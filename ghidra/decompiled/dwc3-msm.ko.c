// Decompiled by Ghidra 12.2
// Program: dwc3-msm.ko
// Image base: 00100000

//------------------------------------------------------------
// dwc3_core_stop_hw_active_transfers @ 00101d0c size=112
// signature: undefined dwc3_core_stop_hw_active_transfers(void)
// callers: [entry_dwc3_gadget_run_stop]
//------------------------------------------------------------

undefined8 dwc3_core_stop_hw_active_transfers(long param_1)

{
  long lVar1;
  int *piVar2;
  
  lVar1 = 0;
  piVar2 = (int *)(*(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98) + 0x540);
  do {
    if (*piVar2 == 2) {
      dwc3_core_stop_active_transfer(*(undefined8 *)(param_1 + 0x270 + lVar1));
    }
    lVar1 = lVar1 + 8;
    piVar2 = piVar2 + 10;
  } while (lVar1 != 0x100);
  return 0;
}



//------------------------------------------------------------
// dwc3_core_stop_active_transfer @ 00101d7c size=424
// signature: undefined dwc3_core_stop_active_transfer(void)
// callers: [dwc3_core_stop_hw_active_transfers, usb_gsi_ep_op]
//------------------------------------------------------------

void dwc3_core_stop_active_transfer(long param_1)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  undefined8 *puVar6;
  long lVar7;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  uVar5 = (ulong)*(byte *)(param_1 + 0xaa);
  if (0x1f < uVar5) {
LAB_00101f64:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101f68);
    (*pcVar2)();
  }
  lVar7 = *(long *)(param_1 + 0x98);
  puVar6 = *(undefined8 **)(*(long *)(*(long *)(lVar7 + 400) + 0x60) + 0x98);
  if (((*(byte *)(puVar6 + uVar5 * 5 + 0xab) & 1) != 0) &&
     ((*(byte *)(param_1 + 0xa5) >> 5 & 1) == 0)) {
    if (*(int *)(puVar6 + uVar5 * 5 + 0xa8) == 1) {
      bVar1 = *(byte *)(puVar6 + uVar5 * 5 + 0xaa);
      uVar3 = readl(puVar6[1] + (ulong)(*(int *)(puVar6[0x3b] + 0x60) + 0xf8000));
      writel(uVar3 | 1 << (ulong)(bVar1 & 0x1f),
             puVar6[1] + (ulong)(*(int *)(puVar6[0x3b] + 0x60) + 0xf8000));
    }
    else {
      _dev_info(*puVar6,"%s: No DBM EP matches USB EP %d\n","find_matching_dbm_ep");
    }
    local_48 = 0;
    local_40 = 0;
    iVar4 = dwc3_core_send_gadget_ep_cmd
                      (param_1,(uint)*(byte *)(param_1 + 0xac) << 0x10 | 0x808,&local_48);
    if (iVar4 != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101f1c);
      (*pcVar2)();
    }
    *(undefined1 *)(param_1 + 0xac) = 0;
    if ((*(int *)(lVar7 + 0x46c) == 0x3331) ||
       ((*(int *)(lVar7 + 0x46c) == 0x5533 && (*(uint *)(lVar7 + 0x470) < 0x5533310a)))) {
      __const_udelay(0x68dbc);
    }
    if ((*(byte *)(param_1 + 0xcc) >> 1 & 1) != 0) {
      *(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) | 0x100;
    }
    uVar5 = (ulong)*(byte *)(param_1 + 0xaa);
    if (0x1f < uVar5) goto LAB_00101f64;
    puVar6[uVar5 * 5 + 0xab] = puVar6[uVar5 * 5 + 0xab] & 0xfffffffffffffffe;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_data_fifo_config @ 00101f70 size=260
// signature: undefined msm_data_fifo_config(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_data_fifo_config(long param_1,ulong param_2,uint param_3,byte param_4)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  
  uVar2 = (uint)param_4;
  puVar5 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  if (uVar2 < 8) {
    if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102074);
      (*pcVar1)();
    }
    lVar4 = puVar5[0x3b];
    *(byte *)(puVar5 + (ulong)*(byte *)(param_1 + 0xaa) * 5 + 0xaa) = param_4;
    writel(param_2 & 0xffffffff,
           puVar5[1] + (ulong)(*(int *)(lVar4 + 0x88) + *(int *)(lVar4 + 0x8c) * uVar2 + 0xf8000));
    writel(param_2 >> 0x20,
           puVar5[1] +
           (ulong)(*(int *)(puVar5[0x3b] + 0x90) + *(int *)(puVar5[0x3b] + 0x94) * uVar2 + 0xf8000))
    ;
    lVar4 = puVar5[1] +
            (ulong)(*(int *)(puVar5[0x3b] + 0x10) + *(int *)(puVar5[0x3b] + 0x14) * uVar2 + 0xf8000)
    ;
    uVar2 = readl(lVar4);
    writel(uVar2 & 0xffff0000 | param_3,lVar4);
    readl(lVar4);
    uVar3 = 0;
  }
  else {
    _dev_err(*puVar5,"Invalid DBM EP num:%d\n",uVar2);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_dwc3_reset_dbm_ep @ 00102078 size=372
// signature: undefined msm_dwc3_reset_dbm_ep(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_dwc3_reset_dbm_ep(long param_1)

{
  byte bVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  uVar6 = (ulong)*(byte *)(param_1 + 0xaa);
  if (0x1f < uVar6) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1021ec);
    (*pcVar3)();
  }
  puVar9 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  if (*(int *)(puVar9 + uVar6 * 5 + 0xa8) == 1) {
    bVar1 = *(byte *)(puVar9 + uVar6 * 5 + 0xaa);
    _dev_info(*puVar9,"Resetting endpoint %d, DBM ep %d\n",uVar6,(ulong)bVar1);
    uVar6 = 1L << ((ulong)bVar1 & 0x3f);
    uVar10 = (uint)uVar6 & 0xf;
    uVar6 = (uVar6 & 10) >> 1 | (uVar6 & 5) << 1;
    lVar8 = puVar9[1] + (ulong)(*(int *)(puVar9[0x3b] + 0x68) + 0xf8000);
    uVar4 = readl(lVar8);
    writel(uVar4 & (uVar10 ^ 0xffffffff) |
           1 << (ulong)((uint)LZCOUNT((uVar6 >> 2 | (uVar6 & 0x3333333333333333) << 2) << 0x3c) &
                       0x1f),lVar8);
    readl(lVar8);
    lVar8 = 0;
    iVar7 = 0;
    do {
      lVar2 = lVar8 + 0x540;
      lVar8 = lVar8 + 0x28;
      if (*(int *)((long)puVar9 + lVar2) == 1) {
        iVar7 = iVar7 + 1;
      }
    } while (lVar8 != 0x500);
    if (iVar7 < 2) {
      __const_udelay(0xa7c6);
    }
    else {
      usleep_range_state(1000,0x4b0,2);
    }
    lVar8 = puVar9[1] + (ulong)(*(int *)(puVar9[0x3b] + 0x68) + 0xf8000);
    uVar4 = readl(lVar8);
    writel(uVar4 & ~uVar10,lVar8);
    readl(lVar8);
    uVar5 = 0;
  }
  else {
    _dev_info(*puVar9,"%s: No DBM EP matches USB EP %d\n","find_matching_dbm_ep");
    uVar5 = 0xffffffed;
  }
  return uVar5;
}



//------------------------------------------------------------
// usb_gsi_ep_op @ 001021f0 size=3548
// signature: undefined usb_gsi_ep_op(void)
// callers: []
//------------------------------------------------------------

uint usb_gsi_ep_op(long param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  undefined1 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  void *__s;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  char *pcVar10;
  char *pcVar11;
  ulong uVar12;
  code *pcVar13;
  long *plVar14;
  int iVar15;
  long *plVar16;
  undefined4 *puVar17;
  long lVar18;
  long lVar19;
  undefined8 *puVar20;
  byte *pbVar21;
  long lVar22;
  undefined8 local_78;
  uint local_70;
  long local_68;
  
  lVar22 = sp_el0;
  local_68 = *(long *)(lVar22 + 0x638);
  lVar22 = *(long *)(param_1 + 0x98);
  puVar20 = *(undefined8 **)(*(long *)(*(long *)(lVar22 + 400) + 0x60) + 0x98);
  if (param_3 < 0xe) {
    pcVar11 = (&gsi_op_strings)[param_3];
  }
  else {
    pcVar11 = "Invalid";
  }
  ipc_log_string(puVar20[0xa5],"%s: %s(%d):%s","usb_gsi_ep_op",*(undefined8 *)(param_1 + 8),
                 *(byte *)(param_1 + 0xaa) >> 1,pcVar11);
  switch(param_3) {
  case 0:
    if (((uint)*(undefined6 *)(lVar22 + 0x4e8) >> 0xc & 1) == 0) goto LAB_00102700;
    uVar9 = _raw_spin_lock_irqsave(lVar22 + 0x158);
    lVar18 = *(long *)(param_1 + 0x38);
    uVar8 = *(undefined8 *)(param_1 + 0x40);
    bVar1 = param_2[0x34];
    puVar20 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
    if ((*(byte *)(param_1 + 0xa5) >> 6 & 1) == 0) {
      local_78 = 0;
      local_70 = 1;
      iVar4 = dwc3_core_send_gadget_ep_cmd(param_1,2,&local_78);
      if (iVar4 == 0) {
        *(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) | 0x4000;
      }
    }
    iVar4 = ((uint)bVar1 << 2 | 0xf8800) - 4;
    writel(*(undefined4 *)((long)puVar20 + 0x504),
           puVar20[1] + (ulong)(uint)(*(int *)(puVar20[0x99] + 8) + iVar4));
    writel(*(undefined4 *)(puVar20 + 0xa0),
           puVar20[1] + (ulong)(uint)(*(int *)(puVar20[0x99] + 4) + iVar4));
    _dev_info(*puVar20,"Dummy DB Addr %pK: %llx\n",puVar20 + 0x9f,puVar20[0xa0]);
    local_70 = 0;
    local_78 = 0;
    dwc3_msm_depcfg_params(param_1,&local_78);
    uVar12 = local_78 & 0xffffffff;
    local_78._4_4_ = local_78._4_4_ | param_2[0x34] & 0x1f;
    _dev_info(*puVar20,"Set EP config to params = %x %x %x, for %s\n",local_70,local_78._4_4_,uVar12
              ,param_1 + 0xb8);
    dwc3_core_send_gadget_ep_cmd(param_1,1,&local_78);
    uVar5 = *(uint *)(param_1 + 0xa4);
    if ((uVar5 & 1) == 0) {
      dwc3_core_resize_tx_fifos(param_1);
      *(long *)(param_1 + 0x38) = lVar18;
      *(undefined8 *)(param_1 + 0x40) = uVar8;
      bVar1 = *(byte *)(lVar18 + 3);
      *(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) | 1;
      *(byte *)(param_1 + 0xab) = bVar1 & 3;
      uVar5 = readl(puVar20[1] + 0xc720);
      writel(uVar5 | (uint)(1L << ((ulong)*(byte *)(param_1 + 0xaa) & 0x3f)),puVar20[1] + 0xc720);
      uVar5 = *(uint *)(param_1 + 0xa4);
    }
    if ((uVar5 >> 0xe & 1) == 0) {
      local_78 = 0;
      local_70 = 1;
      dwc3_core_send_gadget_ep_cmd(param_1,2,&local_78);
      *(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) | 0x4000;
    }
    _raw_spin_unlock_irqrestore(lVar22 + 0x158,uVar9);
    break;
  case 1:
    if (((uint)*(undefined6 *)(lVar22 + 0x4e8) >> 0xc & 1) != 0) {
      uVar8 = _raw_spin_lock_irqsave(lVar22 + 0x158);
      lVar18 = *(long *)(param_1 + 0x98);
      local_70 = (uint)((ulong)*(long *)(param_1 + 0x90) >> 0x20) & 0xffff |
                 (uint)param_2[0x34] << 0x10 | 0xa00000;
      local_78 = *(long *)(param_1 + 0x90) << 0x20;
      uVar5 = dwc3_core_send_gadget_ep_cmd(param_1,6,&local_78);
      if ((int)uVar5 < 0) {
        _dev_info(*(undefined8 *)(lVar18 + 400),"Fail StrtXfr on GSI EP#%d\n",
                  *(undefined1 *)(param_1 + 0xaa));
      }
      uVar9 = *(undefined8 *)(lVar18 + 400);
      pcVar11 = "XferRsc = %x";
      uVar2 = *(undefined1 *)(param_1 + 0xac);
LAB_00102bf8:
      _dev_info(uVar9,pcVar11,uVar2);
      goto LAB_00102640;
    }
    goto LAB_00102700;
  case 2:
    lVar18 = *(long *)(param_1 + 0x98);
    puVar20 = *(undefined8 **)(*(long *)(*(long *)(lVar18 + 400) + 0x60) + 0x98);
    iVar15 = param_2[0x34] - 1;
    iVar4 = iVar15 * 4 + 0xf8800;
    writel(*(undefined4 *)(param_1 + 0x90),
           puVar20[1] + (ulong)(uint)(iVar4 + *(int *)(puVar20[0x99] + 0xc)));
    writel(*(undefined4 *)(param_1 + 0x94),
           puVar20[1] + (ulong)(uint)(*(int *)(puVar20[0x99] + 0x10) + iVar4));
    _dev_info(*puVar20,"Ring Base Addr %d: %x (LSB) %x (MSB)\n",iVar15,
              *(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x94));
    lVar22 = *(long *)(param_2 + 0x28);
    if (lVar22 == 0) {
      lVar22 = dma_map_resource(*(undefined8 *)(lVar18 + 0x198),*(undefined4 *)(param_2 + 0x20),
                                0x1000,0);
      *(long *)(param_2 + 0x28) = lVar22;
      if (lVar22 == -1) {
        _dev_err(*puVar20,"mapping error for db_reg_phs_addr_lsb\n");
        lVar22 = *(long *)(param_2 + 0x28);
      }
    }
    _dev_info(*puVar20,"ep:%s dbl_addr_lsb:%x mapped_dbl_addr_lsb:%llx\n",
              *(undefined8 *)(param_1 + 8),*(undefined4 *)(param_2 + 0x20),lVar22);
    ipc_log_string(puVar20[0xa5],"%s: ep:%s dbl_addr_lsb:%x mapped_addr:%llx\n",
                   "gsi_store_ringbase_dbl_info",*(undefined8 *)(param_1 + 8),
                   *(undefined4 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x28));
    writel(*(undefined4 *)(param_2 + 0x2c),
           puVar20[1] + (ulong)(uint)(*(int *)(puVar20[0x99] + 8) + iVar4));
    writel(*(undefined4 *)(param_2 + 0x28),
           puVar20[1] + (ulong)(uint)(*(int *)(puVar20[0x99] + 4) + iVar4));
    _dev_info(*puVar20,"GSI DB Addr %d: %pad\n",iVar15,param_2 + 0x28);
    break;
  case 3:
    if (((uint)*(undefined6 *)(lVar22 + 0x4e8) >> 0xc & 1) != 0) {
      puVar20 = *(undefined8 **)
                 (*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
      lVar22 = puVar20[1] + (ulong)(*(int *)puVar20[0x99] + 0xf8800);
      uVar5 = readl(lVar22);
      writel(uVar5 | 0x1000,lVar22);
      readl(lVar22);
      lVar22 = puVar20[1] + (ulong)(*(int *)puVar20[0x99] + 0xf8800);
      uVar5 = readl(lVar22);
      writel(uVar5 | 0x100000,lVar22);
      readl(lVar22);
      lVar22 = puVar20[1] + (ulong)(*(int *)puVar20[0x99] + 0xf8800);
      uVar5 = readl(lVar22);
      writel(uVar5 & 0xffefffff,lVar22);
      readl(lVar22);
      _dev_info(*puVar20,"%s: Enable GSI\n","gsi_enable");
      lVar22 = puVar20[1] + (ulong)(*(int *)puVar20[0x99] + 0xf8800);
      uVar5 = readl(lVar22);
      uVar5 = uVar5 | 1;
      goto LAB_00102828;
    }
    goto LAB_00102700;
  case 4:
    uVar8 = _raw_spin_lock_irqsave(lVar22 + 0x158);
    uVar12 = *(ulong *)(param_2 + 0x10);
    lVar18 = *(long *)(param_1 + 0x98);
    if (0 < (int)uVar12) {
      lVar7 = 0;
      do {
        lVar6 = *(long *)(param_1 + 0x88) + lVar7;
        lVar7 = lVar7 + 0x10;
        *(uint *)(lVar6 + 0xc) = *(uint *)(lVar6 + 0xc) | 1;
      } while ((uVar12 & 0xffffffff) * 0x10 != lVar7);
    }
    local_70 = 0;
    local_78 = 0;
    uVar5 = dwc3_core_send_gadget_ep_cmd
                      (param_1,(uint)*(byte *)(param_1 + 0xac) << 0x10 | 7,&local_78);
    if ((int)uVar5 < 0) {
      uVar9 = *(undefined8 *)(lVar18 + 400);
      pcVar11 = "UpdateXfr fail on GSI EP#%d\n";
      uVar2 = *(undefined1 *)(param_1 + 0xaa);
      goto LAB_00102bf8;
    }
LAB_00102640:
    _raw_spin_unlock_irqrestore(lVar22 + 0x158,uVar8);
    goto LAB_001029e4;
  case 5:
    if (((uint)*(undefined6 *)(lVar22 + 0x4e8) >> 0xc & 1) == 0) goto LAB_00102700;
    pbVar21 = param_2 + 0x20;
    bVar1 = *(byte *)(param_1 + 0xcc);
    uVar8 = 0x68000000000713;
    if (arm64_use_ng_mappings != '\0') {
      uVar8 = 0x68000000000f13;
    }
    lVar18 = *(long *)(param_2 + 0x10);
    puVar20 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
    lVar22 = ioremap_prot(*(undefined4 *)pbVar21,4,uVar8);
    if (lVar22 == 0) {
      _dev_err(*puVar20,"Failed to map GSI DBL address LSB 0x%x\n",*(undefined4 *)pbVar21);
    }
    else {
      param_2 = param_2 + 0x30;
      uVar8 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar8 = 0x68000000000f13;
      }
      lVar7 = ioremap_prot(*(undefined4 *)param_2,4,uVar8);
      if (lVar7 == 0) {
        _dev_err(*puVar20,"Failed to map GSI DBL address MSB 0x%x\n",*(undefined4 *)param_2);
        iounmap(lVar22);
      }
      else {
        local_78 = *(long *)(param_1 + 0x90) +
                   (((lVar18 << (bVar1 & 1)) << 0x20) + 0x100000000U >> 0x1c & 0xfffffff0);
        _dev_info(*puVar20,"Writing link TRB addr: %pad to %pK (lsb:%x msb:%x) for ep:%s\n",
                  &local_78,lVar22,*(undefined4 *)pbVar21,*(undefined4 *)param_2,
                  *(undefined8 *)(param_1 + 8));
        ipc_log_string(puVar20[0xa5],"%s: ep:%s link TRB addr:%pad db_lsb:%pad db_msb:%pad\n",
                       "gsi_ring_db",*(undefined8 *)(param_1 + 8),&local_78,pbVar21,param_2);
        writel_relaxed(local_78 & 0xffffffff,lVar22);
        writel_relaxed(local_78._4_4_,lVar7);
        iounmap(lVar22);
        iounmap(lVar7);
      }
    }
    break;
  case 6:
    uVar8 = _raw_spin_lock_irqsave(lVar22 + 0x158);
    dwc3_core_stop_active_transfer(param_1);
    _raw_spin_unlock_irqrestore(lVar22 + 0x158,uVar8);
    break;
  case 7:
    lVar22 = *(long *)(param_1 + 0x98);
    bVar1 = *(byte *)(param_1 + 0xaa);
    lVar18 = *(long *)(*(long *)(*(long *)(lVar22 + 400) + 0x60) + 0x98);
    iVar4 = *(int *)(lVar18 + 0x20);
    param_2[8] = 0;
    iVar4 = iVar4 + (uint)bVar1 * 0x10 + 0xc80c;
    lVar7 = *(long *)(param_2 + 0x20);
    *(int *)(param_2 + 4) = iVar4;
    *(undefined8 *)(param_2 + 0x18) = *(undefined8 *)(param_1 + 0x90);
    param_2[2] = (byte)(*(ulong *)(lVar7 + 0x18) >> 10);
    if ((*(byte *)(param_1 + 0xcc) & 1) == 0) {
      *(short *)(param_2 + 0x12) = *(short *)(lVar7 + 0x10) * 0x10 + 0x20;
      lVar6 = *(long *)(lVar7 + 0x10);
    }
    else {
      *(short *)(param_2 + 0x12) = *(short *)(lVar7 + 0x10) * 0x20 + 0x20;
      lVar6 = *(long *)(lVar7 + 0x10) << 1;
    }
    lVar6 = *(long *)(param_1 + 0x90) + ((lVar6 << 0x20) + 0x100000000U >> 0x1c);
    *(short *)param_2 = (short)lVar6;
    iVar15 = *(int *)(lVar18 + 0x20);
    bVar1 = *(byte *)(lVar7 + 0x34);
    param_2[0x10] = 0;
    iVar15 = iVar15 + (uint)bVar1 * 0x10 + 0xc40c;
    *(int *)(param_2 + 0xc) = iVar15;
    _dev_info(*(undefined8 *)(lVar22 + 400),
              "depcmd_laddr=%x last_trb_addr=%x gevtcnt_laddr=%x gevtcnt_haddr=%x",iVar4,
              (uint)lVar6 & 0xffff,iVar15,0);
    break;
  case 8:
    uVar5 = (uint)*(byte *)(param_1 + 0xac);
    goto LAB_001029e4;
  case 9:
    if (((uint)*(undefined6 *)(lVar22 + 0x4e8) >> 0xc & 1) != 0) {
      lVar22 = *(long *)(param_1 + 0x98);
      lVar18 = *(long *)(*(long *)(*(long *)(lVar22 + 400) + 0x60) + 0x98);
      if (1 < *(byte *)(param_1 + 0xaa)) {
        __s = *(void **)(param_1 + 0x88);
        if ((__s != (void *)0x0) && (*(long *)(param_1 + 0x90) != 0)) {
          memset(__s,0,0x1000);
          dwc3_dbg_print(*(undefined8 *)(lVar18 + 0x528),*(undefined1 *)(param_1 + 0xaa),"Clr_TRB",0
                         ,&DAT_00111364);
          _dev_info(*(undefined8 *)(lVar22 + 400),"Clr_TRB ring of %s\n",param_1 + 0xb8);
          dma_free_attrs(*(undefined8 *)(lVar22 + 0x198),0x1000,*(undefined8 *)(param_1 + 0x88),
                         *(undefined8 *)(param_1 + 0x90),0);
          lVar22 = *(long *)(param_1 + 0x98);
          *(undefined8 *)(param_1 + 0x88) = 0;
          *(undefined8 *)(param_1 + 0x90) = 0;
          lVar18 = *(long *)(*(long *)(*(long *)(lVar22 + 400) + 0x60) + 0x98);
        }
      }
      lVar7 = *(long *)(param_2 + 0x10);
      bVar1 = *(byte *)(param_1 + 0xcc);
      lVar19 = *(long *)(param_2 + 0x18) * lVar7;
      lVar6 = dma_alloc_attrs(*(undefined8 *)(lVar22 + 0x198),lVar19,param_2 + 8,0xcc0,0);
      *(long *)param_2 = lVar6;
      if (lVar6 != 0) {
        iVar4 = (int)lVar7 << ((ulong)bVar1 & 1);
        uVar5 = iVar4 + 2;
        dma_get_sgtable_attrs
                  (*(undefined8 *)(lVar22 + 0x198),param_2 + 0x48,lVar6,*(undefined8 *)(param_2 + 8)
                   ,lVar19,0);
        local_78 = *(ulong *)(param_2 + 8);
        ipc_log_string(*(undefined8 *)(lVar18 + 0x528),"%s: TRB buffer_addr = %pad buf_len = %zu\n",
                       "gsi_prepare_trbs",&local_78,*(undefined8 *)(param_2 + 0x18));
        uVar12 = -(ulong)(uVar5 >> 0x1f) & 0xfffffff000000000 | (ulong)uVar5 << 4;
        lVar7 = dma_alloc_attrs(*(undefined8 *)(lVar22 + 0x198),uVar12,param_1 + 0x90,0xcc0,0);
        *(long *)(param_1 + 0x88) = lVar7;
        if (lVar7 != 0) {
          memset(*(void **)(param_1 + 0x88),0,uVar12);
          if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) goto LAB_00102fc8;
          lVar7 = *(long *)(param_1 + 0x90);
          *(uint *)(lVar18 + (ulong)*(byte *)(param_1 + 0xaa) * 0x28 + 0x554) = uVar5;
          dma_get_sgtable_attrs
                    (*(undefined8 *)(lVar22 + 0x198),param_2 + 0x38,*(undefined8 *)(param_1 + 0x88),
                     *(undefined8 *)(param_1 + 0x90),uVar12,0);
          _dev_info(*(undefined8 *)(lVar22 + 400),"%s(): trb_pool:%pK trb_pool_dma:%lx\n",
                    "gsi_prepare_trbs",*(undefined8 *)(param_1 + 0x88),
                    *(undefined8 *)(param_1 + 0x90));
          if (*(int *)(param_2 + 0x40) != 0) {
            uVar5 = 0;
            puVar20 = *(undefined8 **)(param_2 + 0x38);
            do {
              _dev_info(*(undefined8 *)(lVar22 + 400),
                        "%i: page_link:%lx offset:%x length:%x address:%lx\n",uVar5,*puVar20,
                        *(undefined4 *)(puVar20 + 1),*(undefined4 *)((long)puVar20 + 0xc),puVar20[2]
                       );
              uVar5 = uVar5 + 1;
              puVar20 = (undefined8 *)sg_next(puVar20);
            } while (uVar5 < *(uint *)(param_2 + 0x40));
          }
          plVar14 = *(long **)(param_1 + 0x88);
          uVar5 = (uint)((ulong)lVar7 >> 0x20);
          if ((*(byte *)(param_1 + 0xcc) & 1) == 0) {
            plVar16 = plVar14 + 2;
            *(undefined4 *)((long)plVar14 + 0xc) = 0x80;
            *plVar14 = lVar7 + 0x10;
            if (1 < iVar4 + 1) {
              do {
                plVar14 = plVar16;
                iVar4 = iVar4 + -1;
                *(int *)plVar14 = (int)local_78;
                *(uint *)((long)plVar14 + 4) = local_78._4_4_;
                *(int *)(plVar14 + 1) = (int)*(undefined8 *)(param_2 + 0x18);
                local_78 = local_78 + *(long *)(param_2 + 0x18);
                *(undefined4 *)((long)plVar14 + 0xc) = 0xc18;
                plVar16 = plVar14 + 2;
              } while (iVar4 != 0);
            }
            uVar5 = uVar5 & 0xffff;
            *(int *)plVar16 = (int)lVar7;
            *(uint *)((long)plVar14 + 0x14) = uVar5;
            puVar17 = (undefined4 *)((long)plVar14 + 0x1c);
            *(uint *)((long)plVar14 + 0x14) = uVar5 | (uint)param_2[0x34] << 0x10 | 0xa00000;
          }
          else {
            if (*(long *)(param_2 + 0x10) == -1) {
              iVar15 = 0;
            }
            else {
              iVar15 = 0;
              do {
                *(undefined4 *)((long)plVar14 + 0xc) = 0x810;
                iVar15 = iVar15 + 1;
                plVar14 = plVar14 + 2;
              } while ((ulong)(long)iVar15 < *(long *)(param_2 + 0x10) + 1U);
            }
            if (iVar15 < iVar4 + 1) {
              iVar4 = (iVar4 - iVar15) + 1;
              do {
                *(int *)plVar14 = (int)local_78;
                iVar4 = iVar4 + -1;
                *(undefined4 *)((long)plVar14 + 0xc) = 0x810;
                *(uint *)((long)plVar14 + 4) = local_78._4_4_;
                plVar14 = plVar14 + 2;
                local_78 = local_78 + *(long *)(param_2 + 0x18);
              } while (iVar4 != 0);
            }
            uVar5 = uVar5 & 0xffff;
            *(int *)plVar14 = (int)lVar7;
            *(uint *)((long)plVar14 + 4) = uVar5;
            puVar17 = (undefined4 *)((long)plVar14 + 0xc);
            *(uint *)((long)plVar14 + 4) = uVar5 | (uint)param_2[0x34] << 0x10 | 0xa00000;
          }
          *puVar17 = 0x81;
          _dev_info(*(undefined8 *)(lVar22 + 400),"%s: Initialized TRB Ring for %s\n",
                    "gsi_prepare_trbs",param_1 + 0xb8);
          break;
        }
        dma_free_attrs(*(undefined8 *)(lVar22 + 0x198),lVar19,*(undefined8 *)param_2,
                       *(undefined8 *)(param_2 + 8),0);
        param_2[0] = 0;
        param_2[1] = 0;
        param_2[2] = 0;
        param_2[3] = 0;
        param_2[4] = 0;
        param_2[5] = 0;
        param_2[6] = 0;
        param_2[7] = 0;
        sg_free_table(param_2 + 0x48);
      }
      uVar5 = 0xfffffff4;
      goto LAB_001029e4;
    }
LAB_00102700:
    ipc_log_string(puVar20[0xa5],"%s: No Pullup\n","usb_gsi_ep_op");
    uVar5 = 0xffffff94;
    goto LAB_001029e4;
  case 10:
    uVar12 = (ulong)*(byte *)(param_1 + 0xaa);
    if (0x1f < uVar12) {
LAB_00102fc8:
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x5512,0x102fcc);
      (*pcVar13)();
    }
    lVar18 = *(long *)(param_1 + 0x98);
    lVar22 = *(long *)(*(long *)(*(long *)(lVar18 + 400) + 0x60) + 0x98);
    if (*(int *)(lVar22 + uVar12 * 0x28 + 0x540) == 2) {
      if (*(long *)(param_1 + 0x90) != 0) {
        dma_free_attrs(*(undefined8 *)(lVar18 + 0x198),
                       (long)*(int *)(lVar22 + uVar12 * 0x28 + 0x554) << 4,
                       *(undefined8 *)(param_1 + 0x88),*(long *)(param_1 + 0x90),0);
        *(undefined8 *)(param_1 + 0x88) = 0;
        *(undefined8 *)(param_1 + 0x90) = 0;
      }
      sg_free_table(param_2 + 0x38);
      dma_free_attrs(*(undefined8 *)(lVar18 + 0x198),
                     *(long *)(param_2 + 0x10) * *(long *)(param_2 + 0x18),*(undefined8 *)param_2,
                     *(undefined8 *)(param_2 + 8),0);
      param_2[0] = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      sg_free_table(param_2 + 0x48);
    }
    if (*(long *)(param_1 + 0x88) == 0) {
      lVar22 = dma_alloc_attrs(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x198),0x1000,
                               param_1 + 0x90,0xcc0,0);
      *(long *)(param_1 + 0x88) = lVar22;
      if (lVar22 == 0) {
        pcVar11 = (char *)(param_1 + 0xb8);
        pcVar10 = "failed to allocate trb pool for %s\n";
        uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x98) + 400);
        goto LAB_00102a34;
      }
    }
    break;
  case 0xb:
    bVar1 = *param_2;
    lVar22 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
    lVar22 = *(long *)(lVar22 + 8) + (ulong)(**(int **)(lVar22 + 0x4c8) + 0xf8800);
    uVar5 = readl(lVar22);
    uVar5 = uVar5 & 0xfffffffd | (uint)bVar1 << 1;
LAB_00102828:
    writel(uVar5,lVar22);
    readl(lVar22);
    break;
  case 0xc:
    iVar4 = -0x5dd;
    do {
      uVar5 = readl(puVar20[1] + (ulong)(*(int *)(puVar20[0x99] + 0x14) + 0xf8800));
      if ((uVar5 >> 0xf & 1) == 0) {
        uVar5 = 1;
        goto LAB_001029e4;
      }
      bVar3 = iVar4 != -1;
      iVar4 = iVar4 + 1;
    } while (bVar3);
    _dev_err(*puVar20,"Unable to suspend GSI ch. WR_CTRL_STATE != 0\n");
    uVar5 = (uVar5 & 0x8000) >> 0xf ^ 1;
    goto LAB_001029e4;
  case 0xd:
    uVar8 = _raw_spin_lock_irqsave(lVar22 + 0x158);
    dwc3_core_stop_active_transfer(param_1);
    _raw_spin_unlock_irqrestore(lVar22 + 0x158,uVar8);
    pcVar13 = *(code **)(*(long *)(param_1 + 0x10) + 8);
    if (*(int *)(pcVar13 + -4) != 0x11c93a2e) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1028d8);
      (*pcVar13)();
    }
    uVar5 = (*pcVar13)(param_1);
    goto LAB_001029e4;
  default:
    uVar8 = *puVar20;
    pcVar10 = "%s: Invalid opcode GSI EP\n";
    pcVar11 = "usb_gsi_ep_op";
LAB_00102a34:
    _dev_err(uVar8,pcVar10,pcVar11);
  }
  uVar5 = 0;
LAB_001029e4:
  lVar22 = sp_el0;
  if (*(long *)(lVar22 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// msm_ep_config @ 00102fd0 size=1368
// signature: undefined msm_ep_config(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ep_config(long param_1,long param_2,uint param_3)

{
  long lVar1;
  int *piVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  int iVar15;
  undefined8 uVar16;
  ulong uVar17;
  undefined8 *puVar18;
  undefined8 *puVar19;
  
  lVar1 = *(long *)(param_1 + 0x98) + 0x158;
  puVar19 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  uVar9 = _raw_spin_lock_irqsave(lVar1);
  bVar4 = *(byte *)(param_1 + 0xaa);
  uVar17 = (ulong)bVar4;
  if (0x1f < uVar17) goto LAB_00103524;
  if (*(int *)(puVar19 + uVar17 * 5 + 0xa8) == 3) {
    puVar18 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
    uVar7 = readl(puVar18[1] + 0xf8a04);
    uVar8 = readl(puVar18[1] + 0xc70c);
    if ((uVar8 & 7) == 4) {
      uVar7 = uVar7 | 1;
    }
    else if ((uVar8 & 7) == 5) {
      uVar7 = uVar7 | 2;
    }
    else {
      uVar7 = uVar7 & 0xfffffffc;
    }
    writel(uVar7,puVar18[1] + 0xf8a04);
    puVar11 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
    lVar12 = puVar11[0x147];
    if (lVar12 == 0) {
      _dev_err(*puVar11,"%s: ebc_desc_addr not specified\n","msm_ep_setup_ebc_trbs");
      uVar16 = 0xffffffea;
    }
    else {
      bVar4 = *(byte *)(param_1 + 0xaa);
      iVar14 = 0x8000;
      if ((*(byte *)(param_1 + 0xcc) & 1) != 0) {
        iVar14 = 0x4000;
      }
      if ((0x20 < bVar4) || (bVar4 == 0x20)) goto LAB_00103524;
      uVar3 = *(uint *)(param_2 + 8);
      uVar8 = (*(byte *)(param_1 + 0xcc) & 1) << 9 ^ 0x200;
      uVar7 = uVar3 >> 0xe;
      *(uint *)((long)puVar11 + (ulong)bVar4 * 0x28 + 0x554) = uVar7;
      lVar12 = memremap(uVar8 + (int)lVar12,(ulong)uVar7 << 4,2);
      puVar11[(ulong)bVar4 * 5 + 0xa9] = lVar12;
      if (lVar12 != 0) {
        if (0x3fff < uVar3) {
          uVar3 = uVar7 - 1;
          if (uVar7 == 0 || uVar3 == 0) {
            uVar7 = 1;
          }
          lVar12 = 0;
          do {
            lVar10 = puVar11[(ulong)bVar4 * 5 + 0xa9];
            piVar2 = (int *)(lVar10 + lVar12);
            *piVar2 = iVar14;
            piVar2[1] = 0x8000;
            piVar2[2] = 0x4000;
            piVar2[3] = 0x15;
            if ((ulong)uVar3 * 0x10 == lVar12) {
              iVar15 = 0;
              *(uint *)(lVar10 + lVar12) = uVar8;
              piVar2[1] = 0x8000;
              piVar2[2] = 0;
              piVar2[3] = 0x81;
            }
            else {
              iVar15 = 0x4000;
            }
            iVar14 = iVar15 + iVar14;
            lVar12 = lVar12 + 0x10;
          } while ((ulong)uVar7 * 0x10 != lVar12);
        }
        uVar17 = (ulong)*(byte *)(param_1 + 0xaa) + 0xf;
        if ((*(byte *)(param_1 + 0xcc) & 1) != 0) {
          uVar17 = (ulong)(*(byte *)(param_1 + 0xaa) >> 1);
        }
        uVar7 = readl(puVar18[1] + 0xf8a00);
        writel(uVar7 | (uint)(1L << (uVar17 & 0x3f)),puVar18[1] + 0xf8a00);
        uVar7 = readl(puVar18[1] + 0xf8a04);
        writel(uVar7 | 0x1000,puVar18[1] + 0xf8a04);
        uVar7 = readl(puVar18[1] + 0xf8a10);
        uVar7 = uVar7 | 1;
        lVar12 = puVar18[1] + 0xf8a10;
        goto LAB_001031b0;
      }
      uVar16 = 0xfffffff4;
    }
    _dev_err(*puVar18,"error %d setting up ebc trbs\n",uVar16);
    _dev_err(*puVar19,"error %d after calling ebc_ep_config\n",uVar16);
  }
  else {
    _dev_info(*puVar19,"Configuring DBM ep\n");
    if (*(int *)(puVar19 + uVar17 * 5 + 0xa8) == 1) {
      bVar5 = *(byte *)(puVar19 + uVar17 * 5 + 0xaa);
      if ((((param_3 & 0x80) == 0) || (*(char *)((long)puVar19 + 0x1e4) != '\0')) || (bVar5 != 7)) {
        uVar13 = 1L << ((ulong)bVar5 & 0x3f);
        uVar17 = (uVar13 & 10) >> 1 | (uVar13 & 5) << 1;
        lVar12 = puVar19[1] + (ulong)(*(int *)(puVar19[0x3b] + 0x30) + 0xf8000);
        uVar7 = readl(lVar12);
        writel(uVar7 & ((uint)uVar13 & 0xf ^ 0xffffffff) |
               (param_3 >> 9 & 1) <<
               (ulong)((uint)LZCOUNT((uVar17 >> 2 | (uVar17 & 0x3333333333333333) << 2) << 0x3c) &
                      0x1f),lVar12);
        readl(lVar12);
        lVar12 = puVar19[1] +
                 (ulong)(*(int *)puVar19[0x3b] + ((int *)puVar19[0x3b])[1] * (uint)bVar5 + 0xf8000);
        uVar7 = readl(lVar12);
        writel(uVar7 & 0xfffff8ff |
               param_3 & 0x400 | (param_3 >> 7 & 2 | (param_3 & 0x80) >> 7) << 8,lVar12);
        readl(lVar12);
        uVar8 = (uint)bVar5;
        lVar12 = puVar19[1] +
                 (ulong)(*(int *)puVar19[0x3b] + ((int *)puVar19[0x3b])[1] * uVar8 + 0xf8000);
        uVar7 = readl(lVar12);
        writel(uVar7 & 0xffffffc1 | (uint)bVar4 << 1,lVar12);
        readl(lVar12);
        if (*(char *)((long)puVar19 + 0x1e4) != '\0') {
          lVar12 = puVar19[1] +
                   (ulong)(*(int *)puVar19[0x3b] + ((int *)puVar19[0x3b])[1] * uVar8 + 0xf8000);
          uVar7 = readl(lVar12);
          writel(uVar7 & 0xffffff3f | (param_3 & 0x1f) << 6,lVar12);
          readl(lVar12);
          lVar12 = puVar19[1] + (ulong)(*(int *)(puVar19[0x3b] + 0x58) + 0xf8000);
          uVar7 = readl(lVar12);
          writel(uVar7 & 0xffffff00 | 0xe4,lVar12);
          readl(lVar12);
        }
        lVar12 = puVar19[1] +
                 (ulong)(*(int *)puVar19[0x3b] + ((int *)puVar19[0x3b])[1] * uVar8 + 0xf8000);
        uVar7 = readl(lVar12);
        writel(uVar7 | 1,lVar12);
        readl(lVar12);
        uVar7 = readl(puVar19[1] + (ulong)(*(int *)(puVar19[0x3b] + 0x60) + 0xf8000));
        uVar7 = uVar7 & ((uint)uVar13 ^ 0xffffffff);
        lVar12 = puVar19[1] + (ulong)(*(int *)(puVar19[0x3b] + 0x60) + 0xf8000);
LAB_001031b0:
        writel(uVar7,lVar12);
        if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
LAB_00103524:
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103528);
          (*pcVar6)();
        }
        uVar16 = 0;
        puVar19[(ulong)*(byte *)(param_1 + 0xaa) * 5 + 0xa7] = param_1;
        goto LAB_001031d0;
      }
      _printk(&DAT_00111bfb);
    }
    else {
      _dev_info(*puVar19,"%s: No DBM EP matches USB EP %d\n","find_matching_dbm_ep",uVar17);
    }
    uVar16 = 0xffffffed;
    _dev_err(*puVar19,"error %d after calling dbm_ep_config\n",0xffffffed);
  }
LAB_001031d0:
  _raw_spin_unlock_irqrestore(lVar1,uVar9);
  return uVar16;
}



//------------------------------------------------------------
// msm_ep_unconfig @ 0010352c size=484
// signature: undefined msm_ep_unconfig(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ep_unconfig(long param_1)

{
  int *piVar1;
  long lVar2;
  ulong uVar3;
  byte bVar4;
  code *pcVar5;
  uint uVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  undefined8 *puVar10;
  
  lVar2 = *(long *)(param_1 + 0x98) + 0x158;
  puVar10 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  uVar7 = _raw_spin_lock_irqsave(lVar2);
  bVar4 = *(byte *)(param_1 + 0xaa);
  if (bVar4 < 0x20) {
    if (*(int *)(puVar10 + (ulong)(uint)bVar4 * 5 + 0xa8) == 3) {
      uVar3 = (ulong)bVar4 + 0xf;
      if ((*(byte *)(param_1 + 0xcc) & 1) != 0) {
        uVar3 = (ulong)(bVar4 >> 1);
      }
      uVar6 = readl(puVar10[1] + 0xf8a00);
      writel(uVar6 & ((uint)(1L << (uVar3 & 0x3f)) ^ 0xffffffff),puVar10[1] + 0xf8a00);
      writel(0,puVar10[1] + 0xf8a00);
      uVar6 = readl(puVar10[1] + 0xf8a04);
      writel(uVar6 & 0xffffefff,puVar10[1] + 0xf8a04);
      if (0x20 < (ulong)*(byte *)(param_1 + 0xaa)) goto LAB_0010370c;
      lVar9 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98) +
              (ulong)*(byte *)(param_1 + 0xaa) * 0x28;
      if (*(long *)(lVar9 + 0x548) != 0) {
        memunmap();
        *(undefined8 *)(lVar9 + 0x548) = 0;
      }
    }
    else if (((*(char *)(param_1 + 0xa9) == *(char *)(param_1 + 0xa8)) &&
             (*(long **)(param_1 + 0x60) == (long *)(param_1 + 0x60))) &&
            (*(long **)(param_1 + 0x70) == (long *)(param_1 + 0x70))) {
      _dev_info(*puVar10,"%s: request is not queued, disable DBM ep for ep %s\n","msm_ep_unconfig",
                *(undefined8 *)(param_1 + 8));
      dbm_ep_unconfig(puVar10,*(undefined1 *)(param_1 + 0xaa));
      iVar8 = 0;
      lVar9 = 0x540;
      do {
        piVar1 = (int *)((long)puVar10 + lVar9);
        lVar9 = lVar9 + 0x28;
        if (*piVar1 == 1) {
          iVar8 = iVar8 + 1;
        }
      } while (lVar9 != 0xa40);
      if (iVar8 == 0) {
        dbm_event_buffer_config(puVar10,0,0,0);
      }
    }
    if ((ulong)*(byte *)(param_1 + 0xaa) < 0x20) {
      puVar10[(ulong)*(byte *)(param_1 + 0xaa) * 5 + 0xa7] = 0;
      _raw_spin_unlock_irqrestore(lVar2,uVar7);
      return 0;
    }
  }
LAB_0010370c:
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x103710);
  (*pcVar5)();
}



//------------------------------------------------------------
// dbm_ep_unconfig @ 00103710 size=212
// signature: undefined dbm_ep_unconfig(void)
// callers: [msm_ep_unconfig, dwc3_msm_req_complete_func]
//------------------------------------------------------------

void dbm_ep_unconfig(undefined8 *param_1,byte param_2)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  ulong uVar4;
  int *piVar5;
  
  _dev_info(*param_1,"Unconfiguring DB ep\n");
  if (0x1f < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1037e4);
    (*pcVar2)();
  }
  uVar4 = (ulong)param_2;
  if (*(int *)(param_1 + uVar4 * 5 + 0xa8) == 1) {
    piVar5 = (int *)param_1[0x3b];
    bVar1 = *(byte *)(param_1 + uVar4 * 5 + 0xaa);
    *(undefined1 *)(param_1 + uVar4 * 5 + 0xaa) = 0;
    uVar3 = readl(param_1[1] + (ulong)(*piVar5 + piVar5[1] * (uint)bVar1 + 0xf8000));
    writel(uVar3 & 0xfffffffe,
           param_1[1] +
           (ulong)(*(int *)param_1[0x3b] + ((int *)param_1[0x3b])[1] * (uint)bVar1 + 0xf8000));
  }
  else {
    _dev_info(*param_1,"%s: No DBM EP matches USB EP %d\n","find_matching_dbm_ep",param_2);
  }
  return;
}



//------------------------------------------------------------
// dbm_event_buffer_config @ 001037e4 size=208
// signature: undefined dbm_event_buffer_config(void)
// callers: [dwc3_msm_ep_queue, msm_ep_unconfig, dwc3_msm_req_complete_func]
//------------------------------------------------------------

void dbm_event_buffer_config(undefined8 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  
  _dev_info(*param_1,"Configuring event buffer\n");
  iVar2 = readl(param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x28) + 0xf8000));
  if (iVar2 == 0) {
    writel(param_2,param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x78) + 0xf8000));
    writel(param_3,param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x80) + 0xf8000));
    lVar1 = param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x28) + 0xf8000);
    uVar3 = readl(lVar1);
    writel(uVar3 & 0xffff0000 | param_4,lVar1);
    readl(lVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_ep_clear_ops @ 001038b8 size=180
// signature: undefined msm_ep_clear_ops(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ep_clear_ops(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  undefined8 *puVar7;
  
  lVar1 = *(long *)(param_1 + 0x98) + 0x158;
  puVar7 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10396c);
    (*pcVar2)();
  }
  plVar5 = puVar7 + (ulong)*(byte *)(param_1 + 0xaa) + 7;
  lVar6 = *plVar5;
  if (lVar6 == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
    _dev_err(*puVar7,"ep [%s,%d] was not configured as msm endpoint\n",*(undefined8 *)(param_1 + 8),
             *(undefined1 *)(param_1 + 0xaa));
    uVar3 = 0xffffffea;
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x10);
    *(long *)(param_1 + 0x10) = lVar6;
    *plVar5 = 0;
    kfree(uVar4);
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_ep_update_ops @ 00103970 size=300
// signature: undefined msm_ep_update_ops(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_ep_update_ops(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  code *pcVar9;
  undefined8 uVar10;
  long *plVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  
  lVar1 = *(long *)(param_1 + 0x98) + 0x158;
  puVar13 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  uVar10 = _raw_spin_lock_irqsave(lVar1);
  if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x103a9c);
    (*pcVar9)();
  }
  plVar11 = puVar13 + (ulong)*(byte *)(param_1 + 0xaa) + 7;
  if (*plVar11 == 0) {
    *plVar11 = *(long *)(param_1 + 0x10);
    puVar13 = (undefined8 *)kmalloc_trace(_strnlen,0xb20,0x60);
    if (puVar13 == (undefined8 *)0x0) {
      _raw_spin_unlock_irqrestore(lVar1,uVar10);
      uVar10 = 0xfffffff4;
    }
    else {
      puVar12 = *(undefined8 **)(param_1 + 0x10);
      uVar2 = puVar12[4];
      uVar3 = puVar12[6];
      uVar6 = puVar12[7];
      puVar13[5] = puVar12[5];
      uVar4 = puVar12[2];
      uVar7 = puVar12[3];
      uVar5 = *puVar12;
      uVar8 = puVar12[1];
      puVar13[6] = uVar3;
      puVar13[7] = uVar6;
      puVar13[3] = uVar7;
      puVar13[4] = uVar2;
      *puVar13 = uVar5;
      puVar13[1] = uVar8;
      puVar13[2] = uVar4;
      uVar2 = puVar12[10];
      uVar4 = puVar12[0xb];
      uVar3 = puVar12[8];
      uVar5 = puVar12[9];
      puVar13[5] = dwc3_msm_ep_queue;
      *puVar13 = dwc3_msm_ep_enable;
      puVar13[10] = uVar2;
      puVar13[0xb] = uVar4;
      *(undefined8 **)(param_1 + 0x10) = puVar13;
      puVar13[8] = uVar3;
      puVar13[9] = uVar5;
      _raw_spin_unlock_irqrestore(lVar1,uVar10);
      uVar10 = 0;
    }
  }
  else {
    _raw_spin_unlock_irqrestore(lVar1,uVar10);
    _dev_err(*puVar13,"ep [%s,%d] already configured as msm endpoint\n",*(undefined8 *)(param_1 + 8)
             ,*(undefined1 *)(param_1 + 0xaa));
    uVar10 = 0xffffffff;
  }
  return uVar10;
}



//------------------------------------------------------------
// dwc3_msm_ep_queue @ 00103aa0 size=1552
// signature: undefined dwc3_msm_ep_queue(void)
// callers: []
//------------------------------------------------------------

int dwc3_msm_ep_queue(long param_1,long param_2,uint param_3)

{
  long lVar1;
  undefined *puVar2;
  char cVar3;
  byte bVar4;
  code *pcVar5;
  bool bVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  long *plVar15;
  ulong uVar16;
  undefined8 uVar17;
  char *pcVar18;
  long lVar19;
  int iVar20;
  long *plVar21;
  undefined8 *puVar22;
  long lVar23;
  long *plVar24;
  undefined8 *puVar25;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  lVar1 = *(long *)(param_1 + 0x98) + 0x158;
  puVar25 = *(undefined8 **)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  uVar14 = _raw_spin_lock_irqsave(lVar1);
  if (*(long *)(param_1 + 0x38) == 0) {
    uVar17 = *puVar25;
    pcVar18 = "%s: trying to queue request %pK to disabled ep %s\n";
    goto LAB_00103ed8;
  }
  bVar4 = *(byte *)(param_1 + 0xaa);
  if (0x1f < bVar4) goto LAB_001040a8;
  if (puVar25[(ulong)bVar4 + 7] == 0) {
    _dev_err(*puVar25,"ep [%s,%d] was unconfigured as msm endpoint\n",*(undefined8 *)(param_1 + 8));
  }
  else {
    if (param_2 == 0) {
      uVar17 = *puVar25;
      pcVar18 = "%s: request is NULL\n";
    }
    else {
      if ((*(int *)(puVar25 + (ulong)(uint)bVar4 * 5 + 0xa8) != 1) ||
         (*(uint *)(param_2 + 8) >> 0xd != 0)) {
        if (bVar4 < 2) {
          uVar17 = *puVar25;
          pcVar18 = "%s: trying to queue dbm request %pK to ep %s\n";
        }
        else {
          if (((*(char *)(param_1 + 0xa9) == *(char *)(param_1 + 0xa8)) &&
              (*(long **)(param_1 + 0x60) == (long *)(param_1 + 0x60))) &&
             (plVar21 = (long *)(param_1 + 0x70), (long *)*plVar21 == plVar21)) {
            *(undefined2 *)(param_1 + 0xa8) = 0;
            if ((param_3 & 0x400010) == 0) {
              lVar19 = 0;
            }
            else {
              lVar19 = 1;
              if ((param_3 & 0x10) != 0) {
                lVar19 = 2;
              }
            }
            plVar15 = (long *)kmalloc_trace(*(undefined8 *)(strcmp + lVar19 * 0x70),param_3 | 0x100,
                                            0x20);
            if (plVar15 == (long *)0x0) {
              _raw_spin_unlock_irqrestore(lVar1,uVar14);
              iVar8 = -0xc;
              goto LAB_00103fb4;
            }
            lVar19 = *(long *)(param_2 + 0x30);
            plVar15[2] = param_2;
            plVar15[3] = lVar19;
            puVar22 = (undefined8 *)puVar25[0x28];
            uVar16 = __list_add_valid(plVar15,puVar22,puVar25 + 0x27);
            if ((uVar16 & 1) != 0) {
              puVar25[0x28] = plVar15;
              *plVar15 = (long)(puVar25 + 0x27);
              plVar15[1] = (long)puVar22;
              *puVar22 = plVar15;
            }
            *(code **)(param_2 + 0x30) = dwc3_msm_req_complete_func;
            if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) goto LAB_001040a8;
            if (*(int *)(puVar25 + (ulong)*(byte *)(param_1 + 0xaa) * 5 + 0xa8) == 3) {
              lVar19 = param_2 + 0x68;
              *(undefined4 *)(param_2 + 0x9c) = 1;
              plVar24 = *(long **)(param_1 + 0x78);
              uVar16 = __list_add_valid(lVar19,plVar24,plVar21);
              if ((uVar16 & 1) != 0) {
                *(long *)(param_1 + 0x78) = lVar19;
                *(long **)(param_2 + 0x68) = plVar21;
                *(long **)(param_2 + 0x70) = plVar24;
                *plVar24 = lVar19;
              }
              local_78 = 0;
              uStack_74 = (*(byte *)(param_1 + 0xcc) & 1) << 9 ^ 0x200;
              local_70 = 0x8000;
              iVar8 = dwc3_core_send_gadget_ep_cmd(param_1,6,&local_78);
              if (iVar8 < 0) {
                _dev_info(*(undefined8 *)(*(long *)(param_1 + 0x98) + 400),
                          "%s: failed to send STARTTRANSFER command\n","__dwc3_msm_ebc_ep_queue");
                goto LAB_00104010;
              }
            }
            else {
              lVar19 = param_2 + 0x68;
              local_70 = 0;
              local_78 = 0;
              uStack_74 = 0;
              lVar23 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98
                                );
              *(undefined4 *)(param_2 + 0x9c) = 1;
              plVar24 = *(long **)(param_1 + 0x78);
              uVar16 = __list_add_valid(lVar19,plVar24,plVar21);
              if ((uVar16 & 1) != 0) {
                *(long *)(param_1 + 0x78) = lVar19;
                *(long **)(param_2 + 0x68) = plVar21;
                *(long **)(param_2 + 0x70) = plVar24;
                *plVar24 = lVar19;
              }
              uVar7 = readl(*(long *)(lVar23 + 8) + 0xc408);
              uVar9 = readl(*(long *)(lVar23 + 8) + 0xc400);
              uVar10 = readl(*(long *)(lVar23 + 8) + 0xc404);
              dbm_event_buffer_config(lVar23,uVar9,uVar10,uVar7);
              bVar4 = *(byte *)(param_1 + 0xa8);
              local_78 = 0;
              cVar3 = '\0';
              if (bVar4 != 0xfe) {
                cVar3 = bVar4 + 1;
              }
              puVar22 = (undefined8 *)(*(long *)(param_1 + 0x88) + (ulong)bVar4 * 0x10);
              *(char *)(param_1 + 0xa8) = cVar3;
              *puVar22 = 0;
              puVar22[1] = 0;
              *(undefined8 **)(param_2 + 0xa8) = puVar22;
              *(int *)(param_2 + 0xb8) = *(int *)(param_2 + 0xb8) + 1;
              *(uint *)((long)puVar22 + 4) = (uint)*(byte *)(param_1 + 0xaa) << 0x18 | 0xa0000000;
              *(uint *)(puVar22 + 1) = *(uint *)(param_2 + 8) & 0xffffff;
              *(uint *)((long)puVar22 + 0xc) = (*(byte *)(param_2 + 0xbc) & 2) << 2 ^ 0x1d;
              *(ulong *)(param_2 + 0xb0) =
                   (ulong)(uint)((int)puVar22 - *(int *)(param_1 + 0x88)) +
                   *(long *)(param_1 + 0x90);
              bVar4 = *(byte *)(param_1 + 0xa8);
              cVar3 = '\0';
              if (bVar4 != 0xfe) {
                cVar3 = bVar4 + 1;
              }
              puVar22 = (undefined8 *)(*(long *)(param_1 + 0x88) + (ulong)bVar4 * 0x10);
              *(char *)(param_1 + 0xa8) = cVar3;
              *puVar22 = 0;
              puVar22[1] = 0;
              *(int *)puVar22 = (int)*(undefined8 *)(param_2 + 0xb0);
              uVar11 = *(uint *)(param_2 + 0xb4);
              bVar4 = *(byte *)(param_1 + 0xaa);
              puVar22[1] = 0x8100000000;
              *(uint *)((long)puVar22 + 4) = uVar11 | (uint)bVar4 << 0x18 | 0xa0000000;
              uStack_74 = (uint)*(undefined8 *)(param_2 + 0xb0);
              local_70 = (undefined4)((ulong)*(undefined8 *)(param_2 + 0xb0) >> 0x20);
              iVar8 = dwc3_core_send_gadget_ep_cmd(param_1,0x106,&local_78);
              if (iVar8 < 0) {
                _dev_info(*(undefined8 *)(*(long *)(param_1 + 0x98) + 400),
                          "%s: failed to send STARTTRANSFER command\n","__dwc3_msm_dbm_ep_queue");
LAB_00104010:
                uVar16 = __list_del_entry_valid(param_2 + 0x68);
                if ((uVar16 & 1) != 0) {
                  lVar19 = *(long *)(param_2 + 0x68);
                  plVar21 = *(long **)(param_2 + 0x70);
                  *(long **)(lVar19 + 8) = plVar21;
                  *plVar21 = lVar19;
                }
                *(undefined8 *)(param_2 + 0x68) = 0xdead000000000100;
                *(undefined8 *)(param_2 + 0x70) = 0xdead000000000122;
              }
              else {
                if (*(char *)(lVar23 + 0x308) == '\0') {
                  uVar11 = readl(*(long *)(lVar23 + 8) + 0xc70c);
                  bVar6 = (uVar11 & 6) == 4;
                }
                else {
                  uVar11 = readl(*(long *)(lVar23 + 8) + 4);
                  uVar11 = uVar11 >> 0x18 & 0x7f;
                  if (uVar11 == 0) {
                    bVar6 = false;
                  }
                  else {
                    uVar12 = readl(*(long *)(lVar23 + 8) + (ulong)(*(int *)(lVar23 + 0xb40) + 0x400)
                                  );
                    if (((uVar12 >> 1 & 1) == 0) || ((uVar12 & 0x3000) == 0)) {
                      uVar12 = 0;
                      iVar20 = 0x410;
                      do {
                        if (uVar11 - 1 == uVar12) {
                          uVar12 = uVar11;
                          break;
                        }
                        uVar13 = readl(*(long *)(lVar23 + 8) +
                                       (ulong)(uint)(iVar20 + *(int *)(lVar23 + 0xb40)));
                        iVar20 = iVar20 + 0x10;
                        uVar12 = uVar12 + 1;
                      } while (((uVar13 >> 1 & 1) == 0) || ((uVar13 & 0x3000) == 0));
                      bVar6 = uVar12 < uVar11;
                    }
                    else {
                      bVar6 = true;
                    }
                  }
                }
                writel(bVar6,*(long *)(lVar23 + 8) +
                             (ulong)(*(int *)(*(long *)(lVar23 + 0x1d8) + 0x70) + 0xf8000));
              }
            }
            if (iVar8 < 0) {
              if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
LAB_001040a8:
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1040ac);
                (*pcVar5)();
              }
              puVar2 = &DAT_00111f97;
              if (*(int *)(puVar25 + (ulong)*(byte *)(param_1 + 0xaa) * 5 + 0xa8) != 3) {
                puVar2 = &DAT_0011392e;
              }
              _dev_err(*puVar25,"error %d after queuing %s req\n",iVar8,puVar2);
              _raw_spin_unlock_irqrestore(lVar1,uVar14);
              kfree(plVar15);
            }
            else {
              _raw_spin_unlock_irqrestore(lVar1,uVar14);
              iVar8 = 0;
            }
            goto LAB_00103fb4;
          }
          uVar17 = *puVar25;
          pcVar18 = "%s: trying to queue dbm request %pK tp ep %s\n";
        }
LAB_00103ed8:
        _dev_err(uVar17,pcVar18,"dwc3_msm_ep_queue",param_2,*(undefined8 *)(param_1 + 8));
        _raw_spin_unlock_irqrestore(lVar1,uVar14);
        iVar8 = -1;
        goto LAB_00103fb4;
      }
      uVar17 = *puVar25;
      pcVar18 = "%s: Min TRB size is 8KB\n";
    }
    _dev_err(uVar17,pcVar18,"dwc3_msm_ep_queue");
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar14);
  iVar8 = -0x16;
LAB_00103fb4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// dwc3_msm_ep_enable @ 001040b4 size=620
// signature: undefined dwc3_msm_ep_enable(void)
// callers: []
//------------------------------------------------------------

int dwc3_msm_ep_enable(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  if (((param_1 == 0) || (param_2 == 0)) || (*(char *)(param_2 + 1) != '\x05')) {
    puVar5 = &DAT_0011377e;
LAB_00104278:
    _printk(puVar5);
  }
  else {
    if (*(short *)(param_2 + 4) == 0) {
      puVar5 = &DAT_001107ec;
      goto LAB_00104278;
    }
    lVar6 = *(long *)(param_1 + 0x98);
    lVar7 = *(long *)(*(long *)(*(long *)(lVar6 + 400) + 0x60) + 0x98);
    if (((*(uint *)(param_1 + 0xa4) & 1) != 0) && ((dwc3_msm_ep_enable___already_done & 1) == 0)) {
      dwc3_msm_ep_enable___already_done = 1;
      uVar4 = dev_driver_string();
      lVar7 = (*(long **)(lVar6 + 400))[0xe];
      if (lVar7 == 0) {
        lVar7 = **(long **)(lVar6 + 400);
      }
      __warn_printk("%s %s: %s is already enabled\n",uVar4,lVar7,param_1 + 0xb8);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10431c);
      (*pcVar1)();
    }
    if ((*(uint *)(param_1 + 0xa4) & 1) != 0) {
      iVar2 = 0;
      goto LAB_00104280;
    }
    if ((*(int *)(*(long *)(lVar6 + 0x198) + 0x20c) != 2) ||
       ((*(ushort *)(*(long *)(lVar6 + 0x198) + 0x200) & 7) != 0)) {
      uVar4 = _raw_spin_lock_irqsave(lVar6 + 0x158);
      lVar10 = *(long *)(param_1 + 0x98);
      lVar9 = *(long *)(param_1 + 0x38);
      local_60 = 0;
      local_68 = 0;
      lVar8 = *(long *)(*(long *)(*(long *)(lVar10 + 400) + 0x60) + 0x98);
      dwc3_msm_depcfg_params(param_1,&local_68);
      iVar2 = dwc3_core_send_gadget_ep_cmd(param_1,1,&local_68);
      if (iVar2 == 0) {
        if ((*(byte *)(param_1 + 0xa4) & 1) == 0) {
          dwc3_core_resize_tx_fifos(param_1);
          *(byte *)(param_1 + 0xab) = *(byte *)(lVar9 + 3) & 3;
          *(uint *)(param_1 + 0xa4) = *(uint *)(param_1 + 0xa4) | 1;
          uVar3 = readl(*(long *)(lVar8 + 8) + 0xc720);
          writel(uVar3 | (uint)(1L << ((ulong)*(byte *)(param_1 + 0xaa) & 0x3f)),
                 *(long *)(lVar8 + 8) + 0xc720);
          *(undefined2 *)(param_1 + 0xa8) = 0;
          memset(*(void **)(param_1 + 0x88),0,0x1000);
          lVar8 = *(long *)(param_1 + 0x88);
          *(int *)(lVar8 + 0xff0) = (int)*(undefined8 *)(param_1 + 0x90);
          *(int *)(lVar8 + 0xff4) =
               (int)((ulong)(uint)((int)lVar8 - *(int *)(param_1 + 0x88)) +
                     *(long *)(param_1 + 0x90) >> 0x20);
          *(uint *)(lVar8 + 0xffc) = *(uint *)(lVar8 + 0xffc) | 0x81;
        }
      }
      else {
        _dev_err(*(undefined8 *)(lVar10 + 400),"set_ep_config() failed for %s\n",param_1 + 0xb8);
      }
      dwc3_dbg_print(*(undefined8 *)(lVar7 + 0x528),*(undefined1 *)(param_1 + 0xaa),"ENABLE",iVar2,
                     &DAT_00111364);
      _raw_spin_unlock_irqrestore(lVar6 + 0x158,uVar4);
      goto LAB_00104280;
    }
    _dev_err(*(long *)(lVar6 + 400),"fail ep_enable %s device is into LPM\n",param_1 + 0xb8);
  }
  iVar2 = -0x16;
LAB_00104280:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_ep_set_mode @ 00104328 size=96
// signature: undefined msm_ep_set_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ep_set_mode(long param_1,int param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  if (param_2 == 0) {
    if (0x20 < (ulong)*(byte *)(param_1 + 0xaa)) goto LAB_00104384;
    lVar3 = lVar2 + (ulong)*(byte *)(param_1 + 0xaa) * 0x28;
    *(undefined8 *)(lVar3 + 0x558) = 0;
    *(undefined8 *)(lVar3 + 0x550) = 0;
    *(undefined8 *)(lVar3 + 0x548) = 0;
    *(undefined8 *)(lVar3 + 0x540) = 0;
    *(undefined8 *)(lVar3 + 0x538) = 0;
  }
  if ((ulong)*(byte *)(param_1 + 0xaa) < 0x20) {
    *(int *)(lVar2 + (ulong)*(byte *)(param_1 + 0xaa) * 0x28 + 0x540) = param_2;
    return 0;
  }
LAB_00104384:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104388);
  (*pcVar1)();
}



//------------------------------------------------------------
// dwc3_msm_notify_event @ 0010438c size=2776
// signature: undefined dwc3_msm_notify_event(void)
// callers: [entry___dwc3_gadget_ep_enable, dwc3_otg_start_peripheral, entry_dwc3_gadget_pullup, dwc3_msm_remove, entry_dwc3_send_gadget_ep_cmd, entry_dwc3_gadget_reset_interrupt, exit_dwc3_gadget_pullup, entry___dwc3_gadget_start, entry_dwc3_gadget_run_stop, dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dwc3_msm_notify_event(long param_1,undefined4 param_2,uint param_3)

{
  ulong *puVar1;
  char *pcVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  char *pcVar13;
  undefined8 *puVar14;
  char *__string;
  long lVar15;
  long *plVar16;
  undefined8 *puVar17;
  ulong uVar18;
  long *plVar19;
  uint local_e8 [36];
  long local_58;
  
  lVar11 = diag_dload;
  lVar15 = sp_el0;
  local_58 = *(long *)(lVar15 + 0x638);
  __string = *(char **)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
  switch(param_2) {
  case 0:
    _dev_info(*(undefined8 *)__string,"DWC3_CONTROLLER_ERROR_EVENT received\n");
    writel(0,*(long *)(__string + 8) + 0xc708);
    uVar8 = readl(*(long *)(__string + 8) + 0xc110);
    writel(uVar8 | 0x800,*(long *)(__string + 8) + 0xc110);
    if (2 < *(int *)(__string + 0x524)) break;
    pcVar13 = __string + 600;
    uVar12 = _system_wq;
    goto LAB_00104d6c;
  default:
    _dev_info(*(undefined8 *)__string,"unknown dwc3 event\n");
    break;
  case 5:
    _dev_info(*(undefined8 *)__string,"DWC3_CONTROLLER_CONNDONE_EVENT received\n");
    if ((*(byte *)(param_1 + 0x48a) & 0xfe) != 4) {
      uVar8 = readl(*(long *)(__string + 8) + 0xc2c0);
      writel(uVar8 | 0x20000,*(long *)(__string + 8) + 0xc2c0);
    }
    if ((*(byte *)(*(long *)(__string + 0x1c0) + 0x10) & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x104dd8);
      (*pcVar6)();
    }
    if ((__string[0xa41] != '\0') && (4 < *(uint *)(*(long *)(param_1 + 0x370) + 0x58))) {
      if ((*(long *)(__string + 0x1c0) != 0) &&
         (pcVar6 = *(code **)(*(long *)(__string + 0x1c0) + 0x148), pcVar6 != (code *)0x0)) {
        if (*(int *)(pcVar6 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x104800);
          (*pcVar6)();
        }
        (*pcVar6)();
      }
      if (*(int *)(__string + 0xb2c) == 1) {
        __const_udelay(0x14f8c);
        mdwc3_usb2_phy_soft_reset(__string);
      }
    }
    if ((__string[0x1e4] == '\0') && (*(long *)(__string + 800) != 0)) {
      dwc3_msm_write_reg_field(*(undefined8 *)(__string + 8),0xf885c,0x2000,1);
    }
    _dev_info(*(undefined8 *)__string,"%s: set in_lpm=0\n","dwc3_msm_notify_event");
    __string[0x370] = '\0';
    __string[0x371] = '\0';
    __string[0x372] = '\0';
    __string[0x373] = '\0';
    lVar15 = *(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if (*(char *)(lVar15 + 0xa53) == '\0') {
      *(byte *)(lVar15 + 0xa42) = (byte)((uint)*(undefined4 *)(param_1 + 0x4e8) >> 0x1e) & 1;
      *(byte *)(lVar15 + 0xa43) = (byte)((uint)*(undefined4 *)(param_1 + 0x4e8) >> 0x1f);
      *(undefined1 *)(lVar15 + 0xa53) = 1;
      ipc_log_string(*(undefined8 *)(lVar15 + 0x528),
                     "%s: cached_dt_param: u1_disable:%d u2_disable:%d\n","mdwc3_update_u1u2_value")
      ;
    }
    if (*(char *)(param_1 + 0x48a) == '\x04') {
      uVar10 = (ulong)*(uint6 *)(param_1 + 0x4e8) & 0xffffffffbfffffff |
               (ulong)*(byte *)(lVar15 + 0xa42) << 0x1e;
      *(int *)(param_1 + 0x4e8) = (int)uVar10;
      *(short *)(param_1 + 0x4ec) = (short)(uVar10 >> 0x20);
      uVar10 = uVar10 & 0xffffffff7fffffff | (ulong)*(byte *)(lVar15 + 0xa43) << 0x1f;
      *(int *)(param_1 + 0x4e8) = (int)uVar10;
      *(short *)(param_1 + 0x4ec) = (short)(uVar10 >> 0x20);
    }
    else {
      uVar10 = (ulong)*(uint6 *)(param_1 + 0x4e8) | 0xc0000000;
      *(int *)(param_1 + 0x4e8) = (int)uVar10;
    }
    pcVar13 = "enabled";
    if ((uVar10 & 0x40000000) != 0) {
      pcVar13 = "disabled";
    }
    pcVar2 = "enabled";
    if ((int)uVar10 < 0) {
      pcVar2 = "disabled";
    }
    ipc_log_string(*(undefined8 *)(lVar15 + 0x528),"%s: speed:%d u1:%s u2:%s\n",
                   "mdwc3_update_u1u2_value",*(char *)(param_1 + 0x48a),pcVar13,pcVar2);
LAB_00104e64:
    puVar1 = (ulong *)(__string + 0x2d0);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 | 0x10;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    pcVar13 = __string + 0x2a0;
    uVar12 = *(undefined8 *)(__string + 0x298);
LAB_00104d6c:
    queue_work_on(0x20,uVar12,pcVar13);
    break;
  case 7:
    if ((param_3 & 0xe0) != 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x104e4c);
      (*pcVar6)();
    }
    if (*(int *)(__string + (ulong)(param_3 & 0xff) * 0x28 + 0x540) == 1) {
      bVar3 = __string[(ulong)(param_3 & 0xff) * 0x28 + 0x550];
      uVar8 = readl(*(long *)(__string + 8) +
                    (ulong)(*(int *)(*(long *)(__string + 0x1d8) + 0x60) + 0xf8000));
      writel(uVar8 | 1 << (ulong)(bVar3 & 0x1f),
             *(long *)(__string + 8) +
             (ulong)(*(int *)(*(long *)(__string + 0x1d8) + 0x60) + 0xf8000));
    }
    else {
      _dev_info(*(undefined8 *)__string,"%s: No DBM EP matches USB EP %d\n","find_matching_dbm_ep");
    }
    break;
  case 8:
    _dev_info(*(undefined8 *)__string,"DWC3_CONTROLLER_PULLUP_ENTER %d\n",param_3);
    if (__string[0x312] != '\0') {
      usb_redriver_gadget_pullup_enter(*(undefined8 *)(__string + 0x1d0),param_3);
    }
    break;
  case 9:
    _dev_info(*(undefined8 *)__string,"DWC3_CONTROLLER_PULLUP_EXIT %d\n",param_3);
    if (__string[0x312] != '\0') {
      usb_redriver_gadget_pullup_exit(*(undefined8 *)(__string + 0x1d0),param_3);
    }
    break;
  case 10:
    _dev_info(*(undefined8 *)__string,"DWC3_GSI_EVT_BUF_ALLOC\n");
    lVar15 = *(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if (*(uint *)(lVar15 + 0x388) != 0) {
      lVar11 = devm_kmalloc(*(long *)(param_1 + 400),(ulong)*(uint *)(lVar15 + 0x388) * 0x38,0xdc0);
      *(long *)(lVar15 + 0x390) = lVar11;
      if (lVar11 == 0) {
        _dev_err(*(undefined8 *)(param_1 + 400),"can\'t allocate gsi_ev_buff\n");
      }
      else {
        if (*(int *)(lVar15 + 0x388) != 0) {
          uVar8 = 0;
          do {
            plVar19 = (long *)devm_kmalloc(*(undefined8 *)(param_1 + 400),0x38,0xdc0);
            if (plVar19 == (long *)0x0) goto LAB_00104d74;
            uVar12 = *(undefined8 *)(param_1 + 0x198);
            plVar19[5] = param_1;
            *(undefined4 *)(plVar19 + 2) = 0x1000;
            lVar11 = dma_alloc_attrs(uVar12,0x1000,plVar19 + 4,0xcc0,0);
            *plVar19 = lVar11;
            if (lVar11 == 0) {
              _dev_err(*(undefined8 *)(param_1 + 400),"can\'t allocate gsi_evt_buf(%d)\n",uVar8);
              goto LAB_00104d74;
            }
            *(long **)(*(long *)(lVar15 + 0x390) + (long)(int)uVar8 * 8) = plVar19;
            uVar8 = uVar8 + 1;
          } while (uVar8 < *(uint *)(lVar15 + 0x388));
        }
        uVar10 = lVar15 + 0x4f8;
        plVar19 = *(long **)(param_1 + 0x198);
        uVar18 = is_vmalloc_addr(uVar10);
        if (((uVar18 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar12 = dev_driver_string(plVar19);
          lVar15 = plVar19[0xe];
          if (lVar15 == 0) {
            lVar15 = *plVar19;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar12,lVar15);
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x104e1c);
          (*pcVar6)();
        }
        if ((uVar18 & 1) == 0) {
          lVar11 = dma_map_page_attrs(plVar19,(((long)(uVar10 * 0x100) >> 8) + 0x8000000000U >> 0xc)
                                              * 0x40 + -0x200000000,uVar10 & 0xfff,8,2,0);
          *(long *)(lVar15 + 0x500) = lVar11;
          if (lVar11 != -1) break;
        }
        else {
          *(undefined8 *)(lVar15 + 0x500) = 0xffffffffffffffff;
        }
        _dev_err(*(undefined8 *)(param_1 + 400),"failed to map dummy doorbell buffer\n");
        *(undefined8 *)(lVar15 + 0x500) = 0;
      }
    }
    break;
  case 0xb:
    _dev_info(*(undefined8 *)__string,"DWC3_GSI_EVT_BUF_SETUP\n");
    puVar14 = *(undefined8 **)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if ((puVar14[0x72] != 0) && (*(int *)(puVar14 + 0x71) != 0)) {
      uVar8 = 0;
      iVar7 = 0x10000;
      uVar9 = 0xc41c;
      do {
        puVar17 = *(undefined8 **)(puVar14[0x72] + (long)(int)uVar8 * 8);
        if (puVar17 == (undefined8 *)0x0) break;
        _dev_info(*puVar14,"Evt buf %pK dma %08llx length %d\n",*puVar17,puVar17[4],
                  *(undefined4 *)(puVar17 + 2));
        memset((void *)*puVar17,0,(ulong)*(uint *)(puVar17 + 2));
        *(undefined4 *)((long)puVar17 + 0x14) = 0;
        uVar8 = uVar8 + 1;
        writel(*(undefined4 *)(puVar17 + 4),puVar14[1] + (ulong)(uVar9 - 0xc));
        writel(iVar7 + (uint)*(ushort *)((long)puVar17 + 0x24) | 0xc00000,
               puVar14[1] + (ulong)(uVar9 - 8));
        writel(*(ushort *)(puVar17 + 2) | 0x80000000,puVar14[1] + (ulong)(uVar9 - 4));
        writel(0,puVar14[1] + (ulong)uVar9);
        iVar7 = iVar7 + 0x10000;
        uVar9 = uVar9 + 0x10;
      } while (uVar8 < *(uint *)(puVar14 + 0x71));
    }
    break;
  case 0xc:
    _dev_info(*(undefined8 *)__string,"DWC3_GSI_EVT_BUF_CLEANUP\n");
    lVar15 = *(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if ((*(long *)(lVar15 + 0x390) != 0) && (*(int *)(lVar15 + 0x388) != 0)) {
      uVar8 = 0;
      uVar9 = 0xc41c;
      do {
        lVar11 = (long)(int)uVar8;
        uVar8 = uVar8 + 1;
        *(undefined4 *)(*(long *)(*(long *)(lVar15 + 0x390) + lVar11 * 8) + 0x14) = 0;
        writel(0,*(long *)(lVar15 + 8) + (ulong)(uVar9 - 0xc));
        writel(0,*(long *)(lVar15 + 8) + (ulong)(uVar9 - 8));
        writel(uVar8 & 0xffff | 0x80000000,*(long *)(lVar15 + 8) + (ulong)(uVar9 - 4));
        writel(0,*(long *)(lVar15 + 8) + (ulong)uVar9);
        uVar9 = uVar9 + 0x10;
      } while (uVar8 < *(uint *)(lVar15 + 0x388));
    }
    break;
  case 0xd:
    _dev_info(*(undefined8 *)__string,"DWC3_GSI_EVT_BUF_CLEAR\n");
    uVar9 = readl(*(long *)(__string + 8) + 0xc200);
    uVar8 = uVar9;
    if ((uVar9 & 0x40) != 0) {
      uVar8 = uVar9 & 0xffffffbf;
    }
    if ((uVar8 & 0x100) != 0 || (uVar9 & 0x40) != 0) {
      writel(uVar8 & 0xfffffeff,*(long *)(__string + 8) + 0xc200);
    }
    lVar15 = *(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if (*(int *)(lVar15 + 0x388) != 0) {
      uVar10 = 0;
      uVar18 = 0xc41c;
      do {
        uVar10 = uVar10 + 1;
        uVar8 = readl(*(long *)(lVar15 + 8) + (uVar18 & 0xfffffffc));
        writel(uVar8 & 0xfffc,*(long *)(lVar15 + 8) + (uVar18 & 0xfffffffc));
        ipc_log_string(*(undefined8 *)(lVar15 + 0x528),"%s: remaining EVNTCOUNT(%d)=%d",
                       "handle_gsi_buffer_clear_event",uVar10 & 0xffffffff,uVar8 & 0xfffc);
        uVar18 = uVar18 + 0x10;
      } while (uVar10 < *(uint *)(lVar15 + 0x388));
    }
    break;
  case 0xe:
    _dev_info(*(undefined8 *)__string,"DWC3_GSI_EVT_BUF_FREE\n");
    lVar15 = *(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if (*(long *)(lVar15 + 0x390) != 0) {
      uVar8 = *(uint *)(lVar15 + 0x388);
      if (uVar8 != 0) {
        uVar9 = 0;
        do {
          puVar14 = *(undefined8 **)(*(long *)(lVar15 + 0x390) + (long)(int)uVar9 * 8);
          if (puVar14 != (undefined8 *)0x0) {
            dma_free_attrs(*(undefined8 *)(param_1 + 0x198),*(undefined4 *)(puVar14 + 2),*puVar14,
                           puVar14[4],0);
            uVar8 = *(uint *)(lVar15 + 0x388);
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < uVar8);
      }
      if (*(long *)(lVar15 + 0x500) != 0) {
        dma_unmap_page_attrs(*(undefined8 *)(param_1 + 0x198),*(long *)(lVar15 + 0x500),8,2,0);
        *(undefined8 *)(lVar15 + 0x500) = 0;
      }
    }
    break;
  case 0xf:
    _dev_info(*(undefined8 *)__string,"DWC3_CONTROLLER_NOTIFY_CLEAR_DB\n");
    uVar8 = readl(*(long *)(__string + 8) + 0xc2c0);
    writel(uVar8 & 0xfffdffff,*(long *)(__string + 8) + 0xc2c0);
    __const_udelay(0x418958);
    lVar15 = *(long *)(*(long *)(*(long *)(param_1 + 400) + 0x60) + 0x98);
    if (*(int **)(lVar15 + 0x4c8) != (int *)0x0) {
      lVar11 = *(long *)(lVar15 + 8) + (ulong)(**(int **)(lVar15 + 0x4c8) + 0xf8800);
      uVar8 = readl(lVar11);
      writel(uVar8 | 2,lVar11);
      readl(lVar11);
      lVar15 = *(long *)(lVar15 + 8) + (ulong)(**(int **)(lVar15 + 0x4c8) + 0xf8800);
      uVar8 = readl(lVar15);
      writel(uVar8 & 0xfffffffe,lVar15);
      readl(lVar15);
    }
    break;
  case 0x10:
    local_e8[0x1f] = 0;
    local_e8[0x20] = 0;
    local_e8[0x1d] = 0;
    local_e8[0x1e] = 0;
    local_e8[0x1b] = 0;
    local_e8[0x1c] = 0;
    local_e8[0x19] = 0;
    local_e8[0x1a] = 0;
    local_e8[0x17] = 0;
    local_e8[0x18] = 0;
    local_e8[0x15] = 0;
    local_e8[0x16] = 0;
    local_e8[0x13] = 0;
    local_e8[0x14] = 0;
    local_e8[0x11] = 0;
    local_e8[0x12] = 0;
    local_e8[0xf] = 0;
    local_e8[0x10] = 0;
    local_e8[0xd] = 0;
    local_e8[0xe] = 0;
    local_e8[0xb] = 0;
    local_e8[0xc] = 0;
    local_e8[9] = 0;
    local_e8[10] = 0;
    local_e8[7] = 0;
    local_e8[8] = 0;
    local_e8[5] = 0;
    local_e8[6] = 0;
    local_e8[3] = 0;
    local_e8[4] = 0;
    local_e8[1] = 0;
    local_e8[2] = 0;
    if ((diag_dload == 0) || (*(long *)(param_1 + 0x370) == 0)) {
      _printk(&DAT_00111dcf,"dwc3_msm_update_imem_pid");
    }
    else {
      lVar15 = **(long **)(*(long *)(param_1 + 0x370) + 0x40);
      if (*(short *)(lVar15 + 0x41) == 0x5c6) {
        plVar19 = (long *)(lVar15 + 0x50);
        do {
          plVar19 = (long *)*plVar19;
          if (plVar19 == (long *)(lVar15 + 0x50)) goto LAB_00104d74;
          iVar7 = strcmp((char *)**(undefined8 **)(plVar19[5] + 200),"ffs.diag");
        } while (iVar7 != 0);
        local_e8[0] = (uint)*(ushort *)(lVar15 + 0x43);
        local_e8[0x21] = 0x71432909;
        local_e8[0x22] = 0x61945374;
        plVar19 = (long *)(lVar15 + 0x60);
        plVar16 = (long *)*plVar19;
        if (plVar16 != plVar19) {
          do {
            pcVar13 = *(char **)(plVar16[2] + 8);
            while( true ) {
              if ((pcVar13 == (char *)0x0) ||
                 (__string = *(char **)(pcVar13 + 8), __string == (char *)0x0)) goto LAB_00104530;
              if (*pcVar13 == *(char *)(lVar15 + 0x49)) break;
              pcVar13 = pcVar13 + 0x10;
            }
            uVar10 = strnlen(__string,0x80);
            if (uVar10 == 0xffffffffffffffff) {
LAB_00104e58:
              fortify_panic("strnlen");
              goto LAB_00104e64;
            }
            if (uVar10 != 0x80) {
              uVar10 = uVar10 + 1;
            }
            if (0x80 < uVar10) {
              fortify_panic("strscpy");
              goto LAB_00104e58;
            }
            strscpy((ulong)local_e8 | 4,__string);
LAB_00104530:
            plVar16 = (long *)*plVar16;
          } while (plVar16 != plVar19);
          lVar11 = diag_dload;
        }
        __memcpy_toio(lVar11,local_e8,0x8c);
      }
    }
  }
LAB_00104d74:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mdwc3_usb2_phy_soft_reset @ 00104e80 size=108
// signature: undefined mdwc3_usb2_phy_soft_reset(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

void mdwc3_usb2_phy_soft_reset(long param_1)

{
  uint uVar1;
  
  uVar1 = readl(*(long *)(param_1 + 8) + 0xc200);
  writel(uVar1 | 0x80000000,*(long *)(param_1 + 8) + 0xc200);
  __const_udelay(0x14f8c);
  uVar1 = readl(*(long *)(param_1 + 8) + 0xc200);
  writel(uVar1 & 0x7fffffff,*(long *)(param_1 + 8) + 0xc200);
  return;
}



//------------------------------------------------------------
// dwc3_msm_write_reg_field @ 00104eec size=100
// signature: undefined dwc3_msm_write_reg_field(void)
// callers: [dwc3_otg_start_peripheral, dwc3_msm_notify_event, dwc3_otg_start_host]
//------------------------------------------------------------

void dwc3_msm_write_reg_field(long param_1,ulong param_2,uint param_3,int param_4)

{
  ulong uVar1;
  uint uVar2;
  
  param_1 = param_1 + (param_2 & 0xffffffff);
  uVar1 = ((ulong)param_3 & 0xaaaaaaaaaaaaaaaa) >> 1 | ((ulong)param_3 & 0x5555555555555555) << 1;
  uVar1 = (uVar1 & 0xcccccccccccccccc) >> 2 | (uVar1 & 0x3333333333333333) << 2;
  uVar1 = (uVar1 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar1 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar1 = (uVar1 & 0xff00ff00ff00ff00) >> 8 | (uVar1 & 0xff00ff00ff00ff) << 8;
  uVar2 = readl(param_1);
  writel(uVar2 & (param_3 ^ 0xffffffff) |
         param_4 <<
         (ulong)((uint)LZCOUNT((uVar1 >> 0x10 | (uVar1 & 0xffff0000ffff) << 0x10) << 0x20) & 0x1f),
         param_1);
  readl(param_1);
  return;
}



//------------------------------------------------------------
// dwc3_msm_set_dp_mode @ 00104f54 size=1104
// signature: undefined dwc3_msm_set_dp_mode(void)
// callers: []
//------------------------------------------------------------

int dwc3_msm_set_dp_mode(long param_1,uint param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  if ((puVar3 == (undefined8 *)0x0) || (puVar3[5] == 0)) {
    _dev_err(param_1,"dwc3-msm is not initialized yet.\n");
    return -0xb;
  }
  uVar2 = param_2 & 1;
  uVar4 = param_3 & 0xffffffff;
  _dev_info(param_1,"lanes %d, connect %d\n",param_3,uVar2);
  flush_work(puVar3 + 0x45);
  __flush_workqueue(puVar3[0x53]);
  _dev_info(param_1,"DP: cur_state:%d new_state:%d lanes:%d\n",*(undefined4 *)(puVar3 + 0x149),uVar2
            ,uVar4);
  ipc_log_string(puVar3[0xa5],"%s: DP: cur_state:%d new_state:%d lanes:%d\n","dwc3_msm_set_dp_mode",
                 *(undefined4 *)(puVar3 + 0x149),uVar2,uVar4);
  if ((param_2 & 1) == 0) {
    _dev_info(param_1,"DP not connected, refcnt:%d\n",*(undefined4 *)((long)puVar3 + 0xa44));
    ipc_log_string(puVar3[0xa5],"%s: DP not connected, refcnt:%d\n","dwc3_msm_set_dp_mode",
                   *(undefined4 *)((long)puVar3 + 0xa44));
    mutex_lock(puVar3 + 0x92);
    *(undefined1 *)(puVar3 + 0xa3) = 0;
    *(undefined4 *)(puVar3 + 0x149) = 0;
    iVar1 = *(int *)((long)puVar3 + 0xa44) + -1;
    *(int *)((long)puVar3 + 0xa44) = iVar1;
    if (*(int *)(puVar3 + 0x5b) == 4) {
      if (iVar1 == 0) {
        dwc3_start_stop_host(puVar3,0);
      }
    }
    else {
      _dev_info(*puVar3,"resetting dp params for USB ss\n");
      ipc_log_string(puVar3[0xa5],"%s: resetting params for USB ss\n",
                     "dwc3_msm_clear_dp_only_params");
      *(undefined1 *)(puVar3 + 0xa3) = 0;
      *(uint *)(puVar3[0x39] + 0x10) = *(uint *)(puVar3[0x39] + 0x10) & 0xfffffdff;
      if (puVar3[5] == 0) {
        *(undefined4 *)(puVar3 + 0x98) = *(undefined4 *)((long)puVar3 + 0x4c4);
      }
      else {
        *(undefined4 *)(*(long *)(puVar3[5] + 0xa8) + 0x45c) = *(undefined4 *)((long)puVar3 + 0x4c4)
        ;
      }
      usb_redriver_notify_disconnect(puVar3[0x3a]);
    }
    *(uint *)(puVar3[0x39] + 0x10) = *(uint *)(puVar3[0x39] + 0x10) & 0xfffffbff;
    mutex_unlock(puVar3 + 0x92);
    return 0;
  }
  if (*(int *)(puVar3 + 0x149) == (int)param_3) {
    _dev_info(param_1,"DP lane already configured\n");
    ipc_log_string(puVar3[0xa5],"%s: DP lane already configured\n","dwc3_msm_set_dp_mode");
    return 0;
  }
  _dev_info(param_1,"Set DP lanes:%d refcnt:%d\n",param_3 & 0xffffffff,
            *(undefined4 *)((long)puVar3 + 0xa44));
  ipc_log_string(puVar3[0xa5],"%s: Set DP lanes:%d refcnt:%d\n","dwc3_msm_set_dp_mode",uVar4,
                 *(undefined4 *)((long)puVar3 + 0xa44));
  if ((int)param_3 == 2) {
    if (*(char *)(puVar3 + 0x61) == '\0') {
      msleep(0x14);
      return -0xb;
    }
    mutex_lock(puVar3 + 0x92);
    *(undefined4 *)(puVar3 + 0x149) = 2;
    *(int *)((long)puVar3 + 0xa44) = *(int *)((long)puVar3 + 0xa44) + 1;
    mutex_unlock(puVar3 + 0x92);
    usb_redriver_release_lanes
              (puVar3[0x3a],(*(uint *)(puVar3[0x39] + 0x10) >> 2 ^ 0xffffffff) & 1,2);
    __pm_runtime_resume(puVar3[5] + 0x10,4);
    *(uint *)(puVar3[0x39] + 0x10) = *(uint *)(puVar3[0x39] + 0x10) | 0x400;
    __pm_runtime_idle(puVar3[5] + 0x10,4);
    _dev_info(param_1,"Set DP 2 lanes: success, refcnt:%d\n",*(undefined4 *)((long)puVar3 + 0xa44));
    ipc_log_string(puVar3[0xa5],"%s: Set DP 2 lanes: success, refcnt:%d\n","dwc3_msm_set_dp_mode",
                   *(undefined4 *)((long)puVar3 + 0xa44));
    return 0;
  }
  flush_work(puVar3 + 0x45);
  __flush_workqueue(puVar3[0x53]);
  mutex_lock(puVar3 + 0x92);
  if (*(int *)(puVar3 + 99) == 0) {
    iVar1 = dwc3_start_stop_host(puVar3,0);
    if (iVar1 != 0) goto LAB_00105360;
    _dev_info(param_1,"stop host mode\n");
    dwc3_msm_set_dp_only_params(puVar3);
    dwc3_start_stop_host(puVar3,1);
  }
  else if (*(char *)((long)puVar3 + 0x312) == '\0') {
    uVar2 = (uint)puVar3[0x5a];
    while ((uVar2 >> 3 & 1) != 0) {
      msleep(0x14);
      uVar2 = (uint)puVar3[0x5a];
    }
    _dev_info(param_1,"USB is not active.\n");
    ipc_log_string(puVar3[0xa5],"%s: USB is not active.\n","dwc3_msm_set_dp_mode");
    dwc3_msm_set_dp_only_params(puVar3);
  }
  else {
    iVar1 = dwc3_start_stop_device(puVar3,0);
    if (iVar1 != 0) goto LAB_00105360;
    _dev_info(param_1,"stop device mode\n");
    dwc3_msm_set_dp_only_params(puVar3);
    dwc3_start_stop_device(puVar3,1);
  }
  if (*(int *)(puVar3 + 0x149) != 2) {
    *(int *)((long)puVar3 + 0xa44) = *(int *)((long)puVar3 + 0xa44) + 1;
  }
  iVar1 = 0;
  *(undefined4 *)(puVar3 + 0x149) = 4;
LAB_00105360:
  _dev_info(param_1,"Set DP 4 lanes: %d refcnt:%d\n",iVar1,*(undefined4 *)((long)puVar3 + 0xa44));
  ipc_log_string(puVar3[0xa5],"%s: Set DP 4 lanes: %d refcnt:%d\n","dwc3_msm_set_dp_mode",iVar1,
                 *(undefined4 *)((long)puVar3 + 0xa44));
  mutex_unlock(puVar3 + 0x92);
  return iVar1;
}



//------------------------------------------------------------
// dwc3_start_stop_host @ 001053a4 size=240
// signature: undefined dwc3_start_stop_host(void)
// callers: [dwc3_restart_usb_work, dwc3_msm_set_dp_mode]
//------------------------------------------------------------

undefined8 dwc3_start_stop_host(long param_1,ulong param_2)

{
  uint uVar1;
  
  if ((param_2 & 1) == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: stop_host_mode started",
                   "dwc3_start_stop_host");
    *(undefined1 *)(param_1 + 0x312) = 0;
    *(undefined4 *)(param_1 + 0x318) = 1;
    dwc3_ext_event_notify(param_1);
    __pm_runtime_resume(*(long *)(param_1 + 0x28) + 0x10,5);
    flush_work(param_1 + 0x228);
    __flush_workqueue(*(undefined8 *)(param_1 + 0x298));
    __pm_runtime_idle(*(long *)(param_1 + 0x28) + 0x10,5);
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x2d0);
    while ((uVar1 >> 3 & 1) != 0) {
      msleep(0x14);
      uVar1 = (uint)*(undefined8 *)(param_1 + 0x2d0);
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: stop_host_mode completed",
                   "dwc3_start_stop_host");
    if (*(int *)(param_1 + 0x318) == 0) {
      return 0xfffffff0;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: start host mode","dwc3_start_stop_host");
    *(undefined4 *)(param_1 + 0x318) = 0;
    *(undefined1 *)(param_1 + 0x312) = 0;
    dwc3_ext_event_notify(param_1);
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_set_dp_only_params @ 00105494 size=136
// signature: undefined dwc3_msm_set_dp_only_params(void)
// callers: [dwc3_msm_set_dp_mode]
//------------------------------------------------------------

void dwc3_msm_set_dp_only_params(undefined8 *param_1)

{
  uint uVar1;
  
  _dev_info(*param_1,"set dp params for USB\n");
  usb_redriver_release_lanes
            (param_1[0x3a],(*(uint *)(param_1[0x39] + 0x10) >> 2 ^ 0xffffffff) & 1,4);
  uVar1 = *(uint *)((long)param_1 + 0x4c4);
  *(undefined1 *)(param_1 + 0xa3) = 1;
  if (2 < uVar1) {
    uVar1 = 3;
  }
  if (param_1[5] == 0) {
    *(uint *)(param_1 + 0x98) = uVar1;
  }
  else {
    *(uint *)(*(long *)(param_1[5] + 0xa8) + 0x45c) = uVar1;
  }
  *(uint *)(param_1[0x39] + 0x10) = *(uint *)(param_1[0x39] + 0x10) | 0x200;
  return;
}



//------------------------------------------------------------
// dwc3_start_stop_device @ 0010551c size=244
// signature: undefined dwc3_start_stop_device(void)
// callers: [dwc3_msm_probe, dwc3_msm_set_dp_mode]
//------------------------------------------------------------

undefined8 dwc3_start_stop_device(long param_1,ulong param_2)

{
  uint uVar1;
  
  if ((param_2 & 1) == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: stop device mode","dwc3_start_stop_device")
    ;
    *(undefined1 *)(param_1 + 0x312) = 0;
    *(undefined4 *)(param_1 + 0x318) = 1;
    dwc3_ext_event_notify(param_1);
    __pm_runtime_resume(*(long *)(param_1 + 0x28) + 0x10,5);
    flush_work(param_1 + 0x228);
    __flush_workqueue(*(undefined8 *)(param_1 + 0x298));
    __pm_runtime_idle(*(long *)(param_1 + 0x28) + 0x10,5);
    uVar1 = (uint)*(undefined8 *)(param_1 + 0x2d0);
    while ((uVar1 >> 3 & 1) != 0) {
      msleep(0x14);
      uVar1 = (uint)*(undefined8 *)(param_1 + 0x2d0);
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: stop_device_mode completed",
                   "dwc3_start_stop_device");
    if (*(char *)(param_1 + 0x312) != '\0') {
      return 0xfffffff0;
    }
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: start device mode","dwc3_start_stop_device"
                  );
    *(undefined4 *)(param_1 + 0x318) = 1;
    *(undefined1 *)(param_1 + 0x312) = 1;
    dwc3_ext_event_notify(param_1);
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_get_repeater_ver @ 00105614 size=156
// signature: undefined dwc3_msm_get_repeater_ver(void)
// callers: []
//------------------------------------------------------------

ulong dwc3_msm_get_repeater_ver(long param_1)

{
  undefined4 uVar1;
  ulong uVar2;
  code *pcVar3;
  
  uVar2 = usb_get_repeater_by_phandle(**(undefined8 **)(param_1 + 0x1c0),"usb-repeater",0);
  if (uVar2 < 0xfffffffffffff001) {
    if ((uVar2 == 0) || (pcVar3 = *(code **)(uVar2 + 0x50), pcVar3 == (code *)0x0)) {
      uVar1 = 0xffffffea;
    }
    else {
      if (*(int *)(pcVar3 + -4) != 0x60a42524) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x105674);
        (*pcVar3)();
      }
      uVar1 = (*pcVar3)(uVar2);
    }
    uVar2 = 0;
    *(undefined4 *)(param_1 + 0xb2c) = uVar1;
  }
  else {
    _printk(&DAT_00111ef6,uVar2);
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// init_module @ 001056b4 size=48
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  dwc3_msm_kretprobe_init();
  __platform_driver_register(&dwc3_msm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// dwc3_core_send_gadget_ep_cmd @ 001056e4 size=628
// signature: undefined dwc3_core_send_gadget_ep_cmd(void)
// callers: [dwc3_msm_ep_queue, dwc3_msm_ep_enable, dwc3_core_stop_active_transfer, usb_gsi_ep_op]
//------------------------------------------------------------

int dwc3_core_send_gadget_ep_cmd(long param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  byte extraout_var;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  int iVar9;
  long lVar10;
  
  lVar8 = *(long *)(param_1 + 0x98);
  lVar10 = *(long *)(param_1 + 0x38);
  lVar6 = *(long *)(*(long *)(*(long *)(lVar8 + 400) + 0x60) + 0x98);
  if (*(uint *)(*(long *)(lVar8 + 0x370) + 0x58) < 4) {
    uVar3 = readl(*(long *)(lVar6 + 8) + 0xc200);
    if ((uVar3 >> 6 & 1) == 0) {
      uVar7 = 0;
    }
    else {
      uVar3 = uVar3 & 0xffffffbf;
      uVar7 = 0x40;
    }
    uVar7 = uVar3 & 0x100 | uVar7;
    if (uVar7 != 0) {
      writel(uVar3 & 0xfffffeff,*(long *)(lVar6 + 8) + 0xc200);
    }
  }
  else {
    uVar7 = 0;
  }
  writel_relaxed(param_3[2],*(long *)(param_1 + 0x80) + -0xc0f8);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(param_3[1],*(long *)(param_1 + 0x80) + -0xc0fc);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(*param_3,*(long *)(param_1 + 0x80) + -0xc100);
  DataSynchronizationBarrier(3,3,0);
  if (((param_2 & 0xf) == 7) && ((*(byte *)(lVar10 + 3) & 3) != 1)) {
    param_2 = param_2 & 0xfffffaff;
  }
  else {
    param_2 = param_2 | 0x400;
  }
  writel_relaxed(param_2,*(long *)(param_1 + 0x80) + -0xc0f4);
  DataSynchronizationBarrier(3,3,0);
  iVar9 = 5000;
  do {
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x80) + -0xc0f4);
    if ((uVar3 >> 10 & 1) == 0) {
      uVar3 = uVar3 >> 0xc & 0xf;
      if (uVar3 == 2) {
        iVar5 = -0xb;
      }
      else {
        if (uVar3 == 1) {
          uVar4 = dev_driver_string(*(undefined8 *)(lVar8 + 400));
          lVar6 = (*(long **)(lVar8 + 400))[0xe];
          if (lVar6 == 0) {
            lVar6 = **(long **)(lVar8 + 400);
          }
          __warn_printk("%s %s: No resource for %s\n",uVar4,lVar6,param_1 + 0xb8);
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1058a8);
          (*pcVar2)();
        }
        iVar5 = 0;
        if (uVar3 != 0) {
          uVar4 = dev_driver_string(*(undefined8 *)(lVar8 + 400));
          lVar6 = (*(long **)(lVar8 + 400))[0xe];
          if (lVar6 == 0) {
            lVar6 = **(long **)(lVar8 + 400);
          }
          __warn_printk("%s %s: UNKNOWN cmd status\n",uVar4,lVar6);
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x105868);
          (*pcVar2)();
        }
      }
      goto LAB_001058a8;
    }
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar5 = -0x16;
LAB_001058a8:
  iVar1 = -0x6e;
  if (iVar9 != 0) {
    iVar1 = iVar5;
  }
  if (((param_2 & 0xf) == 6) && (iVar1 != -0x6e)) {
    if (iVar1 == 0) {
      if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10595c);
        (*pcVar2)();
      }
      lVar8 = lVar6 + (ulong)*(byte *)(param_1 + 0xaa) * 0x28;
      *(ulong *)(lVar8 + 0x558) = *(ulong *)(lVar8 + 0x558) | 1;
      if (iVar9 == 0) goto LAB_00105908;
    }
    readl_relaxed(*(long *)(param_1 + 0x80) + -0xc0f4);
    *(byte *)(param_1 + 0xac) = extraout_var & 0x7f;
  }
LAB_00105908:
  if (uVar7 != 0) {
    uVar3 = readl(*(long *)(lVar6 + 8) + 0xc200);
    writel(uVar3 | uVar7,*(long *)(lVar6 + 8) + 0xc200);
  }
  return iVar1;
}



//------------------------------------------------------------
// writel_relaxed @ 0010595c size=132
// signature: undefined writel_relaxed(void)
// callers: [dwc3_msm_probe, usb_gsi_ep_op, dwc3_core_send_gadget_ep_cmd]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x105974,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1059b0,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001059e0 size=124
// signature: undefined readl_relaxed(void)
// callers: [dwc3_msm_probe, dwc3_core_send_gadget_ep_cmd]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x105a28,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// dwc3_msm_depcfg_params @ 00105a5c size=292
// signature: undefined dwc3_msm_depcfg_params(void)
// callers: [dwc3_msm_ep_enable, usb_gsi_ep_op]
//------------------------------------------------------------

void dwc3_msm_depcfg_params(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  code *pcVar5;
  long lVar6;
  long lVar7;
  
  lVar2 = *(long *)(param_1 + 0x38);
  lVar3 = *(long *)(param_1 + 0x40);
  lVar7 = *(long *)(param_1 + 0x98);
  uVar1 = (*(byte *)(lVar2 + 3) & 3) << 1 | (*(ushort *)(lVar2 + 4) & 0x7ff) << 3;
  lVar6 = *(long *)(*(long *)(*(long *)(lVar7 + 400) + 0x60) + 0x98);
  *(uint *)(param_2 + 8) = uVar1;
  if (4 < *(uint *)(*(long *)(lVar7 + 0x370) + 0x58)) {
    *(uint *)(param_2 + 8) =
         (uint)((uint7)*(undefined7 *)(param_1 + 0x2e) >> 0x1c) + 0x3c00000 & 0x3c00000 | uVar1;
  }
  if (((lVar3 != 0) && ((*(byte *)(lVar3 + 3) & 0x1f) != 0)) && ((*(byte *)(lVar2 + 3) & 3) == 2)) {
    *(uint *)(param_2 + 4) = *(uint *)(param_2 + 4) | 0x1002000;
    *(byte *)(param_1 + 0xcc) = *(byte *)(param_1 + 0xcc) | 2;
  }
  uVar1 = *(uint *)(param_2 + 4) | (*(byte *)(param_1 + 0xaa) & 0x1f) << 0x19;
  *(uint *)(param_2 + 4) = uVar1;
  if ((*(byte *)(param_1 + 0xcc) & 1) != 0) {
    *(uint *)(param_2 + 8) =
         *(uint *)(param_2 + 8) | (*(byte *)(param_1 + 0xaa) >> 1 & 0x1f) << 0x11;
  }
  if (0x1f < (ulong)*(byte *)(param_1 + 0xaa)) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x105b80);
    (*pcVar5)();
  }
  iVar4 = *(int *)(lVar6 + (ulong)*(byte *)(param_1 + 0xaa) * 0x28 + 0x540);
  if (iVar4 == 3) {
    *(uint *)(param_2 + 4) = uVar1 | 0xc000;
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x8000;
  }
  else if (iVar4 == 2) {
    *(uint *)(param_2 + 4) = uVar1 | 0xb00;
    return;
  }
  return;
}



//------------------------------------------------------------
// dwc3_core_resize_tx_fifos @ 00105b80 size=500
// signature: undefined dwc3_core_resize_tx_fifos(void)
// callers: [dwc3_msm_ep_enable, usb_gsi_ep_op]
//------------------------------------------------------------

void dwc3_core_resize_tx_fifos(long param_1)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = *(long *)(param_1 + 0x98);
  if ((((*(uint *)(lVar8 + 0x4e8) >> 0xb & 1) != 0) &&
      (*(char *)(*(long *)(param_1 + 0x38) + 2) < '\0')) && (1 < *(byte *)(param_1 + 0xaa))) {
    bVar1 = *(byte *)(*(long *)(param_1 + 0x38) + 3) & 3;
    lVar9 = *(long *)(*(long *)(*(long *)(lVar8 + 400) + 0x60) + 0x98);
    uVar6 = 3;
    if ((bVar1 != 2 || (*(byte *)(param_1 + 0x34) & 0x78) == 0) && bVar1 != 1) {
      uVar6 = 1;
    }
    if (((0x18 < (*(byte *)(param_1 + 0x34) & 0x7c)) && (bVar1 == 2)) &&
       (*(int *)(lVar8 + 0x46c) == 0x3331)) {
      uVar6 = (uint)*(byte *)(lVar8 + 0x4dc);
    }
    uVar2 = *(ushort *)(lVar8 + 0x4ac);
    uVar7 = (uint)*(byte *)(lVar8 + 0x491);
    if (*(int *)(lVar8 + 0x46c) == 0x3332) {
      uVar7 = *(uint *)(lVar8 + 0x4a8) & 0x300 | uVar7;
    }
    uVar7 = uVar7 >> 3;
    uVar5 = 0;
    if (uVar7 != 0) {
      uVar5 = (uVar7 | 0x400) / uVar7;
    }
    iVar3 = (uVar6 - 1) + (uVar6 - 1) * uVar5;
    iVar4 = ((uint)uVar2 - *(int *)(lVar8 + 0x4f4)) +
            (*(int *)(lVar8 + 0x4f0) - *(int *)(lVar8 + 0x4f8)) * (-2 - uVar5);
    if (iVar4 < 1) {
      iVar4 = 0;
    }
    if (iVar3 <= iVar4) {
      iVar4 = iVar3;
    }
    uVar6 = uVar5 + iVar4 + 2;
    uVar5 = readl(*(long *)(lVar9 + 8) + 0xc300);
    iVar4 = *(int *)(lVar8 + 0x4f4);
    uVar7 = uVar6 & 0xffff;
    if (*(int *)(lVar8 + 0x46c) != 0x5533) {
      uVar7 = uVar6 & 0x7fff;
    }
    iVar3 = uVar7 + iVar4;
    *(int *)(lVar8 + 0x4f4) = iVar3;
    if (iVar3 < (int)(uint)uVar2) {
      writel(uVar6 | (uVar5 & 0xffff0000) + iVar4 * 0x10000,
             ((ulong)*(byte *)(param_1 + 0xaa) & 0xfe) * 2 + 0xc300 + *(long *)(lVar9 + 8));
      *(int *)(lVar8 + 0x4f8) = *(int *)(lVar8 + 0x4f8) + 1;
    }
    else {
      _dev_err(*(undefined8 *)(lVar8 + 400),"Fifosize(%d) > RAM size(%d) %s depth:%d\n",iVar3,uVar2,
               *(undefined8 *)(param_1 + 8));
      uVar7 = uVar6 & 0xffff;
      if (*(int *)(lVar8 + 0x46c) != 0x5533) {
        uVar7 = uVar6 & 0x7fff;
      }
      *(uint *)(lVar8 + 0x4f4) = *(int *)(lVar8 + 0x4f4) - uVar7;
    }
  }
  return;
}



//------------------------------------------------------------
// readl @ 00105d74 size=140
// signature: undefined readl(void)
// callers: [dwc3_otg_start_peripheral, dwc3_msm_host_ss_powerdown, msm_dwc3_reset_dbm_ep, usb_gsi_ep_op, dynamic_disable_store, xhci_test_store, dwc3_override_vbus_status, dwc3_pwr_event_handler, dwc3_msm_notify_event, dwc3_core_stop_active_transfer, msm_ep_config, dwc3_msm_is_ss_rhport_connected, dwc3_core_send_gadget_ep_cmd, dwc3_msm_set_in_p3_state, msm_ep_unconfig, dwc3_msm_write_reg_field, msm_data_fifo_config, dbm_ep_unconfig, dwc3_core_resize_tx_fifos, dbm_event_buffer_config, dwc3_otg_sm_work, dwc3_msm_suspend, dwc3_otg_start_host, mdwc3_usb2_phy_soft_reset, dwc3_msm_ep_queue, dwc3_msm_ep_enable, dwc3_msm_host_ss_powerup, dwc3_msm_resume]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x105dcc,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00105e00 size=136
// signature: undefined writel(void)
// callers: [dwc3_otg_start_peripheral, dwc3_msm_host_ss_powerdown, msm_ep_unconfig, dwc3_msm_write_reg_field, msm_data_fifo_config, dbm_ep_unconfig, dwc3_core_resize_tx_fifos, msm_dwc3_reset_dbm_ep, dbm_event_buffer_config, dwc3_msm_suspend, usb_gsi_ep_op, dwc3_otg_start_host, mdwc3_usb2_phy_soft_reset, dwc3_msm_ep_queue, dwc3_msm_ep_enable, dwc3_msm_host_ss_powerup, xhci_test_store, dwc3_override_vbus_status, dwc3_pwr_event_handler, dwc3_msm_notify_event, dwc3_core_stop_active_transfer, msm_ep_config, dwc3_core_send_gadget_ep_cmd, dwc3_msm_resume]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x105e18,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x105e58,uVar1);
  return;
}



//------------------------------------------------------------
// dwc3_msm_req_complete_func @ 00105e8c size=328
// signature: undefined dwc3_msm_req_complete_func(void)
// callers: []
//------------------------------------------------------------

void dwc3_msm_req_complete_func(long param_1,long param_2)

{
  int *piVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  code *pcVar7;
  long *plVar8;
  long lVar9;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 400);
  lVar9 = *(long *)(*(long *)(lVar4 + 0x60) + 0x98);
  plVar2 = (long *)(lVar9 + 0x138);
  plVar8 = plVar2;
  do {
    plVar8 = (long *)*plVar8;
    plVar3 = plVar2;
    if (plVar8 == plVar2) break;
    plVar3 = plVar8;
  } while (plVar8[2] != param_2);
  if ((plVar3 == (long *)0x0) || (plVar3[2] != param_2)) {
    _dev_err(lVar4,"%s: could not find the request\n","dwc3_msm_req_complete_func");
    return;
  }
  uVar5 = __list_del_entry_valid(plVar3);
  if ((uVar5 & 1) != 0) {
    lVar4 = *plVar3;
    plVar2 = (long *)plVar3[1];
    *(long **)(lVar4 + 8) = plVar2;
    *plVar2 = lVar4;
  }
  *plVar3 = -0x2152ffffffffff00;
  plVar3[1] = -0x2152fffffffffede;
  *(char *)(param_1 + 0xa9) = *(char *)(param_1 + 0xa9) + '\x01';
  dbm_ep_unconfig(lVar9,*(undefined1 *)(param_1 + 0xaa));
  iVar6 = 0;
  lVar4 = 0x540;
  do {
    piVar1 = (int *)(lVar9 + lVar4);
    lVar4 = lVar4 + 0x28;
    if (*piVar1 == 1) {
      iVar6 = iVar6 + 1;
    }
  } while (lVar4 != 0xa40);
  if (iVar6 == 0) {
    dbm_event_buffer_config(lVar9,0,0,0);
  }
  pcVar7 = (code *)plVar3[3];
  *(code **)(param_2 + 0x30) = pcVar7;
  if (pcVar7 != (code *)0x0) {
    if (*(int *)(pcVar7 + -4) != -0x2b72cf53) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105f9c);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,param_2);
  }
  kfree(plVar3);
  return;
}



//------------------------------------------------------------
// dwc3_ext_event_notify @ 00105fd4 size=992
// signature: undefined dwc3_ext_event_notify(void)
// callers: [dwc3_msm_probe, dwc3_restart_usb_work, dwc3_resume_work, dwc3_start_stop_device, dwc3_msm_set_role, dynamic_disable_store, dwc3_start_stop_host]
//------------------------------------------------------------

void dwc3_ext_event_notify(undefined8 *param_1)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  code *pcVar7;
  
  flush_work(param_1 + 0x54);
  if ((*(char *)((long)param_1 + 0xa52) == '\0') ||
     ((*(char *)((long)param_1 + 0x312) == '\0' && (*(int *)(param_1 + 99) != 0)))) {
    puVar1 = param_1 + 0x5a;
    ipc_log_string(param_1[0xa5],"%s: enter: mdwc->inputs:%lx hs_phy_flags:%x\n",
                   "dwc3_ext_event_notify",param_1[0x5a],*(undefined4 *)(param_1[0x38] + 0x10));
    if (*(int *)(param_1 + 99) == 1) {
      ipc_log_string(param_1[0xa5],"%s: XCVR: ID set\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 | 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else {
      ipc_log_string(param_1[0xa5],"%s: XCVR: ID clear\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    if ((*(char *)((long)param_1 + 0x312) == '\0') || (*(char *)(param_1 + 0x51) != '\0')) {
      ipc_log_string(param_1[0xa5],"%s: XCVR: BSV clear\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else if ((*(byte *)(param_1[0x38] + 0x10) >> 6 & 1) == 0) {
      ipc_log_string(param_1[0xa5],"%s: XCVR: BSV set\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 | 2;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else {
      ipc_log_string(param_1[0xa5],"%s: XCVR: BSV clear\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    if (*(char *)((long)param_1 + 0x314) == '\0') {
      ipc_log_string(param_1[0xa5],"%s: XCVR: SUSP clear\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else {
      ipc_log_string(param_1[0xa5],"%s: XCVR: SUSP set\n","dwc3_ext_event_notify");
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 | 4;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    if (*(char *)((long)param_1 + 0x311) == '\0') {
      uVar5 = 0;
    }
    else if (*(char *)((long)param_1 + 0x312) == '\0') {
      uVar5 = 1;
    }
    else {
      *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) & 0xffffff3f;
      ipc_log_string(param_1[0xa5],"%s: eud: state:%d active:%d hs_phy_flags:0x%x\n",
                     "dwc3_ext_event_notify",*(undefined1 *)((long)param_1 + 0x311),
                     *(undefined1 *)((long)param_1 + 0x313),*(undefined4 *)(param_1[0x38] + 0x10));
      lVar6 = param_1[0x38];
      if (*(char *)((long)param_1 + 0x313) == '\0') {
        *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) | 0x40;
        ipc_log_string(param_1[0xa5],"%s: EUD: XCVR: BSV clear\n","dwc3_ext_event_notify");
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 & 0xfffffffffffffffd;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      else {
        *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) | 0x80;
        ipc_log_string(param_1[0xa5],"%s: EUD: XCVR: BSV set\n","dwc3_ext_event_notify");
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 2;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      uVar5 = 0;
      *(undefined1 *)((long)param_1 + 0x311) = 0;
    }
    ipc_log_string(param_1[0xa5],"%s: eud: state:%d active:%d hs_phy_flags:0x%x\n",
                   "dwc3_ext_event_notify",uVar5,*(undefined1 *)((long)param_1 + 0x313),
                   *(undefined4 *)(param_1[0x38] + 0x10));
    if (*(char *)((long)param_1 + 0x312) == '\0') {
      uVar2 = *(uint *)(param_1[0x38] + 0x10);
      if ((uVar2 >> 6 & 1) != 0) {
        *(uint *)(param_1[0x38] + 0x10) = uVar2 & 0xffffffbf;
        *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) | 0x100;
        lVar6 = param_1[0x38];
        if ((lVar6 != 0) && (pcVar7 = *(code **)(lVar6 + 0x138), pcVar7 != (code *)0x0)) {
          if (*(int *)(pcVar7 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1062cc);
            (*pcVar7)();
          }
          (*pcVar7)(lVar6,1);
          lVar6 = param_1[0x38];
        }
        *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xfffffeff;
        return;
      }
    }
    ipc_log_string(param_1[0xa5],"%s: exit: mdwc->inputs:%lx\n","dwc3_ext_event_notify",
                   param_1[0x5a]);
    queue_work_on(0x20,param_1[0x53],param_1 + 0x54);
  }
  else {
    _dev_err(*param_1,"%s: Event not allowed\n","dwc3_ext_event_notify");
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_probe @ 00106414 size=6760
// signature: undefined dwc3_msm_probe(void)
// callers: []
//------------------------------------------------------------

ulong dwc3_msm_probe(long param_1)

{
  ulong *puVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  long *plVar11;
  undefined8 uVar12;
  long lVar13;
  long *plVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  size_t sVar17;
  long lVar18;
  char *pcVar19;
  code *pcVar20;
  undefined8 uVar21;
  long lVar22;
  long *plVar23;
  ulong uVar24;
  bool bVar25;
  ulong uVar26;
  int local_c4;
  char *local_c0;
  char *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  code *local_98;
  code *pcStack_90;
  undefined8 local_88;
  long *plStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar22 = sp_el0;
  lVar18 = param_1 + 0x10;
  local_68 = *(long *)(lVar22 + 0x638);
  uVar21 = *(undefined8 *)(param_1 + 0x2f8);
  plVar11 = (long *)devm_kmalloc(lVar18,0xb48,0xdc0);
  if (plVar11 == (long *)0x0) {
    uVar26 = 0xfffffff4;
    goto LAB_00107d5c;
  }
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  *(long **)(param_1 + 0xa8) = plVar11;
  *plVar11 = lVar18;
  iVar6 = of_device_is_compatible(uVar12,"qcom,dwc3-msm-fw-managed");
  if (iVar6 == 0) {
LAB_00106520:
    plVar11[0x27] = (long)(plVar11 + 0x27);
    plVar11[0x28] = (long)(plVar11 + 0x27);
    plVar11[0x45] = 0xfffffffe0;
    plVar11[0x46] = (long)(plVar11 + 0x46);
    plVar11[0x47] = (long)(plVar11 + 0x46);
    plVar11[0x48] = (long)dwc3_resume_work;
    plVar11[0x4b] = 0xfffffffe0;
    plVar11[0x4c] = (long)(plVar11 + 0x4c);
    plVar11[0x4d] = (long)(plVar11 + 0x4c);
    plVar11[0x4e] = (long)dwc3_restart_usb_work;
    plVar11[0x54] = 0xfffffffe0;
    plVar11[0x55] = (long)(plVar11 + 0x55);
    plVar11[0x56] = (long)(plVar11 + 0x55);
    plVar11[0x57] = (long)dwc3_otg_sm_work;
    plVar11[0x7b] = 0xfffffffe0;
    plVar11[0x7c] = (long)(plVar11 + 0x7c);
    plVar11[0x7d] = (long)(plVar11 + 0x7c);
    plVar11[0x7e] = (long)msm_dwc3_perf_vote_work;
    init_timer_key(plVar11 + 0x81,&delayed_work_timer_fn,0x200000,0,0);
    local_a0 = 0;
    local_98 = (code *)0x0;
    local_b0 = 0;
    local_a8 = 0;
    local_b8 = (char *)0x0;
    lVar22 = ((long *)*plVar11)[0xe];
    if (lVar22 == 0) {
      lVar22 = *(long *)*plVar11;
    }
    lVar22 = ipc_log_context_create(0xc,lVar22,0);
    plVar11[0xa5] = lVar22;
    if (lVar22 == 0) {
      _dev_err(*plVar11,"Error getting ipc_log_ctxt\n");
    }
    pcVar19 = (char *)((undefined8 *)*plVar11)[0xe];
    if (pcVar19 == (char *)0x0) {
      pcVar19 = *(char **)*plVar11;
    }
    snprintf((char *)&local_b8,0x28,"%s.ep_events",pcVar19);
    lVar22 = ipc_log_context_create(0x18,&local_b8,0);
    plVar11[0xa6] = lVar22;
    if (lVar22 == 0) {
      _dev_err(*plVar11,"Error getting ipc_log_ctxt for ep_events\n");
    }
    pcVar19 = (char *)((undefined8 *)*plVar11)[0xe];
    if (pcVar19 == (char *)0x0) {
      pcVar19 = *(char **)*plVar11;
    }
    snprintf((char *)&local_b8,0x28,"%s.trace",pcVar19);
    dwc_trace_ipc_log_ctxt = ipc_log_context_create(0x24,&local_b8,0);
    if (dwc_trace_ipc_log_ctxt == 0) {
      _dev_err(*plVar11,"Error getting trace_ipc_log_ctxt for ep_events\n");
    }
    lVar22 = ((long *)*plVar11)[0xe];
    if (lVar22 == 0) {
      lVar22 = *(long *)*plVar11;
    }
    lVar22 = debugfs_create_dir(lVar22,0);
    plVar11[0x14b] = lVar22;
    if (lVar22 != 0) {
      debugfs_create_u8("qos_req_state",0x1a4,lVar22,plVar11 + 0x14c);
      debugfs_create_bool("qos_rec_start",0x1a4,plVar11[0x14b],(long)plVar11 + 0xa61);
      debugfs_create_u8("qos_rec_index",0x1a4,plVar11[0x14b],(long)plVar11 + 0xa62);
      debugfs_create_file("qos_rec_irq",0x124,plVar11[0x14b],plVar11,qos_rec_irq_ops);
      debugfs_create_x32("pm_qos_latency",0x1a4,plVar11[0x14b],plVar11 + 0x74);
    }
    lVar22 = alloc_workqueue("dwc3_wq",0xa0002,1);
    plVar11[0x52] = lVar22;
    if (lVar22 == 0) {
      _printk(&DAT_00111580,"dwc3_msm_probe");
      uVar26 = 0xfffffff4;
      goto LAB_00107d5c;
    }
    lVar22 = alloc_workqueue("k_sm_usb",0xa0006,1);
    plVar11[0x53] = lVar22;
    if (lVar22 == 0) {
      destroy_workqueue(plVar11[0x52]);
      uVar26 = 0xfffffff4;
      goto LAB_00107d5c;
    }
    plVar23 = *(long **)(param_1 + 0xa8);
    local_c4 = 0;
    lVar22 = *plVar23;
    local_c0 = (char *)0x0;
    uVar26 = usb_get_redriver_by_phandle(uVar21,"ssusb_redriver",0);
    plVar23[0x3a] = uVar26;
    if (uVar26 < 0xfffffffffffff001) {
      lVar13 = *plVar23;
      uVar7 = of_get_named_gpio_flags(*(undefined8 *)(lVar13 + 0x2e8),"gpios",0,0);
      *(uint *)((long)plVar23 + 0xa4c) = uVar7;
      if (uVar7 < 0x200) {
        iVar6 = devm_gpio_request_one(lVar13,uVar7,1,"dwc3-msm-orientation");
        if (iVar6 < 0) {
          _dev_err(lVar13,"Failed to request gpio\n");
          *(undefined4 *)((long)plVar23 + 0xa4c) = 0xffffffea;
          goto LAB_00106d3c;
        }
        *(undefined1 *)(plVar23 + 0x14a) = 1;
      }
      else {
        _dev_err(lVar13,"Failed to get gpio\n");
LAB_00106d3c:
        iVar6 = of_property_read_string
                          (*(undefined8 *)(*plVar23 + 0x2e8),"orientation-override",&local_c0);
        if (iVar6 == 0) {
          _dev_info(lVar22,"overriding orientation from devicetree.\n");
          iVar6 = strcmp(local_c0,"A");
          uVar8 = 4;
          if (iVar6 != 0) {
            uVar8 = 8;
          }
          *(undefined4 *)((long)plVar23 + 0x51c) = uVar8;
        }
      }
      if (*(char *)((long)plVar23 + 0xb31) != '\0') goto LAB_001067f0;
      uVar26 = devm_regulator_get(*plVar23,"USB3_GDSC");
      plVar23[0x37] = uVar26;
      if (0xfffffffffffff000 < uVar26) {
        if (uVar26 != 0xfffffffffffffdfb) {
          plVar23[0x37] = 0;
          goto LAB_001070f4;
        }
LAB_00106cd4:
        uVar26 = 0xfffffdfb;
LAB_00106cd8:
        _dev_err(lVar22,"error getting clock or gdsc.\n");
        goto LAB_00106784;
      }
LAB_001070f4:
      uVar24 = devm_clk_get(*plVar23,&DAT_00111759);
      uVar26 = 0;
      if (uVar24 < 0xfffffffffffff001) {
        uVar26 = uVar24;
      }
      plVar23[0x29] = uVar26;
      clk_set_rate(uVar26,19200000);
      uVar26 = devm_clk_get(*plVar23,"iface_clk");
      plVar23[0x2e] = uVar26;
      if (uVar26 < 0xfffffffffffff001) {
        uVar26 = devm_clk_get(*plVar23,"core_clk");
        plVar23[0x2a] = uVar26;
        if (0xfffffffffffff000 < uVar26) {
          _dev_err(*plVar23,"failed to get core_clk\n");
          uVar26 = (ulong)*(uint *)(plVar23 + 0x2a);
          goto LAB_001071fc;
        }
        uVar26 = __devm_reset_control_get(*plVar23,"core_reset",0,0,0,1);
        plVar23[0x36] = uVar26;
        if (0xfffffffffffff000 < uVar26) {
          _dev_err(*plVar23,"failed to get core_reset\n");
          uVar26 = (ulong)*(uint *)(plVar23 + 0x36);
          goto LAB_001071fc;
        }
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*plVar23 + 0x2e8),"qcom,core-clk-rate",plVar23 + 0x2b,1,0
                          );
        if (iVar6 < 0) {
          _dev_err(*plVar23,"USB core-clk-rate is not present\n");
          uVar26 = 0xffffffea;
          goto LAB_00106cd8;
        }
        lVar13 = clk_round_rate(plVar23[0x2a],plVar23[0x2b]);
        plVar23[0x2b] = lVar13;
        _dev_info(*plVar23,"USB core frequency = %ld\n");
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*plVar23 + 0x2e8),"qcom,core-clk-rate-hs",plVar23 + 0x2c,
                           1,0);
        if (iVar6 < 0) {
          _dev_info(*plVar23,"USB core-clk-rate-hs is not present\n");
          plVar23[0x2c] = plVar23[0x2b];
        }
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*plVar23 + 0x2e8),"qcom,core-clk-rate-disconnected",
                           plVar23 + 0x2d,1,0);
        if (iVar6 < 0) {
          _dev_info(*plVar23,"USB core-clk-rate-disconnected is not present\n");
          lVar13 = plVar23[0x2b];
          plVar23[0x2d] = lVar13;
        }
        else {
          lVar13 = plVar23[0x2d];
        }
        iVar6 = clk_set_rate(plVar23[0x2a],lVar13);
        if (iVar6 != 0) {
          _dev_err(*plVar23,"fail to set core_clk freq:%d\n",iVar6);
        }
        uVar26 = devm_clk_get(*plVar23,"sleep_clk");
        plVar23[0x2f] = uVar26;
        if (0xfffffffffffff000 < uVar26) {
          _dev_err(*plVar23,"failed to get sleep_clk\n");
          uVar26 = (ulong)*(uint *)(plVar23 + 0x2f);
          goto LAB_001071fc;
        }
        clk_set_rate(uVar26,32000);
        *(undefined4 *)(plVar23 + 0x31) = 19200000;
        uVar26 = devm_clk_get(*plVar23,"utmi_clk");
        plVar23[0x30] = uVar26;
        if (0xfffffffffffff000 < uVar26) {
          _dev_err(*plVar23,"failed to get utmi_clk\n");
          uVar26 = (ulong)*(uint *)(plVar23 + 0x30);
          goto LAB_001071fc;
        }
        clk_set_rate(uVar26,(int)plVar23[0x31]);
        uVar24 = devm_clk_get(*plVar23,"bus_aggr_clk");
        uVar26 = 0;
        if (uVar24 < 0xfffffffffffff001) {
          uVar26 = uVar24;
        }
        plVar23[0x33] = uVar26;
        uVar24 = devm_clk_get(*plVar23,"noc_aggr_clk");
        uVar26 = 0;
        if (uVar24 < 0xfffffffffffff001) {
          uVar26 = uVar24;
        }
        plVar23[0x34] = uVar26;
        iVar6 = of_property_match_string
                          (*(undefined8 *)(*plVar23 + 0x2e8),"clock-names","cfg_ahb_clk");
        if (-1 < iVar6) {
          uVar26 = devm_clk_get(*plVar23,"cfg_ahb_clk");
          plVar23[0x35] = uVar26;
          if (0xfffffffffffff000 < uVar26) {
            plVar23[0x35] = 0;
            if ((int)uVar26 == -0x205) goto LAB_00106cd4;
            uVar26 = uVar26 & 0xffffffff;
            _dev_err(*plVar23,"failed to get cfg_ahb_clk ret %d\n",uVar26);
            goto LAB_001071fc;
          }
        }
      }
      else {
        _dev_err(*plVar23,"failed to get iface_clk\n");
        uVar26 = (ulong)*(uint *)(plVar23 + 0x2e);
LAB_001071fc:
        if ((int)uVar26 != 0) goto LAB_00106cd8;
      }
LAB_001067f0:
      *(undefined4 *)(plVar23 + 99) = 1;
      puVar1 = (ulong *)(plVar23 + 0x5a);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar25 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar25) {
          *puVar1 = *puVar1 | 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      iVar6 = of_property_read_variable_u32_array
                        (uVar21,"qcom,lpm-to-suspend-delay-ms",(undefined4 *)((long)plVar23 + 0x374)
                         ,1,0);
      if (iVar6 < 0) {
        _dev_info(lVar22,"setting lpm_to_suspend_delay to zero.\n");
        *(undefined4 *)((long)plVar23 + 0x374) = 0;
      }
      lVar13 = *(long *)(param_1 + 0xa8);
      uVar12 = platform_get_irq_byname(param_1,"hs_phy_irq");
      *(int *)(lVar13 + 0x1f8) = (int)uVar12;
      if (-1 < (int)uVar12) {
        irq_modify_status(uVar12,0,0x1000);
        pcVar19 = "hs_phy_irq";
        uVar26 = devm_request_threaded_irq
                           (lVar18,*(undefined4 *)(lVar13 + 0x1f8),msm_dwc3_pwr_irq,
                            msm_dwc3_pwr_irq_thread,0x22004,"hs_phy_irq",lVar13);
        if ((int)uVar26 == 0) goto LAB_0010689c;
LAB_00106a14:
        uVar26 = uVar26 & 0xffffffff;
        _dev_err(lVar18,"irq req %s failed: %d\n\n",pcVar19,uVar26);
        goto LAB_00106784;
      }
      *(undefined4 *)(lVar13 + 0x1f8) = 0;
LAB_0010689c:
      uVar12 = platform_get_irq_byname(param_1,"pwr_event_irq");
      *(int *)(lVar13 + 0x200) = (int)uVar12;
      if ((int)uVar12 < 0) {
        _dev_err(lVar18,"get_irq for %s failed\n\n","pwr_event_irq");
        uVar26 = 0xffffffea;
        goto LAB_00107a1c;
      }
      irq_modify_status(uVar12,0,0x1000);
      pcVar19 = "pwr_event_irq";
      uVar26 = devm_request_threaded_irq
                         (lVar18,*(undefined4 *)(lVar13 + 0x200),msm_dwc3_pwr_irq,
                          msm_dwc3_pwr_irq_thread,0x22004,"pwr_event_irq",lVar13);
      if ((int)uVar26 != 0) goto LAB_00106a14;
      uVar12 = platform_get_irq_byname(param_1,"dp_hs_phy_irq");
      *(int *)(lVar13 + 0x208) = (int)uVar12;
      if ((int)uVar12 < 0) {
        *(undefined4 *)(lVar13 + 0x208) = 0;
      }
      else {
        irq_modify_status(uVar12,0,0x1000);
        pcVar19 = "dp_hs_phy_irq";
        uVar26 = devm_request_threaded_irq
                           (lVar18,*(undefined4 *)(lVar13 + 0x208),msm_dwc3_pwr_irq,
                            msm_dwc3_pwr_irq_thread,0x22001,"dp_hs_phy_irq",lVar13);
        if ((int)uVar26 != 0) goto LAB_00106a14;
      }
      uVar12 = platform_get_irq_byname(param_1,"dm_hs_phy_irq");
      *(int *)(lVar13 + 0x210) = (int)uVar12;
      if ((int)uVar12 < 0) {
        *(undefined4 *)(lVar13 + 0x210) = 0;
      }
      else {
        irq_modify_status(uVar12,0,0x1000);
        pcVar19 = "dm_hs_phy_irq";
        uVar26 = devm_request_threaded_irq
                           (lVar18,*(undefined4 *)(lVar13 + 0x210),msm_dwc3_pwr_irq,
                            msm_dwc3_pwr_irq_thread,0x22001,"dm_hs_phy_irq",lVar13);
        if ((int)uVar26 != 0) goto LAB_00106a14;
      }
      uVar12 = platform_get_irq_byname(param_1,"ss_phy_irq");
      *(int *)(lVar13 + 0x218) = (int)uVar12;
      if ((int)uVar12 < 0) {
        *(undefined4 *)(lVar13 + 0x218) = 0;
      }
      else {
        irq_modify_status(uVar12,0,0x1000);
        pcVar19 = "ss_phy_irq";
        uVar26 = devm_request_threaded_irq
                           (lVar18,*(undefined4 *)(lVar13 + 0x218),msm_dwc3_pwr_irq,
                            msm_dwc3_pwr_irq_thread,0x22004,"ss_phy_irq",lVar13);
        if ((int)uVar26 != 0) goto LAB_00106a14;
      }
      plVar14 = (long *)platform_get_resource_byname(param_1,0x200,"core_base");
      if (plVar14 == (long *)0x0) {
        pcVar19 = "missing memory base resource\n";
      }
      else {
        plVar23[4] = *plVar14;
        lVar13 = devm_ioremap(lVar18,*plVar14,(plVar14[1] - *plVar14) + 1);
        plVar23[1] = lVar13;
        if (lVar13 != 0) {
          plVar14 = (long *)platform_get_resource_byname(param_1,0x200,"tcsr_dyn_en_dis");
          if (plVar14 != (long *)0x0) {
            lVar13 = devm_ioremap(lVar18,*plVar14,(plVar14[1] - *plVar14) + 1);
            plVar23[2] = lVar13;
            if (lVar13 == 0) {
              pcVar19 = "ioremap for tcsr_dyn_en_dis failed\n";
              goto LAB_00107970;
            }
          }
          plVar14 = (long *)platform_get_resource_byname(param_1,0x200,"ahb2phy_base");
          if (plVar14 != (long *)0x0) {
            uVar26 = devm_ioremap(lVar18,*plVar14,(plVar14[1] - *plVar14) + 1);
            plVar23[3] = uVar26;
            if ((uVar26 == 0) || (0xfffffffffffff000 < uVar26)) {
              _dev_err(lVar22,"couldn\'t find ahb2phy_base addr.\n");
              plVar23[3] = 0;
            }
            else {
              if (*(char *)((long)plVar23 + 0xb31) != '\0') {
                uVar7 = dwc3_msm_modeled_d3_to_d0(plVar23);
                if (uVar7 == 0) {
                  iVar6 = readl_relaxed(plVar23[3] + 0x10);
                  if (iVar6 != 0x11) {
                    writel_relaxed(0x11,plVar23[3] + 0x10);
                    DataSynchronizationBarrier(3,3,0);
                  }
                  uVar26 = __pm_runtime_idle(*(undefined8 *)plVar23[0x167],4);
                  if (((int)uVar26 == 0) &&
                     (uVar26 = __pm_runtime_idle(*(undefined8 *)(plVar23[0x167] + 8),4),
                     (int)uVar26 == 0)) goto LAB_00106dcc;
                  uVar26 = uVar26 & 0xffffffff;
                  lVar22 = *plVar23;
                  pcVar19 = "power state transit failed d0 to d3 with %d\n";
                }
                else {
                  uVar26 = (ulong)uVar7;
                  lVar22 = *plVar23;
                  pcVar19 = "power state transit failed d3 to d0 with %d\n";
                }
                _dev_err(lVar22,pcVar19,uVar26);
                goto LAB_00106784;
              }
              if ((plVar23[0x37] != 0) && ((ulong)plVar23[0x37] < 0xfffffffffffff001)) {
                iVar6 = regulator_enable();
                if (iVar6 == 0) {
                  qcom_clk_set_flags(plVar23[0x2a],2);
                }
                else {
                  _dev_err(*plVar23,"unable to enable usb3 gdsc\n");
                }
              }
              lVar13 = plVar23[0x35];
              iVar6 = clk_prepare(lVar13);
              if ((iVar6 == 0) && (iVar6 = clk_enable(lVar13), iVar6 != 0)) {
                clk_unprepare(lVar13);
              }
              iVar6 = readl_relaxed(plVar23[3] + 0x10);
              if (iVar6 != 0x11) {
                writel_relaxed(0x11,plVar23[3] + 0x10);
                DataSynchronizationBarrier(3,3,0);
              }
              lVar13 = plVar23[0x35];
              clk_disable(lVar13);
              clk_unprepare(lVar13);
              if (((*(char *)((long)plVar23 + 0xb31) == '\0') && (plVar23[0x37] != 0)) &&
                 ((ulong)plVar23[0x37] < 0xfffffffffffff001)) {
                qcom_clk_set_flags(plVar23[0x2a],3);
                iVar6 = regulator_disable(plVar23[0x37]);
                if (iVar6 != 0) {
                  _dev_err(*plVar23,"unable to disable usb3 gdsc\n");
                }
              }
            }
          }
LAB_00106dcc:
          plVar14 = (long *)platform_get_resource_byname(param_1,0x200,"ebc_desc");
          if (plVar14 != (long *)0x0) {
            plVar23[0x147] = *plVar14;
          }
          local_b8 = (char *)0x0;
          iVar6 = of_property_read_string
                            (*(undefined8 *)(*plVar23 + 0x2e8),"qcom,dbm-version",&local_b8);
          if ((iVar6 == 0) && (iVar6 = strcmp(local_b8,"1.4"), iVar6 == 0)) {
            plVar23[0x3b] = (long)dbm_1_4_regtable;
            *(undefined4 *)(plVar23 + 0x3c) = 4;
            *(undefined1 *)((long)plVar23 + 0x1e4) = 1;
LAB_00106e6c:
            of_property_read_variable_u32_array(uVar21,"qcom,num-gsi-evt-buffs",plVar23 + 0x71,1,0);
            if ((int)plVar23[0x71] == 0) {
LAB_00106ef0:
              lVar13 = of_find_property(uVar21,"qcom,use-pdc-interrupts",0);
              *(bool *)((long)plVar23 + 0x315) = lVar13 != 0;
              lVar13 = of_find_property(uVar21,"qcom,use-eusb2-phy",0);
              *(bool *)((long)plVar23 + 0xa41) = lVar13 != 0;
              lVar13 = of_find_property(uVar21,"qcom,disable-host-ssphy-powerdown",0);
              *(bool *)((long)plVar23 + 0x329) = lVar13 != 0;
              lVar13 = of_find_property(uVar21,"qcom,hibernate-skip-thaw",0);
              *(bool *)((long)plVar23 + 0x32a) = lVar13 != 0;
              lVar13 = of_find_property(uVar21,"qcom,enable_host_slow_suspend",0);
              *(bool *)((long)plVar23 + 0x32b) = lVar13 != 0;
              lVar13 = of_find_property(uVar21,"qcom,dis-sending-cm-l1-quirk",0);
              *(bool *)(plVar23 + 0x148) = lVar13 != 0;
              if (*(char *)((long)plVar23 + 0xb31) == '\0') {
                uVar7 = of_property_read_string_helper
                                  (*(undefined8 *)(*plVar23 + 0x2e8),"interconnect-names",0,0,0);
                if ((int)uVar7 < 0) {
                  _dev_err(*plVar23,"No interconnects found.\n");
                }
                else {
                  uVar3 = uVar7 << 1;
                  uVar26 = -(ulong)((uVar7 & 0x7fffffff) >> 0x1e) & 0xfffffffc00000000 |
                           (ulong)uVar3 << 2;
                  puVar15 = (undefined4 *)__kmalloc(uVar26,0xdc0);
                  if (puVar15 == (undefined4 *)0x0) {
                    puVar16 = (undefined4 *)0x0;
                  }
                  else {
                    puVar16 = (undefined4 *)__kmalloc(uVar26,0xdc0);
                    if (puVar16 != (undefined4 *)0x0) {
                      iVar6 = of_property_read_variable_u32_array
                                        (*(undefined8 *)(*plVar23 + 0x2e8),
                                         "qcom,interconnect-values-nom",puVar15,(long)(int)uVar3,0);
                      lVar13 = *plVar23;
                      if (iVar6 < 0) {
                        pcVar19 = "Nominal values not found.\n";
                      }
                      else {
                        iVar6 = of_property_read_variable_u32_array
                                          (*(undefined8 *)(lVar13 + 0x2e8),
                                           "qcom,interconnect-values-svs",puVar16,(long)(int)uVar3,0
                                          );
                        if (-1 < iVar6) {
                          if (uVar7 != 0) {
                            uVar7 = uVar7 - 1;
                            if (1 < uVar7) {
                              uVar7 = 2;
                            }
                            bus_vote_values._24_4_ = *puVar15;
                            bus_vote_values._28_4_ = puVar15[1];
                            bus_vote_values._48_4_ = *puVar16;
                            bus_vote_values._52_4_ = puVar16[1];
                            if (uVar7 != 0) {
                              bus_vote_values._32_4_ = puVar15[2];
                              bus_vote_values._36_4_ = puVar15[3];
                              bus_vote_values._56_4_ = puVar16[2];
                              bus_vote_values._60_4_ = puVar16[3];
                              if (uVar7 != 1) {
                                bus_vote_values._40_4_ = puVar15[4];
                                bus_vote_values._44_4_ = puVar15[5];
                                bus_vote_values._64_4_ = puVar16[4];
                                bus_vote_values._68_4_ = puVar16[5];
                              }
                            }
                          }
                          kfree(puVar15);
                          kfree(puVar16);
                          goto LAB_0010725c;
                        }
                        lVar13 = *plVar23;
                        pcVar19 = "Svs values not found.\n";
                      }
                      _dev_err(lVar13,pcVar19);
                    }
                  }
                  kfree(puVar15);
                  kfree(puVar16);
                }
                _dev_err(lVar22,"Using default bus votes\n");
              }
LAB_0010725c:
              *(undefined4 *)((long)plVar23 + 0x2e4) = 1;
              of_property_read_variable_u32_array
                        (uVar21,"qcom,default-bus-vote",(undefined4 *)((long)plVar23 + 0x2e4),1,0);
              if (3 < *(uint *)((long)plVar23 + 0x2e4)) {
                *(undefined4 *)((long)plVar23 + 0x2e4) = 3;
              }
              uVar24 = of_icc_get(lVar22,"usb-ddr");
              uVar26 = 0;
              if (uVar24 < 0xfffffffffffff001) {
                uVar26 = uVar24;
              }
              plVar23[0x5e] = uVar26;
              uVar24 = of_icc_get(lVar22,"usb-ipa");
              uVar26 = 0;
              if (uVar24 < 0xfffffffffffff001) {
                uVar26 = uVar24;
              }
              plVar23[0x5f] = uVar26;
              uVar24 = of_icc_get(lVar22,"ddr-usb");
              uVar26 = 0;
              if (uVar24 < 0xfffffffffffff001) {
                uVar26 = uVar24;
              }
              plVar23[0x60] = uVar26;
              *(undefined4 *)(plVar23 + 0x74) = 0xffffffff;
              of_property_read_variable_u32_array(uVar21,"qcom,pm-qos-latency",plVar23 + 0x73,1,0);
              lVar22 = of_find_compatible_node(0,0,"qcom,msm-imem-diag-dload");
              if (lVar22 == 0) {
                _printk(&DAT_00112f32);
                diag_dload = 0;
              }
              else {
                diag_dload = of_iomap(lVar22,0);
              }
              local_78 = 0;
              uStack_70 = 0;
              local_88 = 0;
              plStack_80 = (long *)0x0;
              local_98 = (code *)0x0;
              pcStack_90 = (code *)0x0;
              local_a8 = 0;
              local_a0 = 0;
              local_b8 = (char *)0x0;
              local_b0 = 0;
              iVar6 = __of_parse_phandle_with_args(uVar21,"qcom,wcd_usbss",0,0,0,&local_b8);
              pcVar19 = local_b8;
              if (iVar6 != 0) {
                pcVar19 = (char *)0x0;
              }
              uVar26 = of_device_is_available(pcVar19);
              if ((uVar26 & 1) != 0) {
                *(undefined1 *)((long)plVar23 + 0xa51) = 1;
              }
              goto LAB_00107388;
            }
            of_get_property(uVar21,"qcom,gsi-reg-offset",&local_c4);
            if (local_c4 == 0) {
              pcVar19 = "err provide qcom,gsi-reg-offset\n";
            }
            else {
              lVar13 = devm_kmalloc(lVar22,(long)local_c4,0xdc0);
              plVar23[0x99] = lVar13;
              if (lVar13 == 0) {
                uVar26 = 0xfffffff4;
                goto LAB_00107a1c;
              }
              *(int *)(plVar23 + 0x9a) = local_c4 >> 2;
              if (local_c4 >> 2 == 6) {
                of_property_read_variable_u32_array
                          (*(undefined8 *)(lVar22 + 0x2e8),"qcom,gsi-reg-offset",lVar13,6,0);
                goto LAB_00106ef0;
              }
              pcVar19 = "invalid reg offset count\n";
            }
          }
          else {
            *(undefined4 *)(plVar23 + 0x3c) = 8;
            plVar23[0x3b] = (long)dbm_1_5_regtable;
            if ((*(char *)((long)plVar23 + 0x1e4) != '\0') || ((int)plVar23[0x40] != 0))
            goto LAB_00106e6c;
            pcVar19 = "need pwr_event_irq exiting L1\n";
          }
          _dev_err(lVar22,pcVar19);
          uVar26 = 0xffffffea;
          goto LAB_00107a1c;
        }
        pcVar19 = "ioremap failed\n";
      }
LAB_00107970:
      _dev_err(lVar22,pcVar19);
      uVar26 = 0xffffffed;
    }
    else {
      uVar26 = uVar26 & 0xffffffff;
      plVar23[0x3a] = 0;
LAB_00106784:
      if (-1 < (int)uVar26) {
LAB_00107388:
        iVar6 = dma_set_mask(lVar18,0xffffffffffffffff);
        if (iVar6 == 0) {
          dma_set_coherent_mask(lVar18,0xffffffffffffffff);
        }
        else {
          _dev_err(lVar18,"setting DMA mask to 64 failed.\n");
          iVar6 = dma_set_mask_and_coherent(lVar18,0xffffffff);
          if (iVar6 != 0) {
            _dev_err(lVar18,"setting DMA mask to 32 failed.\n");
            uVar26 = 0xffffffa1;
            goto LAB_00107a1c;
          }
        }
        lVar22 = of_get_next_available_child(uVar21,0);
        if (lVar22 == 0) {
          pcVar19 = "failed to find dwc3 child\n";
          lVar22 = lVar18;
          goto LAB_00107970;
        }
        local_c0 = (char *)0x0;
        iVar6 = of_property_read_string(lVar22,"maximum-speed",&local_c0);
        if (iVar6 == 0) {
          iVar6 = match_string(&speed_names,7,local_c0);
        }
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        *(int *)((long)plVar11 + 0x4c4) = iVar6;
        if (plVar11[5] == 0) {
          *(int *)(plVar11 + 0x98) = iVar6;
        }
        else {
          *(int *)(*(long *)(plVar11[5] + 0xa8) + 0x45c) = iVar6;
        }
        uVar24 = of_property_read_string(lVar22,"dr_mode",&local_c0);
        if ((int)uVar24 == 0) {
          uVar24 = match_string(&usb_dr_modes,4,local_c0);
        }
        uVar26 = uVar24 & 0xffffffff;
        iVar6 = (int)uVar24;
        if (iVar6 < 1) {
          iVar6 = 0;
        }
        *(int *)((long)plVar11 + 0x2dc) = iVar6;
        uVar8 = of_irq_get(lVar22,0);
        *(undefined4 *)(plVar11 + 0x44) = uVar8;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        plStack_80 = (long *)0x0;
        local_98 = (code *)0x0;
        pcStack_90 = (code *)0x0;
        local_a8 = 0;
        local_a0 = 0;
        local_b8 = (char *)0x0;
        local_b0 = 0;
        iVar6 = __of_parse_phandle_with_args(lVar22,"usb-phy",0,0,0,&local_b8);
        pcVar19 = local_b8;
        if (iVar6 != 0) {
          pcVar19 = (char *)0x0;
        }
        uVar24 = devm_usb_get_phy_by_node(*plVar11,pcVar19,0);
        plVar11[0x38] = uVar24;
        if (uVar24 < 0xfffffffffffff001) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          plStack_80 = (long *)0x0;
          local_98 = (code *)0x0;
          pcStack_90 = (code *)0x0;
          local_a8 = 0;
          local_a0 = 0;
          local_b8 = (char *)0x0;
          local_b0 = 0;
          iVar6 = __of_parse_phandle_with_args(lVar22,"usb-phy",0,0,1,&local_b8);
          pcVar19 = local_b8;
          if (iVar6 != 0) {
            pcVar19 = (char *)0x0;
          }
          uVar24 = devm_usb_get_phy_by_node(*plVar11,pcVar19,0);
          plVar11[0x39] = uVar24;
          if (uVar24 < 0xfffffffffffff001) {
            uVar24 = usb_get_repeater_by_phandle(*(undefined8 *)plVar11[0x38],"usb-repeater",0);
            if (uVar24 < 0xfffffffffffff001) {
              if ((uVar24 == 0) || (pcVar20 = *(code **)(uVar24 + 0x50), pcVar20 == (code *)0x0)) {
                uVar8 = 0xffffffea;
              }
              else {
                if (*(int *)(pcVar20 + -4) != 0x60a42524) {
                    /* WARNING: Does not return */
                  pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x107554);
                  (*pcVar20)();
                }
                uVar8 = (*pcVar20)(uVar24);
              }
              *(undefined4 *)((long)plVar11 + 0xb2c) = uVar8;
            }
            else {
              _printk(&DAT_00111ef6);
            }
          }
          else {
            _dev_err(*plVar11,"unable to get ssphy device\n");
            uVar26 = (ulong)*(uint *)(plVar11 + 0x39);
          }
        }
        else {
          _dev_err(*plVar11,"unable to get hsphy device\n");
          uVar26 = (ulong)*(uint *)(plVar11 + 0x38);
        }
        if ((int)uVar26 < 0) goto LAB_00107a1c;
        plVar11[0x66] = 3;
        *(undefined4 *)(plVar11 + 0x6e) = 1;
        pm_runtime_set_autosuspend_delay(*plVar11,1000);
        __pm_runtime_use_autosuspend(*plVar11,1);
        uVar26 = device_property_present(*plVar11,"qcom,disable-wakeup");
        lVar22 = *plVar11;
        if ((uVar26 & 1) == 0) {
          device_set_wakeup_capable(lVar22,1);
          device_wakeup_enable(lVar22);
        }
        else {
          device_wakeup_disable(lVar22);
          device_set_wakeup_capable(lVar22,0);
        }
        uVar26 = devm_regulator_get_optional(*plVar11,"vbus_dwc3");
        plVar11[0x3d] = uVar26;
        if (0xfffffffffffff000 < uVar26) {
          if (uVar26 == 0xfffffffffffffdfb) {
            uVar26 = 0xfffffdfb;
            goto LAB_00107a1c;
          }
          plVar11[0x3d] = 0;
        }
        lVar22 = of_find_property(uVar21,"qcom,disable-dev-mode-pm",0);
        if (lVar22 != 0) {
          piVar2 = (int *)(*plVar11 + 0x1f8);
          Hint_Prefetch(piVar2,2,0,1);
          do {
            cVar4 = '\x01';
            bVar25 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar25) {
              *piVar2 = *piVar2 + 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
        }
        bVar5 = device_property_present(*plVar11,"qcom,force-suspend");
        *(byte *)((long)plVar11 + 0x32c) = bVar5 & 1;
        __mutex_init(plVar11 + 0x8c,"&mdwc->suspend_resume_mutex",&dwc3_msm_probe___key);
        __mutex_init(plVar11 + 0x92,"&mdwc->role_switch_mutex",&dwc3_msm_probe___key_160);
        lVar22 = of_find_property(uVar21,"usb-role-switch",0);
        if (lVar22 == 0) {
LAB_001076f4:
          lVar22 = of_find_property(uVar21,"extcon",0);
          if (lVar22 == 0) {
LAB_00107ac0:
            if ((plVar11[0xa1] == 0) &&
               ((plVar11[0x68] == 0 ||
                (iVar6 = dwc3_msm_extcon_is_valid_source(plVar11), iVar6 == 0)))) {
              if (*(int *)((long)plVar11 + 0x2dc) == 1) {
LAB_00107d1c:
                *(undefined4 *)(plVar11 + 99) = 0;
              }
              else if (*(int *)((long)plVar11 + 0x2dc) == 3) {
                lVar18 = of_find_property(uVar21,"qcom,default-mode-host",0);
                if (lVar18 != 0) {
                  _dev_info(*plVar11,"%s: start host mode\n","dwc3_msm_probe");
                  goto LAB_00107d1c;
                }
                lVar18 = of_find_property(uVar21,"qcom,default-mode-none",0);
                if (lVar18 == 0) {
                  _dev_info(*plVar11,"%s: start peripheral mode\n","dwc3_msm_probe");
                  goto LAB_00107af0;
                }
                _dev_info(*plVar11,"%s: stay in none mode\n","dwc3_msm_probe");
              }
              else {
LAB_00107af0:
                *(undefined1 *)((long)plVar11 + 0x312) = 1;
              }
              dwc3_ext_event_notify(plVar11);
            }
            *(undefined1 *)(plVar11 + 0x166) = 0;
            if ((int)plVar11[0x73] != 0) {
              cpu_latency_qos_add_request(plVar11 + 0x75,0xffffffff);
            }
            lVar18 = of_find_property(uVar21,"qcom,force-adb-enable",0);
            if (lVar18 != 0) {
              _dev_err(*plVar11,"%s: force usb start device mode\n","dwc3_msm_probe");
              dwc3_start_stop_device(plVar11,1);
            }
            uVar26 = 0;
            goto LAB_00107d5c;
          }
          uVar7 = of_count_phandle_with_args(*(undefined8 *)(*plVar11 + 0x2e8),"extcon",0);
          lVar22 = *plVar11;
          if ((int)uVar7 < 0) {
            pcVar19 = "of_count_phandle_with_args failed\n";
          }
          else {
            lVar22 = devm_kmalloc(lVar22,((ulong)uVar7 + (ulong)uVar7 * 4) * 0x10,0xdc0);
            plVar11[0x68] = lVar22;
            if (lVar22 == 0) {
              uVar26 = 0xfffffff4;
              goto LAB_001079fc;
            }
            if (uVar7 != 0) {
              iVar6 = 0;
              lVar22 = 0;
              bVar25 = false;
              do {
                uVar24 = extcon_get_edev_by_phandle(*plVar11,iVar6);
                if (uVar24 < 0xfffffffffffff001) {
                  if (uVar24 != 0) {
                    *(long **)(plVar11[0x68] + lVar22 + 8) = plVar11;
                    *(ulong *)(plVar11[0x68] + lVar22) = uVar24;
                    *(int *)(plVar11[0x68] + lVar22 + 0x10) = iVar6;
                    pcVar19 = (char *)extcon_get_edev_name(uVar24);
                    sVar17 = strlen(pcVar19);
                    lVar13 = strnstr(pcVar19,&DAT_00110dab,sVar17);
                    if (lVar13 != 0) {
                      *(undefined1 *)(plVar11[0x68] + lVar22 + 0x48) = 1;
                    }
                    *(code **)(plVar11[0x68] + lVar22 + 0x18) = dwc3_msm_vbus_notifier;
                    iVar9 = extcon_register_notifier(uVar24,1,plVar11[0x68] + lVar22 + 0x18);
                    *(code **)(plVar11[0x68] + lVar22 + 0x30) = dwc3_msm_id_notifier;
                    iVar10 = extcon_register_notifier(uVar24,2,plVar11[0x68] + lVar22 + 0x30);
                    if ((iVar9 < 0) || (iVar9 = extcon_get_state(uVar24,1), iVar9 == 0)) {
                      if ((iVar10 < 0) || (iVar9 = extcon_get_state(uVar24,2), iVar9 == 0)) {
                        bVar25 = true;
                      }
                      else {
                        bVar25 = true;
                        dwc3_msm_id_notifier(plVar11[0x68] + lVar22 + 0x30,1,uVar24);
                      }
                    }
                    else {
                      bVar25 = true;
                      dwc3_msm_vbus_notifier(plVar11[0x68] + lVar22 + 0x18,1,uVar24);
                    }
                  }
                }
                else if (uVar24 != 0xffffffffffffffed) {
                  uVar26 = uVar24 & 0xffffffff;
                  if ((int)uVar24 != 0) goto LAB_001079fc;
                  goto LAB_001078d8;
                }
                lVar22 = lVar22 + 0x50;
                iVar6 = iVar6 + 1;
              } while ((ulong)uVar7 * 0x50 != lVar22);
              if (bVar25) {
LAB_001078d8:
                uVar26 = devm_regulator_get_optional(lVar18,&DAT_001134fa);
                plVar11[0x9e] = uVar26;
                if (uVar26 < 0xfffffffffffff001) {
                  if (((*(char *)((long)plVar11 + 0x312) == '\0') && (uVar26 != 0)) &&
                     (iVar6 = regulator_is_enabled(), iVar6 != 0)) {
                    plVar11[0x9b] = (long)dwc_dpdm_cb;
                    regulator_register_notifier(plVar11[0x9e],plVar11 + 0x9b);
                    goto LAB_00107ac0;
                  }
                }
                else {
                  _dev_info(*plVar11,"assume cable is not connected\n");
                  plVar11[0x9e] = 0;
                }
                if (plVar11[0xa1] == 0) {
                  queue_work_on(0x20,plVar11[0x53],plVar11 + 0x54);
                }
                goto LAB_00107ac0;
              }
            }
            lVar22 = *plVar11;
            pcVar19 = "no extcon device found\n";
          }
          _dev_err(lVar22,pcVar19);
          uVar26 = 0xffffffed;
        }
        else {
          local_a8 = 0;
          local_a0 = 0;
          local_b8 = (char *)0x0;
          local_b0 = 0;
          local_98 = dwc3_msm_usb_role_switch_set_role;
          pcStack_90 = dwc3_msm_usb_role_switch_get_role;
          local_88 = 1;
          local_78 = 0;
          *(undefined1 *)(plVar11 + 0x5c) = 1;
          plStack_80 = plVar11;
          dwc3_msm_set_role(plVar11,0);
          local_b8 = (char *)dev_fwnode(lVar18);
          uVar26 = usb_role_switch_register(*plVar11,&local_b8);
          plVar11[0xa1] = uVar26;
          if (uVar26 < 0xfffffffffffff001) goto LAB_001076f4;
          uVar26 = uVar26 & 0xffffffff;
        }
LAB_001079fc:
        usb_role_switch_unregister(plVar11[0xa1]);
        icc_put(plVar11[0x5e]);
        icc_put(plVar11[0x5f]);
        icc_put(plVar11[0x60]);
      }
    }
LAB_00107a1c:
    destroy_workqueue(plVar11[0x53]);
    destroy_workqueue(plVar11[0x52]);
    usb_put_redriver(plVar11[0x3a]);
  }
  else {
    lVar22 = *plVar11;
    *(undefined1 *)((long)plVar11 + 0xb31) = 1;
    uVar7 = of_count_phandle_with_args(*(undefined8 *)(lVar22 + 0x2e8),"power-domains",0);
    *(uint *)((long)plVar11 + 0xb34) = uVar7;
    if ((int)uVar7 < 2) {
      uVar26 = 0xffffffea;
    }
    else {
      lVar13 = devm_kmalloc(lVar22,(ulong)uVar7 << 3,0xdc0);
      plVar11[0x167] = lVar13;
      if (lVar13 != 0) {
        if (0 < *(int *)((long)plVar11 + 0xb34)) {
          uVar24 = 0;
          do {
            uVar12 = dev_pm_domain_attach_by_id(lVar22,uVar24 & 0xffffffff);
            *(undefined8 *)(plVar11[0x167] + uVar24 * 8) = uVar12;
            uVar26 = *(ulong *)(plVar11[0x167] + uVar24 * 8);
            if (0xfffffffffffff000 < uVar26) {
              if ((int)uVar26 != 0) goto LAB_00106c88;
              break;
            }
            uVar24 = uVar24 + 1;
          } while ((long)uVar24 < (long)*(int *)((long)plVar11 + 0xb34));
        }
        goto LAB_00106520;
      }
      uVar26 = 0xfffffff4;
    }
LAB_00106c88:
    _dev_err(lVar18,"Failed to attach domains. Bail out\n");
  }
  if (*(char *)((long)plVar11 + 0xb31) != '\0') {
    if (*(int *)((long)plVar11 + 0xb34) < 2) {
      _dev_err(*plVar11,"%s: PD count invalid\n","dwc3_msm_modeled_domain_detach");
    }
    else {
      uVar7 = *(int *)((long)plVar11 + 0xb34) - 1;
      do {
        uVar24 = *(ulong *)(plVar11[0x167] + (ulong)uVar7 * 8);
        if ((uVar24 != 0) && (uVar24 < 0xfffffffffffff001)) {
          dev_pm_domain_detach(uVar24,1);
        }
        uVar7 = uVar7 - 1;
      } while (-1 < (int)uVar7);
    }
  }
LAB_00107d5c:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar26 & 0xffffffff;
}



//------------------------------------------------------------
// dwc3_msm_remove @ 00107e98 size=1284
// signature: undefined dwc3_msm_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 dwc3_msm_remove(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  int iVar8;
  uint uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  
  puVar12 = *(undefined8 **)(param_1 + 0xa8);
  uVar10 = *(undefined8 *)(puVar12[5] + 0xa8);
  if (diag_dload != 0) {
    iounmap();
  }
  usb_role_switch_unregister(puVar12[0xa1]);
  if (puVar12[0x9b] != 0) {
    regulator_unregister_notifier(puVar12[0x9e],puVar12 + 0x9b);
    puVar12[0x9b] = 0;
  }
  iVar5 = __pm_runtime_resume(*puVar12,4);
  dwc3_dbg_print(puVar12[0xa5],0xff,"Remov gsyn",iVar5,&DAT_00111364);
  if (iVar5 < 0) {
    _dev_err(*puVar12,"pm_runtime_get_sync failed with %d\n",iVar5);
    if (*(char *)((long)puVar12 + 0xb31) == '\0') {
      uVar11 = puVar12[0x34];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
      uVar11 = puVar12[0x30];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
      uVar11 = puVar12[0x2a];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
      uVar11 = puVar12[0x2e];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
      uVar11 = puVar12[0x2f];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
      uVar11 = puVar12[0x33];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
      uVar11 = puVar12[0x29];
      iVar5 = clk_prepare(uVar11);
      if ((iVar5 == 0) && (iVar5 = clk_enable(uVar11), iVar5 != 0)) {
        clk_unprepare(uVar11);
      }
    }
    else {
      lVar6 = *(long *)puVar12[0x167];
      iVar5 = __pm_runtime_resume(lVar6,4);
      if (iVar5 < 0) {
        piVar1 = (int *)(lVar6 + 0x1f8);
        iVar8 = *(int *)(lVar6 + 0x1f8);
        do {
          if (iVar8 == 0) break;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar8) goto LAB_00108210;
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = iVar8 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_00108210:
          bVar4 = iVar8 != iVar2;
          iVar8 = iVar2;
        } while (bVar4);
        _dev_err(*puVar12,"power state transit failed d1 to d0 with %d\n",iVar5);
      }
    }
  }
  lVar6 = irq_to_desc(*(undefined4 *)(puVar12 + 0x44));
  if ((((*(char *)((long)puVar12 + 0xb31) == '\0') && (lVar6 != 0)) &&
      (*(int *)((long)puVar12 + 0x39c) != 0)) &&
     (cancel_delayed_work_sync(puVar12 + 0x7b), *(char *)(puVar12 + 0x62) != '\0')) {
    cpu_latency_qos_update_request(puVar12 + 0x75,0xffffffff);
    *(undefined1 *)(puVar12 + 0x62) = 0;
  }
  cancel_work_sync(puVar12 + 0x54);
  if (*(int *)(puVar12 + 0x73) != 0) {
    cpu_latency_qos_remove_request(puVar12 + 0x75);
  }
  lVar6 = puVar12[0x38];
  if (lVar6 != 0) {
    *(uint *)(lVar6 + 0x10) = *(uint *)(lVar6 + 0x10) & 0xfffffffe;
  }
  dwc3_msm_notify_event(uVar10,0xe,0);
  platform_device_put(puVar12[5]);
  of_platform_depopulate(param_1 + 0x10);
  usb_put_redriver(puVar12[0x3a]);
  dwc3_dbg_print(puVar12[0xa5],0xff,"Remov put",0,&DAT_00111364);
  __pm_runtime_disable(*puVar12,1);
  pm_runtime_barrier(*puVar12);
  __pm_runtime_idle(*puVar12,4);
  __pm_runtime_set_status(*puVar12,2);
  device_wakeup_disable(*puVar12);
  icc_put(puVar12[0x5e]);
  icc_put(puVar12[0x5f]);
  icc_put(puVar12[0x60]);
  if (puVar12[0x3d] != 0) {
    regulator_disable();
  }
  if (*(int *)(puVar12 + 0x3f) != 0) {
    disable_irq();
  }
  if (*(int *)(puVar12 + 0x41) != 0) {
    disable_irq();
  }
  if (*(int *)(puVar12 + 0x42) != 0) {
    disable_irq();
  }
  if (*(int *)(puVar12 + 0x43) != 0) {
    disable_irq();
  }
  disable_irq(*(undefined4 *)(puVar12 + 0x40));
  if (*(char *)((long)puVar12 + 0xb31) == '\0') {
    uVar10 = puVar12[0x30];
    clk_disable(uVar10);
    clk_unprepare(uVar10);
    clk_set_rate(puVar12[0x2a],19200000);
    uVar10 = puVar12[0x2a];
    clk_disable(uVar10);
    clk_unprepare(uVar10);
    uVar10 = puVar12[0x2e];
    clk_disable(uVar10);
    clk_unprepare(uVar10);
    uVar10 = puVar12[0x2f];
    clk_disable(uVar10);
    clk_unprepare(uVar10);
    uVar10 = puVar12[0x29];
    clk_disable(uVar10);
    clk_unprepare(uVar10);
    if (((*(char *)((long)puVar12 + 0xb31) == '\0') && (puVar12[0x37] != 0)) &&
       ((ulong)puVar12[0x37] < 0xfffffffffffff001)) {
      qcom_clk_set_flags(puVar12[0x2a],3);
      iVar5 = regulator_disable(puVar12[0x37]);
      if (iVar5 != 0) {
        _dev_err(*puVar12,"unable to disable usb3 gdsc\n");
      }
    }
  }
  else {
    __pm_runtime_idle(*(undefined8 *)puVar12[0x167],4);
    iVar5 = __pm_runtime_idle(*(undefined8 *)puVar12[0x167],4);
    if (iVar5 == 0) {
      __pm_runtime_idle(*(undefined8 *)(puVar12[0x167] + 8),4);
    }
  }
  destroy_workqueue(puVar12[0x53]);
  destroy_workqueue(puVar12[0x52]);
  ipc_log_context_destroy(puVar12[0xa5]);
  ipc_log_context_destroy(puVar12[0xa6]);
  debugfs_remove(puVar12[0x14b]);
  if (*(char *)((long)puVar12 + 0xb31) != '\0') {
    if (*(int *)((long)puVar12 + 0xb34) < 2) {
      _dev_err(*puVar12,"%s: PD count invalid\n","dwc3_msm_modeled_domain_detach");
    }
    else {
      uVar9 = *(int *)((long)puVar12 + 0xb34) - 1;
      do {
        uVar7 = *(ulong *)(puVar12[0x167] + (ulong)uVar9 * 8);
        if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
          dev_pm_domain_detach(uVar7,1);
        }
        uVar9 = uVar9 - 1;
      } while (-1 < (int)uVar9);
    }
  }
  kfree(puVar12[0x70]);
  kfree(puVar12[0x6f]);
  return 0;
}



//------------------------------------------------------------
// dwc3_resume_work @ 001083b4 size=812
// signature: undefined dwc3_resume_work(void)
// callers: [dwc3_restart_usb_work, msm_dwc3_pwr_irq_thread]
//------------------------------------------------------------

void dwc3_resume_work(long param_1)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined8 *puVar8;
  undefined8 uVar9;
  long *plVar10;
  long lVar11;
  int local_50 [2];
  long local_48;
  
  lVar11 = sp_el0;
  puVar8 = (undefined8 *)(param_1 + -0x228);
  local_48 = *(long *)(lVar11 + 0x638);
  local_50[0] = 0;
  _dev_info(*puVar8,"%s: dwc3 resume work\n","dwc3_resume_work");
  ipc_log_string(*(undefined8 *)(param_1 + 0x300),"%s: resume_work: ext_idx:%d\n","dwc3_resume_work"
                 ,*(undefined4 *)(param_1 + 0x120));
  if (*(long *)(param_1 + 0x118) == 0) {
LAB_0010843c:
    bVar2 = false;
    lVar11 = 0;
    uVar9 = 0;
LAB_00108448:
    if (*(char *)(param_1 + 0x2f0) == '\0') {
      if (*(long *)(param_1 + -0x200) == 0) {
        *(undefined4 *)(param_1 + 0x298) = *(undefined4 *)(param_1 + 0x29c);
      }
      else {
        *(undefined4 *)(*(long *)(*(long *)(param_1 + -0x200) + 0xa8) + 0x45c) =
             *(undefined4 *)(param_1 + 0x29c);
      }
    }
    if (((bVar2) && (iVar3 = extcon_get_state(lVar11,uVar9), iVar3 != 0)) &&
       (iVar3 = extcon_get_property(lVar11,uVar9,2,local_50), iVar3 == 0 && local_50[0] == 0)) {
      uVar7 = *(uint *)(param_1 + 0x29c);
      if (2 < uVar7) {
        uVar7 = 3;
      }
      if (*(long *)(param_1 + -0x200) == 0) {
        *(uint *)(param_1 + 0x298) = uVar7;
      }
      else {
        *(uint *)(*(long *)(*(long *)(param_1 + -0x200) + 0xa8) + 0x45c) = uVar7;
      }
    }
    if (*(long *)(param_1 + -0x200) == 0) {
      puVar5 = (uint *)(param_1 + 0x298);
    }
    else {
      puVar5 = (uint *)(*(long *)(*(long *)(param_1 + -0x200) + 0xa8) + 0x45c);
    }
    if (4 < *puVar5) {
      dwc3_set_ssphy_orientation_flag(puVar8);
    }
  }
  else {
    if ((*(char *)(param_1 + 0xea) == '\0') || (*(char *)(param_1 + 0x60) != '\0')) {
      if (*(int *)(param_1 + 0xf0) != 0) goto LAB_0010843c;
      uVar9 = 2;
    }
    else {
      uVar9 = 1;
    }
    lVar11 = *(long *)(*(long *)(param_1 + 0x118) + (long)*(int *)(param_1 + 0x120) * 0x50);
    if (lVar11 == 0) {
      bVar2 = false;
      goto LAB_00108448;
    }
    uVar4 = extcon_get_edev_name(lVar11);
    ipc_log_string(*(undefined8 *)(param_1 + 0x300),"%s: edev:%s\n","dwc3_resume_work",uVar4);
    bVar2 = true;
    if (*(char *)(*(long *)(param_1 + 0x118) + (long)*(int *)(param_1 + 0x120) * 0x50 + 0x48) ==
        '\0') goto LAB_00108448;
  }
  plVar10 = (long *)(param_1 + -0x200);
  if (*plVar10 == 0) {
    puVar6 = (undefined4 *)(param_1 + 0x298);
  }
  else {
    puVar6 = (undefined4 *)(*(long *)(*plVar10 + 0xa8) + 0x45c);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x300),
                 "%s: max_speed:%d hw_supp_speed:%d override_speed:%d","dwc3_resume_work",*puVar6,
                 *(undefined4 *)(param_1 + 0x29c),*(undefined4 *)(param_1 + 0x298));
  uVar7 = *(uint *)(param_1 + 0x298);
  if (uVar7 != 0) {
    if (*plVar10 == 0) {
      uVar1 = *(uint *)(param_1 + 0x29c);
      if (uVar7 <= *(uint *)(param_1 + 0x29c)) {
        uVar1 = uVar7;
      }
      *(uint *)(param_1 + 0x298) = uVar1;
    }
    else {
      lVar11 = *(long *)(*plVar10 + 0xa8);
      if (uVar7 <= *(uint *)(lVar11 + 0x45c)) {
        uVar1 = *(uint *)(param_1 + 0x29c);
        if (uVar7 <= *(uint *)(param_1 + 0x29c)) {
          uVar1 = uVar7;
        }
        *(uint *)(lVar11 + 0x45c) = uVar1;
      }
    }
  }
  if (*plVar10 == 0) {
    puVar6 = (undefined4 *)(param_1 + 0x298);
  }
  else {
    puVar6 = (undefined4 *)(*(long *)(*plVar10 + 0xa8) + 0x45c);
  }
  dwc3_dbg_print(*(undefined8 *)(param_1 + 0x300),0xff,"speed",*puVar6,&DAT_00111364);
  if (*(int *)(param_1 + 0xb0) != 0) {
    bVar2 = true;
  }
  if (bVar2) {
    if (*(char *)(param_1 + -0x38) != '\0') goto LAB_00108674;
    iVar3 = *(int *)(param_1 + -0x34);
  }
  else {
    if (*(char *)(param_1 + -0x38) == '\0') goto LAB_001086ac;
LAB_00108674:
    __pm_runtime_resume(*puVar8,0);
    *(undefined1 *)(param_1 + -0x38) = 0;
    _dev_info(*puVar8,"%s: set resume_pending to false\n","dwc3_resume_work");
    iVar3 = *(int *)(param_1 + -0x34);
  }
  if (iVar3 == 0) {
    dwc3_ext_event_notify(puVar8);
  }
  else {
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x300),0xff,"RWrk PMSus",0,&DAT_00111364);
  }
LAB_001086ac:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dwc3_restart_usb_work @ 001086e4 size=512
// signature: undefined dwc3_restart_usb_work(void)
// callers: []
//------------------------------------------------------------

void dwc3_restart_usb_work(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = (long *)(param_1 + -600);
  if (*(int *)(param_1 + 0x118) == 0) {
    lVar1 = param_1 + 0x238;
    mutex_lock(lVar1);
    if (*(char *)(param_1 + 0xba) == '\0') {
      iVar3 = *(int *)(param_1 + 0xc0);
      mutex_unlock(lVar1);
      if (iVar3 == 0) {
        if (((uint)*(undefined8 *)
                    (*(long *)(*(long *)(*(long *)(*(long *)(param_1 + -0x230) + 0xa8) + 0x1a0) +
                              0xa8) + 0x198) >> 6 & 1) != 0) {
          mutex_lock(lVar1);
          if ((*(int *)(param_1 + 0xc0) != 1) &&
             (iVar3 = dwc3_start_stop_host(plVar4,0), iVar3 == 0)) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x2d0),"%s: start host mode",
                           "dwc3_start_stop_host");
            *(undefined4 *)(param_1 + 0xc0) = 0;
            *(undefined1 *)(param_1 + 0xba) = 0;
            dwc3_ext_event_notify(plVar4);
          }
          mutex_unlock(lVar1);
        }
      }
      else {
        _dev_err(*plVar4,"incorrect role during restart\n");
      }
    }
    else {
      mutex_unlock(lVar1);
      *(undefined1 *)(param_1 + 0x30) = 1;
      if (*(char *)(param_1 + 0xba) == '\0') {
        _dev_info(*plVar4,"%s bailing out in disconnect\n","dwc3_msm_restart_usb_gadget");
        *(undefined1 *)(param_1 + 0x2c8) = 0;
        *(undefined1 *)(param_1 + 0x30) = 0;
      }
      else {
        dwc3_dbg_print(*(undefined8 *)(param_1 + 0x2d0),0xff,"RestartUSB",0,&DAT_00111364);
        dwc3_resume_work(param_1 + -0x30);
        iVar3 = -0x31;
        do {
          if ((*(int *)(*plVar4 + 0x20c) == 2) && ((*(ushort *)(*plVar4 + 0x200) & 7) == 0))
          goto LAB_00108794;
          msleep(0x14);
          bVar2 = iVar3 != -1;
          iVar3 = iVar3 + 1;
        } while (bVar2);
        _dev_info(*plVar4,"Not in LPM after disconnect, forcing suspend...\n");
        dwc3_dbg_print(*(undefined8 *)(param_1 + 0x2d0),0xff,"ReStart:RT SUSP",
                       *(undefined4 *)(*plVar4 + 0x1f8),&DAT_00111364);
        __pm_runtime_suspend(*plVar4,0);
LAB_00108794:
        *(undefined1 *)(param_1 + 0x30) = 0;
        if (*(char *)(param_1 + 0xba) != '\0') {
          dwc3_resume_work(param_1 + -0x30);
        }
        *(undefined1 *)(param_1 + 0x2c8) = 0;
        flush_work(param_1 + 0x48);
      }
    }
  }
  else {
    _dev_info(*plVar4,"%s failed!!!\n","dwc3_restart_usb_work");
  }
  return;
}



//------------------------------------------------------------
// dwc3_otg_sm_work @ 001088e8 size=2440
// signature: undefined dwc3_otg_sm_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dwc3_otg_sm_work(long param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  ulong *puVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  long lVar11;
  undefined8 *__dest;
  void *__src;
  uint *puVar12;
  ulong uVar13;
  undefined8 uVar14;
  long *plVar15;
  char *pcVar16;
  long lVar17;
  long *plVar18;
  
  plVar18 = (long *)(param_1 + -0x278);
  plVar15 = (long *)(param_1 + -0x2a0);
  if ((*plVar18 == 0) || (lVar17 = *(long *)(*plVar18 + 0xa8), lVar17 == 0)) {
    if (*(int *)(param_1 + 0x38) != 0) {
      _dev_err(*plVar15,"dwc is NULL.\n");
      return;
    }
    lVar17 = 0;
    uVar10 = 0;
LAB_00108964:
    if (4 < uVar10) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(1,0x109280);
      (*pcVar7)();
    }
    pcVar16 = (&state_names)[uVar10];
  }
  else {
    uVar10 = *(uint *)(param_1 + 0x38);
    if (uVar10 < 5) goto LAB_00108964;
    pcVar16 = "UNKNOWN";
  }
  _dev_info(*plVar15,"%s state\n",pcVar16);
  dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,pcVar16,0,&DAT_00111364);
  puVar1 = (undefined4 *)(param_1 + 0x38);
  switch(*puVar1) {
  case 0:
    break;
  case 1:
switchD_001089c8_caseD_1:
    if (((uint)*(undefined8 *)(param_1 + 0x30) >> 3 & 1) != 0) {
      _dev_info(*plVar15,"still not in lpm, wait.\n");
      dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"WAIT_FOR_LPM",0,&DAT_00111364);
      return;
    }
    if ((*(ulong *)(param_1 + 0x30) & 1) == 0) {
      _dev_info(*plVar15,&DAT_0011139a);
      *puVar1 = 4;
      iVar9 = dwc3_otg_start_host(plVar15,1);
      if (iVar9 == 0) {
        return;
      }
      _dev_err(*plVar15,"unable to start host\n");
      *puVar1 = 1;
      return;
    }
    if (((uint)*(undefined8 *)(param_1 + 0x30) >> 1 & 1) == 0) {
      return;
    }
    _dev_info(*plVar15,"b_sess_vld\n");
    iVar9 = pm_runtime_resume_and_get(*plVar15);
    if (iVar9 < 0) {
LAB_00109148:
      _dev_err(*plVar15,"%s: pm_runtime_resume_and_get failed\n","dwc3_otg_sm_work");
      __pm_runtime_set_status(*plVar15,2);
      return;
    }
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"BIDLE gsync",
                   *(undefined4 *)(*plVar15 + 0x1f8),&DAT_00111364);
    dwc3_otg_start_peripheral(plVar15,1);
    *(undefined4 *)(param_1 + 0x38) = 2;
    goto LAB_00109250;
  case 2:
    if ((((uint)*(undefined8 *)(param_1 + 0x30) >> 1 & 1) == 0) ||
       ((*(ulong *)(param_1 + 0x30) & 1) == 0)) {
      _dev_info(*plVar15,"!id || !bsv\n");
      *(undefined4 *)(param_1 + 0x38) = 1;
      dwc3_otg_start_peripheral(plVar15,0);
      __pm_runtime_suspend(*plVar15,4);
      dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"!BSV psync",
                     *(undefined4 *)(*plVar15 + 0x1f8),&DAT_00111364);
      goto LAB_00109250;
    }
    if ((((uint)*(undefined8 *)(param_1 + 0x30) >> 2 & 1) != 0) &&
       (((uint)*(undefined8 *)(param_1 + 0x30) >> 1 & 1) != 0)) {
      _dev_info(*plVar15,"BPER bsv && susp\n");
      lVar17 = *plVar15;
      *(undefined4 *)(param_1 + 0x38) = 3;
      uVar14 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar17 + 0x220) = uVar14;
      __pm_runtime_suspend(*plVar15,0xd);
      lVar17 = *plVar15;
      pcVar16 = "SUSP put";
      goto LAB_00108ec4;
    }
    puVar3 = (ulong *)(param_1 + 0x30);
    Hint_Prefetch(puVar3,2,0,1);
    do {
      uVar13 = *puVar3;
      cVar6 = '\x01';
      bVar8 = (bool)ExclusiveMonitorPass(puVar3,0x10);
      if (bVar8) {
        *puVar3 = uVar13 & 0xffffffffffffffef;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    DataMemoryBarrier(2,3);
    if (((uint)uVar13 >> 4 & 1) == 0) {
      return;
    }
    if (*(char *)(param_1 + 0x7b1) == '\0') {
      return;
    }
    uVar10 = *(uint *)(*(long *)(lVar17 + 0x370) + 0x58);
    if (uVar10 < 5) {
      if (uVar10 != 3) {
        bVar8 = *(char *)(param_1 + 0x73) != '\0';
        goto LAB_00108db4;
      }
    }
    else if (*(char *)(param_1 + 0x73) == '\0') {
      wcd_usbss_dpdm_switch_update(0,0);
      return;
    }
    bVar8 = true;
LAB_00108db4:
    wcd_usbss_dpdm_switch_update(1,bVar8);
    return;
  case 3:
    if (((uint)*(undefined8 *)(param_1 + 0x30) >> 1 & 1) == 0) {
      _dev_info(*plVar15,"BSUSP: !bsv\n");
      *puVar1 = 1;
      dwc3_otg_start_peripheral(plVar15,0);
      return;
    }
    if (((uint)*(undefined8 *)(param_1 + 0x30) >> 2 & 1) != 0) {
      return;
    }
    _dev_info(*plVar15,"BSUSP !susp\n");
    *puVar1 = 2;
    iVar9 = pm_runtime_resume_and_get(*plVar15);
    if (-1 < iVar9) {
      lVar17 = *plVar15;
      pcVar16 = "!SUSP gsync";
LAB_00108ec4:
      dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,pcVar16,*(undefined4 *)(lVar17 + 0x1f8),
                     &DAT_00111364);
      return;
    }
    goto LAB_00109148;
  case 4:
    if ((*(ulong *)(param_1 + 0x30) & 1) == 0) {
      if (*(int *)(lVar17 + 0x3ec) != 1) {
        return;
      }
      _dev_info(*plVar15,"still in a_host state. Resuming root hub.\n");
      dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"XHCIResume",0,&DAT_00111364);
      iVar9 = __pm_runtime_resume(*(long *)(lVar17 + 0x1a0) + 0x10,0);
      if (iVar9 < 1) {
        return;
      }
      uVar14 = *(undefined8 *)(param_1 + 0x288);
      uVar10 = hrtimer_active(*(long *)(lVar17 + 0x1a0) + 0x168);
      dwc3_dbg_print(uVar14,0xff,"RT active",uVar10 & 1,&DAT_00111364);
      __pm_runtime_idle(*(long *)(lVar17 + 0x1a0) + 0x10,1);
      return;
    }
    _dev_info(*plVar15,&DAT_00110bbe);
    dwc3_otg_start_host(plVar15,0);
    *puVar1 = 1;
    goto LAB_00109250;
  default:
    _dev_err(*plVar15,"%s: invalid otg-state\n","dwc3_otg_sm_work");
    return;
  }
  if (*(long *)(param_1 + 0x238) != 0) {
    regulator_unregister_notifier(*(undefined8 *)(param_1 + 0x250),param_1 + 0x238);
    *(undefined8 *)(param_1 + 0x238) = 0;
  }
  pm_runtime_enable(*plVar15);
  lVar17 = *plVar15;
  iVar9 = __pm_runtime_resume(lVar17,4);
  if (iVar9 < 0) {
    piVar2 = (int *)(lVar17 + 0x1f8);
    iVar9 = *(int *)(lVar17 + 0x1f8);
    do {
      if (iVar9 == 0) break;
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar5 = *piVar2;
        if (iVar5 != iVar9) goto LAB_00108e54;
        cVar6 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar8) {
          *piVar2 = iVar9 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      DataMemoryBarrier(2,3);
LAB_00108e54:
      bVar8 = iVar9 != iVar5;
      iVar9 = iVar5;
    } while (bVar8);
    goto LAB_00109148;
  }
  if (*plVar18 != 0) goto LAB_00108f74;
  uVar14 = *(undefined8 *)(*plVar15 + 0x2e8);
  uVar10 = readl(*(undefined8 *)(param_1 + -0x298));
  *(uint *)(param_1 + 0x8a0) = uVar10 & 0xff;
  if ((*(long *)(param_1 + -0xe0) == 0) ||
     (pcVar7 = *(code **)(*(long *)(param_1 + -0xe0) + 0x118), pcVar7 == (code *)0x0)) {
LAB_00108a58:
    if (*plVar18 == 0) {
      puVar12 = (uint *)(param_1 + 0x220);
    }
    else {
      puVar12 = (uint *)(*(long *)(*plVar18 + 0xa8) + 0x45c);
    }
    if (((4 < *puVar12) && (*(long *)(param_1 + -0xd8) != 0)) &&
       (pcVar7 = *(code **)(*(long *)(param_1 + -0xd8) + 0x118), pcVar7 != (code *)0x0)) {
      if (*(int *)(pcVar7 + -4) != 0x3c72446d) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x108bfc);
        (*pcVar7)();
      }
      iVar9 = (*pcVar7)();
      if (iVar9 != 0) {
        lVar17 = *plVar15;
        pcVar16 = "failed to init SS PHY\n";
        goto LAB_00109214;
      }
    }
    lVar17 = of_get_next_available_child(uVar14,0);
    if (lVar17 == 0) {
      _dev_err(*plVar15,"failed to find dwc3 child\n");
      iVar9 = -0x13;
    }
    else {
      iVar9 = of_platform_populate(uVar14,0,0);
      if (iVar9 != 0) {
        lVar17 = *plVar15;
        pcVar16 = "failed to add create dwc3 core\n";
        goto LAB_00109214;
      }
      lVar17 = of_find_device_by_node(lVar17);
      *plVar18 = lVar17;
      if (lVar17 == 0) {
        _dev_err(*plVar15,"failed to get dwc3 platform device\n");
      }
      else {
        lVar17 = *(long *)(lVar17 + 0xa8);
        if (lVar17 != 0) {
          uVar4 = *(uint *)(param_1 + 0x220);
          uVar10 = *(uint *)(lVar17 + 0x45c);
          if (uVar4 - 1 < uVar10) {
            uVar10 = *(uint *)(param_1 + 0x224);
            if (uVar4 <= *(uint *)(param_1 + 0x224)) {
              uVar10 = uVar4;
            }
            *(uint *)(lVar17 + 0x45c) = uVar10;
          }
          if ((4 < uVar10) && (*(int *)(param_1 + -0x88) == 0)) {
            *(ulong *)(param_1 + 0x80) = *(ulong *)(param_1 + 0x80) | 1;
          }
          if ((*(char *)(param_1 + 0x75) == '\0') && (*(int *)(param_1 + -0xa8) == 0)) {
            *(ulong *)(param_1 + 0x80) = *(ulong *)(param_1 + 0x80) | 2;
          }
          lVar11 = of_find_property(uVar14,"qcom,host-poweroff-in-pm-suspend",0);
          if (lVar11 != 0) {
            *(undefined1 *)(param_1 + 0x88) = 1;
            _dev_info(*plVar15,"%s: Core power collapse on host PM suspend\n","dwc3_msm_core_init");
          }
          dev_fwnode(*(undefined8 *)(lVar17 + 400));
          uVar13 = usb_role_switch_find_by_fwnode();
          *(ulong *)(param_1 + 0x270) = uVar13;
          if (uVar13 < 0xfffffffffffff001) {
            __dest = (undefined8 *)kmalloc_trace(___list_add_valid,0xb20,0xc0);
            *(undefined8 **)(param_1 + 0xd8) = __dest;
            if (__dest != (undefined8 *)0x0) {
              lVar11 = *(long *)(lVar17 + 400);
              if ((*(long *)(lVar11 + 0x88) == 0) ||
                 (__src = *(void **)(*(long *)(lVar11 + 0x88) + 0x78), __src == (void *)0x0)) {
                _dev_err(lVar11,"can\'t override PM OPs\n");
                cVar6 = *(char *)(param_1 + 0x8c);
              }
              else {
                memcpy(__dest,__src,0xc0);
                *__dest = dwc3_core_prepare;
                __dest[1] = dwc3_core_complete;
                *(undefined8 **)(*(long *)(lVar11 + 0x88) + 0x78) = __dest;
                cVar6 = *(char *)(param_1 + 0x8c);
              }
              if ((cVar6 == '\0') && (*(char *)(param_1 + 0x8a) != '\0')) {
                *(byte *)(*(long *)(lVar17 + 400) + 0x150) =
                     *(byte *)(*(long *)(lVar17 + 400) + 0x150) | 2;
              }
              lVar11 = kmalloc_trace(___list_add_valid,0xb20,0xc0);
              *(long *)(param_1 + 0xe0) = lVar11;
              if (lVar11 != 0) {
                dwc3_msm_notify_event(lVar17,10,0);
                pm_runtime_set_autosuspend_delay(*(undefined8 *)(lVar17 + 400),0);
                pm_runtime_allow(*(undefined8 *)(lVar17 + 400));
                goto LAB_00108f74;
              }
              kfree(*(undefined8 *)(param_1 + 0xd8));
            }
            of_platform_depopulate(*plVar15);
          }
          else {
            _dev_err(*plVar15,"failed to find dwc3 drd role switch\n");
            iVar9 = *(int *)(param_1 + 0x270);
            of_platform_depopulate(*plVar15);
            if (iVar9 != 0) goto LAB_00109218;
          }
LAB_00108f74:
          *(undefined4 *)(param_1 + 0x38) = 1;
          if (((*(ulong *)(param_1 + 0x30) & 1) != 0) &&
             (((uint)*(undefined8 *)(param_1 + 0x30) >> 1 & 1) == 0)) {
            dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"undef_id_!bsv",0,&DAT_00111364);
            __pm_runtime_idle(*plVar15,4);
            dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"Undef NoUSB",
                           *(undefined4 *)(*plVar15 + 0x1f8),&DAT_00111364);
            return;
          }
          piVar2 = (int *)(*plVar15 + 0x1f8);
          iVar9 = *(int *)(*plVar15 + 0x1f8);
          do {
            if (iVar9 == 0) break;
            Hint_Prefetch(piVar2,2,0,1);
            do {
              iVar5 = *piVar2;
              if (iVar5 != iVar9) goto LAB_0010900c;
              cVar6 = '\x01';
              bVar8 = (bool)ExclusiveMonitorPass(piVar2,0x10);
              if (bVar8) {
                *piVar2 = iVar9 + -1;
                cVar6 = ExclusiveMonitorsStatus();
              }
            } while (cVar6 != '\0');
            DataMemoryBarrier(2,3);
LAB_0010900c:
            bVar8 = iVar9 != iVar5;
            iVar9 = iVar5;
          } while (bVar8);
          dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"Exit UNDEF",0,&DAT_00111364);
          goto switchD_001089c8_caseD_1;
        }
        _dev_err(*plVar15,"Failed to get dwc3 device\n");
        *plVar18 = 0;
      }
      of_platform_depopulate(*plVar15);
      iVar9 = -0x13;
    }
  }
  else {
    if (*(int *)(pcVar7 + -4) != 0x3c72446d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x108a50);
      (*pcVar7)();
    }
    iVar9 = (*pcVar7)();
    if (iVar9 == 0) goto LAB_00108a58;
    lVar17 = *plVar15;
    pcVar16 = "failed to init HS PHY\n";
LAB_00109214:
    _dev_err(lVar17,pcVar16);
  }
LAB_00109218:
  dwc3_dbg_print(*(undefined8 *)(param_1 + 0x288),0xff,"core_init failed",iVar9,&DAT_00111364);
  __pm_runtime_suspend(*plVar15,4);
  __pm_runtime_disable(*plVar15,1);
LAB_00109250:
  queue_work_on(0x20,*(undefined8 *)(param_1 + -8),param_1);
  return;
}



//------------------------------------------------------------
// msm_dwc3_perf_vote_work @ 001092ac size=300
// signature: undefined msm_dwc3_perf_vote_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_dwc3_perf_vote_work(long param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  int *piVar10;
  char cVar11;
  uint uVar12;
  
  lVar7 = irq_to_desc(*(undefined4 *)(param_1 + -0x1b8));
  if (lVar7 == 0) {
    return;
  }
  piVar10 = (int *)(param_1 + -0x1b4);
  iVar1 = *(int *)(lVar7 + 0x90);
  iVar2 = *piVar10;
  if (*(char *)(param_1 + 0x689) != '\0') {
    bVar3 = *(byte *)(param_1 + 0x68a);
    if (bVar3 < 0x32) {
      *(byte *)(param_1 + 0x68a) = bVar3 + 1;
      *(int *)(param_1 + (ulong)bVar3 * 4 + 0x68c) = iVar1 - iVar2;
    }
  }
  cVar4 = *(char *)(param_1 + 0x688);
  if (cVar4 == '\0') {
    cVar11 = *(char *)(param_1 + -200);
    uVar12 = 200;
    if (cVar11 != '\0') {
      uVar12 = 400;
    }
    if (uVar12 <= (uint)(iVar1 - iVar2)) goto LAB_00109338;
LAB_00109354:
    *piVar10 = iVar1;
    if (cVar11 == '\0') {
      bVar6 = cVar4 == '\0';
    }
    else {
      bVar5 = false;
      uVar9 = 0xffffffff;
LAB_00109370:
      cpu_latency_qos_update_request(param_1 + -0x30,uVar9);
      *(bool *)(param_1 + -200) = bVar5;
      bVar6 = *(char *)(param_1 + 0x688) == '\0';
      if (bVar5) goto LAB_0010938c;
    }
    uVar9 = 100;
  }
  else {
    if (cVar4 != '\x01') {
      cVar11 = *(char *)(param_1 + -200);
      goto LAB_00109354;
    }
    cVar11 = *(char *)(param_1 + -200);
LAB_00109338:
    *piVar10 = iVar1;
    if (cVar11 != '\x01') {
      uVar9 = *(undefined4 *)(param_1 + -0x3c);
      bVar5 = true;
      goto LAB_00109370;
    }
    bVar6 = cVar4 == '\0';
LAB_0010938c:
    uVar9 = 2000;
  }
  if (!bVar6) {
    uVar9 = 100;
  }
  uVar8 = __msecs_to_jiffies(uVar9);
  queue_delayed_work_on(0x20,_system_wq,param_1,uVar8);
  return;
}



//------------------------------------------------------------
// dma_set_mask_and_coherent @ 001093d8 size=76
// signature: undefined dma_set_mask_and_coherent(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

int dma_set_mask_and_coherent(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = dma_set_mask();
  if (iVar1 == 0) {
    dma_set_coherent_mask(param_1,param_2);
  }
  return iVar1;
}



//------------------------------------------------------------
// dwc3_msm_usb_role_switch_set_role @ 00109428 size=48
// signature: undefined dwc3_msm_usb_role_switch_set_role(void)
// callers: []
//------------------------------------------------------------

void dwc3_msm_usb_role_switch_set_role(undefined8 param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  uVar1 = usb_role_switch_get_drvdata();
  dwc3_msm_set_role(uVar1,param_2);
  return;
}



//------------------------------------------------------------
// dwc3_msm_usb_role_switch_get_role @ 0010945c size=104
// signature: undefined dwc3_msm_usb_role_switch_get_role(void)
// callers: []
//------------------------------------------------------------

ulong dwc3_msm_usb_role_switch_get_role(void)

{
  long lVar1;
  ulong uVar2;
  
  lVar1 = usb_role_switch_get_drvdata();
  if (*(char *)(lVar1 + 0x312) == '\0') {
    uVar2 = (ulong)(*(int *)(lVar1 + 0x318) == 0);
  }
  else {
    uVar2 = 2;
  }
  ipc_log_string(*(undefined8 *)(lVar1 + 0x528),"%s: get_role:%s\n",
                 "dwc3_msm_usb_role_switch_get_role",(&usb_role_strings)[uVar2]);
  return uVar2;
}



//------------------------------------------------------------
// dwc3_msm_set_role @ 001094c4 size=596
// signature: undefined dwc3_msm_set_role(void)
// callers: [dwc3_msm_probe, mode_store, dwc3_msm_usb_role_switch_set_role]
//------------------------------------------------------------

undefined8 dwc3_msm_set_role(undefined8 *param_1,uint param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  char *pcVar4;
  ulong uVar5;
  
  if (3 < *(uint *)((long)param_1 + 0x2dc)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x109714);
    (*pcVar2)();
  }
  if (param_2 < 3) {
    pcVar4 = (&usb_role_strings)[param_2];
  }
  else {
    pcVar4 = "Invalid";
  }
  _dev_info(*param_1,"%s: dr_mode=%s role_requested=%s\n","dwc3_msm_role_allowed",
            (&usb_dr_modes)[*(uint *)((long)param_1 + 0x2dc)],pcVar4);
  if (param_2 == 2) {
    if (*(int *)((long)param_1 + 0x2dc) == 1) {
      return 0xffffffea;
    }
  }
  else if ((param_2 == 1) && (*(int *)((long)param_1 + 0x2dc) == 2)) {
    return 0xffffffea;
  }
  puVar1 = param_1 + 0x92;
  mutex_lock(puVar1);
  if (*(char *)((long)param_1 + 0x312) == '\0') {
    uVar5 = (ulong)(*(int *)(param_1 + 99) == 0);
  }
  else {
    uVar5 = 2;
  }
  if (param_2 < 3) {
    pcVar4 = (&usb_role_strings)[param_2];
  }
  else {
    pcVar4 = "Invalid";
  }
  ipc_log_string(param_1[0xa5],"%s: cur_role:%s new_role:%s refcnt:%d\n","dwc3_msm_set_role",
                 (&usb_role_strings)[uVar5],pcVar4,*(undefined4 *)((long)param_1 + 0xa44));
  if (((uint)uVar5 == param_2) && (*(int *)(param_1 + 0x5b) != 0)) {
    ipc_log_string(param_1[0xa5],"%s: no USB role change","dwc3_msm_set_role");
LAB_001095ec:
    mutex_unlock(puVar1);
    return 0;
  }
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0x149) != 0) {
      *(int *)((long)param_1 + 0xa44) = *(int *)((long)param_1 + 0xa44) + -1;
      ipc_log_string(param_1[0xa5],"%s: DP (%d)session active, refcnt:%d\n","dwc3_msm_set_role");
      goto LAB_001095ec;
    }
    iVar3 = 0;
    *(undefined1 *)((long)param_1 + 0x312) = 0;
    *(undefined4 *)(param_1 + 99) = 1;
  }
  else if (param_2 == 1) {
    *(undefined1 *)((long)param_1 + 0x312) = 0;
    *(undefined4 *)(param_1 + 99) = 0;
    ipc_log_string(param_1[0xa5],"%s: refcnt:%d start host mode\n","dwc3_msm_set_role",
                   *(undefined4 *)((long)param_1 + 0xa44));
    iVar3 = *(int *)((long)param_1 + 0xa44) + 1;
  }
  else {
    if (param_2 != 2) {
      iVar3 = *(int *)((long)param_1 + 0xa44);
      pcVar4 = "Invalid";
      goto LAB_001096cc;
    }
    *(undefined1 *)((long)param_1 + 0x312) = 1;
    *(undefined4 *)(param_1 + 99) = 1;
    ipc_log_string(param_1[0xa5],"%s: refcnt:%d reset refcnt_dp_usb\n","dwc3_msm_set_role",
                   *(undefined4 *)((long)param_1 + 0xa44));
    iVar3 = 0;
  }
  *(int *)((long)param_1 + 0xa44) = iVar3;
  if (2 < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x109718);
    (*pcVar2)();
  }
  pcVar4 = (&usb_role_strings)[param_2];
LAB_001096cc:
  ipc_log_string(param_1[0xa5],"%s: new_role:%s refcnt:%d\n","dwc3_msm_set_role",pcVar4,iVar3);
  mutex_unlock(puVar1);
  dwc3_ext_event_notify(param_1);
  return 0;
}



//------------------------------------------------------------
// dwc_dpdm_cb @ 0010971c size=280
// signature: undefined dwc_dpdm_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 dwc_dpdm_cb(long param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)(param_1 + -0x4d8);
  if (param_2 == 0x80) {
    uVar1 = *(uint *)(param_1 + -0x200);
    if (uVar1 < 5) {
      pcVar4 = (&state_names)[uVar1];
    }
    else {
      pcVar4 = "UNKNOWN";
    }
    _dev_info(*puVar5,"%s: disable state:%s\n","dwc_dpdm_cb",pcVar4);
    if (*(uint *)(param_1 + -0x200) == 0) {
      queue_work_on(0x20,*(undefined8 *)(param_1 + -0x240),param_1 + -0x238);
    }
  }
  else {
    if (param_2 == 0x1000) {
      uVar1 = *(uint *)(param_1 + -0x200);
      uVar2 = *puVar5;
      if (uVar1 < 5) {
        pcVar3 = "%s: enable state:%s\n";
        pcVar4 = (&state_names)[uVar1];
      }
      else {
        pcVar4 = "UNKNOWN";
        pcVar3 = "%s: enable state:%s\n";
      }
    }
    else {
      uVar1 = *(uint *)(param_1 + -0x200);
      uVar2 = *puVar5;
      if (uVar1 < 5) {
        pcVar4 = (&state_names)[uVar1];
      }
      else {
        pcVar4 = "UNKNOWN";
      }
      pcVar3 = "%s: unknown event state:%s\n";
    }
    _dev_info(uVar2,pcVar3,"dwc_dpdm_cb",pcVar4);
  }
  return 1;
}



//------------------------------------------------------------
// dwc3_msm_extcon_is_valid_source @ 00109834 size=132
// signature: undefined dwc3_msm_extcon_is_valid_source(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

ulong dwc3_msm_extcon_is_valid_source(long *param_1)

{
  ulong uVar1;
  char *pcVar2;
  
  uVar1 = of_count_phandle_with_args(*(undefined8 *)(*param_1 + 0x2e8),"extcon",0);
  if ((int)uVar1 < 0) {
    _dev_err(*param_1,"of_count_phandle_with_args failed\n");
  }
  else {
    if ((int)uVar1 == 0) {
      return uVar1;
    }
    uVar1 = uVar1 & 0xffffffff;
    pcVar2 = (char *)(param_1[0x68] + 0x48);
    do {
      if (*pcVar2 == '\0') {
        return 1;
      }
      pcVar2 = pcVar2 + 0x50;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_set_ssphy_orientation_flag @ 001098b8 size=360
// signature: undefined dwc3_set_ssphy_orientation_flag(void)
// callers: [dwc3_resume_work, dwc3_msm_resume]
//------------------------------------------------------------

void dwc3_set_ssphy_orientation_flag(long param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  int local_40 [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40[0] = 0;
  *(uint *)(*(long *)(param_1 + 0x1c8) + 0x10) =
       *(uint *)(*(long *)(param_1 + 0x1c8) + 0x10) & 0xfffffff3;
  uVar2 = *(uint *)(param_1 + 0x51c);
  if (uVar2 == 0) {
    if (*(char *)(param_1 + 0xa50) != '\0') {
      gpio_to_desc(*(undefined4 *)(param_1 + 0xa4c));
      iVar1 = gpiod_get_raw_value();
      lVar3 = *(long *)(param_1 + 0x1c8);
      if (iVar1 == 0) {
        *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 4;
      }
      else {
        *(uint *)(lVar3 + 0x10) = *(uint *)(lVar3 + 0x10) | 8;
      }
      goto LAB_0010990c;
    }
    if (*(long *)(param_1 + 0x340) == 0) goto LAB_0010990c;
    if ((*(char *)(param_1 + 0x312) == '\0') || (*(char *)(param_1 + 0x288) != '\0')) {
      if (*(int *)(param_1 + 0x318) != 0) goto LAB_0010990c;
      uVar5 = 2;
    }
    else {
      uVar5 = 1;
    }
    lVar3 = *(long *)(*(long *)(param_1 + 0x340) + (long)*(int *)(param_1 + 0x348) * 0x50);
    if (((lVar3 == 0) || (iVar1 = extcon_get_state(lVar3,uVar5), iVar1 == 0)) ||
       (iVar1 = extcon_get_property(lVar3,uVar5,1,local_40), iVar1 != 0)) goto LAB_0010990c;
    lVar3 = *(long *)(param_1 + 0x1c8);
    uVar2 = *(uint *)(lVar3 + 0x10);
    uVar4 = 4;
    if (local_40[0] != 0) {
      uVar4 = 8;
    }
  }
  else {
    lVar3 = *(long *)(param_1 + 0x1c8);
    uVar4 = *(uint *)(lVar3 + 0x10);
  }
  *(uint *)(lVar3 + 0x10) = uVar4 | uVar2;
LAB_0010990c:
  dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"ss_flag",
                 *(undefined4 *)(*(long *)(param_1 + 0x1c8) + 0x10),&DAT_00111364);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pm_runtime_resume_and_get @ 00109a20 size=132
// signature: undefined pm_runtime_resume_and_get(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

int pm_runtime_resume_and_get(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = __pm_runtime_resume(param_1,4);
  if (iVar5 < 0) {
    piVar1 = (int *)(param_1 + 0x1f8);
    iVar6 = *(int *)(param_1 + 0x1f8);
    do {
      if (iVar6 == 0) {
        return iVar5;
      }
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar6) goto LAB_00109a84;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar6 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_00109a84:
      bVar4 = iVar6 != iVar2;
      iVar6 = iVar2;
    } while (bVar4);
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



//------------------------------------------------------------
// dwc3_otg_start_host @ 00109ab8 size=2136
// signature: undefined dwc3_otg_start_host(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

int dwc3_otg_start_host(long *param_1,int param_2)

{
  int *piVar1;
  ulong *puVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  void *__src;
  uint *puVar10;
  int iVar11;
  code *pcVar12;
  long lVar13;
  undefined8 *__dest;
  long lVar14;
  
  lVar13 = *(long *)(param_1[5] + 0xa8);
  if (param_2 == 0) {
    _dev_info(*param_1,"%s: turn off host\n","dwc3_otg_start_host");
    if (param_1[0x3d] != 0) {
      regulator_disable();
    }
    lVar14 = param_1[5];
    iVar6 = __pm_runtime_resume(lVar14 + 0x10,4);
    if (iVar6 < 0) {
      piVar1 = (int *)(lVar14 + 0x208);
      iVar11 = *(int *)(lVar14 + 0x208);
      do {
        if (iVar11 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar3 = *piVar1;
          if (iVar3 != iVar11) goto LAB_0010a14c;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = iVar11 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010a14c:
        bVar5 = iVar11 != iVar3;
        iVar11 = iVar3;
      } while (bVar5);
      _dev_err(*param_1,"%s: pm_runtime_resume_and_get failed\n","dwc3_otg_start_host");
      __pm_runtime_set_status(param_1[5] + 0x10,2);
LAB_0010a240:
      __pm_runtime_set_status(*param_1,2);
      return iVar6;
    }
    dwc3_dbg_print(param_1[0xa5],0xff,"StopHost gsync",*(undefined4 *)(*param_1 + 0x1f8),
                   &DAT_00111364);
    *(undefined1 *)(param_1 + 0x61) = 0;
    if ((char)param_1[0xa3] == '\0') {
      dwc3_msm_host_ss_powerup(param_1);
      _dev_info(*param_1,"resetting dp params for USB ss\n");
      ipc_log_string(param_1[0xa5],"%s: resetting params for USB ss\n",
                     "dwc3_msm_clear_dp_only_params");
      *(undefined1 *)(param_1 + 0xa3) = 0;
      *(uint *)(param_1[0x39] + 0x10) = *(uint *)(param_1[0x39] + 0x10) & 0xfffffdff;
      if (param_1[5] == 0) {
        *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)((long)param_1 + 0x4c4);
      }
      else {
        *(undefined4 *)(*(long *)(param_1[5] + 0xa8) + 0x45c) =
             *(undefined4 *)((long)param_1 + 0x4c4);
      }
      usb_redriver_notify_disconnect(param_1[0x3a]);
    }
    lVar14 = param_1[1];
    uVar7 = readl(lVar14 + 0xf8808);
    writel(uVar7 | 0x100,lVar14 + 0xf8808);
    __const_udelay(0x53e3);
    uVar7 = readl(param_1[1] + 0xf8808);
    writel(uVar7 | 9,param_1[1] + 0xf8808);
    __const_udelay(0x53e3);
    lVar14 = param_1[1];
    uVar7 = readl(lVar14 + 0xf8808);
    writel(uVar7 & 0xfffffeff,lVar14 + 0xf8808);
    lVar14 = param_1[0x39];
    uVar7 = *(uint *)(lVar14 + 0x10);
    if ((uVar7 & 1) != 0) {
      if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x150), pcVar12 != (code *)0x0)) {
        if (*(int *)(pcVar12 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
          pcVar12 = (code *)SoftwareBreakpoint(0x8229,0x109be8);
          (*pcVar12)();
        }
        (*pcVar12)(lVar14,5);
        lVar14 = param_1[0x39];
        uVar7 = *(uint *)(lVar14 + 0x10);
      }
      *(uint *)(lVar14 + 0x10) = uVar7 & 0xfffffffe;
    }
    usb_redriver_notify_disconnect(param_1[0x3a]);
    lVar14 = param_1[0x38];
    if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x150), pcVar12 != (code *)0x0)) {
      if (*(int *)(pcVar12 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x109c30);
        (*pcVar12)();
      }
      (*pcVar12)(lVar14,3);
    }
    usb_role_switch_set_role(param_1[0xa2],2);
    if (*(int *)(lVar13 + 1000) == 3) {
      flush_work(lVar13);
    }
    lVar13 = param_1[1];
    uVar7 = readl(lVar13 + 0xf8808);
    writel(uVar7 | 0x100,lVar13 + 0xf8808);
    __const_udelay(0x53e3);
    uVar7 = readl(param_1[1] + 0xf8808);
    writel(uVar7 & 0xfffffff6,param_1[1] + 0xf8808);
    __const_udelay(0x53e3);
    lVar13 = param_1[1];
    uVar7 = readl(lVar13 + 0xf8808);
    writel(uVar7 & 0xfffffeff,lVar13 + 0xf8808);
    *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) & 0xfffffffe;
    usb_unregister_notify(param_1 + 0x6a);
    lVar13 = param_1[1] + 0xc2c0;
    uVar7 = readl(lVar13);
    writel(uVar7 & 0xfffdffff,lVar13);
    readl(lVar13);
    puVar2 = (ulong *)(param_1 + 0x5a);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar5) {
        *puVar2 = *puVar2 | 8;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    __pm_runtime_suspend(param_1[5] + 0x10,4);
    dwc3_dbg_print(param_1[0xa5],0xff,"StopHost psync",*(undefined4 *)(*param_1 + 0x1f8),
                   &DAT_00111364);
  }
  else {
    _dev_info(*param_1,"%s: turn on host\n","dwc3_otg_start_host");
    if ((param_1[0x3d] != 0) && (iVar6 = regulator_enable(), iVar6 != 0)) {
      _dev_err(*param_1,"Failed to enable vbus, ret %d\n",iVar6);
      return iVar6;
    }
    *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) | 1;
    dwc3_dbg_print(param_1[0xa5],0xff,"hs_phy_flag:",*(undefined4 *)(param_1[0x38] + 0x10),
                   &DAT_00111364);
    if (*(char *)((long)param_1 + 0xa51) != '\0') {
      wcd_usbss_switch_update(0,1);
    }
    lVar14 = *param_1;
    iVar6 = __pm_runtime_resume(lVar14,4);
    if (iVar6 < 0) {
      piVar1 = (int *)(lVar14 + 0x1f8);
      iVar11 = *(int *)(lVar14 + 0x1f8);
      do {
        if (iVar11 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar3 = *piVar1;
          if (iVar3 != iVar11) goto LAB_0010a1d8;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = iVar11 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010a1d8:
        bVar5 = iVar11 != iVar3;
        iVar11 = iVar3;
      } while (bVar5);
      _dev_err(*param_1,"%s: pm_runtime_resume_and_get failed\n","dwc3_otg_start_host");
      if (param_1[0x3d] != 0) {
        regulator_disable();
      }
      *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) & 0xfffffffe;
      goto LAB_0010a240;
    }
    dwc3_dbg_print(param_1[0xa5],0xff,"StrtHost gync",*(undefined4 *)(*param_1 + 0x1f8),
                   &DAT_00111364);
    clk_set_rate(param_1[0x2a],param_1[0x2b]);
    usb_redriver_notify_connect
              (param_1[0x3a],(*(uint *)(param_1[0x39] + 0x10) >> 2 ^ 0xffffffff) & 1);
    if (param_1[5] == 0) {
      puVar10 = (uint *)(param_1 + 0x98);
    }
    else {
      puVar10 = (uint *)(*(long *)(param_1[5] + 0xa8) + 0x45c);
    }
    if (4 < *puVar10) {
      *(uint *)(param_1[0x39] + 0x10) = *(uint *)(param_1[0x39] + 0x10) | 1;
      lVar14 = param_1[0x39];
      if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x148), pcVar12 != (code *)0x0)) {
        if (*(int *)(pcVar12 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
          pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x109e6c);
          (*pcVar12)();
        }
        (*pcVar12)(lVar14,5);
      }
    }
    lVar14 = param_1[0x38];
    if ((lVar14 != 0) && (pcVar12 = *(code **)(lVar14 + 0x148), pcVar12 != (code *)0x0)) {
      if (*(int *)(pcVar12 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x109e9c);
        (*pcVar12)();
      }
      (*pcVar12)(lVar14,3);
    }
    param_1[0x6a] = (long)dwc3_msm_host_notifier;
    usb_register_notify(param_1 + 0x6a);
    if ((*(uint *)(lVar13 + 0x4e8) >> 0x1d & 1) == 0) {
      uVar7 = readl(param_1[1] + 0xc200);
      writel(uVar7 | 0x100,param_1[1] + 0xc200);
      uVar7 = readl(param_1[1] + 0xc11c);
      writel(uVar7 | 0x100,param_1[1] + 0xc11c);
    }
    if ((char)param_1[0x148] != '\0') {
      uVar7 = readl(param_1[1] + 0xc200);
      writel(uVar7 | 0x40,param_1[1] + 0xc200);
    }
    uVar7 = readl(param_1[1] + 0xc12c);
    writel(uVar7 | 0x20000,param_1[1] + 0xc12c);
    if ((*(int *)(lVar13 + 0x46c) == 0x3331) && (0x31373029 < *(uint *)(lVar13 + 0x470))) {
      lVar14 = param_1[1] + 0xc11c;
      uVar7 = readl(lVar14);
      writel(uVar7 & 0xff1fffff | 0x200000,lVar14);
      readl(lVar14);
      lVar14 = param_1[1] + 0xc60c;
      uVar7 = readl(lVar14);
      writel(uVar7 | 0x10000,lVar14);
      readl(lVar14);
    }
    usb_role_switch_set_role(param_1[0xa2],1);
    if (*(int *)(lVar13 + 1000) == 3) {
      flush_work(lVar13);
    }
    lVar14 = *(long *)(lVar13 + 0x1a0);
    if ((*(long *)(lVar14 + 0x98) == 0) ||
       (__src = *(void **)(*(long *)(lVar14 + 0x98) + 0x78), __src == (void *)0x0)) {
      _dev_err(lVar14 + 0x10,"can\'t override PM OPs\n");
    }
    else {
      __dest = (undefined8 *)param_1[0x70];
      memcpy(__dest,__src,0xc0);
      *__dest = dwc3_host_prepare;
      __dest[1] = dwc3_host_complete;
      *(undefined8 **)(*(long *)(lVar14 + 0x98) + 0x78) = __dest;
    }
    *(undefined1 *)(param_1 + 0x61) = 1;
    __pm_runtime_use_autosuspend(*(long *)(lVar13 + 0x1a0) + 0x10,1);
    pm_runtime_set_autosuspend_delay(*(long *)(lVar13 + 0x1a0) + 0x10,0);
    pm_runtime_allow(*(long *)(lVar13 + 0x1a0) + 0x10);
    lVar14 = *(long *)(lVar13 + 0x1a0);
    uVar9 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar14 + 0x230) = uVar9;
    lVar14 = param_1[1] + 0xc2c0;
    uVar7 = readl(lVar14);
    writel(uVar7 | 0x20000,lVar14);
    readl(lVar14);
    if ((*(int *)(lVar13 + 0x46c) == 0x3331) && (*(int *)(lVar13 + 0x470) == 0x3137302a)) {
      dwc3_msm_write_reg_field(param_1[1],0xd010,0xff0000,6);
      dwc3_msm_write_reg_field(param_1[1],0xd010,0xff,5);
      lVar13 = *param_1;
      uVar8 = readl(param_1[1] + 0xd010);
      _dev_info(lVar13,"LU3:%08x\n",uVar8);
    }
    dwc3_dbg_print(param_1[0xa5],0xff,"StrtHost psync",*(undefined4 *)(*param_1 + 0x1f8),
                   &DAT_00111364);
    lVar13 = *param_1;
    uVar9 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar13 + 0x220) = uVar9;
    __pm_runtime_suspend(*param_1,0xc);
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_otg_start_peripheral @ 0010a344 size=1800
// signature: undefined dwc3_otg_start_peripheral(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

void dwc3_otg_start_peripheral(long *param_1,int param_2)

{
  int *piVar1;
  uint6 *puVar2;
  ulong *puVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  code *pcVar11;
  uint *puVar12;
  long lVar13;
  long lVar14;
  
  lVar14 = *param_1;
  lVar13 = *(long *)(param_1[5] + 0xa8);
  iVar7 = __pm_runtime_resume(lVar14,4);
  if (iVar7 < 0) {
    piVar1 = (int *)(lVar14 + 0x1f8);
    iVar7 = *(int *)(lVar14 + 0x1f8);
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar4 = *piVar1;
        if (iVar4 != iVar7) goto LAB_0010a3a8;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = iVar7 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010a3a8:
      bVar6 = iVar7 != iVar4;
      iVar7 = iVar4;
    } while (bVar6);
    _dev_err(*param_1,"%s: pm_runtime_resume_and_get failed\n","dwc3_otg_start_peripheral");
    __pm_runtime_set_status(*param_1,2);
    return;
  }
  dwc3_dbg_print(param_1[0xa5],0xff,"StrtGdgt gsync",*(undefined4 *)(*param_1 + 0x1f8),&DAT_00111364
                );
  if (param_2 != 0) {
    _dev_info(*param_1,"%s: turn on gadget\n","dwc3_otg_start_peripheral");
    if (*(char *)((long)param_1 + 0xa51) != '\0') {
      wcd_usbss_switch_update(0,1);
    }
    __pm_runtime_resume(param_1[5] + 0x10,4);
    if (*(int *)(lVar13 + 1000) == 3) {
      flush_work(lVar13);
    }
    dwc3_msm_notify_event(lVar13,0xb,0);
    dwc3_override_vbus_status(param_1,1);
    usb_redriver_notify_connect
              (param_1[0x3a],(*(uint *)(param_1[0x39] + 0x10) >> 2 ^ 0xffffffff) & 1);
    if (param_1[5] == 0) {
      puVar12 = (uint *)(param_1 + 0x98);
    }
    else {
      puVar12 = (uint *)(*(long *)(param_1[5] + 0xa8) + 0x45c);
    }
    if (((4 < *puVar12) && (lVar14 = param_1[0x39], lVar14 != 0)) &&
       (pcVar11 = *(code **)(lVar14 + 0x148), pcVar11 != (code *)0x0)) {
      if (*(int *)(pcVar11 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10a7ac);
        (*pcVar11)();
      }
      (*pcVar11)(lVar14,5);
    }
    lVar14 = param_1[0x38];
    if ((lVar14 != 0) && (pcVar11 = *(code **)(lVar14 + 0x148), pcVar11 != (code *)0x0)) {
      if (*(int *)(pcVar11 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10a7dc);
        (*pcVar11)();
      }
      (*pcVar11)(lVar14,3);
    }
    lVar14 = param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x68) + 0xf8000);
    uVar8 = readl(lVar14);
    writel(uVar8 | 0x80000000,lVar14);
    readl(lVar14);
    usleep_range_state(1000,0x4b0,2);
    lVar14 = param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x68) + 0xf8000);
    uVar8 = readl(lVar14);
    writel(uVar8 & 0x7fffffff,lVar14);
    readl(lVar14);
    lVar14 = param_1[1] + 0xf8808;
    uVar8 = readl(lVar14);
    writel(uVar8 | 2,lVar14);
    readl(lVar14);
    if (*(char *)((long)param_1 + 0x1e4) == '\0') {
      writel(0xff,param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0x98) + 0xf8000));
      writel(0xff,param_1[1] + (ulong)(*(int *)(param_1[0x3b] + 0xa0) + 0xf8000));
    }
    uVar8 = readl(param_1[1] + 0xc200);
    writel(uVar8 & 0xfffffeff,param_1[1] + 0xc200);
    uVar8 = readl(param_1[1] + 0xc11c);
    writel(uVar8 & 0xfffffeff,param_1[1] + 0xc11c);
    *(undefined1 *)((long)param_1 + 0x309) = 1;
    if ((*(int *)(lVar13 + 0x46c) == 0x3331) && (*(int *)(lVar13 + 0x470) == 0x3137302a)) {
      dwc3_msm_write_reg_field(param_1[1],0xd010,0xff0000,6);
      dwc3_msm_write_reg_field(param_1[1],0xd010,0xff,5);
      lVar14 = *param_1;
      uVar9 = readl(param_1[1] + 0xd010);
      _dev_info(lVar14,"LU3:%08x\n",uVar9);
    }
    usb_role_switch_set_role(param_1[0xa2],2);
    clk_set_rate(param_1[0x2a],param_1[0x2b]);
    lVar14 = lVar13 + 0x158;
    uVar10 = _raw_spin_lock_irqsave(lVar14);
    if (((((char)param_1[0x166] != '\0') && ((*(uint *)(lVar13 + 0x4e8) >> 1 & 1) == 0)) &&
        (*(long *)(lVar13 + 0x370) != 0)) && (**(long **)(*(long *)(lVar13 + 0x370) + 0x30) != 0)) {
      _raw_spin_unlock_irqrestore(lVar14,uVar10);
      dwc3_dbg_print(param_1[0xa5],0xff,"Force Pullup",0,&DAT_00111364);
      usb_gadget_connect(*(undefined8 *)(lVar13 + 0x370));
      uVar10 = _raw_spin_lock_irqsave(lVar14);
    }
    _raw_spin_unlock_irqrestore(lVar14,uVar10);
    *(undefined1 *)(param_1 + 0x166) = 0;
    goto LAB_0010a9bc;
  }
  _dev_info(*param_1,"%s: turn off gadget\n","dwc3_otg_start_peripheral");
  lVar14 = param_1[1] + 0xf8810;
  uVar8 = readl(lVar14);
  writel(uVar8 & 0xffefffff,lVar14);
  readl(lVar14);
  lVar14 = param_1[1] + 0xf8830;
  uVar8 = readl(lVar14);
  writel(uVar8 & 0xfeffffff,lVar14);
  readl(lVar14);
  lVar14 = param_1[0x38];
  *(undefined1 *)((long)param_1 + 0x309) = 0;
  if (lVar14 != 0) {
    pcVar11 = *(code **)(lVar14 + 0x150);
    if (pcVar11 != (code *)0x0) {
      if (*(int *)(pcVar11 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10a4a0);
        (*pcVar11)();
      }
      (*pcVar11)(lVar14,3);
      lVar14 = param_1[0x38];
      if (lVar14 == 0) goto LAB_0010a4e4;
    }
    usb_phy_set_charger_current(lVar14,0);
    pcVar11 = *(code **)(lVar14 + 0x130);
    if (pcVar11 != (code *)0x0) {
      if (*(int *)(pcVar11 + -4) != -0x2f0ceede) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10a4e0);
        (*pcVar11)();
      }
      (*pcVar11)(lVar14,0);
    }
  }
LAB_0010a4e4:
  lVar14 = param_1[0x39];
  if ((lVar14 != 0) && (pcVar11 = *(code **)(lVar14 + 0x150), pcVar11 != (code *)0x0)) {
    if (*(int *)(pcVar11 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10a510);
      (*pcVar11)();
    }
    (*pcVar11)(lVar14,5);
  }
  usb_redriver_notify_disconnect(param_1[0x3a]);
  dwc3_msm_notify_event(lVar13,0xd,0);
  lVar14 = param_1[1] + 0xf8810;
  uVar8 = readl(lVar14);
  writel(uVar8 & 0xffefffff,lVar14);
  readl(lVar14);
  lVar14 = param_1[1] + 0xf8830;
  uVar8 = readl(lVar14);
  writel(uVar8 & 0xfeffffff,lVar14);
  readl(lVar14);
  lVar14 = param_1[1] + 0xc2c0;
  uVar8 = readl(lVar14);
  writel(uVar8 & 0xfffdffff,lVar14);
  readl(lVar14);
  __pm_runtime_idle(param_1[5] + 0x10,4);
  if ((*(int *)(param_1[5] + 0x21c) != 2) || ((*(ushort *)(param_1[5] + 0x210) & 7) != 0)) {
    puVar2 = (uint6 *)(lVar13 + 0x4e8);
    iVar7 = -99;
    do {
      uVar8 = *(uint *)puVar2;
      if ((uVar8 & 1) == 0) {
        dwc3_dbg_print(param_1[0xa5],0xff,"StopGdgt connected",uVar8 & 1,&DAT_00111364);
        __pm_runtime_suspend(param_1[5] + 0x10,0);
        goto LAB_0010aa54;
      }
      msleep(0x14);
      bVar6 = iVar7 != -1;
      iVar7 = iVar7 + 1;
    } while (bVar6);
    dwc3_dbg_print(param_1[0xa5],0xff,"StopGdgt connected",*(uint *)puVar2 & 1,&DAT_00111364);
    __pm_runtime_suspend(param_1[5] + 0x10,0);
    if (((uVar8 & 1) != 0) && ((*puVar2 & 1) != 0)) {
      dwc3_dbg_print(param_1[0xa5],0xff,"Force Pulldown",0,&DAT_00111364);
      usb_gadget_disconnect(*(undefined8 *)(lVar13 + 0x370));
      *(undefined1 *)(param_1 + 0x166) = 1;
    }
  }
LAB_0010aa54:
  puVar3 = (ulong *)(param_1 + 0x5a);
  Hint_Prefetch(puVar3,2,0,1);
  do {
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(puVar3,0x10);
    if (bVar6) {
      *puVar3 = *puVar3 | 8;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
LAB_0010a9bc:
  __pm_runtime_idle(*param_1,4);
  dwc3_dbg_print(param_1[0xa5],0xff,"StopGdgt psync",*(undefined4 *)(*param_1 + 0x1f8),&DAT_00111364
                );
  return;
}



//------------------------------------------------------------
// dwc3_host_prepare @ 0010aa74 size=36
// signature: undefined dwc3_host_prepare(void)
// callers: []
//------------------------------------------------------------

bool dwc3_host_prepare(long param_1)

{
  if ((*(ushort *)(param_1 + 0x200) & 7) == 0) {
    return *(int *)(param_1 + 0x20c) == 2;
  }
  return false;
}



//------------------------------------------------------------
// dwc3_core_prepare @ 0010aa9c size=240
// signature: undefined dwc3_core_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 dwc3_core_prepare(long param_1)

{
  bool bVar1;
  int iVar2;
  char *__s1;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar4 = *(long *)(*(long *)(*(long *)(lVar3 + 400) + 0x60) + 0x98);
  __s1 = (char *)dev_driver_string(*(undefined8 *)(param_1 + 0x60));
  iVar2 = strcmp(__s1,"msm-dwc3");
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x20c) == 2) {
      bVar1 = (*(ushort *)(param_1 + 0x200) & 7) == 0;
    }
    else {
      bVar1 = false;
    }
    dwc3_dbg_print(*(undefined8 *)(lVar4 + 0x528),0xff,"Core PM prepare",bVar1,&DAT_00111364);
    if (((*(ushort *)(param_1 + 0x200) & 7) == 0) && (*(int *)(param_1 + 0x20c) == 2)) {
      return 1;
    }
    if ((*(int *)(lVar3 + 0x3ec) == 2) &&
       (((*(ushort *)(param_1 + 0x200) & 7) != 0 || (*(int *)(param_1 + 0x20c) != 2)))) {
      _dev_info(param_1,"%s: peripheral mode still active\n","dwc3_core_prepare");
      return 0xfffffff0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_host_complete @ 0010ab90 size=80
// signature: undefined dwc3_host_complete(void)
// callers: []
//------------------------------------------------------------

void dwc3_host_complete(long param_1)

{
  int iVar1;
  
  if (((*(ushort *)(param_1 + 0x10c) >> 9 & 1) != 0) &&
     (iVar1 = __pm_runtime_resume(param_1,0), iVar1 < 0)) {
    _dev_err(param_1,"failed to runtime resume, ret %d\n",iVar1);
  }
  return;
}



//------------------------------------------------------------
// dwc3_core_complete @ 0010abe4 size=168
// signature: undefined dwc3_core_complete(void)
// callers: []
//------------------------------------------------------------

void dwc3_core_complete(long param_1)

{
  int iVar1;
  char *__s1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(*(long *)(param_1 + 0x98) + 400) + 0x60) + 0x98);
  __s1 = (char *)dev_driver_string(*(undefined8 *)(param_1 + 0x60));
  iVar1 = strcmp(__s1,"msm-dwc3");
  if (iVar1 == 0) {
    dwc3_dbg_print(*(undefined8 *)(lVar2 + 0x528),0xff,"Core PM complete",
                   *(ushort *)(param_1 + 0x10c) >> 9 & 1,&DAT_00111364);
    if (*(char *)(lVar2 + 0x308) == '\0') {
      dwc3_dbg_print(*(undefined8 *)(lVar2 + 0x528),0xff,"Queue ResWrk",0,&DAT_00111364);
      queue_work_on(0x20,*(undefined8 *)(lVar2 + 0x290),lVar2 + 0x228);
    }
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_host_notifier @ 0010ac90 size=688
// signature: undefined dwc3_msm_host_notifier(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dwc3_msm_host_notifier(long param_1,long param_2,long param_3)

{
  int iVar1;
  char *__s1;
  ulong uVar2;
  char *__s2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined8 *puVar6;
  
  lVar5 = *(long *)(*(long *)(param_1 + -0x328) + 0xa8);
  lVar4 = *(long *)(lVar5 + 0x1a0);
  if (lVar4 != 0) {
    lVar3 = param_3;
    if (param_2 - 1U < 2) {
      lVar3 = *(long *)(param_3 + 0x50);
    }
    __s1 = (char *)(*(undefined8 **)(lVar3 + 8))[0xe];
    if (__s1 == (char *)0x0) {
      __s1 = (char *)**(undefined8 **)(lVar3 + 8);
    }
    __s2 = (char *)(*(undefined8 **)(lVar5 + 0x198))[0xe];
    if (__s2 == (char *)0x0) {
      iVar1 = strcmp(__s1,(char *)**(undefined8 **)(lVar5 + 0x198));
    }
    else {
      iVar1 = strcmp(__s1,__s2);
    }
    if (iVar1 == 0) {
      lVar4 = *(long *)(lVar4 + 0xa8);
      if (param_2 == 3) {
        iVar1 = usb_hcd_is_primary_hcd(lVar4);
        if (iVar1 != 0) {
          iVar1 = usb_hcd_is_primary_hcd(lVar4);
          if (iVar1 == 0) {
            lVar4 = *(long *)(lVar4 + 0x278);
          }
          if (*(char *)(param_1 + -0x25) != '\0') {
            *(ulong *)(lVar4 + 0xd08) = *(ulong *)(lVar4 + 0xd08) | 0x20000;
          }
        }
      }
      else if (0xfffffffffffffffd < param_2 - 3U) {
        if (param_2 == 1) {
          if (*(char *)(param_1 + -0x24) == '\0') {
            *(byte *)(param_3 + 0x1f8) = *(byte *)(param_3 + 0x1f8) | 2;
          }
          lVar3 = *(long *)(param_3 + 0x48);
          if (lVar3 == 0) {
            __pm_runtime_use_autosuspend(param_3 + 0xa8,1);
            pm_runtime_set_autosuspend_delay(param_3 + 0xa8,1000);
            return 0;
          }
        }
        else {
          lVar3 = *(long *)(param_3 + 0x48);
          if (lVar3 == 0) {
            return 0;
          }
        }
        if ((*(long *)(lVar3 + 0x48) == 0) &&
           (*(long *)(*(long *)(param_3 + 0x108) + 0x60) == *(long *)(lVar5 + 0x1a0) + 0x10)) {
          puVar6 = (undefined8 *)(param_1 + -0x350);
          if (param_2 == 1) {
            uVar2 = dwc3_msm_is_ss_rhport_connected(puVar6);
            if ((uVar2 & 1) == 0) {
              if (*(char *)(param_1 + 0x7e1) == '\0') {
                clk_set_rate(*(undefined8 *)(param_1 + -0x200),*(undefined8 *)(param_1 + -0x1f0));
                _dev_info(*puVar6,"set hs core clk rate %ld\n",*(undefined8 *)(param_1 + -0x1f0));
              }
              *(undefined4 *)(param_1 + -0x44) = 3;
              dwc3_msm_update_bus_bw(puVar6,2);
              dwc3_msm_host_ss_powerdown(puVar6);
              if (*(char *)(param_1 + 0x701) != '\0') {
                wcd_usbss_dpdm_switch_update(1,*(int *)(param_3 + 0x1c) == 3);
              }
              dwc3_msm_update_interfaces(param_3);
            }
            else {
              if (*(uint *)(param_1 + -0x44) < 5) {
                dwc3_msm_host_ss_powerup(puVar6);
              }
              *(undefined4 *)(param_1 + -0x44) = 5;
            }
          }
          else {
            if (*(char *)(param_1 + 0x7e1) == '\0') {
              clk_set_rate(*(undefined8 *)(param_1 + -0x200),*(undefined8 *)(param_1 + -0x1f8));
              _dev_info(*puVar6,"set core clk rate %ld\n",*(undefined8 *)(param_1 + -0x1f8));
            }
            *(undefined4 *)(param_1 + -0x44) = 0;
            dwc3_msm_update_bus_bw(puVar6,*(undefined4 *)(param_1 + -0x6c));
            dwc3_msm_host_ss_powerup(puVar6);
            if (4 < *(uint *)(*(long *)(param_3 + 0x48) + 0x1c)) {
              usb_redriver_host_powercycle(*(undefined8 *)(param_1 + -0x180));
            }
            if (*(char *)(param_1 + 0x701) != '\0') {
              wcd_usbss_dpdm_switch_update(1,1);
            }
            if ((lVar4 != 0) && (((uint)*(undefined8 *)(lVar4 + 0x198) >> 6 & 1) != 0)) {
              queue_work_on(0x20,_system_wq,param_1 + -0xf8);
            }
          }
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_host_ss_powerup @ 0010af40 size=392
// signature: undefined dwc3_msm_host_ss_powerup(void)
// callers: [dwc3_otg_start_host, dwc3_msm_host_notifier]
//------------------------------------------------------------

void dwc3_msm_host_ss_powerup(long param_1)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  uint *puVar4;
  code *pcVar5;
  
  if (*(long *)(param_1 + 0x28) == 0) {
    puVar3 = (undefined4 *)(param_1 + 0x4c0);
  }
  else {
    puVar3 = (undefined4 *)(*(long *)(*(long *)(param_1 + 0x28) + 0xa8) + 0x45c);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x528),"%s: start: speed:%d\n","dwc3_msm_host_ss_powerup"
                 ,*puVar3);
  if (*(char *)(param_1 + 0x308) == '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x329) != '\0') {
    return;
  }
  if (*(long *)(param_1 + 0x28) == 0) {
    puVar4 = (uint *)(param_1 + 0x4c0);
  }
  else {
    puVar4 = (uint *)(*(long *)(*(long *)(param_1 + 0x28) + 0xa8) + 0x45c);
  }
  if (*puVar4 < 5) {
    return;
  }
  lVar2 = *(long *)(param_1 + 0x1c8);
  if (lVar2 != 0) {
    pcVar5 = *(code **)(lVar2 + 0x138);
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(pcVar5 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10afec);
        (*pcVar5)();
      }
      (*pcVar5)(lVar2,0);
      lVar2 = *(long *)(param_1 + 0x1c8);
      if (lVar2 == 0) goto LAB_0010b020;
    }
    pcVar5 = *(code **)(lVar2 + 0x148);
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(pcVar5 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10b01c);
        (*pcVar5)();
      }
      (*pcVar5)(lVar2,5);
    }
  }
LAB_0010b020:
  lVar2 = *(long *)(param_1 + 8) + 0xf8808;
  uVar1 = readl(lVar2);
  writel(uVar1 | 0x100,lVar2);
  __const_udelay(0x53e3);
  uVar1 = readl(*(long *)(param_1 + 8) + 0xf8808);
  writel(uVar1 & 0xfffffff6,*(long *)(param_1 + 8) + 0xf8808);
  __const_udelay(0x53e3);
  lVar2 = *(long *)(param_1 + 8) + 0xf8808;
  uVar1 = readl(lVar2);
  writel(uVar1 & 0xfffffeff,lVar2);
  uVar1 = readl(*(long *)(param_1 + 8) + 0xf89e4);
  writel(uVar1 & 0xffffffdf,*(long *)(param_1 + 8) + 0xf89e4);
  return;
}



//------------------------------------------------------------
// dwc3_msm_is_ss_rhport_connected @ 0010b0c8 size=180
// signature: undefined dwc3_msm_is_ss_rhport_connected(void)
// callers: [dwc3_msm_host_notifier]
//------------------------------------------------------------

bool dwc3_msm_is_ss_rhport_connected(long param_1)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  ulong uVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = readl(*(long *)(param_1 + 8) + 4);
  uVar3 = uVar3 >> 0x18 & 0x7f;
  if (uVar3 == 0) {
    bVar2 = false;
  }
  else {
    uVar4 = readl(*(long *)(param_1 + 8) + (ulong)(*(int *)(param_1 + 0xb40) + 0x400));
    if (((uVar4 & 1) == 0) || ((uVar4 & 0x3000) == 0)) {
      iVar6 = 0x410;
      uVar1 = 1;
      do {
        uVar5 = uVar1;
        if (uVar3 == uVar5) break;
        uVar4 = readl(*(long *)(param_1 + 8) + (ulong)(uint)(iVar6 + *(int *)(param_1 + 0xb40)));
        iVar6 = iVar6 + 0x10;
        uVar1 = uVar5 + 1;
      } while (((uVar4 & 1) == 0) || ((uVar4 & 0x3000) == 0));
      bVar2 = uVar5 < uVar3;
    }
    else {
      bVar2 = true;
    }
  }
  return bVar2;
}



//------------------------------------------------------------
// dwc3_msm_update_bus_bw @ 0010b17c size=328
// signature: undefined dwc3_msm_update_bus_bw(void)
// callers: [bus_vote_store, dwc3_msm_suspend, dwc3_msm_resume, dwc3_msm_host_notifier]
//------------------------------------------------------------

void dwc3_msm_update_bus_bw(undefined8 *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(char *)((long)param_1 + 0xb31) == '\0') {
    uVar2 = param_2;
    if (*(uint *)(param_1 + 0x5d) != 0) {
      uVar2 = *(uint *)(param_1 + 0x5d);
    }
    dwc3_dbg_print(param_1[0xa5],0xff,"bus_vote_start",param_2,&DAT_00111364);
    if (2 < uVar2) {
      uVar2 = 3;
    }
    iVar1 = icc_set_bw(param_1[0x5e],*(undefined4 *)(bus_vote_values + (ulong)uVar2 * 0x18),
                       *(undefined4 *)(bus_vote_values + (ulong)uVar2 * 0x18 + 4));
    if (iVar1 != 0) {
      _dev_err(*param_1,"bus bw voting path:%s bv:%d failed %d\n","usb-ddr",uVar2,iVar1);
    }
    iVar1 = icc_set_bw(param_1[0x5f],*(undefined4 *)(bus_vote_values + (ulong)uVar2 * 0x18 + 8),
                       *(undefined4 *)(bus_vote_values + (ulong)uVar2 * 0x18 + 0xc));
    if (iVar1 != 0) {
      _dev_err(*param_1,"bus bw voting path:%s bv:%d failed %d\n","usb-ipa",uVar2,iVar1);
    }
    iVar1 = icc_set_bw(param_1[0x60],*(undefined4 *)(bus_vote_values + (ulong)uVar2 * 0x18 + 0x10),
                       *(undefined4 *)(bus_vote_values + (ulong)uVar2 * 0x18 + 0x14));
    if (iVar1 != 0) {
      _dev_err(*param_1,"bus bw voting path:%s bv:%d failed %d\n","ddr-usb",uVar2,iVar1);
    }
    dwc3_dbg_print(param_1[0xa5],0xff,"bus_vote_end",uVar2,&DAT_00111364);
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_host_ss_powerdown @ 0010b2c4 size=340
// signature: undefined dwc3_msm_host_ss_powerdown(void)
// callers: [dwc3_msm_host_notifier]
//------------------------------------------------------------

void dwc3_msm_host_ss_powerdown(long param_1)

{
  uint uVar1;
  long lVar2;
  uint *puVar3;
  code *pcVar4;
  
  if ((*(char *)(param_1 + 0x329) == '\0') && (*(int *)(param_1 + 0xa48) == 0)) {
    if (*(long *)(param_1 + 0x28) == 0) {
      puVar3 = (uint *)(param_1 + 0x4c0);
    }
    else {
      puVar3 = (uint *)(*(long *)(*(long *)(param_1 + 0x28) + 0xa8) + 0x45c);
    }
    if (4 < *puVar3) {
      uVar1 = readl(*(long *)(param_1 + 8) + 0xf89e4);
      writel(uVar1 | 0x20,*(long *)(param_1 + 8) + 0xf89e4);
      lVar2 = *(long *)(param_1 + 8) + 0xf8808;
      uVar1 = readl(lVar2);
      writel(uVar1 | 0x100,lVar2);
      __const_udelay(0x53e3);
      uVar1 = readl(*(long *)(param_1 + 8) + 0xf8808);
      writel(uVar1 | 9,*(long *)(param_1 + 8) + 0xf8808);
      __const_udelay(0x53e3);
      lVar2 = *(long *)(param_1 + 8) + 0xf8808;
      uVar1 = readl(lVar2);
      writel(uVar1 & 0xfffffeff,lVar2);
      lVar2 = *(long *)(param_1 + 0x1c8);
      if (lVar2 != 0) {
        pcVar4 = *(code **)(lVar2 + 0x150);
        if (pcVar4 != (code *)0x0) {
          if (*(int *)(pcVar4 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10b3d0);
            (*pcVar4)();
          }
          (*pcVar4)(lVar2,5);
          lVar2 = *(long *)(param_1 + 0x1c8);
          if (lVar2 == 0) {
            return;
          }
        }
        pcVar4 = *(code **)(lVar2 + 0x138);
        if (pcVar4 != (code *)0x0) {
          if (*(int *)(pcVar4 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10b400);
            (*pcVar4)();
          }
          (*pcVar4)(lVar2,1);
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_update_interfaces @ 0010b418 size=184
// signature: undefined dwc3_msm_update_interfaces(void)
// callers: [dwc3_msm_host_notifier]
//------------------------------------------------------------

void dwc3_msm_update_interfaces(long param_1)

{
  code *pcVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  lVar2 = *(long *)(param_1 + 0x460);
  if ((lVar2 != 0) && (*(char *)(lVar2 + 4) != '\0')) {
    uVar4 = 0;
    do {
      if (uVar4 == 0x20) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10b4d0);
        (*pcVar1)();
      }
      plVar3 = *(long **)(lVar2 + uVar4 * 8 + 0x98);
      if (*(char *)(*plVar3 + 5) == '\x01') {
        lVar2 = plVar3[0x17];
        if (lVar2 == 0) {
          _dev_err(plVar3 + 6,"can\'t override USB audio OPs\n");
        }
        else {
          *(code **)(lVar2 + -0x38) = usb_audio_pre_reset;
          *(code **)(lVar2 + -0x30) = usb_audio_post_reset;
        }
      }
      lVar2 = *(long *)(param_1 + 0x460);
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(byte *)(lVar2 + 4));
  }
  return;
}



//------------------------------------------------------------
// usb_audio_pre_reset @ 0010b4d4 size=8
// signature: undefined usb_audio_pre_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_audio_pre_reset(void)

{
  return 0;
}



//------------------------------------------------------------
// usb_audio_post_reset @ 0010b4e0 size=84
// signature: undefined usb_audio_post_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_audio_post_reset(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x90);
  _dev_info(lVar1,"USB bus reset recovery triggered\n");
  if (*(long *)(*(long *)(lVar1 + -0x60) + 0x48) == 0) {
    kobject_uevent(param_1 + 0x30,2);
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_override_vbus_status @ 0010b534 size=212
// signature: undefined dwc3_override_vbus_status(void)
// callers: [dwc3_otg_start_peripheral, dwc3_msm_vbus_notifier]
//------------------------------------------------------------

void dwc3_override_vbus_status(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 8) + 0xf8810;
  uVar1 = readl(lVar4);
  uVar2 = 0x100000;
  if ((param_2 & 1) == 0) {
    uVar2 = 0;
  }
  writel(uVar1 & 0xffefffff | uVar2,lVar4);
  readl(lVar4);
  if ((param_2 & 1) == 0) {
    lVar4 = *(long *)(param_1 + 8) + 0xf8830;
    uVar2 = readl(lVar4);
    uVar2 = uVar2 & 0xfeffffff;
  }
  else {
    if (*(long *)(param_1 + 0x28) == 0) {
      puVar3 = (uint *)(param_1 + 0x4c0);
    }
    else {
      puVar3 = (uint *)(*(long *)(*(long *)(param_1 + 0x28) + 0xa8) + 0x45c);
    }
    if (*puVar3 < 5) {
      return;
    }
    lVar4 = *(long *)(param_1 + 8) + 0xf8830;
    uVar2 = readl(lVar4);
    uVar2 = uVar2 | 0x1000000;
  }
  writel(uVar2,lVar4);
  readl(lVar4);
  return;
}



//------------------------------------------------------------
// qos_rec_irq_open @ 0010b60c size=48
// signature: undefined qos_rec_irq_open(void)
// callers: []
//------------------------------------------------------------

void qos_rec_irq_open(long param_1,undefined8 param_2)

{
  single_open(param_2,qos_rec_irq_read,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qos_rec_irq_read @ 0010b640 size=112
// signature: undefined qos_rec_irq_read(void)
// callers: []
//------------------------------------------------------------

undefined8 qos_rec_irq_read(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = *(long *)(param_1 + 0x80);
  lVar2 = 0;
  do {
    seq_printf(param_1,&DAT_0011381d,*(undefined4 *)(lVar1 + 0xa64 + lVar2));
    lVar2 = lVar2 + 4;
  } while (lVar2 != 200);
  seq_puts(param_1,&DAT_00112eda);
  return 0;
}



//------------------------------------------------------------
// msm_dwc3_pwr_irq @ 0010b6b4 size=152
// signature: undefined msm_dwc3_pwr_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_dwc3_pwr_irq(undefined4 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  
  _dev_info(*param_2,"%s received %d\n","msm_dwc3_pwr_irq",param_1);
  if (*(int *)(param_2 + 0x6e) == 0) {
    _dev_info(*param_2,"%s resume_pending=%d, clean resume_pending\n","msm_dwc3_pwr_irq",
              *(undefined1 *)(param_2 + 0x3e));
    *(undefined1 *)(param_2 + 0x3e) = 0;
    dwc3_pwr_event_handler(param_2);
    uVar1 = 1;
  }
  else {
    _dev_info(*param_2,"%s resume_pending=%d, set resume_pending\n","msm_dwc3_pwr_irq",
              *(undefined1 *)(param_2 + 0x3e));
    uVar1 = 2;
    *(undefined1 *)(param_2 + 0x3e) = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_dwc3_pwr_irq_thread @ 0010b750 size=172
// signature: undefined msm_dwc3_pwr_irq_thread(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_dwc3_pwr_irq_thread(undefined4 param_1,undefined8 *param_2)

{
  _dev_info(*param_2,"%s received %d\n","msm_dwc3_pwr_irq_thread",param_1);
  if (*(int *)(param_2 + 0x6e) == 0) {
    _dev_info(*param_2,"%s pwr irq handle\n","msm_dwc3_pwr_irq_thread");
    dwc3_pwr_event_handler(param_2);
  }
  else {
    _dev_info(*param_2,"%s pwr irq resume\n","msm_dwc3_pwr_irq_thread");
    dwc3_resume_work(param_2 + 0x45);
  }
  dwc3_dbg_print(param_2[0xa5],0xff,"PWR IRQ",*(undefined4 *)(param_2 + 0x6e),&DAT_00111364);
  return 1;
}



//------------------------------------------------------------
// dwc3_pwr_event_handler @ 0010b7fc size=388
// signature: undefined dwc3_pwr_event_handler(void)
// callers: [msm_dwc3_pwr_irq_thread, dwc3_msm_resume, msm_dwc3_pwr_irq]
//------------------------------------------------------------

void dwc3_pwr_event_handler(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  
  if (param_1[5] == 0) {
    return;
  }
  if (param_1[100] == 0) {
    return;
  }
  lVar4 = *(long *)(param_1[5] + 0xa8);
  uVar1 = readl(param_1[1] + 0xf8858);
  _dev_info(*param_1,"%s irq_stat=%X\n","dwc3_pwr_event_handler",uVar1);
  if ((~uVar1 & 0xc) == 0) {
    dwc3_msm_set_in_p3_state(param_1);
    uVar1 = uVar1 & 0xfffffff3;
    uVar3 = 0xc;
  }
  else if ((uVar1 >> 3 & 1) == 0) {
    if ((uVar1 >> 2 & 1) == 0) {
      uVar3 = 0;
    }
    else {
      uVar1 = uVar1 & 0xfffffffb;
      uVar3 = 4;
      *(undefined4 *)((long)param_1 + 0x36c) = 1;
    }
  }
  else {
    uVar1 = uVar1 & 0xfffffff7;
    uVar3 = 8;
    *(undefined4 *)((long)param_1 + 0x36c) = 0;
  }
  if ((uVar1 >> 0xd & 1) != 0) {
    _dev_info(*param_1,"%s: handling PWR_EVNT_LPM_OUT_L1_MASK\n","dwc3_pwr_event_handler");
    if (((*(char *)(param_1 + 0x61) == '\0') && (lVar4 != 0)) &&
       (iVar2 = usb_gadget_wakeup(*(undefined8 *)(lVar4 + 0x370)), iVar2 != 0)) {
      _dev_err(*param_1,"%s failed to take dwc out of L1\n","dwc3_pwr_event_handler");
    }
    uVar1 = uVar1 & 0xffffdfff;
    uVar3 = uVar3 | 0x2000;
  }
  if ((uVar1 >> 5 & 1) != 0) {
    _dev_info(*param_1,"%s: handling PWR_EVNT_LPM_OUT_L2_MASK\n","dwc3_pwr_event_handler");
    uVar1 = uVar1 & 0xffffffdf;
    uVar3 = uVar3 | 0x20;
  }
  if (uVar1 != 0) {
    _dev_info(*param_1,"%s: unexpected PWR_EVNT, irq_stat=%X\n","dwc3_pwr_event_handler",uVar1);
  }
  writel(uVar3,param_1[1] + 0xf8858);
  return;
}



//------------------------------------------------------------
// dwc3_msm_set_in_p3_state @ 0010b980 size=136
// signature: undefined dwc3_msm_set_in_p3_state(void)
// callers: [dwc3_pwr_event_handler]
//------------------------------------------------------------

void dwc3_msm_set_in_p3_state(undefined8 *param_1)

{
  long lVar1;
  uint uVar2;
  
  if (param_1[5] != 0) {
    lVar1 = 0xc164;
    if (*(int *)(*(long *)(param_1[5] + 0xa8) + 0x46c) != 0x5533) {
      lVar1 = 0xd050;
    }
    uVar2 = readl(param_1[1] + lVar1);
    uVar2 = uVar2 >> 0x16 & 0xf;
    _dev_info(*param_1,"%s link state = 0x%04x\n","dwc3_msm_set_in_p3_state",uVar2);
    *(uint *)((long)param_1 + 0x36c) = (uint)(uVar2 == 3);
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_modeled_d3_to_d0 @ 0010ba08 size=244
// signature: undefined dwc3_msm_modeled_d3_to_d0(void)
// callers: [dwc3_msm_probe, dwc3_msm_resume]
//------------------------------------------------------------

int dwc3_msm_modeled_d3_to_d0(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  
  lVar7 = **(long **)(param_1 + 0xb38);
  iVar5 = __pm_runtime_resume(lVar7,4);
  if (iVar5 < 0) {
    piVar1 = (int *)(lVar7 + 0x1f8);
    iVar6 = *(int *)(lVar7 + 0x1f8);
    do {
      if (iVar6 == 0) {
        return iVar5;
      }
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar6) goto LAB_0010ba90;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar6 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010ba90:
      bVar4 = iVar6 != iVar2;
      iVar6 = iVar2;
    } while (bVar4);
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 0xb38) + 8);
    iVar5 = __pm_runtime_resume(lVar7,4);
    if (iVar5 < 0) {
      piVar1 = (int *)(lVar7 + 0x1f8);
      iVar6 = *(int *)(lVar7 + 0x1f8);
      do {
        if (iVar6 == 0) {
          return iVar5;
        }
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar6) goto LAB_0010baf0;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010baf0:
        bVar4 = iVar6 != iVar2;
        iVar6 = iVar2;
      } while (bVar4);
    }
    else {
      iVar5 = 0;
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// dwc3_msm_modeled_d0_to_d3 @ 0010bb24 size=72
// signature: undefined dwc3_msm_modeled_d0_to_d3(void)
// callers: [dwc3_msm_resume]
//------------------------------------------------------------

void dwc3_msm_modeled_d0_to_d3(long param_1)

{
  int iVar1;
  
  iVar1 = __pm_runtime_idle(**(undefined8 **)(param_1 + 0xb38),4);
  if (iVar1 == 0) {
    __pm_runtime_idle(*(undefined8 *)(*(long *)(param_1 + 0xb38) + 8),4);
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_config_gdsc @ 0010bb6c size=148
// signature: undefined dwc3_msm_config_gdsc(void)
// callers: [dwc3_msm_resume]
//------------------------------------------------------------

void dwc3_msm_config_gdsc(undefined8 *param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if (((*(char *)((long)param_1 + 0xb31) == '\0') && (param_1[0x37] != 0)) &&
     ((ulong)param_1[0x37] < 0xfffffffffffff001)) {
    if (param_2 == 0) {
      qcom_clk_set_flags(param_1[0x2a],3);
      iVar1 = regulator_disable(param_1[0x37]);
      if (iVar1 == 0) {
        return;
      }
      uVar2 = *param_1;
      pcVar3 = "unable to disable usb3 gdsc\n";
    }
    else {
      iVar1 = regulator_enable();
      if (iVar1 == 0) {
        qcom_clk_set_flags(param_1[0x2a],2);
        return;
      }
      uVar2 = *param_1;
      pcVar3 = "unable to enable usb3 gdsc\n";
    }
    _dev_err(uVar2,pcVar3);
  }
  return;
}



//------------------------------------------------------------
// clk_prepare_enable @ 0010bc00 size=76
// signature: undefined clk_prepare_enable(void)
// callers: [dwc3_clk_enable_disable]
//------------------------------------------------------------

int clk_prepare_enable(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = clk_prepare();
  if (iVar1 == 0) {
    iVar1 = clk_enable(param_1);
    if (iVar1 != 0) {
      clk_unprepare(param_1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// dwc3_msm_vbus_notifier @ 0010bc50 size=416
// signature: undefined dwc3_msm_vbus_notifier(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

undefined8 dwc3_msm_vbus_notifier(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_3 != 0) && (puVar3 = *(undefined8 **)(param_1 + -0x10), puVar3 != (undefined8 *)0x0)) {
    if (puVar3[5] == 0) {
      lVar4 = 0;
    }
    else {
      lVar4 = *(long *)(puVar3[5] + 0xa8);
    }
    dwc3_dbg_print(puVar3[0xa5],0xff,"extcon idx",*(undefined4 *)(param_1 + -8),&DAT_00111364);
    _dev_info(*puVar3,"vbus:%ld event received\n",param_2);
    uVar2 = extcon_get_edev_name(param_3);
    ipc_log_string(puVar3[0xa5],"%s: edev:%s\n","dwc3_msm_vbus_notifier",uVar2);
    if (*(char *)(puVar3[0x68] + (long)*(int *)(param_1 + -8) * 0x50 + 0x48) == '\0') {
      if (*(byte *)((long)puVar3 + 0x312) == param_2) {
        return 0;
      }
      *(bool *)((long)puVar3 + 0x312) = param_2 != 0;
    }
    else {
      iVar1 = extcon_get_state(param_3,0x3d);
      if (*(byte *)((long)puVar3 + 0x313) == param_2) {
        return 0;
      }
      *(bool *)((long)puVar3 + 0x313) = param_2 != 0;
      if ((lVar4 == 0) || (*(uint *)(*(long *)(lVar4 + 0x370) + 0x58) < 5)) {
        if ((iVar1 == 0) && (*(int *)(puVar3 + 0x5b) != 0)) {
          dwc3_override_vbus_status(puVar3,param_2 != 0);
          return 0;
        }
      }
      else {
        wcd_usbss_dpdm_switch_update(param_2 != 0,param_2 != 0);
        if (iVar1 == 0) {
          return 0;
        }
      }
      *(undefined1 *)((long)puVar3 + 0x311) = 1;
    }
    *(undefined4 *)(puVar3 + 0x69) = *(undefined4 *)(param_1 + -8);
    if ((*(int *)((long)puVar3 + 0x2dc) == 3) && (*(char *)(puVar3 + 0x51) == '\0')) {
      queue_work_on(0x20,puVar3[0x52],puVar3 + 0x45);
    }
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_id_notifier @ 0010bdf4 size=204
// signature: undefined dwc3_msm_id_notifier(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

undefined8 dwc3_msm_id_notifier(long param_1,long param_2,long param_3)

{
  bool bVar1;
  undefined8 *puVar2;
  
  if ((param_3 != 0) && (puVar2 = *(undefined8 **)(param_1 + -0x28), puVar2 != (undefined8 *)0x0)) {
    dwc3_dbg_print(puVar2[0xa5],0xff,"extcon idx",*(undefined4 *)(param_1 + -0x20),&DAT_00111364);
    bVar1 = param_2 == 0;
    if (*(uint *)(puVar2 + 99) != (uint)bVar1) {
      *(undefined4 *)(puVar2 + 0x69) = *(undefined4 *)(param_1 + -0x20);
      _dev_info(*puVar2,"host:%ld (id:%d) event received\n",param_2,(uint)bVar1);
      *(uint *)(puVar2 + 99) = (uint)bVar1;
      dwc3_dbg_print(puVar2[0xa5],0xff,"id_state",bVar1,&DAT_00111364);
      queue_work_on(0x20,puVar2[0x52],puVar2 + 0x45);
    }
  }
  return 0;
}



//------------------------------------------------------------
// orientation_show @ 0010bec4 size=92
// signature: undefined orientation_show(void)
// callers: []
//------------------------------------------------------------

long orientation_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(long *)(param_1 + 0x98) + 0x51c);
  pcVar1 = "B\n";
  if (iVar3 != 8) {
    pcVar1 = "none\n";
  }
  pcVar2 = "A\n";
  if (iVar3 != 4) {
    pcVar2 = pcVar1;
  }
  iVar3 = scnprintf(param_3,0x1000,pcVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// orientation_store @ 0010bf24 size=124
// signature: undefined orientation_store(void)
// callers: []
//------------------------------------------------------------

undefined8 orientation_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  uVar1 = sysfs_streq(param_3,&DAT_0011316c);
  if ((uVar1 & 1) == 0) {
    uVar1 = sysfs_streq(param_3,&DAT_00110436);
    if ((uVar1 & 1) == 0) {
      *(undefined4 *)(lVar2 + 0x51c) = 0;
    }
    else {
      *(undefined4 *)(lVar2 + 0x51c) = 8;
    }
  }
  else {
    *(undefined4 *)(lVar2 + 0x51c) = 4;
  }
  return param_4;
}



//------------------------------------------------------------
// mode_show @ 0010bfa4 size=92
// signature: undefined mode_show(void)
// callers: []
//------------------------------------------------------------

long mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  
  if (*(char *)(*(long *)(param_1 + 0x98) + 0x312) == '\0') {
    pcVar2 = "host\n";
    if (*(int *)(*(long *)(param_1 + 0x98) + 0x318) != 0) {
      pcVar2 = "none\n";
    }
  }
  else {
    pcVar2 = "peripheral\n";
  }
  iVar1 = scnprintf(param_3,0x1000,pcVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// mode_store @ 0010c004 size=160
// signature: undefined mode_store(void)
// callers: []
//------------------------------------------------------------

long mode_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  uVar3 = sysfs_streq(param_3,"peripheral");
  if ((uVar3 & 1) == 0) {
    uVar1 = sysfs_streq(param_3,&DAT_00113803);
    uVar1 = uVar1 & 1;
  }
  else {
    uVar1 = 2;
  }
  ipc_log_string(*(undefined8 *)(lVar4 + 0x528),"%s: mode_request:%s\n","mode_store",
                 (&usb_role_strings)[uVar1]);
  iVar2 = dwc3_msm_set_role(lVar4,uVar1);
  lVar4 = (long)iVar2;
  if (-1 < iVar2) {
    lVar4 = param_4;
  }
  return lVar4;
}



//------------------------------------------------------------
// speed_show @ 0010c0a8 size=100
// signature: undefined speed_show(void)
// callers: []
//------------------------------------------------------------

long speed_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0x28);
  if (lVar4 == 0) {
    puVar3 = (undefined4 *)(*(long *)(param_1 + 0x98) + 0x4c0);
  }
  else {
    puVar3 = (undefined4 *)(*(long *)(lVar4 + 0xa8) + 0x45c);
  }
  uVar2 = usb_speed_string(*puVar3);
  iVar1 = scnprintf(param_3,0x1000,&DAT_00112789,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// speed_store @ 0010c110 size=292
// signature: undefined speed_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 speed_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  uint *puVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  if ((*(ulong *)(lVar5 + 0x2d0) & 1) == 0) {
    return 0xffffffffffffffff;
  }
  uVar1 = sysfs_streq(param_3,&DAT_00111cda);
  if ((uVar1 & 1) == 0) {
    uVar1 = sysfs_streq(param_3,&DAT_001131f7);
    if ((uVar1 & 1) == 0) {
      uVar1 = sysfs_streq(param_3,"super");
      if ((uVar1 & 1) == 0) {
        uVar1 = sysfs_streq(param_3,&DAT_0011297b);
        if ((uVar1 & 1) == 0) {
          return 0xffffffffffffffea;
        }
        uVar2 = 6;
        lVar3 = *(long *)(lVar5 + 0x28);
      }
      else {
        uVar2 = 5;
        lVar3 = *(long *)(lVar5 + 0x28);
      }
    }
    else {
      uVar2 = 3;
      lVar3 = *(long *)(lVar5 + 0x28);
    }
  }
  else {
    uVar2 = 2;
    lVar3 = *(long *)(lVar5 + 0x28);
  }
  if (lVar3 == 0) {
    puVar4 = (uint *)(lVar5 + 0x4c0);
  }
  else {
    puVar4 = (uint *)(*(long *)(lVar3 + 0xa8) + 0x45c);
  }
  if (uVar2 == *puVar4 || *(uint *)(lVar5 + 0x4c4) < uVar2) {
    if (*(uint *)(lVar5 + 0x4c4) <= uVar2) {
      *(undefined4 *)(lVar5 + 0x4c0) = 0;
    }
  }
  else {
    *(uint *)(lVar5 + 0x4c0) = uVar2;
    queue_work_on(0x20,_system_wq,lVar5 + 600);
  }
  return param_4;
}



//------------------------------------------------------------
// bus_vote_show @ 0010c238 size=116
// signature: undefined bus_vote_show(void)
// callers: []
//------------------------------------------------------------

long bus_vote_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  long lVar4;
  
  if (*(char *)(*(long *)(param_1 + 0x98) + 0xb31) == '\0') {
    iVar3 = *(int *)(*(long *)(param_1 + 0x98) + 0x2e8);
    pcVar1 = "Fixed bus vote: max";
    if (iVar3 != 4) {
      pcVar1 = "Do not have fixed bus vote";
    }
    pcVar2 = "Fixed bus vote: min";
    if (iVar3 != 3) {
      pcVar2 = pcVar1;
    }
    iVar3 = scnprintf(param_3,0x1000,&DAT_00112789,pcVar2);
    lVar4 = (long)iVar3;
  }
  else {
    lVar4 = -0x16;
  }
  return lVar4;
}



//------------------------------------------------------------
// bus_vote_store @ 0010c2b0 size=244
// signature: undefined bus_vote_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bus_vote_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar3 + 0xb31) != '\0') {
    return 0xffffffffffffffea;
  }
  uVar1 = sysfs_streq(param_3,&DAT_0011161b);
  if ((uVar1 & 1) == 0) {
    uVar1 = sysfs_streq(param_3,&DAT_00113417);
    if ((uVar1 & 1) == 0) {
      uVar1 = sysfs_streq(param_3,"cancel");
      if ((uVar1 & 1) == 0) {
        _dev_err(param_1,"min/max/cancel only.\n");
        return 0xffffffffffffffea;
      }
      *(undefined4 *)(lVar3 + 0x2e8) = 0;
      if (*(int *)(lVar3 + 0x370) != 0) {
        return param_4;
      }
      if ((*(char *)(lVar3 + 0x308) == '\0') || (*(int *)(lVar3 + 0x30c) != 3)) {
        uVar2 = *(undefined4 *)(lVar3 + 0x2e4);
      }
      else {
        uVar2 = 2;
      }
      goto LAB_0010c324;
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 3;
  }
  *(undefined4 *)(lVar3 + 0x2e8) = uVar2;
  if (*(int *)(lVar3 + 0x370) != 0) {
    return param_4;
  }
LAB_0010c324:
  dwc3_msm_update_bus_bw(lVar3,uVar2);
  return param_4;
}



//------------------------------------------------------------
// enable_l1_suspend_show @ 0010c3a8 size=104
// signature: undefined enable_l1_suspend_show(void)
// callers: []
//------------------------------------------------------------

long enable_l1_suspend_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x98) + 0x28) + 0xa8);
  if ((*(char *)(*(long *)(param_1 + 0x98) + 0x2e0) == '\0') && (*(int *)(lVar2 + 1000) == 1)) {
    lVar2 = -1;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00111060,
                      *(uint *)(*(long *)(lVar2 + 0x370) + 0x420) >> 0x10 & 1);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// enable_l1_suspend_store @ 0010c414 size=288
// signature: undefined enable_l1_suspend_store(void)
// callers: []
//------------------------------------------------------------

long enable_l1_suspend_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  char *pcVar1;
  undefined6 uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  byte local_3c [4];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_3c[0] = 0;
  lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x98) + 0x28) + 0xa8);
  if ((*(char *)(*(long *)(param_1 + 0x98) + 0x2e0) == '\0') && (*(int *)(lVar5 + 1000) == 1)) {
    param_4 = -1;
  }
  else {
    iVar3 = kstrtobool(param_3,local_3c);
    if (iVar3 < 0) {
      _dev_err(*(undefined8 *)(lVar5 + 400),"%s: can\'t get entered value: %d\n",
               "enable_l1_suspend_store",iVar3);
      param_4 = (long)iVar3;
    }
    else {
      uVar4 = (uint)local_3c[0];
      pcVar1 = "disabled";
      if (uVar4 != 0) {
        pcVar1 = "enabled";
      }
      *(uint *)(*(long *)(lVar5 + 0x370) + 0x420) =
           *(uint *)(*(long *)(lVar5 + 0x370) + 0x420) & 0xfffeffff | uVar4 << 0x10;
      uVar2 = *(undefined6 *)(lVar5 + 0x4e8);
      *(uint *)(lVar5 + 0x4e8) = (uint)uVar2 & 0xfffbffff | (uint)(uVar4 == 0) << 0x12;
      *(short *)(lVar5 + 0x4ec) = (short)((uint6)uVar2 >> 0x20);
      _printk(&DAT_001121ae,pcVar1);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// xhci_test_store @ 0010c538 size=228
// signature: undefined xhci_test_store(void)
// callers: []
//------------------------------------------------------------

undefined8 xhci_test_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (*(long *)(lVar3 + 0x28) != 0) {
    if ((*(char *)(lVar3 + 0x312) == '\0') && (*(int *)(lVar3 + 0x318) == 0)) {
      lVar2 = *(long *)(*(long *)(lVar3 + 0x28) + 0xa8);
      __pm_runtime_resume(*(long *)(lVar2 + 0x1a0) + 0x10,0);
      pm_runtime_forbid(*(long *)(lVar2 + 0x1a0) + 0x10);
      uVar1 = readl(*(long *)(lVar3 + 8) + (ulong)(*(int *)(lVar3 + 0xb40) + 0x404));
      _dev_info(param_1,"USB PORTPMSC val:%x\n",uVar1);
      _dev_info(param_1,"writing %x to USB PORTPMSC\n",uVar1 | 0x40000000);
      writel(uVar1 | 0x40000000,*(long *)(lVar3 + 8) + (ulong)(*(int *)(lVar3 + 0xb40) + 0x404));
    }
    else {
      _dev_err(param_1,"USB is not in host mode\n");
    }
  }
  return param_4;
}



//------------------------------------------------------------
// dynamic_disable_store @ 0010c620 size=412
// signature: undefined dynamic_disable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
dynamic_disable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  undefined8 *puVar9;
  char local_3c [4];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  puVar9 = *(undefined8 **)(param_1 + 0x98);
  local_3c[0] = '\0';
  kstrtobool(param_3,local_3c);
  if (local_3c[0] == '\0') {
    if (*(char *)((long)puVar9 + 0xa52) == '\0') {
      pcVar7 = "%s: USB already enabled\n";
    }
    else if ((puVar9[2] == 0) || (iVar6 = readl(), iVar6 == 0xf)) {
      *(undefined1 *)((long)puVar9 + 0xa52) = 0;
      __pm_runtime_disable(*puVar9,1);
      __pm_runtime_set_status(*puVar9,2);
      pm_runtime_enable(*puVar9);
      dwc3_ext_event_notify(puVar9);
      flush_work(puVar9 + 0x54);
      pcVar7 = "%s: Dynamic USB enable\n";
    }
    else {
      pcVar7 = "%s: Unable to enable USB\n";
    }
  }
  else if (*(char *)((long)puVar9 + 0xa52) == '\0') {
    puVar1 = puVar9 + 0x54;
    flush_work(puVar1);
    puVar2 = puVar9 + 0x5a;
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 | 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    puVar2 = puVar9 + 0x5a;
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & 0xfffffffffffffffd;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    queue_work_on(0x20,puVar9[0x53],puVar1);
    flush_work(puVar1);
    uVar8 = (uint)puVar9[0x5a];
    while ((uVar8 >> 3 & 1) != 0) {
      msleep(0x14);
      uVar8 = (uint)puVar9[0x5a];
    }
    pcVar7 = "%s: Dynamic USB disable\n";
    *(undefined1 *)((long)puVar9 + 0xa52) = 1;
  }
  else {
    pcVar7 = "%s: USB already disabled\n";
  }
  ipc_log_string(puVar9[0xa5],pcVar7,"dynamic_disable_store");
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dwc3_msm_pm_suspend @ 0010c7d8 size=404
// signature: undefined dwc3_msm_pm_suspend(void)
// callers: []
//------------------------------------------------------------

int dwc3_msm_pm_suspend(long param_1)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  undefined8 *puVar6;
  
  puVar6 = *(undefined8 **)(param_1 + 0x98);
  if (puVar6[5] == 0) {
    uVar1 = *(ushort *)(param_1 + 0x10c);
  }
  else {
    _dev_info(param_1,"dwc3-msm PM suspend\n");
    dwc3_dbg_print(puVar6[0xa5],0xff,"PM Sus",0,&DAT_00111364);
    if ((*(char *)(puVar6 + 0x65) == '\0') || (*(char *)(puVar6 + 0x61) == '\0')) {
      if (*(int *)(puVar6 + 0x6e) == 0) {
        _dev_err(*puVar6,"Abort PM suspend!! (USB is outside LPM)\n");
        return -0x10;
      }
      *(undefined4 *)((long)puVar6 + 500) = 1;
      return 0;
    }
    lVar4 = puVar6[0x38];
    if ((lVar4 != 0) && (pcVar5 = *(code **)(lVar4 + 0x150), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10c878);
        (*pcVar5)();
      }
      (*pcVar5)(lVar4,3);
      lVar4 = puVar6[0x38];
    }
    *(uint *)(lVar4 + 0x10) = *(uint *)(lVar4 + 0x10) & 0xfffffffe;
    lVar4 = puVar6[0x39];
    if ((lVar4 != 0) && (pcVar5 = *(code **)(lVar4 + 0x150), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10c8b8);
        (*pcVar5)();
      }
      (*pcVar5)(lVar4,5);
      lVar4 = puVar6[0x39];
    }
    *(uint *)(lVar4 + 0x10) = *(uint *)(lVar4 + 0x10) & 0xfffffffe;
    uVar1 = *(ushort *)(param_1 + 0x10c);
  }
  if ((uVar1 & 1) == 0) {
    bVar2 = false;
  }
  else {
    bVar2 = *(long *)(param_1 + 0x148) != 0;
  }
  iVar3 = dwc3_msm_suspend(puVar6,1,bVar2);
  if (iVar3 == 0) {
    *(undefined4 *)((long)puVar6 + 500) = 1;
    uVar1 = *(ushort *)(param_1 + 0x10c);
  }
  else {
    uVar1 = *(ushort *)(param_1 + 0x10c);
  }
  if (((uVar1 & 1) == 0) || (*(long *)(param_1 + 0x148) == 0)) {
    dwc3_msm_interrupt_enable(puVar6,0);
  }
  return iVar3;
}



//------------------------------------------------------------
// dwc3_msm_pm_resume @ 0010c970 size=436
// signature: undefined dwc3_msm_pm_resume(void)
// callers: []
//------------------------------------------------------------

int dwc3_msm_pm_resume(long param_1)

{
  int iVar1;
  code *pcVar2;
  uint *puVar3;
  undefined8 *puVar4;
  long lVar5;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4[5] == 0) {
    lVar5 = 0;
  }
  else {
    lVar5 = *(long *)(puVar4[5] + 0xa8);
  }
  _dev_info(param_1,"dwc3-msm PM resume\n");
  dwc3_dbg_print(puVar4[0xa5],0xff,"PM Res",0,&DAT_00111364);
  *(undefined4 *)((long)puVar4 + 500) = 0;
  if (*(char *)(puVar4 + 0x61) == '\0') {
    if (lVar5 == 0) {
      return 0;
    }
    if ((*(byte *)(*(long *)(lVar5 + 400) + 0x150) >> 1 & 1) == 0) {
      return 0;
    }
  }
  else {
    iVar1 = dwc3_msm_resume(puVar4);
    if (iVar1 != 0) {
      _dev_err(*puVar4,"%s: dwc3_msm_resume failed\n","dwc3_msm_pm_resume");
      *(undefined4 *)((long)puVar4 + 500) = 1;
      return iVar1;
    }
    __pm_runtime_disable(param_1,1);
    __pm_runtime_set_status(param_1,0);
    pm_runtime_enable(param_1);
    if ((*(char *)(puVar4 + 0x65) != '\0') && (*(char *)(puVar4 + 0x61) != '\0')) {
      *(uint *)(puVar4[0x38] + 0x10) = *(uint *)(puVar4[0x38] + 0x10) | 1;
      lVar5 = puVar4[0x38];
      if ((lVar5 != 0) && (pcVar2 = *(code **)(lVar5 + 0x148), pcVar2 != (code *)0x0)) {
        if (*(int *)(pcVar2 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10ca54);
          (*pcVar2)();
        }
        (*pcVar2)(lVar5,3);
      }
      if (puVar4[5] == 0) {
        puVar3 = (uint *)(puVar4 + 0x98);
      }
      else {
        puVar3 = (uint *)(*(long *)(puVar4[5] + 0xa8) + 0x45c);
      }
      if (4 < *puVar3) {
        *(uint *)(puVar4[0x39] + 0x10) = *(uint *)(puVar4[0x39] + 0x10) | 1;
        lVar5 = puVar4[0x39];
        if ((lVar5 != 0) && (pcVar2 = *(code **)(lVar5 + 0x148), pcVar2 != (code *)0x0)) {
          if (*(int *)(pcVar2 + -4) != 0x56343779) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10cacc);
            (*pcVar2)();
          }
          (*pcVar2)(lVar5,5);
        }
      }
    }
  }
  queue_work_on(0x20,puVar4[0x52],puVar4 + 0x45);
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_runtime_suspend @ 0010cb28 size=144
// signature: undefined dwc3_msm_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

void dwc3_msm_runtime_suspend(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (*(long *)(lVar1 + 0x28) == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = *(long *)(*(long *)(lVar1 + 0x28) + 0xa8);
  }
  _dev_info(param_1,"DWC3-msm runtime suspend\n");
  dwc3_dbg_print(*(undefined8 *)(lVar1 + 0x528),0xff,"RT Sus",0,&DAT_00111364);
  if (lVar2 != 0) {
    uVar3 = *(undefined8 *)(lVar2 + 400);
    device_wakeup_disable(uVar3);
    device_set_wakeup_capable(uVar3,0);
  }
  dwc3_msm_suspend(lVar1,0,1);
  return;
}



//------------------------------------------------------------
// dwc3_msm_runtime_resume @ 0010cbbc size=88
// signature: undefined dwc3_msm_runtime_resume(void)
// callers: []
//------------------------------------------------------------

void dwc3_msm_runtime_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  _dev_info(param_1,"DWC3-msm runtime resume\n");
  dwc3_dbg_print(*(undefined8 *)(lVar1 + 0x528),0xff,"RT Res",0,&DAT_00111364);
  dwc3_msm_resume(lVar1);
  return;
}



//------------------------------------------------------------
// dwc3_msm_runtime_idle @ 0010cc18 size=84
// signature: undefined dwc3_msm_runtime_idle(void)
// callers: []
//------------------------------------------------------------

undefined8 dwc3_msm_runtime_idle(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  _dev_info(param_1,"DWC3-msm runtime idle\n");
  dwc3_dbg_print(*(undefined8 *)(lVar1 + 0x528),0xff,"RT Idle",0,&DAT_00111364);
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_suspend @ 0010cc6c size=2576
// signature: undefined dwc3_msm_suspend(void)
// callers: [dwc3_msm_runtime_suspend, dwc3_msm_pm_suspend]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int dwc3_msm_suspend(undefined8 *param_1,ulong param_2,uint param_3)

{
  undefined8 *puVar1;
  long lVar2;
  ulong *puVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  char *pcVar11;
  code *pcVar12;
  uint *puVar13;
  ulong uVar14;
  long lVar15;
  
  if (param_1[5] == 0) {
    lVar15 = 0;
  }
  else {
    lVar15 = *(long *)(param_1[5] + 0xa8);
  }
  puVar1 = param_1 + 0x8c;
  mutex_lock(puVar1);
  if (*(int *)(param_1 + 0x6e) == 0) {
    if (lVar15 == 0) {
LAB_0010cd00:
      if ((*(char *)((long)param_1 + 0x312) != '\0') ||
         ((*(int *)((long)param_1 + 0x2dc) != 3 || (*(int *)(param_1 + 0x5b) != 2)))) {
        if ((*(char *)(param_1 + 0x61) != '\0') || (*(char *)((long)param_1 + 0x309) != '\0')) {
          if ((param_1[100] == 0) && (param_1[5] != 0)) {
            lVar2 = 0xc164;
            if (*(int *)(*(long *)(param_1[5] + 0xa8) + 0x46c) != 0x5533) {
              lVar2 = 0xd050;
            }
            uVar6 = readl(param_1[1] + lVar2);
            uVar6 = uVar6 >> 0x16 & 0xf;
            _dev_info(*param_1,"%s link state = 0x%04x\n","dwc3_msm_set_in_p3_state",uVar6);
            *(uint *)((long)param_1 + 0x36c) = (uint)(uVar6 == 3);
          }
          if ((param_2 & 1) == 0) {
            if (*(char *)(param_1 + 0x61) == '\0') {
              uVar6 = readl(param_1[1] + 0xc70c);
              if ((uVar6 & 6) == 4) goto LAB_0010cde0;
            }
            else {
              uVar6 = readl(param_1[1] + 4);
              uVar6 = uVar6 >> 0x18 & 0x7f;
              if (uVar6 != 0) {
                uVar7 = readl(param_1[1] + (ulong)(*(int *)(param_1 + 0x168) + 0x400));
                if (((uVar7 >> 1 & 1) == 0) || ((uVar7 & 0x3000) == 0)) {
                  uVar7 = 0;
                  iVar9 = 0x410;
                  do {
                    if (uVar6 - 1 == uVar7) goto LAB_0010cdf0;
                    uVar8 = readl(param_1[1] + (ulong)(uint)(iVar9 + *(int *)(param_1 + 0x168)));
                    iVar9 = iVar9 + 0x10;
                    uVar7 = uVar7 + 1;
                  } while (((uVar8 >> 1 & 1) == 0) || ((uVar8 & 0x3000) == 0));
                  if (uVar6 <= uVar7) goto LAB_0010cdf0;
                }
LAB_0010cde0:
                if ((*(char *)(param_1 + 0x51) == '\0') && (*(int *)((long)param_1 + 0x36c) == 0)) {
                  _dev_err(*param_1,"Not in P3,aborting LPM sequence\n");
                  iVar9 = -0x10;
                  goto LAB_0010cea8;
                }
              }
            }
          }
LAB_0010cdf0:
          uVar6 = readl(param_1[1] + 0xf88f8);
          if ((uVar6 >> 4 & 1) != 0) {
            writel(0x30,param_1[1] + 0xf8858);
            uVar6 = readl(param_1[1] + 0xc200);
            writel(uVar6 | 0x140,param_1[1] + 0xc200);
            lVar2 = _jiffies + 2;
            do {
              if (lVar2 - _jiffies < 0) break;
              uVar6 = readl(param_1[1] + 0xf8858);
            } while ((uVar6 >> 4 & 1) == 0);
            if ((uVar6 >> 4 & 1) == 0) {
              _dev_err(*param_1,"could not transition HS PHY to L2\n");
              iVar9 = -0x10;
            }
            else {
              iVar9 = 0;
            }
            writel(0x10,param_1[1] + 0xf8858);
            if (((uVar6 >> 4 & 1) == 0) && (*(char *)(param_1 + 0x61) != '\0')) {
LAB_0010cea8:
              mutex_unlock(puVar1);
              if (lVar15 == 0) {
                return iVar9;
              }
              if (*(char *)(param_1 + 0x61) == '\0') {
                return iVar9;
              }
              if (*(long *)(lVar15 + 0x1a0) == 0) {
                return iVar9;
              }
              __pm_runtime_resume(*(long *)(lVar15 + 0x1a0) + 0x10,1);
              return iVar9;
            }
          }
        }
        lVar15 = irq_to_desc(*(undefined4 *)(param_1 + 0x44));
        if ((((*(char *)((long)param_1 + 0xb31) == '\0') && (lVar15 != 0)) &&
            (*(int *)((long)param_1 + 0x39c) != 0)) &&
           (cancel_delayed_work_sync(param_1 + 0x7b), *(char *)(param_1 + 0x62) != '\0')) {
          cpu_latency_qos_update_request(param_1 + 0x75,0xffffffff);
          *(undefined1 *)(param_1 + 0x62) = 0;
        }
        disable_irq_nosync(*(undefined4 *)(param_1 + 0x40));
        if (param_1[5] != 0) {
          lVar15 = *(long *)(param_1[5] + 0xa8);
          *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) & 0xffffffcf;
          if (*(char *)(param_1 + 0x61) == '\0') {
            if ((*(int *)(param_1 + 0x5b) == 3) &&
               (uVar6 = *(int *)(*(long *)(lVar15 + 0x370) + 0x58) - 1, uVar6 < 3)) {
              *(uint *)(param_1[0x38] + 0x10) =
                   *(uint *)(param_1[0x38] + 0x10) | *(uint *)(&DAT_001101a0 + (long)(int)uVar6 * 4)
              ;
            }
          }
          else {
            uVar6 = readl(param_1[1] + 4);
            uVar6 = uVar6 >> 0x18 & 0x7f;
            if (uVar6 != 0) {
              iVar9 = 0;
              do {
                uVar7 = readl(param_1[1] + (ulong)(iVar9 + *(int *)(param_1 + 0x168) + 0x400));
                if ((uVar7 & 0x20001) == 1) {
                  uVar7 = uVar7 & 0x3c00;
                  uVar8 = 0x10;
                  if ((uVar7 != 0x400) && (uVar7 != 0xc00)) {
                    if (uVar7 != 0x800) goto LAB_0010d054;
                    uVar8 = 0x20;
                  }
                  *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) | uVar8;
                }
LAB_0010d054:
                iVar9 = iVar9 + 0x10;
              } while (uVar6 * 0x10 != iVar9);
            }
          }
        }
        lVar15 = param_1[0x38];
        if ((lVar15 != 0) && (pcVar12 = *(code **)(lVar15 + 0x138), pcVar12 != (code *)0x0)) {
          if (*(int *)(pcVar12 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x10cf4c);
            (*pcVar12)();
          }
          (*pcVar12)(lVar15,1);
        }
        if (*(char *)(param_1 + 0x61) == '\0') {
LAB_0010cf58:
          bVar5 = true;
          lVar15 = param_1[5];
          if (lVar15 != 0) goto LAB_0010d224;
LAB_0010cfe0:
          puVar13 = (uint *)(param_1 + 0x98);
        }
        else {
          if ((*(byte *)(param_1[0x38] + 0x10) & 0x30) == 0) {
LAB_0010cfd4:
            bVar5 = false;
            lVar15 = param_1[5];
          }
          else {
            uVar6 = readl(param_1[1] + 4);
            uVar6 = uVar6 >> 0x18 & 0x7f;
            if (uVar6 == 0) goto LAB_0010cf58;
            uVar7 = readl(param_1[1] + (ulong)(*(int *)(param_1 + 0x168) + 0x400));
            if (((uVar7 >> 1 & 1) != 0) && ((uVar7 & 0x3000) != 0)) goto LAB_0010cfd4;
            uVar7 = 0;
            iVar9 = 0x410;
            do {
              if (uVar6 - 1 == uVar7) {
                uVar7 = uVar6;
                break;
              }
              uVar8 = readl(param_1[1] + (ulong)(uint)(iVar9 + *(int *)(param_1 + 0x168)));
              iVar9 = iVar9 + 0x10;
              uVar7 = uVar7 + 1;
            } while (((uVar8 >> 1 & 1) == 0) || ((uVar8 & 0x3000) == 0));
            bVar5 = uVar6 <= uVar7;
            lVar15 = param_1[5];
          }
          if (lVar15 == 0) goto LAB_0010cfe0;
LAB_0010d224:
          puVar13 = (uint *)(*(long *)(lVar15 + 0xa8) + 0x45c);
        }
        if (*puVar13 < 5) {
          if ((param_1[100] & 1) != 0) goto LAB_0010d2b0;
        }
        else {
          if ((param_1[100] & 1) == 0) {
            bVar5 = true;
          }
          if (bVar5) {
            lVar15 = param_1[1];
            if (*(char *)(param_1 + 0x61) == '\0') {
LAB_0010d280:
              uVar6 = readl(lVar15 + 0xc70c);
              if ((uVar6 & 6) == 4) {
LAB_0010d298:
                *(uint *)(param_1[0x39] + 0x10) = *(uint *)(param_1[0x39] + 0x10) | 2;
              }
            }
            else {
              uVar6 = readl(lVar15 + 0xc2c0);
              writel(uVar6 | 0x400000,param_1[1] + 0xc2c0);
              lVar15 = param_1[1];
              if (*(char *)(param_1 + 0x61) == '\0') goto LAB_0010d280;
              uVar6 = readl(lVar15 + 4);
              uVar6 = uVar6 >> 0x18 & 0x7f;
              if (uVar6 != 0) {
                uVar7 = readl(param_1[1] + (ulong)(*(int *)(param_1 + 0x168) + 0x400));
                if (((uVar7 >> 1 & 1) == 0) || ((uVar7 & 0x3000) == 0)) {
                  uVar7 = 0;
                  iVar9 = 0x410;
                  do {
                    if (uVar6 - 1 == uVar7) goto LAB_0010d2c8;
                    uVar8 = readl(param_1[1] + (ulong)(uint)(iVar9 + *(int *)(param_1 + 0x168)));
                    iVar9 = iVar9 + 0x10;
                    uVar7 = uVar7 + 1;
                  } while (((uVar8 >> 1 & 1) == 0) || ((uVar8 & 0x3000) == 0));
                  if (uVar6 <= uVar7) goto LAB_0010d2c8;
                }
                goto LAB_0010d298;
              }
            }
LAB_0010d2c8:
            lVar15 = param_1[0x39];
            if ((lVar15 == 0) || (pcVar12 = *(code **)(lVar15 + 0x138), pcVar12 == (code *)0x0)) {
              uVar14 = 1;
            }
            else {
              uVar14 = 1;
              if (*(int *)(pcVar12 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
                pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x10d300);
                (*pcVar12)();
              }
              (*pcVar12)(lVar15,1);
            }
          }
          else {
LAB_0010d2b0:
            uVar14 = 4;
          }
          param_1[0x66] = param_1[0x66] | uVar14;
        }
        if ((*(char *)(param_1 + 0x61) != '\0') && ((*(byte *)(param_1 + 100) >> 1 & 1) != 0)) {
          param_1[0x66] = param_1[0x66] | 4;
        }
        if ((*(byte *)(param_1 + 0x66) >> 2 & 1) != 0) {
          uVar10 = readl(param_1[1] + 0xf8858);
          writel(uVar10,param_1[1] + 0xf8858);
          uVar6 = readl(param_1[1] + 0xf885c);
          uVar6 = ((uint)param_1[100] & 2) << 4 | uVar6;
          uVar7 = uVar6;
          if (((param_1[100] & 1) != 0) &&
             (uVar7 = uVar6 | 0x1008, (*(byte *)(param_1 + 0x66) & 1) != 0)) {
            uVar7 = uVar6;
          }
          writel(uVar7,param_1[1] + 0xf885c);
          irq_set_irq_wake(*(undefined4 *)(param_1 + 0x40),1);
          enable_irq(*(undefined4 *)(param_1 + 0x40));
        }
        DataSynchronizationBarrier(3,2,0);
        if ((((*(char *)(param_1 + 0x61) == '\0') && (*(char *)((long)param_1 + 0x309) == '\0')) ||
            (*(char *)(param_1 + 0x51) != '\0')) || ((param_2 & 1) != 0)) {
          uVar14 = param_1[0x66] | 2;
          param_1[0x66] = uVar14;
          if (*(char *)((long)param_1 + 0xb31) != '\0') goto LAB_0010d3dc;
LAB_0010d41c:
          dwc3_clk_enable_disable(param_1,0,uVar14 >> 1 & 1);
          if ((((*(byte *)(param_1 + 0x66) >> 1 & 1) != 0) &&
              (_dev_info(*param_1,"%s: power collapse\n","__dwc3_msm_suspend"),
              *(char *)((long)param_1 + 0xb31) == '\0')) &&
             ((param_1[0x37] != 0 && ((ulong)param_1[0x37] < 0xfffffffffffff001)))) {
            qcom_clk_set_flags(param_1[0x2a],3);
            iVar9 = regulator_disable(param_1[0x37]);
            if (iVar9 != 0) {
              _dev_err(*param_1,"unable to disable usb3 gdsc\n");
            }
          }
          dwc3_msm_update_bus_bw(param_1,0);
        }
        else {
          uVar14 = param_1[0x66];
          if (*(char *)((long)param_1 + 0xb31) == '\0') goto LAB_0010d41c;
LAB_0010d3dc:
          iVar9 = __pm_runtime_idle(*(undefined8 *)param_1[0x167],4);
          if (((uint)uVar14 >> 1 & 1) == 0) {
            if (iVar9 < 0) {
              uVar10 = *param_1;
              pcVar11 = "power state transit failed d0 to d1 with %d\n";
LAB_0010d5e8:
              _dev_err(uVar10,pcVar11,iVar9);
              mutex_unlock(puVar1);
              return iVar9;
            }
          }
          else {
            if (iVar9 == 0) {
              iVar9 = __pm_runtime_idle(*(undefined8 *)(param_1[0x167] + 8),4);
            }
            if (iVar9 < 0) {
              uVar10 = *param_1;
              pcVar11 = "power state transit failed d0 to d3 with %d\n";
              goto LAB_0010d5e8;
            }
          }
        }
        if (*(int *)((long)param_1 + 0x374) == 0) {
          pm_relax();
        }
        else {
          _dev_info(*param_1,"defer suspend with %d(msecs)\n");
          pm_wakeup_dev_event(*param_1,*(undefined4 *)((long)param_1 + 0x374),0);
        }
        _dev_info(*param_1,"%s: set in_lpm=1\n","dwc3_msm_suspend");
        *(undefined4 *)(param_1 + 0x6e) = 1;
        dwc3_msm_interrupt_enable(param_1,param_3 & 1);
        if ((param_1[100] != 0) && ((*(byte *)(param_1 + 0x66) & 1) == 0)) {
          irq_set_irq_wake(*(undefined4 *)(param_1 + 0x40),1);
          enable_irq(*(undefined4 *)(param_1 + 0x40));
        }
        if (((*(char *)((long)param_1 + 0xa51) != '\0') && (*(char *)(param_1 + 0x61) == '\0')) &&
           (*(char *)((long)param_1 + 0x309) == '\0')) {
          wcd_usbss_switch_update(0,0);
        }
        _dev_info(*param_1,"DWC3 in low power mode\n");
        dwc3_dbg_print(param_1[0xa5],0xff,"Ctl Sus",*(undefined4 *)(param_1 + 0x6e),&DAT_00111364);
        puVar3 = param_1 + 0x5a;
        Hint_Prefetch(puVar3,2,0,1);
        do {
          uVar14 = *puVar3;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
          if (bVar5) {
            *puVar3 = uVar14 & 0xfffffffffffffff7;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
        if (((uint)uVar14 >> 3 & 1) != 0) {
          queue_work_on(0x20,param_1[0x53],param_1 + 0x54);
        }
        goto LAB_0010d590;
      }
      _dev_info(*param_1,"%s: cable disconnected while not in idle otg state\n","dwc3_msm_suspend");
    }
    else if ((*(char *)(param_1 + 0x61) == '\0') &&
            ((*(byte *)(*(long *)(lVar15 + 0x268) + 0x1c) & 1) != 0)) {
      _dev_info(*param_1,"%s: %d device events pending, abort suspend\n","dwc3_msm_suspend",
                *(uint *)(*(long *)(lVar15 + 0x268) + 0x18) >> 2);
    }
    else {
      if ((*(int *)((long)param_1 + 0x2dc) != 3) ||
         ((*(int *)(param_1 + 0x5b) != 3 || (*(int *)(*(long *)(lVar15 + 0x370) + 0x68) == 7))))
      goto LAB_0010cd00;
      _printk(&DAT_001121e0,"dwc3_msm_suspend");
      _printk(&DAT_00111b5b,"dwc3_msm_suspend");
    }
    mutex_unlock(puVar1);
    iVar9 = -0x10;
  }
  else {
    _dev_info(*param_1,"%s: Already suspended\n","dwc3_msm_suspend");
LAB_0010d590:
    mutex_unlock(puVar1);
    iVar9 = 0;
  }
  return iVar9;
}



//------------------------------------------------------------
// dwc3_msm_interrupt_enable @ 0010d68c size=536
// signature: undefined dwc3_msm_interrupt_enable(void)
// callers: [dwc3_msm_suspend, dwc3_msm_pm_suspend, dwc3_msm_resume]
//------------------------------------------------------------

void dwc3_msm_interrupt_enable(long param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if ((((param_2 & 1) != 0) && (*(char *)(param_1 + 0x309) == '\0')) &&
     (*(char *)(param_1 + 0x308) == '\0')) {
    return;
  }
  if ((*(char *)(param_1 + 0x315) == '\0') && (*(int *)(param_1 + 0x1f8) != 0)) {
    configure_nonpdc_usb_interrupt(param_1,param_1 + 0x1f8,param_2 & 1);
    configure_nonpdc_usb_interrupt(param_1,param_1 + 0x218,param_2 & 1);
    return;
  }
  if ((param_2 & 1) == 0) {
    if ((param_1 != -0x208) && (*(char *)(param_1 + 0x20c) != '\0')) {
      dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"PDC_IRQ_DIS",
                     *(undefined4 *)(param_1 + 0x208),&DAT_00111364);
      irq_set_irq_wake(*(undefined4 *)(param_1 + 0x208),0);
      disable_irq_nosync(*(undefined4 *)(param_1 + 0x208));
      *(undefined1 *)(param_1 + 0x20c) = 0;
    }
    if ((param_1 != -0x210) && (*(char *)(param_1 + 0x214) != '\0')) {
      dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"PDC_IRQ_DIS",
                     *(undefined4 *)(param_1 + 0x210),&DAT_00111364);
      irq_set_irq_wake(*(undefined4 *)(param_1 + 0x210),0);
      disable_irq_nosync(*(undefined4 *)(param_1 + 0x210));
      *(undefined1 *)(param_1 + 0x214) = 0;
    }
    if (param_1 == -0x218) {
      return;
    }
    if (*(char *)(param_1 + 0x21c) == '\0') {
      return;
    }
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"PDC_IRQ_DIS",
                   *(undefined4 *)(param_1 + 0x218),&DAT_00111364);
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0x218),0);
    disable_irq_nosync(*(undefined4 *)(param_1 + 0x218));
    *(undefined1 *)(param_1 + 0x21c) = 0;
    return;
  }
  uVar1 = *(uint *)(*(long *)(param_1 + 0x1c0) + 0x10);
  if ((uVar1 >> 5 & 1) == 0) {
    if ((uVar1 >> 4 & 1) == 0) {
      if (*(char *)(param_1 + 0x308) == '\0') {
        uVar3 = 1;
      }
      else {
        uVar3 = 4;
        if ((*(byte *)(param_1 + 800) & 2) != 0) {
          uVar3 = 1;
        }
      }
      uVar4 = 1;
      configure_usb_wakeup_interrupt(param_1,param_1 + 0x208,uVar3,1);
      lVar2 = param_1 + 0x210;
      if ((*(char *)(param_1 + 0x308) != '\0') && (uVar4 = 4, (*(byte *)(param_1 + 800) & 2) != 0))
      {
        uVar4 = 1;
      }
      goto LAB_0010d878;
    }
    if (*(char *)(param_1 + 0xa41) == '\0') {
      lVar2 = param_1 + 0x208;
      goto LAB_0010d870;
    }
    lVar2 = param_1 + 0x210;
  }
  else {
    if (*(char *)(param_1 + 0xa41) == '\0') {
      lVar2 = param_1 + 0x210;
LAB_0010d870:
      uVar4 = 8;
      goto LAB_0010d878;
    }
    lVar2 = param_1 + 0x208;
  }
  uVar4 = 1;
LAB_0010d878:
  configure_usb_wakeup_interrupt(param_1,lVar2,uVar4,1);
  configure_usb_wakeup_interrupt(param_1,param_1 + 0x218,4,1);
  return;
}



//------------------------------------------------------------
// dwc3_clk_enable_disable @ 0010d8a4 size=676
// signature: undefined dwc3_clk_enable_disable(void)
// callers: [dwc3_msm_suspend, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

int dwc3_clk_enable_disable(undefined8 *param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  
  if (*(char *)((long)param_1 + 0xb31) != '\0') {
    return 0;
  }
  if ((param_2 & 1) == 0) {
    uVar3 = param_1[0x33];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
    iVar1 = 0;
LAB_0010d8ec:
    uVar3 = param_1[0x30];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
LAB_0010d900:
    clk_set_rate(param_1[0x2a],19200000);
    uVar3 = param_1[0x2a];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
LAB_0010d924:
    uVar3 = param_1[0x34];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
LAB_0010d938:
    uVar3 = param_1[0x2e];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
  }
  else {
    uVar3 = param_1[0x29];
    iVar1 = clk_prepare(uVar3);
    if (iVar1 == 0) {
      iVar1 = clk_enable(uVar3);
      if (iVar1 != 0) {
        clk_unprepare(uVar3);
        goto LAB_0010d9bc;
      }
    }
    else {
LAB_0010d9bc:
      if (iVar1 < 0) {
        _dev_err(*param_1,"%s failed to vote TCXO buffer%d\n","dwc3_clk_enable_disable",iVar1);
        return iVar1;
      }
    }
    if (((param_3 & 1) != 0) && (iVar1 = clk_prepare_enable(param_1[0x2f]), iVar1 < 0)) {
      _dev_err(*param_1,"%s: sleep_clk enable failed\n","dwc3_clk_enable_disable");
      goto LAB_0010d964;
    }
    iVar1 = clk_prepare_enable(param_1[0x2e]);
    if (-1 < iVar1) {
      iVar1 = clk_prepare_enable(param_1[0x34]);
      if (-1 < iVar1) {
        uVar3 = param_1[0x2d];
        if ((*(char *)(param_1 + 0x61) == '\0') || (*(int *)((long)param_1 + 0x30c) != 3)) {
          if ((*(byte *)(param_1 + 0x66) >> 1 & 1) == 0) {
            puVar2 = param_1 + 0x2b;
            goto LAB_0010da98;
          }
        }
        else {
          puVar2 = param_1 + 0x2c;
LAB_0010da98:
          uVar3 = *puVar2;
        }
        _dev_info(*param_1,"%s: set core clk rate %ld\n","dwc3_clk_enable_disable",uVar3);
        clk_set_rate(param_1[0x2a],uVar3);
        iVar1 = clk_prepare_enable(param_1[0x2a]);
        if (-1 < iVar1) {
          iVar1 = clk_prepare_enable(param_1[0x30]);
          if (-1 < iVar1) {
            iVar1 = clk_prepare_enable(param_1[0x33]);
            if (-1 < iVar1) {
              return 0;
            }
            _dev_err(*param_1,"%s: bus_aggr_clk enable failed\n","dwc3_clk_enable_disable");
            goto LAB_0010d8ec;
          }
          _dev_err(*param_1,"%s: utmi_clk enable failed\n","dwc3_clk_enable_disable");
          goto LAB_0010d900;
        }
        _dev_err(*param_1,"%s: core_clk enable failed\n","dwc3_clk_enable_disable");
        goto LAB_0010d924;
      }
      _dev_err(*param_1,"%s: noc_aggr_clk enable failed\n","dwc3_clk_enable_disable");
      goto LAB_0010d938;
    }
    _dev_err(*param_1,"%s: iface_clk enable failed\n","dwc3_clk_enable_disable");
  }
  if ((param_3 & 1) != 0) {
    uVar3 = param_1[0x2f];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
  }
LAB_0010d964:
  uVar3 = param_1[0x29];
  clk_disable(uVar3);
  clk_unprepare(uVar3);
  return iVar1;
}



//------------------------------------------------------------
// configure_nonpdc_usb_interrupt @ 0010db48 size=200
// signature: undefined configure_nonpdc_usb_interrupt(void)
// callers: [dwc3_msm_interrupt_enable]
//------------------------------------------------------------

void configure_nonpdc_usb_interrupt(long param_1,undefined4 *param_2,ulong param_3)

{
  if (((param_2 != (undefined4 *)0x0) && ((param_3 & 1) != 0)) && (*(char *)(param_2 + 1) == '\0'))
  {
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"IRQ_EN",*param_2,&DAT_00111364);
    irq_set_irq_wake(*param_2,1);
    enable_irq(*param_2);
    *(undefined1 *)(param_2 + 1) = 1;
  }
  if (((param_2 != (undefined4 *)0x0) && ((param_3 & 1) == 0)) && (*(char *)(param_2 + 1) != '\0'))
  {
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"IRQ_DIS",*param_2,&DAT_00111364);
    irq_set_irq_wake(*param_2,0);
    disable_irq_nosync(*param_2);
    *(undefined1 *)(param_2 + 1) = 0;
  }
  return;
}



//------------------------------------------------------------
// configure_usb_wakeup_interrupt @ 0010dc10 size=272
// signature: undefined configure_usb_wakeup_interrupt(void)
// callers: [dwc3_msm_interrupt_enable]
//------------------------------------------------------------

void configure_usb_wakeup_interrupt
               (long param_1,undefined4 *param_2,undefined4 param_3,ulong param_4)

{
  if (((param_2 != (undefined4 *)0x0) && ((param_4 & 1) != 0)) && (*(char *)(param_2 + 1) == '\0'))
  {
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"PDC_IRQ_EN",*param_2,&DAT_00111364);
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"PDC_IRQ_POL",param_3,&DAT_00111364);
    irq_set_irqchip_state(*param_2,0,0);
    irq_set_irq_type(*param_2,param_3);
    irq_set_irq_wake(*param_2,1);
    enable_irq(*param_2);
    *(undefined1 *)(param_2 + 1) = 1;
  }
  if (((param_2 != (undefined4 *)0x0) && ((param_4 & 1) == 0)) && (*(char *)(param_2 + 1) != '\0'))
  {
    dwc3_dbg_print(*(undefined8 *)(param_1 + 0x528),0xff,"PDC_IRQ_DIS",*param_2,&DAT_00111364);
    irq_set_irq_wake(*param_2,0);
    disable_irq_nosync(*param_2);
    *(undefined1 *)(param_2 + 1) = 0;
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_resume @ 0010dd20 size=2044
// signature: undefined dwc3_msm_resume(void)
// callers: [dwc3_msm_pm_resume, dwc3_msm_runtime_resume]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int dwc3_msm_resume(undefined8 *param_1)

{
  int *piVar1;
  long lVar2;
  ulong *puVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint extraout_var;
  undefined8 uVar11;
  long lVar12;
  undefined4 uVar13;
  char *pcVar14;
  ulong uVar15;
  code *pcVar16;
  uint *puVar17;
  
  _dev_info(*param_1,"%s: exiting lpm\n","dwc3_msm_resume");
  if ((*(char *)((long)param_1 + 0x312) == '\0') && (*(int *)(param_1 + 99) != 0)) {
    puVar3 = param_1 + 0x5a;
    Hint_Prefetch(puVar3,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar3,0x10);
      if (bVar7) {
        *puVar3 = *puVar3 | 8;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
  }
  mutex_lock(param_1 + 0x8c);
  if (*(int *)(param_1 + 0x6e) == 0) {
    _dev_info(*param_1,"%s: Already resumed\n","dwc3_msm_resume");
    iVar8 = 0;
    goto LAB_0010e398;
  }
  pm_stay_awake();
  if (*(char *)((long)param_1 + 0xb31) == '\0') {
    if ((*(char *)(param_1 + 0x61) == '\0') || (*(int *)((long)param_1 + 0x30c) != 3)) {
      uVar13 = *(undefined4 *)((long)param_1 + 0x2e4);
    }
    else {
      uVar13 = 2;
    }
    dwc3_msm_update_bus_bw(param_1,uVar13);
    if ((*(byte *)(param_1 + 0x66) >> 1 & 1) != 0) {
      _dev_info(*param_1,"%s: exit power collapse\n","__dwc3_msm_resume");
      if (*(char *)((long)param_1 + 0xb31) == '\0') {
        iVar8 = -1;
        if ((param_1[0x37] == 0) || (0xfffffffffffff000 < (ulong)param_1[0x37])) goto LAB_0010e374;
        iVar8 = regulator_enable();
        if (iVar8 == 0) {
          qcom_clk_set_flags(param_1[0x2a],2);
        }
        else {
          _dev_err(*param_1,"unable to enable usb3 gdsc\n");
          if (iVar8 < 0) goto LAB_0010e374;
        }
      }
      iVar8 = reset_control_assert(param_1[0x36]);
      if (iVar8 != 0) {
        _dev_err(*param_1,"%s:core_reset assert failed\n","__dwc3_msm_resume");
      }
      usleep_range_state(1000,0x4b0,2);
      iVar8 = reset_control_deassert(param_1[0x36]);
      if (iVar8 != 0) {
        _dev_err(*param_1,"%s:core_reset deassert failed\n","__dwc3_msm_resume");
      }
    }
    iVar8 = dwc3_clk_enable_disable(param_1,1,(ulong)param_1[0x66] >> 1 & 1);
    if (-1 < iVar8) goto LAB_0010df60;
    if (((((*(byte *)(param_1 + 0x66) >> 1 & 1) != 0) && (*(char *)((long)param_1 + 0xb31) == '\0'))
        && (param_1[0x37] != 0)) && ((ulong)param_1[0x37] < 0xfffffffffffff001)) {
      qcom_clk_set_flags(param_1[0x2a],3);
      iVar9 = regulator_disable(param_1[0x37]);
      if (iVar9 != 0) {
        _dev_err(*param_1,"unable to disable usb3 gdsc\n");
      }
    }
    goto LAB_0010e374;
  }
  if ((*(byte *)(param_1 + 0x66) >> 1 & 1) == 0) {
    lVar12 = *(long *)param_1[0x167];
    iVar8 = __pm_runtime_resume(lVar12,4);
    if (iVar8 < 0) {
      piVar1 = (int *)(lVar12 + 0x1f8);
      iVar9 = *(int *)(lVar12 + 0x1f8);
      do {
        if (iVar9 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar5 = *piVar1;
          if (iVar5 != iVar9) goto LAB_0010de94;
          cVar6 = '\x01';
          bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar7) {
            *piVar1 = iVar9 + -1;
            cVar6 = ExclusiveMonitorsStatus();
          }
        } while (cVar6 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010de94:
        bVar7 = iVar9 != iVar5;
        iVar9 = iVar5;
      } while (bVar7);
      uVar11 = *param_1;
      pcVar14 = "power state transit failed d1 to d0 with %d\n";
LAB_0010e368:
      _dev_err(uVar11,pcVar14,iVar8);
      if (iVar8 < 0) goto LAB_0010e374;
    }
  }
  else {
    iVar8 = dwc3_msm_modeled_d3_to_d0(param_1);
    if (iVar8 != 0) {
      uVar11 = *param_1;
      pcVar14 = "power state transit failed d3 to d0 with %d\n";
      goto LAB_0010e368;
    }
  }
LAB_0010df60:
  uVar15 = param_1[0x66];
  if (((uint)uVar15 >> 2 & 1) != 0) {
    disable_irq_nosync(*(undefined4 *)(param_1 + 0x40));
    uVar11 = readl(param_1[1] + 0xf8858);
    writel(uVar11,param_1[1] + 0xf8858);
    uVar10 = readl(param_1[1] + 0xf885c);
    if ((param_1[100] & 2) != 0) {
      uVar10 = uVar10 & 0xffffffdf;
    }
    uVar4 = uVar10;
    if (((param_1[100] & 1) != 0) &&
       (uVar4 = uVar10 & 0xffffeff7, (*(byte *)(param_1 + 0x66) & 1) != 0)) {
      uVar4 = uVar10;
    }
    writel(uVar4,param_1[1] + 0xf885c);
    uVar15 = param_1[0x66] & 0xfffffffffffffffb;
    param_1[0x66] = uVar15;
  }
  if (param_1[5] == 0) {
    puVar17 = (uint *)(param_1 + 0x98);
  }
  else {
    puVar17 = (uint *)(*(long *)(param_1[5] + 0xa8) + 0x45c);
  }
  if (4 < *puVar17 && (uVar15 & 1) != 0) {
    dwc3_set_ssphy_orientation_flag(param_1);
    if ((((*(char *)(param_1 + 0x61) == '\0') || (*(char *)((long)param_1 + 0x329) != '\0')) ||
        (*(int *)((long)param_1 + 0x30c) != 3)) &&
       ((lVar12 = param_1[0x39], lVar12 != 0 &&
        (pcVar16 = *(code **)(lVar12 + 0x138), pcVar16 != (code *)0x0)))) {
      if (*(int *)(pcVar16 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10e060);
        (*pcVar16)();
      }
      (*pcVar16)(lVar12,0);
    }
    *(uint *)(param_1[0x39] + 0x10) = *(uint *)(param_1[0x39] + 0x10) & 0xfffffffd;
    param_1[0x66] = param_1[0x66] & 0xfffffffffffffffe;
    if (*(char *)(param_1 + 0x61) != '\0') {
      uVar10 = readl(param_1[1] + 0xc2c0);
      writel(uVar10 & 0xffbfffff,param_1[1] + 0xc2c0);
    }
  }
  *(uint *)(param_1[0x38] + 0x10) = *(uint *)(param_1[0x38] + 0x10) & 0xffffffcf;
  lVar12 = param_1[0x38];
  if ((lVar12 != 0) && (pcVar16 = *(code **)(lVar12 + 0x138), pcVar16 != (code *)0x0)) {
    if (*(int *)(pcVar16 + -4) != 0x5b8f7219) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10e0e4);
      (*pcVar16)();
    }
    (*pcVar16)(lVar12,0);
  }
  if ((*(byte *)(param_1 + 0x66) >> 1 & 1) != 0) {
    _dev_info(*param_1,"%s: exit power collapse\n","dwc3_msm_resume");
    if (param_1[5] == 0) {
      lVar12 = 0;
    }
    else {
      lVar12 = *(long *)(param_1[5] + 0xa8);
    }
    if (*(int *)(param_1 + 0x6d) == 0) {
      readl(param_1[1] + 0xc120);
      *(uint *)(param_1 + 0x6d) = extraout_var & 0xffff;
    }
    if ((*(char *)((long)param_1 + 0xa52) != '\0') ||
       (((param_1[2] != 0 && (iVar8 = readl(), iVar8 != 0xf)) ||
        (uVar10 = readl(param_1[1] + 0xc120), uVar10 < 0x10000)))) {
      _dev_err(*param_1,"%s: Controller was not turned on properly\n","dwc3_msm_resume");
      if (*(char *)((long)param_1 + 0xb31) == '\0') {
        dwc3_clk_enable_disable(param_1,0,(ulong)param_1[0x66] >> 1 & 1);
        dwc3_msm_config_gdsc(param_1,0);
        iVar8 = -0x16;
      }
      else {
        iVar8 = dwc3_msm_modeled_d0_to_d3(param_1);
        if (iVar8 == 0) goto LAB_0010e4c4;
        _dev_err(*param_1,"power state transit failed d0 to d3 with %d\n",iVar8);
      }
LAB_0010e374:
      dwc3_msm_update_bus_bw(param_1,0);
      pm_relax(*param_1);
      puVar3 = param_1 + 0x5a;
      Hint_Prefetch(puVar3,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(puVar3,0x10);
        if (bVar7) {
          *puVar3 = *puVar3 & 0xfffffffffffffff7;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      goto LAB_0010e398;
    }
    if (param_1[100] != 0) {
      lVar2 = param_1[1] + 0xf885c;
      uVar10 = readl(lVar2);
      writel(uVar10 | 4,lVar2);
      readl(lVar2);
    }
    if (*(char *)(param_1 + 0x61) != '\0') {
      lVar2 = param_1[1] + 0xc110;
      uVar10 = readl(lVar2);
      writel(uVar10 & 0xffffcfff | 0x1000000,lVar2);
      readl(lVar2);
      if ((lVar12 != 0) && ((*(uint *)(lVar12 + 0x4e8) >> 0x1d & 1) == 0)) {
        uVar10 = readl(param_1[1] + 0xc200);
        writel(uVar10 | 0x100,param_1[1] + 0xc200);
        uVar10 = readl(param_1[1] + 0xc11c);
        writel(uVar10 | 0x100,param_1[1] + 0xc11c);
      }
      if (*(char *)(param_1 + 0x148) != '\0') {
        uVar10 = readl(param_1[1] + 0xc200);
        writel(uVar10 | 0x40,param_1[1] + 0xc200);
      }
    }
LAB_0010e4c4:
    param_1[0x66] = param_1[0x66] & 0xfffffffffffffffd;
  }
  _dev_info(*param_1,"%s: set in_lpm=0\n","dwc3_msm_resume");
  *(undefined4 *)(param_1 + 0x6e) = 0;
  irq_set_irq_wake(*(undefined4 *)(param_1 + 0x40),1);
  enable_irq(*(undefined4 *)(param_1 + 0x40));
  uVar10 = readl(param_1[1] + 0xc200);
  writel(uVar10 & 0xfffffebf,param_1[1] + 0xc200);
  dwc3_msm_interrupt_enable(param_1,0);
  _dev_info(*param_1,"DWC3 exited from low power mode\n");
  dwc3_pwr_event_handler(param_1);
  lVar12 = irq_to_desc(*(undefined4 *)(param_1 + 0x44));
  if ((*(char *)((long)param_1 + 0xb31) == '\0') && (lVar12 != 0)) {
    iVar8 = *(int *)(param_1 + 0x74);
    *(undefined1 *)(param_1 + 0x62) = 0;
    if (iVar8 == -1) {
      iVar8 = *(int *)(param_1 + 0x73);
    }
    *(int *)((long)param_1 + 0x39c) = iVar8;
    uVar11 = _system_wq;
    if (iVar8 != 0) {
      *(undefined4 *)((long)param_1 + 0x224) = *(undefined4 *)(lVar12 + 0x90);
      queue_delayed_work_on(0x20,uVar11,param_1 + 0x7b,0x19);
    }
  }
  if (param_1[5] == 0) {
    iVar8 = *(int *)(param_1 + 0x98);
    if (iVar8 != 3) goto LAB_0010e2a8;
LAB_0010e2b0:
    lVar12 = param_1[1];
    uVar10 = readl(lVar12 + 0xf8808);
    writel(uVar10 | 0x100,lVar12 + 0xf8808);
    __const_udelay(0x53e3);
    uVar10 = readl(param_1[1] + 0xf8808);
    writel(uVar10 | 9,param_1[1] + 0xf8808);
    __const_udelay(0x53e3);
    lVar12 = param_1[1];
    uVar10 = readl(lVar12 + 0xf8808);
    writel(uVar10 & 0xfffffeff,lVar12 + 0xf8808);
  }
  else {
    iVar8 = *(int *)(*(long *)(param_1[5] + 0xa8) + 0x45c);
    if (iVar8 == 3) goto LAB_0010e2b0;
LAB_0010e2a8:
    if (iVar8 == 2) goto LAB_0010e2b0;
  }
  dwc3_dbg_print(param_1[0xa5],0xff,"Ctl Res",*(undefined4 *)(param_1 + 0x6e),&DAT_00111364);
  iVar8 = 0;
LAB_0010e398:
  mutex_unlock(param_1 + 0x8c);
  return iVar8;
}



//------------------------------------------------------------
// dwc3_dbg_trace_log_ctrl @ 0010e554 size=136
// signature: undefined dwc3_dbg_trace_log_ctrl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dwc3_dbg_trace_log_ctrl(undefined8 param_1,undefined1 *param_2)

{
  long lVar1;
  
  if ((param_2 != (undefined1 *)0x0) &&
     (lVar1 = kmalloc_trace(___memcpy_toio,0xb20,500), lVar1 != 0)) {
    usb_decode_ctrl(lVar1,500,*param_2,param_2[1],*(undefined2 *)(param_2 + 2),
                    *(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 6));
    ipc_log_string(param_1,"dbg_trace_log_ctrl: %s",lVar1);
    kfree(lVar1);
  }
  return;
}



//------------------------------------------------------------
// dwc3_dbg_trace_log_request @ 0010e5e0 size=152
// signature: undefined dwc3_dbg_trace_log_request(void)
// callers: [entry_trace_event_raw_event_dwc3_log_request]
//------------------------------------------------------------

void dwc3_dbg_trace_log_request(undefined8 param_1,long param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined *puVar3;
  uint uVar4;
  
  if (param_2 != 0) {
    uVar4 = *(uint *)(param_2 + 0x28);
    puVar1 = &DAT_00111b7a;
    if ((uVar4 & 0x40000) != 0) {
      puVar1 = &DAT_0011167c;
    }
    puVar2 = &DAT_0011077f;
    if ((uVar4 & 0x80000) != 0) {
      puVar2 = &DAT_00110933;
    }
    puVar3 = &DAT_00110935;
    if ((uVar4 & 0x20000) != 0) {
      puVar3 = &DAT_001127ca;
    }
    ipc_log_string(param_1,"%s: %s: req %p length %u/%u %s%s%s ==> %d",param_3,
                   *(long *)(param_2 + 0x78) + 0xb8,param_2,*(undefined4 *)(param_2 + 0x58),
                   *(undefined4 *)(param_2 + 8),puVar1,puVar2,puVar3,*(undefined4 *)(param_2 + 0x54)
                  );
  }
  return;
}



//------------------------------------------------------------
// dwc3_dbg_trace_ep_cmd @ 0010e67c size=208
// signature: undefined dwc3_dbg_trace_ep_cmd(void)
// callers: [entry_trace_event_raw_event_dwc3_log_gadget_ep_cmd]
//------------------------------------------------------------

void dwc3_dbg_trace_ep_cmd
               (undefined8 param_1,long param_2,int param_3,undefined4 *param_4,int param_5)

{
  char *pcVar1;
  char *pcVar2;
  
  if ((param_3 - 1U & 0xff) < 9) {
    pcVar1 = (&PTR_s_Set_Endpoint_Configuration_001101f0)[(char)(param_3 - 1U)];
  }
  else {
    pcVar1 = "UNKNOWN command";
  }
  if (param_5 < 1) {
    if (param_5 == -0x6e) {
      pcVar2 = "Timed Out";
      goto LAB_0010e724;
    }
    if (param_5 == 0) {
      pcVar2 = "Successful";
      goto LAB_0010e724;
    }
  }
  else {
    if (param_5 == 1) {
      pcVar2 = "No Resource";
      goto LAB_0010e724;
    }
    if (param_5 == 2) {
      pcVar2 = "Bus Expiry";
      goto LAB_0010e724;
    }
  }
  pcVar2 = "UNKNOWN";
LAB_0010e724:
  ipc_log_string(param_1,"dbg_send_ep_cmd: %s: cmd \'%s\' [%x] params %08x %08x %08x --> status: %s"
                 ,param_2 + 0xb8,pcVar1,param_3,param_4[2],param_4[1],*param_4,pcVar2);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_trace_trb_complete @ 0010e750 size=328
// signature: undefined dwc3_dbg_trace_trb_complete(void)
// callers: [entry_trace_event_raw_event_dwc3_log_trb]
//------------------------------------------------------------

void dwc3_dbg_trace_trb_complete
               (undefined8 param_1,long param_2,undefined4 *param_3,undefined8 param_4)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined *puVar9;
  char *pcVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  uVar2 = param_3[2];
  if ((*(byte *)(*(long *)(param_2 + 0x38) + 3) & 1) == 0) {
    puVar9 = &DAT_00111364;
  }
  else {
    puVar1 = &UNK_00113563;
    if ((uVar2 >> 0x18 & 3) != 1) {
      puVar1 = &DAT_00110c9a;
    }
    puVar9 = &UNK_0011389c;
    if ((uVar2 >> 0x18 & 3) != 0) {
      puVar9 = puVar1;
    }
  }
  uVar3 = param_3[3];
  uVar4 = (uVar3 & 0x3f0) - 0x10;
  if (uVar4 < 0x80) {
    pcVar10 = (&PTR_s_normal_00110238)[uVar4 >> 4];
  }
  else {
    pcVar10 = "UNKNOWN";
  }
  uVar11 = 99;
  if ((uVar3 & 0x800) != 0) {
    uVar11 = 0x43;
  }
  uVar5 = 0x73;
  if ((uVar3 & 0x400) != 0) {
    uVar5 = 0x53;
  }
  uVar6 = 0x73;
  if ((uVar3 & 8) != 0) {
    uVar6 = 0x53;
  }
  uVar12 = 99;
  if ((uVar3 & 4) != 0) {
    uVar12 = 0x43;
  }
  uVar7 = 0x6c;
  if ((uVar3 & 2) != 0) {
    uVar7 = 0x4c;
  }
  uVar8 = 0x68;
  if ((uVar3 & 1) != 0) {
    uVar8 = 0x48;
  }
  ipc_log_string(param_1,
                 "%s: %s: trb %p (E%d:D%d) buf %08x%08x sz %s%d ctrl %08x (%c%c%c%c:%c%c:%s)",
                 param_4,param_2 + 0xb8,param_3,*(undefined1 *)(param_2 + 0xa8),
                 *(undefined1 *)(param_2 + 0xa9),param_3[1],*param_3,puVar9,uVar2,uVar3,uVar8,uVar7,
                 uVar12,uVar6,uVar5,uVar11,pcVar10);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_trace_event @ 0010e89c size=992
// signature: undefined dwc3_dbg_trace_event(void)
// callers: [entry_trace_event_raw_event_dwc3_log_event]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dwc3_dbg_trace_event(undefined8 param_1,uint param_2,long param_3)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  char *__s;
  char *pcVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  long lVar13;
  
  __s = (char *)kmalloc_trace(___memcpy_toio,0xb20,500);
  if (__s == (char *)0x0) {
    return;
  }
  if ((param_2 & 1) != 0) {
    uVar2 = param_2 >> 8 & 0xf;
    if (uVar2 < 0xc) {
      switch(uVar2) {
      case 0:
        pcVar9 = "Disconnect: [%s]";
        break;
      case 1:
        pcVar9 = "Reset [%s]";
        break;
      case 2:
        pcVar9 = "Connection Done [%s]";
        break;
      case 3:
        pcVar9 = "Link Change [%s]";
        break;
      case 4:
        pcVar9 = "WakeUp [%s]";
        break;
      default:
        goto switchD_0010e9e8_caseD_5;
      case 6:
        pcVar9 = "Suspend [%s]";
        break;
      case 7:
        pcVar9 = "Start-Of-Frame [%s]";
        break;
      case 9:
        pcVar9 = "Erratic Error [%s]";
        break;
      case 10:
        pcVar9 = "Command Complete [%s]";
        break;
      case 0xb:
        pcVar9 = "Overflow [%s]";
      }
      snprintf(__s,500,pcVar9,(&PTR_DAT_00110278)[param_2 >> 0x10 & 0xf]);
    }
    else {
switchD_0010e9e8_caseD_5:
      builtin_strncpy(__s,"UNKNOWN",8);
    }
    goto LAB_0010ec44;
  }
  puVar1 = &DAT_0011045b;
  if ((param_2 & 2) != 0) {
    puVar1 = &DAT_001111f3;
  }
  uVar2 = *(uint *)(param_3 + 0x47c);
  iVar7 = scnprintf(__s,500,"ep%d%s: ",param_2 >> 2 & 0xf,puVar1);
  uVar4 = param_2 >> 6 & 0xf;
  lVar13 = (long)iVar7;
  if (6 < uVar4 - 1) {
switchD_0010e948_caseD_5:
    pcVar9 = __s + lVar13;
    lVar13 = 500 - lVar13;
    pcVar8 = "UNKNOWN";
    goto LAB_0010ec40;
  }
  uVar5 = param_2 >> 1 & 0x1f;
  uVar3 = param_2 >> 0xc;
  uVar6 = uVar3 & 0xf;
  switch(uVar4) {
  case 1:
    uVar11 = 0x73;
    if ((uVar3 & 2) != 0) {
      uVar11 = 0x53;
    }
    uVar12 = 0x69;
    if ((uVar3 & 4) != 0) {
      uVar12 = 0x49;
    }
    uVar10 = 0x6c;
    if (7 < uVar6) {
      uVar10 = 0x4c;
    }
    iVar7 = scnprintf(__s + lVar13,500 - lVar13,"Transfer Complete (%c%c%c)",uVar11,uVar12,uVar10);
    if (uVar5 < 2) {
      if (uVar2 < 4) {
        pcVar9 = (&PTR_s_Unconnected_001102f8)[(int)uVar2];
      }
      else {
        pcVar9 = "UNKNOWN";
      }
      scnprintf(__s + lVar13 + iVar7,500 - (lVar13 + iVar7)," [%s]",pcVar9);
    }
    goto LAB_0010ec44;
  case 2:
    uVar11 = 0x73;
    if ((uVar3 & 2) != 0) {
      uVar11 = 0x53;
    }
    uVar12 = 0x69;
    if ((uVar3 & 4) != 0) {
      uVar12 = 0x49;
    }
    uVar10 = 0x6d;
    if (7 < uVar6) {
      uVar10 = 0x4d;
    }
    scnprintf(__s + lVar13,500 - lVar13,"Transfer In Progress [%08x] (%c%c%c)",param_2 >> 0x10,
              uVar11,uVar12,uVar10);
    goto LAB_0010ec44;
  case 3:
    pcVar9 = " (Not Active)";
    if ((param_2 & 0x8000) != 0) {
      pcVar9 = " (Active)";
    }
    iVar7 = scnprintf(__s + lVar13,500 - lVar13,"Transfer Not Ready [%08x]%s",param_2 >> 0x10,pcVar9
                     );
    if (1 < uVar5) goto LAB_0010ec44;
    lVar13 = lVar13 + iVar7;
    uVar2 = param_2 >> 0xc & 3;
    if (uVar2 == 2) {
      pcVar9 = __s + lVar13;
      lVar13 = 500 - lVar13;
      pcVar8 = " [Status Phase]";
    }
    else {
      if (uVar2 != 1) goto LAB_0010ec44;
      pcVar9 = __s + lVar13;
      lVar13 = 500 - lVar13;
      pcVar8 = " [Data Phase]";
    }
    break;
  case 4:
    pcVar9 = __s + lVar13;
    lVar13 = 500 - lVar13;
    pcVar8 = "FIFO";
    break;
  case 5:
    goto switchD_0010e948_caseD_5;
  case 6:
    pcVar9 = __s + lVar13;
    lVar13 = 500 - lVar13;
    if (uVar6 == 1) {
      scnprintf(pcVar9,lVar13," Stream %d Found",param_2 >> 0x10);
      goto LAB_0010ec44;
    }
    pcVar8 = " Stream Not Found";
    break;
  case 7:
    pcVar9 = __s + lVar13;
    lVar13 = 500 - lVar13;
    pcVar8 = "Endpoint Command Complete";
  }
LAB_0010ec40:
  scnprintf(pcVar9,lVar13,pcVar8);
LAB_0010ec44:
  ipc_log_string(param_1,"event (%08x): %s",param_2,__s);
  kfree(__s);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_trace_ep @ 0010ec80 size=212
// signature: undefined dwc3_dbg_trace_ep(void)
// callers: [entry_trace_event_raw_event_dwc3_log_ep]
//------------------------------------------------------------

void dwc3_dbg_trace_ep(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar1 = *(uint *)(param_2 + 0xa4);
  uVar2 = 0x65;
  if ((uVar1 & 1) != 0) {
    uVar2 = 0x45;
  }
  uVar3 = 0x73;
  if ((uVar1 & 2) != 0) {
    uVar3 = 0x53;
  }
  uVar4 = 0x77;
  if ((uVar1 & 4) != 0) {
    uVar4 = 0x57;
  }
  uVar5 = 0x62;
  if ((uVar1 & 8) != 0) {
    uVar5 = 0x42;
  }
  uVar6 = 0x70;
  if ((uVar1 & 0x20) != 0) {
    uVar6 = 0x50;
  }
  uVar7 = 0x3e;
  if ((*(byte *)(param_2 + 0xcc) & 1) != 0) {
    uVar7 = 0x3c;
  }
  ipc_log_string(param_1,"%s: mps %d/%d streams %d burst %d ring %d/%d flags %c:%c%c%c%c:%c",
                 param_2 + 0xb8,*(uint *)(param_2 + 0x2e) & 0xffff,*(uint *)(param_2 + 0x2e) >> 0x10
                 ,*(undefined2 *)(param_2 + 0x32),*(byte *)(param_2 + 0x34) >> 2 & 0x1f,
                 *(undefined1 *)(param_2 + 0xa8),*(undefined1 *)(param_2 + 0xa9),uVar2,uVar3,uVar4,
                 uVar5,uVar6,uVar7);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_print @ 0010ed58 size=128
// signature: undefined dwc3_dbg_print(void)
// callers: [dwc3_otg_start_peripheral, dwc3_set_ssphy_orientation_flag, dwc3_resume_work, dwc3_msm_remove, configure_usb_wakeup_interrupt, dwc3_core_complete, dwc3_msm_interrupt_enable, usb_gsi_ep_op, dwc3_restart_usb_work, dwc3_msm_runtime_resume, msm_dwc3_pwr_irq_thread, dwc3_msm_id_notifier, dwc3_otg_sm_work, dwc3_msm_suspend, dwc3_otg_start_host, dwc3_msm_pm_suspend, dwc3_msm_pm_resume, dwc3_msm_ep_enable, dwc3_core_prepare, dwc3_msm_vbus_notifier, dwc3_msm_runtime_suspend, dwc3_msm_runtime_idle, dwc3_msm_update_bus_bw, configure_nonpdc_usb_interrupt, dwc3_msm_resume]
//------------------------------------------------------------

void dwc3_dbg_print(undefined8 param_1,ulong param_2,long param_3,undefined4 param_4,
                   undefined8 param_5)

{
  uint uVar1;
  uint uVar2;
  
  if ((((uint)param_2 ^ 0xffffffff) & 0xff) == 0) {
    if (param_3 == 0) {
      return;
    }
    uVar1 = 0xff;
  }
  else {
    uVar1 = (uint)param_2 & 0xff;
    if ((param_2 & 1) == 0) {
      if (param_3 == 0) {
        return;
      }
      uVar2 = ep_addr_rxdbg_mask;
    }
    else {
      if (param_3 == 0) {
        return;
      }
      uVar2 = ep_addr_txdbg_mask;
    }
    if ((uVar2 & 1 << (ulong)((uint)(param_2 >> 1) & 0x1f)) == 0) {
      return;
    }
  }
  ipc_log_string(param_1,"%02X %-25.25s %4i ?\t%s",uVar1,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_done @ 0010eddc size=120
// signature: undefined dwc3_dbg_done(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_done(undefined8 param_1,ulong param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0xff;
  if ((((uint)param_2 ^ 0xffffffff) & 0xff) != 0) {
    uVar2 = (uint)param_2 & 0xff;
    uVar1 = ep_addr_txdbg_mask;
    if ((param_2 & 1) == 0) {
      uVar1 = ep_addr_rxdbg_mask;
    }
    if ((uVar1 & 1 << (ulong)((uint)(param_2 >> 1) & 0x1f)) == 0) {
      return;
    }
  }
  ipc_log_string(param_1,"%02X %-25.25s %4i ?\t%d",uVar2,&DAT_0011167e,param_4,param_3);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_event @ 0010ee58 size=156
// signature: undefined dwc3_dbg_event(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_event(undefined8 param_1,ulong param_2,long param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((((uint)param_2 ^ 0xffffffff) & 0xff) == 0) {
    if (param_3 == 0) {
      return;
    }
    uVar2 = 0xff;
  }
  else {
    uVar2 = (uint)param_2 & 0xff;
    uVar1 = 1 << (ulong)((uint)(param_2 >> 1) & 0x1f);
    if ((param_2 & 1) == 0) {
      if (param_3 == 0) {
        return;
      }
      if ((ep_addr_rxdbg_mask & uVar1) == 0) {
        return;
      }
      uVar3 = ep_addr_rxdbg_mask;
    }
    else {
      if (param_3 == 0) {
        return;
      }
      if ((ep_addr_txdbg_mask & uVar1) == 0) {
        return;
      }
      uVar3 = ep_addr_txdbg_mask;
    }
    if ((uVar3 & uVar1) == 0) {
      return;
    }
  }
  ipc_log_string(param_1,"%02X %-25.25s %4i ?\t%s",uVar2,param_3,param_4,&DAT_00111364);
  return;
}



//------------------------------------------------------------
// dwc3_dbg_queue @ 0010eef8 size=144
// signature: undefined dwc3_dbg_queue(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_queue(undefined8 param_1,ulong param_2,long param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xff;
  if ((((uint)param_2 ^ 0xffffffff) & 0xff) == 0) {
    if (param_3 == 0) {
      return;
    }
  }
  else {
    uVar1 = (uint)param_2 & 0xff;
    if ((param_2 & 1) == 0) {
      if (param_3 == 0) {
        return;
      }
      uVar2 = ep_addr_rxdbg_mask;
    }
    else {
      if (param_3 == 0) {
        return;
      }
      uVar2 = ep_addr_txdbg_mask;
    }
    if ((uVar2 & 1 << (ulong)((uint)(param_2 >> 1) & 0x1f)) == 0) {
      return;
    }
  }
  ipc_log_string(param_1,"%02X %-25.25s %4i ?\t%d %d",uVar1,"QUEUE",param_4,
                 (*(uint *)(param_3 + 0x28) >> 0x11 ^ 0xffffffff) & 1,*(undefined4 *)(param_3 + 8));
  return;
}



//------------------------------------------------------------
// dwc3_dbg_setup @ 0010ef8c size=156
// signature: undefined dwc3_dbg_setup(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_setup(undefined8 param_1,ulong param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0xff;
  if ((((uint)param_2 ^ 0xffffffff) & 0xff) == 0) {
    if (param_3 == (undefined1 *)0x0) {
      return;
    }
  }
  else {
    uVar1 = (uint)param_2 & 0xff;
    if ((param_2 & 1) == 0) {
      if (param_3 == (undefined1 *)0x0) {
        return;
      }
      uVar2 = ep_addr_rxdbg_mask;
    }
    else {
      if (param_3 == (undefined1 *)0x0) {
        return;
      }
      uVar2 = ep_addr_txdbg_mask;
    }
    if ((uVar2 & 1 << (ulong)((uint)(param_2 >> 1) & 0x1f)) == 0) {
      return;
    }
  }
  ipc_log_string(param_1,"%02X %-25.25s ?\t%02X %02X %04X %04X %d",uVar1,"SETUP",*param_3,param_3[1]
                 ,*(undefined2 *)(param_3 + 2),*(undefined2 *)(param_3 + 4),
                 *(undefined2 *)(param_3 + 6));
  return;
}



//------------------------------------------------------------
// dwc3_dbg_print_reg @ 0010f02c size=48
// signature: undefined dwc3_dbg_print_reg(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_print_reg(undefined8 param_1,long param_2,undefined4 param_3)

{
  if (param_2 != 0) {
    ipc_log_string(param_1,"%s = 0x%08x",param_2,param_3);
  }
  return;
}



//------------------------------------------------------------
// dwc3_dbg_dma_unmap @ 0010f060 size=144
// signature: undefined dwc3_dbg_dma_unmap(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_dma_unmap(undefined8 param_1,uint param_2,long param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  
  if (1 < (param_2 & 0xff)) {
    puVar1 = &DAT_00112b90;
    if ((param_2 & 1) != 0) {
      puVar1 = &DAT_00112fc2;
    }
    puVar2 = &DAT_00111364;
    if ((*(uint *)(*(long *)(param_3 + 0xa8) + 0xc) & 1) != 0) {
      puVar2 = &DAT_00113719;
    }
    ipc_log_string(param_1,"%02X-%-3.3s %-25.25s 0x%pK %pad %u %pad %s",param_2 >> 1 & 0x7f,puVar1,
                   "UNMAP",param_3,param_3 + 0x10,*(undefined4 *)(param_3 + 8),param_3 + 0xb0,puVar2
                  );
  }
  return;
}



//------------------------------------------------------------
// dwc3_dbg_dma_map @ 0010f0f4 size=112
// signature: undefined dwc3_dbg_dma_map(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_dma_map(undefined8 param_1,uint param_2,long param_3)

{
  undefined *puVar1;
  
  if (1 < (param_2 & 0xff)) {
    puVar1 = &DAT_00112b90;
    if ((param_2 & 1) != 0) {
      puVar1 = &DAT_00112fc2;
    }
    ipc_log_string(param_1,"%02X-%-3.3s %-25.25s 0x%pK %pad %u %pad",param_2 >> 1 & 0x7f,puVar1,
                   &DAT_00113486,param_3,param_3 + 0x10,*(undefined4 *)(param_3 + 8),param_3 + 0xb0)
    ;
  }
  return;
}



//------------------------------------------------------------
// dwc3_dbg_dma_dequeue @ 0010f168 size=96
// signature: undefined dwc3_dbg_dma_dequeue(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_dma_dequeue(undefined8 param_1,uint param_2,long param_3)

{
  undefined *puVar1;
  
  if (1 < (param_2 & 0xff)) {
    puVar1 = &DAT_00112b90;
    if ((param_2 & 1) != 0) {
      puVar1 = &DAT_00112fc2;
    }
    ipc_log_string(param_1,"%02X-%-3.3s %-25.25s 0x%pK %pad %pad",param_2 >> 1 & 0x7f,puVar1,
                   "DEQUEUE",param_3,param_3 + 0x10,param_3 + 0xb0);
  }
  return;
}



//------------------------------------------------------------
// dwc3_dbg_dma_queue @ 0010f1cc size=88
// signature: undefined dwc3_dbg_dma_queue(void)
// callers: []
//------------------------------------------------------------

void dwc3_dbg_dma_queue(undefined8 param_1,uint param_2,undefined8 param_3)

{
  undefined *puVar1;
  
  if (1 < (param_2 & 0xff)) {
    puVar1 = &DAT_00112b90;
    if ((param_2 & 1) != 0) {
      puVar1 = &DAT_00112fc2;
    }
    ipc_log_string(param_1,"%02X-%-3.3s %-25.25s 0x%pK",param_2 >> 1 & 0x7f,puVar1,"QUEUE",param_3);
  }
  return;
}



//------------------------------------------------------------
// dwc3_msm_kretprobe_init @ 0010f228 size=600
// signature: undefined dwc3_msm_kretprobe_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 dwc3_msm_kretprobe_init(void)

{
  int iVar1;
  
  iVar1 = register_kretprobe(&dwc3_msm_probes);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_dwc3_gadget_run_stop_00113f48,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00113fc8);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_dwc3_send_gadget_ep_cmd_00113ff8,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114078);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_dwc3_gadget_reset_interrupt_001140a8,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114128);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s___dwc3_gadget_ep_enable_00114158,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_001141d8);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_dwc3_gadget_pullup_00114208,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114288);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s___dwc3_gadget_start_001142b8,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114338);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_usb_ep_set_maxpacket_limit_00114368,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_001143e8);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_dwc3_suspend_common_00114418,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114498);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_trace_event_raw_event_dwc3_log_r_001144c8,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114548);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_trace_event_raw_event_dwc3_log_g_00114578,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_001145f8);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_trace_event_raw_event_dwc3_log_t_00114628,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_001146a8);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_trace_event_raw_event_dwc3_log_e_001146d8,iVar1);
  }
  iVar1 = register_kretprobe(&DAT_00114758);
  if (iVar1 < 0) {
    _printk(&DAT_00112602,PTR_s_trace_event_raw_event_dwc3_log_e_00114788,iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// dwc3_msm_kretprobe_exit @ 0010f484 size=144
// signature: undefined dwc3_msm_kretprobe_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void dwc3_msm_kretprobe_exit(void)

{
  unregister_kretprobe(&dwc3_msm_probes);
  unregister_kretprobe(&DAT_00113fc8);
  unregister_kretprobe(&DAT_00114078);
  unregister_kretprobe(&DAT_00114128);
  unregister_kretprobe(&DAT_001141d8);
  unregister_kretprobe(&DAT_00114288);
  unregister_kretprobe(&DAT_00114338);
  unregister_kretprobe(&DAT_001143e8);
  unregister_kretprobe(&DAT_00114498);
  unregister_kretprobe(&DAT_00114548);
  unregister_kretprobe(&DAT_001145f8);
  unregister_kretprobe(&DAT_001146a8);
  unregister_kretprobe(&DAT_00114758);
  return;
}



//------------------------------------------------------------
// entry_dwc3_gadget_run_stop @ 0010f518 size=168
// signature: undefined entry_dwc3_gadget_run_stop(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_dwc3_gadget_run_stop(undefined8 param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *param_2;
  if ((int)param_2[1] == 0) {
    dwc3_core_stop_hw_active_transfers(lVar3);
    dwc3_msm_notify_event(lVar3,0xd,0);
    dwc3_msm_notify_event(lVar3,0xf,0);
  }
  else {
    lVar1 = irq_to_desc(*(undefined4 *)(lVar3 + 0x440));
    if (lVar1 != 0) {
      for (lVar1 = *(long *)(lVar1 + 0x78); lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x18)) {
        lVar2 = *(long *)(lVar1 + 0x28);
        if (lVar2 != 0) {
          _dev_info(*(undefined8 *)(lVar3 + 400),"Set IRQ thread:%s pid:%d to SCHED_NORMAL prio\n",
                    lVar2 + 0x848,*(undefined4 *)(lVar2 + 0x630));
          sched_set_normal(*(undefined8 *)(lVar1 + 0x28),0xffffffec);
          return 0;
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// entry_dwc3_send_gadget_ep_cmd @ 0010f5c4 size=60
// signature: undefined entry_dwc3_send_gadget_ep_cmd(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_dwc3_send_gadget_ep_cmd(undefined8 param_1,long *param_2)

{
  if ((int)param_2[1] == 8) {
    dwc3_msm_notify_event(*(undefined8 *)(*param_2 + 0x98),7,*(undefined1 *)(*param_2 + 0xaa));
  }
  return 0;
}



//------------------------------------------------------------
// entry_dwc3_gadget_reset_interrupt @ 0010f604 size=44
// signature: undefined entry_dwc3_gadget_reset_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_dwc3_gadget_reset_interrupt(undefined8 param_1,undefined8 *param_2)

{
  dwc3_msm_notify_event(*param_2,0xf,0);
  return 0;
}



//------------------------------------------------------------
// entry___dwc3_gadget_ep_enable @ 0010f634 size=76
// signature: undefined entry___dwc3_gadget_ep_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 entry___dwc3_gadget_ep_enable(undefined8 param_1,long *param_2)

{
  if (((int)param_2[1] == -0x80000000) && (*(char *)(*param_2 + 0xaa) == '\x01')) {
    dwc3_msm_notify_event(*(undefined8 *)(*param_2 + 0x98),5,0);
  }
  return 0;
}



//------------------------------------------------------------
// exit_dwc3_gadget_pullup @ 0010f684 size=48
// signature: undefined exit_dwc3_gadget_pullup(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_dwc3_gadget_pullup(long param_1)

{
  dwc3_msm_notify_event(*(undefined8 *)(param_1 + 0x30),9,*(undefined4 *)(param_1 + 0x38));
  return 0;
}



//------------------------------------------------------------
// entry_dwc3_gadget_pullup @ 0010f6b8 size=92
// signature: undefined entry_dwc3_gadget_pullup(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_dwc3_gadget_pullup(long param_1,long *param_2)

{
  undefined8 uVar1;
  
  uVar1 = *(undefined8 *)(*param_2 + 0x108);
  *(undefined8 *)(param_1 + 0x30) = uVar1;
  *(int *)(param_1 + 0x38) = (int)param_2[1];
  dwc3_msm_notify_event(uVar1,8);
  if (*(int *)(param_1 + 0x38) != 0) {
    dwc3_msm_notify_event(*(undefined8 *)(param_1 + 0x30),0x10,0);
  }
  return 0;
}



//------------------------------------------------------------
// entry___dwc3_gadget_start @ 0010f718 size=44
// signature: undefined entry___dwc3_gadget_start(void)
// callers: []
//------------------------------------------------------------

undefined8 entry___dwc3_gadget_start(undefined8 param_1,undefined8 *param_2)

{
  dwc3_msm_notify_event(*param_2,0xb,0);
  return 0;
}



//------------------------------------------------------------
// exit_usb_ep_set_maxpacket_limit @ 0010f748 size=76
// signature: undefined exit_usb_ep_set_maxpacket_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_usb_ep_set_maxpacket_limit(long param_1)

{
  byte bVar1;
  code *pcVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x30) != 0) {
    bVar1 = *(byte *)(param_1 + 0x38);
    if (0x1f < bVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10f794);
      (*pcVar2)();
    }
    if ((bVar1 & 0xfe) != 0) {
      lVar3 = *(long *)(*(long *)(param_1 + 0x30) + (ulong)bVar1 * 8 + 0x270);
      *(undefined4 *)(lVar3 + 0x2e) = 0x4000400;
      *(undefined1 *)(lVar3 + 0x34) = *(undefined1 *)(lVar3 + 0x34);
      *(undefined2 *)(lVar3 + 0x32) = *(undefined2 *)(lVar3 + 0x32);
    }
  }
  return 0;
}



//------------------------------------------------------------
// entry_usb_ep_set_maxpacket_limit @ 0010f798 size=108
// signature: undefined entry_usb_ep_set_maxpacket_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_usb_ep_set_maxpacket_limit(long param_1,long *param_2)

{
  int iVar1;
  char *__s1;
  long lVar2;
  long lVar3;
  
  lVar2 = *param_2;
  lVar3 = *(long *)(lVar2 + 0x98);
  if ((lVar3 != 0) && (*(long *)(lVar3 + 400) != 0)) {
    __s1 = (char *)dev_driver_string();
    iVar1 = strcmp(__s1,"dwc3");
    if (iVar1 == 0) {
      *(long *)(param_1 + 0x30) = lVar3;
      *(uint *)(param_1 + 0x38) = (uint)*(byte *)(lVar2 + 0xaa);
      return 0;
    }
  }
  *(undefined8 *)(param_1 + 0x30) = 0;
  return 0;
}



//------------------------------------------------------------
// exit_dwc3_suspend_common @ 0010f808 size=60
// signature: undefined exit_dwc3_suspend_common(void)
// callers: []
//------------------------------------------------------------

undefined8 exit_dwc3_suspend_common(long param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x30);
  if (*(int *)(lVar2 + 0x3ec) == 1) {
    uVar1 = *(uint *)(param_1 + 0x38);
    if ((uVar1 & 1) != 0) {
      *(uint *)(lVar2 + 0x4e8) = *(uint *)(lVar2 + 0x4e8) | 0x10000000;
    }
    if ((uVar1 >> 1 & 1) != 0) {
      *(uint *)(lVar2 + 0x4e8) = *(uint *)(lVar2 + 0x4e8) | 0x20000000;
    }
  }
  return 0;
}



//------------------------------------------------------------
// entry_dwc3_suspend_common @ 0010f848 size=76
// signature: undefined entry_dwc3_suspend_common(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_dwc3_suspend_common(long param_1,long *param_2)

{
  undefined6 uVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = *param_2;
  if (*(int *)(lVar2 + 0x3ec) == 1) {
    uVar1 = *(undefined6 *)(lVar2 + 0x4e8);
    uVar3 = *(uint *)(lVar2 + 0x4e8) >> 0x1c & 3;
    *(uint *)(lVar2 + 0x4e8) = (uint)uVar1 & 0xcfffffff;
    *(short *)(lVar2 + 0x4ec) = (short)((uint6)uVar1 >> 0x20);
  }
  else {
    uVar3 = 0;
  }
  *(long *)(param_1 + 0x30) = lVar2;
  *(uint *)(param_1 + 0x38) = uVar3;
  return 0;
}



//------------------------------------------------------------
// entry_trace_event_raw_event_dwc3_log_request @ 0010f898 size=52
// signature: undefined entry_trace_event_raw_event_dwc3_log_request(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_trace_event_raw_event_dwc3_log_request(undefined8 param_1,long param_2)

{
  dwc3_dbg_trace_log_request(dwc_trace_ipc_log_ctxt,*(undefined8 *)(param_2 + 8),"dbg_ep_queue");
  return 0;
}



//------------------------------------------------------------
// entry_trace_event_raw_event_dwc3_log_gadget_ep_cmd @ 0010f8d0 size=60
// signature: undefined entry_trace_event_raw_event_dwc3_log_gadget_ep_cmd(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_trace_event_raw_event_dwc3_log_gadget_ep_cmd(undefined8 param_1,long param_2)

{
  dwc3_dbg_trace_ep_cmd
            (dwc_trace_ipc_log_ctxt,*(undefined8 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x10),
             *(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x20));
  return 0;
}



//------------------------------------------------------------
// entry_trace_event_raw_event_dwc3_log_trb @ 0010f910 size=56
// signature: undefined entry_trace_event_raw_event_dwc3_log_trb(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_trace_event_raw_event_dwc3_log_trb(undefined8 param_1,long param_2)

{
  dwc3_dbg_trace_trb_complete
            (dwc_trace_ipc_log_ctxt,*(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10),
             "dbg_prepare");
  return 0;
}



//------------------------------------------------------------
// entry_trace_event_raw_event_dwc3_log_event @ 0010f94c size=52
// signature: undefined entry_trace_event_raw_event_dwc3_log_event(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_trace_event_raw_event_dwc3_log_event(undefined8 param_1,long param_2)

{
  dwc3_dbg_trace_event
            (dwc_trace_ipc_log_ctxt,*(undefined4 *)(param_2 + 8),*(undefined8 *)(param_2 + 0x10));
  return 0;
}



//------------------------------------------------------------
// entry_trace_event_raw_event_dwc3_log_ep @ 0010f984 size=44
// signature: undefined entry_trace_event_raw_event_dwc3_log_ep(void)
// callers: []
//------------------------------------------------------------

undefined8 entry_trace_event_raw_event_dwc3_log_ep(undefined8 param_1,long param_2)

{
  dwc3_dbg_trace_ep(dwc_trace_ipc_log_ctxt,*(undefined8 *)(param_2 + 8));
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 0011031c size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&dwc3_msm_driver);
  dwc3_msm_kretprobe_exit();
  return;
}



//------------------------------------------------------------
// __const_udelay @ 00118000 size=1
// signature: undefined __const_udelay(void)
// callers: [dwc3_msm_host_ss_powerdown, dwc3_msm_host_ss_powerup, msm_dwc3_reset_dbm_ep, dwc3_msm_notify_event, dwc3_core_stop_active_transfer, dwc3_otg_start_host, dwc3_msm_resume, mdwc3_usb2_phy_soft_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00118008 size=1
// signature: undefined _dev_info(void)
// callers: [dwc3_msm_probe, dwc3_otg_start_peripheral, dwc3_resume_work, msm_dwc3_reset_dbm_ep, usb_gsi_ep_op, dwc3_clk_enable_disable, dwc3_restart_usb_work, xhci_test_store, dwc3_pwr_event_handler, dwc3_msm_notify_event, entry_dwc3_gadget_run_stop, dwc3_core_stop_active_transfer, msm_ep_config, dwc3_msm_set_role, dwc3_msm_set_in_p3_state, dwc3_msm_set_dp_mode, dwc3_msm_host_notifier, msm_ep_unconfig, dbm_ep_unconfig, dbm_event_buffer_config, dwc3_msm_runtime_resume, msm_dwc3_pwr_irq_thread, dwc3_msm_id_notifier, dwc3_otg_sm_work, dwc3_msm_suspend, dwc3_otg_start_host, dwc3_msm_pm_suspend, msm_dwc3_pwr_irq, dwc3_msm_ep_queue, dwc3_msm_pm_resume, dwc3_core_prepare, usb_audio_post_reset, dwc3_msm_vbus_notifier, dwc_dpdm_cb, dwc3_msm_runtime_suspend, dwc3_msm_runtime_idle, dwc3_msm_set_dp_only_params, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00118010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [dwc3_msm_ep_queue, enable_l1_suspend_store, dwc3_msm_probe, dwc3_set_ssphy_orientation_flag, dwc3_msm_ep_enable, dwc3_resume_work, dwc3_msm_notify_event, dwc3_core_stop_active_transfer, usb_gsi_ep_op, dynamic_disable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00118018 size=1
// signature: undefined _dev_err(void)
// callers: [dwc3_msm_probe, dwc3_otg_start_peripheral, dwc3_msm_remove, usb_gsi_ep_op, dwc3_clk_enable_disable, enable_l1_suspend_store, dwc3_restart_usb_work, xhci_test_store, dwc3_msm_req_complete_func, dwc3_pwr_event_handler, dwc3_msm_notify_event, bus_vote_store, msm_ep_config, dwc3_msm_set_dp_mode, dwc3_host_complete, msm_data_fifo_config, dwc3_core_resize_tx_fifos, msm_ep_clear_ops, dwc3_otg_sm_work, dwc3_msm_suspend, dwc3_otg_start_host, dwc3_msm_pm_suspend, dwc3_msm_ep_queue, msm_ep_update_ops, dwc3_msm_update_interfaces, dwc3_msm_pm_resume, dwc3_msm_ep_enable, dwc3_msm_config_gdsc, dwc3_msm_extcon_is_valid_source, dwc3_ext_event_notify, dwc3_msm_update_bus_bw, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00118020 size=1
// signature: undefined usleep_range_state(void)
// callers: [dwc3_otg_start_peripheral, msm_dwc3_reset_dbm_ep, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00118028 size=1
// signature: undefined ipc_log_string(void)
// callers: [dwc3_dbg_setup, dwc3_dbg_dma_map, dwc3_resume_work, dwc3_dbg_print_reg, usb_gsi_ep_op, dwc3_dbg_done, dynamic_disable_store, dwc3_start_stop_host, dwc3_restart_usb_work, dwc3_dbg_trace_ep, dwc3_dbg_event, dwc3_dbg_trace_log_request, dwc3_msm_notify_event, dwc3_msm_set_role, dwc3_msm_set_dp_mode, dwc3_dbg_trace_ep_cmd, dwc3_msm_usb_role_switch_get_role, dwc3_dbg_trace_trb_complete, dwc3_dbg_print, dwc3_dbg_dma_queue, mode_store, dwc3_start_stop_device, dwc3_dbg_queue, dwc3_dbg_dma_dequeue, dwc3_otg_start_host, dwc3_dbg_trace_log_ctrl, dwc3_msm_host_ss_powerup, dwc3_dbg_dma_unmap, dwc3_msm_vbus_notifier, dwc3_ext_event_notify, dwc3_dbg_trace_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00118030 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [dwc3_msm_ep_queue, msm_ep_update_ops, dwc3_otg_start_peripheral, msm_ep_unconfig, dwc3_msm_ep_enable, msm_ep_clear_ops, msm_ep_config, usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00118038 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [dwc3_msm_ep_queue, msm_ep_update_ops, dwc3_otg_start_peripheral, msm_ep_unconfig, dwc3_msm_ep_enable, msm_ep_clear_ops, msm_ep_config, usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 00118048 size=1
// signature: undefined ioremap_prot(void)
// callers: [usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 00118050 size=1
// signature: undefined dma_free_attrs(void)
// callers: [dwc3_msm_notify_event, usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 00118058 size=1
// signature: undefined sg_free_table(void)
// callers: [usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00118060 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [dwc3_msm_notify_event, usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_sgtable_attrs @ 00118068 size=1
// signature: undefined dma_get_sgtable_attrs(void)
// callers: [usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_sgtable_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_resource @ 00118070 size=1
// signature: undefined dma_map_resource(void)
// callers: [usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00118078 size=1
// signature: undefined iounmap(void)
// callers: [dwc3_msm_remove, usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00118080 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [dwc3_msm_ep_enable, dwc3_msm_notify_event, usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 00118088 size=1
// signature: undefined sg_next(void)
// callers: [usb_gsi_ep_op]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memremap @ 00118090 size=1
// signature: undefined memremap(void)
// callers: [msm_ep_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00118098 size=1
// signature: undefined _printk(void)
// callers: [enable_l1_suspend_store, dwc3_msm_probe, dwc3_msm_ep_enable, dwc3_msm_notify_event, dwc3_msm_kretprobe_init, msm_ep_config, dwc3_msm_suspend, dwc3_msm_get_repeater_ver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memunmap @ 001180a0 size=1
// signature: undefined memunmap(void)
// callers: [msm_ep_unconfig]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001180a8 size=1
// signature: undefined kfree(void)
// callers: [dwc3_msm_ep_queue, dwc3_msm_probe, dwc3_dbg_trace_log_ctrl, dwc3_msm_remove, dwc3_msm_req_complete_func, msm_ep_clear_ops, dwc3_otg_sm_work, dwc3_dbg_trace_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001180b8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [dwc3_msm_ep_queue, msm_ep_update_ops, dwc3_dbg_trace_log_ctrl, dwc3_otg_sm_work, dwc3_dbg_trace_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001180c0 size=1
// signature: undefined __list_add_valid(void)
// callers: [dwc3_msm_ep_queue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001180c8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [dwc3_msm_ep_queue, dwc3_msm_req_complete_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 001180d0 size=1
// signature: undefined dev_driver_string(void)
// callers: [dwc3_msm_ep_enable, dwc3_core_prepare, entry_usb_ep_set_maxpacket_limit, dwc3_core_complete, dwc3_msm_notify_event, dwc3_core_send_gadget_ep_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 001180d8 size=1
// signature: undefined __warn_printk(void)
// callers: [dwc3_msm_ep_enable, dwc3_msm_notify_event, dwc3_core_send_gadget_ep_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001180e0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [dwc3_msm_probe, dwc3_core_prepare, entry_usb_ep_set_maxpacket_limit, dwc3_core_complete, dwc3_msm_notify_event, dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001180e8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001180f0 size=1
// signature: undefined strscpy(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 001180f8 size=1
// signature: undefined __memcpy_toio(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00118100 size=1
// signature: undefined devm_kmalloc(void)
// callers: [dwc3_msm_probe, dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00118108 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 00118110 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_redriver_gadget_pullup_enter @ 00118118 size=1
// signature: undefined usb_redriver_gadget_pullup_enter(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_redriver_gadget_pullup_enter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_redriver_gadget_pullup_exit @ 00118128 size=1
// signature: undefined usb_redriver_gadget_pullup_exit(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_redriver_gadget_pullup_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 00118130 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00118140 size=1
// signature: undefined queue_work_on(void)
// callers: [dwc3_msm_probe, dwc3_core_complete, dwc3_msm_id_notifier, dwc3_otg_sm_work, dwc3_msm_suspend, dynamic_disable_store, dwc3_msm_pm_resume, dwc3_msm_vbus_notifier, dwc3_msm_notify_event, dwc3_ext_event_notify, dwc_dpdm_cb, dwc3_msm_host_notifier, speed_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00118148 size=1
// signature: undefined fortify_panic(void)
// callers: [dwc3_msm_notify_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 00118150 size=1
// signature: undefined flush_work(void)
// callers: [dwc3_restart_usb_work, dwc3_otg_start_peripheral, dwc3_ext_event_notify, dwc3_start_stop_device, dwc3_otg_start_host, dynamic_disable_store, dwc3_msm_set_dp_mode, dwc3_start_stop_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 00118158 size=1
// signature: undefined __flush_workqueue(void)
// callers: [dwc3_start_stop_device, dwc3_msm_set_dp_mode, dwc3_start_stop_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00118160 size=1
// signature: undefined mutex_lock(void)
// callers: [dwc3_restart_usb_work, dwc3_msm_suspend, dwc3_msm_set_role, dwc3_msm_set_dp_mode, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00118168 size=1
// signature: undefined mutex_unlock(void)
// callers: [dwc3_restart_usb_work, dwc3_msm_suspend, dwc3_msm_set_role, dwc3_msm_set_dp_mode, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00118170 size=1
// signature: undefined msleep(void)
// callers: [dwc3_restart_usb_work, dwc3_otg_start_peripheral, dwc3_start_stop_device, dynamic_disable_store, dwc3_msm_set_dp_mode, dwc3_start_stop_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_redriver_release_lanes @ 00118178 size=1
// signature: undefined usb_redriver_release_lanes(void)
// callers: [dwc3_msm_set_dp_only_params, dwc3_msm_set_dp_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_redriver_release_lanes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00118180 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [dwc3_otg_start_peripheral, dwc3_resume_work, dwc3_msm_remove, dwc3_start_stop_device, dwc3_otg_sm_work, dwc3_msm_suspend, dwc3_otg_start_host, dwc3_start_stop_host, dwc3_msm_modeled_d3_to_d0, xhci_test_store, dwc3_msm_set_dp_mode, dwc3_host_complete, dwc3_msm_resume, pm_runtime_resume_and_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00118188 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [dwc3_msm_probe, dwc3_otg_start_peripheral, dwc3_msm_remove, dwc3_start_stop_device, dwc3_otg_sm_work, dwc3_msm_suspend, dwc3_msm_modeled_d0_to_d3, dwc3_msm_set_dp_mode, dwc3_start_stop_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_redriver_notify_disconnect @ 00118190 size=1
// signature: undefined usb_redriver_notify_disconnect(void)
// callers: [dwc3_otg_start_peripheral, dwc3_otg_start_host, dwc3_msm_set_dp_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_redriver_notify_disconnect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_get_repeater_by_phandle @ 00118198 size=1
// signature: undefined usb_get_repeater_by_phandle(void)
// callers: [dwc3_msm_probe, dwc3_msm_get_repeater_ver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_get_repeater_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001181a0 size=1
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
// platform_driver_unregister @ 001181a8 size=1
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
// log_write_mmio @ 001181b0 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 001181b8 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001181c0 size=1
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
// log_post_read_mmio @ 001181c8 size=1
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
// of_device_is_compatible @ 001181d0 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 001181d8 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [dwc3_msm_probe, dwc3_msm_extcon_is_valid_source]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_attach_by_id @ 001181e0 size=1
// signature: undefined dev_pm_domain_attach_by_id(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_attach_by_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001181f0 size=1
// signature: undefined init_timer_key(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001181f8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00118200 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [dwc3_msm_probe, dwc3_dbg_trace_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00118208 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u8 @ 00118210 size=1
// signature: undefined debugfs_create_u8(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_bool @ 00118218 size=1
// signature: undefined debugfs_create_bool(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00118220 size=1
// signature: undefined debugfs_create_file(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x32 @ 00118228 size=1
// signature: undefined debugfs_create_x32(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00118230 size=1
// signature: undefined alloc_workqueue(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_get_redriver_by_phandle @ 00118238 size=1
// signature: undefined usb_get_redriver_by_phandle(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_get_redriver_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00118240 size=1
// signature: undefined destroy_workqueue(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00118248 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 00118250 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00118258 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00118260 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 00118268 size=1
// signature: undefined irq_modify_status(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00118270 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00118278 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00118280 size=1
// signature: undefined devm_ioremap(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00118288 size=1
// signature: undefined regulator_enable(void)
// callers: [dwc3_msm_probe, dwc3_msm_config_gdsc, dwc3_otg_start_host, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_clk_set_flags @ 00118290 size=1
// signature: undefined qcom_clk_set_flags(void)
// callers: [dwc3_msm_probe, dwc3_msm_config_gdsc, dwc3_msm_remove, dwc3_msm_suspend, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_clk_set_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00118298 size=1
// signature: undefined clk_prepare(void)
// callers: [dwc3_msm_probe, clk_prepare_enable, dwc3_msm_remove, dwc3_clk_enable_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001182a0 size=1
// signature: undefined clk_enable(void)
// callers: [dwc3_msm_probe, clk_prepare_enable, dwc3_msm_remove, dwc3_clk_enable_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001182a8 size=1
// signature: undefined clk_unprepare(void)
// callers: [dwc3_msm_probe, clk_prepare_enable, dwc3_msm_remove, dwc3_clk_enable_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001182b0 size=1
// signature: undefined clk_disable(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove, dwc3_clk_enable_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001182b8 size=1
// signature: undefined regulator_disable(void)
// callers: [dwc3_msm_probe, dwc3_msm_config_gdsc, dwc3_msm_remove, dwc3_msm_suspend, dwc3_otg_start_host, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 001182c0 size=1
// signature: undefined devm_regulator_get(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001182c8 size=1
// signature: undefined of_property_read_string(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 001182d0 size=1
// signature: undefined of_get_property(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001182d8 size=1
// signature: undefined of_find_property(void)
// callers: [dwc3_msm_probe, dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 001182e0 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001182e8 size=1
// signature: undefined __kmalloc(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 001182f0 size=1
// signature: undefined devm_clk_get(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 001182f8 size=1
// signature: undefined clk_set_rate(void)
// callers: [dwc3_msm_probe, dwc3_otg_start_peripheral, dwc3_msm_remove, dwc3_otg_start_host, dwc3_clk_enable_disable, dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 00118300 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00118308 size=1
// signature: undefined of_icc_get(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00118310 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 00118318 size=1
// signature: undefined of_iomap(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00118320 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00118328 size=1
// signature: undefined of_device_is_available(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00118330 size=1
// signature: undefined dma_set_mask(void)
// callers: [dwc3_msm_probe, dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00118338 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [dwc3_msm_probe, dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00118340 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [dwc3_msm_probe, dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// match_string @ 00118348 size=1
// signature: undefined match_string(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get @ 00118350 size=1
// signature: undefined of_irq_get(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_usb_get_phy_by_node @ 00118358 size=1
// signature: undefined devm_usb_get_phy_by_node(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_usb_get_phy_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00118360 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [dwc3_msm_probe, dwc3_otg_sm_work, dwc3_otg_start_host, dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 00118368 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [dwc3_msm_probe, dwc3_otg_start_host, dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_present @ 00118370 size=1
// signature: undefined device_property_present(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00118378 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove, dwc3_msm_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00118380 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [dwc3_msm_probe, dwc3_msm_runtime_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00118388 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_optional @ 00118390 size=1
// signature: undefined devm_regulator_get_optional(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00118398 size=1
// signature: undefined __mutex_init(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_fwnode @ 001183a0 size=1
// signature: undefined dev_fwnode(void)
// callers: [dwc3_msm_probe, dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_role_switch_register @ 001183a8 size=1
// signature: undefined usb_role_switch_register(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_role_switch_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_get_edev_by_phandle @ 001183b0 size=1
// signature: undefined extcon_get_edev_by_phandle(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_get_edev_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_get_edev_name @ 001183b8 size=1
// signature: undefined extcon_get_edev_name(void)
// callers: [dwc3_msm_probe, dwc3_resume_work, dwc3_msm_vbus_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_get_edev_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001183c0 size=1
// signature: size_t strlen(char * __s)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 001183c8 size=1
// signature: undefined strnstr(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_register_notifier @ 001183d0 size=1
// signature: undefined extcon_register_notifier(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_get_state @ 001183d8 size=1
// signature: undefined extcon_get_state(void)
// callers: [dwc3_msm_probe, dwc3_set_ssphy_orientation_flag, dwc3_resume_work, dwc3_msm_vbus_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_get_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled @ 001183e0 size=1
// signature: undefined regulator_is_enabled(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_register_notifier @ 001183e8 size=1
// signature: undefined regulator_register_notifier(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_role_switch_unregister @ 001183f0 size=1
// signature: undefined usb_role_switch_unregister(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_role_switch_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 001183f8 size=1
// signature: undefined icc_put(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_put_redriver @ 00118400 size=1
// signature: undefined usb_put_redriver(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_put_redriver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_detach @ 00118408 size=1
// signature: undefined dev_pm_domain_detach(void)
// callers: [dwc3_msm_probe, dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_round_rate @ 00118410 size=1
// signature: undefined clk_round_rate(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 00118418 size=1
// signature: undefined of_property_match_string(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_add_request @ 00118420 size=1
// signature: undefined cpu_latency_qos_add_request(void)
// callers: [dwc3_msm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_unregister_notifier @ 00118428 size=1
// signature: undefined regulator_unregister_notifier(void)
// callers: [dwc3_msm_remove, dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_to_desc @ 00118430 size=1
// signature: undefined irq_to_desc(void)
// callers: [msm_dwc3_perf_vote_work, dwc3_msm_remove, entry_dwc3_gadget_run_stop, dwc3_msm_suspend, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00118438 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [dwc3_msm_remove, dwc3_msm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_update_request @ 00118440 size=1
// signature: undefined cpu_latency_qos_update_request(void)
// callers: [msm_dwc3_perf_vote_work, dwc3_msm_remove, dwc3_msm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00118448 size=1
// signature: undefined cancel_work_sync(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_remove_request @ 00118450 size=1
// signature: undefined cpu_latency_qos_remove_request(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_put @ 00118458 size=1
// signature: undefined platform_device_put(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_depopulate @ 00118460 size=1
// signature: undefined of_platform_depopulate(void)
// callers: [dwc3_msm_remove, dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_depopulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00118468 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [dwc3_msm_pm_resume, dwc3_msm_remove, dwc3_otg_sm_work, dynamic_disable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_barrier @ 00118470 size=1
// signature: undefined pm_runtime_barrier(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_barrier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 00118478 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [dwc3_otg_start_peripheral, dwc3_msm_pm_resume, dwc3_msm_remove, dwc3_otg_sm_work, dwc3_otg_start_host, dynamic_disable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00118480 size=1
// signature: undefined disable_irq(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00118488 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00118490 size=1
// signature: undefined debugfs_remove(void)
// callers: [dwc3_msm_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// extcon_get_property @ 00118498 size=1
// signature: undefined extcon_get_property(void)
// callers: [dwc3_set_ssphy_orientation_flag, dwc3_resume_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void extcon_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 001184a0 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [dwc3_restart_usb_work, dwc3_otg_start_peripheral, dwc3_otg_sm_work, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 001184a8 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [dwc3_msm_pm_resume, dwc3_otg_sm_work, dynamic_disable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 001184b0 size=1
// signature: undefined hrtimer_active(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_dpdm_switch_update @ 001184b8 size=1
// signature: undefined wcd_usbss_dpdm_switch_update(void)
// callers: [dwc3_msm_vbus_notifier, dwc3_otg_sm_work, dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_dpdm_switch_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 001184c0 size=1
// signature: undefined of_platform_populate(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 001184c8 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_role_switch_find_by_fwnode @ 001184d0 size=1
// signature: undefined usb_role_switch_find_by_fwnode(void)
// callers: [dwc3_otg_sm_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_role_switch_find_by_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001184d8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [dwc3_otg_sm_work, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 001184e0 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [dwc3_otg_sm_work, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_allow @ 001184e8 size=1
// signature: undefined pm_runtime_allow(void)
// callers: [dwc3_otg_sm_work, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_allow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 001184f0 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [msm_dwc3_perf_vote_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001184f8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [msm_dwc3_perf_vote_work, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_role_switch_get_drvdata @ 00118500 size=1
// signature: undefined usb_role_switch_get_drvdata(void)
// callers: [dwc3_msm_usb_role_switch_get_role, dwc3_msm_usb_role_switch_set_role]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_role_switch_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00118508 size=1
// signature: undefined gpio_to_desc(void)
// callers: [dwc3_set_ssphy_orientation_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00118510 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [dwc3_set_ssphy_orientation_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_role_switch_set_role @ 00118518 size=1
// signature: undefined usb_role_switch_set_role(void)
// callers: [dwc3_otg_start_peripheral, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_role_switch_set_role(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_unregister_notify @ 00118520 size=1
// signature: undefined usb_unregister_notify(void)
// callers: [dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_unregister_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wcd_usbss_switch_update @ 00118528 size=1
// signature: undefined wcd_usbss_switch_update(void)
// callers: [dwc3_otg_start_peripheral, dwc3_msm_suspend, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wcd_usbss_switch_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_redriver_notify_connect @ 00118530 size=1
// signature: undefined usb_redriver_notify_connect(void)
// callers: [dwc3_otg_start_peripheral, dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_redriver_notify_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_register_notify @ 00118538 size=1
// signature: undefined usb_register_notify(void)
// callers: [dwc3_otg_start_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_register_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_phy_set_charger_current @ 00118540 size=1
// signature: undefined usb_phy_set_charger_current(void)
// callers: [dwc3_otg_start_peripheral]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_phy_set_charger_current(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_gadget_disconnect @ 00118548 size=1
// signature: undefined usb_gadget_disconnect(void)
// callers: [dwc3_otg_start_peripheral]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_gadget_disconnect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_gadget_connect @ 00118550 size=1
// signature: undefined usb_gadget_connect(void)
// callers: [dwc3_otg_start_peripheral]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_gadget_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_hcd_is_primary_hcd @ 00118558 size=1
// signature: undefined usb_hcd_is_primary_hcd(void)
// callers: [dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_hcd_is_primary_hcd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_redriver_host_powercycle @ 00118560 size=1
// signature: undefined usb_redriver_host_powercycle(void)
// callers: [dwc3_msm_host_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_redriver_host_powercycle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00118568 size=1
// signature: undefined icc_set_bw(void)
// callers: [dwc3_msm_update_bus_bw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent @ 00118570 size=1
// signature: undefined kobject_uevent(void)
// callers: [usb_audio_post_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00118578 size=1
// signature: undefined single_open(void)
// callers: [qos_rec_irq_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00118580 size=1
// signature: undefined seq_printf(void)
// callers: [qos_rec_irq_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00118588 size=1
// signature: undefined seq_puts(void)
// callers: [qos_rec_irq_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_gadget_wakeup @ 00118590 size=1
// signature: undefined usb_gadget_wakeup(void)
// callers: [dwc3_pwr_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_gadget_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00118598 size=1
// signature: undefined scnprintf(void)
// callers: [bus_vote_show, speed_show, enable_l1_suspend_show, orientation_show, dwc3_dbg_trace_event, mode_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_streq @ 001185a0 size=1
// signature: undefined sysfs_streq(void)
// callers: [orientation_store, mode_store, bus_vote_store, speed_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_streq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_speed_string @ 001185a8 size=1
// signature: undefined usb_speed_string(void)
// callers: [speed_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_speed_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 001185b0 size=1
// signature: undefined kstrtobool(void)
// callers: [enable_l1_suspend_store, dynamic_disable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_forbid @ 001185b8 size=1
// signature: undefined pm_runtime_forbid(void)
// callers: [xhci_test_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_forbid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 001185c8 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [configure_usb_wakeup_interrupt, dwc3_msm_interrupt_enable, dwc3_msm_suspend, configure_nonpdc_usb_interrupt, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001185d0 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [configure_usb_wakeup_interrupt, dwc3_msm_interrupt_enable, dwc3_msm_suspend, configure_nonpdc_usb_interrupt, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 001185d8 size=1
// signature: undefined enable_irq(void)
// callers: [configure_usb_wakeup_interrupt, dwc3_msm_suspend, configure_nonpdc_usb_interrupt, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 001185e0 size=1
// signature: undefined pm_relax(void)
// callers: [dwc3_msm_suspend, dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 001185e8 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [dwc3_msm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irqchip_state @ 001185f0 size=1
// signature: undefined irq_set_irqchip_state(void)
// callers: [configure_usb_wakeup_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irqchip_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_type @ 001185f8 size=1
// signature: undefined irq_set_irq_type(void)
// callers: [configure_usb_wakeup_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_type(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00118600 size=1
// signature: undefined pm_stay_awake(void)
// callers: [dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 00118608 size=1
// signature: undefined reset_control_assert(void)
// callers: [dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 00118610 size=1
// signature: undefined reset_control_deassert(void)
// callers: [dwc3_msm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_decode_ctrl @ 00118620 size=1
// signature: undefined usb_decode_ctrl(void)
// callers: [dwc3_dbg_trace_log_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_decode_ctrl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_kretprobe @ 00118630 size=1
// signature: undefined register_kretprobe(void)
// callers: [dwc3_msm_kretprobe_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_kretprobe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_kretprobe @ 00118638 size=1
// signature: undefined unregister_kretprobe(void)
// callers: [dwc3_msm_kretprobe_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_kretprobe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_set_normal @ 00118640 size=1
// signature: undefined sched_set_normal(void)
// callers: [entry_dwc3_gadget_run_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_set_normal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



