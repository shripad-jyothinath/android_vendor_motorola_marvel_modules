// Decompiled by Ghidra 12.2
// Program: pinctrl-msm.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_pinctrl_suspend @ 00100f44 size=36
// signature: undefined msm_pinctrl_suspend(void)
// callers: []
//------------------------------------------------------------

void msm_pinctrl_suspend(long param_1)

{
  pinctrl_force_sleep(*(undefined8 *)(*(long *)(param_1 + 0x98) + 8));
  return;
}



//------------------------------------------------------------
// msm_pinctrl_resume @ 00100f6c size=36
// signature: undefined msm_pinctrl_resume(void)
// callers: []
//------------------------------------------------------------

void msm_pinctrl_resume(long param_1)

{
  pinctrl_force_default(*(undefined8 *)(*(long *)(param_1 + 0x98) + 8));
  return;
}



//------------------------------------------------------------
// debug_pintctrl_msm_enable @ 00100f94 size=16
// signature: undefined debug_pintctrl_msm_enable(void)
// callers: []
//------------------------------------------------------------

void debug_pintctrl_msm_enable(void)

{
  pinctrl_msm_log_mask = 1;
  return;
}



//------------------------------------------------------------
// debug_pintctrl_msm_disable @ 00100fa8 size=12
// signature: undefined debug_pintctrl_msm_disable(void)
// callers: []
//------------------------------------------------------------

void debug_pintctrl_msm_disable(void)

{
  pinctrl_msm_log_mask = 0;
  return;
}



//------------------------------------------------------------
// noirq_msm_pinctrl_suspend @ 00100fb8 size=464
// signature: undefined noirq_msm_pinctrl_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 noirq_msm_pinctrl_suspend(long param_1)

{
  ulong uVar1;
  undefined8 *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  code *pcVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  undefined1 auStack_80 [4];
  int local_7c;
  undefined8 local_78;
  int local_70;
  undefined4 local_6c;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  if (pinctrl_msm_log_mask == '\x01') {
    lVar11 = *(long *)(param_1 + 0x98);
    puVar9 = (undefined8 *)(lVar11 + 0x10);
    _printk_deferred(&DAT_00106083,*puVar9);
    if (*(short *)(lVar11 + 0xbc) != 0) {
      lVar12 = 0;
      uVar10 = 0;
      do {
        lVar7 = gpiochip_get_data(puVar9);
        local_6c = 0;
        local_70 = 0;
        local_78 = 0;
        local_7c = 0;
        uVar8 = gpiochip_line_is_valid(puVar9,uVar10 & 0xffffffff);
        if ((uVar8 & 1) != 0) {
          puVar2 = (undefined8 *)(*(long *)(*(long *)(lVar7 + 0x3e0) + 0x20) + lVar12);
          msm_gpio_pin_status_get
                    (lVar7,puVar2,&local_70,&local_6c,(long)&local_78 + 4,&local_78,auStack_80,
                     &local_7c);
          puVar3 = &DAT_00105e88;
          if (local_70 != 0) {
            puVar3 = &DAT_00105de8;
          }
          puVar4 = &DAT_00106087;
          if (local_7c != 0) {
            puVar4 = &DAT_001060c5;
          }
          if (*(char *)(*(long *)(lVar7 + 0x3e0) + 0x30) == '\0') {
            if (3 < (uint)local_78) {
LAB_00101184:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x101188);
              (*pcVar6)();
            }
            ppuVar5 = &pulls_keeper;
            uVar8 = 0x20;
          }
          else {
            if (2 < (uint)local_78) goto LAB_00101184;
            ppuVar5 = &pulls_no_keeper;
            uVar8 = 0x18;
          }
          uVar1 = (local_78 & 0xffffffff) * 8;
          if ((uVar8 <= uVar1) || (uVar8 <= uVar1)) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(1,0x101180);
            (*pcVar6)();
          }
          _printk_deferred("%s: %s, %s, func%d, %dmA, %s\n",*puVar2,puVar3,puVar4,local_6c,
                           local_78._4_4_ * 2 + 2,ppuVar5[local_78 & 0xffffffff]);
        }
        uVar10 = uVar10 + 1;
        lVar12 = lVar12 + 0x58;
      } while (uVar10 < *(ushort *)(lVar11 + 0xbc));
    }
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_gpio_mpm_wake_set @ 0010118c size=408
// signature: undefined msm_gpio_mpm_wake_set(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_mpm_wake_set(ulong param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  uint uVar4;
  uint *puVar5;
  long lVar6;
  long lVar7;
  ulong *puVar8;
  ulong uVar9;
  
  uVar9 = param_1 & 0xffffffff;
  lVar6 = *(long *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x20);
  puVar5 = (uint *)(lVar6 + (param_1 & 0xffffffff) * 0x58 + 0x50);
  if ((*puVar5 == 0xffffffff) && ((*(uint *)(lVar6 + uVar9 * 0x58 + 0x44) & 0xf8000) == 0)) {
    uVar3 = 0xfffffffe;
  }
  else {
    uVar3 = _raw_spin_lock_irqsave(msm_pinctrl_data + 0x314);
    lVar7 = lVar6 + uVar9 * 0x58;
    puVar8 = (ulong *)(lVar7 + 0x3c);
    uVar1 = readl(*(long *)(msm_pinctrl_data + (*puVar8 >> 5 & 3) * 8 + 1000) +
                  (ulong)*(uint *)(lVar7 + 0x2c));
    if (((uVar1 >> ((ulong)(*(uint *)(lVar7 + 0x44) >> 0xf) & 0x1f) & 1) == 0) ||
       ((*(ulong *)(msm_pinctrl_data + (uVar9 >> 3 & 0x1ffffff8) + 0x368) >> (param_1 & 0x3f) & 1)
        == 0)) {
      lVar6 = lVar6 + uVar9 * 0x58;
      uVar2 = readl_relaxed(*(long *)(msm_pinctrl_data + (*puVar8 >> 5 & 3) * 8 + 1000) +
                            (ulong)*(uint *)(lVar6 + 0x4c));
      uVar4 = (uint)(1L << ((ulong)*puVar5 & 0x3f));
      uVar1 = uVar2 | uVar4;
      if ((param_2 & 1) == 0) {
        uVar1 = uVar2 & (uVar4 ^ 0xffffffff);
      }
      writel_relaxed(uVar1,*(long *)(msm_pinctrl_data + (*puVar8 >> 5 & 3) * 8 + 1000) +
                           (ulong)*(uint *)(lVar6 + 0x4c));
    }
    else {
      uVar4 = 1 << (ulong)(*(uint *)(lVar7 + 0x44) >> 10 & 0x1f);
      uVar2 = uVar4 | uVar1;
      if ((param_2 & 1) == 0) {
        uVar2 = uVar1 & (uVar4 ^ 0xffffffff);
      }
      writel(uVar2,*(long *)(msm_pinctrl_data + (*puVar8 >> 5 & 3) * 8 + 1000) +
                   (ulong)*(uint *)(lVar7 + 0x2c));
    }
    _raw_spin_unlock_irqrestore(msm_pinctrl_data + 0x314,uVar3);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// readl_relaxed @ 00101324 size=124
// signature: undefined readl_relaxed(void)
// callers: [msm_gpio_mpm_wake_set, msm_gpio_irq_set_type, msm_pinctrl_hibernation_suspend, msm_spare_read, msm_qup_read]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x10136c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 001013a0 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_gpio_mpm_wake_set, msm_qup_write, msm_spare_write, msm_gpio_irq_set_type, msm_pinctrl_probe, msm_pinctrl_hibernation_resume]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1013b8,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1013f4,uVar1);
  return;
}



//------------------------------------------------------------
// msm_gpio_get_pin_address @ 00101428 size=276
// signature: undefined msm_gpio_get_pin_address(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_get_pin_address(int param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  if (msm_pinctrl_data == (long *)0x0) {
    _printk(&DAT_00105f04);
    uVar4 = 0;
  }
  else {
    lVar8 = *msm_pinctrl_data;
    uVar2 = param_1 - (int)msm_pinctrl_data[0x17];
    uVar3 = gpiochip_line_is_valid(msm_pinctrl_data + 2,uVar2);
    uVar4 = 0;
    if ((param_2 != (long *)0x0) && ((uVar3 & 1) != 0)) {
      lVar5 = lVar8 + -0x10;
      lVar7 = *(long *)(msm_pinctrl_data[0x7c] + 0x38);
      lVar9 = *(long *)(msm_pinctrl_data[0x7c] + 0x20);
      if (lVar7 == 0) {
        plVar6 = (long *)platform_get_resource(lVar5,0x200,0);
      }
      else {
        plVar6 = (long *)platform_get_resource_byname
                                   (lVar5,0x200,
                                    *(undefined8 *)
                                     (lVar7 + (*(ulong *)(lVar9 + (ulong)uVar2 * 0x58 + 0x3c) >> 5 &
                                              3) * 8));
      }
      if (plVar6 == (long *)0x0) {
        _dev_err(lVar8,"failed to get resource\n");
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
        lVar9 = lVar9 + (ulong)uVar2 * 0x58;
        lVar8 = *plVar6 + (ulong)*(uint *)(lVar9 + 0x24);
        *param_2 = lVar8;
        uVar2 = *(uint *)(lVar9 + 0x3c) & 0x1f;
        uVar1 = 0x1000;
        if (uVar2 != 0) {
          uVar1 = uVar2 << 0xc;
        }
        param_2[1] = lVar8 + (ulong)uVar1 + -1;
      }
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// msm_qup_write @ 00101540 size=112
// signature: undefined msm_qup_write(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_qup_write(uint param_1,uint param_2)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  
  uVar1 = *(uint *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x68);
  uVar2 = (ulong)uVar1;
  if (0 < (int)uVar1) {
    puVar3 = (uint *)(*(long *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x60) + 4);
    do {
      if (puVar3[-1] == param_1) {
        writel_relaxed(param_2 & 0x3f,*(long *)(msm_pinctrl_data + 1000) + (ulong)*puVar3);
        return 0;
      }
      puVar3 = puVar3 + 2;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// msm_qup_read @ 001015b4 size=108
// signature: undefined msm_qup_read(void)
// callers: []
//------------------------------------------------------------

uint msm_qup_read(uint param_1)

{
  uint uVar1;
  ulong uVar2;
  uint *puVar3;
  
  uVar1 = *(uint *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x68);
  uVar2 = (ulong)uVar1;
  if (0 < (int)uVar1) {
    puVar3 = (uint *)(*(long *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x60) + 4);
    do {
      if (puVar3[-1] == param_1) {
        uVar1 = readl_relaxed(*(long *)(msm_pinctrl_data + 1000) + (ulong)*puVar3);
        return uVar1 & 0x3f;
      }
      puVar3 = puVar3 + 2;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// msm_spare_write @ 00101624 size=96
// signature: undefined msm_spare_write(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_spare_write(int param_1,uint param_2)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x80);
  if (((lVar3 == 0) || (*(int *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x88) <= param_1)) ||
     (uVar1 = *(uint *)(lVar3 + (long)param_1 * 8 + 4), uVar1 == 0)) {
    uVar2 = 0xfffffffe;
  }
  else {
    writel_relaxed(param_2 & 0xff00,*(long *)(msm_pinctrl_data + 1000) + (ulong)uVar1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_spare_read @ 00101688 size=92
// signature: undefined msm_spare_read(void)
// callers: []
//------------------------------------------------------------

uint msm_spare_read(int param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x80);
  if (((lVar2 == 0) || (*(int *)(*(long *)(msm_pinctrl_data + 0x3e0) + 0x88) <= param_1)) ||
     (uVar1 = *(uint *)(lVar2 + (long)param_1 * 8 + 4), uVar1 == 0)) {
    uVar1 = 0xfffffffe;
  }
  else {
    uVar1 = readl_relaxed(*(long *)(msm_pinctrl_data + 1000) + (ulong)uVar1);
    uVar1 = uVar1 & 0xff00;
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_pinctrl_probe @ 001016e8 size=2084
// signature: undefined msm_pinctrl_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong msm_pinctrl_probe(long param_1,long param_2)

{
  long *__dest;
  long lVar1;
  ulong *puVar2;
  int *piVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  long *plVar12;
  undefined8 uVar13;
  ulong uVar14;
  undefined4 *puVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  undefined8 *puVar19;
  long *plVar20;
  ulong uVar21;
  long lVar22;
  long lVar23;
  long lVar24;
  long local_b8 [11];
  
  lVar23 = sp_el0;
  plVar20 = (long *)(param_1 + 0x10);
  local_b8[10] = *(long *)(lVar23 + 0x638);
  plVar12 = (long *)devm_kmalloc(plVar20,0x430,0xdc0);
  msm_pinctrl_data = plVar12;
  if (plVar12 == (long *)0x0) {
LAB_00101c7c:
    uVar14 = 0xfffffff4;
  }
  else {
    *(undefined1 *)(plVar12 + 0x85) = 0;
    __dest = plVar12 + 2;
    *plVar12 = (long)plVar20;
    plVar12[0x7c] = param_2;
    memcpy(__dest,msm_gpio_template,0x288);
    iVar7 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,ipq8064-pinctrl");
    puVar19 = *(undefined8 **)(param_2 + 0x38);
    *(undefined4 *)((long)plVar12 + 0x314) = 0;
    *(bool *)(plVar12 + 0x62) = iVar7 != 0;
    if (puVar19 == (undefined8 *)0x0) {
      puVar19 = (undefined8 *)platform_get_resource(param_1,0x200,0);
      if (puVar19 == (undefined8 *)0x0) {
        uVar14 = 0xfffffffe;
        goto LAB_00101e54;
      }
      uVar14 = devm_ioremap_resource(plVar20,puVar19);
      plVar12[0x7d] = uVar14;
      if (0xfffffffffffff000 < uVar14) {
        uVar14 = uVar14 & 0xffffffff;
        goto LAB_00101e54;
      }
      *(int *)(plVar12 + 0x81) = (int)*puVar19;
    }
    else if (*(int *)(param_2 + 0x40) != 0) {
      uVar13 = platform_get_resource_byname(param_1,0x200,*puVar19);
      uVar14 = devm_ioremap_resource(plVar20,uVar13);
      plVar12[0x7d] = uVar14;
      if (0xfffffffffffff000 < uVar14) goto LAB_00101e54;
      if (1 < *(uint *)(param_2 + 0x40)) {
        uVar13 = platform_get_resource_byname
                           (param_1,0x200,*(undefined8 *)(*(long *)(param_2 + 0x38) + 8));
        uVar14 = devm_ioremap_resource(plVar20,uVar13);
        plVar12[0x7e] = uVar14;
        if (0xfffffffffffff000 < uVar14) goto LAB_00101e54;
        if (2 < *(uint *)(param_2 + 0x40)) {
          uVar13 = platform_get_resource_byname
                             (param_1,0x200,*(undefined8 *)(*(long *)(param_2 + 0x38) + 0x10));
          uVar14 = devm_ioremap_resource(plVar20,uVar13);
          plVar12[0x7f] = uVar14;
          if (0xfffffffffffff000 < uVar14) goto LAB_00101e54;
          if (3 < *(uint *)(param_2 + 0x40)) {
            uVar13 = platform_get_resource_byname
                               (param_1,0x200,*(undefined8 *)(*(long *)(param_2 + 0x38) + 0x18));
            uVar14 = devm_ioremap_resource(plVar20,uVar13);
            plVar12[0x80] = uVar14;
            if (0xfffffffffffff000 < uVar14) goto LAB_00101e54;
            if (4 < *(uint *)(param_2 + 0x40)) {
              uVar13 = platform_get_resource_byname
                                 (param_1,0x200,*(undefined8 *)(*(long *)(param_2 + 0x38) + 0x20));
              devm_ioremap_resource(plVar20,uVar13);
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1018a8);
              (*pcVar6)();
            }
          }
        }
      }
    }
    iVar7 = *(int *)(plVar12[0x7c] + 0x18);
    if (iVar7 != 0) {
      lVar23 = *(long *)(plVar12[0x7c] + 0x10);
      iVar10 = 0;
      do {
        iVar8 = strcmp(*(char **)(lVar23 + (long)iVar10 * 0x18),"ps_hold");
        if (iVar8 == 0) {
          *(undefined4 *)(plVar12 + 0x60) = 0x80;
          plVar12[0x5e] = (long)msm_ps_hold_restart;
          iVar7 = register_restart_handler(plVar12 + 0x5e);
          if (iVar7 != 0) {
            _dev_err(*plVar12,"failed to setup restart handler.\n");
          }
          _pm_power_off = msm_ps_hold_poweroff;
          poweroff_pctrl = plVar12;
          break;
        }
        iVar10 = iVar10 + 1;
      } while (iVar7 != iVar10);
    }
    uVar14 = platform_get_irq(param_1,0);
    *(int *)(plVar12 + 0x61) = (int)uVar14;
    if (-1 < (int)uVar14) {
      plVar12[0x56] = (long)&msm_pinctrl_ops;
      lVar23 = *(long *)(param_1 + 0x80);
      plVar12[0x57] = (long)&msm_pinmux_ops;
      plVar12[0x59] = (long)&__this_module;
      plVar12[0x58] = (long)msm_pinconf_ops;
      if (lVar23 == 0) {
        lVar23 = *plVar20;
      }
      plVar12[0x53] = lVar23;
      plVar12[0x54] = *(long *)plVar12[0x7c];
      lVar23 = ((long *)plVar12[0x7c])[1];
      *(undefined4 *)(plVar12 + 0x5a) = 3;
      *(int *)(plVar12 + 0x55) = (int)lVar23;
      plVar12[0x5b] = (long)&msm_gpio_bindings;
      uVar14 = devm_pinctrl_register(plVar20,plVar12 + 0x53,plVar12);
      plVar12[1] = uVar14;
      if (0xfffffffffffff000 < uVar14) {
        _dev_err(plVar20,"Couldn\'t register pinctrl driver\n");
        uVar14 = (ulong)*(uint *)(plVar12 + 1);
        goto LAB_00101e54;
      }
      uVar9 = *(uint *)(plVar12[0x7c] + 0x2c);
      if (300 < uVar9) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x101f10);
        (*pcVar6)();
      }
      plVar20 = (long *)*plVar12;
      *(short *)((long)plVar12 + 0xbc) = (short)uVar9;
      *(undefined4 *)(plVar12 + 0x17) = 0xffffffff;
      lVar23 = plVar20[0xe];
      if (lVar23 == 0) {
        lVar23 = *plVar20;
      }
      plVar12[2] = lVar23;
      plVar12[4] = (long)plVar20;
      plVar12[6] = (long)&__this_module;
      if (*(long *)(plVar12[0x7c] + 0x48) == 0) {
        iVar7 = of_property_count_elems_of_size(plVar20[0x5d],"qcom,gpios-reserved",4);
        iVar10 = device_property_read_u16_array(*plVar12,"gpios",0,0);
        if ((0 < iVar7) && (0 < iVar10)) {
          _dev_warn(*plVar12,
                    "qcom,gpios-reserved and gpios are both defined. Only one should be used.\n");
          goto LAB_00101a44;
        }
        if ((0 < iVar7) || (0 < iVar10)) goto LAB_00101a44;
      }
      else {
LAB_00101a44:
        plVar12[0x13] = (long)msm_gpio_init_valid_mask;
      }
      local_b8[8] = 0;
      local_b8[9] = 0;
      local_b8[6] = 0;
      local_b8[7] = 0;
      local_b8[4] = 0;
      local_b8[5] = 0;
      local_b8[2] = 0;
      local_b8[3] = 0;
      local_b8[0] = 0;
      local_b8[1] = 0;
      iVar7 = __of_parse_phandle_with_args
                        (*(undefined8 *)(*plVar12 + 0x2e8),"wakeup-parent",0,0,0,local_b8);
      if ((iVar7 == 0) && (local_b8[0] != 0)) {
        local_b8[0] = local_b8[0] + 0x18;
        local_b8[8] = 0;
        local_b8[9] = 0;
        local_b8[6] = 0;
        local_b8[7] = 0;
        local_b8[4] = 0;
        local_b8[5] = 0;
        local_b8[2] = 0;
        local_b8[3] = 0;
        local_b8[1] = 0;
        lVar23 = irq_find_matching_fwspec(local_b8,9);
        plVar12[0x2a] = lVar23;
        if (lVar23 == 0) {
          uVar14 = 0xfffffdfb;
          goto LAB_00101e54;
        }
        plVar12[0x2b] = (long)msm_gpio_wakeirq;
        if (((*(byte *)(lVar23 + 0x2a) & 1) != 0) &&
           (lVar23 = plVar12[0x7c], *(int *)(lVar23 + 0x58) != 0)) {
          uVar14 = 0;
          do {
            uVar9 = *(uint *)(*(long *)(lVar23 + 0x50) +
                             (-(uVar14 >> 0x1f) & 0xfffffff800000000 | uVar14 << 3));
            puVar2 = (ulong *)(plVar12 + (ulong)(uVar9 >> 6) + 0x6d);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar5) {
                *puVar2 = *puVar2 | 1L << ((ulong)uVar9 & 0x3f);
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            lVar23 = plVar12[0x7c];
            uVar9 = (int)uVar14 + 1;
            uVar14 = (ulong)uVar9;
          } while (uVar9 < *(uint *)(lVar23 + 0x58));
        }
      }
      plVar12[0x26] = (long)&msm_gpio_irq_chip;
      plVar12[0x3c] = (long)msm_gpio_irq_handler;
      lVar23 = *(long *)(*plVar12 + 0x2f0);
      *(undefined4 *)(plVar12 + 0x3e) = 1;
      plVar12[0x29] = lVar23;
      puVar15 = (undefined4 *)devm_kmalloc(*plVar12,4,0xdc0);
      plVar12[0x3f] = (long)puVar15;
      if (puVar15 == (undefined4 *)0x0) goto LAB_00101c7c;
      plVar12[0x38] = (long)handle_bad_irq;
      *puVar15 = (int)plVar12[0x61];
      *(undefined4 *)(plVar12 + 0x39) = 0;
      plVar12[0x43] = (long)msm_gpio_irq_init_valid_mask;
      uVar16 = gpiochip_add_data_with_key(__dest,plVar12,0,0);
      uVar14 = uVar16 & 0xffffffff;
      if ((int)uVar16 != 0) {
        _dev_err(*plVar12,"Failed register gpiochip\n");
        goto LAB_00101e54;
      }
      lVar23 = of_find_property(*(undefined8 *)(*plVar12 + 0x2e8),"gpio-ranges",0);
      if (lVar23 == 0) {
        lVar23 = ((long *)*plVar12)[0xe];
        if (lVar23 == 0) {
          lVar23 = *(long *)*plVar12;
        }
        uVar9 = gpiochip_add_pin_range(__dest,lVar23,0,0,*(undefined2 *)((long)plVar12 + 0xbc));
        if (uVar9 != 0) {
          uVar14 = (ulong)uVar9;
          _dev_err(*plVar12,"Failed to add pin range\n");
          gpiochip_remove(__dest);
          goto LAB_00101e54;
        }
      }
      uVar9 = platform_irq_count(param_1);
      if ((int)uVar9 < 2) {
        uVar11 = *(uint *)((long)plVar12 + 0x30c);
      }
      else {
        uVar14 = 1;
        lVar23 = 0xc;
        do {
          lVar24 = *(long *)(param_2 + 0x90);
          uVar16 = platform_get_irq(param_1,uVar14 & 0xffffffff);
          *(int *)(lVar24 + lVar23) = (int)uVar16;
          __irq_set_handler(uVar16,msm_gpio_dirconn_handler,0,0);
          irq_set_irq_type(uVar16 & 0xffffffff,1);
          uVar14 = uVar14 + 1;
          lVar23 = lVar23 + 8;
          uVar11 = *(int *)((long)plVar12 + 0x30c) + 1;
          *(uint *)((long)plVar12 + 0x30c) = uVar11;
        } while (uVar9 != uVar14);
      }
      uVar14 = (ulong)uVar11;
      if (uVar11 != 0) {
        uVar9 = 0;
        lVar24 = plVar12[0x27];
        lVar23 = uVar14 << 3;
        do {
          uVar14 = uVar14 - 1;
          piVar3 = (int *)(*(long *)(plVar12[0x7c] + 0x90) + lVar23);
          iVar7 = *piVar3;
          if (iVar7 != -1) {
            iVar10 = piVar3[1];
            uVar16 = irq_create_mapping_affinity(lVar24,(long)iVar7,0);
            uVar21 = uVar16 & 0xffffffff;
            irq_set_parent(uVar16,iVar10);
            irq_set_chip_data(uVar21,__dest);
            irq_set_chip_and_handler_name(uVar21,&msm_gpio_irq_chip,0,0);
            lVar17 = irq_get_irq_data(uVar21);
            if (lVar17 != 0) {
              irq_set_handler_data(iVar10,lVar17);
              lVar18 = gpiochip_get_data(*(undefined8 *)(lVar17 + 0x30));
              uVar13 = _raw_spin_lock_irqsave(lVar18 + 0x314);
              lVar1 = lVar18 + 1000;
              lVar22 = *(long *)(*(long *)(lVar18 + 0x3e0) + 0x20) + *(long *)(lVar17 + 8) * 0x58;
              writel_relaxed((uint)*(long *)(lVar17 + 8) & 0xff,
                             *(long *)(lVar1 + (*(ulong *)(lVar22 + 0x3c) >> 5 & 3) * 8) +
                             (ulong)*(uint *)(lVar22 + 0x38) + (ulong)uVar9);
              uVar11 = readl(*(long *)(lVar1 + (*(ulong *)(lVar22 + 0x3c) >> 5 & 3) * 8) +
                             (ulong)*(uint *)(lVar22 + 0x2c));
              writel(uVar11 | (uint)(1L << ((ulong)(*(uint *)(lVar22 + 0x48) >> 0xf) & 0x3f)),
                     *(long *)(lVar1 + (*(ulong *)(lVar22 + 0x3c) >> 5 & 3) * 8) +
                     (ulong)*(uint *)(lVar22 + 0x2c));
              _raw_spin_unlock_irqrestore(lVar18 + 0x314,uVar13);
            }
          }
          uVar9 = uVar9 + 4;
          lVar23 = lVar23 + -8;
        } while ((int)uVar14 != 0);
      }
      *(long **)(param_1 + 0xa8) = plVar12;
      pinctrl_msm_log_mask = 0;
      register_syscore_ops(&msm_pinctrl_pm_ops);
      uVar14 = register_pm_notifier(&pinctrl_notif_block);
    }
    uVar14 = uVar14 & 0xffffffff;
  }
LAB_00101e54:
  lVar23 = sp_el0;
  if (*(long *)(lVar23 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14 & 0xffffffff;
}



//------------------------------------------------------------
// msm_gpio_dirconn_handler @ 00101f1c size=228
// signature: undefined msm_gpio_dirconn_handler(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_dirconn_handler(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 8);
  if (lVar3 == 0) {
    return;
  }
  lVar2 = *(long *)(param_1 + 0x48);
  if (*(long *)(lVar2 + 0x48) == 0) {
    pcVar1 = *(code **)(lVar2 + 0x38);
    if (pcVar1 == (code *)0x0) {
      if (*(int *)(*(code **)(lVar2 + 0x30) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101f7c);
        (*pcVar1)();
      }
      (**(code **)(lVar2 + 0x30))(param_1 + 0x30);
      pcVar1 = *(code **)(lVar2 + 0x28);
      if (pcVar1 == (code *)0x0) goto LAB_00101fa8;
    }
    if (*(int *)(pcVar1 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101fa4);
      (*pcVar1)();
    }
    (*pcVar1)(param_1 + 0x30);
  }
LAB_00101fa8:
  generic_handle_irq(*(undefined4 *)(lVar3 + 4));
  pcVar1 = *(code **)(lVar2 + 0x48);
  if (pcVar1 == (code *)0x0) {
    pcVar1 = *(code **)(lVar2 + 0x40);
  }
  if (*(int *)(pcVar1 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101fd8);
    (*pcVar1)();
  }
  (*pcVar1)(param_1 + 0x30);
  irq_set_irqchip_state(*(undefined4 *)(param_1 + 0x34),1,0);
  return;
}



//------------------------------------------------------------
// msm_pinctrl_remove @ 00102004 size=56
// signature: undefined msm_pinctrl_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pinctrl_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  gpiochip_remove(lVar1 + 0x10);
  unregister_restart_handler(lVar1 + 0x2f0);
  return 0;
}



//------------------------------------------------------------
// msm_gpio_pin_status_get @ 0010203c size=336
// signature: undefined msm_gpio_pin_status_get(void)
// callers: [noirq_msm_pinctrl_suspend, msm_gpio_dbg_show]
//------------------------------------------------------------

void msm_gpio_pin_status_get
               (long param_1,long param_2,uint *param_3,uint *param_4,uint *param_5,uint *param_6,
               uint *param_7,uint *param_8)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar2 = readl(*(long *)(param_1 + 1000 + (*(ulong *)(param_2 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(param_2 + 0x24));
  uVar3 = readl(*(long *)(param_1 + 1000 + (*(ulong *)(param_2 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(param_2 + 0x28));
  *param_3 = uVar2 >> (*(ulong *)(param_2 + 0x3c) >> 0x25 & 0x1f) & 1;
  *param_4 = uVar2 >> (ulong)(*(uint *)(param_2 + 0x3c) >> 7 & 0x1f) & 7;
  *param_5 = uVar2 >> (ulong)(*(uint *)(param_2 + 0x3c) >> 0x11 & 0x1f) & 7;
  *param_6 = uVar2 >> (ulong)(*(uint *)(param_2 + 0x3c) >> 0xc & 0x1f) & 3;
  *param_7 = 0;
  if ((*(int *)(*(long *)(param_1 + 0x3e0) + 0x70) != 0) &&
     ((uVar2 >> (*(ulong *)(param_2 + 0x3c) >> 0x20 & 0x1f) & 1) != 0)) {
    *param_7 = (uint)((uVar2 >> (*(ulong *)(param_2 + 0x3c) >> 0x1b & 0x1f) & 1) == 0);
  }
  lVar1 = 0x2a;
  if (*param_3 != 0) {
    lVar1 = 0x2f;
  }
  *param_8 = (uint)((uVar3 & 0xffffffff) >> (*(ulong *)(param_2 + 0x3c) >> lVar1 & 0x1f)) & 1;
  return;
}



//------------------------------------------------------------
// readl @ 0010218c size=140
// signature: undefined readl(void)
// callers: [msm_gpio_get, msm_gpio_irq_reqres, msm_gpio_irq_unmask, msm_gpio_irq_set_type, msm_gpio_update_dual_edge_pos, msm_pinctrl_probe, msm_gpio_direction_input, msm_gpio_irq_handler, msm_gpio_irq_get_irqchip_state, msm_gpio_set, msm_gpio_mpm_wake_set, msm_pinmux_set_mux, msm_config_group_get, msm_gpio_wakeirq, msm_pinctrl_hibernation_suspend, msm_gpio_update_dual_edge_parent, msm_gpio_direction_output, msm_gpio_get_direction, msm_gpio_irq_mask, msm_config_group_set, msm_gpio_pin_status_get]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1021e4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00102218 size=136
// signature: undefined writel(void)
// callers: [msm_gpio_irq_ack, msm_gpio_irq_reqres, msm_gpio_irq_unmask, msm_gpio_irq_set_type, msm_gpio_update_dual_edge_pos, msm_pinctrl_probe, msm_gpio_direction_input, msm_gpio_set, msm_ps_hold_poweroff, msm_pinctrl_hibernation_resume, msm_gpio_mpm_wake_set, msm_pinmux_set_mux, msm_gpio_wakeirq, msm_ps_hold_restart, msm_gpio_irq_set_irqchip_state, msm_gpio_direction_output, msm_gpio_irq_mask, msm_config_group_set]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102230,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102270,uVar1);
  return;
}



//------------------------------------------------------------
// msm_gpio_get_direction @ 001022a4 size=108
// signature: undefined msm_gpio_get_direction(void)
// callers: []
//------------------------------------------------------------

bool msm_gpio_get_direction(undefined8 param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = gpiochip_get_data();
  lVar3 = *(long *)(*(long *)(lVar1 + 0x3e0) + 0x20) + (ulong)param_2 * 0x58;
  uVar2 = readl(*(long *)(lVar1 + (*(ulong *)(lVar3 + 0x3c) >> 5 & 3) * 8 + 1000) +
                (ulong)*(uint *)(lVar3 + 0x24));
  return ((uVar2 & 0xffffffff) >> (*(ulong *)(lVar3 + 0x3c) >> 0x25 & 0x1f) & 1) == 0;
}



//------------------------------------------------------------
// msm_gpio_direction_input @ 00102314 size=176
// signature: undefined msm_gpio_direction_input(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_direction_input(undefined8 param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar2 = gpiochip_get_data();
  lVar4 = *(long *)(*(long *)(lVar2 + 0x3e0) + 0x20);
  uVar3 = _raw_spin_lock_irqsave(lVar2 + 0x314);
  lVar4 = lVar4 + (param_2 & 0xffffffff) * 0x58;
  uVar1 = readl(*(long *)(lVar2 + 1000 + (*(ulong *)(lVar4 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(lVar4 + 0x24));
  writel(uVar1 & (1 << (ulong)((uint)(*(ulong *)(lVar4 + 0x3c) >> 0x25) & 0x1f) ^ 0xffffffffU),
         *(long *)(lVar2 + 1000 + (*(ulong *)(lVar4 + 0x3c) >> 5 & 3) * 8) +
         (ulong)*(uint *)(lVar4 + 0x24));
  _raw_spin_unlock_irqrestore(lVar2 + 0x314,uVar3);
  return 0;
}



//------------------------------------------------------------
// msm_gpio_direction_output @ 001023c8 size=252
// signature: undefined msm_gpio_direction_output(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_direction_output(undefined8 param_1,ulong param_2,int param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  
  lVar5 = gpiochip_get_data();
  lVar7 = *(long *)(*(long *)(lVar5 + 0x3e0) + 0x20);
  uVar6 = _raw_spin_lock_irqsave(lVar5 + 0x314);
  lVar1 = lVar5 + 1000;
  lVar7 = lVar7 + (param_2 & 0xffffffff) * 0x58;
  uVar3 = readl(*(long *)(lVar1 + (*(ulong *)(lVar7 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(lVar7 + 0x28));
  uVar2 = 1 << (ulong)((uint)(*(ulong *)(lVar7 + 0x3c) >> 0x2f) & 0x1f);
  uVar4 = uVar3 & (uVar2 ^ 0xffffffff);
  if (param_3 != 0) {
    uVar4 = uVar3 | uVar2;
  }
  writel(uVar4,*(long *)(lVar1 + (*(ulong *)(lVar7 + 0x3c) >> 5 & 3) * 8) +
               (ulong)*(uint *)(lVar7 + 0x28));
  uVar4 = readl(*(long *)(lVar1 + (*(ulong *)(lVar7 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(lVar7 + 0x24));
  writel(uVar4 | 1 << (ulong)((uint)(*(ulong *)(lVar7 + 0x3c) >> 0x25) & 0x1f),
         *(long *)(lVar1 + (*(ulong *)(lVar7 + 0x3c) >> 5 & 3) * 8) + (ulong)*(uint *)(lVar7 + 0x24)
        );
  _raw_spin_unlock_irqrestore(lVar5 + 0x314,uVar6);
  return 0;
}



//------------------------------------------------------------
// msm_gpio_get @ 001024c8 size=104
// signature: undefined msm_gpio_get(void)
// callers: []
//------------------------------------------------------------

uint msm_gpio_get(undefined8 param_1,uint param_2)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = gpiochip_get_data();
  lVar3 = *(long *)(*(long *)(lVar1 + 0x3e0) + 0x20) + (ulong)param_2 * 0x58;
  uVar2 = readl(*(long *)(lVar1 + (*(ulong *)(lVar3 + 0x3c) >> 5 & 3) * 8 + 1000) +
                (ulong)*(uint *)(lVar3 + 0x28));
  return (uint)((uVar2 & 0xffffffff) >> (*(ulong *)(lVar3 + 0x3c) >> 0x2a & 0x1f)) & 1;
}



//------------------------------------------------------------
// msm_gpio_set @ 00102534 size=188
// signature: undefined msm_gpio_set(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_set(undefined8 param_1,ulong param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar4 = gpiochip_get_data();
  lVar6 = *(long *)(*(long *)(lVar4 + 0x3e0) + 0x20);
  uVar5 = _raw_spin_lock_irqsave(lVar4 + 0x314);
  lVar6 = lVar6 + (param_2 & 0xffffffff) * 0x58;
  uVar3 = readl(*(long *)(lVar4 + 1000 + (*(ulong *)(lVar6 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(lVar6 + 0x28));
  uVar2 = 1 << (ulong)((uint)(*(ulong *)(lVar6 + 0x3c) >> 0x2f) & 0x1f);
  uVar1 = uVar3 & (uVar2 ^ 0xffffffff);
  if (param_3 != 0) {
    uVar1 = uVar3 | uVar2;
  }
  writel(uVar1,*(long *)(lVar4 + 1000 + (*(ulong *)(lVar6 + 0x3c) >> 5 & 3) * 8) +
               (ulong)*(uint *)(lVar6 + 0x28));
  _raw_spin_unlock_irqrestore(lVar4 + 0x314,uVar5);
  return;
}



//------------------------------------------------------------
// msm_gpio_dbg_show @ 001025f4 size=536
// signature: undefined msm_gpio_dbg_show(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_dbg_show(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined **ppuVar3;
  code *pcVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  undefined8 local_80;
  undefined8 local_78;
  int local_70;
  undefined4 local_6c;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  if (*(short *)(param_2 + 0xac) != 0) {
    lVar9 = 0;
    uVar8 = 0;
    do {
      lVar5 = gpiochip_get_data(param_2);
      local_6c = 0;
      local_70 = 0;
      local_80 = 0;
      local_78 = 0;
      uVar6 = gpiochip_line_is_valid(param_2,uVar8 & 0xffffffff);
      if ((uVar6 & 1) != 0) {
        puVar1 = (undefined8 *)(*(long *)(*(long *)(lVar5 + 0x3e0) + 0x20) + lVar9);
        msm_gpio_pin_status_get
                  (lVar5,puVar1,&local_70,&local_6c,(long)&local_78 + 4,&local_78,&local_80,
                   (long)&local_80 + 4);
        uVar7 = *puVar1;
        if ((int)local_80 == 0) {
          puVar2 = &DAT_00105e88;
          if (local_70 != 0) {
            puVar2 = &DAT_00105de8;
          }
          seq_printf(param_1," %-8s: %-3s",uVar7,puVar2);
          puVar2 = &DAT_00106087;
          if (local_80._4_4_ != 0) {
            puVar2 = &DAT_001060c5;
          }
          seq_printf(param_1," %-4s func%d",puVar2,local_6c);
          seq_printf(param_1," %dmA",local_78._4_4_ * 2 + 2);
          uVar6 = local_78 & 0xffffffff;
          if (*(char *)(*(long *)(lVar5 + 0x3e0) + 0x30) == '\0') {
            if (3 < (uint)local_78) goto LAB_00102800;
            ppuVar3 = &pulls_keeper;
            if (0x20 < uVar6 * 8 || uVar6 * -8 == -0x20) goto LAB_00102804;
          }
          else {
            if (2 < (uint)local_78) {
LAB_00102800:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102804);
              (*pcVar4)();
            }
            ppuVar3 = &pulls_no_keeper;
            if (0x18 < uVar6 * 8 || uVar6 * -8 == -0x18) {
LAB_00102804:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(1,0x102808);
              (*pcVar4)();
            }
          }
          seq_printf(param_1,&DAT_00105ed4,ppuVar3[uVar6]);
          seq_puts(param_1,&DAT_001060ae);
        }
        else {
          seq_printf(param_1," %-8s: egpio\n",uVar7);
        }
      }
      uVar8 = uVar8 + 1;
      lVar9 = lVar9 + 0x58;
    } while (uVar8 < *(ushort *)(param_2 + 0xac));
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_ps_hold_restart @ 00102810 size=76
// signature: undefined msm_ps_hold_restart(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ps_hold_restart(long param_1)

{
  bool bVar1;
  long lVar2;
  
  writel(0,*(long *)(param_1 + 0xf8) + 0x820);
  lVar2 = -1000;
  do {
    __const_udelay(0x418958);
    bVar1 = lVar2 != -1;
    lVar2 = lVar2 + 1;
  } while (bVar1);
  return 0;
}



//------------------------------------------------------------
// msm_ps_hold_poweroff @ 00102860 size=80
// signature: undefined msm_ps_hold_poweroff(void)
// callers: []
//------------------------------------------------------------

void msm_ps_hold_poweroff(void)

{
  bool bVar1;
  long lVar2;
  
  writel(0,*(long *)(poweroff_pctrl + 1000) + 0x820);
  lVar2 = -1000;
  do {
    __const_udelay(0x418958);
    bVar1 = lVar2 != -1;
    lVar2 = lVar2 + 1;
  } while (bVar1);
  return;
}



//------------------------------------------------------------
// msm_get_groups_count @ 001028b4 size=36
// signature: undefined msm_get_groups_count(void)
// callers: []
//------------------------------------------------------------

undefined4 msm_get_groups_count(void)

{
  long lVar1;
  
  lVar1 = pinctrl_dev_get_drvdata();
  return *(undefined4 *)(*(long *)(lVar1 + 0x3e0) + 0x28);
}



//------------------------------------------------------------
// msm_get_group_name @ 001028dc size=60
// signature: undefined msm_get_group_name(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_get_group_name(undefined8 param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = pinctrl_dev_get_drvdata();
  return *(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x3e0) + 0x20) + (ulong)param_2 * 0x58);
}



//------------------------------------------------------------
// msm_get_group_pins @ 0010291c size=104
// signature: undefined msm_get_group_pins(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_get_group_pins(undefined8 param_1,uint param_2,undefined8 *param_3,undefined4 *param_4)

{
  long lVar1;
  
  lVar1 = pinctrl_dev_get_drvdata();
  *param_3 = *(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x3e0) + 0x20) + (ulong)param_2 * 0x58 + 8)
  ;
  *param_4 = *(undefined4 *)
              (*(long *)(*(long *)(lVar1 + 0x3e0) + 0x20) + (ulong)param_2 * 0x58 + 0x10);
  return 0;
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map_group @ 00102988 size=32
// signature: undefined pinconf_generic_dt_node_to_map_group(void)
// callers: []
//------------------------------------------------------------

void pinconf_generic_dt_node_to_map_group(void)

{
  pinconf_generic_dt_node_to_map();
  return;
}



//------------------------------------------------------------
// msm_pinmux_request @ 001029ac size=64
// signature: undefined msm_pinmux_request(void)
// callers: []
//------------------------------------------------------------

undefined4 msm_pinmux_request(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  lVar1 = pinctrl_dev_get_drvdata();
  uVar2 = gpiochip_line_is_valid(lVar1 + 0x10,param_2);
  uVar3 = 0;
  if ((uVar2 & 1) == 0) {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_get_functions_count @ 001029f0 size=36
// signature: undefined msm_get_functions_count(void)
// callers: []
//------------------------------------------------------------

undefined4 msm_get_functions_count(void)

{
  long lVar1;
  
  lVar1 = pinctrl_dev_get_drvdata();
  return *(undefined4 *)(*(long *)(lVar1 + 0x3e0) + 0x18);
}



//------------------------------------------------------------
// msm_get_function_name @ 00102a18 size=60
// signature: undefined msm_get_function_name(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_get_function_name(undefined8 param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = pinctrl_dev_get_drvdata();
  return *(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x3e0) + 0x10) + (ulong)param_2 * 0x18);
}



//------------------------------------------------------------
// msm_get_function_groups @ 00102a58 size=104
// signature: undefined msm_get_function_groups(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_get_function_groups(undefined8 param_1,uint param_2,undefined8 *param_3,undefined4 *param_4)

{
  long lVar1;
  
  lVar1 = pinctrl_dev_get_drvdata();
  *param_3 = *(undefined8 *)(*(long *)(*(long *)(lVar1 + 0x3e0) + 0x10) + (ulong)param_2 * 0x18 + 8)
  ;
  *param_4 = *(undefined4 *)
              (*(long *)(*(long *)(lVar1 + 0x3e0) + 0x10) + (ulong)param_2 * 0x18 + 0x10);
  return 0;
}



//------------------------------------------------------------
// msm_pinmux_set_mux @ 00102ac4 size=1080
// signature: undefined msm_pinmux_set_mux(void)
// callers: [msm_pinmux_request_gpio, msm_gpio_irq_reqres]
//------------------------------------------------------------

void msm_pinmux_set_mux(undefined8 param_1,int param_2,ulong param_3)

{
  ulong *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  code *pcVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  long lVar14;
  ulong uVar15;
  uint uVar16;
  long lVar17;
  ulong uVar18;
  ulong uVar19;
  uint uVar20;
  uint uVar21;
  uint *puVar22;
  ulong uVar23;
  long lVar24;
  long lVar25;
  ulong *puVar26;
  uint *puVar27;
  undefined4 local_6c;
  long local_68;
  
  lVar11 = sp_el0;
  uVar23 = param_3 & 0xffffffff;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = pinctrl_dev_get_drvdata();
  lVar14 = *(long *)(lVar11 + 0x3e0);
  local_6c = 0;
  lVar12 = __irq_resolve_mapping(*(undefined8 *)(lVar11 + 0x138),uVar23,&local_6c);
  uVar2 = 0;
  if (lVar12 != 0) {
    uVar2 = local_6c;
  }
  lVar12 = irq_get_irq_data(uVar2);
  lVar17 = *(long *)(lVar11 + 0x3e0);
  lVar24 = *(long *)(lVar17 + 0x20);
  lVar25 = lVar24 + uVar23 * 0x58;
  uVar4 = *(uint *)(lVar17 + 0x6c);
  uVar5 = *(uint *)(lVar17 + 0x70);
  puVar26 = (ulong *)(lVar25 + 0x3c);
  uVar21 = *(uint *)puVar26 >> 7 & 0x1f;
  uVar9 = *(uint *)(lVar25 + 0x20);
  uVar20 = (uint)(-1L << uVar21);
  if (uVar9 < 2) {
    uVar20 = (uint)(0xffffffffffffffff >> ((ulong)-uVar21 & 0x3f)) & uVar20;
    if (uVar9 == 0) {
      uVar21 = 0;
LAB_00102bcc:
      if (uVar21 != uVar9) {
        if ((lVar12 != 0) && (uVar21 != uVar4)) {
          uVar15 = 1L << (*(ulong *)(lVar12 + 8) & 0x3f);
          puVar1 = (ulong *)(lVar11 + 0x390 + (*(ulong *)(lVar12 + 8) >> 6 & 0x3ffffff) * 8);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            uVar18 = *puVar1;
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar7) {
              *puVar1 = uVar18 | uVar15;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          DataMemoryBarrier(2,3);
          if ((uVar18 & uVar15) == 0) {
            disable_irq(uVar2);
          }
        }
        uVar13 = _raw_spin_lock_irqsave();
        puVar22 = (uint *)(lVar24 + uVar23 * 0x58 + 0x24);
        uVar9 = readl(*(long *)(lVar11 + (*puVar26 >> 5 & 3) * 8 + 1000) + (ulong)*puVar22);
        if ((uVar21 == uVar4) && ((uVar9 >> (*puVar26 >> 0x25 & 0x1f) & 1) != 0)) {
          uVar15 = 1L << (param_3 & 0x3f);
          puVar1 = (ulong *)(lVar11 + 0x3b8 + (uVar23 >> 6) * 8);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            uVar18 = *puVar1;
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar7) {
              *puVar1 = uVar18 | uVar15;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          DataMemoryBarrier(2,3);
          if ((uVar18 & uVar15) == 0) {
            puVar27 = (uint *)(lVar24 + uVar23 * 0x58 + 0x28);
            uVar10 = readl(*(long *)(lVar11 + (*puVar26 >> 5 & 3) * 8 + 1000) + (ulong)*puVar27);
            uVar15 = *puVar26;
            uVar18 = 1L << (uVar15 >> 0x2f & 0x1f);
            uVar19 = uVar18 & uVar10;
            uVar16 = (uint)uVar18;
            if ((uVar10 >> (uVar15 >> 0x2a & 0x1f) & 1) == 0) {
              if (uVar19 == 0) goto LAB_00102d08;
              uVar10 = uVar10 & (uVar16 ^ 0xffffffff);
            }
            else {
              if (uVar19 != 0) goto LAB_00102d08;
              uVar10 = uVar10 | uVar16;
            }
            writel(uVar10,*(long *)(lVar11 + (uVar15 >> 5 & 3) * 8 + 1000) + (ulong)*puVar27);
          }
        }
LAB_00102d08:
        if ((uVar5 == 0) || (uVar21 != uVar5)) {
          uVar15 = *puVar26;
          uVar9 = uVar21 << (ulong)((uint)(uVar15 >> 7) & 0x1f) | uVar9 & (uVar20 ^ 0xffffffff);
          if ((uVar5 != 0) &&
             (((uVar9 >> (uVar15 >> 0x20 & 0x1f) & 1) != 0 &&
              (*(int *)(*(long *)(lVar24 + uVar23 * 0x58 + 0x18) + (ulong)uVar5 * 4) !=
               *(int *)(lVar14 + 0x18))))) {
            uVar9 = uVar9 | 1 << (ulong)((uint)(uVar15 >> 0x1b) & 0x1f);
          }
        }
        else {
          uVar15 = *puVar26;
          if ((uVar9 >> (uVar15 >> 0x20 & 0x1f) & 1) != 0) {
            uVar9 = uVar9 & (1 << (ulong)((uint)(uVar15 >> 0x1b) & 0x1f) ^ 0xffffffffU);
          }
        }
        writel(uVar9,*(long *)(lVar11 + (uVar15 >> 5 & 3) * 8 + 1000) + (ulong)*puVar22);
        _raw_spin_unlock_irqrestore(lVar11 + 0x314,uVar13);
        if ((lVar12 != 0) && (uVar21 == uVar4)) {
          uVar15 = 1L << (*(ulong *)(lVar12 + 8) & 0x3f);
          puVar1 = (ulong *)(lVar11 + 0x390 + (*(ulong *)(lVar12 + 8) >> 6 & 0x3ffffff) * 8);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            uVar18 = *puVar1;
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar7) {
              *puVar1 = uVar18 & (uVar15 ^ 0xffffffffffffffff);
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          DataMemoryBarrier(2,3);
          if ((uVar18 & uVar15) != 0) {
            if ((*(long *)(lVar12 + 0x28) == 0) ||
               ((*(ulong *)(lVar11 + (*(ulong *)(lVar12 + 8) >> 6) * 8 + 0x368) >>
                 (*(ulong *)(lVar12 + 8) & 0x3f) & 1) == 0)) {
              uVar15 = *puVar26;
              iVar3 = 0;
              if ((uVar15 & 0x4000000000000000) != 0) {
                iVar3 = 1 << (ulong)((uint)(uVar15 >> 0x39) & 0x1f);
              }
              writel(iVar3,*(long *)(lVar11 + (uVar15 >> 5 & 3) * 8 + 1000) +
                           (ulong)*(uint *)(lVar24 + uVar23 * 0x58 + 0x30));
            }
            else {
              irq_chip_set_parent_state(lVar12,0,0);
            }
            enable_irq(uVar2);
          }
        }
        lVar11 = sp_el0;
        if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail(0);
        }
        return;
      }
      goto LAB_00102bbc;
    }
  }
  else {
    uVar20 = (uint)(0xffffffffffffffff >> ((ulong)((int)LZCOUNT((ulong)uVar9 - 1) - uVar21) & 0x3f))
             & uVar20;
  }
  uVar21 = 0;
  do {
    if (*(int *)(*(long *)(lVar24 + uVar23 * 0x58 + 0x18) + (long)(int)uVar21 * 4) == param_2)
    goto LAB_00102bcc;
    uVar21 = uVar21 + 1;
  } while (uVar9 != uVar21);
LAB_00102bbc:
                    /* WARNING: Does not return */
  pcVar8 = (code *)SoftwareBreakpoint(0x800,0x102bc4);
  (*pcVar8)();
}



//------------------------------------------------------------
// msm_pinmux_request_gpio @ 00102f2c size=112
// signature: undefined msm_pinmux_request_gpio(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pinmux_request_gpio(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  param_3 = param_3 & 0xffffffff;
  lVar1 = pinctrl_dev_get_drvdata();
  lVar3 = *(long *)(*(long *)(lVar1 + 0x3e0) + 0x20);
  if (*(int *)(lVar3 + param_3 * 0x58 + 0x20) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = msm_pinmux_set_mux(param_1,*(undefined4 *)
                                        (*(long *)(lVar3 + param_3 * 0x58 + 0x18) +
                                        (ulong)*(uint *)(*(long *)(lVar1 + 0x3e0) + 0x6c) * 4),
                               param_3);
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_config_group_get @ 00102fa0 size=556
// signature: undefined msm_config_group_get(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_config_group_get(undefined8 param_1,ulong param_2,ulong *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  
  param_2 = param_2 & 0xffffffff;
  lVar4 = pinctrl_dev_get_drvdata();
  uVar9 = *param_3;
  uVar5 = gpiochip_line_is_valid(msm_pinctrl_data + 0x10,param_2);
  if ((uVar5 & 1) == 0) {
    return 0xffffffea;
  }
  uVar6 = 0xfffffdf4;
  lVar10 = *(long *)(*(long *)(lVar4 + 0x3e0) + 0x20);
  uVar8 = (uint)uVar9;
  switch(uVar9 & 0xff) {
  case 0:
  case 1:
  case 3:
  case 5:
    uVar3 = 3;
    uVar5 = (ulong)(*(uint *)(lVar10 + param_2 * 0x58 + 0x3c) >> 0xc & 0x1f);
    goto LAB_0010306c;
  case 2:
  case 4:
  case 7:
  case 8:
  case 10:
  case 0xb:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    goto switchD_00103024_caseD_2;
  case 6:
    lVar10 = lVar10 + param_2 * 0x58;
    uVar5 = *(ulong *)(lVar10 + 0x3c);
    uVar3 = readl(*(long *)(lVar4 + (uVar5 >> 5 & 3) * 8 + 1000) + (ulong)*(uint *)(lVar10 + 0x24));
    if ((uVar3 >> (ulong)((uint)(uVar5 >> 0x16) & 0x1f) & 1) == 0) {
      return 0xffffffea;
    }
    break;
  case 9:
    lVar10 = lVar10 + param_2 * 0x58;
    uVar5 = *(ulong *)(lVar10 + 0x3c);
    uVar3 = readl(*(long *)(lVar4 + (uVar5 >> 5 & 3) * 8 + 1000) + (ulong)*(uint *)(lVar10 + 0x24));
    iVar7 = (uVar3 >> (ulong)((uint)(uVar5 >> 0x11) & 0x1f) & 7) * 2 + 2;
    goto LAB_00103228;
  case 0xc:
  case 0x11:
    uVar3 = 1;
    uVar5 = *(ulong *)(lVar10 + param_2 * 0x58 + 0x3c) >> 0x25 & 0x1f;
LAB_0010306c:
    lVar10 = lVar10 + param_2 * 0x58;
    uVar2 = readl(*(long *)(lVar4 + (*(ulong *)(lVar10 + 0x3c) >> 5 & 3) * 8 + 1000) +
                  (ulong)*(uint *)(lVar10 + 0x24));
    uVar1 = uVar8 & 0xff;
    uVar3 = uVar2 >> uVar5 & uVar3;
    if (uVar1 < 0x12) {
                    /* WARNING: Jumptable with 0 entries at 0x001030c4 */
                    /* WARNING: Treating indirect jump as call */
      uVar6 = (*(code *)(&UNK_001030c8 + (ulong)(byte)(&DAT_00105742)[uVar9 & 0xff] * 4))
                        (0xfffffdf4);
      return uVar6;
    }
    if (uVar1 == 0x80) {
      if ((uVar2 >> 0xb & 1) == 0) {
        return 0xffffffea;
      }
      if (uVar3 == 0) {
        return 0xffffffea;
      }
    }
    else {
      if (uVar1 != 0x81) {
        return 0xfffffdf4;
      }
      if ((uVar2 >> 0xb & 1) == 0) {
        return 0xffffffea;
      }
      if (uVar3 != 0) {
        return 0xffffffea;
      }
    }
    break;
  default:
    if ((uVar8 & 0xff) - 0x80 < 2) {
      uVar3 = 1;
      uVar5 = 0xc;
      goto LAB_0010306c;
    }
    if ((uVar8 & 0xff) != 0x82) {
      return 0xfffffdf4;
    }
    lVar10 = lVar10 + param_2 * 0x58;
    readl(*(long *)(lVar4 + (*(ulong *)(lVar10 + 0x3c) >> 5 & 3) * 8 + 1000) +
          (ulong)*(uint *)(lVar10 + 0x24));
  }
  iVar7 = 1;
LAB_00103228:
  uVar6 = 0;
  *param_3 = (ulong)(uVar8 & 0xff | iVar7 << 8);
switchD_00103024_caseD_2:
  return uVar6;
}



//------------------------------------------------------------
// msm_config_group_set @ 0010325c size=808
// signature: undefined msm_config_group_set(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001033f8) */

undefined8 msm_config_group_set(undefined8 param_1,ulong param_2,long param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  uint *puVar10;
  uint uVar11;
  ulong *puVar12;
  ulong uVar13;
  ulong uVar14;
  int iVar15;
  int local_80;
  
  puVar5 = (undefined8 *)pinctrl_dev_get_drvdata();
  if (param_4 != 0) {
    iVar15 = 0;
    lVar8 = *(long *)(puVar5[0x7c] + 0x20);
    bVar2 = false;
    local_80 = 0;
    lVar7 = lVar8 + (param_2 & 0xffffffff) * 0x58;
    puVar12 = (ulong *)(lVar7 + 0x3c);
    puVar10 = (uint *)(lVar7 + 0x24);
    do {
      uVar6 = 0xfffffdf4;
      uVar14 = *(ulong *)(param_3 + (long)iVar15 * 8);
      uVar13 = uVar14 >> 8 & 0xffffff;
      uVar3 = (uint)uVar14;
      uVar4 = (uint)uVar13;
      switch(uVar14 & 0xff) {
      case 0:
      case 1:
      case 3:
      case 5:
        uVar11 = 3;
        uVar9 = (ulong)(*(uint *)puVar12 >> 0xc & 0x1f);
        break;
      case 2:
      case 4:
      case 7:
      case 8:
      case 10:
      case 0xb:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
        goto switchD_00103324_caseD_2;
      case 6:
        uVar9 = (ulong)(*(uint *)puVar12 >> 0x16 & 0x1f);
LAB_001033ec:
        uVar11 = 1;
        uVar4 = 1;
        goto LAB_001034dc;
      case 9:
        uVar11 = 7;
        uVar9 = (ulong)(*(uint *)puVar12 >> 0x11 & 0x1f);
        if (((uVar3 >> 8 & 1) != 0) || (0xe < uVar4 - 2)) {
          uVar13 = 0xffffffff;
          goto LAB_0010355c;
        }
        uVar4 = (uVar3 >> 9) - 1;
        uVar13 = (ulong)uVar4;
        uVar1 = uVar4 & 0xfffffff8;
        goto joined_r0x00103424;
      case 0xc:
      case 0x11:
        uVar11 = 1;
        uVar9 = *puVar12 >> 0x25 & 0x1f;
        break;
      default:
        uVar11 = 1;
        if (1 < (uVar3 & 0xff) - 0x80) {
          if ((uVar3 & 0xff) != 0x82) {
            return 0xfffffdf4;
          }
          uVar9 = 0xd;
          goto LAB_001033ec;
        }
        uVar9 = 0xc;
      }
      uVar1 = uVar3 & 0xff;
      if (uVar1 < 0x12) {
                    /* WARNING: Jumptable with 0 entries at 0x00103388 */
                    /* WARNING: Treating indirect jump as call */
        uVar6 = (*(code *)(&UNK_0010338c + (ulong)(byte)(&DAT_00105766)[uVar14 & 0xff] * 4))
                          (0xfffffdf4);
        return uVar6;
      }
      if (uVar1 == 0x80) {
        local_80 = 1;
      }
      else {
        if (uVar1 != 0x81) {
          _dev_err(*puVar5,"Unsupported config parameter: %x\n",uVar3 & 0xff);
          return 0xffffffea;
        }
        local_80 = 0;
      }
      uVar1 = uVar4 & (uVar11 ^ 0xffffffff);
      bVar2 = true;
joined_r0x00103424:
      if (uVar1 != 0) {
LAB_0010355c:
        _dev_err(*puVar5,"config %x: %x is invalid\n",uVar3 & 0xff,uVar13);
        return 0xffffffea;
      }
LAB_001034dc:
      if ((uVar3 & 0xfe) != 0x80) {
        uVar6 = _raw_spin_lock_irqsave((long)puVar5 + 0x314);
        uVar3 = readl(puVar5[(*puVar12 >> 5 & 3) + 0x7d] + (ulong)*puVar10);
        writel(uVar3 & (uVar11 << uVar9 ^ 0xffffffff) | uVar4 << uVar9,
               puVar5[(*puVar12 >> 5 & 3) + 0x7d] + (ulong)*puVar10);
        _raw_spin_unlock_irqrestore((long)puVar5 + 0x314,uVar6);
      }
      iVar15 = iVar15 + 1;
    } while (param_4 != iVar15);
    if (bVar2) {
      uVar6 = _raw_spin_lock_irqsave((long)puVar5 + 0x314);
      lVar8 = lVar8 + (param_2 & 0xffffffff) * 0x58;
      puVar12 = (ulong *)(lVar8 + 0x3c);
      puVar10 = (uint *)(lVar8 + 0x24);
      uVar4 = readl(puVar5[(*puVar12 >> 5 & 3) + 0x7d] + (ulong)*puVar10);
      if ((uVar4 >> 0xb & 1) != 0) {
        writel(uVar4 & 0xffffefff | local_80 << 0xc,
               puVar5[(*puVar12 >> 5 & 3) + 0x7d] + (ulong)*puVar10);
      }
      _raw_spin_unlock_irqrestore((long)puVar5 + 0x314,uVar6);
    }
  }
  uVar6 = 0;
switchD_00103324_caseD_2:
  return uVar6;
}



//------------------------------------------------------------
// msm_gpio_init_valid_mask @ 00103640 size=712
// signature: undefined msm_gpio_init_valid_mask(void)
// callers: []
//------------------------------------------------------------

int msm_gpio_init_valid_mask(undefined8 param_1,void *param_2,uint param_3)

{
  ulong *puVar1;
  ushort uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  uint *puVar11;
  uint local_4c;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  plVar7 = (long *)gpiochip_get_data();
  local_4c = 0;
  puVar11 = *(uint **)(plVar7[0x7c] + 0x48);
  if (puVar11 == (uint *)0x0) {
    iVar5 = of_property_count_elems_of_size
                      (*(undefined8 *)(*plVar7 + 0x2e8),"qcom,gpios-reserved",4);
    if (0 < iVar5) {
      memset(param_2,0xff,(ulong)(param_3 + 0x3f >> 3 & 0x1ffffff8));
      uVar8 = of_find_property(*(undefined8 *)(*plVar7 + 0x2e8),"qcom,gpios-reserved",0);
      lVar9 = of_prop_next_u32(uVar8,0,&local_4c);
      if (lVar9 != 0) {
        do {
          if (param_3 <= local_4c) goto LAB_001038e8;
          puVar1 = (ulong *)((long)param_2 + (ulong)(local_4c >> 6) * 8);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar4) {
              *puVar1 = *puVar1 & (1L << ((ulong)local_4c & 0x3f) ^ 0xffffffffffffffffU);
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          lVar9 = of_prop_next_u32(uVar8,lVar9,&local_4c);
        } while (lVar9 != 0);
      }
    }
    uVar6 = device_property_read_u16_array(*plVar7,"gpios",0,0);
    if (-1 < (int)uVar6) {
      if (param_3 < uVar6) {
        iVar5 = -0x16;
      }
      else {
        lVar9 = __kmalloc((ulong)uVar6 << 1,0xcc0);
        if (lVar9 == 0) {
          iVar5 = -0xc;
        }
        else {
          iVar5 = device_property_read_u16_array(*plVar7,"gpios",lVar9,(ulong)uVar6);
          if (iVar5 < 0) {
            _dev_err(*plVar7,"could not read list of GPIOs\n");
          }
          else {
            memset(param_2,0,(ulong)(param_3 + 0x3f >> 3 & 0x1ffffff8));
            local_4c = 0;
            if (uVar6 != 0) {
              uVar10 = 0;
              do {
                uVar2 = *(ushort *)(lVar9 + uVar10 * 2);
                puVar1 = (ulong *)((long)param_2 + (ulong)(uVar2 >> 6) * 8);
                Hint_Prefetch(puVar1,2,0,1);
                do {
                  cVar3 = '\x01';
                  bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                  if (bVar4) {
                    *puVar1 = *puVar1 | 1L << ((ulong)uVar2 & 0x3f);
                    cVar3 = ExclusiveMonitorsStatus();
                  }
                } while (cVar3 != '\0');
                local_4c = local_4c + 1;
                uVar10 = (ulong)local_4c;
              } while (local_4c < uVar6);
            }
          }
          kfree(lVar9);
        }
      }
      goto LAB_00103804;
    }
  }
  else {
    memset(param_2,0xff,(ulong)(param_3 + 0x3f >> 3 & 0x1ffffff8));
    local_4c = 0;
    uVar6 = *puVar11;
    while (-1 < (int)uVar6) {
      if ((param_3 <= local_4c) || (param_3 <= uVar6)) goto LAB_001038e8;
      puVar1 = (ulong *)((long)param_2 + (ulong)(uVar6 >> 6) * 8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & (1L << ((ulong)uVar6 & 0x3f) ^ 0xffffffffffffffffU);
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      local_4c = local_4c + 1;
      uVar6 = puVar11[local_4c];
    }
  }
  iVar5 = 0;
  goto LAB_00103804;
LAB_001038e8:
  _dev_err(*plVar7,"invalid list of reserved GPIOs\n");
  iVar5 = -0x16;
LAB_00103804:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// msm_gpio_wakeirq @ 00103924 size=304
// signature: undefined msm_gpio_wakeirq(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_gpio_wakeirq(undefined8 param_1,uint param_2,undefined8 param_3,int *param_4,undefined4 *param_5
                )

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong *puVar7;
  uint *puVar8;
  uint *puVar9;
  
  lVar4 = gpiochip_get_data();
  *param_4 = -1;
  *param_5 = 1;
  uVar1 = *(uint *)(*(long *)(lVar4 + 0x3e0) + 0x58);
  if (uVar1 != 0) {
    lVar5 = *(long *)(*(long *)(lVar4 + 0x3e0) + 0x50);
    uVar6 = 0;
    do {
      if (*(uint *)(lVar5 + (-(uVar6 >> 0x1f) & 0xfffffff800000000 | uVar6 << 3)) == param_2) {
        iVar2 = *(int *)(lVar5 + (long)(int)uVar6 * 8 + 4);
        *param_4 = iVar2;
        if (iVar2 == -1) {
          return 0;
        }
        goto LAB_001039b4;
      }
      uVar3 = (int)uVar6 + 1;
      uVar6 = (ulong)uVar3;
    } while (uVar1 != uVar3);
  }
  if (*param_4 != -1) {
LAB_001039b4:
    lVar5 = *(long *)(*(long *)(lVar4 + 0x3e0) + 0x20);
    puVar8 = (uint *)(lVar5 + (ulong)param_2 * 0x58 + 0x44);
    if ((*puVar8 & 0xf8000) != 0) {
      lVar5 = lVar5 + (ulong)param_2 * 0x58;
      puVar7 = (ulong *)(lVar5 + 0x3c);
      puVar9 = (uint *)(lVar5 + 0x2c);
      uVar3 = readl(*(long *)(lVar4 + (*puVar7 >> 5 & 3) * 8 + 1000) + (ulong)*puVar9);
      uVar1 = *puVar8;
      if ((uVar3 >> ((ulong)(uVar1 >> 0xf) & 0x1f) & 1) != 0) {
        writel(1 << (ulong)(uVar1 >> 10 & 0x1f) | uVar3,
               *(long *)(lVar4 + (*puVar7 >> 5 & 3) * 8 + 1000) + (ulong)*puVar9);
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_gpio_irq_handler @ 00103a58 size=396
// signature: undefined msm_gpio_irq_handler(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_handler(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  long lVar8;
  
  lVar5 = *(long *)(param_1 + 8);
  lVar2 = gpiochip_get_data(lVar5);
  lVar6 = *(long *)(param_1 + 0x48);
  if (*(long *)(lVar6 + 0x48) == 0) {
    pcVar4 = *(code **)(lVar6 + 0x38);
    if (pcVar4 == (code *)0x0) {
      if (*(int *)(*(code **)(lVar6 + 0x30) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103acc);
        (*pcVar4)();
      }
      (**(code **)(lVar6 + 0x30))(param_1 + 0x30);
      pcVar4 = *(code **)(lVar6 + 0x28);
      if (pcVar4 == (code *)0x0) goto LAB_00103af8;
    }
    if (*(int *)(pcVar4 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103af4);
      (*pcVar4)();
    }
    (*pcVar4)(param_1 + 0x30);
  }
LAB_00103af8:
  iVar7 = 0;
  iVar1 = 0;
  while (iVar1 = _find_next_bit(lVar2 + 0x340,*(undefined2 *)(lVar2 + 0xbc),(long)iVar1),
        iVar1 < (int)(uint)*(ushort *)(lVar2 + 0xbc)) {
    lVar8 = *(long *)(*(long *)(lVar2 + 0x3e0) + 0x20) + (long)iVar1 * 0x58;
    uVar3 = readl(*(long *)(lVar2 + (*(ulong *)(lVar8 + 0x3c) >> 5 & 3) * 8 + 1000) +
                  (ulong)*(uint *)(lVar8 + 0x30));
    if (((uVar3 & 0xffffffff) >> (*(ulong *)(lVar8 + 0x3c) >> 0x39 & 0x1f) & 1) != 0) {
      generic_handle_domain_irq(*(undefined8 *)(lVar5 + 0x128),iVar1);
      iVar7 = iVar7 + 1;
    }
    iVar1 = iVar1 + 1;
  }
  if (iVar7 == 0) {
    handle_bad_irq(param_1);
    pcVar4 = *(code **)(lVar6 + 0x48);
  }
  else {
    pcVar4 = *(code **)(lVar6 + 0x48);
  }
  if (pcVar4 == (code *)0x0) {
    pcVar4 = *(code **)(lVar6 + 0x40);
  }
  if (*(int *)(pcVar4 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103bac);
    (*pcVar4)();
  }
  (*pcVar4)(param_1 + 0x30);
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_init_valid_mask @ 00103be8 size=184
// signature: undefined msm_gpio_irq_init_valid_mask(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_init_valid_mask(undefined8 param_1,void *param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  
  lVar4 = gpiochip_get_data();
  memset(param_2,0xff,(ulong)(param_3 + 0x3fU >> 3 & 0x1ffffff8));
  if (param_3 != 0) {
    iVar5 = 0;
    do {
      if (1 < (*(uint *)(*(long *)(*(long *)(lVar4 + 0x3e0) + 0x20) + (long)iVar5 * 0x58 + 0x48) >>
               10 & 0x1f) - 1) {
        puVar1 = (ulong *)((long)param_2 + ((ulong)(long)iVar5 >> 6 & 0x3ffffff) * 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & (1L << ((long)iVar5 & 0x3fU) ^ 0xffffffffffffffffU);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      iVar5 = iVar5 + 1;
    } while (param_3 != iVar5);
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_enable @ 00103cb0 size=120
// signature: undefined msm_gpio_irq_enable(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_enable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x30);
  lVar1 = gpiochip_get_data(uVar2);
  gpiochip_enable_irq(uVar2,*(undefined4 *)(param_1 + 8));
  if (*(long *)(param_1 + 0x28) != 0) {
    irq_chip_enable_parent(param_1);
  }
  if ((*(ulong *)(lVar1 + (*(ulong *)(param_1 + 8) >> 6) * 8 + 0x368) >>
       (*(ulong *)(param_1 + 8) & 0x3f) & 1) == 0) {
    msm_gpio_irq_unmask(param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_disable @ 00103d2c size=120
// signature: undefined msm_gpio_irq_disable(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_disable(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + 0x30);
  lVar1 = gpiochip_get_data(uVar3);
  if (*(long *)(param_1 + 0x28) != 0) {
    irq_chip_disable_parent(param_1);
  }
  uVar2 = *(ulong *)(param_1 + 8);
  if ((*(ulong *)(lVar1 + (uVar2 >> 6) * 8 + 0x368) >> (uVar2 & 0x3f) & 1) == 0) {
    msm_gpio_irq_mask(param_1);
    uVar2 = *(ulong *)(param_1 + 8);
  }
  gpiochip_disable_irq(uVar3,uVar2);
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_ack @ 00103da8 size=244
// signature: undefined msm_gpio_irq_ack(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_ack(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  
  lVar2 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  uVar6 = *(ulong *)(param_1 + 8);
  lVar4 = lVar2 + (uVar6 >> 6) * 8;
  if ((*(ulong *)(lVar4 + 0x368) >> (uVar6 & 0x3f) & 1) == 0) {
    lVar7 = *(long *)(*(long *)(lVar2 + 0x3e0) + 0x20);
    uVar3 = _raw_spin_lock_irqsave(lVar2 + 0x314);
    lVar4 = lVar7 + uVar6 * 0x58;
    uVar5 = *(ulong *)(lVar4 + 0x3c);
    iVar1 = 0;
    if ((uVar5 & 0x4000000000000000) != 0) {
      iVar1 = 1 << (ulong)((uint)(uVar5 >> 0x39) & 0x1f);
    }
    writel(iVar1,*(long *)(lVar2 + (uVar5 >> 5 & 3) * 8 + 1000) + (ulong)*(uint *)(lVar4 + 0x30));
    if ((*(ulong *)(lVar2 + (*(ulong *)(param_1 + 8) >> 6) * 8 + 0x318) >>
         (*(ulong *)(param_1 + 8) & 0x3f) & 1) != 0) {
      msm_gpio_update_dual_edge_pos(lVar2,lVar7 + uVar6 * 0x58);
    }
    _raw_spin_unlock_irqrestore(lVar2 + 0x314,uVar3);
  }
  else if ((*(ulong *)(lVar4 + 0x318) >> (uVar6 & 0x3f) & 1) != 0) {
    msm_gpio_update_dual_edge_parent(param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_mask @ 00103ea0 size=324
// signature: undefined msm_gpio_irq_mask(void)
// callers: [msm_gpio_irq_disable]
//------------------------------------------------------------

void msm_gpio_irq_mask(long param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  uint *puVar7;
  ulong uVar8;
  ulong *puVar9;
  long lVar10;
  
  lVar4 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if (*(long *)(param_1 + 0x28) != 0) {
    irq_chip_mask_parent(param_1);
  }
  uVar8 = *(ulong *)(param_1 + 8);
  if ((*(ulong *)(lVar4 + (uVar8 >> 6) * 8 + 0x368) >> (uVar8 & 0x3f) & 1) == 0) {
    lVar10 = *(long *)(*(long *)(lVar4 + 0x3e0) + 0x20);
    uVar5 = _raw_spin_lock_irqsave(lVar4 + 0x314);
    lVar6 = lVar10 + uVar8 * 0x58;
    puVar7 = (uint *)(lVar6 + 0x2c);
    puVar9 = (ulong *)(lVar6 + 0x3c);
    uVar3 = readl(*(long *)(lVar4 + (*puVar9 >> 5 & 3) * 8 + 1000) + (ulong)*puVar7);
    if ((**(byte **)(param_1 + 0x10) & 0xc) != 0) {
      uVar3 = uVar3 & (1 << (ulong)(*(uint *)(lVar10 + uVar8 * 0x58 + 0x44) >> 0x19 & 0x1f) ^
                      0xffffffffU);
    }
    uVar8 = *puVar9;
    writel(uVar3 & (1 << (ulong)((uint)(uVar8 >> 0x34) & 0x1f) ^ 0xffffffffU),
           *(long *)(lVar4 + (uVar8 >> 5 & 3) * 8 + 1000) + (ulong)*puVar7);
    uVar8 = *(ulong *)(param_1 + 8);
    puVar9 = (ulong *)(lVar4 + 0x340 + (uVar8 >> 6 & 0x3ffffff) * 8);
    Hint_Prefetch(puVar9,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(puVar9,0x10);
      if (bVar2) {
        *puVar9 = *puVar9 & (1L << (uVar8 & 0x3f) ^ 0xffffffffffffffffU);
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    _raw_spin_unlock_irqrestore(lVar4 + 0x314,uVar5);
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_unmask @ 00103ff0 size=280
// signature: undefined msm_gpio_irq_unmask(void)
// callers: [msm_gpio_irq_enable]
//------------------------------------------------------------

void msm_gpio_irq_unmask(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  
  lVar5 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if (*(long *)(param_1 + 0x28) != 0) {
    irq_chip_unmask_parent(param_1);
  }
  uVar7 = *(ulong *)(param_1 + 8);
  if ((*(ulong *)(lVar5 + (uVar7 >> 6) * 8 + 0x368) >> (uVar7 & 0x3f) & 1) == 0) {
    lVar8 = *(long *)(*(long *)(lVar5 + 0x3e0) + 0x20);
    uVar6 = _raw_spin_lock_irqsave(lVar5 + 0x314);
    lVar8 = lVar8 + uVar7 * 0x58;
    uVar4 = readl(*(long *)(lVar5 + 1000 + (*(ulong *)(lVar8 + 0x3c) >> 5 & 3) * 8) +
                  (ulong)*(uint *)(lVar8 + 0x2c));
    writel(1 << (ulong)(*(uint *)(lVar8 + 0x44) >> 0x19 & 0x1f) |
           1 << (ulong)((uint)(*(ulong *)(lVar8 + 0x3c) >> 0x34) & 0x1f) | uVar4,
           *(long *)(lVar5 + 1000 + (*(ulong *)(lVar8 + 0x3c) >> 5 & 3) * 8) +
           (ulong)*(uint *)(lVar8 + 0x2c));
    uVar7 = *(ulong *)(param_1 + 8);
    puVar1 = (ulong *)(lVar5 + 0x340 + (uVar7 >> 6 & 0x3ffffff) * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 1L << (uVar7 & 0x3f);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    _raw_spin_unlock_irqrestore(lVar5 + 0x314,uVar6);
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_eoi @ 00104114 size=68
// signature: undefined msm_gpio_irq_eoi(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_eoi(long param_1)

{
  code *pcVar1;
  
  if (*(long *)(param_1 + 0x28) != 0) {
    pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x28) + 0x18) + 0x48);
    if (*(int *)(pcVar1 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104148);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_set_affinity @ 0010415c size=272
// signature: undefined msm_gpio_irq_set_affinity(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_irq_set_affinity(long param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  code *pcVar6;
  long lVar7;
  
  lVar2 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  uVar5 = (ulong)*(uint *)(lVar2 + 0x30c);
  if (*(uint *)(lVar2 + 0x30c) != 0) {
    lVar7 = uVar5 << 3;
    do {
      uVar5 = uVar5 - 1;
      piVar1 = (int *)(*(long *)(*(long *)(lVar2 + 0x3e0) + 0x90) + lVar7);
      lVar3 = irq_get_irq_data(piVar1[1]);
      if ((((lVar3 != 0) && (*(long *)(lVar3 + 0x18) != 0)) &&
          (pcVar6 = *(code **)(*(long *)(lVar3 + 0x18) + 0x50), pcVar6 != (code *)0x0)) &&
         (*(long *)(param_1 + 8) == (long)*piVar1)) {
        if (*(int *)(pcVar6 + -4) != 0x5b961711) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x104210);
          (*pcVar6)();
        }
        uVar4 = (*pcVar6)(lVar3,param_2,param_3 & 1);
        return uVar4;
      }
      lVar7 = lVar7 + -8;
    } while ((int)uVar5 != 0);
  }
  if ((*(long *)(param_1 + 0x28) == 0) ||
     ((*(ulong *)(lVar2 + (*(ulong *)(param_1 + 8) >> 6) * 8 + 0x368) >>
       (*(ulong *)(param_1 + 8) & 0x3f) & 1) == 0)) {
    uVar4 = 0xffffffea;
  }
  else {
    uVar4 = irq_chip_set_affinity_parent(param_1,param_2,param_3 & 1);
  }
  return uVar4;
}



//------------------------------------------------------------
// msm_gpio_irq_set_type @ 00104270 size=1608
// signature: undefined msm_gpio_irq_set_type(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_irq_set_type(long param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined8 *puVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  undefined4 *puVar14;
  ulong uVar15;
  undefined *puVar16;
  uint *puVar17;
  uint *puVar18;
  long lVar19;
  ulong *puVar20;
  long lVar21;
  long lVar22;
  uint *puVar23;
  uint local_6c;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  puVar10 = (undefined8 *)gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  local_6c = 0;
  lVar11 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if (((param_2 == 3) && (*(char *)(*(long *)(lVar11 + 0x3e0) + 0x5c) != '\0')) &&
     (*(long *)(param_1 + 0x28) != 0)) {
    uVar15 = *(ulong *)(param_1 + 8);
    uVar13 = 1L << (uVar15 & 0x3f);
    if ((*(ulong *)(lVar11 + (uVar15 >> 6) * 8 + 0x368) & uVar13) != 0) {
      puVar20 = puVar10 + (uVar15 >> 6 & 0x3ffffff) + 99;
      Hint_Prefetch(puVar20,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar20,0x10);
        if (bVar4) {
          *puVar20 = *puVar20 | uVar13;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      *(undefined **)(*(long *)(param_1 + 0x10) + 0x70) = &handle_fasteoi_ack_irq;
      msm_gpio_update_dual_edge_parent(param_1);
      goto LAB_00104828;
    }
  }
  if (*(long *)(param_1 + 0x28) != 0) {
    irq_chip_set_type_parent(param_1,param_2);
  }
  uVar15 = *(ulong *)(param_1 + 8);
  uVar13 = 1L << (uVar15 & 0x3f);
  if ((puVar10[(uVar15 >> 6) + 0x6d] & uVar13) == 0) {
    lVar11 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
    uVar9 = *(uint *)(lVar11 + 0x30c);
    if ((int)uVar9 < 1) {
      lVar21 = *(long *)(param_1 + 8);
    }
    else {
      uVar7 = 0;
      lVar21 = *(long *)(param_1 + 8);
      iVar6 = uVar9 + 1;
      puVar14 = (undefined4 *)(*(long *)(*(long *)(lVar11 + 0x3e0) + 0x90) + (ulong)uVar9 * 8 + 4);
      do {
        if (lVar21 == (int)puVar14[-1]) {
          if (param_2 != 3) {
            uVar2 = *puVar14;
            lVar11 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
            if ((param_2 & 5) != 0) {
              uVar12 = _raw_spin_lock_irqsave(lVar11 + 0x314);
              lVar21 = *(long *)(*(long *)(lVar11 + 0x3e0) + 0x20) + *(long *)(param_1 + 8) * 0x58;
              uVar9 = readl_relaxed(*(long *)(msm_pinctrl_data +
                                              (*(ulong *)(lVar21 + 0x3c) >> 5 & 3) * 8 + 1000) +
                                    (ulong)*(uint *)(lVar21 + 0x38) + (ulong)uVar7);
              writel_relaxed(uVar9 | 0x100,
                             *(long *)(msm_pinctrl_data + (*(ulong *)(lVar21 + 0x3c) >> 5 & 3) * 8 +
                                      1000) + (ulong)*(uint *)(lVar21 + 0x38) + (ulong)uVar7);
              _raw_spin_unlock_irqrestore(lVar11 + 0x314,uVar12);
            }
            lVar11 = irq_get_irq_data(uVar2);
            if ((lVar11 != 0) && (*(long *)(lVar11 + 0x18) != 0)) {
              pcVar5 = *(code **)(*(long *)(lVar11 + 0x18) + 0x40);
              if (*(int *)(pcVar5 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10472c);
                (*pcVar5)();
              }
              (*pcVar5)();
            }
            goto LAB_001047f8;
          }
          break;
        }
        puVar14 = puVar14 + -2;
        uVar7 = uVar7 + 4;
        iVar6 = iVar6 + -1;
      } while (1 < iVar6);
    }
    lVar11 = *(long *)(puVar10[0x7c] + 0x20);
    lVar22 = lVar11 + lVar21 * 0x58;
    uVar12 = _raw_spin_lock_irqsave((long)puVar10 + 0x314);
    puVar23 = (uint *)(lVar22 + 0x48);
    uVar15 = *(ulong *)(param_1 + 8) >> 6 & 0x3ffffff;
    uVar13 = 1L << (*(ulong *)(param_1 + 8) & 0x3f);
    if ((param_2 == 3) && ((*puVar23 & 0x7c00) == 0x400)) {
      puVar20 = puVar10 + uVar15 + 99;
      Hint_Prefetch(puVar20,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar20,0x10);
        if (bVar4) {
          *puVar20 = *puVar20 | uVar13;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else {
      puVar20 = puVar10 + uVar15 + 99;
      Hint_Prefetch(puVar20,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar20,0x10);
        if (bVar4) {
          *puVar20 = *puVar20 & (uVar13 ^ 0xffffffffffffffff);
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    puVar17 = (uint *)(lVar11 + lVar21 * 0x58 + 0x44);
    uVar13 = (ulong)(*puVar17 >> 5) & 0x1f;
    iVar6 = 7;
    if ((int)uVar13 != 0) {
      iVar6 = (int)(0xffffffffffffffff >> (-uVar13 & 0x3f));
    }
    if (*(char *)(puVar10 + 0x62) == '\0') {
      lVar19 = lVar11 + lVar21 * 0x58;
      uVar7 = readl(puVar10[(*(ulong *)(lVar19 + 0x3c) >> 5 & 3) + 0x7d] +
                    (ulong)*(uint *)(lVar19 + 0x34));
      uVar9 = *puVar17;
      local_6c = (uVar9 >> 0x14 & 0x1f) << (ulong)(uVar9 & 0x1f) |
                 uVar7 & (iVar6 << (ulong)(uVar9 & 0x1f) ^ 0xffffffffU);
      writel(local_6c,puVar10[(*(ulong *)(lVar19 + 0x3c) >> 5 & 3) + 0x7d] +
                      (ulong)*(uint *)(lVar19 + 0x34));
    }
    else {
      iVar1 = *(int *)(lVar11 + lVar21 * 0x58 + 0x34) + *(int *)(puVar10 + 0x81);
      qcom_scm_io_readl(iVar1,&local_6c);
      uVar9 = *puVar17;
      local_6c = (uVar9 >> 0x14 & 0x1f) << (ulong)(uVar9 & 0x1f) |
                 local_6c & (iVar6 << (ulong)(uVar9 & 0x1f) ^ 0xffffffffU);
      iVar6 = qcom_scm_io_writel(iVar1);
      if (iVar6 != 0) {
        _dev_err(*puVar10,"Failed routing %lu interrupt to Apps proc",*(undefined8 *)(param_1 + 8));
      }
    }
    lVar19 = lVar11 + lVar21 * 0x58;
    puVar20 = (ulong *)(lVar19 + 0x3c);
    puVar18 = (uint *)(lVar19 + 0x2c);
    uVar8 = readl(puVar10[(*puVar20 >> 5 & 3) + 0x7d] + (ulong)*puVar18);
    local_6c = 1 << (ulong)(*puVar17 >> 0x19 & 0x1f) | uVar8;
    uVar9 = *puVar23;
    uVar7 = uVar9 >> 10 & 0x1f;
    if (uVar7 != 1) {
      if (uVar7 != 2) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1048c0);
        (*pcVar5)();
      }
      local_6c = local_6c &
                 ((3 << (ulong)(uVar9 >> 5 & 0x1f) | 1 << (ulong)(*puVar23 & 0x1f)) ^ 0xffffffffU);
      switch(param_2) {
      case 1:
        goto switchD_001045cc_caseD_1;
      case 2:
        uVar9 = *puVar23;
        iVar6 = 2;
        break;
      case 3:
        uVar9 = *puVar23;
        iVar6 = 3;
        break;
      case 4:
        goto switchD_001045cc_caseD_4;
      default:
        goto switchD_001045cc_default;
      }
      uVar7 = iVar6 << (ulong)(uVar9 >> 5 & 0x1f);
LAB_00104758:
      uVar7 = uVar7 | 1 << (ulong)(uVar9 & 0x1f);
      goto LAB_0010475c;
    }
    local_6c = local_6c &
               ((1 << (ulong)(uVar9 >> 5 & 0x1f) | 1 << (ulong)(*puVar23 & 0x1f)) ^ 0xffffffffU);
    switch(param_2) {
    case 1:
    case 3:
switchD_001045cc_caseD_1:
      uVar9 = *puVar23;
      uVar7 = 1 << (ulong)(uVar9 >> 5 & 0x1f);
      goto LAB_00104758;
    case 2:
      uVar7 = 1 << (ulong)(*puVar23 >> 5 & 0x1f);
      break;
    case 4:
switchD_001045cc_caseD_4:
      uVar7 = 1 << (ulong)(*puVar23 & 0x1f);
      break;
    default:
      goto switchD_001045cc_default;
    }
LAB_0010475c:
    local_6c = uVar7 | local_6c;
switchD_001045cc_default:
    writel(local_6c,puVar10[(*puVar20 >> 5 & 3) + 0x7d] + (ulong)*puVar18);
    if (local_6c != uVar8) {
      uVar13 = *puVar20;
      iVar6 = 0;
      if ((uVar13 & 0x4000000000000000) != 0) {
        iVar6 = 1 << (ulong)((uint)(uVar13 >> 0x39) & 0x1f);
      }
      writel(iVar6,puVar10[(uVar13 >> 5 & 3) + 0x7d] +
                   (ulong)*(uint *)(lVar11 + lVar21 * 0x58 + 0x30));
    }
    if (((ulong)puVar10[(*(ulong *)(param_1 + 8) >> 6) + 99] >> (*(ulong *)(param_1 + 8) & 0x3f) & 1
        ) != 0) {
      msm_gpio_update_dual_edge_pos(puVar10,lVar22);
    }
    _raw_spin_unlock_irqrestore((long)puVar10 + 0x314,uVar12);
LAB_001047f8:
    if ((param_2 & 0xc) == 0) {
      if ((param_2 & 3) == 0) goto LAB_00104828;
      lVar11 = *(long *)(param_1 + 0x10);
      puVar16 = &handle_edge_irq;
    }
    else {
      lVar11 = *(long *)(param_1 + 0x10);
      puVar16 = &handle_level_irq;
    }
  }
  else {
    puVar20 = puVar10 + (uVar15 >> 6 & 0x3ffffff) + 99;
    Hint_Prefetch(puVar20,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar20,0x10);
      if (bVar4) {
        *puVar20 = *puVar20 & (uVar13 ^ 0xffffffffffffffff);
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar11 = *(long *)(param_1 + 0x10);
    puVar16 = &handle_fasteoi_irq;
  }
  *(undefined **)(lVar11 + 0x70) = puVar16;
LAB_00104828:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_gpio_irq_set_wake @ 001048e0 size=108
// signature: undefined msm_gpio_irq_set_wake(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_set_wake(long param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if ((*(long *)(param_1 + 0x28) == 0) ||
     ((*(ulong *)(lVar1 + (*(ulong *)(param_1 + 8) >> 6) * 8 + 0x368) >>
       (*(ulong *)(param_1 + 8) & 0x3f) & 1) == 0)) {
    irq_set_irq_wake(*(undefined4 *)(lVar1 + 0x308),param_2);
  }
  else {
    irq_chip_set_wake_parent(param_1,param_2);
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_reqres @ 00104950 size=384
// signature: undefined msm_gpio_irq_reqres(void)
// callers: []
//------------------------------------------------------------

int msm_gpio_irq_reqres(long param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  undefined8 uVar7;
  
  lVar6 = *(long *)(param_1 + 0x30);
  lVar3 = gpiochip_get_data(lVar6);
  uVar4 = try_module_get(*(undefined8 *)(lVar6 + 0x20));
  if ((uVar4 & 1) == 0) {
    return -0x13;
  }
  uVar7 = *(undefined8 *)(lVar3 + 8);
  uVar2 = *(uint *)(param_1 + 8);
  lVar3 = pinctrl_dev_get_drvdata(uVar7);
  lVar5 = *(long *)(*(long *)(lVar3 + 0x3e0) + 0x20);
  if (*(int *)(lVar5 + (ulong)uVar2 * 0x58 + 0x20) != 0) {
    iVar1 = msm_pinmux_set_mux(uVar7,*(undefined4 *)
                                      (*(long *)(lVar5 + (ulong)uVar2 * 0x58 + 0x18) +
                                      (ulong)*(uint *)(*(long *)(lVar3 + 0x3e0) + 0x6c) * 4),uVar2);
    if (iVar1 != 0) goto LAB_001049dc;
  }
  uVar2 = *(uint *)(param_1 + 8);
  lVar3 = gpiochip_get_data(lVar6);
  lVar5 = *(long *)(*(long *)(lVar3 + 0x3e0) + 0x20);
  uVar7 = _raw_spin_lock_irqsave(lVar3 + 0x314);
  lVar5 = lVar5 + (ulong)uVar2 * 0x58;
  uVar2 = readl(*(long *)(lVar3 + 1000 + (*(ulong *)(lVar5 + 0x3c) >> 5 & 3) * 8) +
                (ulong)*(uint *)(lVar5 + 0x24));
  writel(uVar2 & (1 << (ulong)((uint)(*(ulong *)(lVar5 + 0x3c) >> 0x25) & 0x1f) ^ 0xffffffffU),
         *(long *)(lVar3 + 1000 + (*(ulong *)(lVar5 + 0x3c) >> 5 & 3) * 8) +
         (ulong)*(uint *)(lVar5 + 0x24));
  _raw_spin_unlock_irqrestore(lVar3 + 0x314,uVar7);
  iVar1 = gpiochip_lock_as_irq(lVar6,*(undefined4 *)(param_1 + 8));
  if (iVar1 == 0) {
    irq_modify_status(*(undefined4 *)(param_1 + 4),0,0x80000);
    return 0;
  }
  _dev_err(*(undefined8 *)(lVar6 + 0x10),"unable to lock HW IRQ %lu for IRQ\n",
           *(undefined8 *)(param_1 + 8));
  iVar1 = -0x16;
LAB_001049dc:
  module_put(*(undefined8 *)(lVar6 + 0x20));
  return iVar1;
}



//------------------------------------------------------------
// msm_gpio_irq_relres @ 00104ad4 size=56
// signature: undefined msm_gpio_irq_relres(void)
// callers: []
//------------------------------------------------------------

void msm_gpio_irq_relres(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x30);
  gpiochip_unlock_as_irq(lVar1,*(undefined4 *)(param_1 + 8));
  module_put(*(undefined8 *)(lVar1 + 0x20));
  return;
}



//------------------------------------------------------------
// msm_gpio_irq_get_irqchip_state @ 00104b10 size=156
// signature: undefined msm_gpio_irq_get_irqchip_state(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_irq_get_irqchip_state(long param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar2 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if ((param_2 == 0) &&
     (uVar4 = *(ulong *)(param_1 + 8),
     (*(ulong *)(lVar2 + (uVar4 >> 6) * 8 + 0x368) >> (uVar4 & 0x3f) & 1) == 0)) {
    lVar5 = *(long *)(*(long *)(lVar2 + 0x3e0) + 0x20) + uVar4 * 0x58;
    iVar1 = readl(*(long *)(lVar2 + (*(ulong *)(lVar5 + 0x3c) >> 5 & 3) * 8 + 1000) +
                  (ulong)*(uint *)(lVar5 + 0x30));
    uVar3 = 0;
    *(bool *)param_3 = iVar1 != 0;
  }
  else {
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_gpio_irq_set_irqchip_state @ 00104bb0 size=148
// signature: undefined msm_gpio_irq_set_irqchip_state(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_irq_set_irqchip_state(long param_1,int param_2,uint param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar1 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if (param_2 == 0) {
    uVar2 = *(ulong *)(param_1 + 8);
    if ((*(ulong *)(lVar1 + (uVar2 >> 6) * 8 + 0x368) >> (uVar2 & 0x3f) & 1) == 0) {
      lVar3 = *(long *)(*(long *)(lVar1 + 0x3e0) + 0x20) + uVar2 * 0x58;
      writel(param_3 & 1,
             *(long *)(lVar1 + (*(ulong *)(lVar3 + 0x3c) >> 5 & 3) * 8 + 1000) +
             (ulong)*(uint *)(lVar3 + 0x30));
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_gpio_irq_set_vcpu_affinity @ 00104c48 size=100
// signature: undefined msm_gpio_irq_set_vcpu_affinity(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_gpio_irq_set_vcpu_affinity(long param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  if ((*(long *)(param_1 + 0x28) == 0) ||
     ((*(ulong *)(lVar1 + (*(ulong *)(param_1 + 8) >> 6) * 8 + 0x368) >>
       (*(ulong *)(param_1 + 8) & 0x3f) & 1) == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = irq_chip_set_vcpu_affinity_parent(param_1,param_2);
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_gpio_update_dual_edge_parent @ 00104cac size=296
// signature: undefined msm_gpio_update_dual_edge_parent(void)
// callers: [msm_gpio_irq_ack, msm_gpio_irq_set_type]
//------------------------------------------------------------

void msm_gpio_update_dual_edge_parent(long param_1)

{
  bool bVar1;
  uint uVar2;
  undefined8 *puVar3;
  long lVar4;
  ulong *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  
  puVar3 = (undefined8 *)gpiochip_get_data(*(undefined8 *)(param_1 + 0x30));
  lVar4 = *(long *)(puVar3[0x7c] + 0x20) + *(long *)(param_1 + 8) * 0x58;
  puVar5 = (ulong *)(lVar4 + 0x3c);
  puVar6 = (uint *)(lVar4 + 0x28);
  uVar2 = readl(puVar3[(*puVar5 >> 5 & 3) + 0x7d] + (ulong)*puVar6);
  iVar8 = -0x65;
  iVar7 = 1;
  if ((uVar2 & 1 << (ulong)((uint)(*puVar5 >> 0x2a) & 0x1f)) != 0) {
    iVar7 = 2;
  }
  do {
    irq_chip_set_type_parent(param_1,iVar7);
    uVar2 = readl(puVar3[(*puVar5 >> 5 & 3) + 0x7d] + (ulong)*puVar6);
    uVar2 = uVar2 & 1 << (ulong)((uint)(*puVar5 >> 0x2a) & 0x1f);
    if (iVar7 == 2) {
      if (uVar2 != 0) {
        return;
      }
      iVar7 = 1;
    }
    else if (iVar7 == 1) {
      if (uVar2 == 0) {
        return;
      }
      iVar7 = 2;
    }
    bVar1 = iVar8 != -1;
    iVar8 = iVar8 + 1;
  } while (bVar1);
  if ((msm_gpio_update_dual_edge_parent___print_once & 1) == 0) {
    msm_gpio_update_dual_edge_parent___print_once = 1;
    _dev_warn(*puVar3,"dual-edge irq failed to stabilize\n");
  }
  return;
}



//------------------------------------------------------------
// msm_gpio_update_dual_edge_pos @ 00104dd4 size=284
// signature: undefined msm_gpio_update_dual_edge_pos(void)
// callers: [msm_gpio_irq_ack, msm_gpio_irq_set_type]
//------------------------------------------------------------

void msm_gpio_update_dual_edge_pos(undefined8 *param_1,long param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  
  iVar5 = -0x65;
  while( true ) {
    uVar2 = readl(param_1[(*(ulong *)(param_2 + 0x3c) >> 5 & 3) + 0x7d] +
                  (ulong)*(uint *)(param_2 + 0x28));
    uVar6 = *(ulong *)(param_2 + 0x3c);
    uVar3 = readl(param_1[(uVar6 >> 5 & 3) + 0x7d] + (ulong)*(uint *)(param_2 + 0x2c));
    writel(1 << (ulong)(*(uint *)(param_2 + 0x48) & 0x1f) ^ uVar3,
           param_1[(*(ulong *)(param_2 + 0x3c) >> 5 & 3) + 0x7d] + (ulong)*(uint *)(param_2 + 0x2c))
    ;
    uVar3 = readl(param_1[(*(ulong *)(param_2 + 0x3c) >> 5 & 3) + 0x7d] +
                  (ulong)*(uint *)(param_2 + 0x28));
    uVar7 = *(ulong *)(param_2 + 0x3c);
    iVar4 = readl(param_1[(uVar7 >> 5 & 3) + 0x7d] + (ulong)*(uint *)(param_2 + 0x30));
    if (iVar4 != 0) {
      return;
    }
    if ((uVar2 & 1 << (ulong)((uint)(uVar6 >> 0x2a) & 0x1f)) ==
        (uVar3 & 1 << (ulong)((uint)(uVar7 >> 0x2a) & 0x1f))) break;
    bVar1 = iVar5 == -1;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      _dev_err(*param_1,"dual-edge irq failed to stabilize, %#08x != %#08x\n");
      return;
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pinctrl_hibernation_suspend @ 00104ef4 size=912
// signature: undefined msm_pinctrl_hibernation_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_pinctrl_hibernation_suspend(void)

{
  ulong *puVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  lVar2 = msm_pinctrl_data;
  if (*(char *)(msm_pinctrl_data + 0x428) != '\0') {
    lVar7 = *(long *)(msm_pinctrl_data + 0x3e0);
    lVar5 = __kmalloc((ulong)*(uint *)(lVar7 + 0x28) << 4,0xdc0);
    *(long *)(lVar2 + 0x418) = lVar5;
    if (lVar5 == 0) {
      return 0xfffffff4;
    }
    if (*(uint *)(lVar7 + 0x40) != 0) {
      lVar5 = __kmalloc((ulong)*(uint *)(lVar7 + 0x40) << 5,0xdc0);
      *(long *)(lVar2 + 0x420) = lVar5;
      if (lVar5 == 0) {
        kfree(*(undefined8 *)(lVar2 + 0x418));
        return 0xfffffff4;
      }
      if (*(int *)(lVar7 + 0x40) != 0) {
        lVar5 = 0;
        uVar9 = 0;
        do {
          plVar6 = (long *)(lVar2 + 1000);
          if (*(long *)(lVar7 + 0x38) != 0) {
            if (3 < uVar9) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105284);
              (*pcVar3)();
            }
            plVar6 = (long *)(lVar2 + 1000 + lVar5);
          }
          lVar10 = *plVar6 + (ulong)*(uint *)(*(long *)(lVar7 + 0x78) + uVar9 * 4);
          _printk(&DAT_00105fa9,lVar10);
          uVar4 = readl_relaxed(lVar10);
          lVar11 = lVar5 * 4;
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 4);
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 4) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 8);
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 8) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 0xc);
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 0xc) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 0x10);
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 0x10) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 0x14);
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 0x14) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 0x18);
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 0x18) = uVar4;
          uVar4 = readl_relaxed(lVar10 + 0x1c);
          uVar9 = uVar9 + 1;
          lVar5 = lVar5 + 8;
          *(undefined4 *)(*(long *)(lVar2 + 0x420) + lVar11 + 0x1c) = uVar4;
        } while (uVar9 < *(uint *)(lVar7 + 0x40));
      }
    }
    if (*(int *)(lVar7 + 0x2c) == 0) {
      uVar9 = 0;
    }
    else {
      lVar5 = 0;
      uVar9 = 0;
      lVar10 = 0x3c;
      do {
        if ((lVar2 != -0x10) ||
           ((*(ulong *)(_DAT_00000250 + (uVar9 >> 3 & 0x1ffffffffffffff8)) >> (uVar9 & 0x3f) & 1) !=
            0)) {
          lVar11 = *(long *)(lVar7 + 0x20);
          puVar1 = (ulong *)(lVar11 + lVar10);
          uVar4 = readl(*(long *)(lVar2 + 1000 + (*puVar1 >> 5 & 3) * 8) + (ulong)(uint)puVar1[-3]);
          *(undefined4 *)(*(long *)(lVar2 + 0x418) + lVar5) = uVar4;
          uVar4 = readl(*(long *)(lVar2 + 1000 + (*puVar1 >> 5 & 3) * 8) +
                        (ulong)*(uint *)((long)puVar1 + -0x14));
          *(undefined4 *)(*(long *)(lVar2 + 0x418) + lVar5 + 4) = uVar4;
          if ((uint)puVar1[-2] != 0) {
            uVar4 = readl(*(long *)(lVar2 + (*(ulong *)(lVar11 + lVar10) >> 5 & 3) * 8 + 1000) +
                          (ulong)(uint)puVar1[-2]);
            *(undefined4 *)(*(long *)(lVar2 + 0x418) + lVar5 + 8) = uVar4;
          }
          if (*(uint *)((long)puVar1 + -0xc) != 0) {
            uVar4 = readl(*(long *)(lVar2 + (*(ulong *)(lVar11 + lVar10) >> 5 & 3) * 8 + 1000) +
                          (ulong)*(uint *)((long)puVar1 + -0xc));
            *(undefined4 *)(*(long *)(lVar2 + 0x418) + lVar5 + 0xc) = uVar4;
          }
        }
        uVar9 = uVar9 + 1;
        lVar5 = lVar5 + 0x10;
        lVar10 = lVar10 + 0x58;
      } while (uVar9 < *(uint *)(lVar7 + 0x2c));
    }
    if ((uint)uVar9 < *(uint *)(lVar7 + 0x28)) {
      uVar8 = uVar9 & 0xffffffff;
      lVar10 = (uVar9 & 0xffffffff) * 0x58;
      lVar5 = (uVar9 & 0xffffffff) << 4;
      do {
        if ((lVar2 != -0x10) ||
           ((*(ulong *)(_DAT_00000250 + (uVar8 >> 3 & 0x1ffffffffffffff8)) >> (uVar8 & 0x3f) & 1) !=
            0)) {
          lVar12 = *(long *)(lVar7 + 0x20);
          lVar11 = lVar12 + lVar10;
          if (*(uint *)(lVar11 + 0x24) != 0) {
            uVar4 = readl(*(long *)(lVar2 + (*(ulong *)(lVar11 + 0x3c) >> 5 & 3) * 8 + 1000) +
                          (ulong)*(uint *)(lVar11 + 0x24));
            *(undefined4 *)(*(long *)(lVar2 + 0x418) + lVar5) = uVar4;
          }
          if (*(uint *)(lVar11 + 0x28) != 0) {
            uVar4 = readl(*(long *)(lVar2 + (*(ulong *)(lVar12 + lVar10 + 0x3c) >> 5 & 3) * 8 + 1000
                                   ) + (ulong)*(uint *)(lVar11 + 0x28));
            *(undefined4 *)(*(long *)(lVar2 + 0x418) + lVar5 + 4) = uVar4;
          }
        }
        uVar8 = uVar8 + 1;
        lVar5 = lVar5 + 0x10;
        lVar10 = lVar10 + 0x58;
      } while (uVar8 < *(uint *)(lVar7 + 0x28));
      return 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_pinctrl_hibernation_resume @ 00105288 size=844
// signature: undefined msm_pinctrl_hibernation_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_pinctrl_hibernation_resume(void)

{
  long *plVar1;
  ulong *puVar2;
  long lVar3;
  code *pcVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  
  lVar3 = msm_pinctrl_data;
  if ((*(char *)(msm_pinctrl_data + 0x428) != '\0') && (*(long *)(msm_pinctrl_data + 0x418) != 0)) {
    lVar6 = *(long *)(msm_pinctrl_data + 0x3e0);
    if (*(int *)(lVar6 + 0x40) != 0) {
      if (*(long *)(msm_pinctrl_data + 0x420) == 0) {
        return;
      }
      lVar7 = 0;
      uVar8 = 0;
      plVar1 = (long *)(msm_pinctrl_data + 1000);
      do {
        plVar5 = plVar1;
        if (*(long *)(lVar6 + 0x38) != 0) {
          if (3 < uVar8) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1055d4);
            (*pcVar4)();
          }
          plVar5 = (long *)((long)plVar1 + lVar7);
        }
        lVar9 = *plVar5 + (ulong)*(uint *)(*(long *)(lVar6 + 0x78) + uVar8 * 4);
        _printk(&DAT_00105fa9,lVar9);
        lVar11 = lVar7 * 4;
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11),lVar9);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 4),lVar9 + 4);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 8),lVar9 + 8);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 0xc),lVar9 + 0xc);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 0x10),lVar9 + 0x10);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 0x14),lVar9 + 0x14);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 0x18),lVar9 + 0x18);
        writel_relaxed(*(undefined4 *)(*(long *)(lVar3 + 0x420) + lVar11 + 0x1c),lVar9 + 0x1c);
        uVar8 = uVar8 + 1;
        lVar7 = lVar7 + 8;
      } while (uVar8 < *(uint *)(lVar6 + 0x40));
    }
    if (*(int *)(lVar6 + 0x2c) == 0) {
      uVar8 = 0;
    }
    else {
      lVar7 = 0;
      uVar8 = 0;
      lVar9 = 0x3c;
      do {
        if ((lVar3 != -0x10) ||
           ((*(ulong *)(_DAT_00000250 + (uVar8 >> 3 & 0x1ffffffffffffff8)) >> (uVar8 & 0x3f) & 1) !=
            0)) {
          lVar11 = *(long *)(lVar6 + 0x20);
          puVar2 = (ulong *)(lVar11 + lVar9);
          writel(*(undefined4 *)(*(long *)(lVar3 + 0x418) + lVar7),
                 *(long *)(lVar3 + 1000 + (*puVar2 >> 5 & 3) * 8) + (ulong)(uint)puVar2[-3]);
          writel(*(undefined4 *)(*(long *)(lVar3 + 0x418) + lVar7 + 4),
                 *(long *)(lVar3 + 1000 + (*puVar2 >> 5 & 3) * 8) +
                 (ulong)*(uint *)((long)puVar2 + -0x14));
          if ((uint)puVar2[-2] != 0) {
            writel(*(undefined4 *)(*(long *)(lVar3 + 0x418) + lVar7 + 8),
                   *(long *)(lVar3 + (*(ulong *)(lVar11 + lVar9) >> 5 & 3) * 8 + 1000) +
                   (ulong)(uint)puVar2[-2]);
          }
          if (*(uint *)((long)puVar2 + -0xc) != 0) {
            writel(*(undefined4 *)(*(long *)(lVar3 + 0x418) + lVar7 + 0xc),
                   *(long *)(lVar3 + (*(ulong *)(lVar11 + lVar9) >> 5 & 3) * 8 + 1000) +
                   (ulong)*(uint *)((long)puVar2 + -0xc));
          }
        }
        uVar8 = uVar8 + 1;
        lVar7 = lVar7 + 0x10;
        lVar9 = lVar9 + 0x58;
      } while (uVar8 < *(uint *)(lVar6 + 0x2c));
    }
    if ((uint)uVar8 < *(uint *)(lVar6 + 0x28)) {
      uVar10 = uVar8 & 0xffffffff;
      lVar9 = (uVar8 & 0xffffffff) * 0x58;
      lVar7 = (uVar8 & 0xffffffff) << 4;
      do {
        if ((lVar3 != -0x10) ||
           ((*(ulong *)(_DAT_00000250 + (uVar10 >> 3 & 0x1ffffffffffffff8)) >> (uVar10 & 0x3f) & 1)
            != 0)) {
          lVar12 = *(long *)(lVar6 + 0x20);
          lVar11 = lVar12 + lVar9;
          if (*(uint *)(lVar11 + 0x24) != 0) {
            writel(*(undefined4 *)(*(long *)(lVar3 + 0x418) + lVar7),
                   *(long *)(lVar3 + (*(ulong *)(lVar11 + 0x3c) >> 5 & 3) * 8 + 1000) +
                   (ulong)*(uint *)(lVar11 + 0x24));
          }
          if (*(uint *)(lVar11 + 0x28) != 0) {
            writel(*(undefined4 *)(*(long *)(lVar3 + 0x418) + lVar7 + 4),
                   *(long *)(lVar3 + (*(ulong *)(lVar12 + lVar9 + 0x3c) >> 5 & 3) * 8 + 1000) +
                   (ulong)*(uint *)(lVar11 + 0x28));
          }
        }
        uVar10 = uVar10 + 1;
        lVar7 = lVar7 + 0x10;
        lVar9 = lVar9 + 0x58;
      } while (uVar10 < *(uint *)(lVar6 + 0x28));
    }
    kfree(*(undefined8 *)(lVar3 + 0x418));
    kfree(*(undefined8 *)(lVar3 + 0x420));
    *(undefined8 *)(lVar3 + 0x418) = 0;
    *(undefined8 *)(lVar3 + 0x420) = 0;
  }
  return;
}



//------------------------------------------------------------
// pinctrl_hibernation_notifier @ 001055d8 size=48
// signature: undefined pinctrl_hibernation_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 pinctrl_hibernation_notifier(undefined8 param_1,long param_2)

{
  undefined1 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 1;
  }
  else {
    if (param_2 != 2) {
      return 1;
    }
    uVar1 = 0;
  }
  *(undefined1 *)(msm_pinctrl_data + 0x428) = uVar1;
  return 1;
}



//------------------------------------------------------------
// pinctrl_force_sleep @ 00108000 size=1
// signature: undefined pinctrl_force_sleep(void)
// callers: [msm_pinctrl_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_force_sleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_force_default @ 00108008 size=1
// signature: undefined pinctrl_force_default(void)
// callers: [msm_pinctrl_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_force_default(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk_deferred @ 00108010 size=1
// signature: undefined _printk_deferred(void)
// callers: [noirq_msm_pinctrl_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk_deferred(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_get_data @ 00108018 size=1
// signature: undefined gpiochip_get_data(void)
// callers: [msm_gpio_get, msm_gpio_irq_reqres, msm_gpio_dbg_show, msm_gpio_irq_unmask, msm_gpio_irq_disable, msm_gpio_irq_set_vcpu_affinity, msm_gpio_irq_set_affinity, noirq_msm_pinctrl_suspend, msm_gpio_irq_set_irqchip_state, msm_gpio_update_dual_edge_parent, msm_gpio_direction_output, msm_gpio_irq_mask, msm_gpio_init_valid_mask, msm_gpio_irq_ack, msm_gpio_irq_set_type, msm_gpio_irq_enable, msm_gpio_irq_init_valid_mask, msm_pinctrl_probe, msm_gpio_direction_input, msm_gpio_irq_handler, msm_gpio_irq_get_irqchip_state, msm_gpio_set, msm_gpio_wakeirq, msm_gpio_get_direction, msm_gpio_irq_set_wake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_get_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_line_is_valid @ 00108020 size=1
// signature: undefined gpiochip_line_is_valid(void)
// callers: [noirq_msm_pinctrl_suspend, msm_pinmux_request, msm_config_group_get, msm_gpio_dbg_show, msm_gpio_get_pin_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_line_is_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [noirq_msm_pinctrl_suspend, msm_pinmux_set_mux, msm_gpio_init_valid_mask, msm_gpio_dbg_show, msm_gpio_irq_set_type, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00108030 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [msm_gpio_mpm_wake_set, msm_pinmux_set_mux, msm_gpio_irq_ack, msm_gpio_irq_reqres, msm_gpio_irq_unmask, msm_gpio_irq_set_type, msm_gpio_direction_output, msm_pinctrl_probe, msm_gpio_irq_mask, msm_gpio_direction_input, msm_config_group_set, msm_gpio_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00108038 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [msm_gpio_mpm_wake_set, msm_pinmux_set_mux, msm_gpio_irq_ack, msm_gpio_irq_reqres, msm_gpio_irq_unmask, msm_gpio_irq_set_type, msm_gpio_direction_output, msm_pinctrl_probe, msm_gpio_irq_mask, msm_gpio_direction_input, msm_config_group_set, msm_gpio_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00108040 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00108048 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00108050 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00108058 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00108060 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_pinctrl_probe, msm_gpio_get_pin_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00108068 size=1
// signature: undefined platform_get_resource(void)
// callers: [msm_pinctrl_probe, msm_gpio_get_pin_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00108070 size=1
// signature: undefined _dev_err(void)
// callers: [msm_gpio_init_valid_mask, msm_gpio_irq_reqres, msm_gpio_irq_set_type, msm_gpio_update_dual_edge_pos, msm_pinctrl_probe, msm_config_group_set, msm_gpio_get_pin_address]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00108078 size=1
// signature: undefined _printk(void)
// callers: [msm_pinctrl_hibernation_suspend, msm_gpio_get_pin_address, msm_pinctrl_hibernation_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00108080 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00108088 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00108090 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00108098 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001080a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_restart_handler @ 001080a8 size=1
// signature: undefined register_restart_handler(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 001080b8 size=1
// signature: undefined platform_get_irq(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_register @ 001080c0 size=1
// signature: undefined devm_pinctrl_register(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001080c8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_find_matching_fwspec @ 001080d0 size=1
// signature: undefined irq_find_matching_fwspec(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_find_matching_fwspec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// handle_bad_irq @ 001080e0 size=1
// signature: undefined handle_bad_irq(void)
// callers: [msm_gpio_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void handle_bad_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_data_with_key @ 001080e8 size=1
// signature: undefined gpiochip_add_data_with_key(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_data_with_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001080f0 size=1
// signature: undefined of_find_property(void)
// callers: [msm_gpio_init_valid_mask, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_pin_range @ 001080f8 size=1
// signature: undefined gpiochip_add_pin_range(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_pin_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_irq_count @ 00108100 size=1
// signature: undefined platform_irq_count(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_irq_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_set_handler @ 00108108 size=1
// signature: undefined __irq_set_handler(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_set_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_type @ 00108110 size=1
// signature: undefined irq_set_irq_type(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_type(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00108118 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [msm_gpio_init_valid_mask, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_read_u16_array @ 00108120 size=1
// signature: undefined device_property_read_u16_array(void)
// callers: [msm_gpio_init_valid_mask, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_u16_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_create_mapping_affinity @ 00108128 size=1
// signature: undefined irq_create_mapping_affinity(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_create_mapping_affinity(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_parent @ 00108130 size=1
// signature: undefined irq_set_parent(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_data @ 00108138 size=1
// signature: undefined irq_set_chip_data(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_and_handler_name @ 00108140 size=1
// signature: undefined irq_set_chip_and_handler_name(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_and_handler_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irq_data @ 00108148 size=1
// signature: undefined irq_get_irq_data(void)
// callers: [msm_gpio_irq_set_affinity, msm_pinmux_set_mux, msm_gpio_irq_set_type, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_handler_data @ 00108150 size=1
// signature: undefined irq_set_handler_data(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_handler_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_syscore_ops @ 00108158 size=1
// signature: undefined register_syscore_ops(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00108160 size=1
// signature: undefined register_pm_notifier(void)
// callers: [msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00108168 size=1
// signature: undefined _dev_warn(void)
// callers: [msm_gpio_update_dual_edge_parent, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_remove @ 00108170 size=1
// signature: undefined gpiochip_remove(void)
// callers: [msm_pinctrl_remove, msm_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// generic_handle_irq @ 00108178 size=1
// signature: undefined generic_handle_irq(void)
// callers: [msm_gpio_dirconn_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void generic_handle_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irqchip_state @ 00108180 size=1
// signature: undefined irq_set_irqchip_state(void)
// callers: [msm_gpio_dirconn_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irqchip_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_restart_handler @ 00108188 size=1
// signature: undefined unregister_restart_handler(void)
// callers: [msm_pinctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00108190 size=1
// signature: undefined seq_printf(void)
// callers: [msm_gpio_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00108198 size=1
// signature: undefined seq_puts(void)
// callers: [msm_gpio_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001081a0 size=1
// signature: undefined __const_udelay(void)
// callers: [msm_ps_hold_restart, msm_ps_hold_poweroff]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_dev_get_drvdata @ 001081a8 size=1
// signature: undefined pinctrl_dev_get_drvdata(void)
// callers: [msm_get_functions_count, msm_get_groups_count, msm_pinmux_request_gpio, msm_pinmux_request, msm_pinmux_set_mux, msm_config_group_get, msm_gpio_irq_reqres, msm_get_group_name, msm_get_group_pins, msm_get_function_name, msm_get_function_groups, msm_config_group_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_dev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map @ 001081b0 size=1
// signature: undefined pinconf_generic_dt_node_to_map(void)
// callers: [pinconf_generic_dt_node_to_map_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinconf_generic_dt_node_to_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 001081b8 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [msm_pinmux_set_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001081c0 size=1
// signature: undefined disable_irq(void)
// callers: [msm_pinmux_set_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_parent_state @ 001081c8 size=1
// signature: undefined irq_chip_set_parent_state(void)
// callers: [msm_pinmux_set_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_parent_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 001081d0 size=1
// signature: undefined enable_irq(void)
// callers: [msm_pinmux_set_mux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001081d8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [msm_gpio_init_valid_mask, msm_gpio_irq_init_valid_mask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_prop_next_u32 @ 001081e0 size=1
// signature: undefined of_prop_next_u32(void)
// callers: [msm_gpio_init_valid_mask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_prop_next_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001081e8 size=1
// signature: undefined __kmalloc(void)
// callers: [msm_gpio_init_valid_mask, msm_pinctrl_hibernation_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001081f0 size=1
// signature: undefined kfree(void)
// callers: [msm_gpio_init_valid_mask, msm_pinctrl_hibernation_suspend, msm_pinctrl_hibernation_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 001081f8 size=1
// signature: undefined _find_next_bit(void)
// callers: [msm_gpio_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// generic_handle_domain_irq @ 00108200 size=1
// signature: undefined generic_handle_domain_irq(void)
// callers: [msm_gpio_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void generic_handle_domain_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_enable_irq @ 00108208 size=1
// signature: undefined gpiochip_enable_irq(void)
// callers: [msm_gpio_irq_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_enable_parent @ 00108210 size=1
// signature: undefined irq_chip_enable_parent(void)
// callers: [msm_gpio_irq_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_enable_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_disable_parent @ 00108218 size=1
// signature: undefined irq_chip_disable_parent(void)
// callers: [msm_gpio_irq_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_disable_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_disable_irq @ 00108220 size=1
// signature: undefined gpiochip_disable_irq(void)
// callers: [msm_gpio_irq_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_mask_parent @ 00108228 size=1
// signature: undefined irq_chip_mask_parent(void)
// callers: [msm_gpio_irq_mask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_mask_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_unmask_parent @ 00108230 size=1
// signature: undefined irq_chip_unmask_parent(void)
// callers: [msm_gpio_irq_unmask]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_unmask_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_affinity_parent @ 00108238 size=1
// signature: undefined irq_chip_set_affinity_parent(void)
// callers: [msm_gpio_irq_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_affinity_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_type_parent @ 00108248 size=1
// signature: undefined irq_chip_set_type_parent(void)
// callers: [msm_gpio_irq_set_type, msm_gpio_update_dual_edge_parent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_type_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 00108258 size=1
// signature: undefined qcom_scm_io_readl(void)
// callers: [msm_gpio_irq_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_readl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 00108260 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [msm_gpio_irq_set_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_wake_parent @ 00108278 size=1
// signature: undefined irq_chip_set_wake_parent(void)
// callers: [msm_gpio_irq_set_wake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_wake_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00108280 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [msm_gpio_irq_set_wake]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_module_get @ 00108288 size=1
// signature: undefined try_module_get(void)
// callers: [msm_gpio_irq_reqres]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 00108290 size=1
// signature: undefined module_put(void)
// callers: [msm_gpio_irq_relres, msm_gpio_irq_reqres]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_lock_as_irq @ 00108298 size=1
// signature: undefined gpiochip_lock_as_irq(void)
// callers: [msm_gpio_irq_reqres]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_lock_as_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 001082a0 size=1
// signature: undefined irq_modify_status(void)
// callers: [msm_gpio_irq_reqres]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_unlock_as_irq @ 001082a8 size=1
// signature: undefined gpiochip_unlock_as_irq(void)
// callers: [msm_gpio_irq_relres]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_unlock_as_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_chip_set_vcpu_affinity_parent @ 001082b0 size=1
// signature: undefined irq_chip_set_vcpu_affinity_parent(void)
// callers: [msm_gpio_irq_set_vcpu_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_chip_set_vcpu_affinity_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



