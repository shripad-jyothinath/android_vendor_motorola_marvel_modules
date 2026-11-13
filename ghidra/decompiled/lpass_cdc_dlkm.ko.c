// Decompiled by Ghidra 12.2
// Program: lpass_cdc_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_cdc_set_port_map @ 00100eb4 size=284
// signature: undefined lpass_cdc_set_port_map(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_set_port_map(long param_1,uint param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 *puVar4;
  long *plVar5;
  uint uVar6;
  
  uVar2 = 0xffffffea;
  if ((((param_1 != 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (plVar5 = *(long **)(*(long *)(param_1 + 0x18) + 0x98), plVar5 != (long *)0x0)) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(*plVar5 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 == 0) {
      iVar1 = ___ratelimit(&lpass_cdc_set_port_map__rs,"lpass_cdc_set_port_map");
      if (iVar1 != 0) {
        _dev_err(*plVar5,"%s: invalid codec\n","lpass_cdc_set_port_map");
      }
      uVar2 = 0xffffffea;
    }
    else {
      uVar6 = 0;
      puVar4 = (undefined4 *)(param_3 + 4);
      do {
        if (4 < (uint)puVar4[-1]) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100fd0);
          (*pcVar3)();
        }
        pcVar3 = (code *)plVar5[(ulong)(uint)puVar4[-1] * 0xe + 0x25];
        if (pcVar3 != (code *)0x0) {
          if (*(int *)(pcVar3 + -4) != 0x7082ea1) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100f6c);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,*puVar4,0xd,*(undefined8 *)(puVar4 + 1));
        }
        uVar6 = uVar6 + 1;
        puVar4 = puVar4 + 4;
      } while ((uVar6 & 0xffff) < param_2);
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_clear_amic_tx_hold @ 00100fd4 size=180
// signature: undefined lpass_cdc_clear_amic_tx_hold(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_clear_amic_tx_hold(long param_1,short param_2)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (param_1 == 0) {
    puVar2 = &DAT_0010ab17;
  }
  else {
    iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 != 0) {
      lVar3 = *(long *)(param_1 + 0x98);
      if (lVar3 == 0) {
        _dev_err(param_1,"%s: priv is null\n","lpass_cdc_clear_amic_tx_hold");
        return;
      }
      if ((ushort)(param_2 - 1U) < 4) {
        blocking_notifier_call_chain
                  (lVar3 + 0x400,*(undefined8 *)(&DAT_0010b4e8 + (long)(short)(param_2 - 1U) * 8),
                   *(undefined8 *)(lVar3 + 0x3f8));
        return;
      }
      return;
    }
    puVar2 = &DAT_0010aa83;
  }
  _printk(puVar2,"lpass_cdc_clear_amic_tx_hold");
  return;
}



//------------------------------------------------------------
// lpass_cdc_get_device_ptr @ 0010108c size=244
// signature: undefined lpass_cdc_get_device_ptr(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_get_device_ptr(long param_1,ushort param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_get_device_ptr__rs,"lpass_cdc_get_device_ptr");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0010ab17;
  }
  else {
    iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 != 0) {
      if ((param_2 < 5) && (*(long *)(param_1 + 0x98) != 0)) {
        return *(undefined8 *)(*(long *)(param_1 + 0x98) + (ulong)param_2 * 0x70 + 0x100);
      }
      iVar1 = ___ratelimit(lpass_cdc_get_device_ptr__rs_5,"lpass_cdc_get_device_ptr");
      if (iVar1 == 0) {
        return 0;
      }
      _dev_err(param_1,"%s: priv is null or invalid macro\n","lpass_cdc_get_device_ptr");
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_get_device_ptr__rs_4,"lpass_cdc_get_device_ptr");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0010aa83;
  }
  _printk(puVar2,"lpass_cdc_get_device_ptr");
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_get_rsc_clk_device_ptr @ 00101184 size=216
// signature: undefined lpass_cdc_get_rsc_clk_device_ptr(void)
// callers: [lpass_cdc_clk_rsc_fs_gen_request, lpass_cdc_clk_rsc_request_clock, lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_rsc_clk_reset]
//------------------------------------------------------------

undefined8 lpass_cdc_get_rsc_clk_device_ptr(long param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_get_rsc_clk_device_ptr__rs,"lpass_cdc_get_rsc_clk_device_ptr");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0010ab17;
  }
  else {
    iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 != 0) {
      if (*(long *)(param_1 + 0x98) != 0) {
        return *(undefined8 *)(*(long *)(param_1 + 0x98) + 0x448);
      }
      iVar1 = ___ratelimit(lpass_cdc_get_rsc_clk_device_ptr__rs_8,"lpass_cdc_get_rsc_clk_device_ptr"
                          );
      if (iVar1 == 0) {
        return 0;
      }
      _dev_err(param_1,"%s: priv is null\n","lpass_cdc_get_rsc_clk_device_ptr");
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_get_rsc_clk_device_ptr__rs_7,"lpass_cdc_get_rsc_clk_device_ptr");
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = &DAT_0010aa83;
  }
  _printk(puVar2,"lpass_cdc_get_rsc_clk_device_ptr");
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_register_res_clk @ 00101260 size=260
// signature: undefined lpass_cdc_register_res_clk(void)
// callers: [lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

undefined8 lpass_cdc_register_res_clk(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar1 = ___ratelimit(lpass_cdc_register_res_clk__rs,"lpass_cdc_register_res_clk");
    if (iVar1 != 0) {
      _printk(&DAT_0010a6a5,"lpass_cdc_register_res_clk");
    }
  }
  else {
    iVar1 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 == 0) {
      iVar1 = ___ratelimit(lpass_cdc_register_res_clk__rs_10,"lpass_cdc_register_res_clk");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: child device :%pK not added yet\n","lpass_cdc_register_res_clk",
                 param_1);
      }
    }
    else {
      lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
      if (lVar2 != 0) {
        *(long *)(lVar2 + 0x448) = param_1;
        *(long *)(lVar2 + 0x450) = param_2;
        return 0;
      }
      iVar1 = ___ratelimit(lpass_cdc_register_res_clk__rs_12,"lpass_cdc_register_res_clk");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: priv is null\n","lpass_cdc_register_res_clk");
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_unregister_res_clk @ 00101368 size=244
// signature: undefined lpass_cdc_unregister_res_clk(void)
// callers: [lpass_cdc_clk_rsc_remove]
//------------------------------------------------------------

void lpass_cdc_unregister_res_clk(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_unregister_res_clk__rs,"lpass_cdc_unregister_res_clk");
    if (iVar1 != 0) {
      _printk(&DAT_0010a961,"lpass_cdc_unregister_res_clk");
    }
  }
  else {
    iVar1 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 == 0) {
      iVar1 = ___ratelimit(lpass_cdc_unregister_res_clk__rs_14,"lpass_cdc_unregister_res_clk");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: child device :%pK not added\n","lpass_cdc_unregister_res_clk",param_1)
        ;
      }
    }
    else {
      lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
      if (lVar2 == 0) {
        iVar1 = ___ratelimit(lpass_cdc_unregister_res_clk__rs_16,"lpass_cdc_unregister_res_clk");
        if (iVar1 != 0) {
          _dev_err(param_1,"%s: priv is null\n","lpass_cdc_unregister_res_clk");
        }
      }
      else {
        *(undefined8 *)(lVar2 + 0x450) = 0;
        *(undefined8 *)(lVar2 + 0x448) = 0;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_dmic_clk_enable @ 00101460 size=796
// signature: undefined lpass_cdc_dmic_clk_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_dmic_clk_enable(long param_1,uint param_2,int param_3,ulong param_4)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  byte *pbVar9;
  byte bVar10;
  int *piVar11;
  
  if (7 < param_2) {
    iVar3 = ___ratelimit(lpass_cdc_dmic_clk_enable__rs,"lpass_cdc_dmic_clk_enable");
    if (iVar3 == 0) {
      return 0xffffffea;
    }
    _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: Invalid DMIC Selection\n",
             "lpass_cdc_dmic_clk_enable");
    return 0xffffffea;
  }
  lVar5 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  switch(param_2) {
  default:
    piVar11 = (int *)(lVar5 + 0x458);
    pbVar9 = (byte *)(lVar5 + 0x468);
    uVar8 = 1;
    uVar7 = 0x3084;
    if ((param_4 & 1) != 0) goto LAB_00101560;
    goto LAB_001014f0;
  case 2:
  case 3:
    piVar11 = (int *)(lVar5 + 0x45c);
    pbVar9 = (byte *)(lVar5 + 0x469);
    uVar8 = 2;
    uVar7 = 0x3088;
    break;
  case 4:
  case 5:
    piVar11 = (int *)(lVar5 + 0x460);
    pbVar9 = (byte *)(lVar5 + 0x46a);
    uVar8 = 4;
    uVar7 = 0x308c;
    break;
  case 6:
  case 7:
    piVar11 = (int *)(lVar5 + 0x464);
    pbVar9 = (byte *)(lVar5 + 0x46b);
    uVar8 = 8;
    uVar7 = 0x3090;
  }
  if ((param_4 & 1) == 0) {
LAB_001014f0:
    iVar3 = *piVar11;
    *piVar11 = iVar3 + -1;
    if (iVar3 + -1 == 0) {
      snd_soc_component_update_bits(param_1,uVar7,1,0);
      snd_soc_component_update_bits(param_1,uVar7,0xe,0);
      bVar10 = 0;
    }
    else {
      lVar5 = 0;
      if (param_3 != 0) {
        lVar5 = 0x150;
      }
      pcVar6 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + lVar5 + 0x130);
      if (pcVar6 == (code *)0x0) {
        uVar2 = 1;
      }
      else {
        if (*(int *)(pcVar6 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10153c);
          (*pcVar6)();
        }
        uVar2 = (*pcVar6)(param_1);
        if ((int)uVar2 < 0) {
          uVar2 = 1;
        }
      }
      bVar10 = *pbVar9;
      if ((uVar2 & 0xff) < (uint)bVar10) {
        lVar5 = 0x150;
        if (param_3 != 0) {
          lVar5 = 0;
        }
        pcVar6 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x98) + lVar5 + 0x130);
        if (pcVar6 == (code *)0x0) {
          uVar2 = 1;
        }
        else {
          if (*(int *)(pcVar6 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1016e8);
            (*pcVar6)();
          }
          uVar2 = (*pcVar6)(param_1);
          if ((int)uVar2 < 0) {
            uVar2 = 1;
          }
        }
        bVar10 = (byte)uVar2;
        snd_soc_component_update_bits(param_1,0x3094,uVar8,uVar8);
        snd_soc_component_update_bits(param_1,uVar7,0xe,(uVar2 & 0xff) << 1);
        snd_soc_component_update_bits(param_1,0x3094,uVar8,0);
      }
    }
  }
  else {
LAB_00101560:
    lVar1 = 0;
    if (param_3 != 0) {
      lVar1 = 0x150;
    }
    pcVar6 = *(code **)(lVar5 + lVar1 + 0x130);
    if (pcVar6 == (code *)0x0) {
      uVar2 = 1;
    }
    else {
      if (*(int *)(pcVar6 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101594);
        (*pcVar6)();
      }
      uVar2 = (*pcVar6)(param_1);
      if ((int)uVar2 < 0) {
        uVar2 = 1;
      }
    }
    iVar3 = *piVar11;
    *piVar11 = iVar3 + 1;
    if (iVar3 == 0) {
      snd_soc_component_update_bits(param_1,0x3094,0x80,0);
      snd_soc_component_update_bits(param_1,uVar7,0xe,(uVar2 & 0xff) << 1);
      uVar8 = 1;
      uVar4 = 1;
    }
    else {
      bVar10 = *pbVar9;
      if ((uint)*pbVar9 <= (uVar2 & 0xff)) goto LAB_0010173c;
      snd_soc_component_update_bits(param_1,0x3094,uVar8,uVar8);
      snd_soc_component_update_bits(param_1,uVar7,0xe,(uVar2 & 0xff) << 1);
      uVar7 = 0x3094;
      uVar4 = 0;
    }
    snd_soc_component_update_bits(param_1,uVar7,uVar8,uVar4);
    bVar10 = (byte)uVar2;
  }
LAB_0010173c:
  *pbVar9 = bVar10;
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_is_va_macro_registered @ 00101780 size=236
// signature: undefined lpass_cdc_is_va_macro_registered(void)
// callers: []
//------------------------------------------------------------

ulong lpass_cdc_is_va_macro_registered(long param_1)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  long lVar4;
  
  if (param_1 == 0) {
    uVar2 = ___ratelimit(lpass_cdc_is_va_macro_registered__rs,"lpass_cdc_is_va_macro_registered");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    _printk(&DAT_0010ab17,"lpass_cdc_is_va_macro_registered");
    return 0;
  }
  iVar1 = of_device_is_compatible
                    (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
  if (iVar1 == 0) {
    uVar2 = ___ratelimit(lpass_cdc_is_va_macro_registered__rs_18,"lpass_cdc_is_va_macro_registered")
    ;
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    pcVar3 = "%s: child device calling is not added yet\n";
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    if (lVar4 != 0) {
      return (ulong)(*(char *)(lVar4 + 0xdc) != '\0');
    }
    uVar2 = ___ratelimit(lpass_cdc_is_va_macro_registered__rs_20,"lpass_cdc_is_va_macro_registered")
    ;
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    pcVar3 = "%s: priv is null\n";
  }
  _dev_err(param_1,pcVar3,"lpass_cdc_is_va_macro_registered");
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_register_macro @ 00101870 size=912
// signature: undefined lpass_cdc_register_macro(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_register_macro(long param_1,ushort param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  void *__dest;
  undefined8 *puVar4;
  ulong uVar5;
  
  if ((param_1 == 0) || (param_3 == (undefined8 *)0x0)) {
    _printk(&DAT_0010ab81,"lpass_cdc_register_macro");
  }
  else {
    iVar2 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
    if (iVar2 == 0) {
      _dev_err(param_1,"%s: child device for macro:%d not added yet\n","lpass_cdc_register_macro",
               param_2);
    }
    else {
      if ((param_2 < 5) &&
         (puVar4 = *(undefined8 **)(*(long *)(param_1 + 0x60) + 0x98), puVar4 != (undefined8 *)0x0))
      {
        uVar5 = (ulong)param_2;
        *(undefined2 *)(puVar4 + uVar5 * 0xe + 0x2a) = *(undefined2 *)(param_3 + 0xd);
        *(undefined2 *)((long)puVar4 + uVar5 * 0x70 + 0x152) = *(undefined2 *)((long)param_3 + 0x6a)
        ;
        puVar4[uVar5 * 0xe + 0x1d] = *param_3;
        puVar4[uVar5 * 0xe + 0x1e] = param_3[1];
        puVar4[uVar5 * 0xe + 0x29] = param_3[0xc];
        *(undefined2 *)(puVar4 + uVar5 * 0xe + 0x1f) = *(undefined2 *)(param_3 + 2);
        puVar4[uVar5 * 0xe + 0x21] = param_3[4];
        puVar4[uVar5 * 0xe + 0x23] = param_3[6];
        uVar3 = param_3[8];
        puVar4[uVar5 * 0xe + 0x20] = param_1;
        puVar4[uVar5 * 0xe + 0x25] = uVar3;
        *(undefined2 *)((long)puVar4 + (ulong)param_2 * 2 + 0x326) =
             *(undefined2 *)(lpass_cdc_mclk_mux_tbl + uVar5 * 4);
        if (param_2 == 3) {
          puVar4[0x50] = param_3[9];
          puVar4[0x4e] = param_3[7];
        }
        else if (param_2 == 0) {
          puVar4[0x24] = param_3[7];
          puVar4[0x27] = param_3[10];
          puVar4[0x28] = param_3[0xb];
          puVar4[0x26] = param_3[9];
        }
        puVar1 = puVar4 + 3;
        mutex_lock(puVar1);
        *(short *)(puVar4 + 100) = *(short *)(puVar4 + 100) + *(short *)(param_3 + 2);
        *(short *)((long)puVar4 + 0x322) = *(short *)((long)puVar4 + 0x322) + 1;
        *(undefined1 *)((long)puVar4 + uVar5 + 0xd9) = 1;
        _dev_info(param_1,"%s: register macro successful:%d\n","lpass_cdc_register_macro",param_2);
        if (*(short *)((long)puVar4 + 0x322) == *(short *)((long)puVar4 + 0x324)) {
          __dest = (void *)puVar4[99];
          if (__dest == (void *)0x0) {
            __dest = (void *)devm_kmalloc(*puVar4,(ulong)*(ushort *)(puVar4 + 100) * 0xe0,0xdc0);
            puVar4[99] = __dest;
            if (__dest == (void *)0x0) {
              _dev_err(param_1,"%s: copy_dais failed\n","lpass_cdc_register_macro");
              mutex_unlock(puVar1);
              return -0xc;
            }
          }
          if (puVar4[0x21] != 0) {
            memcpy(__dest,(void *)puVar4[0x21],(ulong)*(ushort *)(puVar4 + 0x1f) * 0xe0);
            __dest = (void *)((long)__dest + (ulong)*(ushort *)(puVar4 + 0x1f) * 0xe0);
          }
          if (puVar4[0x2f] != 0) {
            memcpy(__dest,(void *)puVar4[0x2f],(ulong)*(ushort *)(puVar4 + 0x2d) * 0xe0);
            __dest = (void *)((long)__dest + (ulong)*(ushort *)(puVar4 + 0x2d) * 0xe0);
          }
          if (puVar4[0x3d] != 0) {
            memcpy(__dest,(void *)puVar4[0x3d],(ulong)*(ushort *)(puVar4 + 0x3b) * 0xe0);
            __dest = (void *)((long)__dest + (ulong)*(ushort *)(puVar4 + 0x3b) * 0xe0);
          }
          if (puVar4[0x4b] != 0) {
            memcpy(__dest,(void *)puVar4[0x4b],(ulong)*(ushort *)(puVar4 + 0x49) * 0xe0);
            __dest = (void *)((long)__dest + (ulong)*(ushort *)(puVar4 + 0x49) * 0xe0);
          }
          if (puVar4[0x59] != 0) {
            memcpy(__dest,(void *)puVar4[0x59],(ulong)*(ushort *)(puVar4 + 0x57) * 0xe0);
          }
          if (*(char *)((long)puVar4 + 0xd9) == '\0') {
            lpass_cdc_mclk_mux_tbl._8_2_ = 2;
            *(undefined2 *)((long)puVar4 + 0x32a) = 2;
            lpass_cdc_mclk_mux_tbl._12_2_ = 3;
            *(undefined2 *)((long)puVar4 + 0x32c) = 3;
          }
          iVar2 = snd_soc_register_component
                            (*(undefined8 *)(param_1 + 0x60),&lpass_cdc,puVar4[99],
                             *(undefined2 *)(puVar4 + 100));
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: register codec failed\n","lpass_cdc_register_macro");
            mutex_unlock(puVar1);
            return iVar2;
          }
        }
        mutex_unlock(puVar1);
        return 0;
      }
      _dev_err(param_1,"%s: priv is null or invalid macro\n","lpass_cdc_register_macro");
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_unregister_macro @ 00101c04 size=360
// signature: undefined lpass_cdc_unregister_macro(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_unregister_macro(long param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_unregister_macro__rs,"lpass_cdc_unregister_macro");
    if (iVar2 == 0) {
      return;
    }
    _printk(&DAT_0010ab17,"lpass_cdc_unregister_macro");
    return;
  }
  iVar2 = of_device_is_compatible
                    (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
  if (iVar2 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_unregister_macro__rs_26,"lpass_cdc_unregister_macro");
    if (iVar2 == 0) {
      return;
    }
    _dev_err(param_1,"%s: macro:%d not in valid registered macro-list\n",
             "lpass_cdc_unregister_macro",param_2);
    return;
  }
  if ((4 < param_2) || (lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98), lVar3 == 0)) {
    iVar2 = ___ratelimit(lpass_cdc_unregister_macro__rs_28,"lpass_cdc_unregister_macro");
    if (iVar2 == 0) {
      return;
    }
    _dev_err(param_1,"%s: priv is null or invalid macro\n","lpass_cdc_unregister_macro");
    return;
  }
  lVar4 = lVar3 + (ulong)param_2 * 0x70;
  *(undefined8 *)(lVar4 + 0xe8) = 0;
  *(undefined2 *)(lVar4 + 0xf8) = 0;
  *(undefined8 *)(lVar4 + 0x118) = 0;
  *(undefined8 *)(lVar4 + 0x100) = 0;
  *(undefined8 *)(lVar4 + 0x108) = 0;
  if (param_2 != 3) {
    if (param_2 != 0) goto LAB_00101c98;
    *(undefined8 *)(lVar3 + 0x120) = 0;
    *(undefined8 *)(lVar3 + 0x138) = 0;
    *(undefined8 *)(lVar3 + 0x140) = 0;
  }
  *(undefined8 *)(lVar3 + (ulong)param_2 * 0x70 + 0x130) = 0;
LAB_00101c98:
  uVar1 = *(short *)(lVar3 + 0x322) - 1;
  *(ushort *)(lVar3 + 0x322) = uVar1;
  if (*(ushort *)(lVar3 + 0x324) - 1 == (uint)uVar1) {
    snd_soc_unregister_component(*(undefined8 *)(param_1 + 0x60));
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_notify_wcd_rx_clk @ 00101d70 size=252
// signature: undefined lpass_cdc_notify_wcd_rx_clk(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_notify_wcd_rx_clk(long param_1,ulong param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_notify_wcd_rx_clk__rs,"lpass_cdc_notify_wcd_rx_clk");
    if (iVar1 == 0) {
      return;
    }
    _printk(&DAT_0010ab17,"lpass_cdc_notify_wcd_rx_clk");
    return;
  }
  iVar1 = of_device_is_compatible
                    (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
  if (iVar1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_notify_wcd_rx_clk__rs_29,"lpass_cdc_notify_wcd_rx_clk");
    if (iVar1 == 0) {
      return;
    }
    pcVar2 = "%s: not a valid child dev\n";
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    if (lVar3 != 0) {
      uVar4 = 0x20007;
      if ((param_2 & 1) == 0) {
        uVar4 = 7;
      }
      blocking_notifier_call_chain(lVar3 + 0x400,uVar4,*(undefined8 *)(lVar3 + 0x3f8));
      return;
    }
    iVar1 = ___ratelimit(lpass_cdc_notify_wcd_rx_clk__rs_31,"lpass_cdc_notify_wcd_rx_clk");
    if (iVar1 == 0) {
      return;
    }
    pcVar2 = "%s: priv is null\n";
  }
  _dev_err(param_1,pcVar2,"lpass_cdc_notify_wcd_rx_clk");
  return;
}



//------------------------------------------------------------
// lpass_cdc_wsa_pa_on @ 00101e70 size=244
// signature: undefined lpass_cdc_wsa_pa_on(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_wsa_pa_on(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long lVar4;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_pa_on__rs,"lpass_cdc_wsa_pa_on");
    if (iVar1 == 0) {
      return;
    }
    _printk(&DAT_0010ab17,"lpass_cdc_wsa_pa_on");
    return;
  }
  iVar1 = of_device_is_compatible
                    (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
  if (iVar1 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_wsa_pa_on__rs_32,"lpass_cdc_wsa_pa_on");
    if (iVar1 == 0) {
      return;
    }
    pcVar3 = "%s: not a valid child dev\n";
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    if (lVar4 != 0) {
      if ((param_2 & 1) == 0) {
        uVar2 = 5;
      }
      else {
        uVar2 = 6;
      }
      blocking_notifier_call_chain(lVar4 + 0x400,uVar2,*(undefined8 *)(lVar4 + 0x3f8));
      return;
    }
    iVar1 = ___ratelimit(lpass_cdc_wsa_pa_on__rs_33,"lpass_cdc_wsa_pa_on");
    if (iVar1 == 0) {
      return;
    }
    pcVar3 = "%s: priv is null\n";
  }
  _dev_err(param_1,pcVar3,"lpass_cdc_wsa_pa_on");
  return;
}



//------------------------------------------------------------
// lpass_cdc_get_version @ 00101f68 size=152
// signature: undefined lpass_cdc_get_version(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_get_version(long param_1)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if (param_1 == 0) {
    _printk(&DAT_0010ab17,"lpass_cdc_get_version");
  }
  else {
    iVar1 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 == 0) {
      pcVar2 = "%s: child device for macro not added yet\n";
    }
    else {
      lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
      if (lVar3 != 0) {
        return *(undefined4 *)(lVar3 + 0x360);
      }
      pcVar2 = "%s: priv is null\n";
    }
    _dev_err(param_1,pcVar2,"lpass_cdc_get_version");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_info_create_codec_entry @ 00102004 size=284
// signature: undefined lpass_cdc_info_create_codec_entry(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_info_create_codec_entry(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x18) + 0x98);
    if (*(long *)(lVar5 + 0x388) == 0) {
      lVar4 = *(long *)(param_2 + 0x20);
      lVar3 = snd_info_create_module_entry(*(undefined8 *)(param_1 + 0x38),"lpass-cdc");
      *(long *)(lVar5 + 0x388) = lVar3;
      if (lVar3 != 0) {
        *(undefined2 *)(lVar3 + 8) = 0x416d;
        iVar1 = snd_info_register(*(undefined8 *)(lVar5 + 0x388));
        if (-1 < iVar1) {
          lVar3 = snd_info_create_card_entry
                            (*(undefined8 *)(lVar4 + 0x48),"version",*(undefined8 *)(lVar5 + 0x388))
          ;
          if (lVar3 == 0) {
            iVar1 = ___ratelimit(lpass_cdc_info_create_codec_entry__rs,
                                 "lpass_cdc_info_create_codec_entry");
            if (iVar1 != 0) {
              _dev_err(*(undefined8 *)(param_2 + 0x18),
                       "%s: failed to create lpass_cdc version entry\n",
                       "lpass_cdc_info_create_codec_entry");
            }
          }
          else {
            *(long *)(lVar3 + 0x40) = lVar5;
            *(undefined8 *)(lVar3 + 0x10) = 0x20;
            *(undefined2 *)(lVar3 + 0x18) = 1;
            *(undefined1 **)(lVar3 + 0x20) = lpass_cdc_info_ops;
            iVar1 = snd_info_register();
            if (-1 < iVar1) {
              *(long *)(lVar5 + 0x390) = lVar3;
              return 0;
            }
            snd_info_free_entry(lVar3);
          }
        }
        snd_info_free_entry(*(undefined8 *)(lVar5 + 0x388));
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
// lpass_cdc_register_wake_irq @ 00102124 size=196
// signature: undefined lpass_cdc_register_wake_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_register_wake_irq(long param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  long *plVar3;
  
  if ((param_1 != 0) &&
     (plVar3 = *(long **)(*(long *)(param_1 + 0x18) + 0x98), plVar3 != (long *)0x0)) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(*plVar3 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 != 0) {
      pcVar2 = (code *)plVar3[0x4e];
      if (pcVar2 != (code *)0x0) {
        if (*(int *)(pcVar2 + -4) != -0x10ef9e3) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102190);
          (*pcVar2)();
        }
        (*pcVar2)(param_1,param_2);
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_register_wake_irq__rs,"lpass_cdc_register_wake_irq");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid codec\n","lpass_cdc_register_wake_irq");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_tx_mclk_enable @ 001021ec size=204
// signature: undefined lpass_cdc_tx_mclk_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_tx_mclk_enable(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  long *plVar4;
  
  if ((param_1 != 0) &&
     (plVar4 = *(long **)(*(long *)(param_1 + 0x18) + 0x98), plVar4 != (long *)0x0)) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(*plVar4 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 != 0) {
      pcVar3 = (code *)plVar4[0x28];
      if (pcVar3 == (code *)0x0) {
        return 0;
      }
      if (*(int *)(pcVar3 + -4) != -0x7eec40ed) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102258);
        (*pcVar3)();
      }
      uVar2 = (*pcVar3)(param_1,param_2 & 1);
      return uVar2;
    }
    iVar1 = ___ratelimit(lpass_cdc_tx_mclk_enable__rs,"lpass_cdc_tx_mclk_enable");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid codec\n","lpass_cdc_tx_mclk_enable");
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_register_event_listener @ 001022bc size=204
// signature: undefined lpass_cdc_register_event_listener(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_register_event_listener(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  long *plVar4;
  
  if ((param_1 != 0) &&
     (plVar4 = *(long **)(*(long *)(param_1 + 0x18) + 0x98), plVar4 != (long *)0x0)) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(*plVar4 + 0x2e8),"qcom,lpass-cdc");
    if (iVar1 != 0) {
      pcVar3 = (code *)plVar4[0x27];
      if (pcVar3 == (code *)0x0) {
        return 0;
      }
      if (*(int *)(pcVar3 + -4) != -0x7eec40ed) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102328);
        (*pcVar3)();
      }
      uVar2 = (*pcVar3)(param_1,param_2 & 1);
      return uVar2;
    }
    iVar1 = ___ratelimit(lpass_cdc_register_event_listener__rs,"lpass_cdc_register_event_listener");
    if (iVar1 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x18),"%s: invalid codec\n",
               "lpass_cdc_register_event_listener");
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_runtime_resume @ 0010238c size=368
// signature: undefined lpass_cdc_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_runtime_resume(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x60) + 0x98);
  mutex_lock(puVar2 + 0x15);
  if (puVar2[0x6d] != 0) {
    iVar1 = *(int *)(puVar2 + 0x6f);
    if (iVar1 == 0) {
      iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(puVar2[0x6d],param_1);
      if (iVar1 < 0) {
        iVar1 = ___ratelimit(lpass_cdc_runtime_resume__rs,"lpass_cdc_runtime_resume");
        if (iVar1 != 0) {
          _dev_err(param_1,"%s:lpass core hw enable failed\n","lpass_cdc_runtime_resume");
        }
        goto LAB_001023e0;
      }
      iVar1 = *(int *)(puVar2 + 0x6f);
    }
    *(int *)(puVar2 + 0x6f) = iVar1 + 1;
  }
LAB_001023e0:
  if (puVar2[0x6e] == 0) goto LAB_00102434;
  iVar1 = *(int *)((long)puVar2 + 0x37c);
  if (iVar1 == 0) {
    iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(puVar2[0x6e],param_1);
    if (-1 < iVar1) {
      iVar1 = *(int *)((long)puVar2 + 0x37c);
      goto LAB_00102400;
    }
    iVar1 = ___ratelimit(lpass_cdc_runtime_resume__rs_39,"lpass_cdc_runtime_resume");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s:lpass audio hw enable failed\n","lpass_cdc_runtime_resume");
    }
  }
  else {
LAB_00102400:
    *(int *)((long)puVar2 + 0x37c) = iVar1 + 1;
  }
  iVar1 = *(int *)(puVar2 + 0x70);
  if (iVar1 == 0) {
    iVar1 = lpass_cdc_clk_rsc_request_clock(param_1,0,0,1);
    if (iVar1 < 0) {
      iVar1 = ___ratelimit(lpass_cdc_runtime_resume__rs_41,"lpass_cdc_runtime_resume");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s:lpass Tx core clk enable failed\n","lpass_cdc_runtime_resume");
      }
      goto LAB_00102434;
    }
    iVar1 = *(int *)(puVar2 + 0x70);
  }
  *(int *)(puVar2 + 0x70) = iVar1 + 1;
LAB_00102434:
  mutex_unlock(puVar2 + 0x15);
  pm_runtime_set_autosuspend_delay(*puVar2,100);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_runtime_suspend @ 00102500 size=244
// signature: undefined lpass_cdc_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_runtime_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  mutex_lock(lVar3 + 0xa8);
  if (*(long *)(lVar3 + 0x368) != 0) {
    iVar1 = *(int *)(lVar3 + 0x378) + -1;
    *(int *)(lVar3 + 0x378) = iVar1;
    if (iVar1 == 0) {
      digital_cdc_rsc_mgr_hw_vote_disable(*(long *)(lVar3 + 0x368),param_1);
      iVar1 = *(int *)(lVar3 + 0x378);
    }
    if (iVar1 < 0) {
      *(undefined4 *)(lVar3 + 0x378) = 0;
      lVar2 = *(long *)(lVar3 + 0x370);
      goto joined_r0x0010254c;
    }
  }
  lVar2 = *(long *)(lVar3 + 0x370);
joined_r0x0010254c:
  if (lVar2 != 0) {
    iVar1 = *(int *)(lVar3 + 0x37c) + -1;
    *(int *)(lVar3 + 0x37c) = iVar1;
    if (iVar1 == 0) {
      digital_cdc_rsc_mgr_hw_vote_disable(lVar2,param_1);
      iVar1 = *(int *)(lVar3 + 0x37c);
    }
    if (iVar1 < 0) {
      *(undefined4 *)(lVar3 + 0x37c) = 0;
    }
  }
  iVar1 = *(int *)(lVar3 + 0x380) + -1;
  *(int *)(lVar3 + 0x380) = iVar1;
  if (iVar1 == 0) {
    lpass_cdc_clk_rsc_request_clock(param_1,0,0,0);
    iVar1 = *(int *)(lVar3 + 0x380);
  }
  if (iVar1 < 0) {
    *(undefined4 *)(lVar3 + 0x380) = 0;
  }
  mutex_unlock(lVar3 + 0xa8);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_check_core_votes @ 001025f8 size=116
// signature: undefined lpass_cdc_check_core_votes(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_check_core_votes(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  mutex_lock(lVar1 + 0xa8);
  if (((*(char *)(lVar1 + 0xdf) == '\0') ||
      ((*(long *)(lVar1 + 0x368) != 0 && (*(int *)(lVar1 + 0x378) == 0)))) ||
     ((*(long *)(lVar1 + 0x370) != 0 && (*(int *)(lVar1 + 0x37c) == 0)))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  mutex_unlock(lVar1 + 0xa8);
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_version_read @ 00102670 size=312
// signature: undefined lpass_cdc_version_read(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_version_read
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 local_40;
  undefined7 local_38;
  undefined1 uStack_31;
  undefined7 local_30;
  undefined1 uStack_29;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_31 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_30 = 0;
  uStack_29 = 0;
  local_40 = param_6;
  if (*(long *)(param_1 + 0x40) == 0) {
    iVar2 = ___ratelimit(lpass_cdc_version_read__rs,"lpass_cdc_version_read");
    if (iVar2 == 0) {
      uVar3 = 0xffffffffffffffea;
    }
    else {
      _printk(&DAT_0010ab2a,"lpass_cdc_version_read");
      uVar3 = 0xffffffffffffffea;
    }
  }
  else {
    switch(*(undefined4 *)(*(long *)(param_1 + 0x40) + 0x360)) {
    case 1:
      pcVar4 = "LPASS-CDC_1_0\n";
      break;
    case 2:
      pcVar4 = "LPASS-CDC_1_1\n";
      break;
    case 3:
      pcVar4 = "LPASS-CDC_1_2\n";
      break;
    default:
      pcVar4 = "VER_UNDEFINED\n";
      break;
    case 5:
      pcVar4 = "LPASS-CDC_2_1\n";
      break;
    case 6:
      pcVar4 = "LPASS-CDC_2_5\n";
      break;
    case 7:
      pcVar4 = "LPASS-CDC_2_6\n";
    }
    local_38 = (undefined7)*(undefined8 *)pcVar4;
    uStack_31 = (undefined1)*(undefined8 *)(pcVar4 + 7);
    local_30 = (undefined7)((ulong)*(undefined8 *)(pcVar4 + 7) >> 8);
    uVar3 = simple_read_from_buffer(param_4,param_5,&local_40,&local_38,0xe);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_soc_codec_probe @ 001027ac size=708
// signature: undefined lpass_cdc_soc_codec_probe(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_soc_codec_probe(long param_1)

{
  undefined4 uVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  char cVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  char *pcVar11;
  int iVar12;
  undefined4 uVar13;
  code *pcVar14;
  undefined8 *puVar15;
  
  puVar15 = *(undefined8 **)(*(long *)(param_1 + 0x18) + 0x98);
  snd_soc_component_init_regmap(param_1,puVar15[2]);
  if (*(int *)(puVar15 + 0x6c) == 0) {
    uVar2 = *(ushort *)((long)puVar15 + 0x322);
    uVar8 = (uint)uVar2;
    if ((uVar2 != 1) && (uVar2 != 2)) {
      if (uVar2 < 3) goto LAB_00102800;
      uVar8 = 3;
    }
    *(uint *)(puVar15 + 0x6c) = uVar8;
  }
LAB_00102800:
  cVar6 = snd_soc_component_read(param_1,0x30c0);
  cVar7 = snd_soc_component_read(param_1,0x30c4);
  uVar8 = snd_soc_component_read(param_1,0x30c8);
  bVar4 = cVar6 == '\x02';
  bVar5 = cVar7 == '\x0f';
  uVar8 = uVar8 & 0xfe;
  bVar3 = bVar5 && bVar4;
  if ((((uVar8 == 0x80 && bVar3) || (uVar8 == 0x70 && bVar3)) || (uVar8 == 0x60 && bVar3)) ||
     (((bVar5 && cVar6 == '\x01' || (cVar7 == '\x0e' && bVar4)) || (uVar8 == 0x50 && bVar3)))) {
    uVar13 = 4;
    if (cVar7 == '\x0e' && bVar4) {
      uVar13 = 5;
    }
    uVar1 = 6;
    if (uVar8 != 0x50 || (!bVar5 || !bVar4)) {
      uVar1 = uVar13;
    }
    uVar13 = 7;
    if (uVar8 != 0x60 || (!bVar5 || !bVar4)) {
      uVar13 = uVar1;
    }
    uVar1 = 8;
    if (uVar8 != 0x70 || (!bVar5 || !bVar4)) {
      uVar1 = uVar13;
    }
    uVar13 = 9;
    if (uVar8 != 0x80 || (!bVar5 || !bVar4)) {
      uVar13 = uVar1;
    }
    *(undefined4 *)(puVar15 + 0x6c) = uVar13;
    pcVar14 = (code *)puVar15[0x1d];
    if (pcVar14 != (code *)0x0) goto LAB_001028e8;
LAB_0010290c:
    pcVar14 = (code *)puVar15[0x2b];
    if (pcVar14 != (code *)0x0) {
      if (*(int *)(pcVar14 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x102930);
        (*pcVar14)();
      }
      iVar9 = (*pcVar14)(param_1);
      if (iVar9 < 0) {
        iVar12 = 1;
        goto LAB_00102a40;
      }
    }
    pcVar14 = (code *)puVar15[0x39];
    if (pcVar14 != (code *)0x0) {
      if (*(int *)(pcVar14 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10295c);
        (*pcVar14)();
      }
      iVar9 = (*pcVar14)(param_1);
      if (iVar9 < 0) {
        iVar12 = 2;
        goto LAB_00102a40;
      }
    }
    pcVar14 = (code *)puVar15[0x47];
    if (pcVar14 != (code *)0x0) {
      if (*(int *)(pcVar14 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x102988);
        (*pcVar14)();
      }
      iVar9 = (*pcVar14)(param_1);
      if (iVar9 < 0) {
        iVar12 = 3;
        goto LAB_00102a40;
      }
    }
    pcVar14 = (code *)puVar15[0x55];
    if (pcVar14 != (code *)0x0) {
      if (*(int *)(pcVar14 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x1029b4);
        (*pcVar14)();
      }
      iVar9 = (*pcVar14)(param_1);
      if (iVar9 < 0) {
        iVar12 = 4;
        goto LAB_00102a40;
      }
    }
    puVar15[1] = param_1;
    iVar9 = snd_event_client_register(*puVar15,&lpass_cdc_ssr_ops,puVar15);
    if (iVar9 == 0) {
      snd_event_notify(*puVar15,1);
      return 0;
    }
    uVar10 = *(undefined8 *)(param_1 + 0x18);
    pcVar11 = "%s: Registration with SND event FWK failed ret = %d\n";
    iVar12 = iVar9;
  }
  else {
    pcVar14 = (code *)puVar15[0x1d];
    if (pcVar14 == (code *)0x0) goto LAB_0010290c;
LAB_001028e8:
    if (*(int *)(pcVar14 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x102904);
      (*pcVar14)();
    }
    iVar9 = (*pcVar14)(param_1);
    if (-1 < iVar9) goto LAB_0010290c;
    iVar12 = 0;
LAB_00102a40:
    uVar10 = *(undefined8 *)(param_1 + 0x18);
    pcVar11 = "%s: init for macro %d failed\n";
  }
  _dev_err(uVar10,pcVar11,"lpass_cdc_soc_codec_probe",iVar12);
  return iVar9;
}



//------------------------------------------------------------
// lpass_cdc_soc_codec_remove @ 00102a74 size=252
// signature: undefined lpass_cdc_soc_codec_remove(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_soc_codec_remove(long param_1)

{
  code *pcVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*(long *)(param_1 + 0x18) + 0x98);
  snd_event_client_deregister(*puVar2);
  pcVar1 = (code *)puVar2[0x1e];
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102abc);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  pcVar1 = (code *)puVar2[0x2c];
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102ae4);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  pcVar1 = (code *)puVar2[0x3a];
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102b0c);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  pcVar1 = (code *)puVar2[0x48];
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102b34);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  pcVar1 = (code *)puVar2[0x56];
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x2fe24ac8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102b5c);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_ssr_enable @ 00102b74 size=1000
// signature: undefined lpass_cdc_ssr_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_ssr_enable(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  
  if (*(char *)(param_2 + 0xe0) == '\0') {
    pcVar2 = *(code **)(param_2 + 0x450);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x4bda02b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102bc0);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 0x448),5);
    }
    pcVar2 = *(code **)(param_2 + 0x118);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102bf0);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),7,0);
    }
    pcVar2 = *(code **)(param_2 + 0x188);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102c20);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),7,0);
    }
    pcVar2 = *(code **)(param_2 + 0x1f8);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102c50);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),7,0);
    }
    pcVar2 = *(code **)(param_2 + 0x268);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102c80);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),7,0);
    }
    pcVar2 = *(code **)(param_2 + 0x2d8);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102cb0);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),7,0);
    }
    lVar1 = param_2 + 0x78;
    mutex_lock(lVar1);
    *(undefined1 *)(param_2 + 0xdf) = 1;
    mutex_unlock(lVar1);
    pcVar2 = *(code **)(param_2 + 0x450);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x4bda02b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102cf8);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 0x448),0xb);
    }
    pcVar2 = *(code **)(param_2 + 0x118);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102d28);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),0xc,0);
    }
    pcVar2 = *(code **)(param_2 + 0x188);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102d58);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),0xc,0);
    }
    pcVar2 = *(code **)(param_2 + 0x1f8);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102d88);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),0xc,0);
    }
    pcVar2 = *(code **)(param_2 + 0x268);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102db8);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),0xc,0);
    }
    pcVar2 = *(code **)(param_2 + 0x2d8);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102de8);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),0xc,0);
    }
    regcache_cache_only(*(undefined8 *)(param_2 + 0x10),0);
    mutex_lock(lVar1);
    *(undefined1 *)(param_2 + 0xde) = 1;
    mutex_unlock(lVar1);
    regcache_mark_dirty(*(undefined8 *)(param_2 + 0x10));
    lpass_cdc_clk_rsc_enable_all_clocks(*(undefined8 *)(param_2 + 0x448),1);
    regcache_sync(*(undefined8 *)(param_2 + 0x10));
    usleep_range_state(100,0x6e,2);
    lpass_cdc_clk_rsc_enable_all_clocks(*(undefined8 *)(param_2 + 0x448),0);
    pcVar2 = *(code **)(param_2 + 0x118);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102e74);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),5,0);
    }
    pcVar2 = *(code **)(param_2 + 0x188);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102ea4);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),5,0);
    }
    pcVar2 = *(code **)(param_2 + 0x1f8);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102ed4);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),5,0);
    }
    pcVar2 = *(code **)(param_2 + 0x268);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102f04);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),5,0);
    }
    pcVar2 = *(code **)(param_2 + 0x2d8);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102f34);
        (*pcVar2)();
      }
      (*pcVar2)(*(undefined8 *)(param_2 + 8),5,0);
    }
    blocking_notifier_call_chain(param_2 + 0x400,4,*(undefined8 *)(param_2 + 0x3f8));
  }
  else {
    *(undefined1 *)(param_2 + 0xe0) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_ssr_disable @ 00102f60 size=436
// signature: undefined lpass_cdc_ssr_disable(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_ssr_disable(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (*(char *)((long)param_2 + 0xde) == '\0') {
    iVar1 = ___ratelimit(lpass_cdc_ssr_disable__rs,"lpass_cdc_ssr_disable");
    if (iVar1 != 0) {
      _dev_err(*param_2,"%s: already disabled\n","lpass_cdc_ssr_disable");
    }
  }
  else {
    regcache_cache_only(param_2[2],1);
    mutex_lock(param_2 + 0xf);
    *(undefined2 *)((long)param_2 + 0xde) = 0;
    mutex_unlock(param_2 + 0xf);
    pcVar2 = (code *)param_2[0x8a];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x4bda02b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102fc8);
        (*pcVar2)();
      }
      (*pcVar2)(param_2[0x89],4);
    }
    pcVar2 = (code *)param_2[0x23];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102ff8);
        (*pcVar2)();
      }
      (*pcVar2)(param_2[1],4,0);
    }
    pcVar2 = (code *)param_2[0x31];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103028);
        (*pcVar2)();
      }
      (*pcVar2)(param_2[1],4,0);
    }
    pcVar2 = (code *)param_2[0x3f];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103058);
        (*pcVar2)();
      }
      (*pcVar2)(param_2[1],4,0);
    }
    pcVar2 = (code *)param_2[0x4d];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103088);
        (*pcVar2)();
      }
      (*pcVar2)(param_2[1],4,0);
    }
    pcVar2 = (code *)param_2[0x5b];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1030b8);
        (*pcVar2)();
      }
      (*pcVar2)(param_2[1],4,0);
    }
    blocking_notifier_call_chain(param_2 + 0x80,3,param_2[0x7f]);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_probe @ 00103118 size=676
// signature: undefined lpass_cdc_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int lpass_cdc_probe(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  ulong uVar7;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  plVar5 = (long *)devm_kmalloc(lVar1,0x470,0xdc0);
  if (plVar5 == (long *)0x0) {
    iVar4 = -0xc;
  }
  else {
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,num-macros",&local_3c,1,0);
    if (iVar4 < 0) {
      _dev_err(lVar1,"%s:num-macros property not found\n","lpass_cdc_probe");
    }
    else {
      *(short *)((long)plVar5 + 0x324) = (short)local_3c;
      if ((local_3c & 0xffff) < 6) {
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,lpass-cdc-version",plVar5 + 0x6c,1,0);
        __init_rwsem(plVar5 + 0x80,"&(&priv->notifier)->rwsem",&lpass_cdc_probe___key);
        plVar5[0x88] = 0;
        *plVar5 = lVar1;
        *(undefined2 *)((long)plVar5 + 0xde) = 0x101;
        *(undefined1 *)(plVar5 + 0x1c) = 1;
        uVar6 = lpass_cdc_regmap_init(lVar1,lpass_cdc_regmap_config);
        plVar5[2] = uVar6;
        if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
          _dev_err(lVar1,"%s:regmap init failed\n","lpass_cdc_probe");
          iVar4 = -0x16;
        }
        else {
          devm_regmap_qti_debugfs_register(*plVar5,uVar6);
          plVar5[0x73] = (long)__lpass_cdc_reg_read;
          plVar5[0x7c] = (long)plVar5;
          plVar5[0x6f] = 0;
          plVar5[0x74] = (long)__lpass_cdc_reg_write;
          *(long **)(param_1 + 0xa8) = plVar5;
          plVar5[0x7d] = (long)lpass_cdc_update_wcd_event;
          plVar5[0x7e] = (long)lpass_cdc_register_notifier;
          __mutex_init(plVar5 + 3,"&priv->macro_lock",&lpass_cdc_probe___key_64);
          __mutex_init(plVar5 + 9,"&priv->io_lock",&lpass_cdc_probe___key_66);
          __mutex_init(plVar5 + 0xf,"&priv->clk_lock",&lpass_cdc_probe___key_68);
          __mutex_init(plVar5 + 0x15,"&priv->vote_lock",&lpass_cdc_probe___key_70);
          plVar5[0x66] = 0xfffffffe0;
          plVar5[0x67] = (long)(plVar5 + 0x67);
          plVar5[0x68] = (long)(plVar5 + 0x67);
          plVar5[0x69] = (long)lpass_cdc_add_child_devices;
          uVar7 = devm_clk_get(lVar1,"lpass_core_hw_vote");
          uVar6 = 0;
          if (uVar7 < 0xfffffffffffff001) {
            uVar6 = uVar7;
          }
          plVar5[0x6d] = uVar6;
          uVar7 = devm_clk_get(lVar1,"lpass_audio_hw_vote");
          uVar3 = _system_wq;
          uVar6 = 0;
          if (uVar7 < 0xfffffffffffff001) {
            uVar6 = uVar7;
          }
          plVar5[0x6e] = uVar6;
          queue_work_on(0x20,uVar3,plVar5 + 0x66);
          iVar4 = 0;
        }
      }
      else {
        _dev_err(lVar1,"%s:num_macros(%d) > MAX_MACRO(%d) than supported\n","lpass_cdc_probe",
                 local_3c & 0xffff,5);
        iVar4 = -0x16;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// lpass_cdc_remove @ 001033c0 size=52
// signature: undefined lpass_cdc_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_remove(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0xa8) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    of_platform_depopulate(param_1 + 0x10);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// __lpass_cdc_reg_read @ 001033f8 size=248
// signature: undefined __lpass_cdc_reg_read(void)
// callers: []
//------------------------------------------------------------

undefined8 __lpass_cdc_reg_read(long param_1,ushort param_2,ushort param_3,undefined1 *param_4)

{
  code *pcVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  mutex_lock(param_1 + 0x78);
  if (*(char *)(param_1 + 0xde) == '\0') {
    uVar3 = 0xffffffea;
    goto LAB_001034c8;
  }
  if (*(long *)(param_1 + 0x250) == 0) {
LAB_0010346c:
    if (4 < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1034f0);
      (*pcVar1)();
    }
    uVar2 = readl(*(long *)(param_1 + (ulong)param_2 * 0x70 + 0x148) + (ulong)param_3);
    *param_4 = uVar2;
  }
  else {
    __pm_runtime_resume(*(long *)(param_1 + 0x250),4);
    mutex_lock(param_1 + 0xa8);
    if (((*(long *)(param_1 + 0x368) == 0) || (*(int *)(param_1 + 0x378) != 0)) &&
       ((*(long *)(param_1 + 0x370) == 0 || (*(int *)(param_1 + 0x37c) != 0)))) goto LAB_0010346c;
  }
  if (*(long *)(param_1 + 0x250) != 0) {
    mutex_unlock(param_1 + 0xa8);
    lVar4 = *(long *)(param_1 + 0x250);
    uVar3 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar4 + 0x220) = uVar3;
    __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x250),0xd);
  }
  uVar3 = 0;
LAB_001034c8:
  mutex_unlock(param_1 + 0x78);
  return uVar3;
}



//------------------------------------------------------------
// __lpass_cdc_reg_write @ 001034f4 size=248
// signature: undefined __lpass_cdc_reg_write(void)
// callers: []
//------------------------------------------------------------

undefined8 __lpass_cdc_reg_write(long param_1,ushort param_2,ushort param_3,undefined1 param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  mutex_lock(param_1 + 0x78);
  if (*(char *)(param_1 + 0xde) == '\0') {
    uVar2 = 0xffffffea;
    goto LAB_001035c4;
  }
  if (*(long *)(param_1 + 0x250) == 0) {
LAB_00103568:
    if (4 < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1035ec);
      (*pcVar1)();
    }
    writel(param_4,*(long *)(param_1 + (ulong)param_2 * 0x70 + 0x148) + (ulong)param_3);
  }
  else {
    __pm_runtime_resume(*(long *)(param_1 + 0x250),4);
    mutex_lock(param_1 + 0xa8);
    if (((*(long *)(param_1 + 0x368) == 0) || (*(int *)(param_1 + 0x378) != 0)) &&
       ((*(long *)(param_1 + 0x370) == 0 || (*(int *)(param_1 + 0x37c) != 0)))) goto LAB_00103568;
  }
  if (*(long *)(param_1 + 0x250) != 0) {
    mutex_unlock(param_1 + 0xa8);
    lVar3 = *(long *)(param_1 + 0x250);
    uVar2 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar3 + 0x220) = uVar2;
    __pm_runtime_suspend(*(undefined8 *)(param_1 + 0x250),0xd);
  }
  uVar2 = 0;
LAB_001035c4:
  mutex_unlock(param_1 + 0x78);
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_update_wcd_event @ 001035f0 size=380
// signature: undefined lpass_cdc_update_wcd_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_update_wcd_event(undefined8 *param_1,undefined2 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  if (param_1 == (undefined8 *)0x0) {
    iVar1 = ___ratelimit(lpass_cdc_update_wcd_event__rs,"lpass_cdc_update_wcd_event");
    if (iVar1 != 0) {
      _printk(&DAT_0010a72b,"lpass_cdc_update_wcd_event");
    }
LAB_0010365c:
    uVar2 = 0xffffffea;
  }
  else {
    switch(param_2) {
    case 1:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 1;
LAB_00103724:
        if (*(int *)(pcVar4 + -4) != -0x29448167) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10373c);
          (*pcVar4)();
        }
        (*pcVar4)(uVar2,uVar3);
      }
      break;
    case 2:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 2;
        goto LAB_00103724;
      }
      break;
    case 3:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 3;
        goto LAB_00103724;
      }
      break;
    case 4:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 9;
        goto LAB_00103724;
      }
      break;
    case 5:
      pcVar4 = (code *)param_1[0x23];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 10;
        goto LAB_00103724;
      }
      break;
    case 6:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 0xd;
        goto LAB_00103724;
      }
      break;
    case 7:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 0xe;
        goto LAB_00103724;
      }
      break;
    case 8:
      pcVar4 = (code *)param_1[0x31];
      if (pcVar4 != (code *)0x0) {
        uVar2 = param_1[1];
        uVar3 = 0xf;
        goto LAB_00103724;
      }
      break;
    default:
      iVar1 = ___ratelimit(lpass_cdc_update_wcd_event__rs_75,"lpass_cdc_update_wcd_event");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: Invalid event %d trigger from wcd\n","lpass_cdc_update_wcd_event",
                 param_2);
      }
      goto LAB_0010365c;
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_register_notifier @ 00103770 size=112
// signature: undefined lpass_cdc_register_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_register_notifier(long param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar1 = ___ratelimit(lpass_cdc_register_notifier__rs,"lpass_cdc_register_notifier");
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      _printk(&DAT_0010ac07,"lpass_cdc_register_notifier");
      uVar2 = 0xffffffea;
    }
  }
  else if ((param_3 & 1) == 0) {
    uVar2 = blocking_notifier_chain_unregister(param_1 + 0x400);
  }
  else {
    uVar2 = blocking_notifier_chain_register();
  }
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_add_child_devices @ 001037e4 size=600
// signature: undefined lpass_cdc_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_add_child_devices(long param_1)

{
  ushort uVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  size_t __n;
  long lVar8;
  char *pcVar9;
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
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  plVar2 = (long *)(param_1 + -0x330);
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
  if (plVar2 == (long *)0x0) {
    _printk(&DAT_0010ad5b,"lpass_cdc_add_child_devices");
  }
  else {
    lVar5 = *plVar2;
    if ((lVar5 == 0) || (*(long *)(lVar5 + 0x2e8) == 0)) {
      pcVar9 = "%s: DT node for lpass_cdc does not exist\n";
LAB_0010392c:
      _dev_err(lVar5,pcVar9,"lpass_cdc_add_child_devices");
    }
    else {
      *(undefined2 *)(param_1 + 0xa8) = 0;
      puVar6 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar5 + 0x2e8),0);
      if (puVar6 != (undefined8 *)0x0) {
        do {
          lVar7 = of_find_property(puVar6,"qcom,split-codec",0);
          pcVar9 = (char *)*puVar6;
          __n = strlen(pcVar9);
          if (0x4d < __n) {
            __n = 0x4e;
          }
          memcpy(&local_b8,pcVar9,__n);
          *(undefined1 *)((long)&local_b8 + __n) = 0;
          lVar8 = platform_device_alloc(&local_b8,0xffffffff);
          lVar5 = *plVar2;
          if (lVar8 == 0) {
            pcVar9 = "%s: pdev memory alloc failed\n";
            goto LAB_0010392c;
          }
          *(long *)(lVar8 + 0x70) = lVar5;
          *(undefined8 **)(lVar8 + 0x2f8) = puVar6;
          *(long *)(*plVar2 + 0x90) = param_1 + 0xb0;
          if (lVar7 != 0) {
            *(long *)(param_1 + 200) = lVar8 + 0x10;
          }
          iVar4 = platform_device_add(lVar8);
          if (iVar4 != 0) {
            _dev_err(lVar8 + 0x10,"%s: Cannot add platform device\n","lpass_cdc_add_child_devices");
            platform_device_put(lVar8);
            if ((((*(short *)(param_1 + 0xa8) != 0) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0x78)),
                 1 < *(ushort *)(param_1 + 0xa8))) &&
                (platform_device_put(*(undefined8 *)(param_1 + 0x80)),
                2 < *(ushort *)(param_1 + 0xa8))) &&
               (((platform_device_put(*(undefined8 *)(param_1 + 0x88)),
                 3 < *(ushort *)(param_1 + 0xa8) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0x90)),
                 4 < *(ushort *)(param_1 + 0xa8))) &&
                ((platform_device_put(*(undefined8 *)(param_1 + 0x98)),
                 5 < *(ushort *)(param_1 + 0xa8) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0xa0)),
                 6 < *(ushort *)(param_1 + 0xa8))))))) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103a38);
              (*pcVar3)();
            }
            break;
          }
          uVar1 = *(ushort *)(param_1 + 0xa8);
          if (5 < uVar1) break;
          lVar5 = *plVar2;
          *(ushort *)(param_1 + 0xa8) = uVar1 + 1;
          *(long *)(param_1 + 0x78 + (ulong)uVar1 * 8) = lVar8;
          puVar6 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar5 + 0x2e8),puVar6);
        } while (puVar6 != (undefined8 *)0x0);
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// readl @ 00103a3c size=140
// signature: undefined readl(void)
// callers: [__lpass_cdc_reg_read]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x103a94,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00103ac8 size=136
// signature: undefined writel(void)
// callers: [__lpass_cdc_reg_write]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103ae0,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x103b20,uVar1);
  return;
}



//------------------------------------------------------------
// lpass_cdc_load_compander_coeff @ 00103b58 size=120
// signature: undefined lpass_cdc_load_compander_coeff(void)
// callers: []
//------------------------------------------------------------

undefined8
lpass_cdc_load_compander_coeff
          (undefined8 param_1,undefined2 param_2,undefined2 param_3,long param_4,ushort param_5)

{
  ulong uVar1;
  undefined1 *puVar2;
  
  if (param_5 != 0) {
    uVar1 = (ulong)param_5;
    puVar2 = (undefined1 *)(param_4 + 1);
    do {
      snd_soc_component_write(param_1,param_2,puVar2[-1]);
      snd_soc_component_write(param_1,param_3,*puVar2);
      uVar1 = uVar1 - 1;
      puVar2 = puVar2 + 2;
    } while (uVar1 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_update_compander_setting @ 00103bd4 size=368
// signature: undefined lpass_cdc_update_compander_setting(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_update_compander_setting(undefined8 param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  param_2 = param_2 & 0xffff;
  iVar3 = param_3[2];
  iVar2 = param_3[1];
  iVar4 = *param_3 - iVar2;
  snd_soc_component_write(param_1,param_2 + 8,6);
  iVar5 = 0xc;
  if (iVar4 < 0x12) {
    iVar5 = iVar4;
  }
  iVar1 = 0x12;
  if (iVar4 < 0x18) {
    iVar1 = iVar5;
  }
  snd_soc_component_write(param_1,param_2 + 0xc,iVar1);
  if (iVar4 < 0x42) {
    iVar5 = 0x18;
    if (iVar4 < 0x1e) {
      iVar5 = iVar4;
    }
    iVar1 = 0x1e;
    if (iVar4 < 0x24) {
      iVar1 = iVar5;
    }
    snd_soc_component_write(param_1,param_2 + 0x10,iVar1);
    if (iVar4 < 0x30) {
      iVar5 = 0x24;
      if (iVar4 < 0x2a) {
        iVar5 = iVar4;
      }
    }
    else {
      iVar5 = 0x2a;
    }
  }
  else {
    snd_soc_component_write(param_1,param_2 + 0x10,0x21);
    iVar5 = 0x30;
  }
  snd_soc_component_write(param_1,param_2 + 0x14,iVar5);
  iVar5 = 0x3f;
  if (iVar4 < 0x45) {
    iVar5 = 0x3c;
  }
  if (iVar4 < 0x42) {
    if (iVar4 < 0x3c) {
      iVar5 = 0x30;
      if (iVar4 < 0x36) {
        iVar5 = iVar4;
      }
    }
    else {
      iVar5 = 0x36;
    }
  }
  snd_soc_component_write(param_1,param_2 + 0x18,iVar5);
  snd_soc_component_write(param_1,param_2 + 0x1c,iVar4);
  iVar5 = iVar2 + 0x100;
  if (-1 < iVar2) {
    iVar5 = iVar2;
  }
  iVar1 = -iVar2;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  snd_soc_component_write(param_1,param_2 + 0x20,iVar5);
  snd_soc_component_write(param_1,param_2 + 0x24,iVar4 - iVar1);
  snd_soc_component_write(param_1,param_2 + 0x28,iVar3);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_get_macro_id @ 00103d48 size=104
// signature: undefined lpass_cdc_get_macro_id(void)
// callers: [lpass_cdc_is_readable_register, lpass_cdc_is_writeable_register]
//------------------------------------------------------------

undefined4 lpass_cdc_get_macro_id(undefined8 param_1,uint param_2)

{
  undefined4 uVar1;
  
  param_2 = param_2 & 0xffff;
  if (param_2 < 0x7a9) {
    return 0;
  }
  if (param_2 - 0x1000 < 0xf8d) {
    return 1;
  }
  if (param_2 - 0x2000 < 0xbe5) {
    return 2;
  }
  if (param_2 - 0x4000 < 0xbe5) {
    return 4;
  }
  uVar1 = 3;
  if (0x5a8 < param_2 - 0x3000) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_regmap_init @ 00103db4 size=52
// signature: undefined lpass_cdc_regmap_init(void)
// callers: [lpass_cdc_probe]
//------------------------------------------------------------

void lpass_cdc_regmap_init(undefined8 param_1,undefined8 param_2)

{
  __devm_regmap_init(param_1,&regmap_bus_config,param_1,param_2,0,0);
  return;
}



//------------------------------------------------------------
// regmap_bus_write @ 00103dec size=148
// signature: undefined regmap_bus_write(void)
// callers: []
//------------------------------------------------------------

undefined8 regmap_bus_write(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x98) != 0) {
    if (1 < param_3) {
      uVar2 = regmap_bus_gather_write(param_1,param_2,2,param_2 + 2,param_3 - 2);
      return uVar2;
    }
    iVar1 = ___ratelimit(regmap_bus_write__rs,"regmap_bus_write");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: count %zd bytes < %d, not supported\n","regmap_bus_write",param_3,2);
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// regmap_bus_gather_write @ 00103e84 size=608
// signature: undefined regmap_bus_gather_write(void)
// callers: [regmap_bus_write]
//------------------------------------------------------------

int regmap_bus_gather_write(long param_1,ushort *param_2,long param_3,long param_4,ulong param_5)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  
  lVar9 = *(long *)(param_1 + 0x98);
  if (lVar9 == 0) {
    iVar4 = ___ratelimit(regmap_bus_gather_write__rs,"regmap_bus_gather_write");
    if (iVar4 == 0) {
      return -0x16;
    }
    pcVar6 = "%s: priv is NULL\n";
  }
  else {
    if ((param_2 != (ushort *)0x0) && (param_4 != 0)) {
      if (param_3 != 2) {
        iVar4 = ___ratelimit(regmap_bus_gather_write__rs_4,"regmap_bus_gather_write");
        if (iVar4 == 0) {
          return -0x16;
        }
        _dev_err(param_1,"%s: register size %zd bytes, not supported\n","regmap_bus_gather_write",
                 param_3);
        return -0x16;
      }
      uVar1 = *param_2;
      if (uVar1 < 0x7a9) {
        lVar8 = 0;
      }
      else if (uVar1 - 0x1000 < 0xf8d) {
        lVar8 = 1;
      }
      else {
        uVar7 = (uint)uVar1;
        if (uVar7 - 0x2000 < 0xbe5) {
          lVar8 = 2;
        }
        else if (uVar7 - 0x4000 < 0xbe5) {
          lVar8 = 4;
        }
        else {
          if (0x5a8 < uVar7 - 0x3000) {
            return 0;
          }
          lVar8 = 3;
        }
      }
      if (*(char *)(lVar9 + lVar8 + 0xd9) == '\0') {
        return 0;
      }
      mutex_lock(lVar9 + 0x48);
      if (param_5 == 0) {
        iVar4 = -0x16;
      }
      else {
        uVar10 = 0;
        uVar1 = (&macro_id_base_offset)[lVar8];
        do {
          iVar2 = (int)uVar10 * 4;
          if (*(int *)(*(code **)(lVar9 + 0x3a0) + -4) != 0x4656a4cc) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104040);
            (*pcVar3)();
          }
          iVar4 = (**(code **)(lVar9 + 0x3a0))
                            (lVar9,lVar8,((uint)*param_2 + iVar2) - (uint)uVar1,
                             *(undefined1 *)(param_4 + uVar10));
          if (iVar4 < 0) {
            iVar5 = ___ratelimit(regmap_bus_gather_write__rs_6,"regmap_bus_gather_write");
            if (iVar5 != 0) {
              _dev_err(param_1,"%s: Codec write failed (%d), reg:0x%x, size:%zd\n",
                       "regmap_bus_gather_write",iVar4,iVar2 + (uint)*param_2,param_5);
            }
            break;
          }
          uVar10 = (ulong)((int)uVar10 + 1);
        } while (uVar10 < param_5);
      }
      mutex_unlock(lVar9 + 0x48);
      return iVar4;
    }
    iVar4 = ___ratelimit(regmap_bus_gather_write__rs_2,"regmap_bus_gather_write");
    if (iVar4 == 0) {
      return -0x16;
    }
    pcVar6 = "%s: reg or val is NULL\n";
  }
  _dev_err(param_1,pcVar6,"regmap_bus_gather_write");
  return -0x16;
}



//------------------------------------------------------------
// regmap_bus_read @ 001040e8 size=652
// signature: undefined regmap_bus_read(void)
// callers: []
//------------------------------------------------------------

int regmap_bus_read(long param_1,ushort *param_2,long param_3,long param_4,ulong param_5)

{
  ushort uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined1 local_6c [4];
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_6c[0] = 0;
  if (lVar9 == 0) {
    iVar4 = ___ratelimit(regmap_bus_read__rs,"regmap_bus_read");
    if (iVar4 != 0) {
      pcVar6 = "%s: priv is NULL\n";
LAB_001041a0:
      _dev_err(param_1,pcVar6,"regmap_bus_read");
      iVar4 = -0x16;
      goto LAB_001041d4;
    }
  }
  else if ((param_2 == (ushort *)0x0) || (param_4 == 0)) {
    iVar4 = ___ratelimit(regmap_bus_read__rs_8,"regmap_bus_read");
    if (iVar4 != 0) {
      pcVar6 = "%s: reg or val is NULL\n";
      goto LAB_001041a0;
    }
  }
  else {
    if (param_3 == 2) {
      uVar1 = *param_2;
      if (uVar1 < 0x7a9) {
        lVar8 = 0;
LAB_0010425c:
        if (*(char *)(lVar9 + lVar8 + 0xd9) != '\0') {
          mutex_lock();
          if (param_5 == 0) {
            iVar4 = -0x16;
          }
          else {
            uVar10 = 0;
            uVar1 = (&macro_id_base_offset)[lVar8];
            do {
              iVar2 = (int)uVar10 * 4;
              if (*(int *)(*(code **)(lVar9 + 0x398) + -4) != 0x7470eb46) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1042c4);
                (*pcVar3)();
              }
              iVar4 = (**(code **)(lVar9 + 0x398))
                                (lVar9,lVar8,((uint)*param_2 + iVar2) - (uint)uVar1,local_6c);
              if (iVar4 < 0) {
                iVar5 = ___ratelimit(regmap_bus_read__rs_10,"regmap_bus_read");
                if (iVar5 != 0) {
                  _dev_err(param_1,"%s: Codec read failed (%d), reg: 0x%x, size:%zd\n",
                           "regmap_bus_read",iVar4,iVar2 + (uint)*param_2,param_5);
                }
                break;
              }
              *(undefined1 *)(param_4 + uVar10) = local_6c[0];
              uVar10 = (ulong)((int)uVar10 + 1);
            } while (uVar10 < param_5);
          }
          mutex_unlock(lVar9 + 0x48);
          goto LAB_001041d4;
        }
      }
      else {
        if (uVar1 - 0x1000 < 0xf8d) {
          lVar8 = 1;
          goto LAB_0010425c;
        }
        uVar7 = (uint)uVar1;
        if (uVar7 - 0x2000 < 0xbe5) {
          lVar8 = 2;
          goto LAB_0010425c;
        }
        if (uVar7 - 0x4000 < 0xbe5) {
          lVar8 = 4;
          goto LAB_0010425c;
        }
        if (uVar7 - 0x3000 < 0x5a9) {
          lVar8 = 3;
          goto LAB_0010425c;
        }
      }
      iVar4 = 0;
      goto LAB_001041d4;
    }
    iVar4 = ___ratelimit(regmap_bus_read__rs_9,"regmap_bus_read");
    if (iVar4 != 0) {
      _dev_err(param_1,"%s: register size %zd bytes, not supported\n","regmap_bus_read",param_3);
      iVar4 = -0x16;
      goto LAB_001041d4;
    }
  }
  iVar4 = -0x16;
LAB_001041d4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// lpass_cdc_is_writeable_register @ 00104378 size=136
// signature: undefined lpass_cdc_is_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte lpass_cdc_is_writeable_register(long param_1,int param_2)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if ((lVar4 != 0) &&
     (uVar2 = lpass_cdc_get_macro_id(*(undefined1 *)(lVar4 + 0xd8)), -1 < (int)uVar2)) {
    if (4 < uVar2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104400);
      (*pcVar1)();
    }
    uVar3 = (ulong)uVar2;
    if ((*(char *)(lVar4 + uVar3 + 0xd9) != '\0') &&
       ((&lpass_cdc_reg_access)[uVar3] != (undefined *)0x0)) {
      return (byte)(&lpass_cdc_reg_access)[uVar3]
                   [(ulong)(param_2 - (uint)(ushort)(&macro_id_base_offset)[uVar3] >> 2) & 0xffff]
             >> 1 & 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_is_readable_register @ 00104404 size=136
// signature: undefined lpass_cdc_is_readable_register(void)
// callers: []
//------------------------------------------------------------

byte lpass_cdc_is_readable_register(long param_1,int param_2)

{
  code *pcVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if ((lVar4 != 0) &&
     (uVar2 = lpass_cdc_get_macro_id(*(undefined1 *)(lVar4 + 0xd8)), -1 < (int)uVar2)) {
    if (4 < uVar2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10448c);
      (*pcVar1)();
    }
    uVar3 = (ulong)uVar2;
    if ((*(char *)(lVar4 + uVar3 + 0xd9) != '\0') &&
       ((&lpass_cdc_reg_access)[uVar3] != (undefined *)0x0)) {
      return (&lpass_cdc_reg_access)[uVar3]
             [(ulong)(param_2 - (uint)(ushort)(&macro_id_base_offset)[uVar3] >> 2) & 0xffff] & 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_is_volatile_register @ 00104490 size=608
// signature: undefined lpass_cdc_is_volatile_register(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_is_volatile_register(undefined8 param_1,int param_2)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (param_2 < 0x1818) {
    if (param_2 < 0x1400) {
      if (param_2 < 0x1088) {
        switch(param_2) {
        case 0x1020:
        case 0x1024:
        case 0x102c:
        case 0x1030:
        case 0x1034:
        case 0x1038:
        case 0x1040:
        case 0x1044:
        case 0x1078:
          return uVar1;
        case 0x1021:
        case 0x1022:
        case 0x1023:
        case 0x1025:
        case 0x1026:
        case 0x1027:
        case 0x1028:
        case 0x1029:
        case 0x102a:
        case 0x102b:
        case 0x102d:
        case 0x102e:
        case 0x102f:
        case 0x1031:
        case 0x1032:
        case 0x1033:
        case 0x1035:
        case 0x1036:
        case 0x1037:
        case 0x1039:
        case 0x103a:
        case 0x103b:
        case 0x103c:
        case 0x103d:
        case 0x103e:
        case 0x103f:
        case 0x1041:
        case 0x1042:
        case 0x1043:
        case 0x1045:
        case 0x1046:
        case 0x1047:
        case 0x1048:
        case 0x1049:
        case 0x104a:
        case 0x104b:
        case 0x104c:
        case 0x104d:
        case 0x104e:
        case 0x104f:
        case 0x1050:
        case 0x1051:
        case 0x1052:
        case 0x1053:
        case 0x1054:
        case 0x1055:
        case 0x1056:
        case 0x1057:
        case 0x1058:
        case 0x1059:
        case 0x105a:
        case 0x105b:
        case 0x105c:
        case 0x105d:
        case 0x105e:
        case 0x105f:
        case 0x1060:
        case 0x1061:
        case 0x1062:
        case 0x1063:
        case 0x1064:
        case 0x1065:
        case 0x1066:
        case 0x1067:
        case 0x1068:
        case 0x1069:
        case 0x106a:
        case 0x106b:
        case 0x106c:
        case 0x106d:
        case 0x106e:
        case 0x106f:
        case 0x1070:
        case 0x1071:
        case 0x1072:
        case 0x1073:
        case 0x1074:
        case 0x1075:
        case 0x1076:
        case 0x1077:
          goto switchD_001045ac_caseD_145d;
        default:
          if (0x14 < param_2 - 0xc0U) {
            return 0;
          }
          if ((1 << (ulong)(param_2 - 0xc0U & 0x1f) & 0x111111U) == 0) {
            return 0;
          }
          return uVar1;
        }
      }
      if (param_2 < 0x1368) {
        if (param_2 == 0x1088) {
          return uVar1;
        }
        iVar2 = 0x12d4;
      }
      else {
        if (param_2 == 0x1368) {
          return uVar1;
        }
        iVar2 = 5000;
      }
    }
    else {
      switch(param_2) {
      case 0x145c:
      case 0x1464:
      case 0x1468:
      case 0x146c:
      case 0x1470:
      case 0x1474:
      case 0x1478:
      case 0x147c:
      case 0x1480:
      case 0x1484:
      case 0x14c0:
        goto switchD_001045ac_caseD_145c;
      case 0x145d:
      case 0x145e:
      case 0x145f:
      case 0x1460:
      case 0x1461:
      case 0x1462:
      case 0x1463:
      case 0x1465:
      case 0x1466:
      case 0x1467:
      case 0x1469:
      case 0x146a:
      case 0x146b:
      case 0x146d:
      case 0x146e:
      case 0x146f:
      case 0x1471:
      case 0x1472:
      case 0x1473:
      case 0x1475:
      case 0x1476:
      case 0x1477:
      case 0x1479:
      case 0x147a:
      case 0x147b:
      case 0x147d:
      case 0x147e:
      case 0x147f:
      case 0x1481:
      case 0x1482:
      case 0x1483:
      case 0x1485:
      case 0x1486:
      case 0x1487:
      case 0x1488:
      case 0x1489:
      case 0x148a:
      case 0x148b:
      case 0x148c:
      case 0x148d:
      case 0x148e:
      case 0x148f:
      case 0x1490:
      case 0x1491:
      case 0x1492:
      case 0x1493:
      case 0x1494:
      case 0x1495:
      case 0x1496:
      case 0x1497:
      case 0x1498:
      case 0x1499:
      case 0x149a:
      case 0x149b:
      case 0x149c:
      case 0x149d:
      case 0x149e:
      case 0x149f:
      case 0x14a0:
      case 0x14a1:
      case 0x14a2:
      case 0x14a3:
      case 0x14a4:
      case 0x14a5:
      case 0x14a6:
      case 0x14a7:
      case 0x14a8:
      case 0x14a9:
      case 0x14aa:
      case 0x14ab:
      case 0x14ac:
      case 0x14ad:
      case 0x14ae:
      case 0x14af:
      case 0x14b0:
      case 0x14b1:
      case 0x14b2:
      case 0x14b3:
      case 0x14b4:
      case 0x14b5:
      case 0x14b6:
      case 0x14b7:
      case 0x14b8:
      case 0x14b9:
      case 0x14ba:
      case 0x14bb:
      case 0x14bc:
      case 0x14bd:
      case 0x14be:
      case 0x14bf:
        goto switchD_001045ac_caseD_145d;
      default:
        if ((param_2 - 0x151cU < 0x29) &&
           ((1L << ((ulong)(param_2 - 0x151cU) & 0x3f) & 0x11111111101U) != 0)) {
          return uVar1;
        }
        iVar2 = 0x1400;
      }
    }
  }
  else if (param_2 < 0x21d4) {
    if (param_2 < 0x1aac) {
      if (param_2 < 0x1a2c) {
        if (param_2 == 0x1818) {
          return uVar1;
        }
        iVar2 = 0x1878;
      }
      else {
        if (param_2 == 0x1a2c) {
          return uVar1;
        }
        iVar2 = 0x1a30;
      }
    }
    else {
      switch(param_2) {
      case 0x1d10:
      case 0x1d14:
      case 0x1d18:
      case 0x1d1c:
      case 0x1d20:
      case 0x1d50:
      case 0x1d54:
      case 0x1d58:
      case 0x1d5c:
      case 0x1d60:
      case 0x1d90:
      case 0x1d94:
      case 0x1d98:
      case 0x1d9c:
      case 0x1da0:
        goto switchD_001045ac_caseD_145c;
      case 0x1d11:
      case 0x1d12:
      case 0x1d13:
      case 0x1d15:
      case 0x1d16:
      case 0x1d17:
      case 0x1d19:
      case 0x1d1a:
      case 0x1d1b:
      case 0x1d1d:
      case 0x1d1e:
      case 0x1d1f:
      case 0x1d21:
      case 0x1d22:
      case 0x1d23:
      case 0x1d24:
      case 0x1d25:
      case 0x1d26:
      case 0x1d27:
      case 0x1d28:
      case 0x1d29:
      case 0x1d2a:
      case 0x1d2b:
      case 0x1d2c:
      case 0x1d2d:
      case 0x1d2e:
      case 0x1d2f:
      case 0x1d30:
      case 0x1d31:
      case 0x1d32:
      case 0x1d33:
      case 0x1d34:
      case 0x1d35:
      case 0x1d36:
      case 0x1d37:
      case 0x1d38:
      case 0x1d39:
      case 0x1d3a:
      case 0x1d3b:
      case 0x1d3c:
      case 0x1d3d:
      case 0x1d3e:
      case 0x1d3f:
      case 0x1d40:
      case 0x1d41:
      case 0x1d42:
      case 0x1d43:
      case 0x1d44:
      case 0x1d45:
      case 0x1d46:
      case 0x1d47:
      case 0x1d48:
      case 0x1d49:
      case 0x1d4a:
      case 0x1d4b:
      case 0x1d4c:
      case 0x1d4d:
      case 0x1d4e:
      case 0x1d4f:
      case 0x1d51:
      case 0x1d52:
      case 0x1d53:
      case 0x1d55:
      case 0x1d56:
      case 0x1d57:
      case 0x1d59:
      case 0x1d5a:
      case 0x1d5b:
      case 0x1d5d:
      case 0x1d5e:
      case 0x1d5f:
      case 0x1d61:
      case 0x1d62:
      case 0x1d63:
      case 0x1d64:
      case 0x1d65:
      case 0x1d66:
      case 0x1d67:
      case 0x1d68:
      case 0x1d69:
      case 0x1d6a:
      case 0x1d6b:
      case 0x1d6c:
      case 0x1d6d:
      case 0x1d6e:
      case 0x1d6f:
      case 0x1d70:
      case 0x1d71:
      case 0x1d72:
      case 0x1d73:
      case 0x1d74:
      case 0x1d75:
      case 0x1d76:
      case 0x1d77:
      case 0x1d78:
      case 0x1d79:
      case 0x1d7a:
      case 0x1d7b:
      case 0x1d7c:
      case 0x1d7d:
      case 0x1d7e:
      case 0x1d7f:
      case 0x1d80:
      case 0x1d81:
      case 0x1d82:
      case 0x1d83:
      case 0x1d84:
      case 0x1d85:
      case 0x1d86:
      case 0x1d87:
      case 0x1d88:
      case 0x1d89:
      case 0x1d8a:
      case 0x1d8b:
      case 0x1d8c:
      case 0x1d8d:
      case 0x1d8e:
      case 0x1d8f:
      case 0x1d91:
      case 0x1d92:
      case 0x1d93:
      case 0x1d95:
      case 0x1d96:
      case 0x1d97:
      case 0x1d99:
      case 0x1d9a:
      case 0x1d9b:
      case 0x1d9d:
      case 0x1d9e:
      case 0x1d9f:
        goto switchD_001045ac_caseD_145d;
      default:
        if (param_2 == 0x1aac) {
          return uVar1;
        }
        iVar2 = 0x1ab0;
      }
    }
  }
  else if (param_2 < 0x3084) {
    if (param_2 < 0x2388) {
      if (param_2 == 0x21d4) {
        return uVar1;
      }
      iVar2 = 0x2368;
    }
    else {
      if (param_2 == 0x2388) {
        return uVar1;
      }
      if (param_2 == 0x2598) {
        return uVar1;
      }
      iVar2 = 0x25f8;
    }
  }
  else {
    if (param_2 < 0x41d4) {
      switch(param_2) {
      case 0x3084:
      case 0x3088:
      case 0x308c:
      case 0x3090:
      case 0x30c0:
      case 0x30c4:
      case 0x30c8:
      case 0x30cc:
        goto switchD_001045ac_caseD_145c;
      default:
        goto switchD_001045ac_caseD_145d;
      }
    }
    if (param_2 < 0x4388) {
      if (param_2 == 0x41d4) {
        return uVar1;
      }
      iVar2 = 0x4368;
    }
    else {
      if (param_2 == 0x4388) {
        return uVar1;
      }
      if (param_2 == 0x4598) {
        return uVar1;
      }
      iVar2 = 0x45f8;
    }
  }
  if (param_2 == iVar2) {
switchD_001045ac_caseD_145c:
    return uVar1;
  }
switchD_001045ac_caseD_145d:
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_rsc_clk_reset @ 001046f4 size=292
// signature: undefined lpass_cdc_rsc_clk_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_rsc_clk_reset(long param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  int iVar8;
  
  if (param_1 == 0) {
    puVar5 = &DAT_0010ab17;
  }
  else {
    if (0xb < param_2) {
      _printk(&DAT_0010a761,"lpass_cdc_rsc_clk_reset",(ulong)param_2);
      return 0xffffffea;
    }
    lVar3 = lpass_cdc_get_rsc_clk_device_ptr(*(undefined8 *)(param_1 + 0x60));
    if (lVar3 == 0) {
      puVar5 = &DAT_0010b0f6;
    }
    else {
      lVar3 = *(long *)(lVar3 + 0x98);
      if (lVar3 != 0) {
        mutex_lock(lVar3 + 8);
        puVar7 = (undefined8 *)(lVar3 + (ulong)param_2 * 8 + 0x68);
        uVar4 = __clk_is_enabled(*puVar7);
        if ((uVar4 & 1) != 0) {
          iVar8 = 0;
          do {
            uVar6 = *puVar7;
            clk_disable(uVar6);
            clk_unprepare(uVar6);
            uVar4 = __clk_is_enabled(*puVar7);
            iVar8 = iVar8 + -1;
          } while ((uVar4 & 1) != 0);
          if (iVar8 != 0) {
            do {
              uVar6 = *puVar7;
              iVar2 = clk_prepare(uVar6);
              if ((iVar2 == 0) && (iVar2 = clk_enable(uVar6), iVar2 != 0)) {
                clk_unprepare(uVar6);
              }
              bVar1 = iVar8 != -1;
              iVar8 = iVar8 + 1;
            } while (bVar1);
          }
        }
        mutex_unlock(lVar3 + 8);
        return 0;
      }
      puVar5 = &DAT_0010b278;
    }
  }
  _printk(puVar5,"lpass_cdc_rsc_clk_reset");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_enable_all_clocks @ 0010481c size=248
// signature: undefined lpass_cdc_clk_rsc_enable_all_clocks(void)
// callers: [lpass_cdc_ssr_enable]
//------------------------------------------------------------

void lpass_cdc_clk_rsc_enable_all_clocks(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined1 *puVar4;
  long lVar5;
  long lVar6;
  
  if (param_1 == 0) {
    puVar4 = &DAT_0010ab17;
  }
  else {
    lVar2 = lpass_cdc_get_rsc_clk_device_ptr(*(undefined8 *)(param_1 + 0x60));
    if (lVar2 == 0) {
      puVar4 = &DAT_0010b0f6;
    }
    else {
      lVar2 = *(long *)(lVar2 + 0x98);
      if (lVar2 != 0) {
        mutex_lock(lVar2 + 8);
        lVar6 = 0;
        do {
          lVar5 = *(long *)(lVar2 + 0x68 + lVar6);
          if ((param_2 & 1) == 0) {
            if ((lVar5 != 0) && (uVar3 = __clk_is_enabled(lVar5), (uVar3 & 1) != 0)) {
              lVar5 = *(long *)(lVar2 + 0x68 + lVar6);
              clk_disable(lVar5);
              goto LAB_00104868;
            }
          }
          else if (((lVar5 != 0) && (iVar1 = clk_prepare(lVar5), iVar1 == 0)) &&
                  (iVar1 = clk_enable(lVar5), iVar1 != 0)) {
LAB_00104868:
            clk_unprepare(lVar5);
          }
          lVar6 = lVar6 + 8;
          if (lVar6 == 0x60) {
            mutex_unlock(lVar2 + 8);
            return;
          }
        } while( true );
      }
      puVar4 = &DAT_0010ac2f;
    }
  }
  _printk(puVar4,"lpass_cdc_clk_rsc_enable_all_clocks");
  return;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_fs_gen_request @ 00104918 size=436
// signature: undefined lpass_cdc_clk_rsc_fs_gen_request(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_clk_rsc_fs_gen_request(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  long lVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  
  if (param_1 == 0) {
    puVar3 = &DAT_0010ab17;
  }
  else {
    lVar2 = lpass_cdc_get_rsc_clk_device_ptr(*(undefined8 *)(param_1 + 0x60));
    if (lVar2 == 0) {
      puVar3 = &DAT_0010b0f6;
    }
    else {
      plVar7 = *(long **)(lVar2 + 0x98);
      if (plVar7 == (long *)0x0) {
        puVar3 = &DAT_0010b278;
      }
      else {
        lVar2 = dev_get_regmap(*(undefined8 *)(*plVar7 + 0x60),0);
        if (lVar2 != 0) {
          mutex_lock(plVar7 + 7);
          iVar1 = (int)plVar7[0x1f];
          if ((param_2 & 1) == 0) {
            if (iVar1 < 1) {
              iVar1 = ___ratelimit(&lpass_cdc_clk_rsc_fs_gen_request__rs,
                                   "lpass_cdc_clk_rsc_fs_gen_request");
              if (iVar1 != 0) {
                _dev_err(*plVar7,"%s: req_seq_cnt: %d is already disabled\n",
                         "lpass_cdc_clk_rsc_fs_gen_request",(int)plVar7[0x1f]);
              }
              *(undefined4 *)(plVar7 + 0x1f) = 0;
            }
            else {
              *(int *)(plVar7 + 0x1f) = iVar1 + -1;
              if (iVar1 + -1 == 0) {
                iVar1 = *(int *)((long)plVar7 + 0x104) * 3;
                uVar5 = iVar1 - 3;
                uVar6 = (ulong)uVar5;
                if (-1 < (int)uVar5) {
                  iVar1 = iVar1 + -2;
                  do {
                    regmap_update_bits_base
                              (lVar2,*(undefined4 *)(plVar7[0x21] + uVar6 * 4),
                               *(undefined4 *)(plVar7[0x21] + (long)iVar1 * 4),0,0,0,0);
                    uVar6 = uVar6 - 3;
                    iVar1 = iVar1 + -3;
                  } while (-1 < (int)uVar6);
                }
              }
            }
          }
          else {
            *(int *)(plVar7 + 0x1f) = iVar1 + 1;
            if ((iVar1 == 0) && (*(int *)((long)plVar7 + 0x104) * 3 != 0)) {
              uVar5 = 0;
              do {
                lVar4 = plVar7[0x21];
                regmap_update_bits_base
                          (lVar2,*(undefined4 *)(lVar4 + (long)(int)uVar5 * 4),
                           *(undefined4 *)(lVar4 + (long)(int)(uVar5 + 1) * 4),
                           *(undefined4 *)(lVar4 + (long)(int)(uVar5 + 2) * 4),0,0,0);
                uVar5 = uVar5 + 3;
              } while (uVar5 < (uint)(*(int *)((long)plVar7 + 0x104) * 3));
            }
          }
          mutex_unlock(plVar7 + 7);
          return;
        }
        puVar3 = &DAT_0010a706;
      }
    }
  }
  _printk(puVar3,"lpass_cdc_clk_rsc_fs_gen_request");
  return;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_request_clock @ 00104ad0 size=1088
// signature: undefined lpass_cdc_clk_rsc_request_clock(void)
// callers: [lpass_cdc_runtime_suspend, lpass_cdc_runtime_resume]
//------------------------------------------------------------

int lpass_cdc_clk_rsc_request_clock(long param_1,uint param_2,uint param_3,uint param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  if (param_1 == 0) {
    puVar5 = &DAT_0010ab17;
LAB_00104d8c:
    _printk(puVar5,"lpass_cdc_clk_rsc_request_clock");
    return -0x16;
  }
  if ((0xb < param_2) && (0xb < param_3)) {
    _printk(&DAT_0010af46,"lpass_cdc_clk_rsc_request_clock",param_3,param_2);
    return -0x16;
  }
  lVar4 = lpass_cdc_get_rsc_clk_device_ptr(*(undefined8 *)(param_1 + 0x60));
  if (lVar4 == 0) {
    puVar5 = &DAT_0010b0f6;
    goto LAB_00104d8c;
  }
  puVar6 = *(undefined8 **)(lVar4 + 0x98);
  if (puVar6 == (undefined8 *)0x0) {
    puVar5 = &DAT_0010b278;
    goto LAB_00104d8c;
  }
  puVar1 = puVar6 + 1;
  mutex_lock(puVar1);
  if ((*(char *)(puVar6 + 0x20) == '\0') && ((param_4 & 1) != 0)) {
    iVar3 = ___ratelimit(lpass_cdc_clk_rsc_request_clock__rs,"lpass_cdc_clk_rsc_request_clock");
    if (iVar3 != 0) {
      _dev_err(*puVar6,"%s: SSR is in progress..\n","lpass_cdc_clk_rsc_request_clock");
    }
    iVar3 = -0x16;
    goto LAB_00104db8;
  }
  if (0xb < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104f10);
    (*pcVar2)();
  }
  *(uint *)((long)puVar6 + (ulong)param_3 * 4 + 0x110) = param_2;
  if (param_2 == param_3) {
    iVar3 = lpass_cdc_clk_rsc_mux0_clk_request(puVar6,param_3,param_4 & 1);
joined_r0x00104b9c:
    if (iVar3 < 0) goto LAB_00104db8;
  }
  else if (param_3 != 3) {
    iVar3 = lpass_cdc_clk_rsc_mux1_clk_request(puVar6,param_3,param_4 & 1);
    goto joined_r0x00104b9c;
  }
  if ((param_4 & 1) == 0) {
    if (param_3 != 3 || param_2 == param_3) {
      if ((*(int *)((long)puVar6 + 0xfc) != 0) &&
         (*(int *)((long)puVar6 + 0xfc) == *(int *)(puVar6 + 0x19))) {
        do {
          iVar3 = lpass_cdc_clk_rsc_mux1_clk_request(puVar6,3,1);
          if (iVar3 < 0) goto LAB_00104db8;
          if (*(int *)(puVar6 + 0x19) < 1) {
            iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                                 "lpass_cdc_clk_rsc_mux0_clk_request");
            if (iVar3 != 0) {
              _dev_err(*puVar6,"%s: clk_id: %d is already disabled\n",
                       "lpass_cdc_clk_rsc_mux0_clk_request",0);
            }
            *(undefined4 *)(puVar6 + 0x19) = 0;
          }
          else {
            iVar3 = *(int *)(puVar6 + 0x19) + -1;
            *(int *)(puVar6 + 0x19) = iVar3;
            if (iVar3 == 0) {
              uVar7 = puVar6[0xd];
              clk_disable(uVar7);
              clk_unprepare(uVar7);
            }
          }
          iVar3 = *(int *)((long)puVar6 + 0xfc) + -1;
          *(int *)((long)puVar6 + 0xfc) = iVar3;
        } while (iVar3 != 0);
      }
      goto LAB_00104e84;
    }
    iVar3 = *(int *)((long)puVar6 + 0xd4);
    if (iVar3 != 0) {
      if (puVar6[0x2b] != 0) {
        if (iVar3 < 1) {
          iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux1_clk_request__rs_10,
                               "lpass_cdc_clk_rsc_mux1_clk_request");
          if (iVar3 != 0) {
            _dev_err(*puVar6,"%s: clk_id: %d is already disabled\n",
                     "lpass_cdc_clk_rsc_mux1_clk_request",3);
          }
          *(undefined4 *)((long)puVar6 + 0xd4) = 0;
        }
        else {
          *(int *)((long)puVar6 + 0xd4) = iVar3 + -1;
          if (iVar3 + -1 == 0) {
            uVar7 = puVar6[0x10];
            clk_disable(uVar7);
            clk_unprepare(uVar7);
          }
        }
      }
      goto LAB_00104e84;
    }
    if (*(int *)((long)puVar6 + 0xfc) == 0) goto LAB_00104e84;
    if (*(int *)(puVar6 + 0x19) < 1) {
      iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                           "lpass_cdc_clk_rsc_mux0_clk_request");
      if (iVar3 != 0) {
        _dev_err(*puVar6,"%s: clk_id: %d is already disabled\n","lpass_cdc_clk_rsc_mux0_clk_request"
                 ,0);
      }
      *(undefined4 *)(puVar6 + 0x19) = 0;
    }
    else {
      iVar3 = *(int *)(puVar6 + 0x19) + -1;
      *(int *)(puVar6 + 0x19) = iVar3;
      if (iVar3 == 0) {
        uVar7 = puVar6[0xd];
        clk_disable(uVar7);
        clk_unprepare(uVar7);
      }
    }
    iVar3 = *(int *)((long)puVar6 + 0xfc) + -1;
  }
  else {
    if (param_3 != 3 || param_2 == param_3) {
      if (0 < *(int *)(puVar6 + 0x19)) {
        iVar3 = *(int *)((long)puVar6 + 0xd4);
        while (0 < iVar3) {
          iVar3 = lpass_cdc_clk_rsc_mux0_clk_request(puVar6,0,1);
          if (iVar3 < 0) goto LAB_00104db8;
          if (puVar6[0x2b] == 0) {
LAB_00104c34:
            iVar3 = *(int *)((long)puVar6 + 0xd4);
          }
          else {
            if (*(int *)((long)puVar6 + 0xd4) < 1) {
              iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux1_clk_request__rs_10,
                                   "lpass_cdc_clk_rsc_mux1_clk_request");
              if (iVar3 != 0) {
                _dev_err(*puVar6,"%s: clk_id: %d is already disabled\n",
                         "lpass_cdc_clk_rsc_mux1_clk_request",3);
              }
              iVar3 = *(int *)((long)puVar6 + 0xfc);
              *(undefined4 *)((long)puVar6 + 0xd4) = 0;
              goto LAB_00104bd4;
            }
            iVar3 = *(int *)((long)puVar6 + 0xd4) + -1;
            *(int *)((long)puVar6 + 0xd4) = iVar3;
            if (iVar3 == 0) {
              uVar7 = puVar6[0x10];
              clk_disable(uVar7);
              clk_unprepare(uVar7);
              goto LAB_00104c34;
            }
          }
          *(int *)((long)puVar6 + 0xfc) = *(int *)((long)puVar6 + 0xfc) + 1;
        }
      }
      goto LAB_00104e84;
    }
    if (*(int *)(puVar6 + 0x19) == 0) {
      iVar3 = lpass_cdc_clk_rsc_mux1_clk_request(puVar6,3,1);
      if (-1 < iVar3) goto LAB_00104e84;
LAB_00104db8:
      mutex_unlock(puVar1);
      return iVar3;
    }
    iVar3 = lpass_cdc_clk_rsc_mux0_clk_request(puVar6,0,1);
    if (iVar3 < 0) goto LAB_00104db8;
    iVar3 = *(int *)((long)puVar6 + 0xfc);
LAB_00104bd4:
    iVar3 = iVar3 + 1;
  }
  *(int *)((long)puVar6 + 0xfc) = iVar3;
LAB_00104e84:
  mutex_unlock(puVar1);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_mux1_clk_request @ 00104f10 size=944
// signature: undefined lpass_cdc_clk_rsc_mux1_clk_request(void)
// callers: [lpass_cdc_clk_rsc_request_clock]
//------------------------------------------------------------

int lpass_cdc_clk_rsc_mux1_clk_request(undefined8 *param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  int *piVar10;
  
  if (0xb < param_2) goto LAB_001052bc;
  switch(param_2) {
  case 1:
    lVar7 = param_1[0x29];
    break;
  case 2:
  case 4:
    lVar7 = param_1[0x2a];
    break;
  case 3:
    lVar7 = param_1[0x2b];
    break;
  default:
    iVar3 = ___ratelimit(lpass_cdc_clk_rsc_get_clk_muxsel__rs,"lpass_cdc_clk_rsc_get_clk_muxsel");
    if (iVar3 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: Invalid case\n","lpass_cdc_clk_rsc_get_clk_muxsel");
    return -0x16;
  }
  if (lVar7 == 0) {
    return -0x16;
  }
  lVar8 = (long)(int)param_2;
  uVar1 = *(uint *)((long)param_1 + lVar8 * 4 + 0x110);
  lVar5 = (long)(int)uVar1;
  piVar10 = (int *)((long)param_1 + lVar8 * 4 + 200);
  iVar3 = *piVar10;
  if ((param_3 & 1) != 0) {
    if (iVar3 != 0) {
      iVar3 = 0;
      goto LAB_00104fd4;
    }
    if ((param_2 != 3) && (iVar3 = lpass_cdc_clk_rsc_mux0_clk_request(param_1,uVar1,1), iVar3 < 0))
    {
      return iVar3;
    }
    uVar9 = param_1[lVar8 + 0xd];
    iVar3 = clk_prepare(uVar9);
    if (iVar3 == 0) {
      iVar3 = clk_enable(uVar9);
      if (iVar3 != 0) {
        clk_unprepare(uVar9);
        goto LAB_0010507c;
      }
    }
    else {
LAB_0010507c:
      if (iVar3 < 0) {
        iVar4 = ___ratelimit(lpass_cdc_clk_rsc_mux1_clk_request__rs,
                             "lpass_cdc_clk_rsc_mux1_clk_request");
        if (iVar4 != 0) {
          _dev_err(*param_1,"%s:clk_id %d enable failed\n","lpass_cdc_clk_rsc_mux1_clk_request",
                   param_2);
        }
        if (param_2 == 3) {
          return iVar3;
        }
        lpass_cdc_clk_rsc_mux0_clk_request(param_1,uVar1,0);
        return iVar3;
      }
    }
    if (param_2 == 3) {
LAB_00104fd4:
      *piVar10 = *piVar10 + 1;
      return iVar3;
    }
    if (*(char *)((long)param_1 + 0x101) != '\0') {
      writel(1,lVar7);
      readl(lVar7);
    }
    if (uVar1 < 0xc) {
      piVar6 = (int *)((long)param_1 + lVar5 * 4 + 200);
      if (*piVar6 < 1) {
        iVar4 = ___ratelimit(lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                             "lpass_cdc_clk_rsc_mux0_clk_request");
        if (iVar4 != 0) {
          _dev_err(*param_1,"%s: clk_id: %d is already disabled\n",
                   "lpass_cdc_clk_rsc_mux0_clk_request",uVar1);
        }
        *piVar6 = 0;
      }
      else {
        iVar4 = *piVar6 + -1;
        *piVar6 = iVar4;
        if (iVar4 == 0) {
          uVar9 = param_1[lVar5 + 0xd];
          clk_disable(uVar9);
          clk_unprepare(uVar9);
        }
      }
      goto LAB_00104fd4;
    }
    goto LAB_001052bc;
  }
  if (iVar3 < 1) {
    iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux1_clk_request__rs_10,
                         "lpass_cdc_clk_rsc_mux1_clk_request");
    if (iVar3 != 0) {
      _dev_err(*param_1,"%s: clk_id: %d is already disabled\n","lpass_cdc_clk_rsc_mux1_clk_request",
               param_2);
    }
    *piVar10 = 0;
    return 0;
  }
  *piVar10 = iVar3 + -1;
  if (iVar3 + -1 != 0) {
    return 0;
  }
  if (param_2 == 3) {
LAB_00105110:
    iVar3 = 0;
  }
  else {
    iVar3 = lpass_cdc_clk_rsc_mux0_clk_request(param_1,uVar1,1);
    if (iVar3 == 0) {
      if (*(char *)((long)param_1 + 0x101) != '\0') {
        writel(0,lVar7);
        readl(lVar7);
      }
      goto LAB_00105110;
    }
  }
  uVar9 = param_1[lVar8 + 0xd];
  clk_disable(uVar9);
  clk_unprepare(uVar9);
  if (param_2 == 3) {
    return iVar3;
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  if (uVar1 < 0xc) {
    piVar10 = (int *)((long)param_1 + lVar5 * 4 + 200);
    if (*piVar10 < 1) {
      iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                           "lpass_cdc_clk_rsc_mux0_clk_request");
      if (iVar3 != 0) {
        _dev_err(*param_1,"%s: clk_id: %d is already disabled\n",
                 "lpass_cdc_clk_rsc_mux0_clk_request",uVar1);
      }
      *piVar10 = 0;
      return 0;
    }
    iVar3 = *piVar10 + -1;
    *piVar10 = iVar3;
    if (iVar3 == 0) {
      uVar9 = param_1[lVar5 + 0xd];
      clk_disable(uVar9);
      clk_unprepare(uVar9);
    }
    return 0;
  }
LAB_001052bc:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1052c0);
  (*pcVar2)();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_mux0_clk_request @ 001052c0 size=364
// signature: undefined lpass_cdc_clk_rsc_mux0_clk_request(void)
// callers: [lpass_cdc_clk_rsc_request_clock, lpass_cdc_clk_rsc_mux1_clk_request]
//------------------------------------------------------------

int lpass_cdc_clk_rsc_mux0_clk_request(undefined8 *param_1,uint param_2,ulong param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  int *piVar6;
  
  lVar4 = (long)(int)param_2;
  if ((param_3 & 1) == 0) {
    if (param_2 < 0xc) {
      piVar6 = (int *)((long)param_1 + lVar4 * 4 + 200);
      if (*piVar6 < 1) {
        iVar2 = ___ratelimit(lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                             "lpass_cdc_clk_rsc_mux0_clk_request");
        if (iVar2 != 0) {
          _dev_err(*param_1,"%s: clk_id: %d is already disabled\n",
                   "lpass_cdc_clk_rsc_mux0_clk_request",param_2);
        }
        *piVar6 = 0;
        return 0;
      }
      iVar2 = *piVar6 + -1;
      *piVar6 = iVar2;
      if (iVar2 == 0) {
        uVar5 = param_1[lVar4 + 0xd];
        clk_disable(uVar5);
        clk_unprepare(uVar5);
      }
      return 0;
    }
  }
  else if (param_2 < 0xc) {
    piVar6 = (int *)((long)param_1 + lVar4 * 4 + 200);
    if (*piVar6 == 0) {
      uVar5 = param_1[lVar4 + 0xd];
      iVar2 = clk_prepare(uVar5);
      if (iVar2 == 0) {
        iVar2 = clk_enable(uVar5);
        if (iVar2 == 0) goto LAB_001053a8;
        clk_unprepare(uVar5);
      }
      if (iVar2 < 0) {
        iVar3 = ___ratelimit(lpass_cdc_clk_rsc_mux0_clk_request__rs,
                             "lpass_cdc_clk_rsc_mux0_clk_request");
        if (iVar3 == 0) {
          return iVar2;
        }
        _dev_err(*param_1,"%s:clk_id %d enable failed\n","lpass_cdc_clk_rsc_mux0_clk_request",
                 param_2);
        return iVar2;
      }
    }
    else {
      iVar2 = 0;
    }
LAB_001053a8:
    *piVar6 = *piVar6 + 1;
    return iVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10542c);
  (*pcVar1)();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_mgr_init @ 00105430 size=44
// signature: undefined lpass_cdc_clk_rsc_mgr_init(void)
// callers: [init_module]
//------------------------------------------------------------

void lpass_cdc_clk_rsc_mgr_init(void)

{
  __platform_driver_register(&lpass_cdc_clk_rsc_mgr,&__this_module);
  return;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_mgr_exit @ 00105460 size=36
// signature: undefined lpass_cdc_clk_rsc_mgr_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void lpass_cdc_clk_rsc_mgr_exit(void)

{
  platform_driver_unregister(&lpass_cdc_clk_rsc_mgr);
  return;
}



//------------------------------------------------------------
// writel @ 00105484 size=136
// signature: undefined writel(void)
// callers: [lpass_cdc_clk_rsc_mux1_clk_request]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10549c,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1054dc,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 0010550c size=140
// signature: undefined readl(void)
// callers: [lpass_cdc_clk_rsc_mux1_clk_request]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x105564,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_probe @ 0010559c size=968
// signature: undefined lpass_cdc_clk_rsc_probe(void)
// callers: []
//------------------------------------------------------------

ulong lpass_cdc_clk_rsc_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 *puVar9;
  char *pcVar10;
  undefined4 local_70;
  int local_6c;
  long local_68;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar5 + 0x638);
  local_6c = 0;
  local_70 = 0;
  plVar4 = (long *)devm_kmalloc(lVar1,0x160,0xdc0);
  if (plVar4 == (long *)0x0) {
LAB_00105738:
    uVar8 = 0xfffffff4;
    goto LAB_0010573c;
  }
  lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,fs-gen-sequence",&local_6c);
  if (lVar5 == 0) {
    _dev_err(lVar1,"%s: unable to find qcom,fs-gen-sequence property\n","lpass_cdc_clk_rsc_probe");
    uVar8 = 0xffffffea;
    goto LAB_0010573c;
  }
  iVar3 = (int)((ulong)(long)local_6c / 0xc);
  *(int *)((long)plVar4 + 0x104) = iVar3;
  lVar5 = devm_kmalloc(lVar1,(long)local_6c,0xdc0);
  plVar4[0x21] = lVar5;
  if (lVar5 == 0) goto LAB_00105738;
  uVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,fs-gen-sequence",lVar5,iVar3 * 3,0);
  if ((int)uVar2 < 0) {
    uVar8 = (ulong)uVar2;
    pcVar10 = "%s: unable to parse fs-gen-sequence, ret = %d\n";
  }
  else {
    uVar2 = of_property_read_string_helper(*(undefined8 *)(param_1 + 0x2f8),"clock-names",0,0,0);
    uVar7 = (ulong)uVar2;
    if (uVar2 - 0xd < 0xfffffff4) {
      _dev_err(lVar1,"%s: Invalid number of clocks %d","lpass_cdc_clk_rsc_probe",uVar7);
      uVar8 = 0xffffffea;
      goto LAB_0010573c;
    }
    puVar6 = (undefined8 *)devm_kmalloc(lVar1,uVar7 << 3,0xdc0);
    if (puVar6 == (undefined8 *)0x0) goto LAB_00105738;
    of_property_read_string_helper(*(undefined8 *)(param_1 + 0x2f8),"clock-names",puVar6,uVar7,0);
    lVar5 = 0;
    do {
      pcVar10 = clk_src_name + lVar5 * 0x1e;
      plVar4[lVar5 + 0xd] = 0;
      uVar8 = uVar7;
      puVar9 = puVar6;
      do {
        iVar3 = strcmp(pcVar10,(char *)*puVar9);
        if (iVar3 == 0) {
          uVar8 = devm_clk_get(lVar1,pcVar10);
          if (0xfffffffffffff000 < uVar8) {
            _dev_err(lVar1,"%s: clk get failed for %s with ret %d\n","lpass_cdc_clk_rsc_probe",
                     pcVar10,uVar8 & 0xffffffff);
            goto LAB_0010573c;
          }
          plVar4[lVar5 + 0xd] = uVar8;
          break;
        }
        puVar9 = puVar9 + 1;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
      lVar5 = lVar5 + 1;
    } while (lVar5 != 0xc);
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,rx_mclk_mode_muxsel",&local_70,1,0);
    if (-1 < iVar3) {
      lVar5 = devm_ioremap(lVar1,local_70,4);
      plVar4[0x29] = lVar5;
      if (lVar5 != 0) goto LAB_001057b8;
      pcVar10 = "%s: ioremap failed for rx muxsel\n";
LAB_00105924:
      _dev_err(lVar1,pcVar10,"lpass_cdc_clk_rsc_probe");
      uVar8 = 0xfffffff4;
      goto LAB_0010573c;
    }
LAB_001057b8:
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,wsa_mclk_mode_muxsel",&local_70,1,0);
    if (-1 < iVar3) {
      lVar5 = devm_ioremap(lVar1,local_70,4);
      plVar4[0x2a] = lVar5;
      if (lVar5 == 0) {
        pcVar10 = "%s: ioremap failed for wsa muxsel\n";
        goto LAB_00105924;
      }
    }
    iVar3 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,va_mclk_mode_muxsel",&local_70,1,0);
    if (-1 < iVar3) {
      lVar5 = devm_ioremap(lVar1,local_70,4);
      plVar4[0x2b] = lVar5;
      if (lVar5 == 0) {
        pcVar10 = "%s: ioremap failed for va muxsel\n";
        goto LAB_00105924;
      }
    }
    uVar7 = lpass_cdc_register_res_clk(lVar1,lpass_cdc_clk_rsc_cb);
    uVar8 = uVar7 & 0xffffffff;
    if (-1 < (int)uVar7) {
      *plVar4 = lVar1;
      *(undefined2 *)(plVar4 + 0x20) = 0x101;
      __mutex_init(plVar4 + 1,"&priv->rsc_clk_lock",&lpass_cdc_clk_rsc_probe___key);
      __mutex_init(plVar4 + 7,"&priv->fs_gen_lock",&lpass_cdc_clk_rsc_probe___key_29);
      *(long **)(param_1 + 0xa8) = plVar4;
      goto LAB_0010573c;
    }
    pcVar10 = "%s: Failed to register cb %d";
  }
  _dev_err(lVar1,pcVar10,"lpass_cdc_clk_rsc_probe",uVar8);
LAB_0010573c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_remove @ 00105968 size=68
// signature: undefined lpass_cdc_clk_rsc_remove(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_clk_rsc_remove(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  lpass_cdc_unregister_res_clk(param_1 + 0x10);
  of_platform_depopulate(param_1 + 0x10);
  uVar1 = 0xffffffea;
  if (lVar2 != 0) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_cb @ 001059b0 size=176
// signature: undefined lpass_cdc_clk_rsc_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_clk_rsc_cb(long param_1,short param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_0010aaf9;
  }
  else {
    lVar2 = *(long *)(param_1 + 0x98);
    if (lVar2 != 0) {
      mutex_lock(lVar2 + 8);
      if (param_2 == 4) {
        *(undefined2 *)(lVar2 + 0x100) = 0;
      }
      else if (param_2 == 0xb) {
        *(undefined1 *)(lVar2 + 0x101) = 1;
      }
      else if (param_2 == 5) {
        *(undefined1 *)(lVar2 + 0x100) = 1;
      }
      mutex_unlock(lVar2 + 8);
      return 0;
    }
    puVar1 = &DAT_0010b01c;
  }
  _printk(puVar1,"lpass_cdc_clk_rsc_cb");
  return 0xffffffea;
}



//------------------------------------------------------------
// init_module @ 00108a5c size=52
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  __platform_driver_register(&lpass_cdc_drv,&__this_module);
  lpass_cdc_clk_rsc_mgr_init();
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00108a94 size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  lpass_cdc_clk_rsc_mgr_exit();
  platform_driver_unregister(&lpass_cdc_drv);
  return;
}



//------------------------------------------------------------
// of_device_is_compatible @ 0010d000 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [lpass_cdc_register_macro, lpass_cdc_unregister_res_clk, lpass_cdc_get_device_ptr, lpass_cdc_register_res_clk, lpass_cdc_get_version, lpass_cdc_wsa_pa_on, lpass_cdc_get_rsc_clk_device_ptr, lpass_cdc_register_event_listener, lpass_cdc_clear_amic_tx_hold, lpass_cdc_unregister_macro, lpass_cdc_set_port_map, lpass_cdc_is_va_macro_registered, lpass_cdc_register_wake_irq, lpass_cdc_tx_mclk_enable, lpass_cdc_notify_wcd_rx_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010d008 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_cdc_register_res_clk, lpass_cdc_dmic_clk_enable, lpass_cdc_ssr_disable, lpass_cdc_wsa_pa_on, lpass_cdc_get_rsc_clk_device_ptr, lpass_cdc_register_event_listener, lpass_cdc_unregister_macro, lpass_cdc_set_port_map, lpass_cdc_clk_rsc_fs_gen_request, lpass_cdc_runtime_resume, lpass_cdc_version_read, lpass_cdc_tx_mclk_enable, regmap_bus_write, regmap_bus_read, lpass_cdc_unregister_res_clk, lpass_cdc_clk_rsc_request_clock, lpass_cdc_get_device_ptr, lpass_cdc_clk_rsc_mux1_clk_request, lpass_cdc_clk_rsc_mux0_clk_request, regmap_bus_gather_write, lpass_cdc_update_wcd_event, lpass_cdc_is_va_macro_registered, lpass_cdc_register_wake_irq, lpass_cdc_info_create_codec_entry, lpass_cdc_notify_wcd_rx_clk, lpass_cdc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d010 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_cdc_register_macro, lpass_cdc_add_child_devices, lpass_cdc_soc_codec_probe, lpass_cdc_register_res_clk, lpass_cdc_dmic_clk_enable, lpass_cdc_ssr_disable, lpass_cdc_wsa_pa_on, lpass_cdc_get_rsc_clk_device_ptr, lpass_cdc_register_event_listener, lpass_cdc_unregister_macro, lpass_cdc_set_port_map, lpass_cdc_clk_rsc_fs_gen_request, lpass_cdc_runtime_resume, lpass_cdc_tx_mclk_enable, regmap_bus_write, regmap_bus_read, lpass_cdc_unregister_res_clk, lpass_cdc_clk_rsc_request_clock, lpass_cdc_get_device_ptr, lpass_cdc_clk_rsc_mux1_clk_request, lpass_cdc_clk_rsc_mux0_clk_request, lpass_cdc_get_version, regmap_bus_gather_write, lpass_cdc_clear_amic_tx_hold, lpass_cdc_probe, lpass_cdc_update_wcd_event, lpass_cdc_clk_rsc_probe, lpass_cdc_is_va_macro_registered, lpass_cdc_register_wake_irq, lpass_cdc_info_create_codec_entry, lpass_cdc_notify_wcd_rx_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 0010d018 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [lpass_cdc_clear_amic_tx_hold, lpass_cdc_ssr_enable, lpass_cdc_ssr_disable, lpass_cdc_notify_wcd_rx_clk, lpass_cdc_wsa_pa_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010d020 size=1
// signature: undefined _printk(void)
// callers: [lpass_cdc_register_macro, lpass_cdc_unregister_res_clk, lpass_cdc_clk_rsc_request_clock, lpass_cdc_get_device_ptr, lpass_cdc_add_child_devices, lpass_cdc_clk_rsc_cb, lpass_cdc_register_res_clk, lpass_cdc_rsc_clk_reset, lpass_cdc_get_version, lpass_cdc_wsa_pa_on, lpass_cdc_get_rsc_clk_device_ptr, lpass_cdc_clear_amic_tx_hold, lpass_cdc_unregister_macro, lpass_cdc_update_wcd_event, lpass_cdc_clk_rsc_fs_gen_request, lpass_cdc_is_va_macro_registered, lpass_cdc_version_read, lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_notify_wcd_rx_clk, lpass_cdc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0010d028 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [lpass_cdc_dmic_clk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010d030 size=1
// signature: undefined mutex_lock(void)
// callers: [lpass_cdc_runtime_suspend, lpass_cdc_check_core_votes, lpass_cdc_register_macro, lpass_cdc_ssr_enable, lpass_cdc_clk_rsc_request_clock, lpass_cdc_clk_rsc_cb, lpass_cdc_ssr_disable, lpass_cdc_rsc_clk_reset, __lpass_cdc_reg_read, regmap_bus_gather_write, lpass_cdc_clk_rsc_fs_gen_request, lpass_cdc_runtime_resume, lpass_cdc_clk_rsc_enable_all_clocks, regmap_bus_read, __lpass_cdc_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010d038 size=1
// signature: undefined _dev_info(void)
// callers: [lpass_cdc_register_macro]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010d040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_cdc_probe, lpass_cdc_register_macro, lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010d048 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lpass_cdc_register_macro, lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 0010d050 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [lpass_cdc_register_macro]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010d058 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpass_cdc_runtime_suspend, lpass_cdc_check_core_votes, lpass_cdc_register_macro, lpass_cdc_ssr_enable, lpass_cdc_clk_rsc_request_clock, lpass_cdc_clk_rsc_cb, lpass_cdc_ssr_disable, lpass_cdc_rsc_clk_reset, __lpass_cdc_reg_read, regmap_bus_gather_write, lpass_cdc_clk_rsc_fs_gen_request, lpass_cdc_runtime_resume, lpass_cdc_clk_rsc_enable_all_clocks, regmap_bus_read, __lpass_cdc_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 0010d060 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [lpass_cdc_unregister_macro]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_module_entry @ 0010d068 size=1
// signature: undefined snd_info_create_module_entry(void)
// callers: [lpass_cdc_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_module_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_register @ 0010d070 size=1
// signature: undefined snd_info_register(void)
// callers: [lpass_cdc_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_create_card_entry @ 0010d078 size=1
// signature: undefined snd_info_create_card_entry(void)
// callers: [lpass_cdc_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_create_card_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_info_free_entry @ 0010d080 size=1
// signature: undefined snd_info_free_entry(void)
// callers: [lpass_cdc_info_create_codec_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_info_free_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_enable @ 0010d088 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_enable(void)
// callers: [lpass_cdc_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010d090 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_cdc_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_disable @ 0010d098 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_disable(void)
// callers: [lpass_cdc_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010d0a0 size=1
// signature: undefined __platform_driver_register(void)
// callers: [lpass_cdc_clk_rsc_mgr_init, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 0010d0a8 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [lpass_cdc_clk_rsc_mgr_exit, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0010d0b0 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [lpass_cdc_version_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010d0b8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_cdc_probe, lpass_cdc_clk_rsc_probe, lpass_cdc_version_read, lpass_cdc_add_child_devices, regmap_bus_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 0010d0c0 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [lpass_cdc_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0010d0c8 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [lpass_cdc_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_register @ 0010d0d0 size=1
// signature: undefined snd_event_client_register(void)
// callers: [lpass_cdc_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_notify @ 0010d0d8 size=1
// signature: undefined snd_event_notify(void)
// callers: [lpass_cdc_soc_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_deregister @ 0010d0e0 size=1
// signature: undefined snd_event_client_deregister(void)
// callers: [lpass_cdc_soc_codec_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_cache_only @ 0010d0e8 size=1
// signature: undefined regcache_cache_only(void)
// callers: [lpass_cdc_ssr_enable, lpass_cdc_ssr_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_cache_only(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0010d0f0 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [lpass_cdc_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 0010d0f8 size=1
// signature: undefined regcache_sync(void)
// callers: [lpass_cdc_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010d100 size=1
// signature: undefined usleep_range_state(void)
// callers: [lpass_cdc_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010d108 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpass_cdc_probe, lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 0010d110 size=1
// signature: undefined __init_rwsem(void)
// callers: [lpass_cdc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 0010d118 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [lpass_cdc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010d120 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_cdc_probe, lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010d128 size=1
// signature: undefined devm_clk_get(void)
// callers: [lpass_cdc_probe, lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010d138 size=1
// signature: undefined queue_work_on(void)
// callers: [lpass_cdc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_depopulate @ 0010d140 size=1
// signature: undefined of_platform_depopulate(void)
// callers: [lpass_cdc_remove, lpass_cdc_clk_rsc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_depopulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010d148 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [__lpass_cdc_reg_read, __lpass_cdc_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010d150 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [__lpass_cdc_reg_read, __lpass_cdc_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010d158 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [__lpass_cdc_reg_read, __lpass_cdc_reg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 0010d160 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [lpass_cdc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 0010d168 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [lpass_cdc_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010d170 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010d178 size=1
// signature: undefined of_find_property(void)
// callers: [lpass_cdc_clk_rsc_probe, lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010d180 size=1
// signature: size_t strlen(char * __s)
// callers: [lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 0010d188 size=1
// signature: undefined platform_device_alloc(void)
// callers: [lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 0010d190 size=1
// signature: undefined platform_device_add(void)
// callers: [lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 0010d198 size=1
// signature: undefined platform_device_put(void)
// callers: [lpass_cdc_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010d1a0 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010d1a8 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010d1b0 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010d1b8 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0010d1c0 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [lpass_cdc_update_compander_setting, lpass_cdc_load_compander_coeff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init @ 0010d1c8 size=1
// signature: undefined __devm_regmap_init(void)
// callers: [lpass_cdc_regmap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __clk_is_enabled @ 0010d1d0 size=1
// signature: undefined __clk_is_enabled(void)
// callers: [lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_rsc_clk_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __clk_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0010d1d8 size=1
// signature: undefined clk_disable(void)
// callers: [lpass_cdc_clk_rsc_request_clock, lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_clk_rsc_mux1_clk_request, lpass_cdc_clk_rsc_mux0_clk_request, lpass_cdc_rsc_clk_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0010d1e0 size=1
// signature: undefined clk_unprepare(void)
// callers: [lpass_cdc_clk_rsc_request_clock, lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_clk_rsc_mux1_clk_request, lpass_cdc_clk_rsc_mux0_clk_request, lpass_cdc_rsc_clk_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0010d1e8 size=1
// signature: undefined clk_prepare(void)
// callers: [lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_clk_rsc_mux1_clk_request, lpass_cdc_clk_rsc_mux0_clk_request, lpass_cdc_rsc_clk_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0010d1f0 size=1
// signature: undefined clk_enable(void)
// callers: [lpass_cdc_clk_rsc_enable_all_clocks, lpass_cdc_clk_rsc_mux1_clk_request, lpass_cdc_clk_rsc_mux0_clk_request, lpass_cdc_rsc_clk_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 0010d1f8 size=1
// signature: undefined dev_get_regmap(void)
// callers: [lpass_cdc_clk_rsc_fs_gen_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0010d200 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [lpass_cdc_clk_rsc_fs_gen_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0010d208 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010d210 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0010d218 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpass_cdc_clk_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



