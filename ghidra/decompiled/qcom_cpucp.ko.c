// Decompiled by Ghidra 12.2
// Program: qcom_cpucp.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_cpucp_probe @ 0010020c size=480
// signature: undefined qcom_cpucp_probe(void)
// callers: []
//------------------------------------------------------------

int qcom_cpucp_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  char *pcVar6;
  undefined4 uVar7;
  
  lVar1 = param_1 + 0x10;
  plVar3 = (long *)devm_kmalloc(lVar1,0x398,0xdc0);
  if (plVar3 != (long *)0x0) {
    plVar3[0x71] = lVar1;
    plVar4 = (long *)platform_get_resource(param_1,0x200,0);
    if (plVar4 == (long *)0x0) {
LAB_0010034c:
      _dev_err(lVar1,"Failed to get the device base address\n");
      return -0x13;
    }
    lVar5 = devm_ioremap(lVar1,*plVar4,(plVar4[1] - *plVar4) + 1);
    plVar3[0x6f] = lVar5;
    if (lVar5 == 0) {
      pcVar6 = "Failed to ioremap cpucp tx irq addr\n";
    }
    else {
      plVar4 = (long *)platform_get_resource(param_1,0x200,1);
      if (plVar4 == (long *)0x0) goto LAB_0010034c;
      lVar5 = devm_ioremap(lVar1,*plVar4,(plVar4[1] - *plVar4) + 1);
      plVar3[0x70] = lVar5;
      if (lVar5 != 0) {
        uVar7 = (undefined4)((plVar4[1] - *plVar4) + 1U >> 0xc);
        *(undefined4 *)((long)plVar3 + 0x394) = uVar7;
        iVar2 = platform_get_irq(param_1,0);
        *(int *)(plVar3 + 0x72) = iVar2;
        if (iVar2 < 0) {
          pcVar6 = "Failed to get the IRQ\n";
        }
        else {
          plVar3[0x30] = 0;
          plVar3[0x4f] = 0;
          plVar3[1] = (long)&cpucp_mbox_chan_ops;
          plVar3[2] = (long)(plVar3 + 0x12);
          plVar3[0x6e] = 0;
          *(undefined4 *)(plVar3 + 3) = uVar7;
          *plVar3 = lVar1;
          plVar3[5] = (long)qcom_cpucp_mbox_xlate;
          *(undefined2 *)((long)plVar3 + 0x1c) = 0;
          iVar2 = mbox_controller_register(plVar3);
          if (iVar2 == 0) {
            iVar2 = devm_request_threaded_irq
                              (lVar1,(int)plVar3[0x72],qcom_cpucp_rx_interrupt,0,0x4004,"qcom_cpucp"
                               ,plVar3);
            if (iVar2 < 0) {
              _dev_err(lVar1,"Failed to register the irq: %d\n",iVar2);
              mbox_controller_unregister(plVar3);
              return iVar2;
            }
            *(long **)(param_1 + 0xa8) = plVar3;
            return 0;
          }
          pcVar6 = "Failed to create mailbox\n";
        }
        _dev_err(lVar1,pcVar6);
        return iVar2;
      }
      pcVar6 = "Failed to ioremap cpucp rx irq addr\n";
    }
    _dev_err(lVar1,pcVar6);
  }
  return -0xc;
}



//------------------------------------------------------------
// qcom_cpucp_remove @ 001003f0 size=36
// signature: undefined qcom_cpucp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpucp_remove(long param_1)

{
  mbox_controller_unregister(*(undefined8 *)(param_1 + 0xa8));
  return 0;
}



//------------------------------------------------------------
// qcom_cpucp_rx_interrupt @ 00100418 size=444
// signature: undefined qcom_cpucp_rx_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpucp_rx_interrupt(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  
  if (0 < *(int *)(param_2 + 0x394)) {
    uVar2 = readl(*(long *)(param_2 + 0x380) + 0x30c);
    if ((uVar2 >> 3 & 1) != 0) {
      writel(8,*(long *)(param_2 + 0x380) + 0x308);
      DataSynchronizationBarrier(3,3,0);
      uVar3 = _raw_spin_lock_irqsave(param_2 + 0x178);
      if (*(long *)(param_2 + 0x180) != 0) {
        mbox_chan_received_data(param_2 + 0x90,0);
      }
      _raw_spin_unlock_irqrestore(param_2 + 0x178,uVar3);
    }
    if (1 < *(int *)(param_2 + 0x394)) {
      uVar2 = readl(*(long *)(param_2 + 0x380) + 0x130c);
      if ((uVar2 >> 3 & 1) != 0) {
        writel(8,*(long *)(param_2 + 0x380) + 0x1308);
        DataSynchronizationBarrier(3,3,0);
        uVar3 = _raw_spin_lock_irqsave(param_2 + 0x270);
        if (*(long *)(param_2 + 0x278) != 0) {
          mbox_chan_received_data(param_2 + 0x188,0);
        }
        _raw_spin_unlock_irqrestore(param_2 + 0x270,uVar3);
      }
      if (2 < *(int *)(param_2 + 0x394)) {
        uVar2 = readl(*(long *)(param_2 + 0x380) + 0x230c);
        if ((uVar2 >> 3 & 1) != 0) {
          writel(8,*(long *)(param_2 + 0x380) + 0x2308);
          DataSynchronizationBarrier(3,3,0);
          uVar3 = _raw_spin_lock_irqsave(param_2 + 0x368);
          if (*(long *)(param_2 + 0x370) != 0) {
            mbox_chan_received_data(param_2 + 0x280,0);
          }
          _raw_spin_unlock_irqrestore(param_2 + 0x368,uVar3);
        }
        if (3 < *(int *)(param_2 + 0x394)) {
          iVar4 = 0x3000;
          lVar5 = 3;
          do {
            uVar2 = readl(*(long *)(param_2 + 0x380) + (long)iVar4 + 0x30c);
            if ((uVar2 >> 3 & 1) != 0) {
              writel(8,*(long *)(param_2 + 0x380) + (long)iVar4 + 0x308);
              DataSynchronizationBarrier(3,3,0);
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1005d4);
              (*pcVar1)();
            }
            lVar5 = lVar5 + 1;
            iVar4 = iVar4 + 0x1000;
          } while (lVar5 < *(int *)(param_2 + 0x394));
        }
      }
    }
  }
  return 1;
}



//------------------------------------------------------------
// qcom_cpucp_mbox_xlate @ 001005d8 size=84
// signature: undefined qcom_cpucp_mbox_xlate(void)
// callers: []
//------------------------------------------------------------

long qcom_cpucp_mbox_xlate(long param_1,long param_2)

{
  ulong uVar1;
  long *plVar2;
  
  if ((*(int *)(param_2 + 8) != 1) ||
     (uVar1 = (ulong)*(uint *)(param_2 + 0xc), (ulong)(long)*(int *)(param_1 + 0x18) <= uVar1)) {
    return -0x16;
  }
  plVar2 = (long *)(*(long *)(param_1 + 0x10) + uVar1 * 0xf8 + 0xf0);
  if (*plVar2 == 0) {
    *plVar2 = param_1;
    return *(long *)(param_1 + 0x10) + uVar1 * 0xf8;
  }
  return -0x10;
}



//------------------------------------------------------------
// qcom_cpucp_mbox_send_data @ 00100630 size=48
// signature: undefined qcom_cpucp_mbox_send_data(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_cpucp_mbox_send_data(long *param_1)

{
  writel(0x10000000,*(long *)(*param_1 + 0x378) + 0xc);
  return 0;
}



//------------------------------------------------------------
// qcom_cpucp_mbox_shutdown @ 00100664 size=64
// signature: undefined qcom_cpucp_mbox_shutdown(void)
// callers: []
//------------------------------------------------------------

void qcom_cpucp_mbox_shutdown(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0xe8);
  *(undefined8 *)(param_1 + 0xf0) = 0;
  _raw_spin_unlock_irqrestore(param_1 + 0xe8,uVar1);
  return;
}



//------------------------------------------------------------
// writel @ 001006a4 size=136
// signature: undefined writel(void)
// callers: [qcom_cpucp_mbox_send_data, qcom_cpucp_rx_interrupt]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1006bc,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1006fc,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 0010072c size=140
// signature: undefined readl(void)
// callers: [qcom_cpucp_rx_interrupt]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100784,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 001007c0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_cpucp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001007f0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_cpucp_driver);
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
// callers: [qcom_cpucp_probe]
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
// callers: [qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00102020 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00102028 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_controller_register @ 00102030 size=1
// signature: undefined mbox_controller_register(void)
// callers: [qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00102038 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_controller_unregister @ 00102048 size=1
// signature: undefined mbox_controller_unregister(void)
// callers: [qcom_cpucp_remove, qcom_cpucp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_controller_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00102050 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_cpucp_mbox_shutdown, qcom_cpucp_rx_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_chan_received_data @ 00102058 size=1
// signature: undefined mbox_chan_received_data(void)
// callers: [qcom_cpucp_rx_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_chan_received_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00102060 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_cpucp_mbox_shutdown, qcom_cpucp_rx_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00102068 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00102070 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00102078 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00102080 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



