// Decompiled by Ghidra 12.2
// Program: lpass_cdc_wsa_macro_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_cdc_wsa_macro_probe @ 00100e1c size=1816
// signature: undefined lpass_cdc_wsa_macro_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lpass_cdc_wsa_macro_probe(long param_1)

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
LAB_001012e4:
    _dev_err(lVar1,pcVar9,"lpass_cdc_wsa_macro_probe");
    iVar2 = -0x205;
    goto LAB_00101420;
  }
  plVar5 = (long *)devm_kmalloc(lVar1,0x2a0,0xdc0);
  if (plVar5 == (long *)0x0) {
    iVar2 = -0xc;
    goto LAB_00101420;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  *(undefined1 *)(plVar5 + 0x52) = 1;
  *plVar5 = lVar1;
  iVar2 = of_property_read_variable_u32_array(uVar6,&DAT_0011a49c,(long)&local_110 + 4,1,0);
  if (iVar2 < 0) {
    _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa_macro_probe",&DAT_0011a49c);
    goto LAB_00101420;
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
    _dev_err(lVar1,"%s: error reading %s in dt\n","lpass_cdc_wsa_macro_probe",
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
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-swr-gpios",0,0,0,local_98);
  uVar4 = local_98[0];
  if (iVar2 != 0) {
    uVar4 = 0;
  }
  plVar5[0x20] = uVar4;
  if ((uVar4 == 0) && (local_118 != 0)) {
    pcVar9 = "%s: swr_gpios handle not provided!\n";
LAB_00101304:
    _dev_err(lVar1,pcVar9,"lpass_cdc_wsa_macro_probe");
    iVar2 = -0x16;
    goto LAB_00101420;
  }
  iVar2 = msm_cdc_pinctrl_get_state();
  if ((iVar2 < 0) && (local_118 != 0)) {
    pcVar9 = "%s: failed to get swr pin state\n";
    goto LAB_001012e4;
  }
  msm_cdc_pinctrl_set_wakeup_capable(plVar5[0x20],0);
  lVar7 = devm_ioremap(lVar1,local_110._4_4_,0x1000);
  if (lVar7 == 0) {
    pcVar9 = "%s: ioremap failed\n";
    goto LAB_00101304;
  }
  local_98[0] = local_98[0] & 0xffffffff00000000;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-rloads",local_98);
  if (lVar8 == 0) {
    pcVar9 = "%s: missing %s\n";
LAB_0010145c:
    _dev_info(lVar1,pcVar9,"lpass_cdc_wsa_macro_read_array","qcom,wsa-rloads");
  }
  else {
    if (((uint)local_98[0] & 0xfffffffc) != 8) {
      pcVar9 = "%s: invalid number of %s\n";
      goto LAB_0010145c;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-rloads",(long)plVar5 + 0x27c,2,0);
    if (iVar2 < 0) {
      pcVar9 = "%s: Failed to read %s\n";
      goto LAB_0010145c;
    }
  }
  local_98[0] = local_98[0] & 0xffffffff00000000;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-system-gains",local_98);
  if (lVar8 == 0) {
    pcVar9 = "%s: missing %s\n";
LAB_00101480:
    _dev_info(lVar1,pcVar9,"lpass_cdc_wsa_macro_read_array","qcom,wsa-system-gains");
  }
  else {
    if (((uint)local_98[0] & 0xfffffffc) != 0x10) {
      pcVar9 = "%s: invalid number of %s\n";
      goto LAB_00101480;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-system-gains",(long)plVar5 + 0x264
                       ,4,0);
    if (iVar2 < 0) {
      pcVar9 = "%s: Failed to read %s\n";
      goto LAB_00101480;
    }
  }
  local_98[0] = local_98[0] & 0xffffffff00000000;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-bat-cfgs",local_98);
  if (lVar8 == 0) {
    pcVar9 = "%s: missing %s\n";
LAB_001014a4:
    _dev_info(lVar1,pcVar9,"lpass_cdc_wsa_macro_read_array","qcom,wsa-bat-cfgs");
  }
  else {
    if (((uint)local_98[0] & 0xfffffffc) != 8) {
      pcVar9 = "%s: invalid number of %s\n";
      goto LAB_001014a4;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa-bat-cfgs",(long)plVar5 + 0x274,2,0
                      );
    if (iVar2 < 0) {
      pcVar9 = "%s: Failed to read %s\n";
      goto LAB_001014a4;
    }
  }
  plVar5[0x35] = lVar7;
  *(undefined1 *)((long)plVar5 + 0x29) = 1;
  plVar5[0x1a] = 0xfffffffe0;
  plVar5[0x1b] = (long)(plVar5 + 0x1b);
  plVar5[0x1c] = (long)(plVar5 + 0x1b);
  plVar5[0x1d] = (long)lpass_cdc_wsa_macro_add_child_devices;
  plVar5[0x46] = 0xfffffffe0;
  plVar5[0x47] = (long)(plVar5 + 0x47);
  plVar5[0x48] = (long)(plVar5 + 0x47);
  plVar5[0x49] = (long)lpass_cdc_wsa_macro_cooling_adjust_gain;
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  plVar5[0x13] = (long)plVar5;
  plVar5[0x14] = 0;
  plVar5[0x15] = 0;
  plVar5[0x16] = 0;
  plVar5[0x17] = (long)wsa_swrm_clock;
  plVar5[0x18] = (long)lpass_cdc_wsa_macro_core_vote;
  plVar5[0x19] = 0;
  iVar2 = of_property_read_variable_u32_array(uVar6,"qcom,default-clk-id",&local_110,1,0);
  if (iVar2 < 0) {
    _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa_macro_probe",
             "qcom,mux0-clk-id");
    uVar10 = 2;
    local_110 = CONCAT44(local_110._4_4_,2);
  }
  else {
    uVar10 = (undefined2)local_110;
  }
  *(undefined2 *)(plVar5 + 0x3e) = uVar10;
  *(long **)(param_1 + 0xa8) = plVar5;
  __mutex_init(plVar5 + 6,"&wsa_priv->mclk_lock",&lpass_cdc_wsa_macro_probe___key);
  __mutex_init(plVar5 + 0xc,"&wsa_priv->swr_clk_lock",&lpass_cdc_wsa_macro_probe___key_17);
  uStack_f0 = 0;
  local_108 = lpass_cdc_wsa_macro_init;
  pcStack_100 = lpass_cdc_wsa_macro_deinit;
  local_b8 = 0;
  uStack_b0 = 0;
  local_e8 = &lpass_cdc_wsa_macro_dai;
  uStack_e0 = 0;
  local_f8 = 5;
  local_d8 = lpass_cdc_wsa_macro_event_handler;
  uStack_d0 = 0;
  local_c8 = lpass_cdc_wsa_macro_set_port_map;
  uStack_c0 = 0;
  local_a0 = (ulong)CONCAT22((short)plVar5[0x3e],(short)plVar5[0x3e]);
  local_a8 = lVar7;
  iVar2 = lpass_cdc_register_macro(lVar1,2,&local_108);
  if (iVar2 < 0) {
    _dev_err(lVar1,"%s: register macro failed\n","lpass_cdc_wsa_macro_probe");
    goto LAB_00101420;
  }
  lVar7 = of_find_property(*(undefined8 *)(*plVar5 + 0x2e8),"#cooling-cells",0);
  if (lVar7 != 0) {
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,thermal-max-state",&local_114,1,0);
    if (iVar2 < 0) {
      _dev_info(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa_macro_probe",
                "qcom,thermal-max-state");
      uVar11 = 0xb;
    }
    else {
      uVar11 = local_114;
    }
    *(undefined4 *)((long)plVar5 + 0x22c) = uVar11;
    uVar4 = devm_thermal_of_cooling_device_register
                      (lVar1,*(undefined8 *)(*plVar5 + 0x2e8),&DAT_0011afa8,plVar5,&wsa_cooling_ops)
    ;
    plVar5[0x44] = uVar4;
    if (0xfffffffffffff000 < uVar4) {
      _dev_err(lVar1,"%s: failed to register wsa macro as cooling device\n",
               "lpass_cdc_wsa_macro_probe");
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
    _dev_info(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_wsa_macro_probe",
              "qcom,noise-gate-mode");
LAB_001013d0:
    *(undefined4 *)((long)plVar5 + 0x28c) = 0;
  }
  else {
    if (3 < local_11c) goto LAB_001013d0;
    *(uint *)((long)plVar5 + 0x28c) = local_11c;
  }
  pm_runtime_set_autosuspend_delay(lVar1,0x32);
  __pm_runtime_use_autosuspend(lVar1,1);
  __pm_runtime_set_status(lVar1,2);
  *(ushort *)(param_1 + 0x210) = *(ushort *)(param_1 + 0x210) | 0x100;
  pm_runtime_enable(lVar1);
  queue_work_on(0x20,_system_wq,plVar5 + 0x1a);
LAB_00101420:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_remove @ 00101538 size=168
// signature: undefined lpass_cdc_wsa_macro_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_remove(long param_1)

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
    lpass_cdc_unregister_macro(param_1,2);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_add_child_devices @ 001015e4 size=780
// signature: undefined lpass_cdc_wsa_macro_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa_macro_add_child_devices(long param_1)

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
  char local_b8 [8];
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  plVar3 = (long *)(param_1 + -0xd0);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b0 = 0;
  if (plVar3 == (long *)0x0) {
    _printk(&DAT_0011a6ec,"lpass_cdc_wsa_macro_add_child_devices");
  }
  else {
    lVar6 = *plVar3;
    if ((lVar6 == 0) || (*(long *)(lVar6 + 0x2e8) == 0)) {
      pcVar9 = "%s: DT node for wsa_priv does not exist\n";
LAB_001017e8:
      _dev_err(lVar6,pcVar9,"lpass_cdc_wsa_macro_add_child_devices");
    }
    else {
      *(undefined4 *)(param_1 + 0xf8) = 0;
      puVar7 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar6 + 0x2e8),0);
      if (puVar7 != (undefined8 *)0x0) {
        uVar12 = 0;
        lVar10 = 0;
        do {
          lVar6 = strnstr(*puVar7,"wsa_swr_master",0xe);
          if (lVar6 != 0) {
            local_b0 = CONCAT44(local_b0._4_4_,0x6c727463);
            local_b8[0] = s_wsa_swr_ctrl_0011a385[0];
            local_b8[1] = s_wsa_swr_ctrl_0011a385[1];
            local_b8[2] = s_wsa_swr_ctrl_0011a385[2];
            local_b8[3] = s_wsa_swr_ctrl_0011a385[3];
            local_b8[4] = s_wsa_swr_ctrl_0011a385[4];
            local_b8[5] = s_wsa_swr_ctrl_0011a385[5];
            local_b8[6] = s_wsa_swr_ctrl_0011a385[6];
            local_b8[7] = s_wsa_swr_ctrl_0011a385[7];
            pcVar9 = (char *)((long)&local_b0 + 4);
LAB_00101728:
            *pcVar9 = '\0';
            lVar8 = platform_device_alloc(local_b8,0xffffffff);
            lVar6 = *plVar3;
            if (lVar8 == 0) {
              pcVar9 = "%s: pdev memory alloc failed\n";
              goto LAB_001017e8;
            }
            *(long *)(lVar8 + 0x70) = lVar6;
            *(undefined8 **)(lVar8 + 0x2f8) = puVar7;
            lVar6 = strnstr(*puVar7,"wsa_swr_master",0xe);
            if (lVar6 == 0) {
LAB_001017b4:
              iVar5 = platform_device_add(lVar8);
              if (iVar5 == 0) {
                uVar2 = *(uint *)(param_1 + 0xf8);
                if ((int)uVar2 < 3) {
                  *(uint *)(param_1 + 0xf8) = uVar2 + 1;
                  if (2 < uVar2) goto LAB_001017dc;
                  *(long *)(param_1 + 0xe0 + (ulong)uVar2 * 8) = lVar8;
                  goto LAB_00101690;
                }
                break;
              }
              _dev_err(lVar8 + 0x10,"%s: Cannot add platform device\n",
                       "lpass_cdc_wsa_macro_add_child_devices");
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
                    pcVar4 = (code *)SoftwareBreakpoint(1,0x1018ec);
                    (*pcVar4)();
                  }
                  uVar12 = uVar12 + 1;
                  *(long *)(lVar10 + uVar11 * 8) = lVar8;
                  *(long *)(param_1 + -0x40) = lVar10;
                  goto LAB_001017b4;
                }
                _dev_err(lVar8 + 0x10,"out of memory\n");
              }
              else {
                _dev_err(lVar8 + 0x10,"%s: cannot add plat data ctrl:%d\n",
                         "lpass_cdc_wsa_macro_add_child_devices",uVar12);
              }
            }
            if ((((0 < *(int *)(param_1 + 0xf8)) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0xe0)), 1 < *(int *)(param_1 + 0xf8)
                 )) && (platform_device_put(*(undefined8 *)(param_1 + 0xe8)),
                       2 < *(int *)(param_1 + 0xf8))) &&
               (platform_device_put(*(undefined8 *)(param_1 + 0xf0)), 3 < *(int *)(param_1 + 0xf8)))
            {
LAB_001017dc:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1017e0);
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
            goto LAB_00101728;
          }
LAB_00101690:
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
// lpass_cdc_wsa_macro_cooling_adjust_gain @ 001018f4 size=188
// signature: undefined lpass_cdc_wsa_macro_cooling_adjust_gain(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa_macro_cooling_adjust_gain(long param_1)

{
  long lVar1;
  
  if ((long *)(param_1 + -0x230) == (long *)0x0) {
    _printk(&DAT_0011b1e0,"lpass_cdc_wsa_macro_cooling_adjust_gain");
  }
  else {
    lVar1 = *(long *)(param_1 + -0x230);
    if ((lVar1 == 0) || (*(long *)(lVar1 + 0x2e8) == 0)) {
      _dev_err(lVar1,"%s: DT node for wsa_priv does not exist\n",
               "lpass_cdc_wsa_macro_cooling_adjust_gain");
    }
    else if (*(char *)(param_1 + -0x208) != '\0') {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + -0x128),0x2414,0xff,
                 *(char *)(param_1 + -0x14) - *(char *)(param_1 + -8));
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + -0x128),0x2494,0xff,
                 *(char *)(param_1 + -0x13) - *(char *)(param_1 + -8));
    }
  }
  return;
}



//------------------------------------------------------------
// wsa_swrm_clock @ 001019b4 size=728
// signature: undefined wsa_swrm_clock(void)
// callers: []
//------------------------------------------------------------

int wsa_swrm_clock(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  short sVar6;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(wsa_swrm_clock__rs,"wsa_swrm_clock");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","wsa_swrm_clock");
    return -0x16;
  }
  mutex_lock(param_1 + 0xc);
  if ((param_2 & 1) == 0) {
    if (*(short *)((long)param_1 + 0x26) == 0) {
      iVar1 = ___ratelimit(wsa_swrm_clock__rs_44,"wsa_swrm_clock");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","wsa_swrm_clock");
      }
      iVar1 = 0;
      *(undefined2 *)((long)param_1 + 0x26) = 0;
    }
    else {
      sVar6 = *(short *)((long)param_1 + 0x26) + -1;
      *(short *)((long)param_1 + 0x26) = sVar6;
      if (sVar6 == 0) {
        regmap_update_bits_base(lVar3,0x2008,1,0,0,0,0);
        lpass_cdc_wsa_macro_mclk_enable(param_1,0);
        iVar1 = msm_cdc_pinctrl_select_sleep_state(param_1[0x20]);
        if ((iVar1 < 0) &&
           (iVar2 = ___ratelimit(wsa_swrm_clock__rs_46,"wsa_swrm_clock"), iVar2 != 0)) {
          _dev_err(*param_1,"%s: wsa swr pinctrl disable failed\n","wsa_swrm_clock");
        }
      }
      else {
        iVar1 = 0;
      }
    }
    goto LAB_00101c14;
  }
  __pm_runtime_resume(*param_1,4);
  sVar6 = *(short *)((long)param_1 + 0x26);
  if (sVar6 == 0) {
    iVar1 = msm_cdc_pinctrl_select_active_state(param_1[0x20]);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(wsa_swrm_clock__rs_40,"wsa_swrm_clock");
      if (iVar2 != 0) {
        lVar3 = *param_1;
        pcVar5 = "%s: wsa swr pinctrl enable failed\n";
LAB_00101c7c:
        _dev_err(lVar3,pcVar5,"wsa_swrm_clock");
      }
    }
    else {
      iVar1 = lpass_cdc_wsa_macro_mclk_enable(param_1,1);
      if (-1 < iVar1) {
        if (*(char *)((long)param_1 + 0x29) != '\0') {
          regmap_update_bits_base(lVar3,0x2008,2,2,0,0,0);
        }
        regmap_update_bits_base(lVar3,0x2008,1,1,0,0,0);
        if (*(char *)((long)param_1 + 0x29) != '\0') {
          regmap_update_bits_base(lVar3,0x2008,2,0,0,0,0);
        }
        regmap_update_bits_base(lVar3,0x2008,0x1c,0xc,0,0,0);
        sVar6 = *(short *)((long)param_1 + 0x26);
        *(undefined1 *)((long)param_1 + 0x29) = 0;
        goto LAB_00101a10;
      }
      msm_cdc_pinctrl_select_sleep_state(param_1[0x20]);
      iVar2 = ___ratelimit(wsa_swrm_clock__rs_42,"wsa_swrm_clock");
      if (iVar2 != 0) {
        lVar3 = *param_1;
        pcVar5 = "%s: wsa request clock enable failed\n";
        goto LAB_00101c7c;
      }
    }
    lVar3 = *param_1;
  }
  else {
    iVar1 = 0;
LAB_00101a10:
    lVar3 = *param_1;
    *(short *)((long)param_1 + 0x26) = sVar6 + 1;
  }
  uVar4 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar3 + 0x220) = uVar4;
  __pm_runtime_suspend(*param_1,0xd);
LAB_00101c14:
  mutex_unlock(param_1 + 0xc);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_core_vote @ 00101c90 size=180
// signature: undefined lpass_cdc_wsa_macro_core_vote(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_wsa_macro_core_vote(long *param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long lVar5;
  
  if (param_1 == (long *)0x0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_core_vote__rs,"lpass_cdc_wsa_macro_core_vote");
    if (iVar1 != 0) {
      _printk(&DAT_0011afac,"lpass_cdc_wsa_macro_core_vote");
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
// lpass_cdc_wsa_macro_mclk_enable @ 00101d44 size=660
// signature: undefined lpass_cdc_wsa_macro_mclk_enable(void)
// callers: [lpass_cdc_wsa_macro_mclk_event, wsa_swrm_clock]
//------------------------------------------------------------

int lpass_cdc_wsa_macro_mclk_enable(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  short sVar4;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_mclk_enable__rs,"lpass_cdc_wsa_macro_mclk_enable");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","lpass_cdc_wsa_macro_mclk_enable");
    return -0x16;
  }
  mutex_lock(param_1 + 6);
  sVar4 = *(short *)((long)param_1 + 0x24);
  if ((param_2 & 1) == 0) {
    if (sVar4 == 0) {
      iVar1 = ___ratelimit(lpass_cdc_wsa_macro_mclk_enable__rs_49,"lpass_cdc_wsa_macro_mclk_enable")
      ;
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","lpass_cdc_wsa_macro_mclk_enable");
      }
      iVar1 = 0;
      *(undefined2 *)((long)param_1 + 0x24) = 0;
    }
    else {
      *(short *)((long)param_1 + 0x24) = sVar4 + -1;
      if ((short)(sVar4 + -1) == 0) {
        regmap_update_bits_base(lVar3,0x2004,1,0,0,0,0);
        regmap_update_bits_base(lVar3,0x2000,1,0,0,0,0);
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
        iVar2 = ___ratelimit(lpass_cdc_wsa_macro_mclk_enable__rs_48,
                             "lpass_cdc_wsa_macro_mclk_enable");
        if (iVar2 != 0) {
          _dev_err(*param_1,"%s: wsa request clock enable failed\n",
                   "lpass_cdc_wsa_macro_mclk_enable");
        }
        goto LAB_00101f60;
      }
      lpass_cdc_clk_rsc_fs_gen_request(*param_1,1);
      regcache_mark_dirty(lVar3);
      regcache_sync_region(lVar3,0x2000,0x2be4);
      regmap_update_bits_base(lVar3,0x2088,1,1,0,0,0);
      regmap_update_bits_base(lVar3,0x2000,1,1,0,0,0);
      regmap_update_bits_base(lVar3,0x2004,2,2,0,0,0);
      regmap_update_bits_base(lVar3,0x2004,2,0,0,0,0);
      regmap_update_bits_base(lVar3,0x2004,1,1,0,0,0);
      sVar4 = *(short *)((long)param_1 + 0x24);
    }
    else {
      iVar1 = 0;
    }
    *(short *)((long)param_1 + 0x24) = sVar4 + 1;
  }
LAB_00101f60:
  mutex_unlock(param_1 + 6);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_init @ 00101fdc size=3020
// signature: undefined lpass_cdc_wsa_macro_init(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_wsa_macro_init(long param_1)

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
  code *pcVar19;
  int iVar20;
  uint uVar21;
  long lVar22;
  undefined8 uVar23;
  char *pcVar24;
  ulong uVar25;
  long lVar26;
  ulong uVar27;
  
  lVar22 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar22 == 0) {
    uVar23 = *(undefined8 *)(param_1 + 0x18);
    pcVar24 = "%s: null device for macro!\n";
  }
  else {
    lVar26 = *(long *)(lVar22 + 0x98);
    if (lVar26 != 0) {
      lVar1 = param_1 + 0xd0;
      iVar20 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_wsa_macro_dapm_widgets,0x28);
      if (iVar20 < 0) {
        pcVar24 = "%s: Failed to add controls\n";
      }
      else {
        uVar21 = lpass_cdc_get_version(lVar22);
        if (uVar21 < 7) {
          iVar20 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_wsa_macro_dapm_widgets_v2p5,8);
          if (iVar20 < 0) {
            pcVar24 = "%s: Failed to add lpass v2p5 controls\n";
            goto LAB_00102b4c;
          }
        }
        else {
          iVar20 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_wsa_macro_dapm_widgets_v2p6,8);
          if (iVar20 < 0) {
            pcVar24 = "%s: Failed to add lpass v2p6 controls\n";
            goto LAB_00102b4c;
          }
        }
        iVar20 = snd_soc_dapm_add_routes(lVar1,&wsa_audio_map,0x77);
        if (iVar20 < 0) {
          pcVar24 = "%s: Failed to add routes\n";
        }
        else {
          iVar20 = snd_soc_dapm_new_widgets(*(undefined8 *)(param_1 + 0xe8));
          if (iVar20 < 0) {
            pcVar24 = "%s: Failed to add widgets\n";
          }
          else {
            iVar20 = snd_soc_add_component_controls(param_1,lpass_cdc_wsa_macro_snd_controls,0x12);
            if (-1 < iVar20) {
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_AIF1 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_AIF_MIX1 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_AIF_VI Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_AIF_ECHO Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_AIF_CPS Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_SPK1 OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_SPK2 OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"VIINPUT_WSA");
              snd_soc_dapm_ignore_suspend(lVar1,"CPSINPUT_WSA");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA SRC0_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_TX DEC0_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"WSA_TX DEC1_INP");
              snd_soc_dapm_sync(lVar1);
              lVar22 = 0;
              *(long *)(lVar26 + 0x108) = param_1;
              *(undefined4 *)(lVar26 + 0x1d0) = 1;
              do {
                snd_soc_component_update_bits
                          (param_1,*(undefined2 *)((long)&lpass_cdc_wsa_macro_reg_init + lVar22),
                           (&DAT_0011086a)[lVar22],(&DAT_0011086b)[lVar22]);
                lVar22 = lVar22 + 4;
              } while (lVar22 != 0x98);
              lVar22 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
              if (lVar22 == 0) {
                iVar20 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,
                                      "lpass_cdc_wsa_macro_get_data");
                if (iVar20 == 0) {
                  return 0;
                }
                pcVar24 = "%s: null device for macro!\n";
              }
              else {
                lVar22 = *(long *)(lVar22 + 0x98);
                if ((lVar22 != 0) && (*(long *)(lVar22 + 0x108) != 0)) {
                  uVar17 = *(uint *)(lVar22 + 0x27c);
                  uVar18 = *(uint *)(lVar22 + 0x264);
                  uVar21 = *(uint *)(lVar22 + 0x274);
                  uVar27 = (ulong)uVar21;
                  if (uVar17 < 4) {
                    snd_soc_component_update_bits
                              (param_1,0x2b4c,0xe0,
                               *(undefined4 *)(&DAT_0011b28c + (long)(int)uVar17 * 4));
                  }
                  snd_soc_component_update_bits(param_1,0x2b50,0xf,uVar18);
                  snd_soc_component_update_bits(param_1,0x2bc4,0xc0,uVar21 * 0x40 + -0x40);
                  if (((0x12 < uVar18) || (6 < uVar21)) || (3 < uVar17)) {
LAB_00102ba4:
                    /* WARNING: Does not return */
                    pcVar19 = (code *)SoftwareBreakpoint(0x5512,0x102ba8);
                    (*pcVar19)();
                  }
                  if (((long)(int)uVar18 * 0x70 + uVar27 * 0x10 + (ulong)uVar17 * 4 < 0x84d) &&
                     (uVar25 = (ulong)uVar17,
                     (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4 < 0x84d)) {
                    uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                    iVar20 = 0xff;
                    if (*(int *)(pbr_vth1_data + uVar2) != 0) {
                      iVar20 = *(int *)(pbr_vth1_data + uVar2);
                    }
                    if (uVar2 < 0x84d) {
                      uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                      iVar3 = 0xff;
                      if (*(int *)(pbr_vth2_data + uVar2) != 0) {
                        iVar3 = *(int *)(pbr_vth2_data + uVar2);
                      }
                      if (uVar2 < 0x84d) {
                        uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                        iVar4 = 0xff;
                        if (*(int *)(pbr_vth3_data + uVar2) != 0) {
                          iVar4 = *(int *)(pbr_vth3_data + uVar2);
                        }
                        if (uVar2 < 0x84d) {
                          uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                          iVar5 = 0xff;
                          if (*(int *)(pbr_vth4_data + uVar2) != 0) {
                            iVar5 = *(int *)(pbr_vth4_data + uVar2);
                          }
                          if (uVar2 < 0x84d) {
                            uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                            iVar6 = 0xff;
                            if (*(int *)(pbr_vth5_data + uVar2) != 0) {
                              iVar6 = *(int *)(pbr_vth5_data + uVar2);
                            }
                            if (uVar2 < 0x84d) {
                              uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                              iVar7 = 0xff;
                              if (*(int *)(pbr_vth6_data + uVar2) != 0) {
                                iVar7 = *(int *)(pbr_vth6_data + uVar2);
                              }
                              if (uVar2 < 0x84d) {
                                uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                iVar8 = 0xff;
                                if (*(int *)(pbr_vth7_data + uVar2) != 0) {
                                  iVar8 = *(int *)(pbr_vth7_data + uVar2);
                                }
                                if (uVar2 < 0x84d) {
                                  uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                  iVar9 = 0xff;
                                  if (*(int *)(pbr_vth8_data + uVar2) != 0) {
                                    iVar9 = *(int *)(pbr_vth8_data + uVar2);
                                  }
                                  if (uVar2 < 0x84d) {
                                    uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                    iVar10 = 0xff;
                                    if (*(int *)(pbr_vth9_data + uVar2) != 0) {
                                      iVar10 = *(int *)(pbr_vth9_data + uVar2);
                                    }
                                    if (uVar2 < 0x84d) {
                                      uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 + uVar25 * 4;
                                      iVar11 = 0xff;
                                      if (*(int *)(pbr_vth10_data + uVar2) != 0) {
                                        iVar11 = *(int *)(pbr_vth10_data + uVar2);
                                      }
                                      if (uVar2 < 0x84d) {
                                        uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                uVar25 * 4;
                                        iVar12 = 0xff;
                                        if (*(int *)(pbr_vth11_data + uVar2) != 0) {
                                          iVar12 = *(int *)(pbr_vth11_data + uVar2);
                                        }
                                        if (uVar2 < 0x84d) {
                                          uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                  uVar25 * 4;
                                          iVar13 = 0xff;
                                          if (*(int *)(pbr_vth12_data + uVar2) != 0) {
                                            iVar13 = *(int *)(pbr_vth12_data + uVar2);
                                          }
                                          if (uVar2 < 0x84d) {
                                            uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                    uVar25 * 4;
                                            iVar14 = 0xff;
                                            if (*(int *)(pbr_vth13_data + uVar2) != 0) {
                                              iVar14 = *(int *)(pbr_vth13_data + uVar2);
                                            }
                                            if ((uVar2 < 0x84d) &&
                                               ((long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                uVar25 * 4 < 0x84d)) {
                                              iVar15 = 0xff;
                                              if (*(int *)(pbr_vth14_data +
                                                          uVar25 * 4 +
                                                          uVar27 * 0x10 + (long)(int)uVar18 * 0x70)
                                                  != 0) {
                                                iVar15 = *(int *)(pbr_vth14_data +
                                                                 uVar25 * 4 +
                                                                 uVar27 * 0x10 +
                                                                 (long)(int)uVar18 * 0x70);
                                              }
                                              iVar16 = 0xff;
                                              if (*(int *)(pbr_vth15_data + uVar2) != 0) {
                                                iVar16 = *(int *)(pbr_vth15_data + uVar2);
                                              }
                                              snd_soc_component_write(param_1,0x2b08,iVar20);
                                              snd_soc_component_write(param_1,0x2b0c,iVar3);
                                              snd_soc_component_write(param_1,0x2b10,iVar4);
                                              snd_soc_component_write(param_1,0x2b14,iVar5);
                                              snd_soc_component_write(param_1,0x2b18,iVar6);
                                              snd_soc_component_write(param_1,0x2b1c,iVar7);
                                              snd_soc_component_write(param_1,0x2b20,iVar8);
                                              snd_soc_component_write(param_1,0x2b24,iVar9);
                                              snd_soc_component_write(param_1,0x2b28,iVar10);
                                              snd_soc_component_write(param_1,0x2b2c,iVar11);
                                              snd_soc_component_write(param_1,0x2b30,iVar12);
                                              snd_soc_component_write(param_1,0x2b34,iVar13);
                                              snd_soc_component_write(param_1,0x2b38,iVar14);
                                              snd_soc_component_write(param_1,0x2b3c,iVar15);
                                              snd_soc_component_write(param_1,0x2b40,iVar16);
                                              uVar17 = *(uint *)(lVar22 + 0x280);
                                              uVar18 = *(uint *)(lVar22 + 0x26c);
                                              uVar21 = *(uint *)(lVar22 + 0x278);
                                              uVar27 = (ulong)uVar21;
                                              if (uVar17 < 4) {
                                                snd_soc_component_update_bits
                                                          (param_1,0x2bb4,0xe0,
                                                           *(undefined4 *)
                                                            (&DAT_0011b28c + (long)(int)uVar17 * 4))
                                                ;
                                              }
                                              snd_soc_component_update_bits
                                                        (param_1,0x2bb8,0xf,uVar18);
                                              snd_soc_component_update_bits
                                                        (param_1,0x2bc4,0x30,uVar21 * 0x10 + -0x10);
                                              if (((0x12 < uVar18) || (6 < uVar21)) || (3 < uVar17))
                                              goto LAB_00102ba4;
                                              if (((long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                   (ulong)uVar17 * 4 < 0x84d) &&
                                                 (uVar25 = (ulong)uVar17,
                                                 (long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                 uVar25 * 4 < 0x84d)) {
                                                uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                        uVar25 * 4;
                                                iVar20 = 0xff;
                                                if (*(int *)(pbr_vth1_data + uVar2) != 0) {
                                                  iVar20 = *(int *)(pbr_vth1_data + uVar2);
                                                }
                                                if (uVar2 < 0x84d) {
                                                  uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                          uVar25 * 4;
                                                  iVar3 = 0xff;
                                                  if (*(int *)(pbr_vth2_data + uVar2) != 0) {
                                                    iVar3 = *(int *)(pbr_vth2_data + uVar2);
                                                  }
                                                  if (uVar2 < 0x84d) {
                                                    uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10
                                                            + uVar25 * 4;
                                                    iVar4 = 0xff;
                                                    if (*(int *)(pbr_vth3_data + uVar2) != 0) {
                                                      iVar4 = *(int *)(pbr_vth3_data + uVar2);
                                                    }
                                                    if (uVar2 < 0x84d) {
                                                      uVar2 = (long)(int)uVar18 * 0x70 +
                                                              uVar27 * 0x10 + uVar25 * 4;
                                                      iVar5 = 0xff;
                                                      if (*(int *)(pbr_vth4_data + uVar2) != 0) {
                                                        iVar5 = *(int *)(pbr_vth4_data + uVar2);
                                                      }
                                                      if (uVar2 < 0x84d) {
                                                        uVar2 = (long)(int)uVar18 * 0x70 +
                                                                uVar27 * 0x10 + uVar25 * 4;
                                                        iVar6 = 0xff;
                                                        if (*(int *)(pbr_vth5_data + uVar2) != 0) {
                                                          iVar6 = *(int *)(pbr_vth5_data + uVar2);
                                                        }
                                                        if (uVar2 < 0x84d) {
                                                          uVar2 = (long)(int)uVar18 * 0x70 +
                                                                  uVar27 * 0x10 + uVar25 * 4;
                                                          iVar7 = 0xff;
                                                          if (*(int *)(pbr_vth6_data + uVar2) != 0)
                                                          {
                                                            iVar7 = *(int *)(pbr_vth6_data + uVar2);
                                                          }
                                                          if (uVar2 < 0x84d) {
                                                            uVar2 = (long)(int)uVar18 * 0x70 +
                                                                    uVar27 * 0x10 + uVar25 * 4;
                                                            iVar8 = 0xff;
                                                            if (*(int *)(pbr_vth7_data + uVar2) != 0
                                                               ) {
                                                              iVar8 = *(int *)(pbr_vth7_data + uVar2
                                                                              );
                                                            }
                                                            if (uVar2 < 0x84d) {
                                                              uVar2 = (long)(int)uVar18 * 0x70 +
                                                                      uVar27 * 0x10 + uVar25 * 4;
                                                              iVar9 = 0xff;
                                                              if (*(int *)(pbr_vth8_data + uVar2) !=
                                                                  0) {
                                                                iVar9 = *(int *)(pbr_vth8_data +
                                                                                uVar2);
                                                              }
                                                              if (uVar2 < 0x84d) {
                                                                uVar2 = (long)(int)uVar18 * 0x70 +
                                                                        uVar27 * 0x10 + uVar25 * 4;
                                                                iVar10 = 0xff;
                                                                if (*(int *)(pbr_vth9_data + uVar2)
                                                                    != 0) {
                                                                  iVar10 = *(int *)(pbr_vth9_data +
                                                                                   uVar2);
                                                                }
                                                                if (uVar2 < 0x84d) {
                                                                  uVar2 = (long)(int)uVar18 * 0x70 +
                                                                          uVar27 * 0x10 + uVar25 * 4
                                                                  ;
                                                                  iVar11 = 0xff;
                                                                  if (*(int *)(pbr_vth10_data +
                                                                              uVar2) != 0) {
                                                                    iVar11 = *(int *)(pbr_vth10_data
                                                                                     + uVar2);
                                                                  }
                                                                  if (uVar2 < 0x84d) {
                                                                    uVar2 = (long)(int)uVar18 * 0x70
                                                                            + uVar27 * 0x10 +
                                                                            uVar25 * 4;
                                                                    iVar12 = 0xff;
                                                                    if (*(int *)(pbr_vth11_data +
                                                                                uVar2) != 0) {
                                                                      iVar12 = *(int *)(
                                                  pbr_vth11_data + uVar2);
                                                  }
                                                  if (uVar2 < 0x84d) {
                                                    uVar2 = (long)(int)uVar18 * 0x70 + uVar27 * 0x10
                                                            + uVar25 * 4;
                                                    iVar13 = 0xff;
                                                    if (*(int *)(pbr_vth12_data + uVar2) != 0) {
                                                      iVar13 = *(int *)(pbr_vth12_data + uVar2);
                                                    }
                                                    if (uVar2 < 0x84d) {
                                                      uVar2 = (long)(int)uVar18 * 0x70 +
                                                              uVar27 * 0x10 + uVar25 * 4;
                                                      iVar14 = 0xff;
                                                      if (*(int *)(pbr_vth13_data + uVar2) != 0) {
                                                        iVar14 = *(int *)(pbr_vth13_data + uVar2);
                                                      }
                                                      if ((uVar2 < 0x84d) &&
                                                         ((long)(int)uVar18 * 0x70 + uVar27 * 0x10 +
                                                          uVar25 * 4 < 0x84d)) {
                                                        iVar15 = 0xff;
                                                        if (*(int *)(pbr_vth14_data +
                                                                    uVar25 * 4 +
                                                                    uVar27 * 0x10 +
                                                                    (long)(int)uVar18 * 0x70) != 0)
                                                        {
                                                          iVar15 = *(int *)(pbr_vth14_data +
                                                                           uVar25 * 4 +
                                                                           uVar27 * 0x10 +
                                                                           (long)(int)uVar18 * 0x70)
                                                          ;
                                                        }
                                                        iVar16 = 0xff;
                                                        if (*(int *)(pbr_vth15_data + uVar2) != 0) {
                                                          iVar16 = *(int *)(pbr_vth15_data + uVar2);
                                                        }
                                                        snd_soc_component_write
                                                                  (param_1,0x2b74,iVar20);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b78,iVar3);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b7c,iVar4);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b80,iVar5);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b84,iVar6);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b88,iVar7);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b8c,iVar8);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b90,iVar9);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b94,iVar10);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b98,iVar11);
                                                        snd_soc_component_write
                                                                  (param_1,0x2b9c,iVar12);
                                                        snd_soc_component_write
                                                                  (param_1,0x2ba0,iVar13);
                                                        snd_soc_component_write
                                                                  (param_1,0x2ba4,iVar14);
                                                        snd_soc_component_write
                                                                  (param_1,0x2ba8,iVar15);
                                                        snd_soc_component_write
                                                                  (param_1,0x2bac,iVar16);
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
                  pcVar19 = (code *)SoftwareBreakpoint(1,0x102ba4);
                  (*pcVar19)();
                }
                iVar20 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,
                                      "lpass_cdc_wsa_macro_get_data");
                if (iVar20 == 0) {
                  return 0;
                }
                pcVar24 = "%s: priv is null for macro!\n";
              }
              _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar24,"lpass_cdc_wsa_macro_init_pbr");
              return 0;
            }
            pcVar24 = "%s: Failed to add snd_ctls\n";
          }
        }
      }
LAB_00102b4c:
      _dev_err(lVar22,pcVar24,"lpass_cdc_wsa_macro_init");
      return iVar20;
    }
    uVar23 = *(undefined8 *)(param_1 + 0x18);
    pcVar24 = "%s: priv is null for macro!\n";
  }
  _dev_err(uVar23,pcVar24,"lpass_cdc_wsa_macro_init");
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_deinit @ 00102bac size=172
// signature: undefined lpass_cdc_wsa_macro_deinit(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_deinit(long param_1)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,"lpass_cdc_wsa_macro_deinit");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_event_handler @ 00102c5c size=380
// signature: undefined lpass_cdc_wsa_macro_event_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_event_handler(long param_1,short param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar4 = *(long *)(lVar2 + 0x98);
    if ((lVar4 != 0) && (*(long *)(lVar4 + 0x108) != 0)) {
      if (param_2 == 7) {
        lpass_cdc_rsc_clk_reset(lVar2,2);
        lpass_cdc_rsc_clk_reset(lVar2,6);
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,"lpass_cdc_wsa_macro_event_handler");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_set_port_map @ 00102ddc size=268
// signature: undefined lpass_cdc_wsa_macro_set_port_map(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa_macro_set_port_map
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
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: null device for macro!\n";
LAB_00102ed0:
      _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar4,"lpass_cdc_wsa_macro_set_port_map");
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
      goto LAB_00102e94;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: priv is null for macro!\n";
      goto LAB_00102ed0;
    }
  }
  uVar3 = 0xffffffea;
LAB_00102e94:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_disable_vi_feedback @ 00102eec size=448
// signature: undefined lpass_cdc_wsa_macro_disable_vi_feedback(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_disable_vi_feedback(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + -0xb8),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
          snd_soc_component_update_bits(lVar4,0x2244,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x2264,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x2244,0x10,0);
          snd_soc_component_update_bits(lVar4,0x2264,0x10,0);
          snd_soc_component_update_bits(lVar4,0x2244,0x20,0);
          snd_soc_component_update_bits(lVar4,0x2264,0x20,0);
        }
        if (((uint)*(undefined8 *)(lVar2 + 0x130) >> 1 & 1) != 0) {
          snd_soc_component_update_bits(lVar4,0x2284,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x22a4,0x20,0x20);
          snd_soc_component_update_bits(lVar4,0x2284,0x10,0);
          snd_soc_component_update_bits(lVar4,0x22a4,0x10,0);
          snd_soc_component_update_bits(lVar4,0x2284,0x20,0);
          snd_soc_component_update_bits(lVar4,0x22a4,0x20,0);
        }
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + -0xb8),pcVar3,"lpass_cdc_wsa_macro_disable_vi_feedback");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_enable_echo @ 001030b0 size=404
// signature: undefined lpass_cdc_wsa_macro_enable_echo(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_enable_echo(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),2);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: null device for macro!\n";
  }
  else {
    lVar7 = *(long *)(lVar3 + 0x98);
    if ((lVar7 != 0) && (*(long *)(lVar7 + 0x108) != 0)) {
      lVar6 = lVar6 + -0xd0;
      uVar4 = snd_soc_component_read(lVar6,0x2110);
      iVar2 = strcmp(*(char **)(param_1 + 8),"WSA RX_MIX EC0_MUX");
      uVar1 = (uint)uVar4;
      if (iVar2 != 0) {
        uVar1 = (uint)((uVar4 & 0xffffffff) >> 3);
      }
      uVar1 = (uVar1 & 7) - 1;
      if (uVar1 < 2) {
        if (*(int *)(lVar7 + (ulong)(uVar1 & 0xffff) * 4 + 0x18) != 0) {
          iVar2 = 1 << (ulong)(uVar1 & 0x1f);
          snd_soc_component_update_bits(lVar6,0x2110,iVar2,iVar2);
          iVar2 = (uVar1 & 0xffff) * 0x40;
          snd_soc_component_update_bits(lVar6,iVar2 + 0x2680U & 0xffc0,1,1);
          snd_soc_component_update_bits(lVar6,iVar2 + 0x2684U & 0xfffc,0x1e,8);
        }
        return 0;
      }
      iVar2 = ___ratelimit(lpass_cdc_wsa_macro_enable_echo__rs,"lpass_cdc_wsa_macro_enable_echo");
      if (iVar2 == 0) {
        return 0xffffffea;
      }
      pcVar5 = "%s: EC mix control not set correctly\n";
      goto LAB_0010323c;
    }
    iVar2 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: priv is null for macro!\n";
  }
  lVar3 = *(long *)(lVar6 + -0xb8);
LAB_0010323c:
  _dev_err(lVar3,pcVar5,"lpass_cdc_wsa_macro_enable_echo");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_enable_main_path @ 00103248 size=612
// signature: undefined lpass_cdc_wsa_macro_enable_main_path(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_enable_main_path(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  
  lVar13 = *(long *)(param_1 + 0x28);
  lVar7 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar13 + -0xb8),2);
  if (lVar7 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: null device for macro!\n";
LAB_00103478:
    _dev_err(*(undefined8 *)(lVar13 + -0xb8),pcVar9,"lpass_cdc_wsa_macro_enable_main_path");
    return 0xffffffea;
  }
  if ((*(long *)(lVar7 + 0x98) == 0) || (*(long *)(*(long *)(lVar7 + 0x98) + 0x108) == 0)) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: priv is null for macro!\n";
    goto LAB_00103478;
  }
  if (param_3 != 1) {
    return 0;
  }
  lVar12 = lVar13 + -0xd0;
  iVar5 = (uint)*(byte *)(param_1 + 0x4c) * 0x80 + 0x2400;
  snd_soc_component_update_bits(lVar12,iVar5,0x40,0x40);
  usleep_range_state(500,0x1fe,2);
  snd_soc_component_update_bits(lVar12,iVar5,0x40,0);
  snd_soc_component_update_bits(lVar12,iVar5,0x20,0x20);
  bVar1 = *(byte *)(param_1 + 0x4c);
  lVar8 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar13 + -0xb8),2);
  if (lVar8 == 0) {
    iVar6 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar6 == 0) goto LAB_00103430;
    pcVar9 = "%s: null device for macro!\n";
  }
  else {
    if ((*(long *)(lVar8 + 0x98) != 0) && (*(long *)(*(long *)(lVar8 + 0x98) + 0x108) != 0)) {
      iVar6 = (uint)bVar1 * 8;
      uVar2 = snd_soc_component_read(lVar12,iVar6 + 0x2100);
      uVar3 = snd_soc_component_read(lVar12,iVar6 + 0x2104);
      uVar4 = lpass_cdc_get_version(lVar8);
      uVar10 = 7;
      if (6 < uVar4) {
        uVar10 = 10;
      }
      uVar11 = 8;
      if (6 < uVar4) {
        uVar11 = 0xb;
      }
      if (((((uVar2 & 0xf) != uVar10) && ((uVar2 & 0xf) != uVar11)) &&
          (uVar2 = uVar2 >> 4 & 0xf, uVar2 != uVar10)) &&
         (((uVar2 != uVar11 && (uVar2 = uVar3 >> 4 & 0xf, uVar2 != uVar10)) && (uVar2 != uVar11))))
      {
        return 0;
      }
      goto LAB_00103430;
    }
    iVar6 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar6 == 0) goto LAB_00103430;
    pcVar9 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar13 + -0xb8),pcVar9,"lpass_cdc_wsa_macro_adie_lb");
LAB_00103430:
  lpass_cdc_wsa_pa_on(lVar7,1);
  snd_soc_component_update_bits(lVar12,iVar5,0x10,0);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_enable_swr @ 001034b0 size=400
// signature: undefined lpass_cdc_wsa_macro_enable_swr(void)
// callers: [lpass_cdc_wsa_macro_enable_mix_path]
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_enable_swr(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + -0xb8),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      if (param_3 == 8) {
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00119f6d,8);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x110) != 0)) {
          *(int *)(lVar2 + 0x110) = *(int *)(lVar2 + 0x110) + -1;
        }
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011af2a,8);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x114) != 0)) {
          *(int *)(lVar2 + 0x114) = *(int *)(lVar2 + 0x114) + -1;
          return 0;
        }
      }
      else if (param_3 == 1) {
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00119f6d,8);
        if ((lVar4 == 0) && (*(int *)(lVar2 + 0x110) == 0)) {
          *(undefined4 *)(lVar2 + 0x110) = 1;
        }
        lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011af2a,8);
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + -0xb8),pcVar3,"lpass_cdc_wsa_macro_enable_swr");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_enable_interpolator @ 00103644 size=1024
// signature: undefined lpass_cdc_wsa_macro_enable_interpolator(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_enable_interpolator(long param_1,undefined8 param_2,int param_3)

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
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + -0xb8),2);
  if (lVar9 == 0) {
LAB_00103728:
    iVar6 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar6 == 0) {
      return 0xffffffea;
    }
    pcVar15 = "%s: null device for macro!\n";
  }
  else {
    if ((*(long *)(lVar9 + 0x98) != 0) && (*(long *)(*(long *)(lVar9 + 0x98) + 0x108) != 0)) {
      lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + -0xb8),2);
      if (lVar9 == 0) goto LAB_00103728;
      lVar9 = *(long *)(lVar9 + 0x98);
      if ((lVar9 != 0) && (lVar16 = *(long *)(lVar9 + 0x108), lVar16 != 0)) {
        pcVar15 = *(char **)(param_1 + 8);
        iVar6 = strcmp(pcVar15,"WSA_RX INT0 INTERP");
        if (iVar6 == 0) {
          uVar10 = 0x2400;
        }
        else {
          iVar7 = strcmp(pcVar15,"WSA_RX INT1 INTERP");
          if (iVar7 != 0) {
            iVar6 = ___ratelimit(lpass_cdc_wsa_macro_enable_interpolator__rs,
                                 "lpass_cdc_wsa_macro_enable_interpolator");
            if (iVar6 == 0) {
              return 0xffffffea;
            }
            uVar10 = *(undefined8 *)(lVar17 + -0xb8);
            pcVar15 = "%s: Interpolator reg not found\n";
            goto LAB_0010376c;
          }
          uVar10 = 0x2480;
        }
        lVar17 = lVar17 + -0xd0;
        if (param_3 == 8) {
          snd_soc_component_update_bits(lVar17,0x2408,8,8);
          lpass_cdc_wsa_macro_config_compander(lVar17,*(undefined1 *)(param_1 + 0x4c),8);
          bVar3 = *(byte *)(param_1 + 0x4c);
          uVar12 = (ulong)bVar3;
          if (*(char *)(lVar9 + 0x288) != '\0') {
            uVar13 = 0x2410;
            if (bVar3 != 0) {
              uVar13 = 0;
            }
            uVar14 = 0;
            if (bVar3 < 2) {
              uVar14 = 0x2780;
            }
            uVar1 = 2;
            if (bVar3 != 1) {
              uVar1 = bVar3 == 0;
            }
            uVar2 = 0x2490;
            if (bVar3 != 1) {
              uVar2 = uVar13;
            }
            if (1 < bVar3) {
LAB_00103a40:
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x103a44);
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
            snd_soc_component_write(lVar17,0x2790,0);
            uVar12 = (ulong)*(byte *)(param_1 + 0x4c);
          }
          lpass_cdc_wsa_macro_config_softclip(lVar17,uVar12,8);
          lpass_cdc_was_macro_config_pbr(lVar17,*(undefined1 *)(param_1 + 0x4c),8);
          uVar11 = 8;
        }
        else {
          if (param_3 == 2) {
            if ((iVar6 == 0) &&
               (bVar3 = *(byte *)(lVar9 + 0x21c), bVar4 = *(byte *)(lVar9 + 0x228),
               uVar8 = snd_soc_component_read(lVar16,0x2414),
               uVar8 != ((uint)bVar3 - (uint)bVar4 & 0xff))) {
              snd_soc_component_update_bits(*(undefined8 *)(lVar9 + 0x108),0x2414,0xff);
            }
            iVar6 = strcmp(*(char **)(param_1 + 8),"WSA_RX INT1 INTERP");
            if ((iVar6 == 0) &&
               (bVar3 = *(byte *)(lVar9 + 0x21d), bVar4 = *(byte *)(lVar9 + 0x228),
               uVar8 = snd_soc_component_read(*(undefined8 *)(lVar9 + 0x108),0x2494),
               uVar8 != ((uint)bVar3 - (uint)bVar4 & 0xff))) {
              snd_soc_component_update_bits(*(undefined8 *)(lVar9 + 0x108),0x2494,0xff);
            }
            lpass_cdc_wsa_macro_config_compander(lVar17,*(undefined1 *)(param_1 + 0x4c),2);
            bVar3 = *(byte *)(param_1 + 0x4c);
            uVar12 = (ulong)bVar3;
            if (*(char *)(lVar9 + 0x288) != '\0') {
              uVar13 = 0x2410;
              if (bVar3 != 0) {
                uVar13 = 0;
              }
              uVar14 = 0;
              if (bVar3 < 2) {
                uVar14 = 0x2780;
              }
              uVar1 = 2;
              if (bVar3 != 1) {
                uVar1 = bVar3 == 0;
              }
              uVar2 = 0x2490;
              if (bVar3 != 1) {
                uVar2 = uVar13;
              }
              if (1 < bVar3) goto LAB_00103a40;
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
            lpass_cdc_wsa_macro_config_softclip(lVar17,uVar12,2);
            lpass_cdc_was_macro_config_pbr(lVar17,*(undefined1 *)(param_1 + 0x4c),2);
            if (*(int *)(lVar9 + 0x1cc) == 0) {
              return 0;
            }
            snd_soc_component_update_bits(lVar17,0x2408,8,0);
            return 0;
          }
          if (param_3 != 1) {
            return 0;
          }
          uVar11 = 1;
        }
        lpass_cdc_wsa_macro_enable_prim_interpolator(lVar17,uVar10,uVar11);
        return 0;
      }
    }
    iVar6 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar6 == 0) {
      return 0xffffffea;
    }
    pcVar15 = "%s: priv is null for macro!\n";
  }
  uVar10 = *(undefined8 *)(lVar17 + -0xb8);
LAB_0010376c:
  _dev_err(uVar10,pcVar15,"lpass_cdc_wsa_macro_enable_interpolator");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_spk_boost_event @ 00103a48 size=288
// signature: undefined lpass_cdc_wsa_macro_spk_boost_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_spk_boost_event(long param_1,undefined8 param_2,int param_3)

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
  iVar1 = strcmp(__s1,"WSA_RX INT0 CHAIN");
  if (iVar1 == 0) {
    uVar4 = 0x2408;
    uVar5 = 0x2500;
  }
  else {
    iVar1 = strcmp(__s1,"WSA_RX INT1 CHAIN");
    if (iVar1 != 0) {
      iVar1 = ___ratelimit(lpass_cdc_wsa_macro_spk_boost_event__rs,
                           "lpass_cdc_wsa_macro_spk_boost_event");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*(undefined8 *)(lVar6 + -0xb8),"%s: unknown widget: %s\n",
               "lpass_cdc_wsa_macro_spk_boost_event",*(undefined8 *)(param_1 + 8));
      return 0xffffffea;
    }
    uVar4 = 0x2488;
    uVar5 = 0x2540;
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
// lpass_cdc_wsa_macro_enable_vbat @ 00103b6c size=1172
// signature: undefined lpass_cdc_wsa_macro_enable_vbat(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_enable_vbat(long param_1,undefined8 param_2,int param_3)

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
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + -0xb8),2);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
      iVar2 = strcmp(pcVar9,"WSA_RX INT0 VBAT");
      if (iVar2 == 0) {
        uVar11 = 0;
        uVar7 = 0x2408;
      }
      else {
        iVar2 = strcmp(pcVar9,"WSA_RX INT1 VBAT");
        uVar11 = (ulong)(iVar2 == 0);
        uVar7 = 0x2488;
        if (iVar2 != 0) {
          uVar7 = 0;
        }
      }
      if (param_3 == 8) {
        snd_soc_component_update_bits(lVar8,0x2908,1,0);
        snd_soc_component_update_bits(lVar8,0x2904,1,0);
        snd_soc_component_update_bits(lVar8,0x2900,1,0);
        snd_soc_component_update_bits(lVar8,uVar7,0x80,0);
        snd_soc_component_update_bits(lVar8,0x2184,2,2);
        snd_soc_component_update_bits(lVar8,uVar7,2,0);
        snd_soc_component_update_bits(lVar8,0x21dc,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21e0,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21e4,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21e8,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21ec,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21f0,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21f4,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21f8,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21fc,0xff,0);
        lVar10 = lVar10 + uVar11 * 4;
        iVar2 = *(int *)(lVar10 + 0x1e0) + -1;
        *(int *)(lVar10 + 0x1e0) = iVar2;
        if (iVar2 == 0) {
          snd_soc_component_update_bits(lVar8,(int)uVar11 << 5 | 0x2640,1,0);
          snd_soc_component_update_bits(lVar8,0x2118,1 << uVar11,0);
        }
        snd_soc_component_update_bits(lVar8,0x2184,1,0);
        uVar4 = 0x2180;
        uVar5 = 0x10;
        uVar6 = 0;
      }
      else {
        if (param_3 != 1) {
          uVar4 = ___ratelimit(lpass_cdc_wsa_macro_enable_vbat__rs,"lpass_cdc_wsa_macro_enable_vbat"
                              );
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          _dev_err(lVar3,"%s: Invalid event %d\n","lpass_cdc_wsa_macro_enable_vbat",param_3);
          return 0;
        }
        snd_soc_component_update_bits(lVar8,0x2180,0x10,0x10);
        snd_soc_component_update_bits(lVar8,0x2184,1,1);
        snd_soc_component_update_bits(lVar8,uVar7,0x80,0x80);
        snd_soc_component_update_bits(lVar8,0x2184,2,0);
        lVar10 = lVar10 + uVar11 * 4;
        piVar1 = (int *)(lVar10 + 0x1e0);
        iVar2 = *(int *)(lVar10 + 0x1e0);
        if (iVar2 == 0) {
          snd_soc_component_update_bits(lVar8,(int)uVar11 << 5 | 0x2640,1,1);
          snd_soc_component_update_bits(lVar8,0x2118,1 << uVar11,1 << uVar11);
          iVar2 = *piVar1;
        }
        *piVar1 = iVar2 + 1;
        snd_soc_component_update_bits(lVar8,uVar7,2,2);
        snd_soc_component_update_bits(lVar8,0x21dc,0xff,0xff);
        snd_soc_component_update_bits(lVar8,0x21e0,0xff,3);
        snd_soc_component_update_bits(lVar8,0x21e4,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21e8,0xff,0xff);
        snd_soc_component_update_bits(lVar8,0x21ec,0xff,3);
        snd_soc_component_update_bits(lVar8,0x21f0,0xff,0);
        snd_soc_component_update_bits(lVar8,0x21f4,0xff,0xff);
        snd_soc_component_update_bits(lVar8,0x21f8,0xff,3);
        snd_soc_component_update_bits(lVar8,0x21fc,0xff,0);
        snd_soc_component_update_bits(lVar8,0x2900,1,1);
        snd_soc_component_update_bits(lVar8,0x2904,1,1);
        uVar4 = 0x2908;
        uVar5 = 1;
        uVar6 = 1;
      }
      snd_soc_component_update_bits(lVar8,uVar4,uVar5,uVar6);
      return 0;
    }
    iVar2 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar8 + -0xb8),pcVar9,"lpass_cdc_wsa_macro_enable_vbat");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_mclk_event @ 00104004 size=316
// signature: undefined lpass_cdc_wsa_macro_mclk_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_mclk_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        lpass_cdc_wsa_macro_mclk_enable(puVar5,0);
        *(undefined1 *)(puVar5 + 5) = 0;
        return 0;
      }
      if (param_3 == 1) {
        uVar3 = lpass_cdc_wsa_macro_mclk_enable(puVar5,1);
        if ((int)uVar3 == 0) {
          *(undefined1 *)(puVar5 + 5) = 1;
          return uVar3;
        }
        *(undefined1 *)(puVar5 + 5) = 0;
        return uVar3;
      }
      iVar1 = ___ratelimit(lpass_cdc_wsa_macro_mclk_event__rs,"lpass_cdc_wsa_macro_mclk_event");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*puVar5,"%s: invalid DAPM event %d\n","lpass_cdc_wsa_macro_mclk_event",param_3);
      return 0xffffffea;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar6 + -0xb8),pcVar4,"lpass_cdc_wsa_macro_mclk_event");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_vi_feed_mixer_get @ 00104144 size=260
// signature: undefined lpass_cdc_wsa_macro_vi_feed_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_vi_feed_mixer_get(long param_1,long param_2)

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
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + -0xb8),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104248);
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
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + -0xb8),pcVar6,"lpass_cdc_wsa_macro_vi_feed_mixer_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_vi_feed_mixer_put @ 0010424c size=460
// signature: undefined lpass_cdc_wsa_macro_vi_feed_mixer_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_vi_feed_mixer_put(long param_1,long param_2)

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
  lVar7 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar9 + -0xb8),2);
  if (lVar7 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: null device for macro!\n";
LAB_001043c0:
    _dev_err(*(undefined8 *)(lVar9 + -0xb8),pcVar8,"lpass_cdc_wsa_macro_vi_feed_mixer_put");
    return 0xffffffea;
  }
  lVar7 = *(long *)(lVar7 + 0x98);
  if ((lVar7 == 0) || (*(long *)(lVar7 + 0x108) == 0)) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar8 = "%s: priv is null for macro!\n";
    goto LAB_001043c0;
  }
  *(int *)(lVar7 + 0x2c) = (int)*(undefined8 *)(param_2 + 0x48);
  if (iVar5 == 0) {
    if (iVar2 == 1) {
      if (((uint)*(undefined8 *)(lVar7 + 0x130) >> 1 & 1) == 0) goto LAB_00104388;
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
      if ((iVar2 != 0) || ((*(ulong *)(lVar7 + 0x130) & 1) == 0)) goto LAB_00104388;
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
    if (((uint)*(undefined8 *)(lVar7 + 0x130) >> 1 & 1) != 0) goto LAB_00104388;
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
    if ((iVar2 != 0) || ((*(ulong *)(lVar7 + 0x130) & 1) != 0)) goto LAB_00104388;
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
LAB_00104388:
  snd_soc_dapm_mixer_update_power(*(undefined8 *)(lVar6 + 0x28),param_1,iVar5,0);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_cps_feed_mixer_get @ 0010445c size=260
// signature: undefined lpass_cdc_wsa_macro_cps_feed_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_cps_feed_mixer_get(long param_1,long param_2)

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
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + -0xb8),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104560);
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
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + -0xb8),pcVar6,"lpass_cdc_wsa_macro_cps_feed_mixer_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_cps_feed_mixer_put @ 00104564 size=512
// signature: undefined lpass_cdc_wsa_macro_cps_feed_mixer_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_cps_feed_mixer_put(long param_1,long param_2)

{
  ulong *puVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  long lVar12;
  
  lVar8 = snd_soc_dapm_kcontrol_widget();
  lVar12 = *(long *)(lVar8 + 0x28);
  bVar3 = *(byte *)(lVar8 + 0x4c);
  uVar11 = (ulong)bVar3;
  iVar7 = *(int *)(*(long *)(param_1 + 0x78) + 0x18);
  iVar2 = *(int *)(param_2 + 0x48);
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar12 + -0xb8),2);
  if (lVar9 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: null device for macro!\n";
LAB_00104708:
    _dev_err(*(undefined8 *)(lVar12 + -0xb8),pcVar10,"lpass_cdc_wsa_macro_cps_feed_mixer_put");
    return 0xffffffea;
  }
  lVar9 = *(long *)(lVar9 + 0x98);
  if ((lVar9 == 0) || (*(long *)(lVar9 + 0x108) == 0)) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
    goto LAB_00104708;
  }
  if (iVar2 == 0) {
    if (iVar7 == 1) {
      if (6 < bVar3) goto LAB_00104720;
      lVar12 = lVar9 + uVar11 * 8;
      if (((uint)*(undefined8 *)(lVar12 + 0x118) >> 1 & 1) == 0) goto LAB_001046d0;
      puVar1 = (ulong *)(lVar12 + 0x118);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
    }
    else {
      if (iVar7 != 0) goto LAB_001046d0;
      if (6 < bVar3) goto LAB_00104720;
      lVar12 = lVar9 + uVar11 * 8;
      if ((*(ulong *)(lVar12 + 0x118) & 1) == 0) goto LAB_001046d0;
      puVar1 = (ulong *)(lVar12 + 0x118);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
    }
    lVar12 = -1;
  }
  else if (iVar7 == 1) {
    if (6 < bVar3) {
LAB_00104720:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x104724);
      (*pcVar6)();
    }
    lVar12 = lVar9 + uVar11 * 8;
    if (((uint)*(undefined8 *)(lVar12 + 0x118) >> 1 & 1) != 0) goto LAB_001046d0;
    puVar1 = (ulong *)(lVar12 + 0x118);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 | 2;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    lVar12 = 1;
  }
  else {
    if (iVar7 != 0) goto LAB_001046d0;
    if (6 < bVar3) goto LAB_00104720;
    lVar12 = lVar9 + uVar11 * 8;
    if ((*(ulong *)(lVar12 + 0x118) & 1) != 0) goto LAB_001046d0;
    puVar1 = (ulong *)(lVar12 + 0x118);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 | 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    lVar12 = 1;
  }
  lVar9 = lVar9 + uVar11 * 8;
  *(long *)(lVar9 + 0x148) = *(long *)(lVar9 + 0x148) + lVar12;
LAB_001046d0:
  snd_soc_dapm_mixer_update_power(*(undefined8 *)(lVar8 + 0x28),param_1,iVar2,0);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_rx_mux_get @ 00104798 size=216
// signature: undefined lpass_cdc_wsa_macro_rx_mux_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_rx_mux_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  long lVar6;
  
  lVar3 = snd_soc_dapm_kcontrol_widget();
  lVar6 = *(long *)(lVar3 + 0x28);
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),2);
  if (lVar4 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104870);
        (*pcVar1)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar4 + (ulong)*(byte *)(lVar3 + 0x4c) * 4 + 0x184)
      ;
      return 0;
    }
    iVar2 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar6 + -0xb8),pcVar5,"lpass_cdc_wsa_macro_rx_mux_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_rx_mux_put @ 00104874 size=608
// signature: undefined lpass_cdc_wsa_macro_rx_mux_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_rx_mux_put(long param_1,long param_2)

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
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + -0xb8),2);
  if (lVar9 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: null device for macro!\n";
LAB_00104a94:
    _dev_err(*(undefined8 *)(lVar16 + -0xb8),pcVar10,"lpass_cdc_wsa_macro_rx_mux_put");
    return 0xffffffea;
  }
  lVar11 = *(long *)(lVar9 + 0x98);
  if ((lVar11 == 0) || (*(long *)(lVar11 + 0x108) == 0)) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
    goto LAB_00104a94;
  }
  if (8 < (ulong)*(byte *)(lVar8 + 0x4c)) {
LAB_00104aa8:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x104aac);
    (*pcVar6)();
  }
  lVar16 = lVar11 + (ulong)*(byte *)(lVar8 + 0x4c) * 4;
  puVar1 = (uint *)(lVar16 + 0x184);
  uVar13 = (uint)uVar14;
  if (uVar13 == 0) {
    uVar13 = *(uint *)(lVar16 + 0x184);
    if (uVar13 == 0) {
      uVar15 = ___ratelimit(lpass_cdc_wsa_macro_rx_mux_put__rs,"lpass_cdc_wsa_macro_rx_mux_put");
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
          goto LAB_0010492c;
        }
        goto LAB_00104938;
      }
      uVar15 = ___ratelimit(lpass_cdc_wsa_macro_rx_mux_put__rs_127,"lpass_cdc_wsa_macro_rx_mux_put")
      ;
      if ((int)uVar15 == 0) {
        return uVar15;
      }
      pcVar10 = "%s: Invalid AIF reset\n";
    }
    _dev_err(lVar9,pcVar10,"lpass_cdc_wsa_macro_rx_mux_put");
  }
  else {
    *puVar1 = uVar13;
    if (2 < uVar13) {
      iVar7 = ___ratelimit(lpass_cdc_wsa_macro_rx_mux_put__rs_129,"lpass_cdc_wsa_macro_rx_mux_put");
      if (iVar7 == 0) {
        return 0xffffffea;
      }
      _dev_err(lVar9,"%s: Invalid AIF_ID for WSA RX MUX %d\n","lpass_cdc_wsa_macro_rx_mux_put",
               uVar14 & 0xffffffff);
      return 0xffffffea;
    }
    uVar12 = uVar14 & 0xffffffff;
    if (6 < uVar12) goto LAB_00104aa8;
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
LAB_0010492c:
    *(long *)(lVar11 + 0x148) = *(long *)(lVar11 + 0x148) + lVar9;
LAB_00104938:
    snd_soc_dapm_mux_update_power
              (*(undefined8 *)(lVar8 + 0x28),param_1,uVar14 & 0xffffffff,uVar15,0);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_enable_prim_interpolator @ 00104ae4 size=760
// signature: undefined lpass_cdc_wsa_macro_enable_prim_interpolator(void)
// callers: [lpass_cdc_wsa_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_wsa_macro_enable_prim_interpolator(long param_1,ushort param_2,int param_3)

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
  
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar6 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return;
    }
    pcVar7 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x98);
    if ((lVar6 != 0) && (*(long *)(lVar6 + 0x108) != 0)) {
      lVar12 = 0;
      if (param_2 < 0x2480) {
        uVar13 = 0x2400;
        if ((param_2 != 0x2400) && (param_2 != 0x2418)) {
          uVar13 = 0;
        }
      }
      else if ((param_2 == 0x2498) || (uVar13 = 0, param_2 == 0x2480)) {
        uVar13 = 0x2480;
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
        iVar4 = 0x2404;
        if (uVar13 != 0x2400) {
          iVar4 = 0;
        }
        iVar1 = 0x2484;
        if (uVar13 != 0x2480) {
          iVar1 = iVar4;
        }
        if (iVar1 == 0) {
          return;
        }
        uVar10 = 0x2430;
        if (uVar13 != 0x2400) {
          uVar10 = 0;
        }
        param_2 = 0x24b0;
        if (uVar13 != 0x2480) {
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
          iVar4 = 0x2404;
          if (uVar13 != 0x2400) {
            iVar4 = 0;
          }
          iVar1 = 0x2484;
          if (uVar13 != 0x2480) {
            iVar1 = iVar4;
          }
          if (iVar1 != 0) {
            uVar11 = 0x2430;
            if (uVar13 != 0x2400) {
              uVar11 = 0;
            }
            uVar2 = 0x24b0;
            if (uVar13 != 0x2480) {
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
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar7,"lpass_cdc_wsa_macro_enable_prim_interpolator");
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_config_compander @ 00104ddc size=752
// signature: undefined lpass_cdc_wsa_macro_config_compander(void)
// callers: [lpass_cdc_wsa_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_wsa_macro_config_compander(long param_1,uint param_2,ulong param_3)

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
  
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar9 == 0) {
    iVar8 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
                 "lpass_cdc_wsa_macro_config_compander",param_2);
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
                   "lpass_cdc_wsa_macro_config_compander");
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
          pcVar7 = (code *)SoftwareBreakpoint(1,0x1050cc);
          (*pcVar7)();
        }
        *(int *)(comp_setting_table + uVar12 * 0xc) = (iVar14 << 1) / 10;
      }
      uVar11 = param_2 * 0x60 + 0x2580;
      uVar1 = param_2 * 0x80 + 0x2404;
      if ((param_3 & 3) != 0) {
        lpass_cdc_update_compander_setting(param_1,param_2 * 0x60 + 0x25a0);
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
    iVar8 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar8 == 0) {
      return;
    }
    pcVar10 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar10,"lpass_cdc_wsa_macro_config_compander");
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_config_softclip @ 001050cc size=440
// signature: undefined lpass_cdc_wsa_macro_config_softclip(void)
// callers: [lpass_cdc_wsa_macro_enable_interpolator]
//------------------------------------------------------------

void lpass_cdc_wsa_macro_config_softclip(long param_1,int param_2,ulong param_3)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  ulong uVar8;
  
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
      uVar3 = (uint)(param_2 == 1) << 5 | 0x2644;
      if ((param_3 & 3) != 0) {
        lVar2 = lVar6 + uVar8 * 4;
        piVar1 = (int *)(lVar2 + 0x1e0);
        iVar5 = *(int *)(lVar2 + 0x1e0);
        if (iVar5 == 0) {
          snd_soc_component_update_bits(param_1,uVar4 | 0x2640,1,1);
          snd_soc_component_update_bits(param_1,0x2118,1 << uVar8,1 << uVar8);
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
        snd_soc_component_update_bits(param_1,uVar4 | 0x2640,1,0);
        snd_soc_component_update_bits(param_1,0x2118,1 << (ulong)(param_2 == 1),0);
        return;
      }
      return;
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar7,"lpass_cdc_wsa_macro_config_softclip");
  return;
}



//------------------------------------------------------------
// lpass_cdc_was_macro_config_pbr @ 00105284 size=744
// signature: undefined lpass_cdc_was_macro_config_pbr(void)
// callers: [lpass_cdc_wsa_macro_enable_interpolator]
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
  
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),2);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: null device for macro!\n";
LAB_00105340:
    _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar7,"lpass_cdc_was_macro_config_pbr");
    return;
  }
  lVar6 = *(long *)(lVar6 + 0x98);
  if ((lVar6 == 0) || (*(long *)(lVar6 + 0x108) == 0)) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return;
    }
    pcVar7 = "%s: priv is null for macro!\n";
    goto LAB_00105340;
  }
  if (param_2 == 0) {
    uVar9 = 0x2408;
    uVar10 = 0x2410;
    uVar11 = 0x2580;
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
      goto joined_r0x0010538c;
    }
    uVar9 = 0x2488;
    uVar10 = 0x2490;
    uVar11 = 0x25e0;
    uVar12 = 1;
    cVar3 = *(char *)(lVar6 + 0x260);
  }
  bVar8 = 1;
joined_r0x0010538c:
  if (cVar3 == '\0') {
    return;
  }
  if (1 < param_2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10556c);
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
      snd_soc_component_update_bits(param_1,uVar12 << 5 | 0x2640,1,1);
      snd_soc_component_update_bits(param_1,0x2118,1 << (ulong)uVar12,1 << (ulong)uVar12);
      iVar5 = *(int *)(lVar1 + 0x1e0);
    }
    *(int *)(lVar1 + 0x1e0) = iVar5 + 1;
    iVar5 = *(int *)(lVar6 + 0x294);
    if (iVar5 == 0) {
      snd_soc_component_update_bits(param_1,0x2b00,1,1);
      iVar5 = *(int *)(lVar6 + 0x294);
    }
    *(int *)(lVar6 + 0x294) = iVar5 + 1;
  }
  if ((param_3 & 0xc) == 0) {
    return;
  }
  if (*(int *)(lVar6 + 0x294) == 1) {
    snd_soc_component_update_bits(param_1,0x2b00,1,0);
  }
  iVar5 = *(int *)(lVar1 + 0x1e0) + -1;
  *(int *)(lVar1 + 0x1e0) = iVar5;
  if (iVar5 == 0) {
    snd_soc_component_update_bits(param_1,uVar12 << 5 | 0x2640,1,0);
    snd_soc_component_update_bits(param_1,0x2118,1 << (ulong)uVar12,0);
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
// lpass_cdc_wsa_macro_enable_mix_path @ 00105570 size=404
// signature: undefined lpass_cdc_wsa_macro_enable_mix_path(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_enable_mix_path(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  int iVar4;
  char *__s1;
  undefined8 uVar5;
  long lVar6;
  
  __s1 = *(char **)(param_1 + 8);
  lVar6 = *(long *)(param_1 + 0x28);
  iVar2 = strcmp(__s1,"WSA_RX0 MIX INP");
  if (iVar2 == 0) {
    bVar1 = *(byte *)(param_1 + 0x4c);
    iVar4 = 0x2400;
    iVar2 = 0x2418;
    uVar5 = 0x2420;
  }
  else {
    iVar2 = strcmp(__s1,"WSA_RX1 MIX INP");
    if (iVar2 != 0) {
      iVar2 = ___ratelimit(lpass_cdc_wsa_macro_enable_mix_path__rs,
                           "lpass_cdc_wsa_macro_enable_mix_path");
      if (iVar2 == 0) {
        return 0;
      }
      _dev_err(*(undefined8 *)(lVar6 + -0xb8),"%s: No gain register avail for %s\n",
               "lpass_cdc_wsa_macro_enable_mix_path",*(undefined8 *)(param_1 + 8));
      return 0;
    }
    bVar1 = *(byte *)(param_1 + 0x4c);
    iVar4 = 0x2480;
    iVar2 = 0x2498;
    uVar5 = 0x24a0;
  }
  iVar2 = (uint)bVar1 * 0x80 + iVar2;
  lVar6 = lVar6 + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar6,*(undefined4 *)(param_1 + 0x48),0x20,0);
    lpass_cdc_wsa_macro_enable_swr(param_1,extraout_x1_00,8);
  }
  else if (param_3 == 1) {
    snd_soc_component_update_bits(lVar6,iVar2,0x40,0x40);
    usleep_range_state(500,0x1fe,2);
    snd_soc_component_update_bits(lVar6,iVar2,0x40,0);
    snd_soc_component_update_bits(lVar6,(uint)bVar1 * 0x80 + iVar4,0x20,0x20);
    snd_soc_component_update_bits(lVar6,iVar2,0x20,0x20);
    lpass_cdc_wsa_macro_enable_swr(param_1,extraout_x1,1);
    uVar3 = snd_soc_component_read(lVar6,uVar5);
    snd_soc_component_write(lVar6,uVar5,uVar3);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_get @ 00105708 size=64
// signature: undefined lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_get(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0x80),0x2184);
  *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 >> 2 & 1);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_put @ 0010574c size=60
// signature: undefined lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_put(long param_1,long param_2)

{
  snd_soc_component_update_bits
            (*(undefined8 *)(param_1 + 0x80),0x2184,4,(ulong)(*(long *)(param_2 + 0x48) != 0) << 2);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_comp_mode_get @ 0010578c size=248
// signature: undefined lpass_cdc_wsa_macro_comp_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_comp_mode_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      strnstr(param_1 + 0x20,&DAT_00119f6d,8);
      lVar4 = strnstr(param_1 + 0x20,&DAT_0011af2a,8);
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar2 + (ulong)(lVar4 != 0) * 4 + 0x10);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_comp_mode_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_comp_mode_put @ 00105888 size=264
// signature: undefined lpass_cdc_wsa_macro_comp_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_comp_mode_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0x108) != 0)) {
      strnstr(param_1 + 0x20,&DAT_00119f6d,8);
      lVar4 = strnstr(param_1 + 0x20,&DAT_0011af2a,8);
      if (*(ulong *)(param_2 + 0x48) < 0x13) {
        *(int *)(lVar2 + (ulong)(lVar4 != 0) * 4 + 0x10) = (int)*(ulong *)(param_2 + 0x48);
        return 0;
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_comp_mode_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_ear_spkrrecv_get @ 00105994 size=180
// signature: undefined lpass_cdc_wsa_macro_ear_spkrrecv_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_ear_spkrrecv_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_ear_spkrrecv_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_ear_spkrrecv_put @ 00105a4c size=180
// signature: undefined lpass_cdc_wsa_macro_ear_spkrrecv_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_ear_spkrrecv_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_ear_spkrrecv_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_idle_detect_get @ 00105b04 size=180
// signature: undefined lpass_cdc_wsa_macro_idle_detect_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_idle_detect_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_idle_detect_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_idle_detect_put @ 00105bbc size=180
// signature: undefined lpass_cdc_wsa_macro_idle_detect_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_idle_detect_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_idle_detect_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_soft_clip_enable_get @ 00105c74 size=208
// signature: undefined lpass_cdc_wsa_macro_soft_clip_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_soft_clip_enable_get(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105d44);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 0x1d8);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa_macro_soft_clip_enable_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_soft_clip_enable_put @ 00105d48 size=208
// signature: undefined lpass_cdc_wsa_macro_soft_clip_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_soft_clip_enable_put(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105e18);
        (*pcVar3)();
      }
      *(int *)(lVar5 + (ulong)uVar2 * 4 + 0x1d8) = (int)*(undefined8 *)(param_2 + 0x48);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa_macro_soft_clip_enable_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_set_digital_volume @ 00105e1c size=372
// signature: undefined lpass_cdc_wsa_macro_set_digital_volume(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_wsa_macro_set_digital_volume(long param_1,undefined8 param_2)

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
  lVar8 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar2 + 0x18),2);
  if (lVar8 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
      if (iVar7 == 0x2494) {
        iVar6 = snd_soc_component_read(puVar11[0x21],0x2494);
        iVar7 = *(int *)(puVar11 + 0x45);
        *(char *)((long)puVar11 + 0x21d) = (char)iVar6;
        uVar5 = iVar6 - iVar7;
        cVar3 = *(char *)(puVar11 + 5);
joined_r0x00105f2c:
        if (cVar3 == '\0') {
          return uVar4;
        }
        if (iVar7 == 0) {
          return uVar4;
        }
        snd_soc_component_update_bits(puVar11[0x21],*(undefined4 *)(lVar1 + 0xc),0xff,uVar5 & 0xff);
        return uVar4;
      }
      if (iVar7 == 0x2414) {
        uVar5 = snd_soc_component_read(puVar11[0x21],0x2414);
        iVar7 = *(int *)(puVar11 + 0x45);
        *(char *)((long)puVar11 + 0x21c) = (char)uVar5;
        uVar5 = (uVar5 & 0xff) - iVar7;
        cVar3 = *(char *)(puVar11 + 5);
        goto joined_r0x00105f2c;
      }
      iVar7 = ___ratelimit(lpass_cdc_wsa_macro_set_digital_volume__rs_220,
                           "lpass_cdc_wsa_macro_set_digital_volume");
      if (iVar7 == 0) {
        return 0xffffffea;
      }
      uVar9 = *puVar11;
      pcVar10 = "%s: Incorrect RX Path selected\n";
      goto LAB_00105f80;
    }
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
  }
  uVar9 = *(undefined8 *)(lVar2 + 0x18);
LAB_00105f80:
  _dev_err(uVar9,pcVar10,"lpass_cdc_wsa_macro_set_digital_volume");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_get_rx_mute_status @ 00105f94 size=208
// signature: undefined lpass_cdc_wsa_macro_get_rx_mute_status(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_get_rx_mute_status(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x106064);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 0x1f8);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa_macro_get_rx_mute_status");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_set_rx_mute_status @ 00106068 size=416
// signature: undefined lpass_cdc_wsa_macro_set_rx_mute_status(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_set_rx_mute_status(long param_1,long param_2)

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
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar10 + 0x18),2);
  if (lVar5 == 0) {
    iVar3 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: null device for macro!\n";
LAB_001061d0:
    _dev_err(*(undefined8 *)(lVar10 + 0x18),pcVar7,"lpass_cdc_wsa_macro_set_rx_mute_status");
    return 0xffffffea;
  }
  plVar9 = *(long **)(lVar5 + 0x98);
  if ((plVar9 == (long *)0x0) || (plVar9[0x21] == 0)) {
    iVar3 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: priv is null for macro!\n";
    goto LAB_001061d0;
  }
  __pm_runtime_resume(*plVar9,4);
  switch((ulong)uVar1) {
  case 0:
    uVar8 = 0x2400;
    break;
  case 1:
    uVar8 = 0x2480;
    break;
  case 2:
    uVar8 = 0x2418;
    break;
  case 3:
    uVar8 = 0x2498;
    break;
  default:
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_set_rx_mute_status__rs,
                         "lpass_cdc_wsa_macro_set_rx_mute_status");
    if (iVar4 != 0) {
      _printk(&DAT_0011addf,"lpass_cdc_wsa_macro_set_rx_mute_status",uVar1);
    }
    uVar8 = 0xffffffea;
    goto LAB_00106184;
  }
  snd_soc_component_update_bits(lVar10,uVar8,0x10,iVar3 << 4);
  uVar8 = 0;
LAB_00106184:
  lVar10 = *plVar9;
  uVar6 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar10 + 0x220) = uVar6;
  __pm_runtime_suspend(*plVar9,0xd);
  if (8 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106208);
    (*pcVar2)();
  }
  *(int *)((long)plVar9 + (ulong)uVar1 * 4 + 0x1f8) = iVar3;
  return uVar8;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_get_compander @ 0010620c size=208
// signature: undefined lpass_cdc_wsa_macro_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_get_compander(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1062dc);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 8);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa_macro_get_compander");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_set_compander @ 001062e0 size=204
// signature: undefined lpass_cdc_wsa_macro_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_set_compander(long param_1,long param_2)

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
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1063ac);
        (*pcVar4)();
      }
      *(undefined4 *)(lVar6 + (ulong)uVar3 * 4 + 8) = uVar2;
      return 0;
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar7,"lpass_cdc_wsa_macro_set_compander");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_get_ec_hq @ 001063b0 size=208
// signature: undefined lpass_cdc_wsa_macro_get_ec_hq(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_get_ec_hq(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  
  lVar1 = *(long *)(param_1 + 0x80);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x106480);
        (*pcVar3)();
      }
      *(long *)(param_2 + 0x48) = (long)*(int *)(lVar5 + (ulong)uVar2 * 4 + 0x18);
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar6,"lpass_cdc_wsa_macro_get_ec_hq");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_set_ec_hq @ 00106484 size=204
// signature: undefined lpass_cdc_wsa_macro_set_ec_hq(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_set_ec_hq(long param_1,long param_2)

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
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar1 + 0x18),2);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x106550);
        (*pcVar4)();
      }
      *(undefined4 *)(lVar6 + (ulong)uVar3 * 4 + 0x18) = uVar2;
      return 0;
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar1 + 0x18),pcVar7,"lpass_cdc_wsa_macro_set_ec_hq");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_pbr_enable_get @ 00106554 size=180
// signature: undefined lpass_cdc_wsa_macro_pbr_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_pbr_enable_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_pbr_enable_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_pbr_enable_put @ 0010660c size=188
// signature: undefined lpass_cdc_wsa_macro_pbr_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_pbr_enable_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),2);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_wsa_macro_pbr_enable_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_get_channel_map @ 001066cc size=680
// signature: undefined lpass_cdc_wsa_macro_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
lpass_cdc_wsa_macro_get_channel_map
          (long param_1,uint *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  ulong uVar1;
  code *pcVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  char *pcVar9;
  uint uVar10;
  long lVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  long lVar17;
  
  lVar17 = *(long *)(param_1 + 0x58);
  lVar6 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + 0x18),2);
  if (lVar6 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: null device for macro!\n";
  }
  else {
    lVar11 = *(long *)(lVar6 + 0x98);
    if ((lVar11 != 0) && (*(long *)(lVar11 + 0x108) != 0)) {
      switch(*(uint *)(param_1 + 8)) {
      case 1:
      case 2:
        uVar16 = *(ulong *)(lVar11 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x118);
        uVar8 = (uVar16 & 0xaa) >> 1 | (uVar16 & 0x155) << 1;
        uVar1 = (uVar8 & 0xcccccccccccccccc) >> 2 | (uVar8 & 0x3333333333333333) << 2;
        uVar8 = 9;
        if ((uVar16 & 0x1ff) != 0) {
          uVar8 = LZCOUNT(((uVar1 & 0xf0f0f0f0f0f0f0f) >> 4 |
                          ((uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf000f000f000f) << 4) << 8)
                          << 0x30);
        }
        if ((uint)uVar8 < 9) {
          uVar12 = 1;
          uVar15 = 1 << (ulong)((uint)uVar8 & 0x1f);
          uVar10 = uVar15 & 0xffff;
          if (uVar8 < 8) {
            uVar14 = (uint)(-2L << (uVar8 & 0x3f)) & (uint)uVar16;
            uVar8 = ((ulong)uVar14 & 0xaa) >> 1 | ((ulong)uVar14 & 0x154) << 1;
            uVar8 = (uVar8 & 0xcccccccccccccccc) >> 2 | (uVar8 & 0x3333333333333333) << 2;
            uVar13 = 9;
            if ((uVar14 & 0x1fe) != 0) {
              uVar13 = (uint)LZCOUNT(((uVar8 & 0xf0f0f0f0f0f0f0f) >> 4 |
                                     ((uVar8 & 0xf0f0f0f0f0f0f0f0) >> 4 |
                                     (uVar8 & 0xf000f000f000f) << 4) << 8) << 0x30);
            }
            uVar12 = 1;
            if (uVar13 < 9) {
              uVar12 = 2;
              uVar10 = (uVar15 | 1 << (ulong)(uVar13 & 0x1f)) & 0xffff;
            }
          }
        }
        else {
          uVar10 = 0;
          uVar12 = 0;
        }
        if ((uVar10 & 0xc) != 0) {
          uVar10 = uVar10 >> 2;
        }
        *param_5 = uVar10;
        *param_4 = uVar12;
        return 0;
      case 3:
        uVar8 = *(ulong *)(lVar11 + 0x130);
        lVar6 = 2;
        if ((uVar8 & 3) != 0) {
          lVar6 = LZCOUNT(((uVar8 & 2) >> 1 | (uVar8 & 1) << 1) << 0x3e);
        }
        if ((uint)lVar6 < 2) {
          uVar15 = 1;
          uVar10 = 1 << (ulong)((uint)lVar6 & 0x1f);
          if (lVar6 == 0) {
            uVar14 = 2;
            if ((uVar8 & 2) != 0) {
              uVar14 = (uint)LZCOUNT(((uVar8 & 2) >> 1) << 0x3e);
            }
            uVar15 = 1;
            if (uVar14 < 2) {
              uVar15 = 2;
              uVar10 = 1 << (ulong)(uVar14 & 0x1f) | 1;
            }
          }
        }
        else {
          uVar10 = 0;
          uVar15 = 0;
        }
        *param_3 = uVar10;
        *param_2 = uVar15;
        return 0;
      case 4:
        uVar8 = snd_soc_component_read(lVar17,0x2110);
        bVar3 = (uVar8 & 0x18) != 0;
        uVar10 = 1;
        if (bVar3) {
          uVar10 = 2;
        }
        bVar4 = (uVar8 & 3) != 0;
        uVar15 = (uint)bVar3;
        if (!bVar4) {
          uVar10 = uVar15;
        }
        *param_3 = (uint)bVar4 | uVar15 << 1;
        *param_2 = uVar10;
        return 0;
      case 5:
        goto switchD_00106748_caseD_5;
      default:
        uVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_channel_map__rs,
                             "lpass_cdc_wsa_macro_get_channel_map");
        if ((int)uVar7 == 0) {
          return uVar7;
        }
        _dev_err(lVar6,"%s: Invalid AIF\n","lpass_cdc_wsa_macro_get_channel_map");
        return 0;
      }
    }
    iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar17 + 0x18),pcVar9,"lpass_cdc_wsa_macro_get_channel_map");
  return 0xffffffea;
switchD_00106748_caseD_5:
  *param_3 = (uint)*(undefined8 *)(lVar11 + 0x140);
  if (5 < *(uint *)(param_1 + 8)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106974);
    (*pcVar2)();
  }
  *param_2 = (uint)*(undefined8 *)(lVar11 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x148);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_mute_stream @ 00106978 size=964
// signature: undefined lpass_cdc_wsa_macro_mute_stream(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_mute_stream(long param_1,int param_2)

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
    lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + 0x18),2);
    if (lVar5 == 0) {
      iVar3 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
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
            snd_soc_component_update_bits(uVar4,0x2400,0x10,0);
            snd_soc_component_update_bits(uVar4,0x2418,0x10,0);
            snd_soc_component_update_bits(uVar4,0x2480,0x10,0);
            snd_soc_component_update_bits(uVar4,0x2498,0x10,0);
          }
          lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + 0x18),2);
          if (lVar5 == 0) {
            iVar3 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
            if (iVar3 != 0) {
              pcVar6 = "%s: null device for macro!\n";
LAB_00106d24:
              _dev_err(*(undefined8 *)(lVar8 + 0x18),pcVar6,
                       "lpass_cdc_wsa_macro_enable_vi_decimator");
            }
          }
          else {
            lVar5 = *(long *)(lVar5 + 0x98);
            if ((lVar5 == 0) || (*(long *)(lVar5 + 0x108) == 0)) {
              iVar3 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,
                                   "lpass_cdc_wsa_macro_get_data");
              if (iVar3 != 0) {
                pcVar6 = "%s: priv is null for macro!\n";
                goto LAB_00106d24;
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
                snd_soc_component_update_bits((ulong)(iVar1 == 24000) << 1,lVar8,0x2244,0x20,0x20);
                snd_soc_component_update_bits(lVar8,0x2264,0x20,0x20);
                usleep_range_state(1000,0x5dc,2);
                snd_soc_component_update_bits(lVar8,0x2244,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x2264,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x2244,0x10,0x10);
                snd_soc_component_update_bits(lVar8,0x2264,0x10,0x10);
                usleep_range_state(1000,0x5dc,2);
                snd_soc_component_update_bits(lVar8,0x2244,0x20,0);
                snd_soc_component_update_bits(lVar8,0x2264,0x20,0);
              }
              if (((uint)*(undefined8 *)(lVar5 + 0x130) >> 1 & 1) != 0) {
                snd_soc_component_update_bits(lVar8,0x2284,0x20,0x20);
                snd_soc_component_update_bits(lVar8,0x22a4,0x20,0x20);
                usleep_range_state(1000,0x5dc,2);
                snd_soc_component_update_bits(lVar8,0x2284,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x22a4,0xf,iVar3);
                snd_soc_component_update_bits(lVar8,0x2284,0x10,0x10);
                snd_soc_component_update_bits(lVar8,0x22a4,0x10,0x10);
                usleep_range_state(1000,0x5dc,2);
                snd_soc_component_update_bits(lVar8,0x2284,0x20,0);
                snd_soc_component_update_bits(lVar8,0x22a4,0x20,0);
              }
            }
          }
          uVar7 = *(uint *)(param_1 + 8);
        }
        if (6 < uVar7) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106d3c);
          (*pcVar2)();
        }
        lVar5 = lVar9 + (ulong)uVar7 * 8;
        if ((((uint)*(undefined8 *)(lVar5 + 0x118) >> 4 & 1) != 0) ||
           (((uint)*(undefined8 *)(lVar5 + 0x118) >> 5 & 1) != 0)) {
          if (*(long *)(lVar9 + 0x298) == 0) {
            return 0;
          }
          uVar4 = readl();
          if ((int)uVar4 == 0) {
            return uVar4;
          }
          writel(uVar4,*(undefined8 *)(lVar9 + 0x298));
        }
        goto LAB_00106994;
      }
      iVar3 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      pcVar6 = "%s: priv is null for macro!\n";
    }
    _dev_err(*(undefined8 *)(lVar8 + 0x18),pcVar6,"lpass_cdc_wsa_macro_mute_stream");
    uVar4 = 0xffffffea;
  }
  else {
LAB_00106994:
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_hw_params @ 00106d40 size=1900
// signature: undefined lpass_cdc_wsa_macro_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_hw_params(long param_1,long param_2,long param_3)

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
  lVar9 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar17 + 0x18),2);
  if (lVar9 == 0) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: null device for macro!\n";
LAB_00106fd8:
    _dev_err(*(undefined8 *)(lVar17 + 0x18),pcVar10,"lpass_cdc_wsa_macro_hw_params");
    return 0xffffffea;
  }
  lVar9 = *(long *)(lVar9 + 0x98);
  if ((lVar9 == 0) || (*(long *)(lVar9 + 0x108) == 0)) {
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    pcVar10 = "%s: priv is null for macro!\n";
    goto LAB_00106fd8;
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
        goto LAB_00106f90;
      }
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
LAB_00106f90:
      uVar14 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
      uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
      uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
      uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
      uVar4 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10) | uVar4;
    }
    iVar7 = snd_pcm_format_width(uVar4);
    if (iVar7 == 0x20) {
LAB_001073a8:
      if (*(uint *)(param_3 + 8) < 6) {
        lVar9 = lVar9 + (ulong)*(uint *)(param_3 + 8) * 2;
        uVar12 = 0x20;
LAB_001073d4:
        *(undefined2 *)(lVar9 + 0x178) = uVar12;
        return 0;
      }
      goto LAB_001074a8;
    }
    if (iVar7 == 0x18) {
LAB_001073c0:
      if (*(uint *)(param_3 + 8) < 6) {
        lVar9 = lVar9 + (ulong)*(uint *)(param_3 + 8) * 2;
        uVar12 = 0x18;
        goto LAB_001073d4;
      }
      goto LAB_001074a8;
    }
    if (iVar7 == 0x10) {
      uVar14 = *(uint *)(param_3 + 8);
joined_r0x00106fc0:
      if (uVar14 < 6) {
        lVar9 = lVar9 + (ulong)uVar14 * 2;
        uVar12 = 0x10;
        goto LAB_001073d4;
      }
      goto LAB_001074a8;
    }
    iVar7 = ___ratelimit(lpass_cdc_wsa_macro_hw_params__rs_247,"lpass_cdc_wsa_macro_hw_params");
    if (iVar7 == 0) {
      return 0xffffffea;
    }
    uVar14 = *(uint *)(param_2 + 0x24);
    uVar15 = *(undefined8 *)(lVar17 + 0x18);
    if (uVar14 == 0) {
      uVar14 = *(uint *)(param_2 + 0x28);
joined_r0x00107014:
      if (uVar14 != 0) {
        uVar4 = 0x20;
        goto LAB_00107458;
      }
      uVar4 = 0;
    }
    else {
LAB_00107454:
      uVar4 = 0;
LAB_00107458:
      uVar14 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
      uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
      uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
      uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
      uVar4 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10) | uVar4;
    }
    uVar8 = snd_pcm_format_width(uVar4);
    pcVar10 = "%s: Invalid format 0x%x\n";
    goto LAB_00107480;
  }
  if (*(int *)(param_1 + 0x3c) != 0) {
    return 0;
  }
  iVar7 = *(int *)(param_2 + 0x128);
  if (iVar7 == 48000) {
    lVar11 = 0;
LAB_00106db8:
    lVar16 = *(long *)(param_3 + 0x58);
    uVar2 = int_mix_sample_rate_val[lVar11 * 8 + 4];
    lVar11 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + 0x18),2);
    if (lVar11 == 0) {
      iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
      if (iVar5 != 0) {
        pcVar10 = "%s: null device for macro!\n";
LAB_00107440:
        _dev_err(*(undefined8 *)(lVar16 + 0x18),pcVar10,
                 "lpass_cdc_wsa_macro_set_mix_interpolator_rate");
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
LAB_00107144:
              if (iVar7 < 24000) {
                if (iVar7 == 8000) goto LAB_00107174;
                if (iVar7 == 16000) goto LAB_0010716c;
                goto LAB_0010705c;
              }
              if (iVar7 == 24000) goto LAB_0010731c;
              if (iVar7 == 32000) goto LAB_00107198;
              goto LAB_0010705c;
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
            if (8 < uVar14) goto LAB_00107144;
            if (3 < uVar14) {
              iVar5 = ___ratelimit(lpass_cdc_wsa_macro_set_mix_interpolator_rate__rs,
                                   "lpass_cdc_wsa_macro_set_mix_interpolator_rate");
              if (iVar5 != 0) {
                _dev_err(lVar11,"%s: Invalid RX port, Dai ID is %d\n",
                         "lpass_cdc_wsa_macro_set_mix_interpolator_rate",
                         *(undefined4 *)(param_3 + 8));
              }
              goto LAB_00107144;
            }
            uVar4 = snd_soc_component_read(lVar16,0x2104);
            if ((uVar4 & 7) == uVar14 + 1) {
              snd_soc_component_update_bits(lVar16,0x2418,0xf,uVar2);
            }
            uVar4 = snd_soc_component_read(lVar16,0x210c);
            if ((uVar4 & 7) == uVar14 + 1) {
              snd_soc_component_update_bits(lVar16,0x2498,0xf,uVar2);
            }
            uVar14 = *(uint *)(param_3 + 8);
            uVar13 = lVar1 + 1;
          } while (uVar14 < 7);
        }
        goto LAB_001074a8;
      }
      iVar5 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
      if (iVar5 != 0) {
        pcVar10 = "%s: priv is null for macro!\n";
        goto LAB_00107440;
      }
    }
LAB_0010705c:
    if (iVar7 == 48000) {
      lVar11 = 4;
    }
    else if (iVar7 < 0x2ee00) {
      if (iVar7 == 0xac44) {
LAB_00107124:
        lVar11 = 8;
      }
      else {
        if (iVar7 != 96000) goto LAB_0010731c;
        lVar11 = 5;
      }
    }
    else {
      if (iVar7 != 0x2ee00) {
        if (iVar7 == 0x5dc00) goto LAB_0010711c;
        goto LAB_0010731c;
      }
      lVar11 = 6;
    }
LAB_001071a4:
    lVar16 = *(long *)(param_3 + 0x58);
    uVar2 = int_prim_sample_rate_val[lVar11 * 8 + 4];
    lVar11 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + 0x18),2);
    if (lVar11 == 0) {
      iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs,"lpass_cdc_wsa_macro_get_data");
      if (iVar7 != 0) {
        pcVar10 = "%s: null device for macro!\n";
        goto LAB_00107424;
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
LAB_00107350:
              uVar14 = *(uint *)(param_2 + 0x24);
              if (uVar14 == 0) {
                uVar14 = *(uint *)(param_2 + 0x28);
                if (uVar14 != 0) {
                  uVar4 = 0x20;
                  goto LAB_00107370;
                }
                uVar4 = 0;
              }
              else {
                uVar4 = 0;
LAB_00107370:
                uVar14 = (uVar14 & 0xaaaaaaaa) >> 1 | (uVar14 & 0x55555555) << 1;
                uVar14 = (uVar14 & 0xcccccccc) >> 2 | (uVar14 & 0x33333333) << 2;
                uVar14 = (uVar14 & 0xf0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f) << 4;
                uVar14 = (uVar14 & 0xff00ff00) >> 8 | (uVar14 & 0xff00ff) << 8;
                uVar4 = (uint)LZCOUNT(uVar14 >> 0x10 | uVar14 << 0x10) | uVar4;
              }
              iVar7 = snd_pcm_format_width(uVar4);
              if (iVar7 == 0x20) goto LAB_001073a8;
              if (iVar7 == 0x18) goto LAB_001073c0;
              if (iVar7 == 0x10) {
                uVar14 = *(uint *)(param_3 + 8);
                goto joined_r0x00106fc0;
              }
              iVar7 = ___ratelimit(lpass_cdc_wsa_macro_hw_params__rs_245,
                                   "lpass_cdc_wsa_macro_hw_params");
              if (iVar7 == 0) {
                return 0xffffffea;
              }
              uVar14 = *(uint *)(param_2 + 0x24);
              uVar15 = *(undefined8 *)(lVar17 + 0x18);
              if (uVar14 != 0) goto LAB_00107454;
              uVar14 = *(uint *)(param_2 + 0x28);
              goto joined_r0x00107014;
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
            if (8 < (uint)lVar18) goto LAB_00107350;
            uVar14 = (uint)lVar18 + 1;
            uVar4 = snd_soc_component_read(lVar16,0x2100);
            uVar6 = snd_soc_component_read(lVar16,0x2104);
            if (((uVar4 & 7) == uVar14 || (uVar4 >> 3 & 7) == uVar14) || (uVar6 >> 3 & 7) == uVar14)
            {
              snd_soc_component_update_bits(lVar16,0x2400,0xf,uVar2);
            }
            uVar4 = snd_soc_component_read(lVar16,0x2108);
            uVar6 = snd_soc_component_read(lVar16,0x210c);
            if ((((uVar4 & 7) == uVar14) || ((uVar4 >> 3 & 7) == uVar14)) ||
               ((uVar6 >> 3 & 7) == uVar14)) {
              snd_soc_component_update_bits(lVar16,0x2480,0xf,uVar2);
            }
            uVar14 = *(uint *)(param_3 + 8);
            uVar13 = lVar18 + 1;
          } while (uVar14 < 7);
        }
LAB_001074a8:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1074ac);
        (*pcVar3)();
      }
      iVar7 = ___ratelimit(lpass_cdc_wsa_macro_get_data__rs_106,"lpass_cdc_wsa_macro_get_data");
      if (iVar7 != 0) {
        pcVar10 = "%s: priv is null for macro!\n";
LAB_00107424:
        _dev_err(*(undefined8 *)(lVar16 + 0x18),pcVar10,
                 "lpass_cdc_wsa_macro_set_prim_interpolator_rate");
      }
    }
  }
  else {
    if (iVar7 < 0xac44) {
      if (iVar7 == 8000) {
LAB_00107174:
        lVar11 = 0;
      }
      else if (iVar7 == 16000) {
LAB_0010716c:
        lVar11 = 1;
      }
      else {
        if (iVar7 != 32000) goto LAB_0010731c;
LAB_00107198:
        lVar11 = 3;
      }
      goto LAB_001071a4;
    }
    if (iVar7 < 0x2ee00) {
      if (iVar7 == 0xac44) goto LAB_00107124;
      if (iVar7 == 96000) {
        lVar11 = 1;
        goto LAB_00106db8;
      }
    }
    else {
      if (iVar7 == 0x5dc00) {
LAB_0010711c:
        lVar11 = 7;
        goto LAB_001071a4;
      }
      if (iVar7 == 0x2ee00) {
        lVar11 = 2;
        goto LAB_00106db8;
      }
    }
  }
LAB_0010731c:
  iVar7 = ___ratelimit(lpass_cdc_wsa_macro_hw_params__rs,"lpass_cdc_wsa_macro_hw_params");
  if (iVar7 == 0) {
    return 0xffffffea;
  }
  uVar15 = *(undefined8 *)(lVar17 + 0x18);
  pcVar10 = "%s: cannot set sample rate: %u\n";
  uVar8 = *(undefined4 *)(param_2 + 0x128);
LAB_00107480:
  _dev_err(uVar15,pcVar10,"lpass_cdc_wsa_macro_hw_params",uVar8);
  return 0xffffffea;
}



//------------------------------------------------------------
// readl @ 001074ac size=140
// signature: undefined readl(void)
// callers: [lpass_cdc_wsa_macro_mute_stream]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x107504,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00107538 size=124
// signature: undefined writel(void)
// callers: [lpass_cdc_wsa_macro_mute_stream]
//------------------------------------------------------------

void writel(undefined8 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(0,0x20,param_2,writel,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = 0;
  log_post_write_mmio(0,0x20,param_2,0x107588,uVar1);
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa_macro_get_max_state @ 001075b8 size=100
// signature: undefined lpass_cdc_wsa_macro_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_get_max_state(long param_1,ulong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x3b0) == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_max_state__rs,"lpass_cdc_wsa_macro_get_max_state");
    if (iVar1 != 0) {
      _printk(&DAT_0011b163,"lpass_cdc_wsa_macro_get_max_state");
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
// lpass_cdc_wsa_macro_get_cur_state @ 00107620 size=100
// signature: undefined lpass_cdc_wsa_macro_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_wsa_macro_get_cur_state(long param_1,ulong *param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x3b0) == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_get_cur_state__rs,"lpass_cdc_wsa_macro_get_cur_state");
    if (iVar1 != 0) {
      _printk(&DAT_0011b163,"lpass_cdc_wsa_macro_get_cur_state");
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
// lpass_cdc_wsa_macro_set_cur_state @ 00107688 size=204
// signature: undefined lpass_cdc_wsa_macro_set_cur_state(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 lpass_cdc_wsa_macro_set_cur_state(long param_1,ulong param_2)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x3b0);
  if ((plVar2 == (long *)0x0) || (*plVar2 == 0)) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_set_cur_state__rs,"lpass_cdc_wsa_macro_set_cur_state");
    if (iVar1 != 0) {
      _printk(&DAT_0011b163,"lpass_cdc_wsa_macro_set_cur_state");
    }
  }
  else {
    if (param_2 <= *(uint *)((long)plVar2 + 0x22c)) {
      *(int *)(plVar2 + 0x45) = (int)param_2;
      queue_work_on(0x20,_system_wq,plVar2 + 0x46);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_macro_set_cur_state__rs_251,
                         "lpass_cdc_wsa_macro_set_cur_state");
    if (iVar1 != 0) {
      _dev_err(*plVar2,"%s: incorrect requested state:%d\n","lpass_cdc_wsa_macro_set_cur_state",
               param_2);
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// init_module @ 0010775c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpass_cdc_wsa_macro_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010778c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpass_cdc_wsa_macro_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0011d000 size=1
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
// platform_driver_unregister @ 0011d008 size=1
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
// lpass_cdc_is_va_macro_registered @ 0011d010 size=1
// signature: undefined lpass_cdc_is_va_macro_registered(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_is_va_macro_registered(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0011d018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0011d020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0011d028 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011d030 size=1
// signature: undefined of_find_property(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0011d038 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0011d040 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_set_wakeup_capable @ 0011d048 size=1
// signature: undefined msm_cdc_pinctrl_set_wakeup_capable(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011d050 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_register_macro @ 0011d058 size=1
// signature: undefined lpass_cdc_register_macro(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_register_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_cooling_device_register @ 0011d060 size=1
// signature: undefined devm_thermal_of_cooling_device_register(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0011d068 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa_macro_soft_clip_enable_get, lpass_cdc_wsa_macro_set_port_map, lpass_cdc_wsa_macro_event_handler, lpass_cdc_wsa_macro_pbr_enable_put, lpass_cdc_wsa_macro_disable_vi_feedback, lpass_cdc_wsa_macro_config_compander, lpass_cdc_wsa_macro_enable_prim_interpolator, lpass_cdc_wsa_macro_mclk_enable, lpass_cdc_wsa_macro_set_digital_volume, lpass_cdc_wsa_macro_get_channel_map, lpass_cdc_wsa_macro_ear_spkrrecv_put, lpass_cdc_wsa_macro_rx_mux_get, lpass_cdc_wsa_macro_enable_echo, lpass_cdc_wsa_macro_ear_spkrrecv_get, lpass_cdc_wsa_macro_enable_main_path, lpass_cdc_wsa_macro_vi_feed_mixer_put, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_spk_boost_event, lpass_cdc_wsa_macro_cooling_adjust_gain, lpass_cdc_wsa_macro_cps_feed_mixer_get, lpass_cdc_wsa_macro_get_compander, lpass_cdc_wsa_macro_set_ec_hq, lpass_cdc_wsa_macro_comp_mode_get, lpass_cdc_wsa_macro_set_compander, lpass_cdc_wsa_macro_soft_clip_enable_put, lpass_cdc_wsa_macro_enable_vbat, lpass_cdc_wsa_macro_cps_feed_mixer_put, lpass_cdc_wsa_macro_vi_feed_mixer_get, lpass_cdc_wsa_macro_idle_detect_get, lpass_cdc_wsa_macro_enable_mix_path, lpass_cdc_wsa_macro_deinit, lpass_cdc_wsa_macro_probe, lpass_cdc_wsa_macro_hw_params, lpass_cdc_wsa_macro_init, lpass_cdc_wsa_macro_idle_detect_put, lpass_cdc_wsa_macro_rx_mux_put, wsa_swrm_clock, lpass_cdc_wsa_macro_mute_stream, lpass_cdc_wsa_macro_get_ec_hq, lpass_cdc_wsa_macro_config_softclip, lpass_cdc_wsa_macro_comp_mode_put, lpass_cdc_wsa_macro_set_cur_state, lpass_cdc_wsa_macro_pbr_enable_get, lpass_cdc_wsa_macro_mclk_event, lpass_cdc_wsa_macro_add_child_devices, lpass_cdc_wsa_macro_enable_swr, lpass_cdc_wsa_macro_get_rx_mute_status, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0011d070 size=1
// signature: undefined _dev_info(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0011d078 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0011d080 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0011d088 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpass_cdc_wsa_macro_remove, lpass_cdc_wsa_macro_probe, lpass_cdc_wsa_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0011d090 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpass_cdc_wsa_macro_probe, lpass_cdc_wsa_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0011d0a0 size=1
// signature: undefined queue_work_on(void)
// callers: [lpass_cdc_wsa_macro_set_cur_state, lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011d0a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices, lpass_cdc_wsa_macro_set_port_map, lpass_cdc_wsa_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 0011d0b0 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [lpass_cdc_wsa_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 0011d0b8 size=1
// signature: undefined platform_device_unregister(void)
// callers: [lpass_cdc_wsa_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0011d0c0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpass_cdc_wsa_macro_remove, lpass_cdc_wsa_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_unregister_macro @ 0011d0c8 size=1
// signature: undefined lpass_cdc_unregister_macro(void)
// callers: [lpass_cdc_wsa_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_unregister_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0011d0d0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0011d0d8 size=1
// signature: undefined strnstr(void)
// callers: [lpass_cdc_wsa_macro_comp_mode_get, lpass_cdc_wsa_macro_add_child_devices, lpass_cdc_wsa_macro_enable_swr, lpass_cdc_wsa_macro_comp_mode_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0011d0e0 size=1
// signature: size_t strlen(char * __s)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0011d0e8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 0011d0f0 size=1
// signature: undefined platform_device_alloc(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add_data @ 0011d0f8 size=1
// signature: undefined platform_device_add_data(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 0011d100 size=1
// signature: undefined krealloc(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 0011d108 size=1
// signature: undefined platform_device_add(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011d110 size=1
// signature: undefined _printk(void)
// callers: [lpass_cdc_wsa_macro_get_max_state, lpass_cdc_wsa_macro_add_child_devices, lpass_cdc_wsa_macro_core_vote, lpass_cdc_wsa_macro_cooling_adjust_gain, lpass_cdc_wsa_macro_set_cur_state, lpass_cdc_wsa_macro_get_cur_state, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 0011d118 size=1
// signature: undefined platform_device_put(void)
// callers: [lpass_cdc_wsa_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0011d120 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_put, lpass_cdc_wsa_macro_mute_stream, lpass_cdc_wsa_macro_enable_echo, lpass_cdc_wsa_macro_enable_main_path, lpass_cdc_wsa_macro_config_softclip, lpass_cdc_wsa_macro_enable_vbat, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_spk_boost_event, lpass_cdc_wsa_macro_cooling_adjust_gain, lpass_cdc_wsa_macro_enable_mix_path, lpass_cdc_wsa_macro_hw_params, lpass_cdc_wsa_macro_init, lpass_cdc_wsa_macro_disable_vi_feedback, lpass_cdc_wsa_macro_config_compander, lpass_cdc_wsa_macro_enable_prim_interpolator, lpass_cdc_wsa_macro_set_digital_volume, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 0011d128 size=1
// signature: undefined dev_get_regmap(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011d130 size=1
// signature: undefined mutex_lock(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0011d138 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_core_vote, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0011d140 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa_macro_soft_clip_enable_get, lpass_cdc_wsa_macro_set_port_map, lpass_cdc_wsa_macro_event_handler, lpass_cdc_wsa_macro_pbr_enable_put, lpass_cdc_wsa_macro_disable_vi_feedback, lpass_cdc_wsa_macro_config_compander, lpass_cdc_wsa_macro_enable_prim_interpolator, lpass_cdc_wsa_macro_mclk_enable, lpass_cdc_wsa_macro_set_digital_volume, lpass_cdc_wsa_macro_get_channel_map, lpass_cdc_wsa_macro_ear_spkrrecv_put, lpass_cdc_wsa_macro_rx_mux_get, lpass_cdc_wsa_macro_enable_echo, lpass_cdc_wsa_macro_ear_spkrrecv_get, lpass_cdc_wsa_macro_enable_main_path, lpass_cdc_wsa_macro_vi_feed_mixer_put, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_spk_boost_event, lpass_cdc_wsa_macro_cps_feed_mixer_get, lpass_cdc_wsa_macro_get_compander, lpass_cdc_wsa_macro_set_ec_hq, lpass_cdc_wsa_macro_comp_mode_get, lpass_cdc_wsa_macro_set_compander, lpass_cdc_wsa_macro_get_max_state, lpass_cdc_wsa_macro_soft_clip_enable_put, lpass_cdc_wsa_macro_enable_vbat, lpass_cdc_wsa_macro_cps_feed_mixer_put, lpass_cdc_wsa_macro_vi_feed_mixer_get, lpass_cdc_wsa_macro_idle_detect_get, lpass_cdc_wsa_macro_enable_mix_path, lpass_cdc_wsa_macro_deinit, lpass_cdc_wsa_macro_hw_params, lpass_cdc_wsa_macro_init, lpass_cdc_wsa_macro_idle_detect_put, lpass_cdc_wsa_macro_rx_mux_put, wsa_swrm_clock, lpass_cdc_wsa_macro_mute_stream, lpass_cdc_wsa_macro_get_ec_hq, lpass_cdc_wsa_macro_config_softclip, lpass_cdc_wsa_macro_comp_mode_put, lpass_cdc_wsa_macro_set_cur_state, lpass_cdc_wsa_macro_pbr_enable_get, lpass_cdc_wsa_macro_get_cur_state, lpass_cdc_wsa_macro_mclk_event, lpass_cdc_wsa_macro_enable_swr, lpass_cdc_wsa_macro_core_vote, lpass_cdc_wsa_macro_get_rx_mute_status, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0011d148 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wsa_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0011d150 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0011d158 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wsa_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0011d160 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_core_vote, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0011d168 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_core_vote, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011d170 size=1
// signature: undefined mutex_unlock(void)
// callers: [wsa_swrm_clock, lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_check_core_votes @ 0011d178 size=1
// signature: undefined lpass_cdc_check_core_votes(void)
// callers: [lpass_cdc_wsa_macro_core_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_check_core_votes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_fs_gen_request @ 0011d180 size=1
// signature: undefined lpass_cdc_clk_rsc_fs_gen_request(void)
// callers: [lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_fs_gen_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_request_clock @ 0011d188 size=1
// signature: undefined lpass_cdc_clk_rsc_request_clock(void)
// callers: [lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_request_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0011d190 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync_region @ 0011d198 size=1
// signature: undefined regcache_sync_region(void)
// callers: [lpass_cdc_wsa_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_device_ptr @ 0011d1a0 size=1
// signature: undefined lpass_cdc_get_device_ptr(void)
// callers: [lpass_cdc_was_macro_config_pbr, lpass_cdc_wsa_macro_soft_clip_enable_put, lpass_cdc_wsa_macro_enable_vbat, lpass_cdc_wsa_macro_soft_clip_enable_get, lpass_cdc_wsa_macro_cps_feed_mixer_put, lpass_cdc_wsa_macro_vi_feed_mixer_get, lpass_cdc_wsa_macro_idle_detect_get, lpass_cdc_wsa_macro_set_port_map, lpass_cdc_wsa_macro_deinit, lpass_cdc_wsa_macro_event_handler, lpass_cdc_wsa_macro_hw_params, lpass_cdc_wsa_macro_pbr_enable_put, lpass_cdc_wsa_macro_init, lpass_cdc_wsa_macro_disable_vi_feedback, lpass_cdc_wsa_macro_config_compander, lpass_cdc_wsa_macro_enable_prim_interpolator, lpass_cdc_wsa_macro_idle_detect_put, lpass_cdc_wsa_macro_set_digital_volume, lpass_cdc_wsa_macro_get_channel_map, lpass_cdc_wsa_macro_ear_spkrrecv_put, lpass_cdc_wsa_macro_rx_mux_get, lpass_cdc_wsa_macro_rx_mux_put, lpass_cdc_wsa_macro_mute_stream, lpass_cdc_wsa_macro_enable_echo, lpass_cdc_wsa_macro_ear_spkrrecv_get, lpass_cdc_wsa_macro_get_ec_hq, lpass_cdc_wsa_macro_enable_main_path, lpass_cdc_wsa_macro_config_softclip, lpass_cdc_wsa_macro_vi_feed_mixer_put, lpass_cdc_wsa_macro_comp_mode_put, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_cps_feed_mixer_get, lpass_cdc_wsa_macro_pbr_enable_get, lpass_cdc_wsa_macro_get_compander, lpass_cdc_wsa_macro_set_ec_hq, lpass_cdc_wsa_macro_comp_mode_get, lpass_cdc_wsa_macro_mclk_event, lpass_cdc_wsa_macro_enable_swr, lpass_cdc_wsa_macro_set_compander, lpass_cdc_wsa_macro_get_rx_mute_status, lpass_cdc_wsa_macro_set_rx_mute_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_device_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 0011d1a8 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [lpass_cdc_wsa_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_version @ 0011d1b0 size=1
// signature: undefined lpass_cdc_get_version(void)
// callers: [lpass_cdc_wsa_macro_init, lpass_cdc_wsa_macro_enable_main_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 0011d1b8 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [lpass_cdc_wsa_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_widgets @ 0011d1c0 size=1
// signature: undefined snd_soc_dapm_new_widgets(void)
// callers: [lpass_cdc_wsa_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_widgets(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 0011d1c8 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [lpass_cdc_wsa_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0011d1d0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [lpass_cdc_wsa_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0011d1d8 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [lpass_cdc_wsa_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0011d1e0 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [lpass_cdc_wsa_macro_init, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_enable_mix_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swrm_wcd_notify @ 0011d1e8 size=1
// signature: undefined swrm_wcd_notify(void)
// callers: [lpass_cdc_wsa_macro_enable_swr, lpass_cdc_wsa_macro_set_port_map, lpass_cdc_wsa_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swrm_wcd_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_runtime_suspend @ 0011d1f0 size=1
// signature: undefined lpass_cdc_runtime_suspend(void)
// callers: [lpass_cdc_wsa_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_rsc_clk_reset @ 0011d1f8 size=1
// signature: undefined lpass_cdc_rsc_clk_reset(void)
// callers: [lpass_cdc_wsa_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_rsc_clk_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0011d200 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [lpass_cdc_wsa_macro_enable_echo, lpass_cdc_wsa_macro_enable_main_path, lpass_cdc_wsa_macro_enable_prim_interpolator, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_set_digital_volume, lpass_cdc_wsa_macro_get_channel_map, lpass_cdc_wsa_macro_vbat_bcl_gsm_mode_func_get, lpass_cdc_wsa_macro_enable_mix_path, lpass_cdc_wsa_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0011d208 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [lpass_cdc_wsa_macro_enable_echo, lpass_cdc_wsa_macro_enable_vbat, lpass_cdc_wsa_macro_enable_interpolator, lpass_cdc_wsa_macro_spk_boost_event, lpass_cdc_wsa_macro_enable_mix_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0011d210 size=1
// signature: undefined usleep_range_state(void)
// callers: [lpass_cdc_wsa_macro_mute_stream, lpass_cdc_wsa_macro_enable_main_path, lpass_cdc_wsa_macro_enable_mix_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_wsa_pa_on @ 0011d218 size=1
// signature: undefined lpass_cdc_wsa_pa_on(void)
// callers: [lpass_cdc_wsa_macro_mute_stream, lpass_cdc_wsa_macro_enable_main_path]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_wsa_pa_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_kcontrol_widget @ 0011d220 size=1
// signature: undefined snd_soc_dapm_kcontrol_widget(void)
// callers: [lpass_cdc_wsa_macro_rx_mux_put, lpass_cdc_wsa_macro_vi_feed_mixer_put, lpass_cdc_wsa_macro_cps_feed_mixer_put, lpass_cdc_wsa_macro_vi_feed_mixer_get, lpass_cdc_wsa_macro_cps_feed_mixer_get, lpass_cdc_wsa_macro_rx_mux_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_kcontrol_widget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mixer_update_power @ 0011d230 size=1
// signature: undefined snd_soc_dapm_mixer_update_power(void)
// callers: [lpass_cdc_wsa_macro_vi_feed_mixer_put, lpass_cdc_wsa_macro_cps_feed_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mixer_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mux_update_power @ 0011d238 size=1
// signature: undefined snd_soc_dapm_mux_update_power(void)
// callers: [lpass_cdc_wsa_macro_rx_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mux_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_update_compander_setting @ 0011d240 size=1
// signature: undefined lpass_cdc_update_compander_setting(void)
// callers: [lpass_cdc_wsa_macro_config_compander]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_update_compander_setting(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_put_volsw @ 0011d248 size=1
// signature: undefined snd_soc_put_volsw(void)
// callers: [lpass_cdc_wsa_macro_set_digital_volume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_put_volsw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 0011d250 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [lpass_cdc_wsa_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0011d258 size=1
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
// log_post_read_mmio @ 0011d260 size=1
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
// log_write_mmio @ 0011d268 size=1
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
// log_post_write_mmio @ 0011d270 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



