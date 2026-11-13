// Decompiled by Ghidra 12.2
// Program: qcom-cpufreq-hw-debug.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_cpufreq_hw_debug_probe @ 001001c4 size=576
// signature: undefined qcom_cpufreq_hw_debug_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_cpufreq_hw_debug_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  long *plVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  long local_f8;
  long lStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
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
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
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
  local_e8 = 0;
  uStack_e0 = 0;
  local_f8 = 0;
  lStack_f0 = 0;
  offsets = of_device_get_match_data(lVar1);
  if (offsets == 0) {
LAB_001003b8:
    iVar4 = -0x16;
  }
  else {
    hw_regs = (long *)devm_kmalloc(lVar1,0x10,0xdc0);
    if (hw_regs != (long *)0x0) {
      lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,freq-hw-domain",0);
      if (lVar5 == 0) goto LAB_001003b8;
      uVar2 = *(int *)(lVar5 + 8) >> 3;
      *(uint *)(hw_regs + 1) = uVar2;
      lVar5 = devm_kmalloc(lVar1,-(ulong)(uVar2 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar2 << 3,
                           0xdc0);
      plVar3 = hw_regs;
      *hw_regs = lVar5;
      if (lVar5 != 0) {
        if (0 < (int)plVar3[1]) {
          uVar6 = 0;
          do {
            iVar4 = __of_parse_phandle_with_args
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,freq-hw-domain",0,1,
                               uVar6 & 0xffffffff,&local_98);
            if ((iVar4 != 0) ||
               (iVar4 = of_address_to_resource(local_98,uStack_90._4_4_,&local_f8), iVar4 != 0)) {
              if (-1 < iVar4) goto LAB_00100334;
              goto LAB_001003bc;
            }
            lVar5 = devm_ioremap(lVar1,local_f8,(lStack_f0 - local_f8) + 1);
            plVar3 = hw_regs;
            if (lVar5 == 0) goto LAB_001003b0;
            *(long *)(*hw_regs + uVar6 * 8) = lVar5;
            uVar6 = uVar6 + 1;
          } while ((long)uVar6 < (long)(int)plVar3[1]);
        }
        atomic_notifier_chain_register(&panic_notifier_list,&cpufreq_panic_notifier);
LAB_00100334:
        cpufreqhw_kobj = kobject_create_and_add("qcom-cpufreq-hw",_kernel_kobj);
        if (cpufreqhw_kobj == 0) {
          iVar4 = -0xc;
        }
        else {
          cpufreq_hwregs_attr = "print_cpufreq_debug_regs";
          DAT_00100f40 = cpufreq_hwregs_show;
          DAT_00100f38 = 0x124;
          iVar4 = sysfs_create_file_ns(cpufreqhw_kobj,&cpufreq_hwregs_attr,0);
          if (iVar4 != 0) {
            _dev_err(lVar1,"Failed to create sysfs entry\n");
            kobject_put(cpufreqhw_kobj);
          }
        }
        goto LAB_001003cc;
      }
    }
LAB_001003b0:
    iVar4 = -0xc;
  }
LAB_001003bc:
  _dev_err(lVar1,"Failed to map cpufreq hw regs\n");
LAB_001003cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qcom_cpufreq_hw_debug_remove @ 00100408 size=64
// signature: undefined qcom_cpufreq_hw_debug_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_cpufreq_hw_debug_remove(void)

{
  sysfs_remove_file_ns(_kernel_kobj,&cpufreq_hwregs_attr,0);
  kobject_put(cpufreqhw_kobj);
  return 0;
}



//------------------------------------------------------------
// cpufreq_hwregs_show @ 0010044c size=564
// signature: undefined cpufreq_hwregs_show(void)
// callers: []
//------------------------------------------------------------

ulong cpufreq_hwregs_show(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  
  puVar2 = offsets;
  if ((int)hw_regs[1] < 1) {
    uVar7 = 0;
  }
  else {
    uVar5 = 0;
    uVar7 = 0;
    do {
      iVar3 = scnprintf(param_3 + uVar7,0x1000,"FREQUENCY DOMAIN %d\n",uVar5 & 0xffffffff);
      lVar6 = uVar5 * 8;
      uVar1 = iVar3 + (int)uVar7;
      uVar4 = readl_relaxed(*(long *)(*hw_regs + lVar6) + (ulong)*offsets);
      iVar3 = scnprintf(param_3 + (ulong)uVar1,0x1000,"%25s: 0x%.8x\n","PERF_STATE_DESIRED",uVar4);
      uVar1 = iVar3 + uVar1;
      uVar4 = readl_relaxed(*(long *)(*hw_regs + lVar6) + (ulong)offsets[1]);
      iVar3 = scnprintf(param_3 + (ulong)uVar1,0x1000,"%25s: 0x%.8x\n","CYCLE_CNTR_VAL",uVar4);
      uVar1 = iVar3 + uVar1;
      uVar4 = readl_relaxed(*(long *)(*hw_regs + lVar6) + (ulong)offsets[2]);
      iVar3 = scnprintf(param_3 + (ulong)uVar1,0x1000,"%25s: 0x%.8x\n","PSTATE_STATUS",uVar4);
      uVar1 = iVar3 + uVar1;
      uVar7 = (ulong)uVar1;
      if (puVar2 == (ushort *)cpufreq_qcom_std_epss_data) {
        uVar4 = readl_relaxed(*(long *)(*hw_regs + lVar6) + (ulong)offsets[3]);
        iVar3 = scnprintf(param_3 + uVar7,0x1000,"%25s: 0x%.8x\n","EPSS_DEBUG_STATUS",uVar4);
        uVar1 = iVar3 + uVar1;
        uVar4 = readl_relaxed(*(long *)(*hw_regs + lVar6) + (ulong)offsets[4]);
        iVar3 = scnprintf(param_3 + (ulong)uVar1,0x1000,"%25s: 0x%.8x\n","EPSS_DEBUG_SRB",uVar4);
        uVar1 = iVar3 + uVar1;
        uVar4 = readl_relaxed(*(long *)(*hw_regs + lVar6) + (ulong)offsets[5]);
        iVar3 = scnprintf(param_3 + (ulong)uVar1,0x1000,"%25s: 0x%.8x\n","EPSS_DEBUG_LUT",uVar4);
        uVar7 = (ulong)(iVar3 + uVar1);
      }
      uVar5 = uVar5 + 1;
    } while ((long)uVar5 < (long)(int)hw_regs[1]);
  }
  return uVar7;
}



//------------------------------------------------------------
// cpufreq_panic_callback @ 00100684 size=508
// signature: undefined cpufreq_panic_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 cpufreq_panic_callback(void)

{
  ushort *puVar1;
  undefined4 uVar2;
  ulong uVar3;
  long lVar4;
  
  puVar1 = offsets;
  if (0 < (int)hw_regs[1]) {
    uVar3 = 0;
    do {
      _printk(&DAT_00100b77,"cpufreq_panic_callback",uVar3 & 0xffffffff);
      lVar4 = uVar3 * 8;
      uVar2 = readl_relaxed(*(long *)(*hw_regs + lVar4) + (ulong)*offsets);
      _printk(&DAT_00100ba4,"cpufreq_panic_callback","PERF_STATE_DESIRED",uVar2);
      uVar2 = readl_relaxed(*(long *)(*hw_regs + lVar4) + (ulong)offsets[1]);
      _printk(&DAT_00100ba4,"cpufreq_panic_callback","CYCLE_CNTR_VAL",uVar2);
      uVar2 = readl_relaxed(*(long *)(*hw_regs + lVar4) + (ulong)offsets[2]);
      _printk(&DAT_00100ba4,"cpufreq_panic_callback","PSTATE_STATUS",uVar2);
      if (puVar1 == (ushort *)cpufreq_qcom_std_epss_data) {
        uVar2 = readl_relaxed(*(long *)(*hw_regs + lVar4) + (ulong)offsets[3]);
        _printk(&DAT_00100ba4,"cpufreq_panic_callback","EPSS_DEBUG_STATUS",uVar2);
        uVar2 = readl_relaxed(*(long *)(*hw_regs + lVar4) + (ulong)offsets[4]);
        _printk(&DAT_00100ba4,"cpufreq_panic_callback","EPSS_DEBUG_SRB",uVar2);
        uVar2 = readl_relaxed(*(long *)(*hw_regs + lVar4) + (ulong)offsets[5]);
        _printk(&DAT_00100ba4,"cpufreq_panic_callback","EPSS_DEBUG_LUT",uVar2);
      }
      uVar3 = uVar3 + 1;
    } while ((long)uVar3 < (long)(int)hw_regs[1]);
  }
  return 1;
}



//------------------------------------------------------------
// readl_relaxed @ 00100880 size=124
// signature: undefined readl_relaxed(void)
// callers: [cpufreq_hwregs_show, cpufreq_panic_callback]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1008c8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100904 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_cpufreq_hw_debug,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100934 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_cpufreq_hw_debug);
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
// of_device_get_match_data @ 00102010 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102020 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102028 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00102030 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00102038 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00102048 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 00102058 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00102060 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102068 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 00102070 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_cpufreq_hw_debug_remove, qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102078 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_cpufreq_hw_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 00102080 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [qcom_cpufreq_hw_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102088 size=1
// signature: undefined scnprintf(void)
// callers: [cpufreq_hwregs_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102090 size=1
// signature: undefined _printk(void)
// callers: [cpufreq_panic_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00102098 size=1
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
// log_post_read_mmio @ 001020a0 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



