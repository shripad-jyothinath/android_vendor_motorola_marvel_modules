// Decompiled by Ghidra 12.2
// Program: lpass_cdc_wsa2_macro_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_cdc_wsa2_macro_probe @ 00100e7c size=1816
// signature: undefined lpass_cdc_wsa2_macro_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lpass_cdc_wsa2_macro_probe(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  char *pcVar9;
  undefined2 uVar10;
  undefined4 uVar11;
  uint local_11c;
  int local_118;
  undefined4 local_114;
  undefined8 local_110;
  code *local_108;
  code *pcStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined **local_e8;
  undefined8 uStack_e0;
  code *local_d8;
  undefined8 uStack_d0;
  code *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  long local_a8;
  undefined8 local_a0;
  ulong local_98 [11];
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_98[10] = *(long *)(lVar7 + 0x638);
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = (code *)0x0;
  uStack_c0 = 0;
  local_d8 = (code *)0x0;
  uStack_d0 = 0;
  local_e8 = (undefined **)0x0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = (code *)0x0;
  pcStack_100 = (code *)0x0;
  local_110 = 0;
  local_118 = 1;
  local_114 = 0;
  local_11c = 0;
  uVar4 = lpass_cdc_is_va_macro_registered(lVar1);
  if ((uVar4 & 1) == 0) {
    pcVar9 = "%s: va-macro not registered yet, defer\n";
LAB_00101344:
    _dev_err(lVar1,pcVar9,"lpass_cdc_wsa2_macro_probe");
    iVar2 = -0x205;
    goto LAB_00101480;
  }
  plVar5 = (long *)devm_kmalloc(lVar1,0x2a8,0xdc0);
  if (plVar5 == (long *)0x0) {
    iVar2 = -0xc;
    goto LAB_00101480;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  *(undefined1 *)(plVar5 + 0x52) = 1;
  *plVar5 = lVar1;
  iVar2 = of_property_read_variable_u32_array(uVar6,&DAT_001192d5,(long)&local_110 + 4,1,0);
  if (iVar2 < 0) {
    _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa2_macro_probe",&DAT_001192d5)
    ;
    goto LAB_00101480;
  }
  of_property_read_variable_u32_array
            (*(undefined8 *)(param_1 + 0x2f8),"wsa_data_fs_ctl_reg",(int *)((long)plVar5 + 0x284),1,
             0);
  if ((plVar5[0x53] == 0) && (iVar2 = *(int *)((long)plVar5 + 0x284), iVar2 != 0)) {
    lVar7 = devm_ioremap(lVar1,iVar2,0x1000);
    plVar5[0x53] = lVar7;
  }
  lVar7 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,is-used-swr-gpio",0);
  if ((lVar7 != 0) &&
     (iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,is-used-swr-gpio",&local_118,1,0),
     iVar2 < 0)) {
    _dev_err(lVar1,"%s: error reading %s in dt\n","lpass_cdc_wsa2_macro_probe",
             "qcom,is-used-swr-gpio");
    local_118 = 1;
  }
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
  iVar2 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa2-swr-gpios",0,0,0,local_98);
  uVar4 = local_98[0];
  if (iVar2 != 0) {
    uVar4 = 0;
  }
  plVar5[0x20] = uVar4;
  if ((uVar4 == 0) && (local_118 != 0)) {
    pcVar9 = "%s: swr_gpios handle not provided!\n";
LAB_00101364:
    _dev_err(lVar1,pcVar9,"lpass_cdc_wsa2_macro_probe");
    iVar2 = -0x16;
    goto LAB_00101480;
  }
  iVar2 = msm_cdc_pinctrl_get_state();
  if ((iVar2 < 0) && (local_118 != 0)) {
    pcVar9 = "%s: failed to get swr pin state\n";
    goto LAB_00101344;
  }
  msm_cdc_pinctrl_set_wakeup_capable(plVar5[0x20],0);
  lVar7 = devm_ioremap(lVar1,local_110._4_4_,0x1000);
  if (lVar7 == 0) {
    pcVar9 = "%s: ioremap failed\n";
    goto LAB_00101364;
  }
  local_98[0] = local_98[0] & 0xffffffff00000000;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-rloads",local_98);
  if (lVar8 == 0) {
    pcVar9 = "%s: missing %s\n";
LAB_001014bc:
    _dev_info(lVar1,pcVar9,"lpass_cdc_wsa2_macro_read_array","qcom,wsa-rloads");
  }
  else {
    if (((uint)local_98[0] & 0xfffffffc) != 8) {
      pcVar9 = "%s: invalid number of %s\n";
      goto LAB_001014bc;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-rloads",(long)plVar5 + 0x27c,2,0);
    if (iVar2 < 0) {
      pcVar9 = "%s: Failed to read %s\n";
      goto LAB_001014bc;
    }
  }
  local_98[0] = local_98[0] & 0xffffffff00000000;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-system-gains",local_98);
  if (lVar8 == 0) {
    pcVar9 = "%s: missing %s\n";
LAB_001014e0:
    _dev_info(lVar1,pcVar9,"lpass_cdc_wsa2_macro_read_array","qcom,wsa-system-gains");
  }
  else {
    if (((uint)local_98[0] & 0xfffffffc) != 0x10) {
      pcVar9 = "%s: invalid number of %s\n";
      goto LAB_001014e0;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-system-gains",(long)plVar5 + 0x264
                       ,4,0);
    if (iVar2 < 0) {
      pcVar9 = "%s: Failed to read %s\n";
      goto LAB_001014e0;
    }
  }
  local_98[0] = local_98[0] & 0xffffffff00000000;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-bat-cfgs",local_98);
  if (lVar8 == 0) {
    pcVar9 = "%s: missing %s\n";
LAB_00101504:
    _dev_info(lVar1,pcVar9,"lpass_cdc_wsa2_macro_read_array","qcom,wsa-bat-cfgs");
  }
  else {
    if (((uint)local_98[0] & 0xfffffffc) != 8) {
      pcVar9 = "%s: invalid number of %s\n";
      goto LAB_00101504;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-bat-cfgs",(long)plVar5 + 0x274,2,0
                      );
    if (iVar2 < 0) {
      pcVar9 = "%s: Failed to read %s\n";
      goto LAB_00101504;
    }
  }
  plVar5[0x35] = lVar7;
  *(undefined1 *)((long)plVar5 + 0x29) = 1;
  plVar5[0x1a] = 0xfffffffe0;
  plVar5[0x1b] = (long)(plVar5 + 0x1b);
  plVar5[0x1c] = (long)(plVar5 + 0x1b);
  plVar5[0x1d] = (long)lpass_cdc_wsa2_macro_add_child_devices;
  plVar5[0x46] = 0xfffffffe0;
  plVar5[0x47] = (long)(plVar5 + 0x47);
  plVar5[0x48] = (long)(plVar5 + 0x47);
  plVar5[0x49] = (long)lpass_cdc_wsa2_macro_cooling_adjust_gain;
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  plVar5[0x13] = (long)plVar5;
  plVar5[0x14] = 0;
  plVar5[0x15] = 0;
  plVar5[0x16] = 0;
  plVar5[0x17] = (long)wsa2_swrm_clock;
  plVar5[0x18] = (long)lpass_cdc_wsa2_macro_core_vote;
  plVar5[0x19] = 0;
  iVar2 = of_property_read_variable_u32_array(uVar6,"qcom,default-clk-id",&local_110,1,0);
  if (iVar2 < 0) {
    _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa2_macro_probe",
             "qcom,mux0-clk-id");
    uVar10 = 4;
    local_110 = CONCAT44(local_110._4_4_,4);
  }
  else {
    uVar10 = (undefined2)local_110;
  }
  *(undefined2 *)(plVar5 + 0x3e) = uVar10;
  *(long **)(param_1 + 0xa8) = plVar5;
  __mutex_init(plVar5 + 6,"&wsa2_priv->mclk_lock",&lpass_cdc_wsa2_macro_probe___key);
  __mutex_init(plVar5 + 0xc,"&wsa2_priv->swr_clk_lock",&lpass_cdc_wsa2_macro_probe___key_17);
  uStack_f0 = 0;
  local_108 = lpass_cdc_wsa2_macro_init;
  pcStack_100 = lpass_cdc_wsa2_macro_deinit;
  local_b8 = 0;
  uStack_b0 = 0;
  local_e8 = &lpass_cdc_wsa2_macro_dai;
  uStack_e0 = 0;
  local_f8 = 5;
  local_d8 = lpass_cdc_wsa2_macro_event_handler;
  uStack_d0 = 0;
  local_c8 = lpass_cdc_wsa2_macro_set_port_map;
  uStack_c0 = 0;
  local_a0 = (ulong)CONCAT22((short)plVar5[0x3e],(short)plVar5[0x3e]);
  local_a8 = lVar7;
  iVar2 = lpass_cdc_register_macro(lVar1,4,&local_108);
  if (iVar2 < 0) {
    _dev_err(lVar1,"%s: register macro failed\n","lpass_cdc_wsa2_macro_probe");
    goto LAB_00101480;
  }
  lVar7 = of_find_property(*(undefined8 *)(*plVar5 + 0x2e8),"#cooling-cells",0);
  if (lVar7 != 0) {
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,thermal-max-state",&local_114,1,0);
    if (iVar2 < 0) {
      _dev_info(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa2_macro_probe",
                "qcom,thermal-max-state");
      uVar11 = 0xb;
    }
    else {
      uVar11 = local_114;
    }
    *(undefined4 *)((long)plVar5 + 0x22c) = uVar11;
    uVar4 = devm_thermal_of_cooling_device_register
                      (lVar1,*(undefined8 *)(*plVar5 + 0x2e8),&DAT_0011946d,plVar5,&wsa2_cooling_ops
                      );
    plVar5[0x44] = uVar4;
    if (0xfffffffffffff000 < uVar4) {
      _dev_err(lVar1,"%s: failed to register wsa2 macro as cooling device\n",
               "lpass_cdc_wsa2_macro_probe");
      plVar5[0x44] = 0;
    }
  }
  iVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,noise-gate-mode",&local_11c,1,0);
  iVar2 = iVar3;
  if (-1 < iVar3) {
    iVar2 = 0;
  }
  if (iVar3 < 0) {
    _dev_info(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa2_macro_probe",
              "qcom,noise-gate-mode");
LAB_00101430:
    *(undefined4 *)((long)plVar5 + 0x28c) = 0;
  }
  else {
    if (3 < local_11c) goto LAB_00101430;
    *(uint *)((long)plVar5 + 0x28c) = local_11c;
  }
  pm_runtime_set_autosuspend_delay(lVar1,0x32);
  __pm_runtime_use_autosuspend(lVar1,1);
  __pm_runtime_set_status(lVar1,2);
  *(ushort *)(param_1 + 0x210) = *(ushort *)(param_1 + 0x210) | 0x100;
  pm_runtime_enable(lVar1);
  queue_work_on(0x20,_system_wq,plVar5 + 0x1a);
LAB_00101480:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_remove @ 00101598 size=168
// signature: undefined lpass_cdc_wsa2_macro_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    param_1 = param_1 + 0x10;
    if (*(long *)(lVar2 + 0x220) != 0) {
      thermal_cooling_device_unregister(*(long *)(lVar2 + 0x220));
    }
    if (0 < *(int *)(lVar2 + 0x1c8)) {
      platform_device_unregister(*(undefined8 *)(lVar2 + 0x1b0));
      if (1 < *(int *)(lVar2 + 0x1c8)) {
        platform_device_unregister(*(undefined8 *)(lVar2 + 0x1b8));
        if (2 < *(int *)(lVar2 + 0x1c8)) {
          platform_device_unregister(*(undefined8 *)(lVar2 + 0x1c0));
        }
      }
    }
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    lpass_cdc_unregister_macro(param_1,4);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_add_child_devices @ 00101644 size=776
// signature: undefined lpass_cdc_wsa2_macro_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa2_macro_add_child_devices(long param_1)

{
  ulong uVar1;
  uint uVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  size_t __n;
  long lVar8;
  char *pcVar9;
  long lVar10;
  ulong uVar11;
  ushort uVar12;
  char local_b8 [80];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  plVar3 = (long *)(param_1 + -0xd0);
  local_b8[0x40] = '\0';
  local_b8[0x41] = '\0';
  local_b8[0x42] = '\0';
  local_b8[0x43] = '\0';
  local_b8[0x44] = '\0';
  local_b8[0x45] = '\0';
  local_b8[0x46] = '\0';
  local_b8[0x47] = '\0';
  local_b8[0x48] = '\0';
  local_b8[0x49] = '\0';
  local_b8[0x4a] = '\0';
  local_b8[0x4b] = '\0';
  local_b8[0x4c] = '\0';
  local_b8[0x4d] = '\0';
  local_b8[0x4e] = '\0';
  local_b8[0x4f] = '\0';
  local_b8[0x30] = '\0';
  local_b8[0x31] = '\0';
  local_b8[0x32] = '\0';
  local_b8[0x33] = '\0';
  local_b8[0x34] = '\0';
  local_b8[0x35] = '\0';
  local_b8[0x36] = '\0';
  local_b8[0x37] = '\0';
  local_b8[0x38] = '\0';
  local_b8[0x39] = '\0';
  local_b8[0x3a] = '\0';
  local_b8[0x3b] = '\0';
  local_b8[0x3c] = '\0';
  local_b8[0x3d] = '\0';
  local_b8[0x3e] = '\0';
  local_b8[0x3f] = '\0';
  local_b8[0x20] = '\0';
  local_b8[0x21] = '\0';
  local_b8[0x22] = '\0';
  local_b8[0x23] = '\0';
  local_b8[0x24] = '\0';
  local_b8[0x25] = '\0';
  local_b8[0x26] = '\0';
  local_b8[0x27] = '\0';
  local_b8[0x28] = '\0';
  local_b8[0x29] = '\0';
  local_b8[0x2a] = '\0';
  local_b8[0x2b] = '\0';
  local_b8[0x2c] = '\0';
  local_b8[0x2d] = '\0';
  local_b8[0x2e] = '\0';
  local_b8[0x2f] = '\0';
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
  if (plVar3 == (long *)0x0) {
    _printk(&DAT_001190e8,"lpass_cdc_wsa2_macro_add_child_devices");
  }
  else {
    lVar6 = *plVar3;
    if ((lVar6 == 0) || (*(long *)(lVar6 + 0x2e8) == 0)) {
      pcVar9 = "%s: DT node for wsa2_priv does not exist\n";
LAB_00101844:
      _dev_err(lVar6,pcVar9,"lpass_cdc_wsa2_macro_add_child_devices");
    }
    else {
      *(undefined4 *)(param_1 + 0xf8) = 0;
      puVar7 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar6 + 0x2e8),0);
      if (puVar7 != (undefined8 *)0x0) {
        uVar12 = 0;
        lVar10 = 0;
        do {
          lVar6 = strnstr(*puVar7,"wsa2_swr_master",0xf);
          if (lVar6 != 0) {
            local_b8[0] = s_wsa2_swr_ctrl_00118ee6[0];
            local_b8[1] = s_wsa2_swr_ctrl_00118ee6[1];
            local_b8[2] = s_wsa2_swr_ctrl_00118ee6[2];
            local_b8[3] = s_wsa2_swr_ctrl_00118ee6[3];
            local_b8[4] = s_wsa2_swr_ctrl_00118ee6[4];
            local_b8[5] = s_wsa2_swr_ctrl_00118ee6[5];
            local_b8[6] = s_wsa2_swr_ctrl_00118ee6[6];
            local_b8[7] = s_wsa2_swr_ctrl_00118ee6[7];
            local_b8[8] = s_wsa2_swr_ctrl_00118ee6[8];
            local_b8[9] = s_wsa2_swr_ctrl_00118ee6[9];
            local_b8[10] = s_wsa2_swr_ctrl_00118ee6[10];
            local_b8[0xb] = s_wsa2_swr_ctrl_00118ee6[0xb];
            local_b8[0xc] = s_wsa2_swr_ctrl_00118ee6[0xc];
            pcVar9 = local_b8 + 0xd;
LAB_00101784:
            *pcVar9 = '\0';
            lVar8 = platform_device_alloc(local_b8,0xffffffff);
            lVar6 = *plVar3;
            if (lVar8 == 0) {
              pcVar9 = "%s: pdev memory alloc failed\n";
              goto LAB_00101844;
            }
            *(long *)(lVar8 + 0x70) = lVar6;
            *(undefined8 **)(lVar8 + 0x2f8) = puVar7;
            lVar6 = strnstr(*puVar7,"wsa2_swr_master",0xf);
            if (lVar6 == 0) {
LAB_00101810:
              iVar5 = platform_device_add(lVar8);
              if (iVar5 == 0) {
                uVar2 = *(uint *)(param_1 + 0xf8);
                if ((int)uVar2 < 3) {
                  *(uint *)(param_1 + 0xf8) = uVar2 + 1;
                  if (2 < uVar2) goto LAB_00101838;
                  *(long *)(param_1 + 0xe0 + (ulong)uVar2 * 8) = lVar8;
                  goto LAB_001016f0;
                }
                break;
              }
              _dev_err(lVar8 + 0x10,"%s: Cannot add platform device\n",
                       "lpass_cdc_wsa2_macro_add_child_devices");
            }
            else {
              iVar5 = platform_device_add_data(lVar8,param_1 + -0x38,0x38);
              if (iVar5 == 0) {
                uVar11 = (ulong)uVar12;
                uVar1 = uVar11 * 8 + 8;
                lVar10 = krealloc(lVar10,uVar1,0xcc0);
                if (lVar10 != 0) {
                  if ((uVar1 < uVar11 * 8) || (uVar1 + uVar11 * -8 < 8)) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(1,0x101948);
                    (*pcVar4)();
                  }
                  uVar12 = uVar12 + 1;
                  *(long *)(lVar10 + uVar11 * 8) = lVar8;
                  *(long *)(param_1 + -0x40) = lVar10;
                  goto LAB_00101810;
                }
                _dev_err(lVar8 + 0x10,"out of memory\n");
              }
              else {
                _dev_err(lVar8 + 0x10,"%s: cannot add plat data ctrl:%d\n",
                         "lpass_cdc_wsa2_macro_add_child_devices",uVar12);
              }
            }
            if ((((0 < *(int *)(param_1 + 0xf8)) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0xe0)), 1 < *(int *)(param_1 + 0xf8)
                 )) && (platform_device_put(*(undefined8 *)(param_1 + 0xe8)),
                       2 < *(int *)(param_1 + 0xf8))) &&
               (platform_device_put(*(undefined8 *)(param_1 + 0xf0)), 3 < *(int *)(param_1 + 0xf8)))
            {
LAB_00101838:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10183c);
              (*pcVar4)();
            }
            break;
          }
          lVar6 = strnstr(*puVar7,"msm_cdc_pinctrl",0xf);
          if (lVar6 != 0) {
            pcVar9 = (char *)*puVar7;
            __n = strlen(pcVar9);
            if (0x4d < __n) {
              __n = 0x4e;
            }
            memcpy(local_b8,pcVar9,__n);
            pcVar9 = local_b8 + __n;
            goto LAB_00101784;
          }
LAB_001016f0:
          puVar7 = (undefined8 *)
                   of_get_next_available_child(*(undefined8 *)(*plVar3 + 0x2e8),puVar7);
        } while (puVar7 != (undefined8 *)0x0);
      }
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_cooling_adjust_gain @ 00101950 size=188
// signature: undefined lpass_cdc_wsa2_macro_cooling_adjust_gain(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa2_macro_cooling_adjust_gain(long param_1)

{
  long lVar1;
  
  if ((long *)(param_1 + -0x230) == (long *)0x0) {
    _printk(&DAT_0011a26b,"lpass_cdc_wsa2_macro_cooling_adjust_gain");
  }
  else {
    lVar1 = *(long *)(param_1 + -0x230);
    if ((lVar1 == 0) || (*(long *)(lVar1 + 0x2e8) == 0)) {
      _dev_err(lVar1,"%s: DT node for wsa2_priv does not exist\n",
               "lpass_cdc_wsa2_macro_cooling_adjust_gain");
    }
    else if (*(char *)(param_1 + -0x208) != '\0') {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + -0x128),0x4414,0xff,
                 *(char *)(param_1 + -0x14) - *(char *)(param_1 + -8));
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + -0x128),0x4494,0xff,
                 *(char *)(param_1 + -0x13) - *(char *)(param_1 + -8));
    }
  }
  return;
}



//------------------------------------------------------------
// wsa2_swrm_clock @ 00101a10 size=728
// signature: undefined wsa2_swrm_clock(void)
// callers: []
//------------------------------------------------------------

int wsa2_swrm_clock(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  short sVar6;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(wsa2_swrm_clock__rs,"wsa2_swrm_clock");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","wsa2_swrm_clock");
    return -0x16;
  }
  mutex_lock(param_1 + 0xc);
  if ((param_2 & 1) == 0) {
    if (*(short *)((long)param_1 + 0x26) == 0) {
      iVar1 = ___ratelimit(wsa2_swrm_clock__rs_44,"wsa2_swrm_clock");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","wsa2_swrm_clock");
      }
      iVar1 = 0;
      *(undefined2 *)((long)param_1 + 0x26) = 0;
    }
    else {
      sVar6 = *(short *)((long)param_1 + 0x26) + -1;
      *(short *)((long)param_1 + 0x26) = sVar6;
      if (sVar6 == 0) {
        regmap_update_bits_base(lVar3,0x4008,1,0,0,0,0);
        lpass_cdc_wsa2_macro_mclk_enable(param_1,0);
        iVar1 = msm_cdc_pinctrl_select_sleep_state(param_1[0x20]);
        if ((iVar1 < 0) &&
           (iVar2 = ___ratelimit(wsa2_swrm_clock__rs_46,"wsa2_swrm_clock"), iVar2 != 0)) {
          _dev_err(*param_1,"%s: wsa2 swr pinctrl disable failed\n","wsa2_swrm_clock");
        }
      }
      else {
        iVar1 = 0;
      }
    }
    goto LAB_00101c70;
  }
  __pm_runtime_resume(*param_1,4);
  sVar6 = *(short *)((long)param_1 + 0x26);
  if (sVar6 == 0) {
    iVar1 = msm_cdc_pinctrl_select_active_state(param_1[0x20]);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(wsa2_swrm_clock__rs_40,"wsa2_swrm_clock");
      if (iVar2 != 0) {
        lVar3 = *param_1;
        pcVar5 = "%s: wsa2 swr pinctrl enable failed\n";
LAB_00101cd8:
        _dev_err(lVar3,pcVar5,"wsa2_swrm_clock");
      }
    }
    else {
      iVar1 = lpass_cdc_wsa2_macro_mclk_enable(param_1,1);
      if (-1 < iVar1) {
        if (*(char *)((long)param_1 + 0x29) != '\0') {
          regmap_update_bits_base(lVar3,0x4008,2,2,0,0,0);
        }
        regmap_update_bits_base(lVar3,0x4008,1,1,0,0,0);
        if (*(char *)((long)param_1 + 0x29) != '\0') {
          regmap_update_bits_base(lVar3,0x4008,2,0,0,0,0);
        }
        regmap_update_bits_base(lVar3,0x4008,0x1c,0xc,0,0,0);
        sVar6 = *(short *)((long)param_1 + 0x26);
        *(undefined1 *)((long)param_1 + 0x29) = 0;
        goto LAB_00101a6c;
      }
      msm_cdc_pinctrl_select_sleep_state(param_1[0x20]);
      iVar2 = ___ratelimit(wsa2_swrm_clock__rs_42,"wsa2_swrm_clock");
      if (iVar2 != 0) {
        lVar3 = *param_1;
        pcVar5 = "%s: wsa2 request clock enable failed\n";
        goto LAB_00101cd8;
      }
    }
    lVar3 = *param_1;
  }
  else {
    iVar1 = 0;
LAB_00101a6c:
    lVar3 = *param_1;
    *(short *)((long)param_1 + 0x26) = sVar6 + 1;
  }
  uVar4 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar3 + 0x220) = uVar4;
  __pm_runtime_suspend(*param_1,0xd);
LAB_00101c70:
  mutex_unlock(param_1 + 0xc);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_core_vote @ 00101cec size=180
// signature: undefined lpass_cdc_wsa2_macro_core_vote(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_wsa2_macro_core_vote(long *param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long lVar5;
  
  if (param_1 == (long *)0x0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_core_vote__rs,"lpass_cdc_wsa2_macro_core_vote");
    if (iVar1 != 0) {
      _printk(&DAT_00118d0e,"lpass_cdc_wsa2_macro_core_vote");
      return 0xffffffea;
    }
  }
  else if (((char)param_1[0x52] != '\0') || ((param_2 & 1) == 0)) {
    if ((param_2 & 1) == 0) {
      __pm_runtime_suspend(*param_1,0xd);
      lVar5 = *param_1;
      uVar3 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar5 + 0x220) = uVar3;
      return 0;
    }
    __pm_runtime_resume(*param_1,4);
    uVar2 = lpass_cdc_check_core_votes(*param_1);
    uVar4 = 0;
    if ((uVar2 & 1) == 0) {
      uVar4 = 0xfffffdf6;
    }
    return uVar4;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_mclk_enable @ 00101da0 size=660
// signature: undefined lpass_cdc_wsa2_macro_mclk_enable(void)
// callers: [lpass_cdc_wsa2_macro_mclk_event, wsa2_swrm_clock]
//------------------------------------------------------------

int lpass_cdc_wsa2_macro_mclk_enable(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  short sVar4;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_mclk_enable__rs,"lpass_cdc_wsa2_macro_mclk_enable");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","lpass_cdc_wsa2_macro_mclk_enable");
    return -0x16;
  }
  mutex_lock(param_1 + 6);
  sVar4 = *(short *)((long)param_1 + 0x24);
  if ((param_2 & 1) == 0) {
    if (sVar4 == 0) {
      iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_mclk_enable__rs_49,
                           "lpass_cdc_wsa2_macro_mclk_enable");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","lpass_cdc_wsa2_macro_mclk_enable");
      }
      iVar1 = 0;
      *(undefined2 *)((long)param_1 + 0x24) = 0;
    }
    else {
      *(short *)((long)param_1 + 0x24) = sVar4 + -1;
      if ((short)(sVar4 + -1) == 0) {
        regmap_update_bits_base(lVar3,0x4004,1,0,0,0,0);
        regmap_update_bits_base(lVar3,0x4000,1,0,0,0,0);
        lpass_cdc_clk_rsc_fs_gen_request(*param_1,0);
        lpass_cdc_clk_rsc_request_clock(*param_1,(short)param_1[0x3e],(short)param_1[0x3e],0);
      }
      iVar1 = 0;
    }
  }
  else {
    if (sVar4 == 0) {
      iVar1 = lpass_cdc_clk_rsc_request_clock(*param_1,(short)param_1[0x3e],(short)param_1[0x3e],1);
      if (iVar1 < 0) {
        iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_mclk_enable__rs_48,
                             "lpass_cdc_wsa2_macro_mclk_enable");
        if (iVar2 != 0) {
          _dev_err(*param_1,"%s: wsa2 request clock enable failed\n",
                   "lpass_cdc_wsa2_macro_mclk_enable");
        }
        goto LAB_00101fbc;
      }
      lpass_cdc_clk_rsc_fs_gen_request(*param_1,1);
      regcache_mark_dirty(lVar3);
      regcache_sync_region(lVar3,0x4000,0x4be4);
      regmap_update_bits_base(lVar3,0x4088,1,1,0,0,0);
      regmap_update_bits_base(lVar3,0x4000,1,1,0,0,0);
      regmap_update_bits_base(lVar3,0x2004,2,2,0,0,0);
      regmap_update_bits_base(lVar3,0x2004,2,0,0,0,0);
      regmap_update_bits_base(lVar3,0x4004,1,1,0,0,0);
      sVar4 = *(short *)((long)param_1 + 0x24);
    }
    else {
      iVar1 = 0;
    }
    *(short *)((long)param_1 + 0x24) = sVar4 + 1;
  }
LAB_00101fbc:
  mutex_unlock(param_1 + 6);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_init @ 00102038 size=2892
// signature: undefined lpass_cdc_wsa2_macro_init(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_wsa2_macro_init(long param_1)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  code *pcVar20;
  int iVar21;
  long lVar22;
  undefined8 uVar23;
  char *pcVar24;
  ulong uVar25;
  long lVar26;
  ulong uVar27;
  
  lVar22 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar22 == 0) {
    uVar23 = *(undefined8 *)(param_1 + 0x18);
    pcVar24 = "%s: null device for macro!\n";
  }
  else {
    lVar26 = *(long *)(lVar22 + 0x98);
    if (lVar26 != 0) {
      lVar1 = param_1 + 0xd0;
      iVar21 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_wsa2_macro_dapm_widgets,0x30);
      if (iVar21 < 0) {
        pcVar24 = "%s: Failed to add controls\n";
      }
      else {
        iVar21 = snd_soc_dapm_add_routes(lVar1,&wsa2_audio_map,0x77);
        if (iVar21 < 0) {
          pcVar24 = "%s: Failed to add routes\n";
        }
        else {
          iVar21 = snd_soc_dapm_new_widgets(*(undefined8 *)(param_1 + 0xe8));
          if (iVar21 < 0) {
            pcVar24 = "%s: Failed to add widgets\n";
          }
          else {
            iVar21 = snd_soc_add_component_controls(param_1,lpass_cdc_wsa2_macro_snd_controls,0x13);
            if (-1 < iVar21) {
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_AIF1 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_AIF_MIX1 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_AIF_VI Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_AIF_ECHO Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_SPK1 OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_SPK2 OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"VIINPUT_WSA2");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2 SRC0_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_TX DEC0_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA2_TX DEC1_INP");
              snd_soc_dapm_sync(lVar1);
              lVar22 = 0;
              *(long *)(lVar26 + 0x108) = param_1;
              *(undefined4 *)(lVar26 + 0x1d0) = 1;
              do {
                snd_soc_component_update_bits
                          (param_1,*(undefined2 *)((long)&lpass_cdc_wsa2_macro_reg_init + lVar22),
                           (&DAT_0010f852)[lVar22],(&DAT_0010f853)[lVar22]);
                lVar22 = lVar22 + 4;
              } while (lVar22 != 0x98);
              lVar22 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
              if (lVar22 == 0) {
                iVar21 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,
                                      "lpass_cdc_wsa2_macro_get_data");
                if (iVar21 == 0) {
                  return 0;
                }
                pcVar24 = "%s: null device for macro!\n";
              }
              else {
                lVar22 = *(long *)(lVar22 + 0x98);
                if ((lVar22 != 0) && (*(long *)(lVar22 + 0x108) != 0)) {
                  uVar18 = *(uint *)(lVar22 + 0x27c);
                  uVar19 = *(uint *)(lVar22 + 0x264);
                  uVar17 = *(uint *)(lVar22 + 0x274);
                  uVar27 = (ulong)uVar17;
                  if (uVar18 < 4) {
                    snd_soc_component_update_bits
                              (param_1,0x4b4c,0xe0,
                               *(undefined4 *)(&DAT_0011a368 + (long)(int)uVar18 * 4));
                  }
                  snd_soc_component_update_bits(param_1,0x4b50,0xf,uVar19);
                  snd_soc_component_update_bits(param_1,0x4bc4,0xc0,uVar17 * 0x40 + -0x40);
                  if (((0x12 < uVar19) || (6 < uVar17)) || (3 < uVar18)) {
LAB_00102b80:
                    /* WARNING: Does not return */
                    pcVar20 = (code *)SoftwareBreakpoint(0x5512,0x102b84);
                    (*pcVar20)();
                  }
                  if (((long)(int)uVar19 * 0x70 + uVar27 * 0x10 + (ulong)uVar18 * 4 < 0x84d) &&
                     (uVar25 = (ulong)uVar18,
                     (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4 < 0x84d)) {
                    uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                    iVar21 = 0xff;
                    if (*(int *)(pbr_vth1_data + uVar2) != 0) {
                      iVar21 = *(int *)(pbr_vth1_data + uVar2);
                    }
                    if (uVar2 < 0x84d) {
                      uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                      iVar3 = 0xff;
                      if (*(int *)(pbr_vth2_data + uVar2) != 0) {
                        iVar3 = *(int *)(pbr_vth2_data + uVar2);
                      }
                      if (uVar2 < 0x84d) {
                        uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                        iVar4 = 0xff;
                        if (*(int *)(pbr_vth3_data + uVar2) != 0) {
                          iVar4 = *(int *)(pbr_vth3_data + uVar2);
                        }
                        if (uVar2 < 0x84d) {
                          uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                          iVar5 = 0xff;
                          if (*(int *)(pbr_vth4_data + uVar2) != 0) {
                            iVar5 = *(int *)(pbr_vth4_data + uVar2);
                          }
                          if (uVar2 < 0x84d) {
                            uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                            iVar6 = 0xff;
                            if (*(int *)(pbr_vth5_data + uVar2) != 0) {
                              iVar6 = *(int *)(pbr_vth5_data + uVar2);
                            }
                            if (uVar2 < 0x84d) {
                              uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                              iVar7 = 0xff;
                              if (*(int *)(pbr_vth6_data + uVar2) != 0) {
                                iVar7 = *(int *)(pbr_vth6_data + uVar2);
                              }
                              if (uVar2 < 0x84d) {
                                uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                iVar8 = 0xff;
                                if (*(int *)(pbr_vth7_data + uVar2) != 0) {
                                  iVar8 = *(int *)(pbr_vth7_data + uVar2);
                                }
                                if (uVar2 < 0x84d) {
                                  uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                  iVar9 = 0xff;
                                  if (*(int *)(pbr_vth8_data + uVar2) != 0) {
                                    iVar9 = *(int *)(pbr_vth8_data + uVar2);
                                  }
                                  if (uVar2 < 0x84d) {
                                    uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                    iVar10 = 0xff;
                                    if (*(int *)(pbr_vth9_data + uVar2) != 0) {
                                      iVar10 = *(int *)(pbr_vth9_data + uVar2);
                                    }
                                    if (uVar2 < 0x84d) {
                                      uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                      iVar11 = 0xff;
                                      if (*(int *)(pbr_vth10_data + uVar2) != 0) {
                                        iVar11 = *(int *)(pbr_vth10_data + uVar2);
                                      }
                                      if (uVar2 < 0x84d) {
                                        uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                uVar25 * 4;
                                        iVar12 = 0xff;
                                        if (*(int *)(pbr_vth11_data + uVar2) != 0) {
                                          iVar12 = *(int *)(pbr_vth11_data + uVar2);
                                        }
                                        if (uVar2 < 0x84d) {
                                          uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                  uVar25 * 4;
                                          iVar13 = 0xff;
                                          if (*(int *)(pbr_vth12_data + uVar2) != 0) {
                                            iVar13 = *(int *)(pbr_vth12_data + uVar2);
                                          }
                                          if (uVar2 < 0x84d) {
                                            uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                    uVar25 * 4;
                                            iVar14 = 0xff;
                                            if (*(int *)(pbr_vth13_data + uVar2) != 0) {
                                              iVar14 = *(int *)(pbr_vth13_data + uVar2);
                                            }
                                            if ((uVar2 < 0x84d) &&
                                               ((long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                uVar25 * 4 < 0x84d)) {
                                              iVar15 = 0xff;
                                              if (*(int *)(pbr_vth14_data +
                                                          uVar25 * 4 +
                                                          uVar27 * 0x10 + (long)(int)uVar19 * 0x70)
                                                  != 0) {
                                                iVar15 = *(int *)(pbr_vth14_data +
                                                                 uVar25 * 4 +
                                                                 uVar27 * 0x10 +
                                                                 (long)(int)uVar19 * 0x70);
                                              }
                                              iVar16 = 0xff;
                                              if (*(int *)(pbr_vth15_data + uVar2) != 0) {
                                                iVar16 = *(int *)(pbr_vth15_data + uVar2);
                                              }
                                              snd_soc_component_write(param_1,0x4b08,iVar21);
                                              snd_soc_component_write(param_1,0x4b0c,iVar3);
                                              snd_soc_component_write(param_1,0x4b10,iVar4);
                                              snd_soc_component_write(param_1,0x4b14,iVar5);
                                              snd_soc_component_write(param_1,0x4b18,iVar6);
                                              snd_soc_component_write(param_1,0x4b1c,iVar7);
                                              snd_soc_component_write(param_1,0x4b20,iVar8);
                                              snd_soc_component_write(param_1,0x4b24,iVar9);
                                              snd_soc_component_write(param_1,0x4b28,iVar10);
                                              snd_soc_component_write(param_1,0x4b2c,iVar11);
                                              snd_soc_component_write(param_1,0x4b30,iVar12);
                                              snd_soc_component_write(param_1,0x4b34,iVar13);
                                              snd_soc_component_write(param_1,0x4b38,iVar14);
                                              snd_soc_component_write(param_1,0x4b3c,iVar15);
                                              snd_soc_component_write(param_1,0x4b40,iVar16);
                                              uVar18 = *(uint *)(lVar22 + 0x280);
                                              uVar19 = *(uint *)(lVar22 + 0x26c);
                                              uVar17 = *(uint *)(lVar22 + 0x278);
                                              uVar27 = (ulong)uVar17;
                                              if (uVar18 < 4) {
                                                snd_soc_component_update_bits
                                                          (param_1,0x4bb4,0xe0,
                                                           *(undefined4 *)
                                                            (&DAT_0011a368 + (long)(int)uVar18 * 4))
                                                ;
                                              }
                                              snd_soc_component_update_bits
                                                        (param_1,0x4bb8,0xf,uVar19);
                                              snd_soc_component_update_bits
                                                        (param_1,0x4bc4,0x30,uVar17 * 0x10 + -0x10);
                                              if (((0x12 < uVar19) || (6 < uVar17)) || (3 < uVar18))
                                              goto LAB_00102b80;
                                              if (((long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                   (ulong)uVar18 * 4 < 0x84d) &&
                                                 (uVar25 = (ulong)uVar18,
                                                 (long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                 uVar25 * 4 < 0x84d)) {
                                                uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                        uVar25 * 4;
                                                iVar21 = 0xff;
                                                if (*(int *)(pbr_vth1_data + uVar2) != 0) {
                                                  iVar21 = *(int *)(pbr_vth1_data + uVar2);
                                                }
                                                if (uVar2 < 0x84d) {
                                                  uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                          uVar25 * 4;
                                                  iVar3 = 0xff;
                                                  if (*(int *)(pbr_vth2_data + uVar2) != 0) {
                                                    iVar3 = *(int *)(pbr_vth2_data + uVar2);
                                                  }
                                                  if (uVar2 < 0x84d) {
                                                    uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10
                                                            + uVar25 * 4;
                                                    iVar4 = 0xff;
                                                    if (*(int *)(pbr_vth3_data + uVar2) != 0) {
                                                      iVar4 = *(int *)(pbr_vth3_data + uVar2);
                                                    }
                                                    if (uVar2 < 0x84d) {
                                                      uVar2 = (long)(int)uVar19 * 0x70 +
                                                              uVar27 * 0x10 + uVar25 * 4;
                                                      iVar5 = 0xff;
                                                      if (*(int *)(pbr_vth4_data + uVar2) != 0) {
                                                        iVar5 = *(int *)(pbr_vth4_data + uVar2);
                                                      }
                                                      if (uVar2 < 0x84d) {
                                                        uVar2 = (long)(int)uVar19 * 0x70 +
                                                                uVar27 * 0x10 + uVar25 * 4;
                                                        iVar6 = 0xff;
                                                        if (*(int *)(pbr_vth5_data + uVar2) != 0) {
                                                          iVar6 = *(int *)(pbr_vth5_data + uVar2);
                                                        }
                                                        if (uVar2 < 0x84d) {
                                                          uVar2 = (long)(int)uVar19 * 0x70 +
                                                                  uVar27 * 0x10 + uVar25 * 4;
                                                          iVar7 = 0xff;
                                                          if (*(int *)(pbr_vth6_data + uVar2) != 0)
                                                          {
                                                            iVar7 = *(int *)(pbr_vth6_data + uVar2);
                                                          }
                                                          if (uVar2 < 0x84d) {
                                                            uVar2 = (long)(int)uVar19 * 0x70 +
                                                                    uVar27 * 0x10 + uVar25 * 4;
                                                            iVar8 = 0xff;
                                                            if (*(int *)(pbr_vth7_data + uVar2) != 0
                                                               ) {
                                                              iVar8 = *(int *)(pbr_vth7_data + uVar2
                                                                              );
                                                            }
                                                            if (uVar2 < 0x84d) {
                                                              uVar2 = (long)(int)uVar19 * 0x70 +
                                                                      uVar27 * 0x10 + uVar25 * 4;
                                                              iVar9 = 0xff;
                                                              if (*(int *)(pbr_vth8_data + uVar2) !=
                                                                  0) {
                                                                iVar9 = *(int *)(pbr_vth8_data +
                                                                                uVar2);
                                                              }
                                                              if (uVar2 < 0x84d) {
                                                                uVar2 = (long)(int)uVar19 * 0x70 +
                                                                        uVar27 * 0x10 + uVar25 * 4;
                                                                iVar10 = 0xff;
                                                                if (*(int *)(pbr_vth9_data + uVar2)
                                                                    != 0) {
                                                                  iVar10 = *(int *)(pbr_vth9_data +
                                                                                   uVar2);
                                                                }
                                                                if (uVar2 < 0x84d) {
                                                                  uVar2 = (long)(int)uVar19 * 0x70 +
                                                                          uVar27 * 0x10 + uVar25 * 4
                                                                  ;
                                                                  iVar11 = 0xff;
                                                                  if (*(int *)(pbr_vth10_data +
                                                                              uVar2) != 0) {
                                                                    iVar11 = *(int *)(pbr_vth10_data
                                                                                     + uVar2);
                                                                  }
                                                                  if (uVar2 < 0x84d) {
                                                                    uVar2 = (long)(int)uVar19 * 0x70
                                                                            + uVar27 * 0x10 +
                                                                            uVar25 * 4;
                                                                    iVar12 = 0xff;
                                                                    if (*(int *)(pbr_vth11_data +
                                                                                uVar2) != 0) {
                                                                      iVar12 = *(int *)(
                                                  pbr_vth11_data + uVar2);
                                                  }
                                                  if (uVar2 < 0x84d) {
                                                    uVar2 = (long)(int)uVar19 * 0x70 + uVar27 * 0x10
                                                            + uVar25 * 4;
                                                    iVar13 = 0xff;
                                                    if (*(int *)(pbr_vth12_data + uVar2) != 0) {
                                                      iVar13 = *(int *)(pbr_vth12_data + uVar2);
                                                    }
                                                    if (uVar2 < 0x84d) {
                                                      uVar2 = (long)(int)uVar19 * 0x70 +
                                                              uVar27 * 0x10 + uVar25 * 4;
                                                      iVar14 = 0xff;
                                                      if (*(int *)(pbr_vth13_data + uVar2) != 0) {
                                                        iVar14 = *(int *)(pbr_vth13_data + uVar2);
                                                      }
                                                      if ((uVar2 < 0x84d) &&
                                                         ((long)(int)uVar19 * 0x70 + uVar27 * 0x10 +
                                                          uVar25 * 4 < 0x84d)) {
                                                        iVar15 = 0xff;
                                                        if (*(int *)(pbr_vth14_data +
                                                                    uVar25 * 4 +
                                                                    uVar27 * 0x10 +
                                                                    (long)(int)uVar19 * 0x70) != 0)
                                                        {
                                                          iVar15 = *(int *)(pbr_vth14_data +
                                                                           uVar25 * 4 +
                                                                           uVar27 * 0x10 +
                                                                           (long)(int)uVar19 * 0x70)
                                                          ;
                                                        }
                                                        iVar16 = 0xff;
                                                        if (*(int *)(pbr_vth15_data + uVar2) != 0) {
                                                          iVar16 = *(int *)(pbr_vth15_data + uVar2);
                                                        }
                                                        snd_soc_component_write
                                                                  (param_1,0x4b74,iVar21);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b78,iVar3);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b7c,iVar4);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b80,iVar5);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b84,iVar6);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b88,iVar7);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b8c,iVar8);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b90,iVar9);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b94,iVar10);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b98,iVar11);
                                                        snd_soc_component_write
                                                                  (param_1,0x4b9c,iVar12);
                                                        snd_soc_component_write
                                                                  (param_1,0x4ba0,iVar13);
                                                        snd_soc_component_write
                                                                  (param_1,0x4ba4,iVar14);
                                                        snd_soc_component_write
                                                                  (param_1,0x4ba8,iVar15);
                                                        snd_soc_component_write
                                                                  (param_1,0x4bac,iVar16);
                                                        return 0;
                                                      }
                                                    }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                    /* WARNING: Does not return */
                  pcVar20 = (code *)SoftwareBreakpoint(1,0x102b80);
                  (*pcVar20)();
                }
                iVar21 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,
                                      "lpass_cdc_wsa2_macro_get_data");
                if (iVar21 == 0) {
                  return 0;
                }
                pcVar24 = "%s: priv is null for macro!\n";
              }
              _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar24,"lpass_cdc_wsa2_macro_init_pbr");
              return 0;
            }
            pcVar24 = "%s: Failed to add snd_ctls\n";
          }
        }
      }
      _dev_err(lVar22,pcVar24,"lpass_cdc_wsa2_macro_init");
      return iVar21;
    }
    uVar23 = *(undefined8 *)(param_1 + 0x18);
    pcVar24 = "%s: priv is null for macro!\n";
  }
  _dev_err(uVar23,pcVar24,"lpass_cdc_wsa2_macro_init");
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_deinit @ 00102b88 size=172
// signature: undefined lpass_cdc_wsa2_macro_deinit(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_deinit(long param_1)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(undefined8 *)(lVar2 + 0x108) = 0;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_deinit");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_event_handler @ 00102c38 size=380
// signature: undefined lpass_cdc_wsa2_macro_event_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_event_handler(long param_1,short param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar4 = *(long *)(lVar2 + 0x98);
    if ((lVar4 != 0) && (*(long *)(lVar4 + 0x108) != 0)) {
      if (param_2 == 7) {
        lpass_cdc_rsc_clk_reset(lVar2,4);
        lpass_cdc_rsc_clk_reset(lVar2,7);
      }
      else if (param_2 == 5) {
        *(undefined1 *)(lVar4 + 0x290) = 1;
        *(undefined1 *)(lVar4 + 0x29) = 1;
        if (*(undefined8 **)(lVar4 + 0x90) != (undefined8 *)0x0) {
          swrm_wcd_notify(**(undefined8 **)(lVar4 + 0x90),7,0);
        }
      }
      else if (param_2 == 4) {
        *(undefined1 *)(lVar4 + 0x290) = 0;
        if (*(undefined8 **)(lVar4 + 0x90) != (undefined8 *)0x0) {
          swrm_wcd_notify(**(undefined8 **)(lVar4 + 0x90),6,0);
        }
        if ((((*(ushort *)(lVar2 + 0x200) & 7) != 0) || (*(int *)(lVar2 + 0x20c) != 2)) &&
           (iVar1 = lpass_cdc_runtime_suspend(lVar2), iVar1 == 0)) {
          __pm_runtime_disable(lVar2,1);
          __pm_runtime_set_status(lVar2,2);
          pm_runtime_enable(lVar2);
        }
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_event_handler");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_set_port_map @ 00102db8 size=268
// signature: undefined lpass_cdc_wsa2_macro_set_port_map(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa2_macro_set_port_map
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: null device for macro!\n";
LAB_00102eac:
      _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar4,"lpass_cdc_wsa2_macro_set_port_map");
    }
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      local_48 = param_3;
      uStack_44 = param_2;
      local_40 = param_4;
      if (*(undefined8 **)(lVar2 + 0x90) == (undefined8 *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = swrm_wcd_notify(**(undefined8 **)(lVar2 + 0x90),9,&local_48);
      }
      goto LAB_00102e70;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: priv is null for macro!\n";
      goto LAB_00102eac;
    }
  }
  uVar3 = 0xffffffea;
LAB_00102e70:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_disable_vi_feedback @ 00102ec8 size=448
// signature: undefined lpass_cdc_wsa2_macro_disable_vi_feedback(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_disable_vi_feedback(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + -0xb8),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      if (param_3 == 8) {
        lVar4 = lVar4 + -0xd0;
        if ((*(ulong *)(lVar2 + 0x130) & 1) != 0) {
          snd_soc_component_update_bits(lVar4,0x4244,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x4264,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x4244,0x10,0);
          snd_soc_component_update_bits(lVar4,0x4264,0x10,0);
          snd_soc_component_update_bits(lVar4,0x4244,0x20,0);
          snd_soc_component_update_bits(lVar4,0x4264,0x20,0);
        }
        if (((uint)*(undefined8 *)(lVar2 + 0x130) >> 1 & 1) != 0) {
          snd_soc_component_update_bits(lVar4,0x4284,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x42a4,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x4284,0x10,0);
          snd_soc_component_update_bits(lVar4,0x42a4,0x10,0);
          snd_soc_component_update_bits(lVar4,0x4284,0x20,0);
          snd_soc_component_update_bits(lVar4,0x42a4,0x20,0);
        }
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + -0xb8),pcVar3,"lpass_cdc_wsa2_macro_disable_vi_feedback");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_echo @ 0010308c size=404
// signature: undefined lpass_cdc_wsa2_macro_enable_echo(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_enable_echo(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),4);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: null device for macro!\n";
  }
  else {
    lVar7 = *(long *)(lVar3 + 0x98);
    if ((lVar7 != 0) && (*(long *)(lVar7 + 0x108) != 0)) {
      lVar6 = lVar6 + -0xd0;
      uVar4 = snd_soc_component_read(lVar6,0x4110);
      iVar2 = strcmp(*(char **)(param_1 + 8),"WSA2 RX_MIX EC0_MUX");
      uVar1 = (uint)uVar4;
      if (iVar2 != 0) {
        uVar1 = (uint)((uVar4 & 0xffffffff) >> 3);
      }
      uVar1 = (uVar1 & 7) - 1;
      if (uVar1 < 2) {
        if (*(int *)(lVar7 + (ulong)(uVar1 & 0xffff) * 4 + 0x18) != 0) {
          iVar2 = 1 << (ulong)(uVar1 & 0x1f);
          snd_soc_component_update_bits(lVar6,0x4110,iVar2,iVar2);
          iVar2 = (uVar1 & 0xffff) * 0x40;
          snd_soc_component_update_bits(lVar6,iVar2 + 0x4680U & 0xffc0,1,1);
          snd_soc_component_update_bits(lVar6,iVar2 + 0x4684U & 0xfffc,0x1e,8);
        }
        return 0;
      }
      iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_enable_echo__rs,"lpass_cdc_wsa2_macro_enable_echo");
      if (iVar2 == 0) {
        return 0xffffffea;
      }
      pcVar5 = "%s: EC mix control not set correctly\n";
      goto LAB_00103218;
    }
    iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: priv is null for macro!\n";
  }
  lVar3 = *(long *)(lVar6 + -0xb8);
LAB_00103218:
  _dev_err(lVar3,pcVar5,"lpass_cdc_wsa2_macro_enable_echo");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_swr @ 00103224 size=400
// signature: undefined lpass_cdc_wsa2_macro_enable_swr(void)
// callers: [lpass_cdc_wsa2_macro_enable_mix_path]
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_enable_swr(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + -0xb8),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      if (param_3 == 8) {
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00118ec8,9);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x110) != 0)) {
          *(int *)(lVar2 + 0x110) = *(int *)(lVar2 + 0x110) + -1;
        }
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00119e54,9);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x114) != 0)) {
          *(int *)(lVar2 + 0x114) = *(int *)(lVar2 + 0x114) + -1;
          return 0;
        }
      }
      else if (param_3 == 1) {
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00118ec8,9);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x110) == 0)) {
          *(undefined4 *)(lVar2 + 0x110) = 1;
        }
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00119e54,9);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x114) == 0)) {
          *(undefined4 *)(lVar2 + 0x114) = 1;
        }
        if (*(undefined8 **)(lVar2 + 0x90) != (undefined8 *)0x0) {
          swrm_wcd_notify(**(undefined8 **)(lVar2 + 0x90),2,0);
          return 0;
        }
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + -0xb8),pcVar3,"lpass_cdc_wsa2_macro_enable_swr");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_mix_path @ 001033b8 size=392
// signature: undefined lpass_cdc_wsa2_macro_enable_mix_path(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_enable_mix_path(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  char *__s1;
  undefined8 uVar4;
  long lVar5;
  
  __s1 = *(char **)(param_1 + 8);
  lVar5 = *(long *)(param_1 + 0x28);
  iVar2 = strcmp(__s1,"WSA2_RX0 MIX INP");
  if (iVar2 == 0) {
    uVar4 = 0x4420;
  }
  else {
    iVar2 = strcmp(__s1,"WSA2_RX1 MIX INP");
    if (iVar2 != 0) {
      iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_enable_mix_path__rs,
                           "lpass_cdc_wsa2_macro_enable_mix_path");
      if (iVar2 == 0) {
        return 0;
      }
      _dev_err(*(undefined8 *)(lVar5 + -0xb8),"%s: No gain register avail for %s\n",
               "lpass_cdc_wsa2_macro_enable_mix_path",*(undefined8 *)(param_1 + 8));
      return 0;
    }
    uVar4 = 0x44a0;
  }
  lVar5 = lVar5 + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar5,*(undefined4 *)(param_1 + 0x48),0x20,0);
    lpass_cdc_wsa2_macro_enable_swr(param_1,extraout_x1_00,8);
  }
  else if (param_3 == 1) {
    iVar1 = (uint)*(byte *)(param_1 + 0x4c) * 0x80;
    iVar2 = iVar1 + 0x4418;
    snd_soc_component_update_bits(lVar5,iVar2,0x40,0x40);
    usleep_range_state(500,0x1fe,2);
    snd_soc_component_update_bits(lVar5,iVar2,0x40,0);
    snd_soc_component_update_bits(lVar5,iVar1 + 0x4400,0x20,0x20);
    snd_soc_component_update_bits(lVar5,iVar2,0x20,0x20);
    lpass_cdc_wsa2_macro_enable_swr(param_1,extraout_x1,1);
    uVar3 = snd_soc_component_read(lVar5,uVar4);
    snd_soc_component_write(lVar5,uVar4,uVar3);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_main_path @ 00103544 size=416
// signature: undefined lpass_cdc_wsa2_macro_enable_main_path(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_enable_main_path(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x28);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + -0xb8),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    if ((*(long *)(lVar5 + 0x98) != 0) && (*(long *)(*(long *)(lVar5 + 0x98) + 0x108) != 0)) {
      if (param_3 == 1) {
        lVar7 = lVar7 + -0xd0;
        iVar4 = (uint)*(byte *)(param_1 + 0x4c) * 0x80 + 0x4400;
        snd_soc_component_update_bits(lVar7,iVar4,0x40,0x40);
        usleep_range_state(500,0x1fe,2);
        snd_soc_component_update_bits(lVar7,iVar4,0x40,0);
        snd_soc_component_update_bits(lVar7,iVar4,0x20,0x20);
        iVar1 = (uint)*(byte *)(param_1 + 0x4c) * 8;
        uVar2 = snd_soc_component_read(lVar7,iVar1 + 0x4100);
        uVar3 = snd_soc_component_read(lVar7,iVar1 + 0x4104);
        if ((((uVar2 & 0xe) != 10) && ((uVar2 & 0xe0) != 0xa0)) && ((uVar3 & 0xe0) != 0xa0)) {
          return 0;
        }
        lpass_cdc_wsa_pa_on(lVar5,1);
        snd_soc_component_update_bits(lVar7,iVar4,0x10,0);
      }
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + -0xb8),pcVar6,"lpass_cdc_wsa2_macro_enable_main_path");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_interpolator @ 001036e8 size=1024
// signature: undefined lpass_cdc_wsa2_macro_enable_interpolator(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_enable_interpolator(long param_1,undefined8 param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  char *pcVar15;
  long lVar16;
  long lVar17;
  
  lVar17 = *(long *)(param_1 + 0x28);
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + -0xb8),4);
  if (lVar9 == 0) {
LAB_001037cc:
    iVar6 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar6 == 0) {
      return 0xffffffea;
    }
    pcVar15 = "%s: null device for macro!\n";
  }
  else {
    if ((*(long *)(lVar9 + 0x98) != 0) && (*(long *)(*(long *)(lVar9 + 0x98) + 0x108) != 0)) {
      lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + -0xb8),4);
      if (lVar9 == 0) goto LAB_001037cc;
      lVar9 = *(long *)(lVar9 + 0x98);
      if ((lVar9 != 0) && (lVar16 = *(long *)(lVar9 + 0x108), lVar16 != 0)) {
        pcVar15 = *(char **)(param_1 + 8);
        iVar6 = strcmp(pcVar15,"WSA2_RX INT0 INTERP");
        if (iVar6 == 0) {
          uVar10 = 0x4400;
        }
        else {
          iVar7 = strcmp(pcVar15,"WSA2_RX INT1 INTERP");
          if (iVar7 != 0) {
            iVar6 = ___ratelimit(lpass_cdc_wsa2_macro_enable_interpolator__rs,
                                 "lpass_cdc_wsa2_macro_enable_interpolator");
            if (iVar6 == 0) {
              return 0xffffffea;
            }
            uVar10 = *(undefined8 *)(lVar17 + -0xb8);
            pcVar15 = "%s: Interpolator reg not found\n";
            goto LAB_00103810;
          }
          uVar10 = 0x4480;
        }
        lVar17 = lVar17 + -0xd0;
        if (param_3 == 8) {
          snd_soc_component_update_bits(lVar17,0x4408,8,8);
          lpass_cdc_wsa2_macro_config_compander(lVar17,*(undefined1 *)(param_1 + 0x4c),8);
          bVar3 = *(byte *)(param_1 + 0x4c);
          uVar12 = (ulong)bVar3;
          if (*(char *)(lVar9 + 0x288) != '\0') {
            uVar13 = 0x4410;
            if (bVar3 != 0) {
              uVar13 = 0;
            }
            uVar14 = 0;
            if (bVar3 < 2) {
              uVar14 = 0x4780;
            }
            uVar1 = 2;
            if (bVar3 != 1) {
              uVar1 = bVar3 == 0;
            }
            uVar2 = 0x4490;
            if (bVar3 != 1) {
              uVar2 = uVar13;
            }
            if (1 < bVar3) {
LAB_00103ae4:
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x103ae8);
              (*pcVar5)();
            }
            lVar16 = 0;
            if ((*(int *)(lVar9 + 0x28c) != 0) &&
               (*(int *)(lVar9 + 0x28c) != 2 || *(ushort *)(lVar9 + uVar12 * 4 + 0x10) < 5)) {
              if (*(char *)(lVar9 + 0x260) == '\0') {
                lVar16 = 0;
              }
              else {
                lVar16 = (ulong)(*(int *)(lVar9 + 0x1cc) == 0) << 7;
              }
            }
            snd_soc_component_update_bits(lVar17,uVar2,0x80,lVar16);
            snd_soc_component_update_bits(lVar17,uVar14,uVar1,0);
            snd_soc_component_write(lVar17,0x4790,0);
            uVar12 = (ulong)*(byte *)(param_1 + 0x4c);
          }
          lpass_cdc_wsa2_macro_config_softclip(lVar17,uVar12,8);
          lpass_cdc_was_macro_config_pbr(lVar17,*(undefined1 *)(param_1 + 0x4c),8);
          uVar11 = 8;
        }
        else {
          if (param_3 == 2) {
            if ((iVar6 == 0) &&
               (bVar3 = *(byte *)(lVar9 + 0x21c), bVar4 = *(byte *)(lVar9 + 0x228),
               uVar8 = snd_soc_component_read(lVar16,0x4414),
               uVar8 != ((uint)bVar3 - (uint)bVar4 & 0xff))) {
              snd_soc_component_update_bits(*(undefined8 *)(lVar9 + 0x108),0x4414,0xff);
            }
            iVar6 = strcmp(*(char **)(param_1 + 8),"WSA2_RX INT1 INTERP");
            if ((iVar6 == 0) &&
               (bVar3 = *(byte *)(lVar9 + 0x21d), bVar4 = *(byte *)(lVar9 + 0x228),
               uVar8 = snd_soc_component_read(*(undefined8 *)(lVar9 + 0x108),0x4494),
               uVar8 != ((uint)bVar3 - (uint)bVar4 & 0xff))) {
              snd_soc_component_update_bits(*(undefined8 *)(lVar9 + 0x108),0x4494,0xff);
            }
            lpass_cdc_wsa2_macro_config_compander(lVar17,*(undefined1 *)(param_1 + 0x4c),2);
            bVar3 = *(byte *)(param_1 + 0x4c);
            uVar12 = (ulong)bVar3;
            if (*(char *)(lVar9 + 0x288) != '\0') {
              uVar13 = 0x4410;
              if (bVar3 != 0) {
                uVar13 = 0;
              }
              uVar14 = 0;
              if (bVar3 < 2) {
                uVar14 = 0x4780;
              }
              uVar1 = 2;
              if (bVar3 != 1) {
                uVar1 = bVar3 == 0;
              }
              uVar2 = 0x4490;
              if (bVar3 != 1) {
                uVar2 = uVar13;
              }
              if (1 < bVar3) goto LAB_00103ae4;
              lVar16 = 0;
              if ((*(int *)(lVar9 + 0x28c) != 0) &&
                 (*(int *)(lVar9 + 0x28c) != 2 || *(ushort *)(lVar9 + uVar12 * 4 + 0x10) < 5)) {
                if (*(char *)(lVar9 + 0x260) == '\0') {
                  lVar16 = 0;
                }
                else {
                  lVar16 = (ulong)(*(int *)(lVar9 + 0x1cc) == 0) << 7;
                }
              }
              snd_soc_component_update_bits(lVar17,uVar2,0x80,lVar16);
              snd_soc_component_update_bits(lVar17,uVar14,uVar1,uVar1);
              uVar12 = (ulong)*(byte *)(param_1 + 0x4c);
            }
            lpass_cdc_wsa2_macro_config_softclip(lVar17,uVar12,2);
            lpass_cdc_was_macro_config_pbr(lVar17,*(undefined1 *)(param_1 + 0x4c),2);
            if (*(int *)(lVar9 + 0x1cc) == 0) {
              return 0;
            }
            snd_soc_component_update_bits(lVar17,0x4408,8,0);
            return 0;
          }
          if (param_3 != 1) {
            return 0;
          }
          uVar11 = 1;
        }
        lpass_cdc_wsa2_macro_enable_prim_interpolator(lVar17,uVar10,uVar11);
        return 0;
      }
    }
    iVar6 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar6 == 0) {
      return 0xffffffea;
    }
    pcVar15 = "%s: priv is null for macro!\n";
  }
  uVar10 = *(undefined8 *)(lVar17 + -0xb8);
LAB_00103810:
  _dev_err(uVar10,pcVar15,"lpass_cdc_wsa2_macro_enable_interpolator");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_spk_boost_event @ 00103aec size=288
// signature: undefined lpass_cdc_wsa2_macro_spk_boost_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_spk_boost_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  char *__s1;
  undefined8 uVar5;
  long lVar6;
  
  __s1 = *(char **)(param_1 + 8);
  lVar6 = *(long *)(param_1 + 0x28);
  iVar1 = strcmp(__s1,"WSA2_RX INT0 CHAIN");
  if (iVar1 == 0) {
    uVar4 = 0x4408;
    uVar5 = 0x4500;
  }
  else {
    iVar1 = strcmp(__s1,"WSA2_RX INT1 CHAIN");
    if (iVar1 != 0) {
      iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_spk_boost_event__rs,
                           "lpass_cdc_wsa2_macro_spk_boost_event");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*(undefined8 *)(lVar6 + -0xb8),"%s: unknown widget: %s\n",
               "lpass_cdc_wsa2_macro_spk_boost_event",*(undefined8 *)(param_1 + 8));
      return 0xffffffea;
    }
    uVar4 = 0x4488;
    uVar5 = 0x4540;
  }
  lVar6 = lVar6 + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar6,uVar5,0x10,0);
    uVar2 = 1;
    uVar3 = 0;
  }
  else {
    if (param_3 != 1) {
      return 0;
    }
    snd_soc_component_update_bits(lVar6,uVar4,1,1);
    uVar2 = 0x10;
    uVar3 = 0x10;
    uVar4 = uVar5;
  }
  snd_soc_component_update_bits(lVar6,uVar4,uVar2,uVar3);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_vbat @ 00103c10 size=1172
// signature: undefined lpass_cdc_wsa2_macro_enable_vbat(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_enable_vbat(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  long lVar8;
  char *pcVar9;
  long lVar10;
  ulong uVar11;
  
  lVar8 = *(long *)(param_1 + 0x28);
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + -0xb8),4);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: null device for macro!\n";
  }
  else {
    lVar10 = *(long *)(lVar3 + 0x98);
    if ((lVar10 != 0) && (*(long *)(lVar10 + 0x108) != 0)) {
      pcVar9 = *(char **)(param_1 + 8);
      lVar8 = lVar8 + -0xd0;
      iVar2 = strcmp(pcVar9,"WSA2_RX INT0 VBAT");
      if (iVar2 == 0) {
        uVar11 = 0;
        uVar7 = 0x4408;
      }
      else {
        iVar2 = strcmp(pcVar9,"WSA2_RX INT1 VBAT");
        uVar11 = (ulong)(iVar2 == 0);
        uVar7 = 0x4488;
        if (iVar2 != 0) {
          uVar7 = 0;
        }
      }
      if (param_3 == 8) {
        snd_soc_component_update_bits(lVar8,0x4908,1,0);
        snd_soc_component_update_bits(lVar8,0x4904,1,0);
        snd_soc_component_update_bits(lVar8,0x4900,1,0);
        snd_soc_component_update_bits(lVar8,uVar7,0x80,0);
        snd_soc_component_update_bits(lVar8,0x4184,2,2);
        snd_soc_component_update_bits(lVar8,uVar7,2,0);
        snd_soc_component_update_bits(lVar8,0x41dc,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41e0,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41e4,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41e8,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41ec,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41f0,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41f4,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41f8,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41fc,0xff,0);
        lVar10 = lVar10 + uVar11 * 4;
        iVar2 = *(int *)(lVar10 + 0x1e0) + -1;
        *(int *)(lVar10 + 0x1e0) = iVar2;
        if (iVar2 == 0) {
          snd_soc_component_update_bits(lVar8,(int)uVar11 << 5 | 0x4640,1,0);
          snd_soc_component_update_bits(lVar8,0x4118,1 << uVar11,0);
        }
        snd_soc_component_update_bits(lVar8,0x4184,1,0);
        uVar4 = 0x4180;
        uVar5 = 0x10;
        uVar6 = 0;
      }
      else {
        if (param_3 != 1) {
          uVar4 = ___ratelimit(lpass_cdc_wsa2_macro_enable_vbat__rs,
                               "lpass_cdc_wsa2_macro_enable_vbat");
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          _dev_err(lVar3,"%s: Invalid event %d\n","lpass_cdc_wsa2_macro_enable_vbat",param_3);
          return 0;
        }
        snd_soc_component_update_bits(lVar8,0x4180,0x10,0x10);
        snd_soc_component_update_bits(lVar8,0x4184,1,1);
        snd_soc_component_update_bits(lVar8,uVar7,0x80,0x80);
        snd_soc_component_update_bits(lVar8,0x4184,2,0);
        lVar10 = lVar10 + uVar11 * 4;
        piVar1 = (int *)(lVar10 + 0x1e0);
        iVar2 = *(int *)(lVar10 + 0x1e0);
        if (iVar2 == 0) {
          snd_soc_component_update_bits(lVar8,(int)uVar11 << 5 | 0x4640,1,1);
          snd_soc_component_update_bits(lVar8,0x4118,1 << uVar11,1 << uVar11);
          iVar2 = *piVar1;
        }
        *piVar1 = iVar2 + 1;
        snd_soc_component_update_bits(lVar8,uVar7,2,2);
        snd_soc_component_update_bits(lVar8,0x41dc,0xff,0xff);
        snd_soc_component_update_bits(lVar8,0x41e0,0xff,3);
        snd_soc_component_update_bits(lVar8,0x41e4,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41e8,0xff,0xff);
        snd_soc_component_update_bits(lVar8,0x41ec,0xff,3);
        snd_soc_component_update_bits(lVar8,0x41f0,0xff,0);
        snd_soc_component_update_bits(lVar8,0x41f4,0xff,0xff);
        snd_soc_component_update_bits(lVar8,0x41f8,0xff,3);
        snd_soc_component_update_bits(lVar8,0x41fc,0xff,0);
        snd_soc_component_update_bits(lVar8,0x4900,1,1);
        snd_soc_component_update_bits(lVar8,0x4904,1,1);
        uVar4 = 0x4908;
        uVar5 = 1;
        uVar6 = 1;
      }
      snd_soc_component_update_bits(lVar8,uVar4,uVar5,uVar6);
      return 0;
    }
    iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar8 + -0xb8),pcVar9,"lpass_cdc_wsa2_macro_enable_vbat");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_mclk_event @ 001040a8 size=316
// signature: undefined lpass_cdc_wsa2_macro_mclk_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_mclk_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: null device for macro!\n";
  }
  else {
    puVar5 = *(undefined8 **)(lVar2 + 0x98);
    if ((puVar5 != (undefined8 *)0x0) && (puVar5[0x21] != 0)) {
      if (param_3 == 8) {
        if (*(char *)(puVar5 + 5) == '\0') {
          return 0;
        }
        lpass_cdc_wsa2_macro_mclk_enable(puVar5,0);
        *(undefined1 *)(puVar5 + 5) = 0;
        return 0;
      }
      if (param_3 == 1) {
        uVar3 = lpass_cdc_wsa2_macro_mclk_enable(puVar5,1);
        if ((int)uVar3 == 0) {
          *(undefined1 *)(puVar5 + 5) = 1;
          return uVar3;
        }
        *(undefined1 *)(puVar5 + 5) = 0;
        return uVar3;
      }
      iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_mclk_event__rs,"lpass_cdc_wsa2_macro_mclk_event");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*puVar5,"%s: invalid DAPM event %d\n","lpass_cdc_wsa2_macro_mclk_event",param_3);
      return 0xffffffea;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar6 + -0xb8),pcVar4,"lpass_cdc_wsa2_macro_mclk_event");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_vi_feed_mixer_get @ 001041e8 size=260
// signature: undefined lpass_cdc_wsa2_macro_vi_feed_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_vi_feed_mixer_get(long param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  
  lVar5 = snd_soc_dapm_kcontrol_widget();
  lVar7 = *(long *)(lVar5 + 0x28);
  bVar2 = *(byte *)(lVar5 + 0x4c);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + -0xb8),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (6 < bVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1042ec);
        (*pcVar3)();
      }
      if ((*(ulong *)(lVar5 + (ulong)bVar2 * 8 + ((ulong)(uVar1 >> 3) & 0x1ffffff8) + 0x118) >>
           ((ulong)uVar1 & 0x3f) & 1) == 0) {
        *(undefined8 *)(param_2 + 0x48) = 0;
        return 0;
      }
      *(undefined8 *)(param_2 + 0x48) = 1;
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + -0xb8),pcVar6,"lpass_cdc_wsa2_macro_vi_feed_mixer_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_vi_feed_mixer_put @ 001042f0 size=460
// signature: undefined lpass_cdc_wsa2_macro_vi_feed_mixer_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_vi_feed_mixer_put(long param_1,long param_2)

{
  ulong *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  
  lVar6 = snd_soc_dapm_kcontrol_widget();
  lVar9 = *(long *)(lVar6 + 0x28);
  iVar5 = *(int *)(param_2 + 0x48);
  iVar2 = *(int *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar7 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar9 + -0xb8),4);
  if (lVar7 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: null device for macro!\n";
LAB_00104464:
    _dev_err(*(undefined8 *)(lVar9 + -0xb8),pcVar8,"lpass_cdc_wsa2_macro_vi_feed_mixer_put");
    return 0xffffffea;
  }
  lVar7 = *(long *)(lVar7 + 0x98);
  if ((lVar7 == 0) || (*(long *)(lVar7 + 0x108) == 0)) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: priv is null for macro!\n";
    goto LAB_00104464;
  }
  *(int *)(lVar7 + 0x2c) = (int)*(undefined8 *)(param_2 + 0x48);
  if (iVar5 == 0) {
    if (iVar2 == 1) {
      if (((uint)*(undefined8 *)(lVar7 + 0x130) >> 1 & 1) == 0) goto LAB_0010442c;
      puVar1 = (ulong *)(lVar7 + 0x130);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else {
      if ((iVar2 != 0) || ((*(ulong *)(lVar7 + 0x130) & 1) == 0)) goto LAB_0010442c;
      puVar1 = (ulong *)(lVar7 + 0x130);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    lVar9 = -1;
  }
  else if (iVar2 == 1) {
    if (((uint)*(undefined8 *)(lVar7 + 0x130) >> 1 & 1) != 0) goto LAB_0010442c;
    puVar1 = (ulong *)(lVar7 + 0x130);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 2;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar9 = 1;
  }
  else {
    if ((iVar2 != 0) || ((*(ulong *)(lVar7 + 0x130) & 1) != 0)) goto LAB_0010442c;
    puVar1 = (ulong *)(lVar7 + 0x130);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar9 = 1;
  }
  *(long *)(lVar7 + 0x160) = *(long *)(lVar7 + 0x160) + lVar9;
LAB_0010442c:
  snd_soc_dapm_mixer_update_power(*(undefined8 *)(lVar6 + 0x28),param_1,iVar5,0);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_cps_feed_mixer_get @ 00104500 size=260
// signature: undefined lpass_cdc_wsa2_macro_cps_feed_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_cps_feed_mixer_get(long param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  
  lVar5 = snd_soc_dapm_kcontrol_widget();
  lVar7 = *(long *)(lVar5 + 0x28);
  bVar2 = *(byte *)(lVar5 + 0x4c);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + -0xb8),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (6 < bVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104604);
        (*pcVar3)();
      }
      if ((*(ulong *)(lVar5 + (ulong)bVar2 * 8 + ((ulong)(uVar1 >> 3) & 0x1ffffff8) + 0x118) >>
           ((ulong)uVar1 & 0x3f) & 1) == 0) {
        *(undefined8 *)(param_2 + 0x48) = 0;
        return 0;
      }
      *(undefined8 *)(param_2 + 0x48) = 1;
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + -0xb8),pcVar6,"lpass_cdc_wsa2_macro_cps_feed_mixer_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_cps_feed_mixer_put @ 00104608 size=452
// signature: undefined lpass_cdc_wsa2_macro_cps_feed_mixer_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_cps_feed_mixer_put(long param_1,long param_2)

{
  ulong *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  
  lVar6 = snd_soc_dapm_kcontrol_widget();
  lVar9 = *(long *)(lVar6 + 0x28);
  iVar5 = *(int *)(param_2 + 0x48);
  iVar2 = *(int *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar7 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar9 + -0xb8),4);
  if (lVar7 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: null device for macro!\n";
LAB_00104774:
    _dev_err(*(undefined8 *)(lVar9 + -0xb8),pcVar8,"lpass_cdc_wsa2_macro_cps_feed_mixer_put");
    return 0xffffffea;
  }
  lVar7 = *(long *)(lVar7 + 0x98);
  if ((lVar7 == 0) || (*(long *)(lVar7 + 0x108) == 0)) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: priv is null for macro!\n";
    goto LAB_00104774;
  }
  if (iVar5 == 0) {
    if (iVar2 == 1) {
      if (((uint)*(undefined8 *)(lVar7 + 0x140) >> 1 & 1) == 0) goto LAB_0010473c;
      puVar1 = (ulong *)(lVar7 + 0x140);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else {
      if ((iVar2 != 0) || ((*(ulong *)(lVar7 + 0x140) & 1) == 0)) goto LAB_0010473c;
      puVar1 = (ulong *)(lVar7 + 0x140);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    lVar9 = -1;
  }
  else if (iVar2 == 1) {
    if (((uint)*(undefined8 *)(lVar7 + 0x140) >> 1 & 1) != 0) goto LAB_0010473c;
    puVar1 = (ulong *)(lVar7 + 0x140);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 2;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar9 = 1;
  }
  else {
    if ((iVar2 != 0) || ((*(ulong *)(lVar7 + 0x140) & 1) != 0)) goto LAB_0010473c;
    puVar1 = (ulong *)(lVar7 + 0x140);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar9 = 1;
  }
  *(long *)(lVar7 + 0x170) = *(long *)(lVar7 + 0x170) + lVar9;
LAB_0010473c:
  snd_soc_dapm_mixer_update_power(*(undefined8 *)(lVar6 + 0x28),param_1,iVar5,0);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_rx_mux_get @ 00104810 size=216
// signature: undefined lpass_cdc_wsa2_macro_rx_mux_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_rx_mux_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  
  lVar3 = snd_soc_dapm_kcontrol_widget();
  lVar6 = *(long *)(lVar3 + 0x28);
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),4);
  if (lVar4 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: null device for macro!\n";
  }
  else {
    lVar4 = *(long *)(lVar4 + 0x98);
    if ((lVar4 != 0) && (*(long *)(lVar4 + 0x108) != 0)) {
      if (8 < (ulong)*(byte *)(lVar3 + 0x4c)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1048e8);
        (*pcVar1)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar4 + (ulong)*(byte *)(lVar3 + 0x4c) * 4 + 0x184)
      ;
      return 0;
    }
    iVar2 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar6 + -0xb8),pcVar5,"lpass_cdc_wsa2_macro_rx_mux_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_rx_mux_put @ 001048ec size=608
// signature: undefined lpass_cdc_wsa2_macro_rx_mux_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_rx_mux_put(long param_1,long param_2)

{
  uint *puVar1;
  ulong *puVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  char *pcVar10;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  ulong uVar14;
  undefined8 uVar15;
  long lVar16;
  
  lVar8 = snd_soc_dapm_kcontrol_widget();
  lVar16 = *(long *)(lVar8 + 0x28);
  uVar15 = *(undefined8 *)(param_1 + 0x78);
  uVar14 = *(ulong *)(param_2 + 0x48);
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + -0xb8),4);
  if (lVar9 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: null device for macro!\n";
LAB_00104b0c:
    _dev_err(*(undefined8 *)(lVar16 + -0xb8),pcVar10,"lpass_cdc_wsa2_macro_rx_mux_put");
    return 0xffffffea;
  }
  lVar11 = *(long *)(lVar9 + 0x98);
  if ((lVar11 == 0) || (*(long *)(lVar11 + 0x108) == 0)) {
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
    goto LAB_00104b0c;
  }
  if (8 < (ulong)*(byte *)(lVar8 + 0x4c)) {
LAB_00104b20:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x104b24);
    (*pcVar6)();
  }
  lVar16 = lVar11 + (ulong)*(byte *)(lVar8 + 0x4c) * 4;
  puVar1 = (uint *)(lVar16 + 0x184);
  uVar13 = (uint)uVar14;
  if (uVar13 == 0) {
    uVar13 = *(uint *)(lVar16 + 0x184);
    if (uVar13 == 0) {
      uVar15 = ___ratelimit(lpass_cdc_wsa2_macro_rx_mux_put__rs,"lpass_cdc_wsa2_macro_rx_mux_put");
      if ((int)uVar15 == 0) {
        return uVar15;
      }
      pcVar10 = "%s: AIF reset already\n";
    }
    else {
      if (uVar13 < 6) {
        lVar11 = lVar11 + (ulong)uVar13 * 8;
        *puVar1 = 0;
        if (*(long *)(lVar11 + 0x148) != 0) {
          bVar3 = *(byte *)(lVar8 + 0x4c);
          puVar2 = (ulong *)(lVar11 + 0x118 + (ulong)(bVar3 >> 6) * 8);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar5) {
              *puVar2 = *puVar2 & (1L << ((ulong)bVar3 & 0x3f) ^ 0xffffffffffffffffU);
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          lVar9 = -1;
          goto LAB_001049a4;
        }
        goto LAB_001049b0;
      }
      uVar15 = ___ratelimit(lpass_cdc_wsa2_macro_rx_mux_put__rs_133,
                            "lpass_cdc_wsa2_macro_rx_mux_put");
      if ((int)uVar15 == 0) {
        return uVar15;
      }
      pcVar10 = "%s: Invalid AIF reset\n";
    }
    _dev_err(lVar9,pcVar10,"lpass_cdc_wsa2_macro_rx_mux_put");
  }
  else {
    *puVar1 = uVar13;
    if (2 < uVar13) {
      iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_rx_mux_put__rs_135,"lpass_cdc_wsa2_macro_rx_mux_put"
                          );
      if (iVar7 == 0) {
        return 0xffffffea;
      }
      _dev_err(lVar9,"%s: Invalid AIF_ID for WSA2 RX MUX %d\n","lpass_cdc_wsa2_macro_rx_mux_put",
               uVar14 & 0xffffffff);
      return 0xffffffea;
    }
    uVar12 = uVar14 & 0xffffffff;
    if (6 < uVar12) goto LAB_00104b20;
    bVar3 = *(byte *)(lVar8 + 0x4c);
    puVar2 = (ulong *)(lVar11 + uVar12 * 8 + 0x118 + (ulong)(bVar3 >> 6) * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar5) {
        *puVar2 = *puVar2 | 1L << ((ulong)bVar3 & 0x3f);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    lVar11 = lVar11 + uVar12 * 8;
    lVar9 = 1;
LAB_001049a4:
    *(long *)(lVar11 + 0x148) = *(long *)(lVar11 + 0x148) + lVar9;
LAB_001049b0:
    snd_soc_dapm_mux_update_power
              (*(undefined8 *)(lVar8 + 0x28),param_1,uVar14 & 0xffffffff,uVar15,0);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_enable_prim_interpolator @ 00104b5c size=760
// signature: undefined lpass_cdc_wsa2_macro_enable_prim_interpolator(void)
// callers: [lpass_cdc_wsa2_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_wsa2_macro_enable_prim_interpolator(long param_1,ushort param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  ushort uVar10;
  undefined4 uVar11;
  long lVar12;
  ushort uVar13;
  
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar6 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return;
    }
    pcVar7 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x98);
    if ((lVar6 != 0) && (*(long *)(lVar6 + 0x108) != 0)) {
      lVar12 = 0;
      if (param_2 < 0x4480) {
        uVar13 = 0x4400;
        if ((param_2 != 0x4400) && (param_2 != 0x4418)) {
          uVar13 = 0;
        }
      }
      else if ((param_2 == 0x4498) || (uVar13 = 0, param_2 == 0x4480)) {
        uVar13 = 0x4480;
        lVar12 = 1;
      }
      if (param_3 == 8) {
        lVar6 = lVar6 + lVar12 * 2;
        sVar3 = *(short *)(lVar6 + 0x20) + -1;
        *(short *)(lVar6 + 0x20) = sVar3;
        if (sVar3 != 0) {
          return;
        }
        snd_soc_component_update_bits(param_1,uVar13,0x20,0);
        snd_soc_component_update_bits(param_1,uVar13 + 0x4c,1,0);
        snd_soc_component_update_bits(param_1,uVar13,0x40,0x40);
        snd_soc_component_update_bits(param_1,uVar13,0x40,0);
        iVar4 = 0x4404;
        if (uVar13 != 0x4400) {
          iVar4 = 0;
        }
        iVar1 = 0x4484;
        if (uVar13 != 0x4480) {
          iVar1 = iVar4;
        }
        if (iVar1 == 0) {
          return;
        }
        uVar10 = 0x4430;
        if (uVar13 != 0x4400) {
          uVar10 = 0;
        }
        param_2 = 0x44b0;
        if (uVar13 != 0x4480) {
          param_2 = uVar10;
        }
        snd_soc_component_update_bits(param_1,iVar1,4,0);
        snd_soc_component_update_bits(param_1,param_2,3,0);
        uVar8 = 0x3c;
        uVar9 = 0;
      }
      else {
        if (param_3 != 1) {
          return;
        }
        lVar6 = lVar6 + lVar12 * 2;
        sVar3 = *(short *)(lVar6 + 0x20);
        *(short *)(lVar6 + 0x20) = sVar3 + 1;
        if (sVar3 == 0) {
          snd_soc_component_update_bits(param_1,uVar13 + 0x10,3,3);
          snd_soc_component_update_bits(param_1,uVar13,0x10,0x10);
          iVar4 = 0x4404;
          if (uVar13 != 0x4400) {
            iVar4 = 0;
          }
          iVar1 = 0x4484;
          if (uVar13 != 0x4480) {
            iVar1 = iVar4;
          }
          if (iVar1 != 0) {
            uVar11 = 0x4430;
            if (uVar13 != 0x4400) {
              uVar11 = 0;
            }
            uVar2 = 0x44b0;
            if (uVar13 != 0x4480) {
              uVar2 = uVar11;
            }
            snd_soc_component_update_bits(param_1,uVar2,0x3c,0x10);
            snd_soc_component_update_bits(param_1,uVar2,3,1);
            snd_soc_component_update_bits(param_1,iVar1,4,4);
          }
          snd_soc_component_update_bits(param_1,uVar13 + 0x4c,1,1);
        }
        if (uVar13 == param_2) {
          return;
        }
        uVar5 = snd_soc_component_read(param_1,uVar13);
        if ((uVar5 >> 4 & 1) == 0) {
          return;
        }
        uVar8 = 0x10;
        uVar9 = 0x10;
      }
      snd_soc_component_update_bits(param_1,param_2,uVar8,uVar9);
      return;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar7,"lpass_cdc_wsa2_macro_enable_prim_interpolator");
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_config_compander @ 00104e54 size=752
// signature: undefined lpass_cdc_wsa2_macro_config_compander(void)
// callers: [lpass_cdc_wsa2_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_wsa2_macro_config_compander(long param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  long lVar9;
  char *pcVar10;
  uint uVar11;
  ulong uVar12;
  undefined4 uVar13;
  int iVar14;
  
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar9 == 0) {
    iVar8 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar8 == 0) {
      return;
    }
    pcVar10 = "%s: null device for macro!\n";
  }
  else {
    lVar9 = *(long *)(lVar9 + 0x98);
    if ((lVar9 != 0) && (*(long *)(lVar9 + 0x108) != 0)) {
      if (1 < (int)param_2) {
        _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Invalid compander value: %d\n",
                 "lpass_cdc_wsa2_macro_config_compander",param_2);
        return;
      }
      if (*(int *)(lVar9 + (ulong)param_2 * 4 + 8) == 0) {
        return;
      }
      lVar2 = lVar9 + (ulong)param_2 * 4;
      uVar5 = *(ushort *)(lVar2 + 0x10);
      iVar8 = *(int *)(lVar2 + 0x274);
      uVar11 = 0;
      if (uVar5 < 0x13) {
        uVar11 = (uint)uVar5;
      }
      uVar12 = (ulong)uVar11;
      if (iVar8 != 0) {
        uVar11 = *(int *)(lVar9 + 0x1cc) + param_2 * 2 & 0xffff;
        if (3 < uVar11) {
          _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Invalid index: %d\n",
                   "lpass_cdc_wsa2_macro_config_compander");
          return;
        }
        iVar4 = *(int *)(lVar9 + (ulong)uVar11 * 4 + 0x264);
        iVar6 = iVar4 * -0xf;
        iVar14 = iVar6 + 0xd2;
        uVar13 = 0xf;
        switch(iVar8) {
        case 1:
        case 4:
          iVar14 = iVar6 + 0x10e;
          uVar13 = 0;
          if (iVar4 < 6) {
            iVar14 = 0xd2;
          }
          break;
        default:
          uVar13 = 0;
          break;
        case 3:
        case 6:
          break;
        }
        if ((0xe0 < uVar12 * 0xc) ||
           (*(undefined4 *)(comp_setting_table + uVar12 * 0xc + 4) = uVar13, 0xe4 < uVar12 * 0xc)) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(1,0x105144);
          (*pcVar7)();
        }
        *(int *)(comp_setting_table + uVar12 * 0xc) = (iVar14 << 1) / 10;
      }
      uVar11 = param_2 * 0x60 + 0x4580;
      uVar1 = param_2 * 0x80 + 0x4404;
      if ((param_3 & 3) != 0) {
        lpass_cdc_update_compander_setting(param_1,param_2 * 0x60 + 0x45a0);
        uVar3 = uVar11 & 0xffff;
        snd_soc_component_update_bits(param_1,uVar3,1,1);
        snd_soc_component_update_bits(param_1,uVar3,2,2);
        snd_soc_component_update_bits(param_1,uVar3,2,0);
        snd_soc_component_update_bits(param_1,uVar1 & 0xffff,2,2);
      }
      if ((param_3 & 0xc) == 0) {
        return;
      }
      uVar11 = uVar11 & 0xffff;
      snd_soc_component_update_bits(param_1,uVar11,4,4);
      snd_soc_component_update_bits(param_1,uVar1 & 0xffff,2,0);
      snd_soc_component_update_bits(param_1,uVar11,2,2);
      snd_soc_component_update_bits(param_1,uVar11,2,0);
      snd_soc_component_update_bits(param_1,uVar11,1,0);
      snd_soc_component_update_bits(param_1,uVar11,4,0);
      return;
    }
    iVar8 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar8 == 0) {
      return;
    }
    pcVar10 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar10,"lpass_cdc_wsa2_macro_config_compander");
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_config_softclip @ 00105144 size=440
// signature: undefined lpass_cdc_wsa2_macro_config_softclip(void)
// callers: [lpass_cdc_wsa2_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_wsa2_macro_config_softclip(long param_1,int param_2,ulong param_3)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  ulong uVar8;
  
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x98);
    if ((lVar6 != 0) && (*(long *)(lVar6 + 0x108) != 0)) {
      uVar8 = (ulong)(param_2 == 1);
      if (*(int *)(lVar6 + uVar8 * 4 + 0x1d8) == 0) {
        return;
      }
      uVar4 = (uint)(param_2 == 1) << 5;
      uVar3 = (uint)(param_2 == 1) << 5 | 0x4644;
      if ((param_3 & 3) != 0) {
        lVar2 = lVar6 + uVar8 * 4;
        piVar1 = (int *)(lVar2 + 0x1e0);
        iVar5 = *(int *)(lVar2 + 0x1e0);
        if (iVar5 == 0) {
          snd_soc_component_update_bits(param_1,uVar4 | 0x4640,1,1);
          snd_soc_component_update_bits(param_1,0x4118,1 << uVar8,1 << uVar8);
          iVar5 = *piVar1;
        }
        *piVar1 = iVar5 + 1;
        snd_soc_component_update_bits(param_1,uVar3,1,1);
      }
      if ((param_3 & 0xc) == 0) {
        return;
      }
      snd_soc_component_update_bits(param_1,uVar3,1,0);
      lVar6 = lVar6 + uVar8 * 4;
      iVar5 = *(int *)(lVar6 + 0x1e0) + -1;
      *(int *)(lVar6 + 0x1e0) = iVar5;
      if (iVar5 == 0) {
        snd_soc_component_update_bits(param_1,uVar4 | 0x4640,1,0);
        snd_soc_component_update_bits(param_1,0x4118,1 << (ulong)(param_2 == 1),0);
        return;
      }
      return;
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar7,"lpass_cdc_wsa2_macro_config_softclip");
  return;
}



//------------------------------------------------------------
// lpass_cdc_was_macro_config_pbr @ 001052fc size=740
// signature: undefined lpass_cdc_was_macro_config_pbr(void)
// callers: [lpass_cdc_wsa2_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_was_macro_config_pbr(long param_1,uint param_2,ulong param_3)

{
  long lVar1;
  bool bVar2;
  char cVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  byte bVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  uint uVar12;
  
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),4);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: null device for macro!\n";
LAB_001053b8:
    _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar7,"lpass_cdc_was_macro_config_pbr");
    return;
  }
  lVar6 = *(long *)(lVar6 + 0x98);
  if ((lVar6 == 0) || (*(long *)(lVar6 + 0x108) == 0)) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: priv is null for macro!\n";
    goto LAB_001053b8;
  }
  if (param_2 == 0) {
    uVar9 = 0x4408;
    uVar10 = 0x4410;
    uVar11 = 0x4580;
    cVar3 = *(char *)(lVar6 + 0x260);
    uVar12 = 0;
  }
  else {
    if (param_2 != 1) {
      bVar8 = 0;
      uVar11 = 0;
      uVar10 = 0;
      uVar9 = 0;
      uVar12 = 0;
      cVar3 = *(char *)(lVar6 + 0x260);
      goto joined_r0x00105404;
    }
    uVar9 = 0x4488;
    uVar10 = 0x4490;
    uVar11 = 0x45e0;
    uVar12 = 1;
    cVar3 = *(char *)(lVar6 + 0x260);
  }
  bVar8 = 1;
joined_r0x00105404:
  if (cVar3 == '\0') {
    return;
  }
  if (1 < param_2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1055e0);
    (*pcVar4)();
  }
  if (3 < *(uint *)(lVar6 + (ulong)param_2 * 4 + 0x274)) {
    return;
  }
  if (6 < *(uint *)(lVar6 + (ulong)(param_2 << 1) * 4 + 0x264)) {
    return;
  }
  bVar2 = (bool)(bVar8 ^ 1);
  if (*(int *)(lVar6 + 0x1cc) != 0) {
    bVar2 = true;
  }
  if (bVar2) {
    return;
  }
  lVar1 = lVar6 + (ulong)uVar12 * 4;
  if ((param_3 & 3) != 0) {
    snd_soc_component_update_bits(param_1,uVar11,8,8);
    snd_soc_component_update_bits(param_1,uVar10,0x40,0x40);
    snd_soc_component_update_bits(param_1,uVar9,0x80,0x80);
    iVar5 = *(int *)(lVar1 + 0x1e0);
    if (iVar5 == 0) {
      snd_soc_component_update_bits(param_1,uVar12 << 5 | 0x4640,1,1);
      snd_soc_component_update_bits(param_1,0x4118,1 << (ulong)uVar12,1 << (ulong)uVar12);
      iVar5 = *(int *)(lVar1 + 0x1e0);
    }
    *(int *)(lVar1 + 0x1e0) = iVar5 + 1;
    iVar5 = *(int *)(lVar6 + 0x294);
    if (iVar5 == 0) {
      snd_soc_component_update_bits(param_1,0x4b00,1,1);
      iVar5 = *(int *)(lVar6 + 0x294);
    }
    *(int *)(lVar6 + 0x294) = iVar5 + 1;
  }
  if ((param_3 & 0xc) == 0) {
    return;
  }
  if (*(int *)(lVar6 + 0x294) != 0) {
    snd_soc_component_update_bits(param_1,0x4b00,1,0);
  }
  iVar5 = *(int *)(lVar1 + 0x1e0) + -1;
  *(int *)(lVar1 + 0x1e0) = iVar5;
  if (iVar5 == 0) {
    snd_soc_component_update_bits(param_1,uVar12 << 5 | 0x4640,1,0);
    snd_soc_component_update_bits(param_1,0x4118,1 << (ulong)uVar12,0);
  }
  snd_soc_component_update_bits(param_1,uVar11,8,0);
  snd_soc_component_update_bits(param_1,uVar10,0x40,0);
  snd_soc_component_update_bits(param_1,uVar9,0x80,0);
  iVar5 = *(int *)(lVar6 + 0x294) + -1;
  if (iVar5 < 1) {
    iVar5 = 0;
  }
  *(int *)(lVar6 + 0x294) = iVar5;
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_get @ 001055e4 size=64
// signature: undefined lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_get(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0x80),0x4184);
  *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 >> 2 & 1);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_put @ 00105628 size=60
// signature: undefined lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_put(long param_1,long param_2)

{
  snd_soc_component_update_bits
            (*(undefined8 *)(param_1 + 0x80),0x4184,4,(ulong)(*(long *)(param_2 + 0x48) != 0) << 2);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_comp_mode_get @ 00105668 size=248
// signature: undefined lpass_cdc_wsa2_macro_comp_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_comp_mode_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      strnstr(param_1 + 0x20,&DAT_00118ec8,9);
      lVar4 = strnstr(param_1 + 0x20,&DAT_00119e54,9);
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar2 + (ulong)(lVar4 != 0) * 4 + 0x10);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_comp_mode_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_comp_mode_put @ 00105764 size=264
// signature: undefined lpass_cdc_wsa2_macro_comp_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_comp_mode_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      strnstr(param_1 + 0x20,&DAT_00118ec8,9);
      lVar4 = strnstr(param_1 + 0x20,&DAT_00119e54,9);
      if (*(ulong *)(param_2 + 0x48) < 0x13) {
        *(int *)(lVar2 + (ulong)(lVar4 != 0) * 4 + 0x10) = (int)*(ulong *)(param_2 + 0x48);
        return 0;
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_comp_mode_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_ear_spkrrecv_get @ 00105870 size=180
// signature: undefined lpass_cdc_wsa2_macro_ear_spkrrecv_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_ear_spkrrecv_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar2 + 0x1cc);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_ear_spkrrecv_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_ear_spkrrecv_put @ 00105928 size=180
// signature: undefined lpass_cdc_wsa2_macro_ear_spkrrecv_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_ear_spkrrecv_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(int *)(lVar2 + 0x1cc) = (int)*(undefined8 *)(param_2 + 0x48);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_ear_spkrrecv_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_idle_detect_get @ 001059e0 size=180
// signature: undefined lpass_cdc_wsa2_macro_idle_detect_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_idle_detect_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(lVar2 + 0x288);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_idle_detect_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_idle_detect_put @ 00105a98 size=180
// signature: undefined lpass_cdc_wsa2_macro_idle_detect_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_idle_detect_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(char *)(lVar2 + 0x288) = (char)*(undefined8 *)(param_2 + 0x48);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_idle_detect_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_soft_clip_enable_get @ 00105b50 size=208
// signature: undefined lpass_cdc_wsa2_macro_soft_clip_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_soft_clip_enable_get(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (1 < uVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105c20);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 0x1d8);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa2_macro_soft_clip_enable_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_soft_clip_enable_put @ 00105c24 size=208
// signature: undefined lpass_cdc_wsa2_macro_soft_clip_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_soft_clip_enable_put(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (1 < uVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105cf4);
        (*pcVar3)();
      }
      *(int *)(lVar5 + (ulong)uVar2 * 4 + 0x1d8) = (int)*(undefined8 *)(param_2 + 0x48);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa2_macro_soft_clip_enable_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_set_digital_volume @ 00105cf8 size=372
// signature: undefined lpass_cdc_wsa2_macro_set_digital_volume(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_wsa2_macro_set_digital_volume(long param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  char *pcVar10;
  undefined8 *puVar11;
  
  lVar1 = *(long *)(param_1 + 0x78);
  lVar2 = *(long *)(param_1 + 0x80);
  lVar8 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar2 + 0x18),4);
  if (lVar8 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: null device for macro!\n";
  }
  else {
    puVar11 = *(undefined8 **)(lVar8 + 0x98);
    if ((puVar11 != (undefined8 *)0x0) && (puVar11[0x21] != 0)) {
      uVar4 = snd_soc_put_volsw(param_1,param_2);
      iVar7 = *(int *)(lVar1 + 0xc);
      if (iVar7 == 0x4494) {
        iVar6 = snd_soc_component_read(puVar11[0x21],0x4494);
        iVar7 = *(int *)(puVar11 + 0x45);
        *(char *)((long)puVar11 + 0x21d) = (char)iVar6;
        uVar5 = iVar6 - iVar7;
        cVar3 = *(char *)(puVar11 + 5);
joined_r0x00105e08:
        if (cVar3 == '\0') {
          return uVar4;
        }
        if (iVar7 == 0) {
          return uVar4;
        }
        snd_soc_component_update_bits(puVar11[0x21],*(undefined4 *)(lVar1 + 0xc),0xff,uVar5 & 0xff);
        return uVar4;
      }
      if (iVar7 == 0x4414) {
        uVar5 = snd_soc_component_read(puVar11[0x21],0x4414);
        iVar7 = *(int *)(puVar11 + 0x45);
        *(char *)((long)puVar11 + 0x21c) = (char)uVar5;
        uVar5 = (uVar5 & 0xff) - iVar7;
        cVar3 = *(char *)(puVar11 + 5);
        goto joined_r0x00105e08;
      }
      iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_set_digital_volume__rs_218,
                           "lpass_cdc_wsa2_macro_set_digital_volume");
      if (iVar7 == 0) {
        return 0xffffffea;
      }
      uVar9 = *puVar11;
      pcVar10 = "%s: Incorrect RX Path selected\n";
      goto LAB_00105e5c;
    }
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
  }
  uVar9 = *(undefined8 *)(lVar2 + 0x18);
LAB_00105e5c:
  _dev_err(uVar9,pcVar10,"lpass_cdc_wsa2_macro_set_digital_volume");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_get_rx_mute_status @ 00105e70 size=208
// signature: undefined lpass_cdc_wsa2_macro_get_rx_mute_status(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_get_rx_mute_status(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (8 < uVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105f40);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 0x1f8);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa2_macro_get_rx_mute_status");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_set_rx_mute_status @ 00105f44 size=416
// signature: undefined lpass_cdc_wsa2_macro_set_rx_mute_status(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_set_rx_mute_status(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  
  lVar10 = *(long *)(param_1 + 0x80);
  iVar3 = *(int *)(param_2 + 0x48);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar10 + 0x18),4);
  if (lVar5 == 0) {
    iVar3 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: null device for macro!\n";
LAB_001060ac:
    _dev_err(*(undefined8 *)(lVar10 + 0x18),pcVar7,"lpass_cdc_wsa2_macro_set_rx_mute_status");
    return 0xffffffea;
  }
  plVar9 = *(long **)(lVar5 + 0x98);
  if ((plVar9 == (long *)0x0) || (plVar9[0x21] == 0)) {
    iVar3 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: priv is null for macro!\n";
    goto LAB_001060ac;
  }
  __pm_runtime_resume(*plVar9,4);
  switch((ulong)uVar1) {
  case 0:
    uVar8 = 0x4400;
    break;
  case 1:
    uVar8 = 0x4480;
    break;
  case 2:
    uVar8 = 0x4418;
    break;
  case 3:
    uVar8 = 0x4498;
    break;
  default:
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_set_rx_mute_status__rs,
                         "lpass_cdc_wsa2_macro_set_rx_mute_status");
    if (iVar4 != 0) {
      _printk(&DAT_00119d43,"lpass_cdc_wsa2_macro_set_rx_mute_status",uVar1);
    }
    uVar8 = 0xffffffea;
    goto LAB_00106060;
  }
  snd_soc_component_update_bits(lVar10,uVar8,0x10,iVar3 << 4);
  uVar8 = 0;
LAB_00106060:
  lVar10 = *plVar9;
  uVar6 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar10 + 0x220) = uVar6;
  __pm_runtime_suspend(*plVar9,0xd);
  if (8 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1060e4);
    (*pcVar2)();
  }
  *(int *)((long)plVar9 + (ulong)uVar1 * 4 + 0x1f8) = iVar3;
  return uVar8;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_get_compander @ 001060e8 size=208
// signature: undefined lpass_cdc_wsa2_macro_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_get_compander(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (1 < uVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1061b8);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 8);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa2_macro_get_compander");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_set_compander @ 001061bc size=204
// signature: undefined lpass_cdc_wsa2_macro_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_set_compander(long param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(undefined4 *)(param_2 + 0x48);
  uVar3 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x98);
    if ((lVar6 != 0) && (*(long *)(lVar6 + 0x108) != 0)) {
      if (1 < uVar3) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x106288);
        (*pcVar4)();
      }
      *(undefined4 *)(lVar6 + (ulong)uVar3 * 4 + 8) = uVar2;
      return 0;
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar7,"lpass_cdc_wsa2_macro_set_compander");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_get_ec_hq @ 0010628c size=208
// signature: undefined lpass_cdc_wsa2_macro_get_ec_hq(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_get_ec_hq(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0x108) != 0)) {
      if (1 < uVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10635c);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 0x18);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa2_macro_get_ec_hq");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_set_ec_hq @ 00106360 size=204
// signature: undefined lpass_cdc_wsa2_macro_set_ec_hq(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_set_ec_hq(long param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(undefined4 *)(param_2 + 0x48);
  uVar3 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),4);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x98);
    if ((lVar6 != 0) && (*(long *)(lVar6 + 0x108) != 0)) {
      if (1 < uVar3) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10642c);
        (*pcVar4)();
      }
      *(undefined4 *)(lVar6 + (ulong)uVar3 * 4 + 0x18) = uVar2;
      return 0;
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar7,"lpass_cdc_wsa2_macro_set_ec_hq");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_pbr_enable_get @ 00106430 size=180
// signature: undefined lpass_cdc_wsa2_macro_pbr_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_pbr_enable_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(lVar2 + 0x260);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_pbr_enable_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_pbr_enable_put @ 001064e8 size=188
// signature: undefined lpass_cdc_wsa2_macro_pbr_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_pbr_enable_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(bool *)(lVar2 + 0x260) = *(long *)(param_2 + 0x48) != 0;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_pbr_enable_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_2ch_dma_enable_get @ 001065a8 size=180
// signature: undefined lpass_cdc_wsa2_macro_2ch_dma_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_2ch_dma_enable_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(lVar2 + 0x2a0);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_2ch_dma_enable_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_2ch_dma_enable_put @ 00106660 size=188
// signature: undefined lpass_cdc_wsa2_macro_2ch_dma_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_2ch_dma_enable_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      *(bool *)(lVar2 + 0x2a0) = *(long *)(param_2 + 0x48) != 0;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa2_macro_2ch_dma_enable_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_get_channel_map @ 00106720 size=668
// signature: undefined lpass_cdc_wsa2_macro_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
lpass_cdc_wsa2_macro_get_channel_map
          (long param_1,uint *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  ulong uVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  char *pcVar8;
  uint uVar9;
  long lVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  long lVar16;
  
  lVar16 = *(long *)(param_1 + 0x58);
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + 0x18),4);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: null device for macro!\n";
  }
  else {
    lVar10 = *(long *)(lVar6 + 0x98);
    if ((lVar10 != 0) && (*(long *)(lVar10 + 0x108) != 0)) {
      switch(*(uint *)(param_1 + 8)) {
      case 1:
      case 2:
        uVar15 = *(ulong *)(lVar10 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x118);
        uVar7 = (uVar15 & 0xaa) >> 1 | (uVar15 & 0x155) << 1;
        uVar1 = (uVar7 & 0xcccccccccccccccc) >> 2 | (uVar7 & 0x3333333333333333) << 2;
        uVar7 = 9;
        if ((uVar15 & 0x1ff) != 0) {
          uVar7 = LZCOUNT(((uVar1 & 0xf0f0f0f0f0f0f0f) >> 4 |
                          ((uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf000f000f000f) << 4) << 8)
                          << 0x30);
        }
        if ((uint)uVar7 < 9) {
          uVar11 = 1;
          uVar13 = 1 << (ulong)((uint)uVar7 & 0x1f);
          uVar9 = uVar13 & 0xffff;
          if (uVar7 < 8) {
            uVar14 = (uint)(-2L << (uVar7 & 0x3f)) & (uint)uVar15;
            uVar7 = ((ulong)uVar14 & 0xaa) >> 1 | ((ulong)uVar14 & 0x154) << 1;
            uVar7 = (uVar7 & 0xcccccccccccccccc) >> 2 | (uVar7 & 0x3333333333333333) << 2;
            uVar12 = 9;
            if ((uVar14 & 0x1fe) != 0) {
              uVar12 = (uint)LZCOUNT(((uVar7 & 0xf0f0f0f0f0f0f0f) >> 4 |
                                     ((uVar7 & 0xf0f0f0f0f0f0f0f0) >> 4 |
                                     (uVar7 & 0xf000f000f000f) << 4) << 8) << 0x30);
            }
            uVar11 = 1;
            if (uVar12 < 9) {
              uVar11 = 2;
              uVar9 = (uVar13 | 1 << (ulong)(uVar12 & 0x1f)) & 0xffff;
            }
          }
        }
        else {
          uVar9 = 0;
          uVar11 = 0;
        }
        uVar13 = uVar9 << 2;
        if ((uVar9 & 0x30) != 0) {
          uVar13 = uVar9 >> 4;
        }
        *param_5 = uVar13;
        *param_4 = uVar11;
        return 0;
      case 3:
        uVar7 = *(ulong *)(lVar10 + 0x130);
        lVar6 = 2;
        if ((uVar7 & 3) != 0) {
          lVar6 = LZCOUNT(((uVar7 & 2) >> 1 | (uVar7 & 1) << 1) << 0x3e);
        }
        if ((uint)lVar6 < 2) {
          uVar13 = 1;
          uVar9 = 1 << (ulong)((uint)lVar6 & 0x1f);
          if (lVar6 == 0) {
            uVar14 = 2;
            if ((uVar7 & 2) != 0) {
              uVar14 = (uint)LZCOUNT(((uVar7 & 2) >> 1) << 0x3e);
            }
            uVar13 = 1;
            if (uVar14 < 2) {
              uVar13 = 2;
              uVar9 = 1 << (ulong)(uVar14 & 0x1f) | 1;
            }
          }
        }
        else {
          uVar9 = 0;
          uVar13 = 0;
        }
        if ((uVar9 & 0xffff) != 0 && *(char *)(lVar10 + 0x2a0) == '\0') {
          uVar9 = uVar9 << 2;
        }
        *param_3 = uVar9 & 0xffff;
        *param_2 = uVar13;
        return 0;
      case 4:
        uVar7 = snd_soc_component_read(lVar16,0x4110);
        bVar3 = (uVar7 & 0x18) != 0;
        uVar9 = 1;
        if (bVar3) {
          uVar9 = 2;
        }
        bVar4 = (uVar7 & 3) != 0;
        uVar13 = (uint)bVar3;
        if (!bVar4) {
          uVar9 = uVar13;
        }
        *param_3 = (uint)bVar4 | uVar13 << 1;
        *param_2 = uVar9;
        return 0;
      case 5:
        goto switchD_00106794_caseD_5;
      default:
        _dev_err(lVar6,"%s: Invalid AIF\n","lpass_cdc_wsa2_macro_get_channel_map");
        return 0;
      }
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar16 + 0x18),pcVar8,"lpass_cdc_wsa2_macro_get_channel_map");
  return 0xffffffea;
switchD_00106794_caseD_5:
  *param_3 = (uint)*(undefined8 *)(lVar10 + 0x140);
  if (5 < *(uint *)(param_1 + 8)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1069bc);
    (*pcVar2)();
  }
  *param_2 = (uint)*(undefined8 *)(lVar10 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x148);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_mute_stream @ 001069c0 size=904
// signature: undefined lpass_cdc_wsa2_macro_mute_stream(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_mute_stream(long param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  
  if (param_2 == 0) {
    lVar8 = *(long *)(param_1 + 0x58);
    lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + 0x18),4);
    if (lVar5 == 0) {
      iVar3 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      pcVar6 = "%s: null device for macro!\n";
    }
    else {
      lVar9 = *(long *)(lVar5 + 0x98);
      if ((lVar9 != 0) && (*(long *)(lVar9 + 0x108) != 0)) {
        uVar7 = *(uint *)(param_1 + 8);
        if (uVar7 - 1 < 2) {
          lpass_cdc_wsa_pa_on(lVar5,0);
          if (*(int *)(param_1 + 8) - 1U < 2) {
            uVar4 = *(undefined8 *)(param_1 + 0x58);
            snd_soc_component_update_bits(uVar4,0x4400,0x10,0);
            snd_soc_component_update_bits(uVar4,0x4418,0x10,0);
            snd_soc_component_update_bits(uVar4,0x4480,0x10,0);
            snd_soc_component_update_bits(uVar4,0x4498,0x10,0);
          }
          lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + 0x18),4);
          if (lVar5 == 0) {
            iVar3 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
            if (iVar3 != 0) {
              pcVar6 = "%s: null device for macro!\n";
LAB_00106d30:
              _dev_err(*(undefined8 *)(lVar8 + 0x18),pcVar6,
                       "lpass_cdc_wsa2_macro_enable_vi_decimator");
            }
          }
          else {
            lVar5 = *(long *)(lVar5 + 0x98);
            if ((lVar5 == 0) || (*(long *)(lVar5 + 0x108) == 0)) {
              iVar3 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,
                                   "lpass_cdc_wsa2_macro_get_data");
              if (iVar3 != 0) {
                pcVar6 = "%s: priv is null for macro!\n";
                goto LAB_00106d30;
              }
            }
            else {
              usleep_range_state(5000,0x157c,2);
              iVar1 = *(int *)(lVar5 + 500);
              iVar3 = 4;
              if (iVar1 != 48000) {
                iVar3 = (uint)(iVar1 == 24000) << 1;
              }
              if ((*(ulong *)(lVar5 + 0x130) & 1) != 0) {
                snd_soc_component_update_bits((ulong)(iVar1 == 24000) << 1,lVar8,0x4244,0x20,0x20);
                snd_soc_component_update_bits(lVar8,0x4264,0x20,0x20);
                snd_soc_component_update_bits(lVar8,0x4244,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x4264,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x4244,0x10,0x10);
                snd_soc_component_update_bits(lVar8,0x4264,0x10,0x10);
                snd_soc_component_update_bits(lVar8,0x4244,0x20,0);
                snd_soc_component_update_bits(lVar8,0x4264,0x20,0);
              }
              if (((uint)*(undefined8 *)(lVar5 + 0x130) >> 1 & 1) != 0) {
                snd_soc_component_update_bits(lVar8,0x4284,0x20,0x20);
                snd_soc_component_update_bits(lVar8,0x42a4,0x20,0x20);
                snd_soc_component_update_bits(lVar8,0x4284,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x42a4,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x4284,0x10,0x10);
                snd_soc_component_update_bits(lVar8,0x42a4,0x10,0x10);
                snd_soc_component_update_bits(lVar8,0x4284,0x20,0);
                snd_soc_component_update_bits(lVar8,0x42a4,0x20,0);
              }
            }
          }
          uVar7 = *(uint *)(param_1 + 8);
        }
        if (6 < uVar7) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106d48);
          (*pcVar2)();
        }
        lVar5 = lVar9 + (ulong)uVar7 * 8;
        if ((((uint)*(undefined8 *)(lVar5 + 0x118) >> 4 & 1) != 0) ||
           (((uint)*(undefined8 *)(lVar5 + 0x118) >> 5 & 1) != 0)) {
          if (*(long *)(lVar9 + 0x298) == 0) {
            return 0;
          }
          uVar4 = readl();
          if ((int)uVar4 != 1) {
            writel(uVar4,*(undefined8 *)(lVar9 + 0x298));
          }
        }
        goto LAB_001069dc;
      }
      iVar3 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      pcVar6 = "%s: priv is null for macro!\n";
    }
    _dev_err(*(undefined8 *)(lVar8 + 0x18),pcVar6,"lpass_cdc_wsa2_macro_mute_stream");
    uVar4 = 0xffffffea;
  }
  else {
LAB_001069dc:
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_hw_params @ 00106d4c size=1900
// signature: undefined lpass_cdc_wsa2_macro_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_hw_params(long param_1,long param_2,long param_3)

{
  long lVar1;
  undefined1 uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  long lVar9;
  char *pcVar10;
  long lVar11;
  undefined2 uVar12;
  ulong uVar13;
  uint uVar14;
  undefined8 uVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  
  lVar17 = *(long *)(param_3 + 0x58);
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + 0x18),4);
  if (lVar9 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: null device for macro!\n";
LAB_00106fe4:
    _dev_err(*(undefined8 *)(lVar17 + 0x18),pcVar10,"lpass_cdc_wsa2_macro_hw_params");
    return 0xffffffea;
  }
  lVar9 = *(long *)(lVar9 + 0x98);
  if ((lVar9 == 0) || (*(long *)(lVar9 + 0x108) == 0)) {
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
    goto LAB_00106fe4;
  }
  if (*(int *)(param_1 + 0x3c) == 1) {
    if (*(int *)(param_3 + 8) == 3) {
      *(undefined4 *)(lVar9 + 500) = *(undefined4 *)(param_2 + 0x128);
    }
    uVar14 = *(uint *)(param_2 + 0x24);
    if (uVar14 == 0) {
      uVar14 = *(uint *)(param_2 + 0x28);
      if (uVar14 != 0) {
        uVar4 = 0x20;
        goto LAB_00106f9c;
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
LAB_00106f9c:
      uVar14 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
      uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
      uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
      uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
      uVar4 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10) | uVar4;
    }
    iVar7 = snd_pcm_format_width(uVar4);
    if (iVar7 == 0x20) {
LAB_001073b4:
      if (*(uint *)(param_3 + 8) < 6) {
        lVar9 = lVar9 + (ulong)*(uint *)(param_3 + 8) * 2;
        uVar12 = 0x20;
LAB_001073e0:
        *(undefined2 *)(lVar9 + 0x178) = uVar12;
        return 0;
      }
      goto LAB_001074b4;
    }
    if (iVar7 == 0x18) {
LAB_001073cc:
      if (*(uint *)(param_3 + 8) < 6) {
        lVar9 = lVar9 + (ulong)*(uint *)(param_3 + 8) * 2;
        uVar12 = 0x18;
        goto LAB_001073e0;
      }
      goto LAB_001074b4;
    }
    if (iVar7 == 0x10) {
      uVar14 = *(uint *)(param_3 + 8);
joined_r0x00106fcc:
      if (uVar14 < 6) {
        lVar9 = lVar9 + (ulong)uVar14 * 2;
        uVar12 = 0x10;
        goto LAB_001073e0;
      }
      goto LAB_001074b4;
    }
    iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_hw_params__rs_245,"lpass_cdc_wsa2_macro_hw_params");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    uVar14 = *(uint *)(param_2 + 0x24);
    uVar15 = *(undefined8 *)(lVar17 + 0x18);
    if (uVar14 == 0) {
      uVar14 = *(uint *)(param_2 + 0x28);
joined_r0x00107020:
      if (uVar14 != 0) {
        uVar4 = 0x20;
        goto LAB_00107464;
      }
      uVar4 = 0;
    }
    else {
LAB_00107460:
      uVar4 = 0;
LAB_00107464:
      uVar14 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
      uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
      uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
      uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
      uVar4 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10) | uVar4;
    }
    uVar8 = snd_pcm_format_width(uVar4);
    pcVar10 = "%s: Invalid format 0x%x\n";
    goto LAB_0010748c;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    return 0;
  }
  iVar7 = *(int *)(param_2 + 0x128);
  if (iVar7 == 48000) {
    lVar11 = 0;
LAB_00106dc4:
    lVar16 = *(long *)(param_3 + 0x58);
    uVar2 = int_mix_sample_rate_val[lVar11 * 8 + 4];
    lVar11 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + 0x18),4);
    if (lVar11 == 0) {
      iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
      if (iVar5 != 0) {
        pcVar10 = "%s: null device for macro!\n";
LAB_0010744c:
        _dev_err(*(undefined8 *)(lVar16 + 0x18),pcVar10,
                 "lpass_cdc_wsa2_macro_set_mix_interpolator_rate");
      }
    }
    else {
      lVar18 = *(long *)(lVar11 + 0x98);
      if ((lVar18 != 0) && (*(long *)(lVar18 + 0x108) != 0)) {
        uVar14 = *(uint *)(param_3 + 8);
        if (uVar14 < 7) {
          uVar13 = 0;
          do {
            if (8 < uVar13) {
LAB_00107150:
              if (iVar7 < 24000) {
                if (iVar7 == 8000) goto LAB_00107180;
                if (iVar7 == 16000) goto LAB_00107178;
                goto LAB_00107068;
              }
              if (iVar7 == 24000) goto LAB_00107328;
              if (iVar7 == 32000) goto LAB_001071a4;
              goto LAB_00107068;
            }
            uVar14 = (uint)(-1L << (uVar13 & 0x3f)) & *(uint *)(lVar18 + (ulong)uVar14 * 8 + 0x118);
            uVar13 = ((ulong)uVar14 & 0xaa) >> 1 | ((ulong)uVar14 & 0x155) << 1;
            uVar13 = (uVar13 & 0xcccccccccccccccc) >> 2 | (uVar13 & 0x3333333333333333) << 2;
            lVar1 = 9;
            if ((uVar14 & 0x1ff) != 0) {
              lVar1 = LZCOUNT(((uVar13 & 0xf0f0f0f0f0f0f0f) >> 4 |
                              ((uVar13 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar13 & 0xf000f000f000f) << 4)
                              << 8) << 0x30);
            }
            uVar14 = (uint)lVar1;
            if (8 < uVar14) goto LAB_00107150;
            if (3 < uVar14) {
              iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_set_mix_interpolator_rate__rs,
                                   "lpass_cdc_wsa2_macro_set_mix_interpolator_rate");
              if (iVar5 != 0) {
                _dev_err(lVar11,"%s: Invalid RX port, Dai ID is %d\n",
                         "lpass_cdc_wsa2_macro_set_mix_interpolator_rate",
                         *(undefined4 *)(param_3 + 8));
              }
              goto LAB_00107150;
            }
            uVar4 = snd_soc_component_read(lVar16,0x4104);
            if ((uVar4 & 7) == uVar14 + 1) {
              snd_soc_component_update_bits(lVar16,0x4418,0xf,uVar2);
            }
            uVar4 = snd_soc_component_read(lVar16,0x410c);
            if ((uVar4 & 7) == uVar14 + 1) {
              snd_soc_component_update_bits(lVar16,0x4498,0xf,uVar2);
            }
            uVar14 = *(uint *)(param_3 + 8);
            uVar13 = lVar1 + 1;
          } while (uVar14 < 7);
        }
        goto LAB_001074b4;
      }
      iVar5 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
      if (iVar5 != 0) {
        pcVar10 = "%s: priv is null for macro!\n";
        goto LAB_0010744c;
      }
    }
LAB_00107068:
    if (iVar7 == 48000) {
      lVar11 = 4;
    }
    else if (iVar7 < 0x2ee00) {
      if (iVar7 == 0xac44) {
LAB_00107130:
        lVar11 = 8;
      }
      else {
        if (iVar7 != 96000) goto LAB_00107328;
        lVar11 = 5;
      }
    }
    else {
      if (iVar7 != 0x2ee00) {
        if (iVar7 == 0x5dc00) goto LAB_00107128;
        goto LAB_00107328;
      }
      lVar11 = 6;
    }
LAB_001071b0:
    lVar16 = *(long *)(param_3 + 0x58);
    uVar2 = int_prim_sample_rate_val[lVar11 * 8 + 4];
    lVar11 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + 0x18),4);
    if (lVar11 == 0) {
      iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs,"lpass_cdc_wsa2_macro_get_data");
      if (iVar7 != 0) {
        pcVar10 = "%s: null device for macro!\n";
        goto LAB_00107430;
      }
    }
    else {
      lVar11 = *(long *)(lVar11 + 0x98);
      if ((lVar11 != 0) && (*(long *)(lVar11 + 0x108) != 0)) {
        uVar14 = *(uint *)(param_3 + 8);
        if (uVar14 < 7) {
          uVar13 = 0;
          do {
            if (8 < uVar13) {
LAB_0010735c:
              uVar14 = *(uint *)(param_2 + 0x24);
              if (uVar14 == 0) {
                uVar14 = *(uint *)(param_2 + 0x28);
                if (uVar14 != 0) {
                  uVar4 = 0x20;
                  goto LAB_0010737c;
                }
                uVar4 = 0;
              }
              else {
                uVar4 = 0;
LAB_0010737c:
                uVar14 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
                uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
                uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
                uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
                uVar4 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10) | uVar4;
              }
              iVar7 = snd_pcm_format_width(uVar4);
              if (iVar7 == 0x20) goto LAB_001073b4;
              if (iVar7 == 0x18) goto LAB_001073cc;
              if (iVar7 == 0x10) {
                uVar14 = *(uint *)(param_3 + 8);
                goto joined_r0x00106fcc;
              }
              iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_hw_params__rs_243,
                                   "lpass_cdc_wsa2_macro_hw_params");
              if (iVar7 == 0) {
                return 0xffffffea;
              }
              uVar14 = *(uint *)(param_2 + 0x24);
              uVar15 = *(undefined8 *)(lVar17 + 0x18);
              if (uVar14 != 0) goto LAB_00107460;
              uVar14 = *(uint *)(param_2 + 0x28);
              goto joined_r0x00107020;
            }
            uVar14 = (uint)(-1L << (uVar13 & 0x3f)) & *(uint *)(lVar11 + (ulong)uVar14 * 8 + 0x118);
            uVar13 = ((ulong)uVar14 & 0xaa) >> 1 | ((ulong)uVar14 & 0x155) << 1;
            uVar13 = (uVar13 & 0xcccccccccccccccc) >> 2 | (uVar13 & 0x3333333333333333) << 2;
            lVar18 = 9;
            if ((uVar14 & 0x1ff) != 0) {
              lVar18 = LZCOUNT(((uVar13 & 0xf0f0f0f0f0f0f0f) >> 4 |
                               ((uVar13 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar13 & 0xf000f000f000f) << 4
                               ) << 8) << 0x30);
            }
            if (8 < (uint)lVar18) goto LAB_0010735c;
            uVar14 = (uint)lVar18 + 1;
            uVar4 = snd_soc_component_read(lVar16,0x4100);
            uVar6 = snd_soc_component_read(lVar16,0x4104);
            if (((uVar4 & 7) == uVar14 || (uVar4 >> 3 & 7) == uVar14) || (uVar6 >> 3 & 7) == uVar14)
            {
              snd_soc_component_update_bits(lVar16,0x4400,0xf,uVar2);
            }
            uVar4 = snd_soc_component_read(lVar16,0x4108);
            uVar6 = snd_soc_component_read(lVar16,0x410c);
            if ((((uVar4 & 7) == uVar14) || ((uVar4 >> 3 & 7) == uVar14)) ||
               ((uVar6 >> 3 & 7) == uVar14)) {
              snd_soc_component_update_bits(lVar16,0x4480,0xf,uVar2);
            }
            uVar14 = *(uint *)(param_3 + 8);
            uVar13 = lVar18 + 1;
          } while (uVar14 < 7);
        }
LAB_001074b4:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1074b8);
        (*pcVar3)();
      }
      iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_get_data__rs_112,"lpass_cdc_wsa2_macro_get_data");
      if (iVar7 != 0) {
        pcVar10 = "%s: priv is null for macro!\n";
LAB_00107430:
        _dev_err(*(undefined8 *)(lVar16 + 0x18),pcVar10,
                 "lpass_cdc_wsa2_macro_set_prim_interpolator_rate");
      }
    }
  }
  else {
    if (iVar7 < 0xac44) {
      if (iVar7 == 8000) {
LAB_00107180:
        lVar11 = 0;
      }
      else if (iVar7 == 16000) {
LAB_00107178:
        lVar11 = 1;
      }
      else {
        if (iVar7 != 32000) goto LAB_00107328;
LAB_001071a4:
        lVar11 = 3;
      }
      goto LAB_001071b0;
    }
    if (iVar7 < 0x2ee00) {
      if (iVar7 == 0xac44) goto LAB_00107130;
      if (iVar7 == 96000) {
        lVar11 = 1;
        goto LAB_00106dc4;
      }
    }
    else {
      if (iVar7 == 0x5dc00) {
LAB_00107128:
        lVar11 = 7;
        goto LAB_001071b0;
      }
      if (iVar7 == 0x2ee00) {
        lVar11 = 2;
        goto LAB_00106dc4;
      }
    }
  }
LAB_00107328:
  iVar7 = ___ratelimit(lpass_cdc_wsa2_macro_hw_params__rs,"lpass_cdc_wsa2_macro_hw_params");
  if (iVar7 == 0) {
    return 0xffffffea;
  }
  uVar15 = *(undefined8 *)(lVar17 + 0x18);
  pcVar10 = "%s: cannot set sample rate: %u\n";
  uVar8 = *(undefined4 *)(param_2 + 0x128);
LAB_0010748c:
  _dev_err(uVar15,pcVar10,"lpass_cdc_wsa2_macro_hw_params",uVar8);
  return 0xffffffea;
}



//------------------------------------------------------------
// readl @ 001074b8 size=140
// signature: undefined readl(void)
// callers: [lpass_cdc_wsa2_macro_mute_stream]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x107510,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00107544 size=132
// signature: undefined writel(void)
// callers: [lpass_cdc_wsa2_macro_mute_stream]
//------------------------------------------------------------

void writel(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(1,0x20,param_2,writel,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = 1;
  log_post_write_mmio(1,0x20,param_2,0x107598,uVar1);
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_get_max_state @ 001075cc size=100
// signature: undefined lpass_cdc_wsa2_macro_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_get_max_state(long param_1,ulong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x3b0) == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_max_state__rs,"lpass_cdc_wsa2_macro_get_max_state"
                        );
    if (iVar1 != 0) {
      _printk(&DAT_0011a1c0,"lpass_cdc_wsa2_macro_get_max_state");
    }
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x22c);
  }
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_get_cur_state @ 00107634 size=100
// signature: undefined lpass_cdc_wsa2_macro_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa2_macro_get_cur_state(long param_1,ulong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x3b0) == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_get_cur_state__rs,"lpass_cdc_wsa2_macro_get_cur_state"
                        );
    if (iVar1 != 0) {
      _printk(&DAT_0011a1c0,"lpass_cdc_wsa2_macro_get_cur_state");
    }
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x228);
  }
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_wsa2_macro_set_cur_state @ 0010769c size=204
// signature: undefined lpass_cdc_wsa2_macro_set_cur_state(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 lpass_cdc_wsa2_macro_set_cur_state(long param_1,ulong param_2)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x3b0);
  if ((plVar2 == (long *)0x0) || (*plVar2 == 0)) {
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_set_cur_state__rs,"lpass_cdc_wsa2_macro_set_cur_state"
                        );
    if (iVar1 != 0) {
      _printk(&DAT_0011a1c0,"lpass_cdc_wsa2_macro_set_cur_state");
    }
  }
  else {
    if (param_2 <= *(uint *)((long)plVar2 + 0x22c)) {
      *(int *)(plVar2 + 0x45) = (int)param_2;
      queue_work_on(0x20,_system_wq,plVar2 + 0x46);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa2_macro_set_cur_state__rs_249,
                         "lpass_cdc_wsa2_macro_set_cur_state");
    if (iVar1 != 0) {
      _dev_err(*plVar2,"%s: incorrect requested state:%d\n","lpass_cdc_wsa2_macro_set_cur_state",
               param_2);
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// init_module @ 00107770 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpass_cdc_wsa2_macro_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001077a0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpass_cdc_wsa2_macro_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0011c000 size=1
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
// platform_driver_unregister @ 0011c008 size=1
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
// lpass_cdc_is_va_macro_registered @ 0011c010 size=1
// signature: undefined lpass_cdc_is_va_macro_registered(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_is_va_macro_registered(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0011c018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0011c020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0011c028 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011c030 size=1
// signature: undefined of_find_property(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0011c038 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0011c040 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_set_wakeup_capable @ 0011c048 size=1
// signature: undefined msm_cdc_pinctrl_set_wakeup_capable(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011c050 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_register_macro @ 0011c058 size=1
// signature: undefined lpass_cdc_register_macro(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_register_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_cooling_device_register @ 0011c060 size=1
// signature: undefined devm_thermal_of_cooling_device_register(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0011c068 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_cdc_wsa2_macro_spk_boost_event, lpass_cdc_wsa2_macro_vi_feed_mixer_put, lpass_cdc_wsa2_macro_mclk_event, lpass_cdc_wsa2_macro_cps_feed_mixer_put, lpass_cdc_wsa2_macro_set_port_map, lpass_cdc_wsa2_macro_enable_main_path, lpass_cdc_wsa2_macro_enable_prim_interpolator, lpass_cdc_wsa2_macro_set_digital_volume, lpass_cdc_wsa2_macro_pbr_enable_put, lpass_cdc_wsa2_macro_idle_detect_put, lpass_cdc_wsa2_macro_idle_detect_get, lpass_cdc_wsa2_macro_get_rx_mute_status, lpass_cdc_wsa2_macro_mclk_enable, lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_rx_mux_get, lpass_cdc_wsa2_macro_soft_clip_enable_get, lpass_cdc_wsa2_macro_vi_feed_mixer_get, lpass_cdc_wsa2_macro_get_channel_map, lpass_cdc_wsa2_macro_config_softclip, lpass_cdc_wsa2_macro_init, lpass_cdc_wsa2_macro_cooling_adjust_gain, lpass_cdc_wsa2_macro_get_compander, lpass_cdc_wsa2_macro_enable_mix_path, lpass_cdc_wsa2_macro_disable_vi_feedback, lpass_cdc_wsa2_macro_config_compander, lpass_cdc_wsa2_macro_comp_mode_put, lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa2_macro_deinit, lpass_cdc_wsa2_macro_2ch_dma_enable_get, lpass_cdc_wsa2_macro_soft_clip_enable_put, lpass_cdc_wsa2_macro_set_cur_state, lpass_cdc_wsa2_macro_ear_spkrrecv_get, lpass_cdc_wsa2_macro_ear_spkrrecv_put, lpass_cdc_wsa2_macro_probe, lpass_cdc_wsa2_macro_add_child_devices, lpass_cdc_wsa2_macro_enable_echo, lpass_cdc_wsa2_macro_enable_vbat, lpass_cdc_wsa2_macro_pbr_enable_get, lpass_cdc_wsa2_macro_comp_mode_get, lpass_cdc_wsa2_macro_hw_params, lpass_cdc_wsa2_macro_set_ec_hq, lpass_cdc_wsa2_macro_mute_stream, lpass_cdc_wsa2_macro_enable_swr, lpass_cdc_wsa2_macro_cps_feed_mixer_get, lpass_cdc_wsa2_macro_event_handler, lpass_cdc_wsa2_macro_get_ec_hq, lpass_cdc_wsa2_macro_set_compander, lpass_cdc_wsa2_macro_2ch_dma_enable_put, wsa2_swrm_clock, lpass_cdc_wsa2_macro_rx_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0011c070 size=1
// signature: undefined _dev_info(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0011c078 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0011c080 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0011c088 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpass_cdc_wsa2_macro_remove, lpass_cdc_wsa2_macro_event_handler, lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0011c090 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpass_cdc_wsa2_macro_event_handler, lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0011c0a0 size=1
// signature: undefined queue_work_on(void)
// callers: [lpass_cdc_wsa2_macro_set_cur_state, lpass_cdc_wsa2_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011c0a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_cdc_wsa2_macro_set_port_map, lpass_cdc_wsa2_macro_probe, lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 0011c0b0 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [lpass_cdc_wsa2_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 0011c0b8 size=1
// signature: undefined platform_device_unregister(void)
// callers: [lpass_cdc_wsa2_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0011c0c0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpass_cdc_wsa2_macro_remove, lpass_cdc_wsa2_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_unregister_macro @ 0011c0c8 size=1
// signature: undefined lpass_cdc_unregister_macro(void)
// callers: [lpass_cdc_wsa2_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_unregister_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0011c0d0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0011c0d8 size=1
// signature: undefined strnstr(void)
// callers: [lpass_cdc_wsa2_macro_comp_mode_put, lpass_cdc_wsa2_macro_enable_swr, lpass_cdc_wsa2_macro_comp_mode_get, lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0011c0e0 size=1
// signature: size_t strlen(char * __s)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0011c0e8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 0011c0f0 size=1
// signature: undefined platform_device_alloc(void)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add_data @ 0011c0f8 size=1
// signature: undefined platform_device_add_data(void)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 0011c100 size=1
// signature: undefined krealloc(void)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 0011c108 size=1
// signature: undefined platform_device_add(void)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011c110 size=1
// signature: undefined _printk(void)
// callers: [lpass_cdc_wsa2_macro_get_cur_state, lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_core_vote, lpass_cdc_wsa2_macro_cooling_adjust_gain, lpass_cdc_wsa2_macro_set_cur_state, lpass_cdc_wsa2_macro_get_max_state, lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 0011c118 size=1
// signature: undefined platform_device_put(void)
// callers: [lpass_cdc_wsa2_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0011c120 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [lpass_cdc_wsa2_macro_enable_echo, lpass_cdc_wsa2_macro_enable_vbat, lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_spk_boost_event, lpass_cdc_wsa2_macro_init, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_cooling_adjust_gain, lpass_cdc_wsa2_macro_enable_mix_path, lpass_cdc_wsa2_macro_disable_vi_feedback, lpass_cdc_wsa2_macro_config_compander, lpass_cdc_wsa2_macro_hw_params, lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa2_macro_mute_stream, lpass_cdc_wsa2_macro_enable_main_path, lpass_cdc_wsa2_macro_enable_prim_interpolator, lpass_cdc_wsa2_macro_set_digital_volume, lpass_cdc_wsa2_macro_config_softclip, lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 0011c128 size=1
// signature: undefined dev_get_regmap(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011c130 size=1
// signature: undefined mutex_lock(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0011c138 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_core_vote, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0011c140 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_cdc_wsa2_macro_spk_boost_event, lpass_cdc_wsa2_macro_vi_feed_mixer_put, lpass_cdc_wsa2_macro_mclk_event, lpass_cdc_wsa2_macro_cps_feed_mixer_put, lpass_cdc_wsa2_macro_set_port_map, lpass_cdc_wsa2_macro_enable_main_path, lpass_cdc_wsa2_macro_enable_prim_interpolator, lpass_cdc_wsa2_macro_set_digital_volume, lpass_cdc_wsa2_macro_pbr_enable_put, lpass_cdc_wsa2_macro_idle_detect_put, lpass_cdc_wsa2_macro_idle_detect_get, lpass_cdc_wsa2_macro_get_rx_mute_status, lpass_cdc_wsa2_macro_mclk_enable, lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_rx_mux_get, lpass_cdc_wsa2_macro_soft_clip_enable_get, lpass_cdc_wsa2_macro_vi_feed_mixer_get, lpass_cdc_wsa2_macro_get_cur_state, lpass_cdc_wsa2_macro_get_channel_map, lpass_cdc_wsa2_macro_core_vote, lpass_cdc_wsa2_macro_config_softclip, lpass_cdc_wsa2_macro_init, lpass_cdc_wsa2_macro_get_compander, lpass_cdc_wsa2_macro_enable_mix_path, lpass_cdc_wsa2_macro_disable_vi_feedback, lpass_cdc_wsa2_macro_config_compander, lpass_cdc_wsa2_macro_comp_mode_put, lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa2_macro_deinit, lpass_cdc_wsa2_macro_2ch_dma_enable_get, lpass_cdc_wsa2_macro_soft_clip_enable_put, lpass_cdc_wsa2_macro_set_cur_state, lpass_cdc_wsa2_macro_ear_spkrrecv_get, lpass_cdc_wsa2_macro_ear_spkrrecv_put, lpass_cdc_wsa2_macro_enable_echo, lpass_cdc_wsa2_macro_enable_vbat, lpass_cdc_wsa2_macro_pbr_enable_get, lpass_cdc_wsa2_macro_comp_mode_get, lpass_cdc_wsa2_macro_get_max_state, lpass_cdc_wsa2_macro_hw_params, lpass_cdc_wsa2_macro_set_ec_hq, lpass_cdc_wsa2_macro_mute_stream, lpass_cdc_wsa2_macro_enable_swr, lpass_cdc_wsa2_macro_cps_feed_mixer_get, lpass_cdc_wsa2_macro_event_handler, lpass_cdc_wsa2_macro_get_ec_hq, lpass_cdc_wsa2_macro_set_compander, lpass_cdc_wsa2_macro_2ch_dma_enable_put, wsa2_swrm_clock, lpass_cdc_wsa2_macro_rx_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0011c148 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0011c150 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0011c158 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0011c160 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_core_vote, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0011c168 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_core_vote, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011c170 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable, wsa2_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_check_core_votes @ 0011c178 size=1
// signature: undefined lpass_cdc_check_core_votes(void)
// callers: [lpass_cdc_wsa2_macro_core_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_check_core_votes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_fs_gen_request @ 0011c180 size=1
// signature: undefined lpass_cdc_clk_rsc_fs_gen_request(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_fs_gen_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_request_clock @ 0011c188 size=1
// signature: undefined lpass_cdc_clk_rsc_request_clock(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_request_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0011c190 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync_region @ 0011c198 size=1
// signature: undefined regcache_sync_region(void)
// callers: [lpass_cdc_wsa2_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_device_ptr @ 0011c1a0 size=1
// signature: undefined lpass_cdc_get_device_ptr(void)
// callers: [lpass_cdc_wsa2_macro_init, lpass_cdc_wsa2_macro_vi_feed_mixer_put, lpass_cdc_wsa2_macro_get_compander, lpass_cdc_wsa2_macro_disable_vi_feedback, lpass_cdc_wsa2_macro_config_compander, lpass_cdc_wsa2_macro_mclk_event, lpass_cdc_wsa2_macro_comp_mode_put, lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa2_macro_deinit, lpass_cdc_wsa2_macro_cps_feed_mixer_put, lpass_cdc_wsa2_macro_2ch_dma_enable_get, lpass_cdc_wsa2_macro_set_port_map, lpass_cdc_wsa2_macro_enable_main_path, lpass_cdc_wsa2_macro_enable_prim_interpolator, lpass_cdc_wsa2_macro_soft_clip_enable_put, lpass_cdc_wsa2_macro_set_digital_volume, lpass_cdc_wsa2_macro_ear_spkrrecv_get, lpass_cdc_wsa2_macro_ear_spkrrecv_put, lpass_cdc_wsa2_macro_pbr_enable_put, lpass_cdc_wsa2_macro_idle_detect_put, lpass_cdc_wsa2_macro_idle_detect_get, lpass_cdc_wsa2_macro_get_rx_mute_status, lpass_cdc_wsa2_macro_enable_echo, lpass_cdc_wsa2_macro_enable_vbat, lpass_cdc_wsa2_macro_set_rx_mute_status, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_pbr_enable_get, lpass_cdc_wsa2_macro_comp_mode_get, lpass_cdc_wsa2_macro_rx_mux_get, lpass_cdc_wsa2_macro_hw_params, lpass_cdc_wsa2_macro_soft_clip_enable_get, lpass_cdc_wsa2_macro_vi_feed_mixer_get, lpass_cdc_wsa2_macro_set_ec_hq, lpass_cdc_wsa2_macro_mute_stream, lpass_cdc_wsa2_macro_get_channel_map, lpass_cdc_wsa2_macro_enable_swr, lpass_cdc_wsa2_macro_cps_feed_mixer_get, lpass_cdc_wsa2_macro_event_handler, lpass_cdc_wsa2_macro_get_ec_hq, lpass_cdc_wsa2_macro_config_softclip, lpass_cdc_wsa2_macro_set_compander, lpass_cdc_wsa2_macro_2ch_dma_enable_put, lpass_cdc_wsa2_macro_rx_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_device_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 0011c1a8 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [lpass_cdc_wsa2_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 0011c1b0 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [lpass_cdc_wsa2_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_widgets @ 0011c1b8 size=1
// signature: undefined snd_soc_dapm_new_widgets(void)
// callers: [lpass_cdc_wsa2_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_widgets(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 0011c1c0 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [lpass_cdc_wsa2_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0011c1c8 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [lpass_cdc_wsa2_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0011c1d0 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [lpass_cdc_wsa2_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0011c1d8 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [lpass_cdc_wsa2_macro_init, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_enable_mix_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swrm_wcd_notify @ 0011c1e0 size=1
// signature: undefined swrm_wcd_notify(void)
// callers: [lpass_cdc_wsa2_macro_set_port_map, lpass_cdc_wsa2_macro_enable_swr, lpass_cdc_wsa2_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swrm_wcd_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_runtime_suspend @ 0011c1e8 size=1
// signature: undefined lpass_cdc_runtime_suspend(void)
// callers: [lpass_cdc_wsa2_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_rsc_clk_reset @ 0011c1f0 size=1
// signature: undefined lpass_cdc_rsc_clk_reset(void)
// callers: [lpass_cdc_wsa2_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_rsc_clk_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0011c1f8 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [lpass_cdc_wsa2_macro_vbat_bcl_gsm_mode_func_get, lpass_cdc_wsa2_macro_enable_main_path, lpass_cdc_wsa2_macro_enable_echo, lpass_cdc_wsa2_macro_enable_prim_interpolator, lpass_cdc_wsa2_macro_get_channel_map, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_set_digital_volume, lpass_cdc_wsa2_macro_enable_mix_path, lpass_cdc_wsa2_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0011c200 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [lpass_cdc_wsa2_macro_enable_echo, lpass_cdc_wsa2_macro_enable_vbat, lpass_cdc_wsa2_macro_spk_boost_event, lpass_cdc_wsa2_macro_enable_interpolator, lpass_cdc_wsa2_macro_enable_mix_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0011c208 size=1
// signature: undefined usleep_range_state(void)
// callers: [lpass_cdc_wsa2_macro_mute_stream, lpass_cdc_wsa2_macro_enable_main_path, lpass_cdc_wsa2_macro_enable_mix_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_wsa_pa_on @ 0011c210 size=1
// signature: undefined lpass_cdc_wsa_pa_on(void)
// callers: [lpass_cdc_wsa2_macro_mute_stream, lpass_cdc_wsa2_macro_enable_main_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_wsa_pa_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_kcontrol_widget @ 0011c218 size=1
// signature: undefined snd_soc_dapm_kcontrol_widget(void)
// callers: [lpass_cdc_wsa2_macro_cps_feed_mixer_put, lpass_cdc_wsa2_macro_cps_feed_mixer_get, lpass_cdc_wsa2_macro_vi_feed_mixer_put, lpass_cdc_wsa2_macro_rx_mux_get, lpass_cdc_wsa2_macro_vi_feed_mixer_get, lpass_cdc_wsa2_macro_rx_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_kcontrol_widget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mixer_update_power @ 0011c228 size=1
// signature: undefined snd_soc_dapm_mixer_update_power(void)
// callers: [lpass_cdc_wsa2_macro_cps_feed_mixer_put, lpass_cdc_wsa2_macro_vi_feed_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mixer_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mux_update_power @ 0011c230 size=1
// signature: undefined snd_soc_dapm_mux_update_power(void)
// callers: [lpass_cdc_wsa2_macro_rx_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mux_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_update_compander_setting @ 0011c238 size=1
// signature: undefined lpass_cdc_update_compander_setting(void)
// callers: [lpass_cdc_wsa2_macro_config_compander]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_update_compander_setting(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_put_volsw @ 0011c240 size=1
// signature: undefined snd_soc_put_volsw(void)
// callers: [lpass_cdc_wsa2_macro_set_digital_volume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_put_volsw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 0011c248 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [lpass_cdc_wsa2_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0011c250 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0011c258 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0011c260 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0011c268 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



