// Decompiled by Ghidra 12.2
// Program: boot_stats.ko
// Image base: 00100000

//------------------------------------------------------------
// readl_relaxed @ 001000b0 size=124
// signature: undefined readl_relaxed(void)
// callers: [init_module]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1000f8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100134 size=412
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined *puVar6;
  
  lVar4 = of_find_compatible_node(0,0,"qcom,msm-imem-boot_stats");
  if (lVar4 == 0) {
    puVar6 = &DAT_0010043e;
  }
  else {
    boot_stats = of_iomap(lVar4,0);
    if (boot_stats == 0) {
      puVar6 = &DAT_0010045f;
    }
    else {
      lVar4 = of_find_compatible_node(0,0,"qcom,mpm2-sleep-counter");
      if (lVar4 == 0) {
        puVar6 = &DAT_001004f3;
      }
      else {
        iVar1 = of_property_read_variable_u32_array(lVar4,"clock-frequency",&mpm_counter_freq,1,0);
        if (iVar1 < 0) {
          return 0xffffffed;
        }
        lVar5 = __of_get_address(lVar4,0,0xffffffff,0,0);
        if (lVar5 == 0) {
          return 0xffffffed;
        }
        mpm_counter_base = of_iomap(lVar4,0);
        if (mpm_counter_base != 0) {
          uVar2 = readl_relaxed(boot_stats);
          _printk(&DAT_001004a7,uVar2);
          uVar2 = readl_relaxed(boot_stats + 4);
          _printk(&DAT_001003d2,uVar2);
          iVar1 = readl_relaxed(boot_stats + 0xc);
          iVar3 = readl_relaxed(boot_stats + 8);
          _printk(&DAT_0010047d,iVar1 - iVar3);
          uVar2 = readl_relaxed(mpm_counter_base);
          _printk(&DAT_00100404,uVar2);
          _printk(&DAT_001004cb,mpm_counter_freq);
          iounmap(boot_stats);
          iounmap(mpm_counter_base);
          return 0;
        }
        puVar6 = &DAT_001003ac;
        mpm_counter_base = 0;
      }
    }
  }
  _printk(puVar6);
  return 0xffffffed;
}



//------------------------------------------------------------
// cleanup_module @ 001002d4 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// of_find_compatible_node @ 00101000 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_iomap @ 00101008 size=1
// signature: undefined of_iomap(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_iomap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00101010 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00101018 size=1
// signature: undefined __of_get_address(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101020 size=1
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
// iounmap @ 00101028 size=1
// signature: undefined iounmap(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00101030 size=1
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
// log_post_read_mmio @ 00101038 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



