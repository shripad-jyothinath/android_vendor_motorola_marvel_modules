// Decompiled by Ghidra 12.2
// Program: wcd9xxx_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcdcal_get_fw_cal @ 0010061c size=200
// signature: undefined wcdcal_get_fw_cal(void)
// callers: []
//------------------------------------------------------------

undefined8 wcdcal_get_fw_cal(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (param_1 == 0) {
    _printk(&DAT_00102d5a,"wcdcal_get_fw_cal");
    uVar2 = 0;
  }
  else {
    uVar3 = (ulong)param_2;
    if (param_2 < 4) {
      lVar1 = param_1 + 0x48;
      mutex_lock(lVar1);
      if (((uint)*(undefined8 *)(param_1 + uVar3 * 8 + 0x28) >> 2 & 1) == 0) {
        _printk(&DAT_00102a3a,"wcdcal_get_fw_cal",uVar3);
        mutex_unlock(lVar1);
        uVar2 = 0;
      }
      else {
        mutex_unlock(lVar1);
        uVar2 = *(undefined8 *)(param_1 + uVar3 * 8);
      }
    }
    else {
      _printk(&DAT_0010296e,"wcdcal_get_fw_cal",uVar3);
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_cal_create_hwdep @ 001006e8 size=8
// signature: undefined wcd_cal_create_hwdep(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_cal_create_hwdep(void)

{
  return 0;
}



//------------------------------------------------------------
// audio_ref_clk_platform_init @ 001006f4 size=44
// signature: undefined audio_ref_clk_platform_init(void)
// callers: [init_module]
//------------------------------------------------------------

void audio_ref_clk_platform_init(void)

{
  __platform_driver_register(&audio_ref_clk_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// audio_ref_clk_platform_exit @ 00100724 size=36
// signature: undefined audio_ref_clk_platform_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void audio_ref_clk_platform_exit(void)

{
  platform_driver_unregister(&audio_ref_clk_driver);
  return;
}



//------------------------------------------------------------
// audio_ref_clk_probe @ 0010074c size=1060
// signature: undefined audio_ref_clk_probe(void)
// callers: []
//------------------------------------------------------------

ulong audio_ref_clk_probe(long param_1)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long *plVar12;
  ulong *puVar13;
  undefined8 uVar14;
  char *pcVar15;
  long lVar16;
  int local_5c;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  lVar16 = param_1 + 0x10;
  local_48 = *(long *)(lVar7 + 0x638);
  local_50 = 0;
  local_58 = 0;
  local_5c = 0;
  lVar7 = devm_kmalloc(lVar16,0x70,0xdc0);
  if (lVar7 == 0) {
    uVar9 = 0xfffffff4;
    goto LAB_00100b38;
  }
  uVar5 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,codec-ext-clk-src",&local_58,1,0);
  if ((int)uVar5 < 0) {
    uVar9 = (ulong)uVar5;
    _dev_err(lVar16,"%s: could not get clk source, ret = %d\n","audio_ref_clk_probe",uVar9);
    goto LAB_00100b38;
  }
  if ((uint)local_58 < 0x15) {
    lVar11 = (local_58 & 0xffffffff) * 0x40;
    uVar8 = *(undefined8 *)(param_1 + 0x2f8);
    uVar14 = *(undefined8 *)(&DAT_00103118 + lVar11);
    uVar2 = *(undefined8 *)(&DAT_00103120 + lVar11);
    *(undefined8 *)(lVar7 + 0x60) = 0;
    puVar1 = (&PTR__compoundliteral_00103128)[(local_58 & 0xffffffff) * 8];
    uVar3 = *(undefined8 *)(&DAT_00103130 + lVar11);
    *(uint *)(lVar7 + 8) = (uint)local_58;
    *(undefined8 *)(lVar7 + 0x40) = uVar14;
    *(undefined8 *)(lVar7 + 0x48) = uVar2;
    uVar14 = *(undefined8 *)(&audio_clk_array + lVar11);
    uVar4 = *(undefined8 *)(&DAT_00103100 + lVar11);
    *(undefined **)(lVar7 + 0x50) = puVar1;
    *(undefined8 *)(lVar7 + 0x58) = uVar3;
    uVar2 = *(undefined8 *)(&DAT_00103108 + lVar11);
    uVar3 = *(undefined8 *)(&DAT_00103110 + lVar11);
    *(undefined8 *)(lVar7 + 0x20) = uVar14;
    *(undefined8 *)(lVar7 + 0x28) = uVar4;
    *(undefined8 *)(lVar7 + 0x30) = uVar2;
    *(undefined8 *)(lVar7 + 0x38) = uVar3;
    *(undefined8 *)(lVar7 + 0x10) = 0x927c000000010a;
    *(undefined8 *)(lVar7 + 0x18) = 1;
    iVar6 = of_property_read_variable_u32_array(uVar8,"qcom,codec-lpass-ext-clk-freq",&local_50,1,0)
    ;
    if (-1 < iVar6) {
      *(undefined4 *)(lVar7 + 0x14) = local_50;
    }
    iVar6 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,codec-lpass-clk-id",
                       (long)&local_58 + 4,1,0);
    if (-1 < iVar6) {
      *(undefined4 *)(lVar7 + 0x10) = local_58._4_4_;
    }
    *(long *)(param_1 + 0xa8) = lVar7;
    of_property_read_string
              (*(undefined8 *)(param_1 + 0x2f8),"pmic-clock-names",(undefined8 *)(lVar7 + 0x60));
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"qcom,use-pinctrl",&local_5c,1,0);
    if (local_5c == 0) goto LAB_00100964;
    lVar7 = *(long *)(param_1 + 0xa8);
    local_4c = 0;
    if (*(long *)(lVar7 + 0x20) == 0) {
      uVar9 = devm_pinctrl_get(lVar16);
      if ((uVar9 == 0) || (0xfffffffffffff000 < uVar9)) {
        pcVar15 = "%s: Unable to get pinctrl handle\n";
        goto LAB_00100ab0;
      }
      *(ulong *)(lVar7 + 0x20) = uVar9;
      uVar10 = pinctrl_lookup_state(uVar9,"sleep");
      *(ulong *)(lVar7 + 0x28) = uVar10;
      if (uVar10 < 0xfffffffffffff001) {
        uVar9 = pinctrl_lookup_state(uVar9,"active");
        *(ulong *)(lVar7 + 0x30) = uVar9;
        if (0xfffffffffffff000 < uVar9) {
          pcVar15 = "%s: could not get active pinstate\n";
          goto LAB_00100b04;
        }
        iVar6 = pinctrl_select_state(*(undefined8 *)(lVar7 + 0x20),*(undefined8 *)(lVar7 + 0x28));
        if (iVar6 == 0) {
          iVar6 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,mclk-clk-reg",&local_4c,1,0);
          if (-1 < iVar6) {
            uVar14 = 0x68000000000713;
            if (arm64_use_ng_mappings != '\0') {
              uVar14 = 0x68000000000f13;
            }
            lVar11 = ioremap_prot(local_4c,4,uVar14);
            *(long *)(lVar7 + 0x38) = lVar11;
            if (lVar11 == 0) {
              pcVar15 = "%s ioremap failed\n";
              goto LAB_00100b04;
            }
          }
LAB_00100964:
          lVar7 = *(long *)(param_1 + 0xa8);
          plVar12 = (long *)devm_kmalloc(lVar16,0x10,0xdc0);
          if (plVar12 == (long *)0x0) {
LAB_00100a04:
            uVar9 = 0xfffffff4;
          }
          else {
            *(undefined4 *)(plVar12 + 1) = 1;
            puVar13 = (ulong *)devm_kmalloc(lVar16,8,0xdc0);
            *plVar12 = (long)puVar13;
            if (puVar13 == (ulong *)0x0) goto LAB_00100a04;
            uVar9 = devm_clk_register(lVar16,lVar7 + 0x40);
            if (uVar9 < 0xfffffffffffff001) {
              uVar14 = *(undefined8 *)(param_1 + 0x2f8);
              *puVar13 = uVar9;
              uVar10 = of_clk_add_provider(uVar14,&of_clk_src_onecell_get,plVar12);
              uVar9 = uVar10 & 0xffffffff;
              if ((int)uVar10 == 0) goto LAB_00100b38;
              _dev_err(lVar16,"%s: clock add failed for clk_src = %d\n","audio_get_clk_data",
                       *(undefined4 *)(lVar7 + 8));
            }
            else {
              _dev_err(lVar16,"%s: clock register failed for clk_src = %d\\n","audio_get_clk_data",
                       *(undefined4 *)(lVar7 + 8));
              if ((int)uVar9 == 0) goto LAB_00100b38;
            }
          }
          _dev_err(param_1 + 0x10,"%s: clk_init is failed\n","audio_ref_clk_probe");
          lVar16 = *(long *)(param_1 + 0xa8);
          if (*(long *)(lVar16 + 0x20) != 0) {
            devm_pinctrl_put();
            *(undefined8 *)(lVar16 + 0x20) = 0;
          }
          goto LAB_00100b38;
        }
        _dev_err(lVar16,"%s: Disable TLMM pins failed with %d\n","audio_get_pinctrl",iVar6);
      }
      else {
        pcVar15 = "%s: could not get sleep pinstate\n";
LAB_00100b04:
        _dev_err(lVar16,pcVar15,"audio_get_pinctrl");
      }
      devm_pinctrl_put(*(undefined8 *)(lVar7 + 0x20));
    }
    else {
      pcVar15 = "%s: already requested before\n";
LAB_00100ab0:
      _dev_err(lVar16,pcVar15,"audio_get_pinctrl");
    }
    _dev_err(lVar16,"%s: Parsing PMI pinctrl failed\n","audio_ref_clk_probe");
  }
  else {
    _dev_err(lVar16,"%s: Invalid clk source = %d\n","audio_ref_clk_probe");
  }
  uVar9 = 0xffffffea;
LAB_00100b38:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// audio_ref_clk_remove @ 00100b74 size=56
// signature: undefined audio_ref_clk_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_ref_clk_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (*(long *)(lVar1 + 0x20) != 0) {
    devm_pinctrl_put();
    *(undefined8 *)(lVar1 + 0x20) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// audio_ext_clk_prepare @ 00100bb0 size=256
// signature: undefined audio_ext_clk_prepare(void)
// callers: []
//------------------------------------------------------------

int audio_ext_clk_prepare(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  if ((*(int *)(param_1 + -0x38) - 2U < 0x12) && (*(int *)(param_1 + -0x34) == 0)) {
    iVar1 = audio_prm_set_lpass_clk_cfg(param_1 + -0x30,1);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(audio_ext_clk_prepare_rtl,"audio_ext_clk_prepare");
      if (iVar2 == 0) {
        return iVar1;
      }
      iVar2 = ___ratelimit(audio_ext_clk_prepare__rs,"audio_ext_clk_prepare");
      if (iVar2 == 0) {
        return iVar1;
      }
      _printk(&DAT_00102ba1,"audio_ext_clk_prepare");
      return iVar1;
    }
    *(undefined4 *)(param_1 + -0x34) = 1;
    lVar3 = *(long *)(param_1 + -0x20);
  }
  else {
    lVar3 = *(long *)(param_1 + -0x20);
  }
  if ((lVar3 == 0) ||
     (iVar1 = pinctrl_select_state(lVar3,*(undefined8 *)(param_1 + -0x10)), iVar1 == 0)) {
    if (*(long *)(param_1 + -8) != 0) {
      writel(1);
    }
    iVar1 = 0;
  }
  else {
    _printk(&DAT_00102f03,"audio_ext_clk_prepare",iVar1);
    iVar1 = -5;
  }
  return iVar1;
}



//------------------------------------------------------------
// audio_ext_clk_unprepare @ 00100cb4 size=224
// signature: undefined audio_ext_clk_unprepare(void)
// callers: []
//------------------------------------------------------------

void audio_ext_clk_unprepare(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  if ((*(long *)(param_1 + -0x20) != 0) &&
     (iVar1 = pinctrl_select_state(*(long *)(param_1 + -0x20),*(undefined8 *)(param_1 + -0x18)),
     iVar1 != 0)) {
    _printk(&DAT_00102f03,"audio_ext_clk_unprepare",iVar1);
    return;
  }
  if (*(int *)(param_1 + -0x38) - 2U < 0x12) {
    *(undefined4 *)(param_1 + -0x34) = 0;
    iVar1 = audio_prm_set_lpass_clk_cfg(param_1 + -0x30,0);
    if (((iVar1 < 0) &&
        (iVar2 = ___ratelimit(audio_ext_clk_unprepare_rtl,"audio_ext_clk_unprepare"), iVar2 != 0))
       && (iVar2 = ___ratelimit(audio_ext_clk_unprepare__rs,"audio_ext_clk_unprepare"), iVar2 != 0))
    {
      _printk(&DAT_00102e96,"audio_ext_clk_unprepare",iVar1);
      lVar3 = *(long *)(param_1 + -8);
      goto joined_r0x00100d38;
    }
  }
  lVar3 = *(long *)(param_1 + -8);
joined_r0x00100d38:
  if (lVar3 != 0) {
    writel(0);
  }
  return;
}



//------------------------------------------------------------
// audio_ext_clk_get_parent @ 00100d98 size=152
// signature: undefined audio_ext_clk_get_parent(void)
// callers: []
//------------------------------------------------------------

int audio_ext_clk_get_parent(long param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *__s2;
  ulong uVar6;
  long lVar7;
  
  iVar2 = clk_hw_get_num_parents();
  if ((*(int *)(param_1 + -0x38) == 0) && (__s2 = *(char **)(param_1 + 0x20), __s2 != (char *)0x0))
  {
    iVar4 = *(byte *)(*(long *)(param_1 + 0x10) + 0x28) + 1;
    if (0 < iVar2) {
      uVar6 = 0;
      lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x10);
      iVar5 = iVar4;
      do {
        iVar3 = strcmp(*(char **)(lVar7 + (uVar6 & 0xff) * 8),__s2);
        iVar4 = (int)uVar6;
        if (iVar3 != 0) {
          iVar4 = iVar5;
        }
        uVar1 = (int)uVar6 + 1;
        uVar6 = (ulong)uVar1;
        iVar5 = iVar4;
      } while ((int)(uVar1 & 0xff) < iVar2);
    }
  }
  else {
    iVar4 = 0;
  }
  return iVar4;
}



//------------------------------------------------------------
// writel @ 00100e30 size=136
// signature: undefined writel(void)
// callers: [audio_ext_clk_unprepare, audio_ext_clk_prepare]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100e48,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100e88,uVar1);
  return;
}



//------------------------------------------------------------
// audio_ext_clk_dummy_prepare @ 00100ebc size=8
// signature: undefined audio_ext_clk_dummy_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 audio_ext_clk_dummy_prepare(void)

{
  return 0;
}



//------------------------------------------------------------
// audio_ext_clk_dummy_unprepare @ 00100ec8 size=4
// signature: undefined audio_ext_clk_dummy_unprepare(void)
// callers: []
//------------------------------------------------------------

void audio_ext_clk_dummy_unprepare(void)

{
  return;
}



//------------------------------------------------------------
// lpass_hw_vote_prepare @ 00100ed0 size=208
// signature: undefined lpass_hw_vote_prepare(void)
// callers: []
//------------------------------------------------------------

int lpass_hw_vote_prepare(long param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar1 = *(int *)(param_1 + -0x38);
  if (iVar1 == 9) {
    iVar1 = audio_prm_set_lpass_hw_core_req(param_1 + -0x30,1,1);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(lpass_hw_vote_prepare_rtl,"lpass_hw_vote_prepare");
      if (iVar2 == 0) {
        return iVar1;
      }
      puVar3 = &DAT_00102896;
      goto LAB_00100f8c;
    }
    iVar1 = *(int *)(param_1 + -0x38);
  }
  if ((iVar1 != 0xb) || (iVar1 = audio_prm_set_lpass_hw_core_req(param_1 + -0x30,2,1), -1 < iVar1))
  {
    return 0;
  }
  iVar2 = ___ratelimit(lpass_hw_vote_prepare_rtl,"lpass_hw_vote_prepare");
  if (iVar2 == 0) {
    return iVar1;
  }
  puVar3 = &DAT_00102c54;
LAB_00100f8c:
  _printk(puVar3,"lpass_hw_vote_prepare",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// lpass_hw_vote_unprepare @ 00100fa4 size=156
// signature: undefined lpass_hw_vote_unprepare(void)
// callers: []
//------------------------------------------------------------

void lpass_hw_vote_unprepare(long param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + -0x38);
  if (iVar1 == 9) {
    iVar1 = audio_prm_set_lpass_hw_core_req(param_1 + -0x30,1,0);
    if (iVar1 < 0) {
      _printk(&DAT_00102896,"lpass_hw_vote_unprepare",iVar1);
    }
    iVar1 = *(int *)(param_1 + -0x38);
  }
  if ((iVar1 == 0xb) && (iVar1 = audio_prm_set_lpass_hw_core_req(param_1 + -0x30,2,0), iVar1 < 0)) {
    _printk(&DAT_00102cf1,"lpass_hw_vote_unprepare",iVar1);
  }
  return;
}



//------------------------------------------------------------
// wcd_clsh_set_hph_mode @ 00101044 size=88
// signature: undefined wcd_clsh_set_hph_mode(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_set_hph_mode(long param_1,uint param_2)

{
  if (param_2 < 9) {
    snd_soc_component_update_bits
              (param_1,0x3009,0xc,*(undefined4 *)(&DAT_00102838 + (long)(int)param_2 * 4));
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s:Invalid mode %d\n","wcd_clsh_set_hph_mode");
  }
  return;
}



//------------------------------------------------------------
// wcd_cls_h_fsm @ 001010a0 size=608
// signature: undefined wcd_cls_h_fsm(void)
// callers: []
//------------------------------------------------------------

void wcd_cls_h_fsm(long param_1,byte *param_2,char param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
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
  if (param_3 == '\x02') {
    bVar2 = *param_2;
    uVar1 = (uint)bVar2 & (param_4 ^ 0xffffffff);
    if (0x1f < uVar1) goto LAB_001012cc;
    uVar7 = (uint)bVar2;
    if (((bVar2 < 0xb) || (bVar2 == 0xc)) || (bVar2 == 0xe)) {
      if (uVar1 != uVar7) {
        if (0x1f < uVar7) goto LAB_001012fc;
        if (*(int *)((code *)(&clsh_state_fp)[bVar2] + -4) != -0x499cd8a4) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1011f4);
          (*pcVar5)();
        }
        (*(code *)(&clsh_state_fp)[bVar2])(param_1,param_2,param_4,0);
        *param_2 = (byte)uVar1;
        if (((param_4 & 0xff) < 9) && ((1 << (ulong)(param_4 & 0x1f) & 0x116U) != 0)) {
          uVar1 = (param_4 & 0xaaaaaaaa) >> 1 | (param_4 & 0x55555555) << 1;
          uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
          uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
          uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
          param_2 = param_2 + (ulong)((int)LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10) + 1) * 4 + 0xc;
          param_2[0] = 9;
          param_2[1] = 0;
          param_2[2] = 0;
          param_2[3] = 0;
        }
        goto LAB_001012cc;
      }
      uVar9 = *(undefined8 *)(param_1 + 0x18);
      goto LAB_001012ac;
    }
    uVar9 = *(undefined8 *)(param_1 + 0x18);
    state_to_str(uVar7,&local_b8);
    pcVar6 = "%s:Invalid old state:%s\n";
  }
  else {
    if (param_3 != '\x01') goto LAB_001012cc;
    uVar7 = (uint)*param_2;
    uVar8 = (uint)*param_2;
    uVar3 = uVar8 | param_4;
    uVar1 = uVar8 | param_4 & 0xff;
    if (((uVar1 < 0xb) || (uVar1 == 0xc)) || (uVar1 == 0xe)) {
      if (uVar8 != (uVar8 | param_4 & 0xff)) {
        *param_2 = (byte)uVar3;
        if (((param_4 & 0xff) < 9) && ((1 << (ulong)(param_4 & 0x1f) & 0x116U) != 0)) {
          uVar1 = (param_4 & 0xaaaaaaaa) >> 1 | (param_4 & 0x55555555) << 1;
          uVar1 = (uVar1 & 0xcccccccc) >> 2 | (uVar1 & 0x33333333) << 2;
          uVar1 = (uVar1 & 0xf0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f) << 4;
          uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
          *(undefined4 *)
           (param_2 + (ulong)((int)LZCOUNT(uVar1 >> 0x10 | uVar1 << 0x10) + 1) * 4 + 0xc) = param_5;
        }
        if (0x1f < (uVar8 | param_4 & 0xff)) {
LAB_001012fc:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x101300);
          (*pcVar5)();
        }
        if (*(int *)((code *)(&clsh_state_fp)[(ulong)uVar3 & 0xff] + -4) != -0x499cd8a4) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101194);
          (*pcVar5)();
        }
        (*(code *)(&clsh_state_fp)[(ulong)uVar3 & 0xff])(param_1,param_2,param_4,1);
        goto LAB_001012cc;
      }
      uVar9 = *(undefined8 *)(param_1 + 0x18);
LAB_001012ac:
      state_to_str(uVar7,&local_b8);
      pcVar6 = "%s: Class-H already in requested state: %s\n";
    }
    else {
      uVar9 = *(undefined8 *)(param_1 + 0x18);
      state_to_str(uVar3,&local_b8);
      pcVar6 = "%s: Class-H not a valid new state: %s\n";
    }
  }
  _dev_err(uVar9,pcVar6,"wcd_cls_h_fsm",&local_b8);
LAB_001012cc:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// state_to_str @ 00101300 size=380
// signature: undefined state_to_str(void)
// callers: [wcd_cls_h_fsm, wcd_clsh_state_err]
//------------------------------------------------------------

char * state_to_str(uint param_1,char *param_2)

{
  uint uVar1;
  char *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  
  uVar1 = param_1 & 0xff;
  if ((param_1 & 0xff) == 0) {
    uVar3 = CONCAT53(s__STATE_IDLE__00102c1a._8_5_,s__STATE_IDLE__00102c1a._5_3_);
    *(ulong *)param_2 = CONCAT35(s__STATE_IDLE__00102c1a._5_3_,s__STATE_IDLE__00102c1a._0_5_);
    *(undefined8 *)(param_2 + 5) = uVar3;
  }
  else {
    uVar4 = 0;
    *param_2 = '\0';
    if ((param_1 & 1) != 0) {
      uVar4 = snprintf(param_2,0x7f,"%s%s%s",param_2,"[","STATE_EAR");
    }
    if ((uVar1 >> 1 & 1) != 0) {
      pcVar2 = "[";
      if (*param_2 != '\0') {
        pcVar2 = "|";
      }
      uVar4 = snprintf(param_2,0x7f - (long)(int)uVar4,"%s%s%s",param_2,pcVar2,"STATE_HPH_L");
    }
    if ((uVar1 >> 2 & 1) != 0) {
      pcVar2 = "[";
      if (*param_2 != '\0') {
        pcVar2 = "|";
      }
      uVar4 = snprintf(param_2,0x7f - (long)(int)uVar4,"%s%s%s",param_2,pcVar2,"STATE_HPH_R");
    }
    if ((uVar1 >> 3 & 1) != 0) {
      pcVar2 = "[";
      if (*param_2 != '\0') {
        pcVar2 = "|";
      }
      uVar4 = snprintf(param_2,0x7f - (long)(int)uVar4,"%s%s%s",param_2,pcVar2,"STATE_AUX");
    }
    if (0 < (int)uVar4) {
      strlcat(param_2 + uVar4,&DAT_0010296c,0x80);
    }
  }
  uVar3 = s__STATE_UNKNOWN__00102d8d._8_8_;
  if (*param_2 == '\0') {
    *(undefined8 *)param_2 = s__STATE_UNKNOWN__00102d8d._0_8_;
    *(undefined8 *)(param_2 + 8) = uVar3;
  }
  return param_2;
}



//------------------------------------------------------------
// wcd_cls_h_init @ 00101480 size=168
// signature: undefined wcd_cls_h_init(void)
// callers: []
//------------------------------------------------------------

void wcd_cls_h_init(undefined1 *param_1)

{
  *param_1 = 0;
  DAT_00103e10 = wcd_clsh_state_err;
  DAT_00103e18 = wcd_clsh_state_err;
  DAT_00103e20 = wcd_clsh_state_err;
  DAT_00103e28 = wcd_clsh_state_err;
  DAT_00103e30 = wcd_clsh_state_err;
  DAT_00103e38 = wcd_clsh_state_err;
  DAT_00103e40 = wcd_clsh_state_err;
  DAT_00103e48 = wcd_clsh_state_err;
  DAT_00103e50 = wcd_clsh_state_err;
  DAT_00103e58 = wcd_clsh_state_err;
  DAT_00103e60 = wcd_clsh_state_err;
  DAT_00103e68 = wcd_clsh_state_err;
  DAT_00103e70 = wcd_clsh_state_err;
  DAT_00103e78 = wcd_clsh_state_err;
  DAT_00103e80 = wcd_clsh_state_err;
  DAT_00103e88 = wcd_clsh_state_err;
  clsh_state_fp = wcd_clsh_state_err;
  DAT_00103d98 = wcd_clsh_state_ear;
  DAT_00103de0 = wcd_clsh_state_hph_aux;
  DAT_00103de8 = wcd_clsh_state_err;
  DAT_00103df0 = wcd_clsh_state_hph_aux;
  DAT_00103df8 = wcd_clsh_state_err;
  DAT_00103e00 = wcd_clsh_state_hph_aux;
  DAT_00103e08 = wcd_clsh_state_err;
  DAT_00103dd0 = wcd_clsh_state_aux;
  DAT_00103dd8 = wcd_clsh_state_ear_aux;
  DAT_00103da0 = wcd_clsh_state_hph_l;
  DAT_00103da8 = wcd_clsh_state_hph_ear;
  DAT_00103db0 = wcd_clsh_state_hph_r;
  DAT_00103db8 = wcd_clsh_state_hph_ear;
  DAT_00103dc0 = wcd_clsh_state_hph_st;
  DAT_00103dc8 = wcd_clsh_state_hph_ear;
  *(undefined8 *)(param_1 + 0x10) = 0x900000009;
  *(undefined8 *)(param_1 + 0x18) = 0x900000009;
  *(undefined8 *)(param_1 + 4) = 0;
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_err @ 0010152c size=180
// signature: undefined wcd_clsh_state_err(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_err(long param_1,undefined8 param_2,undefined4 param_3,ulong param_4)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x18);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  pcVar1 = "enable";
  if ((param_4 & 1) == 0) {
    pcVar1 = "disable";
  }
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  state_to_str(param_3,&local_a8);
  _dev_err(uVar3,"%s Wrong request for class H state machine requested to %s %s\n",
           "wcd_clsh_state_err",pcVar1,&local_a8);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_ear @ 001015e4 size=820
// signature: undefined wcd_clsh_state_ear(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_ear(long param_1,long param_2,undefined8 param_3,ulong param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined4 uVar7;
  
  if ((param_4 & 1) == 0) {
    snd_soc_component_update_bits(param_1,0x3009,0xc,0);
    iVar1 = *(int *)(param_2 + 4) + -1;
    *(int *)(param_2 + 4) = iVar1;
    if (iVar1 == 0) {
      snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
      snd_soc_component_update_bits(param_1,0x3008,0x40,0);
      usleep_range_state(100,0x6e,2);
      snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
      usleep_range_state(500,0x226,2);
    }
    iVar1 = *(int *)(param_2 + 8) + -1;
    *(int *)(param_2 + 8) = iVar1;
    if (iVar1 == 0) {
      snd_soc_component_update_bits(param_1,0x3008,0x80,0);
      usleep_range_state(500,0x1fe,2);
      snd_soc_component_update_bits(param_1,0x3098,0xff,0x3a);
      usleep_range_state(500,0x226,2);
    }
    snd_soc_component_update_bits(param_1,0x3138,0x20,0);
    snd_soc_component_update_bits(param_1,0x30bf,0xf0,0x80);
    snd_soc_component_update_bits(param_1,0x30d1,0xe,6);
    snd_soc_component_update_bits(param_1,0x3008,4,0);
    snd_soc_component_update_bits(param_1,0x30a8,0xf0,0x70);
    uVar3 = 0x3008;
    uVar4 = 8;
    uVar5 = 0;
  }
  else {
    snd_soc_component_update_bits(param_1,0x3008,2,0);
    uVar2 = param_5 - 1;
    if (uVar2 < 8) {
      uVar6 = -(ulong)(uVar2 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar2 << 2;
      uVar5 = *(undefined4 *)(&DAT_00103ed0 + uVar6);
      uVar7 = *(undefined4 *)(&DAT_00103eb0 + uVar6);
    }
    else {
      uVar5 = 0;
      uVar7 = 0x70;
    }
    snd_soc_component_update_bits(param_1,0x3008,4,uVar5);
    snd_soc_component_update_bits(param_1,0x30a8,0xf0,uVar7);
    wcd_clsh_force_iq_ctl(param_1,param_5,1);
    iVar1 = *(int *)(param_2 + 4);
    *(int *)(param_2 + 4) = iVar1 + 1;
    if (iVar1 == 0) {
      snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
      snd_soc_component_update_bits(param_1,0x3008,0x40,0x40);
      usleep_range_state(100,0x6e,2);
      snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
      usleep_range_state(500,0x226,2);
    }
    snd_soc_component_update_bits(param_1,0x30c7,0xf,10);
    snd_soc_component_update_bits(param_1,0x30c7,0xf0,0xa0);
    usleep_range_state(100,0x6e,2);
    if (uVar2 < 8) {
      uVar5 = *(undefined4 *)(&DAT_00103e90 + (long)(int)uVar2 * 4);
    }
    else {
      uVar5 = 0;
    }
    snd_soc_component_update_bits(param_1,0x3008,8,uVar5);
    wcd_clsh_buck_ctrl(param_1,param_2,param_5,1);
    if (8 < param_5) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s:Invalid mode %d\n","wcd_clsh_set_hph_mode",
               param_5);
      return;
    }
    uVar3 = 0x3009;
    uVar5 = *(undefined4 *)(&DAT_00102838 + (long)(int)param_5 * 4);
    uVar4 = 0xc;
  }
  snd_soc_component_update_bits(param_1,uVar3,uVar4,uVar5);
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_hph_l @ 0010191c size=824
// signature: undefined wcd_clsh_state_hph_l(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_hph_l(long param_1,long param_2,undefined8 param_3,ulong param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 uVar6;
  
  if (param_5 != 0) {
    if ((param_4 & 1) == 0) {
      snd_soc_component_update_bits(param_1,0x3009,0xc,0);
      iVar1 = *(int *)(param_2 + 4) + -1;
      *(int *)(param_2 + 4) = iVar1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
        snd_soc_component_update_bits(param_1,0x3008,0x40,0);
        usleep_range_state(100,0x6e,2);
        snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
        usleep_range_state(500,0x226,2);
      }
      iVar1 = *(int *)(param_2 + 8) + -1;
      *(int *)(param_2 + 8) = iVar1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x3008,0x80,0);
        usleep_range_state(500,0x1fe,2);
        snd_soc_component_update_bits(param_1,0x3098,0xff,0x3a);
        usleep_range_state(500,0x226,2);
      }
      snd_soc_component_update_bits(param_1,0x3138,0x20,0);
      snd_soc_component_update_bits(param_1,0x30bf,0xf0,0x80);
      snd_soc_component_update_bits(param_1,0x30d1,0xe,6);
      snd_soc_component_update_bits(param_1,0x3008,4,0);
      snd_soc_component_update_bits(param_1,0x30a8,0xf0,0x70);
      uVar2 = 0x3008;
      uVar3 = 8;
      uVar4 = 0;
    }
    else {
      snd_soc_component_update_bits(param_1,0x3008,2,0);
      if (param_5 < 9) {
        uVar5 = -(ulong)(param_5 - 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_5 - 1) << 2;
        uVar4 = *(undefined4 *)(&DAT_00103ed0 + uVar5);
        uVar6 = *(undefined4 *)(&DAT_00103eb0 + uVar5);
      }
      else {
        uVar4 = 0;
        uVar6 = 0x70;
      }
      snd_soc_component_update_bits(param_1,0x3008,4,uVar4);
      snd_soc_component_update_bits(param_1,0x30a8,0xf0,uVar6);
      wcd_clsh_force_iq_ctl(param_1,param_5,1);
      iVar1 = *(int *)(param_2 + 4);
      *(int *)(param_2 + 4) = iVar1 + 1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
        snd_soc_component_update_bits(param_1,0x3008,0x40,0x40);
        usleep_range_state(100,0x6e,2);
        snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
        usleep_range_state(500,0x226,2);
      }
      snd_soc_component_update_bits(param_1,0x30c7,0xf,10);
      snd_soc_component_update_bits(param_1,0x30c7,0xf0,0xa0);
      usleep_range_state(100,0x6e,2);
      if (param_5 < 9) {
        uVar4 = *(undefined4 *)(&DAT_00103e90 + (long)(int)(param_5 - 1) * 4);
      }
      else {
        uVar4 = 0;
      }
      snd_soc_component_update_bits(param_1,0x3008,8,uVar4);
      wcd_clsh_buck_ctrl(param_1,param_2,param_5,1);
      if (8 < param_5) {
        _dev_err(*(undefined8 *)(param_1 + 0x18),"%s:Invalid mode %d\n","wcd_clsh_set_hph_mode",
                 param_5);
        return;
      }
      uVar2 = 0x3009;
      uVar3 = 0xc;
      uVar4 = *(undefined4 *)(&DAT_00103ef0 + (long)(int)(param_5 - 1) * 4);
    }
    snd_soc_component_update_bits(param_1,uVar2,uVar3,uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_hph_r @ 00101c58 size=824
// signature: undefined wcd_clsh_state_hph_r(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_hph_r(long param_1,long param_2,undefined8 param_3,ulong param_4,uint param_5)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 uVar6;
  
  if (param_5 != 0) {
    if ((param_4 & 1) == 0) {
      snd_soc_component_update_bits(param_1,0x3009,0xc,0);
      iVar1 = *(int *)(param_2 + 4) + -1;
      *(int *)(param_2 + 4) = iVar1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
        snd_soc_component_update_bits(param_1,0x3008,0x40,0);
        usleep_range_state(100,0x6e,2);
        snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
        usleep_range_state(500,0x226,2);
      }
      iVar1 = *(int *)(param_2 + 8) + -1;
      *(int *)(param_2 + 8) = iVar1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x3008,0x80,0);
        usleep_range_state(500,0x1fe,2);
        snd_soc_component_update_bits(param_1,0x3098,0xff,0x3a);
        usleep_range_state(500,0x226,2);
      }
      snd_soc_component_update_bits(param_1,0x3138,0x20,0);
      snd_soc_component_update_bits(param_1,0x30bf,0xf0,0x80);
      snd_soc_component_update_bits(param_1,0x30d1,0xe,6);
      snd_soc_component_update_bits(param_1,0x3008,4,0);
      snd_soc_component_update_bits(param_1,0x30a8,0xf0,0x70);
      uVar2 = 0x3008;
      uVar3 = 8;
      uVar4 = 0;
    }
    else {
      snd_soc_component_update_bits(param_1,0x3008,2,0);
      if (param_5 < 9) {
        uVar5 = -(ulong)(param_5 - 1 >> 0x1f) & 0xfffffffc00000000 | (ulong)(param_5 - 1) << 2;
        uVar4 = *(undefined4 *)(&DAT_00103ed0 + uVar5);
        uVar6 = *(undefined4 *)(&DAT_00103eb0 + uVar5);
      }
      else {
        uVar4 = 0;
        uVar6 = 0x70;
      }
      snd_soc_component_update_bits(param_1,0x3008,4,uVar4);
      snd_soc_component_update_bits(param_1,0x30a8,0xf0,uVar6);
      wcd_clsh_force_iq_ctl(param_1,param_5,1);
      iVar1 = *(int *)(param_2 + 4);
      *(int *)(param_2 + 4) = iVar1 + 1;
      if (iVar1 == 0) {
        snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
        snd_soc_component_update_bits(param_1,0x3008,0x40,0x40);
        usleep_range_state(100,0x6e,2);
        snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
        usleep_range_state(500,0x226,2);
      }
      snd_soc_component_update_bits(param_1,0x30c7,0xf,10);
      snd_soc_component_update_bits(param_1,0x30c7,0xf0,0xa0);
      usleep_range_state(100,0x6e,2);
      if (param_5 < 9) {
        uVar4 = *(undefined4 *)(&DAT_00103e90 + (long)(int)(param_5 - 1) * 4);
      }
      else {
        uVar4 = 0;
      }
      snd_soc_component_update_bits(param_1,0x3008,8,uVar4);
      wcd_clsh_buck_ctrl(param_1,param_2,param_5,1);
      if (8 < param_5) {
        _dev_err(*(undefined8 *)(param_1 + 0x18),"%s:Invalid mode %d\n","wcd_clsh_set_hph_mode",
                 param_5);
        return;
      }
      uVar2 = 0x3009;
      uVar3 = 0xc;
      uVar4 = *(undefined4 *)(&DAT_00103ef0 + (long)(int)(param_5 - 1) * 4);
    }
    snd_soc_component_update_bits(param_1,uVar2,uVar3,uVar4);
  }
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_hph_st @ 00101f94 size=4
// signature: undefined wcd_clsh_state_hph_st(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_hph_st(void)

{
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_aux @ 00101f9c size=564
// signature: undefined wcd_clsh_state_aux(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_aux(undefined8 param_1,long param_2,undefined8 param_3,ulong param_4,int param_5
                       )

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  ulong uVar4;
  undefined4 uVar5;
  
  if ((param_4 & 1) == 0) {
    wcd_clsh_buck_ctrl(param_1,param_2,param_5,0);
    iVar1 = *(int *)(param_2 + 4) + -1;
    *(int *)(param_2 + 4) = iVar1;
    if (iVar1 == 0) {
      snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
      snd_soc_component_update_bits(param_1,0x3008,0x40,0);
      usleep_range_state(100,0x6e,2);
      snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
      usleep_range_state(500,0x226,2);
    }
    snd_soc_component_update_bits(param_1,0x3008,4,0);
    snd_soc_component_update_bits(param_1,0x30a8,0xf0,0x70);
    snd_soc_component_update_bits(param_1,0x3008,8,0);
  }
  else {
    uVar2 = param_5 - 1;
    if (uVar2 < 8) {
      uVar3 = *(undefined4 *)(&DAT_00103e90 + (long)(int)uVar2 * 4);
    }
    else {
      uVar3 = 0;
    }
    snd_soc_component_update_bits(param_1,0x3008,8,uVar3);
    if (uVar2 < 8) {
      uVar4 = -(ulong)(uVar2 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar2 << 2;
      uVar3 = *(undefined4 *)(&DAT_00103ed0 + uVar4);
      uVar5 = *(undefined4 *)(&DAT_00103eb0 + uVar4);
    }
    else {
      uVar3 = 0;
      uVar5 = 0x70;
    }
    snd_soc_component_update_bits(param_1,0x3008,4,uVar3);
    snd_soc_component_update_bits(param_1,0x30a8,0xf0,uVar5);
    iVar1 = *(int *)(param_2 + 4);
    *(int *)(param_2 + 4) = iVar1 + 1;
    if (iVar1 == 0) {
      snd_soc_component_update_bits(param_1,0x30a5,0xe0,0xe0);
      snd_soc_component_update_bits(param_1,0x3008,0x40,0x40);
      usleep_range_state(100,0x6e,2);
      snd_soc_component_update_bits(param_1,0x30af,0xe0,0xe0);
      usleep_range_state(500,0x226,2);
    }
    snd_soc_component_update_bits(param_1,0x30c7,0xf,10);
    snd_soc_component_update_bits(param_1,0x30c7,0xf0,0xa0);
    usleep_range_state(100,0x6e,2);
    wcd_clsh_buck_ctrl(param_1,param_2,param_5,1);
  }
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_hph_aux @ 001021d4 size=4
// signature: undefined wcd_clsh_state_hph_aux(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_hph_aux(void)

{
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_ear_aux @ 001021dc size=4
// signature: undefined wcd_clsh_state_ear_aux(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_ear_aux(void)

{
  return;
}



//------------------------------------------------------------
// wcd_clsh_state_hph_ear @ 001021e4 size=4
// signature: undefined wcd_clsh_state_hph_ear(void)
// callers: []
//------------------------------------------------------------

void wcd_clsh_state_hph_ear(void)

{
  return;
}



//------------------------------------------------------------
// wcd_clsh_force_iq_ctl @ 001021e8 size=228
// signature: undefined wcd_clsh_force_iq_ctl(void)
// callers: [wcd_clsh_state_hph_l, wcd_clsh_state_ear, wcd_clsh_state_hph_r]
//------------------------------------------------------------

void wcd_clsh_force_iq_ctl(undefined8 param_1,int param_2,ulong param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if ((param_3 & 1) == 0) {
    uVar1 = 0;
    uVar2 = 6;
    uVar3 = 0x80;
  }
  else {
    snd_soc_component_update_bits(param_1,0x30af,0xe0,0xa0);
    uVar2 = 2;
    usleep_range_state(100,0x6e,2);
    snd_soc_component_update_bits(param_1,0x3099,2,2);
    snd_soc_component_update_bits(param_1,0x3098,0xff,0x1c);
    uVar3 = 0xc0;
    uVar1 = 0x20;
    if ((param_2 != 8) && (param_2 != 4)) {
      return;
    }
  }
  snd_soc_component_update_bits(param_1,0x3138,0x20,uVar1);
  snd_soc_component_update_bits(param_1,0x30bf,0xf0,uVar3);
  snd_soc_component_update_bits(param_1,0x30d1,0xe,uVar2);
  return;
}



//------------------------------------------------------------
// wcd_clsh_buck_ctrl @ 001022cc size=200
// signature: undefined wcd_clsh_buck_ctrl(void)
// callers: [wcd_clsh_state_aux, wcd_clsh_state_hph_l, wcd_clsh_state_ear, wcd_clsh_state_hph_r]
//------------------------------------------------------------

void wcd_clsh_buck_ctrl(undefined8 param_1,long param_2,uint param_3,ulong param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(param_2 + 8);
  if ((param_4 & 1) == 0) {
    *(int *)(param_2 + 8) = iVar1 + -1;
    if (iVar1 + -1 != 0) {
      return;
    }
    uVar2 = 0;
  }
  else {
    *(int *)(param_2 + 8) = iVar1 + 1;
    if (iVar1 != 0) {
      return;
    }
    uVar2 = 0x80;
  }
  snd_soc_component_update_bits(param_1,0x3008,0x80,uVar2);
  usleep_range_state(500,0x1fe,2);
  if ((param_3 < 6) && ((1 << (ulong)(param_3 & 0x1f) & 0x36U) != 0)) {
    snd_soc_component_update_bits(param_1,0x3099,2,0);
  }
  snd_soc_component_update_bits(param_1,0x3098,0xff,0x3a);
  usleep_range_state(500,0x226,2);
  return;
}



//------------------------------------------------------------
// init_module @ 00103ba4 size=76
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = audio_ref_clk_platform_init();
  if (iVar1 != 0) {
    _printk(&DAT_00102d71,"wcd9xxx_soc_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00103bf4 size=28
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  audio_ref_clk_platform_exit();
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00105000 size=1
// signature: undefined mutex_lock(void)
// callers: [wcdcal_get_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105008 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcdcal_get_fw_cal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105010 size=1
// signature: undefined _printk(void)
// callers: [audio_ext_clk_unprepare, wcdcal_get_fw_cal, audio_ext_clk_prepare, init_module, lpass_hw_vote_unprepare, lpass_hw_vote_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105018 size=1
// signature: undefined __platform_driver_register(void)
// callers: [audio_ref_clk_platform_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00105020 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [audio_ref_clk_platform_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00105028 size=1
// signature: undefined devm_kmalloc(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105030 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105038 size=1
// signature: undefined of_property_read_string(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00105040 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00105048 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00105050 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [audio_ext_clk_unprepare, audio_ext_clk_prepare, audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00105060 size=1
// signature: undefined ioremap_prot(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register @ 00105068 size=1
// signature: undefined devm_clk_register(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_clk_add_provider @ 00105078 size=1
// signature: undefined of_clk_add_provider(void)
// callers: [audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_clk_add_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105080 size=1
// signature: undefined _dev_err(void)
// callers: [wcd_cls_h_fsm, wcd_clsh_state_err, wcd_clsh_state_hph_l, audio_ref_clk_probe, wcd_clsh_state_ear, wcd_clsh_state_hph_r, wcd_clsh_set_hph_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 00105088 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [audio_ref_clk_remove, audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105090 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd_cls_h_fsm, wcd_clsh_state_err, audio_ref_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_prm_set_lpass_clk_cfg @ 00105098 size=1
// signature: undefined audio_prm_set_lpass_clk_cfg(void)
// callers: [audio_ext_clk_unprepare, audio_ext_clk_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_prm_set_lpass_clk_cfg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001050a0 size=1
// signature: undefined ___ratelimit(void)
// callers: [audio_ext_clk_unprepare, audio_ext_clk_prepare, lpass_hw_vote_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_get_num_parents @ 001050a8 size=1
// signature: undefined clk_hw_get_num_parents(void)
// callers: [audio_ext_clk_get_parent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_get_num_parents(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001050b0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [audio_ext_clk_get_parent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001050b8 size=1
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
// log_post_write_mmio @ 001050c0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_prm_set_lpass_hw_core_req @ 001050c8 size=1
// signature: undefined audio_prm_set_lpass_hw_core_req(void)
// callers: [lpass_hw_vote_unprepare, lpass_hw_vote_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_prm_set_lpass_hw_core_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 001050d0 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wcd_clsh_force_iq_ctl, wcd_clsh_state_aux, wcd_clsh_buck_ctrl, wcd_clsh_state_hph_l, wcd_clsh_state_ear, wcd_clsh_state_hph_r, wcd_clsh_set_hph_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001050d8 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [state_to_str]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 001050e0 size=1
// signature: undefined strlcat(void)
// callers: [state_to_str]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001050e8 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd_clsh_force_iq_ctl, wcd_clsh_state_aux, wcd_clsh_buck_ctrl, wcd_clsh_state_hph_l, wcd_clsh_state_ear, wcd_clsh_state_hph_r]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



