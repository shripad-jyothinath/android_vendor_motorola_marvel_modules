// Decompiled by Ghidra 12.2
// Program: coresight-funnel.ko
// Image base: 00100000

//------------------------------------------------------------
// static_funnel_probe @ 001003b4 size=200
// signature: undefined static_funnel_probe(void)
// callers: []
//------------------------------------------------------------

int static_funnel_probe(long param_1)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  
  lVar1 = param_1 + 0x10;
  piVar2 = (int *)(param_1 + 0x208);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar5) {
      *piVar2 = *piVar2 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  __pm_runtime_set_status(lVar1,0);
  pm_runtime_enable(lVar1);
  iVar6 = funnel_probe(lVar1,0);
  if (iVar6 != 0) {
    iVar7 = *piVar2;
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar3 = *piVar2;
        if (iVar3 != iVar7) goto LAB_00100428;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar5) {
          *piVar2 = iVar7 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_00100428:
      bVar5 = iVar7 != iVar3;
      iVar7 = iVar3;
    } while (bVar5);
    __pm_runtime_disable(lVar1,1);
  }
  return iVar6;
}



//------------------------------------------------------------
// static_funnel_remove @ 0010049c size=64
// signature: undefined static_funnel_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 static_funnel_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 0x10));
  __pm_runtime_disable(param_1 + 0x10,1);
  return 0;
}



//------------------------------------------------------------
// funnel_probe @ 001004dc size=764
// signature: undefined funnel_probe(void)
// callers: [static_funnel_probe, dynamic_funnel_probe]
//------------------------------------------------------------

ulong funnel_probe(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  ulong *puVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 local_118;
  ulong local_110;
  undefined1 *local_108;
  ulong local_100;
  long local_f8;
  undefined **local_f0;
  long local_e8;
  undefined8 local_e0;
  ulong local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  long local_c0;
  long lStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  char *local_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  uVar9 = *(undefined8 *)(param_1 + 0x2e8);
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  lStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  local_f0 = (undefined **)0x0;
  local_e8 = 0;
  local_100 = 0;
  local_f8 = 0;
  local_110 = 0;
  local_108 = (undefined1 *)0x0;
  local_118 = 0;
  uVar4 = dev_fwnode();
  if ((((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) &&
      (*(undefined **)(uVar4 + 8) == &of_fwnode_ops)) &&
     ((iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"arm,coresight-funnel"),
      iVar1 != 0 && ((funnel_probe___print_once & 1) == 0)))) {
    funnel_probe___print_once = 1;
    _dev_warn(param_1,"Uses OBSOLETE CoreSight funnel binding\n");
  }
  local_e8 = coresight_alloc_device_name(funnel_devs,param_1);
  if ((local_e8 == 0) ||
     (puVar5 = (ulong *)devm_kmalloc(param_1,0x28,0xdc0), puVar5 == (ulong *)0x0)) {
    uVar4 = 0xfffffff4;
    goto LAB_00100660;
  }
  uVar6 = devm_clk_get(param_1,"atclk");
  puVar5[1] = uVar6;
  if (uVar6 < 0xfffffffffffff001) {
    uVar8 = clk_prepare();
    uVar4 = uVar8 & 0xffffffff;
    if ((int)uVar8 != 0) goto LAB_00100660;
    uVar3 = clk_enable(uVar6);
    if (uVar3 == 0) goto LAB_001005d4;
    uVar4 = (ulong)uVar3;
  }
  else {
LAB_001005d4:
    lVar7 = of_find_property(uVar9,"qcom,duplicate-funnel",0);
    if (lVar7 != 0) {
      local_60 = (char *)0x0;
      iVar1 = of_property_read_string_helper(uVar9,"reg-names",&local_60,1,0);
      if (-1 < iVar1) {
        iVar1 = 0;
        do {
          iVar2 = strcmp("funnel-base-real",local_60);
          if (iVar2 == 0) {
            uVar6 = of_address_to_resource(uVar9,iVar1,&local_c0);
            uVar4 = uVar6 & 0xffffffff;
            if ((int)uVar6 != 0) goto LAB_00100660;
            uVar4 = devm_ioremap(param_1,local_c0,(lStack_b8 - local_c0) + 1);
            goto LAB_00100700;
          }
          iVar1 = iVar1 + 1;
          iVar2 = of_property_read_string_helper(uVar9,"reg-names",&local_60,1,iVar1);
        } while (-1 < iVar2);
      }
      uVar4 = 0xffffffea;
      goto LAB_00100660;
    }
    if (param_2 == 0) {
LAB_00100728:
      *(ulong **)(param_1 + 0x98) = puVar5;
      uVar4 = coresight_get_platform_data(param_1);
      if (uVar4 < 0xfffffffffffff001) {
        *(ulong *)(param_1 + 0x90) = uVar4;
        *(undefined4 *)(puVar5 + 4) = 0;
        local_118 = CONCAT44(local_118._4_4_,1);
        local_110 = local_110 & 0xffffffff00000000;
        local_108 = funnel_cs_ops;
        local_100 = uVar4;
        local_f8 = param_1;
        uVar4 = coresight_register(&local_118);
        puVar5[2] = uVar4;
        if (uVar4 < 0xfffffffffffff001) {
          __pm_runtime_idle(param_1,5);
          uVar4 = 0;
          goto LAB_00100660;
        }
      }
    }
    else {
      uVar4 = devm_ioremap_resource(param_1,param_2);
LAB_00100700:
      if (uVar4 < 0xfffffffffffff001) {
        *puVar5 = uVar4;
        local_e0 = CONCAT71(local_e0._1_7_,1);
        local_f0 = &coresight_funnel_groups;
        local_d8 = uVar4;
        goto LAB_00100728;
      }
    }
    if ((((int)uVar4 == 0) || (uVar6 = puVar5[1], uVar6 == 0)) || (0xfffffffffffff000 < uVar6))
    goto LAB_00100660;
    clk_disable(uVar6);
  }
  clk_unprepare(uVar6);
LAB_00100660:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// funnel_ctrl_show @ 001007dc size=244
// signature: undefined funnel_ctrl_show(void)
// callers: []
//------------------------------------------------------------

long funnel_ctrl_show(long param_1,undefined8 param_2,char *param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  long *plVar8;
  
  plVar8 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = __pm_runtime_resume(*(long *)(param_1 + 0x60),4);
  if (iVar5 < 0) {
    piVar1 = (int *)(*(long *)(param_1 + 0x60) + 0x1f8);
    iVar7 = *(int *)(*(long *)(param_1 + 0x60) + 0x1f8);
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar7) goto LAB_001008b0;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar7 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_001008b0:
      bVar4 = iVar7 != iVar2;
      iVar7 = iVar2;
    } while (bVar4);
  }
  else {
    writel_relaxed(0xc5acce55,*plVar8 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    uVar6 = readl_relaxed(*plVar8);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar8 + 0xfb0);
    __pm_runtime_idle(*(undefined8 *)(param_1 + 0x60),5);
    iVar5 = sprintf(param_3,"%#x\n",uVar6 & 0xffffffff);
  }
  return (long)iVar5;
}



//------------------------------------------------------------
// readl_relaxed @ 001008e4 size=124
// signature: undefined readl_relaxed(void)
// callers: [funnel_ctrl_show, funnel_enable, funnel_disable]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10092c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00100960 size=132
// signature: undefined writel_relaxed(void)
// callers: [funnel_ctrl_show, funnel_enable, funnel_disable]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100978,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1009b4,uVar1);
  return;
}



//------------------------------------------------------------
// priority_show @ 001009e8 size=60
// signature: undefined priority_show(void)
// callers: []
//------------------------------------------------------------

long priority_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%#lx\n",*(ulong *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x18));
  return (long)iVar1;
}



//------------------------------------------------------------
// priority_store @ 00100a28 size=136
// signature: undefined priority_store(void)
// callers: []
//------------------------------------------------------------

long priority_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

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
    *(undefined8 *)(lVar2 + 0x18) = local_30;
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
// funnel_enable @ 00100ab4 size=308
// signature: undefined funnel_enable(void)
// callers: []
//------------------------------------------------------------

int funnel_enable(long param_1,uint param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  
  plVar8 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  uVar6 = _raw_spin_lock_irqsave(plVar8 + 4);
  lVar7 = *(long *)(param_1 + 0x3c8);
  if ((*(int *)(lVar7 + (long)(int)param_2 * 4) == 0) && (*plVar8 != 0)) {
    lVar7 = plVar8[2];
    writel_relaxed(0xc5acce55,*plVar8 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    uVar4 = readl_relaxed(*plVar8);
    if ((uVar4 & 0xff) == 0) {
      iVar5 = coresight_claim_device_unlocked(lVar7);
      if (iVar5 == 0) goto LAB_00100b74;
    }
    else {
LAB_00100b74:
      writel_relaxed(1 << (ulong)(param_2 & 0x1f) | uVar4 & 0xfffff0ff | 0x700,*plVar8);
      writel_relaxed((int)plVar8[3],*plVar8 + 4);
      iVar5 = 0;
    }
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar8 + 0xfb0);
    if (iVar5 != 0) goto LAB_00100b14;
    lVar7 = *(long *)(param_1 + 0x3c8);
  }
  piVar1 = (int *)(lVar7 + (long)(int)param_2 * 4);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  iVar5 = 0;
LAB_00100b14:
  _raw_spin_unlock_irqrestore(plVar8 + 4,uVar6);
  return iVar5;
}



//------------------------------------------------------------
// funnel_disable @ 00100bf4 size=240
// signature: undefined funnel_disable(void)
// callers: []
//------------------------------------------------------------

void funnel_disable(long param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  
  plVar8 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  uVar6 = _raw_spin_lock_irqsave(plVar8 + 4);
  piVar1 = (int *)(*(long *)(param_1 + 0x3c8) + (long)(int)param_2 * 4);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  if ((iVar2 + -1 == 0) && (*plVar8 != 0)) {
    lVar7 = plVar8[2];
    writel_relaxed(0xc5acce55,*plVar8 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    uVar5 = readl_relaxed(*plVar8);
    uVar5 = uVar5 & (1 << (ulong)(param_2 & 0x1f) ^ 0xffffffffU);
    writel_relaxed(uVar5,*plVar8);
    if ((uVar5 & 0xff) == 0) {
      coresight_disclaim_device_unlocked(lVar7);
    }
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar8 + 0xfb0);
  }
  _raw_spin_unlock_irqrestore(plVar8 + 4,uVar6);
  return;
}



//------------------------------------------------------------
// funnel_runtime_suspend @ 00100cf8 size=72
// signature: undefined funnel_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 funnel_runtime_suspend(long param_1)

{
  ulong uVar1;
  
  if ((*(long *)(param_1 + 0x98) != 0) &&
     (uVar1 = *(ulong *)(*(long *)(param_1 + 0x98) + 8), uVar1 < 0xfffffffffffff001)) {
    clk_disable(uVar1);
    clk_unprepare(uVar1);
  }
  return 0;
}



//------------------------------------------------------------
// funnel_runtime_resume @ 00100d44 size=88
// signature: undefined funnel_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 funnel_runtime_resume(long param_1)

{
  int iVar1;
  ulong uVar2;
  
  if ((((*(long *)(param_1 + 0x98) != 0) &&
       (uVar2 = *(ulong *)(*(long *)(param_1 + 0x98) + 8), uVar2 < 0xfffffffffffff001)) &&
      (iVar1 = clk_prepare(uVar2), iVar1 == 0)) && (iVar1 = clk_enable(uVar2), iVar1 != 0)) {
    clk_unprepare(uVar2);
  }
  return 0;
}



//------------------------------------------------------------
// dynamic_funnel_probe @ 00100da0 size=32
// signature: undefined dynamic_funnel_probe(void)
// callers: []
//------------------------------------------------------------

void dynamic_funnel_probe(long param_1)

{
  funnel_probe(param_1,param_1 + 0x390);
  return;
}



//------------------------------------------------------------
// dynamic_funnel_remove @ 00100dc4 size=36
// signature: undefined dynamic_funnel_remove(void)
// callers: []
//------------------------------------------------------------

void dynamic_funnel_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x10));
  return;
}



//------------------------------------------------------------
// init_module @ 00100df0 size=128
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&static_funnel_driver,&__this_module);
  if (iVar1 == 0) {
    iVar1 = amba_driver_register(&dynamic_funnel_driver);
    if (iVar1 != 0) {
      _printk(&DAT_00101650);
      platform_driver_unregister(&static_funnel_driver);
    }
  }
  else {
    _printk(&DAT_00101685);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100e74 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&static_funnel_driver);
  amba_driver_unregister(&dynamic_funnel_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// amba_driver_register @ 00103008 size=1
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
// _printk @ 00103010 size=1
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
// platform_driver_unregister @ 00103018 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_unregister @ 00103020 size=1
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
// __pm_runtime_set_status @ 00103030 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [static_funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00103038 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [static_funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00103040 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [static_funnel_probe, static_funnel_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00103048 size=1
// signature: undefined coresight_unregister(void)
// callers: [static_funnel_remove, dynamic_funnel_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_fwnode @ 00103050 size=1
// signature: undefined dev_fwnode(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00103060 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 00103068 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103070 size=1
// signature: undefined devm_kmalloc(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00103078 size=1
// signature: undefined devm_clk_get(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103080 size=1
// signature: undefined of_find_property(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00103088 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00103090 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00103098 size=1
// signature: undefined clk_prepare(void)
// callers: [funnel_runtime_resume, funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001030a0 size=1
// signature: undefined clk_enable(void)
// callers: [funnel_runtime_resume, funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001030a8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 001030b0 size=1
// signature: undefined of_address_to_resource(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001030b8 size=1
// signature: undefined devm_ioremap(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 001030c0 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 001030c8 size=1
// signature: undefined coresight_register(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001030d0 size=1
// signature: undefined clk_disable(void)
// callers: [funnel_runtime_suspend, funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001030d8 size=1
// signature: undefined clk_unprepare(void)
// callers: [funnel_runtime_resume, funnel_runtime_suspend, funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001030e0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [funnel_ctrl_show, funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001030e8 size=1
// signature: undefined _dev_warn(void)
// callers: [funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030f0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [priority_store, funnel_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001030f8 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [funnel_ctrl_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00103100 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [funnel_ctrl_show, priority_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00103108 size=1
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
// log_post_read_mmio @ 00103110 size=1
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
// log_write_mmio @ 00103118 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00103120 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00103128 size=1
// signature: undefined kstrtoull(void)
// callers: [priority_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103130 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [funnel_enable, funnel_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103138 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [funnel_enable, funnel_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_claim_device_unlocked @ 00103140 size=1
// signature: undefined coresight_claim_device_unlocked(void)
// callers: [funnel_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_claim_device_unlocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disclaim_device_unlocked @ 00103148 size=1
// signature: undefined coresight_disclaim_device_unlocked(void)
// callers: [funnel_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disclaim_device_unlocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



