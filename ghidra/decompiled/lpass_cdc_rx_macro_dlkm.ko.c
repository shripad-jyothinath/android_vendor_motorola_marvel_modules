// Decompiled by Ghidra 12.2
// Program: lpass_cdc_rx_macro_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_cdc_rx_set_fir_capability @ 00100ddc size=184
// signature: undefined lpass_cdc_rx_set_fir_capability(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_set_fir_capability(long param_1,byte param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  if (param_1 == 0) {
    iVar2 = ___ratelimit(&lpass_cdc_rx_set_fir_capability__rs,"lpass_cdc_rx_set_fir_capability");
    if (iVar2 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_set_fir_capability");
    }
  }
  else {
    uVar3 = lpass_cdc_rx_macro_get_data
                      (param_1,auStack_30,&local_38,"lpass_cdc_rx_set_fir_capability");
    if ((uVar3 & 1) != 0) {
      uVar4 = 0;
      *(byte *)(local_38 + 0x6af) = param_2 & 1;
      goto LAB_00100e50;
    }
  }
  uVar4 = 0xffffffea;
LAB_00100e50:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_data @ 00100e94 size=224
// signature: undefined lpass_cdc_rx_macro_get_data(void)
// callers: [lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_put_pcm_path, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, lpass_cdc_rx_macro_hph_idle_detect_get, lpass_cdc_rx_macro_aux_hpf_mode_put, lpass_cdc_rx_macro_set_compander, lpass_cdc_rx_macro_get_pcm_path, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_aux_hpf_mode_get, lpass_cdc_rx_macro_mclk_event, lpass_cdc_rx_macro_put_hph_pwr_mode, lpass_cdc_rx_macro_get_compander, lpass_cdc_rx_macro_hph_idle_detect_put, lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_macro_set_port_map, lpass_cdc_rx_macro_get_hph_hd2_mode, lpass_cdc_rx_macro_get_hph_pwr_mode, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_get_channel_map, lpass_cdc_rx_macro_enable_echo, lpass_cdc_rx_macro_mux_get, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_soft_clip_enable_get, lpass_cdc_rx_macro_get_ear_mode, lpass_cdc_rx_set_fir_capability, lpass_cdc_rx_macro_mux_put, lpass_cdc_rx_macro_soft_clip_enable_put, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_iir_band_audio_mixer_put, lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_enable_vbat, lpass_cdc_rx_macro_fir_coeff_num_get, lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_fir_filter_enable_get, lpass_cdc_rx_macro_deinit, lpass_cdc_rx_macro_put_ear_mode, lpass_cdc_rx_macro_fir_coeff_num_put, lpass_cdc_rx_macro_put_hph_hd2_mode]
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_get_data(long param_1,long *param_2,long *param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  lVar1 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),1);
  *param_2 = lVar1;
  if (lVar1 == 0) {
    uVar2 = ___ratelimit(lpass_cdc_rx_macro_get_data__rs,"lpass_cdc_rx_macro_get_data");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar1 = *(long *)(lVar1 + 0x98);
    *param_3 = lVar1;
    if (lVar1 == 0) {
      uVar2 = ___ratelimit(lpass_cdc_rx_macro_get_data__rs_2,"lpass_cdc_rx_macro_get_data");
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      pcVar3 = "%s: priv is null for macro!\n";
    }
    else {
      if (*(long *)(lVar1 + 0x790) != 0) {
        return 1;
      }
      uVar2 = ___ratelimit(lpass_cdc_rx_macro_get_data__rs_4,"lpass_cdc_rx_macro_get_data");
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      pcVar3 = "%s: rx_priv component is not initialized!\n";
    }
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,param_4);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_probe @ 00100f78 size=1144
// signature: undefined lpass_cdc_rx_macro_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lpass_cdc_rx_macro_probe(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
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
  undefined8 uStack_a0;
  long local_98 [11];
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_98[10] = *(long *)(lVar6 + 0x638);
  local_a8 = 0;
  uStack_a0 = 0;
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
  uVar3 = lpass_cdc_is_va_macro_registered(lVar1);
  if ((uVar3 & 1) == 0) {
    pcVar9 = "%s: va-macro not registered yet, defer\n";
LAB_00101334:
    _dev_err(lVar1,pcVar9,"lpass_cdc_rx_macro_probe");
    iVar2 = -0x205;
  }
  else {
    plVar4 = (long *)devm_kmalloc(lVar1,0x948,0xdc0);
    if (plVar4 != (long *)0x0) {
      uVar5 = *(undefined8 *)(param_1 + 0x2f8);
      *(undefined1 *)((long)plVar4 + 0x6b1) = 1;
      *plVar4 = lVar1;
      iVar2 = of_property_read_variable_u32_array(uVar5,&DAT_00119f1e,(long)&local_110 + 4,1,0);
      if ((iVar2 < 0) ||
         (iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,rx_mclk_mode_muxsel",&local_110,
                             1,0), iVar2 < 0)) {
        _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_rx_macro_probe",
                 &DAT_00119f1e);
        goto LAB_00101374;
      }
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,default-clk-id",&local_114,1,0);
      if (iVar2 < 0) {
        _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_rx_macro_probe",
                 "qcom,default-clk-id");
        local_114 = 1;
      }
      lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,is-used-swr-gpio",0);
      if ((lVar6 != 0) &&
         (iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,is-used-swr-gpio",&local_118,1,0
                            ), iVar2 < 0)) {
        _dev_err(lVar1,"%s: error reading %s in dt\n","lpass_cdc_rx_macro_probe",
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
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,rx-swr-gpios",0,0,0,local_98);
      lVar6 = local_98[0];
      if (iVar2 != 0) {
        lVar6 = 0;
      }
      plVar4[0xf1] = lVar6;
      if ((lVar6 == 0) && (local_118 != 0)) {
        _dev_err(lVar1,"%s: swr_gpios handle not provided!\n","lpass_cdc_rx_macro_probe");
        iVar2 = -0x16;
        goto LAB_00101374;
      }
      iVar2 = msm_cdc_pinctrl_get_state(lVar6);
      if ((iVar2 < 0) && (local_118 != 0)) {
        pcVar9 = "%s: failed to get swr pin state\n";
        goto LAB_00101334;
      }
      msm_cdc_pinctrl_set_wakeup_capable(lVar6,0);
      lVar6 = devm_ioremap(lVar1,local_110._4_4_,0x1000);
      if (lVar6 == 0) {
        pcVar9 = "%s: ioremap failed\n";
      }
      else {
        plVar4[0x105] = lVar6;
        lVar7 = devm_ioremap(lVar1,local_110 & 0xffffffff,4);
        if (lVar7 != 0) {
          plVar4[0x106] = lVar7;
          plVar4[0xeb] = 0xfffffffe0;
          *(undefined1 *)((long)plVar4 + 0x49) = 1;
          plVar4[0xec] = (long)(plVar4 + 0xec);
          plVar4[0xed] = (long)(plVar4 + 0xec);
          plVar4[0xee] = (long)lpass_cdc_rx_macro_add_child_devices;
          plVar4[0xe4] = (long)plVar4;
          plVar4[0xe5] = 0;
          plVar4[0xe6] = 0;
          plVar4[0xe8] = (long)rx_swrm_clock;
          plVar4[0xe7] = 0;
          plVar4[0xea] = 0;
          plVar4[0xe9] = (long)lpass_cdc_rx_macro_core_vote;
          *(undefined2 *)((long)plVar4 + 0x934) = (undefined2)local_114;
          *(undefined2 *)((long)plVar4 + 0x936) = (undefined2)local_114;
          uVar8 = devm_clk_get(lVar1,"rx_mclk2_2x_clk");
          uVar3 = 0;
          if (uVar8 < 0xfffffffffffff001) {
            uVar3 = uVar8;
          }
          *(undefined4 *)(plVar4 + 0x125) = 1;
          plVar4[0x127] = uVar3;
          *(long **)(param_1 + 0xa8) = plVar4;
          __mutex_init(plVar4 + 0xd7,"&rx_priv->mclk_lock",&lpass_cdc_rx_macro_probe___key);
          __mutex_init(plVar4 + 0xdd,"&rx_priv->swr_clk_lock",&lpass_cdc_rx_macro_probe___key_21);
          local_b8 = 0;
          uStack_b0 = 0;
          local_108 = lpass_cdc_rx_macro_init;
          pcStack_100 = lpass_cdc_rx_macro_deinit;
          uStack_f0 = 0;
          uStack_a0 = 0;
          local_e8 = &lpass_cdc_rx_macro_dai;
          uStack_e0 = 0;
          local_f8 = 7;
          local_d8 = lpass_cdc_rx_macro_event_handler;
          uStack_d0 = 0;
          local_c8 = lpass_cdc_rx_macro_set_port_map;
          uStack_c0 = 0;
          local_a8 = lVar6;
          iVar2 = lpass_cdc_register_macro(lVar1,1,&local_108);
          if (iVar2 == 0) {
            pm_runtime_set_autosuspend_delay(lVar1,0x32);
            __pm_runtime_use_autosuspend(lVar1,1);
            __pm_runtime_set_status(lVar1,2);
            *(ushort *)(param_1 + 0x210) = *(ushort *)(param_1 + 0x210) | 0x100;
            pm_runtime_enable(lVar1);
            queue_work_on(0x20,_system_wq,plVar4 + 0xeb);
          }
          else {
            _dev_err(lVar1,"%s: register macro failed\n","lpass_cdc_rx_macro_probe");
          }
          goto LAB_00101374;
        }
        pcVar9 = "%s: ioremap failed for muxsel\n";
      }
      _dev_err(lVar1,pcVar9,"lpass_cdc_rx_macro_probe");
    }
    iVar2 = -0xc;
  }
LAB_00101374:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_remove @ 001013f4 size=160
// signature: undefined lpass_cdc_rx_macro_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    param_1 = param_1 + 0x10;
    if (0 < *(int *)(lVar2 + 0x920)) {
      platform_device_unregister(*(undefined8 *)(lVar2 + 0x908));
      if (1 < *(int *)(lVar2 + 0x920)) {
        platform_device_unregister(*(undefined8 *)(lVar2 + 0x910));
        if (2 < *(int *)(lVar2 + 0x920)) {
          platform_device_unregister(*(undefined8 *)(lVar2 + 0x918));
        }
      }
    }
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    lpass_cdc_unregister_macro(param_1,1);
    kfree(*(undefined8 *)(lVar2 + 0x718));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_add_child_devices @ 00101498 size=724
// signature: undefined lpass_cdc_rx_macro_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_add_child_devices(long param_1)

{
  ulong uVar1;
  uint uVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  long lVar8;
  size_t __n;
  long lVar9;
  undefined *puVar10;
  char *pcVar11;
  undefined5 *puVar12;
  long lVar13;
  ulong uVar14;
  ushort uVar15;
  undefined7 local_b8;
  undefined4 uStack_b1;
  undefined5 local_ad;
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
  plVar3 = (long *)(param_1 + -0x758);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b1 = 0;
  local_ad = 0;
  if (plVar3 == (long *)0x0) {
    puVar10 = &DAT_0011a23f;
  }
  else {
    lVar6 = *plVar3;
    if (lVar6 != 0) {
      if (*(long *)(lVar6 + 0x2e8) == 0) {
        pcVar11 = "%s: DT node for RX dev does not exist\n";
LAB_0010168c:
        _dev_err(lVar6,pcVar11,"lpass_cdc_rx_macro_add_child_devices");
      }
      else {
        *(undefined4 *)(param_1 + 0x1c8) = 0;
        puVar7 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar6 + 0x2e8),0);
        if (puVar7 != (undefined8 *)0x0) {
          lVar13 = 0;
          uVar15 = 0;
          do {
            lVar8 = strnstr(*puVar7,"rx_swr_master",0xd);
            if (lVar8 == 0) {
              pcVar11 = (char *)*puVar7;
              __n = strlen(pcVar11);
              if (0x4d < __n) {
                __n = 0x4e;
              }
              memcpy(&local_b8,pcVar11,__n);
              puVar12 = (undefined5 *)((long)&local_b8 + __n);
            }
            else {
              local_b8 = s_rx_swr_ctrl_00119c98._0_7_;
              uStack_b1 = CONCAT31(0x6c7274,s_rx_swr_ctrl_00119c98[7]);
              puVar12 = &local_ad;
            }
            *(undefined1 *)puVar12 = 0;
            lVar9 = platform_device_alloc(&local_b8,0xffffffff);
            lVar6 = *plVar3;
            if (lVar9 == 0) {
              pcVar11 = "%s: pdev memory alloc failed\n";
              goto LAB_0010168c;
            }
            *(long *)(lVar9 + 0x70) = lVar6;
            *(undefined8 **)(lVar9 + 0x2f8) = puVar7;
            if (lVar8 != 0) {
              iVar5 = platform_device_add_data(lVar9,param_1 + -0x38,0x38);
              if (iVar5 == 0) {
                uVar14 = (ulong)uVar15;
                uVar1 = uVar14 * 8 + 8;
                lVar13 = krealloc(lVar13,uVar1,0xcc0);
                if (lVar13 != 0) {
                  if ((uVar1 < uVar14 * 8) || (uVar1 + uVar14 * -8 < 8)) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(1,0x101768);
                    (*pcVar4)();
                  }
                  uVar15 = uVar15 + 1;
                  *(long *)(lVar13 + uVar14 * 8) = lVar9;
                  *(long *)(param_1 + -0x40) = lVar13;
                  goto LAB_00101618;
                }
              }
              else {
                _dev_err(lVar9 + 0x10,"%s: cannot add plat data ctrl:%d\n",
                         "lpass_cdc_rx_macro_add_child_devices",uVar15);
              }
LAB_001016e0:
              if ((((0 < *(int *)(param_1 + 0x1c8)) &&
                   (platform_device_put(*(undefined8 *)(param_1 + 0x1b0)),
                   1 < *(int *)(param_1 + 0x1c8))) &&
                  (platform_device_put(*(undefined8 *)(param_1 + 0x1b8)),
                  2 < *(int *)(param_1 + 0x1c8))) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0x1c0)),
                 3 < *(int *)(param_1 + 0x1c8))) {
LAB_00101760:
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101764);
                (*pcVar4)();
              }
              break;
            }
LAB_00101618:
            iVar5 = platform_device_add(lVar9);
            if (iVar5 != 0) {
              _dev_err(lVar9 + 0x10,"%s: Cannot add platform device\n",
                       "lpass_cdc_rx_macro_add_child_devices");
              goto LAB_001016e0;
            }
            uVar2 = *(uint *)(param_1 + 0x1c8);
            if (2 < (int)uVar2) break;
            *(uint *)(param_1 + 0x1c8) = uVar2 + 1;
            if (2 < uVar2) goto LAB_00101760;
            lVar6 = *plVar3;
            *(long *)(param_1 + 0x1b0 + (ulong)uVar2 * 8) = lVar9;
            puVar7 = (undefined8 *)
                     of_get_next_available_child(*(undefined8 *)(lVar6 + 0x2e8),puVar7);
          } while (puVar7 != (undefined8 *)0x0);
        }
      }
      goto LAB_00101728;
    }
    puVar10 = &DAT_0011a3f4;
  }
  _printk(puVar10,"lpass_cdc_rx_macro_add_child_devices");
LAB_00101728:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rx_swrm_clock @ 00101770 size=716
// signature: undefined rx_swrm_clock(void)
// callers: []
//------------------------------------------------------------

int rx_swrm_clock(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(rx_swrm_clock__rs,"rx_swrm_clock");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","rx_swrm_clock");
    return -0x16;
  }
  mutex_lock(param_1 + 0xdd);
  if ((param_2 & 1) == 0) {
    if (*(int *)((long)param_1 + 0x44) < 1) {
      iVar1 = ___ratelimit(rx_swrm_clock__rs_38,"rx_swrm_clock");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: rx swrm clock users already reset\n","rx_swrm_clock");
      }
      iVar1 = 0;
      *(undefined4 *)((long)param_1 + 0x44) = 0;
    }
    else {
      iVar1 = *(int *)((long)param_1 + 0x44) + -1;
      *(int *)((long)param_1 + 0x44) = iVar1;
      if (iVar1 == 0) {
        regmap_update_bits_base(lVar3,0x1108,1,0,0,0,0);
        lpass_cdc_rx_macro_mclk_enable(param_1,0);
        iVar1 = msm_cdc_pinctrl_select_sleep_state(param_1[0xf1]);
        if ((iVar1 < 0) && (iVar2 = ___ratelimit(rx_swrm_clock__rs_40,"rx_swrm_clock"), iVar2 != 0))
        {
          _dev_err(*param_1,"%s: rx swr pinctrl disable failed\n","rx_swrm_clock");
        }
      }
      else {
        iVar1 = 0;
      }
    }
    goto LAB_001019c4;
  }
  __pm_runtime_resume(*param_1,4);
  if (*(int *)((long)param_1 + 0x44) == 0) {
    iVar1 = msm_cdc_pinctrl_select_active_state(param_1[0xf1]);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(rx_swrm_clock__rs_34,"rx_swrm_clock");
      if (iVar2 != 0) {
        lVar3 = *param_1;
        pcVar5 = "%s: rx swr pinctrl enable failed\n";
LAB_00101a2c:
        _dev_err(lVar3,pcVar5,"rx_swrm_clock");
      }
    }
    else {
      iVar1 = lpass_cdc_rx_macro_mclk_enable(param_1,1);
      if (-1 < iVar1) {
        if (*(char *)((long)param_1 + 0x49) != '\0') {
          regmap_update_bits_base(lVar3,0x1108,2,2,0,0,0);
        }
        regmap_update_bits_base(lVar3,0x1108,1,1,0,0,0);
        if (*(char *)((long)param_1 + 0x49) != '\0') {
          regmap_update_bits_base(lVar3,0x1108,2,0,0,0,0);
        }
        *(undefined1 *)((long)param_1 + 0x49) = 0;
        goto LAB_001017cc;
      }
      msm_cdc_pinctrl_select_sleep_state(param_1[0xf1]);
      iVar2 = ___ratelimit(rx_swrm_clock__rs_36,"rx_swrm_clock");
      if (iVar2 != 0) {
        lVar3 = *param_1;
        pcVar5 = "%s: rx request clock enable failed\n";
        goto LAB_00101a2c;
      }
    }
    lVar3 = *param_1;
    uVar4 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar3 + 0x220) = uVar4;
    __pm_runtime_suspend(*param_1,0xd);
  }
  else {
    iVar1 = 0;
LAB_001017cc:
    lVar3 = *param_1;
    uVar4 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar3 + 0x220) = uVar4;
    __pm_runtime_suspend(*param_1,0xd);
    *(int *)((long)param_1 + 0x44) = *(int *)((long)param_1 + 0x44) + 1;
  }
LAB_001019c4:
  mutex_unlock(param_1 + 0xdd);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_core_vote @ 00101a40 size=180
// signature: undefined lpass_cdc_rx_macro_core_vote(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_rx_macro_core_vote(long *param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long lVar5;
  
  if (param_1 == (long *)0x0) {
    iVar1 = ___ratelimit(lpass_cdc_rx_macro_core_vote__rs,"lpass_cdc_rx_macro_core_vote");
    if (iVar1 != 0) {
      _printk(&DAT_0011a61f,"lpass_cdc_rx_macro_core_vote");
      return 0xffffffea;
    }
  }
  else if ((*(char *)((long)param_1 + 0x6b1) != '\0') || ((param_2 & 1) == 0)) {
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
// lpass_cdc_rx_macro_mclk_enable @ 00101af4 size=1128
// signature: undefined lpass_cdc_rx_macro_mclk_enable(void)
// callers: [lpass_cdc_rx_macro_mclk_event, set_fir_filter_coeff, rx_swrm_clock]
//------------------------------------------------------------

int lpass_cdc_rx_macro_mclk_enable(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_rx_macro_mclk_enable__rs,"lpass_cdc_rx_macro_mclk_enable");
    if (iVar2 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","lpass_cdc_rx_macro_mclk_enable");
    return -0x16;
  }
  mutex_lock(param_1 + 0xd7);
  iVar2 = (int)param_1[8];
  if ((param_2 & 1) == 0) {
    if (iVar2 < 1) {
      iVar2 = ___ratelimit(lpass_cdc_rx_macro_mclk_enable__rs_45,"lpass_cdc_rx_macro_mclk_enable");
      if (iVar2 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","lpass_cdc_rx_macro_mclk_enable");
      }
      iVar1 = 0;
      *(undefined4 *)(param_1 + 8) = 0;
      goto LAB_00101e8c;
    }
    *(int *)(param_1 + 8) = iVar2 + -1;
    if (iVar2 + -1 != 0) {
      iVar1 = 0;
      goto LAB_00101e8c;
    }
    regmap_update_bits_base(lVar3,0x1104,1,0,0,0,0);
    regmap_update_bits_base(lVar3,0x1104,2,2,0,0,0);
    regmap_update_bits_base(lVar3,0x1100,2,0,0,0,0);
    regmap_update_bits_base(lVar3,0x1100,1,0,0,0,0);
    lpass_cdc_clk_rsc_fs_gen_request(*param_1,0);
    if (param_1 == (long *)0x0) {
      iVar2 = ___ratelimit(lpass_cdc_rx_macro_core_vote__rs,"lpass_cdc_rx_macro_core_vote");
      if (iVar2 != 0) {
        _printk(&DAT_0011a61f,"lpass_cdc_rx_macro_core_vote");
      }
LAB_00101db8:
      iVar1 = -0x16;
LAB_00101e1c:
      iVar2 = ___ratelimit(lpass_cdc_rx_macro_mclk_enable__rs_47,"lpass_cdc_rx_macro_mclk_enable");
      if (iVar2 != 0) {
        _dev_err(*param_1,"%s: rx request core vote failed\n","lpass_cdc_rx_macro_mclk_enable");
      }
    }
    else {
      if (*(char *)((long)param_1 + 0x6b1) == '\0') goto LAB_00101db8;
      __pm_runtime_resume(*param_1,4);
      uVar4 = lpass_cdc_check_core_votes(*param_1);
      if ((uVar4 & 1) == 0) {
        iVar1 = -0x20a;
        goto LAB_00101e1c;
      }
      iVar1 = 0;
    }
    lpass_cdc_clk_rsc_request_clock
              (*param_1,*(undefined2 *)((long)param_1 + 0x936),
               *(undefined2 *)((long)param_1 + 0x934),0);
    if (iVar1 == 0) {
      if (param_1 == (long *)0x0) {
        iVar2 = ___ratelimit(lpass_cdc_rx_macro_core_vote__rs,"lpass_cdc_rx_macro_core_vote");
        if (iVar2 != 0) {
          _printk(&DAT_0011a61f,"lpass_cdc_rx_macro_core_vote");
        }
      }
      else {
        __pm_runtime_suspend(*param_1,0xd);
        lVar3 = *param_1;
        uVar5 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar3 + 0x220) = uVar5;
      }
    }
    *(undefined2 *)((long)param_1 + 0x934) = *(undefined2 *)((long)param_1 + 0x936);
    goto LAB_00101e8c;
  }
  if (iVar2 != 0) {
    iVar1 = 0;
LAB_00101b48:
    *(int *)(param_1 + 8) = iVar2 + 1;
    goto LAB_00101e8c;
  }
  if (*(char *)((long)param_1 + 0x6ac) != '\0') {
    *(undefined2 *)((long)param_1 + 0x934) = 1;
  }
  if (param_1 == (long *)0x0) {
    iVar2 = ___ratelimit(lpass_cdc_rx_macro_core_vote__rs,"lpass_cdc_rx_macro_core_vote");
    if (iVar2 == 0) goto LAB_00101d98;
    _printk(&DAT_0011a61f,"lpass_cdc_rx_macro_core_vote");
    iVar1 = -0x16;
LAB_00101dc4:
    iVar2 = ___ratelimit(lpass_cdc_rx_macro_mclk_enable__rs_42,"lpass_cdc_rx_macro_mclk_enable");
    if (iVar2 == 0) goto LAB_00101e8c;
    lVar3 = *param_1;
    pcVar6 = "%s: rx request core vote failed\n";
  }
  else {
    if (*(char *)((long)param_1 + 0x6b1) == '\0') {
LAB_00101d98:
      iVar1 = -0x16;
      goto LAB_00101dc4;
    }
    __pm_runtime_resume(*param_1,4);
    uVar4 = lpass_cdc_check_core_votes(*param_1);
    if ((uVar4 & 1) == 0) {
      iVar1 = -0x20a;
      goto LAB_00101dc4;
    }
    iVar1 = lpass_cdc_clk_rsc_request_clock
                      (*param_1,*(undefined2 *)((long)param_1 + 0x936),
                       *(undefined2 *)((long)param_1 + 0x934),1);
    __pm_runtime_suspend(*param_1,0xd);
    lVar7 = *param_1;
    uVar5 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar7 + 0x220) = uVar5;
    if (-1 < iVar1) {
      lpass_cdc_clk_rsc_fs_gen_request(*param_1,1);
      regcache_mark_dirty(lVar3);
      regcache_sync_region(lVar3,0x1000,0x1f8c);
      regmap_update_bits_base(lVar3,0x1100,1,1,0,0,0);
      regmap_update_bits_base(lVar3,0x1100,2,2,0,0,0);
      regmap_update_bits_base(lVar3,0x1104,2,0,0,0,0);
      regmap_update_bits_base(lVar3,0x1104,1,1,0,0,0);
      iVar2 = (int)param_1[8];
      goto LAB_00101b48;
    }
    iVar2 = ___ratelimit(lpass_cdc_rx_macro_mclk_enable__rs_44,"lpass_cdc_rx_macro_mclk_enable");
    if (iVar2 == 0) goto LAB_00101e8c;
    lVar3 = *param_1;
    pcVar6 = "%s: rx request clock enable failed\n";
  }
  _dev_err(lVar3,pcVar6,"lpass_cdc_rx_macro_mclk_enable");
LAB_00101e8c:
  mutex_unlock(param_1 + 0xd7);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_init @ 00101f60 size=732
// signature: undefined lpass_cdc_rx_macro_init(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_rx_macro_init(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),1);
  if (lVar3 == 0) {
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    pcVar5 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar3 + 0x98);
    if (lVar6 != 0) {
      lVar1 = param_1 + 0xd0;
      iVar2 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_rx_macro_dapm_widgets,0x4c);
      if (iVar2 < 0) {
        pcVar5 = "%s: failed to add controls\n";
      }
      else {
        iVar2 = snd_soc_dapm_add_routes(lVar1,&rx_audio_map,0x124);
        if (iVar2 < 0) {
          pcVar5 = "%s: failed to add routes\n";
        }
        else {
          iVar2 = snd_soc_dapm_new_widgets(*(undefined8 *)(param_1 + 0xe8));
          if (iVar2 < 0) {
            pcVar5 = "%s: failed to add widgets\n";
          }
          else {
            iVar2 = snd_soc_add_component_controls(param_1,lpass_cdc_rx_macro_snd_controls,0x33);
            if (-1 < iVar2) {
              *(undefined2 *)(lVar6 + 0x940) = 0;
              *(undefined1 *)(lVar6 + 0x6b0) = 1;
              snd_soc_dapm_ignore_suspend(lVar1,"RX_MACRO_AIF1 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_MACRO_AIF2 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_MACRO_AIF3 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_MACRO_AIF4 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_MACRO_AIF5 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_MACRO_AIF6 Playback");
              snd_soc_dapm_ignore_suspend(lVar1,"HPHL_OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"HPHR_OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"AUX_OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"PCM_OUT");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_TX DEC0_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_TX DEC1_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_TX DEC2_INP");
              snd_soc_dapm_ignore_suspend(lVar1,"RX_TX DEC3_INP");
              snd_soc_dapm_sync(lVar1);
              snd_soc_component_update_bits(param_1,0x1434,7,2);
              snd_soc_component_update_bits(param_1,0x14f4,7,2);
              snd_soc_component_update_bits(param_1,0x15c0,7,2);
              snd_soc_component_update_bits(param_1,0x1410,3,2);
              snd_soc_component_update_bits(param_1,0x14d0,3,2);
              snd_soc_component_update_bits(param_1,0x1590,3,2);
              snd_soc_component_update_bits(param_1,0x140c,3,0);
              snd_soc_component_update_bits(param_1,0x14cc,3,0);
              snd_soc_component_update_bits(param_1,0x158c,3,0);
              *(long *)(lVar6 + 0x790) = param_1;
              return 0;
            }
            pcVar5 = "%s: failed to add snd_ctls\n";
          }
        }
      }
      _dev_err(lVar3,pcVar5,"lpass_cdc_rx_macro_init");
      return iVar2;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    pcVar5 = "%s: priv is null for macro!\n";
  }
  _dev_err(uVar4,pcVar5,"lpass_cdc_rx_macro_init");
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_deinit @ 00102240 size=116
// signature: undefined lpass_cdc_rx_macro_deinit(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_deinit(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_28;
  undefined1 auStack_20 [8];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data(param_1,auStack_20,&local_28,"lpass_cdc_rx_macro_deinit");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(undefined8 *)(local_28 + 0x790) = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_event_handler @ 001022b8 size=1828
// signature: undefined lpass_cdc_rx_macro_event_handler(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_rx_macro_event_handler(undefined8 param_1,undefined2 param_2,uint param_3)

{
  byte bVar1;
  long *plVar2;
  code *pcVar3;
  bool bVar4;
  undefined1 uVar5;
  byte bVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  undefined8 uVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  long *local_48;
  long local_40;
  long local_38;
  
  lVar14 = sp_el0;
  local_38 = *(long *)(lVar14 + 0x638);
  local_48 = (long *)0x0;
  local_40 = 0;
  uVar10 = lpass_cdc_rx_macro_get_data
                     (param_1,&local_40,&local_48,"lpass_cdc_rx_macro_event_handler");
  lVar14 = local_40;
  plVar2 = local_48;
  if ((uVar10 & 1) == 0) {
    iVar8 = -0x16;
    goto switchD_0010232c_caseD_6;
  }
  iVar8 = 0;
  switch(param_2) {
  case 1:
    bVar4 = (param_3 & 0xffff) != 0;
    iVar8 = (param_3 >> 0x10) * 0xc0;
    snd_soc_component_update_bits(param_1,iVar8 + 0x1400U & 0xffc0,0x10,(ulong)bVar4 << 4);
    uVar12 = iVar8 + 0x1418U & 0xfff8;
    uVar5 = 0x10;
    param_3 = (uint)bVar4 << 4;
    goto LAB_00102860;
  case 2:
    snd_soc_component_update_bits(param_1,0x1414,0xff,0);
    snd_soc_component_update_bits(param_1,0x1420,0xff,0);
    snd_soc_component_update_bits(param_1,0x1424,1,0);
    snd_soc_component_update_bits(param_1,0x14d4,0xff,0);
    snd_soc_component_update_bits(param_1,0x14e0,0xff,0);
    uVar12 = 0x14e4;
    uVar5 = 1;
    param_3 = 0;
    goto LAB_00102860;
  case 3:
    if (param_3 < 4) {
LAB_00102408:
      lVar14 = 0;
    }
    else {
      if (0xc < param_3) break;
      if (param_3 < 5) goto LAB_00102408;
      if (param_3 - 5 < 7) {
        lVar14 = (ulong)(param_3 - 5) + 1;
      }
      else {
        lVar14 = 8;
      }
    }
    uVar10 = (ulong)(byte)imped_index[lVar14 * 8 + 4];
    uVar15 = uVar10 * 0x18;
    if ((((((((0xd8 < uVar15) || (0xd8 < uVar15)) || (0xd8 < (uVar15 | 2))) ||
           (((0xd8 < (uVar15 | 3) || (0xd8 < (uVar10 * 0x18 | 2))) ||
            ((0xd8 < (uVar10 * 0x18 | 3) ||
             ((snd_soc_component_update_bits
                         (param_1,*(undefined2 *)(imped_table + uVar10 * 0x18),
                          imped_table[uVar10 * 0x18 + 2],imped_table[uVar10 * 0x18 + 3]),
              0xd8 < (uVar15 | 4) || (0xd8 < (uVar10 * 0x18 | 4))))))))) || (0xd8 < (uVar15 | 6)))
         || ((((((0xd8 < (uVar15 | 7) || (0xd8 < (uVar10 * 0x18 | 6))) ||
                (0xd8 < (uVar10 * 0x18 | 7))) ||
               ((snd_soc_component_update_bits
                           (param_1,*(undefined2 *)(imped_table + uVar10 * 0x18 + 4),
                            imped_table[uVar10 * 0x18 + 6],imped_table[uVar10 * 0x18 + 7]),
                0xd0 < uVar15 || (0xce < uVar15)))) || (uVar13 = uVar10 * 0x18, 0xd0 < uVar13)) ||
             (((0xce < uVar13 || (0xcd < uVar10 * 0x18)) ||
              (((snd_soc_component_update_bits
                           (param_1,*(undefined2 *)(imped_table + uVar13 + 8),
                            imped_table[uVar10 * 0x18 + 10],imped_table[uVar13 + 0xb]),
                0xcc < uVar15 ||
                (((0xca < uVar15 || (uVar13 = uVar10 * 0x18, 0xcc < uVar13)) || (0xca < uVar13))))
               || (((0xc9 < uVar10 * 0x18 ||
                    (snd_soc_component_update_bits
                               (param_1,*(undefined2 *)(imped_table + uVar13 + 0xc),
                                imped_table[uVar10 * 0x18 + 0xe],imped_table[uVar13 + 0xf]),
                    200 < uVar15)) || (0xc6 < uVar15)))))))))) ||
        (((uVar13 = uVar10 * 0x18, 200 < uVar13 || (0xc6 < uVar13)) ||
         ((0xc5 < uVar10 * 0x18 ||
          (((snd_soc_component_update_bits
                       (param_1,*(undefined2 *)(imped_table + uVar13 + 0x10),
                        imped_table[uVar10 * 0x18 + 0x12],imped_table[uVar13 + 0x13]), 0xc4 < uVar15
            || (0xc2 < uVar15)) || (uVar15 = uVar10 * 0x18, 0xc4 < uVar15)))))))) ||
       ((0xc2 < uVar15 || (0xc1 < uVar10 * 0x18)))) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x1029d8);
      (*pcVar3)();
    }
    uVar12 = (uint)*(ushort *)(imped_table + uVar15 + 0x14);
    param_3 = (uint)(byte)imped_table[uVar15 + 0x17];
    uVar5 = imped_table[uVar10 * 0x18 + 0x16];
    goto LAB_00102860;
  case 4:
    *(undefined2 *)(local_48 + 0xd6) = 0;
    if ((undefined8 *)local_48[0xe3] != (undefined8 *)0x0) {
      swrm_wcd_notify(*(undefined8 *)local_48[0xe3],6,0);
    }
    lVar14 = local_40;
    if (((*(ushort *)(local_40 + 0x200) & 7) != 0) || (*(int *)(local_40 + 0x20c) != 2)) {
      iVar8 = lpass_cdc_runtime_suspend(local_40);
      if (iVar8 == 0) {
        __pm_runtime_disable(lVar14,1);
        __pm_runtime_set_status(lVar14,2);
        pm_runtime_enable(lVar14);
      }
      goto switchD_0010232c_caseD_6;
    }
    break;
  case 5:
    *(undefined1 *)(local_48 + 0xd6) = 1;
    *(undefined1 *)((long)local_48 + 0x49) = 1;
    if ((undefined8 *)local_48[0xe3] != (undefined8 *)0x0) {
      swrm_wcd_notify(*(undefined8 *)local_48[0xe3],7,0);
    }
    break;
  default:
    goto switchD_0010232c_caseD_6;
  case 7:
    lpass_cdc_rsc_clk_reset(local_40,1);
    lpass_cdc_rsc_clk_reset(lVar14,5);
    break;
  case 9:
    if (param_3 >> 0x10 != 2) {
      uVar12 = (param_3 >> 0x10) * 0x60 + 0x1800 & 0xffe0;
      uVar7 = snd_soc_component_read(param_1,uVar12);
      snd_soc_component_write(param_1,uVar12,uVar7);
    }
    break;
  case 0xc:
    *(undefined1 *)((long)local_48 + 0x6b1) = 1;
    if (local_48 == (long *)0x0) {
      iVar8 = ___ratelimit(lpass_cdc_rx_macro_core_vote__rs,"lpass_cdc_rx_macro_core_vote");
      if (iVar8 == 0) {
        iVar8 = -0x16;
      }
      else {
        _printk(&DAT_0011a61f,"lpass_cdc_rx_macro_core_vote");
        iVar8 = -0x16;
      }
    }
    else {
      __pm_runtime_resume(*local_48,4);
      uVar10 = lpass_cdc_check_core_votes(*plVar2);
      if ((uVar10 & 1) != 0) {
        iVar8 = lpass_cdc_clk_rsc_request_clock(*plVar2,*(undefined2 *)((long)plVar2 + 0x936),1,1);
        if (iVar8 < 0) {
          iVar9 = ___ratelimit(lpass_cdc_rx_macro_event_handler__rs_347,
                               "lpass_cdc_rx_macro_event_handler");
          if (iVar9 != 0) {
            _dev_err(*plVar2,"%s, failed to enable clk, ret:%d\n","lpass_cdc_rx_macro_event_handler"
                     ,iVar8);
          }
        }
        else {
          lpass_cdc_clk_rsc_request_clock(*plVar2,*(undefined2 *)((long)plVar2 + 0x936),1,0);
        }
        __pm_runtime_suspend(*plVar2,0xd);
        lVar14 = *plVar2;
        uVar11 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar14 + 0x220) = uVar11;
        goto switchD_0010232c_caseD_6;
      }
      iVar8 = -0x20a;
    }
    iVar9 = ___ratelimit(lpass_cdc_rx_macro_event_handler__rs,"lpass_cdc_rx_macro_event_handler");
    if (iVar9 != 0) {
      _dev_err(*plVar2,"%s: rx request core vote failed\n","lpass_cdc_rx_macro_event_handler");
    }
    goto switchD_0010232c_caseD_6;
  case 0xd:
    uVar5 = snd_soc_component_read(param_1,0x1414);
    plVar2 = local_48;
    *(undefined1 *)(local_48 + 0x128) = uVar5;
    bVar6 = snd_soc_component_read(param_1,0x14d4);
    bVar1 = *(byte *)(plVar2 + 0x128);
    *(byte *)((long)plVar2 + 0x941) = bVar6;
    if (param_3 == 0) {
      if ((int)(char)bVar1 + 6U < 0x29) {
        snd_soc_component_update_bits(param_1,0x1414,0xff);
        bVar6 = *(byte *)((long)plVar2 + 0x941);
      }
      if ((byte)(bVar6 + 6) < 0x29) {
        param_3 = (int)(char)bVar6 + 6;
        goto LAB_00102914;
      }
    }
    else {
      if (bVar1 < 0x29) {
        snd_soc_component_update_bits(param_1,0x1414,0xff,bVar1 - 6);
        bVar6 = *(byte *)((long)plVar2 + 0x941);
      }
      if (bVar6 < 0x29) {
        param_3 = bVar6 - 6;
LAB_00102914:
        uVar12 = 0x14d4;
        uVar5 = 0xff;
        goto LAB_00102860;
      }
    }
    break;
  case 0xe:
    uVar12 = 0x1404;
    goto LAB_00102858;
  case 0xf:
    uVar12 = 0x14c4;
LAB_00102858:
    uVar5 = 4;
LAB_00102860:
    snd_soc_component_update_bits(param_1,uVar12,uVar5,param_3);
  }
  iVar8 = 0;
switchD_0010232c_caseD_6:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_set_port_map @ 001029e0 size=176
// signature: undefined lpass_cdc_rx_macro_set_port_map(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_set_port_map
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined8 local_50;
  long local_48;
  undefined1 auStack_40 [8];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (param_1,auStack_40,&local_48,"lpass_cdc_rx_macro_set_port_map");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    local_58 = param_3;
    uStack_54 = param_2;
    local_50 = param_4;
    if (*(undefined8 **)(local_48 + 0x718) == (undefined8 *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = swrm_wcd_notify(**(undefined8 **)(local_48 + 0x718),9,&local_58);
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
// lpass_cdc_rx_macro_enable_echo @ 00102a94 size=396
// signature: undefined lpass_cdc_rx_macro_enable_echo(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_enable_echo(long param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  char *__s1;
  undefined1 auStack_48 [8];
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_40 = 0;
  lVar6 = *(long *)(param_1 + 0x28) + -0xd0;
  uVar4 = lpass_cdc_rx_macro_get_data(lVar6,&local_40,auStack_48,"lpass_cdc_rx_macro_enable_echo");
  if ((uVar4 & 1) != 0) {
    uVar1 = snd_soc_component_read(lVar6,0x1198);
    __s1 = *(char **)(param_1 + 8);
    iVar2 = strcmp(__s1,"RX MIX TX0 MUX");
    if (iVar2 == 0) {
      uVar1 = uVar1 >> 4;
LAB_00102b34:
      uVar1 = (uVar1 & 0xf) - 1;
    }
    else {
      iVar2 = strcmp(__s1,"RX MIX TX1 MUX");
      if (iVar2 == 0) goto LAB_00102b34;
      uVar1 = 0;
    }
    uVar3 = snd_soc_component_read(lVar6,0x119c);
    iVar2 = strcmp(*(char **)(param_1 + 8),"RX MIX TX2 MUX");
    uVar3 = (uVar3 & 0xf) - 1;
    if (iVar2 != 0) {
      uVar3 = uVar1;
    }
    if (uVar3 < 3) {
      snd_soc_component_update_bits(lVar6,uVar3 * 0x40 + 0x1c00 & 0xffc0,1,1);
      snd_soc_component_update_bits(lVar6,uVar3 * 0x40 + 0x1c04 & 0xfffc,0x1e,8);
      uVar5 = 0;
      goto LAB_00102bd0;
    }
    iVar2 = ___ratelimit(lpass_cdc_rx_macro_enable_echo__rs,"lpass_cdc_rx_macro_enable_echo");
    if (iVar2 != 0) {
      _dev_err(local_40,"%s: EC mix control not set correctly\n","lpass_cdc_rx_macro_enable_echo");
      uVar5 = 0xffffffea;
      goto LAB_00102bd0;
    }
  }
  uVar5 = 0xffffffea;
LAB_00102bd0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_set_iir_gain @ 00102c24 size=260
// signature: undefined lpass_cdc_rx_macro_set_iir_gain(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_set_iir_gain(long param_1,undefined8 param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  long lVar8;
  
  if ((param_3 == 4) || (param_3 == 2)) {
    lVar8 = *(long *)(param_1 + 0x28) + -0xd0;
    lVar4 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_00119764,5);
    bVar1 = lVar4 != 0;
    uVar3 = 0x1a84;
    if (bVar1) {
      uVar3 = 0x1a04;
    }
    uVar6 = 0x1a88;
    if (bVar1) {
      uVar6 = 0x1a08;
    }
    uVar5 = 0x1a8c;
    if (bVar1) {
      uVar5 = 0x1a0c;
    }
    uVar7 = 0x1a90;
    if (bVar1) {
      uVar7 = 0x1a10;
    }
    uVar2 = snd_soc_component_read(lVar8,uVar3);
    snd_soc_component_write(lVar8,uVar3,uVar2);
    uVar3 = snd_soc_component_read(lVar8,uVar6);
    snd_soc_component_write(lVar8,uVar6,uVar3);
    uVar3 = snd_soc_component_read(lVar8,uVar5);
    snd_soc_component_write(lVar8,uVar5,uVar3);
    uVar3 = snd_soc_component_read(lVar8,uVar7);
    snd_soc_component_write(lVar8,uVar7,uVar3);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_enable_mix_path @ 00102d2c size=436
// signature: undefined lpass_cdc_rx_macro_enable_mix_path(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_enable_mix_path(long param_1,undefined8 param_2,int param_3)

{
  short sVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  undefined8 local_48;
  undefined1 auStack_40 [8];
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  lVar10 = *(long *)(param_1 + 0x28);
  local_48 = 0;
  lVar9 = lVar10 + -0xd0;
  uVar6 = lpass_cdc_rx_macro_get_data
                    (lVar9,auStack_40,&local_48,"lpass_cdc_rx_macro_enable_mix_path");
  if ((uVar6 & 1) != 0) {
    bVar2 = *(byte *)(param_1 + 0x4c);
    if (bVar2 < 3) {
      sVar3 = ((ushort)bVar2 + (ushort)bVar2 * 2) * 0x40;
      sVar1 = sVar3 + 0x1418;
      if (param_3 == 8) {
        snd_soc_component_update_bits(lVar9,sVar1,0x20,0);
        lpass_cdc_rx_macro_enable_interp_clk(lVar9,8,*(undefined1 *)(param_1 + 0x4c));
        snd_soc_component_update_bits(lVar9,sVar1,0x40,0x40);
        uVar7 = 0x40;
        uVar8 = 0;
LAB_00102e54:
        snd_soc_component_update_bits(lVar9,sVar1,uVar7,uVar8);
      }
      else if (param_3 == 2) {
        sVar3 = sVar3 + 0x1420;
        uVar5 = snd_soc_component_read(lVar9,sVar3);
        snd_soc_component_write(lVar9,sVar3,uVar5);
      }
      else if (param_3 == 1) {
        lpass_cdc_rx_macro_set_idle_detect_thr(lVar9,local_48,bVar2,1);
        lpass_cdc_rx_macro_enable_interp_clk(lVar9,1,*(undefined1 *)(param_1 + 0x4c));
        uVar7 = 0x20;
        uVar8 = 0x20;
        goto LAB_00102e54;
      }
      uVar7 = 0;
      goto LAB_00102e88;
    }
    iVar4 = ___ratelimit(lpass_cdc_rx_macro_enable_mix_path__rs,"lpass_cdc_rx_macro_enable_mix_path"
                        );
    if (iVar4 != 0) {
      _dev_err(*(undefined8 *)(lVar10 + -0xb8),"%s: Invalid Interpolator value %d for name %s\n",
               "lpass_cdc_rx_macro_enable_mix_path",*(undefined1 *)(param_1 + 0x4c),
               *(undefined8 *)(param_1 + 8));
      uVar7 = 0xffffffea;
      goto LAB_00102e88;
    }
  }
  uVar7 = 0xffffffea;
LAB_00102e88:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_enable_main_path @ 00102ee4 size=468
// signature: undefined lpass_cdc_rx_macro_enable_main_path(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_enable_main_path(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  undefined8 local_48;
  undefined1 auStack_40 [8];
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  lVar10 = *(long *)(param_1 + 0x28);
  local_48 = 0;
  lVar9 = lVar10 + -0xd0;
  uVar7 = lpass_cdc_rx_macro_get_data
                    (lVar9,auStack_40,&local_48,"lpass_cdc_rx_macro_enable_main_path");
  if ((uVar7 & 1) != 0) {
    bVar1 = *(byte *)(param_1 + 0x4c);
    if (bVar1 < 3) {
      if (param_3 == 8) {
        lpass_cdc_rx_macro_enable_interp_clk(lVar9,8);
      }
      else {
        iVar3 = ((uint)bVar1 + (uint)bVar1 * 2) * 0x40;
        if (param_3 == 2) {
          uVar4 = iVar3 + 0x1414U & 0xffd4;
          uVar6 = snd_soc_component_read(lVar9,uVar4);
          snd_soc_component_write(lVar9,uVar4,uVar6);
        }
        else if (param_3 == 1) {
          lpass_cdc_rx_macro_set_idle_detect_thr(lVar9,local_48,bVar1,0);
          lpass_cdc_rx_macro_enable_interp_clk(lVar9,1,*(undefined1 *)(param_1 + 0x4c));
          iVar2 = (uint)*(byte *)(param_1 + 0x4c) * 8;
          uVar4 = snd_soc_component_read(lVar9,iVar2 + 0x1180);
          uVar5 = snd_soc_component_read(lVar9,iVar2 + 0x1184);
          if ((((uVar4 & 0xf) - 1 < 4) || ((uVar4 >> 4 & 0xf) - 1 < 4)) ||
             ((uVar5 >> 4 & 0xf) - 1 < 4)) {
            snd_soc_component_update_bits(lVar9,iVar3 + 0x1400U & 0xffc0,0x20,0x20);
          }
        }
      }
      uVar8 = 0;
      goto LAB_00103060;
    }
    iVar3 = ___ratelimit(lpass_cdc_rx_macro_enable_main_path__rs,
                         "lpass_cdc_rx_macro_enable_main_path");
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(lVar10 + -0xb8),"%s: Invalid Interpolator value %d for name %s\n",
               "lpass_cdc_rx_macro_enable_main_path",*(undefined1 *)(param_1 + 0x4c),
               *(undefined8 *)(param_1 + 8));
      uVar8 = 0xffffffea;
      goto LAB_00103060;
    }
  }
  uVar8 = 0xffffffea;
LAB_00103060:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_enable_rx_path_clk @ 001030bc size=196
// signature: undefined lpass_cdc_rx_macro_enable_rx_path_clk(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_enable_rx_path_clk(long param_1,undefined8 param_2,int param_3)

{
  short sVar1;
  short sVar2;
  long lVar3;
  
  sVar2 = (ushort)*(byte *)(param_1 + 0x4c) * 0xc0;
  lVar3 = *(long *)(param_1 + 0x28) + -0xd0;
  sVar1 = sVar2 + 0x1408;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar3,sVar1,0x10,0);
    lpass_cdc_rx_macro_enable_interp_clk(lVar3,8,*(undefined1 *)(param_1 + 0x4c));
  }
  else if (param_3 == 1) {
    lpass_cdc_rx_macro_enable_interp_clk(lVar3,1);
    snd_soc_component_update_bits(lVar3,sVar1,0x10,0x10);
    snd_soc_component_update_bits(lVar3,sVar2 + 0x1400,0x20,0x20);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_enable_vbat @ 00103184 size=1012
// signature: undefined lpass_cdc_rx_macro_enable_vbat(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_enable_vbat(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int iVar6;
  long lVar7;
  long local_38;
  undefined8 local_30;
  long local_28;
  
  lVar7 = sp_el0;
  local_28 = *(long *)(lVar7 + 0x638);
  local_38 = 0;
  local_30 = 0;
  lVar7 = *(long *)(param_1 + 0x28) + -0xd0;
  uVar2 = lpass_cdc_rx_macro_get_data(lVar7,&local_30,&local_38,"lpass_cdc_rx_macro_enable_vbat");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
    goto LAB_0010352c;
  }
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar7,0x1608,1,0);
    snd_soc_component_update_bits(lVar7,0x1604,1,0);
    snd_soc_component_update_bits(lVar7,0x1600,1,0);
    snd_soc_component_update_bits(lVar7,0x1588,0x80,0);
    snd_soc_component_update_bits(lVar7,0x15c0,2,0);
    snd_soc_component_update_bits(lVar7,0x1284,2,2);
    snd_soc_component_update_bits(lVar7,0x1588,2,0);
    snd_soc_component_update_bits(lVar7,0x12dc,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12e0,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12e4,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12e8,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12ec,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12f0,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12f4,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12f8,0xff,0);
    snd_soc_component_update_bits(lVar7,0x12fc,0xff,0);
    iVar6 = *(int *)(local_38 + 0x92c) + -1;
    *(int *)(local_38 + 0x92c) = iVar6;
    if (iVar6 == 0) {
      snd_soc_component_update_bits(lVar7,0x1140,1,0);
    }
    snd_soc_component_update_bits(lVar7,0x1284,1,0);
    uVar3 = 0x1280;
    uVar4 = 0x10;
    uVar5 = 0;
LAB_00103508:
    snd_soc_component_update_bits(lVar7,uVar3,uVar4,uVar5);
  }
  else {
    if (param_3 == 1) {
      snd_soc_component_update_bits(lVar7,0x1280,0x10,0x10);
      snd_soc_component_update_bits(lVar7,0x1284,1,1);
      snd_soc_component_update_bits(lVar7,0x1588,0x80,0x80);
      snd_soc_component_update_bits(lVar7,0x15c0,2,2);
      snd_soc_component_update_bits(lVar7,0x1284,2,0);
      lVar1 = local_38;
      iVar6 = *(int *)(local_38 + 0x92c);
      if (iVar6 == 0) {
        snd_soc_component_update_bits(lVar7,0x1140,1,1);
        iVar6 = *(int *)(lVar1 + 0x92c);
      }
      *(int *)(lVar1 + 0x92c) = iVar6 + 1;
      snd_soc_component_update_bits(lVar7,0x1588,2,2);
      snd_soc_component_update_bits(lVar7,0x12dc,0xff,0xff);
      snd_soc_component_update_bits(lVar7,0x12e0,0xff,3);
      snd_soc_component_update_bits(lVar7,0x12e4,0xff,0);
      snd_soc_component_update_bits(lVar7,0x12e8,0xff,0xff);
      snd_soc_component_update_bits(lVar7,0x12ec,0xff,3);
      snd_soc_component_update_bits(lVar7,0x12f0,0xff,0);
      snd_soc_component_update_bits(lVar7,0x12f4,0xff,0xff);
      snd_soc_component_update_bits(lVar7,0x12f8,0xff,3);
      snd_soc_component_update_bits(lVar7,0x12fc,0xff,0);
      snd_soc_component_update_bits(lVar7,0x1600,1,1);
      snd_soc_component_update_bits(lVar7,0x1604,1,1);
      uVar3 = 0x1608;
      uVar4 = 1;
      uVar5 = 1;
      goto LAB_00103508;
    }
    uVar3 = ___ratelimit(lpass_cdc_rx_macro_enable_vbat__rs,"lpass_cdc_rx_macro_enable_vbat");
    if ((int)uVar3 == 0) goto LAB_0010352c;
    _dev_err(local_30,"%s: Invalid event %d\n","lpass_cdc_rx_macro_enable_vbat",param_3);
  }
  uVar3 = 0;
LAB_0010352c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_mclk_event @ 0010357c size=324
// signature: undefined lpass_cdc_rx_macro_mclk_event(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_mclk_event(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined4 local_3c;
  undefined8 *local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = (undefined8 *)0x0;
  local_3c = 9600000;
  uVar4 = lpass_cdc_rx_macro_get_data
                    (*(long *)(param_1 + 0x28) + -0xd0,auStack_30,&local_38,
                     "lpass_cdc_rx_macro_mclk_event");
  puVar2 = local_38;
  if ((uVar4 & 1) != 0) {
    if (param_3 == 8) {
      if (*(char *)(local_38 + 9) == '\0') {
        uVar5 = 0;
      }
      else {
        uVar5 = lpass_cdc_rx_macro_mclk_enable(local_38,0);
      }
      goto LAB_00103660;
    }
    if (param_3 == 1) {
      if (*(char *)((long)local_38 + 0x6ac) != '\0') {
        local_3c = 0xac4400;
      }
      if ((undefined8 *)local_38[0xe3] != (undefined8 *)0x0) {
        swrm_wcd_notify(*(undefined8 *)local_38[0xe3],5,&local_3c);
      }
      uVar5 = lpass_cdc_rx_macro_mclk_enable(puVar2,1);
      if ((int)uVar5 == 0) {
        *(undefined1 *)(puVar2 + 9) = 1;
      }
      else {
        *(undefined1 *)(puVar2 + 9) = 0;
      }
      goto LAB_00103660;
    }
    iVar3 = ___ratelimit(lpass_cdc_rx_macro_mclk_event__rs,"lpass_cdc_rx_macro_mclk_event");
    if (iVar3 != 0) {
      _dev_err(*local_38,"%s: invalid DAPM event %d\n","lpass_cdc_rx_macro_mclk_event",param_3);
    }
  }
  uVar5 = 0xffffffea;
LAB_00103660:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_mux_get @ 001036c4 size=168
// signature: undefined lpass_cdc_rx_macro_mux_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_mux_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = snd_soc_dapm_kcontrol_widget();
  local_38 = 0;
  uVar3 = lpass_cdc_rx_macro_get_data
                    (*(long *)(lVar2 + 0x28) + -0xd0,auStack_30,&local_38,
                     "lpass_cdc_rx_macro_mux_get");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    if (5 < (ulong)*(byte *)(lVar2 + 0x4c)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10376c);
      (*pcVar1)();
    }
    uVar4 = 0;
    *(long *)(param_2 + 0x48) = (long)*(int *)(local_38 + (ulong)*(byte *)(lVar2 + 0x4c) * 4 + 0x20)
    ;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_mux_put @ 00103770 size=568
// signature: undefined lpass_cdc_rx_macro_mux_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_mux_put(long param_1,long param_2)

{
  ulong *puVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  char *pcVar10;
  uint *puVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  undefined8 uVar15;
  long lVar16;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = snd_soc_dapm_kcontrol_widget();
  lVar16 = *(long *)(lVar8 + 0x28);
  uVar15 = *(undefined8 *)(param_1 + 0x78);
  uVar14 = *(ulong *)(param_2 + 0x48);
  local_58 = 0;
  local_50 = 0;
  uVar9 = lpass_cdc_rx_macro_get_data
                    (lVar16 + -0xd0,&local_50,&local_58,"lpass_cdc_rx_macro_mux_put");
  if ((uVar9 & 1) == 0) {
LAB_001038b0:
    uVar15 = 0xffffffea;
  }
  else {
    if (5 < (ulong)*(byte *)(lVar8 + 0x4c)) {
LAB_0010397c:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103980);
      (*pcVar6)();
    }
    puVar11 = (uint *)(local_58 + (ulong)*(byte *)(lVar8 + 0x4c) * 4 + 0x20);
    uVar2 = *puVar11;
    uVar13 = (uint)uVar14;
    if (uVar13 == 0) {
      if (uVar2 == 0) {
        uVar15 = ___ratelimit(lpass_cdc_rx_macro_mux_put__rs,"lpass_cdc_rx_macro_mux_put");
        if ((int)uVar15 == 0) goto LAB_001038b4;
        pcVar10 = "%s:AIF reset already\n";
      }
      else {
        if (uVar2 < 5) {
          lVar16 = local_58 + (ulong)uVar2 * 8;
          *puVar11 = 0;
          if (*(long *)(lVar16 + 0x7d8) != 0) {
            bVar3 = *(byte *)(lVar8 + 0x4c);
            puVar1 = (ulong *)(lVar16 + 0x798 + (ulong)(bVar3 >> 6) * 8);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar5) {
                *puVar1 = *puVar1 & (1L << ((ulong)bVar3 & 0x3f) ^ 0xffffffffffffffffU);
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            lVar12 = -1;
            goto LAB_00103838;
          }
          goto LAB_00103844;
        }
        uVar15 = ___ratelimit(lpass_cdc_rx_macro_mux_put__rs_140,"lpass_cdc_rx_macro_mux_put");
        if ((int)uVar15 == 0) goto LAB_001038b4;
        pcVar10 = "%s: Invalid AIF reset\n";
      }
      _dev_err(local_50,pcVar10,"lpass_cdc_rx_macro_mux_put");
    }
    else {
      *puVar11 = uVar13;
      if (4 < uVar13) {
        iVar7 = ___ratelimit(lpass_cdc_rx_macro_mux_put__rs_142,"lpass_cdc_rx_macro_mux_put");
        if (iVar7 != 0) {
          _dev_err(*(undefined8 *)(lVar16 + -0xb8),
                   "%s:Invalid AIF_ID for LPASS_CDC_RX_MACRO MUX %d\n","lpass_cdc_rx_macro_mux_put",
                   uVar14 & 0xffffffff);
          uVar15 = 0xffffffea;
          goto LAB_001038b4;
        }
        goto LAB_001038b0;
      }
      uVar9 = uVar14 & 0xffffffff;
      if (8 < uVar9) goto LAB_0010397c;
      bVar3 = *(byte *)(lVar8 + 0x4c);
      puVar1 = (ulong *)(local_58 + uVar9 * 8 + 0x798 + (ulong)(bVar3 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | 1L << ((ulong)bVar3 & 0x3f);
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      lVar16 = local_58 + uVar9 * 8;
      lVar12 = 1;
LAB_00103838:
      *(long *)(lVar16 + 0x7d8) = *(long *)(lVar16 + 0x7d8) + lVar12;
LAB_00103844:
      snd_soc_dapm_mux_update_power
                (*(undefined8 *)(lVar8 + 0x28),param_1,uVar14 & 0xffffffff,uVar15,0);
    }
    uVar15 = 0;
  }
LAB_001038b4:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar15);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_int_dem_inp_mux_put @ 001039bc size=136
// signature: undefined lpass_cdc_rx_macro_int_dem_inp_mux_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_int_dem_inp_mux_put(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  lVar1 = snd_soc_dapm_kcontrol_widget();
  if (*(uint *)(param_2 + 0x48) < (uint)(*(int **)(param_1 + 0x78))[2]) {
    uVar3 = 0x14c4;
    if (**(int **)(param_1 + 0x78) != 0x14c8) {
      uVar3 = 0x1404;
    }
    snd_soc_component_update_bits
              (*(long *)(lVar1 + 0x28) + -0xd0,uVar3,8,(ulong)(*(uint *)(param_2 + 0x48) != 0) << 3)
    ;
    uVar2 = snd_soc_dapm_put_enum_double(param_1,param_2);
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_set_idle_detect_thr @ 00103a44 size=1156
// signature: undefined lpass_cdc_rx_macro_set_idle_detect_thr(void)
// callers: [lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_enable_mix_path]
//------------------------------------------------------------

void lpass_cdc_rx_macro_set_idle_detect_thr
               (undefined8 param_1,long param_2,uint param_3,int param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  byte bVar8;
  ushort uVar9;
  int iVar10;
  code *pcVar11;
  uint uVar12;
  ushort uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  byte bVar17;
  char cVar18;
  uint *puVar19;
  uint *puVar20;
  uint local_58;
  int iStack_54;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  iStack_54 = 0;
  local_50 = 0;
  if ((1 < param_3) || (*(char *)(param_2 + 0x839) == '\0')) goto LAB_00103e80;
  if (param_4 == 0) {
    iVar10 = param_3 * 2;
    uVar12 = snd_soc_component_read(param_1,iVar10 + 0x1186);
    puVar19 = &local_58;
    uVar12 = (uVar12 & 0xf) - 5;
    cVar18 = uVar12 < 6;
    if ((bool)cVar18) {
      puVar19 = (uint *)((ulong)puVar19 | 4);
      local_58 = uVar12;
    }
    uVar12 = snd_soc_component_read(param_1,iVar10 + 0x1186);
    uVar12 = (uVar12 >> 4 & 0xf) - 5;
    puVar20 = puVar19;
    if (uVar12 < 6) {
      cVar18 = cVar18 + '\x01';
      puVar20 = puVar19 + 1;
      *puVar19 = uVar12;
    }
    uVar12 = snd_soc_component_read(param_1,iVar10 + 0x1187);
    uVar12 = (uVar12 >> 4 & 0xf) - 5;
    if (uVar12 < 6) {
      cVar18 = cVar18 + '\x01';
      *puVar20 = uVar12;
      snd_soc_component_read(param_1,iVar10 + 0x1188);
    }
    else {
      snd_soc_component_read(param_1,iVar10 + 0x1188);
      if (cVar18 == '\0') goto LAB_00103e58;
    }
LAB_00103b6c:
    lVar1 = param_2 + 0x7a0;
    lVar15 = 1;
    lVar2 = param_2 + 0x7a8;
    lVar3 = param_2 + 0x7b0;
    lVar4 = param_2 + 0x7b8;
    uVar14 = (ulong)(long)(int)local_58 >> 6;
    lVar5 = param_2 + 0x7c0;
    lVar6 = param_2 + 0x7c8;
    lVar7 = param_2 + 2000;
    uVar16 = 1L << ((long)(int)local_58 & 0x3fU);
    if ((*(ulong *)(lVar1 + uVar14 * 8) & uVar16) == 0) {
      if ((*(ulong *)(lVar2 + uVar14 * 8) & uVar16) != 0) {
        lVar15 = 2;
        goto LAB_00103c18;
      }
      if ((*(ulong *)(lVar3 + uVar14 * 8) & uVar16) != 0) {
        lVar15 = 3;
        goto LAB_00103c18;
      }
      if ((*(ulong *)(lVar4 + uVar14 * 8) & uVar16) != 0) {
        lVar15 = 4;
        goto LAB_00103c18;
      }
      if ((*(ulong *)(lVar5 + uVar14 * 8) & uVar16) != 0) {
        lVar15 = 5;
        goto LAB_00103c18;
      }
      if ((*(ulong *)(lVar6 + uVar14 * 8) & uVar16) != 0) {
        lVar15 = 6;
        goto LAB_00103c18;
      }
      if ((*(ulong *)(lVar7 + uVar14 * 8) & uVar16) != 0) {
        lVar15 = 7;
        goto LAB_00103c18;
      }
      uVar13 = 0;
    }
    else {
LAB_00103c18:
      uVar13 = *(ushort *)(param_2 + lVar15 * 2 + 0x818);
    }
    if (cVar18 != '\x01') {
      lVar15 = 1;
      uVar16 = (ulong)(long)iStack_54 >> 6;
      uVar14 = 1L << ((long)iStack_54 & 0x3fU);
      if ((*(ulong *)(lVar1 + uVar16 * 8) & uVar14) == 0) {
        if ((*(ulong *)(lVar2 + uVar16 * 8) & uVar14) != 0) {
          lVar15 = 2;
          goto LAB_00103cb8;
        }
        if ((*(ulong *)(lVar3 + uVar16 * 8) & uVar14) != 0) {
          lVar15 = 3;
          goto LAB_00103cb8;
        }
        if ((*(ulong *)(lVar4 + uVar16 * 8) & uVar14) != 0) {
          lVar15 = 4;
          goto LAB_00103cb8;
        }
        if ((*(ulong *)(lVar5 + uVar16 * 8) & uVar14) != 0) {
          lVar15 = 5;
          goto LAB_00103cb8;
        }
        if ((*(ulong *)(lVar6 + uVar16 * 8) & uVar14) != 0) {
          lVar15 = 6;
          goto LAB_00103cb8;
        }
        if ((*(ulong *)(lVar7 + uVar16 * 8) & uVar14) != 0) {
          lVar15 = 7;
          goto LAB_00103cb8;
        }
      }
      else {
LAB_00103cb8:
        uVar9 = *(ushort *)(param_2 + lVar15 * 2 + 0x818);
        if (uVar13 <= uVar9) {
          uVar13 = uVar9;
        }
      }
      if (cVar18 != '\x02') {
        lVar15 = 1;
        uVar16 = (ulong)(long)(int)local_50 >> 6;
        uVar14 = 1L << ((long)(int)local_50 & 0x3fU);
        if ((*(ulong *)(lVar1 + uVar16 * 8) & uVar14) == 0) {
          if ((*(ulong *)(lVar2 + uVar16 * 8) & uVar14) != 0) {
            lVar15 = 2;
            goto LAB_00103d70;
          }
          if ((*(ulong *)(lVar3 + uVar16 * 8) & uVar14) != 0) {
            lVar15 = 3;
            goto LAB_00103d70;
          }
          if ((*(ulong *)(lVar4 + uVar16 * 8) & uVar14) != 0) {
            lVar15 = 4;
            goto LAB_00103d70;
          }
          if ((*(ulong *)(lVar5 + uVar16 * 8) & uVar14) != 0) {
            lVar15 = 5;
            goto LAB_00103d70;
          }
          if ((*(ulong *)(lVar6 + uVar16 * 8) & uVar14) != 0) {
            lVar15 = 6;
            goto LAB_00103d70;
          }
          if ((*(ulong *)(lVar7 + uVar16 * 8) & uVar14) != 0) {
            lVar15 = 7;
            goto LAB_00103d70;
          }
        }
        else {
LAB_00103d70:
          uVar9 = *(ushort *)(param_2 + lVar15 * 2 + 0x818);
          if (uVar13 <= uVar9) {
            uVar13 = uVar9;
          }
        }
        if (cVar18 != '\x03') {
          uVar14 = (ulong)(long)local_50._4_4_ >> 6;
          lVar15 = 1;
          uVar16 = 1L << ((long)local_50._4_4_ & 0x3fU);
          if ((*(ulong *)(lVar1 + uVar14 * 8) & uVar16) == 0) {
            if ((*(ulong *)(lVar2 + uVar14 * 8) & uVar16) != 0) {
              lVar15 = 2;
              goto LAB_00103e18;
            }
            if ((*(ulong *)(lVar3 + uVar14 * 8) & uVar16) != 0) {
              lVar15 = 3;
              goto LAB_00103e18;
            }
            if ((*(ulong *)(lVar4 + uVar14 * 8) & uVar16) != 0) {
              lVar15 = 4;
              goto LAB_00103e18;
            }
            if ((*(ulong *)(lVar5 + uVar14 * 8) & uVar16) != 0) {
              lVar15 = 5;
              goto LAB_00103e18;
            }
            if ((*(ulong *)(lVar6 + uVar14 * 8) & uVar16) != 0) {
              lVar15 = 6;
              goto LAB_00103e18;
            }
            if ((*(ulong *)(lVar7 + uVar14 * 8) & uVar16) != 0) {
              lVar15 = 7;
              goto LAB_00103e18;
            }
          }
          else {
LAB_00103e18:
            uVar9 = *(ushort *)(param_2 + lVar15 * 2 + 0x818);
            if (uVar13 <= uVar9) {
              uVar13 = uVar9;
            }
          }
          if (cVar18 != '\x04') {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(1,0x103ec8);
            (*pcVar11)();
          }
        }
      }
    }
    if (uVar13 == 0x10) {
      bVar17 = 0xff;
      bVar8 = *(byte *)(param_2 + 0x838);
    }
    else {
      if ((uVar13 != 0x20) && (uVar13 != 0x18)) goto LAB_00103e58;
      bVar17 = 3;
      bVar8 = *(byte *)(param_2 + 0x838);
    }
  }
  else {
    if (param_4 == 1) {
      uVar12 = snd_soc_component_read(param_1,param_3 * 2 + 0x1184);
      uVar12 = (uVar12 & 0xf) - 1;
      if (uVar12 < 6) {
        cVar18 = '\x01';
        local_58 = uVar12;
        goto LAB_00103b6c;
      }
    }
LAB_00103e58:
    bVar17 = 0;
    bVar8 = *(byte *)(param_2 + 0x838);
  }
  if ((bVar8 == 0) || (bVar17 < bVar8)) {
    snd_soc_component_write(param_1,0x1790,bVar17);
    *(byte *)(param_2 + 0x838) = bVar17;
  }
LAB_00103e80:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_enable_interp_clk @ 00103ec8 size=1628
// signature: undefined lpass_cdc_rx_macro_enable_interp_clk(void)
// callers: [lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_enable_rx_path_clk, lpass_cdc_rx_macro_enable_mix_path]
//------------------------------------------------------------

void lpass_cdc_rx_macro_enable_interp_clk(long param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  int iVar10;
  undefined4 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int *piVar14;
  long local_78;
  undefined8 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_78 = 0;
  local_70 = 0;
  if (param_1 == 0) {
    iVar6 = ___ratelimit(lpass_cdc_rx_macro_enable_interp_clk__rs,
                         "lpass_cdc_rx_macro_enable_interp_clk");
    if (iVar6 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_enable_interp_clk");
    }
    goto LAB_00104408;
  }
  uVar8 = lpass_cdc_rx_macro_get_data
                    (param_1,&local_70,&local_78,"lpass_cdc_rx_macro_enable_interp_clk");
  lVar4 = local_78;
  if ((uVar8 & 1) == 0) goto LAB_00104408;
  iVar6 = param_3 * 0xc0;
  uVar3 = 0x15cc;
  if (param_3 != 2) {
    uVar3 = iVar6 + 0x1440;
  }
  uVar1 = param_2 & 3;
  if (uVar1 != 0) {
    if (2 < param_3) goto LAB_00104520;
    piVar14 = (int *)(local_78 + (ulong)param_3 * 4 + 0x14);
    iVar10 = *piVar14;
    if (iVar10 == 0) {
      uVar7 = iVar6 + 0x1400U & 0xffff;
      snd_soc_component_update_bits(param_1,uVar7,0x10,0x10);
      snd_soc_component_update_bits(param_1,uVar3 & 0xffff,1,1);
      snd_soc_component_update_bits(param_1,uVar7,0x20,0x20);
      if ((*(char *)(lVar4 + 0x839) != '\0') && (*(char *)(lVar4 + 0x10) == '\0')) {
        uVar11 = 0;
        if (param_3 < 2) {
          uVar11 = 0x1780;
        }
        uVar2 = 2;
        if (param_3 != 1) {
          uVar2 = param_3 == 0;
        }
        if ((param_3 < 2) &&
           (snd_soc_component_update_bits(param_1,uVar11,uVar2,uVar2), (param_2 & 0xc) != 0)) {
          snd_soc_component_update_bits(param_1,uVar11,uVar2,0);
          *(undefined1 *)(lVar4 + 0x838) = 0;
          snd_soc_component_write(param_1,0x1790,0);
        }
      }
      if ((*(char *)(lVar4 + 0x6b3) != '\0') && (*(char *)(lVar4 + 0x10) == '\0')) {
        if ((param_3 & 0xffff) == 0) {
          uVar13 = 0x1404;
          uVar12 = 0x142c;
        }
        else {
          if ((param_3 & 0xffff) != 1) goto LAB_001040dc;
          uVar13 = 0x14c4;
          uVar12 = 0x14ec;
        }
        snd_soc_component_update_bits(param_1,uVar12,0x3c,0x14);
        snd_soc_component_update_bits(param_1,uVar13,4,4);
        if ((param_2 & 0xc) != 0) {
          snd_soc_component_update_bits(param_1,uVar13,4,0);
          snd_soc_component_update_bits(param_1,uVar12,0x3c,0);
        }
      }
LAB_001040dc:
      lpass_cdc_rx_macro_hphdelay_lutbypass(param_1,lVar4,param_3,param_2);
      if (*(char *)(lVar4 + 0x10) == '\0') {
        uVar7 = snd_soc_component_read(param_1,iVar6 + 0x1400U & 0xffc0);
        uVar7 = uVar7 & 0xf;
        if (uVar7 < 6) {
          lVar9 = 3;
        }
        else if (uVar7 < 8) {
          lVar9 = 1;
        }
        else {
          lVar9 = (ulong)(uVar7 < 0xb) << 1;
        }
        uVar7 = iVar6 + 0x1410U & 0xffd0;
        snd_soc_component_update_bits(param_1,uVar7,3,lVar9);
        if ((param_2 & 0xc) != 0) {
          snd_soc_component_update_bits(param_1,uVar7,3,3);
        }
      }
      lpass_cdc_rx_macro_config_compander(param_1,lVar4,param_3,param_2);
      if (param_3 == 2) {
        lpass_cdc_rx_macro_config_softclip(param_1,lVar4,param_2);
        if (*(int *)(lVar4 + 0x928) == 0) {
          snd_soc_component_update_bits(param_1,0x1588,4,0);
        }
        if ((param_2 & 0xc) != 0) {
          snd_soc_component_update_bits(param_1,0x1588,4,4);
        }
      }
      lpass_cdc_rx_macro_config_classh(param_1,lVar4,param_3,param_2);
      if (((*(char *)(lVar4 + 0x10) != '\0') && (param_3 != 2)) &&
         (*(char *)(lVar4 + 0x6ac) == '\0')) {
        iVar10 = *(int *)(lVar4 + 0x944);
        if (iVar10 == 0) {
          snd_soc_component_update_bits(param_1,0x1008,2,2);
          iVar10 = *(int *)(lVar4 + 0x944);
        }
        *(int *)(lVar4 + 0x944) = iVar10 + 1;
      }
      lpass_cdc_notify_wcd_rx_clk(local_70,*(undefined1 *)(lVar4 + 0x6ac));
      iVar10 = *piVar14;
    }
    *piVar14 = iVar10 + 1;
  }
  lVar4 = local_78;
  if ((param_2 & 0xc) == 0) {
    if (2 < param_3) goto LAB_00104520;
    goto LAB_00104408;
  }
  if (3 < param_3) {
LAB_00104520:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x104524);
    (*pcVar5)();
  }
  piVar14 = (int *)(local_78 + (ulong)param_3 * 4 + 0x14);
  iVar10 = *piVar14;
  *piVar14 = iVar10 + -1;
  if (param_3 == 3) goto LAB_00104520;
  if (0 < iVar10 + -1) goto LAB_00104408;
  uVar7 = iVar6 + 0x1400U & 0xffff;
  *piVar14 = 0;
  snd_soc_component_update_bits(param_1,uVar7,0x10,0x10);
  if (((*(char *)(lVar4 + 0x10) != '\0') && (param_3 != 2)) && (*(char *)(lVar4 + 0x6ac) == '\0')) {
    iVar6 = *(int *)(lVar4 + 0x944);
    if (iVar6 == 1) {
      snd_soc_component_update_bits(param_1,0x1008,2,0);
      iVar6 = *(int *)(lVar4 + 0x944);
    }
    iVar6 = iVar6 + -1;
    if (iVar6 < 1) {
      iVar6 = 0;
    }
    *(int *)(lVar4 + 0x944) = iVar6;
  }
  snd_soc_component_update_bits(param_1,uVar3 & 0xffff,1,0);
  snd_soc_component_update_bits(param_1,uVar7,0x20,0);
  snd_soc_component_update_bits(param_1,uVar7,0x40,0x40);
  snd_soc_component_update_bits(param_1,uVar7,0x40,0);
  snd_soc_component_update_bits(param_1,uVar7,0xf,4);
  lpass_cdc_rx_macro_config_classh(param_1,lVar4,param_3,param_2);
  lpass_cdc_rx_macro_config_compander(param_1,lVar4,param_3,param_2);
  if (param_3 == 2) {
    lpass_cdc_rx_macro_config_softclip(param_1,lVar4,param_2);
    if ((uVar1 != 0) && (*(int *)(lVar4 + 0x928) == 0)) {
      snd_soc_component_update_bits(param_1,0x1588,4,0);
    }
    snd_soc_component_update_bits(param_1,0x1588,4,4);
  }
  lpass_cdc_rx_macro_hphdelay_lutbypass(param_1,lVar4,param_3,param_2);
  if ((*(char *)(lVar4 + 0x6b3) != '\0') && (*(char *)(lVar4 + 0x10) == '\0')) {
    if ((param_3 & 0xffff) == 0) {
      uVar13 = 0x1404;
      uVar12 = 0x142c;
    }
    else {
      if ((param_3 & 0xffff) != 1) goto LAB_0010449c;
      uVar13 = 0x14c4;
      uVar12 = 0x14ec;
    }
    if (uVar1 != 0) {
      snd_soc_component_update_bits(param_1,uVar12,0x3c,0x14);
      snd_soc_component_update_bits(param_1,uVar13,4,4);
    }
    snd_soc_component_update_bits(param_1,uVar13,4,0);
    snd_soc_component_update_bits(param_1,uVar12,0x3c,0);
  }
LAB_0010449c:
  if ((*(char *)(lVar4 + 0x839) != '\0') && (*(char *)(lVar4 + 0x10) == '\0')) {
    uVar11 = 0;
    if (param_3 < 2) {
      uVar11 = 0x1780;
    }
    uVar2 = 2;
    if (param_3 != 1) {
      uVar2 = param_3 == 0;
    }
    if ((param_3 < 2) && (uVar1 != 0)) {
      snd_soc_component_update_bits(param_1,uVar11,uVar2,uVar2);
    }
    else if (1 < param_3) goto LAB_00104408;
    snd_soc_component_update_bits(param_1,uVar11,uVar2,0);
    *(undefined1 *)(lVar4 + 0x838) = 0;
    snd_soc_component_write(param_1,0x1790,0);
  }
LAB_00104408:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_hphdelay_lutbypass @ 00104524 size=340
// signature: undefined lpass_cdc_rx_macro_hphdelay_lutbypass(void)
// callers: [lpass_cdc_rx_macro_enable_interp_clk]
//------------------------------------------------------------

void lpass_cdc_rx_macro_hphdelay_lutbypass
               (undefined8 param_1,long param_2,short param_3,ulong param_4)

{
  char cVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_2 + 0x10) != '\0') {
    return;
  }
  if (param_3 == 1) {
    if ((param_4 & 3) == 0) {
      uVar3 = 0x103c;
      uVar2 = 0x187c;
      goto LAB_00104630;
    }
    uVar3 = 0x103c;
    snd_soc_component_update_bits(param_1,0x103c,0x80,0x80);
    uVar2 = 0x187c;
    cVar1 = *(char *)(param_2 + 0x6b2);
  }
  else {
    if (param_3 != 0) {
      return;
    }
    if ((param_4 & 3) == 0) {
      uVar3 = 0x1028;
      uVar2 = 0x181c;
      goto LAB_00104630;
    }
    if (*(char *)(param_2 + 0x6ad) == '\0') {
      uVar3 = 0x1028;
      snd_soc_component_update_bits(param_1,0x1028,0x80,0x80);
      uVar2 = 0x181c;
      cVar1 = *(char *)(param_2 + 0x6b2);
    }
    else {
      snd_soc_component_update_bits(param_1,0x1408,2,2);
      uVar2 = 0x181c;
      uVar3 = 0x1028;
      cVar1 = *(char *)(param_2 + 0x6b2);
    }
  }
  if (cVar1 != '\0') {
    snd_soc_component_update_bits(param_1,uVar2,0x20,0);
  }
LAB_00104630:
  if ((param_4 & 0xc) != 0) {
    snd_soc_component_update_bits(param_1,0x1408,2,0);
    snd_soc_component_update_bits(param_1,uVar3,0x80,0);
    snd_soc_component_update_bits(param_1,uVar2,0x20,0x20);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_config_compander @ 00104678 size=420
// signature: undefined lpass_cdc_rx_macro_config_compander(void)
// callers: [lpass_cdc_rx_macro_enable_interp_clk]
//------------------------------------------------------------

void lpass_cdc_rx_macro_config_compander(undefined8 param_1,long param_2,uint param_3,ulong param_4)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_3 != 2) {
    if (1 < param_3) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10481c);
      (*pcVar5)();
    }
    if ((*(int *)(param_2 + (ulong)param_3 * 4 + 8) != 0) && (*(char *)(param_2 + 0x10) == '\0')) {
      uVar4 = param_3 * 0xc0 + 0x1404;
      uVar1 = param_3 * 0x60 + 0x1800;
      if ((param_4 & 3) != 0) {
        uVar3 = 2;
        if (*(char *)(param_2 + 0x6ad) == '\0' || param_3 != 0) {
          uVar3 = (ulong)*(byte *)(param_2 + 0x6b2);
        }
        uVar6 = 0x1020;
        if (param_3 != 0) {
          uVar6 = 0x1034;
        }
        uVar7 = 0x1024;
        if (param_3 != 0) {
          uVar7 = 0x1038;
        }
        lpass_cdc_load_compander_coeff
                  (param_1,uVar6,uVar7,comp_coeff_table + (ulong)*(byte *)(param_2 + 0x6b2) * 0x32,
                   0x19);
        lpass_cdc_update_compander_setting
                  (param_1,param_3 * 0x60 + 0x1820,comp_setting_table + uVar3 * 0xc);
        uVar2 = uVar1 & 0xffff;
        snd_soc_component_update_bits(param_1,uVar2,1,1);
        snd_soc_component_update_bits(param_1,uVar2,2,2);
        snd_soc_component_update_bits(param_1,uVar2,2,0);
        snd_soc_component_update_bits(param_1,uVar4 & 0xffff,2,2);
      }
      if ((param_4 & 0xc) != 0) {
        uVar1 = uVar1 & 0xffff;
        snd_soc_component_update_bits(param_1,uVar1,4,4);
        snd_soc_component_update_bits(param_1,uVar4 & 0xffff,2,0);
        snd_soc_component_update_bits(param_1,uVar1,1,0);
        snd_soc_component_update_bits(param_1,uVar1,4,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_config_softclip @ 0010481c size=192
// signature: undefined lpass_cdc_rx_macro_config_softclip(void)
// callers: [lpass_cdc_rx_macro_enable_interp_clk]
//------------------------------------------------------------

void lpass_cdc_rx_macro_config_softclip(undefined8 param_1,long param_2,ulong param_3)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0x924) != 0) {
    if ((param_3 & 3) != 0) {
      iVar1 = *(int *)(param_2 + 0x92c);
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x1140,1,1);
        iVar1 = *(int *)(param_2 + 0x92c);
      }
      *(int *)(param_2 + 0x92c) = iVar1 + 1;
      snd_soc_component_update_bits(param_1,0x1144,1,1);
    }
    if ((param_3 & 0xc) != 0) {
      snd_soc_component_update_bits(param_1,0x1144,1,0);
      iVar1 = *(int *)(param_2 + 0x92c) + -1;
      *(int *)(param_2 + 0x92c) = iVar1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x1140,1,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_config_classh @ 001048dc size=408
// signature: undefined lpass_cdc_rx_macro_config_classh(void)
// callers: [lpass_cdc_rx_macro_enable_interp_clk]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void lpass_cdc_rx_macro_config_classh(undefined8 param_1,long param_2,uint param_3,ulong param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  if (param_3 == 2) {
    return;
  }
  if ((param_4 & 0xc) != 0) {
    iVar2 = *(int *)(param_2 + 0x4c) + -1;
    *(int *)(param_2 + 0x4c) = iVar2;
    if (iVar2 == 0) {
      snd_soc_component_update_bits(*(undefined8 *)(param_2 + 0x790),0x1200,1,0);
      iVar2 = *(int *)(param_2 + 0x4c);
    }
    if (iVar2 < 0) {
      *(undefined4 *)(param_2 + 0x4c) = 0;
      return;
    }
    return;
  }
  if ((param_4 & 3) == 0) {
    return;
  }
  iVar1 = *(int *)(param_2 + 0x4c);
  iVar2 = iVar1 + 1;
  *(int *)(param_2 + 0x4c) = iVar2;
  if (iVar1 == 0) {
    snd_soc_component_update_bits(*(undefined8 *)(param_2 + 0x790),0x1200,1,1);
    iVar2 = *(int *)(param_2 + 0x4c);
  }
  if (iVar2 < 0) {
    *(undefined4 *)(param_2 + 0x4c) = 0;
  }
  if (param_3 < 2) {
    snd_soc_component_update_bits(param_1,0x1220,0xff,0xc0);
    snd_soc_component_update_bits(param_1,0x121c,0xf,0);
  }
  if (param_3 == 1) {
    uVar4 = 0x1c;
    if (*(char *)(param_2 + 0x6ad) != '\0') {
      uVar4 = 0x39;
    }
    snd_soc_component_update_bits(param_1,0x120c,0x3f,uVar4);
    snd_soc_component_update_bits(param_1,0x1208,7,0);
    uVar3 = 0x14c4;
  }
  else {
    if (param_3 != 0) {
      return;
    }
    uVar4 = 0x1c;
    if (*(char *)(param_2 + 0x6ad) != '\0') {
      uVar4 = 0x39;
    }
    snd_soc_component_update_bits(param_1,0x120c,0x3f,uVar4);
    snd_soc_component_update_bits(param_1,0x1208,7,0);
    uVar3 = 0x1404;
  }
  snd_soc_component_update_bits(param_1,uVar3,0x40,0x40);
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_compander @ 00104a78 size=156
// signature: undefined lpass_cdc_rx_macro_get_compander(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_get_compander(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  undefined8 uVar5;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar4 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_get_compander");
  if ((uVar4 & 1) == 0) {
    uVar5 = 0xffffffea;
  }
  else {
    if (1 < uVar1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104b14);
      (*pcVar3)();
    }
    uVar5 = 0;
    *(long *)(param_2 + 0x48) = (long)*(int *)(local_38 + (ulong)uVar1 * 4 + 8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_set_compander @ 00104b18 size=152
// signature: undefined lpass_cdc_rx_macro_set_compander(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_set_compander(long param_1,long param_2)

{
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  ulong uVar5;
  undefined8 uVar6;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar5 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_set_compander");
  if ((uVar5 & 1) == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    if (1 < uVar2) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104bb0);
      (*pcVar4)();
    }
    uVar6 = 0;
    *(undefined4 *)(local_38 + (ulong)uVar2 * 4 + 8) = uVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_pcm_path @ 00104bb4 size=136
// signature: undefined lpass_cdc_rx_macro_get_pcm_path(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_get_pcm_path(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_get_pcm_path");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_38 + 0x10);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_put_pcm_path @ 00104c40 size=136
// signature: undefined lpass_cdc_rx_macro_put_pcm_path(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_put_pcm_path(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_put_pcm_path");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(char *)(local_38 + 0x10) = (char)*(undefined8 *)(param_2 + 0x48);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_coeff_num_get @ 00104ccc size=272
// signature: undefined lpass_cdc_rx_macro_fir_coeff_num_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_fir_coeff_num_get(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = (undefined8 *)0x0;
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  if (*(long *)(param_1 + 0x80) == 0) {
    iVar3 = ___ratelimit(lpass_cdc_rx_macro_fir_coeff_num_get__rs,
                         "lpass_cdc_rx_macro_fir_coeff_num_get");
    if (iVar3 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_fir_coeff_num_get");
      uVar5 = 0xffffffea;
      goto LAB_00104d7c;
    }
  }
  else {
    uVar4 = lpass_cdc_rx_macro_get_data
                      (*(long *)(param_1 + 0x80),auStack_30,&local_38,
                       "lpass_cdc_rx_macro_fir_coeff_num_get");
    if ((uVar4 & 1) != 0) {
      if (uVar1 < 2) {
        uVar5 = 0;
        *(undefined1 *)(param_2 + 0x48) = *(undefined1 *)((long)local_38 + (ulong)uVar1 + 0x54);
        goto LAB_00104d7c;
      }
      iVar3 = ___ratelimit(lpass_cdc_rx_macro_fir_coeff_num_get__rs_305,
                           "lpass_cdc_rx_macro_fir_coeff_num_get");
      if (iVar3 != 0) {
        _dev_err(*local_38,"%s: path_idx:%d is invalid\n","lpass_cdc_rx_macro_fir_coeff_num_get",
                 uVar1);
        uVar5 = 0xffffffea;
        goto LAB_00104d7c;
      }
    }
  }
  uVar5 = 0xffffffea;
LAB_00104d7c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_coeff_num_put @ 00104de0 size=360
// signature: undefined lpass_cdc_rx_macro_fir_coeff_num_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_fir_coeff_num_put(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 *local_48;
  undefined1 auStack_40 [8];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = *(long *)(param_1 + 0x80);
  local_48 = (undefined8 *)0x0;
  bVar3 = *(byte *)(param_2 + 0x48);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar8 = (ulong)uVar2;
  if (lVar1 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_rx_macro_fir_coeff_num_put__rs,
                         "lpass_cdc_rx_macro_fir_coeff_num_put");
    if (iVar5 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_fir_coeff_num_put");
    }
  }
  else {
    uVar6 = lpass_cdc_rx_macro_get_data
                      (lVar1,auStack_40,&local_48,"lpass_cdc_rx_macro_fir_coeff_num_put");
    if ((uVar6 & 1) != 0) {
      if (bVar3 < 0xc9) {
        if (1 < uVar2) goto LAB_00104f40;
        iVar5 = *(int *)((long)local_48 + uVar8 * 8 + 0x69c);
        *(byte *)((long)local_48 + uVar8 + 0x54) = bVar3;
        if (*(int *)(local_48 + uVar8 + 0xd4) + iVar5 == (uint)bVar3) {
          uVar7 = set_fir_filter_coeff(lVar1,local_48,uVar8);
        }
        else {
          uVar7 = 0;
        }
      }
      else {
        iVar5 = ___ratelimit(lpass_cdc_rx_macro_fir_coeff_num_put__rs_307,
                             "lpass_cdc_rx_macro_fir_coeff_num_put");
        if (iVar5 != 0) {
          _dev_err(*local_48,"%s: inavlid total number of RX_FIR coefficients:%d in path:%d\n",
                   "lpass_cdc_rx_macro_fir_coeff_num_put",(uint)bVar3,uVar8);
        }
        if (1 < uVar2) {
LAB_00104f40:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104f44);
          (*pcVar4)();
        }
        uVar7 = 0xffffffea;
        *(undefined1 *)((long)local_48 + uVar8 + 0x54) = 0;
      }
      goto LAB_00104e8c;
    }
  }
  uVar7 = 0xffffffea;
LAB_00104e8c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_filter_enable_get @ 00104f4c size=188
// signature: undefined lpass_cdc_rx_macro_fir_filter_enable_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_fir_filter_enable_get(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  if (*(long *)(param_1 + 0x80) == 0) {
    iVar2 = ___ratelimit(lpass_cdc_rx_macro_fir_filter_enable_get__rs,
                         "lpass_cdc_rx_macro_fir_filter_enable_get");
    if (iVar2 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_fir_filter_enable_get");
    }
  }
  else {
    uVar3 = lpass_cdc_rx_macro_get_data
                      (*(long *)(param_1 + 0x80),auStack_30,&local_38,
                       "lpass_cdc_rx_macro_fir_filter_enable_get");
    if ((uVar3 & 1) != 0) {
      uVar4 = 0;
      *(undefined1 *)(param_2 + 0x48) = *(undefined1 *)(local_38 + 0x6ae);
      goto LAB_00104fc4;
    }
  }
  uVar4 = 0xffffffea;
LAB_00104fc4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_filter_enable_put @ 0010500c size=588
// signature: undefined lpass_cdc_rx_macro_fir_filter_enable_put(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_rx_macro_fir_filter_enable_put(long param_1,long param_2)

{
  char cVar1;
  undefined8 *puVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 *local_48;
  undefined1 auStack_40 [8];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x80);
  local_48 = (undefined8 *)0x0;
  if (lVar6 == 0) {
    iVar3 = ___ratelimit(lpass_cdc_rx_macro_fir_filter_enable_put__rs,
                         "lpass_cdc_rx_macro_fir_filter_enable_put");
    if (iVar3 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_fir_filter_enable_put");
      iVar3 = -0x16;
      goto LAB_001051d4;
    }
  }
  else {
    uVar5 = lpass_cdc_rx_macro_get_data
                      (lVar6,auStack_40,&local_48,"lpass_cdc_rx_macro_fir_filter_enable_put");
    puVar2 = local_48;
    if ((uVar5 & 1) != 0) {
      lVar8 = local_48[0x127];
      if ((lVar8 != 0) && (*(char *)((long)local_48 + 0x6af) != '\0')) {
        cVar1 = *(char *)(param_2 + 0x48);
        *(bool *)((long)local_48 + 0x6ae) = cVar1 != '\0';
        if (cVar1 == '\0') {
          snd_soc_component_update_bits(lVar6,0x145c,0xd,0);
          snd_soc_component_update_bits(lVar6,0x151c,0xd,0);
          snd_soc_component_update_bits(lVar6,0x1400,0x80,0);
          snd_soc_component_update_bits(lVar6,0x14c0,0x80,0);
          snd_soc_component_update_bits(lVar6,0x1004,1,0);
          uVar7 = puVar2[0x127];
          clk_disable(uVar7);
          clk_unprepare(uVar7);
        }
        else {
          iVar3 = clk_prepare(lVar8);
          if (iVar3 == 0) {
            iVar3 = clk_enable(lVar8);
            if (iVar3 != 0) {
              clk_unprepare(lVar8);
              goto LAB_001050ac;
            }
          }
          else {
LAB_001050ac:
            if (iVar3 < 0) {
              iVar4 = ___ratelimit(lpass_cdc_rx_macro_fir_filter_enable_put__rs_316,
                                   "lpass_cdc_rx_macro_fir_filter_enable_put");
              if (iVar4 != 0) {
                _dev_err(*puVar2,"%s:hifi_fir_clk enable failed\n",
                         "lpass_cdc_rx_macro_fir_filter_enable_put");
              }
              goto LAB_001051d4;
            }
          }
          snd_soc_component_write(lVar6,0x1460,*(undefined1 *)((long)puVar2 + 0x54));
          snd_soc_component_write(lVar6,0x1520,*(undefined1 *)((long)puVar2 + 0x55));
          snd_soc_component_update_bits(lVar6,0x1004,1,1);
          snd_soc_component_update_bits(lVar6,0x1400,0x80,0x80);
          snd_soc_component_update_bits(lVar6,0x14c0,0x80,0x80);
          snd_soc_component_update_bits(lVar6,0x145c,0xd,5);
          snd_soc_component_update_bits(lVar6,0x151c,0xd,5);
        }
      }
      iVar3 = 0;
      goto LAB_001051d4;
    }
  }
  iVar3 = -0x16;
LAB_001051d4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_hph_idle_detect_get @ 0010525c size=136
// signature: undefined lpass_cdc_rx_macro_hph_idle_detect_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_hph_idle_detect_get(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_rx_macro_hph_idle_detect_get");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_30 + 0x839);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_hph_idle_detect_put @ 001052e8 size=136
// signature: undefined lpass_cdc_rx_macro_hph_idle_detect_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_hph_idle_detect_put(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_rx_macro_hph_idle_detect_put");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(char *)(local_30 + 0x839) = (char)*(undefined8 *)(param_2 + 0x48);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_ear_mode @ 00105374 size=136
// signature: undefined lpass_cdc_rx_macro_get_ear_mode(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_get_ear_mode(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_get_ear_mode");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_38 + 0x6ad);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_put_ear_mode @ 00105400 size=144
// signature: undefined lpass_cdc_rx_macro_put_ear_mode(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_put_ear_mode(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_put_ear_mode");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(bool *)(local_38 + 0x6ad) = *(long *)(param_2 + 0x48) != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_hph_hd2_mode @ 00105494 size=136
// signature: undefined lpass_cdc_rx_macro_get_hph_hd2_mode(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_get_hph_hd2_mode(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_get_hph_hd2_mode");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_38 + 0x6b3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_put_hph_hd2_mode @ 00105520 size=144
// signature: undefined lpass_cdc_rx_macro_put_hph_hd2_mode(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_put_hph_hd2_mode(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_put_hph_hd2_mode");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(bool *)(local_38 + 0x6b3) = *(long *)(param_2 + 0x48) != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_hph_pwr_mode @ 001055b4 size=136
// signature: undefined lpass_cdc_rx_macro_get_hph_pwr_mode(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_get_hph_pwr_mode(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_get_hph_pwr_mode");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_38 + 0x6b2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_put_hph_pwr_mode @ 00105640 size=144
// signature: undefined lpass_cdc_rx_macro_put_hph_pwr_mode(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_put_hph_pwr_mode(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_put_hph_pwr_mode");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(bool *)(local_38 + 0x6b2) = *(long *)(param_2 + 0x48) != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_get @ 001056d4 size=64
// signature: undefined lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_get(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0x80),0x1284);
  *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 >> 2 & 1);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_put @ 00105718 size=60
// signature: undefined lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_put(long param_1,long param_2)

{
  snd_soc_component_update_bits
            (*(undefined8 *)(param_1 + 0x80),0x1284,4,(ulong)(*(long *)(param_2 + 0x48) != 0) << 2);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_soft_clip_enable_get @ 00105758 size=136
// signature: undefined lpass_cdc_rx_macro_soft_clip_enable_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_soft_clip_enable_get(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_soft_clip_enable_get");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(long *)(param_2 + 0x48) = (long)*(int *)(local_38 + 0x924);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_soft_clip_enable_put @ 001057e4 size=136
// signature: undefined lpass_cdc_rx_macro_soft_clip_enable_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_soft_clip_enable_put(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_soft_clip_enable_put");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(int *)(local_38 + 0x924) = (int)*(undefined8 *)(param_2 + 0x48);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_aux_hpf_mode_get @ 00105870 size=136
// signature: undefined lpass_cdc_rx_macro_aux_hpf_mode_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_aux_hpf_mode_get(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_aux_hpf_mode_get");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(long *)(param_2 + 0x48) = (long)*(int *)(local_38 + 0x928);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_aux_hpf_mode_put @ 001058fc size=136
// signature: undefined lpass_cdc_rx_macro_aux_hpf_mode_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_aux_hpf_mode_put(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_30,&local_38,
                     "lpass_cdc_rx_macro_aux_hpf_mode_put");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(int *)(local_38 + 0x928) = (int)*(undefined8 *)(param_2 + 0x48);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_iir_enable_audio_mixer_get @ 00105988 size=88
// signature: undefined lpass_cdc_rx_macro_iir_enable_audio_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_iir_enable_audio_mixer_get(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar2 = snd_soc_component_read
                    (*(undefined8 *)(param_1 + 0x80),
                     *(int *)(*(long *)(param_1 + 0x78) + 0x10) * 0x80 + 0x1a24U & 0xfffc);
  *(ulong *)(param_2 + 0x48) = (uVar2 & 0xffffffff) >> ((ulong)uVar1 & 0x3f) & 1;
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_iir_enable_audio_mixer_put @ 001059e4 size=692
// signature: undefined lpass_cdc_rx_macro_iir_enable_audio_mixer_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_iir_enable_audio_mixer_put(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  long *local_68;
  undefined1 auStack_60 [8];
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  uVar10 = *(undefined8 *)(param_1 + 0x80);
  local_68 = (long *)0x0;
  uVar11 = *(undefined8 *)(param_2 + 0x48);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x10);
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar8 = lpass_cdc_rx_macro_get_data
                    (uVar10,auStack_60,&local_68,"lpass_cdc_rx_macro_iir_enable_audio_mixer_put");
  plVar5 = local_68;
  if ((uVar8 & 1) == 0) {
    uVar10 = 0xffffffea;
  }
  else {
    iVar3 = uVar1 * 0x80;
    lVar9 = dev_get_regmap(*(undefined8 *)(*local_68 + 0x60),0);
    if (lVar9 == 0) {
      iVar7 = ___ratelimit(lpass_cdc_rx_macro_restore_iir_coeff__rs,
                           "lpass_cdc_rx_macro_restore_iir_coeff");
      if (iVar7 != 0) {
        _dev_err(*plVar5,"%s: regmap is NULL\n","lpass_cdc_rx_macro_restore_iir_coeff");
      }
    }
    else {
      regmap_write(lVar9,iVar3 + 0x1a2c,uVar2 * 0x14 & 0x7c);
      if ((1 < uVar1) || (4 < uVar2)) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x105c98);
        (*pcVar6)();
      }
      lVar4 = (ulong)uVar2 * 0x14 + (ulong)uVar1 * 100;
      uVar1 = iVar3 + 0x1a30U & 0xffb0;
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x83a));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x83b));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x83c));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x83d));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x83e));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x83f));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x840));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x841));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x842));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x843));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x844));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x845));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x846));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x847));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x848));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x849));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x84a));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x84b));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x84c));
      regmap_write(lVar9,uVar1,*(undefined1 *)((long)plVar5 + lVar4 + 0x84d));
    }
    uVar1 = iVar3 + 0x1a24U & 0xffa4;
    snd_soc_component_update_bits
              (uVar10,uVar1,1 << (ulong)(uVar2 & 0x1f),(int)uVar11 << (ulong)(uVar2 & 0x1f));
    snd_soc_component_read(uVar10,uVar1);
    uVar10 = 0;
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_iir_filter_info @ 00105c9c size=28
// signature: undefined lpass_cdc_rx_macro_iir_filter_info(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_iir_filter_info(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x78);
  *(undefined4 *)(param_2 + 0x40) = 4;
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(lVar1 + 8);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_iir_band_audio_mixer_get @ 00105cbc size=380
// signature: undefined lpass_cdc_rx_macro_iir_band_audio_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_iir_band_audio_mixer_get(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined8 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  long lVar10;
  uint local_80 [6];
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = 0;
  piVar4 = *(int **)(param_1 + 0x78);
  uVar5 = *(undefined8 *)(param_1 + 0x80);
  local_80[4] = 0;
  local_80[2] = 0;
  local_80[3] = 0;
  local_80[0] = 0;
  local_80[1] = 0;
  iVar3 = piVar4[1];
  iVar1 = *piVar4 * 0x80 + 0x1a2c;
  iVar2 = *piVar4 * 0x80 + 0x1a30;
  do {
    uVar9 = iVar3 * 0x14 + (int)lVar10 & 0x7c;
    snd_soc_component_write(uVar5,iVar1,uVar9);
    uVar6 = snd_soc_component_read(uVar5,iVar2);
    snd_soc_component_write(uVar5,iVar1,uVar9 | 1);
    iVar7 = snd_soc_component_read(uVar5,iVar2);
    snd_soc_component_write(uVar5,iVar1,uVar9 | 2);
    iVar8 = snd_soc_component_read(uVar5,iVar2);
    snd_soc_component_write(uVar5,iVar1,uVar9 | 3);
    uVar9 = snd_soc_component_read(uVar5,iVar2);
    *(uint *)((long)local_80 + lVar10) = uVar6 | iVar7 << 8 | iVar8 << 0x10 | (uVar9 & 0x3f) << 0x18
    ;
    lVar10 = lVar10 + 4;
  } while (lVar10 != 0x14);
  if ((uint)piVar4[2] < 0x15) {
    memcpy((void *)(param_2 + 0x48),local_80,(long)piVar4[2]);
    lVar10 = sp_el0;
    if (*(long *)(lVar10 + 0x638) == local_68) {
      return 0;
    }
  }
  else {
    fortify_panic("memcpy");
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_iir_band_audio_mixer_put @ 00105e3c size=380
// signature: undefined lpass_cdc_rx_macro_iir_band_audio_mixer_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_iir_band_audio_mixer_put(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  undefined1 auVar12 [16];
  long local_80;
  undefined1 auStack_78 [8];
  uint local_70 [6];
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  puVar3 = *(uint **)(param_1 + 0x78);
  uVar9 = *(undefined8 *)(param_1 + 0x80);
  local_70[4] = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_80 = 0;
  uVar4 = *puVar3;
  uVar5 = puVar3[1];
  uVar8 = lpass_cdc_rx_macro_get_data
                    (uVar9,auStack_78,&local_80,"lpass_cdc_rx_macro_iir_band_audio_mixer_put");
  if ((uVar8 & 1) == 0) {
    uVar9 = 0xffffffea;
  }
  else {
    if (0x14 < puVar3[2]) {
      fortify_panic("memcpy");
      auVar12 = func_0x067fdd4c();
      lVar10 = *(long *)(auVar12._0_8_ + 0x78);
      *(undefined4 *)(auVar12._8_8_ + 0x40) = 4;
      *(undefined4 *)(auVar12._8_8_ + 0x48) = *(undefined4 *)(lVar10 + 8);
      return 0;
    }
    memcpy(local_70,(void *)(param_2 + 0x48),(long)(int)puVar3[2]);
    snd_soc_component_write(uVar9,uVar4 * 0x80 + 0x1a2c,uVar5 * 0x14 & 0x7c);
    iVar2 = uVar4 * 0x80 + 0x1a30;
    lVar10 = (long)(int)uVar5 * 0x14 + (long)(int)uVar4 * 100 + local_80;
    lVar11 = 0;
    do {
      uVar6 = *(uint *)((long)local_70 + lVar11);
      snd_soc_component_write(uVar9,iVar2,uVar6 & 0xff);
      snd_soc_component_write(uVar9,iVar2,uVar6 >> 8 & 0xff);
      snd_soc_component_write(uVar9,iVar2,uVar6 >> 0x10 & 0xff);
      snd_soc_component_write(uVar9,iVar2,uVar6 >> 0x18 & 0x3f);
      if (1 < uVar4 || 4 < uVar5) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x105fa8);
        (*pcVar7)();
      }
      lVar1 = lVar11 + 4;
      *(uint *)(lVar10 + 0x83a + lVar11) = uVar6;
      lVar11 = lVar1;
    } while (lVar1 != 0x14);
    uVar9 = 0;
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return uVar9;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_filter_info @ 00105fbc size=28
// signature: undefined lpass_cdc_rx_macro_fir_filter_info(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rx_macro_fir_filter_info(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x78);
  *(undefined4 *)(param_2 + 0x40) = 4;
  *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(lVar1 + 8);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_audio_mixer_get @ 00105fdc size=476
// signature: undefined lpass_cdc_rx_macro_fir_audio_mixer_get(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001061b0) */

void lpass_cdc_rx_macro_fir_audio_mixer_get(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  char *pcVar8;
  size_t __n;
  ulong uVar9;
  long lVar10;
  undefined8 *local_1f0;
  undefined1 auStack_1e8 [12];
  uint local_1dc;
  undefined4 local_1d8 [100];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x80);
  uVar1 = **(uint **)(param_1 + 0x78);
  uVar2 = (*(uint **)(param_1 + 0x78))[1];
  uVar9 = (ulong)uVar2;
  memset(local_1d8,0,400);
  local_1f0 = (undefined8 *)0x0;
  if (lVar3 == 0) {
    iVar5 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_get__rs,
                         "lpass_cdc_rx_macro_fir_audio_mixer_get");
    if (iVar5 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_fir_audio_mixer_get");
    }
  }
  else {
    uVar6 = lpass_cdc_rx_macro_get_data
                      (lVar3,auStack_1e8,&local_1f0,"lpass_cdc_rx_macro_fir_audio_mixer_get");
    if ((uVar6 & 1) != 0) {
      if (uVar1 < 2) {
        if (uVar2 < 2) {
          local_1dc = *(uint *)((long)local_1f0 + uVar9 * 4 + (ulong)uVar1 * 8 + 0x69c);
          if (local_1dc == 0) {
            __n = 4;
          }
          else {
            lVar3 = 0;
            do {
              lVar10 = lVar3;
              if (lVar10 == 400) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1061b0);
                (*pcVar4)();
              }
              *(undefined4 *)((long)local_1d8 + lVar10) =
                   *(undefined4 *)
                    ((long)local_1f0 + lVar10 + (ulong)uVar2 * 400 + (ulong)uVar1 * 800 + 0x5c);
              lVar3 = lVar10 + 4;
            } while ((ulong)local_1dc * 4 != lVar10 + 4);
            __n = lVar10 + 8;
          }
          memcpy((void *)(param_2 + 0x48),&local_1dc,__n);
          uVar7 = 0;
          goto LAB_001060a0;
        }
        iVar5 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_get__rs_326,
                             "lpass_cdc_rx_macro_fir_audio_mixer_get");
        if (iVar5 != 0) {
          pcVar8 = "%s: grp_idx:%d is invalid\n";
          goto LAB_00106108;
        }
      }
      else {
        iVar5 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_get__rs_325,
                             "lpass_cdc_rx_macro_fir_audio_mixer_get");
        if (iVar5 != 0) {
          pcVar8 = "%s: path_idx:%d is invalid\n";
          uVar9 = (ulong)uVar1;
LAB_00106108:
          _dev_err(*local_1f0,pcVar8,"lpass_cdc_rx_macro_fir_audio_mixer_get",uVar9);
        }
      }
    }
  }
  uVar7 = 0xffffffea;
LAB_001060a0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_fir_audio_mixer_put @ 001061bc size=652
// signature: undefined lpass_cdc_rx_macro_fir_audio_mixer_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_fir_audio_mixer_put(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  uint uVar5;
  byte bVar6;
  undefined8 *puVar7;
  code *pcVar8;
  int iVar9;
  ulong uVar10;
  undefined8 uVar11;
  char *pcVar12;
  ulong uVar13;
  size_t sVar14;
  undefined8 *local_210;
  undefined1 auStack_208 [12];
  uint local_1fc;
  undefined4 local_1f8 [100];
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x80);
  uVar1 = **(uint **)(param_1 + 0x78);
  uVar13 = (ulong)uVar1;
  uVar2 = (*(uint **)(param_1 + 0x78))[1];
  uVar3 = (ulong)uVar2;
  memset(local_1f8,0,400);
  local_210 = (undefined8 *)0x0;
  if (lVar4 == 0) {
    iVar9 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_put__rs,
                         "lpass_cdc_rx_macro_fir_audio_mixer_put");
    if (iVar9 != 0) {
      _printk(&DAT_0011a858,"lpass_cdc_rx_macro_fir_audio_mixer_put");
    }
  }
  else {
    uVar10 = lpass_cdc_rx_macro_get_data
                       (lVar4,auStack_208,&local_210,"lpass_cdc_rx_macro_fir_audio_mixer_put");
    puVar7 = local_210;
    if ((uVar10 & 1) != 0) {
      if (uVar1 < 2) {
        if (uVar2 < 2) {
          if ((local_210[0x127] == 0) || (*(char *)((long)local_210 + 0x6af) == '\0')) {
            uVar11 = 0;
          }
          else {
            uVar5 = *(uint *)(param_2 + 0x48);
            local_1fc = uVar5;
            if (uVar5 < 0x65) {
              *(uint *)((long)local_210 + uVar3 * 4 + uVar13 * 8 + 0x69c) = uVar5;
              memcpy(local_1f8,(void *)(param_2 + 0x4c),(ulong)uVar5 * 4);
              if (uVar5 != 0) {
                sVar14 = 0;
                do {
                  if (sVar14 == 400) {
                    /* WARNING: Does not return */
                    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x106448);
                    (*pcVar8)();
                  }
                  *(undefined4 *)
                   ((long)puVar7 + sVar14 + (ulong)uVar2 * 400 + (ulong)uVar1 * 800 + 0x5c) =
                       *(undefined4 *)((long)local_1f8 + sVar14);
                  sVar14 = sVar14 + 4;
                } while ((ulong)uVar5 * 4 != sVar14);
              }
              uVar11 = 0;
              bVar6 = *(byte *)((long)puVar7 + uVar13 + 0x54);
              *(undefined1 *)((long)puVar7 + uVar3 + uVar13 * 2 + 0x56) = 0;
              if (*(int *)(puVar7 + uVar13 + 0xd4) + *(int *)((long)puVar7 + uVar13 * 8 + 0x69c) ==
                  (uint)bVar6) {
                uVar11 = set_fir_filter_coeff(lVar4,puVar7,uVar1);
              }
            }
            else {
              iVar9 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_put__rs_332,
                                   "lpass_cdc_rx_macro_fir_audio_mixer_put");
              if (iVar9 != 0) {
                _dev_err(*puVar7,
                         "%s: inavlid number of RX_FIR coefficients:%d in path:%d, group:%d\n",
                         "lpass_cdc_rx_macro_fir_audio_mixer_put",uVar5,uVar1,uVar2);
              }
              uVar11 = 0xffffffea;
              *(undefined4 *)((long)puVar7 + uVar3 * 4 + uVar13 * 8 + 0x69c) = 0;
            }
          }
          goto LAB_00106288;
        }
        iVar9 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_put__rs_330,
                             "lpass_cdc_rx_macro_fir_audio_mixer_put");
        if (iVar9 != 0) {
          pcVar12 = "%s: grp_idx:%d is invalid\n";
          uVar13 = (ulong)uVar2;
          goto LAB_001062f8;
        }
      }
      else {
        iVar9 = ___ratelimit(lpass_cdc_rx_macro_fir_audio_mixer_put__rs_329,
                             "lpass_cdc_rx_macro_fir_audio_mixer_put");
        if (iVar9 != 0) {
          pcVar12 = "%s: path_idx:%d is invalid\n";
LAB_001062f8:
          _dev_err(*local_210,pcVar12,"lpass_cdc_rx_macro_fir_audio_mixer_put",uVar13);
        }
      }
    }
  }
  uVar11 = 0xffffffea;
LAB_00106288:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// set_fir_filter_coeff @ 00106448 size=1272
// signature: undefined set_fir_filter_coeff(void)
// callers: [lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_fir_coeff_num_put]
//------------------------------------------------------------

int set_fir_filter_coeff(undefined8 param_1,undefined8 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined8 uVar10;
  ulong uVar11;
  undefined4 uVar12;
  long lVar13;
  undefined8 uVar14;
  uint *puVar15;
  uint *puVar16;
  ulong uVar17;
  ulong uVar18;
  int iVar19;
  int iVar20;
  
  if (param_3 == 0) {
    uVar8 = 0x1464;
    uVar6 = 0x1468;
    uVar14 = 0x145c;
    uVar12 = 0x1400;
  }
  else {
    if (param_3 != 1) {
      iVar5 = ___ratelimit(set_fir_filter_coeff__rs,"set_fir_filter_coeff");
      if (iVar5 == 0) {
        return -0x16;
      }
      _dev_err(*param_2,"%s: inavlid FIR ID: %d\n","set_fir_filter_coeff",param_3);
      return -0x16;
    }
    uVar14 = 0x151c;
    uVar8 = 0x1524;
    uVar6 = 0x1528;
    uVar12 = 0x14c0;
  }
  uVar17 = (ulong)param_3;
  if ((*(char *)((long)param_2 + (ulong)param_3 * 2 + 0x56) == '\0') ||
     (*(char *)((long)param_2 + uVar17 * 2 + 0x57) == '\0')) {
    lpass_cdc_rx_macro_mclk_enable(param_2,1);
    uVar10 = param_2[0x127];
    iVar5 = clk_prepare(uVar10);
    if ((iVar5 == 0) && (iVar5 = clk_enable(uVar10), iVar5 != 0)) {
      clk_unprepare(uVar10);
    }
    snd_soc_component_update_bits(param_1,0x1004,1,1);
    snd_soc_component_update_bits(param_1,uVar12,0xc0,0xc0);
    snd_soc_component_update_bits(param_1,uVar12,0xc0,0x80);
    usleep_range_state(10,0xb,2);
    lVar13 = 0;
    iVar19 = 0;
    uVar18 = 0;
    puVar15 = (uint *)(param_2 + uVar17 * 100 + 0xc);
    do {
      pcVar9 = (char *)((long)param_2 + uVar18 + uVar17 * 2 + 0x56);
      if (*pcVar9 == '\0') {
        uVar1 = *(uint *)((long)param_2 + uVar18 * 4 + uVar17 * 8 + 0x69c);
        if (100 < uVar1) {
          iVar5 = ___ratelimit(set_fir_filter_coeff__rs_314,"set_fir_filter_coeff");
          if (iVar5 != 0) {
            _dev_err(*param_2,"%s: inavlid number of RX_FIR coefficients:%d in path:%d, group:%d\n",
                     "set_fir_filter_coeff",uVar1,param_3,uVar18 & 0xffffffff);
          }
          iVar5 = -0x16;
          break;
        }
        uVar7 = uVar18 * 100;
        uVar3 = (uVar1 & 0xfffffffe) + (int)uVar18 * 100;
        if (uVar7 < uVar3) {
          uVar11 = 0;
          puVar16 = puVar15;
          iVar20 = iVar19;
          do {
            if (99 < uVar11) goto LAB_0010693c;
            uVar2 = puVar16[-1];
            snd_soc_component_write(param_1,uVar6,uVar2 & 0xff);
            snd_soc_component_write(param_1,uVar6 | 4,uVar2 >> 8 & 0xff);
            snd_soc_component_write(param_1,uVar6 + 8,uVar2 >> 0x10 & 0xff);
            snd_soc_component_write(param_1,uVar6 + 0xc,uVar2 >> 0x18);
            uVar2 = *puVar16;
            uVar11 = uVar11 + 2;
            snd_soc_component_write(param_1,uVar6 | 0x10,uVar2 & 0xff);
            snd_soc_component_write(param_1,uVar6 | 0x14,uVar2 >> 8 & 0xff);
            snd_soc_component_write(param_1,uVar6 + 0x18,uVar2 >> 0x10 & 0xff);
            snd_soc_component_write(param_1,uVar6 + 0x1c,uVar2 >> 0x18);
            snd_soc_component_write(param_1,uVar8,iVar20);
            snd_soc_component_update_bits(param_1,uVar14,2,2);
            usleep_range_state(0xd,0xf,2);
            snd_soc_component_update_bits(param_1,uVar14,2,0);
            iVar20 = iVar20 + 1;
            puVar16 = puVar16 + 2;
          } while ((int)lVar13 + (uint)uVar11 < uVar3);
          if ((uVar1 & 1) != 0) {
            if (99 < (uint)uVar11) {
LAB_0010693c:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x106940);
              (*pcVar4)();
            }
            uVar7 = lVar13 + uVar11;
            goto LAB_001065c0;
          }
        }
        else if ((uVar1 & 1) != 0) {
          uVar11 = 0;
LAB_001065c0:
          uVar1 = *(uint *)((long)param_2 +
                           (uVar11 & 0xffffffff) * 4 + uVar18 * 400 + uVar17 * 800 + 0x5c);
          snd_soc_component_write(param_1,uVar6,uVar1 & 0xff);
          snd_soc_component_write(param_1,uVar6 | 4,uVar1 >> 8 & 0xff);
          snd_soc_component_write(param_1,uVar6 + 8,uVar1 >> 0x10 & 0xff);
          snd_soc_component_write(param_1,uVar6 + 0xc,uVar1 >> 0x18);
          snd_soc_component_write(param_1,uVar6 | 0x10,0);
          snd_soc_component_write(param_1,uVar6 | 0x14,0);
          snd_soc_component_write(param_1,uVar6 + 0x18,0);
          snd_soc_component_write(param_1,uVar6 + 0x1c,0);
          snd_soc_component_write(param_1,uVar8,(int)uVar7 >> 1);
          snd_soc_component_update_bits(param_1,uVar14,2,2);
          usleep_range_state(0xd,0xf,2);
          snd_soc_component_update_bits(param_1,uVar14,2,0);
        }
        *pcVar9 = '\x01';
      }
      uVar18 = uVar18 + 1;
      iVar19 = iVar19 + 0x32;
      puVar15 = puVar15 + 100;
      lVar13 = lVar13 + 100;
    } while (uVar18 != 2);
    snd_soc_component_update_bits(param_1,uVar12,0x80,0);
    snd_soc_component_update_bits(param_1,0x1004,1,0);
    uVar14 = param_2[0x127];
    clk_disable(uVar14);
    clk_unprepare(uVar14);
    lpass_cdc_rx_macro_mclk_enable(param_2,0);
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_get_channel_map @ 00106944 size=532
// signature: undefined lpass_cdc_rx_macro_get_channel_map(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_get_channel_map
               (long param_1,uint *param_2,uint *param_3,undefined4 *param_4,uint *param_5)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  code *pcVar4;
  bool bVar5;
  bool bVar6;
  ulong uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 uVar11;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  uVar11 = *(undefined8 *)(param_1 + 0x58);
  local_58 = 0;
  local_50 = 0;
  uVar7 = lpass_cdc_rx_macro_get_data
                    (uVar11,&local_50,&local_58,"lpass_cdc_rx_macro_get_channel_map");
  if ((uVar7 & 1) == 0) {
    uVar11 = 0xffffffea;
  }
  else {
    switch(*(uint *)(param_1 + 8)) {
    case 1:
    case 2:
    case 3:
    case 4:
      uVar10 = *(ulong *)(local_58 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x798);
      uVar2 = (uVar10 & 0x2a) >> 1 | (uVar10 & 0x15) << 1;
      uVar7 = 6;
      if ((uVar10 & 0x3f) != 0) {
        uVar7 = LZCOUNT(((uVar2 & 0x3333333333333333) >> 2 |
                        ((uVar2 & 0xcccccccccccccccc) >> 2 | (uVar2 & 0x303030303030303) << 2) << 4)
                        << 0x38);
      }
      if ((uint)uVar7 < 6) {
        uVar8 = 1 << (ulong)((uint)uVar7 & 0x1f);
        if (uVar7 < 5) {
          uVar1 = (uint)(-2L << (uVar7 & 0x3f)) & (uint)uVar10;
          uVar2 = ((ulong)uVar1 & 0x2a) >> 1;
          uVar7 = uVar2 | ((ulong)uVar1 & 0x14) << 1;
          uVar9 = 6;
          if ((uVar1 & 0x3e) != 0) {
            uVar9 = (uint)LZCOUNT(((uVar7 & 0x3333333333333333) >> 2 |
                                  ((uVar7 & 0xcccccccccccccccc) >> 2 |
                                  (uVar2 & 0x303030303030303) << 2) << 4) << 0x38);
          }
          if (uVar9 < 6) {
            uVar8 = 1 << (ulong)(uVar9 & 0x1f) | uVar8;
          }
        }
      }
      else {
        uVar8 = 0;
      }
      if ((uVar8 & 0xc) != 0) {
        uVar8 = uVar8 >> 2;
      }
      if ((uVar8 & 0x30) != 0) {
        uVar8 = 1;
      }
      *param_5 = uVar8;
      if (7 < *(uint *)(param_1 + 8)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x106b58);
        (*pcVar4)();
      }
      uVar11 = 0;
      *param_4 = (int)*(undefined8 *)(local_58 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x7d8);
      break;
    case 5:
      uVar7 = snd_soc_component_read(uVar11,0x1198);
      bVar5 = (uVar7 & 0xf0) != 0;
      uVar8 = 1;
      if (bVar5) {
        uVar8 = 2;
      }
      bVar6 = (uVar7 & 0xf) != 0;
      uVar1 = (uint)bVar5;
      if (bVar6) {
        uVar1 = bVar5 | 2;
      }
      uVar9 = (uint)bVar5;
      if (bVar6) {
        uVar9 = uVar8;
      }
      uVar7 = snd_soc_component_read(uVar11,0x119c);
      uVar8 = uVar1 | 4;
      if ((uVar7 & 0xf) == 0) {
        uVar8 = uVar1;
      }
      else {
        uVar9 = uVar9 + 1;
      }
      uVar11 = 0;
      *param_3 = uVar8;
      *param_2 = uVar9;
      break;
    case 6:
    case 7:
      uVar11 = 0;
      *param_5 = 1;
      *param_4 = 1;
      break;
    default:
      uVar11 = ___ratelimit(lpass_cdc_rx_macro_get_channel_map__rs,
                            "lpass_cdc_rx_macro_get_channel_map");
      if ((int)uVar11 != 0) {
        _dev_err(local_50,"%s: Invalid AIF\n","lpass_cdc_rx_macro_get_channel_map");
        uVar11 = 0;
      }
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_rx_macro_hw_params @ 00106b5c size=1368
// signature: undefined lpass_cdc_rx_macro_hw_params(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_rx_macro_hw_params(long param_1,long param_2,long param_3)

{
  long lVar1;
  undefined1 uVar2;
  code *pcVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined1 uVar11;
  long lVar12;
  long local_98;
  undefined1 auStack_90 [8];
  long local_88;
  undefined1 auStack_80 [8];
  long local_78;
  undefined1 auStack_70 [8];
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_98 = 0;
  uVar8 = lpass_cdc_rx_macro_get_data
                    (*(undefined8 *)(param_3 + 0x58),auStack_90,&local_98,
                     "lpass_cdc_rx_macro_hw_params");
  if ((uVar8 & 1) != 0) {
    if (*(int *)(param_1 + 0x3c) != 0) {
      uVar9 = 0;
      goto LAB_00107058;
    }
    lVar12 = *(long *)(param_3 + 0x58);
    iVar7 = *(int *)(param_2 + 0x128);
    local_88 = 0;
    uVar8 = lpass_cdc_rx_macro_get_data
                      (lVar12,auStack_80,&local_88,"lpass_cdc_rx_macro_set_interpolator_rate");
    if ((uVar8 & 1) != 0) {
      if (iVar7 < 0x15888) {
        if (iVar7 < 32000) {
          if (iVar7 == 8000) {
            lVar12 = 0;
          }
          else {
            if (iVar7 != 16000) {
LAB_00107020:
              _dev_err(*(undefined8 *)(lVar12 + 0x18),"%s: Unsupported sample rate: %d\n",
                       "lpass_cdc_rx_macro_set_interpolator_rate",iVar7);
              goto LAB_0010703c;
            }
            lVar12 = 1;
          }
        }
        else if (iVar7 == 32000) {
          lVar12 = 2;
        }
        else {
          if (iVar7 == 0xac44) {
            uVar11 = 1;
            lVar12 = 7;
            goto LAB_00106d20;
          }
          if (iVar7 != 48000) goto LAB_00107020;
          lVar12 = 3;
        }
LAB_00106d1c:
        uVar11 = 0;
      }
      else {
        if (0x2edff < iVar7) {
          if (iVar7 == 0x2ee00) {
            lVar12 = 5;
          }
          else {
            if (iVar7 == 0x56220) {
              uVar11 = 1;
              lVar12 = 10;
              goto LAB_00106d20;
            }
            if (iVar7 != 0x5dc00) goto LAB_00107020;
            lVar12 = 6;
          }
          goto LAB_00106d1c;
        }
        if (iVar7 == 0x15888) {
          uVar11 = 1;
          lVar12 = 8;
        }
        else {
          if (iVar7 == 96000) {
            lVar12 = 4;
            goto LAB_00106d1c;
          }
          if (iVar7 != 0x2b110) goto LAB_00107020;
          uVar11 = 1;
          lVar12 = 9;
        }
      }
LAB_00106d20:
      uVar2 = sr_val_tbl[lVar12 * 8 + 4];
      *(undefined1 *)(local_88 + 0x6ac) = uVar11;
      uVar9 = *(undefined8 *)(param_3 + 0x58);
      local_78 = 0;
      uVar8 = lpass_cdc_rx_macro_get_data
                        (uVar9,auStack_70,&local_78,"lpass_cdc_rx_macro_set_prim_interpolator_rate")
      ;
      lVar12 = local_78;
      if ((uVar8 & 1) != 0) {
        uVar10 = *(uint *)(param_3 + 8);
        if (uVar10 < 9) {
          uVar8 = 0;
          do {
            if (5 < uVar8) {
LAB_00106eb8:
              uVar9 = *(undefined8 *)(param_3 + 0x58);
              local_78 = 0;
              uVar8 = lpass_cdc_rx_macro_get_data
                                (uVar9,auStack_70,&local_78,
                                 "lpass_cdc_rx_macro_set_mix_interpolator_rate");
              lVar12 = local_78;
              if ((uVar8 & 1) == 0) goto LAB_0010703c;
              uVar10 = *(uint *)(param_3 + 8);
              if (uVar10 < 9) {
                uVar8 = 0;
                goto LAB_00106f0c;
              }
              break;
            }
            uVar10 = (uint)(-1L << (uVar8 & 0x3f)) & *(uint *)(lVar12 + (ulong)uVar10 * 8 + 0x798);
            uVar8 = ((ulong)uVar10 & 0x2a) >> 1 | ((ulong)uVar10 & 0x15) << 1;
            lVar1 = 6;
            if ((uVar10 & 0x3f) != 0) {
              lVar1 = LZCOUNT(((uVar8 & 0x3333333333333333) >> 2 |
                              ((uVar8 & 0xcccccccccccccccc) >> 2 | (uVar8 & 0x303030303030303) << 2)
                              << 4) << 0x38);
            }
            if (5 < (uint)lVar1) goto LAB_00106eb8;
            uVar10 = (uint)lVar1 + 5;
            uVar5 = snd_soc_component_read(uVar9,0x1180);
            uVar6 = snd_soc_component_read(uVar9,0x1184);
            if (((uVar5 & 0xf) == uVar10 || (uVar5 >> 4 & 0xf) == uVar10) ||
                (uVar6 >> 4 & 0xf) == uVar10) {
              snd_soc_component_update_bits(uVar9,0x1400,0xf,uVar2);
            }
            uVar5 = snd_soc_component_read(uVar9,0x1188);
            uVar6 = snd_soc_component_read(uVar9,0x118c);
            if ((((uVar5 & 0xf) == uVar10) || ((uVar5 >> 4 & 0xf) == uVar10)) ||
               ((uVar6 >> 4 & 0xf) == uVar10)) {
              snd_soc_component_update_bits(uVar9,0x14c0,0xf,uVar2);
            }
            uVar5 = snd_soc_component_read(uVar9,0x1190);
            uVar6 = snd_soc_component_read(uVar9,0x1194);
            if ((((uVar5 & 0xf) == uVar10) || ((uVar5 >> 4 & 0xf) == uVar10)) ||
               ((uVar6 >> 4 & 0xf) == uVar10)) {
              snd_soc_component_update_bits(uVar9,0x1580,0xf,uVar2);
            }
            uVar10 = *(uint *)(param_3 + 8);
            uVar8 = lVar1 + 1;
          } while (uVar10 < 9);
        }
LAB_001070ac:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1070b0);
        (*pcVar3)();
      }
    }
LAB_0010703c:
    iVar7 = ___ratelimit(lpass_cdc_rx_macro_hw_params__rs,"lpass_cdc_rx_macro_hw_params");
    if (iVar7 != 0) {
      _printk(&DAT_0011af4c,"lpass_cdc_rx_macro_hw_params",*(undefined4 *)(param_2 + 0x128));
    }
  }
  uVar9 = 0xffffffea;
LAB_00107058:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
  while( true ) {
    uVar10 = (uint)(-1L << (uVar8 & 0x3f)) & *(uint *)(lVar12 + (ulong)uVar10 * 8 + 0x798);
    uVar8 = ((ulong)uVar10 & 0x2a) >> 1 | ((ulong)uVar10 & 0x15) << 1;
    lVar1 = 6;
    if ((uVar10 & 0x3f) != 0) {
      lVar1 = LZCOUNT(((uVar8 & 0x3333333333333333) >> 2 |
                      ((uVar8 & 0xcccccccccccccccc) >> 2 | (uVar8 & 0x303030303030303) << 2) << 4)
                      << 0x38);
    }
    if (5 < (uint)lVar1) goto LAB_00106fc8;
    uVar10 = (uint)lVar1 + 1;
    uVar5 = snd_soc_component_read(uVar9,0x1184);
    if ((uVar5 & 0xf) == uVar10) {
      snd_soc_component_update_bits(uVar9,0x1418,0xf,uVar2);
    }
    uVar5 = snd_soc_component_read(uVar9,0x118c);
    if ((uVar5 & 0xf) == uVar10) {
      snd_soc_component_update_bits(uVar9,0x14d8,0xf,uVar2);
    }
    uVar5 = snd_soc_component_read(uVar9,0x1194);
    if ((uVar5 & 0xf) == uVar10) {
      snd_soc_component_update_bits(uVar9,0x1598,0xf,uVar2);
    }
    uVar10 = *(uint *)(param_3 + 8);
    uVar8 = lVar1 + 1;
    if (8 < uVar10) break;
LAB_00106f0c:
    if (5 < uVar8) {
LAB_00106fc8:
      uVar10 = *(uint *)(param_2 + 0x24);
      if (uVar10 == 0) {
        uVar10 = *(uint *)(param_2 + 0x28);
        if (uVar10 != 0) {
          uVar5 = 0x20;
          goto LAB_00106fe4;
        }
        uVar5 = 0;
      }
      else {
        uVar5 = 0;
LAB_00106fe4:
        uVar10 = (uVar10 & 0xaaaaaaaa) >> 1 | (uVar10 & 0x55555555) << 1;
        uVar10 = (uVar10 & 0xcccccccc) >> 2 | (uVar10 & 0x33333333) << 2;
        uVar10 = (uVar10 & 0xf0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f) << 4;
        uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
        uVar5 = (uint)LZCOUNT(uVar10 >> 0x10 | uVar10 << 0x10) | uVar5;
      }
      uVar4 = snd_pcm_format_width(uVar5);
      if (*(uint *)(param_3 + 8) < 8) {
        uVar9 = 0;
        *(undefined2 *)(local_98 + (ulong)*(uint *)(param_3 + 8) * 2 + 0x818) = uVar4;
        goto LAB_00107058;
      }
      break;
    }
  }
  goto LAB_001070ac;
}



//------------------------------------------------------------
// init_module @ 001070dc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpass_cdc_rx_macro_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010710c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpass_cdc_rx_macro_driver);
  return;
}



//------------------------------------------------------------
// ___ratelimit @ 0011d000 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_macro_mux_put, set_fir_filter_coeff, lpass_cdc_rx_set_fir_capability, lpass_cdc_rx_macro_enable_vbat, lpass_cdc_rx_macro_core_vote, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_get_data, lpass_cdc_rx_macro_fir_filter_enable_get, lpass_cdc_rx_macro_mclk_event, lpass_cdc_rx_macro_fir_coeff_num_get, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_get_channel_map, lpass_cdc_rx_macro_fir_coeff_num_put, rx_swrm_clock, lpass_cdc_rx_macro_enable_echo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011d008 size=1
// signature: undefined _printk(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_set_fir_capability, lpass_cdc_rx_macro_core_vote, lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_fir_filter_enable_get, lpass_cdc_rx_macro_fir_coeff_num_get, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_add_child_devices, lpass_cdc_rx_macro_fir_coeff_num_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011d010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_cdc_rx_macro_hph_idle_detect_get, lpass_cdc_rx_macro_put_hph_hd2_mode, lpass_cdc_rx_macro_put_pcm_path, lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_macro_iir_band_audio_mixer_put, lpass_cdc_rx_macro_mux_put, lpass_cdc_rx_macro_enable_vbat, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_set_compander, lpass_cdc_rx_macro_get_pcm_path, lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_get_hph_hd2_mode, lpass_cdc_rx_macro_fir_filter_enable_get, lpass_cdc_rx_macro_mclk_event, lpass_cdc_rx_macro_get_compander, lpass_cdc_rx_macro_hph_idle_detect_put, lpass_cdc_rx_macro_set_port_map, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_get_channel_map, lpass_cdc_rx_macro_aux_hpf_mode_get, lpass_cdc_rx_macro_aux_hpf_mode_put, lpass_cdc_rx_macro_enable_echo, lpass_cdc_rx_macro_get_ear_mode, lpass_cdc_rx_set_fir_capability, lpass_cdc_rx_macro_put_ear_mode, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_iir_band_audio_mixer_get, lpass_cdc_rx_macro_put_hph_pwr_mode, lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_fir_coeff_num_get, lpass_cdc_rx_macro_add_child_devices, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_get_hph_pwr_mode, lpass_cdc_rx_macro_deinit, lpass_cdc_rx_macro_mux_get, lpass_cdc_rx_macro_soft_clip_enable_get, lpass_cdc_rx_macro_fir_coeff_num_put, lpass_cdc_rx_macro_probe, lpass_cdc_rx_macro_set_idle_detect_thr, lpass_cdc_rx_macro_soft_clip_enable_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_device_ptr @ 0011d018 size=1
// signature: undefined lpass_cdc_get_device_ptr(void)
// callers: [lpass_cdc_rx_macro_get_data, lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_device_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0011d020 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_macro_mux_put, set_fir_filter_coeff, lpass_cdc_rx_macro_enable_vbat, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_get_data, lpass_cdc_rx_macro_mclk_event, lpass_cdc_rx_macro_fir_coeff_num_get, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_add_child_devices, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_get_channel_map, lpass_cdc_rx_macro_init, lpass_cdc_rx_macro_fir_coeff_num_put, lpass_cdc_rx_macro_probe, rx_swrm_clock, lpass_cdc_rx_macro_enable_echo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0011d028 size=1
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
// platform_driver_unregister @ 0011d030 size=1
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
// lpass_cdc_is_va_macro_registered @ 0011d038 size=1
// signature: undefined lpass_cdc_is_va_macro_registered(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_is_va_macro_registered(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0011d040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0011d048 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011d050 size=1
// signature: undefined of_find_property(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0011d058 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0011d060 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_set_wakeup_capable @ 0011d068 size=1
// signature: undefined msm_cdc_pinctrl_set_wakeup_capable(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0011d070 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0011d078 size=1
// signature: undefined devm_clk_get(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011d080 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_register_macro @ 0011d088 size=1
// signature: undefined lpass_cdc_register_macro(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_register_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0011d090 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0011d098 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0011d0a0 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpass_cdc_rx_macro_remove, lpass_cdc_rx_macro_probe, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0011d0a8 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpass_cdc_rx_macro_probe, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0011d0b8 size=1
// signature: undefined queue_work_on(void)
// callers: [lpass_cdc_rx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 0011d0c0 size=1
// signature: undefined platform_device_unregister(void)
// callers: [lpass_cdc_rx_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0011d0c8 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpass_cdc_rx_macro_remove, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_unregister_macro @ 0011d0d0 size=1
// signature: undefined lpass_cdc_unregister_macro(void)
// callers: [lpass_cdc_rx_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_unregister_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011d0d8 size=1
// signature: undefined kfree(void)
// callers: [lpass_cdc_rx_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0011d0e0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0011d0e8 size=1
// signature: undefined strnstr(void)
// callers: [lpass_cdc_rx_macro_add_child_devices, lpass_cdc_rx_macro_set_iir_gain]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0011d0f0 size=1
// signature: size_t strlen(char * __s)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0011d0f8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_macro_fir_audio_mixer_put, lpass_cdc_rx_macro_iir_band_audio_mixer_put, lpass_cdc_rx_macro_add_child_devices, lpass_cdc_rx_macro_iir_band_audio_mixer_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 0011d100 size=1
// signature: undefined platform_device_alloc(void)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add_data @ 0011d108 size=1
// signature: undefined platform_device_add_data(void)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 0011d110 size=1
// signature: undefined krealloc(void)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 0011d118 size=1
// signature: undefined platform_device_add(void)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 0011d120 size=1
// signature: undefined platform_device_put(void)
// callers: [lpass_cdc_rx_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 0011d128 size=1
// signature: undefined dev_get_regmap(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, rx_swrm_clock]
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
// callers: [lpass_cdc_rx_macro_mclk_enable, rx_swrm_clock]
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
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_core_vote, rx_swrm_clock, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0011d140 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_core_vote, rx_swrm_clock, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0011d148 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_core_vote, rx_swrm_clock, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0011d150 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [rx_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0011d158 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, rx_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0011d160 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [rx_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011d168 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, rx_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_check_core_votes @ 0011d170 size=1
// signature: undefined lpass_cdc_check_core_votes(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_core_vote, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_check_core_votes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_request_clock @ 0011d178 size=1
// signature: undefined lpass_cdc_clk_rsc_request_clock(void)
// callers: [lpass_cdc_rx_macro_mclk_enable, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_request_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_fs_gen_request @ 0011d180 size=1
// signature: undefined lpass_cdc_clk_rsc_fs_gen_request(void)
// callers: [lpass_cdc_rx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_fs_gen_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0011d188 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [lpass_cdc_rx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync_region @ 0011d190 size=1
// signature: undefined regcache_sync_region(void)
// callers: [lpass_cdc_rx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 0011d198 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 0011d1a0 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_widgets @ 0011d1a8 size=1
// signature: undefined snd_soc_dapm_new_widgets(void)
// callers: [lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_widgets(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 0011d1b0 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0011d1b8 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0011d1c0 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [lpass_cdc_rx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0011d1c8 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [lpass_cdc_rx_macro_int_dem_inp_mux_put, set_fir_filter_coeff, lpass_cdc_rx_macro_enable_vbat, lpass_cdc_rx_macro_enable_rx_path_clk, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_config_classh, lpass_cdc_rx_macro_hphdelay_lutbypass, lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_put, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_config_compander, lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_init, lpass_cdc_rx_macro_config_softclip, lpass_cdc_rx_macro_enable_echo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swrm_wcd_notify @ 0011d1d0 size=1
// signature: undefined swrm_wcd_notify(void)
// callers: [lpass_cdc_rx_macro_mclk_event, lpass_cdc_rx_macro_set_port_map, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swrm_wcd_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_runtime_suspend @ 0011d1d8 size=1
// signature: undefined lpass_cdc_runtime_suspend(void)
// callers: [lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_rsc_clk_reset @ 0011d1e0 size=1
// signature: undefined lpass_cdc_rsc_clk_reset(void)
// callers: [lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_rsc_clk_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0011d1e8 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [lpass_cdc_rx_macro_set_iir_gain, lpass_cdc_rx_macro_iir_enable_audio_mixer_put, lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_iir_band_audio_mixer_get, lpass_cdc_rx_macro_event_handler, lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_iir_enable_audio_mixer_get, lpass_cdc_rx_macro_hw_params, lpass_cdc_rx_macro_vbat_bcl_gsm_mode_func_get, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_get_channel_map, lpass_cdc_rx_macro_enable_echo, lpass_cdc_rx_macro_set_idle_detect_thr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0011d1f0 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [lpass_cdc_rx_macro_enable_main_path, lpass_cdc_rx_macro_iir_band_audio_mixer_put, set_fir_filter_coeff, lpass_cdc_rx_macro_set_iir_gain, lpass_cdc_rx_macro_enable_mix_path, lpass_cdc_rx_macro_enable_interp_clk, lpass_cdc_rx_macro_fir_filter_enable_put, lpass_cdc_rx_macro_set_idle_detect_thr, lpass_cdc_rx_macro_iir_band_audio_mixer_get, lpass_cdc_rx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0011d1f8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [lpass_cdc_rx_macro_enable_echo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_kcontrol_widget @ 0011d200 size=1
// signature: undefined snd_soc_dapm_kcontrol_widget(void)
// callers: [lpass_cdc_rx_macro_int_dem_inp_mux_put, lpass_cdc_rx_macro_mux_put, lpass_cdc_rx_macro_mux_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_kcontrol_widget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mux_update_power @ 0011d210 size=1
// signature: undefined snd_soc_dapm_mux_update_power(void)
// callers: [lpass_cdc_rx_macro_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mux_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_put_enum_double @ 0011d218 size=1
// signature: undefined snd_soc_dapm_put_enum_double(void)
// callers: [lpass_cdc_rx_macro_int_dem_inp_mux_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_put_enum_double(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_notify_wcd_rx_clk @ 0011d220 size=1
// signature: undefined lpass_cdc_notify_wcd_rx_clk(void)
// callers: [lpass_cdc_rx_macro_enable_interp_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_notify_wcd_rx_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_load_compander_coeff @ 0011d228 size=1
// signature: undefined lpass_cdc_load_compander_coeff(void)
// callers: [lpass_cdc_rx_macro_config_compander]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_load_compander_coeff(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_update_compander_setting @ 0011d230 size=1
// signature: undefined lpass_cdc_update_compander_setting(void)
// callers: [lpass_cdc_rx_macro_config_compander]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_update_compander_setting(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0011d238 size=1
// signature: undefined clk_prepare(void)
// callers: [set_fir_filter_coeff, lpass_cdc_rx_macro_fir_filter_enable_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0011d240 size=1
// signature: undefined clk_enable(void)
// callers: [set_fir_filter_coeff, lpass_cdc_rx_macro_fir_filter_enable_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0011d248 size=1
// signature: undefined clk_unprepare(void)
// callers: [set_fir_filter_coeff, lpass_cdc_rx_macro_fir_filter_enable_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0011d250 size=1
// signature: undefined clk_disable(void)
// callers: [set_fir_filter_coeff, lpass_cdc_rx_macro_fir_filter_enable_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 0011d258 size=1
// signature: undefined regmap_write(void)
// callers: [lpass_cdc_rx_macro_iir_enable_audio_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0011d260 size=1
// signature: undefined fortify_panic(void)
// callers: [lpass_cdc_rx_macro_iir_band_audio_mixer_put, lpass_cdc_rx_macro_iir_band_audio_mixer_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0011d268 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [lpass_cdc_rx_macro_fir_audio_mixer_get, lpass_cdc_rx_macro_fir_audio_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0011d270 size=1
// signature: undefined usleep_range_state(void)
// callers: [set_fir_filter_coeff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 0011d278 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [lpass_cdc_rx_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



