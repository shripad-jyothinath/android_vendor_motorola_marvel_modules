// Decompiled by Ghidra 12.2
// Program: lpass_cdc_tx_macro_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_cdc_tx_macro_probe @ 001006f4 size=720
// signature: undefined lpass_cdc_tx_macro_probe(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_tx_macro_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  undefined2 uVar8;
  uint uVar9;
  undefined8 local_b0;
  code *local_a8;
  code *local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined **local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  code *pcStack_60;
  undefined8 local_58;
  code *pcStack_50;
  long local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar7 + 0x638);
  local_a0 = (code *)0x0;
  local_b0 = 0;
  uVar4 = lpass_cdc_is_va_macro_registered(lVar1);
  if ((uVar4 & 1) == 0) {
    _dev_err(lVar1,"%s: va-macro not registered yet, defer\n","lpass_cdc_tx_macro_probe");
    iVar3 = -0x205;
    goto LAB_00100800;
  }
  plVar5 = (long *)devm_kmalloc(lVar1,0xac0,0xdc0);
  if (plVar5 == (long *)0x0) {
    iVar3 = -0xc;
    goto LAB_00100800;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  *(long **)(param_1 + 0xa8) = plVar5;
  *plVar5 = lVar1;
  iVar3 = of_property_read_variable_u32_array(uVar6,&DAT_0010f7c6,(long)&local_b0 + 4,1,0);
  if (iVar3 < 0) {
    _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_tx_macro_probe",&DAT_0010f7c6);
    goto LAB_00100800;
  }
  *(long **)(param_1 + 0xa8) = plVar5;
  lVar7 = devm_ioremap(lVar1,local_b0._4_4_,0x1000);
  if (lVar7 == 0) {
    _dev_err(lVar1,"%s: ioremap failed\n","lpass_cdc_tx_macro_probe");
    iVar3 = -0xc;
    goto LAB_00100800;
  }
  plVar5[0x149] = lVar7;
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  *(undefined1 *)(plVar5 + 0x157) = 0;
  *(undefined4 *)((long)plVar5 + 0xabc) = 0;
  iVar3 = of_property_read_variable_u32_array(uVar6,"qcom,tx-dmic-sample-rate",&local_b0,1,0);
  if (iVar3 < 0) {
    _dev_err(lVar1,"%s: could not find sample_rate entry in dt\n","lpass_cdc_tx_macro_probe");
    uVar8 = 0;
LAB_001008c4:
    *(undefined2 *)(plVar5 + 0x140) = uVar8;
    __mutex_init(plVar5 + 3,"&tx_priv->mclk_lock",&lpass_cdc_tx_macro_probe___key);
    __mutex_init(plVar5 + 9,"&tx_priv->wlock",&lpass_cdc_tx_macro_probe___key_8);
    uStack_90 = 0;
    local_a8 = lpass_cdc_tx_macro_init;
    local_a0 = lpass_cdc_tx_macro_deinit;
    uStack_40 = 0;
    local_88 = &lpass_cdc_tx_macro_dai;
    uStack_80 = 0;
    local_98 = 3;
    local_78 = lpass_cdc_tx_macro_event_handler;
    uStack_70 = 0;
    local_68 = 0;
    pcStack_60 = lpass_cdc_tx_macro_clk_div_get;
    local_58 = 0;
    pcStack_50 = __lpass_cdc_tx_macro_mclk_enable;
    local_48 = lVar7;
    iVar3 = lpass_cdc_register_macro(lVar1,0,&local_a8);
    if (iVar3 == 0) {
      pm_runtime_set_autosuspend_delay(lVar1,0x32);
      __pm_runtime_use_autosuspend(lVar1,1);
      __pm_runtime_set_status(lVar1,2);
      *(ushort *)(param_1 + 0x210) = *(ushort *)(param_1 + 0x210) | 0x100;
      pm_runtime_enable(lVar1);
    }
    else {
      _dev_err(lVar1,"%s: register macro failed\n","lpass_cdc_tx_macro_probe");
    }
  }
  else {
    if ((uint)local_b0 != 0) {
      uVar2 = 0;
      if ((uint)local_b0 != 0) {
        uVar2 = 9600000 / (uint)local_b0;
      }
      if (uVar2 * (uint)local_b0 == 9600000) {
        uVar9 = (uint)((ulong)uVar2 - 2);
        if ((uVar9 < 0xf) && ((0x4057U >> (ulong)(uVar9 & 0x1f) & 1) != 0)) {
          uVar8 = *(undefined2 *)(&DAT_0010ddb0 + ((ulong)uVar2 - 2) * 2);
          goto LAB_001008c4;
        }
      }
    }
    iVar3 = -0x16;
  }
LAB_00100800:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_remove @ 001009c8 size=92
// signature: undefined lpass_cdc_tx_macro_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_tx_macro_remove(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0xa8) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    param_1 = param_1 + 0x10;
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    lpass_cdc_unregister_macro(param_1,0);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_init @ 00100a28 size=1324
// signature: undefined lpass_cdc_tx_macro_init(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_tx_macro_init(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),0);
  if (lVar4 == 0) {
    uVar5 = *(undefined8 *)(param_1 + 0x18);
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar7 = *(long *)(lVar4 + 0x98);
    if (lVar7 != 0) {
      lVar1 = param_1 + 0xd0;
      uVar2 = lpass_cdc_get_version(lVar4);
      *(undefined4 *)(lVar7 + 0xa04) = uVar2;
      iVar3 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_tx_macro_dapm_widgets,0x29);
      if (iVar3 < 0) {
        pcVar6 = "%s: Failed to add controls\n";
      }
      else {
        iVar3 = snd_soc_dapm_add_routes(lVar1,&tx_audio_map,0xd6);
        if (iVar3 < 0) {
          pcVar6 = "%s: Failed to add routes\n";
        }
        else {
          iVar3 = snd_soc_dapm_new_widgets(*(undefined8 *)(param_1 + 0xe8));
          if (iVar3 < 0) {
            pcVar6 = "%s: Failed to add widgets\n";
          }
          else {
            iVar3 = snd_soc_add_component_controls(param_1,lpass_cdc_tx_macro_snd_controls,0x1c);
            if (-1 < iVar3) {
              snd_soc_dapm_ignore_suspend(lVar1,"TX_AIF1 Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"TX_AIF2 Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"TX_AIF3 Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"TX SWR_INPUT");
              snd_soc_dapm_sync(lVar1);
              *(long *)(lVar7 + 0x80) = lVar7;
              *(undefined1 *)(lVar7 + 0x88) = 0;
              *(undefined8 *)(lVar7 + 0x90) = 0xfffffffe0;
              *(long *)(lVar7 + 0x98) = lVar7 + 0x98;
              *(long *)(lVar7 + 0xa0) = lVar7 + 0x98;
              *(code **)(lVar7 + 0xa8) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0xc0,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x118) = lVar7;
              *(undefined8 *)(lVar7 + 0x128) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x120) = 1;
              *(long *)(lVar7 + 0x130) = lVar7 + 0x130;
              *(long *)(lVar7 + 0x138) = lVar7 + 0x130;
              *(code **)(lVar7 + 0x140) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x158,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x1b0) = lVar7;
              *(undefined8 *)(lVar7 + 0x1c0) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x1b8) = 2;
              *(long *)(lVar7 + 0x1c8) = lVar7 + 0x1c8;
              *(long *)(lVar7 + 0x1d0) = lVar7 + 0x1c8;
              *(code **)(lVar7 + 0x1d8) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x1f0,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x248) = lVar7;
              *(undefined8 *)(lVar7 + 600) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x250) = 3;
              *(long *)(lVar7 + 0x260) = lVar7 + 0x260;
              *(long *)(lVar7 + 0x268) = lVar7 + 0x260;
              *(code **)(lVar7 + 0x270) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x288,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x2e0) = lVar7;
              *(undefined8 *)(lVar7 + 0x2f0) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x2e8) = 4;
              *(long *)(lVar7 + 0x2f8) = lVar7 + 0x2f8;
              *(long *)(lVar7 + 0x300) = lVar7 + 0x2f8;
              *(code **)(lVar7 + 0x308) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 800,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x378) = lVar7;
              *(undefined8 *)(lVar7 + 0x388) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x380) = 5;
              *(long *)(lVar7 + 0x390) = lVar7 + 0x390;
              *(long *)(lVar7 + 0x398) = lVar7 + 0x390;
              *(code **)(lVar7 + 0x3a0) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x3b8,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x410) = lVar7;
              *(undefined8 *)(lVar7 + 0x420) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x418) = 6;
              *(long *)(lVar7 + 0x428) = lVar7 + 0x428;
              *(long *)(lVar7 + 0x430) = lVar7 + 0x428;
              *(code **)(lVar7 + 0x438) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x450,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x4a8) = lVar7;
              *(undefined8 *)(lVar7 + 0x4b8) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x4b0) = 7;
              *(long *)(lVar7 + 0x4c0) = lVar7 + 0x4c0;
              *(long *)(lVar7 + 0x4c8) = lVar7 + 0x4c0;
              *(code **)(lVar7 + 0x4d0) = lpass_cdc_tx_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x4e8,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x540) = lVar7;
              *(undefined4 *)(lVar7 + 0x548) = 0;
              *(undefined8 *)(lVar7 + 0x550) = 0xfffffffe0;
              *(long *)(lVar7 + 0x558) = lVar7 + 0x558;
              *(long *)(lVar7 + 0x560) = lVar7 + 0x558;
              *(code **)(lVar7 + 0x568) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x580,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x5d8) = lVar7;
              *(undefined4 *)(lVar7 + 0x5e0) = 1;
              *(undefined8 *)(lVar7 + 0x5e8) = 0xfffffffe0;
              *(long *)(lVar7 + 0x5f0) = lVar7 + 0x5f0;
              *(long *)(lVar7 + 0x5f8) = lVar7 + 0x5f0;
              *(code **)(lVar7 + 0x600) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x618,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x670) = lVar7;
              *(undefined4 *)(lVar7 + 0x678) = 2;
              *(undefined8 *)(lVar7 + 0x680) = 0xfffffffe0;
              *(long *)(lVar7 + 0x688) = lVar7 + 0x688;
              *(long *)(lVar7 + 0x690) = lVar7 + 0x688;
              *(code **)(lVar7 + 0x698) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x6b0,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x708) = lVar7;
              *(undefined4 *)(lVar7 + 0x710) = 3;
              *(undefined8 *)(lVar7 + 0x718) = 0xfffffffe0;
              *(long *)(lVar7 + 0x720) = lVar7 + 0x720;
              *(long *)(lVar7 + 0x728) = lVar7 + 0x720;
              *(code **)(lVar7 + 0x730) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x748,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x7a0) = lVar7;
              *(undefined4 *)(lVar7 + 0x7a8) = 4;
              *(undefined8 *)(lVar7 + 0x7b0) = 0xfffffffe0;
              *(long *)(lVar7 + 0x7b8) = lVar7 + 0x7b8;
              *(long *)(lVar7 + 0x7c0) = lVar7 + 0x7b8;
              *(code **)(lVar7 + 0x7c8) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x7e0,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x838) = lVar7;
              *(undefined4 *)(lVar7 + 0x840) = 5;
              *(undefined8 *)(lVar7 + 0x848) = 0xfffffffe0;
              *(long *)(lVar7 + 0x850) = lVar7 + 0x850;
              *(long *)(lVar7 + 0x858) = lVar7 + 0x850;
              *(code **)(lVar7 + 0x860) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x878,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x8d0) = lVar7;
              *(undefined4 *)(lVar7 + 0x8d8) = 6;
              *(undefined8 *)(lVar7 + 0x8e0) = 0xfffffffe0;
              *(long *)(lVar7 + 0x8e8) = lVar7 + 0x8e8;
              *(long *)(lVar7 + 0x8f0) = lVar7 + 0x8e8;
              *(code **)(lVar7 + 0x8f8) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x910,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x968) = lVar7;
              *(undefined4 *)(lVar7 + 0x970) = 7;
              *(undefined8 *)(lVar7 + 0x978) = 0xfffffffe0;
              *(long *)(lVar7 + 0x980) = lVar7 + 0x980;
              *(long *)(lVar7 + 0x988) = lVar7 + 0x980;
              *(code **)(lVar7 + 0x990) = lpass_cdc_tx_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x9a8,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x78) = param_1;
              snd_soc_component_update_bits(param_1,0x42c,0x3f,10);
              return 0;
            }
            pcVar6 = "%s: Failed to add snd_ctls\n";
          }
        }
      }
      _dev_err(lVar4,pcVar6,"lpass_cdc_tx_macro_init");
      return iVar3;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x18);
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(uVar5,pcVar6,"lpass_cdc_tx_macro_init");
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_deinit @ 00100f58 size=116
// signature: undefined lpass_cdc_tx_macro_deinit(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_deinit(undefined8 param_1)

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
  uVar2 = lpass_cdc_tx_macro_get_data(param_1,auStack_20,&local_28,"lpass_cdc_tx_macro_deinit");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(undefined8 *)(local_28 + 0x78) = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_event_handler @ 00100fd0 size=316
// signature: undefined lpass_cdc_tx_macro_event_handler(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_event_handler(undefined8 param_1,short param_2,int param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long local_48;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_40 = 0;
  uVar4 = lpass_cdc_tx_macro_get_data
                    (param_1,&local_40,&local_48,"lpass_cdc_tx_macro_event_handler");
  lVar2 = local_40;
  lVar1 = local_48;
  if ((uVar4 & 1) == 0) {
    uVar5 = 0xffffffea;
  }
  else if (param_2 == 10) {
    if (*(char *)(local_48 + 0xa94) != '\0') {
      snd_soc_component_update_bits(param_1,0x42c,0x40,param_3 << 6);
    }
    if (param_3 == 0) {
      uVar5 = 0;
      *(undefined1 *)(lVar1 + 0xa95) = 0;
    }
    else {
      uVar5 = 0;
      *(undefined1 *)(lVar1 + 0xa95) = 1;
    }
  }
  else {
    if (param_2 == 7) {
      lpass_cdc_rsc_clk_reset(local_40,0);
    }
    else if (param_2 == 4) {
      if ((((*(ushort *)(local_40 + 0x200) & 7) != 0) || (*(int *)(local_40 + 0x20c) != 2)) &&
         (iVar3 = lpass_cdc_runtime_suspend(local_40), iVar3 == 0)) {
        __pm_runtime_disable(lVar2,1);
        __pm_runtime_set_status(lVar2,2);
        pm_runtime_enable(lVar2);
      }
    }
    uVar5 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_clk_div_get @ 00101110 size=112
// signature: undefined lpass_cdc_tx_macro_clk_div_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_clk_div_get(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  long local_28;
  undefined1 auStack_20 [8];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0;
  uVar2 = lpass_cdc_tx_macro_get_data(param_1,auStack_20,&local_28,"lpass_cdc_tx_macro_clk_div_get")
  ;
  if ((uVar2 & 1) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = (ulong)*(ushort *)(local_28 + 0xa00);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// __lpass_cdc_tx_macro_mclk_enable @ 00101184 size=128
// signature: undefined __lpass_cdc_tx_macro_mclk_enable(void)
// callers: []
//------------------------------------------------------------

void __lpass_cdc_tx_macro_mclk_enable(undefined8 param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uVar2 = lpass_cdc_tx_macro_get_data
                    (param_1,auStack_30,&local_38,"__lpass_cdc_tx_macro_mclk_enable");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = lpass_cdc_tx_macro_mclk_enable(local_38,param_2 & 1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_tx_hpf_corner_freq_callback @ 00101208 size=564
// signature: undefined lpass_cdc_tx_macro_tx_hpf_corner_freq_callback(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_tx_hpf_corner_freq_callback(long param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 *puVar11;
  long local_68;
  undefined1 auStack_60 [8];
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  puVar11 = *(undefined8 **)(param_1 + -0x10);
  local_68 = 0;
  bVar2 = *(byte *)(param_1 + -8);
  bVar3 = *(byte *)(param_1 + -7);
  lVar10 = puVar11[0xf];
  iVar4 = (uint)bVar2 * 0x80;
  iVar1 = iVar4 + 0x404;
  iVar4 = iVar4 + 0x418;
  uVar7 = lpass_cdc_tx_macro_get_data(lVar10,auStack_60,&local_68,"is_amic_enabled");
  if ((((uVar7 & 1) == 0) ||
      (uVar7 = snd_soc_component_read(lVar10,(uint)bVar2 * 8 + 0x104), (uVar7 & 1) == 0)) ||
     (*(char *)(local_68 + 0xab8) != '\0')) {
    snd_soc_component_update_bits(lVar10,iVar1,0x60,(ulong)bVar3 << 5);
    snd_soc_component_update_bits(lVar10,iVar4,2,2);
    usleep_range_state(1000,0x3f2,2);
    uVar8 = 2;
    uVar9 = 0;
  }
  else {
    uVar6 = snd_soc_component_read(lVar10,(uint)*(byte *)(param_1 + -8) * 8 + 0x100);
    lpass_cdc_clear_amic_tx_hold(*(undefined8 *)(lVar10 + 0x18),uVar6 & 0xf);
    snd_soc_component_update_bits(lVar10,iVar1,0x60,(ulong)bVar3 << 5);
    snd_soc_component_update_bits(lVar10,iVar4,3,2);
    if (7 < (ulong)*(byte *)(param_1 + -8)) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10143c);
      (*pcVar5)();
    }
    switch(*(undefined4 *)((long)puVar11 + (ulong)*(byte *)(param_1 + -8) * 4 + 0xa98)) {
    default:
      uVar8 = 0x7d;
      uVar9 = 0x82;
      break;
    case 1:
      uVar8 = 0x3e;
      uVar9 = 0x41;
      break;
    case 3:
      uVar8 = 0x1f;
      uVar9 = 0x20;
      break;
    case 4:
      uVar8 = 0x14;
      uVar9 = 0x15;
      break;
    case 5:
      uVar8 = 10;
      uVar9 = 0xb;
      break;
    case 6:
      uVar8 = 5;
      uVar9 = 6;
    }
    usleep_range_state(uVar8,uVar9,2);
    uVar8 = 3;
    uVar9 = 1;
  }
  snd_soc_component_update_bits(lVar10,iVar4,uVar8,uVar9);
  mutex_lock(puVar11 + 9);
  iVar1 = *(int *)((long)puVar11 + 0xabc) + -1;
  *(int *)((long)puVar11 + 0xabc) = iVar1;
  if (iVar1 == 0) {
    pm_relax(*puVar11);
    iVar1 = *(int *)((long)puVar11 + 0xabc);
  }
  if (iVar1 < 0) {
    *(undefined4 *)((long)puVar11 + 0xabc) = 0;
  }
  mutex_unlock(puVar11 + 9);
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_mute_update_callback @ 00101440 size=128
// signature: undefined lpass_cdc_tx_macro_mute_update_callback(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_mute_update_callback(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + -0x10);
  snd_soc_component_update_bits(puVar2[0xf],(*(uint *)(param_1 + -8) & 0xff) * 0x80 + 0x400,0x10,0);
  mutex_lock(puVar2 + 9);
  iVar1 = *(int *)((long)puVar2 + 0xabc) + -1;
  *(int *)((long)puVar2 + 0xabc) = iVar1;
  if (iVar1 == 0) {
    pm_relax(*puVar2);
    iVar1 = *(int *)((long)puVar2 + 0xabc);
  }
  if (iVar1 < 0) {
    *(undefined4 *)((long)puVar2 + 0xabc) = 0;
  }
  mutex_unlock(puVar2 + 9);
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_enable_micbias @ 001014c4 size=8
// signature: undefined lpass_cdc_tx_macro_enable_micbias(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_tx_macro_enable_micbias(void)

{
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_enable_dec @ 001014d0 size=1752
// signature: undefined lpass_cdc_tx_macro_enable_dec(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lpass_cdc_tx_macro_enable_dec(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 *puVar4;
  byte bVar5;
  int iVar6;
  undefined8 *puVar7;
  code *pcVar8;
  uint uVar9;
  undefined4 uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  int iVar15;
  long lVar16;
  char *pcVar17;
  long lVar18;
  undefined8 *local_88;
  undefined8 uStack_80;
  long local_78;
  undefined1 auStack_70 [8];
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  local_88 = (undefined8 *)0x0;
  uStack_80 = 0;
  lVar16 = *(long *)(param_1 + 0x28) + -0xd0;
  uVar11 = lpass_cdc_tx_macro_get_data(lVar16,&uStack_80,&local_88,"lpass_cdc_tx_macro_enable_dec");
  if ((uVar11 & 1) == 0) {
    uVar13 = 0xffffffea;
    goto switchD_001015f0_caseD_3;
  }
  bVar5 = *(byte *)(param_1 + 0x4c);
  uVar11 = (ulong)bVar5;
  iVar6 = (uint)bVar5 * 0x80;
  iVar15 = iVar6 + 0x400;
  uVar9 = snd_soc_component_read(lVar16,iVar15);
  puVar7 = local_88;
  if (7 < uVar11) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x101ba8);
    (*pcVar8)();
  }
  iVar1 = iVar6 + 0x418;
  iVar2 = iVar6 + 0x404;
  iVar3 = (uint)bVar5 * 8 + 0x104;
  *(uint *)((long)local_88 + uVar11 * 4 + 0xa98) = uVar9 & 0xf;
  local_78 = 0;
  uVar12 = lpass_cdc_tx_macro_get_data(lVar16,auStack_70,&local_78,"is_amic_enabled");
  if ((((uVar12 & 1) == 0) || (uVar12 = snd_soc_component_read(lVar16,iVar3), (uVar12 & 1) == 0)) ||
     (*(char *)(local_78 + 0xab8) != '\0')) {
    lVar18 = *(long *)(param_1 + 0x28) + -0xd0;
    uVar12 = snd_soc_component_read(lVar18,(uint)bVar5 * 8 + 0x100);
    uVar13 = 0;
    uVar14 = 1;
    switch(param_3) {
    case 2:
      goto switchD_001015f0_caseD_2;
    default:
      goto switchD_001015f0_caseD_3;
    case 4:
      goto switchD_001015f0_caseD_4;
    case 8:
      uVar14 = 0;
    case 1:
      lpass_cdc_dmic_clk_enable(lVar18,(int)((uVar12 & 0xffffffff) >> 4) + -1,0,uVar14);
    }
  }
  uVar13 = 0;
  switch(param_3) {
  case 1:
    snd_soc_component_update_bits(lVar16,iVar2,6,*(int *)((long)puVar7 + uVar11 * 4 + 0xa70) << 1);
    uVar13 = 0x10;
    uVar14 = 0x10;
LAB_00101b44:
    snd_soc_component_update_bits(lVar16,iVar15,uVar13,uVar14);
    break;
  case 2:
switchD_001015f0_caseD_2:
    snd_soc_component_update_bits(lVar16,iVar15,0x20,0x20);
    local_78 = 0;
    uVar12 = lpass_cdc_tx_macro_get_data(lVar16,auStack_70,&local_78,"is_amic_enabled");
    if ((((uVar12 & 1) == 0) || (uVar12 = snd_soc_component_read(lVar16,iVar3), (uVar12 & 1) == 0))
       || (*(char *)(local_78 + 0xab8) != '\0')) {
      snd_soc_component_update_bits(lVar16,iVar1,1,0);
      usleep_range_state(1000,0x3f2,2);
    }
    uVar9 = snd_soc_component_read(lVar16,iVar2);
    uVar9 = uVar9 >> 5 & 3;
    pcVar17 = (char *)((long)puVar7 + uVar11 * 0x98 + 0x89);
    *pcVar17 = (char)uVar9;
    if (uVar9 != 2) {
      snd_soc_component_update_bits(lVar16,iVar2,0x60,0x40);
    }
    local_78 = 0;
    uVar12 = lpass_cdc_tx_macro_get_data(lVar16,auStack_70,&local_78,"is_amic_enabled");
    if ((((uVar12 & 1) == 0) || (uVar12 = snd_soc_component_read(lVar16,iVar3), (uVar12 & 1) == 0))
       || (*(char *)(local_78 + 0xab8) != '\0')) {
      iVar15 = 0x28;
    }
    else {
      iVar15 = 100;
    }
    if (tx_unmute_delay < iVar15) {
      tx_unmute_delay = iVar15;
    }
    puVar4 = puVar7 + 9;
    mutex_lock(puVar4);
    iVar15 = *(int *)((long)puVar7 + 0xabc);
    *(int *)((long)puVar7 + 0xabc) = iVar15 + 1;
    if (iVar15 == 0) {
      pm_stay_awake(*puVar7);
    }
    mutex_unlock(puVar4);
    uVar13 = _system_freezable_wq;
    uVar14 = __msecs_to_jiffies(tx_unmute_delay);
    queue_delayed_work_on(0x20,uVar13,puVar7 + uVar11 * 0x13 + 0xaa,uVar14);
    if (*pcVar17 != '\x02') {
      mutex_lock(puVar4);
      iVar15 = *(int *)((long)puVar7 + 0xabc);
      *(int *)((long)puVar7 + 0xabc) = iVar15 + 1;
      if (iVar15 == 0) {
        pm_stay_awake(*puVar7);
      }
      mutex_unlock(puVar4);
      queue_delayed_work_on(0x20,_system_freezable_wq,puVar7 + uVar11 * 0x13 + 0x12,0x4b);
      snd_soc_component_update_bits(lVar16,iVar1,3,2);
      local_78 = 0;
      uVar11 = lpass_cdc_tx_macro_get_data(lVar16,auStack_70,&local_78,"is_amic_enabled");
      if ((((uVar11 & 1) == 0) || (uVar11 = snd_soc_component_read(lVar16,iVar3), (uVar11 & 1) == 0)
          ) || (*(char *)(local_78 + 0xab8) != '\0')) {
        snd_soc_component_update_bits(lVar16,iVar1,3,0);
      }
      snd_soc_component_update_bits(lVar16,iVar1,3,1);
      usleep_range_state(6000,0x177a,2);
    }
    uVar10 = snd_soc_component_read(lVar16,iVar6 + 0x40c);
    snd_soc_component_write(lVar16,iVar6 + 0x40c,uVar10);
    if (*(char *)((long)puVar7 + 0xa6c) != '\0') {
      snd_soc_component_update_bits(lVar16,0x30dc,0xf,*(undefined4 *)(puVar7 + 0x152));
      snd_soc_component_update_bits(lVar16,iVar2,1,1);
      *(undefined1 *)((long)puVar7 + 0xa94) = 1;
      if (*(char *)((long)puVar7 + 0xa95) != '\0') {
        iVar15 = 0x42c;
        uVar13 = 0x40;
        uVar14 = 0x40;
        goto LAB_00101b44;
      }
    }
    break;
  default:
    goto switchD_001015f0_caseD_3;
  case 4:
switchD_001015f0_caseD_4:
    bVar5 = *(byte *)((long)puVar7 + uVar11 * 0x98 + 0x89);
    snd_soc_component_update_bits(lVar16,iVar15,0x10,0x10);
    uVar12 = cancel_delayed_work_sync(puVar7 + uVar11 * 0x13 + 0x12);
    if (((uVar12 & 1) != 0) && (bVar5 != 2)) {
      snd_soc_component_update_bits(lVar16,iVar2,0x60,(ulong)bVar5 << 5);
      local_78 = 0;
      uVar12 = lpass_cdc_tx_macro_get_data(lVar16,auStack_70,&local_78,"is_amic_enabled");
      if (((uVar12 & 1) == 0) ||
         ((uVar12 = snd_soc_component_read(lVar16,iVar3), (uVar12 & 1) == 0 ||
          (*(char *)(local_78 + 0xab8) != '\0')))) {
        uVar13 = 3;
      }
      else {
        uVar13 = 2;
      }
      snd_soc_component_update_bits(lVar16,iVar1,3,uVar13);
      usleep_range_state(1000,0x3f2,2);
      snd_soc_component_update_bits(lVar16,iVar1,3,1);
    }
    puVar4 = puVar7 + 9;
    mutex_lock(puVar4);
    iVar15 = *(int *)((long)puVar7 + 0xabc) + -1;
    *(int *)((long)puVar7 + 0xabc) = iVar15;
    if (iVar15 == 0) {
      pm_relax(*puVar7);
      iVar15 = *(int *)((long)puVar7 + 0xabc);
    }
    if (iVar15 < 0) {
      *(undefined4 *)((long)puVar7 + 0xabc) = 0;
    }
    mutex_unlock(puVar4);
    cancel_delayed_work_sync(puVar7 + uVar11 * 0x13 + 0xaa);
    mutex_lock(puVar4);
    iVar15 = *(int *)((long)puVar7 + 0xabc) + -1;
    *(int *)((long)puVar7 + 0xabc) = iVar15;
    if (iVar15 == 0) {
      pm_relax(*puVar7);
      iVar15 = *(int *)((long)puVar7 + 0xabc);
    }
    if (iVar15 < 0) {
      *(undefined4 *)((long)puVar7 + 0xabc) = 0;
    }
    mutex_unlock(puVar4);
    uVar11 = snd_soc_component_read(lVar16,iVar3);
    if ((uVar11 & 1) != 0) {
      iVar15 = 0x88;
      uVar13 = 1;
LAB_00101b40:
      uVar14 = 0;
      goto LAB_00101b44;
    }
    break;
  case 8:
    snd_soc_component_update_bits(lVar16,iVar15,0x20,0);
    snd_soc_component_update_bits(lVar16,iVar15,0x40,0x40);
    snd_soc_component_update_bits(lVar16,iVar15,0x40,0);
    snd_soc_component_update_bits(lVar16,iVar2,6,0);
    snd_soc_component_update_bits(lVar16,iVar15,0x10,0);
    snd_soc_component_update_bits(lVar16,iVar15,0xf,4);
    if (*(char *)((long)puVar7 + 0xa6c) != '\0') {
      snd_soc_component_update_bits(lVar16,iVar2,1,0);
      snd_soc_component_update_bits(lVar16,0x42c,0x40,0);
      iVar15 = 0x30dc;
      uVar13 = 0xf;
      *(undefined1 *)((long)puVar7 + 0xa94) = 0;
      goto LAB_00101b40;
    }
  }
  uVar13 = 0;
switchD_001015f0_caseD_3:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_mclk_event @ 00101bac size=268
// signature: undefined lpass_cdc_tx_macro_mclk_event(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_mclk_event(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined8 *local_38;
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = (undefined8 *)0x0;
  uVar4 = lpass_cdc_tx_macro_get_data
                    (*(long *)(param_1 + 0x28) + -0xd0,auStack_30,&local_38,
                     "lpass_cdc_tx_macro_mclk_event");
  puVar2 = local_38;
  if ((uVar4 & 1) != 0) {
    if (param_3 == 8) {
      if (*(char *)((long)local_38 + 0x14) == '\0') {
        uVar5 = 0;
      }
      else {
        uVar5 = lpass_cdc_tx_macro_mclk_enable(local_38,0);
      }
      goto LAB_00101c58;
    }
    if (param_3 == 1) {
      uVar5 = lpass_cdc_tx_macro_mclk_enable(local_38,1);
      if ((int)uVar5 == 0) {
        *(undefined1 *)((long)puVar2 + 0x14) = 1;
      }
      else {
        *(undefined1 *)((long)puVar2 + 0x14) = 0;
      }
      goto LAB_00101c58;
    }
    iVar3 = ___ratelimit(lpass_cdc_tx_macro_mclk_event__rs,"lpass_cdc_tx_macro_mclk_event");
    if (iVar3 != 0) {
      _dev_err(*local_38,"%s: invalid DAPM event %d\n","lpass_cdc_tx_macro_mclk_event",param_3);
    }
  }
  uVar5 = 0xffffffea;
LAB_00101c58:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_tx_mixer_get @ 00101cbc size=204
// signature: undefined lpass_cdc_tx_macro_tx_mixer_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_tx_mixer_get(long param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long local_48;
  undefined1 auStack_40 [8];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = snd_soc_dapm_kcontrol_widget();
  bVar2 = *(byte *)(lVar4 + 0x4c);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  local_48 = 0;
  uVar5 = lpass_cdc_tx_macro_get_data
                    (*(long *)(lVar4 + 0x28) + -0xd0,auStack_40,&local_48,
                     "lpass_cdc_tx_macro_tx_mixer_get");
  if ((uVar5 & 1) == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    if (4 < bVar2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101d88);
      (*pcVar3)();
    }
    uVar6 = 0;
    *(ulong *)(param_2 + 0x48) =
         *(ulong *)(local_48 + (ulong)bVar2 * 8 + ((ulong)(uVar1 >> 3) & 0x1ffffff8) + 0xa08) >>
         ((ulong)uVar1 & 0x3f) & 1;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_tx_mixer_put @ 00101d8c size=444
// signature: undefined lpass_cdc_tx_macro_tx_mixer_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_tx_mixer_put(long param_1,long param_2)

{
  long lVar1;
  ulong *puVar2;
  uint uVar3;
  int iVar4;
  byte bVar5;
  char cVar6;
  bool bVar7;
  code *pcVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar11;
  char *pcVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  long local_58 [3];
  
  lVar9 = sp_el0;
  local_58[2] = *(long *)(lVar9 + 0x638);
  lVar9 = snd_soc_dapm_kcontrol_widget();
  lVar15 = *(long *)(lVar9 + 0x28);
  bVar5 = *(byte *)(lVar9 + 0x4c);
  uVar13 = (ulong)bVar5;
  uVar3 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar14 = (ulong)uVar3;
  iVar4 = *(int *)(param_2 + 0x48);
  local_58[0] = 0;
  local_58[1] = 0;
  uVar10 = lpass_cdc_tx_macro_get_data
                     (lVar15 + -0xd0,local_58 + 1,local_58,"lpass_cdc_tx_macro_tx_mixer_put");
  if ((uVar10 & 1) == 0) {
    uVar11 = 0xffffffea;
    goto LAB_00101eb4;
  }
  if (iVar4 == 0) {
    if (4 < bVar5) goto LAB_00101f1c;
    lVar1 = local_58[0] + uVar13 * 8;
    uVar10 = 1L << (uVar14 & 0x3f);
    if ((*(ulong *)(lVar1 + (ulong)(uVar3 >> 6) * 8 + 0xa08) & uVar10) == 0) {
      uVar11 = *(undefined8 *)(lVar15 + -0xb8);
      pcVar12 = "%s: channel is already disabled, dec_id = %d, dai_id = %d\n";
      goto LAB_00101f00;
    }
    *(long *)(lVar1 + 0xa28) = *(long *)(lVar1 + 0xa28) + -1;
    puVar2 = (ulong *)(lVar1 + 0xa08 + (ulong)(uVar3 >> 6) * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar7) {
        *puVar2 = *puVar2 & (uVar10 ^ 0xffffffffffffffff);
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
  }
  else {
    if (4 < bVar5) {
LAB_00101f1c:
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x101f20);
      (*pcVar8)();
    }
    uVar10 = 1L << (uVar14 & 0x3f);
    if ((*(ulong *)(local_58[0] + (ulong)(uint)bVar5 * 8 + (ulong)(uVar3 >> 6) * 8 + 0xa08) & uVar10
        ) == 0) {
      puVar2 = (ulong *)(local_58[0] + uVar13 * 8 + 0xa08 + (ulong)(uVar3 >> 6) * 8);
      Hint_Prefetch(puVar2,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(puVar2,0x10);
        if (bVar7) {
          *puVar2 = *puVar2 | uVar10;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      lVar15 = local_58[0] + uVar13 * 8;
      *(long *)(lVar15 + 0xa28) = *(long *)(lVar15 + 0xa28) + 1;
    }
    else {
      uVar11 = *(undefined8 *)(lVar15 + -0xb8);
      pcVar12 = "%s: channel is already enabled, dec_id = %d, dai_id = %d\n";
LAB_00101f00:
      _dev_err(uVar11,pcVar12,"lpass_cdc_tx_macro_tx_mixer_put",uVar14,(uint)bVar5);
    }
  }
  snd_soc_dapm_mixer_update_power(*(undefined8 *)(lVar9 + 0x28),param_1,iVar4,0);
  uVar11 = 0;
LAB_00101eb4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar11);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_get_data @ 00101f58 size=224
// signature: undefined lpass_cdc_tx_macro_get_data(void)
// callers: [lpass_cdc_tx_macro_dec_mode_put, lpass_cdc_tx_macro_get_channel_map, lpass_cdc_tx_macro_dec_mode_get, lpass_cdc_tx_macro_event_handler, lpass_cdc_tx_macro_mclk_event, lpass_cdc_tx_macro_swr_dmic_put, lpass_cdc_tx_macro_hw_params, lpass_cdc_tx_macro_bcs_ch_put, __lpass_cdc_tx_macro_mclk_enable, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback, lpass_cdc_tx_macro_set_bcs, lpass_cdc_tx_macro_bcs_ch_get, lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_get_bcs_ch_sel, lpass_cdc_tx_macro_swr_dmic_get, lpass_cdc_tx_macro_clk_div_get, lpass_cdc_tx_macro_get_bcs, lpass_cdc_tx_macro_tx_mixer_get, lpass_cdc_tx_macro_put_bcs_ch_sel, lpass_cdc_tx_macro_put_dec_enum, lpass_cdc_tx_macro_deinit, lpass_cdc_tx_macro_tx_mixer_put]
//------------------------------------------------------------

undefined8 lpass_cdc_tx_macro_get_data(long param_1,long *param_2,long *param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  lVar1 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),0);
  *param_2 = lVar1;
  if (lVar1 == 0) {
    uVar2 = ___ratelimit(lpass_cdc_tx_macro_get_data__rs,"lpass_cdc_tx_macro_get_data");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar1 = *(long *)(lVar1 + 0x98);
    *param_3 = lVar1;
    if (lVar1 == 0) {
      uVar2 = ___ratelimit(lpass_cdc_tx_macro_get_data__rs_78,"lpass_cdc_tx_macro_get_data");
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      pcVar3 = "%s: priv is null for macro!\n";
    }
    else {
      if (*(long *)(lVar1 + 0x78) != 0) {
        return 1;
      }
      uVar2 = ___ratelimit(lpass_cdc_tx_macro_get_data__rs_79,"lpass_cdc_tx_macro_get_data");
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      pcVar3 = "%s: tx_priv->component not initialized!\n";
    }
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,param_4);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_put_dec_enum @ 0010203c size=456
// signature: undefined lpass_cdc_tx_macro_put_dec_enum(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_put_dec_enum(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  size_t sVar5;
  undefined8 uVar6;
  uint uVar7;
  long lVar8;
  int *piVar9;
  char *__s;
  long lVar10;
  long local_68;
  undefined1 auStack_60 [8];
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  lVar3 = snd_soc_dapm_kcontrol_widget();
  lVar10 = *(long *)(lVar3 + 0x28);
  lVar8 = lVar10 + -0xd0;
  piVar9 = *(int **)(param_1 + 0x78);
  local_68 = 0;
  uVar4 = lpass_cdc_tx_macro_get_data(lVar8,auStack_60,&local_68,"lpass_cdc_tx_macro_put_dec_enum");
  if (((uVar4 & 1) != 0) && (uVar1 = *(uint *)(param_2 + 0x48), uVar1 <= piVar9[2] - 1U)) {
    uVar7 = (uint)(CONCAT44(*piVar9,*piVar9 + -0x100) >> 3);
    if (uVar7 < 8) {
      __s = *(char **)(lVar3 + 8);
      uVar7 = uVar7 * 0x80 + 0x404;
      sVar5 = strlen(__s);
      lVar10 = strnstr(__s,&DAT_0011001b,sVar5);
      lVar3 = local_68;
      if (lVar10 == 0) {
        if (uVar1 != 0) {
          uVar6 = 0x80;
          lVar3 = 0x80;
          goto LAB_001021c8;
        }
      }
      else if (uVar1 != 0) {
        if (*(char *)(local_68 + 0xab8) == '\0') {
          uVar6 = 0x80;
          lVar3 = 0;
        }
        else {
          snd_soc_component_update_bits(lVar8,uVar7,0x80,0x80);
          snd_soc_component_update_bits(lVar8,0x3094,0x80,0);
          uVar7 = uVar1 * 2 + 0xc6 & 0xfffc;
          uVar6 = 0xe;
          lVar3 = (ulong)*(ushort *)(lVar3 + 0xa00) << 1;
        }
LAB_001021c8:
        snd_soc_component_update_bits(lVar8,uVar7,uVar6,lVar3);
      }
      uVar6 = snd_soc_dapm_put_enum_double(param_1,param_2);
      goto LAB_0010216c;
    }
    iVar2 = ___ratelimit(lpass_cdc_tx_macro_put_dec_enum__rs,"lpass_cdc_tx_macro_put_dec_enum");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(lVar10 + -0xb8),"%s: e->reg: 0x%x not expected\n",
               "lpass_cdc_tx_macro_put_dec_enum",*piVar9);
      uVar6 = 0xffffffea;
      goto LAB_0010216c;
    }
  }
  uVar6 = 0xffffffea;
LAB_0010216c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_mclk_enable @ 00102204 size=556
// signature: undefined lpass_cdc_tx_macro_mclk_enable(void)
// callers: [lpass_cdc_tx_macro_mclk_event, __lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

int lpass_cdc_tx_macro_mclk_enable(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_tx_macro_mclk_enable__rs,"lpass_cdc_tx_macro_mclk_enable");
    if (iVar1 == 0) {
      iVar1 = -0x16;
    }
    else {
      _dev_err(*param_1,"%s: regmap is NULL\n","lpass_cdc_tx_macro_mclk_enable");
      iVar1 = -0x16;
    }
  }
  else {
    mutex_lock(param_1 + 3);
    if ((param_2 & 1) == 0) {
      if ((int)param_1[2] < 1) {
        iVar1 = ___ratelimit(lpass_cdc_tx_macro_mclk_enable__rs_153,"lpass_cdc_tx_macro_mclk_enable"
                            );
        if (iVar1 != 0) {
          _dev_err(*param_1,"%s: clock already disabled\n","lpass_cdc_tx_macro_mclk_enable");
        }
        iVar1 = 0;
        *(undefined4 *)(param_1 + 2) = 0;
      }
      else {
        iVar1 = (int)param_1[2] + -1;
        *(int *)(param_1 + 2) = iVar1;
        if (iVar1 == 0) {
          regmap_update_bits_base(lVar3,4,1,0,0,0,0);
          regmap_update_bits_base(lVar3,0,1,0,0,0,0);
        }
        lpass_cdc_clk_rsc_fs_gen_request(*param_1,0);
        lpass_cdc_clk_rsc_request_clock(*param_1,0,0,0);
        iVar1 = 0;
      }
    }
    else {
      iVar1 = lpass_cdc_clk_rsc_request_clock(*param_1,0,0,1);
      if (iVar1 < 0) {
        iVar2 = ___ratelimit(lpass_cdc_tx_macro_mclk_enable__rs_151,"lpass_cdc_tx_macro_mclk_enable"
                            );
        if (iVar2 != 0) {
          _dev_err(*param_1,"%s: request clock enable failed\n","lpass_cdc_tx_macro_mclk_enable");
        }
      }
      else {
        lpass_cdc_clk_rsc_fs_gen_request(*param_1,1);
        regcache_mark_dirty(lVar3);
        regcache_sync_region(lVar3,0,0x7a8);
        iVar2 = (int)param_1[2];
        if (iVar2 == 0) {
          regmap_update_bits_base(lVar3,0,1,1,0,0,0);
          regmap_update_bits_base(lVar3,4,1,1,0,0,0);
          iVar2 = (int)param_1[2];
        }
        *(int *)(param_1 + 2) = iVar2 + 1;
      }
    }
    mutex_unlock(param_1 + 3);
  }
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_dec_mode_get @ 00102434 size=180
// signature: undefined lpass_cdc_tx_macro_dec_mode_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_dec_mode_get(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  undefined8 uVar4;
  uint local_3c;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_3c = 0;
  uVar3 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_dec_mode_get");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar4 = lpass_cdc_tx_macro_path_get(param_1 + 0x20,&local_3c);
    if ((int)uVar4 == 0) {
      if (7 < local_3c) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1024e8);
        (*pcVar2)();
      }
      uVar4 = 0;
      *(long *)(param_2 + 0x48) = (long)*(int *)(local_30 + (ulong)local_3c * 4 + 0xa70);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_dec_mode_put @ 001024ec size=176
// signature: undefined lpass_cdc_tx_macro_dec_mode_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_dec_mode_put(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint local_3c;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  local_3c = 0;
  uVar4 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_dec_mode_put");
  if ((uVar4 & 1) == 0) {
    uVar5 = 0xffffffea;
  }
  else {
    uVar5 = lpass_cdc_tx_macro_path_get(param_1 + 0x20,&local_3c);
    if ((int)uVar5 == 0) {
      if (7 < local_3c) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10259c);
        (*pcVar3)();
      }
      uVar5 = 0;
      *(undefined4 *)(local_30 + (ulong)local_3c * 4 + 0xa70) = uVar1;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_get_bcs @ 001025a0 size=136
// signature: undefined lpass_cdc_tx_macro_get_bcs(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_get_bcs(long param_1,long param_2)

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
  uVar2 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_get_bcs");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_30 + 0xa6c);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_set_bcs @ 0010262c size=140
// signature: undefined lpass_cdc_tx_macro_set_bcs(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_set_bcs(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  iVar1 = *(int *)(param_2 + 0x48);
  uVar3 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_set_bcs");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar4 = 0;
    *(bool *)(local_30 + 0xa6c) = iVar1 != 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_swr_dmic_get @ 001026bc size=136
// signature: undefined lpass_cdc_tx_macro_swr_dmic_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_swr_dmic_get(long param_1,long param_2)

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
  uVar2 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_swr_dmic_get");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(local_30 + 0xab8);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_swr_dmic_put @ 00102748 size=140
// signature: undefined lpass_cdc_tx_macro_swr_dmic_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_swr_dmic_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  iVar1 = *(int *)(param_2 + 0x48);
  uVar3 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_swr_dmic_put");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar4 = 0;
    *(bool *)(local_30 + 0xab8) = iVar1 != 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_bcs_ch_get @ 001027d8 size=136
// signature: undefined lpass_cdc_tx_macro_bcs_ch_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_bcs_ch_get(long param_1,long param_2)

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
  uVar2 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_bcs_ch_get");
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = 0;
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(local_30 + 0xa90);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_bcs_ch_put @ 00102864 size=132
// signature: undefined lpass_cdc_tx_macro_bcs_ch_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_bcs_ch_put(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 auStack_38 [8];
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  uVar3 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x80),auStack_38,&local_30,
                     "lpass_cdc_tx_macro_bcs_ch_put");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar4 = 0;
    *(undefined4 *)(local_30 + 0xa90) = uVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_get_bcs_ch_sel @ 001028ec size=144
// signature: undefined lpass_cdc_tx_macro_get_bcs_ch_sel(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_get_bcs_ch_sel(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x80);
  uVar3 = lpass_cdc_tx_macro_get_data
                    (uVar4,auStack_38,auStack_30,"lpass_cdc_tx_macro_get_bcs_ch_sel");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar2 = snd_soc_component_read(uVar4,0x30dc);
    uVar4 = 0;
    *(ulong *)(param_2 + 0x48) = (ulong)(uVar2 & 0xf);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_put_bcs_ch_sel @ 00102980 size=152
// signature: undefined lpass_cdc_tx_macro_put_bcs_ch_sel(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_put_bcs_ch_sel(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined1 auStack_38 [8];
  undefined1 auStack_30 [8];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x80);
  uVar2 = lpass_cdc_tx_macro_get_data
                    (uVar3,auStack_38,auStack_30,"lpass_cdc_tx_macro_put_bcs_ch_sel");
  if (((uVar2 & 1) == 0) || (0xc < *(ulong *)(param_2 + 0x48))) {
    uVar3 = 0xffffffea;
  }
  else {
    snd_soc_component_update_bits(uVar3,0x30dc,0xf);
    uVar3 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_path_get @ 00102a18 size=336
// signature: undefined lpass_cdc_tx_macro_path_get(void)
// callers: [lpass_cdc_tx_macro_dec_mode_put, lpass_cdc_tx_macro_dec_mode_get]
//------------------------------------------------------------

int lpass_cdc_tx_macro_path_get(undefined8 param_1,undefined8 param_2)

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
  pcVar4 = (char *)kstrndup(param_1,10,0xcc0);
  local_30 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    iVar2 = -0x16;
    goto LAB_00102b20;
  }
  pcVar5 = strsep(&local_30," ");
  if (pcVar5 == (char *)0x0) {
    iVar2 = ___ratelimit(lpass_cdc_tx_macro_path_get__rs,"lpass_cdc_tx_macro_path_get");
    if (iVar2 != 0) {
      _printk(&DAT_0010fb6b,"lpass_cdc_tx_macro_path_get",local_30);
    }
LAB_00102b14:
    iVar2 = -0x16;
  }
  else {
    pcVar5 = strpbrk(pcVar5,"01234567");
    if (pcVar5 == (char *)0x0) {
      iVar2 = ___ratelimit(lpass_cdc_tx_macro_path_get__rs_196,"lpass_cdc_tx_macro_path_get");
      if (iVar2 != 0) {
        _printk(&DAT_0010fcf9,"lpass_cdc_tx_macro_path_get");
      }
      goto LAB_00102b14;
    }
    iVar2 = kstrtouint(pcVar5,10,param_2);
    if ((iVar2 < 0) &&
       (iVar3 = ___ratelimit(lpass_cdc_tx_macro_path_get__rs_198,"lpass_cdc_tx_macro_path_get"),
       iVar3 != 0)) {
      _printk(&DAT_0010fb8b,"lpass_cdc_tx_macro_path_get",pcVar4);
    }
  }
  kfree(pcVar4);
LAB_00102b20:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// lpass_cdc_tx_macro_get_channel_map @ 00102b6c size=260
// signature: undefined lpass_cdc_tx_macro_get_channel_map(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_get_channel_map(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  undefined8 uVar4;
  long local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_40 = 0;
  uVar3 = lpass_cdc_tx_macro_get_data
                    (*(undefined8 *)(param_1 + 0x58),&local_40,&local_48,
                     "lpass_cdc_tx_macro_get_channel_map");
  if ((uVar3 & 1) == 0) {
    uVar4 = 0xffffffea;
  }
  else if (*(uint *)(param_1 + 8) - 1 < 3) {
    *param_3 = (int)*(undefined8 *)(local_48 + (ulong)*(uint *)(param_1 + 8) * 8 + 0xa08);
    if (3 < *(uint *)(param_1 + 8)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102c70);
      (*pcVar2)();
    }
    uVar4 = 0;
    *param_2 = (int)*(undefined8 *)(local_48 + (ulong)*(uint *)(param_1 + 8) * 8 + 0xa28);
  }
  else {
    uVar4 = ___ratelimit(lpass_cdc_tx_macro_get_channel_map__rs,"lpass_cdc_tx_macro_get_channel_map"
                        );
    if ((int)uVar4 != 0) {
      _dev_err(local_40,"%s: Invalid AIF\n","lpass_cdc_tx_macro_get_channel_map");
      uVar4 = 0;
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
// lpass_cdc_tx_macro_hw_params @ 00102c74 size=512
// signature: undefined lpass_cdc_tx_macro_hw_params(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_tx_macro_hw_params(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  long local_68;
  undefined1 auStack_60 [8];
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  lVar7 = *(long *)(param_3 + 0x58);
  local_68 = 0;
  uVar6 = lpass_cdc_tx_macro_get_data(lVar7,auStack_60,&local_68,"lpass_cdc_tx_macro_hw_params");
  lVar3 = local_68;
  if ((uVar6 & 1) != 0) {
    iVar5 = *(int *)(param_2 + 0x128);
    if (iVar5 < 48000) {
      if (iVar5 == 8000) {
        uVar8 = 0;
LAB_00102d80:
        uVar1 = *(uint *)(param_3 + 8);
        if (uVar1 < 5) {
          uVar6 = 0;
          do {
            if (7 < uVar6) {
LAB_00102df8:
              uVar8 = 0;
              goto LAB_00102e1c;
            }
            uVar1 = (uint)(-1L << (uVar6 & 0x3f)) & *(uint *)(lVar3 + (ulong)uVar1 * 8 + 0xa08);
            uVar6 = ((ulong)uVar1 & 0xaa) >> 1 | ((ulong)uVar1 & 0x55) << 1;
            uVar2 = (uVar6 & 0xcccccccccccccccc) >> 2 | (uVar6 & 0x3333333333333333) << 2;
            uVar6 = 8;
            if ((uVar1 & 0xff) != 0) {
              uVar6 = LZCOUNT((uVar2 >> 4 | (uVar2 & 0xf0f0f0f0f0f0f0f) << 4) << 0x38);
            }
            if (7 < uVar6) goto LAB_00102df8;
            snd_soc_component_update_bits(lVar7,(int)uVar6 * 0x80 + 0x400,0xf,uVar8);
            uVar1 = *(uint *)(param_3 + 8);
            uVar6 = uVar6 + 1;
          } while (uVar1 < 5);
        }
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102df8);
        (*pcVar4)();
      }
      if (iVar5 == 16000) {
        uVar8 = 1;
        goto LAB_00102d80;
      }
      if (iVar5 == 32000) {
        uVar8 = 3;
        goto LAB_00102d80;
      }
    }
    else if (iVar5 < 0x2ee00) {
      if (iVar5 == 48000) {
        uVar8 = 4;
        goto LAB_00102d80;
      }
      if (iVar5 == 96000) {
        uVar8 = 5;
        goto LAB_00102d80;
      }
    }
    else {
      if (iVar5 == 0x2ee00) {
        uVar8 = 6;
        goto LAB_00102d80;
      }
      if (iVar5 == 0x5dc00) {
        uVar8 = 7;
        goto LAB_00102d80;
      }
    }
    iVar5 = ___ratelimit(lpass_cdc_tx_macro_hw_params__rs,"lpass_cdc_tx_macro_hw_params");
    if (iVar5 != 0) {
      _dev_err(*(undefined8 *)(lVar7 + 0x18),"%s: Invalid TX sample rate: %d\n",
               "lpass_cdc_tx_macro_hw_params",*(undefined4 *)(param_2 + 0x128));
    }
  }
  uVar8 = 0xffffffea;
LAB_00102e1c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00102e78 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpass_cdc_tx_macro_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102ea8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpass_cdc_tx_macro_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00112000 size=1
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
// platform_driver_unregister @ 00112008 size=1
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
// lpass_cdc_is_va_macro_registered @ 00112010 size=1
// signature: undefined lpass_cdc_is_va_macro_registered(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_is_va_macro_registered(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00112018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00112020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00112028 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00112030 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_cdc_tx_macro_init, lpass_cdc_tx_macro_get_channel_map, lpass_cdc_tx_macro_mclk_event, lpass_cdc_tx_macro_get_data, lpass_cdc_tx_macro_probe, lpass_cdc_tx_macro_put_dec_enum, lpass_cdc_tx_macro_mclk_enable, lpass_cdc_tx_macro_tx_mixer_put, lpass_cdc_tx_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00112038 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_register_macro @ 00112040 size=1
// signature: undefined lpass_cdc_register_macro(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_register_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00112048 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 00112050 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00112058 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpass_cdc_tx_macro_remove, lpass_cdc_tx_macro_event_handler, lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00112060 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpass_cdc_tx_macro_event_handler, lpass_cdc_tx_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00112068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_cdc_tx_macro_dec_mode_put, lpass_cdc_tx_macro_get_channel_map, lpass_cdc_tx_macro_dec_mode_get, lpass_cdc_tx_macro_event_handler, lpass_cdc_tx_macro_mclk_event, lpass_cdc_tx_macro_swr_dmic_put, lpass_cdc_tx_macro_probe, lpass_cdc_tx_macro_hw_params, lpass_cdc_tx_macro_bcs_ch_put, __lpass_cdc_tx_macro_mclk_enable, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback, lpass_cdc_tx_macro_set_bcs, lpass_cdc_tx_macro_bcs_ch_get, lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_get_bcs_ch_sel, lpass_cdc_tx_macro_swr_dmic_get, lpass_cdc_tx_macro_clk_div_get, lpass_cdc_tx_macro_path_get, lpass_cdc_tx_macro_get_bcs, lpass_cdc_tx_macro_tx_mixer_get, lpass_cdc_tx_macro_put_bcs_ch_sel, lpass_cdc_tx_macro_put_dec_enum, lpass_cdc_tx_macro_deinit, lpass_cdc_tx_macro_tx_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00112070 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpass_cdc_tx_macro_remove, lpass_cdc_tx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_unregister_macro @ 00112078 size=1
// signature: undefined lpass_cdc_unregister_macro(void)
// callers: [lpass_cdc_tx_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_unregister_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_device_ptr @ 00112080 size=1
// signature: undefined lpass_cdc_get_device_ptr(void)
// callers: [lpass_cdc_tx_macro_init, lpass_cdc_tx_macro_get_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_device_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_version @ 00112088 size=1
// signature: undefined lpass_cdc_get_version(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 00112090 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 00112098 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_widgets @ 001120a0 size=1
// signature: undefined snd_soc_dapm_new_widgets(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_widgets(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 001120a8 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 001120b0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 001120b8 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001120c8 size=1
// signature: undefined init_timer_key(void)
// callers: [lpass_cdc_tx_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 001120d0 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [lpass_cdc_tx_macro_mute_update_callback, lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_init, lpass_cdc_tx_macro_event_handler, lpass_cdc_tx_macro_put_bcs_ch_sel, lpass_cdc_tx_macro_put_dec_enum, lpass_cdc_tx_macro_hw_params, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_runtime_suspend @ 001120d8 size=1
// signature: undefined lpass_cdc_runtime_suspend(void)
// callers: [lpass_cdc_tx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_rsc_clk_reset @ 001120e0 size=1
// signature: undefined lpass_cdc_rsc_clk_reset(void)
// callers: [lpass_cdc_tx_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_rsc_clk_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 001120e8 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_get_bcs_ch_sel, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001120f0 size=1
// signature: undefined usleep_range_state(void)
// callers: [lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001120f8 size=1
// signature: undefined mutex_lock(void)
// callers: [lpass_cdc_tx_macro_mute_update_callback, lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_mclk_enable, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00112100 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpass_cdc_tx_macro_mute_update_callback, lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_mclk_enable, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 00112108 size=1
// signature: undefined pm_relax(void)
// callers: [lpass_cdc_tx_macro_mute_update_callback, lpass_cdc_tx_macro_enable_dec, lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clear_amic_tx_hold @ 00112110 size=1
// signature: undefined lpass_cdc_clear_amic_tx_hold(void)
// callers: [lpass_cdc_tx_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clear_amic_tx_hold(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_dmic_clk_enable @ 00112118 size=1
// signature: undefined lpass_cdc_dmic_clk_enable(void)
// callers: [lpass_cdc_tx_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_dmic_clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00112120 size=1
// signature: undefined pm_stay_awake(void)
// callers: [lpass_cdc_tx_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00112130 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [lpass_cdc_tx_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00112138 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [lpass_cdc_tx_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 00112140 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [lpass_cdc_tx_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00112148 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [lpass_cdc_tx_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00112150 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_cdc_tx_macro_get_channel_map, lpass_cdc_tx_macro_mclk_event, lpass_cdc_tx_macro_path_get, lpass_cdc_tx_macro_get_data, lpass_cdc_tx_macro_put_dec_enum, lpass_cdc_tx_macro_mclk_enable, lpass_cdc_tx_macro_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_kcontrol_widget @ 00112158 size=1
// signature: undefined snd_soc_dapm_kcontrol_widget(void)
// callers: [lpass_cdc_tx_macro_tx_mixer_get, lpass_cdc_tx_macro_put_dec_enum, lpass_cdc_tx_macro_tx_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_kcontrol_widget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mixer_update_power @ 00112168 size=1
// signature: undefined snd_soc_dapm_mixer_update_power(void)
// callers: [lpass_cdc_tx_macro_tx_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mixer_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00112170 size=1
// signature: size_t strlen(char * __s)
// callers: [lpass_cdc_tx_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00112178 size=1
// signature: undefined strnstr(void)
// callers: [lpass_cdc_tx_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_put_enum_double @ 00112180 size=1
// signature: undefined snd_soc_dapm_put_enum_double(void)
// callers: [lpass_cdc_tx_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_put_enum_double(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00112188 size=1
// signature: undefined dev_get_regmap(void)
// callers: [lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_request_clock @ 00112190 size=1
// signature: undefined lpass_cdc_clk_rsc_request_clock(void)
// callers: [lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_request_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_fs_gen_request @ 00112198 size=1
// signature: undefined lpass_cdc_clk_rsc_fs_gen_request(void)
// callers: [lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_fs_gen_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 001121a0 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync_region @ 001121a8 size=1
// signature: undefined regcache_sync_region(void)
// callers: [lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001121b0 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [lpass_cdc_tx_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 001121b8 size=1
// signature: undefined kstrndup(void)
// callers: [lpass_cdc_tx_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 001121c0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [lpass_cdc_tx_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 001121c8 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [lpass_cdc_tx_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001121d0 size=1
// signature: undefined kstrtouint(void)
// callers: [lpass_cdc_tx_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001121d8 size=1
// signature: undefined _printk(void)
// callers: [lpass_cdc_tx_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001121e0 size=1
// signature: undefined kfree(void)
// callers: [lpass_cdc_tx_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



