// Decompiled by Ghidra 12.2
// Program: lpass_cdc_va_macro_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_cdc_va_macro_probe @ 00100894 size=1628
// signature: undefined lpass_cdc_va_macro_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong lpass_cdc_va_macro_probe(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  char *pcVar10;
  undefined2 uVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 local_118;
  undefined8 local_110;
  code *local_108;
  code *pcStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined **local_e8;
  undefined8 uStack_e0;
  code *local_d8;
  code *pcStack_d0;
  code *local_c8;
  code *pcStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  long local_a8;
  undefined8 local_a0;
  long local_98 [11];
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_98[10] = *(long *)(lVar7 + 0x638);
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = (code *)0x0;
  pcStack_c0 = (code *)0x0;
  local_d8 = (code *)0x0;
  pcStack_d0 = (code *)0x0;
  local_e8 = (undefined **)0x0;
  uStack_e0 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = (code *)0x0;
  pcStack_100 = (code *)0x0;
  local_118 = 0;
  local_110 = 0;
  plVar5 = (long *)devm_kmalloc(lVar1,0x6d0,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar13 = 0xfffffff4;
    goto LAB_00100984;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  *plVar5 = lVar1;
  uVar3 = of_property_read_variable_u32_array(uVar6,&DAT_0010c3ee,(long)&local_110 + 4,1,0);
  if ((int)uVar3 < 0) {
    uVar13 = (ulong)uVar3;
    _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_va_macro_probe",&DAT_0010c3ee);
    goto LAB_00100984;
  }
  iVar4 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,va-dmic-sample-rate",&local_110,1,0);
  if (-1 < iVar4) {
    if ((uint)local_110 != 0) {
      uVar3 = 0;
      if ((uint)local_110 != 0) {
        uVar3 = 9600000 / (uint)local_110;
      }
      if (uVar3 * (uint)local_110 == 9600000) {
        uVar12 = (uint)((ulong)uVar3 - 2);
        if ((uVar12 < 0xf) && ((0x4057U >> (ulong)(uVar12 & 0x1f) & 1) != 0)) {
          uVar11 = *(undefined2 *)(&DAT_0010ac40 + ((ulong)uVar3 - 2) * 2);
          goto LAB_00100a0c;
        }
      }
    }
    uVar13 = 0xffffffea;
    goto LAB_00100984;
  }
  _dev_err(lVar1,"%s: could not find %d entry in dt\n","lpass_cdc_va_macro_probe");
  uVar11 = 0;
LAB_00100a0c:
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  *(undefined2 *)(plVar5 + 0xb6) = uVar11;
  lVar7 = of_find_property(uVar6,"qcom,is-used-swr-gpio",0);
  if ((lVar7 != 0) &&
     (iVar4 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,is-used-swr-gpio",&local_118,1,0),
     iVar4 < 0)) {
    _dev_err(lVar1,"%s: error reading %s in dt\n","lpass_cdc_va_macro_probe","qcom,is-used-swr-gpio"
            );
    local_118 = local_118 & 0xffffffff00000000;
  }
  local_98[8] = 0;
  local_98[9] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[0] = 0;
  local_98[1] = 0;
  iVar4 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,va-swr-gpios",0,0,0,local_98);
  lVar7 = local_98[0];
  if (iVar4 != 0) {
    lVar7 = 0;
  }
  plVar5[0xb8] = lVar7;
  if ((lVar7 == 0) && ((int)local_118 != 0)) {
    pcVar10 = "%s: swr_gpios handle not provided!\n";
  }
  else {
    iVar4 = msm_cdc_pinctrl_get_state();
    if ((iVar4 < 0) && ((int)local_118 != 0)) {
      _dev_err(lVar1,"%s: failed to get swr pin state\n","lpass_cdc_va_macro_probe");
      uVar13 = 0xfffffdfb;
      goto LAB_00100984;
    }
    lVar7 = devm_ioremap(lVar1,local_110._4_4_,0x1000);
    if (lVar7 != 0) {
      plVar5[200] = lVar7;
      uVar8 = devm_clk_get(lVar1,"lpass_audio_hw_vote");
      uVar13 = 0;
      if (uVar8 < 0xfffffffffffff001) {
        uVar13 = uVar8;
      }
      uVar6 = *(undefined8 *)(param_1 + 0x2f8);
      local_98[8] = 0;
      local_98[9] = 0;
      local_98[6] = 0;
      local_98[7] = 0;
      plVar5[2] = uVar13;
      local_98[4] = 0;
      local_98[5] = 0;
      local_98[2] = 0;
      local_98[3] = 0;
      local_98[0] = 0;
      local_98[1] = 0;
      iVar4 = __of_parse_phandle_with_args(uVar6,"va-vdd-micb-supply",0,0,0,local_98);
      if ((iVar4 == 0) && (local_98[0] != 0)) {
        uVar13 = devm_regulator_get(lVar1,"va-vdd-micb");
        plVar5[0xcd] = uVar13;
        if (0xfffffffffffff000 < uVar13) {
          _dev_err(lVar1,"%s:Failed to get micbias supply for VA Mic %d\n",
                   "lpass_cdc_va_macro_probe",uVar13 & 0xffffffff);
          goto LAB_00100984;
        }
        uVar8 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,va-vdd-micb-voltage",plVar5 + 0xce
                           ,1,0);
        uVar13 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) {
          _dev_err(lVar1,"%s:Looking up %s property in node %s failed\n","lpass_cdc_va_macro_probe",
                   "qcom,va-vdd-micb-voltage",*(undefined8 *)(*(long *)(param_1 + 0x2f8) + 0x10));
          goto LAB_00100984;
        }
        uVar3 = of_property_read_variable_u32_array
                          (*(long *)(param_1 + 0x2f8),"qcom,va-vdd-micb-current",
                           (long)plVar5 + 0x674,1,0);
        if ((int)uVar3 < 0) {
          uVar13 = (ulong)uVar3;
          _dev_err(param_1 + 0x10,"%s:Looking up %s property in node %s failed\n",
                   "lpass_cdc_va_macro_probe","qcom,va-vdd-micb-current",
                   *(undefined8 *)(*(long *)(param_1 + 0x2f8) + 0x10));
          goto LAB_00100984;
        }
      }
      uVar11 = 3;
      local_98[0] = CONCAT44(local_98[0]._4_4_,3);
      lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,use-clk-id",0);
      if (lVar9 != 0) {
        iVar4 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,use-clk-id",local_98,1,0);
        if (iVar4 < 0) {
          local_98[0] = CONCAT44(local_98[0]._4_4_,3);
        }
        else {
          uVar11 = (undefined2)local_98[0];
        }
      }
      uVar6 = *(undefined8 *)(param_1 + 0x2f8);
      *(undefined2 *)((long)plVar5 + 0x686) = uVar11;
      iVar4 = of_property_read_variable_u32_array
                        (uVar6,"qcom,default-clk-id",(long)&local_118 + 4,1,0);
      if (iVar4 < 0) {
        _dev_err(lVar1,"%s: could not find %s entry in dt\n","lpass_cdc_va_macro_probe",
                 "qcom,default-clk-id");
        local_118 = CONCAT44((undefined4)local_98[0],(int)local_118);
        uVar2 = (undefined4)local_98[0];
      }
      else {
        uVar2 = local_118._4_4_;
      }
      uVar6 = *(undefined8 *)(param_1 + 0x2f8);
      *(short *)((long)plVar5 + 0x684) = (short)uVar2;
      *(undefined2 *)(plVar5 + 0xd8) = 0;
      *(undefined4 *)(plVar5 + 0xd9) = 0;
      *(undefined1 *)((long)plVar5 + 0x6c5) = 0;
      lVar9 = of_find_property(uVar6,"use-lpi-control",0);
      if (lVar9 != 0) {
        *(undefined1 *)((long)plVar5 + 0x6c5) = 1;
      }
      uVar2 = 0;
      if ((int)local_118 != 0) {
        *(undefined1 *)(plVar5 + 0xb7) = 1;
        plVar5[0xc1] = 0xfffffffe0;
        plVar5[0xc2] = (long)(plVar5 + 0xc2);
        plVar5[0xc3] = (long)(plVar5 + 0xc2);
        plVar5[0xc4] = (long)lpass_cdc_va_macro_add_child_devices;
        plVar5[0xba] = (long)plVar5;
        plVar5[0xbb] = 0;
        plVar5[0xbc] = 0;
        plVar5[0xbe] = (long)lpass_cdc_va_macro_swrm_clock;
        plVar5[0xbd] = 0;
        plVar5[0xc0] = 0;
        plVar5[0xbf] = (long)lpass_cdc_va_macro_core_vote;
        __mutex_init(plVar5 + 9,"&va_priv->swr_clk_lock",&lpass_cdc_va_macro_probe___key);
        uVar2 = (int)local_118;
      }
      *(undefined4 *)((long)plVar5 + 0x67c) = uVar2;
      *(undefined1 *)((long)plVar5 + 0x6c3) = 1;
      __mutex_init(plVar5 + 3,"&va_priv->mclk_lock",&lpass_cdc_va_macro_probe___key_22);
      __mutex_init(plVar5 + 0xf,"&va_priv->wlock",&lpass_cdc_va_macro_probe___key_24);
      uStack_f0 = 0;
      local_e8 = &lpass_cdc_va_macro_dai;
      uStack_e0 = 0;
      local_f8 = 3;
      local_108 = lpass_cdc_va_macro_init;
      pcStack_100 = lpass_cdc_va_macro_deinit;
      *(long **)(param_1 + 0xa8) = plVar5;
      local_d8 = lpass_cdc_va_macro_event_handler;
      pcStack_d0 = lpass_cdc_va_macro_reg_wake_irq;
      local_b8 = 0;
      uStack_b0 = 0;
      local_c8 = lpass_cdc_va_macro_set_port_map;
      pcStack_c0 = lpass_cdc_va_macro_clk_div_get;
      local_a0 = (ulong)CONCAT22(*(undefined2 *)((long)plVar5 + 0x684),
                                 *(undefined2 *)((long)plVar5 + 0x684));
      local_a8 = lVar7;
      uVar8 = lpass_cdc_register_macro(lVar1,3,&local_108);
      uVar13 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        _dev_err(lVar1,"%s: register macro failed\n","lpass_cdc_va_macro_probe");
      }
      else {
        pm_runtime_set_autosuspend_delay(lVar1,100);
        __pm_runtime_use_autosuspend(lVar1,1);
        __pm_runtime_set_status(lVar1,2);
        *(ushort *)(param_1 + 0x210) = *(ushort *)(param_1 + 0x210) | 0x100;
        pm_runtime_enable(lVar1);
        if ((int)local_118 != 0) {
          queue_work_on(0x20,_system_wq,plVar5 + 0xc1);
        }
      }
      goto LAB_00100984;
    }
    pcVar10 = "%s: ioremap failed\n";
  }
  _dev_err(lVar1,pcVar10,"lpass_cdc_va_macro_probe");
  uVar13 = 0xffffffea;
LAB_00100984:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13 & 0xffffffff;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_remove @ 00100ef4 size=172
// signature: undefined lpass_cdc_va_macro_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    param_1 = param_1 + 0x10;
    if (*(int *)(lVar2 + 0x67c) != 0) {
      if (*(long *)(lVar2 + 0x5c8) != 0) {
        kfree();
      }
      if (0 < *(int *)(lVar2 + 0x638)) {
        platform_device_unregister(*(undefined8 *)(lVar2 + 0x650));
        if (1 < *(int *)(lVar2 + 0x638)) {
          platform_device_unregister(*(undefined8 *)(lVar2 + 0x658));
          if (2 < *(int *)(lVar2 + 0x638)) {
            platform_device_unregister(*(undefined8 *)(lVar2 + 0x660));
          }
        }
      }
    }
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    lpass_cdc_unregister_macro(param_1,3);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_add_child_devices @ 00100fa4 size=724
// signature: undefined lpass_cdc_va_macro_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_add_child_devices(long param_1)

{
  ulong uVar1;
  uint uVar2;
  long *plVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  long lVar8;
  size_t __n;
  long lVar9;
  undefined *puVar10;
  char *pcVar11;
  undefined5 *puVar12;
  long lVar13;
  ulong uVar14;
  ushort uVar15;
  undefined7 local_b8;
  undefined4 uStack_b1;
  undefined5 local_ad;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  plVar3 = (long *)(param_1 + -0x608);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b1 = 0;
  local_ad = 0;
  if (plVar3 == (long *)0x0) {
    puVar10 = &DAT_0010ca66;
  }
  else {
    lVar6 = *plVar3;
    if (lVar6 != 0) {
      if (*(long *)(lVar6 + 0x2e8) == 0) {
        pcVar11 = "%s: DT node for va_priv does not exist\n";
LAB_00101198:
        _dev_err(lVar6,pcVar11,"lpass_cdc_va_macro_add_child_devices");
      }
      else {
        *(undefined4 *)(param_1 + 0x30) = 0;
        puVar7 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar6 + 0x2e8),0);
        if (puVar7 != (undefined8 *)0x0) {
          lVar13 = 0;
          uVar15 = 0;
          do {
            lVar8 = strnstr(*puVar7,"va_swr_master",0xd);
            if (lVar8 == 0) {
              pcVar11 = (char *)*puVar7;
              __n = strlen(pcVar11);
              if (0x4d < __n) {
                __n = 0x4e;
              }
              memcpy(&local_b8,pcVar11,__n);
              puVar12 = (undefined5 *)((long)&local_b8 + __n);
            }
            else {
              local_b8 = s_va_swr_ctrl_0010c455._0_7_;
              uStack_b1 = CONCAT31(0x6c7274,s_va_swr_ctrl_0010c455[7]);
              puVar12 = &local_ad;
            }
            *(undefined1 *)puVar12 = 0;
            lVar9 = platform_device_alloc(&local_b8,0xffffffff);
            lVar6 = *plVar3;
            if (lVar9 == 0) {
              pcVar11 = "%s: pdev memory alloc failed\n";
              goto LAB_00101198;
            }
            *(long *)(lVar9 + 0x70) = lVar6;
            *(undefined8 **)(lVar9 + 0x2f8) = puVar7;
            if (lVar8 != 0) {
              iVar5 = platform_device_add_data(lVar9,param_1 + -0x38,0x38);
              if (iVar5 == 0) {
                uVar14 = (ulong)uVar15;
                uVar1 = uVar14 * 8 + 8;
                lVar13 = krealloc(lVar13,uVar1,0xcc0);
                if (lVar13 != 0) {
                  if ((uVar1 < uVar14 * 8) || (uVar1 + uVar14 * -8 < 8)) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(1,0x101274);
                    (*pcVar4)();
                  }
                  uVar15 = uVar15 + 1;
                  *(long *)(lVar13 + uVar14 * 8) = lVar9;
                  *(long *)(param_1 + -0x40) = lVar13;
                  goto LAB_00101124;
                }
              }
              else {
                _dev_err(lVar9 + 0x10,"%s: cannot add plat data ctrl:%d\n",
                         "lpass_cdc_va_macro_add_child_devices",uVar15);
              }
LAB_001011ec:
              if ((((0 < *(int *)(param_1 + 0x30)) &&
                   (platform_device_put(*(undefined8 *)(param_1 + 0x48)),
                   1 < *(int *)(param_1 + 0x30))) &&
                  (platform_device_put(*(undefined8 *)(param_1 + 0x50)),
                  2 < *(int *)(param_1 + 0x30))) &&
                 (platform_device_put(*(undefined8 *)(param_1 + 0x58)), 3 < *(int *)(param_1 + 0x30)
                 )) {
LAB_0010126c:
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101270);
                (*pcVar4)();
              }
              break;
            }
LAB_00101124:
            iVar5 = platform_device_add(lVar9);
            if (iVar5 != 0) {
              _dev_err(lVar9 + 0x10,"%s: Cannot add platform device\n",
                       "lpass_cdc_va_macro_add_child_devices");
              goto LAB_001011ec;
            }
            uVar2 = *(uint *)(param_1 + 0x30);
            if (2 < (int)uVar2) break;
            *(uint *)(param_1 + 0x30) = uVar2 + 1;
            if (2 < uVar2) goto LAB_0010126c;
            lVar6 = *plVar3;
            *(long *)(param_1 + 0x48 + (ulong)uVar2 * 8) = lVar9;
            puVar7 = (undefined8 *)
                     of_get_next_available_child(*(undefined8 *)(lVar6 + 0x2e8),puVar7);
          } while (puVar7 != (undefined8 *)0x0);
        }
      }
      goto LAB_00101234;
    }
    puVar10 = &DAT_0010c9e4;
  }
  _printk(puVar10,"lpass_cdc_va_macro_add_child_devices");
LAB_00101234:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_swrm_clock @ 0010127c size=452
// signature: undefined lpass_cdc_va_macro_swrm_clock(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_va_macro_swrm_clock(long *param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_swrm_clock__rs,"lpass_cdc_va_macro_swrm_clock");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","lpass_cdc_va_macro_swrm_clock");
    return -0x16;
  }
  mutex_lock(param_1 + 9);
  if ((param_2 & 1) == 0) {
    if ((int)param_1[0xd2] == 0) {
      if (*(int *)((long)param_1 + 0x694) == 0) goto LAB_001013fc;
    }
    else if ((*(int *)((long)param_1 + 0x694) == 0) ||
            ((*(int *)((long)param_1 + 0x68c) == 0 && ((int)param_1[0xd1] != 0)))) {
      iVar1 = lpass_cdc_va_macro_tx_va_mclk_enable(param_1,lVar2,1,0);
      if (iVar1 == 0) {
        *(int *)(param_1 + 0xd2) = (int)param_1[0xd2] + -1;
      }
      goto LAB_00101400;
    }
    iVar1 = lpass_cdc_va_macro_tx_va_mclk_enable(param_1,lVar2,0,0);
    if (iVar1 == 0) {
      *(int *)((long)param_1 + 0x694) = *(int *)((long)param_1 + 0x694) + -1;
    }
  }
  else {
    __pm_runtime_resume(*param_1,4);
    if ((*(int *)((long)param_1 + 0x68c) == 0) || ((int)param_1[0xd1] != 0)) {
      iVar1 = lpass_cdc_va_macro_tx_va_mclk_enable(param_1,lVar2,0,1);
      if (iVar1 != 0) goto LAB_001013b8;
      *(int *)((long)param_1 + 0x694) = *(int *)((long)param_1 + 0x694) + 1;
    }
    else {
      iVar1 = lpass_cdc_va_macro_tx_va_mclk_enable(param_1,lVar2,1,1);
      if (iVar1 != 0) {
LAB_001013b8:
        lVar2 = *param_1;
        uVar3 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar2 + 0x220) = uVar3;
        __pm_runtime_suspend(*param_1,0xd);
        goto LAB_00101400;
      }
      *(int *)(param_1 + 0xd2) = (int)param_1[0xd2] + 1;
    }
    lVar2 = *param_1;
    uVar3 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar2 + 0x220) = uVar3;
    __pm_runtime_suspend(*param_1,0xd);
LAB_001013fc:
    iVar1 = 0;
  }
LAB_00101400:
  mutex_unlock(param_1 + 9);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_core_vote @ 00101444 size=192
// signature: undefined lpass_cdc_va_macro_core_vote(void)
// callers: []
//------------------------------------------------------------

undefined4 lpass_cdc_va_macro_core_vote(long *param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined *puVar4;
  undefined4 uVar5;
  long lVar6;
  
  if (param_1 == (long *)0x0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_core_vote__rs,"lpass_cdc_va_macro_core_vote");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    puVar4 = &DAT_0010cde1;
  }
  else {
    if ((*(char *)((long)param_1 + 0x6c3) != '\0') || ((param_2 & 1) == 0)) {
      if ((param_2 & 1) == 0) {
        __pm_runtime_suspend(*param_1,0xd);
        lVar6 = *param_1;
        uVar3 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar6 + 0x220) = uVar3;
        return 0;
      }
      __pm_runtime_resume(*param_1,4);
      uVar2 = lpass_cdc_check_core_votes(*param_1);
      uVar5 = 0;
      if ((uVar2 & 1) == 0) {
        uVar5 = 0xfffffdf6;
      }
      return uVar5;
    }
    puVar4 = &DAT_0010cbeb;
  }
  _printk(puVar4,"lpass_cdc_va_macro_core_vote");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_tx_va_mclk_enable @ 00101504 size=824
// signature: undefined lpass_cdc_va_macro_tx_va_mclk_enable(void)
// callers: [lpass_cdc_va_macro_swrm_clock]
//------------------------------------------------------------

int lpass_cdc_va_macro_tx_va_mclk_enable
              (undefined8 *param_1,undefined8 param_2,int param_3,ulong param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  char *pcVar5;
  
  if ((param_4 & 1) == 0) {
    if (*(int *)((long)param_1 + 0x5b4) < 1) {
      iVar1 = ___ratelimit(lpass_cdc_va_macro_tx_va_mclk_enable__rs_40,
                           "lpass_cdc_va_macro_tx_va_mclk_enable");
      if (iVar1 != 0) {
        _dev_err(*param_1,"va swrm clock users already 0\n");
      }
      *(undefined4 *)((long)param_1 + 0x5b4) = 0;
      return 0;
    }
    iVar1 = lpass_cdc_clk_rsc_request_clock(*param_1,0,0,1);
    iVar2 = *(int *)((long)param_1 + 0x5b4) + -1;
    *(int *)((long)param_1 + 0x5b4) = iVar2;
    if (iVar2 == 0) {
      regmap_update_bits_base(param_2,0x3008,1,0,0,0,0);
    }
    if (param_3 != 0) {
      if (param_3 == 1) {
        lpass_cdc_va_macro_mclk_enable(param_1,0);
      }
LAB_00101708:
      if (iVar1 == 0) {
        lpass_cdc_clk_rsc_request_clock(*param_1,0,0,0);
        iVar1 = *(int *)((long)param_1 + 0x5b4);
      }
      else {
        iVar1 = *(int *)((long)param_1 + 0x5b4);
      }
      if (iVar1 == 0) {
        msm_cdc_pinctrl_select_sleep_state(param_1[0xb8]);
        msm_cdc_pinctrl_set_wakeup_capable(param_1[0xb8],1);
      }
      return 0;
    }
    lpass_cdc_clk_rsc_fs_gen_request(*param_1,0);
    iVar2 = lpass_cdc_clk_rsc_request_clock(*param_1,0,0,0);
    if (-1 < iVar2) goto LAB_00101708;
    if (*(int *)((long)param_1 + 0x5b4) == 0) {
      msm_cdc_pinctrl_select_sleep_state(param_1[0xb8]);
    }
    puVar4 = lpass_cdc_va_macro_tx_va_mclk_enable__rs_42;
LAB_001017c8:
    iVar3 = ___ratelimit(puVar4,"lpass_cdc_va_macro_tx_va_mclk_enable");
    if (iVar3 == 0) goto joined_r0x001017d8;
    pcVar5 = "%s: swr request clk failed\n";
  }
  else {
    if (*(int *)((long)param_1 + 0x5b4) == 0) {
      msm_cdc_pinctrl_select_active_state(param_1[0xb8]);
      msm_cdc_pinctrl_set_wakeup_capable(param_1[0xb8],0);
    }
    iVar1 = lpass_cdc_clk_rsc_request_clock(*param_1,0,0,1);
    if (param_3 != 1) {
      if (param_3 != 0) {
LAB_00101610:
        if (*(int *)((long)param_1 + 0x5b4) == 0) {
          if (*(char *)(param_1 + 0xb7) != '\0') {
            regmap_update_bits_base(param_2,0x3008,2,2,0,0,0);
          }
          regmap_update_bits_base(param_2,0x3008,1,1,0,0,0);
          if (*(char *)(param_1 + 0xb7) != '\0') {
            regmap_update_bits_base(param_2,0x3008,2,0,0,0,0);
          }
          *(undefined1 *)(param_1 + 0xb7) = 0;
        }
        if (iVar1 == 0) {
          lpass_cdc_clk_rsc_request_clock(*param_1,0,0,0);
        }
        *(int *)((long)param_1 + 0x5b4) = *(int *)((long)param_1 + 0x5b4) + 1;
        return 0;
      }
      iVar2 = lpass_cdc_clk_rsc_request_clock(*param_1,0,0,1);
      if (-1 < iVar2) {
        lpass_cdc_clk_rsc_fs_gen_request(*param_1,1);
        goto LAB_00101610;
      }
      if (*(int *)((long)param_1 + 0x5b4) == 0) {
        msm_cdc_pinctrl_select_sleep_state(param_1[0xb8]);
      }
      puVar4 = lpass_cdc_va_macro_tx_va_mclk_enable__rs;
      goto LAB_001017c8;
    }
    iVar2 = lpass_cdc_va_macro_mclk_enable(param_1,1);
    if (-1 < iVar2) goto LAB_00101610;
    if (*(int *)((long)param_1 + 0x5b4) == 0) {
      msm_cdc_pinctrl_select_sleep_state(param_1[0xb8]);
    }
    iVar3 = ___ratelimit(lpass_cdc_va_macro_tx_va_mclk_enable__rs_38,
                         "lpass_cdc_va_macro_tx_va_mclk_enable");
    if (iVar3 == 0) goto joined_r0x001017d8;
    pcVar5 = "%s: request clock enable failed\n";
  }
  _dev_err(*param_1,pcVar5,"lpass_cdc_va_macro_tx_va_mclk_enable");
joined_r0x001017d8:
  if (iVar1 == 0) {
    lpass_cdc_clk_rsc_request_clock(*param_1,0,0,0);
    return iVar2;
  }
  return iVar2;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_mclk_enable @ 0010183c size=856
// signature: undefined lpass_cdc_va_macro_mclk_enable(void)
// callers: [lpass_cdc_va_macro_tx_va_mclk_enable, lpass_cdc_va_macro_mclk_event]
//------------------------------------------------------------

int lpass_cdc_va_macro_mclk_enable(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  char *pcVar7;
  short sVar8;
  long lVar9;
  
  lVar3 = dev_get_regmap(*(undefined8 *)(*param_1 + 0x60),0);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_mclk_enable__rs,"lpass_cdc_va_macro_mclk_enable");
    if (iVar1 == 0) {
      return -0x16;
    }
    _dev_err(*param_1,"%s: regmap is NULL\n","lpass_cdc_va_macro_mclk_enable");
    return -0x16;
  }
  mutex_lock(param_1 + 3);
  if ((param_2 & 1) == 0) {
    if (*(short *)((long)param_1 + 0x5b2) == 0) {
      iVar1 = ___ratelimit(lpass_cdc_va_macro_mclk_enable__rs_47,"lpass_cdc_va_macro_mclk_enable");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","lpass_cdc_va_macro_mclk_enable");
      }
      iVar1 = 0;
      *(undefined2 *)((long)param_1 + 0x5b2) = 0;
      goto LAB_00101ab8;
    }
    *(short *)((long)param_1 + 0x5b2) = *(short *)((long)param_1 + 0x5b2) + -1;
    lpass_cdc_clk_rsc_fs_gen_request(*param_1,0);
    if (param_1 == (long *)0x0) {
      iVar1 = ___ratelimit(lpass_cdc_va_macro_core_vote__rs,"lpass_cdc_va_macro_core_vote");
      if (iVar1 != 0) {
        puVar6 = &DAT_0010cde1;
        goto LAB_00101b6c;
      }
LAB_00101a14:
      iVar1 = -0x16;
LAB_00101a20:
      iVar2 = ___ratelimit(lpass_cdc_va_macro_mclk_enable__rs_49,"lpass_cdc_va_macro_mclk_enable");
      if (iVar2 != 0) {
        _dev_err(*param_1,"%s: va request core vote failed\n","lpass_cdc_va_macro_mclk_enable");
      }
    }
    else {
      if (*(char *)((long)param_1 + 0x6c3) == '\0') {
        puVar6 = &DAT_0010cbeb;
LAB_00101b6c:
        _printk(puVar6,"lpass_cdc_va_macro_core_vote");
        goto LAB_00101a14;
      }
      __pm_runtime_resume(*param_1,4);
      uVar4 = lpass_cdc_check_core_votes(*param_1);
      if ((uVar4 & 1) == 0) {
        iVar1 = -0x20a;
        goto LAB_00101a20;
      }
      iVar1 = 0;
    }
    lpass_cdc_clk_rsc_request_clock
              (*param_1,*(undefined2 *)((long)param_1 + 0x684),
               *(undefined2 *)((long)param_1 + 0x686),0);
    if (iVar1 == 0) {
      if (param_1 == (long *)0x0) {
        iVar1 = ___ratelimit(lpass_cdc_va_macro_core_vote__rs,"lpass_cdc_va_macro_core_vote");
        if (iVar1 != 0) {
          _printk(&DAT_0010cde1,"lpass_cdc_va_macro_core_vote");
        }
        iVar1 = 0;
      }
      else {
        __pm_runtime_suspend(*param_1,0xd);
        lVar3 = *param_1;
        uVar5 = ktime_get_mono_fast_ns();
        iVar1 = 0;
        *(undefined8 *)(lVar3 + 0x220) = uVar5;
      }
    }
    goto LAB_00101ab8;
  }
  if (param_1 == (long *)0x0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_core_vote__rs,"lpass_cdc_va_macro_core_vote");
    if (iVar1 != 0) {
      puVar6 = &DAT_0010cde1;
      goto LAB_00101b38;
    }
LAB_00101998:
    iVar1 = -0x16;
LAB_001019c8:
    iVar2 = ___ratelimit(lpass_cdc_va_macro_mclk_enable__rs_43,"lpass_cdc_va_macro_mclk_enable");
    if (iVar2 == 0) goto LAB_00101ab8;
    lVar3 = *param_1;
    pcVar7 = "%s: va request core vote failed\n";
  }
  else {
    if (*(char *)((long)param_1 + 0x6c3) == '\0') {
      puVar6 = &DAT_0010cbeb;
LAB_00101b38:
      _printk(puVar6,"lpass_cdc_va_macro_core_vote");
      goto LAB_00101998;
    }
    __pm_runtime_resume(*param_1,4);
    uVar4 = lpass_cdc_check_core_votes(*param_1);
    if ((uVar4 & 1) == 0) {
      iVar1 = -0x20a;
      goto LAB_001019c8;
    }
    iVar1 = lpass_cdc_clk_rsc_request_clock
                      (*param_1,*(undefined2 *)((long)param_1 + 0x684),
                       *(undefined2 *)((long)param_1 + 0x686),1);
    __pm_runtime_suspend(*param_1,0xd);
    lVar9 = *param_1;
    uVar5 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar9 + 0x220) = uVar5;
    if (-1 < iVar1) {
      lpass_cdc_clk_rsc_fs_gen_request(*param_1,1);
      sVar8 = *(short *)((long)param_1 + 0x5b2);
      if (sVar8 == 0) {
        regcache_mark_dirty(lVar3);
        regcache_sync_region(lVar3,0x3000,0x35a8);
        sVar8 = *(short *)((long)param_1 + 0x5b2);
      }
      *(short *)((long)param_1 + 0x5b2) = sVar8 + 1;
      goto LAB_00101ab8;
    }
    iVar2 = ___ratelimit(lpass_cdc_va_macro_mclk_enable__rs_45,"lpass_cdc_va_macro_mclk_enable");
    if (iVar2 == 0) goto LAB_00101ab8;
    lVar3 = *param_1;
    pcVar7 = "%s: va request clock en failed\n";
  }
  _dev_err(lVar3,pcVar7,"lpass_cdc_va_macro_mclk_enable");
LAB_00101ab8:
  mutex_unlock(param_1 + 3);
  return iVar1;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_init @ 00101b98 size=928
// signature: undefined lpass_cdc_va_macro_init(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_va_macro_init(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar4 == 0) {
    uVar5 = *(undefined8 *)(param_1 + 0x18);
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar7 = *(long *)(lVar4 + 0x98);
    if (lVar7 != 0) {
      lVar1 = param_1 + 0xd0;
      *(undefined1 *)(lVar7 + 0x698) = 0;
      *(undefined1 *)(lVar7 + 0x6c4) = 0;
      uVar2 = lpass_cdc_get_version(lVar4);
      *(undefined4 *)(lVar7 + 0x678) = uVar2;
      iVar3 = snd_soc_dapm_new_controls(lVar1,lpass_cdc_va_macro_dapm_widgets,0x20);
      if (iVar3 < 0) {
        pcVar6 = "%s: Failed to add controls\n";
      }
      else {
        iVar3 = snd_soc_dapm_add_routes(lVar1,&va_audio_map,0x6c);
        if (iVar3 < 0) {
          pcVar6 = "%s: Failed to add routes\n";
        }
        else {
          iVar3 = snd_soc_dapm_new_widgets(*(undefined8 *)(param_1 + 0xe8));
          if (iVar3 < 0) {
            pcVar6 = "%s: Failed to add widgets\n";
          }
          else {
            iVar3 = snd_soc_add_component_controls(param_1,lpass_cdc_va_macro_snd_controls,10);
            if (-1 < iVar3) {
              snd_soc_dapm_ignore_suspend(lVar1,"VA_AIF1 Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"VA_AIF2 Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"VA_AIF3 Capture");
              snd_soc_dapm_ignore_suspend(lVar1,"VA SWR_INPUT");
              snd_soc_dapm_sync(lVar1);
              *(long *)(lVar7 + 0xb0) = lVar7;
              *(undefined1 *)(lVar7 + 0xb8) = 0;
              *(undefined1 *)(lVar7 + 0x6c2) = 1;
              *(undefined8 *)(lVar7 + 0xc0) = 0xfffffffe0;
              *(long *)(lVar7 + 200) = lVar7 + 200;
              *(long *)(lVar7 + 0xd0) = lVar7 + 200;
              *(code **)(lVar7 + 0xd8) = lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0xf0,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x148) = lVar7;
              *(undefined1 *)(lVar7 + 0x150) = 1;
              *(undefined8 *)(lVar7 + 0x158) = 0xfffffffe0;
              *(long *)(lVar7 + 0x160) = lVar7 + 0x160;
              *(long *)(lVar7 + 0x168) = lVar7 + 0x160;
              *(code **)(lVar7 + 0x170) = lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x188,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x1e0) = lVar7;
              *(undefined8 *)(lVar7 + 0x1f0) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x1e8) = 2;
              *(long *)(lVar7 + 0x1f8) = lVar7 + 0x1f8;
              *(long *)(lVar7 + 0x200) = lVar7 + 0x1f8;
              *(code **)(lVar7 + 0x208) = lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x220,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x278) = lVar7;
              *(undefined8 *)(lVar7 + 0x288) = 0xfffffffe0;
              *(undefined1 *)(lVar7 + 0x280) = 3;
              *(long *)(lVar7 + 0x290) = lVar7 + 0x290;
              *(long *)(lVar7 + 0x298) = lVar7 + 0x290;
              *(code **)(lVar7 + 0x2a0) = lpass_cdc_va_macro_tx_hpf_corner_freq_callback;
              init_timer_key(lVar7 + 0x2b8,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x310) = lVar7;
              *(undefined4 *)(lVar7 + 0x318) = 0;
              *(undefined8 *)(lVar7 + 800) = 0xfffffffe0;
              *(long *)(lVar7 + 0x328) = lVar7 + 0x328;
              *(long *)(lVar7 + 0x330) = lVar7 + 0x328;
              *(code **)(lVar7 + 0x338) = lpass_cdc_va_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x350,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x3a8) = lVar7;
              *(undefined4 *)(lVar7 + 0x3b0) = 1;
              *(undefined8 *)(lVar7 + 0x3b8) = 0xfffffffe0;
              *(long *)(lVar7 + 0x3c0) = lVar7 + 0x3c0;
              *(long *)(lVar7 + 0x3c8) = lVar7 + 0x3c0;
              *(code **)(lVar7 + 0x3d0) = lpass_cdc_va_macro_mute_update_callback;
              init_timer_key(lVar7 + 1000,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x440) = lVar7;
              *(undefined4 *)(lVar7 + 0x448) = 2;
              *(undefined8 *)(lVar7 + 0x450) = 0xfffffffe0;
              *(long *)(lVar7 + 0x458) = lVar7 + 0x458;
              *(long *)(lVar7 + 0x460) = lVar7 + 0x458;
              *(code **)(lVar7 + 0x468) = lpass_cdc_va_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x480,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0x4d8) = lVar7;
              *(undefined4 *)(lVar7 + 0x4e0) = 3;
              *(undefined8 *)(lVar7 + 0x4e8) = 0xfffffffe0;
              *(long *)(lVar7 + 0x4f0) = lVar7 + 0x4f0;
              *(long *)(lVar7 + 0x4f8) = lVar7 + 0x4f0;
              *(code **)(lVar7 + 0x500) = lpass_cdc_va_macro_mute_update_callback;
              init_timer_key(lVar7 + 0x518,&delayed_work_timer_fn,0x200000,0,0);
              *(long *)(lVar7 + 0xa8) = param_1;
              snd_soc_component_update_bits(param_1,0x30d0,0xee,0xcc);
              snd_soc_component_update_bits(param_1,0x30d4,0xee,0xcc);
              snd_soc_component_update_bits(param_1,0x30d8,0xee,0xcc);
              return 0;
            }
            pcVar6 = "%s: Failed to add snd_ctls\n";
          }
        }
      }
      _dev_err(lVar4,pcVar6,"lpass_cdc_va_macro_init");
      return iVar3;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x18);
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(uVar5,pcVar6,"lpass_cdc_va_macro_init");
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_deinit @ 00101f3c size=172
// signature: undefined lpass_cdc_va_macro_deinit(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_deinit(long param_1)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      *(undefined8 *)(lVar2 + 0xa8) = 0;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar3,"lpass_cdc_va_macro_deinit");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_event_handler @ 00101fec size=704
// signature: undefined lpass_cdc_va_macro_event_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_event_handler(long param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long *plVar7;
  
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    plVar7 = *(long **)(lVar3 + 0x98);
    if ((plVar7 != (long *)0x0) && (plVar7[0x15] != 0)) {
      switch(param_2) {
      case 4:
        *(undefined2 *)((long)plVar7 + 0x6c2) = 0;
        if ((undefined8 *)plVar7[0xb9] != (undefined8 *)0x0) {
          swrm_wcd_notify(*(undefined8 *)plVar7[0xb9],6,0);
        }
        if ((((*(ushort *)(lVar3 + 0x200) & 7) != 0) || (*(int *)(lVar3 + 0x20c) != 2)) &&
           (iVar1 = lpass_cdc_runtime_suspend(lVar3), iVar1 == 0)) {
          __pm_runtime_disable(lVar3,1);
          __pm_runtime_set_status(lVar3,2);
          pm_runtime_enable(lVar3);
        }
        break;
      case 5:
        *(undefined1 *)(plVar7 + 0xb7) = 1;
        *(undefined1 *)((long)plVar7 + 0x6c2) = 1;
        if ((undefined8 *)plVar7[0xb9] != (undefined8 *)0x0) {
          swrm_wcd_notify(*(undefined8 *)plVar7[0xb9],7,0);
        }
        break;
      case 6:
        if (*(short *)((long)plVar7 + 0x5b2) != 0) {
          iVar1 = 500;
          do {
            msleep(0x14);
            iVar1 = iVar1 + -1;
            if (*(short *)((long)plVar7 + 0x5b2) == 0) break;
          } while (iVar1 != 0);
          if (iVar1 == 0) {
            uVar5 = ___ratelimit(lpass_cdc_va_macro_event_handler__rs,
                                 "lpass_cdc_va_macro_event_handler");
            if ((int)uVar5 == 0) {
              return uVar5;
            }
            _dev_err(lVar3,"%s: va_mclk_users non-zero, SSR fail!!\n",
                     "lpass_cdc_va_macro_event_handler");
          }
        }
        break;
      case 7:
        lpass_cdc_rsc_clk_reset(lVar3,3);
        break;
      default:
        return 0;
      case 0xc:
        *(undefined1 *)((long)plVar7 + 0x6c3) = 1;
        __pm_runtime_resume(*plVar7,4);
        uVar4 = lpass_cdc_check_core_votes(*plVar7);
        if ((uVar4 & 1) != 0) {
          iVar1 = lpass_cdc_clk_rsc_request_clock
                            (*plVar7,*(undefined2 *)((long)plVar7 + 0x684),
                             *(undefined2 *)((long)plVar7 + 0x686),1);
          if (iVar1 < 0) {
            iVar2 = ___ratelimit(lpass_cdc_va_macro_event_handler__rs_203,
                                 "lpass_cdc_va_macro_event_handler");
            if (iVar2 != 0) {
              _dev_err(*plVar7,"%s, failed to enable clk, ret:%d\n",
                       "lpass_cdc_va_macro_event_handler",iVar1);
            }
          }
          else {
            lpass_cdc_clk_rsc_request_clock
                      (*plVar7,*(undefined2 *)((long)plVar7 + 0x684),
                       *(undefined2 *)((long)plVar7 + 0x686),0);
          }
          __pm_runtime_suspend(*plVar7,0xd);
          lVar3 = *plVar7;
          uVar5 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar3 + 0x220) = uVar5;
          return 0;
        }
        uVar5 = ___ratelimit(lpass_cdc_va_macro_event_handler__rs_202,
                             "lpass_cdc_va_macro_event_handler");
        if ((int)uVar5 == 0) {
          return uVar5;
        }
        _dev_err(*plVar7,"%s: va request core vote failed\n","lpass_cdc_va_macro_event_handler");
      }
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar6,"lpass_cdc_va_macro_event_handler");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_set_port_map @ 001022b0 size=268
// signature: undefined lpass_cdc_va_macro_set_port_map(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_set_port_map
               (long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: null device for macro!\n";
LAB_001023a4:
      _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar4,"lpass_cdc_va_macro_set_port_map");
    }
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      local_48 = param_3;
      uStack_44 = param_2;
      local_40 = param_4;
      if (*(undefined8 **)(lVar2 + 0x5c8) == (undefined8 *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = swrm_wcd_notify(**(undefined8 **)(lVar2 + 0x5c8),9,&local_48);
      }
      goto LAB_00102368;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: priv is null for macro!\n";
      goto LAB_001023a4;
    }
  }
  uVar3 = 0xffffffea;
LAB_00102368:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_reg_wake_irq @ 001023c0 size=244
// signature: undefined lpass_cdc_va_macro_reg_wake_irq(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_reg_wake_irq(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = param_2;
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: null device for macro!\n";
LAB_0010249c:
      _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar4,"lpass_cdc_va_macro_reg_wake_irq");
    }
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      if (*(undefined8 **)(lVar2 + 0x5c8) == (undefined8 *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = swrm_wcd_notify(**(undefined8 **)(lVar2 + 0x5c8),8,&local_2c);
      }
      goto LAB_00102464;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 != 0) {
      pcVar4 = "%s: priv is null for macro!\n";
      goto LAB_0010249c;
    }
  }
  uVar3 = 0xffffffea;
LAB_00102464:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_clk_div_get @ 001024b8 size=188
// signature: undefined lpass_cdc_va_macro_clk_div_get(void)
// callers: []
//------------------------------------------------------------

uint lpass_cdc_va_macro_clk_div_get(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: null device for macro!\n";
  }
  else {
    lVar3 = *(long *)(lVar3 + 0x98);
    if ((lVar3 != 0) && (*(long *)(lVar3 + 0xa8) != 0)) {
      uVar1 = 2;
      if (*(ushort *)(lVar3 + 0x5b0) != 5 || *(char *)(lVar3 + 0x699) == '\0') {
        uVar1 = (uint)*(ushort *)(lVar3 + 0x5b0);
      }
      return uVar1;
    }
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar4,"lpass_cdc_va_macro_clk_div_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_get_channel_map @ 00102578 size=312
// signature: undefined lpass_cdc_va_macro_get_channel_map(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_get_channel_map(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x58);
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + 0x18),3);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: null device for macro!\n";
  }
  else {
    lVar6 = *(long *)(lVar3 + 0x98);
    if ((lVar6 != 0) && (*(long *)(lVar6 + 0xa8) != 0)) {
      if (2 < *(uint *)(param_1 + 8) - 1) {
        uVar4 = ___ratelimit(lpass_cdc_va_macro_get_channel_map__rs,
                             "lpass_cdc_va_macro_get_channel_map");
        if ((int)uVar4 == 0) {
          return uVar4;
        }
        _dev_err(lVar3,"%s: Invalid AIF\n","lpass_cdc_va_macro_get_channel_map");
        return 0;
      }
      *param_3 = (int)*(undefined8 *)(lVar6 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x570);
      if (3 < *(uint *)(param_1 + 8)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1026b0);
        (*pcVar1)();
      }
      *param_2 = (int)*(undefined8 *)(lVar6 + (ulong)*(uint *)(param_1 + 8) * 8 + 0x590);
      return 0;
    }
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar5 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + 0x18),pcVar5,"lpass_cdc_va_macro_get_channel_map");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_hw_params @ 001026b4 size=572
// signature: undefined lpass_cdc_va_macro_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_hw_params(undefined8 param_1,long param_2,long param_3)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  
  lVar8 = *(long *)(param_3 + 0x58);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + 0x18),3);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar10 = *(long *)(lVar5 + 0x98);
    if ((lVar10 != 0) && (*(long *)(lVar10 + 0xa8) != 0)) {
      uVar1 = *(uint *)(param_2 + 0x128);
      *(bool *)(lVar10 + 0x699) = 16000 < uVar1;
      if ((int)uVar1 < 48000) {
        if (uVar1 == 8000) {
          uVar9 = 0;
        }
        else if (uVar1 == 16000) {
          uVar9 = 1;
        }
        else {
          if (uVar1 != 32000) goto LAB_0010289c;
          uVar9 = 3;
        }
      }
      else if ((int)uVar1 < 0x2ee00) {
        if (uVar1 == 48000) {
          uVar9 = 4;
        }
        else {
          if (uVar1 != 96000) {
LAB_0010289c:
            iVar4 = ___ratelimit(lpass_cdc_va_macro_hw_params__rs,"lpass_cdc_va_macro_hw_params");
            if (iVar4 == 0) {
              return 0xffffffea;
            }
            _dev_err(lVar5,"%s: Invalid TX sample rate: %d\n","lpass_cdc_va_macro_hw_params",
                     *(undefined4 *)(param_2 + 0x128));
            return 0xffffffea;
          }
          uVar9 = 5;
        }
      }
      else if (uVar1 == 0x2ee00) {
        uVar9 = 6;
      }
      else {
        if (uVar1 != 0x5dc00) goto LAB_0010289c;
        uVar9 = 7;
      }
      uVar1 = *(uint *)(param_3 + 8);
      if (uVar1 < 5) {
        uVar7 = 0;
        do {
          if (3 < uVar7) {
            return 0;
          }
          uVar1 = (uint)(-1L << (uVar7 & 0x3f)) & *(uint *)(lVar10 + (ulong)uVar1 * 8 + 0x570);
          uVar2 = ((ulong)uVar1 & 10) >> 1 | ((ulong)uVar1 & 5) << 1;
          uVar7 = 4;
          if ((uVar1 & 0xf) != 0) {
            uVar7 = LZCOUNT((uVar2 >> 2 | (uVar2 & 0x3333333333333333) << 2) << 0x3c);
          }
          if (3 < uVar7) {
            return 0;
          }
          snd_soc_component_update_bits(lVar8,(int)uVar7 * 0x80 + 0x3400,0xf,uVar9);
          uVar1 = *(uint *)(param_3 + 8);
          uVar7 = uVar7 + 1;
        } while (uVar1 < 5);
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10287c);
      (*pcVar3)();
    }
    iVar4 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar8 + 0x18),pcVar6,"lpass_cdc_va_macro_hw_params");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_tx_hpf_corner_freq_callback @ 001028f4 size=468
// signature: undefined lpass_cdc_va_macro_tx_hpf_corner_freq_callback(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_tx_hpf_corner_freq_callback(long param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  code *pcVar4;
  uint uVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  undefined8 *puVar10;
  
  puVar10 = *(undefined8 **)(param_1 + -0x10);
  bVar2 = *(byte *)(param_1 + -7);
  lVar9 = puVar10[0x15];
  iVar3 = (uint)*(byte *)(param_1 + -8) * 0x80;
  iVar1 = iVar3 + 0x3404;
  iVar3 = iVar3 + 0x3418;
  uVar6 = is_amic_enabled(lVar9);
  if ((uVar6 & 1) == 0) {
    snd_soc_component_update_bits(lVar9,iVar1,0x60,(ulong)bVar2 << 5);
    snd_soc_component_update_bits(lVar9,iVar3,2,2);
    usleep_range_state(1000,0x3f2,2);
    uVar7 = 2;
    uVar8 = 0;
  }
  else {
    uVar5 = snd_soc_component_read(lVar9,(uint)*(byte *)(param_1 + -8) * 8 + 0x3100);
    lpass_cdc_clear_amic_tx_hold(*(undefined8 *)(lVar9 + 0x18),uVar5 & 0xf);
    snd_soc_component_update_bits(lVar9,iVar1,0x60,(ulong)bVar2 << 5);
    snd_soc_component_update_bits(lVar9,iVar3,3,2);
    if (3 < (ulong)*(byte *)(param_1 + -8)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102ac8);
      (*pcVar4)();
    }
    switch(*(undefined4 *)((long)puVar10 + (ulong)*(byte *)(param_1 + -8) * 4 + 0x6ac)) {
    default:
      uVar7 = 0x7d;
      uVar8 = 0x82;
      break;
    case 1:
      uVar7 = 0x3e;
      uVar8 = 0x41;
      break;
    case 3:
      uVar7 = 0x1f;
      uVar8 = 0x20;
      break;
    case 4:
      uVar7 = 0x14;
      uVar8 = 0x15;
      break;
    case 5:
      uVar7 = 10;
      uVar8 = 0xb;
      break;
    case 6:
      uVar7 = 5;
      uVar8 = 6;
    }
    usleep_range_state(uVar7,uVar8,2);
    uVar7 = 3;
    uVar8 = 1;
  }
  snd_soc_component_update_bits(lVar9,iVar3,uVar7,uVar8);
  mutex_lock(puVar10 + 0xf);
  iVar1 = *(int *)(puVar10 + 0xd9) + -1;
  *(int *)(puVar10 + 0xd9) = iVar1;
  if (iVar1 == 0) {
    pm_relax(*puVar10);
    iVar1 = *(int *)(puVar10 + 0xd9);
  }
  if (iVar1 < 0) {
    *(undefined4 *)(puVar10 + 0xd9) = 0;
  }
  mutex_unlock(puVar10 + 0xf);
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_mute_update_callback @ 00102acc size=132
// signature: undefined lpass_cdc_va_macro_mute_update_callback(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_mute_update_callback(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + -0x10);
  snd_soc_component_update_bits
            (puVar2[0x15],*(int *)(param_1 + -8) * 0x80 + 0x3400U & 0xff80,0x10,0);
  mutex_lock(puVar2 + 0xf);
  iVar1 = *(int *)(puVar2 + 0xd9) + -1;
  *(int *)(puVar2 + 0xd9) = iVar1;
  if (iVar1 == 0) {
    pm_relax(*puVar2);
    iVar1 = *(int *)(puVar2 + 0xd9);
  }
  if (iVar1 < 0) {
    *(undefined4 *)(puVar2 + 0xd9) = 0;
  }
  mutex_unlock(puVar2 + 0xf);
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_enable_tx @ 00102b54 size=340
// signature: undefined lpass_cdc_va_macro_enable_tx(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_enable_tx(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: null device for macro!\n";
  }
  else {
    puVar5 = *(undefined8 **)(lVar2 + 0x98);
    if ((puVar5 != (undefined8 *)0x0) && (puVar5[0x15] != 0)) {
      if (param_3 == 4) {
        uVar3 = lpass_cdc_clk_rsc_request_clock(*puVar5,*(undefined2 *)((long)puVar5 + 0x684),0,1);
        if ((int)uVar3 == 0) {
          *(int *)((long)puVar5 + 0x6bc) = *(int *)((long)puVar5 + 0x6bc) + 1;
          return uVar3;
        }
        return uVar3;
      }
      if (param_3 == 2) {
        if (*(int *)((long)puVar5 + 0x6bc) < 1) {
          return 0;
        }
        uVar3 = lpass_cdc_clk_rsc_request_clock(*puVar5,*(undefined2 *)((long)puVar5 + 0x684),0,0);
        *(int *)((long)puVar5 + 0x6bc) = *(int *)((long)puVar5 + 0x6bc) + -1;
        return uVar3;
      }
      iVar1 = ___ratelimit(lpass_cdc_va_macro_enable_tx__rs,"lpass_cdc_va_macro_enable_tx");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*puVar5,"%s: invalid DAPM event %d\n","lpass_cdc_va_macro_enable_tx",param_3);
      return 0xffffffea;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar6 + -0xb8),pcVar4,"lpass_cdc_va_macro_enable_tx");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_enable_micbias @ 00102cac size=580
// signature: undefined lpass_cdc_va_macro_enable_micbias(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_va_macro_enable_micbias(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),3);
  if (lVar3 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return -0x16;
    }
    pcVar4 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar3 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0xa8) != 0)) {
      if (*(long *)(lVar5 + 0x668) != 0) {
        if (param_3 == 8) {
          iVar1 = *(int *)(lVar5 + 0x680) + -1;
          *(int *)(lVar5 + 0x680) = iVar1;
          if (iVar1 < 1) {
            if (iVar1 < 0) {
              *(undefined4 *)(lVar5 + 0x680) = 0;
              return 0;
            }
            iVar1 = regulator_disable();
            if (iVar1 == 0) {
              regulator_set_voltage(*(undefined8 *)(lVar5 + 0x668),0,*(undefined4 *)(lVar5 + 0x670))
              ;
              regulator_set_load(*(undefined8 *)(lVar5 + 0x668),0);
              return 0;
            }
            iVar2 = ___ratelimit(lpass_cdc_va_macro_enable_micbias__rs_161,
                                 "lpass_cdc_va_macro_enable_micbias");
            if (iVar2 == 0) {
              return iVar1;
            }
            pcVar4 = "%s: regulator disable failed, err = %d\n";
            goto LAB_00102ed8;
          }
        }
        else if ((param_3 == 1) &&
                (iVar1 = *(int *)(lVar5 + 0x680), *(int *)(lVar5 + 0x680) = iVar1 + 1, iVar1 < 1)) {
          iVar1 = regulator_set_voltage
                            (*(long *)(lVar5 + 0x668),*(undefined4 *)(lVar5 + 0x670),
                             *(undefined4 *)(lVar5 + 0x670));
          if (iVar1 == 0) {
            iVar1 = regulator_set_load(*(undefined8 *)(lVar5 + 0x668),*(undefined4 *)(lVar5 + 0x674)
                                      );
            if (iVar1 == 0) {
              iVar1 = regulator_enable(*(undefined8 *)(lVar5 + 0x668));
              if (iVar1 == 0) {
                return 0;
              }
              iVar2 = ___ratelimit(lpass_cdc_va_macro_enable_micbias__rs_159,
                                   "lpass_cdc_va_macro_enable_micbias");
              if (iVar2 == 0) {
                return iVar1;
              }
              pcVar4 = "%s: regulator enable failed, err = %d\n";
            }
            else {
              iVar2 = ___ratelimit(lpass_cdc_va_macro_enable_micbias__rs_157,
                                   "lpass_cdc_va_macro_enable_micbias");
              if (iVar2 == 0) {
                return iVar1;
              }
              pcVar4 = "%s: Setting current failed, err = %d\n";
            }
          }
          else {
            iVar2 = ___ratelimit(lpass_cdc_va_macro_enable_micbias__rs_155,
                                 "lpass_cdc_va_macro_enable_micbias");
            if (iVar2 == 0) {
              return iVar1;
            }
            pcVar4 = "%s: Setting voltage failed, err = %d\n";
          }
LAB_00102ed8:
          _dev_err(lVar3,pcVar4,"lpass_cdc_va_macro_enable_micbias",iVar1);
          return iVar1;
        }
        return 0;
      }
      iVar1 = ___ratelimit(lpass_cdc_va_macro_enable_micbias__rs,"lpass_cdc_va_macro_enable_micbias"
                          );
      if (iVar1 == 0) {
        return -0x16;
      }
      pcVar4 = "%s:regulator not provided in dtsi\n";
      goto LAB_00102e08;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return -0x16;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  lVar3 = *(long *)(lVar6 + -0xb8);
LAB_00102e08:
  _dev_err(lVar3,pcVar4,"lpass_cdc_va_macro_enable_micbias");
  return -0x16;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_enable_dec @ 00102ef4 size=1328
// signature: undefined lpass_cdc_va_macro_enable_dec(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 lpass_cdc_va_macro_enable_dec(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  char *pcVar14;
  undefined8 uVar15;
  long lVar16;
  uint uVar17;
  ulong uVar18;
  undefined8 *puVar19;
  
  lVar16 = *(long *)(param_1 + 0x28);
  lVar11 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + -0xb8),3);
  if (lVar11 == 0) {
    iVar8 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar8 == 0) {
      return 0xffffffea;
    }
    pcVar14 = "%s: null device for macro!\n";
  }
  else {
    puVar19 = *(undefined8 **)(lVar11 + 0x98);
    if ((puVar19 != (undefined8 *)0x0) && (puVar19[0x15] != 0)) {
      bVar4 = *(byte *)(param_1 + 0x4c);
      uVar18 = (ulong)bVar4;
      lVar16 = lVar16 + -0xd0;
      iVar5 = (uint)bVar4 * 0x80;
      iVar8 = iVar5 + 0x3400;
      uVar7 = snd_soc_component_read(lVar16,iVar8);
      if (3 < uVar18) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103424);
        (*pcVar6)();
      }
      iVar2 = iVar5 + 0x3418;
      iVar3 = iVar5 + 0x3404;
      *(uint *)((long)puVar19 + uVar18 * 4 + 0x6ac) = uVar7 & 0xf;
      uVar12 = is_amic_enabled(lVar16,(uint)bVar4);
      uVar7 = (uint)bVar4;
      if ((uVar12 & 1) == 0) {
        lVar11 = *(long *)(param_1 + 0x28) + -0xd0;
        uVar12 = snd_soc_component_read(lVar11,uVar7 * 8 + 0x3100);
        uVar13 = 0;
        uVar15 = 1;
        switch(param_3) {
        case 2:
          goto switchD_00102fd8_caseD_2;
        default:
          goto switchD_00102fd8_caseD_3;
        case 4:
          goto switchD_00102fd8_caseD_4;
        case 8:
          uVar15 = 0;
        case 1:
          lpass_cdc_dmic_clk_enable(lVar11,(int)((uVar12 & 0xffffffff) >> 4) + -1,1,uVar15);
        }
      }
      uVar13 = 0;
      switch(param_3) {
      case 1:
        snd_soc_component_update_bits
                  (lVar16,iVar3,6,*(int *)((long)puVar19 + uVar18 * 4 + 0x69c) << 1);
        uVar13 = 0x10;
        break;
      case 2:
switchD_00102fd8_caseD_2:
        snd_soc_component_update_bits(lVar16,iVar8,0x20,0x20);
        uVar17 = (uint)bVar4;
        uVar18 = is_amic_enabled(lVar16,uVar18);
        if ((uVar18 & 1) == 0) {
          snd_soc_component_update_bits(lVar16,iVar2,1,0);
          usleep_range_state(1000,0x3f2,2);
        }
        uVar9 = snd_soc_component_read(lVar16,iVar3);
        uVar9 = uVar9 >> 5 & 3;
        pcVar14 = (char *)((long)puVar19 + (ulong)uVar17 * 0x98 + 0xb9);
        *pcVar14 = (char)uVar9;
        if (uVar9 != 2) {
          snd_soc_component_update_bits(lVar16,iVar3,0x60,0x40);
        }
        uVar18 = is_amic_enabled(lVar16,uVar17);
        if (((uVar18 & 1) != 0) && (va_tx_unmute_delay < 100)) {
          va_tx_unmute_delay = 100;
        }
        snd_soc_component_update_bits(lVar16,iVar2,3,2);
        uVar18 = is_amic_enabled(lVar16,uVar17);
        if ((uVar18 & 1) == 0) {
          snd_soc_component_update_bits(lVar16,iVar2,3,0);
        }
        usleep_range_state(1000,0x3f2,2);
        snd_soc_component_update_bits(lVar16,iVar2,3,1);
        usleep_range_state(6000,0x177a,2);
        puVar1 = puVar19 + 0xf;
        mutex_lock(puVar1);
        iVar8 = *(int *)(puVar19 + 0xd9);
        *(int *)(puVar19 + 0xd9) = iVar8 + 1;
        if (iVar8 == 0) {
          pm_stay_awake(*puVar19);
        }
        mutex_unlock(puVar1);
        uVar13 = _system_freezable_wq;
        uVar15 = __msecs_to_jiffies(va_tx_unmute_delay);
        queue_delayed_work_on(0x20,uVar13,puVar19 + (ulong)uVar7 * 0x13 + 100,uVar15);
        if (*pcVar14 != '\x02') {
          mutex_lock(puVar1);
          iVar8 = *(int *)(puVar19 + 0xd9);
          *(int *)(puVar19 + 0xd9) = iVar8 + 1;
          if (iVar8 == 0) {
            pm_stay_awake(*puVar19);
          }
          mutex_unlock(puVar1);
          queue_delayed_work_on(0x20,_system_freezable_wq,puVar19 + (ulong)uVar7 * 0x13 + 0x18,0x4b)
          ;
        }
        uVar10 = snd_soc_component_read(lVar16,iVar5 + 0x340c);
        snd_soc_component_write(lVar16,iVar5 + 0x340c,uVar10);
        return 0;
      default:
        goto switchD_00102fd8_caseD_3;
      case 4:
switchD_00102fd8_caseD_4:
        bVar4 = *(byte *)((long)puVar19 + (ulong)uVar7 * 0x98 + 0xb9);
        snd_soc_component_update_bits(lVar16,iVar8,0x10,0x10);
        uVar18 = cancel_delayed_work_sync(puVar19 + (ulong)uVar7 * 0x13 + 0x18);
        if (((uVar18 & 1) != 0) && (bVar4 != 2)) {
          snd_soc_component_update_bits(lVar16,iVar3,0x60,(ulong)bVar4 << 5);
          uVar18 = is_amic_enabled(lVar16,uVar7);
          uVar10 = 2;
          if ((uVar18 & 1) == 0) {
            uVar10 = 3;
          }
          snd_soc_component_update_bits(lVar16,iVar2,3,uVar10);
          usleep_range_state(1000,0x3f2,2);
          snd_soc_component_update_bits(lVar16,iVar2,3,1);
        }
        puVar1 = puVar19 + 0xf;
        mutex_lock(puVar1);
        iVar8 = *(int *)(puVar19 + 0xd9) + -1;
        *(int *)(puVar19 + 0xd9) = iVar8;
        if (iVar8 == 0) {
          pm_relax(*puVar19);
          iVar8 = *(int *)(puVar19 + 0xd9);
        }
        if (iVar8 < 0) {
          *(undefined4 *)(puVar19 + 0xd9) = 0;
        }
        mutex_unlock(puVar1);
        cancel_delayed_work_sync(puVar19 + (ulong)uVar7 * 0x13 + 100);
        mutex_lock(puVar1);
        iVar8 = *(int *)(puVar19 + 0xd9) + -1;
        *(int *)(puVar19 + 0xd9) = iVar8;
        if (iVar8 == 0) {
          pm_relax(*puVar19);
          iVar8 = *(int *)(puVar19 + 0xd9);
        }
        if (iVar8 < 0) {
          *(undefined4 *)(puVar19 + 0xd9) = 0;
        }
        mutex_unlock(puVar1);
        return 0;
      case 8:
        snd_soc_component_update_bits(lVar16,iVar8,0x20,0);
        snd_soc_component_update_bits(lVar16,iVar8,0x40,0x40);
        snd_soc_component_update_bits(lVar16,iVar8,0x40,0);
        uVar13 = 0;
      }
      snd_soc_component_update_bits(lVar16,iVar8,0x10,uVar13);
      return 0;
    }
    iVar8 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar8 == 0) {
      return 0xffffffea;
    }
    pcVar14 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar16 + -0xb8),pcVar14,"lpass_cdc_va_macro_enable_dec");
  uVar13 = 0xffffffea;
switchD_00102fd8_caseD_3:
  return uVar13;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_mclk_event @ 00103428 size=436
// signature: undefined lpass_cdc_va_macro_mclk_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_mclk_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + -0xb8),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: null device for macro!\n";
  }
  else {
    puVar5 = *(undefined8 **)(lVar2 + 0x98);
    if ((puVar5 != (undefined8 *)0x0) && (puVar5[0x15] != 0)) {
      if (param_3 == 8) {
        if ((*(char *)((long)puVar5 + 0x6c5) == '\0') || (*(char *)(puVar5 + 0xd3) != '\0')) {
          lpass_cdc_va_macro_mclk_enable(puVar5,0);
        }
        else {
          lpass_cdc_tx_mclk_enable(lVar6 + -0xd0,0);
        }
        if (*(int *)((long)puVar5 + 0x6bc) < 1) {
          return 0;
        }
        lpass_cdc_clk_rsc_request_clock(*puVar5,*(undefined2 *)((long)puVar5 + 0x684),0,0);
        *(int *)((long)puVar5 + 0x6bc) = *(int *)((long)puVar5 + 0x6bc) + -1;
        return 0;
      }
      if (param_3 != 1) {
        iVar1 = ___ratelimit(lpass_cdc_va_macro_mclk_event__rs,"lpass_cdc_va_macro_mclk_event");
        if (iVar1 == 0) {
          return 0xffffffea;
        }
        _dev_err(*puVar5,"%s: invalid DAPM event %d\n","lpass_cdc_va_macro_mclk_event",param_3);
        return 0xffffffea;
      }
      iVar1 = lpass_cdc_clk_rsc_request_clock(*puVar5,*(undefined2 *)((long)puVar5 + 0x684),0,1);
      if (iVar1 == 0) {
        *(int *)((long)puVar5 + 0x6bc) = *(int *)((long)puVar5 + 0x6bc) + 1;
      }
      if ((*(char *)((long)puVar5 + 0x6c5) == '\0') || (*(char *)(puVar5 + 0xd3) != '\0')) {
        uVar3 = lpass_cdc_va_macro_mclk_enable(puVar5,1);
        return uVar3;
      }
      uVar3 = lpass_cdc_tx_mclk_enable(lVar6 + -0xd0,1);
      return uVar3;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar6 + -0xb8),pcVar4,"lpass_cdc_va_macro_mclk_event");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_swr_pwr_event @ 001035e0 size=924
// signature: undefined lpass_cdc_va_macro_swr_pwr_event(void)
// callers: []
//------------------------------------------------------------

int lpass_cdc_va_macro_swr_pwr_event(long param_1,undefined8 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  char *pcVar7;
  long *plVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x28);
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar9 + -0xb8),3);
  if (lVar4 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return -0x16;
    }
    pcVar7 = "%s: null device for macro!\n";
LAB_00103800:
    _dev_err(*(undefined8 *)(lVar9 + -0xb8),pcVar7,"lpass_cdc_va_macro_swr_pwr_event");
    return -0x16;
  }
  plVar8 = *(long **)(lVar4 + 0x98);
  if ((plVar8 == (long *)0x0) || (plVar8[0x15] == 0)) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return -0x16;
    }
    pcVar7 = "%s: priv is null for macro!\n";
    goto LAB_00103800;
  }
  if (param_3 != 8) {
    if (param_3 != 1) {
      iVar2 = ___ratelimit(lpass_cdc_va_macro_swr_pwr_event__rs_174,
                           "lpass_cdc_va_macro_swr_pwr_event");
      if (iVar2 == 0) {
        return -0x16;
      }
      _dev_err(*plVar8,"%s: invalid DAPM event %d\n","lpass_cdc_va_macro_swr_pwr_event",param_3);
      return -0x16;
    }
    if ((short)plVar8[0xd8] == 3) {
      return 0;
    }
    if (*(int *)((long)plVar8 + 0x68c) == 0) {
      return 0;
    }
    if (*(int *)((long)plVar8 + 0x694) == 0) {
      return 0;
    }
    if (*(char *)((long)plVar8 + 0x6c3) == '\0') {
      _printk(&DAT_0010cbeb,"lpass_cdc_va_macro_core_vote");
      iVar2 = -0x16;
LAB_00103890:
      iVar3 = ___ratelimit(lpass_cdc_va_macro_swr_pwr_event__rs,"lpass_cdc_va_macro_swr_pwr_event");
      if (iVar3 == 0) {
        return iVar2;
      }
      _dev_err(*plVar8,"%s: va request core vote failed\n","lpass_cdc_va_macro_swr_pwr_event");
      return iVar2;
    }
    __pm_runtime_resume(*plVar8,4);
    uVar5 = lpass_cdc_check_core_votes(*plVar8);
    if ((uVar5 & 1) == 0) {
      iVar2 = -0x20a;
      goto LAB_00103890;
    }
    iVar2 = lpass_cdc_clk_rsc_request_clock(*plVar8,*(undefined2 *)((long)plVar8 + 0x684),3,1);
    __pm_runtime_suspend(*plVar8,0xd);
    lVar4 = *plVar8;
    uVar6 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar4 + 0x220) = uVar6;
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = lpass_cdc_clk_rsc_request_clock(*plVar8,*(undefined2 *)((long)plVar8 + 0x684),0,0);
    if (iVar2 == 0) {
      *(undefined2 *)(plVar8 + 0xd8) = 3;
      return 0;
    }
    lVar4 = *plVar8;
    uVar6 = 3;
    goto LAB_0010387c;
  }
  if ((short)plVar8[0xd8] != 3) {
    return 0;
  }
  iVar2 = lpass_cdc_clk_rsc_request_clock(*plVar8,*(undefined2 *)((long)plVar8 + 0x684),0,1);
  if (iVar2 != 0) {
    iVar3 = ___ratelimit(lpass_cdc_va_macro_swr_pwr_event__rs_169,"lpass_cdc_va_macro_swr_pwr_event"
                        );
    if (iVar3 == 0) {
      cVar1 = *(char *)((long)plVar8 + 0x6c2);
    }
    else {
      _dev_err(*(undefined8 *)(lVar9 + -0xb8),"%s: request clock TX_CLK enable failed\n",
               "lpass_cdc_va_macro_swr_pwr_event");
      cVar1 = *(char *)((long)plVar8 + 0x6c2);
    }
    if (cVar1 != '\0') {
      return iVar2;
    }
  }
  if (*(char *)((long)plVar8 + 0x6c3) == '\0') {
    _printk(&DAT_0010cbeb,"lpass_cdc_va_macro_core_vote");
    iVar2 = -0x16;
LAB_00103818:
    iVar3 = ___ratelimit(lpass_cdc_va_macro_swr_pwr_event__rs_171,"lpass_cdc_va_macro_swr_pwr_event"
                        );
    if (iVar3 == 0) {
      cVar1 = *(char *)((long)plVar8 + 0x6c2);
    }
    else {
      _dev_err(*plVar8,"%s: va request core vote failed\n","lpass_cdc_va_macro_swr_pwr_event");
      cVar1 = *(char *)((long)plVar8 + 0x6c2);
    }
    if (cVar1 != '\0') {
      return iVar2;
    }
    iVar2 = lpass_cdc_clk_rsc_request_clock(*plVar8,*(undefined2 *)((long)plVar8 + 0x684),3,0);
  }
  else {
    __pm_runtime_resume(*plVar8,4);
    uVar5 = lpass_cdc_check_core_votes(*plVar8);
    if ((uVar5 & 1) == 0) {
      iVar2 = -0x20a;
      goto LAB_00103818;
    }
    iVar2 = lpass_cdc_clk_rsc_request_clock(*plVar8,*(undefined2 *)((long)plVar8 + 0x684),3,0);
    __pm_runtime_suspend(*plVar8,0xd);
    lVar4 = *plVar8;
    uVar6 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar4 + 0x220) = uVar6;
  }
  if (iVar2 == 0) {
    *(undefined2 *)(plVar8 + 0xd8) = 0;
    return 0;
  }
  iVar3 = ___ratelimit(lpass_cdc_va_macro_swr_pwr_event__rs_172,"lpass_cdc_va_macro_swr_pwr_event");
  if (iVar3 == 0) {
    cVar1 = *(char *)((long)plVar8 + 0x6c2);
  }
  else {
    _dev_err(*(undefined8 *)(lVar9 + -0xb8),"%s: request clock VA_CLK disable failed\n",
             "lpass_cdc_va_macro_swr_pwr_event");
    cVar1 = *(char *)((long)plVar8 + 0x6c2);
  }
  if (cVar1 == '\0') {
    return iVar2;
  }
  lVar4 = *plVar8;
  uVar6 = 0;
LAB_0010387c:
  lpass_cdc_clk_rsc_request_clock(lVar4,*(undefined2 *)((long)plVar8 + 0x684),uVar6,0);
  return iVar2;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_tx_swr_clk_event @ 00103980 size=220
// signature: undefined lpass_cdc_va_macro_tx_swr_clk_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_tx_swr_clk_event(long param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + -0xb8),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      if ((param_3 & 3) != 0) {
        *(int *)(lVar2 + 0x688) = *(int *)(lVar2 + 0x688) + 1;
      }
      if ((param_3 & 0xc) == 0) {
        return 0;
      }
      *(int *)(lVar2 + 0x688) = *(int *)(lVar2 + 0x688) + -1;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + -0xb8),pcVar3,"lpass_cdc_va_macro_tx_swr_clk_event");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_swr_clk_event @ 00103a60 size=220
// signature: undefined lpass_cdc_va_macro_swr_clk_event(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_swr_clk_event(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x28);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + -0xb8),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      if (param_3 == 8) {
        iVar1 = *(int *)(lVar2 + 0x68c) + -1;
      }
      else {
        if (param_3 != 1) {
          return 0;
        }
        iVar1 = *(int *)(lVar2 + 0x68c) + 1;
      }
      *(int *)(lVar2 + 0x68c) = iVar1;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + -0xb8),pcVar3,"lpass_cdc_va_macro_swr_clk_event");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_tx_mixer_get @ 00103b40 size=260
// signature: undefined lpass_cdc_va_macro_tx_mixer_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_tx_mixer_get(long param_1,long param_2)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  long lVar7;
  
  lVar5 = snd_soc_dapm_kcontrol_widget();
  lVar7 = *(long *)(lVar5 + 0x28);
  bVar2 = *(byte *)(lVar5 + 0x4c);
  uVar1 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  lVar5 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + -0xb8),3);
  if (lVar5 == 0) {
    iVar4 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: null device for macro!\n";
  }
  else {
    lVar5 = *(long *)(lVar5 + 0x98);
    if ((lVar5 != 0) && (*(long *)(lVar5 + 0xa8) != 0)) {
      if (4 < bVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103c44);
        (*pcVar3)();
      }
      if ((*(ulong *)(lVar5 + (ulong)bVar2 * 8 + ((ulong)(uVar1 >> 3) & 0x1ffffff8) + 0x570) >>
           ((ulong)uVar1 & 0x3f) & 1) == 0) {
        *(undefined8 *)(param_2 + 0x48) = 0;
        return 0;
      }
      *(undefined8 *)(param_2 + 0x48) = 1;
      return 0;
    }
    iVar4 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar4 == 0) {
      return 0xffffffea;
    }
    pcVar6 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar7 + -0xb8),pcVar6,"lpass_cdc_va_macro_tx_mixer_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_tx_mixer_put @ 00103c48 size=532
// signature: undefined lpass_cdc_va_macro_tx_mixer_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_tx_mixer_put(long param_1,long param_2)

{
  ulong *puVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  char *pcVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  
  lVar9 = snd_soc_dapm_kcontrol_widget();
  lVar16 = *(long *)(lVar9 + 0x28);
  bVar3 = *(byte *)(lVar9 + 0x4c);
  uVar14 = (ulong)bVar3;
  uVar2 = *(uint *)(*(long *)(param_1 + 0x78) + 0x18);
  uVar15 = (ulong)uVar2;
  iVar8 = *(int *)(param_2 + 0x48);
  lVar10 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar16 + -0xb8),3);
  if (lVar10 == 0) {
    iVar8 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar8 == 0) {
      return 0xffffffea;
    }
    pcVar12 = "%s: null device for macro!\n";
LAB_00103df8:
    _dev_err(*(undefined8 *)(lVar16 + -0xb8),pcVar12,"lpass_cdc_va_macro_tx_mixer_put");
    return 0xffffffea;
  }
  lVar10 = *(long *)(lVar10 + 0x98);
  if ((lVar10 == 0) || (*(long *)(lVar10 + 0xa8) == 0)) {
    iVar8 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar8 == 0) {
      return 0xffffffea;
    }
    pcVar12 = "%s: priv is null for macro!\n";
    goto LAB_00103df8;
  }
  if (iVar8 == 0) {
    if (4 < bVar3) goto LAB_00103e34;
    lVar10 = lVar10 + uVar14 * 8;
    uVar14 = 1L << (uVar15 & 0x3f);
    if ((*(ulong *)(lVar10 + (ulong)(uVar2 >> 6) * 8 + 0x570) & uVar14) != 0) {
      *(long *)(lVar10 + 0x590) = *(long *)(lVar10 + 0x590) + -1;
      puVar1 = (ulong *)(lVar10 + 0x570 + (ulong)(uVar2 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 & (uVar14 ^ 0xffffffffffffffff);
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      goto LAB_00103dc0;
    }
    iVar7 = ___ratelimit(lpass_cdc_va_macro_tx_mixer_put__rs_113,"lpass_cdc_va_macro_tx_mixer_put");
    if (iVar7 == 0) goto LAB_00103dc0;
    uVar11 = *(undefined8 *)(lVar16 + -0xb8);
    pcVar12 = "%s: channel is already disabled, dec_id = %d, dai_id = %d\n";
  }
  else {
    if (4 < bVar3) {
LAB_00103e34:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103e38);
      (*pcVar6)();
    }
    uVar13 = 1L << (uVar15 & 0x3f);
    if ((*(ulong *)(lVar10 + (ulong)(uint)bVar3 * 8 + (ulong)(uVar2 >> 6) * 8 + 0x570) & uVar13) ==
        0) {
      puVar1 = (ulong *)(lVar10 + uVar14 * 8 + 0x570 + (ulong)(uVar2 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | uVar13;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      lVar10 = lVar10 + uVar14 * 8;
      *(long *)(lVar10 + 0x590) = *(long *)(lVar10 + 0x590) + 1;
      goto LAB_00103dc0;
    }
    iVar7 = ___ratelimit(lpass_cdc_va_macro_tx_mixer_put__rs,"lpass_cdc_va_macro_tx_mixer_put");
    if (iVar7 == 0) goto LAB_00103dc0;
    uVar11 = *(undefined8 *)(lVar16 + -0xb8);
    pcVar12 = "%s: channel is already enabled, dec_id = %d, dai_id = %d\n";
  }
  _dev_err(uVar11,pcVar12,"lpass_cdc_va_macro_tx_mixer_put",uVar15,(uint)bVar3);
LAB_00103dc0:
  snd_soc_dapm_mixer_update_power(*(undefined8 *)(lVar9 + 0x28),param_1,iVar8,0);
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_put_dec_enum @ 00103e74 size=496
// signature: undefined lpass_cdc_va_macro_put_dec_enum(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_put_dec_enum(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  size_t sVar5;
  undefined8 uVar6;
  uint uVar7;
  long lVar8;
  char *pcVar9;
  int *piVar10;
  
  lVar3 = snd_soc_dapm_kcontrol_widget();
  lVar8 = *(long *)(lVar3 + 0x28);
  piVar10 = *(int **)(param_1 + 0x78);
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar8 + -0xb8),3);
  if (lVar4 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: null device for macro!\n";
LAB_0010402c:
    _dev_err(*(undefined8 *)(lVar8 + -0xb8),pcVar9,"lpass_cdc_va_macro_put_dec_enum");
    return 0xffffffea;
  }
  lVar4 = *(long *)(lVar4 + 0x98);
  if ((lVar4 == 0) || (*(long *)(lVar4 + 0xa8) == 0)) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    pcVar9 = "%s: priv is null for macro!\n";
    goto LAB_0010402c;
  }
  uVar1 = *(uint *)(param_2 + 0x48);
  if (piVar10[2] - 1U < uVar1) {
    return 0xffffffea;
  }
  uVar7 = (uint)(CONCAT44(*piVar10,*piVar10 + -0x3100) >> 3);
  if (3 < uVar7) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_put_dec_enum__rs,"lpass_cdc_va_macro_put_dec_enum");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    _dev_err(*(undefined8 *)(lVar8 + -0xb8),"%s: e->reg: 0x%x not expected\n",
             "lpass_cdc_va_macro_put_dec_enum",*piVar10);
    return 0xffffffea;
  }
  pcVar9 = *(char **)(lVar3 + 8);
  lVar8 = lVar8 + -0xd0;
  uVar7 = uVar7 * 0x80 + 0x3404;
  sVar5 = strlen(pcVar9);
  lVar3 = strnstr(pcVar9,&DAT_0010ce20,sVar5);
  if (lVar3 == 0) {
    if (uVar1 == 0) goto LAB_00104054;
    uVar6 = 0x80;
    lVar3 = 0x80;
  }
  else {
    if (uVar1 == 0) goto LAB_00104054;
    if (*(char *)(lVar4 + 0x6c4) == '\0') {
      uVar6 = 0x80;
      lVar3 = 0;
    }
    else {
      snd_soc_component_update_bits(lVar8,uVar7,0x80,0x80);
      snd_soc_component_update_bits(lVar8,0x3094,0x80,0);
      uVar7 = uVar1 * 2 + 0x30c6 & 0xfffc;
      uVar6 = 0xe;
      lVar3 = (ulong)*(ushort *)(lVar4 + 0x5b0) << 1;
    }
  }
  snd_soc_component_update_bits(lVar8,uVar7,uVar6,lVar3);
LAB_00104054:
  uVar6 = snd_soc_dapm_put_enum_double(param_1,param_2);
  return uVar6;
}



//------------------------------------------------------------
// is_amic_enabled @ 00104064 size=208
// signature: undefined is_amic_enabled(void)
// callers: [lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

undefined8 is_amic_enabled(long param_1,int param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  lVar1 = lpass_cdc_get_device_ptr(*(undefined8 *)(param_1 + 0x18),3);
  if (lVar1 == 0) {
    uVar3 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    pcVar4 = "%s: null device for macro!\n";
  }
  else {
    lVar1 = *(long *)(lVar1 + 0x98);
    if ((lVar1 != 0) && (*(long *)(lVar1 + 0xa8) != 0)) {
      uVar2 = snd_soc_component_read(param_1,param_2 * 8 + 0x3104U & 0xfffc);
      if ((uVar2 & 1) == 0) {
        return 0;
      }
      if (*(char *)(lVar1 + 0x6c4) == '\0') {
        return 1;
      }
      return 0;
    }
    uVar3 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if ((int)uVar3 == 0) {
      return uVar3;
    }
    pcVar4 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(param_1 + 0x18),pcVar4,"is_amic_enabled");
  return 0;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_lpi_get @ 00104138 size=180
// signature: undefined lpass_cdc_va_macro_lpi_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_lpi_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(lVar2 + 0x698);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_va_macro_lpi_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_lpi_put @ 001041f0 size=188
// signature: undefined lpass_cdc_va_macro_lpi_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_lpi_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      *(bool *)(lVar2 + 0x698) = *(long *)(param_2 + 0x48) != 0;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_va_macro_lpi_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_swr_dmic_get @ 001042b0 size=180
// signature: undefined lpass_cdc_va_macro_swr_dmic_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_swr_dmic_get(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(lVar2 + 0x6c4);
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_va_macro_swr_dmic_get");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_swr_dmic_put @ 00104368 size=188
// signature: undefined lpass_cdc_va_macro_swr_dmic_put(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_cdc_va_macro_swr_dmic_put(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x80);
  lVar2 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar4 + 0x18),3);
  if (lVar2 == 0) {
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: null device for macro!\n";
  }
  else {
    lVar2 = *(long *)(lVar2 + 0x98);
    if ((lVar2 != 0) && (*(long *)(lVar2 + 0xa8) != 0)) {
      *(bool *)(lVar2 + 0x6c4) = *(long *)(param_2 + 0x48) != 0;
      return 0;
    }
    iVar1 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    pcVar3 = "%s: priv is null for macro!\n";
  }
  _dev_err(*(undefined8 *)(lVar4 + 0x18),pcVar3,"lpass_cdc_va_macro_swr_dmic_put");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_dec_mode_get @ 00104428 size=276
// signature: undefined lpass_cdc_va_macro_dec_mode_get(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_dec_mode_get(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar6 = *(long *)(param_1 + 0x80);
  local_3c = 0;
  lVar3 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar6 + 0x18),3);
  if (lVar3 == 0) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar2 != 0) {
      pcVar5 = "%s: null device for macro!\n";
LAB_00104520:
      _dev_err(*(undefined8 *)(lVar6 + 0x18),pcVar5,"lpass_cdc_va_macro_dec_mode_get");
    }
  }
  else {
    lVar3 = *(long *)(lVar3 + 0x98);
    if ((lVar3 != 0) && (*(long *)(lVar3 + 0xa8) != 0)) {
      uVar4 = lpass_cdc_va_macro_path_get(param_1 + 0x20,&local_3c);
      if ((int)uVar4 == 0) {
        if (3 < local_3c) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10453c);
          (*pcVar1)();
        }
        uVar4 = 0;
        *(long *)(param_2 + 0x48) = (long)*(int *)(lVar3 + (ulong)local_3c * 4 + 0x69c);
      }
      goto LAB_001044ec;
    }
    iVar2 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar2 != 0) {
      pcVar5 = "%s: priv is null for macro!\n";
      goto LAB_00104520;
    }
  }
  uVar4 = 0xffffffea;
LAB_001044ec:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_dec_mode_put @ 00104540 size=272
// signature: undefined lpass_cdc_va_macro_dec_mode_put(void)
// callers: []
//------------------------------------------------------------

void lpass_cdc_va_macro_dec_mode_put(long param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar7 = *(long *)(param_1 + 0x80);
  local_3c = 0;
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  lVar4 = lpass_cdc_get_device_ptr(*(undefined8 *)(lVar7 + 0x18),3);
  if (lVar4 == 0) {
    iVar3 = ___ratelimit(lpass_cdc_va_macro_get_data__rs,"lpass_cdc_va_macro_get_data");
    if (iVar3 != 0) {
      pcVar6 = "%s: null device for macro!\n";
LAB_00104634:
      _dev_err(*(undefined8 *)(lVar7 + 0x18),pcVar6,"lpass_cdc_va_macro_dec_mode_put");
    }
  }
  else {
    lVar4 = *(long *)(lVar4 + 0x98);
    if ((lVar4 != 0) && (*(long *)(lVar4 + 0xa8) != 0)) {
      uVar5 = lpass_cdc_va_macro_path_get(param_1 + 0x20,&local_3c);
      if ((int)uVar5 == 0) {
        if (3 < local_3c) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104650);
          (*pcVar2)();
        }
        uVar5 = 0;
        *(undefined4 *)(lVar4 + (ulong)local_3c * 4 + 0x69c) = uVar1;
      }
      goto LAB_00104600;
    }
    iVar3 = ___ratelimit(lpass_cdc_va_macro_get_data__rs_61,"lpass_cdc_va_macro_get_data");
    if (iVar3 != 0) {
      pcVar6 = "%s: priv is null for macro!\n";
      goto LAB_00104634;
    }
  }
  uVar5 = 0xffffffea;
LAB_00104600:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_cdc_va_macro_path_get @ 00104650 size=336
// signature: undefined lpass_cdc_va_macro_path_get(void)
// callers: [lpass_cdc_va_macro_dec_mode_put, lpass_cdc_va_macro_dec_mode_get]
//------------------------------------------------------------

int lpass_cdc_va_macro_path_get(undefined8 param_1,undefined8 param_2)

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
    goto LAB_00104758;
  }
  pcVar5 = strsep(&local_30," ");
  if (pcVar5 == (char *)0x0) {
    iVar2 = ___ratelimit(lpass_cdc_va_macro_path_get__rs,"lpass_cdc_va_macro_path_get");
    if (iVar2 != 0) {
      _printk(&DAT_0010c829,"lpass_cdc_va_macro_path_get",local_30);
    }
LAB_0010474c:
    iVar2 = -0x16;
  }
  else {
    pcVar5 = strpbrk(pcVar5,"01234567");
    if (pcVar5 == (char *)0x0) {
      iVar2 = ___ratelimit(lpass_cdc_va_macro_path_get__rs_194,"lpass_cdc_va_macro_path_get");
      if (iVar2 != 0) {
        _printk(&DAT_0010ce4d,"lpass_cdc_va_macro_path_get");
      }
      goto LAB_0010474c;
    }
    iVar2 = kstrtouint(pcVar5,10,param_2);
    if ((iVar2 < 0) &&
       (iVar3 = ___ratelimit(lpass_cdc_va_macro_path_get__rs_196,"lpass_cdc_va_macro_path_get"),
       iVar3 != 0)) {
      _printk(&DAT_0010c849,"lpass_cdc_va_macro_path_get",pcVar4);
    }
  }
  kfree(pcVar4);
LAB_00104758:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 001047a4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpass_cdc_va_macro_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001047d4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpass_cdc_va_macro_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010f000 size=1
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
// platform_driver_unregister @ 0010f008 size=1
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
// devm_kmalloc @ 0010f010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010f018 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010f020 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_cdc_va_macro_set_port_map, lpass_cdc_va_macro_tx_va_mclk_enable, lpass_cdc_va_macro_clk_div_get, is_amic_enabled, lpass_cdc_va_macro_tx_swr_clk_event, lpass_cdc_va_macro_hw_params, lpass_cdc_va_macro_add_child_devices, lpass_cdc_va_macro_swr_dmic_get, lpass_cdc_va_macro_init, lpass_cdc_va_macro_reg_wake_irq, lpass_cdc_va_macro_deinit, lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_swrm_clock, lpass_cdc_va_macro_tx_mixer_get, lpass_cdc_va_macro_swr_clk_event, lpass_cdc_va_macro_tx_mixer_put, lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_get_channel_map, lpass_cdc_va_macro_enable_micbias, lpass_cdc_va_macro_lpi_get, lpass_cdc_va_macro_lpi_put, lpass_cdc_va_macro_enable_tx, lpass_cdc_va_macro_dec_mode_get, lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_swr_dmic_put, lpass_cdc_va_macro_mclk_event, lpass_cdc_va_macro_probe, lpass_cdc_va_macro_dec_mode_put, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010f028 size=1
// signature: undefined of_find_property(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010f030 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 0010f038 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0010f040 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010f048 size=1
// signature: undefined devm_clk_get(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 0010f050 size=1
// signature: undefined devm_regulator_get(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010f058 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_register_macro @ 0010f060 size=1
// signature: undefined lpass_cdc_register_macro(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_register_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010f068 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0010f070 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0010f078 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpass_cdc_va_macro_remove, lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010f080 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010f090 size=1
// signature: undefined queue_work_on(void)
// callers: [lpass_cdc_va_macro_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010f098 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_cdc_va_macro_set_port_map, lpass_cdc_va_macro_dec_mode_put, lpass_cdc_va_macro_dec_mode_get, lpass_cdc_va_macro_add_child_devices, lpass_cdc_va_macro_path_get, lpass_cdc_va_macro_probe, lpass_cdc_va_macro_reg_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010f0a0 size=1
// signature: undefined kfree(void)
// callers: [lpass_cdc_va_macro_remove, lpass_cdc_va_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 0010f0a8 size=1
// signature: undefined platform_device_unregister(void)
// callers: [lpass_cdc_va_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0010f0b0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpass_cdc_va_macro_remove, lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_unregister_macro @ 0010f0b8 size=1
// signature: undefined lpass_cdc_unregister_macro(void)
// callers: [lpass_cdc_va_macro_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_unregister_macro(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010f0c0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0010f0c8 size=1
// signature: undefined strnstr(void)
// callers: [lpass_cdc_va_macro_add_child_devices, lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010f0d0 size=1
// signature: size_t strlen(char * __s)
// callers: [lpass_cdc_va_macro_add_child_devices, lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010f0d8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 0010f0e0 size=1
// signature: undefined platform_device_alloc(void)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add_data @ 0010f0e8 size=1
// signature: undefined platform_device_add_data(void)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 0010f0f0 size=1
// signature: undefined krealloc(void)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 0010f0f8 size=1
// signature: undefined platform_device_add(void)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010f100 size=1
// signature: undefined _printk(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_core_vote, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_add_child_devices, lpass_cdc_va_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 0010f108 size=1
// signature: undefined platform_device_put(void)
// callers: [lpass_cdc_va_macro_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 0010f110 size=1
// signature: undefined dev_get_regmap(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010f118 size=1
// signature: undefined mutex_lock(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback, lpass_cdc_va_macro_mute_update_callback, lpass_cdc_va_macro_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010f120 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_core_vote, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_swrm_clock, lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010f128 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_cdc_va_macro_set_port_map, lpass_cdc_va_macro_tx_va_mclk_enable, lpass_cdc_va_macro_clk_div_get, is_amic_enabled, lpass_cdc_va_macro_tx_swr_clk_event, lpass_cdc_va_macro_hw_params, lpass_cdc_va_macro_swr_dmic_get, lpass_cdc_va_macro_reg_wake_irq, lpass_cdc_va_macro_deinit, lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_core_vote, lpass_cdc_va_macro_swrm_clock, lpass_cdc_va_macro_tx_mixer_get, lpass_cdc_va_macro_path_get, lpass_cdc_va_macro_swr_clk_event, lpass_cdc_va_macro_tx_mixer_put, lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_get_channel_map, lpass_cdc_va_macro_enable_micbias, lpass_cdc_va_macro_lpi_get, lpass_cdc_va_macro_lpi_put, lpass_cdc_va_macro_enable_tx, lpass_cdc_va_macro_dec_mode_get, lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_swr_dmic_put, lpass_cdc_va_macro_mclk_event, lpass_cdc_va_macro_dec_mode_put, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010f130 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_core_vote, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_swrm_clock, lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010f138 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_core_vote, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_swrm_clock, lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010f140 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback, lpass_cdc_va_macro_mute_update_callback, lpass_cdc_va_macro_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_check_core_votes @ 0010f148 size=1
// signature: undefined lpass_cdc_check_core_votes(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_core_vote, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_check_core_votes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 0010f150 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [lpass_cdc_va_macro_tx_va_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_set_wakeup_capable @ 0010f158 size=1
// signature: undefined msm_cdc_pinctrl_set_wakeup_capable(void)
// callers: [lpass_cdc_va_macro_tx_va_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_request_clock @ 0010f160 size=1
// signature: undefined lpass_cdc_clk_rsc_request_clock(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_tx_va_mclk_enable, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_enable_tx, lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_mclk_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_request_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clk_rsc_fs_gen_request @ 0010f168 size=1
// signature: undefined lpass_cdc_clk_rsc_fs_gen_request(void)
// callers: [lpass_cdc_va_macro_mclk_enable, lpass_cdc_va_macro_tx_va_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clk_rsc_fs_gen_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 0010f170 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [lpass_cdc_va_macro_tx_va_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 0010f178 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [lpass_cdc_va_macro_tx_va_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 0010f180 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [lpass_cdc_va_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync_region @ 0010f188 size=1
// signature: undefined regcache_sync_region(void)
// callers: [lpass_cdc_va_macro_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_device_ptr @ 0010f190 size=1
// signature: undefined lpass_cdc_get_device_ptr(void)
// callers: [lpass_cdc_va_macro_set_port_map, lpass_cdc_va_macro_clk_div_get, is_amic_enabled, lpass_cdc_va_macro_tx_swr_clk_event, lpass_cdc_va_macro_hw_params, lpass_cdc_va_macro_swr_dmic_get, lpass_cdc_va_macro_init, lpass_cdc_va_macro_reg_wake_irq, lpass_cdc_va_macro_deinit, lpass_cdc_va_macro_tx_mixer_get, lpass_cdc_va_macro_swr_clk_event, lpass_cdc_va_macro_tx_mixer_put, lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_get_channel_map, lpass_cdc_va_macro_enable_micbias, lpass_cdc_va_macro_lpi_get, lpass_cdc_va_macro_lpi_put, lpass_cdc_va_macro_enable_tx, lpass_cdc_va_macro_dec_mode_get, lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_swr_dmic_put, lpass_cdc_va_macro_mclk_event, lpass_cdc_va_macro_dec_mode_put, lpass_cdc_va_macro_swr_pwr_event, lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_device_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_get_version @ 0010f198 size=1
// signature: undefined lpass_cdc_get_version(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_get_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_controls @ 0010f1a0 size=1
// signature: undefined snd_soc_dapm_new_controls(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_add_routes @ 0010f1a8 size=1
// signature: undefined snd_soc_dapm_add_routes(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_add_routes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_new_widgets @ 0010f1b0 size=1
// signature: undefined snd_soc_dapm_new_widgets(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_new_widgets(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 0010f1b8 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 0010f1c0 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 0010f1c8 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0010f1d8 size=1
// signature: undefined init_timer_key(void)
// callers: [lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_update_bits @ 0010f1e0 size=1
// signature: undefined snd_soc_component_update_bits(void)
// callers: [lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback, lpass_cdc_va_macro_hw_params, lpass_cdc_va_macro_mute_update_callback, lpass_cdc_va_macro_put_dec_enum, lpass_cdc_va_macro_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swrm_wcd_notify @ 0010f1e8 size=1
// signature: undefined swrm_wcd_notify(void)
// callers: [lpass_cdc_va_macro_set_port_map, lpass_cdc_va_macro_event_handler, lpass_cdc_va_macro_reg_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swrm_wcd_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_runtime_suspend @ 0010f1f0 size=1
// signature: undefined lpass_cdc_runtime_suspend(void)
// callers: [lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010f1f8 size=1
// signature: undefined msleep(void)
// callers: [lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_rsc_clk_reset @ 0010f200 size=1
// signature: undefined lpass_cdc_rsc_clk_reset(void)
// callers: [lpass_cdc_va_macro_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_rsc_clk_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_read @ 0010f208 size=1
// signature: undefined snd_soc_component_read(void)
// callers: [is_amic_enabled, lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_clear_amic_tx_hold @ 0010f210 size=1
// signature: undefined lpass_cdc_clear_amic_tx_hold(void)
// callers: [lpass_cdc_va_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_clear_amic_tx_hold(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010f218 size=1
// signature: undefined usleep_range_state(void)
// callers: [lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 0010f220 size=1
// signature: undefined pm_relax(void)
// callers: [lpass_cdc_va_macro_enable_dec, lpass_cdc_va_macro_tx_hpf_corner_freq_callback, lpass_cdc_va_macro_mute_update_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 0010f228 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [lpass_cdc_va_macro_enable_micbias]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0010f230 size=1
// signature: undefined regulator_disable(void)
// callers: [lpass_cdc_va_macro_enable_micbias]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 0010f238 size=1
// signature: undefined regulator_set_load(void)
// callers: [lpass_cdc_va_macro_enable_micbias]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0010f240 size=1
// signature: undefined regulator_enable(void)
// callers: [lpass_cdc_va_macro_enable_micbias]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_dmic_clk_enable @ 0010f248 size=1
// signature: undefined lpass_cdc_dmic_clk_enable(void)
// callers: [lpass_cdc_va_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_dmic_clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 0010f250 size=1
// signature: undefined pm_stay_awake(void)
// callers: [lpass_cdc_va_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0010f260 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [lpass_cdc_va_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0010f268 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [lpass_cdc_va_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_write @ 0010f270 size=1
// signature: undefined snd_soc_component_write(void)
// callers: [lpass_cdc_va_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0010f278 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [lpass_cdc_va_macro_enable_dec]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lpass_cdc_tx_mclk_enable @ 0010f280 size=1
// signature: undefined lpass_cdc_tx_mclk_enable(void)
// callers: [lpass_cdc_va_macro_mclk_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lpass_cdc_tx_mclk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_kcontrol_widget @ 0010f288 size=1
// signature: undefined snd_soc_dapm_kcontrol_widget(void)
// callers: [lpass_cdc_va_macro_tx_mixer_put, lpass_cdc_va_macro_tx_mixer_get, lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_kcontrol_widget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_mixer_update_power @ 0010f298 size=1
// signature: undefined snd_soc_dapm_mixer_update_power(void)
// callers: [lpass_cdc_va_macro_tx_mixer_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_mixer_update_power(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_put_enum_double @ 0010f2a0 size=1
// signature: undefined snd_soc_dapm_put_enum_double(void)
// callers: [lpass_cdc_va_macro_put_dec_enum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_put_enum_double(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 0010f2a8 size=1
// signature: undefined kstrndup(void)
// callers: [lpass_cdc_va_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0010f2b0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [lpass_cdc_va_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 0010f2b8 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [lpass_cdc_va_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010f2c0 size=1
// signature: undefined kstrtouint(void)
// callers: [lpass_cdc_va_macro_path_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



