// Decompiled by Ghidra 12.2
// Program: phy-qcom-emu.ko
// Image base: 00100000

//------------------------------------------------------------
// qcusb_emu_phy_probe @ 00100194 size=464
// signature: undefined qcusb_emu_phy_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcusb_emu_phy_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  ulong uVar9;
  char *pcVar10;
  uint local_3c;
  long local_38;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar6 + 0x638);
  local_3c = 0;
  plVar3 = (long *)devm_kmalloc(lVar1,0x1b0,0xdc0);
  if (plVar3 == (long *)0x0) {
LAB_001002e4:
    uVar5 = 0xfffffff4;
  }
  else {
    *plVar3 = lVar1;
    uVar4 = platform_get_resource(param_1,0x200,0);
    uVar5 = devm_ioremap_resource(lVar1,uVar4);
    plVar3[0x32] = uVar5;
    if (0xfffffffffffff000 < uVar5) goto LAB_001002e8;
    of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,emu-init-seq",&local_3c);
    if (local_3c == 0) {
      pcVar10 = "emu-init-seq not specified\n";
    }
    else {
      lVar6 = devm_kmalloc(lVar1,(long)(int)local_3c,0xdc0);
      plVar3[0x34] = lVar6;
      if (lVar6 == 0) goto LAB_001002e4;
      *(int *)(plVar3 + 0x35) = (int)local_3c >> 2;
      if ((local_3c >> 2 & 1) == 0) {
        uVar2 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,emu-init-seq",lVar6,
                           (long)((int)local_3c >> 2),0);
        if ((int)uVar2 < 0) {
          uVar5 = (ulong)uVar2;
          _dev_err(lVar1,"could not read emu-init-seq, returned %d\n",uVar5);
        }
        else {
          *(long **)(param_1 + 0xa8) = plVar3;
          plVar3[1] = (long)"qcom-usb-emu-phy";
          plVar3[0x23] = (long)qcusb_emu_phy_init;
          *(undefined4 *)((long)plVar3 + 0x14) = 1;
          uVar7 = usb_add_phy_dev(plVar3);
          uVar5 = uVar7 & 0xffffffff;
          if ((int)uVar7 == 0) {
            plVar8 = (long *)platform_get_resource_byname(param_1,0x200,"qscratch_base");
            if (plVar8 == (long *)0x0) {
              uVar5 = 0;
            }
            else {
              uVar9 = devm_ioremap(lVar1,*plVar8,(plVar8[1] - *plVar8) + 1);
              uVar5 = 0;
              uVar7 = 0;
              if (uVar9 < 0xfffffffffffff001) {
                uVar7 = uVar9;
              }
              plVar3[0x33] = uVar7;
            }
          }
        }
        goto LAB_001002e8;
      }
      pcVar10 = "invalid emu_init_seq_len, must be in <data,addr> pairs\n";
    }
    _dev_err(lVar1,pcVar10);
    uVar5 = 0xffffffea;
  }
LAB_001002e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// qcusb_emu_phy_remove @ 00100368 size=36
// signature: undefined qcusb_emu_phy_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcusb_emu_phy_remove(long param_1)

{
  usb_remove_phy(*(undefined8 *)(param_1 + 0xa8));
  return 0;
}



//------------------------------------------------------------
// qcusb_emu_phy_init @ 00100390 size=444
// signature: undefined qcusb_emu_phy_init(void)
// callers: []
//------------------------------------------------------------

undefined8 qcusb_emu_phy_init(undefined8 *param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  undefined8 uVar4;
  
  writel_relaxed(0xffffffff,param_1[0x32] + 4);
  usleep_range_state(10000,12000,2);
  uVar1 = readl_relaxed(param_1[0x32] + 0x34);
  writel_relaxed(uVar1 | 0x2000000,param_1[0x32] + 0x34);
  usleep_range_state(10000,12000,2);
  uVar1 = readl_relaxed(param_1[0x32] + 0x34);
  writel_relaxed(uVar1 & 0xfdffffff,param_1[0x32] + 0x34);
  usleep_range_state(10000,12000,2);
  writel_relaxed(0xfffffff3,param_1[0x32] + 4);
  usleep_range_state(10000,12000,2);
  writel_relaxed(0xfffffff0,param_1[0x32] + 4);
  usleep_range_state(10000,12000,2);
  if (0 < *(int *)(param_1 + 0x35)) {
    iVar3 = 0;
    do {
      writel_relaxed(*(undefined4 *)(param_1[0x34] + (long)iVar3 * 4),
                     param_1[0x32] + (long)*(int *)(param_1[0x34] + (long)(iVar3 + 1) * 4));
      usleep_range_state(10000,12000,2);
      iVar3 = iVar3 + 2;
    } while (iVar3 < *(int *)(param_1 + 0x35));
  }
  writel_relaxed(0,param_1[0x32] + 4);
  usleep_range_state(10000,12000,2);
  writel_relaxed(9,param_1[0x32] + 0x14);
  usleep_range_state(10000,12000,2);
  uVar4 = *param_1;
  uVar2 = readl_relaxed(param_1[0x32] + 0x10);
  _dev_info(uVar4,"PHY UTMI/ULPI CLK frequency:%d MHz\n",(uVar2 & 0xffffffff) / 1000);
  if (param_1[0x33] != 0) {
    uVar1 = readl_relaxed(param_1[0x33] + 0x10);
    writel_relaxed(uVar1 & 0xefffffff,param_1[0x33] + 0x10);
  }
  return 0;
}



//------------------------------------------------------------
// writel_relaxed @ 0010054c size=132
// signature: undefined writel_relaxed(void)
// callers: [qcusb_emu_phy_init]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100564,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1005a0,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001005d0 size=124
// signature: undefined readl_relaxed(void)
// callers: [qcusb_emu_phy_init]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100618,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100654 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcusb_emu_phy_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100684 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcusb_emu_phy_driver);
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00102018 size=1
// signature: undefined platform_get_resource(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00102020 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00102028 size=1
// signature: undefined of_get_property(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102030 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_phy_dev @ 00102038 size=1
// signature: undefined usb_add_phy_dev(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_phy_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00102040 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00102048 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102050 size=1
// signature: undefined _dev_err(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcusb_emu_phy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_phy @ 00102060 size=1
// signature: undefined usb_remove_phy(void)
// callers: [qcusb_emu_phy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_phy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00102068 size=1
// signature: undefined usleep_range_state(void)
// callers: [qcusb_emu_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102070 size=1
// signature: undefined _dev_info(void)
// callers: [qcusb_emu_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00102078 size=1
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
// log_post_write_mmio @ 00102080 size=1
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
// log_read_mmio @ 00102088 size=1
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
// log_post_read_mmio @ 00102090 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



