// Decompiled by Ghidra 12.2
// Program: lpass_bt_swr_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpass_bt_swr_check_core_votes @ 001002e4 size=112
// signature: undefined lpass_bt_swr_check_core_votes(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_bt_swr_check_core_votes(long param_1)

{
  undefined8 uVar1;
  
  mutex_lock(param_1 + 8);
  if (((*(char *)(param_1 + 0x98) == '\0') ||
      ((*(long *)(param_1 + 0xa0) != 0 && (*(int *)(param_1 + 0xb0) == 0)))) ||
     ((*(long *)(param_1 + 0xa8) != 0 && (*(int *)(param_1 + 0xb4) == 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  mutex_unlock(param_1 + 8);
  return uVar1;
}



//------------------------------------------------------------
// lpass_bt_swr_runtime_resume @ 00100358 size=268
// signature: undefined lpass_bt_swr_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_bt_swr_runtime_resume(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0x98);
  mutex_lock(puVar2 + 1);
  if (puVar2[0x14] != 0) {
    iVar1 = *(int *)(puVar2 + 0x16);
    if (iVar1 == 0) {
      iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(puVar2[0x14],param_1);
      if (iVar1 < 0) {
        iVar1 = ___ratelimit(&lpass_bt_swr_runtime_resume__rs,"lpass_bt_swr_runtime_resume");
        if (iVar1 != 0) {
          _dev_err(param_1,"%s:lpass core hw enable failed\n","lpass_bt_swr_runtime_resume");
        }
        goto LAB_001003a8;
      }
      iVar1 = *(int *)(puVar2 + 0x16);
    }
    *(int *)(puVar2 + 0x16) = iVar1 + 1;
  }
LAB_001003a8:
  if (puVar2[0x15] != 0) {
    iVar1 = *(int *)((long)puVar2 + 0xb4);
    if (iVar1 == 0) {
      iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(puVar2[0x15],param_1);
      if (iVar1 < 0) {
        iVar1 = ___ratelimit(lpass_bt_swr_runtime_resume__rs_1,"lpass_bt_swr_runtime_resume");
        if (iVar1 != 0) {
          _dev_err(param_1,"%s:lpass audio hw enable failed\n","lpass_bt_swr_runtime_resume");
        }
        goto LAB_001003d0;
      }
      iVar1 = *(int *)((long)puVar2 + 0xb4);
    }
    *(int *)((long)puVar2 + 0xb4) = iVar1 + 1;
  }
LAB_001003d0:
  mutex_unlock(puVar2 + 1);
  pm_runtime_set_autosuspend_delay(*puVar2,100);
  return 0;
}



//------------------------------------------------------------
// lpass_bt_swr_runtime_suspend @ 00100468 size=184
// signature: undefined lpass_bt_swr_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_bt_swr_runtime_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar3 + 8);
  if (*(long *)(lVar3 + 0xa0) != 0) {
    iVar1 = *(int *)(lVar3 + 0xb0) + -1;
    *(int *)(lVar3 + 0xb0) = iVar1;
    if (iVar1 == 0) {
      digital_cdc_rsc_mgr_hw_vote_disable(*(long *)(lVar3 + 0xa0),param_1);
      iVar1 = *(int *)(lVar3 + 0xb0);
    }
    if (iVar1 < 0) {
      *(undefined4 *)(lVar3 + 0xb0) = 0;
      lVar2 = *(long *)(lVar3 + 0xa8);
      goto joined_r0x001004b0;
    }
  }
  lVar2 = *(long *)(lVar3 + 0xa8);
joined_r0x001004b0:
  if (lVar2 != 0) {
    iVar1 = *(int *)(lVar3 + 0xb4) + -1;
    *(int *)(lVar3 + 0xb4) = iVar1;
    if (iVar1 == 0) {
      digital_cdc_rsc_mgr_hw_vote_disable(lVar2,param_1);
      iVar1 = *(int *)(lVar3 + 0xb4);
    }
    if (iVar1 < 0) {
      *(undefined4 *)(lVar3 + 0xb4) = 0;
    }
  }
  mutex_unlock(lVar3 + 8);
  return 0;
}



//------------------------------------------------------------
// lpass_bt_swr_probe @ 00100524 size=804
// signature: undefined lpass_bt_swr_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void lpass_bt_swr_probe(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  long local_98 [11];
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_98[10] = *(long *)(lVar2 + 0x638);
  plVar4 = (long *)devm_kmalloc(lVar1,0x1b8,0xdc0);
  if (plVar4 == (long *)0x0) {
    uVar5 = 0xfffffff4;
  }
  else {
    __init_rwsem(plVar4 + 0x2d,"&(&priv->notifier)->rwsem",&lpass_bt_swr_probe___key);
    plVar4[0x35] = 0;
    *plVar4 = lVar1;
    plVar4[0x16] = 0;
    *(undefined1 *)(plVar4 + 0x13) = 1;
    *(long **)(param_1 + 0xa8) = plVar4;
    __mutex_init(plVar4 + 1,"&priv->vote_lock",&lpass_bt_swr_probe___key_5);
    __mutex_init(plVar4 + 7,"&priv->swr_clk_lock",&lpass_bt_swr_probe___key_7);
    __mutex_init(plVar4 + 0xd,"&priv->ssr_lock",&lpass_bt_swr_probe___key_9);
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
    iVar3 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,bt-swr-gpios",0,0,0,local_98);
    lVar2 = local_98[0];
    if (iVar3 != 0) {
      lVar2 = 0;
    }
    plVar4[0x2a] = lVar2;
    if (lVar2 == 0) {
      _dev_err(lVar1,"%s: swr_gpios handle not provided!\n","lpass_bt_swr_probe");
      uVar5 = 0xffffffea;
    }
    else {
      iVar3 = msm_cdc_pinctrl_get_state();
      if (iVar3 < 0) {
        _dev_info(lVar1,"%s: failed to get swr pin state\n","lpass_bt_swr_probe");
        uVar5 = 0xfffffdfb;
      }
      else {
        uVar6 = devm_clk_get(lVar1,"lpass_core_hw_vote");
        uVar7 = 0;
        if (uVar6 < 0xfffffffffffff001) {
          uVar7 = uVar6;
        }
        plVar4[0x14] = uVar7;
        uVar6 = devm_clk_get(lVar1,"lpass_audio_hw_vote");
        uVar7 = 0;
        if (uVar6 < 0xfffffffffffff001) {
          uVar7 = uVar6;
        }
        plVar4[0x15] = uVar7;
        uVar7 = devm_clk_get(lVar1,"bt_swr_mclk_clk");
        if (uVar7 < 0xfffffffffffff001) {
          plVar4[0x18] = uVar7;
          uVar6 = devm_clk_get(lVar1,"bt_swr_mclk_clk_2x");
          uVar7 = 0;
          if (uVar6 < 0xfffffffffffff001) {
            uVar7 = uVar6;
          }
          plVar4[0x21] = 0;
          plVar4[0x22] = 0xfffffffe0;
          plVar4[0x19] = uVar7;
          plVar4[0x23] = (long)(plVar4 + 0x23);
          plVar4[0x24] = (long)(plVar4 + 0x23);
          plVar4[0x25] = (long)lpass_bt_swr_add_child_devices;
          plVar4[0x1b] = (long)plVar4;
          plVar4[0x1c] = 0;
          plVar4[0x1d] = 0;
          plVar4[0x1e] = 0;
          plVar4[0x1f] = (long)lpass_bt_swrm_clock;
          plVar4[0x20] = (long)lpass_bt_swr_core_vote;
          lpass_bt_priv = plVar4;
          pm_runtime_set_autosuspend_delay(lVar1,100);
          __pm_runtime_use_autosuspend(lVar1,1);
          __pm_runtime_set_status(lVar1,2);
          *(ushort *)(param_1 + 0x210) = *(ushort *)(param_1 + 0x210) | 0x100;
          pm_runtime_enable(lVar1);
          queue_work_on(0x20,_system_wq,plVar4 + 0x22);
          *(undefined1 *)((long)plVar4 + 0x99) = 1;
          iVar3 = snd_event_client_register(*plVar4,&lpass_bt_swr_ssr_ops,plVar4);
          if (iVar3 == 0) {
            snd_event_notify(*plVar4,1);
            _dev_err(lVar1,"%s: Registered SSR ops\n","lpass_bt_swr_probe");
          }
          else {
            _dev_err(lVar1,"%s: Registration with SND event FWK failed ret = %d\n",
                     "lpass_bt_swr_probe",iVar3);
          }
          uVar5 = 0;
        }
        else {
          _dev_err(lVar1,"%s: clk get %s failed %d\n","lpass_bt_swr_probe","bt_swr_clk");
          uVar5 = 0xffffffea;
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// lpass_bt_swr_remove @ 0010084c size=88
// signature: undefined lpass_bt_swr_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_bt_swr_remove(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0xa8) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    param_1 = param_1 + 0x10;
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    of_platform_depopulate(param_1);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpass_bt_swr_add_child_devices @ 001008a8 size=604
// signature: undefined lpass_bt_swr_add_child_devices(void)
// callers: []
//------------------------------------------------------------

void lpass_bt_swr_add_child_devices(long param_1)

{
  ulong uVar1;
  long *plVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  ushort uVar10;
  ulong uVar11;
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
  plVar2 = (long *)(param_1 + -0x110);
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
    _printk(&DAT_00101703,"lpass_bt_swr_add_child_devices");
  }
  else {
    lVar5 = *plVar2;
    if ((lVar5 == 0) || (*(long *)(lVar5 + 0x2e8) == 0)) {
      pcVar8 = "%s: DT node for priv does not exist\n";
LAB_00100a20:
      _dev_err(lVar5,pcVar8,"lpass_bt_swr_add_child_devices");
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = 0;
      puVar6 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(lVar5 + 0x2e8),0);
      if (puVar6 != (undefined8 *)0x0) {
        uVar10 = 0;
        lVar9 = 0;
        do {
          lVar5 = strnstr(*puVar6,"bt_swr_mstr",0xb);
          if (lVar5 != 0) {
            strscpy(&local_b8,"bt_swr_mstr",0xc);
            lVar7 = platform_device_alloc(&local_b8,0xffffffff);
            lVar5 = *plVar2;
            if (lVar7 == 0) {
              pcVar8 = "%s: pdev memory alloc failed\n";
              goto LAB_00100a20;
            }
            *(long *)(lVar7 + 0x70) = lVar5;
            *(undefined8 **)(lVar7 + 0x2f8) = puVar6;
            iVar4 = platform_device_add_data(lVar7,param_1 + -0x38,0x38);
            if (iVar4 == 0) {
              uVar11 = (ulong)uVar10;
              uVar1 = uVar11 * 8 + 8;
              lVar9 = krealloc(lVar9,uVar1,0xcc0);
              if (lVar9 == 0) {
                _dev_err(lVar7 + 0x10,"out of memory\n");
              }
              else {
                if ((uVar1 < uVar11 * 8) || (uVar1 + uVar11 * -8 < 8)) {
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(1,0x100afc);
                  (*pcVar3)();
                }
                *(long *)(lVar9 + uVar11 * 8) = lVar7;
                *(long *)(param_1 + -0x40) = lVar9;
                iVar4 = platform_device_add(lVar7);
                if (iVar4 == 0) {
                  iVar4 = *(int *)(param_1 + 0x38);
                  if (iVar4 < 1) {
                    *(int *)(param_1 + 0x38) = iVar4 + 1;
                    if (iVar4 != 0) goto LAB_00100afc;
                    uVar10 = uVar10 + 1;
                    *(long *)(param_1 + 0x30) = lVar7;
                    goto LAB_0010093c;
                  }
                  break;
                }
                _dev_err(lVar7 + 0x10,"%s: Cannot add platform device\n",
                         "lpass_bt_swr_add_child_devices");
              }
            }
            else {
              _dev_err(lVar7 + 0x10,"%s: cannot add plat data ctrl:%d\n",
                       "lpass_bt_swr_add_child_devices",uVar10);
            }
            if ((0 < *(int *)(param_1 + 0x38)) &&
               (platform_device_put(*(undefined8 *)(param_1 + 0x30)), 1 < *(int *)(param_1 + 0x38)))
            {
LAB_00100afc:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100b00);
              (*pcVar3)();
            }
            break;
          }
LAB_0010093c:
          puVar6 = (undefined8 *)
                   of_get_next_available_child(*(undefined8 *)(*plVar2 + 0x2e8),puVar6);
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
// lpass_bt_swrm_clock @ 00100b08 size=460
// signature: undefined lpass_bt_swrm_clock(void)
// callers: []
//------------------------------------------------------------

int lpass_bt_swrm_clock(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  
  mutex_lock(param_1 + 7);
  if ((param_2 & 1) == 0) {
    if ((int)param_1[0x17] < 1) {
      iVar1 = ___ratelimit(lpass_bt_swrm_clock__rs_32,"lpass_bt_swrm_clock");
      if (iVar1 != 0) {
        _dev_err(*param_1,"%s: clock already disabled\n","lpass_bt_swrm_clock");
      }
      iVar1 = 0;
      *(undefined4 *)(param_1 + 0x17) = 0;
    }
    else {
      iVar1 = (int)param_1[0x17] + -1;
      *(int *)(param_1 + 0x17) = iVar1;
      if (iVar1 == 0) {
        lpass_bt_swr_mclk_enable(param_1,0);
        iVar1 = msm_cdc_pinctrl_select_sleep_state(param_1[0x2a]);
        if ((iVar1 < 0) &&
           (iVar2 = ___ratelimit(lpass_bt_swrm_clock__rs_34,"lpass_bt_swrm_clock"), iVar2 != 0)) {
          _dev_err(*param_1,"%s: bt swr pinctrl disable failed\n","lpass_bt_swrm_clock");
        }
      }
      else {
        iVar1 = 0;
      }
    }
    goto LAB_00100c7c;
  }
  __pm_runtime_resume(*param_1,4);
  iVar2 = (int)param_1[0x17];
  if (iVar2 == 0) {
    iVar1 = msm_cdc_pinctrl_select_active_state(param_1[0x2a]);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(lpass_bt_swrm_clock__rs,"lpass_bt_swrm_clock");
      if (iVar2 != 0) {
        lVar5 = *param_1;
        pcVar4 = "%s: bt swr pinctrl enable failed\n";
LAB_00100cc4:
        _dev_err(lVar5,pcVar4,"lpass_bt_swrm_clock");
      }
    }
    else {
      iVar1 = lpass_bt_swr_mclk_enable(param_1,1);
      if (-1 < iVar1) {
        iVar2 = (int)param_1[0x17];
        goto LAB_00100b4c;
      }
      msm_cdc_pinctrl_select_sleep_state(param_1[0x2a]);
      iVar2 = ___ratelimit(lpass_bt_swrm_clock__rs_30,"lpass_bt_swrm_clock");
      if (iVar2 != 0) {
        lVar5 = *param_1;
        pcVar4 = "%s: lpass bt swr request clock enable failed\n";
        goto LAB_00100cc4;
      }
    }
    lVar5 = *param_1;
  }
  else {
    iVar1 = 0;
LAB_00100b4c:
    lVar5 = *param_1;
    *(int *)(param_1 + 0x17) = iVar2 + 1;
  }
  uVar3 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar5 + 0x220) = uVar3;
  __pm_runtime_suspend(*param_1,0xd);
LAB_00100c7c:
  mutex_unlock(param_1 + 7);
  return iVar1;
}



//------------------------------------------------------------
// lpass_bt_swr_core_vote @ 00100cd8 size=248
// signature: undefined lpass_bt_swr_core_vote(void)
// callers: [lpass_bt_swr_mclk_enable]
//------------------------------------------------------------

undefined8 lpass_bt_swr_core_vote(long *param_1,ulong param_2)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  long lVar5;
  
  if (param_1 == (long *)0x0) {
    iVar2 = ___ratelimit(lpass_bt_swr_core_vote__rs,"lpass_bt_swr_core_vote");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar4 = &DAT_001017b0;
  }
  else {
    if (((char)param_1[0x13] != '\0') || ((param_2 & 1) == 0)) {
      if ((param_2 & 1) == 0) {
        __pm_runtime_suspend(*param_1,0xd);
        lVar5 = *param_1;
        uVar3 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar5 + 0x220) = uVar3;
        return 0;
      }
      __pm_runtime_resume(*param_1,4);
      plVar1 = param_1 + 1;
      mutex_lock(plVar1);
      if ((((char)param_1[0x13] == '\0') || ((param_1[0x14] != 0 && ((int)param_1[0x16] == 0)))) ||
         ((param_1[0x15] != 0 && (*(int *)((long)param_1 + 0xb4) == 0)))) {
        mutex_unlock(plVar1);
        return 0xfffffdf6;
      }
      mutex_unlock(plVar1);
      return 0;
    }
    puVar4 = &DAT_001018e2;
  }
  _printk(puVar4,"lpass_bt_swr_core_vote");
  return 0xffffffea;
}



//------------------------------------------------------------
// lpass_bt_swr_mclk_enable @ 00100dd0 size=472
// signature: undefined lpass_bt_swr_mclk_enable(void)
// callers: [lpass_bt_swrm_clock, lpass_bt_swr_ssr_enable]
//------------------------------------------------------------

int lpass_bt_swr_mclk_enable(long *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  iVar1 = lpass_bt_swr_core_vote(param_1,1);
  if (iVar1 < 0) {
    iVar2 = ___ratelimit(lpass_bt_swr_mclk_enable__rs,"lpass_bt_swr_mclk_enable");
    if (iVar2 == 0) {
      return iVar1;
    }
    _dev_err(*param_1,"%s: request core vote failed\n","lpass_bt_swr_mclk_enable");
    return iVar1;
  }
  lVar4 = param_1[0x18];
  if ((param_2 & 1) == 0) {
    clk_disable(lVar4);
    clk_unprepare(lVar4);
    lVar4 = param_1[0x19];
    if (lVar4 == 0) goto LAB_00100ecc;
  }
  else {
    iVar1 = clk_prepare();
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar4);
      if (iVar1 != 0) {
        clk_unprepare(lVar4);
        goto joined_r0x00100e90;
      }
    }
    else {
joined_r0x00100e90:
      if (iVar1 < 0) {
        iVar2 = ___ratelimit(lpass_bt_swr_mclk_enable__rs_37,"lpass_bt_swr_mclk_enable");
        if (iVar2 != 0) {
          _dev_err(*param_1,"%s: bt_swr_clk enable failed\n","lpass_bt_swr_mclk_enable");
        }
        goto LAB_00100ecc;
      }
    }
    lVar4 = param_1[0x19];
    if (lVar4 == 0) goto LAB_00100ecc;
    iVar1 = clk_prepare(lVar4);
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar4);
      if (iVar1 == 0) goto LAB_00100ecc;
      clk_unprepare(lVar4);
    }
    if (-1 < iVar1) goto LAB_00100ecc;
    iVar2 = ___ratelimit(lpass_bt_swr_mclk_enable__rs_39,"lpass_bt_swr_mclk_enable");
    if (iVar2 != 0) {
      _dev_err(*param_1,"%s: bt_swr_2x_clk enable failed\n","lpass_bt_swr_mclk_enable");
    }
    lVar4 = param_1[0x18];
  }
  clk_disable(lVar4);
  clk_unprepare(lVar4);
LAB_00100ecc:
  if (param_1 == (long *)0x0) {
    iVar2 = ___ratelimit(lpass_bt_swr_core_vote__rs,"lpass_bt_swr_core_vote");
    if (iVar2 != 0) {
      _printk(&DAT_001017b0,"lpass_bt_swr_core_vote");
    }
  }
  else {
    __pm_runtime_suspend(*param_1,0xd);
    lVar4 = *param_1;
    uVar3 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar4 + 0x220) = uVar3;
  }
  return iVar1;
}



//------------------------------------------------------------
// lpass_bt_swr_ssr_enable @ 00100fac size=288
// signature: undefined lpass_bt_swr_ssr_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 lpass_bt_swr_ssr_enable(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  
  if (*(char *)((long)param_2 + 0x99) == '\0') {
    mutex_lock(param_2 + 0xd);
    *(undefined1 *)(param_2 + 0x13) = 1;
    mutex_unlock(param_2 + 0xd);
    mutex_lock(param_2 + 7);
    lpass_bt_swr_mclk_enable(param_2,0);
    iVar1 = msm_cdc_pinctrl_select_sleep_state(param_2[0x2a]);
    if ((iVar1 < 0) &&
       (iVar1 = ___ratelimit(lpass_bt_swr_ssr_enable__rs,"lpass_bt_swr_ssr_enable"), iVar1 != 0)) {
      _dev_err(*param_2,"%s: bt swr pinctrl disable failed\n","lpass_bt_swr_ssr_enable");
    }
    if (0 < *(int *)(param_2 + 0x17)) {
      lpass_bt_swr_mclk_enable(param_2,1);
      iVar1 = msm_cdc_pinctrl_select_active_state(param_2[0x2a]);
      if ((iVar1 < 0) &&
         (iVar1 = ___ratelimit(lpass_bt_swr_ssr_enable__rs_43,"lpass_bt_swr_ssr_enable"), iVar1 != 0
         )) {
        _dev_err(*param_2,"%s: bt swr pinctrl enable failed\n","lpass_bt_swr_ssr_enable");
      }
    }
    mutex_unlock(param_2 + 7);
    swrm_wcd_notify(*(undefined8 *)param_2[0x1a],7,0);
  }
  else {
    *(undefined1 *)((long)param_2 + 0x99) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// lpass_bt_swr_ssr_disable @ 001010d0 size=144
// signature: undefined lpass_bt_swr_ssr_disable(void)
// callers: []
//------------------------------------------------------------

void lpass_bt_swr_ssr_disable(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  
  if (*(char *)(param_2 + 0x13) == '\0') {
    iVar1 = ___ratelimit(lpass_bt_swr_ssr_disable__rs,"lpass_bt_swr_ssr_disable");
    if (iVar1 != 0) {
      _dev_err(*param_2,"%s: already disabled\n","lpass_bt_swr_ssr_disable");
    }
  }
  else {
    mutex_lock(param_2 + 0xd);
    *(undefined1 *)(param_2 + 0x13) = 0;
    mutex_unlock(param_2 + 0xd);
    swrm_wcd_notify(*(undefined8 *)param_2[0x1a],6,0);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101164 size=48
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  __platform_driver_register(&lpass_bt_swr_drv,&__this_module);
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00101198 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpass_bt_swr_drv);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00103000 size=1
// signature: undefined mutex_lock(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swrm_clock, lpass_bt_swr_check_core_votes, lpass_bt_swr_runtime_resume, lpass_bt_swr_ssr_enable, lpass_bt_swr_ssr_disable, lpass_bt_swr_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103008 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swrm_clock, lpass_bt_swr_check_core_votes, lpass_bt_swr_runtime_resume, lpass_bt_swr_ssr_enable, lpass_bt_swr_ssr_disable, lpass_bt_swr_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_enable @ 00103010 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_enable(void)
// callers: [lpass_bt_swr_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00103018 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpass_bt_swr_probe, lpass_bt_swr_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00103020 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swr_mclk_enable, lpass_bt_swrm_clock, lpass_bt_swr_runtime_resume, lpass_bt_swr_ssr_enable, lpass_bt_swr_ssr_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103028 size=1
// signature: undefined _dev_err(void)
// callers: [lpass_bt_swr_add_child_devices, lpass_bt_swr_probe, lpass_bt_swr_mclk_enable, lpass_bt_swrm_clock, lpass_bt_swr_runtime_resume, lpass_bt_swr_ssr_enable, lpass_bt_swr_ssr_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_disable @ 00103030 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_disable(void)
// callers: [lpass_bt_swr_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103038 size=1
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
// platform_driver_unregister @ 00103040 size=1
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
// devm_kmalloc @ 00103048 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 00103050 size=1
// signature: undefined __init_rwsem(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103058 size=1
// signature: undefined __mutex_init(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103060 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 00103068 size=1
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103070 size=1
// signature: undefined _dev_info(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00103078 size=1
// signature: undefined devm_clk_get(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 00103080 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00103088 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpass_bt_swr_remove, lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00103090 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030a0 size=1
// signature: undefined queue_work_on(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_register @ 001030a8 size=1
// signature: undefined snd_event_client_register(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_notify @ 001030b0 size=1
// signature: undefined snd_event_notify(void)
// callers: [lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030b8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpass_bt_swr_add_child_devices, lpass_bt_swr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 001030c0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpass_bt_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_depopulate @ 001030c8 size=1
// signature: undefined of_platform_depopulate(void)
// callers: [lpass_bt_swr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_depopulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001030d0 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 001030d8 size=1
// signature: undefined strnstr(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001030e0 size=1
// signature: undefined strscpy(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_alloc @ 001030e8 size=1
// signature: undefined platform_device_alloc(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add_data @ 001030f0 size=1
// signature: undefined platform_device_add_data(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 001030f8 size=1
// signature: undefined krealloc(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_add @ 00103100 size=1
// signature: undefined platform_device_add(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103108 size=1
// signature: undefined _printk(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swr_add_child_devices, lpass_bt_swr_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 00103110 size=1
// signature: undefined platform_device_put(void)
// callers: [lpass_bt_swr_add_child_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00103118 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 00103120 size=1
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: [lpass_bt_swrm_clock, lpass_bt_swr_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_active_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 00103128 size=1
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: [lpass_bt_swrm_clock, lpass_bt_swr_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_cdc_pinctrl_select_sleep_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 00103130 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swr_mclk_enable, lpass_bt_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 00103138 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [lpass_bt_swr_core_vote, lpass_bt_swr_mclk_enable, lpass_bt_swrm_clock]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00103140 size=1
// signature: undefined clk_prepare(void)
// callers: [lpass_bt_swr_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00103148 size=1
// signature: undefined clk_disable(void)
// callers: [lpass_bt_swr_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00103150 size=1
// signature: undefined clk_unprepare(void)
// callers: [lpass_bt_swr_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00103158 size=1
// signature: undefined clk_enable(void)
// callers: [lpass_bt_swr_mclk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swrm_wcd_notify @ 00103160 size=1
// signature: undefined swrm_wcd_notify(void)
// callers: [lpass_bt_swr_ssr_enable, lpass_bt_swr_ssr_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swrm_wcd_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



