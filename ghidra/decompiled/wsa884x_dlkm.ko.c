// Decompiled by Ghidra 12.2
// Program: wsa884x_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wsa884x_codec_info_create_codec_entry @ 00100d4c size=408
// signature: undefined wsa884x_codec_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

void wsa884x_codec_info_create_codec_entry(long param_1,long param_2)

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
    if (*(long *)(lVar5 + 0xb0) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      snprintf(local_88,0x50,"%s.%llx","wsa884x",*(ulonglong *)(*(long *)(lVar5 + 0x10) + 0x3d8));
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),local_88,param_1);
      *(long *)(lVar5 + 0xb0) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0xb0));
        if ((-1 < iVar1) &&
           (lVar3 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"version",*(undefined8 *)(lVar5 + 0xb0)
                              ), lVar3 != 0)) {
          *(long *)(lVar3 + 0x40) = lVar5;
          *(undefined8 *)(lVar3 + 0x10) = 0x20;
          *(undefined2 *)(lVar3 + 0x18) = 1;
          *(undefined1 **)(lVar3 + 0x20) = &wsa884x_codec_info_ops;
          iVar1 = snd_info_register();
          if (-1 < iVar1) {
            *(long *)(lVar5 + 0xb8) = lVar3;
            lVar4 = snd_info_create_card_entry
                              (*(undefined8 *)(lVar4 + 0x48),"variant",*(undefined8 *)(lVar5 + 0xb0)
                              );
            if (lVar4 != 0) {
              *(long *)(lVar4 + 0x40) = lVar5;
              *(undefined8 *)(lVar4 + 0x10) = 0x20;
              *(undefined2 *)(lVar4 + 0x18) = 1;
              *(undefined1 **)(lVar4 + 0x20) = wsa884x_variant_ops;
              iVar1 = snd_info_register();
              if (-1 < iVar1) {
                uVar2 = 0;
                *(long *)(lVar5 + 0xc0) = lVar4;
                goto LAB_00100eb4;
              }
              snd_info_free_entry(lVar4);
            }
          }
          snd_info_free_entry(lVar3);
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0xb0));
      }
      uVar2 = 0xfffffff4;
    }
    else {
      uVar2 = 0;
    }
  }
LAB_00100eb4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wsa884x_codec_get_dev_num @ 00100ee8 size=104
// signature: undefined wsa884x_codec_get_dev_num(void)
// callers: []
//------------------------------------------------------------

ulong wsa884x_codec_get_dev_num(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar2 != 0) {
      return (ulong)*(byte *)(*(long *)(lVar2 + 0x10) + 0x40);
    }
    iVar1 = ___ratelimit(wsa884x_codec_get_dev_num__rs,"wsa884x_codec_get_dev_num");
    if (iVar1 != 0) {
      _printk(&DAT_00112495,"wsa884x_codec_get_dev_num");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wsa884x_set_channel_map @ 00100f54 size=296
// signature: undefined wsa884x_set_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8
wsa884x_set_channel_map
          (long param_1,long param_2,byte param_3,long param_4,long param_5,long param_6)

{
  code *pcVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  undefined1 *puVar7;
  
  if ((((param_3 < 7) && (param_2 != 0)) && (param_4 != 0)) && (param_5 != 0)) {
    if (param_3 != 0) {
      uVar6 = 0;
      puVar7 = (undefined1 *)(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + 0x31);
      do {
        if (uVar6 == 6) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10107c);
          (*pcVar1)();
        }
        lVar5 = uVar6 * 4;
        puVar7[-9] = *(undefined1 *)(param_2 + uVar6);
        puVar7[-8] = (char)*(undefined4 *)(param_4 + lVar5);
        *(undefined4 *)(puVar7 + -5) = *(undefined4 *)(param_5 + lVar5);
        uVar2 = __sw_hweight8(*(undefined4 *)(param_4 + lVar5));
        puVar7[-1] = uVar2;
        if (param_6 != 0) {
          *puVar7 = *(undefined1 *)(param_6 + uVar6);
        }
        uVar6 = uVar6 + 1;
        puVar7 = puVar7 + 0xc;
      } while (param_3 != uVar6);
    }
    uVar4 = 0;
  }
  else {
    iVar3 = ___ratelimit(wsa884x_set_channel_map__rs,"wsa884x_set_channel_map");
    if (iVar3 == 0) {
      uVar4 = 0xffffffea;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Invalid port=%pK, ch_mask=%pK, ch_rate=%pK\n",
               "wsa884x_set_channel_map",param_2,param_4,param_5);
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// wsa884x_codec_version_read @ 00101080 size=244
// signature: undefined wsa884x_codec_version_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wsa884x_codec_version_read
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
    iVar2 = ___ratelimit(wsa884x_codec_version_read__rs,"wsa884x_codec_version_read");
    if (iVar2 == 0) {
      uVar3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_001125b4,"wsa884x_codec_version_read");
      uVar3 = 0xffffffffffffffea;
    }
  }
  else {
    if (*(int *)(*(long *)(param_1 + 0x40) + 0xdc) == 0) {
      uVar3 = 0xc;
      local_38 = _DAT_001122b0;
      uStack_33 = s_4X_1_0_001122b5._0_2_;
      cStack_31 = s_4X_1_0_001122b5[2];
      local_30 = (char  [5])s_4X_1_0_001122b5._3_5_;
    }
    else {
      uVar3 = 0xe;
      local_38 = s_VER_UNDEFINED_00112aa5._0_5_;
      uStack_33 = s_VER_UNDEFINED_00112aa5._5_2_;
      cStack_31 = s_VER_UNDEFINED_00112aa5[7];
      local_30 = s_VER_UNDEFINED_00112aa5._8_5_;
      uStack_2b = s_VER_UNDEFINED_00112aa5._13_2_;
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
// wsa884x_variant_read @ 00101178 size=300
// signature: undefined wsa884x_variant_read(void)
// callers: []
//------------------------------------------------------------

void wsa884x_variant_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 local_40;
  undefined7 local_38;
  char cStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
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
  uStack_2e = 0;
  uStack_2d = 0;
  local_40 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    iVar2 = ___ratelimit(wsa884x_variant_read__rs,"wsa884x_variant_read");
    if (iVar2 == 0) {
      uVar3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_001125b4,"wsa884x_variant_read");
      uVar3 = 0xffffffffffffffea;
    }
    goto LAB_00101260;
  }
  iVar2 = *(int *)(*(long *)(param_1 + 0x40) + 0xd8);
  if (iVar2 == 0xc) {
    uVar5 = 9;
    uStack_30 = 10;
    uStack_2f = 0;
    uVar3 = s_WSA8845H_001124b6._0_8_;
LAB_00101244:
    local_38 = (undefined7)uVar3;
    cStack_31 = SUB81(uVar3,7);
  }
  else {
    if (iVar2 == 5) {
      pcVar4 = "WSA8845\n";
    }
    else {
      if (iVar2 != 0) {
        uVar5 = 10;
        uStack_30 = 0x44;
        uStack_2f = 10;
        uVar3 = s_UNDEFINED_00112cd4._0_8_;
        goto LAB_00101244;
      }
      pcVar4 = "WSA8840\n";
    }
    uVar5 = 8;
    uStack_30 = 0;
    local_38 = (undefined7)*(undefined8 *)pcVar4;
    cStack_31 = (char)((ulong)*(undefined8 *)pcVar4 >> 0x38);
  }
  uStack_2e = 0;
  uVar3 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,uVar5);
LAB_00101260:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wsa884x_swr_probe @ 001012a8 size=3064
// signature: undefined wsa884x_swr_probe(void)
// callers: []
//------------------------------------------------------------

ulong wsa884x_swr_probe(ulong param_1)

{
  long *plVar1;
  ulong *puVar2;
  ulong *puVar3;
  ulong *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  ulong *puVar10;
  void *pvVar11;
  long lVar12;
  size_t sVar13;
  undefined8 uVar14;
  ulong uVar15;
  long *plVar16;
  long lVar17;
  char *pcVar18;
  size_t extraout_x1;
  undefined8 uVar19;
  undefined8 uVar20;
  code *pcVar21;
  ulong *puVar22;
  ulong uVar23;
  uint local_f4;
  uint local_f0;
  undefined1 local_ec [4];
  char local_e8 [40];
  ulong local_c0 [12];
  
  lVar12 = sp_el0;
  plVar1 = (long *)(param_1 + 0x48);
  local_c0[10] = *(long *)(lVar12 + 0x638);
  local_ec[0] = 0;
  local_f4 = 0;
  local_f0 = 0;
  local_e8[0x18] = '\0';
  local_e8[0x19] = '\0';
  local_e8[0x1a] = '\0';
  local_e8[0x1b] = '\0';
  local_e8[0x1c] = '\0';
  local_e8[0x1d] = '\0';
  local_e8[0x1e] = '\0';
  local_e8[0x1f] = '\0';
  local_e8[0x20] = '\0';
  local_e8[0x21] = '\0';
  local_e8[0x22] = '\0';
  local_e8[0x23] = '\0';
  local_e8[0x24] = '\0';
  local_e8[0x25] = '\0';
  local_e8[0x26] = '\0';
  local_e8[0x27] = '\0';
  local_e8[8] = '\0';
  local_e8[9] = '\0';
  local_e8[10] = '\0';
  local_e8[0xb] = '\0';
  local_e8[0xc] = '\0';
  local_e8[0xd] = '\0';
  local_e8[0xe] = '\0';
  local_e8[0xf] = '\0';
  local_e8[0x10] = '\0';
  local_e8[0x11] = '\0';
  local_e8[0x12] = '\0';
  local_e8[0x13] = '\0';
  local_e8[0x14] = '\0';
  local_e8[0x15] = '\0';
  local_e8[0x16] = '\0';
  local_e8[0x17] = '\0';
  local_e8[0] = '\0';
  local_e8[1] = '\0';
  local_e8[2] = '\0';
  local_e8[3] = '\0';
  local_e8[4] = '\0';
  local_e8[5] = '\0';
  local_e8[6] = '\0';
  local_e8[7] = '\0';
  puVar10 = (ulong *)devm_kmalloc(plVar1,0x2d0,0xdc0);
  if ((puVar10 == (ulong *)0x0) ||
     (pvVar11 = (void *)devm_kmalloc(plVar1,0xa8,0xdc0), pvVar11 == (void *)0x0)) {
    uVar23 = 0xfffffff4;
    goto LAB_00101324;
  }
  memcpy(pvVar11,&wsa884x_regmap_irq_chip,0xa8);
  puVar2 = puVar10 + 0x52;
  puVar3 = puVar10 + 0x53;
  msm_cdc_get_power_supplies(plVar1,puVar2,puVar3);
  if ((puVar10[0x52] == 0) || ((int)*puVar3 < 1)) {
    pcVar18 = "%s: no power supplies defined\n";
LAB_001013a8:
    _dev_err(plVar1,pcVar18,"wsa884x_enable_supplies");
LAB_001013b8:
    uVar23 = 0xfffffdfb;
    *(undefined8 *)(param_1 + 0xe0) = 0;
    goto LAB_00101324;
  }
  iVar5 = msm_cdc_init_supplies(plVar1,puVar10 + 0x54);
  if (puVar10[0x54] == 0) {
    _dev_err(plVar1,"%s: Cannot init wsa supplies\n","wsa884x_enable_supplies");
    if (iVar5 != 0) goto LAB_001013b8;
  }
  else {
    iVar5 = msm_cdc_enable_static_supplies(plVar1,puVar10[0x54],*puVar2,(int)*puVar3);
    if (iVar5 != 0) {
      pcVar18 = "%s: wsa static supply enable failed!\n";
      goto LAB_001013a8;
    }
  }
  lVar12 = of_find_property(*(undefined8 *)(param_1 + 0x330),"qcom,boost_voltage_11v",0);
  *(bool *)((long)puVar10 + 0x2cc) = lVar12 != 0;
  _dev_info(param_1 + 0x48,"%s: boost_voltage_11v: %d\n","wsa884x_swr_probe");
  local_c0[8] = 0;
  local_c0[9] = 0;
  local_c0[6] = 0;
  local_c0[7] = 0;
  local_c0[4] = 0;
  local_c0[5] = 0;
  local_c0[2] = 0;
  local_c0[3] = 0;
  local_c0[0] = 0;
  local_c0[1] = 0;
  iVar5 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x330),"qcom,spkr-sd-n-node",0,0,0,local_c0);
  uVar23 = local_c0[0];
  if (iVar5 != 0) {
    uVar23 = 0;
  }
  puVar10[0x19] = uVar23;
  if (uVar23 == 0) {
    uVar23 = 0;
  }
  else {
    *(ulong **)(param_1 + 0xe0) = puVar10;
    puVar10[1] = (ulong)plVar1;
    puVar10[2] = param_1;
    iVar5 = msm_cdc_pinctrl_get_state();
    wsa884x_gpio_ctrl(puVar10,1);
    usleep_range_state(5000,0x1392,2);
    iVar6 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_ec);
    if (iVar6 == 0) {
      *(undefined1 *)(param_1 + 0x40) = local_ec[0];
      uVar23 = __devm_regmap_init_swr(param_1,wsa884x_regmap_config,0,0);
      *puVar10 = uVar23;
      if (uVar23 < 0xfffffffffffff001) {
        devm_regmap_qti_debugfs_register(plVar1,uVar23);
        *(ulong **)((long)pvVar11 + 0xa0) = puVar10;
        puVar4 = puVar10 + 0x23;
        puVar10[0x23] = (ulong)pvVar11;
        puVar10[0x24] = (ulong)"WSA884X";
        puVar10[0x27] = (ulong)plVar1;
        puVar10[0x25] = *puVar10;
        uVar7 = wcd_irq_init(puVar4,puVar10 + 0x22);
        if (uVar7 != 0) {
          uVar23 = (ulong)uVar7;
          pcVar18 = "%s: IRQ init failed: %d\n";
          plVar16 = (long *)puVar10[1];
          goto LAB_00101a70;
        }
        *(ulong *)(puVar10[2] + 1000) = puVar10[0x22];
        wcd_request_irq(puVar4,0,"WSA SAF2WAR",wsa884x_saf2war_handle_irq,puVar10);
        wcd_request_irq(puVar4,1,"WSA WAR2SAF",wsa884x_war2saf_handle_irq,puVar10);
        wcd_request_irq(puVar4,2,"WSA OTP",wsa884x_otp_handle_irq,puVar10);
        wcd_request_irq(puVar4,3,"WSA OCP",wsa884x_ocp_handle_irq,puVar10);
        wcd_request_irq(puVar4,4,"WSA CLIP",wsa884x_clip_handle_irq,puVar10);
        wcd_disable_irq(puVar4,4);
        wcd_request_irq(puVar4,5,"WSA PDM WD",wsa884x_pdm_wd_handle_irq,puVar10);
        wcd_request_irq(puVar4,6,"WSA CLK WD",wsa884x_clk_wd_handle_irq,puVar10);
        wcd_request_irq(puVar4,7,"WSA EXT INT",wsa884x_ext_int_handle_irq,puVar10);
        wcd_disable_irq(puVar4,7);
        wcd_request_irq(puVar4,8,"WSA UVLO",wsa884x_uvlo_handle_irq,puVar10);
        wcd_request_irq(puVar4,9,"WSA PA ERR",wsa884x_pa_on_err_handle_irq,puVar10);
        pvVar11 = (void *)devm_kmalloc(plVar1,0x170,0xdc0);
        puVar10[0x58] = (ulong)pvVar11;
        if (pvVar11 == (void *)0x0) {
          uVar23 = 0xfffffff4;
        }
        else {
          memcpy(pvVar11,&soc_codec_dev_wsa884x_wsa,0x170);
          pvVar11 = (void *)devm_kmalloc(plVar1,0xe0,0xdc0);
          puVar10[0x57] = (ulong)pvVar11;
          if (pvVar11 != (void *)0x0) {
            memcpy(pvVar11,&wsa_dai,0xe0);
            uVar8 = *(uint *)(param_1 + 0x3d8) & 0xf;
            iVar6 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x330),"qcom,wsa884x_2");
            uVar7 = uVar8 + 3;
            if (iVar6 == 0) {
              uVar7 = uVar8 + 1;
            }
            snprintf(local_e8,0x28,"wsa-codec.%d",uVar7);
            sVar13 = strnlen(local_e8,0x28);
            if (sVar13 < 0x29) {
              if (sVar13 != 0x28) {
                uVar14 = kstrndup(local_e8,sVar13,0xcc0);
                *(undefined8 *)puVar10[0x58] = uVar14;
                snprintf(local_e8,0x28,"wsa_rx%d",uVar7);
                sVar13 = strnlen(local_e8,0x28);
                if (0x28 < sVar13) goto LAB_00101e84;
                if (sVar13 == 0x28) goto LAB_00101e90;
                uVar14 = kstrndup(local_e8,sVar13,0xcc0);
                *(undefined8 *)puVar10[0x57] = uVar14;
                snprintf(local_e8,0x28,"WSA884X_AIF%d Playback",uVar7);
                sVar13 = strnlen(local_e8,0x28);
                if (0x28 < sVar13) goto LAB_00101e84;
                if (sVar13 == 0x28) goto LAB_00101e90;
                uVar14 = kstrndup(local_e8,sVar13,0xcc0);
                *(undefined8 *)(puVar10[0x57] + 0xa8) = uVar14;
                uVar23 = snd_soc_register_component(plVar1,puVar10[0x58],puVar10[0x57],1);
                uVar23 = uVar23 & 0xffffffff;
                lVar12 = snd_soc_lookup_component(plVar1,*(undefined8 *)puVar10[0x58]);
                if (lVar12 == 0) {
                  _dev_err(plVar1,"%s: component is NULL\n","wsa884x_swr_probe");
                  uVar23 = 0xffffffea;
                  goto LAB_00101d88;
                }
                local_c0[8] = 0;
                local_c0[9] = 0;
                local_c0[6] = 0;
                local_c0[7] = 0;
                local_c0[4] = 0;
                local_c0[5] = 0;
                local_c0[2] = 0;
                local_c0[3] = 0;
                local_c0[0] = 0;
                local_c0[1] = 0;
                iVar6 = __of_parse_phandle_with_args
                                  (*(undefined8 *)(param_1 + 0x330),"qcom,bolero-handle",0,0,0,
                                   local_c0);
                uVar15 = local_c0[0];
                if (iVar6 != 0) {
                  uVar15 = 0;
                }
                puVar10[0x49] = uVar15;
                if (uVar15 == 0) {
                  local_c0[8] = 0;
                  local_c0[9] = 0;
                  local_c0[6] = 0;
                  local_c0[7] = 0;
                  local_c0[4] = 0;
                  local_c0[5] = 0;
                  local_c0[2] = 0;
                  local_c0[3] = 0;
                  local_c0[0] = 0;
                  local_c0[1] = 0;
                  iVar6 = __of_parse_phandle_with_args
                                    (*(undefined8 *)(param_1 + 0x330),"qcom,lpass-cdc-handle",0,0,0,
                                     local_c0);
                  uVar15 = local_c0[0];
                  if (iVar6 != 0) {
                    uVar15 = 0;
                  }
                  puVar10[0x49] = uVar15;
                  if (uVar15 != 0) goto LAB_001018e8;
                  _dev_info(plVar1,"%s: parent node not found\n","wsa884x_swr_probe");
                }
                else {
LAB_001018e8:
                  uVar15 = of_find_device_by_node(local_c0[0]);
                  puVar10[0x4b] = uVar15;
                  if (uVar15 == 0) {
                    pcVar18 = "%s: parent dev not found\n";
                  }
                  else {
                    puVar22 = *(ulong **)(uVar15 + 0xa0);
                    if (puVar22 != (ulong *)0x0) {
                      puVar10[0x4d] = (ulong)wsa884x_event_notify;
                      pcVar21 = (code *)puVar22[2];
                      uVar15 = 0;
                      if (pcVar21 != (code *)0x0) {
                        if (*(int *)(pcVar21 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
                          pcVar21 = (code *)SoftwareBreakpoint(0x8228,0x101938);
                          (*pcVar21)();
                        }
                        (*pcVar21)(*puVar22,puVar10 + 0x4d,1);
                        uVar15 = puVar22[2];
                      }
                      puVar10[0x51] = uVar15;
                      puVar10[0x50] = *puVar22;
                      goto LAB_0010194c;
                    }
                    pcVar18 = "%s: plat data not found\n";
                  }
                  _dev_err(plVar1,pcVar18,"wsa884x_swr_probe");
                }
LAB_0010194c:
                uVar14 = *(undefined8 *)(param_1 + 0x330);
                *(undefined4 *)((long)puVar10 + 0x74) = 0;
                *(char *)((long)puVar10 + 0x10c) = (char)uVar7;
                local_c0[8] = 0;
                local_c0[9] = 0;
                local_c0[6] = 0;
                local_c0[7] = 0;
                local_c0[4] = 0;
                local_c0[5] = 0;
                local_c0[2] = 0;
                local_c0[3] = 0;
                local_c0[0] = 0;
                local_c0[1] = 0;
                iVar6 = __of_parse_phandle_with_args(uVar14,"qcom,wsa-macro-handle",0,0,0,local_c0);
                uVar15 = local_c0[0];
                if (iVar6 != 0) {
                  uVar15 = 0;
                }
                puVar10[0x4a] = uVar15;
                if (uVar15 == 0) {
                  pcVar18 = "%s: parent node not found\n";
                }
                else {
                  uVar15 = of_find_device_by_node();
                  puVar10[0x4c] = uVar15;
                  if (uVar15 == 0) {
                    pcVar18 = "%s: parent dev not found\n";
                  }
                  else {
                    uVar7 = (uVar7 ^ 0xffffffff) & 1;
                    uVar8 = of_property_read_u32_index
                                      (*(undefined8 *)(uVar15 + 0x2f8),"qcom,wsa-rloads",uVar7,
                                       puVar10 + 0x1d);
                    if (uVar8 == 0) {
                      uVar8 = of_property_read_u32_index
                                        (*(undefined8 *)(puVar10[0x4c] + 0x2f8),"qcom,wsa-bat-cfgs",
                                         uVar7,(int *)((long)puVar10 + 0xe4));
                      if (uVar8 == 0) {
                        uVar9 = of_property_read_variable_u32_array
                                          (*(undefined8 *)(puVar10[0x4c] + 0x2f8),
                                           "qcom,noise-gate-mode",&local_f0,1,0);
                        uVar8 = uVar9;
                        if (-1 < (int)uVar9) {
                          uVar8 = 0;
                        }
                        uVar23 = (ulong)uVar8;
                        if ((int)uVar9 < 0) {
                          _dev_info(plVar1,"%s: Failed to read wsa noise gate mode\n",
                                    "wsa884x_swr_probe");
LAB_00101b14:
                          *(undefined4 *)(puVar10 + 0x59) = 0;
                        }
                        else {
                          if (3 < local_f0) goto LAB_00101b14;
                          *(uint *)(puVar10 + 0x59) = local_f0;
                        }
                        lVar17 = of_find_property(*(undefined8 *)(puVar10[0x4c] + 0x2f8),
                                                  "qcom,wsa-system-gains",&local_f4);
                        if (lVar17 == 0) {
                          pcVar18 = "%s: missing wsa-system-gains\n";
                        }
                        else {
                          uVar8 = of_property_read_variable_u32_array
                                            (*(undefined8 *)(puVar10[0x4c] + 0x2f8),
                                             "qcom,wsa-system-gains",puVar10 + 0x1e,
                                             (long)((ulong)local_f4 << 0x20) >> 0x22,0);
                          if (-1 < (int)uVar8) {
                            uVar7 = *(int *)((long)puVar10 + 0x74) + uVar7 * 2;
                            if (3 < uVar7) goto LAB_00101e9c;
                            *(char *)((long)puVar10 + 0xec) =
                                 (char)*(undefined4 *)((long)puVar10 + (ulong)uVar7 * 4 + 0xf0);
                            uVar23 = wsa884x_validate_dt_configuration_params
                                               (lVar12,(int)puVar10[0x1d],
                                                *(undefined4 *)((long)puVar10 + 0xe4));
                            if ((uVar23 & 1) == 0) {
                              *(bool *)(puVar10 + 4) = (int)puVar10[0x1b] != 0xc;
                              wsa884x_set_gain_parameters(lVar12);
                              wsa884x_set_pbr_parameters(lVar12);
                              snd_soc_component_write
                                        (lVar12,0x3504,
                                         (uint)(*(int *)((long)puVar10 + 0x74) == 0) |
                                         ((uint)puVar10[0x21] & 0xf) << 2 | 0xc0);
                              snd_soc_component_write(lVar12,0x3505,0);
                              if ((uint)puVar10[0x1d] < 2) {
                                snd_soc_component_update_bits(lVar12,0x304c,0x70,0x70);
                              }
                              if (*(int *)((long)puVar10 + 0x74) == 0) {
                                uVar14 = 0x34b0;
                                uVar19 = 0xf0;
                                uVar20 = 0xf0;
                              }
                              else {
                                snd_soc_component_update_bits(lVar12,0x34b0,0xf0,0x30);
                                snd_soc_component_update_bits(lVar12,0x341a,2,2);
                                uVar14 = 0x304a;
                                uVar19 = 8;
                                uVar20 = 8;
                              }
                              snd_soc_component_update_bits(lVar12,uVar14,uVar19,uVar20);
                              iVar5 = *(int *)((long)puVar10 + 0xe4);
                              if ((iVar5 != 1) && (iVar5 != 4)) {
                                snd_soc_component_update_bits(lVar12,0x3040,1,0);
                              }
                              uVar7 = wsa884x_parse_port_params(plVar1);
                              if (uVar7 == 0) {
                                swr_init_port_params(puVar10[2],6,puVar10 + 0x40);
                                __mutex_init(puVar10 + 0x10,"&wsa884x->res_lock",
                                             &wsa884x_swr_probe___key);
                                if (puVar10[0x44] == 0) {
                                  lVar12 = *(long *)(param_1 + 0xb8);
                                  if (lVar12 == 0) {
                                    lVar12 = *plVar1;
                                  }
                                  uVar23 = debugfs_create_dir(lVar12,0);
                                  puVar10[0x44] = uVar23;
                                  if (uVar23 < 0xfffffffffffff001) {
                                    uVar23 = debugfs_create_file("swrslave_peek",0x8124,uVar23,
                                                                 param_1,codec_debug_read_ops);
                                    puVar10[0x45] = uVar23;
                                    uVar23 = debugfs_create_file("swrslave_poke",0x8124,
                                                                 puVar10[0x44],param_1,
                                                                 codec_debug_write_ops);
                                    puVar10[0x46] = uVar23;
                                    uVar15 = debugfs_create_file("swrslave_reg_dump",0x8124,
                                                                 puVar10[0x44],param_1,
                                                                 codec_debug_dump_ops);
                                    uVar23 = 0;
                                    puVar10[0x47] = uVar15;
                                    goto LAB_00101324;
                                  }
                                }
                                uVar23 = 0;
                              }
                              else {
                                uVar23 = (ulong)uVar7;
                                _dev_err(plVar1,"Failed to read port params\n");
                                *(undefined8 *)(param_1 + 0xe0) = 0;
                              }
                              goto LAB_00101324;
                            }
                            _dev_err(plVar1,
                                     "%s: invalid dt parameter: Bat_cfg: 0x%x rload: 0x%x, sys_gain: 0x%x\n"
                                     ,"wsa884x_swr_probe",*(undefined4 *)((long)puVar10 + 0xe4),
                                     (int)puVar10[0x1d],*(undefined1 *)((long)puVar10 + 0xec));
                            uVar23 = 0xffffffea;
                            goto LAB_00101d88;
                          }
                          uVar23 = (ulong)uVar8;
                          pcVar18 = "%s: Failed to read wsa system gains\n";
                        }
                      }
                      else {
                        uVar23 = (ulong)uVar8;
                        pcVar18 = "%s: Failed to read wsa bat cfgs\n";
                      }
                    }
                    else {
                      uVar23 = (ulong)uVar8;
                      pcVar18 = "%s: Failed to read wsa rloads\n";
                    }
                  }
                }
                _dev_err(plVar1,pcVar18,"wsa884x_swr_probe");
                goto LAB_00101d88;
              }
            }
            else {
LAB_00101e84:
              fortify_panic("strnlen");
              sVar13 = extraout_x1;
            }
LAB_00101e90:
            fortify_panic("__fortify_strlen",sVar13);
LAB_00101e9c:
                    /* WARNING: Does not return */
            pcVar21 = (code *)SoftwareBreakpoint(0x5512,0x101ea0);
            (*pcVar21)();
          }
          uVar23 = 0xfffffff4;
LAB_00101d88:
          snd_soc_unregister_component(plVar1);
          if ((undefined8 *)puVar10[0x57] != (undefined8 *)0x0) {
            kfree(*(undefined8 *)puVar10[0x57]);
            kfree(*(undefined8 *)(puVar10[0x57] + 0xa8));
            devm_kfree(plVar1,puVar10[0x57]);
            puVar10[0x57] = 0;
          }
          if ((undefined8 *)puVar10[0x58] != (undefined8 *)0x0) {
            kfree(*(undefined8 *)puVar10[0x58]);
            devm_kfree(plVar1,puVar10[0x58]);
            puVar10[0x58] = 0;
          }
        }
        wcd_irq_exit(puVar4,puVar10[0x22]);
      }
      else {
        pcVar18 = "%s: regmap_init failed %d\n";
        plVar16 = plVar1;
LAB_00101a70:
        _dev_err(plVar16,pcVar18,"wsa884x_swr_probe",uVar23 & 0xffffffff);
      }
      if (iVar5 == 0) {
        wsa884x_gpio_ctrl(puVar10,0);
      }
      swr_remove_device(param_1);
    }
    else {
      uVar23 = 0xfffffdfb;
    }
  }
  msm_cdc_release_supplies(plVar1,puVar10[0x54],*puVar2,(int)*puVar3);
  *(undefined8 *)(param_1 + 0xe0) = 0;
LAB_00101324:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_c0[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar23 & 0xffffffff;
}



//------------------------------------------------------------
// wsa884x_swr_remove @ 00101ea4 size=248
// signature: undefined wsa884x_swr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_swr_remove(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0xe0), lVar3 == 0)) {
    _dev_err(param_1 + 0x48,"%s: wsa884x is NULL\n","wsa884x_swr_remove");
    uVar1 = 0xffffffea;
  }
  else {
    pcVar2 = *(code **)(lVar3 + 0x288);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x21242481) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101ef4);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(lVar3 + 0x280),lVar3 + 0x268,0);
    }
    debugfs_remove(*(undefined8 *)(lVar3 + 0x220));
    *(undefined8 *)(lVar3 + 0x220) = 0;
    snd_soc_unregister_component(param_1 + 0x48);
    if (*(undefined8 **)(lVar3 + 0x2b8) != (undefined8 *)0x0) {
      kfree(**(undefined8 **)(lVar3 + 0x2b8));
      kfree(*(undefined8 *)(*(long *)(lVar3 + 0x2b8) + 0xa8));
      kfree(*(undefined8 *)(lVar3 + 0x2b8));
    }
    if (*(undefined8 **)(lVar3 + 0x2c0) != (undefined8 *)0x0) {
      kfree(**(undefined8 **)(lVar3 + 0x2c0));
      kfree(*(undefined8 *)(lVar3 + 0x2c0));
    }
    msm_cdc_release_supplies
              (param_1 + 0x48,*(undefined8 *)(lVar3 + 0x2a0),*(undefined8 *)(lVar3 + 0x290),
               *(undefined4 *)(lVar3 + 0x298));
    uVar1 = 0;
    *(undefined8 *)(param_1 + 0xe0) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// wsa884x_gpio_ctrl @ 00101f9c size=144
// signature: undefined wsa884x_gpio_ctrl(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

void wsa884x_gpio_ctrl(long param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  if ((param_2 & 1) == 0) {
    iVar1 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(param_1 + 200));
  }
  else {
    iVar1 = msm_cdc_pinctrl_select_active_state();
  }
  if ((iVar1 != 0) && (iVar2 = ___ratelimit(wsa884x_gpio_ctrl__rs,"wsa884x_gpio_ctrl"), iVar2 != 0))
  {
    _dev_err(*(undefined8 *)(param_1 + 8),"%s: Failed to turn state %d; ret=%d\n",
             "wsa884x_gpio_ctrl",param_2 & 1,iVar1);
  }
  return;
}



//------------------------------------------------------------
// wsa884x_saf2war_handle_irq @ 00102030 size=92
// signature: undefined wsa884x_saf2war_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_saf2war_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_saf2war_handle_irq__rs,"wsa884x_saf2war_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_saf2war_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_war2saf_handle_irq @ 00102090 size=92
// signature: undefined wsa884x_war2saf_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_war2saf_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_war2saf_handle_irq__rs,"wsa884x_war2saf_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_war2saf_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_otp_handle_irq @ 001020f0 size=92
// signature: undefined wsa884x_otp_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_otp_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_otp_handle_irq__rs,"wsa884x_otp_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_otp_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_ocp_handle_irq @ 00102150 size=92
// signature: undefined wsa884x_ocp_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_ocp_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_ocp_handle_irq__rs,"wsa884x_ocp_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_ocp_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_clip_handle_irq @ 001021b0 size=92
// signature: undefined wsa884x_clip_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_clip_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_clip_handle_irq__rs,"wsa884x_clip_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_clip_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_pdm_wd_handle_irq @ 00102210 size=156
// signature: undefined wsa884x_pdm_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_pdm_wd_handle_irq(undefined4 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    uVar2 = 0;
  }
  else {
    uVar3 = *(undefined8 *)(param_2 + 0x18);
    uVar2 = 1;
    snd_soc_component_update_bits(uVar3,0x348b,1,0);
    snd_soc_component_update_bits(uVar3,0x348b,1,1);
    iVar1 = ___ratelimit(wsa884x_pdm_wd_handle_irq__rs,"wsa884x_pdm_wd_handle_irq");
    if (iVar1 != 0) {
      _printk(&DAT_001123bf,"wsa884x_pdm_wd_handle_irq",param_1);
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wsa884x_clk_wd_handle_irq @ 001022b0 size=92
// signature: undefined wsa884x_clk_wd_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_clk_wd_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_clk_wd_handle_irq__rs,"wsa884x_clk_wd_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_clk_wd_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_ext_int_handle_irq @ 00102310 size=92
// signature: undefined wsa884x_ext_int_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_ext_int_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_ext_int_handle_irq__rs,"wsa884x_ext_int_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_ext_int_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_uvlo_handle_irq @ 00102370 size=92
// signature: undefined wsa884x_uvlo_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_uvlo_handle_irq(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ___ratelimit(wsa884x_uvlo_handle_irq__rs,"wsa884x_uvlo_handle_irq");
  if (iVar1 != 0) {
    _printk(&DAT_001123bf,"wsa884x_uvlo_handle_irq",param_1);
  }
  return 1;
}



//------------------------------------------------------------
// wsa884x_pa_on_err_handle_irq @ 001023d0 size=224
// signature: undefined wsa884x_pa_on_err_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_pa_on_err_handle_irq(undefined4 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if ((param_2 == 0) || (lVar4 = *(long *)(param_2 + 0x18), lVar4 == 0)) {
    uVar3 = 0;
  }
  else {
    snd_soc_component_update_bits(lVar4,0x3430,1,0);
    uVar2 = snd_soc_component_read(lVar4,0x3436);
    if ((uVar2 & 0x1f) != 0) {
      snd_soc_component_read(lVar4,0x3438);
    }
    iVar1 = ___ratelimit(wsa884x_pa_on_err_handle_irq__rs,"wsa884x_pa_on_err_handle_irq");
    if (iVar1 != 0) {
      _printk(&DAT_001123bf,"wsa884x_pa_on_err_handle_irq",param_1);
    }
    snd_soc_component_update_bits(lVar4,0x3431,0x10,0);
    snd_soc_component_update_bits(lVar4,0x3431,0x10,0x10);
    snd_soc_component_update_bits(lVar4,0x3431,0x10,0);
    uVar3 = 1;
  }
  return uVar3;
}



//------------------------------------------------------------
// wsa884x_event_notify @ 001024b4 size=288
// signature: undefined wsa884x_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_event_notify(long param_1,short param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = param_1 + -0x268;
  if (lVar4 == 0) {
    uVar5 = 0xffffffea;
  }
  else {
    if (param_2 == 5) {
      if ((*(ulong *)(param_1 + 0x40) & 1) != 0) {
        snd_soc_component_update_bits(*(undefined8 *)(param_1 + -0x250),0x348b,1,1);
        snd_soc_component_update_bits(*(undefined8 *)(param_1 + -0x250),0x3430,1,1);
      }
    }
    else if (param_2 == 6) {
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
    else if (param_2 == 4) {
      wsa884x_swr_down(lVar4);
      usleep_range_state(500,0x1fe,2);
      wsa884x_swr_up(lVar4);
      usleep_range_state(20000,0x4e2a,2);
      wsa884x_swr_reset(lVar4);
      _dev_err(*(undefined8 *)(param_1 + -0x260),"%s: BOLERO_SLV_EVT_SSR_UP Called",
               "wsa884x_event_notify");
      swr_init_port_params(*(undefined8 *)(param_1 + -600),6,param_1 + -0x68);
    }
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// wsa884x_validate_dt_configuration_params @ 001025e0 size=132
// signature: undefined wsa884x_validate_dt_configuration_params(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

bool wsa884x_validate_dt_configuration_params(long param_1,byte param_2,byte param_3,byte param_4)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = snd_soc_component_read(param_1,0x3501);
  _dev_info(*(undefined8 *)(param_1 + 0x18),"VPHX EN Status: %d",bVar2);
  bVar1 = 0;
  if ((param_3 & 0xfe) != 4 && param_3 != 6) {
    bVar1 = param_3;
  }
  return ((3 < param_2 || 0x12 < param_4) || 6 < bVar1) || bVar1 != bVar2;
}



//------------------------------------------------------------
// wsa884x_set_gain_parameters @ 00102664 size=448
// signature: undefined wsa884x_set_gain_parameters(void)
// callers: [wsa884x_spkr_event, wsa884x_swr_probe]
//------------------------------------------------------------

void wsa884x_set_gain_parameters(long param_1)

{
  byte bVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  
  lVar8 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  uVar4 = 0;
  iVar5 = 8;
  iVar6 = 9;
  switch(*(undefined4 *)(lVar8 + 0xe4)) {
  case 0:
    uVar4 = 0;
    iVar5 = 9;
    iVar6 = 6;
    break;
  case 1:
  case 4:
    bVar1 = *(byte *)(lVar8 + 0xec);
    iVar6 = bVar1 + 0xe;
    uVar4 = (uint)bVar1;
    iVar5 = 7 - uVar4;
    if (3 < bVar1) {
      uVar4 = 4;
      iVar6 = 0x12;
      iVar5 = 3;
    }
    break;
  default:
    uVar4 = 0;
    iVar5 = 7;
    iVar6 = 0xe;
    break;
  case 3:
  case 6:
    break;
  }
  bVar1 = *(byte *)(lVar8 + 0xec);
  uVar7 = (ulong)bVar1;
  *(uint *)(lVar8 + 0x78) = uVar4;
  *(int *)(lVar8 + 0x104) = iVar6;
  *(int *)(lVar8 + 0x108) = iVar5;
  if ((0x12 < bVar1) || (uVar4 = *(uint *)(lVar8 + 0xe8), 3 < uVar4)) {
LAB_0010281c:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102820);
    (*pcVar2)();
  }
  if ((0x4b < (ulong)uVar4 + uVar7 * 4) || (0x12 < bVar1)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x102824);
    (*pcVar2)();
  }
  bVar1 = vsense_gain_data[uVar7];
  snd_soc_component_update_bits
            (param_1,0x3021,0xe0,(ulong)(byte)isense_gain_data[(ulong)uVar4 + uVar7 * 4] << 5);
  snd_soc_component_update_bits(param_1,0x3020,0xe0,(ulong)bVar1 << 5);
  snd_soc_component_update_bits(param_1,0x34b9,0x1f,*(undefined4 *)(lVar8 + 0x104));
  if (*(char *)(lVar8 + 0x20) == '\0') {
    if (0x12 < (ulong)*(byte *)(lVar8 + 0xe0)) goto LAB_0010281c;
    *(uint *)(lVar8 + 0x108) = (uint)(byte)pa_aux_no_comp[*(byte *)(lVar8 + 0xe0)];
    snd_soc_component_update_bits(param_1,0x34b1,1,1);
    uVar3 = 0x3e;
    lVar8 = (ulong)*(byte *)(lVar8 + 0xe0) << 1;
  }
  else {
    snd_soc_component_update_bits(param_1,0x34b0,7,*(undefined4 *)(lVar8 + 0x78));
    uVar3 = 1;
    lVar8 = 0;
  }
  snd_soc_component_update_bits(param_1,0x34b1,uVar3,lVar8);
  return;
}



//------------------------------------------------------------
// wsa884x_set_pbr_parameters @ 00102824 size=1716
// signature: undefined wsa884x_set_pbr_parameters(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

void wsa884x_set_pbr_parameters(long param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  uint uVar16;
  code *pcVar17;
  long lVar18;
  ulong uVar19;
  ulong uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  
  lVar18 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  uVar20 = (ulong)*(byte *)(lVar18 + 0xec);
  if (((0x12 < uVar20) || (uVar16 = *(uint *)(lVar18 + 0xe4), 6 < uVar16)) ||
     (uVar19 = (ulong)*(uint *)(lVar18 + 0xe8), 3 < *(uint *)(lVar18 + 0xe8))) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x5512,0x102ed8);
    (*pcVar17)();
  }
  lVar18 = (ulong)uVar16 * 0x10;
  if ((((0x84c < lVar18 + uVar20 * 0x70 + uVar19 * 4) ||
       (uVar2 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar2)) ||
      ((uVar3 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar3 ||
       ((uVar4 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar4 ||
        (uVar5 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar5)))))) ||
     ((uVar6 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar6 ||
      ((((((uVar7 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar7 ||
           (uVar8 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar8)) ||
          (uVar9 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar9)) ||
         ((uVar10 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar10 ||
          (uVar11 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar11)))) ||
        ((uVar12 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar12 ||
         ((uVar13 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar13 ||
          (uVar14 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar14)))))) ||
       (uVar15 = lVar18 + uVar20 * 0x70 + uVar19 * 4, 0x84c < uVar15)))))) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(1,0x102ed4);
    (*pcVar17)();
  }
  iVar1 = 0;
  if (*(int *)(pbr_vth1_data + uVar2) != 0) {
    iVar1 = (*(int *)(pbr_vth1_data + uVar2) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth2_data + uVar3) == 0) {
    local_64 = 0;
  }
  else {
    local_64 = (*(int *)(pbr_vth2_data + uVar3) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth3_data + uVar4) == 0) {
    local_68 = 0;
  }
  else {
    local_68 = (*(int *)(pbr_vth3_data + uVar4) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth4_data + uVar5) == 0) {
    local_6c = 0;
  }
  else {
    local_6c = (*(int *)(pbr_vth4_data + uVar5) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth5_data + uVar6) == 0) {
    local_70 = 0;
  }
  else {
    local_70 = (*(int *)(pbr_vth5_data + uVar6) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth6_data + uVar7) == 0) {
    local_74 = 0;
  }
  else {
    local_74 = (*(int *)(pbr_vth6_data + uVar7) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth7_data + uVar8) == 0) {
    iVar26 = 0;
  }
  else {
    iVar26 = (*(int *)(pbr_vth7_data + uVar8) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth8_data + uVar9) == 0) {
    iVar27 = 0;
  }
  else {
    iVar27 = (*(int *)(pbr_vth8_data + uVar9) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth9_data + uVar10) == 0) {
    iVar28 = 0;
  }
  else {
    iVar28 = (*(int *)(pbr_vth9_data + uVar10) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth10_data + uVar11) == 0) {
    iVar29 = 0;
  }
  else {
    iVar29 = (*(int *)(pbr_vth10_data + uVar11) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth11_data + uVar12) == 0) {
    iVar21 = 0;
  }
  else {
    iVar21 = (*(int *)(pbr_vth11_data + uVar12) * 0xff + -0x956a) / 2000 + 1;
  }
  lVar18 = (ulong)uVar16 * 0x10 + uVar20 * 0x70;
  if (*(int *)(pbr_vth12_data + uVar13) == 0) {
    iVar22 = 0;
    iVar25 = *(int *)(pbr_vth15_data + uVar19 * 4 + lVar18);
  }
  else {
    iVar22 = (*(int *)(pbr_vth12_data + uVar13) * 0xff + -0x956a) / 2000 + 1;
    iVar25 = *(int *)(pbr_vth15_data + uVar19 * 4 + lVar18);
  }
  if (*(int *)(pbr_vth13_data + uVar14) == 0) {
    iVar23 = 0;
  }
  else {
    iVar23 = (*(int *)(pbr_vth13_data + uVar14) * 0xff + -0x956a) / 2000 + 1;
  }
  if (*(int *)(pbr_vth14_data + uVar15) == 0) {
    iVar24 = 0;
  }
  else {
    iVar24 = (*(int *)(pbr_vth14_data + uVar15) * 0xff + -0x956a) / 2000 + 1;
  }
  if (iVar25 == 0) {
    iVar25 = 0;
  }
  else {
    iVar25 = (iVar25 * 0xff + -0x956a) / 2000 + 1;
  }
  snd_soc_component_write(param_1,0x34e1,iVar1);
  snd_soc_component_write(param_1,0x34e2,local_64);
  snd_soc_component_write(param_1,0x34e3,local_68);
  snd_soc_component_write(param_1,0x34e4,local_6c);
  snd_soc_component_write(param_1,0x34e5,local_70);
  snd_soc_component_write(param_1,0x34e6,local_74);
  snd_soc_component_write(param_1,0x34e7,iVar26);
  snd_soc_component_write(param_1,0x34e8,iVar27);
  snd_soc_component_write(param_1,0x34e9,iVar28);
  snd_soc_component_write(param_1,0x34ea,iVar29);
  snd_soc_component_write(param_1,0x34eb,iVar21);
  snd_soc_component_write(param_1,0x34ec,iVar22);
  snd_soc_component_write(param_1,0x34ed,iVar23);
  snd_soc_component_write(param_1,0x34ee,iVar24);
  snd_soc_component_write(param_1,0x34ef,iVar25);
  return;
}



//------------------------------------------------------------
// wsa884x_parse_port_params @ 00102ed8 size=1676
// signature: undefined wsa884x_parse_port_params(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

int wsa884x_parse_port_params(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char *pcVar7;
  long lVar8;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar8 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,swr-wsa-port-params",&local_4c);
  uVar1 = local_4c;
  if (lVar4 == 0) {
    pcVar6 = "missing port mapping prop %s\n";
    pcVar7 = "qcom,swr-wsa-port-params";
  }
  else {
    if (local_4c - 0xc0 < 0x30) {
      puVar5 = (undefined4 *)__kmalloc(local_4c,0xdc0);
      if (puVar5 == (undefined4 *)0x0) {
        iVar3 = -0xc;
      }
      else {
        iVar3 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2e8),"qcom,swr-wsa-port-params",puVar5,0x30,0
                          );
        if (-1 < iVar3) {
          if (3 < uVar1) {
            *(undefined4 *)(lVar8 + 0x140) = *puVar5;
            if (((((((((uVar1 & 0xfffffffc) != 4) &&
                     (*(undefined4 *)(lVar8 + 0x144) = puVar5[1], 7 < uVar1)) &&
                    ((uVar1 & 0xfffffffc) != 8)) &&
                   (((*(undefined4 *)(lVar8 + 0x148) = puVar5[2], 0xb < uVar1 &&
                     ((uVar1 & 0xfffffffc) != 0xc)) &&
                    ((*(undefined4 *)(lVar8 + 0x14c) = puVar5[3], 0xf < uVar1 &&
                     (((uVar1 & 0xfffffffc) != 0x10 &&
                      (*(undefined4 *)(lVar8 + 0x150) = puVar5[4], 0x13 < uVar1)))))))) &&
                  (((uVar1 & 0xfffffffc) != 0x14 &&
                   (((*(undefined4 *)(lVar8 + 0x154) = puVar5[5], 0x17 < uVar1 &&
                     ((uVar1 & 0xfffffffc) != 0x18)) &&
                    (*(undefined4 *)(lVar8 + 0x158) = puVar5[6], 0x1b < uVar1)))))) &&
                 ((((uVar1 & 0xfffffffc) != 0x1c &&
                   (*(undefined4 *)(lVar8 + 0x15c) = puVar5[7], 0x1f < uVar1)) &&
                  (((uVar1 & 0xfffffffc) != 0x20 &&
                   ((*(undefined4 *)(lVar8 + 0x160) = puVar5[8], 0x23 < uVar1 &&
                    ((uVar1 & 0xfffffffc) != 0x24)))))))) &&
                (*(undefined4 *)(lVar8 + 0x164) = puVar5[9], 0x27 < uVar1)) &&
               ((((uVar1 & 0xfffffffc) != 0x28 &&
                 (*(undefined4 *)(lVar8 + 0x168) = puVar5[10], 0x2b < uVar1)) &&
                ((uVar1 & 0xfffffffc) != 0x2c)))) {
              *(undefined4 *)(lVar8 + 0x16c) = puVar5[0xb];
              *(long *)(lVar8 + 0x200) = lVar8 + 0x140;
              if (((((((0x2f < uVar1) && ((uVar1 & 0xfffffffc) != 0x30)) &&
                     ((*(undefined4 *)(lVar8 + 0x170) = puVar5[0xc], 0x33 < uVar1 &&
                      (((uVar1 & 0xfffffffc) != 0x34 &&
                       (*(undefined4 *)(lVar8 + 0x174) = puVar5[0xd], 0x37 < uVar1)))))) &&
                    ((uVar1 & 0xfffffffc) != 0x38)) &&
                   ((((*(undefined4 *)(lVar8 + 0x178) = puVar5[0xe], 0x3b < uVar1 &&
                      ((uVar1 & 0xfffffffc) != 0x3c)) &&
                     (*(undefined4 *)(lVar8 + 0x17c) = puVar5[0xf], 0x3f < uVar1)) &&
                    (((uVar1 & 0xfffffffc) != 0x40 &&
                     (*(undefined4 *)(lVar8 + 0x180) = puVar5[0x10], 0x43 < uVar1)))))) &&
                  ((((uVar1 & 0xfffffffc) != 0x44 &&
                    ((*(undefined4 *)(lVar8 + 0x184) = puVar5[0x11], 0x47 < uVar1 &&
                     ((uVar1 & 0xfffffffc) != 0x48)))) &&
                   ((*(undefined4 *)(lVar8 + 0x188) = puVar5[0x12], 0x4b < uVar1 &&
                    (((((uVar1 & 0xfffffffc) != 0x4c &&
                       (*(undefined4 *)(lVar8 + 0x18c) = puVar5[0x13], 0x4f < uVar1)) &&
                      ((uVar1 & 0xfffffffc) != 0x50)) &&
                     ((*(undefined4 *)(lVar8 + 400) = puVar5[0x14], 0x53 < uVar1 &&
                      ((uVar1 & 0xfffffffc) != 0x54)))))))))) &&
                 (((*(undefined4 *)(lVar8 + 0x194) = puVar5[0x15], 0x57 < uVar1 &&
                   (((uVar1 & 0xfffffffc) != 0x58 &&
                    (*(undefined4 *)(lVar8 + 0x198) = puVar5[0x16], 0x5b < uVar1)))) &&
                  ((uVar1 & 0xfffffffc) != 0x5c)))) {
                *(undefined4 *)(lVar8 + 0x19c) = puVar5[0x17];
                *(long *)(lVar8 + 0x208) = lVar8 + 0x170;
                if ((((((0x5f < uVar1) && ((uVar1 & 0xfffffffc) != 0x60)) &&
                      (*(undefined4 *)(lVar8 + 0x1a0) = puVar5[0x18], 99 < uVar1)) &&
                     ((((uVar1 & 0xfffffffc) != 100 &&
                       (*(undefined4 *)(lVar8 + 0x1a4) = puVar5[0x19], 0x67 < uVar1)) &&
                      (((uVar1 & 0xfffffffc) != 0x68 &&
                       ((*(undefined4 *)(lVar8 + 0x1a8) = puVar5[0x1a], 0x6b < uVar1 &&
                        ((uVar1 & 0xfffffffc) != 0x6c)))))))) &&
                    ((*(undefined4 *)(lVar8 + 0x1ac) = puVar5[0x1b], 0x6f < uVar1 &&
                     ((((((((uVar1 & 0xfffffffc) != 0x70 &&
                           (*(undefined4 *)(lVar8 + 0x1b0) = puVar5[0x1c], 0x73 < uVar1)) &&
                          ((uVar1 & 0xfffffffc) != 0x74)) &&
                         ((*(undefined4 *)(lVar8 + 0x1b4) = puVar5[0x1d], 0x77 < uVar1 &&
                          ((uVar1 & 0xfffffffc) != 0x78)))) &&
                        (*(undefined4 *)(lVar8 + 0x1b8) = puVar5[0x1e], 0x7b < uVar1)) &&
                       (((uVar1 & 0xfffffffc) != 0x7c &&
                        (*(undefined4 *)(lVar8 + 0x1bc) = puVar5[0x1f], 0x7f < uVar1)))) &&
                      (((uVar1 & 0xfffffffc) != 0x80 &&
                       (((*(undefined4 *)(lVar8 + 0x1c0) = puVar5[0x20], 0x83 < uVar1 &&
                         ((uVar1 & 0xfffffffc) != 0x84)) &&
                        (*(undefined4 *)(lVar8 + 0x1c4) = puVar5[0x21], 0x87 < uVar1)))))))))) &&
                   ((((uVar1 & 0xfffffffc) != 0x88 &&
                     (*(undefined4 *)(lVar8 + 0x1c8) = puVar5[0x22], 0x8b < uVar1)) &&
                    ((uVar1 & 0xfffffffc) != 0x8c)))) {
                  *(undefined4 *)(lVar8 + 0x1cc) = puVar5[0x23];
                  *(long *)(lVar8 + 0x210) = lVar8 + 0x1a0;
                  if ((((0x8f < uVar1) && ((uVar1 & 0xfffffffc) != 0x90)) &&
                      ((*(undefined4 *)(lVar8 + 0x1d0) = puVar5[0x24], 0x93 < uVar1 &&
                       ((((uVar1 & 0xfffffffc) != 0x94 &&
                         (*(undefined4 *)(lVar8 + 0x1d4) = puVar5[0x25], 0x97 < uVar1)) &&
                        ((uVar1 & 0xfffffffc) != 0x98)))))) &&
                     ((((*(undefined4 *)(lVar8 + 0x1d8) = puVar5[0x26], 0x9b < uVar1 &&
                        ((uVar1 & 0xfffffffc) != 0x9c)) &&
                       ((*(undefined4 *)(lVar8 + 0x1dc) = puVar5[0x27], 0x9f < uVar1 &&
                        ((((((uVar1 & 0xfffffffc) != 0xa0 &&
                            (*(undefined4 *)(lVar8 + 0x1e0) = puVar5[0x28], 0xa3 < uVar1)) &&
                           (((uVar1 & 0xfffffffc) != 0xa4 &&
                            ((((*(undefined4 *)(lVar8 + 0x1e4) = puVar5[0x29], 0xa7 < uVar1 &&
                               ((uVar1 & 0xfffffffc) != 0xa8)) &&
                              (*(undefined4 *)(lVar8 + 0x1e8) = puVar5[0x2a], 0xab < uVar1)) &&
                             (((uVar1 & 0xfffffffc) != 0xac &&
                              (*(undefined4 *)(lVar8 + 0x1ec) = puVar5[0x2b], 0xaf < uVar1))))))))
                          && ((uVar1 & 0xfffffffc) != 0xb0)) &&
                         ((*(undefined4 *)(lVar8 + 0x1f0) = puVar5[0x2c], 0xb3 < uVar1 &&
                          ((uVar1 & 0xfffffffc) != 0xb4)))))))) &&
                      ((*(undefined4 *)(lVar8 + 500) = puVar5[0x2d], 0xb7 < uVar1 &&
                       ((((uVar1 & 0xfffffffc) != 0xb8 &&
                         (*(undefined4 *)(lVar8 + 0x1f8) = puVar5[0x2e], 0xbb < uVar1)) &&
                        ((uVar1 & 0xfffffffc) != 0xbc)))))))) {
                    *(undefined4 *)(lVar8 + 0x1fc) = puVar5[0x2f];
                    *(long *)(lVar8 + 0x218) = lVar8 + 0x1d0;
                    kfree(puVar5);
                    iVar3 = 0;
                    goto LAB_00103528;
                  }
                }
              }
            }
          }
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x103560);
          (*pcVar2)();
        }
        _dev_err(param_1,"%s: Failed to read port mapping from prop %s\n",
                 "wsa884x_parse_port_params","qcom,swr-wsa-port-params");
        kfree(puVar5);
      }
      goto LAB_00103528;
    }
    pcVar6 = "%s: port params not provided for all usecases\n";
    pcVar7 = "wsa884x_parse_port_params";
  }
  _dev_err(param_1,pcVar6,pcVar7);
  iVar3 = -0x16;
LAB_00103528:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wsa884x_handle_post_irq @ 00103568 size=480
// signature: undefined wsa884x_handle_post_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_handle_post_irq(undefined8 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (param_1 == (undefined8 *)0x0) {
    uVar2 = 0;
  }
  else if (*(int *)(param_1 + 0x1a) == 0) {
    *(undefined4 *)(param_1 + 0x1a) = 0;
    if ((param_1[0x55] & 1) != 0) {
      regmap_update_bits_base(*param_1,0x3430,1,1,0,0,0);
    }
    usleep_range_state(1000,0x44c,2);
    regmap_read(*param_1,0x3583,(long)&local_30 + 4);
    regmap_read(*param_1,0x3584,&local_30);
    uVar2 = 1;
    *(bool *)(param_1[2] + 0x3f0) = local_30._4_4_ != 0 || (int)local_30 != 0;
    if (*(char *)(param_1[2] + 0x3f0) != '\0') {
      regmap_update_bits_base(*param_1,0x3430,1,0,0,0,0);
      *(undefined4 *)(param_1 + 0x1a) = 1;
      usleep_range_state(1000,0x44c,2);
      *(undefined4 *)(param_1 + 0x1a) = 0;
      if ((param_1[0x55] & 1) != 0) {
        regmap_update_bits_base(*param_1,0x3430,1,1,0,0,0);
      }
      usleep_range_state(1000,0x44c,2);
      regmap_read(*param_1,0x3583,(long)&local_30 + 4);
      regmap_read(*param_1,0x3584,&local_30);
      *(bool *)(param_1[2] + 0x3f0) = local_30._4_4_ != 0 || (int)local_30 != 0;
      if (*(char *)(param_1[2] + 0x3f0) != '\0') {
        regmap_update_bits_base(*param_1,0x3430,1,0,0,0,0);
        *(undefined4 *)(param_1 + 0x1a) = 1;
        usleep_range_state(1000,0x44c,2);
      }
    }
  }
  else {
    uVar2 = 1;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// wsa884x_codec_probe @ 0010374c size=840
// signature: undefined wsa884x_codec_probe(void)
// callers: []
//------------------------------------------------------------

void wsa884x_codec_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  size_t __n;
  undefined8 uVar3;
  int iVar4;
  char *__s;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
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
  puVar5 = *(undefined8 **)(*(long *)(param_1 + 0x18) + 0x98);
  if ((puVar5 == (undefined8 *)0x0) || (*(long *)(param_1 + 0x10) == 0)) {
    uVar3 = 0xffffffea;
  }
  else {
    lVar1 = param_1 + 0xd0;
    snd_soc_component_init_regmap(param_1,*puVar5);
    puVar5[3] = param_1;
    uVar2 = snd_soc_component_read(param_1,0x3880);
    *(uint *)(puVar5 + 0x1b) = uVar2 & 0xf;
    uVar2 = snd_soc_component_read(param_1,0x3401);
    *(undefined4 *)(puVar5 + 0xf) = 2;
    *(uint *)((long)puVar5 + 0xdc) = uVar2 & 0xff;
    lVar6 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
    if (lVar6 != 0) {
      lVar7 = 0;
      do {
        snd_soc_component_update_bits
                  (param_1,*(undefined2 *)((long)&reg_init + lVar7),(&DAT_00106c02)[lVar7],
                   (&DAT_00106c03)[lVar7]);
        lVar7 = lVar7 + 4;
      } while (lVar7 != 0x8c);
      if (*(char *)(lVar6 + 0x2cc) != '\0') {
        snd_soc_component_update_bits(param_1,0x34d6,0xff,0x8c);
      }
      if (*(int *)(lVar6 + 0xe4) == 2) {
        snd_soc_component_update_bits(param_1,0x34d1,0xf0,0x20);
        snd_soc_component_update_bits(param_1,0x34d2,0x1f,0x13);
        snd_soc_component_update_bits(param_1,0x3005,0xf,3);
        snd_soc_component_update_bits(param_1,0x3005,0xf0,0x30);
        snd_soc_component_update_bits(param_1,0x3045,0xff,6);
        snd_soc_component_update_bits(param_1,0x3046,0xff,0x14);
        snd_soc_component_update_bits(param_1,0x3047,0xff,0x19);
        snd_soc_component_update_bits(param_1,0x3048,0xff,0x1b);
        snd_soc_component_update_bits(param_1,0x3049,0xff,0x1c);
        snd_soc_component_update_bits(param_1,0x306a,2,2);
      }
      snd_soc_component_update_bits(param_1,0x3005,0xff,0x77);
      snd_soc_component_update_bits(param_1,0x3433,0xff,0xc0);
      snd_soc_component_update_bits(param_1,0x3460,0xff,0x1d);
      snd_soc_component_update_bits(param_1,0x3006,0xff,0x40);
      uVar2 = *(int *)(lVar6 + 0x2c8) - 1;
      iVar4 = uVar2 * -0x10 + 0x30;
      if (2 < uVar2) {
        iVar4 = 8;
      }
      snd_soc_component_update_bits(param_1,0x3432,0x38,iVar4);
    }
    *(undefined4 *)(puVar5 + 0xe) = 0;
    local_70 = 0;
    uStack_6e = 0;
    uStack_6c = 0;
    local_68 = 0;
    uStack_64 = 0;
    local_60 = 0;
    uStack_5c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    __s = *(char **)(puVar5[0x57] + 0xa8);
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
    local_70 = s_SWR_DAC_Port_00112bc3._0_2_;
    uStack_6e = s_SWR_DAC_Port_00112bc3._2_2_;
    uStack_6c = s_SWR_DAC_Port_00112bc3._4_4_;
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
// wsa884x_codec_remove @ 00103a98 size=40
// signature: undefined wsa884x_codec_remove(void)
// callers: []
//------------------------------------------------------------

void wsa884x_codec_remove(long param_1)

{
  if (*(long *)(*(long *)(param_1 + 0x18) + 0x98) != 0) {
    snd_soc_component_exit_regmap();
  }
  return;
}



//------------------------------------------------------------
// wsa884x_soc_codec_suspend @ 00103ac4 size=28
// signature: undefined wsa884x_soc_codec_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_soc_codec_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x25) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// wsa884x_soc_codec_resume @ 00103ae4 size=24
// signature: undefined wsa884x_soc_codec_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_soc_codec_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x25) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// wsa_pa_gain_get @ 00103b00 size=28
// signature: undefined wsa_pa_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_pa_gain_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0xe0);
  return 0;
}



//------------------------------------------------------------
// wsa_pa_gain_put @ 00103b20 size=72
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
  *(char *)(lVar3 + 0xe0) = (char)uVar2;
  if (*(char *)(lVar3 + 0x20) == '\0') {
    snd_soc_component_update_bits(lVar1,0x34b1,0x3e,((uint)uVar2 & 0xff) << 1);
  }
  return 0;
}



//------------------------------------------------------------
// wsa_get_temp @ 00103b6c size=868
// signature: undefined wsa_get_temp(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_get_temp(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  char cVar13;
  long lVar14;
  
  lVar14 = *(long *)(param_1 + 0x80);
  lVar12 = *(long *)(*(long *)(lVar14 + 0x18) + 0x98);
  if ((*(ulong *)(lVar12 + 0x2a8) & 1) == 0) {
    if (lVar12 == 0) {
      iVar10 = 0;
    }
    else {
      cVar13 = '\x03';
      do {
        lVar11 = *(long *)(*(long *)(lVar14 + 0x18) + 0x98);
        if (lVar11 == 0) {
          iVar10 = ___ratelimit(wsa884x_temp_reg_read__rs,"wsa884x_temp_reg_read");
          if (iVar10 != 0) {
            _dev_err(*(undefined8 *)(lVar14 + 0x18),"%s: wsa884x is NULL\n","wsa884x_temp_reg_read")
            ;
          }
          iVar10 = ___ratelimit(wsa884x_get_temperature__rs,"wsa884x_get_temperature");
          if (iVar10 != 0) {
            _printk(&DAT_00112671,"wsa884x_get_temperature",0xffffffea,
                    *(undefined4 *)(lVar12 + 0xd4));
          }
          iVar10 = *(int *)(lVar12 + 0xd4);
          goto LAB_00103e64;
        }
        lVar11 = lVar11 + 0x80;
        mutex_lock(lVar11);
        snd_soc_component_update_bits(lVar14,0x343d,1,1);
        snd_soc_component_update_bits(lVar14,0x343d,4,4);
        snd_soc_component_update_bits(lVar14,0x343d,2,2);
        snd_soc_component_update_bits(lVar14,0x343d,0x80,0x80);
        snd_soc_component_update_bits(lVar14,0x343d,0x20,0x20);
        snd_soc_component_update_bits(lVar14,0x343d,0x40,0x40);
        snd_soc_component_update_bits(lVar14,0x3450,1,0);
        bVar4 = snd_soc_component_read(lVar14,0x3452);
        uVar9 = snd_soc_component_read(lVar14,0x3453);
        snd_soc_component_update_bits(lVar14,0x3450,1,1);
        bVar5 = snd_soc_component_read(lVar14,0x3881);
        bVar6 = snd_soc_component_read(lVar14,0x3882);
        bVar7 = snd_soc_component_read(lVar14,0x3883);
        bVar8 = snd_soc_component_read(lVar14,0x3884);
        snd_soc_component_update_bits(lVar14,0x343d,0xe7,0);
        mutex_unlock(lVar11);
        if (((((bVar5 - 0x5d < 0xffffffe7) || ((bVar6 & 0x3f) != 0)) || (bVar7 < 0xb9)) ||
            ((0xda < bVar7 || ((bVar8 & 0x3f) != 0)))) &&
           (iVar10 = ___ratelimit(wsa884x_get_temperature__rs_106,"wsa884x_get_temperature"),
           iVar10 != 0)) {
          _printk("%s: Temperature registers[%d %d %d %d] are out of range\n",
                  "wsa884x_get_temperature",bVar5,bVar6,bVar7,bVar8);
        }
        _printk(&DAT_0011269f,"wsa884x_get_temperature",bVar5,bVar6,bVar7,bVar8,bVar4,uVar9 & 0xff);
        uVar1 = (uint)(ushort)(CONCAT11(bVar5,bVar6) >> 6);
        uVar2 = (uint)(ushort)(CONCAT11(bVar7,bVar8) >> 6);
        uVar9 = (uVar9 & 0xff | (uint)bVar4 << 8) >> 6;
        iVar10 = uVar2 - uVar1;
        if (iVar10 == 0) {
          iVar10 = 0xffff;
        }
        else {
          iVar3 = 0;
          if (iVar10 != 0) {
            iVar3 = (int)((uVar9 - uVar1) * 0xa0) / iVar10;
          }
          iVar10 = iVar3 + -10;
          if (0xffffffd8 < iVar3 - 0x37U) break;
        }
        cVar13 = cVar13 + -1;
        msleep(10);
      } while (cVar13 != '\0');
      *(int *)(lVar12 + 0xd4) = iVar10;
      _printk(&DAT_00112c77,"wsa884x_get_temperature",iVar10,uVar9,uVar1,uVar2);
    }
  }
  else {
    iVar10 = *(int *)(lVar12 + 0xd4);
  }
LAB_00103e64:
  *(long *)(param_2 + 0x48) = (long)iVar10;
  return 0;
}



//------------------------------------------------------------
// wsa884x_get_dev_num @ 00103ed4 size=116
// signature: undefined wsa884x_get_dev_num(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_get_dev_num(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x80) != 0) {
    lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
    if (lVar2 != 0) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(*(long *)(lVar2 + 0x10) + 0x40);
      return 0;
    }
    iVar1 = ___ratelimit(wsa884x_get_dev_num__rs,"wsa884x_get_dev_num");
    if (iVar1 != 0) {
      _printk(&DAT_00112495,"wsa884x_get_dev_num");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// wsa_dev_mode_get @ 00103f4c size=28
// signature: undefined wsa_dev_mode_get(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_dev_mode_get(long param_1,long param_2)

{
  *(long *)(param_2 + 0x48) =
       (long)*(int *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x74);
  return 0;
}



//------------------------------------------------------------
// wsa_dev_mode_put @ 00103f6c size=96
// signature: undefined wsa_dev_mode_put(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa_dev_mode_put(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  int iVar4;
  
  if (1 < *(ulong *)(param_2 + 0x48)) {
    return 0xffffffea;
  }
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  iVar4 = (int)*(ulong *)(param_2 + 0x48);
  *(int *)(lVar3 + 0x74) = iVar4;
  uVar1 = *(byte *)(lVar3 + 0x10c) - 1;
  uVar1 = iVar4 + (uVar1 - (uVar1 + ((uVar1 & 0x8000) >> 0xf) & 0x7ffffffe)) * 2;
  if (3 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103fcc);
    (*pcVar2)();
  }
  *(char *)(lVar3 + 0xec) = (char)*(undefined4 *)(lVar3 + (ulong)uVar1 * 4 + 0xf0);
  return 0;
}



//------------------------------------------------------------
// wsa884x_get_compander @ 00103fd0 size=28
// signature: undefined wsa884x_get_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_get_compander(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x20);
  return 0;
}



//------------------------------------------------------------
// wsa884x_set_compander @ 00103ff0 size=36
// signature: undefined wsa884x_set_compander(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_set_compander(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x20) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa884x_get_visense @ 00104018 size=28
// signature: undefined wsa884x_get_visense(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_get_visense(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x21);
  return 0;
}



//------------------------------------------------------------
// wsa884x_set_visense @ 00104038 size=36
// signature: undefined wsa884x_set_visense(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_set_visense(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x21) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa884x_get_pbr @ 00104060 size=28
// signature: undefined wsa884x_get_pbr(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_get_pbr(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x23);
  return 0;
}



//------------------------------------------------------------
// wsa884x_set_pbr @ 00104080 size=36
// signature: undefined wsa884x_set_pbr(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_set_pbr(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x23) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa884x_get_cps @ 001040a8 size=28
// signature: undefined wsa884x_get_cps(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_get_cps(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x22);
  return 0;
}



//------------------------------------------------------------
// wsa884x_set_cps @ 001040c8 size=36
// signature: undefined wsa884x_set_cps(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_set_cps(long param_1,long param_2)

{
  *(bool *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x22) =
       *(int *)(param_2 + 0x48) != 0;
  return 0;
}



//------------------------------------------------------------
// wsa884x_enable_swr_dac_port @ 001040f0 size=1232
// signature: undefined wsa884x_enable_swr_dac_port(void)
// callers: []
//------------------------------------------------------------

void wsa884x_enable_swr_dac_port(long param_1,undefined8 param_2,undefined4 param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  int iVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  undefined1 *puVar14;
  long lVar15;
  long lVar16;
  undefined4 local_60;
  undefined2 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined4 local_50;
  undefined2 local_4c;
  undefined4 local_48;
  undefined2 local_44;
  undefined4 local_40 [2];
  ulong local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar15 = sp_el0;
  local_28 = *(long *)(lVar15 + 0x638);
  lVar16 = *(long *)(param_1 + 0x28);
  local_44 = 0;
  local_48 = 0;
  local_4c = 0;
  lVar15 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
  local_50 = 0;
  local_54 = 0;
  local_58 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_5c = 0;
  local_60 = 0;
  if (lVar15 == 0) {
    uVar9 = 0xffffffea;
    goto switchD_00104168_caseD_3;
  }
  uVar9 = 0;
  switch(param_3) {
  case 1:
    lVar12 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
    local_40[0] = *(undefined4 *)(lVar12 + 0x2c);
    if (*(int *)(lVar15 + 0x74) == 1) {
      local_40[0] = 4800000;
    }
    lVar13 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
    local_48._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x34),*(undefined1 *)(lVar12 + 0x28));
    uVar7 = (ushort)local_48;
    local_48 = (uint)(ushort)local_48;
    local_50._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x3c),*(undefined1 *)(lVar12 + 0x30));
    uVar6 = (ushort)local_50;
    local_50 = (uint)(ushort)local_50;
    local_58._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x35),*(undefined1 *)(lVar12 + 0x29));
    uVar5 = (ushort)local_58;
    local_58 = (uint)(ushort)local_58;
    local_40[1] = *(undefined4 *)(lVar13 + 0x38);
    local_60._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x3d),*(undefined1 *)(lVar12 + 0x31));
    uVar4 = (ushort)local_60;
    local_60 = (uint)(ushort)local_60;
    if (*(char *)(lVar15 + 0x23) == '\0') {
      uVar10 = 2;
      if (*(char *)(lVar15 + 0x21) != '\0') goto LAB_00104300;
LAB_0010436c:
      cVar2 = *(char *)(lVar15 + 0x22);
    }
    else {
      lVar12 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
      local_48._0_3_ = CONCAT12(*(undefined1 *)(lVar12 + 0x4c),uVar7);
      local_48 = (uint)(uint3)local_48;
      local_50 = (uint)CONCAT12(*(undefined1 *)(lVar12 + 0x54),uVar6);
      local_58._0_3_ = CONCAT12(*(undefined1 *)(lVar12 + 0x4d),uVar5);
      local_58 = (uint)(uint3)local_58;
      local_38 = (ulong)*(uint *)(lVar12 + 0x50);
      local_60._0_3_ = CONCAT12(*(undefined1 *)(lVar12 + 0x55),uVar4);
      local_60 = (uint)(uint3)local_60;
      puVar1 = (ulong *)(lVar15 + 0x2b0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 4;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      uVar10 = 3;
      if (*(char *)(lVar15 + 0x21) == '\0') goto LAB_0010436c;
LAB_00104300:
      lVar12 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
      *(undefined1 *)((ulong)&local_48 | uVar10) = *(undefined1 *)(lVar12 + 0x58);
      *(undefined1 *)((ulong)&local_50 | uVar10) = *(undefined1 *)(lVar12 + 0x60);
      puVar14 = (undefined1 *)((ulong)&local_60 | uVar10);
      *(undefined1 *)((ulong)&local_58 | uVar10) = *(undefined1 *)(lVar12 + 0x59);
      local_40[uVar10] = *(undefined4 *)(lVar12 + 0x5c);
      uVar10 = (ulong)((int)uVar10 + 1);
      *puVar14 = *(undefined1 *)(lVar12 + 0x61);
      puVar1 = (ulong *)(lVar15 + 0x2b0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 2;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      cVar2 = *(char *)(lVar15 + 0x22);
    }
    uVar11 = uVar10;
    if (cVar2 != '\0') {
      lVar16 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
      *(undefined1 *)((long)local_40 + (uVar10 - 8)) = *(undefined1 *)(lVar16 + 100);
      *(undefined1 *)((long)local_40 + (uVar10 - 0x10)) = *(undefined1 *)(lVar16 + 0x6c);
      *(undefined1 *)((long)local_40 + (uVar10 - 0x18)) = *(undefined1 *)(lVar16 + 0x65);
      local_40[uVar10] = *(undefined4 *)(lVar16 + 0x68);
      uVar11 = (ulong)((int)uVar10 + 1);
      *(undefined1 *)((long)local_40 + (uVar10 - 0x20)) = *(undefined1 *)(lVar16 + 0x6d);
      puVar1 = (ulong *)(lVar15 + 0x2b0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 8;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    swr_connect_port(*(undefined8 *)(lVar15 + 0x10),&local_48,uVar11,&local_58,local_40,&local_50,
                     &local_60);
    break;
  case 2:
    puVar1 = (ulong *)(lVar15 + 0x2a8);
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
    goto switchD_00104168_caseD_3;
  case 4:
    lVar12 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
    lVar13 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
    local_48._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x34),*(undefined1 *)(lVar12 + 0x28));
    uVar6 = (ushort)local_48;
    local_48 = (uint)(ushort)local_48;
    local_58._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x35),*(undefined1 *)(lVar12 + 0x29));
    uVar5 = (ushort)local_58;
    local_58 = (uint)(ushort)local_58;
    local_60._0_2_ = CONCAT11(*(undefined1 *)(lVar13 + 0x3d),*(undefined1 *)(lVar12 + 0x31));
    uVar4 = (ushort)local_60;
    local_60 = (uint)(ushort)local_60;
    if ((*(char *)(lVar15 + 0x23) == '\0') ||
       (((uint)*(undefined8 *)(lVar15 + 0x2b0) >> 2 & 1) == 0)) {
      uVar10 = 2;
      if (*(char *)(lVar15 + 0x21) != '\0') goto LAB_0010442c;
LAB_00104484:
      cVar2 = *(char *)(lVar15 + 0x22);
      uVar11 = uVar10;
    }
    else {
      lVar12 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
      local_48._0_3_ = CONCAT12(*(undefined1 *)(lVar12 + 0x4c),uVar6);
      local_48 = (uint)(uint3)local_48;
      local_58._0_3_ = CONCAT12(*(undefined1 *)(lVar12 + 0x4d),uVar5);
      local_58 = (uint)(uint3)local_58;
      local_60._0_3_ = CONCAT12(*(undefined1 *)(lVar12 + 0x55),uVar4);
      local_60 = (uint)(uint3)local_60;
      puVar1 = (ulong *)(lVar15 + 0x2b0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      uVar10 = 3;
      if (*(char *)(lVar15 + 0x21) == '\0') goto LAB_00104484;
LAB_0010442c:
      if (((uint)*(undefined8 *)(lVar15 + 0x2b0) >> 1 & 1) == 0) goto LAB_00104484;
      uVar11 = (ulong)((int)uVar10 + 1);
      lVar12 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
      *(undefined1 *)((ulong)&local_48 | uVar10) = *(undefined1 *)(lVar12 + 0x58);
      *(undefined1 *)((ulong)&local_58 | uVar10) = *(undefined1 *)(lVar12 + 0x59);
      *(undefined1 *)((ulong)&local_60 | uVar10) = *(undefined1 *)(lVar12 + 0x61);
      puVar1 = (ulong *)(lVar15 + 0x2b0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      cVar2 = *(char *)(lVar15 + 0x22);
    }
    uVar10 = uVar11;
    if ((cVar2 != '\0') && (((uint)*(undefined8 *)(lVar15 + 0x2b0) >> 3 & 1) != 0)) {
      uVar10 = (ulong)((int)uVar11 + 1);
      lVar16 = *(long *)(*(long *)(lVar16 + -0xb8) + 0x98);
      *(undefined1 *)((long)local_40 + (uVar11 - 8)) = *(undefined1 *)(lVar16 + 100);
      *(undefined1 *)((long)local_40 + (uVar11 - 0x18)) = *(undefined1 *)(lVar16 + 0x65);
      *(undefined1 *)((long)local_40 + (uVar11 - 0x20)) = *(undefined1 *)(lVar16 + 0x6d);
      puVar1 = (ulong *)(lVar15 + 0x2b0);
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
    swr_disconnect_port(*(undefined8 *)(lVar15 + 0x10),&local_48,uVar10,&local_58,&local_60);
    break;
  case 8:
    iVar8 = swr_set_device_group(*(undefined8 *)(lVar15 + 0x10),0);
    if ((iVar8 != 0) &&
       (iVar8 = ___ratelimit(wsa884x_enable_swr_dac_port__rs,"wsa884x_enable_swr_dac_port"),
       iVar8 != 0)) {
      _dev_err(*(undefined8 *)(lVar16 + -0xb8),"%s: set num ch failed\n",
               "wsa884x_enable_swr_dac_port");
    }
    swr_slvdev_datapath_control
              (*(long *)(lVar15 + 0x10),*(undefined1 *)(*(long *)(lVar15 + 0x10) + 0x40),0);
  }
  uVar9 = 0;
switchD_00104168_caseD_3:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// wsa884x_spkr_event @ 0010461c size=460
// signature: undefined wsa884x_spkr_event(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_spkr_event(long param_1,undefined8 param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = *(long *)(param_1 + 0x28) + -0xd0;
  lVar10 = *(long *)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (param_3 == 4) {
    snd_soc_component_update_bits(lVar9,0x3430,1,0);
    snd_soc_component_update_bits(lVar9,0x348b,1,0);
    puVar1 = (ulong *)(lVar10 + 0x2a8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffe;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    puVar1 = (ulong *)(lVar10 + 0x2a8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffb;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    *(undefined4 *)(lVar10 + 0xd0) = 0;
    return 0;
  }
  if (param_3 != 2) {
    return 0;
  }
  swr_slvdev_datapath_control
            (*(long *)(lVar10 + 0x10),*(undefined1 *)(*(long *)(lVar10 + 0x10) + 0x40),1);
  wsa884x_set_gain_parameters(lVar9);
  if (*(int *)(lVar10 + 0x74) == 0) {
    uVar5 = 0x34b0;
    uVar6 = 0xf0;
    uVar7 = 0xf0;
  }
  else {
    snd_soc_component_update_bits(lVar9,0x34b0,0xf0,0x30);
    snd_soc_component_update_bits(lVar9,0x341a,2,2);
    uVar5 = 0x304a;
    uVar6 = 8;
    uVar7 = 8;
  }
  snd_soc_component_update_bits(lVar9,uVar5,uVar6,uVar7);
  if (*(char *)(lVar10 + 0x23) == '\0') {
    snd_soc_component_update_bits(lVar9,0x3091,0x80,0x80);
    iVar8 = 0x54;
    if (*(byte *)(lVar10 + 0xec) < 6) {
      iVar8 = 0x24;
    }
  }
  else {
    snd_soc_component_update_bits(lVar9,0x3091,0x80,0);
    uVar4 = *(int *)(lVar10 + 0xe4) - 1;
    if (2 < uVar4) goto LAB_0010477c;
    iVar8 = uVar4 * -0x10 + 0x54;
  }
  snd_soc_component_update_bits(lVar9,0x3091,0x7c,iVar8);
LAB_0010477c:
  swr_remove_from_group(*(long *)(lVar10 + 0x10),*(undefined1 *)(*(long *)(lVar10 + 0x10) + 0x40));
  if ((((uint)*(undefined8 *)(lVar10 + 0x2a8) >> 2 & 1) != 0) && (*(int *)(lVar10 + 0xd0) == 0)) {
    snd_soc_component_update_bits(lVar9,0x3430,1,1);
  }
  return 0;
}



//------------------------------------------------------------
// wsa884x_swr_down @ 00104800 size=164
// signature: undefined wsa884x_swr_down(void)
// callers: [wsa884x_event_notify]
//------------------------------------------------------------

void wsa884x_swr_down(long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msm_cdc_pinctrl_select_sleep_state(*(undefined8 *)(param_1 + 200));
  if (iVar1 != 0) {
    iVar2 = ___ratelimit(wsa884x_gpio_ctrl__rs,"wsa884x_gpio_ctrl");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 8),"%s: Failed to turn state %d; ret=%d\n",
               "wsa884x_gpio_ctrl",0,iVar1);
    }
    iVar1 = ___ratelimit(wsa884x_swr_down__rs,"wsa884x_swr_down");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 8),"%s: Failed to disable gpio\n","wsa884x_swr_down");
    }
  }
  return;
}



//------------------------------------------------------------
// wsa884x_swr_up @ 001048a4 size=164
// signature: undefined wsa884x_swr_up(void)
// callers: [wsa884x_event_notify]
//------------------------------------------------------------

void wsa884x_swr_up(long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = msm_cdc_pinctrl_select_active_state(*(undefined8 *)(param_1 + 200));
  if (iVar1 != 0) {
    iVar2 = ___ratelimit(wsa884x_gpio_ctrl__rs,"wsa884x_gpio_ctrl");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 8),"%s: Failed to turn state %d; ret=%d\n",
               "wsa884x_gpio_ctrl",1,iVar1);
    }
    iVar1 = ___ratelimit(wsa884x_swr_up__rs,"wsa884x_swr_up");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 8),"%s: Failed to enable gpio\n","wsa884x_swr_up");
    }
  }
  return;
}



//------------------------------------------------------------
// wsa884x_swr_reset @ 00104948 size=336
// signature: undefined wsa884x_swr_reset(void)
// callers: [wsa884x_event_notify]
//------------------------------------------------------------

void wsa884x_swr_reset(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  undefined1 local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = param_1[2];
  local_3c[0] = 0;
  iVar1 = swr_get_logical_dev_num(lVar2,*(undefined8 *)(lVar2 + 0x3d8),local_3c);
  if (iVar1 != 0) {
    usleep_range_state(1000,0x44c,2);
    iVar1 = swr_get_logical_dev_num(lVar2,*(undefined8 *)(lVar2 + 0x3d8),local_3c);
    if (iVar1 != 0) {
      usleep_range_state(1000,0x44c,2);
      iVar1 = swr_get_logical_dev_num(lVar2,*(undefined8 *)(lVar2 + 0x3d8),local_3c);
      if (iVar1 != 0) {
        usleep_range_state(1000,0x44c,2);
        iVar1 = swr_get_logical_dev_num(lVar2,*(undefined8 *)(lVar2 + 0x3d8),local_3c);
        if (iVar1 != 0) {
          usleep_range_state(1000,0x44c,2);
          iVar1 = swr_get_logical_dev_num(lVar2,*(undefined8 *)(lVar2 + 0x3d8),local_3c);
          if (iVar1 != 0) {
            usleep_range_state(1000,0x44c,2);
            swr_get_logical_dev_num(lVar2,*(undefined8 *)(lVar2 + 0x3d8),local_3c);
          }
        }
      }
    }
  }
  *(undefined1 *)(lVar2 + 0x40) = local_3c[0];
  mutex_lock(param_1 + 0x10);
  regcache_mark_dirty(*param_1);
  regcache_sync(*param_1);
  mutex_unlock(param_1 + 0x10);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// codec_debug_read @ 00104a9c size=228
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
    snprintf(local_40,8,"0x%x\n",(uint)*(byte *)(lVar3 + 0x240));
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
// codec_debug_peek_write @ 00104b84 size=600
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
  goto LAB_00104d64;
  __check_object_size(local_58,param_3,0);
  puVar8 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
     (uVar4 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
    uVar4 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar5 = param_3;
  if (0x8000000000 - param_3 < uVar4) {
LAB_00104d90:
    memset(local_58 + (param_3 - uVar5),0,uVar5);
    if ((int)uVar5 != 0) {
      uVar4 = 0xfffffffffffffff2;
      goto LAB_00104d64;
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
    if (uVar5 != 0) goto LAB_00104d90;
  }
  if (0x1f < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x104dc4);
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
        swr_read(lVar9,*(undefined1 *)(lVar9 + 0x40),local_70[0] & 0xffffffff,lVar10 + 0x240,1);
        uVar4 = param_3;
        goto LAB_00104d64;
      }
    }
  }
  uVar4 = 0xffffffffffffffea;
LAB_00104d64:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_open @ 00104df8 size=16
// signature: undefined codec_debug_open(void)
// callers: []
//------------------------------------------------------------

undefined8 codec_debug_open(long param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x2b8);
  return 0;
}



//------------------------------------------------------------
// codec_debug_write @ 00104e0c size=660
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
        pcVar2 = (code *)SoftwareBreakpoint(1,0x105088);
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
            goto LAB_00104f9c;
          }
        }
      }
      uVar4 = 0xffffffffffffffea;
    }
    else {
      uVar4 = 0xfffffffffffffff2;
    }
  }
LAB_00104f9c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// codec_debug_dump @ 001050bc size=1020
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
  int iVar5;
  ulong uVar6;
  undefined *puVar7;
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
  if ((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
     (((param_4 != (long *)0x0 && (lVar9 = *(long *)(param_1 + 0xd8), lVar9 != 0)) &&
      (-1 < *param_4)))) {
    uVar11 = 0;
    local_84 = 0;
    iVar5 = (int)*param_4;
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
    if (iVar5 < 0x17d78) {
      uVar11 = 0;
      puVar3 = (undefined8 *)sp_el0;
      param3 = iVar5 / 0xc + 0x40;
      do {
        if (((((0x864 < param3 - 0xf36 >> 1) && (9 < param3 - 0xf26)) &&
             ((((0x19 < param3 - 0xf06 &&
                (((((0x8c7 < param3 - 0x638 && (uVar4 = param3 & 0xfffffef8, 199 < uVar4 - 0x438))
                   && (199 < uVar4 - 0x238)) &&
                  ((199 < param3 - 0x138 && ((param3 & 0xfffffff8) != 0x628)))) && (uVar4 != 0x428))
                )) && ((uVar4 != 0x228 && ((param3 & 0xfffffff8) != 0x128)))) &&
              (0x19 < param3 - 0x606)))) &&
            ((((0x19 < (param3 & 0xfffffefe) - 0x406 && (0x19 < (param3 & 0xfffffefe) - 0x206)) &&
              (0x19 < param3 - 0x106)) &&
             (((0xe < (param3 & 0xffffffef) - 0xe1 && (0xe < param3 - 0xd1)) &&
              ((6 < param3 - 0xc9 && ((5 < param3 - 0xc2 && (0x4e < param3 - 0x71)))))))))) &&
           ((0xe < param3 - 0x61 &&
            (((9 < param3 - 0x56 && (2 < param3 - 0x47)) && (4 < param3 - 0x4b)))))) {
          swr_read(lVar9,*(undefined1 *)(lVar9 + 0x40),param3,&local_84,1);
          uVar4 = snprintf(local_80,0x14,"0x%.3x: 0x%.2x\n",param3,local_84 & 0xff);
          if ((int)uVar4 < 0) {
            iVar5 = ___ratelimit(swr_slave_reg_show__rs,"swr_slave_reg_show");
            if (iVar5 != 0) {
              puVar7 = &DAT_0011235e;
              goto LAB_001054bc;
            }
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
              uVar6 = uVar10;
              if (uVar8 <= 0x8000000000 - uVar10) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar8 = daif;
                  if ((uVar8 & 0x80) == 0) {
                    uVar6 = daif;
                    daif = uVar6 | 0xc0;
                  }
                  uVar6 = ttbr1_el1;
                  ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar3[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar8;
                }
                uVar6 = __arch_copy_to_user(uVar2 & 0xff7fffffffffffff,local_80,uVar10);
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
              if (uVar6 == 0) {
                *param_4 = *param_4 + uVar10;
                uVar11 = uVar11 + uVar10;
                goto LAB_0010516c;
              }
            }
            else {
              __copy_overflow(0x14,uVar10);
            }
            iVar5 = ___ratelimit(swr_slave_reg_show__rs_149,"swr_slave_reg_show");
            if (iVar5 != 0) {
              puVar7 = &DAT_0011237d;
LAB_001054bc:
              _printk(puVar7,"swr_slave_reg_show");
            }
          }
          uVar11 = 0xfffffffffffffff2;
          break;
        }
LAB_0010516c:
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
// wsa884x_swr_suspend @ 001054d4 size=204
// signature: undefined wsa884x_swr_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_swr_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (lVar6 = *(long *)(param_1 + 0x98), lVar6 == 0)) {
    iVar4 = ___ratelimit(wsa884x_swr_suspend__rs,"wsa884x_swr_suspend");
    if (iVar4 != 0) {
      _dev_err(param_1,"%s: wsa884x private data is NULL\n","wsa884x_swr_suspend");
    }
    uVar5 = 0xffffffea;
  }
  else {
    if ((*(char *)(lVar6 + 0x25) != '\0') ||
       ((*(long *)(lVar6 + 0x18) != 0 && (*(int *)(*(long *)(lVar6 + 0x18) + 0xd0) == 0)))) {
      msm_cdc_set_supplies_lpm_mode
                (param_1,*(undefined8 *)(lVar6 + 0x2a0),*(undefined8 *)(lVar6 + 0x290),
                 *(undefined4 *)(lVar6 + 0x298),1);
      puVar1 = (ulong *)(lVar6 + 0x2a8);
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
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// wsa884x_swr_resume @ 001055b0 size=148
// signature: undefined wsa884x_swr_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wsa884x_swr_resume(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (lVar5 = *(long *)(param_1 + 0x98), lVar5 == 0)) {
    _dev_err(param_1,"%s: wsa884x private data is NULL\n","wsa884x_swr_resume");
    uVar4 = 0xffffffea;
  }
  else {
    if (((uint)*(undefined8 *)(lVar5 + 0x2a8) >> 1 & 1) != 0) {
      msm_cdc_set_supplies_lpm_mode
                (param_1,*(undefined8 *)(lVar5 + 0x2a0),*(undefined8 *)(lVar5 + 0x290),
                 *(undefined4 *)(lVar5 + 0x298),0);
      puVar1 = (ulong *)(lVar5 + 0x2a8);
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
// wsa884x_writeable_register @ 001056cc size=52
// signature: undefined wsa884x_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wsa884x_writeable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x38 < uVar1 >> 8) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105700);
    (*pcVar2)();
  }
  return (byte)(&wsa884x_reg_access)[uVar1] >> 1 & 1;
}



//------------------------------------------------------------
// wsa884x_readable_register @ 00105704 size=52
// signature: undefined wsa884x_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wsa884x_readable_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return 0;
  }
  if (0x38 < uVar1 >> 8) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105738);
    (*pcVar2)();
  }
  return (&wsa884x_reg_access)[uVar1] & 1;
}



//------------------------------------------------------------
// wsa884x_volatile_register @ 0010573c size=100
// signature: undefined wsa884x_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wsa884x_volatile_register(undefined8 param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = param_2 - 0x3000;
  if (param_2 < 0x3000 || uVar1 == 0) {
    return false;
  }
  if ((param_2 - 0x3504 < 2) || (param_2 - 0x3585 < 2)) {
    return true;
  }
  if (0x38 < uVar1 >> 8) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1057a0);
    (*pcVar2)();
  }
  return ((&wsa884x_reg_access)[uVar1] & 3) == 1;
}



//------------------------------------------------------------
// init_module @ 00105800 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  swr_driver_register(&wsa884x_swr_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105828 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  swr_driver_unregister(&wsa884x_swr_driver);
  return;
}



//------------------------------------------------------------
// snprintf @ 00117000 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [codec_debug_dump, wsa884x_codec_info_create_codec_entry, wsa884x_swr_probe, codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 00117008 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [wsa884x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 00117010 size=1
// signature: undefined snd_info_register(void)
// callers: [wsa884x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 00117018 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [wsa884x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 00117020 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [wsa884x_codec_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00117028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wsa884x_handle_post_irq, wsa884x_codec_info_create_codec_entry, wsa884x_swr_probe, codec_debug_write, wsa884x_parse_port_params, codec_debug_dump, wsa884x_swr_reset, wsa884x_codec_probe, wsa884x_variant_read, wsa884x_enable_swr_dac_port, codec_debug_read, codec_debug_peek_write, wsa884x_codec_version_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00117030 size=1
// signature: undefined ___ratelimit(void)
// callers: [wsa884x_gpio_ctrl, wsa884x_set_channel_map, wsa884x_war2saf_handle_irq, wsa884x_swr_up, wsa884x_pa_on_err_handle_irq, wsa884x_otp_handle_irq, wsa884x_uvlo_handle_irq, wsa884x_ocp_handle_irq, wsa884x_clip_handle_irq, wsa884x_pdm_wd_handle_irq, wsa884x_clk_wd_handle_irq, codec_debug_dump, wsa884x_ext_int_handle_irq, wsa_get_temp, wsa884x_saf2war_handle_irq, wsa884x_swr_suspend, wsa884x_variant_read, wsa884x_get_dev_num, wsa884x_enable_swr_dac_port, wsa884x_swr_down, wsa884x_codec_version_read, wsa884x_codec_get_dev_num]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00117038 size=1
// signature: undefined _printk(void)
// callers: [wsa884x_war2saf_handle_irq, wsa884x_pa_on_err_handle_irq, wsa884x_otp_handle_irq, wsa884x_uvlo_handle_irq, wsa884x_ocp_handle_irq, wsa884x_clip_handle_irq, wsa884x_pdm_wd_handle_irq, wsa884x_clk_wd_handle_irq, codec_debug_dump, wsa884x_ext_int_handle_irq, wsa_get_temp, wsa884x_saf2war_handle_irq, wsa884x_variant_read, wsa884x_get_dev_num, wsa884x_codec_version_read, wsa884x_codec_get_dev_num]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight8 @ 00117040 size=1
// signature: undefined __sw_hweight8(void)
// callers: [wsa884x_set_channel_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00117048 size=1
// signature: undefined _dev_err(void)
// callers: [wsa884x_gpio_ctrl, wsa884x_set_channel_map, wsa884x_swr_up, wsa_get_temp, wsa884x_swr_resume, wsa884x_swr_suspend, wsa884x_swr_remove, wsa884x_enable_swr_dac_port, wsa884x_swr_probe, wsa884x_event_notify, wsa884x_swr_down, wsa884x_parse_port_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_register @ 00117050 size=1
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
// swr_driver_unregister @ 00117058 size=1
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
// simple_read_from_buffer @ 00117060 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [wsa884x_variant_read, codec_debug_read, wsa884x_codec_version_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00117068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00117070 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [wsa884x_codec_probe, wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 00117078 size=1
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_get_power_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 00117080 size=1
// signature: undefined msm_cdc_init_supplies(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_init_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 00117088 size=1
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_enable_static_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00117090 size=1
// signature: undefined of_find_property(void)
// callers: [wsa884x_swr_probe, wsa884x_parse_port_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00117098 size=1
// signature: undefined _dev_info(void)
// callers: [wsa884x_validate_dt_configuration_params, wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001170a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 001170a8 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001170b0 size=1
// signature: undefined usleep_range_state(void)
// callers: [wsa884x_swr_reset, wsa884x_handle_post_irq, wsa884x_swr_probe, wsa884x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 001170b8 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [wsa884x_swr_reset, wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 001170c0 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 001170c8 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_init @ 001170d0 size=1
// signature: undefined wcd_irq_init(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_request_irq @ 001170d8 size=1
// signature: undefined wcd_request_irq(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_request_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_disable_irq @ 001170e0 size=1
// signature: undefined wcd_disable_irq(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 001170e8 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001170f0 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [wsa884x_swr_probe, codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 001170f8 size=1
// signature: undefined kstrndup(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 00117100 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_lookup_component @ 00117108 size=1
// signature: undefined snd_soc_lookup_component(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_lookup_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00117110 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00117118 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00117120 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wsa884x_swr_probe, wsa884x_parse_port_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 00117128 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [wsa884x_set_pbr_parameters, wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 00117130 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wsa884x_spkr_event, wsa_get_temp, wsa884x_codec_probe, wsa884x_set_gain_parameters, wsa884x_pa_on_err_handle_irq, wsa_pa_gain_put, wsa884x_swr_probe, wsa884x_event_notify, wsa884x_pdm_wd_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_init_port_params @ 00117138 size=1
// signature: undefined swr_init_port_params(void)
// callers: [wsa884x_swr_probe, wsa884x_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_init_port_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00117140 size=1
// signature: undefined __mutex_init(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00117148 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00117150 size=1
// signature: undefined debugfs_create_file(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 00117158 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [wsa884x_swr_remove, wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00117160 size=1
// signature: undefined kfree(void)
// callers: [wsa884x_swr_remove, wsa884x_swr_probe, wsa884x_parse_port_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00117168 size=1
// signature: undefined devm_kfree(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_irq_exit @ 00117170 size=1
// signature: undefined wcd_irq_exit(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_irq_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_device @ 00117178 size=1
// signature: undefined swr_remove_device(void)
// callers: [wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_release_supplies @ 00117180 size=1
// signature: undefined msm_cdc_release_supplies(void)
// callers: [wsa884x_swr_remove, wsa884x_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_release_supplies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00117188 size=1
// signature: undefined fortify_panic(void)
// callers: [wsa884x_swr_probe, codec_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00117190 size=1
// signature: undefined debugfs_remove(void)
// callers: [wsa884x_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 00117198 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [wsa884x_gpio_ctrl, wsa884x_swr_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 001171a0 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [wsa884x_gpio_ctrl, wsa884x_swr_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 001171a8 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wsa884x_validate_dt_configuration_params, wsa_get_temp, wsa884x_codec_probe, wsa884x_pa_on_err_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001171b8 size=1
// signature: undefined __kmalloc(void)
// callers: [wsa884x_parse_port_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001171c0 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wsa884x_handle_post_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 001171c8 size=1
// signature: undefined regmap_read(void)
// callers: [wsa884x_handle_post_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 001171d0 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [wsa884x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001171d8 size=1
// signature: size_t strlen(char * __s)
// callers: [wsa884x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 001171e0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [wsa884x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 001171e8 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [wsa884x_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_exit_regmap @ 001171f0 size=1
// signature: undefined snd_soc_component_exit_regmap(void)
// callers: [wsa884x_codec_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_exit_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001171f8 size=1
// signature: undefined mutex_lock(void)
// callers: [wsa_get_temp, wsa884x_swr_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00117200 size=1
// signature: undefined mutex_unlock(void)
// callers: [wsa_get_temp, wsa884x_swr_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00117208 size=1
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
// swr_set_device_group @ 00117210 size=1
// signature: undefined swr_set_device_group(void)
// callers: [wsa884x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_set_device_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 00117218 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [wsa884x_spkr_event, wsa884x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 00117220 size=1
// signature: undefined swr_connect_port(void)
// callers: [wsa884x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 00117228 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [wsa884x_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_from_group @ 00117230 size=1
// signature: undefined swr_remove_from_group(void)
// callers: [wsa884x_spkr_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_from_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 00117238 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wsa884x_swr_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 00117240 size=1
// signature: undefined regcache_sync(void)
// callers: [wsa884x_swr_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00117248 size=1
// signature: undefined __check_object_size(void)
// callers: [codec_debug_dump, codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00117258 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00117260 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00117268 size=1
// signature: undefined kstrtouint(void)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_read @ 00117270 size=1
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
// memset @ 00117278 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [codec_debug_peek_write, codec_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_write @ 00117288 size=1
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
// __arch_copy_to_user @ 00117290 size=1
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
// __copy_overflow @ 00117298 size=1
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
// msm_cdc_set_supplies_lpm_mode @ 001172a0 size=1
// signature: undefined msm_cdc_set_supplies_lpm_mode(void)
// callers: [wsa884x_swr_resume, wsa884x_swr_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_set_supplies_lpm_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



