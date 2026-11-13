// Decompiled by Ghidra 12.2
// Program: wcd937x_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd937x_soc_get_mbhc @ 001015cc size=84
// signature: undefined wcd937x_soc_get_mbhc(void)
// callers: [wcd937x_hph_impedance_get, wcd937x_get_hph_type]
//------------------------------------------------------------

undefined8 wcd937x_soc_get_mbhc(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_00113654;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      return *(undefined8 *)(lVar2 + 0xc0);
    }
    puVar1 = &DAT_00112d0a;
  }
  _printk(puVar1,"wcd937x_soc_get_mbhc");
  return 0;
}



//------------------------------------------------------------
// wcd937x_get_micb_vout_ctl_val @ 00101624 size=84
// signature: undefined wcd937x_get_micb_vout_ctl_val(void)
// callers: []
//------------------------------------------------------------

uint wcd937x_get_micb_vout_ctl_val(int param_1)

{
  if (param_1 - 0xb23U < 0xfffff8c5) {
    _printk(&DAT_00113363,"wcd937x_get_micb_vout_ctl_val");
    return 0xffffffea;
  }
  return (param_1 - 1000U >> 1 & 0x7fff) / 0x19;
}



//------------------------------------------------------------
// wcd937x_mbhc_micb_adjust_voltage @ 0010167c size=312
// signature: undefined wcd937x_mbhc_micb_adjust_voltage(void)
// callers: [wcd937x_mbhc_micb_ctrl_threshold_mic]
//------------------------------------------------------------

undefined8 wcd937x_mbhc_micb_adjust_voltage(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (param_3 - 1U < 3) {
    uVar2 = *(undefined4 *)(&DAT_00110ae8 + (long)(int)(param_3 - 1U) * 4);
    lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x60;
    mutex_lock(lVar1);
    uVar4 = snd_soc_component_read(param_1,uVar2);
    if (param_2 - 0xb23U < 0xfffff8c5) {
      _printk(&DAT_00113363,"wcd937x_get_micb_vout_ctl_val");
      uVar5 = 0xffffffea;
    }
    else {
      uVar3 = (param_2 - 1000U >> 1 & 0x7fff) / 0x19;
      if ((uVar4 & 0x3f) != uVar3) {
        if ((uVar4 & 0xc0) == 0x40) {
          snd_soc_component_update_bits(param_1,uVar2,0xc0,0x80);
          snd_soc_component_update_bits(param_1,uVar2,0x3f,uVar3);
          snd_soc_component_update_bits(param_1,uVar2,0xc0,0x40);
          usleep_range_state(2000,0x834,2);
        }
        else {
          snd_soc_component_update_bits(param_1,uVar2,0x3f,uVar3);
        }
      }
      uVar5 = 0;
    }
    mutex_unlock(lVar1);
  }
  else {
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// wcd937x_micbias_control @ 001017b8 size=992
// signature: undefined wcd937x_micbias_control(void)
// callers: [wcd937x_mbhc_request_micbias, wcd937x_codec_enable_micbias, wcd937x_codec_enable_micbias_pullup]
//------------------------------------------------------------

undefined8 wcd937x_micbias_control(long param_1,uint param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  char *pcVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 local_6c;
  uint local_68;
  
  uVar4 = param_2 - 1;
  uVar9 = (ulong)uVar4;
  if (2 < uVar4) {
    pcVar2 = "%s: Invalid micbias index, micb_ind:%d\n";
LAB_00101b34:
    _dev_err(*(long *)(param_1 + 0x18),pcVar2,"wcd937x_micbias_control",uVar4);
    return 0xffffffea;
  }
  lVar7 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (param_2 == 1) {
    local_6c = 0x3022;
LAB_00101878:
    local_68 = 0;
    uVar12 = 0;
    uVar11 = 0;
    uVar10 = 0;
    uVar8 = 0;
    bVar1 = true;
  }
  else {
    if (param_2 == 3) {
      local_6c = 0x3025;
      goto LAB_00101878;
    }
    if (param_2 != 2) {
      pcVar2 = "%s: Invalid micbias number: %d\n";
      uVar4 = param_2;
      goto LAB_00101b34;
    }
    bVar1 = false;
    uVar10 = 8;
    uVar8 = 6;
    uVar11 = 4;
    local_6c = 0x3023;
    local_68 = 1;
    uVar12 = 2;
  }
  mutex_lock(lVar7 + 0x60);
  switch(param_3) {
  case 0:
    lVar3 = lVar7 + (ulong)uVar4 * 4;
    iVar5 = *(int *)(lVar3 + 0x44);
    *(int *)(lVar3 + 0x44) = iVar5 + 1;
    if ((iVar5 == 0) && (*(int *)(lVar7 + uVar9 * 4 + 0x38) == 0)) {
      snd_soc_component_update_bits(param_1,local_6c,0xc0,0x80);
    }
    break;
  case 1:
    piVar6 = (int *)(lVar7 + (ulong)uVar4 * 4 + 0x44);
    iVar5 = *piVar6;
    if (0 < iVar5) {
      *piVar6 = iVar5 + -1;
      iVar5 = iVar5 + -1;
    }
    if ((iVar5 == 0) && (*(int *)(lVar7 + uVar9 * 4 + 0x38) == 0)) {
      snd_soc_component_update_bits(param_1,local_6c,0xc0,0);
    }
    break;
  case 2:
    lVar3 = lVar7 + (ulong)uVar4 * 4;
    *(int *)(lVar3 + 0x38) = *(int *)(lVar3 + 0x38) + 1;
    mutex_lock(lVar7 + 0xc28);
    *(int *)(lVar7 + 0xc1c) = *(int *)(lVar7 + 0xc1c) + 1;
    mutex_unlock(lVar7 + 0xc28);
    if (*(int *)(lVar3 + 0x38) == 1) {
      snd_soc_component_update_bits(param_1,0x3409,0xf0,0xf0);
      snd_soc_component_update_bits(param_1,0x3408,0x10,0x10);
      snd_soc_component_update_bits(param_1,0x306c,1,1);
      snd_soc_component_update_bits(param_1,0x306f,1,1);
      snd_soc_component_update_bits(param_1,0x3072,1,1);
      snd_soc_component_update_bits(param_1,local_6c,0xc0,0x40);
      if (!bVar1) {
        blocking_notifier_call_chain(*(long *)(lVar7 + 0xc0) + 0x428,uVar11);
      }
    }
    if (((local_68 & param_4) != 1) || (lVar3 = *(long *)(lVar7 + 0xc0), lVar3 == 0)) break;
    goto LAB_00101aec;
  case 3:
    lVar3 = lVar7 + 0xc28;
    mutex_lock(lVar3);
    *(int *)(lVar7 + 0xc1c) = *(int *)(lVar7 + 0xc1c) + -1;
    mutex_unlock(lVar3);
    piVar6 = (int *)(lVar7 + (ulong)uVar4 * 4 + 0x38);
    iVar5 = *piVar6;
    if (0 < iVar5) {
      *piVar6 = iVar5 + -1;
      iVar5 = iVar5 + -1;
    }
    if (iVar5 == 0) {
      iVar5 = *(int *)(lVar7 + uVar9 * 4 + 0x44);
      if (iVar5 < 1) {
        if (iVar5 == 0) {
          if (bVar1) {
            uVar10 = 0;
            goto LAB_00101a70;
          }
          if (*(long *)(lVar7 + 0xc0) != 0) {
            blocking_notifier_call_chain(*(long *)(lVar7 + 0xc0) + 0x428,1);
          }
          snd_soc_component_update_bits(param_1,local_6c,0xc0,0);
          if (*(long *)(lVar7 + 0xc0) != 0) {
            blocking_notifier_call_chain(*(long *)(lVar7 + 0xc0) + 0x428,uVar12);
          }
        }
      }
      else {
        uVar10 = 0x80;
LAB_00101a70:
        snd_soc_component_update_bits(param_1,local_6c,0xc0,uVar10);
      }
    }
    mutex_lock(lVar3);
    if (*(int *)(lVar7 + 0xc1c) < 1) {
      snd_soc_component_update_bits(param_1,0x3408,0x10,0);
      *(undefined4 *)(lVar7 + 0xc1c) = 0;
    }
    mutex_unlock(lVar3);
    if (((local_68 & param_4) != 1) || (lVar3 = *(long *)(lVar7 + 0xc0), lVar3 == 0)) break;
    uVar10 = uVar8;
LAB_00101aec:
    blocking_notifier_call_chain(lVar3 + 0x428,uVar10);
  }
  mutex_unlock(lVar7 + 0x60);
  return 0;
}



//------------------------------------------------------------
// wcd937x_disable_bcs_before_slow_insert @ 00101b9c size=84
// signature: undefined wcd937x_disable_bcs_before_slow_insert(void)
// callers: [wcd937x_mbhc_bcs_enable]
//------------------------------------------------------------

void wcd937x_disable_bcs_before_slow_insert(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  pcVar1 = *(code **)(lVar2 + 0xbe0);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101be0);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(lVar2 + 0xbd8),5,(param_2 ^ 0xffffffff) & 1);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_codec_get_dev_num @ 00101bf4 size=80
// signature: undefined wcd937x_codec_get_dev_num(void)
// callers: []
//------------------------------------------------------------

ulong wcd937x_codec_get_dev_num(long param_1)

{
  long lVar1;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if ((lVar1 != 0) && (lVar1 = *(long *)(lVar1 + 0x28), lVar1 != 0)) {
      return (ulong)*(byte *)(lVar1 + 0x40);
    }
    _printk(&DAT_001129d4,"wcd937x_codec_get_dev_num");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd937x_get_codec_variant @ 00101c48 size=80
// signature: undefined wcd937x_get_codec_variant(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd937x_get_codec_variant(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 == 0) {
      _dev_err(*(long *)(param_1 + 0x18),"%s:wcd937x not probed\n","wcd937x_get_codec_variant");
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(lVar2 + 8);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd937x_info_create_codec_entry @ 00101c9c size=308
// signature: undefined wcd937x_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_info_create_codec_entry(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (*(long *)(lVar5 + 0xc00) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),"wcd937x");
      *(long *)(lVar5 + 0xc00) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0xc00));
        if ((-1 < iVar1) &&
           (lVar3 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"version",
                               *(undefined8 *)(lVar5 + 0xc00)), lVar3 != 0)) {
          *(long *)(lVar3 + 0x40) = lVar5;
          *(undefined8 *)(lVar3 + 0x10) = 0x20;
          *(undefined2 *)(lVar3 + 0x18) = 1;
          *(undefined1 **)(lVar3 + 0x20) = &wcd937x_info_ops;
          iVar1 = snd_info_register();
          if (-1 < iVar1) {
            *(long *)(lVar5 + 0xc08) = lVar3;
            lVar4 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"variant",
                               *(undefined8 *)(lVar5 + 0xc00));
            if (lVar4 != 0) {
              *(long *)(lVar4 + 0x40) = lVar5;
              *(undefined8 *)(lVar4 + 0x10) = 0x20;
              *(undefined2 *)(lVar4 + 0x18) = 1;
              *(undefined1 **)(lVar4 + 0x20) = wcd937x_variant_ops;
              iVar1 = snd_info_register();
              if (-1 < iVar1) {
                *(long *)(lVar5 + 0xc10) = lVar4;
                return 0;
              }
              snd_info_free_entry(lVar4);
            }
          }
          snd_info_free_entry(lVar3);
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0xc00));
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
// wcd937x_populate_dt_data @ 00101dd4 size=860
// signature: undefined wcd937x_populate_dt_data(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong * wcd937x_populate_dt_data(long param_1)

{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong local_88 [11];
  
  lVar5 = sp_el0;
  local_88[10] = *(long *)(lVar5 + 0x638);
  puVar3 = (ulong *)kmalloc_trace(__dev_info,0xdc0,0x40);
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
      _dev_err(param_1,"%s: Looking up %s property in node %s failed\n","wcd937x_populate_dt_data",
               "qcom,wcd-rst-gpio-node",*(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
      puVar3 = (ulong *)0x0;
    }
    else {
      msm_cdc_get_power_supplies(param_1,puVar3 + 6,puVar3 + 7);
      if ((puVar3[6] == 0) || ((int)puVar3[7] < 1)) {
        _dev_err(param_1,"%s: no power supplies defined for codec\n","wcd937x_populate_dt_data");
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
          _dev_info(param_1,"%s: Micbias1 DT property not found\n","wcd937x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias1-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd937x_read_of_property_u32","qcom,cdc-micbias1-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)(puVar3 + 4) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias2-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias2 DT property not found\n","wcd937x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias2-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd937x_read_of_property_u32","qcom,cdc-micbias2-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)((long)puVar3 + 0x24) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias3-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias3 DT property not found\n","wcd937x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias3-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd937x_read_of_property_u32","qcom,cdc-micbias3-mv",
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
// wcd937x_version_read @ 00102134 size=216
// signature: undefined wcd937x_version_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wcd937x_version_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_40;
  undefined5 local_38;
  undefined2 uStack_33;
  char cStack_31;
  char local_30 [5];
  undefined2 uStack_2b;
  undefined1 uStack_29;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_33 = 0;
  cStack_31 = '\0';
  local_28 = 0;
  uStack_20 = 0;
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_30[4] = '\0';
  uStack_2b = 0;
  uStack_29 = 0;
  local_40 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    _printk(&DAT_00112f1e,"wcd937x_version_read");
    uVar2 = 0xffffffffffffffea;
  }
  else {
    if (*(int *)(*(long *)(param_1 + 0x40) + 0xbf8) == 1) {
      uVar2 = 0xc;
      local_38 = _DAT_001121db;
      uStack_33 = s_7X_1_0_001121e0._0_2_;
      cStack_31 = s_7X_1_0_001121e0[2];
      local_30 = (char  [5])s_7X_1_0_001121e0._3_5_;
    }
    else {
      uVar2 = 0xe;
      local_38 = s_VER_UNDEFINED_00112f9a._0_5_;
      uStack_33 = s_VER_UNDEFINED_00112f9a._5_2_;
      cStack_31 = s_VER_UNDEFINED_00112f9a[7];
      local_30 = s_VER_UNDEFINED_00112f9a._8_5_;
      uStack_2b = s_VER_UNDEFINED_00112f9a._13_2_;
    }
    uVar2 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,uVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_variant_read @ 00102210 size=228
// signature: undefined wcd937x_variant_read(void)
// callers: []
//------------------------------------------------------------

void wcd937x_variant_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined8 local_40;
  char local_38 [9];
  undefined6 uStack_2f;
  undefined1 uStack_29;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_28 = 0;
  uStack_20 = 0;
  local_38[8] = '\0';
  uStack_2f = 0;
  uStack_29 = 0;
  local_40 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    _printk(&DAT_00112f1e,"wcd937x_variant_read");
    uVar4 = 0xffffffffffffffea;
    goto LAB_001022b0;
  }
  iVar1 = *(int *)(*(long *)(param_1 + 0x40) + 8);
  if (iVar1 == 5) {
    pcVar3 = "WCD9375\n";
LAB_00102268:
    uVar4 = 8;
    local_38[8] = '\0';
    local_38._0_7_ = SUB87(*(undefined8 *)pcVar3,0);
    local_38[7] = (char)((ulong)*(undefined8 *)pcVar3 >> 0x38);
  }
  else {
    if (iVar1 == 0) {
      pcVar3 = "WCD9370\n";
      goto LAB_00102268;
    }
    uVar4 = 0xe;
    local_38._0_7_ = s_VER_UNDEFINED_00112f9a._0_7_;
    local_38[7] = s_VER_UNDEFINED_00112f9a[7];
    local_38[8] = s_VER_UNDEFINED_00112f9a[8];
    uStack_2f = s_VER_UNDEFINED_00112f9a._9_6_;
  }
  uVar4 = simple_read_from_buffer(param_4,param_5,&local_40,local_38,uVar4);
LAB_001022b0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_probe @ 001022f8 size=336
// signature: undefined wcd937x_probe(void)
// callers: []
//------------------------------------------------------------

void wcd937x_probe(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 local_80;
  long local_78 [11];
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_78[10] = *(long *)(lVar2 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  local_80 = 0;
  local_78[0] = 0;
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[1] = 0;
  iVar3 = __of_parse_phandle_with_args(uVar5,"qcom,rx-slave",0,0,0,local_78);
  if ((iVar3 == 0) && (local_78[0] != 0)) {
    component_match_add_release(lVar1,&local_80,wcd937x_release_of,wcd937x_compare_of);
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[0] = 0;
    local_78[1] = 0;
    iVar3 = __of_parse_phandle_with_args(uVar5,"qcom,tx-slave",0,0,0,local_78);
    if ((iVar3 == 0) && (local_78[0] != 0)) {
      component_match_add_release(lVar1,&local_80,wcd937x_release_of,wcd937x_compare_of);
      uVar5 = component_master_add_with_match(lVar1,&wcd937x_comp_ops,local_80);
      goto LAB_001023f0;
    }
    pcVar4 = "%s: Tx-slave node not defined\n";
  }
  else {
    pcVar4 = "%s: Rx-slave node not defined\n";
  }
  _dev_err(lVar1,pcVar4,"wcd937x_add_slave_components");
  uVar5 = 0xffffffed;
LAB_001023f0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_remove @ 0010244c size=60
// signature: undefined wcd937x_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_remove(long param_1)

{
  component_master_del(param_1 + 0x10,&wcd937x_comp_ops);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// wcd937x_release_of @ 0010248c size=4
// signature: undefined wcd937x_release_of(void)
// callers: []
//------------------------------------------------------------

void wcd937x_release_of(void)

{
  return;
}



//------------------------------------------------------------
// wcd937x_compare_of @ 00102494 size=16
// signature: undefined wcd937x_compare_of(void)
// callers: []
//------------------------------------------------------------

bool wcd937x_compare_of(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x2e8) == param_2;
}



//------------------------------------------------------------
// wcd937x_bind @ 001024a8 size=2684
// signature: undefined wcd937x_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint wcd937x_bind(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  long *plVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char *pcVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  uint local_5c;
  long local_58;
  
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  plVar5 = (long *)kmalloc_trace(_component_master_add_with_match,0xdc0,0xc70);
  if (plVar5 == (long *)0x0) {
    uVar2 = 0xfffffff4;
    goto LAB_00102ee4;
  }
  *(long **)(param_1 + 0x98) = plVar5;
  plVar6 = (long *)wcd937x_populate_dt_data(param_1);
  if (plVar6 == (long *)0x0) {
    _dev_err(param_1,"%s: Fail to obtain platform data\n","wcd937x_bind");
    uVar2 = 0xffffffea;
  }
  else {
    *plVar5 = param_1;
    *(long **)(param_1 + 0x90) = plVar6;
    plVar5[3] = *plVar6;
    uVar2 = msm_cdc_init_supplies(param_1,plVar5 + 0x177,plVar6[6],(int)plVar6[7]);
    if (plVar5[0x177] == 0) {
      pcVar8 = "%s: Cannot init wcd supplies\n";
LAB_00102d00:
      _dev_err(param_1,pcVar8,"wcd937x_bind");
      goto LAB_00102ed0;
    }
    plVar10 = *(long **)(*(long *)(param_1 + 0x60) + 0x90);
    if (plVar10 == (long *)0x0) {
      pcVar8 = "%s: platform data from parent is NULL\n";
LAB_00102cdc:
      _dev_err(param_1,pcVar8,"wcd937x_bind");
      uVar2 = 0xffffffea;
    }
    else {
      lVar11 = *plVar10;
      plVar5[0x17b] = lVar11;
      if (lVar11 == 0) {
        pcVar8 = "%s: handle is NULL\n";
        goto LAB_00102cdc;
      }
      lVar11 = plVar10[1];
      plVar5[0x17c] = lVar11;
      if (lVar11 == 0) {
        pcVar8 = "%s: update_wcd_event api is null!\n";
        goto LAB_00102cdc;
      }
      lVar11 = plVar10[2];
      plVar5[0x17d] = lVar11;
      if (lVar11 == 0) {
        pcVar8 = "%s: register_notifier api is null!\n";
        goto LAB_00102cdc;
      }
      uVar2 = msm_cdc_enable_static_supplies(param_1,plVar5[0x177],plVar6[6],(int)plVar6[7]);
      if (uVar2 != 0) {
        pcVar8 = "%s: wcd static supply enable failed!\n";
        goto LAB_00102d00;
      }
      iVar3 = wcd937x_reset(param_1);
      if (iVar3 == -0x205) {
        _dev_err(param_1,"%s: wcd reset failed!\n","wcd937x_bind");
        uVar2 = 0xfffffdfb;
      }
      else {
        usleep_range_state(5000,0x1392,2);
        plVar5[0x17e] = (long)wcd937x_wakeup;
        uVar2 = component_bind_all(param_1,plVar5);
        if (uVar2 == 0) {
          uVar4 = wcd937x_parse_port_mapping(param_1,"qcom,rx_swr_ch_map",1);
          uVar2 = wcd937x_parse_port_mapping(param_1,"qcom,tx_swr_ch_map",0);
          uVar2 = uVar2 | uVar4;
          if (uVar2 == 0) {
            lVar12 = *(long *)(param_1 + 0x98);
            local_5c = 0;
            lVar11 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,swr-tx-port-params",
                                      &local_5c);
            uVar4 = local_5c;
            if (lVar11 == 0) {
              pcVar8 = "missing port mapping prop %s\n";
              pcVar9 = "qcom,swr-tx-port-params";
LAB_00102d88:
              _dev_err(param_1,pcVar8,pcVar9);
              uVar2 = 0xffffffea;
LAB_00102dcc:
              pcVar8 = "Failed to read port params\n";
              goto LAB_00102dd4;
            }
            if ((local_5c & 0xffffffe0) != 0x80) {
              pcVar8 = "%s: port params not provided for all usecases\n";
              pcVar9 = "wcd937x_parse_port_params";
              goto LAB_00102d88;
            }
            puVar7 = (undefined4 *)__kmalloc(local_5c,0xdc0);
            if (puVar7 == (undefined4 *)0x0) {
              uVar2 = 0xfffffff4;
              goto LAB_00102dcc;
            }
            uVar2 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2e8),"qcom,swr-tx-port-params",puVar7,
                               0x20,0);
            if ((int)uVar2 < 0) {
              _dev_err(param_1,"%s: Failed to read  port mapping from prop %s\n",
                       "wcd937x_parse_port_params","qcom,swr-tx-port-params");
              kfree(puVar7);
              goto LAB_00102dcc;
            }
            if (uVar4 < 4) {
LAB_00102f1c:
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(1,0x102f20);
              (*pcVar1)();
            }
            *(undefined4 *)(lVar12 + 0xb14) = *puVar7;
            if ((((((uVar4 & 0xfffffffc) == 4) ||
                  (*(undefined4 *)(lVar12 + 0xb18) = puVar7[1], uVar4 < 8)) ||
                 ((uVar4 & 0xfffffffc) == 8)) ||
                (((*(undefined4 *)(lVar12 + 0xb1c) = puVar7[2], uVar4 < 0xc ||
                  ((uVar4 & 0xfffffffc) == 0xc)) ||
                 ((*(undefined4 *)(lVar12 + 0xb20) = puVar7[3], uVar4 < 0x10 ||
                  (((uVar4 & 0xfffffffc) == 0x10 ||
                   (*(undefined4 *)(lVar12 + 0xb24) = puVar7[4], uVar4 < 0x14)))))))) ||
               (((uVar4 & 0xfffffffc) == 0x14 ||
                ((((*(undefined4 *)(lVar12 + 0xb28) = puVar7[5], uVar4 < 0x18 ||
                   ((uVar4 & 0xfffffffc) == 0x18)) ||
                  (*(undefined4 *)(lVar12 + 0xb2c) = puVar7[6], uVar4 < 0x1c)) ||
                 ((uVar4 & 0xfffffffc) == 0x1c)))))) goto LAB_00102f1c;
            *(undefined4 *)(lVar12 + 0xb30) = puVar7[7];
            *(long *)(lVar12 + 0xb98) = lVar12 + 0xb14;
            if ((((uVar4 < 0x20) || ((uVar4 & 0xfffffffc) == 0x20)) ||
                (((*(undefined4 *)(lVar12 + 0xb34) = puVar7[8], uVar4 < 0x24 ||
                  (((uVar4 & 0xfffffffc) == 0x24 ||
                   (*(undefined4 *)(lVar12 + 0xb38) = puVar7[9], uVar4 < 0x28)))) ||
                 ((uVar4 & 0xfffffffc) == 0x28)))) ||
               ((((((*(undefined4 *)(lVar12 + 0xb3c) = puVar7[10], uVar4 < 0x2c ||
                    ((uVar4 & 0xfffffffc) == 0x2c)) ||
                   (*(undefined4 *)(lVar12 + 0xb40) = puVar7[0xb], uVar4 < 0x30)) ||
                  ((((uVar4 & 0xfffffffc) == 0x30 ||
                    (*(undefined4 *)(lVar12 + 0xb44) = puVar7[0xc], uVar4 < 0x34)) ||
                   (((uVar4 & 0xfffffffc) == 0x34 ||
                    ((*(undefined4 *)(lVar12 + 0xb48) = puVar7[0xd], uVar4 < 0x38 ||
                     ((uVar4 & 0xfffffffc) == 0x38)))))))) ||
                 (*(undefined4 *)(lVar12 + 0xb4c) = puVar7[0xe], uVar4 < 0x3c)) ||
                ((uVar4 & 0xfffffffc) == 0x3c)))) goto LAB_00102f1c;
            *(undefined4 *)(lVar12 + 0xb50) = puVar7[0xf];
            *(long *)(lVar12 + 0xba0) = lVar12 + 0xb34;
            if ((((((((uVar4 < 0x40) || ((uVar4 & 0xfffffffc) == 0x40)) ||
                    (*(undefined4 *)(lVar12 + 0xb54) = puVar7[0x10], uVar4 < 0x44)) ||
                   (((uVar4 & 0xfffffffc) == 0x44 ||
                    (*(undefined4 *)(lVar12 + 0xb58) = puVar7[0x11], uVar4 < 0x48)))) ||
                  (((uVar4 & 0xfffffffc) == 0x48 ||
                   ((*(undefined4 *)(lVar12 + 0xb5c) = puVar7[0x12], uVar4 < 0x4c ||
                    ((uVar4 & 0xfffffffc) == 0x4c)))))) ||
                 (*(undefined4 *)(lVar12 + 0xb60) = puVar7[0x13], uVar4 < 0x50)) ||
                ((((((uVar4 & 0xfffffffc) == 0x50 ||
                    (*(undefined4 *)(lVar12 + 0xb64) = puVar7[0x14], uVar4 < 0x54)) ||
                   ((uVar4 & 0xfffffffc) == 0x54)) ||
                  ((*(undefined4 *)(lVar12 + 0xb68) = puVar7[0x15], uVar4 < 0x58 ||
                   ((uVar4 & 0xfffffffc) == 0x58)))) ||
                 (*(undefined4 *)(lVar12 + 0xb6c) = puVar7[0x16], uVar4 < 0x5c)))) ||
               ((uVar4 & 0xfffffffc) == 0x5c)) goto LAB_00102f1c;
            *(undefined4 *)(lVar12 + 0xb70) = puVar7[0x17];
            *(long *)(lVar12 + 0xba8) = lVar12 + 0xb54;
            if ((((((uVar4 < 0x60) || ((uVar4 & 0xfffffffc) == 0x60)) ||
                  ((*(undefined4 *)(lVar12 + 0xb74) = puVar7[0x18], uVar4 < 100 ||
                   ((((uVar4 & 0xfffffffc) == 100 ||
                     (*(undefined4 *)(lVar12 + 0xb78) = puVar7[0x19], uVar4 < 0x68)) ||
                    ((uVar4 & 0xfffffffc) == 0x68)))))) ||
                 ((*(undefined4 *)(lVar12 + 0xb7c) = puVar7[0x1a], uVar4 < 0x6c ||
                  ((uVar4 & 0xfffffffc) == 0x6c)))) ||
                ((*(undefined4 *)(lVar12 + 0xb80) = puVar7[0x1b], uVar4 < 0x70 ||
                 ((((uVar4 & 0xfffffffc) == 0x70 ||
                   (*(undefined4 *)(lVar12 + 0xb84) = puVar7[0x1c], uVar4 < 0x74)) ||
                  (((uVar4 & 0xfffffffc) == 0x74 ||
                   (((*(undefined4 *)(lVar12 + 0xb88) = puVar7[0x1d], uVar4 < 0x78 ||
                     ((uVar4 & 0xfffffffc) == 0x78)) ||
                    (*(undefined4 *)(lVar12 + 0xb8c) = puVar7[0x1e], uVar4 < 0x7c)))))))))) ||
               ((uVar4 & 0xfffffffc) == 0x7c)) goto LAB_00102f1c;
            *(undefined4 *)(lVar12 + 0xb90) = puVar7[0x1f];
            *(long *)(lVar12 + 0xbb0) = lVar12 + 0xb74;
            kfree(puVar7);
            lVar11 = get_matching_swr_slave_device(plVar6[1]);
            plVar5[5] = lVar11;
            if (lVar11 == 0) {
              pcVar8 = "%s: Could not find RX swr slave device\n";
LAB_00102df4:
              _dev_err(param_1,pcVar8,"wcd937x_bind");
              uVar2 = 0xffffffed;
            }
            else {
              lVar11 = get_matching_swr_slave_device(plVar6[2]);
              plVar5[6] = lVar11;
              if (lVar11 == 0) {
                pcVar8 = "%s: Could not find TX swr slave device\n";
                goto LAB_00102df4;
              }
              swr_init_port_params(lVar11,4,plVar5 + 0x173);
              lVar11 = __devm_regmap_init_swr(plVar5[6],&wcd937x_regmap_config,0,0);
              plVar5[4] = lVar11;
              if (lVar11 == 0) {
                _dev_err(param_1,"%s: Regmap init failed\n","wcd937x_bind");
                uVar2 = 0;
              }
              else {
                if (0 < _DAT_00113b00) {
                  iVar3 = 0;
                  do {
                    regmap_write(plVar5[4],iVar3 + 0x3474,0);
                    iVar3 = iVar3 + 1;
                  } while (iVar3 < _DAT_00113b00);
                  lVar11 = plVar5[4];
                }
                plVar10 = plVar5 + 0x1b;
                _DAT_00113b50 = plVar5;
                *plVar10 = (long)&wcd937x_regmap_irq_chip;
                plVar5[0x1c] = (long)"WCD937X";
                plVar5[0x1d] = lVar11;
                plVar5[0x1f] = param_1;
                uVar2 = wcd_irq_init(plVar10,plVar5 + 0x1a);
                if (uVar2 == 0) {
                  *(long *)(plVar5[6] + 1000) = plVar5[0x1a];
                  if ((int)plVar6[4] - 0xb23U < 0xfffff8c5) {
                    _printk(&DAT_00113363,"wcd937x_get_micb_vout_ctl_val");
                    uVar4 = 0xffffffea;
                  }
                  else {
                    uVar4 = ((int)plVar6[4] - 1000U >> 1 & 0x7fff) / 0x19;
                  }
                  if (*(int *)((long)plVar6 + 0x24) - 0xb23U < 0xfffff8c5) {
                    _printk(&DAT_00113363,"wcd937x_get_micb_vout_ctl_val");
                    uVar13 = 0xffffffea;
                  }
                  else {
                    uVar13 = (*(int *)((long)plVar6 + 0x24) - 1000U >> 1 & 0x7fff) / 0x19;
                  }
                  lVar11 = plVar6[5];
                  if ((int)lVar11 - 0xb23U < 0xfffff8c5) {
                    _printk(&DAT_00113363,"wcd937x_get_micb_vout_ctl_val");
                    uVar2 = 0xffffffea;
                    pcVar8 = "%s: bad micbias pdata\n";
                  }
                  else {
                    pcVar8 = "%s: bad micbias pdata\n";
                    uVar2 = 0xffffffea;
                    if ((-1 < (int)uVar4) && (-1 < (int)uVar13)) {
                      regmap_update_bits_base(plVar5[4],0x3022,0x3f,uVar4,0,0,0);
                      regmap_update_bits_base(plVar5[4],0x3023,0x3f,uVar13,0,0,0);
                      regmap_update_bits_base
                                (plVar5[4],0x3025,0x3f,((int)lVar11 - 1000U >> 1 & 0x7fff) / 0x19,0,
                                 0,0);
                      *(undefined8 *)((long)plVar5 + 0xc64) = 0x100000001;
                      __mutex_init(plVar5 + 0xc,"&wcd937x->micb_lock",&wcd937x_bind___key);
                      __mutex_init(plVar5 + 0x185,"&wcd937x->ana_tx_clk_lock",&wcd937x_bind___key_65
                                  );
                      wcd_request_irq(plVar10,0xe,"HPHR PDM WD INT",wcd937x_wd_handle_irq,0);
                      wcd_request_irq(plVar10,0xd,"HPHL PDM WD INT",wcd937x_wd_handle_irq,0);
                      wcd_request_irq(plVar10,0xf,"AUX PDM WD INT",wcd937x_wd_handle_irq,0);
                      wcd_disable_irq(plVar10,0xe);
                      wcd_disable_irq(plVar10,0xd);
                      wcd_disable_irq(plVar10,0xf);
                      uVar4 = snd_soc_register_component
                                        (param_1,&soc_codec_dev_wcd937x,&wcd937x_dai,1);
                      uVar2 = 0;
                      if (uVar4 == 0) goto LAB_00102ee4;
                      pcVar8 = "%s: Codec registration failed\n";
                      uVar2 = uVar4;
                    }
                  }
                  _dev_err(param_1,pcVar8,"wcd937x_bind");
                  wcd_irq_exit(plVar10,plVar5[0x1a]);
                }
                else {
                  _dev_err(param_1,"%s: IRQ init failed: %d\n","wcd937x_bind",uVar2);
                }
              }
            }
          }
          else {
            pcVar8 = "Failed to read port mapping\n";
LAB_00102dd4:
            _dev_err(param_1,pcVar8);
          }
          component_unbind_all(param_1,plVar5);
        }
        else {
          _dev_err(param_1,"%s: Slave bind failed, ret = %d\n","wcd937x_bind",uVar2);
        }
      }
    }
LAB_00102ed0:
    kfree(plVar6);
  }
  *(undefined8 *)(param_1 + 0x98) = 0;
  kfree(plVar5);
LAB_00102ee4:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd937x_unbind @ 00102f28 size=108
// signature: undefined wcd937x_unbind(void)
// callers: []
//------------------------------------------------------------

void wcd937x_unbind(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(long **)(param_1 + 0x98);
  uVar2 = *(undefined8 *)(*plVar1 + 0x90);
  wcd_irq_exit(plVar1 + 0x1b,plVar1[0x1a]);
  snd_soc_unregister_component(param_1);
  component_unbind_all(param_1,plVar1);
  *(undefined8 *)(param_1 + 0x98) = 0;
  kfree(uVar2);
  kfree(plVar1);
  return;
}



//------------------------------------------------------------
// wcd937x_reset @ 00102f94 size=212
// signature: undefined wcd937x_reset(void)
// callers: [wcd937x_bind, wcd937x_event_notify]
//------------------------------------------------------------

undefined8 wcd937x_reset(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 != 0) {
    if (*(long *)(lVar3 + 0x18) != 0) {
      iVar1 = msm_cdc_pinctrl_get_state();
      if (0 < iVar1) {
        return 0;
      }
      iVar1 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(lVar3 + 0x18));
      if (iVar1 == 0) {
        usleep_range_state(0x14,0x1e,2);
        iVar1 = msm_cdc_pinctrl_select_active_state(*(undefined8 *)(lVar3 + 0x18));
        if (iVar1 == 0) {
          usleep_range_state(0x14,0x1e,2);
          return 0;
        }
        pcVar2 = "%s: wcd active state request fail!\n";
      }
      else {
        pcVar2 = "%s: wcd sleep state request fail!\n";
      }
      _dev_err(param_1,pcVar2,"wcd937x_reset");
      return 0xfffffdfb;
    }
    _dev_err(param_1,"%s: reset gpio device node not specified\n","wcd937x_reset");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd937x_wakeup @ 0010306c size=92
// signature: undefined wcd937x_wakeup(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_wakeup(long param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    puVar2 = &DAT_00113481;
  }
  else {
    if (*(long *)(param_1 + 0x30) != 0) {
      if ((param_2 & 1) == 0) {
        uVar1 = swr_device_wakeup_unvote();
        return uVar1;
      }
      uVar1 = swr_device_wakeup_vote();
      return uVar1;
    }
    puVar2 = &DAT_00112aa0;
  }
  _printk(puVar2,"wcd937x_wakeup");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd937x_parse_port_mapping @ 001030c8 size=544
// signature: undefined wcd937x_parse_port_mapping(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

undefined8 wcd937x_parse_port_mapping(long param_1,undefined8 param_2,char param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined1 *puVar10;
  undefined4 *puVar11;
  long lVar12;
  uint uVar13;
  uint uVar14;
  uint local_6c;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_6c = 0;
  if (param_3 == '\0') {
    lVar12 = lVar6 + 0x114;
    puVar10 = (undefined1 *)(lVar6 + 0x110);
  }
  else {
    if (param_3 != '\x01') {
      _dev_err(param_1,"%s Invalid path selected %u\n","wcd937x_parse_port_mapping",param_3);
      uVar7 = 0xffffffea;
      goto LAB_0010321c;
    }
    lVar12 = lVar6 + 0x614;
    puVar10 = (undefined1 *)(lVar6 + 0x111);
  }
  lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),param_2,&local_6c);
  uVar13 = local_6c;
  if (lVar6 == 0) {
    _dev_err(param_1,"missing port mapping prop %s\n",param_2);
    uVar7 = 0xffffffea;
  }
  else {
    lVar6 = __kmalloc(local_6c,0xdc0);
    if (lVar6 == 0) {
      uVar7 = 0xfffffff4;
    }
    else {
      iVar3 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),param_2,lVar6,(uVar13 / 0x14) * 5,0);
      if (iVar3 < 0) {
        _dev_err(param_1,"%s: Failed to read  port mapping from prop %s\n",
                 "wcd937x_parse_port_mapping",param_2);
        uVar7 = 0xffffffea;
LAB_001032d8:
        kfree(lVar6);
      }
      else {
        if (uVar13 < 0x14) {
          uVar14 = 0;
        }
        else {
          uVar13 = uVar13 / 0x14;
          uVar5 = 0;
          if (uVar13 < 2) {
            uVar13 = 1;
          }
          uVar8 = (ulong)uVar13;
          puVar9 = (undefined4 *)(lVar6 + 8);
          uVar13 = 0;
          do {
            uVar14 = puVar9[-2];
            if (7 < uVar14 || 7 < uVar5) {
              _dev_err(param_1,"%s: Invalid port or channel number\n","wcd937x_parse_port_mapping");
              uVar7 = 0;
              goto LAB_001032d8;
            }
            if (uVar14 != uVar13) {
              uVar5 = 0;
            }
            uVar4 = *puVar9;
            puVar11 = (undefined4 *)(lVar12 + (ulong)uVar14 * 0xa0 + (ulong)uVar5 * 0x14);
            uVar1 = puVar9[1];
            uVar2 = puVar9[2];
            *puVar11 = puVar9[-1];
            puVar11[1] = uVar2;
            puVar11[2] = uVar4;
            uVar4 = __sw_hweight8();
            uVar5 = uVar5 + 1;
            puVar9 = puVar9 + 5;
            uVar8 = uVar8 - 1;
            puVar11[3] = uVar4;
            puVar11[4] = uVar1;
            uVar13 = uVar14;
          } while (uVar8 != 0);
        }
        *puVar10 = (char)uVar14;
        kfree(lVar6);
        uVar7 = 0;
      }
    }
  }
LAB_0010321c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// wcd937x_wd_handle_irq @ 001032ec size=92
// signature: undefined wcd937x_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wcd937x_wd_handle_irq__rs,"wcd937x_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001125ac,"wcd937x_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wcd937x_handle_post_irq @ 0010334c size=184
// signature: undefined wcd937x_handle_post_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_handle_post_irq(long param_1)

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
  regmap_read(*(undefined8 *)(param_1 + 0x20),0x346e,&local_2c);
  regmap_read(*(undefined8 *)(param_1 + 0x20),0x346f,&local_30);
  regmap_read(*(undefined8 *)(param_1 + 0x20),0x3470,&local_34);
  *(bool *)(*(long *)(param_1 + 0x30) + 0x3f0) = (local_2c != 0 || local_30 != 0) || local_34 != 0;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// wcd937x_soc_codec_probe @ 00103408 size=976
// signature: undefined wcd937x_soc_codec_probe(void)
// callers: []
//------------------------------------------------------------

int wcd937x_soc_codec_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  code *pcVar9;
  long lVar10;
  
  _dev_info(*(undefined8 *)(param_1 + 0x18),"%s()\n","wcd937x_soc_codec_probe");
  lVar10 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar10 == 0) {
    return -0x16;
  }
  *(long *)(lVar10 + 0x10) = param_1;
  snd_soc_component_init_regmap(param_1,*(undefined8 *)(lVar10 + 0x20));
  devm_regmap_qti_debugfs_register(*(long *)(lVar10 + 0x30) + 0x48,*(undefined8 *)(lVar10 + 0x20));
  uVar4 = snd_soc_component_read(param_1,0x34b0);
  *(undefined4 *)(lVar10 + 0xc20) = 0;
  *(uint *)(lVar10 + 8) = uVar4 >> 1 & 0xf;
  lVar6 = devm_kmalloc(*(undefined8 *)(param_1 + 0x18),0x78,0xdc0);
  *(long *)(lVar10 + 0x50) = lVar6;
  if (lVar6 == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"Failed to allocate fw_data\n");
    return -0xc;
  }
  puVar1 = (ulong *)(lVar6 + 0x20);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 4;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  iVar5 = wcd_cal_create_hwdep(*(undefined8 *)(lVar10 + 0x50),1000,param_1);
  if (iVar5 < 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s hwdep failed %d\n","wcd937x_soc_codec_probe",iVar5)
    ;
    *(undefined8 *)(lVar10 + 0x50) = 0;
    return iVar5;
  }
  iVar5 = wcd937x_mbhc_init(lVar10 + 0xc0,param_1,*(undefined8 *)(lVar10 + 0x50));
  if (iVar5 != 0) {
    _printk(&DAT_0011297e,"wcd937x_soc_codec_probe");
    *(undefined8 *)(lVar10 + 0x50) = 0;
    return iVar5;
  }
  lVar6 = param_1 + 0xd0;
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC1");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC2");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC3");
  snd_soc_dapm_ignore_suspend(lVar6,"IN1_HPHL");
  snd_soc_dapm_ignore_suspend(lVar6,"IN2_HPHR");
  snd_soc_dapm_ignore_suspend(lVar6,"IN3_AUX");
  snd_soc_dapm_ignore_suspend(lVar6,"ADC1_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,"ADC2_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,"WCD_TX_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_00112529);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_00112fc0);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_00112862);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_001120a8);
  snd_soc_dapm_ignore_suspend(lVar6,"WCD_TX_DUMMY");
  snd_soc_dapm_ignore_suspend(lVar6,"WCD_RX_DUMMY");
  snd_soc_dapm_sync(lVar6);
  wcd_cls_h_init(lVar10 + 0x9c);
  wcd937x_init_reg(param_1);
  if (*(int *)(lVar10 + 8) == 5) {
    iVar5 = snd_soc_dapm_new_controls(lVar6,wcd9375_dapm_widgets,0x17);
    if (iVar5 < 0) {
      uVar7 = *(undefined8 *)(param_1 + 0x18);
      pcVar8 = "%s: Failed to add snd_ctls\n";
    }
    else {
      iVar5 = snd_soc_dapm_add_routes(lVar6,&wcd9375_audio_map,0x18);
      if (-1 < iVar5) {
        snd_soc_dapm_ignore_suspend(lVar6,"AMIC4");
        snd_soc_dapm_ignore_suspend(lVar6,"DMIC1_OUTPUT");
        snd_soc_dapm_ignore_suspend(lVar6,"DMIC2_OUTPUT");
        snd_soc_dapm_ignore_suspend(lVar6,"DMIC3_OUTPUT");
        snd_soc_dapm_ignore_suspend(lVar6,"DMIC4_OUTPUT");
        snd_soc_dapm_ignore_suspend(lVar6,"DMIC5_OUTPUT");
        snd_soc_dapm_ignore_suspend(lVar6,"DMIC6_OUTPUT");
        snd_soc_dapm_ignore_suspend(lVar6,"ADC3_OUTPUT");
        snd_soc_dapm_sync(lVar6);
        goto LAB_001036b0;
      }
      uVar7 = *(undefined8 *)(param_1 + 0x18);
      pcVar8 = "%s: Failed to add routes\n";
    }
    _dev_err(uVar7,pcVar8,"wcd937x_soc_codec_probe");
    *(undefined8 *)(lVar10 + 0x50) = 0;
  }
  else {
    iVar5 = 0;
LAB_001036b0:
    pcVar9 = *(code **)(lVar10 + 0xbe8);
    *(undefined4 *)(lVar10 + 0xbf8) = 1;
    *(code **)(lVar10 + 0xbc0) = wcd937x_event_notify;
    if (pcVar9 != (code *)0x0) {
      if (*(int *)(pcVar9 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1036f0);
        (*pcVar9)();
      }
      iVar5 = (*pcVar9)(*(undefined8 *)(lVar10 + 0xbd8),lVar10 + 0xbc0,1);
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Failed to register notifier %d\n",
                 "wcd937x_soc_codec_probe",iVar5);
      }
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// wcd937x_soc_codec_remove @ 001037e8 size=84
// signature: undefined wcd937x_soc_codec_remove(void)
// callers: []
//------------------------------------------------------------

void wcd937x_soc_codec_remove(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if ((lVar2 != 0) && (pcVar1 = *(code **)(lVar2 + 0xbe8), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10382c);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(lVar2 + 0xbd8),lVar2 + 0xbc0,0);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_ear_pa_gain_get @ 00103840 size=64
// signature: undefined wcd937x_ear_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_ear_pa_gain_get(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0x80),0x300b);
  *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 >> 2 & 0x1f);
  return 0;
}



//------------------------------------------------------------
// wcd937x_ear_pa_gain_put @ 00103884 size=68
// signature: undefined wcd937x_ear_pa_gain_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_ear_pa_gain_put(long param_1,long param_2)

{
  if (*(char *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xcc) == '\0') {
    snd_soc_component_update_bits
              (*(long *)(param_1 + 0x80),0x300b,0x7c,(*(uint *)(param_2 + 0x48) & 0x3f) << 2);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_rx_hph_mode_get @ 001038cc size=28
// signature: undefined wcd937x_rx_hph_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_rx_hph_mode_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(uint *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 200);
  return 0;
}



//------------------------------------------------------------
// wcd937x_rx_hph_mode_put @ 001038ec size=88
// signature: undefined wcd937x_rx_hph_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_rx_hph_mode_put(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x80) + 0x18);
  iVar2 = *(int *)(param_2 + 0x48);
  lVar3 = *(long *)(lVar1 + 0x98);
  if (iVar2 == 0) {
    _dev_warn(lVar1,"%s:Invalid HPH Mode, default to class_AB\n","wcd937x_rx_hph_mode_put");
    iVar2 = 3;
  }
  *(int *)(lVar3 + 200) = iVar2;
  return 0;
}



//------------------------------------------------------------
// wcd937x_get_compander @ 00103948 size=44
// signature: undefined wcd937x_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_get_compander(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0xcc;
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) != 0) {
    lVar1 = 0xcd;
  }
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + lVar1);
  return 0;
}



//------------------------------------------------------------
// wcd937x_set_compander @ 00103978 size=56
// signature: undefined wcd937x_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_set_compander(long param_1,long param_2)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = *(int *)(param_2 + 0x48) != 0;
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) == 0) {
    *(bool *)(lVar2 + 0xcc) = bVar1;
    return 0;
  }
  *(bool *)(lVar2 + 0xcd) = bVar1;
  return 0;
}



//------------------------------------------------------------
// wcd937x_bcs_get @ 001039b4 size=28
// signature: undefined wcd937x_bcs_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_bcs_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xce);
  return 0;
}



//------------------------------------------------------------
// wcd937x_bcs_put @ 001039d4 size=36
// signature: undefined wcd937x_bcs_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_bcs_put(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xce) =
       *(long *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wcd937x_tx_master_ch_get @ 001039fc size=176
// signature: undefined wcd937x_tx_master_ch_get(void)
// callers: []
//------------------------------------------------------------

void wcd937x_tx_master_ch_get(long param_1,long param_2)

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
    wcd937x_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if (local_2c < 10) {
      uVar2 = 0;
      uVar1 = *(byte *)(lVar3 + (ulong)local_2c + 0xc58) - 0x2e;
      lVar3 = 0;
      if (uVar1 < 9) {
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
// wcd937x_tx_master_ch_put @ 00103ab0 size=180
// signature: undefined wcd937x_tx_master_ch_put(void)
// callers: []
//------------------------------------------------------------

void wcd937x_tx_master_ch_put(long param_1,long param_2)

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
    wcd937x_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if ((local_2c < 10) && (*(uint *)(param_2 + 0x48) < 0xe)) {
      uVar1 = 0;
      *(char *)(lVar2 + (ulong)local_2c + 0xc58) =
           (char)*(undefined4 *)(wcd937x_swr_master_ch_map + (ulong)*(uint *)(param_2 + 0x48) * 4);
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
// wcd937x_tx_ch_pwr_level_get @ 00103b68 size=132
// signature: undefined wcd937x_tx_ch_pwr_level_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_tx_ch_pwr_level_get(long param_1,long param_2)

{
  long lVar1;
  uint *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  lVar1 = strnstr(param_1 + 0x20,&DAT_0011318b,0x2c);
  if (lVar1 == 0) {
    lVar1 = strnstr(param_1 + 0x20,&DAT_001136f5,0x2c);
    if (lVar1 == 0) {
      return 0;
    }
    puVar2 = (uint *)(lVar3 + 0xc68);
  }
  else {
    puVar2 = (uint *)(lVar3 + 0xc64);
  }
  *(ulong *)(param_2 + 0x48) = (ulong)*puVar2;
  return 0;
}



//------------------------------------------------------------
// wcd937x_tx_ch_pwr_level_put @ 00103bf0 size=168
// signature: undefined wcd937x_tx_ch_pwr_level_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_tx_ch_pwr_level_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x80);
  iVar1 = *(int *)(param_2 + 0x48);
  lVar5 = *(long *)(*(long *)(lVar4 + 0x18) + 0x98);
  lVar2 = strnstr(param_1 + 0x20,&DAT_0011318b,0x2c);
  if (lVar2 == 0) {
    lVar2 = strnstr(param_1 + 0x20,&DAT_001136f5,0x2c);
    if (lVar2 == 0) {
      return 0;
    }
    snd_soc_component_update_bits(lVar4,0x3010,0x60,iVar1 << 5);
    piVar3 = (int *)(lVar5 + 0xc68);
  }
  else {
    snd_soc_component_update_bits(lVar4,0x300e,0x60,iVar1 << 5);
    piVar3 = (int *)(lVar5 + 0xc64);
  }
  *piVar3 = iVar1;
  return 0;
}



//------------------------------------------------------------
// wcd937x_tx_get_slave_ch_type_idx @ 00103c98 size=404
// signature: undefined wcd937x_tx_get_slave_ch_type_idx(void)
// callers: [wcd937x_tx_master_ch_put, wcd937x_tx_master_ch_get]
//------------------------------------------------------------

void wcd937x_tx_get_slave_ch_type_idx(undefined8 param_1,uint *param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  lVar1 = strnstr(param_1,&DAT_00112b90,5);
  if (lVar1 == 0) {
    lVar1 = strnstr(param_1,&DAT_00113186,5);
    if (lVar1 == 0) {
      lVar1 = strnstr(param_1,&DAT_001130b1,5);
      if (lVar1 == 0) {
        lVar1 = strnstr(param_1,"DMIC0",6);
        if (lVar1 == 0) {
          lVar1 = strnstr(param_1,"DMIC1",6);
          if (lVar1 == 0) {
            lVar3 = 5;
            lVar1 = strnstr(param_1,&DAT_00112045,5);
            if (lVar1 == 0) {
              lVar3 = 6;
              lVar1 = strnstr(param_1,"DMIC2",6);
              if (lVar1 == 0) {
                lVar1 = strnstr(param_1,"DMIC3",6);
                if (lVar1 == 0) {
                  lVar1 = strnstr(param_1,"DMIC4",6);
                  if (lVar1 == 0) {
                    lVar1 = strnstr(param_1,"DMIC5",6);
                    if (lVar1 == 0) {
                      _printk(&DAT_001137f1,"wcd937x_tx_get_slave_ch_type_idx",param_1);
                      uVar2 = 0xffffffea;
                      goto LAB_00103df4;
                    }
                    lVar3 = 9;
                  }
                  else {
                    lVar3 = 8;
                  }
                }
                else {
                  lVar3 = 7;
                }
              }
            }
          }
          else {
            lVar3 = 4;
          }
        }
        else {
          lVar3 = 3;
        }
      }
      else {
        lVar3 = 2;
      }
    }
    else {
      lVar3 = 1;
    }
  }
  else {
    lVar3 = 0;
  }
  uVar2 = (uint)(byte)wcd937x_swr_slv_tx_ch_idx[lVar3 * 2 + 1];
LAB_00103df4:
  *param_2 = uVar2;
  return;
}



//------------------------------------------------------------
// wcd937x_codec_enable_adc @ 00103e30 size=464
// signature: undefined wcd937x_codec_enable_adc(void)
// callers: []
//------------------------------------------------------------

void wcd937x_codec_enable_adc(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined1 local_4c [4];
  undefined1 auStack_48 [4];
  undefined1 local_44 [4];
  undefined1 auStack_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar8 = *(long *)(param_1 + 0x28);
  lVar6 = lVar8 + -0xd0;
  lVar7 = *(long *)(*(long *)(lVar8 + -0xb8) + 0x98);
  if (param_3 == 8) {
    wcd937x_tx_connect_port(lVar6,*(byte *)(param_1 + 0x4c) + 0x1e,0);
    if ((*(char *)(param_1 + 0x4c) == '\x01') &&
       (((uint)*(undefined8 *)(lVar7 + 0x108) >> 3 & 1) != 0)) {
      lVar8 = *(long *)(*(long *)(lVar8 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_44[0] = 0;
      iVar4 = wcd937x_set_port_params(lVar6,0x1d,local_3c,auStack_40,local_44,auStack_48,local_4c,0)
      ;
      if (iVar4 == 0) {
        local_4c[0] = *(undefined1 *)(lVar8 + 0xc5d);
        swr_disconnect_port(*(undefined8 *)(lVar8 + 0x30),local_3c,1,local_44,local_4c);
      }
      puVar1 = (ulong *)(lVar7 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffff7;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    iVar4 = *(int *)(lVar7 + 0xc20) + -1;
    *(int *)(lVar7 + 0xc20) = iVar4;
    if (iVar4 < 1) {
      snd_soc_component_update_bits(lVar6,0x3408,8,0);
      uVar5 = 0;
      *(undefined4 *)(lVar7 + 0xc20) = 0;
      goto LAB_00103f9c;
    }
  }
  else if (param_3 == 1) {
    mutex_lock(lVar7 + 0xc28);
    *(int *)(lVar7 + 0xc1c) = *(int *)(lVar7 + 0xc1c) + 1;
    mutex_unlock(lVar7 + 0xc28);
    *(int *)(lVar7 + 0xc20) = *(int *)(lVar7 + 0xc20) + 1;
    snd_soc_component_update_bits(lVar6,0x3409,0x80,0x80);
    snd_soc_component_update_bits(lVar6,0x3408,8,8);
    snd_soc_component_update_bits(lVar6,0x3408,0x10,0x10);
    uVar5 = swr_slvdev_datapath_control
                      (*(long *)(lVar7 + 0x30),*(undefined1 *)(*(long *)(lVar7 + 0x30) + 0x40),1);
    goto LAB_00103f9c;
  }
  uVar5 = 0;
LAB_00103f9c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_enable_req @ 00104010 size=432
// signature: undefined wcd937x_enable_req(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_enable_req(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    if (*(int *)(lVar3 + 0xc20) == 0) {
      snd_soc_component_update_bits(lVar2,0x300e,0x80,0);
      snd_soc_component_update_bits(lVar2,0x300f,0x80,0);
      snd_soc_component_update_bits(lVar2,0x3010,0x80,0);
      snd_soc_component_update_bits(lVar2,0x3409,0x10,0);
      snd_soc_component_update_bits(lVar2,0x3409,0x80,0);
    }
    mutex_lock(lVar3 + 0xc28);
    iVar1 = *(int *)(lVar3 + 0xc1c) + -1;
    *(int *)(lVar3 + 0xc1c) = iVar1;
    if (iVar1 < 1) {
      snd_soc_component_update_bits(lVar2,0x3408,0x10,0);
      *(undefined4 *)(lVar3 + 0xc1c) = 0;
    }
    mutex_unlock(lVar3 + 0xc28);
  }
  else if (param_3 == 1) {
    snd_soc_component_update_bits(lVar2,0x3457,2,2);
    snd_soc_component_update_bits(lVar2,0x3457,1,0);
    snd_soc_component_update_bits(lVar2,0x300f,0x40,0x40);
    snd_soc_component_update_bits(lVar2,0x3011,0x40,0x40);
    snd_soc_component_update_bits(lVar2,0x3409,0x70,0x70);
    snd_soc_component_update_bits(lVar2,0x300e,0x80,0x80);
    snd_soc_component_update_bits(lVar2,0x300f,0x40,0);
    snd_soc_component_update_bits(lVar2,0x300f,0x80,0x80);
    snd_soc_component_update_bits(lVar2,0x3010,0x80,0x80);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_tx_swr_ctrl @ 001041c4 size=236
// signature: undefined wcd937x_tx_swr_ctrl(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_tx_swr_ctrl(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  lVar9 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 == 8) {
    uVar7 = swr_slvdev_datapath_control
                      (*(long *)(lVar9 + 0x30),*(undefined1 *)(*(long *)(lVar9 + 0x30) + 0x40),0);
  }
  else {
    if (param_3 == 1) {
      lVar8 = *(long *)(param_1 + 0x28) + -0xd0;
      lVar6 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011297a,4);
      if (lVar6 == 0) {
        iVar1 = *(byte *)(param_1 + 0x4c) + 0x22;
      }
      else {
        if (((*(byte *)(param_1 + 0x4c) == 1) &&
            (uVar5 = snd_soc_component_read(lVar8,0x3127), (uVar5 >> 7 & 1) == 0)) &&
           (*(char *)(lVar9 + 0xce) == '\0')) {
          wcd937x_tx_connect_port(lVar8,0x1d,1);
          puVar2 = (ulong *)(lVar9 + 0x108);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar4) {
              *puVar2 = *puVar2 | 8;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
        }
        iVar1 = *(byte *)(param_1 + 0x4c) + 0x1e;
      }
      wcd937x_tx_connect_port(lVar8,iVar1,1);
    }
    uVar7 = 0;
  }
  return uVar7;
}



//------------------------------------------------------------
// wcd937x_codec_enable_micbias @ 001042c0 size=224
// signature: undefined wcd937x_codec_enable_micbias(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_enable_micbias(long param_1,undefined8 param_2,int param_3)

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
  wcd937x_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_enable_vdd_buck @ 001043a4 size=296
// signature: undefined wcd937x_codec_enable_vdd_buck(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_enable_vdd_buck(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  
  lVar10 = *(long *)(param_1 + 0x28);
  lVar7 = *(long *)(lVar10 + -0xb8);
  plVar9 = *(long **)(lVar7 + 0x98);
  lVar8 = *(long *)(*plVar9 + 0x90);
  if (lVar8 == 0) {
    pcVar6 = "%s: pdata is NULL\n";
LAB_00104474:
    _dev_err(lVar7,pcVar6,"wcd937x_codec_enable_vdd_buck");
    uVar5 = 0xffffffea;
  }
  else {
    if (param_3 == 8) {
      puVar1 = (ulong *)(plVar9 + 0x21);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else if (param_3 == 1) {
      if ((plVar9[0x21] & 1U) == 0) {
        iVar4 = msm_cdc_enable_ondemand_supply
                          (*plVar9,plVar9[0x177],*(undefined8 *)(lVar8 + 0x30),
                           *(undefined4 *)(lVar8 + 0x38),"cdc-vdd-buck");
        if (iVar4 == -0x16) {
          lVar7 = *(long *)(lVar10 + -0xb8);
          pcVar6 = "%s: vdd buck is not enabled\n";
          goto LAB_00104474;
        }
        puVar1 = (ulong *)(plVar9 + 0x21);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xfffffffffffffffe;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        usleep_range_state(200,0xfa,2);
      }
      else {
        puVar1 = (ulong *)(plVar9 + 0x21);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xfffffffffffffffe;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// wcd937x_enable_clsh @ 001044f8 size=276
// signature: undefined wcd937x_enable_clsh(void)
// callers: []
//------------------------------------------------------------

void wcd937x_enable_clsh(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined1 local_3c [4];
  undefined4 local_38;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (*(uint *)(lVar3 + 200) < 6 && (1 << (ulong)(*(uint *)(lVar3 + 200) & 0x1f) & 0x36U) != 0) {
    local_2c[0] = 0;
    local_30[0] = 0;
    local_34[0] = 0;
    local_38 = 0;
    local_3c[0] = 0;
    iVar1 = wcd937x_set_port_params
                      (*(long *)(param_1 + 0x28) + -0xd0,0x12,local_2c,local_30,local_34,&local_38,
                       local_3c,1);
    if (iVar1 == 0) {
      if ((param_3 & 3) == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar3 + 0x28),local_2c,1,local_34,local_3c);
      }
      else {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_2c,1,local_34,&local_38,local_30,
                         local_3c);
      }
    }
  }
  if ((param_3 & 0xc) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = swr_slvdev_datapath_control
                      (*(long *)(lVar3 + 0x28),*(undefined1 *)(*(long *)(lVar3 + 0x28) + 0x40),0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_codec_enable_ear_pa @ 00104610 size=564
// signature: undefined wcd937x_codec_enable_ear_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd937x_codec_enable_ear_pa(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  code *pcVar7;
  long lVar8;
  long lVar9;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar8 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar9 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  iVar1 = *(int *)(lVar9 + 200);
  switch(param_3) {
  case 1:
    uVar2 = swr_slvdev_datapath_control
                      (*(long *)(lVar9 + 0x28),*(undefined1 *)(*(long *)(lVar9 + 0x28) + 0x40),1);
    uVar3 = snd_soc_component_read(lVar8,0x3450);
    *(uint *)(lVar9 + 0xc18) = uVar3;
    if ((uVar3 & 1) == 0) {
      uVar4 = 0x3465;
      uVar5 = 7;
      uVar6 = 3;
    }
    else {
      uVar4 = 0x3467;
      uVar5 = 1;
      uVar6 = 1;
    }
    snd_soc_component_update_bits(lVar8,uVar4,uVar5,uVar6);
    if (*(char *)(lVar9 + 0xcc) == '\0') {
      snd_soc_component_update_bits(lVar8,0x300b,0x80,0x80);
      return uVar2;
    }
    return uVar2;
  case 2:
    usleep_range_state(6000,0x177a,2);
    if (iVar1 == 6 || iVar1 == 3) {
      snd_soc_component_update_bits(lVar8,0x3008,2,2);
    }
    pcVar7 = *(code **)(lVar9 + 0xbe0);
    if (pcVar7 != (code *)0x0) {
      if (*(int *)(pcVar7 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1046f8);
        (*pcVar7)();
      }
      (*pcVar7)(*(undefined8 *)(lVar9 + 0xbd8),1,0);
    }
    if ((*(byte *)(lVar9 + 0xc18) & 1) == 0) {
      wcd_enable_irq(lVar9 + 0xd8,0xd);
    }
    else {
      wcd_enable_irq(lVar9 + 0xd8,0xf);
    }
    break;
  case 4:
    uVar2 = 0xd;
    if ((*(uint *)(lVar9 + 0xc18) & 1) != 0) {
      uVar2 = 0xf;
    }
    wcd_disable_irq(lVar9 + 0xd8,uVar2);
    pcVar7 = *(code **)(lVar9 + 0xbe0);
    if (pcVar7 != (code *)0x0) {
      if (*(int *)(pcVar7 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10475c);
        (*pcVar7)();
      }
      (*pcVar7)(*(undefined8 *)(lVar9 + 0xbd8),1,1);
    }
    break;
  case 8:
    if (*(char *)(lVar9 + 0xcc) == '\0') {
      snd_soc_component_update_bits(lVar8,0x300b,0x80,0);
    }
    usleep_range_state(7000,0x1b62,2);
    wcd_cls_h_fsm(lVar8,lVar9 + 0x9c,2,1,iVar1);
    snd_soc_component_update_bits(lVar8,0x30a4,4,4);
    if ((*(byte *)(lVar9 + 0xc18) & 1) == 0) {
      uVar4 = 0x3465;
      uVar5 = 7;
    }
    else {
      uVar4 = 0x3467;
      uVar5 = 1;
    }
    snd_soc_component_update_bits(lVar8,uVar4,uVar5,0);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_enable_aux_pa @ 00104848 size=392
// signature: undefined wcd937x_codec_enable_aux_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd937x_codec_enable_aux_pa(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar4 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  iVar1 = *(int *)(lVar5 + 200);
  switch(param_3) {
  case 1:
    uVar2 = swr_slvdev_datapath_control
                      (*(long *)(lVar5 + 0x28),*(undefined1 *)(*(long *)(lVar5 + 0x28) + 0x40),1);
    snd_soc_component_update_bits(lVar4,0x3467,1,1);
    return uVar2;
  case 2:
    usleep_range_state(1000,0x3f2,2);
    if (iVar1 == 6 || iVar1 == 3) {
      snd_soc_component_update_bits(lVar4,0x3008,2,2);
    }
    pcVar3 = *(code **)(lVar5 + 0xbe0);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104920);
        (*pcVar3)();
      }
      (*pcVar3)(*(undefined8 *)(lVar5 + 0xbd8),1,0x20000);
    }
    wcd_enable_irq(lVar5 + 0xd8,0xf);
    break;
  case 4:
    wcd_disable_irq(lVar5 + 0xd8,0xf);
    pcVar3 = *(code **)(lVar5 + 0xbe0);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104970);
        (*pcVar3)();
      }
      (*pcVar3)(*(undefined8 *)(lVar5 + 0xbd8),1,0x20001);
    }
    break;
  case 8:
    usleep_range_state(2000,0x7da,2);
    wcd_cls_h_fsm(lVar4,lVar5 + 0x9c,2,8,iVar1);
    snd_soc_component_update_bits(lVar4,0x3467,1,0);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_enable_hphl_pa @ 001049d4 size=708
// signature: undefined wcd937x_codec_enable_hphl_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd937x_codec_enable_hphl_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar9 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar10 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  iVar2 = *(int *)(lVar10 + 200);
  switch(param_3) {
  case 1:
    uVar5 = swr_slvdev_datapath_control
                      (*(long *)(lVar10 + 0x28),*(undefined1 *)(*(long *)(lVar10 + 0x28) + 0x40),1);
    wcd_cls_h_fsm(lVar9,lVar10 + 0x9c,1,2,iVar2);
    snd_soc_component_update_bits(lVar9,0x3009,0x20,0x20);
    usleep_range_state(100,0x6e,2);
    puVar1 = (ulong *)(lVar10 + 0x108);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 4;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    snd_soc_component_update_bits(lVar9,0x3465,7,3);
    return uVar5;
  case 2:
    if (((uint)*(undefined8 *)(lVar10 + 0x108) >> 2 & 1) != 0) {
      if (*(char *)(lVar10 + 0xcc) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      puVar1 = (ulong *)(lVar10 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    snd_soc_component_update_bits(lVar9,0x313a,2,2);
    if (iVar2 == 6 || iVar2 == 3) {
      snd_soc_component_update_bits(lVar9,0x3008,2,2);
    }
    pcVar8 = *(code **)(lVar10 + 0xbe0);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x104bb4);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xbd8),1,0);
    }
    wcd_enable_irq(lVar10 + 0xd8,0xd);
    break;
  case 4:
    wcd_disable_irq(lVar10 + 0xd8,0xd);
    pcVar8 = *(code **)(lVar10 + 0xbe0);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x104ad4);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xbd8),1,1);
    }
    blocking_notifier_call_chain(*(long *)(lVar10 + 0xc0) + 0x428,0xd);
    puVar1 = (ulong *)(lVar10 + 0x108);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 4;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    break;
  case 8:
    if (((uint)*(undefined8 *)(lVar10 + 0x108) >> 2 & 1) != 0) {
      if (*(char *)(lVar10 + 0xcc) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      puVar1 = (ulong *)(lVar10 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    snd_soc_component_update_bits(lVar9,0x3465,7,0);
    blocking_notifier_call_chain(*(long *)(lVar10 + 0xc0) + 0x428,10);
    snd_soc_component_update_bits(lVar9,0x3009,0x20,0);
    wcd_cls_h_fsm(lVar9,lVar10 + 0x9c,2,2,iVar2);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_enable_hphr_pa @ 00104cd0 size=708
// signature: undefined wcd937x_codec_enable_hphr_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd937x_codec_enable_hphr_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar9 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar10 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  iVar2 = *(int *)(lVar10 + 200);
  switch(param_3) {
  case 1:
    uVar5 = swr_slvdev_datapath_control
                      (*(long *)(lVar10 + 0x28),*(undefined1 *)(*(long *)(lVar10 + 0x28) + 0x40),1);
    wcd_cls_h_fsm(lVar9,lVar10 + 0x9c,1,4,iVar2);
    snd_soc_component_update_bits(lVar9,0x3009,0x10,0x10);
    usleep_range_state(100,0x6e,2);
    puVar1 = (ulong *)(lVar10 + 0x108);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 4;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    snd_soc_component_update_bits(lVar9,0x3466,7,3);
    return uVar5;
  case 2:
    if (((uint)*(undefined8 *)(lVar10 + 0x108) >> 2 & 1) != 0) {
      if (*(char *)(lVar10 + 0xcd) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      puVar1 = (ulong *)(lVar10 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    snd_soc_component_update_bits(lVar9,0x313a,2,2);
    if (iVar2 == 6 || iVar2 == 3) {
      snd_soc_component_update_bits(lVar9,0x3008,2,2);
    }
    pcVar8 = *(code **)(lVar10 + 0xbe0);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x104eb0);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xbd8),1,0x10000);
    }
    wcd_enable_irq(lVar10 + 0xd8,0xe);
    break;
  case 4:
    wcd_disable_irq(lVar10 + 0xd8,0xe);
    pcVar8 = *(code **)(lVar10 + 0xbe0);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x104dd0);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xbd8),1,0x10001);
    }
    blocking_notifier_call_chain(*(long *)(lVar10 + 0xc0) + 0x428,0xe);
    puVar1 = (ulong *)(lVar10 + 0x108);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 4;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    break;
  case 8:
    if (((uint)*(undefined8 *)(lVar10 + 0x108) >> 2 & 1) != 0) {
      if (*(char *)(lVar10 + 0xcd) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      puVar1 = (ulong *)(lVar10 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    snd_soc_component_update_bits(lVar9,0x3466,7,0);
    blocking_notifier_call_chain(*(long *)(lVar10 + 0xc0) + 0x428,0xc);
    snd_soc_component_update_bits(lVar9,0x3009,0x10,0);
    wcd_cls_h_fsm(lVar9,lVar10 + 0x9c,2,4,iVar2);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_hphl_dac_event @ 00104fcc size=600
// signature: undefined wcd937x_codec_hphl_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_hphl_dac_event(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  
  lVar10 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    iVar6 = snd_soc_component_read(lVar10,0x34c0);
    if ((iVar6 == 2) &&
       (uVar5 = snd_soc_component_read(lVar10,0x3009), ((uVar5 ^ 0xffffffff) & 0xc) == 0)) {
      snd_soc_component_update_bits(lVar10,0x30bf,0xf0,0x80);
    }
    uVar8 = 0x3133;
    uVar7 = 0xf;
    uVar9 = 1;
    goto LAB_001051ec;
  }
  lVar11 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 != 2) {
    if (param_3 != 1) {
      return 0;
    }
    wcd937x_rx_clk_enable(lVar10);
    snd_soc_component_update_bits(lVar10,0x3409,1,1);
    snd_soc_component_update_bits(lVar10,0x344e,4,4);
    snd_soc_component_update_bits(lVar10,0x30d9,0x80,0);
    puVar1 = (ulong *)(lVar11 + 0x108);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 2;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    return 0;
  }
  iVar6 = *(int *)(lVar11 + 200);
  iVar4 = snd_soc_component_read(lVar10,0x34c0);
  if ((iVar4 == 2) &&
     (uVar5 = snd_soc_component_read(lVar10,0x3009), ((uVar5 ^ 0xffffffff) & 0xc) == 0)) {
    snd_soc_component_update_bits(lVar10,0x30bf,0xf0,0x90);
  }
  if (iVar6 == 1 || iVar6 == 6) {
    uVar8 = 2;
LAB_00105118:
    snd_soc_component_update_bits(lVar10,0x3133,0xf,uVar8);
  }
  else if (iVar6 == 4) {
    uVar8 = 6;
    goto LAB_00105118;
  }
  if (*(char *)(lVar11 + 0xcc) == '\0') {
    snd_soc_component_update_bits(lVar10,0x3414,2,0);
    snd_soc_component_update_bits(lVar10,0x30d3,0x20,0x20);
  }
  else {
    snd_soc_component_update_bits(lVar10,0x3414,2,2);
    snd_soc_component_update_bits(lVar10,0x30d3,0x20,0);
    if (*(char *)(lVar11 + 0xcd) != '\0') {
      snd_soc_component_update_bits(lVar10,0x3414,1,1);
      snd_soc_component_update_bits(lVar10,0x30d6,0x20,0);
    }
    if (((uint)*(undefined8 *)(lVar11 + 0x108) >> 1 & 1) != 0) {
      usleep_range_state(5000,0x13ec,2);
      puVar1 = (ulong *)(lVar11 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  uVar8 = 0x313a;
  uVar7 = 2;
  uVar9 = 0;
LAB_001051ec:
  snd_soc_component_update_bits(lVar10,uVar8,uVar7,uVar9);
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_hphr_dac_event @ 00105248 size=600
// signature: undefined wcd937x_codec_hphr_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_hphr_dac_event(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  
  lVar10 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    iVar6 = snd_soc_component_read(lVar10,0x34c0);
    if ((iVar6 == 2) &&
       (uVar5 = snd_soc_component_read(lVar10,0x3009), ((uVar5 ^ 0xffffffff) & 0xc) == 0)) {
      snd_soc_component_update_bits(lVar10,0x30bf,0xf0,0x80);
    }
    uVar8 = 0x3136;
    uVar7 = 0xf;
    uVar9 = 1;
    goto LAB_00105468;
  }
  lVar11 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 != 2) {
    if (param_3 != 1) {
      return 0;
    }
    wcd937x_rx_clk_enable(lVar10);
    snd_soc_component_update_bits(lVar10,0x3409,2,2);
    snd_soc_component_update_bits(lVar10,0x344e,8,8);
    snd_soc_component_update_bits(lVar10,0x30d9,0x80,0);
    puVar1 = (ulong *)(lVar11 + 0x108);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 2;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    return 0;
  }
  iVar6 = *(int *)(lVar11 + 200);
  iVar4 = snd_soc_component_read(lVar10,0x34c0);
  if ((iVar4 == 2) &&
     (uVar5 = snd_soc_component_read(lVar10,0x3009), ((uVar5 ^ 0xffffffff) & 0xc) == 0)) {
    snd_soc_component_update_bits(lVar10,0x30bf,0xf0,0x90);
  }
  if (iVar6 == 1 || iVar6 == 6) {
    uVar8 = 2;
LAB_00105394:
    snd_soc_component_update_bits(lVar10,0x3136,0xf,uVar8);
  }
  else if (iVar6 == 4) {
    uVar8 = 6;
    goto LAB_00105394;
  }
  if (*(char *)(lVar11 + 0xcd) == '\0') {
    snd_soc_component_update_bits(lVar10,0x3414,1,0);
    snd_soc_component_update_bits(lVar10,0x30d6,0x20,0x20);
  }
  else {
    snd_soc_component_update_bits(lVar10,0x3414,1,1);
    snd_soc_component_update_bits(lVar10,0x30d6,0x20,0);
    if (*(char *)(lVar11 + 0xcc) != '\0') {
      snd_soc_component_update_bits(lVar10,0x3414,2,2);
      snd_soc_component_update_bits(lVar10,0x30d3,0x20,0);
    }
    if (((uint)*(undefined8 *)(lVar11 + 0x108) >> 1 & 1) != 0) {
      usleep_range_state(5000,0x13ec,2);
      puVar1 = (ulong *)(lVar11 + 0x108);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  uVar8 = 0x313a;
  uVar7 = 2;
  uVar9 = 0;
LAB_00105468:
  snd_soc_component_update_bits(lVar10,uVar8,uVar7,uVar9);
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_ear_dac_event @ 001054c4 size=344
// signature: undefined wcd937x_codec_ear_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_ear_dac_event(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  uVar1 = *(uint *)(lVar4 + 200);
  if (param_3 == 8) {
    if (uVar1 < 7 && (1 << (ulong)(uVar1 & 0x1f) & 0x52U) != 0) {
      snd_soc_component_update_bits(lVar3,0x3133,0xf,1);
    }
    if (*(char *)(lVar4 + 0xcc) == '\0') {
      return 0;
    }
    snd_soc_component_update_bits(lVar3,0x3414,2,0);
    return 0;
  }
  if (param_3 != 1) {
    return 0;
  }
  wcd937x_rx_clk_enable(lVar3);
  snd_soc_component_update_bits(lVar3,0x344e,4,4);
  snd_soc_component_update_bits(lVar3,0x3409,1,1);
  uVar2 = 2;
  if ((uVar1 != 1) && (uVar1 != 6)) {
    if (uVar1 != 4) goto LAB_0010555c;
    uVar2 = 6;
  }
  snd_soc_component_update_bits(lVar3,0x3133,0xf,uVar2);
LAB_0010555c:
  if (*(char *)(lVar4 + 0xcc) != '\0') {
    snd_soc_component_update_bits(lVar3,0x3414,2,2);
  }
  usleep_range_state(5000,0x1392,2);
  snd_soc_component_update_bits(lVar3,0x30a4,4,0);
  wcd_cls_h_fsm(lVar3,lVar4 + 0x9c,1,1,uVar1);
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_aux_dac_event @ 00105620 size=196
// signature: undefined wcd937x_codec_aux_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_aux_dac_event(long param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar2,0x3408,4,0);
  }
  else if (param_3 == 1) {
    lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    uVar1 = *(undefined4 *)(lVar3 + 200);
    wcd937x_rx_clk_enable(lVar2);
    snd_soc_component_update_bits(lVar2,0x3408,4,4);
    snd_soc_component_update_bits(lVar2,0x3409,4,4);
    snd_soc_component_update_bits(lVar2,0x344f,1,1);
    wcd_cls_h_fsm(lVar2,lVar3 + 0x9c,1,8,uVar1);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_enable_rx1 @ 001056e8 size=600
// signature: undefined wcd937x_enable_rx1(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_enable_rx1(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x28);
  lVar2 = lVar3 + -0xd0;
  lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
  if (param_3 == 8) {
    local_3c[0] = 0;
    local_44[0] = 0;
    local_4c[0] = 0;
    iVar1 = wcd937x_set_port_params(lVar2,0xe,local_3c,local_40,local_44,&local_48,local_4c,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_4c);
    }
    if (*(char *)(lVar4 + 0xcc) != '\0') {
      lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_44[0] = 0;
      local_4c[0] = 0;
      iVar1 = wcd937x_set_port_params(lVar2,0x10,local_3c,local_40,local_44,&local_48,local_4c,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_4c);
      }
    }
    lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    iVar1 = *(int *)(lVar3 + 0x100);
    if ((iVar1 != 0) && (iVar1 = iVar1 + -1, *(int *)(lVar3 + 0x100) = iVar1, iVar1 == 0)) {
      snd_soc_component_update_bits(lVar2,0x3008,1,0);
      snd_soc_component_update_bits(lVar2,0x3408,2,0);
      snd_soc_component_update_bits(lVar2,0x3408,1,0);
    }
    snd_soc_component_update_bits(lVar2,0x3409,1,0);
  }
  else if (param_3 == 1) {
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48 = 0;
    local_4c[0] = 0;
    iVar1 = wcd937x_set_port_params(lVar2,0xe,local_3c,local_40,local_44,&local_48,local_4c,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_48,local_40,local_4c
                      );
    }
    if (*(char *)(lVar4 + 0xcc) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_40[0] = 0;
      local_44[0] = 0;
      local_48 = 0;
      local_4c[0] = 0;
      iVar1 = wcd937x_set_port_params(lVar2,0x10,local_3c,local_40,local_44,&local_48,local_4c,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,&local_48,local_40,
                         local_4c);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_enable_rx2 @ 00105944 size=600
// signature: undefined wcd937x_enable_rx2(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_enable_rx2(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x28);
  lVar2 = lVar3 + -0xd0;
  lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
  if (param_3 == 8) {
    local_3c[0] = 0;
    local_44[0] = 0;
    local_4c[0] = 0;
    iVar1 = wcd937x_set_port_params(lVar2,0xf,local_3c,local_40,local_44,&local_48,local_4c,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_4c);
    }
    if (*(char *)(lVar4 + 0xcd) != '\0') {
      lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_44[0] = 0;
      local_4c[0] = 0;
      iVar1 = wcd937x_set_port_params(lVar2,0x11,local_3c,local_40,local_44,&local_48,local_4c,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_4c);
      }
    }
    lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    iVar1 = *(int *)(lVar3 + 0x100);
    if ((iVar1 != 0) && (iVar1 = iVar1 + -1, *(int *)(lVar3 + 0x100) = iVar1, iVar1 == 0)) {
      snd_soc_component_update_bits(lVar2,0x3008,1,0);
      snd_soc_component_update_bits(lVar2,0x3408,2,0);
      snd_soc_component_update_bits(lVar2,0x3408,1,0);
    }
    snd_soc_component_update_bits(lVar2,0x3409,2,0);
  }
  else if (param_3 == 1) {
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48 = 0;
    local_4c[0] = 0;
    iVar1 = wcd937x_set_port_params(lVar2,0xf,local_3c,local_40,local_44,&local_48,local_4c,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_48,local_40,local_4c
                      );
    }
    if (*(char *)(lVar4 + 0xcd) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_40[0] = 0;
      local_44[0] = 0;
      local_48 = 0;
      local_4c[0] = 0;
      iVar1 = wcd937x_set_port_params(lVar2,0x11,local_3c,local_40,local_44,&local_48,local_4c,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,&local_48,local_40,
                         local_4c);
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_enable_rx3 @ 00105ba0 size=424
// signature: undefined wcd937x_enable_rx3(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_enable_rx3(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar3 = *(long *)(param_1 + 0x28);
  lVar2 = lVar3 + -0xd0;
  if (param_3 == 8) {
    lVar4 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    local_3c[0] = 0;
    local_44[0] = 0;
    local_4c[0] = 0;
    iVar1 = wcd937x_set_port_params(lVar2,0x13,local_3c,local_40,local_44,&local_48,local_4c,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_4c);
    }
    usleep_range_state(6000,0x177a,2);
    lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    iVar1 = *(int *)(lVar3 + 0x100);
    if ((iVar1 != 0) && (iVar1 = iVar1 + -1, *(int *)(lVar3 + 0x100) = iVar1, iVar1 == 0)) {
      snd_soc_component_update_bits(lVar2,0x3008,1,0);
      snd_soc_component_update_bits(lVar2,0x3408,2,0);
      snd_soc_component_update_bits(lVar2,0x3408,1,0);
    }
    snd_soc_component_update_bits(lVar2,0x3409,4,0);
  }
  else if (param_3 == 1) {
    lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48 = 0;
    local_4c[0] = 0;
    iVar1 = wcd937x_set_port_params(lVar2,0x13,local_3c,local_40,local_44,&local_48,local_4c,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,&local_48,local_40,local_4c
                      );
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_enable_micbias_pullup @ 00105d4c size=224
// signature: undefined wcd937x_codec_enable_micbias_pullup(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_codec_enable_micbias_pullup(long param_1,undefined8 param_2,int param_3)

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
  wcd937x_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd937x_tx_connect_port @ 00105e2c size=280
// signature: undefined wcd937x_tx_connect_port(void)
// callers: [wcd937x_codec_enable_adc, wcd937x_tx_swr_ctrl, wcd937x_codec_enable_dmic]
//------------------------------------------------------------

void wcd937x_tx_connect_port(long param_1,undefined8 param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 local_4c [4];
  undefined4 local_48;
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
  local_48 = 0;
  local_4c[0] = 0;
  iVar2 = wcd937x_set_port_params(param_1,param_2,local_3c,local_40,local_44,&local_48,local_4c,0);
  if (iVar2 == 0) {
    uVar1 = (int)param_2 - 0x1d;
    if (((uVar1 & 0xff) < 0xb) && ((0x7efU >> (ulong)(uVar1 & 0x1f) & 1) != 0)) {
      local_4c[0] = *(undefined1 *)
                     (lVar4 + (ulong)(byte)wcd937x_swr_slv_tx_ch_idx
                                           [*(long *)(&DAT_00110af8 + (long)(char)uVar1 * 8) * 2 + 1
                                           ] + 0xc58);
    }
    uVar3 = *(undefined8 *)(lVar4 + 0x30);
    if (param_3 == '\0') {
      swr_disconnect_port(uVar3,local_3c,1,local_44,local_4c);
    }
    else {
      swr_connect_port(uVar3,local_3c,1,local_44,&local_48,local_40,local_4c);
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
// wcd937x_set_port_params @ 00105f44 size=424
// signature: undefined wcd937x_set_port_params(void)
// callers: [wcd937x_codec_enable_adc, wcd937x_enable_rx3, wcd937x_tx_connect_port, wcd937x_enable_clsh, wcd937x_enable_rx1, wcd937x_enable_rx2]
//------------------------------------------------------------

undefined8
wcd937x_set_port_params
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
    lVar6 = lVar4 + 0x114;
    pbVar5 = (byte *)(lVar4 + 0x110);
  }
  else {
    if (param_8 != 1) {
      param_2 = (uint)param_8;
      pcVar3 = "%s Invalid path selected %u\n";
      goto LAB_001060dc;
    }
    lVar6 = lVar4 + 0x614;
    pbVar5 = (byte *)(lVar4 + 0x111);
  }
  lVar4 = 0;
  bVar2 = false;
  param_2 = param_2 & 0xff;
  lVar8 = 1;
  uVar7 = 0;
  do {
    if ((int)lVar4 == 0x500) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1060ec);
      (*pcVar1)();
    }
    if (*(uint *)(lVar6 + lVar4) == param_2) {
      lVar8 = 0;
LAB_0010606c:
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
    if (*(uint *)(lVar6 + lVar4 + 0x14) == param_2) goto LAB_0010606c;
    if (*(uint *)(lVar6 + lVar4 + 0x28) == param_2) {
      lVar8 = 2;
      goto LAB_0010606c;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x3c) == param_2) {
      lVar8 = 3;
      goto LAB_0010606c;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x50) == param_2) {
      lVar8 = 4;
      goto LAB_0010606c;
    }
    if (*(uint *)(lVar6 + lVar4 + 100) == param_2) {
      lVar8 = 5;
      goto LAB_0010606c;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x78) == param_2) {
      lVar8 = 6;
      goto LAB_0010606c;
    }
    if (*(uint *)(lVar6 + lVar4 + 0x8c) == param_2) {
      lVar8 = 7;
      goto LAB_0010606c;
    }
    bVar2 = *pbVar5 <= uVar7;
    lVar4 = lVar4 + 0xa0;
    uVar7 = uVar7 + 1;
  } while ((uint)*pbVar5 * 0xa0 + 0xa0 != (int)lVar4);
  pcVar3 = "%s Failed to find slave port for type %u\n";
LAB_001060dc:
  _dev_err(*(long *)(param_1 + 0x18),pcVar3,"wcd937x_set_port_params",param_2);
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd937x_rx_clk_enable @ 001060ec size=200
// signature: undefined wcd937x_rx_clk_enable(void)
// callers: [wcd937x_codec_hphl_dac_event, wcd937x_codec_hphr_dac_event, wcd937x_codec_aux_dac_event, wcd937x_codec_ear_dac_event]
//------------------------------------------------------------

void wcd937x_rx_clk_enable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  iVar1 = *(int *)(lVar2 + 0x100);
  if (iVar1 == 0) {
    snd_soc_component_update_bits(param_1,0x3409,8,8);
    snd_soc_component_update_bits(param_1,0x3408,1,1);
    snd_soc_component_update_bits(param_1,0x3008,1,1);
    snd_soc_component_update_bits(param_1,0x340d,0x40,0);
    snd_soc_component_update_bits(param_1,0x340e,0x40,0);
    snd_soc_component_update_bits(param_1,0x340f,0x40,0);
    snd_soc_component_update_bits(param_1,0x3408,2,2);
    iVar1 = *(int *)(lVar2 + 0x100);
  }
  *(int *)(lVar2 + 0x100) = iVar1 + 1;
  return;
}



//------------------------------------------------------------
// wcd937x_init_reg @ 001061b4 size=580
// signature: undefined wcd937x_init_reg(void)
// callers: [wcd937x_soc_codec_probe, wcd937x_event_notify]
//------------------------------------------------------------

void wcd937x_init_reg(undefined8 param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  
  uVar1 = snd_soc_component_read(param_1,0x34cd);
  uVar1 = uVar1 & 0xf;
  iVar2 = snd_soc_component_read(param_1,0x34c0);
  if ((iVar2 != 2) && (uVar3 = snd_soc_component_read(param_1,0x34c1), uVar3 < 10)) {
    uVar1 = 0xe;
  }
  snd_soc_component_update_bits(param_1,0x3103,0xe,uVar1);
  snd_soc_component_update_bits(param_1,0x3103,0x80,0x80);
  usleep_range_state(1000,0x3f2,2);
  snd_soc_component_update_bits(param_1,0x3103,0x40,0x40);
  usleep_range_state(1000,0x3f2,2);
  snd_soc_component_update_bits(param_1,0x312a,0x10,0);
  snd_soc_component_update_bits(param_1,0x3029,0xf0,0x80);
  snd_soc_component_update_bits(param_1,0x3001,0x80,0x80);
  snd_soc_component_update_bits(param_1,0x3001,0x40,0x40);
  usleep_range_state(10000,0x271a,2);
  snd_soc_component_update_bits(param_1,0x3001,0x40,0);
  snd_soc_component_update_bits(param_1,0x30e2,0xff,0xd9);
  snd_soc_component_update_bits(param_1,0x306b,0xff,0xfa);
  snd_soc_component_update_bits(param_1,0x306e,0xff,0xfa);
  snd_soc_component_update_bits(param_1,0x3071,0xff,0xfa);
  snd_soc_component_update_bits(param_1,0x306c,0x38,0);
  snd_soc_component_update_bits(param_1,0x306f,0x38,0);
  snd_soc_component_update_bits(param_1,0x3072,0x38,0);
  iVar2 = snd_soc_component_read(param_1,0x34c0);
  if (iVar2 == 1) {
    uVar4 = 0x3029;
    uVar5 = 0xb0;
  }
  else {
    iVar2 = snd_soc_component_read(param_1,0x34c0);
    if (iVar2 != 2) {
      return;
    }
    snd_soc_component_update_bits(param_1,0x3133,0x1f,4);
    snd_soc_component_update_bits(param_1,0x3136,0x1f,4);
    snd_soc_component_update_bits(param_1,0x3029,0xf0,0xb0);
    uVar4 = 0x3132;
    uVar5 = 0x50;
  }
  snd_soc_component_update_bits(param_1,uVar4,0xf0,uVar5);
  return;
}



//------------------------------------------------------------
// wcd937x_event_notify @ 001063fc size=600
// signature: undefined wcd937x_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_event_notify(undefined8 param_1,undefined8 param_2,long param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined1 uVar6;
  undefined4 uVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  
  plVar10 = *(long **)(param_3 + 0x98);
  lVar8 = plVar10[2];
  uVar2 = (uint)((ulong)param_2 >> 0x10);
  switch((uint)param_2 & 0xffff) {
  case 1:
    uVar2 = uVar2 & 0xffff;
    if (uVar2 - 1 < 2) {
      uVar4 = 0x300f;
    }
    else {
      if (uVar2 != 3) {
        return 0;
      }
      uVar4 = 0x3011;
    }
    uVar7 = 0x20;
    if (uVar2 != 2) {
      uVar7 = 0x40;
    }
    goto LAB_001065d0;
  case 2:
    snd_soc_component_update_bits(lVar8,0x3009,0xc0,0);
    snd_soc_component_update_bits(lVar8,0x300a,0x80,0);
    uVar4 = 0x3128;
    uVar7 = 0x80;
LAB_001065d0:
    iVar3 = 0;
LAB_001065d4:
    snd_soc_component_update_bits(lVar8,uVar4,uVar7,iVar3);
    break;
  case 3:
    *(undefined1 *)(plVar10[0x18] + 0x3d0) = 1;
    if ((*(int *)(*(long *)(plVar10[0x18] + 0x90) + 0x58) == 0) ||
       (uVar2 = snd_soc_component_read(lVar8,0x3014), (uVar2 >> 5 & 1) != 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    *(undefined1 *)((long)plVar10 + 0xc62) = uVar6;
    wcd937x_mbhc_ssr_down(plVar10[0x18],lVar8);
    lVar8 = *plVar10;
    if ((lVar8 != 0) && (*(long *)(lVar8 + 0x98) != 0)) {
      if (*(long *)(*(long *)(lVar8 + 0x98) + 0x18) == 0) {
        pcVar5 = "%s: reset gpio device node not specified\n";
      }
      else {
        iVar3 = msm_cdc_pinctrl_select_sleep_state();
        if (iVar3 == 0) {
          usleep_range_state(0x14,0x1e,2);
          return 0;
        }
        pcVar5 = "%s: wcd sleep state request fail!\n";
      }
      _dev_err(lVar8,pcVar5,"wcd937x_reset_low");
    }
    break;
  case 4:
    wcd937x_reset(*plVar10);
    usleep_range_state(10000,0x271a,2);
    wcd937x_get_logical_addr(plVar10[6]);
    wcd937x_get_logical_addr(plVar10[5]);
    wcd937x_init_reg(lVar8);
    regcache_mark_dirty(plVar10[4]);
    regcache_sync(plVar10[4]);
    lVar9 = plVar10[0x18];
    iVar3 = wcd937x_mbhc_post_ssr_init(lVar9,lVar8);
    if (iVar3 == 0) {
      wcd937x_mbhc_hs_detect(lVar8,*(undefined8 *)(lVar9 + 0x90));
      if (*(char *)((long)plVar10 + 0xc62) != '\0') {
        lVar8 = -500;
        do {
          __const_udelay(0x418958);
          bVar1 = lVar8 != -1;
          lVar8 = lVar8 + 1;
        } while (bVar1);
      }
    }
    else {
      _dev_err(*(undefined8 *)(lVar8 + 0x18),"%s: mbhc initialization failed\n",
               "wcd937x_event_notify");
    }
    *(undefined1 *)(plVar10[0x18] + 0x3d0) = 0;
    break;
  default:
    _dev_err(*(undefined8 *)(lVar8 + 0x18),"%s: invalid event %d\n","wcd937x_event_notify",
             (uint)param_2 & 0xffff);
    break;
  case 7:
    iVar3 = uVar2 << 1;
    uVar4 = 0x3407;
    uVar7 = 6;
    goto LAB_001065d4;
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_codec_enable_dmic @ 00106658 size=392
// signature: undefined wcd937x_codec_enable_dmic(void)
// callers: []
//------------------------------------------------------------

void wcd937x_codec_enable_dmic(long param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  uint local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar7 = *(long *)(param_1 + 0x28);
  local_4c = 0;
  lVar5 = *(long *)(lVar7 + -0xb8);
  lVar6 = *(long *)(lVar5 + 0x98);
  pcVar3 = strpbrk(*(char **)(param_1 + 8),"012345");
  if (pcVar3 == (char *)0x0) {
    pcVar3 = "%s: widget not found\n";
  }
  else {
    iVar2 = kstrtouint(pcVar3,10,&local_4c);
    if (iVar2 < 0) {
      lVar5 = *(long *)(lVar7 + -0xb8);
      pcVar3 = "%s: Invalid DMIC line on the codec\n";
    }
    else {
      if (local_4c < 6) {
        lVar7 = lVar7 + -0xd0;
        if (param_3 == 8) {
          wcd937x_tx_connect_port(lVar7,*(byte *)(param_1 + 0x4c) + 0x22,0);
        }
        else if (param_3 == 1) {
          uVar1 = *(undefined4 *)(&DAT_00110b50 + (long)(int)local_4c * 4);
          snd_soc_component_update_bits(lVar7,0x3409,0x80,0x80);
          snd_soc_component_update_bits(lVar7,uVar1,7,2);
          snd_soc_component_update_bits(lVar7,uVar1,8,8);
          snd_soc_component_update_bits(lVar7,uVar1,0x70,0x20);
          lVar5 = *(long *)(lVar6 + 0x30);
          swr_slvdev_datapath_control(lVar5,*(undefined1 *)(lVar5 + 0x40),1);
        }
        uVar4 = 0;
        goto LAB_00106764;
      }
      lVar5 = *(long *)(lVar7 + -0xb8);
      pcVar3 = "%s: Invalid DMIC Selection\n";
    }
  }
  _dev_err(lVar5,pcVar3,"wcd937x_codec_enable_dmic");
  uVar4 = 0xffffffea;
LAB_00106764:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_get_logical_addr @ 001067e0 size=440
// signature: undefined wcd937x_get_logical_addr(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

void wcd937x_get_logical_addr(long param_1)

{
  long lVar1;
  int iVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
  if (iVar2 != 0) {
    _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %lx failed\n","wcd937x_get_logical_addr",
             local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
    usleep_range_state(1000,0x3f2,2);
    iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
    if (iVar2 != 0) {
      _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %lx failed\n",
               "wcd937x_get_logical_addr",local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
      usleep_range_state(1000,0x3f2,2);
      iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
      if (iVar2 != 0) {
        _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %lx failed\n",
                 "wcd937x_get_logical_addr",local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
        usleep_range_state(1000,0x3f2,2);
        iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
        if (iVar2 != 0) {
          _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %lx failed\n",
                   "wcd937x_get_logical_addr",local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
          usleep_range_state(1000,0x3f2,2);
          iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
          if (iVar2 != 0) {
            _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %lx failed\n",
                     "wcd937x_get_logical_addr",local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
            usleep_range_state(1000,0x3f2,2);
          }
        }
      }
    }
  }
  *(undefined1 *)(param_1 + 0x40) = local_2c[0];
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd937x_suspend @ 0010699c size=208
// signature: undefined wcd937x_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  
  if (param_1 == 0) {
    uVar5 = 0xffffffed;
  }
  else {
    plVar7 = *(long **)(param_1 + 0x98);
    if (plVar7 != (long *)0x0) {
      lVar6 = *(long *)(*plVar7 + 0x90);
      if (lVar6 != 0) {
        if ((plVar7[0x21] & 1U) != 0) {
          iVar4 = msm_cdc_disable_ondemand_supply
                            (*plVar7,plVar7[0x177],*(undefined8 *)(lVar6 + 0x30),
                             *(undefined4 *)(lVar6 + 0x38),"cdc-vdd-buck");
          if (iVar4 == -0x16) {
            _dev_err(param_1,"%s: vdd buck is not disabled\n","wcd937x_suspend");
          }
          else {
            puVar1 = (ulong *)(plVar7 + 0x21);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = *puVar1 & 0xfffffffffffffffe;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
          }
        }
        return 0;
      }
      _dev_err(param_1,"%s: pdata is NULL\n","wcd937x_suspend");
    }
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// wcd937x_resume @ 00106a7c size=8
// signature: undefined wcd937x_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_resume(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd937x_writeable_register @ 00106a88 size=52
// signature: undefined wcd937x_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd937x_writeable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x34c < uVar1 >> 4) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106abc);
    (*pcVar2)();
  }
  return (byte)(&wcd937x_reg_access)[uVar1] >> 1 & 1;
}



//------------------------------------------------------------
// wcd937x_readable_register @ 00106ac0 size=52
// signature: undefined wcd937x_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd937x_readable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x34c < uVar1 >> 4) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106af4);
    (*pcVar2)();
  }
  return (&wcd937x_reg_access)[uVar1] & 1;
}



//------------------------------------------------------------
// wcd937x_volatile_register @ 00106af8 size=60
// signature: undefined wcd937x_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wcd937x_volatile_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return false;
  }
  if (0x34c < uVar1 >> 4) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106b34);
    (*pcVar2)();
  }
  return ((&wcd937x_reg_access)[uVar1] & 3) == 1;
}



//------------------------------------------------------------
// wcd937x_mbhc_get_impedance @ 00106b38 size=80
// signature: undefined wcd937x_mbhc_get_impedance(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_mbhc_get_impedance(long param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    puVar2 = &DAT_00113593;
  }
  else {
    if ((param_2 != 0) && (param_3 != 0)) {
      uVar1 = wcd_mbhc_get_impedance();
      return uVar1;
    }
    puVar2 = &DAT_0011261d;
  }
  _printk(puVar2,"wcd937x_mbhc_get_impedance");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd937x_mbhc_hs_detect @ 00106b8c size=124
// signature: undefined wcd937x_mbhc_hs_detect(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

undefined8 wcd937x_mbhc_hs_detect(long param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    puVar2 = &DAT_001130b6;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      lVar3 = *(long *)(lVar3 + 0xc0);
      if (lVar3 == 0) {
        _dev_err(*(long *)(param_1 + 0x18),"%s: mbhc not initialized!\n","wcd937x_mbhc_hs_detect");
        return 0xffffffea;
      }
      uVar1 = wcd_mbhc_start(lVar3);
      return uVar1;
    }
    puVar2 = &DAT_0011204a;
  }
  _printk(puVar2,"wcd937x_mbhc_hs_detect");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd937x_mbhc_hs_detect_exit @ 00106c0c size=116
// signature: undefined wcd937x_mbhc_hs_detect_exit(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_hs_detect_exit(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_001130b6;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      lVar2 = *(long *)(lVar2 + 0xc0);
      if (lVar2 == 0) {
        _dev_err(*(long *)(param_1 + 0x18),"%s: mbhc not initialized!\n",
                 "wcd937x_mbhc_hs_detect_exit");
        return;
      }
      wcd_mbhc_stop(lVar2);
      return;
    }
    puVar1 = &DAT_0011204a;
  }
  _printk(puVar1,"wcd937x_mbhc_hs_detect_exit");
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_ssr_down @ 00106c84 size=128
// signature: undefined wcd937x_mbhc_ssr_down(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

void wcd937x_mbhc_ssr_down(long param_1,long param_2)

{
  long lVar1;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar1 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (lVar1 == 0) {
      _printk(&DAT_0011204a,"wcd937x_mbhc_hs_detect_exit");
    }
    else {
      lVar1 = *(long *)(lVar1 + 0xc0);
      if (lVar1 == 0) {
        _dev_err(*(long *)(param_2 + 0x18),"%s: mbhc not initialized!\n",
                 "wcd937x_mbhc_hs_detect_exit");
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
// wcd937x_mbhc_post_ssr_init @ 00106d08 size=160
// signature: undefined wcd937x_mbhc_post_ssr_init(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

int wcd937x_mbhc_post_ssr_init(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = -0x16;
  if ((param_1 != 0) && (param_2 != 0)) {
    snd_soc_component_update_bits(param_2,0x3014,0x20,0x20);
    iVar1 = wcd_mbhc_init(param_1,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
               "wcd937x_mbhc_post_ssr_init");
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd937x_mbhc_init @ 00106dac size=340
// signature: undefined wcd937x_mbhc_init(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

int wcd937x_mbhc_init(long *param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (param_2 == 0) {
    _printk(&DAT_001130b6,"wcd937x_mbhc_init");
    iVar1 = -0x16;
  }
  else {
    lVar2 = devm_kmalloc(*(undefined8 *)(param_2 + 0x18),0x478,0xdc0);
    if (lVar2 == 0) {
      iVar1 = -0xc;
    }
    else {
      *(undefined8 *)(lVar2 + 0x470) = param_3;
      __init_rwsem(lVar2 + 0x428,"&(&wcd937x_mbhc->notifier)->rwsem",&wcd937x_mbhc_init___key);
      lVar3 = *(long *)(param_2 + 0x18);
      *(undefined8 *)(lVar2 + 0x468) = 0;
      *(undefined4 *)(lVar2 + 0x3d4) = 1;
      lVar4 = *(long *)(lVar3 + 0x90);
      if (lVar4 == 0) {
        _dev_err(lVar3,"%s: pdata pointer is NULL\n","wcd937x_mbhc_init");
        iVar1 = -0x16;
      }
      else {
        *(undefined4 *)(lVar2 + 0xd0) = *(undefined4 *)(lVar4 + 0x24);
        iVar1 = wcd_mbhc_init(lVar2,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
        if (iVar1 == 0) {
          *param_1 = lVar2;
          snd_soc_add_component_controls(param_2,impedance_detect_controls,2);
          snd_soc_add_component_controls(param_2,hph_type_detect_controls,1);
          return 0;
        }
        _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
                 "wcd937x_mbhc_init");
      }
      devm_kfree(*(undefined8 *)(param_2 + 0x18),lVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd937x_mbhc_deinit @ 00106f04 size=116
// signature: undefined wcd937x_mbhc_deinit(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_deinit(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_001130b6;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      lVar2 = *(long *)(lVar2 + 0xc0);
      if (lVar2 == 0) {
        return;
      }
      wcd_mbhc_deinit(lVar2);
      devm_kfree(*(undefined8 *)(param_1 + 0x18),lVar2);
      return;
    }
    puVar1 = &DAT_0011204a;
  }
  _printk(puVar1,"wcd937x_mbhc_deinit");
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_bcs_enable @ 00106f7c size=40
// signature: undefined wcd937x_mbhc_bcs_enable(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_bcs_enable(long param_1,uint param_2)

{
  wcd937x_disable_bcs_before_slow_insert(*(undefined8 *)(param_1 + 0xf8),(param_2 ^ 0xffffffff) & 1)
  ;
  return;
}



//------------------------------------------------------------
// wcd937x_wcd_mbhc_calc_impedance @ 00106fa8 size=1884
// signature: undefined wcd937x_wcd_mbhc_calc_impedance(void)
// callers: []
//------------------------------------------------------------

void wcd937x_wcd_mbhc_calc_impedance(long param_1,uint *param_2,uint *param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  uint uVar11;
  uint uVar12;
  ulong uVar13;
  undefined *puVar14;
  undefined4 uVar15;
  int iVar16;
  long lVar17;
  undefined1 *puVar18;
  undefined1 *puVar19;
  long lVar20;
  undefined *puVar21;
  long lVar22;
  uint local_74;
  undefined8 local_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  lVar17 = *(long *)(param_1 + 0xf8);
  local_70 = 0;
  local_74 = 0;
  lVar22 = *(long *)(*(long *)(lVar17 + 0x18) + 0x98);
  uVar13 = mutex_is_locked(param_1 + 0x328);
  if (((uVar13 & 1) == 0) && ((wcd937x_wcd_mbhc_calc_impedance___already_done & 1) == 0)) {
    wcd937x_wcd_mbhc_calc_impedance___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd937x_wcd_mbhc_calc_impedance");
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1076fc);
    (*pcVar4)();
  }
  sVar6 = snd_soc_component_read(lVar17,0x301f);
  sVar7 = snd_soc_component_read(lVar17,0x3020);
  sVar8 = snd_soc_component_read(lVar17,0x3021);
  sVar9 = snd_soc_component_read(lVar17,0x3056);
  sVar10 = snd_soc_component_read(lVar17,0x3123);
  uVar11 = snd_soc_component_read(lVar17,0x3015);
  if ((uVar11 >> 7 & 1) != 0) {
    regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x3015,0x80,0,0,0,0);
  }
  if (*(char *)(param_1 + 0xc3) != '\0') {
    regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x3014,0x80,0,0,0,0);
  }
  regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x3014,1,0,0,0,0);
  regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x30e2,0xc0,0,0,0,0);
  usleep_range_state(1000,0x3f2,2);
  puVar21 = &DAT_00111f94;
  puVar18 = &DAT_00114ba0;
  wcd937x_mbhc_zdet_ramp(lVar17,&DAT_00111f94,(long)&local_70 + 4,0,&DAT_00114ba0);
  if (local_70._4_4_ - 0x61a81U < 0xfffa627f) {
    bVar5 = 0xc34 < local_70._4_4_ - 0x61a81U >> 8;
    lVar1 = 0x18;
    if (bVar5) {
      lVar1 = 0x24;
    }
    puVar14 = &DAT_00111fa0;
    if (bVar5) {
      puVar14 = &DAT_00111fac;
    }
    puVar19 = &DAT_00114ba8;
    if (bVar5) {
      puVar19 = &DAT_00114bb0;
    }
    puVar21 = &DAT_00111f88;
    if (31999 < local_70._4_4_) {
      puVar21 = puVar14;
    }
    puVar18 = &_L__const_wcd937x_wcd_mbhc_calc_impedance_d1_a;
    if (31999 < local_70._4_4_) {
      puVar18 = puVar19;
    }
    lVar20 = 0;
    if (31999 < local_70._4_4_) {
      lVar20 = lVar1;
    }
    wcd937x_mbhc_zdet_ramp(lVar17,puVar21,(long)&local_70 + 4,0,puVar18);
    if (local_70._4_4_ < 0x5f5e101) goto LAB_00107204;
    puVar21 = &DAT_00111f94;
    puVar18 = &DAT_00114ba0;
    uVar12 = 0xffffffe;
    lVar20 = 0xc;
LAB_00107280:
    *param_2 = uVar12;
  }
  else {
    lVar20 = 0xc;
LAB_00107204:
    uVar15 = 0x34c7;
    if (399999 < local_70._4_4_) {
      uVar15 = 0x34c8;
    }
    *param_2 = local_70._4_4_ / 1000;
    uVar12 = snd_soc_component_read(lVar17,uVar15);
    if ((uVar12 >> 7 & 1) != 0) {
      uVar12 = uVar12 & 0x7f;
      iVar16 = -0x19;
LAB_00107268:
      iVar16 = uVar12 * iVar16 + 10000;
      uVar12 = 0;
      if (iVar16 != 0) {
        uVar12 = (int)(*param_2 * 10000) / iVar16;
      }
      goto LAB_00107280;
    }
    if (-0x1900000 < (int)(uVar12 * 0x10000)) {
      uVar12 = (uint)(short)uVar12;
      iVar16 = 0x19;
      goto LAB_00107268;
    }
  }
  wcd937x_mbhc_zdet_ramp(lVar17,puVar21,0,&local_70,puVar18);
  if ((int)local_70 - 0x61a81U < 0xfffa627f) {
    if ((int)local_70 < 0x124f81) {
LAB_001072dc:
      if (*param_2 == 0xffffffe) {
        if ((int)local_70 < 32000) {
          puVar19 = &_L__const_wcd937x_wcd_mbhc_calc_impedance_d1_a;
          puVar14 = &DAT_00111f88;
        }
        else {
          bVar5 = 0xc34 < (int)local_70 - 0x61a81U >> 8;
          puVar14 = &DAT_00111fa0;
          if (bVar5) {
            puVar14 = puVar21;
          }
          puVar19 = &DAT_00114ba8;
          if (bVar5) {
            puVar19 = puVar18;
          }
          if (1200000 < (int)local_70) {
            puVar19 = &DAT_00114bb0;
            puVar14 = &DAT_00111fac;
          }
        }
        wcd937x_mbhc_zdet_ramp(lVar17,puVar14,0,&local_70,puVar19);
        puVar18 = puVar19;
      }
    }
    else {
      if (lVar20 - 0x2dU < 0xffffffffffffffd1) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x107708);
        (*pcVar4)();
      }
      if (*(short *)(puVar21 + 2) != 6) goto LAB_001072dc;
    }
    iVar16 = (int)local_70;
    if ((int)local_70 < 0x5f5e101) goto LAB_00107398;
    uVar12 = 0xffffffe;
LAB_00107410:
    *param_3 = uVar12;
  }
  else {
    iVar16 = (int)local_70;
LAB_00107398:
    uVar15 = 0x34c9;
    if (399999 < iVar16) {
      uVar15 = 0x34ca;
    }
    *param_3 = iVar16 / 1000;
    uVar12 = snd_soc_component_read(lVar17,uVar15);
    if ((uVar12 >> 7 & 1) != 0) {
      uVar12 = uVar12 & 0x7f;
      iVar16 = -0x19;
LAB_001073f4:
      iVar16 = uVar12 * iVar16 + 10000;
      uVar12 = 0;
      if (iVar16 != 0) {
        uVar12 = (int)(*param_3 * 10000) / iVar16;
      }
      goto LAB_00107410;
    }
    if (-0x1900000 < (int)(uVar12 * 0x10000)) {
      uVar12 = (uint)(short)uVar12;
      iVar16 = 0x19;
      goto LAB_001073f4;
    }
  }
  uVar12 = *param_2;
  uVar2 = *param_3;
  if (uVar12 == 0xffffffe) {
    if (uVar2 == 0xffffffe) goto LAB_00107464;
  }
  else if (((uVar2 != 0xffffffe) && ((1 < uVar12 || (uVar2 < 3)))) && ((uVar12 < 3 || (1 < uVar2))))
  {
    snd_soc_component_update_bits(lVar17,0x30d8,2,2);
    snd_soc_component_update_bits(lVar17,0x30d2,0x40,1);
    puVar21 = &DAT_00111f88;
    if (0x1f < *param_2) {
      puVar21 = &DAT_00111f94;
    }
    wcd937x_mbhc_zdet_ramp(lVar17,puVar21,&local_74,0,puVar18);
    snd_soc_component_update_bits(lVar17,0x30d2,0x40,0);
    snd_soc_component_update_bits(lVar17,0x30d8,2,0);
    uVar15 = 0x34c7;
    if (399999 < (int)local_74) {
      uVar15 = 0x34c8;
    }
    local_74 = (int)local_74 / 1000;
    uVar12 = snd_soc_component_read(lVar17,uVar15);
    if ((uVar12 >> 7 & 1) == 0) {
      if (-0x1900000 < (int)(uVar12 * 0x10000)) {
        uVar12 = (uint)(short)uVar12;
        iVar16 = 0x19;
        goto LAB_0010764c;
      }
    }
    else {
      uVar12 = uVar12 & 0x7f;
      iVar16 = -0x19;
LAB_0010764c:
      iVar16 = uVar12 * iVar16 + 10000;
      iVar3 = local_74 * 10000;
      local_74 = 0;
      if (iVar16 != 0) {
        local_74 = iVar3 / iVar16;
      }
    }
    uVar12 = *param_2;
    uVar2 = 0;
    if (uVar12 + 9 != 0) {
      uVar2 = (uVar12 * 9) / (uVar12 + 9);
    }
    iVar16 = local_74 - uVar2;
    if (local_74 - uVar2 == 0 || (int)local_74 < (int)uVar2) {
      iVar16 = uVar2 - local_74;
    }
    iVar3 = uVar12 - local_74;
    if (uVar12 < local_74 || uVar12 - local_74 == 0) {
      iVar3 = local_74 - uVar12;
    }
    uVar15 = 1;
    if (iVar3 * (local_74 + uVar2) < iVar16 * (local_74 + uVar12)) {
      uVar15 = 2;
    }
    *(undefined4 *)(param_1 + 0x1c4) = uVar15;
    regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x30e2,0xc0,0xc0,0,0,0);
    goto LAB_00107464;
  }
  *(undefined4 *)(param_1 + 0x1c4) = 1;
LAB_00107464:
  snd_soc_component_write(lVar17,0x301f,(int)sVar6);
  snd_soc_component_write(lVar17,0x3020,(int)sVar7);
  snd_soc_component_write(lVar17,0x3021,(int)sVar8);
  regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x3014,1,1,0,0,0);
  if (*(char *)(param_1 + 0xc3) != '\0') {
    regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x3014,0x80,0x80,0,0,0);
  }
  snd_soc_component_write(lVar17,0x3123,(int)sVar10);
  snd_soc_component_write(lVar17,0x3056,(int)sVar9);
  if ((uVar11 >> 7 & 1) != 0) {
    regmap_update_bits_base(*(undefined8 *)(lVar22 + 0x20),0x3015,0x80,0x80,0,0,0);
  }
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd937x_get_hwdep_fw_cal @ 0010770c size=116
// signature: undefined wcd937x_get_hwdep_fw_cal(void)
// callers: []
//------------------------------------------------------------

long wcd937x_get_hwdep_fw_cal(long param_1,undefined4 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xf8);
  if (lVar2 == 0) {
    _printk(&DAT_00112741,"wcd937x_get_hwdep_fw_cal");
  }
  else {
    lVar1 = wcdcal_get_fw_cal(*(undefined8 *)(param_1 + 0x470));
    if (lVar1 != 0) {
      return lVar1;
    }
    _dev_err(*(undefined8 *)(lVar2 + 0x18),"%s: cal not sent by %d\n","wcd937x_get_hwdep_fw_cal",
             param_2);
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_mbhc_register_notifier @ 00107784 size=44
// signature: undefined wcd937x_mbhc_register_notifier(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_register_notifier(long param_1,undefined8 param_2,uint param_3)

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
// wcd937x_mbhc_request_irq @ 001077b4 size=52
// signature: undefined wcd937x_mbhc_request_irq(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_request_irq(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  wcd_request_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0xd8,param_2,param_4,param_3);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_irq_control @ 001077ec size=52
// signature: undefined wcd937x_mbhc_irq_control(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_irq_control(long param_1,undefined8 param_2,uint param_3)

{
  if ((param_3 & 1) == 0) {
    wcd_disable_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0xd8);
  }
  else {
    wcd_enable_irq();
  }
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_free_irq @ 00107824 size=44
// signature: undefined wcd937x_mbhc_free_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_mbhc_free_irq(long param_1)

{
  wcd_free_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0xd8);
  return 0;
}



//------------------------------------------------------------
// wcd937x_mbhc_clk_setup @ 00107854 size=48
// signature: undefined wcd937x_mbhc_clk_setup(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_clk_setup(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x80;
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
  }
  snd_soc_component_update_bits(param_1,0x3120,0x80,uVar1);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_btn_to_num @ 00107888 size=36
// signature: undefined wcd937x_mbhc_btn_to_num(void)
// callers: []
//------------------------------------------------------------

uint wcd937x_mbhc_btn_to_num(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x3019);
  return uVar1 & 7;
}



//------------------------------------------------------------
// wcd937x_mbhc_lock_sleep @ 001078b0 size=72
// signature: undefined wcd937x_mbhc_lock_sleep(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_mbhc_lock_sleep(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98) + 0xbf0);
  if (*(int *)(pcVar1 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1078e4);
    (*pcVar1)();
  }
  (*pcVar1)();
  return 1;
}



//------------------------------------------------------------
// wcd937x_mbhc_micb_en_status @ 001078fc size=68
// signature: undefined wcd937x_mbhc_micb_en_status(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_mbhc_micb_en_status(long param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 2) {
    uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8),0x3023);
    if ((uVar1 & 0xc0) == 0x40) {
      return 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd937x_mbhc_mbhc_bias_control @ 00107944 size=40
// signature: undefined wcd937x_mbhc_mbhc_bias_control(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_mbhc_bias_control(undefined8 param_1,uint param_2)

{
  snd_soc_component_update_bits(param_1,0x3015,1,param_2 & 1);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_hph_pa_on_status @ 00107970 size=40
// signature: undefined wcd937x_mbhc_hph_pa_on_status(void)
// callers: []
//------------------------------------------------------------

bool wcd937x_mbhc_hph_pa_on_status(undefined8 param_1)

{
  ulong uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x3009);
  return (uVar1 & 0xc0) != 0;
}



//------------------------------------------------------------
// wcd937x_mbhc_program_btn_thr @ 0010799c size=516
// signature: undefined wcd937x_mbhc_program_btn_thr(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_program_btn_thr(long param_1,undefined8 param_2,short *param_3,int param_4)

{
  if (param_4 < 9) {
    if (((((0 < param_4) &&
          (snd_soc_component_update_bits
                     (param_1,0x301a,0xfc,
                      ((uint)((ulong)((long)((int)*param_3 << 1) * 0x51eb851f) >> 0x23) -
                      (((int)*param_3 << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 1)) &&
         (snd_soc_component_update_bits
                    (param_1,0x301b,0xfc,
                     ((uint)((ulong)((long)((int)param_3[1] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[1] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 2)) &&
        ((snd_soc_component_update_bits
                    (param_1,0x301c,0xfc,
                     ((uint)((ulong)((long)((int)param_3[2] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[2] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 3 &&
         (snd_soc_component_update_bits
                    (param_1,0x301d,0xfc,
                     ((uint)((ulong)((long)((int)param_3[3] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[3] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 4)))) &&
       ((snd_soc_component_update_bits
                   (param_1,0x301e,0xfc,
                    ((uint)((ulong)((long)((int)param_3[4] << 1) * 0x51eb851f) >> 0x23) -
                    (((int)param_3[4] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 5 &&
        ((snd_soc_component_update_bits
                    (param_1,0x301f,0xfc,
                     ((uint)((ulong)((long)((int)param_3[5] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[5] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 6 &&
         (snd_soc_component_update_bits
                    (param_1,0x3020,0xfc,
                     ((uint)((ulong)((long)((int)param_3[6] << 1) * 0x51eb851f) >> 0x23) -
                     (((int)param_3[6] << 1) >> 0x1f)) * 4 & 0xfc), param_4 != 7)))))) {
      snd_soc_component_update_bits
                (param_1,0x3021,0xfc,
                 ((uint)((ulong)((long)((int)param_3[7] << 1) * 0x51eb851f) >> 0x23) -
                 (((int)param_3[7] << 1) >> 0x1f)) * 4 & 0xfc);
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid number of buttons: %d\n",
             "wcd937x_mbhc_program_btn_thr",param_4);
  }
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_request_micbias @ 00107ba4 size=32
// signature: undefined wcd937x_mbhc_request_micbias(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_request_micbias(void)

{
  wcd937x_micbias_control();
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_micb_ramp_control @ 00107bc8 size=112
// signature: undefined wcd937x_mbhc_micb_ramp_control(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_micb_ramp_control(undefined8 param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((param_2 & 1) == 0) {
    snd_soc_component_update_bits(param_1,0x3024,0x80,0);
    uVar1 = 0x1c;
    uVar2 = 0;
  }
  else {
    snd_soc_component_update_bits(param_1,0x3024,0x1c,0xc);
    uVar1 = 0x80;
    uVar2 = 0x80;
  }
  snd_soc_component_update_bits(param_1,0x3024,uVar1,uVar2);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_micb_ctrl_threshold_mic @ 00107c3c size=88
// signature: undefined wcd937x_mbhc_micb_ctrl_threshold_mic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_mbhc_micb_ctrl_threshold_mic(long param_1,int param_2,ulong param_3)

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
      uVar3 = wcd937x_mbhc_micb_adjust_voltage(param_1,uVar1,2);
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
// wcd937x_mbhc_gnd_det_ctrl @ 00107c98 size=112
// signature: undefined wcd937x_mbhc_gnd_det_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_gnd_det_ctrl(undefined8 param_1,ulong param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if ((param_2 & 1) == 0) {
    snd_soc_component_update_bits(param_1,0x3014,0x40,0);
    uVar1 = 2;
    uVar2 = 0;
  }
  else {
    snd_soc_component_update_bits(param_1,0x3014,2,2);
    uVar1 = 0x40;
    uVar2 = 0x40;
  }
  snd_soc_component_update_bits(param_1,0x3014,uVar1,uVar2);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_hph_pull_down_ctrl @ 00107d0c size=88
// signature: undefined wcd937x_mbhc_hph_pull_down_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_hph_pull_down_ctrl(undefined8 param_1,ulong param_2)

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
  snd_soc_component_update_bits(param_1,0x30d2,0x40,uVar2);
  snd_soc_component_update_bits(param_1,0x30d2,0x10,uVar3);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_moisture_config @ 00107d68 size=88
// signature: undefined wcd937x_mbhc_moisture_config(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_moisture_config(long param_1)

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
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x3121,0xc,iVar1);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_hph_l_pull_up_control @ 00107dc4 size=48
// signature: undefined wcd937x_mbhc_hph_l_pull_up_control(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_hph_l_pull_up_control(undefined8 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 8;
  if (param_2 < 0x19) {
    uVar1 = param_2;
  }
  snd_soc_component_update_bits(param_1,0x31b1,0x1f,uVar1);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_get_moisture_status @ 00107df8 size=160
// signature: undefined wcd937x_mbhc_get_moisture_status(void)
// callers: []
//------------------------------------------------------------

bool wcd937x_mbhc_get_moisture_status(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0xf8);
  if (((*(int *)(param_1 + 0xe0) == 0) || (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0)) ||
     (*(char *)(param_1 + 0xc3) == '\0')) {
    snd_soc_component_update_bits(uVar2,0x3121,0xc,0);
  }
  else {
    uVar1 = snd_soc_component_read(uVar2,0x3121);
    if ((uVar1 & 0xc) == 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),0x3121,0xc,*(int *)(param_1 + 0xe0) << 2);
      uVar1 = snd_soc_component_read(uVar2,0x3125);
      return (uVar1 & 0x20) == 0;
    }
  }
  return false;
}



//------------------------------------------------------------
// wcd937x_mbhc_moisture_polling_ctrl @ 00107e9c size=52
// signature: undefined wcd937x_mbhc_moisture_polling_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_moisture_polling_ctrl(long param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 4;
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
  }
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x31b0,4,uVar1);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_moisture_detect_en @ 00107ed4 size=64
// signature: undefined wcd937x_mbhc_moisture_detect_en(void)
// callers: []
//------------------------------------------------------------

void wcd937x_mbhc_moisture_detect_en(long param_1,ulong param_2)

{
  int iVar1;
  
  if ((param_2 & 1) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0xe0) << 2;
  }
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x3121,0xc,iVar1);
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_zdet_ramp @ 00107f14 size=436
// signature: undefined wcd937x_mbhc_zdet_ramp(void)
// callers: [wcd937x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

void wcd937x_mbhc_zdet_ramp
               (long param_1,ushort *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined8 param_5)

{
  long lVar1;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  snd_soc_component_update_bits(param_1,0x3123,0x70,(ulong)*param_2 << 4);
  snd_soc_component_update_bits(param_1,0x301f,0xfc,param_2[3]);
  snd_soc_component_update_bits(param_1,0x3020,0xfc,param_2[4]);
  snd_soc_component_update_bits(param_1,0x3021,0xfc,param_2[5]);
  snd_soc_component_update_bits(param_1,0x3123,0xf,param_2[1]);
  snd_soc_component_update_bits(param_1,0x3124,0xf,param_2[2]);
  if (param_3 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x80,0x80,0,0,0);
    wcd937x_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_4c);
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x80,0,0,0,0);
    *param_3 = local_4c;
  }
  if (param_4 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x40,0x40,0,0,0);
    wcd937x_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_4c);
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x40,0,0,0,0);
    *param_4 = local_4c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd937x_mbhc_get_result_params @ 001080c8 size=476
// signature: undefined wcd937x_mbhc_get_result_params(void)
// callers: [wcd937x_mbhc_zdet_ramp]
//------------------------------------------------------------

void wcd937x_mbhc_get_result_params(long param_1,long param_2,ulong param_3,uint *param_4)

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
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x20),0x3016,0x20,0x20,0,0,0);
  iVar7 = 899;
  do {
    regmap_read(*(undefined8 *)(param_1 + 0x20),0x3018,(long)&local_60 + 4);
    if ((local_60._4_4_ >> 7 & 1) != 0) break;
    bVar5 = iVar7 != 0;
    iVar7 = iVar7 + -1;
  } while (bVar5);
  local_60._4_4_ = local_60._4_4_ << 8;
  regmap_read(*(undefined8 *)(param_1 + 0x20),0x3017,&local_60);
  local_60._4_4_ = local_60._4_4_ | (uint)local_60;
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x20),0x3016,0x20,0,0,0,0);
  uVar3 = local_60._4_4_;
  uVar6 = local_60._4_4_ & 0x3fff;
  uVar1 = local_60._4_4_ & 0xffff;
  if (((local_60._4_4_ >> 0xf & 1) == 0) && (uVar6 != 0)) {
    usleep_range_state(5000,0x13ba,2);
  }
  if ((uVar1 < 0x4000) || (uVar6 == 0)) {
    if (uVar6 == 0) goto LAB_00108268;
  }
  else {
    uVar1 = (-1 << (ulong)(0xe - ((uint)param_3 & 0xffff) & 0x1f)) +
            uVar6 * (int)*(short *)(param_2 + (ulong)(uVar3 >> 0xe & 3) * 2);
    if ((int)uVar1 < 1) {
      if (7 < ((uint)param_3 & 0xffff)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1082a4);
        (*pcVar4)();
      }
      if (*(int *)(&DAT_00114bb8 + (param_3 & 0xffff) * 4) <= (int)uVar6) goto LAB_00108228;
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
LAB_00108228:
  iVar7 = 899;
  do {
    regmap_read(*(undefined8 *)(param_1 + 0x20),0x3017,(long)&local_60 + 4);
    regmap_read(*(undefined8 *)(param_1 + 0x20),0x3018,&local_60);
    bVar5 = iVar7 == 0;
    iVar7 = iVar7 + -1;
    local_60._4_4_ = (uint)local_60 | local_60._4_4_ << 8;
    if (bVar5) break;
  } while ((local_60._4_4_ & 0x3fff) != 0);
LAB_00108268:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd937x_hph_impedance_get @ 001082a8 size=192
// signature: undefined wcd937x_hph_impedance_get(void)
// callers: []
//------------------------------------------------------------

void wcd937x_hph_impedance_get(long param_1,long param_2)

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
  lVar3 = wcd937x_soc_get_mbhc(lVar5);
  if (lVar3 == 0) {
    _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: mbhc not initialized!\n","wcd937x_hph_impedance_get"
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
// wcd937x_get_hph_type @ 0010836c size=96
// signature: undefined wcd937x_get_hph_type(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd937x_get_hph_type(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x80);
  lVar1 = wcd937x_soc_get_mbhc(lVar3);
  if (lVar1 == 0) {
    _dev_err(*(undefined8 *)(lVar3 + 0x18),"%s: mbhc not initialized!\n","wcd937x_get_hph_type");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar1 + 0x1c4);
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00111fbc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&wcd937x_codec_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00111fec size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&wcd937x_codec_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00117000 size=1
// signature: undefined _printk(void)
// callers: [wcd937x_version_read, wcd937x_mbhc_hs_detect, wcd937x_mbhc_hs_detect_exit, wcd937x_wakeup, wcd937x_wd_handle_irq, wcd937x_variant_read, wcd937x_soc_get_mbhc, wcd937x_mbhc_ssr_down, wcd937x_mbhc_micb_adjust_voltage, wcd937x_bind, wcd937x_soc_codec_probe, wcd937x_mbhc_deinit, wcd937x_tx_get_slave_ch_type_idx, wcd937x_mbhc_get_impedance, wcd937x_codec_get_dev_num, wcd937x_get_hwdep_fw_cal, wcd937x_mbhc_init, wcd937x_get_micb_vout_ctl_val]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00117008 size=1
// signature: undefined mutex_lock(void)
// callers: [wcd937x_micbias_control, wcd937x_enable_req, wcd937x_codec_enable_adc, wcd937x_mbhc_micb_adjust_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 00117010 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wcd937x_codec_hphr_dac_event, wcd937x_mbhc_micb_adjust_voltage, wcd937x_codec_enable_ear_pa, wcd937x_mbhc_hph_pa_on_status, wcd937x_soc_codec_probe, wcd937x_ear_pa_gain_get, wcd937x_codec_hphl_dac_event, wcd937x_wcd_mbhc_calc_impedance, wcd937x_mbhc_get_moisture_status, wcd937x_mbhc_micb_en_status, wcd937x_mbhc_btn_to_num, wcd937x_event_notify, wcd937x_tx_swr_ctrl, wcd937x_init_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 00117018 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wcd937x_codec_enable_adc, wcd937x_mbhc_zdet_ramp, wcd937x_mbhc_micb_adjust_voltage, wcd937x_mbhc_hph_l_pull_up_control, wcd937x_codec_enable_ear_pa, wcd937x_mbhc_clk_setup, wcd937x_mbhc_moisture_polling_ctrl, wcd937x_mbhc_micb_ramp_control, wcd937x_codec_hphl_dac_event, wcd937x_enable_req, wcd937x_mbhc_program_btn_thr, wcd937x_mbhc_gnd_det_ctrl, wcd937x_enable_rx3, wcd937x_mbhc_mbhc_bias_control, wcd937x_rx_clk_enable, wcd937x_enable_rx2, wcd937x_init_reg, wcd937x_codec_hphr_dac_event, wcd937x_codec_aux_dac_event, wcd937x_codec_enable_aux_pa, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_dmic, wcd937x_mbhc_moisture_detect_en, wcd937x_micbias_control, wcd937x_mbhc_post_ssr_init, wcd937x_wcd_mbhc_calc_impedance, wcd937x_mbhc_get_moisture_status, wcd937x_mbhc_moisture_config, wcd937x_tx_ch_pwr_level_put, wcd937x_mbhc_hph_pull_down_ctrl, wcd937x_ear_pa_gain_put, wcd937x_event_notify, wcd937x_codec_ear_dac_event, wcd937x_enable_rx1, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00117020 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd937x_reset, wcd937x_codec_hphr_dac_event, wcd937x_codec_enable_aux_pa, wcd937x_mbhc_micb_adjust_voltage, wcd937x_bind, wcd937x_codec_enable_micbias, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_ear_pa, wcd937x_codec_enable_micbias_pullup, wcd937x_codec_enable_vdd_buck, wcd937x_codec_hphl_dac_event, wcd937x_wcd_mbhc_calc_impedance, wcd937x_enable_rx3, wcd937x_get_logical_addr, wcd937x_event_notify, wcd937x_codec_ear_dac_event, wcd937x_mbhc_get_result_params, wcd937x_init_reg, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00117028 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcd937x_micbias_control, wcd937x_enable_req, wcd937x_codec_enable_adc, wcd937x_mbhc_micb_adjust_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00117030 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [wcd937x_micbias_control, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00117038 size=1
// signature: undefined _dev_err(void)
// callers: [wcd937x_probe, wcd937x_mbhc_hs_detect, wcd937x_mbhc_hs_detect_exit, wcd937x_reset, wcd937x_set_port_params, wcd937x_get_hph_type, wcd937x_populate_dt_data, wcd937x_mbhc_ssr_down, wcd937x_get_codec_variant, wcd937x_bind, wcd937x_codec_enable_dmic, wcd937x_micbias_control, wcd937x_codec_enable_vdd_buck, wcd937x_parse_port_mapping, wcd937x_soc_codec_probe, wcd937x_mbhc_post_ssr_init, wcd937x_mbhc_program_btn_thr, wcd937x_suspend, wcd937x_hph_impedance_get, wcd937x_get_logical_addr, wcd937x_get_hwdep_fw_cal, wcd937x_mbhc_init, wcd937x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 00117040 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [wcd937x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 00117048 size=1
// signature: undefined snd_info_register(void)
// callers: [wcd937x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 00117050 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [wcd937x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 00117058 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [wcd937x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00117068 size=1
// signature: undefined kmalloc_trace(void)
// callers: [wcd937x_populate_dt_data, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00117070 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wcd937x_probe, wcd937x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 00117078 size=1
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: [wcd937x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_get_power_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00117080 size=1
// signature: undefined of_find_property(void)
// callers: [wcd937x_parse_port_mapping, wcd937x_populate_dt_data, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00117088 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wcd937x_parse_port_mapping, wcd937x_populate_dt_data, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00117090 size=1
// signature: undefined _dev_info(void)
// callers: [wcd937x_soc_codec_probe, wcd937x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00117098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd937x_version_read, wcd937x_probe, wcd937x_tx_master_ch_put, wcd937x_variant_read, wcd937x_populate_dt_data, wcd937x_codec_enable_adc, wcd937x_mbhc_zdet_ramp, wcd937x_bind, wcd937x_tx_connect_port, wcd937x_codec_enable_dmic, wcd937x_handle_post_irq, wcd937x_tx_master_ch_get, wcd937x_parse_port_mapping, wcd937x_hph_impedance_get, wcd937x_wcd_mbhc_calc_impedance, wcd937x_enable_rx3, wcd937x_get_logical_addr, wcd937x_enable_clsh, wcd937x_enable_rx1, wcd937x_enable_rx2, wcd937x_mbhc_get_result_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001170a0 size=1
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
// platform_driver_unregister @ 001170a8 size=1
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
// simple_read_from_buffer @ 001170b0 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [wcd937x_version_read, wcd937x_variant_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_match_add_release @ 001170b8 size=1
// signature: undefined component_match_add_release(void)
// callers: [wcd937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_match_add_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_add_with_match @ 001170c0 size=1
// signature: undefined component_master_add_with_match(void)
// callers: [wcd937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_add_with_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_del @ 001170c8 size=1
// signature: undefined component_master_del(void)
// callers: [wcd937x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 001170d0 size=1
// signature: undefined msm_cdc_init_supplies(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_init_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 001170d8 size=1
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_static_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_bind_all @ 001170e0 size=1
// signature: undefined component_bind_all(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_bind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001170e8 size=1
// signature: undefined __kmalloc(void)
// callers: [wcd937x_parse_port_mapping, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001170f0 size=1
// signature: undefined kfree(void)
// callers: [wcd937x_parse_port_mapping, wcd937x_unbind, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_matching_swr_slave_device @ 001170f8 size=1
// signature: undefined get_matching_swr_slave_device(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_matching_swr_slave_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_init_port_params @ 00117100 size=1
// signature: undefined swr_init_port_params(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_init_port_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 00117108 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00117110 size=1
// signature: undefined regmap_write(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_init @ 00117118 size=1
// signature: undefined wcd_irq_init(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00117120 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wcd937x_wcd_mbhc_calc_impedance, wcd937x_mbhc_zdet_ramp, wcd937x_bind, wcd937x_mbhc_get_result_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00117128 size=1
// signature: undefined __mutex_init(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_request_irq @ 00117130 size=1
// signature: undefined wcd_request_irq(void)
// callers: [wcd937x_bind, wcd937x_mbhc_request_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_request_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_disable_irq @ 00117138 size=1
// signature: undefined wcd_disable_irq(void)
// callers: [wcd937x_codec_enable_aux_pa, wcd937x_mbhc_irq_control, wcd937x_bind, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_ear_pa, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 00117140 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_exit @ 00117148 size=1
// signature: undefined wcd_irq_exit(void)
// callers: [wcd937x_unbind, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_unbind_all @ 00117150 size=1
// signature: undefined component_unbind_all(void)
// callers: [wcd937x_unbind, wcd937x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_unbind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 00117158 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [wcd937x_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 00117160 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [wcd937x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 00117168 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wcd937x_reset, wcd937x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 00117170 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wcd937x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_vote @ 00117178 size=1
// signature: undefined swr_device_wakeup_vote(void)
// callers: [wcd937x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_unvote @ 00117180 size=1
// signature: undefined swr_device_wakeup_unvote(void)
// callers: [wcd937x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_unvote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 00117188 size=1
// signature: undefined __sw_hweight8(void)
// callers: [wcd937x_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00117190 size=1
// signature: undefined ___ratelimit(void)
// callers: [wcd937x_wd_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00117198 size=1
// signature: undefined regmap_read(void)
// callers: [wcd937x_handle_post_irq, wcd937x_mbhc_get_result_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 001171a0 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 001171a8 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001171b0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd937x_soc_codec_probe, wcd937x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cal_create_hwdep @ 001171c0 size=1
// signature: undefined wcd_cal_create_hwdep(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cal_create_hwdep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 001171c8 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 001171d0 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_init @ 001171d8 size=1
// signature: undefined wcd_cls_h_init(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 001171e0 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 001171e8 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [wcd937x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001171f0 size=1
// signature: undefined _dev_warn(void)
// callers: [wcd937x_rx_hph_mode_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 001171f8 size=1
// signature: undefined strnstr(void)
// callers: [wcd937x_tx_get_slave_ch_type_idx, wcd937x_tx_ch_pwr_level_get, wcd937x_tx_ch_pwr_level_put, wcd937x_codec_enable_micbias, wcd937x_tx_swr_ctrl, wcd937x_codec_enable_micbias_pullup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 00117200 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [wcd937x_codec_enable_aux_pa, wcd937x_codec_enable_adc, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_ear_pa, wcd937x_tx_swr_ctrl, wcd937x_enable_clsh, wcd937x_codec_enable_dmic, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 00117208 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [wcd937x_codec_enable_adc, wcd937x_enable_rx3, wcd937x_tx_connect_port, wcd937x_enable_clsh, wcd937x_enable_rx1, wcd937x_enable_rx2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_ondemand_supply @ 00117210 size=1
// signature: undefined msm_cdc_enable_ondemand_supply(void)
// callers: [wcd937x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 00117218 size=1
// signature: undefined swr_connect_port(void)
// callers: [wcd937x_enable_rx3, wcd937x_tx_connect_port, wcd937x_enable_clsh, wcd937x_enable_rx1, wcd937x_enable_rx2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_enable_irq @ 00117220 size=1
// signature: undefined wcd_enable_irq(void)
// callers: [wcd937x_codec_enable_aux_pa, wcd937x_mbhc_irq_control, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_ear_pa, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_fsm @ 00117228 size=1
// signature: undefined wcd_cls_h_fsm(void)
// callers: [wcd937x_codec_aux_dac_event, wcd937x_codec_enable_aux_pa, wcd937x_codec_enable_hphl_pa, wcd937x_codec_enable_ear_pa, wcd937x_codec_ear_dac_event, wcd937x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_fsm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 00117230 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 00117238 size=1
// signature: undefined regcache_sync(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00117240 size=1
// signature: undefined __const_udelay(void)
// callers: [wcd937x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 00117248 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [wcd937x_codec_enable_dmic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00117250 size=1
// signature: undefined kstrtouint(void)
// callers: [wcd937x_codec_enable_dmic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 00117258 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wcd937x_get_logical_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_disable_ondemand_supply @ 00117260 size=1
// signature: undefined msm_cdc_disable_ondemand_supply(void)
// callers: [wcd937x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_disable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_get_impedance @ 001172a8 size=1
// signature: undefined wcd_mbhc_get_impedance(void)
// callers: [wcd937x_mbhc_get_impedance, wcd937x_hph_impedance_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_get_impedance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_start @ 001172b0 size=1
// signature: undefined wcd_mbhc_start(void)
// callers: [wcd937x_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_stop @ 001172b8 size=1
// signature: undefined wcd_mbhc_stop(void)
// callers: [wcd937x_mbhc_hs_detect_exit, wcd937x_mbhc_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_deinit @ 001172c0 size=1
// signature: undefined wcd_mbhc_deinit(void)
// callers: [wcd937x_mbhc_deinit, wcd937x_mbhc_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_deinit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_init @ 001172c8 size=1
// signature: undefined wcd_mbhc_init(void)
// callers: [wcd937x_mbhc_post_ssr_init, wcd937x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 001172d0 size=1
// signature: undefined __init_rwsem(void)
// callers: [wcd937x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 001172d8 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [wcd937x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 001172e0 size=1
// signature: undefined devm_kfree(void)
// callers: [wcd937x_mbhc_deinit, wcd937x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 001172e8 size=1
// signature: undefined mutex_is_locked(void)
// callers: [wcd937x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 001172f0 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [wcd937x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001172f8 size=1
// signature: undefined __warn_printk(void)
// callers: [wcd937x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcdcal_get_fw_cal @ 00117300 size=1
// signature: undefined wcdcal_get_fw_cal(void)
// callers: [wcd937x_get_hwdep_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcdcal_get_fw_cal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00117308 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [wcd937x_mbhc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00117310 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [wcd937x_mbhc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_free_irq @ 00117318 size=1
// signature: undefined wcd_free_irq(void)
// callers: [wcd937x_mbhc_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



