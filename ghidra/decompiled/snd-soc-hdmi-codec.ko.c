// Decompiled by Ghidra 12.2
// Program: snd-soc-hdmi-codec.ko
// Image base: 00100000

//------------------------------------------------------------
// hdmi_codec_probe @ 0010045c size=436
// signature: undefined hdmi_codec_probe(void)
// callers: []
//------------------------------------------------------------

int hdmi_codec_probe(long param_1)

{
  long lVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  void *__dest;
  char *pcVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  
  plVar10 = *(long **)(param_1 + 0xa0);
  lVar1 = param_1 + 0x10;
  if (plVar10 == (long *)0x0) {
    pcVar7 = "%s: No platform data\n";
  }
  else {
    iVar5 = (*(byte *)(plVar10 + 1) >> 1 & 1) + (*(byte *)(plVar10 + 1) & 1);
    if ((((iVar5 != 0) && (lVar8 = *plVar10, lVar8 != 0)) &&
        ((*(long *)(lVar8 + 8) != 0 || (*(long *)(lVar8 + 0x10) != 0)))) &&
       (*(long *)(lVar8 + 0x18) != 0)) {
      plVar6 = (long *)devm_kmalloc(lVar1,0x108,0xdc0);
      if (plVar6 != (long *)0x0) {
        lVar8 = plVar10[2];
        lVar9 = *plVar10;
        plVar6[1] = plVar10[1];
        plVar6[2] = lVar8;
        *plVar6 = lVar9;
        __mutex_init(plVar6 + 0x15,"&hcp->lock",&hdmi_codec_probe___key);
        iVar4 = snd_pcm_create_iec958_consumer_default((long)plVar6 + 0xec,0x18);
        if (iVar4 < 0) {
          return iVar4;
        }
        __dest = (void *)devm_kmalloc(lVar1,iVar5 * 0xe0,0xdc0);
        if (__dest != (void *)0x0) {
          bVar3 = *(byte *)(plVar10 + 1);
          bVar2 = (bVar3 & 1) != 0;
          if (bVar2) {
            memcpy(__dest,&hdmi_i2s_dai,0xe0);
            *(undefined4 *)((long)__dest + 200) = *(undefined4 *)((long)plVar10 + 0xc);
            bVar3 = *(byte *)(plVar10 + 1);
          }
          if ((bVar3 >> 1 & 1) != 0) {
            memcpy((void *)((long)__dest + (ulong)bVar2 * 0xe0),&hdmi_spdif_dai,0xe0);
          }
          *(long **)(param_1 + 0xa8) = plVar6;
          iVar5 = devm_snd_soc_register_component(lVar1,hdmi_driver,__dest,iVar5);
          if (iVar5 == 0) {
            return 0;
          }
          _dev_err(lVar1,"%s: snd_soc_register_component() failed (%d)\n","hdmi_codec_probe",iVar5);
          return iVar5;
        }
      }
      return -0xc;
    }
    pcVar7 = "%s: Invalid parameters\n";
  }
  _dev_err(lVar1,pcVar7,"hdmi_codec_probe");
  return -0x16;
}



//------------------------------------------------------------
// hdmi_dai_probe @ 00100614 size=232
// signature: undefined hdmi_dai_probe(void)
// callers: []
//------------------------------------------------------------

void hdmi_dai_probe(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined *local_78;
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
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_e8 = &DAT_001025d3;
  uStack_e0 = 0;
  local_d8 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0xa8);
  local_88 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x80);
  local_90 = 0;
  uStack_d0 = 0;
  uStack_80 = 0;
  uStack_70 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_78 = &DAT_001025b8;
  uVar1 = snd_soc_dapm_add_routes(*(long *)(param_1 + 0x58) + 0xd0,&local_e8,2);
  if ((int)uVar1 == 0) {
    lVar2 = devm_kmalloc(*(undefined8 *)(param_1 + 0x10),0xc,0xdc0);
    if (lVar2 == 0) {
      uVar1 = 0xfffffff4;
    }
    else {
      uVar1 = 0;
      *(long *)(param_1 + 0x38) = lVar2;
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
// hdmi_codec_pcm_new @ 00100700 size=308
// signature: undefined hdmi_codec_pcm_new(void)
// callers: []
//------------------------------------------------------------

ulong hdmi_codec_pcm_new(long param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_2 + 0x10) + 0x98);
  uVar2 = snd_pcm_add_chmap_ctls
                    (*(undefined8 *)(param_1 + 0x610),0,0,
                     *(undefined4 *)(*(long *)(param_2 + 0x18) + 200),0,lVar3 + 0x98);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  *(long *)(*(long *)(lVar3 + 0x98) + 0x28) = lVar3;
  *(code **)(*(long *)(*(long *)(lVar3 + 0x98) + 0x10) + 0x60) = hdmi_codec_chmap_ctl_get;
  *(undefined1 **)(*(long *)(lVar3 + 0x98) + 0x18) = hdmi_codec_stereo_chmaps;
  *(undefined4 *)(lVar3 + 0xa0) = 0xffffffff;
  lVar3 = snd_ctl_new1(hdmi_codec_controls,*(undefined8 *)(param_2 + 0x58));
  if (lVar3 != 0) {
    *(undefined4 *)(lVar3 + 0x18) = *(undefined4 *)(*(long *)(param_1 + 0x610) + 0x18);
    uVar2 = snd_ctl_add(*(undefined8 *)(*(long *)(param_1 + 8) + 0x48),lVar3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    lVar3 = snd_ctl_new1(0x102458,*(undefined8 *)(param_2 + 0x58));
    if (lVar3 != 0) {
      *(undefined4 *)(lVar3 + 0x18) = *(undefined4 *)(*(long *)(param_1 + 0x610) + 0x18);
      uVar2 = snd_ctl_add(*(undefined8 *)(*(long *)(param_1 + 8) + 0x48),lVar3);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      lVar3 = snd_ctl_new1(0x1024a8,*(undefined8 *)(param_2 + 0x58));
      if (lVar3 != 0) {
        *(undefined4 *)(lVar3 + 0x18) = *(undefined4 *)(*(long *)(param_1 + 0x610) + 0x18);
        uVar1 = snd_ctl_add(*(undefined8 *)(*(long *)(param_1 + 8) + 0x48),lVar3);
        if (-1 < (int)uVar1) {
          uVar1 = 0;
        }
        return (ulong)uVar1;
      }
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// hdmi_codec_chmap_ctl_get @ 00100838 size=140
// signature: undefined hdmi_codec_chmap_ctl_get(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_chmap_ctl_get(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar5 = *(long *)(lVar4 + 0x28);
  uVar1 = *(uint *)(lVar5 + 0xa0);
  if (uVar1 == 0xffffffff) {
    lVar6 = 0;
    iVar2 = *(int *)(lVar4 + 0x20);
  }
  else {
    lVar6 = *(long *)(lVar4 + 0x18) + (ulong)uVar1 * 0x10 + 1;
    iVar2 = *(int *)(lVar4 + 0x20);
  }
  if (iVar2 != 0) {
    uVar7 = 0;
    do {
      if (*(int *)(lVar5 + 0xa0) == -1) {
        if (0x7f < uVar7) {
LAB_001008c0:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1008c4);
          (*pcVar3)();
        }
        uVar8 = 0;
      }
      else {
        if (0x7f < uVar7) goto LAB_001008c0;
        uVar8 = (ulong)*(byte *)(lVar6 + uVar7);
      }
      *(ulong *)(param_2 + 0x48 + uVar7 * 8) = uVar8;
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(lVar4 + 0x20));
  }
  return 0;
}



//------------------------------------------------------------
// hdmi_codec_iec958_info @ 001008c8 size=24
// signature: undefined hdmi_codec_iec958_info(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_iec958_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 5;
  *(undefined4 *)(param_2 + 0x48) = 1;
  return 0;
}



//------------------------------------------------------------
// hdmi_codec_iec958_mask_get @ 001008e4 size=20
// signature: undefined hdmi_codec_iec958_mask_get(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_iec958_mask_get(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0x50) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x58) = 0xffffffffffffffff;
  *(undefined8 *)(param_2 + 0x48) = 0xffffffffffffffff;
  return 0;
}



//------------------------------------------------------------
// hdmi_codec_iec958_default_get @ 001008fc size=44
// signature: undefined hdmi_codec_iec958_default_get(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_iec958_default_get(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  uVar3 = *(undefined8 *)(lVar1 + 0xfc);
  uVar2 = *(undefined8 *)(lVar1 + 0xec);
  *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(lVar1 + 0xf4);
  *(undefined8 *)(param_2 + 0x58) = uVar3;
  *(undefined8 *)(param_2 + 0x48) = uVar2;
  return 0;
}



//------------------------------------------------------------
// hdmi_codec_iec958_default_put @ 0010092c size=44
// signature: undefined hdmi_codec_iec958_default_put(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_iec958_default_put(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar1 = *(undefined8 *)(param_2 + 0x50);
  uVar3 = *(undefined8 *)(param_2 + 0x48);
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  *(undefined8 *)(lVar2 + 0xfc) = *(undefined8 *)(param_2 + 0x58);
  *(undefined8 *)(lVar2 + 0xf4) = uVar1;
  *(undefined8 *)(lVar2 + 0xec) = uVar3;
  return 0;
}



//------------------------------------------------------------
// hdmi_eld_ctl_info @ 0010095c size=24
// signature: undefined hdmi_eld_ctl_info(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_eld_ctl_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 4;
  *(undefined4 *)(param_2 + 0x48) = 0x80;
  return 0;
}



//------------------------------------------------------------
// hdmi_eld_ctl_get @ 00100978 size=88
// signature: undefined hdmi_eld_ctl_get(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_eld_ctl_get(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98);
  uVar2 = *(undefined8 *)(lVar4 + 0x50);
  uVar1 = *(undefined8 *)(lVar4 + 0x38);
  uVar3 = *(undefined8 *)(lVar4 + 0x40);
  *(undefined8 *)(param_2 + 0x78) = *(undefined8 *)(lVar4 + 0x48);
  *(undefined8 *)(param_2 + 0x80) = uVar2;
  *(undefined8 *)(param_2 + 0x68) = uVar1;
  *(undefined8 *)(param_2 + 0x70) = uVar3;
  uVar2 = *(undefined8 *)(lVar4 + 0x70);
  uVar1 = *(undefined8 *)(lVar4 + 0x58);
  uVar3 = *(undefined8 *)(lVar4 + 0x60);
  *(undefined8 *)(param_2 + 0x98) = *(undefined8 *)(lVar4 + 0x68);
  *(undefined8 *)(param_2 + 0xa0) = uVar2;
  *(undefined8 *)(param_2 + 0x88) = uVar1;
  *(undefined8 *)(param_2 + 0x90) = uVar3;
  uVar2 = *(undefined8 *)(lVar4 + 0x90);
  uVar1 = *(undefined8 *)(lVar4 + 0x78);
  uVar3 = *(undefined8 *)(lVar4 + 0x80);
  *(undefined8 *)(param_2 + 0xb8) = *(undefined8 *)(lVar4 + 0x88);
  *(undefined8 *)(param_2 + 0xc0) = uVar2;
  *(undefined8 *)(param_2 + 0xa8) = uVar1;
  *(undefined8 *)(param_2 + 0xb0) = uVar3;
  uVar2 = *(undefined8 *)(lVar4 + 0x30);
  uVar1 = *(undefined8 *)(lVar4 + 0x18);
  uVar3 = *(undefined8 *)(lVar4 + 0x20);
  *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(lVar4 + 0x28);
  *(undefined8 *)(param_2 + 0x60) = uVar2;
  *(undefined8 *)(param_2 + 0x48) = uVar1;
  *(undefined8 *)(param_2 + 0x50) = uVar3;
  return 0;
}



//------------------------------------------------------------
// hdmi_codec_i2s_set_fmt @ 001009d4 size=92
// signature: undefined hdmi_codec_i2s_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_i2s_set_fmt(long param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x38);
  uVar1 = (param_2 & 0xf000) - 0x1000 >> 0xc;
  *(undefined4 *)(puVar3 + 1) = 0;
  *puVar3 = 0;
  if (uVar1 < 4) {
                    /* WARNING: Jumptable with 0 entries at 0x00100a1c */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (*(code *)(&UNK_00100a20 + (ulong)(byte)(&DAT_001015f8)[uVar1] * 4))();
    return uVar2;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// hdmi_codec_mute @ 00100af4 size=112
// signature: undefined hdmi_codec_mute(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_mute(long param_1,int param_2,int param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  long *plVar3;
  long lVar4;
  
  plVar3 = *(long **)(*(long *)(param_1 + 0x10) + 0x98);
  lVar4 = *plVar3;
  pcVar2 = *(code **)(lVar4 + 0x20);
  if ((pcVar2 == (code *)0x0) || ((param_3 != 0 && ((*(byte *)(lVar4 + 0x40) & 1) != 0)))) {
    uVar1 = 0xfffffdf4;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x414f8aea) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100b4c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x60),plVar3[2],param_2 != 0,
                      param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// hdmi_codec_startup @ 00100b68 size=436
// signature: undefined hdmi_codec_startup(void)
// callers: []
//------------------------------------------------------------

int hdmi_codec_startup(long param_1,long param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  code *pcVar4;
  undefined1 *puVar5;
  uint uVar6;
  long *plVar7;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  plVar7 = *(long **)(*(long *)(param_2 + 0x10) + 0x98);
  mutex_lock(plVar7 + 0x15);
  if ((char)plVar7[0x1b] == '\0') {
    pcVar4 = *(code **)*plVar7;
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100bd8);
        (*pcVar4)();
      }
      iVar3 = (*pcVar4)(*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x60),plVar7[2]);
      if (iVar3 != 0) goto LAB_00100bf4;
    }
    if ((iVar1 == 0) && (pcVar4 = *(code **)(*plVar7 + 0x28), pcVar4 != (code *)0x0)) {
      if (*(int *)(pcVar4 + -4) != 0x697c5574) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100c54);
        (*pcVar4)();
      }
      iVar3 = (*pcVar4)(*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x60),plVar7[2],plVar7 + 3,0x80)
      ;
      if ((iVar3 != 0) ||
         (iVar3 = snd_pcm_hw_constraint_eld(*(undefined8 *)(param_1 + 0xc0),plVar7 + 3), iVar3 != 0)
         ) goto LAB_00100bf4;
      bVar2 = *(byte *)((long)plVar7 + 0x1f);
      uVar6 = (bVar2 >> 1 & 1) << 10 | bVar2 >> 1 & 2;
      if ((bVar2 & 8) != 0) {
        uVar6 = uVar6 | 0xa0;
      }
      uVar6 = uVar6 | (bVar2 & 0x10) << 2;
      if ((bVar2 & 0x20) != 0) {
        uVar6 = uVar6 | 0x18;
      }
      if ((bVar2 & 0x40) != 0) {
        uVar6 = uVar6 | 0x300;
      }
      if ((uVar6 == 0) || (*(uint *)(plVar7[0x13] + 0x20) < 3)) {
        puVar5 = hdmi_codec_stereo_chmaps;
      }
      else {
        puVar5 = hdmi_codec_8ch_chmaps;
      }
      *(undefined1 **)(plVar7[0x13] + 0x18) = puVar5;
    }
    iVar3 = 0;
    *(undefined1 *)(plVar7 + 0x1b) = 1;
  }
  else {
    _dev_err(*(undefined8 *)(param_2 + 0x10),"Only one simultaneous stream supported!\n");
    iVar3 = -0x16;
  }
LAB_00100bf4:
  mutex_unlock(plVar7 + 0x15);
  return iVar3;
}



//------------------------------------------------------------
// hdmi_codec_shutdown @ 00100d20 size=120
// signature: undefined hdmi_codec_shutdown(void)
// callers: []
//------------------------------------------------------------

void hdmi_codec_shutdown(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_2 + 0x10) + 0x98);
  *(undefined4 *)(plVar2 + 0x14) = 0xffffffff;
  if (*(int *)(*(code **)(*plVar2 + 0x18) + -4) != -0x6fdc0bc8) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100d6c);
    (*pcVar1)();
  }
  (**(code **)(*plVar2 + 0x18))(*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x60),plVar2[2]);
  mutex_lock(plVar2 + 0x15);
  *(undefined1 *)(plVar2 + 0x1b) = 0;
  mutex_unlock(plVar2 + 0x15);
  return;
}



//------------------------------------------------------------
// hdmi_codec_hw_params @ 00100d9c size=460
// signature: undefined hdmi_codec_hw_params(void)
// callers: []
//------------------------------------------------------------

int hdmi_codec_hw_params(undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long *plVar7;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
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
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  lVar6 = *(long *)(param_3 + 0x38);
  local_c8 = 0;
  uStack_c0 = 0;
  plVar7 = *(long **)(*(long *)(param_3 + 0x10) + 0x98);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  uStack_fc = 0;
  local_118 = 0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_130 = 0;
  if (*(long *)(*plVar7 + 8) == 0) {
    iVar3 = 0;
    goto LAB_00100f08;
  }
  uVar4 = *(uint *)(param_2 + 0x24);
  if (uVar4 == 0) {
    uVar4 = *(uint *)(param_2 + 0x28);
    if (uVar4 != 0) {
      uVar5 = 0x20;
      goto LAB_00100e44;
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 0;
LAB_00100e44:
    uVar4 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
    uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
    uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
    uVar5 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10) | uVar5;
  }
  uVar2 = snd_pcm_format_width(uVar5);
  iVar3 = hdmi_codec_fill_codec_params
                    (param_3,uVar2,*(undefined4 *)(param_2 + 0x128),*(undefined4 *)(param_2 + 0x11c)
                     ,&local_130);
  if (iVar3 < 0) goto LAB_00100f08;
  uStack_114 = (undefined4)*(undefined8 *)((long)plVar7 + 0xec);
  uStack_110 = (undefined4)((ulong)*(undefined8 *)((long)plVar7 + 0xec) >> 0x20);
  uStack_10c = (undefined4)*(undefined8 *)((long)plVar7 + 0xf4);
  local_108 = (undefined4)((ulong)*(undefined8 *)((long)plVar7 + 0xf4) >> 0x20);
  uStack_104 = (undefined4)*(undefined8 *)((long)plVar7 + 0xfc);
  uStack_100 = (undefined4)((ulong)*(undefined8 *)((long)plVar7 + 0xfc) >> 0x20);
  iVar3 = snd_pcm_fill_iec958_consumer_hw_params(param_2,&uStack_114,0x18);
  if (iVar3 < 0) {
    _dev_err(*(undefined8 *)(param_3 + 0x10),"Creating IEC958 channel status failed %d\n",iVar3);
    goto LAB_00100f08;
  }
  uVar4 = *(uint *)(param_2 + 0x24);
  if (uVar4 == 0) {
    uVar4 = *(uint *)(param_2 + 0x28);
    uVar5 = 0;
    if (uVar4 != 0) {
      uVar5 = 0x20;
      goto LAB_00100ebc;
    }
  }
  else {
    uVar5 = 0;
LAB_00100ebc:
    uVar4 = (uVar4 & 0xaaaaaaaa) >> 1 | (uVar4 & 0x55555555) << 1;
    uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
    uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
    uVar5 = (uint)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10) | uVar5;
  }
  *(uint *)(lVar6 + 8) = uVar5;
  if (*(int *)(*(code **)(*plVar7 + 8) + -4) != 0x52fc5091) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100f00);
    (*pcVar1)();
  }
  iVar3 = (**(code **)(*plVar7 + 8))
                    (*(undefined8 *)(*(long *)(param_3 + 0x10) + 0x60),plVar7[2],lVar6,&local_130);
LAB_00100f08:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdmi_codec_prepare @ 00100f6c size=384
// signature: undefined hdmi_codec_prepare(void)
// callers: []
//------------------------------------------------------------

int hdmi_codec_prepare(long param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined4 local_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 local_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
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
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  lVar6 = *(long *)(param_1 + 0xc0);
  lVar5 = *(long *)(param_2 + 0x38);
  plVar7 = *(long **)(*(long *)(param_2 + 0x10) + 0x98);
  uVar1 = *(undefined4 *)(lVar6 + 0x70);
  uVar3 = snd_pcm_format_width(*(undefined4 *)(lVar6 + 100));
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
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_104 = 0;
  uStack_100 = 0;
  uStack_fc = 0;
  local_118 = 0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_10c = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_130 = 0;
  if (*(long *)(*plVar7 + 0x10) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = hdmi_codec_fill_codec_params
                      (param_2,uVar3,*(undefined4 *)(lVar6 + 0x6c),uVar1,&local_130);
    if (-1 < iVar4) {
      uStack_114 = (undefined4)*(undefined8 *)((long)plVar7 + 0xec);
      uStack_110 = (undefined4)((ulong)*(undefined8 *)((long)plVar7 + 0xec) >> 0x20);
      uStack_10c = (undefined4)*(undefined8 *)((long)plVar7 + 0xf4);
      local_108 = (undefined4)((ulong)*(undefined8 *)((long)plVar7 + 0xf4) >> 0x20);
      uStack_104 = (undefined4)*(undefined8 *)((long)plVar7 + 0xfc);
      uStack_100 = (undefined4)((ulong)*(undefined8 *)((long)plVar7 + 0xfc) >> 0x20);
      iVar4 = snd_pcm_fill_iec958_consumer(lVar6,&uStack_114,0x18);
      if (iVar4 < 0) {
        _dev_err(*(undefined8 *)(param_2 + 0x10),"Creating IEC958 channel status failed %d\n",iVar4)
        ;
      }
      else {
        *(undefined4 *)(lVar5 + 8) = *(undefined4 *)(lVar6 + 100);
        if (*(int *)(*(code **)(*plVar7 + 0x10) + -4) != 0x52fc5091) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101084);
          (*pcVar2)();
        }
        iVar4 = (**(code **)(*plVar7 + 0x10))
                          (*(undefined8 *)(*(long *)(param_2 + 0x10) + 0x60),plVar7[2],lVar5,
                           &local_130);
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hdmi_codec_fill_codec_params @ 001010ec size=388
// signature: undefined hdmi_codec_fill_codec_params(void)
// callers: [hdmi_codec_prepare, hdmi_codec_hw_params]
//------------------------------------------------------------

undefined8
hdmi_codec_fill_codec_params
          (long param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined8 *param_5)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  uint uVar5;
  undefined8 uVar6;
  long lVar7;
  int *piVar8;
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x98);
  uVar5 = 0;
  piVar8 = &hdmi_codec_channel_alloc;
  bVar1 = *(byte *)(lVar7 + 0x1f);
  uVar4 = 0;
  if ((bVar1 & 1) != 0) {
    uVar4 = 5;
  }
  uVar4 = uVar4 | ((ulong)(bVar1 >> 1) & 1) << 10 | (ulong)(bVar1 >> 1 & 2);
  if ((bVar1 & 8) != 0) {
    uVar4 = uVar4 | 0xa0;
  }
  uVar4 = uVar4 | (bVar1 & 0x10) << 2;
  if ((bVar1 & 0x20) != 0) {
    uVar4 = uVar4 | 0x18;
  }
  if ((bVar1 & 0x40) != 0) {
    uVar4 = uVar4 | 0x300;
  }
  while ((((bVar1 & 0x7f) != 0 || (*piVar8 != 0)) &&
         ((piVar8[1] != (param_4 & 0xff) ||
          ((*(ulong *)(piVar8 + 2) & (uVar4 ^ 0xffffffffffffffff)) != 0))))) {
    uVar5 = uVar5 + 1;
    piVar8 = piVar8 + 4;
    if (uVar5 == 0x2b) {
      uVar6 = 0xffffffea;
      _dev_err(*(long *)(param_1 + 0x10),"Not able to map channels to speakers (%d)\n",0xffffffea);
      iVar3 = -1;
LAB_0010122c:
      *(int *)(lVar7 + 0xa0) = iVar3;
      return uVar6;
    }
  }
  param_5[0x19] = 0;
  param_5[0x1a] = 0;
  param_5[0x17] = 0;
  param_5[0x18] = 0;
  param_5[0x15] = 0;
  param_5[0x16] = 0;
  param_5[0x13] = 0;
  param_5[0x14] = 0;
  param_5[0x11] = 0;
  param_5[0x12] = 0;
  param_5[0xf] = 0;
  param_5[0x10] = 0;
  param_5[0xd] = 0;
  param_5[0xe] = 0;
  param_5[0xb] = 0;
  param_5[0xc] = 0;
  param_5[9] = 0;
  param_5[10] = 0;
  param_5[7] = 0;
  param_5[8] = 0;
  param_5[5] = 0;
  param_5[6] = 0;
  param_5[3] = 0;
  param_5[4] = 0;
  param_5[1] = 0;
  param_5[2] = 0;
  *param_5 = 0;
  hdmi_audio_infoframe_init(param_5);
  *(char *)((long)param_5 + 6) = (char)param_4;
  param_5[1] = 0;
  *(undefined4 *)(param_5 + 2) = 0;
  if (0x2a < uVar5) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101270);
    (*pcVar2)();
  }
  uVar6 = 0;
  iVar3 = *piVar8;
  *(undefined4 *)((long)param_5 + 0xcc) = param_3;
  *(undefined4 *)(param_5 + 0x1a) = param_2;
  *(uint *)((long)param_5 + 0xd4) = param_4;
  *(char *)(param_5 + 3) = (char)iVar3;
  goto LAB_0010122c;
}



//------------------------------------------------------------
// hdmi_dai_spdif_probe @ 00101274 size=240
// signature: undefined hdmi_dai_spdif_probe(void)
// callers: []
//------------------------------------------------------------

void hdmi_dai_spdif_probe(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined *local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined *local_78;
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
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_e8 = &DAT_001025d3;
  uStack_e0 = 0;
  local_d8 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0xa8);
  local_88 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x80);
  local_90 = 0;
  uStack_d0 = 0;
  uStack_80 = 0;
  uStack_70 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_78 = &DAT_001025b8;
  uVar2 = snd_soc_dapm_add_routes(*(long *)(param_1 + 0x58) + 0xd0,&local_e8,2);
  if ((int)uVar2 == 0) {
    puVar3 = (undefined4 *)devm_kmalloc(*(undefined8 *)(param_1 + 0x10),0xc,0xdc0);
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      uVar2 = 0;
      *(undefined4 **)(param_1 + 0x38) = puVar3;
      *puVar3 = 6;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// hdmi_probe @ 00101368 size=96
// signature: undefined hdmi_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_probe(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long *plVar3;
  
  plVar3 = *(long **)(*(long *)(param_1 + 0x18) + 0x98);
  pcVar2 = *(code **)(*plVar3 + 0x38);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x72ae842a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1013b0);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x60),plVar3[2],plugged_cb);
  }
  return uVar1;
}



//------------------------------------------------------------
// hdmi_remove @ 001013cc size=88
// signature: undefined hdmi_remove(void)
// callers: []
//------------------------------------------------------------

void hdmi_remove(long param_1)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x18) + 0x98);
  pcVar1 = *(code **)(*plVar2 + 0x38);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x72ae842a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101414);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x60),plVar2[2],0,0);
  }
  return;
}



//------------------------------------------------------------
// hdmi_codec_set_jack @ 00101428 size=80
// signature: undefined hdmi_codec_set_jack(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_codec_set_jack(long param_1,long param_2)

{
  undefined8 uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x18) + 0x98);
  if (*(long *)(*plVar2 + 0x38) == 0) {
    uVar1 = 0xfffffdf4;
  }
  else {
    plVar2[0x1c] = param_2;
    snd_soc_jack_report(param_2,(int)plVar2[0x1d],4);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// hdmi_of_xlate_dai_id @ 0010147c size=80
// signature: undefined hdmi_of_xlate_dai_id(void)
// callers: []
//------------------------------------------------------------

undefined8 hdmi_of_xlate_dai_id(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(**(long **)(*(long *)(param_1 + 0x18) + 0x98) + 0x30);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffdf4;
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x71302e4b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1014b4);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// plugged_cb @ 001014d0 size=204
// signature: undefined plugged_cb(void)
// callers: []
//------------------------------------------------------------

void plugged_cb(long param_1,ulong param_2)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x98);
  if ((param_2 & 1) == 0) {
    if ((int)plVar2[0x1d] != 0) {
      if (plVar2[0x1c] != 0) {
        snd_soc_jack_report(plVar2[0x1c],0,4);
      }
      *(undefined4 *)(plVar2 + 0x1d) = 0;
    }
    plVar2[0x11] = 0;
    plVar2[0x12] = 0;
    plVar2[0xf] = 0;
    plVar2[0x10] = 0;
    plVar2[0xd] = 0;
    plVar2[0xe] = 0;
    plVar2[0xb] = 0;
    plVar2[0xc] = 0;
    plVar2[9] = 0;
    plVar2[10] = 0;
    plVar2[7] = 0;
    plVar2[8] = 0;
    plVar2[5] = 0;
    plVar2[6] = 0;
    plVar2[3] = 0;
    plVar2[4] = 0;
  }
  else {
    pcVar1 = *(code **)(*plVar2 + 0x28);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x697c5574) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10151c);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(param_1 + 0x60),plVar2[2],plVar2 + 3,0x80);
    }
    if ((int)plVar2[0x1d] != 4) {
      if (plVar2[0x1c] != 0) {
        snd_soc_jack_report(plVar2[0x1c],4,4);
      }
      *(undefined4 *)(plVar2 + 0x1d) = 4;
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001015a0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&hdmi_codec_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001015d0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&hdmi_codec_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// platform_driver_unregister @ 00104008 size=1
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
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [hdmi_codec_probe, hdmi_dai_probe, hdmi_dai_spdif_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104018 size=1
// signature: undefined __mutex_init(void)
// callers: [hdmi_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_create_iec958_consumer_default @ 00104020 size=1
// signature: undefined snd_pcm_create_iec958_consumer_default(void)
// callers: [hdmi_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_create_iec958_consumer_default(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104028 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [hdmi_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_snd_soc_register_component @ 00104030 size=1
// signature: undefined devm_snd_soc_register_component(void)
// callers: [hdmi_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104038 size=1
// signature: undefined _dev_err(void)
// callers: [hdmi_codec_startup, hdmi_codec_probe, hdmi_codec_fill_codec_params, hdmi_codec_prepare, hdmi_codec_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 00104040 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [hdmi_dai_probe, hdmi_dai_spdif_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hdmi_dai_probe, hdmi_dai_spdif_probe, hdmi_codec_prepare, hdmi_codec_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_add_chmap_ctls @ 00104050 size=1
// signature: undefined snd_pcm_add_chmap_ctls(void)
// callers: [hdmi_codec_pcm_new]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_add_chmap_ctls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_ctl_new1 @ 00104058 size=1
// signature: undefined snd_ctl_new1(void)
// callers: [hdmi_codec_pcm_new]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_ctl_new1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_ctl_add @ 00104060 size=1
// signature: undefined snd_ctl_add(void)
// callers: [hdmi_codec_pcm_new]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_ctl_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104068 size=1
// signature: undefined mutex_lock(void)
// callers: [hdmi_codec_startup, hdmi_codec_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104070 size=1
// signature: undefined mutex_unlock(void)
// callers: [hdmi_codec_startup, hdmi_codec_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_hw_constraint_eld @ 00104078 size=1
// signature: undefined snd_pcm_hw_constraint_eld(void)
// callers: [hdmi_codec_startup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_hw_constraint_eld(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 00104080 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [hdmi_codec_prepare, hdmi_codec_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_fill_iec958_consumer_hw_params @ 00104088 size=1
// signature: undefined snd_pcm_fill_iec958_consumer_hw_params(void)
// callers: [hdmi_codec_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_fill_iec958_consumer_hw_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_fill_iec958_consumer @ 00104090 size=1
// signature: undefined snd_pcm_fill_iec958_consumer(void)
// callers: [hdmi_codec_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_fill_iec958_consumer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hdmi_audio_infoframe_init @ 00104098 size=1
// signature: undefined hdmi_audio_infoframe_init(void)
// callers: [hdmi_codec_fill_codec_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hdmi_audio_infoframe_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_jack_report @ 001040a0 size=1
// signature: undefined snd_soc_jack_report(void)
// callers: [hdmi_codec_set_jack, plugged_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_jack_report(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



