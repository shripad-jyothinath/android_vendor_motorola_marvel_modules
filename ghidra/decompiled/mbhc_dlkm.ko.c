// Decompiled by Ghidra 12.2
// Program: mbhc_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd_mbhc_jack_report @ 00100b14 size=40
// signature: undefined wcd_mbhc_jack_report(void)
// callers: []
//------------------------------------------------------------

void wcd_mbhc_jack_report
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  snd_soc_jack_report(param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// wcd_enable_curr_micbias @ 00100b40 size=84
// signature: undefined wcd_enable_curr_micbias(void)
// callers: [wcd_event_notify, wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug]
//------------------------------------------------------------

void wcd_enable_curr_micbias(long param_1,uint param_2)

{
  if (*(long *)(*(long *)(param_1 + 0x98) + 0xd0) == 0 && param_2 < 4) {
                    /* WARNING: Could not recover jumptable at 0x00100b80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)(&UNK_00100b84 + (ulong)(byte)(&DAT_001081a8)[param_2] * 4))();
    return;
  }
  return;
}



//------------------------------------------------------------
// wcd_cancel_btn_work @ 00100d84 size=96
// signature: undefined wcd_cancel_btn_work(void)
// callers: []
//------------------------------------------------------------

uint wcd_cancel_btn_work(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  uVar1 = cancel_delayed_work_sync();
  if ((uVar1 & 1) != 0) {
    pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
    if (*(int *)(pcVar2 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100dcc);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,0);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// wcd_swch_level_remove @ 00100de8 size=92
// signature: undefined wcd_swch_level_remove(void)
// callers: [wcd_mbhc_adc_detect_anc_plug_type, wcd_check_cross_conn, wcd_correct_swch_plug, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

bool wcd_swch_level_remove(long param_1)

{
  bool bVar1;
  uint uVar2;
  
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x1d8) == 0) {
    bVar1 = true;
  }
  else {
    uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    bVar1 = (uVar2 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0x1dc)) >>
            (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0x1dd) & 0x1f) != 0;
  }
  return bVar1;
}



//------------------------------------------------------------
// wcd_mbhc_get_impedance @ 00100e48 size=40
// signature: undefined wcd_mbhc_get_impedance(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd_mbhc_get_impedance(long param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_2 = *(int *)(param_1 + 0x1b8);
  iVar1 = *(int *)(param_1 + 0x1bc);
  *param_3 = iVar1;
  uVar2 = 0xffffffea;
  if (iVar1 != 0 && *param_2 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_mbhc_hs_elec_irq @ 00100e74 size=308
// signature: undefined wcd_mbhc_hs_elec_irq(void)
// callers: [wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_adc_detect_anc_plug_type, wcd_correct_swch_plug]
//------------------------------------------------------------

void wcd_mbhc_hs_elec_irq(long param_1,ulong param_2,uint param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  undefined4 *puVar5;
  code *pcVar6;
  ulong uVar7;
  
  uVar4 = mutex_is_locked(param_1 + 0x328);
  if (((uVar4 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
    wcd_mbhc_hs_elec_irq___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x100ee4);
    (*pcVar6)();
  }
  if ((int)param_2 == 1) {
    puVar5 = (undefined4 *)(*(long *)(param_1 + 0x358) + 0x10);
  }
  else {
    if ((int)param_2 != 0) {
      return;
    }
    puVar5 = (undefined4 *)(*(long *)(param_1 + 0x358) + 0xc);
  }
  if (((uint)(*(ulong *)(param_1 + ((param_2 & 0xffffffff) >> 3 & 0x1ffffff8) + 0x3d8) >>
             (param_2 & 0x3f)) & 1) != (param_3 & 1)) {
    pcVar6 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
    if (*(int *)(pcVar6 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x100f44);
      (*pcVar6)();
    }
    (*pcVar6)(*(undefined8 *)(param_1 + 0xf8),*puVar5);
    uVar7 = (param_2 & 0xffffffff) >> 6;
    uVar4 = 1L << (param_2 & 0x3f);
    if ((param_3 & 1) == 0) {
      puVar1 = (ulong *)(param_1 + 0x3d8 + uVar7 * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & (uVar4 ^ 0xffffffffffffffff);
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      puVar1 = (ulong *)(param_1 + 0x3d8 + uVar7 * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | uVar4;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  return;
}



//------------------------------------------------------------
// wcd_mbhc_report_plug @ 00100fc8 size=2496
// signature: undefined wcd_mbhc_report_plug(void)
// callers: [wcd_mbhc_find_plug_and_report, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wcd_mbhc_report_plug(long param_1,int param_2,uint param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  code *pcVar8;
  long lVar9;
  int iVar10;
  undefined8 uVar11;
  
  uVar11 = *(undefined8 *)(param_1 + 0xf8);
  uVar5 = mutex_is_locked(param_1 + 0x328);
  if (((uVar5 & 1) == 0) && ((wcd_mbhc_report_plug___already_done & 1) == 0)) {
    wcd_mbhc_report_plug___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_report_plug");
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x1017dc);
    (*pcVar8)();
  }
  _printk(&DAT_00108c8b,"wcd_mbhc_report_plug",param_2,*(undefined4 *)(param_1 + 0xa0),param_3);
  if (param_2 == 0) {
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & (param_3 ^ 0xffffffff);
    uVar5 = cancel_delayed_work_sync(param_1);
    if ((uVar5 & 1) == 0) {
      if (*(int *)(param_1 + 0x88) != 0) {
        snd_soc_jack_report(param_1 + 0x278,0);
        *(uint *)(param_1 + 0x88) = *(uint *)(param_1 + 0x88) & 0xffff81ff;
      }
    }
    else {
      pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
      if (*(int *)(pcVar8 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101070);
        (*pcVar8)();
      }
      (*pcVar8)(param_1,0);
    }
    if (*(char *)(param_1 + 0xef) != '\0') {
      lVar9 = *(long *)(param_1 + 0x98);
      pcVar8 = *(code **)(lVar9 + 0xd0);
      if (pcVar8 == (code *)0x0) {
        pcVar8 = *(code **)(lVar9 + 0xf0);
        if (pcVar8 == (code *)0x0) goto LAB_00101114;
LAB_00101154:
        if (*(int *)(pcVar8 + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x101178);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11,2,0);
        pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x40);
      }
      else {
        if (*(int *)(pcVar8 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x101144);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11,2,3);
        lVar9 = *(long *)(param_1 + 0x98);
        pcVar8 = *(code **)(lVar9 + 0xf0);
        if (pcVar8 != (code *)0x0) goto LAB_00101154;
LAB_00101114:
        pcVar8 = *(code **)(lVar9 + 0x40);
      }
      if (pcVar8 != (code *)0x0) {
        if (*(int *)(pcVar8 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1011a4);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11);
        iVar10 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x188);
        if (iVar10 != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),iVar10,
                     *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0x18c),0);
        }
      }
      *(undefined1 *)(param_1 + 0xef) = 0;
    }
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    *(undefined8 *)(param_1 + 0x1b8) = 0;
    _printk(&DAT_00108845,"wcd_mbhc_report_plug",param_3,*(undefined4 *)(param_1 + 0xa0));
    snd_soc_jack_report(param_1 + 0x1c8,*(undefined4 *)(param_1 + 0xa0),0xf);
    wcd_mbhc_set_and_turnoff_hph_padac(param_1);
    *(undefined1 *)(param_1 + 0xc1) = 0;
    *(undefined1 *)(param_1 + 0x3f0) = 0;
    goto LAB_00101940;
  }
  if ((*(char *)(*(long *)(param_1 + 0x90) + 0x10) != '\0') &&
     ((((param_3 == 4 || (*(char *)(param_1 + 0xc1) == '\x03')) &&
       (uVar4 = *(uint *)(param_1 + 0xa0), uVar4 != 0)) && (uVar4 != param_3)))) {
    if ((*(char *)(param_1 + 0xef) != '\0') && (uVar4 == 3)) {
      lVar9 = *(long *)(param_1 + 0x98);
      pcVar8 = *(code **)(lVar9 + 0xd0);
      if (pcVar8 == (code *)0x0) {
        pcVar8 = *(code **)(lVar9 + 0xf0);
        if (pcVar8 == (code *)0x0) goto LAB_001010cc;
LAB_00101244:
        if (*(int *)(pcVar8 + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x101268);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11,2,0);
        pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x40);
      }
      else {
        if (*(int *)(pcVar8 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x101234);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11,2,3);
        lVar9 = *(long *)(param_1 + 0x98);
        pcVar8 = *(code **)(lVar9 + 0xf0);
        if (pcVar8 != (code *)0x0) goto LAB_00101244;
LAB_001010cc:
        pcVar8 = *(code **)(lVar9 + 0x40);
      }
      if (pcVar8 != (code *)0x0) {
        if (*(int *)(pcVar8 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101294);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11);
        iVar10 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x188);
        if (iVar10 != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),iVar10,
                     *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0x18c),0);
        }
      }
      *(undefined1 *)(param_1 + 0xef) = 0;
    }
    *(undefined4 *)(param_1 + 0x1c4) = 0;
    *(undefined8 *)(param_1 + 0x1b8) = 0;
    if (*(char *)(param_1 + 0x3f0) == '\0') {
      _printk(&DAT_0010902d,"wcd_mbhc_report_plug",*(undefined4 *)(param_1 + 0xa0));
      snd_soc_jack_report(param_1 + 0x1c8,0,0xf);
      uVar6 = 0;
      if ((byte)(*(char *)(param_1 + 0xc1) - 1U) < 4) {
        uVar6 = *(undefined4 *)(&DAT_001091d4 + (long)(char)(*(char *)(param_1 + 0xc1) + -1) * 4);
      }
      extcon_set_state_sync(*(undefined8 *)(param_1 + 0x420),uVar6,0);
    }
    if (*(int *)(param_1 + 0xa0) == 4) {
      wcd_enable_curr_micbias(param_1,1);
      usleep_range_state(200,0xd2,2);
      uVar5 = mutex_is_locked(param_1 + 0x328);
      if (((uVar5 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
        wcd_mbhc_hs_elec_irq___already_done = 1;
        __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x800,0x101800);
        (*pcVar8)();
      }
      if (((uint)*(undefined8 *)(param_1 + 0x3d8) >> 1 & 1) == 0) {
        pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
        if (*(int *)(pcVar8 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10139c);
          (*pcVar8)();
        }
        (*pcVar8)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x10)
                  ,1);
        puVar1 = (ulong *)(param_1 + 0x3d8);
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
    }
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffff8;
  }
  if ((param_3 == 1) && (*(char *)(param_1 + 0xc1) == '\x01')) {
    *(uint *)(param_1 + 0xa0) = *(uint *)(param_1 + 0xa0) & 0xfffffffc;
LAB_001013e8:
    uVar7 = 2;
LAB_001013ec:
    *(undefined1 *)(param_1 + 0xc1) = uVar7;
  }
  else {
    if (param_3 == 1) goto LAB_001013e8;
    if (param_3 == 4) {
      uVar7 = 3;
      goto LAB_001013ec;
    }
    if (param_3 == 3) {
      *(undefined1 *)(param_1 + 0xc1) = 1;
      *(undefined8 *)(param_1 + 0x1b0) = _jiffies;
    }
    else {
      _printk(&DAT_0010899b,"wcd_mbhc_report_plug",param_3);
    }
  }
  pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0xb8);
  if (pcVar8 == (code *)0x0) {
    uVar5 = 0;
    cVar2 = *(char *)(param_1 + 0x1c0);
  }
  else {
    if (*(int *)(pcVar8 + -4) != -0x7ea8dd3) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101428);
      (*pcVar8)();
    }
    uVar5 = (*pcVar8)(uVar11);
    uVar5 = uVar5 & 0xffffffff;
    cVar2 = *(char *)(param_1 + 0x1c0);
  }
  if (((cVar2 != '\0') && (*(long *)(*(long *)(param_1 + 0x98) + 0x38) != 0)) &&
     (*(int *)(*(long *)(param_1 + 0x90) + 0x44) != 0 && (uVar5 & 1) == 0)) {
    lVar9 = *(long *)(param_1 + 0x3a8);
    if (*(int *)(lVar9 + 0xb8) == 0) {
      uVar4 = 0xea;
      iVar10 = *(int *)(lVar9 + 0x218);
joined_r0x001017b4:
      if (iVar10 != 0) goto LAB_00101474;
LAB_0010150c:
      iVar10 = *(int *)(lVar9 + 0xb8);
    }
    else {
      uVar4 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
      lVar9 = *(long *)(param_1 + 0x3a8);
      uVar4 = (uVar4 & *(byte *)(lVar9 + 0xbc)) >> (ulong)(*(byte *)(lVar9 + 0xbd) & 0x1f);
      if (*(int *)(lVar9 + 0xb8) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar9 + 0xb8),
                   *(undefined1 *)(lVar9 + 0xbc),0);
        lVar9 = *(long *)(param_1 + 0x3a8);
        iVar10 = *(int *)(lVar9 + 0x218);
        goto joined_r0x001017b4;
      }
      iVar10 = *(int *)(lVar9 + 0x218);
      if (iVar10 == 0) goto LAB_0010150c;
LAB_00101474:
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),iVar10,*(undefined1 *)(lVar9 + 0x21c),0);
      lVar9 = *(long *)(param_1 + 0x3a8);
      iVar10 = *(int *)(lVar9 + 0xb8);
    }
    if (iVar10 != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),iVar10,*(undefined1 *)(lVar9 + 0xbc),
                 1 << (ulong)(*(byte *)(lVar9 + 0xbd) & 0x1f));
    }
    pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x38);
    if (*(int *)(pcVar8 + -4) != 0x499ea4d0) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10155c);
      (*pcVar8)();
    }
    (*pcVar8)(param_1,param_1 + 0x1b8,(uint *)(param_1 + 0x1bc));
    lVar9 = *(long *)(param_1 + 0x3a8);
    if (*(int *)(lVar9 + 0xb8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar9 + 0xb8),
                 *(undefined1 *)(lVar9 + 0xbc),uVar4 << (ulong)(*(byte *)(lVar9 + 0xbd) & 0x1f));
    }
    _printk(&DAT_001083ab,"wcd_mbhc_report_plug",*(undefined4 *)(param_1 + 0x1b8),
            *(undefined4 *)(param_1 + 0x1bc),*(undefined4 *)(*(long *)(param_1 + 0x90) + 0x44));
    uVar4 = *(uint *)(*(long *)(param_1 + 0x90) + 0x44);
    if (((uVar4 < *(uint *)(param_1 + 0x1b8)) && (param_3 == 1)) &&
       (uVar4 < *(uint *)(param_1 + 0x1bc))) {
      *(undefined1 *)(param_1 + 0x3f0) = 1;
      *(undefined1 *)(param_1 + 0xc1) = 3;
      if (*(uint *)(param_1 + 0xa0) != 0) {
        uVar4 = *(uint *)(param_1 + 0xa0) & 0xfffffff8;
        *(uint *)(param_1 + 0xa0) = uVar4;
        snd_soc_jack_report(param_1 + 0x1c8,uVar4,0xf);
      }
      _printk(&DAT_00108f6f,"wcd_mbhc_report_plug");
      param_3 = 4;
    }
  }
  if (((uVar5 & 1) == 0) || (*(char *)(param_1 + 0x3f0) == '\0')) {
    uVar4 = *(uint *)(param_1 + 0xa0) | param_3;
    *(uint *)(param_1 + 0xa0) = uVar4;
    if (param_3 == 1) {
      pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0xd8);
      if (pcVar8 != (code *)0x0) {
        if (*(int *)(pcVar8 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10165c);
          (*pcVar8)();
        }
        (*pcVar8)(uVar11,0);
        uVar4 = *(uint *)(param_1 + 0xa0);
      }
      param_3 = 1;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xc1) = 3;
    if (*(uint *)(param_1 + 0xa0) == 0) {
      uVar4 = 4;
    }
    else {
      uVar4 = *(uint *)(param_1 + 0xa0) & 0xfffffff8;
      *(uint *)(param_1 + 0xa0) = uVar4;
      snd_soc_jack_report(param_1 + 0x1c8,uVar4,0xf);
      uVar4 = *(uint *)(param_1 + 0xa0) | 4;
    }
    param_3 = 4;
    *(uint *)(param_1 + 0xa0) = uVar4;
  }
  _printk(&DAT_00108c0a,"wcd_mbhc_report_plug",param_3,uVar4);
  snd_soc_jack_report(param_1 + 0x1c8,*(uint *)(param_1 + 0xa0) | 8,0xf);
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x198) == 0) {
    iVar10 = 0x395f8;
  }
  else {
    uVar4 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    iVar10 = (((uVar4 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0x19c)) >>
              (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0x19d) & 0x1f)) + 1 & 0xff) * 1000;
  }
  mutex_lock(hphr_pa_lock);
  puVar1 = (ulong *)(param_1 + 0x198);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar5 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar5 & 0xfffffffffffffffd;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  uVar4 = (uint)uVar5;
  if ((uVar4 >> 1 & 1) != 0) {
    lVar9 = *(long *)(param_1 + 0x3a8);
    if (*(int *)(lVar9 + 0x1a8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar9 + 0x1a8),
                 *(undefined1 *)(lVar9 + 0x1ac),1 << (ulong)(*(byte *)(lVar9 + 0x1ad) & 0x1f));
    }
  }
  mutex_unlock(hphr_pa_lock);
  mutex_lock(hphl_pa_lock);
  puVar1 = (ulong *)(param_1 + 0x198);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar5 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar5 & 0xfffffffffffffffe;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  if ((uVar5 & 1) == 0) {
    mutex_unlock(hphl_pa_lock);
    if ((uVar4 >> 1 & 1) != 0) goto LAB_00101880;
  }
  else {
    lVar9 = *(long *)(param_1 + 0x3a8);
    if (*(int *)(lVar9 + 0x1b8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar9 + 0x1b8),
                 *(undefined1 *)(lVar9 + 0x1bc),1 << (ulong)(*(byte *)(lVar9 + 0x1bd) & 0x1f));
    }
    mutex_unlock(hphl_pa_lock);
LAB_00101880:
    usleep_range_state(iVar10,iVar10 + 0x32,2);
  }
  puVar1 = (ulong *)(param_1 + 0x1a0);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar5 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar5 & 0xfffffffffffffffe;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  if ((uVar5 & 1) != 0) {
    usleep_range_state(20000,0x4e84,2);
    pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x118);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x1c0e0bd4) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1018e4);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(param_1 + 0xf8),1,0);
    }
  }
  puVar1 = (ulong *)(param_1 + 0x1a0);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar5 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar5 & 0xfffffffffffffffd;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  if (((uint)uVar5 >> 1 & 1) != 0) {
    usleep_range_state(20000,0x4e84,2);
    pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x118);
    if (pcVar8 != (code *)0x0) {
      if (*(int *)(pcVar8 + -4) != 0x1c0e0bd4) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10193c);
        (*pcVar8)();
      }
      (*pcVar8)(*(undefined8 *)(param_1 + 0xf8),1,1);
    }
  }
LAB_00101940:
  _printk(&DAT_0010859f,"wcd_mbhc_report_plug",*(undefined4 *)(param_1 + 0xa0));
  return;
}



//------------------------------------------------------------
// wcd_mbhc_set_and_turnoff_hph_padac @ 001019dc size=544
// signature: undefined wcd_mbhc_set_and_turnoff_hph_padac(void)
// callers: [wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug]
//------------------------------------------------------------

void wcd_mbhc_set_and_turnoff_hph_padac(long param_1)

{
  ulong *puVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  ulong uVar7;
  long lVar8;
  code *pcVar9;
  
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x198) == 0) {
    iVar3 = 0x395f8;
    iVar2 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x1c8);
  }
  else {
    uVar6 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar8 = *(long *)(param_1 + 0x3a8);
    iVar3 = (((uVar6 & *(byte *)(lVar8 + 0x19c)) >> (ulong)(*(byte *)(lVar8 + 0x19d) & 0x1f)) + 1 &
            0xff) * 1000;
    iVar2 = *(int *)(lVar8 + 0x1c8);
  }
  if (iVar2 != 0) {
    uVar6 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar8 = *(long *)(param_1 + 0x3a8);
    if ((uVar6 & *(byte *)(lVar8 + 0x1cc)) >> (ulong)(*(byte *)(lVar8 + 0x1cd) & 0x1f) == 0)
    goto LAB_00101ac0;
  }
  puVar1 = (ulong *)(param_1 + 0x198);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = *puVar1 | 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  puVar1 = (ulong *)(param_1 + 0x198);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = *puVar1 | 2;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  lVar8 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar8 + 600) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 600),*(undefined1 *)(lVar8 + 0x25c),
               0);
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0x268) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x268),
               *(undefined1 *)(lVar8 + 0x26c),0);
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
LAB_00101ac0:
  if (*(int *)(lVar8 + 0x1c8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x1c8),
               *(undefined1 *)(lVar8 + 0x1cc),0);
  }
  usleep_range_state(iVar3,iVar3 + 0x32,2);
  pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x120);
  if (pcVar9 != (code *)0x0) {
    if (*(int *)(pcVar9 + -4) != -0x153982ba) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x101b10);
      (*pcVar9)();
    }
    uVar7 = (*pcVar9)(param_1);
    if ((uVar7 & 1) != 0) {
      usleep_range_state(20000,0x4e84,2);
      puVar1 = (ulong *)(param_1 + 0x1a0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      puVar1 = (ulong *)(param_1 + 0x1a0);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | 2;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x118);
      if (pcVar9 != (code *)0x0) {
        if (*(int *)(pcVar9 + -4) != 0x1c0e0bd4) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x101b78);
          (*pcVar9)();
        }
        (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),0,0);
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x118);
        if (*(int *)(pcVar9 + -4) != 0x1c0e0bd4) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x101ba8);
          (*pcVar9)();
        }
        (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),0,1);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// wcd_mbhc_elec_hs_report_unplug @ 00101c30 size=604
// signature: undefined wcd_mbhc_elec_hs_report_unplug(void)
// callers: [wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

void wcd_mbhc_elec_hs_report_unplug(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  code *pcVar5;
  long lVar6;
  
  uVar4 = cancel_delayed_work_sync();
  if ((uVar4 & 1) != 0) {
    pcVar5 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
    if (*(int *)(pcVar5 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101c78);
      (*pcVar5)();
    }
    (*pcVar5)(param_1,0);
  }
  pcVar5 = *(code **)(*(long *)(param_1 + 1000) + 0x20);
  if (pcVar5 == (code *)0x0) {
    _printk(&DAT_00108f9c,"wcd_mbhc_elec_hs_report_unplug");
    uVar4 = *(ulong *)(param_1 + 0x1a8);
  }
  else {
    if (*(int *)(pcVar5 + -4) != 0x4eb19105) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101ca8);
      (*pcVar5)();
    }
    (*pcVar5)(param_1,param_1 + 0x360);
    uVar4 = *(ulong *)(param_1 + 0x1a8);
  }
  if ((uVar4 & 1) != 0) {
    wcd_mbhc_set_and_turnoff_hph_padac(param_1);
  }
  uVar4 = mutex_is_locked(param_1 + 0x328);
  if (((uVar4 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
    wcd_mbhc_hs_elec_irq___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101e48);
    (*pcVar5)();
  }
  if (((uint)*(undefined8 *)(param_1 + 0x3d8) >> 1 & 1) != 0) {
    pcVar5 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
    if (*(int *)(pcVar5 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101d10);
      (*pcVar5)();
    }
    (*pcVar5)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x10),0);
    puVar1 = (ulong *)(param_1 + 0x3d8);
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
  wcd_enable_curr_micbias(param_1,3);
  lVar6 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar6 + 0xb8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar6 + 0xb8),*(undefined1 *)(lVar6 + 0xbc),
               0);
    lVar6 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar6 + 0xa8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar6 + 0xa8),*(undefined1 *)(lVar6 + 0xac),
               3 << (ulong)(*(byte *)(lVar6 + 0xad) & 0x1f));
    lVar6 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar6 + 0x48) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar6 + 0x48),*(undefined1 *)(lVar6 + 0x4c),
               1 << (ulong)(*(byte *)(lVar6 + 0x4d) & 0x1f));
  }
  uVar4 = mutex_is_locked(param_1 + 0x328);
  if (((uVar4 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
    wcd_mbhc_hs_elec_irq___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101e6c);
    (*pcVar5)();
  }
  if ((*(ulong *)(param_1 + 0x3d8) & 1) == 0) {
    pcVar5 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
    if (*(int *)(pcVar5 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101de0);
      (*pcVar5)();
    }
    (*pcVar5)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0xc),1);
    puVar1 = (ulong *)(param_1 + 0x3d8);
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
  return;
}



//------------------------------------------------------------
// wcd_mbhc_find_plug_and_report @ 00101eb0 size=808
// signature: undefined wcd_mbhc_find_plug_and_report(void)
// callers: [wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_release_handler, wcd_correct_swch_plug]
//------------------------------------------------------------

void wcd_mbhc_find_plug_and_report(long param_1,uint param_2)

{
  ulong *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  byte bVar9;
  undefined8 uVar10;
  long lVar11;
  
  if (*(char *)(param_1 + 0x3d0) != '\0') {
    puVar8 = &DAT_001083dd;
    goto LAB_0010210c;
  }
  _printk(&DAT_001088d0,"wcd_mbhc_find_plug_and_report",*(undefined1 *)(param_1 + 0xc1),param_2);
  uVar6 = mutex_is_locked(param_1 + 0x328);
  if (((uVar6 & 1) == 0) && ((wcd_mbhc_find_plug_and_report___already_done & 1) == 0)) {
    wcd_mbhc_find_plug_and_report___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_find_plug_and_report");
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1021ac);
    (*pcVar5)();
  }
  bVar9 = *(byte *)(param_1 + 0xc1);
  if (bVar9 != param_2) {
    switch(param_2) {
    case 1:
      if ((*(char *)(*(long *)(param_1 + 0x90) + 0x54) != '\0') &&
         (pcVar5 = *(code **)(*(long *)(param_1 + 1000) + 0x18), pcVar5 != (code *)0x0)) {
        if (*(int *)(pcVar5 + -4) != -0x153982ba) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x101f70);
          (*pcVar5)();
        }
        (*pcVar5)(param_1);
      }
      wcd_mbhc_report_plug(param_1,1,3);
      uVar7 = *(undefined8 *)(param_1 + 0x420);
      uVar10 = 0x14;
      break;
    case 2:
      wcd_mbhc_report_plug(param_1,1,1);
      uVar7 = *(undefined8 *)(param_1 + 0x420);
      uVar10 = 0x15;
      break;
    case 3:
      cVar3 = *(char *)(*(long *)(param_1 + 0x90) + 0x10);
      wcd_mbhc_report_plug(param_1,1,4);
      extcon_set_state_sync(*(undefined8 *)(param_1 + 0x420),0x17,1);
      if (cVar3 == '\0') goto LAB_00102104;
      lVar11 = *(long *)(param_1 + 0x3a8);
      if (*(int *)(lVar11 + 0xb8) == 0) {
        iVar2 = *(int *)(lVar11 + 0x168);
        if (iVar2 == 0) goto LAB_00101fdc;
LAB_00102148:
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),iVar2,*(undefined1 *)(lVar11 + 0x16c),0);
        lVar11 = *(long *)(param_1 + 0x3a8);
        iVar2 = *(int *)(lVar11 + 0x48);
        if (iVar2 != 0) goto LAB_00102164;
LAB_00101fe4:
        iVar2 = *(int *)(lVar11 + 0xa8);
      }
      else {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar11 + 0xb8),
                   *(undefined1 *)(lVar11 + 0xbc),0);
        lVar11 = *(long *)(param_1 + 0x3a8);
        iVar2 = *(int *)(lVar11 + 0x168);
        if (iVar2 != 0) goto LAB_00102148;
LAB_00101fdc:
        iVar2 = *(int *)(lVar11 + 0x48);
        if (iVar2 == 0) goto LAB_00101fe4;
LAB_00102164:
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),iVar2,*(undefined1 *)(lVar11 + 0x4c),
                   1 << (ulong)(*(byte *)(lVar11 + 0x4d) & 0x1f));
        lVar11 = *(long *)(param_1 + 0x3a8);
        iVar2 = *(int *)(lVar11 + 0xa8);
      }
      if (iVar2 != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),iVar2,*(undefined1 *)(lVar11 + 0xac),
                   3 << (ulong)(*(byte *)(lVar11 + 0xad) & 0x1f));
      }
      uVar6 = mutex_is_locked(param_1 + 0x328);
      if (((uVar6 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
        wcd_mbhc_hs_elec_irq___already_done = 1;
        __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1021d0);
        (*pcVar5)();
      }
      if ((*(ulong *)(param_1 + 0x3d8) & 1) == 0) {
        pcVar5 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
        if (*(int *)(pcVar5 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102054);
          (*pcVar5)();
        }
        (*pcVar5)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0xc),
                  1);
        puVar1 = (ulong *)(param_1 + 0x3d8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      goto LAB_00102104;
    case 4:
      if (bVar9 == 2) {
        wcd_mbhc_report_plug(param_1,0,1);
        extcon_set_state_sync(*(undefined8 *)(param_1 + 0x420),0x15,0);
        bVar9 = *(byte *)(param_1 + 0xc1);
      }
      if (bVar9 == 1) {
        wcd_mbhc_report_plug(param_1,0,3);
        extcon_set_state_sync(*(undefined8 *)(param_1 + 0x420),0x14,0);
      }
      uVar7 = *(undefined8 *)(param_1 + 0x420);
      uVar10 = 0x3e;
      break;
    default:
      __warn_printk("Unexpected current plug_type %d, plug_type %d\n",bVar9,param_2);
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x102104);
      (*pcVar5)();
    }
    extcon_set_state_sync(uVar7,uVar10,1);
  }
LAB_00102104:
  puVar8 = &DAT_0010840a;
LAB_0010210c:
  _printk(puVar8,"wcd_mbhc_find_plug_and_report");
  return;
}



//------------------------------------------------------------
// wcd_mbhc_get_button_mask @ 001021f4 size=92
// signature: undefined wcd_mbhc_get_button_mask(void)
// callers: []
//------------------------------------------------------------

undefined4 wcd_mbhc_get_button_mask(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(*(long *)(param_1 + 0x98) + 0x88);
  if (*(int *)(pcVar3 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102224);
    (*pcVar3)();
  }
  uVar1 = (*pcVar3)(*(undefined8 *)(param_1 + 0xf8));
  if (uVar1 < 6) {
    uVar2 = (&DAT_00108238)[(int)uVar1];
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_mbhc_start @ 00102254 size=628
// signature: undefined wcd_mbhc_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wcd_mbhc_start(long param_1,long param_2)

{
  int *piVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  int *piVar8;
  ulong uVar9;
  long lVar10;
  
  iVar4 = -0x16;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar10 = *(long *)(*(long *)(param_1 + 0xf8) + 0x20);
    *(long *)(param_1 + 0x90) = param_2;
    piVar8 = (int *)(param_2 + 0x58);
    *piVar8 = 0;
    lVar7 = of_find_property(*(undefined8 *)(*(long *)(lVar10 + 0x40) + 0x2e8),
                             "qcom,msm-mbhc-usbc-audio-supported",0);
    if (lVar7 == 0) {
      iVar4 = 0;
      iVar5 = *piVar8;
    }
    else {
      iVar4 = of_property_read_variable_u32_array
                        (*(undefined8 *)(*(long *)(lVar10 + 0x40) + 0x2e8),
                         "qcom,msm-mbhc-usbc-audio-supported",piVar8,1,0);
      if (-1 < iVar4) {
        iVar4 = 0;
      }
      iVar5 = *piVar8;
    }
    if (iVar5 != 0) {
      *(undefined4 *)(param_1 + 0xd4) = 2;
      if ((*(long *)(param_1 + 0x3f8) == 0) && (*(long *)(param_1 + 0x400) == 0)) {
        _dev_err(*(undefined8 *)(lVar10 + 0x40),"%s: wcd939x or fsa i2c node not found\n",
                 "wcd_mbhc_start");
        return -0x16;
      }
      if (*piVar8 != 0) {
        *(undefined1 *)(param_2 + 0x48) = 0;
        *(undefined1 *)(param_2 + 0x5c) = 0;
      }
    }
    if (*(char *)(param_1 + 0xf4) == '\0') {
      uVar9 = 0;
      piVar1 = (int *)(*(long *)(param_1 + 0x90) + 0x24);
      do {
        if (piVar1[uVar9] != 0) {
          if ((uint)uVar9 < 6) {
            iVar5 = snd_jack_set_key(*(undefined8 *)(param_1 + 0x2a8),(&DAT_00108238)[uVar9]);
            if (iVar5 == 0) {
              input_set_capability
                        (*(undefined8 *)(*(long *)(param_1 + 0x2a8) + 0x20),1,piVar1[uVar9]);
              goto LAB_00102338;
            }
            _printk(&DAT_001089d4,"wcd_mbhc_set_keycode",piVar1[uVar9]);
          }
          else if ((wcd_mbhc_set_keycode___already_done & 1) == 0) {
            wcd_mbhc_set_keycode___already_done = 1;
            __warn_printk("Wrong button number:%d\n",uVar9 & 0xffffffff);
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102480);
            (*pcVar3)();
          }
          _printk(&DAT_00108784);
          goto LAB_0010238c;
        }
LAB_00102338:
        uVar9 = uVar9 + 1;
      } while (uVar9 != 8);
      if (*piVar1 != 0) {
        *(undefined1 *)(param_1 + 0xf4) = 1;
      }
    }
LAB_0010238c:
    if (((**(char **)(param_1 + 0x90) == '\0') || (*(long *)(param_1 + 0x188) != 0)) ||
       (*(long *)(param_1 + 400) != 0)) {
      wcd_mbhc_initialise(param_1);
      iVar4 = 0;
      iVar5 = *piVar8;
    }
    else {
      uVar6 = jiffies_to_usecs(0x3ffffffffffffffe);
      uVar2 = 0x3ffffffffffffffe;
      if (3999999 < uVar6) {
        uVar2 = 1000;
      }
      queue_delayed_work_on(0x20,_system_wq,param_1 + 0x100,uVar2);
      iVar5 = *piVar8;
    }
    if (iVar5 != 0) {
      *(undefined4 *)(param_1 + 0x418) = 0;
      *(code **)(param_1 + 0x408) = wcd_mbhc_usbc_ana_event_handler;
      if (*(long *)(param_1 + 0x3f8) != 0) {
        iVar4 = wcd_usbss_reg_notifier(param_1 + 0x408);
      }
      if (*(long *)(param_1 + 0x400) != 0) {
        iVar4 = fsa4480_reg_notifier(param_1 + 0x408);
      }
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// wcd_mbhc_initialise @ 001024cc size=1096
// signature: undefined wcd_mbhc_initialise(void)
// callers: [wcd_mbhc_start, wcd_mbhc_fw_read]
//------------------------------------------------------------

void wcd_mbhc_initialise(long param_1)

{
  undefined1 uVar1;
  undefined8 uVar2;
  int iVar3;
  code *pcVar4;
  long lVar5;
  int iVar6;
  undefined8 uVar7;
  
  uVar7 = *(undefined8 *)(param_1 + 0xf8);
  mutex_lock(param_1 + 0x328);
  pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0x128);
  if (pcVar4 == (code *)0x0) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 200);
    if (pcVar4 == (code *)0x0) {
      lVar5 = *(long *)(param_1 + 0x3a8);
      if (*(int *)(lVar5 + 0x58) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0x58),
                   *(undefined1 *)(lVar5 + 0x5c),3 << (ulong)(*(byte *)(lVar5 + 0x5d) & 0x1f));
      }
    }
    else {
      if (*(int *)(pcVar4 + -4) != 0x58ba7acd) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102550);
        (*pcVar4)();
      }
      (*pcVar4)(uVar7,0xffffffff);
    }
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x79a901b6) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102520);
      (*pcVar4)();
    }
    (*pcVar4)(uVar7,0xffffffff);
  }
  if (((*(char *)(*(long *)(param_1 + 0x90) + 0x48) == '\0') ||
      (pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0x108), pcVar4 == (code *)0x0)) ||
     (*(char *)(*(long *)(param_1 + 0x90) + 0x5c) != '\0')) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0x140);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1025c0);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,0);
    }
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x5c9283de) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x822a,0x1025e4);
      (*pcVar4)();
    }
    (*pcVar4)(param_1);
  }
  if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0x128);
    if (pcVar4 == (code *)0x0) {
      pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 200);
      if (pcVar4 == (code *)0x0) {
        iVar6 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x58);
        if (iVar6 != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),iVar6,
                     *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0x5c),0);
        }
      }
      else {
        if (*(int *)(pcVar4 + -4) != 0x58ba7acd) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102650);
          (*pcVar4)();
        }
        (*pcVar4)(uVar7,0);
      }
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x79a901b6) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102620);
        (*pcVar4)();
      }
      (*pcVar4)(uVar7,0x18);
    }
  }
  lVar5 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar5 + 0x78) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0x78),*(undefined1 *)(lVar5 + 0x7c),
               (uint)*(byte *)(param_1 + 0xc3) << (ulong)(*(byte *)(lVar5 + 0x7d) & 0x1f));
    lVar5 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar5 + 0x88) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0x88),*(undefined1 *)(lVar5 + 0x8c),
               (uint)*(byte *)(param_1 + 0xc4) << (ulong)(*(byte *)(lVar5 + 0x8d) & 0x1f));
    lVar5 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar5 + 0x98) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0x98),*(undefined1 *)(lVar5 + 0x9c),
               1 << (ulong)(*(byte *)(lVar5 + 0x9d) & 0x1f));
  }
  if ((*(char *)(*(long *)(param_1 + 0x90) + 0x21) != '\0') &&
     (pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0xf8), pcVar4 != (code *)0x0)) {
    if (*(int *)(pcVar4 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102718);
      (*pcVar4)();
    }
    (*pcVar4)(uVar7,1);
  }
  lVar5 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar5 + 0x68) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0x68),*(undefined1 *)(lVar5 + 0x6c),
               1 << (ulong)(*(byte *)(lVar5 + 0x6d) & 0x1f));
  }
  lVar5 = *(long *)(param_1 + 0x3a8);
  iVar6 = *(int *)(lVar5 + 8);
  if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) == 0) {
    if (iVar6 == 0) goto LAB_00102784;
    uVar2 = *(undefined8 *)(param_1 + 0xf8);
    uVar1 = *(undefined1 *)(lVar5 + 0xc);
    iVar3 = 1 << (ulong)(*(byte *)(lVar5 + 0xd) & 0x1f);
  }
  else {
    if (iVar6 == 0) goto LAB_00102784;
    uVar2 = *(undefined8 *)(param_1 + 0xf8);
    iVar3 = 0;
    uVar1 = *(undefined1 *)(lVar5 + 0xc);
  }
  snd_soc_component_update_bits(uVar2,iVar6,uVar1,iVar3);
LAB_00102784:
  lVar5 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar5 + 200) != 0) {
    iVar6 = 6;
    if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) {
      iVar6 = 4;
    }
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 200),*(undefined1 *)(lVar5 + 0xcc),
               iVar6 << (ulong)(*(byte *)(lVar5 + 0xcd) & 0x1f));
  }
  lVar5 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar5 + 0xd8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0xd8),*(undefined1 *)(lVar5 + 0xdc),
               2 << (ulong)(*(byte *)(lVar5 + 0xdd) & 0x1f));
  }
  pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0xa0);
  if (*(int *)(pcVar4 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102808);
    (*pcVar4)();
  }
  (*pcVar4)(uVar7,1);
  pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0x80);
  if (pcVar4 != (code *)0x0) {
    if (*(int *)(pcVar4 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102844);
      (*pcVar4)();
    }
    (*pcVar4)(uVar7,*(int *)(*(long *)(param_1 + 0x90) + 0x58) == 0);
  }
  lVar5 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar5 + 0xe8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar5 + 0xe8),*(undefined1 *)(lVar5 + 0xec),
               (*(short *)(*(long *)(*(long *)(param_1 + 0x90) + 8) + 0x30) + -0x578) / 100 <<
               (ulong)(*(byte *)(lVar5 + 0xed) & 0x1f));
  }
  lVar5 = *(long *)(*(long *)(param_1 + 0x90) + 8);
  if (lVar5 == 0) {
    _dev_err(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x20) + 0x40),
             "%s: calibration data is NULL\n","wcd_program_btn_threshold");
  }
  else {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0xc0);
    if (*(int *)(pcVar4 + -4) != 0x5be7b888) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1028d0);
      (*pcVar4)();
    }
    (*pcVar4)(*(long *)(param_1 + 0xf8),lVar5 + 0x50,
              lVar5 + 0x50 + (ulong)*(byte *)(lVar5 + 0x41) * 2,(ulong)*(byte *)(lVar5 + 0x41),0);
  }
  *(undefined4 *)(param_1 + 0x3b0) = 0;
  mutex_unlock(param_1 + 0x328);
  return;
}



//------------------------------------------------------------
// wcd_mbhc_usbc_ana_event_handler @ 00102918 size=684
// signature: undefined wcd_mbhc_usbc_ana_event_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_mbhc_usbc_ana_event_handler(long param_1,ulong param_2,char *param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  code *pcVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  
  lVar1 = param_1 + -0x408;
  if (lVar1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    plVar8 = (long *)(param_1 + -0x310);
    _dev_info(*(undefined8 *)(*plVar8 + 0x18),"%s: mode = %lu\n","wcd_mbhc_usbc_ana_event_handler",
              param_2);
    if (param_2 == 1) {
      if ((*(long *)(param_1 + -0x10) != 0) && ((param_3 == (char *)0x0 || (*param_3 == '\0')))) {
        wcd_usbss_switch_update(3,1);
      }
      plVar7 = (long *)(param_1 + -0x370);
      pcVar5 = *(code **)(*plVar7 + 0x80);
      if (pcVar5 != (code *)0x0) {
        if (*(int *)(pcVar5 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1029dc);
          (*pcVar5)();
        }
        (*pcVar5)(*plVar8,1);
      }
      lVar6 = *(long *)(param_1 + -0x60);
      if (*(int *)(lVar6 + 8) != 0) {
        snd_soc_component_update_bits
                  (*plVar8,*(int *)(lVar6 + 8),*(undefined1 *)(lVar6 + 0xc),
                   1 << (ulong)(*(byte *)(lVar6 + 0xd) & 0x1f));
      }
      if (*(long *)(param_1 + -0x10) != 0) {
        if (*(int *)(*(code **)(*plVar7 + 0x90) + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102a34);
          (*pcVar5)();
        }
        uVar4 = (**(code **)(*plVar7 + 0x90))(lVar1,1);
        if ((uVar4 & 1) == 0) {
          _printk(&DAT_001089f5,"wcd_mbhc_usbc_ana_event_handler");
        }
        else {
          if (*(char *)(param_1 + -0x347) == '\0') {
            wcd_mbhc_swch_irq_handler(lVar1);
          }
          if (*(int *)(*(code **)(*plVar7 + 0x90) + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102a78);
            (*pcVar5)();
          }
          (**(code **)(*plVar7 + 0x90))(lVar1,0);
        }
      }
    }
    else if (param_2 < 3) {
      if (*(long *)(param_1 + -0x10) != 0) {
        lVar6 = *(long *)(param_1 + -0x60);
        if (*(int *)(lVar6 + 8) != 0) {
          snd_soc_component_read(*plVar8);
          lVar6 = *(long *)(param_1 + -0x60);
        }
        if (*(int *)(lVar6 + 0x28) != 0) {
          uVar2 = snd_soc_component_read(*plVar8);
          if (param_2 != 0) {
            return 0;
          }
          if ((uVar2 & *(byte *)(*(long *)(param_1 + -0x60) + 0x2c)) >>
              (ulong)(*(byte *)(*(long *)(param_1 + -0x60) + 0x2d) & 0x1f) != 0) {
            return 0;
          }
          pcVar5 = *(code **)(*(long *)(param_1 + -0x370) + 0x90);
          if (*(int *)(pcVar5 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102b08);
            (*pcVar5)();
          }
          uVar4 = (*pcVar5)(lVar1,1);
          if ((uVar4 & 1) == 0) {
            _printk(&DAT_001089f5,"wcd_mbhc_usbc_ana_event_handler");
          }
          else {
            wcd_mbhc_swch_irq_handler(lVar1);
            pcVar5 = *(code **)(*(long *)(param_1 + -0x370) + 0x90);
            if (*(int *)(pcVar5 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102b40);
              (*pcVar5)();
            }
            (*pcVar5)(lVar1,0);
          }
          wcd_usbss_switch_update(3,0);
        }
      }
    }
    else if ((param_2 == 3) &&
            (pcVar5 = *(code **)(*(long *)(param_1 + -0x370) + 0x148), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0x5c9283de) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102b88);
        (*pcVar5)();
      }
      (*pcVar5)(lVar1);
    }
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// wcd_mbhc_stop @ 00102bc8 size=316
// signature: undefined wcd_mbhc_stop(void)
// callers: []
//------------------------------------------------------------

void wcd_mbhc_stop(long param_1)

{
  code *pcVar1;
  
  if (((*(char *)(param_1 + 0xc1) != '\0') && (*(long *)(param_1 + 0x98) != 0)) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0xe0), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c10);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(param_1 + 0xf8));
  }
  *(undefined1 *)(param_1 + 0xc1) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  if ((*(long *)(param_1 + 0x98) != 0) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x70), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c54);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x14),0);
    pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
    if (*(int *)(pcVar1 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c88);
      (*pcVar1)();
    }
    (*pcVar1)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x18),0);
  }
  if ((*(long *)(param_1 + 0x188) != 0) || (*(long *)(param_1 + 400) != 0)) {
    cancel_delayed_work_sync(param_1 + 0x100);
    if (*(long *)(param_1 + 400) == 0) {
      release_firmware(*(undefined8 *)(param_1 + 0x188));
    }
    *(undefined8 *)(param_1 + 0x188) = 0;
    *(undefined8 *)(param_1 + 400) = 0;
  }
  if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) {
    if ((*(long *)(param_1 + 0x3f8) != 0) &&
       (wcd_usbss_unreg_notifier(param_1 + 0x408), *(int *)(*(long *)(param_1 + 0x90) + 0x58) == 0))
    {
      return;
    }
    if (*(long *)(param_1 + 0x400) != 0) {
      fsa4480_unreg_notifier(param_1 + 0x408);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd_mbhc_init @ 00102d08 size=2820
// signature: undefined wcd_mbhc_init(void)
// callers: []
//------------------------------------------------------------

int wcd_mbhc_init(undefined8 *param_1,long param_2,long param_3,long param_4,long param_5,
                 byte param_6)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined *puVar11;
  char *pcVar12;
  code *pcVar13;
  long *plVar14;
  long lVar15;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined4 local_b0;
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
  
  lVar15 = sp_el0;
  local_58 = *(long *)(lVar15 + 0x638);
  lVar15 = *(long *)(param_2 + 0x20);
  local_c0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  iVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),"qcom,msm-mbhc-hphl-swh",
                     (long)&local_c0 + 4,1,0);
  if (iVar7 < 0) {
    _dev_err(*(long *)(lVar15 + 0x40),"%s: missing %s in dt node\n","wcd_mbhc_init",
             "qcom,msm-mbhc-hphl-swh");
    goto LAB_0010374c;
  }
  iVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),"qcom,msm-mbhc-gnd-swh",
                     &local_c0,1,0);
  if (iVar7 < 0) {
    _dev_err(*(long *)(lVar15 + 0x40),"%s: missing %s in dt node\n","wcd_mbhc_init",
             "qcom,msm-mbhc-gnd-swh");
    goto LAB_0010374c;
  }
  of_property_read_variable_u32_array
            (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),
             "qcom,msm-mbhc-hs-mic-max-threshold-mv",param_1 + 0x19,1,0);
  of_property_read_variable_u32_array
            (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),
             "qcom,msm-mbhc-hs-mic-min-threshold-mv",(long)param_1 + 0xcc,1,0);
  iVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),"qcom,msm-mbhc-moist-cfg",
                     &local_b8,3,0);
  if (iVar7 < 0) {
    uVar4 = 1;
    uVar5 = 3;
    uVar6 = 1;
  }
  else {
    iVar7 = 0;
    uVar4 = local_b0;
    uVar5 = local_b8._4_4_;
    uVar6 = (undefined4)local_b8;
  }
  *(undefined4 *)(param_1 + 0x1b) = uVar6;
  *(undefined4 *)((long)param_1 + 0xdc) = uVar5;
  *(undefined4 *)(param_1 + 0x1c) = uVar4;
  local_78 = 0;
  uStack_70 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  iVar8 = __of_parse_phandle_with_args
                    (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),"wcd939x-i2c-handle",0,0,0,
                     &local_a8);
  if (iVar8 != 0) {
    local_a8 = 0;
  }
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  param_1[0x7f] = local_a8;
  local_68 = 0;
  uStack_60 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  iVar8 = __of_parse_phandle_with_args
                    (*(undefined8 *)(*(long *)(lVar15 + 0x40) + 0x2e8),"fsa4480-i2c-handle",0,0,0,
                     &local_a8);
  *(undefined1 *)((long)param_1 + 0xc2) = 0;
  uVar10 = local_a8;
  if (iVar8 != 0) {
    uVar10 = 0;
  }
  *(undefined2 *)(param_1 + 0x18) = 0;
  param_1[0x1f] = param_2;
  param_1[0x6b] = param_4;
  param_1[0x80] = uVar10;
  *(byte *)(param_1 + 0x38) = param_6 & 1;
  *(bool *)((long)param_1 + 0xc3) = local_c0._4_4_ != 0;
  *(bool *)((long)param_1 + 0xc4) = (int)local_c0 != 0;
  *(undefined1 *)((long)param_1 + 0xef) = 0;
  param_1[0x13] = param_3;
  *(undefined2 *)(param_1 + 0x1e) = 0;
  *(undefined1 *)((long)param_1 + 0xf2) = 0;
  *(undefined1 *)((long)param_1 + 0xf5) = 0;
  *(undefined4 *)((long)param_1 + 0x1c4) = 0;
  param_1[0x75] = param_5;
  *(undefined4 *)((long)param_1 + 0xd4) = 4;
  *(undefined8 *)((long)param_1 + 0xe4) = 0x6400000064;
  if (param_4 == 0) {
    _printk(&DAT_001087a1,"wcd_mbhc_init");
    iVar7 = -0x16;
    goto LAB_0010374c;
  }
  if (param_5 == 0) {
    uVar10 = *(undefined8 *)(param_2 + 0x18);
    pcVar12 = "%s: mbhc registers are not defined\n";
  }
  else {
    if ((((param_3 != 0) && (*(long *)(param_3 + 0x68) != 0)) && (*(long *)(param_3 + 0x70) != 0))
       && (((*(long *)(param_3 + 0x78) != 0 && (*(long *)(param_3 + 0x88) != 0)) &&
           ((*(long *)(param_3 + 0x90) != 0 &&
            ((*(long *)(param_3 + 0xa0) != 0 && (*(long *)(param_3 + 0xc0) != 0)))))))) {
      if (param_1[0x3f] == 0) {
        iVar7 = snd_soc_card_jack_new
                          (*(undefined8 *)(param_2 + 0x20),"Headset Jack",0xf,param_1 + 0x39);
        if (iVar7 == 0) {
          iVar7 = snd_soc_card_jack_new
                            (*(undefined8 *)(param_2 + 0x20),"Button Jack",0x7e00,param_1 + 0x4f);
          if (iVar7 != 0) {
            _printk(&DAT_001089b7);
            goto LAB_0010374c;
          }
          iVar7 = snd_jack_set_key(param_1[0x55],0x4000,0xe2);
          if (iVar7 == 0) {
            param_1[0x20] = 0xfffffffe0;
            param_1[0x21] = param_1 + 0x21;
            param_1[0x22] = param_1 + 0x21;
            param_1[0x23] = wcd_mbhc_fw_read;
            init_timer_key(param_1 + 0x26,&delayed_work_timer_fn,0x200000,0,0);
            *param_1 = 0xfffffffe0;
            param_1[1] = param_1 + 1;
            param_1[2] = param_1 + 1;
            param_1[3] = wcd_btn_lpress_fn;
            init_timer_key(param_1 + 6,&delayed_work_timer_fn,0x200000,0,0);
            iVar7 = 0;
            goto LAB_00103034;
          }
          puVar11 = &DAT_00108fc5;
        }
        else {
          puVar11 = &DAT_00108a92;
        }
        _printk(puVar11,"wcd_mbhc_init");
        goto LAB_0010374c;
      }
LAB_00103034:
      *(undefined4 *)(param_1 + 0x76) = 0;
      __init_swait_queue_head(param_1 + 0x77,"&x->wait",&init_completion___key);
      param_1[0x72] = wcd_event_notify;
      pcVar13 = *(code **)(param_1[0x13] + 0x60);
      if (pcVar13 != (code *)0x0) {
        if (*(int *)(pcVar13 + -4) != -0xea46357) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103090);
          (*pcVar13)();
        }
        iVar7 = (*pcVar13)(param_1,param_1 + 0x72,1);
        if (iVar7 != 0) {
          _printk(&DAT_001085f5,"wcd_mbhc_init",iVar7);
          goto LAB_0010374c;
        }
      }
      __init_waitqueue_head(param_1 + 0x15,"&mbhc->wait_btn_press",&wcd_mbhc_init___key);
      __mutex_init(param_1 + 0x65,"&mbhc->codec_resource_lock",&wcd_mbhc_init___key_37);
      if (*(int *)((long)param_1 + 0x3d4) == 0) {
LAB_001030e4:
        plVar14 = (long *)param_1[0x7d];
        if (plVar14 == (long *)0x0) goto LAB_001035a8;
LAB_001030ec:
        if ((((*plVar14 == 0) || (plVar14[1] == 0)) || (plVar14[2] == 0)) || (plVar14[4] == 0))
        goto LAB_001035a8;
        if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10314c);
          (*pcVar13)();
        }
        iVar7 = (**(code **)(param_1[0x13] + 0x68))
                          (param_2,*(undefined4 *)param_1[0x6b],wcd_mbhc_mech_plug_detect_irq,
                           "mbhc sw intr",param_1);
        if (iVar7 == 0) {
          if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103194);
            (*pcVar13)();
          }
          iVar7 = (**(code **)(param_1[0x13] + 0x68))
                            (param_2,*(undefined4 *)(param_1[0x6b] + 4),wcd_mbhc_btn_press_handler,
                             "Button Press detect",param_1);
          if (iVar7 == 0) {
            if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1031dc);
              (*pcVar13)();
            }
            iVar7 = (**(code **)(param_1[0x13] + 0x68))
                              (param_2,*(undefined4 *)(param_1[0x6b] + 8),wcd_mbhc_release_handler,
                               "Button Release detect",param_1);
            if (iVar7 == 0) {
              if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103224);
                (*pcVar13)();
              }
              iVar7 = (**(code **)(param_1[0x13] + 0x68))
                                (param_2,*(undefined4 *)(param_1[0x6b] + 0xc),
                                 *(undefined8 *)param_1[0x7d],"Elect Insert",param_1);
              if (iVar7 == 0) {
                if (*(int *)(*(code **)(param_1[0x13] + 0x70) + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10325c);
                  (*pcVar13)();
                }
                (**(code **)(param_1[0x13] + 0x70))(param_2,*(undefined4 *)(param_1[0x6b] + 0xc),0);
                puVar1 = param_1 + 0x7b;
                Hint_Prefetch(puVar1,2,0,1);
                do {
                  cVar2 = '\x01';
                  bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                  if (bVar3) {
                    *puVar1 = *puVar1 & 0xfffffffffffffffe;
                    cVar2 = ExclusiveMonitorsStatus();
                  }
                } while (cVar2 != '\0');
                if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1032b0);
                  (*pcVar13)();
                }
                iVar7 = (**(code **)(param_1[0x13] + 0x68))
                                  (param_2,*(undefined4 *)(param_1[0x6b] + 0x10),
                                   *(undefined8 *)(param_1[0x7d] + 8),"Elect Remove",param_1);
                if (iVar7 == 0) {
                  if (*(int *)(*(code **)(param_1[0x13] + 0x70) + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1032e8);
                    (*pcVar13)();
                  }
                  (**(code **)(param_1[0x13] + 0x70))
                            (param_2,*(undefined4 *)(param_1[0x6b] + 0x10),0);
                  puVar1 = param_1 + 0x7b;
                  Hint_Prefetch(puVar1,2,0,1);
                  do {
                    cVar2 = '\x01';
                    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                    if (bVar3) {
                      *puVar1 = *puVar1 & 0xfffffffffffffffd;
                      cVar2 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar2 != '\0');
                  if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10333c);
                    (*pcVar13)();
                  }
                  iVar7 = (**(code **)(param_1[0x13] + 0x68))
                                    (param_2,*(undefined4 *)(param_1[0x6b] + 0x14),
                                     wcd_mbhc_hphl_ocp_irq,"HPH_L OCP detect",param_1);
                  if (iVar7 == 0) {
                    if (*(int *)(*(code **)(param_1[0x13] + 0x68) + -4) != 0x5512c6ab) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103384);
                      (*pcVar13)();
                    }
                    iVar7 = (**(code **)(param_1[0x13] + 0x68))
                                      (param_2,*(undefined4 *)(param_1[0x6b] + 0x18),
                                       wcd_mbhc_hphr_ocp_irq,"HPH_R OCP detect",param_1);
                    if (iVar7 == 0) {
                      if (param_1[0x84] != 0) {
LAB_00103488:
                        iVar7 = 0;
                        *(undefined1 *)(param_1 + 0x7a) = 0;
                        goto LAB_0010374c;
                      }
                      uVar9 = devm_extcon_dev_allocate
                                        (*(undefined8 *)(param_2 + 0x18),
                                         mbhc_ext_dev_supported_table);
                      param_1[0x84] = uVar9;
                      if (uVar9 < 0xfffffffffffff001) {
                        iVar7 = devm_extcon_dev_register(*(undefined8 *)(param_2 + 0x18),uVar9);
                        if (iVar7 == 0) goto LAB_00103488;
                        _printk(&DAT_00108cf5,"wcd_mbhc_init");
                      }
                      else {
                        iVar7 = 0;
                      }
                      if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1033e4);
                        (*pcVar13)();
                      }
                      (**(code **)(param_1[0x13] + 0x78))
                                (param_2,*(undefined4 *)(param_1[0x6b] + 0x18),param_1);
                    }
                    else {
                      _printk(&DAT_00108ecb,"wcd_mbhc_init",*(undefined4 *)(param_1[0x6b] + 0x18));
                    }
                    if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103610);
                      (*pcVar13)();
                    }
                    (**(code **)(param_1[0x13] + 0x78))
                              (param_2,*(undefined4 *)(param_1[0x6b] + 0x14),param_1);
                  }
                  else {
                    _printk(&DAT_00108ecb,"wcd_mbhc_init",*(undefined4 *)(param_1[0x6b] + 0x14));
                  }
                  if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103644);
                    (*pcVar13)();
                  }
                  (**(code **)(param_1[0x13] + 0x78))
                            (param_2,*(undefined4 *)(param_1[0x6b] + 0x10),param_1);
                }
                else {
                  _printk(&DAT_00108ecb,"wcd_mbhc_init",*(undefined4 *)(param_1[0x6b] + 0x10));
                }
                if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103678);
                  (*pcVar13)();
                }
                (**(code **)(param_1[0x13] + 0x78))
                          (param_2,*(undefined4 *)(param_1[0x6b] + 0xc),param_1);
              }
              else {
                _printk(&DAT_00108ecb,"wcd_mbhc_init",*(undefined4 *)(param_1[0x6b] + 0xc));
              }
              if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1036ac);
                (*pcVar13)();
              }
              (**(code **)(param_1[0x13] + 0x78))
                        (param_2,*(undefined4 *)(param_1[0x6b] + 8),param_1);
            }
            else {
              _printk(&DAT_00108ecb,"wcd_mbhc_init",*(undefined4 *)(param_1[0x6b] + 8));
            }
            if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1036e0);
              (*pcVar13)();
            }
            (**(code **)(param_1[0x13] + 0x78))(param_2,*(undefined4 *)(param_1[0x6b] + 4),param_1);
          }
          else {
            _printk(&DAT_00108ecb,"wcd_mbhc_init",*(undefined4 *)(param_1[0x6b] + 4));
          }
          if (*(int *)(*(code **)(param_1[0x13] + 0x78) + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103714);
            (*pcVar13)();
          }
          (**(code **)(param_1[0x13] + 0x78))(param_2,*(undefined4 *)param_1[0x6b],param_1);
        }
        else {
          _printk(&DAT_00108e54,"wcd_mbhc_init",*(undefined4 *)param_1[0x6b],iVar7);
        }
      }
      else {
        if (*(int *)((long)param_1 + 0x3d4) == 1) {
          wcd_mbhc_adc_init(param_1);
          goto LAB_001030e4;
        }
        _printk(&DAT_0010861b,"wcd_mbhc_init");
        plVar14 = (long *)param_1[0x7d];
        if (plVar14 != (long *)0x0) goto LAB_001030ec;
LAB_001035a8:
        _printk(&DAT_0010844a,"wcd_mbhc_init");
      }
      pcVar13 = *(code **)(param_1[0x13] + 0x60);
      if (pcVar13 != (code *)0x0) {
        if (*(int *)(pcVar13 + -4) != -0xea46357) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x103748);
          (*pcVar13)();
        }
        (*pcVar13)(param_1,param_1 + 0x72,0);
      }
      goto LAB_0010374c;
    }
    uVar10 = *(undefined8 *)(param_2 + 0x18);
    pcVar12 = "%s: required mbhc callbacks are not defined\n";
  }
  _dev_err(uVar10,pcVar12,"wcd_mbhc_init");
  iVar7 = -0x16;
LAB_0010374c:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// wcd_mbhc_fw_read @ 00103828 size=412
// signature: undefined wcd_mbhc_fw_read(void)
// callers: []
//------------------------------------------------------------

void wcd_mbhc_fw_read(long param_1)

{
  ulong *puVar1;
  bool bVar2;
  int iVar3;
  ulong *puVar4;
  code *pcVar5;
  ulong *puVar6;
  long lVar7;
  int iVar8;
  ulong *local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  iVar8 = 0xf;
  lVar7 = *(long *)(param_1 + -8);
  local_50 = (ulong *)0x0;
  do {
    pcVar5 = *(code **)(*(long *)(param_1 + -0x68) + 0x50);
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(pcVar5 + -4) != 0x710a3f47) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1038a0);
        (*pcVar5)();
      }
      puVar4 = (ulong *)(*pcVar5)(param_1 + -0x100,2);
      if (puVar4 == (ulong *)0x0) goto LAB_001038a8;
      bVar2 = false;
      puVar6 = puVar4 + 1;
LAB_00103910:
      if (0x69 < *puVar6) {
        puVar1 = local_50 + 1;
        if (!bVar2) {
          puVar1 = puVar4;
        }
        if ((ulong)*(byte *)(*puVar1 + 0x41) * 4 + 0x56 <= *puVar6) {
          if (bVar2) {
            *(ulong *)(*(long *)(param_1 + -0x70) + 8) = local_50[1];
            *(ulong **)(param_1 + 0x88) = local_50;
          }
          else {
            *(ulong *)(*(long *)(param_1 + -0x70) + 8) = *puVar4;
            *(ulong **)(param_1 + 0x90) = puVar4;
          }
          goto LAB_00103964;
        }
      }
      _printk(&DAT_001084b5,"wcd_mbhc_fw_read");
      if (bVar2) {
        release_firmware(local_50);
      }
      goto LAB_00103964;
    }
LAB_001038a8:
    iVar3 = request_firmware(&local_50,"wcd9320/wcd9320_mbhc.bin",*(undefined8 *)(lVar7 + 0x18));
    if (iVar3 == 0) {
      puVar4 = (ulong *)0x0;
      bVar2 = true;
      puVar6 = local_50;
      goto LAB_00103910;
    }
    usleep_range_state(4000000,0x3d0964,2);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  _printk(&DAT_00108507,"wcd_mbhc_fw_read");
LAB_00103964:
  wcd_mbhc_initialise(param_1 + -0x100);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd_btn_lpress_fn @ 001039c8 size=180
// signature: undefined wcd_btn_lpress_fn(void)
// callers: []
//------------------------------------------------------------

void wcd_btn_lpress_fn(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x158) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    uVar1 = (uVar1 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0x15c)) >>
            (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0x15d) & 0x1f);
  }
  if (*(char *)(param_1 + 0xc1) == '\x01') {
    _printk(&DAT_00108d33,"wcd_btn_lpress_fn",uVar1);
    snd_soc_jack_report(param_1 + 0x278,*(undefined4 *)(param_1 + 0x88),
                        *(undefined4 *)(param_1 + 0x88));
  }
  pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
  if (*(int *)(pcVar2 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103a40);
    (*pcVar2)();
  }
  (*pcVar2)(param_1,0);
  return;
}



//------------------------------------------------------------
// wcd_event_notify @ 00103a80 size=1364
// signature: undefined wcd_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_event_notify(undefined8 param_1,undefined4 param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  long lVar7;
  undefined8 uVar8;
  
  uVar8 = *(undefined8 *)(param_3 + 0xf8);
  pcVar6 = *(code **)(*(long *)(param_3 + 0x98) + 0x98);
  if (pcVar6 == (code *)0x0) {
    uVar4 = 0;
    uVar5 = 0;
  }
  else {
    if (*(int *)(pcVar6 + -4) != 0x65fc7482) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103ad0);
      (*pcVar6)();
    }
    uVar4 = (*pcVar6)(param_3,2);
    pcVar6 = *(code **)(*(long *)(param_3 + 0x98) + 0x98);
    if (*(int *)(pcVar6 + -4) != 0x65fc7482) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103b00);
      (*pcVar6)();
    }
    uVar5 = (*pcVar6)(param_3,1);
  }
  switch(param_2) {
  case 1:
    if ((*(long *)(*(long *)(param_3 + 0x98) + 0xd0) != 0) && (*(char *)(param_3 + 0xef) == '\0')) {
      lVar7 = *(long *)(param_3 + 0x3a8);
      if (*(int *)(lVar7 + 0xb8) != 0) {
        uVar4 = snd_soc_component_read(*(undefined8 *)(param_3 + 0xf8));
        lVar7 = *(long *)(param_3 + 0x3a8);
        if ((uVar4 & *(byte *)(lVar7 + 0xbc)) >> (ulong)(*(byte *)(lVar7 + 0xbd) & 0x1f) == 0) {
          return 0;
        }
      }
      if (*(int *)(lVar7 + 0x168) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_3 + 0xf8),*(int *)(lVar7 + 0x168),
                   *(undefined1 *)(lVar7 + 0x16c),3 << (ulong)(*(byte *)(lVar7 + 0x16d) & 0x1f));
      }
    }
    break;
  case 2:
    lVar7 = *(long *)(param_3 + 0x98);
    if (*(long *)(lVar7 + 0xd0) == 0) {
      *(undefined1 *)(param_3 + 0xf1) = 0;
    }
    if (*(char *)(param_3 + 0xef) == '\0') {
      pcVar6 = *(code **)(lVar7 + 0x48);
      if (pcVar6 != (code *)0x0) {
        if (*(int *)(pcVar6 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x103d40);
          (*pcVar6)();
        }
        (*pcVar6)(uVar8,0);
        lVar7 = *(long *)(param_3 + 0x98);
      }
      pcVar6 = *(code **)(lVar7 + 0x40);
      if ((pcVar6 != (code *)0x0) && (*(char *)(param_3 + 0xef) == '\0')) {
        if (*(int *)(pcVar6 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103d74);
          (*pcVar6)();
        }
        (*pcVar6)(uVar8);
      }
      if ((*(ulong *)(param_3 + 0x1a8) & 1) == 0) {
        uVar4 = (uint)*(undefined8 *)(param_3 + 0x1a8) & 2;
      }
      else {
        uVar4 = 2;
      }
      wcd_enable_curr_micbias(param_3,uVar4);
      pcVar6 = *(code **)(*(long *)(param_3 + 0x98) + 0x58);
      if (pcVar6 == (code *)0x0) {
        return 0;
      }
      if (*(int *)(pcVar6 + -4) != 0x7065c181) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103f1c);
        (*pcVar6)();
      }
      (*pcVar6)(uVar8,uVar5 & 1,0);
      return 0;
    }
    goto LAB_00103df8;
  case 4:
    if (*(char *)(param_3 + 0xef) != '\0') {
      lVar7 = *(long *)(param_3 + 0x98);
      pcVar6 = *(code **)(lVar7 + 0xa8);
      if (pcVar6 != (code *)0x0) {
        if (*(int *)(pcVar6 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x103c0c);
          (*pcVar6)();
        }
        (*pcVar6)(uVar8,0,1);
        pcVar6 = *(code **)(*(long *)(param_3 + 0x98) + 0xa8);
        if (*(int *)(pcVar6 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103c3c);
          (*pcVar6)();
        }
        (*pcVar6)(uVar8,1,1);
        msleep(0x32);
        lVar7 = *(long *)(param_3 + 0x98);
      }
      pcVar6 = *(code **)(lVar7 + 0x48);
      if (pcVar6 != (code *)0x0) {
        if (*(int *)(pcVar6 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x103c74);
          (*pcVar6)();
        }
        (*pcVar6)(uVar8,1);
        lVar7 = *(long *)(param_3 + 0x98);
      }
      pcVar6 = *(code **)(lVar7 + 0xa8);
      if (pcVar6 != (code *)0x0) {
        if (*(int *)(pcVar6 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103ca8);
          (*pcVar6)();
        }
        (*pcVar6)(uVar8,0,0);
      }
    }
    if (*(long *)(*(long *)(param_3 + 0x98) + 0xd0) == 0) {
      *(undefined1 *)(param_3 + 0xf1) = 1;
      wcd_enable_curr_micbias(param_3,1);
    }
    else {
      lVar7 = *(long *)(param_3 + 0x3a8);
      if (*(int *)(lVar7 + 0xb8) != 0) {
        uVar4 = snd_soc_component_read(*(undefined8 *)(param_3 + 0xf8));
        lVar7 = *(long *)(param_3 + 0x3a8);
        if ((uVar4 & *(byte *)(lVar7 + 0xbc)) >> (ulong)(*(byte *)(lVar7 + 0xbd) & 0x1f) == 0)
        goto LAB_00103ea8;
      }
      if (*(int *)(lVar7 + 0x168) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_3 + 0xf8),*(int *)(lVar7 + 0x168),
                   *(undefined1 *)(lVar7 + 0x16c),0);
      }
    }
LAB_00103ea8:
    pcVar6 = *(code **)(*(long *)(param_3 + 0x98) + 0x58);
    if (pcVar6 != (code *)0x0) {
      if (*(int *)(pcVar6 + -4) != 0x7065c181) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103ed8);
        (*pcVar6)();
      }
      (*pcVar6)(uVar8,uVar5 & 1,1);
    }
    break;
  case 6:
    *(undefined1 *)(param_3 + 0xf1) = 0;
    break;
  case 8:
    *(undefined1 *)(param_3 + 0xf1) = 1;
    break;
  case 9:
    puVar1 = (ulong *)(param_3 + 0x1a8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if ((uVar4 & 1) != 0) goto LAB_00103df8;
LAB_00103fc0:
    uVar8 = 2;
    goto LAB_00103fc8;
  case 10:
    mutex_lock(hphl_pa_lock);
    puVar1 = (ulong *)(param_3 + 0x198);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffe;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    puVar1 = (ulong *)(param_3 + 0x1a8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffe;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    wcd_enable_curr_micbias(param_3,uVar4 & 1);
    mutex_unlock(hphl_pa_lock);
    puVar1 = (ulong *)(param_3 + 0x1a0);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffe;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    break;
  case 0xb:
    puVar1 = (ulong *)(param_3 + 0x1a8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 2;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if ((uVar4 & 1) == 0) goto LAB_00103fc0;
LAB_00103df8:
    uVar8 = 1;
LAB_00103fc8:
    wcd_enable_curr_micbias(param_3,uVar8);
    break;
  case 0xc:
    mutex_lock(hphr_pa_lock);
    puVar1 = (ulong *)(param_3 + 0x198);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffd;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    puVar1 = (ulong *)(param_3 + 0x1a8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffd;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    wcd_enable_curr_micbias(param_3,uVar4 & 1);
    mutex_unlock(hphr_pa_lock);
    puVar1 = (ulong *)(param_3 + 0x1a0);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffd;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    break;
  case 0xf:
    lVar7 = *(long *)(param_3 + 0x98);
    uVar8 = 0;
    goto LAB_00103e0c;
  case 0x10:
    lVar7 = *(long *)(param_3 + 0x98);
    uVar8 = 1;
LAB_00103e0c:
    if (*(int *)(*(code **)(lVar7 + 0x70) + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x103e34);
      (*pcVar6)();
    }
    (**(code **)(lVar7 + 0x70))
              (*(undefined8 *)(param_3 + 0xf8),*(undefined4 *)(*(long *)(param_3 + 0x358) + 0x14),
               uVar8);
  }
  return 0;
}



//------------------------------------------------------------
// wcd_mbhc_mech_plug_detect_irq @ 0010404c size=272
// signature: undefined wcd_mbhc_mech_plug_detect_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_mbhc_mech_plug_detect_irq(undefined8 param_1,long param_2)

{
  ulong uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  _printk(&DAT_00108389,"wcd_mbhc_mech_plug_detect_irq");
  if (param_2 == 0) {
    _printk(&DAT_00108865,"wcd_mbhc_mech_plug_detect_irq");
    uVar3 = 0;
  }
  else if ((*(int *)(*(long *)(param_2 + 0x90) + 0x58) == 0) || (*(long *)(param_2 + 0x3f8) == 0)) {
    pcVar2 = *(code **)(*(long *)(param_2 + 0x98) + 0x90);
    if (*(int *)(pcVar2 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1040cc);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_2,1);
    if ((uVar1 & 1) == 0) {
      _printk(&DAT_001089f5,"wcd_mbhc_mech_plug_detect_irq");
      uVar3 = 0;
    }
    else {
      wcd_mbhc_swch_irq_handler(param_2);
      pcVar2 = *(code **)(*(long *)(param_2 + 0x98) + 0x90);
      if (*(int *)(pcVar2 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104104);
        (*pcVar2)();
      }
      (*pcVar2)(param_2,0);
      uVar3 = 1;
    }
    _printk(&DAT_00108ce5,"wcd_mbhc_mech_plug_detect_irq",uVar3);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// wcd_mbhc_btn_press_handler @ 00104160 size=460
// signature: undefined wcd_mbhc_btn_press_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 wcd_mbhc_btn_press_handler(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  ulong uVar3;
  code *pcVar4;
  
  complete(param_2 + 0x3b0);
  mutex_lock(param_2 + 0x328);
  uVar3 = cancel_delayed_work_sync(param_2);
  if ((uVar3 & 1) != 0) {
    pcVar4 = *(code **)(*(long *)(param_2 + 0x98) + 0x90);
    if (*(int *)(pcVar4 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1041bc);
      (*pcVar4)();
    }
    (*pcVar4)(param_2,0);
  }
  if ((*(int *)(*(long *)(param_2 + 0x3a8) + 0x1d8) != 0) &&
     (uVar1 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8)),
     (uVar1 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x1dc)) >>
     (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x1dd) & 0x1f) == 0)) {
    *(undefined1 *)(param_2 + 0xc0) = 1;
    uVar1 = jiffies_to_msecs(_jiffies - *(long *)(param_2 + 0x1b0));
    if ((0xf9 < uVar1) && (*(char *)(param_2 + 0xc2) == '\0')) {
      pcVar4 = *(code **)(*(long *)(param_2 + 0x98) + 0x88);
      if (*(int *)(pcVar4 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10423c);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(*(undefined8 *)(param_2 + 0xf8));
      switch(uVar2) {
      case 0:
        uVar1 = 0x4000;
        *(undefined1 *)(param_2 + 0xf0) = 1;
        break;
      case 1:
        uVar1 = 0x2000;
        break;
      case 2:
        uVar1 = 0x1000;
        break;
      case 3:
        uVar1 = 0x800;
        break;
      case 4:
        uVar1 = 0x400;
        break;
      case 5:
        uVar1 = 0x200;
        break;
      default:
        uVar1 = 0;
      }
      if (*(char *)(param_2 + 0xc1) == '\x01') {
        *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) | uVar1;
        pcVar4 = *(code **)(*(long *)(param_2 + 0x98) + 0x90);
        if (*(int *)(pcVar4 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1042e0);
          (*pcVar4)();
        }
        (*pcVar4)(param_2,1);
        uVar3 = queue_delayed_work_on(0x20,_system_wq,param_2,100);
        if ((uVar3 & 1) == 0) {
          __warn_printk("Button pressed twice without release event\n");
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x104310);
          (*pcVar4)();
        }
      }
    }
  }
  mutex_unlock(param_2 + 0x328);
  return 1;
}



//------------------------------------------------------------
// wcd_mbhc_release_handler @ 0010435c size=376
// signature: undefined wcd_mbhc_release_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_mbhc_release_handler(undefined8 param_1,long param_2)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  
  _printk(&DAT_00108389,"wcd_mbhc_release_handler");
  mutex_lock(param_2 + 0x328);
  if (((*(int *)(*(long *)(param_2 + 0x3a8) + 0x1d8) == 0) ||
      (uVar1 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8)),
      (uVar1 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x1dc)) >>
      (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x1dd) & 0x1f) != 0)) ||
     (*(char *)(param_2 + 0xc0) == '\0')) goto LAB_001044a0;
  *(undefined1 *)(param_2 + 0xc0) = 0;
  if ((*(int *)(param_2 + 0x3d4) == 0) && (*(char *)(param_2 + 0xc1) == '\x02')) {
    wcd_mbhc_find_plug_and_report(param_2,1);
    goto LAB_001044a0;
  }
  if ((*(byte *)(param_2 + 0x89) & 0x7e) == 0) goto LAB_001044a0;
  uVar2 = cancel_delayed_work_sync(param_2);
  if ((uVar2 & 1) == 0) {
    _printk(&DAT_00108ddc,"wcd_mbhc_release_handler");
LAB_00104484:
    snd_soc_jack_report(param_2 + 0x278,0,*(undefined4 *)(param_2 + 0x88));
  }
  else {
    pcVar3 = *(code **)(*(long *)(param_2 + 0x98) + 0x90);
    if (*(int *)(pcVar3 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104430);
      (*pcVar3)();
    }
    (*pcVar3)(param_2,0);
    if (*(char *)(param_2 + 0xc2) == '\0') {
      _printk(&DAT_0010906c,"wcd_mbhc_release_handler",*(undefined4 *)(param_2 + 0x88));
      snd_soc_jack_report(param_2 + 0x278,*(undefined4 *)(param_2 + 0x88),
                          *(undefined4 *)(param_2 + 0x88));
      goto LAB_00104484;
    }
  }
  *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) & 0xffff81ff;
LAB_001044a0:
  _printk(&DAT_0010840a,"wcd_mbhc_release_handler");
  mutex_unlock(param_2 + 0x328);
  return 1;
}



//------------------------------------------------------------
// wcd_mbhc_hphl_ocp_irq @ 001044d8 size=328
// signature: undefined wcd_mbhc_hphl_ocp_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_mbhc_hphl_ocp_irq(undefined8 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  long lVar5;
  
  if (param_2 == 0) {
    _printk(&DAT_00108eeb,"wcd_mbhc_hphl_ocp_irq");
  }
  else {
    pcVar4 = *(code **)(*(long *)(param_2 + 0x98) + 0x110);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0x153982ba) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104518);
        (*pcVar4)();
      }
      uVar3 = (*pcVar4)(param_2);
      if ((uVar3 & 1) != 0) {
        if (*(int *)(*(long *)(param_2 + 0x3a8) + 0x288) == 0) {
          return 1;
        }
        uVar2 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8));
        if ((uVar2 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x28c)) >>
            (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x28d) & 0x1f) == 0) {
          return 1;
        }
        *(undefined1 *)(param_2 + 0x3e0) = 1;
        return 1;
      }
    }
    if (*(byte *)(param_2 + 0xa4) < 0x14) {
      *(byte *)(param_2 + 0xa4) = *(byte *)(param_2 + 0xa4) + 1;
      iVar1 = *(int *)(*(long *)(param_2 + 0x3a8) + 0x148);
      if (iVar1 != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_2 + 0xf8),iVar1,
                   *(undefined1 *)(*(long *)(param_2 + 0x3a8) + 0x14c),0);
        lVar5 = *(long *)(param_2 + 0x3a8);
        if (*(int *)(lVar5 + 0x148) != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar5 + 0x148),
                     *(undefined1 *)(lVar5 + 0x14c),1 << (ulong)(*(byte *)(lVar5 + 0x14d) & 0x1f));
        }
      }
    }
    else {
      pcVar4 = *(code **)(*(long *)(param_2 + 0x98) + 0x70);
      if (*(int *)(pcVar4 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1045e0);
        (*pcVar4)();
      }
      (*pcVar4)(*(undefined8 *)(param_2 + 0xf8),*(undefined4 *)(*(long *)(param_2 + 0x358) + 0x14),0
               );
      snd_soc_jack_report(param_2 + 0x1c8,*(undefined4 *)(param_2 + 0xa0),0xf);
    }
  }
  return 1;
}



//------------------------------------------------------------
// wcd_mbhc_hphr_ocp_irq @ 00104624 size=288
// signature: undefined wcd_mbhc_hphr_ocp_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_mbhc_hphr_ocp_irq(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  
  if (param_2 == 0) {
    _printk(&DAT_00108c59,"wcd_mbhc_hphr_ocp_irq");
  }
  else if (*(char *)(param_2 + 0x3e0) == '\0') {
    pcVar3 = *(code **)(*(long *)(param_2 + 0x98) + 0x110);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x153982ba) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104684);
        (*pcVar3)();
      }
      uVar2 = (*pcVar3)(param_2);
      if ((uVar2 & 1) != 0) {
        return 1;
      }
    }
    if (*(byte *)(param_2 + 0xa5) < 0x14) {
      *(byte *)(param_2 + 0xa5) = *(byte *)(param_2 + 0xa5) + 1;
      iVar1 = *(int *)(*(long *)(param_2 + 0x3a8) + 0x148);
      if (iVar1 != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_2 + 0xf8),iVar1,
                   *(undefined1 *)(*(long *)(param_2 + 0x3a8) + 0x14c),0);
        lVar4 = *(long *)(param_2 + 0x3a8);
        if (*(int *)(lVar4 + 0x148) != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar4 + 0x148),
                     *(undefined1 *)(lVar4 + 0x14c),1 << (ulong)(*(byte *)(lVar4 + 0x14d) & 0x1f));
        }
      }
    }
    else {
      pcVar3 = *(code **)(*(long *)(param_2 + 0x98) + 0x70);
      if (*(int *)(pcVar3 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104714);
        (*pcVar3)();
      }
      (*pcVar3)(*(undefined8 *)(param_2 + 0xf8),*(undefined4 *)(*(long *)(param_2 + 0x358) + 0x18),0
               );
      snd_soc_jack_report(param_2 + 0x1c8,*(undefined4 *)(param_2 + 0xa0),0xf);
    }
  }
  else {
    *(undefined1 *)(param_2 + 0x3e0) = 0;
  }
  return 1;
}



//------------------------------------------------------------
// wcd_mbhc_deinit @ 00104748 size=536
// signature: undefined wcd_mbhc_deinit(void)
// callers: []
//------------------------------------------------------------

void wcd_mbhc_deinit(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0xf8);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104790);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,**(undefined4 **)(param_1 + 0x358),param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1047c4);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x358) + 4),param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1047f8);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x358) + 8),param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10482c);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x358) + 0xc),param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104860);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x10),param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104894);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x14),param_1);
  pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x78);
  if (*(int *)(pcVar1 + -4) != -0x510dbef0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1048c8);
    (*pcVar1)();
  }
  (*pcVar1)(uVar2,*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x18),param_1);
  if ((*(long *)(param_1 + 0x98) != 0) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0x98) + 0x60), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0xea46357) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104900);
      (*pcVar1)();
    }
    (*pcVar1)(param_1,param_1 + 0x390,0);
  }
  if (*(long *)(*(long *)(param_1 + 1000) + 0x20) != 0) {
    mutex_lock(param_1 + 0x328);
    pcVar1 = *(code **)(*(long *)(param_1 + 1000) + 0x20);
    if (*(int *)(pcVar1 + -4) != 0x4eb19105) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104944);
      (*pcVar1)();
    }
    (*pcVar1)(param_1,param_1 + 0x360);
    mutex_unlock(param_1 + 0x328);
  }
  return;
}



//------------------------------------------------------------
// wcd_mbhc_swch_irq_handler @ 00104960 size=2564
// signature: undefined wcd_mbhc_swch_irq_handler(void)
// callers: [wcd_mbhc_usbc_ana_event_handler, wcd_mbhc_mech_plug_detect_irq]
//------------------------------------------------------------

void wcd_mbhc_swch_irq_handler(long param_1)

{
  long lVar1;
  ulong *puVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  ulong uVar8;
  code *pcVar9;
  long lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  lVar1 = param_1 + 0x328;
  uVar11 = *(undefined8 *)(param_1 + 0xf8);
  mutex_lock(lVar1);
  *(undefined1 *)(param_1 + 0xc2) = 1;
  uVar8 = cancel_delayed_work_sync(param_1);
  if ((uVar8 & 1) != 0) {
    pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
    if (*(int *)(pcVar9 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1049c8);
      (*pcVar9)();
    }
    (*pcVar9)(param_1,0);
  }
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x28) == 0) {
    bVar6 = true;
  }
  else {
    uVar7 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar10 = *(long *)(param_1 + 0x3a8);
    uVar7 = (uVar7 & *(byte *)(lVar10 + 0x2c)) >> (ulong)(*(byte *)(lVar10 + 0x2d) & 0x1f);
    bVar6 = uVar7 != 0;
    if (*(int *)(lVar10 + 0x28) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x28),
                 *(undefined1 *)(lVar10 + 0x2c),
                 (uint)(uVar7 == 0) << (ulong)(*(byte *)(lVar10 + 0x2d) & 0x1f));
    }
  }
  pcVar9 = *(code **)(*(long *)(param_1 + 1000) + 0x20);
  if (pcVar9 == (code *)0x0) {
    _printk(&DAT_00108f9c,"wcd_mbhc_swch_irq_handler");
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x4eb19105) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104a54);
      (*pcVar9)();
    }
    (*pcVar9)(param_1,param_1 + 0x360);
  }
  lVar10 = *(long *)(param_1 + 0x98);
  pcVar9 = *(code **)(lVar10 + 0xd8);
  if (pcVar9 != (code *)0x0) {
    if (*(int *)(pcVar9 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x104a84);
      (*pcVar9)();
    }
    (*pcVar9)(uVar11,1);
    lVar10 = *(long *)(param_1 + 0x98);
  }
  pcVar9 = *(code **)(lVar10 + 0x98);
  if (pcVar9 == (code *)0x0) {
    uVar7 = 0;
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x65fc7482) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104ab4);
      (*pcVar9)();
    }
    uVar7 = (*pcVar9)(param_1,1);
  }
  bVar5 = false;
  if (*(char *)(param_1 + 0xc1) == '\0') {
    bVar5 = bVar6;
  }
  if (bVar5) {
    if (*(long *)(param_1 + 0x3f8) != 0) {
      lVar10 = *(long *)(param_1 + 0xf8);
      if ((*(long *)(param_1 + 0x98) != 0) &&
         (pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x150), pcVar9 != (code *)0x0)) {
        if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104b14);
          (*pcVar9)();
        }
        (*pcVar9)(param_1,0);
      }
      lVar10 = of_find_property(*(undefined8 *)(*(long *)(*(long *)(lVar10 + 0x20) + 0x40) + 0x2e8),
                                "qcom,usbss-hsj-connect-enabled",0);
      if (lVar10 != 0) {
        wcd_usbss_switch_update(5,1);
      }
    }
    if ((*(char *)(*(long *)(param_1 + 0x90) + 0x48) != '\0') ||
       (*(char *)(*(long *)(param_1 + 0x90) + 0x5c) != '\0')) {
      lVar10 = *(long *)(param_1 + 0x98);
      pcVar9 = *(code **)(lVar10 + 0x130);
      if ((pcVar9 != (code *)0x0) &&
         ((*(long *)(lVar10 + 0x138) != 0 && (*(long *)(lVar10 + 0x140) != 0)))) {
        if (*(int *)(pcVar9 + -4) != -0x153982ba) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104b90);
          (*pcVar9)();
        }
        uVar8 = (*pcVar9)(param_1);
        if ((uVar8 & 1) != 0) {
          lVar10 = *(long *)(param_1 + 0x3a8);
          if (*(int *)(lVar10 + 8) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 8),
                       *(undefined1 *)(lVar10 + 0xc),0);
            lVar10 = *(long *)(param_1 + 0x3a8);
          }
          if (*(int *)(lVar10 + 0x18) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x18),
                       *(undefined1 *)(lVar10 + 0x1c),0);
          }
          pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x138);
          if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104bfc);
            (*pcVar9)();
          }
          (*pcVar9)(param_1,1);
          lVar10 = *(long *)(param_1 + 0x3a8);
          if (*(int *)(lVar10 + 0x28) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x28),
                       *(undefined1 *)(lVar10 + 0x2c),1 << (ulong)(*(byte *)(lVar10 + 0x2d) & 0x1f))
            ;
            lVar10 = *(long *)(param_1 + 0x3a8);
          }
          if (*(int *)(lVar10 + 8) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 8),
                       *(undefined1 *)(lVar10 + 0xc),1 << (ulong)(*(byte *)(lVar10 + 0xd) & 0x1f));
          }
          if (*(char *)(*(long *)(param_1 + 0x90) + 0x21) != '\0') {
            lVar10 = *(long *)(param_1 + 0x3a8);
            if (*(int *)(lVar10 + 0x18) != 0) {
              snd_soc_component_update_bits
                        (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x18),
                         *(undefined1 *)(lVar10 + 0x1c),
                         1 << (ulong)(*(byte *)(lVar10 + 0x1d) & 0x1f));
            }
          }
          goto LAB_001052d8;
        }
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x138);
        if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104edc);
          (*pcVar9)();
        }
        (*pcVar9)(param_1,0);
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x140);
        if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104f08);
          (*pcVar9)();
        }
        (*pcVar9)(param_1,0);
      }
    }
    pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0xa0);
    if (*(int *)(pcVar9 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104f34);
      (*pcVar9)();
    }
    (*pcVar9)(uVar11,1);
    pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0xa8);
    if (pcVar9 != (code *)0x0) {
      if (*(int *)(pcVar9 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104f68);
        (*pcVar9)();
      }
      (*pcVar9)(uVar11,2,1);
    }
    if ((*(char *)(*(long *)(param_1 + 0x90) + 0x20) == '\0') &&
       (pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0xb0), pcVar9 != (code *)0x0)) {
      if (*(int *)(pcVar9 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104fa8);
        (*pcVar9)();
      }
      (*pcVar9)(uVar11,1,1);
    }
    iVar3 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x1e8);
    if (iVar3 != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),iVar3,
                 *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0x1ec),0);
    }
    lVar10 = *(long *)(param_1 + 0x98);
    pcVar9 = *(code **)(lVar10 + 0x30);
    if (pcVar9 != (code *)0x0) {
      if (*(int *)(pcVar9 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x104ff0);
        (*pcVar9)();
      }
      (*pcVar9)(uVar11);
      lVar10 = *(long *)(param_1 + 0x98);
    }
    pcVar9 = *(code **)(lVar10 + 0x28);
    if (pcVar9 != (code *)0x0) {
      if (*(int *)(pcVar9 + -4) != -0x1a0d9049) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x105020);
        (*pcVar9)();
      }
      (*pcVar9)(param_1,1);
    }
    *(undefined1 *)(param_1 + 0xf0) = 0;
    *(undefined1 *)(param_1 + 0xc0) = 0;
    if (*(long *)(param_1 + 1000) != 0) {
      pcVar9 = *(code **)(*(long *)(param_1 + 1000) + 0x10);
      if (*(int *)(pcVar9 + -4) != 0x5c9283de) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x105054);
        (*pcVar9)();
      }
      (*pcVar9)(param_1);
    }
  }
  else {
    bVar5 = bVar6;
    if (*(char *)(param_1 + 0xc1) == '\0') {
      bVar5 = true;
    }
    if (bVar5) {
      if (!bVar6) {
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x28);
        if (pcVar9 != (code *)0x0) {
          if (*(int *)(pcVar9 + -4) != -0x1a0d9049) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104cb4);
            (*pcVar9)();
          }
          (*pcVar9)(param_1,0);
        }
        lVar10 = *(long *)(param_1 + 0x3a8);
        if (*(int *)(lVar10 + 0xb8) != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0xb8),
                     *(undefined1 *)(lVar10 + 0xbc),0);
          lVar10 = *(long *)(param_1 + 0x3a8);
        }
        if (*(int *)(lVar10 + 0x168) != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x168),
                     *(undefined1 *)(lVar10 + 0x16c),0);
        }
        *(undefined1 *)(param_1 + 0xf5) = 0;
      }
    }
    else {
      pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x28);
      if (pcVar9 != (code *)0x0) {
        if (*(int *)(pcVar9 + -4) != -0x1a0d9049) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104d24);
          (*pcVar9)();
        }
        (*pcVar9)(param_1,0);
      }
      lVar10 = *(long *)(param_1 + 0x3a8);
      if (*(int *)(lVar10 + 0xb8) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0xb8),
                   *(undefined1 *)(lVar10 + 0xbc),0);
        lVar10 = *(long *)(param_1 + 0x3a8);
      }
      if (*(int *)(lVar10 + 0x168) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x168),
                   *(undefined1 *)(lVar10 + 0x16c),0);
      }
      lVar10 = *(long *)(param_1 + 0x98);
      pcVar9 = *(code **)(lVar10 + 0xa8);
      if (pcVar9 != (code *)0x0) {
        if (*(int *)(pcVar9 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x104d90);
          (*pcVar9)();
        }
        (*pcVar9)(uVar11,2,0);
        lVar10 = *(long *)(param_1 + 0x98);
      }
      pcVar9 = *(code **)(lVar10 + 0x58);
      if (pcVar9 != (code *)0x0) {
        if (*(int *)(pcVar9 + -4) != 0x7065c181) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104dc4);
          (*pcVar9)();
        }
        (*pcVar9)(uVar11,uVar7 & 1,0);
      }
      *(undefined1 *)(param_1 + 0xf0) = 0;
      *(undefined1 *)(param_1 + 0xc0) = 0;
      uVar12 = 1;
      uVar13 = 0x15;
      switch(*(undefined1 *)(param_1 + 0xc1)) {
      case 1:
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0xb0);
        if (pcVar9 != (code *)0x0) {
          if (*(int *)(pcVar9 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104e30);
            (*pcVar9)();
          }
          (*pcVar9)(uVar11,1,0);
        }
        lVar10 = *(long *)(param_1 + 0x3a8);
        if (*(int *)(lVar10 + 0x1e8) != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x1e8),
                     *(undefined1 *)(lVar10 + 0x1ec),1 << (ulong)(*(byte *)(lVar10 + 0x1ed) & 0x1f))
          ;
        }
        uVar12 = 3;
        uVar13 = 0x14;
        break;
      case 2:
        break;
      case 3:
        if (*(int *)(param_1 + 0x3d4) == 1) {
          iVar3 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x308);
          if (iVar3 != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_1 + 0xf8),iVar3,
                       *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0x30c),0);
          }
        }
        uVar12 = 4;
        uVar13 = 0x17;
        *(undefined1 *)(param_1 + 0xf2) = 0;
        break;
      default:
        _printk(&DAT_0010892b,"wcd_mbhc_swch_irq_handler");
      case 4:
        uVar12 = 1;
        uVar13 = 0x3e;
      }
      uVar8 = mutex_is_locked(lVar1);
      if (((uVar8 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
        wcd_mbhc_hs_elec_irq___already_done = 1;
        __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x800,0x10531c);
        (*pcVar9)();
      }
      if (((uint)*(undefined8 *)(param_1 + 0x3d8) >> 1 & 1) != 0) {
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
        if (*(int *)(pcVar9 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1050c8);
          (*pcVar9)();
        }
        (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0x10)
                  ,0);
        puVar2 = (ulong *)(param_1 + 0x3d8);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar6) {
            *puVar2 = *puVar2 & 0xfffffffffffffffd;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
      uVar8 = mutex_is_locked(lVar1);
      if (((uVar8 & 1) == 0) && ((wcd_mbhc_hs_elec_irq___already_done & 1) == 0)) {
        wcd_mbhc_hs_elec_irq___already_done = 1;
        __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_hs_elec_irq");
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x800,0x105340);
        (*pcVar9)();
      }
      if ((*(ulong *)(param_1 + 0x3d8) & 1) != 0) {
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x70);
        if (*(int *)(pcVar9 + -4) != -0x58f48f42) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x105128);
          (*pcVar9)();
        }
        (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x358) + 0xc),
                  0);
        puVar2 = (ulong *)(param_1 + 0x3d8);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar6) {
            *puVar2 = *puVar2 & 0xfffffffffffffffe;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
      lVar10 = *(long *)(param_1 + 0x3a8);
      if (*(int *)(lVar10 + 0x48) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0x48),
                   *(undefined1 *)(lVar10 + 0x4c),1 << (ulong)(*(byte *)(lVar10 + 0x4d) & 0x1f));
        lVar10 = *(long *)(param_1 + 0x3a8);
      }
      if (*(int *)(lVar10 + 0xa8) != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar10 + 0xa8),
                   *(undefined1 *)(lVar10 + 0xac),0);
      }
      *(undefined1 *)(param_1 + 0xf5) = 0;
      wcd_mbhc_report_plug(param_1,0,uVar12);
      extcon_set_state_sync(*(undefined8 *)(param_1 + 0x420),uVar13,0);
      if (*(int *)(*(long *)(param_1 + 0x90) + 0x58) != 0) {
        iVar3 = *(int *)(*(long *)(param_1 + 0x3a8) + 8);
        if (iVar3 != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_1 + 0xf8),iVar3,
                     *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0xc),0);
        }
        pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x80);
        if (pcVar9 != (code *)0x0) {
          if (*(int *)(pcVar9 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1051f4);
            (*pcVar9)();
          }
          (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),0);
        }
      }
      if ((*(char *)(*(long *)(param_1 + 0x90) + 0x48) != '\0') ||
         (*(char *)(*(long *)(param_1 + 0x90) + 0x5c) != '\0')) {
        lVar10 = *(long *)(param_1 + 0x98);
        pcVar9 = *(code **)(lVar10 + 0x138);
        if (pcVar9 != (code *)0x0) {
          if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x105238);
            (*pcVar9)();
          }
          (*pcVar9)(param_1,0);
          lVar10 = *(long *)(param_1 + 0x98);
        }
        pcVar9 = *(code **)(lVar10 + 0x140);
        if (pcVar9 != (code *)0x0) {
          if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x105268);
            (*pcVar9)();
          }
          (*pcVar9)(param_1,0);
        }
      }
      if (*(long *)(param_1 + 0x3f8) != 0) {
        lVar10 = of_find_property(*(undefined8 *)
                                   (*(long *)(*(long *)(*(long *)(param_1 + 0xf8) + 0x20) + 0x40) +
                                   0x2e8),"qcom,usbss-hsj-connect-enabled",0);
        if (lVar10 != 0) {
          wcd_usbss_switch_update(5,0);
        }
        if ((*(long *)(param_1 + 0x98) != 0) &&
           (pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0x150), pcVar9 != (code *)0x0)) {
          if (*(int *)(pcVar9 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1052d4);
            (*pcVar9)();
          }
          (*pcVar9)(param_1,1);
        }
      }
    }
  }
LAB_001052d8:
  *(undefined1 *)(param_1 + 0xc2) = 0;
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// wcd_mbhc_adc_init @ 00105388 size=96
// signature: undefined wcd_mbhc_adc_init(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

void wcd_mbhc_adc_init(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_0010908c,"wcd_mbhc_adc_init");
  }
  else {
    *(undefined ***)(param_1 + 1000) = &mbhc_fn;
    *(undefined8 *)(param_1 + 0x360) = 0xfffffffe0;
    *(long *)(param_1 + 0x368) = param_1 + 0x368;
    *(long *)(param_1 + 0x370) = param_1 + 0x368;
    *(code **)(param_1 + 0x378) = wcd_correct_swch_plug;
  }
  return;
}



//------------------------------------------------------------
// wcd_correct_swch_plug @ 001053ec size=5288
// signature: undefined wcd_correct_swch_plug(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wcd_correct_swch_plug(long param_1)

{
  char *pcVar1;
  uint uVar2;
  undefined1 uVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 uVar14;
  bool bVar15;
  code *pcVar16;
  byte *pbVar17;
  long lVar18;
  uint uVar19;
  undefined8 uVar20;
  uint *puVar21;
  long *plVar22;
  uint *puVar23;
  char *pcVar24;
  long lVar25;
  long lVar26;
  uint *puVar27;
  undefined8 *puVar28;
  char *pcVar29;
  bool bVar30;
  uint uVar31;
  long *plVar32;
  ulong uVar33;
  uint local_bc;
  uint local_b8;
  uint local_6c;
  long local_68;
  
  lVar25 = sp_el0;
  local_68 = *(long *)(lVar25 + 0x638);
  _printk(&DAT_00108389,"wcd_correct_swch_plug");
  plVar32 = (long *)(param_1 + -0x2c8);
  puVar28 = (undefined8 *)(param_1 + -0x268);
  lVar25 = param_1 + -0x360;
  local_6c = 0;
  uVar20 = *puVar28;
  pcVar16 = *(code **)(*plVar32 + 0x18);
  if (pcVar16 == (code *)0x0) {
    if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
      uVar12 = 0x319c;
    }
    else {
      uVar12 = snd_soc_component_read(uVar20);
      uVar12 = ((uVar12 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
               (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
    }
  }
  else {
    if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105494);
      (*pcVar16)();
    }
    (*pcVar16)(lVar25,&local_6c);
    uVar12 = local_6c;
  }
  local_6c = 0;
  pcVar16 = *(code **)(*plVar32 + 0x18);
  if (pcVar16 == (code *)0x0) {
    if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
      uVar10 = 0x319c;
    }
    else {
      uVar10 = snd_soc_component_read(*puVar28);
      uVar10 = ((uVar10 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
               (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
    }
  }
  else {
    if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105510);
      (*pcVar16)();
    }
    (*pcVar16)(lVar25,&local_6c);
    uVar10 = local_6c;
  }
  puVar21 = (uint *)(param_1 + -0x298);
  uVar31 = *puVar21;
  if (uVar31 == 0) {
    uVar31 = (int)(uVar10 * 0x6a4) / 0x708;
  }
  else {
    uVar8 = *(uint *)(param_1 + -0x290);
    if (uVar8 != uVar10) {
      uVar10 = uVar31 * uVar10;
      uVar31 = 0;
      if (uVar8 != 0) {
        uVar31 = uVar10 / uVar8;
      }
    }
  }
  lVar26 = param_1 + -0x38;
  mutex_lock(lVar26);
  wcd_mbhc_hs_elec_irq(lVar25,0,0);
  mutex_unlock(lVar26);
  uVar10 = 0;
  puVar27 = (uint *)(param_1 + -0x28c);
  do {
    iVar6 = wcd_check_cross_conn(lVar25);
    uVar10 = uVar10 + 1;
  } while (uVar10 < *puVar27);
  if (iVar6 < 1) {
    lVar18 = *(long *)(param_1 + 0x48);
    if (*(int *)(lVar18 + 0xa8) == 0) {
      iVar6 = *(int *)(lVar18 + 0x2e8);
      if (iVar6 == 0) goto LAB_00105608;
LAB_00105658:
      snd_soc_component_update_bits
                (*puVar28,iVar6,*(undefined1 *)(lVar18 + 0x2ec),
                 1 << (ulong)(*(byte *)(lVar18 + 0x2ed) & 0x1f));
      lVar18 = *(long *)(param_1 + 0x48);
      if (*(int *)(lVar18 + 0x298) != 0) goto LAB_0010567c;
LAB_00105610:
      uVar10 = 0xea;
      iVar6 = *(int *)(lVar18 + 0xb8);
joined_r0x001056a4:
      if (iVar6 == 0) goto LAB_001056a8;
LAB_0010561c:
      snd_soc_component_update_bits(*puVar28,iVar6,*(undefined1 *)(lVar18 + 0xbc),0);
      lVar18 = *(long *)(param_1 + 0x48);
      iVar6 = *(int *)(lVar18 + 0x218);
    }
    else {
      snd_soc_component_update_bits
                (*puVar28,*(int *)(lVar18 + 0xa8),*(undefined1 *)(lVar18 + 0xac),0);
      lVar18 = *(long *)(param_1 + 0x48);
      iVar6 = *(int *)(lVar18 + 0x2e8);
      if (iVar6 != 0) goto LAB_00105658;
LAB_00105608:
      if (*(int *)(lVar18 + 0x298) == 0) goto LAB_00105610;
LAB_0010567c:
      uVar10 = snd_soc_component_read(*puVar28);
      lVar18 = *(long *)(param_1 + 0x48);
      uVar10 = (uVar10 & *(byte *)(lVar18 + 0x29c)) >> (ulong)(*(byte *)(lVar18 + 0x29d) & 0x1f);
      if (*(int *)(lVar18 + 0x298) == 0) {
        iVar6 = *(int *)(lVar18 + 0xb8);
        goto joined_r0x001056a4;
      }
      snd_soc_component_update_bits(*puVar28,*(int *)(lVar18 + 0x298),*(byte *)(lVar18 + 0x29c),0);
      lVar18 = *(long *)(param_1 + 0x48);
      iVar6 = *(int *)(lVar18 + 0xb8);
      if (iVar6 != 0) goto LAB_0010561c;
LAB_001056a8:
      iVar6 = *(int *)(lVar18 + 0x218);
    }
    if (iVar6 != 0) {
      snd_soc_component_update_bits
                (*puVar28,iVar6,*(undefined1 *)(lVar18 + 0x21c),
                 1 << (ulong)(*(byte *)(lVar18 + 0x21d) & 0x1f));
    }
    pcVar16 = *(code **)(*plVar32 + 0x10);
    if (pcVar16 != (code *)0x0) {
      if (*(int *)(pcVar16 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1056f4);
        (*pcVar16)();
      }
      (*pcVar16)(lVar25,1);
    }
    lVar18 = *(long *)(param_1 + 0x48);
    if (*(int *)(lVar18 + 0xb8) != 0) {
      snd_soc_component_update_bits
                (*puVar28,*(int *)(lVar18 + 0xb8),*(undefined1 *)(lVar18 + 0xbc),
                 1 << (ulong)(*(byte *)(lVar18 + 0xbd) & 0x1f));
    }
    pcVar16 = *(code **)(*plVar32 + 0x10);
    if (pcVar16 != (code *)0x0) {
      if (*(int *)(pcVar16 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105748);
        (*pcVar16)();
      }
      (*pcVar16)(lVar25,0);
    }
    lVar18 = *(long *)(param_1 + 0x48);
    if (*(int *)(lVar18 + 0x298) != 0) {
      snd_soc_component_update_bits
                (*puVar28,*(int *)(lVar18 + 0x298),*(undefined1 *)(lVar18 + 0x29c),
                 1 << (ulong)(*(byte *)(lVar18 + 0x29d) & 0x1f));
    }
    usleep_range_state(3000,0xc1c,2);
    if (*(int *)(*(long *)(param_1 + 0x48) + 0x2c8) != 0) {
      snd_soc_component_read(*puVar28);
    }
    usleep_range_state(3000,0xc1c,2);
    if (*(int *)(*(long *)(param_1 + 0x48) + 0x2c8) != 0) {
      snd_soc_component_read(*puVar28);
    }
    usleep_range_state(3000,0xc1c,2);
    lVar18 = *(long *)(param_1 + 0x48);
    if (*(int *)(lVar18 + 0x2c8) == 0) {
      iVar11 = 0x7242;
      iVar6 = *(int *)(lVar18 + 0x298);
    }
    else {
      uVar8 = snd_soc_component_read(*puVar28);
      lVar18 = *(long *)(param_1 + 0x48);
      iVar11 = ((uVar8 & *(byte *)(lVar18 + 0x2cc)) >> (ulong)(*(byte *)(lVar18 + 0x2cd) & 0x1f)) *
               0x7d;
      iVar6 = *(int *)(lVar18 + 0x298);
    }
    if (iVar6 != 0) {
      snd_soc_component_update_bits
                (*puVar28,iVar6,*(undefined1 *)(lVar18 + 0x29c),
                 uVar10 << (ulong)(*(byte *)(lVar18 + 0x29d) & 0x1f));
    }
    local_6c = 0;
    pcVar16 = *(code **)(*plVar32 + 0x18);
    if (pcVar16 == (code *)0x0) {
      if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
        uVar10 = 0x319c;
      }
      else {
        uVar10 = snd_soc_component_read(*puVar28);
        uVar10 = ((uVar10 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
                 (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
      }
    }
    else {
      if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10586c);
        (*pcVar16)();
      }
      (*pcVar16)(lVar25,&local_6c);
      uVar10 = local_6c;
    }
    iVar11 = (int)(uVar10 * iVar11) / 18000;
    iVar6 = wcd_mbhc_get_plug_from_adc(lVar25,iVar11);
    _printk(&DAT_00108f2c,"wcd_correct_swch_plug",iVar6,iVar11);
    if ((iVar6 != 3) && (uVar33 = wcd_swch_level_remove(lVar25), (uVar33 & 1) == 0)) {
      mutex_lock(lVar26);
      wcd_mbhc_find_plug_and_report(lVar25,iVar6);
      mutex_unlock(lVar26);
    }
    if ((*(byte *)(param_1 + -0x29f) | 4) == 5) {
      lVar18 = *(long *)(param_1 + 0x48);
      if (*(int *)(lVar18 + 0x2e8) == 0) {
        iVar11 = *(int *)(lVar18 + 0x298);
        if (iVar11 == 0) goto LAB_0010596c;
LAB_001060c8:
        snd_soc_component_update_bits(*puVar28,iVar11,*(undefined1 *)(lVar18 + 0x29c),0);
        lVar18 = *(long *)(param_1 + 0x48);
        iVar11 = *(int *)(lVar18 + 0x2f8);
      }
      else {
        snd_soc_component_update_bits
                  (*puVar28,*(int *)(lVar18 + 0x2e8),*(undefined1 *)(lVar18 + 0x2ec),0);
        lVar18 = *(long *)(param_1 + 0x48);
        iVar11 = *(int *)(lVar18 + 0x298);
        if (iVar11 != 0) goto LAB_001060c8;
LAB_0010596c:
        iVar11 = *(int *)(lVar18 + 0x2f8);
      }
      if (iVar11 != 0) {
        snd_soc_component_update_bits
                  (*puVar28,iVar11,*(undefined1 *)(lVar18 + 0x2fc),
                   1 << (ulong)(*(byte *)(lVar18 + 0x2fd) & 0x1f));
      }
    }
  }
  else {
    iVar6 = 4;
  }
  pcVar16 = *(code **)(*plVar32 + 0x20);
  if (pcVar16 != (code *)0x0) {
    if (*(int *)(pcVar16 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1059bc);
      (*pcVar16)();
    }
    (*pcVar16)(lVar25,0);
  }
  bVar15 = false;
  local_b8 = 0;
  iVar11 = 0;
  uVar33 = 0;
  lVar18 = _jiffies + 0x2ee;
  plVar22 = (long *)(param_1 + -0x2d0);
  pcVar29 = (char *)(param_1 + -0x272);
  pbVar17 = (byte *)(param_1 + -0x29f);
  puVar23 = (uint *)(param_1 + -0x290);
  pcVar24 = (char *)(param_1 + -0x271);
  uVar10 = 0;
  bVar4 = false;
LAB_00105a30:
  do {
    bVar30 = bVar4;
    local_bc = uVar10;
    if (lVar18 - _jiffies < 0) {
      if (!bVar30 && iVar6 == 1) {
        iVar6 = 1;
        _printk(&DAT_0010880b,"wcd_correct_swch_plug",1,*pbVar17);
        if (*pbVar17 != 1) {
          bVar30 = false;
          goto LAB_001063f4;
        }
        lVar18 = *(long *)(param_1 + 0x48);
        if (*(int *)(lVar18 + 0x2e8) != 0) {
          snd_soc_component_update_bits
                    (*puVar28,*(int *)(lVar18 + 0x2e8),*(undefined1 *)(lVar18 + 0x2ec),0);
          lVar18 = *(long *)(param_1 + 0x48);
        }
        if (*(int *)(lVar18 + 0x298) != 0) {
          snd_soc_component_update_bits
                    (*puVar28,*(int *)(lVar18 + 0x298),*(undefined1 *)(lVar18 + 0x29c),0);
        }
        goto LAB_0010649c;
      }
      if (iVar6 != 3) goto LAB_001063f4;
      lVar18 = *plVar32;
      pcVar16 = *(code **)(lVar18 + 0xf0);
      if (*(long *)(lVar18 + 0xd0) == 0) {
        if (pcVar16 != (code *)0x0) goto LAB_0010620c;
      }
      else {
        if (pcVar16 == (code *)0x0) goto LAB_001063a8;
LAB_0010620c:
        if (*(int *)(pcVar16 + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
          pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x106230);
          (*pcVar16)();
        }
        iVar6 = (*pcVar16)(*puVar28,2,1);
        if (iVar6 != 0) {
          _printk(&DAT_00108b63,"wcd_is_special_headset",1);
          goto LAB_001063a8;
        }
        lVar18 = *plVar32;
      }
      pcVar16 = *(code **)(lVar18 + 0x18);
      local_6c = 0;
      if (pcVar16 == (code *)0x0) {
        if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
          uVar12 = 0x319c;
        }
        else {
          uVar12 = snd_soc_component_read(*puVar28);
          uVar12 = ((uVar12 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
                   (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
        }
      }
      else {
        if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
          pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x106298);
          (*pcVar16)();
        }
        (*pcVar16)(lVar25,&local_6c);
        uVar12 = local_6c;
      }
      uVar10 = *puVar21;
      if ((uVar10 == 0) || (uVar31 = *puVar23, uVar31 == 0x708)) {
        uVar10 = (int)(uVar12 * 0x6a4) / 0x708;
      }
      else if (uVar31 != uVar12) {
        uVar12 = uVar10 * uVar12;
        uVar10 = 0;
        if (uVar31 != 0) {
          uVar10 = uVar12 / uVar31;
        }
      }
      bVar15 = false;
      iVar6 = 2000;
      goto LAB_00106314;
    }
    if (*pcVar29 != '\0') {
      if (*pcVar24 != '\0') {
        if (*(int *)(*(code **)(*plVar32 + 0xf0) + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
          pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x106184);
          (*pcVar16)();
        }
        (**(code **)(*plVar32 + 0xf0))(*puVar28,2,0);
        lVar18 = *plVar32;
LAB_001061c8:
        pcVar16 = *(code **)(lVar18 + 0x40);
        if (pcVar16 != (code *)0x0) {
          if (*(int *)(pcVar16 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
            pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1061f0);
            (*pcVar16)();
          }
          (*pcVar16)(*puVar28);
        }
        *pcVar24 = '\0';
      }
      goto LAB_001065dc;
    }
    msleep(0x14);
    if (*pcVar29 != '\0') {
      if (*pcVar24 != '\0') {
        if (*(int *)(*(code **)(*plVar32 + 0xf0) + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
          pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1061bc);
          (*pcVar16)();
        }
        (**(code **)(*plVar32 + 0xf0))(*puVar28,2,0);
        lVar18 = *plVar32;
        goto LAB_001061c8;
      }
      goto LAB_001065dc;
    }
    msleep(0xb4);
    iVar7 = wcd_measure_adc_once(lVar25,1);
    iVar6 = wcd_mbhc_get_plug_from_adc(lVar25,iVar7);
    if (((int)uVar31 < iVar7) && (iVar11 < 1)) {
      pcVar16 = *(code **)(*plVar32 + 0xf0);
      if (pcVar16 == (code *)0x0) {
LAB_00105d00:
        iVar7 = wcd_measure_adc_once(lVar25,1);
      }
      else {
        if (*(int *)(pcVar16 + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
          pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105acc);
          (*pcVar16)();
        }
        (*pcVar16)(*puVar28,*(undefined4 *)(*plVar22 + 0x4c),1);
        usleep_range_state(10000,0x2774,2);
        iVar7 = wcd_measure_adc_once(lVar25,1);
        local_6c = 0;
        pcVar16 = *(code **)(*plVar32 + 0x18);
        if (pcVar16 == (code *)0x0) {
          if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
            local_6c = 0x319c;
          }
          else {
            uVar10 = snd_soc_component_read(*puVar28);
            local_6c = ((uVar10 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
                       (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
          }
        }
        else {
          if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
            pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105b20);
            (*pcVar16)();
          }
          (*pcVar16)(lVar25,&local_6c);
        }
        uVar10 = *puVar21;
        if ((uVar10 == 0) || (uVar8 = *puVar23, uVar8 == 0x708)) {
          uVar10 = (int)(local_6c * 0x6a4) / 0x708;
        }
        else if (uVar8 != local_6c) {
          local_6c = uVar10 * local_6c;
          uVar10 = 0;
          if (uVar8 != 0) {
            uVar10 = local_6c / uVar8;
          }
        }
        local_6c = 0;
        pcVar16 = *(code **)(*plVar32 + 0x18);
        if (pcVar16 == (code *)0x0) {
          if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
            uVar8 = 0x319c;
          }
          else {
            uVar8 = snd_soc_component_read(*puVar28);
            uVar8 = ((uVar8 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
                    (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
          }
        }
        else {
          if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
            pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105bdc);
            (*pcVar16)();
          }
          (*pcVar16)(lVar25,&local_6c);
          uVar8 = local_6c;
        }
        uVar19 = *(uint *)(param_1 + -0x294);
        if (uVar19 == 0) {
          uVar19 = (int)(uVar8 * 0x4b) / 0x708;
        }
        else {
          uVar2 = *puVar23;
          if (uVar2 != uVar8) {
            uVar8 = uVar19 * uVar8;
            uVar19 = 0;
            if (uVar2 != 0) {
              uVar19 = uVar8 / uVar2;
            }
          }
        }
        if ((int)uVar10 < iVar7 || iVar7 < (int)uVar19) {
LAB_00105cb4:
          if (*(int *)(*(code **)(*plVar32 + 0xf0) + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
            pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105ce8);
            (*pcVar16)();
          }
          (**(code **)(*plVar32 + 0xf0))(*puVar28,*(undefined4 *)(*plVar22 + 0x4c),0);
          usleep_range_state(10000,0x2774,2);
          if ((int)uVar10 < iVar7 || iVar7 < (int)uVar19) goto LAB_00105d00;
        }
        else {
          if (iVar11 != 0) {
            iVar11 = iVar11 + 1;
            goto LAB_00105cb4;
          }
          iVar11 = 1;
        }
        _printk(&DAT_00108e07,"wcd_correct_swch_plug",1);
        iVar7 = wcd_measure_adc_once(lVar25,1);
        if (iVar11 == 1) {
          local_6c = 0;
          pcVar16 = *(code **)(*plVar32 + 0x18);
          if (pcVar16 == (code *)0x0) {
            if (*(int *)(*(long *)(param_1 + 0x48) + 0x2d8) == 0) {
              uVar10 = 0x319c;
            }
            else {
              uVar10 = snd_soc_component_read(*puVar28);
              uVar10 = ((uVar10 & *(byte *)(*(long *)(param_1 + 0x48) + 0x2dc)) >>
                       (ulong)(*(byte *)(*(long *)(param_1 + 0x48) + 0x2dd) & 0x1f)) * 0x32 + 1000;
            }
          }
          else {
            if (*(int *)(pcVar16 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
              pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105dcc);
              (*pcVar16)();
            }
            (*pcVar16)(lVar25,&local_6c);
            uVar10 = local_6c;
          }
          iVar9 = uVar10 * uVar31;
          iVar11 = 1;
          uVar31 = 0;
          if (uVar12 != 0) {
            uVar31 = iVar9 / (int)uVar12;
          }
          *pcVar24 = '\x01';
        }
      }
    }
    pcVar16 = *(code **)(*plVar32 + 0xb8);
    if (pcVar16 != (code *)0x0) {
      if (*(int *)(pcVar16 + -4) != -0x7ea8dd3) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105d3c);
        (*pcVar16)();
      }
      uVar33 = (*pcVar16)(*puVar28);
      uVar33 = uVar33 & 0xffffffff;
    }
    uVar10 = local_bc;
    bVar4 = bVar30;
    if (((int)uVar31 < iVar7) || ((uVar33 & 1) != 0)) {
      if ((int)uVar31 < iVar7) {
        _printk(&DAT_00108a5a,"wcd_correct_swch_plug");
        iVar6 = 3;
        bVar4 = true;
        goto LAB_00105a30;
      }
    }
    else {
      iVar9 = wcd_check_cross_conn(lVar25);
      uVar33 = 0;
      if (iVar9 < 0) goto LAB_00105a30;
      if (iVar9 == 0) {
        local_b8 = local_b8 + 1;
        iVar6 = wcd_mbhc_get_plug_from_adc(lVar25,iVar7);
        uVar8 = *puVar27;
        if (local_b8 < uVar8) {
          uVar33 = 0;
          local_bc = 0;
          uVar10 = 0;
          if (iVar11 != 1) goto LAB_00105a30;
        }
        else {
          local_bc = 0;
        }
      }
      else {
        uVar33 = 0;
        uVar8 = *puVar27;
        local_b8 = 0;
        local_bc = local_bc + 1;
        uVar10 = local_bc;
        if (local_bc < uVar8) goto LAB_00105a30;
        if (uVar8 < local_bc) {
          _printk(&DAT_00108a3f,"wcd_correct_swch_plug");
          iVar6 = 4;
          goto LAB_001063f4;
        }
        iVar6 = 4;
      }
      if ((local_bc == uVar8) && (iVar6 == 4)) {
        pcVar16 = *(code **)(*plVar22 + 0x18);
        if (pcVar16 != (code *)0x0) {
          if (*(int *)(pcVar16 + -4) != -0x201c1056) {
                    /* WARNING: Does not return */
            pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x105efc);
            (*pcVar16)();
          }
          uVar13 = (*pcVar16)(uVar20,1);
          uVar33 = 0;
          iVar6 = 4;
          local_b8 = 0;
          uVar10 = uVar8;
          if ((uVar13 & 1) != 0) goto LAB_00105a30;
        }
        iVar6 = 4;
        _printk(&DAT_00108478,"wcd_correct_swch_plug",4);
        uVar33 = 0;
        local_b8 = 0;
        uVar10 = local_bc;
        bVar4 = false;
        goto LAB_00105a30;
      }
      uVar33 = 0;
      local_b8 = 0;
    }
    _printk(&DAT_00108478,"wcd_correct_swch_plug",iVar6);
    bVar5 = iVar6 == 4;
    iVar6 = 4;
    uVar10 = local_bc;
    bVar4 = false;
    if (bVar5) goto LAB_00105a30;
    iVar6 = wcd_mbhc_get_plug_from_adc(lVar25,iVar7);
    if (!bVar15 && iVar11 == 1) {
      mutex_lock(lVar26);
      wcd_mbhc_find_plug_and_report(lVar25,iVar6);
      mutex_unlock(lVar26);
      iVar11 = 1;
LAB_0010602c:
      bVar15 = true;
      bVar4 = bVar30;
      goto LAB_00105a30;
    }
    if (bVar15) goto LAB_0010602c;
    bVar4 = false;
    if ((*pbVar17 | 4) == 5) goto LAB_00105a30;
    uVar13 = wcd_swch_level_remove(lVar25);
    bVar4 = false;
  } while ((uVar13 & 1) != 0);
  pcVar1 = "special ";
  if (iVar11 != 1) {
    pcVar1 = "";
  }
  _printk(&DAT_00108b9d,"wcd_correct_swch_plug",pcVar1);
  goto LAB_001063f4;
  while( true ) {
    if (*pcVar29 != '\0') goto LAB_00106360;
    msleep(0x32);
    iVar11 = wcd_measure_adc_once(lVar25,1);
    bVar15 = iVar11 <= (int)uVar10;
    iVar6 = iVar6 + -0x32;
    if (iVar6 == 0) break;
LAB_00106314:
    if (bVar15) goto LAB_00106350;
  }
  if ((int)uVar10 < iVar11) {
LAB_00106360:
    bVar15 = false;
  }
  else {
LAB_00106350:
    bVar15 = true;
    *pcVar24 = '\x01';
  }
  pcVar16 = *(code **)(*plVar32 + 0xf0);
  if ((pcVar16 != (code *)0x0) && (*pcVar24 == '\0')) {
    if (*(int *)(pcVar16 + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1063a0);
      (*pcVar16)();
    }
    (*pcVar16)(*puVar28,2,0);
  }
  if (bVar15) {
    _printk(&DAT_0010857f,"wcd_correct_swch_plug",3);
    iVar6 = 1;
  }
  else {
LAB_001063a8:
    lVar18 = *(long *)(param_1 + 0x48);
    if (*(int *)(lVar18 + 0x308) != 0) {
      snd_soc_component_update_bits
                (*puVar28,*(int *)(lVar18 + 0x308),*(undefined1 *)(lVar18 + 0x30c),
                 1 << (ulong)(*(byte *)(lVar18 + 0x30d) & 0x1f));
    }
    iVar6 = 3;
  }
LAB_001063f4:
  uVar33 = wcd_swch_level_remove(lVar25);
  if ((uVar33 & 1) == 0) {
    _printk(&DAT_00108892,"wcd_correct_swch_plug",iVar6,bVar30,*(undefined1 *)(param_1 + -0x270));
    lVar18 = *(long *)(param_1 + 0x48);
    if (*(int *)(lVar18 + 0x2e8) != 0) {
      snd_soc_component_update_bits
                (*puVar28,*(int *)(lVar18 + 0x2e8),*(undefined1 *)(lVar18 + 0x2ec),0);
      lVar18 = *(long *)(param_1 + 0x48);
    }
    if (*(int *)(lVar18 + 0x298) != 0) {
      snd_soc_component_update_bits
                (*puVar28,*(int *)(lVar18 + 0x298),*(undefined1 *)(lVar18 + 0x29c),0);
    }
    mutex_lock(lVar26);
    wcd_mbhc_find_plug_and_report(lVar25,iVar6);
    mutex_unlock(lVar26);
    if (iVar6 == 1) {
LAB_0010649c:
      lVar18 = *(long *)(param_1 + 0x48);
      iVar6 = 1;
      iVar11 = *(int *)(lVar18 + 0x2f8);
      if (iVar11 != 0) {
        uVar14 = *puVar28;
        uVar3 = *(undefined1 *)(lVar18 + 0x2fc);
        iVar7 = 1 << (ulong)(*(byte *)(lVar18 + 0x2fd) & 0x1f);
        iVar6 = 1;
        goto LAB_001064d8;
      }
    }
    else {
      iVar11 = *(int *)(*(long *)(param_1 + 0x48) + 0x2f8);
      if (iVar11 != 0) {
        uVar14 = *puVar28;
        iVar7 = 0;
        uVar3 = *(undefined1 *)(*(long *)(param_1 + 0x48) + 0x2fc);
LAB_001064d8:
        snd_soc_component_update_bits(uVar14,iVar11,uVar3,iVar7);
      }
    }
    lVar18 = *plVar32;
    pcVar16 = *(code **)(lVar18 + 0x20);
    if (pcVar16 != (code *)0x0) {
      if (*(int *)(pcVar16 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8229,0x106508);
        (*pcVar16)();
      }
      (*pcVar16)(lVar25,1);
      lVar18 = *plVar32;
    }
    if (*(long *)(lVar18 + 0xd0) != 0) {
      if (*(int *)(*(code **)(lVar18 + 0x98) + -4) != 0x65fc7482) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10653c);
        (*pcVar16)();
      }
      uVar12 = (**(code **)(lVar18 + 0x98))(lVar25,2);
      if ((iVar6 == 1) || (iVar6 == 5)) {
        if (*(char *)(param_1 + -0x26f) == '\0' && (uVar12 & 1) == 0) {
          lVar18 = *(long *)(param_1 + 0x48);
          iVar11 = *(int *)(lVar18 + 0x168);
          if (iVar11 != 0) {
            uVar14 = *puVar28;
            uVar3 = *(undefined1 *)(lVar18 + 0x16c);
            iVar7 = 3 << (ulong)(*(byte *)(lVar18 + 0x16d) & 0x1f);
            goto LAB_001065d8;
          }
        }
      }
      else if (iVar6 == 2) {
        lVar18 = *(long *)(param_1 + 0x48);
        if (*(int *)(lVar18 + 0x168) != 0) {
          snd_soc_component_update_bits
                    (*puVar28,*(int *)(lVar18 + 0x168),*(undefined1 *)(lVar18 + 0x16c),
                     3 << (ulong)(*(byte *)(lVar18 + 0x16d) & 0x1f));
        }
        iVar6 = 2;
      }
      else {
        iVar11 = *(int *)(*(long *)(param_1 + 0x48) + 0x168);
        if (iVar11 != 0) {
          uVar14 = *puVar28;
          iVar7 = 0;
          uVar3 = *(undefined1 *)(*(long *)(param_1 + 0x48) + 0x16c);
LAB_001065d8:
          snd_soc_component_update_bits(uVar14,iVar11,uVar3,iVar7);
        }
      }
    }
  }
  else {
    _printk(&DAT_001086ff,"wcd_correct_swch_plug");
  }
LAB_001065dc:
  pcVar16 = *(code **)(*plVar32 + 0xd0);
  if ((pcVar16 != (code *)0x0) && (*pcVar24 == '\0')) {
    if (*(int *)(pcVar16 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x106618);
      (*pcVar16)();
    }
    (*pcVar16)(uVar20,2,3);
  }
  if ((iVar6 != 2) || (*pcVar24 == '\0')) goto LAB_001066fc;
  lVar18 = *plVar32;
  pcVar16 = *(code **)(lVar18 + 0xd0);
  if (pcVar16 == (code *)0x0) {
    pcVar16 = *(code **)(lVar18 + 0xf0);
    if (pcVar16 == (code *)0x0) goto LAB_00106644;
LAB_00106684:
    if (*(int *)(pcVar16 + -4) != -0x55ff567c) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8229,0x1066a8);
      (*pcVar16)();
    }
    (*pcVar16)(uVar20,2,0);
    pcVar16 = *(code **)(*plVar32 + 0x40);
  }
  else {
    if (*(int *)(pcVar16 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8229,0x106674);
      (*pcVar16)();
    }
    (*pcVar16)(uVar20,2,3);
    lVar18 = *plVar32;
    pcVar16 = *(code **)(lVar18 + 0xf0);
    if (pcVar16 != (code *)0x0) goto LAB_00106684;
LAB_00106644:
    pcVar16 = *(code **)(lVar18 + 0x40);
  }
  if (pcVar16 != (code *)0x0) {
    if (*(int *)(pcVar16 + -4) != 0x16879923) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1066d4);
      (*pcVar16)();
    }
    (*pcVar16)(uVar20);
    iVar11 = *(int *)(*(long *)(param_1 + 0x48) + 0x188);
    if (iVar11 != 0) {
      snd_soc_component_update_bits
                (*puVar28,iVar11,*(undefined1 *)(*(long *)(param_1 + 0x48) + 0x18c),0);
    }
  }
  *pcVar24 = '\0';
LAB_001066fc:
  if (((*(char *)(*plVar22 + 0x10) != '\0') && (iVar6 - 1U < 2)) && (*pcVar29 == '\0')) {
    mutex_lock(lVar26);
    wcd_mbhc_hs_elec_irq(lVar25,1,1);
    mutex_unlock(lVar26);
  }
  if (iVar6 == 2) {
    mutex_lock(lVar26);
    wcd_mbhc_hs_elec_irq(lVar25,0,1);
    mutex_unlock(lVar26);
  }
  lVar26 = *plVar32;
  pcVar16 = *(code **)(lVar26 + 0x100);
  if (pcVar16 != (code *)0x0) {
    if (*(int *)(pcVar16 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8229,0x1067a0);
      (*pcVar16)();
    }
    (*pcVar16)(uVar20,1);
    lVar26 = *plVar32;
  }
  if (*(int *)(*(code **)(lVar26 + 0x90) + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
    pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x1067cc);
    (*pcVar16)();
  }
  (**(code **)(lVar26 + 0x90))(lVar25,0);
  _printk(&DAT_0010840a,"wcd_correct_swch_plug");
  lVar25 = sp_el0;
  if (*(long *)(lVar25 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wcd_mbhc_adc_hs_ins_irq @ 00106898 size=564
// signature: undefined wcd_mbhc_adc_hs_ins_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_mbhc_adc_hs_ins_irq(undefined8 param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  _printk(&DAT_00108389,"wcd_mbhc_adc_hs_ins_irq");
  if (*(char *)(param_2 + 0xf5) == '\0') {
    if (((((*(int *)(*(long *)(param_2 + 0x3a8) + 0x108) != 0) &&
          (uVar2 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8)),
          (uVar2 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x10c)) >>
          (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x10d) & 0x1f) == 0)) &&
         (usleep_range_state(30000,0x7594,2), *(int *)(*(long *)(param_2 + 0x3a8) + 0x108) != 0)) &&
        ((uVar2 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8)),
         (uVar2 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x10c)) >>
         (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x10d) & 0x1f) == 0 &&
         (usleep_range_state(30000,0x7594,2), *(int *)(*(long *)(param_2 + 0x3a8) + 0x108) != 0))))
       && ((uVar2 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8)),
           (uVar2 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x10c)) >>
           (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x10d) & 0x1f) == 0 &&
           ((usleep_range_state(30000,0x7594,2), *(int *)(*(long *)(param_2 + 0x3a8) + 0x108) != 0
            && (uVar2 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8)),
               (uVar2 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x10c)) >>
               (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x10d) & 0x1f) == 0)))))) {
      usleep_range_state(30000,0x7594,2);
      lVar1 = param_2 + 0x328;
      mutex_lock(lVar1);
      if ((*(ulong *)(param_2 + 0x3d8) & 1) != 0) {
        if (*(char *)(param_2 + 0xc1) == '\x02') {
          wcd_mbhc_hs_elec_irq(param_2,0,0);
          lVar3 = *(long *)(param_2 + 0x3a8);
          if (*(int *)(lVar3 + 0x2f8) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar3 + 0x2f8),
                       *(undefined1 *)(lVar3 + 0x2fc),1 << (ulong)(*(byte *)(lVar3 + 0x2fd) & 0x1f))
            ;
          }
          wcd_mbhc_find_plug_and_report(param_2,1);
        }
        else if (*(char *)(*(long *)(param_2 + 0x90) + 0x10) != '\0') {
          wcd_mbhc_hs_elec_irq(param_2,0,0);
          lVar3 = *(long *)(param_2 + 0x3a8);
          if (*(int *)(lVar3 + 0xa8) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar3 + 0xa8),
                       *(undefined1 *)(lVar3 + 0xac),0);
            lVar3 = *(long *)(param_2 + 0x3a8);
          }
          if (*(int *)(lVar3 + 0x308) != 0) {
            snd_soc_component_update_bits
                      (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar3 + 0x308),
                       *(undefined1 *)(lVar3 + 0x30c),0);
          }
          *(undefined1 *)(param_2 + 0xf0) = 0;
          *(undefined1 *)(param_2 + 0x3f0) = 0;
          *(undefined1 *)(param_2 + 0xf2) = 1;
          wcd_mbhc_adc_detect_plug_type(param_2);
          mutex_unlock(lVar1);
          _printk(&DAT_0010840a,"wcd_mbhc_adc_hs_ins_irq");
          return 1;
        }
      }
      mutex_unlock(lVar1);
    }
  }
  else {
    *(undefined1 *)(param_2 + 0xf5) = 0;
  }
  return 1;
}



//------------------------------------------------------------
// wcd_mbhc_adc_hs_rem_irq @ 00106ad0 size=1456
// signature: undefined wcd_mbhc_adc_hs_rem_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 wcd_mbhc_adc_hs_rem_irq(undefined8 param_1,long param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  code *pcVar9;
  long lVar10;
  int iVar11;
  uint local_4c;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  _printk(&DAT_00108389,"wcd_mbhc_adc_hs_rem_irq");
  mutex_lock(param_2 + 0x328);
  lVar10 = _jiffies;
  local_4c = 0;
  pcVar9 = *(code **)(*(long *)(param_2 + 0x98) + 0x18);
  if (pcVar9 == (code *)0x0) {
    if (*(int *)(*(long *)(param_2 + 0x3a8) + 0x2d8) != 0) {
      uVar4 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8));
      uVar8 = ((uVar4 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x2dc)) >>
              (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x2dd) & 0x1f)) * 0x32 + 1000;
      uVar4 = *(uint *)(param_2 + 200);
      goto joined_r0x00106b7c;
    }
    uVar8 = 0x319c;
    uVar4 = *(uint *)(param_2 + 200);
    if (uVar4 == 0) goto LAB_00106b80;
LAB_00106bd8:
    uVar1 = *(uint *)(param_2 + 0xd0);
    if (uVar1 != uVar8) {
      uVar8 = uVar4 * uVar8;
      uVar4 = 0;
      if (uVar1 != 0) {
        uVar4 = uVar8 / uVar1;
      }
    }
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106b70);
      (*pcVar9)();
    }
    (*pcVar9)(param_2,&local_4c);
    uVar4 = *(uint *)(param_2 + 200);
    uVar8 = local_4c;
joined_r0x00106b7c:
    if (uVar4 != 0) goto LAB_00106bd8;
LAB_00106b80:
    uVar4 = (int)(uVar8 * 0x6a4) / 0x708;
  }
  pcVar9 = *(code **)(*(long *)(param_2 + 0x98) + 0xd0);
  if (pcVar9 != (code *)0x0) {
    if (*(int *)(pcVar9 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106c1c);
      (*pcVar9)();
    }
    (*pcVar9)(*(undefined8 *)(param_2 + 0xf8),2,2);
  }
  iVar11 = 1;
  do {
    usleep_range_state(10000,0x2774,2);
    iVar3 = wcd_measure_adc_once(param_2,1);
    if ((iVar3 <= (int)uVar4) && (3 < iVar11)) {
      pcVar9 = *(code **)(*(long *)(param_2 + 0x98) + 0xd0);
      if (pcVar9 != (code *)0x0) {
        if (*(int *)(pcVar9 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106c98);
          (*pcVar9)();
        }
        (*pcVar9)(*(undefined8 *)(param_2 + 0xf8),2,3);
      }
      goto switchD_00106e74_default;
    }
    iVar11 = iVar11 + 1;
  } while (-1 < (lVar10 + 0x19) - _jiffies);
  pcVar9 = *(code **)(*(long *)(param_2 + 0x98) + 0xd0);
  if (pcVar9 != (code *)0x0) {
    if (*(int *)(pcVar9 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106cd0);
      (*pcVar9)();
    }
    (*pcVar9)(*(undefined8 *)(param_2 + 0xf8),2,3);
  }
  uVar5 = wcd_swch_level_remove(param_2);
  if ((uVar5 & 1) != 0) goto switchD_00106e74_default;
  if (((uint)*(undefined8 *)(param_2 + 0x3d8) >> 1 & 1) == 0) {
    _printk(&DAT_001087e5,"wcd_mbhc_adc_hs_rem_irq");
    goto switchD_00106e74_default;
  }
  lVar10 = *(long *)(param_2 + 0x90);
  if ((*(char *)(lVar10 + 0x48) == '\0') && (*(char *)(lVar10 + 0x5c) == '\0')) {
    bVar2 = false;
    uVar4 = 0;
LAB_00106e00:
    if (*(char *)(lVar10 + 0x5c) != '\0') {
LAB_00106e08:
      if (uVar4 == 0) {
        lVar10 = *(long *)(param_2 + 0x3a8);
        if (*(int *)(lVar10 + 8) == 0) {
          iVar11 = *(int *)(lVar10 + 0x28);
          if (iVar11 == 0) goto LAB_00106e20;
LAB_00106f7c:
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),iVar11,*(undefined1 *)(lVar10 + 0x2c),
                     1 << (ulong)(*(byte *)(lVar10 + 0x2d) & 0x1f));
          lVar10 = *(long *)(param_2 + 0x3a8);
          iVar11 = *(int *)(lVar10 + 8);
          if (iVar11 != 0) goto LAB_00106fa0;
LAB_00106e28:
          iVar11 = *(int *)(lVar10 + 0xb8);
          if (iVar11 == 0) goto LAB_00106e30;
LAB_00106fc4:
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),iVar11,*(undefined1 *)(lVar10 + 0xbc),0);
          lVar10 = *(long *)(param_2 + 0x3a8);
          iVar11 = *(int *)(lVar10 + 0x168);
        }
        else {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar10 + 8),
                     *(undefined1 *)(lVar10 + 0xc),0);
          lVar10 = *(long *)(param_2 + 0x3a8);
          iVar11 = *(int *)(lVar10 + 0x28);
          if (iVar11 != 0) goto LAB_00106f7c;
LAB_00106e20:
          iVar11 = *(int *)(lVar10 + 8);
          if (iVar11 == 0) goto LAB_00106e28;
LAB_00106fa0:
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),iVar11,*(undefined1 *)(lVar10 + 0xc),
                     1 << (ulong)(*(byte *)(lVar10 + 0xd) & 0x1f));
          lVar10 = *(long *)(param_2 + 0x3a8);
          iVar11 = *(int *)(lVar10 + 0xb8);
          if (iVar11 != 0) goto LAB_00106fc4;
LAB_00106e30:
          iVar11 = *(int *)(lVar10 + 0x168);
        }
        if (iVar11 != 0) {
          snd_soc_component_update_bits
                    (*(undefined8 *)(param_2 + 0xf8),iVar11,*(undefined1 *)(lVar10 + 0x16c),0);
        }
        *(undefined1 *)(param_2 + 0xf0) = 0;
        *(undefined1 *)(param_2 + 0xc0) = 0;
        switch(*(undefined1 *)(param_2 + 0xc1)) {
        case 1:
          wcd_mbhc_report_plug(param_2,0,3);
          uVar6 = *(undefined8 *)(param_2 + 0x420);
          uVar7 = 0x14;
          break;
        case 2:
          wcd_mbhc_report_plug(param_2,0,1);
          uVar6 = *(undefined8 *)(param_2 + 0x420);
          uVar7 = 0x15;
          break;
        case 3:
          wcd_mbhc_report_plug(param_2,0,4);
          uVar6 = *(undefined8 *)(param_2 + 0x420);
          uVar7 = 0x17;
          break;
        case 4:
          uVar6 = *(undefined8 *)(param_2 + 0x420);
          uVar7 = 0x3e;
          break;
        default:
          goto switchD_00106e74_default;
        }
        extcon_set_state_sync(uVar6,uVar7,0);
        goto switchD_00106e74_default;
      }
    }
  }
  else {
    pcVar9 = *(code **)(*(long *)(param_2 + 0x98) + 0xb8);
    if (pcVar9 == (code *)0x0) {
LAB_00106d70:
      bVar2 = false;
    }
    else {
      if (*(int *)(pcVar9 + -4) != -0x7ea8dd3) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x106d44);
        (*pcVar9)();
      }
      uVar5 = (*pcVar9)(*(undefined8 *)(param_2 + 0xf8));
      if ((uVar5 & 1) == 0) goto LAB_00106d70;
      iVar11 = *(int *)(*(long *)(param_2 + 0x3a8) + 0x1c8);
      if (iVar11 != 0) {
        snd_soc_component_update_bits
                  (*(undefined8 *)(param_2 + 0xf8),iVar11,
                   *(undefined1 *)(*(long *)(param_2 + 0x3a8) + 0x1cc),0);
      }
      bVar2 = true;
    }
    lVar10 = *(long *)(param_2 + 0x3a8);
    if (*(int *)(lVar10 + 0x238) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar10 + 0x238),
                 *(undefined1 *)(lVar10 + 0x23c),1 << (ulong)(*(byte *)(lVar10 + 0x23d) & 0x1f));
      lVar10 = *(long *)(param_2 + 0x3a8);
    }
    if (*(int *)(lVar10 + 0x248) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar10 + 0x248),
                 *(undefined1 *)(lVar10 + 0x24c),1 << (ulong)(*(byte *)(lVar10 + 0x24d) & 0x1f));
    }
    usleep_range_state(50000,0xc3b4,2);
    if (*(int *)(*(long *)(param_2 + 0x3a8) + 0x228) != 0) {
      uVar4 = snd_soc_component_read(*(undefined8 *)(param_2 + 0xf8));
      lVar10 = *(long *)(param_2 + 0x90);
      uVar4 = (uVar4 & *(byte *)(*(long *)(param_2 + 0x3a8) + 0x22c)) >>
              (ulong)(*(byte *)(*(long *)(param_2 + 0x3a8) + 0x22d) & 0x1f);
      if (*(char *)(lVar10 + 0x48) == '\0') goto LAB_00106e00;
      goto LAB_00106e08;
    }
  }
  if (*(char *)(param_2 + 0xc1) == '\x02') {
    *(undefined1 *)(param_2 + 0xf5) = 1;
  }
  lVar10 = *(long *)(param_2 + 0x3a8);
  if (*(int *)(lVar10 + 0x2f8) == 0) {
    iVar11 = *(int *)(lVar10 + 0x2e8);
    if (iVar11 == 0) goto LAB_00106ebc;
LAB_00106f40:
    snd_soc_component_update_bits
              (*(undefined8 *)(param_2 + 0xf8),iVar11,*(undefined1 *)(lVar10 + 0x2ec),0);
    lVar10 = *(long *)(param_2 + 0x3a8);
    iVar11 = *(int *)(lVar10 + 0x298);
  }
  else {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar10 + 0x2f8),
               *(undefined1 *)(lVar10 + 0x2fc),0);
    lVar10 = *(long *)(param_2 + 0x3a8);
    iVar11 = *(int *)(lVar10 + 0x2e8);
    if (iVar11 != 0) goto LAB_00106f40;
LAB_00106ebc:
    iVar11 = *(int *)(lVar10 + 0x298);
  }
  if (iVar11 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_2 + 0xf8),iVar11,*(undefined1 *)(lVar10 + 0x29c),0);
  }
  wcd_mbhc_elec_hs_report_unplug(param_2);
  iVar11 = *(int *)(*(long *)(param_2 + 0x3a8) + 0x168);
  if (iVar11 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_2 + 0xf8),iVar11,
               *(undefined1 *)(*(long *)(param_2 + 0x3a8) + 0x16c),0);
  }
  if (bVar2) {
    lVar10 = *(long *)(param_2 + 0x3a8);
    if (*(int *)(lVar10 + 0x1c8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_2 + 0xf8),*(int *)(lVar10 + 0x1c8),
                 *(undefined1 *)(lVar10 + 0x1cc),3 << (ulong)(*(byte *)(lVar10 + 0x1cd) & 0x1f));
    }
  }
switchD_00106e74_default:
  mutex_unlock(param_2 + 0x328);
  _printk(&DAT_0010840a,"wcd_mbhc_adc_hs_rem_irq");
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// wcd_mbhc_adc_detect_plug_type @ 00107084 size=392
// signature: undefined wcd_mbhc_adc_detect_plug_type(void)
// callers: [wcd_mbhc_adc_hs_ins_irq]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wcd_mbhc_adc_detect_plug_type(long param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  uVar4 = *(undefined8 *)(param_1 + 0xf8);
  uVar2 = mutex_is_locked(param_1 + 0x328);
  if (((uVar2 & 1) == 0) && ((wcd_mbhc_adc_detect_plug_type___already_done & 1) == 0)) {
    wcd_mbhc_adc_detect_plug_type___already_done = 1;
    __warn_printk("%s: BCL should have acquired\n","wcd_mbhc_adc_detect_plug_type");
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1071ec);
    (*pcVar3)();
  }
  pcVar3 = *(code **)(*(long *)(param_1 + 0x98) + 0x100);
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != 0x493b737d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1070e8);
      (*pcVar3)();
    }
    (*pcVar3)(uVar4,0);
  }
  iVar1 = *(int *)(*(long *)(param_1 + 0x3a8) + 0x2f8);
  if (iVar1 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar1,
               *(undefined1 *)(*(long *)(param_1 + 0x3a8) + 0x2fc),0);
  }
  pcVar3 = *(code **)(*(long *)(param_1 + 0x98) + 0xd0);
  if (pcVar3 == (code *)0x0) {
    _printk(&DAT_0010854a,"wcd_mbhc_adc_detect_plug_type");
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107138);
      (*pcVar3)();
    }
    (*pcVar3)(uVar4,2,2);
    *(undefined4 *)(param_1 + 0x3b0) = 0;
    uVar2 = mutex_is_locked(param_1 + 0x328);
    if (((uVar2 & 1) == 0) && ((wcd_schedule_hs_detect_plug___already_done & 1) == 0)) {
      wcd_schedule_hs_detect_plug___already_done = 1;
      __warn_printk("%s: BCL should have acquired\n","wcd_schedule_hs_detect_plug");
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x107210);
      (*pcVar3)();
    }
    *(undefined1 *)(param_1 + 0xee) = 0;
    pcVar3 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
    if (*(int *)(pcVar3 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107188);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,1);
    queue_work_on(0x20,_system_wq,param_1 + 0x360);
  }
  return;
}



//------------------------------------------------------------
// wcd_mbhc_adc_detect_anc_plug_type @ 00107218 size=1316
// signature: undefined wcd_mbhc_adc_detect_anc_plug_type(void)
// callers: []
//------------------------------------------------------------

bool wcd_mbhc_adc_detect_anc_plug_type(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  code *pcVar9;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  
  if ((*(int *)(*(long *)(param_1 + 0x90) + 0x50) - 5U < 0xfffffffc) ||
     (*(long *)(*(long *)(param_1 + 0x98) + 0xd0) == 0)) {
    return false;
  }
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x2f8) == 0) {
    uVar1 = 0xea;
  }
  else {
    uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar8 = *(long *)(param_1 + 0x3a8);
    uVar1 = (uVar1 & *(byte *)(lVar8 + 0x2fc)) >> (ulong)(*(byte *)(lVar8 + 0x2fd) & 0x1f);
    if (*(int *)(lVar8 + 0x2f8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x2f8),
                 *(undefined1 *)(lVar8 + 0x2fc),0);
    }
  }
  wcd_mbhc_hs_elec_irq(param_1,0,0);
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0xb8) == 0) {
    uVar2 = 0xffea;
  }
  else {
    uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    uVar2 = (uVar2 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0xbc)) >>
            (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0xbd) & 0x1f);
  }
  pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0xd0);
  if (*(int *)(pcVar9 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x107314);
    (*pcVar9)();
  }
  (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x90) + 0x50),2);
  lVar8 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar8 + 0xa8) == 0) {
    uVar3 = 0xea;
    iVar5 = *(int *)(lVar8 + 0x1f8);
  }
  else {
    uVar3 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar8 = *(long *)(param_1 + 0x3a8);
    uVar3 = (uVar3 & *(byte *)(lVar8 + 0xac)) >> (ulong)(*(byte *)(lVar8 + 0xad) & 0x1f);
    if (*(int *)(lVar8 + 0xa8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0xa8),
                 *(undefined1 *)(lVar8 + 0xac),0);
      lVar8 = *(long *)(param_1 + 0x3a8);
    }
    iVar5 = *(int *)(lVar8 + 0x1f8);
  }
  if (iVar5 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar5,*(undefined1 *)(lVar8 + 0x1fc),
               1 << (ulong)(*(byte *)(lVar8 + 0x1fd) & 0x1f));
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0x2e8) == 0) {
    uVar4 = 0xea;
  }
  else {
    uVar4 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    uVar4 = (uVar4 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0x2ec)) >>
            (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0x2ed) & 0x1f);
  }
  usleep_range_state(20000,0x4e84,2);
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0xe8) == 0) {
    uVar6 = 0xea;
  }
  else {
    uVar6 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    uVar6 = (uVar6 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0xec)) >>
            ((ulong)*(byte *)(*(long *)(param_1 + 0x3a8) + 0xed) & 0x3f);
  }
  uVar7 = wcd_swch_level_remove(param_1);
  if ((uVar7 & 1) == 0) {
    iVar5 = wcd_measure_adc_once(param_1,2);
    if (iVar5 == 0) {
LAB_00107440:
      uVar12 = 0;
      uVar11 = 1;
    }
    else {
      if (3 < uVar6) goto LAB_00107738;
      if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_00107440;
      uVar11 = 0;
      uVar12 = 1;
    }
    uVar7 = wcd_swch_level_remove(param_1);
    if ((uVar7 & 1) == 0) {
      iVar5 = wcd_measure_adc_once(param_1,2);
      if (iVar5 == 0) {
LAB_00107488:
        uVar11 = uVar11 + 1;
      }
      else {
        if (3 < uVar6) goto LAB_00107738;
        if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_00107488;
        uVar12 = uVar12 + 1;
      }
      uVar7 = wcd_swch_level_remove(param_1);
      if ((uVar7 & 1) == 0) {
        iVar5 = wcd_measure_adc_once(param_1,2);
        if (iVar5 == 0) {
LAB_001074cc:
          uVar11 = uVar11 + 1;
        }
        else {
          if (3 < uVar6) goto LAB_00107738;
          if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_001074cc;
          uVar12 = uVar12 + 1;
        }
        uVar7 = wcd_swch_level_remove(param_1);
        if ((uVar7 & 1) == 0) {
          iVar5 = wcd_measure_adc_once(param_1,2);
          if (iVar5 == 0) {
LAB_00107510:
            uVar11 = uVar11 + 1;
          }
          else {
            if (3 < uVar6) goto LAB_00107738;
            if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_00107510;
            uVar12 = uVar12 + 1;
          }
          uVar7 = wcd_swch_level_remove(param_1);
          if ((uVar7 & 1) == 0) {
            iVar5 = wcd_measure_adc_once(param_1,2);
            if (iVar5 == 0) {
LAB_00107554:
              uVar11 = uVar11 + 1;
            }
            else {
              if (3 < uVar6) goto LAB_00107738;
              if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_00107554;
              uVar12 = uVar12 + 1;
            }
            uVar7 = wcd_swch_level_remove(param_1);
            if ((uVar7 & 1) == 0) {
              iVar5 = wcd_measure_adc_once(param_1,2);
              if (iVar5 == 0) {
LAB_00107598:
                uVar11 = uVar11 + 1;
              }
              else {
                if (3 < uVar6) goto LAB_00107738;
                if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_00107598;
                uVar12 = uVar12 + 1;
              }
              uVar7 = wcd_swch_level_remove(param_1);
              if ((uVar7 & 1) == 0) {
                iVar5 = wcd_measure_adc_once(param_1,2);
                if (iVar5 == 0) {
LAB_00107728:
                  uVar11 = uVar11 + 1;
                }
                else {
                  if (3 < uVar6) {
LAB_00107738:
                    /* WARNING: Does not return */
                    pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x10773c);
                    (*pcVar9)();
                  }
                  if (*(int *)(&DAT_001091e4 + uVar6 * 4) <= iVar5) goto LAB_00107728;
                  uVar12 = uVar12 + 1;
                }
                bVar10 = uVar11 < uVar12;
                goto LAB_001075ac;
              }
            }
          }
        }
      }
    }
  }
  bVar10 = false;
LAB_001075ac:
  lVar8 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar8 + 0x2e8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x2e8),
               *(undefined1 *)(lVar8 + 0x2ec),uVar4 << (ulong)(*(byte *)(lVar8 + 0x2ed) & 0x1f));
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0x1f8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x1f8),
               *(undefined1 *)(lVar8 + 0x1fc),0);
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0xb8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0xb8),*(undefined1 *)(lVar8 + 0xbc),
               0);
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0x218) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x218),
               *(undefined1 *)(lVar8 + 0x21c),0);
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0xb8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0xb8),*(undefined1 *)(lVar8 + 0xbc),
               1 << (ulong)(*(byte *)(lVar8 + 0xbd) & 0x1f));
    lVar8 = *(long *)(param_1 + 0x3a8);
    if (*(int *)(lVar8 + 0xb8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0xb8),
                 *(undefined1 *)(lVar8 + 0xbc),uVar2 << (ulong)(*(byte *)(lVar8 + 0xbd) & 0x1f));
      lVar8 = *(long *)(param_1 + 0x3a8);
    }
  }
  if (*(int *)(lVar8 + 0x2f8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0x2f8),
               *(undefined1 *)(lVar8 + 0x2fc),uVar1 << (ulong)(*(byte *)(lVar8 + 0x2fd) & 0x1f));
    lVar8 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar8 + 0xa8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar8 + 0xa8),*(undefined1 *)(lVar8 + 0xac),
               uVar3 << (ulong)(*(byte *)(lVar8 + 0xad) & 0x1f));
  }
  pcVar9 = *(code **)(*(long *)(param_1 + 0x98) + 0xd0);
  if (*(int *)(pcVar9 + -4) != -0xe0273db) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1076d0);
    (*pcVar9)();
  }
  (*pcVar9)(*(undefined8 *)(param_1 + 0xf8),*(undefined4 *)(*(long *)(param_1 + 0x90) + 0x50),3);
  return bVar10;
}



//------------------------------------------------------------
// wcd_cancel_hs_detect_plug @ 00107740 size=132
// signature: undefined wcd_cancel_hs_detect_plug(void)
// callers: []
//------------------------------------------------------------

void wcd_cancel_hs_detect_plug(long param_1,undefined8 param_2)

{
  ulong uVar1;
  code *pcVar2;
  
  *(undefined1 *)(param_1 + 0xee) = 1;
  mutex_unlock(param_1 + 0x328);
  uVar1 = cancel_work_sync(param_2);
  if ((uVar1 & 1) != 0) {
    pcVar2 = *(code **)(*(long *)(param_1 + 0x98) + 0x90);
    if (*(int *)(pcVar2 + -4) != -0x5ac5ef17) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1077a4);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,0);
  }
  mutex_lock(param_1 + 0x328);
  return;
}



//------------------------------------------------------------
// wcd_measure_adc_once @ 001077c4 size=780
// signature: undefined wcd_measure_adc_once(void)
// callers: [wcd_mbhc_adc_detect_anc_plug_type, wcd_check_cross_conn, wcd_correct_swch_plug, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

int wcd_measure_adc_once(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar4 + 0x2e8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar4 + 0x2e8),
               *(undefined1 *)(lVar4 + 0x2ec),0);
    lVar4 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar4 + 0x298) == 0) {
    uVar1 = 0xea;
    iVar8 = *(int *)(lVar4 + 0xb8);
  }
  else {
    uVar1 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar4 = *(long *)(param_1 + 0x3a8);
    uVar1 = (uVar1 & *(byte *)(lVar4 + 0x29c)) >> (ulong)(*(byte *)(lVar4 + 0x29d) & 0x1f);
    if (*(int *)(lVar4 + 0x298) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar4 + 0x298),
                 *(undefined1 *)(lVar4 + 0x29c),0);
      lVar4 = *(long *)(param_1 + 0x3a8);
    }
    iVar8 = *(int *)(lVar4 + 0xb8);
  }
  if (iVar8 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar8,*(undefined1 *)(lVar4 + 0xbc),0);
    lVar4 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar4 + 0x218) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar4 + 0x218),
               *(undefined1 *)(lVar4 + 0x21c),param_2 << (ulong)(*(byte *)(lVar4 + 0x21d) & 0x1f));
    lVar4 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar4 + 0xb8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar4 + 0xb8),*(undefined1 *)(lVar4 + 0xbc),
               1 << (ulong)(*(byte *)(lVar4 + 0xbd) & 0x1f));
    lVar4 = *(long *)(param_1 + 0x3a8);
  }
  if (*(int *)(lVar4 + 0x298) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar4 + 0x298),
               *(undefined1 *)(lVar4 + 0x29c),1 << (ulong)(*(byte *)(lVar4 + 0x29d) & 0x1f));
  }
  iVar8 = 5;
  do {
    usleep_range_state(600,0x262,2);
    lVar4 = *(long *)(param_1 + 0x3a8);
    if (*(int *)(lVar4 + 0x2b8) == 0) {
      uVar2 = 0xea;
    }
    else {
      uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
      lVar4 = *(long *)(param_1 + 0x3a8);
      uVar2 = (uVar2 & *(byte *)(lVar4 + 700)) >> (ulong)(*(byte *)(lVar4 + 0x2bd) & 0x1f);
      if (uVar2 == 0) {
        if (*(int *)(lVar4 + 0x2a8) == 0) {
          uVar6 = 0xea;
        }
        else {
          uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
          lVar4 = *(long *)(param_1 + 0x3a8);
          uVar6 = (uVar2 & *(byte *)(lVar4 + 0x2ac)) >> (ulong)(*(byte *)(lVar4 + 0x2ad) & 0x1f);
          if (uVar6 == 0) {
            uVar2 = 0;
            goto LAB_001078e4;
          }
        }
        if (*(int *)(lVar4 + 0x2c8) == 0) {
          iVar7 = 0x7242;
        }
        else {
          uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
          lVar4 = *(long *)(param_1 + 0x3a8);
          iVar7 = ((uVar2 & *(byte *)(lVar4 + 0x2cc)) >> (ulong)(*(byte *)(lVar4 + 0x2cd) & 0x1f)) *
                  0x7d;
        }
        local_4c = 0;
        pcVar5 = *(code **)(*(long *)(param_1 + 0x98) + 0x18);
        if (pcVar5 == (code *)0x0) {
          if (*(int *)(lVar4 + 0x2d8) == 0) {
            iVar3 = 0x319c;
          }
          else {
            uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
            lVar4 = *(long *)(param_1 + 0x3a8);
            iVar3 = ((uVar2 & *(byte *)(lVar4 + 0x2dc)) >> (ulong)(*(byte *)(lVar4 + 0x2dd) & 0x1f))
                    * 0x32 + 1000;
          }
        }
        else {
          if (*(int *)(pcVar5 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x107a34);
            (*pcVar5)();
          }
          (*pcVar5)(param_1,&local_4c);
          lVar4 = *(long *)(param_1 + 0x3a8);
          iVar3 = local_4c;
        }
        uVar2 = 0;
        iVar3 = (iVar3 * iVar7) / 18000;
        iVar7 = *(int *)(lVar4 + 0x298);
        goto joined_r0x00107ac4;
      }
    }
LAB_001078e4:
    iVar8 = iVar8 + -1;
  } while (iVar8 != -1);
  iVar3 = 0;
  uVar6 = 0;
  iVar7 = *(int *)(lVar4 + 0x298);
joined_r0x00107ac4:
  if (iVar7 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar7,*(undefined1 *)(lVar4 + 0x29c),
               uVar1 << (ulong)(*(byte *)(lVar4 + 0x29d) & 0x1f));
  }
  if (iVar8 < 1) {
    _printk(&DAT_001086d6,"wcd_measure_adc_once",uVar6,uVar2);
    iVar3 = -0x16;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wcd_check_cross_conn @ 00107ad0 size=888
// signature: undefined wcd_check_cross_conn(void)
// callers: [wcd_correct_swch_plug]
//------------------------------------------------------------

undefined8 wcd_check_cross_conn(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  undefined *puVar9;
  code *pcVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  
  uVar8 = wcd_swch_level_remove();
  if ((uVar8 & 1) != 0) {
    return 0xffffffea;
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x98) + 0xb8);
  if (pcVar10 != (code *)0x0) {
    if (*(int *)(pcVar10 + -4) != -0x7ea8dd3) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107b20);
      (*pcVar10)();
    }
    uVar8 = (*pcVar10)(*(undefined8 *)(param_1 + 0xf8));
    if ((uVar8 & 1) != 0) {
      return 0xffffffea;
    }
  }
  if (*(int *)(*(long *)(param_1 + 0x3a8) + 0xa8) == 0) {
    uVar2 = 0xea;
  }
  else {
    uVar2 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar11 = *(long *)(param_1 + 0x3a8);
    uVar2 = (uVar2 & *(byte *)(lVar11 + 0xac)) >> (ulong)(*(byte *)(lVar11 + 0xad) & 0x1f);
    if (*(int *)(lVar11 + 0xa8) != 0) {
      snd_soc_component_update_bits
                (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar11 + 0xa8),
                 *(undefined1 *)(lVar11 + 0xac),0);
    }
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x98) + 8);
  if (pcVar10 != (code *)0x0) {
    if (*(int *)(pcVar10 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107bc0);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,0);
  }
  lVar11 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar11 + 0x2e8) == 0) {
    uVar5 = 0xea;
    if (*(int *)(lVar11 + 0x298) != 0) goto LAB_00107bdc;
LAB_00107c44:
    uVar3 = 0xea;
    if (*(int *)(lVar11 + 0xb8) == 0) goto LAB_00107c50;
LAB_00107c00:
    uVar4 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    uVar4 = (uVar4 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0xbc)) >>
            (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0xbd) & 0x1f);
  }
  else {
    uVar5 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar11 = *(long *)(param_1 + 0x3a8);
    uVar5 = (uVar5 & *(byte *)(lVar11 + 0x2ec)) >> (ulong)(*(byte *)(lVar11 + 0x2ed) & 0x1f);
    if (*(int *)(lVar11 + 0x298) == 0) goto LAB_00107c44;
LAB_00107bdc:
    uVar3 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
    lVar11 = *(long *)(param_1 + 0x3a8);
    uVar3 = (uVar3 & *(byte *)(lVar11 + 0x29c)) >> (ulong)(*(byte *)(lVar11 + 0x29d) & 0x1f);
    if (*(int *)(lVar11 + 0xb8) != 0) goto LAB_00107c00;
LAB_00107c50:
    uVar4 = 0xea;
  }
  uVar6 = wcd_measure_adc_once(param_1,4);
  if ((int)uVar6 < 0) {
    puVar9 = &DAT_00109002;
LAB_00107c8c:
    _printk(puVar9,"wcd_check_cross_conn");
  }
  else {
    uVar7 = wcd_measure_adc_once(param_1,5);
    if ((int)uVar7 < 0) {
      puVar9 = &DAT_00108959;
      goto LAB_00107c8c;
    }
    pcVar10 = (code *)**(undefined8 **)(param_1 + 0x98);
    if (pcVar10 != (code *)0x0) {
      if (*(int *)(pcVar10 + -4) != 0x5c9283de) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107e20);
        (*pcVar10)();
      }
      (*pcVar10)(param_1);
    }
    if ((*(uint *)(param_1 + 0xe4) < uVar6) && (*(uint *)(param_1 + 0xe8) < uVar7)) {
      uVar13 = 4;
      uVar12 = 1;
      goto LAB_00107ca0;
    }
  }
  uVar12 = 0;
  uVar13 = 0;
LAB_00107ca0:
  lVar11 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar11 + 0xb8) == 0) {
    iVar1 = *(int *)(lVar11 + 0x218);
  }
  else {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar11 + 0xb8),
               *(undefined1 *)(lVar11 + 0xbc),0);
    lVar11 = *(long *)(param_1 + 0x3a8);
    iVar1 = *(int *)(lVar11 + 0x218);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(lVar11 + 0xb8);
  }
  else {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar1,*(undefined1 *)(lVar11 + 0x21c),0);
    lVar11 = *(long *)(param_1 + 0x3a8);
    iVar1 = *(int *)(lVar11 + 0xb8);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(lVar11 + 0x298);
  }
  else {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar1,*(undefined1 *)(lVar11 + 0xbc),
               1 << (ulong)(*(byte *)(lVar11 + 0xbd) & 0x1f));
    lVar11 = *(long *)(param_1 + 0x3a8);
    iVar1 = *(int *)(lVar11 + 0x298);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(lVar11 + 0x2e8);
  }
  else {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar1,*(undefined1 *)(lVar11 + 0x29c),
               uVar3 << (ulong)(*(byte *)(lVar11 + 0x29d) & 0x1f));
    lVar11 = *(long *)(param_1 + 0x3a8);
    iVar1 = *(int *)(lVar11 + 0x2e8);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(lVar11 + 0xb8);
  }
  else {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar1,*(undefined1 *)(lVar11 + 0x2ec),
               uVar5 << (ulong)(*(byte *)(lVar11 + 0x2ed) & 0x1f));
    lVar11 = *(long *)(param_1 + 0x3a8);
    iVar1 = *(int *)(lVar11 + 0xb8);
  }
  if (iVar1 != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),iVar1,*(undefined1 *)(lVar11 + 0xbc),
               uVar4 << (ulong)(*(byte *)(lVar11 + 0xbd) & 0x1f));
  }
  pcVar10 = *(code **)(*(long *)(param_1 + 0x98) + 8);
  if (pcVar10 != (code *)0x0) {
    if (*(int *)(pcVar10 + -4) != 0x7311a9cf) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107d14);
      (*pcVar10)();
    }
    (*pcVar10)(param_1,1);
  }
  lVar11 = *(long *)(param_1 + 0x3a8);
  if (*(int *)(lVar11 + 0xa8) != 0) {
    snd_soc_component_update_bits
              (*(undefined8 *)(param_1 + 0xf8),*(int *)(lVar11 + 0xa8),
               *(undefined1 *)(lVar11 + 0xac),uVar2 << (ulong)(*(byte *)(lVar11 + 0xad) & 0x1f));
  }
  _printk(&DAT_00108b47,"wcd_check_cross_conn",uVar13);
  return uVar12;
}



//------------------------------------------------------------
// wcd_mbhc_get_plug_from_adc @ 00107e48 size=548
// signature: undefined wcd_mbhc_get_plug_from_adc(void)
// callers: [wcd_correct_swch_plug]
//------------------------------------------------------------

void wcd_mbhc_get_plug_from_adc(long param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  code *pcVar8;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x18);
  if (pcVar8 == (code *)0x0) {
    if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x2d8) == 0) {
      local_3c = 0x319c;
      uVar5 = *(uint *)(param_1 + 200);
    }
    else {
      uVar5 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
      local_3c = ((uVar5 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0x2dc)) >>
                 (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0x2dd) & 0x1f)) * 0x32 + 1000;
      uVar5 = *(uint *)(param_1 + 200);
    }
  }
  else {
    if (*(int *)(pcVar8 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x107ec0);
      (*pcVar8)();
    }
    (*pcVar8)(param_1,&local_3c);
    uVar5 = *(uint *)(param_1 + 200);
  }
  if (uVar5 == 0) {
    uVar5 = (int)(local_3c * 0x6a4) / 0x708;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0xd0);
    if (uVar6 != local_3c) {
      local_3c = uVar5 * local_3c;
      uVar5 = 0;
      if (uVar6 != 0) {
        uVar5 = local_3c / uVar6;
      }
    }
  }
  local_3c = 0;
  pcVar8 = *(code **)(*(long *)(param_1 + 0x98) + 0x18);
  if (pcVar8 == (code *)0x0) {
    if (*(int *)(*(long *)(param_1 + 0x3a8) + 0x2d8) == 0) {
      uVar6 = *(uint *)(param_1 + 0xcc);
      uVar3 = 0x319c;
    }
    else {
      uVar6 = snd_soc_component_read(*(undefined8 *)(param_1 + 0xf8));
      uVar3 = ((uVar6 & *(byte *)(*(long *)(param_1 + 0x3a8) + 0x2dc)) >>
              (ulong)(*(byte *)(*(long *)(param_1 + 0x3a8) + 0x2dd) & 0x1f)) * 0x32 + 1000;
      uVar6 = *(uint *)(param_1 + 0xcc);
    }
  }
  else {
    if (*(int *)(pcVar8 + -4) != 0x13bf3532) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x107f88);
      (*pcVar8)();
    }
    (*pcVar8)(param_1,&local_3c);
    uVar6 = *(uint *)(param_1 + 0xcc);
    uVar3 = local_3c;
  }
  if (uVar6 == 0) {
    uVar6 = (int)(uVar3 * 0x4b) / 0x708;
  }
  else {
    uVar2 = *(uint *)(param_1 + 0xd0);
    if (uVar2 != uVar3) {
      uVar3 = uVar6 * uVar3;
      uVar6 = 0;
      if (uVar2 != 0) {
        uVar6 = uVar3 / uVar2;
      }
    }
  }
  _printk(&DAT_00108bb8,"wcd_mbhc_get_plug_from_adc",uVar5,uVar6,param_2);
  lVar4 = sp_el0;
  uVar7 = 3;
  if (param_2 <= uVar5) {
    uVar7 = 1;
  }
  uVar1 = 2;
  if (uVar6 <= param_2) {
    uVar1 = uVar7;
  }
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001082dc size=84
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  __mutex_init(hphl_pa_lock,"&hphl_pa_lock",&mbhc_init___key);
  __mutex_init(hphr_pa_lock,"&hphr_pa_lock",&mbhc_init___key_72);
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00108334 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// snd_soc_jack_report @ 0010b000 size=1
// signature: undefined snd_soc_jack_report(void)
// callers: [wcd_mbhc_jack_report, wcd_mbhc_hphr_ocp_irq, wcd_mbhc_report_plug, wcd_mbhc_release_handler, wcd_btn_lpress_fn, wcd_mbhc_hphl_ocp_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_jack_report(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0010b008 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [wcd_mbhc_initialise, wcd_mbhc_hphr_ocp_irq, wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_find_plug_and_report, wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug, wcd_check_cross_conn, wcd_mbhc_hphl_ocp_irq, wcd_correct_swch_plug, wcd_mbhc_adc_detect_plug_type, wcd_mbhc_usbc_ana_event_handler, wcd_event_notify, wcd_measure_adc_once, wcd_mbhc_adc_detect_anc_plug_type, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq, wcd_mbhc_set_and_turnoff_hph_padac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010b010 size=1
// signature: undefined _dev_err(void)
// callers: [wcd_mbhc_init, wcd_mbhc_initialise, wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0010b018 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [wcd_mbhc_stop, wcd_mbhc_btn_press_handler, wcd_cancel_btn_work, wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug, wcd_mbhc_release_handler, wcd_mbhc_swch_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0010b020 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [wcd_mbhc_get_plug_from_adc, wcd_mbhc_btn_press_handler, wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_report_plug, wcd_mbhc_release_handler, wcd_check_cross_conn, wcd_mbhc_hphl_ocp_irq, wcd_correct_swch_plug, wcd_mbhc_usbc_ana_event_handler, wcd_event_notify, wcd_measure_adc_once, wcd_mbhc_adc_detect_anc_plug_type, wcd_btn_lpress_fn, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq, wcd_swch_level_remove, wcd_mbhc_set_and_turnoff_hph_padac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 0010b028 size=1
// signature: undefined mutex_is_locked(void)
// callers: [wcd_mbhc_hs_elec_irq, wcd_mbhc_find_plug_and_report, wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_detect_plug_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010b030 size=1
// signature: undefined __warn_printk(void)
// callers: [wcd_mbhc_hs_elec_irq, wcd_mbhc_btn_press_handler, wcd_mbhc_find_plug_and_report, wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug, wcd_mbhc_start, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_detect_plug_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010b040 size=1
// signature: undefined _printk(void)
// callers: [wcd_mbhc_init, wcd_mbhc_adc_init, wcd_mbhc_hphr_ocp_irq, wcd_mbhc_get_plug_from_adc, wcd_mbhc_find_plug_and_report, wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_report_plug, wcd_mbhc_elec_hs_report_unplug, wcd_mbhc_start, wcd_mbhc_release_handler, wcd_check_cross_conn, wcd_mbhc_fw_read, wcd_mbhc_hphl_ocp_irq, wcd_correct_swch_plug, wcd_mbhc_mech_plug_detect_irq, wcd_mbhc_adc_detect_plug_type, wcd_mbhc_usbc_ana_event_handler, wcd_measure_adc_once, wcd_btn_lpress_fn, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_set_state_sync @ 0010b048 size=1
// signature: undefined extcon_set_state_sync(void)
// callers: [wcd_mbhc_find_plug_and_report, wcd_mbhc_report_plug, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_set_state_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010b050 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd_measure_adc_once, wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_adc_detect_anc_plug_type, wcd_mbhc_report_plug, wcd_mbhc_fw_read, wcd_correct_swch_plug, wcd_mbhc_adc_hs_rem_irq, wcd_mbhc_set_and_turnoff_hph_padac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010b060 size=1
// signature: undefined mutex_lock(void)
// callers: [wcd_mbhc_initialise, wcd_mbhc_btn_press_handler, wcd_mbhc_deinit, wcd_cancel_hs_detect_plug, wcd_event_notify, wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_report_plug, wcd_mbhc_release_handler, wcd_correct_swch_plug, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010b068 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcd_mbhc_initialise, wcd_event_notify, wcd_mbhc_btn_press_handler, wcd_mbhc_deinit, wcd_cancel_hs_detect_plug, wcd_mbhc_adc_hs_ins_irq, wcd_mbhc_report_plug, wcd_mbhc_release_handler, wcd_correct_swch_plug, wcd_mbhc_swch_irq_handler, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010b070 size=1
// signature: undefined of_find_property(void)
// callers: [wcd_mbhc_start, wcd_mbhc_swch_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010b078 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [wcd_mbhc_init, wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_jack_set_key @ 0010b080 size=1
// signature: undefined snd_jack_set_key(void)
// callers: [wcd_mbhc_init, wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_jack_set_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_capability @ 0010b088 size=1
// signature: undefined input_set_capability(void)
// callers: [wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_reg_notifier @ 0010b090 size=1
// signature: undefined wcd_usbss_reg_notifier(void)
// callers: [wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fsa4480_reg_notifier @ 0010b098 size=1
// signature: undefined fsa4480_reg_notifier(void)
// callers: [wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fsa4480_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_usecs @ 0010b0a0 size=1
// signature: undefined jiffies_to_usecs(void)
// callers: [wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_usecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0010b0b0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [wcd_mbhc_btn_press_handler, wcd_mbhc_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010b0b8 size=1
// signature: undefined _dev_info(void)
// callers: [wcd_mbhc_usbc_ana_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_switch_update @ 0010b0c0 size=1
// signature: undefined wcd_usbss_switch_update(void)
// callers: [wcd_mbhc_usbc_ana_event_handler, wcd_mbhc_swch_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_switch_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 0010b0c8 size=1
// signature: undefined release_firmware(void)
// callers: [wcd_mbhc_stop, wcd_mbhc_fw_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_unreg_notifier @ 0010b0d0 size=1
// signature: undefined wcd_usbss_unreg_notifier(void)
// callers: [wcd_mbhc_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fsa4480_unreg_notifier @ 0010b0d8 size=1
// signature: undefined fsa4480_unreg_notifier(void)
// callers: [wcd_mbhc_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fsa4480_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010b0e0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_card_jack_new @ 0010b0e8 size=1
// signature: undefined snd_soc_card_jack_new(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_card_jack_new(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0010b0f8 size=1
// signature: undefined init_timer_key(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010b100 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010b108 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010b110 size=1
// signature: undefined __mutex_init(void)
// callers: [wcd_mbhc_init, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_allocate @ 0010b118 size=1
// signature: undefined devm_extcon_dev_allocate(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_allocate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_register @ 0010b120 size=1
// signature: undefined devm_extcon_dev_register(void)
// callers: [wcd_mbhc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010b128 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd_mbhc_init, wcd_mbhc_get_plug_from_adc, wcd_measure_adc_once, wcd_mbhc_fw_read, wcd_correct_swch_plug, wcd_mbhc_adc_hs_rem_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 0010b130 size=1
// signature: undefined request_firmware(void)
// callers: [wcd_mbhc_fw_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010b138 size=1
// signature: undefined msleep(void)
// callers: [wcd_event_notify, wcd_correct_swch_plug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010b140 size=1
// signature: undefined complete(void)
// callers: [wcd_mbhc_btn_press_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 0010b148 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [wcd_mbhc_btn_press_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010b150 size=1
// signature: undefined queue_work_on(void)
// callers: [wcd_mbhc_adc_detect_plug_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0010b158 size=1
// signature: undefined cancel_work_sync(void)
// callers: [wcd_cancel_hs_detect_plug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



