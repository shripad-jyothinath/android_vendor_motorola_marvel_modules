// Decompiled by Ghidra 12.2
// Program: qcom_cpu_vendor_hooks.ko
// Image base: 00100000

//------------------------------------------------------------
// cpu_vendor_hooks_driver_probe @ 0010017c size=408
// signature: undefined cpu_vendor_hooks_driver_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cpu_vendor_hooks_driver_probe(long param_1)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  code *pcVar5;
  
  lVar2 = of_find_compatible_node(0,0,"qcom,msm-imem-kaslr_offset");
  if (lVar2 == 0) {
    puVar4 = &DAT_00100977;
  }
  else {
    puVar3 = (undefined4 *)of_iomap(lVar2,0);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0xdead4ead;
      puVar3[1] = _kimage_vaddr + -0x8000000;
      puVar3[2] = (int)((ulong)(CONCAT44(uRam0000000000102024,_kimage_vaddr) + 0x3ff8000000) >> 0x20
                       );
      iounmap();
      goto LAB_001001f4;
    }
    puVar4 = &DAT_001009e6;
  }
  _printk(puVar4,"qcom,msm-imem-kaslr_offset");
LAB_001001f4:
  register_syscore_ops(kaslr_offset_restore_syscore_ops);
  iVar1 = tracepoint_probe_register(&__tracepoint_android_vh_ipi_stop,trace_ipi_stop,0);
  if (iVar1 == 0) {
    iVar1 = tracepoint_probe_register(&__tracepoint_android_vh_printk_hotplug,printk_hotplug,0);
    if (iVar1 == 0) {
      iVar1 = tracepoint_probe_register
                        (&__tracepoint_android_vh_timer_calc_index,timer_recalc_index,0);
      if (iVar1 == 0) {
        return 0;
      }
      _dev_err(param_1 + 0x10,"Failed to android_vh_timer_calc_index hook\n");
      tracepoint_probe_unregister(&__tracepoint_android_vh_ipi_stop,trace_ipi_stop,0);
      puVar4 = &__tracepoint_android_vh_printk_hotplug;
      pcVar5 = printk_hotplug;
    }
    else {
      _dev_err(param_1 + 0x10,"Failed to android_vh_printk_hotplug hook\n");
      puVar4 = &__tracepoint_android_vh_ipi_stop;
      pcVar5 = trace_ipi_stop;
    }
    tracepoint_probe_unregister(puVar4,pcVar5,0);
  }
  else {
    _dev_err(param_1 + 0x10,"Failed to register android_vh_ipi_stop hook\n");
  }
  return iVar1;
}



//------------------------------------------------------------
// cpu_vendor_hooks_driver_remove @ 00100318 size=100
// signature: undefined cpu_vendor_hooks_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 cpu_vendor_hooks_driver_remove(void)

{
  tracepoint_probe_unregister(&__tracepoint_android_vh_ipi_stop,trace_ipi_stop,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_printk_hotplug,printk_hotplug,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_timer_calc_index,timer_recalc_index,0);
  return 0;
}



//------------------------------------------------------------
// store_kaslr_offset @ 00100380 size=160
// signature: undefined store_kaslr_offset(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void store_kaslr_offset(void)

{
  long lVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  lVar1 = of_find_compatible_node(0,0,"qcom,msm-imem-kaslr_offset");
  if (lVar1 == 0) {
    puVar3 = &DAT_00100977;
  }
  else {
    puVar2 = (undefined4 *)of_iomap(lVar1,0);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 0xdead4ead;
      puVar2[1] = _kimage_vaddr + -0x8000000;
      puVar2[2] = (int)((ulong)(CONCAT44(uRam0000000000102024,_kimage_vaddr) + 0x3ff8000000) >> 0x20
                       );
      iounmap();
      return;
    }
    puVar3 = &DAT_001009e6;
  }
  _printk(puVar3,"qcom,msm-imem-kaslr_offset");
  return;
}



//------------------------------------------------------------
// trace_ipi_stop @ 00100424 size=160
// signature: undefined trace_ipi_stop(void)
// callers: []
//------------------------------------------------------------

void trace_ipi_stop(undefined8 param_1,void *param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  
  lVar2 = tpidr_el1;
  uVar1 = *(uint *)(&cpu_number + lVar2);
  if (0x1f < uVar1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1004c4);
    (*pcVar3)();
  }
  memcpy(&regs_before_stop + *(long *)(&__per_cpu_offset + (ulong)uVar1 * 8),param_2,0x150);
  uVar4 = _raw_spin_lock_irqsave(&stop_lock);
  _printk(&DAT_0010093c,uVar1);
  show_regs(param_2);
  _raw_spin_unlock_irqrestore(&stop_lock,uVar4);
  return;
}



//------------------------------------------------------------
// printk_hotplug @ 001004c8 size=12
// signature: undefined printk_hotplug(void)
// callers: []
//------------------------------------------------------------

void printk_hotplug(undefined8 param_1,undefined4 *param_2)

{
  *param_2 = 1;
  return;
}



//------------------------------------------------------------
// timer_recalc_index @ 001004d8 size=16
// signature: undefined timer_recalc_index(void)
// callers: []
//------------------------------------------------------------

void timer_recalc_index(undefined8 param_1,undefined8 param_2,long *param_3)

{
  *param_3 = *param_3 + -1;
  return;
}



//------------------------------------------------------------
// init_module @ 001004f0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cpu_vendor_hooks_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100520 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cpu_vendor_hooks_driver);
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
// of_find_compatible_node @ 00102010 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [store_kaslr_offset, cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 00102018 size=1
// signature: undefined of_iomap(void)
// callers: [store_kaslr_offset, cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 00102028 size=1
// signature: undefined iounmap(void)
// callers: [store_kaslr_offset, cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_syscore_ops @ 00102030 size=1
// signature: undefined register_syscore_ops(void)
// callers: [cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_syscore_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00102040 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102058 size=1
// signature: undefined _dev_err(void)
// callers: [cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102060 size=1
// signature: undefined _printk(void)
// callers: [store_kaslr_offset, cpu_vendor_hooks_driver_probe, trace_ipi_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00102068 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cpu_vendor_hooks_driver_remove, cpu_vendor_hooks_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00102080 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [trace_ipi_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00102088 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [trace_ipi_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// show_regs @ 00102090 size=1
// signature: undefined show_regs(void)
// callers: [trace_ipi_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void show_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00102098 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [trace_ipi_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



