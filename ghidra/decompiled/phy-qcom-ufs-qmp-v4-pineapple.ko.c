// Decompiled by Ghidra 12.2
// Program: phy-qcom-ufs-qmp-v4-pineapple.ko
// Image base: 00100000

//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_probe @ 0010036c size=176
// signature: undefined ufs_qcom_phy_qmp_v4_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_qmp_v4_probe(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = devm_kmalloc(param_1 + 0x10,0x1b0,0xdc0);
  if (lVar1 == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    lVar2 = ufs_qcom_phy_generic_probe(param_1,lVar1,&ufs_qcom_phy_qmp_v4_phy_ops,phy_v4_ops);
    if (lVar2 == 0) {
      _dev_err(param_1 + 0x10,"%s: ufs_qcom_phy_generic_probe() failed\n",
               "ufs_qcom_phy_qmp_v4_probe");
      uVar3 = 0xfffffffb;
    }
    else {
      *(long *)(lVar2 + 0x98) = lVar1;
      strscpy(lVar1 + 0x156,"ufs_phy_qmp_v4_pineapple",0x19);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_init @ 00100420 size=128
// signature: undefined ufs_qcom_phy_qmp_v4_init(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_phy_qmp_v4_init(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  iVar1 = ufs_qcom_phy_init_clks(lVar4);
  if (iVar1 == 0) {
    iVar1 = ufs_qcom_phy_init_vregulators(lVar4);
    if (iVar1 == 0) {
      ufs_qcom_phy_get_reset(lVar4);
      return 0;
    }
    uVar2 = *(undefined8 *)(lVar4 + 0x10);
    pcVar3 = "%s: ufs_qcom_phy_init_vregulators() failed %d\n";
  }
  else {
    uVar2 = *(undefined8 *)(lVar4 + 0x10);
    pcVar3 = "%s: ufs_qcom_phy_init_clks() failed %d\n";
  }
  _dev_err(uVar2,pcVar3,"ufs_qcom_phy_qmp_v4_init",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_exit @ 001004a4 size=8
// signature: undefined ufs_qcom_phy_qmp_v4_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_qmp_v4_exit(void)

{
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_set_mode @ 001004b0 size=60
// signature: undefined ufs_qcom_phy_qmp_v4_set_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_qmp_v4_set_mode(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = get_ufs_qcom_phy();
  *(undefined4 *)(lVar1 + 400) = param_2;
  *(undefined4 *)(lVar1 + 0x194) = param_3;
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_phy_calibrate @ 001004f0 size=368
// signature: undefined ufs_qcom_phy_qmp_v4_phy_calibrate(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_phy_qmp_v4_phy_calibrate(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  char *pcVar5;
  undefined8 uVar6;
  
  lVar4 = get_ufs_qcom_phy();
  uVar6 = *(undefined8 *)(lVar4 + 0x10);
  iVar2 = reset_control_assert(*(undefined8 *)(lVar4 + 0x198));
  if (iVar2 == 0) {
    iVar2 = *(int *)(lVar4 + 0x194);
    if (iVar2 - 3U < 0xfffffffe) {
      _dev_err(uVar6,"%s: unsupported submode.\n","ufs_qcom_phy_qmp_v4_phy_calibrate");
      return -0x5f;
    }
    iVar1 = *(int *)(lVar4 + 400);
    writel_relaxed(1,*(long *)(lVar4 + 0x18) + 0x408);
    DataSynchronizationBarrier(3,2,0);
    ufs_qcom_phy_write_tbl(lVar4,phy_cal_table_rate_A_g5,0x6c);
    if (iVar2 == 1) {
      ufs_qcom_phy_write_tbl(lVar4,phy_cal_table_rate_A_g4,2);
    }
    if (*(int *)(lVar4 + 0x148) == 2) {
      ufs_qcom_phy_write_tbl(lVar4,&phy_cal_table_2nd_lane,1);
    }
    if (iVar1 == 0xd) {
      ufs_qcom_phy_write_tbl(lVar4,phy_cal_table_rate_B,2);
    }
    writel_relaxed(0,*(long *)(lVar4 + 0x18) + 0x408);
    DataSynchronizationBarrier(3,2,0);
    iVar2 = reset_control_deassert(*(undefined8 *)(lVar4 + 0x198));
    if (iVar2 == 0) {
      uVar3 = readl_relaxed(*(long *)(lVar4 + 0x18) + 0x400);
      writel_relaxed(uVar3 | 1,*(long *)(lVar4 + 0x18) + 0x400);
      DataSynchronizationBarrier(3,3,0);
      iVar2 = ufs_qcom_phy_qmp_v4_is_pcs_ready(lVar4);
      return iVar2;
    }
    pcVar5 = "Failed to deassert UFS PHY reset %d\n";
  }
  else {
    pcVar5 = "Failed to assert UFS PHY reset %d\n";
  }
  _dev_err(uVar6,pcVar5,iVar2);
  return iVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00100660 size=132
// signature: undefined writel_relaxed(void)
// callers: [ufs_qcom_phy_qmp_v4_power_control, ufs_qcom_phy_qmp_v4_phy_calibrate, ufs_qcom_phy_qmp_v4_start_serdes, ufs_qcom_phy_qmp_v4_ctrl_rx_linecfg]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100678,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1006b4,uVar1);
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_start_serdes @ 001006e8 size=68
// signature: undefined ufs_qcom_phy_qmp_v4_start_serdes(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qmp_v4_start_serdes(long param_1)

{
  uint uVar1;
  
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0x400);
  writel_relaxed(uVar1 | 1,*(long *)(param_1 + 0x18) + 0x400);
  DataSynchronizationBarrier(3,3,0);
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_is_pcs_ready @ 00100730 size=188
// signature: undefined ufs_qcom_phy_qmp_v4_is_pcs_ready(void)
// callers: [ufs_qcom_phy_qmp_v4_phy_calibrate]
//------------------------------------------------------------

undefined4 ufs_qcom_phy_qmp_v4_is_pcs_ready(long param_1)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  undefined4 uVar4;
  
  lVar1 = ktime_get();
  uVar2 = readl(*(long *)(param_1 + 0x18) + 0x5a8);
  if ((uVar2 & 1) == 0) {
    do {
      lVar3 = ktime_get();
      if (lVar1 + 1000000000 < lVar3) {
        uVar2 = readl(*(long *)(param_1 + 0x18) + 0x5a8);
        break;
      }
      usleep_range_state(3,10,2);
      Yield();
      uVar2 = readl(*(long *)(param_1 + 0x18) + 0x5a8);
    } while ((uVar2 & 1) == 0);
  }
  uVar4 = 0xffffff92;
  if ((uVar2 & 1) != 0) {
    uVar4 = 0;
  }
  if ((uVar2 & 1) == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x10),"%s: poll for pcs failed err = %d\n",
             "ufs_qcom_phy_qmp_v4_is_pcs_ready",uVar4);
  }
  return uVar4;
}



//------------------------------------------------------------
// readl_relaxed @ 001007ec size=124
// signature: undefined readl_relaxed(void)
// callers: [ufs_qcom_phy_qmp_v4_power_control, ufs_qcom_phy_qmp_v4_phy_calibrate, ufs_qcom_phy_qmp_v4_start_serdes, ufs_qcom_phy_qmp_v4_ctrl_rx_linecfg]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100834,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readl @ 00100868 size=140
// signature: undefined readl(void)
// callers: [ufs_qcom_phy_qmp_v4_is_pcs_ready]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1008c0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_set_tx_lane_enable @ 001008f8 size=4
// signature: undefined ufs_qcom_phy_qmp_v4_set_tx_lane_enable(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qmp_v4_set_tx_lane_enable(void)

{
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_power_control @ 00100900 size=240
// signature: undefined ufs_qcom_phy_qmp_v4_power_control(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qmp_v4_power_control(long param_1,ulong param_2)

{
  uint uVar1;
  
  if ((param_2 & 1) == 0) {
    writel_relaxed(0,*(long *)(param_1 + 0x18) + 0x404);
    DataSynchronizationBarrier(3,3,0);
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0x13e0);
    writel_relaxed(uVar1 | 0x40,*(long *)(param_1 + 0x18) + 0x13e0);
    if (*(int *)(param_1 + 0x148) != 1) {
      uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0x1be0);
      writel_relaxed(uVar1 | 0x40,*(long *)(param_1 + 0x18) + 0x1be0);
    }
    DataSynchronizationBarrier(3,3,0);
  }
  else {
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0x13e0);
    writel_relaxed(uVar1 & 0xffffffbf,*(long *)(param_1 + 0x18) + 0x13e0);
    if (*(int *)(param_1 + 0x148) != 1) {
      uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0x1be0);
      writel_relaxed(uVar1 & 0xffffffbf,*(long *)(param_1 + 0x18) + 0x1be0);
    }
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(1,*(long *)(param_1 + 0x18) + 0x404);
    DataSynchronizationBarrier(3,3,0);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_ctrl_rx_linecfg @ 001009f4 size=88
// signature: undefined ufs_qcom_phy_qmp_v4_ctrl_rx_linecfg(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qmp_v4_ctrl_rx_linecfg(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0x57c);
  uVar2 = 0;
  if ((param_2 & 1) == 0) {
    uVar2 = 2;
  }
  writel_relaxed(uVar1 & 0xfffffffd | uVar2,*(long *)(param_1 + 0x18) + 0x57c);
  DataSynchronizationBarrier(3,3,0);
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_get_tx_hs_equalizer @ 00100a50 size=16
// signature: undefined ufs_qcom_phy_qmp_v4_get_tx_hs_equalizer(void)
// callers: []
//------------------------------------------------------------

long ufs_qcom_phy_qmp_v4_get_tx_hs_equalizer(undefined8 param_1,int param_2)

{
  return (ulong)(param_2 == 5) << 2;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_dbg_register_dump @ 00100a64 size=200
// signature: undefined ufs_qcom_phy_qmp_v4_dbg_register_dump(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qmp_v4_dbg_register_dump(undefined8 param_1)

{
  ufs_qcom_phy_dump_regs(param_1,0,0x2000,"PHY QSERDES COM Registers ");
  ufs_qcom_phy_dump_regs(param_1,0x800,0x6c,"PHY PCS2 Registers ");
  ufs_qcom_phy_dump_regs(param_1,0x400,600,"PHY Registers ");
  ufs_qcom_phy_dump_regs(param_1,0x1200,0x3d8,"PHY RX0 Registers ");
  ufs_qcom_phy_dump_regs(param_1,0x1000,0x134,"PHY TX0 Registers ");
  ufs_qcom_phy_dump_regs(param_1,0x1a00,0x3d8,"PHY RX1 Registers ");
  ufs_qcom_phy_dump_regs(param_1,0x1800,0x134,"PHY TX1 Registers ");
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qmp_v4_dbg_register_save @ 00100b30 size=200
// signature: undefined ufs_qcom_phy_qmp_v4_dbg_register_save(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qmp_v4_dbg_register_save(undefined8 param_1)

{
  ufs_qcom_phy_save_regs(param_1,0,0x2000,"PHY QSERDES COM Registers ");
  ufs_qcom_phy_save_regs(param_1,0x800,0x6c,"PHY PCS2 Registers ");
  ufs_qcom_phy_save_regs(param_1,0x400,600,"PHY Registers ");
  ufs_qcom_phy_save_regs(param_1,0x1200,0x3d8,"PHY RX0 Registers ");
  ufs_qcom_phy_save_regs(param_1,0x1000,0x134,"PHY TX0 Registers ");
  ufs_qcom_phy_save_regs(param_1,0x1a00,0x3d8,"PHY RX1 Registers ");
  ufs_qcom_phy_save_regs(param_1,0x1800,0x134,"PHY TX1 Registers ");
  return;
}



//------------------------------------------------------------
// init_module @ 00100c04 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ufs_qcom_phy_qmp_v4_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100c34 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ufs_qcom_phy_qmp_v4_driver);
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
// platform_driver_unregister @ 00103008 size=1
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ufs_qcom_phy_qmp_v4_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_generic_probe @ 00103018 size=1
// signature: undefined ufs_qcom_phy_generic_probe(void)
// callers: [ufs_qcom_phy_qmp_v4_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_generic_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103020 size=1
// signature: undefined strscpy(void)
// callers: [ufs_qcom_phy_qmp_v4_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103028 size=1
// signature: undefined _dev_err(void)
// callers: [ufs_qcom_phy_qmp_v4_phy_calibrate, ufs_qcom_phy_qmp_v4_is_pcs_ready, ufs_qcom_phy_qmp_v4_init, ufs_qcom_phy_qmp_v4_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_init_clks @ 00103030 size=1
// signature: undefined ufs_qcom_phy_init_clks(void)
// callers: [ufs_qcom_phy_qmp_v4_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_init_clks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_init_vregulators @ 00103038 size=1
// signature: undefined ufs_qcom_phy_init_vregulators(void)
// callers: [ufs_qcom_phy_qmp_v4_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_init_vregulators(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_get_reset @ 00103040 size=1
// signature: undefined ufs_qcom_phy_get_reset(void)
// callers: [ufs_qcom_phy_qmp_v4_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_get_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_ufs_qcom_phy @ 00103048 size=1
// signature: undefined get_ufs_qcom_phy(void)
// callers: [ufs_qcom_phy_qmp_v4_phy_calibrate, ufs_qcom_phy_qmp_v4_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_ufs_qcom_phy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 00103050 size=1
// signature: undefined reset_control_assert(void)
// callers: [ufs_qcom_phy_qmp_v4_phy_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_write_tbl @ 00103058 size=1
// signature: undefined ufs_qcom_phy_write_tbl(void)
// callers: [ufs_qcom_phy_qmp_v4_phy_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_write_tbl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 00103060 size=1
// signature: undefined reset_control_deassert(void)
// callers: [ufs_qcom_phy_qmp_v4_phy_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00103068 size=1
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
// log_post_write_mmio @ 00103070 size=1
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
// ktime_get @ 00103078 size=1
// signature: undefined ktime_get(void)
// callers: [ufs_qcom_phy_qmp_v4_is_pcs_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00103080 size=1
// signature: undefined usleep_range_state(void)
// callers: [ufs_qcom_phy_qmp_v4_is_pcs_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00103088 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00103090 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_dump_regs @ 00103098 size=1
// signature: undefined ufs_qcom_phy_dump_regs(void)
// callers: [ufs_qcom_phy_qmp_v4_dbg_register_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_dump_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_save_regs @ 001030a0 size=1
// signature: undefined ufs_qcom_phy_save_regs(void)
// callers: [ufs_qcom_phy_qmp_v4_dbg_register_save]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_save_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



