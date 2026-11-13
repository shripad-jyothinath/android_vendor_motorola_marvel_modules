// Decompiled by Ghidra 12.2
// Program: rbs_fod_mmi.ko
// Image base: 00100000

//------------------------------------------------------------
// egisfp_interrupt_timer_call @ 00100a24 size=144
// signature: undefined egisfp_interrupt_timer_call(void)
// callers: []
//------------------------------------------------------------

void egisfp_interrupt_timer_call(long param_1)

{
  char *pcVar1;
  
  _printk("[EGISFP] %s : interrupt count = %d \n","egisfp_interrupt_timer_call",
          *(undefined4 *)(param_1 + -8));
  if (*(int *)(param_1 + -8) < *(int *)(param_1 + 0x40)) {
    pcVar1 = "[EGISFP] %s : interrupt not triggered \n";
  }
  else {
    pcVar1 = "[EGISFP] %s : interrupt triggered \n";
    *(undefined4 *)(param_1 + 0x38) = 1;
  }
  _printk(pcVar1,"egisfp_interrupt_timer_call");
  *(undefined4 *)(param_1 + -8) = 0;
  __wake_up(interrupt_waitq,1,1,0);
  return;
}



//------------------------------------------------------------
// fp_eint_func @ 00100ab8 size=140
// signature: undefined fp_eint_func(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fp_eint_func(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = _jiffies;
  iVar1 = *(int *)(param_2 + 0x1a8);
  if (iVar1 == 0) {
    lVar3 = __msecs_to_jiffies(*(undefined4 *)(param_2 + 0x1ec));
    mod_timer(param_2 + 0x1b0,lVar3 + lVar2);
    iVar1 = *(int *)(param_2 + 0x1a8);
  }
  *(int *)(param_2 + 0x1a8) = iVar1 + 1;
  _printk("[EGISFP] %s : fps_ints.int_count=%d \n","fp_eint_func");
  pm_wakeup_dev_event(*(long *)(param_2 + 8) + 0x10,2000,0);
  return 1;
}



//------------------------------------------------------------
// fp_eint_func_ll @ 00100b48 size=148
// signature: undefined fp_eint_func_ll(void)
// callers: []
//------------------------------------------------------------

undefined8 fp_eint_func_ll(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_2 + 0x88);
  if (*(int *)(param_2 + 500) == 1) {
    *(undefined4 *)(param_2 + 0x1e8) = 1;
    disable_irq_nosync(*(undefined4 *)(param_2 + 0x84));
    *(undefined4 *)(param_2 + 500) = 0;
  }
  _raw_spin_unlock_irqrestore(param_2 + 0x88,uVar1);
  __wake_up(interrupt_waitq,1,1,0);
  pm_wakeup_dev_event(*(long *)(param_2 + 8) + 0x10,2000,0);
  return 1;
}



//------------------------------------------------------------
// egisfp_interrupt_init @ 00100be0 size=740
// signature: undefined egisfp_interrupt_init(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

int egisfp_interrupt_init(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  
  _printk("[EGISFP] %s :  mode = %d period = %d threshold = %d \n","egisfp_interrupt_init",param_2,
          param_3,param_4);
  _printk("[EGISFP] %s :  request_irq_done = %d gpio_irq = %d  pin = %d \n","egisfp_interrupt_init",
          *(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x84),
          *(undefined4 *)(param_1 + 0x60));
  *(undefined4 *)(param_1 + 0x1ec) = param_3;
  *(undefined4 *)(param_1 + 0x1f0) = param_4;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  if (*(int *)(param_1 + 0x8c) != 0) goto LAB_00100e0c;
  if (0x1ff < *(uint *)(param_1 + 0x60)) {
    puVar3 = &DAT_0010446c;
LAB_00100cb0:
    _printk(puVar3,"egisfp_interrupt_init");
    return -5;
  }
  gpio_to_desc();
  uVar1 = gpiod_to_irq();
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  _printk("[EGISFP] %s : fp_irq number %d \n","egisfp_interrupt_init",uVar1);
  if (*(int *)(param_1 + 0x84) < 0) {
    puVar3 = &DAT_00104806;
    goto LAB_00100cb0;
  }
  _printk("[EGISFP] %s : current flag : %d disable: %d enable: %d \n","egisfp_interrupt_init",
          *(undefined4 *)(param_1 + 500),0,1);
  switch(param_2) {
  case 0:
    _printk("[EGISFP] %s : EDGE_TRIGGER_FALLING \n","egisfp_interrupt_init");
    uVar1 = *(undefined4 *)(param_1 + 0x84);
    pcVar5 = fp_eint_func;
    uVar4 = 2;
    break;
  case 1:
    _printk("[EGISFP] %s : EDGE_TRIGGER_RISING \n","egisfp_interrupt_init");
    uVar1 = *(undefined4 *)(param_1 + 0x84);
    pcVar5 = fp_eint_func;
    uVar4 = 1;
    break;
  case 2:
    _printk("[EGISFP] %s : LEVEL_TRIGGER_LOW \n","egisfp_interrupt_init");
    uVar1 = *(undefined4 *)(param_1 + 0x84);
    pcVar5 = fp_eint_func_ll;
    uVar4 = 8;
    break;
  case 3:
    _printk("[EGISFP] %s : LEVEL_TRIGGER_HIGH \n","egisfp_interrupt_init");
    uVar1 = *(undefined4 *)(param_1 + 0x84);
    pcVar5 = fp_eint_func_ll;
    uVar4 = 4;
    break;
  default:
    goto switchD_00100d08_default;
  }
  iVar2 = request_threaded_irq(uVar1,pcVar5,0,uVar4,"fp_detect-eint",param_1);
  if (iVar2 != 0) {
    _printk(&DAT_00103be0,"egisfp_interrupt_init",iVar2);
    return iVar2;
  }
switchD_00100d08_default:
  disable_irq_nosync(*(undefined4 *)(param_1 + 0x84));
  _printk("[EGISFP] %s : request_irq return %d \n","egisfp_interrupt_init",0);
  *(undefined4 *)(param_1 + 0x8c) = 1;
LAB_00100e0c:
  _printk("[EGISFP] %s : current flag : %d disable: %d enable: %d \n","egisfp_interrupt_init",
          *(undefined4 *)(param_1 + 500),0,1);
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0x88);
  if (*(int *)(param_1 + 500) == 0) {
    *(undefined4 *)(param_1 + 500) = 1;
    _printk("[EGISFP] %s : enable irq with mode = %d \n","egisfp_interrupt_init",param_2);
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0x84),1);
    enable_irq(*(undefined4 *)(param_1 + 0x84));
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x88,uVar4);
  return 0;
}



//------------------------------------------------------------
// egisfp_interrupt_free @ 00100ec8 size=156
// signature: undefined egisfp_interrupt_free(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

undefined8 egisfp_interrupt_free(long param_1)

{
  undefined8 uVar1;
  
  _printk(&DAT_00103fd5,"egisfp_interrupt_free");
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  if (*(int *)(param_1 + 500) == 1) {
    _printk(&DAT_00103c61,"egisfp_interrupt_free");
    disable_irq_nosync(*(undefined4 *)(param_1 + 0x84));
    del_timer_sync(param_1 + 0x1b0);
    *(undefined4 *)(param_1 + 500) = 0;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x88,uVar1);
  return 0;
}



//------------------------------------------------------------
// egisfp_interrupt_poll @ 00100f68 size=136
// signature: undefined egisfp_interrupt_poll(void)
// callers: []
//------------------------------------------------------------

undefined8 egisfp_interrupt_poll(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xd8);
  if ((param_2 != (undefined8 *)0x0) && (pcVar2 = (code *)*param_2, pcVar2 != (code *)0x0)) {
    if (*(int *)(pcVar2 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100fac);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,interrupt_waitq,param_2);
    DataMemoryBarrier(2,3);
  }
  if (*(int *)(lVar3 + 0x1e8) == 0) {
    if (*(int *)(lVar3 + 0x1f8) == 1) {
      uVar1 = 0x440;
      *(undefined4 *)(lVar3 + 0x1f8) = 0;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x41;
  }
  return uVar1;
}



//------------------------------------------------------------
// egisfp_interrupt_abort @ 00100ff4 size=92
// signature: undefined egisfp_interrupt_abort(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

void egisfp_interrupt_abort(long param_1)

{
  _printk(&DAT_00103fd5,"egisfp_interrupt_abort");
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  *(undefined4 *)(param_1 + 0x1f8) = 1;
  __wake_up(interrupt_waitq,1,1,0);
  return;
}



//------------------------------------------------------------
// do_egisfp_reset @ 00101054 size=232
// signature: undefined do_egisfp_reset(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

uint do_egisfp_reset(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  
  uVar1 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x208),*(undefined8 *)(param_1 + 0x228));
  __const_udelay(0x1062560);
  uVar2 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x208),*(undefined8 *)(param_1 + 0x220));
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  uVar2 = uVar2 | uVar1;
  if (uVar2 == 0) {
    gpio_to_desc(*(undefined4 *)(param_1 + 100));
    uVar1 = gpiod_get_raw_value();
    puVar3 = &DAT_00103f51;
  }
  else {
    puVar3 = &DAT_0010442a;
    uVar1 = uVar2;
  }
  _printk(puVar3,"do_egisfp_reset",uVar1);
  return uVar2;
}



//------------------------------------------------------------
// egisfp_set_screen_onoff @ 00101140 size=108
// signature: undefined egisfp_set_screen_onoff(void)
// callers: []
//------------------------------------------------------------

undefined8 egisfp_set_screen_onoff(undefined4 param_1)

{
  undefined8 uVar1;
  
  _printk(&DAT_00103fd5,"egisfp_set_screen_onoff");
  if (g_data == 0) {
    uVar1 = 0xfffffffa;
  }
  else {
    *(undefined4 *)(g_data + 0x16c) = param_1;
    _printk(&DAT_00103a6e,"egisfp_set_screen_onoff",param_1);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// do_egisfp_power_onoff @ 001011b0 size=400
// signature: undefined do_egisfp_power_onoff(void)
// callers: [egisfp_platformfree, egisfp_ioctl]
//------------------------------------------------------------

int do_egisfp_power_onoff(long param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  long lVar6;
  
  if (*(int *)(param_1 + 0x160) == 0) {
    pcVar5 = "[EGISFP] %s : power can not control by driver \n";
  }
  else {
    iVar2 = *param_2;
    _printk(&DAT_00104d15,"do_egisfp_power_onoff",iVar2);
    if (*(int *)(param_1 + 0x168) != iVar2) {
      if (iVar2 == 0) {
        if (*(int *)(param_1 + 0x164) == 0) {
          iVar2 = regulator_disable(*(undefined8 *)(param_1 + 0x178));
        }
        else {
          iVar2 = pinctrl_select_state
                            (*(undefined8 *)(param_1 + 0x208),*(undefined8 *)(param_1 + 0x238));
        }
        if (iVar2 != 0) {
LAB_001012fc:
          _printk(&DAT_0010442a,"do_egisfp_power_onoff",iVar2);
          return iVar2;
        }
        lVar6 = -0x32;
        do {
          __const_udelay(0x418958);
          bVar1 = lVar6 != -1;
          lVar6 = lVar6 + 1;
        } while (bVar1);
        uVar3 = 0;
      }
      else {
        if (*(int *)(param_1 + 0x164) == 0) {
          iVar2 = regulator_enable(*(undefined8 *)(param_1 + 0x178));
        }
        else {
          iVar2 = pinctrl_select_state
                            (*(undefined8 *)(param_1 + 0x208),*(undefined8 *)(param_1 + 0x230));
        }
        if (iVar2 != 0) goto LAB_001012fc;
        __const_udelay(0x1062560);
        uVar3 = 1;
      }
      *(undefined4 *)(param_1 + 0x168) = uVar3;
      if (*(int *)(param_1 + 0x164) == 0) {
        uVar3 = regulator_is_enabled(*(undefined8 *)(param_1 + 0x178));
        uVar4 = regulator_get_voltage(*(undefined8 *)(param_1 + 0x178));
        _printk(&DAT_00103a8e,"do_egisfp_power_onoff",uVar3,uVar4);
        return 0;
      }
      gpio_to_desc(*(undefined4 *)(param_1 + 0x6c));
      uVar3 = gpiod_get_raw_value();
      _printk(&DAT_00103fe5,"do_egisfp_power_onoff",uVar3);
      return 0;
    }
    pcVar5 = "[EGISFP] %s : duplicate set power on/off \n";
  }
  _printk(pcVar5,"do_egisfp_power_onoff");
  return 0;
}



//------------------------------------------------------------
// do_egisfp_reset_set @ 00101344 size=164
// signature: undefined do_egisfp_reset_set(void)
// callers: [egisfp_platformfree, egisfp_ioctl]
//------------------------------------------------------------

int do_egisfp_reset_set(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  _printk(&DAT_0010422d,"do_egisfp_reset_set",param_2);
  lVar1 = 0x228;
  if (param_2 != 0) {
    lVar1 = 0x220;
  }
  iVar2 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x208),*(undefined8 *)(param_1 + lVar1));
  if (iVar2 == 0) {
    gpio_to_desc(*(undefined4 *)(param_1 + 100));
    iVar3 = gpiod_get_raw_value();
    puVar4 = &DAT_00103c1f;
  }
  else {
    puVar4 = &DAT_0010442a;
    iVar3 = iVar2;
  }
  _printk(puVar4,"do_egisfp_reset_set",iVar3);
  return iVar2;
}



//------------------------------------------------------------
// egisfp_ioctl @ 001013ec size=2508
// signature: undefined egisfp_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void egisfp_ioctl(long param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  size_t __n;
  undefined *puVar5;
  undefined8 *puVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  undefined8 local_48;
  ulong local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_48 = 0;
  local_40 = 0;
  _printk("[EGISFP] %s : cmd = 0x%X \n","egisfp_ioctl",param_2);
  lVar9 = *(long *)(param_1 + 0xd8);
  if (*(int *)(lVar9 + 0x7c) == 0) {
    _printk(&DAT_00104bdb,"egisfp_ioctl");
    lVar9 = -0x13;
    goto LAB_00101950;
  }
  if ((1 < param_2 - 0x11U) && (*(int *)(lVar9 + 0x80) == 0)) {
    _printk(&DAT_00104102,"egisfp_check_ioctl_permission");
    lVar9 = -0xd;
    goto LAB_00101950;
  }
  iVar2 = 0;
  uVar7 = (uint)_cpu_hwcaps;
  switch(param_2) {
  case 4:
    _printk(&DAT_00103b9e,"egisfp_ioctl");
    do_egisfp_reset(lVar9);
    break;
  case 5:
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if ((uVar7 >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar4 = __arch_copy_from_user(puVar6,&local_48,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar4 == 0) {
        _printk(&DAT_0010437b,"egisfp_ioctl");
        iVar2 = do_egisfp_power_onoff(lVar9,&local_48);
        goto switchD_0010147c_caseD_a;
      }
    }
    goto LAB_00101c64;
  case 6:
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if ((uVar7 >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar4 = __arch_copy_from_user(puVar6,&local_48,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar4 == 0) {
        *(int *)(lVar9 + 0x200) = (int)local_48 * 1000000;
        _printk(&DAT_00103c7f,"egisfp_ioctl");
        break;
      }
    }
    goto LAB_00101c64;
  case 7:
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if ((uVar7 >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar4 = __arch_copy_from_user(puVar6,&local_48,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar4 == 0) {
        _printk(&DAT_0010400c,"egisfp_ioctl");
        iVar2 = do_egisfp_reset_set(lVar9,local_48 & 0xffffffff);
        goto switchD_0010147c_caseD_a;
      }
    }
    goto LAB_00101c64;
  case 8:
    _printk(&DAT_00103e9e,"egisfp_ioctl");
    pm_stay_awake(*(long *)(lVar9 + 8) + 0x10);
    break;
  case 9:
    _printk(&DAT_00104564,"egisfp_ioctl");
    pm_relax(*(long *)(lVar9 + 8) + 0x10);
    break;
  default:
    goto switchD_0010147c_caseD_a;
  case 0x11:
    _printk(&DAT_00103e7c,"egisfp_ioctl");
    iVar3 = egisfp_platforminit(lVar9);
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = -5;
    }
    goto switchD_0010147c_caseD_a;
  case 0x12:
    _printk(&DAT_00104253,"egisfp_ioctl");
    egisfp_platformfree(lVar9);
    break;
  case 0x21:
    _printk(&DAT_00103da1,"egisfp_ioctl");
    egis_get_io_stus(lVar9);
    break;
  case 0x31:
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if ((uVar7 >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar4 = __arch_copy_from_user(puVar6,&local_48,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar4 == 0) {
        _printk(&DAT_00104bfe,"egisfp_ioctl");
        send_navi_event(lVar9,local_48 & 0xffffffff);
        break;
      }
    }
    goto LAB_00101c64;
  case 0xa4:
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if ((uVar7 >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar4 = __arch_copy_from_user(puVar6,&local_48,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar4 == 0) {
        iVar2 = egisfp_interrupt_init
                          (lVar9,local_48 & 0xffffffff,local_48._4_4_,local_40 & 0xffffffff);
        _printk(&DAT_00103ac8,"egisfp_ioctl",iVar2);
        goto switchD_0010147c_caseD_a;
      }
    }
    goto LAB_00101c64;
  case 0xa5:
    egisfp_interrupt_free(lVar9);
    _printk(&DAT_00104723,"egisfp_ioctl",0);
    break;
  case 0xa8:
    _printk(&DAT_00104b1c,"egisfp_ioctl");
    egisfp_interrupt_abort(lVar9);
    break;
  case 0xac:
    puVar5 = &DAT_00104509;
    goto LAB_00101ce0;
  case 0xaf:
    puVar5 = &DAT_00104ecd;
    goto LAB_00101ce0;
  case 0xb1:
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if ((uVar7 >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      __n = __arch_copy_from_user(puVar6,&local_48,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (__n != 0) goto LAB_00101cf4;
      if ((int)local_48 == 0) goto LAB_00101a94;
    }
    else {
      __n = 0x10;
LAB_00101cf4:
      memset((void *)((long)&local_38 - __n),0,__n);
LAB_00101a94:
      local_48 = CONCAT44(local_48._4_4_,2000);
    }
    _printk(&DAT_0010458a,"egisfp_ioctl");
    pm_wakeup_dev_event(*(long *)(lVar9 + 8) + 0x10,local_48 & 0xffffffff,0);
    break;
  case 0xb2:
    puVar5 = &DAT_001049c2;
LAB_00101ce0:
    _printk(puVar5,"egisfp_ioctl");
    break;
  case 0xb3:
    _printk(&DAT_001040a3,"egisfp_ioctl");
    puVar6 = (undefined8 *)sp_el0;
    local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)(lVar9 + 0x16c));
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff1) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar9 = __arch_copy_to_user(puVar6,param_3 & 0xff7fffffffffffff,&local_48,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar9 == 0) break;
    }
LAB_00101c64:
    lVar9 = -0xe;
    goto LAB_00101950;
  }
  iVar2 = 0;
switchD_0010147c_caseD_a:
  _printk(&DAT_001049f0,"egisfp_ioctl");
  lVar9 = (long)iVar2;
LAB_00101950:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar9);
  }
  return;
}



//------------------------------------------------------------
// egisfp_check_ioctl_permission @ 00101e64 size=76
// signature: undefined egisfp_check_ioctl_permission(void)
// callers: []
//------------------------------------------------------------

undefined8 egisfp_check_ioctl_permission(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if ((param_2 - 0x11U < 2) || (*(int *)(param_1 + 0x80) != 0)) {
    uVar1 = 0;
  }
  else {
    _printk(&DAT_00104102,"egisfp_check_ioctl_permission");
    uVar1 = 0xfffffff3;
  }
  return uVar1;
}



//------------------------------------------------------------
// egisfp_platforminit @ 00101eb4 size=1012
// signature: undefined egisfp_platforminit(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

undefined8 egisfp_platforminit(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined *puVar5;
  
  _printk("[EGISFP] %s : Version %s \n","egisfp_platforminit","20210517");
  if (param_1 == 0) {
    _printk(&DAT_00104679,"egisfp_platforminit");
    return 0xffffffed;
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    _printk("[EGISFP] %s : platform already init \n","egisfp_platforminit");
    return 0;
  }
  if (*(int *)(param_1 + 0x160) != 0) {
    if (*(int *)(param_1 + 0x164) == 0) {
      uVar4 = devm_regulator_get(*(long *)(param_1 + 8) + 0x10,"vcc_fp");
      *(ulong *)(param_1 + 0x178) = uVar4;
      if (0xfffffffffffff000 < uVar4) {
        _printk(&DAT_001040c6,"egisfp_platforminit");
        return 0xfffffffb;
      }
      iVar1 = regulator_count_voltages(uVar4);
      if (0 < iVar1) {
        iVar1 = regulator_set_voltage
                          (*(undefined8 *)(param_1 + 0x178),*(undefined4 *)(param_1 + 400),
                           *(undefined4 *)(param_1 + 0x18c));
        if (iVar1 == 0) {
          iVar1 = regulator_set_load(*(undefined8 *)(param_1 + 0x178),
                                     *(undefined4 *)(param_1 + 0x188));
          if (iVar1 == 0) goto LAB_00101f14;
          puVar5 = &DAT_001039ec;
        }
        else {
          puVar5 = &DAT_00104c43;
        }
        _printk(puVar5,"egisfp_platforminit",iVar1);
        goto LAB_001021b4;
      }
    }
    else {
      iVar1 = gpio_request(*(undefined4 *)(param_1 + 0x6c),"egis_dev-33v-gpio");
      if (iVar1 < 0) {
        _printk(&DAT_001045e3,"egisfp_platforminit");
        return 0xfffffffb;
      }
      uVar3 = gpio_to_desc(*(undefined4 *)(param_1 + 0x6c));
      gpiod_direction_output_raw(uVar3,0);
    }
  }
LAB_00101f14:
  iVar1 = gpio_request(*(undefined4 *)(param_1 + 100),"egis_dev-reset-gpio");
  if (iVar1 < 0) {
    _printk(&DAT_00104a05,"egisfp_platforminit");
    goto LAB_001021b4;
  }
  uVar3 = gpio_to_desc(*(undefined4 *)(param_1 + 100));
  gpiod_direction_output_raw(uVar3,0);
  iVar1 = gpio_request(*(undefined4 *)(param_1 + 0x60),"egis_dev-irq-gpio");
  if (iVar1 < 0) {
    _printk(&DAT_00103b1f,"egisfp_platforminit");
  }
  else {
    gpio_to_desc(*(undefined4 *)(param_1 + 0x60));
    gpiod_direction_input();
    if (*(long *)(param_1 + 8) == 0) goto LAB_00102020;
    _printk("[EGISFP] %s : find node enter \n","egisfp_platforminit");
    uVar4 = devm_pinctrl_get(*(long *)(param_1 + 8) + 0x10);
    *(ulong *)(param_1 + 0x208) = uVar4;
    if (uVar4 < 0xfffffffffffff001) {
      uVar4 = pinctrl_lookup_state(uVar4,"egis_rst_high");
      *(ulong *)(param_1 + 0x220) = uVar4;
      if (0xfffffffffffff000 < uVar4) {
        puVar5 = &DAT_00103f72;
        goto LAB_00102178;
      }
      uVar4 = pinctrl_lookup_state(*(undefined8 *)(param_1 + 0x208),"egis_rst_low");
      *(ulong *)(param_1 + 0x228) = uVar4;
      if (0xfffffffffffff000 < uVar4) {
        puVar5 = &DAT_00103ef8;
        goto LAB_00102178;
      }
      iVar2 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x208),uVar4);
      if (iVar2 == 0) {
        uVar4 = pinctrl_lookup_state(*(undefined8 *)(param_1 + 0x208),"egis_irq_active");
        *(ulong *)(param_1 + 0x240) = uVar4;
        if (uVar4 < 0xfffffffffffff001) {
          iVar2 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x208),uVar4);
          if (iVar2 != 0) goto LAB_00102184;
          if ((*(int *)(param_1 + 0x164) == 0) || (*(int *)(param_1 + 0x160) == 0)) {
LAB_00102020:
            *(undefined4 *)(param_1 + 0x80) = 1;
            if ((*(int *)(param_1 + 0x164) == 0) || (*(int *)(param_1 + 0x160) == 0)) {
              _printk("[EGISFP] %s : successful status = %d gpio num -> rst = %d Irq = %d \n",
                      "egisfp_platforminit",iVar1,*(undefined4 *)(param_1 + 100),
                      *(undefined4 *)(param_1 + 0x60));
              return 0;
            }
            _printk("[EGISFP] %s : successful status = %d gpio num -> vcc = %d rst = %d Irq = %d \n"
                    ,"egisfp_platforminit",iVar1,*(undefined4 *)(param_1 + 0x6c),
                    *(undefined4 *)(param_1 + 100),*(undefined4 *)(param_1 + 0x60));
            return 0;
          }
          uVar4 = pinctrl_lookup_state(*(undefined8 *)(param_1 + 0x208),"egis_vcc_high");
          *(ulong *)(param_1 + 0x230) = uVar4;
          if (uVar4 < 0xfffffffffffff001) {
            uVar4 = pinctrl_lookup_state(*(undefined8 *)(param_1 + 0x208),"egis_vcc_low");
            *(ulong *)(param_1 + 0x238) = uVar4;
            if (uVar4 < 0xfffffffffffff001) {
              iVar2 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x208),uVar4);
              if (iVar2 == 0) goto LAB_00102020;
              goto LAB_00102184;
            }
            puVar5 = &DAT_00104f07;
          }
          else {
            puVar5 = &DAT_0010474b;
          }
        }
        else {
          puVar5 = &DAT_00104a47;
        }
        goto LAB_00102178;
      }
    }
    else {
      puVar5 = &DAT_00104046;
LAB_00102178:
      _printk(puVar5,"egisfp_platforminit");
    }
LAB_00102184:
    _printk(&DAT_00104872,"egisfp_platforminit");
    devm_pinctrl_put(*(undefined8 *)(param_1 + 0x208));
    *(undefined8 *)(param_1 + 0x208) = 0;
    gpio_free(*(undefined4 *)(param_1 + 0x60));
  }
  gpio_free(*(undefined4 *)(param_1 + 100));
LAB_001021b4:
  if (*(int *)(param_1 + 0x160) != 0) {
    if (*(int *)(param_1 + 0x164) == 0) {
      devm_regulator_put(*(undefined8 *)(param_1 + 0x178));
    }
    else {
      gpio_free(*(undefined4 *)(param_1 + 0x6c));
    }
  }
  return 0xfffffffb;
}



//------------------------------------------------------------
// egisfp_platformfree @ 001022ac size=400
// signature: undefined egisfp_platformfree(void)
// callers: [egisfp_ioctl, egisfp_release]
//------------------------------------------------------------

undefined4 egisfp_platformfree(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  _printk(&DAT_00104d38,"egisfp_platformfree");
  if (*(int *)(param_1 + 0x80) != 1) {
    uVar1 = 0;
    goto LAB_001022f8;
  }
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x8c) == 1) {
      if (*(int *)(param_1 + 500) == 1) {
        disable_irq_nosync(*(undefined4 *)(param_1 + 0x84));
        *(undefined4 *)(param_1 + 500) = 0;
      }
      free_irq(*(undefined4 *)(param_1 + 0x84),param_1);
      *(undefined4 *)(param_1 + 0x8c) = 0;
    }
    uVar1 = do_egisfp_reset_set(param_1,0);
    if ((*(int *)(param_1 + 0x168) != 0) && (*(int *)(param_1 + 0x160) != 0)) {
      uVar1 = do_egisfp_power_onoff(param_1,&local_38);
    }
    gpio_free(*(undefined4 *)(param_1 + 0x60));
    gpio_free(*(undefined4 *)(param_1 + 100));
    if (*(int *)(param_1 + 0x164) == 0) {
      if (*(long *)(param_1 + 0x178) == 0) goto LAB_001023b4;
LAB_0010240c:
      _printk(&DAT_001043c7,"egisfp_platformfree");
      devm_regulator_put(*(undefined8 *)(param_1 + 0x178));
      *(undefined8 *)(param_1 + 0x178) = 0;
      lVar2 = *(long *)(param_1 + 0x208);
    }
    else {
      gpio_free(*(undefined4 *)(param_1 + 0x6c));
      if (*(long *)(param_1 + 0x178) != 0) goto LAB_0010240c;
LAB_001023b4:
      lVar2 = *(long *)(param_1 + 0x208);
    }
    if (lVar2 != 0) {
      _printk(&DAT_00103ec3,"egisfp_platformfree");
      devm_pinctrl_put(*(undefined8 *)(param_1 + 0x208));
      *(undefined8 *)(param_1 + 0x208) = 0;
    }
  }
  *(undefined4 *)(param_1 + 0x80) = 0;
  _printk(&DAT_001039c3,"egisfp_platformfree",uVar1);
LAB_001022f8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}



//------------------------------------------------------------
// egis_get_io_stus @ 0010243c size=188
// signature: undefined egis_get_io_stus(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

void egis_get_io_stus(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  _printk("[EGISFP] %s \n","egis_get_io_stus");
  if (*(int *)(param_1 + 0x160) != 0) {
    if (*(int *)(param_1 + 0x164) == 0) {
      uVar1 = regulator_is_enabled(*(undefined8 *)(param_1 + 0x178));
      pcVar3 = "[EGISFP] %s : regulator vcc enable = %d \n";
    }
    else {
      gpio_to_desc(*(undefined4 *)(param_1 + 0x6c));
      uVar1 = gpiod_get_raw_value();
      pcVar3 = "[EGISFP] %s : power_pin value = %d \n";
    }
    _printk(pcVar3,"egis_get_io_stus",uVar1);
  }
  gpio_to_desc(*(undefined4 *)(param_1 + 100));
  uVar1 = gpiod_get_raw_value();
  gpio_to_desc(*(undefined4 *)(param_1 + 0x60));
  uVar2 = gpiod_get_raw_value();
  _printk("[EGISFP] %s : reset_pin value = %d irq_pin value = %d \n","egis_get_io_stus",uVar1,uVar2)
  ;
  return;
}



//------------------------------------------------------------
// send_navi_event @ 001024f8 size=188
// signature: undefined send_navi_event(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

void send_navi_event(long param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 9) {
    uVar1 = *(undefined4 *)(&DAT_001035c0 + (long)(int)param_2 * 4);
    _printk((&PTR_DAT_00103578)[(int)param_2],"send_navi_event");
    input_event(*(undefined8 *)(param_1 + 0x70),1,uVar1,1);
    input_event(*(undefined8 *)(param_1 + 0x70),0,0,0);
    input_event(*(undefined8 *)(param_1 + 0x70),1,uVar1,0);
    input_event(*(undefined8 *)(param_1 + 0x70),0,0,0);
  }
  else {
    _printk(&DAT_00104af4,"send_navi_event");
  }
  return;
}



//------------------------------------------------------------
// egisfp_open @ 001025b8 size=312
// signature: undefined egisfp_open(void)
// callers: []
//------------------------------------------------------------

int egisfp_open(long param_1,long param_2)

{
  int iVar1;
  undefined **ppuVar2;
  
  _printk(&DAT_00103fd5,"egisfp_open");
  mutex_lock(&device_list_lock);
  ppuVar2 = &device_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &device_list) {
      _printk(&DAT_0010482b,"egisfp_open",*(uint *)(param_1 + 0x4c) & 0xfffff);
      iVar1 = -6;
      goto LAB_001026a8;
    }
  } while (*(int *)(ppuVar2 + -2) != *(int *)(param_1 + 0x4c));
  if (((*(long *)(ppuVar2[-1] + 0x2f8) == 0) || (*(int *)((long)ppuVar2 + 0x6c) != 0)) ||
     (iVar1 = egisfp_parse_dt(ppuVar2 + -2), iVar1 == 0)) {
    *(undefined4 *)((long)ppuVar2 + 0x6c) = 1;
    *(int *)(ppuVar2 + 8) = *(int *)(ppuVar2 + 8) + 1;
    *(undefined ***)(param_2 + 0xd8) = ppuVar2 + -2;
    nonseekable_open(param_1,param_2);
    _printk("[EGISFP] %s : open ioctl user count = %d \n","egisfp_open",*(undefined4 *)(ppuVar2 + 8)
           );
    iVar1 = 0;
  }
  else {
    _printk(&DAT_001041d3,"egisfp_open",iVar1);
  }
LAB_001026a8:
  mutex_unlock(&device_list_lock);
  return iVar1;
}



//------------------------------------------------------------
// egisfp_parse_dt @ 001026f4 size=640
// signature: undefined egisfp_parse_dt(void)
// callers: [egisfp_open]
//------------------------------------------------------------

undefined4 egisfp_parse_dt(long param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  undefined4 local_44;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 8) + 0x2f8);
  _printk("[EGISFP] %s : start \n","egisfp_parse_dt");
  if (lVar6 == 0) {
    uVar2 = 0xffffffed;
    pcVar4 = "\x013[EGISFP] %s : device node is null \n";
    goto LAB_00102934;
  }
  lVar5 = of_find_property(lVar6,"fp-ctrl-power",0);
  *(uint *)(param_1 + 0x160) = (uint)(lVar5 != 0);
  if (lVar5 != 0) {
    lVar5 = of_find_property(lVar6,"fp-gpio-vcc-enable",0);
    *(uint *)(param_1 + 0x164) = (uint)(lVar5 != 0);
    if (lVar5 == 0) {
      iVar3 = of_property_read_variable_u32_array(lVar6,"egis-fp,vcc-voltage",&local_40,2,0);
      if (iVar3 < 0) {
        uVar2 = 0xffffffed;
        pcVar4 = "\x013[EGISFP] %s : fail to get vcc regulator voltage \n";
        goto LAB_00102934;
      }
      _printk("[EGISFP] %s : vcc regulator voltage get Max = %d, Min = %d \n","egisfp_parse_dt",
              local_40._4_4_,local_40 & 0xffffffff);
      *(undefined4 *)(param_1 + 0x18c) = local_40._4_4_;
      *(undefined4 *)(param_1 + 400) = (undefined4)local_40;
      iVar3 = of_property_read_variable_u32_array(lVar6,"egis-fp,vcc-current",&local_44,1,0);
      if (iVar3 < 0) {
        uVar2 = 0xffffffed;
        pcVar4 = "\x013[EGISFP]  %s : fail to get vcc regulator current_supply \n";
        goto LAB_00102934;
      }
      _printk("[EGISFP] %s : vcc regulator current get %d \n","egisfp_parse_dt",local_44);
      *(undefined4 *)(param_1 + 0x188) = local_44;
    }
    else {
      uVar2 = of_get_named_gpio_flags(lVar6,"egistec,gpio_vcc_en",0,0);
      *(undefined4 *)(param_1 + 0x6c) = uVar2;
      _printk("[EGISFP] %s : vcc_33v_pin gpio num is %d \n","egisfp_parse_dt",uVar2);
      if (0x1ff < *(uint *)(param_1 + 0x6c)) {
        uVar2 = 0xffffffed;
        pcVar4 = "\x013[EGISFP] %s : vcc_33v_pin gpio is invalid \n";
        goto LAB_00102934;
      }
    }
  }
  uVar2 = of_get_named_gpio_flags(lVar6,"egistec,gpio_reset",0,0);
  *(undefined4 *)(param_1 + 100) = uVar2;
  _printk("[EGISFP] %s : rst pin gpio num is %d \n","egisfp_parse_dt",uVar2);
  uVar2 = 0xffffffed;
  if (*(uint *)(param_1 + 100) < 0x200) {
    uVar2 = of_get_named_gpio_flags(lVar6,"egistec,gpio_irq",0,0);
    *(undefined4 *)(param_1 + 0x60) = uVar2;
    _printk("[EGISFP] %s : irq pin gpio num is %d \n","egisfp_parse_dt",uVar2);
    bVar1 = 0x1ff < *(uint *)(param_1 + 0x60);
    pcVar4 = "[EGISFP] %s : successful \n";
    if (bVar1) {
      pcVar4 = "\x013[EGISFP] %s : irq pin gpio is invalid \n";
    }
    uVar2 = 0;
    if (bVar1) {
      uVar2 = 0xffffffed;
    }
  }
  else {
    pcVar4 = "\x013[EGISFP] %s : rst pin gpio is invalid \n";
  }
LAB_00102934:
  _printk(pcVar4,"egisfp_parse_dt");
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// egisfp_release @ 00102978 size=144
// signature: undefined egisfp_release(void)
// callers: []
//------------------------------------------------------------

undefined8 egisfp_release(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  _printk(&DAT_00103fd5,"egisfp_release");
  mutex_lock(&device_list_lock);
  lVar2 = *(long *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  iVar1 = *(int *)(lVar2 + 0x50) + -1;
  *(int *)(lVar2 + 0x50) = iVar1;
  if (iVar1 == 0) {
    _printk("[EGISFP] %s : egis_dev->users == %d \n","egisfp_release",0);
    egisfp_platformfree(lVar2);
  }
  mutex_unlock(&device_list_lock);
  return 0;
}



//------------------------------------------------------------
// egisfp_remove @ 00102a0c size=244
// signature: undefined egisfp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 egisfp_remove(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0xa8);
  _printk("[EGISFP] %s : driver remove \n","egisfp_remove");
  if (puVar5[0x23] != 0) {
    free_irq(puVar5[0x21],puVar5);
  }
  del_timer_sync(puVar5 + 0x6c);
  lVar4 = *(long *)(puVar5 + 2);
  device_wakeup_disable(lVar4 + 0x10);
  device_set_wakeup_capable(lVar4 + 0x10,0);
  puVar5[0x23] = 0;
  if (*(long *)(puVar5 + 0x1c) != 0) {
    input_unregister_device();
  }
  device_destroy(egisfp_class,*puVar5);
  uVar3 = __list_del_entry_valid(puVar5 + 4);
  if ((uVar3 & 1) != 0) {
    lVar4 = *(long *)(puVar5 + 4);
    plVar1 = *(long **)(puVar5 + 6);
    *(long **)(lVar4 + 8) = plVar1;
    *plVar1 = lVar4;
  }
  uVar2 = egisfp_class;
  *(undefined8 *)(puVar5 + 4) = 0xdead000000000100;
  *(undefined8 *)(puVar5 + 6) = 0xdead000000000122;
  class_destroy(uVar2);
  __unregister_chrdev(100,0,0x100,PTR_s_esfp0_001038d0);
  g_data = 0;
  return 0;
}



//------------------------------------------------------------
// egisfp_probe @ 00102b04 size=1052
// signature: undefined egisfp_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong egisfp_probe(long param_1)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  uint *puVar9;
  long lVar10;
  undefined *puVar11;
  ulong uVar12;
  ulong uVar13;
  
  _printk("[EGISFP] %s : driver init \n","egisfp_probe");
  uVar8 = __register_chrdev(100,0,0x100,"egis_fp",&egisfp_fops);
  if ((int)uVar8 < 0) {
    uVar13 = (ulong)uVar8;
    _printk(&DAT_00103a22,"egisfp_probe");
    goto LAB_00102db0;
  }
  egisfp_class = __class_create(&__this_module,"egis_fp",&egisfp_probe___key);
  if (0xfffffffffffff000 < egisfp_class) {
    _printk(&DAT_00104bb6,"egisfp_probe");
    __unregister_chrdev(100,0,0x100,PTR_s_esfp0_001038d0);
    uVar13 = egisfp_class & 0xffffffff;
    goto LAB_00102db0;
  }
  puVar9 = (uint *)kmalloc_trace(_init_timer_key,0xdc0,0x268);
  if (puVar9 == (uint *)0x0) {
    _printk(&DAT_00104b40,"egisfp_probe");
    uVar13 = 0xfffffff4;
    goto LAB_00102db0;
  }
  *(uint **)(param_1 + 0xa8) = puVar9;
  *(long *)(puVar9 + 2) = param_1;
  puVar9[0x22] = 0;
  device_set_wakeup_capable(param_1 + 0x10,1);
  device_wakeup_enable(param_1 + 0x10);
  __mutex_init(&device_list_lock,"&device_list_lock",0x1036a9);
  puVar1 = puVar9 + 4;
  *(uint **)(puVar9 + 4) = puVar1;
  *(uint **)(puVar9 + 6) = puVar1;
  puVar9[0x1f] = 0;
  puVar9[0x20] = 0;
  puVar9[0x7d] = 0;
  puVar9[0x65] = 0;
  puVar9[0x23] = 0;
  puVar9[0x5a] = 0;
  puVar9[0x5b] = 0;
  puVar9[0x5c] = 0;
  mutex_lock(&device_list_lock);
  uVar7 = egisfp_class;
  uVar12 = ~(minors | 0xffffffff00000000);
  uVar12 = (uVar12 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar12 & 0x5555555555555555) << 1;
  uVar12 = (uVar12 & 0xcccccccccccccccc) >> 2 | (uVar12 & 0x3333333333333333) << 2;
  uVar12 = (uVar12 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar12 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar12 = (uVar12 & 0xff00ff00ff00ff00) >> 8 | (uVar12 & 0xff00ff00ff00ff) << 8;
  uVar13 = (uVar12 & 0xffff0000ffff0000) >> 0x10 | (uVar12 & 0xffff0000ffff) << 0x10;
  uVar12 = 0x20;
  if ((minors | 0xffffffff00000000) != 0xffffffffffffffff) {
    uVar12 = LZCOUNT(uVar13 >> 0x20 | uVar13 << 0x20);
  }
  if (uVar12 < 0x20) {
    uVar8 = (uint)uVar12 | 0x6400000;
    *puVar9 = uVar8;
    uVar13 = device_create(uVar7,*(long *)(puVar9 + 2) + 0x10,uVar8,puVar9,"esfp0");
    puVar4 = device_list;
    if ((0xfffffffffffff000 < uVar13) && ((int)uVar13 != 0)) goto LAB_00102d70;
    Hint_Prefetch(0x1036b0,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(0x1036b0,0x10);
      if (bVar3) {
        cVar2 = ExclusiveMonitorsStatus();
        minors = minors | 1L << (uVar12 & 0x3f);
      }
    } while (cVar2 != '\0');
    uVar12 = __list_add_valid(puVar1,&device_list,device_list);
    if ((uVar12 & 1) != 0) {
      *(uint **)(puVar4 + 8) = puVar1;
      *(undefined **)(puVar9 + 4) = puVar4;
      *(undefined ***)(puVar9 + 6) = &device_list;
      device_list = (undefined *)puVar1;
    }
    mutex_unlock(&device_list_lock);
    lVar10 = input_allocate_device();
    *(long *)(puVar9 + 0x1c) = lVar10;
    if (lVar10 == 0) {
      _printk(&DAT_001047a8,"egisfp_probe");
      uVar13 = 0xfffffff4;
      goto LAB_00102d7c;
    }
    input_set_capability(lVar10,1,0x26a);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x26b);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x26d);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x26c);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x268);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x26e);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x66);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x266);
    input_set_capability(*(undefined8 *)(puVar9 + 0x1c),1,0x267);
    **(undefined8 **)(puVar9 + 0x1c) = "uinput-egis";
    *(undefined2 *)(*(long *)(puVar9 + 0x1c) + 0x1a) = 0x1f;
    uVar12 = input_register_device(*(undefined8 *)(puVar9 + 0x1c));
    uVar13 = uVar12 & 0xffffffff;
    if ((int)uVar12 != 0) {
      _printk(&DAT_001048ed,"egisfp_probe",uVar13);
      if (*(long *)(puVar9 + 0x1c) != 0) {
        input_free_device();
      }
      goto LAB_00102d7c;
    }
    init_timer_key(puVar9 + 0x6c,egisfp_interrupt_timer_call,0,0,0);
    uVar5 = DAT_00103568;
    puVar4 = egisfp_noti_block;
    puVar11 = &DAT_0010417c;
    uVar12 = 0;
    puVar9[0x5c] = 1;
    uVar6 = DAT_00103570;
    *(undefined **)(puVar9 + 0x92) = puVar4;
    *(undefined8 *)(puVar9 + 0x94) = uVar5;
    *(undefined8 *)(puVar9 + 0x96) = uVar6;
    g_data = puVar9;
  }
  else {
    _printk(&DAT_00104077,"egisfp_probe");
    uVar13 = 0xffffffed;
LAB_00102d70:
    mutex_unlock(&device_list_lock);
LAB_00102d7c:
    device_destroy(egisfp_class,*puVar9);
    class_destroy(egisfp_class);
    kfree(puVar9);
    puVar11 = &DAT_00104352;
    uVar12 = uVar13 & 0xffffffff;
  }
  _printk(puVar11,"egisfp_probe",uVar12);
LAB_00102db0:
  return uVar13 & 0xffffffff;
}



//------------------------------------------------------------
// egisfp_fb_callback @ 00102f30 size=292
// signature: undefined egisfp_fb_callback(void)
// callers: []
//------------------------------------------------------------

void egisfp_fb_callback(long param_1,long param_2,long param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  char *local_38;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = (char *)0x0;
  if (param_2 == 9) {
    _printk("[EGISFP] %s : got notify value = %d \n","egisfp_fb_callback",9);
    if (param_3 != 0) {
      uVar3 = 1;
      if ((param_1 == 0x248) || (*(int **)(param_3 + 8) == (int *)0x0)) goto LAB_00102f60;
      iVar1 = **(int **)(param_3 + 8);
      _printk("[EGISFP] %s : blank value = %d \n","egisfp_fb_callback",iVar1);
      if (iVar1 == 0) {
        uVar4 = 1;
        local_38 = "PANEL=1";
        *(undefined4 *)(param_1 + -0xdc) = 1;
      }
      else if (iVar1 == 4) {
        uVar4 = 0;
        *(undefined4 *)(param_1 + -0xdc) = 0;
        local_38 = "PANEL=0";
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + -0xdc);
      }
      _printk("[EGISFP] %s : screen_onoff = %d \n","egisfp_fb_callback",uVar4);
      local_30 = 0;
      kobject_uevent_env(*(long *)(param_1 + -0x240) + 0x10,2,&local_38);
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
LAB_00102f60:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001035e8 size=120
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined4 init_module(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  _printk("[EGISFP] %s : module init \n","egisfp_init");
  iVar2 = __platform_driver_register(&egisfp_driver,&__this_module);
  pcVar1 = "[EGISFP] %s : module init OK ! \n";
  if (iVar2 != 0) {
    pcVar1 = "\x013[EGISFP] %s : register Egis driver fail \n";
  }
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar3 = 0xffffffea;
  }
  _printk(pcVar1,"egisfp_init");
  return uVar3;
}



//------------------------------------------------------------
// cleanup_module @ 00103664 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  _printk("[EGISFP]module exit \n");
  platform_driver_unregister(&egisfp_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00107000 size=1
// signature: undefined _printk(void)
// callers: [fp_eint_func, egis_get_io_stus, egisfp_open, do_egisfp_reset, egisfp_remove, send_navi_event, cleanup_module, egisfp_platformfree, egisfp_interrupt_timer_call, egisfp_ioctl, egisfp_platforminit, egisfp_interrupt_init, egisfp_probe, egisfp_set_screen_onoff, do_egisfp_power_onoff, do_egisfp_reset_set, egisfp_fb_callback, egisfp_interrupt_free, egisfp_interrupt_abort, egisfp_check_ioctl_permission, init_module, egisfp_release, egisfp_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00107008 size=1
// signature: undefined __wake_up(void)
// callers: [fp_eint_func_ll, egisfp_interrupt_abort, egisfp_interrupt_timer_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00107018 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [fp_eint_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00107020 size=1
// signature: undefined mod_timer(void)
// callers: [fp_eint_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 00107028 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [fp_eint_func, fp_eint_func_ll, egisfp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00107030 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [egisfp_interrupt_init, fp_eint_func_ll, egisfp_interrupt_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00107038 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [egisfp_interrupt_init, fp_eint_func_ll, egisfp_interrupt_free, egisfp_platformfree]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00107040 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [egisfp_interrupt_init, fp_eint_func_ll, egisfp_interrupt_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00107048 size=1
// signature: undefined gpio_to_desc(void)
// callers: [egisfp_interrupt_init, egis_get_io_stus, do_egisfp_reset, do_egisfp_power_onoff, do_egisfp_reset_set, egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 00107050 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [egisfp_interrupt_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00107058 size=1
// signature: undefined request_threaded_irq(void)
// callers: [egisfp_interrupt_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00107060 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [egisfp_interrupt_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00107068 size=1
// signature: undefined enable_irq(void)
// callers: [egisfp_interrupt_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 00107070 size=1
// signature: undefined del_timer_sync(void)
// callers: [egisfp_remove, egisfp_interrupt_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00107078 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [do_egisfp_reset, do_egisfp_power_onoff, do_egisfp_reset_set, egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00107080 size=1
// signature: undefined __const_udelay(void)
// callers: [do_egisfp_reset, do_egisfp_power_onoff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00107088 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [egis_get_io_stus, do_egisfp_reset, do_egisfp_power_onoff, do_egisfp_reset_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00107090 size=1
// signature: undefined regulator_disable(void)
// callers: [do_egisfp_power_onoff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00107098 size=1
// signature: undefined regulator_enable(void)
// callers: [do_egisfp_power_onoff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled @ 001070a0 size=1
// signature: undefined regulator_is_enabled(void)
// callers: [egis_get_io_stus, do_egisfp_power_onoff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_voltage @ 001070a8 size=1
// signature: undefined regulator_get_voltage(void)
// callers: [do_egisfp_power_onoff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001070c0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 001070c8 size=1
// signature: undefined pm_stay_awake(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 001070d0 size=1
// signature: undefined pm_relax(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001070d8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001070e0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [egisfp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001070e8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [egisfp_fb_callback, egisfp_platformfree, egisfp_ioctl, egisfp_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 001070f8 size=1
// signature: undefined gpio_request(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00107100 size=1
// signature: undefined devm_regulator_get(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00107108 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 00107110 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 00107118 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00107120 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00107128 size=1
// signature: undefined regulator_set_load(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00107130 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00107138 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 00107140 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [egisfp_platformfree, egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 00107148 size=1
// signature: undefined gpio_free(void)
// callers: [egisfp_platformfree, egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_put @ 00107150 size=1
// signature: undefined devm_regulator_put(void)
// callers: [egisfp_platformfree, egisfp_platforminit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00107158 size=1
// signature: undefined free_irq(void)
// callers: [egisfp_remove, egisfp_platformfree]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 00107160 size=1
// signature: undefined input_event(void)
// callers: [send_navi_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00107168 size=1
// signature: undefined mutex_lock(void)
// callers: [egisfp_open, egisfp_probe, egisfp_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nonseekable_open @ 00107170 size=1
// signature: undefined nonseekable_open(void)
// callers: [egisfp_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00107178 size=1
// signature: undefined mutex_unlock(void)
// callers: [egisfp_open, egisfp_probe, egisfp_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00107180 size=1
// signature: undefined of_find_property(void)
// callers: [egisfp_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00107188 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [egisfp_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00107190 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [egisfp_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00107198 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001071a0 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [egisfp_probe, egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 001071a8 size=1
// signature: undefined input_unregister_device(void)
// callers: [egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 001071b0 size=1
// signature: undefined device_destroy(void)
// callers: [egisfp_probe, egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001071b8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001071c0 size=1
// signature: undefined class_destroy(void)
// callers: [egisfp_probe, egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 001071c8 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [egisfp_probe, egisfp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_chrdev @ 001071d0 size=1
// signature: undefined __register_chrdev(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001071d8 size=1
// signature: undefined __class_create(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001071e8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 001071f0 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001071f8 size=1
// signature: undefined __mutex_init(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00107200 size=1
// signature: undefined device_create(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00107208 size=1
// signature: undefined __list_add_valid(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_allocate_device @ 00107210 size=1
// signature: undefined input_allocate_device(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00107218 size=1
// signature: undefined kfree(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_capability @ 00107220 size=1
// signature: undefined input_set_capability(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 00107228 size=1
// signature: undefined input_register_device(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00107230 size=1
// signature: undefined init_timer_key(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_free_device @ 00107238 size=1
// signature: undefined input_free_device(void)
// callers: [egisfp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_free_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107240 size=1
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
// platform_driver_unregister @ 00107248 size=1
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
// kobject_uevent_env @ 00107250 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [egisfp_fb_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



