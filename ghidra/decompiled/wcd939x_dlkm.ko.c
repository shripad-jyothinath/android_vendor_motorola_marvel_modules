// Decompiled by Ghidra 12.2
// Program: wcd939x_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd939x_soc_get_mbhc @ 00101cbc size=136
// signature: undefined wcd939x_soc_get_mbhc(void)
// callers: [wcd939x_get_hph_type, wcd939x_hph_impedance_get]
//------------------------------------------------------------

undefined8 wcd939x_soc_get_mbhc(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(&wcd939x_soc_get_mbhc__rs,"wcd939x_soc_get_mbhc");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0011fcff;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      return *(undefined8 *)(lVar3 + 0x100);
    }
    iVar1 = ___ratelimit(wcd939x_soc_get_mbhc__rs_1,"wcd939x_soc_get_mbhc");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0011f300;
  }
  _printk(puVar2,"wcd939x_soc_get_mbhc");
  return 0;
}



//------------------------------------------------------------
// wcd939x_get_micb_vout_ctl_val @ 00101d48 size=116
// signature: undefined wcd939x_get_micb_vout_ctl_val(void)
// callers: []
//------------------------------------------------------------

uint wcd939x_get_micb_vout_ctl_val(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 - 0xb23U < 0xfffff8c5) {
    iVar1 = ___ratelimit(wcd939x_get_micb_vout_ctl_val__rs,"wcd939x_get_micb_vout_ctl_val");
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      _printk(&DAT_0011f918,"wcd939x_get_micb_vout_ctl_val");
      uVar2 = 0xffffffea;
    }
  }
  else {
    uVar2 = (param_1 - 1000U >> 1 & 0x7fff) / 0x19;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd939x_mbhc_micb_adjust_voltage @ 00101dc0 size=344
// signature: undefined wcd939x_mbhc_micb_adjust_voltage(void)
// callers: [wcd939x_mbhc_micb_ctrl_threshold_mic]
//------------------------------------------------------------

undefined8 wcd939x_mbhc_micb_adjust_voltage(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  
  if (param_3 - 1U < 4) {
    uVar2 = *(undefined4 *)(&DAT_0012015c + (long)(int)(param_3 - 1U) * 4);
    lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x68;
    mutex_lock(lVar1);
    uVar4 = snd_soc_component_read(param_1,uVar2);
    if (param_2 - 0xb23U < 0xfffff8c5) {
      iVar5 = ___ratelimit(wcd939x_get_micb_vout_ctl_val__rs,"wcd939x_get_micb_vout_ctl_val");
      if (iVar5 == 0) {
        uVar6 = 0xffffffea;
      }
      else {
        _printk(&DAT_0011f918,"wcd939x_get_micb_vout_ctl_val");
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
// wcd939x_tx_channel_config @ 00101f1c size=152
// signature: undefined wcd939x_tx_channel_config(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_tx_channel_config(undefined8 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_2 < 4) {
    uVar4 = -(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 | (ulong)param_2 << 2;
    uVar1 = 0;
    if (param_3 != 0) {
      uVar1 = *(undefined4 *)(&DAT_0012016c + uVar4);
    }
    snd_soc_component_update_bits
              (param_1,*(undefined4 *)(&DAT_0012019c + uVar4),*(undefined4 *)(&DAT_0012016c + uVar4)
               ,uVar1);
    uVar3 = 0;
  }
  else {
    iVar2 = ___ratelimit(wcd939x_tx_channel_config__rs,"wcd939x_tx_channel_config");
    if (iVar2 != 0) {
      _printk(&DAT_0011f317,"wcd939x_tx_channel_config",(ulong)param_2);
    }
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// wcd939x_disable_bcs_before_slow_insert @ 00101fb8 size=84
// signature: undefined wcd939x_disable_bcs_before_slow_insert(void)
// callers: [wcd939x_mbhc_bcs_enable]
//------------------------------------------------------------

void wcd939x_disable_bcs_before_slow_insert(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  pcVar1 = *(code **)(lVar2 + 0xc50);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101ffc);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(lVar2 + 0xc48),5,(param_2 ^ 0xffffffff) & 1);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_micbias_control @ 00102010 size=1152
// signature: undefined wcd939x_micbias_control(void)
// callers: [__wcd939x_codec_enable_micbias, wcd939x_codec_enable_micbias_pullup, wcd939x_mbhc_request_micbias]
//------------------------------------------------------------

undefined8 wcd939x_micbias_control(long param_1,uint param_2,undefined4 param_3,uint param_4)

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
  undefined8 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  
  uVar1 = param_2 - 1;
  uVar12 = (ulong)uVar1;
  if (3 < uVar1) {
    iVar3 = ___ratelimit(wcd939x_micbias_control__rs,"wcd939x_micbias_control");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    pcVar5 = "%s: Invalid micbias index, micb_ind:%d\n";
    param_2 = uVar1;
LAB_00102074:
    _dev_err(uVar4,pcVar5,"wcd939x_micbias_control",param_2);
    return 0xffffffea;
  }
  lVar10 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar10 == 0) {
    iVar3 = ___ratelimit(wcd939x_micbias_control__rs_6,"wcd939x_micbias_control");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: wcd939x private data is NULL\n",
             "wcd939x_micbias_control");
    return 0xffffffea;
  }
  uVar14 = 0;
  uVar11 = 0;
  uVar8 = 0;
  uVar13 = 0;
  uVar4 = 0;
  bVar2 = true;
  uVar9 = 0x3022;
  switch(uVar12) {
  case 0:
    break;
  case 1:
    bVar2 = false;
    uVar8 = 1;
    uVar9 = 0x3023;
    uVar4 = 8;
    uVar13 = 6;
    uVar11 = 4;
    uVar14 = 2;
    break;
  case 2:
    uVar14 = 0;
    uVar11 = 0;
    uVar8 = 0;
    uVar13 = 0;
    uVar4 = 0;
    uVar9 = 0x3025;
    break;
  case 3:
    uVar14 = 0;
    uVar11 = 0;
    uVar8 = 0;
    uVar13 = 0;
    uVar4 = 0;
    uVar9 = 0x3026;
    break;
  default:
    iVar3 = ___ratelimit(wcd939x_micbias_control__rs_8,"wcd939x_micbias_control");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    uVar4 = *(undefined8 *)(param_1 + 0x18);
    pcVar5 = "%s: Invalid micbias number: %d\n";
    goto LAB_00102074;
  }
  mutex_lock();
  switch(param_3) {
  case 0:
    if (*(char *)(lVar10 + 0xc90) == '\0') {
LAB_001023b8:
      uVar4 = 0xffffffed;
      goto LAB_001023ec;
    }
    lVar6 = lVar10 + (ulong)uVar1 * 4;
    iVar3 = *(int *)(lVar6 + 0x48);
    *(int *)(lVar6 + 0x48) = iVar3 + 1;
    if ((iVar3 == 0) && (*(int *)(lVar10 + uVar12 * 4 + 0x38) == 0)) {
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
    if (*(char *)(lVar10 + 0xc90) == '\0') goto LAB_001023b8;
    if ((iVar3 == 0) && (*(int *)(lVar10 + uVar12 * 4 + 0x38) == 0)) {
      snd_soc_component_update_bits(param_1,uVar9,0xc0,0);
    }
    break;
  case 2:
    if (*(char *)(lVar10 + 0xc90) == '\0') goto LAB_001023b8;
    lVar6 = lVar10 + (ulong)uVar1 * 4;
    iVar3 = *(int *)(lVar6 + 0x38);
    *(int *)(lVar6 + 0x38) = iVar3 + 1;
    if (iVar3 == 0) {
      snd_soc_component_update_bits(param_1,0x3409,0x80,0x80);
      snd_soc_component_update_bits(param_1,0x3409,0x40,0x40);
      snd_soc_component_update_bits(param_1,0x3409,0x20,0x20);
      snd_soc_component_update_bits(param_1,0x3409,0x10,0x10);
      snd_soc_component_update_bits(param_1,0x3408,0x10,0x10);
      snd_soc_component_update_bits(param_1,0x3417,1,1);
      snd_soc_component_update_bits(param_1,0x306c,7,1);
      snd_soc_component_update_bits(param_1,0x306f,7,1);
      snd_soc_component_update_bits(param_1,0x3072,7,1);
      snd_soc_component_update_bits(param_1,0x3075,7,1);
      snd_soc_component_update_bits(param_1,uVar9,0xc0,0x40);
      if (!bVar2) {
        blocking_notifier_call_chain(*(long *)(lVar10 + 0x100) + 0x428,uVar11);
      }
    }
    if (((uVar8 & param_4) == 1) && (lVar6 = *(long *)(lVar10 + 0x100), lVar6 != 0)) {
LAB_001023e4:
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
    if (*(char *)(lVar10 + 0xc90) == '\0') goto LAB_001023b8;
    if (iVar3 == 0) {
      iVar3 = *(int *)(lVar10 + uVar12 * 4 + 0x48);
      if (iVar3 < 1) {
        if (iVar3 == 0) {
          if (bVar2) {
            uVar4 = 0;
            goto LAB_001023b0;
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
LAB_001023b0:
        snd_soc_component_update_bits(param_1,uVar9,0xc0,uVar4);
      }
    }
    if (((uVar8 & param_4) == 1) && (lVar6 = *(long *)(lVar10 + 0x100), lVar6 != 0)) {
      uVar4 = uVar13;
      goto LAB_001023e4;
    }
  }
  uVar4 = 0;
LAB_001023ec:
  mutex_unlock(lVar10 + 0x68);
  return uVar4;
}



//------------------------------------------------------------
// wcd939x_swr_dmic_register_notifier @ 00102494 size=124
// signature: undefined wcd939x_swr_dmic_register_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_swr_dmic_register_notifier(long param_1,undefined8 param_2,byte param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd939x_swr_dmic_register_notifier__rs,"wcd939x_swr_dmic_register_notifier"
                        );
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      _printk(&DAT_0011f9f8,"wcd939x_swr_dmic_register_notifier");
      uVar2 = 0xffffffea;
    }
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    *(byte *)(lVar3 + 0xca0) = param_3 & 1;
    if ((param_3 & 1) == 0) {
      uVar2 = blocking_notifier_chain_unregister(lVar3 + 0xca8);
    }
    else {
      uVar2 = blocking_notifier_chain_register();
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd939x_codec_force_enable_micbias_v2 @ 00102514 size=400
// signature: undefined wcd939x_codec_force_enable_micbias_v2(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_force_enable_micbias_v2(long param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(wcd939x_codec_force_enable_micbias_v2__rs,
                         "wcd939x_codec_force_enable_micbias_v2");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    _printk(&DAT_0011f9f8,"wcd939x_codec_force_enable_micbias_v2");
    return 0xffffffea;
  }
  if ((param_2 == 1) || (param_2 == 8)) {
    if (0xfffffffb < param_3 - 5U) {
      lVar6 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
      if (*(char *)(lVar6 + 0xc90) == '\0') {
        if (3 < param_3 - 1U) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1026a4);
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
        wcd939x_wakeup(lVar6,1);
        uVar4 = 1;
      }
      else {
        if (param_2 != 1) {
          return 0;
        }
        wcd939x_wakeup(lVar6,1);
        uVar4 = 0;
      }
      wcd939x_enable_micbias(lVar6,param_3,uVar4);
      wcd939x_wakeup(lVar6,0);
      return 0;
    }
    iVar2 = ___ratelimit(wcd939x_codec_force_enable_micbias_v2__rs_13,
                         "wcd939x_codec_force_enable_micbias_v2");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011f3e4;
    param_2 = param_3;
  }
  else {
    iVar2 = ___ratelimit(wcd939x_codec_force_enable_micbias_v2__rs_11,
                         "wcd939x_codec_force_enable_micbias_v2");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011ee8a;
  }
  _printk(puVar3,"wcd939x_codec_force_enable_micbias_v2",param_2);
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd939x_wakeup @ 001026a8 size=204
// signature: undefined wcd939x_wakeup(void)
// callers: [wcd939x_codec_force_enable_micbias_v2, wcd939x_codec_force_enable_micbias]
//------------------------------------------------------------

undefined4 wcd939x_wakeup(long param_1,ulong param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(wcd939x_wakeup__rs,"wcd939x_wakeup");
    if (iVar2 != 0) {
      puVar3 = &DAT_0011fa26;
      goto LAB_00102760;
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
    iVar2 = ___ratelimit(wcd939x_wakeup__rs_41,"wcd939x_wakeup");
    if (iVar2 != 0) {
      puVar3 = &DAT_0011eb06;
LAB_00102760:
      _printk(puVar3,"wcd939x_wakeup");
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd939x_enable_micbias @ 00102774 size=332
// signature: undefined wcd939x_enable_micbias(void)
// callers: [wcd939x_codec_force_enable_micbias_v2]
//------------------------------------------------------------

void wcd939x_enable_micbias(long param_1,int param_2,int param_3)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  int *piVar6;
  
  if (param_1 == 0) {
    iVar4 = ___ratelimit(wcd939x_enable_micbias__rs,"wcd939x_enable_micbias");
    if (iVar4 == 0) {
      return;
    }
    _printk(&DAT_0011ec86,"wcd939x_enable_micbias");
    return;
  }
  uVar3 = param_2 - 1;
  if (3 < uVar3) {
    iVar4 = ___ratelimit(wcd939x_enable_micbias__rs_44,"wcd939x_enable_micbias");
    if (iVar4 == 0) {
      return;
    }
    _printk(&DAT_0011f07b,"wcd939x_enable_micbias",param_2);
    return;
  }
  uVar2 = *(undefined4 *)(&DAT_0012015c + (long)(int)uVar3 * 4);
  mutex_lock(param_1 + 0x68);
  if (param_3 == 1) {
    piVar6 = (int *)(param_1 + (ulong)uVar3 * 4 + 0x48);
    iVar4 = *piVar6;
    if (0 < iVar4) {
      *piVar6 = iVar4 + -1;
      iVar4 = iVar4 + -1;
    }
    if ((iVar4 != 0) || (*(int *)(param_1 + (ulong)uVar3 * 4 + 0x38) != 0)) goto LAB_001028a0;
    uVar5 = 0;
  }
  else {
    if (((param_3 != 0) ||
        (lVar1 = param_1 + (ulong)uVar3 * 4, iVar4 = *(int *)(lVar1 + 0x48),
        *(int *)(lVar1 + 0x48) = iVar4 + 1, iVar4 != 0)) ||
       (*(int *)(param_1 + (ulong)uVar3 * 4 + 0x38) != 0)) goto LAB_001028a0;
    uVar5 = 0x80;
  }
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x20),uVar2,0xc0,uVar5,0,0,0);
LAB_001028a0:
  mutex_unlock(param_1 + 0x68);
  return;
}



//------------------------------------------------------------
// wcd939x_codec_get_dev_num @ 001028c4 size=108
// signature: undefined wcd939x_codec_get_dev_num(void)
// callers: []
//------------------------------------------------------------

ulong wcd939x_codec_get_dev_num(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if ((lVar2 != 0) && (lVar2 = *(long *)(lVar2 + 0x28), lVar2 != 0)) {
      return (ulong)*(byte *)(lVar2 + 0x40);
    }
    iVar1 = ___ratelimit(wcd939x_codec_get_dev_num__rs,"wcd939x_codec_get_dev_num");
    if (iVar1 != 0) {
      _printk(&DAT_0011f9f8,"wcd939x_codec_get_dev_num");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd939x_get_codec_variant @ 00102934 size=80
// signature: undefined wcd939x_get_codec_variant(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_get_codec_variant(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 == 0) {
      _dev_err(*(long *)(param_1 + 0x18),"%s:wcd939x not probed\n","wcd939x_get_codec_variant");
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(lVar2 + 8);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd939x_info_create_codec_entry @ 00102988 size=308
// signature: undefined wcd939x_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_info_create_codec_entry(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (*(long *)(lVar5 + 0xc70) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),"wcd939x");
      *(long *)(lVar5 + 0xc70) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0xc70));
        if ((-1 < iVar1) &&
           (lVar3 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"version",
                               *(undefined8 *)(lVar5 + 0xc70)), lVar3 != 0)) {
          *(long *)(lVar3 + 0x40) = lVar5;
          *(undefined8 *)(lVar3 + 0x10) = 0x20;
          *(undefined2 *)(lVar3 + 0x18) = 1;
          *(undefined1 **)(lVar3 + 0x20) = wcd939x_info_ops;
          iVar1 = snd_info_register();
          if (-1 < iVar1) {
            *(long *)(lVar5 + 0xc78) = lVar3;
            lVar4 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"variant",
                               *(undefined8 *)(lVar5 + 0xc70));
            if (lVar4 != 0) {
              *(long *)(lVar4 + 0x40) = lVar5;
              *(undefined8 *)(lVar4 + 0x10) = 0x20;
              *(undefined2 *)(lVar4 + 0x18) = 1;
              *(undefined1 **)(lVar4 + 0x20) = wcd939x_variant_ops;
              iVar1 = snd_info_register();
              if (-1 < iVar1) {
                *(long *)(lVar5 + 0xc80) = lVar4;
                return 0;
              }
              snd_info_free_entry(lVar4);
            }
          }
          snd_info_free_entry(lVar3);
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0xc70));
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
// wcd939x_populate_dt_data @ 00102ac0 size=3884
// signature: undefined wcd939x_populate_dt_data(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

ulong * wcd939x_populate_dt_data(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  ulong *puVar6;
  undefined8 uVar7;
  long lVar8;
  uint uVar9;
  int local_8c;
  ulong local_88 [11];
  
  lVar8 = sp_el0;
  local_88[10] = *(long *)(lVar8 + 0x638);
  puVar6 = (ulong *)devm_kmalloc(param_1,0x128,0xdc0);
  if (puVar6 == (ulong *)0x0) goto LAB_00103550;
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
  iVar4 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x2e8),"qcom,wcd-rst-gpio-node",0,0,0,local_88);
  uVar3 = local_88[0];
  if (iVar4 != 0) {
    uVar3 = 0;
  }
  *puVar6 = uVar3;
  if (uVar3 == 0) {
    iVar4 = ___ratelimit(wcd939x_populate_dt_data__rs,"wcd939x_populate_dt_data");
    if (iVar4 != 0) {
      _dev_err(param_1,"%s: Looking up %s property in node %s failed\n","wcd939x_populate_dt_data",
               "qcom,wcd-rst-gpio-node",*(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
      puVar6 = (ulong *)0x0;
      goto LAB_00103550;
    }
  }
  else {
    msm_cdc_get_power_supplies(param_1,puVar6 + 0x23,puVar6 + 0x24);
    if ((puVar6[0x23] != 0) && (0 < (int)puVar6[0x24])) {
      puVar1 = (undefined8 *)(param_1 + 0x2e8);
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
      iVar4 = __of_parse_phandle_with_args(*puVar1,"qcom,rx-slave",0,0,0,local_88);
      uVar7 = *puVar1;
      if (iVar4 != 0) {
        local_88[0] = 0;
      }
      local_88[8] = 0;
      local_88[9] = 0;
      local_88[6] = 0;
      local_88[7] = 0;
      local_88[4] = 0;
      local_88[5] = 0;
      puVar6[1] = local_88[0];
      local_88[2] = 0;
      local_88[3] = 0;
      local_88[0] = 0;
      local_88[1] = 0;
      iVar4 = __of_parse_phandle_with_args(uVar7,"qcom,tx-slave",0,0,0,local_88);
      uVar7 = *puVar1;
      uVar3 = local_88[0];
      if (iVar4 != 0) {
        uVar3 = 0;
      }
      local_88[0] = local_88[0] & 0xffffffff00000000;
      puVar6[2] = uVar3;
      lVar8 = of_find_property(uVar7,"qcom,cdc-micbias1-mv",0);
      if (lVar8 == 0) {
        _dev_info(param_1,"%s: Micbias1 DT property not found\n","wcd939x_dt_parse_micbias_info");
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,cdc-micbias1-mv",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,cdc-micbias1-mv",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else {
          *(uint *)(puVar6 + 4) = (uint)local_88[0];
        }
      }
      lVar8 = of_find_property(*puVar1,"qcom,cdc-micbias2-mv",0);
      if (lVar8 == 0) {
        _dev_info(param_1,"%s: Micbias2 DT property not found\n","wcd939x_dt_parse_micbias_info");
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,cdc-micbias2-mv",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,cdc-micbias2-mv",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else {
          *(uint *)((long)puVar6 + 0x24) = (uint)local_88[0];
        }
      }
      lVar8 = of_find_property(*puVar1,"qcom,cdc-micbias3-mv",0);
      if (lVar8 == 0) {
        _dev_info(param_1,"%s: Micbias3 DT property not found\n","wcd939x_dt_parse_micbias_info");
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,cdc-micbias3-mv",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,cdc-micbias3-mv",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else {
          *(uint *)(puVar6 + 5) = (uint)local_88[0];
        }
      }
      lVar8 = of_find_property(*puVar1,"qcom,cdc-micbias4-mv",0);
      if (lVar8 == 0) {
        _dev_info(param_1,"%s: Micbias4 DT property not found\n","wcd939x_dt_parse_micbias_info");
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,cdc-micbias4-mv",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,cdc-micbias4-mv",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else {
          *(uint *)((long)puVar6 + 0x2c) = (uint)local_88[0];
        }
      }
      uVar7 = *puVar1;
      *(undefined8 *)((long)puVar6 + 0xa4) = 0x50000007f;
      puVar6[0x1b] = 0;
      puVar6[0x1c] = 0x221000001f4;
      local_8c = 0;
      local_88[0] = local_88[0] & 0xffffffff00000000;
      puVar6[0x1d] = 0x2d;
      puVar6[0x1e] = 0;
      puVar6[0x10] = 0x5000000b7;
      puVar6[0x11] = 0x14a;
      *(undefined8 *)((long)puVar6 + 0xac) = 0x14a;
      puVar6[7] = 0x122;
      *(undefined4 *)((long)puVar6 + 0x54) = 0x122;
      *(undefined4 *)(puVar6 + 0xe) = 0xe5;
      *(undefined8 *)((long)puVar6 + 0x44) = 0x13600000000;
      puVar6[0x21] = 0x26aa00000000;
      *(undefined4 *)(puVar6 + 0x22) = 0x26b2;
      puVar6[0xb] = 0;
      puVar6[0xc] = 0x13600000000;
      *(undefined8 *)((long)puVar6 + 0x4c) = 1;
      puVar6[0xd] = 1;
      *(undefined4 *)(puVar6 + 0x12) = 0;
      *(undefined4 *)((long)puVar6 + 0x94) = 0x212;
      *(undefined4 *)((long)puVar6 + 0xb4) = 0;
      *(undefined4 *)(puVar6 + 0x17) = 0x212;
      puVar6[0x19] = 0;
      puVar6[0x1a] = 0;
      puVar6[0x13] = 0x100000005;
      *(undefined8 *)((long)puVar6 + 0xbc) = 0x100000005;
      *(undefined4 *)(puVar6 + 0x14) = 5;
      *(undefined4 *)((long)puVar6 + 0xc4) = 5;
      *(undefined8 *)((long)puVar6 + 0x74) = 0xd;
      *(undefined4 *)(puVar6 + 8) = 0;
      puVar6[0x1f] = 0x1f400000000;
      puVar6[0x20] = 0x1f001f;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-xtalk-config",0);
      if (lVar8 != 0) {
        iVar4 = of_property_read_variable_u32_array
                          (*puVar1,"qcom,usbcss-hs-xtalk-config",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-xtalk-config",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else if ((uint)local_88[0] < 3) {
          *(uint *)((long)puVar6 + 0x104) = (uint)local_88[0];
        }
      }
      lVar8 = of_find_property(*puVar1,"qcom,usbcss-hs-lin-k-aud",0);
      if (lVar8 != 0) {
        iVar4 = of_property_read_variable_u32_array
                          (*puVar1,"qcom,usbcss-hs-lin-k-aud",&local_8c,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_s32","qcom,usbcss-hs-lin-k-aud",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else if (local_8c + 0x5aU < 0x276b) {
          *(int *)((long)puVar6 + 0x74) = local_8c;
        }
      }
      lVar8 = of_find_property(*puVar1,"qcom,usbcss-hs-diff-slope",0);
      if (lVar8 != 0) {
        iVar4 = of_property_read_variable_u32_array
                          (*puVar1,"qcom,usbcss-hs-diff-slope",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-diff-slope",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        }
        else if ((uint)local_88[0] - 0x2648 < 0xc9) {
          *(uint *)((long)puVar6 + 0x10c) = (uint)local_88[0];
        }
      }
      uVar3 = puVar6[0x1c];
      lVar8 = of_find_property(*puVar1,"qcom,usbcss-hs-rdson-6v",0);
      if (lVar8 == 0) {
LAB_00102eec:
        local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
        iVar4 = (int)uVar3;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-rdson-6v",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-rdson-6v",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_00102eec;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00102eec;
      }
      uVar7 = *puVar1;
      iVar5 = *(int *)((long)puVar6 + 0xe4);
      *(int *)(puVar6 + 0x1c) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-rdson-3p6v",0);
      if (lVar8 == 0) {
LAB_00102f48:
        local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
        iVar4 = iVar5;
      }
      else {
        iVar4 = of_property_read_variable_u32_array
                          (*puVar1,"qcom,usbcss-hs-rdson-3p6v",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-rdson-3p6v",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_00102f48;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00102f48;
      }
      uVar7 = *puVar1;
      iVar5 = *(int *)((long)puVar6 + 0xfc);
      *(int *)((long)puVar6 + 0xe4) = iVar4;
      *(int *)(puVar6 + 0x1d) = iVar4 - (int)puVar6[0x1c];
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-rcom-margin",0);
      if (lVar8 == 0) {
LAB_00102fac:
        local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
        iVar4 = iVar5;
      }
      else {
        iVar4 = of_property_read_variable_u32_array
                          (*puVar1,"qcom,usbcss-hs-rcom-margin",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-rcom-margin",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_00102fac;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00102fac;
      }
      uVar7 = *puVar1;
      uVar3 = puVar6[9];
      *(int *)((long)puVar6 + 0xfc) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r1-l",0);
      if (lVar8 == 0) {
LAB_00103008:
        local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
        iVar4 = (int)uVar3;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r1-l",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-r1-l",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_00103008;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00103008;
      }
      uVar7 = *puVar1;
      iVar5 = *(int *)((long)puVar6 + 100);
      *(int *)(puVar6 + 9) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r1-r",0);
      if (lVar8 == 0) {
LAB_00103064:
        local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
        iVar4 = iVar5;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r1-r",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-r1-r",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_00103064;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00103064;
      }
      uVar7 = *puVar1;
      iVar5 = *(int *)((long)puVar6 + 0x4c);
      *(int *)((long)puVar6 + 100) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r3-l",0);
      if (lVar8 == 0) {
LAB_001030c0:
        local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
        iVar4 = iVar5;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r3-l",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-r3-l",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_001030c0;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_001030c0;
      }
      uVar7 = *puVar1;
      uVar3 = puVar6[0xd];
      *(int *)((long)puVar6 + 0x4c) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r3-r",0);
      if (lVar8 == 0) {
LAB_0010311c:
        local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
        iVar4 = (int)uVar3;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r3-r",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-r3-r",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_0010311c;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_0010311c;
      }
      uVar7 = *puVar1;
      iVar5 = *(int *)((long)puVar6 + 0x94);
      *(int *)(puVar6 + 0xd) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r4-sbu1",0);
      if (lVar8 == 0) {
LAB_00103178:
        local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
        iVar4 = iVar5;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r4-sbu1",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-r4-sbu1",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_00103178;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00103178;
      }
      uVar7 = *puVar1;
      uVar3 = puVar6[0x17];
      *(int *)((long)puVar6 + 0x94) = iVar4;
      lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r4-sbu2",0);
      if (lVar8 == 0) {
LAB_001031d4:
        local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
        iVar4 = (int)uVar3;
      }
      else {
        iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r4-sbu2",local_88,1,0);
        if (iVar4 < 0) {
          _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                   "wcd939x_read_of_property_u32","qcom,usbcss-hs-r4-sbu2",
                   *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
          goto LAB_001031d4;
        }
        iVar4 = (uint)local_88[0];
        if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_001031d4;
      }
      *(int *)(puVar6 + 0x17) = iVar4;
      if (*(int *)((long)puVar6 + 0x104) == 1) {
        iVar4 = *(int *)((long)puVar6 + 0x9c);
        lVar8 = of_find_property(*puVar1,"qcom,usbcss-hs-r6-sbu1",0);
        if (lVar8 == 0) {
LAB_00103374:
          local_88[0] = CONCAT44(local_88[0]._4_4_,iVar4);
          iVar5 = iVar4;
        }
        else {
          iVar5 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r6-sbu1",local_88,1,0)
          ;
          if (iVar5 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd939x_read_of_property_u32","qcom,usbcss-hs-r6-sbu1",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
            goto LAB_00103374;
          }
          iVar5 = (uint)local_88[0];
          if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00103374;
        }
        uVar7 = *puVar1;
        uVar3 = puVar6[0x18];
        *(int *)((long)puVar6 + 0x9c) = iVar5;
        lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r6-sbu2",0);
        if (lVar8 == 0) {
LAB_001033d0:
          local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
          iVar4 = (int)uVar3;
        }
        else {
          iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r6-sbu2",local_88,1,0)
          ;
          if (iVar4 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd939x_read_of_property_u32","qcom,usbcss-hs-r6-sbu2",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
            goto LAB_001033d0;
          }
          iVar4 = (uint)local_88[0];
          if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_001033d0;
        }
        uVar3 = puVar6[0x14];
        uVar7 = *puVar1;
        *(int *)(puVar6 + 0x18) = iVar4;
        *(int *)(puVar6 + 0x11) = *(int *)((long)puVar6 + 0x94) + *(int *)((long)puVar6 + 0x9c);
        *(int *)((long)puVar6 + 0xac) = (int)puVar6[0x17] + iVar4;
        lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r7-sbu1",0);
        if (lVar8 == 0) {
LAB_00103444:
          local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
          iVar4 = (int)uVar3;
        }
        else {
          iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r7-sbu1",local_88,1,0)
          ;
          if (iVar4 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd939x_read_of_property_u32","qcom,usbcss-hs-r7-sbu1",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
            goto LAB_00103444;
          }
          iVar4 = (uint)local_88[0];
          if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00103444;
        }
        uVar7 = *puVar1;
        iVar5 = *(int *)((long)puVar6 + 0xc4);
        *(int *)(puVar6 + 0x14) = iVar4;
        *(int *)((long)puVar6 + 0x84) = iVar4;
        lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r7-sbu2",0);
        if (lVar8 == 0) {
LAB_001034a4:
          local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
          iVar4 = iVar5;
        }
        else {
          iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r7-sbu2",local_88,1,0)
          ;
          if (iVar4 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd939x_read_of_property_u32","qcom,usbcss-hs-r7-sbu2",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
            goto LAB_001034a4;
          }
          iVar4 = (uint)local_88[0];
          if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_001034a4;
        }
        *(int *)((long)puVar6 + 0xc4) = iVar4;
        *(int *)(puVar6 + 0x15) = iVar4;
      }
      else if (*(int *)((long)puVar6 + 0x104) == 2) {
        uVar3 = puVar6[0x13];
        lVar8 = of_find_property(*puVar1,"qcom,usbcss-hs-r5-sbu1",0);
        if (lVar8 == 0) {
LAB_00103244:
          local_88[0] = CONCAT44(local_88[0]._4_4_,(int)uVar3);
          iVar4 = (int)uVar3;
        }
        else {
          iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r5-sbu1",local_88,1,0)
          ;
          if (iVar4 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd939x_read_of_property_u32","qcom,usbcss-hs-r5-sbu1",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
            goto LAB_00103244;
          }
          iVar4 = (uint)local_88[0];
          if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_00103244;
        }
        uVar7 = *puVar1;
        iVar5 = *(int *)((long)puVar6 + 0xbc);
        *(int *)(puVar6 + 0x13) = iVar4;
        lVar8 = of_find_property(uVar7,"qcom,usbcss-hs-r5-sbu2",0);
        if (lVar8 == 0) {
LAB_001032a0:
          local_88[0] = CONCAT44(local_88[0]._4_4_,iVar5);
          iVar4 = iVar5;
        }
        else {
          iVar4 = of_property_read_variable_u32_array(*puVar1,"qcom,usbcss-hs-r5-sbu2",local_88,1,0)
          ;
          if (iVar4 < 0) {
            _dev_err(param_1,"%s: Looking up %s property in node %s failed\n",
                     "wcd939x_read_of_property_u32","qcom,usbcss-hs-r5-sbu2",
                     *(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
            goto LAB_001032a0;
          }
          iVar4 = (uint)local_88[0];
          if ((uint)local_88[0] - 0x4e21 < 0xffffb1e0) goto LAB_001032a0;
        }
        *(int *)((long)puVar6 + 0xbc) = iVar4;
        iVar4 = (int)puVar6[0x17] + iVar4;
        *(int *)((long)puVar6 + 0x84) = *(int *)((long)puVar6 + 0x94) + (int)puVar6[0x13];
        *(undefined4 *)(puVar6 + 0x11) = 0x7d;
        *(int *)(puVar6 + 0x15) = iVar4;
        *(undefined4 *)((long)puVar6 + 0xac) = 0x7d;
      }
      else {
        iVar4 = (int)puVar6[0x15];
      }
      iVar5 = (int)puVar6[0x11] + *(int *)((long)puVar6 + 0x84);
      iVar4 = *(int *)((long)puVar6 + 0xac) + iVar4;
      *(int *)((long)puVar6 + 0x8c) = iVar5;
      *(int *)(puVar6 + 0x12) = (int)puVar6[0x10] + (int)puVar6[0x1e] + iVar5;
      *(int *)(puVar6 + 0x16) = iVar4;
      *(int *)((long)puVar6 + 0xb4) = (int)puVar6[0x1e] + *(int *)((long)puVar6 + 0xa4) + iVar4;
      *(int *)(puVar6 + 8) =
           *(int *)((long)puVar6 + 0x3c) + (int)puVar6[7] + *(int *)((long)puVar6 + 0x4c);
      uVar9 = *(uint *)((long)puVar6 + 0xe4) - 200;
      iVar4 = (int)puVar6[0x1c] + ((uint)(*(int *)((long)puVar6 + 0xac) + (int)puVar6[0x11]) >> 1);
      if (199 < uVar9) {
        uVar9 = 200;
      }
      uVar2 = 0;
      if (199 < *(uint *)((long)puVar6 + 0xe4)) {
        uVar2 = uVar9;
      }
      *(int *)((long)puVar6 + 0x5c) =
           (int)puVar6[0xb] + *(int *)((long)puVar6 + 0x54) + (int)puVar6[0xd];
      *(int *)(puVar6 + 0x19) = iVar4;
      *(int *)((long)puVar6 + 0xcc) = iVar4;
      *(int *)(puVar6 + 0x1a) = iVar4;
      *(int *)((long)puVar6 + 0xd4) = iVar4;
      *(uint *)((long)puVar6 + 0xec) = uVar2;
      wcd_usbss_linearizer_rdac_cal_code_select(1);
      goto LAB_00103550;
    }
    iVar4 = ___ratelimit(wcd939x_populate_dt_data__rs_36,"wcd939x_populate_dt_data");
    if (iVar4 != 0) {
      _dev_err(param_1,"%s: no power supplies defined for codec\n","wcd939x_populate_dt_data");
      puVar6 = (ulong *)0x0;
      goto LAB_00103550;
    }
  }
  puVar6 = (ulong *)0x0;
LAB_00103550:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}



//------------------------------------------------------------
// wcd939x_version_read @ 001039f0 size=264
// signature: undefined wcd939x_version_read(void)
// callers: []
//------------------------------------------------------------

void wcd939x_version_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_40;
  undefined5 local_38;
  undefined2 uStack_33;
  char cStack_31;
  undefined5 local_30;
  undefined2 uStack_2b;
  undefined1 uStack_29;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_33 = 0;
  cStack_31 = '\0';
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0;
  uStack_2b = 0;
  uStack_29 = 0;
  local_40 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    iVar3 = ___ratelimit(wcd939x_version_read__rs,"wcd939x_version_read");
    if (iVar3 == 0) {
      uVar5 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0011eb20,"wcd939x_version_read");
      uVar5 = 0xffffffffffffffea;
    }
    goto LAB_00103ab4;
  }
  uVar1 = *(uint *)(*(long *)(param_1 + 0x40) + 0xc68);
  if (uVar1 < 2) {
    puVar4 = (undefined8 *)&DAT_0011f4fc;
LAB_00103a68:
    uVar6 = *(undefined8 *)((long)puVar4 + 5);
    uVar5 = 0xc;
    local_38 = (undefined5)*puVar4;
    uStack_33 = (undefined2)uVar6;
    cStack_31 = (char)((ulong)uVar6 >> 0x10);
    local_30 = (undefined5)((ulong)uVar6 >> 0x18);
  }
  else {
    if (uVar1 == 2) {
      puVar4 = (undefined8 *)&DAT_0011f84e;
      goto LAB_00103a68;
    }
    uVar5 = 0xe;
    local_38 = s_VER_UNDEFINED_0011f335._0_5_;
    uStack_33 = s_VER_UNDEFINED_0011f335._5_2_;
    cStack_31 = s_VER_UNDEFINED_0011f335[7];
    local_30 = s_VER_UNDEFINED_0011f335._8_5_;
    uStack_2b = s_VER_UNDEFINED_0011f335._13_2_;
  }
  uVar5 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,uVar5);
LAB_00103ab4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_variant_read @ 00103afc size=260
// signature: undefined wcd939x_variant_read(void)
// callers: []
//------------------------------------------------------------

void wcd939x_variant_read
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
    iVar2 = ___ratelimit(wcd939x_variant_read__rs,"wcd939x_variant_read");
    if (iVar2 == 0) {
      uVar4 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0011eb20,"wcd939x_variant_read");
      uVar4 = 0xffffffffffffffea;
    }
    goto LAB_00103bbc;
  }
  iVar2 = *(int *)(*(long *)(param_1 + 0x40) + 8);
  if (iVar2 == 5) {
    pcVar3 = "WCD9395\n";
LAB_00103b74:
    uVar4 = 8;
    local_38[8] = '\0';
    local_38._0_7_ = SUB87(*(undefined8 *)pcVar3,0);
    local_38[7] = (char)((ulong)*(undefined8 *)pcVar3 >> 0x38);
  }
  else {
    if (iVar2 == 0) {
      pcVar3 = "WCD9390\n";
      goto LAB_00103b74;
    }
    uVar4 = 0xe;
    local_38._0_7_ = s_VER_UNDEFINED_0011f335._0_7_;
    local_38[7] = s_VER_UNDEFINED_0011f335[7];
    local_38[8] = s_VER_UNDEFINED_0011f335[8];
    uStack_2f = s_VER_UNDEFINED_0011f335._9_6_;
  }
  uVar4 = simple_read_from_buffer(param_4,param_5,&local_40,local_38,uVar4);
LAB_00103bbc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_probe @ 00103c04 size=2112
// signature: undefined wcd939x_probe(void)
// callers: []
//------------------------------------------------------------

uint wcd939x_probe(long param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
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
  plVar6 = (long *)devm_kmalloc(lVar1,0xcf0,0xdc0);
  if (plVar6 == (long *)0x0) {
    uVar3 = 0xfffffff4;
    goto LAB_001043c4;
  }
  *(long **)(param_1 + 0xa8) = plVar6;
  *plVar6 = lVar1;
  plVar7 = (long *)wcd939x_populate_dt_data(lVar1);
  if (plVar7 == (long *)0x0) {
    pcVar10 = "%s: Fail to obtain platform data\n";
    goto LAB_001042f8;
  }
  *(long **)(param_1 + 0xa0) = plVar7;
  plVar6[3] = *plVar7;
  uVar3 = msm_cdc_init_supplies(lVar1,plVar6 + 0x185,plVar7[0x23],(int)plVar7[0x24]);
  if (plVar6[0x185] == 0) {
    pcVar10 = "%s: Cannot init wcd supplies\n";
    goto LAB_001043b4;
  }
  plVar12 = *(long **)(*(long *)(param_1 + 0x70) + 0x90);
  if (plVar12 == (long *)0x0) {
    pcVar10 = "%s: platform data from parent is NULL\n";
  }
  else {
    lVar13 = *plVar12;
    plVar6[0x189] = lVar13;
    if (lVar13 == 0) {
      pcVar10 = "%s: handle is NULL\n";
    }
    else {
      lVar13 = plVar12[1];
      plVar6[0x18a] = lVar13;
      if (lVar13 == 0) {
        pcVar10 = "%s: update_wcd_event api is null!\n";
      }
      else {
        lVar13 = plVar12[2];
        plVar6[0x18b] = lVar13;
        if (lVar13 != 0) {
          uVar3 = msm_cdc_enable_static_supplies(lVar1,plVar6[0x185],plVar7[0x23],(int)plVar7[0x24])
          ;
          if (uVar3 == 0) {
            uVar8 = msm_cdc_is_ondemand_supply
                              (*plVar6,plVar6[0x185],plVar7[0x23],(int)plVar7[0x24],"cdc-vdd-px");
            if (((uVar8 & 1) == 0) ||
               (uVar3 = msm_cdc_enable_ondemand_supply
                                  (*plVar6,plVar6[0x185],plVar7[0x23],(int)plVar7[0x24],"cdc-vdd-px"
                                  ), uVar3 == 0)) {
              uVar4 = wcd939x_parse_port_mapping(lVar1,"qcom,rx_swr_ch_map",1);
              uVar3 = wcd939x_parse_port_mapping(lVar1,"qcom,tx_swr_ch_map",0);
              uVar3 = uVar3 | uVar4;
              if (uVar3 == 0) {
                lVar15 = *(long *)(param_1 + 0xa8);
                local_a8[0] = local_a8[0] & 0xffffffff00000000;
                lVar13 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-tx-port-params"
                                          ,local_a8);
                uVar8 = local_a8[0];
                if (lVar13 == 0) {
                  pcVar10 = "missing port mapping prop %s\n";
                  pcVar11 = "qcom,swr-tx-port-params";
LAB_00104350:
                  _dev_err(lVar1,pcVar10,pcVar11);
                  uVar3 = 0xffffffea;
                }
                else {
                  uVar4 = (uint)local_a8[0];
                  if (((uint)local_a8[0] & 0xffffffe0) != 0x80) {
                    pcVar10 = "%s: port params not provided for all usecases\n";
                    pcVar11 = "wcd939x_parse_port_params";
                    goto LAB_00104350;
                  }
                  puVar9 = (undefined4 *)__kmalloc(local_a8[0] & 0xffffffff,0xdc0);
                  if (puVar9 == (undefined4 *)0x0) {
                    uVar3 = 0xfffffff4;
                  }
                  else {
                    uVar3 = of_property_read_variable_u32_array
                                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-tx-port-params",
                                       puVar9,0x20,0);
                    if (-1 < (int)uVar3) {
                      if (uVar4 < 4) {
LAB_0010443c:
                    /* WARNING: Does not return */
                        pcVar2 = (code *)SoftwareBreakpoint(1,0x104440);
                        (*pcVar2)();
                      }
                      *(undefined4 *)(lVar15 + 0xb84) = *puVar9;
                      if (((((((uVar8 & 0xfffffffc) == 4) ||
                             (*(undefined4 *)(lVar15 + 0xb88) = puVar9[1], uVar4 < 8)) ||
                            ((uVar8 & 0xfffffffc) == 8)) ||
                           ((*(undefined4 *)(lVar15 + 0xb8c) = puVar9[2], uVar4 < 0xc ||
                            ((uVar8 & 0xfffffffc) == 0xc)))) ||
                          (((*(undefined4 *)(lVar15 + 0xb90) = puVar9[3], uVar4 < 0x10 ||
                            (((uVar8 & 0xfffffffc) == 0x10 ||
                             (*(undefined4 *)(lVar15 + 0xb94) = puVar9[4], uVar4 < 0x14)))) ||
                           ((uVar8 & 0xfffffffc) == 0x14)))) ||
                         ((((*(undefined4 *)(lVar15 + 0xb98) = puVar9[5], uVar4 < 0x18 ||
                            ((uVar8 & 0xfffffffc) == 0x18)) ||
                           (*(undefined4 *)(lVar15 + 0xb9c) = puVar9[6], uVar4 < 0x1c)) ||
                          ((uVar8 & 0xfffffffc) == 0x1c)))) goto LAB_0010443c;
                      *(undefined4 *)(lVar15 + 0xba0) = puVar9[7];
                      *(long *)(lVar15 + 0xc08) = lVar15 + 0xb84;
                      if (((((uVar4 < 0x20) || ((uVar8 & 0xfffffffc) == 0x20)) ||
                           ((*(undefined4 *)(lVar15 + 0xba4) = puVar9[8], uVar4 < 0x24 ||
                            (((uVar8 & 0xfffffffc) == 0x24 ||
                             (*(undefined4 *)(lVar15 + 0xba8) = puVar9[9], uVar4 < 0x28)))))) ||
                          ((((uVar8 & 0xfffffffc) == 0x28 ||
                            (((*(undefined4 *)(lVar15 + 0xbac) = puVar9[10], uVar4 < 0x2c ||
                              ((uVar8 & 0xfffffffc) == 0x2c)) ||
                             (*(undefined4 *)(lVar15 + 0xbb0) = puVar9[0xb], uVar4 < 0x30)))) ||
                           ((((uVar8 & 0xfffffffc) == 0x30 ||
                             (*(undefined4 *)(lVar15 + 0xbb4) = puVar9[0xc], uVar4 < 0x34)) ||
                            (((uVar8 & 0xfffffffc) == 0x34 ||
                             ((*(undefined4 *)(lVar15 + 3000) = puVar9[0xd], uVar4 < 0x38 ||
                              ((uVar8 & 0xfffffffc) == 0x38)))))))))) ||
                         ((*(undefined4 *)(lVar15 + 0xbbc) = puVar9[0xe], uVar4 < 0x3c ||
                          ((uVar8 & 0xfffffffc) == 0x3c)))) goto LAB_0010443c;
                      *(undefined4 *)(lVar15 + 0xbc0) = puVar9[0xf];
                      *(long *)(lVar15 + 0xc10) = lVar15 + 0xba4;
                      if (((((((uVar4 < 0x40) || ((uVar8 & 0xfffffffc) == 0x40)) ||
                             (*(undefined4 *)(lVar15 + 0xbc4) = puVar9[0x10], uVar4 < 0x44)) ||
                            (((uVar8 & 0xfffffffc) == 0x44 ||
                             (*(undefined4 *)(lVar15 + 0xbc8) = puVar9[0x11], uVar4 < 0x48)))) ||
                           (((uVar8 & 0xfffffffc) == 0x48 ||
                            ((*(undefined4 *)(lVar15 + 0xbcc) = puVar9[0x12], uVar4 < 0x4c ||
                             ((uVar8 & 0xfffffffc) == 0x4c)))))) ||
                          ((*(undefined4 *)(lVar15 + 0xbd0) = puVar9[0x13], uVar4 < 0x50 ||
                           ((((uVar8 & 0xfffffffc) == 0x50 ||
                             (*(undefined4 *)(lVar15 + 0xbd4) = puVar9[0x14], uVar4 < 0x54)) ||
                            ((uVar8 & 0xfffffffc) == 0x54)))))) ||
                         (((*(undefined4 *)(lVar15 + 0xbd8) = puVar9[0x15], uVar4 < 0x58 ||
                           ((uVar8 & 0xfffffffc) == 0x58)) ||
                          ((*(undefined4 *)(lVar15 + 0xbdc) = puVar9[0x16], uVar4 < 0x5c ||
                           ((uVar8 & 0xfffffffc) == 0x5c)))))) goto LAB_0010443c;
                      *(undefined4 *)(lVar15 + 0xbe0) = puVar9[0x17];
                      *(long *)(lVar15 + 0xc18) = lVar15 + 0xbc4;
                      if ((((uVar4 < 0x60) || ((uVar8 & 0xfffffffc) == 0x60)) ||
                          (*(undefined4 *)(lVar15 + 0xbe4) = puVar9[0x18], uVar4 < 100)) ||
                         (((((((uVar8 & 0xfffffffc) == 100 ||
                              (*(undefined4 *)(lVar15 + 0xbe8) = puVar9[0x19], uVar4 < 0x68)) ||
                             ((uVar8 & 0xfffffffc) == 0x68)) ||
                            (((*(undefined4 *)(lVar15 + 0xbec) = puVar9[0x1a], uVar4 < 0x6c ||
                              ((uVar8 & 0xfffffffc) == 0x6c)) ||
                             ((*(undefined4 *)(lVar15 + 0xbf0) = puVar9[0x1b], uVar4 < 0x70 ||
                              (((uVar8 & 0xfffffffc) == 0x70 ||
                               (*(undefined4 *)(lVar15 + 0xbf4) = puVar9[0x1c], uVar4 < 0x74))))))))
                           || ((uVar8 & 0xfffffffc) == 0x74)) ||
                          ((((*(undefined4 *)(lVar15 + 0xbf8) = puVar9[0x1d], uVar4 < 0x78 ||
                             ((uVar8 & 0xfffffffc) == 0x78)) ||
                            (*(undefined4 *)(lVar15 + 0xbfc) = puVar9[0x1e], uVar4 < 0x7c)) ||
                           ((uVar8 & 0xfffffffc) == 0x7c)))))) goto LAB_0010443c;
                      *(undefined4 *)(lVar15 + 0xc00) = puVar9[0x1f];
                      *(long *)(lVar15 + 0xc20) = lVar15 + 0xbe4;
                      kfree(puVar9);
                      __mutex_init(plVar6 + 0x13,"&wcd939x->wakeup_lock",&wcd939x_probe___key);
                      __mutex_init(plVar6 + 0xd,"&wcd939x->micb_lock",&wcd939x_probe___key_94);
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
                      iVar5 = __of_parse_phandle_with_args(uVar14,"qcom,rx-slave",0,0,0,local_a8);
                      if ((iVar5 == 0) && (local_a8[0] != 0)) {
                        component_match_add_release
                                  (lVar1,&local_b0,wcd939x_release_of,wcd939x_compare_of);
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
                        iVar5 = __of_parse_phandle_with_args(uVar14,"qcom,tx-slave",0,0,0,local_a8);
                        if ((iVar5 == 0) && (local_a8[0] != 0)) {
                          component_match_add_release
                                    (lVar1,&local_b0,wcd939x_release_of,wcd939x_compare_of);
                          iVar5 = wcd939x_reset(lVar1);
                          if (iVar5 == -0x205) {
                            _dev_err(lVar1,"%s: wcd reset failed!\n","wcd939x_probe");
                            uVar3 = 0xfffffdfb;
                          }
                          else {
                            plVar6[0x18c] = (long)wcd939x_wakeup;
                            uVar3 = component_master_add_with_match
                                              (lVar1,&wcd939x_comp_ops,local_b0);
                          }
                          goto LAB_001043c4;
                        }
                        iVar5 = ___ratelimit(wcd939x_add_slave_components__rs_104,
                                             "wcd939x_add_slave_components");
                        if (iVar5 != 0) {
                          pcVar10 = "%s: Tx-slave node not defined\n";
                          goto LAB_00104424;
                        }
                      }
                      else {
                        iVar5 = ___ratelimit(wcd939x_add_slave_components__rs,
                                             "wcd939x_add_slave_components");
                        if (iVar5 != 0) {
                          pcVar10 = "%s: Rx-slave node not defined\n";
LAB_00104424:
                          _dev_err(lVar1,pcVar10,"wcd939x_add_slave_components");
                          uVar3 = 0xffffffed;
                          goto LAB_001043c4;
                        }
                      }
                      uVar3 = 0xffffffed;
                      goto LAB_001043c4;
                    }
                    _dev_err(lVar1,"%s: Failed to read  port mapping from prop %s\n",
                             "wcd939x_parse_port_params","qcom,swr-tx-port-params");
                    kfree(puVar9);
                  }
                }
                pcVar10 = "Failed to read port params\n";
              }
              else {
                pcVar10 = "Failed to read port mapping\n";
              }
              _dev_err(lVar1,pcVar10);
              goto LAB_001043c4;
            }
            pcVar10 = "%s: vdd px supply enable failed!\n";
          }
          else {
            pcVar10 = "%s: wcd static supply enable failed!\n";
          }
LAB_001043b4:
          _dev_err(lVar1,pcVar10,"wcd939x_probe");
          goto LAB_001043c4;
        }
        pcVar10 = "%s: register_notifier api is null!\n";
      }
    }
  }
LAB_001042f8:
  _dev_err(lVar1,pcVar10,"wcd939x_probe");
  uVar3 = 0xffffffea;
LAB_001043c4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// wcd939x_remove @ 00104448 size=60
// signature: undefined wcd939x_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_remove(long param_1)

{
  component_master_del(param_1 + 0x10,&wcd939x_comp_ops);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// wcd939x_parse_port_mapping @ 00104484 size=552
// signature: undefined wcd939x_parse_port_mapping(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

int wcd939x_parse_port_mapping(long param_1,undefined8 param_2,char param_3)

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
    lVar10 = lVar5 + 0x184;
    puVar6 = (undefined1 *)(lVar5 + 0x180);
  }
  else {
    if (param_3 != '\x01') {
      _dev_err(param_1,"%s Invalid path selected %u\n","wcd939x_parse_port_mapping",param_3);
      local_84 = -0x16;
      goto LAB_001045e4;
    }
    lVar10 = lVar5 + 0x684;
    puVar6 = (undefined1 *)(lVar5 + 0x181);
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
                 "wcd939x_parse_port_mapping",param_2);
LAB_0010469c:
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
              _dev_err(param_1,"%s: Invalid port or channel number\n","wcd939x_parse_port_mapping");
              goto LAB_0010469c;
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
LAB_001045e4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return local_84;
}



//------------------------------------------------------------
// wcd939x_reset @ 001046ac size=492
// signature: undefined wcd939x_reset(void)
// callers: [wcd939x_event_notify, wcd939x_probe]
//------------------------------------------------------------

void wcd939x_reset(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  char *pcVar4;
  long lVar5;
  ulong local_38;
  ulong uStack_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  _printk(&DAT_0011dcae,"wcd939x_reset");
  if (param_1 == 0) {
    uVar2 = 0xffffffed;
    goto LAB_001047e0;
  }
  lVar5 = *(long *)(param_1 + 0x98);
  if (lVar5 != 0) {
    if (*(long *)(lVar5 + 0x18) != 0) {
      iVar1 = msm_cdc_pinctrl_get_state();
      if (iVar1 < 1) {
        local_38 = 0x1e;
        uStack_30 = 0x21;
        wcd_usbss_register_update(&local_38,0,2);
        local_38 = local_38 & 0xfffffff1ffffffff | 0x800000000;
        uStack_30 = uStack_30 & 0xfffffff1ffffffff | 0x800000000;
        wcd_usbss_register_update(&local_38,1,2);
        iVar1 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(lVar5 + 0x18));
        if (iVar1 == 0) {
          usleep_range_state(0x50,0x55,2);
          iVar1 = msm_cdc_pinctrl_select_active_state(*(undefined8 *)(lVar5 + 0x18));
          if (iVar1 == 0) {
            usleep_range_state(0x50,0x55,2);
            wcd_usbss_set_ovp_threshold(6);
            puVar3 = &DAT_0011e4b7;
            iVar1 = 0;
            goto LAB_0010486c;
          }
          iVar1 = ___ratelimit(wcd939x_reset__rs_111,"wcd939x_reset");
          if (iVar1 != 0) {
            pcVar4 = "%s: wcd active state request fail!\n";
            goto LAB_00104880;
          }
        }
        else {
          iVar1 = ___ratelimit(wcd939x_reset__rs_109,"wcd939x_reset");
          if (iVar1 != 0) {
            pcVar4 = "%s: wcd sleep state request fail!\n";
LAB_00104880:
            _dev_err(param_1,pcVar4,"wcd939x_reset");
          }
        }
        uVar2 = 0xfffffdfb;
      }
      else {
        puVar3 = &DAT_0011f0ba;
LAB_0010486c:
        _printk(puVar3,"wcd939x_reset",iVar1);
        uVar2 = 0;
      }
      goto LAB_001047e0;
    }
    iVar1 = ___ratelimit(wcd939x_reset__rs,"wcd939x_reset");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: reset gpio device node not specified\n","wcd939x_reset");
      uVar2 = 0xffffffea;
      goto LAB_001047e0;
    }
  }
  uVar2 = 0xffffffea;
LAB_001047e0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_release_of @ 0010489c size=4
// signature: undefined wcd939x_release_of(void)
// callers: []
//------------------------------------------------------------

void wcd939x_release_of(void)

{
  return;
}



//------------------------------------------------------------
// wcd939x_compare_of @ 001048a4 size=16
// signature: undefined wcd939x_compare_of(void)
// callers: []
//------------------------------------------------------------

bool wcd939x_compare_of(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x2e8) == param_2;
}



//------------------------------------------------------------
// wcd_usbss_set_ovp_threshold @ 001048b4 size=160
// signature: undefined wcd_usbss_set_ovp_threshold(void)
// callers: [wcd939x_reset]
//------------------------------------------------------------

void wcd_usbss_set_ovp_threshold(int param_1)

{
  long lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0x1e;
  uStack_30 = 0x21;
  wcd_usbss_register_update(&local_38,0,2);
  local_38 = CONCAT44(local_38._4_4_ & 0xfffffff1 | param_1 << 1,(undefined4)local_38);
  uStack_30 = CONCAT44(uStack_30._4_4_ & 0xfffffff1 | param_1 << 1,(undefined4)uStack_30);
  wcd_usbss_register_update(&local_38,1,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd939x_bind @ 00104958 size=1180
// signature: undefined wcd939x_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wcd939x_bind(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 *puVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  char *pcVar8;
  int local_54;
  byte local_50 [4];
  char local_4c [4];
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x90);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_4c[0] = '\0';
  local_50[0] = 0;
  local_54 = 0;
  usleep_range_state(5000,0x1392,2);
  iVar5 = component_bind_all(param_1,puVar3);
  if (iVar5 != 0) {
    iVar6 = ___ratelimit(wcd939x_bind__rs,"wcd939x_bind");
    if (iVar6 != 0) {
      _dev_err(param_1,"%s: Slave bind failed, ret = %d\n","wcd939x_bind",iVar5);
    }
    goto LAB_00104a5c;
  }
  lVar7 = get_matching_swr_slave_device(*(undefined8 *)(lVar2 + 8));
  puVar3[5] = lVar7;
  if (lVar7 == 0) {
    iVar5 = ___ratelimit(wcd939x_bind__rs_115,"wcd939x_bind");
    if (iVar5 != 0) {
      pcVar8 = "%s: Could not find RX swr slave device\n";
LAB_00104b00:
      _dev_err(param_1,pcVar8,"wcd939x_bind");
    }
LAB_00104a4c:
    iVar5 = -0x13;
  }
  else {
    lVar7 = get_matching_swr_slave_device(*(undefined8 *)(lVar2 + 0x10));
    puVar3[6] = lVar7;
    if (lVar7 == 0) {
      iVar5 = ___ratelimit(wcd939x_bind__rs_117,"wcd939x_bind");
      if (iVar5 != 0) {
        pcVar8 = "%s: Could not find TX swr slave device\n";
        goto LAB_00104b00;
      }
      goto LAB_00104a4c;
    }
    swr_init_port_params(lVar7,4,puVar3 + 0x181);
    swr_read(puVar3[6],*(undefined1 *)(puVar3[6] + 0x40),0x3402,local_4c,1);
    swr_read(puVar3[6],*(undefined1 *)(puVar3[6] + 0x40),0x30ef,local_50,1);
    if (local_4c[0] == '\0') {
      bVar4 = (local_50[0] & 3) != 0;
      wcd939x_version = (uint)bVar4;
      *(uint *)(puVar3 + 0x18d) = (uint)bVar4;
LAB_00104b2c:
      if (wcd939x_version < 3) {
        pcVar8 = (&PTR_s_WCD939X_1_0_00119a10)[(int)wcd939x_version];
      }
      else {
        pcVar8 = (char *)0x0;
      }
    }
    else {
      if (local_4c[0] != '\x01') {
        wcd939x_version = *(uint *)(puVar3 + 0x18d);
        goto LAB_00104b2c;
      }
      pcVar8 = "WCD939X_2_0";
      *(undefined4 *)(puVar3 + 0x18d) = 2;
      wcd939x_version = 2;
    }
    _dev_info(param_1,"%s: wcd9395 version: %s\n","wcd939x_bind",pcVar8);
    wcd939x_regmap_config._40_8_ = wcd939x_readable_register;
    lVar7 = __devm_regmap_init_swr(puVar3[6],wcd939x_regmap_config,0,0);
    puVar3[4] = lVar7;
    if (lVar7 == 0) {
      iVar5 = ___ratelimit(wcd939x_bind__rs_120,"wcd939x_bind");
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        _dev_err(param_1,"%s: Regmap init failed\n","wcd939x_bind");
        iVar5 = 0;
      }
    }
    else {
      regmap_read(lVar7,0x34c1,&local_54);
      if ((wcd939x_version == 2) && (local_54 < 3)) {
        wcd_usbss_update_default_trim();
      }
      wcd939x_update_regmap_cache(puVar3);
      if (0 < _DAT_0011adb0) {
        iVar5 = 0;
        do {
          regmap_write(puVar3[4],iVar5 + 0x3474,0);
          iVar5 = iVar5 + 1;
        } while (iVar5 < _DAT_0011adb0);
      }
      puVar1 = puVar3 + 0x29;
      _DAT_0011ae00 = puVar3;
      puVar3[0x29] = &wcd939x_regmap_irq_chip;
      puVar3[0x2a] = "WCD939X";
      puVar3[0x2d] = param_1;
      puVar3[0x2b] = puVar3[4];
      iVar5 = wcd_irq_init(puVar1,puVar3 + 0x28);
      if (iVar5 == 0) {
        *(undefined8 *)(puVar3[6] + 1000) = puVar3[0x28];
        iVar5 = wcd939x_set_micbias_data(puVar3,lVar2);
        if (iVar5 < 0) {
          iVar6 = ___ratelimit(wcd939x_bind__rs_125,"wcd939x_bind");
          if (iVar6 != 0) {
            pcVar8 = "%s: bad micbias pdata\n";
LAB_00104ddc:
            _dev_err(param_1,pcVar8,"wcd939x_bind");
          }
        }
        else {
          wcd_request_irq(puVar1,0xc,"HPHR PDM WD INT",wcd939x_wd_handle_irq,0);
          wcd_request_irq(puVar1,0xb,"HPHL PDM WD INT",wcd939x_wd_handle_irq,0);
          wcd_request_irq(puVar1,0xd,"EAR PDM WD INT",wcd939x_wd_handle_irq,0);
          wcd_disable_irq(puVar1,0xc);
          wcd_disable_irq(puVar1,0xb);
          wcd_disable_irq(puVar1,0xd);
          iVar5 = snd_soc_register_component(param_1,&soc_codec_dev_wcd939x,&wcd939x_dai,1);
          if (iVar5 == 0) {
            *(undefined1 *)(puVar3 + 0x192) = 1;
            goto LAB_00104a5c;
          }
          iVar6 = ___ratelimit(wcd939x_bind__rs_130,"wcd939x_bind");
          if (iVar6 != 0) {
            pcVar8 = "%s: Codec registration failed\n";
            goto LAB_00104ddc;
          }
        }
        wcd_irq_exit(puVar1,puVar3[0x28]);
      }
      else {
        iVar6 = ___ratelimit(wcd939x_bind__rs_123,"wcd939x_bind");
        if (iVar6 != 0) {
          _dev_err(*puVar3,"%s: IRQ init failed: %d\n","wcd939x_bind",iVar5);
        }
      }
    }
  }
  component_unbind_all(param_1,puVar3);
LAB_00104a5c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// wcd939x_unbind @ 00104df8 size=132
// signature: undefined wcd939x_unbind(void)
// callers: []
//------------------------------------------------------------

void wcd939x_unbind(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  lVar1 = lVar2 + 0x148;
  wcd_free_irq(lVar1,0xc,0);
  wcd_free_irq(lVar1,0xb,0);
  wcd_free_irq(lVar1,0xd,0);
  wcd_irq_exit(lVar1,*(undefined8 *)(lVar2 + 0x140));
  snd_soc_unregister_component(param_1);
  component_unbind_all(param_1,lVar2);
  return;
}



//------------------------------------------------------------
// wcd939x_readable_register @ 00104e80 size=84
// signature: undefined wcd939x_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd939x_readable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if ((param_2 - 0x30f6 < 3) && (wcd939x_version == 0)) {
    return 0;
  }
  if (0x5a6 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104ed4);
    (*pcVar2)();
  }
  return (&wcd939x_reg_access)[uVar1] & 1;
}



//------------------------------------------------------------
// wcd939x_update_regmap_cache @ 00104ed4 size=152
// signature: undefined wcd939x_update_regmap_cache(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

void wcd939x_update_regmap_cache(long param_1)

{
  if (*(int *)(param_1 + 0xc68) != 0) {
    regmap_write(*(undefined8 *)(param_1 + 0x20),0x3029,0xa5);
    regmap_write(*(undefined8 *)(param_1 + 0x20),0x30f6,0);
    regmap_write(*(undefined8 *)(param_1 + 0x20),0x30f7,0);
    regmap_write(*(undefined8 *)(param_1 + 0x20),0x30f8,0x44);
    regmap_write(*(undefined8 *)(param_1 + 0x20),0x3136,0x80);
    if (*(int *)(param_1 + 0xc68) == 2) {
      regmap_write(*(undefined8 *)(param_1 + 0x20),0x346d,0x3e);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd939x_set_micbias_data @ 00104f6c size=632
// signature: undefined wcd939x_set_micbias_data(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

undefined8 wcd939x_set_micbias_data(undefined8 *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_2 == 0) {
    _dev_err(*param_1,"%s: NULL pdata\n","wcd939x_set_micbias_data");
    uVar2 = 0xffffffed;
  }
  else {
    if (*(int *)(param_2 + 0x20) - 0xb23U < 0xfffff8c5) {
      iVar1 = ___ratelimit(wcd939x_get_micb_vout_ctl_val__rs,"wcd939x_get_micb_vout_ctl_val");
      if (iVar1 == 0) {
        uVar3 = 0xffffffea;
      }
      else {
        _printk(&DAT_0011f918,"wcd939x_get_micb_vout_ctl_val");
        uVar3 = 0xffffffea;
      }
    }
    else {
      uVar3 = (*(int *)(param_2 + 0x20) - 1000U >> 1 & 0x7fff) / 0x19;
    }
    if (*(int *)(param_2 + 0x24) - 0xb23U < 0xfffff8c5) {
      iVar1 = ___ratelimit(wcd939x_get_micb_vout_ctl_val__rs,"wcd939x_get_micb_vout_ctl_val");
      if (iVar1 == 0) {
        uVar5 = 0xffffffea;
      }
      else {
        _printk(&DAT_0011f918,"wcd939x_get_micb_vout_ctl_val");
        uVar5 = 0xffffffea;
      }
    }
    else {
      uVar5 = (*(int *)(param_2 + 0x24) - 1000U >> 1 & 0x7fff) / 0x19;
    }
    if (*(int *)(param_2 + 0x28) - 0xb23U < 0xfffff8c5) {
      iVar1 = ___ratelimit(wcd939x_get_micb_vout_ctl_val__rs,"wcd939x_get_micb_vout_ctl_val");
      if (iVar1 == 0) {
        uVar6 = 0xffffffea;
      }
      else {
        _printk(&DAT_0011f918,"wcd939x_get_micb_vout_ctl_val");
        uVar6 = 0xffffffea;
      }
    }
    else {
      uVar6 = (*(int *)(param_2 + 0x28) - 1000U >> 1 & 0x7fff) / 0x19;
    }
    if (*(int *)(param_2 + 0x2c) - 0xb23U < 0xfffff8c5) {
      iVar1 = ___ratelimit(wcd939x_get_micb_vout_ctl_val__rs,"wcd939x_get_micb_vout_ctl_val");
      if (iVar1 != 0) {
        _printk(&DAT_0011f918,"wcd939x_get_micb_vout_ctl_val");
      }
      uVar4 = 0xffffffea;
    }
    else {
      uVar4 = (*(int *)(param_2 + 0x2c) - 1000U >> 1 & 0x7fff) / 0x19;
    }
    uVar2 = 0xffffffea;
    if ((((-1 < (int)uVar3) && (uVar2 = 0xffffffea, -1 < (int)uVar5)) && (-1 < (int)uVar6)) &&
       (-1 < (int)uVar4)) {
      regmap_update_bits_base(param_1[4],0x3022,0x3f,uVar3,0,0,0);
      regmap_update_bits_base(param_1[4],0x3023,0x3f,uVar5,0,0,0);
      regmap_update_bits_base(param_1[4],0x3025,0x3f,uVar6,0,0,0);
      regmap_update_bits_base(param_1[4],0x3026,0x3f,uVar4,0,0,0);
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd939x_wd_handle_irq @ 001051e8 size=92
// signature: undefined wcd939x_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wcd939x_wd_handle_irq__rs,"wcd939x_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_0011e4e5,"wcd939x_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wcd939x_handle_post_irq @ 00105248 size=184
// signature: undefined wcd939x_handle_post_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_handle_post_irq(long param_1)

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
// wcd939x_soc_codec_probe @ 00105304 size=944
// signature: undefined wcd939x_soc_codec_probe(void)
// callers: []
//------------------------------------------------------------

int wcd939x_soc_codec_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  int iVar8;
  code *pcVar9;
  long *plVar10;
  
  _dev_info(*(undefined8 *)(param_1 + 0x18),"%s()\n","wcd939x_soc_codec_probe");
  plVar10 = *(long **)(*(long *)(param_1 + 0x18) + 0x98);
  if (plVar10 == (long *)0x0) {
    return -0x16;
  }
  plVar10[2] = param_1;
  snd_soc_component_init_regmap(param_1,plVar10[4]);
  devm_regmap_qti_debugfs_register(plVar10[6] + 0x48,plVar10[4]);
  *(undefined4 *)(plVar10 + 1) = 5;
  lVar5 = of_find_property(*(undefined8 *)(*plVar10 + 0x2e8),"qcom,hph-2p15v-mode",0);
  *(bool *)((long)plVar10 + 0x139) = lVar5 != 0;
  lVar5 = devm_kmalloc(*(undefined8 *)(param_1 + 0x18),0x78,0xdc0);
  plVar10[0xb] = lVar5;
  if (lVar5 == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"Failed to allocate fw_data\n");
    return -0xc;
  }
  puVar1 = (ulong *)(lVar5 + 0x20);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 4;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  iVar4 = wcd_cal_create_hwdep(plVar10[0xb],1000,param_1);
  if (iVar4 < 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x18);
    pcVar7 = "%s hwdep failed %d\n";
    iVar8 = iVar4;
    goto LAB_00105678;
  }
  iVar4 = wcd939x_mbhc_init(plVar10 + 0x20,param_1,plVar10[0xb]);
  if (iVar4 != 0) {
    _printk(&DAT_0011e9b8,"wcd939x_soc_codec_probe");
    plVar10[0xb] = 0;
    return iVar4;
  }
  lVar5 = param_1 + 0xd0;
  snd_soc_dapm_ignore_suspend(lVar5,"WCD939X_AIF Playback");
  snd_soc_dapm_ignore_suspend(lVar5,"WCD939X_AIF Capture");
  snd_soc_dapm_ignore_suspend(lVar5,"AMIC1");
  snd_soc_dapm_ignore_suspend(lVar5,"AMIC2");
  snd_soc_dapm_ignore_suspend(lVar5,"AMIC3");
  snd_soc_dapm_ignore_suspend(lVar5,"AMIC4");
  snd_soc_dapm_ignore_suspend(lVar5,"AMIC5");
  snd_soc_dapm_ignore_suspend(lVar5,"VA AMIC1");
  snd_soc_dapm_ignore_suspend(lVar5,"VA AMIC2");
  snd_soc_dapm_ignore_suspend(lVar5,"VA AMIC3");
  snd_soc_dapm_ignore_suspend(lVar5,"VA AMIC4");
  snd_soc_dapm_ignore_suspend(lVar5,"VA AMIC5");
  snd_soc_dapm_ignore_suspend(lVar5,"WCD_TX_OUTPUT");
  snd_soc_dapm_ignore_suspend(lVar5,"IN1_HPHL");
  snd_soc_dapm_ignore_suspend(lVar5,"IN2_HPHR");
  snd_soc_dapm_ignore_suspend(lVar5,"IN3_EAR");
  snd_soc_dapm_ignore_suspend(lVar5,&DAT_0011e436);
  snd_soc_dapm_ignore_suspend(lVar5,&DAT_0011e886);
  snd_soc_dapm_ignore_suspend(lVar5,&DAT_0011de14);
  snd_soc_dapm_ignore_suspend(lVar5,"WCD_TX_DUMMY");
  snd_soc_dapm_ignore_suspend(lVar5,"WCD_RX_DUMMY");
  snd_soc_dapm_sync(lVar5);
  wcd_cls_h_init(plVar10 + 0x1c);
  wcd939x_init_reg(param_1);
  iVar8 = (int)plVar10[1];
  if (iVar8 == 0) {
    iVar4 = snd_soc_add_component_controls(param_1,wcd9390_snd_controls,6);
    if (-1 < iVar4) {
      iVar8 = (int)plVar10[1];
      goto joined_r0x0010558c;
    }
  }
  else {
    iVar4 = 0;
joined_r0x0010558c:
    if ((iVar8 != 5) ||
       (iVar4 = snd_soc_add_component_controls(param_1,wcd9395_snd_controls,5), -1 < iVar4)) {
      pcVar9 = (code *)plVar10[0x18b];
      plVar10[0x186] = (long)wcd939x_event_notify;
      if (pcVar9 == (code *)0x0) {
        return iVar4;
      }
      if (*(int *)(pcVar9 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1055e4);
        (*pcVar9)();
      }
      iVar4 = (*pcVar9)(plVar10[0x189],plVar10 + 0x186,1);
      if (iVar4 == 0) {
        return 0;
      }
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Failed to register notifier %d\n",
               "wcd939x_soc_codec_probe",iVar4);
      return iVar4;
    }
  }
  uVar6 = *(undefined8 *)(param_1 + 0x18);
  pcVar7 = "%s: Failed to add snd ctrls for variant: %d\n";
  iVar8 = (int)plVar10[1];
LAB_00105678:
  _dev_err(uVar6,pcVar7,"wcd939x_soc_codec_probe",iVar8);
  plVar10[0xb] = 0;
  return iVar4;
}



//------------------------------------------------------------
// wcd939x_soc_codec_remove @ 001056c4 size=108
// signature: undefined wcd939x_soc_codec_remove(void)
// callers: []
//------------------------------------------------------------

void wcd939x_soc_codec_remove(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar2 == 0) {
    _dev_err(*(long *)(param_1 + 0x18),"%s: wcd939x is already NULL\n","wcd939x_soc_codec_remove");
  }
  else {
    pcVar1 = *(code **)(lVar2 + 0xc58);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105708);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(lVar2 + 0xc48),lVar2 + 0xc30,0);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd939x_soc_codec_suspend @ 00105734 size=28
// signature: undefined wcd939x_soc_codec_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_soc_codec_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x138) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_soc_codec_resume @ 00105754 size=24
// signature: undefined wcd939x_soc_codec_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_soc_codec_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x138) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_get_compander @ 00105770 size=44
// signature: undefined wcd939x_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_get_compander(long param_1,long param_2)

{
  long lVar1;
  
  lVar1 = 0x134;
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) != 0) {
    lVar1 = 0x135;
  }
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + lVar1);
  return 0;
}



//------------------------------------------------------------
// wcd939x_set_compander @ 001057a0 size=56
// signature: undefined wcd939x_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_set_compander(long param_1,long param_2)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = *(int *)(param_2 + 0x48) != 0;
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  if (*(int *)(*(long *)(param_1 + 0x78) + 0x18) == 0) {
    *(bool *)(lVar2 + 0x134) = bVar1;
    return 0;
  }
  *(bool *)(lVar2 + 0x135) = bVar1;
  return 0;
}



//------------------------------------------------------------
// wcd939x_ldoh_get @ 001057dc size=28
// signature: undefined wcd939x_ldoh_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_ldoh_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x136);
  return 0;
}



//------------------------------------------------------------
// wcd939x_ldoh_put @ 001057fc size=36
// signature: undefined wcd939x_ldoh_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_ldoh_put(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x136) =
       *(long *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wcd939x_bcs_get @ 00105824 size=28
// signature: undefined wcd939x_bcs_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_bcs_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x137);
  return 0;
}



//------------------------------------------------------------
// wcd939x_bcs_put @ 00105844 size=36
// signature: undefined wcd939x_bcs_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_bcs_put(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x137) =
       *(long *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wcd939x_hph_compander_get @ 0010586c size=52
// signature: undefined wcd939x_hph_compander_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_hph_compander_get(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  if (1 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1058a0);
    (*pcVar2)();
  }
  *(long *)(param_2 + 0x48) =
       (long)*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) +
                      (ulong)uVar1 * 4 + 0x108);
  return 0;
}



//------------------------------------------------------------
// wcd939x_hph_compander_put @ 001058a4 size=112
// signature: undefined wcd939x_hph_compander_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_hph_compander_put(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x80) + 0x18);
  if (*(uint *)(param_2 + 0x48) < 2) {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
    if (1 < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105914);
      (*pcVar2)();
    }
    uVar4 = 0;
    *(uint *)(*(long *)(lVar3 + 0x98) + (ulong)uVar1 * 4 + 0x108) = *(uint *)(param_2 + 0x48);
  }
  else {
    _dev_err(lVar3,"%s: Invalid comp value = %d\n","wcd939x_hph_compander_put");
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd939x_hph_xtalk_get @ 00105918 size=52
// signature: undefined wcd939x_hph_xtalk_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_hph_xtalk_get(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  if (1 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10594c);
    (*pcVar2)();
  }
  *(long *)(param_2 + 0x48) =
       (long)*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) +
                      (ulong)uVar1 * 4 + 0x110);
  return 0;
}



//------------------------------------------------------------
// wcd939x_hph_xtalk_put @ 00105950 size=112
// signature: undefined wcd939x_hph_xtalk_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_hph_xtalk_put(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x80) + 0x18);
  if (*(uint *)(param_2 + 0x48) < 2) {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
    if (1 < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1059c0);
      (*pcVar2)();
    }
    uVar4 = 0;
    *(uint *)(*(long *)(lVar3 + 0x98) + (ulong)uVar1 * 4 + 0x110) = *(uint *)(param_2 + 0x48);
  }
  else {
    _dev_err(lVar3,"%s: Invalid xtalk value = %d\n","wcd939x_hph_xtalk_put");
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// wcd939x_hph_pcm_enable_get @ 001059c4 size=28
// signature: undefined wcd939x_hph_pcm_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_hph_pcm_enable_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x118);
  return 0;
}



//------------------------------------------------------------
// wcd939x_hph_pcm_enable_put @ 001059e4 size=28
// signature: undefined wcd939x_hph_pcm_enable_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_hph_pcm_enable_put(long param_1,long param_2)

{
  *(char *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x118) =
       (char)*(undefined8 *)(param_2 + 0x48);
  return 0;
}



//------------------------------------------------------------
// wcd939x_tx_master_ch_get @ 00105a04 size=176
// signature: undefined wcd939x_tx_master_ch_get(void)
// callers: []
//------------------------------------------------------------

void wcd939x_tx_master_ch_get(long param_1,long param_2)

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
    wcd939x_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if (local_2c < 0xd) {
      uVar2 = 0;
      uVar1 = *(byte *)(lVar3 + (ulong)local_2c + 0xc91) - 0x2d;
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
// wcd939x_tx_master_ch_put @ 00105ab8 size=180
// signature: undefined wcd939x_tx_master_ch_put(void)
// callers: []
//------------------------------------------------------------

void wcd939x_tx_master_ch_put(long param_1,long param_2)

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
    wcd939x_tx_get_slave_ch_type_idx(param_1 + 0x20,&local_2c);
    if ((local_2c < 0xd) && (*(uint *)(param_2 + 0x48) < 0xf)) {
      uVar1 = 0;
      *(char *)(lVar2 + (ulong)local_2c + 0xc91) =
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
// wcd939x_tx_get_slave_ch_type_idx @ 00105b6c size=528
// signature: undefined wcd939x_tx_get_slave_ch_type_idx(void)
// callers: [wcd939x_tx_master_ch_get, wcd939x_tx_master_ch_put]
//------------------------------------------------------------

void wcd939x_tx_get_slave_ch_type_idx(undefined8 param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = strnstr(param_1,&DAT_0011ecf3,5);
  if (lVar2 == 0) {
    lVar2 = strnstr(param_1,&DAT_0011f67b,5);
    if (lVar2 == 0) {
      lVar2 = strnstr(param_1,&DAT_0011f540,5);
      if (lVar2 == 0) {
        lVar2 = strnstr(param_1,&DAT_0011f371,5);
        if (lVar2 == 0) {
          lVar2 = strnstr(param_1,"DMIC0",6);
          if (lVar2 == 0) {
            lVar2 = strnstr(param_1,"DMIC1",6);
            if (lVar2 == 0) {
              lVar2 = strnstr(param_1,&DAT_0011dce1,5);
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
                            iVar1 = ___ratelimit(wcd939x_tx_get_slave_ch_type_idx__rs,
                                                 "wcd939x_tx_get_slave_ch_type_idx");
                            if (iVar1 != 0) {
                              _printk(&DAT_0011f270,"wcd939x_tx_get_slave_ch_type_idx",param_1);
                            }
                            uVar3 = 0xffffffea;
                            goto LAB_00105d2c;
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
LAB_00105d2c:
  *param_2 = uVar3;
  return;
}



//------------------------------------------------------------
// wcd939x_codec_enable_adc @ 00105d80 size=976
// signature: undefined wcd939x_codec_enable_adc(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_codec_enable_adc(long param_1,undefined8 param_2,int param_3)

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
    iVar6 = *(int *)(lVar14 + 0x130) + -1;
    if (iVar6 < 1) {
      iVar6 = 0;
    }
    *(int *)(lVar14 + 0x130) = iVar6;
    wcd939x_tx_connect_port(lVar13,*(byte *)(param_1 + 0x4c) + 0x1e,0,0);
    uVar7 = 0;
    if (*(char *)(param_1 + 0x4c) == '\x01') {
      if (((uint)*(undefined8 *)(lVar14 + 0x178) >> 7 & 1) != 0) {
        lVar15 = *(long *)(*(long *)(lVar15 + -0xb8) + 0x98);
        local_5c[0] = 0;
        local_64[0] = 0;
        iVar6 = wcd939x_set_port_params
                          (lVar13,0x1d,local_5c,auStack_60,local_64,&local_6c,local_68,0);
        if (iVar6 == 0) {
          local_68[0] = *(undefined1 *)(lVar15 + 0xc97);
          swr_disconnect_port(*(undefined8 *)(lVar15 + 0x30),local_5c,1,local_64,local_68);
        }
        puVar1 = (ulong *)(lVar14 + 0x178);
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
    goto LAB_001060fc;
  }
  uVar7 = 0;
  if (param_3 != 1) goto LAB_001060fc;
  iVar6 = *(int *)(lVar14 + 0x130) + 1;
  *(int *)(lVar14 + 0x130) = iVar6;
  if (((*(ulong *)(lVar14 + 0x178) & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar14 + 0x178) >> 9 & 1) == 0)) {
    uVar10 = 0;
    if (((uint)*(undefined8 *)(lVar14 + 0x178) >> 1 & 1) != 0) goto LAB_00105f10;
LAB_00105f08:
    if (((uint)*(undefined8 *)(lVar14 + 0x178) >> 10 & 1) != 0) goto LAB_00105f10;
  }
  else {
    if (6 < *(uint *)(lVar14 + 0x120)) goto LAB_00106134;
    uVar10 = (uint)*(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x120));
    if (((uint)*(undefined8 *)(lVar14 + 0x178) >> 1 & 1) == 0) goto LAB_00105f08;
LAB_00105f10:
    if (6 < *(uint *)(lVar14 + 0x124)) goto LAB_00106134;
    uVar10 = uVar10 | *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x124));
  }
  if ((((uint)*(undefined8 *)(lVar14 + 0x178) >> 2 & 1) != 0) ||
     (((uint)*(undefined8 *)(lVar14 + 0x178) >> 0xb & 1) != 0)) {
    if (6 < *(uint *)(lVar14 + 0x128)) goto LAB_00106134;
    uVar10 = uVar10 | *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 0x128));
  }
  if ((((uint)*(undefined8 *)(lVar14 + 0x178) >> 3 & 1) != 0) ||
     (((uint)*(undefined8 *)(lVar14 + 0x178) >> 0xc & 1) != 0)) {
    if (6 < *(uint *)(lVar14 + 300)) {
LAB_00106134:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x106138);
      (*pcVar5)();
    }
    uVar10 = uVar10 | *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar14 + 300));
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
      if (iVar12 != 1200000) goto LAB_00106050;
      uVar8 = 0x50;
      uVar7 = 5;
    }
LAB_001060a8:
    uVar9 = uVar7;
    if (bVar3 && bVar4) {
      uVar9 = uVar8;
    }
    uVar11 = 0xf;
    if (bVar3 && bVar4) {
      uVar11 = 0xf0;
      uVar8 = uVar7;
    }
LAB_001060c4:
    snd_soc_component_update_bits(lVar13,0x3405,uVar11,uVar9);
    uVar7 = swr_slvdev_datapath_control
                      (*(long *)(lVar14 + 0x30),*(undefined1 *)(*(long *)(lVar14 + 0x30) + 0x40),1);
  }
  else {
    if (iVar12 == 2400000) {
      uVar8 = 0x30;
      uVar7 = 3;
      goto LAB_001060a8;
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
      goto LAB_001060c4;
    }
LAB_00106050:
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
LAB_001060fc:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// wcd939x_codec_enable_dmic @ 00106160 size=552
// signature: undefined wcd939x_codec_enable_dmic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_enable_dmic(long param_1,undefined8 param_2,int param_3)

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
    iVar2 = ___ratelimit(wcd939x_codec_enable_dmic__rs,"wcd939x_codec_enable_dmic");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    _dev_err(*(undefined8 *)(lVar8 + -0xb8),"%s: Invalid DMIC Selection\n",
             "wcd939x_codec_enable_dmic");
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
    goto switchD_001061c0_caseD_0;
  case 2:
    iVar2 = 0x345d;
switchD_001061c0_caseD_3:
    uVar5 = 0xf0;
    lVar7 = 4;
    lVar9 = 1;
    uVar4 = 0x345d;
    if (param_3 == 8) {
LAB_001062f0:
      wcd939x_tx_connect_port(lVar3,bVar1 + 0x22,0,0);
      snd_soc_component_update_bits(lVar3,0x345a,1 << lVar9,1 << lVar9);
      if (iVar2 != 0) {
        snd_soc_component_update_bits(lVar3,iVar2,0x80,0);
      }
      snd_soc_component_update_bits(lVar3,uVar4,8,0);
    }
    else {
LAB_001061f8:
      if (param_3 == 1) {
        lVar8 = *(long *)(*(long *)(lVar8 + -0xb8) + 0x98);
        snd_soc_component_update_bits(lVar3,0x345a,1 << lVar9,0);
        usleep_range_state(0xfa,0x104,2);
        if (iVar2 != 0) {
          snd_soc_component_update_bits(lVar3,iVar2,0x80,0x80);
        }
        snd_soc_component_update_bits(lVar3,uVar6,uVar5,3 << lVar7);
        snd_soc_component_update_bits(lVar3,uVar4,8,8);
        snd_soc_component_update_bits(lVar3,0x345b,2,2);
        snd_soc_component_update_bits(lVar3,0x345b,4,4);
        lVar8 = *(long *)(lVar8 + 0x30);
        uVar4 = swr_slvdev_datapath_control(lVar8,*(undefined1 *)(lVar8 + 0x40),1);
        return uVar4;
      }
    }
    return 0;
  case 3:
    goto switchD_001061c0_caseD_3;
  case 4:
  case 5:
    lVar7 = 0;
    lVar9 = 2;
    uVar4 = 0x345e;
    goto LAB_001061ec;
  case 6:
  case 7:
    uVar5 = 0xf0;
    lVar7 = 4;
    lVar9 = 3;
    uVar4 = 0x345f;
LAB_001061ec:
    uVar6 = 0x3463;
switchD_001061c0_caseD_0:
    iVar2 = 0;
    if (param_3 == 8) goto LAB_001062f0;
    goto LAB_001061f8;
  }
}



//------------------------------------------------------------
// wcd939x_enable_req @ 0010638c size=940
// signature: undefined wcd939x_enable_req(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_enable_req(long param_1,undefined8 param_2,int param_3)

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
                (lVar7,*(undefined4 *)(&DAT_0012019c + (long)(char)bVar1 * 4),
                 *(undefined4 *)(&DAT_0012016c + (long)(char)bVar1 * 4),
                 *(undefined4 *)(&DAT_0012016c + (long)(char)bVar1 * 4));
      uVar9 = 0;
    }
    else {
      iVar3 = ___ratelimit(wcd939x_tx_channel_config__rs,"wcd939x_tx_channel_config");
      if (iVar3 != 0) {
        _printk(&DAT_0011f317,"wcd939x_tx_channel_config",bVar1);
      }
      uVar9 = 0xffffffea;
    }
    if (3 < (ulong)*(byte *)(param_1 + 0x4c)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106738);
      (*pcVar2)();
    }
    uVar6 = *(uint *)(lVar10 + (ulong)*(byte *)(param_1 + 0x4c) * 4 + 0x120);
    if (uVar6 < 7) {
      uVar6 = *(uint *)(&DAT_00119a28 + (long)(int)uVar6 * 4);
    }
    else {
      iVar3 = ___ratelimit(wcd939x_get_adc_mode__rs,"wcd939x_get_adc_mode");
      if (iVar3 != 0) {
        _printk(&DAT_0011ff96,"wcd939x_get_adc_mode",uVar6);
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
      goto switchD_0010651c_default;
    }
    snd_soc_component_update_bits(lVar7,0x3409,uVar4,uVar5);
    uVar8 = (ulong)*(byte *)(param_1 + 0x4c);
switchD_0010651c_default:
    if ((uint)uVar8 < 4) {
      uVar8 = -(uVar8 >> 7) & 0xfffffffffffffc00 | uVar8 << 2;
      snd_soc_component_update_bits
                (lVar7,*(undefined4 *)(&DAT_0012019c + uVar8),*(undefined4 *)(&DAT_0012016c + uVar8)
                 ,0);
      return uVar9;
    }
    iVar3 = ___ratelimit(wcd939x_tx_channel_config__rs,"wcd939x_tx_channel_config");
    if (iVar3 != 0) {
      _printk(&DAT_0011f317,"wcd939x_tx_channel_config",uVar8);
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
    goto switchD_00106478_default;
  }
  snd_soc_component_update_bits(lVar7,0x3409,uVar9,0);
switchD_00106478_default:
  if (*(int *)(lVar10 + 0x130) == 0) {
    snd_soc_component_update_bits(lVar7,0x3408,0x10,0);
    snd_soc_component_update_bits(lVar7,0x3408,8,0);
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_tx_swr_ctrl @ 0010673c size=1696
// signature: undefined wcd939x_tx_swr_ctrl(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_tx_swr_ctrl(long param_1,undefined8 param_2,int param_3)

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
  lVar11 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011e9b4,4);
  if (lVar11 == 0) {
    iVar7 = 0;
  }
  else {
    uVar14 = (ulong)*(byte *)(param_1 + 0x4c) - 0x1e;
    if (3 < uVar14) goto LAB_00106d1c;
    uVar8 = *(int *)(lVar15 + uVar14 * 4 + 0x120) - 4;
    if (uVar8 < 3) {
      iVar7 = *(int *)(&DAT_00119a44 + (long)(int)uVar8 * 4);
    }
    else {
      iVar7 = 9600000;
    }
  }
  lVar11 = lVar16 + -0xd0;
  if (param_3 != 8) {
    if (param_3 == 1) {
      if (((*(char *)(param_1 + 0x4c) == '\x1f') &&
          (uVar8 = snd_soc_component_read(lVar11,0x3127), (uVar8 & 0x38) == 0x10)) &&
         (*(char *)(lVar15 + 0x137) == '\0')) {
        lVar16 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
        local_5c[0] = 0;
        local_60[0] = 0;
        local_64[0] = 0;
        iVar9 = wcd939x_set_port_params(lVar11,0x1d,local_5c,local_60,local_64,&local_6c,local_68,0)
        ;
        if (iVar9 == 0) {
          local_6c = 4800000;
          local_68[0] = *(undefined1 *)(lVar16 + 0xc97);
          swr_connect_port(*(undefined8 *)(lVar16 + 0x30),local_5c,1,local_64,&local_6c,local_60,
                           local_68);
        }
        puVar1 = (ulong *)(lVar15 + 0x178);
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
      lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011e9b4,4);
      uVar14 = (ulong)*(byte *)(param_1 + 0x4c);
      if (lVar16 == 0) {
        iVar7 = 2400000;
      }
      else {
        puVar1 = (ulong *)(lVar15 + 0x178 + (uVar14 - 0x1e >> 6 & 0x3ffffff) * 8);
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
      wcd939x_tx_connect_port(lVar11,uVar14,iVar7,1);
      uVar10 = 0;
    }
    else {
      uVar10 = 0;
    }
    goto LAB_00106ce4;
  }
  lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011e9b4,4);
  if (lVar16 != 0) {
    lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011ecf3,5);
    if (lVar16 == 0) {
      lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011f67b,5);
      if (lVar16 == 0) {
        lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011f540,5);
        if (lVar16 == 0) {
          lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011f371,5);
          if (lVar16 != 0) {
            puVar1 = (ulong *)(lVar15 + 0x178);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = *puVar1 & 0xfffffffffffffff7;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            puVar1 = (ulong *)(lVar15 + 0x178);
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
          puVar1 = (ulong *)(lVar15 + 0x178);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 & 0xfffffffffffffffb;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          puVar1 = (ulong *)(lVar15 + 0x178);
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
        puVar1 = (ulong *)(lVar15 + 0x178);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xfffffffffffffffd;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        puVar1 = (ulong *)(lVar15 + 0x178);
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
      puVar1 = (ulong *)(lVar15 + 0x178);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      puVar1 = (ulong *)(lVar15 + 0x178);
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
  lVar16 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011e9b4,4);
  if (lVar16 != 0) {
    if (((*(ulong *)(lVar15 + 0x178) & 1) == 0) &&
       (((uint)*(undefined8 *)(lVar15 + 0x178) >> 9 & 1) == 0)) {
      uVar8 = 0;
      if (((uint)*(undefined8 *)(lVar15 + 0x178) >> 1 & 1) != 0) goto LAB_00106a9c;
LAB_00106a94:
      if (((uint)*(undefined8 *)(lVar15 + 0x178) >> 10 & 1) != 0) goto LAB_00106a9c;
    }
    else {
      if (6 < *(uint *)(lVar15 + 0x120)) goto LAB_00106d1c;
      uVar8 = (uint)*(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x120));
      if (((uint)*(undefined8 *)(lVar15 + 0x178) >> 1 & 1) == 0) goto LAB_00106a94;
LAB_00106a9c:
      if (6 < *(uint *)(lVar15 + 0x124)) goto LAB_00106d1c;
      uVar8 = *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x124)) | uVar8;
    }
    if ((((uint)*(undefined8 *)(lVar15 + 0x178) >> 2 & 1) != 0) ||
       (((uint)*(undefined8 *)(lVar15 + 0x178) >> 0xb & 1) != 0)) {
      if (6 < *(uint *)(lVar15 + 0x128)) goto LAB_00106d1c;
      uVar8 = *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 0x128)) | uVar8;
    }
    if ((((uint)*(undefined8 *)(lVar15 + 0x178) >> 3 & 1) != 0) ||
       (((uint)*(undefined8 *)(lVar15 + 0x178) >> 0xc & 1) != 0)) {
      if (6 < *(uint *)(lVar15 + 300)) {
LAB_00106d1c:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x106d20);
        (*pcVar6)();
      }
      uVar8 = *(byte *)((long)&tx_mode_bit + (ulong)*(uint *)(lVar15 + 300)) | uVar8;
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
    iVar9 = *(int *)(lVar15 + 0x130) * iVar7;
    if (9599999 < iVar9) {
      iVar9 = 9600000;
    }
    if (*(int *)(lVar15 + 0x130) != 0) {
      iVar7 = iVar9;
    }
    if (iVar7 < 2400000) {
      if (iVar7 == 600000) {
        uVar12 = 0x60;
        uVar10 = 6;
      }
      else {
        if (iVar7 != 1200000) goto LAB_00106bec;
        uVar12 = 0x50;
        uVar10 = 5;
      }
LAB_00106be8:
      if (!bVar4 && !bVar5) {
        uVar10 = uVar12;
      }
    }
    else {
      if (iVar7 == 2400000) {
        uVar12 = 0x30;
        uVar10 = 3;
        goto LAB_00106be8;
      }
      if ((iVar7 == 4800000) && (uVar10 = 0x10, bVar4 || bVar5)) {
        uVar10 = 1;
      }
    }
LAB_00106bec:
    uVar12 = 0xf;
    if (!bVar4 && !bVar5) {
      uVar12 = 0xf0;
    }
    snd_soc_component_update_bits(lVar11,0x3405,uVar12,uVar10);
  }
  uVar10 = swr_slvdev_datapath_control
                     (*(long *)(lVar15 + 0x30),*(undefined1 *)(*(long *)(lVar15 + 0x30) + 0x40),0);
  lVar15 = strnstr(*(undefined8 *)(param_1 + 8),&DAT_0011e9b4,4);
  if (lVar15 == 0) goto LAB_00106ce4;
  uVar12 = 0;
  if (iVar7 < 2400000) {
    if (iVar7 == 600000) {
      uVar13 = 6;
      uVar12 = 0x60;
    }
    else {
      if (iVar7 != 1200000) goto LAB_00106cc8;
      uVar13 = 5;
      uVar12 = 0x50;
    }
LAB_00106cc4:
    if (!bVar4 && !bVar5) {
      uVar12 = uVar13;
    }
  }
  else {
    if (iVar7 == 2400000) {
      uVar13 = 3;
      uVar12 = 0x30;
      goto LAB_00106cc4;
    }
    if ((iVar7 == 4800000) && (uVar12 = 0x10, !bVar4 && !bVar5)) {
      uVar12 = 1;
    }
  }
LAB_00106cc8:
  uVar13 = 0xf0;
  if (!bVar4 && !bVar5) {
    uVar13 = 0xf;
  }
  snd_soc_component_update_bits(lVar11,0x3405,uVar13,uVar12);
LAB_00106ce4:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// wcd939x_codec_enable_micbias @ 00106e60 size=32
// signature: undefined wcd939x_codec_enable_micbias(void)
// callers: []
//------------------------------------------------------------

void wcd939x_codec_enable_micbias(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  __wcd939x_codec_enable_micbias(param_1,param_3);
  return;
}



//------------------------------------------------------------
// wcd939x_codec_force_enable_micbias @ 00106e84 size=128
// signature: undefined wcd939x_codec_force_enable_micbias(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_codec_force_enable_micbias(long param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if ((param_3 == 8) || (param_3 == 1)) {
    uVar2 = *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    wcd939x_wakeup(uVar2,1);
    uVar1 = __wcd939x_codec_enable_micbias(param_1,param_3);
    wcd939x_wakeup(uVar2,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wcd939x_codec_enable_vdd_buck @ 00106f08 size=384
// signature: undefined wcd939x_codec_enable_vdd_buck(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_enable_vdd_buck(long param_1,undefined8 param_2,int param_3)

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
    iVar4 = ___ratelimit(wcd939x_codec_enable_vdd_buck__rs,"wcd939x_codec_enable_vdd_buck");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    uVar6 = *(undefined8 *)(lVar8 + -0xb8);
    pcVar7 = "%s: pdata is NULL\n";
LAB_00107044:
    _dev_err(uVar6,pcVar7,"wcd939x_codec_enable_vdd_buck");
    uVar6 = 0xffffffea;
  }
  else {
    uVar5 = msm_cdc_is_ondemand_supply
                      (*plVar9,plVar9[0x185],*(undefined8 *)(lVar10 + 0x118),
                       *(undefined4 *)(lVar10 + 0x120),"cdc-vdd-buck");
    if ((uVar5 & 1) != 0) {
      if (param_3 == 8) {
        puVar1 = (ulong *)(plVar9 + 0x2f);
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
        if (((uint)plVar9[0x2f] >> 4 & 1) == 0) {
          iVar4 = msm_cdc_enable_ondemand_supply
                            (*plVar9,plVar9[0x185],*(undefined8 *)(lVar10 + 0x118),
                             *(undefined4 *)(lVar10 + 0x120),"cdc-vdd-buck");
          if (iVar4 == -0x16) {
            iVar4 = ___ratelimit(wcd939x_codec_enable_vdd_buck__rs_335,
                                 "wcd939x_codec_enable_vdd_buck");
            if (iVar4 == 0) {
              return 0xffffffea;
            }
            uVar6 = *(undefined8 *)(lVar8 + -0xb8);
            pcVar7 = "%s: vdd buck is not enabled\n";
            goto LAB_00107044;
          }
          puVar1 = (ulong *)(plVar9 + 0x2f);
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
          puVar1 = (ulong *)(plVar9 + 0x2f);
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
// wcd939x_enable_clsh @ 001070b8 size=276
// signature: undefined wcd939x_enable_clsh(void)
// callers: []
//------------------------------------------------------------

void wcd939x_enable_clsh(long param_1,undefined8 param_2,ulong param_3)

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
  if (*(uint *)(lVar3 + 0x11c) < 6 && (1 << (ulong)(*(uint *)(lVar3 + 0x11c) & 0x1f) & 0x36U) != 0)
  {
    local_2c[0] = 0;
    local_30[0] = 0;
    local_34[0] = 0;
    local_38[0] = 0;
    local_3c = 0;
    iVar1 = wcd939x_set_port_params
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
// wcd939x_clsh_dummy @ 001071d0 size=68
// signature: undefined wcd939x_clsh_dummy(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_clsh_dummy(long param_1,undefined8 param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  
  if ((param_3 & 0xc) == 0) {
    return 0;
  }
  lVar1 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98) + 0x28);
  uVar2 = swr_slvdev_datapath_control(lVar1,*(undefined1 *)(lVar1 + 0x40),0);
  return uVar2;
}



//------------------------------------------------------------
// wcd939x_codec_enable_ear_pa @ 00107218 size=416
// signature: undefined wcd939x_codec_enable_ear_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_codec_enable_ear_pa(long param_1,undefined8 param_2,int param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar3 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  switch(param_3) {
  case 1:
    uVar1 = swr_slvdev_datapath_control
                      (*(long *)(lVar4 + 0x28),*(undefined1 *)(*(long *)(lVar4 + 0x28) + 0x40),1);
    snd_soc_component_update_bits(lVar3,0x3465,7,3);
    snd_soc_component_update_bits(lVar3,0x3008,2,2);
    snd_soc_component_update_bits(lVar3,0x300b,0x80,0x80);
    return uVar1;
  case 2:
    usleep_range_state(6000,0x177a,2);
    pcVar2 = *(code **)(lVar4 + 0xc50);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1072f4);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(lVar4 + 0xc48),1,0x20000);
    }
    wcd_enable_irq(lVar4 + 0x148,0xd);
    break;
  case 4:
    wcd_disable_irq(lVar4 + 0x148,0xd);
    pcVar2 = *(code **)(lVar4 + 0xc50);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107344);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(lVar4 + 0xc48),1,0x20001);
    }
    break;
  case 8:
    snd_soc_component_update_bits(lVar3,0x300b,0x80,0);
    usleep_range_state(7000,0x1b62,2);
    snd_soc_component_update_bits(lVar3,0x3465,7,0);
    wcd_cls_h_fsm(lVar3,lVar4 + 0xe0,2,1,6);
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_codec_enable_hphl_pa @ 001073bc size=1264
// signature: undefined wcd939x_codec_enable_hphl_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_codec_enable_hphl_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  code *pcVar10;
  long lVar11;
  long lVar12;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar12 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar11 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  uVar5 = *(uint *)(lVar11 + 0x11c);
  switch(param_3) {
  case 1:
    if (*(char *)(lVar11 + 0x136) != '\0') {
      snd_soc_component_update_bits(lVar12,0x3067,0x80,0x80);
    }
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107458);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),1,1);
    }
    uVar4 = swr_slvdev_datapath_control
                      (*(long *)(lVar11 + 0x28),*(undefined1 *)(*(long *)(lVar11 + 0x28) + 0x40),1);
    wcd_cls_h_fsm(lVar12,lVar11 + 0xe0,1,2,uVar5);
    wcd939x_config_2Vpk_mode(lVar12,lVar11,1);
    if ((uVar5 < 6) && ((1 << (ulong)(uVar5 & 0x1f) & 0x34U) != 0)) {
      if (*(char *)(lVar11 + 0x118) == '\0') {
        snd_soc_component_update_bits(lVar12,0x30de,1,1);
      }
      if (uVar5 == 4) {
        snd_soc_component_update_bits(lVar12,0x3009,0xc,0);
      }
    }
    if (*(int *)(*(long *)(*(long *)(lVar11 + 0x100) + 0x90) + 0x58) != 0) {
      uVar9 = 4;
      if (uVar5 != 4 && uVar5 != 1) {
        uVar9 = 2;
      }
      wcd_usbss_audio_config(0,0,uVar9);
    }
    snd_soc_component_update_bits(lVar12,0x30a8,0xf0,0xd0);
    snd_soc_component_update_bits(lVar12,0x3009,0x20,0x20);
    uVar5 = snd_soc_component_read(lVar12,0x3009);
    if (((uVar5 ^ 0xffffffff) & 0x30) == 0) {
      usleep_range_state(0x9c4,0xa28,2);
    }
    puVar1 = (ulong *)(lVar11 + 0x178);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x40;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (*(char *)(lVar11 + 0x118) == '\0') {
      snd_soc_component_update_bits(lVar12,0x3465,7,3);
      return uVar4;
    }
    return uVar4;
  case 2:
    if (((uint)*(undefined8 *)(lVar11 + 0x178) >> 6 & 1) != 0) {
      if (*(char *)(lVar11 + 0x134) == '\0') {
        uVar6 = 20000;
        uVar8 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar8 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar8,2);
      if (((uVar5 < 6) && ((1 << (ulong)(uVar5 & 0x1f) & 0x34U) != 0)) &&
         (*(char *)(lVar11 + 0x118) == '\0')) {
        snd_soc_component_update_bits(lVar12,0x30de,1,0);
      }
      puVar1 = (ulong *)(lVar11 + 0x178);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    snd_soc_component_update_bits(lVar12,0x313a,2,2);
    if ((uVar5 < 9) && ((1 << (ulong)(uVar5 & 0x1f) & 0x1c8U) != 0)) {
      snd_soc_component_update_bits(lVar12,0x3008,2,2);
    }
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10776c);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),1,0);
    }
    if (*(char *)(lVar11 + 0x118) == '\0') {
      wcd_enable_irq(lVar11 + 0x148,0xb);
    }
    break;
  case 4:
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1075c8);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),1,1);
    }
    wcd_disable_irq(lVar11 + 0x148,0xb);
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if ((pcVar10 != (code *)0x0) && (*(char *)(lVar11 + 0x134) != '\0')) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10760c);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),4,0);
    }
    if (*(char *)(lVar11 + 0x134) == '\0') {
      uVar6 = 20000;
      uVar8 = 0x4e84;
    }
    else {
      uVar6 = 7000;
      uVar8 = 0x1bbc;
    }
    usleep_range_state(uVar6,uVar8,2);
    snd_soc_component_update_bits(lVar12,0x3009,0x80,0);
    blocking_notifier_call_chain(*(long *)(lVar11 + 0x100) + 0x428,0xd);
    puVar1 = (ulong *)(lVar11 + 0x178);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x40;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    break;
  case 8:
    if (((uint)*(undefined8 *)(lVar11 + 0x178) >> 6 & 1) != 0) {
      if (*(char *)(lVar11 + 0x134) == '\0') {
        uVar6 = 21000;
        uVar8 = 0x526c;
      }
      else {
        uVar6 = 7000;
        uVar8 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar8,2);
      puVar1 = (ulong *)(lVar11 + 0x178);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    blocking_notifier_call_chain(*(long *)(lVar11 + 0x100) + 0x428,10);
    snd_soc_component_update_bits(lVar12,0x3009,0x20,0);
    snd_soc_component_update_bits(lVar12,0x3465,7,0);
    if ((*(int *)(*(long *)(*(long *)(lVar11 + 0x100) + 0x90) + 0x58) != 0) &&
       (uVar7 = snd_soc_component_read(lVar12,0x3009), (uVar7 & 0xc0) == 0)) {
      wcd_usbss_audio_config(0,0,1);
    }
    wcd_cls_h_fsm(lVar12,lVar11 + 0xe0,2,2,uVar5);
    if (*(char *)(lVar11 + 0x136) != '\0') {
      snd_soc_component_update_bits(lVar12,0x3067,0x80,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_codec_enable_hphr_pa @ 001078ec size=1264
// signature: undefined wcd939x_codec_enable_hphr_pa(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd939x_codec_enable_hphr_pa(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  code *pcVar10;
  long lVar11;
  long lVar12;
  
  if (7 < param_3 - 1U) {
    return 0;
  }
  lVar12 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar11 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  uVar5 = *(uint *)(lVar11 + 0x11c);
  switch(param_3) {
  case 1:
    if (*(char *)(lVar11 + 0x136) != '\0') {
      snd_soc_component_update_bits(lVar12,0x3067,0x80,0x80);
    }
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107988);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),1,0x10001);
    }
    uVar4 = swr_slvdev_datapath_control
                      (*(long *)(lVar11 + 0x28),*(undefined1 *)(*(long *)(lVar11 + 0x28) + 0x40),1);
    wcd_cls_h_fsm(lVar12,lVar11 + 0xe0,1,4,uVar5);
    wcd939x_config_2Vpk_mode(lVar12,lVar11,1);
    if ((uVar5 < 6) && ((1 << (ulong)(uVar5 & 0x1f) & 0x34U) != 0)) {
      if (*(char *)(lVar11 + 0x118) == '\0') {
        snd_soc_component_update_bits(lVar12,0x30de,1,1);
      }
      if (uVar5 == 4) {
        snd_soc_component_update_bits(lVar12,0x3009,0xc,0);
      }
    }
    if (*(int *)(*(long *)(*(long *)(lVar11 + 0x100) + 0x90) + 0x58) != 0) {
      uVar9 = 4;
      if (uVar5 != 4 && uVar5 != 1) {
        uVar9 = 2;
      }
      wcd_usbss_audio_config(0,0,uVar9);
    }
    snd_soc_component_update_bits(lVar12,0x30a8,0xf0,0xd0);
    snd_soc_component_update_bits(lVar12,0x3009,0x10,0x10);
    uVar5 = snd_soc_component_read(lVar12,0x3009);
    if (((uVar5 ^ 0xffffffff) & 0x30) == 0) {
      usleep_range_state(0x9c4,0xa28,2);
    }
    puVar1 = (ulong *)(lVar11 + 0x178);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x40;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (*(char *)(lVar11 + 0x118) == '\0') {
      snd_soc_component_update_bits(lVar12,0x3466,7,3);
      return uVar4;
    }
    return uVar4;
  case 2:
    if (((uint)*(undefined8 *)(lVar11 + 0x178) >> 6 & 1) != 0) {
      if (*(char *)(lVar11 + 0x135) == '\0') {
        uVar6 = 20000;
        uVar8 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar8 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar8,2);
      if (((uVar5 < 6) && ((1 << (ulong)(uVar5 & 0x1f) & 0x34U) != 0)) &&
         (*(char *)(lVar11 + 0x118) == '\0')) {
        snd_soc_component_update_bits(lVar12,0x30de,1,0);
      }
      puVar1 = (ulong *)(lVar11 + 0x178);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    snd_soc_component_update_bits(lVar12,0x313a,2,2);
    if ((uVar5 < 9) && ((1 << (ulong)(uVar5 & 0x1f) & 0x1c8U) != 0)) {
      snd_soc_component_update_bits(lVar12,0x3008,2,2);
    }
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107c9c);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),1,0x10000);
    }
    if (*(char *)(lVar11 + 0x118) == '\0') {
      wcd_enable_irq(lVar11 + 0x148,0xc);
    }
    break;
  case 4:
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107af8);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),1,0x10001);
    }
    wcd_disable_irq(lVar11 + 0x148,0xc);
    pcVar10 = *(code **)(lVar11 + 0xc50);
    if ((pcVar10 != (code *)0x0) && (*(char *)(lVar11 + 0x135) != '\0')) {
      if (*(int *)(pcVar10 + -4) != 0x6562e36b) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107b3c);
        (*pcVar10)();
      }
      (*pcVar10)(*(undefined8 *)(lVar11 + 0xc48),4,0x10000);
    }
    if (*(char *)(lVar11 + 0x135) == '\0') {
      uVar6 = 20000;
      uVar8 = 0x4e84;
    }
    else {
      uVar6 = 7000;
      uVar8 = 0x1bbc;
    }
    usleep_range_state(uVar6,uVar8,2);
    snd_soc_component_update_bits(lVar12,0x3009,0x40,0);
    blocking_notifier_call_chain(*(long *)(lVar11 + 0x100) + 0x428,0xe);
    puVar1 = (ulong *)(lVar11 + 0x178);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x40;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    break;
  case 8:
    if (((uint)*(undefined8 *)(lVar11 + 0x178) >> 6 & 1) != 0) {
      if (*(char *)(lVar11 + 0x135) == '\0') {
        uVar6 = 20000;
        uVar8 = 0x4e84;
      }
      else {
        uVar6 = 7000;
        uVar8 = 0x1bbc;
      }
      usleep_range_state(uVar6,uVar8,2);
      puVar1 = (ulong *)(lVar11 + 0x178);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xffffffffffffffbf;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    blocking_notifier_call_chain(*(long *)(lVar11 + 0x100) + 0x428,0xc);
    snd_soc_component_update_bits(lVar12,0x3009,0x10,0);
    snd_soc_component_update_bits(lVar12,0x3466,7,0);
    if ((*(int *)(*(long *)(*(long *)(lVar11 + 0x100) + 0x90) + 0x58) != 0) &&
       (uVar7 = snd_soc_component_read(lVar12,0x3009), (uVar7 & 0xc0) == 0)) {
      wcd_usbss_audio_config(0,0,1);
    }
    wcd_cls_h_fsm(lVar12,lVar11 + 0xe0,2,4,uVar5);
    if (*(char *)(lVar11 + 0x136) != '\0') {
      snd_soc_component_update_bits(lVar12,0x3067,0x80,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_codec_hphl_dac_event @ 00107e1c size=424
// signature: undefined wcd939x_codec_hphl_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_hphl_dac_event(long param_1,undefined8 param_2,int param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar5,0x3140,0x3f,1);
    uVar3 = 0;
  }
  else {
    lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    if (param_3 == 2) {
      snd_soc_component_update_bits(lVar5,0x3140,0x3f,0x1d);
      if (*(char *)(lVar6 + 0x118) == '\0') {
        if (*(char *)(lVar6 + 0x134) == '\0') {
          snd_soc_component_update_bits(lVar5,0x3414,2,0);
          uVar3 = 0x30d3;
          uVar2 = 0x20;
          uVar4 = 0x20;
        }
        else {
          snd_soc_component_update_bits(lVar5,0x3414,2,2);
          if ((*(char *)(lVar6 + 0x135) == '\0') ||
             (uVar1 = snd_soc_component_read(lVar5,0x3414), (uVar1 & 1) != 0)) {
            usleep_range_state(5000,0x1392,2);
          }
          uVar3 = 0x313a;
          uVar2 = 2;
          uVar4 = 0;
        }
        snd_soc_component_update_bits(lVar5,uVar3,uVar2,uVar4);
        if (*(char *)(lVar6 + 0x118) == '\0') {
          return 0;
        }
      }
      snd_soc_component_update_bits(lVar5,0x313a,2,0);
      snd_soc_component_write(lVar5,0x30a5,0xeb);
      if (*(int *)(lVar6 + 0x11c) == 4) {
        snd_soc_component_write(lVar5,0x3145,0x52);
        return 0;
      }
      snd_soc_component_write(lVar5,0x3145,100);
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    if (*(char *)(lVar6 + 0x118) == '\0') {
      snd_soc_component_update_bits(lVar5,0x30d9,0x80,0);
    }
    wcd939x_config_2Vpk_mode(lVar5,lVar6,0);
    uVar3 = 4;
  }
  snd_soc_component_update_bits(lVar5,0x344e,4,uVar3);
  return 0;
}



//------------------------------------------------------------
// wcd939x_codec_hphr_dac_event @ 00107fc8 size=404
// signature: undefined wcd939x_codec_hphr_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_hphr_dac_event(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0x28) + -0xd0;
  if (param_3 == 8) {
    snd_soc_component_update_bits(lVar5,0x3141,0x3f,1);
    uVar3 = 0;
  }
  else {
    lVar6 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    if (param_3 == 2) {
      snd_soc_component_update_bits(lVar5,0x3141,0x3f,0x1d);
      if (*(char *)(lVar6 + 0x118) == '\0') {
        if (*(char *)(lVar6 + 0x134) == '\0') {
          snd_soc_component_update_bits(lVar5,0x3414,1,0);
          uVar3 = 0x30d6;
          uVar2 = 0x20;
          uVar4 = 0x20;
        }
        else {
          snd_soc_component_update_bits(lVar5,0x3414,1,1);
          if ((*(char *)(lVar6 + 0x135) == '\0') ||
             (uVar1 = snd_soc_component_read(lVar5,0x3414), (uVar1 >> 1 & 1) != 0)) {
            usleep_range_state(5000,0x1392,2);
          }
          uVar3 = 0x313a;
          uVar2 = 2;
          uVar4 = 0;
        }
        snd_soc_component_update_bits(lVar5,uVar3,uVar2,uVar4);
        if (*(char *)(lVar6 + 0x118) == '\0') {
          return 0;
        }
      }
      snd_soc_component_write(lVar5,0x30a5,0xeb);
      if (*(int *)(lVar6 + 0x11c) == 4) {
        snd_soc_component_write(lVar5,0x3145,0x52);
        return 0;
      }
      snd_soc_component_write(lVar5,0x3145,100);
      return 0;
    }
    if (param_3 != 1) {
      return 0;
    }
    if (*(char *)(lVar6 + 0x118) == '\0') {
      snd_soc_component_update_bits(lVar5,0x30d9,0x80,0);
    }
    wcd939x_config_2Vpk_mode(lVar5,lVar6,0);
    uVar3 = 8;
  }
  snd_soc_component_update_bits(lVar5,0x344e,8,uVar3);
  return 0;
}



//------------------------------------------------------------
// wcd939x_codec_ear_dac_event @ 00108160 size=184
// signature: undefined wcd939x_codec_ear_dac_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_ear_dac_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x28) + -0xd0;
  if ((int)param_3 == 8) {
    uVar1 = 0x30ec;
    uVar2 = 0x80;
    uVar3 = 0x80;
  }
  else {
    if ((int)param_3 != 1) {
      return 0;
    }
    lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
    snd_soc_component_update_bits(lVar4,0x344f,param_3,1);
    snd_soc_component_update_bits(lVar4,0x30ec,0x80,0);
    usleep_range_state(5000,0x1392,2);
    wcd_cls_h_fsm(lVar4,lVar5 + 0xe0,1,1,6);
    uVar1 = 0x30a8;
    uVar2 = 0xf0;
    uVar3 = 0xd0;
  }
  snd_soc_component_update_bits(lVar4,uVar1,uVar2,uVar3);
  return 0;
}



//------------------------------------------------------------
// wcd939x_rx_mux @ 0010821c size=752
// signature: undefined wcd939x_rx_mux(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_rx_mux(long param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  char cVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0x28);
  lVar9 = lVar11 + -0xd0;
  lVar10 = *(long *)(*(long *)(lVar11 + -0xb8) + 0x98);
  iVar3 = *(int *)(lVar10 + 0x11c);
  if (param_3 == 8) {
    if (lVar9 == 0) {
      iVar2 = ___ratelimit(wcd939x_config_xtalk__rs,"wcd939x_config_xtalk");
      if (iVar2 != 0) {
        _printk(&DAT_0011fcff,"wcd939x_config_xtalk");
      }
    }
    else {
      if (1 < *(byte *)(param_1 + 0x4c)) goto LAB_00108508;
      if (*(int *)(lVar10 + (ulong)*(byte *)(param_1 + 0x4c) * 4 + 0x110) != 0) {
        snd_soc_component_update_bits(lVar9,0x3520,0,0);
      }
    }
    wcd939x_config_compander(lVar9,8,*(undefined1 *)(param_1 + 0x4c));
    if ((*(char *)(lVar10 + 0x118) != '\0') && (iVar3 == 5)) {
      snd_soc_component_update_bits(lVar9,0x30dd,3,0);
      snd_soc_component_update_bits(lVar9,0x30dd,0xc,0);
    }
    wcd939x_rx_clk_disable(lVar9);
    return 0;
  }
  if (param_3 != 2) {
    if (param_3 != 1) {
      return 0;
    }
    wcd939x_rx_clk_enable(lVar9);
    if (*(char *)(lVar10 + 0x118) != '\0') {
      wcd939x_config_power_mode(lVar9,1,*(undefined1 *)(param_1 + 0x4c),iVar3);
    }
    wcd939x_config_compander(lVar9,1,*(undefined1 *)(param_1 + 0x4c));
    wcd939x_config_xtalk(lVar9,1,*(undefined1 *)(param_1 + 0x4c));
    return 0;
  }
  if (lVar9 == 0) {
    iVar2 = ___ratelimit(wcd939x_config_xtalk__rs,"wcd939x_config_xtalk");
    if (iVar2 == 0) {
LAB_001083a0:
      cVar6 = *(char *)(lVar10 + 0x118);
    }
    else {
      _printk(&DAT_0011fcff,"wcd939x_config_xtalk");
      cVar6 = *(char *)(lVar10 + 0x118);
    }
  }
  else {
    if (1 < *(byte *)(param_1 + 0x4c)) {
LAB_00108508:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10850c);
      (*pcVar1)();
    }
    if (*(int *)(lVar10 + (ulong)*(byte *)(param_1 + 0x4c) * 4 + 0x110) == 0) goto LAB_001083a0;
    snd_soc_component_update_bits(lVar9,0x3520,0xf,0xf);
    cVar6 = *(char *)(lVar10 + 0x118);
  }
  if (cVar6 != '\0') {
    uVar8 = 2;
    if (iVar3 != 1 && iVar3 != 6) {
      uVar8 = 0;
    }
    snd_soc_component_update_bits(lVar9,0x3501,2,uVar8);
  }
  if (lVar9 == 0) {
    iVar3 = ___ratelimit(wcd939x_enable_hph_pcm_index__rs,"wcd939x_enable_hph_pcm_index");
    if (iVar3 == 0) {
      return 0;
    }
    _printk(&DAT_0011fcff,"wcd939x_enable_hph_pcm_index");
    return 0;
  }
  lVar10 = *(long *)(*(long *)(lVar11 + -0xb8) + 0x98);
  if (*(char *)(lVar10 + 0x118) == '\0') {
    return 0;
  }
  if (*(char *)(param_1 + 0x4c) == '\x01') {
    cVar6 = *(char *)(lVar10 + 0xc9f);
    if (cVar6 == '\x02') {
LAB_0010847c:
      snd_soc_component_update_bits(lVar9,0x351f,3,cVar6);
    }
    else if (cVar6 == '\0') {
      cVar6 = '\x03';
      goto LAB_0010847c;
    }
    snd_soc_component_update_bits(lVar9,0x351e,2,2);
    uVar4 = 0x351e;
    uVar5 = 4;
    uVar7 = 0xc;
    goto LAB_001084b0;
  }
  if (*(char *)(param_1 + 0x4c) != '\0') {
    return 0;
  }
  cVar6 = *(char *)(lVar10 + 0xc9f);
  if (cVar6 == '\x02') {
LAB_00108400:
    snd_soc_component_update_bits(lVar9,0x351d,3,cVar6);
  }
  else if (cVar6 == '\0') {
    cVar6 = '\x03';
    goto LAB_00108400;
  }
  snd_soc_component_update_bits(lVar9,0x351c,1,1);
  uVar4 = 0x351c;
  uVar5 = 2;
  uVar7 = 6;
LAB_001084b0:
  snd_soc_component_update_bits(lVar9,uVar4,uVar5,uVar7);
  return 0;
}



//------------------------------------------------------------
// wcd939x_rx3_mux @ 00108510 size=64
// signature: undefined wcd939x_rx3_mux(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_rx3_mux(long param_1,undefined8 param_2,int param_3)

{
  if (param_3 == 8) {
    wcd939x_rx_clk_disable(*(long *)(param_1 + 0x28) + -0xd0);
  }
  else if (param_3 == 1) {
    wcd939x_rx_clk_enable();
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_enable_rx1 @ 00108554 size=604
// signature: undefined wcd939x_enable_rx1(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_enable_rx1(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 local_4c;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar5 = *(long *)(param_1 + 0x28);
  lVar3 = lVar5 + -0xd0;
  lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
  if (param_3 == 8) {
    if (*(char *)(lVar4 + 0x118) == '\0') {
      local_3c[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      iVar1 = wcd939x_set_port_params(lVar3,0xe,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_48);
      }
      if (*(char *)(lVar4 + 0x134) == '\0') goto LAB_0010877c;
      lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
      uVar2 = 0x10;
    }
    else {
      uVar2 = 0x3b;
    }
    local_3c[0] = 0;
    local_44[0] = 0;
    local_48[0] = 0;
    iVar1 = wcd939x_set_port_params(lVar3,uVar2,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_48);
    }
  }
  else if (param_3 == 1) {
    if (*(char *)(lVar4 + 0x118) == '\0') {
      local_3c[0] = 0;
      local_40[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      local_4c = 0;
      iVar1 = wcd939x_set_port_params(lVar3,0xe,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_4c,local_40,
                         local_48);
      }
      if (*(char *)(lVar4 + 0x134) == '\0') goto LAB_0010877c;
      lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
      uVar2 = 0x10;
    }
    else {
      uVar2 = 0x3b;
    }
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48[0] = 0;
    local_4c = 0;
    iVar1 = wcd939x_set_port_params(lVar3,uVar2,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_4c,local_40,local_48
                      );
    }
  }
LAB_0010877c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_enable_rx2 @ 001087b4 size=604
// signature: undefined wcd939x_enable_rx2(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_enable_rx2(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 local_4c;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar5 = *(long *)(param_1 + 0x28);
  lVar3 = lVar5 + -0xd0;
  lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
  if (param_3 == 8) {
    if (*(char *)(lVar4 + 0x118) == '\0') {
      local_3c[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      iVar1 = wcd939x_set_port_params(lVar3,0xf,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_48);
      }
      if (*(char *)(lVar4 + 0x135) == '\0') goto LAB_001089dc;
      lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
      uVar2 = 0x11;
    }
    else {
      uVar2 = 0x3c;
    }
    local_3c[0] = 0;
    local_44[0] = 0;
    local_48[0] = 0;
    iVar1 = wcd939x_set_port_params(lVar3,uVar2,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,local_48);
    }
  }
  else if (param_3 == 1) {
    if (*(char *)(lVar4 + 0x118) == '\0') {
      local_3c[0] = 0;
      local_40[0] = 0;
      local_44[0] = 0;
      local_48[0] = 0;
      local_4c = 0;
      iVar1 = wcd939x_set_port_params(lVar3,0xf,local_3c,local_40,local_44,&local_4c,local_48,1);
      if (iVar1 == 0) {
        swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_4c,local_40,
                         local_48);
      }
      if (*(char *)(lVar4 + 0x135) == '\0') goto LAB_001089dc;
      lVar4 = *(long *)(*(long *)(lVar5 + -0xb8) + 0x98);
      uVar2 = 0x11;
    }
    else {
      uVar2 = 0x3c;
    }
    local_3c[0] = 0;
    local_40[0] = 0;
    local_44[0] = 0;
    local_48[0] = 0;
    local_4c = 0;
    iVar1 = wcd939x_set_port_params(lVar3,uVar2,local_3c,local_40,local_44,&local_4c,local_48,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar4 + 0x28),local_3c,1,local_44,&local_4c,local_40,local_48
                      );
    }
  }
LAB_001089dc:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_enable_rx3 @ 00108a14 size=300
// signature: undefined wcd939x_enable_rx3(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_enable_rx3(long param_1,undefined8 param_2,int param_3)

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
  if (param_3 == 8) {
    lVar3 = *(long *)(*(long *)(lVar2 + -0xb8) + 0x98);
    local_2c[0] = 0;
    local_34[0] = 0;
    local_38[0] = 0;
    iVar1 = wcd939x_set_port_params
                      (lVar2 + -0xd0,0x13,local_2c,local_30,local_34,&local_3c,local_38,1);
    if (iVar1 == 0) {
      swr_disconnect_port(*(undefined8 *)(lVar3 + 0x28),local_2c,1,local_34,local_38);
    }
    usleep_range_state(6000,0x177a,2);
  }
  else if (param_3 == 1) {
    lVar3 = *(long *)(*(long *)(lVar2 + -0xb8) + 0x98);
    local_2c[0] = 0;
    local_30[0] = 0;
    local_34[0] = 0;
    local_38[0] = 0;
    local_3c = 0;
    iVar1 = wcd939x_set_port_params
                      (lVar2 + -0xd0,0x13,local_2c,local_30,local_34,&local_3c,local_38,1);
    if (iVar1 == 0) {
      swr_connect_port(*(undefined8 *)(lVar3 + 0x28),local_2c,1,local_34,&local_3c,local_30,local_38
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
// wcd939x_codec_enable_micbias_pullup @ 00108b44 size=256
// signature: undefined wcd939x_codec_enable_micbias_pullup(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_codec_enable_micbias_pullup(long param_1,undefined8 param_2,int param_3)

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
  wcd939x_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd939x_tx_connect_port @ 00108c44 size=280
// signature: undefined wcd939x_tx_connect_port(void)
// callers: [wcd939x_codec_enable_dmic, wcd939x_codec_enable_adc, wcd939x_tx_swr_ctrl]
//------------------------------------------------------------

void wcd939x_tx_connect_port(long param_1,undefined8 param_2,int param_3,char param_4)

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
  iVar2 = wcd939x_set_port_params(param_1,param_2,local_3c,local_40,local_44,&local_4c,local_48,0);
  if (iVar2 == 0) {
    if (param_3 != 0) {
      local_4c = param_3;
    }
    uVar1 = (int)param_2 - 0x1d;
    if ((uVar1 & 0xff) < 0xd) {
      local_48[0] = *(undefined1 *)
                     (lVar4 + (ulong)(byte)swr_slv_tx_ch_idx
                                           [*(long *)(&DAT_00119a50 + (long)(char)uVar1 * 8) * 2 + 1
                                           ] + 0xc91);
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
// wcd939x_set_port_params @ 00108d5c size=508
// signature: undefined wcd939x_set_port_params(void)
// callers: [wcd939x_enable_rx2, wcd939x_codec_enable_adc, wcd939x_enable_clsh, wcd939x_enable_rx3, wcd939x_tx_swr_ctrl, wcd939x_tx_connect_port, wcd939x_enable_rx1]
//------------------------------------------------------------

undefined8
wcd939x_set_port_params
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
    lVar6 = lVar7 + 0x184;
    pbVar9 = (byte *)(lVar7 + 0x180);
  }
  else {
    if (param_8 != 1) {
      iVar3 = ___ratelimit(wcd939x_set_port_params__rs,"wcd939x_set_port_params");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x18);
      pcVar5 = "%s Invalid path selected %u\n";
      goto LAB_00108f3c;
    }
    lVar6 = lVar7 + 0x684;
    pbVar9 = (byte *)(lVar7 + 0x181);
  }
  lVar7 = 0;
  bVar2 = false;
  param_8 = param_2 & 0xff;
  lVar10 = 1;
  uVar8 = 0;
  do {
    if ((int)lVar7 == 0x500) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x108f58);
      (*pcVar1)();
    }
    if (*(uint *)(lVar6 + lVar7) == param_8) {
      lVar10 = 0;
joined_r0x00108e84:
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
    if (*(uint *)(lVar6 + lVar7 + 0x14) == param_8) goto joined_r0x00108e84;
    if (*(uint *)(lVar6 + lVar7 + 0x28) == param_8) {
      lVar10 = 2;
      goto joined_r0x00108e84;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x3c) == param_8) {
      lVar10 = 3;
      goto joined_r0x00108e84;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x50) == param_8) {
      lVar10 = 4;
      goto joined_r0x00108e84;
    }
    if (*(uint *)(lVar6 + lVar7 + 100) == param_8) {
      lVar10 = 5;
      goto joined_r0x00108e84;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x78) == param_8) {
      lVar10 = 6;
      goto joined_r0x00108e84;
    }
    if (*(uint *)(lVar6 + lVar7 + 0x8c) == param_8) {
      lVar10 = 7;
      goto joined_r0x00108e84;
    }
    bVar2 = *pbVar9 <= uVar8;
    lVar7 = lVar7 + 0xa0;
    uVar8 = uVar8 + 1;
  } while ((uint)*pbVar9 * 0xa0 + 0xa0 != (int)lVar7);
  iVar3 = ___ratelimit(wcd939x_set_port_params__rs_278,"wcd939x_set_port_params");
  if (iVar3 == 0) {
    return 0xffffffea;
  }
  uVar4 = *(undefined8 *)(param_1 + 0x18);
  pcVar5 = "%s Failed to find slave port for type %u\n";
LAB_00108f3c:
  _dev_err(uVar4,pcVar5,"wcd939x_set_port_params",param_8);
  return 0xffffffea;
}



//------------------------------------------------------------
// __wcd939x_codec_enable_micbias @ 00108f58 size=256
// signature: undefined __wcd939x_codec_enable_micbias(void)
// callers: [wcd939x_codec_enable_micbias, wcd939x_codec_force_enable_micbias]
//------------------------------------------------------------

undefined8 __wcd939x_codec_enable_micbias(long param_1,int param_2)

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
  wcd939x_micbias_control(lVar4 + -0xd0,uVar2,uVar3,1);
  return 0;
}



//------------------------------------------------------------
// wcd939x_config_2Vpk_mode @ 00109058 size=368
// signature: undefined wcd939x_config_2Vpk_mode(void)
// callers: [wcd939x_config_compander, wcd939x_codec_hphr_dac_event, wcd939x_codec_enable_hphl_pa, wcd939x_codec_enable_hphr_pa, wcd939x_codec_hphl_dac_event]
//------------------------------------------------------------

void wcd939x_config_2Vpk_mode(long param_1,long param_2,int param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (*(char *)(param_2 + 0x139) == '\0') goto LAB_0010919c;
  iVar2 = wcd_mbhc_get_impedance(*(undefined8 *)(param_2 + 0x100),(long)&local_30 + 4,&local_30);
  if (iVar2 != 0) {
    iVar2 = ___ratelimit(wcd939x_config_2Vpk_mode__rs,"wcd939x_config_2Vpk_mode");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Unable to get impedance for 2Vpk mode",
               "wcd939x_config_2Vpk_mode");
    }
    goto LAB_0010919c;
  }
  if (param_3 == 2) {
    if (local_30._4_4_ < 0x104) goto LAB_0010919c;
    snd_soc_component_update_bits(param_1,0x3133,0x1f,2);
    uVar3 = 0x3136;
    uVar4 = 0x1f;
LAB_00109178:
    uVar5 = 2;
  }
  else if (param_3 == 1) {
    if (0x103 < local_30._4_4_) {
      snd_soc_component_update_bits(param_1,0x3008,2,2);
      uVar3 = 0x30b2;
      uVar4 = 0xf;
      goto LAB_00109178;
    }
    uVar3 = 0x30b2;
    uVar4 = 0xf;
    uVar5 = 0xd;
  }
  else {
    if (param_3 != 0) goto LAB_0010919c;
    snd_soc_component_update_bits(param_1,0x3133,0x40,0x40);
    uVar3 = 0x3133;
    uVar4 = 0x80;
    if (local_30._4_4_ < 0x104) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0x80;
    }
  }
  snd_soc_component_update_bits(param_1,uVar3,uVar4,uVar5);
LAB_0010919c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd939x_rx_clk_enable @ 001091c8 size=200
// signature: undefined wcd939x_rx_clk_enable(void)
// callers: [wcd939x_rx_mux, wcd939x_rx3_mux]
//------------------------------------------------------------

void wcd939x_rx_clk_enable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  iVar1 = *(int *)(lVar2 + 0x170);
  if (iVar1 == 0) {
    snd_soc_component_update_bits(param_1,0x3008,1,1);
    snd_soc_component_update_bits(param_1,0x3408,1,1);
    snd_soc_component_update_bits(param_1,0x3408,2,2);
    snd_soc_component_update_bits(param_1,0x3408,4,4);
    snd_soc_component_update_bits(param_1,0x3409,1,1);
    snd_soc_component_update_bits(param_1,0x3409,2,2);
    snd_soc_component_update_bits(param_1,0x3409,4,4);
    iVar1 = *(int *)(lVar2 + 0x170);
  }
  *(int *)(lVar2 + 0x170) = iVar1 + 1;
  return;
}



//------------------------------------------------------------
// wcd939x_config_power_mode @ 00109290 size=620
// signature: undefined wcd939x_config_power_mode(void)
// callers: [wcd939x_rx_mux]
//------------------------------------------------------------

void wcd939x_config_power_mode(long param_1,int param_2,uint param_3,int param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_2 == 8) {
    if (param_4 != 5) {
      return;
    }
    snd_soc_component_update_bits(param_1,0x30dd,3,0);
    uVar2 = 0x30dd;
    uVar3 = 0xc;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    lVar5 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (param_4 == 5) {
      snd_soc_component_update_bits(param_1,0x30dd,0xc,4);
      snd_soc_component_update_bits(param_1,0x30dd,3,1);
      if (1 < param_3) {
LAB_001094f8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1094fc);
        (*pcVar1)();
      }
      if (*(int *)(lVar5 + (ulong)param_3 * 4 + 0x108) == 0) {
        return;
      }
      if (param_3 == 1) {
        snd_soc_component_update_bits(param_1,0x356c,0x7f,0x21);
        snd_soc_component_update_bits(param_1,0x356d,0x7f,0x30);
        snd_soc_component_update_bits(param_1,0x356e,0x7f,0x3f);
        snd_soc_component_update_bits(param_1,0x356f,0x7f,0x48);
        uVar2 = 0x3571;
      }
      else {
        if (param_3 != 0) {
          return;
        }
        snd_soc_component_update_bits(param_1,0x354c,0x7f,0x21);
        snd_soc_component_update_bits(param_1,0x354d,0x7f,0x30);
        snd_soc_component_update_bits(param_1,0x354e,0x7f,0x3f);
        snd_soc_component_update_bits(param_1,0x354f,0x7f,0x48);
        uVar2 = 0x3551;
      }
      uVar3 = 0x3f;
      uVar4 = 0xc;
      goto LAB_00109480;
    }
    if (1 < param_3) goto LAB_001094f8;
    if (*(int *)(lVar5 + (ulong)param_3 * 4 + 0x108) == 0) {
      return;
    }
    if (param_3 == 1) {
      snd_soc_component_update_bits(param_1,0x356c,0x7f,0x1e);
      snd_soc_component_update_bits(param_1,0x356d,0x7f,0x2a);
      snd_soc_component_update_bits(param_1,0x356e,0x7f,0x36);
      snd_soc_component_update_bits(param_1,0x356f,0x7f,0x3c);
      uVar2 = 0x3571;
      uVar3 = 0x3f;
    }
    else {
      if (param_3 != 0) {
        return;
      }
      snd_soc_component_update_bits(param_1,0x354c,0x7f,0x1e);
      snd_soc_component_update_bits(param_1,0x354d,0x7f,0x2a);
      snd_soc_component_update_bits(param_1,0x354e,0x7f,0x36);
      snd_soc_component_update_bits(param_1,0x354f,0x7f,0x3c);
      uVar2 = 0x3551;
      uVar3 = 0x3f;
    }
  }
  uVar4 = 0;
LAB_00109480:
  snd_soc_component_update_bits(param_1,uVar2,uVar3,uVar4);
  return;
}



//------------------------------------------------------------
// wcd939x_config_compander @ 001094fc size=504
// signature: undefined wcd939x_config_compander(void)
// callers: [wcd939x_rx_mux]
//------------------------------------------------------------

void wcd939x_config_compander(long param_1,ulong param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  
  if ((int)param_3 < 2) {
    if (param_1 == 0) {
      iVar2 = ___ratelimit(wcd939x_config_compander__rs_340,"wcd939x_config_compander");
      if (iVar2 != 0) {
        _printk(&DAT_0011fcff,"wcd939x_config_compander");
      }
    }
    else {
      lVar6 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
      if (*(char *)(lVar6 + 0x118) != '\0') {
        if (*(int *)(lVar6 + (ulong)param_3 * 4 + 0x108) == 0) {
          uVar5 = 0x30d3;
          if (param_3 != 0) {
            uVar5 = 0x30d6;
          }
          snd_soc_component_update_bits(param_1,uVar5,0x20,(ulong)((param_2 & 3) != 0) << 5);
          wcd939x_config_2Vpk_mode(param_1,lVar6,2);
        }
        else {
          uVar5 = 1;
          if (param_3 == 0) {
            uVar5 = 2;
          }
          uVar1 = param_3 * 0x20 + 0x3540;
          if ((param_2 & 3) == 0) {
            if ((param_2 & 0xc) == 0) {
              return;
            }
            snd_soc_component_update_bits(param_1,0x3414,uVar5,0);
            snd_soc_component_update_bits(param_1,uVar1 & 0xffff,1,0);
            if (param_3 == 0) {
              uVar3 = 0x30d3;
            }
            else {
              if (param_3 != 1) {
                return;
              }
              uVar3 = 0x30d6;
            }
            uVar5 = 0x20;
            uVar4 = 0;
          }
          else {
            snd_soc_component_update_bits(param_1,param_3 * 0x20 + 0x3547 & 0xffe7,0x1e,0);
            uVar1 = uVar1 & 0xffff;
            snd_soc_component_update_bits(param_1,uVar1,1,1);
            usleep_range_state(0xfa,0x104,2);
            snd_soc_component_update_bits(param_1,uVar1,2,2);
            snd_soc_component_update_bits(param_1,uVar1,2,0);
            uVar3 = 0x3414;
            uVar4 = uVar5;
          }
          snd_soc_component_update_bits(param_1,uVar3,uVar5,uVar4);
        }
      }
    }
  }
  else {
    iVar2 = ___ratelimit(wcd939x_config_compander__rs,"wcd939x_config_compander");
    if (iVar2 != 0) {
      _printk(&DAT_0011fb85,"wcd939x_config_compander",(ulong)param_3);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd939x_config_xtalk @ 001096f4 size=400
// signature: undefined wcd939x_config_xtalk(void)
// callers: [wcd939x_rx_mux]
//------------------------------------------------------------

void wcd939x_config_xtalk(long param_1,int param_2,uint param_3)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined8 uVar6;
  long *plVar7;
  long lVar8;
  
  if (param_1 == 0) {
    iVar3 = ___ratelimit(wcd939x_config_xtalk__rs,"wcd939x_config_xtalk");
    if (iVar3 == 0) {
      return;
    }
    _printk(&DAT_0011fcff,"wcd939x_config_xtalk");
    return;
  }
  if (1 < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x109884);
    (*pcVar2)();
  }
  plVar7 = *(long **)(*(long *)(param_1 + 0x18) + 0x98);
  if (*(int *)((long)plVar7 + (ulong)param_3 * 4 + 0x110) == 0) {
    return;
  }
  if (param_2 == 8) {
    iVar3 = 0x3520;
    uVar4 = 0;
    uVar6 = 0;
  }
  else if (param_2 == 2) {
    iVar3 = 0x3520;
    uVar4 = 0xf;
    uVar6 = 0xf;
  }
  else {
    if (param_2 != 1) {
      return;
    }
    iVar1 = param_3 * 4;
    lVar8 = *(long *)(*plVar7 + 0x90);
    iVar3 = iVar1 + 0x3523;
    if (param_3 == 1) {
      snd_soc_component_update_bits(param_1,0x3526,0xff,*(undefined1 *)(lVar8 + 0x103));
      uVar5 = *(undefined1 *)(lVar8 + 0x102);
    }
    else if (param_3 == 0) {
      snd_soc_component_update_bits(param_1,0x3522,0xff,*(undefined1 *)(lVar8 + 0x101));
      uVar5 = *(undefined1 *)(lVar8 + 0x100);
    }
    else {
      snd_soc_component_update_bits(param_1,iVar1 + 0x3522U & 0xffff,0xff,0);
      uVar5 = 0x1f;
    }
    snd_soc_component_update_bits(param_1,iVar1 + 0x3521U & 0xffff,0x1f,uVar5);
    snd_soc_component_update_bits(param_1,iVar1 + 0x3524U & 0xfffc,0xff,0x4f);
    uVar4 = 0x1f;
    uVar6 = 0x11;
  }
  snd_soc_component_update_bits(param_1,iVar3,uVar4,uVar6);
  return;
}



//------------------------------------------------------------
// wcd939x_rx_clk_disable @ 00109884 size=240
// signature: undefined wcd939x_rx_clk_disable(void)
// callers: [wcd939x_rx_mux, wcd939x_rx3_mux]
//------------------------------------------------------------

void wcd939x_rx_clk_disable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  iVar1 = *(int *)(lVar2 + 0x170);
  if ((iVar1 != 0) && (iVar1 = iVar1 + -1, *(int *)(lVar2 + 0x170) = iVar1, iVar1 == 0)) {
    snd_soc_component_update_bits(param_1,0x3008,0x40,0);
    snd_soc_component_update_bits(param_1,0x3008,0x80,0);
    snd_soc_component_update_bits(param_1,0x3409,4,0);
    snd_soc_component_update_bits(param_1,0x3409,2,0);
    snd_soc_component_update_bits(param_1,0x3409,1,0);
    snd_soc_component_update_bits(param_1,0x3408,4,0);
    snd_soc_component_update_bits(param_1,0x3408,2,0);
    snd_soc_component_update_bits(param_1,0x3408,1,0);
    snd_soc_component_update_bits(param_1,0x3008,1,0);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_init_reg @ 00109974 size=512
// signature: undefined wcd939x_init_reg(void)
// callers: [wcd939x_event_notify, wcd939x_soc_codec_probe]
//------------------------------------------------------------

void wcd939x_init_reg(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  snd_soc_component_update_bits(param_1,0x3001,0x80,0x80);
  snd_soc_component_update_bits(param_1,0x3001,0x40,0x40);
  usleep_range_state(10000,0x271a,2);
  snd_soc_component_update_bits(param_1,0x3001,0x40,0);
  snd_soc_component_update_bits(param_1,0x3140,0x3f,0x15);
  snd_soc_component_update_bits(param_1,0x3141,0x3f,0x15);
  snd_soc_component_update_bits(param_1,0x345b,2,2);
  snd_soc_component_update_bits(param_1,0x31e1,0xf0,0x10);
  snd_soc_component_update_bits(param_1,0x31e1,0xf,4);
  snd_soc_component_update_bits(param_1,0x31df,0x1f,8);
  snd_soc_component_update_bits(param_1,0x306b,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x306e,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x3071,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x3074,0xe0,0xe0);
  snd_soc_component_update_bits(param_1,0x308f,1,0);
  lVar1 = of_find_property(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x20) + 0x40) + 0x2e8),
                           "qcom,wcd-disable-legacy-surge",0);
  snd_soc_component_update_bits(param_1,0x30e2,0x80,(ulong)(lVar1 == 0) << 7);
  snd_soc_component_update_bits(param_1,0x30e2,0x40,(ulong)(lVar1 == 0) << 6);
  snd_soc_component_update_bits(param_1,0x30ce,0x10,0x10);
  snd_soc_component_update_bits(param_1,0x30ce,2,2);
  if (*(int *)(lVar2 + 0xc68) != 2) {
    snd_soc_component_write(param_1,0x3581,5);
  }
  snd_soc_component_update_bits(param_1,0x3059,0x80,0x80);
  return;
}



//------------------------------------------------------------
// wcd939x_event_notify @ 00109b78 size=1196
// signature: undefined wcd939x_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_event_notify(undefined8 param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined1 uVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  ulong local_48;
  ulong uStack_40;
  long local_38;
  
  lVar8 = sp_el0;
  uVar4 = (uint)param_2 & 0xffff;
  local_38 = *(long *)(lVar8 + 0x638);
  if (6 < uVar4 - 1) goto switchD_00109bc8_caseD_5;
  plVar10 = *(long **)(param_3 + 0x98);
  lVar8 = plVar10[2];
  switch(uVar4) {
  case 1:
    puVar1 = (ulong *)(plVar10 + 0x2f);
    if ((plVar10[0x2f] & 1U) == 0) {
      if (((uint)*puVar1 >> 1 & 1) == 0) goto LAB_00109be0;
LAB_00109e1c:
      snd_soc_component_update_bits(lVar8,0x300f,0x20,0);
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
      if (((uint)*puVar1 >> 2 & 1) != 0) goto LAB_00109e50;
LAB_00109be8:
      uVar4 = (uint)*puVar1;
    }
    else {
      snd_soc_component_update_bits(lVar8,0x300f,0x40,0);
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
      if (((uint)*puVar1 >> 1 & 1) != 0) goto LAB_00109e1c;
LAB_00109be0:
      if (((uint)*puVar1 >> 2 & 1) == 0) goto LAB_00109be8;
LAB_00109e50:
      snd_soc_component_update_bits(lVar8,0x3011,0x40,0);
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
      snd_soc_component_update_bits(lVar8,0x3011,0x20,0);
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
    snd_soc_component_update_bits(lVar8,0x3009,0x80,0);
    snd_soc_component_update_bits(lVar8,0x3009,0x40,0);
    snd_soc_component_update_bits(lVar8,0x300a,0x80,0);
    break;
  case 3:
    *(undefined1 *)(plVar10 + 0x192) = 0;
    if ((char)plVar10[0x194] != '\0') {
      blocking_notifier_call_chain(plVar10 + 0x195,0,0);
    }
    *(undefined1 *)(plVar10[0x20] + 0x3d0) = 1;
    if ((*(int *)(*(long *)(plVar10[0x20] + 0x90) + 0x58) == 0) ||
       (uVar4 = snd_soc_component_read(lVar8,0x3014), (uVar4 >> 5 & 1) != 0)) {
      uVar7 = 0;
    }
    else {
      uVar7 = 1;
    }
    *(undefined1 *)((long)plVar10 + 0xc9e) = uVar7;
    wcd939x_mbhc_ssr_down(plVar10[0x20],lVar8);
    lVar8 = *plVar10;
    if ((lVar8 != 0) && (lVar9 = *(long *)(lVar8 + 0x98), lVar9 != 0)) {
      if (*(long *)(lVar9 + 0x18) == 0) {
        iVar5 = ___ratelimit(wcd939x_reset_low__rs,"wcd939x_reset_low");
        if (iVar5 == 0) break;
        pcVar6 = "%s: reset gpio device node not specified\n";
      }
      else {
        local_48 = 0x1e;
        uStack_40 = 0x21;
        wcd_usbss_register_update(&local_48,0,2);
        local_48 = local_48 & 0xfffffff1ffffffff | 0x800000000;
        uStack_40 = uStack_40 & 0xfffffff1ffffffff | 0x800000000;
        wcd_usbss_register_update(&local_48,1,2);
        iVar5 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(lVar9 + 0x18));
        if (iVar5 == 0) {
          usleep_range_state(0x14,0x1e,2);
          break;
        }
        iVar5 = ___ratelimit(wcd939x_reset_low__rs_409,"wcd939x_reset_low");
        if (iVar5 == 0) break;
        pcVar6 = "%s: wcd sleep state request fail!\n";
      }
      _dev_err(lVar8,pcVar6,"wcd939x_reset_low");
    }
    break;
  case 4:
    wcd939x_reset(*plVar10);
    usleep_range_state(10000,0x271a,2);
    wcd939x_get_logical_addr(plVar10[6]);
    wcd939x_get_logical_addr(plVar10[5]);
    wcd939x_init_reg(lVar8);
    regcache_mark_dirty(plVar10[4]);
    regcache_sync(plVar10[4]);
    lVar9 = plVar10[0x20];
    iVar5 = wcd939x_mbhc_post_ssr_init(lVar9,lVar8);
    if (iVar5 == 0) {
      wcd939x_mbhc_hs_detect(lVar8,*(undefined8 *)(lVar9 + 0x90));
    }
    else {
      iVar5 = ___ratelimit(wcd939x_event_notify__rs,"wcd939x_event_notify");
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(lVar8 + 0x18),"%s: mbhc initialization failed\n",
                 "wcd939x_event_notify");
      }
    }
    *(undefined1 *)(plVar10[0x20] + 0x3d0) = 0;
    *(undefined1 *)(plVar10 + 0x192) = 1;
    if ((char)plVar10[0x194] != '\0') {
      blocking_notifier_call_chain(plVar10 + 0x195,1,0);
    }
    if (*(char *)((long)plVar10 + 0xc9e) != '\0') {
      lVar8 = -500;
      do {
        __const_udelay(0x418958);
        bVar3 = lVar8 != -1;
        lVar8 = lVar8 + 1;
      } while (bVar3);
    }
    break;
  case 7:
    iVar5 = (int)((ulong)param_2 >> 0x10);
    snd_soc_component_update_bits(lVar8,0x3407,6,iVar5 << 1);
    if (iVar5 == 2) {
      *(undefined1 *)((long)plVar10 + 0xc9f) = 2;
    }
    else if (iVar5 == 1) {
      *(undefined1 *)((long)plVar10 + 0xc9f) = 1;
    }
    else {
      *(undefined1 *)((long)plVar10 + 0xc9f) = 0;
    }
  }
switchD_00109bc8_caseD_5:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_ear_pa_gain_get @ 0010a084 size=64
// signature: undefined wcd939x_ear_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_ear_pa_gain_get(long param_1,long param_2)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0x80),0x300b);
  *(ulong *)(param_2 + 0x48) = (ulong)(uVar1 >> 2 & 0x1f);
  return 0;
}



//------------------------------------------------------------
// wcd939x_ear_pa_gain_put @ 0010a0c8 size=52
// signature: undefined wcd939x_ear_pa_gain_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_ear_pa_gain_put(long param_1,long param_2)

{
  snd_soc_component_update_bits
            (*(undefined8 *)(param_1 + 0x80),0x300b,0x7c,(*(uint *)(param_2 + 0x48) & 0x3f) << 2);
  return 0;
}



//------------------------------------------------------------
// wcd939x_rx_hph_mode_get @ 0010a100 size=28
// signature: undefined wcd939x_rx_hph_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_rx_hph_mode_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(uint *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x11c);
  return 0;
}



//------------------------------------------------------------
// wcd939x_rx_hph_mode_put @ 0010a120 size=184
// signature: undefined wcd939x_rx_hph_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_rx_hph_mode_put(long param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar3 = *(long *)(*(long *)(lVar4 + 0x18) + 0x98);
  iVar1 = *(int *)(param_2 + 0x48);
  if (*(int *)(lVar3 + 8) == 0) {
    if (iVar1 == 0) goto LAB_0010a188;
    if ((iVar1 != 6) && (iVar1 != 1)) goto LAB_0010a1a4;
    iVar1 = ___ratelimit(wcd939x_rx_hph_mode_put__rs,"wcd939x_rx_hph_mode_put");
    if (iVar1 != 0) {
      pcVar2 = "%s:Invalid HPH Mode, default to CLS_H_ULP\n";
      goto LAB_0010a1c4;
    }
  }
  else {
    if (iVar1 != 0) goto LAB_0010a1a4;
LAB_0010a188:
    iVar1 = ___ratelimit(wcd939x_rx_hph_mode_put__rs_381,"wcd939x_rx_hph_mode_put");
    if (iVar1 != 0) {
      pcVar2 = "%s:Invalid HPH Mode, default to class_AB\n";
LAB_0010a1c4:
      _dev_info(*(undefined8 *)(lVar4 + 0x18),pcVar2,"wcd939x_rx_hph_mode_put");
    }
  }
  iVar1 = 5;
LAB_0010a1a4:
  *(int *)(lVar3 + 0x11c) = iVar1;
  return 0;
}



//------------------------------------------------------------
// wcd939x_tx_mode_get @ 0010a1dc size=160
// signature: undefined wcd939x_tx_mode_get(void)
// callers: []
//------------------------------------------------------------

void wcd939x_tx_mode_get(long param_1,long param_2)

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
      uVar2 = wcd939x_tx_path_get(param_1 + 0x20,&local_2c);
      if (-1 < (int)uVar2) {
        if (3 < local_2c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a27c);
          (*pcVar1)();
        }
        uVar2 = 0;
        *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar3 + (ulong)local_2c * 4 + 0x120);
      }
      goto LAB_0010a24c;
    }
  }
  uVar2 = 0xffffffea;
LAB_0010a24c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_tx_mode_put @ 0010a280 size=160
// signature: undefined wcd939x_tx_mode_put(void)
// callers: []
//------------------------------------------------------------

void wcd939x_tx_mode_put(long param_1,long param_2)

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
      uVar2 = wcd939x_tx_path_get(param_1 + 0x20,&local_2c);
      if ((int)uVar2 == 0) {
        if (3 < local_2c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a320);
          (*pcVar1)();
        }
        uVar2 = 0;
        *(undefined4 *)(lVar3 + (ulong)local_2c * 4 + 0x120) = *(undefined4 *)(param_2 + 0x48);
      }
      goto LAB_0010a2f0;
    }
  }
  uVar2 = 0xffffffea;
LAB_0010a2f0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_tx_path_get @ 0010a320 size=336
// signature: undefined wcd939x_tx_path_get(void)
// callers: [wcd939x_tx_mode_get, wcd939x_tx_mode_put]
//------------------------------------------------------------

int wcd939x_tx_path_get(undefined8 param_1,undefined8 param_2)

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
    goto LAB_0010a428;
  }
  pcVar5 = strsep(&local_30," ");
  if (pcVar5 == (char *)0x0) {
    iVar2 = ___ratelimit(wcd939x_tx_path_get__rs,"wcd939x_tx_path_get");
    if (iVar2 != 0) {
      _printk(&DAT_0011f15e,"wcd939x_tx_path_get",local_30);
    }
LAB_0010a41c:
    iVar2 = -0x16;
  }
  else {
    pcVar5 = strpbrk(pcVar5,"0123");
    if (pcVar5 == (char *)0x0) {
      iVar2 = ___ratelimit(wcd939x_tx_path_get__rs_395,"wcd939x_tx_path_get");
      if (iVar2 != 0) {
        _printk(&DAT_0011f480,"wcd939x_tx_path_get");
      }
      goto LAB_0010a41c;
    }
    iVar2 = kstrtouint(pcVar5,10,param_2);
    if ((iVar2 < 0) &&
       (iVar3 = ___ratelimit(wcd939x_tx_path_get__rs_397,"wcd939x_tx_path_get"), iVar3 != 0)) {
      _printk(&DAT_0011f17e,"wcd939x_tx_path_get",pcVar4);
    }
  }
  kfree(pcVar4);
LAB_0010a428:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd939x_get_logical_addr @ 0010a470 size=372
// signature: undefined wcd939x_get_logical_addr(void)
// callers: [wcd939x_event_notify]
//------------------------------------------------------------

void wcd939x_get_logical_addr(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  usleep_range_state(1000,0x3f2,2);
  iVar3 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
  bVar2 = iVar3 == 0;
  if (iVar3 != 0) {
    usleep_range_state(1000,0x3f2,2);
    iVar3 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
    bVar2 = iVar3 == 0;
    if (iVar3 != 0) {
      usleep_range_state(1000,0x3f2,2);
      iVar3 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
      bVar2 = iVar3 == 0;
      if (iVar3 != 0) {
        usleep_range_state(1000,0x3f2,2);
        iVar3 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
        bVar2 = iVar3 == 0;
        if (iVar3 != 0) {
          usleep_range_state(1000,0x3f2,2);
          iVar3 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_2c);
          bVar2 = iVar3 == 0;
        }
      }
    }
  }
  if ((!bVar2) &&
     (iVar3 = ___ratelimit(wcd939x_get_logical_addr__rs,"wcd939x_get_logical_addr"), iVar3 != 0)) {
    _dev_err(param_1 + 0x48,"%s get devnum %d for dev addr %llx failed\n","wcd939x_get_logical_addr"
             ,local_2c[0],*(undefined8 *)(param_1 + 0x3d8));
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
// wcd939x_suspend @ 0010a5e8 size=484
// signature: undefined wcd939x_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  
  if (param_1 == 0) {
    return 0xffffffed;
  }
  plVar7 = *(long **)(param_1 + 0x98);
  if (plVar7 == (long *)0x0) {
    return 0xffffffea;
  }
  lVar8 = *(long *)(*plVar7 + 0x90);
  if (lVar8 == 0) {
    iVar4 = ___ratelimit(wcd939x_suspend__rs,"wcd939x_suspend");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    _dev_err(param_1,"%s: pdata is NULL\n","wcd939x_suspend");
    return 0xffffffea;
  }
  if (((uint)plVar7[0x2f] >> 4 & 1) == 0) {
    cVar2 = (char)plVar7[0x27];
  }
  else {
    iVar4 = msm_cdc_disable_ondemand_supply
                      (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                       *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-buck");
    if (iVar4 == -0x16) {
      uVar5 = ___ratelimit(wcd939x_suspend__rs_413,"wcd939x_suspend");
      if ((int)uVar5 == 0) {
        return uVar5;
      }
      _dev_err(param_1,"%s: vdd buck is not disabled\n","wcd939x_suspend");
      return 0;
    }
    puVar1 = (ulong *)(plVar7 + 0x2f);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xffffffffffffffef;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    cVar2 = (char)plVar7[0x27];
  }
  if ((cVar2 != '\0') || ((plVar7[2] != 0 && (*(int *)(plVar7[2] + 0xd0) == 0)))) {
    msm_cdc_set_supplies_lpm_mode
              (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),*(undefined4 *)(lVar8 + 0x120),1
              );
    puVar1 = (ulong *)(plVar7 + 0x2f);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x100;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    uVar6 = msm_cdc_is_ondemand_supply
                      (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                       *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px");
    if ((((uVar6 & 1) != 0) &&
        (uVar6 = msm_cdc_supply_supports_retention_mode
                           (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                            *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px"), (uVar6 & 1) != 0)) &&
       (uVar6 = msm_cdc_check_supply_vote
                          (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                           *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px"), (uVar6 & 1) != 0)) {
      msm_cdc_disable_ondemand_supply
                (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),*(undefined4 *)(lVar8 + 0x120)
                 ,"cdc-vdd-px");
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_resume @ 0010a7e8 size=328
// signature: undefined wcd939x_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_resume(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  long lVar8;
  
  if (param_1 == 0) {
    uVar6 = 0xffffffed;
  }
  else {
    plVar7 = *(long **)(param_1 + 0x98);
    if (plVar7 != (long *)0x0) {
      lVar8 = *(long *)(*plVar7 + 0x90);
      if (lVar8 != 0) {
        uVar5 = msm_cdc_is_ondemand_supply
                          (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                           *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px");
        if ((((uVar5 & 1) != 0) &&
            (uVar5 = msm_cdc_supply_supports_retention_mode
                               (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                                *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px"), (uVar5 & 1) != 0)) &&
           (uVar5 = msm_cdc_check_supply_vote
                              (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                               *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px"), (uVar5 & 1) == 0)) {
          msm_cdc_enable_ondemand_supply
                    (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                     *(undefined4 *)(lVar8 + 0x120),"cdc-vdd-px");
        }
        if (((uint)plVar7[0x2f] >> 8 & 1) != 0) {
          msm_cdc_set_supplies_lpm_mode
                    (*plVar7,plVar7[0x185],*(undefined8 *)(lVar8 + 0x118),
                     *(undefined4 *)(lVar8 + 0x120),0);
          puVar1 = (ulong *)(plVar7 + 0x2f);
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
      iVar4 = ___ratelimit(wcd939x_resume__rs,"wcd939x_resume");
      if (iVar4 != 0) {
        _dev_err(param_1,"%s: pdata is NULL\n","wcd939x_resume");
      }
    }
    uVar6 = 0xffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// wcd939x_writeable_register @ 0010a940 size=48
// signature: undefined wcd939x_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd939x_writeable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x5a6 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10a970);
    (*pcVar2)();
  }
  return (byte)(&wcd939x_reg_access)[uVar1] >> 1 & 1;
}



//------------------------------------------------------------
// wcd939x_volatile_register @ 0010a974 size=56
// signature: undefined wcd939x_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wcd939x_volatile_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return false;
  }
  if (0x5a6 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10a9ac);
    (*pcVar2)();
  }
  return ((&wcd939x_reg_access)[uVar1] & 3) == 1;
}



//------------------------------------------------------------
// wcd939x_mbhc_get_impedance @ 0010a9b0 size=132
// signature: undefined wcd939x_mbhc_get_impedance(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_mbhc_get_impedance(long param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(&wcd939x_mbhc_get_impedance__rs,"wcd939x_mbhc_get_impedance");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011fbc3;
  }
  else {
    if ((param_2 != 0) && (param_3 != 0)) {
      uVar2 = wcd_mbhc_get_impedance();
      return uVar2;
    }
    iVar1 = ___ratelimit(wcd939x_mbhc_get_impedance__rs_1,"wcd939x_mbhc_get_impedance");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011e5a2;
  }
  _printk(puVar3,"wcd939x_mbhc_get_impedance");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd939x_mbhc_hs_detect @ 0010aa38 size=208
// signature: undefined wcd939x_mbhc_hs_detect(void)
// callers: [wcd939x_event_notify]
//------------------------------------------------------------

undefined8 wcd939x_mbhc_hs_detect(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  long lVar4;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd939x_mbhc_hs_detect__rs,"wcd939x_mbhc_hs_detect");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011f574;
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar4 != 0) {
      if (*(long *)(lVar4 + 0x100) != 0) {
        uVar2 = wcd_mbhc_start();
        return uVar2;
      }
      iVar1 = ___ratelimit(wcd939x_mbhc_hs_detect__rs_6,"wcd939x_mbhc_hs_detect");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: mbhc not initialized!\n",
               "wcd939x_mbhc_hs_detect");
      return 0xffffffea;
    }
    iVar1 = ___ratelimit(wcd939x_mbhc_hs_detect__rs_4,"wcd939x_mbhc_hs_detect");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar3 = &DAT_0011f300;
  }
  _printk(puVar3,"wcd939x_mbhc_hs_detect");
  return 0xffffffea;
}



//------------------------------------------------------------
// wcd939x_mbhc_hs_detect_exit @ 0010ab0c size=204
// signature: undefined wcd939x_mbhc_hs_detect_exit(void)
// callers: [wcd939x_mbhc_ssr_down]
//------------------------------------------------------------

void wcd939x_mbhc_hs_detect_exit(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(wcd939x_mbhc_hs_detect_exit__rs,"wcd939x_mbhc_hs_detect_exit");
    if (iVar1 == 0) {
      return;
    }
    puVar2 = &DAT_0011f574;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar3 != 0) {
      if (*(long *)(lVar3 + 0x100) != 0) {
        wcd_mbhc_stop();
        return;
      }
      iVar1 = ___ratelimit(wcd939x_mbhc_hs_detect_exit__rs_9,"wcd939x_mbhc_hs_detect_exit");
      if (iVar1 == 0) {
        return;
      }
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: mbhc not initialized!\n",
               "wcd939x_mbhc_hs_detect_exit");
      return;
    }
    iVar1 = ___ratelimit(wcd939x_mbhc_hs_detect_exit__rs_8,"wcd939x_mbhc_hs_detect_exit");
    if (iVar1 == 0) {
      return;
    }
    puVar2 = &DAT_0011f300;
  }
  _printk(puVar2,"wcd939x_mbhc_hs_detect_exit");
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_ssr_down @ 0010abdc size=60
// signature: undefined wcd939x_mbhc_ssr_down(void)
// callers: [wcd939x_event_notify]
//------------------------------------------------------------

void wcd939x_mbhc_ssr_down(long param_1,long param_2)

{
  if ((param_1 != 0) && (param_2 != 0)) {
    wcd939x_mbhc_hs_detect_exit(param_2);
    wcd_mbhc_deinit(param_1);
  }
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_post_ssr_init @ 0010ac1c size=160
// signature: undefined wcd939x_mbhc_post_ssr_init(void)
// callers: [wcd939x_event_notify]
//------------------------------------------------------------

int wcd939x_mbhc_post_ssr_init(long param_1,long param_2)

{
  int iVar1;
  
  iVar1 = -0x16;
  if ((param_1 != 0) && (param_2 != 0)) {
    snd_soc_component_update_bits(param_2,0x3014,0x20,0x20);
    iVar1 = wcd_mbhc_init(param_1,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
               "wcd939x_mbhc_post_ssr_init");
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd939x_mbhc_init @ 0010acc0 size=660
// signature: undefined wcd939x_mbhc_init(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wcd939x_mbhc_init(long *param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 *puVar4;
  long lVar5;
  char *pcVar6;
  undefined *puVar7;
  long *plVar8;
  
  if (param_2 == 0) {
    _printk(&DAT_0011f574,"wcd939x_mbhc_init");
    return -0x16;
  }
  lVar2 = devm_kmalloc(*(undefined8 *)(param_2 + 0x18),0x4b8,0xdc0);
  if (lVar2 == 0) {
    return -0xc;
  }
  *(undefined8 *)(lVar2 + 0x470) = param_3;
  __init_rwsem(lVar2 + 0x428,"&(&wcd939x_mbhc->notifier)->rwsem",&wcd939x_mbhc_init___key);
  *(undefined8 *)(lVar2 + 0x468) = 0;
  *(undefined4 *)(lVar2 + 0x3d4) = 1;
  init_timer_key(lVar2 + 0x478,rdown_timer_callback,0,0,0);
  lVar3 = *(long *)(param_2 + 0x18);
  *(undefined4 *)(lVar2 + 0x4b0) = 0;
  *(undefined1 *)(lVar2 + 0x4b4) = 0;
  if (*(long *)(lVar3 + 0x90) == 0) {
    pcVar6 = "%s: pdata pointer is NULL\n";
  }
  else {
    *(undefined4 *)(lVar2 + 0xd0) = *(undefined4 *)(*(long *)(lVar3 + 0x90) + 0x24);
    iVar1 = wcd_mbhc_init(lVar2,param_2,&mbhc_cb,intr_ids,&wcd_mbhc_registers,1);
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_2 + 0x18),"%s: mbhc initialization failed\n",
               "wcd939x_mbhc_init");
      goto LAB_0010aee4;
    }
    *param_1 = lVar2;
    snd_soc_add_component_controls(param_2,impedance_detect_controls,2);
    snd_soc_add_component_controls(param_2,hph_type_detect_controls,1);
    lVar3 = *(long *)(param_2 + 0x18);
    plVar8 = *(long **)(lVar3 + 0x98);
    if (plVar8 != (long *)0x0) {
      if (*plVar8 == 0) {
        _printk(&DAT_0011f03c,"usbcss_hs_sysfs_init");
      }
      else {
        lVar2 = kobject_create_and_add("usbcss_hs",_kernel_kobj);
        if (lVar2 == 0) {
          _dev_err(*plVar8,"%s: Could not create the USBC-SS HS kobj.\n","usbcss_hs_sysfs_init");
        }
        else {
          lVar3 = 0;
          do {
            puVar7 = (&usbcss_sysfs_files)[lVar3];
            puVar4 = (undefined8 *)devm_kmalloc(*plVar8,0x30,0xcc0);
            if ((puVar4 != (undefined8 *)0x0) &&
               (lVar5 = devm_kstrdup(*plVar8,puVar7,0xcc0), lVar5 != 0)) {
              *puVar4 = plVar8;
              *(int *)(puVar4 + 5) = (int)lVar3;
              puVar4[1] = lVar5;
              *(undefined2 *)(puVar4 + 2) = 0x1a4;
              puVar4[3] = usbcss_sysfs_show;
              puVar4[4] = usbcss_sysfs_store;
              sysfs_create_file_ns(lVar2,puVar4 + 1,0);
            }
            lVar3 = lVar3 + 1;
          } while (lVar3 != 0x14);
        }
      }
      return 0;
    }
    pcVar6 = "%s: wcd939x pointer is NULL\n";
  }
  _dev_err(lVar3,pcVar6,"wcd939x_mbhc_init");
  iVar1 = -0x16;
LAB_0010aee4:
  del_timer(lVar2 + 0x478);
  devm_kfree(*(undefined8 *)(param_2 + 0x18),lVar2);
  return iVar1;
}



//------------------------------------------------------------
// rdown_timer_callback @ 0010af58 size=12
// signature: undefined rdown_timer_callback(void)
// callers: []
//------------------------------------------------------------

void rdown_timer_callback(long param_1)

{
  *(undefined1 *)(param_1 + 0x3c) = 1;
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_deinit @ 0010af68 size=124
// signature: undefined wcd939x_mbhc_deinit(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_deinit(long param_1)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_0011f574;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      lVar2 = *(long *)(lVar2 + 0x100);
      if (lVar2 == 0) {
        return;
      }
      del_timer(lVar2 + 0x478);
      wcd_mbhc_deinit(lVar2);
      devm_kfree(*(undefined8 *)(param_1 + 0x18),lVar2);
      return;
    }
    puVar1 = &DAT_0011f300;
  }
  _printk(puVar1,"wcd939x_mbhc_deinit");
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_bcs_enable @ 0010afe8 size=40
// signature: undefined wcd939x_mbhc_bcs_enable(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_bcs_enable(long param_1,uint param_2)

{
  wcd939x_disable_bcs_before_slow_insert(*(undefined8 *)(param_1 + 0xf8),(param_2 ^ 0xffffffff) & 1)
  ;
  return;
}



//------------------------------------------------------------
// wcd939x_wcd_mbhc_calc_impedance @ 0010b014 size=3852
// signature: undefined wcd939x_wcd_mbhc_calc_impedance(void)
// callers: []
//------------------------------------------------------------

void wcd939x_wcd_mbhc_calc_impedance(long param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  code *pcVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  short sVar11;
  short sVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  ulong uVar17;
  undefined4 uVar18;
  int *piVar19;
  int *piVar20;
  int iVar21;
  int *piVar22;
  long lVar23;
  int iVar24;
  long *plVar25;
  long lVar26;
  long lVar27;
  uint uVar28;
  uint local_d8;
  uint uStack_d4;
  undefined8 local_d0;
  undefined4 local_c8;
  uint local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar26 = sp_el0;
  local_68 = *(long *)(lVar26 + 0x638);
  lVar26 = *(long *)(param_1 + 0xf8);
  local_70 = 0x6001e001e0000;
  local_c8 = 0xe8;
  local_c4 = 0;
  local_d8 = 0;
  uStack_d4 = 0;
  local_d0 = 0;
  plVar25 = *(long **)(*(long *)(lVar26 + 0x18) + 0x98);
  local_80 = 0x25;
  uStack_78 = 0x29;
  lVar27 = *(long *)(*plVar25 + 0x90);
  local_90 = 0x3d;
  uStack_88 = 0x43;
  local_b0 = 0x3d;
  uStack_a8 = 0x43;
  local_a0 = 0xe00000025;
  uStack_98 = 0xe00000029;
  local_c0 = 0x3d;
  uStack_b8 = 0x43;
  uVar17 = mutex_is_locked(param_1 + 0x328);
  if (((uVar17 & 1) == 0) && ((wcd939x_wcd_mbhc_calc_impedance___already_done & 1) == 0)) {
    wcd939x_wcd_mbhc_calc_impedance___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd939x_wcd_mbhc_calc_impedance");
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10bf18);
    (*pcVar7)();
  }
  if ((int)plVar25[0x18d] == 2) {
    regmap_update_bits_base(plVar25[4],0x3058,0x4e,0x4e,0,0,0);
    usleep_range_state(100,0x6e,2);
    regmap_update_bits_base(plVar25[4],0x3058,0x10,0x10,0,0,0);
    usleep_range_state(100,0x6e,2);
    regmap_update_bits_base(plVar25[4],0x3058,1,1,0,0,0);
    regmap_update_bits_base(plVar25[4],0x3058,0x20,0x20,0,0,0);
    usleep_range_state(500,0x1fe,2);
  }
  wcd_usbss_register_update(&local_90,0,4);
  wcd_usbss_register_update(&local_b0,1,4);
  sVar8 = snd_soc_component_read(lVar26,0x301f);
  sVar9 = snd_soc_component_read(lVar26,0x3020);
  sVar10 = snd_soc_component_read(lVar26,0x3021);
  sVar11 = snd_soc_component_read(lVar26,0x3056);
  sVar12 = snd_soc_component_read(lVar26,0x3123);
  uVar13 = snd_soc_component_read(lVar26,0x3015);
  if ((uVar13 >> 7 & 1) != 0) {
    regmap_update_bits_base(plVar25[4],0x3015,0x80,0,0,0,0);
  }
  if (*(char *)(param_1 + 0xc3) != '\0') {
    regmap_update_bits_base(plVar25[4],0x3014,0x80,0,0,0,0);
  }
  regmap_update_bits_base(plVar25[4],0x3014,1,0,0,0,0);
  regmap_update_bits_base(plVar25[4],0x30e2,0xc0,0,0,0,0);
  usleep_range_state(1000,0x3f2,2);
  if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) {
    wcd_usbss_set_switch_settings_enable(2,0);
    wcd_usbss_set_switch_settings_enable(1,0);
  }
  wcd939x_mbhc_zdet_ramp(lVar26,&DAT_0011a2c8,(long)&local_d0 + 4,0,&local_70);
  if ((int)local_d0._4_4_ < 0x5f5e101) {
    *param_2 = local_d0._4_4_;
    uVar16 = snd_soc_component_read(lVar26,0x34c5);
    if ((uVar16 >> 7 & 1) == 0) {
      if (-0x3e80000 < (int)(uVar16 * 0x10000)) {
        iVar15 = ((int)(short)uVar16 + (short)uVar16 * 4) * 2;
        goto LAB_0010b354;
      }
    }
    else {
      iVar15 = (uVar16 & 0x7f) * -10;
LAB_0010b354:
      uVar14 = *param_2;
      uVar16 = iVar15 + 10000;
      if ((int)uVar14 < 200000) {
        uVar28 = 0;
        if (uVar16 != 0) {
          uVar28 = (int)(uVar14 * 10000) / (int)uVar16;
        }
      }
      else if (uVar14 < 2000000) {
        uVar28 = 0;
        if (uVar16 != 0) {
          uVar28 = (uVar14 * 1000) / uVar16;
        }
        uVar28 = uVar28 * 10;
      }
      else {
        if (19999999 < uVar14) goto LAB_0010b3c0;
        uVar28 = 0;
        if (uVar16 != 0) {
          uVar28 = (uVar14 * 100) / uVar16;
        }
        uVar28 = uVar28 * 100;
      }
      *param_2 = uVar28;
    }
LAB_0010b3c0:
    apply_zdet_correction(param_2,0,*(undefined4 *)(lVar27 + 0x110),*(undefined4 *)(lVar27 + 0x10c))
    ;
    uVar16 = *param_2;
  }
  else {
    uVar16 = 0xffffffe;
    *param_2 = 0xffffffe;
  }
  *(uint *)(lVar27 + 0x50) = uVar16;
  wcd939x_mbhc_zdet_ramp(lVar26,&DAT_0011a2c8,0,&local_d0,&local_70);
  if ((int)(uint)local_d0 < 0x5f5e101) {
    *param_3 = (uint)local_d0;
    uVar16 = snd_soc_component_read(lVar26,0x34c9);
    if ((uVar16 >> 7 & 1) == 0) {
      if (-0x3e80000 < (int)(uVar16 * 0x10000)) {
        iVar15 = ((int)(short)uVar16 + (short)uVar16 * 4) * 2;
        goto LAB_0010b44c;
      }
    }
    else {
      iVar15 = (uVar16 & 0x7f) * -10;
LAB_0010b44c:
      uVar14 = *param_3;
      uVar16 = iVar15 + 10000;
      if ((int)uVar14 < 200000) {
        uVar28 = 0;
        if (uVar16 != 0) {
          uVar28 = (int)(uVar14 * 10000) / (int)uVar16;
        }
      }
      else if (uVar14 < 2000000) {
        uVar28 = 0;
        if (uVar16 != 0) {
          uVar28 = (uVar14 * 1000) / uVar16;
        }
        uVar28 = uVar28 * 10;
      }
      else {
        if (19999999 < uVar14) goto LAB_0010b4b8;
        uVar28 = 0;
        if (uVar16 != 0) {
          uVar28 = (uVar14 * 100) / uVar16;
        }
        uVar28 = uVar28 * 100;
      }
      *param_3 = uVar28;
    }
LAB_0010b4b8:
    apply_zdet_correction(param_3,0,*(undefined4 *)(lVar27 + 0x110),*(undefined4 *)(lVar27 + 0x10c))
    ;
    uVar16 = *param_3;
  }
  else {
    uVar16 = 0xffffffe;
    *param_3 = 0xffffffe;
  }
  *(uint *)(lVar27 + 0x6c) = uVar16;
  if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) == 0) {
    *param_2 = (*param_2 + 500) / 1000;
    *param_3 = (*param_3 + 500) / 1000;
LAB_0010ba48:
    uVar16 = *param_2;
    uVar14 = *param_3;
    if (uVar16 == 0xffffffe) {
      if (uVar14 != 0xffffffe) goto LAB_0010bcc4;
    }
    else {
      if (((uVar14 == 0xffffffe) || ((uVar16 < 2 && (2 < uVar14)))) ||
         ((2 < uVar16 && (uVar14 < 2)))) {
LAB_0010bcc4:
        uVar18 = 1;
      }
      else {
        snd_soc_component_update_bits(lVar26,0x30d8,2,2);
        snd_soc_component_update_bits(lVar26,0x30d2,0x40,1);
        wcd939x_mbhc_zdet_ramp(lVar26,&DAT_0011a2c8,&uStack_d4,0,&local_70);
        snd_soc_component_update_bits(lVar26,0x30d2,0x40,0);
        snd_soc_component_update_bits(lVar26,0x30d8,2,0);
        uStack_d4 = (int)uStack_d4 / 1000;
        uVar16 = snd_soc_component_read(lVar26,0x34c5);
        if ((uVar16 >> 7 & 1) == 0) {
          if (-0x3e80000 < (int)(uVar16 * 0x10000)) {
            iVar15 = ((int)(short)uVar16 + (short)uVar16 * 4) * 2;
            goto LAB_0010bc08;
          }
        }
        else {
          iVar15 = (uVar16 & 0x7f) * -10;
LAB_0010bc08:
          uVar16 = iVar15 + 10000;
          if ((int)uStack_d4 < 200000) {
            iVar15 = uStack_d4 * 10000;
            uStack_d4 = 0;
            if (uVar16 != 0) {
              uStack_d4 = iVar15 / (int)uVar16;
            }
          }
          else if (uStack_d4 < 2000000) {
            uVar14 = 0;
            if (uVar16 != 0) {
              uVar14 = (uStack_d4 * 1000) / uVar16;
            }
            uStack_d4 = uVar14 * 10;
          }
          else if (uStack_d4 < 20000000) {
            uVar14 = 0;
            if (uVar16 != 0) {
              uVar14 = (uStack_d4 * 100) / uVar16;
            }
            uStack_d4 = uVar14 * 100;
          }
        }
        uVar16 = *param_2;
        uVar14 = 0;
        if (uVar16 + 9 != 0) {
          uVar14 = (uVar16 * 9) / (uVar16 + 9);
        }
        iVar15 = uStack_d4 - uVar14;
        if (uStack_d4 - uVar14 == 0 || (int)uStack_d4 < (int)uVar14) {
          iVar15 = uVar14 - uStack_d4;
        }
        iVar3 = uVar16 - uStack_d4;
        if (uVar16 < uStack_d4 || uVar16 - uStack_d4 == 0) {
          iVar3 = uStack_d4 - uVar16;
        }
        if (iVar15 * (uStack_d4 + uVar16) <= iVar3 * (uStack_d4 + uVar14)) goto LAB_0010bcc4;
        uVar18 = 2;
      }
      *(undefined4 *)(param_1 + 0x1c4) = uVar18;
    }
  }
  else {
    wcd_usbss_set_switch_settings_enable(0,0);
    uVar14 = 1;
    wcd_usbss_register_update(&local_c0,1,2);
    regmap_update_bits_base(plVar25[4],0x30e3,8,8,0,0,0);
    usleep_range_state(3000,0xbc2,2);
    wcd939x_mbhc_zdet_ramp(lVar26,&DAT_0011a2c8,&local_d8,0,&local_70);
    uVar16 = local_d8;
    if ((int)local_d8 < 0x5f5e101) {
      local_c4 = local_d8;
      uVar14 = snd_soc_component_read(lVar26,0x34c5);
      if ((uVar14 >> 7 & 1) == 0) {
        if (-0x3e80000 < (int)(uVar14 * 0x10000)) {
          iVar15 = ((int)(short)uVar14 + (short)uVar14 * 4) * 2;
          goto LAB_0010b5e8;
        }
      }
      else {
        iVar15 = (uVar14 & 0x7f) * -10;
LAB_0010b5e8:
        uVar14 = iVar15 + 10000;
        if ((int)uVar16 < 200000) {
          local_c4 = 0;
          if (uVar14 != 0) {
            local_c4 = (int)(uVar16 * 10000) / (int)uVar14;
          }
        }
        else if (uVar16 < 2000000) {
          local_c4 = 0;
          if (uVar14 != 0) {
            local_c4 = (uVar16 * 1000) / uVar14;
          }
          local_c4 = local_c4 * 10;
        }
        else if (uVar16 < 20000000) {
          local_c4 = 0;
          if (uVar14 != 0) {
            local_c4 = (uVar16 * 100) / uVar14;
          }
          local_c4 = local_c4 * 100;
        }
      }
      apply_zdet_correction
                (&local_c4,1,*(undefined4 *)(lVar27 + 0x110),*(undefined4 *)(lVar27 + 0x10c));
      uVar14 = 2;
      uVar28 = local_c4;
    }
    else {
      uVar28 = 0;
    }
    wcd939x_mbhc_zdet_ramp(lVar26,&DAT_0011a2c8,&local_d8,0,&local_70);
    uVar4 = local_d8;
    if ((int)local_d8 < 0x5f5e101) {
      local_c4 = local_d8;
      uVar16 = snd_soc_component_read(lVar26,0x34c5);
      if ((uVar16 >> 7 & 1) == 0) {
        if (-0x3e80000 < (int)(uVar16 * 0x10000)) {
          iVar15 = ((int)(short)uVar16 + (short)uVar16 * 4) * 2;
          goto LAB_0010b6fc;
        }
      }
      else {
        iVar15 = (uVar16 & 0x7f) * -10;
LAB_0010b6fc:
        uVar16 = iVar15 + 10000;
        if ((int)uVar4 < 200000) {
          local_c4 = 0;
          if (uVar16 != 0) {
            local_c4 = (int)(uVar4 * 10000) / (int)uVar16;
          }
        }
        else if (uVar4 < 2000000) {
          local_c4 = 0;
          if (uVar16 != 0) {
            local_c4 = (uVar4 * 1000) / uVar16;
          }
          local_c4 = local_c4 * 10;
        }
        else if (uVar4 < 20000000) {
          local_c4 = 0;
          if (uVar16 != 0) {
            local_c4 = (uVar4 * 100) / uVar16;
          }
          local_c4 = local_c4 * 100;
        }
      }
      apply_zdet_correction
                (&local_c4,1,*(undefined4 *)(lVar27 + 0x110),*(undefined4 *)(lVar27 + 0x10c));
      uVar28 = local_c4 + uVar28;
LAB_0010b780:
      uVar16 = 0;
      if (uVar14 != 0) {
        uVar16 = uVar28 / uVar14;
      }
    }
    else {
      if ((int)uVar16 < 0x5f5e101) {
        uVar14 = 1;
        goto LAB_0010b780;
      }
      uVar16 = 0xffffffe;
    }
    *(uint *)(lVar27 + 0x108) = uVar16;
    local_c4 = uVar16;
    regmap_update_bits_base(plVar25[4],0x30e3,8,0,0,0,0);
    wcd_usbss_set_switch_settings_enable(0,1);
    iVar15 = wcd_usbss_get_sbu_switch_orientation();
    if (iVar15 == 2) {
      piVar20 = (int *)(lVar27 + 0xa4);
      piVar19 = (int *)(lVar27 + 0xa8);
      piVar22 = (int *)(lVar27 + 0xb0);
LAB_0010b7fc:
      iVar15 = *piVar22;
      iVar3 = *piVar20;
      if ((*(uint *)(lVar27 + 0x50) < 0x186a1) && (*(uint *)(lVar27 + 0x6c) < 0x186a1)) {
        iVar21 = iVar3 + *piVar19;
        lVar23 = *(long *)(*plVar25 + 0x90);
        uVar14 = *(uint *)(lVar23 + 0xfc);
        uVar28 = (uint)(*(int *)(lVar23 + 0xcc) + *(int *)(lVar23 + 200) +
                       *(int *)(lVar23 + 0xd0) + *(int *)(lVar23 + 0xd4)) >> 2;
        uVar16 = (((*param_2 - uVar16) + *param_3 + *(int *)(lVar27 + 0x70) >> 1) -
                 *(int *)(lVar27 + 0xe8)) - iVar21;
        if (uVar28 + uVar14 < uVar16) {
LAB_0010b8d0:
          *(uint *)(lVar23 + 0xf4) = uVar28;
        }
        else {
          uVar17 = *(ulong *)(lVar23 + 0xd8);
          if ((uVar14 <= uVar28) && (uVar16 < uVar28 - uVar14)) goto LAB_0010b8d0;
          *(uint *)(lVar23 + 0xf4) = uVar16;
          if (3 < uVar17) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10bf24);
            (*pcVar7)();
          }
          ((int *)(lVar23 + 200))[uVar17] = uVar16;
          *(ulong *)(lVar23 + 0xd8) = (ulong)((int)uVar17 + 1) & 3;
        }
        iVar24 = *(int *)(lVar27 + 0xf4);
        bVar6 = true;
        iVar21 = iVar21 + iVar24;
      }
      else {
        bVar6 = false;
        iVar24 = *(int *)(lVar27 + 0xe0) + iVar15;
        iVar21 = iVar24 + iVar3;
        iVar24 = iVar24 - *piVar19;
      }
      uVar28 = (iVar21 - iVar3) - iVar15;
      uVar16 = *(int *)(lVar27 + 0xe8) + uVar28;
      *(int *)(lVar27 + 0xf4) = iVar24 + *(int *)(lVar27 + 0xf8);
      uVar4 = *param_3 - (uVar16 + iVar21 + *(int *)(lVar27 + 0x54));
      uVar14 = uVar4;
      if (uVar4 == 0) {
        uVar14 = 1;
      }
      uVar5 = *param_2 - (uVar16 + iVar21 + *(int *)(lVar27 + 0x38));
      *param_2 = ((uVar5 - *(int *)(lVar27 + 0x4c)) - 0x1ce3) / 1000;
      uVar2 = uVar5;
      if (uVar5 == 0) {
        uVar2 = 1;
      }
      uVar1 = 900000;
      if (uVar5 < 0xdbba1) {
        uVar1 = uVar2;
      }
      uVar2 = 900000;
      if (uVar4 < 0xdbba1) {
        uVar2 = uVar14;
      }
      *param_3 = ((uVar4 - *(int *)(lVar27 + 0x68)) - 0x1ce3) / 1000;
      *(uint *)(lVar27 + 0x44) = uVar1;
      *(uint *)(lVar27 + 0x60) = uVar2;
      if (lVar27 != 0) {
        uVar14 = uVar28;
        if (19999 < uVar28) {
          uVar14 = 20000;
        }
        if (19999 < uVar16) {
          uVar16 = 20000;
        }
        *(uint *)(lVar27 + 0xf0) = uVar14;
        *(uint *)(lVar27 + 0x90) = *(int *)(lVar27 + 0x80) + *(int *)(lVar27 + 0x8c) + uVar14;
        *(uint *)(lVar27 + 0xb4) = *(int *)(lVar27 + 0xa4) + *(int *)(lVar27 + 0xb0) + uVar14;
        *(uint *)(lVar27 + 0x3c) = uVar16;
        *(uint *)(lVar27 + 0x40) = uVar1 + uVar16 + *(int *)(lVar27 + 0x38);
        *(uint *)(lVar27 + 0x58) = uVar16;
        *(uint *)(lVar27 + 0x5c) = uVar2 + uVar16 + *(int *)(lVar27 + 0x54);
      }
      if ((*(uint *)(lVar27 + 0x50) < 0x927c1) && (*(uint *)(lVar27 + 0x6c) < 0x927c1)) {
        update_xtalk_scale_and_alpha(plVar25);
        if (bVar6) {
          uVar14 = *(uint *)(lVar27 + 0xec);
          uVar16 = uVar28;
          if (uVar28 <= uVar14) {
            uVar16 = uVar14;
          }
          if ((lVar27 != 0) && (uVar28 < uVar14 || 2000 < uVar16)) {
            if (1999 < uVar16) {
              uVar16 = 2000;
            }
            *(uint *)(lVar27 + 0xf0) = uVar16;
            uVar14 = *(int *)(lVar27 + 0xe8) + uVar16;
            if (19999 < uVar14) {
              uVar14 = 20000;
            }
            *(uint *)(lVar27 + 0x90) = *(int *)(lVar27 + 0x80) + *(int *)(lVar27 + 0x8c) + uVar16;
            *(uint *)(lVar27 + 0xb4) = *(int *)(lVar27 + 0xa4) + *(int *)(lVar27 + 0xb0) + uVar16;
            *(uint *)(lVar27 + 0x3c) = uVar14;
            *(uint *)(lVar27 + 0x40) = *(int *)(lVar27 + 0x38) + *(int *)(lVar27 + 0x44) + uVar14;
            *(uint *)(lVar27 + 0x58) = uVar14;
            *(uint *)(lVar27 + 0x5c) = *(int *)(lVar27 + 0x54) + *(int *)(lVar27 + 0x60) + uVar14;
          }
          get_linearizer_taps(lVar27,&local_c8);
        }
      }
      else {
        *(undefined4 *)(lVar27 + 0x100) = 0x1f001f;
      }
      *(int *)(lVar27 + 0xf4) = *(int *)(lVar27 + 0xf4) - *(int *)(lVar27 + 0xf8);
      goto LAB_0010ba48;
    }
    iVar15 = wcd_usbss_get_sbu_switch_orientation();
    if (iVar15 == 1) {
      piVar20 = (int *)(lVar27 + 0x80);
      piVar19 = (int *)(lVar27 + 0x84);
      piVar22 = (int *)(lVar27 + 0x8c);
      goto LAB_0010b7fc;
    }
    *param_2 = 0;
    *param_3 = 0;
    *(undefined4 *)(lVar27 + 0x100) = 0x1f001f;
  }
  wcd_usbss_set_linearizer_sw_tap(local_c8,0xe8);
  if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) {
    wcd_usbss_set_switch_settings_enable(2,1);
    wcd_usbss_set_switch_settings_enable(1,1);
    if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) goto LAB_0010bd28;
  }
  regmap_update_bits_base(plVar25[4],0x30e2,0xc0,0xc0,0,0,0);
LAB_0010bd28:
  snd_soc_component_write(lVar26,0x301f,(int)sVar8);
  snd_soc_component_write(lVar26,0x3020,(int)sVar9);
  snd_soc_component_write(lVar26,0x3021,(int)sVar10);
  regmap_update_bits_base(plVar25[4],0x3014,1,1,0,0,0);
  if (*(char *)(param_1 + 0xc3) != '\0') {
    regmap_update_bits_base(plVar25[4],0x3014,0x80,0x80,0,0,0);
  }
  snd_soc_component_write(lVar26,0x3123,(int)sVar12);
  snd_soc_component_write(lVar26,0x3056,(int)sVar11);
  if ((uVar13 >> 7 & 1) != 0) {
    regmap_update_bits_base(plVar25[4],0x3015,0x80,0x80,0,0,0);
  }
  wcd_usbss_register_update(&local_90,1,4);
  if ((int)plVar25[0x18d] == 2) {
    regmap_update_bits_base(plVar25[4],0x3058,0x20,0,0,0,0);
    usleep_range_state(500,0x1fe,2);
    regmap_update_bits_base(plVar25[4],0x3058,0x11,0,0,0,0);
    usleep_range_state(100,0x6e,2);
    regmap_update_bits_base(plVar25[4],0x3058,6,0,0,0,0);
    usleep_range_state(100,0x6e,2);
    regmap_update_bits_base(plVar25[4],0x3058,0x48,0,0,0,0);
  }
  lVar26 = sp_el0;
  if (*(long *)(lVar26 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd939x_get_hwdep_fw_cal @ 0010bf28 size=164
// signature: undefined wcd939x_get_hwdep_fw_cal(void)
// callers: []
//------------------------------------------------------------

long wcd939x_get_hwdep_fw_cal(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xf8);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(wcd939x_get_hwdep_fw_cal__rs,"wcd939x_get_hwdep_fw_cal");
    if (iVar1 != 0) {
      _printk(&DAT_0011e729,"wcd939x_get_hwdep_fw_cal");
    }
  }
  else {
    lVar2 = wcdcal_get_fw_cal(*(undefined8 *)(param_1 + 0x470));
    if (lVar2 != 0) {
      return lVar2;
    }
    iVar1 = ___ratelimit(wcd939x_get_hwdep_fw_cal__rs_18,"wcd939x_get_hwdep_fw_cal");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(lVar3 + 0x18),"%s: cal not sent by %d\n","wcd939x_get_hwdep_fw_cal",
               param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// wcd939x_mbhc_register_notifier @ 0010bfd0 size=44
// signature: undefined wcd939x_mbhc_register_notifier(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_register_notifier(long param_1,undefined8 param_2,uint param_3)

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
// wcd939x_mbhc_request_irq @ 0010c000 size=52
// signature: undefined wcd939x_mbhc_request_irq(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_request_irq(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  wcd_request_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x148,param_2,param_4,param_3);
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_irq_control @ 0010c038 size=52
// signature: undefined wcd939x_mbhc_irq_control(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_irq_control(long param_1,undefined8 param_2,uint param_3)

{
  if ((param_3 & 1) == 0) {
    wcd_disable_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x148);
  }
  else {
    wcd_enable_irq();
  }
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_free_irq @ 0010c070 size=44
// signature: undefined wcd939x_mbhc_free_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_mbhc_free_irq(long param_1)

{
  wcd_free_irq(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x148);
  return 0;
}



//------------------------------------------------------------
// wcd939x_mbhc_clk_setup @ 0010c0a0 size=48
// signature: undefined wcd939x_mbhc_clk_setup(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_clk_setup(undefined8 param_1,ulong param_2)

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
// wcd939x_mbhc_btn_to_num @ 0010c0d4 size=36
// signature: undefined wcd939x_mbhc_btn_to_num(void)
// callers: []
//------------------------------------------------------------

uint wcd939x_mbhc_btn_to_num(undefined8 param_1)

{
  uint uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x3019);
  return uVar1 & 7;
}



//------------------------------------------------------------
// wcd939x_mbhc_lock_sleep @ 0010c0fc size=72
// signature: undefined wcd939x_mbhc_lock_sleep(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_mbhc_lock_sleep(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98) + 0xc60);
  if (*(int *)(pcVar1 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c130);
    (*pcVar1)();
  }
  (*pcVar1)();
  return 1;
}



//------------------------------------------------------------
// wcd939x_mbhc_micb_en_status @ 0010c148 size=68
// signature: undefined wcd939x_mbhc_micb_en_status(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_mbhc_micb_en_status(long param_1,int param_2)

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
// wcd939x_mbhc_mbhc_bias_control @ 0010c190 size=40
// signature: undefined wcd939x_mbhc_mbhc_bias_control(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_mbhc_bias_control(undefined8 param_1,uint param_2)

{
  snd_soc_component_update_bits(param_1,0x3015,1,param_2 & 1);
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_hph_pa_on_status @ 0010c1bc size=40
// signature: undefined wcd939x_mbhc_hph_pa_on_status(void)
// callers: []
//------------------------------------------------------------

bool wcd939x_mbhc_hph_pa_on_status(undefined8 param_1)

{
  ulong uVar1;
  
  uVar1 = snd_soc_component_read(param_1,0x3009);
  return (uVar1 & 0xc0) != 0;
}



//------------------------------------------------------------
// wcd939x_mbhc_program_btn_thr @ 0010c1e8 size=540
// signature: undefined wcd939x_mbhc_program_btn_thr(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_program_btn_thr(long param_1,undefined8 param_2,short *param_3,int param_4)

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
    iVar1 = ___ratelimit(wcd939x_mbhc_program_btn_thr__rs,"wcd939x_mbhc_program_btn_thr");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid number of buttons: %d\n",
               "wcd939x_mbhc_program_btn_thr",param_4);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_request_micbias @ 0010c408 size=32
// signature: undefined wcd939x_mbhc_request_micbias(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_request_micbias(void)

{
  wcd939x_micbias_control();
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_micb_ramp_control @ 0010c42c size=112
// signature: undefined wcd939x_mbhc_micb_ramp_control(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_micb_ramp_control(undefined8 param_1,ulong param_2)

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
// wcd939x_mbhc_micb_ctrl_threshold_mic @ 0010c4a0 size=88
// signature: undefined wcd939x_mbhc_micb_ctrl_threshold_mic(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_mbhc_micb_ctrl_threshold_mic(long param_1,int param_2,ulong param_3)

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
      uVar3 = wcd939x_mbhc_micb_adjust_voltage(param_1,uVar1,2);
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
// wcd939x_mbhc_gnd_det_ctrl @ 0010c4fc size=112
// signature: undefined wcd939x_mbhc_gnd_det_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_gnd_det_ctrl(undefined8 param_1,ulong param_2)

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
// wcd939x_mbhc_hph_pull_down_ctrl @ 0010c570 size=88
// signature: undefined wcd939x_mbhc_hph_pull_down_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_hph_pull_down_ctrl(undefined8 param_1,ulong param_2)

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
// wcd939x_mbhc_moisture_config @ 0010c5cc size=88
// signature: undefined wcd939x_mbhc_moisture_config(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_moisture_config(long param_1)

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
// wcd939x_mbhc_hph_l_pull_up_control @ 0010c628 size=48
// signature: undefined wcd939x_mbhc_hph_l_pull_up_control(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_hph_l_pull_up_control(undefined8 param_1,uint param_2)

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
// wcd939x_mbhc_get_moisture_status @ 0010c65c size=160
// signature: undefined wcd939x_mbhc_get_moisture_status(void)
// callers: []
//------------------------------------------------------------

bool wcd939x_mbhc_get_moisture_status(long param_1)

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
// wcd939x_mbhc_moisture_polling_ctrl @ 0010c700 size=52
// signature: undefined wcd939x_mbhc_moisture_polling_ctrl(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_moisture_polling_ctrl(long param_1,ulong param_2)

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
// wcd939x_mbhc_moisture_detect_en @ 0010c738 size=64
// signature: undefined wcd939x_mbhc_moisture_detect_en(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_moisture_detect_en(long param_1,ulong param_2)

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
// wcd939x_surge_reset_routine @ 0010c77c size=60
// signature: undefined wcd939x_surge_reset_routine(void)
// callers: []
//------------------------------------------------------------

void wcd939x_surge_reset_routine(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x18) + 0x98);
  regcache_mark_dirty(*(undefined8 *)(lVar1 + 0x20));
  regcache_sync(*(undefined8 *)(lVar1 + 0x20));
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_zdet_leakage_resistance @ 0010c7bc size=52
// signature: undefined wcd939x_mbhc_zdet_leakage_resistance(void)
// callers: []
//------------------------------------------------------------

void wcd939x_mbhc_zdet_leakage_resistance(long param_1,ulong param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x80;
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
  }
  snd_soc_component_update_bits(*(undefined8 *)(param_1 + 0xf8),0x3059,0x80,uVar1);
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_zdet_ramp @ 0010c7f0 size=460
// signature: undefined wcd939x_mbhc_zdet_ramp(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

void wcd939x_mbhc_zdet_ramp
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
  snd_soc_component_update_bits(param_1,0x3123,0xf0,(uint)*param_2 << 4 | 0x80);
  snd_soc_component_update_bits(param_1,0x301f,0xfc,param_2[3]);
  snd_soc_component_update_bits(param_1,0x3020,0xfc,param_2[4]);
  snd_soc_component_update_bits(param_1,0x3021,0xfc,param_2[5]);
  snd_soc_component_update_bits(param_1,0x3123,0xf,param_2[1]);
  snd_soc_component_update_bits(param_1,0x3124,0xf,param_2[2]);
  snd_soc_component_update_bits(param_1,0x3124,0x70,0x60);
  if (param_3 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x80,0x80,0,0,0);
    wcd939x_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_4c);
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x80,0,0,0,0);
    *param_3 = local_4c;
  }
  if (param_4 != (undefined4 *)0x0) {
    regmap_update_bits_base(*(undefined8 *)(lVar1 + 0x20),0x3016,0x40,0x40,0,0,0);
    wcd939x_mbhc_get_result_params(lVar1,param_5,param_2[1],&local_4c);
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
// apply_zdet_correction @ 0010c9bc size=336
// signature: undefined apply_zdet_correction(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

void apply_zdet_correction(uint *param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  code *pcVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  uint uVar12;
  
  if (param_2 != 0) {
    param_3 = param_4;
  }
  iVar11 = 1;
  iVar9 = -10000;
  if (param_2 != 0) {
    iVar9 = -20000;
  }
  uVar1 = *param_1 + iVar9;
  uVar6 = ((ulong)*param_1 * (ulong)param_3 * 0x10000) / 0x27100000;
  uVar8 = 10;
  while ((uint)(byte)(&UNK_0011a2d0)[uVar8] * 1000 <= uVar1) {
    uVar8 = uVar8 + 6;
    iVar11 = iVar11 + 1;
    if (uVar8 == 0xb8) {
      uVar12 = 0x1d;
LAB_0010ca48:
      if (uVar12 != 0x1d) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10cb08);
        (*pcVar5)();
      }
      lVar7 = -0x37;
      if (param_2 != 0) {
        lVar7 = 0x33;
      }
      if (lVar7 < (long)uVar6) {
LAB_0010ca68:
        *param_1 = (int)uVar6 - (int)lVar7;
      }
      return;
    }
  }
  uVar12 = iVar11 - 1;
  if (iVar11 < 1) {
    return;
  }
  if (0x1c < uVar12) goto LAB_0010ca48;
  uVar2 = uVar8 - 8;
  puVar3 = &UNK_0011a2d2;
  if (param_2 != 0) {
    uVar2 = uVar8 - 6;
    puVar3 = zdet_dnl_table;
  }
  if (uVar2 < 0xb4) {
    uVar2 = uVar8 - 2;
    if (param_2 != 0) {
      uVar2 = uVar8;
    }
    if (uVar2 < 0xb4) {
      puVar4 = &UNK_0011a2cc;
      if (param_2 != 0) {
        puVar4 = &UNK_0011a2ce;
      }
      lVar10 = (long)(int)((uint)(byte)(&UNK_0011a2d0)[uVar8] - (uint)(byte)(&UNK_0011a2ca)[uVar8])
               * 1000;
      lVar7 = 0;
      if (lVar10 != 0) {
        lVar7 = (long)(((ulong)(byte)(&UNK_0011a2d0)[uVar8] * 1000 - (ulong)uVar1) *
                       (long)*(short *)(puVar4 + uVar8) +
                      ((ulong)uVar1 + (long)(int)(uint)(byte)(&UNK_0011a2ca)[uVar8] * -1000) *
                      (long)*(short *)(puVar3 + uVar8)) / lVar10;
      }
      if ((long)uVar6 <= lVar7) {
        return;
      }
      goto LAB_0010ca68;
    }
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(1,0x10cb0c);
  (*pcVar5)();
}



//------------------------------------------------------------
// update_xtalk_scale_and_alpha @ 0010cb0c size=572
// signature: undefined update_xtalk_scale_and_alpha(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance, usbcss_sysfs_store]
//------------------------------------------------------------

void update_xtalk_scale_and_alpha(long *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  undefined1 uVar9;
  int *piVar10;
  long lVar11;
  long lVar12;
  
  lVar12 = *(long *)(*param_1 + 0x90);
  if ((lVar12 != 0) && (*(int *)(lVar12 + 0x104) != 0)) {
    *(undefined4 *)(lVar12 + 0x100) = 0x1f001f;
    iVar5 = wcd_usbss_get_sbu_switch_orientation();
    if (iVar5 == 2) {
      piVar8 = (int *)(lVar12 + 0xa4);
      puVar6 = (uint *)(lVar12 + 0xb4);
      piVar10 = (int *)(lVar12 + 0xa8);
    }
    else {
      iVar5 = wcd_usbss_get_sbu_switch_orientation();
      if (iVar5 != 1) {
        return;
      }
      piVar8 = (int *)(lVar12 + 0x80);
      puVar6 = (uint *)(lVar12 + 0x90);
      piVar10 = (int *)(lVar12 + 0x84);
    }
    iVar5 = *piVar10;
    iVar2 = *piVar8;
    if ((*(int *)(lVar12 + 0x104) == 2) && (lVar11 = param_1[4], lVar11 != 0)) {
      uVar7 = *puVar6 + ((uint)(*(int *)(lVar12 + 0x60) + *(int *)(lVar12 + 0x44)) >> 1);
      uVar4 = 0;
      if ((ulong)uVar7 != 0) {
        uVar4 = ((ulong)(uVar7 >> 1) * 0x10000 + (ulong)*puVar6 * 0x401a41) / ((ulong)uVar7 << 0x10)
        ;
      }
      iVar1 = 0;
      if (uVar4 < 0x1d) {
        iVar1 = 0x1d - (int)uVar4;
      }
      regmap_update_bits_base(lVar11,0x3140,0x1f,iVar1,0,0,0);
      regmap_update_bits_base(lVar11,0x3141,0x1f,iVar1,0,0,0);
    }
    uVar7 = (*(int *)(lVar12 + 0x50) - (iVar2 + iVar5)) + *(int *)(lVar12 + 0x48);
    if (uVar7 != 0) {
      iVar1 = 0;
      if ((ulong)uVar7 != 0) {
        iVar1 = (int)(((ulong)*(uint *)(lVar12 + 0xf4) << 0x10) / (ulong)uVar7);
      }
      if (iVar1 == 0) {
        *(undefined1 *)(lVar12 + 0x100) = 0x1f;
        uVar9 = 0;
      }
      else {
        uVar7 = 0;
        iVar3 = 0;
        if ((long)iVar1 != 0) {
          iVar3 = (int)(0x10000 / (ulong)(long)iVar1);
        }
        do {
          if ((-1 << (ulong)(uVar7 & 0x1f)) + iVar3 < 0) goto LAB_0010cc6c;
          uVar7 = uVar7 + 1;
        } while (uVar7 != 0x20);
        uVar7 = 0x1f;
LAB_0010cc6c:
        *(char *)(lVar12 + 0x100) = (char)uVar7;
        uVar4 = (ulong)(uint)(iVar1 << (ulong)(uVar7 & 0x1f)) * 0xff + 0xffffff018000;
        uVar9 = (undefined1)(uVar4 >> 0x10);
        if ((uVar4 & 0xffffff000000) != 0) {
          uVar9 = 0xff;
        }
      }
      *(undefined1 *)(lVar12 + 0x101) = uVar9;
    }
    uVar7 = (*(int *)(lVar12 + 0x6c) - (iVar2 + iVar5)) + *(int *)(lVar12 + 100);
    if (uVar7 != 0) {
      iVar5 = 0;
      if ((ulong)uVar7 != 0) {
        iVar5 = (int)(((ulong)*(uint *)(lVar12 + 0xf4) << 0x10) / (ulong)uVar7);
      }
      if (iVar5 == 0) {
        *(undefined1 *)(lVar12 + 0x102) = 0x1f;
        uVar9 = 0;
      }
      else {
        uVar7 = 0;
        iVar2 = 0;
        if ((long)iVar5 != 0) {
          iVar2 = (int)(0x10000 / (ulong)(long)iVar5);
        }
        do {
          if ((-1 << (ulong)(uVar7 & 0x1f)) + iVar2 < 0) goto LAB_0010ccf8;
          uVar7 = uVar7 + 1;
        } while (uVar7 != 0x20);
        uVar7 = 0x1f;
LAB_0010ccf8:
        *(char *)(lVar12 + 0x102) = (char)uVar7;
        uVar4 = (ulong)(uint)(iVar5 << (ulong)(uVar7 & 0x1f)) * 0xff + 0xffffff018000;
        uVar9 = (undefined1)(uVar4 >> 0x10);
        if ((uVar4 & 0xffffff000000) != 0) {
          uVar9 = 0xff;
        }
      }
      *(undefined1 *)(lVar12 + 0x103) = uVar9;
    }
  }
  return;
}



//------------------------------------------------------------
// get_linearizer_taps @ 0010cd48 size=256
// signature: undefined get_linearizer_taps(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance, usbcss_sysfs_store]
//------------------------------------------------------------

void get_linearizer_taps(long param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  ulong uVar6;
  
  if (param_1 == 0) {
LAB_0010ce30:
    uVar5 = 0xe8;
  }
  else {
    iVar3 = wcd_usbss_get_sbu_switch_orientation();
    if (iVar3 == 2) {
      piVar4 = (int *)(param_1 + 0xa4);
    }
    else {
      iVar3 = wcd_usbss_get_sbu_switch_orientation();
      if (iVar3 != 1) goto LAB_0010ce30;
      piVar4 = (int *)(param_1 + 0x80);
    }
    uVar5 = ((*piVar4 + ((uint)(*(int *)(param_1 + 0x60) + *(int *)(param_1 + 0x44)) >> 1)) -
            ((uint)(*(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x4c)) >> 1)) +
            *(int *)(param_1 + 0xf0);
    uVar1 = uVar5 + (*(uint *)(param_1 + 0x3c) & 0x7fffffff);
    uVar6 = (ulong)(uVar1 + (*(uint *)(param_1 + 0x38) & 0x7fffffff));
    iVar3 = 0;
    if (uVar6 != 0) {
      iVar3 = (int)(((ulong)uVar5 << 0xc) / uVar6);
    }
    iVar2 = 0;
    if (uVar6 != 0) {
      iVar2 = (int)(((ulong)uVar1 << 0xc) / uVar6);
    }
    uVar1 = (int)((((long)*(int *)(param_1 + 0x74) & 0xfffffffffffffU) << 10) / 0x19) + 0x1000;
    uVar5 = 0;
    if (uVar1 != 0) {
      uVar5 = (iVar2 * 1000 + *(int *)(param_1 + 0x74) * iVar3 * 10 + (uVar1 >> 1)) / uVar1;
    }
    uVar5 = *(int *)(param_1 + 0x78) + uVar5;
    if (0x3fe < uVar5) {
      uVar5 = 0x3ff;
    }
  }
  *param_2 = uVar5;
  return;
}



//------------------------------------------------------------
// wcd939x_mbhc_get_result_params @ 0010ce48 size=548
// signature: undefined wcd939x_mbhc_get_result_params(void)
// callers: [wcd939x_mbhc_zdet_ramp]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wcd939x_mbhc_get_result_params(long param_1,long param_2,ulong param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 local_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + 0x100);
  local_60 = 0;
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x20),0x3016,0x20,0x20,0,0,0);
  iVar6 = 899;
  do {
    regmap_read(*(undefined8 *)(param_1 + 0x20),0x3018,(long)&local_60 + 4);
    if ((local_60._4_4_ >> 7 & 1) != 0) break;
    bVar3 = iVar6 != 0;
    iVar6 = iVar6 + -1;
  } while (bVar3);
  local_60._4_4_ = local_60._4_4_ << 8;
  regmap_read(*(undefined8 *)(param_1 + 0x20),0x3017,&local_60);
  local_60._4_4_ = local_60._4_4_ | (uint)local_60;
  *(uint *)(lVar7 + 0x4b0) = local_60._4_4_;
  regmap_update_bits_base(*(undefined8 *)(param_1 + 0x20),0x3016,0x20,0,0,0,0);
  uVar5 = local_60._4_4_;
  uVar1 = local_60._4_4_ & 0x3fff;
  uVar2 = local_60._4_4_ & 0xffff;
  if (((local_60._4_4_ >> 0xf & 1) == 0) && (uVar1 != 0)) {
    usleep_range_state(5000,0x13ba,2);
  }
  if ((0x3fff < uVar2) && (uVar1 != 0)) {
    uVar2 = (-1 << (ulong)(0xe - ((uint)param_3 & 0xffff) & 0x1f)) +
            uVar1 * (int)*(short *)(param_2 + (ulong)(uVar5 >> 0xe & 3) * 2);
    if ((int)uVar2 < 1) {
      if (7 < ((uint)param_3 & 0xffff)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10d06c);
        (*pcVar4)();
      }
      if (*(int *)(&DAT_00120238 + (param_3 & 0xffff) * 4) <= (int)uVar1) goto LAB_0010cfac;
      uVar5 = 0xffffffe;
    }
    else {
      uVar5 = 0;
      if (uVar2 != 0) {
        uVar5 = 0x415e6000 / uVar2;
      }
    }
    *param_4 = uVar5;
  }
LAB_0010cfac:
  *(undefined1 *)(lVar7 + 0x4b4) = 0;
  mod_timer(lVar7 + 0x478,_jiffies + 0x19);
  if (uVar1 != 0) {
    iVar6 = 900;
    while( true ) {
      regmap_read(*(undefined8 *)(param_1 + 0x20),0x3017,(long)&local_60 + 4);
      regmap_read(*(undefined8 *)(param_1 + 0x20),0x3018,&local_60);
      iVar6 = iVar6 + -1;
      local_60._4_4_ = (uint)local_60 | local_60._4_4_ << 8;
      if (iVar6 == 0) break;
      if (((*(char *)(lVar7 + 0x4b4) != '\0') && (*(uint *)(lVar7 + 0x4b0) == local_60._4_4_)) ||
         (*(uint *)(lVar7 + 0x4b0) = local_60._4_4_, (local_60._4_4_ & 0x3fff) == 0)) break;
    }
  }
  del_timer(lVar7 + 0x478);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd939x_hph_impedance_get @ 0010d070 size=220
// signature: undefined wcd939x_hph_impedance_get(void)
// callers: []
//------------------------------------------------------------

void wcd939x_hph_impedance_get(long param_1,long param_2)

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
  lVar3 = wcd939x_soc_get_mbhc(lVar5);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(wcd939x_hph_impedance_get__rs,"wcd939x_hph_impedance_get");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(lVar5 + 0x18),"%s: mbhc not initialized!\n",
               "wcd939x_hph_impedance_get");
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
// wcd939x_get_hph_type @ 0010d150 size=124
// signature: undefined wcd939x_get_hph_type(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd939x_get_hph_type(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = wcd939x_soc_get_mbhc(lVar4);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(wcd939x_get_hph_type__rs,"wcd939x_get_hph_type");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(lVar4 + 0x18),"%s: mbhc not initialized!\n","wcd939x_get_hph_type");
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
// usbcss_sysfs_show @ 0010d1d0 size=648
// signature: undefined usbcss_sysfs_show(void)
// callers: []
//------------------------------------------------------------

long usbcss_sysfs_show(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  char *__s1;
  int iVar1;
  undefined4 *puVar2;
  long lVar3;
  
  __s1 = (char *)*param_2;
  lVar3 = *(long *)(*(long *)param_2[-1] + 0x90);
  iVar1 = strcmp(__s1,"rdson_3p6v");
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)(lVar3 + 0xe4);
  }
  else {
    iVar1 = strcmp(__s1,"rdson_6v");
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)(lVar3 + 0xe0);
    }
    else {
      iVar1 = strcmp(__s1,"r1_l");
      if (iVar1 == 0) {
        puVar2 = (undefined4 *)(lVar3 + 0x48);
      }
      else {
        iVar1 = strcmp(__s1,"r1_r");
        if (iVar1 == 0) {
          puVar2 = (undefined4 *)(lVar3 + 100);
        }
        else {
          iVar1 = strcmp(__s1,"r3_l");
          if (iVar1 == 0) {
            puVar2 = (undefined4 *)(lVar3 + 0x4c);
          }
          else {
            iVar1 = strcmp(__s1,"r3_r");
            if (iVar1 == 0) {
              puVar2 = (undefined4 *)(lVar3 + 0x68);
            }
            else {
              iVar1 = strcmp(__s1,"r4_sbu1");
              if (iVar1 == 0) {
                puVar2 = (undefined4 *)(lVar3 + 0x94);
              }
              else {
                iVar1 = strcmp(__s1,"r4_sbu2");
                if (iVar1 == 0) {
                  puVar2 = (undefined4 *)(lVar3 + 0xb8);
                }
                else {
                  iVar1 = strcmp(__s1,"r5_sbu1");
                  if (iVar1 == 0) {
                    puVar2 = (undefined4 *)(lVar3 + 0x98);
                  }
                  else {
                    iVar1 = strcmp(__s1,"r5_sbu2");
                    if (iVar1 == 0) {
                      puVar2 = (undefined4 *)(lVar3 + 0xbc);
                    }
                    else {
                      iVar1 = strcmp(__s1,"r6_sbu1");
                      if (iVar1 == 0) {
                        puVar2 = (undefined4 *)(lVar3 + 0x9c);
                      }
                      else {
                        iVar1 = strcmp(__s1,"r6_sbu2");
                        if (iVar1 == 0) {
                          puVar2 = (undefined4 *)(lVar3 + 0xc0);
                        }
                        else {
                          iVar1 = strcmp(__s1,"r7_sbu1");
                          if (iVar1 == 0) {
                            puVar2 = (undefined4 *)(lVar3 + 0xa0);
                          }
                          else {
                            iVar1 = strcmp(__s1,"r7_sbu2");
                            if (iVar1 == 0) {
                              puVar2 = (undefined4 *)(lVar3 + 0xc4);
                            }
                            else {
                              iVar1 = strcmp(__s1,"r_common_gnd_offset");
                              if (iVar1 == 0) {
                                puVar2 = (undefined4 *)(lVar3 + 0xf8);
                              }
                              else {
                                iVar1 = strcmp(__s1,"rcom_margin");
                                if (iVar1 == 0) {
                                  puVar2 = (undefined4 *)(lVar3 + 0xfc);
                                }
                                else {
                                  iVar1 = strcmp(__s1,"se_slope_factor_times_1000");
                                  if (iVar1 == 0) {
                                    puVar2 = (undefined4 *)(lVar3 + 0x110);
                                  }
                                  else {
                                    iVar1 = strcmp(__s1,"diff_slope_factor_times_1000");
                                    if (iVar1 == 0) {
                                      puVar2 = (undefined4 *)(lVar3 + 0x10c);
                                    }
                                    else {
                                      iVar1 = strcmp(__s1,"lin_k_aud");
                                      if (iVar1 == 0) {
                                        puVar2 = (undefined4 *)(lVar3 + 0x74);
                                      }
                                      else {
                                        iVar1 = strcmp(__s1,"xtalk_config");
                                        if (iVar1 != 0) {
                                          return 0;
                                        }
                                        puVar2 = (undefined4 *)(lVar3 + 0x104);
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
  iVar1 = scnprintf(param_3,10,&DAT_0011e490,*puVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// usbcss_sysfs_store @ 0010d45c size=1788
// signature: undefined usbcss_sysfs_store(void)
// callers: []
//------------------------------------------------------------

long usbcss_sysfs_store(undefined8 param_1,undefined8 *param_2,undefined8 param_3,long param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long *plVar8;
  long lVar9;
  char *pcVar10;
  undefined4 local_44;
  long local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_40 = 0;
  local_44 = 0;
  if (((param_2 + -1 == (undefined8 *)0x0) || (plVar8 = (long *)param_2[-1], plVar8 == (long *)0x0))
     || (lVar9 = *(long *)(*plVar8 + 0x90), lVar9 == 0)) {
    param_4 = -0x16;
    goto LAB_0010d4cc;
  }
  iVar3 = kstrtoll(param_3,0,&local_40);
  if (iVar3 != 0) {
    param_4 = (long)iVar3;
    goto LAB_0010d4cc;
  }
  pcVar10 = (char *)*param_2;
  iVar3 = strcmp(pcVar10,"rdson_3p6v");
  if (iVar3 == 0) {
    if (local_40 < 0x4e21) {
      bVar1 = false;
      bVar2 = *(int *)(lVar9 + 0x104) == 2;
      *(int *)(lVar9 + 0xe4) = (int)local_40;
      *(int *)(lVar9 + 0xe8) = (int)local_40 - *(int *)(lVar9 + 0xe0);
LAB_0010d800:
      if (*(uint *)(lVar9 + 0x104) < 2) {
        iVar6 = *(int *)(lVar9 + 0xa0);
        iVar5 = *(int *)(lVar9 + 0xc4);
        iVar3 = *(int *)(lVar9 + 0x94) + *(int *)(lVar9 + 0x9c);
        *(int *)(lVar9 + 0xa8) = iVar5;
        iVar7 = *(int *)(lVar9 + 0xb8) + *(int *)(lVar9 + 0xc0);
        *(int *)(lVar9 + 0x84) = iVar6;
        *(int *)(lVar9 + 0x88) = iVar3;
      }
      else {
        if (*(uint *)(lVar9 + 0x104) != 2) goto LAB_0010d4cc;
        iVar5 = *(int *)(lVar9 + 0xb8) + *(int *)(lVar9 + 0xbc);
        iVar6 = *(int *)(lVar9 + 0x94) + *(int *)(lVar9 + 0x98);
        iVar7 = 1;
        iVar3 = 1;
        *(int *)(lVar9 + 0xa8) = iVar5;
        *(int *)(lVar9 + 0x84) = iVar6;
        *(undefined4 *)(lVar9 + 0x88) = 1;
      }
      *(int *)(lVar9 + 0x8c) = iVar3 + iVar6;
      *(int *)(lVar9 + 0xac) = iVar7;
      *(int *)(lVar9 + 0xb0) = iVar7 + iVar5;
      if (bVar1) {
        *(int *)(lVar9 + 0xf4) = *(int *)(lVar9 + 0xf4) + *(int *)(lVar9 + 0xf8);
        update_xtalk_scale_and_alpha(plVar8);
        *(int *)(lVar9 + 0xf4) = *(int *)(lVar9 + 0xf4) - *(int *)(lVar9 + 0xf8);
        regmap_update_bits_base(plVar8[4],0x3521,0x1f,*(undefined1 *)(lVar9 + 0x100),0,0,0);
        regmap_update_bits_base(plVar8[4],0x3522,0xff,*(undefined1 *)(lVar9 + 0x101),0,0,0);
        regmap_update_bits_base(plVar8[4],0x3525,0x1f,*(undefined1 *)(lVar9 + 0x102),0,0,0);
        regmap_update_bits_base(plVar8[4],0x3526,0xff,*(undefined1 *)(lVar9 + 0x103),0,0,0);
        _dev_err(*plVar8,"%s: Updated xtalk thru sysfs\n","usbcss_sysfs_store");
      }
      if (bVar2) {
        get_linearizer_taps(lVar9,&local_44);
        wcd_usbss_set_linearizer_sw_tap(local_44,0xe8);
        _dev_err(*plVar8,"%s: Updated linearizer thru sysfs\n","usbcss_sysfs_store");
      }
      goto LAB_0010d4cc;
    }
  }
  else {
    iVar3 = strcmp(pcVar10,"rdson_6v");
    if (iVar3 == 0) {
      if (local_40 < 0x4e21) {
        bVar1 = false;
        *(int *)(lVar9 + 0xe0) = (int)local_40;
        bVar2 = *(int *)(lVar9 + 0x104) == 2;
        goto LAB_0010d800;
      }
    }
    else {
      iVar3 = strcmp(pcVar10,"r1_l");
      if (iVar3 == 0) {
        if (local_40 < 0x4e21) {
          bVar2 = false;
          bVar1 = true;
          *(int *)(lVar9 + 0x48) = (int)local_40;
          goto LAB_0010d800;
        }
      }
      else {
        iVar3 = strcmp(pcVar10,"r1_r");
        if (iVar3 == 0) {
          if (local_40 < 0x4e21) {
            bVar2 = false;
            bVar1 = true;
            *(int *)(lVar9 + 100) = (int)local_40;
            goto LAB_0010d800;
          }
        }
        else {
          iVar3 = strcmp(pcVar10,"r3_l");
          if (iVar3 == 0) {
            if (local_40 < 0x4e21) {
              bVar1 = false;
              bVar2 = true;
              *(int *)(lVar9 + 0x4c) = (int)local_40;
              goto LAB_0010d800;
            }
          }
          else {
            iVar3 = strcmp(pcVar10,"r3_r");
            if (iVar3 == 0) {
              if (local_40 < 0x4e21) {
                bVar1 = false;
                bVar2 = true;
                *(int *)(lVar9 + 0x68) = (int)local_40;
                goto LAB_0010d800;
              }
            }
            else {
              iVar3 = strcmp(pcVar10,"r4_sbu1");
              if (iVar3 == 0) {
                if (local_40 < 0x4e21) {
                  bVar1 = true;
                  bVar2 = true;
                  *(int *)(lVar9 + 0x94) = (int)local_40;
                  goto LAB_0010d800;
                }
              }
              else {
                iVar3 = strcmp(pcVar10,"r4_sbu2");
                if (iVar3 == 0) {
                  if (local_40 < 0x4e21) {
                    bVar1 = true;
                    bVar2 = true;
                    *(int *)(lVar9 + 0xb8) = (int)local_40;
                    goto LAB_0010d800;
                  }
                }
                else {
                  iVar3 = strcmp(pcVar10,"r5_sbu1");
                  if (iVar3 == 0) {
                    if (local_40 < 0x4e21) {
                      iVar3 = *(int *)(lVar9 + 0x104);
                      *(int *)(lVar9 + 0x98) = (int)local_40;
joined_r0x0010d7d0:
                      if (iVar3 != 2) goto LAB_0010d4cc;
LAB_0010d7fc:
                      bVar1 = true;
                      bVar2 = true;
                      goto LAB_0010d800;
                    }
                  }
                  else {
                    iVar3 = strcmp(pcVar10,"r5_sbu2");
                    if (iVar3 == 0) {
                      if (local_40 < 0x4e21) {
                        iVar3 = *(int *)(lVar9 + 0x104);
                        *(int *)(lVar9 + 0xbc) = (int)local_40;
                        goto joined_r0x0010d7d0;
                      }
                    }
                    else {
                      iVar3 = strcmp(pcVar10,"r6_sbu1");
                      if (iVar3 == 0) {
                        if (local_40 < 0x4e21) {
                          iVar3 = *(int *)(lVar9 + 0x104);
                          *(int *)(lVar9 + 0x9c) = (int)local_40;
joined_r0x0010d9a0:
                          if (iVar3 != 1) goto LAB_0010d4cc;
                          goto LAB_0010d7fc;
                        }
                      }
                      else {
                        iVar3 = strcmp(pcVar10,"r6_sbu2");
                        if (iVar3 == 0) {
                          if (local_40 < 0x4e21) {
                            iVar3 = *(int *)(lVar9 + 0x104);
                            *(int *)(lVar9 + 0xc0) = (int)local_40;
                            goto joined_r0x0010d9a0;
                          }
                        }
                        else {
                          iVar3 = strcmp(pcVar10,"r7_sbu1");
                          if (iVar3 == 0) {
                            if (local_40 < 0x4e21) {
                              iVar3 = *(int *)(lVar9 + 0x104);
                              *(int *)(lVar9 + 0xa0) = (int)local_40;
                              goto joined_r0x0010d9a0;
                            }
                          }
                          else {
                            iVar3 = strcmp(pcVar10,"r7_sbu2");
                            if (iVar3 != 0) {
                              iVar3 = strcmp(pcVar10,"r_common_gnd_offset");
                              if (iVar3 == 0) {
                                if (local_40 - 0x4e21U < 0xffffffffffff63bf) {
                                  _dev_err(*plVar8,"%s: Value %d out of bounds. Min: %d, Max: %d\n",
                                           "usbcss_sysfs_store",local_40,0xffffb1e0,20000);
                                  goto LAB_0010d4cc;
                                }
                                bVar2 = false;
                                bVar1 = true;
                                *(int *)(lVar9 + 0xf8) = (int)local_40;
                              }
                              else {
                                iVar3 = strcmp(pcVar10,"rcom_margin");
                                if (iVar3 == 0) {
                                  if (20000 < local_40) goto LAB_0010da58;
                                  bVar1 = false;
                                  bVar2 = false;
                                  *(int *)(lVar9 + 0xfc) = (int)local_40;
                                }
                                else {
                                  iVar3 = strcmp(pcVar10,"se_slope_factor_times_1000");
                                  if (iVar3 == 0) {
                                    if (20000 < local_40) goto LAB_0010da58;
                                    bVar1 = false;
                                    bVar2 = false;
                                    *(int *)(lVar9 + 0x110) = (int)local_40;
                                  }
                                  else {
                                    iVar3 = strcmp(pcVar10,"diff_slope_factor_times_1000");
                                    if (iVar3 == 0) {
                                      if (local_40 - 0x2711U < 0xffffffffffffff36 ||
                                          local_40 == 0x2647) {
                                        lVar9 = *plVar8;
                                        pcVar10 = "%s: Value %d out of range of %d to %d\n";
                                        uVar4 = 0x2648;
LAB_0010db4c:
                                        _dev_err(lVar9,pcVar10,"usbcss_sysfs_store",local_40,uVar4,
                                                 10000);
                                        goto LAB_0010d4cc;
                                      }
                                      bVar1 = false;
                                      bVar2 = false;
                                      *(int *)(lVar9 + 0x10c) = (int)local_40;
                                    }
                                    else {
                                      iVar3 = strcmp(pcVar10,"lin_k_aud");
                                      if (iVar3 == 0) {
                                        if (local_40 - 0x2711U < 0xffffffffffffd895) {
                                          lVar9 = *plVar8;
                                          pcVar10 = "%s: Value %d out of bounds. Min: %d, Max: %d\n"
                                          ;
                                          uVar4 = 0xffffffa6;
                                          goto LAB_0010db4c;
                                        }
                                        bVar1 = false;
                                        bVar2 = true;
                                        *(int *)(lVar9 + 0x74) = (int)local_40;
                                      }
                                      else {
                                        iVar3 = strcmp(pcVar10,"xtalk_config");
                                        if (iVar3 == 0) {
                                          *(int *)(lVar9 + 0x104) = (int)local_40;
                                          if (local_40 - 1U < 2) goto LAB_0010d7fc;
                                          if (local_40 != 0) goto LAB_0010d4cc;
                                          bVar2 = false;
                                          bVar1 = true;
                                          *(undefined4 *)(lVar9 + 0x100) = 0x1f001f;
                                        }
                                        else {
                                          bVar1 = false;
                                          bVar2 = false;
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                              goto LAB_0010d800;
                            }
                            if (local_40 < 0x4e21) {
                              iVar3 = *(int *)(lVar9 + 0x104);
                              *(int *)(lVar9 + 0xc4) = (int)local_40;
                              goto joined_r0x0010d9a0;
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
LAB_0010da58:
  _dev_err(*plVar8,"%s: Value %d out of HS impedance range %d\n","usbcss_sysfs_store",local_40,20000
          );
LAB_0010d4cc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 0011a42c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&wcd939x_codec_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0011a45c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&wcd939x_codec_driver);
  return;
}



//------------------------------------------------------------
// ___ratelimit @ 00123000 size=1
// signature: undefined ___ratelimit(void)
// callers: [wcd939x_tx_path_get, wcd939x_event_notify, wcd939x_get_hwdep_fw_cal, wcd939x_mbhc_hs_detect_exit, wcd939x_codec_get_dev_num, wcd939x_wd_handle_irq, wcd939x_codec_force_enable_micbias_v2, wcd939x_probe, wcd939x_tx_get_slave_ch_type_idx, wcd939x_bind, wcd939x_codec_enable_dmic, wcd939x_tx_channel_config, wcd939x_swr_dmic_register_notifier, wcd939x_soc_get_mbhc, wcd939x_resume, wcd939x_hph_impedance_get, wcd939x_wakeup, wcd939x_enable_micbias, wcd939x_mbhc_micb_adjust_voltage, wcd939x_rx_mux, wcd939x_get_micb_vout_ctl_val, wcd939x_enable_req, wcd939x_suspend, wcd939x_populate_dt_data, wcd939x_config_2Vpk_mode, wcd939x_mbhc_get_impedance, wcd939x_mbhc_program_btn_thr, wcd939x_reset, wcd939x_set_port_params, wcd939x_get_hph_type, wcd939x_micbias_control, wcd939x_rx_hph_mode_put, wcd939x_mbhc_hs_detect, wcd939x_variant_read, wcd939x_set_micbias_data, wcd939x_config_compander, wcd939x_version_read, wcd939x_config_xtalk, wcd939x_get_logical_addr, wcd939x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00123008 size=1
// signature: undefined _printk(void)
// callers: [wcd939x_tx_path_get, wcd939x_get_hwdep_fw_cal, wcd939x_mbhc_hs_detect_exit, wcd939x_codec_get_dev_num, wcd939x_soc_codec_probe, wcd939x_wd_handle_irq, wcd939x_codec_force_enable_micbias_v2, wcd939x_tx_get_slave_ch_type_idx, wcd939x_mbhc_deinit, wcd939x_tx_channel_config, wcd939x_swr_dmic_register_notifier, wcd939x_soc_get_mbhc, wcd939x_wakeup, wcd939x_enable_micbias, wcd939x_mbhc_micb_adjust_voltage, wcd939x_rx_mux, wcd939x_get_micb_vout_ctl_val, wcd939x_enable_req, wcd939x_mbhc_get_impedance, wcd939x_reset, wcd939x_mbhc_hs_detect, wcd939x_mbhc_init, wcd939x_variant_read, wcd939x_set_micbias_data, wcd939x_config_compander, wcd939x_version_read, wcd939x_config_xtalk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00123010 size=1
// signature: undefined mutex_lock(void)
// callers: [wcd939x_wakeup, wcd939x_enable_micbias, wcd939x_mbhc_micb_adjust_voltage, wcd939x_micbias_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 00123018 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wcd939x_codec_hphr_dac_event, wcd939x_event_notify, wcd939x_wcd_mbhc_calc_impedance, wcd939x_codec_enable_hphr_pa, wcd939x_mbhc_btn_to_num, wcd939x_codec_hphl_dac_event, wcd939x_mbhc_get_moisture_status, wcd939x_mbhc_hph_pa_on_status, wcd939x_mbhc_micb_adjust_voltage, wcd939x_codec_enable_hphl_pa, wcd939x_tx_swr_ctrl, wcd939x_ear_pa_gain_get, wcd939x_mbhc_micb_en_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 00123020 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wcd939x_codec_enable_ear_pa, wcd939x_mbhc_micb_ramp_control, wcd939x_mbhc_gnd_det_ctrl, wcd939x_event_notify, wcd939x_wcd_mbhc_calc_impedance, wcd939x_codec_enable_hphr_pa, wcd939x_mbhc_post_ssr_init, wcd939x_mbhc_get_moisture_status, wcd939x_codec_enable_dmic, wcd939x_mbhc_mbhc_bias_control, wcd939x_tx_channel_config, wcd939x_rx_clk_disable, wcd939x_ear_pa_gain_put, wcd939x_mbhc_micb_adjust_voltage, wcd939x_rx_mux, wcd939x_enable_req, wcd939x_config_2Vpk_mode, wcd939x_mbhc_moisture_polling_ctrl, wcd939x_mbhc_program_btn_thr, wcd939x_codec_enable_adc, wcd939x_codec_hphr_dac_event, wcd939x_rx_clk_enable, wcd939x_mbhc_hph_l_pull_up_control, wcd939x_config_power_mode, wcd939x_mbhc_zdet_leakage_resistance, wcd939x_micbias_control, wcd939x_mbhc_clk_setup, wcd939x_mbhc_moisture_config, wcd939x_codec_hphl_dac_event, wcd939x_mbhc_moisture_detect_en, wcd939x_config_compander, wcd939x_mbhc_hph_pull_down_ctrl, wcd939x_codec_enable_hphl_pa, wcd939x_codec_ear_dac_event, wcd939x_config_xtalk, wcd939x_mbhc_zdet_ramp, wcd939x_tx_swr_ctrl, wcd939x_init_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00123028 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd939x_codec_enable_ear_pa, wcd939x_reset, wcd939x_codec_hphr_dac_event, wcd939x_event_notify, wcd939x_wcd_mbhc_calc_impedance, wcd939x_codec_enable_hphr_pa, wcd939x_codec_hphl_dac_event, wcd939x_bind, wcd939x_config_compander, wcd939x_codec_enable_dmic, wcd939x_mbhc_get_result_params, wcd939x_codec_enable_micbias_pullup, wcd939x_mbhc_micb_adjust_voltage, wcd939x_codec_ear_dac_event, wcd939x_codec_enable_hphl_pa, wcd939x_enable_rx3, wcd939x_get_logical_addr, wcd939x_init_reg, __wcd939x_codec_enable_micbias, wcd939x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00123030 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcd939x_wakeup, wcd939x_enable_micbias, wcd939x_mbhc_micb_adjust_voltage, wcd939x_micbias_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00123038 size=1
// signature: undefined _dev_err(void)
// callers: [wcd939x_event_notify, wcd939x_hph_compander_put, wcd939x_get_hwdep_fw_cal, wcd939x_mbhc_hs_detect_exit, wcd939x_soc_codec_probe, wcd939x_mbhc_post_ssr_init, wcd939x_probe, wcd939x_bind, wcd939x_codec_enable_dmic, wcd939x_resume, wcd939x_hph_impedance_get, wcd939x_get_codec_variant, wcd939x_parse_port_mapping, wcd939x_suspend, wcd939x_populate_dt_data, wcd939x_config_2Vpk_mode, wcd939x_mbhc_program_btn_thr, wcd939x_reset, wcd939x_soc_codec_remove, wcd939x_set_port_params, wcd939x_get_hph_type, wcd939x_micbias_control, wcd939x_mbhc_hs_detect, wcd939x_mbhc_init, wcd939x_set_micbias_data, wcd939x_hph_xtalk_put, wcd939x_get_logical_addr, wcd939x_codec_enable_vdd_buck, usbcss_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00123040 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [wcd939x_event_notify, wcd939x_codec_enable_hphl_pa, wcd939x_codec_enable_hphr_pa, wcd939x_micbias_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00123048 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [wcd939x_swr_dmic_register_notifier, wcd939x_mbhc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00123050 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [wcd939x_swr_dmic_register_notifier, wcd939x_mbhc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_vote @ 00123058 size=1
// signature: undefined swr_device_wakeup_vote(void)
// callers: [wcd939x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_unvote @ 00123060 size=1
// signature: undefined swr_device_wakeup_unvote(void)
// callers: [wcd939x_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_unvote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00123068 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wcd939x_mbhc_get_result_params, wcd939x_wcd_mbhc_calc_impedance, wcd939x_enable_micbias, wcd939x_mbhc_zdet_ramp, wcd939x_set_micbias_data, update_xtalk_scale_and_alpha, usbcss_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 00123070 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [wcd939x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 00123078 size=1
// signature: undefined snd_info_register(void)
// callers: [wcd939x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 00123080 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [wcd939x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 00123088 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [wcd939x_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00123090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd939x_soc_codec_probe, wcd939x_mbhc_init, wcd939x_probe, wcd939x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00123098 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wcd939x_probe, wcd939x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 001230a0 size=1
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: [wcd939x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_get_power_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001230a8 size=1
// signature: undefined of_find_property(void)
// callers: [wcd939x_soc_codec_probe, wcd939x_parse_port_mapping, wcd939x_probe, wcd939x_init_reg, wcd939x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001230b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wcd939x_parse_port_mapping, wcd939x_probe, wcd939x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_linearizer_rdac_cal_code_select @ 001230b8 size=1
// signature: undefined wcd_usbss_linearizer_rdac_cal_code_select(void)
// callers: [wcd939x_populate_dt_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_linearizer_rdac_cal_code_select(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001230c0 size=1
// signature: undefined _dev_info(void)
// callers: [wcd939x_soc_codec_probe, wcd939x_rx_hph_mode_put, wcd939x_populate_dt_data, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001230c8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd939x_enable_rx2, wcd939x_tx_path_get, wcd939x_event_notify, wcd939x_enable_clsh, wcd939x_wcd_mbhc_calc_impedance, wcd939x_handle_post_irq, wcd939x_probe, wcd939x_tx_master_ch_get, wcd939x_bind, wcd939x_enable_rx1, wcd939x_hph_impedance_get, wcd939x_enable_rx3, wcd939x_parse_port_mapping, wcd939x_populate_dt_data, wcd939x_config_2Vpk_mode, wcd939x_tx_master_ch_put, wcd939x_reset, wcd939x_codec_enable_adc, wcd_usbss_set_ovp_threshold, wcd939x_variant_read, wcd939x_tx_mode_put, wcd939x_version_read, wcd939x_mbhc_get_result_params, wcd939x_tx_mode_get, wcd939x_mbhc_zdet_ramp, wcd939x_get_logical_addr, wcd939x_tx_swr_ctrl, wcd939x_tx_connect_port, usbcss_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001230d0 size=1
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
// platform_driver_unregister @ 001230d8 size=1
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
// simple_read_from_buffer @ 001230e0 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [wcd939x_version_read, wcd939x_variant_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 001230e8 size=1
// signature: undefined msm_cdc_init_supplies(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_init_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 001230f0 size=1
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_static_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_is_ondemand_supply @ 001230f8 size=1
// signature: undefined msm_cdc_is_ondemand_supply(void)
// callers: [wcd939x_resume, wcd939x_probe, wcd939x_suspend, wcd939x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_is_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_ondemand_supply @ 00123100 size=1
// signature: undefined msm_cdc_enable_ondemand_supply(void)
// callers: [wcd939x_resume, wcd939x_probe, wcd939x_codec_enable_vdd_buck]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00123108 size=1
// signature: undefined __kmalloc(void)
// callers: [wcd939x_parse_port_mapping, wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00123110 size=1
// signature: undefined kfree(void)
// callers: [wcd939x_tx_path_get, wcd939x_parse_port_mapping, wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00123118 size=1
// signature: undefined __mutex_init(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_match_add_release @ 00123120 size=1
// signature: undefined component_match_add_release(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_match_add_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_add_with_match @ 00123128 size=1
// signature: undefined component_master_add_with_match(void)
// callers: [wcd939x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_add_with_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_master_del @ 00123130 size=1
// signature: undefined component_master_del(void)
// callers: [wcd939x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_master_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 00123138 size=1
// signature: undefined __sw_hweight8(void)
// callers: [wcd939x_parse_port_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 00123140 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [wcd939x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_register_update @ 00123148 size=1
// signature: undefined wcd_usbss_register_update(void)
// callers: [wcd939x_reset, wcd939x_event_notify, wcd939x_wcd_mbhc_calc_impedance, wcd_usbss_set_ovp_threshold]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_register_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 00123150 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wcd939x_reset, wcd939x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 00123158 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wcd939x_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_bind_all @ 00123160 size=1
// signature: undefined component_bind_all(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_bind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_matching_swr_slave_device @ 00123168 size=1
// signature: undefined get_matching_swr_slave_device(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_matching_swr_slave_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// component_unbind_all @ 00123170 size=1
// signature: undefined component_unbind_all(void)
// callers: [wcd939x_unbind, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void component_unbind_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_init_port_params @ 00123178 size=1
// signature: undefined swr_init_port_params(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_init_port_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 00123180 size=1
// signature: undefined swr_read(void)
// callers: [wcd939x_codec_enable_adc, wcd939x_tx_swr_ctrl, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 00123188 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00123190 size=1
// signature: undefined regmap_read(void)
// callers: [wcd939x_mbhc_get_result_params, wcd939x_handle_post_irq, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_update_default_trim @ 00123198 size=1
// signature: undefined wcd_usbss_update_default_trim(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_update_default_trim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001231a0 size=1
// signature: undefined regmap_write(void)
// callers: [wcd939x_bind, wcd939x_update_regmap_cache]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_init @ 001231a8 size=1
// signature: undefined wcd_irq_init(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_request_irq @ 001231b0 size=1
// signature: undefined wcd_request_irq(void)
// callers: [wcd939x_mbhc_request_irq, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_request_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_disable_irq @ 001231b8 size=1
// signature: undefined wcd_disable_irq(void)
// callers: [wcd939x_codec_enable_ear_pa, wcd939x_mbhc_irq_control, wcd939x_codec_enable_hphl_pa, wcd939x_codec_enable_hphr_pa, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 001231c0 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_exit @ 001231c8 size=1
// signature: undefined wcd_irq_exit(void)
// callers: [wcd939x_unbind, wcd939x_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_free_irq @ 001231d0 size=1
// signature: undefined wcd_free_irq(void)
// callers: [wcd939x_mbhc_free_irq, wcd939x_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 001231d8 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [wcd939x_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 001231e0 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 001231e8 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cal_create_hwdep @ 001231f8 size=1
// signature: undefined wcd_cal_create_hwdep(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cal_create_hwdep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 00123200 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 00123208 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_init @ 00123210 size=1
// signature: undefined wcd_cls_h_init(void)
// callers: [wcd939x_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 00123218 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [wcd939x_soc_codec_probe, wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00123220 size=1
// signature: undefined strnstr(void)
// callers: [wcd939x_codec_enable_micbias_pullup, wcd939x_tx_swr_ctrl, wcd939x_tx_get_slave_ch_type_idx, __wcd939x_codec_enable_micbias]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 00123228 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [wcd939x_enable_rx2, wcd939x_codec_enable_adc, wcd939x_enable_clsh, wcd939x_enable_rx3, wcd939x_tx_connect_port, wcd939x_enable_rx1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 00123230 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [wcd939x_codec_enable_ear_pa, wcd939x_codec_enable_dmic, wcd939x_codec_enable_adc, wcd939x_clsh_dummy, wcd939x_enable_clsh, wcd939x_codec_enable_hphl_pa, wcd939x_codec_enable_hphr_pa, wcd939x_tx_swr_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 00123238 size=1
// signature: undefined swr_connect_port(void)
// callers: [wcd939x_enable_rx2, wcd939x_enable_clsh, wcd939x_enable_rx3, wcd939x_tx_swr_ctrl, wcd939x_tx_connect_port, wcd939x_enable_rx1]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_enable_irq @ 00123240 size=1
// signature: undefined wcd_enable_irq(void)
// callers: [wcd939x_codec_enable_ear_pa, wcd939x_codec_enable_hphl_pa, wcd939x_mbhc_irq_control, wcd939x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_cls_h_fsm @ 00123248 size=1
// signature: undefined wcd_cls_h_fsm(void)
// callers: [wcd939x_codec_enable_ear_pa, wcd939x_codec_enable_hphl_pa, wcd939x_codec_ear_dac_event, wcd939x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_cls_h_fsm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_audio_config @ 00123250 size=1
// signature: undefined wcd_usbss_audio_config(void)
// callers: [wcd939x_codec_enable_hphl_pa, wcd939x_codec_enable_hphr_pa]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_audio_config(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 00123258 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [wcd939x_codec_hphr_dac_event, wcd939x_wcd_mbhc_calc_impedance, wcd939x_init_reg, wcd939x_codec_hphl_dac_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_get_impedance @ 00123260 size=1
// signature: undefined wcd_mbhc_get_impedance(void)
// callers: [wcd939x_hph_impedance_get, wcd939x_config_2Vpk_mode, wcd939x_mbhc_get_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_get_impedance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 00123268 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wcd939x_event_notify, wcd939x_surge_reset_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 00123270 size=1
// signature: undefined regcache_sync(void)
// callers: [wcd939x_event_notify, wcd939x_surge_reset_routine]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00123278 size=1
// signature: undefined __const_udelay(void)
// callers: [wcd939x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 00123280 size=1
// signature: undefined kstrndup(void)
// callers: [wcd939x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00123288 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [wcd939x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 00123290 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [wcd939x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00123298 size=1
// signature: undefined kstrtouint(void)
// callers: [wcd939x_tx_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 001232a0 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wcd939x_get_logical_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_disable_ondemand_supply @ 001232a8 size=1
// signature: undefined msm_cdc_disable_ondemand_supply(void)
// callers: [wcd939x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_disable_ondemand_supply(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_set_supplies_lpm_mode @ 001232b0 size=1
// signature: undefined msm_cdc_set_supplies_lpm_mode(void)
// callers: [wcd939x_resume, wcd939x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_set_supplies_lpm_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_supply_supports_retention_mode @ 001232b8 size=1
// signature: undefined msm_cdc_supply_supports_retention_mode(void)
// callers: [wcd939x_resume, wcd939x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_supply_supports_retention_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_check_supply_vote @ 001232c0 size=1
// signature: undefined msm_cdc_check_supply_vote(void)
// callers: [wcd939x_resume, wcd939x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_check_supply_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_start @ 00123308 size=1
// signature: undefined wcd_mbhc_start(void)
// callers: [wcd939x_mbhc_hs_detect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_stop @ 00123310 size=1
// signature: undefined wcd_mbhc_stop(void)
// callers: [wcd939x_mbhc_hs_detect_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_deinit @ 00123318 size=1
// signature: undefined wcd_mbhc_deinit(void)
// callers: [wcd939x_mbhc_deinit, wcd939x_mbhc_ssr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_deinit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_mbhc_init @ 00123320 size=1
// signature: undefined wcd_mbhc_init(void)
// callers: [wcd939x_mbhc_init, wcd939x_mbhc_post_ssr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_mbhc_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 00123328 size=1
// signature: undefined __init_rwsem(void)
// callers: [wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00123330 size=1
// signature: undefined init_timer_key(void)
// callers: [wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00123340 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 00123348 size=1
// signature: undefined devm_kstrdup(void)
// callers: [wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00123350 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 00123358 size=1
// signature: undefined del_timer(void)
// callers: [wcd939x_mbhc_deinit, wcd939x_mbhc_get_result_params, wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00123360 size=1
// signature: undefined devm_kfree(void)
// callers: [wcd939x_mbhc_deinit, wcd939x_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 00123368 size=1
// signature: undefined mutex_is_locked(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_set_switch_settings_enable @ 00123370 size=1
// signature: undefined wcd_usbss_set_switch_settings_enable(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_set_switch_settings_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_get_sbu_switch_orientation @ 00123378 size=1
// signature: undefined wcd_usbss_get_sbu_switch_orientation(void)
// callers: [get_linearizer_taps, wcd939x_wcd_mbhc_calc_impedance, update_xtalk_scale_and_alpha]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_get_sbu_switch_orientation(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_set_linearizer_sw_tap @ 00123380 size=1
// signature: undefined wcd_usbss_set_linearizer_sw_tap(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance, usbcss_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_set_linearizer_sw_tap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00123388 size=1
// signature: undefined __warn_printk(void)
// callers: [wcd939x_wcd_mbhc_calc_impedance]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcdcal_get_fw_cal @ 00123390 size=1
// signature: undefined wcdcal_get_fw_cal(void)
// callers: [wcd939x_get_hwdep_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcdcal_get_fw_cal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 001233a0 size=1
// signature: undefined mod_timer(void)
// callers: [wcd939x_mbhc_get_result_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001233a8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [usbcss_sysfs_show, usbcss_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001233b0 size=1
// signature: undefined scnprintf(void)
// callers: [usbcss_sysfs_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 001233b8 size=1
// signature: undefined kstrtoll(void)
// callers: [usbcss_sysfs_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



