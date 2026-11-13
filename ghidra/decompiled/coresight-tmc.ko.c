// Decompiled by Ghidra 12.2
// Program: coresight-tmc.ko
// Image base: 00100000

//------------------------------------------------------------
// tmc_wait_for_tmcready @ 00101824 size=84
// signature: undefined tmc_wait_for_tmcready(void)
// callers: [tmc_enable_etf_link, __tmc_etr_enable_hw, __tmc_etb_enable_hw]
//------------------------------------------------------------

undefined8 tmc_wait_for_tmcready(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 8);
  uVar1 = coresight_timeout(lVar2 + 0x20,0xc,2,1);
  if ((int)uVar1 != 0) {
    _dev_err(lVar2 + 0x38,"timeout while waiting for TMC to be Ready\n");
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}



//------------------------------------------------------------
// tmc_flush_and_stop @ 0010187c size=192
// signature: undefined tmc_flush_and_stop(void)
// callers: [tmc_update_etf_buffer, __tmc_etr_disable_hw, __tmc_etb_disable_hw, tmc_update_etr_buffer, tmc_disable_etf_link]
//------------------------------------------------------------

void tmc_flush_and_stop(long *param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = param_1[1];
  uVar1 = readl_relaxed(*param_1 + 0x304);
  writel_relaxed(uVar1 | 0x1000,*param_1 + 0x304);
  writel_relaxed(uVar1 | 0x1040,*param_1 + 0x304);
  iVar2 = coresight_timeout(lVar3 + 0x20,0x304,6,0);
  if (iVar2 != 0) {
    _dev_err(lVar3 + 0x38,"timeout while waiting for completion of Manual Flush\n");
  }
  lVar3 = param_1[1];
  iVar2 = coresight_timeout(lVar3 + 0x20,0xc,2,1);
  if (iVar2 != 0) {
    _dev_err(lVar3 + 0x38,"timeout while waiting for TMC to be Ready\n");
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 0010193c size=124
// signature: undefined readl_relaxed(void)
// callers: [tmc_probe, tmc_flush_and_stop]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101984,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 001019b8 size=132
// signature: undefined writel_relaxed(void)
// callers: [tmc_flush_and_stop, tmc_disable_hw, tmc_enable_hw]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1019d0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x101a0c,uVar1);
  return;
}



//------------------------------------------------------------
// tmc_disable_stop_on_flush @ 00101a40 size=8
// signature: undefined tmc_disable_stop_on_flush(void)
// callers: [__tmc_etr_disable_hw, __tmc_etb_disable_hw]
//------------------------------------------------------------

void tmc_disable_stop_on_flush(long param_1)

{
  *(undefined1 *)(param_1 + 0x148) = 0;
  return;
}



//------------------------------------------------------------
// tmc_enable_hw @ 00101a4c size=40
// signature: undefined tmc_enable_hw(void)
// callers: [tmc_enable_etf_link, __tmc_etr_enable_hw, __tmc_etb_enable_hw]
//------------------------------------------------------------

void tmc_enable_hw(long *param_1)

{
  writel_relaxed(1,*param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// tmc_disable_hw @ 00101a78 size=40
// signature: undefined tmc_disable_hw(void)
// callers: [__tmc_etr_disable_hw, __tmc_etb_disable_hw, tmc_disable_etf_link]
//------------------------------------------------------------

void tmc_disable_hw(long *param_1)

{
  writel_relaxed(0,*param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// tmc_get_memwidth_mask @ 00101aa4 size=40
// signature: undefined tmc_get_memwidth_mask(void)
// callers: [tmc_update_etf_buffer, tmc_update_etr_buffer]
//------------------------------------------------------------

undefined4 tmc_get_memwidth_mask(long param_1)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 0x8c) - 1;
  if (uVar1 < 8) {
    return *(undefined4 *)(&DAT_001093e0 + (long)(int)uVar1 * 4);
  }
  return 0;
}



//------------------------------------------------------------
// tmc_probe @ 00101ad0 size=1144
// signature: undefined tmc_probe(void)
// callers: []
//------------------------------------------------------------

ulong tmc_probe(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulong *puVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  ulong uVar10;
  undefined4 uVar11;
  long *plVar12;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined **local_98;
  ulong local_90;
  long local_88;
  undefined **local_80;
  ulong local_78;
  undefined8 local_70;
  ulong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  local_68 = 0;
  local_80 = (undefined **)0x0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_a0 = 0;
  local_98 = (undefined **)0x0;
  local_a8 = 0;
  puVar6 = (ulong *)devm_kmalloc(param_1,0x150,0xdc0);
  if (puVar6 != (ulong *)0x0) {
    *(ulong **)(param_1 + 0x98) = puVar6;
    uVar7 = devm_ioremap_resource(param_1,param_1 + 0x390);
    if (0xfffffffffffff000 < uVar7) goto LAB_00101d2c;
    *puVar6 = uVar7;
    local_70 = CONCAT71(local_70._1_7_,1);
    *(undefined4 *)(puVar6 + 0xc) = 0;
    local_68 = uVar7;
    __mutex_init(puVar6 + 0x12,"&drvdata->mem_lock",&tmc_probe___key);
    uVar3 = readl_relaxed(*puVar6 + 0xfc8);
    uVar11 = 0;
    uVar5 = uVar3 >> 6 & 3;
    uVar7 = (ulong)(uVar3 >> 8 & 7) - 2;
    *(uint *)(puVar6 + 0x11) = uVar5;
    if (uVar7 < 4) {
      uVar11 = *(undefined4 *)(&DAT_00109400 + uVar7 * 4);
    }
    *(undefined4 *)((long)puVar6 + 0x8c) = uVar11;
    *(undefined4 *)((long)puVar6 + 100) = 0xffffffff;
    if (uVar5 == 1) {
      uVar8 = *(undefined8 *)(param_1 + 0x2f0);
      *(undefined4 *)((long)puVar6 + 0x13c) = 1;
      local_4c = 0;
      iVar4 = fwnode_property_read_u32_array(uVar8,"arm,buffer-size",&local_4c,1);
      uVar8 = *(undefined8 *)(param_1 + 0x2f0);
      uVar5 = local_4c;
      if (iVar4 != 0) {
        uVar5 = 0x100000;
      }
      local_4c = 0;
      *(uint *)((long)puVar6 + 0x7c) = uVar5;
      iVar4 = fwnode_property_read_u32_array(uVar8,"arm,max-burst-size",&local_4c,1);
      uVar5 = local_4c;
      if (0xe < local_4c) {
        uVar5 = 0xf;
      }
      if (iVar4 != 0) {
        uVar5 = 0xf;
      }
      *(uint *)(puVar6 + 0x10) = uVar5;
    }
    else {
      iVar4 = readl_relaxed(*puVar6 + 4);
      *(int *)((long)puVar6 + 0x7c) = iVar4 << 2;
    }
    iVar4 = of_get_coresight_csr_name(*(undefined8 *)(param_1 + 0x2e8),puVar6 + 0x26);
    if (iVar4 == 0) {
      uVar7 = coresight_csr_get(puVar6[0x26]);
      puVar6[0x25] = uVar7;
      if (0xfffffffffffff000 < uVar7) {
        uVar7 = 0xfffffdfb;
        goto LAB_00101d2c;
      }
    }
    iVar4 = (int)puVar6[0x11];
    *(undefined1 *)(puVar6 + 0x29) = 0;
    local_88 = param_1;
    if (iVar4 == 2) {
      puVar9 = etf_devs;
      local_a0 = CONCAT44(local_a0._4_4_,2);
      local_a8 = 0x100000002;
      local_98 = &tmc_etf_cs_ops;
LAB_00101cd4:
      local_80 = &coresight_tmc_etf_groups;
    }
    else {
      if (iVar4 != 1) {
        if (iVar4 != 0) {
          _printk(&DAT_00108566,0);
          uVar7 = 0xffffffea;
          goto LAB_00101d2c;
        }
        puVar9 = etb_devs;
        local_a8 = 0x100000000;
        local_98 = &tmc_etb_cs_ops;
        goto LAB_00101cd4;
      }
      local_a8 = 0x200000000;
      local_98 = &tmc_etr_cs_ops;
      local_80 = &coresight_tmc_etr_groups;
      if (*(long *)(param_2 + 8) == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = *(undefined4 *)(*(long *)(param_2 + 8) + 0x10);
      }
      plVar12 = *(long **)(param_1 + 0x98);
      uVar5 = readl_relaxed(*plVar12 + 0xfb8);
      if (((uVar5 ^ 0xffffffff) & 3) != 0) {
        uVar7 = 0xfffffff3;
        goto LAB_00101d2c;
      }
      if (*(int *)((long)plVar12 + 0xc4) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101f44);
        (*pcVar2)();
      }
      *(undefined4 *)((long)plVar12 + 0xc4) = uVar11;
      if (((uVar3 >> 0x18 & 1) == 0) &&
         (uVar7 = fwnode_property_present(*(undefined8 *)(param_1 + 0x2f0),"arm,scatter-gather"),
         (uVar7 & 1) != 0)) {
        *(uint *)((long)plVar12 + 0xc4) = *(uint *)((long)plVar12 + 0xc4) | 1;
      }
      uVar5 = 0;
      if ((uVar3 & 0x10000) != 0) {
        uVar5 = uVar3 >> 0x11 & 0x7f;
      }
      uVar7 = 0xffffffffff;
      uVar3 = (uint)(CONCAT44(uVar5,uVar5 - 0x20) >> 2);
      if ((uVar3 < 6) && (uVar3 != 1)) {
        _dev_info(param_1,"Detected dma mask %dbits\n",(ulong)uVar5);
        uVar7 = 0xffffffffffffffff;
        if (uVar5 != 0x40) {
          uVar7 = ~(-1L << ((ulong)uVar5 & 0x3f));
        }
      }
      uVar5 = dma_set_mask(param_1,uVar7);
      if (uVar5 != 0) {
        uVar7 = (ulong)uVar5;
        _dev_err(param_1,"Failed to setup DMA mask: %d\n",uVar7);
        goto LAB_00101d2c;
      }
      dma_set_coherent_mask(param_1,uVar7);
      puVar6[0x1b] = 0;
      puVar6[0x19] = 0x1000000400000000;
      puVar6[0x1a] = 0;
      __mutex_init(puVar6 + 0x1c,"&drvdata->idr_mutex",&tmc_probe___key_4);
      of_property_read_variable_u32_array
                (*(undefined8 *)(param_1 + 0x2e8),"csr-atid-offset",puVar6 + 0x27,1,0);
      uVar7 = byte_cntr_init(param_1,puVar6);
      puVar6[0x24] = uVar7;
      uVar10 = tmc_etr_usb_init(param_1,puVar6);
      uVar7 = uVar10 & 0xffffffff;
      if ((int)uVar10 != 0) goto LAB_00101d2c;
      puVar9 = etr_devs;
    }
    local_78 = coresight_alloc_device_name(puVar9,param_1);
    if (local_78 != 0) {
      uVar7 = coresight_get_platform_data(param_1);
      if (uVar7 < 0xfffffffffffff001) {
        *(ulong *)(param_1 + 0x90) = uVar7;
        local_90 = uVar7;
        uVar7 = coresight_register(&local_a8);
        puVar6[1] = uVar7;
        if (uVar7 < 0xfffffffffffff001) {
          *(undefined4 *)(puVar6 + 2) = 0xff;
          puVar6[3] = local_78;
          puVar6[4] = (ulong)&tmc_fops;
          uVar10 = misc_register();
          uVar7 = uVar10 & 0xffffffff;
          if ((int)uVar10 == 0) {
            __pm_runtime_idle(param_1,5);
          }
          else {
            coresight_unregister(puVar6[1]);
          }
          goto LAB_00101d2c;
        }
      }
      uVar7 = uVar7 & 0xffffffff;
      goto LAB_00101d2c;
    }
  }
  uVar7 = 0xfffffff4;
LAB_00101d2c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// tmc_remove @ 00101f50 size=76
// signature: undefined tmc_remove(void)
// callers: []
//------------------------------------------------------------

void tmc_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if ((*(int *)(lVar1 + 0x88) == 1) && (*(long *)(lVar1 + 0x120) != 0)) {
    byte_cntr_remove();
  }
  misc_deregister(lVar1 + 0x10);
  coresight_unregister(*(undefined8 *)(lVar1 + 8));
  return;
}



//------------------------------------------------------------
// tmc_shutdown @ 00101fa0 size=136
// signature: undefined tmc_shutdown(void)
// callers: []
//------------------------------------------------------------

void tmc_shutdown(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  uVar1 = _raw_spin_lock_irqsave(lVar2 + 0x60);
  if (((*(int *)(lVar2 + 0x84) != 0) && (*(int *)(lVar2 + 0x88) == 1)) &&
     ((*(int *)(lVar2 + 0x13c) == 1 ||
      ((*(int *)(lVar2 + 0x13c) == 2 && (**(int **)(lVar2 + 0x140) == 1)))))) {
    tmc_etr_disable_hw(lVar2);
  }
  _raw_spin_unlock_irqrestore(lVar2 + 0x60,uVar1);
  return;
}



//------------------------------------------------------------
// trigger_cntr_show @ 0010202c size=64
// signature: undefined trigger_cntr_show(void)
// callers: []
//------------------------------------------------------------

long trigger_cntr_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%#lx\n",
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0xc0));
  return (long)iVar1;
}



//------------------------------------------------------------
// trigger_cntr_store @ 00102070 size=136
// signature: undefined trigger_cntr_store(void)
// callers: []
//------------------------------------------------------------

long trigger_cntr_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0x10,&local_30);
  if (iVar1 == 0) {
    *(int *)(lVar2 + 0xc0) = (int)local_30;
  }
  else {
    param_4 = (long)iVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// stop_on_flush_show @ 001020fc size=64
// signature: undefined stop_on_flush_show(void)
// callers: []
//------------------------------------------------------------

long stop_on_flush_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001083b0,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x148));
  return (long)iVar1;
}



//------------------------------------------------------------
// stop_on_flush_store @ 00102140 size=152
// signature: undefined stop_on_flush_store(void)
// callers: []
//------------------------------------------------------------

undefined8
stop_on_flush_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  ulong local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_30);
  if ((iVar1 == 0) && (local_30 < 2)) {
    *(bool *)(lVar2 + 0x148) = local_30 != 0;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// buffer_size_show @ 001021dc size=64
// signature: undefined buffer_size_show(void)
// callers: []
//------------------------------------------------------------

long buffer_size_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001083b4,
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x7c));
  return (long)iVar1;
}



//------------------------------------------------------------
// buffer_size_store @ 00102220 size=168
// signature: undefined buffer_size_store(void)
// callers: []
//------------------------------------------------------------

long buffer_size_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  ulong local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(lVar2 + 0x88) == 1) {
    iVar1 = kstrtoull(param_3,0,&local_30);
    if (iVar1 == 0) {
      if ((local_30 & 0xfff) == 0) {
        *(int *)(lVar2 + 0x7c) = (int)local_30;
      }
      else {
        param_4 = -0x16;
      }
    }
    else {
      param_4 = (long)iVar1;
    }
  }
  else {
    param_4 = -1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// block_size_show @ 001022cc size=76
// signature: undefined block_size_show(void)
// callers: []
//------------------------------------------------------------

long block_size_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x120);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(lVar3 + 0x98);
  }
  iVar1 = scnprintf(param_3,0x1000,&DAT_00107f5e,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// block_size_store @ 0010231c size=200
// signature: undefined block_size_store(void)
// callers: []
//------------------------------------------------------------

undefined8 block_size_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_30);
  if ((iVar1 == 0) && (*(long *)(lVar2 + 0x120) != 0)) {
    if (0xffe < local_30 - 1U) {
      mutex_lock(*(long *)(lVar2 + 0x120) + 0x148);
      *(int *)(*(long *)(lVar2 + 0x120) + 0x98) = (int)local_30;
      mutex_unlock(*(long *)(lVar2 + 0x120) + 0x148);
      goto LAB_001023a4;
    }
    _printk(&DAT_00108413);
  }
  param_4 = 0xffffffffffffffea;
LAB_001023a4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// out_mode_show @ 001023e8 size=88
// signature: undefined out_mode_show(void)
// callers: []
//------------------------------------------------------------

long out_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  
  uVar1 = *(uint *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x13c);
  if (2 < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102440);
    (*pcVar2)();
  }
  iVar3 = scnprintf(param_3,0x1000,&DAT_0010835e,(&str_tmc_etr_out_mode)[uVar1]);
  return (long)iVar3;
}



//------------------------------------------------------------
// out_mode_store @ 00102444 size=184
// signature: undefined out_mode_store(void)
// callers: []
//------------------------------------------------------------

void out_mode_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  undefined8 local_48;
  undefined2 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_48 = 0;
  uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x98);
  sVar3 = strlen(param_3);
  if ((sVar3 < 10) && (iVar2 = sscanf(param_3,"%s",&local_48), iVar2 == 1)) {
    iVar2 = tmc_etr_switch_mode(uVar4,&local_48);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// tmc_read @ 00102500 size=508
// signature: undefined tmc_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong tmc_read(long param_1,ulong param_2,undefined8 param_3,long *param_4)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0xd8);
  local_50 = 0;
  mutex_lock(lVar8 + 0x80);
  iVar1 = *(int *)(lVar8 + 0x78);
  if (iVar1 == 2) {
LAB_0010256c:
    uVar9 = tmc_etb_get_sysfs_trace(lVar8 + -0x10,*param_4,param_3,&local_50);
  }
  else {
    if (iVar1 != 1) {
      uVar9 = 0;
      if (iVar1 != 0) goto LAB_0010269c;
      goto LAB_0010256c;
    }
    uVar9 = tmc_etr_get_sysfs_trace(lVar8 + -0x10,*param_4,param_3,&local_50);
  }
  uVar3 = local_50;
  if ((long)uVar9 < 1) {
    uVar9 = 0;
  }
  else {
    if (uVar9 >> 0x1f != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1026e0);
      (*pcVar4)();
    }
    __check_object_size(local_50,uVar9,1);
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar7 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar7 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar7 <= 0x8000000000 - uVar9) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar7 = daif;
        if ((uVar7 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar2 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar7;
      }
      lVar5 = __arch_copy_to_user(puVar6,param_2 & 0xff7fffffffffffff,uVar3,uVar9);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar7 = daif;
        if ((uVar7 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar7;
      }
      if (lVar5 == 0) {
        *param_4 = *param_4 + uVar9;
        goto LAB_0010269c;
      }
    }
    uVar9 = 0xfffffffffffffff2;
  }
LAB_0010269c:
  mutex_unlock(lVar8 + 0x80);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
}



//------------------------------------------------------------
// tmc_open @ 0010271c size=116
// signature: undefined tmc_open(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_open(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(*(long *)(param_2 + 0xd8) + 0x78);
  if (iVar1 != 2) {
    if (iVar1 == 1) {
      uVar2 = tmc_read_prepare_etr(*(long *)(param_2 + 0xd8) + -0x10);
      iVar1 = (int)uVar2;
      goto joined_r0x00102758;
    }
    if (iVar1 != 0) {
      return 0xffffffea;
    }
  }
  uVar2 = tmc_read_prepare_etb();
  iVar1 = (int)uVar2;
joined_r0x00102758:
  if (iVar1 == 0) {
    nonseekable_open(param_1,param_2);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// tmc_release @ 00102794 size=76
// signature: undefined tmc_release(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_release(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = *(int *)(*(long *)(param_2 + 0xd8) + 0x78);
  if (iVar1 != 2) {
    if (iVar1 == 1) {
      uVar2 = tmc_read_unprepare_etr(*(long *)(param_2 + 0xd8) + -0x10);
      return uVar2;
    }
    if (iVar1 != 0) {
      return 0xffffffea;
    }
  }
  uVar2 = tmc_read_unprepare_etb();
  return uVar2;
}



//------------------------------------------------------------
// tmc_etb_get_sysfs_trace @ 00102810 size=48
// signature: undefined tmc_etb_get_sysfs_trace(void)
// callers: [tmc_read]
//------------------------------------------------------------

long tmc_etb_get_sysfs_trace(long param_1,long param_2,long param_3,long *param_4)

{
  long lVar1;
  
  lVar1 = (ulong)*(uint *)(param_1 + 0x78) - param_2;
  if (param_3 + param_2 <= (long)(ulong)*(uint *)(param_1 + 0x78)) {
    lVar1 = param_3;
  }
  if (0 < lVar1) {
    *param_4 = *(long *)(param_1 + 0x70) + param_2;
  }
  return lVar1;
}



//------------------------------------------------------------
// tmc_read_prepare_etb @ 00102844 size=184
// signature: undefined tmc_read_prepare_etb(void)
// callers: [tmc_open]
//------------------------------------------------------------

undefined8 tmc_read_prepare_etb(long *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  if ((*(uint *)(param_1 + 0x11) & 0xfffffffd) != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1028fc);
    (*pcVar1)();
  }
  uVar3 = _raw_spin_lock_irqsave(param_1 + 0xc);
  if ((char)param_1[0xd] != '\0') {
    uVar4 = 0xfffffff0;
    goto LAB_001028d0;
  }
  if ((*(int *)((long)param_1 + 0x84) == 2) || (param_1[0xe] == 0)) {
LAB_001028b4:
    uVar4 = 0xffffffea;
  }
  else {
    if (*(int *)((long)param_1 + 0x84) == 1) {
      iVar2 = readl_relaxed(*param_1 + 0x28);
      if (iVar2 != 0) goto LAB_001028b4;
      __tmc_etb_disable_hw(param_1);
    }
    uVar4 = 0;
    *(undefined1 *)(param_1 + 0xd) = 1;
  }
LAB_001028d0:
  _raw_spin_unlock_irqrestore(param_1 + 0xc,uVar3);
  return uVar4;
}



//------------------------------------------------------------
// readl_relaxed @ 00102900 size=124
// signature: undefined readl_relaxed(void)
// callers: [tmc_update_etf_buffer, __tmc_etb_disable_hw, tmc_read_prepare_etb, tmc_read_unprepare_etb]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102948,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// __tmc_etb_disable_hw @ 0010297c size=252
// signature: undefined __tmc_etb_disable_hw(void)
// callers: [tmc_disable_etf_sink, tmc_read_prepare_etb]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __tmc_etb_disable_hw(long *param_1)

{
  undefined8 uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  int *piVar6;
  
  writel_relaxed(0xc5acce55,*param_1 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  uVar3 = readl_relaxed(*param_1 + 0x20);
  if ((uVar3 & 1) == 0) {
    lVar4 = *param_1;
    DataSynchronizationBarrier(3,3,0);
  }
  else {
    tmc_flush_and_stop(param_1);
    tmc_disable_stop_on_flush(param_1);
    if (*(int *)((long)param_1 + 0x84) == 1) {
      uVar3 = readl_relaxed(*param_1 + 0xc);
      lVar4 = *param_1;
      *(undefined4 *)(param_1 + 0xf) = 0;
      piVar6 = (int *)param_1[0xe];
      while (iVar2 = readl_relaxed(lVar4 + 0x10), uVar1 = _memset, iVar2 != -1) {
        *piVar6 = iVar2;
        lVar4 = *param_1;
        *(int *)(param_1 + 0xf) = (int)param_1[0xf] + 4;
        piVar6 = piVar6 + 1;
      }
      if (((uVar3 & 1) != 0) && (puVar5 = (undefined8 *)param_1[0xe], puVar5 != (undefined8 *)0x0))
      {
        *puVar5 = _coresight_barrier_pkt;
        puVar5[1] = uVar1;
      }
    }
    tmc_disable_hw(param_1);
    lVar4 = *param_1;
    DataSynchronizationBarrier(3,3,0);
  }
  writel_relaxed(0,lVar4 + 0xfb0);
  return;
}



//------------------------------------------------------------
// tmc_read_unprepare_etb @ 00102a7c size=196
// signature: undefined tmc_read_unprepare_etb(void)
// callers: [tmc_release]
//------------------------------------------------------------

undefined8 tmc_read_unprepare_etb(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  if ((*(uint *)(param_1 + 0x11) & 0xfffffffd) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x102b40);
    (*pcVar2)();
  }
  plVar1 = param_1 + 0xc;
  uVar4 = _raw_spin_lock_irqsave(plVar1);
  if (*(int *)((long)param_1 + 0x84) == 1) {
    iVar3 = readl_relaxed(*param_1 + 0x28);
    if (iVar3 != 0) {
      _raw_spin_unlock_irqrestore(plVar1,uVar4);
      return 0xffffffea;
    }
    memset((void *)param_1[0xe],0,(ulong)*(uint *)((long)param_1 + 0x7c));
    __tmc_etb_enable_hw(param_1);
    lVar5 = 0;
  }
  else {
    lVar5 = param_1[0xe];
    param_1[0xe] = 0;
  }
  *(undefined1 *)(param_1 + 0xd) = 0;
  _raw_spin_unlock_irqrestore(plVar1,uVar4);
  kfree(lVar5);
  return 0;
}



//------------------------------------------------------------
// __tmc_etb_enable_hw @ 00102b44 size=200
// signature: undefined __tmc_etb_enable_hw(void)
// callers: [tmc_enable_etf_sink, tmc_read_unprepare_etb]
//------------------------------------------------------------

ulong __tmc_etb_enable_hw(long *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  
  writel_relaxed(0xc5acce55,*param_1 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  uVar1 = tmc_wait_for_tmcready(param_1);
  if ((int)uVar1 == 0) {
    writel_relaxed(uVar1,*param_1 + 0x28);
    uVar2 = 0x133;
    if ((char)param_1[0x29] != '\0') {
      uVar2 = 0x1133;
    }
    writel_relaxed(uVar2,*param_1 + 0x304);
    writel_relaxed((int)param_1[0x18],*param_1 + 0x1c);
    tmc_enable_hw(param_1);
    lVar3 = *param_1;
    DataSynchronizationBarrier(3,3,0);
  }
  else {
    _dev_err(param_1[1] + 0x38,"Failed to enable: TMC not ready\n");
    lVar3 = *param_1;
    DataSynchronizationBarrier(3,3,0);
  }
  writel_relaxed(0,lVar3 + 0xfb0);
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// tmc_enable_etf_sink @ 00102c10 size=756
// signature: undefined tmc_enable_etf_sink(void)
// callers: []
//------------------------------------------------------------

int tmc_enable_etf_sink(long param_1,int param_2,long param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  int *piVar7;
  undefined4 *puVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  if (param_2 == 2) {
    lVar11 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
    lVar6 = perf_get_aux(param_3);
    if (lVar6 == 0) {
      return -0x16;
    }
    lVar6 = *(long *)(lVar6 + 0x38);
    if (lVar6 == 0) {
      return -0x16;
    }
    uVar5 = _raw_spin_lock_irqsave(lVar11 + 0x60);
    if (*(char *)(lVar11 + 0x68) == '\0') {
      if (*(int *)(lVar11 + 0x84) != 1) {
        iVar3 = *(int *)(lVar6 + 8);
        if ((*(int *)(lVar11 + 100) == -1) || (*(int *)(lVar11 + 100) == iVar3)) {
          lVar6 = perf_get_aux(param_3);
          if ((lVar6 != 0) && (puVar8 = *(undefined4 **)(lVar6 + 0x38), puVar8 != (undefined4 *)0x0)
             ) {
            uVar9 = *(ulong *)(param_3 + 0x28);
            *(ulong *)(puVar8 + 4) = uVar9 & 0xfff;
            *puVar8 = (int)(((ulong)(uint)puVar8[1] * 0x1000 - 1 & uVar9) >> 0xc);
            *(undefined8 *)(puVar8 + 6) = 0;
            if (*(int *)(lVar11 + 100) == iVar3) {
              piVar7 = *(int **)(param_1 + 0x3c8);
              Hint_Prefetch(piVar7,2,0,1);
              do {
                cVar1 = '\x01';
                bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
                if (bVar2) {
                  *piVar7 = *piVar7 + 1;
                  cVar1 = ExclusiveMonitorsStatus();
                }
              } while (cVar1 != '\0');
            }
            else {
              iVar4 = coresight_claim_device(*(undefined8 *)(lVar11 + 8));
              if (iVar4 != 0) goto LAB_00102d6c;
              iVar4 = __tmc_etb_enable_hw(lVar11);
              if (iVar4 != 0) {
                coresight_disclaim_device(*(undefined8 *)(lVar11 + 8));
                goto LAB_00102d6c;
              }
              *(int *)(lVar11 + 100) = iVar3;
              *(undefined4 *)(lVar11 + 0x84) = 2;
              piVar7 = *(int **)(param_1 + 0x3c8);
              Hint_Prefetch(piVar7,2,0,1);
              do {
                cVar1 = '\x01';
                bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
                if (bVar2) {
                  *piVar7 = *piVar7 + 1;
                  cVar1 = ExclusiveMonitorsStatus();
                }
              } while (cVar1 != '\0');
            }
            iVar4 = 0;
            goto LAB_00102d6c;
          }
          goto LAB_00102cac;
        }
      }
      iVar4 = -0x10;
    }
    else {
LAB_00102cac:
      iVar4 = -0x16;
    }
LAB_00102d6c:
    _raw_spin_unlock_irqrestore(lVar11 + 0x60,uVar5);
    return iVar4;
  }
  if (param_2 != 1) {
    return -0x16;
  }
  lVar11 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  lVar6 = lVar11 + 0x60;
  uVar5 = _raw_spin_lock_irqsave(lVar6);
  if (*(long *)(lVar11 + 0x70) == 0) {
    _raw_spin_unlock_irqrestore(lVar6,uVar5);
    lVar10 = __kmalloc(*(undefined4 *)(lVar11 + 0x7c),0xdc0);
    if (lVar10 == 0) {
      return -0xc;
    }
    uVar5 = _raw_spin_lock_irqsave(lVar6);
    if (*(char *)(lVar11 + 0x68) == '\0') goto LAB_00102cf0;
LAB_00102c6c:
    iVar3 = -0x10;
  }
  else {
    lVar10 = 0;
    if (*(char *)(lVar11 + 0x68) != '\0') goto LAB_00102c6c;
LAB_00102cf0:
    if (*(int *)(lVar11 + 0x84) != 1) {
      lVar12 = *(long *)(lVar11 + 0x70);
      if (lVar12 == 0) {
        *(long *)(lVar11 + 0x70) = lVar10;
      }
      else {
        memset(*(void **)(lVar11 + 0x70),0,(ulong)*(uint *)(lVar11 + 0x7c));
      }
      iVar3 = coresight_claim_device(*(undefined8 *)(lVar11 + 8));
      if (iVar3 == 0) {
        iVar3 = __tmc_etb_enable_hw(lVar11);
        if (iVar3 != 0) {
          coresight_disclaim_device(*(undefined8 *)(lVar11 + 8));
          goto LAB_00102db0;
        }
        *(undefined4 *)(lVar11 + 0x84) = 1;
        piVar7 = *(int **)(param_1 + 0x3c8);
        Hint_Prefetch(piVar7,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
          if (bVar2) {
            *piVar7 = *piVar7 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        _raw_spin_unlock_irqrestore(lVar6,uVar5);
        iVar3 = 0;
      }
      else {
LAB_00102db0:
        kfree(*(undefined8 *)(lVar11 + 0x70));
        *(undefined8 *)(lVar11 + 0x70) = 0;
        _raw_spin_unlock_irqrestore(lVar6,uVar5);
      }
      if (lVar12 == 0) {
        return iVar3;
      }
      goto LAB_00102d1c;
    }
    piVar7 = *(int **)(param_1 + 0x3c8);
    Hint_Prefetch(piVar7,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
      if (bVar2) {
        *piVar7 = *piVar7 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    iVar3 = 0;
  }
  _raw_spin_unlock_irqrestore(lVar6,uVar5);
LAB_00102d1c:
  kfree(lVar10);
  return iVar3;
}



//------------------------------------------------------------
// tmc_disable_etf_sink @ 00102f2c size=184
// signature: undefined tmc_disable_etf_sink(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_disable_etf_sink(long param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  undefined8 uVar5;
  int *piVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  uVar5 = _raw_spin_lock_irqsave(lVar7 + 0x60);
  if (*(char *)(lVar7 + 0x68) == '\0') {
    piVar6 = *(int **)(param_1 + 0x3c8);
    Hint_Prefetch(piVar6,2,0,1);
    do {
      iVar1 = *piVar6;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar6,0x10);
      if (bVar3) {
        *piVar6 = iVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar1 + -1 == 0) {
      if (*(int *)(lVar7 + 0x84) == 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x102ff4);
        (*pcVar4)();
      }
      __tmc_etb_disable_hw(lVar7);
      coresight_disclaim_device(*(undefined8 *)(lVar7 + 8));
      uVar8 = 0;
      *(undefined4 *)(lVar7 + 0x84) = 0;
      *(undefined4 *)(lVar7 + 100) = 0xffffffff;
      goto LAB_00102f80;
    }
  }
  uVar8 = 0xfffffff0;
LAB_00102f80:
  _raw_spin_unlock_irqrestore(lVar7 + 0x60,uVar5);
  return uVar8;
}



//------------------------------------------------------------
// tmc_alloc_etf_buffer @ 00102ffc size=116
// signature: undefined tmc_alloc_etf_buffer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void tmc_alloc_etf_buffer
               (undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4,byte param_5)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = kmalloc_node_trace(_arm64_use_ng_mappings,0xdc0,-(uint)(*(int *)(param_2 + 0x28c) == -1),
                             0x30);
  if (lVar2 != 0) {
    lVar3 = *(long *)(param_2 + 0x2a0);
    *(undefined8 *)(lVar2 + 0x28) = param_3;
    uVar1 = *(undefined4 *)(lVar3 + 0x630);
    *(byte *)(lVar2 + 0x20) = param_5 & 1;
    *(undefined4 *)(lVar2 + 4) = param_4;
    *(undefined4 *)(lVar2 + 8) = uVar1;
  }
  return;
}



//------------------------------------------------------------
// tmc_free_etf_buffer @ 00103074 size=28
// signature: undefined tmc_free_etf_buffer(void)
// callers: []
//------------------------------------------------------------

void tmc_free_etf_buffer(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// tmc_update_etf_buffer @ 00103094 size=980
// signature: undefined tmc_update_etf_buffer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00103468) */

ulong tmc_update_etf_buffer(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  code *pcVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  
  if (param_3 == (uint *)0x0) {
    return 0;
  }
  plVar10 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  if (*(int *)((long)plVar10 + 0x84) != 2) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x103340);
    (*pcVar8)();
  }
  uVar5 = _raw_spin_lock_irqsave(plVar10 + 0xc);
  if (**(int **)(param_1 + 0x3c8) != 1) {
    uVar11 = 0;
    goto LAB_00103304;
  }
  writel_relaxed(0xc5acce55,*plVar10 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  tmc_flush_and_stop(plVar10);
  lVar9 = plVar10[1];
  pcVar8 = *(code **)(lVar9 + 0x28);
  if (*(char *)(lVar9 + 0x20) == '\0') {
    if (*(int *)(pcVar8 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103368);
      (*pcVar8)();
    }
    iVar2 = (*pcVar8)(0x14,1,0);
    if (*(int *)(*(code **)(lVar9 + 0x28) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103398);
      (*pcVar8)();
    }
    (**(code **)(lVar9 + 0x28))(0x38,1,0);
  }
  else {
    iVar2 = readl_relaxed(pcVar8 + 0x14);
    readl_relaxed(*(long *)(lVar9 + 0x28) + 0x38);
  }
  lVar9 = plVar10[1];
  pcVar8 = *(code **)(lVar9 + 0x28);
  if (*(char *)(lVar9 + 0x20) == '\0') {
    if (*(int *)(pcVar8 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1033c4);
      (*pcVar8)();
    }
    uVar6 = (*pcVar8)(0x18,1,0);
    if (*(int *)(*(code **)(lVar9 + 0x28) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1033f4);
      (*pcVar8)();
    }
    uVar7 = (**(code **)(lVar9 + 0x28))(0x3c,1,0);
  }
  else {
    uVar6 = readl_relaxed(pcVar8 + 0x18);
    uVar6 = uVar6 & 0xffffffff;
    uVar7 = readl_relaxed(*(long *)(lVar9 + 0x28) + 0x3c);
    uVar7 = uVar7 & 0xffffffff;
  }
  uVar3 = readl_relaxed(*plVar10 + 0xc);
  uVar14 = uVar3 & 1;
  if ((uVar3 & 1) == 0) {
    uVar11 = (ulong)((int)uVar6 - iVar2 & *(int *)((long)plVar10 + 0x7c) - 1U);
    if ((char)param_3[8] == '\0') goto LAB_001031c4;
LAB_00103230:
    if (uVar14 != 0) goto LAB_00103234;
  }
  else {
    uVar11 = (ulong)*(uint *)((long)plVar10 + 0x7c);
    if ((char)param_3[8] != '\0') goto LAB_00103230;
LAB_001031c4:
    if (uVar11 <= *(ulong *)(param_2 + 0x18)) goto LAB_00103230;
    uVar11 = tmc_get_memwidth_mask(plVar10);
    lVar9 = plVar10[1];
    uVar11 = *(ulong *)(param_2 + 0x18) & uVar11 & 0xffffffff;
    uVar7 = (uVar6 | uVar7 << 0x20) - uVar11;
    uVar6 = uVar7 + *(uint *)((long)plVar10 + 0x7c);
    if (uVar6 <= *(uint *)((long)plVar10 + 0x7c) - 1) {
      uVar7 = uVar6;
    }
    if (*(char *)(lVar9 + 0x20) != '\0') {
      writel_relaxed(uVar7,*(long *)(lVar9 + 0x28) + 0x14);
      writel_relaxed(uVar7 >> 0x20,*(long *)(lVar9 + 0x28) + 0x38);
      uVar14 = 1;
      goto LAB_00103230;
    }
    uVar14 = 1;
    if (*(int *)(*(code **)(lVar9 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103430);
      (*pcVar8)();
    }
    (**(code **)(lVar9 + 0x30))(uVar7 & 0xffffffff,0x14,1,0);
    if (*(int *)(*(code **)(lVar9 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x103460);
      (*pcVar8)();
    }
    (**(code **)(lVar9 + 0x30))(uVar7 >> 0x20,0x38,1,0);
LAB_00103234:
    if ((char)param_3[8] == '\0') {
      perf_aux_output_flag(param_2,1);
    }
  }
  if (uVar11 != 0) {
    uVar6 = *(ulong *)(param_3 + 4);
    uVar3 = *param_3;
    puVar12 = (undefined4 *)&coresight_barrier_pkt;
    iVar2 = 4;
    do {
      lVar9 = *(long *)(*(long *)(param_3 + 10) + (long)(int)uVar3 * 8);
      uVar4 = readl_relaxed(*plVar10 + 0x10);
      *(undefined4 *)(lVar9 + uVar6) = uVar4;
      uVar1 = 0;
      if (iVar2 - 4U < 0x10) {
        uVar1 = uVar14;
      }
      puVar13 = puVar12;
      if (uVar1 == 1) {
        puVar13 = puVar12 + 1;
        *(undefined4 *)(lVar9 + uVar6) = *puVar12;
      }
      uVar6 = uVar6 + 4;
      if (0xfff < uVar6) {
        uVar6 = 0;
        uVar3 = param_3[1] - 1 & uVar3 + 1;
      }
      uVar7 = (ulong)iVar2;
      puVar12 = puVar13;
      iVar2 = iVar2 + 4;
    } while (uVar7 < uVar11);
  }
  if ((char)param_3[8] != '\0') {
    *(ulong *)(param_2 + 0x28) = *(long *)(param_2 + 0x28) + uVar11;
  }
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*plVar10 + 0xfb0);
LAB_00103304:
  _raw_spin_unlock_irqrestore(plVar10 + 0xc,uVar5);
  return uVar11;
}



//------------------------------------------------------------
// writel_relaxed @ 0010346c size=132
// signature: undefined writel_relaxed(void)
// callers: [tmc_update_etf_buffer, tmc_enable_etf_link, __tmc_etb_disable_hw, tmc_disable_etf_link, __tmc_etb_enable_hw]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103484,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1034c0,uVar1);
  return;
}



//------------------------------------------------------------
// tmc_enable_etf_link @ 001034f4 size=356
// signature: undefined tmc_enable_etf_link(void)
// callers: []
//------------------------------------------------------------

int tmc_enable_etf_link(long param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  int *piVar5;
  long *plVar6;
  
  plVar6 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  uVar4 = _raw_spin_lock_irqsave(plVar6 + 0xc);
  if ((char)plVar6[0xd] != '\0') {
    iVar3 = -0x10;
    goto LAB_00103568;
  }
  piVar5 = *(int **)(param_1 + 0x3c8);
  if (*piVar5 == 0) {
    iVar3 = coresight_claim_device(plVar6[1]);
    if (iVar3 != 0) goto LAB_00103568;
    writel_relaxed(0xc5acce55,*plVar6 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    iVar3 = tmc_wait_for_tmcready(plVar6);
    if (iVar3 != 0) {
      _dev_err(plVar6[1] + 0x38,"Failed to enable : TMC is not ready\n");
      DataSynchronizationBarrier(3,3,0);
      writel_relaxed(0,*plVar6 + 0xfb0);
      coresight_disclaim_device(plVar6[1]);
      goto LAB_00103568;
    }
    writel_relaxed(2,*plVar6 + 0x28);
    writel_relaxed(3,*plVar6 + 0x304);
    writel_relaxed(0,*plVar6 + 0x34);
    tmc_enable_hw(plVar6);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar6 + 0xfb0);
    *(undefined4 *)((long)plVar6 + 0x84) = 1;
    piVar5 = *(int **)(param_1 + 0x3c8);
  }
  Hint_Prefetch(piVar5,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(piVar5,0x10);
    if (bVar2) {
      *piVar5 = *piVar5 + 1;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  iVar3 = 0;
LAB_00103568:
  _raw_spin_unlock_irqrestore(plVar6 + 0xc,uVar4);
  return iVar3;
}



//------------------------------------------------------------
// tmc_disable_etf_link @ 00103664 size=204
// signature: undefined tmc_disable_etf_link(void)
// callers: []
//------------------------------------------------------------

void tmc_disable_etf_link(long param_1)

{
  long lVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  int *piVar6;
  long *plVar7;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  uVar5 = _raw_spin_lock_irqsave(plVar7 + 0xc);
  if ((char)plVar7[0xd] == '\0') {
    piVar6 = *(int **)(param_1 + 0x3c8);
    Hint_Prefetch(piVar6,2,0,1);
    do {
      iVar2 = *piVar6;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar6,0x10);
      if (bVar4) {
        *piVar6 = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar2 + -1 == 0) {
      lVar1 = plVar7[1];
      writel_relaxed(0xc5acce55,*plVar7 + 0xfb0);
      DataSynchronizationBarrier(3,3,0);
      tmc_flush_and_stop(plVar7);
      tmc_disable_hw(plVar7);
      coresight_disclaim_device_unlocked(lVar1);
      DataSynchronizationBarrier(3,3,0);
      writel_relaxed(0,*plVar7 + 0xfb0);
      *(undefined4 *)((long)plVar7 + 0x84) = 0;
    }
  }
  _raw_spin_unlock_irqrestore(plVar7 + 0xc,uVar5);
  return;
}



//------------------------------------------------------------
// tmc_free_sg_table @ 00103748 size=100
// signature: undefined tmc_free_sg_table(void)
// callers: []
//------------------------------------------------------------

void tmc_free_sg_table(undefined8 *param_1)

{
  if (param_1[1] != 0) {
    vunmap();
  }
  tmc_pages_free(param_1 + 5,*param_1,1);
  if (param_1[2] != 0) {
    vunmap();
  }
  tmc_pages_free(param_1 + 8,*param_1,2);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// tmc_get_rwp_offset @ 001037b0 size=432
// signature: undefined tmc_get_rwp_offset(void)
// callers: [tmc_etr_byte_cntr_stop, usb_notifier, usb_bypass_stop, tmc_etr_byte_cntr_open, usb_read_work_fn]
//------------------------------------------------------------

long tmc_get_rwp_offset(long param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  code *pcVar5;
  ulong *puVar6;
  long lVar7;
  
  lVar4 = *(long *)(param_1 + 0x110);
  if (lVar4 != 0) {
    if (*(int *)(lVar4 + 4) == 0) {
      lVar7 = *(long *)(param_1 + 8);
      lVar4 = *(long *)(lVar4 + 0x18);
      pcVar5 = *(code **)(lVar7 + 0x28);
      if (*(char *)(lVar7 + 0x20) == '\0') {
        if (*(int *)(pcVar5 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x103924);
          (*pcVar5)();
        }
        uVar2 = (*pcVar5)(0x18,1,0);
        if (*(int *)(*(code **)(lVar7 + 0x28) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x103958);
          (*pcVar5)();
        }
        uVar3 = (**(code **)(lVar7 + 0x28))(0x3c,1,0);
      }
      else {
        uVar2 = readl_relaxed(pcVar5 + 0x18);
        uVar2 = uVar2 & 0xffffffff;
        uVar3 = readl_relaxed(*(long *)(lVar7 + 0x28) + 0x3c);
        uVar3 = uVar3 & 0xffffffff;
      }
      return (uVar2 | uVar3 << 0x20) - lVar4;
    }
    lVar7 = *(long *)(param_1 + 8);
    lVar4 = **(long **)(lVar4 + 0x38);
    pcVar5 = *(code **)(lVar7 + 0x28);
    if (*(char *)(lVar7 + 0x20) == '\0') {
      if (*(int *)(pcVar5 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1038c8);
        (*pcVar5)();
      }
      uVar2 = (*pcVar5)(0x18,1,0);
      if (*(int *)(*(code **)(lVar7 + 0x28) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1038f8);
        (*pcVar5)();
      }
      uVar3 = (**(code **)(lVar7 + 0x28))(0x3c,1,0);
    }
    else {
      uVar2 = readl_relaxed(pcVar5 + 0x18);
      uVar2 = uVar2 & 0xffffffff;
      uVar3 = readl_relaxed(*(long *)(lVar7 + 0x28) + 0x3c);
      uVar3 = uVar3 & 0xffffffff;
    }
    uVar1 = *(uint *)(lVar4 + 0x40);
    if (0 < (int)uVar1) {
      lVar7 = 0;
      uVar2 = uVar2 | uVar3 << 0x20;
      puVar6 = *(ulong **)(lVar4 + 0x48);
      do {
        uVar3 = *puVar6;
        if ((uVar2 >= uVar3 && uVar2 <= uVar3 + 0x1000) &&
            (uVar2 < uVar3 || uVar3 + 0x1000 != uVar2)) {
          return (uVar2 - uVar3) + lVar7;
        }
        lVar7 = lVar7 + 0x1000;
        puVar6 = puVar6 + 1;
      } while ((ulong)uVar1 * 0x1000 != lVar7);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// tmc_alloc_sg_table @ 00103964 size=384
// signature: undefined tmc_alloc_sg_table(void)
// callers: [tmc_etr_alloc_sg_buf]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
tmc_alloc_sg_table(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined8 param_5)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 *puVar6;
  
  puVar3 = (undefined8 *)kmalloc_trace(_vmap,0xdc0,0x58);
  if (puVar3 == (undefined8 *)0x0) {
    return (undefined8 *)0xfffffffffffffff4;
  }
  *(undefined4 *)(puVar3 + 4) = param_2;
  *puVar3 = param_1;
  puVar5 = puVar3 + 8;
  *(undefined4 *)puVar5 = param_4;
  puVar6 = puVar3 + 5;
  *(undefined4 *)puVar6 = param_3;
  iVar2 = tmc_pages_alloc(puVar5,param_1,param_2,2,param_5);
  if (iVar2 == 0) {
    uVar1 = 0x68000000000703;
    if (arm64_use_ng_mappings != '\0') {
      uVar1 = 0x68000000000f03;
    }
    lVar4 = vmap(puVar3[10],*(undefined4 *)(puVar3 + 8),4,uVar1);
    puVar3[2] = lVar4;
    if (lVar4 != 0) {
      iVar2 = tmc_pages_alloc(puVar6,*puVar3,0xffffffff,1,0);
      if (iVar2 != 0) goto LAB_00103a78;
      uVar1 = 0x68000000000703;
      if (arm64_use_ng_mappings != '\0') {
        uVar1 = 0x68000000000f03;
      }
      lVar4 = vmap(puVar3[7],*(undefined4 *)(puVar3 + 5),4,uVar1);
      puVar3[1] = lVar4;
      if (lVar4 != 0) {
        puVar3[3] = *(undefined8 *)puVar3[6];
        return puVar3;
      }
    }
    iVar2 = -0xc;
  }
LAB_00103a78:
  if (puVar3[1] != 0) {
    vunmap(puVar3[1]);
  }
  tmc_pages_free(puVar6,*puVar3,1);
  if (puVar3[2] != 0) {
    vunmap();
  }
  tmc_pages_free(puVar5,*puVar3,2);
  kfree(puVar3);
  return (undefined8 *)(long)iVar2;
}



//------------------------------------------------------------
// tmc_sg_table_sync_data_range @ 00103ae8 size=124
// signature: undefined tmc_sg_table_sync_data_range(void)
// callers: []
//------------------------------------------------------------

void tmc_sg_table_sync_data_range(long *param_1,ulong param_2,long param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  ulong uVar5;
  int iVar6;
  
  param_2 = param_2 >> 0xc;
  uVar5 = param_3 + 0xfffU >> 0xc;
  if ((int)param_2 < (int)uVar5 + (int)param_2) {
    uVar4 = *(undefined8 *)(*param_1 + 0x60);
    do {
      iVar1 = (int)param_1[8];
      iVar2 = 0;
      iVar6 = (int)param_2;
      if (iVar1 != 0) {
        iVar2 = iVar6 / iVar1;
      }
      dma_sync_single_for_cpu
                (uVar4,*(undefined8 *)(param_1[9] + (long)(iVar6 - iVar2 * iVar1) * 8),0x1000,2);
      param_2 = (ulong)(iVar6 + 1);
      uVar3 = (int)uVar5 - 1;
      uVar5 = (ulong)uVar3;
    } while (uVar3 != 0);
  }
  return;
}



//------------------------------------------------------------
// tmc_sg_table_sync_table @ 00103b68 size=108
// signature: undefined tmc_sg_table_sync_table(void)
// callers: []
//------------------------------------------------------------

void tmc_sg_table_sync_table(long *param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (0 < (int)param_1[5]) {
    lVar2 = 0;
    uVar1 = *(undefined8 *)(*param_1 + 0x60);
    do {
      dma_sync_single_for_device(uVar1,*(undefined8 *)(param_1[6] + lVar2 * 8),0x1000,1);
      lVar2 = lVar2 + 1;
    } while (lVar2 < (int)param_1[5]);
  }
  return;
}



//------------------------------------------------------------
// tmc_sg_table_get_data @ 00103bd8 size=104
// signature: undefined tmc_sg_table_get_data(void)
// callers: []
//------------------------------------------------------------

ulong tmc_sg_table_get_data(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = (long)*(int *)(param_1 + 0x40) * 0x1000;
  uVar1 = uVar2 - param_2;
  if (uVar2 < param_2 || uVar1 == 0) {
    return 0xffffffffffffffea;
  }
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  uVar2 = 0x1000 - (param_2 & 0xfff);
  if (uVar2 <= uVar1) {
    uVar1 = uVar2;
  }
  if (uVar1 != 0) {
    *param_4 = ((*(ulong *)(*(long *)(param_1 + 0x50) + (long)(int)(param_2 >> 0xc) * 8) &
                0x3ffffffffffc0) << 6 | 0xff00000000000000) + (param_2 & 0xfff);
  }
  return uVar1;
}



//------------------------------------------------------------
// tmc_etr_get_catu_device @ 00103c4c size=8
// signature: undefined tmc_etr_get_catu_device(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_etr_get_catu_device(void)

{
  return 0;
}



//------------------------------------------------------------
// tmc_etr_set_catu_ops @ 00103c58 size=12
// signature: undefined tmc_etr_set_catu_ops(void)
// callers: []
//------------------------------------------------------------

void tmc_etr_set_catu_ops(undefined8 param_1)

{
  DAT_001091c8 = param_1;
  return;
}



//------------------------------------------------------------
// tmc_etr_remove_catu_ops @ 00103c68 size=12
// signature: undefined tmc_etr_remove_catu_ops(void)
// callers: []
//------------------------------------------------------------

void tmc_etr_remove_catu_ops(void)

{
  DAT_001091c8 = 0;
  return;
}



//------------------------------------------------------------
// tmc_etr_buf_get_data @ 00103c78 size=76
// signature: undefined tmc_etr_buf_get_data(void)
// callers: [tmc_etr_byte_cntr_read, usb_read_work_fn]
//------------------------------------------------------------

void tmc_etr_buf_get_data(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  
  uVar1 = *(long *)(param_1 + 0x10) - param_2;
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 0x10);
  if (*(int *)(pcVar2 + -4) != -0x408d4ef0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103cb4);
    (*pcVar2)();
  }
  (*pcVar2)(param_1,param_2,uVar1);
  return;
}



//------------------------------------------------------------
// tmc_etr_get_sysfs_trace @ 00103cc8 size=132
// signature: undefined tmc_etr_get_sysfs_trace(void)
// callers: [tmc_read]
//------------------------------------------------------------

void tmc_etr_get_sysfs_trace(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  ulong uVar6;
  
  lVar3 = *(long *)(param_1 + 0x110);
  uVar1 = *(long *)(lVar3 + 0x28) - param_2;
  if ((long)(param_3 + param_2) <= *(long *)(lVar3 + 0x28)) {
    uVar1 = param_3;
  }
  if (0 < (long)uVar1) {
    lVar5 = *(long *)(lVar3 + 0x10);
    param_2 = *(long *)(lVar3 + 0x20) + param_2;
    lVar2 = 0;
    if (lVar5 <= param_2) {
      lVar2 = lVar5;
    }
    param_2 = param_2 - lVar2;
    uVar6 = lVar5 - param_2;
    if (uVar1 <= uVar6) {
      uVar6 = uVar1;
    }
    pcVar4 = *(code **)(*(long *)(lVar3 + 0x30) + 0x10);
    if (*(int *)(pcVar4 + -4) != -0x408d4ef0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x103d3c);
      (*pcVar4)();
    }
    (*pcVar4)(lVar3,param_2,uVar6);
  }
  return;
}



//------------------------------------------------------------
// tmc_etr_disable_hw @ 00103d50 size=52
// signature: undefined tmc_etr_disable_hw(void)
// callers: [tmc_shutdown, _tmc_disable_etr_sink]
//------------------------------------------------------------

void tmc_etr_disable_hw(long param_1)

{
  __tmc_etr_disable_hw();
  coresight_disclaim_device(*(undefined8 *)(param_1 + 8));
  *(undefined8 *)(param_1 + 0x70) = 0;
  return;
}



//------------------------------------------------------------
// __tmc_etr_disable_hw @ 00103d84 size=304
// signature: undefined __tmc_etr_disable_hw(void)
// callers: [tmc_read_prepare_etr, tmc_etr_disable_hw]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __tmc_etr_disable_hw(long *param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  undefined8 *local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  writel_relaxed(0xc5acce55,*param_1 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  tmc_flush_and_stop(param_1);
  tmc_disable_stop_on_flush(param_1);
  if (*(int *)((long)param_1 + 0x84) == 1) {
    lVar4 = param_1[0xe];
    if (param_1[0x22] != lVar4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x103eac);
      (*pcVar3)();
    }
    tmc_sync_etr_buf(param_1);
    if (*(char *)(lVar4 + 8) != '\0') {
      local_30 = (undefined8 *)0x0;
      uVar2 = *(long *)(lVar4 + 0x10) - *(long *)(lVar4 + 0x20);
      if (0xf < uVar2) {
        uVar2 = 0x10;
      }
      pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 0x10);
      if (*(int *)(pcVar3 + -4) != -0x408d4ef0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103e40);
        (*pcVar3)();
      }
      lVar4 = (*pcVar3)(lVar4,*(long *)(lVar4 + 0x20),uVar2,&local_30);
      uVar1 = _memset;
      if (lVar4 < 0x10) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x103f04);
        (*pcVar3)();
      }
      if (local_30 != (undefined8 *)0x0) {
        *local_30 = _coresight_barrier_pkt;
        local_30[1] = uVar1;
      }
    }
  }
  tmc_disable_hw(param_1);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*param_1 + 0xfb0);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tmc_etr_switch_mode @ 00103f10 size=300
// signature: undefined tmc_etr_switch_mode(void)
// callers: [out_mode_store]
//------------------------------------------------------------

undefined8 tmc_etr_switch_mode(long param_1,char *param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  
  mutex_lock(param_1 + 0x90);
  iVar3 = strcmp(param_2,"mem");
  if (iVar3 == 0) {
    uVar5 = 1;
LAB_00103f80:
    if (uVar5 != *(uint *)(param_1 + 0x13c)) {
      if (*(int *)(param_1 + 0x84) == 0) {
        uVar4 = 0;
        *(uint *)(param_1 + 0x13c) = uVar5;
        goto LAB_00103fb8;
      }
      _tmc_disable_etr_sink(*(undefined8 *)(param_1 + 8),1);
      uVar1 = *(uint *)(param_1 + 0x13c);
      *(uint *)(param_1 + 0x13c) = uVar5;
      iVar3 = tmc_enable_etr_sink_sysfs(*(undefined8 *)(param_1 + 8));
      if (iVar3 != 0) {
        *(uint *)(param_1 + 0x13c) = uVar1;
        tmc_enable_etr_sink_sysfs(*(undefined8 *)(param_1 + 8));
        if (2 < uVar1) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10403c);
          (*pcVar2)();
        }
        _dev_err(*(long *)(param_1 + 8) + 0x38,"Switch to %s failed. Fall back to %s.\n",
                 (&str_tmc_etr_out_mode)[uVar5],(&str_tmc_etr_out_mode)[uVar1]);
        goto LAB_00103f60;
      }
    }
    uVar4 = 0;
  }
  else {
    iVar3 = strcmp(param_2,"usb");
    if (iVar3 == 0) {
      if (**(int **)(param_1 + 0x140) != 0) {
        uVar5 = 2;
        goto LAB_00103f80;
      }
      _dev_err(*(long *)(param_1 + 8) + 0x38,"USB mode is not supported.\n");
    }
LAB_00103f60:
    uVar4 = 0xffffffea;
  }
LAB_00103fb8:
  mutex_unlock(param_1 + 0x90);
  return uVar4;
}



//------------------------------------------------------------
// _tmc_disable_etr_sink @ 0010403c size=356
// signature: undefined _tmc_disable_etr_sink(void)
// callers: [tmc_disable_etr_sink, tmc_etr_switch_mode]
//------------------------------------------------------------

undefined8 _tmc_disable_etr_sink(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  undefined8 uVar6;
  int *piVar7;
  long lVar8;
  
  lVar8 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  lVar1 = lVar8 + 0x60;
  uVar6 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(lVar8 + 0x68) != '\0') {
LAB_00104098:
    _raw_spin_unlock_irqrestore(lVar1,uVar6);
    return 0xfffffff0;
  }
  piVar7 = *(int **)(param_1 + 0x3c8);
  Hint_Prefetch(piVar7,2,0,1);
  do {
    iVar2 = *piVar7;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar7,0x10);
    if (bVar4) {
      *piVar7 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  if ((iVar2 + -1 != 0) && ((param_2 & 1) == 0)) goto LAB_00104098;
  if (*(int *)(lVar8 + 0x84) == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1041b0);
    (*pcVar5)();
  }
  if (*(int *)(lVar8 + 0x13c) != 1) {
    if ((*(int *)(lVar8 + 0x13c) != 2) || (**(int **)(lVar8 + 0x140) != 1)) {
      _raw_spin_unlock_irqrestore(lVar1,uVar6);
      tmc_usb_disable(*(undefined8 *)(lVar8 + 0x140));
      uVar6 = _raw_spin_lock_irqsave(lVar1);
      goto LAB_00104158;
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar6);
    tmc_usb_disable(*(undefined8 *)(lVar8 + 0x140));
    uVar6 = _raw_spin_lock_irqsave(lVar1);
  }
  tmc_etr_disable_hw(lVar8);
LAB_00104158:
  iVar2 = *(int *)(lVar8 + 0x84);
  *(undefined4 *)(lVar8 + 0x84) = 0;
  *(undefined4 *)(lVar8 + 100) = 0xffffffff;
  *(undefined8 *)(lVar8 + 0x118) = 0;
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
  if (iVar2 == 1) {
    tmc_etr_byte_cntr_stop(*(undefined8 *)(lVar8 + 0x120));
  }
  lVar1 = sp_el0;
  _dev_err(param_1 + 0x38,"[%s][%d]TMC-ETR disabled\n",lVar1 + 0x848,*(undefined4 *)(lVar1 + 0x630))
  ;
  return 0;
}



//------------------------------------------------------------
// tmc_enable_etr_sink_sysfs @ 001041b4 size=884
// signature: undefined tmc_enable_etr_sink_sysfs(void)
// callers: [tmc_enable_etr_sink, tmc_etr_switch_mode]
//------------------------------------------------------------

int tmc_enable_etr_sink_sysfs(long param_1)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  code *pcVar8;
  int *piVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  
  lVar10 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  lVar1 = lVar10 + 0x60;
  uVar6 = _raw_spin_lock_irqsave(lVar1);
  if ((*(char *)(lVar10 + 0x68) == '\0') && (1 < *(int *)(lVar10 + 0x84) - 2U)) {
    if (*(int *)(lVar10 + 0x84) == 1) {
      piVar9 = *(int **)(param_1 + 0x3c8);
      uVar11 = 0;
      Hint_Prefetch(piVar9,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar9,0x10);
        if (bVar3) {
          *piVar9 = *piVar9 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(lVar10 + 0x13c);
      if (iVar5 != 1) {
        if (iVar5 == 2) {
          if ((**(int **)(lVar10 + 0x140) == 1) &&
             ((*(long *)(lVar10 + 0x110) == 0 ||
              (*(long *)(*(long *)(lVar10 + 0x110) + 0x10) != 0x4000000)))) goto LAB_0010435c;
          uVar11 = 0;
LAB_001043e0:
          if (**(int **)(lVar10 + 0x140) == 1) {
LAB_001043f0:
            uVar12 = *(ulong *)(lVar10 + 0x110);
            if (uVar12 == 0) {
              *(ulong *)(lVar10 + 0x110) = uVar11;
              if (uVar11 == 0) {
LAB_0010434c:
                    /* WARNING: Does not return */
                pcVar8 = (code *)SoftwareBreakpoint(0x800,0x104358);
                (*pcVar8)();
              }
              uVar4 = 0;
              uVar12 = uVar11;
            }
            else {
              if (uVar11 == 0) goto LAB_00104414;
              if (*(long *)(uVar12 + 0x10) == *(long *)(uVar11 + 0x10)) {
                uVar4 = uVar11;
              }
              else {
                *(ulong *)(lVar10 + 0x110) = uVar11;
                uVar4 = uVar12;
                uVar12 = uVar11;
              }
            }
            goto LAB_0010443c;
          }
        }
        else {
          uVar11 = 0;
joined_r0x00104394:
          if (iVar5 == 1) goto LAB_001043f0;
          if (iVar5 == 2) goto LAB_001043e0;
        }
LAB_00104494:
        *(undefined4 *)(lVar10 + 0x84) = 1;
        piVar9 = *(int **)(param_1 + 0x3c8);
        Hint_Prefetch(piVar9,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar9,0x10);
          if (bVar3) {
            *piVar9 = *piVar9 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        if (*(int *)(lVar10 + 0x13c) == 2) {
          iVar5 = tmc_usb_enable(*(undefined8 *)(lVar10 + 0x140));
          if (iVar5 != 0) {
            piVar9 = *(int **)(param_1 + 0x3c8);
            Hint_Prefetch(piVar9,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(piVar9,0x10);
              if (bVar3) {
                *piVar9 = *piVar9 + -1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            *(undefined4 *)(lVar10 + 0x84) = 0;
          }
        }
        else {
          iVar5 = 0;
        }
        goto LAB_0010421c;
      }
      if ((*(long *)(lVar10 + 0x110) == 0) ||
         (*(ulong *)(*(long *)(lVar10 + 0x110) + 0x10) != (ulong)*(uint *)(lVar10 + 0x7c))) {
LAB_0010435c:
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        if ((*(int *)(lVar10 + 0x13c) == 2) && (**(int **)(lVar10 + 0x140) == 1)) {
          uVar7 = 0x4000000;
        }
        else {
          uVar7 = *(undefined4 *)(lVar10 + 0x7c);
        }
        uVar11 = tmc_alloc_etr_buf(lVar10,uVar7,0);
        if (0xfffffffffffff000 < uVar11) {
          return (int)uVar11;
        }
        uVar6 = _raw_spin_lock_irqsave(lVar1);
        iVar5 = *(int *)(lVar10 + 0x13c);
        goto joined_r0x00104394;
      }
      uVar12 = *(ulong *)(lVar10 + 0x110);
      if (uVar12 == 0) {
        *(undefined8 *)(lVar10 + 0x110) = 0;
        goto LAB_0010434c;
      }
LAB_00104414:
      uVar4 = 0;
LAB_0010443c:
      uVar11 = uVar4;
      if ((*(int *)(uVar12 + 4) == 1) && ((*(byte *)(lVar10 + 0xc4) & 1) == 0)) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x800,0x104508);
        (*pcVar8)();
      }
      if (*(long *)(lVar10 + 0x70) != 0) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x800,0x1044fc);
        (*pcVar8)();
      }
      iVar5 = coresight_claim_device(*(undefined8 *)(lVar10 + 8));
      if (iVar5 == 0) {
        *(ulong *)(lVar10 + 0x70) = uVar12;
        iVar5 = __tmc_etr_enable_hw(lVar10);
        if (iVar5 == 0) goto LAB_00104494;
        *(undefined8 *)(lVar10 + 0x70) = 0;
        coresight_disclaim_device(*(undefined8 *)(lVar10 + 8));
      }
    }
  }
  else {
    uVar11 = 0;
    iVar5 = -0x10;
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
LAB_0010421c:
  if (uVar11 != 0) {
    if ((*(long *)(uVar11 + 0x30) == 0) ||
       (pcVar8 = *(code **)(*(long *)(uVar11 + 0x30) + 0x18), pcVar8 == (code *)0x0)) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x800,0x104234);
      (*pcVar8)();
    }
    if (*(int *)(pcVar8 + -4) != -0x1fa83ec2) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x104258);
      (*pcVar8)();
    }
    (*pcVar8)(uVar11);
    kfree(uVar11);
  }
  if (iVar5 == 0) {
    if (*(int *)(lVar10 + 0x13c) == 1) {
      tmc_etr_byte_cntr_start(*(undefined8 *)(lVar10 + 0x120));
    }
    lVar1 = sp_el0;
    _dev_err(param_1 + 0x38,"[%s][%d]TMC-ETR enabled\n",lVar1 + 0x848,*(undefined4 *)(lVar1 + 0x630)
            );
    iVar5 = 0;
  }
  return iVar5;
}



//------------------------------------------------------------
// tmc_read_prepare_etr @ 00104564 size=204
// signature: undefined tmc_read_prepare_etr(void)
// callers: [tmc_open]
//------------------------------------------------------------

undefined8 tmc_read_prepare_etr(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x88) != 1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x104630);
    (*pcVar1)();
  }
  mutex_lock(param_1 + 0x90);
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x60);
  if (*(char *)(param_1 + 0x68) == '\0') {
    if ((*(long *)(param_1 + 0x110) == 0) ||
       ((*(long *)(param_1 + 0x120) != 0 && (*(char *)(*(long *)(param_1 + 0x120) + 0x90) != '\0')))
       ) {
      uVar3 = 0xffffffea;
    }
    else {
      if (*(int *)(param_1 + 0x84) == 1) {
        __tmc_etr_disable_hw(param_1);
      }
      uVar3 = 0;
      *(undefined1 *)(param_1 + 0x68) = 1;
    }
  }
  else {
    uVar3 = 0xfffffff0;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x60,uVar2);
  mutex_unlock(param_1 + 0x90);
  return uVar3;
}



//------------------------------------------------------------
// tmc_read_unprepare_etr @ 00104638 size=240
// signature: undefined tmc_read_unprepare_etr(void)
// callers: [tmc_release]
//------------------------------------------------------------

undefined8 tmc_read_unprepare_etr(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  
  if (*(int *)(param_1 + 0x88) != 1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x104730);
    (*pcVar3)();
  }
  mutex_lock(param_1 + 0x90);
  lVar1 = param_1 + 0x60;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  if (*(int *)(param_1 + 0x84) == 1) {
    __tmc_etr_enable_hw(param_1);
    *(undefined1 *)(param_1 + 0x68) = 0;
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
  }
  else {
    lVar4 = *(long *)(param_1 + 0x110);
    *(undefined8 *)(param_1 + 0x110) = 0;
    *(undefined1 *)(param_1 + 0x68) = 0;
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
    if (lVar4 != 0) {
      if ((*(long *)(lVar4 + 0x30) == 0) ||
         (pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 0x18), pcVar3 == (code *)0x0)) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1046d4);
        (*pcVar3)();
      }
      if (*(int *)(pcVar3 + -4) != -0x1fa83ec2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1046f8);
        (*pcVar3)();
      }
      (*pcVar3)(lVar4);
      kfree(lVar4);
    }
  }
  mutex_unlock(param_1 + 0x90);
  return 0;
}



//------------------------------------------------------------
// __tmc_etr_enable_hw @ 00104734 size=828
// signature: undefined __tmc_etr_enable_hw(void)
// callers: [tmc_enable_etr_sink_sysfs, tmc_enable_etr_sink, tmc_read_unprepare_etr]
//------------------------------------------------------------

int __tmc_etr_enable_hw(long *param_1)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  undefined4 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = param_1[0xe];
  writel_relaxed(0xc5acce55,*param_1 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  iVar3 = tmc_wait_for_tmcready(param_1);
  if (iVar3 == 0) {
    uVar8 = *(ulong *)(lVar9 + 0x10);
    uVar6 = uVar8 + 3;
    if (-1 < (long)uVar8) {
      uVar6 = uVar8;
    }
    writel_relaxed(uVar6 >> 2,*param_1 + 4);
    writel_relaxed(0,*param_1 + 0x28);
    uVar4 = readl_relaxed(*param_1 + 0x110);
    uVar5 = 0x3e;
    if ((*(uint *)((long)param_1 + 0xc4) & 2) != 0) {
      uVar5 = 0xf003e;
    }
    uVar5 = uVar4 & 0xfffff000 | uVar4 & 0x40 | (*(uint *)(param_1 + 0x10) & 0xf) << 8 | uVar5;
    uVar4 = uVar5 | 0x80;
    if (*(int *)(lVar9 + 4) != 1) {
      uVar4 = uVar5;
    }
    writel_relaxed(uVar4,*param_1 + 0x110);
    lVar10 = param_1[1];
    uVar6 = *(ulong *)(lVar9 + 0x18);
    if (*(char *)(lVar10 + 0x20) == '\0') {
      if (*(int *)(*(code **)(lVar10 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104968);
        (*pcVar2)();
      }
      (**(code **)(lVar10 + 0x30))(uVar6 & 0xffffffff,0x118,1,0);
      if (*(int *)(*(code **)(lVar10 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104998);
        (*pcVar2)();
      }
      (**(code **)(lVar10 + 0x30))(uVar6 >> 0x20,0x11c,1,0);
      bVar1 = *(byte *)((long)param_1 + 0xc4);
    }
    else {
      writel_relaxed(uVar6,*(long *)(lVar10 + 0x28) + 0x118);
      writel_relaxed(uVar6 >> 0x20,*(long *)(lVar10 + 0x28) + 0x11c);
      bVar1 = *(byte *)((long)param_1 + 0xc4);
    }
    if ((bVar1 >> 2 & 1) != 0) {
      lVar10 = param_1[1];
      uVar6 = *(ulong *)(lVar9 + 0x18);
      if (*(char *)(lVar10 + 0x20) == '\0') {
        if (*(int *)(*(code **)(lVar10 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1049d4);
          (*pcVar2)();
        }
        (**(code **)(lVar10 + 0x30))(uVar6 & 0xffffffff,0x14,1,0);
        if (*(int *)(*(code **)(lVar10 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104a04);
          (*pcVar2)();
        }
        (**(code **)(lVar10 + 0x30))(uVar6 >> 0x20,0x38,1,0);
      }
      else {
        writel_relaxed(uVar6,*(long *)(lVar10 + 0x28) + 0x14);
        writel_relaxed(uVar6 >> 0x20,*(long *)(lVar10 + 0x28) + 0x38);
      }
      lVar10 = param_1[1];
      uVar6 = *(ulong *)(lVar9 + 0x18);
      if (*(char *)(lVar10 + 0x20) == '\0') {
        if (*(int *)(*(code **)(lVar10 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104a38);
          (*pcVar2)();
        }
        (**(code **)(lVar10 + 0x30))(uVar6 & 0xffffffff,0x18,1,0);
        if (*(int *)(*(code **)(lVar10 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104a68);
          (*pcVar2)();
        }
        (**(code **)(lVar10 + 0x30))(uVar6 >> 0x20,0x3c,1,0);
      }
      else {
        writel_relaxed(uVar6,*(long *)(lVar10 + 0x28) + 0x18);
        writel_relaxed(uVar6 >> 0x20,*(long *)(lVar10 + 0x28) + 0x3c);
      }
      uVar5 = readl_relaxed(*param_1 + 0xc);
      writel_relaxed(uVar5 & 0xfffffffe,*param_1 + 0xc);
    }
    uVar7 = 0x133;
    if ((char)param_1[0x29] != '\0') {
      uVar7 = 0x1133;
    }
    writel_relaxed(uVar7,*param_1 + 0x304);
    writel_relaxed((int)param_1[0x18],*param_1 + 0x1c);
    tmc_enable_hw(param_1);
    lVar9 = *param_1;
    DataSynchronizationBarrier(3,3,0);
  }
  else {
    _dev_err(param_1[1] + 0x38,"Failed to enable : TMC not ready\n");
    lVar9 = *param_1;
    DataSynchronizationBarrier(3,3,0);
  }
  writel_relaxed(0,lVar9 + 0xfb0);
  return iVar3;
}



//------------------------------------------------------------
// tmc_pages_free @ 00104a70 size=228
// signature: undefined tmc_pages_free(void)
// callers: [tmc_alloc_sg_table, tmc_pages_alloc, tmc_etr_free_sg_buf, tmc_free_sg_table]
//------------------------------------------------------------

void tmc_pages_free(int *param_1,long param_2,undefined4 param_3)

{
  ulong uVar1;
  long lVar2;
  int *piVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (0 < *param_1) {
    lVar5 = 0;
    uVar4 = *(undefined8 *)(param_2 + 0x60);
    do {
      if ((*(long *)(param_1 + 2) != 0) &&
         (lVar2 = *(long *)(*(long *)(param_1 + 2) + lVar5 * 8), lVar2 != 0)) {
        dma_unmap_page_attrs(uVar4,lVar2,0x1000,param_3,0);
      }
      if ((*(long *)(param_1 + 4) != 0) &&
         (lVar2 = *(long *)(*(long *)(param_1 + 4) + lVar5 * 8), lVar2 != 0)) {
        __free_pages(lVar2,0);
      }
      lVar5 = lVar5 + 1;
    } while (lVar5 < *param_1);
  }
  uVar1 = is_vmalloc_addr(*(undefined8 *)(param_1 + 4));
  if ((uVar1 & 1) == 0) {
    kfree(*(undefined8 *)(param_1 + 4));
  }
  else {
    vfree();
  }
  piVar3 = param_1 + 2;
  uVar1 = is_vmalloc_addr(*(undefined8 *)piVar3);
  if ((uVar1 & 1) == 0) {
    kfree(*(undefined8 *)piVar3);
  }
  else {
    vfree();
  }
  *param_1 = 0;
  piVar3[0] = 0;
  piVar3[1] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00104b54 size=124
// signature: undefined readl_relaxed(void)
// callers: [tmc_get_rwp_offset, tmc_sync_etr_buf, __tmc_etr_enable_hw]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x104b9c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// tmc_pages_alloc @ 00104bd0 size=520
// signature: undefined tmc_pages_alloc(void)
// callers: [tmc_alloc_sg_table]
//------------------------------------------------------------

undefined8 tmc_pages_alloc(uint *param_1,long param_2,int param_3,undefined4 param_4,long param_5)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  uint *puVar12;
  
  uVar2 = *param_1;
  uVar10 = *(undefined8 *)(param_2 + 0x60);
  lVar11 = (long)(int)uVar2 << 3;
  if ((int)uVar2 < 0) {
    puVar12 = param_1 + 2;
    puVar12[0] = 0;
    puVar12[1] = 0;
    lVar5 = vmalloc(lVar11);
    *(long *)puVar12 = lVar5;
    if (lVar5 == 0) {
      return 0xfffffff4;
    }
    param_1[4] = 0;
    param_1[5] = 0;
  }
  else {
    lVar5 = __kmalloc(lVar11,0xdc0);
    *(long *)(param_1 + 2) = lVar5;
    if (lVar5 == 0) {
      lVar5 = vmalloc(lVar11);
      *(long *)(param_1 + 2) = lVar5;
      if (lVar5 == 0) {
        return 0xfffffff4;
      }
    }
    lVar5 = __kmalloc(lVar11,0xdc0);
    *(long *)(param_1 + 4) = lVar5;
    if (lVar5 != 0) goto LAB_00104c68;
  }
  puVar12 = param_1 + 2;
  lVar11 = vmalloc(lVar11);
  *(long *)(param_1 + 4) = lVar11;
  if (lVar11 == 0) {
    uVar9 = is_vmalloc_addr(*(undefined8 *)puVar12);
    if ((uVar9 & 1) == 0) {
      kfree(*(undefined8 *)puVar12);
    }
    else {
      vfree();
    }
    puVar12[0] = 0;
    puVar12[1] = 0;
    return 0xfffffff4;
  }
LAB_00104c68:
  uVar9 = (ulong)uVar2;
  if (0 < (int)uVar2) {
    lVar11 = 0;
    lVar5 = uVar9 * 8;
    do {
      if (param_5 == 0) {
LAB_00104cc4:
        iVar8 = param_3;
        if (param_3 == -1) {
          uVar9 = tpidr_el1;
          iVar8 = 0;
        }
        lVar6 = __alloc_pages(uVar9,0xdc0,0,iVar8,0);
        if (lVar6 == 0) goto LAB_00104d60;
      }
      else {
        uVar9 = 0;
        if (*(long *)(param_5 + lVar11) == 0) goto LAB_00104cc4;
        lVar7 = (((*(long *)(param_5 + lVar11) << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40;
        lVar6 = lVar7 + -0x200000000;
        uVar9 = *(ulong *)(lVar7 + -0x1fffffff8);
        lVar7 = lVar6;
        if ((uVar9 & 1) != 0) {
          lVar7 = uVar9 - 1;
        }
        piVar1 = (int *)(lVar7 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = *piVar1 + 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      lVar7 = dma_map_page_attrs(uVar10,lVar6,0,0x1000,param_4,0);
      if (lVar7 == -1) {
LAB_00104d60:
        tmc_pages_free(param_1,param_2,param_4);
        return 0xfffffff4;
      }
      *(long *)(*(long *)(param_1 + 2) + lVar11) = lVar7;
      uVar9 = *(ulong *)(param_1 + 4);
      *(long *)(uVar9 + lVar11) = lVar6;
      lVar11 = lVar11 + 8;
    } while (lVar5 != lVar11);
  }
  return 0;
}



//------------------------------------------------------------
// tmc_etr_alloc_flat_buf @ 00104dec size=264
// signature: undefined tmc_etr_alloc_flat_buf(void)
// callers: [tmc_alloc_etr_buf]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 tmc_etr_alloc_flat_buf(long param_1,long param_2,undefined8 param_3,long param_4)

{
  undefined8 uVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  if (param_4 == 0) {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 8) + 0x98);
    plVar2 = (long *)kmalloc_trace(_arm64_use_ng_mappings,0xdc0,0x28);
    if (plVar2 == (long *)0x0) {
      uVar1 = 0xfffffff4;
    }
    else {
      plVar3 = (long *)dma_alloc_noncontiguous(uVar1,*(undefined8 *)(param_2 + 0x10),2,0x2cc0,0);
      plVar2[4] = (long)plVar3;
      if (plVar3 == (long *)0x0) {
        kfree(plVar2);
        uVar1 = 0xfffffff4;
      }
      else {
        uVar5 = *(undefined8 *)(param_2 + 0x10);
        lVar7 = *(long *)(*plVar3 + 0x10);
        plVar2[1] = lVar7;
        lVar4 = dma_vmap_noncontiguous(uVar1,uVar5,plVar3);
        lVar6 = *(long *)(param_2 + 0x10);
        plVar2[2] = lVar4;
        if (lVar4 == 0) {
          dma_free_noncontiguous(uVar1,lVar6,plVar3,2);
          uVar1 = 0xfffffff4;
          plVar2[4] = 0;
        }
        else {
          lVar4 = *(long *)(param_1 + 8);
          uVar1 = 0;
          plVar2[3] = lVar6;
          *(long *)(param_2 + 0x18) = lVar7;
          *(undefined4 *)(param_2 + 4) = 0;
          *(long **)(param_2 + 0x38) = plVar2;
          *plVar2 = lVar4 + 0x38;
        }
      }
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// tmc_etr_sync_flat_buf @ 00104ef8 size=228
// signature: undefined tmc_etr_sync_flat_buf(void)
// callers: []
//------------------------------------------------------------

void tmc_etr_sync_flat_buf(long param_1,long param_2,long param_3)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  long *plVar5;
  ulong uVar6;
  uint uVar7;
  
  plVar5 = *(long **)(param_1 + 0x38);
  lVar1 = param_2 - *(long *)(param_1 + 0x18);
  uVar4 = *(undefined8 *)(*plVar5 + 0x60);
  *(long *)(param_1 + 0x20) = lVar1;
  if (*(char *)(param_1 + 8) == '\0') {
    uVar6 = param_3 - param_2;
    uVar3 = *(ulong *)(param_1 + 0x10);
  }
  else {
    uVar3 = *(ulong *)(param_1 + 0x10);
    uVar6 = uVar3;
  }
  *(ulong *)(param_1 + 0x28) = uVar6;
  plVar2 = (long *)plVar5[4];
  if (uVar3 < uVar6 + lVar1) {
    dma_sync_sg_for_cpu(uVar4,*plVar2,*(undefined4 *)((long)plVar2 + 0xc),2);
  }
  else if (*(int *)((long)plVar2 + 0xc) != 0) {
    uVar7 = 0;
    lVar1 = *plVar2;
    do {
      dma_sync_sg_for_cpu(uVar4,lVar1,1,2);
      uVar6 = uVar6 - *(uint *)(lVar1 + 0xc);
      if ((long)uVar6 < 1) {
        return;
      }
      uVar7 = uVar7 + 1;
      lVar1 = sg_next(lVar1);
    } while (uVar7 < *(uint *)(plVar5[4] + 0xc));
  }
  return;
}



//------------------------------------------------------------
// tmc_etr_get_data_flat_buf @ 00104fe0 size=24
// signature: undefined tmc_etr_get_data_flat_buf(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_etr_get_data_flat_buf(long param_1,long param_2,undefined8 param_3,long *param_4)

{
  *param_4 = *(long *)(*(long *)(param_1 + 0x38) + 0x10) + param_2;
  return param_3;
}



//------------------------------------------------------------
// tmc_etr_free_flat_buf @ 00104ffc size=116
// signature: undefined tmc_etr_free_flat_buf(void)
// callers: []
//------------------------------------------------------------

void tmc_etr_free_flat_buf(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  
  plVar1 = *(long **)(param_1 + 0x38);
  if ((plVar1 != (long *)0x0) && (plVar1[1] != 0)) {
    uVar2 = *(undefined8 *)(*plVar1 + 0x60);
    dma_vunmap_noncontiguous(uVar2,plVar1[2]);
    dma_free_noncontiguous(uVar2,*(undefined8 *)(param_1 + 0x10),plVar1[4],2);
    plVar1[2] = 0;
    plVar1[4] = 0;
  }
  kfree(plVar1);
  return;
}



//------------------------------------------------------------
// tmc_etr_alloc_sg_buf @ 00105074 size=564
// signature: undefined tmc_etr_alloc_sg_buf(void)
// callers: [tmc_alloc_etr_buf]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 tmc_etr_alloc_sg_buf(long param_1,long param_2,undefined4 param_3,undefined8 param_4)

{
  long lVar1;
  ulong *puVar2;
  ulong *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 uVar12;
  ulong uVar13;
  long lVar14;
  
  lVar14 = *(long *)(param_1 + 8);
  uVar13 = *(ulong *)(param_2 + 0x10);
  puVar2 = (ulong *)kmalloc_trace(_arm64_use_ng_mappings,0xdc0,0x10);
  if (puVar2 != (ulong *)0x0) {
    uVar13 = uVar13 >> 0xc;
    uVar4 = (uint)uVar13;
    if (uVar4 < 0x3ff) {
      iVar5 = 0;
    }
    else {
      iVar5 = (int)((ulong)(long)(int)uVar4 / 0x3ff) - (uint)((ulong)(long)(int)uVar4 % 0x3ff < 2);
    }
    puVar3 = (ulong *)tmc_alloc_sg_table(lVar14 + 0x38,param_3,
                                         (long)(int)(iVar5 + uVar4) + 0x3ffU >> 10,uVar13,param_4);
    if (puVar3 < (ulong *)0xfffffffffffff001) {
      *puVar2 = (ulong)puVar3;
      puVar2[1] = puVar3[3];
      uVar4 = (uint)puVar3[8];
      uVar13 = puVar3[9];
      if (uVar4 < 0x3ff) {
        iVar5 = 0;
      }
      else {
        iVar5 = (int)((ulong)(long)(int)uVar4 / 0x3ff) - (uint)((ulong)(long)(int)uVar4 % 0x3ff < 2)
        ;
      }
      puVar6 = (uint *)puVar3[1];
      iVar5 = uVar4 + iVar5 + -1;
      if (iVar5 < 1) {
        lVar14 = 0;
      }
      else {
        iVar8 = 0;
        uVar4 = 0;
        iVar9 = 0;
        uVar10 = puVar3[6];
        puVar7 = puVar6;
        do {
          lVar14 = (long)iVar8;
          lVar1 = uVar10 + (long)(iVar9 + 1) * 8;
          if (uVar4 != 0x3ff) {
            iVar8 = iVar8 + 1;
            lVar1 = uVar13 + lVar14 * 8;
          }
          uVar11 = 2;
          if (uVar4 == 0x3ff) {
            uVar11 = 3;
          }
          uVar4 = uVar4 + 1 & 0x3ff;
          if (uVar4 == 0) {
            iVar9 = iVar9 + 1;
          }
          iVar5 = iVar5 + -1;
          puVar6 = puVar7 + 1;
          *puVar7 = *(uint *)(lVar1 + 1) & 0xfffffff0 | uVar11;
          puVar7 = puVar6;
        } while (iVar5 != 0);
        lVar14 = (long)iVar8;
      }
      *puVar6 = (uint)((ulong)*(undefined8 *)(uVar13 + lVar14 * 8) >> 8) & 0xfffffff0 | 1;
      if (0 < (int)puVar3[5]) {
        lVar14 = 0;
        uVar12 = *(undefined8 *)(*puVar3 + 0x60);
        do {
          dma_sync_single_for_device(uVar12,*(undefined8 *)(puVar3[6] + lVar14 * 8),0x1000,1);
          lVar14 = lVar14 + 1;
        } while (lVar14 < (int)puVar3[5]);
      }
    }
    else {
      kfree(puVar2);
      puVar2 = puVar3;
    }
    if (puVar2 < (ulong *)0xfffffffffffff001) {
      uVar13 = puVar2[1];
      *(ulong **)(param_2 + 0x38) = puVar2;
      *(ulong *)(param_2 + 0x18) = uVar13;
      *(undefined4 *)(param_2 + 4) = 1;
      return 0;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// tmc_etr_sync_sg_buf @ 001052ac size=380
// signature: undefined tmc_etr_sync_sg_buf(void)
// callers: []
//------------------------------------------------------------

void tmc_etr_sync_sg_buf(long param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  ulong *puVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  long *plVar11;
  ulong uVar12;
  int iVar13;
  ulong uVar14;
  
  plVar11 = (long *)**(undefined8 **)(param_1 + 0x38);
  uVar1 = *(uint *)(plVar11 + 8);
  if (0 < (int)uVar1) {
    puVar8 = (ulong *)plVar11[9];
    uVar12 = param_2;
    puVar6 = puVar8;
    uVar14 = (ulong)uVar1;
    do {
      uVar7 = *puVar6;
      if ((uVar7 <= param_2 && param_2 <= uVar7 + 0x1000) &&
          (param_2 < uVar7 || uVar7 + 0x1000 != param_2)) {
        uVar14 = uVar12 - uVar7;
        if (-1 < (long)uVar14) {
          lVar4 = 0;
          goto LAB_00105324;
        }
        break;
      }
      uVar12 = uVar12 + 0x1000;
      uVar14 = uVar14 - 1;
      puVar6 = puVar6 + 1;
    } while (uVar14 != 0);
  }
  lVar4 = *plVar11;
  pcVar5 = "Unable to map RRP %llx to offset\n";
  param_3 = param_2;
  goto LAB_0010540c;
  while( true ) {
    lVar4 = lVar4 + -0x1000;
    puVar8 = puVar8 + 1;
    uVar7 = uVar7 + 0x1000;
    if ((ulong)uVar1 * 0x1000 + lVar4 == 0) break;
LAB_00105324:
    uVar9 = *puVar8;
    if ((uVar9 <= param_3 && param_3 <= uVar9 + 0x1000) &&
        (param_3 < uVar9 || uVar9 + 0x1000 != param_3)) {
      lVar4 = (param_3 - uVar9) - lVar4;
      if (-1 < lVar4) {
        *(ulong *)(param_1 + 0x20) = uVar14;
        if (*(char *)(param_1 + 8) == '\0') {
          if (lVar4 < (long)uVar14) {
            lVar4 = *(long *)(param_1 + 0x10);
          }
          else {
            lVar4 = 0;
          }
          lVar4 = (((lVar4 + uVar7) - uVar9) + param_3) - uVar12;
        }
        else {
          lVar4 = *(long *)(param_1 + 0x10);
        }
        uVar14 = uVar14 >> 0xc;
        uVar12 = lVar4 + 0xfffU >> 0xc;
        *(long *)(param_1 + 0x28) = lVar4;
        if ((int)uVar12 + (int)uVar14 <= (int)uVar14) {
          return;
        }
        uVar10 = *(undefined8 *)(*plVar11 + 0x60);
        do {
          iVar2 = (int)plVar11[8];
          iVar3 = 0;
          iVar13 = (int)uVar14;
          if (iVar2 != 0) {
            iVar3 = iVar13 / iVar2;
          }
          dma_sync_single_for_cpu
                    (uVar10,*(undefined8 *)(plVar11[9] + (long)(iVar13 - iVar3 * iVar2) * 8),0x1000,
                     2);
          uVar14 = (ulong)(iVar13 + 1);
          uVar1 = (int)uVar12 - 1;
          uVar12 = (ulong)uVar1;
        } while (uVar1 != 0);
        return;
      }
      break;
    }
  }
  lVar4 = *plVar11;
  pcVar5 = "Unable to map RWP %llx to offset\n";
LAB_0010540c:
  _dev_warn(lVar4,pcVar5,param_3);
  *(undefined8 *)(param_1 + 0x28) = 0;
  return;
}



//------------------------------------------------------------
// tmc_etr_get_data_sg_buf @ 0010542c size=108
// signature: undefined tmc_etr_get_data_sg_buf(void)
// callers: []
//------------------------------------------------------------

ulong tmc_etr_get_data_sg_buf(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar2 = (long)*(int *)(**(long **)(param_1 + 0x38) + 0x40) * 0x1000;
  uVar1 = uVar2 - param_2;
  if (uVar2 < param_2 || uVar1 == 0) {
    return 0xffffffffffffffea;
  }
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  uVar2 = 0x1000 - (param_2 & 0xfff);
  if (uVar2 <= uVar1) {
    uVar1 = uVar2;
  }
  if (uVar1 != 0) {
    *param_4 = ((*(ulong *)(*(long *)(**(long **)(param_1 + 0x38) + 0x50) +
                           (long)(int)(param_2 >> 0xc) * 8) & 0x3ffffffffffc0) << 6 |
               0xff00000000000000) + (param_2 & 0xfff);
  }
  return uVar1;
}



//------------------------------------------------------------
// tmc_etr_free_sg_buf @ 001054a4 size=116
// signature: undefined tmc_etr_free_sg_buf(void)
// callers: []
//------------------------------------------------------------

void tmc_etr_free_sg_buf(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0x38);
  if (puVar1 != (undefined8 *)0x0) {
    puVar2 = (undefined8 *)*puVar1;
    if (puVar2[1] != 0) {
      vunmap();
    }
    tmc_pages_free(puVar2 + 5,*puVar2,1);
    if (puVar2[2] != 0) {
      vunmap();
    }
    tmc_pages_free(puVar2 + 8,*puVar2,2);
    kfree(puVar2);
    kfree(puVar1);
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00105518 size=132
// signature: undefined writel_relaxed(void)
// callers: [__tmc_etr_disable_hw, tmc_update_etr_buffer, __tmc_etr_enable_hw]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x105530,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10556c,uVar1);
  return;
}



//------------------------------------------------------------
// tmc_sync_etr_buf @ 0010559c size=424
// signature: undefined tmc_sync_etr_buf(void)
// callers: [__tmc_etr_disable_hw, tmc_update_etr_buffer]
//------------------------------------------------------------

void tmc_sync_etr_buf(long *param_1)

{
  uint uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  code *pcVar6;
  long lVar7;
  long lVar8;
  
  lVar8 = param_1[1];
  lVar7 = param_1[0xe];
  pcVar6 = *(code **)(lVar8 + 0x28);
  if (*(char *)(lVar8 + 0x20) == '\0') {
    if (*(int *)(pcVar6 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1056ac);
      (*pcVar6)();
    }
    uVar2 = (*pcVar6)(0x14,1,0);
    if (*(int *)(*(code **)(lVar8 + 0x28) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1056dc);
      (*pcVar6)();
    }
    uVar3 = (**(code **)(lVar8 + 0x28))(0x38,1,0);
  }
  else {
    uVar2 = readl_relaxed(pcVar6 + 0x14);
    uVar2 = uVar2 & 0xffffffff;
    uVar3 = readl_relaxed(*(long *)(lVar8 + 0x28) + 0x38);
    uVar3 = uVar3 & 0xffffffff;
  }
  lVar8 = param_1[1];
  pcVar6 = *(code **)(lVar8 + 0x28);
  if (*(char *)(lVar8 + 0x20) == '\0') {
    if (*(int *)(pcVar6 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10570c);
      (*pcVar6)();
    }
    uVar4 = (*pcVar6)(0x18,1,0);
    if (*(int *)(*(code **)(lVar8 + 0x28) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10573c);
      (*pcVar6)();
    }
    uVar5 = (**(code **)(lVar8 + 0x28))(0x3c,1,0);
  }
  else {
    uVar4 = readl_relaxed(pcVar6 + 0x18);
    uVar4 = uVar4 & 0xffffffff;
    uVar5 = readl_relaxed(*(long *)(lVar8 + 0x28) + 0x3c);
    uVar5 = uVar5 & 0xffffffff;
  }
  uVar1 = readl_relaxed(*param_1 + 0xc);
  if ((uVar1 >> 5 & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10574c);
    (*pcVar6)();
  }
  *(byte *)(lVar7 + 8) = (byte)uVar1 & 1;
  if ((*(long *)(lVar7 + 0x30) == 0) ||
     (pcVar6 = *(code **)(*(long *)(lVar7 + 0x30) + 8), pcVar6 == (code *)0x0)) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x105648);
    (*pcVar6)();
  }
  if (*(int *)(pcVar6 + -4) != -0x2a1b9fa1) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10566c);
    (*pcVar6)();
  }
  (*pcVar6)(lVar7,uVar2 | uVar3 << 0x20,uVar4 | uVar5 << 0x20);
  return;
}



//------------------------------------------------------------
// tmc_alloc_etr_buf @ 00105758 size=380
// signature: undefined tmc_alloc_etr_buf(void)
// callers: [tmc_alloc_etr_buffer, tmc_enable_etr_sink_sysfs]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * tmc_alloc_etr_buf(long param_1,long param_2,undefined4 param_3)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined4 *puVar6;
  code *pcVar7;
  undefined **ppuVar8;
  
  uVar1 = *(uint *)(param_1 + 0xc4);
  lVar5 = iommu_get_domain_for_dev(*(undefined8 *)(*(long *)(param_1 + 8) + 0x98));
  if (lVar5 == 0) {
    bVar2 = false;
  }
  else {
    uVar3 = qcom_iommu_get_mappings_configuration();
    if ((int)uVar3 < 0) {
      return (undefined4 *)0xfffffffffffffff4;
    }
    bVar2 = (uVar3 & 1) == 0;
  }
  puVar6 = (undefined4 *)kmalloc_trace(_arm64_use_ng_mappings,0xdc0,0x40);
  if (puVar6 == (undefined4 *)0x0) {
    return (undefined4 *)0xfffffffffffffff4;
  }
  if (param_2 < 0x100000) {
    bVar2 = true;
  }
  *(long *)(puVar6 + 4) = param_2;
  if (((uVar1 & 1) == 0) || (bVar2)) {
    if ((etr_buf_ops == (undefined *)0x0) || (pcVar7 = *(code **)etr_buf_ops, pcVar7 == (code *)0x0)
       ) {
      iVar4 = -0x16;
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x2096832a) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105814);
        (*pcVar7)();
      }
      iVar4 = (*pcVar7)(param_1,puVar6,param_3,0);
      if (iVar4 == 0) {
        ppuVar8 = &etr_buf_ops;
        goto LAB_001058c0;
      }
    }
    if ((uVar1 & 1) == 0) goto LAB_00105890;
  }
  if ((PTR_etr_sg_buf_ops_001091c0 == (undefined *)0x0) ||
     (pcVar7 = *(code **)PTR_etr_sg_buf_ops_001091c0, pcVar7 == (code *)0x0)) {
    iVar4 = -0x16;
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x2096832a) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105874);
      (*pcVar7)();
    }
    iVar4 = (*pcVar7)(param_1,puVar6,param_3,0);
    if (iVar4 == 0) {
      ppuVar8 = &PTR_etr_sg_buf_ops_001091c0;
LAB_001058c0:
      *(undefined **)(puVar6 + 0xc) = *ppuVar8;
      *puVar6 = 1;
      return puVar6;
    }
  }
LAB_00105890:
  kfree(puVar6);
  return (undefined4 *)(long)iVar4;
}



//------------------------------------------------------------
// tmc_enable_etr_sink @ 001058d8 size=444
// signature: undefined tmc_enable_etr_sink(void)
// callers: []
//------------------------------------------------------------

int tmc_enable_etr_sink(long param_1,int param_2,undefined8 param_3)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  int *piVar8;
  long lVar9;
  long lVar10;
  
  lVar9 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  if (param_2 != 2) {
    if (param_2 == 1) {
      mutex_lock(lVar9 + 0x90);
      iVar5 = tmc_enable_etr_sink_sysfs(param_1);
      mutex_unlock(lVar9 + 0x90);
      return iVar5;
    }
    return -0x16;
  }
  lVar6 = perf_get_aux(param_3);
  if (lVar6 == 0) {
    lVar6 = 0;
  }
  else {
    lVar6 = *(long *)(lVar6 + 0x38);
  }
  uVar7 = _raw_spin_lock_irqsave(lVar9 + 0x60);
  if ((*(uint *)(lVar9 + 0x84) | 2) != 3) {
    if ((lVar6 == 0) || (lVar10 = *(long *)(lVar6 + 8), lVar10 == 0)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1059f0);
      (*pcVar4)();
    }
    iVar5 = *(int *)(lVar9 + 100);
    iVar1 = *(int *)(lVar6 + 0x10);
    if ((iVar5 == -1) || (iVar5 == iVar1)) {
      if (iVar5 == iVar1) {
        piVar8 = *(int **)(param_1 + 0x3c8);
        Hint_Prefetch(piVar8,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar8,0x10);
          if (bVar3) {
            *piVar8 = *piVar8 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      else {
        if ((*(int *)(lVar10 + 4) == 1) && ((*(byte *)(lVar9 + 0xc4) & 1) == 0)) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105a80);
          (*pcVar4)();
        }
        if (*(long *)(lVar9 + 0x70) != 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105a74);
          (*pcVar4)();
        }
        iVar5 = coresight_claim_device(*(undefined8 *)(lVar9 + 8));
        if (iVar5 != 0) goto LAB_00105978;
        *(long *)(lVar9 + 0x70) = lVar10;
        iVar5 = __tmc_etr_enable_hw(lVar9);
        if (iVar5 != 0) {
          *(undefined8 *)(lVar9 + 0x70) = 0;
          coresight_disclaim_device(*(undefined8 *)(lVar9 + 8));
          goto LAB_00105978;
        }
        *(int *)(lVar9 + 100) = iVar1;
        *(undefined4 *)(lVar9 + 0x84) = 2;
        *(undefined8 *)(lVar9 + 0x118) = *(undefined8 *)(lVar6 + 8);
        piVar8 = *(int **)(param_1 + 0x3c8);
        Hint_Prefetch(piVar8,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar8,0x10);
          if (bVar3) {
            *piVar8 = *piVar8 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      iVar5 = 0;
      goto LAB_00105978;
    }
  }
  iVar5 = -0x10;
LAB_00105978:
  _raw_spin_unlock_irqrestore(lVar9 + 0x60,uVar7);
  return iVar5;
}



//------------------------------------------------------------
// tmc_disable_etr_sink @ 00105ab8 size=164
// signature: undefined tmc_disable_etr_sink(void)
// callers: []
//------------------------------------------------------------

undefined4 tmc_disable_etr_sink(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  uVar3 = _raw_spin_lock_irqsave(lVar4 + 0x60);
  iVar1 = *(int *)(lVar4 + 0x84);
  _raw_spin_unlock_irqrestore(lVar4 + 0x60,uVar3);
  if (iVar1 == 2) {
    uVar2 = _tmc_disable_etr_sink(param_1,0);
  }
  else if (iVar1 == 1) {
    mutex_lock(lVar4 + 0x90);
    uVar2 = _tmc_disable_etr_sink(param_1,0);
    mutex_unlock(lVar4 + 0x90);
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// tmc_alloc_etr_buffer @ 00105b60 size=828
// signature: undefined tmc_alloc_etr_buffer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * tmc_alloc_etr_buffer(long param_1,long param_2,long param_3,uint param_4,byte param_5)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  long *plVar8;
  uint *puVar9;
  undefined8 uVar10;
  code *pcVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  
  lVar14 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  plVar8 = (long *)kmalloc_node_trace(_arm64_use_ng_mappings,0xdc0,
                                      -(uint)(*(int *)(param_2 + 0x28c) == -1),0x28);
  if (plVar8 == (long *)0x0) {
    return (long *)0x0;
  }
  if (*(int *)(param_2 + 0x28c) == -1) {
    uVar4 = *(uint *)(lVar14 + 0x7c);
    if (param_4 << 0xc <= uVar4) {
LAB_00105c5c:
      uVar13 = (ulong)uVar4;
      do {
        puVar9 = (uint *)tmc_alloc_etr_buf(lVar14,uVar13,0xffffffff);
        if (puVar9 < (uint *)0xfffffffffffff001) goto LAB_00105dc4;
        uVar12 = uVar13 >> 0x15;
        uVar13 = uVar13 >> 1;
      } while (uVar12 != 0);
      goto LAB_00105dcc;
    }
    puVar9 = (uint *)tmc_alloc_etr_buf(lVar14,-(ulong)(param_4 >> 0x1f) & 0xfffff00000000000 |
                                              (ulong)param_4 << 0xc,0xffffffff);
    if ((uint *)0xfffffffffffff000 < puVar9) {
      uVar4 = *(uint *)(lVar14 + 0x7c);
      goto LAB_00105c5c;
    }
  }
  else {
    lVar1 = lVar14 + 0xe0;
    iVar3 = *(int *)(*(long *)(param_2 + 0x2a0) + 0x630);
    mutex_lock(lVar1);
    lVar2 = lVar14 + 200;
    puVar9 = (uint *)idr_find(lVar2,(long)iVar3);
    if (puVar9 == (uint *)0x0) {
      do {
        mutex_unlock(lVar1);
        uVar4 = *(uint *)(lVar14 + 0x7c);
        iVar7 = -(uint)(*(int *)(param_2 + 0x28c) == -1);
        if (uVar4 < param_4 << 0xc) {
          puVar9 = (uint *)tmc_alloc_etr_buf(lVar14,-(ulong)(param_4 >> 0x1f) & 0xfffff00000000000 |
                                                    (ulong)param_4 << 0xc,iVar7);
          if ((uint *)0xfffffffffffff000 < puVar9) {
            uVar4 = *(uint *)(lVar14 + 0x7c);
            goto LAB_00105ce4;
          }
        }
        else {
LAB_00105ce4:
          uVar13 = (ulong)uVar4;
          while (puVar9 = (uint *)tmc_alloc_etr_buf(lVar14,uVar13,iVar7),
                (uint *)0xfffffffffffff000 < puVar9) {
            uVar12 = uVar13 >> 0x15;
            uVar13 = uVar13 >> 1;
            if (uVar12 == 0) goto LAB_00105dcc;
          }
        }
        if ((uint *)0xfffffffffffff000 < puVar9) goto LAB_00105dc4;
        mutex_lock(lVar1);
        iVar7 = idr_alloc(lVar2,puVar9,iVar3,iVar3 + 1,0xcc0);
        mutex_unlock(lVar1);
        if (iVar7 != -0x1c) {
          if (iVar7 != -0xc) goto LAB_00105dc4;
          if ((*(long *)(puVar9 + 0xc) == 0) ||
             (pcVar11 = *(code **)(*(long *)(puVar9 + 0xc) + 0x18), pcVar11 == (code *)0x0)) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105e54);
            (*pcVar11)();
          }
          if (*(int *)(pcVar11 + -4) != -0x1fa83ec2) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x105e78);
            (*pcVar11)();
          }
          (*pcVar11)(puVar9);
          kfree(puVar9);
          goto LAB_00105dcc;
        }
        if ((*(long *)(puVar9 + 0xc) == 0) ||
           (pcVar11 = *(code **)(*(long *)(puVar9 + 0xc) + 0x18), pcVar11 == (code *)0x0)) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x800,0x105d70);
          (*pcVar11)();
        }
        if (*(int *)(pcVar11 + -4) != -0x1fa83ec2) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x105d94);
          (*pcVar11)();
        }
        (*pcVar11)(puVar9);
        kfree(puVar9);
        mutex_lock(lVar1);
        puVar9 = (uint *)idr_find(lVar2,(long)iVar3);
      } while (puVar9 == (uint *)0x0);
    }
    Hint_Prefetch(puVar9,2,0,1);
    do {
      uVar4 = *puVar9;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar9,0x10);
      if (bVar6) {
        *puVar9 = uVar4 + 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    if (uVar4 == 0) {
      uVar10 = 2;
LAB_00105eac:
      refcount_warn_saturate(puVar9,uVar10);
    }
    else if ((int)(uVar4 + 1 | uVar4) < 0) {
      uVar10 = 1;
      goto LAB_00105eac;
    }
    mutex_unlock(lVar1);
  }
LAB_00105dc4:
  if (puVar9 < (uint *)0xfffffffffffff001) {
    *plVar8 = lVar14;
    plVar8[1] = (long)puVar9;
    if (plVar8 < (long *)0xfffffffffffff001) {
      *(undefined4 *)(plVar8 + 2) = *(undefined4 *)(*(long *)(param_2 + 0x2a0) + 0x630);
      *(byte *)((long)plVar8 + 0x14) = param_5 & 1;
      plVar8[4] = param_3;
      *(uint *)(plVar8 + 3) = param_4;
      return plVar8;
    }
    return (long *)0x0;
  }
LAB_00105dcc:
  kfree(plVar8);
  return (long *)0x0;
}



//------------------------------------------------------------
// tmc_free_etr_buffer @ 00105ebc size=256
// signature: undefined tmc_free_etr_buffer(void)
// callers: []
//------------------------------------------------------------

void tmc_free_etr_buffer(long *param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  int *piVar4;
  code *pcVar5;
  int *piVar6;
  long lVar7;
  long lVar8;
  
  piVar6 = (int *)param_1[1];
  if (piVar6 != (int *)0x0) {
    lVar8 = *param_1;
    lVar7 = lVar8 + 0xe0;
    mutex_lock(lVar7);
    Hint_Prefetch(piVar6,2,0,1);
    do {
      iVar1 = *piVar6;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar6,0x10);
      if (bVar3) {
        *piVar6 = iVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (iVar1 == 1) {
      DataMemoryBarrier(2,1);
      piVar4 = (int *)idr_remove(lVar8 + 200,(long)(int)param_1[2]);
      mutex_unlock(lVar7);
      if ((piVar4 != (int *)0x0) && (piVar4 != piVar6)) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x105f78);
        (*pcVar5)();
      }
      lVar7 = param_1[1];
      if ((*(long *)(lVar7 + 0x30) == 0) ||
         (pcVar5 = *(code **)(*(long *)(lVar7 + 0x30) + 0x18), pcVar5 == (code *)0x0)) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x105f40);
        (*pcVar5)();
      }
      if (*(int *)(pcVar5 + -4) != -0x1fa83ec2) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x105f64);
        (*pcVar5)();
      }
      (*pcVar5)(lVar7);
      kfree(lVar7);
    }
    else {
      if (iVar1 < 1) {
        refcount_warn_saturate(piVar6,3);
      }
      mutex_unlock(lVar7);
    }
  }
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// tmc_update_etr_buffer @ 00105fdc size=772
// signature: undefined tmc_update_etr_buffer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong tmc_update_etr_buffer(long param_1,long param_2,long param_3)

{
  long *plVar1;
  bool bVar2;
  undefined8 uVar3;
  ulong uVar4;
  size_t __n;
  ulong uVar5;
  code *pcVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  long lVar14;
  ulong uVar15;
  undefined8 *local_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_3 + 8);
  plVar13 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  plVar1 = plVar13 + 0xc;
  uVar3 = _raw_spin_lock_irqsave(plVar1);
  if (**(int **)(param_1 + 0x3c8) != 1) {
    _raw_spin_unlock_irqrestore(plVar1,uVar3);
    uVar4 = 0;
    goto LAB_00106290;
  }
  if (plVar13[0x23] != lVar12) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1062d8);
    (*pcVar6)();
  }
  writel_relaxed(0xc5acce55,*plVar13 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  tmc_flush_and_stop(plVar13);
  tmc_sync_etr_buf(plVar13);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*plVar13 + 0xfb0);
  _raw_spin_unlock_irqrestore(plVar1,uVar3);
  uVar10 = *(ulong *)(lVar12 + 0x20);
  uVar4 = *(ulong *)(lVar12 + 0x28);
  if ((*(char *)(param_3 + 0x14) == '\0') && (*(ulong *)(param_2 + 0x18) < uVar4)) {
    uVar4 = tmc_get_memwidth_mask(plVar13);
    uVar4 = *(ulong *)(param_2 + 0x18) & uVar4 & 0xffffffff;
    uVar5 = *(ulong *)(lVar12 + 0x10);
    uVar10 = (*(long *)(lVar12 + 0x20) - uVar4) + *(long *)(lVar12 + 0x28);
    uVar9 = 0;
    if (uVar5 <= uVar10) {
      uVar9 = uVar5;
    }
    uVar10 = uVar10 - uVar9;
LAB_00106104:
    uVar5 = uVar5 - uVar10;
    if (0xf < uVar5) {
      uVar5 = 0x10;
    }
    pcVar6 = *(code **)(*(long *)(lVar12 + 0x30) + 0x10);
    local_70 = (undefined8 *)0x0;
    if (*(int *)(pcVar6 + -4) != -0x408d4ef0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106144);
      (*pcVar6)();
    }
    lVar12 = (*pcVar6)(lVar12,uVar10,uVar5,&local_70);
    uVar3 = _memset;
    if (lVar12 < 0x10) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1062f0);
      (*pcVar6)();
    }
    if (local_70 != (undefined8 *)0x0) {
      *local_70 = _coresight_barrier_pkt;
      local_70[1] = uVar3;
    }
    bVar2 = true;
  }
  else {
    if (*(char *)(lVar12 + 8) != '\0') {
      uVar5 = *(ulong *)(lVar12 + 0x10);
      goto LAB_00106104;
    }
    bVar2 = false;
  }
  local_70 = (undefined8 *)0x0;
  if (uVar4 != 0) {
    lVar12 = *(long *)(param_3 + 8);
    lVar14 = *(long *)(param_3 + 0x20);
    uVar9 = (long)*(int *)(param_3 + 0x18) * 0x1000;
    uVar5 = 0;
    if (uVar9 != 0) {
      uVar5 = *(ulong *)(param_2 + 0x28) / uVar9;
    }
    uVar7 = *(ulong *)(param_2 + 0x28) - uVar5 * uVar9;
    uVar5 = uVar7 & 0xfff;
    uVar9 = uVar4;
    uVar7 = uVar7 >> 0xc;
    do {
      uVar8 = *(ulong *)(lVar12 + 0x10);
      uVar15 = 0;
      if (uVar8 <= uVar10) {
        uVar15 = uVar8;
      }
      lVar11 = uVar10 - uVar15;
      uVar10 = uVar8 - lVar11;
      if (uVar9 <= uVar8 - lVar11) {
        uVar10 = uVar9;
      }
      pcVar6 = *(code **)(*(long *)(lVar12 + 0x30) + 0x10);
      if (*(int *)(pcVar6 + -4) != -0x408d4ef0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x106200);
        (*pcVar6)();
      }
      __n = (*pcVar6)(lVar12,lVar11,uVar10,&local_70);
      if ((long)__n < 1) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x106258);
        (*pcVar6)();
      }
      if ((long)(0x1000 - uVar5) <= (long)__n) {
        __n = 0x1000 - uVar5;
      }
      memcpy((void *)(*(long *)(lVar14 + uVar7 * 8) + uVar5),local_70,__n);
      uVar9 = uVar9 - __n;
      uVar5 = __n + uVar5;
      uVar15 = uVar7;
      if (uVar5 == 0x1000) {
        uVar5 = 0;
        uVar15 = 0;
        if (uVar7 + 1 != (long)*(int *)(param_3 + 0x18)) {
          uVar15 = uVar7 + 1;
        }
      }
      uVar10 = __n + lVar11;
      uVar7 = uVar15;
    } while (uVar9 != 0);
  }
  if (*(char *)(param_3 + 0x14) != '\0') {
    *(ulong *)(param_2 + 0x28) = *(long *)(param_2 + 0x28) + uVar4;
  }
  DataMemoryBarrier(2,2);
  if ((bVar2) && (*(char *)(param_3 + 0x14) == '\0')) {
    perf_aux_output_flag(param_2,1);
  }
LAB_00106290:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// tmc_etr_byte_cntr_start @ 00106304 size=88
// signature: undefined tmc_etr_byte_cntr_start(void)
// callers: [tmc_enable_etr_sink_sysfs]
//------------------------------------------------------------

void tmc_etr_byte_cntr_start(long param_1)

{
  if (param_1 != 0) {
    mutex_lock(param_1 + 0x148);
    if ((*(int *)(param_1 + 0x98) != 0) && (*(char *)(param_1 + 0x91) == '\0')) {
      *(undefined4 *)(param_1 + 0xa0) = 0;
      *(undefined1 *)(param_1 + 0x90) = 1;
    }
    mutex_unlock(param_1 + 0x148);
  }
  return;
}



//------------------------------------------------------------
// tmc_etr_byte_cntr_stop @ 00106360 size=120
// signature: undefined tmc_etr_byte_cntr_stop(void)
// callers: [_tmc_disable_etr_sink]
//------------------------------------------------------------

void tmc_etr_byte_cntr_stop(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    mutex_lock(param_1 + 0x148);
    uVar1 = tmc_get_rwp_offset(*(undefined8 *)(param_1 + 0x180));
    *(undefined8 *)(param_1 + 0x1a8) = uVar1;
    *(undefined2 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0xa0) = 0;
    __wake_up(param_1 + 0xa8,3,1,0);
    coresight_csr_set_byte_cntr(*(undefined8 *)(param_1 + 0x178),*(undefined4 *)(param_1 + 0x198),0)
    ;
    mutex_unlock(param_1 + 0x148);
  }
  return;
}



//------------------------------------------------------------
// byte_cntr_init @ 001063dc size=644
// signature: undefined byte_cntr_init(void)
// callers: [tmc_probe]
//------------------------------------------------------------

long byte_cntr_init(long *param_1,long param_2)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  iVar2 = of_irq_get_byname(param_1[0x5d],"byte-cntr-irq");
  if (-1 < iVar2) {
    lVar4 = devm_kmalloc(param_1,0x1c0,0xdc0);
    if (lVar4 == 0) goto LAB_00106628;
    lVar7 = param_1[0xe];
    if (lVar7 == 0) {
      lVar7 = *param_1;
    }
    iVar3 = devm_request_threaded_irq(param_1,iVar2,etr_handler,0,0x81,lVar7,lVar4);
    if (iVar3 == 0) {
      iVar3 = of_property_read_variable_u32_array
                        (param_1[0x5d],"csr-irqctrl-offset",(undefined4 *)(lVar4 + 0x198),1,0);
      if (iVar3 < 0) {
        *(undefined4 *)(lVar4 + 0x198) = 0x6c;
      }
      puVar1 = (undefined8 *)(lVar4 + 0x188);
      iVar3 = device_property_read_string(param_1,"byte-cntr-name",puVar1);
      if (iVar3 != 0) {
        *puVar1 = "byte-cntr";
      }
      iVar3 = device_property_read_string
                        (param_1,"byte-cntr-class-name",(undefined8 *)(lVar4 + 400));
      if (iVar3 != 0) {
        *(undefined8 *)(lVar4 + 400) = "coresight-tmc-etr-stream";
      }
      local_4c = 0;
      iVar3 = alloc_chrdev_region(&local_4c,0,1,*puVar1);
      if (iVar3 < 0) {
        _printk(&DAT_00108531,iVar3);
      }
      else {
        cdev_init(lVar4,&byte_cntr_fops);
        *(undefined1 **)(lVar4 + 0x60) = &__this_module;
        *(undefined ***)(lVar4 + 0x68) = &byte_cntr_fops;
        iVar3 = cdev_add(lVar4,local_4c,1);
        if (iVar3 == 0) {
          uVar5 = __class_create(&__this_module,*(undefined8 *)(lVar4 + 400),
                                 &byte_cntr_register_chardev___key);
          *(ulong *)(lVar4 + 0x88) = uVar5;
          if (uVar5 < 0xfffffffffffff001) {
            uVar5 = device_create(uVar5,0,*(undefined4 *)(lVar4 + 0x80),lVar4,
                                  *(undefined8 *)(lVar4 + 0x188));
            if (uVar5 < 0xfffffffffffff001) {
              uVar8 = *(undefined8 *)(param_2 + 0x128);
              *(int *)(lVar4 + 0x9c) = iVar2;
              *(undefined8 *)(lVar4 + 0x178) = uVar8;
              *(long *)(lVar4 + 0x180) = param_2;
              *(undefined4 *)(lVar4 + 0xa0) = 0;
              __init_waitqueue_head(lVar4 + 0xa8,"&byte_cntr_data->wq",&byte_cntr_init___key);
              __mutex_init(lVar4 + 0x148,"&byte_cntr_data->byte_cntr_lock",&byte_cntr_init___key_9);
              goto LAB_00106628;
            }
            _printk(&DAT_00107e93,0);
            class_destroy(*(undefined8 *)(lVar4 + 0x88));
          }
          else {
            _printk(&DAT_00107fd8,0xfffffff4);
          }
        }
        unregister_chrdev_region(*(undefined4 *)(lVar4 + 0x80),1);
      }
      pcVar6 = "Byte_cntr char dev registration failed\n";
    }
    else {
      pcVar6 = "Byte_cntr interrupt registration failed\n";
    }
    _dev_err(param_1,pcVar6);
  }
  lVar4 = 0;
LAB_00106628:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// etr_handler @ 00106664 size=164
// signature: undefined etr_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 etr_handler(undefined8 param_1,long param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  
  iVar2 = *(int *)(*(long *)(param_2 + 0x180) + 0x13c);
  if (iVar2 == 1) {
    piVar1 = (int *)(param_2 + 0xa0);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar5 = param_2 + 0xa8;
  }
  else {
    if (iVar2 != 2) goto LAB_001066cc;
    piVar1 = (int *)(param_2 + 0xa0);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar5 = param_2 + 0xc0;
  }
  __wake_up(lVar5,3,1,0);
LAB_001066cc:
  *(long *)(param_2 + 0x1b8) = *(long *)(param_2 + 0x1b8) + 1;
  return 1;
}



//------------------------------------------------------------
// byte_cntr_remove @ 0010672c size=68
// signature: undefined byte_cntr_remove(void)
// callers: [tmc_remove]
//------------------------------------------------------------

void byte_cntr_remove(long param_1)

{
  device_destroy(*(undefined8 *)(param_1 + 0x88),*(undefined4 *)(param_1 + 0x80));
  class_destroy(*(undefined8 *)(param_1 + 0x88));
  unregister_chrdev_region(*(undefined4 *)(param_1 + 0x80),1);
  return;
}



//------------------------------------------------------------
// tmc_etr_byte_cntr_read @ 00106774 size=972
// signature: undefined tmc_etr_byte_cntr_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong tmc_etr_byte_cntr_read(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  uint uVar8;
  undefined8 uVar9;
  code *pcVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  long local_58;
  
  lVar16 = sp_el0;
  local_58 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 0xd8);
  local_60 = 0;
  lVar17 = *(long *)(lVar16 + 0x180);
  if (param_2 == 0) {
    uVar12 = 0xffffffffffffffea;
    goto LAB_00106acc;
  }
  lVar1 = lVar16 + 0x148;
  mutex_lock(lVar1);
  if (*(char *)(lVar16 + 0x91) == '\0') {
LAB_001068cc:
    if ((lVar17 != 0) && (*(long *)(lVar17 + 0x120) != 0)) {
      uVar12 = *(ulong *)(lVar16 + 0x1a0);
      uVar15 = *(ulong *)(*(long *)(lVar17 + 0x120) + 0x1a8);
      if (uVar15 < uVar12) {
        uVar18 = (ulong)*(uint *)(lVar17 + 0x7c);
      }
      else {
        uVar18 = 0;
      }
      uVar18 = (uVar15 - uVar12) + uVar18;
      if (param_3 <= uVar18) {
        uVar18 = param_3;
      }
      if (0 < (long)uVar18) {
        uVar12 = tmc_etr_buf_get_data(*(undefined8 *)(lVar17 + 0x110),uVar12,uVar18,&local_60);
joined_r0x001069a4:
        uVar9 = local_60;
        if (0 < (long)uVar12) goto joined_r0x00106b34;
      }
    }
LAB_00106a98:
    uVar12 = 0xffffffffffffffea;
  }
  else {
    if (*(char *)(lVar16 + 0x90) == '\0') {
      if ((lVar17 != 0) && (*(long *)(lVar17 + 0x120) != 0)) {
        uVar12 = *(ulong *)(lVar16 + 0x1a0);
        uVar15 = *(ulong *)(*(long *)(lVar17 + 0x120) + 0x1a8);
        if (uVar15 < uVar12) {
          uVar18 = (ulong)*(uint *)(lVar17 + 0x7c);
        }
        else {
          uVar18 = 0;
        }
        uVar18 = (uVar15 - uVar12) + uVar18;
        if (param_3 <= uVar18) {
          uVar18 = param_3;
        }
        if (0 < (long)uVar18) {
          uVar12 = tmc_etr_buf_get_data(*(undefined8 *)(lVar17 + 0x110),uVar12,uVar18,&local_60);
          goto joined_r0x001069a4;
        }
      }
      goto LAB_00106a98;
    }
    if (*(int *)(lVar16 + 0xa0) == 0) {
      mutex_unlock(lVar1);
      if ((*(int *)(lVar16 + 0xa0) < 1) && (*(char *)(lVar16 + 0x90) != '\0')) {
        local_70 = 0;
        uStack_68 = 0;
        local_80 = 0;
        uStack_78 = 0;
        local_88 = 0;
        init_wait_entry(&local_88,0);
        lVar2 = lVar16 + 0xa8;
        lVar11 = prepare_to_wait_event(lVar2,&local_88,1);
        iVar4 = *(int *)(lVar16 + 0xa0);
        while ((iVar4 < 1 && (*(char *)(lVar16 + 0x90) != '\0'))) {
          if (lVar11 != 0) {
            if ((int)lVar11 == 0) goto LAB_0010683c;
            uVar12 = 0xfffffffffffffe00;
            goto LAB_00106acc;
          }
          schedule();
          lVar11 = prepare_to_wait_event(lVar2,&local_88,1);
          iVar4 = *(int *)(lVar16 + 0xa0);
        }
        finish_wait(lVar2,&local_88);
      }
LAB_0010683c:
      mutex_lock(lVar1);
      if (*(char *)(lVar16 + 0x91) == '\0') goto LAB_001068cc;
    }
    uVar5 = *(uint *)(lVar16 + 0x98);
    uVar18 = (ulong)uVar5;
    uVar15 = *(ulong *)(lVar16 + 0x1a0);
    uVar12 = uVar18;
    if (param_3 < uVar18) {
      uVar8 = 0;
      if (uVar5 != 0) {
        uVar8 = (uint)uVar15 / uVar5;
      }
      uVar13 = (ulong)((uint)uVar15 - uVar8 * uVar5);
      uVar12 = uVar18 - uVar13;
      if (uVar13 + param_3 <= uVar18) {
        uVar12 = param_3;
      }
    }
    uVar12 = tmc_etr_buf_get_data
                       (*(undefined8 *)(*(long *)(lVar16 + 0x180) + 0x110),uVar15,uVar12,&local_60);
    uVar9 = local_60;
    if (uVar12 == uVar18) {
LAB_00106b14:
      piVar3 = (int *)(lVar16 + 0xa0);
      Hint_Prefetch(piVar3,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(piVar3,0x10);
        if (bVar7) {
          *piVar3 = *piVar3 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
    }
    else {
      uVar15 = uVar12 + (uVar15 & 0xffffffff);
      uVar13 = 0;
      if (uVar18 != 0) {
        uVar13 = uVar15 / uVar18;
      }
      if (uVar15 == uVar13 * uVar18) goto LAB_00106b14;
    }
joined_r0x00106b34:
    local_60 = uVar9;
    if (uVar12 >> 0x1f != 0) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x800,0x106b40);
      (*pcVar10)();
    }
    __check_object_size(uVar9,uVar12,1);
    puVar14 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
       (uVar15 = param_2, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
      uVar15 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar18 = uVar12;
    if (uVar15 <= 0x8000000000 - uVar12) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar18 = daif;
          daif = uVar18 | 0xc0;
        }
        puVar14 = (undefined8 *)puVar14[1];
        uVar18 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar18 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar14;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      uVar18 = __arch_copy_to_user(puVar14,param_2 & 0xff7fffffffffffff,uVar9,uVar12);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
    }
    if (uVar18 == 0) {
      *(ulong *)(lVar16 + 0x1b0) = *(long *)(lVar16 + 0x1b0) + uVar12;
      uVar15 = *(long *)(lVar16 + 0x1a0) + uVar12;
      if (*(uint *)(lVar17 + 0x7c) <= uVar15) {
        uVar15 = 0;
      }
      *(ulong *)(lVar16 + 0x1a0) = uVar15;
    }
    else {
      uVar12 = 0xfffffffffffffff2;
    }
  }
  mutex_unlock(lVar1);
LAB_00106acc:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// tmc_etr_byte_cntr_open @ 00106b78 size=212
// signature: undefined tmc_etr_byte_cntr_open(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_etr_byte_cntr_open(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x290);
  lVar2 = *(long *)(lVar4 + 0x180);
  mutex_lock(lVar4 + 0x148);
  if (*(char *)(lVar4 + 0x91) == '\0') {
    if ((*(int *)(lVar2 + 0x84) == 1) && (*(int *)(lVar4 + 0x98) != 0)) {
      irq_set_irq_wake(*(undefined4 *)(lVar4 + 0x9c),1);
      coresight_csr_set_byte_cntr
                (*(undefined8 *)(lVar4 + 0x178),*(undefined4 *)(lVar4 + 0x198),
                 *(uint *)(lVar4 + 0x98) >> 3);
      *(long *)(param_2 + 0xd8) = lVar4;
      nonseekable_open(param_1,param_2);
      *(undefined8 *)(lVar4 + 0x1b0) = 0;
      *(undefined2 *)(lVar4 + 0x90) = 0x101;
      uVar1 = tmc_get_rwp_offset(lVar2);
      uVar3 = 0;
      *(undefined8 *)(lVar4 + 0x1b8) = 0;
      *(undefined8 *)(lVar4 + 0x1a0) = uVar1;
    }
    else {
      uVar3 = 0xffffffea;
    }
  }
  else {
    uVar3 = 0xfffffff0;
  }
  mutex_unlock(lVar4 + 0x148);
  return uVar3;
}



//------------------------------------------------------------
// tmc_etr_byte_cntr_release @ 00106c50 size=104
// signature: undefined tmc_etr_byte_cntr_release(void)
// callers: []
//------------------------------------------------------------

undefined8 tmc_etr_byte_cntr_release(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0xd8);
  mutex_lock(lVar1 + 0x148);
  *(undefined1 *)(lVar1 + 0x91) = 0;
  *(undefined4 *)(lVar1 + 0xa0) = 0;
  if (*(char *)(lVar1 + 0x90) != '\0') {
    coresight_csr_set_byte_cntr(*(undefined8 *)(lVar1 + 0x178),*(undefined4 *)(lVar1 + 0x198),0);
  }
  irq_set_irq_wake(*(undefined4 *)(lVar1 + 0x9c),0);
  mutex_unlock(lVar1 + 0x148);
  return 0;
}



//------------------------------------------------------------
// usb_notifier @ 00106ce4 size=924
// signature: undefined usb_notifier(void)
// callers: []
//------------------------------------------------------------

void usb_notifier(long param_1,int param_2,long param_3,undefined8 param_4)

{
  int *piVar1;
  char cVar2;
  ulong uVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined1 *puVar7;
  char *pcVar8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  uint uVar13;
  long local_58;
  long lStack_50;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  if (param_1 == 0) goto LAB_00106fd4;
  if (*(int *)(param_1 + 0x13c) == 2) {
    if (param_2 == 3) {
      if (**(int **)(param_1 + 0x140) == 1) {
        lVar10 = *(long *)(param_1 + 0x120);
        local_58 = 0;
        lStack_50 = 0;
        lVar12 = *(long *)(*(long *)(lVar10 + 0x180) + 0x140);
        *(long *)(lVar12 + 0x28) = *(long *)(lVar12 + 0x28) + (long)*(int *)(param_3 + 8);
        piVar1 = (int *)(lVar10 + 0xa4);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = *piVar1 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        iVar5 = *(int *)(param_3 + 0x10);
        if ((((iVar5 != -0x6c) && (iVar5 != -0x68)) && (iVar5 != 0)) &&
           (iVar5 = ___ratelimit(usb_write_done__rs,"usb_write_done"), iVar5 != 0)) {
          _printk(&DAT_00108611,*(undefined4 *)(param_3 + 0x10));
        }
        kfree(*(undefined8 *)(param_3 + 0x20));
        kfree(param_3);
        __wake_up(lVar10 + 0xc0,3,1,0);
        ktime_get_real_ts64(&local_58);
        lVar12 = *(long *)(*(long *)(lVar10 + 0x180) + 0x140);
        uVar9 = (lStack_50 - *(long *)(lVar12 + 0x48)) / 1000000 +
                (local_58 - *(long *)(lVar12 + 0x40)) * 1000;
        if (uVar9 != 0) {
          uVar3 = 0;
          if (uVar9 != 0) {
            uVar3 = (ulong)(*(long *)(lVar12 + 0x28) * 1000) / uVar9;
          }
          *(ulong *)(lVar12 + 0x38) = uVar3 >> 0x14;
        }
      }
      goto LAB_00106fd4;
    }
    if (param_2 == 1) {
      if (*(int *)(param_1 + 0x84) != 0) {
        if (**(int **)(param_1 + 0x140) == 1) {
          usb_bypass_stop(*(undefined8 *)(param_1 + 0x120));
          flush_work(*(long *)(param_1 + 0x120) + 0xe8);
          usb_qdss_free_req(*(undefined8 *)(*(long *)(param_1 + 0x140) + 8));
        }
        goto LAB_00106fd4;
      }
      puVar7 = usb_notifier__rs_2;
    }
    else {
      if (param_2 != 0) goto LAB_00106fd4;
      if (*(int *)(param_1 + 0x84) != 0) {
        if ((**(int **)(param_1 + 0x140) == 1) && (lVar12 = *(long *)(param_1 + 0x120), lVar12 != 0)
           ) {
          lVar10 = lVar12 + 0x118;
          lVar11 = *(long *)(lVar12 + 0x180);
          mutex_lock(lVar10);
          _dev_info(*(long *)(lVar11 + 8) + 0x38,"%s: Start usb bypass\n","usb_bypass_start");
          if (*(int *)(lVar11 + 0x84) == 1) {
            lVar6 = tmc_get_rwp_offset(lVar11);
            if (lVar6 < 0) {
              _dev_err(*(long *)(lVar11 + 8) + 0x38,"%s: invalid rwp offset value\n",
                       "usb_bypass_start");
              mutex_unlock(lVar10);
              if ((int)lVar6 < 0) goto LAB_00106fd4;
            }
            else {
              *(long *)(lVar12 + 0x1a0) = lVar6;
              *(undefined8 *)(lVar12 + 0x1b8) = 0;
              *(undefined8 *)(*(long *)(lVar11 + 0x140) + 0x20) = 0;
              *(undefined1 *)(*(long *)(lVar11 + 0x140) + 0x18) = 0;
              *(undefined8 *)(*(long *)(lVar11 + 0x140) + 0x28) = 0;
              *(undefined8 *)(*(long *)(lVar11 + 0x140) + 0x30) = 0;
              *(undefined8 *)(*(long *)(lVar11 + 0x140) + 0x38) = 0;
              if (*(long *)(*(long *)(lVar11 + 0x140) + 8) == 0) {
                uVar13 = 0xffffff9c;
                do {
                  bVar4 = 0xfffffffe < uVar13;
                  uVar13 = uVar13 + 1;
                  if (bVar4) {
                    _dev_err(*(long *)(lVar11 + 8) + 0x38,
                             "timeout while waiting usbch to be ready\n");
                    goto LAB_00107060;
                  }
                  __const_udelay(0x10c7);
                } while (*(long *)(*(long *)(lVar11 + 0x140) + 8) == 0);
              }
              *(undefined4 *)(lVar12 + 0xa4) = 0xff;
              *(undefined1 *)(lVar12 + 0x91) = 1;
              coresight_csr_set_byte_cntr
                        (*(undefined8 *)(lVar12 + 0x178),*(undefined4 *)(lVar12 + 0x198),0x2000);
              *(undefined4 *)(lVar12 + 0xa0) = 0;
              *(undefined8 *)(lVar12 + 0x1b0) = 0;
              mutex_unlock(lVar10);
            }
            usb_qdss_alloc_req(param_4,0xff);
            queue_work_on(0x20,*(undefined8 *)(*(long *)(param_1 + 0x120) + 0xd8),
                          *(long *)(param_1 + 0x120) + 0xe8);
          }
          else {
LAB_00107060:
            mutex_unlock(lVar10);
          }
        }
        goto LAB_00106fd4;
      }
      puVar7 = &usb_notifier__rs;
    }
    iVar5 = ___ratelimit(puVar7,"usb_notifier");
    if (iVar5 == 0) goto LAB_00106fd4;
    lVar12 = *(long *)(param_1 + 8);
    pcVar8 = "%s: ETR is disabled.\n";
  }
  else {
    lVar12 = *(long *)(param_1 + 8);
    pcVar8 = "%s: ETR is not USB mode.\n";
  }
  _dev_err(lVar12 + 0x38,pcVar8,"usb_notifier");
LAB_00106fd4:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// usb_bypass_stop @ 0010708c size=240
// signature: undefined usb_bypass_stop(void)
// callers: [tmc_usb_disable, usb_notifier]
//------------------------------------------------------------

void usb_bypass_stop(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_1 != 0) {
    mutex_lock(param_1 + 0x118);
    if (*(char *)(param_1 + 0x91) != '\0') {
      *(undefined1 *)(param_1 + 0x91) = 0;
      __wake_up(param_1 + 0xc0,3,1,0);
      _printk(&DAT_001080a9);
      uVar3 = tmc_get_rwp_offset(*(undefined8 *)(param_1 + 0x180));
      *(undefined8 *)(param_1 + 0x1a8) = uVar3;
      coresight_csr_set_byte_cntr
                (*(undefined8 *)(param_1 + 0x178),*(undefined4 *)(param_1 + 0x198),0);
      _dev_info(*(long *)(*(long *)(param_1 + 0x180) + 8) + 0x38,
                "USB total size: %lld, total irq: %lld,current irq:%d, offset: %ld, rwp_offset: %ld, drop_data: %lld\n"
                ,*(undefined8 *)(param_1 + 0x1b0),*(undefined8 *)(param_1 + 0x1b8),
                *(undefined4 *)(param_1 + 0xa0),*(undefined8 *)(param_1 + 0x1a0),
                *(undefined8 *)(param_1 + 0x1a8),
                *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x180) + 0x140) + 0x20));
      lVar4 = *(long *)(*(long *)(param_1 + 0x180) + 0x140);
      uVar1 = *(long *)(param_1 + 0x1b0) + *(long *)(lVar4 + 0x20);
      uVar2 = 0;
      if (uVar1 != 0) {
        uVar2 = (ulong)(*(long *)(lVar4 + 0x20) * 100) / uVar1;
      }
      _dev_info(*(long *)(*(long *)(param_1 + 0x180) + 8) + 0x38,
                "Data input speed: %lldMB/s, Data output speed: %lldMB/s, drop_rate: %d%%\n",
                *(undefined8 *)(lVar4 + 0x30),*(undefined8 *)(lVar4 + 0x38),uVar2);
    }
    mutex_unlock(param_1 + 0x118);
  }
  return;
}



//------------------------------------------------------------
// tmc_usb_enable @ 00107180 size=144
// signature: undefined tmc_usb_enable(void)
// callers: [tmc_enable_etr_sink_sysfs]
//------------------------------------------------------------

undefined8 tmc_usb_enable(int *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (param_1 == (int *)0x0) {
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = *(long *)(param_1 + 4);
    if (*param_1 == 1) {
      uVar1 = usb_qdss_open("qdss_sw",lVar3,usb_notifier);
      *(ulong *)(param_1 + 2) = uVar1;
    }
    else {
      uVar1 = *(ulong *)(param_1 + 2);
    }
    if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
      _dev_err(*(long *)(lVar3 + 8) + 0x38,"usb_qdss_open failed for qdss.\n");
      uVar2 = 0xffffffed;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// tmc_usb_disable @ 00107214 size=108
// signature: undefined tmc_usb_disable(void)
// callers: [_tmc_disable_etr_sink]
//------------------------------------------------------------

void tmc_usb_disable(int *param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 4);
  if (*param_1 == 1) {
    usb_bypass_stop(*(undefined8 *)(lVar1 + 0x120));
    flush_work(*(long *)(lVar1 + 0x120) + 0xe8);
  }
  if (*(long *)(param_1 + 2) == 0) {
    _dev_err(*(long *)(lVar1 + 8) + 0x38,"usb channel is null.\n");
  }
  else {
    usb_qdss_close();
  }
  return;
}



//------------------------------------------------------------
// tmc_etr_usb_init @ 00107284 size=308
// signature: undefined tmc_etr_usb_init(void)
// callers: [tmc_probe]
//------------------------------------------------------------

undefined8 tmc_etr_usb_init(long *param_1,long param_2)

{
  undefined4 *puVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  
  puVar1 = (undefined4 *)devm_kmalloc(param_1,0x50,0xdc0);
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    *(undefined4 **)(param_2 + 0x140) = puVar1;
    lVar2 = param_1[0x5e];
    lVar5 = *(long *)(param_2 + 0x120);
    *(long *)(puVar1 + 4) = param_2;
    uVar3 = fwnode_property_present(lVar2,"qcom,sw-usb");
    if ((uVar3 & 1) == 0) {
      lVar2 = param_1[0xe];
      *puVar1 = 0;
      if (lVar2 == 0) {
        lVar2 = *param_1;
      }
      _printk(&DAT_0010825a,lVar2);
      uVar4 = 0;
    }
    else {
      *(undefined8 *)(puVar1 + 8) = 0;
      *(undefined1 *)(puVar1 + 6) = 0;
      *puVar1 = 1;
      if (lVar5 != 0) {
        lVar2 = alloc_workqueue(&DAT_00107f70,0xe000a,1,"byte-cntr");
        *(long *)(lVar5 + 0xd8) = lVar2;
        if (lVar2 != 0) {
          *(undefined8 *)(lVar5 + 0x1a0) = 0;
          __mutex_init(lVar5 + 0x118,"&byte_cntr_data->usb_bypass_lock",&usb_bypass_init___key);
          __init_waitqueue_head
                    (lVar5 + 0xc0,"&byte_cntr_data->usb_wait_wq",&usb_bypass_init___key_18);
          *(undefined4 *)(lVar5 + 0xa4) = 0xff;
          *(undefined8 *)(lVar5 + 0xe8) = 0xfffffffe0;
          *(long *)(lVar5 + 0xf0) = lVar5 + 0xf0;
          *(long *)(lVar5 + 0xf8) = lVar5 + 0xf0;
          *(code **)(lVar5 + 0x100) = usb_read_work_fn;
          return 0;
        }
      }
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// usb_read_work_fn @ 001073bc size=2436
// signature: undefined usb_read_work_fn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void usb_read_work_fn(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  char *pcVar10;
  long lVar11;
  long lVar12;
  int *piVar13;
  ulong uVar14;
  long lVar15;
  undefined8 uVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  long lVar20;
  int local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  long local_80;
  long local_78;
  long local_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  lVar17 = *(long *)(param_1 + 0x98);
  local_78 = 0;
  local_70 = 0;
  local_80 = 0;
  uVar16 = *(undefined8 *)(lVar17 + 0x110);
  ktime_get_real_ts64(*(long *)(lVar17 + 0x140) + 0x40);
  if (*(int *)(lVar17 + 0x84) != 1) {
LAB_00107d50:
    lVar17 = *(long *)(lVar17 + 8);
    pcVar10 = "TMC has been stopped.\n";
LAB_00107d5c:
    _dev_err(lVar17 + 0x38,pcVar10);
LAB_00107c90:
    lVar17 = sp_el0;
    if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  lVar20 = 0;
  lVar18 = param_1 + -0x28;
  local_ac = 0;
LAB_00107460:
  if (*(int *)(lVar17 + 0x13c) != 2) goto LAB_00107d50;
  if (*(int *)(param_1 + -0x48) == 0) {
    if ((*(int *)(param_1 + -0x48) < 1) && (*(char *)(param_1 + -0x57) != '\0')) {
      local_90 = 0;
      uStack_88 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_a8 = 0;
      init_wait_entry(&local_a8,0);
      lVar11 = prepare_to_wait_event(lVar18,&local_a8,1);
      if (*(int *)(param_1 + -0x48) < 1) {
        lVar8 = 0x4e2;
        do {
          if ((*(int *)(lVar17 + 0x84) != 1) || (*(int *)(lVar17 + 0x13c) != 2)) break;
          if (lVar8 == 0 && *(char *)(param_1 + -0x57) == '\0') {
            lVar8 = 1;
          }
          if ((*(char *)(param_1 + -0x57) == '\0') || (lVar8 == 0)) goto LAB_0010753c;
          if (lVar11 != 0) goto LAB_0010754c;
          lVar8 = schedule_timeout(lVar8);
          lVar11 = prepare_to_wait_event(lVar18,&local_a8,1);
        } while (*(int *)(param_1 + -0x48) < 1);
        if (lVar8 == 0) {
          lVar8 = 1;
        }
      }
      else {
        lVar8 = 0x4e2;
      }
LAB_0010753c:
      lVar11 = lVar8;
      finish_wait(lVar18,&local_a8);
LAB_0010754c:
      if ((int)lVar11 == -0x200) {
        lVar11 = 0xfffffe00;
      }
      else if (*(int *)(lVar17 + 0x84) == 1) goto LAB_00107560;
    }
    else {
      lVar11 = 0x4e2;
LAB_00107560:
      if ((*(int *)(lVar17 + 0x13c) == 2) && (*(char *)(param_1 + -0x57) != '\0')) {
        if ((int)lVar11 != 0) goto LAB_00107578;
        lVar8 = *(long *)(param_1 + 0x98);
        lVar11 = *(long *)(lVar8 + 0x110);
        uVar14 = tmc_get_rwp_offset(lVar8);
        if ((long)uVar14 < 0) {
          iVar4 = ___ratelimit(usb_transfer_small_packet__rs,"usb_transfer_small_packet");
          if (iVar4 != 0) {
            _dev_err(*(long *)(lVar8 + 8) + 0x38,"%s: RWP offset is invalid\n",
                     "usb_transfer_small_packet");
          }
LAB_0010799c:
          if (((int)uVar14 == -0xb) || ((int)uVar14 == 0)) goto LAB_00107454;
          goto LAB_00107c90;
        }
        lVar12 = *(long *)(lVar8 + 0x140);
        if (*(int *)(param_1 + -0x48) < 0x401) {
          if (*(char *)(lVar12 + 0x18) != '\0') {
            *(undefined1 *)(lVar12 + 0x18) = 0;
          }
        }
        else {
          *(undefined1 *)(lVar12 + 0x18) = 1;
          iVar4 = ___ratelimit(usb_transfer_small_packet__rs_33,"usb_transfer_small_packet");
          if (iVar4 != 0) {
            _dev_err(*(long *)(lVar8 + 8) + 0x38,"ETR data is overwritten.\n");
          }
        }
        if (uVar14 < *(ulong *)(param_1 + 0xb8)) {
          lVar12 = *(long *)(lVar11 + 0x10);
        }
        else {
          lVar12 = 0;
        }
        uVar14 = lVar12 + (uVar14 - *(ulong *)(param_1 + 0xb8));
        if ((uVar14 + lVar20 < 0x10000) || (*(int *)(param_1 + -0x48) != 0)) {
          while (uVar14 != 0) {
            lVar12 = kmalloc_trace(_arm64_use_ng_mappings,0xdc0,0x30);
            if (lVar12 == 0) goto LAB_00107c90;
            uVar9 = tmc_etr_buf_get_data(lVar11,*(undefined8 *)(param_1 + 0xb8),uVar14,lVar12);
            if ((long)uVar9 < 1 || uVar14 < uVar9) {
              kfree(lVar12);
              iVar4 = ___ratelimit(usb_transfer_small_packet__rs_35,"usb_transfer_small_packet");
              if (iVar4 != 0) {
                _dev_err(*(long *)(lVar8 + 8) + 0x38,"%s: Invalid data in ETR\n",
                         "usb_transfer_small_packet");
              }
              goto LAB_00107c90;
            }
            *(long *)(param_1 + -8) = lVar12;
            lVar15 = *(long *)(param_1 + 0xb8);
            uVar14 = uVar14 - uVar9;
            lVar20 = uVar9 + lVar20;
            *(int *)(lVar12 + 8) = (int)uVar9;
            uVar19 = lVar15 + uVar9;
            if (*(ulong *)(*(long *)(lVar8 + 0x110) + 0x10) <= uVar19) {
              uVar19 = 0;
            }
            *(ulong *)(param_1 + 0xb8) = uVar19;
            if (*(int *)(param_1 + -0x44) < 1) {
              iVar4 = ___ratelimit(usb_transfer_small_packet__rs_38,"usb_transfer_small_packet");
              if (iVar4 != 0) {
                _dev_err(*(long *)(lVar8 + 8) + 0x38,"Drop data, offset = %d, len = %d\n",
                         *(undefined8 *)(param_1 + 0xb8),uVar14);
              }
              *(ulong *)(*(long *)(lVar8 + 0x140) + 0x20) =
                   *(long *)(*(long *)(lVar8 + 0x140) + 0x20) + uVar9;
              kfree(lVar12);
              *(undefined8 *)(param_1 + -8) = 0;
            }
            else {
              uVar6 = usb_qdss_write(*(undefined8 *)(*(long *)(lVar8 + 0x140) + 8),lVar12);
              if (uVar6 != 0) {
                uVar14 = (ulong)uVar6;
                kfree(lVar12);
                *(undefined8 *)(param_1 + -8) = 0;
                iVar4 = ___ratelimit(usb_transfer_small_packet__rs_37,"usb_transfer_small_packet");
                if (iVar4 != 0) {
                  _dev_err(*(long *)(lVar8 + 8) + 0x38,"Write data failed:%d\n",uVar14);
                }
                goto LAB_0010799c;
              }
              *(ulong *)(param_1 + 200) = *(long *)(param_1 + 200) + uVar9;
              piVar13 = (int *)(param_1 + -0x44);
              Hint_Prefetch(piVar13,2,0,1);
              do {
                cVar2 = '\x01';
                bVar3 = (bool)ExclusiveMonitorPass(piVar13,0x10);
                if (bVar3) {
                  *piVar13 = *piVar13 + -1;
                  cVar2 = ExclusiveMonitorsStatus();
                }
              } while (cVar2 != '\0');
            }
          }
        }
        else {
          *(int *)(param_1 + -0x48) = (int)(uVar14 + lVar20 >> 0x10);
        }
        goto LAB_00107454;
      }
    }
    lVar20 = *(long *)(lVar17 + 8);
    pcVar10 = "usb wait for irq_cnt exit, ret=%d\n";
LAB_00107d48:
    _dev_err(lVar20 + 0x38,pcVar10,lVar11);
    goto LAB_00107d50;
  }
LAB_00107578:
  if (*(int *)(param_1 + -0x48) < 0x401) {
    *(undefined1 *)(*(long *)(lVar17 + 0x140) + 0x18) = 0;
    if (*(int *)(param_1 + -0x44) < 1) {
      if ((*(int *)(lVar17 + 0x84) == 1) && (*(int *)(lVar17 + 0x13c) == 2)) {
        if (*(char *)(param_1 + -0x57) == '\0') goto LAB_00107598;
        local_90 = 0;
        uStack_88 = 0;
        local_a0 = 0;
        uStack_98 = 0;
        local_a8 = 0;
        init_wait_entry(&local_a8,0);
        lVar11 = prepare_to_wait_event(lVar18,&local_a8,1);
        if (*(int *)(param_1 + -0x44) < 1) {
          lVar8 = 0x7d;
          do {
            if ((*(int *)(lVar17 + 0x84) != 1) || (*(int *)(lVar17 + 0x13c) != 2)) break;
            if (lVar8 == 0 && *(char *)(param_1 + -0x57) == '\0') {
              lVar8 = 1;
            }
            if ((*(char *)(param_1 + -0x57) == '\0') || (lVar8 == 0)) goto LAB_001078f0;
            if (lVar11 != 0) goto LAB_00107900;
            lVar8 = schedule_timeout(lVar8);
            lVar11 = prepare_to_wait_event(lVar18,&local_a8,1);
          } while (*(int *)(param_1 + -0x44) < 1);
          if (lVar8 == 0) {
            lVar8 = 1;
          }
        }
        else {
          lVar8 = 0x7d;
        }
LAB_001078f0:
        lVar11 = lVar8;
        finish_wait(lVar18,&local_a8);
LAB_00107900:
        if ((int)lVar11 == 0) {
          iVar4 = ___ratelimit(usb_read_work_fn__rs_22,"usb_read_work_fn");
          if (iVar4 != 0) {
            _dev_err(*(long *)(lVar17 + 8) + 0x38,"wait for usb free_buf\n");
          }
          goto LAB_00107454;
        }
        if ((int)lVar11 == -0x200) goto LAB_00107d28;
        goto LAB_0010759c;
      }
      lVar11 = 0x7d;
    }
    else {
LAB_00107598:
      lVar11 = 0x7d;
LAB_0010759c:
      if (((*(int *)(lVar17 + 0x84) == 1) && (*(int *)(lVar17 + 0x13c) == 2)) &&
         (*(char *)(param_1 + -0x57) != '\0')) goto LAB_001075bc;
    }
LAB_00107d28:
    lVar20 = *(long *)(lVar17 + 8);
    pcVar10 = "usb wait for usb free_buf exit, ret=%d\n";
    goto LAB_00107d48;
  }
  *(undefined1 *)(*(long *)(lVar17 + 0x140) + 0x18) = 1;
  iVar4 = ___ratelimit(usb_read_work_fn__rs,"usb_read_work_fn");
  if (iVar4 != 0) {
    _dev_err(*(long *)(lVar17 + 8) + 0x38,"ETR data is overwritten. irq_cnt=%d\n",
             *(undefined4 *)(param_1 + -0x48));
  }
LAB_001075bc:
  if (lVar20 == 0x10000) goto LAB_001075c4;
  plVar7 = (long *)kmalloc_trace(_arm64_use_ng_mappings,0xdc0,0x30);
  if (plVar7 == (long *)0x0) goto LAB_00107c90;
  uVar14 = 0xffffU - lVar20 >> 0xc;
  lVar11 = uVar14 * 0x20;
  lVar20 = __kmalloc(lVar11 + 0x20,0xdc0);
  plVar7[4] = lVar20;
  if (lVar20 == 0) {
    kfree(plVar7);
    goto LAB_00107c90;
  }
  uVar19 = 0;
  lVar20 = 0;
  uVar9 = *(ulong *)(param_1 + 0xb8);
  local_ac = local_ac + 1;
  do {
    lVar8 = tmc_etr_buf_get_data(uVar16,uVar9,0x1000,&local_70);
    if (lVar8 - 0x1001U < 0xfffffffffffff000) {
      kfree(plVar7[4]);
      kfree(plVar7);
      iVar4 = ___ratelimit(usb_read_work_fn__rs_25,"usb_read_work_fn");
      if (iVar4 == 0) goto LAB_00107c90;
      lVar17 = *(long *)(lVar17 + 8);
      pcVar10 = "Invalid data in ETR\n";
      goto LAB_00107d5c;
    }
    puVar1 = (ulong *)(plVar7[4] + uVar19 * 0x20);
    *(uint *)(puVar1 + 1) = (uint)local_70 & 0xfff;
    *(int *)((long)puVar1 + 0xc) = (int)lVar8;
    *puVar1 = (*puVar1 & 3 | (((local_70 << 8) >> 8) + 0x8000000000U >> 0xc) << 6) - 0x200000000;
    if ((int)uVar19 == 0) {
      *plVar7 = local_70;
    }
    if (uVar14 == uVar19) {
      *(ulong *)(plVar7[4] + lVar11) = *(ulong *)(plVar7[4] + lVar11) & 0xfffffffffffffffc | 2;
    }
    lVar20 = lVar8 + lVar20;
    uVar9 = *(long *)(param_1 + 0xb8) + lVar8;
    iVar4 = (int)uVar19 + 1;
    if (*(ulong *)(*(long *)(lVar17 + 0x110) + 0x10) <= uVar9) {
      uVar9 = 0;
    }
    uVar19 = (ulong)iVar4;
    *(ulong *)(param_1 + 0xb8) = uVar9;
  } while (uVar19 <= uVar14);
  *(int *)(plVar7 + 1) = (int)lVar20;
  *(long **)(param_1 + -8) = plVar7;
  *(int *)(plVar7 + 5) = iVar4;
  if (*(int *)(param_1 + -0x44) < 1) {
    iVar4 = ___ratelimit(usb_read_work_fn__rs_29,"usb_read_work_fn");
    if (iVar4 != 0) {
      _dev_err(*(long *)(lVar17 + 8) + 0x38,"Drop data, offset = %d, seq = %d, irq = %d\n",
               *(undefined8 *)(param_1 + 0xb8),local_ac,*(undefined4 *)(param_1 + -0x48));
    }
    *(long *)(*(long *)(lVar17 + 0x140) + 0x20) =
         *(long *)(*(long *)(lVar17 + 0x140) + 0x20) + lVar20;
    kfree(plVar7[4]);
    kfree(plVar7);
    *(undefined8 *)(param_1 + -8) = 0;
LAB_001075c4:
    if (0 < *(int *)(param_1 + -0x48)) {
      piVar13 = (int *)(param_1 + -0x48);
      Hint_Prefetch(piVar13,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar13,0x10);
        if (bVar3) {
          *piVar13 = *piVar13 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    ktime_get_real_ts64(&local_80);
    lVar11 = *(long *)(lVar17 + 0x140);
    uVar14 = (local_78 - *(long *)(lVar11 + 0x48)) / 1000000 +
             (local_80 - *(long *)(lVar11 + 0x40)) * 1000;
    if (uVar14 != 0) {
      lVar20 = 0;
      uVar9 = 0;
      if (uVar14 != 0) {
        uVar9 = (ulong)((*(long *)(lVar11 + 0x20) + *(long *)(param_1 + 200)) * 1000) / uVar14;
      }
      *(ulong *)(lVar11 + 0x30) = uVar9 >> 0x14;
      goto LAB_00107454;
    }
  }
  else {
    iVar4 = usb_qdss_write(*(undefined8 *)(*(long *)(lVar17 + 0x140) + 8),plVar7);
    if (iVar4 == 0) {
      *(long *)(param_1 + 200) = *(long *)(param_1 + 200) + lVar20;
      piVar13 = (int *)(param_1 + -0x44);
      Hint_Prefetch(piVar13,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar13,0x10);
        if (bVar3) {
          *piVar13 = *piVar13 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      goto LAB_001075c4;
    }
    kfree(plVar7[4]);
    kfree(plVar7);
    *(undefined8 *)(param_1 + -8) = 0;
    iVar5 = ___ratelimit(usb_read_work_fn__rs_27,"usb_read_work_fn");
    if (iVar5 != 0) {
      _dev_err(*(long *)(lVar17 + 8) + 0x38,"Write data failed:%d\n",iVar4);
    }
    if (iVar4 != -0xb) goto LAB_00107c90;
  }
  lVar20 = 0;
LAB_00107454:
  if (*(int *)(lVar17 + 0x84) != 1) goto LAB_00107d50;
  goto LAB_00107460;
}



//------------------------------------------------------------
// init_module @ 00107d70 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  amba_driver_register(&tmc_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00107d98 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  amba_driver_unregister(&tmc_driver);
  return;
}



//------------------------------------------------------------
// coresight_timeout @ 0010c000 size=1
// signature: undefined coresight_timeout(void)
// callers: [tmc_flush_and_stop, tmc_wait_for_tmcready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010c008 size=1
// signature: undefined _dev_err(void)
// callers: [tmc_usb_disable, tmc_enable_etr_sink_sysfs, tmc_enable_etf_link, byte_cntr_init, tmc_usb_enable, tmc_probe, usb_notifier, tmc_flush_and_stop, _tmc_disable_etr_sink, tmc_wait_for_tmcready, tmc_etr_switch_mode, __tmc_etr_enable_hw, __tmc_etb_enable_hw, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010c010 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010c018 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010c020 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010c028 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_register @ 0010c030 size=1
// signature: undefined amba_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_unregister @ 0010c038 size=1
// signature: undefined amba_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010c040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [tmc_probe, tmc_etr_usb_init, byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0010c048 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010c050 size=1
// signature: undefined __mutex_init(void)
// callers: [tmc_probe, tmc_etr_usb_init, byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_u32_array @ 0010c058 size=1
// signature: undefined fwnode_property_read_u32_array(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_coresight_csr_name @ 0010c060 size=1
// signature: undefined of_get_coresight_csr_name(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_coresight_csr_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_csr_get @ 0010c068 size=1
// signature: undefined coresight_csr_get(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_csr_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 0010c070 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 0010c078 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 0010c080 size=1
// signature: undefined coresight_register(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_present @ 0010c088 size=1
// signature: undefined fwnode_property_present(void)
// callers: [tmc_probe, tmc_etr_usb_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010c090 size=1
// signature: undefined _dev_info(void)
// callers: [tmc_probe, usb_notifier, usb_bypass_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0010c098 size=1
// signature: undefined dma_set_mask(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0010c0a0 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010c0a8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [tmc_probe, byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 0010c0b0 size=1
// signature: undefined misc_register(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 0010c0b8 size=1
// signature: undefined coresight_unregister(void)
// callers: [tmc_probe, tmc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010c0c0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [tmc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010c0c8 size=1
// signature: undefined _printk(void)
// callers: [tmc_probe, tmc_etr_usb_init, usb_notifier, byte_cntr_init, usb_bypass_stop, block_size_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010c0d0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [stop_on_flush_store, byte_cntr_init, __tmc_etr_disable_hw, tmc_read, tmc_probe, tmc_etr_byte_cntr_read, usb_notifier, buffer_size_store, out_mode_store, trigger_cntr_store, block_size_store, tmc_update_etr_buffer, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 0010c0d8 size=1
// signature: undefined misc_deregister(void)
// callers: [tmc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010c0e0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [tmc_shutdown, tmc_disable_etf_sink, tmc_update_etf_buffer, tmc_enable_etr_sink_sysfs, tmc_enable_etr_sink, tmc_disable_etr_sink, tmc_read_prepare_etb, tmc_read_unprepare_etb, tmc_enable_etf_link, tmc_enable_etf_sink, tmc_read_prepare_etr, _tmc_disable_etr_sink, tmc_update_etr_buffer, tmc_read_unprepare_etr, tmc_disable_etf_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010c0e8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [tmc_shutdown, tmc_disable_etf_sink, tmc_update_etf_buffer, tmc_enable_etr_sink_sysfs, tmc_enable_etr_sink, tmc_disable_etr_sink, tmc_read_prepare_etb, tmc_read_unprepare_etb, tmc_enable_etf_link, tmc_enable_etf_sink, tmc_read_prepare_etr, _tmc_disable_etr_sink, tmc_update_etr_buffer, tmc_read_unprepare_etr, tmc_disable_etf_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010c0f0 size=1
// signature: undefined scnprintf(void)
// callers: [trigger_cntr_show, stop_on_flush_show, block_size_show, buffer_size_show, out_mode_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0010c0f8 size=1
// signature: undefined kstrtoull(void)
// callers: [stop_on_flush_store, buffer_size_store, trigger_cntr_store, block_size_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010c100 size=1
// signature: undefined mutex_lock(void)
// callers: [tmc_read, tmc_etr_byte_cntr_read, tmc_etr_switch_mode, tmc_enable_etr_sink, tmc_disable_etr_sink, tmc_etr_byte_cntr_start, tmc_etr_byte_cntr_open, usb_notifier, tmc_read_prepare_etr, tmc_etr_byte_cntr_stop, tmc_etr_byte_cntr_release, tmc_free_etr_buffer, usb_bypass_stop, block_size_store, tmc_read_unprepare_etr, tmc_alloc_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010c108 size=1
// signature: undefined mutex_unlock(void)
// callers: [tmc_read, tmc_etr_byte_cntr_read, tmc_etr_switch_mode, tmc_enable_etr_sink, tmc_disable_etr_sink, tmc_etr_byte_cntr_start, tmc_etr_byte_cntr_open, usb_notifier, tmc_read_prepare_etr, tmc_etr_byte_cntr_stop, tmc_etr_byte_cntr_release, tmc_free_etr_buffer, usb_bypass_stop, block_size_store, tmc_read_unprepare_etr, tmc_alloc_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010c110 size=1
// signature: size_t strlen(char * __s)
// callers: [out_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0010c118 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [out_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0010c120 size=1
// signature: undefined __check_object_size(void)
// callers: [tmc_read, tmc_etr_byte_cntr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0010c138 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [tmc_read, tmc_etr_byte_cntr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nonseekable_open @ 0010c148 size=1
// signature: undefined nonseekable_open(void)
// callers: [tmc_open, tmc_etr_byte_cntr_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010c168 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [tmc_enable_etf_sink, tmc_read_unprepare_etb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010c170 size=1
// signature: undefined kfree(void)
// callers: [tmc_alloc_sg_table, tmc_etr_alloc_sg_buf, tmc_enable_etr_sink_sysfs, tmc_free_etf_buffer, tmc_read_unprepare_etb, tmc_enable_etf_sink, tmc_pages_free, tmc_etr_alloc_flat_buf, tmc_alloc_etr_buf, usb_notifier, tmc_pages_alloc, tmc_etr_free_sg_buf, tmc_free_etr_buffer, tmc_etr_free_flat_buf, tmc_free_sg_table, tmc_read_unprepare_etr, tmc_alloc_etr_buffer, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_get_aux @ 0010c178 size=1
// signature: undefined perf_get_aux(void)
// callers: [tmc_enable_etf_sink, tmc_enable_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_get_aux(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010c180 size=1
// signature: undefined __kmalloc(void)
// callers: [tmc_enable_etf_sink, tmc_pages_alloc, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_claim_device @ 0010c188 size=1
// signature: undefined coresight_claim_device(void)
// callers: [tmc_enable_etf_link, tmc_enable_etf_sink, tmc_enable_etr_sink_sysfs, tmc_enable_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_claim_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disclaim_device @ 0010c190 size=1
// signature: undefined coresight_disclaim_device(void)
// callers: [tmc_enable_etf_link, tmc_etr_disable_hw, tmc_enable_etf_sink, tmc_disable_etf_sink, tmc_enable_etr_sink_sysfs, tmc_enable_etr_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disclaim_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_node_trace @ 0010c1a0 size=1
// signature: undefined kmalloc_node_trace(void)
// callers: [tmc_alloc_etf_buffer, tmc_alloc_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_node_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_aux_output_flag @ 0010c1a8 size=1
// signature: undefined perf_aux_output_flag(void)
// callers: [tmc_update_etf_buffer, tmc_update_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_aux_output_flag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disclaim_device_unlocked @ 0010c1b0 size=1
// signature: undefined coresight_disclaim_device_unlocked(void)
// callers: [tmc_disable_etf_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disclaim_device_unlocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vunmap @ 0010c1b8 size=1
// signature: undefined vunmap(void)
// callers: [tmc_alloc_sg_table, tmc_etr_free_sg_buf, tmc_free_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010c1c0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [tmc_etr_alloc_flat_buf, tmc_alloc_etr_buf, tmc_alloc_sg_table, tmc_etr_alloc_sg_buf, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmap @ 0010c1d0 size=1
// signature: undefined vmap(void)
// callers: [tmc_alloc_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_cpu @ 0010c1d8 size=1
// signature: undefined dma_sync_single_for_cpu(void)
// callers: [tmc_sg_table_sync_data_range, tmc_etr_sync_sg_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_device @ 0010c1e0 size=1
// signature: undefined dma_sync_single_for_device(void)
// callers: [tmc_etr_alloc_sg_buf, tmc_sg_table_sync_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010c1f0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [tmc_etr_switch_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 0010c1f8 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [tmc_pages_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 0010c200 size=1
// signature: undefined __free_pages(void)
// callers: [tmc_pages_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 0010c208 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [tmc_pages_free, tmc_pages_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 0010c210 size=1
// signature: undefined vfree(void)
// callers: [tmc_pages_free, tmc_pages_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 0010c218 size=1
// signature: undefined vmalloc(void)
// callers: [tmc_pages_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 0010c220 size=1
// signature: undefined __alloc_pages(void)
// callers: [tmc_pages_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 0010c228 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [tmc_pages_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_noncontiguous @ 0010c230 size=1
// signature: undefined dma_alloc_noncontiguous(void)
// callers: [tmc_etr_alloc_flat_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_noncontiguous(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_vmap_noncontiguous @ 0010c238 size=1
// signature: undefined dma_vmap_noncontiguous(void)
// callers: [tmc_etr_alloc_flat_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_vmap_noncontiguous(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_noncontiguous @ 0010c240 size=1
// signature: undefined dma_free_noncontiguous(void)
// callers: [tmc_etr_alloc_flat_buf, tmc_etr_free_flat_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_noncontiguous(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_sg_for_cpu @ 0010c248 size=1
// signature: undefined dma_sync_sg_for_cpu(void)
// callers: [tmc_etr_sync_flat_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_sg_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 0010c250 size=1
// signature: undefined sg_next(void)
// callers: [tmc_etr_sync_flat_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_vunmap_noncontiguous @ 0010c258 size=1
// signature: undefined dma_vunmap_noncontiguous(void)
// callers: [tmc_etr_free_flat_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_vunmap_noncontiguous(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0010c260 size=1
// signature: undefined _dev_warn(void)
// callers: [tmc_etr_sync_sg_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_get_domain_for_dev @ 0010c268 size=1
// signature: undefined iommu_get_domain_for_dev(void)
// callers: [tmc_alloc_etr_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_domain_for_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_iommu_get_mappings_configuration @ 0010c270 size=1
// signature: undefined qcom_iommu_get_mappings_configuration(void)
// callers: [tmc_alloc_etr_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_iommu_get_mappings_configuration(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 0010c278 size=1
// signature: undefined idr_find(void)
// callers: [tmc_alloc_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 0010c280 size=1
// signature: undefined idr_alloc(void)
// callers: [tmc_alloc_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010c288 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [tmc_free_etr_buffer, tmc_alloc_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 0010c290 size=1
// signature: undefined idr_remove(void)
// callers: [tmc_free_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010c298 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [tmc_update_etr_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010c2a0 size=1
// signature: undefined __wake_up(void)
// callers: [etr_handler, usb_notifier, tmc_etr_byte_cntr_stop, usb_bypass_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_csr_set_byte_cntr @ 0010c2a8 size=1
// signature: undefined coresight_csr_set_byte_cntr(void)
// callers: [usb_notifier, tmc_etr_byte_cntr_stop, tmc_etr_byte_cntr_release, usb_bypass_stop, tmc_etr_byte_cntr_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_csr_set_byte_cntr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 0010c2b0 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010c2b8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_read_string @ 0010c2c0 size=1
// signature: undefined device_property_read_string(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 0010c2c8 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 0010c2d0 size=1
// signature: undefined cdev_init(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 0010c2d8 size=1
// signature: undefined cdev_add(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0010c2e0 size=1
// signature: undefined __class_create(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0010c2e8 size=1
// signature: undefined device_create(void)
// callers: [byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010c2f0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [tmc_etr_usb_init, byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0010c2f8 size=1
// signature: undefined class_destroy(void)
// callers: [byte_cntr_remove, byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0010c300 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [byte_cntr_remove, byte_cntr_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 0010c308 size=1
// signature: undefined device_destroy(void)
// callers: [byte_cntr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010c310 size=1
// signature: undefined init_wait_entry(void)
// callers: [tmc_etr_byte_cntr_read, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010c318 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [tmc_etr_byte_cntr_read, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010c320 size=1
// signature: undefined finish_wait(void)
// callers: [tmc_etr_byte_cntr_read, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0010c328 size=1
// signature: undefined schedule(void)
// callers: [tmc_etr_byte_cntr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 0010c330 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [tmc_etr_byte_cntr_release, tmc_etr_byte_cntr_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0010c338 size=1
// signature: undefined __const_udelay(void)
// callers: [usb_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_qdss_alloc_req @ 0010c340 size=1
// signature: undefined usb_qdss_alloc_req(void)
// callers: [usb_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_qdss_alloc_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010c348 size=1
// signature: undefined queue_work_on(void)
// callers: [usb_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 0010c350 size=1
// signature: undefined flush_work(void)
// callers: [usb_notifier, tmc_usb_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_qdss_free_req @ 0010c358 size=1
// signature: undefined usb_qdss_free_req(void)
// callers: [usb_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_qdss_free_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010c360 size=1
// signature: undefined ___ratelimit(void)
// callers: [usb_notifier, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 0010c368 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [usb_notifier, usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_qdss_open @ 0010c370 size=1
// signature: undefined usb_qdss_open(void)
// callers: [tmc_usb_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_qdss_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_qdss_close @ 0010c378 size=1
// signature: undefined usb_qdss_close(void)
// callers: [tmc_usb_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_qdss_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010c380 size=1
// signature: undefined alloc_workqueue(void)
// callers: [tmc_etr_usb_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010c388 size=1
// signature: undefined schedule_timeout(void)
// callers: [usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_qdss_write @ 0010c390 size=1
// signature: undefined usb_qdss_write(void)
// callers: [usb_read_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_qdss_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



