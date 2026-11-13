// Decompiled by Ghidra 12.2
// Program: core_hang_detect.ko
// Image base: 00100000

//------------------------------------------------------------
// show_threshold @ 00100294 size=160
// signature: undefined show_threshold(void)
// callers: []
//------------------------------------------------------------

void show_threshold(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar2 = qcom_scm_io_readl(*(undefined8 *)(param_1 + -0x208),&local_2c);
  if (iVar2 == 0) {
    iVar2 = scnprintf(param_3,0xc,"0x%x\n",local_2c);
    lVar3 = (long)iVar2;
  }
  else {
    _printk(&DAT_00100f6d,"show_threshold");
    lVar3 = -5;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// store_threshold @ 00100338 size=284
// signature: undefined store_threshold(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long store_threshold(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  int local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_4c = 0;
  iVar2 = kstrtouint(param_3,0,&local_4c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else if (local_4c == 0) {
    param_4 = -0x16;
  }
  else {
    iVar2 = 0;
    while (uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar2), uVar3 < _nr_cpu_ids
          ) {
      if ((uVar3 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100450);
        (*pcVar1)();
      }
      lVar4 = *(long *)(param_1 + -0x208 + (ulong)uVar3 * 8);
      if ((lVar4 != 0) && (iVar2 = qcom_scm_io_writel(lVar4,local_4c), iVar2 != 0)) {
        _printk(&DAT_00101171,"store_threshold",uVar3);
        param_4 = -5;
        break;
      }
      iVar2 = uVar3 + 1;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_pmu_event_sel @ 00100458 size=56
// signature: undefined show_pmu_event_sel(void)
// callers: []
//------------------------------------------------------------

long show_pmu_event_sel(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0xc,"0x%x\n",*(undefined4 *)(param_1 + -8));
  return (long)iVar1;
}



//------------------------------------------------------------
// store_pmu_event_sel @ 00100494 size=336
// signature: undefined store_pmu_event_sel(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long store_pmu_event_sel(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  iVar2 = kstrtouint(param_3,0,(long)&local_50 + 4);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else if (local_50._4_4_ < 0x20) {
    iVar2 = 0;
    while (uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar2), uVar3 < _nr_cpu_ids
          ) {
      if ((uVar3 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1005e0);
        (*pcVar1)();
      }
      lVar4 = *(long *)(param_1 + -0x108 + (ulong)uVar3 * 8);
      if (lVar4 != 0) {
        iVar2 = qcom_scm_io_readl(lVar4,&local_50);
        if (iVar2 == 0) {
          iVar2 = qcom_scm_io_writel(*(undefined8 *)(param_1 + -0x108 + (ulong)uVar3 * 8),
                                     (uint)local_50 & 0xffffff0f | local_50._4_4_ << 4);
          if (iVar2 == 0) goto LAB_0010051c;
          puVar5 = &DAT_0010120a;
        }
        else {
          puVar5 = &DAT_00101146;
        }
        _printk(puVar5,"store_pmu_event_sel",uVar3);
        param_4 = -5;
        goto LAB_00100588;
      }
LAB_0010051c:
      iVar2 = uVar3 + 1;
    }
    *(uint *)(param_1 + -8) = local_50._4_4_;
  }
  else {
    param_4 = -0x16;
  }
LAB_00100588:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// show_enable @ 001005e8 size=168
// signature: undefined show_enable(void)
// callers: []
//------------------------------------------------------------

void show_enable(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar2 = qcom_scm_io_readl(*(undefined8 *)(param_1 + -0x108),&local_2c);
  if (iVar2 == 0) {
    local_2c = local_2c >> 1 & 1;
    iVar2 = scnprintf(param_3,0xc,&DAT_00100f9c);
    lVar3 = (long)iVar2;
  }
  else {
    _printk(&DAT_0010105e,"show_enable");
    lVar3 = -5;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// store_enable @ 00100694 size=320
// signature: undefined store_enable(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 store_enable(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined *puVar5;
  byte local_60 [4];
  uint local_5c;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_5c = 0;
  local_60[0] = 0;
  iVar2 = kstrtobool(param_3,local_60);
  if (iVar2 < 0) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    iVar2 = 0;
    puVar5 = &DAT_0010111c;
    while (uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar2), uVar3 < _nr_cpu_ids
          ) {
      if ((uVar3 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1007d0);
        (*pcVar1)();
      }
      lVar4 = *(long *)(param_1 + -0x108 + (ulong)uVar3 * 8);
      if (lVar4 != 0) {
        iVar2 = qcom_scm_io_readl(lVar4,&local_5c);
        if (iVar2 == 0) {
          iVar2 = qcom_scm_io_writel(*(undefined8 *)(param_1 + -0x108 + (ulong)uVar3 * 8),
                                     local_5c & 0xfffffffd | (uint)local_60[0] << 1);
          if (iVar2 == 0) goto LAB_0010070c;
          puVar5 = &DAT_0010119b;
        }
        _printk(puVar5,"store_enable",uVar3);
        param_4 = 0xfffffffffffffffb;
        break;
      }
LAB_0010070c:
      iVar2 = uVar3 + 1;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// msm_hang_detect_probe @ 001007d8 size=828
// signature: undefined msm_hang_detect_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_hang_detect_probe(long param_1)

{
  ulong *puVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  undefined *puVar9;
  long lVar10;
  uint uVar11;
  uint local_bc;
  undefined8 local_b8;
  ulong uStack_b0;
  ulong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  iVar3 = -0x13;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0x2f8);
  local_bc = 0;
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
  if ((lVar10 != 0) && (enable != 0)) {
    lVar7 = devm_kmalloc(param_1 + 0x10,0x268,0xdc0);
    if (lVar7 == 0) {
      iVar3 = -0xc;
    }
    else {
      lVar8 = of_get_property(lVar10,"label",0);
      if (lVar8 == 0) {
        puVar9 = &DAT_00101088;
      }
      else {
        iVar3 = of_property_read_variable_u32_array(lVar10,"cluster-id",&local_bc,1,0);
        if (iVar3 < 0) {
          _printk(&DAT_001011ef,"msm_hang_detect_probe");
        }
        else {
          iVar3 = 0;
          do {
            uVar4 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
            if (_nr_cpu_ids <= uVar4) {
              puVar9 = &DAT_001011c2;
              uVar4 = local_bc;
              goto LAB_00100b00;
            }
            if ((uVar4 & 0xffffffe0) != 0) goto LAB_00100b0c;
            iVar3 = uVar4 + 1;
          } while (*(uint *)(&DAT_00102084 + (ulong)uVar4 * 0x38) != local_bc);
        }
        uVar5 = of_count_phandle_with_args(lVar10,"qcom,chd-percpu-info",0);
        if (0 < (int)uVar5) {
          if (uVar5 < 3) {
            uVar11 = 0;
          }
          else {
            uVar11 = 0;
            uVar4 = 0;
            do {
              iVar3 = __of_parse_phandle_with_args
                                (lVar10,"qcom,chd-percpu-info",0,2,uVar4,&local_b8);
              if (iVar3 != 0) {
                puVar9 = &DAT_00100fbb;
LAB_00100b00:
                _printk(puVar9,"msm_hang_detect_probe",uVar4);
                iVar3 = -0x16;
                goto LAB_00100978;
              }
              uVar6 = of_cpu_node_to_id(local_b8);
              if (-1 < (int)uVar6) {
                if (0x1f < uVar6) {
LAB_00100b0c:
                    /* WARNING: Does not return */
                  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100b10);
                  (*pcVar2)();
                }
                puVar1 = (ulong *)(lVar7 + (ulong)uVar6 * 8);
                uVar11 = uVar11 + 1;
                *puVar1 = uStack_b0 >> 0x20;
                puVar1[0x20] = local_a8 & 0xffffffff;
              }
              uVar4 = uVar4 + 1;
            } while (uVar5 / 3 != uVar4);
          }
          if (uVar11 == _nr_cpu_ids) {
            lVar10 = lVar7 + 0x208;
            iVar3 = kobject_init_and_add
                              (lVar10,core_ktype,_sysfs_create_group,"%s_%s","hang_detect",lVar8);
            if (iVar3 == 0) {
              iVar3 = sysfs_create_group(lVar10,hang_attr_group);
              if (iVar3 == 0) {
                *(long *)(param_1 + 0xa8) = lVar7;
                goto LAB_00100978;
              }
              _printk(&DAT_001010f0,"msm_hang_detect_probe");
              kobject_del(lVar10);
            }
            else {
              _printk(&DAT_0010126a,"msm_hang_detect_probe");
            }
            kobject_put(lVar10);
          }
          else {
            _printk(&DAT_00100ff7,"msm_hang_detect_probe",uVar11);
            iVar3 = -0x16;
          }
          goto LAB_00100978;
        }
        puVar9 = &DAT_00101234;
      }
      _printk(puVar9,"msm_hang_detect_probe");
      iVar3 = -0x16;
    }
  }
LAB_00100978:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_hang_detect_remove @ 00100b18 size=80
// signature: undefined msm_hang_detect_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_hang_detect_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  lVar1 = lVar1 + 0x208;
  sysfs_remove_group(lVar1,hang_attr_group);
  kobject_del(lVar1);
  kobject_put(lVar1);
  return 0;
}



//------------------------------------------------------------
// attr_show @ 00100b6c size=68
// signature: undefined attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_show(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x40e7484a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100b98);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 00100bb4 size=68
// signature: undefined attr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_store(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x2e5b3341) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100be0);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 00100bfc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&msm_hang_detect_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100c2c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&msm_hang_detect_driver);
  return;
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 00102000 size=1
// signature: undefined qcom_scm_io_readl(void)
// callers: [show_enable, show_threshold, store_pmu_event_sel, store_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_readl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102008 size=1
// signature: undefined scnprintf(void)
// callers: [show_enable, show_pmu_event_sel, show_threshold]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102010 size=1
// signature: undefined _printk(void)
// callers: [show_enable, msm_hang_detect_probe, show_threshold, store_threshold, store_pmu_event_sel, store_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [show_enable, msm_hang_detect_probe, show_threshold, store_threshold, store_pmu_event_sel, store_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00102020 size=1
// signature: undefined kstrtouint(void)
// callers: [store_threshold, store_pmu_event_sel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00102038 size=1
// signature: undefined _find_next_bit(void)
// callers: [msm_hang_detect_probe, store_threshold, store_pmu_event_sel, store_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 00102040 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [store_threshold, store_pmu_event_sel, store_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 00102048 size=1
// signature: undefined kstrtobool(void)
// callers: [store_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102050 size=1
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
// platform_driver_unregister @ 00102058 size=1
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
// devm_kmalloc @ 00102060 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00102068 size=1
// signature: undefined of_get_property(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102070 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 00102080 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 00102090 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00102098 size=1
// signature: undefined sysfs_create_group(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001020a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_cpu_node_to_id @ 001020a8 size=1
// signature: undefined of_cpu_node_to_id(void)
// callers: [msm_hang_detect_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_cpu_node_to_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_del @ 001020b0 size=1
// signature: undefined kobject_del(void)
// callers: [msm_hang_detect_probe, msm_hang_detect_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 001020b8 size=1
// signature: undefined kobject_put(void)
// callers: [msm_hang_detect_probe, msm_hang_detect_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 001020c0 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [msm_hang_detect_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



