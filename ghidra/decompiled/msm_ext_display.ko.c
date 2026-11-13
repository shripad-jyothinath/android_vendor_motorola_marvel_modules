// Decompiled by Ghidra 12.2
// Program: msm_ext_display.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_hdmi_register_audio_codec @ 001002b4 size=28
// signature: undefined msm_hdmi_register_audio_codec(void)
// callers: []
//------------------------------------------------------------

void msm_hdmi_register_audio_codec(void)

{
  msm_ext_disp_register_audio_codec();
  return;
}



//------------------------------------------------------------
// msm_ext_disp_register_audio_codec @ 001002d4 size=544
// signature: undefined msm_ext_disp_register_audio_codec(void)
// callers: [msm_hdmi_register_audio_codec]
//------------------------------------------------------------

undefined8 msm_ext_disp_register_audio_codec(long param_1,long param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 uVar12;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    puVar7 = &DAT_00101367;
  }
  else {
    lVar11 = *(long *)(param_1 + 0xa8);
    if (lVar11 != 0) {
      mutex_lock(lVar11 + 0x58);
      if (*(long *)(lVar11 + 0x28) == 0) {
        *(long *)(lVar11 + 0x28) = param_2;
        if (*(char *)(lVar11 + 0x88) != '\0') {
          *(undefined1 *)(lVar11 + 0x88) = 0;
          msm_ext_disp_update_audio_ops(lVar11,(undefined4 *)(lVar11 + 0x18));
          if (*(long *)(lVar11 + 0x28) == 0) {
            _printk(&DAT_00101550,"msm_ext_disp_process_audio");
          }
          else {
            if (1 < *(uint *)(lVar11 + 0x20)) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1004f4);
              (*pcVar5)();
            }
            uVar12 = *(undefined8 *)(lVar11 + (ulong)*(uint *)(lVar11 + 0x20) * 8 + 0x30);
            iVar6 = extcon_get_state(uVar12,*(undefined4 *)(lVar11 + 0x18));
            if ((iVar6 != 1) &&
               (iVar6 = extcon_set_state_sync(uVar12,*(undefined4 *)(lVar11 + 0x18),1), iVar6 != 0))
            {
              _printk(&DAT_00101340,"msm_ext_disp_process_audio",iVar6);
            }
          }
        }
        uVar12 = 0;
      }
      else {
        _printk(&DAT_001011f8,"msm_ext_disp_register_audio_codec");
        uVar12 = 0xffffffea;
      }
      mutex_unlock(lVar11 + 0x58);
      iVar6 = *(int *)(lVar11 + 0x18);
      if (iVar6 == -1) {
        return uVar12;
      }
      puVar9 = *(undefined8 **)(lVar11 + 0x48);
      do {
        if (puVar9 == (undefined8 *)(lVar11 + 0x48)) {
LAB_00100424:
          pcVar1 = "EXT_DISPLAY_TYPE_DP";
          if (iVar6 != 0x2c) {
            pcVar1 = "???";
          }
          pcVar2 = "EXT_DISPLAY_TYPE_HDMI";
          if (iVar6 != 0x28) {
            pcVar2 = pcVar1;
          }
          _printk(&DAT_001012b9,"msm_ext_disp_ready_for_display",pcVar2);
          return uVar12;
        }
        piVar8 = (int *)puVar9[-1];
        if (((*piVar8 == iVar6) && (piVar8[2] == *(int *)(lVar11 + 0x20))) &&
           (piVar8[1] == *(int *)(lVar11 + 0x1c))) {
          if (piVar8 != (int *)0x0) {
            uVar3 = *(undefined8 *)(piVar8 + 0xe);
            puVar9 = *(undefined8 **)(lVar11 + 0x28);
            uVar10 = *(undefined8 *)(piVar8 + 10);
            puVar9[1] = *(undefined8 *)(piVar8 + 0xc);
            puVar9[2] = uVar3;
            *puVar9 = uVar10;
            uVar10 = *(undefined8 *)(piVar8 + 0x16);
            uVar3 = *(undefined8 *)(piVar8 + 0x10);
            uVar4 = *(undefined8 *)(piVar8 + 0x12);
            puVar9[5] = *(undefined8 *)(piVar8 + 0x14);
            puVar9[6] = uVar10;
            puVar9[3] = uVar3;
            puVar9[4] = uVar4;
            if (*(int *)(*(code **)(piVar8 + 0x16) + -4) != 0x63df1691) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10041c);
              (*pcVar5)();
            }
            (**(code **)(piVar8 + 0x16))(*(undefined8 *)(lVar11 + 0x10));
            return uVar12;
          }
          goto LAB_00100424;
        }
        puVar9 = (undefined8 *)*puVar9;
      } while( true );
    }
    puVar7 = &DAT_00101518;
  }
  _printk(puVar7,"msm_ext_disp_register_audio_codec");
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_ext_disp_update_audio_ops @ 001004f4 size=292
// signature: undefined msm_ext_disp_update_audio_ops(void)
// callers: [msm_ext_disp_register_audio_codec]
//------------------------------------------------------------

void msm_ext_disp_update_audio_ops(undefined8 *param_1,int *param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  int *piVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  if (param_2 == (int *)0x0) {
    _printk(&DAT_00101367,"msm_ext_disp_get_intf_data");
  }
  else {
    puVar5 = param_1 + 9;
    puVar6 = (undefined8 *)*puVar5;
    if (puVar6 != puVar5) {
      do {
        piVar4 = (int *)puVar6[-1];
        if (((*piVar4 == *param_2) && (piVar4[2] == param_2[2])) && (piVar4[1] == param_2[1])) {
          if (piVar4 != (int *)0x0) {
            puVar5 = (undefined8 *)param_1[5];
            if (puVar5 == (undefined8 *)0x0) {
              return;
            }
            uVar7 = *(undefined8 *)(piVar4 + 0xe);
            uVar8 = *(undefined8 *)(piVar4 + 10);
            puVar5[1] = *(undefined8 *)(piVar4 + 0xc);
            puVar5[2] = uVar7;
            *puVar5 = uVar8;
            uVar8 = *(undefined8 *)(piVar4 + 0x16);
            uVar7 = *(undefined8 *)(piVar4 + 0x10);
            uVar3 = *(undefined8 *)(piVar4 + 0x12);
            puVar5[5] = *(undefined8 *)(piVar4 + 0x14);
            puVar5[6] = uVar8;
            puVar5[3] = uVar7;
            puVar5[4] = uVar3;
            uVar7 = *(undefined8 *)param_2;
            *(int *)(param_1 + 4) = param_2[2];
            param_1[3] = uVar7;
            *param_1 = *(undefined8 *)(piVar4 + 0x18);
            param_1[1] = *(undefined8 *)(piVar4 + 0x1a);
            return;
          }
          break;
        }
        puVar6 = (undefined8 *)*puVar6;
      } while (puVar6 != puVar5);
    }
  }
  pcVar1 = "EXT_DISPLAY_TYPE_DP";
  if (*param_2 != 0x2c) {
    pcVar1 = "???";
  }
  pcVar2 = "EXT_DISPLAY_TYPE_HDMI";
  if (*param_2 != 0x28) {
    pcVar2 = pcVar1;
  }
  _printk(&DAT_00101451,"msm_ext_disp_update_audio_ops",pcVar2,param_2[1],param_2[2]);
  return;
}



//------------------------------------------------------------
// msm_ext_disp_select_audio_codec @ 0010061c size=404
// signature: undefined msm_ext_disp_select_audio_codec(void)
// callers: [msm_ext_disp_audio_config]
//------------------------------------------------------------

undefined8 msm_ext_disp_select_audio_codec(long param_1,int *param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  int *piVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    puVar5 = &DAT_00101367;
  }
  else {
    puVar11 = *(undefined8 **)(param_1 + 0xa8);
    if (puVar11 != (undefined8 *)0x0) {
      mutex_lock(puVar11 + 0xb);
      puVar6 = (undefined8 *)puVar11[5];
      if (puVar6 == (undefined8 *)0x0) {
        _printk(&DAT_001010e8,"msm_ext_disp_select_audio_codec");
        *(undefined1 *)(puVar11 + 0x11) = 1;
        iVar4 = param_2[2];
        uVar10 = 0xffffffea;
        puVar11[3] = *(undefined8 *)param_2;
        *(int *)(puVar11 + 4) = iVar4;
      }
      else {
        iVar4 = *param_2;
        for (puVar8 = (undefined8 *)puVar11[9]; puVar8 != puVar11 + 9;
            puVar8 = (undefined8 *)*puVar8) {
          piVar7 = (int *)puVar8[-1];
          if (((*piVar7 == iVar4) && (piVar7[2] == param_2[2])) && (piVar7[1] == param_2[1])) {
            if (piVar7 != (int *)0x0) {
              uVar10 = *(undefined8 *)(piVar7 + 0xe);
              uVar9 = *(undefined8 *)(piVar7 + 10);
              puVar6[1] = *(undefined8 *)(piVar7 + 0xc);
              puVar6[2] = uVar10;
              *puVar6 = uVar9;
              uVar9 = *(undefined8 *)(piVar7 + 0x16);
              uVar10 = *(undefined8 *)(piVar7 + 0x10);
              uVar3 = *(undefined8 *)(piVar7 + 0x12);
              puVar6[5] = *(undefined8 *)(piVar7 + 0x14);
              puVar6[6] = uVar9;
              puVar6[3] = uVar10;
              puVar6[4] = uVar3;
              uVar9 = *(undefined8 *)param_2;
              uVar10 = 0;
              *(int *)(puVar11 + 4) = param_2[2];
              puVar11[3] = uVar9;
              *puVar11 = *(undefined8 *)(piVar7 + 0x18);
              puVar11[1] = *(undefined8 *)(piVar7 + 0x1a);
              goto LAB_00100734;
            }
            break;
          }
        }
        pcVar1 = "EXT_DISPLAY_TYPE_DP";
        if (iVar4 != 0x2c) {
          pcVar1 = "???";
        }
        pcVar2 = "EXT_DISPLAY_TYPE_HDMI";
        if (iVar4 != 0x28) {
          pcVar2 = pcVar1;
        }
        _printk(&DAT_00101451,"msm_ext_disp_update_audio_ops",pcVar2,param_2[1],param_2[2]);
        uVar10 = 0xffffffed;
      }
LAB_00100734:
      mutex_unlock(puVar11 + 0xb);
      return uVar10;
    }
    puVar5 = &DAT_00101518;
  }
  _printk(puVar5,"msm_ext_disp_select_audio_codec");
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_ext_disp_register_intf @ 001007b4 size=528
// signature: undefined msm_ext_disp_register_intf(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_ext_disp_register_intf(long param_1,int *param_2)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  int iVar8;
  long *plVar9;
  int *piVar10;
  long lVar11;
  long *plVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  long lVar15;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    puVar7 = &DAT_00101367;
LAB_0010091c:
    _printk(puVar7,"msm_ext_disp_register_intf");
    return 0xffffffea;
  }
  lVar11 = *(long *)(param_1 + 0xa8);
  if (lVar11 == 0) {
    puVar7 = &DAT_00101518;
    goto LAB_0010091c;
  }
  mutex_lock(lVar11 + 0x58);
  if (*(long *)(param_2 + 0x18) == 0) {
    puVar6 = &DAT_00101218;
LAB_001008f0:
    _printk(puVar6,"msm_ext_disp_validate_intf");
  }
  else {
    iVar3 = *param_2;
    iVar8 = param_2[1];
    if ((iVar3 != -1) && (iVar8 == 0)) {
      if (param_2[2] < 2) {
        if (((((*(long *)(param_2 + 10) != 0) && (*(long *)(param_2 + 0xc) != 0)) &&
             (*(long *)(param_2 + 0xe) != 0)) &&
            ((*(long *)(param_2 + 0x10) != 0 && (*(long *)(param_2 + 0x12) != 0)))) &&
           ((*(long *)(param_2 + 0x14) != 0 && (*(long *)(param_2 + 0x16) != 0)))) {
          plVar12 = (long *)(lVar11 + 0x48);
          for (plVar9 = (long *)*plVar12; plVar9 != plVar12; plVar9 = (long *)*plVar9) {
            piVar10 = (int *)plVar9[-1];
            if (((*piVar10 == iVar3) && (piVar10[2] == param_2[2])) && (piVar10[1] == 0)) {
              if (piVar10 != (int *)0x0) {
                pcVar1 = "EXT_DISPLAY_TYPE_DP";
                if (iVar3 != 0x2c) {
                  pcVar1 = "???";
                }
                pcVar2 = "EXT_DISPLAY_TYPE_HDMI";
                if (iVar3 != 0x28) {
                  pcVar2 = pcVar1;
                }
                _printk(&DAT_001014a5,"msm_ext_disp_register_intf",pcVar2,0);
                uVar13 = 0;
                goto LAB_00100958;
              }
              break;
            }
          }
          puVar4 = (undefined8 *)kmalloc_trace(_devm_kmalloc,0xdc0,0x18);
          if (puVar4 == (undefined8 *)0x0) {
            uVar13 = 0xfffffff4;
          }
          else {
            puVar14 = puVar4 + 1;
            *puVar4 = param_2;
            lVar15 = *plVar12;
            uVar5 = __list_add_valid(puVar14,plVar12,lVar15);
            if ((uVar5 & 1) != 0) {
              *(undefined8 **)(lVar15 + 8) = puVar14;
              puVar4[1] = lVar15;
              puVar4[2] = plVar12;
              *plVar12 = (long)puVar14;
            }
            uVar13 = 0;
            *(code **)(param_2 + 4) = msm_ext_disp_audio_config;
            *(code **)(param_2 + 6) = msm_ext_disp_audio_notify;
          }
          goto LAB_00100958;
        }
        puVar6 = &DAT_0010157f;
        goto LAB_001008f0;
      }
      iVar8 = 0;
    }
    _printk(&DAT_00101122,"msm_ext_disp_validate_intf",iVar3,iVar8);
  }
  uVar13 = 0xffffffea;
LAB_00100958:
  mutex_unlock(lVar11 + 0x58);
  return uVar13;
}



//------------------------------------------------------------
// msm_ext_disp_audio_config @ 001009c8 size=252
// signature: undefined msm_ext_disp_audio_config(void)
// callers: []
//------------------------------------------------------------

ulong msm_ext_disp_audio_config(long param_1,int *param_2,uint param_3)

{
  undefined *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  
  if (param_1 == 0) {
    puVar1 = &DAT_0010115a;
LAB_00100aa0:
    _printk(puVar1,"msm_ext_disp_validate_and_get");
  }
  else {
    if ((((param_2 == (int *)0x0) || (*param_2 == -1)) || (param_2[1] != 0)) || (1 < param_2[2])) {
      puVar1 = &DAT_00101179;
      goto LAB_00100aa0;
    }
    if (param_3 < 2) {
      uVar3 = *(ulong *)(param_1 + 0xa8);
      if (uVar3 != 0) {
        if (uVar3 < 0xfffffffffffff001) {
          if (param_3 == 1) {
            uVar3 = msm_ext_disp_select_audio_codec();
            uVar3 = uVar3 & 0xffffffff;
          }
          else {
            mutex_lock(uVar3 + 0x58);
            puVar2 = *(undefined8 **)(uVar3 + 0x28);
            if (puVar2 != (undefined8 *)0x0) {
              puVar2[5] = 0;
              puVar2[6] = 0;
              puVar2[3] = 0;
              puVar2[4] = 0;
              puVar2[1] = 0;
              puVar2[2] = 0;
              *puVar2 = 0;
            }
            *(undefined4 *)(uVar3 + 0x18) = 0xffffffff;
            mutex_unlock(uVar3 + 0x58);
            uVar3 = 0;
          }
        }
        goto LAB_00100ab0;
      }
      puVar1 = &DAT_00101254;
      goto LAB_00100aa0;
    }
    _printk(&DAT_00101304,"msm_ext_disp_validate_and_get");
  }
  uVar3 = 0xffffffffffffffea;
LAB_00100ab0:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// msm_ext_disp_audio_notify @ 00100ac8 size=368
// signature: undefined msm_ext_disp_audio_notify(void)
// callers: []
//------------------------------------------------------------

ulong msm_ext_disp_audio_notify(long param_1,int *param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  undefined *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  
  if (param_1 == 0) {
    puVar5 = &DAT_0010115a;
LAB_00100bd4:
    _printk(puVar5,"msm_ext_disp_validate_and_get");
  }
  else {
    if ((((param_2 == (int *)0x0) || (*param_2 == -1)) || (param_2[1] != 0)) || (1 < param_2[2])) {
      puVar5 = &DAT_00101179;
      goto LAB_00100bd4;
    }
    if (param_3 < 2) {
      uVar6 = *(ulong *)(param_1 + 0xa8);
      if (uVar6 != 0) {
        if (uVar6 < 0xfffffffffffff001) {
          lVar1 = uVar6 + 0x58;
          mutex_lock(lVar1);
          if (*(long *)(uVar6 + 0x28) == 0) {
            _printk(&DAT_00101550,"msm_ext_disp_process_audio");
            uVar6 = 0xffffffff;
          }
          else {
            if (1 < (uint)param_2[2]) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100c38);
              (*pcVar2)();
            }
            uVar7 = *(undefined8 *)(uVar6 + (ulong)(uint)param_2[2] * 8 + 0x30);
            uVar3 = extcon_get_state(uVar7,*param_2);
            if (uVar3 == (param_3 != 0)) {
              uVar6 = 0xffffffef;
            }
            else {
              uVar4 = extcon_set_state_sync(uVar7,*param_2,param_3 != 0);
              uVar6 = uVar4 & 0xffffffff;
              if ((int)uVar4 != 0) {
                _printk(&DAT_00101340,"msm_ext_disp_process_audio",uVar6);
              }
            }
          }
          mutex_unlock(lVar1);
        }
        goto LAB_00100be4;
      }
      puVar5 = &DAT_00101254;
      goto LAB_00100bd4;
    }
    _printk(&DAT_00101304,"msm_ext_disp_validate_and_get",param_3);
  }
  uVar6 = 0xffffffffffffffea;
LAB_00100be4:
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// msm_ext_disp_deregister_intf @ 00100c3c size=216
// signature: undefined msm_ext_disp_deregister_intf(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ext_disp_deregister_intf(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined1 *puVar4;
  long lVar5;
  long *plVar6;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    puVar4 = &DAT_00101367;
  }
  else {
    lVar5 = *(long *)(param_1 + 0xa8);
    if (lVar5 != 0) {
      mutex_lock(lVar5 + 0x58);
      plVar6 = (long *)(lVar5 + 0x48);
      do {
        plVar6 = (long *)*plVar6;
        if (plVar6 == (long *)(lVar5 + 0x48)) goto LAB_00100cc8;
      } while (plVar6[-1] != param_2);
      uVar3 = __list_del_entry_valid(plVar6);
      if ((uVar3 & 1) != 0) {
        lVar1 = *plVar6;
        plVar2 = (long *)plVar6[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      kfree(plVar6 + -1);
LAB_00100cc8:
      *(undefined8 *)(param_2 + 0x10) = 0;
      *(undefined8 *)(param_2 + 0x18) = 0;
      mutex_unlock(lVar5 + 0x58);
      return 0;
    }
    puVar4 = &DAT_00101518;
  }
  _printk(puVar4,"msm_ext_disp_deregister_intf");
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_ext_disp_probe @ 00100d18 size=540
// signature: undefined msm_ext_disp_probe(void)
// callers: []
//------------------------------------------------------------

ulong msm_ext_disp_probe(long param_1)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  undefined *puVar5;
  long lVar6;
  
  if (param_1 == 0) {
    puVar5 = &DAT_001015a7;
  }
  else {
    lVar6 = *(long *)(param_1 + 0x2f8);
    if (lVar6 != 0) {
      lVar1 = param_1 + 0x10;
      lVar2 = devm_kmalloc(lVar1,0x90,0xdc0);
      if (lVar2 == 0) {
        uVar3 = 0xfffffff4;
        goto LAB_00100e94;
      }
      *(long *)(param_1 + 0xa8) = lVar2;
      *(long *)(lVar2 + 0x10) = param_1;
      uVar3 = devm_extcon_dev_allocate(lVar1,msm_ext_disp_supported_cable);
      *(ulong *)(lVar2 + 0x30) = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        uVar3 = devm_extcon_dev_register(*(long *)(lVar2 + 0x10) + 0x10,uVar3);
        if ((int)uVar3 == 0) goto LAB_00100da4;
LAB_00100eac:
        uVar3 = uVar3 & 0xffffffff;
        _printk(&DAT_001013e8,"msm_ext_disp_extcon_register");
      }
      else if ((int)uVar3 == 0) {
LAB_00100da4:
        if (*(long *)(lVar2 + 0x10) == 0) {
          _printk(&DAT_001011c5,"msm_ext_disp_extcon_register");
          uVar3 = 0xffffffea;
        }
        else {
          uVar3 = devm_extcon_dev_allocate
                            (*(long *)(lVar2 + 0x10) + 0x10,msm_ext_disp_supported_cable);
          *(ulong *)(lVar2 + 0x38) = uVar3;
          if (uVar3 < 0xfffffffffffff001) {
            uVar3 = devm_extcon_dev_register(*(long *)(lVar2 + 0x10) + 0x10,uVar3);
            if ((int)uVar3 != 0) goto LAB_00100eac;
          }
          else if ((int)uVar3 != 0) goto LAB_00100dd0;
          uVar4 = of_platform_populate(lVar6,0,0,lVar1);
          uVar3 = uVar4 & 0xffffffff;
          if ((int)uVar4 == 0) {
            __mutex_init(lVar2 + 0x58,"&ext_disp->lock",&msm_ext_disp_probe___key);
            *(long *)(lVar2 + 0x48) = lVar2 + 0x48;
            *(long *)(lVar2 + 0x50) = lVar2 + 0x48;
            *(undefined4 *)(lVar2 + 0x18) = 0xffffffff;
            *(undefined1 *)(lVar2 + 0x88) = 0;
            goto LAB_00100e94;
          }
          _printk(&DAT_0010128a,"msm_ext_disp_probe",uVar3);
        }
      }
LAB_00100dd0:
      if (*(long *)(lVar2 + 0x10) == 0) {
        _printk(&DAT_00101367,"msm_ext_disp_extcon_unregister");
        lVar6 = *(long *)(lVar2 + 0x10);
        if (lVar6 != 0) goto LAB_00100dec;
LAB_00100f00:
        _printk(&DAT_00101367,"msm_ext_disp_extcon_unregister");
      }
      else {
        devm_extcon_dev_unregister(*(long *)(lVar2 + 0x10) + 0x10,*(undefined8 *)(lVar2 + 0x30));
        lVar6 = *(long *)(lVar2 + 0x10);
        if (lVar6 == 0) goto LAB_00100f00;
LAB_00100dec:
        devm_extcon_dev_unregister(lVar6 + 0x10,*(undefined8 *)(lVar2 + 0x38));
      }
      devm_kfree(*(long *)(lVar2 + 0x10) + 0x10,lVar2);
      goto LAB_00100e94;
    }
    puVar5 = &DAT_001012e8;
  }
  _printk(puVar5,"msm_ext_disp_probe");
  uVar3 = 0xffffffed;
LAB_00100e94:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// msm_ext_disp_remove @ 00100f38 size=196
// signature: undefined msm_ext_disp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ext_disp_remove(long param_1)

{
  undefined *puVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 == 0) {
    puVar1 = &DAT_00101421;
  }
  else {
    lVar3 = *(long *)(param_1 + 0xa8);
    if (lVar3 != 0) {
      if (*(long *)(lVar3 + 0x10) == 0) {
        _printk(&DAT_00101367,"msm_ext_disp_extcon_unregister");
        lVar2 = *(long *)(lVar3 + 0x10);
      }
      else {
        devm_extcon_dev_unregister(*(long *)(lVar3 + 0x10) + 0x10,*(undefined8 *)(lVar3 + 0x30));
        lVar2 = *(long *)(lVar3 + 0x10);
      }
      if (lVar2 == 0) {
        _printk(&DAT_00101367,"msm_ext_disp_extcon_unregister");
      }
      else {
        devm_extcon_dev_unregister(lVar2 + 0x10,*(undefined8 *)(lVar3 + 0x38));
      }
      devm_kfree(*(long *)(lVar3 + 0x10) + 0x10,lVar3);
      return 0;
    }
    puVar1 = &DAT_00101199;
  }
  _printk(puVar1,"msm_ext_disp_remove");
  return 0xffffffed;
}



//------------------------------------------------------------
// init_module @ 0010107c size=92
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&this_driver,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_00101409,"msm_ext_disp_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_ext_disp_register_intf, msm_ext_disp_deregister_intf, msm_ext_disp_select_audio_codec, msm_ext_disp_audio_config, msm_ext_disp_audio_notify, msm_ext_disp_register_audio_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_get_state @ 00103008 size=1
// signature: undefined extcon_get_state(void)
// callers: [msm_ext_disp_audio_notify, msm_ext_disp_register_audio_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_set_state_sync @ 00103010 size=1
// signature: undefined extcon_set_state_sync(void)
// callers: [msm_ext_disp_audio_notify, msm_ext_disp_register_audio_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_set_state_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103018 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_ext_disp_register_intf, msm_ext_disp_deregister_intf, msm_ext_disp_select_audio_codec, msm_ext_disp_audio_config, msm_ext_disp_audio_notify, msm_ext_disp_register_audio_codec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103020 size=1
// signature: undefined _printk(void)
// callers: [msm_ext_disp_register_intf, msm_ext_disp_probe, msm_ext_disp_remove, msm_ext_disp_deregister_intf, msm_ext_disp_select_audio_codec, msm_ext_disp_audio_config, msm_ext_disp_audio_notify, msm_ext_disp_register_audio_codec, msm_ext_disp_update_audio_ops, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103030 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_ext_disp_register_intf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103038 size=1
// signature: undefined __list_add_valid(void)
// callers: [msm_ext_disp_register_intf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103040 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [msm_ext_disp_deregister_intf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103048 size=1
// signature: undefined kfree(void)
// callers: [msm_ext_disp_deregister_intf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103050 size=1
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
// devm_kmalloc @ 00103058 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_ext_disp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_allocate @ 00103060 size=1
// signature: undefined devm_extcon_dev_allocate(void)
// callers: [msm_ext_disp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_allocate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_register @ 00103068 size=1
// signature: undefined devm_extcon_dev_register(void)
// callers: [msm_ext_disp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_unregister @ 00103070 size=1
// signature: undefined devm_extcon_dev_unregister(void)
// callers: [msm_ext_disp_probe, msm_ext_disp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00103078 size=1
// signature: undefined devm_kfree(void)
// callers: [msm_ext_disp_probe, msm_ext_disp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00103080 size=1
// signature: undefined of_platform_populate(void)
// callers: [msm_ext_disp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103088 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_ext_disp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



