// Decompiled by Ghidra 12.2
// Program: msm_show_resume_irq.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_show_resume_probe @ 00100264 size=200
// signature: undefined msm_show_resume_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_show_resume_probe(long param_1)

{
  undefined8 uVar1;
  
  base = of_iomap(*(undefined8 *)(param_1 + 0x2f8),0);
  if (base < 0xfffffffffffff001) {
    tracepoint_probe_register_prio
              (&__tracepoint_android_vh_cpuidle_psci_enter,gic_s2idle_enter,0,0x7fffffff);
    tracepoint_probe_register_prio
              (&__tracepoint_android_vh_cpuidle_psci_exit,gic_s2idle_exit,0,0x7fffffff);
    register_syscore_ops(gic_syscore_ops);
    register_pm_notifier(&gic_notif_block);
    tracepoint_probe_register(&__tracepoint_android_vh_gic_v3_suspend,gic_suspend_ds,0);
    uVar1 = 0;
  }
  else {
    _printk(&DAT_00100e80,*(undefined8 *)(param_1 + 0x2f8),base);
    uVar1 = 0xfffffffa;
  }
  return uVar1;
}



//------------------------------------------------------------
// msm_show_resume_remove @ 00100330 size=100
// signature: undefined msm_show_resume_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_show_resume_remove(void)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_cpuidle_psci_enter,gic_s2idle_enter,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_cpuidle_psci_exit,gic_s2idle_exit,0);
  unregister_syscore_ops(gic_syscore_ops);
  iounmap(base);
  return 0;
}



//------------------------------------------------------------
// gic_s2idle_enter @ 00100398 size=40
// signature: undefined gic_s2idle_enter(void)
// callers: []
//------------------------------------------------------------

void gic_s2idle_enter(undefined8 param_1,undefined8 param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  
  if ((param_3 & 1) != 0) {
    Hint_Prefetch(0x100bc8,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(0x100bc8,0x10);
      if (bVar2) {
        cVar1 = ExclusiveMonitorsStatus();
        cpus_in_s2idle = cpus_in_s2idle + 1;
      }
    } while (cVar1 != '\0');
  }
  return;
}



//------------------------------------------------------------
// gic_s2idle_exit @ 001003d8 size=96
// signature: undefined gic_s2idle_exit(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gic_s2idle_exit(undefined8 param_1,undefined8 param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  
  if ((param_3 & 1) != 0) {
    if (cpus_in_s2idle == ___num_online_cpus) {
      msm_show_resume_irqs();
    }
    Hint_Prefetch(0x100bc8,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(0x100bc8,0x10);
      if (bVar2) {
        cVar1 = ExclusiveMonitorsStatus();
        cpus_in_s2idle = cpus_in_s2idle + -1;
      }
    } while (cVar1 != '\0');
  }
  return;
}



//------------------------------------------------------------
// gic_suspend_ds @ 0010044c size=372
// signature: undefined gic_suspend_ds(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gic_suspend_ds(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  
  lVar4 = tpidr_el1;
  lVar4 = *(long *)(lVar4 + *(long *)(param_2 + 0x18) + 8);
  gic_data_glb = param_2;
  if (((hibernation & 1) != 0) || (_pm_suspend_target_state == 3)) {
    DAT_00101108 = readl_relaxed(lVar4 + 0x10100);
    DAT_0010110c = readl_relaxed(lVar4 + 0x10200);
    DAT_00101104 = readl_relaxed(lVar4 + 0x10c04);
    uVar5 = 0;
    lVar4 = 0;
    do {
      uVar2 = readl_relaxed(base + lVar4 + 0x100);
      lVar1 = base + lVar4;
      *(undefined4 *)((long)&gic_data_ds + lVar4) = uVar2;
      uVar2 = readl_relaxed(lVar1 + 0x200);
      *(undefined4 *)((long)&DAT_00100f84 + lVar4) = uVar2;
      lVar4 = lVar4 + 4;
      uVar5 = uVar5 + 0x20;
      uVar6 = (*(uint *)(param_2 + 0x38) & 0x1f) << 5;
      if (0x3db < uVar6) {
        uVar6 = 0x3dc;
      }
    } while (uVar5 < uVar6 + 0x20);
    if (0xf < uVar6) {
      uVar5 = 2;
      lVar4 = 0xc08;
      do {
        uVar2 = readl_relaxed(base + lVar4);
        uVar5 = uVar5 + 1;
        puVar3 = (undefined4 *)(lVar4 + 0x100404);
        lVar4 = lVar4 + 4;
        *puVar3 = uVar2;
        uVar6 = (*(uint *)(param_2 + 0x38) & 0x1f) << 5;
        if (0x3db < uVar6) {
          uVar6 = 0x3dc;
        }
      } while (uVar5 < uVar6 + 0x20 >> 4);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_show_resume_irqs @ 001005c4 size=692
// signature: undefined msm_show_resume_irqs(void)
// callers: [gic_s2idle_exit]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_show_resume_irqs(void)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = gic_data_glb;
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  if (((hibernation & 1) != 0) || (_pm_suspend_target_state == 3)) {
    lVar6 = tpidr_el1;
    lVar6 = *(long *)(lVar6 + *(long *)(gic_data_glb + 0x18) + 8);
    _printk(&DAT_00100ed6);
    gic_v3_dist_init();
    gic_v3_cpu_init();
    writel_relaxed(DAT_00101108,lVar6 + 0x10100);
    writel_relaxed(DAT_0010110c,lVar6 + 0x10200);
    writel_relaxed(DAT_00101104,lVar6 + 0x10c04);
    uVar3 = (*(uint *)(lVar2 + 0x38) & 0x1f) << 5;
    if (0x3db < uVar3) {
      uVar3 = 0x3dc;
    }
    if (0xf < uVar3) {
      uVar7 = 2;
      lVar6 = 0xc08;
      do {
        writel_relaxed(*(undefined4 *)(lVar6 + 0x100404),base + lVar6);
        uVar7 = uVar7 + 1;
        lVar6 = lVar6 + 4;
        uVar3 = (*(uint *)(lVar2 + 0x38) & 0x1f) << 5;
        if (0x3db < uVar3) {
          uVar3 = 0x3dc;
        }
      } while (uVar7 < uVar3 + 0x20 >> 4);
    }
    gic_v3_dist_wait_for_rwp();
    lVar6 = 0;
    uVar7 = 0;
    do {
      writel_relaxed(*(undefined4 *)((long)&DAT_00100f84 + lVar6),base + lVar6 + 0x200);
      writel_relaxed(*(undefined4 *)((long)&gic_data_ds + lVar6),base + lVar6 + 0x100);
      uVar7 = uVar7 + 0x20;
      lVar6 = lVar6 + 4;
      uVar3 = (*(uint *)(lVar2 + 0x38) & 0x1f) << 5;
      if (0x3db < uVar3) {
        uVar3 = 0x3dc;
      }
    } while (uVar7 < uVar3 + 0x20);
    gic_v3_dist_wait_for_rwp();
  }
  if (msm_show_resume_irq_mask != 0) {
    uVar3 = readl_relaxed(base + 4);
    uVar3 = (uVar3 & 0x1f) << 5;
    lVar6 = 0;
    if (0x3de < uVar3) {
      uVar3 = 0x3df;
    }
    uVar1 = uVar3 + 0x20;
    do {
      uVar4 = readl_relaxed(base + lVar6 + 0x180);
      uVar5 = readl_relaxed(base + lVar6 + 0x200);
      *(uint *)((long)&local_d8 + lVar6) = uVar5 & uVar4;
      lVar6 = lVar6 + 4;
    } while (((ulong)(uVar3 + 0x1f >> 3) & 0xfc) + 4 != lVar6);
    for (uVar3 = _find_first_bit(&local_d8,uVar1); uVar3 < uVar1;
        uVar3 = _find_next_bit(&local_d8,uVar1,uVar3 + 1)) {
      if (0x1f < uVar3) {
        _printk(&DAT_00100e70,"msm_show_resume_irqs",uVar3);
      }
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100878 size=124
// signature: undefined readl_relaxed(void)
// callers: [msm_show_resume_irqs, gic_suspend_ds]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1008c0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 001008f4 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10090c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100948,uVar1);
  return;
}



//------------------------------------------------------------
// gic_suspend_notifier @ 0010097c size=44
// signature: undefined gic_suspend_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 gic_suspend_notifier(undefined8 param_1,long param_2)

{
  if (param_2 == 1) {
    hibernation = 1;
  }
  else {
    if (param_2 != 2) {
      return 1;
    }
    hibernation = 0;
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 001009b8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_show_resume_dev_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001009e8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_show_resume_dev_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// of_iomap @ 00102010 size=1
// signature: undefined of_iomap(void)
// callers: [msm_show_resume_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register_prio @ 00102020 size=1
// signature: undefined tracepoint_probe_register_prio(void)
// callers: [msm_show_resume_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register_prio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_syscore_ops @ 00102030 size=1
// signature: undefined register_syscore_ops(void)
// callers: [msm_show_resume_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00102038 size=1
// signature: undefined register_pm_notifier(void)
// callers: [msm_show_resume_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00102048 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [msm_show_resume_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102050 size=1
// signature: undefined _printk(void)
// callers: [msm_show_resume_irqs, msm_show_resume_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00102058 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [msm_show_resume_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_syscore_ops @ 00102060 size=1
// signature: undefined unregister_syscore_ops(void)
// callers: [msm_show_resume_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00102068 size=1
// signature: undefined iounmap(void)
// callers: [msm_show_resume_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gic_v3_dist_init @ 00102088 size=1
// signature: undefined gic_v3_dist_init(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gic_v3_dist_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gic_v3_cpu_init @ 00102090 size=1
// signature: undefined gic_v3_cpu_init(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gic_v3_cpu_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gic_v3_dist_wait_for_rwp @ 00102098 size=1
// signature: undefined gic_v3_dist_wait_for_rwp(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gic_v3_dist_wait_for_rwp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 001020a0 size=1
// signature: undefined _find_first_bit(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 001020a8 size=1
// signature: undefined _find_next_bit(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001020b0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_show_resume_irqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 001020b8 size=1
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
// log_post_read_mmio @ 001020c0 size=1
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
// log_write_mmio @ 001020c8 size=1
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
// log_post_write_mmio @ 001020d0 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



