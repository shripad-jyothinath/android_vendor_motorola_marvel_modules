// Decompiled by Ghidra 12.2
// Program: swr_ctrl_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// swrm_get_clk_div_rate @ 00101094 size=100
// signature: undefined swrm_get_clk_div_rate(void)
// callers: []
//------------------------------------------------------------

ulong swrm_get_clk_div_rate(ulong param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  if (((param_2 != 0) && (iVar2 = (int)param_1, iVar2 != 0xbb8000)) && (iVar2 != 0xac4400)) {
    if (iVar2 == 9600000) {
      param_1 = 600000;
      if (600000 < (int)param_2) {
        uVar1 = 9600000;
        if (param_2 < 0x493e01) {
          uVar1 = 4800000;
        }
        return (ulong)uVar1;
      }
    }
    else {
      param_1 = (ulong)param_2;
    }
  }
  return param_1;
}



//------------------------------------------------------------
// swrm_register_wake_irq @ 001010fc size=396
// signature: undefined swrm_register_wake_irq(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

undefined4 swrm_register_wake_irq(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x3da0) == 0) {
    uVar2 = of_get_named_gpio_flags
                      (*(undefined8 *)(*(long *)(param_1 + 0x2140) + 0x2e8),"qcom,swr-wakeup-irq",0,
                       0);
    if (uVar2 < 0x200) {
      gpio_to_desc();
      iVar3 = gpiod_to_irq();
      *(int *)(param_1 + 0x23a4) = iVar3;
      if (iVar3 < 0) {
        iVar3 = ___ratelimit(swrm_register_wake_irq__rs,"swrm_register_wake_irq");
        if (iVar3 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x2140),"Unable to configure irq\n");
        }
        return *(undefined4 *)(param_1 + 0x23a4);
      }
    }
    else {
      iVar3 = platform_get_irq_byname(*(undefined8 *)(param_1 + 0x3bf0),"swr_wake_irq");
      if (iVar3 < 0) {
        iVar3 = ___ratelimit(swrm_register_wake_irq__rs_3,"swrm_register_wake_irq");
        if (iVar3 == 0) {
          return 0xffffffea;
        }
        _dev_err(*(undefined8 *)(param_1 + 0x2140),"TLMM connect gpio not found\n");
        return 0xffffffea;
      }
      *(int *)(param_1 + 0x23a4) = iVar3;
    }
    lVar1 = param_1 + 0x22e0;
    mutex_lock(lVar1);
    iVar3 = request_threaded_irq
                      (*(undefined4 *)(param_1 + 0x23a4),0,swrm_wakeup_interrupt,0x2004,
                       "swr_wake_irq",param_1);
    if (iVar3 != 0) {
      iVar4 = ___ratelimit(swrm_register_wake_irq__rs_5,"swrm_register_wake_irq");
      if (iVar4 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: Failed to request irq %d\n",
                 "swrm_register_wake_irq",iVar3);
      }
      mutex_unlock(lVar1);
      return 0xffffffea;
    }
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0x23a4),1);
    mutex_unlock(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// swrm_wakeup_interrupt @ 0010128c size=644
// signature: undefined swrm_wakeup_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_wakeup_interrupt(undefined8 param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined *puVar6;
  
  if ((param_2 == 0) || (*(long *)(param_2 + 0x2140) == 0)) {
    uVar4 = ___ratelimit(swrm_wakeup_interrupt__rs,"swrm_wakeup_interrupt");
    if ((int)uVar4 == 0) {
      return uVar4;
    }
    puVar6 = &DAT_0010bc54;
LAB_001013f0:
    _printk(puVar6,"swrm_wakeup_interrupt");
    uVar4 = 0;
  }
  else {
    lVar3 = param_2 + 0x2220;
    mutex_lock(lVar3);
    if ((*(int *)(param_2 + 0x3be8) == 4) || (*(char *)(param_2 + 0x3da4) == '\0')) {
      if (0 < *(int *)(param_2 + 0x23a4)) {
        lVar5 = irq_get_irq_data();
        if (lVar5 == 0) {
          iVar1 = ___ratelimit(swrm_wakeup_interrupt__rs_31,"swrm_wakeup_interrupt");
          if (iVar1 != 0) {
            _printk(&DAT_0010c684,"swrm_wakeup_interrupt");
          }
          mutex_unlock(lVar3);
          return 0;
        }
        mutex_lock(param_2 + 0x22e0);
        lVar5 = irq_get_irq_data(*(undefined4 *)(param_2 + 0x23a4));
        if ((*(byte *)(*(long *)(lVar5 + 0x10) + 2) & 1) == 0) {
          irq_set_irq_wake(*(undefined4 *)(param_2 + 0x23a4),0);
          disable_irq_nosync(*(undefined4 *)(param_2 + 0x23a4));
        }
        mutex_unlock(param_2 + 0x22e0);
      }
      mutex_unlock(lVar3);
    }
    else {
      mutex_unlock(lVar3);
      uVar2 = swrm_lock_sleep(param_2);
      if ((uVar2 & 1) == 0) {
        iVar1 = ___ratelimit(swrm_wakeup_interrupt__rs_33,"swrm_wakeup_interrupt");
        if (iVar1 != 0) {
          _dev_err(*(undefined8 *)(param_2 + 0x2140),"%s Failed to hold suspend\n",
                   "swrm_wakeup_interrupt");
        }
      }
      else {
        if (0 < *(int *)(param_2 + 0x23a4)) {
          lVar3 = irq_get_irq_data();
          if (lVar3 == 0) {
            uVar4 = ___ratelimit(swrm_wakeup_interrupt__rs_35,"swrm_wakeup_interrupt");
            if ((int)uVar4 == 0) {
              return uVar4;
            }
            puVar6 = &DAT_0010c684;
            goto LAB_001013f0;
          }
          mutex_lock(param_2 + 0x22e0);
          lVar3 = irq_get_irq_data(*(undefined4 *)(param_2 + 0x23a4));
          if ((*(byte *)(*(long *)(lVar3 + 0x10) + 2) & 1) == 0) {
            irq_set_irq_wake(*(undefined4 *)(param_2 + 0x23a4),0);
            disable_irq_nosync(*(undefined4 *)(param_2 + 0x23a4));
          }
          mutex_unlock(param_2 + 0x22e0);
        }
        __pm_runtime_resume(*(undefined8 *)(param_2 + 0x2140),4);
        lVar3 = *(long *)(param_2 + 0x2140);
        uVar4 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar3 + 0x220) = uVar4;
        __pm_runtime_suspend(*(undefined8 *)(param_2 + 0x2140),0xd);
        mutex_lock(param_2 + 0x22b0);
        iVar1 = *(int *)(param_2 + 0x3df8) + -1;
        *(int *)(param_2 + 0x3df8) = iVar1;
        if (iVar1 == 0) {
          if (*(int *)(param_2 + 0x3dd8) == 1) {
            *(undefined4 *)(param_2 + 0x3dd8) = 0;
          }
          cpu_latency_qos_update_request(param_2 + 0x3da8,0xffffffff);
          pm_relax(*(undefined8 *)(param_2 + 0x2140));
        }
        mutex_unlock(param_2 + 0x22b0);
        __wake_up(param_2 + 0x3de0,3,0,0);
      }
    }
    uVar4 = 1;
  }
  return uVar4;
}



//------------------------------------------------------------
// swrm_wcd_notify @ 00101514 size=1852
// signature: undefined swrm_wcd_notify(void)
// callers: []
//------------------------------------------------------------

int swrm_wcd_notify(long param_1,int param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 uVar8;
  long lVar9;
  long *plVar10;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(swrm_wcd_notify__rs,"swrm_wcd_notify");
    if (iVar2 == 0) {
      return -0x16;
    }
    _printk(&DAT_0010c5f4,"swrm_wcd_notify");
    return -0x16;
  }
  lVar9 = *(long *)(param_1 + 0xa8);
  if (lVar9 == 0) {
    iVar2 = ___ratelimit(swrm_wcd_notify__rs_8,"swrm_wcd_notify");
    if (iVar2 == 0) {
      return -0x16;
    }
    param_1 = param_1 + 0x10;
    pcVar7 = "%s: swrm is NULL\n";
    goto LAB_00101a90;
  }
  if (0xb < param_2 - 1U) {
switchD_00101578_caseD_3:
    iVar2 = ___ratelimit(swrm_wcd_notify__rs_28,"swrm_wcd_notify");
    if (iVar2 == 0) {
      return 0;
    }
    _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: swr master unknown id %d\n","swrm_wcd_notify",
             param_2);
    return 0;
  }
  switch(param_2) {
  case 1:
    mutex_lock(lVar9 + 0x2250);
    if (*(int *)(lVar9 + 0x3be8) != 3) {
      swrm_device_down(param_1 + 0x10);
    }
    break;
  case 2:
    mutex_lock(lVar9 + 0x2220);
    cVar1 = *(char *)(lVar9 + 0x3da4);
    mutex_unlock(lVar9 + 0x2220);
    if (cVar1 == '\0') {
      return -0x10;
    }
    mutex_lock(lVar9 + 0x2250);
    uVar6 = ktime_get_mono_fast_ns();
    *(undefined8 *)(param_1 + 0x230) = uVar6;
    __pm_runtime_resume(param_1 + 0x10,4);
    mutex_lock(lVar9 + 0x2280);
    plVar10 = *(long **)(lVar9 + 0x3d8);
    if (plVar10 == (long *)(lVar9 + 0x3d8)) {
      iVar2 = 0;
    }
    else {
      do {
        iVar2 = swr_reset_device(plVar10 + -6);
        if (iVar2 == -0x13 || iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar3 = ___ratelimit(swrm_wcd_notify__rs_16,"swrm_wcd_notify");
          if (iVar3 != 0) {
            _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: failed to reset swr device %d\n",
                     "swrm_wcd_notify",(char)plVar10[2]);
          }
          swrm_clk_request(lVar9,0);
        }
        plVar10 = (long *)*plVar10;
      } while (plVar10 != (long *)(lVar9 + 0x3d8));
    }
    uVar6 = ktime_get_mono_fast_ns();
    *(undefined8 *)(param_1 + 0x230) = uVar6;
    __pm_runtime_suspend(param_1 + 0x10,0xd);
    mutex_unlock(lVar9 + 0x2280);
    mutex_unlock(lVar9 + 0x2250);
    return iVar2;
  case 3:
    goto switchD_00101578_caseD_3;
  case 4:
    if (param_3 != (int *)0x0) {
      mutex_lock(lVar9 + 0x2250);
      iVar2 = *param_3;
      *(int *)(lVar9 + 0x3bf8) = iVar2;
      if ((iVar2 < 2) || (*(char *)(lVar9 + 0x3bfc) != '\0')) {
        plVar10 = *(long **)(lVar9 + 0x3d8);
        if (plVar10 != (long *)(lVar9 + 0x3d8)) {
          do {
            iVar2 = swr_set_device_group(plVar10 + -6,0);
            if ((iVar2 != 0) &&
               (iVar3 = ___ratelimit(swrm_wcd_notify__rs_21,"swrm_wcd_notify"), iVar3 != 0)) {
              _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: set num ch failed\n","swrm_wcd_notify");
            }
            plVar10 = (long *)*plVar10;
          } while (plVar10 != (long *)(lVar9 + 0x3d8));
          goto LAB_00101c28;
        }
      }
      else {
        plVar10 = *(long **)(lVar9 + 0x3d8);
        if (plVar10 != (long *)(lVar9 + 0x3d8)) {
          do {
            iVar2 = swr_set_device_group(plVar10 + -6,0xf);
            if ((iVar2 != 0) &&
               (iVar3 = ___ratelimit(swrm_wcd_notify__rs_19,"swrm_wcd_notify"), iVar3 != 0)) {
              _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: set num ch failed\n","swrm_wcd_notify");
            }
            plVar10 = (long *)*plVar10;
          } while (plVar10 != (long *)(lVar9 + 0x3d8));
          goto LAB_00101c28;
        }
      }
      iVar2 = 0;
LAB_00101c28:
      mutex_unlock(lVar9 + 0x2250);
      return iVar2;
    }
    puVar5 = swrm_wcd_notify__rs_18;
LAB_00101ac0:
    iVar2 = ___ratelimit(puVar5,"swrm_wcd_notify");
    if (iVar2 == 0) {
      return -0x16;
    }
    param_1 = *(long *)(lVar9 + 0x2140);
    pcVar7 = "%s: data is NULL\n";
LAB_00101a90:
    _dev_err(param_1,pcVar7,"swrm_wcd_notify");
    return -0x16;
  case 5:
    if (param_3 == (int *)0x0) {
      puVar5 = swrm_wcd_notify__rs_12;
      goto LAB_00101ac0;
    }
    mutex_lock(lVar9 + 0x2250);
    iVar3 = *(int *)(lVar9 + 0x23b0);
    iVar2 = *param_3;
    if (iVar3 != iVar2) {
      if (*(int *)(lVar9 + 0x3be8) != 3) {
        *(int *)(lVar9 + 0x23b0) = iVar2;
        *(int *)(lVar9 + 0x23b4) = iVar2;
        swrm_switch_frame_shape(lVar9);
        swrm_device_suspend(param_1 + 0x10);
      }
      usleep_range_state(10000,0x2904,2);
      iVar3 = *param_3;
    }
    *(int *)(lVar9 + 0x23b0) = iVar3;
    *(int *)(lVar9 + 0x23b4) = iVar3;
    break;
  case 6:
    mutex_lock(lVar9 + 0x2250);
    lVar4 = lVar9 + 0x2220;
    mutex_lock(lVar4);
    *(undefined1 *)(lVar9 + 0x3da4) = 0;
    mutex_unlock(lVar4);
    if (*(int *)(lVar9 + 0x3be8) != 3) {
      swrm_device_down(param_1 + 0x10);
    }
    mutex_lock(lVar4);
    if (*(int *)(lVar9 + 0x3e20) != 0) {
      digital_cdc_rsc_mgr_hw_vote_disable
                (*(undefined8 *)(lVar9 + 0x3e08),*(undefined8 *)(lVar9 + 0x2140));
    }
    *(undefined4 *)(lVar9 + 0x3e20) = 0;
    if (*(int *)(lVar9 + 0x3e24) != 0) {
      digital_cdc_rsc_mgr_hw_vote_disable
                (*(undefined8 *)(lVar9 + 0x3e10),*(undefined8 *)(lVar9 + 0x2140));
    }
    *(undefined4 *)(lVar9 + 0x3e24) = 0;
    mutex_unlock(lVar4);
    mutex_lock(lVar9 + 0x2280);
    *(undefined4 *)(lVar9 + 0x3be8) = 4;
    mutex_unlock(lVar9 + 0x2280);
    break;
  case 7:
    *(undefined4 *)(lVar9 + 0x2160) = 0;
    if (((*(int *)(lVar9 + 0x2158) != 0) &&
        (lVar4 = wait_for_completion_timeout(lVar9 + 0x2160,0x7d), lVar4 == 0)) &&
       (iVar2 = ___ratelimit(swrm_wcd_notify__rs_14,"swrm_wcd_notify"), iVar2 != 0)) {
      _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: clock voting not zero\n","swrm_wcd_notify");
    }
    if ((*(int *)(lVar9 + 0x3be8) == 2) ||
       (lVar4 = pm_runtime_autosuspend_expiration(*(undefined8 *)(lVar9 + 0x2140)), lVar4 != 0)) {
      *(undefined4 *)(lVar9 + 0x3be8) = 5;
      pm_runtime_set_autosuspend_delay(*(undefined8 *)(lVar9 + 0x2140),1);
      usleep_range_state(50000,0xc3b4,2);
      *(undefined4 *)(lVar9 + 0x3be8) = 4;
    }
    lVar4 = lVar9 + 0x2220;
    mutex_lock(lVar4);
    *(undefined1 *)(lVar9 + 0x3da4) = 1;
    goto LAB_00101a58;
  case 8:
    if (param_3 != (int *)0x0) {
      mutex_lock(lVar9 + 0x2250);
      *(int *)(lVar9 + 0x3da0) = *param_3;
      iVar2 = swrm_register_wake_irq(lVar9);
      if ((iVar2 != 0) &&
         (iVar3 = ___ratelimit(swrm_wcd_notify__rs_24,"swrm_wcd_notify"), iVar3 != 0)) {
        _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: register wake_irq failed\n","swrm_wcd_notify")
        ;
      }
      goto LAB_00101c28;
    }
    iVar2 = ___ratelimit(swrm_wcd_notify__rs_22,"swrm_wcd_notify");
    if (iVar2 == 0) {
      return -0x16;
    }
    param_1 = *(long *)(lVar9 + 0x2140);
    pcVar7 = "%s: reg wake irq data is NULL\n";
    goto LAB_00101a90;
  case 9:
    if (param_3 != (int *)0x0) {
      mutex_lock(lVar9 + 0x2250);
      if (*param_3 == 0) {
        iVar2 = -0x16;
      }
      else {
        iVar2 = swrm_alloc_port_mem(param_1 + 0x10,lVar9,param_3[1]);
        if (iVar2 == 0) {
          swrm_copy_port_config(lVar9,param_3,*param_3);
        }
      }
      mutex_unlock(lVar9 + 0x2250);
      return iVar2;
    }
    iVar2 = ___ratelimit(swrm_wcd_notify__rs_26,"swrm_wcd_notify");
    if (iVar2 == 0) {
      return -0x16;
    }
    uVar6 = *(undefined8 *)(lVar9 + 0x2140);
    pcVar7 = "%s: data is NULL for id=%d\n";
    uVar8 = 9;
LAB_00101b6c:
    _dev_err(uVar6,pcVar7,"swrm_wcd_notify",uVar8);
    return -0x16;
  case 10:
    if (param_3 == (int *)0x0) {
      iVar2 = ___ratelimit(swrm_wcd_notify__rs_10,"swrm_wcd_notify");
      if (iVar2 == 0) {
        return -0x16;
      }
      uVar6 = *(undefined8 *)(lVar9 + 0x2140);
      pcVar7 = "%s: data is NULL for id:%d\n";
      uVar8 = 10;
      goto LAB_00101b6c;
    }
    mutex_lock(lVar9 + 0x2250);
    if (*(int *)(lVar9 + 0x3e28) != *param_3) {
      if (*(int *)(lVar9 + 0x3be8) == 2) {
        *(undefined1 *)(lVar9 + 0x3da6) = 1;
        swrm_device_suspend(param_1 + 0x10);
        if (*(int *)(lVar9 + 0x3be8) == 2) {
          *(undefined1 *)(lVar9 + 0x3da6) = 0;
        }
      }
      *(int *)(lVar9 + 0x3e28) = *param_3;
    }
    break;
  default:
    goto switchD_00101578_caseD_b;
  }
  lVar4 = lVar9 + 0x2250;
LAB_00101a58:
  mutex_unlock(lVar4);
switchD_00101578_caseD_b:
  return 0;
}



//------------------------------------------------------------
// swrm_device_suspend @ 00101c50 size=104
// signature: undefined swrm_device_suspend(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

void swrm_device_suspend(long param_1)

{
  int iVar1;
  
  if ((((*(ushort *)(param_1 + 0x200) & 7) != 0) || (*(int *)(param_1 + 0x20c) != 2)) &&
     (iVar1 = swrm_runtime_suspend(param_1), iVar1 == 0)) {
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    pm_runtime_enable(param_1);
  }
  return;
}



//------------------------------------------------------------
// swrm_switch_frame_shape @ 00101cb8 size=248
// signature: undefined swrm_switch_frame_shape(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

void swrm_switch_frame_shape(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (param_2 == 0xac4400) {
    iVar4 = 0xe5b;
    iVar5 = 0x10;
    iVar7 = 0x40;
    uVar3 = 7;
    iVar6 = 3;
  }
  else if (param_2 == 0xbb8000) {
    uVar3 = 0;
    iVar4 = 4000;
    iVar5 = 2;
    iVar7 = 0x40;
    iVar6 = 3;
  }
  else {
    uVar3 = 0;
    iVar4 = 4000;
    iVar5 = 2;
    iVar7 = 0x32;
    iVar6 = 1;
  }
  uVar1 = swr_master_read(param_1,0x104c);
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar4 = iVar5 * iVar7 * iVar4;
    uVar2 = 0;
    if (iVar4 != 0) {
      uVar2 = (*(int *)(param_1 + 0x23b4) << 1) / iVar4;
    }
    uVar2 = (uVar2 & 0xff) * 0x10000 - 0x10000;
  }
  uVar3 = uVar3 | iVar6 << 3;
  swr_master_write(param_1,(uVar1 & 1) << 6 ^ 0x105c,uVar3 | uVar2);
  swrm_cmd_fifo_wr_cmd(param_1,uVar3,0xf,0xf,(uVar1 & 1) << 4 ^ 0x70);
  return;
}



//------------------------------------------------------------
// swrm_device_down @ 00101db0 size=148
// signature: undefined swrm_device_down(void)
// callers: [swrm_notify_work_fn, swrm_wcd_notify]
//------------------------------------------------------------

void swrm_device_down(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x3c00;
  mutex_lock(lVar1);
  *(undefined4 *)(lVar3 + 0x3be8) = 4;
  mutex_unlock(lVar1);
  if ((((*(ushort *)(param_1 + 0x200) & 7) != 0) || (*(int *)(param_1 + 0x20c) != 2)) &&
     (iVar2 = swrm_runtime_suspend(param_1), iVar2 == 0)) {
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    pm_runtime_enable(param_1);
  }
  return;
}



//------------------------------------------------------------
// swrm_clk_request @ 00101e44 size=612
// signature: undefined swrm_clk_request(void)
// callers: [swrm_runtime_resume, swrm_runtime_suspend, swr_master_write, swrm_wcd_notify, swrm_probe, swr_mstr_interrupt, swr_master_read]
//------------------------------------------------------------

int swrm_clk_request(long param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if ((*(long *)(param_1 + 0x2388) == 0) || (*(long *)(param_1 + 0x2368) == 0)) {
    return -0x16;
  }
  mutex_lock(param_1 + 0x21c0);
  if ((param_2 & 1) == 0) {
    iVar1 = *(int *)(param_1 + 0x2158) + -1;
    *(int *)(param_1 + 0x2158) = iVar1;
    if (iVar1 == 0) {
      if (*(int *)(*(code **)(param_1 + 0x2388) + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101f58);
        (*pcVar3)();
      }
      (**(code **)(param_1 + 0x2388))(*(undefined8 *)(param_1 + 0x2368),0);
      complete(param_1 + 0x2160);
    }
    iVar1 = 0;
  }
  else {
    if (*(char *)(param_1 + 0x3da4) == '\0') {
      iVar1 = -0x13;
      goto LAB_00102004;
    }
    if ((*(int *)(param_1 + 0x23a8) < 0x1050002) &&
       (pcVar3 = *(code **)(param_1 + 0x2390), pcVar3 != (code *)0x0)) {
      if (*(int *)(pcVar3 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101ecc);
        (*pcVar3)();
      }
      iVar1 = (*pcVar3)(*(undefined8 *)(param_1 + 0x2368),1);
      if (iVar1 != 0) {
        iVar2 = ___ratelimit(swrm_clk_request__rs,"swrm_clk_request");
        if (iVar2 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: core vote request failed\n",
                   "swrm_clk_request");
        }
        if (*(int *)(*(code **)(param_1 + 0x2390) + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101f14);
          (*pcVar3)();
        }
        (**(code **)(param_1 + 0x2390))(*(undefined8 *)(param_1 + 0x2368),0);
        goto LAB_00102004;
      }
      if (*(int *)(*(code **)(param_1 + 0x2390) + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102048);
        (*pcVar3)();
      }
      iVar1 = (**(code **)(param_1 + 0x2390))(*(undefined8 *)(param_1 + 0x2368),0);
    }
    else {
      iVar1 = 0;
    }
    iVar2 = *(int *)(param_1 + 0x2158);
    *(int *)(param_1 + 0x2158) = iVar2 + 1;
    if (iVar2 == 0) {
      if (*(int *)(*(code **)(param_1 + 0x2388) + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101fa8);
        (*pcVar3)();
      }
      iVar1 = (**(code **)(param_1 + 0x2388))(*(undefined8 *)(param_1 + 0x2368),1);
      if (iVar1 != 0) {
        iVar2 = ___ratelimit(swrm_clk_request__rs_56,"swrm_clk_request");
        if (iVar2 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: clock enable req failed",
                   "swrm_clk_request");
        }
        *(int *)(param_1 + 0x2158) = *(int *)(param_1 + 0x2158) + -1;
      }
    }
  }
  if (*(int *)(param_1 + 0x2158) < 0) {
    iVar2 = ___ratelimit(swrm_clk_request__rs_58,"swrm_clk_request");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: swrm clk count mismatch\n","swrm_clk_request")
      ;
    }
    *(undefined4 *)(param_1 + 0x2158) = 0;
  }
LAB_00102004:
  mutex_unlock(param_1 + 0x21c0);
  return iVar1;
}



//------------------------------------------------------------
// swrm_alloc_port_mem @ 001020a8 size=212
// signature: undefined swrm_alloc_port_mem(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

undefined8 swrm_alloc_port_mem(undefined8 param_1,long param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x3e00);
  if (lVar3 == 0) {
    lVar3 = devm_kmalloc(param_1,0x20,0xdc0);
    *(long *)(param_2 + 0x3e00) = lVar3;
    if (lVar3 != 0) goto LAB_001020f0;
LAB_00102164:
    uVar2 = 0xfffffff4;
  }
  else {
LAB_001020f0:
    if (*(long *)(lVar3 + (ulong)param_3 * 8) == 0) {
      uVar2 = devm_kmalloc(param_1,(ulong)param_4 * 0xc,0xdc0);
      *(undefined8 *)(*(long *)(param_2 + 0x3e00) + (ulong)param_3 * 8) = uVar2;
      if (*(long *)(*(long *)(param_2 + 0x3e00) + (ulong)param_3 * 8) == 0) goto LAB_00102164;
    }
    else {
      iVar1 = ___ratelimit(swrm_alloc_port_mem__rs,"swrm_alloc_port_mem");
      if (iVar1 != 0) {
        _dev_err(*(undefined8 *)(param_2 + 0x2140),"%s: called more than once\n",
                 "swrm_alloc_port_mem");
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// swrm_copy_port_config @ 0010217c size=164
// signature: undefined swrm_copy_port_config(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

void swrm_copy_port_config(long param_1,long param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  if (param_3 != 0) {
    iVar2 = 0;
    iVar1 = *(int *)(param_2 + 4);
    do {
      puVar3 = (undefined8 *)(*(long *)(param_2 + 8) + (long)iVar2 * 0xc);
      if (puVar3 == (undefined8 *)0x0) {
        iVar2 = ___ratelimit(swrm_copy_port_config__rs,"swrm_copy_port_config");
        if (iVar2 == 0) {
          return;
        }
        _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: Invalid params\n","swrm_copy_port_config");
        return;
      }
      uVar4 = *puVar3;
      puVar5 = (undefined8 *)
               (*(long *)(*(long *)(param_1 + 0x3e00) + (long)iVar1 * 8) + (long)iVar2 * 0xc);
      iVar2 = iVar2 + 1;
      *(undefined4 *)(puVar5 + 1) = *(undefined4 *)(puVar3 + 1);
      *puVar5 = uVar4;
    } while (param_3 != iVar2);
  }
  return;
}



//------------------------------------------------------------
// swrm_lock_sleep @ 00102220 size=536
// signature: undefined swrm_lock_sleep(void)
// callers: [swrm_wakeup_work, swrm_device_wakeup_vote, swrm_wakeup_interrupt, swr_mstr_interrupt]
//------------------------------------------------------------

undefined8 swrm_lock_sleep(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x22b0;
  local_48 = *(long *)(lVar5 + 0x638);
  mutex_lock(lVar1);
  iVar3 = *(int *)(param_1 + 0x3df8);
  *(int *)(param_1 + 0x3df8) = iVar3 + 1;
  if (iVar3 == 0) {
    cpu_latency_qos_update_request(param_1 + 0x3da8,10);
    pm_stay_awake(*(undefined8 *)(param_1 + 0x2140));
  }
  mutex_unlock(lVar1);
  if (param_1 != 0) {
    mutex_lock(lVar1);
    iVar3 = *(int *)(param_1 + 0x3dd8);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x3dd8) = 1;
      mutex_unlock(lVar1);
    }
    else {
      mutex_unlock(lVar1);
      if (iVar3 != 1) {
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_70 = 0;
        init_wait_entry(&local_70,0);
        lVar5 = 0xaf;
        while( true ) {
          prepare_to_wait_event(param_1 + 0x3de0,&local_70,2);
          mutex_lock(lVar1);
          uVar2 = *(uint *)(param_1 + 0x3dd8);
          if (uVar2 == 0) {
            *(undefined4 *)(param_1 + 0x3dd8) = 1;
          }
          mutex_unlock(lVar1);
          if (lVar5 == 0 && uVar2 < 2) {
            lVar5 = 1;
          }
          if ((uVar2 < 2) || (lVar5 == 0)) break;
          lVar5 = schedule_timeout(lVar5);
        }
        finish_wait(param_1 + 0x3de0,&local_70);
        if (lVar5 == 0) {
          iVar3 = ___ratelimit(swrm_lock_sleep__rs,"swrm_lock_sleep");
          if (iVar3 != 0) {
            _dev_err(*(undefined8 *)(param_1 + 0x2140),
                     "%s: system didn\'t resume within %dms, s %d, w %d\n","swrm_lock_sleep",700,
                     *(undefined4 *)(param_1 + 0x3dd8),*(undefined4 *)(param_1 + 0x3df8));
          }
          mutex_lock(lVar1);
          iVar3 = *(int *)(param_1 + 0x3df8) + -1;
          *(int *)(param_1 + 0x3df8) = iVar3;
          if (iVar3 == 0) {
            if (*(int *)(param_1 + 0x3dd8) == 1) {
              *(undefined4 *)(param_1 + 0x3dd8) = 0;
            }
            cpu_latency_qos_update_request(param_1 + 0x3da8,0xffffffff);
            pm_relax(*(undefined8 *)(param_1 + 0x2140));
          }
          mutex_unlock(lVar1);
          uVar4 = 0;
          goto LAB_0010235c;
        }
      }
    }
  }
  uVar4 = 1;
LAB_0010235c:
  __wake_up(param_1 + 0x3de0,3,0,0);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// swrm_runtime_suspend @ 0010243c size=1236
// signature: undefined swrm_runtime_suspend(void)
// callers: [swrm_device_suspend, swrm_device_down, swrm_suspend]
//------------------------------------------------------------

int swrm_runtime_suspend(long param_1)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  
  lVar9 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar9 + 0x3be8) == 5) {
    *(undefined4 *)(lVar9 + 0x3be8) = 4;
    return 0;
  }
  mutex_lock(lVar9 + 0x2310);
  lVar1 = lVar9 + 0x2280;
  mutex_lock(lVar1);
  mutex_lock(lVar9 + 0x3c00);
  iVar7 = *(int *)(lVar9 + 0x3be8);
  mutex_unlock(lVar9 + 0x3c00);
  iVar4 = swrm_request_hw_vote(lVar9,0,1);
  if ((iVar4 == 0) ||
     (iVar5 = ___ratelimit(swrm_runtime_suspend__rs,"swrm_runtime_suspend"), iVar5 == 0)) {
    if (*(int *)(lVar9 + 0x3e44) != 0) goto LAB_001024f4;
LAB_00102538:
    bVar3 = false;
    if (iVar7 == 4) goto LAB_00102564;
LAB_00102544:
    if (iVar7 != 2) goto LAB_001027ac;
    if (*(char *)(lVar9 + 0x20d9) == '\0') goto LAB_00102564;
    iVar5 = -0x10;
  }
  else {
    _dev_err(param_1,"%s:lpass core hw enable failed\n","swrm_runtime_suspend");
    if (*(int *)(lVar9 + 0x3e44) == 0) goto LAB_00102538;
LAB_001024f4:
    iVar5 = swrm_request_hw_vote(lVar9,1,1);
    bVar3 = iVar5 != 0;
    if (iVar7 != 4) goto LAB_00102544;
LAB_00102564:
    if ((*(int *)(lVar9 + 0x3d68) == 0) || (*(int *)(lVar9 + 0x3be8) == 4)) {
      iVar5 = ___ratelimit(swrm_runtime_suspend__rs_38,"swrm_runtime_suspend");
      if (iVar5 != 0) {
        _dev_err(param_1,"%s: clk stop mode not supported or SSR entry\n","swrm_runtime_suspend");
      }
      if (*(int *)(lVar9 + 0x3be8) != 4) {
        mutex_unlock(lVar1);
        if (*(int *)(lVar9 + 0x235c) != 5) {
          swrm_cmd_fifo_wr_cmd(lVar9,8,0xf,0xf,0x60);
        }
        mutex_lock(lVar1);
        if (2 < *(uint *)(lVar9 + 0x23ac)) goto LAB_0010290c;
        lVar8 = (ulong)*(uint *)(lVar9 + 0x23ac) * 4;
        swr_master_write(lVar9,*(undefined4 *)(swrm_registers + lVar8 + 0xc),
                         *(undefined4 *)(swrm_registers + lVar8 + 0x6c));
        uVar6 = swr_master_read(lVar9,0x1048);
        swr_master_write(lVar9,0x1048,uVar6 | 2);
        swr_master_write(lVar9,4,0);
        for (plVar10 = *(long **)(lVar9 + 0x3d8); plVar10 != (long *)(lVar9 + 0x3d8);
            plVar10 = (long *)*plVar10) {
          iVar5 = swr_device_down(plVar10 + -6);
          if (iVar5 != -0x13 && iVar5 != 0) {
            iVar7 = ___ratelimit(swrm_runtime_suspend__rs_40,"swrm_runtime_suspend");
            if (iVar7 != 0) {
              _dev_err(param_1,"%s: failed to shutdown swr dev %d\n","swrm_runtime_suspend",
                       *(undefined1 *)(plVar10 + 2));
            }
            goto LAB_001027b8;
          }
        }
      }
    }
    else {
      *(uint *)(lVar9 + 0x3dfc) = *(uint *)(lVar9 + 0x3dfc) & 0xfffffff7;
      if (2 < *(uint *)(lVar9 + 0x23ac)) {
LAB_0010290c:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102910);
        (*pcVar2)();
      }
      swr_master_write(lVar9,*(undefined4 *)
                              (swrm_registers + (ulong)*(uint *)(lVar9 + 0x23ac) * 4 + 0xc));
      mutex_unlock(lVar1);
      swrm_cmd_fifo_wr_cmd(lVar9,2,0xf,0xf,0x44);
      mutex_lock(lVar1);
      usleep_range_state(100,0x69,2);
    }
    swrm_check_link_status(lVar9,0);
    iVar5 = swrm_clk_request(lVar9,0);
    if (iVar5 == 0) {
      if (*(int *)(lVar9 + 0x3d68) != 0) {
        if (*(int *)(lVar9 + 0x23a4) < 1) {
          if (*(int *)(lVar9 + 0x3da0) != 0) {
            iVar5 = ___ratelimit(swrm_runtime_suspend__rs_44,"swrm_runtime_suspend");
            if (iVar5 != 0) {
              _dev_err(param_1,"%s:notifications disabled\n","swrm_runtime_suspend");
            }
            *(undefined1 *)(lVar9 + 0x3da5) = 0;
          }
        }
        else {
          lVar8 = irq_get_irq_data();
          mutex_lock(lVar9 + 0x22e0);
          if ((lVar8 != 0) && ((*(byte *)(*(long *)(lVar8 + 0x10) + 2) & 1) != 0)) {
            irq_set_irq_wake(*(undefined4 *)(lVar9 + 0x23a4),1);
            enable_irq(*(undefined4 *)(lVar9 + 0x23a4));
          }
          mutex_unlock(lVar9 + 0x22e0);
        }
      }
      if (iVar7 == 4) goto LAB_001027a4;
LAB_001027ac:
      iVar5 = 0;
      *(undefined4 *)(lVar9 + 0x3be8) = 3;
    }
    else {
      iVar7 = ___ratelimit(swrm_runtime_suspend__rs_42,"swrm_runtime_suspend");
      if (iVar7 == 0) {
LAB_001027a4:
        iVar5 = 0;
      }
      else {
        _dev_err(param_1,"%s: swrmn clk failed\n","swrm_runtime_suspend");
        iVar5 = 0;
      }
    }
  }
LAB_001027b8:
  if (*(int *)(lVar9 + 0x3e44) == 0) {
    if (*(int *)(lVar9 + 0x3be8) == 2) goto joined_r0x0010281c;
  }
  else if (bVar3) goto joined_r0x0010281c;
  mutex_lock(lVar9 + 0x2220);
  if (*(long *)(lVar9 + 0x3e10) != 0) {
    iVar7 = *(int *)(lVar9 + 0x3e24) + -1;
    *(int *)(lVar9 + 0x3e24) = iVar7;
    if (iVar7 < 0) {
      *(undefined4 *)(lVar9 + 0x3e24) = 0;
    }
    else if (iVar7 == 0) {
      digital_cdc_rsc_mgr_hw_vote_disable(*(long *)(lVar9 + 0x3e10),*(undefined8 *)(lVar9 + 0x2140))
      ;
    }
  }
  mutex_unlock(lVar9 + 0x2220);
joined_r0x0010281c:
  if (iVar4 == 0) {
    mutex_lock(lVar9 + 0x2220);
    if (*(long *)(lVar9 + 0x3e08) != 0) {
      iVar7 = *(int *)(lVar9 + 0x3e20) + -1;
      *(int *)(lVar9 + 0x3e20) = iVar7;
      if (iVar7 < 0) {
        *(undefined4 *)(lVar9 + 0x3e20) = 0;
      }
      else if (iVar7 == 0) {
        digital_cdc_rsc_mgr_hw_vote_disable
                  (*(long *)(lVar9 + 0x3e08),*(undefined8 *)(lVar9 + 0x2140));
      }
    }
    mutex_unlock(lVar9 + 0x2220);
  }
  mutex_unlock(lVar1);
  mutex_unlock(lVar9 + 0x2310);
  return iVar5;
}



//------------------------------------------------------------
// swrm_request_hw_vote @ 00102910 size=420
// signature: undefined swrm_request_hw_vote(void)
// callers: [swrm_runtime_resume, swrm_device_wakeup_vote, swrm_runtime_suspend, swrm_probe, swr_mstr_interrupt]
//------------------------------------------------------------

int swrm_request_hw_vote(long param_1,int param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  mutex_lock(param_1 + 0x2220);
  if (param_2 == 1) {
    lVar3 = *(long *)(param_1 + 0x3e10);
    if (lVar3 != 0) {
      if ((param_3 & 1) == 0) {
        iVar1 = *(int *)(param_1 + 0x3e24) + -1;
        *(int *)(param_1 + 0x3e24) = iVar1;
        if (iVar1 < 0) {
          iVar1 = 0;
          *(undefined4 *)(param_1 + 0x3e24) = 0;
          goto LAB_00102a48;
        }
        goto LAB_00102a38;
      }
      if (*(char *)(param_1 + 0x3da4) == '\0') goto LAB_00102a68;
      iVar1 = *(int *)(param_1 + 0x3e24);
      *(int *)(param_1 + 0x3e24) = iVar1 + 1;
      if (iVar1 == 0) {
        iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(lVar3,*(undefined8 *)(param_1 + 0x2140));
        if (iVar1 < 0) {
          iVar2 = ___ratelimit(swrm_request_hw_vote__rs_46,"swrm_request_hw_vote");
          if (iVar2 != 0) {
            _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s:lpass audio hw enable failed\n",
                     "swrm_request_hw_vote");
          }
          *(int *)(param_1 + 0x3e24) = *(int *)(param_1 + 0x3e24) + -1;
        }
        goto LAB_00102a48;
      }
    }
  }
  else if ((param_2 == 0) && (lVar3 = *(long *)(param_1 + 0x3e08), lVar3 != 0)) {
    if ((param_3 & 1) == 0) {
      iVar1 = *(int *)(param_1 + 0x3e20) + -1;
      *(int *)(param_1 + 0x3e20) = iVar1;
      if (iVar1 < 0) {
        iVar1 = 0;
        *(undefined4 *)(param_1 + 0x3e20) = 0;
        goto LAB_00102a48;
      }
LAB_00102a38:
      if (iVar1 == 0) {
        digital_cdc_rsc_mgr_hw_vote_disable(lVar3,*(undefined8 *)(param_1 + 0x2140));
      }
    }
    else {
      if (*(char *)(param_1 + 0x3da4) == '\0') {
LAB_00102a68:
        iVar1 = -0x13;
        goto LAB_00102a48;
      }
      iVar1 = *(int *)(param_1 + 0x3e20);
      *(int *)(param_1 + 0x3e20) = iVar1 + 1;
      if (iVar1 == 0) {
        iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(lVar3,*(undefined8 *)(param_1 + 0x2140));
        if (iVar1 < 0) {
          iVar2 = ___ratelimit(swrm_request_hw_vote__rs,"swrm_request_hw_vote");
          if (iVar2 != 0) {
            _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s:lpass core hw enable failed\n",
                     "swrm_request_hw_vote");
          }
          *(int *)(param_1 + 0x3e20) = *(int *)(param_1 + 0x3e20) + -1;
        }
        goto LAB_00102a48;
      }
    }
  }
  iVar1 = 0;
LAB_00102a48:
  mutex_unlock(param_1 + 0x2220);
  return iVar1;
}



//------------------------------------------------------------
// swr_master_write @ 00102ab4 size=316
// signature: undefined swr_master_write(void)
// callers: [swr_master_bulk_write, swrm_runtime_resume, swrm_pcm_port_config, swrm_runtime_suspend, swrm_debug_write, swrm_disable_ports, swr_mstr_interrupt, swrm_cmd_fifo_rd_cmd, swrm_switch_frame_shape, swrm_cmd_fifo_wr_cmd, swrm_master_init, swrm_slvdev_datapath_control]
//------------------------------------------------------------

void swr_master_write(long param_1,ushort param_2,undefined4 param_3)

{
  int iVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_1 + 0x2378);
  if (pcVar2 != (code *)0x0) {
    if (*(int *)(pcVar2 + -4) != 0x181144f3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102b04);
      (*pcVar2)();
    }
    (*pcVar2)(*(undefined8 *)(param_1 + 0x2368),param_2,param_3);
    return;
  }
  mutex_lock(param_1 + 0x2220);
  if (*(char *)(param_1 + 0x3da4) == '\0') goto LAB_00102bd0;
  if (*(int *)(param_1 + 0x23a8) < 0x1050002) {
    iVar1 = swrm_clk_request();
    if (iVar1 != 0) {
      iVar1 = ___ratelimit(swrm_ahb_write__rs,"swrm_ahb_write");
      if (iVar1 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: clock request failed\n","swrm_ahb_write");
      }
      goto LAB_00102bd0;
    }
LAB_00102b90:
    writel(param_3,*(long *)(param_1 + 0x2348) + (ulong)param_2);
    if (*(int *)(param_1 + 0x23a8) < 0x1050002) {
      swrm_clk_request(param_1,0);
      goto LAB_00102bb8;
    }
  }
  else {
    iVar1 = swrm_core_vote_request(param_1,1);
    if (iVar1 != -0x20a) {
      if (iVar1 != 0) goto LAB_00102bd0;
      goto LAB_00102b90;
    }
LAB_00102bb8:
    if (*(int *)(param_1 + 0x23a8) < 0x1050002) goto LAB_00102bd0;
  }
  swrm_core_vote_request(param_1,0);
LAB_00102bd0:
  mutex_unlock(param_1 + 0x2220);
  return;
}



//------------------------------------------------------------
// swrm_cmd_fifo_wr_cmd @ 00102bf0 size=356
// signature: undefined swrm_cmd_fifo_wr_cmd(void)
// callers: [swrm_write, swrm_runtime_resume, swrm_runtime_suspend, swrm_initialize_clk_base_scale, swrm_enable_slave_irq, swrm_disable_ports, swr_mstr_interrupt, swrm_switch_frame_shape, swrm_slvdev_datapath_control]
//------------------------------------------------------------

void swrm_cmd_fifo_wr_cmd(long param_1,int param_2,uint param_3,byte param_4,uint param_5)

{
  byte bVar1;
  byte bVar2;
  code *pcVar3;
  byte bVar4;
  uint uVar5;
  
  mutex_lock(param_1 + 0x21f0);
  if (param_4 != 0xf) {
    if (param_4 != 0) {
      bVar4 = 0;
      if (param_4 < 0xe) {
        bVar4 = param_4 + 1;
      }
      uVar5 = (uint)bVar4 << 0x10;
      goto LAB_00102c90;
    }
    bVar2 = *(byte *)(param_1 + 0x2359);
    if (bVar2 != 0xf) {
      bVar4 = 0;
      bVar1 = 0;
      if (bVar2 < 0xe) {
        bVar1 = bVar2 + 1;
      }
      uVar5 = (uint)bVar1 << 0x10;
      *(byte *)(param_1 + 0x2359) = bVar1;
      goto LAB_00102c90;
    }
    param_4 = 0;
  }
  uVar5 = 0xf0000;
  bVar4 = param_4;
LAB_00102c90:
  swrm_wait_for_fifo_avail(param_1,0);
  if (2 < *(uint *)(param_1 + 0x23ac)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x102d54);
    (*pcVar3)();
  }
  swr_master_write(param_1,*(undefined4 *)
                            (swrm_registers + (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x24),
                   param_5 & 0xffff | param_2 << 0x18 | (param_3 & 0xff) << 0x14 | uVar5);
  if (*(long *)(param_1 + 0x2378) == 0) {
    usleep_range_state(0x96,0x9b,2);
  }
  if (bVar4 == 0xf) {
    if (*(int *)(param_1 + 0x23a8) == 0x1040000) {
      usleep_range_state(10000,0x2774,2);
    }
    else {
      wait_for_completion_timeout(param_1 + 0x21a0,0x32);
    }
  }
  mutex_unlock(param_1 + 0x21f0);
  return;
}



//------------------------------------------------------------
// swrm_check_link_status @ 00102d54 size=264
// signature: undefined swrm_check_link_status(void)
// callers: [swrm_runtime_resume, swrm_runtime_suspend, swr_mstr_interrupt, swrm_master_init]
//------------------------------------------------------------

undefined8 swrm_check_link_status(long param_1,uint param_2)

{
  char *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x23a8) < 0x1050002) {
    return 1;
  }
  iVar5 = -99;
  if (*(int *)(param_1 + 0x23a8) < 0x2000000) goto LAB_00102dc4;
  do {
    iVar4 = *(int *)(param_1 + 0x2360) * 0x1000 + 0x4064;
    while( true ) {
      uVar2 = swr_master_read(param_1,iVar4);
      if ((uVar2 & 1) == (param_2 & 1)) {
        return 1;
      }
      usleep_range_state(500,0x1fe,2);
      if (iVar5 == 0) {
        uVar3 = ___ratelimit(swrm_check_link_status__rs,"swrm_check_link_status");
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        pcVar1 = "connected";
        if ((param_2 & 1) == 0) {
          pcVar1 = "disconnected";
        }
        _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: link status not %s\n",
                 "swrm_check_link_status",pcVar1);
        return 0;
      }
      iVar5 = iVar5 + 1;
      if (0x1ffffff < *(int *)(param_1 + 0x23a8)) break;
LAB_00102dc4:
      iVar4 = 0x14;
    }
  } while( true );
}



//------------------------------------------------------------
// swr_master_read @ 00102e5c size=336
// signature: undefined swr_master_read(void)
// callers: [swrm_initialize_clk_base_scale, swrm_enable_slave_irq, swrm_probe, swrm_debug_reg_dump, swrm_switch_frame_shape, swrm_master_init, swrm_debug_peek_write, swrm_pcm_port_config, swrm_runtime_suspend, swrm_get_logical_dev_num, swrm_wait_for_fifo_avail, swr_mstr_interrupt, swrm_cmd_fifo_rd_cmd, swrm_check_link_status, swrm_slvdev_datapath_control]
//------------------------------------------------------------

undefined4 swr_master_read(long param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(param_1 + 0x2370);
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != 0x58b62cee) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102ea4);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)(*(undefined8 *)(param_1 + 0x2368),param_2);
    return uVar1;
  }
  mutex_lock(param_1 + 0x2220);
  if (*(char *)(param_1 + 0x3da4) == '\0') {
LAB_00102f08:
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x23a8) < 0x1050002) {
      iVar2 = swrm_clk_request();
      if (iVar2 != 0) {
        iVar2 = ___ratelimit(swrm_ahb_read__rs,"swrm_ahb_read");
        if (iVar2 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: clock request failed\n","swrm_ahb_read");
          uVar1 = 0;
          goto LAB_00102f68;
        }
        goto LAB_00102f08;
      }
LAB_00102f24:
      uVar1 = readl(*(long *)(param_1 + 0x2348) + (ulong)(param_2 & 0xffff));
      if (*(int *)(param_1 + 0x23a8) < 0x1050002) {
        swrm_clk_request(param_1,0);
        goto LAB_00102f50;
      }
    }
    else {
      iVar2 = swrm_core_vote_request(param_1,1);
      uVar1 = 0;
      if (iVar2 != -0x20a) {
        if (iVar2 != 0) goto LAB_00102f68;
        goto LAB_00102f24;
      }
LAB_00102f50:
      if (*(int *)(param_1 + 0x23a8) < 0x1050002) goto LAB_00102f68;
    }
    swrm_core_vote_request(param_1,0);
  }
LAB_00102f68:
  mutex_unlock(param_1 + 0x2220);
  return uVar1;
}



//------------------------------------------------------------
// swrm_core_vote_request @ 00102fac size=244
// signature: undefined swrm_core_vote_request(void)
// callers: [swr_master_write, swr_master_read]
//------------------------------------------------------------

int swrm_core_vote_request(long param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  if (*(long *)(param_1 + 0x2368) == 0) {
    iVar1 = -0x16;
  }
  else {
    mutex_lock(param_1 + 0x21c0);
    if (*(char *)(param_1 + 0x3da4) == '\0') {
      iVar1 = -0x13;
    }
    else {
      pcVar3 = *(code **)(param_1 + 0x2390);
      if (pcVar3 == (code *)0x0) {
        iVar1 = 0;
      }
      else {
        if (*(int *)(pcVar3 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103014);
          (*pcVar3)();
        }
        iVar1 = (*pcVar3)(*(undefined8 *)(param_1 + 0x2368),param_2 & 1);
        if (((iVar1 != 0) &&
            (iVar2 = ___ratelimit(swrm_core_vote_request_rtl,"swrm_core_vote_request"), iVar2 != 0))
           && (iVar2 = ___ratelimit(swrm_core_vote_request__rs,"swrm_core_vote_request"), iVar2 != 0
              )) {
          _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: core vote request failed\n",
                   "swrm_core_vote_request");
        }
      }
    }
    mutex_unlock(param_1 + 0x21c0);
  }
  return iVar1;
}



//------------------------------------------------------------
// readl @ 001030a0 size=140
// signature: undefined readl(void)
// callers: [swrm_runtime_resume, swrm_master_init, swr_master_read]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1030f8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 0010312c size=136
// signature: undefined writel(void)
// callers: [swrm_runtime_resume, swr_master_write, swrm_master_init]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103144,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x103184,uVar1);
  return;
}



//------------------------------------------------------------
// swrm_wait_for_fifo_avail @ 001031b4 size=384
// signature: undefined swrm_wait_for_fifo_avail(void)
// callers: [swr_master_bulk_write, swrm_cmd_fifo_rd_cmd, swrm_cmd_fifo_wr_cmd]
//------------------------------------------------------------

void swrm_wait_for_fifo_avail(long param_1,int param_2)

{
  code *pcVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  char *pcVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 + 0x23ac);
  if (param_2 == 0) {
    if (2 < uVar7) goto LAB_00103330;
    uVar3 = swr_master_read(param_1,*(undefined4 *)(swrm_registers + (ulong)uVar7 * 4 + 0x48));
    uVar7 = *(uint *)(param_1 + 0x3e38);
    uVar3 = uVar3 >> 8 & 0x1f;
    if (uVar3 == uVar7) {
      iVar4 = -0x1d;
      do {
        usleep_range_state(500,0x1fe,2);
        if (2 < *(uint *)(param_1 + 0x23ac)) goto LAB_00103330;
        uVar3 = swr_master_read(param_1,*(undefined4 *)
                                         (swrm_registers +
                                         (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x48));
        uVar7 = *(uint *)(param_1 + 0x3e38);
        uVar3 = uVar3 >> 8 & 0x1f;
        bVar2 = iVar4 != 0;
        iVar4 = iVar4 + 1;
      } while (uVar7 <= uVar3 && bVar2);
    }
    if ((uVar3 == uVar7) &&
       (iVar4 = ___ratelimit(swrm_wait_for_fifo_avail__rs_51,"swrm_wait_for_fifo_avail"), iVar4 != 0
       )) {
      pcVar6 = "%s err write overflow\n";
LAB_0010331c:
      _dev_err(*(undefined8 *)(param_1 + 0x2140),pcVar6,"swrm_wait_for_fifo_avail");
    }
  }
  else {
    if (2 < uVar7) {
LAB_00103330:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103334);
      (*pcVar1)();
    }
    uVar5 = swr_master_read(param_1,*(undefined4 *)(swrm_registers + (ulong)uVar7 * 4 + 0x48));
    if ((uVar5 & 0x1f0000) == 0) {
      uVar7 = 0xffffffe1;
      do {
        bVar2 = 0xfffffffe < uVar7;
        uVar7 = uVar7 + 1;
        if (bVar2) {
          iVar4 = ___ratelimit(swrm_wait_for_fifo_avail__rs,"swrm_wait_for_fifo_avail");
          if (iVar4 == 0) {
            return;
          }
          pcVar6 = "%s err read underflow\n";
          goto LAB_0010331c;
        }
        usleep_range_state(500,0x1fe,2);
        if (2 < *(uint *)(param_1 + 0x23ac)) goto LAB_00103330;
        uVar5 = swr_master_read(param_1,*(undefined4 *)
                                         (swrm_registers +
                                         (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x48));
      } while ((uVar5 & 0x1f0000) == 0);
    }
  }
  return;
}



//------------------------------------------------------------
// swrm_probe @ 00103338 size=3736
// signature: undefined swrm_probe(void)
// callers: []
//------------------------------------------------------------

int swrm_probe(long param_1)

{
  uint *puVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  long *plVar14;
  char *pcVar15;
  long lVar16;
  ulong uVar17;
  code *pcVar18;
  undefined1 *puVar19;
  long lVar20;
  undefined1 uVar21;
  long lVar22;
  uint uVar23;
  long *plVar24;
  uint local_74;
  undefined4 local_70;
  uint local_6c;
  long local_68;
  
  lVar11 = sp_el0;
  plVar14 = (long *)(param_1 + 0x10);
  local_68 = *(long *)(lVar11 + 0x638);
  local_6c = 0;
  local_74 = 0;
  local_70 = 0;
  lVar11 = devm_kmalloc(plVar14,0x51b8,0xdc0);
  if (lVar11 == 0) {
LAB_00103b2c:
    iVar7 = -0xc;
    goto LAB_00104178;
  }
  plVar24 = *(long **)(param_1 + 0xa0);
  *(long *)(lVar11 + 0x3bf0) = param_1;
  *(long **)(lVar11 + 0x2140) = plVar14;
  *(long *)(param_1 + 0xa8) = lVar11;
  *(long *)(lVar11 + 0x98) = lVar11;
  if (plVar24 == (long *)0x0) {
    pcVar15 = "%s: pdata from parent is NULL\n";
  }
  else {
    lVar16 = *plVar24;
    *(long *)(lVar11 + 0x2368) = lVar16;
    if (lVar16 == 0) {
      pcVar15 = "%s: swrm->handle is NULL\n";
    }
    else {
      iVar7 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-master-ee-val",
                         (undefined4 *)(lVar11 + 0x2360),1,0);
      if (iVar7 < 0) {
        *(undefined4 *)(lVar11 + 0x2360) = 1;
      }
      puVar1 = (uint *)(lVar11 + 0x23a8);
      iVar7 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-master-version",puVar1,1,0);
      if (iVar7 < 0) {
        *puVar1 = 0;
LAB_00103444:
        iVar7 = ___ratelimit(get_version_index__rs,"get_version_index");
        if (iVar7 != 0) {
          _printk(&DAT_0010be1a,"get_version_index");
        }
LAB_0010345c:
        uVar10 = 0;
      }
      else {
        uVar9 = *puVar1 & 0xffffff00;
        if ((int)uVar9 < 0x2000000) {
          if (uVar9 == 0x1060000) goto LAB_0010345c;
          if (uVar9 != 0x1070000) goto LAB_00103444;
          uVar10 = 1;
        }
        else {
          if ((uVar9 != 0x2000000) && (uVar9 != 0x2010000)) goto LAB_00103444;
          uVar10 = 2;
        }
      }
      uVar12 = *(undefined8 *)(param_1 + 0x2f8);
      *(undefined4 *)(lVar11 + 0x23ac) = uVar10;
      iVar7 = of_property_read_variable_u32_array(uVar12,"qcom,swr_master_id",lVar11 + 0x235c,1,0);
      if (iVar7 < 0) {
        _dev_err(plVar14,"%s: failed to get master id\n","swrm_probe");
        goto LAB_00104178;
      }
      iVar7 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,dynamic-port-map-supported",
                         (undefined4 *)(lVar11 + 0x2364),1,0);
      if (iVar7 < 0) {
        *(undefined4 *)(lVar11 + 0x2364) = 1;
      }
      piVar2 = (int *)(lVar11 + 0x2340);
      iVar7 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"swrm-io-base",piVar2,1,0);
      if (-1 < iVar7) {
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"swrm-io-base",piVar2,1,0);
      }
      iVar7 = *piVar2;
      if (iVar7 == 0) {
        lVar16 = plVar24[1];
        *(long *)(lVar11 + 0x2370) = lVar16;
        if (lVar16 == 0) {
          pcVar15 = "%s: swrm->read is NULL\n";
        }
        else {
          lVar16 = plVar24[2];
          *(long *)(lVar11 + 0x2378) = lVar16;
          if (lVar16 == 0) {
            pcVar15 = "%s: swrm->write is NULL\n";
          }
          else {
            lVar16 = plVar24[3];
            *(long *)(lVar11 + 0x2380) = lVar16;
            if (lVar16 != 0) goto LAB_001035fc;
            pcVar15 = "%s: swrm->bulk_write is NULL\n";
          }
        }
      }
      else {
        if (*puVar1 == 0) {
          uVar10 = 0x1954;
        }
        else {
          uVar9 = *puVar1 & 0xffffff00;
          if ((int)uVar9 < 0x2000000) {
            if (uVar9 == 0x1060000) {
LAB_001035cc:
              lVar16 = 0;
            }
            else {
              if (uVar9 != 0x1070000) goto LAB_001035b4;
              lVar16 = 1;
            }
          }
          else {
            if ((uVar9 != 0x2000000) && (uVar9 != 0x2010000)) {
LAB_001035b4:
              iVar7 = ___ratelimit(get_version_index__rs,"get_version_index");
              if (iVar7 != 0) {
                _printk(&DAT_0010be1a,"get_version_index");
              }
              goto LAB_001035cc;
            }
            lVar16 = 2;
          }
          *(int *)(lVar11 + 0x23ac) = (int)lVar16;
          uVar10 = *(undefined4 *)(swrm_registers + lVar16 * 4 + 0x54);
          iVar7 = *(int *)(lVar11 + 0x2340);
        }
        uVar12 = devm_ioremap(plVar14,iVar7,uVar10);
        *(undefined8 *)(lVar11 + 0x2348) = uVar12;
LAB_001035fc:
        uVar12 = *(undefined8 *)(param_1 + 0x2f8);
        *(long *)(lVar11 + 0x2390) = plVar24[5];
        iVar7 = of_property_read_variable_u32_array(uVar12,"qcom,swrm-hctl-reg",&local_70,1,0);
        if (-1 < iVar7) {
          uVar12 = devm_ioremap(plVar14,local_70,4);
          *(undefined8 *)(lVar11 + 0x2350) = uVar12;
        }
        lVar16 = plVar24[4];
        *(long *)(lVar11 + 0x2388) = lVar16;
        if (lVar16 != 0) {
          iVar7 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-clock-stop-mode0",
                             (undefined4 *)(lVar11 + 0x3d68),1,0);
          if (iVar7 < 0) {
            *(undefined4 *)(lVar11 + 0x3d68) = 0;
          }
          iVar7 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-num-ports",&local_6c,1,0);
          if (iVar7 < 0) {
            uVar12 = *(undefined8 *)(lVar11 + 0x2140);
            pcVar15 = "%s: Failed to get num_ports\n";
LAB_00103f40:
            _dev_err(uVar12,pcVar15,"swrm_probe");
            goto LAB_00104178;
          }
          uVar12 = *(undefined8 *)(param_1 + 0x2f8);
          *(char *)(lVar11 + 0x3c80) = (char)local_6c;
          lVar16 = of_find_property(uVar12,"qcom,swr-port-mapping",&local_74);
          uVar9 = local_74;
          if (lVar16 == 0) {
            _dev_err(*(undefined8 *)(lVar11 + 0x2140),"missing port mapping\n");
            iVar7 = 0;
            goto LAB_00104178;
          }
          *(undefined4 *)(lVar11 + 0x3e2c) = 0;
          if (0xd < local_6c) {
            pcVar15 = "%s:invalid number of swr ports\n";
            goto LAB_00103fe0;
          }
          lVar16 = devm_kmalloc(plVar14,local_74,0xdc0);
          if (lVar16 == 0) goto LAB_00103b2c;
          iVar7 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-port-mapping",lVar16,
                             (uVar9 / 0xc) * 3,0);
          if (iVar7 < 0) {
            uVar12 = *(undefined8 *)(lVar11 + 0x2140);
            pcVar15 = "%s: Failed to read port mapping\n";
            goto LAB_00103f40;
          }
          if (0xb < uVar9) {
            uVar9 = uVar9 / 0xc;
            uVar23 = 0;
            if (uVar9 < 2) {
              uVar9 = 1;
            }
            uVar17 = (ulong)uVar9;
            puVar19 = (undefined1 *)(lVar16 + 8);
            uVar9 = 0;
            do {
              uVar6 = *(uint *)(puVar19 + -8);
              if (uVar6 != uVar9) {
                uVar23 = 0;
              }
              if ((0xd < uVar6) || (7 < uVar23)) {
                _dev_err(plVar14,"%s:invalid port_num %d or ch_iter %d\n","swrm_probe");
                iVar7 = 0;
                goto LAB_00104178;
              }
              uVar21 = 3;
              if (*(int *)(puVar19 + -4) != 0x6b) {
                uVar21 = 1;
              }
              lVar20 = lVar11 + (ulong)uVar6 * 0x10 + (ulong)uVar23 * 2;
              if (*(int *)(lVar11 + 0x235c) != 5) {
                uVar21 = *puVar19;
              }
              uVar23 = uVar23 + 1;
              uVar17 = uVar17 - 1;
              *(char *)(lVar20 + 0x3c81) = (char)*(int *)(puVar19 + -4);
              *(undefined1 *)(lVar20 + 0x3c82) = uVar21;
              puVar19 = puVar19 + 0xc;
              uVar9 = uVar6;
            } while (uVar17 != 0);
          }
          devm_kfree(plVar14,lVar16);
          iVar8 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,is-always-on",lVar11 + 0x3e44,1,
                             0);
          *(long *)(lVar11 + 0x2398) = plVar24[6];
          *(code **)(lVar11 + 0x20f0) = swrm_read;
          if (-1 < iVar8) {
            iVar8 = 0;
          }
          *(code **)(lVar11 + 0x2100) = swrm_bulk_write;
          *(code **)(lVar11 + 0x20f8) = swrm_write;
          *(long **)(lVar11 + 0x60) = plVar14;
          *(code **)(lVar11 + 0x2108) = swrm_get_logical_dev_num;
          *(code **)(lVar11 + 0x2130) = swrm_device_wakeup_unvote;
          *(undefined1 *)(lVar11 + 0x20d9) = 0;
          *(undefined1 *)(lVar11 + 0x235a) = 0;
          *(code **)(lVar11 + 0x2110) = swrm_init_port_params;
          *(undefined2 *)(lVar11 + 0x2358) = 0;
          *(undefined4 *)(lVar11 + 0x23bc) = 0;
          piVar2 = (int *)(lVar11 + 0x3e1c);
          *(undefined4 *)(lVar11 + 0x3bf8) = 0;
          *(code **)(lVar11 + 0x20e0) = swrm_connect_port;
          *(undefined4 *)(lVar11 + 0x2158) = 0;
          *(undefined4 *)(lVar11 + 0x3e1c) = 0;
          *(undefined8 *)(lVar11 + 0x23b0) = 0x927c0000927c00;
          *(code **)(lVar11 + 0x20e8) = swrm_disconnect_port;
          *(code **)(lVar11 + 0x2118) = swrm_slvdev_datapath_control;
          *(code **)(lVar11 + 0x2120) = swrm_remove_from_group;
          *(code **)(lVar11 + 0x2128) = swrm_device_wakeup_vote;
          *(undefined8 *)(lVar11 + 0x2e8) = *(undefined8 *)(param_1 + 0x2f8);
          if (*(int *)(lVar11 + 0x235c) == 5) {
            *(undefined8 *)(lVar11 + 0x23b0) = 0xbb800000bb8000;
          }
          *(undefined2 *)(lVar11 + 0x3da4) = 1;
          *(undefined4 *)(lVar11 + 0x3be8) = 2;
          *(undefined4 *)(lVar11 + 0x3da0) = 0;
          *(undefined1 *)(lVar11 + 0x3e40) = 0;
          *(undefined1 *)(lVar11 + 0x3e48) = 0;
          *(undefined4 *)(lVar11 + 0x3e30) = 0;
          *(undefined4 *)(lVar11 + 0x2180) = 0;
          __init_swait_queue_head(lVar11 + 0x2188,"&x->wait",&init_completion___key);
          *(undefined4 *)(lVar11 + 0x21a0) = 0;
          __init_swait_queue_head(lVar11 + 0x21a8,"&x->wait",&init_completion___key);
          *(undefined4 *)(lVar11 + 0x2160) = 0;
          __init_swait_queue_head(lVar11 + 0x2168,"&x->wait",&init_completion___key);
          __mutex_init(lVar11 + 0x22e0,"&swrm->irq_lock",&swrm_probe___key);
          lVar3 = lVar11 + 0x2250;
          __mutex_init(lVar3,"&swrm->mlock",&swrm_probe___key_89);
          __mutex_init(lVar11 + 0x2280,"&swrm->reslock",&swrm_probe___key_91);
          __mutex_init(lVar11 + 0x3c00,"&swrm->force_down_lock",&swrm_probe___key_93);
          __mutex_init(lVar11 + 0x21f0,"&swrm->iolock",&swrm_probe___key_95);
          __mutex_init(lVar11 + 0x21c0,"&swrm->clklock",&swrm_probe___key_97);
          __mutex_init(lVar11 + 0x2220,"&swrm->devlock",&swrm_probe___key_99);
          __mutex_init(lVar11 + 0x22b0,"&swrm->pm_lock",&swrm_probe___key_101);
          __mutex_init(lVar11 + 0x2310,"&swrm->runtime_lock",&swrm_probe___key_103);
          *(undefined4 *)(lVar11 + 0x3df8) = 0;
          *(undefined4 *)(lVar11 + 0x3dd8) = 0;
          __init_waitqueue_head(lVar11 + 0x3de0,"&swrm->pm_wq",&swrm_probe___key_105);
          cpu_latency_qos_add_request(lVar11 + 0x3da8,0xffffffff);
          uVar17 = 0;
          lVar16 = 0x23c0;
          lVar20 = 0x23df;
          lVar22 = 0x23d6;
          do {
            lVar5 = lVar11 + lVar16;
            *(long *)lVar5 = lVar5;
            *(long *)(lVar5 + 8) = lVar5;
            iVar7 = *(int *)(lVar11 + 0x235c);
            if ((iVar7 == 5) || (iVar7 == 3)) {
              *(undefined2 *)(lVar11 + lVar22) = 0xffff;
              lVar4 = lVar11 + lVar20;
              uVar21 = 0x14;
              if (iVar7 != 5 || uVar17 < 4) {
                uVar21 = 0;
              }
              *(undefined1 *)(lVar4 + -0xb) = 0;
              *(undefined1 *)(lVar4 + -0xc) = uVar21;
              *(undefined1 *)(lVar5 + 0x1c) = 0xff;
              *(undefined4 *)(lVar5 + 0x18) = 0xffffffff;
              *(undefined1 *)(lVar4 + -2) = 0;
              *(bool *)(lVar4 + -1) = 3 < uVar17 && *(int *)(lVar11 + 0x235c) == 5;
              *(bool *)lVar4 = *(int *)(lVar11 + 0x235c) != 3;
            }
            uVar17 = uVar17 + 1;
            lVar16 = lVar16 + 0x28;
            lVar20 = lVar20 + 0x28;
            lVar22 = lVar22 + 0x28;
          } while (uVar17 != 0xd);
          iVar7 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,disable-div2-clk-switch",
                             (undefined4 *)(lVar11 + 0x3e30),1,0);
          if (iVar7 < 0) {
            *(undefined4 *)(lVar11 + 0x3e30) = 0;
          }
          uVar13 = devm_clk_get(plVar14,"lpass_core_hw_vote");
          uVar17 = 0;
          if (uVar13 < 0xfffffffffffff001) {
            uVar17 = uVar13;
          }
          *(ulong *)(lVar11 + 0x3e08) = uVar17;
          uVar17 = devm_clk_get(plVar14,"lpass_audio_hw_vote");
          pcVar18 = *(code **)(lVar11 + 0x2398);
          iVar7 = 0;
          if (uVar13 < 0xfffffffffffff001 && uVar17 < 0xfffffffffffff001) {
            iVar7 = iVar8;
          }
          uVar13 = 0;
          if (uVar17 < 0xfffffffffffff001) {
            uVar13 = uVar17;
          }
          *(ulong *)(lVar11 + 0x3e10) = uVar13;
          if (pcVar18 == (code *)0x0) {
            iVar8 = platform_get_irq_byname(param_1,"swr_master_irq");
            *(int *)(lVar11 + 0x23a0) = iVar8;
            if (-1 < iVar8) {
              iVar7 = request_threaded_irq
                                (iVar8,0,swr_mstr_interrupt,0x2001,"swr_master_irq",lVar11);
              if (iVar7 == 0) goto LAB_00103c40;
              plVar14 = *(long **)(lVar11 + 0x2140);
              pcVar15 = "%s: Failed to request irq %d\n";
              goto LAB_00104168;
            }
            plVar14 = *(long **)(lVar11 + 0x2140);
            pcVar15 = "%s() error getting irq hdle: %d\n";
LAB_0010416c:
            _dev_err(plVar14,pcVar15,"swrm_probe",iVar8);
          }
          else {
            if (*(int *)(pcVar18 + -4) != -0x4cfe445d) {
                    /* WARNING: Does not return */
              pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x103bd8);
              (*pcVar18)();
            }
            iVar7 = (*pcVar18)(*(undefined8 *)(lVar11 + 0x2368),swr_mstr_interrupt,lVar11,1);
            if (iVar7 != 0) {
              pcVar15 = "%s: IRQ register failed ret %d\n";
LAB_00104168:
              iVar8 = iVar7;
              goto LAB_0010416c;
            }
LAB_00103c40:
            of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,swr-mstr-irq-wakeup-capable",piVar2,1,
                       0);
            if (*piVar2 != 0) {
              irq_set_irq_wake(*(undefined4 *)(lVar11 + 0x23a0),1);
              uVar12 = *(undefined8 *)(lVar11 + 0x2140);
              device_set_wakeup_capable(uVar12,1);
              iVar7 = device_wakeup_enable(uVar12);
              if (iVar7 != 0) {
                _dev_info(*(undefined8 *)(lVar11 + 0x2140),"%s: Device wakeup init failed: %d\n",
                          "swrm_probe",iVar7);
              }
            }
            iVar7 = swr_register_master(lVar11);
            if (iVar7 == 0) {
              swr_master_add_boarddevices(lVar11);
              if (*(int *)(lVar11 + 0x3e44) == 0) {
                swrm_request_hw_vote(lVar11,1,1);
              }
              mutex_lock(lVar3);
              swrm_clk_request(lVar11,1);
              uVar9 = swr_master_read(lVar11,0x100);
              *(uint *)(lVar11 + 0x3e34) = uVar9 >> 0xf & 0x1f;
              uVar9 = swr_master_read(lVar11,0x100);
              *(uint *)(lVar11 + 0x3e38) = uVar9 >> 10 & 0x1f;
              iVar7 = swr_master_read(lVar11,0);
              if (*(int *)(lVar11 + 0x23a8) != iVar7) {
                _dev_info(plVar14,
                          "%s: version specified in dtsi: 0x%x not match with HW read version 0x%x\n"
                          ,"swrm_probe",*(int *)(lVar11 + 0x23a8),iVar7);
                *(int *)(lVar11 + 0x23a8) = iVar7;
                uVar10 = get_version_index(iVar7);
                *(undefined4 *)(lVar11 + 0x23ac) = uVar10;
              }
              uVar9 = swr_master_read(lVar11,0x100);
              *(uint *)(lVar11 + 0x3e3c) = uVar9 >> 0x14 & 0xf;
              iVar7 = of_property_read_variable_u32_array
                                (*(undefined8 *)(*(long *)(lVar11 + 0x2140) + 0x2e8),
                                 "qcom,swr-num-dev",lVar11 + 0x23b8,1,0);
              if (iVar7 < 0) {
                _dev_err(plVar14,"%s: Looking up %s property failed\n","swrm_probe",
                         "qcom,swr-num-dev");
              }
              else if (*(uint *)(lVar11 + 0x3e3c) < *(uint *)(lVar11 + 0x23b8)) {
                _dev_err(plVar14,"%s: num_dev %d > max limit %d\n","swrm_probe");
                iVar7 = -0x16;
              }
              else {
                iVar7 = swrm_master_init(lVar11);
                if (-1 < iVar7) {
                  mutex_unlock(lVar3);
                  *(undefined8 *)(lVar11 + 0x3d70) = 0xfffffffe0;
                  *(long *)(lVar11 + 0x3d78) = lVar11 + 0x3d78;
                  *(long *)(lVar11 + 0x3d80) = lVar11 + 0x3d78;
                  lVar16 = *(long *)(param_1 + 0x2f8);
                  *(code **)(lVar11 + 0x3d88) = swrm_wakeup_work;
                  if (lVar16 != 0) {
                    of_register_swr_devices(lVar11);
                  }
                  lVar16 = *(long *)(param_1 + 0x80);
                  if (lVar16 == 0) {
                    lVar16 = *plVar14;
                  }
                  uVar17 = debugfs_create_dir(lVar16,0);
                  *(ulong *)(lVar11 + 0x5190) = uVar17;
                  if (uVar17 < 0xfffffffffffff001) {
                    uVar12 = debugfs_create_file("swrm_peek",0x8124,uVar17,lVar11,
                                                 swrm_debug_read_ops);
                    *(undefined8 *)(lVar11 + 0x5198) = uVar12;
                    uVar12 = debugfs_create_file("swrm_poke",0x8124,*(undefined8 *)(lVar11 + 0x5190)
                                                 ,lVar11,swrm_debug_write_ops);
                    *(undefined8 *)(lVar11 + 0x51a0) = uVar12;
                    uVar12 = debugfs_create_file("swrm_reg_dump",0x8124,
                                                 *(undefined8 *)(lVar11 + 0x5190),lVar11,
                                                 swrm_debug_dump_ops);
                    *(undefined8 *)(lVar11 + 0x51a8) = uVar12;
                  }
                  pm_runtime_set_autosuspend_delay(plVar14,auto_suspend_timer);
                  __pm_runtime_use_autosuspend(plVar14,1);
                  __pm_runtime_set_status(plVar14,0);
                  pm_runtime_enable(plVar14);
                  uVar12 = ktime_get_mono_fast_ns();
                  *(undefined8 *)(param_1 + 0x230) = uVar12;
                  iVar7 = 0;
                  *(undefined8 *)(lVar11 + 0x3c50) = 0xfffffffe0;
                  *(long *)(lVar11 + 0x3c58) = lVar11 + 0x3c58;
                  *(long *)(lVar11 + 0x3c60) = lVar11 + 0x3c58;
                  *(code **)(lVar11 + 0x3c68) = swrm_notify_work_fn;
                  *(code **)(lVar11 + 0x3c38) = swrm_event_notify;
                  goto LAB_00104178;
                }
                _dev_err(plVar14,"%s: Error in master Initialization , err %d\n","swrm_probe",iVar7)
                ;
                iVar7 = -0x205;
              }
              mutex_unlock(lVar3);
              swr_unregister_master(lVar11);
              uVar12 = *(undefined8 *)(lVar11 + 0x2140);
              device_wakeup_disable(uVar12);
              device_set_wakeup_capable(uVar12,0);
            }
            else {
              _dev_err(plVar14,"%s: error adding swr master\n","swrm_probe");
            }
            pcVar18 = *(code **)(lVar11 + 0x2398);
            if (pcVar18 == (code *)0x0) {
              if (*(int *)(lVar11 + 0x23a0) != 0) {
                lVar16 = irq_get_irq_data();
                if (lVar16 != 0) {
                  lVar16 = irq_get_irq_data(*(undefined4 *)(lVar11 + 0x23a0));
                  **(uint **)(lVar16 + 0x10) = **(uint **)(lVar16 + 0x10) & 0xfffffff0;
                  **(uint **)(lVar16 + 0x10) = **(uint **)(lVar16 + 0x10) | 0x2000000;
                }
                if (*piVar2 != 0) {
                  irq_set_irq_wake(*(undefined4 *)(lVar11 + 0x23a0),0);
                }
                free_irq(*(undefined4 *)(lVar11 + 0x23a0),lVar11);
              }
            }
            else {
              if (*(int *)(pcVar18 + -4) != -0x4cfe445d) {
                    /* WARNING: Does not return */
                pcVar18 = (code *)SoftwareBreakpoint(0x8228,0x104094);
                (*pcVar18)();
              }
              (*pcVar18)(*(undefined8 *)(lVar11 + 0x2368),swr_mstr_interrupt,lVar11,0);
            }
          }
          cpu_latency_qos_remove_request(lVar11 + 0x3da8);
          goto LAB_00104178;
        }
        pcVar15 = "%s: swrm->clk is NULL\n";
      }
    }
  }
LAB_00103fe0:
  _dev_err(plVar14,pcVar15,"swrm_probe");
  iVar7 = -0x16;
LAB_00104178:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// swrm_remove @ 001041d4 size=312
// signature: undefined swrm_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_remove(long param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = *(long *)(param_1 + 0xa8);
  pcVar3 = *(code **)(lVar4 + 0x2398);
  if (pcVar3 == (code *)0x0) {
    if (*(int *)(lVar4 + 0x23a0) == 0) {
      iVar1 = *(int *)(lVar4 + 0x23a4);
      if (iVar1 < 1) goto LAB_001042ac;
    }
    else {
      lVar2 = irq_get_irq_data();
      if (lVar2 != 0) {
        lVar2 = irq_get_irq_data(*(undefined4 *)(lVar4 + 0x23a0));
        **(uint **)(lVar2 + 0x10) = **(uint **)(lVar2 + 0x10) & 0xfffffff0;
        **(uint **)(lVar2 + 0x10) = **(uint **)(lVar2 + 0x10) | 0x2000000;
      }
      if (*(int *)(lVar4 + 0x3e1c) != 0) {
        irq_set_irq_wake(*(undefined4 *)(lVar4 + 0x23a0),0);
        uVar5 = *(undefined8 *)(lVar4 + 0x2140);
        device_wakeup_disable(uVar5);
        device_set_wakeup_capable(uVar5,0);
      }
      iVar1 = *(int *)(lVar4 + 0x23a0);
    }
    free_irq(iVar1,lVar4);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x4cfe445d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x104224);
      (*pcVar3)();
    }
    (*pcVar3)(*(undefined8 *)(lVar4 + 0x2368),swr_mstr_interrupt,lVar4,0);
  }
LAB_001042ac:
  cancel_work_sync(lVar4 + 0x3d70);
  param_1 = param_1 + 0x10;
  __pm_runtime_disable(param_1,1);
  __pm_runtime_set_status(param_1,2);
  swr_unregister_master(lVar4);
  cpu_latency_qos_remove_request(lVar4 + 0x3da8);
  devm_kfree(param_1,lVar4);
  return 0;
}



//------------------------------------------------------------
// get_version_index @ 0010430c size=152
// signature: undefined get_version_index(void)
// callers: [swrm_probe]
//------------------------------------------------------------

undefined8 get_version_index(uint param_1)

{
  undefined8 uVar1;
  
  param_1 = param_1 & 0xffffff00;
  if ((int)param_1 < 0x2000000) {
    if (param_1 == 0x1060000) {
      return 0;
    }
    if (param_1 == 0x1070000) {
      return 1;
    }
  }
  else if ((param_1 == 0x2000000) || (param_1 == 0x2010000)) {
    return 2;
  }
  uVar1 = ___ratelimit(get_version_index__rs,"get_version_index");
  if ((int)uVar1 == 0) {
    return uVar1;
  }
  _printk(&DAT_0010be1a,"get_version_index");
  return 0;
}



//------------------------------------------------------------
// swrm_read @ 001043a8 size=412
// signature: undefined swrm_read(void)
// callers: []
//------------------------------------------------------------

void swrm_read(long param_1,uint param_2,undefined4 param_3,undefined1 *param_4,undefined4 param_5)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  undefined4 local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (param_1 == 0) {
LAB_001044a8:
    iVar4 = ___ratelimit(swrm_read__rs,"swrm_read");
    if (iVar4 != 0) {
      pcVar7 = "%s: swrm is NULL\n";
LAB_0010452c:
      _dev_err(param_1,pcVar7,"swrm_read");
    }
  }
  else {
    lVar8 = *(long *)(param_1 + 0x98);
    local_5c = 0;
    if (lVar8 == 0) goto LAB_001044a8;
    if ((param_2 & 0xff) != 0) {
      mutex_lock(lVar8 + 0x2220);
      cVar2 = *(char *)(lVar8 + 0x3da4);
      mutex_unlock(lVar8 + 0x2220);
      if (cVar2 == '\0') {
        uVar6 = 0;
      }
      else {
        __pm_runtime_resume(*(undefined8 *)(lVar8 + 0x2140),4);
        if (*(char *)(lVar8 + 0x3da6) != '\0') {
          swrm_runtime_resume(*(undefined8 *)(lVar8 + 0x2140));
        }
        bVar3 = *(byte *)(lVar8 + 0x235a);
        bVar1 = 0;
        if (bVar3 != 0xe) {
          bVar1 = bVar3 + 1 & 0xf;
        }
        *(byte *)(lVar8 + 0x235a) = bVar1;
        swrm_cmd_fifo_rd_cmd(lVar8,&local_5c,param_2,bVar3,param_3,param_5);
        *param_4 = (char)local_5c;
        __pm_runtime_suspend(*(undefined8 *)(lVar8 + 0x2140),0xd);
        lVar8 = *(long *)(lVar8 + 0x2140);
        uVar5 = ktime_get_mono_fast_ns();
        uVar6 = 0;
        *(undefined8 *)(lVar8 + 0x220) = uVar5;
      }
      goto LAB_001044c4;
    }
    iVar4 = ___ratelimit(swrm_read__rs_125,"swrm_read");
    if (iVar4 != 0) {
      pcVar7 = "%s: invalid slave dev num\n";
      goto LAB_0010452c;
    }
  }
  uVar6 = 0xffffffea;
LAB_001044c4:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// swrm_write @ 00104548 size=348
// signature: undefined swrm_write(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_write(long param_1,uint param_2,undefined4 param_3,undefined1 *param_4)

{
  byte bVar1;
  undefined1 uVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  
  if ((param_1 == 0) || (lVar8 = *(long *)(param_1 + 0x98), lVar8 == 0)) {
    iVar5 = ___ratelimit(swrm_write__rs,"swrm_write");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: swrm is NULL\n";
  }
  else {
    if ((param_2 & 0xff) != 0) {
      uVar2 = *param_4;
      mutex_lock(lVar8 + 0x2220);
      cVar3 = *(char *)(lVar8 + 0x3da4);
      mutex_unlock(lVar8 + 0x2220);
      if (cVar3 == '\0') {
        return 0;
      }
      __pm_runtime_resume(*(undefined8 *)(lVar8 + 0x2140),4);
      if (*(char *)(lVar8 + 0x3da6) != '\0') {
        swrm_runtime_resume(*(undefined8 *)(lVar8 + 0x2140));
      }
      bVar4 = *(byte *)(lVar8 + 0x235a);
      bVar1 = 0;
      if (bVar4 != 0xe) {
        bVar1 = bVar4 + 1 & 0xf;
      }
      *(byte *)(lVar8 + 0x235a) = bVar1;
      swrm_cmd_fifo_wr_cmd(lVar8,uVar2,param_2,bVar4,param_3);
      __pm_runtime_suspend(*(undefined8 *)(lVar8 + 0x2140),0xd);
      lVar8 = *(long *)(lVar8 + 0x2140);
      uVar6 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar8 + 0x220) = uVar6;
      return 0;
    }
    iVar5 = ___ratelimit(swrm_write__rs_135,"swrm_write");
    if (iVar5 == 0) {
      return 0xffffffea;
    }
    pcVar7 = "%s: invalid slave dev num\n";
  }
  _dev_err(param_1,pcVar7,"swrm_write");
  return 0xffffffea;
}



//------------------------------------------------------------
// swrm_bulk_write @ 001046a8 size=560
// signature: undefined swrm_bulk_write(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_bulk_write(long param_1,byte param_2,long param_3,long param_4,ulong param_5)

{
  byte bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  uint uVar12;
  long lVar13;
  undefined8 uVar14;
  
  if (((param_1 == 0) || (lVar13 = *(long *)(param_1 + 0x98), lVar13 == 0)) ||
     (*(long *)(lVar13 + 0x2368) == 0)) {
    iVar7 = ___ratelimit(swrm_bulk_write__rs,"swrm_bulk_write");
    if (iVar7 != 0) {
      _dev_err(param_1,"%s: swrm is NULL\n","swrm_bulk_write");
    }
  }
  else if (param_5 != 0) {
    mutex_lock(lVar13 + 0x2220);
    cVar2 = *(char *)(lVar13 + 0x3da4);
    mutex_unlock(lVar13 + 0x2220);
    if (cVar2 == '\0') {
      return 0;
    }
    __pm_runtime_resume(*(undefined8 *)(lVar13 + 0x2140),4);
    if (param_2 == 0) {
      iVar7 = ___ratelimit(swrm_bulk_write__rs_138,"swrm_bulk_write");
      if (iVar7 != 0) {
        _dev_err(param_1,"%s: No support of Bulk write for master regs\n","swrm_bulk_write");
      }
      uVar14 = 0xffffffea;
    }
    else {
      if (param_5 >> 0x3e == 0) {
        lVar8 = __kmalloc(param_5 << 2,0xdc0);
        if (lVar8 != 0) {
          lVar9 = __kmalloc(param_5 << 2,0xdc0);
          if (lVar9 == 0) {
            uVar14 = 0xfffffff4;
          }
          else {
            uVar11 = 0;
            do {
              bVar4 = *(byte *)(param_4 + uVar11);
              bVar3 = *(byte *)(lVar13 + 0x2359);
              uVar5 = *(ushort *)(param_3 + uVar11 * 2);
              if (bVar3 == 0xf) {
                uVar12 = 0xf0000;
              }
              else {
                bVar1 = 0;
                if (bVar3 < 0xe) {
                  bVar1 = bVar3 + 1;
                }
                uVar12 = (uint)bVar1 << 0x10;
                *(byte *)(lVar13 + 0x2359) = bVar1;
              }
              *(uint *)(lVar9 + uVar11 * 4) =
                   (uint)param_2 << 0x14 | (uint)uVar5 | (uint)bVar4 << 0x18 | uVar12;
              if (2 < *(uint *)(lVar13 + 0x23ac)) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1048d8);
                (*pcVar6)();
              }
              *(undefined4 *)(lVar8 + uVar11 * 4) =
                   *(undefined4 *)(swrm_registers + (ulong)*(uint *)(lVar13 + 0x23ac) * 4 + 0x24);
              uVar11 = (ulong)((int)uVar11 + 1);
            } while (uVar11 < param_5);
            swr_master_bulk_write(lVar13,lVar8,lVar9,param_5 & 0xffffffff);
            kfree(lVar9);
            uVar14 = 0;
          }
          kfree(lVar8);
          goto LAB_0010489c;
        }
      }
      uVar14 = 0xfffffff4;
    }
LAB_0010489c:
    __pm_runtime_suspend(*(undefined8 *)(lVar13 + 0x2140),0xd);
    lVar13 = *(long *)(lVar13 + 0x2140);
    uVar10 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar13 + 0x220) = uVar10;
    return uVar14;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// swrm_get_logical_dev_num @ 001048dc size=556
// signature: undefined swrm_get_logical_dev_num(void)
// callers: []
//------------------------------------------------------------

int swrm_get_logical_dev_num(long param_1,ulong param_2,undefined1 *param_3)

{
  long *plVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  int iVar11;
  uint uVar12;
  long *plVar13;
  long *plVar14;
  
  if ((param_1 == 0) || (lVar9 = *(long *)(param_1 + 0x98), lVar9 == 0)) {
    _printk(&DAT_0010c21c,"swrm_get_logical_dev_num");
    return -0x16;
  }
  uVar2 = *(uint *)(lVar9 + 0x23b8);
  mutex_lock(lVar9 + 0x2220);
  cVar3 = *(char *)(lVar9 + 0x3da4);
  mutex_unlock(lVar9 + 0x2220);
  if (cVar3 == '\0') {
    return -0x16;
  }
  __pm_runtime_resume(*(undefined8 *)(lVar9 + 0x2140),4);
  mutex_lock(enumeration_lock);
  if (uVar2 - 1 < 0xfffffffe) {
    plVar14 = (long *)0x0;
    plVar1 = (long *)(param_1 + 0x3d8);
    iVar11 = -0x16;
    uVar12 = 1;
    do {
      uVar6 = swr_master_read(lVar9,uVar12 * 8 + 0x534);
      uVar7 = swr_master_read(lVar9,uVar12 * 8 + 0x530);
      plVar13 = (long *)*plVar1;
      if (plVar13 != plVar1) {
        uVar6 = uVar7 & 0xffffffff | (uVar6 & 0xffff) << 0x20;
        do {
          if (plVar13[0x75] == uVar6) {
            iVar5 = swr_master_read(lVar9,0x1090);
            *(int *)(lVar9 + 0x23bc) = iVar5;
            if ((iVar5 >> ((uVar12 & 0xf) << 1) & 3U) - 1 < 2) {
              *(char *)(plVar13 + 2) = (char)uVar12;
              if (uVar6 == param_2) {
                *param_3 = (char)uVar12;
                plVar14 = plVar13 + -6;
                _dev_info(*(undefined8 *)(lVar9 + 0x2140),"%s: devnum %d assigned for dev %llx\n",
                          "swrm_get_logical_dev_num",uVar12,plVar13[0x75]);
                iVar11 = 0;
              }
            }
          }
          plVar13 = (long *)*plVar13;
        } while (plVar13 != plVar1);
      }
      bVar4 = uVar12 != uVar2;
      uVar12 = uVar12 + 1;
    } while (bVar4);
    if ((iVar11 == 0) && (plVar14 != (long *)0x0)) {
      if (*(char *)((long)plVar14 + 0x3f1) == '\0') {
        swrm_initialize_clk_base_scale(lVar9,*param_3);
        iVar11 = 0;
      }
      else {
        iVar11 = 0;
      }
      goto LAB_00104abc;
    }
    if (iVar11 == 0) goto LAB_00104abc;
  }
  else {
    iVar11 = -0x16;
  }
  _dev_err(*(undefined8 *)(lVar9 + 0x2140),"%s: device 0x%llx is not ready\n",
           "swrm_get_logical_dev_num",param_2);
LAB_00104abc:
  mutex_unlock(enumeration_lock);
  lVar10 = *(long *)(lVar9 + 0x2140);
  uVar8 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar10 + 0x220) = uVar8;
  __pm_runtime_suspend(*(undefined8 *)(lVar9 + 0x2140),0xd);
  return iVar11;
}



//------------------------------------------------------------
// swrm_init_port_params @ 00104b0c size=412
// signature: undefined swrm_init_port_params(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_init_port_params(long param_1,int param_2,uint param_3,long *param_4)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  undefined8 uVar10;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x98) == 0)) {
    uVar10 = 0;
    puVar4 = &DAT_0010c21c;
  }
  else {
    if (param_2 != 0) {
      if (param_3 != 0) {
        lVar8 = 0;
        uVar5 = param_2 * 0xe - 0xe;
        lVar1 = *(long *)(param_1 + 0x98) + (ulong)uVar5 * 8;
        uVar9 = uVar5;
        do {
          if (0x99 < uVar9) goto LAB_00104ca4;
          lVar7 = lVar1 + lVar8;
          uVar9 = uVar9 + 1;
          *(undefined4 *)(lVar7 + 0x3e4c) = *(undefined4 *)(*param_4 + lVar8);
          lVar2 = *param_4 + lVar8;
          lVar8 = lVar8 + 8;
          *(undefined4 *)(lVar7 + 0x3e50) = *(undefined4 *)(lVar2 + 4);
        } while ((ulong)param_3 * 8 != lVar8);
        if (param_3 != 0) {
          lVar8 = 0;
          lVar7 = (ulong)param_3 * 8;
          puVar6 = (undefined4 *)(lVar1 + 0x4320);
          uVar9 = uVar5;
          do {
            if (0x99 < uVar9) goto LAB_00104ca4;
            uVar9 = uVar9 + 1;
            puVar6[-1] = *(undefined4 *)(param_4[1] + lVar8);
            lVar2 = param_4[1] + lVar8;
            lVar8 = lVar8 + 8;
            *puVar6 = *(undefined4 *)(lVar2 + 4);
            puVar6 = puVar6 + 2;
          } while (lVar7 != lVar8);
          if (param_3 != 0) {
            lVar8 = 0;
            puVar6 = (undefined4 *)(lVar1 + 0x47f0);
            uVar9 = uVar5;
            do {
              if (0x99 < uVar9) goto LAB_00104ca4;
              uVar9 = uVar9 + 1;
              puVar6[-1] = *(undefined4 *)(param_4[2] + lVar8);
              lVar2 = param_4[2] + lVar8;
              lVar8 = lVar8 + 8;
              *puVar6 = *(undefined4 *)(lVar2 + 4);
              puVar6 = puVar6 + 2;
            } while (lVar7 != lVar8);
            if (param_3 != 0) {
              lVar8 = 0;
              puVar6 = (undefined4 *)(lVar1 + 0x4cc0);
              do {
                if (0x99 < uVar5) {
LAB_00104ca4:
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104ca8);
                  (*pcVar3)();
                }
                uVar5 = uVar5 + 1;
                puVar6[-1] = *(undefined4 *)(param_4[3] + lVar8);
                lVar1 = param_4[3] + lVar8;
                lVar8 = lVar8 + 8;
                *puVar6 = *(undefined4 *)(lVar1 + 4);
                puVar6 = puVar6 + 2;
              } while (lVar7 != lVar8);
            }
          }
        }
      }
      return 0;
    }
    uVar10 = 0xffffffea;
    puVar4 = &DAT_0010c0b8;
  }
  _printk(puVar4,"swrm_init_port_params");
  return uVar10;
}



//------------------------------------------------------------
// swrm_connect_port @ 00104cac size=1260
// signature: undefined swrm_connect_port(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int swrm_connect_port(long param_1,undefined1 *param_2)

{
  char *pcVar1;
  long *plVar2;
  long lVar3;
  char *pcVar4;
  long *plVar5;
  ulong *puVar6;
  undefined1 uVar7;
  char cVar8;
  bool bVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  ulong uVar13;
  byte bVar14;
  undefined4 uVar15;
  uint uVar16;
  long *plVar17;
  long lVar18;
  uint uVar19;
  ulong uVar20;
  long lVar21;
  ulong uVar22;
  byte local_70 [4];
  byte local_6c [4];
  long local_68;
  
  lVar21 = sp_el0;
  local_68 = *(long *)(lVar21 + 0x638);
  if (param_1 == 0) {
    if (param_2 != (undefined1 *)0x0) {
LAB_00104d50:
      iVar11 = ___ratelimit(swrm_connect_port__rs,"swrm_connect_port");
      if (iVar11 != 0) {
        _dev_err(param_1,"%s: Invalid handle to swr controller\n","swrm_connect_port");
      }
    }
  }
  else {
    lVar21 = *(long *)(param_1 + 0x98);
    local_6c[0] = 0;
    local_70[0] = 0;
    if (param_2 != (undefined1 *)0x0) {
      if (lVar21 == 0) goto LAB_00104d50;
      lVar3 = lVar21 + 0x2250;
      mutex_lock(lVar3);
      lVar18 = lVar21 + 0x2220;
      mutex_lock(lVar18);
      if (*(char *)(lVar21 + 0x3da4) != '\0') {
        pcVar4 = (char *)(param_1 + 0x20d9);
        mutex_unlock(lVar18);
        if (*pcVar4 == '\0') {
          __pm_runtime_resume(*(undefined8 *)(lVar21 + 0x2140),4);
          bVar14 = 0;
          if (param_2[2] != '\0') goto LAB_00104df4;
        }
        else if (param_2[2] == '\0') {
          bVar14 = 0;
        }
        else {
LAB_00104df4:
          uVar22 = 0;
          do {
            if (uVar22 == 0xe) {
LAB_00105180:
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x105184);
              (*pcVar10)();
            }
            pcVar1 = param_2 + uVar22 + 3;
            iVar11 = swrm_get_master_port(lVar21,local_6c,local_70,param_2[uVar22 + 0x66]);
            bVar14 = local_6c[0];
            if (iVar11 != 0) {
              iVar12 = ___ratelimit(swrm_connect_port__rs_146,"swrm_connect_port");
              if (iVar12 != 0) {
                _dev_err(param_1,"%s: mstr portid for slv port %d not found\n","swrm_connect_port",
                         *pcVar1);
              }
LAB_0010515c:
              swr_port_response(param_1,*param_2);
              swrm_cleanup_disabled_port_reqs(param_1);
              mutex_unlock(lVar3);
              goto LAB_00104da4;
            }
            uVar20 = (ulong)local_6c[0];
            if (0x9a < uVar20) goto LAB_00105180;
            lVar18 = lVar21 + uVar20 * 0x28;
            plVar5 = (long *)(lVar18 + 0x23c0);
            plVar17 = *(long **)(lVar18 + 0x23c0);
            uVar19 = (uint)local_6c[0];
            if (plVar17 != plVar5) {
              do {
                if ((*(char *)((long)plVar17 + -6) == *pcVar1) && ((char)plVar17[-1] == param_2[1]))
                {
                  plVar17 = plVar17 + -1;
                  if (plVar17 != (long *)0x0) goto LAB_00104f98;
                  break;
                }
                plVar17 = (long *)*plVar17;
              } while (plVar17 != plVar5);
            }
            plVar17 = (long *)kmalloc_trace(_system_wq,0xdc0,0x30);
            if (plVar17 == (long *)0x0) {
              iVar11 = -0xc;
              goto LAB_0010515c;
            }
            cVar8 = *pcVar1;
            uVar7 = param_2[uVar22 + 0x11];
            iVar11 = *(int *)(param_2 + uVar22 * 4 + 0x20);
            *(undefined1 *)plVar17 = param_2[1];
            *(char *)((long)plVar17 + 2) = cVar8;
            *(undefined1 *)((long)plVar17 + 0x21) = uVar7;
            *(int *)((long)plVar17 + 0x24) = iVar11;
            *(int *)(plVar17 + 5) = iVar11;
            if (iVar11 < 0x2b110) {
              if (iVar11 == 0xac44) {
                uVar15 = 48000;
              }
              else {
                if (iVar11 != 0x15888) goto LAB_00104f64;
                uVar15 = 96000;
              }
LAB_00104f60:
              *(undefined4 *)((long)plVar17 + 0x24) = uVar15;
            }
            else {
              if (iVar11 == 0x2b110) {
                uVar15 = 0x2ee00;
                goto LAB_00104f60;
              }
              if (iVar11 == 0x56220) {
                uVar15 = 0x5dc00;
                goto LAB_00104f60;
              }
            }
LAB_00104f64:
            *(undefined1 *)((long)plVar17 + 0x1f) = 0;
            plVar2 = plVar17 + 1;
            *(byte *)(plVar17 + 3) = bVar14;
            lVar18 = *plVar5;
            uVar13 = __list_add_valid(plVar2,plVar5,lVar18);
            if ((uVar13 & 1) != 0) {
              *(long **)(lVar18 + 8) = plVar2;
              plVar17[1] = lVar18;
              plVar17[2] = (long)plVar5;
              *plVar5 = (long)plVar2;
            }
LAB_00104f98:
            lVar18 = lVar21 + uVar20 * 0x28;
            *(byte *)(plVar17 + 4) = *(byte *)(plVar17 + 4) | param_2[uVar22 + 0x58];
            *(undefined1 *)(lVar18 + 0x23d0) = 1;
            *(byte *)(lVar18 + 0x23d2) = *(byte *)(lVar18 + 0x23d2) | local_70[0];
            *(ushort *)(param_1 + 0x2138) =
                 *(ushort *)(param_1 + 0x2138) | (ushort)(1 << (ulong)(uVar19 & 0x1f));
            if ((*(int *)(lVar21 + 0x3d68) == 0) || (*(int *)(lVar21 + 0x2364) == 0)) {
              *(undefined4 *)(lVar21 + uVar20 * 0x28 + 0x23e0) =
                   *(undefined4 *)(param_2 + uVar22 * 4 + 0x20);
            }
            else {
              lVar18 = lVar21 + uVar20 * 0x28;
              *(int *)(lVar18 + 0x23e0) =
                   *(int *)(lVar18 + 0x23e0) + *(int *)(param_2 + uVar22 * 4 + 0x20);
              uVar19 = *(int *)(lVar21 + 0x2408) + *(int *)(lVar21 + 0x23e0) +
                       *(int *)(lVar21 + 0x2430) + *(int *)(lVar21 + 0x2458) +
                       *(int *)(lVar21 + 0x2480) + *(int *)(lVar21 + 0x24a8) +
                       *(int *)(lVar21 + 0x24d0) +
                       *(int *)(lVar21 + 0x24f8) + *(int *)(lVar21 + 0x2520) +
                       *(int *)(lVar21 + 0x2548) + *(int *)(lVar21 + 0x2570) +
                       *(int *)(lVar21 + 0x2598) + *(int *)(lVar21 + 0x25c0);
              uVar16 = *(uint *)(lVar21 + 0x23b0);
              if (((uVar19 != 0) && (uVar16 != 0xbb8000)) && (uVar16 != 0xac4400)) {
                if (uVar16 == 9600000) {
                  uVar16 = 600000;
                  if (600000 < (int)uVar19) {
                    uVar15 = 9600000;
                    if (uVar19 < 0x493e01) {
                      uVar15 = 4800000;
                    }
                    *(undefined4 *)(lVar21 + 0x23b4) = uVar15;
                    goto LAB_00104e14;
                  }
                }
                else {
                  uVar16 = uVar19;
                }
              }
              *(uint *)(lVar21 + 0x23b4) = uVar16;
            }
LAB_00104e14:
            bVar14 = param_2[2];
            uVar22 = uVar22 + 1;
          } while (uVar22 < bVar14);
        }
        *pcVar4 = *pcVar4 + bVar14;
        puVar6 = (ulong *)(lVar21 + 0x3be0);
        Hint_Prefetch(puVar6,2,0,1);
        do {
          cVar8 = '\x01';
          bVar9 = (bool)ExclusiveMonitorPass(puVar6,0x10);
          if (bVar9) {
            *puVar6 = *puVar6 | 1;
            cVar8 = ExclusiveMonitorsStatus();
          }
        } while (cVar8 != '\0');
        swr_port_response(param_1,*param_2);
        mutex_unlock(lVar3);
        iVar11 = 0;
        goto LAB_00104da4;
      }
      swr_port_response(param_1,*param_2);
      mutex_unlock(lVar18);
      mutex_unlock(lVar3);
    }
  }
  iVar11 = -0x16;
LAB_00104da4:
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar11;
}



//------------------------------------------------------------
// swrm_disconnect_port @ 001051ac size=1132
// signature: undefined swrm_disconnect_port(void)
// callers: []
//------------------------------------------------------------

void swrm_disconnect_port(long param_1,undefined1 *param_2)

{
  long *plVar1;
  ulong *puVar2;
  byte bVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  uint uVar11;
  ulong uVar12;
  uint uVar13;
  long *plVar14;
  long lVar15;
  long lVar16;
  byte bVar17;
  ulong uVar18;
  byte local_70 [4];
  byte local_6c [4];
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  if (param_1 == 0) {
LAB_001054d4:
    iVar8 = ___ratelimit(swrm_disconnect_port__rs,"swrm_disconnect_port");
    if (iVar8 != 0) {
      pcVar10 = "%s: Invalid handle to swr controller\n";
LAB_001055cc:
      _dev_err(param_1,pcVar10,"swrm_disconnect_port");
    }
  }
  else {
    lVar16 = *(long *)(param_1 + 0x98);
    local_6c[0] = 0;
    local_70[0] = 0;
    if (lVar16 == 0) goto LAB_001054d4;
    if (param_2 != (undefined1 *)0x0) {
      mutex_lock();
      if (param_2[2] == '\0') {
        bVar17 = 0;
      }
      else {
        uVar18 = 0;
        bVar17 = 0;
        do {
          if (uVar18 == 0xe) {
LAB_00105600:
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x105604);
            (*pcVar7)();
          }
          pcVar10 = param_2 + uVar18 + 3;
          iVar8 = swrm_get_master_port(lVar16,local_6c,local_70,param_2[uVar18 + 0x66]);
          if (iVar8 != 0) {
            iVar8 = ___ratelimit(swrm_disconnect_port__rs_152,"swrm_disconnect_port");
            if (iVar8 != 0) {
              _dev_err(param_1,"%s: mstr portid for slv port %d not found\n","swrm_disconnect_port",
                       *pcVar10);
            }
            swr_port_response(param_1,*param_2);
            mutex_unlock(lVar16 + 0x2250);
            goto LAB_001054ec;
          }
          uVar12 = (ulong)local_6c[0];
          if (0x9a < uVar12) goto LAB_00105600;
          lVar15 = lVar16 + uVar12 * 0x28;
          plVar14 = *(long **)(lVar15 + 0x23c0);
          plVar1 = (long *)(lVar15 + 0x23c0);
          if (plVar14 != plVar1) {
            do {
              if ((*(char *)((long)plVar14 + -6) == *pcVar10) && ((char)plVar14[-1] == param_2[1]))
              {
                if (plVar14 != (long *)0x8) {
                  lVar15 = lVar16 + uVar12 * 0x28;
                  *(byte *)(plVar14 + 3) = *(byte *)(plVar14 + 3) & (param_2[uVar18 + 0x58] ^ 0xff);
                  bVar3 = *(byte *)(lVar15 + 0x23d2) & (local_70[0] ^ 0xff);
                  *(byte *)(lVar15 + 0x23d2) = bVar3;
                  if (((*(int *)(lVar16 + 0x3d68) == 0) || (*(int *)(lVar16 + 0x2364) == 0)) ||
                     (bVar3 != 0)) {
                    lVar15 = lVar16 + uVar12 * 0x28;
                    iVar8 = *(int *)(lVar15 + 0x23e0);
                    if ((iVar8 != 0) && (bVar3 != 0)) {
                      *(int *)(lVar15 + 0x23e0) = iVar8 - *(int *)((long)plVar14 + 0x1c);
                      uVar13 = *(int *)(lVar16 + 0x2408) + *(int *)(lVar16 + 0x23e0) +
                               *(int *)(lVar16 + 0x2430) + *(int *)(lVar16 + 0x2458) +
                               *(int *)(lVar16 + 0x2480) + *(int *)(lVar16 + 0x24a8) +
                               *(int *)(lVar16 + 0x24d0) +
                               *(int *)(lVar16 + 0x24f8) + *(int *)(lVar16 + 0x2520) +
                               *(int *)(lVar16 + 0x2548) + *(int *)(lVar16 + 0x2570) +
                               *(int *)(lVar16 + 0x2598) + *(int *)(lVar16 + 0x25c0);
                      uVar11 = *(uint *)(lVar16 + 0x23b0);
                      if ((uVar13 != 0) && ((uVar11 != 0xbb8000 && (uVar11 != 0xac4400)))) {
                        if (uVar11 == 9600000) goto LAB_00105478;
                        uVar11 = uVar13;
                      }
                      goto LAB_001054c8;
                    }
                  }
                  else {
                    *(undefined4 *)(lVar16 + uVar12 * 0x28 + 0x23e0) = 0;
                    uVar13 = *(int *)(lVar16 + 0x2408) + *(int *)(lVar16 + 0x23e0) +
                             *(int *)(lVar16 + 0x2430) + *(int *)(lVar16 + 0x2458) +
                             *(int *)(lVar16 + 0x2480) + *(int *)(lVar16 + 0x24a8) +
                             *(int *)(lVar16 + 0x24d0) +
                             *(int *)(lVar16 + 0x24f8) + *(int *)(lVar16 + 0x2520) +
                             *(int *)(lVar16 + 0x2548) + *(int *)(lVar16 + 0x2570) +
                             *(int *)(lVar16 + 0x2598) + *(int *)(lVar16 + 0x25c0);
                    uVar4 = *(uint *)(lVar16 + 0x23b0);
                    uVar11 = uVar4;
                    if ((((uVar13 != 0) && (uVar4 != 0xbb8000)) && (uVar4 != 0xac4400)) &&
                       (uVar11 = uVar13, uVar4 == 9600000)) {
LAB_00105478:
                      uVar11 = 600000;
                      if (600000 < (int)uVar13) {
                        uVar11 = 9600000;
                        if (uVar13 < 0x493e01) {
                          uVar11 = 4800000;
                        }
                      }
                    }
LAB_001054c8:
                    *(uint *)(lVar16 + 0x23b4) = uVar11;
                  }
                  bVar17 = bVar17 + 1;
                  goto LAB_00105248;
                }
                break;
              }
              plVar14 = (long *)*plVar14;
            } while (plVar14 != plVar1);
          }
          iVar8 = ___ratelimit(swrm_disconnect_port__rs_153,"swrm_disconnect_port");
          if (iVar8 != 0) {
            _dev_err(param_1,"%s:port not enabled : port %d\n","swrm_disconnect_port",*pcVar10);
          }
LAB_00105248:
          uVar18 = uVar18 + 1;
        } while (uVar18 < (byte)param_2[2]);
      }
      cVar5 = '\0';
      if (bVar17 <= *(byte *)(param_1 + 0x20d9)) {
        cVar5 = *(byte *)(param_1 + 0x20d9) - bVar17;
      }
      *(char *)(param_1 + 0x20d9) = cVar5;
      puVar2 = (ulong *)(lVar16 + 0x3be0);
      Hint_Prefetch(puVar2,2,0,1);
      do {
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
        if (bVar6) {
          *puVar2 = *puVar2 | 2;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      swr_port_response(param_1,*param_2);
      mutex_unlock(lVar16 + 0x2250);
      uVar9 = 0;
      goto LAB_001054f0;
    }
    iVar8 = ___ratelimit(swrm_disconnect_port__rs_150,"swrm_disconnect_port");
    if (iVar8 != 0) {
      pcVar10 = "%s: portinfo is NULL\n";
      goto LAB_001055cc;
    }
  }
LAB_001054ec:
  uVar9 = 0xffffffea;
LAB_001054f0:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// swrm_slvdev_datapath_control @ 0010562c size=1504
// signature: undefined swrm_slvdev_datapath_control(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_slvdev_datapath_control(long param_1,ulong param_2)

{
  byte *pbVar1;
  undefined2 *puVar2;
  ulong *puVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  code *pcVar11;
  bool bVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  undefined8 uVar18;
  undefined1 *puVar19;
  int iVar20;
  int iVar21;
  ulong uVar22;
  long lVar23;
  int iVar24;
  long lVar25;
  long lVar26;
  uint uVar27;
  long *plVar28;
  int iVar29;
  
  if ((param_1 == 0) || (lVar26 = *(long *)(param_1 + 0x98), lVar26 == 0)) {
    iVar15 = ___ratelimit(swrm_slvdev_datapath_control__rs,"swrm_slvdev_datapath_control");
    if (iVar15 == 0) {
      return 0xfffffff2;
    }
    _printk(&DAT_0010c58e,"swrm_slvdev_datapath_control");
    return 0xfffffff2;
  }
  mutex_lock(lVar26 + 0x2250);
  if ((*(int *)(lVar26 + 0x3be8) == 4) && ((param_2 & 1) == 0)) {
    if (((uint)*(undefined8 *)(lVar26 + 0x3be0) >> 1 & 1) == 0) goto LAB_00105ad0;
    puVar3 = (ulong *)(lVar26 + 0x3be0);
    Hint_Prefetch(puVar3,2,0,1);
    do {
      cVar10 = '\x01';
      bVar12 = (bool)ExclusiveMonitorPass(puVar3,0x10);
      if (bVar12) {
        *puVar3 = *puVar3 & 0xfffffffffffffffd;
        cVar10 = ExclusiveMonitorsStatus();
      }
    } while (cVar10 != '\0');
    swrm_cleanup_disabled_port_reqs(param_1);
    *(undefined4 *)(lVar26 + 0x3e2c) = 0;
    cVar10 = *(char *)(param_1 + 0x20d9);
  }
  else {
    uVar13 = swr_master_read(lVar26,0x104c);
    uVar4 = uVar13 & 1;
    if ((param_2 & 1) == 0) {
      if (((uint)*(ulong *)(lVar26 + 0x3be0) >> 1 & 1) == 0) goto LAB_00105ad0;
      puVar3 = (ulong *)(lVar26 + 0x3be0);
      Hint_Prefetch(puVar3,2,0,1);
      do {
        cVar10 = '\x01';
        bVar12 = (bool)ExclusiveMonitorPass(puVar3,0x10);
        if (bVar12) {
          *puVar3 = *puVar3 & 0xfffffffffffffffd;
          cVar10 = ExclusiveMonitorsStatus();
        }
      } while (cVar10 != '\0');
      swrm_disable_ports(param_1,(uVar13 & 1) == 0);
      bVar12 = *(char *)(param_1 + 0x20d9) == '\0';
    }
    else {
      if ((*(ulong *)(lVar26 + 0x3be0) & 1) == 0) goto LAB_00105ad0;
      puVar3 = (ulong *)(lVar26 + 0x3be0);
      Hint_Prefetch(puVar3,2,0,1);
      do {
        cVar10 = '\x01';
        bVar12 = (bool)ExclusiveMonitorPass(puVar3,0x10);
        if (bVar12) {
          *puVar3 = *puVar3 & 0xfffffffffffffffe;
          cVar10 = ExclusiveMonitorsStatus();
        }
      } while (cVar10 != '\0');
      iVar15 = *(int *)(lVar26 + 0x235c);
      if ((iVar15 != 3) && (iVar15 != 5)) {
        if ((iVar15 == 2) && (*(char *)(lVar26 + 0x2470) != '\0')) {
          uVar22 = 1;
        }
        else if (iVar15 == 2) {
          uVar22 = (ulong)(*(int *)(lVar26 + 0x23b4) == 0xac4400) << 1;
        }
        else if ((iVar15 == 1) && (*(char *)(lVar26 + 0x23d0) != '\0')) {
          uVar22 = (ulong)(*(int *)(lVar26 + 0x23e0) == 4800000);
        }
        else {
          uVar22 = 0;
        }
        lVar25 = 0;
        puVar19 = (undefined1 *)(lVar26 + 0x23d8);
        lVar23 = *(long *)(*(long *)(lVar26 + 0x3e00) + uVar22 * 8);
        do {
          if (puVar19[-8] != '\0') {
            puVar2 = (undefined2 *)(lVar23 + lVar25);
            *(undefined2 *)(puVar19 + -2) = *puVar2;
            puVar19[-5] = *(undefined1 *)(puVar2 + 1);
            puVar19[-4] = *(undefined1 *)((long)puVar2 + 3);
            *puVar19 = *(undefined1 *)(puVar2 + 2);
            puVar19[1] = *(undefined1 *)((long)puVar2 + 5);
            puVar19[3] = *(undefined1 *)((long)puVar2 + 7);
            puVar19[2] = *(undefined1 *)(puVar2 + 4);
            puVar19[4] = *(undefined1 *)(puVar2 + 3);
            puVar19[5] = *(undefined1 *)((long)puVar2 + 9);
            puVar19[6] = *(undefined1 *)(puVar2 + 5);
            puVar19[7] = *(undefined1 *)((long)puVar2 + 0xb);
          }
          lVar25 = lVar25 + 0xc;
          puVar19 = puVar19 + 0x28;
        } while (lVar25 != 0x9c);
      }
      if (2 < *(uint *)(lVar26 + 0x23ac)) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x105bd0);
        (*pcVar11)();
      }
      lVar25 = (ulong)*(uint *)(lVar26 + 0x23ac) * 4;
      swr_master_write(lVar26,*(undefined4 *)(swrm_registers + lVar25 + 0xc),
                       *(undefined4 *)(swrm_registers + lVar25 + 0x6c));
      lVar25 = *(long *)(param_1 + 0x98);
      if (lVar25 == 0) {
        iVar15 = ___ratelimit(swrm_apply_port_config__rs,"swrm_apply_port_config");
        if (iVar15 != 0) {
          _printk(&DAT_0010c21c,"swrm_apply_port_config");
        }
      }
      else {
        uVar14 = swr_master_read(lVar25,0x104c);
        if (*(int *)(lVar25 + 0x3e30) == 0) {
          cVar10 = *(char *)(lVar25 + 0x235a);
          bVar8 = 0;
          if (cVar10 != '\x0e') {
            bVar8 = cVar10 + 1U & 0xf;
          }
          *(byte *)(lVar25 + 0x235a) = bVar8;
          swrm_cmd_fifo_wr_cmd(lVar25,1,0xf,cVar10,(uVar14 & 1) << 4 ^ 0xf0);
        }
        swrm_copy_data_port_config(param_1,(uVar14 & 1) == 0);
      }
      bVar12 = *(int *)(lVar26 + 0x23b4) == 600000;
    }
    iVar15 = *(int *)(lVar26 + 0x23b0);
    uVar14 = 0;
    if (!bVar12) {
      uVar14 = 7;
    }
    iVar20 = 2;
    if (!bVar12) {
      iVar20 = 0x10;
    }
    if (iVar15 == 0xac4400) {
      iVar24 = 0xe5b;
LAB_0010586c:
      iVar21 = iVar24;
      iVar24 = 0x40;
      iVar29 = 3;
    }
    else {
      iVar21 = 4000;
      iVar24 = 4000;
      if (iVar15 == 0xbb8000) goto LAB_0010586c;
      iVar24 = 0x32;
      iVar29 = 1;
    }
    iVar7 = *(int *)(lVar26 + 0x23b4);
    uVar27 = 0;
    iVar21 = iVar24 * iVar20 * iVar21;
    uVar17 = 0;
    if (iVar21 != 0) {
      uVar17 = (iVar7 << 1) / iVar21;
    }
    if ((iVar15 != 0) && (iVar7 != 0)) {
      iVar20 = 0;
      if (iVar7 != 0) {
        iVar20 = iVar15 / iVar7;
      }
      uVar27 = 0x500;
      switch(iVar20) {
      case 2:
        uVar27 = 0x100;
        break;
      default:
        uVar27 = 0;
        break;
      case 4:
        uVar27 = 0x200;
        break;
      case 8:
        uVar27 = 0x300;
        break;
      case 0x10:
        uVar27 = 0x400;
        break;
      case 0x20:
        break;
      }
    }
    uVar6 = uVar4 << 6 ^ 0x105c;
    uVar16 = swr_master_read(lVar26,uVar6);
    swr_master_write(lVar26,uVar6,
                     uVar16 & 0xff00f800 | uVar14 |
                     (uVar27 | iVar29 << 3 | (uVar17 & 0xff) << 0x10) - 0x10000);
    lVar25 = *(long *)(param_1 + 0x98);
    uVar17 = swr_master_read(lVar25,0x1090);
    plVar28 = *(long **)(param_1 + 0x3d8);
    if (plVar28 != (long *)(param_1 + 0x3d8)) {
      pbVar1 = (byte *)(lVar25 + 0x235a);
      do {
        bVar8 = *(byte *)(plVar28 + 2);
        if (((bVar8 != 0) && ((*(byte *)((long)plVar28 + 0x3ad) & 0x3f) != 0)) &&
           ((uVar17 >> (ulong)((bVar8 & 0xf) << 1) & 3) - 1 < 2)) {
          bVar9 = *pbVar1;
          bVar5 = 0;
          if (bVar9 != 0xe) {
            bVar5 = bVar9 + 1 & 0xf;
          }
          *pbVar1 = bVar5;
          swrm_cmd_fifo_wr_cmd(lVar25,1,bVar8,bVar9,0x4d);
          bVar8 = *pbVar1;
          lVar23 = plVar28[2];
          uVar27 = 0;
          if (*(int *)(lVar25 + 0x23b4) != 0) {
            uVar27 = (*(int *)(lVar25 + 0x23b0) << 1) / *(int *)(lVar25 + 0x23b4);
          }
          uVar6 = (uVar27 & 0xaaaaaaaa) >> 1 | (uVar27 & 0x55555555) << 1;
          uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
          uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
          uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
          iVar15 = 0;
          if (uVar27 != 0) {
            iVar15 = (int)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) + 1;
          }
          bVar5 = 0;
          if (bVar8 != 0xe) {
            bVar5 = bVar8 + 1 & 0xf;
          }
          *pbVar1 = bVar5;
          swrm_cmd_fifo_wr_cmd(lVar25,iVar15,(char)lVar23,bVar8,uVar4 << 4 ^ 0x72);
        }
        plVar28 = (long *)*plVar28;
      } while (plVar28 != (long *)(param_1 + 0x3d8));
    }
    swrm_cmd_fifo_wr_cmd(lVar26,uVar14 | iVar29 << 3,0xf,0xf,uVar4 << 4 ^ 0x70);
    if ((param_2 & 1) == 0) {
      swrm_disable_ports(param_1,(uVar13 & 1) != 0);
      swrm_cleanup_disabled_port_reqs(param_1);
    }
    else {
      swrm_copy_data_port_config();
    }
    cVar10 = *(char *)(param_1 + 0x20d9);
  }
  if (cVar10 == '\0') {
    lVar25 = *(long *)(lVar26 + 0x2140);
    uVar18 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar25 + 0x220) = uVar18;
    __pm_runtime_suspend(*(undefined8 *)(lVar26 + 0x2140),0xd);
  }
LAB_00105ad0:
  mutex_unlock(lVar26 + 0x2250);
  return 0;
}



//------------------------------------------------------------
// swrm_remove_from_group @ 00105c40 size=156
// signature: undefined swrm_remove_from_group(void)
// callers: []
//------------------------------------------------------------

bool swrm_remove_from_group(long param_1)

{
  long *plVar1;
  bool bVar2;
  long lVar3;
  
  if (param_1 == 0) {
    bVar2 = false;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x98);
    bVar2 = false;
    if (lVar3 != 0) {
      mutex_lock(lVar3 + 0x2250);
      bVar2 = 1 < *(int *)(lVar3 + 0x3bf8);
      if (1 < *(int *)(lVar3 + 0x3bf8)) {
        plVar1 = *(long **)(param_1 + 0x3d8);
        if (plVar1 != (long *)(param_1 + 0x3d8)) {
          do {
            *(undefined1 *)(plVar1 + 0x76) = 0;
            *(undefined1 *)(param_1 + 0x20db) = 0;
            plVar1 = (long *)*plVar1;
          } while (plVar1 != (long *)(param_1 + 0x3d8));
        }
      }
      mutex_unlock(lVar3 + 0x2250);
    }
  }
  return bVar2;
}



//------------------------------------------------------------
// swrm_device_wakeup_vote @ 00105ce0 size=316
// signature: undefined swrm_device_wakeup_vote(void)
// callers: []
//------------------------------------------------------------

void swrm_device_wakeup_vote(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0x98), lVar3 == 0)) {
    iVar1 = ___ratelimit(swrm_device_wakeup_vote__rs,"swrm_device_wakeup_vote");
    if (iVar1 != 0) {
      _printk(&DAT_0010c21c,"swrm_device_wakeup_vote");
    }
  }
  else {
    uVar2 = swrm_lock_sleep(lVar3);
    if ((uVar2 & 1) == 0) {
      iVar1 = ___ratelimit(swrm_device_wakeup_vote__rs_159,"swrm_device_wakeup_vote");
      if (iVar1 != 0) {
        _dev_err(*(undefined8 *)(lVar3 + 0x2140),"%s Failed to hold suspend\n",
                 "swrm_device_wakeup_vote");
      }
    }
    else {
      iVar1 = swrm_request_hw_vote(lVar3,0,1);
      if ((iVar1 != 0) &&
         (iVar1 = ___ratelimit(swrm_device_wakeup_vote__rs_160,"swrm_device_wakeup_vote"),
         iVar1 != 0)) {
        _dev_err(*(undefined8 *)(lVar3 + 0x2140),"%s:lpass core hw enable failed\n",
                 "swrm_device_wakeup_vote");
      }
      iVar1 = swrm_request_hw_vote(lVar3,1,1);
      if ((iVar1 != 0) &&
         (iVar1 = ___ratelimit(swrm_device_wakeup_vote__rs_161,"swrm_device_wakeup_vote"),
         iVar1 != 0)) {
        _dev_err(*(undefined8 *)(lVar3 + 0x2140),"%s:lpass audio hw enable failed\n",
                 "swrm_device_wakeup_vote");
      }
      __pm_runtime_resume(*(undefined8 *)(lVar3 + 0x2140),4);
    }
  }
  return;
}



//------------------------------------------------------------
// swrm_device_wakeup_unvote @ 00105e20 size=348
// signature: undefined swrm_device_wakeup_unvote(void)
// callers: []
//------------------------------------------------------------

void swrm_device_wakeup_unvote(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if ((param_1 == 0) || (lVar4 = *(long *)(param_1 + 0x98), lVar4 == 0)) {
    iVar1 = ___ratelimit(swrm_device_wakeup_unvote__rs,"swrm_device_wakeup_unvote");
    if (iVar1 != 0) {
      _printk(&DAT_0010c21c,"swrm_device_wakeup_unvote");
    }
  }
  else {
    lVar3 = *(long *)(lVar4 + 0x2140);
    uVar2 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar3 + 0x220) = uVar2;
    __pm_runtime_suspend(*(undefined8 *)(lVar4 + 0x2140),0xd);
    lVar3 = lVar4 + 0x2220;
    mutex_lock(lVar3);
    if (*(long *)(lVar4 + 0x3e10) != 0) {
      iVar1 = *(int *)(lVar4 + 0x3e24) + -1;
      *(int *)(lVar4 + 0x3e24) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(lVar4 + 0x3e24) = 0;
      }
      else if (iVar1 == 0) {
        digital_cdc_rsc_mgr_hw_vote_disable
                  (*(long *)(lVar4 + 0x3e10),*(undefined8 *)(lVar4 + 0x2140));
      }
    }
    mutex_unlock(lVar3);
    mutex_lock(lVar3);
    if (*(long *)(lVar4 + 0x3e08) != 0) {
      iVar1 = *(int *)(lVar4 + 0x3e20) + -1;
      *(int *)(lVar4 + 0x3e20) = iVar1;
      if (iVar1 < 0) {
        *(undefined4 *)(lVar4 + 0x3e20) = 0;
      }
      else if (iVar1 == 0) {
        digital_cdc_rsc_mgr_hw_vote_disable
                  (*(long *)(lVar4 + 0x3e08),*(undefined8 *)(lVar4 + 0x2140));
      }
    }
    mutex_unlock(lVar3);
    mutex_lock(lVar4 + 0x22b0);
    iVar1 = *(int *)(lVar4 + 0x3df8) + -1;
    *(int *)(lVar4 + 0x3df8) = iVar1;
    if (iVar1 == 0) {
      if (*(int *)(lVar4 + 0x3dd8) == 1) {
        *(undefined4 *)(lVar4 + 0x3dd8) = 0;
      }
      cpu_latency_qos_update_request(lVar4 + 0x3da8,0xffffffff);
      pm_relax(*(undefined8 *)(lVar4 + 0x2140));
    }
    mutex_unlock(lVar4 + 0x22b0);
    __wake_up(lVar4 + 0x3de0,3,0,0);
  }
  return;
}



//------------------------------------------------------------
// swr_mstr_interrupt @ 00105f80 size=2844
// signature: undefined swr_mstr_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined4 swr_mstr_interrupt(undefined8 param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  byte *pbVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 uVar14;
  char *pcVar15;
  int iVar16;
  uint uVar17;
  undefined4 uVar18;
  long *plVar19;
  uint uVar20;
  uint uVar21;
  long lVar22;
  uint local_a4;
  undefined4 local_84;
  undefined8 local_80;
  undefined6 uStack_78;
  undefined2 local_72;
  undefined6 uStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_84 = 0;
  uVar13 = swrm_lock_sleep(param_2);
  if ((uVar13 & 1) == 0) {
    iVar8 = ___ratelimit(swr_mstr_interrupt__rs,"swr_mstr_interrupt");
    if (iVar8 == 0) {
      uVar18 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(param_2 + 0x2140),"%s Failed to hold suspend\n","swr_mstr_interrupt")
      ;
      uVar18 = 0;
    }
  }
  else {
    lVar2 = param_2 + 0x2280;
    mutex_lock(lVar2);
    iVar8 = swrm_request_hw_vote(param_2,0,1);
    uVar18 = 0;
    if (iVar8 == 0) {
      iVar8 = swrm_request_hw_vote(param_2,1,1);
      if (iVar8 == 0) {
        iVar8 = swrm_clk_request(param_2,1);
        if (iVar8 == 0) {
          mutex_unlock(lVar2);
          if (*(uint *)(param_2 + 0x23ac) < 3) {
            local_a4 = swr_master_read(param_2,*(undefined4 *)
                                                (swrm_registers +
                                                (ulong)*(uint *)(param_2 + 0x23ac) * 4));
            uVar9 = *(uint *)(param_2 + 0x23ac);
            if (uVar9 < 3) {
              pbVar3 = (byte *)(param_2 + 0x235a);
              uVar18 = 0;
              iVar8 = 5;
              uVar21 = *(uint *)(param_2 + 0x3dfc) & local_a4;
              plVar1 = (long *)(param_2 + 0x3d8);
              do {
                uVar20 = 0;
                while( true ) {
                  uVar13 = (ulong)uVar9;
                  if (5 < uVar13) goto LAB_00106a70;
                  if (*(uint *)(swrm_registers + uVar13 * 4 + 0x60) <= uVar20) break;
                  uVar9 = 1 << (ulong)(uVar20 & 0x1f) & uVar21;
                  if ((int)uVar9 < 0x200) {
                    switch(uVar9) {
                    case 0:
                    case 2:
                      break;
                    case 1:
                      uVar9 = swr_master_read(param_2,0x1090);
                      if (*(int *)(param_2 + 0x23b8) != -1) {
                        uVar12 = 0;
LAB_00106174:
                        if ((uVar9 & 3) != 2) goto code_r0x00106180;
                        bVar5 = *pbVar3;
                        bVar4 = 0;
                        if (bVar5 != 0xe) {
                          bVar4 = bVar5 + 1 & 0xf;
                        }
                        *pbVar3 = bVar4;
                        swrm_cmd_fifo_rd_cmd(param_2,&local_84,uVar12,bVar5,0x40,1);
                        bVar5 = *pbVar3;
                        bVar4 = 0;
                        if (bVar5 != 0xe) {
                          bVar4 = bVar5 + 1 & 0xf;
                        }
                        *pbVar3 = bVar4;
                        swrm_cmd_fifo_wr_cmd(param_2,4,uVar12,bVar5,0x40);
                        bVar5 = *pbVar3;
                        bVar4 = 0;
                        if (bVar5 != 0xe) {
                          bVar4 = bVar5 + 1 & 0xf;
                        }
                        *pbVar3 = bVar4;
                        swrm_cmd_fifo_wr_cmd(param_2,0,uVar12,bVar5,0x40);
                        for (plVar19 = *(long **)(param_2 + 0x3d8); plVar19 != plVar1;
                            plVar19 = (long *)*plVar19) {
                          if (((uint)*(byte *)(plVar19 + 2) == (uVar12 & 0xff)) &&
                             (plVar19[0x77] != 0)) {
                            do {
                              *(undefined1 *)(plVar19 + 0x78) = 0;
                              local_80 = local_80 & 0xffffffff00000000;
                              lVar22 = __irq_resolve_mapping(plVar19[0x77],0,&local_80);
                              uVar18 = 0;
                              if (lVar22 != 0) {
                                uVar18 = (undefined4)local_80;
                              }
                              handle_nested_irq(uVar18);
                            } while (((char)plVar19[0x78] != '\0') &&
                                    (*(char *)(param_2 + 0x3da4) != '\0'));
                          }
                        }
                        goto LAB_001066b0;
                      }
LAB_00106190:
                      iVar11 = ___ratelimit(swr_mstr_interrupt__rs_165,"swr_mstr_interrupt");
                      if (iVar11 == 0) {
                        uVar18 = 0xffffffea;
                      }
                      else {
                        _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                 "%s: no slave alert found.spurious interrupt\n",
                                 "swr_mstr_interrupt");
                        uVar18 = 0xffffffea;
                      }
                      break;
                    case 3:
                    case 5:
                    case 6:
                    case 7:
                    case 9:
                    case 10:
                    case 0xb:
                    case 0xc:
                    case 0xd:
                    case 0xe:
                    case 0xf:
                    case 0x11:
                    case 0x12:
                    case 0x13:
                    case 0x14:
                    case 0x15:
                    case 0x16:
                    case 0x17:
                    case 0x18:
                    case 0x19:
                    case 0x1a:
                    case 0x1b:
                    case 0x1c:
                    case 0x1d:
                    case 0x1e:
                    case 0x1f:
                    case 0x21:
                    case 0x22:
                    case 0x23:
                    case 0x24:
                    case 0x25:
                    case 0x26:
                    case 0x27:
                    case 0x28:
                    case 0x29:
                    case 0x2a:
                    case 0x2b:
                    case 0x2c:
                    case 0x2d:
                    case 0x2e:
                    case 0x2f:
                    case 0x30:
                    case 0x31:
                    case 0x32:
                    case 0x33:
                    case 0x34:
                    case 0x35:
                    case 0x36:
                    case 0x37:
                    case 0x38:
                    case 0x39:
                    case 0x3a:
                    case 0x3b:
                    case 0x3c:
                    case 0x3d:
                    case 0x3e:
                    case 0x3f:
switchD_00106150_caseD_3:
                      iVar11 = ___ratelimit(swr_mstr_interrupt__rs_184,"swr_mstr_interrupt");
                      if (iVar11 != 0) {
                        _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                 "%s: SWR unknown interrupt value: %d\n","swr_mstr_interrupt",uVar9)
                        ;
                      }
LAB_001066b0:
                      uVar18 = 0;
                      break;
                    case 4:
                      mutex_lock(enumeration_lock);
                      swrm_enable_slave_irq(param_2);
                      iVar11 = swr_master_read(param_2,0x1090);
                      if (iVar11 == *(int *)(param_2 + 0x23bc)) {
                        if (*(int *)(param_2 + 0x235c) == 3) {
                          for (plVar19 = (long *)*plVar1; plVar19 != plVar1;
                              plVar19 = (long *)*plVar19) {
                            swr_reset_device(plVar19 + -6);
                          }
                        }
                      }
                      else {
                        uStack_70 = 0;
                        local_80 = 0;
                        uStack_78 = 0;
                        local_72 = 0;
                        uVar12 = swr_master_read(param_2,0x1090);
                        uVar9 = *(uint *)(param_2 + 0x23bc);
                        if (uVar12 != uVar9) {
                          iVar11 = *(int *)(param_2 + 0x23b8);
                          if (iVar11 == -1) {
                            *(uint *)(param_2 + 0x23bc) = uVar12;
                          }
                          else {
                            uVar13 = 0;
                            iVar16 = 0;
                            uVar17 = uVar12;
                            do {
                              if ((uVar17 & 3) != (uVar9 & 3)) {
                                if (((10 < (uint)uVar13) ||
                                    (*(char *)((long)&local_80 + uVar13 * 2) = (char)iVar16,
                                    0x16 < (uVar13 << 1 | 1))) || (0x16 < (uVar13 << 1 | 1)))
                                goto LAB_00106a70;
                                lVar22 = uVar13 * 2;
                                uVar13 = (ulong)((uint)uVar13 + 1);
                                *(char *)((long)&local_80 + lVar22 + 1) = (char)(uVar17 & 3);
                              }
                              uVar17 = (int)uVar17 >> 2;
                              uVar9 = (int)uVar9 >> 2;
                              iVar16 = iVar16 + 1;
                            } while (iVar11 + 1 != iVar16);
                            *(uint *)(param_2 + 0x23bc) = uVar12;
                            if ((int)uVar13 != 0) {
                              lVar22 = 0;
                              do {
                                if (lVar22 == 0x16) goto LAB_00106a74;
                                if ((0x16 < lVar22 + 1U) || (lVar22 == 0x16)) goto LAB_00106a70;
                                cVar6 = *(char *)((long)&local_80 + lVar22 + 1);
                                if (cVar6 == '\x01') {
                                  swrm_initialize_clk_base_scale(param_2);
LAB_001066d8:
                                  *(undefined1 *)(param_2 + 0x3e40) = 1;
                                }
                                else if ((cVar6 == '\0') &&
                                        (*(char *)((long)&local_80 + lVar22) == '\0'))
                                goto LAB_001066d8;
                                lVar22 = lVar22 + 2;
                              } while (uVar13 * 2 != lVar22);
                            }
                          }
                        }
                      }
                      mutex_unlock(enumeration_lock);
                      break;
                    case 8:
                      iVar11 = ___ratelimit(swr_mstr_interrupt__rs_167,"swr_mstr_interrupt");
                      if (iVar11 != 0) {
                        _dev_err(*(undefined8 *)(param_2 + 0x2140),"%s: SWR bus clsh detected\n",
                                 "swr_mstr_interrupt");
                      }
                      uVar13 = (ulong)*(uint *)(param_2 + 0x23ac);
                      uVar9 = *(uint *)(param_2 + 0x3dfc) & 0xfffffff7;
LAB_001063a8:
                      *(uint *)(param_2 + 0x3dfc) = uVar9;
                      if (2 < (uint)uVar13) goto LAB_00106a74;
LAB_00106498:
                      swr_master_write(param_2,*(undefined4 *)(swrm_registers + uVar13 * 4 + 0xc));
                      break;
                    case 0x10:
switchD_00106150_caseD_10:
                      if (0xb < uVar13) goto LAB_00106a70;
                      uVar10 = swr_master_read(param_2,*(undefined4 *)
                                                        (swrm_registers + uVar13 * 4 + 0x48));
                      iVar11 = ___ratelimit(swr_mstr_interrupt__rs_169,"swr_mstr_interrupt");
                      if (iVar11 != 0) {
                        uVar14 = *(undefined8 *)(param_2 + 0x2140);
                        pcVar15 = "%s: SWR read FIFO overflow fifo status %x\n";
LAB_00106438:
                        _dev_err(uVar14,pcVar15,"swr_mstr_interrupt",uVar10);
                      }
                      break;
                    case 0x20:
switchD_00106150_caseD_20:
                      if ((uVar9 == 0x80000) && (0x1ffffff < *(int *)(param_2 + 0x23a8))) {
                        if (0xb < uVar13) goto LAB_00106a70;
                        uVar10 = swr_master_read(param_2,*(undefined4 *)
                                                          (swrm_registers + uVar13 * 4 + 0x48));
                        iVar11 = ___ratelimit(swr_mstr_interrupt__rs_171,"swr_mstr_interrupt");
                        if (iVar11 != 0) {
                          _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                   "%s: SWR CMD Ignored, fifo status 0x%x\n","swr_mstr_interrupt",
                                   uVar10);
                        }
                        usleep_range_state(0xdac,0xdb1,2);
                      }
                      else {
                        if (0xb < uVar13) goto LAB_00106a70;
                        uVar10 = swr_master_read(param_2,*(undefined4 *)
                                                          (swrm_registers + uVar13 * 4 + 0x48));
                        iVar11 = ___ratelimit(swr_mstr_interrupt__rs_173,"swr_mstr_interrupt");
                        if (iVar11 != 0) {
                          uVar14 = *(undefined8 *)(param_2 + 0x2140);
                          pcVar15 = "%s: SWR read FIFO underflow fifo status %x\n";
                          goto LAB_00106438;
                        }
                      }
                      break;
                    case 0x40:
                      if (0xb < uVar13) goto LAB_00106a70;
                      uVar10 = swr_master_read(param_2,*(undefined4 *)
                                                        (swrm_registers + uVar13 * 4 + 0x48));
                      iVar11 = ___ratelimit(swr_mstr_interrupt__rs_175,"swr_mstr_interrupt");
                      if (iVar11 != 0) {
                        uVar14 = *(undefined8 *)(param_2 + 0x2140);
                        pcVar15 = "%s: SWR write FIFO overflow fifo status %x\n";
                        goto LAB_00106438;
                      }
                      break;
                    default:
                      if (uVar9 != 0x80) {
                        if (uVar9 == 0x100) {
                          iVar11 = ___ratelimit(swr_mstr_interrupt__rs_179,"swr_mstr_interrupt");
                          if (iVar11 != 0) {
                            _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                     "%s: SWR Port collision detected\n","swr_mstr_interrupt");
                          }
                          uVar13 = (ulong)*(uint *)(param_2 + 0x23ac);
                          uVar9 = *(uint *)(param_2 + 0x3dfc) & 0xfffffeff;
                          goto LAB_001063a8;
                        }
                        goto switchD_00106150_caseD_3;
                      }
                      if (0xb < uVar13) goto LAB_00106a70;
                      uVar10 = swr_master_read(param_2,*(undefined4 *)
                                                        (swrm_registers + uVar13 * 4 + 0x48));
                      iVar11 = ___ratelimit(swr_mstr_interrupt__rs_177,"swr_mstr_interrupt");
                      if (iVar11 != 0) {
                        _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                 "%s: SWR CMD error, fifo status 0x%x, flushing fifo\n",
                                 "swr_mstr_interrupt",uVar10);
                      }
                      uVar14 = 0x308;
LAB_001064e8:
                      swr_master_write(param_2,uVar14,1);
                    }
                  }
                  else if ((int)uVar9 < 0x4000) {
                    if ((int)uVar9 < 0x800) {
                      if (uVar9 == 0x200) {
                        *(uint *)(param_2 + 0x3dfc) = *(uint *)(param_2 + 0x3dfc) & 0xfffffdff;
                        if (uVar13 < 0x1b) goto LAB_00106498;
                        goto LAB_00106a70;
                      }
                      if (uVar9 != 0x400) goto switchD_00106150_caseD_3;
LAB_001060d4:
                      complete(param_2 + 0x21a0);
                    }
                    else {
                      if (uVar9 == 0x800) {
                        swr_master_write(param_2,0x500,0);
                        iVar8 = iVar8 + 1;
                        do {
                          iVar11 = swr_master_read(param_2,0x504);
                          iVar8 = iVar8 + -1;
                          if (iVar11 == 0) break;
                        } while (iVar8 != 0);
                        uVar14 = 0x500;
                        goto LAB_001064e8;
                      }
                      if (uVar9 != 0x1000) {
                        if (uVar9 != 0x2000) goto switchD_00106150_caseD_3;
                        swrm_check_link_status(param_2,1);
                      }
                    }
                  }
                  else {
                    if (0x3ffff < (int)uVar9) {
                      if (uVar9 == 0x40000) goto switchD_00106150_caseD_10;
                      if (uVar9 == 0x80000) goto switchD_00106150_caseD_20;
                      if (uVar9 == 0x100000) goto LAB_001060d4;
                      goto switchD_00106150_caseD_3;
                    }
                    if (uVar9 != 0x4000) {
                      if (uVar9 != 0x10000) {
                        if (uVar9 == 0x20000) {
                          _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                   "%s: SWR Port Channel rate mismatch\n","swr_mstr_interrupt");
                          uVar13 = (ulong)*(uint *)(param_2 + 0x23ac);
                          uVar9 = *(uint *)(param_2 + 0x3dfc) & 0xfffdffff;
                          goto LAB_001063a8;
                        }
                        goto switchD_00106150_caseD_3;
                      }
                      if (*(int *)(param_2 + 0x3be8) != 2) {
                        iVar11 = ___ratelimit(swr_mstr_interrupt__rs_181,"swr_mstr_interrupt");
                        if (iVar11 != 0) {
                          _dev_err(*(undefined8 *)(param_2 + 0x2140),
                                   "%s: SWR wokeup during clock stop\n","swr_mstr_interrupt");
                        }
                        *(undefined1 *)(param_2 + 0x3e48) = 1;
                        swrm_enable_slave_irq(param_2);
                        *(undefined1 *)(param_2 + 0x3e48) = 0;
                      }
                    }
                  }
                  uVar9 = *(uint *)(param_2 + 0x23ac);
                  uVar20 = uVar20 + 1;
                  if (2 < uVar9) goto LAB_00106a74;
                }
                if (0x17 < uVar13) {
LAB_00106a70:
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(1,0x106a74);
                  (*pcVar7)();
                }
                swr_master_write(param_2,*(undefined4 *)(swrm_registers + uVar13 * 4 + 0x18),
                                 local_a4);
                if (2 < *(uint *)(param_2 + 0x23ac)) break;
                swr_master_write(param_2,*(undefined4 *)
                                          (swrm_registers +
                                          (ulong)*(uint *)(param_2 + 0x23ac) * 4 + 0x18),0);
                if (*(char *)(param_2 + 0x3e40) != '\0') {
                  mutex_lock(enumeration_lock);
                  swrm_enable_slave_irq(param_2);
                  *(undefined1 *)(param_2 + 0x3e40) = 0;
                  mutex_unlock(enumeration_lock);
                }
                if (2 < *(uint *)(param_2 + 0x23ac)) break;
                local_a4 = swr_master_read(param_2,*(undefined4 *)
                                                    (swrm_registers +
                                                    (ulong)*(uint *)(param_2 + 0x23ac) * 4));
                uVar21 = *(uint *)(param_2 + 0x3dfc) & local_a4;
                if ((uVar21 == 0) ||
                   ((*(int *)(*(long *)(param_2 + 0x2140) + 0x20c) == 2 &&
                    ((*(ushort *)(*(long *)(param_2 + 0x2140) + 0x200) & 7) == 0)))) {
                  mutex_lock(lVar2);
                  swrm_clk_request(param_2,0);
                  goto LAB_001068fc;
                }
                uVar9 = *(uint *)(param_2 + 0x23ac);
              } while (uVar9 < 3);
            }
          }
LAB_00106a74:
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x106a78);
          (*pcVar7)();
        }
        iVar8 = ___ratelimit(swr_mstr_interrupt__rs_163,"swr_mstr_interrupt");
        if (iVar8 == 0) {
          uVar18 = 0;
        }
        else {
          _dev_err(param_2,"%s: swrm clk failed\n","swr_mstr_interrupt");
          uVar18 = 0;
        }
LAB_001068fc:
        mutex_lock(param_2 + 0x2220);
        if (*(long *)(param_2 + 0x3e10) != 0) {
          iVar8 = *(int *)(param_2 + 0x3e24) + -1;
          *(int *)(param_2 + 0x3e24) = iVar8;
          if (iVar8 < 0) {
            *(undefined4 *)(param_2 + 0x3e24) = 0;
          }
          else if (iVar8 == 0) {
            digital_cdc_rsc_mgr_hw_vote_disable
                      (*(long *)(param_2 + 0x3e10),*(undefined8 *)(param_2 + 0x2140));
          }
        }
        mutex_unlock(param_2 + 0x2220);
      }
      else {
        uVar18 = 0;
      }
      mutex_lock(param_2 + 0x2220);
      if (*(long *)(param_2 + 0x3e08) != 0) {
        iVar8 = *(int *)(param_2 + 0x3e20) + -1;
        *(int *)(param_2 + 0x3e20) = iVar8;
        if (iVar8 < 0) {
          *(undefined4 *)(param_2 + 0x3e20) = 0;
        }
        else if (iVar8 == 0) {
          digital_cdc_rsc_mgr_hw_vote_disable
                    (*(long *)(param_2 + 0x3e08),*(undefined8 *)(param_2 + 0x2140));
        }
      }
      mutex_unlock(param_2 + 0x2220);
    }
    mutex_unlock(lVar2);
    mutex_lock(param_2 + 0x22b0);
    iVar8 = *(int *)(param_2 + 0x3df8) + -1;
    *(int *)(param_2 + 0x3df8) = iVar8;
    if (iVar8 == 0) {
      if (*(int *)(param_2 + 0x3dd8) == 1) {
        *(undefined4 *)(param_2 + 0x3dd8) = 0;
      }
      cpu_latency_qos_update_request(param_2 + 0x3da8,0xffffffff);
      pm_relax(*(undefined8 *)(param_2 + 0x2140));
    }
    mutex_unlock(param_2 + 0x22b0);
    __wake_up(param_2 + 0x3de0,3,0,0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar18;
code_r0x00106180:
  uVar9 = (int)uVar9 >> 2;
  uVar12 = uVar12 + 1;
  if (*(int *)(param_2 + 0x23b8) + 1U == uVar12) goto LAB_00106190;
  goto LAB_00106174;
}



//------------------------------------------------------------
// swrm_master_init @ 00106a9c size=876
// signature: undefined swrm_master_init(void)
// callers: [swrm_runtime_resume, swrm_probe]
//------------------------------------------------------------

void swrm_master_init(long param_1)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  ulong uVar9;
  ulong uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  uint local_b8 [4];
  uint local_a8 [8];
  undefined8 local_88;
  undefined8 local_80;
  uint local_78 [8];
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  iVar7 = *(int *)(param_1 + 0x235c);
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  uVar11 = 3;
  if (iVar7 == 1) {
    uVar11 = 1;
  }
  if ((0x105ffff < *(int *)(param_1 + 0x23a8)) && (*(long *)(param_1 + 0x2350) != 0)) {
    uVar4 = readl();
    writel(uVar4 & 0xfffffffd,*(undefined8 *)(param_1 + 0x2350));
    usleep_range_state(500,0x1f9,2);
    readl(*(undefined8 *)(param_1 + 0x2350));
    iVar7 = *(int *)(param_1 + 0x235c);
  }
  uVar4 = 0x18;
  if (iVar7 != 5) {
    uVar4 = 8;
  }
  if (param_1 == 0) {
    local_b8[0] = 0;
  }
  else {
    iVar8 = 0x7d000;
    if (iVar7 != 5) {
      iVar8 = 400000;
    }
    uVar2 = 0;
    if (iVar8 != 0) {
      uVar2 = (*(int *)(param_1 + 0x23b4) << 1) / iVar8;
    }
    local_b8[0] = (uVar2 & 0xff) * 0x10000 - 0x10000;
  }
  local_b8[0] = local_b8[0] | uVar4;
  local_88 = 0x5000000101c;
  local_b8[1] = 1;
  local_b8[2] = swr_master_read(param_1,0x1048);
  iVar7 = *(int *)(param_1 + 0x23a8);
  local_b8[2] = local_b8[2] | 0x3e0000;
  local_80 = 0x31400001048;
  if (iVar7 < 0x1070000) {
    uVar9 = 4;
  }
  else {
    uVar9 = 5;
    local_78[0] = 0x18;
    local_a8[0] = *(undefined4 *)(param_1 + 0x2360);
  }
  uVar10 = uVar9;
  if (*(int *)(param_1 + 0x235c) == 5) {
    uVar10 = (ulong)((int)uVar9 + 1);
    local_a8[uVar9 + 8] = 0x714;
    local_b8[uVar9] = 1;
  }
  uVar9 = uVar10;
  if (iVar7 < 0x1070001) {
    local_a8[uVar10 + 8] = 0x1044;
    uVar9 = (ulong)((int)uVar10 + 1);
    uVar4 = 2;
    if (iVar7 == 0x1070000) {
      uVar4 = 2 << (ulong)(*(uint *)(param_1 + 0x2360) & 0x1f);
    }
    local_b8[uVar10] = uVar4;
  }
  uVar4 = *(uint *)(param_1 + 0x23ac);
  local_a8[uVar9 + 8] = 4;
  local_b8[uVar9] = 2;
  local_b8[3] = uVar11;
  if (2 < uVar4) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x106e04);
    (*pcVar3)();
  }
  lVar1 = (ulong)uVar4 * 4;
  iVar8 = (int)uVar9;
  uVar10 = (ulong)(iVar8 + 4);
  uVar4 = *(uint *)(swrm_registers + lVar1 + 0x6c);
  uVar2 = *(uint *)(swrm_registers + lVar1 + 0x18);
  local_b8[iVar8 + 1] = 0xffffffff;
  local_a8[(ulong)(iVar8 + 1) + 8] = uVar2;
  *(uint *)(param_1 + 0x3dfc) = uVar4;
  uVar2 = *(uint *)(swrm_registers + lVar1 + 0xc);
  local_b8[iVar8 + 2] = uVar4;
  local_a8[(ulong)(iVar8 + 2) + 8] = uVar2;
  local_a8[(ulong)(iVar8 + 3) + 8] = 4;
  local_b8[iVar8 + 3] = 3;
  uVar9 = uVar10;
  if (0x1ffffff < iVar7) {
    uVar9 = (ulong)(iVar8 + 5);
    local_a8[uVar10 + 8] = *(int *)(param_1 + 0x2360) * 0x1000 + 0x4060;
    local_b8[uVar10] = 1;
  }
  swr_master_bulk_write(param_1,&local_88,local_b8,uVar9);
  uVar10 = swrm_check_link_status(param_1,1);
  if ((uVar10 & 1) == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: swr link failed to connect\n","swrm_master_init"
            );
    puVar12 = &local_88;
    do {
      usleep_range_state(0x32,0x37,2);
      uVar11 = *(undefined4 *)puVar12;
      uVar6 = *(undefined8 *)(param_1 + 0x2140);
      uVar5 = swr_master_read(param_1,uVar11);
      _dev_err(uVar6,"%s:reg:0x%x val:0x%x\n","swrm_master_init",uVar11,uVar5);
      uVar9 = uVar9 - 1;
      uVar6 = 0xffffffea;
      puVar12 = (undefined8 *)((long)puVar12 + 4);
    } while (uVar9 != 0);
  }
  else {
    if (0x1050000 < *(int *)(param_1 + 0x23a8)) {
      uVar4 = swr_master_read(param_1,0x314);
      swr_master_write(param_1,0x314,uVar4 | 0x80000000);
    }
    uVar6 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// swrm_wakeup_work @ 00106e0c size=316
// signature: undefined swrm_wakeup_work(void)
// callers: []
//------------------------------------------------------------

void swrm_wakeup_work(long param_1)

{
  long *plVar1;
  char cVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  
  if ((param_1 + -0x3d70 == 0) || (plVar1 = (long *)(param_1 + -0x1c30), *plVar1 == 0)) {
    _printk(&DAT_0010bc54,"swrm_wakeup_work");
    return;
  }
  mutex_lock(param_1 + -0x1b50);
  cVar2 = *(char *)(param_1 + 0x34);
  mutex_unlock(param_1 + -0x1b50);
  if (cVar2 != '\0') {
    uVar4 = swrm_lock_sleep(param_1 + -0x3d70);
    if ((uVar4 & 1) == 0) {
      _dev_err(*plVar1,"%s Failed to hold suspend\n","swrm_wakeup_work");
    }
    else {
      __pm_runtime_resume(*plVar1,4);
      lVar6 = *plVar1;
      uVar5 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar6 + 0x220) = uVar5;
      __pm_runtime_suspend(*plVar1,0xd);
      mutex_lock(param_1 + -0x1ac0);
      iVar3 = *(int *)(param_1 + 0x88) + -1;
      *(int *)(param_1 + 0x88) = iVar3;
      if (iVar3 == 0) {
        if (*(int *)(param_1 + 0x68) == 1) {
          *(undefined4 *)(param_1 + 0x68) = 0;
        }
        cpu_latency_qos_update_request(param_1 + 0x38,0xffffffff);
        pm_relax(*plVar1);
      }
      mutex_unlock(param_1 + -0x1ac0);
      __wake_up(param_1 + 0x70,3,0,0);
    }
  }
  pm_relax(*plVar1);
  return;
}



//------------------------------------------------------------
// swrm_notify_work_fn @ 00106f4c size=216
// signature: undefined swrm_notify_work_fn(void)
// callers: []
//------------------------------------------------------------

void swrm_notify_work_fn(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if ((param_1 == 0x3c50) || (lVar2 = *(long *)(param_1 + -0x60), lVar2 == 0)) {
    iVar1 = ___ratelimit(swrm_notify_work_fn__rs,"swrm_notify_work_fn");
    if (iVar1 != 0) {
      _printk(&DAT_0010bf2a,"swrm_notify_work_fn");
    }
  }
  else {
    lVar3 = *(long *)(lVar2 + 0xa8);
    if (lVar3 == 0) {
      iVar1 = ___ratelimit(swrm_wcd_notify__rs_8,"swrm_wcd_notify");
      if (iVar1 != 0) {
        _dev_err(lVar2 + 0x10,"%s: swrm is NULL\n","swrm_wcd_notify");
      }
    }
    else {
      mutex_lock(lVar3 + 0x2250);
      if (*(int *)(lVar3 + 0x3be8) != 3) {
        swrm_device_down(lVar2 + 0x10);
      }
      mutex_unlock(lVar3 + 0x2250);
    }
  }
  return;
}



//------------------------------------------------------------
// swrm_event_notify @ 00107028 size=276
// signature: undefined swrm_event_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 swrm_event_notify(long param_1,long param_2)

{
  int iVar1;
  
  if ((param_1 == 0x3c38) || (*(long *)(param_1 + -0x1af8) == 0)) {
    iVar1 = ___ratelimit(swrm_event_notify__rs,"swrm_event_notify");
    if (iVar1 != 0) {
      _printk(&DAT_0010b92e,"swrm_event_notify");
    }
    return 0xffffffea;
  }
  if (param_2 == 4) {
    if ((*(int *)(param_1 + 0x168) == 0) || (*(char *)(param_1 + 0x16d) != '\0')) {
      return 0;
    }
    *(undefined1 *)(param_1 + 0x16d) = 1;
    pm_stay_awake();
    param_1 = param_1 + 0x138;
  }
  else {
    if (param_2 != 1) {
      iVar1 = ___ratelimit(swrm_event_notify__rs_198,"swrm_event_notify");
      if (iVar1 == 0) {
        return 0xffffffea;
      }
      _dev_err(*(long *)(param_1 + -0x1af8),"%s: invalid event type: %lu\n","swrm_event_notify",
               param_2);
      return 0xffffffea;
    }
    param_1 = param_1 + 0x18;
  }
  queue_work_on(0x20,_system_wq,param_1);
  return 0;
}



//------------------------------------------------------------
// swrm_runtime_resume @ 00107140 size=1400
// signature: undefined swrm_runtime_resume(void)
// callers: [swrm_read, swrm_write, swrm_resume]
//------------------------------------------------------------

int swrm_runtime_resume(long param_1)

{
  long lVar1;
  byte bVar2;
  undefined4 uVar3;
  byte bVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  
  lVar12 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar12 + 0x2310);
  lVar1 = lVar12 + 0x2280;
  mutex_lock(lVar1);
  iVar7 = swrm_request_hw_vote(lVar12,0,1);
  if (iVar7 == 0) {
    iVar7 = swrm_request_hw_vote(lVar12,1,1);
    if ((iVar7 != 0) &&
       (iVar8 = ___ratelimit(swrm_runtime_resume__rs_127,"swrm_runtime_resume"), iVar8 != 0)) {
      _dev_err(param_1,"%s:lpass audio hw enable failed\n","swrm_runtime_resume");
    }
    if ((*(int *)(lVar12 + 0x3be8) == 3) ||
       ((*(int *)(lVar12 + 0x3be8) == 4 && (*(char *)(lVar12 + 0x3da4) != '\0')))) {
      if (*(int *)(lVar12 + 0x3d68) != 0) {
        if (0 < *(int *)(lVar12 + 0x23a4)) {
          lVar11 = irq_get_irq_data();
          if (lVar11 == 0) {
            iVar7 = ___ratelimit(swrm_runtime_resume__rs_128,"swrm_runtime_resume");
            if (iVar7 != 0) {
              _printk(&DAT_0010c684,"swrm_runtime_resume");
              iVar8 = 0;
              goto LAB_00107664;
            }
            goto LAB_00107660;
          }
          mutex_lock(lVar12 + 0x22e0);
          lVar11 = irq_get_irq_data(*(undefined4 *)(lVar12 + 0x23a4));
          if ((*(byte *)(*(long *)(lVar11 + 0x10) + 2) & 1) == 0) {
            irq_set_irq_wake(*(undefined4 *)(lVar12 + 0x23a4),0);
            disable_irq_nosync(*(undefined4 *)(lVar12 + 0x23a4));
          }
          mutex_unlock(lVar12 + 0x22e0);
        }
        if ((*(int *)(lVar12 + 0x3da0) != 0) &&
           (iVar8 = ___ratelimit(swrm_runtime_resume__rs_129,"swrm_runtime_resume"), iVar8 != 0)) {
          _dev_err(param_1,"%s:notifications disabled\n","swrm_runtime_resume");
        }
      }
      bVar5 = true;
      iVar8 = swrm_clk_request(lVar12,1);
      if (iVar8 == 0) {
        if ((*(int *)(lVar12 + 0x3d68) == 0) || (*(int *)(lVar12 + 0x3be8) == 4)) {
          for (plVar13 = *(long **)(lVar12 + 0x3d8); plVar13 != (long *)(lVar12 + 0x3d8);
              plVar13 = (long *)*plVar13) {
            iVar8 = swr_device_up(plVar13 + -6);
            if (iVar8 != -0x13 && iVar8 != 0) {
              iVar10 = ___ratelimit(swrm_runtime_resume__rs_130,"swrm_runtime_resume");
              if (iVar10 != 0) {
                _dev_err(param_1,"%s: failed to wakeup swr dev %d\n","swrm_runtime_resume",
                         *(undefined1 *)(plVar13 + 2));
              }
              swrm_clk_request(lVar12,0);
              bVar5 = false;
              goto joined_r0x00107604;
            }
          }
          mutex_lock(lVar12 + 0x21c0);
          iVar8 = *(int *)(lVar12 + 0x2158);
          mutex_unlock(lVar12 + 0x21c0);
          if (iVar8 == 1) {
            swr_master_write(lVar12,8,1);
            swr_master_write(lVar12,8,1);
            swr_master_write(lVar12,0x1044,1);
            swrm_master_init(lVar12);
            usleep_range_state(100,0x69,2);
            swrm_check_link_status(lVar12,1);
            bVar4 = *(byte *)(lVar12 + 0x235a);
            bVar2 = 0;
            if (bVar4 != 0xe) {
              bVar2 = bVar4 + 1 & 0xf;
            }
            *(byte *)(lVar12 + 0x235a) = bVar2;
            swrm_cmd_fifo_wr_cmd(lVar12,4,0xf,bVar4,0x41);
          }
          if (*(int *)(lVar12 + 0x3be8) == 4) {
            mutex_unlock(lVar1);
            swrm_cmd_fifo_wr_cmd(lVar12,8,0xf,0xf,0x60);
            mutex_lock(lVar1);
          }
        }
        else {
          if (*(long *)(lVar12 + 0x2350) != 0) {
            uVar9 = readl();
            writel(uVar9 & 0xfffffffd,*(undefined8 *)(lVar12 + 0x2350));
          }
          if (*(int *)(lVar12 + 0x23a8) < 0x2000000) {
            iVar8 = 2;
            if (0x106ffff < *(int *)(lVar12 + 0x23a8)) {
              iVar8 = 2 << (ulong)(*(uint *)(lVar12 + 0x2360) & 0x1f);
            }
            iVar10 = 0x1044;
          }
          else {
            iVar8 = 1;
            iVar10 = (uint)*(ushort *)(lVar12 + 0x2360) * 0x1000 + 0x4060;
          }
          swr_master_write(lVar12,iVar10,iVar8);
          if (2 < *(uint *)(lVar12 + 0x23ac)) {
LAB_001076b4:
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1076b8);
            (*pcVar6)();
          }
          swr_master_write(lVar12,*(undefined4 *)
                                   (swrm_registers + (ulong)*(uint *)(lVar12 + 0x23ac) * 4 + 0x18),8
                          );
          *(uint *)(lVar12 + 0x3dfc) = *(uint *)(lVar12 + 0x3dfc) | 8;
          if (2 < *(uint *)(lVar12 + 0x23ac)) goto LAB_001076b4;
          swr_master_write(lVar12,*(undefined4 *)
                                   (swrm_registers + (ulong)*(uint *)(lVar12 + 0x23ac) * 4 + 0xc));
          usleep_range_state(100,0x69,2);
          swrm_check_link_status(lVar12,1);
        }
        bVar5 = false;
        *(undefined4 *)(lVar12 + 0x3be8) = 2;
      }
    }
    else {
      bVar5 = false;
    }
    iVar8 = 0;
joined_r0x00107604:
    if ((iVar7 == 0) && (*(int *)(lVar12 + 0x3e44) != 0)) {
      mutex_lock(lVar12 + 0x2220);
      if (*(long *)(lVar12 + 0x3e10) != 0) {
        iVar10 = *(int *)(lVar12 + 0x3e24) + -1;
        *(int *)(lVar12 + 0x3e24) = iVar10;
        if (iVar10 < 0) {
          *(undefined4 *)(lVar12 + 0x3e24) = 0;
        }
        else if (iVar10 == 0) {
          digital_cdc_rsc_mgr_hw_vote_disable
                    (*(long *)(lVar12 + 0x3e10),*(undefined8 *)(lVar12 + 0x2140));
        }
      }
      mutex_unlock(lVar12 + 0x2220);
    }
    mutex_lock(lVar12 + 0x2220);
    if (*(long *)(lVar12 + 0x3e08) != 0) {
      iVar10 = *(int *)(lVar12 + 0x3e20) + -1;
      *(int *)(lVar12 + 0x3e20) = iVar10;
      if (iVar10 < 0) {
        *(undefined4 *)(lVar12 + 0x3e20) = 0;
      }
      else if (iVar10 == 0) {
        digital_cdc_rsc_mgr_hw_vote_disable
                  (*(long *)(lVar12 + 0x3e08),*(undefined8 *)(lVar12 + 0x2140));
      }
    }
    mutex_unlock(lVar12 + 0x2220);
    if (iVar7 != 0) {
      bVar5 = true;
    }
    uVar3 = auto_suspend_timer;
    if (bVar5) {
      uVar3 = 1;
    }
    pm_runtime_set_autosuspend_delay(param_1,uVar3);
    if (*(char *)(lVar12 + 0x3da6) == '\0') goto LAB_00107664;
  }
  else {
    iVar7 = ___ratelimit(swrm_runtime_resume__rs,"swrm_runtime_resume");
    if (iVar7 != 0) {
      _dev_err(param_1,"%s:lpass core hw enable failed\n","swrm_runtime_resume");
    }
    pm_runtime_set_autosuspend_delay(param_1,1);
    if (*(char *)(lVar12 + 0x3da6) == '\0') {
LAB_00107660:
      iVar8 = 0;
      goto LAB_00107664;
    }
    iVar8 = 0;
  }
  *(undefined1 *)(lVar12 + 0x3da6) = 0;
LAB_00107664:
  mutex_unlock(lVar1);
  mutex_unlock(lVar12 + 0x2310);
  return iVar8;
}



//------------------------------------------------------------
// swrm_cmd_fifo_rd_cmd @ 001076b8 size=724
// signature: undefined swrm_cmd_fifo_rd_cmd(void)
// callers: [swrm_read, swrm_enable_slave_irq, swr_mstr_interrupt]
//------------------------------------------------------------

void swrm_cmd_fifo_rd_cmd
               (long param_1,uint *param_2,uint param_3,undefined1 param_4,uint param_5,int param_6)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  mutex_lock(param_1 + 0x21f0);
  pbVar1 = (byte *)(param_1 + 0x2358);
  bVar3 = *pbVar1;
  if (bVar3 == 0xf) {
    uVar6 = 0xf0000;
  }
  else {
    bVar2 = 0;
    if (bVar3 < 0xe) {
      bVar2 = bVar3 + 1;
    }
    uVar6 = (uint)bVar2 << 0x10;
    *pbVar1 = bVar2;
  }
  uVar6 = (param_3 & 0xff) << 0x14 | param_6 << 0x18 | uVar6 | param_5 & 0xffff;
  if (*(long *)(param_1 + 0x2370) == 0) {
    swrm_wait_for_fifo_avail(param_1,0);
    usleep_range_state(100,0x69,2);
    if (2 < *(uint *)(param_1 + 0x23ac)) goto LAB_00107988;
    swr_master_write(param_1,*(undefined4 *)
                              (swrm_registers + (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x30),uVar6
                    );
    usleep_range_state(0xfa,0xff,2);
  }
  else {
    if (2 < *(uint *)(param_1 + 0x23ac)) goto LAB_00107988;
    swr_master_write(param_1,*(undefined4 *)
                              (swrm_registers + (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x30),uVar6
                    );
  }
  swrm_wait_for_fifo_avail(param_1,1);
  if (*(uint *)(param_1 + 0x23ac) < 3) {
    uVar5 = swr_master_read(param_1,*(undefined4 *)
                                     (swrm_registers + (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x3c
                                     ));
    *param_2 = uVar5;
    if ((uVar5 >> 8 & 0xf) == (uint)*pbVar1) {
LAB_00107914:
      mutex_unlock(param_1 + 0x21f0);
      return;
    }
    usleep_range_state(500,0x1f9,2);
    if (*(uint *)(param_1 + 0x23ac) < 3) {
      uVar5 = swr_master_read(param_1,*(undefined4 *)
                                       (swrm_registers +
                                       (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x3c));
      *param_2 = uVar5;
      if ((uVar5 >> 8 & 0xf) == (uint)*pbVar1) goto LAB_00107914;
      usleep_range_state(500,0x1f9,2);
      if (*(uint *)(param_1 + 0x23ac) < 3) {
        uVar5 = swr_master_read(param_1,*(undefined4 *)
                                         (swrm_registers +
                                         (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x3c));
        *param_2 = uVar5;
        if ((uVar5 >> 8 & 0xf) == (uint)*pbVar1) goto LAB_00107914;
        usleep_range_state(500,0x1f9,2);
        if (*(uint *)(param_1 + 0x23ac) < 3) {
          swr_master_write(param_1,*(undefined4 *)
                                    (swrm_registers + (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x30)
                           ,uVar6);
          if (*(uint *)(param_1 + 0x23ac) < 3) {
            uVar6 = swr_master_read(param_1,*(undefined4 *)
                                             (swrm_registers +
                                             (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x3c));
            *param_2 = uVar6;
            if ((uVar6 >> 8 & 0xf) != (uint)*pbVar1) {
              iVar7 = ___ratelimit(swrm_cmd_fifo_rd_cmd__rs,"swrm_cmd_fifo_rd_cmd");
              if (iVar7 != 0) {
                _dev_err(*(undefined8 *)(param_1 + 0x2140),
                         "%s: reg: 0x%x, cmd_id: 0x%x, \t\t\t\trcmd_id: 0x%x, dev_num: 0x%x, cmd_data: 0x%x\n"
                         ,"swrm_cmd_fifo_rd_cmd",param_5 & 0xffff,param_4,*pbVar1,param_3 & 0xff,
                         *param_2);
              }
              iVar7 = ___ratelimit(swrm_cmd_fifo_rd_cmd__rs_133,"swrm_cmd_fifo_rd_cmd");
              if (iVar7 != 0) {
                _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: failed to read fifo\n",
                         "swrm_cmd_fifo_rd_cmd");
              }
            }
            goto LAB_00107914;
          }
        }
      }
    }
  }
LAB_00107988:
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10798c);
  (*pcVar4)();
}



//------------------------------------------------------------
// swr_master_bulk_write @ 0010798c size=288
// signature: undefined swr_master_bulk_write(void)
// callers: [swrm_bulk_write, swrm_copy_data_port_config, swrm_master_init]
//------------------------------------------------------------

void swr_master_bulk_write(long param_1,long param_2,long param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  
  pcVar2 = *(code **)(param_1 + 0x2380);
  if (pcVar2 == (code *)0x0) {
    mutex_lock(param_1 + 0x21f0);
    if (param_4 != 0) {
      iVar3 = 0;
      do {
        usleep_range_state(0x32,0x37,2);
        if (2 < *(uint *)(param_1 + 0x23ac)) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x107aac);
          (*pcVar2)();
        }
        lVar4 = (long)iVar3;
        iVar1 = *(int *)(param_2 + lVar4 * 4);
        if (iVar1 == *(int *)(swrm_registers + (ulong)*(uint *)(param_1 + 0x23ac) * 4 + 0x24)) {
          swrm_wait_for_fifo_avail(param_1,0);
          iVar1 = *(int *)(param_2 + lVar4 * 4);
        }
        swr_master_write(param_1,iVar1,*(undefined4 *)(param_3 + lVar4 * 4));
        iVar3 = iVar3 + 1;
      } while (param_4 != iVar3);
    }
    usleep_range_state(100,0x6e,2);
    mutex_unlock(param_1 + 0x21f0);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x5a366efb) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1079e8);
      (*pcVar2)();
    }
    (*pcVar2)(*(undefined8 *)(param_1 + 0x2368),param_2,param_3,param_4);
  }
  return;
}



//------------------------------------------------------------
// swrm_initialize_clk_base_scale @ 00107aac size=312
// signature: undefined swrm_initialize_clk_base_scale(void)
// callers: [swrm_get_logical_dev_num, swr_mstr_interrupt]
//------------------------------------------------------------

void swrm_initialize_clk_base_scale(long param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  ulong uVar7;
  
  if ((param_2 & 0xff) != 0) {
    uVar7 = swr_master_read(param_1,(param_2 & 0xff) * 8 + 0x534);
    if ((uVar7 & 0xff00) != 0) {
      uVar5 = swr_master_read(param_1,0x104c);
      if ((uVar5 & 1) != 0) {
        uVar6 = swr_master_read(param_1,(uVar5 & 1) << 6 | 0x101c);
        swrm_cmd_fifo_wr_cmd(param_1,uVar6,0xf,0xf,(uVar5 & 1) << 4 | 0x60);
      }
      cVar3 = *(char *)(param_1 + 0x235a);
      bVar1 = 0;
      if (cVar3 != '\x0e') {
        bVar1 = cVar3 + 1U & 0xf;
      }
      *(byte *)(param_1 + 0x235a) = bVar1;
      swrm_cmd_fifo_wr_cmd(param_1,1,param_2,cVar3,0x4d);
      cVar3 = *(char *)(param_1 + 0x235a);
      uVar5 = 0;
      if (*(int *)(param_1 + 0x23b4) != 0) {
        uVar5 = (*(int *)(param_1 + 0x23b0) << 1) / *(int *)(param_1 + 0x23b4);
      }
      uVar4 = (uVar5 & 0xaaaaaaaa) >> 1 | (uVar5 & 0x55555555) << 1;
      uVar4 = (uVar4 & 0xcccccccc) >> 2 | (uVar4 & 0x33333333) << 2;
      uVar4 = (uVar4 & 0xf0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f) << 4;
      uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
      iVar2 = 0;
      if (uVar5 != 0) {
        iVar2 = (int)LZCOUNT(uVar4 >> 0x10 | uVar4 << 0x10) + 1;
      }
      bVar1 = 0;
      if (cVar3 != '\x0e') {
        bVar1 = cVar3 + 1U & 0xf;
      }
      *(byte *)(param_1 + 0x235a) = bVar1;
      swrm_cmd_fifo_wr_cmd(param_1,iVar2,param_2,cVar3,0x62);
      cVar3 = *(char *)(param_1 + 0x235a);
      bVar1 = 0;
      if (cVar3 != '\x0e') {
        bVar1 = cVar3 + 1U & 0xf;
      }
      *(byte *)(param_1 + 0x235a) = bVar1;
      swrm_cmd_fifo_wr_cmd(param_1,iVar2,param_2,cVar3,0x72);
    }
  }
  return;
}



//------------------------------------------------------------
// swrm_get_master_port @ 00107be4 size=384
// signature: undefined swrm_get_master_port(void)
// callers: [swrm_connect_port, swrm_disconnect_port]
//------------------------------------------------------------

undefined8 swrm_get_master_port(long param_1,undefined1 *param_2,char *param_3,char param_4)

{
  byte bVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  long lVar7;
  
  *param_2 = 0;
  bVar1 = *(byte *)(param_1 + 0x3c80);
  if (bVar1 != 0) {
    uVar6 = 0;
    bVar3 = false;
    pcVar5 = (char *)(param_1 + 0x3c9f);
    lVar7 = 1;
    do {
      if (uVar6 == 0xd) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x107d64);
        (*pcVar2)();
      }
      if (pcVar5[-0xe] == param_4) {
        lVar7 = 0;
joined_r0x00107cc4:
        if (!bVar3) {
          *param_2 = (char)uVar6;
          *param_3 = pcVar5[lVar7 * 2 + -0xd];
          return 0;
        }
        break;
      }
      if (pcVar5[-0xc] == param_4) goto joined_r0x00107cc4;
      if (pcVar5[-10] == param_4) {
        lVar7 = 2;
        goto joined_r0x00107cc4;
      }
      if (pcVar5[-8] == param_4) {
        lVar7 = 3;
        goto joined_r0x00107cc4;
      }
      if (pcVar5[-6] == param_4) {
        lVar7 = 4;
        goto joined_r0x00107cc4;
      }
      if (pcVar5[-4] == param_4) {
        lVar7 = 5;
        goto joined_r0x00107cc4;
      }
      if (pcVar5[-2] == param_4) {
        lVar7 = 6;
        goto joined_r0x00107cc4;
      }
      if (*pcVar5 == param_4) {
        lVar7 = 7;
        goto joined_r0x00107cc4;
      }
      pcVar5 = pcVar5 + 0x10;
      bVar3 = (uint)bVar1 <= uVar6 + 1;
      uVar6 = uVar6 + 1;
    } while (bVar1 != uVar6);
  }
  iVar4 = ___ratelimit(swrm_get_master_port__rs,"swrm_get_master_port");
  if (iVar4 != 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: port type not supported by master\n",
             "swrm_get_master_port");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// swrm_cleanup_disabled_port_reqs @ 00107d64 size=324
// signature: undefined swrm_cleanup_disabled_port_reqs(void)
// callers: [swrm_connect_port, swrm_slvdev_datapath_control]
//------------------------------------------------------------

void swrm_cleanup_disabled_port_reqs(long param_1)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  long *plVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  
  if ((param_1 == 0) || (lVar8 = *(long *)(param_1 + 0x98), lVar8 == 0)) {
    iVar5 = ___ratelimit(swrm_cleanup_disabled_port_reqs__rs,"swrm_cleanup_disabled_port_reqs");
    if (iVar5 != 0) {
      _printk(&DAT_0010c58e,"swrm_cleanup_disabled_port_reqs");
    }
  }
  else {
    lVar9 = 0;
    do {
      lVar7 = lVar8 + lVar9 * 0x28;
      plVar10 = *(long **)(lVar7 + 0x23c0);
      while (plVar4 = plVar10, plVar4 != (long *)(lVar7 + 0x23c0)) {
        cVar3 = (char)plVar4[3];
        plVar10 = (long *)*plVar4;
        if ((*(char *)((long)plVar4 + 0x17) != cVar3) &&
           (*(char *)((long)plVar4 + 0x17) = cVar3, cVar3 == '\0')) {
          uVar6 = __list_del_entry_valid(plVar4);
          if ((uVar6 & 1) != 0) {
            lVar1 = *plVar4;
            plVar2 = (long *)plVar4[1];
            *(long **)(lVar1 + 8) = plVar2;
            *plVar2 = lVar1;
          }
          *plVar4 = -0x2152ffffffffff00;
          plVar4[1] = -0x2152fffffffffede;
          kfree(plVar4 + -1);
        }
      }
      lVar7 = lVar8 + lVar9 * 0x28;
      cVar3 = *(char *)(lVar7 + 0x23d2);
      *(char *)(lVar7 + 0x23d1) = cVar3;
      if (cVar3 == '\0') {
        *(undefined1 *)(lVar8 + lVar9 * 0x28 + 0x23d0) = 0;
        *(ushort *)(param_1 + 0x2138) = *(ushort *)(param_1 + 0x2138) & ((ushort)lVar9 ^ 0xffff);
      }
      lVar9 = lVar9 + 1;
    } while (lVar9 != 0xd);
  }
  return;
}



//------------------------------------------------------------
// swrm_disable_ports @ 00107ea8 size=368
// signature: undefined swrm_disable_ports(void)
// callers: [swrm_slvdev_datapath_control]
//------------------------------------------------------------

void swrm_disable_ports(long param_1,uint param_2)

{
  undefined8 *puVar1;
  byte bVar2;
  char cVar3;
  byte bVar4;
  undefined1 uVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  
  if ((param_1 == 0) || (lVar8 = *(long *)(param_1 + 0x98), lVar8 == 0)) {
    iVar6 = ___ratelimit(swrm_disable_ports__rs,"swrm_disable_ports");
    if (iVar6 != 0) {
      _printk(&DAT_0010c58e,"swrm_disable_ports");
    }
  }
  else {
    lVar10 = 0;
    do {
      lVar7 = lVar8 + lVar10 * 0x28;
      puVar1 = (undefined8 *)(lVar7 + 0x23c0);
      if (*(char *)(lVar7 + 0x23d0) != '\0') {
        for (puVar9 = (undefined8 *)*puVar1; puVar9 != puVar1; puVar9 = (undefined8 *)*puVar9) {
          cVar3 = *(char *)(puVar9 + 3);
          if (cVar3 != *(char *)((long)puVar9 + 0x17)) {
            bVar4 = *(byte *)(lVar8 + 0x235a);
            uVar5 = *(undefined1 *)(puVar9 + -1);
            bVar2 = 0;
            if (bVar4 != 0xe) {
              bVar2 = bVar4 + 1 & 0xf;
            }
            *(byte *)(lVar8 + 0x235a) = bVar2;
            swrm_cmd_fifo_wr_cmd
                      (lVar8,cVar3,uVar5,bVar4,
                       (param_2 & 0xff) * 0x10 + 0x120 + (uint)*(byte *)((long)puVar9 + -6) * 0x100)
            ;
          }
        }
        lVar7 = lVar8 + lVar10 * 0x28;
        iVar6 = (int)lVar10 + 1;
        swr_master_write(lVar8,(param_2 & 0xff) * 0x40 + 0x1024 + iVar6 * 0x100,
                         (uint)*(byte *)(lVar7 + 0x23d2) << 0x18 |
                         (uint)*(byte *)(lVar7 + 0x23d4) << 0x10 |
                         (uint)*(byte *)(lVar7 + 0x23d3) << 8 | (uint)*(byte *)(lVar7 + 0x23d6));
        if (*(char *)(lVar7 + 0x23d2) == '\0') {
          swrm_pcm_port_config(lVar8,iVar6,puVar1,0);
        }
      }
      lVar10 = lVar10 + 1;
    } while (lVar10 != 0xd);
  }
  return;
}



//------------------------------------------------------------
// swrm_copy_data_port_config @ 00108018 size=3704
// signature: undefined swrm_copy_data_port_config(void)
// callers: [swrm_slvdev_datapath_control]
//------------------------------------------------------------

void swrm_copy_data_port_config(long param_1,uint param_2)

{
  uint uVar1;
  byte *pbVar2;
  long *plVar3;
  long lVar4;
  byte *pbVar5;
  byte *pbVar6;
  undefined4 uVar7;
  byte bVar8;
  byte bVar9;
  char cVar10;
  byte bVar11;
  byte bVar12;
  code *pcVar13;
  int iVar14;
  ulong uVar15;
  ulong uVar16;
  undefined1 uVar17;
  long lVar18;
  char cVar19;
  long lVar20;
  long *plVar21;
  int iVar22;
  short sVar23;
  short sVar24;
  undefined1 uVar25;
  uint uVar26;
  long lVar27;
  ulong uVar28;
  uint uVar29;
  ulong uVar30;
  byte local_440 [16];
  uint local_430 [240];
  long local_70;
  
  lVar27 = sp_el0;
  local_70 = *(long *)(lVar27 + 0x638);
  memset(local_430 + 0x78,0,0x1e0);
  memset(local_430,0,0x1e0);
  if ((param_1 == 0) || (lVar27 = *(long *)(param_1 + 0x98), lVar27 == 0)) {
    iVar14 = ___ratelimit(swrm_copy_data_port_config__rs,"swrm_copy_data_port_config");
    if (iVar14 != 0) {
      _printk(&DAT_0010c58e,"swrm_copy_data_port_config");
    }
  }
  else {
    pbVar2 = (byte *)(lVar27 + 0x235a);
    uVar30 = 0;
    uVar28 = 0;
    do {
      while( true ) {
        uVar29 = (uint)uVar30;
        lVar20 = lVar27 + uVar28 * 0x28;
        plVar3 = (long *)(lVar20 + 0x23c0);
        if (*(char *)(lVar20 + 0x23d0) != '\0') break;
        uVar28 = uVar28 + 1;
        if (uVar28 == 0xd) goto LAB_00108dcc;
      }
      local_440[0] = 0xff;
      local_440[1] = 0xff;
      local_440[2] = 0xff;
      local_440[3] = 0xff;
      local_440[4] = 0xff;
      local_440[5] = 0xff;
      local_440[6] = 0xff;
      local_440[7] = 0xff;
      local_440[8] = 0xff;
      local_440[9] = 0xff;
      local_440[10] = 0xff;
      swrm_pcm_port_config(lVar27,(int)uVar28 + 1,plVar3,1);
      plVar21 = (long *)*plVar3;
      if (plVar21 == plVar3) {
        cVar19 = '\0';
        sVar24 = -1;
      }
      else {
        lVar20 = lVar27 + uVar28 * 0x28;
        iVar14 = 0;
        cVar19 = '\0';
        sVar23 = -1;
        do {
          bVar11 = *(byte *)(plVar21 + -1);
          sVar24 = sVar23;
          if (bVar11 != 0) {
            bVar12 = *(byte *)((long)plVar21 + -6);
            if (*(int *)(lVar27 + 0x235c) == 5) {
              uVar17 = 0;
              sVar24 = 0;
              if (*(uint *)((long)plVar21 + 0x1c) != 0) {
                sVar24 = (short)((uint)(*(int *)(lVar27 + 0x23b4) << 1) /
                                *(uint *)((long)plVar21 + 0x1c));
              }
              *(short *)((long)plVar21 + -2) = sVar24 + -1;
              cVar10 = *(char *)(lVar20 + 0x23de);
              *(undefined1 *)((long)plVar21 + -4) = 0;
              *(undefined4 *)((long)plVar21 + 0x11) = 0xffff0f01;
              uVar25 = 0;
              if (cVar10 != '\0') {
                uVar25 = 0x14;
              }
              *(undefined1 *)((long)plVar21 + -5) = uVar25;
              *(undefined1 *)((long)plVar21 + 0x15) = 0xf;
LAB_001082d8:
              *(undefined1 *)((long)plVar21 + 0x16) = uVar17;
              if (*(int *)(lVar27 + 0x235c) == 1) {
                iVar22 = *(int *)(lVar27 + 0x23b4);
                if (iVar22 == 600000) {
                  lVar18 = 3;
                }
                else if (iVar22 == 4800000) {
                  lVar18 = 1;
                }
                else if (iVar22 == 1200000) {
                  lVar18 = 2;
                }
                else {
                  lVar18 = 0;
                }
                lVar4 = (ulong)((uint)bVar11 * 0xe - 0xe) + (ulong)bVar12;
                if (((uint)lVar4 < 0x9a) &&
                   (iVar22 = *(int *)(lVar27 + lVar18 * 0x4d0 + lVar4 * 8 + 0x3e4c), iVar22 != 0)) {
                  *(char *)((long)plVar21 + -5) = (char)iVar22;
                }
              }
            }
            else {
              if (*(int *)(lVar27 + 0x235c) != 3) {
                *(undefined2 *)((long)plVar21 + -2) = *(undefined2 *)(lVar20 + 0x23d6);
                *(undefined1 *)((long)plVar21 + -5) = *(undefined1 *)(lVar20 + 0x23d3);
                *(undefined1 *)((long)plVar21 + -4) = *(undefined1 *)(lVar20 + 0x23d4);
                *(undefined1 *)((long)plVar21 + 0x11) = *(undefined1 *)(lVar20 + 0x23d8);
                *(undefined1 *)((long)plVar21 + 0x12) = *(undefined1 *)(lVar20 + 0x23d9);
                *(undefined1 *)((long)plVar21 + 0x15) = *(undefined1 *)(lVar20 + 0x23dc);
                *(undefined1 *)((long)plVar21 + 0x14) = *(undefined1 *)(lVar20 + 0x23db);
                *(undefined1 *)((long)plVar21 + 0x13) = *(undefined1 *)(lVar20 + 0x23da);
                uVar17 = *(undefined1 *)(lVar20 + 0x23dd);
                goto LAB_001082d8;
              }
              iVar22 = *(int *)(lVar27 + 0x23b4);
              if (iVar22 == 600000) {
                lVar18 = 3;
              }
              else if (iVar22 == 4800000) {
                lVar18 = 1;
              }
              else if (iVar22 == 1200000) {
                lVar18 = 2;
              }
              else {
                lVar18 = 0;
              }
              lVar4 = (ulong)((uint)bVar11 * 0xe - 0xe) + (ulong)bVar12;
              if ((uint)lVar4 < 0x9a) {
                sVar24 = 0;
                if (*(uint *)((long)plVar21 + 0x1c) != 0) {
                  sVar24 = (short)((uint)(iVar22 << 1) / *(uint *)((long)plVar21 + 0x1c));
                }
                lVar18 = lVar27 + lVar18 * 0x4d0 + lVar4 * 8;
                *(short *)((long)plVar21 + -2) = sVar24 + -1;
                uVar7 = *(undefined4 *)(lVar18 + 0x3e4c);
                *(undefined1 *)((long)plVar21 + -4) = 0;
                *(undefined1 *)((long)plVar21 + 0x15) = 0xff;
                *(undefined4 *)((long)plVar21 + 0x11) = 0xffffffff;
                *(char *)((long)plVar21 + -5) = (char)uVar7;
                uVar17 = (undefined1)*(undefined4 *)(lVar18 + 0x3e50);
                goto LAB_001082d8;
              }
            }
            sVar24 = *(short *)((long)plVar21 + -2);
            if (iVar14 == 0) {
              cVar19 = *(char *)((long)plVar21 + 0x16);
            }
            else if ((sVar23 != sVar24) ||
                    (sVar24 = sVar23, cVar19 != *(char *)((long)plVar21 + 0x16))) {
              iVar14 = ___ratelimit(swrm_copy_data_port_config__rs_156,"swrm_copy_data_port_config")
              ;
              if (iVar14 != 0) {
                _dev_err(*(undefined8 *)(lVar27 + 0x2140),
                         "%s:slaves/slave ports attaching to mport%d are not using same SI or data lane, update slave tables,bailing out without setting port config\n"
                         ,"swrm_copy_data_port_config",uVar28 & 0xffffffff);
              }
              goto LAB_00108e2c;
            }
            if ((2 < *(uint *)(lVar27 + 0x23ac)) || (uVar29 = (uint)uVar30, 0x77 < uVar29))
            goto LAB_00108e84;
            local_430[uVar30 + 0x78] =
                 *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
            bVar8 = *pbVar2;
            bVar11 = 0;
            if (bVar8 != 0xe) {
              bVar11 = bVar8 + 1 & 0xf;
            }
            iVar22 = (uint)bVar12 * 0x100;
            *pbVar2 = bVar11;
            uVar1 = iVar22 + (param_2 & 0xff) * 0x10;
            local_430[uVar30] =
                 uVar1 + 0x120 | (uint)bVar8 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                 (uint)*(byte *)(plVar21 + 3) << 0x18;
            if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x76 < uVar29)) goto LAB_00108e84;
            uVar26 = uVar29 + 1;
            local_430[(ulong)uVar26 + 0x78] =
                 *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
            bVar12 = *pbVar2;
            bVar11 = 0;
            if (bVar12 != 0xe) {
              bVar11 = bVar12 + 1 & 0xf;
            }
            *pbVar2 = bVar11;
            if (uVar26 == 0x78) goto LAB_00108e88;
            local_430[uVar26] =
                 uVar1 + 0x122 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                 (uint)*(ushort *)((long)plVar21 + -2) << 0x18;
            if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x75 < uVar29)) goto LAB_00108e84;
            uVar26 = uVar29 + 2;
            local_430[(ulong)uVar26 + 0x78] =
                 *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
            bVar12 = *pbVar2;
            bVar11 = 0;
            if (bVar12 != 0xe) {
              bVar11 = bVar12 + 1 & 0xf;
            }
            *pbVar2 = bVar11;
            if (uVar26 == 0x78) goto LAB_00108e88;
            local_430[uVar26] =
                 uVar1 + 0x123 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                 (uint)(byte)((ushort)*(undefined2 *)((long)plVar21 + -2) >> 8) << 0x18;
            uVar30 = (ulong)(uVar29 + 3);
            if (*(char *)((long)plVar21 + -5) != -1) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x74 < uVar29)) goto LAB_00108e84;
              local_430[uVar30 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              if (uVar29 + 3 == 0x78) goto LAB_00108e88;
              local_430[uVar30] =
                   uVar1 + 0x124 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                   (uint)*(byte *)((long)plVar21 + -5) << 0x18;
              uVar30 = (ulong)(uVar29 + 4);
            }
            uVar15 = uVar30;
            if (*(char *)((long)plVar21 + -4) != -1) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < (uint)uVar30)) goto LAB_00108e84;
              uVar15 = (ulong)((uint)uVar30 + 1);
              local_430[uVar30 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar30] =
                   uVar1 + 0x125 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                   (uint)*(byte *)((long)plVar21 + -4) << 0x18;
            }
            bVar11 = *(byte *)((long)plVar21 + 0x11);
            uVar30 = uVar15;
            if ((bVar11 != 0xff) && (bVar12 = *(byte *)((long)plVar21 + 0x12), bVar12 != 0xff)) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < (uint)uVar15)) goto LAB_00108e84;
              uVar30 = (ulong)((uint)uVar15 + 1);
              local_430[uVar15 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar9 = *pbVar2;
              bVar8 = 0;
              if (bVar9 != 0xe) {
                bVar8 = bVar9 + 1 & 0xf;
              }
              *pbVar2 = bVar8;
              local_430[uVar15] =
                   (uVar1 | (uint)bVar11 << 0x1c | (uint)bVar12 << 0x18) + 0x126 |
                   (uint)bVar9 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14;
            }
            uVar15 = uVar30;
            if (*(char *)((long)plVar21 + 0x15) != -1) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < (uint)uVar30)) goto LAB_00108e84;
              uVar15 = (ulong)((uint)uVar30 + 1);
              local_430[uVar30 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar30] =
                   iVar22 + 0x103U | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                   (uint)*(byte *)((long)plVar21 + 0x15) << 0x18;
            }
            uVar30 = uVar15;
            if (*(char *)((long)plVar21 + 0x14) != -1) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < (uint)uVar15)) goto LAB_00108e84;
              uVar30 = (ulong)((uint)uVar15 + 1);
              local_430[uVar15 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar15] =
                   uVar1 + 0x127 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                   (uint)*(byte *)((long)plVar21 + 0x14) << 0x18;
            }
            uVar15 = uVar30;
            if (*(char *)((long)plVar21 + 0x13) != -1) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < (uint)uVar30)) goto LAB_00108e84;
              uVar15 = (ulong)((uint)uVar30 + 1);
              local_430[uVar30 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar30] =
                   uVar1 + 0x121 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                   (uint)*(byte *)((long)plVar21 + 0x13) << 0x18;
            }
            uVar16 = uVar15;
            if (*(char *)((long)plVar21 + 0x16) != -1) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < (uint)uVar15)) goto LAB_00108e84;
              uVar16 = (ulong)((uint)uVar15 + 1);
              local_430[uVar15 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar15] =
                   uVar1 + 0x128 | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14 |
                   (uint)*(byte *)((long)plVar21 + 0x16) << 0x18;
            }
            uVar29 = (uint)uVar16;
            if ((int)plVar21[4] == *(int *)((long)plVar21 + 0x1c)) {
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < uVar29)) goto LAB_00108e84;
              uVar30 = (ulong)(uVar29 + 1);
              local_430[uVar16 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar16] =
                   iVar22 + 0x102U | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14;
              if (*(int *)(lVar27 + 0x235c) == 5) {
                if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x76 < uVar29)) goto LAB_00108e84;
                local_430[uVar30 + 0x78] =
                     *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
                bVar12 = *pbVar2;
                bVar8 = *(byte *)((long)plVar21 + -6);
                bVar11 = 0;
                if (bVar12 != 0xe) {
                  bVar11 = bVar12 + 1 & 0xf;
                }
                *pbVar2 = bVar11;
                if (uVar29 + 1 == 0x78) goto LAB_00108e88;
                local_430[uVar30] =
                     (uint)bVar8 * 0x100 + 0x1d4 | (uint)bVar12 << 0x10 |
                     (uint)*(byte *)(plVar21 + -1) << 0x14;
                uVar30 = (ulong)(uVar29 + 2);
              }
            }
            else {
              cVar10 = *(char *)(lVar20 + 0x23de);
              if (cVar10 == '\x01') {
                uVar1 = *(uint *)(lVar27 + 0x23ac);
                if ((2 < uVar1) || (0x77 < uVar29)) goto LAB_00108e84;
                uVar26 = 0x2000000;
LAB_001088e0:
                uVar29 = uVar29 + 1;
                local_430[uVar16 + 0x78] = *(uint *)(swrm_registers + (ulong)uVar1 * 4 + 0x24);
                bVar12 = *pbVar2;
                bVar11 = 0;
                if (bVar12 != 0xe) {
                  bVar11 = bVar12 + 1 & 0xf;
                }
                *pbVar2 = bVar11;
                local_430[uVar16] =
                     iVar22 + 0x102U | (uint)bVar12 << 0x10 | (uint)*(byte *)(plVar21 + -1) << 0x14
                     | uVar26;
              }
              else if (cVar10 == '\0') {
                uVar1 = *(uint *)(lVar27 + 0x23ac);
                if ((uVar1 < 3) && (uVar29 < 0x78)) {
                  uVar26 = 0x1000000;
                  goto LAB_001088e0;
                }
                goto LAB_00108e84;
              }
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x77 < uVar29)) goto LAB_00108e84;
              local_430[(ulong)uVar29 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar8 = *(byte *)((long)plVar21 + -6);
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              local_430[uVar29] =
                   (uint)bVar8 * 0x100 + 0x1d4 | (uint)bVar12 << 0x10 |
                   (uint)*(byte *)(plVar21 + -1) << 0x14 | 0x4000000;
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x76 < uVar29)) goto LAB_00108e84;
              uVar1 = uVar29 + 1;
              local_430[(ulong)uVar1 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar8 = *(byte *)((long)plVar21 + -6);
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              if (uVar1 == 0x78) goto LAB_00108e88;
              local_430[uVar1] =
                   (uint)bVar8 * 0x100 + 0x1cc | (uint)bVar12 << 0x10 |
                   (uint)*(byte *)(plVar21 + -1) << 0x14 | 0x1000000;
              if ((2 < *(uint *)(lVar27 + 0x23ac)) || (0x75 < uVar29)) goto LAB_00108e84;
              uVar1 = uVar29 + 2;
              local_430[(ulong)uVar1 + 0x78] =
                   *(uint *)(swrm_registers + (ulong)*(uint *)(lVar27 + 0x23ac) * 4 + 0x24);
              bVar12 = *pbVar2;
              bVar8 = *(byte *)((long)plVar21 + -6);
              bVar11 = 0;
              if (bVar12 != 0xe) {
                bVar11 = bVar12 + 1 & 0xf;
              }
              *pbVar2 = bVar11;
              if (uVar1 == 0x78) goto LAB_00108e88;
              uVar30 = (ulong)(uVar29 + 3);
              local_430[uVar1] =
                   (uint)bVar8 * 0x100 + 0x1c4 | (uint)bVar12 << 0x10 |
                   (uint)*(byte *)(plVar21 + -1) << 0x14 | 0x1000000;
            }
            *(char *)((long)plVar21 + 0x17) = (char)plVar21[3];
            if (10 < (ulong)*(byte *)(plVar21 + -1)) goto LAB_00108e84;
            iVar14 = iVar14 + 1;
            local_440[*(byte *)(plVar21 + -1)] = *(byte *)((long)plVar21 + -5);
          }
          uVar29 = (uint)uVar30;
          plVar21 = (long *)*plVar21;
          sVar23 = sVar24;
        } while (plVar21 != plVar3);
      }
      if (*(int *)(lVar27 + 0x235c) == 5) {
        lVar20 = lVar27 + uVar28 * 0x28;
        *(char *)(lVar20 + 0x23dd) = cVar19;
        *(short *)(lVar20 + 0x23d6) = sVar24;
        *(undefined1 *)(lVar20 + 0x23dc) = 0xf;
        *(undefined2 *)(lVar20 + 0x23d8) = 0xf01;
      }
      else if (*(int *)(lVar27 + 0x235c) == 3) {
        lVar20 = lVar27 + uVar28 * 0x28;
        *(short *)(lVar20 + 0x23d6) = sVar24;
        *(char *)(lVar20 + 0x23dd) = cVar19;
      }
      lVar20 = lVar27 + uVar28 * 0x28;
      uVar26 = (uint)*(byte *)(lVar20 + 0x23d3);
      uVar1 = 0;
      if (*(byte *)(lVar20 + 0x23d4) != 0xff) {
        uVar1 = (uint)*(byte *)(lVar20 + 0x23d4) << 0x10;
      }
      if (*(int *)(lVar27 + 0x235c) == 3) {
        uVar26 = (uint)local_440[1];
        if ((uint)local_440[2] <= (uint)local_440[1]) {
          uVar26 = (uint)local_440[2];
        }
        if (local_440[3] <= uVar26) {
          uVar26 = (uint)local_440[3];
        }
        if (local_440[4] <= uVar26) {
          uVar26 = (uint)local_440[4];
        }
        if (local_440[5] <= uVar26) {
          uVar26 = (uint)local_440[5];
        }
        if (local_440[6] <= uVar26) {
          uVar26 = (uint)local_440[6];
        }
        if (local_440[7] <= uVar26) {
          uVar26 = (uint)local_440[7];
        }
        if (local_440[8] <= uVar26) {
          uVar26 = (uint)local_440[8];
        }
        if (local_440[9] <= uVar26) {
          uVar26 = (uint)local_440[9];
        }
        if (local_440[10] <= uVar26) {
          uVar26 = (uint)local_440[10];
        }
        if (0xe < uVar26) {
          uVar26 = 0xf;
        }
      }
      *(byte *)(lVar20 + 0x23d3) = (byte)uVar26;
      bVar11 = *(byte *)(lVar20 + 0x23d2);
      if (0x77 < uVar29) {
LAB_00108e84:
                    /* WARNING: Does not return */
        pcVar13 = (code *)SoftwareBreakpoint(0x5512,0x108e88);
        (*pcVar13)();
      }
      lVar18 = lVar27 + uVar28 * 0x28;
      uVar15 = uVar28 + 1;
      iVar14 = (int)uVar15 * 0x100;
      iVar22 = iVar14 + (param_2 & 0xff) * 0x40;
      bVar12 = *(byte *)(lVar18 + 0x23d6);
      local_430[(ulong)uVar29 + 0x78] = iVar22 + 0x1024;
      local_430[uVar29] = uVar1 | (uint)bVar11 << 0x18 | uVar26 << 8 | (uint)bVar12;
      if (uVar29 == 0x77) goto LAB_00108e84;
      if (0x76 < uVar29) {
LAB_00108e88:
                    /* WARNING: Does not return */
        pcVar13 = (code *)SoftwareBreakpoint(1,0x108e8c);
        (*pcVar13)();
      }
      uVar1 = uVar29 + 1;
      local_430[(ulong)uVar1 + 0x78] = iVar22 + 0x103c;
      if (uVar1 == 0x78) goto LAB_00108e88;
      pbVar5 = (byte *)(lVar27 + uVar28 * 0x28 + 0x23dd);
      local_430[uVar1] = (uint)*(byte *)(lVar18 + 0x23d7);
      uVar1 = uVar29 + 2;
      uVar30 = (ulong)uVar1;
      if (*pbVar5 != 0xff) {
        if (0x75 < uVar29) goto LAB_00108e84;
        if ((uVar1 == 0x78) || (local_430[(ulong)uVar1 + 0x78] = iVar22 + 0x1028, 0x76 < uVar29))
        goto LAB_00108e88;
        local_430[uVar30] = (uint)*pbVar5;
        uVar30 = (ulong)(uVar29 + 3);
      }
      pbVar5 = (byte *)(lVar27 + uVar28 * 0x28 + 0x23dc);
      uVar16 = uVar30;
      if (*pbVar5 != 0xff) {
        if (0x77 < (uint)uVar30) goto LAB_00108e84;
        uVar16 = (ulong)((uint)uVar30 + 1);
        local_430[uVar30 + 0x78] = iVar14 + 0x102c;
        local_430[uVar30] = (uint)*pbVar5;
      }
      uVar29 = (uint)uVar16;
      pbVar5 = (byte *)(lVar27 + uVar28 * 0x28 + 0x23da);
      if (*pbVar5 != 0xff) {
        if (0x77 < uVar29) goto LAB_00108e84;
        uVar29 = uVar29 + 1;
        local_430[uVar16 + 0x78] = iVar22 + 0x1030;
        local_430[uVar16] = (uint)*pbVar5;
      }
      pbVar5 = (byte *)(lVar27 + uVar28 * 0x28 + 0x23d8);
      if ((*pbVar5 == 0xff) || (pbVar6 = (byte *)(lVar27 + uVar28 * 0x28 + 0x23d9), *pbVar6 == 0xff)
         ) {
        if (0x77 < uVar29) goto LAB_00108e84;
        local_430[(ulong)uVar29 + 0x78] = iVar22 + 0x1034;
        local_430[uVar29] = 0xf0;
      }
      else {
        if (0x77 < uVar29) goto LAB_00108e84;
        local_430[(ulong)uVar29 + 0x78] = iVar22 + 0x1034;
        local_430[uVar29] = (*pbVar6 & 0xf) << 4 | (uint)*pbVar5;
      }
      uVar1 = uVar29 + 1;
      uVar30 = (ulong)uVar1;
      pbVar5 = (byte *)(lVar27 + uVar28 * 0x28 + 0x23db);
      if (*pbVar5 != 0xff) {
        if (0x76 < uVar29) goto LAB_00108e84;
        if ((uVar1 == 0x78) || (local_430[(ulong)uVar1 + 0x78] = iVar22 + 0x1038, 0x77 < uVar29))
        goto LAB_00108e88;
        local_430[uVar30] = (uint)*pbVar5;
        uVar30 = (ulong)(uVar29 + 2);
      }
      *(byte *)(lVar27 + uVar28 * 0x28 + 0x23d1) = *(byte *)(lVar20 + 0x23d2);
      uVar28 = uVar15;
    } while (uVar15 != 0xd);
LAB_00108dcc:
    swr_master_bulk_write(lVar27,local_430 + 0x78,local_430,uVar30);
  }
LAB_00108e2c:
  lVar27 = sp_el0;
  if (*(long *)(lVar27 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// swrm_pcm_port_config @ 00108e90 size=652
// signature: undefined swrm_pcm_port_config(void)
// callers: [swrm_disable_ports, swrm_copy_data_port_config]
//------------------------------------------------------------

void swrm_pcm_port_config(long param_1,uint param_2,long *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  long *plVar6;
  
  param_2 = param_2 & 0xff;
  uVar4 = 8;
  if (*(char *)((long)param_3 + 0x1e) != '\0') {
    uVar4 = 0x10;
  }
  if (param_2 - 0xe < 0xfffffff3) {
    iVar2 = ___ratelimit(swrm_pcm_port_config__rs,"swrm_pcm_port_config");
    if (iVar2 == 0) {
      return;
    }
    _dev_err(*(undefined8 *)(param_1 + 0x2140),"%s: invalid port: %d\n","swrm_pcm_port_config",
             param_2);
    return;
  }
  if (1 < *(byte *)((long)param_3 + 0x1f) - 1) {
    return;
  }
  if (*(int *)(param_1 + 0x23a8) == 0x1070000) {
    if (*(byte *)((long)param_3 + 0x1f) == 1) {
      uVar3 = param_4 & 1;
      goto LAB_00108f5c;
    }
  }
  else {
    uVar3 = 3;
    if ((param_4 & 1) == 0) {
      uVar3 = 0;
    }
LAB_00108f5c:
    swr_master_write(param_1,param_2 * 0x100 + 0x1054,uVar3);
    if (*(int *)(param_1 + 0x23a8) != 0x1070000) goto LAB_00108fc0;
  }
  iVar2 = *(int *)(param_1 + 0x3e2c);
  if ((param_4 & 1) == 0) {
    if ((iVar2 == 0) || (*(int *)(param_1 + 0x3e2c) = iVar2 + -1, iVar2 + -1 == 0)) {
      swr_master_write(param_1,0x10,0x406);
    }
  }
  else {
    if (iVar2 == 0) {
      swr_master_write(param_1,0x10,0x41e);
      iVar2 = *(int *)(param_1 + 0x3e2c);
    }
    *(int *)(param_1 + 0x3e2c) = iVar2 + 1;
  }
LAB_00108fc0:
  plVar6 = (long *)*param_3;
  if (plVar6 != param_3) {
    do {
      uVar3 = *(uint *)(plVar6 + 4);
      if ((int)uVar3 < 0x2b110) {
        if ((uVar3 == 0xac44) || (uVar3 == 0x15888)) {
LAB_00108ff8:
          uVar1 = 0;
          if (uVar3 != 0) {
            uVar1 = *(uint *)(param_1 + 0x23b4) / uVar3;
          }
          if (*(uint *)(param_1 + 0x23b4) != uVar1 * uVar3) {
            if ((param_4 & 1) == 0) goto LAB_001090c4;
            iVar2 = param_2 * 0x100;
            uVar3 = swr_master_read(param_1,iVar2 + 0x1020U & 0xffe0);
            swr_master_write(param_1,iVar2 + 0x1020U,uVar3 | uVar4);
            uVar4 = swr_master_read(param_1,iVar2 + 0x1054U & 0xfffc);
            swr_master_write(param_1,iVar2 + 0x1054U,uVar4 | 4);
            swr_master_write(param_1,iVar2 + 0x1080,0x93);
            uVar5 = 0xa0;
            goto LAB_00109100;
          }
        }
      }
      else if ((uVar3 == 0x56220) || (uVar3 == 0x2b110)) goto LAB_00108ff8;
      plVar6 = (long *)*plVar6;
    } while (plVar6 != param_3);
  }
  if ((param_4 & 1) == 0) {
LAB_001090c4:
    swr_master_write(param_1,param_2 * 0x100 + 0x1020,0);
    swr_master_write(param_1,param_2 * 0x100 + 0x1080,1);
    uVar5 = 1;
LAB_00109100:
    swr_master_write(param_1,param_2 * 0x100 + 0x1084,uVar5);
  }
  return;
}



//------------------------------------------------------------
// swrm_enable_slave_irq @ 0010911c size=332
// signature: undefined swrm_enable_slave_irq(void)
// callers: [swr_mstr_interrupt]
//------------------------------------------------------------

void swrm_enable_slave_irq(long param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  uVar5 = swr_master_read(param_1,0x1090);
  if (uVar5 != 0) {
    iVar6 = *(int *)(param_1 + 0x23b8);
    if (iVar6 != -1) {
      uVar7 = 0;
      pbVar1 = (byte *)(param_1 + 0x235a);
      do {
        if ((uVar5 & 3) != 0) {
          if (*(char *)(param_1 + 0x3e48) == '\0') {
            bVar3 = *pbVar1;
            bVar2 = 0;
            if (bVar3 != 0xe) {
              bVar2 = bVar3 + 1 & 0xf;
            }
            *pbVar1 = bVar2;
            swrm_cmd_fifo_rd_cmd(param_1,&local_4c,uVar7,bVar3,0x40,1);
            bVar3 = *pbVar1;
            bVar2 = 0;
            if (bVar3 != 0xe) {
              bVar2 = bVar3 + 1 & 0xf;
            }
            *pbVar1 = bVar2;
            swrm_cmd_fifo_wr_cmd(param_1,0xff,uVar7,bVar3,0x40);
          }
          bVar3 = *pbVar1;
          bVar2 = 0;
          if (bVar3 != 0xe) {
            bVar2 = bVar3 + 1 & 0xf;
          }
          *pbVar1 = bVar2;
          swrm_cmd_fifo_wr_cmd(param_1,4,uVar7,bVar3,0x41);
          iVar6 = *(int *)(param_1 + 0x23b8);
        }
        uVar5 = (int)uVar5 >> 2;
        uVar7 = uVar7 + 1;
      } while (uVar7 < iVar6 + 1U);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// swrm_debug_read @ 0010926c size=224
// signature: undefined swrm_debug_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swrm_debug_read(long param_1,long param_2,long param_3,long *param_4)

{
  long lVar1;
  undefined8 uVar2;
  size_t sVar3;
  char local_40 [8];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar2 = 0xffffffffffffffea;
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  if ((((param_2 != 0) && (param_1 != 0)) && (param_3 != 0)) &&
     (((param_4 != (long *)0x0 && (*(long *)(param_1 + 0xd8) != 0)) && (-1 < *param_4)))) {
    snprintf(local_40,8,"0x%x\n",*(uint *)(*(long *)(param_1 + 0xd8) + 0x51b0));
    sVar3 = strnlen(local_40,7);
    if (7 < sVar3) {
      fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    uVar2 = simple_read_from_buffer(param_2,param_3,param_4,local_40,sVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// swrm_debug_peek_write @ 00109350 size=696
// signature: undefined swrm_debug_peek_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void swrm_debug_peek_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  bool bVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;
  bool bVar9;
  undefined8 *puVar10;
  long lVar11;
  char *local_60;
  ulong local_58 [2];
  undefined4 local_48;
  char local_40 [8];
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  uVar6 = 0xffffffffffffffea;
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_48 = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  if (((((param_2 == 0) || (param_1 == 0)) || (param_3 == 0)) ||
      ((param_4 == (long *)0x0 || (lVar11 = *(long *)(param_1 + 0xd8), lVar11 == 0)))) ||
     ((7 < param_3 || (*param_4 < 0)))) goto LAB_0010956c;
  __check_object_size(local_40,param_3,0);
  puVar10 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
     (uVar6 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
    uVar6 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar7 = param_3;
  if (0x8000000000 - param_3 < uVar6) {
LAB_001095b8:
    memset(local_40 + (param_3 - uVar7),0,uVar7);
    if ((int)uVar7 != 0) {
      uVar6 = 0xfffffffffffffff2;
      goto LAB_0010956c;
    }
  }
  else {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar7 = daif;
        daif = uVar7 | 0xc0;
      }
      puVar10 = (undefined8 *)puVar10[1];
      uVar7 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    uVar7 = __arch_copy_from_user(puVar10,local_40,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    if (uVar7 != 0) goto LAB_001095b8;
  }
  if (7 < param_3) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x1095ec);
    (*pcVar3)();
  }
  local_60 = local_40;
  local_60[param_3] = '\0';
  pcVar8 = strsep(&local_60," ");
  if (pcVar8 == (char *)0x0) {
LAB_001094e4:
    bVar9 = false;
  }
  else {
    uVar5 = 0x10;
    if ((pcVar8[1] + 0xa8U & 0xdf) != 0) {
      uVar5 = 10;
    }
    iVar4 = kstrtouint(pcVar8,uVar5,local_58);
    if (iVar4 != 0) goto LAB_001094e4;
    strsep(&local_60," ");
    bVar9 = true;
  }
  if (2 < *(uint *)(lVar11 + 0x23ac)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1095f0);
    (*pcVar3)();
  }
  bVar1 = false;
  if ((uint)local_58[0] <= *(uint *)(swrm_registers + (ulong)*(uint *)(lVar11 + 0x23ac) * 4 + 0x54))
  {
    bVar1 = bVar9;
  }
  if (((local_58[0] & 3) == 0) && (bVar1)) {
    uVar5 = swr_master_read(lVar11);
    *(undefined4 *)(lVar11 + 0x51b0) = uVar5;
    uVar6 = param_3;
  }
  else {
    iVar4 = ___ratelimit(swrm_debug_peek_write__rs,"swrm_debug_peek_write");
    if (iVar4 != 0) {
      _dev_err(*(undefined8 *)(lVar11 + 0x2140),"%s: rc = %d\n","swrm_debug_peek_write",0xffffffea);
    }
    uVar6 = 0xffffffffffffffea;
  }
LAB_0010956c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// swrm_debug_open @ 00109624 size=16
// signature: undefined swrm_debug_open(void)
// callers: []
//------------------------------------------------------------

undefined8 swrm_debug_open(long param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x2b8);
  return 0;
}



//------------------------------------------------------------
// swrm_debug_write @ 00109638 size=740
// signature: undefined swrm_debug_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void swrm_debug_write(long param_1,ulong param_2,ulong param_3,long param_4)

{
  bool bVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  bool bVar8;
  undefined4 uVar9;
  undefined8 *puVar10;
  long lVar11;
  char *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  char local_58 [32];
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  uVar5 = 0xffffffffffffffea;
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
  if ((((param_2 == 0) || (param_1 == 0)) || (param_4 == 0)) ||
     ((0x1f < param_3 || (lVar11 = *(long *)(param_1 + 0xd8), lVar11 == 0)))) goto LAB_0010982c;
  __check_object_size(local_58,param_3,0);
  puVar10 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar6 = param_3;
  if (uVar5 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar6 = daif;
        daif = uVar6 | 0xc0;
      }
      puVar10 = (undefined8 *)puVar10[1];
      uVar6 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    uVar6 = __arch_copy_from_user(puVar10,local_58,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
  }
  if ((uVar6 != 0) && (memset(local_58 + (param_3 - uVar6),0,uVar6), (int)uVar6 != 0)) {
    uVar5 = 0xfffffffffffffff2;
    goto LAB_0010982c;
  }
  if (0x1f < param_3) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x109900);
    (*pcVar3)();
  }
  local_78 = local_58;
  local_78[param_3] = '\0';
  pcVar7 = strsep(&local_78," ");
  if (pcVar7 == (char *)0x0) {
LAB_001097c4:
    bVar8 = false;
  }
  else {
    uVar9 = 0x10;
    if ((pcVar7[1] + 0xa8U & 0xdf) != 0) {
      uVar9 = 10;
    }
    iVar4 = kstrtouint(pcVar7,uVar9,&local_70);
    if ((iVar4 != 0) || (pcVar7 = strsep(&local_78," "), pcVar7 == (char *)0x0)) goto LAB_001097c4;
    uVar9 = 0x10;
    if ((pcVar7[1] + 0xa8U & 0xdf) != 0) {
      uVar9 = 10;
    }
    iVar4 = kstrtouint(pcVar7,uVar9,(ulong)&local_70 | 4);
    if (iVar4 != 0) goto LAB_001097c4;
    strsep(&local_78," ");
    bVar8 = true;
  }
  if (2 < *(uint *)(lVar11 + 0x23ac)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x109904);
    (*pcVar3)();
  }
  bVar1 = false;
  if ((uint)local_70 <= *(uint *)(swrm_registers + (ulong)*(uint *)(lVar11 + 0x23ac) * 4 + 0x54)) {
    bVar1 = bVar8;
  }
  if (((local_70 & 3) == 0) && (bVar1)) {
    swr_master_write(lVar11,local_70 & 0xffffffff,local_70._4_4_);
    uVar5 = param_3;
  }
  else {
    iVar4 = ___ratelimit(swrm_debug_write__rs,"swrm_debug_write");
    if (iVar4 != 0) {
      _printk(&DAT_0010c0fd,"swrm_debug_write",0xffffffea);
    }
    uVar5 = 0xffffffffffffffea;
  }
LAB_0010982c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// swrm_debug_reg_dump @ 00109938 size=724
// signature: undefined swrm_debug_reg_dump(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong swrm_debug_reg_dump(long param_1,long param_2,long param_3,ulong *param_4)

{
  undefined8 *puVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  ulong uVar7;
  long lVar8;
  uint param3;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  char local_88 [32];
  long local_68;
  
  lVar8 = sp_el0;
  uVar10 = 0xffffffffffffffea;
  local_68 = *(long *)(lVar8 + 0x638);
  if (((((param_2 == 0) || (param_1 == 0)) || (param_3 == 0)) ||
      ((param_4 == (ulong *)0x0 || (lVar8 = *(long *)(param_1 + 0xd8), lVar8 == 0)))) ||
     (uVar9 = *param_4, (long)uVar9 < 0)) {
LAB_00109bc4:
    lVar8 = sp_el0;
    if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return uVar10;
  }
  uVar7 = (ulong)*(uint *)(lVar8 + 0x23ac);
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
  if (*(uint *)(lVar8 + 0x23ac) < 3) {
    puVar1 = (undefined8 *)sp_el0;
    uVar10 = 0;
    do {
      if (8 < uVar7) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x109c1c);
        (*pcVar3)();
      }
      param3 = (uint)uVar9;
      if (*(uint *)(swrm_registers + uVar7 * 4 + 0x54) < param3) goto LAB_00109bc4;
      uVar11 = uVar10;
      if (0x13aa < param3 - 0x2c55) {
        usleep_range_state(100,0x96,2);
        uVar4 = swr_master_read(lVar8,uVar9 & 0xffffffff);
        uVar4 = snprintf(local_88,0x19,"0x%.3x: 0x%.2x\n",param3,uVar4);
        if ((int)uVar4 < 0) {
          iVar5 = ___ratelimit(swrm_reg_show__rs,"swrm_reg_show");
          if (iVar5 != 0) {
            puVar6 = &DAT_0010b8f2;
            goto LAB_00109c08;
          }
        }
        else {
          uVar9 = (ulong)uVar4;
          uVar11 = uVar10 + uVar9;
          if (param_3 - 1U <= uVar11) goto LAB_00109bc4;
          if (uVar4 < 0x21) {
            uVar10 = param_2 + uVar10;
            __check_object_size(local_88,uVar9,1);
            if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
               (uVar7 = uVar10, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
              uVar7 = uVar10 & (long)(uVar10 * 0x100) >> 8;
            }
            if (uVar7 <= 0x8000000000 - uVar9) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar7 = daif;
                if ((uVar7 & 0x80) == 0) {
                  uVar2 = daif;
                  daif = uVar2 | 0xc0;
                }
                uVar2 = ttbr1_el1;
                ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar1[1];
                InstructionSynchronizationBarrier();
                daif = uVar7;
              }
              uVar9 = __arch_copy_to_user(uVar10 & 0xff7fffffffffffff,local_88,uVar9);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar10 = daif;
                if ((uVar10 & 0x80) == 0) {
                  uVar7 = daif;
                  daif = uVar7 | 0xc0;
                }
                uVar7 = ttbr1_el1;
                ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar7 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar10;
              }
            }
            if (uVar9 == 0) {
              *param_4 = *param_4 + 4;
              uVar7 = (ulong)*(uint *)(lVar8 + 0x23ac);
              goto LAB_001099c8;
            }
          }
          else {
            __copy_overflow(0x20,uVar9);
          }
          iVar5 = ___ratelimit(swrm_reg_show__rs_194,"swrm_reg_show");
          if (iVar5 != 0) {
            puVar6 = &DAT_0010b911;
LAB_00109c08:
            _printk(puVar6,"swrm_reg_show");
          }
        }
        uVar10 = 0xfffffffffffffff2;
        goto LAB_00109bc4;
      }
LAB_001099c8:
      uVar9 = (ulong)(param3 + 4);
      uVar10 = uVar11;
    } while (uVar7 < 3);
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x109c20);
  (*pcVar3)();
}



//------------------------------------------------------------
// swrm_suspend @ 00109c28 size=556
// signature: undefined swrm_suspend(void)
// callers: []
//------------------------------------------------------------

void swrm_suspend(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  lVar1 = lVar5 + 0x22b0;
  mutex_lock(lVar1);
  if (*(int *)(lVar5 + 0x3dd8) == 1) {
    mutex_unlock(lVar1);
    if (lVar5 != 0) {
      mutex_lock(lVar1);
      if (*(int *)(lVar5 + 0x3dd8) == 0) {
        *(undefined4 *)(lVar5 + 0x3dd8) = 2;
        mutex_unlock(lVar1);
      }
      else {
        mutex_unlock(lVar1);
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_80 = 0;
        init_wait_entry(&local_80,0);
        lVar4 = 1;
        while( true ) {
          prepare_to_wait_event(lVar5 + 0x3de0,&local_80,2);
          mutex_lock(lVar1);
          iVar2 = *(int *)(lVar5 + 0x3dd8);
          if (iVar2 == 0) {
            *(undefined4 *)(lVar5 + 0x3dd8) = 2;
          }
          mutex_unlock(lVar1);
          if (lVar4 == 0 && iVar2 == 0) {
            lVar4 = 1;
          }
          if ((iVar2 == 0) || (lVar4 == 0)) break;
          lVar4 = schedule_timeout(lVar4);
        }
        finish_wait(lVar5 + 0x3de0,&local_80);
        if (lVar4 == 0) goto LAB_00109e18;
      }
    }
    mutex_lock(lVar1);
LAB_00109dc4:
    mutex_unlock(lVar1);
    if (((*(ushort *)(param_1 + 0x200) & 7) != 0) || (*(int *)(param_1 + 0x20c) != 2)) {
      uVar3 = swrm_runtime_suspend(param_1);
      if ((int)uVar3 != -0x10) {
        if ((int)uVar3 != 0) goto LAB_00109e1c;
        __pm_runtime_disable(param_1,1);
        __pm_runtime_set_status(param_1,2);
        pm_runtime_enable(param_1);
      }
    }
  }
  else {
    if (*(int *)(lVar5 + 0x3dd8) != 0) goto LAB_00109dc4;
    mutex_unlock(lVar1);
    lVar4 = *(long *)(lVar5 + 0x2140);
    if ((((*(ushort *)(lVar4 + 0x200) & 7) != 0) || (*(int *)(lVar4 + 0x20c) != 2)) &&
       (iVar2 = swrm_runtime_suspend(lVar4), iVar2 == 0)) {
      __pm_runtime_disable(lVar4,1);
      __pm_runtime_set_status(lVar4,2);
      pm_runtime_enable(lVar4);
    }
    mutex_lock(lVar1);
    if (*(int *)(lVar5 + 0x3dd8) != 1) {
      if (*(int *)(lVar5 + 0x3dd8) == 0) {
        *(undefined4 *)(lVar5 + 0x3dd8) = 2;
      }
      goto LAB_00109dc4;
    }
    mutex_unlock(lVar1);
  }
LAB_00109e18:
  uVar3 = 0;
LAB_00109e1c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// swrm_resume @ 00109e58 size=188
// signature: undefined swrm_resume(void)
// callers: []
//------------------------------------------------------------

int swrm_resume(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if ((*(ushort *)(param_1 + 0x200) & 7) == 0) {
    iVar2 = __pm_runtime_suspend(param_1,0);
    iVar1 = 0;
    if (iVar2 != 0) goto LAB_00109ebc;
  }
  iVar1 = swrm_runtime_resume(param_1);
  if (iVar1 == 0) {
    uVar3 = ktime_get_mono_fast_ns();
    *(undefined8 *)(param_1 + 0x220) = uVar3;
    __pm_runtime_suspend(param_1,9);
  }
LAB_00109ebc:
  mutex_lock(lVar4 + 0x22b0);
  if (*(int *)(lVar4 + 0x3dd8) == 2) {
    *(undefined4 *)(lVar4 + 0x3dd8) = 0;
  }
  mutex_unlock(lVar4 + 0x22b0);
  __wake_up(lVar4 + 0x3de0,3,0,0);
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 0010a6d4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&swr_mstr_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010a704 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&swr_mstr_driver);
  return;
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 0010f000 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [swrm_register_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 0010f008 size=1
// signature: undefined gpio_to_desc(void)
// callers: [swrm_register_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 0010f010 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [swrm_register_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010f018 size=1
// signature: undefined ___ratelimit(void)
// callers: [swrm_read, swrm_runtime_resume, swrm_event_notify, swr_master_write, swrm_debug_write, swrm_wakeup_interrupt, swrm_copy_port_config, swrm_core_vote_request, swrm_alloc_port_mem, swrm_write, swrm_debug_peek_write, swrm_connect_port, swrm_register_wake_irq, swrm_wait_for_fifo_avail, swrm_get_master_port, swr_mstr_interrupt, swrm_check_link_status, swrm_lock_sleep, swrm_cleanup_disabled_port_reqs, swrm_device_wakeup_vote, get_version_index, swrm_probe, swrm_bulk_write, swrm_debug_reg_dump, swrm_clk_request, swrm_copy_data_port_config, swr_master_read, swrm_pcm_port_config, swrm_runtime_suspend, swrm_wcd_notify, swrm_notify_work_fn, swrm_request_hw_vote, swrm_disable_ports, swrm_cmd_fifo_rd_cmd, swrm_disconnect_port, swrm_device_wakeup_unvote, swrm_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 0010f020 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [swrm_register_wake_irq, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010f028 size=1
// signature: undefined mutex_lock(void)
// callers: [swrm_read, swrm_runtime_resume, swr_master_write, swrm_wakeup_interrupt, swrm_suspend, swrm_resume, swrm_core_vote_request, swrm_wakeup_work, swrm_write, swr_master_bulk_write, swrm_connect_port, swrm_get_logical_dev_num, swrm_register_wake_irq, swr_mstr_interrupt, swrm_lock_sleep, swrm_probe, swrm_bulk_write, swrm_clk_request, swrm_cmd_fifo_wr_cmd, swrm_device_down, swr_master_read, swrm_runtime_suspend, swrm_notify_work_fn, swrm_wcd_notify, swrm_request_hw_vote, swrm_remove_from_group, swrm_cmd_fifo_rd_cmd, swrm_disconnect_port, swrm_device_wakeup_unvote, swrm_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 0010f030 size=1
// signature: undefined request_threaded_irq(void)
// callers: [swrm_register_wake_irq, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010f038 size=1
// signature: undefined mutex_unlock(void)
// callers: [swrm_read, swrm_runtime_resume, swr_master_write, swrm_wakeup_interrupt, swrm_suspend, swrm_resume, swrm_core_vote_request, swrm_wakeup_work, swrm_write, swr_master_bulk_write, swrm_connect_port, swrm_get_logical_dev_num, swrm_register_wake_irq, swr_mstr_interrupt, swrm_lock_sleep, swrm_probe, swrm_bulk_write, swrm_clk_request, swrm_cmd_fifo_wr_cmd, swrm_device_down, swr_master_read, swrm_runtime_suspend, swrm_notify_work_fn, swrm_wcd_notify, swrm_request_hw_vote, swrm_remove_from_group, swrm_cmd_fifo_rd_cmd, swrm_disconnect_port, swrm_device_wakeup_unvote, swrm_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 0010f040 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [swrm_runtime_resume, swrm_runtime_suspend, swrm_remove, swrm_register_wake_irq, swrm_wakeup_interrupt, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010f048 size=1
// signature: undefined _dev_err(void)
// callers: [swrm_read, swrm_runtime_resume, swrm_event_notify, swr_master_write, swrm_wakeup_interrupt, swrm_master_init, swrm_copy_port_config, swrm_core_vote_request, swrm_wakeup_work, swrm_alloc_port_mem, swrm_write, swrm_debug_peek_write, swrm_connect_port, swrm_get_logical_dev_num, swrm_register_wake_irq, swrm_wait_for_fifo_avail, swrm_get_master_port, swr_mstr_interrupt, swrm_check_link_status, swrm_lock_sleep, swrm_device_wakeup_vote, swrm_probe, swrm_bulk_write, swrm_clk_request, swrm_copy_data_port_config, swr_master_read, swrm_pcm_port_config, swrm_runtime_suspend, swrm_wcd_notify, swrm_notify_work_fn, swrm_request_hw_vote, swrm_cmd_fifo_rd_cmd, swrm_disconnect_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irq_data @ 0010f050 size=1
// signature: undefined irq_get_irq_data(void)
// callers: [swrm_runtime_resume, swrm_runtime_suspend, swrm_remove, swrm_wakeup_interrupt, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 0010f058 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [swrm_runtime_resume, swrm_wakeup_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010f060 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [swrm_read, swrm_wakeup_work, swrm_write, swrm_device_wakeup_vote, swrm_connect_port, swrm_wcd_notify, swrm_get_logical_dev_num, swrm_wakeup_interrupt, swrm_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0010f068 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [swrm_read, swrm_wakeup_work, swrm_write, swrm_wcd_notify, swrm_get_logical_dev_num, swrm_wakeup_interrupt, swrm_probe, swrm_bulk_write, swrm_device_wakeup_unvote, swrm_slvdev_datapath_control, swrm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0010f070 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [swrm_read, swrm_wakeup_work, swrm_write, swrm_wcd_notify, swrm_get_logical_dev_num, swrm_wakeup_interrupt, swrm_bulk_write, swrm_device_wakeup_unvote, swrm_slvdev_datapath_control, swrm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_update_request @ 0010f078 size=1
// signature: undefined cpu_latency_qos_update_request(void)
// callers: [swrm_lock_sleep, swrm_wakeup_work, swrm_wakeup_interrupt, swr_mstr_interrupt, swrm_device_wakeup_unvote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 0010f080 size=1
// signature: undefined pm_relax(void)
// callers: [swrm_lock_sleep, swrm_wakeup_work, swrm_wakeup_interrupt, swr_mstr_interrupt, swrm_device_wakeup_unvote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010f088 size=1
// signature: undefined __wake_up(void)
// callers: [swrm_lock_sleep, swrm_wakeup_work, swrm_wakeup_interrupt, swr_mstr_interrupt, swrm_device_wakeup_unvote, swrm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010f090 size=1
// signature: undefined _printk(void)
// callers: [swrm_runtime_resume, swrm_cleanup_disabled_port_reqs, swrm_device_wakeup_vote, swrm_event_notify, get_version_index, swrm_init_port_params, swrm_debug_write, swrm_wakeup_interrupt, swrm_probe, swrm_debug_reg_dump, swrm_copy_data_port_config, swrm_wakeup_work, swrm_wcd_notify, swrm_notify_work_fn, swrm_get_logical_dev_num, swrm_disable_ports, swrm_device_wakeup_unvote, swrm_slvdev_datapath_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_reset_device @ 0010f098 size=1
// signature: undefined swr_reset_device(void)
// callers: [swrm_wcd_notify, swr_mstr_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_reset_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_set_device_group @ 0010f0a0 size=1
// signature: undefined swr_set_device_group(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_set_device_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010f0a8 size=1
// signature: undefined usleep_range_state(void)
// callers: [swr_master_bulk_write, swrm_runtime_resume, swrm_runtime_suspend, swrm_wcd_notify, swrm_wait_for_fifo_avail, swr_mstr_interrupt, swrm_debug_reg_dump, swrm_cmd_fifo_rd_cmd, swrm_cmd_fifo_wr_cmd, swrm_check_link_status, swrm_master_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_disable @ 0010f0b0 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_disable(void)
// callers: [swrm_runtime_resume, swrm_runtime_suspend, swrm_wcd_notify, swrm_request_hw_vote, swr_mstr_interrupt, swrm_device_wakeup_unvote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010f0b8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [swrm_wcd_notify, swrm_cmd_fifo_wr_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_autosuspend_expiration @ 0010f0c0 size=1
// signature: undefined pm_runtime_autosuspend_expiration(void)
// callers: [swrm_wcd_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_autosuspend_expiration(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0010f0c8 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [swrm_runtime_resume, swrm_wcd_notify, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0010f0d0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [swrm_remove, swrm_device_suspend, swrm_device_down, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0010f0d8 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [swrm_remove, swrm_device_suspend, swrm_probe, swrm_device_down, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010f0e0 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [swrm_device_suspend, swrm_probe, swrm_device_down, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010f0e8 size=1
// signature: undefined complete(void)
// callers: [swr_mstr_interrupt, swrm_clk_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010f0f0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [swrm_alloc_port_mem, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010f0f8 size=1
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
// platform_driver_unregister @ 0010f100 size=1
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
// pm_stay_awake @ 0010f108 size=1
// signature: undefined pm_stay_awake(void)
// callers: [swrm_lock_sleep, swrm_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010f110 size=1
// signature: undefined init_wait_entry(void)
// callers: [swrm_lock_sleep, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010f118 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [swrm_lock_sleep, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010f120 size=1
// signature: undefined schedule_timeout(void)
// callers: [swrm_lock_sleep, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010f128 size=1
// signature: undefined finish_wait(void)
// callers: [swrm_lock_sleep, swrm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010f130 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [swrm_lock_sleep, swrm_read, swrm_enable_slave_irq, swrm_debug_write, swrm_probe, swrm_debug_reg_dump, swrm_copy_data_port_config, swrm_master_init, swrm_suspend, swrm_debug_peek_write, swrm_connect_port, swr_mstr_interrupt, swrm_debug_read, swrm_disconnect_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_down @ 0010f138 size=1
// signature: undefined swr_device_down(void)
// callers: [swrm_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_down(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0010f140 size=1
// signature: undefined enable_irq(void)
// callers: [swrm_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_enable @ 0010f148 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_enable(void)
// callers: [swrm_request_hw_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010f150 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010f158 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010f160 size=1
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
// log_post_write_mmio @ 0010f168 size=1
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
// of_property_read_variable_u32_array @ 0010f170 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0010f178 size=1
// signature: undefined devm_ioremap(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010f180 size=1
// signature: undefined of_find_property(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0010f188 size=1
// signature: undefined devm_kfree(void)
// callers: [swrm_remove, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010f190 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010f198 size=1
// signature: undefined __mutex_init(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010f1a0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_add_request @ 0010f1a8 size=1
// signature: undefined cpu_latency_qos_add_request(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010f1b0 size=1
// signature: undefined devm_clk_get(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 0010f1b8 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [swrm_remove, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 0010f1c0 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_register_master @ 0010f1c8 size=1
// signature: undefined swr_register_master(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_register_master(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_master_add_boarddevices @ 0010f1d0 size=1
// signature: undefined swr_master_add_boarddevices(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_master_add_boarddevices(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_register_swr_devices @ 0010f1d8 size=1
// signature: undefined of_register_swr_devices(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_register_swr_devices(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010f1e0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0010f1e8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0010f1f0 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010f1f8 size=1
// signature: undefined _dev_info(void)
// callers: [swrm_get_logical_dev_num, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_unregister_master @ 0010f200 size=1
// signature: undefined swr_unregister_master(void)
// callers: [swrm_remove, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_unregister_master(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 0010f208 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [swrm_remove, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 0010f210 size=1
// signature: undefined free_irq(void)
// callers: [swrm_remove, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_remove_request @ 0010f218 size=1
// signature: undefined cpu_latency_qos_remove_request(void)
// callers: [swrm_remove, swrm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0010f220 size=1
// signature: undefined cancel_work_sync(void)
// callers: [swrm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010f228 size=1
// signature: undefined __kmalloc(void)
// callers: [swrm_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010f230 size=1
// signature: undefined kfree(void)
// callers: [swrm_cleanup_disabled_port_reqs, swrm_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_port_response @ 0010f238 size=1
// signature: undefined swr_port_response(void)
// callers: [swrm_connect_port, swrm_disconnect_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_port_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010f248 size=1
// signature: undefined kmalloc_trace(void)
// callers: [swrm_connect_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010f250 size=1
// signature: undefined __list_add_valid(void)
// callers: [swrm_connect_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 0010f260 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [swr_mstr_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// handle_nested_irq @ 0010f268 size=1
// signature: undefined handle_nested_irq(void)
// callers: [swr_mstr_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void handle_nested_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010f278 size=1
// signature: undefined queue_work_on(void)
// callers: [swrm_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_up @ 0010f280 size=1
// signature: undefined swr_device_up(void)
// callers: [swrm_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010f288 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [swrm_cleanup_disabled_port_reqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010f290 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [swrm_debug_peek_write, swrm_debug_write, swrm_copy_data_port_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010f298 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [swrm_debug_reg_dump, swrm_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010f2a0 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [swrm_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0010f2a8 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [swrm_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010f2b0 size=1
// signature: undefined fortify_panic(void)
// callers: [swrm_debug_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0010f2b8 size=1
// signature: undefined __check_object_size(void)
// callers: [swrm_debug_peek_write, swrm_debug_write, swrm_debug_reg_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0010f2c8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [swrm_debug_peek_write, swrm_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0010f2d0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [swrm_debug_peek_write, swrm_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010f2d8 size=1
// signature: undefined kstrtouint(void)
// callers: [swrm_debug_peek_write, swrm_debug_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0010f2e8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [swrm_debug_reg_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __copy_overflow @ 0010f2f0 size=1
// signature: undefined __copy_overflow(void)
// callers: [swrm_debug_reg_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __copy_overflow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



