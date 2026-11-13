// Decompiled by Ghidra 12.2
// Program: qcom_iommu_debug.ko
// Image base: 00100000

//------------------------------------------------------------
// iommu_debug_check_mapping_flags @ 00100b94 size=352
// signature: undefined iommu_debug_check_mapping_flags(void)
// callers: [__functional_dma_api_basic_test, iommu_debug_check_mapping_sg_flags]
//------------------------------------------------------------

void iommu_debug_check_mapping_flags
               (long param_1,long param_2,long param_3,long param_4,undefined4 param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  long local_78;
  long local_70;
  long local_68;
  undefined4 local_60;
  uint local_5c;
  long local_58;
  long lStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = param_4;
  lStack_50 = param_2;
  lVar2 = iommu_get_domain_for_dev();
  if (lVar2 == 0) {
    pcVar5 = "iommu_get_domain_for_dev() failed\n";
  }
  else {
    if ((*(long *)(param_1 + 0x338) != 0) &&
       (lVar6 = *(long *)(*(long *)(param_1 + 0x338) + 0x40), lVar6 != 0)) {
      local_5c = (uint)*(ushort *)(lVar6 + 0x18);
      local_68 = param_2;
      local_60 = param_5;
      if ((param_3 + 0xfffU & 0xfffffffffffff000) != 0) {
        lVar6 = -(param_3 + 0xfffU & 0xfffffffffffff000);
        do {
          lVar3 = qcom_iommu_iova_to_phys_hard(lVar2,&local_68);
          local_78 = lVar3;
          local_70 = iommu_iova_to_phys(lVar2,param_2);
          if ((param_4 != lVar3) || (param_4 != local_70)) {
            iVar1 = ___ratelimit(&iommu_debug_check_mapping_flags__rs,
                                 "iommu_debug_check_mapping_flags");
            if (iVar1 != 0) {
              _dev_err(param_1,
                       "Bad translation for %pad! Expected: %pa Got: %pa (ATOS) %pa (Table Walk) sid=%08x\n"
                       ,&lStack_50,&local_58,&local_78,&local_70,local_5c);
            }
            goto LAB_00100cbc;
          }
          param_2 = param_2 + 0x1000;
          param_4 = param_4 + 0x1000;
          lVar6 = lVar6 + 0x1000;
          local_58 = param_4;
          lStack_50 = param_2;
        } while (lVar6 != 0);
      }
      uVar4 = 0;
      goto LAB_00100cc0;
    }
    pcVar5 = "dev_iommu_fwspec_get() failed\n";
  }
  _dev_err(param_1,pcVar5);
LAB_00100cbc:
  uVar4 = 0xffffffea;
LAB_00100cc0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// iommu_debug_check_mapping_sg_flags @ 00100cf8 size=276
// signature: undefined iommu_debug_check_mapping_sg_flags(void)
// callers: [iommu_debug_functional_arm_dma_api_show]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void iommu_debug_check_mapping_sg_flags
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long local_78;
  undefined8 local_70;
  undefined8 local_68;
  ulong *local_60;
  ulong local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  local_60 = (ulong *)0x0;
  local_78 = 0;
  local_70 = 0;
  __sg_page_iter_start(&local_60,param_2,param_5,param_3);
  __sg_page_iter_start(&local_78,param_2,param_4,param_3);
  while ((uVar2 = __sg_page_iter_next(&local_60), (uVar2 & 1) != 0 &&
         (uVar2 = __sg_page_iter_dma_next(&local_78), (uVar2 & 1) != 0))) {
    uVar3 = iommu_debug_check_mapping_flags
                      (param_1,*(long *)(local_78 + 0x10) + (ulong)(uint)((int)local_70 << 0xc),
                       0x1000,((*local_60 & 0x3fffffffffffffc) + (local_58 & 0xffffffff) * 0x40 +
                              (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000,param_6);
    if ((int)uVar3 != 0) {
LAB_00100dd8:
      lVar1 = sp_el0;
      if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar3);
      }
      return;
    }
  }
  uVar3 = 0;
  goto LAB_00100dd8;
}



//------------------------------------------------------------
// iommu_debug_switch_usecase @ 00100e10 size=516
// signature: undefined iommu_debug_switch_usecase(void)
// callers: [iommu_debug_usecase_write, iommu_debug_usecase_reset]
//------------------------------------------------------------

void iommu_debug_switch_usecase(long *param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  uint uVar6;
  long *plVar7;
  char *local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  plVar7 = param_1 + 4;
  local_50 = (char *)0x0;
  if (*plVar7 != 0) {
    of_platform_device_destroy(*plVar7,0);
    *plVar7 = 0;
    param_1[5] = 0;
  }
  uVar5 = *(undefined8 *)(*param_1 + 0x2e8);
  lVar2 = of_get_next_child(uVar5,0);
  if (lVar2 != 0) {
    uVar6 = 0;
    do {
      uVar6 = uVar6 + 1;
      lVar2 = of_get_next_child(uVar5,lVar2);
    } while (lVar2 != 0);
    if (param_2 < uVar6) {
      *(undefined4 *)(param_1 + 0xd) = 0;
      lVar2 = of_get_next_child(*(undefined8 *)(*param_1 + 0x2e8),0);
      if ((lVar2 != 0) && (uVar6 = param_2, param_2 != 0)) {
        do {
          uVar6 = uVar6 - 1;
          lVar2 = of_get_next_child(*(undefined8 *)(*param_1 + 0x2e8),lVar2);
        } while (lVar2 != 0 && uVar6 != 0);
      }
      lVar3 = of_platform_device_create(lVar2,0,*param_1);
      if (lVar3 == 0) {
        _dev_err(*param_1,"Creating platform device failed\n");
        lVar2 = 0;
      }
      else {
        iVar1 = wait_for_completion_interruptible_timeout(param_1 + 0xd,0x7d);
        if (iVar1 < 1) {
          pcVar4 = "Timed out waiting for usecase to register\n";
        }
        else {
          iVar1 = of_property_read_string(lVar2,"qcom,iommu-dma",&local_50);
          if (iVar1 != 0) {
            local_50 = "default";
          }
          iVar1 = strcmp(local_50,"fastmap");
          *(uint *)(param_1 + 6) = param_2;
          param_1[4] = lVar3 + 0x10;
          *(bool *)((long)param_1 + 0x34) = iVar1 == 0;
          lVar2 = iommu_get_domain_for_dev();
          param_1[5] = lVar2;
          if (lVar2 != 0) {
            lVar2 = *plVar7;
            goto LAB_00100f74;
          }
          pcVar4 = "Oops, usecase not associated with iommu\n";
        }
        _dev_err(*param_1,pcVar4);
        lVar2 = 0;
        if (param_1[4] != 0) {
          of_platform_device_destroy(param_1[4],0);
          lVar2 = 0;
          *plVar7 = 0;
          param_1[5] = 0;
        }
      }
      goto LAB_00100f74;
    }
  }
  _dev_err(*param_1,"Invalid usecase nr requested: %u\n",param_2);
  lVar2 = 0;
LAB_00100f74:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// iommu_debug_usecase_reset @ 00101018 size=32
// signature: undefined iommu_debug_usecase_reset(void)
// callers: [iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show, iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

void iommu_debug_usecase_reset(long param_1)

{
  iommu_debug_switch_usecase(param_1,*(undefined4 *)(param_1 + 0x30));
  return;
}



//------------------------------------------------------------
// init_module @ 0010103c size=104
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&iommu_debug_driver,&__this_module);
  if (iVar1 == 0) {
    iVar1 = __platform_driver_register(&iommu_debug_usecase_driver,&__this_module);
    if (iVar1 != 0) {
      platform_driver_unregister(&iommu_debug_driver);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001010a8 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&iommu_debug_usecase_driver);
  platform_driver_unregister(&iommu_debug_driver);
  return;
}



//------------------------------------------------------------
// iommu_debug_probe @ 001010dc size=724
// signature: undefined iommu_debug_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  int iVar8;
  
  lVar1 = param_1 + 0x10;
  plVar3 = (long *)devm_kmalloc(lVar1,0x98,0xdc0);
  if (plVar3 != (long *)0x0) {
    *(undefined4 *)(plVar3 + 6) = 0xffffffff;
    *plVar3 = lVar1;
    *(undefined4 *)(plVar3 + 0x12) = 1;
    __mutex_init(plVar3 + 7,"&ddev->state_lock",&iommu_debug_probe___key);
    *(undefined4 *)(plVar3 + 0xd) = 0;
    __init_swait_queue_head(plVar3 + 0xe,"&x->wait",&init_completion___key);
    lVar4 = devm_kmalloc(lVar1,0x1000,0xdc0);
    plVar3[2] = lVar4;
    if (lVar4 != 0) {
      uVar5 = *(undefined8 *)(param_1 + 0x2f8);
      *(undefined4 *)(plVar3 + 1) = 0;
      puVar6 = (undefined8 *)of_get_next_child(uVar5,0);
      if (puVar6 != (undefined8 *)0x0) {
        iVar8 = 0;
        do {
          iVar2 = scnprintf(plVar3[2] + (long)iVar8,0x1000 - (long)iVar8,"%d: %s\n",(int)plVar3[1],
                            *puVar6);
          iVar8 = iVar2 + iVar8;
          if (iVar8 == 0xfff) {
            _dev_err(lVar1,"Too many testcases?\n");
            break;
          }
          uVar5 = *(undefined8 *)(param_1 + 0x2f8);
          *(int *)(plVar3 + 1) = (int)plVar3[1] + 1;
          puVar6 = (undefined8 *)of_get_next_child(uVar5,puVar6);
        } while (puVar6 != (undefined8 *)0x0);
      }
      *(long **)(param_1 + 0xa8) = plVar3;
      uVar7 = debugfs_create_dir("iommu-test",0);
      if (uVar7 < 0xfffffffffffff001) {
        plVar3[3] = uVar7;
        debugfs_create_file("usecase",0x180,uVar7,plVar3,iommu_debug_usecase_fops);
        debugfs_create_file("functional_arm_dma_api",0x100,uVar7,plVar3,
                            iommu_debug_functional_arm_dma_api_fops);
        debugfs_create_file("functional_fast_dma_api",0x100,uVar7,plVar3,
                            iommu_debug_functional_fast_dma_api_fops);
        debugfs_create_file(&DAT_00105f91,0x180,uVar7,plVar3,&iommu_debug_atos_fops);
        debugfs_create_file(&DAT_00106047,0x80,uVar7,plVar3,iommu_debug_map_fops);
        debugfs_create_file("unmap",0x80,uVar7,plVar3,iommu_debug_unmap_fops);
        debugfs_create_file("dma_map",0x80,uVar7,plVar3,iommu_debug_dma_map_fops);
        debugfs_create_file("dma_unmap",0x80,uVar7,plVar3,iommu_debug_dma_unmap_fops);
        debugfs_create_file("nr_iters",0x180,uVar7,plVar3,&iommu_debug_nr_iters_fops);
        debugfs_create_file("test_virt_addr",0x100,uVar7,plVar3,iommu_debug_test_virt_addr_fops);
        debugfs_create_file("profiling",0x100,uVar7,plVar3,iommu_debug_profiling_fops);
        return 0;
      }
      return 0xffffffea;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// iommu_debug_remove @ 001013b4 size=64
// signature: undefined iommu_debug_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  debugfs_remove(*(undefined8 *)(lVar1 + 0x18));
  lVar1 = *(long *)(lVar1 + 0x20);
  if (lVar1 != 0) {
    of_platform_device_destroy(lVar1,0);
  }
  return 0;
}



//------------------------------------------------------------
// iommu_debug_usecase_read @ 001013f8 size=116
// signature: undefined iommu_debug_usecase_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_debug_usecase_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  size_t sVar1;
  char *__string;
  
  __string = *(char **)(*(long *)(param_1 + 0xd8) + 0x10);
  sVar1 = strnlen(__string,0x1000);
  if (sVar1 == 0xffffffffffffffff) {
    fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  simple_read_from_buffer(param_2,param_3,param_4,__string,sVar1);
  return;
}



//------------------------------------------------------------
// iommu_debug_usecase_write @ 00101470 size=196
// signature: undefined iommu_debug_usecase_write(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_usecase_write(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0xd8);
  local_3c = 0;
  iVar1 = kstrtouint_from_user(param_2,param_3,0,&local_3c);
  if (iVar1 == 0) {
    uVar3 = 0xffffffffffffffea;
    if (local_3c < *(uint *)(lVar4 + 8)) {
      mutex_lock(lVar4 + 0x38);
      lVar2 = iommu_debug_switch_usecase(lVar4,local_3c);
      mutex_unlock(lVar4 + 0x38);
      uVar3 = 0xffffffffffffffea;
      if (lVar2 != 0) {
        uVar3 = param_3;
      }
    }
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// iommu_debug_nr_iters_fops_open @ 00101538 size=52
// signature: undefined iommu_debug_nr_iters_fops_open(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_nr_iters_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,iommu_debug_nr_iters_get,iommu_debug_nr_iters_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// iommu_debug_nr_iters_get @ 00101570 size=16
// signature: undefined iommu_debug_nr_iters_get(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_nr_iters_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x90);
  return 0;
}



//------------------------------------------------------------
// iommu_debug_nr_iters_set @ 00101584 size=36
// signature: undefined iommu_debug_nr_iters_set(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_nr_iters_set(long param_1,ulong param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar1 = param_2;
  if (9999 < param_2) {
    uVar1 = 10000;
  }
  uVar2 = (undefined4)uVar1;
  if (param_2 == 0) {
    uVar2 = 1;
  }
  *(undefined4 *)(param_1 + 0x90) = uVar2;
  return 0;
}



//------------------------------------------------------------
// iommu_debug_usecase_probe @ 001015ac size=44
// signature: undefined iommu_debug_usecase_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_usecase_probe(long param_1)

{
  complete(*(long *)(*(long *)(param_1 + 0x70) + 0x98) + 0x68);
  return 0;
}



//------------------------------------------------------------
// iommu_debug_dma_atos_read @ 001015dc size=384
// signature: undefined iommu_debug_dma_atos_read(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_dma_atos_read(long param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined8 local_c8;
  undefined4 local_c0;
  uint uStack_bc;
  long local_b8 [13];
  undefined4 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  uVar3 = 0;
  local_50 = 0;
  lVar5 = *(long *)(param_1 + 0xd8);
  local_b8[0xb] = 0;
  local_b8[0xc] = 0;
  local_b8[9] = 0;
  local_b8[10] = 0;
  local_b8[7] = 0;
  local_b8[8] = 0;
  local_b8[5] = 0;
  local_b8[6] = 0;
  local_b8[3] = 0;
  local_b8[4] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  if (*param_4 == 0) {
    lVar1 = lVar5 + 0x38;
    mutex_lock(lVar1);
    if (*(long *)(lVar5 + 0x28) == 0) {
      _printk(&DAT_00105dd9,"iommu_debug_dma_atos_read");
      mutex_unlock(lVar1);
      uVar3 = 0xffffffffffffffea;
    }
    else {
      lVar4 = *(long *)(*(long *)(lVar5 + 0x20) + 0x338);
      if ((lVar4 == 0) || (lVar4 = *(long *)(lVar4 + 0x40), lVar4 == 0)) {
        _printk(&DAT_00105fa0,"iommu_debug_dma_atos_read");
        mutex_unlock(lVar1);
        uVar3 = 0;
      }
      else {
        local_c8 = *(undefined8 *)(lVar5 + 0x88);
        uStack_bc = (uint)*(ushort *)(lVar4 + 0x18);
        local_c0 = 0;
        local_b8[0] = qcom_iommu_iova_to_phys_hard(*(long *)(lVar5 + 0x28),&local_c8);
        if (local_b8[0] == 0) {
          iVar2 = strscpy(local_b8 + 1,"FAIL\n",6);
        }
        else {
          iVar2 = scnprintf(local_b8 + 1,100,&DAT_001057de,local_b8);
        }
        mutex_unlock(lVar1);
        uVar3 = simple_read_from_buffer(param_2,param_3,param_4,local_b8 + 1,(long)iVar2);
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// iommu_debug_atos_write @ 00101760 size=364
// signature: undefined iommu_debug_atos_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 iommu_debug_atos_write(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  ulong local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar7 = *(long *)(param_1 + 0xd8);
  local_40 = 0;
  lVar1 = lVar7 + 0x38;
  mutex_lock(lVar1);
  if (*(long *)(lVar7 + 0x28) == 0) {
    _printk(&DAT_00105dd9,"iommu_debug_atos_write");
  }
  else {
    iVar3 = kstrtoull_from_user(param_2,param_3,0,&local_40);
    if (iVar3 == 0) {
      local_48 = iommu_iova_to_phys(*(undefined8 *)(lVar7 + 0x28),local_40);
      if (((local_48 >> 0x30 == 0) && (_mem_section != 0)) &&
         (lVar4 = *(long *)(_mem_section + (local_48 >> 0x1f & 0x1fffffff8)), lVar4 != 0)) {
        uVar5 = local_48 >> 0x1b & 0x7f;
        puVar2 = (undefined8 *)(lVar4 + uVar5 * 0x20);
        if (((puVar2 != (undefined8 *)0x0) && (uVar6 = (uint)*puVar2, (uVar6 >> 1 & 1) != 0)) &&
           (((uVar6 >> 3 & 1) != 0 ||
            ((**(ulong **)(lVar4 + uVar5 * 0x20 + 8) >> (local_48 >> 0x15 & 0x3f) & 1) != 0)))) {
          *(undefined8 *)(lVar7 + 0x88) = local_40;
          mutex_unlock(lVar1);
          _printk(&DAT_001062b3,&local_40);
          goto LAB_00101874;
        }
      }
      _dev_err(*(undefined8 *)(lVar7 + 0x20),"Invalid ATOS operation page %pa\n",&local_48);
    }
    else {
      _dev_err(*(undefined8 *)(lVar7 + 0x20),"Invalid format for iova\n");
      *(undefined8 *)(lVar7 + 0x88) = 0;
    }
  }
  mutex_unlock(lVar1);
  param_3 = 0xffffffffffffffea;
LAB_00101874:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// iommu_debug_map_write @ 001018d0 size=920
// signature: undefined iommu_debug_map_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong iommu_debug_map_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  ulong uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  ulong uVar11;
  long lVar12;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar12 = sp_el0;
  local_58 = *(long *)(lVar12 + 0x638);
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_d8 = 0;
  local_dc = 0;
  if (param_3 < 100) {
    lVar12 = *(long *)(param_1 + 0xd8);
    __check_object_size(&local_c0,param_3,0);
    puVar10 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar11 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar6 = param_3;
    if (uVar11 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        puVar10 = (undefined8 *)puVar10[1];
        uVar6 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      uVar6 = __arch_copy_from_user(puVar10,&local_c0,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
    }
    if (uVar6 != 0) {
      memset((void *)((long)&local_c0 + (param_3 - uVar6)),0,uVar6);
      iVar3 = ___ratelimit(iommu_debug_map_write__rs_8,"iommu_debug_map_write");
      if (iVar3 != 0) {
        _printk(&DAT_001062de);
      }
    }
    puVar7 = (undefined1 *)strnchr(&local_c0,param_3,0x2c);
    if (puVar7 != (undefined1 *)0x0) {
      puVar8 = (undefined1 *)strnchr(puVar7 + 1,param_3,0x2c);
      if (puVar8 != (undefined1 *)0x0) {
        puVar9 = (undefined1 *)strnchr(puVar8 + 1,param_3,0x2c);
        if (puVar9 != (undefined1 *)0x0) {
          *puVar9 = 0;
          *puVar8 = 0;
          *puVar7 = 0;
          iVar3 = kstrtoull(&local_c0,0,&uStack_c8);
          if ((((iVar3 == 0) && (iVar3 = kstrtoull(puVar7 + 1,0,&local_d0), iVar3 == 0)) &&
              (iVar3 = kstrtoull(puVar8 + 1,0,&local_d8), iVar3 == 0)) &&
             (iVar3 = kstrtoint(puVar9 + 1,0,&local_dc), iVar3 == 0)) {
            lVar1 = lVar12 + 0x38;
            mutex_lock(lVar1);
            lVar12 = *(long *)(lVar12 + 0x28);
            if (lVar12 != 0) {
              iVar3 = iommu_map(lVar12,uStack_c8,local_d0,local_d8,local_dc);
              if (iVar3 == 0) {
                _printk(&DAT_001065ce,&uStack_c8,&local_d0,local_d8,local_dc);
              }
              else {
                iVar4 = ___ratelimit(iommu_debug_map_write__rs_11,"iommu_debug_map_write");
                if (iVar4 != 0) {
                  _printk(&DAT_001063ff,iVar3);
                }
                param_3 = 0xfffffffffffffffb;
              }
              mutex_unlock(lVar1);
              goto LAB_00101b04;
            }
            iVar3 = ___ratelimit(iommu_debug_map_write__rs_10,"iommu_debug_map_write");
            if (iVar3 != 0) {
              _printk(&DAT_00105dd9,"iommu_debug_map_write");
            }
            mutex_unlock(lVar1);
            goto LAB_00101b00;
          }
        }
      }
    }
    iVar3 = ___ratelimit(iommu_debug_map_write__rs_14,"iommu_debug_map_write");
    if (iVar3 != 0) {
      puVar5 = &DAT_0010594f;
      goto LAB_00101b44;
    }
  }
  else {
    iVar3 = ___ratelimit(&iommu_debug_map_write__rs,"iommu_debug_map_write");
    if (iVar3 != 0) {
      puVar5 = &DAT_0010593c;
LAB_00101b44:
      _printk(puVar5);
    }
  }
LAB_00101b00:
  param_3 = 0xffffffffffffffea;
LAB_00101b04:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// iommu_debug_unmap_write @ 00101c84 size=848
// signature: undefined iommu_debug_unmap_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong iommu_debug_unmap_write(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  undefined *puVar3;
  ulong uVar4;
  undefined1 *puVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  long local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  if (param_3 < 100) {
    lVar9 = *(long *)(param_1 + 0xd8);
    if (*(long *)(lVar9 + 0x28) == 0) {
      iVar2 = ___ratelimit(iommu_debug_unmap_write__rs_17,"iommu_debug_unmap_write");
      if (iVar2 != 0) {
        _printk(&DAT_00105dd9,"iommu_debug_unmap_write");
      }
    }
    else {
      __check_object_size(&local_a0,param_3,0);
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar8 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar4 = param_3;
      if (uVar8 <= 0x8000000000 - param_3) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar4 = daif;
            daif = uVar4 | 0xc0;
          }
          puVar7 = (undefined8 *)puVar7[1];
          uVar4 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar7;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
        uVar4 = __arch_copy_from_user(puVar7,&local_a0,param_2 & 0xff7fffffffffffff,param_3);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          uVar1 = ttbr1_el1;
          ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
      }
      if (uVar4 != 0) {
        memset((void *)((long)&local_a0 + (param_3 - uVar4)),0,uVar4);
        iVar2 = ___ratelimit(iommu_debug_unmap_write__rs_18,"iommu_debug_unmap_write");
        if (iVar2 == 0) {
          param_3 = 0xfffffffffffffff2;
        }
        else {
          _printk(&DAT_001062de);
          param_3 = 0xfffffffffffffff2;
        }
LAB_00101ee8:
        mutex_unlock(lVar9 + 0x38);
        goto LAB_00101e70;
      }
      puVar5 = (undefined1 *)strnchr(&local_a0,param_3,0x2c);
      if (puVar5 != (undefined1 *)0x0) {
        *puVar5 = 0;
        iVar2 = kstrtoull(&local_a0,0,&uStack_a8);
        if ((iVar2 == 0) && (iVar2 = kstrtoull(puVar5 + 1,0,&local_b0), iVar2 == 0)) {
          mutex_lock(lVar9 + 0x38);
          if (*(long *)(lVar9 + 0x28) == 0) {
            iVar2 = ___ratelimit(iommu_debug_unmap_write__rs_19,"iommu_debug_unmap_write");
            if (iVar2 != 0) {
              _printk(&DAT_00105b67);
            }
            mutex_unlock(lVar9 + 0x38);
            goto LAB_00101e6c;
          }
          lVar6 = iommu_unmap(*(long *)(lVar9 + 0x28),uStack_a8,local_b0);
          if (lVar6 == local_b0) {
            _printk(&DAT_0010631a,&uStack_a8,lVar6);
          }
          else {
            iVar2 = ___ratelimit(iommu_debug_unmap_write__rs_21,"iommu_debug_unmap_write");
            if (iVar2 != 0) {
              _printk(&DAT_0010585a,local_b0,lVar6);
            }
            param_3 = 0xfffffffffffffffb;
          }
          goto LAB_00101ee8;
        }
      }
      iVar2 = ___ratelimit(iommu_debug_unmap_write__rs_24,"iommu_debug_unmap_write");
      if (iVar2 != 0) {
        puVar3 = &DAT_00106336;
        goto LAB_00101e4c;
      }
    }
  }
  else {
    iVar2 = ___ratelimit(iommu_debug_unmap_write__rs,"iommu_debug_unmap_write");
    if (iVar2 != 0) {
      puVar3 = &DAT_0010593c;
LAB_00101e4c:
      _printk(puVar3);
    }
  }
LAB_00101e6c:
  param_3 = 0xffffffffffffffea;
LAB_00101e70:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// iommu_debug_dma_map_read @ 00101ff0 size=200
// signature: undefined iommu_debug_dma_map_read(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_dma_map_read(long param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = 0;
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  if (*param_4 == 0) {
    local_a8 = *(undefined8 *)(*(long *)(param_1 + 0xd8) + 0x88);
    iVar2 = scnprintf(&local_a0,100,&DAT_001057de,&local_a8);
    uVar3 = simple_read_from_buffer(param_2,param_3,param_4,&local_a0,(long)iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// iommu_debug_dma_map_write @ 001020bc size=1188
// signature: undefined iommu_debug_dma_map_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong iommu_debug_dma_map_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  undefined *puVar4;
  ulong uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  long lVar13;
  uint local_cc;
  long local_c8;
  long local_c0;
  ulong local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar13 = sp_el0;
  local_48 = *(long *)(lVar13 + 0x638);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_c8 = 0;
  local_cc = 0;
  if (param_3 < 100) {
    lVar13 = *(long *)(param_1 + 0xd8);
    uVar11 = *(undefined8 *)(lVar13 + 0x20);
    __check_object_size(&local_b0,param_3,0);
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_2, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar10 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar5 = param_3;
    if (uVar10 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      uVar5 = __arch_copy_from_user(puVar9,&local_b0,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
    }
    if (uVar5 != 0) {
      memset((void *)((long)&local_b0 + (param_3 - uVar5)),0,uVar5);
      iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_26,"iommu_debug_dma_map_write");
      if (iVar3 != 0) {
        _printk(&DAT_001062de);
      }
      param_3 = 0xfffffffffffffff2;
      goto LAB_001022c0;
    }
    puVar6 = (undefined1 *)strnchr(&local_b0,param_3,0x2c);
    if (puVar6 == (undefined1 *)0x0) {
LAB_001022a4:
      iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_34,"iommu_debug_dma_map_write");
      if (iVar3 != 0) {
        puVar4 = &DAT_00105ea7;
        goto LAB_001022fc;
      }
    }
    else {
      puVar7 = (undefined1 *)strnchr(puVar6 + 1,param_3,0x2c);
      if (puVar7 == (undefined1 *)0x0) goto LAB_001022a4;
      *puVar7 = 0;
      *puVar6 = 0;
      iVar3 = kstrtoull(&local_b0,0,&local_b8);
      uVar10 = local_b8;
      if (iVar3 != 0) goto LAB_001022a4;
      iVar3 = kstrtoull(puVar6 + 1,0,&local_c8);
      if ((iVar3 != 0) || (iVar3 = kstrtouint(puVar7 + 1,0,&local_cc), iVar3 != 0))
      goto LAB_001022a4;
      mutex_lock(test_virt_addr_lock);
      uVar5 = test_virt_addr;
      if (0xfffffffffffff000 < test_virt_addr) {
        mutex_unlock(test_virt_addr_lock);
        iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_38,"iommu_debug_dma_map_write");
        if (iVar3 != 0) {
          _printk(&DAT_00105d4e);
        }
        param_3 = 0xfffffffffffffff4;
        goto LAB_001022c0;
      }
      mutex_unlock(test_virt_addr_lock);
      if (uVar5 == 0) {
        iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_40,"iommu_debug_dma_map_write");
        if (iVar3 != 0) {
          puVar4 = &DAT_001059bf;
          goto LAB_001022fc;
        }
      }
      else if ((uVar10 < test_virt_addr) || (test_virt_addr + 0x100000 < uVar10 + local_c8)) {
        iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_36,"iommu_debug_dma_map_write");
        if (iVar3 != 0) {
          _printk(&DAT_001064e6,uVar10);
        }
      }
      else {
        if (3 < local_cc) goto LAB_001022a4;
        lVar1 = lVar13 + 0x38;
        uVar12 = *(undefined8 *)(&DAT_00107fc8 + (long)(int)local_cc * 8);
        mutex_lock(lVar1);
        if (*(long *)(lVar13 + 0x28) != 0) {
          lVar8 = dma_map_single_attrs(uVar11,uVar10,local_c8,uVar12);
          local_c0 = lVar8;
          if (lVar8 == -1) {
            iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_28,"iommu_debug_dma_map_write");
            if (iVar3 != 0) {
              _printk(&DAT_00105823);
            }
            param_3 = 0xffffffffffffffea;
          }
          else {
            iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_30,"iommu_debug_dma_map_write");
            if (iVar3 != 0) {
              _printk(&DAT_00105e85,uVar10,&local_c0,local_c8);
              lVar8 = local_c0;
            }
            *(long *)(lVar13 + 0x88) = lVar8;
            iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_32,"iommu_debug_dma_map_write");
            if (iVar3 != 0) {
              _printk(&DAT_001057e3,&local_c0);
            }
          }
          mutex_unlock(lVar1);
          goto LAB_001022c0;
        }
        iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs_27,"iommu_debug_dma_map_write");
        if (iVar3 != 0) {
          _printk(&DAT_00105dd9,"iommu_debug_dma_map_write");
        }
        mutex_unlock(lVar1);
      }
    }
  }
  else {
    iVar3 = ___ratelimit(iommu_debug_dma_map_write__rs,"iommu_debug_dma_map_write");
    if (iVar3 == 0) goto LAB_001022bc;
    puVar4 = &DAT_0010593c;
LAB_001022fc:
    _printk(puVar4);
  }
LAB_001022bc:
  param_3 = 0xffffffffffffffea;
LAB_001022c0:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// iommu_debug_dma_unmap_write @ 0010257c size=868
// signature: undefined iommu_debug_dma_unmap_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong iommu_debug_dma_unmap_write(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  undefined *puVar3;
  ulong uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  long lVar11;
  undefined8 local_c8;
  uint local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_bc = 0;
  local_c8 = 0;
  if (param_3 < 100) {
    lVar11 = *(long *)(param_1 + 0xd8);
    uVar9 = *(undefined8 *)(lVar11 + 0x20);
    __check_object_size(&local_b0,param_3,0);
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar8 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar4 = param_3;
    if (uVar8 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar4 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      uVar4 = __arch_copy_from_user(puVar7,&local_b0,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
    }
    if (uVar4 != 0) {
      memset((void *)((long)&local_b0 + (param_3 - uVar4)),0,uVar4);
      iVar2 = ___ratelimit(iommu_debug_dma_unmap_write__rs_43,"iommu_debug_dma_unmap_write");
      if (iVar2 == 0) {
        param_3 = 0xfffffffffffffff2;
      }
      else {
        _printk(&DAT_001062de);
        param_3 = 0xfffffffffffffff2;
      }
LAB_001027bc:
      mutex_unlock(lVar11 + 0x38);
      goto LAB_001027e4;
    }
    puVar5 = (undefined1 *)strnchr(&local_b0,param_3,0x2c);
    if (puVar5 != (undefined1 *)0x0) {
      puVar6 = (undefined1 *)strnchr(puVar5 + 1,param_3,0x2c);
      if (puVar6 != (undefined1 *)0x0) {
        *puVar6 = 0;
        *puVar5 = 0;
        iVar2 = kstrtoull(&local_b0,0,&local_c8);
        if ((((iVar2 == 0) && (iVar2 = kstrtoull(puVar5 + 1,0,&local_b8), iVar2 == 0)) &&
            (iVar2 = kstrtouint(puVar6 + 1,0,&local_bc), iVar2 == 0)) && (local_bc < 4)) {
          uVar10 = *(undefined8 *)(&DAT_00107fc8 + (long)(int)local_bc * 8);
          mutex_lock(lVar11 + 0x38);
          if (*(long *)(lVar11 + 0x28) == 0) {
            iVar2 = ___ratelimit(iommu_debug_dma_unmap_write__rs_44,"iommu_debug_dma_unmap_write");
            if (iVar2 != 0) {
              _printk(&DAT_00105dd9,"iommu_debug_dma_unmap_write");
            }
            mutex_unlock(lVar11 + 0x38);
            goto LAB_001027e0;
          }
          dma_unmap_page_attrs(uVar9,local_c8,local_b8,1,uVar10);
          iVar2 = ___ratelimit(iommu_debug_dma_unmap_write__rs_45,"iommu_debug_dma_unmap_write");
          if (iVar2 != 0) {
            _printk(&DAT_00105b47,&local_c8,local_b8);
          }
          goto LAB_001027bc;
        }
      }
    }
    iVar2 = ___ratelimit(iommu_debug_dma_unmap_write__rs_47,"iommu_debug_dma_unmap_write");
    if (iVar2 != 0) {
      puVar3 = &DAT_0010641b;
      goto LAB_00102820;
    }
  }
  else {
    iVar2 = ___ratelimit(iommu_debug_dma_unmap_write__rs,"iommu_debug_dma_unmap_write");
    if (iVar2 != 0) {
      puVar3 = &DAT_0010593c;
LAB_00102820:
      _printk(puVar3);
    }
  }
LAB_001027e0:
  param_3 = 0xffffffffffffffea;
LAB_001027e4:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// iommu_debug_functional_arm_dma_api_open @ 001028fc size=48
// signature: undefined iommu_debug_functional_arm_dma_api_open(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_functional_arm_dma_api_open(long param_1,undefined8 param_2)

{
  single_open(param_2,iommu_debug_functional_arm_dma_api_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// iommu_debug_functional_fast_dma_api_open @ 00102930 size=48
// signature: undefined iommu_debug_functional_fast_dma_api_open(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_functional_fast_dma_api_open(long param_1,undefined8 param_2)

{
  single_open(param_2,iommu_debug_functional_fast_dma_api_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// iommu_debug_test_virt_addr_read @ 00102964 size=288
// signature: undefined iommu_debug_test_virt_addr_read(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_test_virt_addr_read
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long *param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  uVar3 = 0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  if (*param_4 != 0) goto LAB_00102a30;
  mutex_lock(test_virt_addr_lock);
  if ((test_virt_addr == 0) || (0xfffffffffffff000 < test_virt_addr)) {
    test_virt_addr = kmalloc_large(0x100000,0xdc0);
    if (test_virt_addr != 0) goto LAB_001029f4;
    test_virt_addr = 0xfffffffffffffff4;
    iVar2 = strscpy(&local_a0,"FAIL\n",6,0);
  }
  else {
LAB_001029f4:
    iVar2 = scnprintf(&local_a0,100,"0x%p\n");
  }
  mutex_unlock(test_virt_addr_lock);
  uVar3 = simple_read_from_buffer(param_2,param_3,param_4,&local_a0,(long)iVar2);
LAB_00102a30:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// iommu_debug_profiling_open @ 00102a88 size=48
// signature: undefined iommu_debug_profiling_open(void)
// callers: []
//------------------------------------------------------------

void iommu_debug_profiling_open(long param_1,undefined8 param_2)

{
  single_open(param_2,iommu_debug_profiling_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// dma_map_single_attrs @ 00102ab8 size=200
// signature: undefined dma_map_single_attrs(void)
// callers: [iommu_debug_dma_map_write]
//------------------------------------------------------------

undefined8 dma_map_single_attrs(long *param_1,ulong param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = is_vmalloc_addr(param_2);
  if (((uVar2 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar3 = dev_driver_string(param_1);
    lVar4 = param_1[0xe];
    if (lVar4 == 0) {
      lVar4 = *param_1;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar3,lVar4);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102b38);
    (*pcVar1)();
  }
  if ((uVar2 & 1) == 0) {
    uVar3 = dma_map_page_attrs(param_1,(((long)(param_2 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                       -0x200000000,param_2 & 0xfff,param_3,1,param_4);
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  return uVar3;
}



//------------------------------------------------------------
// iommu_debug_functional_arm_dma_api_show @ 00102b88 size=640
// signature: undefined iommu_debug_functional_arm_dma_api_show(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_functional_arm_dma_api_show(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  ulong *puVar7;
  char *pcVar8;
  long lVar9;
  long *plVar10;
  long *plVar11;
  uint uVar12;
  ulong *local_90;
  ulong local_88;
  long local_80;
  long local_78 [5];
  
  lVar1 = sp_el0;
  local_78[4] = *(long *)(lVar1 + 0x638);
  lVar9 = *(long *)(param_1 + 0x80);
  local_78[1] = 0x200000;
  local_78[2] = 0xc00000;
  local_78[3] = 0;
  local_80 = 0x1000;
  local_78[0] = 0x10000;
  lVar1 = lVar9 + 0x38;
  mutex_lock(lVar1);
  lVar6 = iommu_debug_usecase_reset(lVar9);
  if (lVar6 == 0) {
    mutex_unlock(lVar1);
    uVar4 = 0xffffffea;
  }
  else {
    plVar10 = *(long **)(lVar9 + 0x20);
    uVar2 = __functional_dma_api_alloc_test(plVar10,param_1);
    uVar3 = __functional_dma_api_basic_test(plVar10,param_1);
    lVar6 = plVar10[0xe];
    if (lVar6 == 0) {
      lVar6 = *plVar10;
    }
    _printk(&DAT_0010635c,lVar6);
    seq_printf(param_1,"Map SG DMA API test");
    plVar11 = &local_80;
    lVar6 = 0x1000;
    do {
      local_90 = (ulong *)0x0;
      local_88 = 0;
      uVar4 = iommu_debug_build_phoney_sg_table(&local_90,lVar6);
      if (uVar4 != 0) {
        seq_puts(param_1,"couldn\'t build phoney sg table! bailing...\n");
        goto LAB_00102db8;
      }
      iVar5 = dma_map_sg_attrs(plVar10,local_90,local_88 & 0xffffffff,0,0);
      if (iVar5 == 0) {
        uVar4 = 0xffffffea;
        puVar7 = local_90;
      }
      else {
        uVar4 = iommu_debug_check_mapping_sg_flags
                          (plVar10,local_90,
                           ((int)local_90[1] + *(int *)((long)local_90 + 0xc) + 0xfffU >> 0xc) - 1,
                           local_88 & 0xffffffff,1,0);
        dma_unmap_sg_attrs(plVar10,local_90,local_88 & 0xffffffff,0,0);
        puVar7 = local_90;
      }
      local_90 = puVar7;
      if ((uint)local_88 != 0) {
        uVar12 = 0;
        do {
          __free_pages(*puVar7 & 0xfffffffffffffffc,0);
          uVar12 = uVar12 + 1;
          puVar7 = (ulong *)sg_next(puVar7);
        } while (uVar12 < (uint)local_88);
      }
      sg_free_table(&local_90);
      plVar11 = plVar11 + 1;
      lVar6 = *plVar11;
    } while (lVar6 != 0);
    if (uVar4 == 0) {
      lVar6 = plVar10[0xe];
      if (lVar6 == 0) {
        lVar6 = *plVar10;
      }
      _printk(&DAT_00105f38,lVar6);
      uVar4 = 0;
      pcVar8 = "  -> SUCCEEDED\n";
    }
    else {
LAB_00102db8:
      lVar6 = plVar10[0xe];
      if (lVar6 == 0) {
        lVar6 = *plVar10;
      }
      _printk(&DAT_0010616a,lVar6);
      pcVar8 = "  -> FAILED\n";
    }
    seq_printf(param_1,pcVar8);
    uVar4 = uVar3 | uVar2 | uVar4;
    mutex_unlock(lVar1);
    if (uVar4 == 0) {
      seq_puts(param_1,"SUCCESS\n");
      goto LAB_00102c10;
    }
  }
  seq_printf(param_1,"FAIL %d\n",uVar4);
LAB_00102c10:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[4]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// __functional_dma_api_alloc_test @ 00102e0c size=584
// signature: undefined __functional_dma_api_alloc_test(void)
// callers: [iommu_debug_functional_arm_dma_api_show, iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

undefined8 __functional_dma_api_alloc_test(long *param_1,undefined8 param_2)

{
  uint uVar1;
  bool bVar2;
  void *__s;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar4 = param_1[0xe];
  local_70 = 0;
  if (lVar4 == 0) {
    lVar4 = *param_1;
  }
  _printk(&DAT_0010618f,lVar4);
  seq_printf(param_2,"Allocating coherent buffer");
  __s = (void *)dma_alloc_attrs(param_1,0xb9800,&local_70,0xcc0,0);
  if (__s == (void *)0x0) {
    uVar6 = 0xfffffff4;
  }
  else {
    lVar4 = param_1[0xe];
    if (lVar4 == 0) {
      lVar4 = *param_1;
    }
    _printk(&DAT_00105f38,lVar4);
    seq_printf(param_2,"  -> SUCCEEDED\n");
    lVar4 = param_1[0xe];
    if (lVar4 == 0) {
      lVar4 = *param_1;
    }
    _printk(&DAT_0010655e,lVar4);
    seq_printf(param_2,"Using coherent buffer");
    uVar6 = 0;
    bVar2 = true;
    uVar5 = 0;
    do {
      uVar7 = uVar5 + 1;
      lVar4 = uVar5 << 10;
      uVar5 = uVar5 & 0xffffffff;
      while( true ) {
        uVar1 = (int)uVar7 + (int)(uVar5 / 0xff) * -0xff;
        memset(__s,0xa5,0xb9800);
        *(char *)((long)__s + lVar4) = (char)uVar1;
        if (uVar1 != (uVar1 & 0xff)) break;
        uVar7 = uVar7 + 1;
        lVar4 = lVar4 + 0x400;
        uVar5 = (ulong)((int)uVar5 + 1);
        if (uVar7 == 0x2e7) {
          if (bVar2) {
            lVar4 = param_1[0xe];
            if (lVar4 == 0) {
              lVar4 = *param_1;
            }
            _printk(&DAT_00105f38,lVar4);
            seq_printf(param_2,"  -> SUCCEEDED\n");
            uVar6 = 0;
          }
          goto LAB_00103000;
        }
      }
      lVar3 = param_1[0xe];
      if (lVar3 == 0) {
        lVar3 = *param_1;
      }
      uVar5 = (uint)((int)(uVar5 / 0xff) * -0xff) + uVar7;
      _printk(&DAT_00105f4e,lVar3,uVar7 - 1 & 0xffffffff,uVar1 & 0xff,uVar5 & 0xffffffff);
      seq_printf(param_2,"  -> FAILED on iter %d since %d != %d\n",uVar7 - 1 & 0xffffffff,
                 *(undefined1 *)((long)__s + lVar4),uVar5 & 0xffffffff);
      uVar6 = 0xffffffea;
      bVar2 = false;
      uVar5 = uVar7;
    } while (uVar7 != 0x2e6);
LAB_00103000:
    dma_free_attrs(param_1,0xb9800,__s,local_70,0);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// __functional_dma_api_basic_test @ 00103058 size=608
// signature: undefined __functional_dma_api_basic_test(void)
// callers: [iommu_debug_functional_arm_dma_api_show, iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __functional_dma_api_basic_test(long *param_1,undefined8 param_2)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  void *__s;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  undefined8 uVar9;
  
  lVar8 = param_1[0xe];
  if (lVar8 == 0) {
    lVar8 = *param_1;
  }
  _printk(&DAT_00106151,lVar8);
  seq_printf(param_2,"Basic DMA API test");
  iVar5 = 0;
  do {
    __s = (void *)kmalloc_trace(_seq_lseek,0xcc0,0x5ee);
    if (__s == (void *)0x0) {
      iVar4 = -0xc;
LAB_0010322c:
      lVar8 = param_1[0xe];
      if (lVar8 == 0) {
        lVar8 = *param_1;
      }
      _printk(&DAT_0010616a,lVar8);
      pcVar7 = "  -> FAILED\n";
      goto LAB_00103250;
    }
    memset(__s,0xa5,0x5ee);
    uVar6 = is_vmalloc_addr(__s);
    if (((uVar6 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar9 = dev_driver_string(param_1);
      lVar8 = param_1[0xe];
      if (lVar8 == 0) {
        lVar8 = *param_1;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar9,lVar8);
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1031f8);
      (*pcVar3)();
    }
    lVar8 = ((long)__s << 8) >> 8;
    uVar1 = lVar8 + 0x8000000000;
    if ((uVar6 & 1) == 0) {
      uVar9 = dma_map_page_attrs(param_1,(uVar1 >> 0xc) * 0x40 + -0x200000000,(ulong)__s & 0xfc0,
                                 0x5ee,1,0);
    }
    else {
      uVar9 = 0xffffffffffffffff;
    }
    lVar2 = _memstart_addr + uVar1;
    if (uVar1 >> 0x26 != 0) {
      lVar2 = lVar8 - _kimage_voffset;
    }
    iVar4 = iommu_debug_check_mapping_flags(param_1,uVar9,0x1000,lVar2,0);
    if (iVar4 != 0) goto LAB_0010322c;
    dma_unmap_page_attrs(param_1,uVar9,0x5ee,1,0);
    lVar8 = 0;
    do {
      if (*(char *)((long)__s + lVar8) != -0x5b) {
        iVar5 = ___ratelimit(__functional_dma_api_basic_test__rs,"__functional_dma_api_basic_test");
        if (iVar5 != 0) {
          _dev_err(param_1,"data[%d] != 0xa5\n",*(undefined1 *)((long)__s + lVar8));
        }
        iVar4 = -0x16;
        goto LAB_0010322c;
      }
      lVar8 = lVar8 + 1;
    } while (lVar8 != 0x5ee);
    kfree(__s);
    iVar5 = iVar5 + 1;
  } while (iVar5 != 1000);
  lVar8 = param_1[0xe];
  if (lVar8 == 0) {
    lVar8 = *param_1;
  }
  _printk(&DAT_00105f38,lVar8);
  iVar4 = 0;
  pcVar7 = "  -> SUCCEEDED\n";
LAB_00103250:
  seq_printf(param_2,pcVar7);
  return iVar4;
}



//------------------------------------------------------------
// iommu_debug_build_phoney_sg_table @ 001032bc size=276
// signature: undefined iommu_debug_build_phoney_sg_table(void)
// callers: [iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show]
//------------------------------------------------------------

undefined8 iommu_debug_build_phoney_sg_table(undefined8 *param_1,ulong param_2)

{
  bool bVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong *puVar7;
  int iVar8;
  
  if (((param_2 & 0xfff) == 0) && (iVar4 = sg_alloc_table(param_1,param_2 >> 0xc,0xcc0), iVar4 == 0)
     ) {
    if (*(int *)(param_1 + 1) != 0) {
      puVar7 = (ulong *)*param_1;
      iVar4 = -1;
      do {
        uVar5 = tpidr_el1;
        uVar6 = __alloc_pages(uVar5,0xcc0,0,0,0);
        if (uVar6 == 0) {
          if (0 < iVar4 + 1) {
            iVar8 = 0;
            puVar7 = (ulong *)*param_1;
            do {
              __free_pages(*puVar7 & 0xfffffffffffffffc,0);
              iVar8 = iVar8 + 1;
              puVar7 = (ulong *)sg_next(puVar7);
              bVar1 = iVar8 < iVar4;
              iVar4 = iVar4 + -1;
            } while (bVar1);
          }
          sg_free_table(param_1);
          return 0xfffffff4;
        }
        if ((uVar6 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1033d0);
          (*pcVar3)();
        }
        *puVar7 = *puVar7 & 3 | uVar6;
        puVar7[1] = 0x100000000000;
        puVar7 = (ulong *)sg_next(puVar7);
        uVar2 = iVar4 + 2;
        iVar4 = iVar4 + 1;
      } while (uVar2 < *(uint *)(param_1 + 1));
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// iommu_debug_functional_fast_dma_api_show @ 001033d4 size=5584
// signature: undefined iommu_debug_functional_fast_dma_api_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00103624) */
/* WARNING: Removing unreachable block (ram,0x00103a40) */

void iommu_debug_functional_fast_dma_api_show(long param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined *puVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  char *pcVar12;
  long *plVar13;
  ulong uVar14;
  ulong uVar15;
  uint uVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  bool bVar20;
  ulong *puVar21;
  undefined8 uVar22;
  long lVar23;
  long lVar24;
  long lVar25;
  undefined1 auVar26 [16];
  uint local_f4;
  uint local_f0;
  int local_ac;
  undefined8 local_a0;
  ulong local_98;
  ulong local_90 [6];
  
  lVar17 = sp_el0;
  local_90[5] = *(long *)(lVar17 + 0x638);
  lVar17 = *(long *)(param_1 + 0x80);
  plVar13 = *(long **)(lVar17 + 0x20);
  if (plVar13 == (long *)0x0) {
    _printk(&DAT_00106229,"iommu_debug_functional_fast_dma_api_show");
    uVar16 = 0xffffffea;
    goto LAB_00103578;
  }
  if (*(char *)(lVar17 + 0x34) == '\0') {
    lVar17 = plVar13[0xe];
    if (lVar17 == 0) {
      lVar17 = *plVar13;
    }
    _printk(&DAT_00106626,lVar17);
    seq_printf(param_1,"Not a fastmap usecase\n");
    uVar16 = 0;
    goto LAB_00103578;
  }
  lVar7 = lVar17 + 0x38;
  mutex_lock(lVar7);
  lVar6 = iommu_debug_usecase_reset(lVar17);
  if (lVar6 == 0) {
    mutex_unlock(lVar7);
    pcVar11 = "FAIL";
    local_f0 = 0xffffffea;
  }
  else {
    local_f0 = __functional_dma_api_alloc_test(*(undefined8 *)(lVar17 + 0x20),param_1);
    mutex_unlock(lVar7);
    pcVar11 = "SUCCESS";
    if (local_f0 != 0) {
      pcVar11 = "FAIL";
    }
  }
  seq_printf(param_1,&DAT_001061f9,pcVar11);
  lVar6 = *(long *)(param_1 + 0x80);
  lVar17 = lVar6 + 0x38;
  mutex_lock(lVar17);
  lVar7 = iommu_debug_usecase_reset(lVar6);
  if (lVar7 == 0) {
    mutex_unlock(lVar17);
    pcVar11 = "FAIL";
    local_f4 = 0xffffffea;
  }
  else {
    local_f4 = __functional_dma_api_basic_test(*(undefined8 *)(lVar6 + 0x20),param_1);
    mutex_unlock(lVar17);
    pcVar11 = "SUCCESS";
    if (local_f4 != 0) {
      pcVar11 = "FAIL";
    }
  }
  seq_printf(param_1,&DAT_001061f9,pcVar11);
  lVar7 = *(long *)(param_1 + 0x80);
  lVar17 = lVar7 + 0x38;
  local_90[0] = 0x1000;
  local_90[1] = 0x2000;
  local_90[2] = 0x4000;
  local_90[3] = 0x10000;
  local_90[4] = 0;
  mutex_lock(lVar17);
  plVar13 = *(long **)(lVar7 + 0x20);
  if (plVar13 == (long *)0x0) {
    mutex_unlock(lVar17);
    uVar16 = 0xffffffed;
  }
  else {
    lVar7 = plVar13[0xe];
    if (lVar7 == 0) {
      lVar7 = *plVar13;
    }
    lVar7 = kstrdup(lVar7,0xcc0);
    mutex_unlock(lVar17);
    if (lVar7 != 0) {
      lVar17 = 0;
      uVar16 = 0;
      lVar6 = 0x1000;
      do {
        lVar18 = lVar17;
        if (lVar6 < 0x4000) {
          pcVar11 = "4K";
          if (lVar6 != 0x1000) {
            if (lVar6 != 0x2000) {
              if (lVar6 != 0) goto LAB_00103628;
              _printk(&DAT_00106376,lVar7,&DAT_00105fb8);
              seq_printf(param_1,"bonus map:");
              lVar18 = *(long *)(param_1 + 0x80);
              lVar17 = lVar18 + 0x38;
              mutex_lock(lVar17);
              lVar6 = iommu_debug_usecase_reset(lVar18);
              if (lVar6 == 0) {
                mutex_unlock(lVar17);
                seq_printf(param_1,&DAT_001061f9,&DAT_00105a70);
LAB_001039f4:
                uVar16 = 0xffffffea;
                pcVar11 = "  -> FAILED\n";
                puVar8 = &DAT_0010616a;
              }
              else {
                iVar2 = __full_va_sweep(*(undefined8 *)(lVar18 + 0x20),
                                        *(undefined8 *)(lVar18 + 0x28),0x1000);
                mutex_unlock(lVar17);
                pcVar11 = "SUCCESS";
                if (iVar2 != 0) {
                  pcVar11 = "FAIL";
                }
                seq_printf(param_1,&DAT_001061f9,pcVar11);
                if (iVar2 != 0) goto LAB_001039f4;
                pcVar11 = "  -> SUCCEEDED\n";
                puVar8 = &DAT_00105f38;
              }
              _printk(puVar8,lVar7);
              seq_printf(param_1,pcVar11);
              lVar17 = 0;
              puVar21 = local_90;
              uVar14 = 0x1000;
              goto LAB_00104224;
            }
            pcVar11 = "8K";
          }
        }
        else if (lVar6 == 0x4000) {
          pcVar11 = "16K";
        }
        else if (lVar6 == 0x10000) {
          pcVar11 = "64K";
        }
        else {
          if (lVar6 != 0x100000) goto LAB_00103628;
          pcVar11 = "1M";
        }
LAB_00103644:
        _printk(&DAT_001062f9,lVar7,pcVar11);
        lVar17 = *(long *)((long)local_90 + lVar18);
        if (lVar17 < 0x200000) {
          if (lVar17 < 0x4000) {
            pcVar11 = "4K";
            if (lVar17 != 0x1000) {
              if (lVar17 != 0x2000) goto LAB_0010373c;
              pcVar11 = "8K";
            }
          }
          else if (lVar17 == 0x4000) {
            pcVar11 = "16K";
          }
          else if (lVar17 == 0x10000) {
            pcVar11 = "64K";
          }
          else {
            if (lVar17 != 0x100000) goto LAB_0010373c;
            pcVar11 = "1M";
          }
        }
        else if (lVar17 < 0x1400000) {
          if (lVar17 == 0x200000) {
            pcVar11 = "2M";
          }
          else if (lVar17 == 0xc00000) {
            pcVar11 = "12M";
          }
          else {
LAB_0010373c:
            _printk(&DAT_00106291,"_size_to_string");
            pcVar11 = "unknown size";
          }
        }
        else if (lVar17 == 0x1400000) {
          pcVar11 = "20M";
        }
        else if (lVar17 == 0x1800000) {
          pcVar11 = "24M";
        }
        else {
          if (lVar17 != 0x2000000) goto LAB_0010373c;
          pcVar11 = "32M";
        }
        seq_printf(param_1,"Full VA sweep @%s:",pcVar11);
        lVar25 = *(long *)(param_1 + 0x80);
        uVar22 = *(undefined8 *)((long)local_90 + lVar18);
        lVar17 = lVar25 + 0x38;
        mutex_lock(lVar17);
        lVar6 = iommu_debug_usecase_reset(lVar25);
        if (lVar6 == 0) {
          mutex_unlock(lVar17);
          seq_printf(param_1,&DAT_001061f9,&DAT_00105a70);
          uVar16 = 0xffffffea;
          puVar8 = &DAT_0010616a;
          pcVar11 = "  -> FAILED\n";
        }
        else {
          iVar2 = __full_va_sweep(*(undefined8 *)(lVar25 + 0x20),*(undefined8 *)(lVar25 + 0x28),
                                  uVar22);
          mutex_unlock(lVar17);
          pcVar11 = "SUCCESS";
          if (iVar2 != 0) {
            pcVar11 = "FAIL";
          }
          seq_printf(param_1,&DAT_001061f9,pcVar11);
          if (iVar2 == 0) {
            puVar8 = &DAT_00105f38;
            pcVar11 = "  -> SUCCEEDED\n";
          }
          else {
            uVar16 = 0xffffffea;
            puVar8 = &DAT_0010616a;
            pcVar11 = "  -> FAILED\n";
          }
        }
        _printk(puVar8,lVar7);
        seq_printf(param_1,pcVar11);
        if ((lVar18 - 0x20U < 0xffffffffffffffd8) || (lVar18 == 0x20)) {
LAB_00104568:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x10456c);
          (*pcVar1)();
        }
        lVar17 = lVar18 + 8;
        lVar6 = *(long *)((long)local_90 + lVar18 + 8);
        if (0x1fffff < lVar6) {
          lVar18 = lVar17;
          if (lVar6 < 0x1400000) {
            if (lVar6 == 0x200000) {
              pcVar11 = "2M";
            }
            else {
              if (lVar6 != 0xc00000) goto LAB_00103628;
              pcVar11 = "12M";
            }
          }
          else if (lVar6 == 0x1400000) {
            pcVar11 = "20M";
          }
          else if (lVar6 == 0x1800000) {
            pcVar11 = "24M";
          }
          else if (lVar6 == 0x2000000) {
            pcVar11 = "32M";
          }
          else {
LAB_00103628:
            _printk(&DAT_00106291,"_size_to_string");
            pcVar11 = "unknown size";
            lVar18 = lVar17;
          }
          goto LAB_00103644;
        }
      } while( true );
    }
    uVar16 = 0xfffffff4;
  }
  goto LAB_0010356c;
LAB_00104224:
  if ((long)uVar14 < 0x4000) {
    pcVar11 = "4K";
    if (uVar14 != 0x1000) {
      if (uVar14 != 0x2000) {
        if (uVar14 != 0) goto LAB_00103a44;
        _printk(&DAT_00105a75,lVar7,&DAT_00105fb8);
        seq_printf(param_1,"TLB stress sweep:");
        lVar18 = *(long *)(param_1 + 0x80);
        lVar17 = lVar18 + 0x38;
        mutex_lock(lVar17);
        lVar6 = iommu_debug_usecase_reset(lVar18);
        if (lVar6 == 0) {
          mutex_unlock(lVar17);
          seq_printf(param_1,&DAT_001061f9,&DAT_00105a70);
          uVar16 = 0xffffffea;
          pcVar11 = "  -> FAILED\n";
          puVar8 = &DAT_0010616a;
          goto LAB_00104854;
        }
        plVar13 = *(long **)(lVar18 + 0x20);
        local_98 = 0;
        auVar26 = __get_free_pages(0xcc0,1);
        uVar10 = auVar26._8_8_;
        uVar9 = auVar26._0_8_;
        iVar2 = 0;
        uVar14 = 0;
        iVar3 = 0;
        uVar15 = uVar9 & 0xfff;
        lVar6 = (((long)(uVar9 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
        goto LAB_00104370;
      }
      pcVar11 = "8K";
    }
  }
  else if (uVar14 == 0x4000) {
    pcVar11 = "16K";
  }
  else if (uVar14 == 0x10000) {
    pcVar11 = "64K";
  }
  else {
    if (uVar14 != 0x100000) goto LAB_00103a44;
    pcVar11 = "1M";
  }
LAB_00103a60:
  pcVar12 = "FAIL";
  _printk(&DAT_00106481,lVar7,pcVar11);
  uVar14 = *puVar21;
  if ((long)uVar14 < 0x200000) {
    if ((long)uVar14 < 0x4000) {
      pcVar11 = "4K";
      if (uVar14 != 0x1000) {
        if (uVar14 != 0x2000) goto LAB_00103b5c;
        pcVar11 = "8K";
      }
    }
    else if (uVar14 == 0x4000) {
      pcVar11 = "16K";
    }
    else if (uVar14 == 0x10000) {
      pcVar11 = "64K";
    }
    else {
      if (uVar14 != 0x100000) goto LAB_00103b5c;
      pcVar11 = "1M";
    }
  }
  else if ((long)uVar14 < 0x1400000) {
    if (uVar14 == 0x200000) {
      pcVar11 = "2M";
    }
    else if (uVar14 == 0xc00000) {
      pcVar11 = "12M";
    }
    else {
LAB_00103b5c:
      _printk(&DAT_00106291,"_size_to_string");
      pcVar11 = "unknown size";
    }
  }
  else if (uVar14 == 0x1400000) {
    pcVar11 = "20M";
  }
  else if (uVar14 == 0x1800000) {
    pcVar11 = "24M";
  }
  else {
    if (uVar14 != 0x2000000) goto LAB_00103b5c;
    pcVar11 = "32M";
  }
  seq_printf(param_1,"Rand VA sweep @%s:",pcVar11);
  lVar25 = *(long *)(param_1 + 0x80);
  uVar14 = *puVar21;
  lVar6 = lVar25 + 0x38;
  mutex_lock(lVar6);
  lVar18 = iommu_debug_usecase_reset(lVar25);
  if (lVar18 == 0) {
LAB_00104068:
    mutex_unlock(lVar6);
    uVar16 = 0xffffffea;
    puVar8 = &DAT_0010616a;
    pcVar11 = "  -> FAILED\n";
  }
  else {
    plVar13 = *(long **)(lVar25 + 0x20);
    iVar2 = 0;
    if (0xfff < uVar14 - 1) {
      iVar2 = 0x40 - (int)LZCOUNT(uVar14 - 1 >> 0xc);
    }
    uVar9 = __get_free_pages(0xcc0);
    if (uVar9 == 0) {
      if (uVar14 < 0x2001) goto LAB_00104068;
      iVar2 = ___ratelimit(__rand_va_sweep__rs,"__rand_va_sweep");
      if (iVar2 != 0) {
        if ((long)uVar14 < 0x200000) {
          if ((long)uVar14 < 0x4000) {
            pcVar11 = "4K";
            if (uVar14 != 0x1000) {
              if (uVar14 != 0x2000) goto LAB_00104108;
              pcVar11 = "8K";
            }
          }
          else if (uVar14 == 0x4000) {
            pcVar11 = "16K";
          }
          else if (uVar14 == 0x10000) {
            pcVar11 = "64K";
          }
          else {
            if (uVar14 != 0x100000) goto LAB_00104108;
            pcVar11 = "1M";
          }
        }
        else if ((long)uVar14 < 0x1400000) {
          if (uVar14 == 0x200000) {
            pcVar11 = "2M";
          }
          else if (uVar14 == 0xc00000) {
            pcVar11 = "12M";
          }
          else {
LAB_00104108:
            _printk(&DAT_00106291,"_size_to_string");
            pcVar11 = "unknown size";
          }
        }
        else if (uVar14 == 0x1400000) {
          pcVar11 = "20M";
        }
        else if (uVar14 == 0x1800000) {
          pcVar11 = "24M";
        }
        else {
          if (uVar14 != 0x2000000) goto LAB_00104108;
          pcVar11 = "32M";
        }
        _dev_err(plVar13,
                 "Failed to allocate %s of memory, which is a lot. Skipping test for this size\n",
                 pcVar11);
      }
      mutex_unlock(lVar6);
    }
    else {
      local_ac = 0;
      iVar3 = 0;
      lVar18 = (((long)(uVar9 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
      uVar10 = 0;
      do {
        if (uVar10 == 0x8000000) {
          uVar10 = 0x8100000 - uVar14;
        }
        else {
          uVar15 = is_vmalloc_addr();
          if (((uVar15 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
            dma_map_single_attrs___already_done = 1;
            uVar22 = dev_driver_string(plVar13);
            lVar17 = plVar13[0xe];
            if (lVar17 == 0) {
              lVar17 = *plVar13;
            }
            __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103d34);
            (*pcVar1)();
          }
          if (((uVar15 & 1) != 0) ||
             (uVar15 = dma_map_page_attrs(plVar13,lVar18,uVar9 & 0xfff,uVar14,1,0),
             uVar15 == 0xffffffffffffffff)) {
            iVar5 = ___ratelimit(__rand_va_sweep__rs_108,"__rand_va_sweep");
            if (iVar5 != 0) {
              _dev_err(plVar13,"Failed map on iter %d\n",iVar3);
            }
            goto LAB_00103d6c;
          }
          if (uVar15 != uVar10) {
            dma_unmap_page_attrs(plVar13,uVar15,uVar14,1,0);
            iVar3 = ___ratelimit(__rand_va_sweep__rs_110,"__rand_va_sweep");
            if (iVar3 != 0) {
              _dev_err(plVar13,"Unexpected dma_addr. got: %lx, expected: %lx\n",uVar15,uVar10);
            }
            bVar20 = false;
            goto LAB_00103f30;
          }
          local_ac = local_ac + 1;
        }
        uVar10 = uVar10 + uVar14;
        iVar3 = iVar3 + 1;
      } while (uVar10 < 0xffffffff);
      uVar10 = uVar14 << 1;
      if (uVar10 < 0xffffffff - uVar14) {
        iVar3 = 0;
        lVar25 = 1;
        lVar24 = 2;
        do {
          uVar15 = 0x100000000 - (uVar10 + uVar14);
          if (uVar10 == uVar15) {
            __warn_printk("%s test needs update! The random number sequence is folding in on itself and should be changed.\n"
                          ,"__rand_va_sweep");
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x800,0x104050);
            (*pcVar1)();
          }
          if (uVar10 >> 0x14 != 0x80) {
            dma_unmap_page_attrs(plVar13,uVar10,uVar14,1,0);
          }
          if (0xfffff < (uVar10 + uVar14) - 0xf7f00001) {
            dma_unmap_page_attrs(plVar13,uVar15,uVar14,1,0);
          }
          lVar23 = (long)((int)lVar24 + (int)lVar25);
          iVar3 = iVar3 + 2;
          uVar10 = lVar23 * uVar14;
          lVar25 = lVar24;
          lVar24 = lVar23;
        } while (uVar10 < 0xffffffff - uVar14);
      }
      else {
        iVar3 = 0;
      }
      iVar5 = 0;
      while( true ) {
        uVar10 = is_vmalloc_addr(uVar9);
        if (((uVar10 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar22 = dev_driver_string(plVar13);
          lVar17 = plVar13[0xe];
          if (lVar17 == 0) {
            lVar17 = *plVar13;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103ebc);
          (*pcVar1)();
        }
        if (((uVar10 & 1) != 0) ||
           (lVar25 = dma_map_page_attrs(plVar13,lVar18,uVar9 & 0xfff,uVar14,1,0), lVar25 == -1))
        break;
        iVar5 = iVar5 + 1;
      }
      if (iVar3 == iVar5) {
        bVar20 = true;
      }
      else {
        iVar4 = ___ratelimit(__rand_va_sweep__rs_113,"__rand_va_sweep");
        if (iVar4 != 0) {
          _dev_err(plVar13,"Unexpected random remap count! Unmapped %d but remapped %d\n",iVar3,
                   iVar5);
        }
LAB_00103d6c:
        bVar20 = false;
      }
LAB_00103f30:
      uVar10 = 0;
      local_ac = local_ac + 1;
      do {
        local_ac = local_ac + -1;
        if (local_ac == 0) break;
        uVar15 = 0x8100000 - uVar14;
        if (uVar10 != 0x8000000) {
          dma_unmap_page_attrs(plVar13,uVar10,uVar14,1,0);
          uVar15 = uVar10;
        }
        uVar10 = uVar15 + uVar14;
      } while (uVar10 < 0xffffffff);
      free_pages(uVar9,iVar2);
      mutex_unlock(lVar6);
      if (!bVar20) {
        uVar16 = 0xffffffea;
        pcVar12 = "FAIL";
        puVar8 = &DAT_0010616a;
        pcVar11 = "  -> FAILED\n";
        goto LAB_00104158;
      }
    }
    pcVar12 = "SUCCESS";
    puVar8 = &DAT_00105f38;
    pcVar11 = "  -> SUCCEEDED\n";
  }
LAB_00104158:
  seq_printf(param_1,&DAT_001061f9,pcVar12);
  _printk(puVar8,lVar7);
  seq_printf(param_1,pcVar11);
  if ((lVar17 - 0x20U < 0xffffffffffffffd8) || (lVar17 == 0x20)) goto LAB_00104568;
  puVar21 = puVar21 + 1;
  uVar14 = *puVar21;
  lVar17 = lVar17 + 8;
  if (0x1fffff < (long)uVar14) {
    if ((long)uVar14 < 0x1400000) {
      if (uVar14 == 0x200000) {
        pcVar11 = "2M";
      }
      else {
        if (uVar14 != 0xc00000) goto LAB_00103a44;
        pcVar11 = "12M";
      }
    }
    else if (uVar14 == 0x1400000) {
      pcVar11 = "20M";
    }
    else if (uVar14 == 0x1800000) {
      pcVar11 = "24M";
    }
    else if (uVar14 == 0x2000000) {
      pcVar11 = "32M";
    }
    else {
LAB_00103a44:
      _printk(&DAT_00106291,"_size_to_string");
      pcVar11 = "unknown size";
    }
    goto LAB_00103a60;
  }
  goto LAB_00104224;
LAB_00104370:
  do {
    if (uVar14 != 0x8000000) {
      uVar10 = is_vmalloc_addr(uVar9,uVar10);
      if (((uVar10 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
        dma_map_single_attrs___already_done = 1;
        uVar22 = dev_driver_string(plVar13);
        lVar17 = plVar13[0xe];
        if (lVar17 == 0) {
          lVar17 = *plVar13;
        }
        __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10440c);
        (*pcVar1)();
      }
      if ((uVar10 & 1) == 0) {
        uVar10 = dma_map_page_attrs(plVar13,lVar6,uVar15,0x2000,1,0);
        local_98 = uVar10;
        if (uVar10 == 0xffffffffffffffff) goto LAB_00104418;
        if (uVar10 == uVar14) {
          iVar3 = iVar3 + 1;
          uVar19 = uVar14;
          goto LAB_0010435c;
        }
        dma_unmap_page_attrs(plVar13,uVar10,0x2000,1,0);
        iVar5 = ___ratelimit(__tlb_stress_sweep__rs_115,"__tlb_stress_sweep");
      }
      else {
        local_98 = 0xffffffffffffffff;
LAB_00104418:
        iVar5 = ___ratelimit(__tlb_stress_sweep__rs,"__tlb_stress_sweep");
      }
      if (iVar5 != 0) {
        _dev_err(plVar13,"Failed map on iter %d\n",iVar2);
      }
      goto LAB_00104530;
    }
    uVar19 = 0x80fe000;
LAB_0010435c:
    uVar14 = uVar19 + 0x2000;
    iVar2 = iVar2 + 1;
  } while (uVar19 < 0xffffdfff);
  uVar14 = is_vmalloc_addr(uVar9,uVar10);
  if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar22 = dev_driver_string(plVar13);
    lVar17 = plVar13[0xe];
    if (lVar17 == 0) {
      lVar17 = *plVar13;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1045a0);
    (*pcVar1)();
  }
  if (((uVar14 & 1) == 0) &&
     (lVar18 = dma_map_page_attrs(plVar13,lVar6,uVar15,0x1000,1,0), lVar18 != -1)) {
    iVar2 = ___ratelimit(__tlb_stress_sweep__rs_116,"__tlb_stress_sweep");
    if (iVar2 != 0) {
      pcVar11 = "dma_map_single unexpectedly (VA should have been exhausted)\n";
LAB_0010455c:
      _dev_err(plVar13,pcVar11);
    }
LAB_00104530:
    uVar14 = 0;
LAB_0010479c:
    bVar20 = false;
    pcVar11 = "FAIL";
  }
  else {
    dma_unmap_page_attrs(plVar13,0,0x1000,1,0);
    dma_unmap_page_attrs(plVar13,0x2000,0x1000,1,0);
    dma_unmap_page_attrs(plVar13,0x3000,0x1000,1,0);
    uVar14 = is_vmalloc_addr(uVar9);
    if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar22 = dev_driver_string(plVar13);
      lVar17 = plVar13[0xe];
      if (lVar17 == 0) {
        lVar17 = *plVar13;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1045e0);
      (*pcVar1)();
    }
    if ((uVar14 & 1) != 0) {
      local_98 = 0xffffffffffffffff;
LAB_0010463c:
      local_a0 = 0x2000;
      iVar2 = ___ratelimit(__tlb_stress_sweep__rs_118,"__tlb_stress_sweep");
      if (iVar2 != 0) {
        _dev_err(plVar13,"Unexpected dma_addr. got: %pa expected: %pa\n",&local_98,&local_a0);
      }
      dma_unmap_page_attrs(plVar13,0x1000,0x1000,1,0);
      dma_unmap_page_attrs(plVar13,0x3000,0x1000,1,0);
      iVar3 = iVar3 + -2;
      uVar14 = 0x4000;
      goto LAB_0010479c;
    }
    local_98 = dma_map_page_attrs(plVar13,lVar6,uVar15,0x2000,1,0);
    if (local_98 != 0x2000) goto LAB_0010463c;
    uVar14 = is_vmalloc_addr(uVar9);
    if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar22 = dev_driver_string(plVar13);
      lVar17 = plVar13[0xe];
      if (lVar17 == 0) {
        lVar17 = *plVar13;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1046ec);
      (*pcVar1)();
    }
    if ((uVar14 & 1) != 0) {
      local_98 = 0xffffffffffffffff;
LAB_00104744:
      local_a0 = 0;
      iVar2 = ___ratelimit(__tlb_stress_sweep__rs_120,"__tlb_stress_sweep");
      if (iVar2 != 0) {
        _dev_err(plVar13,"Unexpected dma_addr. got: %pa expected: %pa\n",&local_98,&local_a0);
      }
      dma_unmap_page_attrs(plVar13,0x1000,0x1000,1,0);
      iVar3 = iVar3 + -1;
      uVar14 = 0x2000;
      goto LAB_0010479c;
    }
    local_98 = dma_map_page_attrs(plVar13,lVar6,uVar15,0x1000,1,0);
    if (local_98 != 0) goto LAB_00104744;
    uVar14 = is_vmalloc_addr(uVar9);
    if (((uVar14 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar22 = dev_driver_string(plVar13);
      lVar17 = plVar13[0xe];
      if (lVar17 == 0) {
        lVar17 = *plVar13;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar22,lVar17);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x104988);
      (*pcVar1)();
    }
    if (((uVar14 & 1) == 0) &&
       (lVar6 = dma_map_page_attrs(plVar13,lVar6,uVar15,0x1000,1,0), lVar6 != -1)) {
      iVar2 = ___ratelimit(__tlb_stress_sweep__rs_121,"__tlb_stress_sweep");
      if (iVar2 != 0) {
        pcVar11 = "dma_map_single unexpectedly after remaps (VA should have been exhausted)\n";
        goto LAB_0010455c;
      }
      goto LAB_00104530;
    }
    bVar20 = true;
    uVar14 = 0;
    pcVar11 = "SUCCESS";
  }
  iVar3 = iVar3 + 1;
  do {
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) break;
    uVar10 = 0x80fe000;
    if (uVar14 != 0x8000000) {
      dma_unmap_page_attrs(plVar13,uVar14,0x2000,1,0);
      uVar10 = uVar14;
    }
    uVar14 = uVar10 + 0x2000;
  } while (uVar10 < 0xffffdfff);
  free_pages(uVar9,1);
  mutex_unlock(lVar17);
  seq_printf(param_1,&DAT_001061f9,pcVar11);
  if (bVar20) {
    pcVar11 = "  -> SUCCEEDED\n";
    puVar8 = &DAT_00105f38;
  }
  else {
    uVar16 = 0xffffffea;
    pcVar11 = "  -> FAILED\n";
    puVar8 = &DAT_0010616a;
  }
LAB_00104854:
  _printk(puVar8,lVar7);
  seq_printf(param_1,pcVar11);
  _printk(&DAT_00105bd4,lVar7);
  seq_printf(param_1,"second bonus map:");
  lVar18 = *(long *)(param_1 + 0x80);
  lVar17 = lVar18 + 0x38;
  mutex_lock(lVar17);
  lVar6 = iommu_debug_usecase_reset(lVar18);
  if (lVar6 == 0) {
    mutex_unlock(lVar17);
    seq_printf(param_1,&DAT_001061f9,&DAT_00105a70);
LAB_0010491c:
    uVar16 = 0xffffffea;
    pcVar11 = "  -> FAILED\n";
    puVar8 = &DAT_0010616a;
  }
  else {
    iVar2 = __full_va_sweep(*(undefined8 *)(lVar18 + 0x20),*(undefined8 *)(lVar18 + 0x28),0x1000);
    mutex_unlock(lVar17);
    pcVar11 = "SUCCESS";
    if (iVar2 != 0) {
      pcVar11 = "FAIL";
    }
    seq_printf(param_1,&DAT_001061f9,pcVar11);
    if (iVar2 != 0) goto LAB_0010491c;
    pcVar11 = "  -> SUCCEEDED\n";
    puVar8 = &DAT_00105f38;
  }
  _printk(puVar8,lVar7);
  seq_printf(param_1,pcVar11);
  kfree(lVar7);
LAB_0010356c:
  uVar16 = local_f4 | local_f0 | uVar16;
LAB_00103578:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_90[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar16);
  }
  return;
}



//------------------------------------------------------------
// _size_to_string @ 001049ec size=288
// signature: undefined _size_to_string(void)
// callers: [__full_va_sweep]
//------------------------------------------------------------

char * _size_to_string(long param_1)

{
  if (param_1 < 0x200000) {
    if (param_1 < 0x4000) {
      if (param_1 == 0x1000) {
        return "4K";
      }
      if (param_1 == 0x2000) {
        return "8K";
      }
    }
    else {
      if (param_1 == 0x4000) {
        return "16K";
      }
      if (param_1 == 0x10000) {
        return "64K";
      }
      if (param_1 == 0x100000) {
        return "1M";
      }
    }
  }
  else if (param_1 < 0x1400000) {
    if (param_1 == 0x200000) {
      return "2M";
    }
    if (param_1 == 0xc00000) {
      return "12M";
    }
  }
  else {
    if (param_1 == 0x1400000) {
      return "20M";
    }
    if (param_1 == 0x1800000) {
      return "24M";
    }
    if (param_1 == 0x2000000) {
      return "32M";
    }
  }
  _printk(&DAT_00106291,"_size_to_string");
  return "unknown size";
}



//------------------------------------------------------------
// __full_va_sweep @ 00104b10 size=1084
// signature: undefined __full_va_sweep(void)
// callers: [iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __full_va_sweep(long *param_1,long param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  undefined1 *puVar9;
  long lVar10;
  undefined8 uVar11;
  int iVar12;
  ulong uVar13;
  
  iVar3 = 0;
  if (0xfff < param_3 - 1) {
    iVar3 = 0x40 - (int)LZCOUNT(param_3 - 1 >> 0xc);
  }
  uVar6 = __get_free_pages(0xcc0,iVar3);
  if (uVar6 == 0) {
    if (param_3 < 0x2001) {
      uVar11 = 0xfffffff4;
    }
    else {
      iVar3 = ___ratelimit(__full_va_sweep__rs,"__full_va_sweep");
      if (iVar3 == 0) {
        uVar11 = 0;
      }
      else {
        uVar11 = _size_to_string(param_3);
        _dev_err(param_1,
                 "Failed to allocate %s of memory, which is a lot. Skipping test for this size\n",
                 uVar11);
        uVar11 = 0;
      }
    }
  }
  else {
    lVar1 = (long)(uVar6 << 8) >> 8;
    uVar7 = lVar1 + 0x8000000000;
    iVar5 = 0;
    uVar13 = 0;
    iVar12 = 0;
    lVar8 = _memstart_addr + uVar7;
    if (uVar7 >> 0x26 != 0) {
      lVar8 = lVar1 - _kimage_voffset;
    }
    lVar1 = (uVar7 >> 0xc) * 0x40 + -0x200000000;
    do {
      if (uVar13 != 0x8000000) {
        uVar7 = is_vmalloc_addr(uVar6);
        if (((uVar7 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
          dma_map_single_attrs___already_done = 1;
          uVar11 = dev_driver_string(param_1);
          lVar8 = param_1[0xe];
          if (lVar8 == 0) {
            lVar8 = *param_1;
          }
          __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar11,lVar8);
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104c78);
          (*pcVar2)();
        }
        if ((uVar7 & 1) == 0) {
          uVar7 = dma_map_page_attrs(param_1,lVar1,uVar6 & 0xfff,param_3,1,0);
          if (uVar7 == uVar13) {
            iVar12 = iVar12 + 1;
            goto LAB_00104be0;
          }
        }
        else {
          uVar7 = 0xffffffffffffffff;
        }
        iVar4 = ___ratelimit(__full_va_sweep__rs_97,"__full_va_sweep");
        if (iVar4 != 0) {
          _dev_err(param_1,"Unexpected iova on iter %d (expected: 0x%lx got: 0x%lx)\n",iVar5,uVar13,
                   uVar7);
        }
        if (uVar7 != 0xffffffffffffffff) {
          dma_unmap_page_attrs(param_1,uVar7,param_3,1,0);
        }
        uVar11 = 0xffffffea;
        goto LAB_00104ecc;
      }
      uVar13 = 0x8100000 - param_3;
LAB_00104be0:
      uVar13 = uVar13 + param_3;
      iVar5 = iVar5 + 1;
    } while (uVar13 < 0xffffffff);
    if (param_2 != 0) {
      iVar5 = 0;
      uVar7 = 0;
      do {
        iVar4 = __check_mapping(param_1,param_2,uVar7,lVar8);
        if (iVar4 != 0) {
          puVar9 = __full_va_sweep__rs_99;
          goto LAB_00104df4;
        }
        uVar7 = uVar7 + param_3;
        iVar5 = iVar5 + 1;
      } while (uVar7 < 0x600000);
      iVar5 = 0;
      uVar7 = 0;
      lVar10 = 0x100000000 - param_3;
LAB_00104cf8:
      iVar4 = __check_mapping(param_1,param_2,lVar10,lVar8);
      if (iVar4 == 0) goto code_r0x00104d10;
      puVar9 = __full_va_sweep__rs_101;
LAB_00104df4:
      iVar4 = ___ratelimit(puVar9,"__full_va_sweep");
      if (iVar4 != 0) {
        _dev_err(param_1,"iter: %d\n",iVar5);
      }
      uVar11 = 0xffffffea;
      goto LAB_00104ecc;
    }
LAB_00104d24:
    uVar7 = is_vmalloc_addr(uVar6);
    if (((uVar7 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar11 = dev_driver_string(param_1);
      lVar8 = param_1[0xe];
      if (lVar8 == 0) {
        lVar8 = *param_1;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar11,lVar8);
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104ec0);
      (*pcVar2)();
    }
    if (((uVar7 & 1) == 0) &&
       (lVar8 = dma_map_page_attrs(param_1,lVar1,uVar6 & 0xfff,param_3,1,0), lVar8 != -1)) {
      iVar5 = ___ratelimit(__full_va_sweep__rs_102,"__full_va_sweep");
      if (iVar5 != 0) {
        _dev_err(param_1,"dma_map_single succeeded when it should have failed. Got iova: 0x%lx\n",
                 lVar8);
      }
      uVar11 = 0xffffffea;
    }
    else {
      uVar11 = 0;
    }
LAB_00104ecc:
    uVar7 = 0;
    iVar12 = iVar12 + 1;
    do {
      iVar12 = iVar12 + -1;
      if (iVar12 == 0) break;
      uVar13 = 0x8100000 - param_3;
      if (uVar7 != 0x8000000) {
        dma_unmap_page_attrs(param_1,uVar7,param_3,1,0);
        uVar13 = uVar7;
      }
      uVar7 = uVar13 + param_3;
    } while (uVar7 < 0xffffffff);
    free_pages(uVar6,iVar3);
  }
  return uVar11;
code_r0x00104d10:
  uVar7 = uVar7 + param_3;
  iVar5 = iVar5 + 1;
  lVar10 = lVar10 - param_3;
  if (0x5fffff < uVar7) goto LAB_00104d24;
  goto LAB_00104cf8;
}



//------------------------------------------------------------
// __check_mapping @ 00104f54 size=320
// signature: undefined __check_mapping(void)
// callers: [__full_va_sweep]
//------------------------------------------------------------

void __check_mapping(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_70;
  undefined4 local_68;
  uint uStack_64;
  long local_60;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = param_4;
  local_50 = param_3;
  if ((*(long *)(param_1 + 0x338) == 0) ||
     (lVar5 = *(long *)(*(long *)(param_1 + 0x338) + 0x40), lVar5 == 0)) {
    iVar2 = ___ratelimit(__check_mapping__rs,"__check_mapping");
    if (iVar2 != 0) {
      _dev_err(param_1,"No fwspec.\n");
    }
  }
  else {
    uStack_64 = (uint)*(ushort *)(lVar5 + 0x18);
    local_68 = 0;
    local_70 = param_3;
    lVar5 = qcom_iommu_iova_to_phys_hard(param_2,&local_70);
    local_60 = lVar5;
    lVar3 = iommu_iova_to_phys(param_2,param_3);
    if (lVar5 != lVar3) {
      __warn_printk("hard/soft iova_to_phys fns don\'t agree...");
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105024);
      (*pcVar1)();
    }
    if (lVar5 == param_4) {
      uVar4 = 0;
      goto LAB_00105048;
    }
    iVar2 = ___ratelimit(__check_mapping__rs_106,"__check_mapping");
    if (iVar2 != 0) {
      _dev_err(param_1,"Bad translation for %pa! Expected: %pa Got: %pa\n",&local_50,&local_58,
               &local_60);
    }
  }
  uVar4 = 0xffffffea;
LAB_00105048:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// iommu_debug_profiling_show @ 001050a0 size=1612
// signature: undefined iommu_debug_profiling_show(void)
// callers: []
//------------------------------------------------------------

undefined8 iommu_debug_profiling_show(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong *puVar7;
  char *pcVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  long *plVar14;
  ulong uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong *local_78;
  undefined8 local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  lVar11 = *(long *)(param_1 + 0x80);
  mutex_lock();
  lVar2 = iommu_debug_usecase_reset(lVar11);
  if (lVar2 != 0) {
    uVar12 = *(undefined8 *)(lVar11 + 0x28);
    seq_printf(param_1,"(average over %d iterations)\n",*(undefined4 *)(lVar11 + 0x90));
    seq_printf(param_1,"%8s %19s %16s\n",&DAT_00105916,"iommu_map","iommu_unmap");
    plVar14 = (long *)&DAT_00107f18;
    lVar2 = 0x1000;
    do {
      if (*(int *)(lVar11 + 0x90) == 0) {
        uVar16 = 0;
        uVar13 = 0;
        uVar10 = 0;
      }
      else {
        uVar17 = 0;
        uVar13 = 0;
        uVar16 = 0;
        uVar10 = 0;
        if (lVar2 + -1 != 0) {
          uVar10 = ~(-1L << (-LZCOUNT(lVar2 + -1) & 0x3fU));
        }
        uVar15 = uVar10 + 0x10000 & (uVar10 ^ 0xffffffffffffffff);
        do {
          lVar3 = ktime_get();
          iVar1 = iommu_map(uVar12,uVar15,lVar2 + 0x7fffffffU & -lVar2,lVar2,3);
          if (iVar1 == 0) {
            lVar4 = ktime_get();
            uVar16 = (lVar4 - lVar3) + uVar16;
            lVar3 = ktime_get();
            lVar4 = iommu_unmap(uVar12,uVar15,lVar2);
            if (lVar4 == lVar2) {
              lVar4 = ktime_get();
              uVar13 = (uVar13 - lVar3) + lVar4;
            }
            else {
              seq_printf(param_1,"Only unmapped %zx instead of %zx\n",lVar4,lVar2);
            }
          }
          else {
            seq_puts(param_1,"Failed to map\n");
          }
          uVar10 = (ulong)*(uint *)(lVar11 + 0x90);
          uVar17 = uVar17 + 1;
        } while (uVar17 < uVar10);
      }
      if (lVar2 < 0x200000) {
        if (lVar2 < 0x4000) {
          pcVar8 = "4K";
          if (lVar2 != 0x1000) {
            if (lVar2 == 0x2000) {
              pcVar8 = "8K";
            }
            else {
LAB_00105374:
              _printk(&DAT_00106291,"_size_to_string");
              pcVar8 = "unknown size";
            }
          }
        }
        else if (lVar2 == 0x4000) {
          pcVar8 = "16K";
        }
        else if (lVar2 == 0x10000) {
          pcVar8 = "64K";
        }
        else {
          if (lVar2 != 0x100000) goto LAB_00105374;
          pcVar8 = "1M";
        }
      }
      else if (lVar2 < 0x1400000) {
        if (lVar2 == 0x200000) {
          pcVar8 = "2M";
        }
        else {
          if (lVar2 != 0xc00000) goto LAB_00105374;
          pcVar8 = "12M";
        }
      }
      else if (lVar2 == 0x1400000) {
        pcVar8 = "20M";
      }
      else if (lVar2 == 0x1800000) {
        pcVar8 = "24M";
      }
      else {
        if (lVar2 != 0x2000000) goto LAB_00105374;
        pcVar8 = "32M";
      }
      uVar17 = 0;
      if (uVar10 != 0) {
        uVar17 = uVar16 / uVar10;
      }
      uVar16 = 0;
      if (uVar10 != 0) {
        uVar16 = uVar13 / uVar10;
      }
      seq_printf(param_1,"%8s %12lld.%03d us %9lld.%03d us\n",pcVar8,uVar17 / 1000,
                 (int)uVar17 + (int)(uVar17 / 1000) * -1000,uVar16 / 1000,
                 (int)uVar16 + (int)(uVar16 / 1000) * -1000);
      plVar14 = plVar14 + 1;
      lVar2 = *plVar14;
    } while (lVar2 != 0);
    seq_putc(param_1,10);
    seq_printf(param_1,"%8s %19s %16s\n",&DAT_00105916,"iommu_map_sg","iommu_unmap");
    plVar14 = (long *)&DAT_00107f18;
    lVar2 = 0x1000;
    do {
      local_78 = (ulong *)0x0;
      local_70 = 0;
      uVar16 = 0;
      if (lVar2 + -1 != 0) {
        uVar16 = ~(-1L << (-LZCOUNT(lVar2 + -1) & 0x3fU));
      }
      iVar1 = iommu_debug_build_phoney_sg_table(&local_78,lVar2);
      if (iVar1 != 0) {
        seq_puts(param_1,"couldn\'t build phoney sg table! bailing...\n");
        break;
      }
      if (*(int *)(lVar11 + 0x90) == 0) {
        uVar13 = 0;
        uVar10 = 0;
        uVar16 = 0;
        if (lVar2 < 0x200000) goto LAB_001054b4;
LAB_001054f4:
        if (lVar2 < 0x1400000) {
          if (lVar2 == 0x200000) {
            pcVar8 = "2M";
          }
          else {
            if (lVar2 != 0xc00000) goto LAB_00105674;
            pcVar8 = "12M";
          }
        }
        else if (lVar2 == 0x1400000) {
          pcVar8 = "20M";
        }
        else if (lVar2 == 0x1800000) {
          pcVar8 = "24M";
        }
        else {
          if (lVar2 != 0x2000000) goto LAB_00105674;
          pcVar8 = "32M";
        }
      }
      else {
        uVar17 = 0;
        uVar10 = 0;
        uVar13 = 0;
        uVar15 = uVar16 + 0x10000 & (uVar16 ^ 0xffffffffffffffff);
        do {
          lVar3 = ktime_get();
          lVar4 = iommu_map_sg(uVar12,uVar15,local_78,local_70._4_4_,3);
          if (lVar4 != lVar2) {
            seq_puts(param_1,"Failed to map_sg\n");
            goto LAB_00105630;
          }
          lVar4 = ktime_get();
          lVar5 = ktime_get();
          lVar6 = iommu_unmap(uVar12,uVar15,lVar2);
          if (lVar6 != lVar2) {
            seq_printf(param_1,"Only unmapped %zx instead of %zx\n",lVar6,lVar2);
            goto LAB_00105630;
          }
          uVar13 = lVar4 + (uVar13 - lVar3);
          lVar3 = ktime_get();
          uVar16 = (ulong)*(uint *)(lVar11 + 0x90);
          uVar10 = lVar3 + (uVar10 - lVar5);
          uVar17 = uVar17 + 1;
        } while (uVar17 < uVar16);
        if (0x1fffff < lVar2) goto LAB_001054f4;
LAB_001054b4:
        if (lVar2 < 0x4000) {
          pcVar8 = "4K";
          if (lVar2 == 0x1000) goto LAB_001055e4;
          if (lVar2 == 0x2000) {
            pcVar8 = "8K";
            goto LAB_001055e4;
          }
LAB_00105674:
          _printk(&DAT_00106291,"_size_to_string");
          pcVar8 = "unknown size";
        }
        else if (lVar2 == 0x4000) {
          pcVar8 = "16K";
        }
        else if (lVar2 == 0x10000) {
          pcVar8 = "64K";
        }
        else {
          if (lVar2 != 0x100000) goto LAB_00105674;
          pcVar8 = "1M";
        }
      }
LAB_001055e4:
      uVar17 = 0;
      if (uVar16 != 0) {
        uVar17 = uVar13 / uVar16;
      }
      uVar13 = 0;
      if (uVar16 != 0) {
        uVar13 = uVar10 / uVar16;
      }
      seq_printf(param_1,"%8s %12lld.%03d us %9lld.%03d us\n",pcVar8,uVar17 / 1000,
                 (int)uVar17 + (int)(uVar17 / 1000) * -1000,uVar13 / 1000,
                 (int)uVar13 + (int)(uVar13 / 1000) * -1000);
LAB_00105630:
      if ((uint)local_70 != 0) {
        uVar9 = 0;
        puVar7 = local_78;
        do {
          __free_pages(*puVar7 & 0xfffffffffffffffc,0);
          uVar9 = uVar9 + 1;
          puVar7 = (ulong *)sg_next(puVar7);
        } while (uVar9 < (uint)local_70);
      }
      sg_free_table(&local_78);
      plVar14 = plVar14 + 1;
      lVar2 = *plVar14;
    } while (lVar2 != 0);
  }
  mutex_unlock(lVar11 + 0x38);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// iommu_get_domain_for_dev @ 0010a000 size=1
// signature: undefined iommu_get_domain_for_dev(void)
// callers: [iommu_debug_check_mapping_flags, iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_domain_for_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_iommu_iova_to_phys_hard @ 0010a008 size=1
// signature: undefined qcom_iommu_iova_to_phys_hard(void)
// callers: [__check_mapping, iommu_debug_dma_atos_read, iommu_debug_check_mapping_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_iommu_iova_to_phys_hard(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_iova_to_phys @ 0010a010 size=1
// signature: undefined iommu_iova_to_phys(void)
// callers: [__check_mapping, iommu_debug_check_mapping_flags, iommu_debug_atos_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_iova_to_phys(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010a018 size=1
// signature: undefined ___ratelimit(void)
// callers: [iommu_debug_dma_unmap_write, __check_mapping, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_check_mapping_flags, iommu_debug_unmap_write, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a020 size=1
// signature: undefined _dev_err(void)
// callers: [__check_mapping, iommu_debug_check_mapping_flags, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, iommu_debug_probe, __full_va_sweep, iommu_debug_switch_usecase, iommu_debug_atos_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [iommu_debug_dma_map_read, iommu_debug_dma_unmap_write, iommu_debug_dma_atos_read, iommu_debug_test_virt_addr_read, iommu_debug_map_write, iommu_debug_check_mapping_flags, iommu_debug_functional_arm_dma_api_show, iommu_debug_atos_write, iommu_debug_check_mapping_sg_flags, __functional_dma_api_alloc_test, __check_mapping, iommu_debug_profiling_show, iommu_debug_dma_map_write, iommu_debug_unmap_write, iommu_debug_functional_fast_dma_api_show, iommu_debug_usecase_write, iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_start @ 0010a030 size=1
// signature: undefined __sg_page_iter_start(void)
// callers: [iommu_debug_check_mapping_sg_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_next @ 0010a040 size=1
// signature: undefined __sg_page_iter_next(void)
// callers: [iommu_debug_check_mapping_sg_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_dma_next @ 0010a048 size=1
// signature: undefined __sg_page_iter_dma_next(void)
// callers: [iommu_debug_check_mapping_sg_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_dma_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_device_destroy @ 0010a050 size=1
// signature: undefined of_platform_device_destroy(void)
// callers: [iommu_debug_remove, iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 0010a058 size=1
// signature: undefined of_get_next_child(void)
// callers: [iommu_debug_probe, iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_device_create @ 0010a060 size=1
// signature: undefined of_platform_device_create(void)
// callers: [iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible_timeout @ 0010a068 size=1
// signature: undefined wait_for_completion_interruptible_timeout(void)
// callers: [iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010a070 size=1
// signature: undefined of_property_read_string(void)
// callers: [iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010a078 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [iommu_debug_switch_usecase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a080 size=1
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
// platform_driver_unregister @ 0010a088 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010a090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [iommu_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010a098 size=1
// signature: undefined __mutex_init(void)
// callers: [iommu_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010a0a0 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [iommu_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010a0a8 size=1
// signature: undefined scnprintf(void)
// callers: [iommu_debug_dma_map_read, iommu_debug_dma_atos_read, iommu_debug_test_virt_addr_read, iommu_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010a0b0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [iommu_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0010a0b8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [iommu_debug_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0010a0c0 size=1
// signature: undefined debugfs_remove(void)
// callers: [iommu_debug_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010a0c8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [iommu_debug_usecase_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0010a0d0 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [iommu_debug_dma_map_read, iommu_debug_dma_atos_read, iommu_debug_test_virt_addr_read, iommu_debug_usecase_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010a0d8 size=1
// signature: undefined fortify_panic(void)
// callers: [iommu_debug_usecase_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint_from_user @ 0010a0e0 size=1
// signature: undefined kstrtouint_from_user(void)
// callers: [iommu_debug_usecase_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a0e8 size=1
// signature: undefined mutex_lock(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_profiling_show, iommu_debug_dma_atos_read, iommu_debug_dma_map_write, iommu_debug_test_virt_addr_read, iommu_debug_map_write, iommu_debug_functional_arm_dma_api_show, iommu_debug_unmap_write, iommu_debug_functional_fast_dma_api_show, iommu_debug_usecase_write, iommu_debug_atos_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a0f0 size=1
// signature: undefined mutex_unlock(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_profiling_show, iommu_debug_dma_atos_read, iommu_debug_dma_map_write, iommu_debug_test_virt_addr_read, iommu_debug_map_write, iommu_debug_functional_arm_dma_api_show, iommu_debug_unmap_write, iommu_debug_functional_fast_dma_api_show, iommu_debug_usecase_write, iommu_debug_atos_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 0010a0f8 size=1
// signature: undefined simple_attr_open(void)
// callers: [iommu_debug_nr_iters_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010a100 size=1
// signature: undefined complete(void)
// callers: [iommu_debug_usecase_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 0010a128 size=1
// signature: undefined strscpy(void)
// callers: [iommu_debug_dma_atos_read, iommu_debug_test_virt_addr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a130 size=1
// signature: undefined _printk(void)
// callers: [iommu_debug_dma_unmap_write, __functional_dma_api_alloc_test, iommu_debug_profiling_show, iommu_debug_dma_atos_read, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_functional_arm_dma_api_show, iommu_debug_unmap_write, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, iommu_debug_atos_write, _size_to_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull_from_user @ 0010a138 size=1
// signature: undefined kstrtoull_from_user(void)
// callers: [iommu_debug_atos_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0010a148 size=1
// signature: undefined __check_object_size(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_unmap_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0010a160 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_unmap_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnchr @ 0010a168 size=1
// signature: undefined strnchr(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_unmap_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnchr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0010a170 size=1
// signature: undefined kstrtoull(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_unmap_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 0010a178 size=1
// signature: undefined kstrtoint(void)
// callers: [iommu_debug_map_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_map @ 0010a180 size=1
// signature: undefined iommu_map(void)
// callers: [iommu_debug_profiling_show, iommu_debug_map_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010a188 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [iommu_debug_dma_unmap_write, __functional_dma_api_alloc_test, iommu_debug_dma_map_write, iommu_debug_map_write, iommu_debug_unmap_write, __functional_dma_api_basic_test]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_unmap @ 0010a198 size=1
// signature: undefined iommu_unmap(void)
// callers: [iommu_debug_profiling_show, iommu_debug_unmap_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_unmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010a1a0 size=1
// signature: undefined kstrtouint(void)
// callers: [iommu_debug_dma_unmap_write, iommu_debug_dma_map_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 0010a1a8 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [iommu_debug_dma_unmap_write, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 0010a1b0 size=1
// signature: undefined single_open(void)
// callers: [iommu_debug_functional_arm_dma_api_open, iommu_debug_functional_fast_dma_api_open, iommu_debug_profiling_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 0010a1b8 size=1
// signature: undefined kmalloc_large(void)
// callers: [iommu_debug_test_virt_addr_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 0010a1c0 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [dma_map_single_attrs, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 0010a1c8 size=1
// signature: undefined dev_driver_string(void)
// callers: [dma_map_single_attrs, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010a1d0 size=1
// signature: undefined __warn_printk(void)
// callers: [dma_map_single_attrs, __check_mapping, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 0010a1d8 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [dma_map_single_attrs, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 0010a1e0 size=1
// signature: undefined seq_printf(void)
// callers: [__functional_dma_api_alloc_test, iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show, __functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 0010a1e8 size=1
// signature: undefined sg_free_table(void)
// callers: [iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show, iommu_debug_build_phoney_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_sg_attrs @ 0010a1f0 size=1
// signature: undefined dma_map_sg_attrs(void)
// callers: [iommu_debug_functional_arm_dma_api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_sg_attrs @ 0010a1f8 size=1
// signature: undefined dma_unmap_sg_attrs(void)
// callers: [iommu_debug_functional_arm_dma_api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 0010a200 size=1
// signature: undefined __free_pages(void)
// callers: [iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show, iommu_debug_build_phoney_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 0010a208 size=1
// signature: undefined sg_next(void)
// callers: [iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show, iommu_debug_build_phoney_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 0010a210 size=1
// signature: undefined seq_puts(void)
// callers: [iommu_debug_profiling_show, iommu_debug_functional_arm_dma_api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 0010a218 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [__functional_dma_api_alloc_test]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 0010a220 size=1
// signature: undefined dma_free_attrs(void)
// callers: [__functional_dma_api_alloc_test]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a238 size=1
// signature: undefined kmalloc_trace(void)
// callers: [__functional_dma_api_basic_test]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010a240 size=1
// signature: undefined kfree(void)
// callers: [__functional_dma_api_basic_test, iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table @ 0010a248 size=1
// signature: undefined sg_alloc_table(void)
// callers: [iommu_debug_build_phoney_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 0010a250 size=1
// signature: undefined __alloc_pages(void)
// callers: [iommu_debug_build_phoney_sg_table]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 0010a258 size=1
// signature: undefined kstrdup(void)
// callers: [iommu_debug_functional_fast_dma_api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_free_pages @ 0010a260 size=1
// signature: undefined __get_free_pages(void)
// callers: [iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 0010a268 size=1
// signature: undefined free_pages(void)
// callers: [iommu_debug_functional_fast_dma_api_show, __full_va_sweep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0010a270 size=1
// signature: undefined ktime_get(void)
// callers: [iommu_debug_profiling_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_putc @ 0010a278 size=1
// signature: undefined seq_putc(void)
// callers: [iommu_debug_profiling_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_putc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_map_sg @ 0010a280 size=1
// signature: undefined iommu_map_sg(void)
// callers: [iommu_debug_profiling_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_map_sg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



