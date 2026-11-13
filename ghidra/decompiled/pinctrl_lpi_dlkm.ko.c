// Decompiled by Ghidra 12.2
// Program: pinctrl_lpi_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// lpi_pinctrl_suspend @ 001005f4 size=168
// signature: undefined lpi_pinctrl_suspend(void)
// callers: [lpi_pinctrl_ssr_disable]
//------------------------------------------------------------

undefined8 lpi_pinctrl_suspend(long param_1)

{
  long lVar1;
  long lVar2;
  
  if (((*(ushort *)(param_1 + 0x200) & 7) != 0) || (*(int *)(param_1 + 0x20c) != 2)) {
    lVar2 = *(long *)(param_1 + 0x98);
    lVar1 = *(long *)(lVar2 + 0x2a0);
    if ((lVar1 != 0) || (lVar1 = *(long *)(lVar2 + 0x2a8), lVar1 != 0)) {
      mutex_lock(lVar2 + 0x2e8);
      if (*(char *)(lVar2 + 0x2e0) != '\0') {
        digital_cdc_rsc_mgr_hw_vote_disable(lVar1,param_1);
        *(undefined1 *)(lVar2 + 0x2e0) = 0;
      }
      mutex_unlock(lVar2 + 0x2e8);
    }
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,2);
    pm_runtime_enable(param_1);
  }
  return 0;
}



//------------------------------------------------------------
// lpi_pinctrl_runtime_suspend @ 001006a0 size=112
// signature: undefined lpi_pinctrl_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_pinctrl_runtime_suspend(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  lVar1 = *(long *)(lVar2 + 0x2a0);
  if ((lVar1 != 0) || (lVar1 = *(long *)(lVar2 + 0x2a8), lVar1 != 0)) {
    mutex_lock(lVar2 + 0x2e8);
    if (*(char *)(lVar2 + 0x2e0) != '\0') {
      digital_cdc_rsc_mgr_hw_vote_disable(lVar1,param_1);
      *(undefined1 *)(lVar2 + 0x2e0) = 0;
    }
    mutex_unlock(lVar2 + 0x2e8);
  }
  return 0;
}



//------------------------------------------------------------
// lpi_pinctrl_resume @ 00100714 size=8
// signature: undefined lpi_pinctrl_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_pinctrl_resume(void)

{
  return 0;
}



//------------------------------------------------------------
// lpi_pinctrl_runtime_resume @ 00100720 size=192
// signature: undefined lpi_pinctrl_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_pinctrl_runtime_resume(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar3 + 0x2a0);
  if ((lVar2 != 0) || (lVar2 = *(long *)(lVar3 + 0x2a8), lVar2 != 0)) {
    mutex_lock(lVar3 + 0x2e8);
    iVar1 = digital_cdc_rsc_mgr_hw_vote_enable(lVar2,param_1);
    if (iVar1 < 0) {
      pm_runtime_set_autosuspend_delay(param_1,1);
      iVar1 = ___ratelimit(&lpi_pinctrl_runtime_resume__rs,"lpi_pinctrl_runtime_resume");
      if (iVar1 != 0) {
        _dev_err(param_1,"%s:lpass core hw island enable failed\n","lpi_pinctrl_runtime_resume");
      }
    }
    else {
      *(undefined1 *)(lVar3 + 0x2e0) = 1;
      pm_runtime_set_autosuspend_delay(param_1,100);
    }
    mutex_unlock(lVar3 + 0x2e8);
  }
  return 0;
}



//------------------------------------------------------------
// lpi_pinctrl_probe @ 001007e4 size=1616
// signature: undefined lpi_pinctrl_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100e34) */

ulong lpi_pinctrl_probe(long param_1)

{
  long *plVar1;
  long *__dest;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auVar5 [16];
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  long *plVar11;
  undefined8 uVar12;
  long lVar13;
  undefined4 *puVar14;
  long *plVar15;
  ulong uVar16;
  char *pcVar17;
  long lVar18;
  undefined *puVar19;
  long lVar20;
  long lVar21;
  undefined8 *puVar22;
  undefined4 local_74;
  undefined8 local_70;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  local_70 = 0;
  local_74 = 0;
  _printk(&DAT_00102848,"lpi_pinctrl_probe");
  uVar10 = audio_notifier_probe_status();
  if ((uVar10 & 1) == 0) {
    _printk(&DAT_00102bcf,"lpi_pinctrl_probe");
    uVar10 = 0xfffffdfb;
    goto LAB_00100c50;
  }
  plVar1 = (long *)(param_1 + 0x10);
  uVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),&DAT_001029ce,&local_70,1,0);
  if ((int)uVar7 < 0) {
    uVar10 = (ulong)uVar7;
    _dev_err(plVar1,"missing base address\n");
    goto LAB_00100c50;
  }
  uVar8 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,gpios-count",(long)&local_70 + 4,1,0);
  uVar7 = uVar8;
  if (-1 < (int)uVar8) {
    uVar7 = 0;
  }
  uVar10 = (ulong)uVar7;
  if ((int)uVar8 < 0) goto LAB_00100c50;
  if (0x20 < local_70._4_4_) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x100da4);
    (*pcVar6)();
  }
  uVar7 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,lpi-offset-tbl",&lpi_offset,
                     (long)(int)local_70._4_4_,0);
  if ((int)uVar7 < 0) {
    uVar10 = (ulong)uVar7;
    _dev_err(plVar1,"error in reading lpi offset table: %d\n",uVar10);
    goto LAB_00100c50;
  }
  iVar9 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,lpi-slew-offset-tbl",&lpi_slew_offset,
                     (long)(int)local_70._4_4_,0);
  if ((iVar9 < 0) && (0 < (int)local_70._4_4_)) {
    lVar20 = 0;
    do {
      if (lVar20 == 400) goto LAB_00100e30;
      *(undefined4 *)((long)&lpi_slew_offset + lVar20) = 0xffffffff;
      lVar20 = lVar20 + 4;
    } while ((ulong)local_70._4_4_ * 4 != lVar20);
  }
  iVar9 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,lpi-slew-base-tbl",&lpi_slew_base,
                     (long)(int)local_70._4_4_,0);
  if (iVar9 < 0) {
    if (0 < (int)local_70._4_4_) {
      lVar20 = 0;
      do {
        if (lVar20 == 400) goto LAB_00100e30;
        *(undefined4 *)((long)&lpi_slew_base + lVar20) = 0xffffffff;
        lVar20 = lVar20 + 4;
      } while ((ulong)local_70._4_4_ * 4 != lVar20);
    }
  }
  plVar11 = (long *)devm_kmalloc(plVar1,0x318,0xdc0);
  if (plVar11 != (long *)0x0) {
    *(long **)(param_1 + 0xa8) = plVar11;
    uVar12 = *(undefined8 *)(param_1 + 0x2f8);
    *plVar11 = (long)plVar1;
    local_74 = 0;
    iVar9 = of_property_read_variable_u32_array(uVar12,"qcom,slew-reg",&local_74,1,0);
    if (iVar9 < 0) {
      lVar20 = 0;
LAB_001009e4:
      auVar5._8_8_ = 0;
      auVar5._0_8_ = (long)(int)local_70._4_4_;
      if ((((SUB168(auVar5 * ZEXT816(0x18),8) != 0) ||
           (lVar13 = devm_kmalloc(plVar1,(long)(int)local_70._4_4_ * 0x18,0xdc0), lVar13 == 0)) ||
          ((long)local_70 < 0)) ||
         ((puVar14 = (undefined4 *)devm_kmalloc(plVar1,(local_70 >> 0x20) << 6,0xdc0),
          puVar14 == (undefined4 *)0x0 ||
          (plVar15 = (long *)devm_kmalloc(plVar1,0x58,0xdc0), plVar15 == (long *)0x0))))
      goto LAB_00100c4c;
      plVar15[3] = (long)&lpi_gpio_pinctrl_ops;
      plVar15[4] = (long)lpi_gpio_pinmux_ops;
      lVar18 = *(long *)(param_1 + 0x80);
      plVar15[5] = (long)lpi_gpio_pinconf_ops;
      plVar15[6] = (long)&__this_module;
      if (lVar18 == 0) {
        lVar18 = *plVar1;
      }
      *plVar15 = lVar18;
      plVar15[1] = lVar13;
      *(uint *)(plVar15 + 2) = local_70._4_4_;
      lVar18 = devm_ioremap(plVar1,local_70 & 0xffffffff,0x20000);
      if (lVar18 != 0) {
        plVar11[0x53] = lVar18;
        iVar9 = local_70._4_4_;
        if (0 < (int)local_70._4_4_) {
          lVar21 = 0;
          puVar22 = (undefined8 *)(lVar13 + 0x10);
          do {
            *puVar22 = puVar14;
            *(int *)(puVar22 + -2) = (int)lVar21;
            if (lVar21 == 0x20) {
LAB_00100e30:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x100e34);
              (*pcVar6)();
            }
            puVar19 = (&lpi_gpio_groups)[lVar21];
            *(long *)(puVar14 + 4) = lVar18;
            *(long *)(puVar14 + 6) = lVar18;
            *(long *)(puVar14 + 8) = lVar20;
            *(undefined8 *)(puVar14 + 10) = 0;
            uVar2 = (&lpi_slew_offset)[lVar21];
            puVar22[-1] = puVar19;
            iVar3 = (&lpi_slew_base)[lVar21];
            uVar4 = (&lpi_offset)[lVar21];
            puVar14[1] = uVar4;
            puVar14[2] = uVar2;
            *puVar14 = uVar4;
            if (1 < iVar3 + 1U) {
              uVar12 = devm_ioremap(plVar1,iVar3,4);
              *(undefined8 *)(puVar14 + 10) = uVar12;
              iVar9 = local_70._4_4_;
            }
            lVar21 = lVar21 + 1;
            puVar22 = puVar22 + 3;
            puVar14 = puVar14 + 0x10;
          } while (lVar21 < iVar9);
        }
        __dest = plVar11 + 2;
        memcpy(__dest,lpi_gpio_template,0x288);
        lVar20 = *(long *)(param_1 + 0x80);
        *(short *)((long)plVar11 + 0xbc) = (short)iVar9;
        *(undefined4 *)(plVar11 + 0x17) = 0xffffffff;
        plVar11[4] = (long)plVar1;
        if (lVar20 == 0) {
          lVar20 = *plVar1;
        }
        plVar11[2] = lVar20;
        *(undefined4 *)(plVar11 + 0x4e) = 2;
        *(undefined1 *)(plVar11 + 0x19) = 0;
        __mutex_init(plVar11 + 0x56,"&state->slew_access_lock",&lpi_pinctrl_probe___key);
        __mutex_init(plVar11 + 0x5d,"&state->core_hw_vote_lock",&lpi_pinctrl_probe___key_15);
        uVar10 = devm_pinctrl_register(plVar1,plVar15,plVar11);
        plVar11[1] = uVar10;
        if (uVar10 < 0xfffffffffffff001) {
          uVar7 = gpiochip_add_data_with_key(__dest,plVar11,0,0);
          if (uVar7 == 0) {
            lVar20 = *(long *)(param_1 + 0x80);
            if (lVar20 == 0) {
              lVar20 = *plVar1;
            }
            uVar7 = gpiochip_add_pin_range(__dest,lVar20,0,0,local_70._4_4_);
            if (uVar7 == 0) {
              lpi_dev_up = 1;
              initial_boot = 1;
              lpi_dev = plVar1;
              uVar7 = snd_event_client_register(plVar1,&lpi_pinctrl_ssr_ops,0);
              if (uVar7 == 0) {
                snd_event_notify(plVar1,1);
                uVar7 = audio_notifier_register("lpi_tlmm",0,&service_nb);
                if (-1 < (int)uVar7) {
                  uVar16 = devm_clk_get(plVar1,"lpass_core_hw_vote");
                  uVar10 = 0;
                  if (uVar16 < 0xfffffffffffff001) {
                    uVar10 = uVar16;
                  }
                  plVar11[0x54] = uVar10;
                  uVar16 = devm_clk_get(plVar1,"lpass_audio_hw_vote");
                  uVar10 = 0;
                  if (uVar16 < 0xfffffffffffff001) {
                    uVar10 = uVar16;
                  }
                  *(undefined1 *)(plVar11 + 0x5c) = 0;
                  plVar11[0x55] = uVar10;
                  pm_runtime_set_autosuspend_delay(plVar1,100);
                  __pm_runtime_use_autosuspend(plVar1,1);
                  __pm_runtime_set_status(plVar1,2);
                  pm_runtime_enable(plVar1);
                  _printk(&DAT_00102a26,"lpi_pinctrl_probe");
                  uVar10 = 0;
                  goto LAB_00100c50;
                }
                uVar10 = (ulong)uVar7;
                _printk(&DAT_00102a63,"lpi_pinctrl_probe",uVar10);
              }
              else {
                uVar10 = (ulong)uVar7;
                _dev_err(plVar1,"%s: snd_event registration failed, ret [%d]\n","lpi_pinctrl_probe",
                         uVar10);
              }
            }
            else {
              uVar10 = (ulong)uVar7;
              _dev_err(plVar1,"failed to add pin range\n");
            }
            gpiochip_remove(__dest);
          }
          else {
            uVar10 = (ulong)uVar7;
            _dev_err(*plVar11,"can\'t add gpio chip\n");
          }
        }
        goto LAB_00100c50;
      }
      pcVar17 = "%s devm_ioremap failed\n";
    }
    else {
      lVar20 = devm_ioremap(plVar1,local_74,0x1000);
      if (lVar20 != 0) goto LAB_001009e4;
      pcVar17 = "%s devm_ioremap failed for slew rate reg\n";
    }
    _dev_err(plVar1,pcVar17,"lpi_pinctrl_probe");
  }
LAB_00100c4c:
  uVar10 = 0xfffffff4;
LAB_00100c50:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// lpi_pinctrl_remove @ 00100e40 size=96
// signature: undefined lpi_pinctrl_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_pinctrl_remove(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = param_1 + 0x10;
  lVar2 = *(long *)(param_1 + 0xa8);
  __pm_runtime_disable(lVar1,1);
  __pm_runtime_set_status(lVar1,2);
  snd_event_client_deregister(lVar1);
  audio_notifier_deregister("lpi_tlmm");
  gpiochip_remove(lVar2 + 0x10);
  return 0;
}



//------------------------------------------------------------
// lpi_gpio_get_groups_count @ 00100ea4 size=12
// signature: undefined lpi_gpio_get_groups_count(void)
// callers: []
//------------------------------------------------------------

undefined4 lpi_gpio_get_groups_count(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x10);
}



//------------------------------------------------------------
// lpi_gpio_get_group_name @ 00100eb4 size=24
// signature: undefined lpi_gpio_get_group_name(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_gpio_get_group_name(long param_1,uint param_2)

{
  return *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 8);
}



//------------------------------------------------------------
// lpi_gpio_get_group_pins @ 00100ed0 size=36
// signature: undefined lpi_gpio_get_group_pins(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_gpio_get_group_pins(long param_1,uint param_2,long *param_3,undefined4 *param_4)

{
  *param_3 = *(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18;
  *param_4 = 1;
  return 0;
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map_group @ 00100ef8 size=32
// signature: undefined pinconf_generic_dt_node_to_map_group(void)
// callers: []
//------------------------------------------------------------

void pinconf_generic_dt_node_to_map_group(void)

{
  pinconf_generic_dt_node_to_map();
  return;
}



//------------------------------------------------------------
// lpi_gpio_get_functions_count @ 00100f1c size=8
// signature: undefined lpi_gpio_get_functions_count(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_gpio_get_functions_count(void)

{
  return 6;
}



//------------------------------------------------------------
// lpi_gpio_get_function_name @ 00100f28 size=28
// signature: undefined lpi_gpio_get_function_name(void)
// callers: []
//------------------------------------------------------------

undefined * lpi_gpio_get_function_name(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  
  if (5 < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100f44);
    (*pcVar1)();
  }
  return (&lpi_gpio_functions)[param_2];
}



//------------------------------------------------------------
// lpi_gpio_get_function_groups @ 00100f48 size=32
// signature: undefined lpi_gpio_get_function_groups(void)
// callers: []
//------------------------------------------------------------

undefined8
lpi_gpio_get_function_groups
          (long param_1,undefined8 param_2,undefined8 *param_3,undefined4 *param_4)

{
  *param_3 = &lpi_gpio_groups;
  *param_4 = *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x10);
  return 0;
}



//------------------------------------------------------------
// lpi_gpio_set_mux @ 00100f6c size=100
// signature: undefined lpi_gpio_set_mux(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_gpio_set_mux(long param_1,undefined4 param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (param_3 & 0xffffffff) * 0x18 + 0x10)
  ;
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x38) = param_2;
    uVar1 = lpi_gpio_read(lVar2,0);
    lpi_gpio_write(lVar2,0,uVar1 & 0xffffffc3 | *(int *)(lVar2 + 0x38) << 2);
  }
  return 0;
}



//------------------------------------------------------------
// lpi_gpio_read @ 00100fd0 size=476
// signature: undefined lpi_gpio_read(void)
// callers: [lpi_gpio_dbg_show, lpi_gpio_get, lpi_gpio_set_mux, lpi_config_set]
//------------------------------------------------------------

int lpi_gpio_read(uint *param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (lpi_dev == 0) {
    iVar2 = ___ratelimit(lpi_gpio_read_rtl,"lpi_gpio_read");
    if ((iVar2 == 0) || (iVar2 = ___ratelimit(lpi_gpio_read__rs,"lpi_gpio_read"), iVar2 == 0)) {
      iVar2 = -0x16;
    }
    else {
      _printk(&DAT_00102855,"lpi_gpio_read");
      iVar2 = -0x16;
    }
  }
  else if ((lpi_dev_up & 1) == 0) {
    iVar2 = ___ratelimit(lpi_gpio_read_rtl,"lpi_gpio_read");
    if ((iVar2 == 0) || (iVar2 = ___ratelimit(lpi_gpio_read__rs_32,"lpi_gpio_read"), iVar2 == 0)) {
      iVar2 = 0;
    }
    else {
      _printk(&DAT_00102b36,"lpi_gpio_read");
      iVar2 = 0;
    }
  }
  else {
    lVar5 = *(long *)(lpi_dev + 0x98);
    __pm_runtime_resume(lpi_dev,4);
    lVar1 = lVar5 + 0x2e8;
    mutex_lock(lVar1);
    if (*(char *)(lVar5 + 0x2e0) == '\0') {
      iVar2 = ___ratelimit(lpi_gpio_read_rtl,"lpi_gpio_read");
      if ((iVar2 != 0) && (iVar2 = ___ratelimit(lpi_gpio_read__rs_34,"lpi_gpio_read"), iVar2 != 0))
      {
        _printk(&DAT_00102b5d,"lpi_gpio_read");
      }
      iVar2 = -0x16;
    }
    else {
      iVar2 = readl(*(long *)(param_1 + 4) + (ulong)*param_1 + (ulong)param_2);
      if ((iVar2 < 0) && (iVar3 = ___ratelimit(lpi_gpio_read__rs_36,"lpi_gpio_read"), iVar3 != 0)) {
        _printk(&DAT_00102a98,"lpi_gpio_read",param_2);
      }
    }
    mutex_unlock(lVar1);
    lVar1 = lpi_dev;
    uVar4 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar1 + 0x220) = uVar4;
    __pm_runtime_suspend(lpi_dev,0xd);
  }
  return iVar2;
}



//------------------------------------------------------------
// lpi_gpio_write @ 001011ac size=328
// signature: undefined lpi_gpio_write(void)
// callers: [lpi_gpio_set_mux, lpi_config_set]
//------------------------------------------------------------

void lpi_gpio_write(uint *param_1,uint param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (lpi_dev == 0) {
    iVar2 = ___ratelimit(lpi_gpio_write_rtl,"lpi_gpio_write");
    if ((iVar2 != 0) && (iVar2 = ___ratelimit(lpi_gpio_write__rs,"lpi_gpio_write"), iVar2 != 0)) {
      _printk(&DAT_00102855,"lpi_gpio_write");
    }
  }
  else if (lpi_dev_up == '\x01') {
    lVar4 = *(long *)(lpi_dev + 0x98);
    __pm_runtime_resume(lpi_dev,4);
    lVar1 = lVar4 + 0x2e8;
    mutex_lock(lVar1);
    if (*(char *)(lVar4 + 0x2e0) == '\0') {
      iVar2 = ___ratelimit(lpi_gpio_write_rtl,"lpi_gpio_write");
      if ((iVar2 != 0) && (iVar2 = ___ratelimit(lpi_gpio_write__rs_38,"lpi_gpio_write"), iVar2 != 0)
         ) {
        _printk(&DAT_00102b5d,"lpi_gpio_write");
      }
    }
    else {
      writel(param_3,*(long *)(param_1 + 4) + (ulong)*param_1 + (ulong)param_2);
    }
    mutex_unlock(lVar1);
    lVar1 = lpi_dev;
    uVar3 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar1 + 0x220) = uVar3;
    __pm_runtime_suspend(lpi_dev,0xd);
  }
  return;
}



//------------------------------------------------------------
// readl @ 001012f4 size=140
// signature: undefined readl(void)
// callers: [lpi_gpio_read]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10134c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00101380 size=136
// signature: undefined writel(void)
// callers: [lpi_gpio_write]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101398,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1013d8,uVar1);
  return;
}



//------------------------------------------------------------
// lpi_config_get @ 0010140c size=144
// signature: undefined lpi_config_get(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_config_get(long param_1,uint param_2,ulong *param_3)

{
  bool bVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  uVar2 = 0xffffffea;
  if (0x11 < ((uint)*param_3 & 0xff)) {
    return 0xffffffea;
  }
  uVar3 = *param_3 & 0xff;
  lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 0x10);
  switch(uVar3) {
  case 0:
    uVar4 = 2;
    *(undefined4 *)(lVar5 + 0x30) = 2;
    break;
  case 1:
    uVar4 = 0;
    *(undefined4 *)(lVar5 + 0x30) = 0;
    break;
  default:
    goto switchD_00101450_caseD_2;
  case 3:
    bVar1 = *(int *)(lVar5 + 0x30) == 1;
    goto LAB_00101488;
  case 5:
    bVar1 = *(int *)(lVar5 + 0x30) == 3;
LAB_00101488:
    uVar4 = (ulong)bVar1;
    break;
  case 0xc:
  case 0x11:
    uVar4 = (ulong)*(byte *)(lVar5 + 0xc);
  }
  uVar2 = 0;
  *param_3 = uVar3 | uVar4 << 8;
switchD_00101450_caseD_2:
  return uVar2;
}



//------------------------------------------------------------
// lpi_config_set @ 001014a0 size=1120
// signature: undefined lpi_config_set(void)
// callers: [lpi_gpio_set, lpi_gpio_direction_output, lpi_gpio_direction_input]
//------------------------------------------------------------

void lpi_config_set(long param_1,uint param_2,long param_3,uint param_4)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  uint uVar7;
  uint *puVar8;
  ulong uVar9;
  uint uVar10;
  ulong uVar11;
  ulong local_70 [2];
  
  lVar1 = sp_el0;
  local_70[1] = *(long *)(lVar1 + 0x638);
  local_70[0] = 0;
  puVar8 = *(uint **)(*(long *)(*(long *)(param_1 + 0x10) + 8) + (ulong)param_2 * 0x18 + 0x10);
  if (param_4 != 0) {
    uVar7 = 0;
    lVar1 = *(long *)(*(long *)(param_1 + 0x68) + 0x98) + 0x2b0;
    do {
      uVar11 = *(ulong *)(param_3 + (long)(int)uVar7 * 8);
      uVar10 = (uint)uVar11;
      if (0x18 < (uVar10 & 0xff)) {
switchD_00101550_caseD_2:
        uVar6 = 0xffffffea;
        goto LAB_00101910;
      }
      uVar9 = uVar11 >> 8 & 0xffffff;
      switch(uVar11 & 0xff) {
      case 0:
        puVar8[0xc] = 2;
        break;
      case 1:
        puVar8[0xc] = 0;
        break;
      default:
        goto switchD_00101550_caseD_2;
      case 3:
        puVar8[0xc] = 1;
        break;
      case 5:
        puVar8[0xc] = 3;
        break;
      case 9:
        puVar8[0xd] = (uint)uVar9;
        break;
      case 0xc:
        *(undefined1 *)(puVar8 + 3) = 0;
        break;
      case 0x11:
        *(undefined1 *)(puVar8 + 3) = 1;
        *(bool *)((long)puVar8 + 0xd) = 0xff < uVar10;
        break;
      case 0x18:
        if ((*(long *)(puVar8 + 8) == 0) || (puVar8[2] == 0xffffffff)) goto LAB_00101858;
        if (0x3ff < uVar10) {
          iVar5 = ___ratelimit(lpi_config_set__rs,"lpi_config_set");
          if (iVar5 != 0) {
            _dev_err(*(undefined8 *)(param_1 + 0x68),
                     "%s: invalid slew rate %u for \t\t\t\t\tpin: %d\n","lpi_config_set",uVar9,
                     param_2);
          }
          goto LAB_00101858;
        }
        *(long *)(puVar8 + 4) = *(long *)(puVar8 + 8);
        *puVar8 = 0;
        mutex_lock(lVar1);
        if (*(long *)(puVar8 + 10) == 0) {
          iVar5 = lpi_gpio_read(puVar8,0);
          local_70[0] = (long)iVar5;
          uVar7 = puVar8[2];
          uVar11 = 1L << ((ulong)uVar7 & 0x3f);
          *puVar8 = uVar7;
          if ((uVar10 >> 8 & 1) == 0) {
            puVar2 = local_70 + (uVar7 >> 6);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 & (uVar11 ^ 0xffffffffffffffff);
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
          else {
            puVar2 = local_70 + (uVar7 >> 6);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 | uVar11;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
          uVar7 = *puVar8 + 1;
          uVar11 = 1L << ((ulong)uVar7 & 0x3f);
          *puVar8 = uVar7;
          if ((uVar10 >> 9 & 1) == 0) {
            puVar2 = local_70 + (uVar7 >> 6);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 & (uVar11 ^ 0xffffffffffffffff);
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
          else {
            puVar2 = local_70 + (uVar7 >> 6);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 | uVar11;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
          *puVar8 = 0;
          lpi_gpio_write(puVar8,0,local_70[0]);
          uVar7 = 2;
        }
        else {
          *(long *)(puVar8 + 4) = *(long *)(puVar8 + 10);
          if (puVar8[2] != 0xffffffff) {
            iVar5 = lpi_gpio_read(puVar8,0);
            local_70[0] = (long)iVar5;
            uVar7 = puVar8[2];
            uVar11 = 1L << ((ulong)uVar7 & 0x3f);
            *puVar8 = uVar7;
            if ((uVar10 >> 8 & 1) == 0) {
              puVar2 = local_70 + (uVar7 >> 6);
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar4) {
                  *puVar2 = *puVar2 & (uVar11 ^ 0xffffffffffffffff);
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
            }
            else {
              puVar2 = local_70 + (uVar7 >> 6);
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar4) {
                  *puVar2 = *puVar2 | uVar11;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
            }
            uVar7 = *puVar8 + 1;
            uVar11 = 1L << ((ulong)uVar7 & 0x3f);
            *puVar8 = uVar7;
            if ((uVar10 >> 9 & 1) == 0) {
              puVar2 = local_70 + (uVar7 >> 6);
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar4) {
                  *puVar2 = *puVar2 & (uVar11 ^ 0xffffffffffffffff);
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
            }
            else {
              puVar2 = local_70 + (uVar7 >> 6);
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar4) {
                  *puVar2 = *puVar2 | uVar11;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
            }
            uVar7 = 2;
            *puVar8 = 0;
            uVar9 = local_70[0];
          }
          lpi_gpio_write(puVar8,0,uVar9 & 0xffffffff);
          *(undefined8 *)(puVar8 + 4) = *(undefined8 *)(puVar8 + 8);
        }
        mutex_unlock(lVar1);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_4);
  }
LAB_00101858:
  *(undefined8 *)(puVar8 + 4) = *(undefined8 *)(puVar8 + 6);
  *puVar8 = puVar8[1];
  iVar5 = lpi_gpio_read(puVar8,0);
  uVar7 = puVar8[0xd];
  if (uVar7 < 3) {
    uVar7 = 2;
  }
  if (0xf < uVar7) {
    uVar7 = 0x10;
  }
  local_70[0] = (long)iVar5 & 0xfffffffffffffc3cU | (ulong)puVar8[0xc] |
                (ulong)((uVar7 & 0x1e) * 0x20 - 0x40);
  if ((char)puVar8[3] != '\0') {
    local_70[0] = local_70[0] | (ulong)*(byte *)((long)puVar8 + 0xd) << 9;
  }
  lpi_gpio_write(puVar8,0,local_70[0]);
  lpi_gpio_write(puVar8,4,(ulong)(byte)puVar8[3] << 1);
  uVar6 = 0;
LAB_00101910:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70[1]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// lpi_gpio_direction_input @ 00101974 size=112
// signature: undefined lpi_gpio_direction_input(void)
// callers: []
//------------------------------------------------------------

void lpi_gpio_direction_input(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = 0x10c;
  lpi_config_set(*(undefined8 *)(lVar1 + 8),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpi_gpio_direction_output @ 001019e8 size=120
// signature: undefined lpi_gpio_direction_output(void)
// callers: []
//------------------------------------------------------------

void lpi_gpio_direction_output(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = (ulong)(param_3 << 8 | 0x11);
  lpi_config_set(*(undefined8 *)(lVar1 + 8),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpi_gpio_get @ 00101a64 size=72
// signature: undefined lpi_gpio_get(void)
// callers: []
//------------------------------------------------------------

void lpi_gpio_get(undefined8 param_1,ulong param_2)

{
  long lVar1;
  
  lVar1 = gpiochip_get_data();
  lpi_gpio_read(*(undefined8 *)
                 (*(long *)(*(long *)(*(long *)(lVar1 + 8) + 0x10) + 8) +
                  (param_2 & 0xffffffff) * 0x18 + 0x10),0);
  return;
}



//------------------------------------------------------------
// lpi_gpio_set @ 00101ab0 size=120
// signature: undefined lpi_gpio_set(void)
// callers: []
//------------------------------------------------------------

void lpi_gpio_set(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = gpiochip_get_data();
  local_30 = (ulong)(param_3 << 8 | 0x11);
  lpi_config_set(*(undefined8 *)(lVar1 + 8),param_2,&local_30,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// lpi_gpio_dbg_show @ 00101b2c size=304
// signature: undefined lpi_gpio_dbg_show(void)
// callers: []
//------------------------------------------------------------

void lpi_gpio_dbg_show(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  
  if (*(short *)(param_2 + 0xac) != 0) {
    lVar8 = 0;
    uVar7 = 0;
    do {
      lVar4 = gpiochip_get_data(param_2);
      lVar4 = *(long *)(*(long *)(*(long *)(lVar4 + 8) + 0x10) + 8) + lVar8;
      uVar2 = *(undefined8 *)(lVar4 + 8);
      uVar3 = *(undefined8 *)(lVar4 + 0x10);
      uVar5 = lpi_gpio_read(uVar3,4);
      uVar6 = lpi_gpio_read(uVar3,0);
      puVar1 = &DAT_001029cb;
      if ((uVar5 & 2) != 0) {
        puVar1 = &DAT_001028a5;
      }
      seq_printf(param_1," %-8s: %-3s %d",uVar2,puVar1,(uint)uVar6 >> 2 & 0xf);
      seq_printf(param_1," %dmA",((uint)((uVar6 & 0xffffffff) >> 5) & 0xe) + 2);
      seq_printf(param_1,&DAT_00102a22,(&lpi_gpio_dbg_show_one_pulls)[(uint)uVar6 & 3]);
      seq_puts(param_1,&DAT_00102c2b);
      uVar7 = uVar7 + 1;
      lVar8 = lVar8 + 0x18;
    } while (uVar7 < *(ushort *)(param_2 + 0xac));
  }
  return;
}



//------------------------------------------------------------
// lpi_pinctrl_ssr_enable @ 00101c60 size=152
// signature: undefined lpi_pinctrl_ssr_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_pinctrl_ssr_enable(undefined8 param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (lpi_dev == 0) {
    _dev_err(param_1,"%s: lpi_dev is NULL, return\n","lpi_pinctrl_ssr_enable");
    uVar1 = 0xffffffea;
  }
  else if ((initial_boot & 1) == 0) {
    if ((lpi_dev_up & 1) == 0) {
      lVar2 = *(long *)(lpi_dev + 0x98);
      msleep(100);
      if (*(long *)(lVar2 + 0x2a0) != 0) {
        digital_cdc_rsc_mgr_hw_vote_reset();
      }
      if (*(long *)(lVar2 + 0x2a8) != 0) {
        digital_cdc_rsc_mgr_hw_vote_reset();
      }
    }
    uVar1 = 0;
    lpi_dev_up = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// lpi_pinctrl_ssr_disable @ 00101cfc size=36
// signature: undefined lpi_pinctrl_ssr_disable(void)
// callers: []
//------------------------------------------------------------

void lpi_pinctrl_ssr_disable(void)

{
  lpi_dev_up = 0;
  lpi_pinctrl_suspend();
  return;
}



//------------------------------------------------------------
// lpi_notifier_service_cb @ 00101d24 size=124
// signature: undefined lpi_notifier_service_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 lpi_notifier_service_cb(undefined8 param_1,long param_2)

{
  if (param_2 == 1) {
    if (initial_boot == '\x01') {
      initial_boot = '\0';
    }
    lpi_dev_up = 1;
    snd_event_notify(lpi_dev,1);
  }
  else if (param_2 == 0) {
    if (initial_boot == '\x01') {
      initial_boot = '\0';
    }
    else {
      lpi_dev_up = 0;
    }
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 00101da8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&lpi_pinctrl_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101dd8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&lpi_pinctrl_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00105000 size=1
// signature: undefined mutex_lock(void)
// callers: [lpi_pinctrl_runtime_resume, lpi_pinctrl_suspend, lpi_config_set, lpi_pinctrl_runtime_suspend, lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_disable @ 00105008 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_disable(void)
// callers: [lpi_pinctrl_suspend, lpi_pinctrl_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105010 size=1
// signature: undefined mutex_unlock(void)
// callers: [lpi_pinctrl_runtime_resume, lpi_pinctrl_suspend, lpi_config_set, lpi_pinctrl_runtime_suspend, lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00105018 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [lpi_pinctrl_suspend, lpi_pinctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00105020 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [lpi_pinctrl_suspend, lpi_pinctrl_remove, lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00105028 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [lpi_pinctrl_suspend, lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_enable @ 00105030 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_enable(void)
// callers: [lpi_pinctrl_runtime_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00105038 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [lpi_pinctrl_runtime_resume, lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00105040 size=1
// signature: undefined ___ratelimit(void)
// callers: [lpi_pinctrl_runtime_resume, lpi_config_set, lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105048 size=1
// signature: undefined _dev_err(void)
// callers: [lpi_pinctrl_runtime_resume, lpi_pinctrl_ssr_enable, lpi_pinctrl_probe, lpi_config_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105050 size=1
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
// platform_driver_unregister @ 00105058 size=1
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
// _printk @ 00105060 size=1
// signature: undefined _printk(void)
// callers: [lpi_pinctrl_probe, lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_probe_status @ 00105068 size=1
// signature: undefined audio_notifier_probe_status(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_probe_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00105078 size=1
// signature: undefined devm_kmalloc(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00105080 size=1
// signature: undefined devm_ioremap(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105088 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105090 size=1
// signature: undefined __mutex_init(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_register @ 00105098 size=1
// signature: undefined devm_pinctrl_register(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_data_with_key @ 001050a0 size=1
// signature: undefined gpiochip_add_data_with_key(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_data_with_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_add_pin_range @ 001050a8 size=1
// signature: undefined gpiochip_add_pin_range(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_add_pin_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_register @ 001050b0 size=1
// signature: undefined snd_event_client_register(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_notify @ 001050b8 size=1
// signature: undefined snd_event_notify(void)
// callers: [lpi_notifier_service_cb, lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_register @ 001050c0 size=1
// signature: undefined audio_notifier_register(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiochip_remove @ 001050c8 size=1
// signature: undefined gpiochip_remove(void)
// callers: [lpi_pinctrl_remove, lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001050d0 size=1
// signature: undefined devm_clk_get(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 001050d8 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [lpi_pinctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050e0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [lpi_gpio_set, lpi_gpio_direction_output, lpi_gpio_direction_input, lpi_pinctrl_probe, lpi_config_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_deregister @ 001050e8 size=1
// signature: undefined snd_event_client_deregister(void)
// callers: [lpi_pinctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_deregister @ 001050f0 size=1
// signature: undefined audio_notifier_deregister(void)
// callers: [lpi_pinctrl_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinconf_generic_dt_node_to_map @ 001050f8 size=1
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
// __pm_runtime_resume @ 00105100 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 00105108 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 00105110 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [lpi_gpio_write, lpi_gpio_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00105118 size=1
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
// log_post_read_mmio @ 00105120 size=1
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
// log_write_mmio @ 00105128 size=1
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
// log_post_write_mmio @ 00105130 size=1
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
// gpiochip_get_data @ 00105140 size=1
// signature: undefined gpiochip_get_data(void)
// callers: [lpi_gpio_dbg_show, lpi_gpio_get, lpi_gpio_set, lpi_gpio_direction_output, lpi_gpio_direction_input]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiochip_get_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00105148 size=1
// signature: undefined seq_printf(void)
// callers: [lpi_gpio_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00105150 size=1
// signature: undefined seq_puts(void)
// callers: [lpi_gpio_dbg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00105158 size=1
// signature: undefined msleep(void)
// callers: [lpi_pinctrl_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// digital_cdc_rsc_mgr_hw_vote_reset @ 00105160 size=1
// signature: undefined digital_cdc_rsc_mgr_hw_vote_reset(void)
// callers: [lpi_pinctrl_ssr_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void digital_cdc_rsc_mgr_hw_vote_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



