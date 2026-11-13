// Decompiled by Ghidra 12.2
// Program: wsa883x_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wsa883x_codec_info_create_codec_entry @ 00100bb4 size=408
// signature: undefined wsa883x_codec_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

void wsa883x_codec_info_create_codec_entry(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  char local_88 [80];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  uVar2 = 0xffffffea;
  local_88[0x40] = '\0';
  local_88[0x41] = '\0';
  local_88[0x42] = '\0';
  local_88[0x43] = '\0';
  local_88[0x44] = '\0';
  local_88[0x45] = '\0';
  local_88[0x46] = '\0';
  local_88[0x47] = '\0';
  local_88[0x48] = '\0';
  local_88[0x49] = '\0';
  local_88[0x4a] = '\0';
  local_88[0x4b] = '\0';
  local_88[0x4c] = '\0';
  local_88[0x4d] = '\0';
  local_88[0x4e] = '\0';
  local_88[0x4f] = '\0';
  local_88[0x30] = '\0';
  local_88[0x31] = '\0';
  local_88[0x32] = '\0';
  local_88[0x33] = '\0';
  local_88[0x34] = '\0';
  local_88[0x35] = '\0';
  local_88[0x36] = '\0';
  local_88[0x37] = '\0';
  local_88[0x38] = '\0';
  local_88[0x39] = '\0';
  local_88[0x3a] = '\0';
  local_88[0x3b] = '\0';
  local_88[0x3c] = '\0';
  local_88[0x3d] = '\0';
  local_88[0x3e] = '\0';
  local_88[0x3f] = '\0';
  local_88[0x20] = '\0';
  local_88[0x21] = '\0';
  local_88[0x22] = '\0';
  local_88[0x23] = '\0';
  local_88[0x24] = '\0';
  local_88[0x25] = '\0';
  local_88[0x26] = '\0';
  local_88[0x27] = '\0';
  local_88[0x28] = '\0';
  local_88[0x29] = '\0';
  local_88[0x2a] = '\0';
  local_88[0x2b] = '\0';
  local_88[0x2c] = '\0';
  local_88[0x2d] = '\0';
  local_88[0x2e] = '\0';
  local_88[0x2f] = '\0';
  local_88[0x10] = '\0';
  local_88[0x11] = '\0';
  local_88[0x12] = '\0';
  local_88[0x13] = '\0';
  local_88[0x14] = '\0';
  local_88[0x15] = '\0';
  local_88[0x16] = '\0';
  local_88[0x17] = '\0';
  local_88[0x18] = '\0';
  local_88[0x19] = '\0';
  local_88[0x1a] = '\0';
  local_88[0x1b] = '\0';
  local_88[0x1c] = '\0';
  local_88[0x1d] = '\0';
  local_88[0x1e] = '\0';
  local_88[0x1f] = '\0';
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\0';
  local_88[4] = '\0';
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_88[8] = '\0';
  local_88[9] = '\0';
  local_88[10] = '\0';
  local_88[0xb] = '\0';
  local_88[0xc] = '\0';
  local_88[0xd] = '\0';
  local_88[0xe] = '\0';
  local_88[0xf] = '\0';
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (*(long *)(lVar5 + 0x90) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      snprintf(local_88,0x50,"%s.%llx","wsa883x",*(ulonglong *)(*(long *)(lVar5 + 0x10) + 0x3d8));
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),local_88,param_1);
      *(long *)(lVar5 + 0x90) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0x90));
        if ((-1 < iVar1) &&
           (lVar3 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"version",*(undefined8 *)(lVar5 + 0x90)
                              ), lVar3 != 0)) {
          *(long *)(lVar3 + 0x40) = lVar5;
          *(undefined8 *)(lVar3 + 0x10) = 0x20;
          *(undefined2 *)(lVar3 + 0x18) = 1;
          *(undefined1 **)(lVar3 + 0x20) = &wsa883x_codec_info_ops;
          iVar1 = snd_info_register();
          if (-1 < iVar1) {
            *(long *)(lVar5 + 0x98) = lVar3;
            lVar4 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"variant",*(undefined8 *)(lVar5 + 0x90)
                              );
            if (lVar4 != 0) {
              *(long *)(lVar4 + 0x40) = lVar5;
              *(undefined8 *)(lVar4 + 0x10) = 0x20;
              *(undefined2 *)(lVar4 + 0x18) = 1;
              *(undefined1 **)(lVar4 + 0x20) = wsa883x_variant_ops;
              iVar1 = snd_info_register();
              if (-1 < iVar1) {
                uVar2 = 0;
                *(long *)(lVar5 + 0xa0) = lVar4;
                goto LAB_00100d1c;
              }
              snd_info_free_entry(lVar4);
            }
          }
          snd_info_free_entry(lVar3);
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0x90));
      }
      uVar2 = 0xfffffff4;
    }
    else {
      uVar2 = 0;
    }
  }
LAB_00100d1c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_codec_get_dev_num @ 00100d50 size=76
// signature: undefined wsa883x_codec_get_dev_num(void)
// callers: []
//------------------------------------------------------------

ulong wsa883x_codec_get_dev_num(long param_1)

{
  long lVar1;
  
  if (param_1 != 0) {
    lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar1 != 0) {
      return (ulong)*(byte *)(*(long *)(lVar1 + 0x10) + 0x40);
    }
    _printk(&DAT_00108c62,"wsa883x_codec_get_dev_num");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wsa883x_set_channel_map @ 00100da0 size=388
// signature: undefined wsa883x_set_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
wsa883x_set_channel_map
          (long param_1,undefined1 *param_2,byte param_3,undefined4 *param_4,undefined4 *param_5,
          undefined1 *param_6)

{
  undefined1 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((((param_3 < 5) && (param_2 != (undefined1 *)0x0)) && (param_4 != (undefined4 *)0x0)) &&
     (param_5 != (undefined4 *)0x0)) {
    if (param_3 != 0) {
      lVar3 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
      *(undefined1 *)(lVar3 + 0x24) = *param_2;
      *(char *)(lVar3 + 0x25) = (char)*param_4;
      *(undefined4 *)(lVar3 + 0x28) = *param_5;
      uVar1 = __sw_hweight8(*param_4);
      *(undefined1 *)(lVar3 + 0x2c) = uVar1;
      if (param_6 != (undefined1 *)0x0) {
        *(undefined1 *)(lVar3 + 0x2d) = *param_6;
      }
      if (param_3 != 1) {
        *(undefined1 *)(lVar3 + 0x30) = param_2[1];
        *(char *)(lVar3 + 0x31) = (char)param_4[1];
        *(undefined4 *)(lVar3 + 0x34) = param_5[1];
        uVar1 = __sw_hweight8(param_4[1]);
        *(undefined1 *)(lVar3 + 0x38) = uVar1;
        if (param_6 != (undefined1 *)0x0) {
          *(undefined1 *)(lVar3 + 0x39) = param_6[1];
        }
        if (param_3 != 2) {
          *(undefined1 *)(lVar3 + 0x3c) = param_2[2];
          *(char *)(lVar3 + 0x3d) = (char)param_4[2];
          *(undefined4 *)(lVar3 + 0x40) = param_5[2];
          uVar1 = __sw_hweight8(param_4[2]);
          *(undefined1 *)(lVar3 + 0x44) = uVar1;
          if (param_6 != (undefined1 *)0x0) {
            *(undefined1 *)(lVar3 + 0x45) = param_6[2];
          }
          if (param_3 != 3) {
            *(undefined1 *)(lVar3 + 0x48) = param_2[3];
            *(char *)(lVar3 + 0x49) = (char)param_4[3];
            *(undefined4 *)(lVar3 + 0x4c) = param_5[3];
            uVar1 = __sw_hweight8(param_4[3]);
            *(undefined1 *)(lVar3 + 0x50) = uVar1;
            if (param_6 != (undefined1 *)0x0) {
              *(undefined1 *)(lVar3 + 0x51) = param_6[3];
              return 0;
            }
          }
        }
      }
    }
    uVar2 = 0;
  }
  else {
    _dev_err(*(long *)(param_1 + 0x18),"%s: Invalid port=%pK, ch_mask=%pK, ch_rate=%pK\n",
             "wsa883x_set_channel_map",param_2,param_4,param_5);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// wsa883x_codec_version_read @ 00100f28 size=232
// signature: undefined wsa883x_codec_version_read(void)
// callers: []
//------------------------------------------------------------

void wsa883x_codec_version_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 uVar5;
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
    _printk(&DAT_00109175,"wsa883x_codec_version_read");
    uVar4 = 0xffffffffffffffea;
    goto LAB_00100fcc;
  }
  iVar1 = *(int *)(*(long *)(param_1 + 0x40) + 0xbc);
  if (iVar1 == 1) {
    puVar3 = (undefined8 *)&DAT_001090ab;
LAB_00100f80:
    uVar5 = *(undefined8 *)((long)puVar3 + 5);
    uVar4 = 0xc;
    local_38 = (undefined5)*puVar3;
    uStack_33 = (undefined2)uVar5;
    cStack_31 = (char)((ulong)uVar5 >> 0x10);
    local_30 = (undefined5)((ulong)uVar5 >> 0x18);
  }
  else {
    if (iVar1 == 0) {
      puVar3 = (undefined8 *)&DAT_001092ca;
      goto LAB_00100f80;
    }
    uVar4 = 0xe;
    local_38 = s_VER_UNDEFINED_0010907a._0_5_;
    uStack_33 = s_VER_UNDEFINED_0010907a._5_2_;
    cStack_31 = s_VER_UNDEFINED_0010907a[7];
    local_30 = s_VER_UNDEFINED_0010907a._8_5_;
    uStack_2b = s_VER_UNDEFINED_0010907a._13_2_;
  }
  uVar4 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,uVar4);
LAB_00100fcc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_variant_read @ 00101014 size=264
// signature: undefined wsa883x_variant_read(void)
// callers: []
//------------------------------------------------------------

void wsa883x_variant_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 local_40;
  undefined7 local_38;
  char cStack_31;
  undefined1 uStack_30;
  undefined2 uStack_2f;
  undefined5 uStack_2d;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  cStack_31 = '\0';
  local_28 = 0;
  uStack_20 = 0;
  uStack_30 = 0;
  uStack_2f = 0;
  uStack_2d = 0;
  local_40 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    _printk(&DAT_00109175,"wsa883x_variant_read");
    uVar3 = 0xffffffffffffffea;
    goto LAB_001010d8;
  }
  switch(*(undefined4 *)(*(long *)(param_1 + 0x40) + 0xb8)) {
  case 0:
    pcVar2 = "WSA8830\n";
    break;
  case 1:
  case 5:
    pcVar2 = "WSA8835\n";
    break;
  case 2:
    pcVar2 = "WSA8832\n";
    break;
  default:
    uVar3 = 10;
    uStack_30 = 0x44;
    uStack_2f = 10;
    local_38 = s_UNDEFINED_001091dd._0_7_;
    cStack_31 = s_UNDEFINED_001091dd[7];
    goto LAB_001010c0;
  }
  uVar3 = 8;
  uStack_30 = 0;
  local_38 = (undefined7)*(undefined8 *)pcVar2;
  cStack_31 = (char)((ulong)*(undefined8 *)pcVar2 >> 0x38);
LAB_001010c0:
  uVar3 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,uVar3);
LAB_001010d8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_swr_probe @ 00101120 size=2484
// signature: undefined wsa883x_swr_probe(void)
// callers: []
//------------------------------------------------------------

ulong wsa883x_swr_probe(ulong param_1)

{
  long *plVar1;
  ulong *puVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong *puVar7;
  void *pvVar8;
  size_t sVar9;
  undefined8 uVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  char *pcVar14;
  size_t extraout_x1;
  code *pcVar15;
  undefined8 *puVar16;
  long lVar17;
  ulong *puVar18;
  ulong *puVar19;
  ulong uVar20;
  undefined1 local_e4 [4];
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  ulong local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  plVar1 = (long *)(param_1 + 0x48);
  local_68 = *(long *)(lVar11 + 0x638);
  local_e4[0] = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e0 = 0;
  puVar7 = (ulong *)devm_kmalloc(plVar1,400,0xdc0);
  if ((puVar7 == (ulong *)0x0) ||
     (pvVar8 = (void *)devm_kmalloc(plVar1,0xa8,0xdc0), pvVar8 == (void *)0x0)) {
    uVar20 = 0xfffffff4;
    goto LAB_00101914;
  }
  memcpy(pvVar8,&wsa883x_regmap_irq_chip,0xa8);
  puVar18 = puVar7 + 0x2b;
  puVar2 = puVar7 + 0x2c;
  msm_cdc_get_power_supplies(plVar1,puVar18,puVar2);
  if ((puVar7[0x2b] == 0) || ((int)*puVar2 < 1)) {
    pcVar14 = "%s: no power supplies defined\n";
LAB_00101804:
    _dev_err(plVar1,pcVar14,"wsa883x_enable_supplies");
    uVar20 = 0xfffffdfb;
  }
  else {
    iVar4 = msm_cdc_init_supplies(plVar1,puVar7 + 0x2d);
    if (puVar7[0x2d] == 0) {
      _dev_err(plVar1,"%s: Cannot init wsa supplies\n","wsa883x_enable_supplies");
      if (iVar4 != 0) {
        uVar20 = 0xfffffdfb;
        goto LAB_00101910;
      }
    }
    else {
      iVar4 = msm_cdc_enable_static_supplies(plVar1,puVar7[0x2d],*puVar18,(int)*puVar2);
      if (iVar4 != 0) {
        pcVar14 = "%s: wsa static supply enable failed!\n";
        goto LAB_00101804;
      }
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
    iVar4 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x330),"qcom,spkr-sd-n-node",0,0,0,&local_b8);
    uVar20 = local_b8;
    if (iVar4 != 0) {
      uVar20 = 0;
    }
    puVar7[0x15] = uVar20;
    if (uVar20 == 0) {
      uVar20 = 0;
    }
    else {
      *(ulong **)(param_1 + 0xe0) = puVar7;
      puVar7[1] = (ulong)plVar1;
      puVar7[2] = param_1;
      iVar4 = msm_cdc_pinctrl_get_state();
      iVar5 = msm_cdc_pinctrl_select_active_state(puVar7[0x15]);
      if (iVar5 != 0) {
        _dev_err(puVar7[1],"%s: Failed to turn state %d; ret=%d\n","wsa883x_gpio_ctrl",1,iVar5);
      }
      usleep_range_state(5000,0x1392,2);
      iVar5 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_e4);
      if (iVar5 == 0) {
        *(undefined1 *)(param_1 + 0x40) = local_e4[0];
        uVar20 = __devm_regmap_init_swr(param_1,wsa883x_regmap_config,0,0);
        *puVar7 = uVar20;
        if (uVar20 < 0xfffffffffffff001) {
          devm_regmap_qti_debugfs_register(plVar1,uVar20);
          if (0 < *(int *)((long)pvVar8 + 0x50)) {
            iVar5 = 0;
            do {
              regmap_write(*puVar7,iVar5 + 0x3487,0);
              iVar5 = iVar5 + 1;
            } while (iVar5 < *(int *)((long)pvVar8 + 0x50));
          }
          *(ulong **)((long)pvVar8 + 0xa0) = puVar7;
          puVar7[0x1e] = (ulong)plVar1;
          puVar19 = puVar7 + 0x1a;
          *puVar19 = (ulong)pvVar8;
          puVar7[0x1b] = (ulong)"WSA883X";
          puVar7[0x1c] = *puVar7;
          uVar6 = wcd_irq_init(puVar19,puVar7 + 0x19);
          if (uVar6 != 0) {
            uVar20 = (ulong)uVar6;
            pcVar14 = "%s: IRQ init failed: %d\n";
            plVar13 = (long *)puVar7[1];
            goto LAB_00101a18;
          }
          *(ulong *)(puVar7[2] + 1000) = puVar7[0x19];
          wcd_request_irq(puVar19,0,"WSA SAF2WAR",wsa883x_saf2war_handle_irq,puVar7);
          wcd_disable_irq(puVar19,0);
          wcd_request_irq(puVar19,1,"WSA WAR2SAF",wsa883x_war2saf_handle_irq,puVar7);
          wcd_disable_irq(puVar19,1);
          wcd_request_irq(puVar19,2,"WSA OTP",wsa883x_otp_handle_irq,puVar7);
          wcd_disable_irq(puVar19,2);
          wcd_request_irq(puVar19,3,"WSA OCP",wsa883x_ocp_handle_irq,puVar7);
          wcd_disable_irq(puVar19,3);
          wcd_request_irq(puVar19,4,"WSA CLIP",wsa883x_clip_handle_irq,puVar7);
          wcd_disable_irq(puVar19,4);
          wcd_request_irq(puVar19,5,"WSA PDM WD",wsa883x_pdm_wd_handle_irq,puVar7);
          wcd_disable_irq(puVar19,5);
          wcd_request_irq(puVar19,6,"WSA CLK WD",wsa883x_clk_wd_handle_irq,puVar7);
          wcd_disable_irq(puVar19,6);
          wcd_request_irq(puVar19,7,"WSA EXT INT",wsa883x_ext_int_handle_irq,puVar7);
          wcd_disable_irq(puVar19,7);
          wcd_request_irq(puVar19,8,"WSA UVLO",wsa883x_uvlo_handle_irq,puVar7);
          wcd_disable_irq(puVar19,8);
          wcd_request_irq(puVar19,9,"WSA PA ERR",wsa883x_pa_on_err_handle_irq,puVar7);
          wcd_disable_irq(puVar19,9);
          pvVar8 = (void *)devm_kmalloc(plVar1,0x170,0xdc0);
          puVar7[0x30] = (ulong)pvVar8;
          if (pvVar8 == (void *)0x0) {
            uVar20 = 0xfffffff4;
          }
          else {
            memcpy(pvVar8,&soc_codec_dev_wsa883x_wsa,0x170);
            pvVar8 = (void *)devm_kmalloc(plVar1,0xe0,0xdc0);
            puVar7[0x2f] = (ulong)pvVar8;
            if (pvVar8 != (void *)0x0) {
              memcpy(pvVar8,&wsa_dai,0xe0);
              uVar6 = *(uint *)(param_1 + 0x3d8) & 0xf;
              iVar5 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x330),"qcom,wsa883x_2");
              if (iVar5 != 0) {
                uVar6 = uVar6 + 2;
              }
              snprintf((char *)&local_e0,0x28,"wsa-codec.%d",uVar6);
              sVar9 = strnlen((char *)&local_e0,0x28);
              if (0x28 < sVar9) {
LAB_00101abc:
                fortify_panic("strnlen");
                sVar9 = extraout_x1;
LAB_00101ac8:
                lVar11 = fortify_panic("__fortify_strlen",sVar9);
                if ((lVar11 == 0) || (lVar17 = *(long *)(lVar11 + 0xe0), lVar17 == 0)) {
                  _dev_err(lVar11 + 0x48,"%s: wsa883x is NULL\n","wsa883x_swr_remove");
                  uVar20 = 0xffffffea;
                }
                else {
                  lVar3 = lVar17 + 0xd0;
                  wcd_free_irq(lVar3,0,0);
                  wcd_free_irq(lVar3,1,0);
                  wcd_free_irq(lVar3,2,0);
                  wcd_free_irq(lVar3,3,0);
                  wcd_free_irq(lVar3,4,0);
                  wcd_free_irq(lVar3,5,0);
                  wcd_free_irq(lVar3,6,0);
                  wcd_free_irq(lVar3,7,0);
                  wcd_free_irq(lVar3,8,0);
                  wcd_free_irq(lVar3,9,0);
                  pcVar15 = *(code **)(lVar17 + 0x150);
                  if (pcVar15 != (code *)0x0) {
                    if (*(int *)(pcVar15 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
                      pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x101bcc);
                      (*pcVar15)();
                    }
                    (*pcVar15)(*(undefined8 *)(lVar17 + 0x148),lVar17 + 0x130,0);
                  }
                  debugfs_remove(*(undefined8 *)(lVar17 + 0xf8));
                  *(undefined8 *)(lVar17 + 0xf8) = 0;
                  snd_soc_unregister_component(lVar11 + 0x48);
                  if (*(undefined8 **)(lVar17 + 0x178) != (undefined8 *)0x0) {
                    kfree(**(undefined8 **)(lVar17 + 0x178));
                    kfree(*(undefined8 *)(*(long *)(lVar17 + 0x178) + 0xa8));
                    kfree(*(undefined8 *)(lVar17 + 0x178));
                  }
                  if (*(undefined8 **)(lVar17 + 0x180) != (undefined8 *)0x0) {
                    kfree(**(undefined8 **)(lVar17 + 0x180));
                    kfree(*(undefined8 *)(lVar17 + 0x180));
                  }
                  msm_cdc_release_supplies
                            (lVar11 + 0x48,*(undefined8 *)(lVar17 + 0x168),
                             *(undefined8 *)(lVar17 + 0x158),*(undefined4 *)(lVar17 + 0x160));
                  uVar20 = 0;
                  *(undefined8 *)(lVar11 + 0xe0) = 0;
                }
                return uVar20;
              }
              if (sVar9 == 0x28) goto LAB_00101ac8;
              uVar10 = kstrndup(&local_e0,sVar9,0xcc0);
              *(undefined8 *)puVar7[0x30] = uVar10;
              snprintf((char *)&local_e0,0x28,"wsa_rx%d",uVar6);
              sVar9 = strnlen((char *)&local_e0,0x28);
              if (0x28 < sVar9) goto LAB_00101abc;
              if (sVar9 == 0x28) goto LAB_00101ac8;
              uVar10 = kstrndup(&local_e0,sVar9,0xcc0);
              *(undefined8 *)puVar7[0x2f] = uVar10;
              snprintf((char *)&local_e0,0x28,"WSA883X_AIF%d Playback",uVar6);
              sVar9 = strnlen((char *)&local_e0,0x28);
              if (0x28 < sVar9) goto LAB_00101abc;
              if (sVar9 == 0x28) goto LAB_00101ac8;
              uVar10 = kstrndup(&local_e0,sVar9,0xcc0);
              *(undefined8 *)(puVar7[0x2f] + 0xa8) = uVar10;
              snd_soc_register_component(plVar1,puVar7[0x30],puVar7[0x2f],1);
              lVar11 = snd_soc_lookup_component(plVar1,*(undefined8 *)puVar7[0x30]);
              if (lVar11 == 0) {
                _dev_err(plVar1,"%s: component is NULL \n","wsa883x_swr_probe");
                if ((undefined8 *)puVar7[0x2f] != (undefined8 *)0x0) {
                  kfree(*(undefined8 *)puVar7[0x2f]);
                  kfree(*(undefined8 *)(puVar7[0x2f] + 0xa8));
                  kfree(puVar7[0x2f]);
                }
                uVar20 = 0xffffffea;
                puVar16 = (undefined8 *)puVar7[0x30];
                goto joined_r0x00101a6c;
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
              iVar4 = __of_parse_phandle_with_args
                                (*(undefined8 *)(param_1 + 0x330),"qcom,bolero-handle",0,0,0,
                                 &local_b8);
              uVar20 = local_b8;
              if (iVar4 != 0) {
                uVar20 = 0;
              }
              puVar7[0x24] = uVar20;
              if (uVar20 == 0) {
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
                iVar4 = __of_parse_phandle_with_args
                                  (*(undefined8 *)(param_1 + 0x330),"qcom,lpass-cdc-handle",0,0,0,
                                   &local_b8);
                uVar20 = local_b8;
                if (iVar4 != 0) {
                  uVar20 = 0;
                }
                puVar7[0x24] = uVar20;
                if (uVar20 != 0) goto LAB_00101714;
                _dev_info(plVar1,"%s: parent node not found\n","wsa883x_swr_probe");
              }
              else {
LAB_00101714:
                uVar20 = of_find_device_by_node(local_b8);
                puVar7[0x25] = uVar20;
                if (uVar20 == 0) {
                  pcVar14 = "%s: parent dev not found\n";
                }
                else {
                  puVar18 = *(ulong **)(uVar20 + 0xa0);
                  if (puVar18 != (ulong *)0x0) {
                    puVar7[0x26] = (ulong)wsa883x_event_notify;
                    pcVar15 = (code *)puVar18[2];
                    uVar20 = 0;
                    if (pcVar15 != (code *)0x0) {
                      if (*(int *)(pcVar15 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
                        pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x101764);
                        (*pcVar15)();
                      }
                      (*pcVar15)(*puVar18,puVar7 + 0x26,1);
                      uVar20 = puVar18[2];
                    }
                    puVar7[0x2a] = uVar20;
                    puVar7[0x29] = *puVar18;
                    goto LAB_00101778;
                  }
                  pcVar14 = "%s: plat data not found\n";
                }
                _dev_err(plVar1,pcVar14,"wsa883x_swr_probe");
              }
LAB_00101778:
              __mutex_init(puVar7 + 0xc,"&wsa883x->res_lock",&wsa883x_swr_probe___key);
              if (puVar7[0x1f] == 0) {
                lVar11 = *(long *)(param_1 + 0xb8);
                if (lVar11 == 0) {
                  lVar11 = *plVar1;
                }
                uVar20 = debugfs_create_dir(lVar11,0);
                puVar7[0x1f] = uVar20;
                if (uVar20 < 0xfffffffffffff001) {
                  uVar20 = debugfs_create_file("swrslave_peek",0x8124,uVar20,param_1,
                                               codec_debug_read_ops);
                  puVar7[0x20] = uVar20;
                  uVar20 = debugfs_create_file("swrslave_poke",0x8124,puVar7[0x1f],param_1,
                                               codec_debug_write_ops);
                  puVar7[0x21] = uVar20;
                  uVar12 = debugfs_create_file("swrslave_reg_dump",0x8124,puVar7[0x1f],param_1,
                                               codec_debug_dump_ops);
                  uVar20 = 0;
                  puVar7[0x22] = uVar12;
                  goto LAB_00101914;
                }
              }
              uVar20 = 0;
              goto LAB_00101914;
            }
            uVar20 = 0xfffffff4;
            puVar16 = (undefined8 *)puVar7[0x30];
joined_r0x00101a6c:
            if (puVar16 != (undefined8 *)0x0) {
              kfree(*puVar16);
              kfree(puVar7[0x30]);
            }
          }
          wcd_free_irq(puVar19,0,0);
          wcd_free_irq(puVar19,1,0);
          wcd_free_irq(puVar19,2,0);
          wcd_free_irq(puVar19,3,0);
          wcd_free_irq(puVar19,4,0);
          wcd_free_irq(puVar19,5,0);
          wcd_free_irq(puVar19,6,0);
          wcd_free_irq(puVar19,7,0);
          wcd_free_irq(puVar19,8,0);
          wcd_free_irq(puVar19,9,0);
          wcd_irq_exit(puVar19,puVar7[0x19]);
        }
        else {
          pcVar14 = "%s: regmap_init failed %d\n";
          plVar13 = plVar1;
LAB_00101a18:
          _dev_err(plVar13,pcVar14,"wsa883x_swr_probe",uVar20 & 0xffffffff);
        }
        if (iVar4 == 0) {
          wsa883x_gpio_ctrl(puVar7,0);
        }
        swr_remove_device(param_1);
      }
      else {
        uVar20 = 0xfffffdfb;
      }
    }
    msm_cdc_release_supplies(plVar1,puVar7[0x2d],*puVar18,(int)*puVar2);
  }
LAB_00101910:
  *(undefined8 *)(param_1 + 0xe0) = 0;
LAB_00101914:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20 & 0xffffffff;
}



//------------------------------------------------------------
// wsa883x_swr_remove @ 00101ad8 size=412
// signature: undefined wsa883x_swr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_swr_remove(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  
  if ((param_1 == 0) || (lVar4 = *(long *)(param_1 + 0xe0), lVar4 == 0)) {
    _dev_err(param_1 + 0x48,"%s: wsa883x is NULL\n","wsa883x_swr_remove");
    uVar2 = 0xffffffea;
  }
  else {
    lVar1 = lVar4 + 0xd0;
    wcd_free_irq(lVar1,0,0);
    wcd_free_irq(lVar1,1,0);
    wcd_free_irq(lVar1,2,0);
    wcd_free_irq(lVar1,3,0);
    wcd_free_irq(lVar1,4,0);
    wcd_free_irq(lVar1,5,0);
    wcd_free_irq(lVar1,6,0);
    wcd_free_irq(lVar1,7,0);
    wcd_free_irq(lVar1,8,0);
    wcd_free_irq(lVar1,9,0);
    pcVar3 = *(code **)(lVar4 + 0x150);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101bcc);
        (*pcVar3)();
      }
      (*pcVar3)(*(undefined8 *)(lVar4 + 0x148),lVar4 + 0x130,0);
    }
    debugfs_remove(*(undefined8 *)(lVar4 + 0xf8));
    *(undefined8 *)(lVar4 + 0xf8) = 0;
    snd_soc_unregister_component(param_1 + 0x48);
    if (*(undefined8 **)(lVar4 + 0x178) != (undefined8 *)0x0) {
      kfree(**(undefined8 **)(lVar4 + 0x178));
      kfree(*(undefined8 *)(*(long *)(lVar4 + 0x178) + 0xa8));
      kfree(*(undefined8 *)(lVar4 + 0x178));
    }
    if (*(undefined8 **)(lVar4 + 0x180) != (undefined8 *)0x0) {
      kfree(**(undefined8 **)(lVar4 + 0x180));
      kfree(*(undefined8 *)(lVar4 + 0x180));
    }
    msm_cdc_release_supplies
              (param_1 + 0x48,*(undefined8 *)(lVar4 + 0x168),*(undefined8 *)(lVar4 + 0x158),
               *(undefined4 *)(lVar4 + 0x160));
    uVar2 = 0;
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// wsa883x_gpio_ctrl @ 00101c74 size=104
// signature: undefined wsa883x_gpio_ctrl(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

void wsa883x_gpio_ctrl(long param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 & 1) == 0) {
    iVar1 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(param_1 + 0xa8));
  }
  else {
    iVar1 = msm_cdc_pinctrl_select_active_state();
  }
  if (iVar1 != 0) {
    _dev_err(*(undefined8 *)(param_1 + 8),"%s: Failed to turn state %d; ret=%d\n",
             "wsa883x_gpio_ctrl",param_2 & 1,iVar1);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_saf2war_handle_irq @ 00101ce0 size=92
// signature: undefined wsa883x_saf2war_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_saf2war_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_saf2war_handle_irq__rs,"wsa883x_saf2war_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_saf2war_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_war2saf_handle_irq @ 00101d40 size=92
// signature: undefined wsa883x_war2saf_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_war2saf_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_war2saf_handle_irq__rs,"wsa883x_war2saf_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_war2saf_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_otp_handle_irq @ 00101da0 size=92
// signature: undefined wsa883x_otp_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_otp_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_otp_handle_irq__rs,"wsa883x_otp_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_otp_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_ocp_handle_irq @ 00101e00 size=92
// signature: undefined wsa883x_ocp_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_ocp_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_ocp_handle_irq__rs,"wsa883x_ocp_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_ocp_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_clip_handle_irq @ 00101e60 size=92
// signature: undefined wsa883x_clip_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_clip_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_clip_handle_irq__rs,"wsa883x_clip_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_clip_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_pdm_wd_handle_irq @ 00101ec0 size=92
// signature: undefined wsa883x_pdm_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_pdm_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_pdm_wd_handle_irq__rs,"wsa883x_pdm_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_pdm_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_clk_wd_handle_irq @ 00101f20 size=92
// signature: undefined wsa883x_clk_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_clk_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_clk_wd_handle_irq__rs,"wsa883x_clk_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_clk_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_ext_int_handle_irq @ 00101f80 size=92
// signature: undefined wsa883x_ext_int_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_ext_int_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_ext_int_handle_irq__rs,"wsa883x_ext_int_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_ext_int_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_uvlo_handle_irq @ 00101fe0 size=92
// signature: undefined wsa883x_uvlo_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_uvlo_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa883x_uvlo_handle_irq__rs,"wsa883x_uvlo_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_00108bef,"wsa883x_uvlo_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_pa_on_err_handle_irq @ 00102040 size=204
// signature: undefined wsa883x_pa_on_err_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_pa_on_err_handle_irq(undefined4 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if ((param_2 == 0) || (lVar4 = *(long *)(param_2 + 0x18), lVar4 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar2 = snd_soc_component_read(lVar4,0x3413);
    if ((uVar2 & 0x70) != 0) {
      snd_soc_component_read(lVar4,0x3414);
    }
    iVar1 = ___ratelimit(wsa883x_pa_on_err_handle_irq__rs,"wsa883x_pa_on_err_handle_irq");
    if (iVar1 != 0) {
      _printk(&DAT_00108bef,"wsa883x_pa_on_err_handle_irq",param_1);
    }
    snd_soc_component_update_bits(lVar4,0x3410,0x10,0);
    snd_soc_component_update_bits(lVar4,0x3410,0x10,0x10);
    snd_soc_component_update_bits(lVar4,0x3410,0x10,0);
    uVar3 = 1;
  }
  return uVar3;
}



//------------------------------------------------------------
// wsa883x_event_notify @ 00102110 size=756
// signature: undefined wsa883x_event_notify(void)
// callers: []
//------------------------------------------------------------

void wsa883x_event_notify(long param_1,short param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 *puVar7;
  undefined1 local_3c [4];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  puVar7 = (undefined8 *)(param_1 + -0x130);
  if (puVar7 == (undefined8 *)0x0) {
    uVar5 = 0xffffffea;
  }
  else {
    if (param_2 == 6) {
      if ((*(ulong *)(param_1 + 0x40) & 1) != 0) {
        puVar1 = (ulong *)(param_1 + 0x40);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 4;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
    }
    else if (param_2 == 5) {
      if ((*(ulong *)(param_1 + 0x40) & 1) != 0) {
        puVar7 = (undefined8 *)(param_1 + -0x118);
        snd_soc_component_update_bits(*puVar7,0x344b,1,1);
        snd_soc_component_update_bits(*puVar7,0x3410,1,1);
        wcd_enable_irq(param_1 + -0x60,5);
        usleep_range_state(3000,0xc1c,2);
        if ((*(char *)(param_1 + -0x110) != '\0') && ((*(ulong *)(param_1 + 0x58) & 1) != 0)) {
          snd_soc_component_update_bits(*puVar7,0x346d,1,0);
          usleep_range_state(5000,0x13ba,2);
        }
      }
    }
    else if (param_2 == 4) {
      iVar4 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(param_1 + -0x88));
      if (iVar4 != 0) {
        _dev_err(*(undefined8 *)(param_1 + -0x128),"%s: Failed to turn state %d; ret=%d\n",
                 "wsa883x_gpio_ctrl",0,iVar4);
        _dev_err(*(undefined8 *)(param_1 + -0x128),"%s: Failed to disable gpio\n","wsa883x_swr_down"
                );
      }
      usleep_range_state(500,0x1fe,2);
      iVar4 = msm_cdc_pinctrl_select_active_state(*(undefined8 *)(param_1 + -0x88));
      if (iVar4 != 0) {
        _dev_err(*(undefined8 *)(param_1 + -0x128),"%s: Failed to turn state %d; ret=%d\n",
                 "wsa883x_gpio_ctrl",1,iVar4);
        _dev_err(*(undefined8 *)(param_1 + -0x128),"%s: Failed to enable gpio\n","wsa883x_swr_up");
      }
      usleep_range_state(20000,0x4e2a,2);
      local_3c[0] = 0;
      lVar6 = *(long *)(param_1 + -0x120);
      iVar4 = swr_get_logical_dev_num(lVar6,*(undefined8 *)(lVar6 + 0x3d8),local_3c);
      if (iVar4 != 0) {
        usleep_range_state(1000,0x44c,2);
        iVar4 = swr_get_logical_dev_num(lVar6,*(undefined8 *)(lVar6 + 0x3d8),local_3c);
        if (iVar4 != 0) {
          usleep_range_state(1000,0x44c,2);
          iVar4 = swr_get_logical_dev_num(lVar6,*(undefined8 *)(lVar6 + 0x3d8),local_3c);
          if (iVar4 != 0) {
            usleep_range_state(1000,0x44c,2);
            iVar4 = swr_get_logical_dev_num(lVar6,*(undefined8 *)(lVar6 + 0x3d8),local_3c);
            if (iVar4 != 0) {
              usleep_range_state(1000,0x44c,2);
              iVar4 = swr_get_logical_dev_num(lVar6,*(undefined8 *)(lVar6 + 0x3d8),local_3c);
              if (iVar4 != 0) {
                usleep_range_state(1000,0x44c,2);
                swr_get_logical_dev_num(lVar6,*(undefined8 *)(lVar6 + 0x3d8),local_3c);
              }
            }
          }
        }
      }
      *(undefined1 *)(lVar6 + 0x40) = local_3c[0];
      mutex_lock(param_1 + -0xd0);
      regcache_mark_dirty(*puVar7);
      regcache_sync(*puVar7);
      mutex_unlock(param_1 + -0xd0);
    }
    uVar5 = 0;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_handle_post_irq @ 00102414 size=144
// signature: undefined wsa883x_handle_post_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_handle_post_irq(undefined8 *param_1)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  regmap_read(*param_1,0x3483,(long)&local_30 + 4);
  regmap_read(*param_1,0x3484,&local_30);
  *(bool *)(param_1[2] + 0x3f0) = local_30._4_4_ != 0 || (int)local_30 != 0;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// wsa883x_codec_probe @ 001024a8 size=520
// signature: undefined wsa883x_codec_probe(void)
// callers: []
//------------------------------------------------------------

void wsa883x_codec_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  size_t __n;
  undefined8 uVar3;
  char *__s;
  undefined8 *puVar4;
  long lVar5;
  long lVar6;
  undefined2 local_70;
  undefined2 uStack_6e;
  undefined4 uStack_6c;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined8 **)(*(long *)(param_1 + 0x18) + 0x98);
  if ((puVar4 == (undefined8 *)0x0) || (*(long *)(param_1 + 0x10) == 0)) {
    uVar3 = 0xffffffea;
  }
  else {
    lVar1 = param_1 + 0xd0;
    snd_soc_component_init_regmap(param_1,*puVar4);
    puVar4[3] = param_1;
    uVar2 = snd_soc_component_read(param_1,0x3580);
    *(uint *)(puVar4 + 0x17) = uVar2 & 0xf;
    uVar2 = snd_soc_component_read(param_1,0x3401);
    *(undefined4 *)((long)puVar4 + 0x5c) = 2;
    *(uint *)((long)puVar4 + 0xbc) = uVar2 & 0xff;
    lVar5 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar5 != 0) {
      lVar6 = 0;
      do {
        snd_soc_component_update_bits
                  (param_1,*(undefined2 *)((long)&reg_init + lVar6),(&DAT_0010547a)[lVar6],
                   (&DAT_0010547b)[lVar6]);
        lVar6 = lVar6 + 4;
      } while (lVar6 != 200);
      if ((*(uint *)(lVar5 + 0xb8) | 2) == 2) {
        snd_soc_component_update_bits(param_1,0x346c,7,3);
        *(undefined4 *)(lVar5 + 0x5c) = 3;
      }
    }
    *(undefined4 *)((long)puVar4 + 0x54) = 0;
    local_70 = 0;
    uStack_6e = 0;
    uStack_6c = 0;
    local_68 = 0;
    uStack_64 = 0;
    local_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    __s = *(char **)(puVar4[0x2f] + 0xa8);
    local_50 = 0;
    uStack_4c = 0;
    __n = strlen(__s);
    if (0x26 < __n) {
      __n = 0x27;
    }
    memcpy(&local_70,__s,__n);
    *(undefined1 *)((long)&local_70 + __n) = 0;
    snd_soc_dapm_ignore_suspend(lVar1,&local_70);
    uStack_6e = 0;
    uStack_6c = 0;
    local_68 = 0;
    uStack_64 = 0;
    local_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    local_50 = 0;
    uStack_4c = 0;
    local_70 = 0x4e49;
    snd_soc_dapm_ignore_suspend(lVar1,&local_70);
    uStack_64 = 0;
    local_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    local_50 = 0;
    uStack_4c = 0;
    local_68 = 0x74726f50;
    local_70 = s_SWR_DAC_Port_00109138._0_2_;
    uStack_6e = s_SWR_DAC_Port_00109138._2_2_;
    uStack_6c = s_SWR_DAC_Port_00109138._4_4_;
    snd_soc_dapm_ignore_suspend(lVar1,&local_70);
    uStack_6c = 0;
    local_68 = 0;
    uStack_64 = 0;
    local_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    local_50 = 0;
    uStack_4c = 0;
    local_70 = 0x5053;
    uStack_6e = 0x524b;
    snd_soc_dapm_ignore_suspend(lVar1,&local_70);
    snd_soc_dapm_sync(lVar1);
    uVar3 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_codec_remove @ 001026b4 size=40
// signature: undefined wsa883x_codec_remove(void)
// callers: []
//------------------------------------------------------------

void wsa883x_codec_remove(long param_1)

{
  if (*(long *)(*(long *)(param_1 + 0x18) + 0x98) != 0) {
    snd_soc_component_exit_regmap();
  }
  return;
}



//------------------------------------------------------------
// wsa883x_soc_codec_suspend @ 001026e0 size=28
// signature: undefined wsa883x_soc_codec_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_soc_codec_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x23) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// wsa883x_soc_codec_resume @ 00102700 size=24
// signature: undefined wsa883x_soc_codec_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_soc_codec_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x23) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// wsa_pa_gain_get @ 0010271c size=28
// signature: undefined wsa_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_pa_gain_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xc0);
  return 0;
}



//------------------------------------------------------------
// wsa_pa_gain_put @ 0010273c size=72
// signature: undefined wsa_pa_gain_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_pa_gain_put(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0x80);
  lVar3 = *(long *)(*(long *)(lVar1 + 0x18) + 0x98);
  uVar2 = *(undefined8 *)(param_2 + 0x48);
  *(char *)(lVar3 + 0xc0) = (char)uVar2;
  if (*(char *)(lVar3 + 0x20) == '\0') {
    snd_soc_component_update_bits(lVar1,0x346d,0x3e,((uint)uVar2 & 0xff) << 1);
  }
  return 0;
}



//------------------------------------------------------------
// wsa883x_get_mute @ 00102788 size=28
// signature: undefined wsa883x_get_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_get_mute(long param_1,long param_2)

{
  *(long *)(param_2 + 0x48) =
       (long)*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xb0);
  return 0;
}



//------------------------------------------------------------
// wsa883x_set_mute @ 001027a8 size=28
// signature: undefined wsa883x_set_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_set_mute(long param_1,long param_2)

{
  *(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xb0) =
       (int)*(undefined8 *)(param_2 + 0x48);
  return 0;
}



//------------------------------------------------------------
// wsa_get_temp @ 001027c8 size=736
// signature: undefined wsa_get_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_get_temp(long param_1,long param_2)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  char cVar12;
  
  lVar11 = *(long *)(param_1 + 0x80);
  lVar10 = *(long *)(*(long *)(lVar11 + 0x18) + 0x98);
  if ((*(ulong *)(lVar10 + 0x170) & 1) == 0) {
    if (lVar10 == 0) {
      iVar8 = 0;
    }
    else {
      cVar12 = '\x03';
      do {
        lVar9 = *(long *)(*(long *)(lVar11 + 0x18) + 0x98);
        if (lVar9 == 0) {
          _dev_err(*(long *)(lVar11 + 0x18),"%s: wsa883x is NULL\n","wsa883x_temp_reg_read");
          _printk(&DAT_00108d50,"wsa883x_get_temperature",0xffffffea,*(undefined4 *)(lVar10 + 0xb4))
          ;
          iVar8 = *(int *)(lVar10 + 0xb4);
          goto LAB_00102a3c;
        }
        lVar9 = lVar9 + 0x60;
        mutex_lock(lVar9);
        snd_soc_component_update_bits(lVar11,0x3416,1,1);
        snd_soc_component_update_bits(lVar11,0x3416,4,4);
        snd_soc_component_update_bits(lVar11,0x3416,2,2);
        snd_soc_component_update_bits(lVar11,0x3416,0x80,0x80);
        snd_soc_component_update_bits(lVar11,0x3416,0x20,0x20);
        snd_soc_component_update_bits(lVar11,0x3416,0x40,0x40);
        snd_soc_component_update_bits(lVar11,0x3420,1,0);
        uVar4 = snd_soc_component_read(lVar11,0x3422);
        uVar5 = snd_soc_component_read(lVar11,0x3423);
        snd_soc_component_update_bits(lVar11,0x3420,1,1);
        bVar2 = snd_soc_component_read(lVar11,0x3581);
        uVar6 = snd_soc_component_read(lVar11,0x3582);
        bVar3 = snd_soc_component_read(lVar11,0x3583);
        uVar7 = snd_soc_component_read(lVar11,0x3584);
        snd_soc_component_update_bits(lVar11,0x3416,0xe7,0);
        mutex_unlock(lVar9);
        if (((((bVar2 - 0x5d < 0xffffffe7) || ((uVar6 & 0x3f) != 0)) || (bVar3 < 0xb9)) ||
            ((0xda < bVar3 || ((uVar7 & 0x3f) != 0)))) &&
           (iVar8 = ___ratelimit(wsa883x_get_temperature__rs,"wsa883x_get_temperature"), iVar8 != 0)
           ) {
          _printk("%s: Temperature registers[%d %d %d %d] are out of range\n",
                  "wsa883x_get_temperature",bVar2,uVar6 & 0xff,bVar3,uVar7 & 0xff);
        }
        uVar6 = (uVar6 & 0xc0 | (uint)bVar2 << 8) >> 6;
        iVar8 = ((uVar7 & 0xc0 | (uint)bVar3 << 8) >> 6) - uVar6;
        if (iVar8 == 0) {
          iVar8 = 0xffff;
        }
        else {
          iVar1 = 0;
          if (iVar8 != 0) {
            iVar1 = (int)((((uVar5 & 0xc0 | (uVar4 & 0xff) << 8) >> 6) - uVar6) * 0xa0) / iVar8;
          }
          iVar8 = iVar1 + -10;
          if (0xffffffd8 < iVar1 - 0x37U) break;
        }
        cVar12 = cVar12 + -1;
        msleep(10);
      } while (cVar12 != '\0');
      *(int *)(lVar10 + 0xb4) = iVar8;
    }
  }
  else {
    iVar8 = *(int *)(lVar10 + 0xb4);
  }
LAB_00102a3c:
  *(long *)(param_2 + 0x48) = (long)iVar8;
  return 0;
}



//------------------------------------------------------------
// wsa883x_get_dev_num @ 00102aac size=88
// signature: undefined wsa883x_get_dev_num(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_get_dev_num(long param_1,long param_2)

{
  long lVar1;
  
  if (*(long *)(param_1 + 0x80) != 0) {
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
    if (lVar1 != 0) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(*(long *)(lVar1 + 0x10) + 0x40);
      return 0;
    }
    _printk(&DAT_00108c62,"wsa883x_get_dev_num");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wsa_dev_mode_get @ 00102b08 size=28
// signature: undefined wsa_dev_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_dev_mode_get(long param_1,long param_2)

{
  *(long *)(param_2 + 0x48) =
       (long)*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x58);
  return 0;
}



//------------------------------------------------------------
// wsa_dev_mode_put @ 00102b28 size=28
// signature: undefined wsa_dev_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_dev_mode_put(long param_1,long param_2)

{
  *(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x58) =
       (int)*(undefined8 *)(param_2 + 0x48);
  return 0;
}



//------------------------------------------------------------
// wsa883x_get_comp_offset @ 00102b48 size=28
// signature: undefined wsa883x_get_comp_offset(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_get_comp_offset(long param_1,long param_2)

{
  *(long *)(param_2 + 0x48) =
       (long)*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x5c);
  return 0;
}



//------------------------------------------------------------
// wsa883x_set_comp_offset @ 00102b68 size=28
// signature: undefined wsa883x_set_comp_offset(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_set_comp_offset(long param_1,long param_2)

{
  *(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x5c) =
       (int)*(undefined8 *)(param_2 + 0x48);
  return 0;
}



//------------------------------------------------------------
// wsa883x_get_compander @ 00102b88 size=28
// signature: undefined wsa883x_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_get_compander(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x20);
  return 0;
}



//------------------------------------------------------------
// wsa883x_set_compander @ 00102ba8 size=36
// signature: undefined wsa883x_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_set_compander(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x20) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa883x_get_visense @ 00102bd0 size=28
// signature: undefined wsa883x_get_visense(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_get_visense(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x21);
  return 0;
}



//------------------------------------------------------------
// wsa883x_set_visense @ 00102bf0 size=36
// signature: undefined wsa883x_set_visense(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_set_visense(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x21) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa883x_get_ext_vdd_spk @ 00102c18 size=28
// signature: undefined wsa883x_get_ext_vdd_spk(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_get_ext_vdd_spk(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x22);
  return 0;
}



//------------------------------------------------------------
// wsa883x_put_ext_vdd_spk @ 00102c38 size=36
// signature: undefined wsa883x_put_ext_vdd_spk(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_put_ext_vdd_spk(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x22) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa883x_enable_swr_dac_port @ 00102c60 size=868
// signature: undefined wsa883x_enable_swr_dac_port(void)
// callers: []
//------------------------------------------------------------

void wsa883x_enable_swr_dac_port(long param_1,undefined8 param_2,undefined4 param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint6 uVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  undefined1 *puVar11;
  long lVar12;
  long lVar13;
  undefined1 local_48 [4];
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined8 local_40;
  undefined4 local_38;
  ulong local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar12 = sp_el0;
  local_28 = *(long *)(lVar12 + 0x638);
  lVar13 = *(long *)(param_1 + 0x28);
  _local_48 = 0;
  local_40 = 0;
  local_2c = 0;
  local_34 = 0;
  lVar12 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
  if (lVar12 == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    uVar6 = 0;
    switch(param_3) {
    case 1:
      lVar9 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
      local_40 = (ulong)*(byte *)(lVar9 + 0x24) << 0x20;
      local_40 = CONCAT71(local_40._1_7_,*(undefined1 *)(lVar9 + 0x2c));
      _local_48 = (ulong)*(byte *)(lVar9 + 0x25) << 0x20;
      local_38 = *(undefined4 *)(lVar9 + 0x28);
      _local_48 = CONCAT71(stack0xffffffffffffffb9,*(undefined1 *)(lVar9 + 0x2d));
      if (*(int *)(lVar12 + 0x58) == 1) {
        local_38 = 4800000;
      }
      if (*(char *)(lVar12 + 0x20) == '\0') {
        uVar7 = 1;
        cVar2 = *(char *)(lVar12 + 0x21);
      }
      else {
        lVar10 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
        local_40._0_6_ = CONCAT15(*(undefined1 *)(lVar10 + 0x30),(undefined5)local_40);
        uVar4 = (uint6)local_40 >> 0x10;
        local_40._0_2_ = CONCAT11(*(undefined1 *)(lVar10 + 0x38),*(undefined1 *)(lVar9 + 0x2c));
        local_40 = CONCAT62(uVar4,(undefined2)local_40);
        _local_48 = CONCAT15(*(undefined1 *)(lVar10 + 0x31),_local_48);
        local_34 = (ulong)*(uint *)(lVar10 + 0x34);
        uVar4 = _local_48 >> 0x10;
        local_48._0_2_ = CONCAT11(*(undefined1 *)(lVar10 + 0x39),*(undefined1 *)(lVar9 + 0x2d));
        _local_48 = CONCAT62(uVar4,local_48._0_2_);
        puVar1 = (ulong *)(lVar12 + 0x188);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        uVar7 = 2;
        cVar2 = *(char *)(lVar12 + 0x21);
      }
      if (cVar2 != '\0') {
        lVar13 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
        *(undefined1 *)((long)&local_40 + 4U | uVar7) = *(undefined1 *)(lVar13 + 0x48);
        *(undefined1 *)((ulong)&local_40 | uVar7) = *(undefined1 *)(lVar13 + 0x50);
        puVar11 = (undefined1 *)((ulong)local_48 | uVar7);
        *(undefined1 *)((ulong)&uStack_44 | uVar7) = *(undefined1 *)(lVar13 + 0x49);
        (&local_38)[uVar7] = *(undefined4 *)(lVar13 + 0x4c);
        uVar7 = (ulong)((int)uVar7 + 1);
        *puVar11 = *(undefined1 *)(lVar13 + 0x51);
        puVar1 = (ulong *)(lVar12 + 0x188);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 2;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      swr_connect_port(*(undefined8 *)(lVar12 + 0x10),(long)&local_40 + 4,uVar7,&uStack_44,&local_38
                       ,&local_40,local_48);
      break;
    case 2:
      puVar1 = (ulong *)(lVar12 + 0x170);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      break;
    default:
      goto switchD_00102cc0_caseD_3;
    case 4:
      lVar9 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
      local_40 = (ulong)*(byte *)(lVar9 + 0x24) << 0x20;
      _local_48 = (ulong)*(byte *)(lVar9 + 0x25) << 0x20;
      _local_48 = CONCAT71(stack0xffffffffffffffb9,*(undefined1 *)(lVar9 + 0x2d));
      if ((*(char *)(lVar12 + 0x20) == '\0') || ((*(ulong *)(lVar12 + 0x188) & 1) == 0)) {
        uVar7 = 1;
        cVar2 = *(char *)(lVar12 + 0x21);
      }
      else {
        lVar10 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
        local_40._0_6_ = CONCAT15(*(undefined1 *)(lVar10 + 0x30),(undefined5)local_40);
        local_40 = (ulong)(uint6)local_40;
        _local_48 = CONCAT15(*(undefined1 *)(lVar10 + 0x31),_local_48);
        uVar4 = _local_48 >> 0x10;
        local_48._0_2_ = CONCAT11(*(undefined1 *)(lVar10 + 0x39),*(undefined1 *)(lVar9 + 0x2d));
        _local_48 = CONCAT62(uVar4,local_48._0_2_);
        puVar1 = (ulong *)(lVar12 + 0x188);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & 0xfffffffffffffffe;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        uVar7 = 2;
        cVar2 = *(char *)(lVar12 + 0x21);
      }
      uVar8 = uVar7;
      if ((cVar2 != '\0') && (((uint)*(undefined8 *)(lVar12 + 0x188) >> 1 & 1) != 0)) {
        uVar8 = (ulong)((int)uVar7 + 1);
        lVar13 = *(long *)(*(long *)(lVar13 + -0xb8) + 0x98);
        *(undefined1 *)((long)&local_40 + 4U | uVar7) = *(undefined1 *)(lVar13 + 0x48);
        *(undefined1 *)((ulong)&uStack_44 | uVar7) = *(undefined1 *)(lVar13 + 0x49);
        *(undefined1 *)((ulong)local_48 | uVar7) = *(undefined1 *)(lVar13 + 0x51);
        puVar1 = (ulong *)(lVar12 + 0x188);
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
      swr_disconnect_port(*(undefined8 *)(lVar12 + 0x10),(long)&local_40 + 4,uVar8,&uStack_44,
                          local_48);
      break;
    case 8:
      iVar5 = swr_set_device_group(*(undefined8 *)(lVar12 + 0x10),0);
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(lVar13 + -0xb8),"%s: set num ch failed\n",
                 "wsa883x_enable_swr_dac_port");
      }
      swr_slvdev_datapath_control
                (*(long *)(lVar12 + 0x10),*(undefined1 *)(*(long *)(lVar12 + 0x10) + 0x40),0);
    }
    uVar6 = 0;
  }
switchD_00102cc0_caseD_3:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// wsa883x_spkr_event @ 00103008 size=768
// signature: undefined wsa883x_spkr_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_spkr_event(long param_1,undefined8 param_2,int param_3)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  
  lVar6 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar9 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 == 4) {
    if (((uint)*(undefined8 *)(lVar9 + 0x170) >> 2 & 1) == 0) {
      wcd_disable_irq(lVar9 + 0xd0,5);
    }
    snd_soc_component_update_bits(lVar6,0x3426,1,0);
    snd_soc_component_update_bits(lVar6,0x3426,0xe,0);
    snd_soc_component_update_bits(lVar6,0x3410,1,0);
    snd_soc_component_update_bits(lVar6,0x3410,0x10,0);
    snd_soc_component_update_bits(lVar6,0x3410,0x10,0x10);
    snd_soc_component_update_bits(lVar6,0x3410,0x10,0);
    snd_soc_component_update_bits(lVar6,0x344b,1,0);
    lVar6 = lVar9 + 0xd0;
    wcd_disable_irq(lVar6,6);
    wcd_disable_irq(lVar6,3);
    wcd_disable_irq(lVar6,2);
    wcd_disable_irq(lVar6,1);
    wcd_disable_irq(lVar6,0);
    wcd_disable_irq(lVar6,8);
    wcd_disable_irq(lVar6,9);
    puVar2 = (ulong *)(lVar9 + 0x170);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & 0xfffffffffffffffe;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    puVar2 = (ulong *)(lVar9 + 0x170);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & 0xfffffffffffffffb;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    return 0;
  }
  if (param_3 != 2) {
    return 0;
  }
  if (*(int *)(lVar9 + 0x58) == 1) {
    uVar7 = 0;
    uVar8 = 8;
    uVar5 = 2;
  }
  else {
    if (*(int *)(lVar9 + 0x58) != 0) goto LAB_001031bc;
    uVar5 = 0;
    uVar8 = 0;
    uVar7 = 0x90;
  }
  snd_soc_component_update_bits(lVar6,0x3408,2,uVar5);
  snd_soc_component_update_bits(lVar6,0x3039,8,uVar8);
  snd_soc_component_update_bits(lVar6,0x346c,0xf0,uVar7);
LAB_001031bc:
  swr_slvdev_datapath_control
            (*(long *)(lVar9 + 0x10),*(undefined1 *)(*(long *)(lVar9 + 0x10) + 0x40),1);
  usleep_range_state(0xfa,300,2);
  snd_soc_component_update_bits(lVar6,0x346d,1,1);
  usleep_range_state(0xfa,300,2);
  swr_remove_from_group(*(long *)(lVar9 + 0x10),*(undefined1 *)(*(long *)(lVar9 + 0x10) + 0x40));
  if ((*(char *)(lVar9 + 0x20) != '\0') && ((*(ulong *)(lVar9 + 0x188) & 1) != 0)) {
    snd_soc_component_update_bits(lVar6,0x346c,7,*(undefined4 *)(lVar9 + 0x5c));
  }
  lVar1 = lVar9 + 0xd0;
  wcd_enable_irq(lVar1,9);
  wcd_enable_irq(lVar1,8);
  wcd_enable_irq(lVar1,0);
  wcd_enable_irq(lVar1,1);
  wcd_enable_irq(lVar1,2);
  wcd_enable_irq(lVar1,3);
  wcd_enable_irq(lVar1,6);
  snd_soc_component_update_bits(lVar6,0x3426,0xe,6);
  snd_soc_component_update_bits(lVar6,0x3426,1,1);
  if (((uint)*(undefined8 *)(lVar9 + 0x170) >> 2 & 1) != 0) {
    snd_soc_component_update_bits(lVar6,0x3410,1,1);
  }
  return 0;
}



//------------------------------------------------------------
// codec_debug_read @ 00103328 size=228
// signature: undefined codec_debug_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void codec_debug_read(long param_1,long param_2,long param_3,long *param_4)

{
  undefined8 uVar1;
  size_t sVar2;
  long lVar3;
  char local_40 [8];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar1 = 0xffffffffffffffea;
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  if ((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
     (((param_4 != (long *)0x0 && (*(long *)(param_1 + 0xd8) != 0)) &&
      ((lVar3 = *(long *)(*(long *)(param_1 + 0xd8) + 0xe0), lVar3 != 0 && (-1 < *param_4)))))) {
    snprintf(local_40,8,"0x%x\n",(uint)*(byte *)(lVar3 + 0x118));
    sVar2 = strnlen(local_40,7);
    if (7 < sVar2) {
      fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar1 = simple_read_from_buffer(param_2,param_3,param_4,local_40,sVar2);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_peek_write @ 00103410 size=600
// signature: undefined codec_debug_peek_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void codec_debug_peek_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  long lVar9;
  long lVar10;
  char *local_78;
  ulong local_70 [2];
  undefined4 local_60;
  char local_58 [32];
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  uVar4 = 0xffffffffffffffea;
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  local_60 = 0;
  local_70[0] = 0;
  local_70[1] = 0;
  if (((((param_2 == 0) || (param_1 == 0)) || (param_3 == 0)) ||
      ((param_4 == (long *)0x0 || (lVar9 = *(long *)(param_1 + 0xd8), lVar9 == 0)))) ||
     ((lVar10 = *(long *)(lVar9 + 0xe0), lVar10 == 0 || ((0x1f < param_3 || (*param_4 < 0))))))
  goto LAB_001035f0;
  __check_object_size(local_58,param_3,0);
  puVar8 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
     (uVar4 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
    uVar4 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar5 = param_3;
  if (0x8000000000 - param_3 < uVar4) {
LAB_0010361c:
    memset(local_58 + (param_3 - uVar5),0,uVar5);
    if ((int)uVar5 != 0) {
      uVar4 = 0xfffffffffffffff2;
      goto LAB_001035f0;
    }
  }
  else {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      puVar8 = (undefined8 *)puVar8[1];
      uVar5 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar8;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    uVar5 = __arch_copy_from_user(puVar8,local_58,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    if (uVar5 != 0) goto LAB_0010361c;
  }
  if (0x1f < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x103650);
    (*pcVar2)();
  }
  local_78 = local_58;
  local_78[param_3] = '\0';
  pcVar6 = strsep(&local_78," ");
  if (pcVar6 != (char *)0x0) {
    uVar7 = 0x10;
    if ((pcVar6[1] + 0xa8U & 0xdf) != 0) {
      uVar7 = 10;
    }
    iVar3 = kstrtouint(pcVar6,uVar7,local_70);
    if (iVar3 == 0) {
      strsep(&local_78," ");
      if ((uint)local_70[0] < 0x200a) {
        swr_read(lVar9,*(undefined1 *)(lVar9 + 0x40),local_70[0] & 0xffffffff,lVar10 + 0x118,1);
        uVar4 = param_3;
        goto LAB_001035f0;
      }
    }
  }
  uVar4 = 0xffffffffffffffea;
LAB_001035f0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_open @ 00103684 size=16
// signature: undefined codec_debug_open(void)
// callers: []
//------------------------------------------------------------

undefined8 codec_debug_open(long param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x2b8);
  return 0;
}



//------------------------------------------------------------
// codec_debug_write @ 00103698 size=660
// signature: undefined codec_debug_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void codec_debug_write(long param_1,ulong param_2,ulong param_3,long param_4)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined8 *puVar8;
  long lVar9;
  char *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  char local_58 [32];
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  uVar4 = 0xffffffffffffffea;
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  if ((((param_2 != 0) && (param_1 != 0)) && (param_4 != 0)) &&
     ((param_3 < 0x20 && (lVar9 = *(long *)(param_1 + 0xd8), lVar9 != 0)))) {
    __check_object_size(local_58,param_3,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar4 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar4 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar5 = param_3;
    if (uVar4 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
      uVar5 = __arch_copy_from_user(puVar8,local_58,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar4 = daif;
        if ((uVar4 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar4;
      }
    }
    if ((uVar5 == 0) || (memset(local_58 + (param_3 - uVar5),0,uVar5), (int)uVar5 == 0)) {
      if (0x1f < param_3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x103914);
        (*pcVar2)();
      }
      local_78 = local_58;
      local_78[param_3] = '\0';
      pcVar6 = strsep(&local_78," ");
      if (pcVar6 != (char *)0x0) {
        uVar7 = 0x10;
        if ((pcVar6[1] + 0xa8U & 0xdf) != 0) {
          uVar7 = 10;
        }
        iVar3 = kstrtouint(pcVar6,uVar7,&local_70);
        if ((iVar3 == 0) && (pcVar6 = strsep(&local_78," "), pcVar6 != (char *)0x0)) {
          uVar7 = 0x10;
          if ((pcVar6[1] + 0xa8U & 0xdf) != 0) {
            uVar7 = 10;
          }
          iVar3 = kstrtouint(pcVar6,uVar7,(ulong)&local_70 | 4);
          if (iVar3 == 0) {
            strsep(&local_78," ");
            uVar4 = 0xffffffffffffffea;
            if (((uint)local_70 < 0x200a) && (local_70._4_4_ < 0x100)) {
              swr_write(lVar9,*(undefined1 *)(lVar9 + 0x40),local_70 & 0xffffffff,
                        (ulong)&local_70 | 4);
              uVar4 = param_3;
            }
            goto LAB_00103828;
          }
        }
      }
      uVar4 = 0xffffffffffffffea;
    }
    else {
      uVar4 = 0xfffffffffffffff2;
    }
  }
LAB_00103828:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_dump @ 00103948 size=900
// signature: undefined codec_debug_dump(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong codec_debug_dump(long param_1,long param_2,long param_3,long *param_4)

{
  bool bVar1;
  ulong uVar2;
  undefined8 *puVar3;
  uint uVar4;
  ulong uVar5;
  undefined *puVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  uint param3;
  ulong uVar10;
  ulong uVar11;
  uint local_84;
  char local_80 [24];
  long local_68;
  
  lVar9 = sp_el0;
  uVar11 = 0xffffffffffffffea;
  local_68 = *(long *)(lVar9 + 0x638);
  if (((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
      ((param_4 != (long *)0x0 && (lVar9 = *(long *)(param_1 + 0xd8), lVar9 != 0)))) &&
     (-1 < *param_4)) {
    uVar11 = 0;
    local_84 = 0;
    iVar7 = (int)*param_4;
    local_80[0x10] = '\0';
    local_80[0x11] = '\0';
    local_80[0x12] = '\0';
    local_80[0x13] = '\0';
    local_80[0] = '\0';
    local_80[1] = '\0';
    local_80[2] = '\0';
    local_80[3] = '\0';
    local_80[4] = '\0';
    local_80[5] = '\0';
    local_80[6] = '\0';
    local_80[7] = '\0';
    local_80[8] = '\0';
    local_80[9] = '\0';
    local_80[10] = '\0';
    local_80[0xb] = '\0';
    local_80[0xc] = '\0';
    local_80[0xd] = '\0';
    local_80[0xe] = '\0';
    local_80[0xf] = '\0';
    if (iVar7 < 0x17d78) {
      uVar11 = 0;
      puVar3 = (undefined8 *)sp_el0;
      param3 = iVar7 / 0xc + 0x40;
      do {
        if ((((((0x864 < param3 - 0xf36 >> 1) && (9 < param3 - 0xf26)) &&
              ((0x19 < param3 - 0xf06 &&
               (((0xaf9 < param3 - 0x406 && (0xcb < param3 - 0x339)) && (0xcb < param3 - 0x239))))))
             && ((0xcb < param3 - 0x139 && (6 < param3 - 0x429)))) &&
            ((6 < (param3 & 0xfffffeff) - 0x229 &&
             (((6 < param3 - 0x129 && (0x19 < param3 - 0x406)) &&
              ((0x19 < (param3 & 0xfffffefe) - 0x206 &&
               (((0x19 < param3 - 0x106 && (0xe < (param3 & 0xffffffef) - 0xe1)) &&
                (0xe < param3 - 0xd1)))))))))) &&
           (((0x79 < param3 - 0x56 && (2 < param3 - 0x47)) && (4 < param3 - 0x4b)))) {
          swr_read(lVar9,*(undefined1 *)(lVar9 + 0x40),param3,&local_84,1);
          uVar4 = snprintf(local_80,0x14,"0x%.3x: 0x%.2x\n",param3,local_84 & 0xff);
          if ((int)uVar4 < 0) {
            puVar6 = &DAT_00108bb3;
          }
          else {
            uVar10 = (ulong)uVar4;
            if (param_3 - 1U <= uVar11 + uVar10) break;
            if (uVar4 < 0x15) {
              uVar2 = param_2 + uVar11;
              __check_object_size(local_80,uVar10,1);
              if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
                 (uVar8 = uVar2, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
                uVar8 = uVar2 & (long)(uVar2 * 0x100) >> 8;
              }
              uVar5 = uVar10;
              if (uVar8 <= 0x8000000000 - uVar10) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar8 = daif;
                  if ((uVar8 & 0x80) == 0) {
                    uVar5 = daif;
                    daif = uVar5 | 0xc0;
                  }
                  uVar5 = ttbr1_el1;
                  ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar3[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar8;
                }
                uVar5 = __arch_copy_to_user(uVar2 & 0xff7fffffffffffff,local_80,uVar10);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar2 = daif;
                  if ((uVar2 & 0x80) == 0) {
                    uVar8 = daif;
                    daif = uVar8 | 0xc0;
                  }
                  uVar8 = ttbr1_el1;
                  ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar8 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar2;
                }
              }
              if (uVar5 == 0) {
                *param_4 = *param_4 + uVar10;
                uVar11 = uVar11 + uVar10;
                goto LAB_001039f8;
              }
            }
            else {
              __copy_overflow(0x14,uVar10);
            }
            puVar6 = &DAT_00108bd2;
          }
          _printk(puVar6,"swr_slave_reg_show");
          uVar11 = 0xfffffffffffffff2;
          break;
        }
LAB_001039f8:
        bVar1 = (int)param3 < 0x2009;
        param3 = param3 + 1;
      } while (bVar1);
    }
    *param_4 = 0x1806c;
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// wsa883x_swr_suspend @ 00103ce8 size=164
// signature: undefined wsa883x_swr_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_swr_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (lVar5 = *(long *)(param_1 + 0x98), lVar5 == 0)) {
    _dev_err(param_1,"%s: wsa883x private data is NULL\n","wsa883x_swr_suspend");
    uVar4 = 0xffffffea;
  }
  else {
    if ((*(char *)(lVar5 + 0x23) != '\0') ||
       ((*(long *)(lVar5 + 0x18) != 0 && (*(int *)(*(long *)(lVar5 + 0x18) + 0xd0) == 0)))) {
      msm_cdc_set_supplies_lpm_mode
                (param_1,*(undefined8 *)(lVar5 + 0x168),*(undefined8 *)(lVar5 + 0x158),
                 *(undefined4 *)(lVar5 + 0x160),1);
      puVar1 = (ulong *)(lVar5 + 0x170);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 2;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// wsa883x_swr_resume @ 00103d9c size=148
// signature: undefined wsa883x_swr_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa883x_swr_resume(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (lVar5 = *(long *)(param_1 + 0x98), lVar5 == 0)) {
    _dev_err(param_1,"%s: wsa883x private data is NULL\n","wsa883x_swr_resume");
    uVar4 = 0xffffffea;
  }
  else {
    if (((uint)*(undefined8 *)(lVar5 + 0x170) >> 1 & 1) != 0) {
      msm_cdc_set_supplies_lpm_mode
                (param_1,*(undefined8 *)(lVar5 + 0x168),*(undefined8 *)(lVar5 + 0x158),
                 *(undefined4 *)(lVar5 + 0x160),0);
      puVar1 = (ulong *)(lVar5 + 0x170);
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
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// wsa883x_writeable_register @ 00103eb8 size=52
// signature: undefined wsa883x_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wsa883x_writeable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x1a < uVar1 >> 9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103eec);
    (*pcVar2)();
  }
  return (byte)(&wsa883x_reg_access)[uVar1] >> 1 & 1;
}



//------------------------------------------------------------
// wsa883x_readable_register @ 00103ef0 size=52
// signature: undefined wsa883x_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wsa883x_readable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x1a < uVar1 >> 9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103f24);
    (*pcVar2)();
  }
  return (&wsa883x_reg_access)[uVar1] & 1;
}



//------------------------------------------------------------
// wsa883x_volatile_register @ 00103f28 size=60
// signature: undefined wsa883x_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wsa883x_volatile_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return false;
  }
  if (0x1a < uVar1 >> 9) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103f64);
    (*pcVar2)();
  }
  return ((&wsa883x_reg_access)[uVar1] & 3) == 1;
}



//------------------------------------------------------------
// init_module @ 00103fc4 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  swr_driver_register(&wsa883x_swr_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103fec size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  swr_driver_unregister(&wsa883x_swr_driver);
  return;
}



//------------------------------------------------------------
// snprintf @ 0010d000 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [wsa883x_swr_probe, codec_debug_read, codec_debug_dump, wsa883x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 0010d008 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [wsa883x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 0010d010 size=1
// signature: undefined snd_info_register(void)
// callers: [wsa883x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 0010d018 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [wsa883x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 0010d020 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [wsa883x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010d028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wsa883x_swr_probe, wsa883x_event_notify, codec_debug_read, wsa883x_handle_post_irq, wsa883x_enable_swr_dac_port, codec_debug_write, wsa883x_codec_version_read, wsa883x_codec_probe, wsa883x_variant_read, codec_debug_dump, codec_debug_peek_write, wsa883x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010d030 size=1
// signature: undefined _printk(void)
// callers: [wsa883x_war2saf_handle_irq, wsa883x_pdm_wd_handle_irq, wsa883x_codec_version_read, wsa_get_temp, wsa883x_variant_read, codec_debug_dump, wsa883x_codec_get_dev_num, wsa883x_ocp_handle_irq, wsa883x_clk_wd_handle_irq, wsa883x_otp_handle_irq, wsa883x_uvlo_handle_irq, wsa883x_get_dev_num, wsa883x_saf2war_handle_irq, wsa883x_pa_on_err_handle_irq, wsa883x_clip_handle_irq, wsa883x_ext_int_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 0010d038 size=1
// signature: undefined __sw_hweight8(void)
// callers: [wsa883x_set_channel_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d040 size=1
// signature: undefined _dev_err(void)
// callers: [wsa883x_swr_probe, wsa883x_event_notify, wsa883x_set_channel_map, wsa883x_swr_resume, wsa883x_enable_swr_dac_port, wsa883x_gpio_ctrl, wsa883x_swr_suspend, wsa_get_temp, wsa883x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_register @ 0010d048 size=1
// signature: undefined swr_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_unregister @ 0010d050 size=1
// signature: undefined swr_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0010d058 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [codec_debug_read, wsa883x_codec_version_read, wsa883x_variant_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010d060 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010d068 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [wsa883x_swr_probe, wsa883x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 0010d070 size=1
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_get_power_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 0010d078 size=1
// signature: undefined msm_cdc_init_supplies(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_init_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 0010d080 size=1
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_static_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010d088 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0010d090 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0010d098 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wsa883x_swr_probe, wsa883x_event_notify, wsa883x_gpio_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010d0a0 size=1
// signature: undefined usleep_range_state(void)
// callers: [wsa883x_swr_probe, wsa883x_event_notify, wsa883x_spkr_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 0010d0a8 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wsa883x_swr_probe, wsa883x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 0010d0b0 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 0010d0b8 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 0010d0c0 size=1
// signature: undefined regmap_write(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_init @ 0010d0c8 size=1
// signature: undefined wcd_irq_init(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_request_irq @ 0010d0d0 size=1
// signature: undefined wcd_request_irq(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_request_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_disable_irq @ 0010d0d8 size=1
// signature: undefined wcd_disable_irq(void)
// callers: [wsa883x_swr_probe, wsa883x_spkr_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 0010d0e0 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010d0e8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [wsa883x_swr_probe, codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 0010d0f0 size=1
// signature: undefined kstrndup(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 0010d0f8 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_lookup_component @ 0010d100 size=1
// signature: undefined snd_soc_lookup_component(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_lookup_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 0010d108 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010d110 size=1
// signature: undefined __mutex_init(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010d118 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010d120 size=1
// signature: undefined kfree(void)
// callers: [wsa883x_swr_probe, wsa883x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_free_irq @ 0010d128 size=1
// signature: undefined wcd_free_irq(void)
// callers: [wsa883x_swr_probe, wsa883x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_exit @ 0010d130 size=1
// signature: undefined wcd_irq_exit(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_device @ 0010d138 size=1
// signature: undefined swr_remove_device(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_release_supplies @ 0010d140 size=1
// signature: undefined msm_cdc_release_supplies(void)
// callers: [wsa883x_swr_probe, wsa883x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_release_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0010d148 size=1
// signature: undefined debugfs_create_file(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010d150 size=1
// signature: undefined _dev_info(void)
// callers: [wsa883x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010d158 size=1
// signature: undefined fortify_panic(void)
// callers: [wsa883x_swr_probe, codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0010d160 size=1
// signature: undefined debugfs_remove(void)
// callers: [wsa883x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 0010d168 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [wsa883x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0010d170 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wsa883x_event_notify, wsa883x_gpio_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010d178 size=1
// signature: undefined ___ratelimit(void)
// callers: [wsa883x_clk_wd_handle_irq, wsa883x_otp_handle_irq, wsa883x_uvlo_handle_irq, wsa883x_war2saf_handle_irq, wsa883x_pdm_wd_handle_irq, wsa883x_saf2war_handle_irq, wsa883x_pa_on_err_handle_irq, wsa_get_temp, wsa883x_ocp_handle_irq, wsa883x_clip_handle_irq, wsa883x_ext_int_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0010d180 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wsa883x_pa_on_err_handle_irq, wsa883x_codec_probe, wsa_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0010d188 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wsa883x_event_notify, wsa883x_spkr_event, wsa_pa_gain_put, wsa883x_pa_on_err_handle_irq, wsa883x_codec_probe, wsa_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010d190 size=1
// signature: undefined mutex_lock(void)
// callers: [wsa883x_event_notify, wsa_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0010d198 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wsa883x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 0010d1a0 size=1
// signature: undefined regcache_sync(void)
// callers: [wsa883x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010d1a8 size=1
// signature: undefined mutex_unlock(void)
// callers: [wsa883x_event_notify, wsa_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_enable_irq @ 0010d1b0 size=1
// signature: undefined wcd_enable_irq(void)
// callers: [wsa883x_event_notify, wsa883x_spkr_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 0010d1c0 size=1
// signature: undefined regmap_read(void)
// callers: [wsa883x_handle_post_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 0010d1c8 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [wsa883x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010d1d0 size=1
// signature: size_t strlen(char * __s)
// callers: [wsa883x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0010d1d8 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [wsa883x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0010d1e0 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [wsa883x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_exit_regmap @ 0010d1e8 size=1
// signature: undefined snd_soc_component_exit_regmap(void)
// callers: [wsa883x_codec_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_exit_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010d1f0 size=1
// signature: undefined msleep(void)
// callers: [wsa_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_set_device_group @ 0010d1f8 size=1
// signature: undefined swr_set_device_group(void)
// callers: [wsa883x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_set_device_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 0010d200 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [wsa883x_spkr_event, wsa883x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 0010d208 size=1
// signature: undefined swr_connect_port(void)
// callers: [wsa883x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 0010d210 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [wsa883x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_from_group @ 0010d218 size=1
// signature: undefined swr_remove_from_group(void)
// callers: [wsa883x_spkr_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_from_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0010d220 size=1
// signature: undefined __check_object_size(void)
// callers: [codec_debug_write, codec_debug_dump, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0010d230 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0010d238 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010d240 size=1
// signature: undefined kstrtouint(void)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 0010d248 size=1
// signature: undefined swr_read(void)
// callers: [codec_debug_dump, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010d250 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [codec_debug_write, codec_debug_peek_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_write @ 0010d260 size=1
// signature: undefined swr_write(void)
// callers: [codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0010d268 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [codec_debug_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __copy_overflow @ 0010d270 size=1
// signature: undefined __copy_overflow(void)
// callers: [codec_debug_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __copy_overflow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_set_supplies_lpm_mode @ 0010d278 size=1
// signature: undefined msm_cdc_set_supplies_lpm_mode(void)
// callers: [wsa883x_swr_resume, wsa883x_swr_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_set_supplies_lpm_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



