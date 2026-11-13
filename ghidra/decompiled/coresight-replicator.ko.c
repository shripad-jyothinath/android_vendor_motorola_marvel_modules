// Decompiled by Ghidra 12.2
// Program: coresight-replicator.ko
// Image base: 00100000

//------------------------------------------------------------
// static_replicator_probe @ 00100324 size=200
// signature: undefined static_replicator_probe(void)
// callers: []
//------------------------------------------------------------

int static_replicator_probe(long param_1)

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
  iVar6 = replicator_probe(lVar1,0);
  if (iVar6 != 0) {
    iVar7 = *piVar2;
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar2,2,0,1);
      do {
        iVar3 = *piVar2;
        if (iVar3 != iVar7) goto LAB_00100398;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
        if (bVar5) {
          *piVar2 = iVar7 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_00100398:
      bVar5 = iVar7 != iVar3;
      iVar7 = iVar3;
    } while (bVar5);
    __pm_runtime_disable(lVar1,1);
  }
  return iVar6;
}



//------------------------------------------------------------
// static_replicator_remove @ 0010040c size=64
// signature: undefined static_replicator_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 static_replicator_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 0x10));
  __pm_runtime_disable(param_1 + 0x10,1);
  return 0;
}



//------------------------------------------------------------
// replicator_probe @ 0010044c size=672
// signature: undefined replicator_probe(void)
// callers: [static_replicator_probe, dynamic_replicator_probe]
//------------------------------------------------------------

ulong replicator_probe(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  ulong *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined1 *local_90;
  ulong local_88;
  long local_80;
  undefined **local_78;
  long local_70;
  undefined8 local_68;
  ulong local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = (undefined **)0x0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = (undefined1 *)0x0;
  local_a0 = 0;
  uVar4 = dev_fwnode();
  if ((((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) &&
      (*(undefined **)(uVar4 + 8) == &of_fwnode_ops)) &&
     ((iVar2 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"arm,coresight-replicator"),
      iVar2 != 0 && ((replicator_probe___print_once & 1) == 0)))) {
    replicator_probe___print_once = 1;
    _dev_warn(param_1,"Uses OBSOLETE CoreSight replicator binding\n");
  }
  local_70 = coresight_alloc_device_name(replicator_devs,param_1);
  if ((local_70 == 0) ||
     (puVar5 = (ulong *)devm_kmalloc(param_1,0x20,0xdc0), puVar5 == (ulong *)0x0)) {
    uVar4 = 0xfffffff4;
    goto LAB_001005f8;
  }
  uVar6 = devm_clk_get(param_1,"atclk");
  puVar5[1] = uVar6;
  if (uVar6 < 0xfffffffffffff001) {
    uVar8 = clk_prepare();
    uVar4 = uVar8 & 0xffffffff;
    if ((int)uVar8 != 0) goto LAB_001005f8;
    uVar3 = clk_enable(uVar6);
    if (uVar3 == 0) goto LAB_00100524;
    uVar4 = (ulong)uVar3;
  }
  else {
LAB_00100524:
    if (param_2 == 0) {
LAB_0010055c:
      uVar7 = dev_fwnode(param_1);
      uVar4 = fwnode_property_present(uVar7,"qcom,replicator-loses-context");
      if ((uVar4 & 1) != 0) {
        *(undefined1 *)((long)puVar5 + 0x1c) = 1;
      }
      *(ulong **)(param_1 + 0x98) = puVar5;
      uVar4 = coresight_get_platform_data(param_1);
      if (uVar4 < 0xfffffffffffff001) {
        *(ulong *)(param_1 + 0x90) = uVar4;
        *(undefined4 *)(puVar5 + 3) = 0;
        local_a0 = CONCAT44(local_a0._4_4_,1);
        local_98 = CONCAT44(local_98._4_4_,1);
        local_90 = replicator_cs_ops;
        local_88 = uVar4;
        local_80 = param_1;
        uVar4 = coresight_register(&local_a0);
        puVar5[2] = uVar4;
        if (uVar4 < 0xfffffffffffff001) {
          if (*puVar5 != 0) {
            writel_relaxed(0xc5acce55,*puVar5 + 0xfb0);
            DataSynchronizationBarrier(3,3,0);
            iVar2 = coresight_claim_device_unlocked(uVar4);
            if (iVar2 == 0) {
              writel_relaxed(0xff,*puVar5);
              writel_relaxed(0xff,*puVar5 + 4);
              coresight_disclaim_device_unlocked(uVar4);
            }
            DataSynchronizationBarrier(3,3,0);
            writel_relaxed(0,*puVar5 + 0xfb0);
          }
          __pm_runtime_idle(param_1,5);
          uVar4 = 0;
          goto LAB_001005f8;
        }
      }
    }
    else {
      uVar4 = devm_ioremap_resource(param_1,param_2);
      if (uVar4 < 0xfffffffffffff001) {
        *puVar5 = uVar4;
        local_68 = CONCAT71(local_68._1_7_,1);
        local_78 = &replicator_groups;
        local_60 = uVar4;
        goto LAB_0010055c;
      }
    }
    if ((((int)uVar4 == 0) || (uVar6 = puVar5[1], uVar6 == 0)) || (0xfffffffffffff000 < uVar6))
    goto LAB_001005f8;
    clk_disable(uVar6);
  }
  clk_unprepare(uVar6);
LAB_001005f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// replicator_enable @ 001006f0 size=384
// signature: undefined replicator_enable(void)
// callers: []
//------------------------------------------------------------

int replicator_enable(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  int iVar9;
  int iVar10;
  long *plVar11;
  
  plVar11 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  uVar7 = _raw_spin_lock_irqsave(plVar11 + 3);
  lVar8 = *(long *)(param_1 + 0x3c8);
  if ((*(int *)(lVar8 + (long)param_3 * 4) == 0) && (*plVar11 != 0)) {
    lVar8 = plVar11[2];
    writel_relaxed(0xc5acce55,*plVar11 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    iVar5 = readl_relaxed(*plVar11);
    iVar6 = readl_relaxed(*plVar11 + 4);
    bVar4 = *(char *)((long)plVar11 + 0x1c) == '\0';
    iVar9 = 0xff;
    if ((bVar4 || iVar5 != 0) || iVar6 != 0) {
      iVar9 = iVar5;
    }
    iVar10 = 0xff;
    if ((bVar4 || iVar5 != 0) || iVar6 != 0) {
      iVar10 = iVar6;
    }
    if (((iVar9 != 0xff) || (iVar10 != 0xff)) ||
       (iVar5 = coresight_claim_device_unlocked(lVar8), iVar5 == 0)) {
      if (param_3 == 0) {
        iVar9 = 0;
      }
      else {
        if (param_3 != 1) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100840);
          (*pcVar3)();
        }
        iVar10 = 0;
      }
      writel_relaxed(iVar9,*plVar11);
      writel_relaxed(iVar10,*plVar11 + 4);
      iVar5 = 0;
    }
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar11 + 0xfb0);
    if (iVar5 != 0) goto LAB_00100750;
    lVar8 = *(long *)(param_1 + 0x3c8);
  }
  piVar1 = (int *)(lVar8 + (long)param_3 * 4);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  iVar5 = 0;
LAB_00100750:
  _raw_spin_unlock_irqrestore(plVar11 + 3,uVar7);
  return iVar5;
}



//------------------------------------------------------------
// replicator_disable @ 0010087c size=284
// signature: undefined replicator_disable(void)
// callers: []
//------------------------------------------------------------

void replicator_disable(long param_1,undefined8 param_2,int param_3)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  
  plVar9 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  uVar6 = _raw_spin_lock_irqsave(plVar9 + 3);
  piVar1 = (int *)(*(long *)(param_1 + 0x3c8) + (long)param_3 * 4);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar5 = *piVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = iVar5 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  if ((iVar5 + -1 == 0) && (*plVar9 != 0)) {
    lVar7 = plVar9[2];
    if (param_3 == 0) {
      lVar8 = 0;
    }
    else {
      if (param_3 != 1) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100960);
        (*pcVar4)();
      }
      lVar8 = 4;
    }
    writel_relaxed(0xc5acce55,*plVar9 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0xff,*plVar9 + lVar8);
    iVar5 = readl_relaxed(*plVar9);
    if ((iVar5 == 0xff) && (iVar5 = readl_relaxed(*plVar9 + 4), iVar5 == 0xff)) {
      coresight_disclaim_device_unlocked(lVar7);
    }
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar9 + 0xfb0);
  }
  _raw_spin_unlock_irqrestore(plVar9 + 3,uVar6);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001009a8 size=124
// signature: undefined readl_relaxed(void)
// callers: [replicator_enable, replicator_disable]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1009f0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00100a24 size=132
// signature: undefined writel_relaxed(void)
// callers: [replicator_enable, replicator_probe, replicator_disable]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100a3c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100a78,uVar1);
  return;
}



//------------------------------------------------------------
// replicator_runtime_suspend @ 00100aac size=72
// signature: undefined replicator_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 replicator_runtime_suspend(long param_1)

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
// replicator_runtime_resume @ 00100af8 size=88
// signature: undefined replicator_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 replicator_runtime_resume(long param_1)

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
// dynamic_replicator_probe @ 00100b54 size=32
// signature: undefined dynamic_replicator_probe(void)
// callers: []
//------------------------------------------------------------

void dynamic_replicator_probe(long param_1)

{
  replicator_probe(param_1,param_1 + 0x390);
  return;
}



//------------------------------------------------------------
// dynamic_replicator_remove @ 00100b78 size=36
// signature: undefined dynamic_replicator_remove(void)
// callers: []
//------------------------------------------------------------

void dynamic_replicator_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x10));
  return;
}



//------------------------------------------------------------
// init_module @ 00100ba4 size=128
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&static_replicator_driver,&__this_module);
  if (iVar1 == 0) {
    iVar1 = amba_driver_register(&dynamic_replicator_driver);
    if (iVar1 != 0) {
      _printk(&DAT_00101578);
      platform_driver_unregister(&static_replicator_driver);
    }
  }
  else {
    _printk(&DAT_0010159f);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100c28 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&static_replicator_driver);
  amba_driver_unregister(&dynamic_replicator_driver);
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
// callers: [cleanup_module, init_module]
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
// callers: [static_replicator_probe]
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
// callers: [static_replicator_probe]
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
// callers: [static_replicator_remove, static_replicator_probe]
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
// callers: [static_replicator_remove, dynamic_replicator_remove]
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
// callers: [replicator_probe]
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
// callers: [replicator_probe]
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
// callers: [replicator_probe]
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
// callers: [replicator_probe]
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
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00103080 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_present @ 00103088 size=1
// signature: undefined fwnode_property_present(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00103090 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00103098 size=1
// signature: undefined coresight_register(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001030a0 size=1
// signature: undefined clk_disable(void)
// callers: [replicator_runtime_suspend, replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001030a8 size=1
// signature: undefined clk_prepare(void)
// callers: [replicator_runtime_resume, replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001030b0 size=1
// signature: undefined clk_enable(void)
// callers: [replicator_runtime_resume, replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001030b8 size=1
// signature: undefined clk_unprepare(void)
// callers: [replicator_runtime_suspend, replicator_runtime_resume, replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_claim_device_unlocked @ 001030c0 size=1
// signature: undefined coresight_claim_device_unlocked(void)
// callers: [replicator_enable, replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_claim_device_unlocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disclaim_device_unlocked @ 001030c8 size=1
// signature: undefined coresight_disclaim_device_unlocked(void)
// callers: [replicator_probe, replicator_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disclaim_device_unlocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001030d0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001030d8 size=1
// signature: undefined _dev_warn(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030e0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [replicator_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001030e8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [replicator_enable, replicator_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001030f0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [replicator_enable, replicator_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001030f8 size=1
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
// log_post_read_mmio @ 00103100 size=1
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
// log_write_mmio @ 00103108 size=1
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
// log_post_write_mmio @ 00103110 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



