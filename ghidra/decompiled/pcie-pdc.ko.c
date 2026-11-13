// Decompiled by Ghidra 12.2
// Program: pcie-pdc.ko
// Image base: 00100000

//------------------------------------------------------------
// pcie_pdc_cfg_irq @ 00100144 size=304
// signature: undefined pcie_pdc_cfg_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 pcie_pdc_cfg_irq(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 uVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  
  if (d == (long *)0x0) {
    uVar5 = 0xffffffed;
  }
  else {
    if ((int)d[1] != 0) {
      iVar8 = 0;
      iVar7 = 0;
      do {
        if (*(int *)(*d + (long)iVar7 * 0xc) == param_1) {
          uVar3 = param_2 - 1;
          if ((7 < uVar3) || ((0x8fU >> (ulong)(uVar3 & 0x1f) & 1) == 0)) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1001d8);
            (*pcVar4)();
          }
          lVar6 = *d + (long)iVar7 * 0xc;
          uVar2 = *(undefined4 *)(lVar6 + 4);
          iVar7 = *(int *)(lVar6 + 8);
          uVar1 = (uint)*(undefined8 *)(&DAT_00100870 + (long)(int)uVar3 * 8) | 8;
          if ((param_3 & 1) == 0) {
            uVar2 = 0;
            uVar1 = (uint)*(undefined8 *)(&DAT_00100870 + (long)(int)uVar3 * 8);
          }
          uVar5 = _raw_spin_lock_irqsave(&pdc_lock);
          writel_relaxed(uVar2,pcie_pdc_base + iVar8 + 0x4900);
          writel_relaxed(uVar1,pcie_pdc_base + (ulong)(uint)(iVar7 << 2) + 0x110);
          _raw_spin_unlock_irqrestore(&pdc_lock,uVar5);
          return 0;
        }
        iVar7 = iVar7 + 1;
        iVar8 = iVar8 + 0x14;
      } while ((int)d[1] != iVar7);
    }
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// writel_relaxed @ 00100278 size=132
// signature: undefined writel_relaxed(void)
// callers: [pcie_pdc_cfg_irq]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100290,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1002cc,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_pcie_pdc_probe @ 00100300 size=96
// signature: undefined qcom_pcie_pdc_probe(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_pcie_pdc_probe(long param_1)

{
  undefined4 uVar1;
  
  pcie_pdc_base = devm_platform_ioremap_resource(param_1,0);
  if (pcie_pdc_base == 0) {
    uVar1 = 0xfffffffa;
  }
  else {
    d = of_device_get_match_data(param_1 + 0x10);
    uVar1 = 0xffffffea;
    if (d != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 00100394 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_pcie_pdc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001003c4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_pcie_pdc_driver);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00102000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [pcie_pdc_cfg_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00102008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [pcie_pdc_cfg_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102010 size=1
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
// platform_driver_unregister @ 00102018 size=1
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
// log_write_mmio @ 00102020 size=1
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
// log_post_write_mmio @ 00102028 size=1
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
// devm_platform_ioremap_resource @ 00102030 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [qcom_pcie_pdc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00102038 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_pcie_pdc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



