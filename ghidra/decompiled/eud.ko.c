// Decompiled by Ghidra 12.2
// Program: eud.ko
// Image base: 00100000

//------------------------------------------------------------
// param_eud_set @ 001004b4 size=760
// signature: undefined param_eud_set(void)
// callers: []
//------------------------------------------------------------

void param_eud_set(char *param_1,long param_2)

{
  char cVar1;
  ushort uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  iVar4 = sscanf(param_1,"%du",&local_40);
  cVar1 = eud_ready;
  if ((iVar4 != 1) || (1 < local_40)) {
    uVar5 = 0xffffffea;
    goto LAB_00100720;
  }
  **(uint **)(param_2 + 0x20) = local_40;
  lVar3 = eud_private;
  if (cVar1 == '\x01') {
    if (local_40 == 0) {
      lVar7 = *(long *)(eud_private + 0xa8);
      if (*(char *)(lVar7 + 0x291) != '\0') {
        extcon_set_state(*(undefined8 *)(lVar7 + 0x20),0x3d,0);
        extcon_set_state_sync(*(undefined8 *)(lVar7 + 0x20),1,0);
        writel_relaxed(0,*(long *)(lVar7 + 0x18) + 0x1014);
        if ((*(char *)(lVar7 + 0x270) == '\0') ||
           (iVar4 = qcom_scm_io_writel(*(undefined8 *)(lVar7 + 0x278),0), iVar4 == 0)) {
          cVar1 = *(char *)(lVar7 + 0x290);
        }
        else {
          _dev_err(lVar3 + 0x10,"qcom_scm_io_write failed with rc:%d\n",iVar4);
          cVar1 = *(char *)(lVar7 + 0x290);
        }
        if (cVar1 != '\0') {
          uVar5 = *(undefined8 *)(lVar7 + 0x288);
          clk_disable(uVar5);
          clk_unprepare(uVar5);
          *(undefined1 *)(lVar7 + 0x290) = 0;
        }
        usleep_range_state(0x32,100,2);
        extcon_set_state_sync(*(undefined8 *)(lVar7 + 0x20),1,1);
        uVar5 = 0;
        *(undefined1 *)(lVar7 + 0x291) = 0;
        goto LAB_00100720;
      }
    }
    else if ((local_40 == 1) &&
            (puVar6 = *(undefined8 **)(eud_private + 0xa8), *(char *)((long)puVar6 + 0x291) == '\0')
            ) {
      extcon_set_state_sync(puVar6[4],1,1);
      extcon_set_state(puVar6[4],0x3d,0);
      extcon_set_state_sync(puVar6[4],1,0);
      if (*(char *)(puVar6 + 0x52) == '\x01') {
LAB_001005a8:
        uVar2 = *(ushort *)((long)puVar6 + 0x292);
      }
      else {
        uVar5 = puVar6[0x51];
        iVar4 = clk_prepare(uVar5);
        if (iVar4 == 0) {
          iVar4 = clk_enable(uVar5);
          if (iVar4 == 0) {
            *(undefined1 *)(puVar6 + 0x52) = 1;
            goto LAB_001005a8;
          }
          clk_unprepare(uVar5);
        }
        _dev_err(*puVar6,"Failed to enable eud_clkref_clk\n");
        uVar2 = *(ushort *)((long)puVar6 + 0x292);
      }
      if (uVar2 != 0) {
        writew_relaxed(uVar2 >> 8,puVar6[3] + 0x1034);
        writew_relaxed(*(undefined1 *)((long)puVar6 + 0x292),puVar6[3] + 0x1030);
      }
      writel_relaxed(1,puVar6[3] + 0x1014);
      writel_relaxed(0x1c,puVar6[3] + 0x24);
      if (*(char *)(puVar6 + 0x4e) != '\0') {
        local_3c = 0;
        qcom_scm_io_readl(puVar6[0x4f],&local_3c);
        if (((local_3c & 1) == 0) && (iVar4 = qcom_scm_io_writel(puVar6[0x4f],1), iVar4 != 0)) {
          _dev_err(lVar3 + 0x10,"qcom_scm_io_writel failed with rc:%d\n",iVar4);
        }
      }
      DataSynchronizationBarrier(3,2,0);
      usleep_range_state(0x32,100,2);
      extcon_set_state_sync(puVar6[4],1,1);
      extcon_set_state_sync(puVar6[4],5,1);
      uVar5 = 0;
      *(undefined1 *)((long)puVar6 + 0x291) = 1;
      goto LAB_00100720;
    }
  }
  uVar5 = 0;
LAB_00100720:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 001007ac size=132
// signature: undefined writel_relaxed(void)
// callers: [handle_eud_irq, eud_config_port, eud_shutdown, eud_stop_rx, eud_stop_tx, param_eud_set, msm_eud_probe, eud_startup, eud_start_tx]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1007c4,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100800,uVar1);
  return;
}



//------------------------------------------------------------
// writew_relaxed @ 00100830 size=132
// signature: undefined writew_relaxed(void)
// callers: [param_eud_set, msm_eud_probe]
//------------------------------------------------------------

void writew_relaxed(undefined2 param_1,undefined2 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x10,param_2,0x10084c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x10,param_2,0x100884,uVar1);
  return;
}



//------------------------------------------------------------
// msm_eud_probe @ 001008b8 size=1448
// signature: undefined msm_eud_probe(void)
// callers: []
//------------------------------------------------------------

ulong msm_eud_probe(long param_1)

{
  ushort *puVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  ulong uVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 *puVar13;
  char *pcVar14;
  undefined8 uVar15;
  long lVar16;
  uint local_4c;
  long local_48;
  
  lVar9 = sp_el0;
  lVar16 = param_1 + 0x10;
  local_48 = *(long *)(lVar9 + 0x638);
  plVar7 = (long *)devm_kmalloc(lVar16,0x298,0xdc0);
  if (plVar7 == (long *)0x0) {
LAB_00100d48:
    uVar8 = 0xfffffff4;
    goto LAB_00100d4c;
  }
  *(long **)(param_1 + 0xa8) = plVar7;
  *plVar7 = lVar16;
  uVar8 = devm_extcon_dev_allocate(lVar16,eud_extcon_cable);
  plVar7[4] = uVar8;
  if (0xfffffffffffff000 < uVar8) {
    _dev_err(*plVar7,"%s: failed to allocate extcon device\n","msm_eud_probe");
    uVar8 = (ulong)*(uint *)(plVar7 + 4);
    goto LAB_00100d4c;
  }
  uVar3 = devm_extcon_dev_register(lVar16,uVar8);
  if (uVar3 != 0) {
    uVar8 = (ulong)uVar3;
    _dev_err(*plVar7,"%s: failed to register extcon device\n","msm_eud_probe");
    goto LAB_00100d4c;
  }
  lVar9 = platform_get_resource_byname(param_1,0x200,"eud_base");
  if (lVar9 == 0) {
    lVar16 = *plVar7;
    pcVar14 = "%s: failed to get resource eud_base\n";
LAB_00100d3c:
    _dev_err(lVar16,pcVar14,"msm_eud_probe");
    goto LAB_00100d48;
  }
  uVar8 = devm_ioremap_resource(lVar16,lVar9);
  plVar7[3] = uVar8;
  if (0xfffffffffffff000 < uVar8) goto LAB_00100d4c;
  uVar4 = platform_get_irq_byname(param_1,"eud_irq");
  uVar15 = *(undefined8 *)(param_1 + 0x2f8);
  *(undefined4 *)(plVar7 + 1) = uVar4;
  lVar9 = of_find_property(uVar15,"qcom,secure-eud-en",0);
  *(bool *)(plVar7 + 0x4e) = lVar9 != 0;
  if (lVar9 != 0) {
    plVar10 = (long *)platform_get_resource_byname(param_1,0x200,"eud_mode_mgr2");
    if (plVar10 == (long *)0x0) {
      lVar16 = *plVar7;
      pcVar14 = "%s: failed to get resource eud_mode_mgr2\n";
      goto LAB_00100d3c;
    }
    plVar7[0x4f] = *plVar10;
  }
  lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,eud-clock-vote-req",0);
  *(bool *)((long)plVar7 + 0x271) = lVar9 != 0;
  if (lVar9 != 0) {
    uVar11 = devm_clk_get(lVar16,"eud_ahb2phy_clk");
    plVar7[0x50] = uVar11;
    if (0xfffffffffffff000 < uVar11) {
      uVar8 = uVar11 & 0xffffffff;
      goto LAB_00100d4c;
    }
    uVar12 = clk_prepare(uVar11);
    uVar8 = uVar12 & 0xffffffff;
    if ((int)uVar12 != 0) goto LAB_00100d4c;
    uVar3 = clk_enable(uVar11);
    if (uVar3 != 0) {
      uVar8 = (ulong)uVar3;
      clk_unprepare(uVar11);
      goto LAB_00100d4c;
    }
  }
  uVar11 = devm_clk_get(lVar16,"eud_clkref_clk");
  uVar8 = 0;
  if (uVar11 < 0xfffffffffffff001) {
    uVar8 = uVar11;
  }
  plVar7[0x51] = uVar8;
  uVar3 = devm_request_threaded_irq(lVar16,(int)plVar7[1],handle_eud_irq,0,4,"eud_irq",plVar7);
  if (uVar3 == 0) {
    puVar1 = (ushort *)((long)plVar7 + 0x292);
    uVar5 = of_property_read_variable_u16_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,eud-utmi-delay",puVar1,1,0);
    uVar3 = uVar5;
    if (-1 < (int)uVar5) {
      uVar3 = 0;
    }
    uVar8 = (ulong)uVar3;
    if (((int)uVar5 < 0) || (*puVar1 < 0x1c)) {
      *puVar1 = 0;
    }
    device_set_wakeup_capable(lVar16,1);
    device_wakeup_enable(lVar16);
    irq_set_irq_wake((int)plVar7[1],1);
    plVar7[0x47] = 0xfffffffe0;
    plVar7[0x48] = (long)(plVar7 + 0x48);
    plVar7[0x49] = (long)(plVar7 + 0x48);
    *(undefined4 *)(plVar7 + 0x29) = 300;
    plVar7[0x4a] = (long)eud_event_notifier;
    *(undefined4 *)((long)plVar7 + 0xdc) = 0xe;
    *(undefined1 *)((long)plVar7 + 0xe2) = 2;
    plVar7[0x2f] = *plVar7;
    uVar15 = *(undefined8 *)(param_1 + 0x2f8);
    plVar7[0x26] = 0x10000000;
    *(int *)(plVar7 + 0x19) = (int)plVar7[1];
    plVar7[7] = plVar7[3];
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined4 *)((long)plVar7 + 0x15c) = 0;
    plVar7[0x2a] = (long)&eud_uart_ops;
    lVar9 = of_find_property(uVar15,"qcom,eud-tcsr-check-enable",0);
    if (lVar9 != 0) {
      puVar13 = (undefined8 *)platform_get_resource_byname(param_1,0x200,"eud_tcsr_check_reg");
      if (puVar13 == (undefined8 *)0x0) {
        pcVar14 = "Failed to get resource for tcsr check!\n";
        goto LAB_00100da8;
      }
      iVar6 = qcom_scm_io_writel(*puVar13,1);
      if (iVar6 != 0) {
        _dev_err(lVar16,"TCSR qcom_scm_io_writel failed with rc:%d\n",iVar6);
      }
    }
    if ((char)plVar7[0x4e] != '\0') {
      local_4c = 0;
      qcom_scm_io_readl(plVar7[0x4f],&local_4c);
      if ((local_4c & 1) != 0) {
        enable = 1;
      }
    }
    uVar3 = uart_add_one_port(&eud_uart_driver,plVar7 + 5);
    if (uVar3 == 0) {
      lVar9 = *(long *)(param_1 + 0xa8);
      local_4c = 0;
      eud_ready = 1;
      eud_private = param_1;
      if (*(char *)(lVar9 + 0x270) == '\0') {
        uVar8 = readl_relaxed(*(long *)(lVar9 + 0x18) + 0x1014);
        if ((uVar8 & 1) == 0) {
LAB_00100d18:
          uVar8 = 0;
          goto LAB_00100d4c;
        }
      }
      else {
        iVar6 = qcom_scm_io_readl(*(undefined8 *)(lVar9 + 0x278),&local_4c);
        if (iVar6 != 0) {
          _dev_err(lVar16,"qcom_scm_io_readl failed with rc: %d\n",iVar6);
          uVar8 = 0;
          goto LAB_00100d4c;
        }
        if (local_4c == 0) goto LAB_00100d18;
      }
      if ((char)plVar7[0x52] == '\x01') {
LAB_00100c40:
        uVar2 = *puVar1;
      }
      else {
        lVar9 = plVar7[0x51];
        iVar6 = clk_prepare(lVar9);
        if (iVar6 == 0) {
          iVar6 = clk_enable(lVar9);
          if (iVar6 == 0) {
            *(undefined1 *)(plVar7 + 0x52) = 1;
            goto LAB_00100c40;
          }
          clk_unprepare(lVar9);
        }
        _dev_err(*plVar7,"Failed to enable eud_clkref_clk\n");
        uVar2 = *puVar1;
      }
      if (uVar2 != 0) {
        writew_relaxed(uVar2 >> 8,plVar7[3] + 0x1034);
        writew_relaxed(*(undefined1 *)((long)plVar7 + 0x292),plVar7[3] + 0x1030);
      }
      writel_relaxed(0x1c,plVar7[3] + 0x24);
      iVar6 = extcon_set_state_sync(plVar7[4],1,1);
      if (iVar6 != 0) {
        _dev_warn(lVar16,"Failed to set EXTCON_USB (%d)\n",iVar6);
      }
      iVar6 = extcon_set_state_sync(plVar7[4],5,1);
      if (iVar6 != 0) {
        _dev_warn(lVar16,"Failed to set EXTCON_CHG_USB_SDP (%d)\n",iVar6);
      }
      uVar8 = 0;
      *(undefined1 *)((long)plVar7 + 0x291) = 1;
      enable = 1;
      goto LAB_00100d4c;
    }
    uVar8 = (ulong)uVar3;
    pcVar14 = "failed to add uart port!\n";
  }
  else {
    uVar8 = (ulong)uVar3;
    pcVar14 = "request failed for eud irq\n";
  }
LAB_00100da8:
  _dev_err(*plVar7,pcVar14);
  if ((*(char *)((long)plVar7 + 0x271) != '\0') && (lVar16 = plVar7[0x50], lVar16 != 0)) {
    clk_disable(lVar16);
    clk_unprepare(lVar16);
  }
LAB_00100d4c:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// msm_eud_remove @ 00100e64 size=124
// signature: undefined msm_eud_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eud_remove(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  if (puVar2[0x4d] != 0) {
    power_supply_put();
  }
  uart_remove_one_port(&eud_uart_driver,puVar2 + 5);
  uVar1 = *puVar2;
  device_wakeup_disable(uVar1);
  device_set_wakeup_capable(uVar1,0);
  if (*(char *)((long)puVar2 + 0x271) != '\0') {
    uVar1 = puVar2[0x50];
    clk_disable(uVar1);
    clk_unprepare(uVar1);
  }
  return 0;
}



//------------------------------------------------------------
// handle_eud_irq @ 00100ee4 size=788
// signature: undefined handle_eud_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool handle_eud_irq(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  long lVar9;
  
  uVar3 = readl_relaxed(*(long *)(param_2 + 0x18) + 0x24);
  uVar4 = readb_relaxed(*(long *)(param_2 + 0x18) + 0x44);
  uVar7 = uVar4;
  if ((uVar4 & 1) != 0) {
    iVar6 = readl_relaxed(*(long *)(param_2 + 0x18) + 0xc);
    if (iVar6 == 0x90) {
      lVar9 = param_2 + 0x28;
      _raw_spin_lock(lVar9);
      for (iVar6 = readl_relaxed(*(long *)(param_2 + 0x18) + 0x10); iVar6 != 0; iVar6 = iVar6 + -1)
      {
        cVar2 = readl_relaxed(*(long *)(param_2 + 0x18) + 0x14);
        *(int *)(param_2 + 0x108) = *(int *)(param_2 + 0x108) + 1;
        if (*(long *)(param_2 + 0x180) == 0) {
LAB_00100f7c:
          uart_insert_char(lVar9,0,0,cVar2,0);
        }
        else {
          if ((cVar2 == '\0') || (-1 < _jiffies - *(long *)(param_2 + 0x180))) {
LAB_00100f78:
            *(undefined8 *)(param_2 + 0x180) = 0;
            goto LAB_00100f7c;
          }
          iVar5 = sysrq_mask();
          if (iVar5 == 0) {
            uVar8 = uart_try_toggle_sysrq(lVar9,cVar2);
            if ((uVar8 & 1) == 0) goto LAB_00100f78;
          }
          else {
            handle_sysrq(cVar2);
            *(undefined8 *)(param_2 + 0x180) = 0;
          }
        }
      }
      _raw_spin_unlock(lVar9);
      tty_flip_buffer_push(*(undefined8 *)(param_2 + 0xf0));
    }
    uVar7 = uVar4 & 0xfffffffe;
  }
  if ((uVar4 >> 1 & 1) == 0) {
    uVar3 = uVar7;
  }
  else {
    if ((uVar3 >> 1 & 1) != 0) {
      lVar9 = *(long *)(param_2 + 0xf0);
      writel_relaxed(0x90,*(undefined8 *)(param_2 + 0x18));
      iVar6 = readl_relaxed(*(undefined8 *)(param_2 + 0x18));
      if (iVar6 == 0x90) {
        _raw_spin_lock(param_2 + 0x28);
        uVar3 = *(int *)(lVar9 + 0x1d0) - *(int *)(lVar9 + 0x1d4) & 0xfff;
        if (uVar3 != 0) {
          if (*(uint *)(param_2 + 0xdc) <= uVar3) {
            uVar3 = *(uint *)(param_2 + 0xdc);
          }
          for (; uVar3 != 0; uVar3 = uVar3 - 1) {
            writel_relaxed(*(undefined1 *)(*(long *)(lVar9 + 0x1c8) + (long)*(int *)(lVar9 + 0x1d4))
                           ,*(long *)(param_2 + 0x38) + 8);
            *(uint *)(lVar9 + 0x1d4) = *(int *)(lVar9 + 0x1d4) + 1U & 0xfff;
            *(int *)(param_2 + 0x10c) = *(int *)(param_2 + 0x10c) + 1;
          }
        }
        _raw_spin_unlock(param_2 + 0x28);
      }
    }
    uVar3 = uVar7 & 0xfffffffd;
  }
  if ((uVar7 >> 2 & 1) == 0) {
    uVar7 = uVar3;
  }
  else {
    *(undefined8 *)(param_2 + 0xc) = 0x400000001;
    uVar7 = readl_relaxed(*(long *)(param_2 + 0x18) + 0x74);
    uVar1 = _system_wq;
    *(byte *)(param_2 + 0x14) = (byte)(uVar7 >> 4) & 1;
    queue_work_on(0x20,uVar1,param_2 + 0x238);
    writel_relaxed(1,*(long *)(param_2 + 0x18) + 0x80);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_2 + 0x18) + 0x80);
    uVar7 = uVar3 & 0xfffffffb;
  }
  if ((uVar3 >> 3 & 1) == 0) {
    uVar3 = uVar7;
  }
  else {
    *(undefined8 *)(param_2 + 0xc) = 0x800000005;
    uVar3 = readl_relaxed(*(long *)(param_2 + 0x18) + 0x74);
    uVar1 = _system_wq;
    *(byte *)(param_2 + 0x15) = (byte)(uVar3 >> 6) & 1;
    queue_work_on(0x20,uVar1,param_2 + 0x238);
    writel_relaxed(1,*(long *)(param_2 + 0x18) + 0x84);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0,*(long *)(param_2 + 0x18) + 0x84);
    uVar3 = uVar7 & 0xfffffff7;
  }
  if ((uVar7 >> 4 & 1) != 0) {
    uVar8 = readl_relaxed(*(long *)(param_2 + 0x18) + 0x1018);
    lVar9 = *(long *)(param_2 + 0x18) + 0x1018;
    if ((uVar8 & 1) == 0) {
      writel_relaxed(1,lVar9);
      DataSynchronizationBarrier(3,2,0);
    }
    else {
      writel_relaxed(0,lVar9);
      DataSynchronizationBarrier(3,2,0);
      __const_udelay(0x68dbc);
      writel_relaxed(1,*(long *)(param_2 + 0x18) + 0x1018);
      DataSynchronizationBarrier(3,2,0);
    }
    uVar3 = uVar3 & 0xffffffef;
  }
  return (uVar3 & 0xff) == 0;
}



//------------------------------------------------------------
// eud_event_notifier @ 001011fc size=252
// signature: undefined eud_event_notifier(void)
// callers: []
//------------------------------------------------------------

void eud_event_notifier(long param_1)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  if (*(int *)(param_1 + -0x228) == 8) {
    lVar2 = *(long *)(param_1 + 0x30);
    if (lVar2 == 0) {
      lVar2 = power_supply_get_by_name(&DAT_00101ed9);
      *(long *)(param_1 + 0x30) = lVar2;
      if (lVar2 == 0) goto LAB_001012b0;
    }
    uVar3 = 0;
    if (*(char *)(param_1 + -0x223) != '\0') {
      uVar3 = 0xffffffea;
    }
    local_30 = CONCAT44(local_30._4_4_,uVar3);
    iVar1 = power_supply_set_property(lVar2,0x26,&local_30);
    if (iVar1 < 0) {
      _dev_err(*(undefined8 *)(param_1 + -0x238),"Failed to set the powersupply property: %d\n",
               iVar1);
    }
  }
  else if (*(int *)(param_1 + -0x228) == 4) {
    extcon_set_state(*(undefined8 *)(param_1 + -0x218),0x3d,1);
    extcon_set_state_sync
              (*(undefined8 *)(param_1 + -0x218),*(undefined4 *)(param_1 + -0x22c),
               *(undefined1 *)(param_1 + -0x224));
  }
LAB_001012b0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001012f8 size=124
// signature: undefined readl_relaxed(void)
// callers: [handle_eud_irq, msm_eud_probe, eud_tx_empty]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101340,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readb_relaxed @ 00101374 size=124
// signature: undefined readb_relaxed(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

undefined1 readb_relaxed(undefined1 *param_1)

{
  ulong uVar1;
  undefined1 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(8,param_1,readb_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,8,param_1,0x1013bc,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// eud_tx_empty @ 001013f4 size=40
// signature: undefined eud_tx_empty(void)
// callers: []
//------------------------------------------------------------

uint eud_tx_empty(long param_1)

{
  uint uVar1;
  
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x10) + 0x44);
  return uVar1 >> 1 & 1;
}



//------------------------------------------------------------
// eud_set_mctrl @ 00101420 size=4
// signature: undefined eud_set_mctrl(void)
// callers: []
//------------------------------------------------------------

void eud_set_mctrl(void)

{
  return;
}



//------------------------------------------------------------
// eud_get_mctrl @ 00101428 size=8
// signature: undefined eud_get_mctrl(void)
// callers: []
//------------------------------------------------------------

undefined8 eud_get_mctrl(void)

{
  return 0;
}



//------------------------------------------------------------
// eud_stop_tx @ 00101434 size=44
// signature: undefined eud_stop_tx(void)
// callers: []
//------------------------------------------------------------

void eud_stop_tx(long param_1)

{
  writel_relaxed(0xfffffffd,*(long *)(param_1 + 0x10) + 0x44);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// eud_start_tx @ 00101464 size=44
// signature: undefined eud_start_tx(void)
// callers: []
//------------------------------------------------------------

void eud_start_tx(long param_1)

{
  writel_relaxed(2,*(long *)(param_1 + 0x10) + 0x44);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// eud_stop_rx @ 00101494 size=44
// signature: undefined eud_stop_rx(void)
// callers: []
//------------------------------------------------------------

void eud_stop_rx(long param_1)

{
  writel_relaxed(0xfffffffe,*(long *)(param_1 + 0x10) + 0x44);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// eud_startup @ 001014c4 size=48
// signature: undefined eud_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 eud_startup(long param_1)

{
  writel_relaxed(1,*(long *)(param_1 + 0x10) + 0x44);
  DataSynchronizationBarrier(3,2,0);
  return 0;
}



//------------------------------------------------------------
// eud_shutdown @ 001014f8 size=44
// signature: undefined eud_shutdown(void)
// callers: []
//------------------------------------------------------------

void eud_shutdown(long param_1)

{
  writel_relaxed(0xffffffff,*(long *)(param_1 + 0x10) + 0x44);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// eud_set_termios @ 00101528 size=4
// signature: undefined eud_set_termios(void)
// callers: []
//------------------------------------------------------------

void eud_set_termios(void)

{
  return;
}



//------------------------------------------------------------
// eud_type @ 00101530 size=24
// signature: undefined eud_type(void)
// callers: []
//------------------------------------------------------------

char * eud_type(long param_1)

{
  char *pcVar1;
  
  pcVar1 = "EUD UART";
  if (*(int *)(param_1 + 0x120) != 300) {
    pcVar1 = (char *)0x0;
  }
  return pcVar1;
}



//------------------------------------------------------------
// eud_release_port @ 0010154c size=4
// signature: undefined eud_release_port(void)
// callers: []
//------------------------------------------------------------

void eud_release_port(void)

{
  return;
}



//------------------------------------------------------------
// eud_request_port @ 00101554 size=8
// signature: undefined eud_request_port(void)
// callers: []
//------------------------------------------------------------

undefined8 eud_request_port(void)

{
  return 0;
}



//------------------------------------------------------------
// eud_config_port @ 00101560 size=52
// signature: undefined eud_config_port(void)
// callers: []
//------------------------------------------------------------

void eud_config_port(long param_1)

{
  *(undefined4 *)(param_1 + 0x120) = 300;
  writel_relaxed(0xffffffff,*(long *)(param_1 + 0x10) + 0x44);
  DataSynchronizationBarrier(3,2,0);
  return;
}



//------------------------------------------------------------
// eud_verify_port @ 00101598 size=24
// signature: undefined eud_verify_port(void)
// callers: []
//------------------------------------------------------------

undefined4 eud_verify_port(undefined8 param_1,int *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*param_2 != 300 && *param_2 != 0) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_eud_suspend @ 001015b4 size=72
// signature: undefined msm_eud_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_eud_suspend(long param_1)

{
  long lVar1;
  
  if ((*(char *)(*(long *)(param_1 + 0x98) + 0x271) != '\0') &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0x280), lVar1 != 0)) {
    clk_disable(lVar1);
    clk_unprepare(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// msm_eud_resume @ 00101600 size=144
// signature: undefined msm_eud_resume(void)
// callers: []
//------------------------------------------------------------

int msm_eud_resume(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  if ((*(char *)((long)puVar3 + 0x271) == '\0') || (lVar2 = puVar3[0x50], lVar2 == 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = clk_prepare(lVar2);
    if (iVar1 == 0) {
      iVar1 = clk_enable(lVar2);
      if (iVar1 == 0) {
        return 0;
      }
      clk_unprepare(lVar2);
    }
    _dev_err(*puVar3,"%s failed to vote ahb2phy clk %d\n","msm_eud_resume",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 0010169c size=144
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = uart_register_driver(&eud_uart_driver);
  if (iVar1 == 0) {
    iVar1 = __platform_driver_register(&msm_eud_driver,&__this_module);
    if (iVar1 != 0) {
      _printk(&DAT_00101cde,"msm_eud_init");
      uart_unregister_driver(&eud_uart_driver);
    }
  }
  else {
    _printk(&DAT_00101cb4,"msm_eud_init");
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00101730 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_eud_driver);
  uart_unregister_driver(&eud_uart_driver);
  return;
}



//------------------------------------------------------------
// uart_register_driver @ 00104000 size=1
// signature: undefined uart_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104008 size=1
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
// _printk @ 00104010 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_unregister_driver @ 00104018 size=1
// signature: undefined uart_unregister_driver(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_unregister_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00104020 size=1
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
// sscanf @ 00104028 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [param_eud_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_set_state_sync @ 00104030 size=1
// signature: undefined extcon_set_state_sync(void)
// callers: [eud_event_notifier, param_eud_set, msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_set_state_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_set_state @ 00104038 size=1
// signature: undefined extcon_set_state(void)
// callers: [eud_event_notifier, param_eud_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_set_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00104040 size=1
// signature: undefined clk_prepare(void)
// callers: [param_eud_set, msm_eud_probe, msm_eud_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00104048 size=1
// signature: undefined clk_enable(void)
// callers: [param_eud_set, msm_eud_probe, msm_eud_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 00104050 size=1
// signature: undefined qcom_scm_io_readl(void)
// callers: [param_eud_set, msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_readl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 00104058 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [param_eud_set, msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00104060 size=1
// signature: undefined usleep_range_state(void)
// callers: [param_eud_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00104068 size=1
// signature: undefined clk_disable(void)
// callers: [msm_eud_remove, msm_eud_suspend, param_eud_set, msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00104070 size=1
// signature: undefined clk_unprepare(void)
// callers: [msm_eud_remove, msm_eud_suspend, param_eud_set, msm_eud_probe, msm_eud_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104078 size=1
// signature: undefined _dev_err(void)
// callers: [eud_event_notifier, param_eud_set, msm_eud_probe, msm_eud_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [eud_event_notifier, param_eud_set, msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00104088 size=1
// signature: undefined log_write_mmio(void)
// callers: [writew_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00104090 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writew_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104098 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_allocate @ 001040a0 size=1
// signature: undefined devm_extcon_dev_allocate(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_allocate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_extcon_dev_register @ 001040a8 size=1
// signature: undefined devm_extcon_dev_register(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_extcon_dev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 001040b0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001040b8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 001040c0 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001040c8 size=1
// signature: undefined of_find_property(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001040d0 size=1
// signature: undefined devm_clk_get(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001040d8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u16_array @ 001040e0 size=1
// signature: undefined of_property_read_variable_u16_array(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u16_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001040e8 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [msm_eud_remove, msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 001040f0 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001040f8 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_add_one_port @ 00104100 size=1
// signature: undefined uart_add_one_port(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_add_one_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00104108 size=1
// signature: undefined _dev_warn(void)
// callers: [msm_eud_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 00104110 size=1
// signature: undefined power_supply_put(void)
// callers: [msm_eud_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_remove_one_port @ 00104118 size=1
// signature: undefined uart_remove_one_port(void)
// callers: [msm_eud_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_remove_one_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00104120 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [msm_eud_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00104128 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_insert_char @ 00104138 size=1
// signature: undefined uart_insert_char(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_insert_char(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysrq_mask @ 00104140 size=1
// signature: undefined sysrq_mask(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysrq_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// handle_sysrq @ 00104148 size=1
// signature: undefined handle_sysrq(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void handle_sysrq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// uart_try_toggle_sysrq @ 00104150 size=1
// signature: undefined uart_try_toggle_sysrq(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void uart_try_toggle_sysrq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00104158 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tty_flip_buffer_push @ 00104160 size=1
// signature: undefined tty_flip_buffer_push(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tty_flip_buffer_push(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104170 size=1
// signature: undefined queue_work_on(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00104178 size=1
// signature: undefined __const_udelay(void)
// callers: [handle_eud_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00104180 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [eud_event_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_set_property @ 00104188 size=1
// signature: undefined power_supply_set_property(void)
// callers: [eud_event_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_set_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00104190 size=1
// signature: undefined log_read_mmio(void)
// callers: [readb_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00104198 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readb_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



