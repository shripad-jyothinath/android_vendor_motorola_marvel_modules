// Decompiled by Ghidra 12.2
// Program: wcd_core_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd9xxx_lock_sleep @ 00100bac size=8
// signature: undefined wcd9xxx_lock_sleep(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9xxx_lock_sleep(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd9xxx_unlock_sleep @ 00100bb8 size=4
// signature: undefined wcd9xxx_unlock_sleep(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_unlock_sleep(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_nested_irq_lock @ 00100bc0 size=4
// signature: undefined wcd9xxx_nested_irq_lock(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_nested_irq_lock(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_nested_irq_unlock @ 00100bc8 size=4
// signature: undefined wcd9xxx_nested_irq_unlock(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_nested_irq_unlock(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_request_irq @ 00100bd0 size=8
// signature: undefined wcd9xxx_request_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9xxx_request_irq(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd9xxx_free_irq @ 00100bdc size=4
// signature: undefined wcd9xxx_free_irq(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_free_irq(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_enable_irq @ 00100be4 size=4
// signature: undefined wcd9xxx_enable_irq(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_enable_irq(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_disable_irq @ 00100bec size=4
// signature: undefined wcd9xxx_disable_irq(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_disable_irq(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_disable_irq_sync @ 00100bf4 size=4
// signature: undefined wcd9xxx_disable_irq_sync(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_disable_irq_sync(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_irq_init @ 00100bfc size=8
// signature: undefined wcd9xxx_irq_init(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9xxx_irq_init(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd9xxx_irq_exit @ 00100c08 size=4
// signature: undefined wcd9xxx_irq_exit(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_irq_exit(void)

{
  return;
}



//------------------------------------------------------------
// wcd9xxx_irq_drv_init @ 00100c10 size=8
// signature: undefined wcd9xxx_irq_drv_init(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd9xxx_irq_drv_init(void)

{
  return 0;
}



//------------------------------------------------------------
// wcd9xxx_irq_drv_exit @ 00100c1c size=4
// signature: undefined wcd9xxx_irq_drv_exit(void)
// callers: []
//------------------------------------------------------------

void wcd9xxx_irq_drv_exit(void)

{
  return;
}



//------------------------------------------------------------
// msm_cdc_get_gpio_state @ 00100c24 size=60
// signature: undefined msm_cdc_get_gpio_state(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_get_gpio_state(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = msm_cdc_pinctrl_get_gpiodata();
  if ((lVar1 == 0) || (0x1ff < *(uint *)(lVar1 + 0x20))) {
    uVar2 = 0xffffffea;
  }
  else {
    gpio_to_desc();
    uVar2 = gpiod_get_raw_value_cansleep();
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_gpiodata @ 00100c60 size=196
// signature: undefined msm_cdc_pinctrl_get_gpiodata(void)
// callers: [msm_cdc_pinctrl_set_wakeup_capable, msm_cdc_get_gpio_state, msm_cdc_pinctrl_select_active_state, msm_cdc_pinctrl_get_state, msm_cdc_pinctrl_select_sleep_state, msm_cdc_pinctrl_select_alt_active_state]
//------------------------------------------------------------

long msm_cdc_pinctrl_get_gpiodata(long param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(msm_cdc_pinctrl_get_gpiodata__rs,"msm_cdc_pinctrl_get_gpiodata");
    if (iVar1 == 0) {
      return 0;
    }
    puVar3 = &DAT_00103862;
  }
  else {
    lVar2 = of_find_device_by_node();
    if (lVar2 != 0) {
      if (*(long *)(lVar2 + 0xa8) != 0) {
        return *(long *)(lVar2 + 0xa8);
      }
      iVar1 = ___ratelimit(msm_cdc_pinctrl_get_gpiodata__rs_6,"msm_cdc_pinctrl_get_gpiodata");
      if (iVar1 == 0) {
        return 0;
      }
      _dev_err(lVar2 + 0x10,"%s: cannot find cdc gpio info\n","msm_cdc_pinctrl_get_gpiodata");
      return 0;
    }
    iVar1 = ___ratelimit(msm_cdc_pinctrl_get_gpiodata__rs_4,"msm_cdc_pinctrl_get_gpiodata");
    if (iVar1 == 0) {
      return 0;
    }
    puVar3 = &DAT_00103a6c;
  }
  _printk(puVar3,"msm_cdc_pinctrl_get_gpiodata");
  return 0;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_sleep_state @ 00100d28 size=112
// signature: undefined msm_cdc_pinctrl_select_sleep_state(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_pinctrl_select_sleep_state(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)msm_cdc_pinctrl_get_gpiodata();
  if (puVar2 != (undefined8 *)0x0) {
    if (puVar2[2] != 0) {
      *(undefined1 *)((long)puVar2 + 0x24) = 0;
      uVar3 = pinctrl_select_state(*puVar2);
      return uVar3;
    }
    iVar1 = ___ratelimit(&msm_cdc_pinctrl_select_sleep_state__rs,
                         "msm_cdc_pinctrl_select_sleep_state");
    if (iVar1 != 0) {
      _printk(&DAT_00103739,"msm_cdc_pinctrl_select_sleep_state");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_alt_active_state @ 00100d9c size=116
// signature: undefined msm_cdc_pinctrl_select_alt_active_state(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_pinctrl_select_alt_active_state(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)msm_cdc_pinctrl_get_gpiodata();
  if (puVar2 != (undefined8 *)0x0) {
    if (puVar2[3] != 0) {
      *(undefined1 *)((long)puVar2 + 0x24) = 1;
      uVar3 = pinctrl_select_state(*puVar2);
      return uVar3;
    }
    iVar1 = ___ratelimit(msm_cdc_pinctrl_select_alt_active_state__rs,
                         "msm_cdc_pinctrl_select_alt_active_state");
    if (iVar1 != 0) {
      _printk(&DAT_00103ac9,"msm_cdc_pinctrl_select_alt_active_state");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_select_active_state @ 00100e14 size=116
// signature: undefined msm_cdc_pinctrl_select_active_state(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_pinctrl_select_active_state(void)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  puVar2 = (undefined8 *)msm_cdc_pinctrl_get_gpiodata();
  if (puVar2 != (undefined8 *)0x0) {
    if (puVar2[1] != 0) {
      *(undefined1 *)((long)puVar2 + 0x24) = 1;
      uVar3 = pinctrl_select_state(*puVar2);
      return uVar3;
    }
    iVar1 = ___ratelimit(msm_cdc_pinctrl_select_active_state__rs,
                         "msm_cdc_pinctrl_select_active_state");
    if (iVar1 != 0) {
      _printk(&DAT_00103fe7,"msm_cdc_pinctrl_select_active_state");
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_get_state @ 00100e8c size=44
// signature: undefined msm_cdc_pinctrl_get_state(void)
// callers: []
//------------------------------------------------------------

ulong msm_cdc_pinctrl_get_state(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = msm_cdc_pinctrl_get_gpiodata();
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = (ulong)*(byte *)(lVar1 + 0x24);
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_set_wakeup_capable @ 00100ebc size=268
// signature: undefined msm_cdc_pinctrl_set_wakeup_capable(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_pinctrl_set_wakeup_capable(undefined8 param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  ulong uVar9;
  
  lVar8 = msm_cdc_pinctrl_get_gpiodata();
  if (lVar8 == 0) {
    iVar6 = -0x16;
  }
  else {
    if ((*(char *)(lVar8 + 0x130) == '\0') || (*(int *)(lVar8 + 0x128) == 0)) {
      iVar6 = 0;
      cVar3 = *(char *)(lVar8 + 0x131);
    }
    else {
      uVar9 = 0;
      do {
        if (uVar9 == 0x10) goto LAB_00100fc4;
        iVar6 = msm_gpio_mpm_wake_set(*(undefined4 *)(lVar8 + 0x28 + uVar9 * 4),param_2 & 1);
        if (iVar6 < 0) {
          return iVar6;
        }
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(lVar8 + 0x128));
      cVar3 = *(char *)(lVar8 + 0x131);
    }
    if ((cVar3 != '\0') && (*(int *)(lVar8 + 300) != 0)) {
      uVar9 = 0;
      do {
        if (uVar9 == 0x10) {
LAB_00100fc4:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100fc8);
          (*pcVar5)();
        }
        lVar1 = lVar8 + 0xe8 + uVar9 * 8;
        uVar7 = readl(*(undefined8 *)(lVar1 + -0x80));
        uVar4 = 1 << (ulong)(*(uint *)(lVar8 + 0xe8 + uVar9 * 4) & 0x1f);
        uVar2 = uVar4 | uVar7;
        if ((param_2 & 1) == 0) {
          uVar2 = uVar7 & (uVar4 ^ 0xffffffff);
        }
        writel(uVar2,*(undefined8 *)(lVar1 + -0x80));
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(lVar8 + 300));
    }
  }
  return iVar6;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_drv_init @ 00100fcc size=44
// signature: undefined msm_cdc_pinctrl_drv_init(void)
// callers: [init_module]
//------------------------------------------------------------

void msm_cdc_pinctrl_drv_init(void)

{
  __platform_driver_register(&msm_cdc_pinctrl_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_drv_exit @ 00100ffc size=36
// signature: undefined msm_cdc_pinctrl_drv_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void msm_cdc_pinctrl_drv_exit(void)

{
  platform_driver_unregister(&msm_cdc_pinctrl_driver);
  return;
}



//------------------------------------------------------------
// readl @ 00101020 size=140
// signature: undefined readl(void)
// callers: [msm_cdc_pinctrl_set_wakeup_capable, msm_cdc_pinctrl_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101078,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 001010ac size=136
// signature: undefined writel(void)
// callers: [msm_cdc_pinctrl_set_wakeup_capable, msm_cdc_pinctrl_probe]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1010c4,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101104,uVar1);
  return;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_probe @ 00101138 size=1348
// signature: undefined msm_cdc_pinctrl_probe(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_pinctrl_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulong *puVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  undefined8 uVar14;
  ulong uVar15;
  ulong *puVar16;
  int local_130 [16];
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar12 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_70 = *(long *)(lVar12 + 0x638);
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_130[0xc] = 0;
  local_130[0xd] = 0;
  local_130[0xe] = 0;
  local_130[0xf] = 0;
  local_130[8] = 0;
  local_130[9] = 0;
  local_130[10] = 0;
  local_130[0xb] = 0;
  local_130[4] = 0;
  local_130[5] = 0;
  local_130[6] = 0;
  local_130[7] = 0;
  local_130[0] = 0;
  local_130[1] = 0;
  local_130[2] = 0;
  local_130[3] = 0;
  _dev_info(lVar1,"%s: enter\n","msm_cdc_pinctrl_probe");
  puVar10 = (ulong *)devm_kmalloc(lVar1,0x138,0xdc0);
  if (puVar10 == (ulong *)0x0) {
    iVar6 = -0xc;
  }
  else {
    uVar11 = devm_pinctrl_get(lVar1);
    *puVar10 = uVar11;
    if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
      _dev_err(lVar1,"%s: Cannot get cdc gpio pinctrl:%ld\n","msm_cdc_pinctrl_probe");
      iVar6 = (int)*puVar10;
    }
    else {
      uVar11 = pinctrl_lookup_state(uVar11,"aud_active");
      puVar10[1] = uVar11;
      if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
        _dev_err(lVar1,"%s: Cannot get aud_active pinctrl state:%ld\n","msm_cdc_pinctrl_probe");
        iVar6 = (int)puVar10[1];
      }
      else {
        uVar11 = pinctrl_lookup_state(*puVar10,"aud_sleep");
        puVar10[2] = uVar11;
        if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
          _dev_err(lVar1,"%s: Cannot get aud_sleep pinctrl state:%ld\n","msm_cdc_pinctrl_probe");
          iVar6 = (int)puVar10[2];
        }
        else {
          uVar11 = pinctrl_lookup_state(*puVar10,"aud_alt_active");
          uVar14 = *(undefined8 *)(param_1 + 0x2f8);
          puVar10[3] = uVar11;
          lVar12 = of_find_property(uVar14,"qcom,lpi-gpios",0);
          if ((lVar12 == 0) && (iVar6 = pinctrl_select_state(*puVar10,puVar10[2]), iVar6 != 0)) {
            _dev_err(lVar1,"%s: set cdc gpio sleep state fail: %d\n","msm_cdc_pinctrl_probe",iVar6);
          }
          uVar7 = of_property_count_elems_of_size
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,chip-wakeup-reg",4);
          if (0 < (int)uVar7) {
            uVar11 = (ulong)uVar7;
            iVar6 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,chip-wakeup-reg",&local_f0,
                               uVar11,0);
            if (-1 < iVar6) {
              iVar6 = of_property_read_variable_u32_array
                                (*(undefined8 *)(param_1 + 0x2f8),"qcom,chip-wakeup-maskbit",
                                 puVar10 + 0x1d,uVar11,0);
              if (iVar6 < 0) {
                _dev_err(lVar1,"chip-wakeup-maskbit needed if chip-wakeup-reg is defined!\n");
              }
              else {
                uVar15 = 0;
                *(undefined1 *)((long)puVar10 + 0x131) = 1;
                do {
                  if (uVar15 == 0x10) goto LAB_00101678;
                  uVar13 = devm_ioremap(lVar1,local_130[uVar15 + 0x10],4);
                  puVar10[uVar15 + 0xd] = uVar13;
                  uVar15 = uVar15 + 1;
                } while (uVar11 != uVar15);
                iVar6 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,chip-wakeup-default-val",
                                   local_130,uVar11,0);
                if (-1 < iVar6) {
                  lVar12 = 0;
                  uVar3 = uVar7;
                  if (uVar7 < 2) {
                    uVar3 = 1;
                  }
                  puVar16 = puVar10 + 0xd;
                  do {
                    if (lVar12 == 0x40) goto LAB_00101678;
                    uVar8 = readl(*puVar16);
                    if (lVar12 == 0x40) {
                    /* WARNING: Does not return */
                      pcVar5 = (code *)SoftwareBreakpoint(1,0x101678);
                      (*pcVar5)();
                    }
                    uVar4 = 1 << (ulong)(*(uint *)((long)puVar10 + lVar12 + 0xe8) & 0x1f);
                    uVar2 = uVar8 & (uVar4 ^ 0xffffffff);
                    if (*(int *)((long)local_130 + lVar12) != 0) {
                      uVar2 = uVar4 | uVar8;
                    }
                    writel(uVar2,*puVar16);
                    lVar12 = lVar12 + 4;
                    puVar16 = puVar16 + 1;
                  } while ((ulong)uVar3 * 4 != lVar12);
                }
                *(uint *)((long)puVar10 + 300) = uVar7;
              }
            }
          }
          iVar6 = of_property_count_elems_of_size
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,tlmm-pins",4);
          if ((0 < iVar6) &&
             (iVar9 = of_property_read_variable_u32_array
                                (*(undefined8 *)(param_1 + 0x2f8),"qcom,tlmm-pins",&local_b0,iVar6,0
                                ), -1 < iVar9)) {
            *(undefined1 *)(puVar10 + 0x26) = 1;
            *(int *)(puVar10 + 5) = (int)local_b0;
            if (iVar6 != 1) {
              *(int *)((long)puVar10 + 0x2c) = local_b0._4_4_;
              if (iVar6 != 2) {
                *(int *)(puVar10 + 6) = (int)local_a8;
                if (iVar6 != 3) {
                  *(int *)((long)puVar10 + 0x34) = local_a8._4_4_;
                  if (iVar6 != 4) {
                    *(int *)(puVar10 + 7) = (int)local_a0;
                    if (iVar6 != 5) {
                      *(int *)((long)puVar10 + 0x3c) = local_a0._4_4_;
                      if (iVar6 != 6) {
                        *(int *)(puVar10 + 8) = (int)local_98;
                        if (iVar6 != 7) {
                          *(int *)((long)puVar10 + 0x44) = local_98._4_4_;
                          if (iVar6 != 8) {
                            *(int *)(puVar10 + 9) = (int)local_90;
                            if (iVar6 != 9) {
                              *(int *)((long)puVar10 + 0x4c) = local_90._4_4_;
                              if (iVar6 != 10) {
                                *(int *)(puVar10 + 10) = (int)local_88;
                                if (iVar6 != 0xb) {
                                  *(int *)((long)puVar10 + 0x54) = local_88._4_4_;
                                  if (iVar6 != 0xc) {
                                    *(int *)(puVar10 + 0xb) = (int)local_80;
                                    if (iVar6 != 0xd) {
                                      *(int *)((long)puVar10 + 0x5c) = local_80._4_4_;
                                      if (iVar6 != 0xe) {
                                        *(int *)(puVar10 + 0xc) = (int)local_78;
                                        if (iVar6 != 0xf) {
                                          *(int *)((long)puVar10 + 100) = local_78._4_4_;
                                          if (iVar6 != 0x10) {
LAB_00101678:
                    /* WARNING: Does not return */
                                            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10167c);
                                            (*pcVar5)();
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            *(int *)(puVar10 + 0x25) = iVar6;
          }
          uVar14 = of_get_named_gpio_flags
                             (*(undefined8 *)(param_1 + 0x2f8),"qcom,cdc-rst-n-gpio",0,0);
          *(uint *)(puVar10 + 4) = (uint)uVar14;
          if ((0x1ff < (uint)uVar14) || (iVar6 = gpio_request(uVar14,"MSM_CDC_RESET"), iVar6 == 0))
          {
            _dev_info(param_1 + 0x10,"%s: gpio_data %p\n","msm_cdc_pinctrl_probe",puVar10);
            iVar6 = 0;
            *(ulong **)(param_1 + 0xa8) = puVar10;
            goto LAB_001011d0;
          }
          _dev_err(lVar1,"%s: Failed to request gpio %d\n","msm_cdc_pinctrl_probe",(int)puVar10[4]);
        }
      }
      devm_pinctrl_put(*puVar10);
    }
    devm_kfree(lVar1,puVar10);
    _dev_err(lVar1,"%s: exit, ret = %d\n","msm_cdc_pinctrl_probe",iVar6);
  }
LAB_001011d0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// msm_cdc_pinctrl_remove @ 00101680 size=88
// signature: undefined msm_cdc_pinctrl_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_pinctrl_remove(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  if (plVar1 != (long *)0x0) {
    if (*(uint *)(plVar1 + 4) < 0x200) {
      gpio_free();
    }
    if (*plVar1 != 0) {
      devm_pinctrl_put();
    }
  }
  devm_kfree(param_1 + 0x10,plVar1);
  return 0;
}



//------------------------------------------------------------
// msm_cdc_is_ondemand_supply @ 001016e0 size=288
// signature: undefined msm_cdc_is_ondemand_supply(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_cdc_is_ondemand_supply(long param_1,long param_2,undefined8 *param_3,uint param_4,char *param_5)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if ((param_2 == 0) || (param_5 == (char *)0x0)) {
    uVar2 = ___ratelimit(&msm_cdc_is_ondemand_supply__rs,"msm_cdc_is_ondemand_supply");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    _printk(&DAT_001039de,"msm_cdc_is_ondemand_supply");
  }
  else if (param_1 == 0) {
    uVar2 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    _printk(&DAT_00103723,"msm_cdc_check_supply_param");
  }
  else {
    uVar3 = (ulong)param_4;
    if ((param_3 == (undefined8 *)0x0) || ((int)param_4 < 1)) {
      uVar2 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,uVar3);
    }
    else {
      do {
        if ((*(char *)((long)param_3 + 0x14) != '\0') &&
           (iVar1 = strcmp((char *)*param_3,param_5), iVar1 == 0)) {
          return 1;
        }
        param_3 = param_3 + 4;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_cdc_supply_supports_retention_mode @ 00101804 size=288
// signature: undefined msm_cdc_supply_supports_retention_mode(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_cdc_supply_supports_retention_mode
          (long param_1,long param_2,undefined8 *param_3,uint param_4,char *param_5)

{
  int iVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if ((param_2 == 0) || (param_5 == (char *)0x0)) {
    uVar2 = ___ratelimit(msm_cdc_supply_supports_retention_mode__rs,
                         "msm_cdc_supply_supports_retention_mode");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    _printk(&DAT_001039de,"msm_cdc_supply_supports_retention_mode");
  }
  else if (param_1 == 0) {
    uVar2 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
    if ((int)uVar2 == 0) {
      return uVar2;
    }
    _printk(&DAT_00103723,"msm_cdc_check_supply_param");
  }
  else {
    uVar3 = (ulong)param_4;
    if ((param_3 == (undefined8 *)0x0) || ((int)param_4 < 1)) {
      uVar2 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
      if ((int)uVar2 == 0) {
        return uVar2;
      }
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,uVar3);
    }
    else {
      do {
        if ((*(char *)((long)param_3 + 0x16) != '\0') &&
           (iVar1 = strcmp((char *)*param_3,param_5), iVar1 == 0)) {
          return 1;
        }
        param_3 = param_3 + 4;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_cdc_check_supply_vote @ 00101928 size=348
// signature: undefined msm_cdc_check_supply_vote(void)
// callers: []
//------------------------------------------------------------

ulong msm_cdc_check_supply_vote
                (long param_1,long param_2,undefined8 *param_3,uint param_4,char *param_5)

{
  int iVar1;
  undefined *puVar2;
  ulong uVar3;
  char *pcVar4;
  ulong uVar5;
  
  if ((param_2 == 0) || (param_5 == (char *)0x0)) {
    uVar5 = ___ratelimit(msm_cdc_check_supply_vote__rs,"msm_cdc_check_supply_vote");
    if ((int)uVar5 == 0) {
      return uVar5;
    }
    puVar2 = &DAT_001039de;
    pcVar4 = "msm_cdc_check_supply_vote";
  }
  else {
    if (param_1 != 0) {
      uVar5 = (ulong)param_4;
      if ((param_3 == (undefined8 *)0x0) || ((int)param_4 < 1)) {
        uVar3 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
        if ((int)uVar3 == 0) {
          return uVar3;
        }
        _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
                 "msm_cdc_check_supply_param",param_3,uVar5);
        return 0;
      }
      do {
        iVar1 = strcmp((char *)*param_3,param_5);
        if (iVar1 == 0) {
          return (ulong)(*(char *)((long)param_3 + 0x17) != '\0');
        }
        param_3 = param_3 + 4;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      iVar1 = ___ratelimit(msm_cdc_check_supply_vote__rs_1,"msm_cdc_check_supply_vote");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: Unable to find vote for supply %s\n","msm_cdc_check_supply_vote",
                 param_5);
      }
      return 1;
    }
    uVar5 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
    if ((int)uVar5 == 0) {
      return uVar5;
    }
    puVar2 = &DAT_00103723;
    pcVar4 = "msm_cdc_check_supply_param";
  }
  _printk(puVar2,pcVar4);
  return 0;
}



//------------------------------------------------------------
// msm_cdc_set_supply_min_voltage @ 00101a88 size=360
// signature: undefined msm_cdc_set_supply_min_voltage(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_cdc_set_supply_min_voltage
          (long param_1,long param_2,long param_3,uint param_4,char *param_5,undefined4 param_6,
          uint param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  if ((param_2 == 0) || (param_5 == (char *)0x0)) {
    iVar2 = ___ratelimit(msm_cdc_set_supply_min_voltage__rs,"msm_cdc_set_supply_min_voltage");
    if (iVar2 != 0) {
      _printk(&DAT_001039de,"msm_cdc_set_supply_min_voltage");
      return 0xffffffea;
    }
  }
  else {
    if (param_1 == 0) {
      iVar2 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
      if (iVar2 == 0) {
        return 0xffffffed;
      }
      _printk(&DAT_00103723,"msm_cdc_check_supply_param");
      return 0xffffffed;
    }
    uVar4 = (ulong)param_4;
    if ((param_3 != 0) && (0 < (int)param_4)) {
      puVar3 = (undefined4 *)(param_3 + 0xc);
      puVar5 = (undefined8 *)(param_2 + 0x10);
      do {
        iVar2 = strcmp(*(char **)(puVar3 + -3),param_5);
        if (iVar2 == 0) {
          if ((param_7 & 1) == 0) {
            param_6 = puVar3[-1];
            uVar1 = *puVar3;
          }
          else {
            uVar1 = *puVar3;
          }
          regulator_set_voltage(*puVar5,param_6,uVar1);
          return 0;
        }
        puVar3 = puVar3 + 8;
        puVar5 = puVar5 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
      return 0;
    }
    iVar2 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
    if (iVar2 != 0) {
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,uVar4);
      return 0xffffffea;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_cdc_disable_ondemand_supply @ 00101bf4 size=548
// signature: undefined msm_cdc_disable_ondemand_supply(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_disable_ondemand_supply
              (long param_1,undefined8 *param_2,long param_3,uint param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  
  if ((param_2 == (undefined8 *)0x0) || (param_5 == (char *)0x0)) {
    iVar1 = ___ratelimit(msm_cdc_disable_ondemand_supply__rs,"msm_cdc_disable_ondemand_supply");
    if (iVar1 != 0) {
      _printk(&DAT_001039de,"msm_cdc_disable_ondemand_supply");
    }
  }
  else {
    if (param_1 == 0) {
      iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
      if (iVar1 == 0) {
        return -0x13;
      }
      _printk(&DAT_00103723,"msm_cdc_check_supply_param");
      return -0x13;
    }
    uVar3 = (ulong)param_4;
    if ((param_3 == 0) || ((int)param_4 < 1)) {
      iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
                 "msm_cdc_check_supply_param",param_3,uVar3);
      }
    }
    else {
      pcVar4 = (char *)(param_3 + 0x17);
      do {
        if ((pcVar4[-3] != '\0') && (iVar1 = strcmp(*(char **)(pcVar4 + -0x17),param_5), iVar1 == 0)
           ) {
          if (*pcVar4 == '\0') {
            iVar1 = ___ratelimit(msm_cdc_disable_ondemand_supply__rs_3,
                                 "msm_cdc_disable_ondemand_supply");
            if (iVar1 != 0) {
              _dev_err(param_1,"%s: Attempted to disable already disabled supply %s\n",
                       "msm_cdc_disable_ondemand_supply",*param_2);
            }
            iVar1 = 0;
          }
          else {
            iVar1 = regulator_disable(param_2[2]);
            if (iVar1 == 0) {
              *pcVar4 = '\0';
            }
            else {
              iVar2 = ___ratelimit(msm_cdc_disable_ondemand_supply__rs_5,
                                   "msm_cdc_disable_ondemand_supply");
              if (iVar2 != 0) {
                _dev_err(param_1,"%s: failed to disable supply %s, err:%d\n",
                         "msm_cdc_disable_ondemand_supply",*param_2,iVar1);
              }
            }
          }
          if ((int)uVar3 != 0) {
            return iVar1;
          }
          break;
        }
        uVar3 = uVar3 - 1;
        pcVar4 = pcVar4 + 0x20;
        param_2 = param_2 + 4;
      } while (uVar3 != 0);
      iVar1 = ___ratelimit(msm_cdc_disable_ondemand_supply__rs_7,"msm_cdc_disable_ondemand_supply");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: not able to find supply %s\n","msm_cdc_disable_ondemand_supply",
                 param_5);
      }
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_cdc_enable_ondemand_supply @ 00101e1c size=552
// signature: undefined msm_cdc_enable_ondemand_supply(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_enable_ondemand_supply
              (long param_1,undefined8 *param_2,long param_3,uint param_4,char *param_5)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  char *pcVar4;
  
  if ((param_2 == (undefined8 *)0x0) || (param_5 == (char *)0x0)) {
    iVar1 = ___ratelimit(msm_cdc_enable_ondemand_supply__rs,"msm_cdc_enable_ondemand_supply");
    if (iVar1 != 0) {
      _printk(&DAT_001039de,"msm_cdc_enable_ondemand_supply");
    }
  }
  else {
    if (param_1 == 0) {
      iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
      if (iVar1 == 0) {
        return -0x13;
      }
      _printk(&DAT_00103723,"msm_cdc_check_supply_param");
      return -0x13;
    }
    uVar3 = (ulong)param_4;
    if ((param_3 == 0) || ((int)param_4 < 1)) {
      iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
                 "msm_cdc_check_supply_param",param_3,uVar3);
      }
    }
    else {
      pcVar4 = (char *)(param_3 + 0x17);
      do {
        if ((pcVar4[-3] != '\0') && (iVar1 = strcmp(*(char **)(pcVar4 + -0x17),param_5), iVar1 == 0)
           ) {
          if (*pcVar4 == '\0') {
            iVar1 = regulator_enable(param_2[2]);
            if (iVar1 == 0) {
              *pcVar4 = '\x01';
            }
            else {
              iVar2 = ___ratelimit(msm_cdc_enable_ondemand_supply__rs_11,
                                   "msm_cdc_enable_ondemand_supply");
              if (iVar2 != 0) {
                _dev_err(param_1,"%s: failed to enable supply %s, rc: %d\n",
                         "msm_cdc_enable_ondemand_supply",*param_2,iVar1);
              }
            }
          }
          else {
            iVar1 = ___ratelimit(msm_cdc_enable_ondemand_supply__rs_9,
                                 "msm_cdc_enable_ondemand_supply");
            if (iVar1 != 0) {
              _dev_err(param_1,"%s: Attempted to enable already enabled supply %s\n",
                       "msm_cdc_enable_ondemand_supply",*param_2);
            }
            iVar1 = 0;
          }
          if ((int)uVar3 != 0) {
            return iVar1;
          }
          break;
        }
        uVar3 = uVar3 - 1;
        pcVar4 = pcVar4 + 0x20;
        param_2 = param_2 + 4;
      } while (uVar3 != 0);
      iVar1 = ___ratelimit(msm_cdc_enable_ondemand_supply__rs_13,"msm_cdc_enable_ondemand_supply");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s: not able to find supply %s\n","msm_cdc_enable_ondemand_supply",param_5
                );
      }
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_cdc_set_supplies_lpm_mode @ 00102048 size=448
// signature: undefined msm_cdc_set_supplies_lpm_mode(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_set_supplies_lpm_mode(long param_1,long param_2,long param_3,uint param_4,ulong param_5)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  
  if (param_2 == 0) {
    iVar2 = ___ratelimit(msm_cdc_set_supplies_lpm_mode__rs,"msm_cdc_set_supplies_lpm_mode");
    if (iVar2 != 0) {
      _printk(&DAT_001038ce,"msm_cdc_set_supplies_lpm_mode");
    }
  }
  else {
    if (param_1 == 0) {
      iVar2 = ___ratelimit(msm_cdc_check_supply_param__rs,"msm_cdc_check_supply_param");
      if (iVar2 == 0) {
        return -0x13;
      }
      _printk(&DAT_00103723,"msm_cdc_check_supply_param");
      return -0x13;
    }
    uVar5 = (ulong)param_4;
    if ((param_3 != 0) && (0 < (int)param_4)) {
      iVar2 = 0;
      puVar1 = &UNK_00103a10;
      if ((param_5 & 1) == 0) {
        puVar1 = &DAT_00103c6a;
      }
      puVar6 = (undefined4 *)(param_3 + 0x10);
      puVar7 = (undefined8 *)(param_2 + 0x10);
      do {
        if (*(char *)((long)puVar6 + 5) != '\0') {
          if ((param_5 & 1) == 0) {
            uVar4 = *puVar6;
          }
          else {
            uVar4 = 0;
          }
          iVar2 = regulator_set_load(*puVar7,uVar4);
          if ((iVar2 != 0) &&
             (iVar3 = ___ratelimit(msm_cdc_set_supplies_lpm_mode__rs_15,
                                   "msm_cdc_set_supplies_lpm_mode"), iVar3 != 0)) {
            _dev_err(param_1,"%s: failed to set supply %s to %s, err:%d\n",
                     "msm_cdc_set_supplies_lpm_mode",puVar7[-2],puVar1,iVar2);
          }
        }
        puVar6 = puVar6 + 8;
        puVar7 = puVar7 + 4;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      return iVar2;
    }
    iVar2 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
    if (iVar2 != 0) {
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,uVar5);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_cdc_disable_static_supplies @ 0010220c size=288
// signature: undefined msm_cdc_disable_static_supplies(void)
// callers: [msm_cdc_release_supplies]
//------------------------------------------------------------

int msm_cdc_disable_static_supplies(long param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  ulong uVar2;
  undefined1 *puVar3;
  undefined8 *puVar4;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    _printk(&DAT_001039de,"msm_cdc_disable_static_supplies");
  }
  else {
    uVar2 = (ulong)param_4;
    if (0 < (int)param_4) {
      iVar1 = 0;
      puVar3 = (undefined1 *)(param_3 + 0x17);
      puVar4 = (undefined8 *)(param_2 + 0x10);
      do {
        if (puVar3[-3] == '\0') {
          iVar1 = regulator_disable(*puVar4);
          if (iVar1 == 0) {
            *puVar3 = 0;
          }
          else {
            _dev_err(param_1,"%s: failed to disable supply %s, err:%d\n",
                     "msm_cdc_disable_static_supplies",puVar4[-2],iVar1);
          }
        }
        puVar3 = puVar3 + 0x20;
        puVar4 = puVar4 + 4;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
      return iVar1;
    }
    iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,uVar2);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_cdc_release_supplies @ 00102330 size=268
// signature: undefined msm_cdc_release_supplies(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_release_supplies(long param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    _printk(&DAT_001039de,"msm_cdc_release_supplies");
  }
  else {
    uVar3 = (ulong)param_4;
    if (0 < (int)param_4) {
      msm_cdc_disable_static_supplies(param_1,param_2,param_3,uVar3);
      puVar2 = (undefined4 *)(param_3 + 0xc);
      puVar4 = (undefined8 *)(param_2 + 0x10);
      do {
        iVar1 = regulator_count_voltages(*puVar4);
        if (-1 < iVar1) {
          regulator_set_voltage(*puVar4,0,*puVar2);
          regulator_set_load(*puVar4,0);
        }
        puVar2 = puVar2 + 8;
        puVar4 = puVar4 + 4;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
      return 0;
    }
    iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,uVar3);
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_cdc_enable_static_supplies @ 00102440 size=392
// signature: undefined msm_cdc_enable_static_supplies(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_enable_static_supplies(long param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    _printk(&DAT_001039de,"msm_cdc_enable_static_supplies");
  }
  else {
    if (0 < (int)param_4) {
      lVar3 = 0;
      do {
        if (*(char *)(param_3 + 0x14 + lVar3) == '\0') {
          iVar1 = regulator_enable(*(undefined8 *)(param_2 + 0x10 + lVar3));
          if (iVar1 != 0) {
            _dev_err(param_1,"%s: failed to enable supply %s, rc: %d\n",
                     "msm_cdc_enable_static_supplies",*(undefined8 *)(param_2 + lVar3),iVar1);
            for (; lVar3 != 0; lVar3 = lVar3 + -0x20) {
              if (*(char *)(param_3 + lVar3 + -0xc) == '\0') {
                iVar2 = regulator_disable(*(undefined8 *)(param_2 + lVar3 + -0x10));
                if (iVar2 == 0) {
                  *(undefined1 *)(param_3 + lVar3 + -9) = 0;
                }
                else {
                  _dev_err(param_1,"%s: failed to disable supply %s during unwind\n",
                           "msm_cdc_enable_static_supplies",*(undefined8 *)(param_2 + lVar3 + -0x20)
                          );
                }
              }
            }
            return iVar1;
          }
          *(undefined1 *)(param_3 + 0x14 + lVar3 + 3) = 1;
        }
        lVar3 = lVar3 + 0x20;
      } while ((ulong)param_4 * 0x20 != lVar3);
      return 0;
    }
    iVar1 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
               "msm_cdc_check_supply_param",param_3,(ulong)param_4);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// msm_cdc_init_supplies @ 001025cc size=32
// signature: undefined msm_cdc_init_supplies(void)
// callers: []
//------------------------------------------------------------

void msm_cdc_init_supplies(void)

{
  msm_cdc_init_supplies_v2();
  return;
}



//------------------------------------------------------------
// msm_cdc_init_supplies_v2 @ 001025f0 size=520
// signature: undefined msm_cdc_init_supplies_v2(void)
// callers: [msm_cdc_init_supplies]
//------------------------------------------------------------

int msm_cdc_init_supplies_v2(long param_1,long *param_2,long param_3,uint param_4,int param_5)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  ulong uVar8;
  
  if ((param_1 == 0) || (param_3 == 0)) {
    _printk(&DAT_00103bcd,"msm_cdc_init_supplies_v2");
    iVar3 = -0x16;
  }
  else {
    uVar8 = (ulong)param_4;
    if ((int)param_4 < 1) {
      iVar3 = ___ratelimit(msm_cdc_check_supply_param__rs_45,"msm_cdc_check_supply_param");
      if (iVar3 == 0) {
        iVar3 = -0x16;
      }
      else {
        _dev_err(param_1,"%s: supply check failed: vreg: %pK, num_supplies: %d\n",
                 "msm_cdc_check_supply_param",param_3,uVar8);
        iVar3 = -0x16;
      }
    }
    else {
      lVar4 = devm_kmalloc(param_1,uVar8 << 5,0xdc0);
      if (lVar4 == 0) {
        iVar3 = -0xc;
      }
      else {
        lVar7 = 0;
        do {
          if (*(long *)(param_3 + lVar7) == 0) {
            _dev_err(param_1,"%s: supply name not defined\n","msm_cdc_init_supplies_v2");
            return -0x16;
          }
          *(long *)(lVar4 + lVar7) = *(long *)(param_3 + lVar7);
          lVar7 = lVar7 + 0x20;
        } while (uVar8 * 0x20 != lVar7);
        iVar3 = devm_regulator_bulk_get(param_1,uVar8,lVar4);
        if (iVar3 == 0) {
          lVar7 = 0;
          do {
            lVar1 = lVar4 + lVar7;
            iVar3 = regulator_count_voltages(*(undefined8 *)(lVar1 + 0x10));
            if ((-1 < iVar3) &&
               ((lVar2 = param_3 + lVar7, param_5 == 0 || (*(char *)(lVar2 + 0x14) == '\0')))) {
              uVar5 = *(undefined8 *)(lVar1 + 0x10);
              *(undefined8 *)(lVar2 + 0x18) = uVar5;
              iVar3 = regulator_set_voltage
                                (uVar5,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc));
              if (iVar3 != 0) {
                uVar5 = *(undefined8 *)(lVar4 + lVar7);
                pcVar6 = "%s: set regulator voltage failed for %s, err:%d\n";
LAB_001027c0:
                _dev_err(param_1,pcVar6,"msm_cdc_init_supplies_v2",uVar5,iVar3);
                return iVar3;
              }
              iVar3 = regulator_set_load(*(undefined8 *)(lVar1 + 0x10),
                                         *(undefined4 *)(param_3 + lVar7 + 0x10));
              if (iVar3 < 0) {
                uVar5 = *(undefined8 *)(lVar4 + lVar7);
                pcVar6 = "%s: set regulator optimum mode failed for %s, err:%d\n";
                goto LAB_001027c0;
              }
            }
            lVar7 = lVar7 + 0x20;
          } while (uVar8 * 0x20 != lVar7);
          iVar3 = 0;
          *param_2 = lVar4;
        }
        else {
          _dev_err(param_1,"%s: failed to get supplies (%d)\n","msm_cdc_init_supplies_v2",iVar3);
        }
      }
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_cdc_get_power_supplies @ 001027fc size=676
// signature: undefined msm_cdc_get_power_supplies(void)
// callers: []
//------------------------------------------------------------

ulong msm_cdc_get_power_supplies(long param_1,long *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  char *pcVar7;
  ulong uVar8;
  
  if (param_1 == 0) {
    iVar3 = ___ratelimit(msm_cdc_get_power_supplies__rs,"msm_cdc_get_power_supplies");
    if (iVar3 != 0) {
      _printk(&DAT_001039c0,"msm_cdc_get_power_supplies");
      return 0xffffffea;
    }
LAB_0010298c:
    uVar8 = 0xffffffea;
  }
  else {
    uVar2 = of_property_read_string_helper
                      (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-static-supplies",0,0,0);
    uVar8 = (ulong)uVar2;
    if ((int)uVar2 < 0) {
      iVar3 = ___ratelimit(msm_cdc_get_power_supplies__rs_29,"msm_cdc_get_power_supplies");
      if (iVar3 == 0) {
        return uVar8;
      }
      pcVar7 = "%s: Failed to get static supplies(%d)\n";
    }
    else {
      iVar3 = of_property_read_string_helper
                        (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-on-demand-supplies",0,0,0);
      if (iVar3 < 1) {
        iVar3 = 0;
      }
      iVar4 = of_property_read_string_helper
                        (*(undefined8 *)(param_1 + 0x2e8),"qcom,cdc-cp-supplies",0,0,0);
      if (iVar4 < 1) {
        iVar4 = 0;
      }
      uVar1 = iVar4 + iVar3 + uVar2;
      if ((int)uVar1 < 1) {
        iVar3 = ___ratelimit(msm_cdc_get_power_supplies__rs_31,"msm_cdc_get_power_supplies");
        if (iVar3 != 0) {
          _dev_err(param_1,"%s: supply count is 0 or negative\n","msm_cdc_get_power_supplies");
          return 0xffffffea;
        }
        goto LAB_0010298c;
      }
      lVar6 = devm_kmalloc(param_1,(ulong)uVar1 << 5,0xdc0);
      if (lVar6 == 0) {
        return 0xfffffff4;
      }
      uVar5 = msm_cdc_parse_supplies(param_1,lVar6,"qcom,cdc-static-supplies",uVar2,0);
      if (uVar5 != 0) {
        iVar3 = ___ratelimit(msm_cdc_get_power_supplies__rs_33,"msm_cdc_get_power_supplies");
        if (iVar3 != 0) {
          _dev_err(param_1,"%s: failed to parse static supplies(%d)\n","msm_cdc_get_power_supplies",
                   (ulong)uVar5);
        }
        return (ulong)uVar5;
      }
      uVar5 = msm_cdc_parse_supplies
                        (param_1,lVar6 + uVar8 * 0x20,"qcom,cdc-on-demand-supplies",iVar3,1);
      if (uVar5 == 0) {
        uVar2 = msm_cdc_parse_supplies
                          (param_1,lVar6 + (long)(int)(iVar3 + uVar2) * 0x20,"qcom,cdc-cp-supplies",
                           iVar4,1);
        uVar8 = (ulong)uVar2;
        if (uVar2 == 0) {
          *param_2 = lVar6;
          *param_3 = uVar1;
          return 0;
        }
        iVar3 = ___ratelimit(msm_cdc_get_power_supplies__rs_37,"msm_cdc_get_power_supplies");
        if (iVar3 == 0) {
          return uVar8;
        }
        pcVar7 = "%s: failed to parse cp supplies(%d)\n";
      }
      else {
        uVar8 = (ulong)uVar5;
        iVar3 = ___ratelimit(msm_cdc_get_power_supplies__rs_35,"msm_cdc_get_power_supplies");
        if (iVar3 == 0) {
          return uVar8;
        }
        pcVar7 = "%s: failed to parse demand supplies(%d)\n";
      }
    }
    _dev_err(param_1,pcVar7,"msm_cdc_get_power_supplies",uVar8);
  }
  return uVar8;
}



//------------------------------------------------------------
// msm_cdc_parse_supplies @ 00102aa0 size=852
// signature: undefined msm_cdc_parse_supplies(void)
// callers: [msm_cdc_get_power_supplies]
//------------------------------------------------------------

int msm_cdc_parse_supplies(long param_1,long param_2,undefined8 param_3,uint param_4,byte param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  ulong uVar8;
  long lVar9;
  char *local_f0;
  undefined8 local_e8;
  char acStack_e0 [40];
  long local_b8 [11];
  
  lVar9 = sp_el0;
  local_b8[10] = *(long *)(lVar9 + 0x638);
  local_f0 = (char *)0x0;
  if (0 < (int)param_4) {
    uVar8 = 0;
    lVar9 = param_2 + 0x16;
    do {
      iVar3 = of_property_read_string_helper
                        (*(undefined8 *)(param_1 + 0x2e8),param_3,&local_f0,1,uVar8 & 0xffffffff);
      pcVar6 = local_f0;
      if (iVar3 < 0) {
        _dev_err(param_1,"%s: read string %s[%d] error (%d)\n","msm_cdc_parse_supplies",param_3,
                 uVar8 & 0xffffffff,iVar3);
        goto LAB_00102ce0;
      }
      acStack_e0[0x18] = '\0';
      acStack_e0[0x19] = '\0';
      acStack_e0[0x1a] = '\0';
      acStack_e0[0x1b] = '\0';
      acStack_e0[0x1c] = '\0';
      acStack_e0[0x1d] = '\0';
      acStack_e0[0x1e] = '\0';
      acStack_e0[0x1f] = '\0';
      acStack_e0[0x20] = '\0';
      acStack_e0[0x21] = '\0';
      acStack_e0[0x22] = '\0';
      acStack_e0[0x23] = '\0';
      acStack_e0[0x24] = '\0';
      acStack_e0[0x25] = '\0';
      acStack_e0[0x26] = '\0';
      acStack_e0[0x27] = '\0';
      acStack_e0[8] = '\0';
      acStack_e0[9] = '\0';
      acStack_e0[10] = '\0';
      acStack_e0[0xb] = '\0';
      acStack_e0[0xc] = '\0';
      acStack_e0[0xd] = '\0';
      acStack_e0[0xe] = '\0';
      acStack_e0[0xf] = '\0';
      acStack_e0[0x10] = '\0';
      acStack_e0[0x11] = '\0';
      acStack_e0[0x12] = '\0';
      acStack_e0[0x13] = '\0';
      acStack_e0[0x14] = '\0';
      acStack_e0[0x15] = '\0';
      acStack_e0[0x16] = '\0';
      acStack_e0[0x17] = '\0';
      local_e8 = 0;
      acStack_e0[0] = '\0';
      acStack_e0[1] = '\0';
      acStack_e0[2] = '\0';
      acStack_e0[3] = '\0';
      acStack_e0[4] = '\0';
      acStack_e0[5] = '\0';
      acStack_e0[6] = '\0';
      acStack_e0[7] = '\0';
      snprintf(acStack_e0,0x28,"%s-supply",local_f0);
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
      iVar3 = __of_parse_phandle_with_args
                        (*(undefined8 *)(param_1 + 0x2e8),acStack_e0,0,0,0,local_b8);
      if ((iVar3 != 0) || (local_b8[0] == 0)) {
        pcVar5 = "%s: Looking up %s property in node %s failed";
        pcVar6 = acStack_e0;
        pcVar7 = *(char **)(*(long *)(param_1 + 0x2e8) + 0x10);
LAB_00102d94:
        _dev_err(param_1,pcVar5,"msm_cdc_dt_parse_vreg_info",pcVar6,pcVar7);
        iVar3 = -0x16;
LAB_00102dcc:
        _dev_err(param_1,"%s: parse %s vreg info failed (%d)\n","msm_cdc_parse_supplies",local_f0,
                 iVar3);
        goto LAB_00102ce0;
      }
      *(char **)(lVar9 + -0x16) = pcVar6;
      *(byte *)(lVar9 + -2) = param_5 & 1;
      snprintf(acStack_e0,0x28,"qcom,%s-voltage",pcVar6);
      puVar4 = (uint *)of_get_property(*(undefined8 *)(param_1 + 0x2e8),acStack_e0,
                                       (long)&local_e8 + 4);
      if ((puVar4 == (uint *)0x0) || (local_e8._4_4_ != 8)) {
        pcVar5 = "%s: %s %s property\n";
        pcVar6 = "no";
        if (puVar4 != (uint *)0x0) {
          pcVar6 = "invalid format";
        }
        pcVar7 = acStack_e0;
        goto LAB_00102d94;
      }
      uVar2 = (*puVar4 & 0xff00ff00) >> 8 | (*puVar4 & 0xff00ff) << 8;
      *(uint *)(lVar9 + -0xe) = uVar2 >> 0x10 | uVar2 << 0x10;
      uVar2 = (puVar4[1] & 0xff00ff00) >> 8 | (puVar4[1] & 0xff00ff) << 8;
      *(uint *)(lVar9 + -10) = uVar2 >> 0x10 | uVar2 << 0x10;
      snprintf(acStack_e0,0x28,"qcom,%s-current",pcVar6);
      iVar3 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),acStack_e0,&local_e8,1,0);
      if (iVar3 < 0) {
        _dev_err(param_1,"%s: Looking up %s property in node %s failed","msm_cdc_dt_parse_vreg_info"
                 ,acStack_e0,*(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0x10));
        goto LAB_00102dcc;
      }
      *(int *)(lVar9 + -6) = (int)local_e8;
      snprintf(acStack_e0,0x28,"qcom,%s-lpm-supported",pcVar6);
      iVar3 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),acStack_e0,&local_e8,1,0);
      *(bool *)(lVar9 + -1) = -1 < iVar3 && (int)local_e8 != 0;
      snprintf(acStack_e0,0x28,"qcom,%s-rem-supported",pcVar6);
      iVar3 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),acStack_e0,&local_e8,1,0);
      bVar1 = -1 < iVar3 && (int)local_e8 != 0;
      *(bool *)lVar9 = bVar1;
      _dev_info(param_1,"%s: %s: vol=[%d %d]uV, curr=[%d]uA, ond %d lpm %d rem %d\n",
                "msm_cdc_dt_parse_vreg_info",*(undefined8 *)(lVar9 + -0x16),
                *(undefined4 *)(lVar9 + -0xe),*(undefined4 *)(lVar9 + -10),
                *(undefined4 *)(lVar9 + -6),*(undefined1 *)(lVar9 + -2),*(undefined1 *)(lVar9 + -1),
                bVar1);
      uVar8 = uVar8 + 1;
      lVar9 = lVar9 + 0x20;
    } while (param_4 != uVar8);
  }
  iVar3 = 0;
LAB_00102ce0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_cdc_init_wcd_supply @ 00102df8 size=104
// signature: undefined msm_cdc_init_wcd_supply(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_cdc_init_wcd_supply(long param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar1 = 0xffffffea;
  if ((param_1 != 0) && (param_3 != (undefined8 *)0x0)) {
    lVar2 = of_find_device_by_node(param_1);
    if (lVar2 == 0) {
      uVar1 = 0xffffffea;
    }
    else {
      *param_3 = param_2;
      param_3[1] = lVar2 + 0x10;
      uVar3 = snd_soc_lookup_component(lVar2 + 0x10,0);
      uVar1 = 0;
      param_3[2] = uVar3;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_cdc_enable_wcd_supply @ 00102e64 size=244
// signature: undefined msm_cdc_enable_wcd_supply(void)
// callers: []
//------------------------------------------------------------

int msm_cdc_enable_wcd_supply(undefined8 *param_1,ulong param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = param_1[2];
  if (lVar4 == 0) {
    iVar2 = ___ratelimit(msm_cdc_enable_wcd_supply__rs,"msm_cdc_enable_wcd_supply");
    if (iVar2 == 0) {
      iVar2 = -0x16;
    }
    else {
      _printk(&DAT_00103697,"msm_cdc_enable_wcd_supply");
      iVar2 = -0x16;
    }
  }
  else {
    if ((param_2 & 1) == 0) {
      iVar2 = snd_soc_dapm_disable_pin(lVar4 + 0xd0,*param_1);
    }
    else {
      iVar2 = snd_soc_dapm_force_enable_pin();
    }
    if (iVar2 == 0) {
      snd_soc_dapm_sync(lVar4 + 0xd0);
    }
    else {
      iVar3 = ___ratelimit(msm_cdc_enable_wcd_supply__rs_40,"msm_cdc_enable_wcd_supply");
      if (iVar3 != 0) {
        pcVar1 = "enable";
        if ((param_2 & 1) == 0) {
          pcVar1 = "disable";
        }
        _dev_err(*(undefined8 *)(lVar4 + 0x18),"%s: micbias %s force %s pin failed\n",
                 "msm_cdc_enable_wcd_supply",*param_1,pcVar1);
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd_request_irq @ 00102f5c size=140
// signature: undefined wcd_request_irq(void)
// callers: []
//------------------------------------------------------------

int wcd_request_irq(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                   undefined8 param_5)

{
  int iVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_00103cc0,"wcd_request_irq");
    iVar1 = -0x16;
  }
  else {
    iVar1 = regmap_irq_get_virq(*(undefined8 *)(param_1 + 0x18));
    if (-1 < iVar1) {
      iVar1 = devm_request_threaded_irq
                        (*(undefined8 *)(param_1 + 0x20),iVar1,0,param_4,0x2001,param_3,param_5);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_free_irq @ 00102fec size=96
// signature: undefined wcd_free_irq(void)
// callers: []
//------------------------------------------------------------

void wcd_free_irq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_00103cc0,"wcd_free_irq");
  }
  else {
    iVar1 = regmap_irq_get_virq(*(undefined8 *)(param_1 + 0x18));
    if (-1 < iVar1) {
      devm_free_irq(*(undefined8 *)(param_1 + 0x20),iVar1,param_3);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd_enable_irq @ 00103050 size=64
// signature: undefined wcd_enable_irq(void)
// callers: []
//------------------------------------------------------------

void wcd_enable_irq(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_00103cc0,"wcd_enable_irq");
  }
  else {
    regmap_irq_get_virq(*(undefined8 *)(param_1 + 0x18));
    enable_irq();
  }
  return;
}



//------------------------------------------------------------
// wcd_disable_irq @ 00103094 size=64
// signature: undefined wcd_disable_irq(void)
// callers: []
//------------------------------------------------------------

void wcd_disable_irq(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_00103cc0,"wcd_disable_irq");
  }
  else {
    regmap_irq_get_virq(*(undefined8 *)(param_1 + 0x18));
    disable_irq_nosync();
  }
  return;
}



//------------------------------------------------------------
// wcd_irq_init @ 001030d8 size=240
// signature: undefined wcd_irq_init(void)
// callers: []
//------------------------------------------------------------

int wcd_irq_init(undefined8 *param_1,long *param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  if (param_1 == (undefined8 *)0x0) {
    puVar4 = &DAT_00103cc0;
  }
  else {
    wcd_irq_chip = param_1[1];
    lVar3 = __irq_domain_add(0,1,1,0,&wcd_domain_ops,0);
    *param_2 = lVar3;
    if (lVar3 != 0) {
      uVar5 = param_1[4];
      uVar6 = param_1[2];
      uVar1 = irq_create_mapping_affinity(lVar3,0,0);
      iVar2 = devm_regmap_add_irq_chip(uVar5,uVar6,uVar1,0x2000,0,*param_1,param_1 + 3);
      if (iVar2 == 0) {
        return 0;
      }
      _printk(&DAT_00103eb8,"wcd_irq_init",iVar2);
      return iVar2;
    }
    puVar4 = &DAT_0010388f;
  }
  _printk(puVar4,"wcd_irq_init");
  return -0x16;
}



//------------------------------------------------------------
// wcd_irq_exit @ 001031cc size=164
// signature: undefined wcd_irq_exit(void)
// callers: []
//------------------------------------------------------------

void wcd_irq_exit(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00103fcc,"wcd_irq_exit");
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = *(undefined8 *)(param_1 + 0x20);
    local_2c = 0;
    lVar2 = __irq_resolve_mapping(param_2,0,&local_2c);
    uVar1 = 0;
    if (lVar2 != 0) {
      uVar1 = local_2c;
    }
    devm_regmap_del_irq_chip(uVar3,uVar1,*(undefined8 *)(param_1 + 0x18));
    uVar3 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wcd_irq_chip_enable @ 00103274 size=4
// signature: undefined wcd_irq_chip_enable(void)
// callers: []
//------------------------------------------------------------

void wcd_irq_chip_enable(void)

{
  return;
}



//------------------------------------------------------------
// wcd_irq_chip_disable @ 0010327c size=4
// signature: undefined wcd_irq_chip_disable(void)
// callers: []
//------------------------------------------------------------

void wcd_irq_chip_disable(void)

{
  return;
}



//------------------------------------------------------------
// wcd_irq_chip_map @ 00103284 size=100
// signature: undefined wcd_irq_chip_map(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_irq_chip_map(undefined8 param_1,undefined4 param_2)

{
  irq_set_chip_and_handler_name(param_2,&wcd_irq_chip,&handle_simple_irq,0);
  irq_modify_status(param_2,0,0x8000);
  irq_modify_status(param_2,0,0x400);
  return 0;
}



//------------------------------------------------------------
// init_module @ 001032ec size=144
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  int *piVar1;
  bool bVar2;
  long lVar3;
  int local_24 [3];
  long local_18;
  
  lVar3 = sp_el0;
  local_18 = *(long *)(lVar3 + 0x638);
  local_24[0] = msm_cdc_pinctrl_drv_init();
  if (local_24[0] != 0) {
    _printk(&DAT_001034a7,"wcd9xxx_core_init",local_24[0]);
  }
  local_24[1] = 0;
  local_24[2] = 0;
  lVar3 = 0;
  do {
    piVar1 = (int *)((long)local_24 + lVar3);
    bVar2 = lVar3 != 8;
    lVar3 = lVar3 + 4;
  } while (*piVar1 == 0 && bVar2);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103380 size=28
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  msm_cdc_pinctrl_drv_exit();
  return;
}



//------------------------------------------------------------
// _printk @ 00106000 size=1
// signature: undefined _printk(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_enable_wcd_supply, msm_cdc_is_ondemand_supply, msm_cdc_supply_supports_retention_mode, msm_cdc_check_supply_vote, msm_cdc_release_supplies, msm_cdc_enable_static_supplies, wcd_request_irq, msm_cdc_pinctrl_get_gpiodata, wcd_disable_irq, msm_cdc_pinctrl_select_alt_active_state, msm_cdc_set_supply_min_voltage, wcd_irq_init, msm_cdc_enable_ondemand_supply, msm_cdc_set_supplies_lpm_mode, msm_cdc_get_power_supplies, msm_cdc_pinctrl_select_active_state, msm_cdc_disable_ondemand_supply, wcd_irq_exit, init_module, msm_cdc_pinctrl_select_sleep_state, msm_cdc_disable_static_supplies, wcd_enable_irq, wcd_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106008 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_cdc_pinctrl_probe, msm_cdc_parse_supplies, wcd_irq_exit, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00106010 size=1
// signature: undefined gpio_to_desc(void)
// callers: [msm_cdc_get_gpio_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value_cansleep @ 00106018 size=1
// signature: undefined gpiod_get_raw_value_cansleep(void)
// callers: [msm_cdc_get_gpio_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value_cansleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00106020 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [msm_cdc_init_wcd_supply, msm_cdc_pinctrl_get_gpiodata]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00106028 size=1
// signature: undefined ___ratelimit(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_enable_wcd_supply, msm_cdc_is_ondemand_supply, msm_cdc_supply_supports_retention_mode, msm_cdc_check_supply_vote, msm_cdc_release_supplies, msm_cdc_enable_static_supplies, msm_cdc_pinctrl_get_gpiodata, msm_cdc_pinctrl_select_alt_active_state, msm_cdc_set_supply_min_voltage, msm_cdc_enable_ondemand_supply, msm_cdc_set_supplies_lpm_mode, msm_cdc_get_power_supplies, msm_cdc_pinctrl_select_active_state, msm_cdc_disable_ondemand_supply, msm_cdc_pinctrl_select_sleep_state, msm_cdc_disable_static_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106030 size=1
// signature: undefined _dev_err(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_enable_wcd_supply, msm_cdc_is_ondemand_supply, msm_cdc_supply_supports_retention_mode, msm_cdc_check_supply_vote, msm_cdc_release_supplies, msm_cdc_parse_supplies, msm_cdc_enable_static_supplies, msm_cdc_pinctrl_get_gpiodata, msm_cdc_set_supply_min_voltage, msm_cdc_enable_ondemand_supply, msm_cdc_set_supplies_lpm_mode, msm_cdc_get_power_supplies, msm_cdc_pinctrl_probe, msm_cdc_disable_ondemand_supply, msm_cdc_disable_static_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00106038 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [msm_cdc_pinctrl_select_active_state, msm_cdc_pinctrl_probe, msm_cdc_pinctrl_select_sleep_state, msm_cdc_pinctrl_select_alt_active_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_gpio_mpm_wake_set @ 00106040 size=1
// signature: undefined msm_gpio_mpm_wake_set(void)
// callers: [msm_cdc_pinctrl_set_wakeup_capable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_gpio_mpm_wake_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00106048 size=1
// signature: undefined __platform_driver_register(void)
// callers: [msm_cdc_pinctrl_drv_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00106050 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [msm_cdc_pinctrl_drv_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00106058 size=1
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
// log_post_read_mmio @ 00106060 size=1
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
// log_write_mmio @ 00106068 size=1
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
// log_post_write_mmio @ 00106070 size=1
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
// _dev_info @ 00106078 size=1
// signature: undefined _dev_info(void)
// callers: [msm_cdc_pinctrl_probe, msm_cdc_parse_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00106080 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_get_power_supplies, msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00106088 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00106090 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00106098 size=1
// signature: undefined of_find_property(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 001060a0 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001060a8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_cdc_pinctrl_probe, msm_cdc_parse_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001060b0 size=1
// signature: undefined devm_ioremap(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 001060b8 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [msm_cdc_pinctrl_remove, msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 001060c0 size=1
// signature: undefined devm_kfree(void)
// callers: [msm_cdc_pinctrl_remove, msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 001060c8 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 001060d0 size=1
// signature: undefined gpio_request(void)
// callers: [msm_cdc_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 001060d8 size=1
// signature: undefined gpio_free(void)
// callers: [msm_cdc_pinctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001060e0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [msm_cdc_is_ondemand_supply, msm_cdc_supply_supports_retention_mode, msm_cdc_check_supply_vote, msm_cdc_disable_ondemand_supply, msm_cdc_set_supply_min_voltage, msm_cdc_enable_ondemand_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001060e8 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_release_supplies, msm_cdc_set_supply_min_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001060f0 size=1
// signature: undefined regulator_disable(void)
// callers: [msm_cdc_disable_ondemand_supply, msm_cdc_enable_static_supplies, msm_cdc_disable_static_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001060f8 size=1
// signature: undefined regulator_enable(void)
// callers: [msm_cdc_enable_static_supplies, msm_cdc_enable_ondemand_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00106100 size=1
// signature: undefined regulator_set_load(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_set_supplies_lpm_mode, msm_cdc_release_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 00106108 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [msm_cdc_init_supplies_v2, msm_cdc_release_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_bulk_get @ 00106110 size=1
// signature: undefined devm_regulator_bulk_get(void)
// callers: [msm_cdc_init_supplies_v2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_bulk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00106118 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [msm_cdc_get_power_supplies, msm_cdc_parse_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00106120 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [msm_cdc_parse_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00106128 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_cdc_parse_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00106130 size=1
// signature: undefined of_get_property(void)
// callers: [msm_cdc_parse_supplies]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_lookup_component @ 00106138 size=1
// signature: undefined snd_soc_lookup_component(void)
// callers: [msm_cdc_init_wcd_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_lookup_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_force_enable_pin @ 00106140 size=1
// signature: undefined snd_soc_dapm_force_enable_pin(void)
// callers: [msm_cdc_enable_wcd_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_force_enable_pin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_disable_pin @ 00106148 size=1
// signature: undefined snd_soc_dapm_disable_pin(void)
// callers: [msm_cdc_enable_wcd_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_disable_pin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_sync @ 00106150 size=1
// signature: undefined snd_soc_dapm_sync(void)
// callers: [msm_cdc_enable_wcd_supply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_irq_get_virq @ 00106158 size=1
// signature: undefined regmap_irq_get_virq(void)
// callers: [wcd_request_irq, wcd_enable_irq, wcd_disable_irq, wcd_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_irq_get_virq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00106160 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [wcd_request_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00106168 size=1
// signature: undefined devm_free_irq(void)
// callers: [wcd_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00106170 size=1
// signature: undefined enable_irq(void)
// callers: [wcd_enable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00106178 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [wcd_disable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_domain_add @ 00106180 size=1
// signature: undefined __irq_domain_add(void)
// callers: [wcd_irq_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_domain_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_create_mapping_affinity @ 00106188 size=1
// signature: undefined irq_create_mapping_affinity(void)
// callers: [wcd_irq_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_create_mapping_affinity(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_add_irq_chip @ 00106190 size=1
// signature: undefined devm_regmap_add_irq_chip(void)
// callers: [wcd_irq_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_add_irq_chip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 00106198 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [wcd_irq_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_del_irq_chip @ 001061a0 size=1
// signature: undefined devm_regmap_del_irq_chip(void)
// callers: [wcd_irq_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_del_irq_chip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chip_and_handler_name @ 001061b0 size=1
// signature: undefined irq_set_chip_and_handler_name(void)
// callers: [wcd_irq_chip_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chip_and_handler_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 001061b8 size=1
// signature: undefined irq_modify_status(void)
// callers: [wcd_irq_chip_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



