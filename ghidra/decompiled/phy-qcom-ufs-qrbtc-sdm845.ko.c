// Decompiled by Ghidra 12.2
// Program: phy-qcom-ufs-qrbtc-sdm845.ko
// Image base: 00100000

//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_probe @ 0010027c size=176
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_qrbtc_sdm845_probe(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar1 = devm_kmalloc(param_1 + 0x10,0x1b0,0xdc0);
  if (lVar1 == 0) {
    uVar3 = 0xfffffff4;
  }
  else {
    lVar2 = ufs_qcom_phy_generic_probe
                      (param_1,lVar1,&ufs_qcom_phy_qrbtc_sdm845_phy_ops,phy_qrbtc_sdm845_ops);
    if (lVar2 == 0) {
      _dev_err(param_1 + 0x10,"%s: ufs_qcom_phy_generic_probe() failed\n",
               "ufs_qcom_phy_qrbtc_sdm845_probe");
      uVar3 = 0xfffffffb;
    }
    else {
      *(long *)(lVar2 + 0x98) = lVar1;
      strscpy(lVar1 + 0x156,"ufs_phy_qrbtc_sdm845",0x15);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_init @ 00100330 size=80
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_init(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_phy_qrbtc_sdm845_init(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = get_ufs_qcom_phy();
  iVar1 = ufs_qcom_phy_get_reset();
  if (iVar1 != 0) {
    _dev_err(*(undefined8 *)(lVar2 + 0x10),"Failed to get reset control %d\n",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_exit @ 00100384 size=8
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_qrbtc_sdm845_exit(void)

{
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_set_mode @ 00100390 size=60
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_set_mode(void)
// callers: []
//------------------------------------------------------------

undefined8
ufs_qcom_phy_qrbtc_sdm845_set_mode(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = get_ufs_qcom_phy();
  *(undefined4 *)(lVar1 + 400) = param_2;
  *(undefined4 *)(lVar1 + 0x194) = param_3;
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_phy_calibrate @ 001003d0 size=124
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_phy_calibrate(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_phy_qrbtc_sdm845_phy_calibrate(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = get_ufs_qcom_phy();
  iVar1 = ufs_qcom_phy_calibrate
                    (lVar2,phy_cal_table_rate_A,0x35,phy_cal_table_rate_B,0xd,
                     *(int *)(lVar2 + 400) == 0xd);
  if (iVar1 != 0) {
    _dev_err(*(undefined8 *)(lVar2 + 0x10),"%s: ufs_qcom_phy_calibrate() failed %d\n",
             "ufs_qcom_phy_qrbtc_sdm845_phy_calibrate",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_start_serdes @ 00100450 size=84
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_start_serdes(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_phy_qrbtc_sdm845_start_serdes(long param_1)

{
  uint uVar1;
  
  writel_relaxed(1,*(long *)(param_1 + 0x18) + 0xc04);
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) + 0xc00);
  writel_relaxed(uVar1 | 1,*(long *)(param_1 + 0x18) + 0xc00);
  DataSynchronizationBarrier(3,3,0);
  return;
}



//------------------------------------------------------------
// ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready @ 001004a8 size=196
// signature: undefined ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = ktime_get();
  iVar1 = readl(*(long *)(param_1 + 0x18) + 0xbc);
  if (iVar1 != 0x3d) {
    do {
      lVar3 = ktime_get();
      if (lVar2 + 1000000000 < lVar3) {
        iVar1 = readl(*(long *)(param_1 + 0x18) + 0xbc);
        if (iVar1 == 0x3d) {
          return 0;
        }
        _dev_err(*(undefined8 *)(param_1 + 0x10),"%s: poll for pcs failed err = %d\n",
                 "ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready",0xffffff92);
        return 0xffffff92;
      }
      usleep_range_state(3,10,2);
      Yield();
      iVar1 = readl(*(long *)(param_1 + 0x18) + 0xbc);
    } while (iVar1 != 0x3d);
  }
  return 0;
}



//------------------------------------------------------------
// writel_relaxed @ 0010056c size=132
// signature: undefined writel_relaxed(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_start_serdes]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100584,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1005c0,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001005f0 size=124
// signature: undefined readl_relaxed(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_start_serdes]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100638,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readl @ 0010066c size=140
// signature: undefined readl(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1006c4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100704 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ufs_qcom_phy_qrbtc_sdm845_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100734 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ufs_qcom_phy_qrbtc_sdm845_driver);
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
// callers: [ufs_qcom_phy_qrbtc_sdm845_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_generic_probe @ 00102018 size=1
// signature: undefined ufs_qcom_phy_generic_probe(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_generic_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00102020 size=1
// signature: undefined strscpy(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102028 size=1
// signature: undefined _dev_err(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_probe, ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready, ufs_qcom_phy_qrbtc_sdm845_phy_calibrate, ufs_qcom_phy_qrbtc_sdm845_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_ufs_qcom_phy @ 00102030 size=1
// signature: undefined get_ufs_qcom_phy(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_set_mode, ufs_qcom_phy_qrbtc_sdm845_phy_calibrate, ufs_qcom_phy_qrbtc_sdm845_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_ufs_qcom_phy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_get_reset @ 00102038 size=1
// signature: undefined ufs_qcom_phy_get_reset(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_get_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_calibrate @ 00102040 size=1
// signature: undefined ufs_qcom_phy_calibrate(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_phy_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_calibrate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00102048 size=1
// signature: undefined ktime_get(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00102050 size=1
// signature: undefined usleep_range_state(void)
// callers: [ufs_qcom_phy_qrbtc_sdm845_is_pcs_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00102058 size=1
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
// log_post_write_mmio @ 00102060 size=1
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
// log_read_mmio @ 00102068 size=1
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
// log_post_read_mmio @ 00102070 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



