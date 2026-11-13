// Decompiled by Ghidra 12.2
// Program: wcd9378_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd9378_get_micb_vout_ctl_val @ 0010184c size=84
// signature: undefined wcd9378_get_micb_vout_ctl_val(void)
// callers: []
//------------------------------------------------------------

uint wcd9378_get_micb_vout_ctl_val(int param_1)

{
  if (param_1 - 0xb23U < 0xfffff8c5) {
    _printk(&DAT_00154e17,"wcd9378_get_micb_vout_ctl_val");
    return 0xffffffea;
  }
  return (param_1 - 1000U >> 1 & 0x7fff) / 0x19;
}



//------------------------------------------------------------
// wcd9378_mbhc_micb_adjust_voltage @ 001018a4 size=296
// signature: undefined wcd9378_mbhc_micb_adjust_voltage(void)
// callers: [wcd9378_mbhc_micb_ctrl_threshold_mic]
//------------------------------------------------------------

undefined8 wcd9378_mbhc_micb_adjust_voltage(long param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_1 + 0x18);
  lVar5 = *(long *)(lVar2 + 0x98);
  if (lVar5 == 0) {
    _dev_err(lVar2,"%s: wcd9378 private data is NULL\n","wcd9378_mbhc_micb_adjust_voltage");
    uVar4 = 0xffffffea;
  }
  else {
    if (param_3 - 1U < 3) {
      uVar4 = 0xff;
      uVar3 = *(undefined4 *)(&DAT_00113518 + (long)(int)(param_3 - 1U) * 4);
    }
    else {
      _dev_err(lVar2,"%s: wcd9378 private data is NULL\n","wcd9378_mbhc_micb_adjust_voltage");
      uVar3 = 0;
      uVar4 = 0;
    }
    mutex_lock(lVar5 + 0x88);
    uVar1 = wcd9378_micb_usage_value_convert(param_1,param_2,param_3);
    snd_soc_component_update_bits(param_1,uVar3,uVar4,uVar1);
    if (param_3 == 2) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: sj micbias set\n",
               "wcd9378_mbhc_micb_adjust_voltage");
      snd_soc_component_update_bits(param_1,0x40c00798,0xff,uVar1);
      *(undefined4 *)(lVar5 + 0x160) = param_2;
    }
    mutex_unlock(lVar5 + 0x88);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd9378_micb_usage_value_convert @ 001019cc size=372
// signature: undefined wcd9378_micb_usage_value_convert(void)
// callers: [wcd9378_mbhc_micb_adjust_voltage]
//------------------------------------------------------------

undefined8 wcd9378_micb_usage_value_convert(undefined8 param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  uint uVar2;
  
  if (param_2 < 0x9c4) {
    if (param_2 < 0x708) {
      if (param_2 == 0) {
        return 1;
      }
      if (param_2 == 0x4b0) {
        return 2;
      }
    }
    else {
      if (param_2 == 0x708) {
        return 3;
      }
      if (param_2 == 0x898) {
        return 0xf0;
      }
    }
  }
  else if (param_2 < 0xabe) {
    if (param_2 == 0x9c4) {
      return 4;
    }
    if (param_2 == 0xa8c) {
      return 0xf1;
    }
  }
  else {
    if (param_2 == 0xabe) {
      return 5;
    }
    if (param_2 == 0xaf0) {
      return 0xf2;
    }
  }
  if (param_2 - 0xb23U < 0xfffff8c5) {
    _printk(&DAT_00154e17,"wcd9378_get_micb_vout_ctl_val");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = (param_2 - 1000U >> 1 & 0x7fff) / 0x19;
  }
  if (param_3 == 3) {
    snd_soc_component_update_bits(param_1,0x401805a5,0xff,uVar2);
    uVar1 = 0xf5;
  }
  else if (param_3 == 2) {
    snd_soc_component_update_bits(param_1,0x401805a4,0xff,uVar2);
    uVar1 = 0xf4;
  }
  else if (param_3 == 1) {
    snd_soc_component_update_bits(param_1,0x401805a3,0xff,uVar2);
    uVar1 = 0xf3;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd9378_disable_bcs_before_slow_insert @ 00101b44 size=84
// signature: undefined wcd9378_disable_bcs_before_slow_insert(void)
// callers: [wcd9378_mbhc_bcs_enable]
//------------------------------------------------------------

void wcd9378_disable_bcs_before_slow_insert(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  pcVar1 = *(code **)(lVar2 + 0xc90);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101b88);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(lVar2 + 0xc88),5,(param_2 ^ 0xffffffff) & 1);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_soc_get_mbhc @ 00101b9c size=136
// signature: undefined wcd9378_soc_get_mbhc(void)
// callers: [wcd9378_get_hph_type, wcd9378_hph_impedance_get]
//------------------------------------------------------------

undefined8 wcd9378_soc_get_mbhc(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(&wcd9378_soc_get_mbhc__rs,"wcd9378_soc_get_mbhc");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_001551c2;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      return *(undefined8 *)(lVar3 + 0x150);
    }
    iVar1 = ___ratelimit(wcd9378_soc_get_mbhc__rs_4,"wcd9378_soc_get_mbhc");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_001542a4;
  }
  _printk(puVar2,"wcd9378_soc_get_mbhc");
  return 0;
}



//------------------------------------------------------------
// wcd9378_micbias_control @ 00101c28 size=1104
// signature: undefined wcd9378_micbias_control(void)
// callers: [wcd9378_mbhc_request_micbias, wcd9378_codec_enable_micbias_pullup, wcd9378_codec_enable_micbias]
//------------------------------------------------------------

undefined8 wcd9378_micbias_control(long param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  bool bVar2;
  long lVar3;
  char *pcVar4;
  undefined4 *puVar5;
  ulong uVar6;
  int iVar7;
  int *piVar8;
  long *plVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_6c;
  uint local_68;
  
  lVar3 = *(long *)(param_1 + 0x18);
  plVar9 = *(long **)(lVar3 + 0x98);
  lVar10 = *(long *)(*plVar9 + 0x90);
  if (param_2 == 3) {
    local_88 = 0;
    uVar12 = 0;
    local_68 = 0;
    local_80 = 0;
    local_78 = 0;
    puVar5 = (undefined4 *)(lVar10 + 0x34);
    uVar11 = 4;
    bVar2 = true;
    local_6c = 0x41800098;
  }
  else if (param_2 == 2) {
    bVar2 = false;
    puVar5 = (undefined4 *)(lVar10 + 0x30);
    uVar12 = 4;
    uVar11 = 2;
    local_6c = 0x41400098;
    local_88 = 2;
    local_68 = 1;
    local_80 = 8;
    local_78 = 6;
  }
  else {
    if (param_2 != 1) {
      pcVar4 = "%s: Invalid micbias number: %d\n";
      goto LAB_0010206c;
    }
    local_88 = 0;
    uVar12 = 0;
    local_68 = 0;
    bVar2 = true;
    local_80 = 0;
    local_78 = 0;
    uVar11 = 1;
    local_6c = 0x41000098;
    puVar5 = (undefined4 *)(lVar10 + 0x2c);
  }
  uVar1 = *puVar5;
  mutex_lock(plVar9 + 0x11);
  if (3 < param_3) {
    lVar3 = *(long *)(param_1 + 0x18);
    pcVar4 = "%s: Invalid req event: %d\n";
    param_2 = param_3;
LAB_0010206c:
    _dev_err(lVar3,pcVar4,"wcd9378_micbias_control",param_2);
    return 0xffffffea;
  }
  uVar6 = (ulong)(param_2 - 1);
  switch(param_3) {
  case 0:
    iVar7 = *(int *)((long)plVar9 + uVar6 * 4 + 0x54);
    *(int *)((long)plVar9 + uVar6 * 4 + 0x54) = iVar7 + 1;
    if ((iVar7 == 0) && (*(int *)((long)plVar9 + uVar6 * 4 + 0x48) == 0)) {
      snd_soc_component_update_bits(param_1,0x401805b3,uVar11,uVar11);
      snd_soc_component_update_bits(param_1,local_6c,0xff,uVar1);
      if (param_2 == 2) {
        snd_soc_component_update_bits(param_1,0x40c00798,0xff,uVar1);
        *(undefined4 *)(plVar9 + 0x2c) = *(undefined4 *)(lVar10 + 0x24);
      }
    }
    goto LAB_00101f2c;
  case 1:
    piVar8 = (int *)((long)plVar9 + uVar6 * 4 + 0x54);
    iVar7 = *piVar8;
    if (0 < iVar7) {
      *piVar8 = iVar7 + -1;
      iVar7 = iVar7 + -1;
    }
    if (((iVar7 == 0) && (*(int *)((long)plVar9 + uVar6 * 4 + 0x48) == 0)) &&
       (snd_soc_component_update_bits(param_1,local_6c,0xff,1), param_2 == 2)) {
      snd_soc_component_update_bits(param_1,0x40c00798,0xff,1);
      *(undefined4 *)(plVar9 + 0x2c) = 0;
    }
    goto LAB_00101f2c;
  case 2:
    iVar7 = *(int *)((long)plVar9 + uVar6 * 4 + 0x48);
    *(int *)((long)plVar9 + uVar6 * 4 + 0x48) = iVar7 + 1;
    if (iVar7 == 0) {
      snd_soc_component_update_bits(param_1,local_6c,0xff,uVar1);
      if (param_2 == 2) {
        snd_soc_component_update_bits(param_1,0x40180024,0x1c,0xc);
        snd_soc_component_update_bits(param_1,0x40180024,0x80,0);
        snd_soc_component_update_bits(param_1,0x40c00798,0xff,uVar1);
        *(undefined4 *)(plVar9 + 0x2c) = *(undefined4 *)(lVar10 + 0x24);
      }
      if (!bVar2) {
        blocking_notifier_call_chain(plVar9[0x2a] + 0x428,uVar12);
      }
    }
    if (((local_68 & param_4) != 1) || (lVar3 = plVar9[0x2a], lVar3 == 0)) goto LAB_00101f2c;
    local_78 = local_80;
    break;
  case 3:
    piVar8 = (int *)((long)plVar9 + uVar6 * 4 + 0x48);
    iVar7 = *piVar8;
    if (0 < iVar7) {
      *piVar8 = iVar7 + -1;
      iVar7 = iVar7 + -1;
    }
    if (iVar7 == 0) {
      iVar7 = *(int *)((long)plVar9 + uVar6 * 4 + 0x54);
      if (iVar7 < 1) {
        if (iVar7 == 0) {
          if ((!bVar2) && (plVar9[0x2a] != 0)) {
            blocking_notifier_call_chain(plVar9[0x2a] + 0x428,1);
          }
          snd_soc_component_update_bits(param_1,local_6c,0xff,0);
          if (param_2 == 2) {
            snd_soc_component_update_bits(param_1,0x40c00798,0xff,0);
            snd_soc_component_update_bits(param_1,0x40180024,0x1c,0xc);
            snd_soc_component_update_bits(param_1,0x40180024,0x80,0x80);
            *(undefined4 *)(plVar9 + 0x2c) = 0;
          }
          if ((!bVar2) && (plVar9[0x2a] != 0)) {
            blocking_notifier_call_chain(plVar9[0x2a] + 0x428,local_88);
          }
        }
      }
      else {
        snd_soc_component_update_bits(param_1,0x401805b3,uVar11,uVar11);
        if (param_2 == 2) {
          *(undefined4 *)(plVar9 + 0x2c) = *(undefined4 *)(lVar10 + 0x24);
        }
      }
    }
    if (((local_68 & param_4) != 1) || (lVar3 = plVar9[0x2a], lVar3 == 0)) goto LAB_00101f2c;
  }
  blocking_notifier_call_chain(lVar3 + 0x428,local_78);
LAB_00101f2c:
  mutex_unlock(plVar9 + 0x11);
  return 0;
}



//------------------------------------------------------------
// wcd9378_swr_dmic_register_notifier @ 0010207c size=124
// signature: undefined wcd9378_swr_dmic_register_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_swr_dmic_register_notifier(long param_1,undefined8 param_2,byte param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd9378_swr_dmic_register_notifier__rs,"wcd9378_swr_dmic_register_notifier"
                        );
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      _printk(&DAT_00153e01,"wcd9378_swr_dmic_register_notifier");
      uVar2 = 0xffffffea;
    }
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    *(byte *)(lVar3 + 0xcda) = param_3 & 1;
    if ((param_3 & 1) == 0) {
      uVar2 = blocking_notifier_chain_unregister(lVar3 + 0xce0);
    }
    else {
      uVar2 = blocking_notifier_chain_register();
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_codec_get_dev_num @ 001020fc size=80
// signature: undefined wcd9378_codec_get_dev_num(void)
// callers: []
//------------------------------------------------------------

ulong wcd9378_codec_get_dev_num(long param_1)

{
  long lVar1;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if ((lVar1 != 0) && (lVar1 = *(long *)(lVar1 + 0x38), lVar1 != 0)) {
      return (ulong)*(byte *)(lVar1 + 0x40);
    }
    _printk(&DAT_00153e01,"wcd9378_codec_get_dev_num");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_info_create_codec_entry @ 00102150 size=220
// signature: undefined wcd9378_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_info_create_codec_entry(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (*(long *)(lVar5 + 0xcb0) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),"wcd9378");
      *(long *)(lVar5 + 0xcb0) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0xcb0));
        if ((-1 < iVar1) &&
           (lVar3 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"version",
                               *(undefined8 *)(lVar5 + 0xcb0)), lVar3 != 0)) {
          *(long *)(lVar3 + 0x40) = lVar5;
          *(undefined8 *)(lVar3 + 0x10) = 0x20;
          *(undefined2 *)(lVar3 + 0x18) = 1;
          *(undefined1 **)(lVar3 + 0x20) = wcd9378_info_ops;
          iVar1 = snd_info_register();
          if (-1 < iVar1) {
            *(long *)(lVar5 + 0xcb8) = lVar3;
            return 0;
          }
          snd_info_free_entry(lVar3);
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0xcb0));
      }
      uVar2 = 0xfffffff4;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_populate_dt_data @ 00102230 size=852
// signature: undefined wcd9378_populate_dt_data(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

ulong * wcd9378_populate_dt_data(long param_1)

{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong local_88 [11];
  
  lVar5 = sp_el0;
  local_88[10] = *(long *)(lVar5 + 0x638);
  puVar3 = (ulong *)devm_kmalloc(param_1,0x50,0xdc0);
  if (puVar3 != (ulong *)0x0) {
    local_88[8] = 0;
    local_88[9] = 0;
    local_88[6] = 0;
    local_88[7] = 0;
    local_88[4] = 0;
    local_88[5] = 0;
    local_88[2] = 0;
    local_88[3] = 0;
    local_88[0] = 0;
    local_88[1] = 0;
    iVar2 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2e8),"qcom,wcd-rst-gpio-node",0,0,0,local_88);
    uVar1 = local_88[0];
    if (iVar2 != 0) {
      uVar1 = 0;
    }
    *puVar3 = uVar1;
    if (uVar1 == 0) {
      _dev_err(param_1,"%s: Looking up %s property in node %s failed\n","wcd9378_populate_dt_data",
               "qcom,wcd-rst-gpio-node",*(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
      puVar3 = (ulong *)0x0;
    }
    else {
      msm_cdc_get_power_supplies(param_1,puVar3 + 8,puVar3 + 9);
      if ((puVar3[8] == 0) || ((int)puVar3[9] < 1)) {
        _dev_err(param_1,"%s: no power supplies defined for codec\n","wcd9378_populate_dt_data");
        puVar3 = (ulong *)0x0;
      }
      else {
        local_88[8] = 0;
        local_88[9] = 0;
        local_88[6] = 0;
        local_88[7] = 0;
        local_88[4] = 0;
        local_88[5] = 0;
        local_88[2] = 0;
        local_88[3] = 0;
        local_88[0] = 0;
        local_88[1] = 0;
        iVar2 = __of_parse_phandle_with_args
                          (*(undefined8 *)(param_1 + 0x2e8),"qcom,rx-slave",0,0,0,local_88);
        uVar4 = *(undefined8 *)(param_1 + 0x2e8);
        if (iVar2 != 0) {
          local_88[0] = 0;
        }
        local_88[8] = 0;
        local_88[9] = 0;
        local_88[6] = 0;
        local_88[7] = 0;
        local_88[4] = 0;
        local_88[5] = 0;
        puVar3[1] = local_88[0];
        local_88[2] = 0;
        local_88[3] = 0;
        local_88[0] = 0;
        local_88[1] = 0;
        iVar2 = __of_parse_phandle_with_args(uVar4,"qcom,tx-slave",0,0,0,local_88);
        uVar4 = *(undefined8 *)(param_1 + 0x2e8);
        uVar1 = local_88[0];
        if (iVar2 != 0) {
          uVar1 = 0;
        }
        local_88[0] = local_88[0] & 0xffffffff00000000;
        puVar3[2] = uVar1;
        lVar5 = of_find_property(uVar4,"qcom,cdc-micbias1-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias1 DT property not found\n","wcd9378_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias1-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd9378_read_of_property_u32","qcom,cdc-micbias1-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)(puVar3 + 4) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias2-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias2 DT property not found\n","wcd9378_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias2-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd9378_read_of_property_u32","qcom,cdc-micbias2-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)((long)puVar3 + 0x24) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias3-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias3 DT property not found\n","wcd9378_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias3-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd9378_read_of_property_u32","qcom,cdc-micbias3-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)(puVar3 + 5) = (undefined4)local_88[0];
          }
        }
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar3;
}



//------------------------------------------------------------
// wcd9378_version_read @ 00102588 size=196
// signature: undefined wcd9378_version_read(void)
// callers: []
//------------------------------------------------------------

void wcd9378_version_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  uStack_48 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_40 = 0;
  local_50 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    _printk(&DAT_00153bae,"wcd9378_version_read");
    uVar4 = 0xffffffffffffffea;
  }
  else {
    pcVar1 = "WCD9378_1_0\n";
    if (*(int *)(*(long *)(param_1 + 0x40) + 0xca8) != 1) {
      pcVar1 = "VER_UNDEFINED\n";
    }
    iVar3 = scnprintf(&uStack_48,0x20,pcVar1);
    uVar4 = simple_read_from_buffer(param_4,param_5,&local_50,&uStack_48,(long)iVar3);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_probe @ 00102650 size=2052
// signature: undefined wcd9378_probe(void)
// callers: []
//------------------------------------------------------------

uint wcd9378_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long *plVar8;
  undefined4 *puVar9;
  char *pcVar10;
  char *pcVar11;
  long *plVar12;
  long lVar13;
  undefined8 uVar14;
  long lVar15;
  undefined8 local_b0;
  ulong local_a8 [11];
  
  lVar13 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_a8[10] = *(long *)(lVar13 + 0x638);
  local_b0 = 0;
  plVar7 = (long *)devm_kmalloc(lVar1,0xd28,0xdc0);
  if (plVar7 == (long *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_00102e14;
  }
  *(long **)(param_1 + 0xa8) = plVar7;
  *plVar7 = lVar1;
  plVar8 = (long *)wcd9378_populate_dt_data(lVar1);
  if (plVar8 == (long *)0x0) {
    pcVar10 = "%s: Fail to obtain platform data\n";
    goto LAB_00102d0c;
  }
  *(long **)(param_1 + 0xa0) = plVar8;
  plVar7[5] = *plVar8;
  uVar4 = msm_cdc_init_supplies(lVar1,plVar7 + 0x18d,plVar8[8],(int)plVar8[9]);
  if (plVar7[0x18d] == 0) {
    pcVar10 = "%s: Cannot init wcd supplies\n";
LAB_00102d30:
    _dev_err(lVar1,pcVar10,"wcd9378_probe");
    goto LAB_00102e14;
  }
  plVar12 = *(long **)(*(long *)(param_1 + 0x70) + 0x90);
  if (plVar12 == (long *)0x0) {
    pcVar10 = "%s: platform data from parent is NULL\n";
  }
  else {
    lVar13 = *plVar12;
    plVar7[0x191] = lVar13;
    if (lVar13 == 0) {
      pcVar10 = "%s: handle is NULL\n";
    }
    else {
      lVar13 = plVar12[1];
      plVar7[0x192] = lVar13;
      if (lVar13 == 0) {
        pcVar10 = "%s: update_wcd_event api is null!\n";
      }
      else {
        lVar13 = plVar12[2];
        plVar7[0x193] = lVar13;
        if (lVar13 != 0) {
          iVar5 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,wcd-mode",plVar7 + 3,1,0);
          if (iVar5 < 0) {
            *(undefined4 *)(plVar7 + 3) = 1;
          }
          uVar4 = msm_cdc_enable_static_supplies(lVar1,plVar7[0x18d],plVar8[8],(int)plVar8[9]);
          if (uVar4 != 0) {
            pcVar10 = "%s: wcd static supply enable failed!\n";
            goto LAB_00102d30;
          }
          uVar6 = wcd9378_parse_port_mapping(lVar1,"qcom,rx_swr_ch_map",1);
          uVar4 = wcd9378_parse_port_mapping(lVar1,"qcom,tx_swr_ch_map",0);
          uVar4 = uVar4 | uVar6;
          if (uVar4 == 0) {
            lVar15 = *(long *)(param_1 + 0xa8);
            local_a8[0] = local_a8[0] & 0xffffffff00000000;
            lVar13 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-tx-port-params",
                                      local_a8);
            uVar2 = local_a8[0];
            if (lVar13 == 0) {
              pcVar10 = "missing port mapping prop %s\n";
              pcVar11 = "qcom,swr-tx-port-params";
LAB_00102d74:
              _dev_err(lVar1,pcVar10,pcVar11);
              uVar4 = 0xffffffea;
            }
            else {
              uVar6 = (uint)local_a8[0];
              if (((uint)local_a8[0] & 0xffffffe0) != 0x80) {
                pcVar10 = "%s: port params not provided for all usecases\n";
                pcVar11 = "wcd9378_parse_port_params";
                goto LAB_00102d74;
              }
              puVar9 = (undefined4 *)__kmalloc(local_a8[0] & 0xffffffff,0xdc0);
              if (puVar9 == (undefined4 *)0x0) {
                uVar4 = 0xfffffff4;
              }
              else {
                uVar4 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-tx-port-params",puVar9
                                   ,0x20,0);
                if (-1 < (int)uVar4) {
                  if (3 < uVar6) {
                    *(undefined4 *)(lVar15 + 0xbc4) = *puVar9;
                    if (((((((uVar2 & 0xfffffffc) != 4) &&
                           (*(undefined4 *)(lVar15 + 0xbc8) = puVar9[1], 7 < uVar6)) &&
                          ((uVar2 & 0xfffffffc) != 8)) &&
                         ((*(undefined4 *)(lVar15 + 0xbcc) = puVar9[2], 0xb < uVar6 &&
                          ((uVar2 & 0xfffffffc) != 0xc)))) &&
                        (((*(undefined4 *)(lVar15 + 0xbd0) = puVar9[3], 0xf < uVar6 &&
                          (((uVar2 & 0xfffffffc) != 0x10 &&
                           (*(undefined4 *)(lVar15 + 0xbd4) = puVar9[4], 0x13 < uVar6)))) &&
                         ((uVar2 & 0xfffffffc) != 0x14)))) &&
                       ((((*(undefined4 *)(lVar15 + 0xbd8) = puVar9[5], 0x17 < uVar6 &&
                          ((uVar2 & 0xfffffffc) != 0x18)) &&
                         (*(undefined4 *)(lVar15 + 0xbdc) = puVar9[6], 0x1b < uVar6)) &&
                        ((uVar2 & 0xfffffffc) != 0x1c)))) {
                      *(undefined4 *)(lVar15 + 0xbe0) = puVar9[7];
                      *(long *)(lVar15 + 0xc48) = lVar15 + 0xbc4;
                      if (((((0x1f < uVar6) && ((uVar2 & 0xfffffffc) != 0x20)) &&
                           ((*(undefined4 *)(lVar15 + 0xbe4) = puVar9[8], 0x23 < uVar6 &&
                            (((uVar2 & 0xfffffffc) != 0x24 &&
                             (*(undefined4 *)(lVar15 + 0xbe8) = puVar9[9], 0x27 < uVar6)))))) &&
                          ((((uVar2 & 0xfffffffc) != 0x28 &&
                            (((*(undefined4 *)(lVar15 + 0xbec) = puVar9[10], 0x2b < uVar6 &&
                              ((uVar2 & 0xfffffffc) != 0x2c)) &&
                             (*(undefined4 *)(lVar15 + 0xbf0) = puVar9[0xb], 0x2f < uVar6)))) &&
                           ((((uVar2 & 0xfffffffc) != 0x30 &&
                             (*(undefined4 *)(lVar15 + 0xbf4) = puVar9[0xc], 0x33 < uVar6)) &&
                            (((uVar2 & 0xfffffffc) != 0x34 &&
                             ((*(undefined4 *)(lVar15 + 0xbf8) = puVar9[0xd], 0x37 < uVar6 &&
                              ((uVar2 & 0xfffffffc) != 0x38)))))))))) &&
                         ((*(undefined4 *)(lVar15 + 0xbfc) = puVar9[0xe], 0x3b < uVar6 &&
                          ((uVar2 & 0xfffffffc) != 0x3c)))) {
                        *(undefined4 *)(lVar15 + 0xc00) = puVar9[0xf];
                        *(long *)(lVar15 + 0xc50) = lVar15 + 0xbe4;
                        if (((((((0x3f < uVar6) && ((uVar2 & 0xfffffffc) != 0x40)) &&
                               (*(undefined4 *)(lVar15 + 0xc04) = puVar9[0x10], 0x43 < uVar6)) &&
                              (((uVar2 & 0xfffffffc) != 0x44 &&
                               (*(undefined4 *)(lVar15 + 0xc08) = puVar9[0x11], 0x47 < uVar6)))) &&
                             (((uVar2 & 0xfffffffc) != 0x48 &&
                              ((*(undefined4 *)(lVar15 + 0xc0c) = puVar9[0x12], 0x4b < uVar6 &&
                               ((uVar2 & 0xfffffffc) != 0x4c)))))) &&
                            ((*(undefined4 *)(lVar15 + 0xc10) = puVar9[0x13], 0x4f < uVar6 &&
                             ((((uVar2 & 0xfffffffc) != 0x50 &&
                               (*(undefined4 *)(lVar15 + 0xc14) = puVar9[0x14], 0x53 < uVar6)) &&
                              ((uVar2 & 0xfffffffc) != 0x54)))))) &&
                           (((*(undefined4 *)(lVar15 + 0xc18) = puVar9[0x15], 0x57 < uVar6 &&
                             ((uVar2 & 0xfffffffc) != 0x58)) &&
                            ((*(undefined4 *)(lVar15 + 0xc1c) = puVar9[0x16], 0x5b < uVar6 &&
                             ((uVar2 & 0xfffffffc) != 0x5c)))))) {
                          *(undefined4 *)(lVar15 + 0xc20) = puVar9[0x17];
                          *(long *)(lVar15 + 0xc58) = lVar15 + 0xc04;
                          if ((((0x5f < uVar6) && ((uVar2 & 0xfffffffc) != 0x60)) &&
                              (*(undefined4 *)(lVar15 + 0xc24) = puVar9[0x18], 99 < uVar6)) &&
                             (((((((uVar2 & 0xfffffffc) != 100 &&
                                  (*(undefined4 *)(lVar15 + 0xc28) = puVar9[0x19], 0x67 < uVar6)) &&
                                 ((uVar2 & 0xfffffffc) != 0x68)) &&
                                (((*(undefined4 *)(lVar15 + 0xc2c) = puVar9[0x1a], 0x6b < uVar6 &&
                                  ((uVar2 & 0xfffffffc) != 0x6c)) &&
                                 ((*(undefined4 *)(lVar15 + 0xc30) = puVar9[0x1b], 0x6f < uVar6 &&
                                  (((uVar2 & 0xfffffffc) != 0x70 &&
                                   (*(undefined4 *)(lVar15 + 0xc34) = puVar9[0x1c], 0x73 < uVar6))))
                                 )))) && ((uVar2 & 0xfffffffc) != 0x74)) &&
                              ((((*(undefined4 *)(lVar15 + 0xc38) = puVar9[0x1d], 0x77 < uVar6 &&
                                 ((uVar2 & 0xfffffffc) != 0x78)) &&
                                (*(undefined4 *)(lVar15 + 0xc3c) = puVar9[0x1e], 0x7b < uVar6)) &&
                               ((uVar2 & 0xfffffffc) != 0x7c)))))) {
                            *(undefined4 *)(lVar15 + 0xc40) = puVar9[0x1f];
                            *(long *)(lVar15 + 0xc60) = lVar15 + 0xc24;
                            kfree(puVar9);
                            __mutex_init(plVar7 + 0x17,"&wcd9378->wakeup_lock",&wcd9378_probe___key)
                            ;
                            __mutex_init(plVar7 + 0x11,"&wcd9378->micb_lock",&wcd9378_probe___key_54
                                        );
                            __mutex_init(plVar7 + 0x1d,"&wcd9378->sys_usage_lock",
                                         &wcd9378_probe___key_56);
                            uVar14 = *(undefined8 *)(param_1 + 0x2f8);
                            local_a8[8] = 0;
                            local_a8[9] = 0;
                            local_a8[6] = 0;
                            local_a8[7] = 0;
                            local_a8[4] = 0;
                            local_a8[5] = 0;
                            local_a8[2] = 0;
                            local_a8[3] = 0;
                            local_a8[0] = 0;
                            local_a8[1] = 0;
                            iVar5 = __of_parse_phandle_with_args
                                              (uVar14,"qcom,rx-slave",0,0,0,local_a8);
                            if ((iVar5 == 0) && (local_a8[0] != 0)) {
                              component_match_add_release
                                        (lVar1,&local_b0,wcd9378_release_of,wcd9378_compare_of);
                              local_a8[8] = 0;
                              local_a8[9] = 0;
                              local_a8[6] = 0;
                              local_a8[7] = 0;
                              local_a8[4] = 0;
                              local_a8[5] = 0;
                              local_a8[2] = 0;
                              local_a8[3] = 0;
                              local_a8[0] = 0;
                              local_a8[1] = 0;
                              iVar5 = __of_parse_phandle_with_args
                                                (uVar14,"qcom,tx-slave",0,0,0,local_a8);
                              if ((iVar5 == 0) && (local_a8[0] != 0)) {
                                component_match_add_release
                                          (lVar1,&local_b0,wcd9378_release_of,wcd9378_compare_of);
                                iVar5 = wcd9378_reset(lVar1);
                                if (iVar5 == -0x205) {
                                  _dev_err(lVar1,"%s: wcd reset failed!\n","wcd9378_probe");
                                  uVar4 = 0xfffffdfb;
                                }
                                else {
                                  plVar7[0x194] = (long)wcd9378_wakeup;
                                  uVar4 = component_master_add_with_match
                                                    (lVar1,&wcd9378_comp_ops,local_b0);
                                }
                                goto LAB_00102e14;
                              }
                              pcVar10 = "%s: Tx-slave node not defined\n";
                            }
                            else {
                              pcVar10 = "%s: Rx-slave node not defined\n";
                            }
                            _dev_err(lVar1,pcVar10,"wcd9378_add_slave_components");
                            uVar4 = 0xffffffed;
                            goto LAB_00102e14;
                          }
                        }
                      }
                    }
                  }
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(1,0x102e50);
                  (*pcVar3)();
                }
                _dev_err(lVar1,"%s: Failed to read  port mapping from prop %s\n",
                         "wcd9378_parse_port_params","qcom,swr-tx-port-params");
                kfree(puVar9);
              }
            }
            pcVar10 = "Failed to read port params\n";
          }
          else {
            pcVar10 = "Failed to read port mapping\n";
          }
          _dev_err(lVar1,pcVar10);
          goto LAB_00102e14;
        }
        pcVar10 = "%s: register_notifier api is null!\n";
      }
    }
  }
LAB_00102d0c:
  _dev_err(lVar1,pcVar10,"wcd9378_probe");
  uVar4 = 0xffffffea;
LAB_00102e14:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd9378_remove @ 00102e58 size=60
// signature: undefined wcd9378_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_remove(long param_1)

{
  component_master_del(param_1 + 0x10,&wcd9378_comp_ops);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// wcd9378_parse_port_mapping @ 00102e94 size=552
// signature: undefined wcd9378_parse_port_mapping(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

int wcd9378_parse_port_mapping(long param_1,undefined8 param_2,char param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  long lVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  ulong uVar8;
  undefined4 *puVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  int local_84;
  uint local_6c;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_6c = 0;
  if (param_3 == '\0') {
    lVar10 = lVar5 + 0x1c4;
    puVar6 = (undefined1 *)(lVar5 + 0x1c0);
  }
  else {
    if (param_3 != '\x01') {
      _dev_err(param_1,"%s Invalid path selected %u\n","wcd9378_parse_port_mapping",param_3);
      local_84 = -0x16;
      goto LAB_00102ff4;
    }
    lVar10 = lVar5 + 0x6c4;
    puVar6 = (undefined1 *)(lVar5 + 0x1c1);
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),param_2,&local_6c);
  uVar11 = local_6c;
  if (lVar5 == 0) {
    _dev_err(param_1,"missing port mapping prop %s\n",param_2);
    local_84 = -0x16;
  }
  else {
    lVar5 = __kmalloc(local_6c,0xdc0);
    if (lVar5 == 0) {
      local_84 = -0xc;
    }
    else {
      local_84 = of_property_read_variable_u32_array
                           (*(undefined8 *)(param_1 + 0x2e8),param_2,lVar5,(uVar11 / 0x14) * 5,0);
      if (local_84 < 0) {
        _dev_err(param_1,"%s: Failed to read  port mapping from prop %s\n",
                 "wcd9378_parse_port_mapping",param_2);
LAB_001030ac:
        kfree(lVar5);
      }
      else {
        if (uVar11 < 0x14) {
          uVar12 = 0;
        }
        else {
          uVar11 = uVar11 / 0x14;
          uVar4 = 0;
          if (uVar11 < 2) {
            uVar11 = 1;
          }
          uVar8 = (ulong)uVar11;
          puVar9 = (undefined4 *)(lVar5 + 8);
          local_84 = 0;
          uVar11 = 0;
          do {
            uVar12 = puVar9[-2];
            if (7 < uVar12 || 7 < uVar4) {
              _dev_err(param_1,"%s: Invalid port or channel number\n","wcd9378_parse_port_mapping");
              goto LAB_001030ac;
            }
            if (uVar12 != uVar11) {
              uVar4 = 0;
            }
            uVar3 = *puVar9;
            puVar7 = (undefined4 *)(lVar10 + (ulong)uVar12 * 0xa0 + (ulong)uVar4 * 0x14);
            uVar1 = puVar9[1];
            uVar2 = puVar9[2];
            *puVar7 = puVar9[-1];
            puVar7[1] = uVar2;
            puVar7[2] = uVar3;
            uVar3 = __sw_hweight8();
            uVar4 = uVar4 + 1;
            puVar9 = puVar9 + 5;
            uVar8 = uVar8 - 1;
            puVar7[3] = uVar3;
            puVar7[4] = uVar1;
            uVar11 = uVar12;
          } while (uVar8 != 0);
        }
        *puVar6 = (char)uVar12;
        kfree(lVar5);
        local_84 = 0;
      }
    }
  }
LAB_00102ff4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_84;
}



//------------------------------------------------------------
// wcd9378_reset @ 001030bc size=212
// signature: undefined wcd9378_reset(void)
// callers: [wcd9378_probe, wcd9378_event_notify]
//------------------------------------------------------------

undefined8 wcd9378_reset(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 != 0) {
    if (*(long *)(lVar3 + 0x28) != 0) {
      iVar1 = msm_cdc_pinctrl_get_state();
      if (0 < iVar1) {
        return 0;
      }
      iVar1 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(lVar3 + 0x28));
      if (iVar1 == 0) {
        usleep_range_state(0x50,0x55,2);
        iVar1 = msm_cdc_pinctrl_select_active_state(*(undefined8 *)(lVar3 + 0x28));
        if (iVar1 == 0) {
          usleep_range_state(0x50,0x55,2);
          return 0;
        }
        pcVar2 = "%s: wcd active state request fail!\n";
      }
      else {
        pcVar2 = "%s: wcd sleep state request fail!\n";
      }
      _dev_err(param_1,pcVar2,"wcd9378_reset");
      return 0xfffffdfb;
    }
    _dev_err(param_1,"%s: reset gpio device node not specified\n","wcd9378_reset");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_wakeup @ 00103194 size=148
// signature: undefined wcd9378_wakeup(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd9378_wakeup(long param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    puVar2 = &DAT_00154f13;
  }
  else {
    if (*(long *)(param_1 + 0x40) != 0) {
      mutex_lock(param_1 + 0xb8);
      if ((param_2 & 1) == 0) {
        uVar1 = swr_device_wakeup_unvote(*(undefined8 *)(param_1 + 0x40));
      }
      else {
        uVar1 = swr_device_wakeup_vote();
      }
      mutex_unlock(param_1 + 0xb8);
      return uVar1;
    }
    puVar2 = &DAT_0015440b;
  }
  _printk(puVar2,"wcd9378_wakeup");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_release_of @ 0010322c size=4
// signature: undefined wcd9378_release_of(void)
// callers: []
//------------------------------------------------------------

void wcd9378_release_of(void)

{
  return;
}



//------------------------------------------------------------
// wcd9378_compare_of @ 00103234 size=16
// signature: undefined wcd9378_compare_of(void)
// callers: []
//------------------------------------------------------------

bool wcd9378_compare_of(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x2e8) == param_2;
}



//------------------------------------------------------------
// wcd9378_bind @ 00103248 size=680
// signature: undefined wcd9378_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wcd9378_bind(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  
  lVar5 = *(long *)(param_1 + 0x90);
  puVar2 = *(undefined8 **)(param_1 + 0x98);
  usleep_range_state(5000,0x1392,2);
  iVar3 = component_bind_all(param_1,puVar2);
  if (iVar3 != 0) {
    _dev_err(param_1,"%s: Slave bind failed, ret = %d\n","wcd9378_bind",iVar3);
    return iVar3;
  }
  lVar4 = get_matching_swr_slave_device(*(undefined8 *)(lVar5 + 8));
  puVar2[7] = lVar4;
  if (lVar4 == 0) {
    pcVar6 = "%s: Could not find RX swr slave device\n";
  }
  else {
    *(undefined1 *)(lVar4 + 0x3e1) = 1;
    lVar5 = get_matching_swr_slave_device(*(undefined8 *)(lVar5 + 0x10));
    puVar2[8] = lVar5;
    if (lVar5 != 0) {
      *(undefined1 *)(lVar5 + 0x3e1) = 1;
      swr_init_port_params(puVar2[8],4,puVar2 + 0x189);
      lVar5 = __devm_regmap_init_swr(puVar2[8],wcd9378_regmap_config,0,0);
      puVar2[6] = lVar5;
      if (lVar5 == 0) {
        _dev_err(param_1,"%s: Regmap init failed\n","wcd9378_bind");
        iVar3 = 0;
      }
      else {
        regmap_write(lVar5,0xf4,0xff);
        regmap_write(puVar2[6],0xf8,0xb);
        regmap_write(puVar2[6],0xfc,0xff);
        puVar1 = puVar2 + 0x31;
        _DAT_00155718 = puVar2;
        puVar2[0x31] = &wcd9378_regmap_irq_chip;
        puVar2[0x32] = "WCD9378";
        puVar2[0x35] = param_1;
        puVar2[0x33] = puVar2[6];
        iVar3 = wcd_irq_init(puVar1,puVar2 + 0x30);
        if (iVar3 == 0) {
          _dev_err(*puVar2,"%s: wcd irq init done\n","wcd9378_bind");
          *(undefined8 *)(puVar2[8] + 1000) = puVar2[0x30];
          wcd_request_irq(puVar1,0xe,"HPHR PDM WD INT",wcd9378_wd_handle_irq,0);
          wcd_request_irq(puVar1,0xd,"HPHL PDM WD INT",wcd9378_wd_handle_irq,0);
          wcd_request_irq(puVar1,0xf,"AUX PDM WD INT",wcd9378_wd_handle_irq,0);
          wcd_disable_irq(puVar1,0xe);
          wcd_disable_irq(puVar1,0xd);
          wcd_disable_irq(puVar1,0xf);
          iVar3 = snd_soc_register_component(param_1,&soc_codec_dev_wcd9378,&wcd9378_dai,1);
          if (iVar3 == 0) {
            return 0;
          }
          _dev_err(param_1,"%s: Codec registration failed\n","wcd9378_bind");
          wcd_irq_exit(puVar1,puVar2[0x30]);
        }
        else {
          _dev_err(*puVar2,"%s: IRQ init failed: %d\n","wcd9378_bind",iVar3);
        }
      }
      goto LAB_001032fc;
    }
    pcVar6 = "%s: Could not find TX swr slave device\n";
  }
  _dev_err(param_1,pcVar6,"wcd9378_bind");
  iVar3 = -0x13;
LAB_001032fc:
  component_unbind_all(param_1,puVar2);
  return iVar3;
}



//------------------------------------------------------------
// wcd9378_unbind @ 001034f4 size=132
// signature: undefined wcd9378_unbind(void)
// callers: []
//------------------------------------------------------------

void wcd9378_unbind(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  lVar1 = lVar2 + 0x188;
  wcd_free_irq(lVar1,0xe,0);
  wcd_free_irq(lVar1,0xd,0);
  wcd_free_irq(lVar1,0xf,0);
  wcd_irq_exit(lVar1,*(undefined8 *)(lVar2 + 0x180));
  snd_soc_unregister_component(param_1);
  component_unbind_all(param_1,lVar2);
  return;
}



//------------------------------------------------------------
// wcd9378_wd_handle_irq @ 0010357c size=92
// signature: undefined wcd9378_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wcd9378_wd_handle_irq__rs,"wcd9378_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00153ee5,"wcd9378_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wcd9378_handle_post_irq @ 001035dc size=232
// signature: undefined wcd9378_handle_post_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_handle_post_irq(long param_1)

{
  long lVar1;
  int local_34;
  int local_30;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  local_34 = 0;
  local_30 = 0;
  regmap_write(*(undefined8 *)(param_1 + 0x30),0x58,0xff);
  regmap_write(*(undefined8 *)(param_1 + 0x30),0x59,0xff);
  regmap_write(*(undefined8 *)(param_1 + 0x30),0x5a,0xff);
  regmap_read(*(undefined8 *)(param_1 + 0x30),0x58,&local_2c);
  regmap_read(*(undefined8 *)(param_1 + 0x30),0x59,&local_30);
  regmap_read(*(undefined8 *)(param_1 + 0x30),0x5a,&local_34);
  *(bool *)(*(long *)(param_1 + 0x40) + 0x3f0) = (local_2c != 0 || local_30 != 0) || local_34 != 0;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// wcd9378_soc_codec_probe @ 001036c8 size=1404
// signature: undefined wcd9378_soc_codec_probe(void)
// callers: []
//------------------------------------------------------------

int wcd9378_soc_codec_probe(long param_1)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  code *pcVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar7 == 0) {
    return -0x16;
  }
  *(long *)(lVar7 + 0x20) = param_1;
  snd_soc_component_init_regmap(param_1,*(undefined8 *)(lVar7 + 0x30));
  devm_regmap_qti_debugfs_register(*(long *)(lVar7 + 0x40) + 0x48,*(undefined8 *)(lVar7 + 0x30));
  lVar6 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  uVar3 = snd_soc_component_read(param_1,0x401804cd);
  if ((uVar3 & 1) == 0) {
    uVar1 = snd_soc_component_read(param_1,0x401804f0);
  }
  else {
    uVar3 = snd_soc_component_read(param_1,0x401804cd);
    uVar1 = (uint)(uVar3 >> 1) & 0x7fffffff;
  }
  if ((uVar1 & 1) != *(uint *)(lVar6 + 0x18)) {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"wcd mode check failed\n");
    return -0x16;
  }
  iVar2 = wcd9378_mbhc_init(lVar7 + 0x150,param_1);
  if (iVar2 != 0) {
    _printk(&DAT_00154262,"wcd9378_soc_codec_probe");
    return -0x16;
  }
  lVar6 = param_1 + 0xd0;
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC1");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC2");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC3");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC4");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC1");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC2");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC3");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC4");
  snd_soc_dapm_ignore_suspend(lVar6,"IN1_HPHL");
  snd_soc_dapm_ignore_suspend(lVar6,"IN2_HPHR");
  snd_soc_dapm_ignore_suspend(lVar6,"IN3_AUX");
  snd_soc_dapm_ignore_suspend(lVar6,"ADC1_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,"ADC2_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,"ADC3_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_00153e78);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_001549fc);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_00154149);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_00153992);
  snd_soc_dapm_sync(lVar6);
  wcd_cls_h_init(lVar7 + 300);
  wcd9378_init_reg(param_1);
  lVar6 = *(long *)(**(long **)(*(long *)(param_1 + 0x18) + 0x98) + 0x90);
  iVar2 = *(int *)(lVar6 + 0x20);
  if (iVar2 < 0x9c4) {
    if (iVar2 < 0x708) {
      if (iVar2 == 0) {
        uVar5 = 1;
      }
      else if (iVar2 == 0x4b0) {
        uVar5 = 2;
      }
      else {
LAB_0010395c:
        if (iVar2 - 0xb23U < 0xfffff8c5) {
          _printk(&DAT_00154e17,"wcd9378_get_micb_vout_ctl_val");
          uVar1 = 0xffffffea;
        }
        else {
          uVar1 = (iVar2 - 1000U >> 1 & 0x7fff) / 0x19;
        }
        snd_soc_component_update_bits(param_1,0x401805a3,0xff,uVar1);
        uVar5 = 0xf3;
      }
    }
    else if (iVar2 == 0x708) {
      uVar5 = 3;
    }
    else {
      if (iVar2 != 0x898) goto LAB_0010395c;
      uVar5 = 0xf0;
    }
  }
  else if (iVar2 < 0xabe) {
    if (iVar2 == 0x9c4) {
      uVar5 = 4;
    }
    else {
      if (iVar2 != 0xa8c) goto LAB_0010395c;
      uVar5 = 0xf1;
    }
  }
  else if (iVar2 == 0xabe) {
    uVar5 = 5;
  }
  else {
    if (iVar2 != 0xaf0) goto LAB_0010395c;
    uVar5 = 0xf2;
  }
  iVar2 = *(int *)(lVar6 + 0x24);
  *(undefined4 *)(lVar6 + 0x2c) = uVar5;
  if (iVar2 < 0x9c4) {
    if (iVar2 < 0x708) {
      if (iVar2 == 0) {
        uVar5 = 1;
      }
      else if (iVar2 == 0x4b0) {
        uVar5 = 2;
      }
      else {
LAB_00103a2c:
        if (iVar2 - 0xb23U < 0xfffff8c5) {
          _printk(&DAT_00154e17,"wcd9378_get_micb_vout_ctl_val");
          uVar1 = 0xffffffea;
        }
        else {
          uVar1 = (iVar2 - 1000U >> 1 & 0x7fff) / 0x19;
        }
        snd_soc_component_update_bits(param_1,0x401805a4,0xff,uVar1);
        uVar5 = 0xf4;
      }
    }
    else if (iVar2 == 0x708) {
      uVar5 = 3;
    }
    else {
      if (iVar2 != 0x898) goto LAB_00103a2c;
      uVar5 = 0xf0;
    }
  }
  else if (iVar2 < 0xabe) {
    if (iVar2 == 0x9c4) {
      uVar5 = 4;
    }
    else {
      if (iVar2 != 0xa8c) goto LAB_00103a2c;
      uVar5 = 0xf1;
    }
  }
  else if (iVar2 == 0xabe) {
    uVar5 = 5;
  }
  else {
    if (iVar2 != 0xaf0) goto LAB_00103a2c;
    uVar5 = 0xf2;
  }
  iVar2 = *(int *)(lVar6 + 0x28);
  *(undefined4 *)(lVar6 + 0x30) = uVar5;
  if (iVar2 < 0x9c4) {
    if (iVar2 < 0x708) {
      if (iVar2 == 0) {
        uVar5 = 1;
        goto LAB_00103b30;
      }
      if (iVar2 == 0x4b0) {
        uVar5 = 2;
        goto LAB_00103b30;
      }
    }
    else {
      if (iVar2 == 0x708) {
        uVar5 = 3;
        goto LAB_00103b30;
      }
      if (iVar2 == 0x898) {
        uVar5 = 0xf0;
        goto LAB_00103b30;
      }
    }
  }
  else if (iVar2 < 0xabe) {
    if (iVar2 == 0x9c4) {
      uVar5 = 4;
      goto LAB_00103b30;
    }
    if (iVar2 == 0xa8c) {
      uVar5 = 0xf1;
      goto LAB_00103b30;
    }
  }
  else {
    if (iVar2 == 0xabe) {
      uVar5 = 5;
      goto LAB_00103b30;
    }
    if (iVar2 == 0xaf0) {
      uVar5 = 0xf2;
      goto LAB_00103b30;
    }
  }
  if (iVar2 - 0xb23U < 0xfffff8c5) {
    _printk(&DAT_00154e17,"wcd9378_get_micb_vout_ctl_val");
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = (iVar2 - 1000U >> 1 & 0x7fff) / 0x19;
  }
  snd_soc_component_update_bits(param_1,0x401805a5,0xff,uVar1);
  uVar5 = 0xf5;
LAB_00103b30:
  *(undefined4 *)(lVar6 + 0x34) = uVar5;
  pcVar4 = *(code **)(lVar7 + 0xc98);
  *(undefined4 *)(lVar7 + 0xca8) = 1;
  *(code **)(lVar7 + 0xc70) = wcd9378_event_notify;
  if (pcVar4 == (code *)0x0) {
    iVar2 = 0;
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103b74);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)(*(undefined8 *)(lVar7 + 0xc88),lVar7 + 0xc70,1);
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Failed to register notifier %d\n",
               "wcd9378_soc_codec_probe",iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd9378_soc_codec_remove @ 00103c48 size=108
// signature: undefined wcd9378_soc_codec_remove(void)
// callers: []
//------------------------------------------------------------

void wcd9378_soc_codec_remove(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar2 == 0) {
    _dev_err(*(long *)(param_1 + 0x18),"%s: wcd9378 is already NULL\n","wcd9378_soc_codec_remove");
  }
  else {
    pcVar1 = *(code **)(lVar2 + 0xc98);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103c8c);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(lVar2 + 0xc88),lVar2 + 0xc70,0);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd9378_soc_codec_suspend @ 00103cb8 size=28
// signature: undefined wcd9378_soc_codec_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_soc_codec_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x17c) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_soc_codec_resume @ 00103cd8 size=24
// signature: undefined wcd9378_soc_codec_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_soc_codec_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x17c) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_get_compander @ 00103cf4 size=44
// signature: undefined wcd9378_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_get_compander(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0x178;
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) != 0) {
    lVar1 = 0x179;
  }
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + lVar1);
  return 0;
}



//------------------------------------------------------------
// wcd9378_set_compander @ 00103d24 size=56
// signature: undefined wcd9378_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_set_compander(long param_1,long param_2)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = *(int *)(param_2 + 0x48) != 0;
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) == 0) {
    *(bool *)(lVar2 + 0x178) = bVar1;
    return 0;
  }
  *(bool *)(lVar2 + 0x179) = bVar1;
  return 0;
}



//------------------------------------------------------------
// wcd9378_bcs_get @ 00103d60 size=28
// signature: undefined wcd9378_bcs_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_bcs_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x17b);
  return 0;
}



//------------------------------------------------------------
// wcd9378_bcs_put @ 00103d80 size=36
// signature: undefined wcd9378_bcs_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_bcs_put(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x17b) =
       *(long *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wcd9378_loopback_mode_get @ 00103da8 size=76
// signature: undefined wcd9378_loopback_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_loopback_mode_get(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = snd_soc_component_read(*(long *)(param_1 + 0x80),0x40180483);
    uVar2 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 & 7);
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_loopback_mode_put @ 00103df8 size=64
// signature: undefined wcd9378_loopback_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_loopback_mode_put(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    snd_soc_component_update_bits
              (*(long *)(param_1 + 0x80),0x40180483,7,*(undefined4 *)(param_2 + 0x48));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd9378_aux_dsm_get @ 00103e3c size=76
// signature: undefined wcd9378_aux_dsm_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_aux_dsm_get(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = snd_soc_component_read(*(long *)(param_1 + 0x80),0x40180482);
    uVar2 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 & 0xc);
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_aux_dsm_put @ 00103e8c size=64
// signature: undefined wcd9378_aux_dsm_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_aux_dsm_put(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    snd_soc_component_update_bits
              (*(long *)(param_1 + 0x80),0x40180482,0xc,*(undefined4 *)(param_2 + 0x48));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd9378_hph_dsm_get @ 00103ed0 size=76
// signature: undefined wcd9378_hph_dsm_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_hph_dsm_get(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = snd_soc_component_read(*(long *)(param_1 + 0x80),0x40180482);
    uVar2 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 & 3);
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_hph_dsm_put @ 00103f20 size=64
// signature: undefined wcd9378_hph_dsm_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_hph_dsm_put(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    snd_soc_component_update_bits
              (*(long *)(param_1 + 0x80),0x40180482,3,*(undefined4 *)(param_2 + 0x48));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd9378_tx_mode_get @ 00103f64 size=160
// signature: undefined wcd9378_tx_mode_get(void)
// callers: []
//------------------------------------------------------------

void wcd9378_tx_mode_get(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x80) != 0) {
    lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
    if (lVar3 != 0) {
      uVar2 = wcd9378_tx_path_get(param_1 + 0x20,&local_2c);
      if (-1 < (int)uVar2) {
        if (2 < local_2c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104004);
          (*pcVar1)();
        }
        uVar2 = 0;
        *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar3 + (ulong)local_2c * 4 + 0x168);
      }
      goto LAB_00103fd4;
    }
  }
  uVar2 = 0xffffffea;
LAB_00103fd4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_tx_mode_put @ 00104008 size=160
// signature: undefined wcd9378_tx_mode_put(void)
// callers: []
//------------------------------------------------------------

void wcd9378_tx_mode_put(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x80) != 0) {
    lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
    if (lVar3 != 0) {
      uVar2 = wcd9378_tx_path_get(param_1 + 0x20,&local_2c);
      if ((int)uVar2 == 0) {
        if (2 < local_2c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1040a8);
          (*pcVar1)();
        }
        uVar2 = 0;
        *(undefined4 *)(lVar3 + (ulong)local_2c * 4 + 0x168) = *(undefined4 *)(param_2 + 0x48);
      }
      goto LAB_00104078;
    }
  }
  uVar2 = 0xffffffea;
LAB_00104078:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_rx2_mode_put @ 001040ac size=36
// signature: undefined wcd9378_rx2_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_rx2_mode_put(long param_1,long param_2)

{
  *(uint *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x164) =
       (uint)(*(int *)(param_2 + 0x48) != 0);
  return 1;
}



//------------------------------------------------------------
// wcd9378_rx_hph_mode_get @ 001040d4 size=28
// signature: undefined wcd9378_rx_hph_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_rx_hph_mode_get(long param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x48) =
       *(undefined4 *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x158);
  return 0;
}



//------------------------------------------------------------
// wcd9378_rx_hph_mode_put @ 001040f4 size=48
// signature: undefined wcd9378_rx_hph_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_rx_hph_mode_put(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  if (*(int *)(lVar1 + 0x158) == *(int *)(param_2 + 0x48)) {
    return 0;
  }
  *(int *)(lVar1 + 0x158) = *(int *)(param_2 + 0x48);
  return 1;
}



//------------------------------------------------------------
// wcd9378_hph_get_gain @ 00104128 size=48
// signature: undefined wcd9378_hph_get_gain(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_hph_get_gain(long param_1,long param_2)

{
  *(uint *)(param_2 + 0x48) =
       (-(uint)*(ushort *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x15c) &
       0xffff) / 0x180;
  return 0;
}



//------------------------------------------------------------
// wcd9378_hph_put_gain @ 0010415c size=36
// signature: undefined wcd9378_hph_put_gain(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_hph_put_gain(long param_1,long param_2)

{
  *(short *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x15c) =
       *(short *)(param_2 + 0x48) * -0x180;
  return 0;
}



//------------------------------------------------------------
// wcd9378_ear_pa_gain_get @ 00104184 size=76
// signature: undefined wcd9378_ear_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_ear_pa_gain_get(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = snd_soc_component_read(*(long *)(param_1 + 0x80),0x4018000b);
    uVar2 = 0;
    *(uint *)(param_2 + 0x48) = uVar1 >> 2 & 0x1f;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_ear_pa_gain_put @ 001041d4 size=100
// signature: undefined wcd9378_ear_pa_gain_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_ear_pa_gain_put(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x80);
  if (lVar1 != 0) {
    if (*(ulong *)(param_2 + 0x48) < 0x11) {
      snd_soc_component_update_bits(lVar1,0x4018000b,0x7c,(int)*(ulong *)(param_2 + 0x48) << 2);
      return 0;
    }
    _dev_err(*(undefined8 *)(lVar1 + 0x18),"%s: Unsupported gain val %ld\n",
             "wcd9378_ear_pa_gain_put");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_aux_pa_gain_get @ 0010423c size=76
// signature: undefined wcd9378_aux_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_aux_pa_gain_get(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x80) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = snd_soc_component_read(*(long *)(param_1 + 0x80),0x401801c4);
    uVar2 = 0;
    *(uint *)(param_2 + 0x48) = uVar1 & 0xf;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_aux_pa_gain_put @ 0010428c size=96
// signature: undefined wcd9378_aux_pa_gain_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_aux_pa_gain_put(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x80);
  if (lVar1 != 0) {
    if (*(ulong *)(param_2 + 0x48) < 9) {
      snd_soc_component_update_bits(lVar1,0x401801c4,0xf);
      return 0;
    }
    _dev_err(*(undefined8 *)(lVar1 + 0x18),"%s: Unsupported gain val %ld\n",
             "wcd9378_aux_pa_gain_put");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_tx_master_ch_get @ 001042f0 size=176
// signature: undefined wcd9378_tx_master_ch_get(void)
// callers: []
//------------------------------------------------------------

void wcd9378_tx_master_ch_get(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  uVar2 = 0xffffffea;
  local_2c = 0xffffffea;
  if ((*(long *)(param_1 + 0x80) != 0) &&
     (lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98), lVar3 != 0)) {
    wcd9378_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if (local_2c < 0xd) {
      uVar2 = 0;
      uVar1 = *(byte *)(lVar3 + (ulong)local_2c + 0xccc) - 0x2e;
      lVar3 = 0;
      if (uVar1 < 0xc) {
        lVar3 = ((ulong)uVar1 & 0xff) + 1;
      }
      *(long *)(param_2 + 0x48) = lVar3;
    }
    else {
      uVar2 = 0xffffffea;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_tx_master_ch_put @ 001043a4 size=180
// signature: undefined wcd9378_tx_master_ch_put(void)
// callers: []
//------------------------------------------------------------

void wcd9378_tx_master_ch_put(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  uVar1 = 0xffffffea;
  local_2c = 0xffffffea;
  if ((*(long *)(param_1 + 0x80) != 0) &&
     (lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98), lVar2 != 0)) {
    wcd9378_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if ((local_2c < 0xd) && (*(uint *)(param_2 + 0x48) < 0xe)) {
      uVar1 = 0;
      *(char *)(lVar2 + (ulong)local_2c + 0xccc) =
           (char)*(undefined4 *)(wcd9378_swr_master_ch_map + (ulong)*(uint *)(param_2 + 0x48) * 4);
    }
    else {
      uVar1 = 0xffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_tx_path_get @ 00104458 size=268
// signature: undefined wcd9378_tx_path_get(void)
// callers: [wcd9378_tx_mode_get, wcd9378_tx_mode_put]
//------------------------------------------------------------

int wcd9378_tx_path_get(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  pcVar3 = (char *)kstrndup(param_1,9,0xcc0);
  local_30 = pcVar3;
  if (pcVar3 == (char *)0x0) {
    iVar2 = -0x16;
  }
  else {
    pcVar4 = strsep(&local_30," ");
    if (pcVar4 == (char *)0x0) {
      _printk(&DAT_001547f1,"wcd9378_tx_path_get",local_30);
      iVar2 = -0x16;
    }
    else {
      pcVar4 = strpbrk(pcVar4,"0123");
      if (pcVar4 == (char *)0x0) {
        _printk(&DAT_00154a37,"wcd9378_tx_path_get");
        iVar2 = -0x16;
      }
      else {
        iVar2 = kstrtouint(pcVar4,10,param_2);
        if (iVar2 < 0) {
          _printk(&DAT_00154811,"wcd9378_tx_path_get",pcVar3);
        }
      }
    }
    kfree(pcVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd9378_tx_get_slave_ch_type_idx @ 00104564 size=436
// signature: undefined wcd9378_tx_get_slave_ch_type_idx(void)
// callers: [wcd9378_tx_master_ch_get, wcd9378_tx_master_ch_put]
//------------------------------------------------------------

void wcd9378_tx_get_slave_ch_type_idx(undefined8 param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = strnstr(param_1,&DAT_001544e8,5);
  if (lVar1 == 0) {
    lVar1 = strnstr(param_1,&DAT_00154c0a,5);
    if (lVar1 == 0) {
      lVar1 = strnstr(param_1,&DAT_00154b16,5);
      if (lVar1 == 0) {
        lVar1 = strnstr(param_1,&DAT_001549eb,5);
        if (lVar1 == 0) {
          lVar1 = strnstr(param_1,"DMIC0",6);
          if (lVar1 == 0) {
            lVar1 = strnstr(param_1,"DMIC1",6);
            if (lVar1 == 0) {
              lVar1 = strnstr(param_1,&DAT_001538cc,5);
              if (lVar1 == 0) {
                lVar1 = strnstr(param_1,"DMIC2",6);
                if (lVar1 == 0) {
                  lVar1 = strnstr(param_1,"DMIC3",6);
                  if (lVar1 == 0) {
                    lVar1 = strnstr(param_1,"DMIC4",6);
                    if (lVar1 == 0) {
                      lVar1 = strnstr(param_1,"DMIC5",6);
                      if (lVar1 == 0) {
                        _printk(&DAT_00154946,"wcd9378_tx_get_slave_ch_type_idx",param_1);
                        uVar2 = 0xffffffea;
                        goto LAB_001046e4;
                      }
                      lVar1 = 10;
                    }
                    else {
                      lVar1 = 9;
                    }
                  }
                  else {
                    lVar1 = 8;
                  }
                }
                else {
                  lVar1 = 7;
                }
              }
              else {
                lVar1 = 6;
              }
            }
            else {
              lVar1 = 5;
            }
          }
          else {
            lVar1 = 4;
          }
        }
        else {
          lVar1 = 3;
        }
      }
      else {
        lVar1 = 2;
      }
    }
    else {
      lVar1 = 1;
    }
  }
  else {
    lVar1 = 0;
  }
  uVar2 = (uint)(byte)wcd9378_swr_slv_tx_ch_idx[lVar1 * 2 + 1];
LAB_001046e4:
  *param_2 = uVar2;
  return;
}



//------------------------------------------------------------
// wcd9378_tx_sequencer_enable @ 0010471c size=1856
// signature: undefined wcd9378_tx_sequencer_enable(void)
// callers: []
//------------------------------------------------------------

void wcd9378_tx_sequencer_enable(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined1 uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  undefined4 uVar15;
  undefined8 *puVar16;
  long lVar17;
  undefined4 local_6c;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 auStack_60 [4];
  undefined1 local_5c [4];
  long local_58;
  
  lVar14 = sp_el0;
  local_58 = *(long *)(lVar14 + 0x638);
  lVar17 = *(long *)(param_1 + 0x28);
  local_6c = 0;
  lVar14 = lVar17 + -0xd0;
  puVar16 = *(undefined8 **)(*(long *)(lVar17 + -0xb8) + 0x98);
  swr_read(puVar16[8],*(undefined1 *)(puVar16[8] + 0x40),0x44,&local_6c,1);
  uVar5 = (uint)*(byte *)(param_1 + 0x4c);
  if (param_3 == 8) {
    uVar5 = uVar5 - 0x1e;
    if (uVar5 < 3) {
      uVar13 = -((ulong)(uVar5 >> 7) & 1) & 0xfffffffffffff800 | ((ulong)uVar5 & 0xff) << 3;
      lVar11 = *(long *)(*(long *)(lVar17 + -0xb8) + 0x98);
      uVar12 = (ulong)uVar5 & 0xff;
      uVar9 = 0;
      if ((*(ulong *)(lVar11 + 0x10) & *(ulong *)(&DAT_00113528 + uVar13)) != 0) {
        uVar9 = uVar12 * -2 + 7;
      }
      if ((*(ulong *)(lVar11 + 0x10) & *(ulong *)(&DAT_00113540 + uVar13)) != 0) {
        uVar9 = uVar12 * -2 + 6;
      }
    }
    else {
      uVar9 = 0;
    }
    wcd9378_tx_connect_port(lVar14,*(byte *)(param_1 + 0x4c),0,0);
    cVar2 = *(char *)(param_1 + 0x4c);
    if (cVar2 == '\x1f') {
      if (((uint)puVar16[0x37] >> 7 & 1) != 0) {
        lVar11 = *(long *)(*(long *)(lVar17 + -0xb8) + 0x98);
        local_5c[0] = 0;
        local_64[0] = 0;
        iVar6 = wcd9378_set_port_params
                          (lVar14,0x1d,local_5c,auStack_60,local_64,&local_6c,local_68,0);
        if (iVar6 == 0) {
          local_68[0] = *(undefined1 *)(lVar11 + 0xcd2);
          swr_disconnect_port(*(undefined8 *)(lVar11 + 0x40),local_5c,1,local_64,local_68);
        }
        puVar1 = puVar16 + 0x37;
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xffffffffffffff7f;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      cVar2 = *(char *)(param_1 + 0x4c);
    }
    uVar15 = 0x4018000f;
    if (cVar2 == '\x1e') {
      iVar6 = 0x410000a0;
LAB_001049a8:
      snd_soc_component_update_bits(lVar14,iVar6,0xff,0);
      snd_soc_component_update_bits(lVar14,uVar15,0x40,0);
      snd_soc_component_update_bits(lVar14,iVar6 + 0x68,0xff,3);
    }
    else {
      if (cVar2 == ' ') {
        uVar15 = 0x40180011;
        iVar6 = 0x418000a0;
        goto LAB_001049a8;
      }
      if (cVar2 == '\x1f') {
        if (((uint)puVar16[2] >> 5 & 1) != 0) {
          snd_soc_component_update_bits(lVar14,0x40c007a0,0xff,0);
          snd_soc_component_update_bits(lVar14,0x40c00808,0xff,3);
        }
        if (((uint)puVar16[2] >> 4 & 1) != 0) {
          iVar6 = 0x414000a0;
          goto LAB_001049a8;
        }
      }
    }
    usleep_range_state(800,0x32a,2);
    lVar17 = *(long *)(*(long *)(lVar17 + -0xb8) + 0x98);
    lVar14 = lVar17 + 0xe8;
    mutex_lock(lVar14);
    puVar1 = (ulong *)(lVar17 + 0x10);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & (1L << (uVar9 & 0x3f) ^ 0xffffffffffffffffU);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    mutex_unlock(lVar14);
    wcd9378_swr_slvdev_datapath_control(*puVar16,1,0);
  }
  else {
    uVar7 = 0;
    if (param_3 != 1) goto LAB_00104a38;
    if (uVar5 == 0x20) {
      uVar5 = snd_soc_component_read(lVar14,0x4018012f);
      if ((uVar5 & 7) == 1) {
        uVar7 = 3;
      }
      else {
        uVar5 = snd_soc_component_read(lVar14,0x4018012f);
        if ((uVar5 & 7) != 3) {
LAB_00104dbc:
          _dev_err(*(undefined8 *)(lVar17 + -0xb8),"%s: unsupport usecase, pls check\n",
                   "wcd9378_sys_usage_bit_get");
          uVar7 = 0xffffffea;
          goto LAB_00104a38;
        }
        uVar7 = 2;
      }
    }
    else if (uVar5 == 0x1f) {
      uVar5 = snd_soc_component_read(lVar14,0x4018012e);
      if ((uVar5 & 0x38) == 0x10) {
        uVar7 = 5;
      }
      else {
        uVar5 = snd_soc_component_read(lVar14,0x4018012e);
        if ((uVar5 & 0x38) != 0x18) goto LAB_00104dbc;
        uVar7 = 4;
      }
    }
    else if (uVar5 == 0x1e) {
      uVar5 = snd_soc_component_read(lVar14,0x4018012e);
      if ((uVar5 & 7) == 1) {
        uVar7 = 7;
      }
      else {
        uVar5 = snd_soc_component_read(lVar14,0x4018012e);
        if ((uVar5 & 7) != 2) goto LAB_00104dbc;
        uVar7 = 6;
      }
    }
    else {
      uVar7 = 0;
    }
    wcd9378_sys_usage_auto_udpate(lVar14,uVar7,1);
    uVar12 = (ulong)*(byte *)(param_1 + 0x4c);
    uVar9 = uVar12 - 0x1e;
    if (2 < uVar9) {
LAB_00104e0c:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104e10);
      (*pcVar4)();
    }
    uVar7 = 3;
    switch(*(undefined4 *)((long)puVar16 + uVar9 * 4 + 0x168)) {
    case 0:
    case 2:
      break;
    case 1:
      uVar7 = 1;
      break;
    case 3:
      uVar7 = 5;
      break;
    default:
      _printk(&DAT_00155381,"wcd9378_get_adc_mode_val");
      uVar12 = (ulong)*(byte *)(param_1 + 0x4c);
      uVar9 = uVar12 - 0x1e;
      if (2 < uVar9) goto LAB_00104e0c;
      uVar7 = 3;
    }
    iVar6 = *(int *)((long)puVar16 + uVar9 * 4 + 0x168);
    uVar15 = 4800000;
    if (iVar6 != 3) {
      uVar15 = 9600000;
    }
    if ((((int)uVar12 == 0x1f) &&
        (uVar5 = snd_soc_component_read(4800000,lVar14,0x4018012e), (uVar5 & 0x38) == 0x10)) &&
       (*(char *)((long)puVar16 + 0x17b) == '\0')) {
      wcd9378_tx_connect_port(lVar14,0x1d,4800000,1);
      puVar1 = puVar16 + 0x37;
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x80;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    uVar9 = (ulong)*(byte *)(param_1 + 0x4c) - 0x1e;
    puVar1 = puVar16 + (uVar9 >> 6 & 0x3ffffff) + 0x37;
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 1L << (uVar9 & 0x3f);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    wcd9378_tx_connect_port(lVar14,*(undefined1 *)(param_1 + 0x4c),uVar15,1);
    uVar10 = 2;
    if (iVar6 == 3) {
      uVar10 = 3;
    }
    lVar17 = *(long *)(*(long *)(lVar17 + -0xb8) + 0x98);
    *(undefined1 *)(lVar17 + 0xcdd) = 1;
    *(undefined1 *)(lVar17 + 0xcde) = uVar10;
    cVar2 = *(char *)(param_1 + 0x4c);
    if (cVar2 == ' ') {
      iVar6 = 0x418000a0;
      snd_soc_component_update_bits(lVar14,0x418000a0,0xff,uVar7);
      uVar15 = 0x40180011;
LAB_00104c90:
      uVar8 = 0x40;
      uVar7 = 0x40;
LAB_00104c98:
      snd_soc_component_update_bits(lVar14,uVar15,uVar8,uVar7);
      snd_soc_component_update_bits(lVar14,iVar6 + 0x68,0xff,0);
    }
    else {
      if (cVar2 == '\x1f') {
        uVar5 = snd_soc_component_read(lVar14,0x4018012e);
        if ((uVar5 & 0x38) == 0x10) {
          uVar15 = 0x40c007a0;
          uVar8 = 0xff;
          iVar6 = 0x40c007a0;
        }
        else {
          iVar6 = 0x414000a0;
          snd_soc_component_update_bits(lVar14,0x414000a0,0xff,uVar7);
          uVar15 = 0x4018000f;
          uVar8 = 0x20;
          uVar7 = 0x20;
        }
        goto LAB_00104c98;
      }
      if (cVar2 == '\x1e') {
        iVar6 = 0x410000a0;
        snd_soc_component_update_bits(lVar14,0x410000a0,0xff,uVar7);
        uVar15 = 0x4018000f;
        goto LAB_00104c90;
      }
    }
    usleep_range_state(800,0x32a,2);
    wcd9378_swr_slvdev_datapath_control(*puVar16,1,1);
    cVar2 = *(char *)(param_1 + 0x4c);
    if (cVar2 == ' ') {
      snd_soc_component_update_bits(lVar14,0x40180011,0x40,0);
      snd_soc_component_read(lVar14,0x41880100);
    }
    else if (cVar2 == '\x1f') {
      snd_soc_component_update_bits(lVar14,0x4018000f,0x20,0);
      if (((uint)puVar16[2] >> 5 & 1) == 0) {
        snd_soc_component_read(lVar14,0x41480100);
      }
      else {
        snd_soc_component_read(lVar14,0x40c80800);
      }
    }
    else if (cVar2 == '\x1e') {
      snd_soc_component_update_bits(lVar14,0x4018000f,0x40,0);
      snd_soc_component_read(lVar14,0x41080100);
    }
  }
  uVar7 = 0;
LAB_00104a38:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_codec_enable_dmic @ 00104e88 size=528
// signature: undefined wcd9378_codec_enable_dmic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_dmic(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  bVar1 = *(byte *)(param_1 + 0x4c);
  lVar8 = *(long *)(param_1 + 0x28);
  if (bVar1 < 6) {
    iVar2 = 0;
    lVar9 = 0;
    lVar3 = lVar8 + -0xd0;
    uVar4 = 0x4018045c;
    uVar5 = 0xf;
    uVar6 = 0x40180462;
    switch(bVar1) {
    case 2:
      iVar2 = 0x4018045d;
    case 3:
      uVar4 = 0x4018045d;
      uVar5 = 0xf0;
      lVar7 = 4;
      lVar9 = 1;
      break;
    case 4:
    case 5:
      uVar4 = 0x4018045e;
      uVar6 = 0x40180463;
      lVar9 = 2;
    default:
      lVar7 = 0;
      iVar2 = 0;
    }
    if (param_3 == 8) {
      wcd9378_tx_connect_port(lVar3,bVar1 + 0x22,0,0);
      snd_soc_component_update_bits(lVar3,0x4018045a,1 << lVar9,1 << lVar9);
      if (iVar2 != 0) {
        snd_soc_component_update_bits(lVar3,iVar2,0x80,0);
      }
      snd_soc_component_update_bits(lVar3,uVar4,8,0);
    }
    else if (param_3 == 1) {
      lVar8 = *(long *)(*(long *)(lVar8 + -0xb8) + 0x98);
      snd_soc_component_update_bits(lVar3,0x4018045a,1 << lVar9,0);
      usleep_range_state(0xfa,0x104,2);
      if (iVar2 != 0) {
        snd_soc_component_update_bits(lVar3,iVar2,0x80,0x80);
      }
      snd_soc_component_update_bits(lVar3,uVar6,uVar5,3 << lVar7);
      snd_soc_component_update_bits(lVar3,uVar4,8,8);
      snd_soc_component_update_bits(lVar3,0x4018045b,6,6);
      lVar8 = *(long *)(lVar8 + 0x40);
      uVar5 = swr_slvdev_datapath_control(lVar8,*(undefined1 *)(lVar8 + 0x40),1);
      return uVar5;
    }
    uVar5 = 0;
  }
  else {
    iVar2 = ___ratelimit(wcd9378_codec_enable_dmic__rs,"wcd9378_codec_enable_dmic");
    if (iVar2 == 0) {
      uVar5 = 0xffffffea;
    }
    else {
      _dev_err(*(undefined8 *)(lVar8 + -0xb8),"%s: Invalid DMIC Selection\n",
               "wcd9378_codec_enable_dmic");
      uVar5 = 0xffffffea;
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// wcd9378_codec_hphl_dac_event @ 0010509c size=708
// signature: undefined wcd9378_codec_hphl_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_hphl_dac_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x28);
  lVar2 = lVar3 + -0xd0;
  lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar2,0x401800ce,0x10,0);
    snd_soc_component_update_bits(lVar2,0x401800ce,2,0);
    snd_soc_component_update_bits(lVar2,0x4018044e,4,0);
    lVar5 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    local_4c[0] = 0;
    local_54[0] = 0;
    local_58[0] = 0;
    iVar1 = wcd9378_set_port_params(lVar2,0xe,local_4c,local_50,local_54,&local_5c,local_58,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar5 + 0x38),local_4c,1,local_54,local_58);
    }
    if (*(char *)(lVar4 + 0x178) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_4c[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      iVar1 = wcd9378_set_port_params(lVar2,0x10,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar3 + 0x38),local_4c,1,local_54,local_58);
      }
    }
  }
  else if (param_3 == 1) {
    snd_soc_component_update_bits(lVar2,0x401800ce,0x10,0x10);
    snd_soc_component_update_bits(lVar2,0x401800ce,2,2);
    snd_soc_component_update_bits(lVar2,0x4018044e,4,4);
    snd_soc_component_update_bits(lVar2,0x401800d9,0x80,0);
    lVar5 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    local_4c[0] = 0;
    local_50[0] = 0;
    local_54[0] = 0;
    local_58[0] = 0;
    local_5c = 0;
    iVar1 = wcd9378_set_port_params(lVar2,0xe,local_4c,local_50,local_54,&local_5c,local_58,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar5 + 0x38),local_4c,1,local_54,&local_5c,local_50,local_58
                      );
    }
    if (*(char *)(lVar4 + 0x178) != '\0') {
      snd_soc_component_update_bits(lVar2,0x40180414,2,2);
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_4c[0] = 0;
      local_50[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      local_5c = 0;
      iVar1 = wcd9378_set_port_params(lVar2,0x10,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x38),local_4c,1,local_54,&local_5c,local_50,
                         local_58);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_hphr_dac_event @ 00105364 size=708
// signature: undefined wcd9378_codec_hphr_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_hphr_dac_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x28);
  lVar2 = lVar3 + -0xd0;
  lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar2,0x401800ce,0x10,0);
    snd_soc_component_update_bits(lVar2,0x401800ce,2,0);
    snd_soc_component_update_bits(lVar2,0x4018044e,8,0);
    lVar5 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    local_4c[0] = 0;
    local_54[0] = 0;
    local_58[0] = 0;
    iVar1 = wcd9378_set_port_params(lVar2,0xf,local_4c,local_50,local_54,&local_5c,local_58,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar5 + 0x38),local_4c,1,local_54,local_58);
    }
    if (*(char *)(lVar4 + 0x179) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_4c[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      iVar1 = wcd9378_set_port_params(lVar2,0x11,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar3 + 0x38),local_4c,1,local_54,local_58);
      }
    }
  }
  else if (param_3 == 1) {
    snd_soc_component_update_bits(lVar2,0x401800ce,0x10,0x10);
    snd_soc_component_update_bits(lVar2,0x401800ce,2,2);
    snd_soc_component_update_bits(lVar2,0x4018044e,8,8);
    snd_soc_component_update_bits(lVar2,0x401800d9,0x80,0);
    lVar5 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    local_4c[0] = 0;
    local_50[0] = 0;
    local_54[0] = 0;
    local_58[0] = 0;
    local_5c = 0;
    iVar1 = wcd9378_set_port_params(lVar2,0xf,local_4c,local_50,local_54,&local_5c,local_58,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar5 + 0x38),local_4c,1,local_54,&local_5c,local_50,local_58
                      );
    }
    if (*(char *)(lVar4 + 0x179) != '\0') {
      snd_soc_component_update_bits(lVar2,0x40180414,1,1);
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_4c[0] = 0;
      local_50[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      local_5c = 0;
      iVar1 = wcd9378_set_port_params(lVar2,0x11,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x38),local_4c,1,local_54,&local_5c,local_50,
                         local_58);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_hph_sequencer_enable @ 0010562c size=852
// signature: undefined wcd9378_hph_sequencer_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_hph_sequencer_enable(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  ushort uVar2;
  char cVar3;
  bool bVar4;
  ushort uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  undefined8 *puVar13;
  undefined1 local_5c [4];
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  lVar12 = *(long *)(param_1 + 0x28);
  lVar11 = lVar12 + -0xd0;
  puVar13 = *(undefined8 **)(*(long *)(lVar12 + -0xb8) + 0x98);
  lVar10 = puVar13[8];
  local_5c[0] = 2;
  if (param_3 == 8) {
    regmap_write(puVar13[6],0x40c04309,1);
    regmap_write(puVar13[6],0x40c0430a,1);
    swr_write(lVar10,*(undefined1 *)(lVar10 + 0x40),0x4c,local_5c);
    snd_soc_component_update_bits(lVar11,0x40c00488,0xff,3);
    if ((*(char *)(puVar13 + 0x2f) == '\0') || (*(char *)((long)puVar13 + 0x179) == '\0')) {
      uVar6 = 0x5eec;
      uVar7 = 0x5ef6;
    }
    else {
      uVar6 = 0x2c24;
      uVar7 = 0x2c2e;
    }
    usleep_range_state(uVar6,uVar7,2);
    lVar11 = *(long *)(*(long *)(lVar12 + -0xb8) + 0x98);
    lVar10 = lVar11 + 0xe8;
    mutex_lock(lVar10);
    puVar1 = (ulong *)(lVar11 + 0x10);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 & 0xffffffffffffefff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    mutex_unlock(lVar10);
  }
  else if (param_3 == 1) {
    wcd9378_sys_usage_auto_udpate(lVar11,0xc);
    regmap_write(puVar13[6],0x40c00008,2);
    if ((*(char *)(puVar13 + 0x2f) == '\0') || (*(char *)((long)puVar13 + 0x179) == '\0')) {
      snd_soc_component_update_bits(lVar11,0x40180517,7,7);
      snd_soc_component_update_bits(lVar11,0x4018051c,7,7);
    }
    uVar9 = *(uint *)(puVar13 + 0x2b);
    if ((uVar9 < 9) && ((1 << (ulong)(uVar9 & 0x1f) & 0x1c8U) != 0)) {
      snd_soc_component_update_bits(lVar11,0x4018016a,0x80,0x80);
      uVar9 = *(uint *)(puVar13 + 0x2b);
    }
    if (uVar9 - 1 < 8) {
      uVar8 = *(undefined4 *)(&DAT_00158454 + (long)(int)(uVar9 - 1) * 4);
    }
    else {
      uVar8 = 3;
    }
    snd_soc_component_update_bits(lVar11,0x40c000a0,0xff,uVar8);
    snd_soc_component_update_bits(lVar11,0x40c00488,0xff,0);
    lVar12 = *(long *)(*(long *)(lVar12 + -0xb8) + 0x98);
    if ((*(char *)(lVar12 + 0x178) == '\0') && (*(char *)(lVar12 + 0x179) == '\0')) {
      uVar2 = *(ushort *)(lVar12 + 0x15c);
      uVar5 = uVar2 >> 8;
      regmap_write(*(undefined8 *)(lVar12 + 0x30),0x40c06311,uVar5);
      uVar2 = uVar2 & 0xff;
      regmap_write(*(undefined8 *)(lVar12 + 0x30),0x40c04311,uVar2);
      regmap_write(*(undefined8 *)(lVar12 + 0x30),0x40c06312,uVar5);
      regmap_write(*(undefined8 *)(lVar12 + 0x30),0x40c04312,uVar2);
    }
    if ((*(char *)(puVar13 + 0x2f) == '\0') || (*(char *)((long)puVar13 + 0x179) == '\0')) {
      uVar6 = 0x57e4;
      uVar7 = 0x57ee;
    }
    else {
      uVar6 = 0x251c;
      uVar7 = 0x2526;
    }
    usleep_range_state(uVar6,uVar7,2);
    regmap_write(puVar13[6],0x40c04309,0);
    regmap_write(puVar13[6],0x40c0430a,0);
    if (*(int *)(puVar13 + 1) == 10) {
      snd_soc_component_update_bits(lVar11,0x40800388,1,0);
    }
    swr_write(lVar10,*(undefined1 *)(lVar10 + 0x40),0x4c,local_5c);
    wcd9378_swr_slvdev_datapath_control(*puVar13,0,1);
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_enable_hphl_pa @ 00105990 size=412
// signature: undefined wcd9378_codec_enable_hphl_pa(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_hphl_pa(long param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x28);
  local_3c = 0;
  lVar2 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
  swr_read(*(long *)(lVar2 + 0x38),*(undefined1 *)(*(long *)(lVar2 + 0x38) + 0x40),0x44,&local_3c,1)
  ;
  if (param_3 == 8) {
    pcVar1 = *(code **)(lVar2 + 0xc90);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105aa0);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(lVar2 + 0xc88),1,1);
    }
    wcd_disable_irq(lVar2 + 0x188,0xd);
    pcVar1 = *(code **)(lVar2 + 0xc90);
    if ((pcVar1 != (code *)0x0) && (*(char *)(lVar2 + 0x178) != '\0')) {
      if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105ae4);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(lVar2 + 0xc88),4,0);
    }
    blocking_notifier_call_chain(*(long *)(lVar2 + 0x150) + 0x428,10);
  }
  else if (param_3 == 1) {
    pcVar1 = *(code **)(lVar2 + 0xc90);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105a20);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(lVar2 + 0xc88),1,1);
      pcVar1 = *(code **)(lVar2 + 0xc90);
      if (pcVar1 != (code *)0x0) {
        if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105a50);
          (*pcVar1)();
        }
        (*pcVar1)(*(undefined8 *)(lVar2 + 0xc88),1,0);
      }
    }
    wcd_enable_irq(lVar2 + 0x188,0xd);
    snd_soc_component_read(lVar3 + -0xd0,0x40c80480);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_enable_hphr_pa @ 00105b30 size=328
// signature: undefined wcd9378_codec_enable_hphr_pa(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_hphr_pa(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x28);
  lVar3 = *(long *)(*(long *)(lVar1 + -0xb8) + 0x98);
  if (param_3 == 8) {
    pcVar2 = *(code **)(lVar3 + 0xc90);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105c0c);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(lVar3 + 0xc88),1,0x10001);
    }
    wcd_disable_irq(lVar3 + 0x188,0xe);
    pcVar2 = *(code **)(lVar3 + 0xc90);
    if ((pcVar2 != (code *)0x0) && (*(char *)(lVar3 + 0x179) != '\0')) {
      if (*(int *)(pcVar2 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105c50);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(lVar3 + 0xc88),4,0x10000);
    }
    blocking_notifier_call_chain(*(long *)(lVar3 + 0x150) + 0x428,0xc);
  }
  else if (param_3 == 1) {
    pcVar2 = *(code **)(lVar3 + 0xc90);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x105b8c);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(lVar3 + 0xc88),1,0x10001);
      pcVar2 = *(code **)(lVar3 + 0xc90);
      if (pcVar2 != (code *)0x0) {
        if (*(int *)(pcVar2 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105bbc);
          (*pcVar2)();
        }
        (*pcVar2)(*(undefined8 *)(lVar3 + 0xc88),1,0x10000);
      }
    }
    wcd_enable_irq(lVar3 + 0x188,0xe);
    snd_soc_component_read(lVar1 + -0xd0,0x40c80480);
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_sa_sequencer_enable @ 00105c7c size=264
// signature: undefined wcd9378_sa_sequencer_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_sa_sequencer_enable(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar1,0x40800388,1,1);
    snd_soc_component_update_bits(lVar1,0x40800408,0xff,3);
    usleep_range_state(0x3c28,0x3c32,2);
  }
  else if (param_3 == 1) {
    lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    snd_soc_component_update_bits(lVar1,0x40800408,0xff,0);
    usleep_range_state(0x2198,0x21a2,2);
    snd_soc_component_update_bits(lVar1,0x40800388,1,0);
    if (*(int *)(lVar2 + 8) == 10) {
      regmap_write(*(undefined8 *)(lVar2 + 0x30),0x40c00309,0);
      regmap_write(*(undefined8 *)(lVar2 + 0x30),0x40c0030a,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_ear_dac_event @ 00105d88 size=1032
// signature: undefined wcd9378_codec_ear_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_ear_dac_event(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 *puVar10;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar9 = *(long *)(param_1 + 0x28);
  lVar7 = lVar9 + -0xd0;
  puVar10 = *(undefined8 **)(*(long *)(lVar9 + -0xb8) + 0x98);
  uVar5 = snd_soc_component_read(lVar7,0x4018044f);
  if (param_3 == 8) {
    if (((uint)puVar10[2] >> 0xb & 1) == 0) {
      lVar8 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      local_4c[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      iVar4 = wcd9378_set_port_params(lVar7,0x13,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar4 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar8 + 0x38),local_4c,1,local_54,local_58);
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      lVar7 = lVar9 + 0xe8;
      mutex_lock(lVar7);
      puVar1 = (ulong *)(lVar9 + 0x10);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffeff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      mutex_unlock(lVar7);
      wcd9378_swr_slvdev_datapath_control(*puVar10,0,0);
    }
    else {
      snd_soc_component_update_bits(lVar7,0x4018044e,4,0);
      lVar8 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      local_4c[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      iVar4 = wcd9378_set_port_params(lVar7,0xe,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar4 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar8 + 0x38),local_4c,1,local_54,local_58);
      }
      if (*(char *)(puVar10 + 0x2f) != '\0') {
        snd_soc_component_update_bits(lVar7,0x40180414,4,0);
        lVar8 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
        local_4c[0] = 0;
        local_54[0] = 0;
        local_58[0] = 0;
        iVar4 = wcd9378_set_port_params(lVar7,0x10,local_4c,local_50,local_54,&local_5c,local_58,1);
        if (iVar4 == 0) {
          swr_disconnect_port(*(undefined8 *)(lVar8 + 0x38),local_4c,1,local_54,local_58);
        }
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      lVar7 = lVar9 + 0xe8;
      mutex_lock(lVar7);
      puVar1 = (ulong *)(lVar9 + 0x10);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffff7ff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      mutex_unlock(lVar7);
    }
  }
  else if (param_3 == 1) {
    if ((uVar5 & 1) == 0) {
      snd_soc_component_update_bits(lVar7,0x4018044e,4,4);
      wcd9378_sys_usage_auto_udpate(lVar7,0xb,1);
      if (*(char *)(puVar10 + 0x2f) != '\0') {
        snd_soc_component_update_bits(lVar7,0x40180414,4,4);
        lVar8 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
        local_4c[0] = 0;
        local_50[0] = 0;
        local_54[0] = 0;
        local_58[0] = 0;
        local_5c = 0;
        iVar4 = wcd9378_set_port_params(lVar7,0x10,local_4c,local_50,local_54,&local_5c,local_58,1);
        if (iVar4 == 0) {
          swr_connect_port(*(undefined8 *)(lVar8 + 0x38),local_4c,1,local_54,&local_5c,local_50,
                           local_58);
        }
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      uVar6 = 0xe;
    }
    else {
      wcd9378_sys_usage_auto_udpate(lVar7,8,1);
      snd_soc_component_update_bits(lVar7,0x401805c3,0x20,0x20);
      snd_soc_component_update_bits(lVar7,0x4018016a,0x80,0x80);
      if (*(int *)((long)puVar10 + 0x164) != 0) {
        snd_soc_component_update_bits(lVar7,0x4018040b,0x40,0x40);
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      uVar6 = 0x13;
    }
    local_4c[0] = 0;
    local_50[0] = 0;
    local_54[0] = 0;
    local_58[0] = 0;
    local_5c = 0;
    iVar4 = wcd9378_set_port_params(lVar7,uVar6,local_4c,local_50,local_54,&local_5c,local_58,1);
    if (iVar4 == 0) {
      swr_connect_port(*(undefined8 *)(lVar9 + 0x38),local_4c,1,local_54,&local_5c,local_50,local_58
                      );
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_aux_dac_event @ 001061ac size=768
// signature: undefined wcd9378_codec_aux_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_aux_dac_event(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined8 *puVar10;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar9 = *(long *)(param_1 + 0x28);
  lVar7 = lVar9 + -0xd0;
  puVar10 = *(undefined8 **)(*(long *)(lVar9 + -0xb8) + 0x98);
  uVar5 = snd_soc_component_read(lVar7,0x4018044f);
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar7,0x40180128,0x40,0);
    lVar8 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
    if (((uint)puVar10[2] >> 10 & 1) == 0) {
      local_4c[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      iVar4 = wcd9378_set_port_params(lVar7,0x13,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar4 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar8 + 0x38),local_4c,1,local_54,local_58);
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      lVar7 = lVar9 + 0xe8;
      mutex_lock(lVar7);
      puVar1 = (ulong *)(lVar9 + 0x10);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffdff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      mutex_unlock(lVar7);
      wcd9378_swr_slvdev_datapath_control(*puVar10,0,0);
    }
    else {
      local_4c[0] = 0;
      local_54[0] = 0;
      local_58[0] = 0;
      iVar4 = wcd9378_set_port_params(lVar7,0xf,local_4c,local_50,local_54,&local_5c,local_58,1);
      if (iVar4 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar8 + 0x38),local_4c,1,local_54,local_58);
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      lVar7 = lVar9 + 0xe8;
      mutex_lock(lVar7);
      puVar1 = (ulong *)(lVar9 + 0x10);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffbff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      mutex_unlock(lVar7);
    }
  }
  else if (param_3 == 1) {
    snd_soc_component_update_bits(lVar7,0x40180128,0x40,0x40);
    if ((uVar5 & 1) == 0) {
      snd_soc_component_update_bits(lVar7,0x4018044e,8,8);
      wcd9378_sys_usage_auto_udpate(lVar7,10,1);
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      uVar6 = 0xf;
    }
    else {
      wcd9378_sys_usage_auto_udpate(lVar7,9,1);
      if (*(int *)((long)puVar10 + 0x164) != 0) {
        snd_soc_component_update_bits(lVar7,0x4018040b,0x40,0x40);
      }
      lVar9 = *(long *)(*(long *)(lVar9 + -0xb8) + 0x98);
      uVar6 = 0x13;
    }
    local_4c[0] = 0;
    local_50[0] = 0;
    local_54[0] = 0;
    local_58[0] = 0;
    local_5c = 0;
    iVar4 = wcd9378_set_port_params(lVar7,uVar6,local_4c,local_50,local_54,&local_5c,local_58,1);
    if (iVar4 == 0) {
      swr_connect_port(*(undefined8 *)(lVar9 + 0x38),local_4c,1,local_54,&local_5c,local_50,local_58
                      );
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_enable_ear_pa @ 001064c8 size=320
// signature: undefined wcd9378_codec_enable_ear_pa(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_ear_pa(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  
  lVar2 = *(long *)(param_1 + 0x28);
  puVar5 = *(undefined8 **)(*(long *)(lVar2 + -0xb8) + 0x98);
  if (param_3 == 8) {
    pcVar3 = (code *)puVar5[0x192];
    if (((uint)puVar5[2] >> 0xb & 1) == 0) {
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1065a8);
          (*pcVar3)();
        }
        (*pcVar3)(puVar5[0x191],1,0x20001);
      }
      uVar1 = 0xf;
    }
    else {
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1065e0);
          (*pcVar3)();
        }
        (*pcVar3)(puVar5[0x191],1,1);
      }
      uVar1 = 0xd;
    }
    wcd_disable_irq(puVar5 + 0x31,uVar1);
  }
  else if (param_3 == 1) {
    wcd9378_swr_slvdev_datapath_control(*puVar5,0);
    pcVar3 = (code *)puVar5[0x192];
    uVar4 = 0xf;
    if ((puVar5[2] & 0x800) != 0) {
      uVar4 = 0xd;
    }
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10654c);
        (*pcVar3)();
      }
      (*pcVar3)(puVar5[0x191],1,(int)(puVar5[2] & 0x800) << 6 ^ 0x20000);
    }
    wcd_enable_irq(puVar5 + 0x31,uVar4);
    snd_soc_component_read(lVar2 + -0xd0,0x40880400);
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_enable_aux_pa @ 0010660c size=324
// signature: undefined wcd9378_codec_enable_aux_pa(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_aux_pa(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  
  lVar2 = *(long *)(param_1 + 0x28);
  puVar6 = *(undefined8 **)(*(long *)(lVar2 + -0xb8) + 0x98);
  if (param_3 == 8) {
    pcVar3 = (code *)puVar6[0x192];
    if (((uint)puVar6[2] >> 10 & 1) == 0) {
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1066f0);
          (*pcVar3)();
        }
        (*pcVar3)(puVar6[0x191],1,0x20001);
      }
      uVar1 = 0xf;
    }
    else {
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106728);
          (*pcVar3)();
        }
        (*pcVar3)(puVar6[0x191],1,0x10001);
      }
      uVar1 = 0xe;
    }
    wcd_disable_irq(puVar6 + 0x31,uVar1);
  }
  else if (param_3 == 1) {
    wcd9378_swr_slvdev_datapath_control(*puVar6,0);
    pcVar3 = (code *)puVar6[0x192];
    uVar5 = 0xe;
    if ((puVar6[2] & 0x400) == 0) {
      uVar5 = 0xf;
    }
    if (pcVar3 != (code *)0x0) {
      uVar4 = 0x20000;
      if ((puVar6[2] & 0x400) != 0) {
        uVar4 = 0x10000;
      }
      if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106694);
        (*pcVar3)();
      }
      (*pcVar3)(puVar6[0x191],1,uVar4);
    }
    wcd_enable_irq(puVar6 + 0x31,uVar5);
    snd_soc_component_read(lVar2 + -0xd0,0x40880400);
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_enable_vdd_buck @ 00106754 size=340
// signature: undefined wcd9378_codec_enable_vdd_buck(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_vdd_buck(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  
  lVar10 = *(long *)(param_1 + 0x28);
  lVar8 = *(long *)(lVar10 + -0xb8);
  plVar9 = *(long **)(lVar8 + 0x98);
  lVar11 = *(long *)(*plVar9 + 0x90);
  if (lVar11 == 0) {
    pcVar7 = "%s: pdata is NULL\n";
LAB_00106850:
    _dev_err(lVar8,pcVar7,"wcd9378_codec_enable_vdd_buck");
    uVar6 = 0xffffffea;
  }
  else {
    uVar5 = msm_cdc_is_ondemand_supply
                      (*plVar9,plVar9[0x18d],*(undefined8 *)(lVar11 + 0x40),
                       *(undefined4 *)(lVar11 + 0x48),"cdc-vdd-buck");
    if ((uVar5 & 1) != 0) {
      if (param_3 == 8) {
        puVar1 = (ulong *)(plVar9 + 0x37);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 0x10;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      else if (param_3 == 1) {
        if (((uint)plVar9[0x37] >> 4 & 1) == 0) {
          iVar4 = msm_cdc_enable_ondemand_supply
                            (*plVar9,plVar9[0x18d],*(undefined8 *)(lVar11 + 0x40),
                             *(undefined4 *)(lVar11 + 0x48),"cdc-vdd-buck");
          if (iVar4 == -0x16) {
            lVar8 = *(long *)(lVar10 + -0xb8);
            pcVar7 = "%s: vdd buck is not enabled\n";
            goto LAB_00106850;
          }
          puVar1 = (ulong *)(plVar9 + 0x37);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 & 0xffffffffffffffef;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          usleep_range_state(200,0xfa,2);
        }
        else {
          puVar1 = (ulong *)(plVar9 + 0x37);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 & 0xffffffffffffffef;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
        }
      }
    }
    uVar6 = 0;
  }
  return uVar6;
}



//------------------------------------------------------------
// wcd9378_enable_clsh @ 001068d4 size=128
// signature: undefined wcd9378_enable_clsh(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_enable_clsh(long param_1,undefined8 param_2,uint param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  uVar1 = *(uint *)(puVar3 + 0x2b);
  if (uVar1 < 6 && (1 << (ulong)(uVar1 & 0x1f) & 0x36U) != 0) {
    wcd9378_rx_connect_port(*(long *)(param_1 + 0x28) + -0xd0,0x12,param_3 & 3);
  }
  if ((param_3 & 0xc) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = wcd9378_swr_slvdev_datapath_control(*puVar3,0,0);
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd9378_tx_swr_ctrl @ 00106958 size=104
// signature: undefined wcd9378_tx_swr_ctrl(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_tx_swr_ctrl(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_3 == 8) {
    lVar2 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98) + 0x40);
    uVar1 = swr_slvdev_datapath_control(lVar2,*(undefined1 *)(lVar2 + 0x40),0);
  }
  else {
    if (param_3 == 1) {
      wcd9378_tx_connect_port
                (*(long *)(param_1 + 0x28) + -0xd0,*(undefined1 *)(param_1 + 0x4c),2400000,1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd9378_codec_enable_micbias @ 001069c4 size=224
// signature: undefined wcd9378_codec_enable_micbias(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_micbias(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"MIC BIAS1",10);
  if (lVar1 == 0) {
    lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"MIC BIAS2",10);
    if (lVar1 == 0) {
      lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"MIC BIAS3",10);
      if (lVar1 == 0) {
        return 0xffffffea;
      }
      uVar2 = 3;
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 1;
  }
  if (param_3 == 8) {
    uVar3 = 3;
  }
  else {
    if (param_3 == 2) {
      usleep_range_state(1000,0x44c,2);
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    uVar3 = 2;
  }
  wcd9378_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd9378_codec_enable_micbias_pullup @ 00106aa8 size=224
// signature: undefined wcd9378_codec_enable_micbias_pullup(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_codec_enable_micbias_pullup(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"VA MIC BIAS1",0xd);
  if (lVar1 == 0) {
    lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"VA MIC BIAS2",0xd);
    if (lVar1 == 0) {
      lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"VA MIC BIAS3",0xd);
      if (lVar1 == 0) {
        return 0xffffffea;
      }
      uVar2 = 3;
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 1;
  }
  if (param_3 == 8) {
    uVar3 = 1;
  }
  else {
    if (param_3 == 2) {
      usleep_range_state(1000,0x44c,2);
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    uVar3 = 0;
  }
  wcd9378_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd9378_sys_usage_auto_udpate @ 00106b88 size=500
// signature: undefined wcd9378_sys_usage_auto_udpate(void)
// callers: [wcd9378_tx_sequencer_enable, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event, wcd9378_hph_sequencer_enable]
//------------------------------------------------------------

void wcd9378_sys_usage_auto_udpate(long param_1,ulong param_2,ulong param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  ulong uVar5;
  ulong uVar6;
  undefined4 uVar7;
  long lVar8;
  
  lVar8 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  mutex_lock(lVar8 + 0xe8);
  uVar6 = (param_2 & 0xffffffff) >> 6;
  uVar5 = 1L << (param_2 & 0x3f);
  if ((param_3 & 1) == 0) {
    puVar1 = (ulong *)(lVar8 + 0x10 + uVar6 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & (uVar5 ^ 0xffffffffffffffff);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  else {
    puVar1 = (ulong *)(lVar8 + 0x10 + uVar6 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | uVar5;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (0xc < *(uint *)(lVar8 + 8)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x106d58);
      (*pcVar4)();
    }
    uVar5 = *(ulong *)(lVar8 + 0x10);
    if ((uVar5 & ((long)*(int *)(sys_usage + (ulong)*(uint *)(lVar8 + 8) * 4) ^ 0xffffffffffffffffU)
        ) != 0) {
      if ((uVar5 & 0xfffffffffffff36a) == 0) {
        uVar7 = 0;
      }
      else if ((uVar5 & 0xffffffffffffed58) == 0) {
        uVar7 = 1;
      }
      else if ((uVar5 & 0xfffffffffffff366) == 0) {
        uVar7 = 2;
      }
      else if ((uVar5 & 0xffffffffffffe554) == 0) {
        uVar7 = 3;
      }
      else if ((uVar5 & 0xfffffffffffff76b) == 0) {
        uVar7 = 4;
      }
      else if ((uVar5 & 0xffffffffffffee59) == 0) {
        uVar7 = 5;
      }
      else if ((uVar5 & 0xfffffffffffff767) == 0) {
        uVar7 = 6;
      }
      else if ((uVar5 & 0xffffffffffffee54) == 0) {
        uVar7 = 7;
      }
      else if ((uVar5 & 0xffffffffffffed95) == 0) {
        uVar7 = 8;
      }
      else if ((uVar5 & 0xffffffffffffee94) == 0) {
        uVar7 = 9;
      }
      else if ((uVar5 & 0xffffffffffffe358) == 0) {
        uVar7 = 10;
      }
      else if ((uVar5 & 0xffffffffffffee6a) == 0) {
        uVar7 = 0xb;
      }
      else {
        if ((uVar5 & 0xffffffffffffed69) != 0) goto LAB_00106d34;
        uVar7 = 0xc;
      }
      snd_soc_component_update_bits(param_1,0x40180501,0xf,uVar7);
      *(undefined4 *)(lVar8 + 8) = uVar7;
    }
  }
LAB_00106d34:
  mutex_unlock(lVar8 + 0xe8);
  return;
}



//------------------------------------------------------------
// wcd9378_tx_connect_port @ 00106d90 size=280
// signature: undefined wcd9378_tx_connect_port(void)
// callers: [wcd9378_tx_sequencer_enable, wcd9378_codec_enable_dmic, wcd9378_tx_swr_ctrl]
//------------------------------------------------------------

void wcd9378_tx_connect_port(long param_1,undefined8 param_2,int param_3,char param_4)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  int local_4c;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c[0] = 0;
  local_40[0] = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  local_44[0] = 0;
  local_48[0] = 0;
  local_4c = 0;
  iVar2 = wcd9378_set_port_params(param_1,param_2,local_3c,local_40,local_44,&local_4c,local_48,0);
  if (iVar2 == 0) {
    if (param_3 != 0) {
      local_4c = param_3;
    }
    uVar1 = (int)param_2 - 0x1d;
    if ((uVar1 & 0xff) < 0xd) {
      local_48[0] = *(undefined1 *)
                     (lVar4 + (ulong)(byte)wcd9378_swr_slv_tx_ch_idx
                                           [*(long *)(&DAT_00113558 + (long)(char)uVar1 * 8) * 2 + 1
                                           ] + 0xccc);
    }
    uVar3 = *(undefined8 *)(lVar4 + 0x40);
    if (param_4 == '\0') {
      swr_disconnect_port(uVar3,local_3c,1,local_44,local_48);
    }
    else {
      swr_connect_port(uVar3,local_3c,1,local_44,&local_4c,local_40,local_48);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_swr_slvdev_datapath_control @ 00106ea8 size=384
// signature: undefined wcd9378_swr_slvdev_datapath_control(void)
// callers: [wcd9378_codec_enable_ear_pa, wcd9378_codec_enable_aux_pa, wcd9378_tx_sequencer_enable, wcd9378_hph_sequencer_enable, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event, wcd9378_enable_clsh]
//------------------------------------------------------------

void wcd9378_swr_slvdev_datapath_control(long param_1,int param_2,uint param_3)

{
  long lVar1;
  byte bVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 *puVar6;
  byte bVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  long lVar10;
  undefined1 *puVar11;
  long lVar12;
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  undefined1 local_54 [4];
  undefined1 local_50 [4];
  uint local_4c;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_1 + 0x98);
  local_50[0] = 0;
  local_54[0] = 0;
  if (lVar12 == 0) {
    uVar5 = 0xffffffea;
    goto LAB_00106ff4;
  }
  bVar3 = param_2 != 0;
  lVar1 = 0xcdb;
  if (bVar3) {
    lVar1 = 0xcdd;
  }
  lVar10 = 0x38;
  if (bVar3) {
    lVar10 = 0x40;
  }
  local_58[0] = *(undefined1 *)(lVar12 + lVar1);
  lVar1 = 0xcdc;
  if (bVar3) {
    lVar1 = 0xcde;
  }
  lVar10 = *(long *)(lVar12 + lVar10);
  local_5c[0] = *(undefined1 *)(lVar12 + lVar1);
  local_4c = 0;
  iVar4 = swr_read(lVar10,*(undefined1 *)(lVar10 + 0x40),0x44,&local_4c,1);
  bVar3 = (local_4c & 0x40) != 0;
  bVar7 = 0x62;
  uVar8 = 0x72;
  if (iVar4 != 0 || bVar3) {
    uVar8 = 0x62;
  }
  uVar9 = 0x62;
  if (iVar4 != 0 || bVar3) {
    uVar9 = 0x72;
  }
  if ((param_3 & 1) == 0) {
    if (param_2 != 0) {
      if (param_2 == 1) {
        bVar7 = *(byte *)(lVar12 + 0x10);
        bVar2 = bVar7 & 0xfc;
        goto joined_r0x00106fa0;
      }
LAB_00106fa4:
      puVar11 = local_54;
      puVar6 = local_50;
      goto LAB_00106fac;
    }
    bVar7 = *(byte *)(lVar12 + 0x11);
    bVar2 = bVar7 & 0x1f;
joined_r0x00106fa0:
    if (bVar2 == 0) goto LAB_00106fa4;
    param_3 = 0;
  }
  else {
    puVar11 = local_5c;
    puVar6 = local_58;
LAB_00106fac:
    swr_write(bVar7,lVar10,*(undefined1 *)(lVar10 + 0x40),0x4d,puVar6);
    swr_write(lVar10,*(undefined1 *)(lVar10 + 0x40),uVar8,puVar11);
    swr_write(lVar10,*(undefined1 *)(lVar10 + 0x40),uVar9,puVar11);
  }
  uVar5 = swr_slvdev_datapath_control(lVar10,*(undefined1 *)(lVar10 + 0x40),param_3 & 1);
LAB_00106ff4:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_set_port_params @ 00107028 size=424
// signature: undefined wcd9378_set_port_params(void)
// callers: [wcd9378_codec_hphl_dac_event, wcd9378_codec_hphr_dac_event, wcd9378_rx_connect_port, wcd9378_tx_sequencer_enable, wcd9378_tx_connect_port, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event]
//------------------------------------------------------------

undefined8
wcd9378_set_port_params
          (long param_1,uint param_2,undefined1 *param_3,undefined1 *param_4,undefined1 *param_5,
          undefined4 *param_6,undefined1 *param_7,byte param_8)

{
  code *pcVar1;
  bool bVar2;
  char *pcVar3;
  long lVar4;
  byte *pbVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (param_8 == 0) {
    lVar6 = lVar4 + 0x1c4;
    pbVar5 = (byte *)(lVar4 + 0x1c0);
  }
  else {
    if (param_8 != 1) {
      param_2 = (uint)param_8;
      pcVar3 = "%s Invalid path selected %u\n";
      goto LAB_001071c0;
    }
    lVar6 = lVar4 + 0x6c4;
    pbVar5 = (byte *)(lVar4 + 0x1c1);
  }
  lVar4 = 0;
  bVar2 = false;
  param_2 = param_2 & 0xff;
  lVar8 = 1;
  uVar7 = 0;
  do {
    if ((int)lVar4 == 0x500) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1071d0);
      (*pcVar1)();
    }
    if (*(uint *)(lVar6 + lVar4) == param_2) {
      lVar8 = 0;
LAB_00107150:
      if (!bVar2) {
        *param_3 = (char)uVar7;
        lVar4 = lVar6 + lVar8 * 0x14 + lVar4;
        *param_4 = (char)*(undefined4 *)(lVar4 + 0xc);
        *param_5 = (char)*(undefined4 *)(lVar4 + 8);
        *param_6 = *(undefined4 *)(lVar4 + 0x10);
        *param_7 = (char)*(undefined4 *)(lVar4 + 4);
        return 0;
      }
      break;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x14) == param_2) goto LAB_00107150;
    if (*(uint *)(lVar6 + lVar4 + 0x28) == param_2) {
      lVar8 = 2;
      goto LAB_00107150;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x3c) == param_2) {
      lVar8 = 3;
      goto LAB_00107150;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x50) == param_2) {
      lVar8 = 4;
      goto LAB_00107150;
    }
    if (*(uint *)(lVar6 + lVar4 + 100) == param_2) {
      lVar8 = 5;
      goto LAB_00107150;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x78) == param_2) {
      lVar8 = 6;
      goto LAB_00107150;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x8c) == param_2) {
      lVar8 = 7;
      goto LAB_00107150;
    }
    bVar2 = *pbVar5 <= uVar7;
    lVar4 = lVar4 + 0xa0;
    uVar7 = uVar7 + 1;
  } while ((uint)*pbVar5 * 0xa0 + 0xa0 != (int)lVar4);
  pcVar3 = "%s Failed to find slave port for type %u\n";
LAB_001071c0:
  _dev_err(*(long *)(param_1 + 0x18),pcVar3,"wcd9378_set_port_params",param_2);
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_rx_connect_port @ 001071d0 size=196
// signature: undefined wcd9378_rx_connect_port(void)
// callers: [wcd9378_enable_clsh]
//------------------------------------------------------------

void wcd9378_rx_connect_port(long param_1,undefined8 param_2,char param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 local_3c;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = 0;
  local_30[0] = 0;
  local_34[0] = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  local_38[0] = 0;
  local_3c = 0;
  iVar1 = wcd9378_set_port_params(param_1,param_2,local_2c,local_30,local_34,&local_3c,local_38,1);
  if (iVar1 == 0) {
    uVar2 = *(undefined8 *)(lVar3 + 0x38);
    if (param_3 == '\0') {
      swr_disconnect_port(uVar2,local_2c,1,local_34,local_38);
    }
    else {
      swr_connect_port(uVar2,local_2c,1,local_34,&local_3c,local_30,local_38);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_init_reg @ 00107294 size=1024
// signature: undefined wcd9378_init_reg(void)
// callers: [wcd9378_event_notify, wcd9378_soc_codec_probe]
//------------------------------------------------------------

void wcd9378_init_reg(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  iVar1 = snd_soc_component_read(param_1,0x401804c0);
  uVar2 = 3;
  if (iVar1 != 0) {
    uVar2 = 1;
  }
  snd_soc_component_update_bits(param_1,0x40180058,3,uVar2);
  snd_soc_component_update_bits(param_1,0x40180103,0xe,0xe);
  snd_soc_component_update_bits(param_1,0x40180103,0x80,0x80);
  usleep_range_state(1000,0x3f2,2);
  snd_soc_component_update_bits(param_1,0x40180103,0x40,0x40);
  usleep_range_state(1000,0x3f2,2);
  snd_soc_component_update_bits(param_1,0x40180029,0xf0,0xb0);
  snd_soc_component_update_bits(param_1,0x40180001,0x80,0x80);
  snd_soc_component_update_bits(param_1,0x40180001,0x40,0x40);
  usleep_range_state(10000,0x271a,2);
  snd_soc_component_update_bits(param_1,0x40180001,0x40,0);
  snd_soc_component_update_bits(param_1,0x40180417,1,1);
  snd_soc_component_update_bits(param_1,0x4018007b,0x80,0x80);
  snd_soc_component_update_bits(param_1,0x40180465,0x18,0x10);
  snd_soc_component_update_bits(param_1,0x40180466,0x18,0x10);
  snd_soc_component_update_bits(param_1,0x4018006c,7,1);
  snd_soc_component_update_bits(param_1,0x4018006f,7,1);
  snd_soc_component_update_bits(param_1,0x40180072,7,1);
  snd_soc_component_update_bits(param_1,0x40180133,0xf,4);
  snd_soc_component_update_bits(param_1,0x40180136,0xf,4);
  snd_soc_component_update_bits(param_1,0x40180132,0xf0,0x50);
  snd_soc_component_update_bits(param_1,0x40180510,7,5);
  snd_soc_component_update_bits(param_1,0x40180519,7,5);
  snd_soc_component_update_bits(param_1,0x4018051b,7,6);
  snd_soc_component_update_bits(param_1,0x4018000a,0x40,0x40);
  snd_soc_component_update_bits(param_1,0x401805b0,3,1);
  snd_soc_component_update_bits(param_1,0x401805b1,3,2);
  snd_soc_component_update_bits(param_1,0x401805b2,3,3);
  snd_soc_component_update_bits(param_1,0x40180501,0xf,0);
  *(undefined4 *)(lVar3 + 8) = 0;
  snd_soc_component_update_bits(param_1,0x40880008,1,1);
  usleep_range_state(20000,0x4e2a,2);
  snd_soc_component_update_bits(param_1,0x40880000,0xff,0xff);
  snd_soc_component_update_bits(param_1,0x40c80008,1,1);
  usleep_range_state(30000,0x753a,2);
  snd_soc_component_update_bits(param_1,0x40c00008,0xff,2);
  snd_soc_component_update_bits(param_1,0x40c80000,0xff,0xff);
  snd_soc_component_update_bits(param_1,0x41080008,1,1);
  usleep_range_state(5000,0x1392,2);
  snd_soc_component_update_bits(param_1,0x41080000,0xff,0xff);
  snd_soc_component_update_bits(param_1,0x41480008,1,1);
  usleep_range_state(5000,0x1392,2);
  snd_soc_component_update_bits(param_1,0x41480000,0xff,0xff);
  snd_soc_component_update_bits(param_1,0x41880008,1,1);
  usleep_range_state(5000,0x1392,2);
  snd_soc_component_update_bits(param_1,0x41880000,0xff,0xff);
  return;
}



//------------------------------------------------------------
// wcd9378_event_notify @ 00107698 size=1208
// signature: undefined wcd9378_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_event_notify(undefined8 param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined2 uVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar10 = sp_el0;
  uVar4 = (uint)param_2 & 0xffff;
  local_38 = *(long *)(lVar10 + 0x638);
  if (6 < uVar4 - 1) goto switchD_001076e8_caseD_5;
  plVar12 = *(long **)(param_3 + 0x98);
  lVar10 = plVar12[4];
  switch(uVar4) {
  case 1:
    puVar1 = (ulong *)(plVar12 + 0x37);
    if ((plVar12[0x37] & 1U) == 0) {
      if (((uint)*puVar1 >> 1 & 1) == 0) goto LAB_00107708;
LAB_001079b0:
      snd_soc_component_update_bits(lVar10,0x4018000f,0x20,0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x400;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      uVar4 = (uint)*puVar1;
    }
    else {
      snd_soc_component_update_bits(lVar10,0x4018000f,0x40,0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x200;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (((uint)*puVar1 >> 1 & 1) != 0) goto LAB_001079b0;
LAB_00107708:
      uVar4 = (uint)*puVar1;
    }
    if ((uVar4 >> 2 & 1) != 0) {
      snd_soc_component_update_bits(lVar10,0x40180011,0x40,0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x800;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    break;
  case 2:
    snd_soc_component_update_bits(lVar10,0x40180009,0xc0,0);
    snd_soc_component_update_bits(lVar10,0x4018000a,0x80,0);
    snd_soc_component_update_bits(lVar10,0x40180128,0x80,0);
    break;
  case 3:
    if (*(char *)((long)plVar12 + 0xcda) != '\0') {
      blocking_notifier_call_chain(plVar12 + 0x19c,0,0);
    }
    *(undefined1 *)(plVar12[0x2a] + 0x3d0) = 1;
    if ((*(int *)(*(long *)(plVar12[0x2a] + 0x90) + 0x58) == 0) ||
       (uVar4 = snd_soc_component_read(lVar10,0x40180014), (uVar4 >> 5 & 1) != 0)) {
      uVar8 = 0;
    }
    else {
      uVar8 = 1;
    }
    *(undefined1 *)((long)plVar12 + 0xcd9) = uVar8;
    wcd9378_mbhc_ssr_down(plVar12[0x2a],lVar10);
    lVar10 = *plVar12;
    if ((lVar10 != 0) && (*(long *)(lVar10 + 0x98) != 0)) {
      if (*(long *)(*(long *)(lVar10 + 0x98) + 0x28) == 0) {
        pcVar7 = "%s: reset gpio device node not specified\n";
      }
      else {
        iVar6 = msm_cdc_pinctrl_select_sleep_state();
        if (iVar6 == 0) {
          usleep_range_state(0x14,0x1e,2);
          break;
        }
        pcVar7 = "%s: wcd sleep state request fail!\n";
      }
      _dev_err(lVar10,pcVar7,"wcd9378_reset_low");
    }
    break;
  case 4:
    wcd9378_reset(*plVar12);
    usleep_range_state(10000,0x271a,2);
    lVar11 = plVar12[8];
    local_40[0] = 0;
    iVar6 = -0x13;
    do {
      usleep_range_state(4000,0xfaa,2);
      iVar5 = swr_get_logical_dev_num(lVar11,*(undefined8 *)(lVar11 + 0x3d8),local_40);
      if (iVar5 == 0) break;
      bVar3 = iVar6 != 0;
      iVar6 = iVar6 + 1;
    } while (bVar3);
    if (iVar5 != 0) {
      _dev_err(lVar11 + 0x48,"%s get devnum %d for dev addr %llx failed\n",
               "wcd9378_get_logical_addr",local_40[0],*(undefined8 *)(lVar11 + 0x3d8));
    }
    local_3c[0] = 0;
    *(undefined1 *)(lVar11 + 0x40) = local_40[0];
    lVar11 = plVar12[7];
    iVar6 = -0x13;
    do {
      usleep_range_state(4000,0xfaa,2);
      iVar5 = swr_get_logical_dev_num(lVar11,*(undefined8 *)(lVar11 + 0x3d8),local_3c);
      if (iVar5 == 0) break;
      bVar3 = iVar6 != 0;
      iVar6 = iVar6 + 1;
    } while (bVar3);
    if (iVar5 != 0) {
      _dev_err(lVar11 + 0x48,"%s get devnum %d for dev addr %llx failed\n",
               "wcd9378_get_logical_addr",local_3c[0],*(undefined8 *)(lVar11 + 0x3d8));
    }
    *(undefined1 *)(lVar11 + 0x40) = local_3c[0];
    *(undefined1 *)(plVar12[8] + 0x3f2) = 0;
    *(undefined1 *)(plVar12[8] + 0x3f3) = 0;
    *(undefined1 *)(plVar12[7] + 0x3f2) = 0;
    *(undefined1 *)(plVar12[7] + 0x3f3) = 0;
    wcd9378_init_reg(lVar10);
    regcache_mark_dirty(plVar12[6]);
    regcache_sync(plVar12[6]);
    lVar11 = plVar12[0x2a];
    iVar6 = wcd9378_mbhc_post_ssr_init(lVar11,lVar10);
    if (iVar6 == 0) {
      wcd9378_mbhc_hs_detect(lVar10,*(undefined8 *)(lVar11 + 0x90));
    }
    else {
      _dev_err(*(undefined8 *)(lVar10 + 0x18),"%s: mbhc initialization failed\n",
               "wcd9378_event_notify");
    }
    *(undefined1 *)(plVar12[0x2a] + 0x3d0) = 0;
    if (*(char *)((long)plVar12 + 0xcda) != '\0') {
      blocking_notifier_call_chain(plVar12 + 0x19c,1,0);
    }
    if (*(char *)((long)plVar12 + 0xcd9) != '\0') {
      lVar10 = -500;
      do {
        __const_udelay(0x418958);
        bVar3 = lVar10 != -1;
        lVar10 = lVar10 + 1;
      } while (bVar3);
    }
    break;
  case 7:
    iVar6 = (int)((ulong)param_2 >> 0x10);
    snd_soc_component_update_bits(lVar10,0x40180407,6,iVar6 << 1);
    if (iVar6 == 2) {
      uVar9 = 0x204;
    }
    else if (iVar6 == 1) {
      uVar9 = 0x203;
    }
    else {
      uVar9 = 0x201;
    }
    *(undefined2 *)((long)plVar12 + 0xcdb) = uVar9;
  }
switchD_001076e8_caseD_5:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_suspend @ 00107b98 size=304
// signature: undefined wcd9378_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  plVar5 = *(long **)(param_1 + 0x98);
  if (plVar5 == (long *)0x0) {
    return 0xffffffea;
  }
  lVar6 = *(long *)(*plVar5 + 0x90);
  if (lVar6 == 0) {
    _dev_err(param_1,"%s: pdata is NULL\n","wcd9378_suspend");
    return 0xffffffea;
  }
  if (((uint)plVar5[0x37] >> 4 & 1) == 0) {
    cVar2 = *(char *)((long)plVar5 + 0x17c);
  }
  else {
    iVar4 = msm_cdc_disable_ondemand_supply
                      (*plVar5,plVar5[0x18d],*(undefined8 *)(lVar6 + 0x40),
                       *(undefined4 *)(lVar6 + 0x48),"cdc-vdd-buck");
    if (iVar4 == -0x16) {
      _dev_err(param_1,"%s: vdd buck is not disabled\n","wcd9378_suspend");
      return 0;
    }
    puVar1 = (ulong *)(plVar5 + 0x37);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xffffffffffffffef;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    cVar2 = *(char *)((long)plVar5 + 0x17c);
  }
  if ((cVar2 != '\0') || ((plVar5[4] != 0 && (*(int *)(plVar5[4] + 0xd0) == 0)))) {
    msm_cdc_set_supplies_lpm_mode
              (*plVar5,plVar5[0x18d],*(undefined8 *)(lVar6 + 0x40),*(undefined4 *)(lVar6 + 0x48),1);
    puVar1 = (ulong *)(plVar5 + 0x37);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x100;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_resume @ 00107ce4 size=168
// signature: undefined wcd9378_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_resume(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  
  if (param_1 == 0) {
    uVar4 = 0xffffffed;
  }
  else {
    plVar6 = *(long **)(param_1 + 0x98);
    if (plVar6 != (long *)0x0) {
      lVar5 = *(long *)(*plVar6 + 0x90);
      if (lVar5 != 0) {
        if (((uint)plVar6[0x37] >> 8 & 1) != 0) {
          msm_cdc_set_supplies_lpm_mode
                    (*plVar6,plVar6[0x18d],*(undefined8 *)(lVar5 + 0x40),
                     *(undefined4 *)(lVar5 + 0x48),0);
          puVar1 = (ulong *)(plVar6 + 0x37);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 & 0xfffffffffffffeff;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
        }
        return 0;
      }
      _dev_err(param_1,"%s: pdata is NULL\n","wcd9378_resume");
    }
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd9378_writeable_register @ 00107d9c size=96
// signature: undefined wcd9378_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd9378_writeable_register(undefined8 param_1,uint param_2)

{
  if ((param_2 >> 0x1e == 0) && ((6 < param_2 - 0x58 || (param_2 - 0x58 == 3)))) {
    if (8 < param_2 - 0xf4) {
      return 0;
    }
    if ((1 << (ulong)(param_2 - 0xf4 & 0x1f) & 0x111U) == 0) {
      return 0;
    }
  }
  return (byte)(&wcd9378_reg_access)[param_2 & 0xfff | (param_2 >> 0x14 & 0xff) << 0xc] >> 1 & 1;
}



//------------------------------------------------------------
// wcd9378_readable_register @ 00107e00 size=96
// signature: undefined wcd9378_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd9378_readable_register(undefined8 param_1,uint param_2)

{
  if ((param_2 >> 0x1e == 0) && ((6 < param_2 - 0x58 || (param_2 - 0x58 == 3)))) {
    if (8 < param_2 - 0xf4) {
      return 0;
    }
    if ((1 << (ulong)(param_2 - 0xf4 & 0x1f) & 0x111U) == 0) {
      return 0;
    }
  }
  return (&wcd9378_reg_access)[param_2 & 0xfff | (param_2 >> 0x14 & 0xff) << 0xc] & 1;
}



//------------------------------------------------------------
// wcd9378_volatile_register @ 00107e64 size=116
// signature: undefined wcd9378_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wcd9378_volatile_register(undefined8 param_1,uint param_2)

{
  if (param_2 >> 0x1e != 0) {
    return ((&wcd9378_reg_access)[param_2 & 0xfff | (param_2 >> 0x14 & 0xff) << 0xc] & 3) == 1;
  }
  if (((param_2 - 0x58 < 7) && (param_2 - 0x58 != 3)) ||
     ((param_2 - 0xf4 < 9 && ((1 << (ulong)(param_2 - 0xf4 & 0x1f) & 0x111U) != 0)))) {
    return true;
  }
  return false;
}



//------------------------------------------------------------
// wcd9378_mbhc_get_impedance @ 00107edc size=80
// signature: undefined wcd9378_mbhc_get_impedance(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_mbhc_get_impedance(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    puVar2 = &DAT_001550ac;
  }
  else {
    if ((param_2 != 0) && (param_3 != 0)) {
      uVar1 = wcd_mbhc_get_impedance();
      return uVar1;
    }
    puVar2 = &DAT_00153f32;
  }
  _printk(puVar2,"wcd9378_mbhc_get_impedance");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_mbhc_hs_detect @ 00107f30 size=124
// signature: undefined wcd9378_mbhc_hs_detect(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

undefined8 wcd9378_mbhc_hs_detect(long param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    puVar2 = &DAT_00154b37;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      lVar3 = *(long *)(lVar3 + 0x150);
      if (lVar3 == 0) {
        _dev_err(*(long *)(param_1 + 0x18),"%s: mbhc not initialized!\n","wcd9378_mbhc_hs_detect");
        return 0xffffffea;
      }
      uVar1 = wcd_mbhc_start(lVar3);
      return uVar1;
    }
    puVar2 = &DAT_001542a4;
  }
  _printk(puVar2,"wcd9378_mbhc_hs_detect");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd9378_mbhc_hs_detect_exit @ 00107fb0 size=116
// signature: undefined wcd9378_mbhc_hs_detect_exit(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_hs_detect_exit(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_00154b37;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      lVar2 = *(long *)(lVar2 + 0x150);
      if (lVar2 == 0) {
        _dev_err(*(long *)(param_1 + 0x18),"%s: mbhc not initialized!\n",
                 "wcd9378_mbhc_hs_detect_exit");
        return;
      }
      wcd_mbhc_stop(lVar2);
      return;
    }
    puVar1 = &DAT_001542a4;
  }
  _printk(puVar1,"wcd9378_mbhc_hs_detect_exit");
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_ssr_down @ 00108028 size=128
// signature: undefined wcd9378_mbhc_ssr_down(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

void wcd9378_mbhc_ssr_down(long param_1,long param_2)

{
  long lVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (lVar1 == 0) {
      _printk(&DAT_001542a4,"wcd9378_mbhc_hs_detect_exit");
    }
    else {
      lVar1 = *(long *)(lVar1 + 0x150);
      if (lVar1 == 0) {
        _dev_err(*(long *)(param_2 + 0x18),"%s: mbhc not initialized!\n",
                 "wcd9378_mbhc_hs_detect_exit");
      }
      else {
        wcd_mbhc_stop(lVar1);
      }
    }
    wcd_mbhc_deinit(param_1);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_post_ssr_init @ 001080ac size=252
// signature: undefined wcd9378_mbhc_post_ssr_init(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

int wcd9378_mbhc_post_ssr_init(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = -0x16;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar2 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (lVar2 == 0) {
      _printk(&DAT_001542a4,"wcd9378_mbhc_post_ssr_init");
    }
    else {
      snd_soc_component_update_bits(param_2,0x40180014,0x20,0x20);
      iVar1 = wcd_mbhc_init(param_1,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
      if (iVar1 == 0) {
        lVar2 = lVar2 + 0x188;
        wcd_disable_irq(lVar2,2);
        wcd_disable_irq(lVar2,3);
        wcd_disable_irq(lVar2,10);
        wcd_disable_irq(lVar2,0xc);
      }
      else {
        _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
                 "wcd9378_mbhc_post_ssr_init");
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd9378_mbhc_init @ 001081ac size=404
// signature: undefined wcd9378_mbhc_init(void)
// callers: [wcd9378_soc_codec_probe]
//------------------------------------------------------------

int wcd9378_mbhc_init(long *param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined *puVar4;
  long lVar5;
  long lVar6;
  
  if (param_2 == 0) {
    puVar4 = &DAT_00154b37;
  }
  else {
    lVar6 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (lVar6 != 0) {
      lVar2 = devm_kmalloc(*(long *)(param_2 + 0x18),0x478,0xdc0);
      if (lVar2 == 0) {
        return -0xc;
      }
      __init_rwsem(lVar2 + 0x428,"&(&wcd9378_mbhc->notifier)->rwsem",&wcd9378_mbhc_init___key);
      lVar3 = *(long *)(param_2 + 0x18);
      *(undefined8 *)(lVar2 + 0x468) = 0;
      *(undefined4 *)(lVar2 + 0x3d4) = 1;
      lVar5 = *(long *)(lVar3 + 0x90);
      if (lVar5 == 0) {
        _dev_err(lVar3,"%s: pdata pointer is NULL\n","wcd9378_mbhc_init");
        return -0x16;
      }
      *(undefined4 *)(lVar2 + 0xd0) = *(undefined4 *)(lVar5 + 0x24);
      iVar1 = wcd_mbhc_init(lVar2,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
      if (iVar1 == 0) {
        lVar6 = lVar6 + 0x188;
        wcd_disable_irq(lVar6,2);
        wcd_disable_irq(lVar6,3);
        wcd_disable_irq(lVar6,10);
        wcd_disable_irq(lVar6,0xc);
        *param_1 = lVar2;
        snd_soc_add_component_controls(param_2,impedance_detect_controls,2);
        snd_soc_add_component_controls(param_2,hph_type_detect_controls,1);
        return 0;
      }
      _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
               "wcd9378_mbhc_init");
      return iVar1;
    }
    puVar4 = &DAT_001542a4;
  }
  _printk(puVar4,"wcd9378_mbhc_init");
  return -0x16;
}



//------------------------------------------------------------
// wcd9378_mbhc_deinit @ 00108344 size=88
// signature: undefined wcd9378_mbhc_deinit(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_deinit(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_00154b37;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      if (*(long *)(lVar2 + 0x150) == 0) {
        return;
      }
      wcd_mbhc_deinit();
      return;
    }
    puVar1 = &DAT_001542a4;
  }
  _printk(puVar1,"wcd9378_mbhc_deinit");
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_get_micbias_val @ 001083a0 size=24
// signature: undefined wcd9378_mbhc_get_micbias_val(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_get_micbias_val(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98) + 0x160);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_bcs_enable @ 001083bc size=40
// signature: undefined wcd9378_mbhc_bcs_enable(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_bcs_enable(long param_1,uint param_2)

{
  wcd9378_disable_bcs_before_slow_insert(*(undefined8 *)(param_1 + 0xf8),(param_2 ^ 0xffffffff) & 1)
  ;
  return;
}



//------------------------------------------------------------
// wcd9378_wcd_mbhc_calc_impedance @ 001083e8 size=1972
// signature: undefined wcd9378_wcd_mbhc_calc_impedance(void)
// callers: []
//------------------------------------------------------------

void wcd9378_wcd_mbhc_calc_impedance(long param_1,uint *param_2,uint *param_3)

{
  long lVar1;
  undefined *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  uint uVar13;
  uint uVar14;
  ulong uVar15;
  undefined4 uVar16;
  int iVar17;
  long lVar18;
  undefined1 *puVar19;
  undefined *puVar20;
  long lVar21;
  long lVar22;
  uint local_74;
  undefined8 local_70;
  long local_68;
  
  lVar18 = sp_el0;
  local_68 = *(long *)(lVar18 + 0x638);
  lVar18 = *(long *)(param_1 + 0xf8);
  local_70 = 0;
  local_74 = 0;
  lVar21 = *(long *)(*(long *)(lVar18 + 0x18) + 0x98);
  uVar15 = mutex_is_locked(param_1 + 0x328);
  if (((uVar15 & 1) == 0) && ((wcd9378_wcd_mbhc_calc_impedance___already_done & 1) == 0)) {
    wcd9378_wcd_mbhc_calc_impedance___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd9378_wcd_mbhc_calc_impedance");
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x108b94);
    (*pcVar6)();
  }
  sVar8 = snd_soc_component_read(lVar18,0x4018001f);
  sVar9 = snd_soc_component_read(lVar18,0x40180020);
  sVar10 = snd_soc_component_read(lVar18,0x40180021);
  sVar11 = snd_soc_component_read(lVar18,0x40180056);
  sVar12 = snd_soc_component_read(lVar18,0x40180123);
  uVar13 = snd_soc_component_read(lVar18,0x40180015);
  if ((uVar13 >> 7 & 1) != 0) {
    regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x40180015,0x80,0,0,0,0);
  }
  if (*(char *)(param_1 + 0xc3) != '\0') {
    regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x40180014,0x80,0,0,0,0);
  }
  regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x40180014,1,0,0,0,0);
  regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x401800e2,0xc0,0,0,0,0);
  usleep_range_state(1000,0x3f2,2);
  puVar20 = &DAT_0015383c;
  puVar19 = &DAT_0015841c;
  wcd9378_mbhc_zdet_ramp(lVar18,&DAT_0015383c,(long)&local_70 + 4,0,&DAT_0015841c);
  if (local_70._4_4_ - 0x61a81 < 0xfffa627f) {
    bVar7 = 2099999 < local_70._4_4_ - 0x61a81;
    lVar1 = 0x18;
    if (bVar7) {
      lVar1 = 0x24;
    }
    puVar2 = &DAT_00153848;
    if (bVar7) {
      puVar2 = &DAT_00153854;
    }
    puVar3 = &DAT_00158424;
    if (bVar7) {
      puVar3 = &DAT_0015842c;
    }
    bVar7 = 0x7c < local_70._4_4_ >> 8;
    puVar20 = &DAT_00153830;
    if (bVar7) {
      puVar20 = puVar2;
    }
    puVar19 = &_L__const_wcd9378_wcd_mbhc_calc_impedance_d1_a;
    if (bVar7) {
      puVar19 = puVar3;
    }
    lVar22 = 0;
    if (bVar7) {
      lVar22 = lVar1;
    }
    wcd9378_mbhc_zdet_ramp(lVar18,puVar20,(long)&local_70 + 4,0,puVar19);
    if ((int)local_70._4_4_ < 0x5f5e101) goto LAB_00108688;
    puVar19 = &DAT_0015841c;
    puVar20 = &DAT_0015383c;
    uVar14 = 0xffffffe;
    lVar22 = 0xc;
LAB_00108708:
    *param_2 = uVar14;
  }
  else {
    lVar22 = 0xc;
LAB_00108688:
    uVar16 = 0x401804c7;
    if (399999 < (int)local_70._4_4_) {
      uVar16 = 0x401804c8;
    }
    *param_2 = (int)local_70._4_4_ / 1000;
    uVar14 = snd_soc_component_read(lVar18,uVar16);
    if ((uVar14 >> 7 & 1) != 0) {
      uVar14 = uVar14 & 0x7f;
      iVar17 = -0x19;
LAB_001086f0:
      iVar17 = uVar14 * iVar17 + 10000;
      uVar14 = 0;
      if (iVar17 != 0) {
        uVar14 = (int)(*param_2 * 10000) / iVar17;
      }
      goto LAB_00108708;
    }
    if (-0x1900000 < (int)(uVar14 * 0x10000)) {
      uVar14 = (uint)(short)uVar14;
      iVar17 = 0x19;
      goto LAB_001086f0;
    }
  }
  wcd9378_mbhc_zdet_ramp(lVar18,puVar20,0,&local_70,puVar19);
  if ((uint)local_70 - 0x61a81 < 0xfffa627f) {
    if ((uint)local_70 < 0x2625a1) {
LAB_00108764:
      if (*param_2 == 0xffffffe) {
        if ((uint)local_70 >> 8 < 0x7d) {
          puVar19 = &_L__const_wcd9378_wcd_mbhc_calc_impedance_d1_a;
          puVar20 = &DAT_00153830;
        }
        else if ((uint)local_70 - 0x61a81 < 2100000) {
          puVar19 = &DAT_00158424;
          puVar20 = &DAT_00153848;
        }
        else if (2500000 < local_70._4_4_) {
          puVar19 = &DAT_0015842c;
          puVar20 = &DAT_00153854;
        }
        wcd9378_mbhc_zdet_ramp(lVar18,puVar20,0,&local_70,puVar19);
      }
    }
    else {
      if (lVar22 - 0x2dU < 0xffffffffffffffd1) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(1,0x108ba0);
        (*pcVar6)();
      }
      if (*(short *)(puVar20 + 2) != 6) goto LAB_00108764;
    }
    uVar14 = (uint)local_70;
    if ((int)(uint)local_70 < 0x5f5e101) goto LAB_00108814;
    uVar14 = 0xffffffe;
LAB_0010888c:
    *param_3 = uVar14;
  }
  else {
    uVar14 = (uint)local_70;
LAB_00108814:
    uVar16 = 0x401804c9;
    if (399999 < (int)uVar14) {
      uVar16 = 0x401804ca;
    }
    *param_3 = (int)uVar14 / 1000;
    uVar14 = snd_soc_component_read(lVar18,uVar16);
    if ((uVar14 >> 7 & 1) != 0) {
      uVar14 = uVar14 & 0x7f;
      iVar17 = -0x19;
LAB_00108874:
      iVar17 = uVar14 * iVar17 + 10000;
      uVar14 = 0;
      if (iVar17 != 0) {
        uVar14 = (int)(*param_3 * 10000) / iVar17;
      }
      goto LAB_0010888c;
    }
    if (-0x1900000 < (int)(uVar14 * 0x10000)) {
      uVar14 = (uint)(short)uVar14;
      iVar17 = 0x19;
      goto LAB_00108874;
    }
  }
  uVar14 = *param_2;
  uVar4 = *param_3;
  if (uVar14 == 0xffffffe) {
    if (uVar4 == 0xffffffe) goto LAB_001088e0;
  }
  else if (((uVar4 != 0xffffffe) && ((1 < uVar14 || (uVar4 < 3)))) && ((uVar14 < 3 || (1 < uVar4))))
  {
    snd_soc_component_update_bits(lVar18,0x401800d8,1,1);
    snd_soc_component_update_bits(lVar18,0x401800d2,0x40,1);
    puVar20 = &DAT_00153830;
    if (0x1f < *param_2) {
      puVar20 = &DAT_0015383c;
    }
    wcd9378_mbhc_zdet_ramp(lVar18,puVar20,&local_74,0,puVar19);
    snd_soc_component_update_bits(lVar18,0x401800d2,0x40,0);
    snd_soc_component_update_bits(lVar18,0x401800d8,1,0);
    uVar16 = 0x401804c7;
    if (399999 < (int)local_74) {
      uVar16 = 0x401804c8;
    }
    local_74 = (int)local_74 / 1000;
    uVar14 = snd_soc_component_read(lVar18,uVar16);
    if ((uVar14 >> 7 & 1) == 0) {
      if (-0x1900000 < (int)(uVar14 * 0x10000)) {
        uVar14 = (uint)(short)uVar14;
        iVar17 = 0x19;
        goto LAB_00108adc;
      }
    }
    else {
      uVar14 = uVar14 & 0x7f;
      iVar17 = -0x19;
LAB_00108adc:
      iVar17 = uVar14 * iVar17 + 10000;
      iVar5 = local_74 * 10000;
      local_74 = 0;
      if (iVar17 != 0) {
        local_74 = iVar5 / iVar17;
      }
    }
    uVar14 = *param_2;
    uVar4 = 0;
    if (uVar14 + 9 != 0) {
      uVar4 = (uVar14 * 9) / (uVar14 + 9);
    }
    iVar17 = local_74 - uVar4;
    if (local_74 - uVar4 == 0 || (int)local_74 < (int)uVar4) {
      iVar17 = uVar4 - local_74;
    }
    iVar5 = uVar14 - local_74;
    if (uVar14 < local_74 || uVar14 - local_74 == 0) {
      iVar5 = local_74 - uVar14;
    }
    uVar16 = 1;
    if (iVar5 * (local_74 + uVar4) < iVar17 * (local_74 + uVar14)) {
      uVar16 = 2;
    }
    *(undefined4 *)(param_1 + 0x1c4) = uVar16;
    regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x401800e2,0xc0,0xc0,0,0,0);
    goto LAB_001088e0;
  }
  *(undefined4 *)(param_1 + 0x1c4) = 1;
LAB_001088e0:
  snd_soc_component_write(lVar18,0x4018001f,(int)sVar8);
  snd_soc_component_write(lVar18,0x40180020,(int)sVar9);
  snd_soc_component_write(lVar18,0x40180021,(int)sVar10);
  regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x40180014,1,1,0,0,0);
  if (*(char *)(param_1 + 0xc3) != '\0') {
    regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x40180014,0x80,0x80,0,0,0);
  }
  snd_soc_component_write(lVar18,0x40180123,(int)sVar12);
  snd_soc_component_write(lVar18,0x40180056,(int)sVar11);
  if ((uVar13 >> 7 & 1) != 0) {
    regmap_update_bits_base(*(undefined8 *)(lVar21 + 0x30),0x40180015,0x80,0x80,0,0,0);
  }
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_get_hwdep_fw_cal @ 00108ba4 size=116
// signature: undefined wcd9378_get_hwdep_fw_cal(void)
// callers: []
//------------------------------------------------------------

long wcd9378_get_hwdep_fw_cal(long param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xf8);
  if (lVar2 == 0) {
    _printk(&DAT_00154024,"wcd9378_get_hwdep_fw_cal");
  }
  else {
    lVar1 = wcdcal_get_fw_cal(*(undefined8 *)(param_1 + 0x470));
    if (lVar1 != 0) {
      return lVar1;
    }
    _dev_err(*(undefined8 *)(lVar2 + 0x18),"%s: cal not sent by %d\n","wcd9378_get_hwdep_fw_cal",
             param_2);
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_mbhc_register_notifier @ 00108c1c size=44
// signature: undefined wcd9378_mbhc_register_notifier(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_register_notifier(long param_1,undefined8 param_2,uint param_3)

{
  if ((param_3 & 1) == 0) {
    blocking_notifier_chain_unregister(param_1 + 0x428);
  }
  else {
    blocking_notifier_chain_register();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_request_irq @ 00108c4c size=52
// signature: undefined wcd9378_mbhc_request_irq(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_request_irq(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  wcd_request_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x188,param_2,param_4,param_3);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_irq_control @ 00108c84 size=52
// signature: undefined wcd9378_mbhc_irq_control(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_irq_control(long param_1,undefined8 param_2,uint param_3)

{
  if ((param_3 & 1) == 0) {
    wcd_disable_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x188);
  }
  else {
    wcd_enable_irq();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_free_irq @ 00108cbc size=44
// signature: undefined wcd9378_mbhc_free_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_mbhc_free_irq(long param_1)

{
  wcd_free_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x188);
  return 0;
}



//------------------------------------------------------------
// wcd9378_mbhc_clk_setup @ 00108cec size=52
// signature: undefined wcd9378_mbhc_clk_setup(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_clk_setup(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x80;
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
  }
  snd_soc_component_update_bits(param_1,0x40180120,0x80,uVar1);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_btn_to_num @ 00108d24 size=40
// signature: undefined wcd9378_mbhc_btn_to_num(void)
// callers: []
//------------------------------------------------------------

uint wcd9378_mbhc_btn_to_num(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x40180019);
  return uVar1 & 7;
}



//------------------------------------------------------------
// wcd9378_mbhc_lock_sleep @ 00108d50 size=72
// signature: undefined wcd9378_mbhc_lock_sleep(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_mbhc_lock_sleep(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98) + 0xca0);
  if (*(int *)(pcVar1 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108d84);
    (*pcVar1)();
  }
  (*pcVar1)();
  return 1;
}



//------------------------------------------------------------
// wcd9378_mbhc_micb_en_status @ 00108d9c size=44
// signature: undefined wcd9378_mbhc_micb_en_status(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_mbhc_micb_en_status(long param_1,int param_2)

{
  if ((param_2 == 2) &&
     (*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98) + 0x160) != 0)) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// wcd9378_mbhc_mbhc_bias_control @ 00108dcc size=44
// signature: undefined wcd9378_mbhc_mbhc_bias_control(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_mbhc_bias_control(undefined8 param_1,uint param_2)

{
  snd_soc_component_update_bits(param_1,0x40180015,1,param_2 & 1);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_hph_pa_on_status @ 00108dfc size=44
// signature: undefined wcd9378_mbhc_hph_pa_on_status(void)
// callers: []
//------------------------------------------------------------

bool wcd9378_mbhc_hph_pa_on_status(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = snd_soc_component_read(param_1,0x40c80480);
  return iVar1 == 0;
}



//------------------------------------------------------------
// wcd9378_mbhc_program_btn_thr @ 00108e2c size=536
// signature: undefined wcd9378_mbhc_program_btn_thr(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_program_btn_thr(long param_1,undefined8 param_2,short *param_3,int param_4)

{
  if (param_4 < 9) {
    if (((((0 < param_4) &&
          (snd_soc_component_update_bits
                     (param_1,0x4018001a,0xfc,
                      ((uint)((ulong)((long)((int)*param_3 << 1) * 0x51eb851f) >> 0x23) -
                      (((int)*param_3 << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 1)) &&
         (snd_soc_component_update_bits
                    (param_1,0x4018001b,0xfc,
                     ((uint)((ulong)((long)((int)param_3[1] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[1] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 2)) &&
        ((snd_soc_component_update_bits
                    (param_1,0x4018001c,0xfc,
                     ((uint)((ulong)((long)((int)param_3[2] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[2] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 3 &&
         (snd_soc_component_update_bits
                    (param_1,0x4018001d,0xfc,
                     ((uint)((ulong)((long)((int)param_3[3] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[3] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 4)))) &&
       ((snd_soc_component_update_bits
                   (param_1,0x4018001e,0xfc,
                    ((uint)((ulong)((long)((int)param_3[4] << 1) * 0x51eb851f) >> 0x23) -
                    (((int)param_3[4] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 5 &&
        ((snd_soc_component_update_bits
                    (param_1,0x4018001f,0xfc,
                     ((uint)((ulong)((long)((int)param_3[5] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[5] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 6 &&
         (snd_soc_component_update_bits
                    (param_1,0x40180020,0xfc,
                     ((uint)((ulong)((long)((int)param_3[6] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[6] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 7)))))) {
      snd_soc_component_update_bits
                (param_1,0x40180021,0xfc,
                 ((uint)((ulong)((long)((int)param_3[7] << 1) * 0x51eb851f) >> 0x23) -
                 (((int)param_3[7] << 1) >> 0x1f)) * 4 & 0xfc);
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid number of buttons: %d\n",
             "wcd9378_mbhc_program_btn_thr",param_4);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_request_micbias @ 00109048 size=32
// signature: undefined wcd9378_mbhc_request_micbias(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_request_micbias(void)

{
  wcd9378_micbias_control();
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_micb_ramp_control @ 0010906c size=128
// signature: undefined wcd9378_mbhc_micb_ramp_control(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_micb_ramp_control(undefined8 param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((param_2 & 1) == 0) {
    snd_soc_component_update_bits(param_1,0x40180024,0x80,0);
    uVar1 = 0x1c;
    uVar2 = 0;
  }
  else {
    snd_soc_component_update_bits(param_1,0x40180024,0x1c,0xc);
    uVar1 = 0x80;
    uVar2 = 0x80;
  }
  snd_soc_component_update_bits(param_1,0x40180024,uVar1,uVar2);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_micb_ctrl_threshold_mic @ 001090f0 size=88
// signature: undefined wcd9378_mbhc_micb_ctrl_threshold_mic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_mbhc_micb_ctrl_threshold_mic(long param_1,int param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (param_2 == 2) {
    uVar2 = *(uint *)(*(long *)(*(long *)(param_1 + 0x18) + 0x90) + 0x24);
    if (uVar2 < 0xa8c) {
      uVar1 = 0xa8c;
      if ((param_3 & 1) == 0) {
        uVar1 = uVar2;
      }
      uVar3 = wcd9378_mbhc_micb_adjust_voltage(param_1,uVar1,2);
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// wcd9378_mbhc_gnd_det_ctrl @ 0010914c size=128
// signature: undefined wcd9378_mbhc_gnd_det_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_gnd_det_ctrl(undefined8 param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((param_2 & 1) == 0) {
    snd_soc_component_update_bits(param_1,0x40180014,0x40,0);
    uVar1 = 2;
    uVar2 = 0;
  }
  else {
    snd_soc_component_update_bits(param_1,0x40180014,2,2);
    uVar1 = 0x40;
    uVar2 = 0x40;
  }
  snd_soc_component_update_bits(param_1,0x40180014,uVar1,uVar2);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_hph_pull_down_ctrl @ 001091d0 size=96
// signature: undefined wcd9378_mbhc_hph_pull_down_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_hph_pull_down_ctrl(undefined8 param_1,ulong param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  bVar1 = (param_2 & 1) == 0;
  uVar2 = 0x40;
  if (bVar1) {
    uVar2 = 0;
  }
  uVar3 = 0x10;
  if (bVar1) {
    uVar3 = 0;
  }
  snd_soc_component_update_bits(param_1,0x401800d2,0x40,uVar2);
  snd_soc_component_update_bits(param_1,0x401800d2,0x10,uVar3);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_moisture_config @ 00109234 size=92
// signature: undefined wcd9378_mbhc_moisture_config(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_moisture_config(long param_1)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xe0) == 0) || (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (*(char *)(param_1 + 0xc3) != '\0') {
      iVar1 = *(int *)(param_1 + 0xe0) << 2;
    }
  }
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x40180121,0xc,iVar1);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_hph_l_pull_up_control @ 00109294 size=52
// signature: undefined wcd9378_mbhc_hph_l_pull_up_control(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_hph_l_pull_up_control(undefined8 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 8;
  if (param_2 < 0x19) {
    uVar1 = param_2;
  }
  snd_soc_component_update_bits(param_1,0x401801b1,0x1f,uVar1);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_get_moisture_status @ 001092cc size=188
// signature: undefined wcd9378_mbhc_get_moisture_status(void)
// callers: []
//------------------------------------------------------------

bool wcd9378_mbhc_get_moisture_status(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0xf8);
  if (((*(int *)(param_1 + 0xe0) == 0) || (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0)) ||
     (*(char *)(param_1 + 0xc3) == '\0')) {
    snd_soc_component_update_bits(uVar2,0x40180121,0xc,0);
  }
  else {
    uVar1 = snd_soc_component_read(uVar2,0x40180121);
    if ((uVar1 & 0xc) == 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),0x40180121,0xc,*(int *)(param_1 + 0xe0) << 2);
      uVar1 = snd_soc_component_read(uVar2,0x40180125);
      return (uVar1 & 0x20) == 0;
    }
  }
  return false;
}



//------------------------------------------------------------
// wcd9378_mbhc_moisture_polling_ctrl @ 0010938c size=56
// signature: undefined wcd9378_mbhc_moisture_polling_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_moisture_polling_ctrl(long param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
  }
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x401801b0,4,uVar1);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_moisture_detect_en @ 001093c8 size=68
// signature: undefined wcd9378_mbhc_moisture_detect_en(void)
// callers: []
//------------------------------------------------------------

void wcd9378_mbhc_moisture_detect_en(long param_1,ulong param_2)

{
  int iVar1;
  
  if ((param_2 & 1) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe0) << 2;
  }
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x40180121,0xc,iVar1);
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_zdet_ramp @ 0010940c size=476
// signature: undefined wcd9378_mbhc_zdet_ramp(void)
// callers: [wcd9378_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

void wcd9378_mbhc_zdet_ramp
               (long param_1,ushort *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined8 param_5)

{
  long lVar1;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  snd_soc_component_update_bits(param_1,0x40180123,0x70,(ulong)*param_2 << 4);
  snd_soc_component_update_bits(param_1,0x4018001f,0xfc,param_2[3]);
  snd_soc_component_update_bits(param_1,0x40180020,0xfc,param_2[4]);
  snd_soc_component_update_bits(param_1,0x40180021,0xfc,param_2[5]);
  snd_soc_component_update_bits(param_1,0x40180123,0xf,param_2[1]);
  snd_soc_component_update_bits(param_1,0x40180124,0xf,param_2[2]);
  if (param_3 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x30),0x40180016,0x80,0x80,0,0,0);
    wcd9378_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_5c);
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x30),0x40180016,0x80,0,0,0,0);
    *param_3 = local_5c;
  }
  if (param_4 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x30),0x40180016,0x40,0x40,0,0,0);
    wcd9378_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_5c);
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x30),0x40180016,0x40,0,0,0,0);
    *param_4 = local_5c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_mbhc_get_result_params @ 001095e8 size=496
// signature: undefined wcd9378_mbhc_get_result_params(void)
// callers: [wcd9378_mbhc_zdet_ramp]
//------------------------------------------------------------

void wcd9378_mbhc_get_result_params(long param_1,long param_2,ulong param_3,uint *param_4)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  uint uVar6;
  int iVar7;
  undefined8 local_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_60 = 0;
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x30),0x40180016,0x20,0x20,0,0,0);
  iVar7 = 899;
  do {
    regmap_read(*(undefined8 *)(param_1 + 0x30),0x40180018,(long)&local_60 + 4);
    if ((local_60._4_4_ >> 7 & 1) != 0) break;
    bVar5 = iVar7 != 0;
    iVar7 = iVar7 + -1;
  } while (bVar5);
  local_60._4_4_ = local_60._4_4_ << 8;
  regmap_read(*(undefined8 *)(param_1 + 0x30),0x40180017,&local_60);
  local_60._4_4_ = local_60._4_4_ | (uint)local_60;
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x30),0x40180016,0x20,0,0,0,0);
  uVar3 = local_60._4_4_;
  uVar6 = local_60._4_4_ & 0x3fff;
  uVar1 = local_60._4_4_ & 0xffff;
  if (((local_60._4_4_ >> 0xf & 1) == 0) && (uVar6 != 0)) {
    usleep_range_state(5000,0x13ba,2);
  }
  if ((uVar1 < 0x4000) || (uVar6 == 0)) {
    *param_4 = 0;
    if (uVar6 == 0) goto LAB_0010979c;
  }
  else {
    uVar1 = (-1 << (ulong)(0xe - ((uint)param_3 & 0xffff) & 0x1f)) +
            uVar6 * (int)*(short *)(param_2 + (ulong)(uVar3 >> 0xe & 3) * 2);
    if ((int)uVar1 < 1) {
      if (7 < ((uint)param_3 & 0xffff)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1097d8);
        (*pcVar4)();
      }
      if (*(int *)(&DAT_00158434 + (param_3 & 0xffff) * 4) <= (int)uVar6) goto LAB_0010975c;
      uVar6 = 0xffffffe;
    }
    else {
      uVar6 = 0;
      if (uVar1 != 0) {
        uVar6 = 0x53fc0000 / uVar1;
      }
    }
    *param_4 = uVar6;
  }
LAB_0010975c:
  iVar7 = 899;
  do {
    regmap_read(*(undefined8 *)(param_1 + 0x30),0x40180017,(long)&local_60 + 4);
    regmap_read(*(undefined8 *)(param_1 + 0x30),0x40180018,&local_60);
    bVar5 = iVar7 == 0;
    iVar7 = iVar7 + -1;
    local_60._4_4_ = (uint)local_60 | local_60._4_4_ << 8;
    if (bVar5) break;
  } while ((local_60._4_4_ & 0x3fff) != 0);
LAB_0010979c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd9378_hph_impedance_get @ 001097dc size=192
// signature: undefined wcd9378_hph_impedance_get(void)
// callers: []
//------------------------------------------------------------

void wcd9378_hph_impedance_get(long param_1,long param_2)

{
  uint *puVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  uint local_40 [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar5 = *(long *)(param_1 + 0x80);
  local_40[0] = 0;
  local_40[1] = 0;
  lVar3 = wcd9378_soc_get_mbhc(lVar5);
  if (lVar3 == 0) {
    _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: mbhc not initialized!\n","wcd9378_hph_impedance_get"
            );
    uVar4 = 0xffffffea;
  }
  else {
    iVar2 = *(int *)(*(long *)(param_1 + 0x78) + 0x18);
    wcd_mbhc_get_impedance(lVar3,local_40 + 1,local_40);
    uVar4 = 0;
    puVar1 = local_40 + 1;
    if (iVar2 != 0) {
      puVar1 = local_40;
    }
    *(ulong *)(param_2 + 0x48) = (ulong)*puVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd9378_get_hph_type @ 001098a0 size=96
// signature: undefined wcd9378_get_hph_type(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9378_get_hph_type(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x80);
  lVar1 = wcd9378_soc_get_mbhc(lVar3);
  if (lVar1 == 0) {
    _dev_err(*(undefined8 *)(lVar3 + 0x18),"%s: mbhc not initialized!\n","wcd9378_get_hph_type");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar1 + 0x1c4);
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00153864 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&wcd9378_codec_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00153894 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&wcd9378_codec_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 0015b000 size=1
// signature: undefined _printk(void)
// callers: [wcd9378_tx_sequencer_enable, wcd9378_mbhc_get_impedance, wcd9378_micb_usage_value_convert, wcd9378_wd_handle_irq, wcd9378_tx_path_get, wcd9378_mbhc_hs_detect, wcd9378_codec_get_dev_num, wcd9378_get_micb_vout_ctl_val, wcd9378_mbhc_init, wcd9378_wakeup, wcd9378_soc_get_mbhc, wcd9378_mbhc_post_ssr_init, wcd9378_mbhc_hs_detect_exit, wcd9378_tx_get_slave_ch_type_idx, wcd9378_mbhc_deinit, wcd9378_mbhc_ssr_down, wcd9378_swr_dmic_register_notifier, wcd9378_soc_codec_probe, wcd9378_get_hwdep_fw_cal, wcd9378_version_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0015b008 size=1
// signature: undefined mutex_lock(void)
// callers: [wcd9378_tx_sequencer_enable, wcd9378_sys_usage_auto_udpate, wcd9378_mbhc_micb_adjust_voltage, wcd9378_micbias_control, wcd9378_hph_sequencer_enable, wcd9378_codec_aux_dac_event, wcd9378_wakeup, wcd9378_codec_ear_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0015b010 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wcd9378_mbhc_program_btn_thr, wcd9378_sys_usage_auto_udpate, wcd9378_ear_pa_gain_put, wcd9378_mbhc_gnd_det_ctrl, wcd9378_hph_dsm_put, wcd9378_mbhc_post_ssr_init, wcd9378_codec_hphr_dac_event, wcd9378_mbhc_moisture_detect_en, wcd9378_mbhc_mbhc_bias_control, wcd9378_micbias_control, wcd9378_mbhc_micb_ramp_control, wcd9378_mbhc_moisture_config, wcd9378_codec_hphl_dac_event, wcd9378_sa_sequencer_enable, wcd9378_wcd_mbhc_calc_impedance, wcd9378_tx_sequencer_enable, wcd9378_micb_usage_value_convert, wcd9378_init_reg, wcd9378_mbhc_get_moisture_status, wcd9378_mbhc_hph_l_pull_up_control, wcd9378_codec_enable_dmic, wcd9378_aux_pa_gain_put, wcd9378_mbhc_clk_setup, wcd9378_hph_sequencer_enable, wcd9378_mbhc_zdet_ramp, wcd9378_mbhc_hph_pull_down_ctrl, wcd9378_aux_dsm_put, wcd9378_mbhc_micb_adjust_voltage, wcd9378_event_notify, wcd9378_loopback_mode_put, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event, wcd9378_soc_codec_probe, wcd9378_mbhc_moisture_polling_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0015b018 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcd9378_tx_sequencer_enable, wcd9378_sys_usage_auto_udpate, wcd9378_mbhc_micb_adjust_voltage, wcd9378_micbias_control, wcd9378_hph_sequencer_enable, wcd9378_codec_aux_dac_event, wcd9378_wakeup, wcd9378_codec_ear_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0015b020 size=1
// signature: undefined _dev_err(void)
// callers: [wcd9378_mbhc_program_btn_thr, wcd9378_get_hph_type, wcd9378_ear_pa_gain_put, wcd9378_mbhc_hs_detect, wcd9378_codec_enable_vdd_buck, wcd9378_parse_port_mapping, wcd9378_mbhc_post_ssr_init, wcd9378_reset, wcd9378_soc_codec_remove, wcd9378_probe, wcd9378_micbias_control, wcd9378_mbhc_ssr_down, wcd9378_tx_sequencer_enable, wcd9378_codec_enable_dmic, wcd9378_aux_pa_gain_put, wcd9378_mbhc_init, wcd9378_bind, wcd9378_set_port_params, wcd9378_suspend, wcd9378_populate_dt_data, wcd9378_mbhc_hs_detect_exit, wcd9378_mbhc_micb_adjust_voltage, wcd9378_resume, wcd9378_event_notify, wcd9378_hph_impedance_get, wcd9378_soc_codec_probe, wcd9378_get_hwdep_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0015b028 size=1
// signature: undefined ___ratelimit(void)
// callers: [wcd9378_wd_handle_irq, wcd9378_codec_enable_dmic, wcd9378_swr_dmic_register_notifier, wcd9378_soc_get_mbhc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 0015b030 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [wcd9378_event_notify, wcd9378_micbias_control, wcd9378_codec_enable_hphl_pa, wcd9378_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 0015b038 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [wcd9378_swr_dmic_register_notifier, wcd9378_mbhc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 0015b040 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [wcd9378_swr_dmic_register_notifier, wcd9378_mbhc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 0015b048 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [wcd9378_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 0015b050 size=1
// signature: undefined snd_info_register(void)
// callers: [wcd9378_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 0015b058 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [wcd9378_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 0015b060 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [wcd9378_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0015b068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd9378_probe, wcd9378_mbhc_init, wcd9378_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0015b070 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wcd9378_probe, wcd9378_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 0015b078 size=1
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: [wcd9378_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_get_power_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0015b080 size=1
// signature: undefined of_find_property(void)
// callers: [wcd9378_probe, wcd9378_parse_port_mapping, wcd9378_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0015b088 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wcd9378_probe, wcd9378_parse_port_mapping, wcd9378_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0015b090 size=1
// signature: undefined _dev_info(void)
// callers: [wcd9378_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0015b098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd9378_tx_mode_put, wcd9378_codec_enable_hphl_pa, wcd9378_parse_port_mapping, wcd9378_swr_slvdev_datapath_control, wcd9378_codec_hphr_dac_event, wcd9378_tx_mode_get, wcd9378_rx_connect_port, wcd9378_probe, wcd9378_version_read, wcd9378_codec_hphl_dac_event, wcd9378_wcd_mbhc_calc_impedance, wcd9378_tx_sequencer_enable, wcd9378_tx_path_get, wcd9378_tx_connect_port, wcd9378_tx_master_ch_get, wcd9378_hph_sequencer_enable, wcd9378_tx_master_ch_put, wcd9378_mbhc_zdet_ramp, wcd9378_populate_dt_data, wcd9378_event_notify, wcd9378_hph_impedance_get, wcd9378_mbhc_get_result_params, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event, wcd9378_handle_post_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0015b0a0 size=1
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
// platform_driver_unregister @ 0015b0a8 size=1
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
// scnprintf @ 0015b0b0 size=1
// signature: undefined scnprintf(void)
// callers: [wcd9378_version_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0015b0b8 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [wcd9378_version_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 0015b0c0 size=1
// signature: undefined msm_cdc_init_supplies(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_init_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 0015b0c8 size=1
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_static_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0015b0d0 size=1
// signature: undefined __kmalloc(void)
// callers: [wcd9378_probe, wcd9378_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0015b0d8 size=1
// signature: undefined kfree(void)
// callers: [wcd9378_probe, wcd9378_tx_path_get, wcd9378_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0015b0e0 size=1
// signature: undefined __mutex_init(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_match_add_release @ 0015b0e8 size=1
// signature: undefined component_match_add_release(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_match_add_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_add_with_match @ 0015b0f0 size=1
// signature: undefined component_master_add_with_match(void)
// callers: [wcd9378_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_add_with_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_del @ 0015b0f8 size=1
// signature: undefined component_master_del(void)
// callers: [wcd9378_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 0015b100 size=1
// signature: undefined __sw_hweight8(void)
// callers: [wcd9378_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0015b108 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [wcd9378_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0015b110 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wcd9378_reset, wcd9378_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0015b118 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd9378_sa_sequencer_enable, wcd9378_wcd_mbhc_calc_impedance, wcd9378_tx_sequencer_enable, wcd9378_init_reg, wcd9378_codec_enable_micbias_pullup, wcd9378_codec_enable_dmic, wcd9378_codec_enable_vdd_buck, wcd9378_codec_enable_micbias, wcd9378_hph_sequencer_enable, wcd9378_bind, wcd9378_reset, wcd9378_event_notify, wcd9378_mbhc_get_result_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0015b120 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wcd9378_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_vote @ 0015b128 size=1
// signature: undefined swr_device_wakeup_vote(void)
// callers: [wcd9378_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_unvote @ 0015b130 size=1
// signature: undefined swr_device_wakeup_unvote(void)
// callers: [wcd9378_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_unvote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_bind_all @ 0015b138 size=1
// signature: undefined component_bind_all(void)
// callers: [wcd9378_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_bind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_matching_swr_slave_device @ 0015b140 size=1
// signature: undefined get_matching_swr_slave_device(void)
// callers: [wcd9378_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_matching_swr_slave_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_unbind_all @ 0015b148 size=1
// signature: undefined component_unbind_all(void)
// callers: [wcd9378_bind, wcd9378_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_unbind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_init_port_params @ 0015b150 size=1
// signature: undefined swr_init_port_params(void)
// callers: [wcd9378_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_init_port_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 0015b158 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [wcd9378_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 0015b160 size=1
// signature: undefined regmap_write(void)
// callers: [wcd9378_sa_sequencer_enable, wcd9378_hph_sequencer_enable, wcd9378_bind, wcd9378_handle_post_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_init @ 0015b168 size=1
// signature: undefined wcd_irq_init(void)
// callers: [wcd9378_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_request_irq @ 0015b170 size=1
// signature: undefined wcd_request_irq(void)
// callers: [wcd9378_bind, wcd9378_mbhc_request_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_request_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_disable_irq @ 0015b178 size=1
// signature: undefined wcd_disable_irq(void)
// callers: [wcd9378_codec_enable_ear_pa, wcd9378_codec_enable_aux_pa, wcd9378_codec_enable_hphl_pa, wcd9378_mbhc_init, wcd9378_bind, wcd9378_mbhc_irq_control, wcd9378_codec_enable_hphr_pa, wcd9378_mbhc_post_ssr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 0015b180 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [wcd9378_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_exit @ 0015b188 size=1
// signature: undefined wcd_irq_exit(void)
// callers: [wcd9378_bind, wcd9378_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_free_irq @ 0015b190 size=1
// signature: undefined wcd_free_irq(void)
// callers: [wcd9378_mbhc_free_irq, wcd9378_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 0015b198 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [wcd9378_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 0015b1a0 size=1
// signature: undefined regmap_read(void)
// callers: [wcd9378_mbhc_get_result_params, wcd9378_handle_post_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 0015b1a8 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [wcd9378_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 0015b1b0 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wcd9378_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0015b1b8 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wcd9378_loopback_mode_get, wcd9378_codec_enable_ear_pa, wcd9378_wcd_mbhc_calc_impedance, wcd9378_ear_pa_gain_get, wcd9378_tx_sequencer_enable, wcd9378_init_reg, wcd9378_mbhc_get_moisture_status, wcd9378_codec_enable_hphl_pa, wcd9378_mbhc_btn_to_num, wcd9378_codec_enable_hphr_pa, wcd9378_codec_enable_aux_pa, wcd9378_mbhc_hph_pa_on_status, wcd9378_event_notify, wcd9378_aux_pa_gain_get, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event, wcd9378_soc_codec_probe, wcd9378_aux_dsm_get, wcd9378_hph_dsm_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0015b1c0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [wcd9378_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0015b1c8 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [wcd9378_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_init @ 0015b1d0 size=1
// signature: undefined wcd_cls_h_init(void)
// callers: [wcd9378_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 0015b1d8 size=1
// signature: undefined kstrndup(void)
// callers: [wcd9378_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0015b1e0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [wcd9378_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 0015b1e8 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [wcd9378_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0015b1f0 size=1
// signature: undefined kstrtouint(void)
// callers: [wcd9378_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0015b1f8 size=1
// signature: undefined strnstr(void)
// callers: [wcd9378_tx_get_slave_ch_type_idx, wcd9378_codec_enable_micbias_pullup, wcd9378_codec_enable_micbias]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 0015b200 size=1
// signature: undefined swr_read(void)
// callers: [wcd9378_tx_sequencer_enable, wcd9378_codec_enable_hphl_pa, wcd9378_swr_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 0015b208 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [wcd9378_codec_hphl_dac_event, wcd9378_codec_hphr_dac_event, wcd9378_rx_connect_port, wcd9378_tx_sequencer_enable, wcd9378_tx_connect_port, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 0015b218 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [wcd9378_codec_enable_dmic, wcd9378_tx_swr_ctrl, wcd9378_swr_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 0015b220 size=1
// signature: undefined swr_connect_port(void)
// callers: [wcd9378_codec_hphl_dac_event, wcd9378_codec_hphr_dac_event, wcd9378_rx_connect_port, wcd9378_tx_connect_port, wcd9378_codec_aux_dac_event, wcd9378_codec_ear_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_write @ 0015b228 size=1
// signature: undefined swr_write(void)
// callers: [wcd9378_hph_sequencer_enable, wcd9378_swr_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_enable_irq @ 0015b230 size=1
// signature: undefined wcd_enable_irq(void)
// callers: [wcd9378_codec_enable_ear_pa, wcd9378_codec_enable_aux_pa, wcd9378_codec_enable_hphl_pa, wcd9378_mbhc_irq_control, wcd9378_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_is_ondemand_supply @ 0015b238 size=1
// signature: undefined msm_cdc_is_ondemand_supply(void)
// callers: [wcd9378_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_is_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_ondemand_supply @ 0015b240 size=1
// signature: undefined msm_cdc_enable_ondemand_supply(void)
// callers: [wcd9378_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 0015b248 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0015b250 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 0015b258 size=1
// signature: undefined regcache_sync(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0015b260 size=1
// signature: undefined __const_udelay(void)
// callers: [wcd9378_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_disable_ondemand_supply @ 0015b268 size=1
// signature: undefined msm_cdc_disable_ondemand_supply(void)
// callers: [wcd9378_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_disable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_set_supplies_lpm_mode @ 0015b270 size=1
// signature: undefined msm_cdc_set_supplies_lpm_mode(void)
// callers: [wcd9378_resume, wcd9378_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_set_supplies_lpm_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_get_impedance @ 0015b2b8 size=1
// signature: undefined wcd_mbhc_get_impedance(void)
// callers: [wcd9378_mbhc_get_impedance, wcd9378_hph_impedance_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_get_impedance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_start @ 0015b2c0 size=1
// signature: undefined wcd_mbhc_start(void)
// callers: [wcd9378_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_stop @ 0015b2c8 size=1
// signature: undefined wcd_mbhc_stop(void)
// callers: [wcd9378_mbhc_hs_detect_exit, wcd9378_mbhc_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_deinit @ 0015b2d0 size=1
// signature: undefined wcd_mbhc_deinit(void)
// callers: [wcd9378_mbhc_deinit, wcd9378_mbhc_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_deinit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_init @ 0015b2d8 size=1
// signature: undefined wcd_mbhc_init(void)
// callers: [wcd9378_mbhc_init, wcd9378_mbhc_post_ssr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 0015b2e0 size=1
// signature: undefined __init_rwsem(void)
// callers: [wcd9378_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 0015b2e8 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [wcd9378_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 0015b2f0 size=1
// signature: undefined mutex_is_locked(void)
// callers: [wcd9378_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0015b2f8 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wcd9378_wcd_mbhc_calc_impedance, wcd9378_mbhc_get_result_params, wcd9378_mbhc_zdet_ramp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0015b300 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [wcd9378_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0015b308 size=1
// signature: undefined __warn_printk(void)
// callers: [wcd9378_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcdcal_get_fw_cal @ 0015b310 size=1
// signature: undefined wcdcal_get_fw_cal(void)
// callers: [wcd9378_get_hwdep_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcdcal_get_fw_cal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



