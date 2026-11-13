// Decompiled by Ghidra 12.2
// Program: wcd938x_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd938x_soc_get_mbhc @ 00101934 size=136
// signature: undefined wcd938x_soc_get_mbhc(void)
// callers: [wcd938x_hph_impedance_get, wcd938x_get_hph_type]
//------------------------------------------------------------

undefined8 wcd938x_soc_get_mbhc(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(&wcd938x_soc_get_mbhc__rs,"wcd938x_soc_get_mbhc");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0011c3a5;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      return *(undefined8 *)(lVar3 + 0x100);
    }
    iVar1 = ___ratelimit(wcd938x_soc_get_mbhc__rs_1,"wcd938x_soc_get_mbhc");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0011be98;
  }
  _printk(puVar2,"wcd938x_soc_get_mbhc");
  return 0;
}



//------------------------------------------------------------
// wcd938x_get_micb_vout_ctl_val @ 001019c0 size=116
// signature: undefined wcd938x_get_micb_vout_ctl_val(void)
// callers: []
//------------------------------------------------------------

uint wcd938x_get_micb_vout_ctl_val(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 - 0xb23U < 0xfffff8c5) {
    iVar1 = ___ratelimit(wcd938x_get_micb_vout_ctl_val__rs,"wcd938x_get_micb_vout_ctl_val");
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      _printk(&DAT_0011c02c,"wcd938x_get_micb_vout_ctl_val");
      uVar2 = 0xffffffea;
    }
  }
  else {
    uVar2 = (param_1 - 1000U >> 1 & 0x7fff) / 0x19;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd938x_mbhc_micb_adjust_voltage @ 00101a38 size=344
// signature: undefined wcd938x_mbhc_micb_adjust_voltage(void)
// callers: [wcd938x_mbhc_micb_ctrl_threshold_mic]
//------------------------------------------------------------

undefined8 wcd938x_mbhc_micb_adjust_voltage(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_3 - 1U < 4) {
    uVar2 = *(undefined4 *)(&DAT_0011c71c + (long)(int)(param_3 - 1U) * 4);
    lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x68;
    mutex_lock(lVar1);
    uVar4 = snd_soc_component_read(param_1,uVar2);
    if (param_2 - 0xb23U < 0xfffff8c5) {
      iVar5 = ___ratelimit(wcd938x_get_micb_vout_ctl_val__rs,"wcd938x_get_micb_vout_ctl_val");
      if (iVar5 == 0) {
        uVar6 = 0xffffffea;
      }
      else {
        _printk(&DAT_0011c02c,"wcd938x_get_micb_vout_ctl_val");
        uVar6 = 0xffffffea;
      }
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
      uVar6 = 0;
    }
    mutex_unlock(lVar1);
  }
  else {
    uVar6 = 0xffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// wcd938x_tx_channel_config @ 00101b94 size=152
// signature: undefined wcd938x_tx_channel_config(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_tx_channel_config(undefined8 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_2 < 4) {
    uVar4 = -(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_2 << 2;
    uVar1 = 0;
    if (param_3 != 0) {
      uVar1 = *(undefined4 *)(&DAT_0011c72c + uVar4);
    }
    snd_soc_component_update_bits
              (param_1,*(undefined4 *)(&DAT_0011c73c + uVar4),*(undefined4 *)(&DAT_0011c72c + uVar4)
               ,uVar1);
    uVar3 = 0;
  }
  else {
    iVar2 = ___ratelimit(wcd938x_tx_channel_config__rs,"wcd938x_tx_channel_config");
    if (iVar2 != 0) {
      _printk(&DAT_0011bb61,"wcd938x_tx_channel_config",(ulong)param_2);
    }
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// wcd938x_disable_bcs_before_slow_insert @ 00101c30 size=84
// signature: undefined wcd938x_disable_bcs_before_slow_insert(void)
// callers: [wcd938x_mbhc_bcs_enable]
//------------------------------------------------------------

void wcd938x_disable_bcs_before_slow_insert(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  pcVar1 = *(code **)(lVar2 + 0xc38);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101c74);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(lVar2 + 0xc30),5,(param_2 ^ 0xffffffff) & 1);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_micbias_control @ 00101c88 size=1092
// signature: undefined wcd938x_micbias_control(void)
// callers: [wcd938x_mbhc_request_micbias, __wcd938x_codec_enable_micbias, wcd938x_codec_enable_micbias_pullup]
//------------------------------------------------------------

undefined8 wcd938x_micbias_control(long param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  long lVar10;
  ulong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  uVar1 = param_2 - 1;
  uVar11 = (ulong)uVar1;
  if (3 < uVar1) {
    iVar3 = ___ratelimit(wcd938x_micbias_control__rs,"wcd938x_micbias_control");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    pcVar5 = "%s: Invalid micbias index, micb_ind:%d\n";
    param_2 = uVar1;
LAB_00101cec:
    _dev_err(uVar4,pcVar5,"wcd938x_micbias_control",param_2);
    return 0xffffffea;
  }
  lVar10 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar10 == 0) {
    iVar3 = ___ratelimit(wcd938x_micbias_control__rs_6,"wcd938x_micbias_control");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: wcd938x private data is NULL\n",
             "wcd938x_micbias_control");
    return 0xffffffea;
  }
  uVar14 = 0;
  uVar13 = 0;
  uVar8 = 0;
  uVar12 = 0;
  uVar4 = 0;
  bVar2 = true;
  uVar9 = 0x3022;
  switch(uVar11) {
  case 0:
    break;
  case 1:
    bVar2 = false;
    uVar8 = 1;
    uVar9 = 0x3023;
    uVar4 = 8;
    uVar12 = 6;
    uVar13 = 4;
    uVar14 = 2;
    break;
  case 2:
    uVar14 = 0;
    uVar13 = 0;
    uVar8 = 0;
    uVar12 = 0;
    uVar4 = 0;
    uVar9 = 0x3025;
    break;
  case 3:
    uVar14 = 0;
    uVar13 = 0;
    uVar8 = 0;
    uVar12 = 0;
    uVar4 = 0;
    uVar9 = 0x3026;
    break;
  default:
    iVar3 = ___ratelimit(wcd938x_micbias_control__rs_8,"wcd938x_micbias_control");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    pcVar5 = "%s: Invalid micbias number: %d\n";
    goto LAB_00101cec;
  }
  mutex_lock();
  switch(param_3) {
  case 0:
    if (*(char *)(lVar10 + 0xc78) == '\0') {
LAB_00101ff4:
      uVar4 = 0xffffffed;
      goto LAB_00102028;
    }
    lVar6 = lVar10 + (ulong)uVar1 * 4;
    iVar3 = *(int *)(lVar6 + 0x48);
    *(int *)(lVar6 + 0x48) = iVar3 + 1;
    if ((iVar3 == 0) && (*(int *)(lVar10 + uVar11 * 4 + 0x38) == 0)) {
      snd_soc_component_update_bits(param_1,uVar9,0xc0,0x80);
    }
    break;
  case 1:
    piVar7 = (int *)(lVar10 + (ulong)uVar1 * 4 + 0x48);
    iVar3 = *piVar7;
    if (0 < iVar3) {
      *piVar7 = iVar3 + -1;
      iVar3 = iVar3 + -1;
    }
    if (*(char *)(lVar10 + 0xc78) == '\0') goto LAB_00101ff4;
    if ((iVar3 == 0) && (*(int *)(lVar10 + uVar11 * 4 + 0x38) == 0)) {
      snd_soc_component_update_bits(param_1,uVar9,0xc0,0);
    }
    break;
  case 2:
    if (*(char *)(lVar10 + 0xc78) == '\0') goto LAB_00101ff4;
    lVar6 = lVar10 + (ulong)uVar1 * 4;
    iVar3 = *(int *)(lVar6 + 0x38);
    *(int *)(lVar6 + 0x38) = iVar3 + 1;
    if (iVar3 == 0) {
      snd_soc_component_update_bits(param_1,0x3409,0xf0,0xf0);
      snd_soc_component_update_bits(param_1,0x3408,0x10,0x10);
      snd_soc_component_update_bits(param_1,0x3417,1,1);
      snd_soc_component_update_bits(param_1,0x306c,1,1);
      snd_soc_component_update_bits(param_1,0x306f,1,1);
      snd_soc_component_update_bits(param_1,0x3072,1,1);
      snd_soc_component_update_bits(param_1,0x3075,1,1);
      snd_soc_component_update_bits(param_1,uVar9,0xc0,0x40);
      if (!bVar2) {
        blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,uVar13);
      }
    }
    if (((uVar8 & param_4) == 1) && (lVar6 = *(long *)(lVar10 + 0x100), lVar6 != 0)) {
LAB_00102020:
      blocking_notifier_call_chain(lVar6 + 0x428,uVar4);
    }
    break;
  case 3:
    piVar7 = (int *)(lVar10 + (ulong)uVar1 * 4 + 0x38);
    iVar3 = *piVar7;
    if (0 < iVar3) {
      *piVar7 = iVar3 + -1;
      iVar3 = iVar3 + -1;
    }
    if (*(char *)(lVar10 + 0xc78) == '\0') goto LAB_00101ff4;
    if (iVar3 == 0) {
      iVar3 = *(int *)(lVar10 + uVar11 * 4 + 0x48);
      if (iVar3 < 1) {
        if (iVar3 == 0) {
          if (bVar2) {
            uVar4 = 0;
            goto LAB_00101fec;
          }
          if (*(long *)(lVar10 + 0x100) != 0) {
            blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,1);
          }
          snd_soc_component_update_bits(param_1,uVar9,0xc0,0);
          if (*(long *)(lVar10 + 0x100) != 0) {
            blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,uVar14);
          }
        }
      }
      else {
        uVar4 = 0x80;
LAB_00101fec:
        snd_soc_component_update_bits(param_1,uVar9,0xc0,uVar4);
      }
    }
    if (((uVar8 & param_4) == 1) && (lVar6 = *(long *)(lVar10 + 0x100), lVar6 != 0)) {
      uVar4 = uVar12;
      goto LAB_00102020;
    }
  }
  uVar4 = 0;
LAB_00102028:
  mutex_unlock(lVar10 + 0x68);
  return uVar4;
}



//------------------------------------------------------------
// wcd938x_swr_dmic_register_notifier @ 001020d0 size=124
// signature: undefined wcd938x_swr_dmic_register_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_swr_dmic_register_notifier(long param_1,undefined8 param_2,byte param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd938x_swr_dmic_register_notifier__rs,"wcd938x_swr_dmic_register_notifier"
                        );
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      _printk(&DAT_0011c04f,"wcd938x_swr_dmic_register_notifier");
      uVar2 = 0xffffffea;
    }
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    *(byte *)(lVar3 + 0xc87) = param_3 & 1;
    if ((param_3 & 1) == 0) {
      uVar2 = blocking_notifier_chain_unregister(lVar3 + 0xc88);
    }
    else {
      uVar2 = blocking_notifier_chain_register();
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd938x_codec_force_enable_micbias_v2 @ 00102150 size=400
// signature: undefined wcd938x_codec_force_enable_micbias_v2(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_force_enable_micbias_v2(long param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(wcd938x_codec_force_enable_micbias_v2__rs,
                         "wcd938x_codec_force_enable_micbias_v2");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    _printk(&DAT_0011c04f,"wcd938x_codec_force_enable_micbias_v2");
    return 0xffffffea;
  }
  if ((param_2 == 1) || (param_2 == 8)) {
    if (0xfffffffb < param_3 - 5U) {
      lVar6 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
      if (*(char *)(lVar6 + 0xc78) == '\0') {
        if (3 < param_3 - 1U) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1022e0);
          (*pcVar1)();
        }
        if (param_2 == 8) {
          piVar5 = (int *)(lVar6 + (ulong)(param_3 - 1U) * 4 + 0x48);
          iVar2 = *piVar5;
          if (0 < iVar2) {
            *piVar5 = iVar2 + -1;
            return 0xffffffed;
          }
        }
      }
      if (param_2 == 8) {
        wcd938x_wakeup(lVar6,1);
        uVar4 = 1;
      }
      else {
        if (param_2 != 1) {
          return 0;
        }
        wcd938x_wakeup(lVar6,1);
        uVar4 = 0;
      }
      wcd938x_enable_micbias(lVar6,param_3,uVar4);
      wcd938x_wakeup(lVar6,0);
      return 0;
    }
    iVar2 = ___ratelimit(wcd938x_codec_force_enable_micbias_v2__rs_13,
                         "wcd938x_codec_force_enable_micbias_v2");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011bbfd;
    param_2 = param_3;
  }
  else {
    iVar2 = ___ratelimit(wcd938x_codec_force_enable_micbias_v2__rs_11,
                         "wcd938x_codec_force_enable_micbias_v2");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011b7f0;
  }
  _printk(puVar3,"wcd938x_codec_force_enable_micbias_v2",param_2);
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd938x_wakeup @ 001022e4 size=204
// signature: undefined wcd938x_wakeup(void)
// callers: [wcd938x_codec_force_enable_micbias, wcd938x_codec_force_enable_micbias_v2]
//------------------------------------------------------------

undefined4 wcd938x_wakeup(long param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(wcd938x_wakeup__rs,"wcd938x_wakeup");
    if (iVar2 != 0) {
      puVar3 = &DAT_0011c12b;
      goto LAB_0010239c;
    }
  }
  else {
    if (*(long *)(param_1 + 0x30) != 0) {
      mutex_lock(param_1 + 0x98);
      if ((param_2 & 1) == 0) {
        uVar1 = swr_device_wakeup_unvote(*(undefined8 *)(param_1 + 0x30));
      }
      else {
        uVar1 = swr_device_wakeup_vote();
      }
      mutex_unlock(param_1 + 0x98);
      return uVar1;
    }
    iVar2 = ___ratelimit(wcd938x_wakeup__rs_41,"wcd938x_wakeup");
    if (iVar2 != 0) {
      puVar3 = &DAT_0011b4f6;
LAB_0010239c:
      _printk(puVar3,"wcd938x_wakeup");
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd938x_enable_micbias @ 001023b0 size=332
// signature: undefined wcd938x_enable_micbias(void)
// callers: [wcd938x_codec_force_enable_micbias_v2]
//------------------------------------------------------------

void wcd938x_enable_micbias(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  
  if (param_1 == 0) {
    iVar4 = ___ratelimit(wcd938x_enable_micbias__rs,"wcd938x_enable_micbias");
    if (iVar4 == 0) {
      return;
    }
    _printk(&DAT_0011c402,"wcd938x_enable_micbias");
    return;
  }
  uVar3 = param_2 - 1;
  if (3 < uVar3) {
    iVar4 = ___ratelimit(wcd938x_enable_micbias__rs_44,"wcd938x_enable_micbias");
    if (iVar4 == 0) {
      return;
    }
    _printk(&DAT_0011b984,"wcd938x_enable_micbias",param_2);
    return;
  }
  uVar2 = *(undefined4 *)(&DAT_0011c71c + (long)(int)uVar3 * 4);
  mutex_lock(param_1 + 0x68);
  if (param_3 == 1) {
    piVar6 = (int *)(param_1 + (ulong)uVar3 * 4 + 0x48);
    iVar4 = *piVar6;
    if (0 < iVar4) {
      *piVar6 = iVar4 + -1;
      iVar4 = iVar4 + -1;
    }
    if ((iVar4 != 0) || (*(int *)(param_1 + (ulong)uVar3 * 4 + 0x38) != 0)) goto LAB_001024dc;
    uVar5 = 0;
  }
  else {
    if (((param_3 != 0) ||
        (lVar1 = param_1 + (ulong)uVar3 * 4, iVar4 = *(int *)(lVar1 + 0x48),
        *(int *)(lVar1 + 0x48) = iVar4 + 1, iVar4 != 0)) ||
       (*(int *)(param_1 + (ulong)uVar3 * 4 + 0x38) != 0)) goto LAB_001024dc;
    uVar5 = 0x80;
  }
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x20),uVar2,0xc0,uVar5,0,0,0);
LAB_001024dc:
  mutex_unlock(param_1 + 0x68);
  return;
}



//------------------------------------------------------------
// wcd938x_codec_get_dev_num @ 00102500 size=108
// signature: undefined wcd938x_codec_get_dev_num(void)
// callers: []
//------------------------------------------------------------

ulong wcd938x_codec_get_dev_num(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if ((lVar2 != 0) && (lVar2 = *(long *)(lVar2 + 0x28), lVar2 != 0)) {
      return (ulong)*(byte *)(lVar2 + 0x40);
    }
    iVar1 = ___ratelimit(wcd938x_codec_get_dev_num__rs,"wcd938x_codec_get_dev_num");
    if (iVar1 != 0) {
      _printk(&DAT_0011c04f,"wcd938x_codec_get_dev_num");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd938x_get_codec_variant @ 00102570 size=80
// signature: undefined wcd938x_get_codec_variant(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_get_codec_variant(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 == 0) {
      _dev_err(*(long *)(param_1 + 0x18),"%s:wcd938x not probed\n","wcd938x_get_codec_variant");
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(lVar2 + 8);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd938x_info_create_codec_entry @ 001025c4 size=308
// signature: undefined wcd938x_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_info_create_codec_entry(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (*(long *)(lVar5 + 0xc58) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),"wcd938x");
      *(long *)(lVar5 + 0xc58) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0xc58));
        if ((-1 < iVar1) &&
           (lVar3 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"version",
                               *(undefined8 *)(lVar5 + 0xc58)), lVar3 != 0)) {
          *(long *)(lVar3 + 0x40) = lVar5;
          *(undefined8 *)(lVar3 + 0x10) = 0x20;
          *(undefined2 *)(lVar3 + 0x18) = 1;
          *(undefined1 **)(lVar3 + 0x20) = wcd938x_info_ops;
          iVar1 = snd_info_register();
          if (-1 < iVar1) {
            *(long *)(lVar5 + 0xc60) = lVar3;
            lVar4 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"variant",
                               *(undefined8 *)(lVar5 + 0xc58));
            if (lVar4 != 0) {
              *(long *)(lVar4 + 0x40) = lVar5;
              *(undefined8 *)(lVar4 + 0x10) = 0x20;
              *(undefined2 *)(lVar4 + 0x18) = 1;
              *(undefined1 **)(lVar4 + 0x20) = wcd938x_variant_ops;
              iVar1 = snd_info_register();
              if (-1 < iVar1) {
                *(long *)(lVar5 + 0xc68) = lVar4;
                return 0;
              }
              snd_info_free_entry(lVar4);
            }
          }
          snd_info_free_entry(lVar3);
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0xc58));
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
// wcd938x_populate_dt_data @ 001026fc size=1036
// signature: undefined wcd938x_populate_dt_data(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

ulong * wcd938x_populate_dt_data(long param_1)

{
  ulong uVar1;
  int iVar2;
  ulong *puVar3;
  undefined8 uVar4;
  long lVar5;
  ulong local_88 [11];
  
  lVar5 = sp_el0;
  local_88[10] = *(long *)(lVar5 + 0x638);
  puVar3 = (ulong *)devm_kmalloc(param_1,0x48,0xdc0);
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
      iVar2 = ___ratelimit(wcd938x_populate_dt_data__rs,"wcd938x_populate_dt_data");
      if (iVar2 != 0) {
        _dev_err(param_1,"%s: Looking up %s property in node %s failed\n","wcd938x_populate_dt_data"
                 ,"qcom,wcd-rst-gpio-node",*(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
      }
    }
    else {
      msm_cdc_get_power_supplies(param_1,puVar3 + 7,puVar3 + 8);
      if ((puVar3[7] != 0) && (0 < (int)puVar3[8])) {
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
          _dev_info(param_1,"%s: Micbias1 DT property not found\n","wcd938x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias1-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd938x_read_of_property_u32","qcom,cdc-micbias1-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)(puVar3 + 4) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias2-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias2 DT property not found\n","wcd938x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias2-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd938x_read_of_property_u32","qcom,cdc-micbias2-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)((long)puVar3 + 0x24) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias3-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias3 DT property not found\n","wcd938x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias3-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd938x_read_of_property_u32","qcom,cdc-micbias3-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)(puVar3 + 5) = (undefined4)local_88[0];
          }
        }
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias4-mv",0);
        if (lVar5 == 0) {
          _dev_info(param_1,"%s: Micbias4 DT property not found\n","wcd938x_dt_parse_micbias_info");
        }
        else {
          iVar2 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-micbias4-mv",local_88,1,0);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd938x_read_of_property_u32","qcom,cdc-micbias4-mv",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          }
          else {
            *(undefined4 *)((long)puVar3 + 0x2c) = (undefined4)local_88[0];
          }
        }
        goto LAB_00102988;
      }
      iVar2 = ___ratelimit(wcd938x_populate_dt_data__rs_36,"wcd938x_populate_dt_data");
      if (iVar2 != 0) {
        _dev_err(param_1,"%s: no power supplies defined for codec\n","wcd938x_populate_dt_data");
      }
    }
    puVar3 = (ulong *)0x0;
  }
LAB_00102988:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar3;
}



//------------------------------------------------------------
// wcd938x_version_read @ 00102b0c size=248
// signature: undefined wcd938x_version_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wcd938x_version_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
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
    iVar2 = ___ratelimit(wcd938x_version_read__rs,"wcd938x_version_read");
    if (iVar2 == 0) {
      uVar3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0011c2d3,"wcd938x_version_read");
      uVar3 = 0xffffffffffffffea;
    }
  }
  else {
    if (*(int *)(*(long *)(param_1 + 0x40) + 0xc50) == 1) {
      uVar3 = 0xc;
      local_38 = _DAT_0011beaf;
      uStack_33 = s_8X_1_0_0011beb4._0_2_;
      cStack_31 = s_8X_1_0_0011beb4[2];
      local_30 = (char  [5])s_8X_1_0_0011beb4._3_5_;
    }
    else {
      uVar3 = 0xe;
      local_38 = s_VER_UNDEFINED_0011bb7f._0_5_;
      uStack_33 = s_VER_UNDEFINED_0011bb7f._5_2_;
      cStack_31 = s_VER_UNDEFINED_0011bb7f[7];
      local_30 = s_VER_UNDEFINED_0011bb7f._8_5_;
      uStack_2b = s_VER_UNDEFINED_0011bb7f._13_2_;
    }
    uVar3 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,uVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_variant_read @ 00102c08 size=260
// signature: undefined wcd938x_variant_read(void)
// callers: []
//------------------------------------------------------------

void wcd938x_variant_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  undefined8 uVar4;
  undefined8 local_40;
  char local_38 [9];
  undefined6 uStack_2f;
  undefined1 uStack_29;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
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
    iVar2 = ___ratelimit(wcd938x_variant_read__rs,"wcd938x_variant_read");
    if (iVar2 == 0) {
      uVar4 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0011c2d3,"wcd938x_variant_read");
      uVar4 = 0xffffffffffffffea;
    }
    goto LAB_00102cc8;
  }
  iVar2 = *(int *)(*(long *)(param_1 + 0x40) + 8);
  if (iVar2 == 5) {
    pcVar3 = "WCD9385\n";
LAB_00102c80:
    uVar4 = 8;
    local_38[8] = '\0';
    local_38._0_7_ = SUB87(*(undefined8 *)pcVar3,0);
    local_38[7] = (char)((ulong)*(undefined8 *)pcVar3 >> 0x38);
  }
  else {
    if (iVar2 == 0) {
      pcVar3 = "WCD9380\n";
      goto LAB_00102c80;
    }
    uVar4 = 0xe;
    local_38._0_7_ = s_VER_UNDEFINED_0011bb7f._0_7_;
    local_38[7] = s_VER_UNDEFINED_0011bb7f[7];
    local_38[8] = s_VER_UNDEFINED_0011bb7f[8];
    uStack_2f = s_VER_UNDEFINED_0011bb7f._9_6_;
  }
  uVar4 = simple_read_from_buffer(param_4,param_5,&local_40,local_38,uVar4);
LAB_00102cc8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_probe @ 00102d10 size=2032
// signature: undefined wcd938x_probe(void)
// callers: []
//------------------------------------------------------------

uint wcd938x_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
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
  plVar7 = (long *)devm_kmalloc(lVar1,0xcd0,0xdc0);
  if (plVar7 == (long *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_00103480;
  }
  *(long **)(param_1 + 0xa8) = plVar7;
  *plVar7 = lVar1;
  plVar8 = (long *)wcd938x_populate_dt_data(lVar1);
  if (plVar8 == (long *)0x0) {
    pcVar10 = "%s: Fail to obtain platform data\n";
    goto LAB_001033c4;
  }
  *(long **)(param_1 + 0xa0) = plVar8;
  plVar7[3] = *plVar8;
  uVar4 = msm_cdc_init_supplies(lVar1,plVar7 + 0x182,plVar8[7],(int)plVar8[8]);
  if (plVar7[0x182] == 0) {
    pcVar10 = "%s: Cannot init wcd supplies\n";
LAB_001033e8:
    _dev_err(lVar1,pcVar10,"wcd938x_probe");
    goto LAB_00103480;
  }
  plVar12 = *(long **)(*(long *)(param_1 + 0x70) + 0x90);
  if (plVar12 == (long *)0x0) {
    pcVar10 = "%s: platform data from parent is NULL\n";
  }
  else {
    lVar13 = *plVar12;
    plVar7[0x186] = lVar13;
    if (lVar13 == 0) {
      pcVar10 = "%s: handle is NULL\n";
    }
    else {
      lVar13 = plVar12[1];
      plVar7[0x187] = lVar13;
      if (lVar13 == 0) {
        pcVar10 = "%s: update_wcd_event api is null!\n";
      }
      else {
        lVar13 = plVar12[2];
        plVar7[0x188] = lVar13;
        if (lVar13 != 0) {
          uVar4 = msm_cdc_enable_static_supplies(lVar1,plVar7[0x182],plVar8[7],(int)plVar8[8]);
          if (uVar4 != 0) {
            pcVar10 = "%s: wcd static supply enable failed!\n";
            goto LAB_001033e8;
          }
          uVar5 = wcd938x_parse_port_mapping(lVar1,"qcom,rx_swr_ch_map",1);
          uVar4 = wcd938x_parse_port_mapping(lVar1,"qcom,tx_swr_ch_map",0);
          uVar4 = uVar4 | uVar5;
          if (uVar4 == 0) {
            lVar15 = *(long *)(param_1 + 0xa8);
            local_a8[0] = local_a8[0] & 0xffffffff00000000;
            lVar13 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-tx-port-params",
                                      local_a8);
            uVar2 = local_a8[0];
            if (lVar13 == 0) {
              pcVar10 = "missing port mapping prop %s\n";
              pcVar11 = "qcom,swr-tx-port-params";
LAB_0010342c:
              _dev_err(lVar1,pcVar10,pcVar11);
              uVar4 = 0xffffffea;
            }
            else {
              uVar5 = (uint)local_a8[0];
              if (((uint)local_a8[0] & 0xffffffe0) != 0x80) {
                pcVar10 = "%s: port params not provided for all usecases\n";
                pcVar11 = "wcd938x_parse_port_params";
                goto LAB_0010342c;
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
                  if (uVar5 < 4) {
LAB_001034f8:
                    /* WARNING: Does not return */
                    pcVar3 = (code *)SoftwareBreakpoint(1,0x1034fc);
                    (*pcVar3)();
                  }
                  *(undefined4 *)(lVar15 + 0xb6c) = *puVar9;
                  if (((((((uVar2 & 0xfffffffc) == 4) ||
                         (*(undefined4 *)(lVar15 + 0xb70) = puVar9[1], uVar5 < 8)) ||
                        ((uVar2 & 0xfffffffc) == 8)) ||
                       ((*(undefined4 *)(lVar15 + 0xb74) = puVar9[2], uVar5 < 0xc ||
                        ((uVar2 & 0xfffffffc) == 0xc)))) ||
                      (((*(undefined4 *)(lVar15 + 0xb78) = puVar9[3], uVar5 < 0x10 ||
                        (((uVar2 & 0xfffffffc) == 0x10 ||
                         (*(undefined4 *)(lVar15 + 0xb7c) = puVar9[4], uVar5 < 0x14)))) ||
                       ((uVar2 & 0xfffffffc) == 0x14)))) ||
                     ((((*(undefined4 *)(lVar15 + 0xb80) = puVar9[5], uVar5 < 0x18 ||
                        ((uVar2 & 0xfffffffc) == 0x18)) ||
                       (*(undefined4 *)(lVar15 + 0xb84) = puVar9[6], uVar5 < 0x1c)) ||
                      ((uVar2 & 0xfffffffc) == 0x1c)))) goto LAB_001034f8;
                  *(undefined4 *)(lVar15 + 0xb88) = puVar9[7];
                  *(long *)(lVar15 + 0xbf0) = lVar15 + 0xb6c;
                  if (((((uVar5 < 0x20) || ((uVar2 & 0xfffffffc) == 0x20)) ||
                       ((*(undefined4 *)(lVar15 + 0xb8c) = puVar9[8], uVar5 < 0x24 ||
                        (((uVar2 & 0xfffffffc) == 0x24 ||
                         (*(undefined4 *)(lVar15 + 0xb90) = puVar9[9], uVar5 < 0x28)))))) ||
                      ((((uVar2 & 0xfffffffc) == 0x28 ||
                        (((*(undefined4 *)(lVar15 + 0xb94) = puVar9[10], uVar5 < 0x2c ||
                          ((uVar2 & 0xfffffffc) == 0x2c)) ||
                         (*(undefined4 *)(lVar15 + 0xb98) = puVar9[0xb], uVar5 < 0x30)))) ||
                       ((((uVar2 & 0xfffffffc) == 0x30 ||
                         (*(undefined4 *)(lVar15 + 0xb9c) = puVar9[0xc], uVar5 < 0x34)) ||
                        (((uVar2 & 0xfffffffc) == 0x34 ||
                         ((*(undefined4 *)(lVar15 + 0xba0) = puVar9[0xd], uVar5 < 0x38 ||
                          ((uVar2 & 0xfffffffc) == 0x38)))))))))) ||
                     ((*(undefined4 *)(lVar15 + 0xba4) = puVar9[0xe], uVar5 < 0x3c ||
                      ((uVar2 & 0xfffffffc) == 0x3c)))) goto LAB_001034f8;
                  *(undefined4 *)(lVar15 + 0xba8) = puVar9[0xf];
                  *(long *)(lVar15 + 0xbf8) = lVar15 + 0xb8c;
                  if (((((((uVar5 < 0x40) || ((uVar2 & 0xfffffffc) == 0x40)) ||
                         (*(undefined4 *)(lVar15 + 0xbac) = puVar9[0x10], uVar5 < 0x44)) ||
                        (((uVar2 & 0xfffffffc) == 0x44 ||
                         (*(undefined4 *)(lVar15 + 0xbb0) = puVar9[0x11], uVar5 < 0x48)))) ||
                       (((uVar2 & 0xfffffffc) == 0x48 ||
                        ((*(undefined4 *)(lVar15 + 0xbb4) = puVar9[0x12], uVar5 < 0x4c ||
                         ((uVar2 & 0xfffffffc) == 0x4c)))))) ||
                      ((*(undefined4 *)(lVar15 + 3000) = puVar9[0x13], uVar5 < 0x50 ||
                       ((((uVar2 & 0xfffffffc) == 0x50 ||
                         (*(undefined4 *)(lVar15 + 0xbbc) = puVar9[0x14], uVar5 < 0x54)) ||
                        ((uVar2 & 0xfffffffc) == 0x54)))))) ||
                     (((*(undefined4 *)(lVar15 + 0xbc0) = puVar9[0x15], uVar5 < 0x58 ||
                       ((uVar2 & 0xfffffffc) == 0x58)) ||
                      ((*(undefined4 *)(lVar15 + 0xbc4) = puVar9[0x16], uVar5 < 0x5c ||
                       ((uVar2 & 0xfffffffc) == 0x5c)))))) goto LAB_001034f8;
                  *(undefined4 *)(lVar15 + 0xbc8) = puVar9[0x17];
                  *(long *)(lVar15 + 0xc00) = lVar15 + 0xbac;
                  if ((((uVar5 < 0x60) || ((uVar2 & 0xfffffffc) == 0x60)) ||
                      (*(undefined4 *)(lVar15 + 0xbcc) = puVar9[0x18], uVar5 < 100)) ||
                     (((((((uVar2 & 0xfffffffc) == 100 ||
                          (*(undefined4 *)(lVar15 + 0xbd0) = puVar9[0x19], uVar5 < 0x68)) ||
                         ((uVar2 & 0xfffffffc) == 0x68)) ||
                        (((*(undefined4 *)(lVar15 + 0xbd4) = puVar9[0x1a], uVar5 < 0x6c ||
                          ((uVar2 & 0xfffffffc) == 0x6c)) ||
                         ((*(undefined4 *)(lVar15 + 0xbd8) = puVar9[0x1b], uVar5 < 0x70 ||
                          (((uVar2 & 0xfffffffc) == 0x70 ||
                           (*(undefined4 *)(lVar15 + 0xbdc) = puVar9[0x1c], uVar5 < 0x74)))))))) ||
                       ((uVar2 & 0xfffffffc) == 0x74)) ||
                      ((((*(undefined4 *)(lVar15 + 0xbe0) = puVar9[0x1d], uVar5 < 0x78 ||
                         ((uVar2 & 0xfffffffc) == 0x78)) ||
                        (*(undefined4 *)(lVar15 + 0xbe4) = puVar9[0x1e], uVar5 < 0x7c)) ||
                       ((uVar2 & 0xfffffffc) == 0x7c)))))) goto LAB_001034f8;
                  *(undefined4 *)(lVar15 + 0xbe8) = puVar9[0x1f];
                  *(long *)(lVar15 + 0xc08) = lVar15 + 0xbcc;
                  kfree(puVar9);
                  __mutex_init(plVar7 + 0x13,"&wcd938x->wakeup_lock",&wcd938x_probe___key);
                  __mutex_init(plVar7 + 0xd,"&wcd938x->micb_lock",&wcd938x_probe___key_73);
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
                  iVar6 = __of_parse_phandle_with_args(uVar14,"qcom,rx-slave",0,0,0,local_a8);
                  if ((iVar6 == 0) && (local_a8[0] != 0)) {
                    component_match_add_release
                              (lVar1,&local_b0,wcd938x_release_of,wcd938x_compare_of);
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
                    iVar6 = __of_parse_phandle_with_args(uVar14,"qcom,tx-slave",0,0,0,local_a8);
                    if ((iVar6 == 0) && (local_a8[0] != 0)) {
                      component_match_add_release
                                (lVar1,&local_b0,wcd938x_release_of,wcd938x_compare_of);
                      iVar6 = wcd938x_reset(lVar1);
                      if (iVar6 == -0x205) {
                        _dev_err(lVar1,"%s: wcd reset failed!\n","wcd938x_probe");
                        uVar4 = 0xfffffdfb;
                      }
                      else {
                        plVar7[0x189] = (long)wcd938x_wakeup;
                        uVar4 = component_master_add_with_match(lVar1,&wcd938x_comp_ops,local_b0);
                      }
                      goto LAB_00103480;
                    }
                    iVar6 = ___ratelimit(wcd938x_add_slave_components__rs_83,
                                         "wcd938x_add_slave_components");
                    if (iVar6 != 0) {
                      pcVar10 = "%s: Tx-slave node not defined\n";
                      goto LAB_001034e0;
                    }
                  }
                  else {
                    iVar6 = ___ratelimit(wcd938x_add_slave_components__rs,
                                         "wcd938x_add_slave_components");
                    if (iVar6 != 0) {
                      pcVar10 = "%s: Rx-slave node not defined\n";
LAB_001034e0:
                      _dev_err(lVar1,pcVar10,"wcd938x_add_slave_components");
                      uVar4 = 0xffffffed;
                      goto LAB_00103480;
                    }
                  }
                  uVar4 = 0xffffffed;
                  goto LAB_00103480;
                }
                _dev_err(lVar1,"%s: Failed to read  port mapping from prop %s\n",
                         "wcd938x_parse_port_params","qcom,swr-tx-port-params");
                kfree(puVar9);
              }
            }
            pcVar10 = "Failed to read port params\n";
          }
          else {
            pcVar10 = "Failed to read port mapping\n";
          }
          _dev_err(lVar1,pcVar10);
          goto LAB_00103480;
        }
        pcVar10 = "%s: register_notifier api is null!\n";
      }
    }
  }
LAB_001033c4:
  _dev_err(lVar1,pcVar10,"wcd938x_probe");
  uVar4 = 0xffffffea;
LAB_00103480:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd938x_remove @ 00103504 size=60
// signature: undefined wcd938x_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_remove(long param_1)

{
  component_master_del(param_1 + 0x10,&wcd938x_comp_ops);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// wcd938x_parse_port_mapping @ 00103540 size=552
// signature: undefined wcd938x_parse_port_mapping(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

int wcd938x_parse_port_mapping(long param_1,undefined8 param_2,char param_3)

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
    lVar10 = lVar5 + 0x16c;
    puVar6 = (undefined1 *)(lVar5 + 0x168);
  }
  else {
    if (param_3 != '\x01') {
      _dev_err(param_1,"%s Invalid path selected %u\n","wcd938x_parse_port_mapping",param_3);
      local_84 = -0x16;
      goto LAB_001036a0;
    }
    lVar10 = lVar5 + 0x66c;
    puVar6 = (undefined1 *)(lVar5 + 0x169);
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
                 "wcd938x_parse_port_mapping",param_2);
LAB_00103758:
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
              _dev_err(param_1,"%s: Invalid port or channel number\n","wcd938x_parse_port_mapping");
              goto LAB_00103758;
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
LAB_001036a0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_84;
}



//------------------------------------------------------------
// wcd938x_reset @ 00103768 size=296
// signature: undefined wcd938x_reset(void)
// callers: [wcd938x_event_notify, wcd938x_probe]
//------------------------------------------------------------

undefined8 wcd938x_reset(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 == 0) {
    return 0xffffffea;
  }
  if (*(long *)(lVar3 + 0x18) == 0) {
    iVar1 = ___ratelimit(wcd938x_reset__rs,"wcd938x_reset");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    _dev_err(param_1,"%s: reset gpio device node not specified\n","wcd938x_reset");
    return 0xffffffea;
  }
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
    iVar1 = ___ratelimit(wcd938x_reset__rs_88,"wcd938x_reset");
    if (iVar1 == 0) {
      return 0xfffffdfb;
    }
    pcVar2 = "%s: wcd active state request fail!\n";
  }
  else {
    iVar1 = ___ratelimit(wcd938x_reset__rs_86,"wcd938x_reset");
    if (iVar1 == 0) {
      return 0xfffffdfb;
    }
    pcVar2 = "%s: wcd sleep state request fail!\n";
  }
  _dev_err(param_1,pcVar2,"wcd938x_reset");
  return 0xfffffdfb;
}



//------------------------------------------------------------
// wcd938x_release_of @ 00103894 size=4
// signature: undefined wcd938x_release_of(void)
// callers: []
//------------------------------------------------------------

void wcd938x_release_of(void)

{
  return;
}



//------------------------------------------------------------
// wcd938x_compare_of @ 0010389c size=16
// signature: undefined wcd938x_compare_of(void)
// callers: []
//------------------------------------------------------------

bool wcd938x_compare_of(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x2e8) == param_2;
}



//------------------------------------------------------------
// wcd938x_bind @ 001038b0 size=1452
// signature: undefined wcd938x_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wcd938x_bind(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 *puVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  lVar2 = *(long *)(param_1 + 0x90);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  usleep_range_state(5000,0x1392,2);
  iVar4 = component_bind_all(param_1,puVar3);
  if (iVar4 != 0) {
    iVar5 = ___ratelimit(wcd938x_bind__rs,"wcd938x_bind");
    if (iVar5 == 0) {
      return iVar4;
    }
    _dev_err(param_1,"%s: Slave bind failed, ret = %d\n","wcd938x_bind",iVar4);
    return iVar4;
  }
  lVar6 = get_matching_swr_slave_device(*(undefined8 *)(lVar2 + 8));
  puVar3[5] = lVar6;
  if (lVar6 == 0) {
    iVar4 = ___ratelimit(wcd938x_bind__rs_91,"wcd938x_bind");
    if (iVar4 != 0) {
      pcVar7 = "%s: Could not find RX swr slave device\n";
LAB_00103d58:
      _dev_err(param_1,pcVar7,"wcd938x_bind");
      iVar4 = -0x13;
      goto LAB_00103a70;
    }
  }
  else {
    lVar6 = get_matching_swr_slave_device(*(undefined8 *)(lVar2 + 0x10));
    puVar3[6] = lVar6;
    if (lVar6 != 0) {
      swr_init_port_params(lVar6,4,puVar3 + 0x17e);
      lVar6 = __devm_regmap_init_swr(puVar3[6],&wcd938x_regmap_config,0,0);
      puVar3[4] = lVar6;
      if (lVar6 == 0) {
        iVar4 = ___ratelimit(wcd938x_bind__rs_95,"wcd938x_bind");
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          _dev_err(param_1,"%s: Regmap init failed\n","wcd938x_bind");
          iVar4 = 0;
        }
        goto LAB_00103a70;
      }
      if (0 < _DAT_00118c78) {
        iVar4 = 0;
        do {
          regmap_write(puVar3[4],iVar4 + 0x3474,0);
          iVar4 = iVar4 + 1;
        } while (iVar4 < _DAT_00118c78);
      }
      puVar1 = puVar3 + 0x26;
      _DAT_00118cc8 = puVar3;
      puVar3[0x26] = &wcd938x_regmap_irq_chip;
      puVar3[0x27] = "WCD938X";
      puVar3[0x2a] = param_1;
      puVar3[0x28] = puVar3[4];
      iVar4 = wcd_irq_init(puVar1,puVar3 + 0x25);
      if (iVar4 != 0) {
        iVar5 = ___ratelimit(wcd938x_bind__rs_98,"wcd938x_bind");
        if (iVar5 != 0) {
          _dev_err(*puVar3,"%s: IRQ init failed: %d\n","wcd938x_bind",iVar4);
        }
        goto LAB_00103a70;
      }
      *(undefined8 *)(puVar3[6] + 1000) = puVar3[0x25];
      if (lVar2 == 0) {
        _dev_err(*puVar3,"%s: NULL pdata\n","wcd938x_set_micbias_data");
        iVar4 = -0x13;
LAB_00103dac:
        iVar5 = ___ratelimit(wcd938x_bind__rs_100,"wcd938x_bind");
        if (iVar5 != 0) {
          pcVar7 = "%s: bad micbias pdata\n";
LAB_00103ddc:
          _dev_err(param_1,pcVar7,"wcd938x_bind");
        }
      }
      else {
        if (*(int *)(lVar2 + 0x20) - 0xb23U < 0xfffff8c5) {
          iVar4 = ___ratelimit(wcd938x_get_micb_vout_ctl_val__rs,"wcd938x_get_micb_vout_ctl_val");
          if (iVar4 == 0) {
            uVar8 = 0xffffffea;
          }
          else {
            _printk(&DAT_0011c02c,"wcd938x_get_micb_vout_ctl_val");
            uVar8 = 0xffffffea;
          }
        }
        else {
          uVar8 = (*(int *)(lVar2 + 0x20) - 1000U >> 1 & 0x7fff) / 0x19;
        }
        if (*(int *)(lVar2 + 0x24) - 0xb23U < 0xfffff8c5) {
          iVar4 = ___ratelimit(wcd938x_get_micb_vout_ctl_val__rs,"wcd938x_get_micb_vout_ctl_val");
          if (iVar4 == 0) {
            uVar9 = 0xffffffea;
          }
          else {
            _printk(&DAT_0011c02c,"wcd938x_get_micb_vout_ctl_val");
            uVar9 = 0xffffffea;
          }
        }
        else {
          uVar9 = (*(int *)(lVar2 + 0x24) - 1000U >> 1 & 0x7fff) / 0x19;
        }
        if (*(int *)(lVar2 + 0x28) - 0xb23U < 0xfffff8c5) {
          iVar4 = ___ratelimit(wcd938x_get_micb_vout_ctl_val__rs,"wcd938x_get_micb_vout_ctl_val");
          if (iVar4 == 0) {
            uVar10 = 0xffffffea;
          }
          else {
            _printk(&DAT_0011c02c,"wcd938x_get_micb_vout_ctl_val");
            uVar10 = 0xffffffea;
          }
        }
        else {
          uVar10 = (*(int *)(lVar2 + 0x28) - 1000U >> 1 & 0x7fff) / 0x19;
        }
        if (0xfffff8c4 < *(int *)(lVar2 + 0x2c) - 0xb23U) {
          uVar11 = (*(int *)(lVar2 + 0x2c) - 1000U >> 1 & 0x7fff) / 0x19;
          iVar4 = -0x16;
          if (-1 < (int)uVar8) goto LAB_00103bf0;
          goto LAB_00103dac;
        }
        iVar4 = ___ratelimit(wcd938x_get_micb_vout_ctl_val__rs,"wcd938x_get_micb_vout_ctl_val");
        if (iVar4 != 0) {
          _printk(&DAT_0011c02c,"wcd938x_get_micb_vout_ctl_val");
        }
        uVar11 = 0xffffffea;
        iVar4 = -0x16;
        if ((int)uVar8 < 0) goto LAB_00103dac;
LAB_00103bf0:
        iVar4 = -0x16;
        if ((((int)uVar9 < 0) || ((int)uVar10 < 0)) || ((int)uVar11 < 0)) goto LAB_00103dac;
        regmap_update_bits_base(puVar3[4],0x3022,0x3f,uVar8,0,0,0);
        regmap_update_bits_base(puVar3[4],0x3023,0x3f,uVar9,0,0,0);
        regmap_update_bits_base(puVar3[4],0x3025,0x3f,uVar10,0,0,0);
        regmap_update_bits_base(puVar3[4],0x3026,0x3f,uVar11,0,0,0);
        wcd_request_irq(puVar1,0xe,"HPHR PDM WD INT",wcd938x_wd_handle_irq,0);
        wcd_request_irq(puVar1,0xd,"HPHL PDM WD INT",wcd938x_wd_handle_irq,0);
        wcd_request_irq(puVar1,0xf,"AUX PDM WD INT",wcd938x_wd_handle_irq,0);
        wcd_disable_irq(puVar1,0xe);
        wcd_disable_irq(puVar1,0xd);
        wcd_disable_irq(puVar1,0xf);
        iVar4 = snd_soc_register_component(param_1,&soc_codec_dev_wcd938x,&wcd938x_dai,1);
        if (iVar4 == 0) {
          *(undefined1 *)(puVar3 + 399) = 1;
          return 0;
        }
        iVar5 = ___ratelimit(wcd938x_bind__rs_105,"wcd938x_bind");
        if (iVar5 != 0) {
          pcVar7 = "%s: Codec registration failed\n";
          goto LAB_00103ddc;
        }
      }
      wcd_irq_exit(puVar1,puVar3[0x25]);
      goto LAB_00103a70;
    }
    iVar4 = ___ratelimit(wcd938x_bind__rs_93,"wcd938x_bind");
    if (iVar4 != 0) {
      pcVar7 = "%s: Could not find TX swr slave device\n";
      goto LAB_00103d58;
    }
  }
  iVar4 = -0x13;
LAB_00103a70:
  component_unbind_all(param_1,puVar3);
  return iVar4;
}



//------------------------------------------------------------
// wcd938x_unbind @ 00103e60 size=132
// signature: undefined wcd938x_unbind(void)
// callers: []
//------------------------------------------------------------

void wcd938x_unbind(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  lVar1 = lVar2 + 0x130;
  wcd_free_irq(lVar1,0xe,0);
  wcd_free_irq(lVar1,0xd,0);
  wcd_free_irq(lVar1,0xf,0);
  wcd_irq_exit(lVar1,*(undefined8 *)(lVar2 + 0x128));
  snd_soc_unregister_component(param_1);
  component_unbind_all(param_1,lVar2);
  return;
}



//------------------------------------------------------------
// wcd938x_wd_handle_irq @ 00103ee8 size=92
// signature: undefined wcd938x_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wcd938x_wd_handle_irq__rs,"wcd938x_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_0011afe8,"wcd938x_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wcd938x_handle_post_irq @ 00103f48 size=184
// signature: undefined wcd938x_handle_post_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_handle_post_irq(long param_1)

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
// wcd938x_soc_codec_probe @ 00104004 size=1008
// signature: undefined wcd938x_soc_codec_probe(void)
// callers: []
//------------------------------------------------------------

int wcd938x_soc_codec_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  int iVar9;
  code *pcVar10;
  long lVar11;
  
  _dev_info(*(undefined8 *)(param_1 + 0x18),"%s()\n","wcd938x_soc_codec_probe");
  lVar11 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar11 == 0) {
    return -0x16;
  }
  *(long *)(lVar11 + 0x10) = param_1;
  snd_soc_component_init_regmap(param_1,*(undefined8 *)(lVar11 + 0x20));
  devm_regmap_qti_debugfs_register(*(long *)(lVar11 + 0x30) + 0x48,*(undefined8 *)(lVar11 + 0x20));
  uVar4 = snd_soc_component_read(param_1,0x34b0);
  *(uint *)(lVar11 + 8) = uVar4 >> 1 & 0xf;
  lVar6 = devm_kmalloc(*(undefined8 *)(param_1 + 0x18),0x78,0xdc0);
  *(long *)(lVar11 + 0x58) = lVar6;
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
  iVar5 = wcd_cal_create_hwdep(*(undefined8 *)(lVar11 + 0x58),1000,param_1);
  if (iVar5 < 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x18);
    pcVar8 = "%s hwdep failed %d\n";
    iVar9 = iVar5;
    goto LAB_001043b8;
  }
  iVar5 = wcd938x_mbhc_init(lVar11 + 0x100,param_1,*(undefined8 *)(lVar11 + 0x58));
  if (iVar5 != 0) {
    _printk(&DAT_0011b458,"wcd938x_soc_codec_probe");
    *(undefined8 *)(lVar11 + 0x58) = 0;
    return iVar5;
  }
  lVar6 = param_1 + 0xd0;
  snd_soc_dapm_ignore_suspend(lVar6,"WCD938X_AIF Playback");
  snd_soc_dapm_ignore_suspend(lVar6,"WCD938X_AIF Capture");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC1");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC2");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC3");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC4");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC5");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC6");
  snd_soc_dapm_ignore_suspend(lVar6,"AMIC7");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC1");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC2");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC3");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC4");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC5");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC6");
  snd_soc_dapm_ignore_suspend(lVar6,"VA AMIC7");
  snd_soc_dapm_ignore_suspend(lVar6,"WCD_TX_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar6,"IN1_HPHL");
  snd_soc_dapm_ignore_suspend(lVar6,"IN2_HPHR");
  snd_soc_dapm_ignore_suspend(lVar6,"IN3_AUX");
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_0011af0b);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_0011bbe1);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_0011b2d7);
  snd_soc_dapm_ignore_suspend(lVar6,&DAT_0011aa16);
  snd_soc_dapm_ignore_suspend(lVar6,"WCD_TX_DUMMY");
  snd_soc_dapm_ignore_suspend(lVar6,"WCD_RX_DUMMY");
  snd_soc_dapm_sync(lVar6);
  wcd_cls_h_init(lVar11 + 0xe0);
  wcd938x_init_reg(param_1);
  iVar9 = *(int *)(lVar11 + 8);
  if (iVar9 == 0) {
    iVar5 = snd_soc_add_component_controls(param_1,wcd9380_snd_controls,6);
    if (-1 < iVar5) {
      iVar9 = *(int *)(lVar11 + 8);
      goto joined_r0x001042c4;
    }
  }
  else {
    iVar5 = 0;
joined_r0x001042c4:
    if ((iVar9 != 5) ||
       (iVar5 = snd_soc_add_component_controls(param_1,wcd9385_snd_controls,6), -1 < iVar5)) {
      pcVar10 = *(code **)(lVar11 + 0xc40);
      *(undefined4 *)(lVar11 + 0xc50) = 1;
      *(code **)(lVar11 + 0xc18) = wcd938x_event_notify;
      if (pcVar10 == (code *)0x0) {
        return iVar5;
      }
      if (*(int *)(pcVar10 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x104324);
        (*pcVar10)();
      }
      iVar5 = (*pcVar10)(*(undefined8 *)(lVar11 + 0xc30),lVar11 + 0xc18,1);
      if (iVar5 == 0) {
        return 0;
      }
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Failed to register notifier %d\n",
               "wcd938x_soc_codec_probe",iVar5);
      return iVar5;
    }
  }
  uVar7 = *(undefined8 *)(param_1 + 0x18);
  pcVar8 = "%s: Failed to add snd ctrls for variant: %d\n";
  iVar9 = *(int *)(lVar11 + 8);
LAB_001043b8:
  _dev_err(uVar7,pcVar8,"wcd938x_soc_codec_probe",iVar9);
  *(undefined8 *)(lVar11 + 0x58) = 0;
  return iVar5;
}



//------------------------------------------------------------
// wcd938x_soc_codec_remove @ 00104404 size=108
// signature: undefined wcd938x_soc_codec_remove(void)
// callers: []
//------------------------------------------------------------

void wcd938x_soc_codec_remove(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar2 == 0) {
    _dev_err(*(long *)(param_1 + 0x18),"%s: wcd938x is already NULL\n","wcd938x_soc_codec_remove");
  }
  else {
    pcVar1 = *(code **)(lVar2 + 0xc40);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104448);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(lVar2 + 0xc30),lVar2 + 0xc18,0);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd938x_soc_codec_suspend @ 00104474 size=28
// signature: undefined wcd938x_soc_codec_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_soc_codec_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x124) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_soc_codec_resume @ 00104494 size=24
// signature: undefined wcd938x_soc_codec_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_soc_codec_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x124) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_get_compander @ 001044b0 size=44
// signature: undefined wcd938x_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_get_compander(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0x120;
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) != 0) {
    lVar1 = 0x121;
  }
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + lVar1);
  return 0;
}



//------------------------------------------------------------
// wcd938x_set_compander @ 001044e0 size=56
// signature: undefined wcd938x_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_set_compander(long param_1,long param_2)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = *(int *)(param_2 + 0x48) != 0;
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) == 0) {
    *(bool *)(lVar2 + 0x120) = bVar1;
    return 0;
  }
  *(bool *)(lVar2 + 0x121) = bVar1;
  return 0;
}



//------------------------------------------------------------
// wcd938x_ldoh_get @ 0010451c size=28
// signature: undefined wcd938x_ldoh_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_ldoh_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x122);
  return 0;
}



//------------------------------------------------------------
// wcd938x_ldoh_put @ 0010453c size=36
// signature: undefined wcd938x_ldoh_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_ldoh_put(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x122) =
       *(long *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wcd938x_bcs_get @ 00104564 size=28
// signature: undefined wcd938x_bcs_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_bcs_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x123);
  return 0;
}



//------------------------------------------------------------
// wcd938x_bcs_put @ 00104584 size=36
// signature: undefined wcd938x_bcs_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_bcs_put(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x123) =
       *(long *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wcd938x_tx_master_ch_get @ 001045ac size=176
// signature: undefined wcd938x_tx_master_ch_get(void)
// callers: []
//------------------------------------------------------------

void wcd938x_tx_master_ch_get(long param_1,long param_2)

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
    wcd938x_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if (local_2c < 0xd) {
      uVar2 = 0;
      uVar1 = *(byte *)(lVar3 + (ulong)local_2c + 0xc79) - 0x2d;
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
// wcd938x_tx_master_ch_put @ 00104660 size=180
// signature: undefined wcd938x_tx_master_ch_put(void)
// callers: []
//------------------------------------------------------------

void wcd938x_tx_master_ch_put(long param_1,long param_2)

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
    wcd938x_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if ((local_2c < 0xd) && (*(uint *)(param_2 + 0x48) < 0xf)) {
      uVar1 = 0;
      *(char *)(lVar2 + (ulong)local_2c + 0xc79) =
           (char)*(undefined4 *)(swr_master_ch_map + (ulong)*(uint *)(param_2 + 0x48) * 4);
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
// wcd938x_tx_get_slave_ch_type_idx @ 00104714 size=528
// signature: undefined wcd938x_tx_get_slave_ch_type_idx(void)
// callers: [wcd938x_tx_master_ch_put, wcd938x_tx_master_ch_get]
//------------------------------------------------------------

void wcd938x_tx_get_slave_ch_type_idx(undefined8 param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = strnstr(param_1,&DAT_0011b661,5);
  if (lVar2 == 0) {
    lVar2 = strnstr(param_1,&DAT_0011be2b,5);
    if (lVar2 == 0) {
      lVar2 = strnstr(param_1,&DAT_0011bd1b,5);
      if (lVar2 == 0) {
        lVar2 = strnstr(param_1,&DAT_0011bbb5,5);
        if (lVar2 == 0) {
          lVar2 = strnstr(param_1,"DMIC0",6);
          if (lVar2 == 0) {
            lVar2 = strnstr(param_1,"DMIC1",6);
            if (lVar2 == 0) {
              lVar2 = strnstr(param_1,&DAT_0011a95e,5);
              if (lVar2 == 0) {
                lVar2 = strnstr(param_1,"DMIC2",6);
                if (lVar2 == 0) {
                  lVar2 = strnstr(param_1,"DMIC3",6);
                  if (lVar2 == 0) {
                    lVar2 = strnstr(param_1,"DMIC4",6);
                    if (lVar2 == 0) {
                      lVar2 = strnstr(param_1,"DMIC5",6);
                      if (lVar2 == 0) {
                        lVar2 = strnstr(param_1,"DMIC6",6);
                        if (lVar2 == 0) {
                          lVar2 = strnstr(param_1,"DMIC7",6);
                          if (lVar2 == 0) {
                            iVar1 = ___ratelimit(wcd938x_tx_get_slave_ch_type_idx__rs,
                                                 "wcd938x_tx_get_slave_ch_type_idx");
                            if (iVar1 != 0) {
                              _printk(&DAT_0011bae2,"wcd938x_tx_get_slave_ch_type_idx",param_1);
                            }
                            uVar3 = 0xffffffea;
                            goto LAB_001048d4;
                          }
                          lVar2 = 0xc;
                        }
                        else {
                          lVar2 = 0xb;
                        }
                      }
                      else {
                        lVar2 = 10;
                      }
                    }
                    else {
                      lVar2 = 9;
                    }
                  }
                  else {
                    lVar2 = 8;
                  }
                }
                else {
                  lVar2 = 7;
                }
              }
              else {
                lVar2 = 6;
              }
            }
            else {
              lVar2 = 5;
            }
          }
          else {
            lVar2 = 4;
          }
        }
        else {
          lVar2 = 3;
        }
      }
      else {
        lVar2 = 2;
      }
    }
    else {
      lVar2 = 1;
    }
  }
  else {
    lVar2 = 0;
  }
  uVar3 = (uint)(byte)swr_slv_tx_ch_idx[lVar2 * 2 + 1];
LAB_001048d4:
  *param_2 = uVar3;
  return;
}



//------------------------------------------------------------
// wcd938x_codec_enable_adc @ 00104928 size=976
// signature: undefined wcd938x_codec_enable_adc(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_codec_enable_adc(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  uint local_6c;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 auStack_60 [4];
  undefined1 local_5c [4];
  long local_58;
  
  lVar13 = sp_el0;
  local_58 = *(long *)(lVar13 + 0x638);
  lVar15 = *(long *)(param_1 + 0x28);
  local_6c = 0;
  lVar13 = lVar15 + -0xd0;
  lVar14 = *(long *)(*(long *)(lVar15 + -0xb8) + 0x98);
  iVar6 = swr_read(*(long *)(lVar14 + 0x30),*(undefined1 *)(*(long *)(lVar14 + 0x30) + 0x40),0x44,
                   &local_6c,1);
  bVar3 = iVar6 == 0;
  bVar4 = (local_6c & 0x40) == 0;
  if (param_3 == 8) {
    iVar6 = *(int *)(lVar14 + 0x11c) + -1;
    if (iVar6 < 1) {
      iVar6 = 0;
    }
    *(int *)(lVar14 + 0x11c) = iVar6;
    wcd938x_tx_connect_port(lVar13,*(byte *)(param_1 + 0x4c) + 0x1e,0,0);
    uVar7 = 0;
    if (*(char *)(param_1 + 0x4c) == '\x01') {
      if (((uint)*(undefined8 *)(lVar14 + 0x160) >> 7 & 1) != 0) {
        lVar15 = *(long *)(*(long *)(lVar15 + -0xb8) + 0x98);
        local_5c[0] = 0;
        local_64[0] = 0;
        iVar6 = wcd938x_set_port_params
                          (lVar13,0x1d,local_5c,auStack_60,local_64,&local_6c,local_68,0);
        if (iVar6 == 0) {
          local_68[0] = *(undefined1 *)(lVar15 + 0xc7f);
          swr_disconnect_port(*(undefined8 *)(lVar15 + 0x30),local_5c,1,local_64,local_68);
        }
        puVar1 = (ulong *)(lVar14 + 0x160);
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
      uVar7 = 0;
    }
    goto LAB_00104ca4;
  }
  uVar7 = 0;
  if (param_3 != 1) goto LAB_00104ca4;
  iVar6 = *(int *)(lVar14 + 0x11c) + 1;
  *(int *)(lVar14 + 0x11c) = iVar6;
  if (((*(ulong *)(lVar14 + 0x160) & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar14 + 0x160) >> 9 & 1) == 0)) {
    uVar10 = 0;
    if (((uint)*(undefined8 *)(lVar14 + 0x160) >> 1 & 1) != 0) goto LAB_00104ab8;
LAB_00104ab0:
    if (((uint)*(undefined8 *)(lVar14 + 0x160) >> 10 & 1) != 0) goto LAB_00104ab8;
  }
  else {
    if (6 < *(uint *)(lVar14 + 0x10c)) goto LAB_00104cdc;
    uVar10 = (uint)*(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x10c));
    if (((uint)*(undefined8 *)(lVar14 + 0x160) >> 1 & 1) == 0) goto LAB_00104ab0;
LAB_00104ab8:
    if (6 < *(uint *)(lVar14 + 0x110)) goto LAB_00104cdc;
    uVar10 = uVar10 | *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x110));
  }
  if ((((uint)*(undefined8 *)(lVar14 + 0x160) >> 2 & 1) != 0) ||
     (((uint)*(undefined8 *)(lVar14 + 0x160) >> 0xb & 1) != 0)) {
    if (6 < *(uint *)(lVar14 + 0x114)) goto LAB_00104cdc;
    uVar10 = uVar10 | *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x114));
  }
  if ((((uint)*(undefined8 *)(lVar14 + 0x160) >> 3 & 1) != 0) ||
     (((uint)*(undefined8 *)(lVar14 + 0x160) >> 0xc & 1) != 0)) {
    if (6 < *(uint *)(lVar14 + 0x118)) {
LAB_00104cdc:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x104ce0);
      (*pcVar5)();
    }
    uVar10 = uVar10 | *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x118));
  }
  if (uVar10 == 0) {
    iVar12 = 9600000;
  }
  else {
    iVar12 = 9600000;
    if ((uVar10 & 7) == 0) {
      if ((uVar10 >> 3 & 1) == 0) {
        iVar12 = 600000;
        if ((uVar10 & 0x10) != 0) {
          iVar12 = 1200000;
        }
      }
      else {
        iVar12 = 4800000;
      }
    }
  }
  iVar12 = iVar12 * iVar6;
  if (9599999 < iVar12) {
    iVar12 = 9600000;
  }
  if (iVar12 < 2400000) {
    if (iVar12 == 600000) {
      uVar8 = 0x60;
      uVar7 = 6;
    }
    else {
      if (iVar12 != 1200000) goto LAB_00104bf8;
      uVar8 = 0x50;
      uVar7 = 5;
    }
LAB_00104c50:
    uVar9 = uVar7;
    if (bVar3 && bVar4) {
      uVar9 = uVar8;
    }
    uVar11 = 0xf;
    if (bVar3 && bVar4) {
      uVar11 = 0xf0;
      uVar8 = uVar7;
    }
LAB_00104c6c:
    snd_soc_component_update_bits(lVar13,0x3405,uVar11,uVar9);
    uVar7 = swr_slvdev_datapath_control
                      (*(long *)(lVar14 + 0x30),*(undefined1 *)(*(long *)(lVar14 + 0x30) + 0x40),1);
  }
  else {
    if (iVar12 == 2400000) {
      uVar8 = 0x30;
      uVar7 = 3;
      goto LAB_00104c50;
    }
    if (iVar12 == 4800000) {
      uVar9 = 0x10;
      if (!bVar3 || !bVar4) {
        uVar9 = 1;
      }
      uVar11 = 0xf;
      if (bVar3 && bVar4) {
        uVar11 = 0xf0;
      }
      uVar8 = 0x10;
      if (bVar3 && bVar4) {
        uVar8 = 1;
      }
      goto LAB_00104c6c;
    }
LAB_00104bf8:
    uVar7 = 0xf;
    if (bVar3 && bVar4) {
      uVar7 = 0xf0;
    }
    snd_soc_component_update_bits(lVar13,0x3405,uVar7,0);
    uVar7 = swr_slvdev_datapath_control
                      (*(long *)(lVar14 + 0x30),*(undefined1 *)(*(long *)(lVar14 + 0x30) + 0x40),1);
    uVar8 = 0;
  }
  uVar9 = 0xf0;
  if (bVar3 && bVar4) {
    uVar9 = 0xf;
  }
  snd_soc_component_update_bits(lVar13,0x3405,uVar9,uVar8);
LAB_00104ca4:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// wcd938x_codec_enable_dmic @ 00104d08 size=532
// signature: undefined wcd938x_codec_enable_dmic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_enable_dmic(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  bVar1 = *(byte *)(param_1 + 0x4c);
  lVar8 = *(long *)(param_1 + 0x28);
  if (7 < bVar1) {
    iVar2 = ___ratelimit(wcd938x_codec_enable_dmic__rs,"wcd938x_codec_enable_dmic");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    _dev_err(*(undefined8 *)(lVar8 + -0xb8),"%s: Invalid DMIC Selection\n",
             "wcd938x_codec_enable_dmic");
    return 0xffffffea;
  }
  iVar2 = 0;
  lVar9 = 0;
  lVar7 = 0;
  lVar3 = lVar8 + -0xd0;
  uVar5 = 0xf;
  uVar4 = 0x345c;
  uVar6 = 0x3462;
  switch(bVar1) {
  default:
    goto switchD_00104d68_caseD_0;
  case 2:
    iVar2 = 0x345d;
switchD_00104d68_caseD_3:
    uVar5 = 0xf0;
    lVar7 = 4;
    lVar9 = 1;
    uVar4 = 0x345d;
    if (param_3 == 8) {
LAB_00104e84:
      wcd938x_tx_connect_port(lVar3,bVar1 + 0x22,0,0);
      snd_soc_component_update_bits(lVar3,0x345a,1 << lVar9,1 << lVar9);
      if (iVar2 != 0) {
        snd_soc_component_update_bits(lVar3,iVar2,0x80,0);
      }
      snd_soc_component_update_bits(lVar3,uVar4,8,0);
    }
    else {
LAB_00104da0:
      if (param_3 == 1) {
        lVar8 = *(long *)(*(long *)(lVar8 + -0xb8) + 0x98);
        snd_soc_component_update_bits(lVar3,0x345a,1 << lVar9,0);
        usleep_range_state(0xfa,0x104,2);
        if (iVar2 != 0) {
          snd_soc_component_update_bits(lVar3,iVar2,0x80,0x80);
        }
        snd_soc_component_update_bits(lVar3,uVar6,uVar5,3 << lVar7);
        snd_soc_component_update_bits(lVar3,uVar4,8,8);
        snd_soc_component_update_bits(lVar3,0x345b,6,6);
        lVar8 = *(long *)(lVar8 + 0x30);
        uVar4 = swr_slvdev_datapath_control(lVar8,*(undefined1 *)(lVar8 + 0x40),1);
        return uVar4;
      }
    }
    return 0;
  case 3:
    goto switchD_00104d68_caseD_3;
  case 4:
  case 5:
    lVar7 = 0;
    lVar9 = 2;
    uVar4 = 0x345e;
    goto LAB_00104d94;
  case 6:
  case 7:
    uVar5 = 0xf0;
    lVar7 = 4;
    lVar9 = 3;
    uVar4 = 0x345f;
LAB_00104d94:
    uVar6 = 0x3463;
switchD_00104d68_caseD_0:
    iVar2 = 0;
    if (param_3 == 8) goto LAB_00104e84;
    goto LAB_00104da0;
  }
}



//------------------------------------------------------------
// wcd938x_enable_req @ 00104f20 size=940
// signature: undefined wcd938x_enable_req(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_enable_req(long param_1,undefined8 param_2,int param_3)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  long lVar10;
  
  lVar7 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar10 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 != 8) {
    if (param_3 != 1) {
      return 0;
    }
    snd_soc_component_update_bits(lVar7,0x3408,8,8);
    snd_soc_component_update_bits(lVar7,0x3408,0x10,0x10);
    snd_soc_component_update_bits(lVar7,0x3457,2,2);
    snd_soc_component_update_bits(lVar7,0x3457,1,0);
    bVar1 = *(byte *)(param_1 + 0x4c);
    if (bVar1 < 4) {
      snd_soc_component_update_bits
                (lVar7,*(undefined4 *)(&DAT_0011c73c + (long)(char)bVar1 * 4),
                 *(undefined4 *)(&DAT_0011c72c + (long)(char)bVar1 * 4),
                 *(undefined4 *)(&DAT_0011c72c + (long)(char)bVar1 * 4));
      uVar9 = 0;
    }
    else {
      iVar3 = ___ratelimit(wcd938x_tx_channel_config__rs,"wcd938x_tx_channel_config");
      if (iVar3 != 0) {
        _printk(&DAT_0011bb61,"wcd938x_tx_channel_config",bVar1);
      }
      uVar9 = 0xffffffea;
    }
    if (3 < (ulong)*(byte *)(param_1 + 0x4c)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1052cc);
      (*pcVar2)();
    }
    uVar6 = *(uint *)(lVar10 + (ulong)*(byte *)(param_1 + 0x4c) * 4 + 0x10c);
    if (uVar6 < 7) {
      uVar6 = *(uint *)(&DAT_00116c70 + (long)(int)uVar6 * 4);
    }
    else {
      iVar3 = ___ratelimit(wcd938x_get_adc_mode__rs,"wcd938x_get_adc_mode");
      if (iVar3 != 0) {
        _printk(&DAT_0011c598,"wcd938x_get_adc_mode",uVar6);
      }
      uVar6 = 0xffffffea;
    }
    uVar8 = (ulong)*(byte *)(param_1 + 0x4c);
    switch(uVar8) {
    case 0:
      snd_soc_component_update_bits(lVar7,0x3410,0xf,uVar6 & 0xef);
      uVar4 = 0x10;
      uVar5 = 0x10;
      break;
    case 1:
      snd_soc_component_update_bits(lVar7,0x3410,0xf0,(uVar6 & 0xef) << 4);
      uVar4 = 0x20;
      uVar5 = 0x20;
      break;
    case 2:
      snd_soc_component_update_bits(lVar7,0x3411,0xf,uVar6 & 0xef);
      uVar4 = 0x40;
      uVar5 = 0x40;
      break;
    case 3:
      snd_soc_component_update_bits(lVar7,0x3411,0xf0,(uVar6 & 0xef) << 4);
      uVar4 = 0x80;
      uVar5 = 0x80;
      break;
    default:
      goto switchD_001050b0_default;
    }
    snd_soc_component_update_bits(lVar7,0x3409,uVar4,uVar5);
    uVar8 = (ulong)*(byte *)(param_1 + 0x4c);
switchD_001050b0_default:
    if ((uint)uVar8 < 4) {
      uVar8 = -(uVar8 >> 7) & 0xfffffffffffffc00 | uVar8 << 2;
      snd_soc_component_update_bits
                (lVar7,*(undefined4 *)(&DAT_0011c73c + uVar8),*(undefined4 *)(&DAT_0011c72c + uVar8)
                 ,0);
      return uVar9;
    }
    iVar3 = ___ratelimit(wcd938x_tx_channel_config__rs,"wcd938x_tx_channel_config");
    if (iVar3 != 0) {
      _printk(&DAT_0011bb61,"wcd938x_tx_channel_config",uVar8);
    }
    return 0xffffffea;
  }
  switch(*(undefined1 *)(param_1 + 0x4c)) {
  case 0:
    snd_soc_component_update_bits(lVar7,0x3410,0xf,0);
    uVar9 = 0x10;
    break;
  case 1:
    snd_soc_component_update_bits(lVar7,0x3410,0xf0,0);
    uVar9 = 0x20;
    break;
  case 2:
    snd_soc_component_update_bits(lVar7,0x3411,0xf,0);
    uVar9 = 0x40;
    break;
  case 3:
    snd_soc_component_update_bits(lVar7,0x3411,0xf0,0);
    uVar9 = 0x80;
    break;
  default:
    goto switchD_0010500c_default;
  }
  snd_soc_component_update_bits(lVar7,0x3409,uVar9,0);
switchD_0010500c_default:
  if (*(int *)(lVar10 + 0x11c) == 0) {
    snd_soc_component_update_bits(lVar7,0x3408,0x10,0);
    snd_soc_component_update_bits(lVar7,0x3408,8,0);
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_tx_swr_ctrl @ 001052d0 size=1688
// signature: undefined wcd938x_tx_swr_ctrl(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_tx_swr_ctrl(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  long lVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  uint local_6c;
  undefined1 local_68 [4];
  undefined1 local_64 [4];
  undefined1 local_60 [4];
  undefined1 local_5c [4];
  long local_58;
  
  lVar11 = sp_el0;
  local_58 = *(long *)(lVar11 + 0x638);
  lVar16 = *(long *)(param_1 + 0x28);
  local_6c = 0;
  lVar15 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
  iVar7 = swr_read(*(long *)(lVar15 + 0x30),*(undefined1 *)(*(long *)(lVar15 + 0x30) + 0x40),0x44,
                   &local_6c,1);
  bVar4 = iVar7 != 0;
  bVar5 = (local_6c & 0x40) != 0;
  lVar11 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011b454,4);
  if (lVar11 == 0) {
    iVar7 = 0;
  }
  else {
    uVar14 = (ulong)*(byte *)(param_1 + 0x4c) - 0x1e;
    if (3 < uVar14) goto LAB_001058a8;
    uVar8 = *(int *)(lVar15 + uVar14 * 4 + 0x10c) - 4;
    if (uVar8 < 3) {
      iVar7 = *(int *)(&DAT_00116c8c + (long)(int)uVar8 * 4);
    }
    else {
      iVar7 = 9600000;
    }
  }
  lVar11 = lVar16 + -0xd0;
  if (param_3 != 8) {
    if (param_3 == 1) {
      if (((*(char *)(param_1 + 0x4c) == '\x1f') &&
          (uVar8 = snd_soc_component_read(lVar11,0x3127), (uVar8 >> 7 & 1) == 0)) &&
         (*(char *)(lVar15 + 0x123) == '\0')) {
        lVar16 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
        local_5c[0] = 0;
        local_60[0] = 0;
        local_64[0] = 0;
        iVar9 = wcd938x_set_port_params(lVar11,0x1d,local_5c,local_60,local_64,&local_6c,local_68,0)
        ;
        if (iVar9 == 0) {
          local_6c = 4800000;
          local_68[0] = *(undefined1 *)(lVar16 + 0xc7f);
          swr_connect_port(*(undefined8 *)(lVar16 + 0x30),local_5c,1,local_64,&local_6c,local_60,
                           local_68);
        }
        puVar1 = (ulong *)(lVar15 + 0x160);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 0x80;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011b454,4);
      uVar14 = (ulong)*(byte *)(param_1 + 0x4c);
      if (lVar16 == 0) {
        iVar7 = 2400000;
      }
      else {
        puVar1 = (ulong *)(lVar15 + 0x160 + (uVar14 - 0x1e >> 6 & 0x3ffffff) * 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 1L << (uVar14 - 0x1e & 0x3f);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        uVar14 = (ulong)*(byte *)(param_1 + 0x4c);
      }
      wcd938x_tx_connect_port(lVar11,uVar14,iVar7,1);
      uVar10 = 0;
    }
    else {
      uVar10 = 0;
    }
    goto LAB_00105870;
  }
  lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011b454,4);
  if (lVar16 != 0) {
    lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011b661,5);
    if (lVar16 == 0) {
      lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011be2b,5);
      if (lVar16 == 0) {
        lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011bd1b,5);
        if (lVar16 == 0) {
          lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011bbb5,5);
          if (lVar16 != 0) {
            puVar1 = (ulong *)(lVar15 + 0x160);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = *puVar1 & 0xfffffffffffffff7;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            puVar1 = (ulong *)(lVar15 + 0x160);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = *puVar1 & 0xffffffffffffefff;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
          }
        }
        else {
          puVar1 = (ulong *)(lVar15 + 0x160);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 & 0xfffffffffffffffb;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          puVar1 = (ulong *)(lVar15 + 0x160);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 & 0xfffffffffffff7ff;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
        }
      }
      else {
        puVar1 = (ulong *)(lVar15 + 0x160);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xfffffffffffffffd;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        puVar1 = (ulong *)(lVar15 + 0x160);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xfffffffffffffbff;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
    }
    else {
      puVar1 = (ulong *)(lVar15 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      puVar1 = (ulong *)(lVar15 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffdff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011b454,4);
  if (lVar16 != 0) {
    if (((*(ulong *)(lVar15 + 0x160) & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar15 + 0x160) >> 9 & 1) == 0)) {
      uVar8 = 0;
      if (((uint)*(undefined8 *)(lVar15 + 0x160) >> 1 & 1) != 0) goto LAB_00105628;
LAB_00105620:
      if (((uint)*(undefined8 *)(lVar15 + 0x160) >> 10 & 1) != 0) goto LAB_00105628;
    }
    else {
      if (6 < *(uint *)(lVar15 + 0x10c)) goto LAB_001058a8;
      uVar8 = (uint)*(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x10c));
      if (((uint)*(undefined8 *)(lVar15 + 0x160) >> 1 & 1) == 0) goto LAB_00105620;
LAB_00105628:
      if (6 < *(uint *)(lVar15 + 0x110)) goto LAB_001058a8;
      uVar8 = *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x110)) | uVar8;
    }
    if ((((uint)*(undefined8 *)(lVar15 + 0x160) >> 2 & 1) != 0) ||
       (((uint)*(undefined8 *)(lVar15 + 0x160) >> 0xb & 1) != 0)) {
      if (6 < *(uint *)(lVar15 + 0x114)) goto LAB_001058a8;
      uVar8 = *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x114)) | uVar8;
    }
    if ((((uint)*(undefined8 *)(lVar15 + 0x160) >> 3 & 1) != 0) ||
       (((uint)*(undefined8 *)(lVar15 + 0x160) >> 0xc & 1) != 0)) {
      if (6 < *(uint *)(lVar15 + 0x118)) {
LAB_001058a8:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1058ac);
        (*pcVar6)();
      }
      uVar8 = *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x118)) | uVar8;
    }
    iVar7 = 9600000;
    if ((((uVar8 != 0) && ((uVar8 & 1) == 0)) && ((uVar8 >> 1 & 1) == 0)) && ((uVar8 >> 2 & 1) == 0)
       ) {
      if ((uVar8 >> 3 & 1) == 0) {
        iVar7 = 600000;
        if ((uVar8 & 0x10) != 0) {
          iVar7 = 1200000;
        }
      }
      else {
        iVar7 = 4800000;
      }
    }
    uVar10 = 0;
    iVar9 = *(int *)(lVar15 + 0x11c) * iVar7;
    if (9599999 < iVar9) {
      iVar9 = 9600000;
    }
    if (*(int *)(lVar15 + 0x11c) != 0) {
      iVar7 = iVar9;
    }
    if (iVar7 < 2400000) {
      if (iVar7 == 600000) {
        uVar12 = 0x60;
        uVar10 = 6;
      }
      else {
        if (iVar7 != 1200000) goto LAB_00105778;
        uVar12 = 0x50;
        uVar10 = 5;
      }
LAB_00105774:
      if (!bVar4 && !bVar5) {
        uVar10 = uVar12;
      }
    }
    else {
      if (iVar7 == 2400000) {
        uVar12 = 0x30;
        uVar10 = 3;
        goto LAB_00105774;
      }
      if ((iVar7 == 4800000) && (uVar10 = 0x10, bVar4 || bVar5)) {
        uVar10 = 1;
      }
    }
LAB_00105778:
    uVar12 = 0xf;
    if (!bVar4 && !bVar5) {
      uVar12 = 0xf0;
    }
    snd_soc_component_update_bits(lVar11,0x3405,uVar12,uVar10);
  }
  uVar10 = swr_slvdev_datapath_control
                     (*(long *)(lVar15 + 0x30),*(undefined1 *)(*(long *)(lVar15 + 0x30) + 0x40),0);
  lVar15 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011b454,4);
  if (lVar15 == 0) goto LAB_00105870;
  uVar12 = 0;
  if (iVar7 < 2400000) {
    if (iVar7 == 600000) {
      uVar13 = 6;
      uVar12 = 0x60;
    }
    else {
      if (iVar7 != 1200000) goto LAB_00105854;
      uVar13 = 5;
      uVar12 = 0x50;
    }
LAB_00105850:
    if (!bVar4 && !bVar5) {
      uVar12 = uVar13;
    }
  }
  else {
    if (iVar7 == 2400000) {
      uVar13 = 3;
      uVar12 = 0x30;
      goto LAB_00105850;
    }
    if ((iVar7 == 4800000) && (uVar12 = 0x10, !bVar4 && !bVar5)) {
      uVar12 = 1;
    }
  }
LAB_00105854:
  uVar13 = 0xf0;
  if (!bVar4 && !bVar5) {
    uVar13 = 0xf;
  }
  snd_soc_component_update_bits(lVar11,0x3405,uVar13,uVar12);
LAB_00105870:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// wcd938x_codec_enable_micbias @ 001059ec size=32
// signature: undefined wcd938x_codec_enable_micbias(void)
// callers: []
//------------------------------------------------------------

void wcd938x_codec_enable_micbias(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  __wcd938x_codec_enable_micbias(param_1,param_3);
  return;
}



//------------------------------------------------------------
// wcd938x_codec_force_enable_micbias @ 00105a10 size=128
// signature: undefined wcd938x_codec_force_enable_micbias(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_codec_force_enable_micbias(long param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if ((param_3 == 8) || (param_3 == 1)) {
    uVar2 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    wcd938x_wakeup(uVar2,1);
    uVar1 = __wcd938x_codec_enable_micbias(param_1,param_3);
    wcd938x_wakeup(uVar2,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd938x_codec_enable_vdd_buck @ 00105a94 size=384
// signature: undefined wcd938x_codec_enable_vdd_buck(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_enable_vdd_buck(long param_1,undefined8 param_2,int param_3)

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
  
  lVar8 = *(long *)(param_1 + 0x28);
  plVar9 = *(long **)(*(long *)(lVar8 + -0xb8) + 0x98);
  lVar10 = *(long *)(*plVar9 + 0x90);
  if (lVar10 == 0) {
    iVar4 = ___ratelimit(wcd938x_codec_enable_vdd_buck__rs,"wcd938x_codec_enable_vdd_buck");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    uVar6 = *(undefined8 *)(lVar8 + -0xb8);
    pcVar7 = "%s: pdata is NULL\n";
LAB_00105bd0:
    _dev_err(uVar6,pcVar7,"wcd938x_codec_enable_vdd_buck");
    uVar6 = 0xffffffea;
  }
  else {
    uVar5 = msm_cdc_is_ondemand_supply
                      (*plVar9,plVar9[0x182],*(undefined8 *)(lVar10 + 0x38),
                       *(undefined4 *)(lVar10 + 0x40),"cdc-vdd-buck");
    if ((uVar5 & 1) != 0) {
      if (param_3 == 8) {
        puVar1 = (ulong *)(plVar9 + 0x2c);
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
        if (((uint)plVar9[0x2c] >> 4 & 1) == 0) {
          iVar4 = msm_cdc_enable_ondemand_supply
                            (*plVar9,plVar9[0x182],*(undefined8 *)(lVar10 + 0x38),
                             *(undefined4 *)(lVar10 + 0x40),"cdc-vdd-buck");
          if (iVar4 == -0x16) {
            iVar4 = ___ratelimit(wcd938x_codec_enable_vdd_buck__rs_298,
                                 "wcd938x_codec_enable_vdd_buck");
            if (iVar4 == 0) {
              return 0xffffffea;
            }
            uVar6 = *(undefined8 *)(lVar8 + -0xb8);
            pcVar7 = "%s: vdd buck is not enabled\n";
            goto LAB_00105bd0;
          }
          puVar1 = (ulong *)(plVar9 + 0x2c);
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
          puVar1 = (ulong *)(plVar9 + 0x2c);
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
// wcd938x_enable_clsh @ 00105c44 size=276
// signature: undefined wcd938x_enable_clsh(void)
// callers: []
//------------------------------------------------------------

void wcd938x_enable_clsh(long param_1,undefined8 param_2,ulong param_3)

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
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (*(uint *)(lVar3 + 0x108) < 6 && (1 << (ulong)(*(uint *)(lVar3 + 0x108) & 0x1f) & 0x36U) != 0)
  {
    local_2c[0] = 0;
    local_30[0] = 0;
    local_34[0] = 0;
    local_38[0] = 0;
    local_3c = 0;
    iVar1 = wcd938x_set_port_params
                      (*(long *)(param_1 + 0x28) + -0xd0,0x12,local_2c,local_30,local_34,&local_3c,
                       local_38,1);
    if (iVar1 == 0) {
      if ((param_3 & 3) == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar3 + 0x28),local_2c,1,local_34,local_38);
      }
      else {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_2c,1,local_34,&local_3c,local_30,
                         local_38);
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
// wcd938x_codec_enable_ear_pa @ 00105d5c size=792
// signature: undefined wcd938x_codec_enable_ear_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_codec_enable_ear_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  long lVar8;
  long lVar9;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar8 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar9 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  uVar6 = *(uint *)(lVar9 + 0x108);
  switch(param_3) {
  case 1:
    uVar5 = swr_slvdev_datapath_control
                      (*(long *)(lVar9 + 0x28),*(undefined1 *)(*(long *)(lVar9 + 0x28) + 0x40),1);
    uVar6 = snd_soc_component_read(lVar8,0x3450);
    *(uint *)(lVar9 + 0xc74) = uVar6;
    if ((uVar6 & 1) == 0) {
      snd_soc_component_update_bits(lVar8,0x3465,7,3);
      puVar1 = (ulong *)(lVar9 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x4000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      cVar2 = *(char *)(lVar9 + 0x120);
    }
    else {
      snd_soc_component_update_bits(lVar8,0x3467,1,1);
      cVar2 = *(char *)(lVar9 + 0x120);
    }
    if (cVar2 == '\0') {
      snd_soc_component_update_bits(lVar8,0x300b,0x80,0x80);
      return uVar5;
    }
    return uVar5;
  case 2:
    usleep_range_state(6000,0x177a,2);
    if (uVar6 < 9 && (1 << (ulong)(uVar6 & 0x1f) & 0x1c8U) != 0) {
      snd_soc_component_update_bits(lVar8,0x3008,2,2);
    }
    pcVar7 = *(code **)(lVar9 + 0xc38);
    if ((*(byte *)(lVar9 + 0xc74) & 1) == 0) {
      if (pcVar7 != (code *)0x0) {
        if (*(int *)(pcVar7 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105ec8);
          (*pcVar7)();
        }
        (*pcVar7)(*(undefined8 *)(lVar9 + 0xc30),1,0);
      }
      wcd_enable_irq(lVar9 + 0x130,0xd);
    }
    else {
      if (pcVar7 != (code *)0x0) {
        if (*(int *)(pcVar7 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105fd8);
          (*pcVar7)();
        }
        (*pcVar7)(*(undefined8 *)(lVar9 + 0xc30),1,0x20000);
      }
      wcd_enable_irq(lVar9 + 0x130,0xf);
    }
    break;
  case 4:
    if ((*(byte *)(lVar9 + 0xc74) & 1) == 0) {
      if (((uint)*(undefined8 *)(lVar9 + 0x160) >> 0xd & 1) == 0) {
        wcd_disable_irq(lVar9 + 0x130,0xd);
        pcVar7 = *(code **)(lVar9 + 0xc38);
        if (pcVar7 != (code *)0x0) {
          if (*(int *)(pcVar7 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105e4c);
            (*pcVar7)();
          }
          (*pcVar7)(*(undefined8 *)(lVar9 + 0xc30),1,1);
        }
      }
    }
    else {
      wcd_disable_irq(lVar9 + 0x130,0xf);
      pcVar7 = *(code **)(lVar9 + 0xc38);
      if (pcVar7 != (code *)0x0) {
        if (*(int *)(pcVar7 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105f74);
          (*pcVar7)();
        }
        (*pcVar7)(*(undefined8 *)(lVar9 + 0xc30),1,0x20001);
      }
    }
    break;
  case 8:
    if (*(char *)(lVar9 + 0x120) == '\0') {
      snd_soc_component_update_bits(lVar8,0x300b,0x80,0);
    }
    usleep_range_state(7000,0x1b62,2);
    if ((*(byte *)(lVar9 + 0xc74) & 1) == 0) {
      snd_soc_component_update_bits(lVar8,0x3465,7,0);
      puVar1 = (ulong *)(lVar9 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xffffffffffffbfff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      snd_soc_component_update_bits(lVar8,0x3467,1,0);
    }
    wcd_cls_h_fsm(lVar8,lVar9 + 0xe0,2,1,uVar6);
    iVar4 = *(int *)(lVar9 + 0xc70) + -1;
    *(int *)(lVar9 + 0xc70) = iVar4;
    if (iVar4 == 0) {
      snd_soc_component_update_bits(lVar8,0x30a4,4,4);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_enable_aux_pa @ 001060a0 size=448
// signature: undefined wcd938x_codec_enable_aux_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_codec_enable_aux_pa(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar5 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  uVar1 = *(uint *)(lVar6 + 0x108);
  switch(param_3) {
  case 1:
    uVar3 = swr_slvdev_datapath_control
                      (*(long *)(lVar6 + 0x28),*(undefined1 *)(*(long *)(lVar6 + 0x28) + 0x40),1);
    snd_soc_component_update_bits(lVar5,0x3467,1,1);
    return uVar3;
  case 2:
    usleep_range_state(1000,0x3f2,2);
    if (uVar1 < 9 && (1 << (ulong)(uVar1 & 0x1f) & 0x1c8U) != 0) {
      snd_soc_component_update_bits(lVar5,0x3008,2,2);
    }
    pcVar4 = *(code **)(lVar6 + 0xc38);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x106188);
        (*pcVar4)();
      }
      (*pcVar4)(*(undefined8 *)(lVar6 + 0xc30),1,0x20000);
    }
    wcd_enable_irq(lVar6 + 0x130,0xf);
    break;
  case 4:
    wcd_disable_irq(lVar6 + 0x130,0xf);
    pcVar4 = *(code **)(lVar6 + 0xc38);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1061d8);
        (*pcVar4)();
      }
      (*pcVar4)(*(undefined8 *)(lVar6 + 0xc30),1,0x20001);
    }
    break;
  case 8:
    usleep_range_state(1000,0x3f2,2);
    snd_soc_component_update_bits(lVar5,0x3467,1,0);
    wcd_cls_h_fsm(lVar5,lVar6 + 0xe0,2,8,uVar1);
    iVar2 = *(int *)(lVar6 + 0xc70) + -1;
    *(int *)(lVar6 + 0xc70) = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    snd_soc_component_update_bits(lVar5,0x30a4,4,4);
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_enable_hphl_pa @ 00106264 size=1140
// signature: undefined wcd938x_codec_enable_hphl_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_codec_enable_hphl_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  uint uVar2;
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
  uVar2 = *(uint *)(lVar10 + 0x108);
  switch(param_3) {
  case 1:
    if (*(char *)(lVar10 + 0x122) != '\0') {
      snd_soc_component_update_bits(lVar9,0x3067,0x80,0x80);
    }
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x106300);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),1,1);
    }
    uVar5 = swr_slvdev_datapath_control
                      (*(long *)(lVar10 + 0x28),*(undefined1 *)(*(long *)(lVar10 + 0x28) + 0x40),1);
    wcd_cls_h_fsm(lVar9,lVar10 + 0xe0,1,2,uVar2);
    wcd_clsh_set_hph_mode(lVar9,1);
    if ((uVar2 < 6) && ((1 << (ulong)(uVar2 & 0x1f) & 0x34U) != 0)) {
      snd_soc_component_update_bits(lVar9,0x30de,1,1);
    }
    snd_soc_component_update_bits(lVar9,0x3009,0x20,0x20);
    wcd_clsh_set_hph_mode(lVar9,uVar2);
    usleep_range_state(100,0x6e,2);
    puVar1 = (ulong *)(lVar10 + 0x160);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 0x40;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    snd_soc_component_update_bits(lVar9,0x3465,7,3);
    puVar1 = (ulong *)(lVar10 + 0x160);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 0x2000;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    return uVar5;
  case 2:
    if (((uint)*(undefined8 *)(lVar10 + 0x160) >> 6 & 1) != 0) {
      if (*(char *)(lVar10 + 0x120) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      if ((uVar2 < 6) && ((1 << (ulong)(uVar2 & 0x1f) & 0x34U) != 0)) {
        snd_soc_component_update_bits(lVar9,0x30de,1,0);
      }
      puVar1 = (ulong *)(lVar10 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    snd_soc_component_update_bits(lVar9,0x313a,2,2);
    if ((uVar2 < 9) && ((1 << (ulong)(uVar2 & 0x1f) & 0x1c8U) != 0)) {
      snd_soc_component_update_bits(lVar9,0x3008,2,2);
    }
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1065a4);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),1,0);
    }
    wcd_enable_irq(lVar10 + 0x130,0xd);
    break;
  case 4:
    if (((uint)*(undefined8 *)(lVar10 + 0x160) >> 0xe & 1) == 0) {
      pcVar8 = *(code **)(lVar10 + 0xc38);
      if (pcVar8 != (code *)0x0) {
        if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x106408);
          (*pcVar8)();
        }
        (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),1,1);
      }
      wcd_disable_irq(lVar10 + 0x130,0xd);
    }
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if ((pcVar8 != (code *)0x0) && (*(char *)(lVar10 + 0x120) != '\0')) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10644c);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),4,0);
    }
    if (*(char *)(lVar10 + 0x120) == '\0') {
      uVar6 = 20000;
      uVar7 = 0x4e84;
    }
    else {
      uVar6 = 7000;
      uVar7 = 0x1bbc;
    }
    usleep_range_state(uVar6,uVar7,2);
    snd_soc_component_update_bits(lVar9,0x3009,0x80,0);
    blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,0xd);
    puVar1 = (ulong *)(lVar10 + 0x160);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 0x40;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    break;
  case 8:
    if (((uint)*(undefined8 *)(lVar10 + 0x160) >> 6 & 1) != 0) {
      if (*(char *)(lVar10 + 0x120) == '\0') {
        uVar6 = 21000;
        uVar7 = 0x526c;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      puVar1 = (ulong *)(lVar10 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,10);
    snd_soc_component_update_bits(lVar9,0x3009,0x20,0);
    snd_soc_component_update_bits(lVar9,0x3465,7,0);
    wcd_cls_h_fsm(lVar9,lVar10 + 0xe0,2,2,uVar2);
    if (*(char *)(lVar10 + 0x122) != '\0') {
      snd_soc_component_update_bits(lVar9,0x3067,0x80,0);
    }
    puVar1 = (ulong *)(lVar10 + 0x160);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 & 0xffffffffffffdfff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_enable_hphr_pa @ 0010672c size=1068
// signature: undefined wcd938x_codec_enable_hphr_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd938x_codec_enable_hphr_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  uint uVar2;
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
  uVar2 = *(uint *)(lVar10 + 0x108);
  switch(param_3) {
  case 1:
    if (*(char *)(lVar10 + 0x122) != '\0') {
      snd_soc_component_update_bits(lVar9,0x3067,0x80,0x80);
    }
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1067c8);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),1,0x10001);
    }
    uVar5 = swr_slvdev_datapath_control
                      (*(long *)(lVar10 + 0x28),*(undefined1 *)(*(long *)(lVar10 + 0x28) + 0x40),1);
    wcd_cls_h_fsm(lVar9,lVar10 + 0xe0,1,4,uVar2);
    wcd_clsh_set_hph_mode(lVar9,1);
    if ((uVar2 < 6) && ((1 << (ulong)(uVar2 & 0x1f) & 0x34U) != 0)) {
      snd_soc_component_update_bits(lVar9,0x30de,1,1);
    }
    snd_soc_component_update_bits(lVar9,0x3009,0x10,0x10);
    wcd_clsh_set_hph_mode(lVar9,uVar2);
    usleep_range_state(100,0x6e,2);
    puVar1 = (ulong *)(lVar10 + 0x160);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 0x40;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    snd_soc_component_update_bits(lVar9,0x3466,7,3);
    return uVar5;
  case 2:
    if (((uint)*(undefined8 *)(lVar10 + 0x160) >> 6 & 1) != 0) {
      if (*(char *)(lVar10 + 0x121) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      if ((uVar2 < 6) && ((1 << (ulong)(uVar2 & 0x1f) & 0x34U) != 0)) {
        snd_soc_component_update_bits(lVar9,0x30de,1,0);
      }
      puVar1 = (ulong *)(lVar10 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    snd_soc_component_update_bits(lVar9,0x313a,2,2);
    if ((uVar2 < 9) && ((1 << (ulong)(uVar2 & 0x1f) & 0x1c8U) != 0)) {
      snd_soc_component_update_bits(lVar9,0x3008,2,2);
    }
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x106a54);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),1,0x10000);
    }
    wcd_enable_irq(lVar10 + 0x130,0xe);
    break;
  case 4:
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1068b8);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),1,0x10001);
    }
    wcd_disable_irq(lVar10 + 0x130,0xe);
    pcVar8 = *(code **)(lVar10 + 0xc38);
    if ((pcVar8 != (code *)0x0) && (*(char *)(lVar10 + 0x121) != '\0')) {
      if (*(int *)(pcVar8 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1068fc);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(lVar10 + 0xc30),4,0x10000);
    }
    if (*(char *)(lVar10 + 0x121) == '\0') {
      uVar6 = 20000;
      uVar7 = 0x4e84;
    }
    else {
      uVar6 = 7000;
      uVar7 = 0x1bbc;
    }
    usleep_range_state(uVar6,uVar7,2);
    snd_soc_component_update_bits(lVar9,0x3009,0x40,0);
    blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,0xe);
    puVar1 = (ulong *)(lVar10 + 0x160);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 0x40;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    break;
  case 8:
    if (((uint)*(undefined8 *)(lVar10 + 0x160) >> 6 & 1) != 0) {
      if (*(char *)(lVar10 + 0x121) == '\0') {
        uVar6 = 20000;
        uVar7 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar7 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar7,2);
      puVar1 = (ulong *)(lVar10 + 0x160);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,0xc);
    snd_soc_component_update_bits(lVar9,0x3009,0x10,0);
    snd_soc_component_update_bits(lVar9,0x3466,7,0);
    wcd_cls_h_fsm(lVar9,lVar10 + 0xe0,2,4,uVar2);
    if (*(char *)(lVar10 + 0x122) != '\0') {
      snd_soc_component_update_bits(lVar9,0x3067,0x80,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_hphl_dac_event @ 00106b90 size=312
// signature: undefined wcd938x_codec_hphl_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_hphl_dac_event(long param_1,undefined8 param_2,int param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    uVar2 = 0x3136;
    uVar3 = 0xf;
    uVar4 = 1;
  }
  else if (param_3 == 2) {
    lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    snd_soc_component_update_bits(lVar5,0x3133,0xf,2);
    if (*(char *)(lVar6 + 0x120) == '\0') {
      snd_soc_component_update_bits(lVar5,0x3414,2,0);
      uVar2 = 0x30d3;
      uVar3 = 0x20;
      uVar4 = 0x20;
    }
    else {
      snd_soc_component_update_bits(lVar5,0x3414,2,2);
      if ((*(char *)(lVar6 + 0x121) == '\0') ||
         (uVar1 = snd_soc_component_read(lVar5,0x3414), (uVar1 & 1) != 0)) {
        usleep_range_state(5000,0x1392,2);
      }
      uVar2 = 0x313a;
      uVar3 = 2;
      uVar4 = 0;
    }
  }
  else {
    if (param_3 != 1) {
      return 0;
    }
    wcd938x_rx_clk_enable(lVar5);
    snd_soc_component_update_bits(lVar5,0x3409,1,1);
    snd_soc_component_update_bits(lVar5,0x344e,4,4);
    uVar2 = 0x30d9;
    uVar3 = 0x80;
    uVar4 = 0;
  }
  snd_soc_component_update_bits(lVar5,uVar2,uVar3,uVar4);
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_hphr_dac_event @ 00106ccc size=312
// signature: undefined wcd938x_codec_hphr_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_hphr_dac_event(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    uVar2 = 0x3136;
    uVar3 = 0xf;
    uVar4 = 1;
  }
  else if (param_3 == 2) {
    lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    snd_soc_component_update_bits(lVar5,0x3136,0xf,2);
    if (*(char *)(lVar6 + 0x121) == '\0') {
      snd_soc_component_update_bits(lVar5,0x3414,1,0);
      uVar2 = 0x30d6;
      uVar3 = 0x20;
      uVar4 = 0x20;
    }
    else {
      snd_soc_component_update_bits(lVar5,0x3414,1,1);
      if ((*(char *)(lVar6 + 0x120) == '\0') ||
         (uVar1 = snd_soc_component_read(lVar5,0x3414), (uVar1 >> 1 & 1) != 0)) {
        usleep_range_state(5000,0x1392,2);
      }
      uVar2 = 0x313a;
      uVar3 = 2;
      uVar4 = 0;
    }
  }
  else {
    if (param_3 != 1) {
      return 0;
    }
    wcd938x_rx_clk_enable(lVar5);
    snd_soc_component_update_bits(lVar5,0x3409,2,2);
    snd_soc_component_update_bits(lVar5,0x344e,8,8);
    uVar2 = 0x30d9;
    uVar3 = 0x80;
    uVar4 = 0;
  }
  snd_soc_component_update_bits(lVar5,uVar2,uVar3,uVar4);
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_ear_dac_event @ 00106e08 size=488
// signature: undefined wcd938x_codec_ear_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_ear_dac_event(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar7 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 != 8) {
    if (param_3 != 1) {
      return 0;
    }
    wcd938x_rx_clk_enable(lVar6);
    uVar1 = snd_soc_component_read(lVar6,0x3450);
    *(uint *)(lVar7 + 0xc74) = uVar1;
    if ((uVar1 & 1) == 0) {
      snd_soc_component_update_bits(lVar6,0x344e,4,4);
      snd_soc_component_update_bits(lVar6,0x3409,1,1);
      if (*(char *)(lVar7 + 0x120) == '\0') goto LAB_00106f38;
      uVar2 = 0x3414;
      uVar3 = 2;
      uVar4 = 2;
    }
    else {
      snd_soc_component_update_bits(lVar6,0x30ec,0x80,0);
      snd_soc_component_update_bits(lVar6,0x344f,1,1);
      snd_soc_component_update_bits(lVar6,0x3409,4,4);
      uVar2 = 0x300b;
      uVar3 = 0x80;
      uVar4 = 0x80;
    }
    snd_soc_component_update_bits(lVar6,uVar2,uVar3,uVar4);
LAB_00106f38:
    usleep_range_state(5000,0x1392,2);
    iVar5 = *(int *)(lVar7 + 0xc70);
    if (iVar5 == 0) {
      snd_soc_component_update_bits(lVar6,0x30a4,4,0);
      iVar5 = *(int *)(lVar7 + 0xc70);
    }
    *(int *)(lVar7 + 0xc70) = iVar5 + 1;
    wcd_cls_h_fsm(lVar6,lVar7 + 0xe0,1,1,*(undefined4 *)(lVar7 + 0x108));
    return 0;
  }
  if ((*(byte *)(lVar7 + 0xc74) & 1) == 0) {
    if (((uint)*(undefined8 *)(lVar7 + 0x160) >> 0xd & 1) == 0) {
      snd_soc_component_update_bits(lVar6,0x344e,4,0);
      snd_soc_component_update_bits(lVar6,0x3409,1,0);
    }
    if (*(char *)(lVar7 + 0x120) == '\0') goto LAB_00106fb4;
    uVar2 = 0x3414;
    uVar3 = 2;
  }
  else {
    snd_soc_component_update_bits(lVar6,0x344f,1,0);
    uVar2 = 0x3409;
    uVar3 = 4;
  }
  snd_soc_component_update_bits(lVar6,uVar2,uVar3,0);
LAB_00106fb4:
  snd_soc_component_update_bits(lVar6,0x300b,0x80,0);
  snd_soc_component_update_bits(lVar6,0x30ec,0x80,0x80);
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_aux_dac_event @ 00106ff4 size=224
// signature: undefined wcd938x_codec_aux_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_aux_dac_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar2,0x3408,4,0);
  }
  else if (param_3 == 1) {
    lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    wcd938x_rx_clk_enable(lVar2);
    snd_soc_component_update_bits(lVar2,0x3408,4,4);
    snd_soc_component_update_bits(lVar2,0x3409,4,4);
    snd_soc_component_update_bits(lVar2,0x344f,1,1);
    iVar1 = *(int *)(lVar3 + 0xc70);
    if (iVar1 == 0) {
      snd_soc_component_update_bits(lVar2,0x30a4,4,0);
      iVar1 = *(int *)(lVar3 + 0xc70);
    }
    *(int *)(lVar3 + 0xc70) = iVar1 + 1;
    wcd_cls_h_fsm(lVar2,lVar3 + 0xe0,1,8,*(undefined4 *)(lVar3 + 0x108));
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_enable_rx1 @ 001070d8 size=536
// signature: undefined wcd938x_enable_rx1(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_enable_rx1(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined4 local_4c;
  undefined1 local_48 [4];
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
    if ((((uint)*(undefined8 *)(lVar4 + 0x160) >> 0xd & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar4 + 0x160) >> 0xe & 1) == 0)) {
      local_3c[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      iVar1 = wcd938x_set_port_params(lVar2,0xe,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_48);
      }
      if (*(char *)(lVar4 + 0x120) != '\0') {
        lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
        local_3c[0] = 0;
        local_44[0] = 0;
        local_48[0] = 0;
        iVar1 = wcd938x_set_port_params(lVar2,0x10,local_3c,local_40,local_44,&local_4c,local_48,1);
        if (iVar1 == 0) {
          swr_disconnect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,local_48);
        }
      }
      wcd938x_rx_clk_disable(lVar2);
      snd_soc_component_update_bits(lVar2,0x3409,1,0);
    }
  }
  else if (param_3 == 1) {
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48[0] = 0;
    local_4c = 0;
    iVar1 = wcd938x_set_port_params(lVar2,0xe,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_4c,local_40,local_48
                      );
    }
    if (*(char *)(lVar4 + 0x120) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_40[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      local_4c = 0;
      iVar1 = wcd938x_set_port_params(lVar2,0x10,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,&local_4c,local_40,
                         local_48);
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
// wcd938x_enable_rx2 @ 001072f4 size=520
// signature: undefined wcd938x_enable_rx2(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_enable_rx2(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined4 local_4c;
  undefined1 local_48 [4];
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
    local_48[0] = 0;
    iVar1 = wcd938x_set_port_params(lVar2,0xf,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_48);
    }
    if (*(char *)(lVar4 + 0x121) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      iVar1 = wcd938x_set_port_params(lVar2,0x11,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,local_48);
      }
    }
    wcd938x_rx_clk_disable(lVar2);
    snd_soc_component_update_bits(lVar2,0x3409,2,0);
  }
  else if (param_3 == 1) {
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48[0] = 0;
    local_4c = 0;
    iVar1 = wcd938x_set_port_params(lVar2,0xf,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_4c,local_40,local_48
                      );
    }
    if (*(char *)(lVar4 + 0x121) != '\0') {
      lVar3 = *(long *)(*(long *)(lVar3 + -0xb8) + 0x98);
      local_3c[0] = 0;
      local_40[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      local_4c = 0;
      iVar1 = wcd938x_set_port_params(lVar2,0x11,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_3c,1,local_44,&local_4c,local_40,
                         local_48);
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
// wcd938x_enable_rx3 @ 00107500 size=336
// signature: undefined wcd938x_enable_rx3(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_enable_rx3(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined4 local_3c;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x28);
  lVar3 = lVar2 + -0xd0;
  if (param_3 == 8) {
    lVar2 = *(long *)(*(long *)(lVar2 + -0xb8) + 0x98);
    local_2c[0] = 0;
    local_34[0] = 0;
    local_38[0] = 0;
    iVar1 = wcd938x_set_port_params(lVar3,0x13,local_2c,local_30,local_34,&local_3c,local_38,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar2 + 0x28),local_2c,1,local_34,local_38);
    }
    usleep_range_state(6000,0x177a,2);
    wcd938x_rx_clk_disable(lVar3);
    snd_soc_component_update_bits(lVar3,0x3409,4,0);
  }
  else if (param_3 == 1) {
    lVar2 = *(long *)(*(long *)(lVar2 + -0xb8) + 0x98);
    local_2c[0] = 0;
    local_30[0] = 0;
    local_34[0] = 0;
    local_38[0] = 0;
    local_3c = 0;
    iVar1 = wcd938x_set_port_params(lVar3,0x13,local_2c,local_30,local_34,&local_3c,local_38,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar2 + 0x28),local_2c,1,local_34,&local_3c,local_30,local_38
                      );
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_codec_enable_micbias_pullup @ 00107654 size=256
// signature: undefined wcd938x_codec_enable_micbias_pullup(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_codec_enable_micbias_pullup(long param_1,undefined8 param_2,int param_3)

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
        lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"VA MIC BIAS4",0xd);
        if (lVar1 == 0) {
          return 0xffffffea;
        }
        uVar2 = 4;
      }
      else {
        uVar2 = 3;
      }
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
  wcd938x_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd938x_tx_connect_port @ 00107754 size=280
// signature: undefined wcd938x_tx_connect_port(void)
// callers: [wcd938x_codec_enable_dmic, wcd938x_codec_enable_adc, wcd938x_tx_swr_ctrl]
//------------------------------------------------------------

void wcd938x_tx_connect_port(long param_1,undefined8 param_2,int param_3,char param_4)

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
  iVar2 = wcd938x_set_port_params(param_1,param_2,local_3c,local_40,local_44,&local_4c,local_48,0);
  if (iVar2 == 0) {
    if (param_3 != 0) {
      local_4c = param_3;
    }
    uVar1 = (int)param_2 - 0x1d;
    if ((uVar1 & 0xff) < 0xd) {
      local_48[0] = *(undefined1 *)
                     (lVar4 + (ulong)(byte)swr_slv_tx_ch_idx
                                           [*(long *)(&DAT_00116c98 + (long)(char)uVar1 * 8) * 2 + 1
                                           ] + 0xc79);
    }
    uVar3 = *(undefined8 *)(lVar4 + 0x30);
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
// wcd938x_set_port_params @ 0010786c size=508
// signature: undefined wcd938x_set_port_params(void)
// callers: [wcd938x_tx_connect_port, wcd938x_enable_clsh, wcd938x_enable_rx2, wcd938x_enable_rx3, wcd938x_codec_enable_adc, wcd938x_tx_swr_ctrl, wcd938x_enable_rx1]
//------------------------------------------------------------

undefined8
wcd938x_set_port_params
          (long param_1,uint param_2,undefined1 *param_3,undefined1 *param_4,undefined1 *param_5,
          undefined4 *param_6,undefined1 *param_7,uint param_8)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  byte *pbVar9;
  long lVar10;
  
  param_8 = param_8 & 0xff;
  lVar7 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (param_8 == 0) {
    lVar6 = lVar7 + 0x16c;
    pbVar9 = (byte *)(lVar7 + 0x168);
  }
  else {
    if (param_8 != 1) {
      iVar3 = ___ratelimit(wcd938x_set_port_params__rs,"wcd938x_set_port_params");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x18);
      pcVar5 = "%s Invalid path selected %u\n";
      goto LAB_00107a4c;
    }
    lVar6 = lVar7 + 0x66c;
    pbVar9 = (byte *)(lVar7 + 0x169);
  }
  lVar7 = 0;
  bVar2 = false;
  param_8 = param_2 & 0xff;
  lVar10 = 1;
  uVar8 = 0;
  do {
    if ((int)lVar7 == 0x500) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x107a68);
      (*pcVar1)();
    }
    if (*(uint *)(lVar6 + lVar7) == param_8) {
      lVar10 = 0;
joined_r0x00107994:
      if (!bVar2) {
        *param_3 = (char)uVar8;
        lVar7 = lVar6 + lVar10 * 0x14 + lVar7;
        *param_4 = (char)*(undefined4 *)(lVar7 + 0xc);
        *param_5 = (char)*(undefined4 *)(lVar7 + 8);
        *param_6 = *(undefined4 *)(lVar7 + 0x10);
        *param_7 = (char)*(undefined4 *)(lVar7 + 4);
        return 0;
      }
      break;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x14) == param_8) goto joined_r0x00107994;
    if (*(uint *)(lVar6 + lVar7 + 0x28) == param_8) {
      lVar10 = 2;
      goto joined_r0x00107994;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x3c) == param_8) {
      lVar10 = 3;
      goto joined_r0x00107994;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x50) == param_8) {
      lVar10 = 4;
      goto joined_r0x00107994;
    }
    if (*(uint *)(lVar6 + lVar7 + 100) == param_8) {
      lVar10 = 5;
      goto joined_r0x00107994;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x78) == param_8) {
      lVar10 = 6;
      goto joined_r0x00107994;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x8c) == param_8) {
      lVar10 = 7;
      goto joined_r0x00107994;
    }
    bVar2 = *pbVar9 <= uVar8;
    lVar7 = lVar7 + 0xa0;
    uVar8 = uVar8 + 1;
  } while ((uint)*pbVar9 * 0xa0 + 0xa0 != (int)lVar7);
  iVar3 = ___ratelimit(wcd938x_set_port_params__rs_248,"wcd938x_set_port_params");
  if (iVar3 == 0) {
    return 0xffffffea;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  pcVar5 = "%s Failed to find slave port for type %u\n";
LAB_00107a4c:
  _dev_err(uVar4,pcVar5,"wcd938x_set_port_params",param_8);
  return 0xffffffea;
}



//------------------------------------------------------------
// __wcd938x_codec_enable_micbias @ 00107a68 size=256
// signature: undefined __wcd938x_codec_enable_micbias(void)
// callers: [wcd938x_codec_force_enable_micbias, wcd938x_codec_enable_micbias]
//------------------------------------------------------------

undefined8 __wcd938x_codec_enable_micbias(long param_1,int param_2)

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
        lVar1 = strnstr(*(undefined8 *)(param_1 + 8),"MIC BIAS4",10);
        if (lVar1 == 0) {
          return 0xffffffea;
        }
        uVar2 = 4;
      }
      else {
        uVar2 = 3;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  else {
    uVar2 = 1;
  }
  if (param_2 == 8) {
    uVar3 = 3;
  }
  else {
    if (param_2 == 2) {
      usleep_range_state(1000,0x44c,2);
      return 0;
    }
    if (param_2 != 1) {
      return 0;
    }
    uVar3 = 2;
  }
  wcd938x_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd938x_rx_clk_enable @ 00107b68 size=200
// signature: undefined wcd938x_rx_clk_enable(void)
// callers: [wcd938x_codec_hphr_dac_event, wcd938x_codec_aux_dac_event, wcd938x_codec_ear_dac_event, wcd938x_codec_hphl_dac_event]
//------------------------------------------------------------

void wcd938x_rx_clk_enable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  iVar1 = *(int *)(lVar2 + 0x158);
  if (iVar1 == 0) {
    snd_soc_component_update_bits(param_1,0x3408,1,1);
    snd_soc_component_update_bits(param_1,0x3008,1,1);
    snd_soc_component_update_bits(param_1,0x340d,0x40,0);
    snd_soc_component_update_bits(param_1,0x340e,0x40,0);
    snd_soc_component_update_bits(param_1,0x340f,0x40,0);
    snd_soc_component_update_bits(param_1,0x3408,2,2);
    snd_soc_component_update_bits(param_1,0x3128,0x10,0x10);
    iVar1 = *(int *)(lVar2 + 0x158);
  }
  *(int *)(lVar2 + 0x158) = iVar1 + 1;
  return;
}



//------------------------------------------------------------
// wcd938x_rx_clk_disable @ 00107c30 size=156
// signature: undefined wcd938x_rx_clk_disable(void)
// callers: [wcd938x_enable_rx2, wcd938x_enable_rx3, wcd938x_enable_rx1]
//------------------------------------------------------------

void wcd938x_rx_clk_disable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  iVar1 = *(int *)(lVar2 + 0x158) + -1;
  *(int *)(lVar2 + 0x158) = iVar1;
  if (iVar1 == 0) {
    snd_soc_component_update_bits(param_1,0x3008,0x40,0);
    snd_soc_component_update_bits(param_1,0x3008,0x80,0);
    snd_soc_component_update_bits(param_1,0x3008,1,0);
    snd_soc_component_update_bits(param_1,0x3408,2,0);
    snd_soc_component_update_bits(param_1,0x3408,1,0);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_init_reg @ 00107ccc size=632
// signature: undefined wcd938x_init_reg(void)
// callers: [wcd938x_soc_codec_probe, wcd938x_event_notify]
//------------------------------------------------------------

void wcd938x_init_reg(undefined8 param_1)

{
  uint uVar1;
  
  snd_soc_component_update_bits(param_1,0x3103,0xe,0xe);
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
  snd_soc_component_update_bits(param_1,0x3132,0xf0,0);
  snd_soc_component_update_bits(param_1,0x3140,0x1f,0x15);
  snd_soc_component_update_bits(param_1,0x3141,0x1f,0x15);
  snd_soc_component_update_bits(param_1,0x30dd,0xc0,0x80);
  snd_soc_component_update_bits(param_1,0x345b,2,2);
  snd_soc_component_update_bits(param_1,0x31e1,0xff,0x14);
  snd_soc_component_update_bits(param_1,0x31df,0x1f,8);
  snd_soc_component_update_bits(param_1,0x34d0,0xff,0x55);
  snd_soc_component_update_bits(param_1,0x34d1,0xff,0x44);
  snd_soc_component_update_bits(param_1,0x34d2,0xff,0x11);
  snd_soc_component_update_bits(param_1,0x34d3,0xff,0);
  snd_soc_component_update_bits(param_1,0x34d4,0xff,0);
  snd_soc_component_update_bits(param_1,0x306b,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x306e,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x3071,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x3074,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x308f,1,0);
  uVar1 = snd_soc_component_read(param_1,0x34ce);
  snd_soc_component_update_bits(param_1,0x3103,0xe,(uVar1 & 7) << 1);
  snd_soc_component_update_bits(param_1,0x30e2,0xc0,0xc0);
  return;
}



//------------------------------------------------------------
// wcd938x_event_notify @ 00107f48 size=1024
// signature: undefined wcd938x_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_event_notify(undefined8 param_1,ulong param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined1 uVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  
  uVar4 = (uint)param_2 & 0xffff;
  if (6 < uVar4 - 1) {
    return 0;
  }
  plVar12 = *(long **)(param_3 + 0x98);
  lVar10 = plVar12[2];
  switch(uVar4) {
  case 1:
    puVar1 = (ulong *)(plVar12 + 0x2c);
    if ((plVar12[0x2c] & 1U) == 0) {
      if (((uint)*puVar1 >> 1 & 1) != 0) goto LAB_00108170;
LAB_00107fa0:
      if (((uint)*puVar1 >> 2 & 1) != 0) goto LAB_001081a4;
LAB_00107fa8:
      uVar4 = (uint)*puVar1;
    }
    else {
      snd_soc_component_update_bits(lVar10,0x300f,0x40,0);
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
      if (((uint)*puVar1 >> 1 & 1) == 0) goto LAB_00107fa0;
LAB_00108170:
      snd_soc_component_update_bits(lVar10,0x300f,0x20,0);
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
      if (((uint)*puVar1 >> 2 & 1) == 0) goto LAB_00107fa8;
LAB_001081a4:
      snd_soc_component_update_bits(lVar10,0x3011,0x40,0);
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
      uVar4 = (uint)*puVar1;
    }
    if ((uVar4 >> 3 & 1) != 0) {
      snd_soc_component_update_bits(lVar10,0x3011,0x20,0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x1000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
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
    break;
  case 2:
    snd_soc_component_update_bits(lVar10,0x3009,0xc0,0);
    snd_soc_component_update_bits(lVar10,0x300a,0x80,0);
    uVar6 = 0x3128;
    uVar8 = 0x80;
    uVar4 = 0;
    goto LAB_001080dc;
  case 3:
    *(undefined1 *)(plVar12 + 399) = 0;
    if (*(char *)((long)plVar12 + 0xc87) != '\0') {
      blocking_notifier_call_chain(plVar12 + 0x191,0,0);
    }
    *(undefined1 *)(plVar12[0x20] + 0x3d0) = 1;
    if ((*(int *)(*(long *)(plVar12[0x20] + 0x90) + 0x58) == 0) ||
       (uVar4 = snd_soc_component_read(lVar10,0x3014), (uVar4 >> 5 & 1) != 0)) {
      uVar9 = 0;
    }
    else {
      uVar9 = 1;
    }
    *(undefined1 *)((long)plVar12 + 0xc86) = uVar9;
    wcd938x_mbhc_ssr_down(plVar12[0x20],lVar10);
    lVar10 = *plVar12;
    if ((lVar10 != 0) && (*(long *)(lVar10 + 0x98) != 0)) {
      if (*(long *)(*(long *)(lVar10 + 0x98) + 0x18) == 0) {
        iVar5 = ___ratelimit(wcd938x_reset_low__rs,"wcd938x_reset_low");
        if (iVar5 == 0) {
          return 0;
        }
        pcVar7 = "%s: reset gpio device node not specified\n";
      }
      else {
        iVar5 = msm_cdc_pinctrl_select_sleep_state();
        if (iVar5 == 0) {
          usleep_range_state(0x14,0x1e,2);
          return 0;
        }
        iVar5 = ___ratelimit(wcd938x_reset_low__rs_365,"wcd938x_reset_low");
        if (iVar5 == 0) {
          return 0;
        }
        pcVar7 = "%s: wcd sleep state request fail!\n";
      }
      _dev_err(lVar10,pcVar7,"wcd938x_reset_low");
    }
    break;
  case 4:
    wcd938x_reset(*plVar12);
    usleep_range_state(10000,0x271a,2);
    wcd938x_get_logical_addr(plVar12[6]);
    wcd938x_get_logical_addr(plVar12[5]);
    wcd938x_init_reg(lVar10);
    regcache_mark_dirty(plVar12[4]);
    regcache_sync(plVar12[4]);
    lVar11 = plVar12[0x20];
    iVar5 = wcd938x_mbhc_post_ssr_init(lVar11,lVar10);
    if (iVar5 == 0) {
      wcd938x_mbhc_hs_detect(lVar10,*(undefined8 *)(lVar11 + 0x90));
    }
    else {
      iVar5 = ___ratelimit(wcd938x_event_notify__rs,"wcd938x_event_notify");
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(lVar10 + 0x18),"%s: mbhc initialization failed\n",
                 "wcd938x_event_notify");
      }
    }
    *(undefined1 *)(plVar12[0x20] + 0x3d0) = 0;
    *(undefined1 *)(plVar12 + 399) = 1;
    if (*(char *)((long)plVar12 + 0xc87) != '\0') {
      blocking_notifier_call_chain(plVar12 + 0x191,1,0);
    }
    if (*(char *)((long)plVar12 + 0xc86) != '\0') {
      lVar10 = -500;
      do {
        __const_udelay(0x418958);
        bVar3 = lVar10 != -1;
        lVar10 = lVar10 + 1;
      } while (bVar3);
    }
    break;
  case 7:
    uVar4 = (uint)(param_2 >> 0xf) & 0xfffffffe;
    uVar6 = 0x3407;
    uVar8 = 6;
LAB_001080dc:
    snd_soc_component_update_bits(lVar10,uVar6,uVar8,uVar4);
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_ear_pa_gain_get @ 001083a8 size=64
// signature: undefined wcd938x_ear_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_ear_pa_gain_get(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0x80),0x300b);
  *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 >> 2 & 0x1f);
  return 0;
}



//------------------------------------------------------------
// wcd938x_ear_pa_gain_put @ 001083ec size=68
// signature: undefined wcd938x_ear_pa_gain_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_ear_pa_gain_put(long param_1,long param_2)

{
  if (*(char *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x120) == '\0') {
    snd_soc_component_update_bits
              (*(long *)(param_1 + 0x80),0x300b,0x7c,(*(uint *)(param_2 + 0x48) & 0x3f) << 2);
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_rx_hph_mode_get @ 00108434 size=28
// signature: undefined wcd938x_rx_hph_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_rx_hph_mode_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(uint *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x108);
  return 0;
}



//------------------------------------------------------------
// wcd938x_rx_hph_mode_put @ 00108454 size=184
// signature: undefined wcd938x_rx_hph_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_rx_hph_mode_put(long param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar3 = *(long *)(*(long *)(lVar4 + 0x18) + 0x98);
  iVar1 = *(int *)(param_2 + 0x48);
  if (*(int *)(lVar3 + 8) == 0) {
    if (iVar1 == 0) goto LAB_001084bc;
    if ((iVar1 != 6) && (iVar1 != 1)) goto LAB_001084d8;
    iVar1 = ___ratelimit(wcd938x_rx_hph_mode_put__rs,"wcd938x_rx_hph_mode_put");
    if (iVar1 != 0) {
      pcVar2 = "%s:Invalid HPH Mode, default to CLS_H_ULP\n";
      goto LAB_001084f8;
    }
  }
  else {
    if (iVar1 != 0) goto LAB_001084d8;
LAB_001084bc:
    iVar1 = ___ratelimit(wcd938x_rx_hph_mode_put__rs_337,"wcd938x_rx_hph_mode_put");
    if (iVar1 != 0) {
      pcVar2 = "%s:Invalid HPH Mode, default to class_AB\n";
LAB_001084f8:
      _dev_info(*(undefined8 *)(lVar4 + 0x18),pcVar2,"wcd938x_rx_hph_mode_put");
    }
  }
  iVar1 = 5;
LAB_001084d8:
  *(int *)(lVar3 + 0x108) = iVar1;
  return 0;
}



//------------------------------------------------------------
// wcd938x_tx_mode_get @ 00108510 size=160
// signature: undefined wcd938x_tx_mode_get(void)
// callers: []
//------------------------------------------------------------

void wcd938x_tx_mode_get(long param_1,long param_2)

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
      uVar2 = wcd938x_tx_path_get(param_1 + 0x20,&local_2c);
      if (-1 < (int)uVar2) {
        if (3 < local_2c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1085b0);
          (*pcVar1)();
        }
        uVar2 = 0;
        *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar3 + (ulong)local_2c * 4 + 0x10c);
      }
      goto LAB_00108580;
    }
  }
  uVar2 = 0xffffffea;
LAB_00108580:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_tx_mode_put @ 001085b4 size=160
// signature: undefined wcd938x_tx_mode_put(void)
// callers: []
//------------------------------------------------------------

void wcd938x_tx_mode_put(long param_1,long param_2)

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
      uVar2 = wcd938x_tx_path_get(param_1 + 0x20,&local_2c);
      if ((int)uVar2 == 0) {
        if (3 < local_2c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x108654);
          (*pcVar1)();
        }
        uVar2 = 0;
        *(undefined4 *)(lVar3 + (ulong)local_2c * 4 + 0x10c) = *(undefined4 *)(param_2 + 0x48);
      }
      goto LAB_00108624;
    }
  }
  uVar2 = 0xffffffea;
LAB_00108624:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_tx_path_get @ 00108654 size=336
// signature: undefined wcd938x_tx_path_get(void)
// callers: [wcd938x_tx_mode_get, wcd938x_tx_mode_put]
//------------------------------------------------------------

int wcd938x_tx_path_get(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  pcVar4 = (char *)kstrndup(param_1,9,0xcc0);
  local_30 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    iVar2 = -0x16;
    goto LAB_0010875c;
  }
  pcVar5 = strsep(&local_30," ");
  if (pcVar5 == (char *)0x0) {
    iVar2 = ___ratelimit(wcd938x_tx_path_get__rs,"wcd938x_tx_path_get");
    if (iVar2 != 0) {
      _printk(&DAT_0011ba20,"wcd938x_tx_path_get",local_30);
    }
LAB_00108750:
    iVar2 = -0x16;
  }
  else {
    pcVar5 = strpbrk(pcVar5,"0123");
    if (pcVar5 == (char *)0x0) {
      iVar2 = ___ratelimit(wcd938x_tx_path_get__rs_351,"wcd938x_tx_path_get");
      if (iVar2 != 0) {
        _printk(&DAT_0011bc7b,"wcd938x_tx_path_get");
      }
      goto LAB_00108750;
    }
    iVar2 = kstrtouint(pcVar5,10,param_2);
    if ((iVar2 < 0) &&
       (iVar3 = ___ratelimit(wcd938x_tx_path_get__rs_353,"wcd938x_tx_path_get"), iVar3 != 0)) {
      _printk(&DAT_0011ba40,"wcd938x_tx_path_get",pcVar4);
    }
  }
  kfree(pcVar4);
LAB_0010875c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd938x_get_logical_addr @ 001087a4 size=208
// signature: undefined wcd938x_get_logical_addr(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

void wcd938x_get_logical_addr(long param_1)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c[0] = 0;
  iVar4 = -0x13;
  do {
    usleep_range_state(4000,0xfaa,2);
    iVar3 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
    if (iVar3 == 0) break;
    bVar1 = iVar4 != 0;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if ((iVar3 != 0) &&
     (iVar4 = ___ratelimit(wcd938x_get_logical_addr__rs,"wcd938x_get_logical_addr"), iVar4 != 0)) {
    _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %llx failed\n","wcd938x_get_logical_addr"
             ,local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
  }
  *(undefined1 *)(param_1 + 0x40) = local_2c[0];
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd938x_suspend @ 00108878 size=360
// signature: undefined wcd938x_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long *plVar6;
  long lVar7;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  plVar6 = *(long **)(param_1 + 0x98);
  if (plVar6 == (long *)0x0) {
    return 0xffffffea;
  }
  lVar7 = *(long *)(*plVar6 + 0x90);
  if (lVar7 == 0) {
    iVar4 = ___ratelimit(wcd938x_suspend__rs,"wcd938x_suspend");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    _dev_err(param_1,"%s: pdata is NULL\n","wcd938x_suspend");
    return 0xffffffea;
  }
  if (((uint)plVar6[0x2c] >> 4 & 1) == 0) {
    cVar2 = *(char *)((long)plVar6 + 0x124);
  }
  else {
    iVar4 = msm_cdc_disable_ondemand_supply
                      (*plVar6,plVar6[0x182],*(undefined8 *)(lVar7 + 0x38),
                       *(undefined4 *)(lVar7 + 0x40),"cdc-vdd-buck");
    if (iVar4 == -0x16) {
      uVar5 = ___ratelimit(wcd938x_suspend__rs_369,"wcd938x_suspend");
      if ((int)uVar5 == 0) {
        return uVar5;
      }
      _dev_err(param_1,"%s: vdd buck is not disabled\n","wcd938x_suspend");
      return 0;
    }
    puVar1 = (ulong *)(plVar6 + 0x2c);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xffffffffffffffef;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    cVar2 = *(char *)((long)plVar6 + 0x124);
  }
  if ((cVar2 != '\0') || ((plVar6[2] != 0 && (*(int *)(plVar6[2] + 0xd0) == 0)))) {
    msm_cdc_set_supplies_lpm_mode
              (*plVar6,plVar6[0x182],*(undefined8 *)(lVar7 + 0x38),*(undefined4 *)(lVar7 + 0x40),1);
    puVar1 = (ulong *)(plVar6 + 0x2c);
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
// wcd938x_resume @ 001089fc size=196
// signature: undefined wcd938x_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_resume(long param_1)

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
        if (((uint)plVar7[0x2c] >> 8 & 1) != 0) {
          msm_cdc_set_supplies_lpm_mode
                    (*plVar7,plVar7[0x182],*(undefined8 *)(lVar6 + 0x38),
                     *(undefined4 *)(lVar6 + 0x40),0);
          puVar1 = (ulong *)(plVar7 + 0x2c);
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
      iVar4 = ___ratelimit(wcd938x_resume__rs,"wcd938x_resume");
      if (iVar4 != 0) {
        _dev_err(param_1,"%s: pdata is NULL\n","wcd938x_resume");
      }
    }
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// wcd938x_writeable_register @ 00108ad0 size=52
// signature: undefined wcd938x_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd938x_writeable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x34d8 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x108b04);
    (*pcVar2)();
  }
  return (byte)(&wcd938x_reg_access)[uVar1] >> 1 & 1;
}



//------------------------------------------------------------
// wcd938x_readable_register @ 00108b08 size=52
// signature: undefined wcd938x_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd938x_readable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x34d8 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x108b3c);
    (*pcVar2)();
  }
  return (&wcd938x_reg_access)[uVar1] & 1;
}



//------------------------------------------------------------
// wcd938x_volatile_register @ 00108b40 size=60
// signature: undefined wcd938x_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wcd938x_volatile_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return false;
  }
  if (0x34d8 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x108b7c);
    (*pcVar2)();
  }
  return ((&wcd938x_reg_access)[uVar1] & 3) == 1;
}



//------------------------------------------------------------
// wcd938x_mbhc_get_impedance @ 00108b80 size=132
// signature: undefined wcd938x_mbhc_get_impedance(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_mbhc_get_impedance(long param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(&wcd938x_mbhc_get_impedance__rs,"wcd938x_mbhc_get_impedance");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011c297;
  }
  else {
    if ((param_2 != 0) && (param_3 != 0)) {
      uVar2 = wcd_mbhc_get_impedance();
      return uVar2;
    }
    iVar1 = ___ratelimit(wcd938x_mbhc_get_impedance__rs_1,"wcd938x_mbhc_get_impedance");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011b066;
  }
  _printk(puVar3,"wcd938x_mbhc_get_impedance");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd938x_mbhc_hs_detect @ 00108c08 size=208
// signature: undefined wcd938x_mbhc_hs_detect(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

undefined8 wcd938x_mbhc_hs_detect(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  long lVar4;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd938x_mbhc_hs_detect__rs,"wcd938x_mbhc_hs_detect");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011bd55;
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar4 != 0) {
      if (*(long *)(lVar4 + 0x100) != 0) {
        uVar2 = wcd_mbhc_start();
        return uVar2;
      }
      iVar1 = ___ratelimit(wcd938x_mbhc_hs_detect__rs_6,"wcd938x_mbhc_hs_detect");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: mbhc not initialized!\n",
               "wcd938x_mbhc_hs_detect");
      return 0xffffffea;
    }
    iVar1 = ___ratelimit(wcd938x_mbhc_hs_detect__rs_4,"wcd938x_mbhc_hs_detect");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011be98;
  }
  _printk(puVar3,"wcd938x_mbhc_hs_detect");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd938x_mbhc_hs_detect_exit @ 00108cdc size=204
// signature: undefined wcd938x_mbhc_hs_detect_exit(void)
// callers: [wcd938x_mbhc_ssr_down]
//------------------------------------------------------------

void wcd938x_mbhc_hs_detect_exit(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd938x_mbhc_hs_detect_exit__rs,"wcd938x_mbhc_hs_detect_exit");
    if (iVar1 == 0) {
      return;
    }
    puVar2 = &DAT_0011bd55;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      if (*(long *)(lVar3 + 0x100) != 0) {
        wcd_mbhc_stop();
        return;
      }
      iVar1 = ___ratelimit(wcd938x_mbhc_hs_detect_exit__rs_9,"wcd938x_mbhc_hs_detect_exit");
      if (iVar1 == 0) {
        return;
      }
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: mbhc not initialized!\n",
               "wcd938x_mbhc_hs_detect_exit");
      return;
    }
    iVar1 = ___ratelimit(wcd938x_mbhc_hs_detect_exit__rs_8,"wcd938x_mbhc_hs_detect_exit");
    if (iVar1 == 0) {
      return;
    }
    puVar2 = &DAT_0011be98;
  }
  _printk(puVar2,"wcd938x_mbhc_hs_detect_exit");
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_ssr_down @ 00108dac size=60
// signature: undefined wcd938x_mbhc_ssr_down(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

void wcd938x_mbhc_ssr_down(long param_1,long param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    wcd938x_mbhc_hs_detect_exit(param_2);
    wcd_mbhc_deinit(param_1);
  }
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_post_ssr_init @ 00108dec size=160
// signature: undefined wcd938x_mbhc_post_ssr_init(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

int wcd938x_mbhc_post_ssr_init(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = -0x16;
  if ((param_1 != 0) && (param_2 != 0)) {
    snd_soc_component_update_bits(param_2,0x3014,0x20,0x20);
    iVar1 = wcd_mbhc_init(param_1,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
               "wcd938x_mbhc_post_ssr_init");
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd938x_mbhc_init @ 00108e90 size=340
// signature: undefined wcd938x_mbhc_init(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

int wcd938x_mbhc_init(long *param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (param_2 == 0) {
    _printk(&DAT_0011bd55,"wcd938x_mbhc_init");
    iVar1 = -0x16;
  }
  else {
    lVar2 = devm_kmalloc(*(undefined8 *)(param_2 + 0x18),0x478,0xdc0);
    if (lVar2 == 0) {
      iVar1 = -0xc;
    }
    else {
      *(undefined8 *)(lVar2 + 0x470) = param_3;
      __init_rwsem(lVar2 + 0x428,"&(&wcd938x_mbhc->notifier)->rwsem",&wcd938x_mbhc_init___key);
      lVar3 = *(long *)(param_2 + 0x18);
      *(undefined8 *)(lVar2 + 0x468) = 0;
      *(undefined4 *)(lVar2 + 0x3d4) = 1;
      lVar4 = *(long *)(lVar3 + 0x90);
      if (lVar4 == 0) {
        _dev_err(lVar3,"%s: pdata pointer is NULL\n","wcd938x_mbhc_init");
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
                 "wcd938x_mbhc_init");
      }
      devm_kfree(*(undefined8 *)(param_2 + 0x18),lVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd938x_mbhc_deinit @ 00108fe8 size=116
// signature: undefined wcd938x_mbhc_deinit(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_deinit(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_0011bd55;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      lVar2 = *(long *)(lVar2 + 0x100);
      if (lVar2 == 0) {
        return;
      }
      wcd_mbhc_deinit(lVar2);
      devm_kfree(*(undefined8 *)(param_1 + 0x18),lVar2);
      return;
    }
    puVar1 = &DAT_0011be98;
  }
  _printk(puVar1,"wcd938x_mbhc_deinit");
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_bcs_enable @ 00109060 size=40
// signature: undefined wcd938x_mbhc_bcs_enable(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_bcs_enable(long param_1,uint param_2)

{
  wcd938x_disable_bcs_before_slow_insert(*(undefined8 *)(param_1 + 0xf8),(param_2 ^ 0xffffffff) & 1)
  ;
  return;
}



//------------------------------------------------------------
// wcd938x_wcd_mbhc_calc_impedance @ 0010908c size=1884
// signature: undefined wcd938x_wcd_mbhc_calc_impedance(void)
// callers: []
//------------------------------------------------------------

void wcd938x_wcd_mbhc_calc_impedance(long param_1,uint *param_2,uint *param_3)

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
  if (((uVar13 & 1) == 0) && ((wcd938x_wcd_mbhc_calc_impedance___already_done & 1) == 0)) {
    wcd938x_wcd_mbhc_calc_impedance___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd938x_wcd_mbhc_calc_impedance");
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1097e0);
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
  puVar21 = &DAT_001182d4;
  puVar18 = &DAT_0011c7a0;
  wcd938x_mbhc_zdet_ramp(lVar17,&DAT_001182d4,(long)&local_70 + 4,0,&DAT_0011c7a0);
  if (local_70._4_4_ - 0x61a81U < 0xfffa627f) {
    bVar5 = 0xc34 < local_70._4_4_ - 0x61a81U >> 8;
    lVar1 = 0x18;
    if (bVar5) {
      lVar1 = 0x24;
    }
    puVar14 = &DAT_001182e0;
    if (bVar5) {
      puVar14 = &DAT_001182ec;
    }
    puVar19 = &DAT_0011c7a8;
    if (bVar5) {
      puVar19 = &DAT_0011c7b0;
    }
    puVar21 = &DAT_001182c8;
    if (31999 < local_70._4_4_) {
      puVar21 = puVar14;
    }
    puVar18 = &_L__const_wcd938x_wcd_mbhc_calc_impedance_d1_a;
    if (31999 < local_70._4_4_) {
      puVar18 = puVar19;
    }
    lVar20 = 0;
    if (31999 < local_70._4_4_) {
      lVar20 = lVar1;
    }
    wcd938x_mbhc_zdet_ramp(lVar17,puVar21,(long)&local_70 + 4,0,puVar18);
    if (local_70._4_4_ < 0x5f5e101) goto LAB_001092e8;
    puVar21 = &DAT_001182d4;
    puVar18 = &DAT_0011c7a0;
    uVar12 = 0xffffffe;
    lVar20 = 0xc;
LAB_00109364:
    *param_2 = uVar12;
  }
  else {
    lVar20 = 0xc;
LAB_001092e8:
    uVar15 = 0x34c7;
    if (399999 < local_70._4_4_) {
      uVar15 = 0x34c8;
    }
    *param_2 = local_70._4_4_ / 1000;
    uVar12 = snd_soc_component_read(lVar17,uVar15);
    if ((uVar12 >> 7 & 1) != 0) {
      uVar12 = uVar12 & 0x7f;
      iVar16 = -0x19;
LAB_0010934c:
      iVar16 = uVar12 * iVar16 + 10000;
      uVar12 = 0;
      if (iVar16 != 0) {
        uVar12 = (int)(*param_2 * 10000) / iVar16;
      }
      goto LAB_00109364;
    }
    if (-0x1900000 < (int)(uVar12 * 0x10000)) {
      uVar12 = (uint)(short)uVar12;
      iVar16 = 0x19;
      goto LAB_0010934c;
    }
  }
  wcd938x_mbhc_zdet_ramp(lVar17,puVar21,0,&local_70,puVar18);
  if ((int)local_70 - 0x61a81U < 0xfffa627f) {
    if ((int)local_70 < 0x124f81) {
LAB_001093c0:
      if (*param_2 == 0xffffffe) {
        if ((int)local_70 < 32000) {
          puVar19 = &_L__const_wcd938x_wcd_mbhc_calc_impedance_d1_a;
          puVar14 = &DAT_001182c8;
        }
        else {
          bVar5 = 0xc34 < (int)local_70 - 0x61a81U >> 8;
          puVar14 = &DAT_001182e0;
          if (bVar5) {
            puVar14 = puVar21;
          }
          puVar19 = &DAT_0011c7a8;
          if (bVar5) {
            puVar19 = puVar18;
          }
          if (1200000 < (int)local_70) {
            puVar19 = &DAT_0011c7b0;
            puVar14 = &DAT_001182ec;
          }
        }
        wcd938x_mbhc_zdet_ramp(lVar17,puVar14,0,&local_70,puVar19);
        puVar18 = puVar19;
      }
    }
    else {
      if (lVar20 - 0x2dU < 0xffffffffffffffd1) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x1097ec);
        (*pcVar4)();
      }
      if (*(short *)(puVar21 + 2) != 6) goto LAB_001093c0;
    }
    iVar16 = (int)local_70;
    if ((int)local_70 < 0x5f5e101) goto LAB_0010947c;
    uVar12 = 0xffffffe;
LAB_001094f4:
    *param_3 = uVar12;
  }
  else {
    iVar16 = (int)local_70;
LAB_0010947c:
    uVar15 = 0x34c9;
    if (399999 < iVar16) {
      uVar15 = 0x34ca;
    }
    *param_3 = iVar16 / 1000;
    uVar12 = snd_soc_component_read(lVar17,uVar15);
    if ((uVar12 >> 7 & 1) != 0) {
      uVar12 = uVar12 & 0x7f;
      iVar16 = -0x19;
LAB_001094d8:
      iVar16 = uVar12 * iVar16 + 10000;
      uVar12 = 0;
      if (iVar16 != 0) {
        uVar12 = (int)(*param_3 * 10000) / iVar16;
      }
      goto LAB_001094f4;
    }
    if (-0x1900000 < (int)(uVar12 * 0x10000)) {
      uVar12 = (uint)(short)uVar12;
      iVar16 = 0x19;
      goto LAB_001094d8;
    }
  }
  uVar12 = *param_2;
  uVar2 = *param_3;
  if (uVar12 == 0xffffffe) {
    if (uVar2 == 0xffffffe) goto LAB_00109548;
  }
  else if (((uVar2 != 0xffffffe) && ((1 < uVar12 || (uVar2 < 3)))) && ((uVar12 < 3 || (1 < uVar2))))
  {
    snd_soc_component_update_bits(lVar17,0x30d8,2,2);
    snd_soc_component_update_bits(lVar17,0x30d2,0x40,1);
    puVar21 = &DAT_001182c8;
    if (0x1f < *param_2) {
      puVar21 = &DAT_001182d4;
    }
    wcd938x_mbhc_zdet_ramp(lVar17,puVar21,&local_74,0,puVar18);
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
        goto LAB_00109730;
      }
    }
    else {
      uVar12 = uVar12 & 0x7f;
      iVar16 = -0x19;
LAB_00109730:
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
    goto LAB_00109548;
  }
  *(undefined4 *)(param_1 + 0x1c4) = 1;
LAB_00109548:
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
// wcd938x_get_hwdep_fw_cal @ 001097f0 size=164
// signature: undefined wcd938x_get_hwdep_fw_cal(void)
// callers: []
//------------------------------------------------------------

long wcd938x_get_hwdep_fw_cal(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xf8);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(wcd938x_get_hwdep_fw_cal__rs,"wcd938x_get_hwdep_fw_cal");
    if (iVar1 != 0) {
      _printk(&DAT_0011b19a,"wcd938x_get_hwdep_fw_cal");
    }
  }
  else {
    lVar2 = wcdcal_get_fw_cal(*(undefined8 *)(param_1 + 0x470));
    if (lVar2 != 0) {
      return lVar2;
    }
    iVar1 = ___ratelimit(wcd938x_get_hwdep_fw_cal__rs_17,"wcd938x_get_hwdep_fw_cal");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(lVar3 + 0x18),"%s: cal not sent by %d\n","wcd938x_get_hwdep_fw_cal",
               param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd938x_mbhc_register_notifier @ 00109898 size=44
// signature: undefined wcd938x_mbhc_register_notifier(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_register_notifier(long param_1,undefined8 param_2,uint param_3)

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
// wcd938x_mbhc_request_irq @ 001098c8 size=52
// signature: undefined wcd938x_mbhc_request_irq(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_request_irq(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  wcd_request_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x130,param_2,param_4,param_3);
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_irq_control @ 00109900 size=52
// signature: undefined wcd938x_mbhc_irq_control(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_irq_control(long param_1,undefined8 param_2,uint param_3)

{
  if ((param_3 & 1) == 0) {
    wcd_disable_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x130);
  }
  else {
    wcd_enable_irq();
  }
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_free_irq @ 00109938 size=44
// signature: undefined wcd938x_mbhc_free_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_mbhc_free_irq(long param_1)

{
  wcd_free_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x130);
  return 0;
}



//------------------------------------------------------------
// wcd938x_mbhc_clk_setup @ 00109968 size=48
// signature: undefined wcd938x_mbhc_clk_setup(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_clk_setup(undefined8 param_1,ulong param_2)

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
// wcd938x_mbhc_btn_to_num @ 0010999c size=36
// signature: undefined wcd938x_mbhc_btn_to_num(void)
// callers: []
//------------------------------------------------------------

uint wcd938x_mbhc_btn_to_num(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x3019);
  return uVar1 & 7;
}



//------------------------------------------------------------
// wcd938x_mbhc_lock_sleep @ 001099c4 size=72
// signature: undefined wcd938x_mbhc_lock_sleep(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_mbhc_lock_sleep(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98) + 0xc48);
  if (*(int *)(pcVar1 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1099f8);
    (*pcVar1)();
  }
  (*pcVar1)();
  return 1;
}



//------------------------------------------------------------
// wcd938x_mbhc_micb_en_status @ 00109a10 size=68
// signature: undefined wcd938x_mbhc_micb_en_status(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_mbhc_micb_en_status(long param_1,int param_2)

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
// wcd938x_mbhc_mbhc_bias_control @ 00109a58 size=40
// signature: undefined wcd938x_mbhc_mbhc_bias_control(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_mbhc_bias_control(undefined8 param_1,uint param_2)

{
  snd_soc_component_update_bits(param_1,0x3015,1,param_2 & 1);
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_hph_pa_on_status @ 00109a84 size=40
// signature: undefined wcd938x_mbhc_hph_pa_on_status(void)
// callers: []
//------------------------------------------------------------

bool wcd938x_mbhc_hph_pa_on_status(undefined8 param_1)

{
  ulong uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x3009);
  return (uVar1 & 0xc0) != 0;
}



//------------------------------------------------------------
// wcd938x_mbhc_program_btn_thr @ 00109ab0 size=540
// signature: undefined wcd938x_mbhc_program_btn_thr(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_program_btn_thr(long param_1,undefined8 param_2,short *param_3,int param_4)

{
  int iVar1;
  
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
    iVar1 = ___ratelimit(wcd938x_mbhc_program_btn_thr__rs,"wcd938x_mbhc_program_btn_thr");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid number of buttons: %d\n",
               "wcd938x_mbhc_program_btn_thr",param_4);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_request_micbias @ 00109cd0 size=32
// signature: undefined wcd938x_mbhc_request_micbias(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_request_micbias(void)

{
  wcd938x_micbias_control();
  return;
}



//------------------------------------------------------------
// wcd938x_mbhc_micb_ramp_control @ 00109cf4 size=112
// signature: undefined wcd938x_mbhc_micb_ramp_control(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_micb_ramp_control(undefined8 param_1,ulong param_2)

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
// wcd938x_mbhc_micb_ctrl_threshold_mic @ 00109d68 size=88
// signature: undefined wcd938x_mbhc_micb_ctrl_threshold_mic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_mbhc_micb_ctrl_threshold_mic(long param_1,int param_2,ulong param_3)

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
      uVar3 = wcd938x_mbhc_micb_adjust_voltage(param_1,uVar1,2);
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
// wcd938x_mbhc_gnd_det_ctrl @ 00109dc4 size=112
// signature: undefined wcd938x_mbhc_gnd_det_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_gnd_det_ctrl(undefined8 param_1,ulong param_2)

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
// wcd938x_mbhc_hph_pull_down_ctrl @ 00109e38 size=88
// signature: undefined wcd938x_mbhc_hph_pull_down_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_hph_pull_down_ctrl(undefined8 param_1,ulong param_2)

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
// wcd938x_mbhc_moisture_config @ 00109e94 size=88
// signature: undefined wcd938x_mbhc_moisture_config(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_moisture_config(long param_1)

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
// wcd938x_mbhc_hph_l_pull_up_control @ 00109ef0 size=48
// signature: undefined wcd938x_mbhc_hph_l_pull_up_control(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_hph_l_pull_up_control(undefined8 param_1,uint param_2)

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
// wcd938x_mbhc_get_moisture_status @ 00109f24 size=160
// signature: undefined wcd938x_mbhc_get_moisture_status(void)
// callers: []
//------------------------------------------------------------

bool wcd938x_mbhc_get_moisture_status(long param_1)

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
// wcd938x_mbhc_moisture_polling_ctrl @ 00109fc8 size=52
// signature: undefined wcd938x_mbhc_moisture_polling_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_moisture_polling_ctrl(long param_1,ulong param_2)

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
// wcd938x_mbhc_moisture_detect_en @ 0010a000 size=64
// signature: undefined wcd938x_mbhc_moisture_detect_en(void)
// callers: []
//------------------------------------------------------------

void wcd938x_mbhc_moisture_detect_en(long param_1,ulong param_2)

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
// wcd938x_mbhc_zdet_ramp @ 0010a040 size=436
// signature: undefined wcd938x_mbhc_zdet_ramp(void)
// callers: [wcd938x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

void wcd938x_mbhc_zdet_ramp
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
    wcd938x_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_4c);
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x80,0,0,0,0);
    *param_3 = local_4c;
  }
  if (param_4 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x40,0x40,0,0,0);
    wcd938x_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_4c);
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
// wcd938x_mbhc_get_result_params @ 0010a1f4 size=476
// signature: undefined wcd938x_mbhc_get_result_params(void)
// callers: [wcd938x_mbhc_zdet_ramp]
//------------------------------------------------------------

void wcd938x_mbhc_get_result_params(long param_1,long param_2,ulong param_3,uint *param_4)

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
    if (uVar6 == 0) goto LAB_0010a394;
  }
  else {
    uVar1 = (-1 << (ulong)(0xe - ((uint)param_3 & 0xffff) & 0x1f)) +
            uVar6 * (int)*(short *)(param_2 + (ulong)(uVar3 >> 0xe & 3) * 2);
    if ((int)uVar1 < 1) {
      if (7 < ((uint)param_3 & 0xffff)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10a3d0);
        (*pcVar4)();
      }
      if (*(int *)(&DAT_0011c7b8 + (param_3 & 0xffff) * 4) <= (int)uVar6) goto LAB_0010a354;
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
LAB_0010a354:
  iVar7 = 899;
  do {
    regmap_read(*(undefined8 *)(param_1 + 0x20),0x3017,(long)&local_60 + 4);
    regmap_read(*(undefined8 *)(param_1 + 0x20),0x3018,&local_60);
    bVar5 = iVar7 == 0;
    iVar7 = iVar7 + -1;
    local_60._4_4_ = (uint)local_60 | local_60._4_4_ << 8;
    if (bVar5) break;
  } while ((local_60._4_4_ & 0x3fff) != 0);
LAB_0010a394:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd938x_hph_impedance_get @ 0010a3d4 size=220
// signature: undefined wcd938x_hph_impedance_get(void)
// callers: []
//------------------------------------------------------------

void wcd938x_hph_impedance_get(long param_1,long param_2)

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
  lVar3 = wcd938x_soc_get_mbhc(lVar5);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(wcd938x_hph_impedance_get__rs,"wcd938x_hph_impedance_get");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: mbhc not initialized!\n",
               "wcd938x_hph_impedance_get");
    }
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
// wcd938x_get_hph_type @ 0010a4b4 size=124
// signature: undefined wcd938x_get_hph_type(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd938x_get_hph_type(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = wcd938x_soc_get_mbhc(lVar4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(wcd938x_get_hph_type__rs,"wcd938x_get_hph_type");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(lVar4 + 0x18),"%s: mbhc not initialized!\n","wcd938x_get_hph_type");
    }
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar2 + 0x1c4);
  }
  return uVar3;
}



//------------------------------------------------------------
// init_module @ 001182fc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&wcd938x_codec_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0011832c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&wcd938x_codec_driver);
  return;
}



//------------------------------------------------------------
// ___ratelimit @ 0011f000 size=1
// signature: undefined ___ratelimit(void)
// callers: [wcd938x_enable_req, wcd938x_mbhc_get_impedance, wcd938x_hph_impedance_get, wcd938x_codec_enable_dmic, wcd938x_swr_dmic_register_notifier, wcd938x_resume, wcd938x_mbhc_hs_detect_exit, wcd938x_wd_handle_irq, wcd938x_codec_enable_vdd_buck, wcd938x_get_hwdep_fw_cal, wcd938x_soc_get_mbhc, wcd938x_codec_force_enable_micbias_v2, wcd938x_tx_path_get, wcd938x_version_read, wcd938x_get_hph_type, wcd938x_codec_get_dev_num, wcd938x_set_port_params, wcd938x_suspend, wcd938x_micbias_control, wcd938x_mbhc_program_btn_thr, wcd938x_reset, wcd938x_populate_dt_data, wcd938x_enable_micbias, wcd938x_variant_read, wcd938x_tx_get_slave_ch_type_idx, wcd938x_get_logical_addr, wcd938x_get_micb_vout_ctl_val, wcd938x_event_notify, wcd938x_probe, wcd938x_tx_channel_config, wcd938x_bind, wcd938x_mbhc_micb_adjust_voltage, wcd938x_rx_hph_mode_put, wcd938x_wakeup, wcd938x_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011f008 size=1
// signature: undefined _printk(void)
// callers: [wcd938x_enable_req, wcd938x_version_read, wcd938x_mbhc_get_impedance, wcd938x_codec_get_dev_num, wcd938x_soc_codec_probe, wcd938x_mbhc_init, wcd938x_swr_dmic_register_notifier, wcd938x_mbhc_hs_detect_exit, wcd938x_wd_handle_irq, wcd938x_enable_micbias, wcd938x_variant_read, wcd938x_tx_get_slave_ch_type_idx, wcd938x_mbhc_deinit, wcd938x_get_micb_vout_ctl_val, wcd938x_tx_channel_config, wcd938x_get_hwdep_fw_cal, wcd938x_bind, wcd938x_mbhc_micb_adjust_voltage, wcd938x_soc_get_mbhc, wcd938x_codec_force_enable_micbias_v2, wcd938x_wakeup, wcd938x_tx_path_get, wcd938x_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011f010 size=1
// signature: undefined mutex_lock(void)
// callers: [wcd938x_enable_micbias, wcd938x_micbias_control, wcd938x_mbhc_micb_adjust_voltage, wcd938x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0011f018 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wcd938x_codec_hphr_dac_event, wcd938x_soc_codec_probe, wcd938x_ear_pa_gain_get, wcd938x_codec_ear_dac_event, wcd938x_mbhc_get_moisture_status, wcd938x_tx_swr_ctrl, wcd938x_wcd_mbhc_calc_impedance, wcd938x_init_reg, wcd938x_mbhc_hph_pa_on_status, wcd938x_mbhc_btn_to_num, wcd938x_event_notify, wcd938x_codec_enable_ear_pa, wcd938x_mbhc_micb_adjust_voltage, wcd938x_codec_hphl_dac_event, wcd938x_mbhc_micb_en_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0011f020 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wcd938x_enable_req, wcd938x_codec_hphr_dac_event, wcd938x_enable_rx2, wcd938x_ear_pa_gain_put, wcd938x_codec_enable_dmic, wcd938x_codec_ear_dac_event, wcd938x_mbhc_zdet_ramp, wcd938x_tx_swr_ctrl, wcd938x_wcd_mbhc_calc_impedance, wcd938x_init_reg, wcd938x_mbhc_gnd_det_ctrl, wcd938x_codec_aux_dac_event, wcd938x_mbhc_moisture_polling_ctrl, wcd938x_codec_enable_hphl_pa, wcd938x_enable_rx3, wcd938x_codec_enable_ear_pa, wcd938x_mbhc_moisture_config, wcd938x_rx_clk_disable, wcd938x_rx_clk_enable, wcd938x_mbhc_clk_setup, wcd938x_mbhc_micb_ramp_control, wcd938x_codec_enable_hphr_pa, wcd938x_mbhc_get_moisture_status, wcd938x_codec_enable_aux_pa, wcd938x_mbhc_post_ssr_init, wcd938x_micbias_control, wcd938x_mbhc_program_btn_thr, wcd938x_mbhc_hph_l_pull_up_control, wcd938x_mbhc_hph_pull_down_ctrl, wcd938x_mbhc_moisture_detect_en, wcd938x_event_notify, wcd938x_tx_channel_config, wcd938x_codec_enable_adc, wcd938x_mbhc_micb_adjust_voltage, wcd938x_mbhc_mbhc_bias_control, wcd938x_enable_rx1, wcd938x_codec_hphl_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0011f028 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd938x_codec_hphr_dac_event, wcd938x_codec_enable_micbias_pullup, __wcd938x_codec_enable_micbias, wcd938x_codec_enable_dmic, wcd938x_codec_enable_hphr_pa, wcd938x_codec_ear_dac_event, wcd938x_codec_enable_aux_pa, wcd938x_wcd_mbhc_calc_impedance, wcd938x_init_reg, wcd938x_reset, wcd938x_get_logical_addr, wcd938x_codec_enable_hphl_pa, wcd938x_enable_rx3, wcd938x_event_notify, wcd938x_codec_enable_ear_pa, wcd938x_codec_enable_vdd_buck, wcd938x_mbhc_get_result_params, wcd938x_bind, wcd938x_mbhc_micb_adjust_voltage, wcd938x_codec_hphl_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011f030 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcd938x_enable_micbias, wcd938x_micbias_control, wcd938x_mbhc_micb_adjust_voltage, wcd938x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0011f038 size=1
// signature: undefined _dev_err(void)
// callers: [wcd938x_get_codec_variant, wcd938x_get_hph_type, wcd938x_soc_codec_probe, wcd938x_set_port_params, wcd938x_hph_impedance_get, wcd938x_codec_enable_dmic, wcd938x_mbhc_init, wcd938x_parse_port_mapping, wcd938x_suspend, wcd938x_micbias_control, wcd938x_mbhc_post_ssr_init, wcd938x_resume, wcd938x_mbhc_hs_detect_exit, wcd938x_mbhc_program_btn_thr, wcd938x_reset, wcd938x_populate_dt_data, wcd938x_get_logical_addr, wcd938x_event_notify, wcd938x_probe, wcd938x_codec_enable_vdd_buck, wcd938x_get_hwdep_fw_cal, wcd938x_bind, wcd938x_soc_codec_remove, wcd938x_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 0011f040 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [wcd938x_codec_enable_hphl_pa, wcd938x_codec_enable_hphr_pa, wcd938x_event_notify, wcd938x_micbias_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 0011f048 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [wcd938x_mbhc_register_notifier, wcd938x_swr_dmic_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 0011f050 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [wcd938x_mbhc_register_notifier, wcd938x_swr_dmic_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_vote @ 0011f058 size=1
// signature: undefined swr_device_wakeup_vote(void)
// callers: [wcd938x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_unvote @ 0011f060 size=1
// signature: undefined swr_device_wakeup_unvote(void)
// callers: [wcd938x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_unvote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0011f068 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wcd938x_enable_micbias, wcd938x_mbhc_zdet_ramp, wcd938x_mbhc_get_result_params, wcd938x_bind, wcd938x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 0011f070 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [wcd938x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 0011f078 size=1
// signature: undefined snd_info_register(void)
// callers: [wcd938x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 0011f080 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [wcd938x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 0011f088 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [wcd938x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0011f090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd938x_populate_dt_data, wcd938x_soc_codec_probe, wcd938x_mbhc_init, wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0011f098 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wcd938x_populate_dt_data, wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 0011f0a0 size=1
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: [wcd938x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_get_power_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011f0a8 size=1
// signature: undefined of_find_property(void)
// callers: [wcd938x_populate_dt_data, wcd938x_probe, wcd938x_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0011f0b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wcd938x_populate_dt_data, wcd938x_probe, wcd938x_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0011f0b8 size=1
// signature: undefined _dev_info(void)
// callers: [wcd938x_populate_dt_data, wcd938x_soc_codec_probe, wcd938x_rx_hph_mode_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011f0c0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd938x_tx_connect_port, wcd938x_version_read, wcd938x_enable_clsh, wcd938x_enable_rx2, wcd938x_hph_impedance_get, wcd938x_tx_master_ch_get, wcd938x_mbhc_zdet_ramp, wcd938x_parse_port_mapping, wcd938x_tx_swr_ctrl, wcd938x_wcd_mbhc_calc_impedance, wcd938x_tx_mode_put, wcd938x_populate_dt_data, wcd938x_variant_read, wcd938x_handle_post_irq, wcd938x_get_logical_addr, wcd938x_enable_rx3, wcd938x_probe, wcd938x_codec_enable_adc, wcd938x_mbhc_get_result_params, wcd938x_tx_master_ch_put, wcd938x_enable_rx1, wcd938x_tx_path_get, wcd938x_tx_mode_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0011f0c8 size=1
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
// platform_driver_unregister @ 0011f0d0 size=1
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
// simple_read_from_buffer @ 0011f0d8 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [wcd938x_version_read, wcd938x_variant_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 0011f0e0 size=1
// signature: undefined msm_cdc_init_supplies(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_init_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 0011f0e8 size=1
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_static_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0011f0f0 size=1
// signature: undefined __kmalloc(void)
// callers: [wcd938x_probe, wcd938x_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011f0f8 size=1
// signature: undefined kfree(void)
// callers: [wcd938x_probe, wcd938x_parse_port_mapping, wcd938x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011f100 size=1
// signature: undefined __mutex_init(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_match_add_release @ 0011f108 size=1
// signature: undefined component_match_add_release(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_match_add_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_add_with_match @ 0011f110 size=1
// signature: undefined component_master_add_with_match(void)
// callers: [wcd938x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_add_with_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_del @ 0011f118 size=1
// signature: undefined component_master_del(void)
// callers: [wcd938x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 0011f120 size=1
// signature: undefined __sw_hweight8(void)
// callers: [wcd938x_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0011f128 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [wcd938x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0011f130 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wcd938x_event_notify, wcd938x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0011f138 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wcd938x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_bind_all @ 0011f140 size=1
// signature: undefined component_bind_all(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_bind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_matching_swr_slave_device @ 0011f148 size=1
// signature: undefined get_matching_swr_slave_device(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_matching_swr_slave_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_init_port_params @ 0011f150 size=1
// signature: undefined swr_init_port_params(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_init_port_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 0011f158 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 0011f160 size=1
// signature: undefined regmap_write(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_init @ 0011f168 size=1
// signature: undefined wcd_irq_init(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_unbind_all @ 0011f170 size=1
// signature: undefined component_unbind_all(void)
// callers: [wcd938x_unbind, wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_unbind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_request_irq @ 0011f178 size=1
// signature: undefined wcd_request_irq(void)
// callers: [wcd938x_mbhc_request_irq, wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_request_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_disable_irq @ 0011f180 size=1
// signature: undefined wcd_disable_irq(void)
// callers: [wcd938x_codec_enable_hphl_pa, wcd938x_codec_enable_hphr_pa, wcd938x_codec_enable_aux_pa, wcd938x_codec_enable_ear_pa, wcd938x_bind, wcd938x_mbhc_irq_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 0011f188 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_exit @ 0011f190 size=1
// signature: undefined wcd_irq_exit(void)
// callers: [wcd938x_unbind, wcd938x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_free_irq @ 0011f198 size=1
// signature: undefined wcd_free_irq(void)
// callers: [wcd938x_unbind, wcd938x_mbhc_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 0011f1a0 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [wcd938x_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 0011f1a8 size=1
// signature: undefined regmap_read(void)
// callers: [wcd938x_handle_post_irq, wcd938x_mbhc_get_result_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 0011f1b0 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 0011f1b8 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cal_create_hwdep @ 0011f1c8 size=1
// signature: undefined wcd_cal_create_hwdep(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cal_create_hwdep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0011f1d0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0011f1d8 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_init @ 0011f1e0 size=1
// signature: undefined wcd_cls_h_init(void)
// callers: [wcd938x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 0011f1e8 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [wcd938x_soc_codec_probe, wcd938x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0011f1f0 size=1
// signature: undefined strnstr(void)
// callers: [wcd938x_tx_get_slave_ch_type_idx, wcd938x_codec_enable_micbias_pullup, __wcd938x_codec_enable_micbias, wcd938x_tx_swr_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 0011f1f8 size=1
// signature: undefined swr_read(void)
// callers: [wcd938x_codec_enable_adc, wcd938x_tx_swr_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 0011f200 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [wcd938x_tx_connect_port, wcd938x_enable_clsh, wcd938x_enable_rx2, wcd938x_enable_rx3, wcd938x_codec_enable_adc, wcd938x_enable_rx1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 0011f208 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [wcd938x_enable_clsh, wcd938x_codec_enable_dmic, wcd938x_codec_enable_hphl_pa, wcd938x_codec_enable_hphr_pa, wcd938x_codec_enable_aux_pa, wcd938x_codec_enable_ear_pa, wcd938x_codec_enable_adc, wcd938x_tx_swr_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 0011f210 size=1
// signature: undefined swr_connect_port(void)
// callers: [wcd938x_tx_connect_port, wcd938x_enable_clsh, wcd938x_enable_rx2, wcd938x_enable_rx3, wcd938x_tx_swr_ctrl, wcd938x_enable_rx1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_is_ondemand_supply @ 0011f218 size=1
// signature: undefined msm_cdc_is_ondemand_supply(void)
// callers: [wcd938x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_is_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_ondemand_supply @ 0011f220 size=1
// signature: undefined msm_cdc_enable_ondemand_supply(void)
// callers: [wcd938x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_enable_irq @ 0011f228 size=1
// signature: undefined wcd_enable_irq(void)
// callers: [wcd938x_codec_enable_hphl_pa, wcd938x_codec_enable_hphr_pa, wcd938x_codec_enable_aux_pa, wcd938x_codec_enable_ear_pa, wcd938x_mbhc_irq_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_fsm @ 0011f230 size=1
// signature: undefined wcd_cls_h_fsm(void)
// callers: [wcd938x_codec_aux_dac_event, wcd938x_codec_enable_hphl_pa, wcd938x_codec_enable_hphr_pa, wcd938x_codec_ear_dac_event, wcd938x_codec_enable_aux_pa, wcd938x_codec_enable_ear_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_fsm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_clsh_set_hph_mode @ 0011f238 size=1
// signature: undefined wcd_clsh_set_hph_mode(void)
// callers: [wcd938x_codec_enable_hphl_pa, wcd938x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_clsh_set_hph_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0011f240 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 0011f248 size=1
// signature: undefined regcache_sync(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0011f250 size=1
// signature: undefined __const_udelay(void)
// callers: [wcd938x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 0011f258 size=1
// signature: undefined kstrndup(void)
// callers: [wcd938x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0011f260 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [wcd938x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 0011f268 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [wcd938x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0011f270 size=1
// signature: undefined kstrtouint(void)
// callers: [wcd938x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 0011f278 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wcd938x_get_logical_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_disable_ondemand_supply @ 0011f280 size=1
// signature: undefined msm_cdc_disable_ondemand_supply(void)
// callers: [wcd938x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_disable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_set_supplies_lpm_mode @ 0011f288 size=1
// signature: undefined msm_cdc_set_supplies_lpm_mode(void)
// callers: [wcd938x_suspend, wcd938x_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_set_supplies_lpm_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_get_impedance @ 0011f2d0 size=1
// signature: undefined wcd_mbhc_get_impedance(void)
// callers: [wcd938x_mbhc_get_impedance, wcd938x_hph_impedance_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_get_impedance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_start @ 0011f2d8 size=1
// signature: undefined wcd_mbhc_start(void)
// callers: [wcd938x_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_stop @ 0011f2e0 size=1
// signature: undefined wcd_mbhc_stop(void)
// callers: [wcd938x_mbhc_hs_detect_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_deinit @ 0011f2e8 size=1
// signature: undefined wcd_mbhc_deinit(void)
// callers: [wcd938x_mbhc_deinit, wcd938x_mbhc_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_deinit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_init @ 0011f2f0 size=1
// signature: undefined wcd_mbhc_init(void)
// callers: [wcd938x_mbhc_init, wcd938x_mbhc_post_ssr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 0011f2f8 size=1
// signature: undefined __init_rwsem(void)
// callers: [wcd938x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0011f300 size=1
// signature: undefined devm_kfree(void)
// callers: [wcd938x_mbhc_deinit, wcd938x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 0011f308 size=1
// signature: undefined mutex_is_locked(void)
// callers: [wcd938x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0011f310 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [wcd938x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0011f318 size=1
// signature: undefined __warn_printk(void)
// callers: [wcd938x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcdcal_get_fw_cal @ 0011f320 size=1
// signature: undefined wcdcal_get_fw_cal(void)
// callers: [wcd938x_get_hwdep_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcdcal_get_fw_cal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



