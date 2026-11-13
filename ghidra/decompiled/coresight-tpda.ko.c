// Decompiled by Ghidra 12.2
// Program: coresight-tpda.ko
// Image base: 00100000

//------------------------------------------------------------
// tpda_probe @ 00100594 size=1120
// signature: undefined tpda_probe(void)
// callers: []
//------------------------------------------------------------

void tpda_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  long lVar12;
  undefined8 local_88;
  ulong local_80;
  undefined1 *local_78;
  undefined8 local_70;
  long local_68;
  undefined **local_60;
  long local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  uint local_2c;
  long local_28;
  
  lVar9 = sp_el0;
  local_28 = *(long *)(lVar9 + 0x638);
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = (undefined **)0x0;
  local_58 = 0;
  local_70 = 0;
  local_68 = 0;
  local_80 = 0;
  local_78 = (undefined1 *)0x0;
  local_88 = 0;
  local_58 = coresight_alloc_device_name(tpda_devs,param_1);
  if (local_58 != 0) {
    uVar7 = coresight_get_platform_data(param_1);
    if (0xfffffffffffff000 < uVar7) goto LAB_00100930;
    *(ulong *)(param_1 + 0x90) = uVar7;
    plVar8 = (long *)devm_kmalloc(param_1,0x260,0xdc0);
    if (plVar8 != (long *)0x0) {
      plVar8[1] = param_1;
      *(long **)(param_1 + 0x98) = plVar8;
      lVar9 = devm_ioremap_resource(param_1,param_1 + 0x390);
      *plVar8 = lVar9;
      if (lVar9 != 0) {
        __mutex_init(plVar8 + 3,"&drvdata->lock",&tpda_probe___key);
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(plVar8[1] + 0x2e8),"qcom,tpda-atid",(long)plVar8 + 0x4c,1
                           ,0);
        if (iVar6 < 0) {
          lVar9 = plVar8[1];
          pcVar11 = "TPDA ATID is not specified\n";
LAB_001009e0:
          _dev_err(lVar9,pcVar11);
          uVar7 = 0xffffffea;
        }
        else {
          local_2c = 0;
          lVar9 = of_get_property(*(undefined8 *)(plVar8[1] + 0x2e8),"qcom,tc-elem-size",&local_2c);
          if (lVar9 != 0) {
            pcVar11 = "Dataset TC width entries are wrong\n";
            uVar2 = (int)local_2c >> 2;
            if ((0xf7 < local_2c - 8) || ((local_2c >> 2 & 1) != 0)) {
LAB_00100974:
              local_2c = uVar2;
              _dev_err(plVar8[1],pcVar11);
              lVar9 = plVar8[1];
              pcVar11 = "Dataset TC width entries are wrong\n";
              goto LAB_001009e0;
            }
            lVar12 = 0;
            pcVar11 = "Wrong port specified for TC\n";
            do {
              uVar4 = *(uint *)(lVar9 + lVar12 * 4);
              uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
              uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
              if (0x1f < (int)uVar4) goto LAB_00100974;
              local_2c = uVar2;
              if (0x1f < uVar4) goto LAB_001009ec;
              lVar1 = lVar12 * 4;
              lVar12 = lVar12 + 2;
              uVar3 = *(uint *)(lVar9 + lVar1 + 4);
              uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
              *(uint *)((long)plVar8 + (ulong)uVar4 * 4 + 0xd0) = uVar3 >> 0x10 | uVar3 << 0x10;
            } while (lVar12 < (int)uVar2);
          }
          local_2c = 0;
          lVar9 = of_get_property(*(undefined8 *)(plVar8[1] + 0x2e8),"qcom,bc-elem-size",&local_2c);
          if (lVar9 != 0) {
            pcVar11 = "Dataset BC width entries are wrong\n";
            uVar2 = (int)local_2c >> 2;
            if ((0xf7 < local_2c - 8) || ((local_2c >> 2 & 1) != 0)) {
LAB_0010098c:
              local_2c = uVar2;
              _dev_err(plVar8[1],pcVar11);
              lVar9 = plVar8[1];
              pcVar11 = "Dataset BC width entries are wrong\n";
              goto LAB_001009e0;
            }
            lVar12 = 0;
            pcVar11 = "Wrong port specified for BC\n";
            do {
              uVar4 = *(uint *)(lVar9 + lVar12 * 4);
              uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
              uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
              if (0x1f < (int)uVar4) goto LAB_0010098c;
              local_2c = uVar2;
              if (0x1f < uVar4) goto LAB_001009ec;
              lVar1 = lVar12 * 4;
              lVar12 = lVar12 + 2;
              uVar3 = *(uint *)(lVar9 + lVar1 + 4);
              uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
              *(uint *)((long)plVar8 + (ulong)uVar4 * 4 + 0x50) = uVar3 >> 0x10 | uVar3 << 0x10;
            } while (lVar12 < (int)uVar2);
          }
          local_2c = 0;
          lVar9 = of_get_property(*(undefined8 *)(plVar8[1] + 0x2e8),"qcom,dsb-elem-size",&local_2c)
          ;
          if (lVar9 != 0) {
            pcVar11 = "Dataset DSB width entries are wrong\n";
            uVar2 = (int)local_2c >> 2;
            if ((0xf7 < local_2c - 8) || ((local_2c >> 2 & 1) != 0)) {
LAB_001009b4:
              local_2c = uVar2;
              _dev_err(plVar8[1],pcVar11);
              lVar9 = plVar8[1];
              pcVar11 = "Dataset DSB width entries are wrong\n";
              goto LAB_001009e0;
            }
            lVar12 = 0;
            pcVar11 = "Wrong port specified for DSB\n";
            do {
              uVar4 = *(uint *)(lVar9 + lVar12 * 4);
              uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
              uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
              if (0x1f < (int)uVar4) goto LAB_001009b4;
              local_2c = uVar2;
              if (0x1f < uVar4) goto LAB_001009ec;
              lVar1 = lVar12 * 4;
              lVar12 = lVar12 + 2;
              uVar3 = *(uint *)(lVar9 + lVar1 + 4);
              uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
              *(uint *)((long)plVar8 + (ulong)uVar4 * 4 + 0x150) = uVar3 >> 0x10 | uVar3 << 0x10;
            } while (lVar12 < (int)uVar2);
          }
          local_2c = 0;
          lVar9 = of_get_property(*(undefined8 *)(plVar8[1] + 0x2e8),"qcom,cmb-elem-size",&local_2c)
          ;
          if (lVar9 != 0) {
            pcVar11 = "Dataset CMB width entries are wrong\n";
            uVar2 = (int)local_2c >> 2;
            if ((0xf7 < local_2c - 8) || ((local_2c >> 2 & 1) != 0)) {
LAB_001009cc:
              local_2c = uVar2;
              _dev_err(plVar8[1],pcVar11);
              lVar9 = plVar8[1];
              pcVar11 = "Dataset CMB width entries are wrong\n";
              goto LAB_001009e0;
            }
            lVar12 = 0;
            pcVar11 = "Wrong port specified for CMB\n";
            do {
              uVar4 = *(uint *)(lVar9 + lVar12 * 4);
              uVar4 = (uVar4 & 0xff00ff00) >> 8 | (uVar4 & 0xff00ff) << 8;
              uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
              if (0x1f < (int)uVar4) goto LAB_001009cc;
              local_2c = uVar2;
              if (0x1f < uVar4) {
LAB_001009ec:
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1009f0);
                (*pcVar5)();
              }
              lVar1 = lVar12 * 4;
              lVar12 = lVar12 + 2;
              uVar3 = *(uint *)(lVar9 + lVar1 + 4);
              uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
              *(uint *)((long)plVar8 + (ulong)uVar4 * 4 + 0x1d0) = uVar3 >> 0x10 | uVar3 << 0x10;
            } while (lVar12 < (int)uVar2);
          }
          if (*plVar8 == 0) {
            uVar7 = 0xffffffff;
          }
          else {
            uVar10 = readl_relaxed(*plVar8 + 0xfb8);
            uVar7 = 0xffffffff;
            if (((((uVar10 & 3) != 2) && ((uVar10 & 0xc) != 8)) && ((uVar10 & 0x30) != 0x20)) &&
               ((uVar10 & 0xc0) != 0x80)) {
              local_70 = *(undefined8 *)(param_1 + 0x90);
              local_80 = local_80 & 0xffffffff00000000;
              *(undefined1 *)((long)plVar8 + 0x253) = 1;
              local_88 = CONCAT44(local_88._4_4_,1);
              local_78 = &tpda_cs_ops;
              local_60 = &tpda_attr_grps;
              local_68 = param_1;
              uVar7 = coresight_register(&local_88);
              plVar8[2] = uVar7;
              if (uVar7 < 0xfffffffffffff001) {
                __pm_runtime_idle(param_1,5);
                uVar7 = 0;
              }
            }
          }
        }
        goto LAB_00100930;
      }
    }
  }
  uVar7 = 0xfffffff4;
LAB_00100930:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001009f4 size=124
// signature: undefined readl_relaxed(void)
// callers: [tpda_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100a3c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// tpda_enable @ 00100a74 size=588
// signature: undefined tpda_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 tpda_enable(long param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  long *plVar6;
  
  plVar6 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  mutex_lock(plVar6 + 3);
  *(undefined4 *)(*plVar6 + 0xfb0) = 0xc5acce55;
  DataSynchronizationBarrier(3,3,0);
  if (((char)plVar6[9] == '\0') &&
     (*(uint *)*plVar6 =
           (*(uint *)((long)plVar6 + 0x4c) & 0x3ffbfff) << 6 | *(uint *)*plVar6 & 0xffe00003 |
           (uint)*(byte *)(plVar6 + 0x4a) << 5 | (uint)*(byte *)((long)plVar6 + 0x251) << 4 |
           (uint)*(byte *)((long)plVar6 + 0x252) << 3 | (uint)*(byte *)((long)plVar6 + 0x253) << 2 |
           (uint)*(byte *)((long)plVar6 + 0x259) << 0x14, (*(uint *)*plVar6 >> 4 & 1) != 0)) {
    *(undefined4 *)(*plVar6 + 0x84) = 0;
  }
  lVar3 = (long)(int)(param_2 * 4 + 4);
  uVar4 = *(uint *)(*plVar6 + lVar3);
  if (0x1f < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100cc0);
    (*pcVar2)();
  }
  lVar5 = (long)(int)param_2;
  iVar1 = *(int *)((long)plVar6 + lVar5 * 4 + 0x50);
  if (iVar1 == 0x40) {
    uVar4 = uVar4 | 0x10;
  }
  else if (iVar1 == 0x20) {
    uVar4 = uVar4 & 0xffffffef;
  }
  iVar1 = *(int *)((long)plVar6 + lVar5 * 4 + 0xd0);
  if (iVar1 == 0x40) {
    uVar4 = uVar4 | 0x20;
  }
  else if (iVar1 == 0x20) {
    uVar4 = uVar4 & 0xffffffdf;
  }
  iVar1 = *(int *)((long)plVar6 + lVar5 * 4 + 0x150);
  if (iVar1 == 0x40) {
    uVar4 = uVar4 | 0x100;
  }
  else if (iVar1 == 0x20) {
    uVar4 = uVar4 & 0xfffffeff;
  }
  uVar4 = uVar4 & 0xffffff3f;
  iVar1 = *(int *)((long)plVar6 + lVar5 * 4 + 0x1d0);
  if (iVar1 == 0x40) {
    uVar4 = uVar4 | 0x80;
  }
  else if (iVar1 == 0x20) {
    uVar4 = uVar4 | 0x40;
  }
  *(uint *)(*plVar6 + lVar3) = uVar4 & 0xfffffff1 | 10;
  *(uint *)(*plVar6 + lVar3) = uVar4 & 0xfffffff1 | 0xb;
  if ((char)plVar6[9] == '\0') {
    *(uint *)(*plVar6 + 0x8c) = *(uint *)(*plVar6 + 0x8c) & 0xffffe000 | 0xfff;
    if (*(int *)((long)plVar6 + 0x254) == 0) {
      *(int *)(*plVar6 + 0x88) = 0;
    }
    else {
      *(int *)(*plVar6 + 0x88) = *(int *)((long)plVar6 + 0x254);
    }
    *(uint *)*plVar6 = *(uint *)*plVar6 & 0xfffffffd | (uint)*(byte *)(plVar6 + 0x4b) << 1;
  }
  DataSynchronizationBarrier(3,3,0);
  *(undefined4 *)(*plVar6 + 0xfb0) = 0;
  *(undefined1 *)(plVar6 + 9) = 1;
  mutex_unlock(plVar6 + 3);
  _dev_info(plVar6[1],"TPDA inport %d enabled\n",param_2);
  return 0;
}



//------------------------------------------------------------
// tpda_disable @ 00100cc4 size=180
// signature: undefined tpda_disable(void)
// callers: []
//------------------------------------------------------------

void tpda_disable(long param_1,int param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  mutex_lock(plVar2 + 3);
  *(undefined4 *)(*plVar2 + 0xfb0) = 0xc5acce55;
  DataSynchronizationBarrier(3,3,0);
  lVar1 = (long)(param_2 * 4 + 4);
  *(uint *)(*plVar2 + lVar1) = *(uint *)(*plVar2 + lVar1) & 0xfffffffe;
  DataSynchronizationBarrier(3,3,0);
  *(undefined4 *)(*plVar2 + 0xfb0) = 0;
  *(undefined1 *)(plVar2 + 9) = 0;
  mutex_unlock(plVar2 + 3);
  _dev_info(plVar2[1],"TPDA inport %d disabled\n",param_2);
  return;
}



//------------------------------------------------------------
// trig_async_enable_show @ 00100d7c size=64
// signature: undefined trig_async_enable_show(void)
// callers: []
//------------------------------------------------------------

long trig_async_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101c49,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x250));
  return (long)iVar1;
}



//------------------------------------------------------------
// trig_async_enable_store @ 00100dc0 size=172
// signature: undefined trig_async_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
trig_async_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(bool *)(lVar3 + 0x250) = local_40 != 0;
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// trig_flag_ts_enable_show @ 00100e70 size=64
// signature: undefined trig_flag_ts_enable_show(void)
// callers: []
//------------------------------------------------------------

long trig_flag_ts_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101c49,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x251));
  return (long)iVar1;
}



//------------------------------------------------------------
// trig_flag_ts_enable_store @ 00100eb4 size=172
// signature: undefined trig_flag_ts_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
trig_flag_ts_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(bool *)(lVar3 + 0x251) = local_40 != 0;
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// trig_freq_enable_show @ 00100f64 size=64
// signature: undefined trig_freq_enable_show(void)
// callers: []
//------------------------------------------------------------

long trig_freq_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101c49,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x252));
  return (long)iVar1;
}



//------------------------------------------------------------
// trig_freq_enable_store @ 00100fa8 size=172
// signature: undefined trig_freq_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
trig_freq_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(bool *)(lVar3 + 0x252) = local_40 != 0;
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_ts_enable_show @ 00101058 size=64
// signature: undefined freq_ts_enable_show(void)
// callers: []
//------------------------------------------------------------

long freq_ts_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101c49,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x253));
  return (long)iVar1;
}



//------------------------------------------------------------
// freq_ts_enable_store @ 0010109c size=172
// signature: undefined freq_ts_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
freq_ts_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(bool *)(lVar3 + 0x253) = local_40 != 0;
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_req_val_show @ 0010114c size=64
// signature: undefined freq_req_val_show(void)
// callers: []
//------------------------------------------------------------

long freq_req_val_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%#lx\n",
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x254));
  return (long)iVar1;
}



//------------------------------------------------------------
// freq_req_val_store @ 00101190 size=164
// signature: undefined freq_req_val_store(void)
// callers: []
//------------------------------------------------------------

undefined8 freq_req_val_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(int *)(lVar3 + 0x254) = (int)local_40;
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_req_show @ 00101238 size=64
// signature: undefined freq_req_show(void)
// callers: []
//------------------------------------------------------------

long freq_req_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101c49,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 600));
  return (long)iVar1;
}



//------------------------------------------------------------
// freq_req_store @ 0010127c size=172
// signature: undefined freq_req_store(void)
// callers: []
//------------------------------------------------------------

undefined8 freq_req_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(bool *)(lVar3 + 600) = local_40 != 0;
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// global_flush_req_show @ 0010132c size=180
// signature: undefined global_flush_req_show(void)
// callers: []
//------------------------------------------------------------

long global_flush_req_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  plVar1 = plVar5 + 3;
  mutex_lock(plVar1);
  if ((char)plVar5[9] == '\0') {
    mutex_unlock(plVar1);
    lVar4 = -1;
  }
  else {
    *(undefined4 *)(*plVar5 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar2 = *(undefined4 *)*plVar5;
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar5 + 0xfb0) = 0;
    mutex_unlock(plVar1);
    iVar3 = scnprintf(param_3,0x1000,&DAT_00101c5c,uVar2);
    lVar4 = (long)iVar3;
  }
  return lVar4;
}



//------------------------------------------------------------
// global_flush_req_store @ 001013e4 size=248
// signature: undefined global_flush_req_store(void)
// callers: []
//------------------------------------------------------------

undefined8
global_flush_req_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    mutex_lock(plVar3 + 3);
    if ((char)plVar3[9] == '\0') {
      param_4 = 0xffffffffffffffff;
    }
    else if (local_40 != 0) {
      *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      local_40 = (ulong)(*(uint *)*plVar3 | 1);
      *(uint *)*plVar3 = *(uint *)*plVar3 | 1;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar3 + 0xfb0) = 0;
    }
    mutex_unlock(plVar3 + 3);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// port_flush_req_show @ 001014e0 size=184
// signature: undefined port_flush_req_show(void)
// callers: []
//------------------------------------------------------------

long port_flush_req_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  plVar1 = plVar5 + 3;
  mutex_lock(plVar1);
  if ((char)plVar5[9] == '\0') {
    mutex_unlock(plVar1);
    lVar4 = -1;
  }
  else {
    *(undefined4 *)(*plVar5 + 0xfb0) = 0xc5acce55;
    DataSynchronizationBarrier(3,3,0);
    uVar2 = *(undefined4 *)(*plVar5 + 0x90);
    DataSynchronizationBarrier(3,3,0);
    *(undefined4 *)(*plVar5 + 0xfb0) = 0;
    mutex_unlock(plVar1);
    iVar3 = scnprintf(param_3,0x1000,&DAT_00101c5c,uVar2);
    lVar4 = (long)iVar3;
  }
  return lVar4;
}



//------------------------------------------------------------
// port_flush_req_store @ 0010159c size=240
// signature: undefined port_flush_req_store(void)
// callers: []
//------------------------------------------------------------

undefined8
port_flush_req_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar3 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    mutex_lock(plVar3 + 3);
    if ((char)plVar3[9] == '\0') {
      param_4 = 0xffffffffffffffff;
    }
    else if (local_40 != 0) {
      *(undefined4 *)(*plVar3 + 0xfb0) = 0xc5acce55;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar3 + 0x90) = (undefined4)local_40;
      DataSynchronizationBarrier(3,3,0);
      *(undefined4 *)(*plVar3 + 0xfb0) = 0;
    }
    mutex_unlock(plVar3 + 3);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cmbchan_mode_show @ 00101690 size=64
// signature: undefined cmbchan_mode_show(void)
// callers: []
//------------------------------------------------------------

long cmbchan_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101c49,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x259));
  return (long)iVar1;
}



//------------------------------------------------------------
// cmbchan_mode_store @ 001016d4 size=156
// signature: undefined cmbchan_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cmbchan_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined1 local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_3c[0] = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtobool(param_3,local_3c);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    mutex_lock(lVar1);
    *(undefined1 *)(lVar3 + 0x259) = local_3c[0];
    mutex_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 0010179c size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  amba_driver_register(&tpda_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001017c4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  amba_driver_unregister(&tpda_driver);
  return;
}



//------------------------------------------------------------
// tpda_remove @ 001017ec size=36
// signature: undefined tpda_remove(void)
// callers: []
//------------------------------------------------------------

void tpda_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x10));
  return;
}



//------------------------------------------------------------
// amba_driver_register @ 00103000 size=1
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
// amba_driver_unregister @ 00103008 size=1
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
// coresight_alloc_device_name @ 00103010 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00103018 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00103028 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103030 size=1
// signature: undefined __mutex_init(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103038 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00103040 size=1
// signature: undefined of_get_property(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00103048 size=1
// signature: undefined coresight_register(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00103050 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103058 size=1
// signature: undefined _dev_err(void)
// callers: [tpda_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [freq_req_val_store, freq_ts_enable_store, port_flush_req_store, cmbchan_mode_store, trig_freq_enable_store, trig_async_enable_store, tpda_probe, freq_req_store, global_flush_req_store, trig_flag_ts_enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00103068 size=1
// signature: undefined coresight_unregister(void)
// callers: [tpda_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00103070 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00103078 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103080 size=1
// signature: undefined mutex_lock(void)
// callers: [freq_req_val_store, tpda_enable, freq_req_store, global_flush_req_show, trig_flag_ts_enable_store, freq_ts_enable_store, port_flush_req_store, cmbchan_mode_store, tpda_disable, trig_freq_enable_store, trig_async_enable_store, port_flush_req_show, global_flush_req_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103088 size=1
// signature: undefined mutex_unlock(void)
// callers: [freq_req_val_store, tpda_enable, freq_req_store, global_flush_req_show, trig_flag_ts_enable_store, freq_ts_enable_store, port_flush_req_store, cmbchan_mode_store, tpda_disable, trig_freq_enable_store, trig_async_enable_store, port_flush_req_show, global_flush_req_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103090 size=1
// signature: undefined _dev_info(void)
// callers: [tpda_enable, tpda_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103098 size=1
// signature: undefined scnprintf(void)
// callers: [trig_flag_ts_enable_show, trig_async_enable_show, freq_req_val_show, cmbchan_mode_show, freq_req_show, freq_ts_enable_show, trig_freq_enable_show, global_flush_req_show, port_flush_req_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 001030a0 size=1
// signature: undefined kstrtoull(void)
// callers: [freq_req_val_store, freq_ts_enable_store, port_flush_req_store, trig_freq_enable_store, trig_async_enable_store, freq_req_store, global_flush_req_store, trig_flag_ts_enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 001030a8 size=1
// signature: undefined kstrtobool(void)
// callers: [cmbchan_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



