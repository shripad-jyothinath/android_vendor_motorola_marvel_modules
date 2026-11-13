// Decompiled by Ghidra 12.2
// Program: moto_swap5.ko
// Image base: 00100000

//------------------------------------------------------------
// zram_oem_fn_nocfi @ 00101f34 size=36
// signature: undefined zram_oem_fn_nocfi(void)
// callers: []
//------------------------------------------------------------

void zram_oem_fn_nocfi(void)

{
  (*zram_oem_fn)();
  return;
}



//------------------------------------------------------------
// zram_perform_task_prefetch @ 00101f5c size=380
// signature: undefined zram_perform_task_prefetch(void)
// callers: [prefetch_pid_store]
//------------------------------------------------------------

undefined4 zram_perform_task_prefetch(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  ulong *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  long lVar6;
  undefined8 local_48;
  long local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  if (param_2 == 0) {
    puVar5 = &DAT_0010c6c9;
  }
  else {
    if (zram_oem_fn != 0) {
      _printk(&DAT_0010c3e9,*(undefined4 *)(param_2 + 0x630),param_2 + 0x848);
      local_48 = 0;
      local_40 = 0;
      lVar6 = get_task_mm(param_2);
      if (lVar6 == 0) {
        _printk(&DAT_0010c8bd,*(undefined4 *)(param_2 + 0x630));
        uVar4 = 0xfffffffd;
      }
      else {
        iVar3 = down_read_killable(lVar6 + 0x60);
        if (iVar3 == 0) {
          puVar2 = (ulong *)sp_el0;
          uVar1 = 0x8000000000;
          if ((*puVar2 & 0x400000) != 0) {
            uVar1 = 0xfffff000;
          }
          uVar4 = walk_page_range(lVar6,0,uVar1,&prefetch_walk_ops,&local_48);
          up_read(lVar6 + 0x60);
          mmput(lVar6);
          if (local_40 == 0) {
            _printk(&DAT_0010cce5,*(undefined4 *)(param_2 + 0x630));
          }
          else {
            _printk(&DAT_0010cea3);
          }
        }
        else {
          _printk(&DAT_0010cd90,*(undefined4 *)(param_2 + 0x630));
          mmput(lVar6);
          uVar4 = 0xfffffffc;
        }
      }
      goto LAB_00101fac;
    }
    puVar5 = &DAT_0010c44c;
  }
  _printk(puVar5);
  uVar4 = 0xffffffea;
LAB_00101fac:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// zram_perform_task_eswapout @ 00102114 size=692
// signature: undefined zram_perform_task_eswapout(void)
// callers: [writeback_pid_store]
//------------------------------------------------------------

undefined8 zram_perform_task_eswapout(long param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  long local_d0 [8];
  undefined8 ****local_90;
  undefined8 uStack_88;
  long local_80;
  undefined8 ****local_78;
  undefined8 ****local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  if (param_2 == 0) {
    puVar3 = &DAT_0010c6c9;
  }
  else {
    if (zram_oem_fn != (code *)0x0) {
      _printk(&DAT_0010c604,*(undefined4 *)(param_2 + 0x630),param_2 + 0x848);
      local_90 = &local_78;
      uStack_88 = 0;
      local_80 = 0;
      local_78 = local_90;
      local_70 = local_90;
      lVar4 = get_task_mm(param_2);
      if (lVar4 == 0) {
        _printk(&DAT_0010c8bd,*(undefined4 *)(param_2 + 0x630));
        uVar7 = 0xfffffffd;
        goto LAB_001022d8;
      }
      iVar2 = down_read_killable(lVar4 + 0x60);
      if (iVar2 != 0) {
        _printk(&DAT_0010cd90,*(undefined4 *)(param_2 + 0x630));
        mmput(lVar4);
        uVar7 = 0xfffffffc;
        goto LAB_001022d8;
      }
      bVar1 = true;
      local_d0[6] = 0;
      local_d0[7] = 0;
      local_d0[4] = 0;
      local_d0[5] = 0;
      local_d0[1] = 0;
      local_d0[2] = 0;
      local_d0[3] = 1;
      local_d0[0] = lVar4;
      puVar5 = (undefined8 *)mas_find(local_d0,0xffffffffffffffff);
      if (puVar5 == (undefined8 *)0x0) {
        uVar7 = 0;
      }
      else {
        do {
          if (*(int *)(param_1 + 0x33c) != 0) {
            _printk(&DAT_0010ca16,*(undefined4 *)(param_2 + 0x630));
            bVar1 = false;
            uVar7 = 0xffffff83;
            goto code_r0x0010227c;
          }
          if (((*(uint *)(puVar5 + 4) & 0x46400) == 0) &&
             ((puVar5[0xf] == 0 || (uVar6 = (*ref_vma_is_shmem)(puVar5), (uVar6 & 1) != 0)))) {
            walk_page_range(lVar4,*puVar5,puVar5[1],eswapout_walk_ops,&local_90);
          }
          puVar5 = (undefined8 *)mas_find(local_d0,0xffffffffffffffff);
        } while (puVar5 != (undefined8 *)0x0);
        uVar7 = 0;
        bVar1 = true;
      }
code_r0x0010227c:
      up_read(lVar4 + 0x60);
      mmput(lVar4);
      if (bVar1) {
        if (*(int *)(param_1 + 0x33c) != 0) {
          uVar7 = 0xffffff83;
          goto LAB_00102330;
        }
        if ((local_80 == 0) || ((undefined8 *****)local_78 == &local_78)) {
          if ((undefined8 *****)local_78 == &local_78) {
            _printk(&DAT_0010cce5,*(undefined4 *)(param_2 + 0x630));
          }
        }
        else {
          _printk(&DAT_0010ca41,local_80,*(undefined4 *)(param_2 + 0x630));
          (*zram_oem_fn)(2,&local_78,0);
        }
        uVar7 = 0;
      }
      else {
LAB_00102330:
        _printk(&DAT_0010c981,*(undefined4 *)(param_2 + 0x630));
      }
      (*zram_oem_fn)(3,&local_78,0);
      goto LAB_001022d8;
    }
    puVar3 = &DAT_0010c44c;
  }
  _printk(puVar3);
  uVar7 = 0xffffffea;
LAB_001022d8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// zram_shrink_init @ 00102404 size=408
// signature: undefined zram_shrink_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined4 zram_shrink_init(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  code *local_90;
  undefined *local_88;
  undefined8 uStack_80;
  code *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = DAT_0010d230;
  uStack_48 = DAT_0010d238;
  local_40 = DAT_0010d240;
  uStack_70 = DAT_0010d210;
  local_60 = DAT_0010d220;
  uStack_58 = DAT_0010d228;
  local_98 = DAT_0010d1e8;
  local_90 = DAT_0010d1f0;
  local_88 = PTR_s_kallsyms_lookup_name_0010d1f8;
  uStack_80 = DAT_0010d200;
  local_b8 = DAT_0010d1c8;
  uStack_b0 = DAT_0010d1d0;
  local_a8 = DAT_0010d1d8;
  uStack_a0 = DAT_0010d1e0;
  local_68 = DAT_0010d218;
  local_78 = get_kallsyms_lookup_name_cb;
  iVar3 = register_kprobe(&local_b8);
  if (iVar3 < 0) {
    _printk(&DAT_0010cfd3,iVar3);
LAB_001024d0:
    uVar5 = 0xfffffff2;
  }
  else {
    ref_kallsyms_lookup_name = local_90;
    unregister_kprobe(&local_b8);
    if (ref_kallsyms_lookup_name == (code *)0x0) {
      _printk(&DAT_0010cb0c);
      goto LAB_001024d0;
    }
    _printk(&DAT_0010c500);
    ref_swp_swapcount = (*ref_kallsyms_lookup_name)("swp_swapcount");
    ref_vma_is_shmem = (*ref_kallsyms_lookup_name)("vma_is_shmem");
    if ((ref_swp_swapcount != 0) && (ref_vma_is_shmem != 0)) {
      uVar5 = 0xffffffea;
      puVar4 = &DAT_0010cc81;
      if (param_1 != 0) {
        bVar2 = *(long *)(param_1 + 0x18) != 0;
        puVar4 = &DAT_0010cc81;
        if (bVar2) {
          puVar4 = &DAT_0010ce43;
        }
        uVar5 = 0xffffffea;
        if (bVar2) {
          uVar5 = 0;
        }
      }
      goto LAB_001024dc;
    }
    _printk(&DAT_0010cf9f);
    uVar5 = 0xffffffea;
  }
  puVar4 = &DAT_0010cf78;
LAB_001024dc:
  _printk(puVar4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// prefetch_pte_range @ 001025a0 size=352
// signature: undefined prefetch_pte_range(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 prefetch_pte_range(ulong *param_1,ulong param_2,ulong param_3,long param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_4 + 0x28);
  uVar3 = *param_1;
  if (((uVar3 != 0) && (((uint)uVar3 >> 1 & 1) != 0)) && ((uVar3 & 0xc00000000000001) != 0)) {
    if ((~(uint)uVar3 & 3) == 0) {
      for (; param_2 < param_3; param_2 = param_2 + 0x1000) {
        *plVar5 = *plVar5 + 1;
        uVar3 = (*param_1 & 0x7ffffff000) - _memstart_addr;
        lVar1 = (*param_1 >> 0xc & 0xfffffffff) * 0x40 + (_memstart_addr >> 0xc) * -0x40 +
                -0x1ffffffd8;
        _raw_spin_lock(lVar1);
        uVar3 = *(ulong *)((uVar3 | 0xffffff8000000000) + (param_2 >> 0xc & 0x1ff) * 8);
        _raw_spin_unlock(lVar1);
        if (((uVar3 != 0) && ((uVar3 & 0x400000000000001) == 0)) &&
           (((uint)((uVar3 & 0x1ff) >> 3) & 0x1f) < 0x1c)) {
          uVar4 = uVar3 >> 8 & 0x3ffffffffffff;
          iVar2 = (*ref_swp_swapcount)(uVar4 | (uVar3 & 0xf8) << 0x37);
          if ((iVar2 < 2) && (zram_oem_fn != (code *)0x0)) {
            (*zram_oem_fn)(6,0,uVar4);
            plVar5[1] = plVar5[1] + 1;
          }
        }
      }
    }
    else {
      pmd_clear_bad(param_1);
    }
  }
  return 0;
}



//------------------------------------------------------------
// prefetch_test_walk @ 00102704 size=84
// signature: undefined prefetch_test_walk(void)
// callers: []
//------------------------------------------------------------

undefined8 prefetch_test_walk(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined8 uVar1;
  ulong uVar2;
  
  if (((*(uint *)(*(long *)(param_3 + 0x18) + 0x20) & 0x10046400) == 0) &&
     ((*(long *)(*(long *)(param_3 + 0x18) + 0x78) == 0 ||
      (uVar2 = (*ref_vma_is_shmem)(), (uVar2 & 1) != 0)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// eswapout_writeback_pte_range @ 0010275c size=356
// signature: undefined eswapout_writeback_pte_range(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 eswapout_writeback_pte_range(ulong *param_1,ulong param_2,ulong param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  ulong *puVar7;
  
  lVar2 = _memstart_addr;
  puVar6 = *(undefined8 **)(param_4 + 0x28);
  uVar4 = *param_1;
  if (((uVar4 != 0) && (((uint)uVar4 >> 1 & 1) != 0)) && ((uVar4 & 0xc00000000000001) != 0)) {
    if ((~(uint)uVar4 & 3) == 0) {
      uVar4 = *param_1;
      lVar1 = (uVar4 >> 0xc & 0xfffffffff) * 0x40 + (_memstart_addr >> 0xc) * -0x40 + -0x1ffffffd8;
      _raw_spin_lock(lVar1);
      if (param_2 < param_3) {
        puVar7 = (ulong *)(((uVar4 & 0x7ffffff000) - lVar2 | 0xffffff8000000000) +
                          (param_2 >> 0xc & 0x1ff) * 8);
        do {
          uVar4 = *puVar7;
          puVar6[1] = puVar6[1] + 1;
          if (((uVar4 != 0) && ((uVar4 & 0x400000000000001) == 0)) &&
             (((uint)((uVar4 & 0x1ff) >> 3) & 0x1f) < 0x1c)) {
            uVar5 = uVar4 >> 8 & 0x3ffffffffffff;
            iVar3 = (*ref_swp_swapcount)(uVar5 | (uVar4 & 0xf8) << 0x37);
            if ((iVar3 < 2) && (zram_oem_fn != (code *)0x0)) {
              (*zram_oem_fn)(1,*puVar6,uVar5);
              puVar6[2] = puVar6[2] + 1;
            }
          }
          puVar7 = puVar7 + 1;
          param_2 = param_2 + 0x1000;
        } while (param_2 < param_3);
      }
      _raw_spin_unlock(lVar1);
    }
    else {
      pmd_clear_bad();
    }
  }
  return 0;
}



//------------------------------------------------------------
// get_kallsyms_lookup_name_cb @ 001028c4 size=8
// signature: undefined get_kallsyms_lookup_name_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 get_kallsyms_lookup_name_cb(void)

{
  return 0;
}



//------------------------------------------------------------
// zram_ext_version_show @ 001028d0 size=52
// signature: undefined zram_ext_version_show(void)
// callers: []
//------------------------------------------------------------

long zram_ext_version_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010c6eb,100);
  return (long)iVar1;
}



//------------------------------------------------------------
// zram_get_total_used_pages @ 00102908 size=244
// signature: undefined zram_get_total_used_pages(void)
// callers: []
//------------------------------------------------------------

long zram_get_total_used_pages(void)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  mutex_lock(zram_index_mutex);
  local_3c = 0;
  lVar2 = idr_get_next(zram_index_idr,&local_3c);
  if (lVar2 == 0) {
    lVar4 = 0;
  }
  else {
    lVar4 = 0;
    do {
      iVar1 = down_read_trylock(lVar2 + 0x20);
      if (iVar1 != 0) {
        if ((*(long *)(lVar2 + 0x198) != 0) && (*(long *)(lVar2 + 8) != 0)) {
          lVar3 = zs_get_total_pages();
          lVar4 = lVar3 + lVar4;
        }
        up_read(lVar2 + 0x20);
      }
      local_3c = local_3c + 1;
      lVar2 = idr_get_next(zram_index_idr,&local_3c);
    } while (lVar2 != 0);
  }
  mutex_unlock(zram_index_mutex);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar4;
}



//------------------------------------------------------------
// zram_add @ 001029fc size=784
// signature: undefined zram_add(void)
// callers: [init_module, hot_add_show]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int zram_add(void)

{
  int param3;
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined8 uVar4;
  
  lVar2 = kmalloc_trace(_blk_queue_physical_block_size,0xdc0,0x378);
  if (lVar2 == 0) {
    iVar1 = -0xc;
  }
  else {
    param3 = idr_alloc(zram_index_idr,lVar2,0,0,0xcc0);
    iVar1 = param3;
    if (-1 < param3) {
      __init_rwsem(lVar2 + 0x20,"&zram->init_lock",&zram_add___key);
      *(undefined4 *)(lVar2 + 0x230) = 0;
      *(long *)(lVar2 + 0x2a0) = lVar2 + 0x2a0;
      *(long *)(lVar2 + 0x2a8) = lVar2 + 0x2a0;
      *(undefined8 *)(lVar2 + 0x2b0) = 0;
      *(undefined4 *)(lVar2 + 0x2b8) = 0;
      __mutex_init(lVar2 + 0x2c8,"&zram->blk_bitmap_lock",&zram_add___key_43);
      __mutex_init(lVar2 + 0x308,"&zram->wb_pid_lock",&init_wb_pid___key);
      *(undefined4 *)(lVar2 + 0x338) = 0;
      *(undefined4 *)(lVar2 + 0x33c) = 0;
      __mutex_init(lVar2 + 0x340,"&zram->prefetch_pid_lock",&init_prefetch_pid___key);
      *(undefined4 *)(lVar2 + 0x370) = 0;
      puVar3 = (undefined4 *)__blk_alloc_disk(0xffffffff,&zram_add___key_45);
      *(undefined4 **)(lVar2 + 0x18) = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        _printk(&DAT_0010c879,param3);
        iVar1 = -0xc;
      }
      else {
        *puVar3 = zram_major;
        *(int *)(*(long *)(lVar2 + 0x18) + 4) = param3;
        *(undefined4 *)(*(long *)(lVar2 + 0x18) + 8) = 1;
        *(uint *)(*(long *)(lVar2 + 0x18) + 0x168) = *(uint *)(*(long *)(lVar2 + 0x18) + 0x168) | 4;
        *(undefined ***)(*(long *)(lVar2 + 0x18) + 0x48) = &zram_devops;
        *(long *)(*(long *)(lVar2 + 0x18) + 0x58) = lVar2;
        snprintf((char *)(*(long *)(lVar2 + 0x18) + 0xc),0x10,"zram%d",param3);
        set_capacity(*(undefined8 *)(lVar2 + 0x18),0);
        blk_queue_flag_set(6,*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50));
        blk_queue_flag_clear(10,*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50));
        blk_queue_physical_block_size(*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50),0x1000);
        blk_queue_logical_block_size(*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50),0x1000);
        blk_queue_io_min(*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50),0x1000);
        blk_queue_io_opt(*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50),0x1000);
        *(undefined4 *)(*(long *)(*(long *)(lVar2 + 0x18) + 0x50) + 0x234) = 0x1000;
        blk_queue_max_discard_sectors(*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50),0xffffffff);
        blk_queue_max_write_zeroes_sectors
                  (*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50),0xffffffff);
        blk_queue_flag_set(0xf,*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x50));
        iVar1 = device_add_disk(0,*(undefined8 *)(lVar2 + 0x18),&zram_disk_groups);
        if (iVar1 == 0) {
          strscpy(lVar2 + 0x1a0,"lzo-rle",8);
          if (zram_debugfs_root != 0) {
            uVar4 = debugfs_create_dir(*(long *)(lVar2 + 0x18) + 0xc);
            *(undefined8 *)(lVar2 + 600) = uVar4;
            debugfs_create_file("block_state",0x100,uVar4,lVar2,proc_zram_block_state_op);
          }
          _printk(&DAT_0010cc02,*(long *)(lVar2 + 0x18) + 0xc);
          tracepoint_probe_register(&__tracepoint_android_vh_show_mem,zram_show_mem,lVar2);
          tracepoint_probe_register(&__tracepoint_android_vh_meminfo_proc_show,zram_meminfo,lVar2);
          return param3;
        }
        put_disk(*(undefined8 *)(lVar2 + 0x18));
      }
      idr_remove(zram_index_idr,param3);
    }
    kfree(lVar2);
  }
  return iVar1;
}



//------------------------------------------------------------
// destroy_devices @ 00102d0c size=124
// signature: undefined destroy_devices(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

void destroy_devices(void)

{
  class_unregister(&zram_control_class);
  idr_for_each(zram_index_idr,zram_remove_cb,0);
  debugfs_remove(zram_debugfs_root);
  idr_destroy(zram_index_idr);
  unregister_blkdev(zram_major,&DAT_0010cd58);
  __cpuhp_remove_state(0x44,0);
  return;
}



//------------------------------------------------------------
// hot_add_show @ 00102d8c size=112
// signature: undefined hot_add_show(void)
// callers: []
//------------------------------------------------------------

long hot_add_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  mutex_lock(zram_index_mutex);
  iVar1 = zram_add();
  mutex_unlock(zram_index_mutex);
  if (-1 < iVar1) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010c82e,iVar1);
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// hot_remove_store @ 00102e00 size=228
// signature: undefined hot_remove_store(void)
// callers: []
//------------------------------------------------------------

long hot_remove_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar1 = kstrtoint(param_3,10,&local_2c);
  if (iVar1 == 0) {
    if (local_2c < 0) {
      param_4 = -0x16;
    }
    else {
      mutex_lock(zram_index_mutex);
      lVar2 = idr_find(zram_index_idr,(long)local_2c);
      if (lVar2 == 0) {
        iVar1 = -0x13;
      }
      else {
        iVar1 = zram_remove();
        if (iVar1 == 0) {
          idr_remove(zram_index_idr,(long)local_2c);
          mutex_unlock(zram_index_mutex);
          goto LAB_00102eb4;
        }
      }
      mutex_unlock(zram_index_mutex);
      param_4 = (long)iVar1;
    }
  }
  else {
    param_4 = (long)iVar1;
  }
LAB_00102eb4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// zram_remove @ 00102ee4 size=460
// signature: undefined zram_remove(void)
// callers: [zram_remove_cb, hot_remove_store]
//------------------------------------------------------------

undefined8 zram_remove(long param_1)

{
  char cVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  mutex_lock(*(long *)(param_1 + 0x18) + 0x178);
  if (*(int *)(*(long *)(*(long *)(param_1 + 0x18) + 0x40) + 0x28) == 0) {
    tracepoint_probe_unregister(&__tracepoint_android_vh_show_mem,zram_show_mem,param_1);
    tracepoint_probe_unregister(&__tracepoint_android_vh_meminfo_proc_show,zram_meminfo,param_1);
    cVar1 = *(char *)(param_1 + 0x220);
    if (cVar1 == '\0') {
      *(undefined1 *)(param_1 + 0x220) = 1;
      mutex_unlock(*(long *)(param_1 + 0x18) + 0x178);
      if ((*(ulong *)(param_1 + 0x260) != 0) && (*(ulong *)(param_1 + 0x260) < 0xfffffffffffff001))
      {
        g_zram = 0;
        kthread_stop();
        *(undefined8 *)(param_1 + 0x260) = 0;
      }
      *(undefined4 *)(param_1 + 0x33c) = 1;
      mutex_lock(param_1 + 0x308);
      *(undefined4 *)(param_1 + 0x338) = 0;
      mutex_unlock(param_1 + 0x308);
      mutex_lock(param_1 + 0x340);
      *(undefined4 *)(param_1 + 0x370) = 0;
      mutex_unlock(param_1 + 0x340);
      debugfs_remove(*(undefined8 *)(param_1 + 600));
      sync_blockdev(*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x40));
      zram_reset_device(param_1);
    }
    else {
      mutex_unlock(*(long *)(param_1 + 0x18) + 0x178);
      if ((*(ulong *)(param_1 + 0x260) != 0) && (*(ulong *)(param_1 + 0x260) < 0xfffffffffffff001))
      {
        g_zram = 0;
        kthread_stop();
        *(undefined8 *)(param_1 + 0x260) = 0;
      }
      *(undefined4 *)(param_1 + 0x33c) = 1;
      mutex_lock(param_1 + 0x308);
      *(undefined4 *)(param_1 + 0x338) = 0;
      mutex_unlock(param_1 + 0x308);
      mutex_lock(param_1 + 0x340);
      *(undefined4 *)(param_1 + 0x370) = 0;
      mutex_unlock(param_1 + 0x340);
      debugfs_remove(*(undefined8 *)(param_1 + 600));
    }
    _printk(&DAT_0010c778,*(long *)(param_1 + 0x18) + 0xc);
    del_gendisk(*(undefined8 *)(param_1 + 0x18));
    if ((cVar1 != '\0') && (*(char *)(param_1 + 0x220) != '\0')) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1030b0);
      (*pcVar2)();
    }
    zram_reset_device(param_1);
    put_disk(*(undefined8 *)(param_1 + 0x18));
    kfree(param_1);
    uVar3 = 0;
  }
  else {
    mutex_unlock(*(long *)(param_1 + 0x18) + 0x178);
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}



//------------------------------------------------------------
// zram_show_mem @ 001030b8 size=136
// signature: undefined zram_show_mem(void)
// callers: []
//------------------------------------------------------------

void zram_show_mem(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 != 0) {
    lVar1 = param_1 + 0x20;
    iVar2 = down_read_trylock(lVar1);
    if (iVar2 != 0) {
      if ((*(long *)(param_1 + 0x198) == 0) || (*(long *)(param_1 + 8) == 0)) {
        up_read(lVar1);
      }
      else {
        lVar3 = zs_get_total_pages();
        up_read(lVar1);
        if (lVar3 << 2 != 0) {
          _printk(&DAT_0010c794,*(long *)(param_1 + 0x18) + 0xc,lVar3 << 2);
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// zram_meminfo @ 00103144 size=264
// signature: undefined zram_meminfo(void)
// callers: []
//------------------------------------------------------------

void zram_meminfo(long param_1,undefined8 param_2)

{
  long lVar1;
  char *__s;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char local_50 [24];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (param_1 != 0) {
    lVar1 = param_1 + 0x20;
    iVar2 = down_read_trylock(lVar1);
    if (iVar2 != 0) {
      if ((*(long *)(param_1 + 0x198) == 0) || (*(long *)(param_1 + 8) == 0)) {
        up_read(lVar1);
      }
      else {
        lVar3 = zs_get_total_pages();
        up_read(lVar1);
        if (lVar3 << 2 != 0) {
          local_50[0x10] = 0;
          local_50[0] = '\0';
          local_50[1] = '\0';
          local_50[2] = '\0';
          local_50[3] = '\0';
          local_50[4] = '\0';
          local_50[5] = '\0';
          local_50[6] = '\0';
          local_50[7] = '\0';
          local_50[8] = '\0';
          local_50[9] = '\0';
          local_50[10] = '\0';
          local_50[0xb] = '\0';
          local_50[0xc] = '\0';
          local_50[0xd] = '\0';
          local_50[0xe] = '\0';
          local_50[0xf] = 0;
          __s = (char *)(*(long *)(param_1 + 0x18) + 0xc);
          sVar4 = strlen(__s);
          if ((int)sVar4 < 0x10) {
            sprintf(local_50,"%s:",__s);
          }
          else {
            strncpy(local_50,__s,0xf);
            local_50[0xf] = 0x3a;
            local_50[0x10] = 0;
          }
          seq_printf(param_2,"%-16s%8ld kB\n",local_50,lVar3 << 2);
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// zram_reset_device @ 0010324c size=328
// signature: undefined zram_reset_device(void)
// callers: [zram_remove, reset_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zram_reset_device(undefined8 *param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  
  down_write(param_1 + 4);
  param_1[0xc] = 0;
  if (param_1[0x33] != 0) {
    set_capacity_and_notify(param_1[3],0);
    iVar4 = 0;
    lVar7 = *(long *)(param_1[3] + 0x40);
    while (uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4), uVar3 < _nr_cpu_ids
          ) {
      if ((uVar3 & 0xffffffe0) != 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103394);
        (*pcVar2)();
      }
      puVar1 = (undefined8 *)
               (*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + *(long *)(lVar7 + 0x10));
      iVar4 = uVar3 + 1;
      puVar1[0x11] = 0;
      puVar1[0x12] = 0;
      puVar1[0xf] = 0;
      puVar1[0x10] = 0;
      puVar1[0xd] = 0;
      puVar1[0xe] = 0;
      puVar1[0xb] = 0;
      puVar1[0xc] = 0;
      puVar1[9] = 0;
      puVar1[10] = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      *puVar1 = 0;
    }
    uVar5 = param_1[0x33];
    if (0xfff < uVar5) {
      uVar6 = 0;
      do {
        zram_free_page(param_1,uVar6);
        uVar6 = uVar6 + 1;
      } while (uVar5 >> 0xc != uVar6);
    }
    zs_destroy_pool(param_1[1]);
    vfree(*param_1);
    param_1[0x33] = 0;
    memset(param_1 + 0xd,0,0x130);
    zcomp_destroy(param_1[2]);
    param_1[2] = 0;
    reset_bdev(param_1);
  }
  up_write(param_1 + 4);
  return;
}



//------------------------------------------------------------
// zram_meta_free @ 00103394 size=100
// signature: undefined zram_meta_free(void)
// callers: [disksize_store]
//------------------------------------------------------------

void zram_meta_free(undefined8 *param_1,ulong param_2)

{
  ulong uVar1;
  
  if (0xfff < param_2) {
    uVar1 = 0;
    do {
      zram_free_page(param_1,uVar1);
      uVar1 = uVar1 + 1;
    } while (param_2 >> 0xc != uVar1);
  }
  zs_destroy_pool(param_1[1]);
  vfree(*param_1);
  return;
}



//------------------------------------------------------------
// reset_bdev @ 001033f8 size=296
// signature: undefined reset_bdev(void)
// callers: [zram_reset_device, backing_dev_store]
//------------------------------------------------------------

void reset_bdev(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x228) != 0) {
    blkdev_put(*(undefined8 *)(param_1 + 0x240),0x83);
    filp_close(*(undefined8 *)(param_1 + 0x228),0);
    *(undefined8 *)(param_1 + 0x228) = 0;
    *(undefined8 *)(param_1 + 0x240) = 0;
    *(undefined ***)(*(long *)(param_1 + 0x18) + 0x48) = &zram_devops;
    kvfree(*(undefined8 *)(param_1 + 0x248));
    *(undefined8 *)(param_1 + 0x248) = 0;
    uVar2 = *(undefined8 *)(param_1 + 0x280);
    if ((*(ulong *)(param_1 + 0x260) != 0) && (*(ulong *)(param_1 + 0x260) < 0xfffffffffffff001)) {
      g_zram = 0;
      kthread_stop();
      *(undefined8 *)(param_1 + 0x260) = 0;
    }
    if (*(long *)(param_1 + 0x2f8) != 0) {
      kvfree();
      *(undefined8 *)(param_1 + 0x2f8) = 0;
    }
    if (*(long *)(param_1 + 0x288) != 0) {
      kvfree();
      *(undefined8 *)(param_1 + 0x288) = 0;
    }
    if (*(long *)(param_1 + 0x2c0) != 0) {
      kvfree();
      *(undefined8 *)(param_1 + 0x2c0) = 0;
    }
    uVar1 = _raw_spin_lock_irqsave(param_1 + 0x2b4);
    if (*(long *)(param_1 + 0x280) != 0) {
      *(undefined8 *)(param_1 + 0x280) = 0;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x2b4,uVar1);
    kvfree(uVar2);
    *(undefined4 *)(param_1 + 0x33c) = 1;
    mutex_lock(param_1 + 0x308);
    *(undefined4 *)(param_1 + 0x338) = 0;
    mutex_unlock(param_1 + 0x308);
    mutex_lock(param_1 + 0x340);
    *(undefined4 *)(param_1 + 0x370) = 0;
    mutex_unlock(param_1 + 0x340);
  }
  return;
}



//------------------------------------------------------------
// zram_free_page @ 00103520 size=996
// signature: undefined zram_free_page(void)
// callers: [zram_writeback_done_work, zram_meta_free, zram_submit_bio, writeback_store, zram_reset_device, zram_bvec_rw, zram_slot_free_notify, zram_handle_comp_page]
//------------------------------------------------------------

void zram_free_page(long *param_1,ulong param_2)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  ulong uVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  ulong *puVar14;
  uint uVar15;
  
  *(undefined8 *)(*param_1 + param_2 * 0x28 + 0x10) = 0;
  lVar7 = *param_1;
  puVar14 = (ulong *)(lVar7 + param_2 * 0x28 + 8);
  uVar12 = *puVar14;
  if (((uint)uVar12 >> 0x12 & 1) != 0) {
    *puVar14 = uVar12 & 0xfffffffffffbffff;
    lVar7 = *param_1;
    uVar12 = *(ulong *)(lVar7 + param_2 * 0x28 + 8);
  }
  if (((uint)uVar12 >> 0x11 & 1) != 0) {
    *(ulong *)(lVar7 + param_2 * 0x28 + 8) = uVar12 & 0xfffffffffffdffff;
    plVar8 = param_1 + 0x15;
    Hint_Prefetch(plVar8,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
      if (bVar3) {
        *plVar8 = *plVar8 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  plVar8 = (long *)(*param_1 + param_2 * 0x28);
  puVar14 = (ulong *)(plVar8 + 1);
  uVar12 = *puVar14;
  uVar15 = (uint)uVar12;
  if ((uVar15 >> 0xf & 1) == 0) {
    if ((uVar15 >> 0xe & 1) == 0) {
      if (*plVar8 == 0) {
        return;
      }
      zs_free(param_1[1]);
      uVar12 = *(ulong *)(*param_1 + param_2 * 0x28 + 8);
      plVar8 = param_1 + 0xd;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 - (uVar12 & 0x1fff);
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      *puVar14 = uVar12 & 0xffffffffffffbfff;
      plVar8 = param_1 + 0x14;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  else {
    uVar5 = ktime_get_seconds();
    uVar9 = *(ulong *)(*param_1 + param_2 * 0x28 + 0x10);
    uVar10 = 0;
    if (uVar9 <= uVar5) {
      uVar10 = uVar5 - uVar9;
    }
    if (uVar10 < wb_duration_limit_1) {
      plVar8 = param_1 + 0x30;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else if (uVar10 < wb_duration_limit_2) {
      plVar8 = param_1 + 0x31;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      plVar8 = param_1 + 0x32;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    uVar10 = *(ulong *)(*param_1 + (param_2 & 0xffffffff) * 0x28);
    uVar1 = 0x1000;
    if ((uVar10 & 0xfff) != 0) {
      uVar1 = (uint)uVar10 & 0xfff;
    }
    plVar8 = param_1 + 0x20;
    Hint_Prefetch(plVar8,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
      if (bVar3) {
        *plVar8 = *plVar8 - (ulong)uVar1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if ((uVar15 >> 0x15 & 1) != 0) {
      lVar7 = *param_1 + param_2 * 0x28;
      *(ulong *)(lVar7 + 8) = *(ulong *)(lVar7 + 8) & 0xffffffffffdfffff;
      plVar8 = param_1 + 0x27;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 - (ulong)uVar1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    puVar14 = (ulong *)(*param_1 + param_2 * 0x28 + 8);
    uVar5 = *puVar14;
    if (((uint)uVar5 >> 0x13 & 1) != 0) {
      *puVar14 = uVar5 & 0xfffffffffff7ffff;
      plVar8 = param_1 + 0x1e;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    lVar7 = *param_1 + param_2 * 0x28;
    *(ulong *)(lVar7 + 8) = *(ulong *)(lVar7 + 8) & 0xffffffffffff7fff;
    free_block_bdev(param_1,uVar10 >> 0x18,uVar12 >> 0x15 & 1);
  }
  plVar8 = param_1 + 0x17;
  Hint_Prefetch(plVar8,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
    if (bVar3) {
      *plVar8 = *plVar8 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  lVar7 = param_2 * 0x28;
  *(undefined8 *)(*param_1 + lVar7) = 0;
  *(ulong *)(*param_1 + lVar7 + 8) = *(ulong *)(*param_1 + lVar7 + 8) & 0xffffffffffffe000;
  puVar14 = (ulong *)(*param_1 + lVar7 + 8);
  uVar12 = *puVar14;
  if (((uint)uVar12 >> 0x16 & 1) != 0) {
    *puVar14 = uVar12 & 0xffffffffffbfffff;
  }
  uVar6 = _raw_spin_lock_irqsave(param_1 + 0x56);
  lVar7 = *param_1;
  plVar8 = (long *)(lVar7 + param_2 * 0x28 + 0x18);
  if ((long *)*plVar8 != plVar8) {
    uVar12 = __list_del_entry_valid(plVar8);
    if ((uVar12 & 1) != 0) {
      lVar13 = *plVar8;
      plVar11 = *(long **)(lVar7 + param_2 * 0x28 + 0x20);
      *(long **)(lVar13 + 8) = plVar11;
      *plVar11 = lVar13;
    }
    *plVar8 = (long)plVar8;
    *(long **)(lVar7 + param_2 * 0x28 + 0x20) = plVar8;
    puVar14 = (ulong *)(*param_1 + param_2 * 0x28 + 8);
    uVar12 = *puVar14;
    if (((uint)uVar12 >> 0x17 & 1) != 0) {
      *puVar14 = uVar12 & 0xffffffffff7fffff;
      plVar8 = param_1 + 0x2c;
      Hint_Prefetch(plVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
        if (bVar3) {
          *plVar8 = *plVar8 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x56,uVar6);
  if ((*(ulong *)(*param_1 + param_2 * 0x28 + 8) & 0xfffffffffffedfff) != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x103850);
    (*pcVar4)();
  }
  return;
}



//------------------------------------------------------------
// free_block_bdev @ 001039a0 size=456
// signature: undefined free_block_bdev(void)
// callers: [zram_writeback_done_work, zram_free_page, writeback_store, zram_writeback_page]
//------------------------------------------------------------

void free_block_bdev(long param_1,ulong param_2,uint param_3)

{
  long *plVar1;
  ulong *puVar2;
  short sVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  
  lVar8 = param_1 + 0x2b4;
  uVar7 = _raw_spin_lock_irqsave(lVar8);
  lVar9 = *(long *)(param_1 + 0x280);
  if ((lVar9 != 0) && (sVar3 = *(short *)(lVar9 + param_2 * 2), sVar3 != 0)) {
    *(short *)(lVar9 + param_2 * 2) = sVar3 + -1;
    plVar1 = (long *)(param_1 + 0xf8);
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar5) {
        *plVar1 = *plVar1 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if ((param_3 & 1) != 0) {
      plVar1 = (long *)(param_1 + 0x130);
      Hint_Prefetch(plVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
        if (bVar5) {
          *plVar1 = *plVar1 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
    }
    if (*(short *)(*(long *)(param_1 + 0x280) + param_2 * 2) != 0) goto LAB_00103ad4;
  }
  _raw_spin_unlock_irqrestore(lVar8,uVar7);
  uVar10 = 1L << (param_2 & 0x3f);
  puVar2 = (ulong *)(*(long *)(param_1 + 0x248) + (param_2 >> 6 & 0x3ffffff) * 8);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    uVar11 = *puVar2;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar5) {
      *puVar2 = uVar11 & (uVar10 ^ 0xffffffffffffffff);
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  DataMemoryBarrier(2,3);
  if ((uVar11 & uVar10) == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x103b14);
    (*pcVar6)();
  }
  plVar1 = (long *)(param_1 + 0xd8);
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar5) {
      *plVar1 = *plVar1 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if ((param_3 & 1) != 0) {
    plVar1 = (long *)(param_1 + 0x118);
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar5) {
        *plVar1 = *plVar1 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
  lVar8 = param_1 + 0x2b8;
  uVar7 = _raw_spin_lock_irqsave(lVar8);
  uVar10 = 0;
  do {
    if ((*(ulong *)(*(long *)(param_1 + 0x248) +
                   ((param_2 & 0xffffffffffffffc0) + uVar10 >> 3 & 0x1ffffffffffffff8)) >>
         (uVar10 & 0x3f) & 1) != 0) goto LAB_00103ad4;
    uVar10 = uVar10 + 1;
  } while (uVar10 != 0x40);
  puVar2 = (ulong *)(*(long *)(param_1 + 0x288) + (param_2 >> 0xc & 0x3ffffff) * 8);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar5) {
      *puVar2 = *puVar2 & (1L << (param_2 >> 6 & 0x3f) ^ 0xffffffffffffffffU);
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
LAB_00103ad4:
  _raw_spin_unlock_irqrestore(lVar8,uVar7);
  return;
}



//------------------------------------------------------------
// zram_submit_bio @ 00103bc0 size=888
// signature: undefined zram_submit_bio(void)
// callers: []
//------------------------------------------------------------

void zram_submit_bio(long param_1)

{
  long *plVar1;
  ulong *puVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  bool bVar10;
  int iVar11;
  undefined8 uVar12;
  uint uVar13;
  ulong uVar14;
  long *plVar15;
  ulong uVar16;
  ulong uVar17;
  uint uVar18;
  uint uVar19;
  int local_80;
  uint local_7c;
  long local_78;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  uVar14 = *(ulong *)(param_1 + 0x20);
  uVar13 = *(uint *)(param_1 + 0x28);
  uVar17 = (ulong)uVar13;
  plVar15 = *(long **)(*(long *)(*(long *)(param_1 + 8) + 0x3f8) + 0x58);
  if ((((uVar14 & 7) != 0 || (uVar13 & 0xfff) != 0) || (CARRY8(uVar14,(ulong)(uVar13 >> 9)))) ||
     ((ulong)plVar15[0x33] >> 9 <= uVar14 || (ulong)plVar15[0x33] >> 9 < uVar14 + (uVar13 >> 9))) {
    plVar15 = plVar15 + 0x12;
    Hint_Prefetch(plVar15,2,0,1);
    do {
      cVar5 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(plVar15,0x10);
      if (bVar10) {
        *plVar15 = *plVar15 + 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    *(undefined1 *)(param_1 + 0x18) = 10;
  }
  else {
    uVar16 = uVar14 >> 3;
    uVar19 = (uint)uVar14 & 7;
    uVar18 = uVar19 * 0x200;
    if ((*(char *)(param_1 + 0x10) == '\t') || (*(char *)(param_1 + 0x10) == '\x03')) {
      if ((uVar14 & 7) != 0) {
        uVar18 = uVar19 * -0x200 + 0x1000;
        if (uVar13 <= uVar18) goto LAB_00103ef8;
        uVar17 = uVar17 - uVar18;
        uVar16 = (ulong)((int)uVar16 + 1);
      }
      if (0xfff < uVar17) {
        lVar8 = sp_el0;
LAB_00103c88:
        puVar2 = (ulong *)(*plVar15 + (uVar16 & 0xffffffff) * 0x28 + 8);
        *(int *)(lVar8 + 0x10) = *(int *)(lVar8 + 0x10) + 1;
        uVar13 = (uint)*puVar2;
        do {
          if ((uVar13 >> 0xd & 1) == 0) {
            Hint_Prefetch(puVar2,2,0,1);
            do {
              uVar14 = *puVar2;
              cVar5 = '\x01';
              bVar10 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar10) {
                *puVar2 = uVar14 | 0x2000;
                cVar5 = ExclusiveMonitorsStatus();
              }
            } while (cVar5 != '\0');
            if (((uint)uVar14 >> 0xd & 1) == 0) goto LAB_00103d14;
          }
          lVar7 = *(long *)(lVar8 + 0x10) + -1;
          *(int *)(lVar8 + 0x10) = (int)lVar7;
          if ((lVar7 == 0) || (*(long *)(lVar8 + 0x10) == 0)) {
            preempt_schedule();
          }
          do {
            Yield();
          } while (((uint)*puVar2 >> 0xd & 1) != 0);
          *(int *)(lVar8 + 0x10) = *(int *)(lVar8 + 0x10) + 1;
          uVar13 = (uint)*puVar2;
        } while( true );
      }
    }
    else {
      uVar12 = bio_start_io_acct(param_1);
      uVar13 = *(uint *)(param_1 + 0x28);
      if (uVar13 != 0) {
        local_80 = *(int *)(param_1 + 0x30);
        local_7c = *(uint *)(param_1 + 0x2c);
        do {
          plVar1 = (long *)(*(long *)(param_1 + 0x78) + (ulong)local_7c * 0x10);
          uVar19 = *(int *)((long)plVar1 + 0xc) + local_80;
          uVar6 = (int)plVar1[1] - local_80;
          local_6c = uVar19 & 0xfff;
          uVar4 = uVar13;
          if (uVar6 <= uVar13) {
            uVar4 = uVar6;
          }
          if (0x1000 - local_6c <= uVar4) {
            uVar4 = 0x1000 - local_6c;
          }
          local_78 = *plVar1 + (ulong)(uVar19 >> 0xc) * 0x40;
          uVar19 = uVar4;
          do {
            uVar9 = local_6c;
            uVar6 = 0x1000 - uVar18;
            if (uVar19 <= 0x1000 - uVar18) {
              uVar6 = uVar19;
            }
            local_70 = uVar6;
            iVar11 = zram_bvec_rw(plVar15,&local_78,uVar16 & 0xffffffff,
                                  *(undefined1 *)(param_1 + 0x10),param_1);
            if (iVar11 < 0) {
              *(undefined1 *)(param_1 + 0x18) = 10;
              break;
            }
            uVar3 = uVar6 + uVar18;
            local_6c = uVar6 + uVar9;
            uVar19 = uVar19 - uVar6;
            uVar18 = uVar3 & 0xfff;
            uVar16 = (ulong)((int)uVar16 + (uVar3 >> 0xc));
          } while (uVar19 != 0);
          if ((9 < *(byte *)(param_1 + 0x10)) ||
             ((1 << (ulong)(*(byte *)(param_1 + 0x10) & 0x1f) & 0x228U) == 0)) {
            iVar11 = uVar4 + local_80;
            bVar10 = iVar11 == *(int *)(*(long *)(param_1 + 0x78) + (ulong)local_7c * 0x10 + 8);
            if (bVar10) {
              local_7c = local_7c + 1;
            }
            local_80 = 0;
            if (!bVar10) {
              local_80 = iVar11;
            }
          }
          uVar13 = uVar13 - uVar4;
        } while (uVar13 != 0);
      }
      bio_end_io_acct_remapped(param_1,uVar12,*(undefined8 *)(param_1 + 8));
    }
  }
LAB_00103ef8:
  bio_endio(param_1);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00103d14:
  zram_free_page(plVar15,uVar16 & 0xffffffff);
  puVar2 = (ulong *)(*plVar15 + (uVar16 & 0xffffffff) * 0x28 + 8);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar5 = '\x01';
    bVar10 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar10) {
      *puVar2 = *puVar2 & 0xffffffffffffdfff;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  lVar7 = *(long *)(lVar8 + 0x10) + -1;
  *(int *)(lVar8 + 0x10) = (int)lVar7;
  if ((lVar7 == 0) || (*(long *)(lVar8 + 0x10) == 0)) {
    preempt_schedule();
  }
  plVar1 = plVar15 + 0x13;
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar5 = '\x01';
    bVar10 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar10) {
      *plVar1 = *plVar1 + 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  uVar16 = (ulong)((int)uVar16 + 1);
  uVar17 = uVar17 - 0x1000;
  if (uVar17 < 0x1000) goto LAB_00103ef8;
  goto LAB_00103c88;
}



//------------------------------------------------------------
// zram_open @ 00103f5c size=80
// signature: undefined zram_open(void)
// callers: []
//------------------------------------------------------------

undefined4 zram_open(long param_1)

{
  code *pcVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  uVar2 = mutex_is_locked(*(long *)(param_1 + 0x3f8) + 0x178);
  if ((uVar2 & 1) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103fac);
    (*pcVar1)();
  }
  uVar3 = 0;
  if (*(char *)(*(long *)(*(long *)(param_1 + 0x3f8) + 0x58) + 0x220) != '\0') {
    uVar3 = 0xfffffff0;
  }
  return uVar3;
}



//------------------------------------------------------------
// zram_rw_page @ 00103fb4 size=344
// signature: undefined zram_rw_page(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int zram_rw_page(long param_1,ulong param_2,undefined8 *param_3,uint param_4)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  undefined8 *local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  if (((uint)*param_3 >> 0x10 & 1) == 0) {
    lVar8 = *(long *)(*(long *)(param_1 + 0x3f8) + 0x58);
    if ((((param_2 & 7) == 0) && (param_2 < 0xfffffffffffffff8)) &&
       (uVar7 = *(ulong *)(lVar8 + 0x198) >> 9, param_2 < uVar7 && param_2 + 8 <= uVar7)) {
      uStack_50 = 0x1000;
      local_58 = param_3;
      uVar6 = bdev_start_io_acct(*(undefined8 *)(*(long *)(param_1 + 0x3f8) + 0x40),8,param_4,
                                 _jiffies);
      iVar5 = zram_bvec_rw(lVar8,&local_58,param_2 >> 3 & 0xffffffff,param_4,0);
      bdev_end_io_acct(*(undefined8 *)(*(long *)(param_1 + 0x3f8) + 0x40),param_4,uVar6);
      if (-1 < iVar5) {
        if (iVar5 == 1) {
          iVar5 = 0;
        }
        else {
          if (iVar5 != 0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1040c8);
            (*pcVar4)();
          }
          page_endio(param_3,param_4 & 1,0);
        }
      }
    }
    else {
      plVar1 = (long *)(lVar8 + 0x90);
      Hint_Prefetch(plVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
        if (bVar3) {
          *plVar1 = *plVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      iVar5 = -0x16;
    }
  }
  else {
    iVar5 = -0x20c;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// zram_slot_free_notify @ 00104124 size=308
// signature: undefined zram_slot_free_notify(void)
// callers: []
//------------------------------------------------------------

void zram_slot_free_notify(long param_1,ulong param_2)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  ulong *puVar6;
  ulong uVar7;
  long *plVar8;
  
  plVar8 = *(long **)(*(long *)(param_1 + 0x3f8) + 0x58);
  plVar1 = plVar8 + 0x13;
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar3) {
      *plVar1 = *plVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  lVar5 = *plVar8;
  lVar4 = sp_el0;
  *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
  puVar6 = (ulong *)(lVar5 + (param_2 & 0xffffffff) * 0x28 + 8);
  if (((uint)*puVar6 >> 0xd & 1) == 0) {
    Hint_Prefetch(puVar6,2,0,1);
    do {
      uVar7 = *puVar6;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar6,0x10);
      if (bVar3) {
        *puVar6 = uVar7 | 0x2000;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (((uint)uVar7 >> 0xd & 1) == 0) {
      zram_free_page(plVar8,param_2);
      puVar6 = (ulong *)(*plVar8 + param_2 * 0x28 + 8);
      Hint_Prefetch(puVar6,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar6,0x10);
        if (bVar3) {
          *puVar6 = *puVar6 & 0xffffffffffffdfff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar5 = *(long *)(lVar4 + 0x10) + -1;
      *(int *)(lVar4 + 0x10) = (int)lVar5;
      if ((lVar5 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
        preempt_schedule();
        return;
      }
      return;
    }
  }
  lVar5 = *(long *)(lVar4 + 0x10) + -1;
  *(int *)(lVar4 + 0x10) = (int)lVar5;
  if ((lVar5 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
    preempt_schedule();
  }
  plVar8 = plVar8 + 0x1a;
  Hint_Prefetch(plVar8,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(plVar8,0x10);
    if (bVar3) {
      *plVar8 = *plVar8 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// zram_bvec_rw @ 00104288 size=2580
// signature: undefined zram_bvec_rw(void)
// callers: [zram_submit_bio, zram_rw_page]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

ulong zram_bvec_rw(long *param_1,ulong *param_2,uint param_3,uint param_4,undefined8 param_5)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  void *__dest;
  undefined8 uVar7;
  void *__src;
  uint uVar8;
  long *plVar9;
  ulong *puVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  undefined8 *puVar18;
  long *plVar19;
  uint local_6c;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  if ((param_4 & 1) == 0) {
    plVar19 = param_1 + 0xe;
    Hint_Prefetch(plVar19,2,0,1);
    do {
      cVar1 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar19,0x10);
      if (bVar3) {
        *plVar19 = *plVar19 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    uVar4 = zram_bvec_read(param_1,param_2,param_3,param_5);
    uVar4 = uVar4 & 0xffffffff;
    flush_dcache_page(*param_2);
  }
  else {
    plVar19 = param_1 + 0xf;
    Hint_Prefetch(plVar19,2,0,1);
    do {
      cVar1 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar19,0x10);
      if (bVar3) {
        *plVar19 = *plVar19 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    local_6c = 0;
    uVar11 = *param_2;
    if (((am_app_launch == 0) || (param_3 == 0)) ||
       (lVar17 = sp_el0, (*(uint *)(lVar17 + 0x44) >> 0x11 & 1) != 0)) {
      lVar17 = sp_el0;
      uVar15 = (ulong)param_3;
      plVar19 = (long *)(lVar17 + 0x10);
      puVar10 = (ulong *)(*param_1 + (ulong)param_3 * 0x28 + 8);
      *(int *)plVar19 = *(int *)plVar19 + 1;
      uVar8 = (uint)*puVar10;
      do {
        if ((uVar8 >> 0xd & 1) == 0) {
          Hint_Prefetch(puVar10,2,0,1);
          do {
            uVar4 = *puVar10;
            cVar1 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
            if (bVar3) {
              *puVar10 = uVar4 | 0x2000;
              cVar1 = ExclusiveMonitorsStatus();
            }
          } while (cVar1 != '\0');
          if (((uint)uVar4 >> 0xd & 1) == 0) goto LAB_001043d8;
        }
        lVar14 = *plVar19;
        *(int *)plVar19 = (int)(lVar14 + -1);
        if ((lVar14 + -1 == 0) || (*plVar19 == 0)) {
          preempt_schedule();
        }
        do {
          Yield();
        } while (((uint)*puVar10 >> 0xd & 1) != 0);
        *(int *)plVar19 = *(int *)plVar19 + 1;
        uVar8 = (uint)*puVar10;
      } while( true );
    }
    uVar4 = 0xfffffff0;
  }
LAB_00104b2c:
  lVar17 = sp_el0;
  puVar10 = (ulong *)(*param_1 + (ulong)param_3 * 0x28 + 8);
  *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
  uVar8 = (uint)*puVar10;
  do {
    if ((uVar8 >> 0xd & 1) == 0) {
      Hint_Prefetch(puVar10,2,0,1);
      do {
        uVar11 = *puVar10;
        cVar1 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
        if (bVar3) {
          *puVar10 = uVar11 | 0x2000;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      if (((uint)uVar11 >> 0xd & 1) == 0) {
        lVar14 = (ulong)param_3 * 0x28;
        *(ulong *)(*param_1 + lVar14 + 8) = *(ulong *)(*param_1 + lVar14 + 8) & 0xfffffffffffbffff;
        uVar7 = ktime_get_with_offset(1);
        *(undefined8 *)(*param_1 + lVar14 + 0x10) = uVar7;
        puVar10 = (ulong *)(*param_1 + lVar14 + 8);
        Hint_Prefetch(puVar10,2,0,1);
        do {
          cVar1 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
          if (bVar3) {
            *puVar10 = *puVar10 & 0xffffffffffffdfff;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        lVar14 = *(long *)(lVar17 + 0x10) + -1;
        *(int *)(lVar17 + 0x10) = (int)lVar14;
        if ((lVar14 == 0) || (*(long *)(lVar17 + 0x10) == 0)) {
          preempt_schedule();
        }
        if ((int)uVar4 < 0) {
          if ((param_4 & 1) == 0) {
            param_1 = param_1 + 0x10;
            Hint_Prefetch(param_1,2,0,1);
            do {
              cVar1 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
              if (bVar3) {
                *param_1 = *param_1 + 1;
                cVar1 = ExclusiveMonitorsStatus();
              }
            } while (cVar1 != '\0');
          }
          else {
            param_1 = param_1 + 0x11;
            Hint_Prefetch(param_1,2,0,1);
            do {
              cVar1 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(param_1,0x10);
              if (bVar3) {
                *param_1 = *param_1 + 1;
                cVar1 = ExclusiveMonitorsStatus();
              }
            } while (cVar1 != '\0');
          }
        }
        lVar17 = sp_el0;
        if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return uVar4;
      }
    }
    lVar14 = *(long *)(lVar17 + 0x10) + -1;
    *(int *)(lVar17 + 0x10) = (int)lVar14;
    if ((lVar14 == 0) || (*(long *)(lVar17 + 0x10) == 0)) {
      preempt_schedule();
    }
    do {
      Yield();
    } while (((uint)*puVar10 >> 0xd & 1) != 0);
    *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
    uVar8 = (uint)*puVar10;
  } while( true );
LAB_001043d8:
  lVar14 = *param_1 + uVar15 * 0x28;
  puVar10 = (ulong *)(lVar14 + 8);
  if ((*(byte *)(lVar14 + 10) & 1) == 0) {
    Hint_Prefetch(puVar10,2,0,1);
    do {
      cVar1 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
      if (bVar3) {
        *puVar10 = *puVar10 & 0xffffffffffffdfff;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    lVar14 = *plVar19;
    *(int *)plVar19 = (int)(lVar14 + -1);
    if ((lVar14 + -1 == 0) || (*plVar19 == 0)) {
      preempt_schedule();
    }
    *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
    *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + 1;
    uVar13 = (uVar11 & 0x3ffffffffffc0) << 6;
    plVar9 = (long *)(uVar13 | 0xff00000000000000);
    lVar14 = *plVar9;
    if (lVar14 == plVar9[0x1ff]) {
      lVar12 = 8;
      do {
        if (lVar14 != *(long *)((long)plVar9 + lVar12)) goto LAB_001044bc;
        lVar12 = lVar12 + 8;
      } while (lVar12 != 0xff8);
      *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + -1;
      lVar12 = *(long *)(lVar17 + 0x10) + -1;
      *(int *)(lVar17 + 0x10) = (int)lVar12;
      if ((lVar12 == 0) || (*plVar19 == 0)) {
        preempt_schedule();
      }
      plVar9 = param_1 + 0x14;
      Hint_Prefetch(plVar9,2,0,1);
      do {
        cVar1 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar9,0x10);
        if (bVar3) {
          *plVar9 = *plVar9 + 1;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      uVar16 = 0xfffffffffffffff4;
      bVar3 = true;
      lVar17 = 0xe;
    }
    else {
LAB_001044bc:
      *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + -1;
      lVar14 = *(long *)(lVar17 + 0x10) + -1;
      *(int *)(lVar17 + 0x10) = (int)lVar14;
      if ((lVar14 == 0) || (*plVar19 == 0)) {
        preempt_schedule();
      }
      uVar16 = 0xfffffffffffffff4;
      do {
        puVar18 = (undefined8 *)zcomp_stream_get(param_1[2]);
        *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
        *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + 1;
        uVar5 = zcomp_compress(puVar18,uVar13 | 0xff00000000000000,&local_6c);
        uVar4 = uVar5 & 0xffffffff;
        *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + -1;
        lVar14 = *(long *)(lVar17 + 0x10) + -1;
        *(int *)(lVar17 + 0x10) = (int)lVar14;
        if ((lVar14 == 0) || (*plVar19 == 0)) {
          preempt_schedule();
        }
        if ((int)uVar5 != 0) {
          zcomp_stream_put(param_1[2]);
          _printk(&DAT_0010c8e1,uVar4);
          zs_free(param_1[1],uVar16);
          goto LAB_00104b2c;
        }
        uVar4 = (ulong)local_6c;
        if (huge_class_size <= uVar4) {
          uVar4 = 0x1000;
          local_6c = 0x1000;
        }
        if (0xfffffffffffff000 < uVar16) {
          uVar16 = zs_malloc(param_1[1],uVar4,0x800280a);
        }
        if (uVar16 < 0xfffffffffffff001) goto LAB_00104644;
        zcomp_stream_put(param_1[2]);
        plVar9 = param_1 + 0x19;
        Hint_Prefetch(plVar9,2,0,1);
        do {
          cVar1 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(plVar9,0x10);
          if (bVar3) {
            *plVar9 = *plVar9 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        uVar16 = zs_malloc(param_1[1],local_6c,0x8000c0a);
        if (0xfffffffffffff000 < uVar16) {
          uVar4 = uVar16 & 0xffffffff;
          goto LAB_00104b2c;
        }
      } while (local_6c != 0x1000);
      puVar18 = (undefined8 *)zcomp_stream_get(param_1[2]);
LAB_00104644:
      uVar5 = zs_get_total_pages(param_1[1]);
      puVar10 = (ulong *)(param_1 + 0x18);
      uVar4 = *puVar10;
      do {
        if (uVar5 <= uVar4) break;
        Hint_Prefetch(puVar10,2,0,1);
        do {
          uVar6 = *puVar10;
          if (uVar6 != uVar4) goto LAB_0010467c;
          cVar1 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
          if (bVar3) {
            *puVar10 = uVar5;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010467c:
        bVar3 = uVar6 != uVar4;
        uVar4 = uVar6;
      } while (bVar3);
      if ((param_1[0xc] != 0) && ((ulong)param_1[0xc] < uVar5)) {
        zcomp_stream_put(param_1[2]);
        zs_free(param_1[1],uVar16);
        uVar4 = 0xfffffff4;
        goto LAB_00104b2c;
      }
      __dest = (void *)zs_map_object(param_1[1],uVar16,2);
      if (local_6c == 0x1000) {
        *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
        *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + 1;
        __src = (void *)(uVar13 | 0xff00000000000000);
      }
      else {
        __src = (void *)*puVar18;
      }
      memcpy(__dest,__src,(ulong)local_6c);
      if (local_6c == 0x1000) {
        *(int *)(lVar17 + 0xb68) = *(int *)(lVar17 + 0xb68) + -1;
        lVar14 = *(long *)(lVar17 + 0x10) + -1;
        *(int *)(lVar17 + 0x10) = (int)lVar14;
        if ((lVar14 == 0) || (*plVar19 == 0)) {
          preempt_schedule();
        }
      }
      zcomp_stream_put(param_1[2]);
      zs_unmap_object(param_1[1],uVar16);
      bVar3 = false;
      lVar14 = 0;
      plVar9 = param_1 + 0xd;
      Hint_Prefetch(plVar9,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(plVar9,0x10);
        if (bVar2) {
          *plVar9 = *plVar9 + (ulong)local_6c;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      lVar17 = 0;
    }
    puVar10 = (ulong *)(*param_1 + uVar15 * 0x28 + 8);
    *(int *)plVar19 = *(int *)plVar19 + 1;
    uVar8 = (uint)*puVar10;
    do {
      if ((uVar8 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar10,2,0,1);
        do {
          uVar4 = *puVar10;
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
          if (bVar2) {
            *puVar10 = uVar4 | 0x2000;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        if (((uint)uVar4 >> 0xd & 1) == 0) goto LAB_00104830;
      }
      lVar12 = *plVar19;
      *(int *)plVar19 = (int)(lVar12 + -1);
      if ((lVar12 + -1 == 0) || (*plVar19 == 0)) {
        preempt_schedule();
      }
      do {
        Yield();
      } while (((uint)*puVar10 >> 0xd & 1) != 0);
      *(int *)plVar19 = *(int *)plVar19 + 1;
      uVar8 = (uint)*puVar10;
    } while( true );
  }
  Hint_Prefetch(puVar10,2,0,1);
  do {
    cVar1 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
    if (bVar3) {
      *puVar10 = *puVar10 & 0xffffffffffffdfff;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  lVar17 = *plVar19;
  *(int *)plVar19 = (int)(lVar17 + -1);
  if ((lVar17 + -1 == 0) || (*plVar19 == 0)) {
    preempt_schedule();
  }
  _printk(&DAT_0010c483,param_3);
  uVar4 = 0xfffffff0;
  goto LAB_00104b2c;
LAB_00104830:
  zram_free_page(param_1,uVar15);
  if (local_6c == 0x1000) {
    lVar12 = *param_1 + uVar15 * 0x28;
    *(ulong *)(lVar12 + 8) = *(ulong *)(lVar12 + 8) | 0x20000;
    plVar9 = param_1 + 0x15;
    Hint_Prefetch(plVar9,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(plVar9,0x10);
      if (bVar2) {
        *plVar9 = *plVar9 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    plVar9 = param_1 + 0x16;
    Hint_Prefetch(plVar9,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(plVar9,0x10);
      if (bVar2) {
        *plVar9 = *plVar9 + 1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    if (bVar3) goto LAB_00104888;
LAB_001049f4:
    *(ulong *)(*param_1 + uVar15 * 0x28) = uVar16;
    lVar17 = *param_1 + uVar15 * 0x28;
    *(ulong *)(lVar17 + 8) = *(ulong *)(lVar17 + 8) & 0xffffffffffffe000 | (ulong)local_6c;
    if ((*(ulong *)(uVar11 + 8) & 1) != 0) {
      uVar11 = *(ulong *)(uVar11 + 8) - 1;
    }
    uVar4 = *(ulong *)(uVar11 + 0x38) & 0xfffffffffffffffc;
    if (((uint)*(ulong *)(uVar11 + 0x38) >> 1 & 1) != 0) {
      uVar4 = *(ulong *)(uVar4 + 0x10);
    }
    if ((uVar4 == 0) || (*(int *)(uVar4 + 0x4d8) != 99)) {
      uVar7 = _raw_spin_lock_irqsave(param_1 + 0x56);
      lVar17 = *param_1;
      puVar18 = (undefined8 *)param_1[0x55];
      plVar9 = (long *)(lVar17 + uVar15 * 0x28 + 0x18);
      uVar4 = __list_add_valid(plVar9,puVar18,param_1 + 0x54);
      if ((uVar4 & 1) != 0) {
        param_1[0x55] = (long)plVar9;
        *plVar9 = (long)(param_1 + 0x54);
        *(undefined8 **)(lVar17 + uVar15 * 0x28 + 0x20) = puVar18;
        *puVar18 = plVar9;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x56,uVar7);
      lVar17 = *param_1 + uVar15 * 0x28;
      *(ulong *)(lVar17 + 8) = *(ulong *)(lVar17 + 8) | 0x800000;
      plVar9 = param_1 + 0x2c;
      Hint_Prefetch(plVar9,2,0,1);
      do {
        cVar1 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(plVar9,0x10);
        if (bVar3) {
          *plVar9 = *plVar9 + 1;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
    }
  }
  else {
    if (!bVar3) goto LAB_001049f4;
LAB_00104888:
    lVar12 = *param_1 + uVar15 * 0x28;
    *(ulong *)(lVar12 + 8) = *(ulong *)(lVar12 + 8) | 1L << lVar17;
    *(long *)(*param_1 + uVar15 * 0x28) = lVar14;
  }
  puVar10 = (ulong *)(*param_1 + uVar15 * 0x28 + 8);
  Hint_Prefetch(puVar10,2,0,1);
  do {
    cVar1 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
    if (bVar3) {
      *puVar10 = *puVar10 & 0xffffffffffffdfff;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  lVar17 = *plVar19;
  *(int *)plVar19 = (int)(lVar17 + -1);
  if ((lVar17 + -1 == 0) || (*plVar19 == 0)) {
    preempt_schedule();
  }
  plVar19 = param_1 + 0x17;
  Hint_Prefetch(plVar19,2,0,1);
  do {
    cVar1 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(plVar19,0x10);
    if (bVar3) {
      *plVar19 = *plVar19 + 1;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  uVar4 = 0;
  goto LAB_00104b2c;
}



//------------------------------------------------------------
// bit_spin_unlock @ 00104d98 size=92
// signature: undefined bit_spin_unlock(void)
// callers: [zram_handle_comp_page]
//------------------------------------------------------------

void bit_spin_unlock(ulong *param_1)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  long lVar4;
  
  Hint_Prefetch(param_1,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(param_1,0x10);
    if (bVar2) {
      *param_1 = *param_1 & 0xffffffffffffdfff;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  lVar4 = sp_el0;
  lVar3 = *(long *)(lVar4 + 0x10) + -1;
  *(int *)(lVar4 + 0x10) = (int)lVar3;
  if ((lVar3 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
    preempt_schedule();
  }
  return;
}



//------------------------------------------------------------
// zram_bvec_read @ 00104dfc size=1920
// signature: undefined zram_bvec_read(void)
// callers: [writeback_store, zram_bvec_rw]
//------------------------------------------------------------

int zram_bvec_read(long *param_1,ulong *param_2,uint param_3,long param_4)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  void *__src;
  undefined8 uVar5;
  undefined8 uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong *puVar10;
  long *plVar11;
  ulong *puVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  long *plVar16;
  long *plVar17;
  ulong uVar18;
  ulong uVar19;
  ulong local_78;
  undefined8 local_70;
  long local_68;
  
  lVar15 = sp_el0;
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  uVar18 = (ulong)param_3;
  uVar19 = *param_2;
  plVar17 = (long *)(lVar13 + 0x10);
  puVar10 = (ulong *)(*param_1 + (ulong)param_3 * 0x28 + 8);
  *(int *)plVar17 = *(int *)plVar17 + 1;
  uVar7 = (uint)*puVar10;
  do {
    if ((uVar7 >> 0xd & 1) == 0) {
      Hint_Prefetch(puVar10,2,0,1);
      do {
        uVar8 = *puVar10;
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
        if (bVar2) {
          *puVar10 = uVar8 | 0x2000;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      if (((uint)uVar8 >> 0xd & 1) == 0) break;
    }
    lVar15 = *plVar17;
    *(int *)plVar17 = (int)(lVar15 + -1);
    if ((lVar15 + -1 == 0) || (*plVar17 == 0)) {
      preempt_schedule();
    }
    do {
      Yield();
    } while (((uint)*puVar10 >> 0xd & 1) != 0);
    *(int *)plVar17 = *(int *)plVar17 + 1;
    uVar7 = (uint)*puVar10;
  } while( true );
  uVar8 = *(ulong *)(*param_1 + uVar18 * 0x28 + 8);
  if (((uint)uVar8 >> 0xf & 1) == 0) {
    lVar15 = *(long *)(*param_1 + uVar18 * 0x28);
    if (lVar15 == 0 || (uVar8 & 0x4000) != 0) {
      *(int *)(lVar13 + 0x10) = *(int *)(lVar13 + 0x10) + 1;
      *(int *)(lVar13 + 0xb68) = *(int *)(lVar13 + 0xb68) + 1;
      memset64((uVar19 & 0x3ffffffffffc0) << 6 | 0xff00000000000000,lVar15,0x200);
      *(int *)(lVar13 + 0xb68) = *(int *)(lVar13 + 0xb68) + -1;
      lVar15 = *(long *)(lVar13 + 0x10) + -1;
      *(int *)(lVar13 + 0x10) = (int)lVar15;
      if ((lVar15 == 0) || (*plVar17 == 0)) {
        preempt_schedule();
      }
      puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
      Hint_Prefetch(puVar10,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
        if (bVar2) {
          *puVar10 = *puVar10 & 0xffffffffffffdfff;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
    }
    else {
      if ((uVar8 & 0x1fff) == 0x1000) {
        __src = (void *)zs_map_object(param_1[1],lVar15,1);
        *(int *)(lVar13 + 0x10) = *(int *)(lVar13 + 0x10) + 1;
        *(int *)(lVar13 + 0xb68) = *(int *)(lVar13 + 0xb68) + 1;
        memcpy((void *)((uVar19 & 0x3ffffffffffc0) << 6 | 0xff00000000000000),__src,0x1000);
        *(int *)(lVar13 + 0xb68) = *(int *)(lVar13 + 0xb68) + -1;
        lVar3 = *(long *)(lVar13 + 0x10) + -1;
        *(int *)(lVar13 + 0x10) = (int)lVar3;
        if ((lVar3 == 0) || (*plVar17 == 0)) {
          preempt_schedule();
        }
      }
      else {
        uVar7 = (uint)uVar8 & 0x1fff;
        uVar6 = zcomp_stream_get(param_1[2]);
        uVar5 = zs_map_object(param_1[1],lVar15,1);
        *(int *)(lVar13 + 0x10) = *(int *)(lVar13 + 0x10) + 1;
        *(int *)(lVar13 + 0xb68) = *(int *)(lVar13 + 0xb68) + 1;
        iVar4 = zcomp_decompress(uVar6,uVar5,uVar7,
                                 (uVar19 & 0x3ffffffffffc0) << 6 | 0xff00000000000000);
        *(int *)(lVar13 + 0xb68) = *(int *)(lVar13 + 0xb68) + -1;
        lVar3 = *(long *)(lVar13 + 0x10) + -1;
        *(int *)(lVar13 + 0x10) = (int)lVar3;
        if ((lVar3 == 0) || (*plVar17 == 0)) {
          preempt_schedule();
        }
        zcomp_stream_put(param_1[2]);
        if (iVar4 != 0) {
          handle_decomp_fail(param_1 + 0x34,iVar4,param_3,uVar5,uVar7,0);
          goto LAB_001054bc;
        }
      }
      zs_unmap_object(param_1[1],lVar15);
      puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
      uVar19 = *puVar10;
      if (((uint)uVar19 >> 0x16 & 1) != 0) {
        *puVar10 = uVar19 & 0xffffffffffbfffff;
      }
      uVar6 = _raw_spin_lock_irqsave(param_1 + 0x56);
      lVar15 = *param_1;
      plVar16 = (long *)(lVar15 + uVar18 * 0x28 + 0x18);
      if ((long *)*plVar16 != plVar16) {
        uVar19 = __list_del_entry_valid(plVar16);
        if ((uVar19 & 1) != 0) {
          lVar13 = *plVar16;
          plVar11 = *(long **)(lVar15 + uVar18 * 0x28 + 0x20);
          *(long **)(lVar13 + 8) = plVar11;
          *plVar11 = lVar13;
        }
        *plVar16 = (long)plVar16;
        *(long **)(lVar15 + uVar18 * 0x28 + 0x20) = plVar16;
        puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
        uVar19 = *puVar10;
        if (((uint)uVar19 >> 0x17 & 1) != 0) {
          *puVar10 = uVar19 & 0xffffffffff7fffff;
          plVar16 = param_1 + 0x2c;
          Hint_Prefetch(plVar16,2,0,1);
          do {
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
            if (bVar2) {
              *plVar16 = *plVar16 + -1;
              cVar1 = ExclusiveMonitorsStatus();
            }
          } while (cVar1 != '\0');
        }
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x56,uVar6);
      puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
      Hint_Prefetch(puVar10,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
        if (bVar2) {
          *puVar10 = *puVar10 & 0xffffffffffffdfff;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
    }
    lVar15 = *plVar17;
    *(int *)plVar17 = (int)(lVar15 + -1);
    if ((lVar15 + -1 == 0) || (*plVar17 == 0)) {
      preempt_schedule();
    }
    iVar4 = 0;
  }
  else {
    uVar8 = ktime_get_seconds();
    if (param_4 == 0) {
      puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
      Hint_Prefetch(puVar10,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
        if (bVar2) {
          *puVar10 = *puVar10 & 0xffffffffffffdfff;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      lVar15 = *plVar17;
      *(int *)plVar17 = (int)(lVar15 + -1);
      if ((lVar15 + -1 == 0) || (*plVar17 == 0)) {
        preempt_schedule();
      }
      iVar4 = -0x5f;
    }
    else {
      local_70 = 0x1000;
      uVar9 = *(ulong *)(*param_1 + uVar18 * 0x28 + 0x10);
      uVar14 = 0;
      if (uVar9 <= uVar8) {
        uVar14 = uVar8 - uVar9;
      }
      if (uVar14 < wb_duration_limit_1) {
        plVar16 = param_1 + 0x2d;
        Hint_Prefetch(plVar16,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
          if (bVar2) {
            *plVar16 = *plVar16 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
      }
      else if (uVar14 < wb_duration_limit_2) {
        plVar16 = param_1 + 0x2e;
        Hint_Prefetch(plVar16,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
          if (bVar2) {
            *plVar16 = *plVar16 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
      }
      else {
        plVar16 = param_1 + 0x2f;
        Hint_Prefetch(plVar16,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
          if (bVar2) {
            *plVar16 = *plVar16 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
      }
      plVar16 = param_1 + 0x2a;
      Hint_Prefetch(plVar16,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
        if (bVar2) {
          *plVar16 = *plVar16 + 1;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      uVar8 = *(ulong *)(*param_1 + uVar18 * 0x28 + 8);
      if (((uint)uVar8 >> 0x15 & 1) != 0) {
        plVar16 = param_1 + 0x24;
        Hint_Prefetch(plVar16,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
          if (bVar2) {
            *plVar16 = *plVar16 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
      }
      uVar8 = uVar8 & 0x200000;
      puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
      uVar14 = *puVar10;
      if (((uint)uVar14 >> 0x13 & 1) == 0) {
        *puVar10 = uVar14 | 0x80000;
        plVar16 = param_1 + 0x1e;
        Hint_Prefetch(plVar16,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(plVar16,0x10);
          if (bVar2) {
            *plVar16 = *plVar16 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
      }
      puVar10 = (ulong *)(*param_1 + uVar18 * 0x28);
      puVar12 = puVar10 + 1;
      uVar9 = *puVar10;
      uVar14 = uVar9 >> 0x18;
      local_78 = uVar19;
      if ((uVar9 & 0xfff) == 0 && uVar8 == 0) {
        Hint_Prefetch(puVar12,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(puVar12,0x10);
          if (bVar2) {
            *puVar12 = *puVar12 & 0xffffffffffffdfff;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        lVar15 = *plVar17;
        *(int *)plVar17 = (int)(lVar15 + -1);
        if ((lVar15 + -1 == 0) || (*plVar17 == 0)) {
          preempt_schedule();
        }
        plVar17 = param_1 + 0x1c;
        Hint_Prefetch(plVar17,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(plVar17,0x10);
          if (bVar2) {
            *plVar17 = *plVar17 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        lVar15 = bio_alloc_bioset(param_1[0x48],1,*(undefined4 *)(param_4 + 0x10),0xc00,&fs_bio_set)
        ;
        if (lVar15 == 0) {
          iVar4 = -0xc;
        }
        else {
          *(ulong *)(lVar15 + 0x20) = uVar14 << 3;
          iVar4 = bio_add_page(lVar15,local_78,local_70 & 0xffffffff,local_70._4_4_);
          if (iVar4 == 0) {
            bio_put(lVar15);
            iVar4 = -5;
          }
          else {
            bio_chain(lVar15,param_4);
            submit_bio(lVar15);
            iVar4 = 1;
          }
        }
      }
      else {
        *puVar12 = *puVar12 | 0x100000;
        uVar6 = _raw_spin_lock_irqsave((long)param_1 + 0x2b4);
        lVar15 = param_1[0x50];
        if (lVar15 != 0) {
          *(short *)(lVar15 + uVar14 * 2) = *(short *)(lVar15 + uVar14 * 2) + 1;
        }
        _raw_spin_unlock_irqrestore((long)param_1 + 0x2b4,uVar6);
        puVar10 = (ulong *)(*param_1 + uVar18 * 0x28 + 8);
        Hint_Prefetch(puVar10,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
          if (bVar2) {
            *puVar10 = *puVar10 & 0xffffffffffffdfff;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        lVar15 = *plVar17;
        *(int *)plVar17 = (int)(lVar15 + -1);
        if ((lVar15 + -1 == 0) || (*plVar17 == 0)) {
          preempt_schedule();
        }
        iVar4 = read_comp_from_bdev(param_1,&local_78,uVar9,param_4,uVar8 != 0);
        if (iVar4 < 0) {
          zram_dec_wb_table(param_1,uVar14,uVar8 != 0);
        }
      }
    }
  }
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) == local_68) {
    return iVar4;
  }
LAB_001054bc:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// kmap_atomic @ 00105630 size=52
// signature: undefined kmap_atomic(void)
// callers: [print_hex_dump_pages]
//------------------------------------------------------------

ulong kmap_atomic(ulong param_1)

{
  long lVar1;
  
  lVar1 = sp_el0;
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
  *(int *)(lVar1 + 0xb68) = *(int *)(lVar1 + 0xb68) + 1;
  return (param_1 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
}



//------------------------------------------------------------
// __kunmap_atomic @ 0010566c size=72
// signature: undefined __kunmap_atomic(void)
// callers: [print_hex_dump_pages]
//------------------------------------------------------------

void __kunmap_atomic(void)

{
  long lVar1;
  long lVar2;
  
  lVar2 = sp_el0;
  *(int *)(lVar2 + 0xb68) = *(int *)(lVar2 + 0xb68) + -1;
  lVar1 = *(long *)(lVar2 + 0x10) + -1;
  *(int *)(lVar2 + 0x10) = (int)lVar1;
  if ((lVar1 == 0) || (*(long *)(lVar2 + 0x10) == 0)) {
    preempt_schedule();
  }
  return;
}



//------------------------------------------------------------
// read_comp_from_bdev @ 001056b4 size=668
// signature: undefined read_comp_from_bdev(void)
// callers: [zram_bvec_read, zram_writeback_oem_func]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
read_comp_from_bdev(long param_1,undefined8 *param_2,ulong param_3,long param_4,byte param_5)

{
  long *plVar1;
  ulong uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  uint uVar10;
  undefined8 uVar11;
  long lVar12;
  
  uVar10 = 0x40;
  if ((param_5 & 1) == 0) {
    uVar10 = 1;
  }
  plVar1 = (long *)(param_1 + 0xe0);
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar4) {
      *plVar1 = *plVar1 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  lVar7 = bio_alloc_bioset(*(undefined8 *)(param_1 + 0x240),(ulong)uVar10,0,0xc00,&fs_bio_set);
  if (lVar7 == 0) {
    return 0xfffffff4;
  }
  lVar8 = kmalloc_trace(_blk_queue_physical_block_size,0xd00,0x268);
  if (lVar8 == 0) goto LAB_001058c0;
  lVar12 = 0;
  *(uint *)(lVar8 + 0x260) = uVar10;
  do {
    uVar11 = tpidr_el1;
    lVar9 = __alloc_pages(uVar11,0xc02,0,0,0);
    if (lVar12 == 0x40) goto LAB_0010593c;
    *(long *)(lVar8 + lVar12 * 8 + 0x30) = lVar9;
    if (lVar9 == 0) {
      _printk(&DAT_0010c9df,"alloc_zw_pages");
      iVar6 = *(int *)(lVar8 + 0x260);
      if (iVar6 < 1) goto LAB_001058b8;
      lVar12 = 0;
      goto LAB_00105914;
    }
    lVar12 = lVar12 + 1;
  } while (lVar12 < *(int *)(lVar8 + 0x260));
  if (param_2 == (undefined8 *)0x0) {
    uVar11 = 0;
  }
  else {
    uVar11 = *param_2;
  }
  *(undefined8 *)(lVar8 + 0x230) = uVar11;
  uVar2 = 0x7fffffffe00;
  if ((param_5 & 1) == 0) {
    uVar2 = 0x7fffffffff8;
  }
  lVar12 = 0;
  *(long *)(lVar8 + 0x250) = param_1;
  *(ulong *)(lVar8 + 600) = param_3;
  *(long *)(lVar8 + 0x238) = lVar7;
  *(byte *)(lVar8 + 0x264) = param_5 & 1;
  *(long *)(*(long *)(lVar8 + 0x30) + 0x28) = lVar8;
  *(ulong *)(lVar7 + 0x20) = uVar2 & param_3 >> 0x15;
  do {
    if (lVar12 == 0x200) goto LAB_0010593c;
    iVar6 = bio_add_page(lVar7,*(undefined8 *)(lVar8 + lVar12 + 0x30),0x1000,0);
    if (iVar6 == 0) {
      if (*(int *)(lVar8 + 0x260) < 1) goto LAB_00105898;
      lVar12 = 0;
      goto LAB_00105870;
    }
    lVar12 = lVar12 + 8;
  } while ((ulong)uVar10 * 8 != lVar12);
  *(code **)(lVar7 + 0x38) = zram_comp_page_end_io;
  if (param_4 == 0) {
LAB_0010584c:
    submit_bio(lVar7);
    return 1;
  }
  lVar12 = bio_alloc_bioset(*(undefined8 *)(param_1 + 0x240),1,0,0xc00,&fs_bio_set);
  *(long *)(lVar8 + 0x240) = lVar12;
  if (lVar12 != 0) {
    *(undefined4 *)(lVar12 + 0x10) = *(undefined4 *)(param_4 + 0x10);
    bio_chain(*(undefined8 *)(lVar8 + 0x240),param_4);
    goto LAB_0010584c;
  }
  free_zw_pages(lVar8);
  goto LAB_001058b8;
  while( true ) {
    __free_pages(lVar9,0);
    lVar12 = lVar12 + 1;
    if (*(int *)(lVar8 + 0x260) <= lVar12) break;
LAB_00105870:
    if (lVar12 == 0x40) {
LAB_0010593c:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x105940);
      (*pcVar5)();
    }
    lVar9 = *(long *)(lVar8 + 0x30 + lVar12 * 8);
    if (lVar9 == 0) break;
  }
LAB_00105898:
  kfree(lVar8);
  bio_put(lVar7);
  return 0xfffffffb;
  while( true ) {
    __free_pages(lVar9,0);
    lVar12 = lVar12 + 1;
    if (iVar6 <= lVar12) break;
LAB_00105914:
    if (lVar12 == 0x40) goto LAB_0010593c;
    lVar9 = *(long *)(lVar8 + 0x30 + lVar12 * 8);
    if (lVar9 == 0) break;
  }
LAB_001058b8:
  kfree(lVar8);
LAB_001058c0:
  bio_put(lVar7);
  return 0xfffffff4;
}



//------------------------------------------------------------
// zram_dec_wb_table @ 0010595c size=376
// signature: undefined zram_dec_wb_table(void)
// callers: [zram_bvec_read, zram_writeback_oem_func, zram_handle_comp_page]
//------------------------------------------------------------

void zram_dec_wb_table(long param_1,ulong param_2,uint param_3)

{
  long *plVar1;
  ulong *puVar2;
  short sVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  
  lVar7 = param_1 + 0x2b4;
  uVar6 = _raw_spin_lock_irqsave(lVar7);
  lVar8 = *(long *)(param_1 + 0x280);
  if (lVar8 != 0) {
    lVar10 = param_2 * 2;
    *(short *)(lVar8 + lVar10) = *(short *)(lVar8 + lVar10) + -1;
    sVar3 = *(short *)(*(long *)(param_1 + 0x280) + lVar10);
    _raw_spin_unlock_irqrestore(lVar7,uVar6);
    if (sVar3 != 0) {
      return;
    }
    puVar2 = (ulong *)(*(long *)(param_1 + 0x248) + (param_2 >> 6 & 0x3ffffff) * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar5) {
        *puVar2 = *puVar2 & (1L << (param_2 & 0x3f) ^ 0xffffffffffffffffU);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    plVar1 = (long *)(param_1 + 0xd8);
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar5) {
        *plVar1 = *plVar1 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if ((param_3 & 1) != 0) {
      plVar1 = (long *)(param_1 + 0x118);
      Hint_Prefetch(plVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
        if (bVar5) {
          *plVar1 = *plVar1 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
    }
    lVar7 = param_1 + 0x2b8;
    uVar6 = _raw_spin_lock_irqsave(lVar7);
    uVar9 = 0;
    do {
      if ((*(ulong *)(*(long *)(param_1 + 0x248) +
                     ((param_2 & 0xffffffffffffffc0) + uVar9 >> 3 & 0x1ffffffffffffff8)) >>
           (uVar9 & 0x3f) & 1) != 0) goto LAB_00105a68;
      uVar9 = uVar9 + 1;
    } while (uVar9 != 0x40);
    puVar2 = (ulong *)(*(long *)(param_1 + 0x288) + (param_2 >> 0xc & 0x3ffffff) * 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar5) {
        *puVar2 = *puVar2 & (1L << (param_2 >> 6 & 0x3f) ^ 0xffffffffffffffffU);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
LAB_00105a68:
  _raw_spin_unlock_irqrestore(lVar7,uVar6);
  return;
}



//------------------------------------------------------------
// handle_decomp_fail @ 00105b00 size=296
// signature: undefined handle_decomp_fail(void)
// callers: [zram_bvec_read, zram_handle_comp_page]
//------------------------------------------------------------

void handle_decomp_fail(undefined8 param_1,undefined4 param_2,undefined4 param_3,long param_4,
                       uint param_5,undefined8 *param_6)

{
  long lVar1;
  ulong uVar2;
  char *pcVar3;
  bool bVar4;
  code *pcVar5;
  ulong unaff_x30;
  
  uVar2 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar2 = unaff_x30 | 0xffffff8000000000;
  }
  pcVar3 = "index";
  if (param_6 != (undefined8 *)0x0) {
    pcVar3 = "offset";
  }
  _printk(&DAT_0010c5a2,uVar2,param_1,param_2,pcVar3,param_3,param_4,param_5);
  bVar4 = false;
  if ((param_5 != 0x1000) && (is_lzorle != '\0')) {
    lVar1 = param_4 + (ulong)param_5;
    if (*(short *)(lVar1 + -3) == lzo_marker && *(char *)(lVar1 + -1) == DAT_0010d83a) {
      bVar4 = false;
    }
    else {
      _printk(&DAT_0010d04d,"handle_decomp_fail");
      bVar4 = true;
    }
  }
  if (param_6 == (undefined8 *)0x0) {
    print_hex_dump(&DAT_0010c71e,"",2,0x10,1,param_4,(ulong)param_5,1);
  }
  else {
    print_hex_dump_pages(*param_6,*(undefined4 *)(param_6 + 1),*(undefined4 *)((long)param_6 + 0xc))
    ;
  }
  if (bVar4) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x105c28);
    (*pcVar5)();
  }
                    /* WARNING: Subroutine does not return */
  panic("zram decomp failed");
}



//------------------------------------------------------------
// free_zw_pages @ 00105c28 size=108
// signature: undefined free_zw_pages(void)
// callers: [read_comp_from_bdev]
//------------------------------------------------------------

void free_zw_pages(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (0 < *(int *)(param_1 + 0x260)) {
    lVar3 = 0;
    do {
      if (lVar3 == 0x40) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x105c94);
        (*pcVar1)();
      }
      lVar2 = *(long *)(param_1 + 0x30 + lVar3 * 8);
      if (lVar2 == 0) {
        return;
      }
      __free_pages(lVar2,0);
      lVar3 = lVar3 + 1;
    } while (lVar3 < *(int *)(param_1 + 0x260));
  }
  return;
}



//------------------------------------------------------------
// zram_comp_page_end_io @ 00105c98 size=136
// signature: undefined zram_comp_page_end_io(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zram_comp_page_end_io(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(**(long **)(param_1 + 0x78) + 0x28);
  iVar2 = blk_status_to_errno(*(undefined1 *)(param_1 + 0x18));
  if (iVar2 != 0) {
    _printk(&DAT_0010cd5d,"zram_comp_page_end_io",iVar2);
  }
  *puVar3 = 0xfffffffe0;
  puVar3[1] = puVar3 + 1;
  puVar3[2] = puVar3 + 1;
  uVar1 = _system_wq;
  puVar3[3] = zram_handle_comp_page;
  queue_work_on(0x20,uVar1,puVar3);
  return;
}



//------------------------------------------------------------
// zram_handle_comp_page @ 00105d24 size=2596
// signature: undefined zram_handle_comp_page(void)
// callers: []
//------------------------------------------------------------

void zram_handle_comp_page(long param_1)

{
  ulong *puVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  char cVar7;
  code *pcVar8;
  bool bVar9;
  int iVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  long lVar14;
  undefined8 *puVar15;
  uint uVar16;
  ulong uVar17;
  ulong *puVar18;
  ulong uVar19;
  long lVar20;
  ulong uVar21;
  long *plVar22;
  long lVar23;
  uint uVar24;
  undefined8 uVar25;
  long *plVar26;
  uint uVar27;
  ulong uVar28;
  uint *puVar29;
  ulong unaff_x30;
  long local_c8;
  long local_78;
  undefined4 local_70;
  uint uStack_6c;
  long local_68;
  
  lVar23 = sp_el0;
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar23 + 0x638);
  lVar23 = param_1 + 0x30;
  uVar19 = *(ulong *)(param_1 + 600);
  plVar26 = *(long **)(param_1 + 0x250);
  uVar4 = (uint)(uVar19 >> 0x18);
  uVar21 = *(ulong *)(param_1 + 0x230);
  bVar9 = *(char *)(param_1 + 0x264) != '\0';
  uVar25 = *(undefined8 *)(param_1 + 0x238);
  uVar3 = 0;
  if (bVar9) {
    uVar3 = uVar4 & 0x3f;
  }
  uVar28 = uVar19 >> 0xc & 0xfff;
  uVar17 = *(ulong *)(lVar23 + (ulong)uVar3 * 8);
  plVar22 = (long *)(lVar14 + 0x10);
  if (bVar9) {
    uVar4 = uVar4 & 0xffffffc0;
  }
  *(int *)plVar22 = *(int *)plVar22 + 1;
  *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + 1;
  uVar17 = (uVar17 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
  puVar29 = (uint *)(uVar17 + uVar28);
  uVar16 = 0x1000;
  if ((uVar19 & 0xfff) != 0) {
    uVar16 = (uint)uVar19 & 0xfff;
  }
  if (puVar29[1] != uVar16) {
    _printk(&DAT_0010cb48,"zram_handle_comp_page",plVar26 + 0x34,uVar16,puVar29[1],uVar17,uVar28);
    print_hex_dump_pages(lVar23,*(undefined4 *)(param_1 + 0x260),uVar3);
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x10679c);
    (*pcVar8)();
  }
  if (uVar21 == 0) {
    *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + -1;
    lVar11 = *(long *)(lVar14 + 0x10) + -1;
    *(int *)(lVar14 + 0x10) = (int)lVar11;
    if ((lVar11 == 0) || (*plVar22 == 0)) {
      preempt_schedule();
    }
    goto LAB_00106040;
  }
  uVar24 = *puVar29;
  *(int *)(lVar14 + 0x10) = *(int *)(lVar14 + 0x10) + 1;
  *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + 1;
  uVar17 = (uVar21 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
  lVar11 = zcomp_stream_get(plVar26[2]);
  uVar27 = (int)uVar28 + 8;
  if (uVar27 + uVar16 < 0x1001) {
    puVar29 = puVar29 + 2;
  }
  else {
    *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + -1;
    lVar20 = *(long *)(lVar14 + 0x10) + -1;
    *(int *)(lVar14 + 0x10) = (int)lVar20;
    if ((lVar20 == 0) || (*plVar22 == 0)) {
      preempt_schedule();
    }
    if ((uVar19 & 0xfff) == 0) {
      copy_to_buf(uVar17,lVar23,uVar3,uVar27,uVar16);
      zcomp_stream_put(plVar26[2]);
      goto LAB_00105efc;
    }
    puVar29 = *(uint **)(lVar11 + 0x10);
    copy_to_buf(puVar29,lVar23,uVar3,uVar27,uVar16);
  }
  iVar10 = zcomp_decompress(lVar11,puVar29,uVar16,uVar17);
  zcomp_stream_put(plVar26[2]);
  if (iVar10 != 0) {
    local_70 = *(undefined4 *)(param_1 + 0x260);
    local_78 = lVar23;
    uStack_6c = uVar3;
    handle_decomp_fail(plVar26 + 0x34,iVar10,uVar27,puVar29,uVar16,&local_78);
LAB_00106720:
    uVar19 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar19 = unaff_x30 | 0xffffff8000000000;
    }
    _printk(&DAT_0010c7ac,uVar19,local_c8,(ulong)puVar29 & 0xffffffff);
    print_hex_dump_pages(lVar23,uVar16,uVar27);
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x106760);
    (*pcVar8)();
  }
LAB_00105efc:
  *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + -1;
  lVar11 = *(long *)(lVar14 + 0x10) + -1;
  *(int *)(lVar14 + 0x10) = (int)lVar11;
  if ((lVar11 == 0) || (*plVar22 == 0)) {
    preempt_schedule();
  }
  if (uVar27 + uVar16 < 0x1001) {
    *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + -1;
    lVar11 = *(long *)(lVar14 + 0x10) + -1;
    *(int *)(lVar14 + 0x10) = (int)lVar11;
    if ((lVar11 == 0) || (*plVar22 == 0)) {
      preempt_schedule();
    }
  }
  puVar1 = (ulong *)(*plVar26 + (ulong)uVar24 * 0x28 + 8);
  *(int *)plVar22 = *(int *)plVar22 + 1;
  uVar16 = (uint)*puVar1;
  do {
    if ((uVar16 >> 0xd & 1) == 0) {
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar19 = *puVar1;
        cVar7 = '\x01';
        bVar9 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar9) {
          *puVar1 = uVar19 | 0x2000;
          cVar7 = ExclusiveMonitorsStatus();
        }
      } while (cVar7 != '\0');
      if (((uint)uVar19 >> 0xd & 1) == 0) break;
    }
    lVar11 = *plVar22;
    *(int *)plVar22 = (int)(lVar11 + -1);
    if ((lVar11 + -1 == 0) || (*plVar22 == 0)) {
      preempt_schedule();
    }
    do {
      Yield();
    } while (((uint)*puVar1 >> 0xd & 1) != 0);
    *(int *)plVar22 = *(int *)plVar22 + 1;
    uVar16 = (uint)*puVar1;
  } while( true );
  lVar20 = (ulong)uVar24 * 0x28;
  lVar11 = *plVar26 + lVar20;
  *(ulong *)(lVar11 + 8) = *(ulong *)(lVar11 + 8) & 0xffffffffffefffff;
  puVar1 = (ulong *)(*plVar26 + lVar20 + 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar7 = '\x01';
    bVar9 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar9) {
      *puVar1 = *puVar1 & 0xffffffffffffdfff;
      cVar7 = ExclusiveMonitorsStatus();
    }
  } while (cVar7 != '\0');
  lVar11 = *plVar22;
  *(int *)plVar22 = (int)(lVar11 + -1);
  if ((lVar11 + -1 == 0) || (*plVar22 == 0)) {
    preempt_schedule();
    lVar11 = *(long *)(param_1 + 0x240);
  }
  else {
    lVar11 = *(long *)(param_1 + 0x240);
  }
  if (lVar11 != 0) {
    bio_endio();
  }
LAB_00106040:
  bio_put(uVar25);
  uVar16 = *(uint *)(param_1 + 0x260);
  if (uVar16 != 0) {
    puVar1 = (ulong *)(plVar26 + 0x18);
    uVar24 = 0;
    uVar27 = 0;
    do {
      uVar19 = *(ulong *)(lVar23 + (ulong)uVar27 * 8);
      *(int *)(lVar14 + 0x10) = *(int *)(lVar14 + 0x10) + 1;
      *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + 1;
      puVar29 = (uint *)(((uVar19 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) + (ulong)uVar24);
      uVar5 = *puVar29;
      uVar19 = (ulong)uVar5;
      uVar6 = puVar29[1];
      puVar29 = (uint *)(ulong)uVar6;
      *(int *)(lVar14 + 0xb68) = *(int *)(lVar14 + 0xb68) + -1;
      lVar11 = *(long *)(lVar14 + 0x10) + -1;
      *(int *)(lVar14 + 0x10) = (int)lVar11;
      if ((lVar11 == 0) || (*plVar22 == 0)) {
        preempt_schedule();
      }
      if ((uVar19 < (ulong)plVar26[0x33] >> 0xc) && (uVar6 < 0x1001)) {
        lVar11 = *plVar26;
        *(int *)plVar22 = *(int *)plVar22 + 1;
        puVar18 = (ulong *)(lVar11 + uVar19 * 0x28 + 8);
        if (((uint)*puVar18 >> 0xd & 1) == 0) {
          Hint_Prefetch(puVar18,2,0,1);
          do {
            uVar17 = *puVar18;
            cVar7 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(puVar18,0x10);
            if (bVar9) {
              *puVar18 = uVar17 | 0x2000;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
          if (((uint)uVar17 >> 0xd & 1) != 0) goto LAB_001061ec;
          puVar18 = (ulong *)(*plVar26 + uVar19 * 0x28 + 8);
          if (((*puVar18 & 0xdfff) == 0) || ((*puVar18 & 0x108000) != 0x8000)) {
            Hint_Prefetch(puVar18,2,0,1);
            do {
              cVar7 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar18,0x10);
              if (bVar9) {
                *puVar18 = *puVar18 & 0xffffffffffffdfff;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            goto LAB_001061ec;
          }
          uVar17 = *(ulong *)(*plVar26 + uVar19 * 0x28);
          if (((((ulong)(uVar27 + uVar4) != uVar17 >> 0x18) ||
               ((uVar17 >> 0xc & 0xfff) != (ulong)uVar24)) ||
              ((uVar6 == 0x1000 && ((uint *)(uVar17 & 0xfff) != (uint *)0x0)))) ||
             ((uVar6 != 0x1000 && ((uint *)(uVar17 & 0xfff) != puVar29)))) {
            Hint_Prefetch(puVar18,2,0,1);
            do {
              cVar7 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar18,0x10);
              if (bVar9) {
                *puVar18 = *puVar18 & 0xffffffffffffdfff;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            goto LAB_001061ec;
          }
          plVar2 = plVar26 + 0x2a;
          Hint_Prefetch(plVar2,2,0,1);
          do {
            cVar7 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(plVar2,0x10);
            if (bVar9) {
              *plVar2 = *plVar2 + 1;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
          uVar17 = zs_malloc(plVar26[1],puVar29,0x800280a);
          if (0xfffffffffffff000 < uVar17) {
            bit_spin_unlock(*plVar26 + (ulong)uVar5 * 0x28 + 8);
            break;
          }
          uVar12 = zs_get_total_pages(plVar26[1]);
          uVar28 = plVar26[0x18];
          do {
            if (uVar12 <= uVar28) break;
            Hint_Prefetch(puVar1,2,0,1);
            do {
              uVar13 = *puVar1;
              if (uVar13 != uVar28) goto LAB_00106288;
              cVar7 = '\x01';
              bVar9 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar9) {
                *puVar1 = uVar12;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            DataMemoryBarrier(2,3);
LAB_00106288:
            bVar9 = uVar13 != uVar28;
            uVar28 = uVar13;
          } while (bVar9);
          local_c8 = zs_map_object(plVar26[1],uVar17,2);
          copy_to_buf(local_c8,lVar23,uVar27,uVar24 + 8,uVar6);
          if (((uVar6 != 0x1000) && (is_lzorle != '\0')) &&
             (*(short *)(local_c8 + (int)uVar6 + -3) != lzo_marker ||
              *(char *)(local_c8 + (int)uVar6 + -1) != DAT_0010d83a)) goto LAB_00106720;
          zs_unmap_object(plVar26[1],uVar17);
          plVar2 = plVar26 + 0xd;
          Hint_Prefetch(plVar2,2,0,1);
          do {
            cVar7 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(plVar2,0x10);
            if (bVar9) {
              *plVar2 = *plVar2 + (long)puVar29;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
          zram_free_page(plVar26,uVar19);
          lVar20 = uVar19 * 0x28;
          *(ulong *)(*plVar26 + lVar20) = uVar17;
          *(ulong *)(*plVar26 + lVar20 + 8) =
               *(ulong *)(*plVar26 + lVar20 + 8) & 0xffffffffffffe000 | (ulong)puVar29;
          uVar25 = _raw_spin_lock_irqsave(plVar26 + 0x56);
          lVar11 = *plVar26;
          puVar15 = (undefined8 *)plVar26[0x55];
          plVar2 = (long *)(lVar11 + lVar20 + 0x18);
          uVar19 = __list_add_valid(plVar2,puVar15,plVar26 + 0x54);
          if ((uVar19 & 1) != 0) {
            plVar26[0x55] = (long)plVar2;
            *plVar2 = (long)(plVar26 + 0x54);
            *(undefined8 **)(lVar11 + (ulong)uVar5 * 0x28 + 0x20) = puVar15;
            *puVar15 = plVar2;
          }
          _raw_spin_unlock_irqrestore(plVar26 + 0x56,uVar25);
          lVar11 = *plVar26 + (ulong)uVar5 * 0x28;
          *(ulong *)(lVar11 + 8) = *(ulong *)(lVar11 + 8) | 0x800000;
          plVar2 = plVar26 + 0x2c;
          Hint_Prefetch(plVar2,2,0,1);
          do {
            cVar7 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(plVar2,0x10);
            if (bVar9) {
              *plVar2 = *plVar2 + 1;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
          puVar18 = (ulong *)(*plVar26 + (ulong)uVar5 * 0x28 + 8);
          Hint_Prefetch(puVar18,2,0,1);
          do {
            cVar7 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(puVar18,0x10);
            if (bVar9) {
              *puVar18 = *puVar18 & 0xffffffffffffdfff;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
          lVar11 = *plVar22;
          *(int *)plVar22 = (int)(lVar11 + -1);
          if ((lVar11 + -1 == 0) || (*plVar22 == 0)) {
            preempt_schedule();
          }
          plVar2 = plVar26 + 0x17;
          Hint_Prefetch(plVar2,2,0,1);
          do {
            cVar7 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(plVar2,0x10);
            if (bVar9) {
              *plVar2 = *plVar2 + 1;
              cVar7 = ExclusiveMonitorsStatus();
            }
          } while (cVar7 != '\0');
        }
        else {
LAB_001061ec:
          lVar11 = *plVar22;
          *(int *)plVar22 = (int)(lVar11 + -1);
          if ((lVar11 + -1 == 0) || (*plVar22 == 0)) {
            preempt_schedule();
          }
        }
        iVar10 = uVar24 + uVar6;
        bVar9 = uVar5 == 0xffffffea;
        uVar24 = iVar10 + 8;
        if ((iVar10 - 0xff1U < 0xffffefff) || (uVar5 == 0xffffffea)) goto LAB_001060a4;
      }
      else {
        uVar24 = uVar24 + uVar6 + 8;
        bVar9 = true;
LAB_001060a4:
        iVar10 = 1;
        if (uVar24 < 0x1000) {
          bVar9 = true;
        }
        uVar5 = 0;
        if (!bVar9) {
          uVar5 = uVar24 & 0xfff;
        }
        if (0xff8 < uVar5) {
          iVar10 = 2;
        }
        uVar24 = 0;
        if (uVar5 < 0xff9) {
          uVar24 = uVar5;
        }
        uVar27 = iVar10 + uVar27;
      }
    } while (uVar27 < uVar16);
  }
  if (uVar21 == 0) {
    puVar1 = (ulong *)(plVar26[0x5f] + (ulong)(uVar4 >> 0xc) * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar7 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar9) {
        *puVar1 = *puVar1 & (1L << ((ulong)(uVar4 >> 6) & 0x3f) ^ 0xffffffffffffffffU);
        cVar7 = ExclusiveMonitorsStatus();
      }
    } while (cVar7 != '\0');
  }
  zram_dec_wb_table(plVar26,uVar4 + uVar3,*(undefined1 *)(param_1 + 0x264));
  if (0 < *(int *)(param_1 + 0x260)) {
    lVar23 = 0;
    do {
      if (lVar23 == 0x40) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x1066ec);
        (*pcVar8)();
      }
      lVar14 = *(long *)(param_1 + 0x30 + lVar23 * 8);
      if (lVar14 == 0) break;
      __free_pages(lVar14,0);
      lVar23 = lVar23 + 1;
    } while (lVar23 < *(int *)(param_1 + 0x260));
  }
  kfree(param_1);
  lVar23 = sp_el0;
  if (*(long *)(lVar23 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// print_hex_dump_pages @ 001067d4 size=472
// signature: undefined print_hex_dump_pages(void)
// callers: [zram_handle_comp_page, handle_decomp_fail]
//------------------------------------------------------------

void print_hex_dump_pages(long param_1,int param_2,uint param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_3 < 0x40) {
    if ((param_2 == 0x40) && (param_3 != 0)) {
      _printk(&DAT_0010c64a);
      lVar2 = sp_el0;
      uVar4 = *(ulong *)(param_1 + (ulong)(param_3 - 1) * 8);
      *(int *)(lVar2 + 0x10) = *(int *)(lVar2 + 0x10) + 1;
      *(int *)(lVar2 + 0xb68) = *(int *)(lVar2 + 0xb68) + 1;
      print_hex_dump(&DAT_0010c71e,"",2,0x10,1,(uVar4 & 0x3ffffffffffc0) << 6 | 0xff00000000000000,
                     0x1000,1);
      *(int *)(lVar2 + 0xb68) = *(int *)(lVar2 + 0xb68) + -1;
      lVar1 = *(long *)(lVar2 + 0x10) + -1;
      *(int *)(lVar2 + 0x10) = (int)lVar1;
      if ((lVar1 == 0) || (*(long *)(lVar2 + 0x10) == 0)) {
        preempt_schedule();
      }
    }
    _printk(&DAT_0010c661);
    uVar4 = *(ulong *)(param_1 + (ulong)param_3 * 8);
    lVar2 = sp_el0;
    *(int *)(lVar2 + 0x10) = *(int *)(lVar2 + 0x10) + 1;
    *(int *)(lVar2 + 0xb68) = *(int *)(lVar2 + 0xb68) + 1;
    print_hex_dump(&DAT_0010c71e,"",2,0x10,1,(uVar4 & 0x3ffffffffffc0) << 6 | 0xff00000000000000,
                   0x1000,1);
    *(int *)(lVar2 + 0xb68) = *(int *)(lVar2 + 0xb68) + -1;
    lVar1 = *(long *)(lVar2 + 0x10) + -1;
    *(int *)(lVar2 + 0x10) = (int)lVar1;
    if ((lVar1 == 0) || (*(long *)(lVar2 + 0x10) == 0)) {
      preempt_schedule();
    }
    if ((param_2 == 0x40) && (param_3 != 0x3f)) {
      _printk(&DAT_0010cd7d);
      uVar3 = kmap_atomic(*(undefined8 *)(param_1 + (ulong)(param_3 + 1) * 8));
      print_hex_dump(&DAT_0010c71e,"",2,0x10,1,uVar3,0x1000,1);
      __kunmap_atomic();
    }
  }
  return;
}



//------------------------------------------------------------
// copy_to_buf @ 001069bc size=340
// signature: undefined copy_to_buf(void)
// callers: [zram_handle_comp_page]
//------------------------------------------------------------

void copy_to_buf(void *param_1,long param_2,uint param_3,uint param_4,int param_5)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  iVar2 = 0x1000 - param_4;
  iVar1 = iVar2;
  if (param_5 <= iVar2) {
    iVar1 = param_5;
  }
  if (iVar1 != 0) {
    uVar5 = *(ulong *)(param_2 + (ulong)param_3 * 8);
    lVar4 = sp_el0;
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    *(int *)(lVar4 + 0xb68) = *(int *)(lVar4 + 0xb68) + 1;
    memcpy(param_1,(void *)(((uVar5 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) + (ulong)param_4),
           (long)iVar1);
    *(int *)(lVar4 + 0xb68) = *(int *)(lVar4 + 0xb68) + -1;
    lVar3 = *(long *)(lVar4 + 0x10) + -1;
    *(int *)(lVar4 + 0x10) = (int)lVar3;
    if ((lVar3 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
      preempt_schedule();
    }
  }
  if (iVar2 < param_5) {
    lVar4 = sp_el0;
    uVar5 = *(ulong *)(param_2 + (ulong)(param_3 + 1) * 8);
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    *(int *)(lVar4 + 0xb68) = *(int *)(lVar4 + 0xb68) + 1;
    memcpy((void *)((long)param_1 + (long)iVar1),
           (void *)((uVar5 & 0x3ffffffffffc0) << 6 | 0xff00000000000000),(long)(param_5 - iVar1));
    *(int *)(lVar4 + 0xb68) = *(int *)(lVar4 + 0xb68) + -1;
    lVar3 = *(long *)(lVar4 + 0x10) + -1;
    *(int *)(lVar4 + 0x10) = (int)lVar3;
    if ((lVar3 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
      preempt_schedule();
    }
  }
  return;
}



//------------------------------------------------------------
// disksize_show @ 00106b24 size=64
// signature: undefined disksize_show(void)
// callers: []
//------------------------------------------------------------

long disksize_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%llu\n",
                    *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x3b0) + 0x58) + 0x198));
  return (long)iVar1;
}



//------------------------------------------------------------
// disksize_store @ 00106b68 size=400
// signature: undefined disksize_store(void)
// callers: []
//------------------------------------------------------------

long disksize_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long *__s1;
  int iVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  ulong uVar6;
  ulong uVar7;
  
  plVar5 = *(long **)(*(long *)(param_1 + 0x3b0) + 0x58);
  lVar2 = memparse(param_3,0);
  if (lVar2 == 0) {
    param_4 = -0x16;
  }
  else {
    down_write(plVar5 + 4);
    if (plVar5[0x33] == 0) {
      uVar7 = lVar2 + 0xfffU >> 0xc;
      lVar3 = vzalloc(uVar7 * 0x28);
      *plVar5 = lVar3;
      if (lVar3 == 0) {
        param_4 = -0xc;
      }
      else {
        uVar6 = lVar2 + 0xfffU & 0xfffffffffffff000;
        if (uVar6 != 0) {
          uVar4 = 0;
          do {
            lVar2 = *plVar5 + uVar4 * 0x28;
            uVar4 = (ulong)((int)uVar4 + 1);
            *(long *)(lVar2 + 0x18) = lVar2 + 0x18;
            *(long *)(lVar2 + 0x20) = lVar2 + 0x18;
          } while (uVar4 < uVar7);
        }
        lVar2 = zs_create_pool(plVar5[3] + 0xc);
        plVar5[1] = lVar2;
        if (lVar2 == 0) {
          vfree(*plVar5);
          param_4 = -0xc;
        }
        else {
          if (huge_class_size == 0) {
            huge_class_size = zs_huge_class_size();
          }
          __s1 = plVar5 + 0x34;
          uVar7 = zcomp_create(__s1);
          if (uVar7 < 0xfffffffffffff001) {
            iVar1 = strncmp((char *)__s1,"lzo-rle",7);
            if (iVar1 == 0) {
              is_lzorle = 1;
            }
            plVar5[2] = uVar7;
            plVar5[0x33] = uVar6;
            set_capacity_and_notify(plVar5[3],uVar6 >> 9);
          }
          else {
            _printk(&DAT_0010c4a9,__s1);
            zram_meta_free(plVar5,uVar6);
            param_4 = (long)(int)uVar7;
          }
        }
      }
    }
    else {
      _printk(&DAT_0010cab3);
      param_4 = -0x10;
    }
    up_write(plVar5 + 4);
  }
  return param_4;
}



//------------------------------------------------------------
// initstate_show @ 00106cfc size=104
// signature: undefined initstate_show(void)
// callers: []
//------------------------------------------------------------

long initstate_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  lVar1 = lVar4 + 0x20;
  down_read(lVar1);
  uVar2 = *(undefined4 *)(lVar4 + 0x198);
  up_read(lVar1);
  iVar3 = scnprintf(param_3,0x1000,&DAT_0010c6eb,uVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// reset_store @ 00106d68 size=292
// signature: undefined reset_store(void)
// callers: []
//------------------------------------------------------------

long reset_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  short local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  iVar2 = kstrtou16(param_3,10,local_3c);
  if (iVar2 == 0) {
    if (local_3c[0] == 0) {
      param_4 = -0x16;
    }
    else {
      lVar3 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
      lVar4 = *(long *)(lVar3 + 0x18);
      lVar1 = lVar4 + 0x178;
      mutex_lock(lVar1);
      if ((*(int *)(*(long *)(lVar4 + 0x40) + 0x28) == 0) && (*(char *)(lVar3 + 0x220) == '\0')) {
        *(undefined1 *)(lVar3 + 0x220) = 1;
        mutex_unlock(lVar1);
        if ((*(ulong *)(lVar3 + 0x260) != 0) && (*(ulong *)(lVar3 + 0x260) < 0xfffffffffffff001)) {
          g_zram = 0;
          kthread_stop();
          *(undefined8 *)(lVar3 + 0x260) = 0;
        }
        sync_blockdev(*(undefined8 *)(lVar4 + 0x40));
        zram_reset_device(lVar3);
        mutex_lock(lVar1);
        *(undefined1 *)(lVar3 + 0x220) = 0;
        mutex_unlock(lVar1);
      }
      else {
        mutex_unlock(lVar1);
        param_4 = -0x10;
      }
    }
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// compact_store @ 00106e90 size=100
// signature: undefined compact_store(void)
// callers: []
//------------------------------------------------------------

undefined8 compact_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar1 + 0x20);
  if (*(long *)(lVar1 + 0x198) == 0) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    zs_compact(*(undefined8 *)(lVar1 + 8));
  }
  up_read(lVar1 + 0x20);
  return param_4;
}



//------------------------------------------------------------
// mem_limit_store @ 00106ef8 size=176
// signature: undefined mem_limit_store(void)
// callers: []
//------------------------------------------------------------

undefined8 mem_limit_store(long param_1,undefined8 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  lVar2 = memparse(param_3,&local_40);
  if (local_40 == param_3) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    lVar1 = lVar3 + 0x20;
    down_write(lVar1);
    *(ulong *)(lVar3 + 0x60) = lVar2 + 0xfffU >> 0xc;
    up_write(lVar1);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mem_used_max_store @ 00106fac size=184
// signature: undefined mem_used_max_store(void)
// callers: []
//------------------------------------------------------------

void mem_used_max_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  iVar1 = kstrtoull(param_3,10,&local_40);
  uVar2 = 0xffffffffffffffea;
  if ((iVar1 == 0) && (local_40 == 0)) {
    down_read(lVar3 + 0x20);
    if (*(long *)(lVar3 + 0x198) != 0) {
      uVar2 = zs_get_total_pages(*(undefined8 *)(lVar3 + 8));
      *(undefined8 *)(lVar3 + 0xc0) = uVar2;
    }
    up_read(lVar3 + 0x20);
    uVar2 = param_4;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// idle_store @ 00107068 size=564
// signature: undefined idle_store(void)
// callers: []
//------------------------------------------------------------

undefined8 idle_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  uint uVar7;
  ulong uVar8;
  ulong *puVar9;
  long *plVar10;
  long lVar11;
  ulong uVar12;
  long local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  plVar10 = *(long **)(*(long *)(param_1 + 0x3b0) + 0x58);
  uVar5 = sysfs_streq(param_3,&DAT_0010cdfe);
  if ((uVar5 & 1) == 0) {
    local_70 = 0;
    iVar4 = kstrtoull(param_3,0,&local_70);
    if (iVar4 != 0) {
      param_4 = 0xffffffffffffffea;
      goto LAB_00107268;
    }
    lVar11 = ktime_get_with_offset(1);
    lVar11 = lVar11 + local_70 * -1000000000;
  }
  else {
    lVar11 = 0;
  }
  down_read(plVar10 + 4);
  uVar5 = plVar10[0x33];
  if (uVar5 == 0) {
    param_4 = 0xffffffffffffffea;
  }
  else if (0xfff < uVar5) {
    uVar12 = 0;
    lVar3 = sp_el0;
LAB_0010712c:
    puVar9 = (ulong *)(*plVar10 + uVar12 * 0x28 + 8);
    *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
    uVar7 = (uint)*puVar9;
    do {
      if ((uVar7 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar9,2,0,1);
        do {
          uVar8 = *puVar9;
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(puVar9,0x10);
          if (bVar2) {
            *puVar9 = uVar8 | 0x2000;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        if (((uint)uVar8 >> 0xd & 1) == 0) goto LAB_001071bc;
      }
      lVar6 = *(long *)(lVar3 + 0x10) + -1;
      *(int *)(lVar3 + 0x10) = (int)lVar6;
      if ((lVar6 == 0) || (*(long *)(lVar3 + 0x10) == 0)) {
        preempt_schedule();
      }
      do {
        Yield();
      } while (((uint)*puVar9 >> 0xd & 1) != 0);
      *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
      uVar7 = (uint)*puVar9;
    } while( true );
  }
LAB_00107260:
  up_read(plVar10 + 4);
LAB_00107268:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
LAB_001071bc:
  lVar6 = *plVar10;
  if ((*(ushort *)(lVar6 + (uVar12 & 0xffffffff) * 0x28 + 8) & 0xdfff) != 0) {
    puVar9 = (ulong *)(lVar6 + uVar12 * 0x28 + 8);
    uVar8 = *puVar9;
    if ((((uint)uVar8 >> 0x10 & 1) == 0) &&
       ((lVar11 == 0 || (*(long *)(lVar6 + uVar12 * 0x28 + 0x10) < lVar11)))) {
      *puVar9 = uVar8 | 0x40000;
      lVar6 = *plVar10;
    }
  }
  puVar9 = (ulong *)(lVar6 + uVar12 * 0x28 + 8);
  Hint_Prefetch(puVar9,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(puVar9,0x10);
    if (bVar2) {
      *puVar9 = *puVar9 & 0xffffffffffffdfff;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  lVar6 = *(long *)(lVar3 + 0x10) + -1;
  *(int *)(lVar3 + 0x10) = (int)lVar6;
  if ((lVar6 == 0) || (*(long *)(lVar3 + 0x10) == 0)) {
    preempt_schedule();
  }
  uVar12 = (ulong)((int)uVar12 + 1);
  if (uVar5 >> 0xc <= uVar12) goto LAB_00107260;
  goto LAB_0010712c;
}



//------------------------------------------------------------
// max_comp_streams_show @ 001072ac size=56
// signature: undefined max_comp_streams_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long max_comp_streams_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010c82e,___num_online_cpus);
  return (long)iVar1;
}



//------------------------------------------------------------
// max_comp_streams_store @ 001072e8 size=8
// signature: undefined max_comp_streams_store(void)
// callers: []
//------------------------------------------------------------

undefined8 max_comp_streams_store(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



//------------------------------------------------------------
// comp_algorithm_show @ 001072f4 size=92
// signature: undefined comp_algorithm_show(void)
// callers: []
//------------------------------------------------------------

undefined8 comp_algorithm_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  lVar1 = lVar3 + 0x20;
  down_read(lVar1);
  uVar2 = zcomp_available_show(lVar3 + 0x1a0,param_3);
  up_read(lVar1);
  return uVar2;
}



//------------------------------------------------------------
// comp_algorithm_store @ 00107354 size=424
// signature: undefined comp_algorithm_store(void)
// callers: []
//------------------------------------------------------------

undefined8 comp_algorithm_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  char cStack_b9;
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
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  lVar5 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  uVar3 = strnlen(param_3,0x80);
  if (uVar3 == 0xffffffffffffffff) {
LAB_001074d0:
    fortify_panic("strnlen");
LAB_001074dc:
    fortify_panic("strscpy");
  }
  else {
    if (uVar3 != 0x80) {
      uVar3 = uVar3 + 1;
    }
    if (0x80 < uVar3) goto LAB_001074dc;
    strscpy(&local_b8,param_3);
    sVar4 = strnlen((char *)&local_b8,0x80);
    if (0x80 < sVar4) goto LAB_001074d0;
    if (sVar4 == 0) {
LAB_00107424:
      uVar3 = zcomp_available_algorithm(&local_b8);
      if ((uVar3 & 1) == 0) {
        param_4 = 0xffffffffffffffea;
      }
      else {
        lVar1 = lVar5 + 0x20;
        down_write(lVar1);
        if (*(long *)(lVar5 + 0x198) == 0) {
          sVar4 = strnlen((char *)&local_b8,0x80);
          if (0x80 < sVar4) goto LAB_001074d0;
          if (sVar4 == 0x80) goto LAB_001074e8;
          memcpy((void *)(lVar5 + 0x1a0),&local_b8,sVar4 + 1);
          up_write(lVar1);
        }
        else {
          up_write(lVar1);
          _printk(&DAT_0010ce02);
          param_4 = 0xfffffffffffffff0;
        }
      }
      lVar5 = sp_el0;
      if (*(long *)(lVar5 + 0x638) == local_38) {
        return param_4;
      }
      goto LAB_001074f4;
    }
    if (sVar4 != 0x80) {
      if (sVar4 - 0x81 < 0xffffffffffffff80) {
LAB_001074f8:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1074fc);
        (*pcVar2)();
      }
      if ((&cStack_b9)[sVar4] == '\n') {
        if (sVar4 - 0x81 < 0xffffffffffffff80) goto LAB_001074f8;
        (&cStack_b9)[sVar4] = '\0';
      }
      goto LAB_00107424;
    }
  }
LAB_001074e8:
  fortify_panic("__fortify_strlen");
LAB_001074f4:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// backing_dev_show @ 00107500 size=176
// signature: undefined backing_dev_show(void)
// callers: []
//------------------------------------------------------------

char * backing_dev_show(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  char *__s;
  size_t __n;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  lVar1 = lVar2 + 0x20;
  down_read(lVar1);
  lVar2 = *(long *)(lVar2 + 0x228);
  if (lVar2 == 0) {
    __s = (char *)0x5;
    *(undefined1 *)(param_3 + 1) = 10;
    *param_3 = 0x656e6f6e;
  }
  else {
    __s = (char *)file_path(lVar2,param_3,0xfff);
    if (__s < (char *)0xfffffffffffff001) {
      __n = strlen(__s);
      memmove(param_3,__s,__n);
      __s = (char *)(__n + 1);
      *(undefined1 *)((long)param_3 + __n) = 10;
    }
  }
  up_read(lVar1);
  return __s;
}



//------------------------------------------------------------
// backing_dev_store @ 001075b4 size=1072
// signature: undefined backing_dev_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long backing_dev_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  char *__string;
  ulong uVar3;
  size_t sVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ushort *puVar11;
  __pid_t __pid;
  sched_param local_60 [2];
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  __string = (char *)kmalloc_trace(_blk_queue_io_min,0xcc0,0x1000);
  if (__string == (char *)0x0) {
    param_4 = -0xc;
  }
  else {
    lVar1 = lVar10 + 0x20;
    down_write(lVar1);
    if (*(long *)(lVar10 + 0x198) != 0) {
      _printk(&DAT_0010d0d9);
      uVar3 = 0;
      __pid = -0x10;
      goto LAB_00107714;
    }
    uVar3 = strnlen(param_3,0x1000);
    if (uVar3 == 0xffffffffffffffff) {
LAB_001079b8:
      fortify_panic("strnlen");
      goto LAB_001079c4;
    }
    if (uVar3 != 0x1000) {
      uVar3 = uVar3 + 1;
    }
    if (0x1000 < uVar3) {
      fortify_panic("strscpy");
      goto LAB_001079d4;
    }
    strscpy(__string,param_3);
    sVar4 = strnlen(__string,0x1000);
    if (0x1000 < sVar4) goto LAB_001079b8;
    if (sVar4 != 0) {
      if (sVar4 == 0x1000) {
        fortify_panic("__fortify_strlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if (sVar4 - 0x1001 < 0xfffffffffffff000) {
LAB_001079d4:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1079d8);
        (*pcVar2)();
      }
      if (__string[sVar4 - 1] == '\n') {
        if (sVar4 - 0x1001 < 0xfffffffffffff000) goto LAB_001079d4;
        __string[sVar4 - 1] = '\0';
      }
    }
    uVar3 = filp_open_block(__string,0x20002,0);
    if (uVar3 < 0xfffffffffffff001) {
      puVar11 = (ushort *)**(undefined8 **)(uVar3 + 0xe8);
      if ((*puVar11 & 0xf000) != 0x6000) {
        __pid = -0xf;
        goto LAB_00107714;
      }
      uVar5 = blkdev_get_by_dev(*(undefined4 *)(puVar11 + 0x26),0x83,lVar10);
      if (0xfffffffffffff000 < uVar5) {
        __pid = (__pid_t)uVar5;
        goto LAB_00107714;
      }
      lVar9 = *(long *)(puVar11 + 0x28);
      lVar6 = kvmalloc_node((lVar9 >> 0xc) + 0x3fU >> 3 & 0xfffffff8,0xdc0,0xffffffff);
      if (lVar6 == 0) {
        __pid = -0xc;
      }
      else {
        reset_bdev(lVar10);
        *(ulong *)(lVar10 + 0x240) = uVar5;
        *(ulong *)(lVar10 + 0x228) = uVar3;
        *(long *)(lVar10 + 0x248) = lVar6;
        *(long *)(lVar10 + 0x250) = lVar9 >> 0xc;
        local_60[0].__sched_priority = 0;
        __init_waitqueue_head(lVar10 + 0x268,"&zram->wbd_wait",&init_lru_writeback___key);
        lVar9 = kvmalloc_node(*(long *)(lVar10 + 0x250) << 1,0xdc0,0xffffffff);
        *(long *)(lVar10 + 0x280) = lVar9;
        if (lVar9 != 0) {
          lVar9 = kvmalloc_node(*(long *)(lVar10 + 0x250) * 0x100000 + 0x3f00000 >> 0x20,0xdc0,
                                0xffffffff);
          *(long *)(lVar10 + 0x2c0) = lVar9;
          if (lVar9 == 0) goto LAB_001078b0;
          uVar8 = *(long *)(lVar10 + 0x250) + 0x3f;
          if ((uVar8 & 0x1fffffffe00) == 0) {
            __pid = -0x16;
            goto LAB_00107934;
          }
          lVar9 = (long)(uVar8 * 0x800000) >> 0x20;
          lVar7 = kvmalloc_node(lVar9,0xdc0,0xffffffff);
          *(long *)(lVar10 + 0x288) = lVar7;
          if (lVar7 == 0) {
LAB_001078b0:
            __pid = -0xc;
LAB_001078b4:
            if (*(long *)(lVar10 + 0x2f8) != 0) {
              kvfree();
              *(undefined8 *)(lVar10 + 0x2f8) = 0;
            }
            if (*(long *)(lVar10 + 0x288) != 0) {
              kvfree();
              *(undefined8 *)(lVar10 + 0x288) = 0;
            }
            if (*(long *)(lVar10 + 0x2c0) != 0) {
              kvfree();
              *(undefined8 *)(lVar10 + 0x2c0) = 0;
            }
            kvfree(*(undefined8 *)(lVar10 + 0x280));
            *(undefined8 *)(lVar10 + 0x280) = 0;
            if (__pid != 0) goto LAB_00107934;
          }
          else {
            lVar9 = kvmalloc_node(lVar9,0xdc0,0xffffffff);
            *(long *)(lVar10 + 0x2f8) = lVar9;
            if (lVar9 == 0) goto LAB_001078b0;
            uVar8 = kthread_create_on_node
                              (zram_wbd,lVar10,0xffffffff,"%s_wbd",*(long *)(lVar10 + 0x18) + 0xc);
            __pid = (__pid_t)uVar8;
            if (0xfffffffffffff000 < uVar8) {
              *(ulong *)(lVar10 + 0x260) = uVar8;
              goto LAB_001078b4;
            }
            wake_up_process();
            *(ulong *)(lVar10 + 0x260) = uVar8;
            g_zram = lVar10;
            *(undefined1 *)(lVar10 + 0x234) = 1;
            *(undefined8 *)(lVar10 + 0x238) = 0x280000;
            sched_setscheduler(__pid,5,local_60);
            *(ulong *)(lVar10 + 0x290) =
                 (ulong)(*(long *)(lVar10 + 0x250) * 3) / 10 & 0x1fffffffffffffc0;
          }
          up_write(lVar1);
          zram_oem_fn = zram_writeback_oem_func;
          _printk(&DAT_0010cb94,__string);
          kfree(__string);
          goto LAB_00107740;
        }
        __pid = -0xc;
LAB_00107934:
        *(undefined8 *)(lVar10 + 0x228) = 0;
        *(undefined8 *)(lVar10 + 0x240) = 0;
        *(undefined8 *)(lVar10 + 0x248) = 0;
        *(undefined8 *)(lVar10 + 0x250) = 0;
      }
      kvfree(lVar6);
      if (uVar5 != 0) {
        blkdev_put(uVar5,0x83);
      }
    }
    else {
      __pid = (__pid_t)uVar3;
      uVar3 = 0;
LAB_00107714:
      kvfree(0);
    }
    if (uVar3 != 0) {
      filp_close(uVar3,0);
    }
    up_write(lVar1);
    kfree(__string);
    param_4 = (long)__pid;
  }
LAB_00107740:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) == local_58) {
    return param_4;
  }
LAB_001079c4:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// zram_writeback_oem_func @ 001079e8 size=3028
// signature: undefined zram_writeback_oem_func(void)
// callers: []
//------------------------------------------------------------

ulong zram_writeback_oem_func(undefined4 param_1,long *param_2,ulong param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  undefined *puVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong *puVar10;
  long *plVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong *puVar15;
  ulong uVar16;
  long lVar17;
  long *plVar18;
  long lVar19;
  
  puVar2 = g_zram;
  switch(param_1) {
  case 0:
    is_app_launch = param_3 != 0;
    return 0;
  case 1:
    goto switchD_00107a34_caseD_1;
  case 2:
    plVar18 = (long *)*param_2;
    if (plVar18 == param_2) {
      return 0;
    }
    puVar15 = g_zram + 0x60;
    puVar1 = g_zram + 0x56;
    lVar12 = sp_el0;
LAB_00107b64:
    if (plVar18 + -3 < (long *)*puVar2) {
      uVar14 = puVar2[0x33] >> 0xc;
      uVar13 = uVar14;
    }
    else {
      uVar13 = (ulong)((long)(plVar18 + -3) - (long)*puVar2) / 0x28;
      uVar14 = puVar2[0x33] >> 0xc;
    }
    uVar16 = uVar13 & 0xffffffff;
    if (uVar16 < uVar14) {
      if (((is_app_launch == '\0') && (uVar14 = zram_wb_available(puVar2), (uVar14 & 1) != 0)) &&
         (*(int *)((long)puVar2 + 0x33c) == 0)) {
        iVar6 = zram_writeback_index(puVar2,uVar13 & 0xffffffff,puVar15,1);
        if (iVar6 != 0) {
          _printk(&DAT_0010c7ea,"zram_writeback_list",uVar13 & 0xffffffff,iVar6);
          return (long)iVar6;
        }
        puVar10 = (ulong *)(*puVar2 + uVar16 * 0x28 + 8);
        *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
        uVar9 = (uint)*puVar10;
        do {
          if ((uVar9 >> 0xd & 1) == 0) {
            Hint_Prefetch(puVar10,2,0,1);
            do {
              uVar13 = *puVar10;
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
              if (bVar4) {
                *puVar10 = uVar13 | 0x2000;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            if (((uint)uVar13 >> 0xd & 1) == 0) goto LAB_00107c68;
          }
          lVar17 = *(long *)(lVar12 + 0x10) + -1;
          *(int *)(lVar12 + 0x10) = (int)lVar17;
          if ((lVar17 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
            preempt_schedule();
          }
          do {
            Yield();
          } while (((uint)*puVar10 >> 0xd & 1) != 0);
          *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
          uVar9 = (uint)*puVar10;
        } while( true );
      }
      puVar7 = &DAT_0010ceed;
    }
    else {
      puVar7 = &DAT_0010d01f;
    }
    _printk(puVar7,"zram_writeback_list",uVar13 & 0xffffffff);
    return 0xffffffffffffffea;
  case 3:
    if (((long *)*param_2 == param_2) && (uVar13 = g_zram[0x60], uVar13 != 0)) {
      if (0x3f < *(uint *)(uVar13 + 0x200)) {
LAB_0010844c:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x108450);
        (*pcVar5)();
      }
      lVar12 = *(long *)(uVar13 + (ulong)*(uint *)(uVar13 + 0x200) * 8);
      lVar17 = (long)*(int *)(lVar12 + 0x20c);
      if (lVar17 + 8U < 0x1000) {
        uVar13 = *(ulong *)(lVar12 + 0x200);
        lVar19 = sp_el0;
        *(int *)(lVar19 + 0x10) = *(int *)(lVar19 + 0x10) + 1;
        *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + 1;
        *(undefined8 *)(((uVar13 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) + lVar17) =
             0xffffffff;
        *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + -1;
        lVar12 = *(long *)(lVar19 + 0x10) + -1;
        *(int *)(lVar19 + 0x10) = (int)lVar12;
        if ((lVar12 == 0) || (*(long *)(lVar19 + 0x10) == 0)) {
          preempt_schedule();
        }
      }
      zram_writeback_page(puVar2,puVar2[0x60],1);
    }
    else {
      plVar18 = (long *)*param_2;
      while (plVar18 != param_2) {
        if (plVar18 + -3 < *puVar2) {
          uVar14 = puVar2[0x33] >> 0xc;
          uVar13 = uVar14;
        }
        else {
          uVar14 = ((long)(plVar18 + -3) - *puVar2) / 0x28;
          uVar13 = puVar2[0x33] >> 0xc;
        }
        if (uVar13 <= (uVar14 & 0xffffffff)) break;
        zram_writeback_clear_flag(puVar2);
        plVar18 = (long *)*param_2;
      }
      uVar13 = puVar2[0x60];
      if (uVar13 == 0) {
        return 0;
      }
      lVar12 = 0;
      do {
        lVar17 = *(long *)(uVar13 + lVar12 * 8);
        if (*(int *)(lVar17 + 0x208) != 0) {
          lVar19 = 0;
          uVar14 = 0;
          do {
            if (uVar14 == 0x20) goto LAB_0010844c;
            zram_writeback_clear_flag(puVar2,*(undefined4 *)(lVar17 + lVar19));
            lVar17 = *(long *)(uVar13 + lVar12 * 8);
            uVar14 = uVar14 + 1;
            lVar19 = lVar19 + 0x10;
          } while (uVar14 < *(uint *)(lVar17 + 0x208));
        }
        lVar12 = lVar12 + 1;
      } while (lVar12 != 0x40);
      uVar13 = puVar2[0x60];
      if (uVar13 != 0) {
        lVar12 = 0;
        do {
          lVar17 = *(long *)(uVar13 + lVar12);
          if (lVar17 == 0) break;
          if (*(long *)(lVar17 + 0x200) != 0) {
            __free_pages(*(long *)(lVar17 + 0x200),0);
            lVar17 = *(long *)(uVar13 + lVar12);
          }
          kfree(lVar17);
          lVar12 = lVar12 + 8;
        } while (lVar12 != 0x200);
        kfree(uVar13);
      }
    }
    puVar2[0x60] = 0;
    return 0;
  case 4:
    if (g_zram[0x33] >> 0xc <= param_3) {
      return 0;
    }
    lVar12 = sp_el0;
    puVar15 = (ulong *)(*g_zram + param_3 * 0x28 + 8);
    *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
    uVar9 = (uint)*puVar15;
    do {
      if ((uVar9 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar15,2,0,1);
        do {
          uVar13 = *puVar15;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
          if (bVar4) {
            *puVar15 = uVar13 | 0x2000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (((uint)uVar13 >> 0xd & 1) == 0) {
          uVar13 = *puVar2;
          if ((*(ushort *)(uVar13 + (param_3 & 0xffffffff) * 0x28 + 8) & 0xdfff) == 0) {
            uVar9 = 0;
          }
          else {
            uVar14 = *(ulong *)(uVar13 + param_3 * 0x28 + 8);
            uVar9 = (uint)uVar14;
            if ((uVar9 >> 0xf & 1) == 0) {
              if ((uVar9 >> 0xe & 1) == 0) {
                uVar9 = (uint)(uVar14 >> 0xf) & 4;
              }
              else {
                uVar9 = 3;
              }
            }
            else {
              uVar9 = 1;
              if ((*(ushort *)(uVar13 + (param_3 & 0xffffffff) * 0x28) & 0xfff) == 0) {
                uVar9 = 2;
              }
            }
          }
          puVar2 = (ulong *)(uVar13 + param_3 * 0x28 + 8);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar4) {
              *puVar2 = *puVar2 & 0xffffffffffffdfff;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          lVar17 = *(long *)(lVar12 + 0x10) + -1;
          *(int *)(lVar12 + 0x10) = (int)lVar17;
          if ((lVar17 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
            preempt_schedule();
          }
          return (ulong)uVar9;
        }
      }
      lVar17 = *(long *)(lVar12 + 0x10) + -1;
      *(int *)(lVar12 + 0x10) = (int)lVar17;
      if ((lVar17 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
        preempt_schedule();
      }
      do {
        Yield();
      } while (((uint)*puVar15 >> 0xd & 1) != 0);
      *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
      uVar9 = (uint)*puVar15;
    } while( true );
  case 5:
    if (g_zram[0x33] >> 0xc <= param_3) {
      return 0;
    }
    lVar12 = sp_el0;
    puVar15 = (ulong *)(*g_zram + param_3 * 0x28 + 8);
    *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
    uVar9 = (uint)*puVar15;
    do {
      if ((uVar9 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar15,2,0,1);
        do {
          uVar13 = *puVar15;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
          if (bVar4) {
            *puVar15 = uVar13 | 0x2000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (((uint)uVar13 >> 0xd & 1) == 0) break;
      }
      lVar17 = *(long *)(lVar12 + 0x10) + -1;
      *(int *)(lVar12 + 0x10) = (int)lVar17;
      if ((lVar17 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
        preempt_schedule();
      }
      do {
        Yield();
      } while (((uint)*puVar15 >> 0xd & 1) != 0);
      *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
      uVar9 = (uint)*puVar15;
    } while( true );
  case 6:
    if (param_3 < g_zram[0x33] >> 0xc) {
      uVar14 = *g_zram;
      lVar12 = sp_el0;
      uVar13 = param_3 & 0xffffffff;
      *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
      puVar15 = (ulong *)(uVar14 + uVar13 * 0x28 + 8);
      if (((uint)*puVar15 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar15,2,0,1);
        do {
          uVar14 = *puVar15;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
          if (bVar4) {
            *puVar15 = uVar14 | 0x2000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (((uint)uVar14 >> 0xd & 1) == 0) {
          uVar14 = *puVar2;
          if (((*(ushort *)(uVar14 + uVar13 * 0x28 + 8) & 0xdfff) == 0) ||
             ((*(ulong *)(uVar14 + param_3 * 0x28 + 8) & 0x308000) != 0x208000)) {
            puVar2 = (ulong *)(uVar14 + param_3 * 0x28 + 8);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 & 0xffffffffffffdfff;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
          else {
            uVar14 = *(ulong *)(uVar14 + uVar13 * 0x28);
            uVar13 = 1L << (uVar14 >> 0x1e & 0x3f);
            puVar15 = (ulong *)(puVar2[0x5f] + (uVar14 >> 0x24 & 0x3ffffff) * 8);
            Hint_Prefetch(puVar15,2,0,1);
            do {
              uVar16 = *puVar15;
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
              if (bVar4) {
                *puVar15 = uVar16 | uVar13;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            DataMemoryBarrier(2,3);
            if ((uVar16 & uVar13) == 0) {
              uVar8 = _raw_spin_lock_irqsave((long)puVar2 + 0x2b4);
              uVar13 = puVar2[0x50];
              if (uVar13 != 0) {
                lVar17 = (uVar14 >> 0x18) * 2;
                *(short *)(uVar13 + lVar17) = *(short *)(uVar13 + lVar17) + 1;
              }
              _raw_spin_unlock_irqrestore((long)puVar2 + 0x2b4,uVar8);
              puVar15 = (ulong *)(*puVar2 + param_3 * 0x28 + 8);
              Hint_Prefetch(puVar15,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
                if (bVar4) {
                  *puVar15 = *puVar15 & 0xffffffffffffdfff;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              lVar17 = *(long *)(lVar12 + 0x10) + -1;
              *(int *)(lVar12 + 0x10) = (int)lVar17;
              if ((lVar17 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
                preempt_schedule();
              }
              iVar6 = read_comp_from_bdev(puVar2,0,uVar14,0,1);
              if (iVar6 < 0) {
                zram_dec_wb_table(puVar2,uVar14 >> 0x18,1);
              }
              puVar2 = puVar2 + 0x24;
              Hint_Prefetch(puVar2,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                if (bVar4) {
                  *puVar2 = *puVar2 + 1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
              return 0;
            }
            puVar2 = (ulong *)(*puVar2 + param_3 * 0x28 + 8);
            Hint_Prefetch(puVar2,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
              if (bVar4) {
                *puVar2 = *puVar2 & 0xffffffffffffdfff;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
          }
        }
      }
      lVar17 = *(long *)(lVar12 + 0x10) + -1;
      *(int *)(lVar12 + 0x10) = (int)lVar17;
      if ((lVar17 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
        preempt_schedule();
        return 0xffffffffffffffff;
      }
    }
    return 0xffffffffffffffff;
  default:
    return 0;
  }
  uVar13 = *puVar2;
  if ((*(ushort *)(uVar13 + (param_3 & 0xffffffff) * 0x28 + 8) & 0xdfff) != 0) {
    uVar8 = _raw_spin_lock_irqsave(puVar2 + 0x56);
    uVar13 = *puVar2;
    plVar18 = (long *)(uVar13 + param_3 * 0x28 + 0x18);
    if ((long *)*plVar18 != plVar18) {
      uVar14 = __list_del_entry_valid(plVar18);
      if ((uVar14 & 1) != 0) {
        lVar17 = *plVar18;
        plVar11 = *(long **)(uVar13 + param_3 * 0x28 + 0x20);
        *(long **)(lVar17 + 8) = plVar11;
        *plVar11 = lVar17;
      }
      *plVar18 = (long)plVar18;
      *(long **)(uVar13 + param_3 * 0x28 + 0x20) = plVar18;
      puVar15 = (ulong *)(*puVar2 + param_3 * 0x28 + 8);
      uVar13 = *puVar15;
      if (((uint)uVar13 >> 0x17 & 1) != 0) {
        *puVar15 = uVar13 & 0xffffffffff7fffff;
        puVar15 = puVar2 + 0x2c;
        Hint_Prefetch(puVar15,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
          if (bVar4) {
            *puVar15 = *puVar15 - 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
    }
    _raw_spin_unlock_irqrestore(puVar2 + 0x56,uVar8);
    uVar13 = *puVar2;
  }
  puVar2 = (ulong *)(uVar13 + param_3 * 0x28 + 8);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar4) {
      *puVar2 = *puVar2 & 0xffffffffffffdfff;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  lVar17 = *(long *)(lVar12 + 0x10) + -1;
  *(int *)(lVar12 + 0x10) = (int)lVar17;
  if (lVar17 == 0) goto LAB_00108430;
  lVar12 = *(long *)(lVar12 + 0x10);
  goto joined_r0x00108130;
LAB_00107c68:
  puVar10 = (ulong *)(*puVar2 + uVar16 * 0x28 + 8);
  if (((uint)*puVar10 >> 0x16 & 1) == 0) {
    Hint_Prefetch(puVar10,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
      if (bVar4) {
        *puVar10 = *puVar10 & 0xffffffffffffdfff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar17 = *(long *)(lVar12 + 0x10);
  }
  else {
    *puVar10 = *puVar10 & 0xffffffffffbfffff;
    uVar8 = _raw_spin_lock_irqsave(puVar1);
    uVar13 = *puVar2;
    plVar18 = (long *)(uVar13 + uVar16 * 0x28 + 0x18);
    if ((long *)*plVar18 != plVar18) {
      uVar14 = __list_del_entry_valid(plVar18);
      if ((uVar14 & 1) != 0) {
        lVar17 = *plVar18;
        plVar11 = *(long **)(uVar13 + uVar16 * 0x28 + 0x20);
        *(long **)(lVar17 + 8) = plVar11;
        *plVar11 = lVar17;
      }
      *plVar18 = (long)plVar18;
      *(long **)(uVar13 + uVar16 * 0x28 + 0x20) = plVar18;
    }
    _raw_spin_unlock_irqrestore(puVar1,uVar8);
    puVar10 = (ulong *)(*puVar2 + uVar16 * 0x28 + 8);
    Hint_Prefetch(puVar10,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar10,0x10);
      if (bVar4) {
        *puVar10 = *puVar10 & 0xffffffffffffdfff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar17 = *(long *)(lVar12 + 0x10);
  }
  *(int *)(lVar12 + 0x10) = (int)(lVar17 + -1);
  if ((lVar17 + -1 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
    preempt_schedule();
  }
  plVar18 = (long *)*param_2;
  if (plVar18 == param_2) {
    return 0;
  }
  goto LAB_00107b64;
switchD_00107a34_caseD_1:
  uVar13 = zram_wb_available(g_zram);
  if ((uVar13 & 1) == 0) {
    return 0;
  }
  if (puVar2[0x33] >> 0xc <= param_3) {
    return 0;
  }
  uVar13 = *puVar2;
  lVar12 = sp_el0;
  *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
  puVar15 = (ulong *)(uVar13 + (param_3 & 0xffffffff) * 0x28 + 8);
  if (((uint)*puVar15 >> 0xd & 1) == 0) {
    Hint_Prefetch(puVar15,2,0,1);
    do {
      uVar13 = *puVar15;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
      if (bVar4) {
        *puVar15 = uVar13 | 0x2000;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (((uint)uVar13 >> 0xd & 1) == 0) {
      uVar13 = *puVar2;
      if ((*(ushort *)(uVar13 + (param_3 & 0xffffffff) * 0x28 + 8) & 0xdfff) != 0) {
        puVar15 = (ulong *)(uVar13 + param_3 * 0x28 + 8);
        uVar14 = *puVar15;
        if ((uVar14 & 0x45c000) == 0) {
          *puVar15 = uVar14 | 0x40000;
          lVar17 = *puVar2 + param_3 * 0x28;
          *(ulong *)(lVar17 + 8) = *(ulong *)(lVar17 + 8) | 0x400000;
          uVar8 = _raw_spin_lock_irqsave(puVar2 + 0x56);
          plVar18 = (long *)(*puVar2 + param_3 * 0x28 + 0x18);
          if ((long *)*plVar18 != plVar18) {
            list_move(plVar18,param_2);
            puVar15 = (ulong *)(*puVar2 + param_3 * 0x28 + 8);
            uVar13 = *puVar15;
            if (((uint)uVar13 >> 0x17 & 1) != 0) {
              *puVar15 = uVar13 & 0xffffffffff7fffff;
              puVar15 = puVar2 + 0x2c;
              Hint_Prefetch(puVar15,2,0,1);
              do {
                cVar3 = '\x01';
                bVar4 = (bool)ExclusiveMonitorPass(puVar15,0x10);
                if (bVar4) {
                  *puVar15 = *puVar15 - 1;
                  cVar3 = ExclusiveMonitorsStatus();
                }
              } while (cVar3 != '\0');
            }
          }
          _raw_spin_unlock_irqrestore(puVar2 + 0x56,uVar8);
          uVar13 = *puVar2;
        }
      }
      puVar2 = (ulong *)(uVar13 + param_3 * 0x28 + 8);
      Hint_Prefetch(puVar2,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
        if (bVar4) {
          *puVar2 = *puVar2 & 0xffffffffffffdfff;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
  }
  lVar17 = *(long *)(lVar12 + 0x10) + -1;
  *(int *)(lVar12 + 0x10) = (int)lVar17;
  if (lVar17 == 0) goto LAB_00108430;
  lVar12 = *(long *)(lVar12 + 0x10);
joined_r0x00108130:
  if (lVar12 != 0) {
    return 0;
  }
LAB_00108430:
  preempt_schedule();
  return 0;
}



//------------------------------------------------------------
// zram_wbd @ 0010866c size=1028
// signature: undefined zram_wbd(void)
// callers: []
//------------------------------------------------------------

undefined8 zram_wbd(ulong *param_1)

{
  ulong *puVar1;
  ulong *puVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  ulong *puVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  ulong *puVar16;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  local_70 = 0;
  set_freezable();
  uVar7 = kthread_should_stop();
  if ((uVar7 & 1) == 0) {
    puVar1 = param_1 + 0x4d;
    puVar2 = param_1 + 0x54;
    lVar15 = sp_el0;
    do {
      if (((char)param_1[0x53] == '\0') && (uVar7 = kthread_should_stop(), (uVar7 & 1) == 0)) {
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_98 = 0;
        init_wait_entry(&local_98,0);
        lVar8 = prepare_to_wait_event(puVar1,&local_98,0x2001);
        if ((char)param_1[0x53] == '\0') {
          do {
            uVar7 = kthread_should_stop();
            if ((uVar7 & 1) != 0) break;
            if (lVar8 != 0) goto LAB_0010874c;
            schedule();
            lVar8 = prepare_to_wait_event(puVar1,&local_98,0x2001);
          } while ((char)param_1[0x53] == '\0');
        }
        finish_wait(puVar1,&local_98);
      }
LAB_0010874c:
      puVar11 = (ulong *)*puVar2;
      if (puVar11 != puVar2) {
        uVar7 = 0;
        puVar16 = puVar11 + -3;
        while( true ) {
          uVar14 = *puVar11;
          uVar9 = kthread_should_stop();
          if (((uVar9 & 1) != 0) || (uVar9 = zram_wb_available(param_1), (uVar9 & 1) == 0)) break;
          puVar11 = (ulong *)*param_1;
          if (puVar16 < puVar11) {
            uVar13 = param_1[0x33] >> 0xc;
            uVar9 = uVar13;
          }
          else {
            uVar13 = param_1[0x33] >> 0xc;
            uVar9 = (ulong)((long)puVar16 - (long)puVar11) / 0x28;
          }
          uVar12 = uVar9 & 0xffffffff;
          if (uVar12 < uVar13) {
            puVar16 = (ulong *)(uVar14 - 0x18);
            *(int *)(lVar15 + 0x10) = *(int *)(lVar15 + 0x10) + 1;
            puVar11 = puVar11 + uVar12 * 5 + 1;
            if (((uint)*puVar11 >> 0xd & 1) == 0) {
              Hint_Prefetch(puVar11,2,0,1);
              do {
                uVar14 = *puVar11;
                cVar4 = '\x01';
                bVar5 = (bool)ExclusiveMonitorPass(puVar11,0x10);
                if (bVar5) {
                  *puVar11 = uVar14 | 0x2000;
                  cVar4 = ExclusiveMonitorsStatus();
                }
              } while (cVar4 != '\0');
              if (((uint)uVar14 >> 0xd & 1) == 0) {
                puVar11 = (ulong *)(*param_1 + uVar12 * 0x28 + 8);
                uVar14 = *puVar11;
                if (((uVar14 & 0xdfff) == 0) || (((uint)uVar14 >> 0x16 & 1) != 0)) {
                  Hint_Prefetch(puVar11,2,0,1);
                  do {
                    cVar4 = '\x01';
                    bVar5 = (bool)ExclusiveMonitorPass(puVar11,0x10);
                    if (bVar5) {
                      *puVar11 = *puVar11 & 0xffffffffffffdfff;
                      cVar4 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar4 != '\0');
                  lVar8 = *(long *)(lVar15 + 0x10) + -1;
                  *(int *)(lVar15 + 0x10) = (int)lVar8;
                  if ((lVar8 == 0) || (*(long *)(lVar15 + 0x10) == 0)) {
                    preempt_schedule();
                  }
                  goto LAB_001088ac;
                }
                if (((uint)uVar14 >> 0x10 & 1) == 0) {
                  *puVar11 = uVar14 | 0x40000;
                  puVar11 = (ulong *)(*param_1 + uVar12 * 0x28 + 8);
                  Hint_Prefetch(puVar11,2,0,1);
                  do {
                    cVar4 = '\x01';
                    bVar5 = (bool)ExclusiveMonitorPass(puVar11,0x10);
                    if (bVar5) {
                      *puVar11 = *puVar11 & 0xffffffffffffdfff;
                      cVar4 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar4 != '\0');
                  lVar8 = *(long *)(lVar15 + 0x10) + -1;
                  *(int *)(lVar15 + 0x10) = (int)lVar8;
                  if ((lVar8 == 0) || (*(long *)(lVar15 + 0x10) == 0)) {
                    preempt_schedule();
                  }
                  iVar6 = zram_writeback_index(param_1,uVar9 & 0xffffffff,&local_70,0);
                  if (iVar6 == 0) goto LAB_001088b4;
                  break;
                }
                Hint_Prefetch(puVar11,2,0,1);
                do {
                  cVar4 = '\x01';
                  bVar5 = (bool)ExclusiveMonitorPass(puVar11,0x10);
                  if (bVar5) {
                    *puVar11 = *puVar11 & 0xffffffffffffdfff;
                    cVar4 = ExclusiveMonitorsStatus();
                  }
                } while (cVar4 != '\0');
              }
            }
            lVar8 = *(long *)(lVar15 + 0x10) + -1;
            *(int *)(lVar15 + 0x10) = (int)lVar8;
            if ((lVar8 == 0) || (*(long *)(lVar15 + 0x10) == 0)) {
              preempt_schedule();
            }
          }
          else {
LAB_001088ac:
            puVar16 = (ulong *)(*puVar2 - 0x18);
          }
LAB_001088b4:
          uVar9 = param_1[0x2c];
          if (uVar9 == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = 0;
            if (uVar9 != 0) {
              iVar6 = (int)(((param_1[0x1f] - (param_1[0x26] + param_1[0x1e])) * 100) / uVar9);
            }
          }
          if ((0x139c < uVar7) || (is_app_launch != '\0')) break;
          iVar3 = zram_balance_ratio / 10;
          if (iVar3 < 2) {
            iVar3 = 1;
          }
          uVar14 = 0x40000000;
          if (param_1[0x33] < 0x100000004) {
            uVar14 = param_1[0x33] >> 2;
          }
          if ((uVar9 * 0x1000 < uVar14) || (iVar3 + zram_balance_ratio < iVar6)) break;
          puVar11 = puVar16 + 3;
          uVar7 = uVar7 + 1;
          if (puVar11 == puVar2) break;
        }
      }
      *(undefined1 *)(param_1 + 0x53) = 0;
      _printk(&DAT_0010cd29,"zram_wbd");
      uVar7 = kthread_should_stop();
      lVar8 = local_70;
    } while ((uVar7 & 1) == 0);
    if (local_70 != 0) {
      lVar15 = 0;
      do {
        lVar10 = *(long *)(lVar8 + lVar15);
        if (lVar10 == 0) break;
        if (*(long *)(lVar10 + 0x200) != 0) {
          __free_pages(*(long *)(lVar10 + 0x200),0);
          lVar10 = *(long *)(lVar8 + lVar15);
        }
        kfree(lVar10);
        lVar15 = lVar15 + 8;
      } while (lVar15 != 0x200);
      kfree(lVar8);
    }
  }
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// zram_wb_available @ 00108ab0 size=324
// signature: undefined zram_wb_available(void)
// callers: [zram_wbd, zram_writeback_oem_func, writeback_store]
//------------------------------------------------------------

void zram_wb_available(long param_1)

{
  ulong uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  undefined8 local_a0;
  long local_98;
  undefined8 uStack_90;
  long local_88;
  ulong uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x240) + 0x3f8);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if (((lVar4 != 0) && (lVar4 = *(long *)(lVar4 + 0x58), lVar4 != 0)) &&
     (lVar4 = *(long *)(lVar4 + 0x60), lVar4 != 0)) {
    lVar4 = *(long *)(*(long *)(**(long **)(lVar4 + 0xe8) + 0x28) + 0x68);
    pcVar5 = *(code **)(*(long *)(*(long *)(lVar4 + 0x68) + 0x30) + 0x68);
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(pcVar5 + -4) != -0x6c5af77b) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x108b4c);
        (*pcVar5)();
      }
      iVar3 = (*pcVar5)(lVar4,&local_a0);
      if (iVar3 == 0) {
        uVar1 = 0;
        if (local_98 != 0) {
          uVar1 = 0x40000000 / local_98;
        }
        uVar6 = (local_88 - uStack_80) * 2;
        if (uVar1 <= uVar6) {
          uVar1 = uVar6;
        }
        if ((uVar1 <= uStack_80) && (*(long *)(param_1 + 0x280) != 0)) {
          lVar4 = param_1 + 0x230;
          _raw_spin_lock(lVar4);
          if ((*(char *)(param_1 + 0x234) == '\0') || (*(long *)(param_1 + 0x238) != 0)) {
            _raw_spin_unlock(lVar4);
            bVar2 = *(ulong *)(param_1 + 0xf8) < (ulong)(*(long *)(param_1 + 0x250) << 2);
            goto LAB_00108bc8;
          }
          _raw_spin_unlock(lVar4);
        }
      }
    }
  }
  bVar2 = false;
LAB_00108bc8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// zram_writeback_index @ 00108bf4 size=1864
// signature: undefined zram_writeback_index(void)
// callers: [zram_wbd, zram_writeback_oem_func, writeback_store]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00109058) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 zram_writeback_index(long *param_1,uint param_2,long *param_3,byte param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  void *__src;
  uint *__dest;
  void *pvVar8;
  undefined8 uVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  ulong *puVar13;
  long lVar14;
  int iVar15;
  ulong __n;
  long lVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  long *plVar21;
  ulong unaff_x30;
  
  uVar20 = (ulong)param_2;
  lVar16 = *param_3;
  lVar19 = sp_el0;
LAB_00108c70:
  if (lVar16 == 0) {
    lVar16 = kmalloc_trace(_blk_queue_physical_block_size,0xdc0,0x208);
    if (lVar16 == 0) {
      return 0xfffffff4;
    }
    lVar11 = 0;
    do {
      lVar18 = kmalloc_trace(_blk_queue_physical_block_size,0xdc0,0x210);
      *(long *)(lVar16 + lVar11) = lVar18;
      if (lVar18 == 0) {
LAB_001092a0:
        lVar19 = 0;
        goto LAB_001092bc;
      }
      uVar9 = tpidr_el1;
      lVar14 = __alloc_pages(uVar9,0xcc0,0,0,0);
      *(long *)(lVar18 + 0x200) = lVar14;
      if (lVar14 == 0) goto LAB_001092a0;
      lVar11 = lVar11 + 8;
    } while (lVar11 != 0x200);
  }
  iVar3 = *(int *)(lVar16 + 0x200);
  lVar18 = (long)iVar3;
  lVar11 = *(long *)(lVar16 + lVar18 * 8);
  puVar13 = (ulong *)(*param_1 + uVar20 * 0x28 + 8);
  uVar17 = *(ulong *)(lVar11 + 0x200);
  iVar4 = *(int *)(lVar11 + 0x20c);
  plVar21 = (long *)(lVar19 + 0x10);
  *(int *)plVar21 = *(int *)plVar21 + 1;
  uVar10 = (uint)*puVar13;
  do {
    if ((uVar10 >> 0xd & 1) == 0) {
      Hint_Prefetch(puVar13,2,0,1);
      do {
        uVar12 = *puVar13;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(puVar13,0x10);
        if (bVar6) {
          *puVar13 = uVar12 | 0x2000;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      if (((uint)uVar12 >> 0xd & 1) == 0) break;
    }
    lVar11 = *plVar21;
    *(int *)plVar21 = (int)(lVar11 + -1);
    if ((lVar11 + -1 == 0) || (*plVar21 == 0)) {
      preempt_schedule();
    }
    do {
      Yield();
    } while (((uint)*puVar13 >> 0xd & 1) != 0);
    *(int *)plVar21 = *(int *)plVar21 + 1;
    uVar10 = (uint)*puVar13;
  } while( true );
  puVar13 = (ulong *)(*param_1 + uVar20 * 0x28 + 8);
  uVar12 = *puVar13;
  if (((uVar12 & 0xdfff) == 0) || ((uVar12 & 0x5c000) != 0x40000)) {
    Hint_Prefetch(puVar13,2,0,1);
    do {
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar13,0x10);
      if (bVar6) {
        *puVar13 = *puVar13 & 0xffffffffffffdfff;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    lVar11 = *plVar21;
    *(int *)plVar21 = (int)(lVar11 + -1);
    if ((lVar11 + -1 == 0) || (*plVar21 == 0)) {
      uVar10 = 0;
      goto LAB_00109200;
    }
  }
  else {
    __n = uVar12 & 0x1fff;
    uVar10 = (uint)uVar12 & 0x1fff;
    iVar15 = 8;
    if ((param_4 & 1) == 0 && __n == 0x1000) {
      iVar15 = 0;
    }
    uVar1 = iVar15 + iVar4;
    if ((((iVar3 == 0x3f | param_4 ^ 0xff) & 0x1000 < uVar1 + uVar10) == 0) && (uVar1 < 0x1001)) {
      *puVar13 = uVar12 | 0x10000;
      lVar14 = uVar20 * 0x28;
      *(ulong *)(*param_1 + lVar14 + 8) = *(ulong *)(*param_1 + lVar14 + 8) | 0x40000;
      lVar11 = *(long *)(*param_1 + lVar14);
      if (lVar11 == 0) {
        lVar11 = *param_1 + lVar14;
        *(ulong *)(lVar11 + 8) = *(ulong *)(lVar11 + 8) & 0xfffffffffffeffff;
        *(ulong *)(*param_1 + lVar14 + 8) = *(ulong *)(*param_1 + lVar14 + 8) & 0xfffffffffffbffff;
        puVar13 = (ulong *)(*param_1 + lVar14 + 8);
        Hint_Prefetch(puVar13,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar13,0x10);
          if (bVar6) {
            *puVar13 = *puVar13 & 0xffffffffffffdfff;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        lVar11 = *plVar21;
        *(int *)plVar21 = (int)(lVar11 + -1);
        if ((lVar11 + -1 != 0) && (*plVar21 != 0)) goto LAB_00108f80;
        uVar10 = 0xfffffffe;
        goto LAB_00109200;
      }
      __src = (void *)zs_map_object(param_1[1],lVar11,1);
      *(int *)(lVar19 + 0x10) = *(int *)(lVar19 + 0x10) + 1;
      *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + 1;
      __dest = (uint *)((uVar17 & 0x3ffffffffffc0) << 6 | 0xff00000000000000);
      if ((param_4 & 1) != 0 || __n != 0x1000) {
        puVar2 = (uint *)((long)__dest + (long)iVar4);
        __dest = puVar2 + 2;
        *puVar2 = param_2;
        puVar2[1] = uVar10;
      }
      if (uVar1 + uVar10 < 0x1001) {
        pvVar8 = memcpy(__dest,__src,__n);
      }
      else {
        uVar1 = 0x1000 - uVar1;
        memcpy(__dest,__src,(ulong)uVar1);
        *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + -1;
        lVar14 = *(long *)(lVar19 + 0x10) + -1;
        *(int *)(lVar19 + 0x10) = (int)lVar14;
        if ((lVar14 == 0) || (*plVar21 == 0)) {
          preempt_schedule();
        }
        uVar17 = *(ulong *)(*(long *)(lVar16 + (long)(iVar3 + 1) * 8) + 0x200);
        *(int *)(lVar19 + 0x10) = *(int *)(lVar19 + 0x10) + 1;
        *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + 1;
        pvVar8 = memcpy((void *)((uVar17 & 0x3ffffffffffc0) << 6 | 0xff00000000000000),
                        (void *)((long)__src + (ulong)uVar1),(long)(int)(uVar10 - uVar1));
        *(uint *)(*(long *)(lVar16 + (long)(iVar3 + 1) * 8) + 0x20c) = uVar10 - uVar1;
      }
      *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + -1;
      lVar14 = *(long *)(lVar19 + 0x10) + -1;
      *(int *)(lVar19 + 0x10) = (int)lVar14;
      if ((lVar14 == 0) || (*plVar21 == 0)) {
        preempt_schedule(pvVar8,lVar11);
      }
      if (((uVar10 != 0x1000) && (is_lzorle != '\0')) &&
         (*(short *)((long)__src + (__n - 3)) != lzo_marker ||
          *(char *)((long)__src + (__n - 1)) != DAT_0010d83a)) {
        uVar20 = unaff_x30 & 0xff80007fffffffff;
        if ((unaff_x30 & 0x80000000000000) != 0) {
          uVar20 = unaff_x30 | 0xffffff8000000000;
        }
        _printk(&DAT_0010c7ac,uVar20,__src,uVar10);
        print_hex_dump(&DAT_0010c71e,"",2,0x10,1,__src,__n,1);
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10937c);
        (*pcVar7)();
      }
      zs_unmap_object(param_1[1],lVar11);
      puVar13 = (ulong *)(*param_1 + uVar20 * 0x28 + 8);
      Hint_Prefetch(puVar13,2,0,1);
      do {
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(puVar13,0x10);
        if (bVar6) {
          *puVar13 = *puVar13 & 0xffffffffffffdfff;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      lVar11 = *plVar21;
      *(int *)plVar21 = (int)(lVar11 + -1);
      if ((lVar11 + -1 == 0) || (*plVar21 == 0)) goto LAB_00109200;
      if ((uVar12 & 0x1fff) == 0) goto LAB_00109214;
    }
    else {
      Hint_Prefetch(puVar13,2,0,1);
      do {
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(puVar13,0x10);
        if (bVar6) {
          *puVar13 = *puVar13 & 0xffffffffffffdfff;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      lVar11 = *plVar21;
      *(int *)plVar21 = (int)(lVar11 + -1);
      if ((lVar11 + -1 != 0) && (*plVar21 != 0)) goto LAB_00108fc0;
      uVar10 = 0xffffffe4;
LAB_00109200:
      preempt_schedule();
      if ((int)uVar10 < 1) {
LAB_00109214:
        if (uVar10 == 0xffffffe4) goto LAB_00108fc0;
        goto LAB_00108f80;
      }
    }
    lVar11 = lVar18 * 8;
    lVar14 = *(long *)(lVar16 + lVar11);
    *(ulong *)(lVar14 + (ulong)*(uint *)(lVar14 + 0x208) * 0x10) = uVar20;
    *(undefined4 *)(lVar14 + (ulong)*(uint *)(*(long *)(lVar16 + lVar11) + 0x208) * 0x10 + 8) =
         *(undefined4 *)(*(long *)(lVar16 + lVar11) + 0x20c);
    *(uint *)(lVar14 + (ulong)*(uint *)(*(long *)(lVar16 + lVar11) + 0x208) * 0x10 + 0xc) = uVar10;
    *(uint *)(*(long *)(lVar16 + lVar11) + 0x20c) =
         uVar10 + *(int *)(*(long *)(lVar16 + lVar11) + 0x20c) + 8;
    *(int *)(*(long *)(lVar16 + lVar11) + 0x208) = *(int *)(*(long *)(lVar16 + lVar11) + 0x208) + 1;
  }
LAB_00108f80:
  if (*(int *)(*(long *)(lVar16 + lVar18 * 8) + 0x208) != 0x20) {
    uVar9 = 0;
    goto LAB_0010930c;
  }
LAB_00108fc0:
  lVar18 = *(long *)(lVar16 + lVar18 * 8);
  lVar11 = (long)*(int *)(lVar18 + 0x20c);
  if (lVar11 + 8U < 0x1000) {
    uVar17 = *(ulong *)(lVar18 + 0x200);
    *(int *)(lVar19 + 0x10) = *(int *)(lVar19 + 0x10) + 1;
    *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + 1;
    *(undefined8 *)(((uVar17 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) + lVar11) = 0xffffffff;
    *(int *)(lVar19 + 0xb68) = *(int *)(lVar19 + 0xb68) + -1;
    lVar11 = *(long *)(lVar19 + 0x10) + -1;
    *(int *)(lVar19 + 0x10) = (int)lVar11;
    if ((lVar11 == 0) || (*plVar21 == 0)) {
      preempt_schedule();
    }
  }
  iVar3 = *(int *)(lVar16 + 0x200) + 1;
  *(int *)(lVar16 + 0x200) = iVar3;
  if (iVar3 == 0x40) {
    uVar9 = zram_writeback_page(param_1,lVar16,param_4 & 1);
    lVar16 = 0;
    if ((int)uVar9 != 0) {
LAB_0010930c:
      *param_3 = lVar16;
      return uVar9;
    }
  }
  goto LAB_00108c70;
  while( true ) {
    if (*(long *)(lVar11 + 0x200) != 0) {
      __free_pages(*(long *)(lVar11 + 0x200),0);
    }
    kfree(lVar11);
    lVar19 = lVar19 + 8;
    if (lVar19 == 0x200) break;
LAB_001092bc:
    lVar11 = *(long *)(lVar16 + lVar19);
    if (lVar11 == 0) break;
  }
  kfree(lVar16);
  return 0xfffffff4;
}



//------------------------------------------------------------
// zram_writeback_page @ 0010937c size=1540
// signature: undefined zram_writeback_page(void)
// callers: [zram_writeback_index, zram_writeback_oem_func, writeback_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 zram_writeback_page(long param_1,long *param_2,byte param_3)

{
  long *plVar1;
  int *piVar2;
  ushort uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong *puVar12;
  ulong uVar11;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  
  if ((param_3 & 1) == 0) {
    puVar12 = (ulong *)(param_1 + 0x290);
    uVar9 = 1;
  }
  else {
    uVar9 = (*(ulong *)(param_1 + 0x290) >> 6) + 1;
    puVar12 = (ulong *)(param_1 + 0x250);
  }
  uVar11 = *puVar12;
  lVar17 = param_1 + 0x2b8;
  while( true ) {
    uVar9 = _find_next_zero_bit(*(undefined8 *)(param_1 + 0x288),uVar11 >> 6,uVar9);
    if (uVar9 == uVar11 >> 6) goto LAB_001097f4;
    uVar10 = _raw_spin_lock_irqsave(lVar17);
    uVar13 = 1L << (uVar9 & 0x3f);
    puVar12 = (ulong *)(*(long *)(param_1 + 0x288) + (uVar9 >> 6 & 0x3ffffff) * 8);
    Hint_Prefetch(puVar12,2,0,1);
    do {
      uVar15 = *puVar12;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar12,0x10);
      if (bVar5) {
        *puVar12 = uVar15 | uVar13;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar15 & uVar13) == 0) break;
    _raw_spin_unlock_irqrestore(lVar17,uVar10);
  }
  uVar11 = 0;
  lVar18 = uVar9 * 0x40;
  do {
    uVar13 = 1L << (uVar11 & 0x3f);
    puVar12 = (ulong *)(*(long *)(param_1 + 0x248) + (uVar9 & 0x3ffffff) * 8);
    Hint_Prefetch(puVar12,2,0,1);
    do {
      uVar15 = *puVar12;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar12,0x10);
      if (bVar5) {
        *puVar12 = uVar15 | uVar13;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar15 & uVar13) != 0) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x800,0x1094bc);
      (*pcVar7)();
    }
    uVar11 = uVar11 + 1;
  } while (uVar11 != 0x40);
  _raw_spin_unlock_irqrestore(lVar17,uVar10);
  plVar1 = (long *)(param_1 + 0xd8);
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar5) {
      *plVar1 = *plVar1 + 0x40;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if ((param_3 & 1) != 0) {
    plVar1 = (long *)(param_1 + 0x118);
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar5) {
        *plVar1 = *plVar1 + 0x40;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
  if (lVar18 != 0) {
    lVar17 = *(long *)(param_1 + 0x240);
    if (lVar17 != 0) {
      mutex_lock(param_1 + 0x2c8);
      uVar11 = 1L << ((uVar9 & 0x3ffffffffffffff) >> 3 & 0x3f);
      puVar12 = (ulong *)(*(long *)(param_1 + 0x2c0) +
                         ((uVar9 & 0x3ffffffffffffff) >> 9 & 0x3ffffff) * 8);
      Hint_Prefetch(puVar12,2,0,1);
      do {
        uVar13 = *puVar12;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar12,0x10);
        if (bVar5) {
          *puVar12 = uVar13 | uVar11;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
      if ((uVar13 & uVar11) == 0) {
        lVar19 = (uVar9 & 0x3ffffffffff8) << 0x12;
        lVar17 = *(long *)(*(long *)(*(long *)(lVar17 + 0x3f8) + 0x58) + 0x60);
        if ((**(ushort **)(lVar17 + 0x20) & 0xf000) == 0x8000) {
          lVar16 = *(long *)(*(ushort **)(lVar17 + 0x20) + 0x14);
          lVar14 = sp_el0;
          *(int *)(lVar14 + 0x10) = *(int *)(lVar14 + 0x10) + 1;
          _trace_android_vh_record_pcpu_rwsem_time_early(_jiffies,lVar16 + 0x2a8);
          if (*(int *)(lVar16 + 0x2a8) == 0) {
            *(int *)(lVar14 + 0x10) = *(int *)(lVar14 + 0x10) + 1;
            lVar6 = tpidr_el1;
            piVar2 = (int *)(lVar6 + *(long *)(lVar16 + 0x2d8));
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
              if (bVar5) {
                *piVar2 = *piVar2 + 1;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            lVar16 = *(long *)(lVar14 + 0x10) + -1;
            *(int *)(lVar14 + 0x10) = (int)lVar16;
            if ((lVar16 == 0) || (*(long *)(lVar14 + 0x10) == 0)) {
              preempt_schedule_notrace();
            }
          }
          else {
            __percpu_down_read(lVar16 + 0x2a8,0);
          }
          lVar16 = *(long *)(lVar14 + 0x10) + -1;
          *(int *)(lVar14 + 0x10) = (int)lVar16;
          if ((lVar16 == 0) || (*(long *)(lVar14 + 0x10) == 0)) {
            preempt_schedule();
          }
          _trace_android_vh_record_pcpu_rwsem_starttime(lVar14,_jiffies);
        }
        pcVar7 = *(code **)(*(long *)(lVar17 + 0x28) + 0xd8);
        if (*(int *)(pcVar7 + -4) != -0x5fdc689) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x109628);
          (*pcVar7)();
        }
        iVar8 = (*pcVar7)(lVar17,1,lVar19,0x200000);
        if (iVar8 != 0) {
          _printk(&DAT_0010cd39,"fallocate_block",lVar19);
        }
        if ((**(ushort **)(lVar17 + 0x20) & 0xf000) == 0x8000) {
          lVar19 = *(long *)(*(ushort **)(lVar17 + 0x20) + 0x14);
          lVar17 = sp_el0;
          *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
          if (*(int *)(lVar19 + 0x2a8) == 0) {
            *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
            lVar14 = tpidr_el1;
            piVar2 = (int *)(lVar14 + *(long *)(lVar19 + 0x2d8));
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
              if (bVar5) {
                *piVar2 = *piVar2 + -1;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            lVar14 = *(long *)(lVar17 + 0x10) + -1;
            *(int *)(lVar17 + 0x10) = (int)lVar14;
            if ((lVar14 == 0) || (*(long *)(lVar17 + 0x10) == 0)) {
              preempt_schedule_notrace();
            }
          }
          else {
            DataMemoryBarrier(2,3);
            *(int *)(lVar17 + 0x10) = *(int *)(lVar17 + 0x10) + 1;
            lVar14 = tpidr_el1;
            piVar2 = (int *)(lVar14 + *(long *)(lVar19 + 0x2d8));
            do {
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
              if (bVar5) {
                *piVar2 = *piVar2 + -1;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            lVar14 = *(long *)(lVar17 + 0x10) + -1;
            *(int *)(lVar17 + 0x10) = (int)lVar14;
            if ((lVar14 == 0) || (*(long *)(lVar17 + 0x10) == 0)) {
              preempt_schedule_notrace();
            }
            rcuwait_wake_up(lVar19 + 0x2e0);
          }
          _trace_android_vh_record_pcpu_rwsem_time_early(0,lVar19 + 0x2a8);
          _trace_android_vh_record_pcpu_rwsem_starttime(lVar17,0);
          lVar19 = *(long *)(lVar17 + 0x10) + -1;
          *(int *)(lVar17 + 0x10) = (int)lVar19;
          if ((lVar19 == 0) || (*(long *)(lVar17 + 0x10) == 0)) {
            preempt_schedule();
          }
        }
      }
      mutex_unlock(param_1 + 0x2c8);
    }
    lVar17 = kmalloc_trace(_blk_queue_physical_block_size,0xdc0,0x268);
    if (lVar17 != 0) {
      lVar19 = bio_alloc_bioset(*(undefined8 *)(param_1 + 0x240),0x40,1,0xc00,&fs_bio_set);
      if (lVar19 != 0) {
        *(code **)(lVar19 + 0x38) = zram_writeback_page_end_io;
        uVar3 = *(ushort *)(lVar19 + 0x14);
        *(ulong *)(lVar19 + 0x20) = uVar9 << 9;
        lVar14 = *(long *)(param_1 + 0x240);
        *(ushort *)(lVar19 + 0x14) = uVar3 & 0xf7ff;
        if (*(long *)(lVar19 + 8) != lVar14) {
          *(ushort *)(lVar19 + 0x14) = uVar3 & 0xf7bf;
        }
        *(long *)(lVar19 + 8) = lVar14;
        bio_associate_blkg(lVar19);
        lVar14 = 0;
        do {
          bio_add_page(lVar19,*(undefined8 *)(*(long *)((long)param_2 + lVar14) + 0x200),0x1000,0);
          lVar14 = lVar14 + 8;
        } while (lVar14 != 0x200);
        lVar14 = *param_2;
        *(long *)(lVar17 + 0x250) = param_1;
        *(long *)(lVar17 + 600) = lVar18;
        *(long **)(lVar17 + 0x248) = param_2;
        *(undefined4 *)(lVar17 + 0x260) = 0x40;
        *(long *)(lVar17 + 0x238) = lVar19;
        *(byte *)(lVar17 + 0x264) = param_3 & 1;
        *(long *)(*(long *)(lVar14 + 0x200) + 0x28) = lVar17;
        submit_bio(lVar19);
        return 0;
      }
      kfree(lVar17);
    }
    lVar17 = 0;
    do {
      free_block_bdev(param_1,lVar18 + lVar17,param_3 & 1);
      lVar17 = lVar17 + 1;
    } while (lVar17 != 0x40);
  }
LAB_001097f4:
  lVar17 = 0;
  do {
    lVar18 = param_2[lVar17];
    if (*(int *)(lVar18 + 0x208) != 0) {
      lVar19 = 0;
      uVar9 = 0;
      do {
        if (uVar9 == 0x20) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x1098dc);
          (*pcVar7)();
        }
        zram_writeback_clear_flag(param_1,*(undefined4 *)(lVar18 + lVar19));
        lVar18 = param_2[lVar17];
        uVar9 = uVar9 + 1;
        lVar19 = lVar19 + 0x10;
      } while (uVar9 < *(uint *)(lVar18 + 0x208));
    }
    lVar17 = lVar17 + 1;
  } while (lVar17 != 0x40);
  if (param_2 != (long *)0x0) {
    lVar17 = 0;
    do {
      lVar18 = *(long *)((long)param_2 + lVar17);
      if (lVar18 == 0) break;
      if (*(long *)(lVar18 + 0x200) != 0) {
        __free_pages(*(long *)(lVar18 + 0x200),0);
        lVar18 = *(long *)((long)param_2 + lVar17);
      }
      kfree(lVar18);
      lVar17 = lVar17 + 8;
    } while (lVar17 != 0x200);
    kfree(param_2);
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// zram_writeback_page_end_io @ 001099d0 size=136
// signature: undefined zram_writeback_page_end_io(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zram_writeback_page_end_io(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(**(long **)(param_1 + 0x78) + 0x28);
  iVar2 = blk_status_to_errno(*(undefined1 *)(param_1 + 0x18));
  if (iVar2 != 0) {
    _printk(&DAT_0010c864,"zram_writeback_page_end_io",iVar2);
  }
  *puVar3 = 0xfffffffe0;
  puVar3[1] = puVar3 + 1;
  puVar3[2] = puVar3 + 1;
  uVar1 = _system_wq;
  puVar3[3] = zram_writeback_done_work;
  queue_work_on(0x20,uVar1,puVar3);
  return;
}



//------------------------------------------------------------
// zram_writeback_done_work @ 00109a5c size=1440
// signature: undefined zram_writeback_done_work(void)
// callers: []
//------------------------------------------------------------

void zram_writeback_done_work(long param_1)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  bool bVar7;
  code *pcVar8;
  undefined8 uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  ulong *puVar15;
  long lVar16;
  long lVar17;
  ulong uVar18;
  long lVar19;
  long lVar20;
  uint uVar21;
  ulong uVar22;
  long *plVar23;
  long lVar24;
  ulong uVar25;
  
  lVar11 = *(long *)(param_1 + 0x238);
  plVar23 = *(long **)(param_1 + 0x250);
  lVar24 = *(long *)(param_1 + 0x248);
  lVar16 = *(long *)(param_1 + 600);
  uVar3 = *(uint *)(param_1 + 0x260);
  cVar5 = *(char *)(param_1 + 0x264);
  if (*(char *)(lVar11 + 0x18) != '\0') {
    lVar17 = 0;
    do {
      lVar12 = *(long *)(lVar24 + lVar17 * 8);
      if (*(int *)(lVar12 + 0x208) != 0) {
        lVar19 = 0;
        uVar22 = 0;
        do {
          if (uVar22 == 0x20) goto LAB_0010a01c;
          zram_writeback_clear_flag(plVar23,*(undefined4 *)(lVar12 + lVar19));
          lVar12 = *(long *)(lVar24 + lVar17 * 8);
          uVar22 = uVar22 + 1;
          lVar19 = lVar19 + 0x10;
        } while (uVar22 < *(uint *)(lVar12 + 0x208));
      }
      lVar17 = lVar17 + 1;
    } while (lVar17 != 0x40);
  }
  if (0 < (int)uVar3) {
    uVar22 = 0;
    lVar17 = (long)plVar23 + 0x2b4;
    lVar12 = sp_el0;
    do {
      if (uVar22 == 0x40) {
LAB_0010a01c:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10a020);
        (*pcVar8)();
      }
      lVar13 = *(long *)(lVar24 + uVar22 * 8);
      uVar4 = *(uint *)(lVar13 + 0x208);
      uVar18 = (ulong)uVar4;
      lVar19 = lVar16 + uVar22;
      if (uVar4 == 0) {
        free_block_bdev(plVar23,lVar19,cVar5 != '\0');
      }
      else {
        uVar9 = _raw_spin_lock_irqsave(lVar17);
        if (plVar23[0x50] != 0) {
          *(short *)(plVar23[0x50] + lVar19 * 2) = (short)uVar4;
          _raw_spin_unlock_irqrestore(lVar17,uVar9);
          plVar1 = plVar23 + 0x2b;
          Hint_Prefetch(plVar1,2,0,1);
          do {
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
            if (bVar7) {
              *plVar1 = *plVar1 + uVar18;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          plVar1 = plVar23 + 0x1f;
          Hint_Prefetch(plVar1,2,0,1);
          do {
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
            if (bVar7) {
              *plVar1 = *plVar1 + uVar18;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          if (cVar5 != '\0') {
            plVar1 = plVar23 + 0x26;
            Hint_Prefetch(plVar1,2,0,1);
            do {
              cVar6 = '\x01';
              bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
              if (bVar7) {
                *plVar1 = *plVar1 + uVar18;
                cVar6 = ExclusiveMonitorsStatus();
              }
            } while (cVar6 != '\0');
          }
          uVar21 = 0;
LAB_00109c00:
          puVar15 = (ulong *)(lVar13 + (long)(int)uVar21 * 0x10);
          uVar25 = *puVar15;
          uVar18 = puVar15[1];
          uVar2 = *(uint *)((long)puVar15 + 0xc);
          puVar15 = (ulong *)(*plVar23 + uVar25 * 0x28 + 8);
          *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
          uVar10 = (uint)*puVar15;
          do {
            if ((uVar10 >> 0xd & 1) == 0) {
              Hint_Prefetch(puVar15,2,0,1);
              do {
                uVar14 = *puVar15;
                cVar6 = '\x01';
                bVar7 = (bool)ExclusiveMonitorPass(puVar15,0x10);
                if (bVar7) {
                  *puVar15 = uVar14 | 0x2000;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              if (((uint)uVar14 >> 0xd & 1) == 0) goto LAB_00109c9c;
            }
            lVar20 = *(long *)(lVar12 + 0x10) + -1;
            *(int *)(lVar12 + 0x10) = (int)lVar20;
            if ((lVar20 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
              preempt_schedule();
            }
            do {
              Yield();
            } while (((uint)*puVar15 >> 0xd & 1) != 0);
            *(int *)(lVar12 + 0x10) = *(int *)(lVar12 + 0x10) + 1;
            uVar10 = (uint)*puVar15;
          } while( true );
        }
        _raw_spin_unlock_irqrestore(lVar17,uVar9);
      }
LAB_00109b38:
      uVar22 = uVar22 + 1;
    } while (uVar22 != uVar3);
  }
  uVar22 = (ulong)(int)uVar3;
  if ((ulong)plVar23[0x21] < (ulong)plVar23[0x1b]) {
    plVar23[0x21] = plVar23[0x1b];
    plVar23[0x22] = plVar23[0x20];
    plVar23[0x28] = plVar23[0x23];
    plVar23[0x29] = plVar23[0x27];
  }
  plVar1 = plVar23 + 0x1d;
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar6 = '\x01';
    bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar7) {
      *plVar1 = *plVar1 + uVar22;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  if (cVar5 != '\0') {
    plVar1 = plVar23 + 0x25;
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar5 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar7) {
        *plVar1 = *plVar1 + uVar22;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
  }
  _raw_spin_lock(plVar23 + 0x46);
  if (*(char *)((long)plVar23 + 0x234) != '\0') {
    lVar16 = 0;
    if (uVar22 <= (ulong)plVar23[0x47]) {
      lVar16 = plVar23[0x47] - uVar22;
    }
    plVar23[0x47] = lVar16;
  }
  _raw_spin_unlock(plVar23 + 0x46);
  bio_put(lVar11);
  if (lVar24 != 0) {
    lVar11 = 0;
    do {
      lVar16 = *(long *)(lVar24 + lVar11);
      if (lVar16 == 0) break;
      if (*(long *)(lVar16 + 0x200) != 0) {
        __free_pages(*(long *)(lVar16 + 0x200),0);
        lVar16 = *(long *)(lVar24 + lVar11);
      }
      kfree(lVar16);
      lVar11 = lVar11 + 8;
    } while (lVar11 != 0x200);
    kfree(lVar24);
  }
  kfree(param_1);
  return;
LAB_00109c9c:
  puVar15 = (ulong *)(*plVar23 + uVar25 * 0x28 + 8);
  uVar14 = *puVar15;
  if ((*(ushort *)(*plVar23 + (uVar25 & 0xffffffff) * 0x28 + 8) & 0xdfff) == 0 ||
      (uVar14 & 0x40000) == 0) {
    *puVar15 = uVar14 & 0xfffffffffffeffff;
    lVar20 = uVar25 * 0x28;
    *(ulong *)(*plVar23 + lVar20 + 8) = *(ulong *)(*plVar23 + lVar20 + 8) & 0xfffffffffffbffff;
    *(ulong *)(*plVar23 + lVar20 + 8) = *(ulong *)(*plVar23 + lVar20 + 8) & 0xffffffffffbfffff;
    free_block_bdev(plVar23,lVar19,cVar5 != '\0');
    puVar15 = (ulong *)(*plVar23 + lVar20 + 8);
    Hint_Prefetch(puVar15,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar15,0x10);
      if (bVar7) {
        *puVar15 = *puVar15 & 0xffffffffffffdfff;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    lVar20 = *(long *)(lVar12 + 0x10) + -1;
    *(int *)(lVar12 + 0x10) = (int)lVar20;
    if ((lVar20 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
      preempt_schedule();
    }
  }
  else {
    zram_free_page(plVar23,uVar25);
    lVar20 = uVar25 * 0x28;
    *(ulong *)(*plVar23 + lVar20 + 8) = *(ulong *)(*plVar23 + lVar20 + 8) & 0xfffffffffffeffff;
    *(ulong *)(*plVar23 + lVar20 + 8) = *(ulong *)(*plVar23 + lVar20 + 8) | 0x8000;
    uVar9 = ktime_get_seconds();
    *(undefined8 *)(*plVar23 + lVar20 + 0x10) = uVar9;
    plVar1 = plVar23 + 0x20;
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar7) {
        *plVar1 = *plVar1 + (ulong)uVar2;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    if (cVar5 != '\0') {
      lVar20 = *plVar23 + uVar25 * 0x28;
      *(ulong *)(lVar20 + 8) = *(ulong *)(lVar20 + 8) | 0x200000;
      plVar1 = plVar23 + 0x27;
      Hint_Prefetch(plVar1,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
        if (bVar7) {
          *plVar1 = *plVar1 + (ulong)uVar2;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
    }
    uVar10 = 0;
    if (uVar2 != 0x1000) {
      uVar10 = uVar2;
    }
    *(ulong *)(*plVar23 + (uVar25 & 0xffffffff) * 0x28) =
         lVar19 * 0x1000000 | (ulong)(uint)((int)uVar18 << 0xc) | (ulong)uVar10;
    puVar15 = (ulong *)(*plVar23 + uVar25 * 0x28 + 8);
    Hint_Prefetch(puVar15,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar15,0x10);
      if (bVar7) {
        *puVar15 = *puVar15 & 0xffffffffffffdfff;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    lVar20 = *(long *)(lVar12 + 0x10) + -1;
    *(int *)(lVar12 + 0x10) = (int)lVar20;
    if ((lVar20 == 0) || (*(long *)(lVar12 + 0x10) == 0)) {
      preempt_schedule();
    }
    plVar1 = plVar23 + 0x17;
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar7) {
        *plVar1 = *plVar1 + 1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
  }
  uVar21 = uVar21 + 1;
  if (uVar21 == uVar4) goto LAB_00109b38;
  goto LAB_00109c00;
}



//------------------------------------------------------------
// zram_writeback_clear_flag @ 0010a05c size=572
// signature: undefined zram_writeback_clear_flag(void)
// callers: [zram_writeback_done_work, zram_writeback_oem_func, zram_writeback_page]
//------------------------------------------------------------

void zram_writeback_clear_flag(long *param_1,ulong param_2)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  undefined8 uVar4;
  uint uVar5;
  ulong uVar6;
  ulong *puVar7;
  long *plVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  undefined8 *puVar12;
  ulong uVar13;
  
  lVar3 = sp_el0;
  uVar13 = param_2 & 0xffffffff;
  puVar7 = (ulong *)(*param_1 + (param_2 & 0xffffffff) * 0x28 + 8);
  *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
  uVar5 = (uint)*puVar7;
  do {
    if ((uVar5 >> 0xd & 1) == 0) {
      Hint_Prefetch(puVar7,2,0,1);
      do {
        uVar6 = *puVar7;
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(puVar7,0x10);
        if (bVar2) {
          *puVar7 = uVar6 | 0x2000;
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      if (((uint)uVar6 >> 0xd & 1) == 0) {
        lVar9 = uVar13 * 0x28;
        *(ulong *)(*param_1 + lVar9 + 8) = *(ulong *)(*param_1 + lVar9 + 8) & 0xfffffffffffeffff;
        *(ulong *)(*param_1 + lVar9 + 8) = *(ulong *)(*param_1 + lVar9 + 8) & 0xfffffffffffbffff;
        puVar7 = (ulong *)(*param_1 + lVar9 + 8);
        uVar6 = *puVar7;
        if ((uVar6 & 0xdfff) != 0) {
          *puVar7 = uVar6 & 0xffffffffffbfffff;
          uVar4 = _raw_spin_lock_irqsave(param_1 + 0x56);
          lVar9 = *param_1;
          plVar11 = (long *)(lVar9 + uVar13 * 0x28 + 0x18);
          if (((long *)*plVar11 != plVar11) &&
             (uVar6 = __list_del_entry_valid(plVar11), (uVar6 & 1) != 0)) {
            lVar10 = *plVar11;
            plVar8 = *(long **)(lVar9 + uVar13 * 0x28 + 0x20);
            *(long **)(lVar10 + 8) = plVar8;
            *plVar8 = lVar10;
          }
          puVar12 = (undefined8 *)param_1[0x55];
          uVar6 = __list_add_valid(plVar11,puVar12,param_1 + 0x54);
          if ((uVar6 & 1) != 0) {
            param_1[0x55] = (long)plVar11;
            *plVar11 = (long)(param_1 + 0x54);
            *(undefined8 **)(lVar9 + uVar13 * 0x28 + 0x20) = puVar12;
            *puVar12 = plVar11;
          }
          _raw_spin_unlock_irqrestore(param_1 + 0x56,uVar4);
          lVar9 = *param_1 + uVar13 * 0x28;
          *(ulong *)(lVar9 + 8) = *(ulong *)(lVar9 + 8) | 0x800000;
          plVar11 = param_1 + 0x2c;
          Hint_Prefetch(plVar11,2,0,1);
          do {
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(plVar11,0x10);
            if (bVar2) {
              *plVar11 = *plVar11 + 1;
              cVar1 = ExclusiveMonitorsStatus();
            }
          } while (cVar1 != '\0');
        }
        puVar7 = (ulong *)(*param_1 + uVar13 * 0x28 + 8);
        Hint_Prefetch(puVar7,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(puVar7,0x10);
          if (bVar2) {
            *puVar7 = *puVar7 & 0xffffffffffffdfff;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
        lVar9 = *(long *)(lVar3 + 0x10) + -1;
        *(int *)(lVar3 + 0x10) = (int)lVar9;
        if ((lVar9 == 0) || (*(long *)(lVar3 + 0x10) == 0)) {
          preempt_schedule();
        }
        return;
      }
    }
    lVar9 = *(long *)(lVar3 + 0x10) + -1;
    *(int *)(lVar3 + 0x10) = (int)lVar9;
    if ((lVar9 == 0) || (*(long *)(lVar3 + 0x10) == 0)) {
      preempt_schedule();
    }
    do {
      Yield();
    } while (((uint)*puVar7 >> 0xd & 1) != 0);
    *(int *)(lVar3 + 0x10) = *(int *)(lVar3 + 0x10) + 1;
    uVar5 = (uint)*puVar7;
  } while( true );
}



//------------------------------------------------------------
// list_move @ 0010a2b4 size=104
// signature: undefined list_move(void)
// callers: [zram_writeback_oem_func]
//------------------------------------------------------------

void list_move(long *param_1,long *param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  
  uVar2 = __list_del_entry_valid();
  if ((uVar2 & 1) != 0) {
    lVar3 = *param_1;
    plVar1 = (long *)param_1[1];
    *(long **)(lVar3 + 8) = plVar1;
    *plVar1 = lVar3;
  }
  lVar3 = *param_2;
  uVar2 = __list_add_valid(param_1,param_2,lVar3);
  if ((uVar2 & 1) != 0) {
    *(long **)(lVar3 + 8) = param_1;
    *param_1 = lVar3;
    param_1[1] = (long)param_2;
    *param_2 = (long)param_1;
  }
  return;
}



//------------------------------------------------------------
// writeback_store @ 0010a320 size=2608
// signature: undefined writeback_store(void)
// callers: []
//------------------------------------------------------------

void writeback_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  char cVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  ulong uVar14;
  ulong *puVar15;
  long lVar16;
  ulong uVar17;
  long lVar18;
  long *plVar19;
  bool bVar20;
  long *plVar21;
  ulong uVar22;
  long local_138;
  undefined8 uStack_130;
  long local_128;
  undefined8 uStack_120;
  ulong local_118;
  long local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  long local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
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
  long local_70;
  
  lVar11 = sp_el0;
  local_70 = *(long *)(lVar11 + 0x638);
  local_118 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  plVar19 = *(long **)(*(long *)(param_1 + 0x3b0) + 0x58);
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
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  uVar22 = (ulong)plVar19[0x33] >> 0xc;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_128 = 0;
  uStack_120 = 0;
  uVar10 = sysfs_streq(param_3,&DAT_0010d066);
  if ((uVar10 & 1) == 0) {
    uVar10 = sysfs_streq(param_3,&DAT_0010cc1c);
    if ((uVar10 & 1) == 0) {
      uVar10 = sysfs_streq(param_3,"huge_idle");
      if ((uVar10 & 1) == 0) {
        iVar9 = strncmp(param_3,"page_index=",0xb);
        if (iVar9 != 0) {
          lVar11 = -0x16;
          goto LAB_0010ad30;
        }
        iVar9 = kstrtoll(param_3 + 0xb,10,&local_118);
        lVar11 = -0x16;
        if ((iVar9 != 0) || (uVar22 <= local_118)) goto LAB_0010ad30;
        bVar8 = false;
        uVar22 = 1;
        bVar20 = true;
        goto LAB_0010a3f0;
      }
      bVar20 = false;
    }
    else {
      bVar20 = true;
    }
    bVar8 = true;
  }
  else {
    bVar20 = false;
    bVar8 = false;
  }
LAB_0010a3f0:
  down_read(plVar19 + 4);
  if (plVar19[0x33] == 0) {
    lVar11 = -0x16;
  }
  else if (plVar19[0x45] == 0) {
    lVar11 = -0x13;
  }
  else if (bVar20) {
    uVar12 = tpidr_el1;
    lVar11 = __alloc_pages(uVar12,0xcc0,0,0,0);
    if (lVar11 != 0) {
      if (uVar22 != 0) {
        uVar10 = 0;
        plVar1 = plVar19 + 0x46;
        plVar2 = plVar19 + 0x57;
        lVar5 = sp_el0;
LAB_0010a450:
        uStack_130 = 0x1000;
        local_138 = lVar11;
        _raw_spin_lock(plVar1);
        if ((*(char *)((long)plVar19 + 0x234) != '\0') && (plVar19[0x47] == 0)) {
          _raw_spin_unlock(plVar1);
          param_4 = -5;
          if (uVar10 == 0) goto LAB_0010ad18;
          goto LAB_0010ad08;
        }
        _raw_spin_unlock(plVar1);
        if (uVar10 == 0) {
          uVar10 = 1;
          while( true ) {
            uVar10 = _find_next_zero_bit(plVar19[0x49],plVar19[0x52],uVar10);
            if (uVar10 == plVar19[0x52]) {
              uVar10 = 0;
              goto LAB_0010ad00;
            }
            uVar12 = _raw_spin_lock_irqsave(plVar2);
            uVar14 = 1L << (uVar10 & 0x3f);
            puVar15 = (ulong *)(plVar19[0x49] + (uVar10 >> 6 & 0x3ffffff) * 8);
            Hint_Prefetch(puVar15,2,0,1);
            do {
              uVar17 = *puVar15;
              cVar4 = '\x01';
              bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
              if (bVar20) {
                *puVar15 = uVar17 | uVar14;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            DataMemoryBarrier(2,3);
            if ((uVar17 & uVar14) == 0) break;
            _raw_spin_unlock_irqrestore(plVar2,uVar12);
          }
          puVar15 = (ulong *)(plVar19[0x51] + (uVar10 >> 0xc & 0x3ffffff) * 8);
          Hint_Prefetch(puVar15,2,0,1);
          do {
            cVar4 = '\x01';
            bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
            if (bVar20) {
              *puVar15 = *puVar15 | 1L << (uVar10 >> 6 & 0x3f);
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          _raw_spin_unlock_irqrestore(plVar2,uVar12);
          plVar21 = plVar19 + 0x1b;
          Hint_Prefetch(plVar21,2,0,1);
          do {
            cVar4 = '\x01';
            bVar20 = (bool)ExclusiveMonitorPass(plVar21,0x10);
            if (bVar20) {
              *plVar21 = *plVar21 + 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          if (uVar10 == 0) {
LAB_0010ad00:
            param_4 = -0x1c;
            goto LAB_0010ad04;
          }
        }
        plVar21 = (long *)(lVar5 + 0x10);
        puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
        *(int *)plVar21 = *(int *)plVar21 + 1;
        uVar13 = (uint)*puVar15;
        do {
          if ((uVar13 >> 0xd & 1) == 0) {
            Hint_Prefetch(puVar15,2,0,1);
            do {
              uVar14 = *puVar15;
              cVar4 = '\x01';
              bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
              if (bVar20) {
                *puVar15 = uVar14 | 0x2000;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            if (((uint)uVar14 >> 0xd & 1) == 0) goto LAB_0010a5d4;
          }
          lVar16 = *plVar21;
          *(int *)plVar21 = (int)(lVar16 + -1);
          if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
            preempt_schedule();
          }
          do {
            Yield();
          } while (((uint)*puVar15 >> 0xd & 1) != 0);
          *(int *)plVar21 = *(int *)plVar21 + 1;
          uVar13 = (uint)*puVar15;
        } while( true );
      }
      goto LAB_0010ad18;
    }
    lVar11 = -0xc;
  }
  else {
    uVar22 = zram_wb_available(plVar19);
    lVar11 = param_4;
    if ((uVar22 & 1) != 0) {
      uVar22 = plVar19[0x33];
      local_138 = 0;
      if (0xfff < uVar22) {
        uVar10 = 0;
        do {
          uVar14 = zram_wb_available(plVar19);
          if (((uVar14 & 1) == 0) ||
             (iVar9 = zram_writeback_index(plVar19,uVar10 & 0xffffffff,&local_138,0), iVar9 != 0))
          break;
          bVar8 = (uVar22 >> 0xc) - 1 != uVar10;
          uVar10 = uVar10 + 1;
        } while (bVar8);
        lVar5 = local_138;
        if (local_138 != 0) {
          if (0x3f < *(uint *)(local_138 + 0x200)) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10adc4);
            (*pcVar7)();
          }
          lVar16 = *(long *)(local_138 + (ulong)*(uint *)(local_138 + 0x200) * 8);
          lVar18 = (long)*(int *)(lVar16 + 0x20c);
          if (lVar18 + 8U < 0x1000) {
            uVar22 = *(ulong *)(lVar16 + 0x200);
            lVar6 = sp_el0;
            *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
            *(int *)(lVar6 + 0xb68) = *(int *)(lVar6 + 0xb68) + 1;
            *(undefined8 *)(((uVar22 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) + lVar18) =
                 0xffffffff;
            *(int *)(lVar6 + 0xb68) = *(int *)(lVar6 + 0xb68) + -1;
            lVar16 = *(long *)(lVar6 + 0x10) + -1;
            *(int *)(lVar6 + 0x10) = (int)lVar16;
            if ((lVar16 == 0) || (*(long *)(lVar6 + 0x10) == 0)) {
              preempt_schedule();
            }
          }
          zram_writeback_page(plVar19,lVar5,0);
        }
      }
    }
  }
  goto LAB_0010ad24;
LAB_0010a5d4:
  if ((*(ushort *)(*plVar19 + (local_118 & 0xffffffff) * 0x28 + 8) & 0xdfff) != 0) {
    puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
    uVar14 = *puVar15;
    if ((uVar14 & 0x1c000) == 0) {
      bVar20 = false;
      if ((uVar14 & 0x20000) == 0) {
        bVar20 = bVar8;
      }
      if (!bVar20) {
        *puVar15 = uVar14 | 0x10000;
        lVar16 = *plVar19 + local_118 * 0x28;
        *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) | 0x40000;
        puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
        Hint_Prefetch(puVar15,2,0,1);
        do {
          cVar4 = '\x01';
          bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
          if (bVar20) {
            *puVar15 = *puVar15 & 0xffffffffffffdfff;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        lVar16 = *plVar21;
        *(int *)plVar21 = (int)(lVar16 + -1);
        if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
          preempt_schedule();
        }
        iVar9 = zram_bvec_read(plVar19,&local_138,local_118 & 0xffffffff,0);
        if (iVar9 != 0) {
          puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
          *(int *)plVar21 = *(int *)plVar21 + 1;
          do {
            if (((uint)*puVar15 >> 0xd & 1) == 0) {
              Hint_Prefetch(puVar15,2,0,1);
              do {
                uVar14 = *puVar15;
                cVar4 = '\x01';
                bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
                if (bVar20) {
                  *puVar15 = uVar14 | 0x2000;
                  cVar4 = ExclusiveMonitorsStatus();
                }
              } while (cVar4 != '\0');
              if (((uint)uVar14 >> 0xd & 1) == 0) goto LAB_0010a718;
            }
            lVar16 = *plVar21;
            *(int *)plVar21 = (int)(lVar16 + -1);
            if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
              preempt_schedule();
            }
            do {
              Yield();
            } while (((uint)*puVar15 >> 0xd & 1) != 0);
            *(int *)plVar21 = *(int *)plVar21 + 1;
          } while( true );
        }
        bio_init(&local_110,plVar19[0x48],&local_128,1,0x801);
        local_f0 = uVar10 << 3;
        bio_add_page(&local_110,lVar11,0x1000,0);
        iVar9 = submit_bio_wait(&local_110);
        if (iVar9 != 0) {
          puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
          *(int *)plVar21 = *(int *)plVar21 + 1;
          do {
            if (((uint)*puVar15 >> 0xd & 1) == 0) {
              Hint_Prefetch(puVar15,2,0,1);
              do {
                uVar14 = *puVar15;
                cVar4 = '\x01';
                bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
                if (bVar20) {
                  *puVar15 = uVar14 | 0x2000;
                  cVar4 = ExclusiveMonitorsStatus();
                }
              } while (cVar4 != '\0');
              if (((uint)uVar14 >> 0xd & 1) == 0) goto LAB_0010a894;
            }
            lVar16 = *plVar21;
            *(int *)plVar21 = (int)(lVar16 + -1);
            if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
              preempt_schedule();
            }
            do {
              Yield();
            } while (((uint)*puVar15 >> 0xd & 1) != 0);
            *(int *)plVar21 = *(int *)plVar21 + 1;
          } while( true );
        }
        plVar3 = plVar19 + 0x1d;
        Hint_Prefetch(plVar3,2,0,1);
        do {
          cVar4 = '\x01';
          bVar20 = (bool)ExclusiveMonitorPass(plVar3,0x10);
          if (bVar20) {
            *plVar3 = *plVar3 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
        *(int *)plVar21 = *(int *)plVar21 + 1;
        uVar13 = (uint)*puVar15;
        do {
          if ((uVar13 >> 0xd & 1) == 0) {
            Hint_Prefetch(puVar15,2,0,1);
            do {
              uVar14 = *puVar15;
              cVar4 = '\x01';
              bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
              if (bVar20) {
                *puVar15 = uVar14 | 0x2000;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            if (((uint)uVar14 >> 0xd & 1) == 0) goto LAB_0010a9b4;
          }
          lVar16 = *plVar21;
          *(int *)plVar21 = (int)(lVar16 + -1);
          if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
            preempt_schedule();
          }
          do {
            Yield();
          } while (((uint)*puVar15 >> 0xd & 1) != 0);
          *(int *)plVar21 = *(int *)plVar21 + 1;
          uVar13 = (uint)*puVar15;
        } while( true );
      }
    }
  }
LAB_0010a770:
  puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
  Hint_Prefetch(puVar15,2,0,1);
  do {
    cVar4 = '\x01';
    bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
    if (bVar20) {
      *puVar15 = *puVar15 & 0xffffffffffffdfff;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
LAB_0010a788:
  lVar16 = *plVar21;
  *(int *)plVar21 = (int)(lVar16 + -1);
  if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
    preempt_schedule();
  }
LAB_0010a7a0:
  uVar22 = uVar22 - 1;
  local_118 = local_118 + 1;
  if (uVar22 == 0) goto LAB_0010ad04;
  goto LAB_0010a450;
LAB_0010a718:
  lVar16 = *plVar19 + local_118 * 0x28;
  *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) & 0xfffffffffffeffff;
  lVar16 = *plVar19 + local_118 * 0x28;
  *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) & 0xfffffffffffbffff;
  puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
  Hint_Prefetch(puVar15,2,0,1);
  do {
    cVar4 = '\x01';
    bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
    if (bVar20) {
      *puVar15 = *puVar15 & 0xffffffffffffdfff;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  goto LAB_0010a788;
LAB_0010a894:
  lVar16 = *plVar19 + local_118 * 0x28;
  *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) & 0xfffffffffffeffff;
  lVar16 = *plVar19 + local_118 * 0x28;
  *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) & 0xfffffffffffbffff;
  puVar15 = (ulong *)(*plVar19 + local_118 * 0x28 + 8);
  Hint_Prefetch(puVar15,2,0,1);
  do {
    cVar4 = '\x01';
    bVar20 = (bool)ExclusiveMonitorPass(puVar15,0x10);
    if (bVar20) {
      *puVar15 = *puVar15 & 0xffffffffffffdfff;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  lVar16 = *plVar21;
  *(int *)plVar21 = (int)(lVar16 + -1);
  if ((lVar16 + -1 == 0) || (*plVar21 == 0)) {
    preempt_schedule();
  }
  param_4 = (long)iVar9;
  goto LAB_0010a7a0;
LAB_0010a9b4:
  lVar16 = *plVar19;
  uVar14 = *(ulong *)(lVar16 + local_118 * 0x28 + 8);
  if ((*(ushort *)(lVar16 + (local_118 & 0xffffffff) * 0x28 + 8) & 0xdfff) == 0 ||
      (uVar14 & 0x40000) == 0) {
    *(ulong *)(lVar16 + local_118 * 0x28 + 8) = uVar14 & 0xfffffffffffeffff;
    lVar16 = *plVar19 + local_118 * 0x28;
    *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) & 0xfffffffffffbffff;
  }
  else {
    zram_free_page(plVar19);
    lVar16 = *plVar19 + local_118 * 0x28;
    *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) & 0xfffffffffffeffff;
    lVar16 = *plVar19 + local_118 * 0x28;
    *(ulong *)(lVar16 + 8) = *(ulong *)(lVar16 + 8) | 0x8000;
    *(ulong *)(*plVar19 + (local_118 & 0xffffffff) * 0x28) = uVar10 << 0x18;
    plVar3 = plVar19 + 0x17;
    Hint_Prefetch(plVar3,2,0,1);
    do {
      cVar4 = '\x01';
      bVar20 = (bool)ExclusiveMonitorPass(plVar3,0x10);
      if (bVar20) {
        *plVar3 = *plVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    plVar3 = plVar19 + 0x1f;
    Hint_Prefetch(plVar3,2,0,1);
    do {
      cVar4 = '\x01';
      bVar20 = (bool)ExclusiveMonitorPass(plVar3,0x10);
      if (bVar20) {
        *plVar3 = *plVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    _raw_spin_lock(plVar1);
    if ((*(char *)((long)plVar19 + 0x234) != '\0') && (plVar19[0x47] != 0)) {
      plVar19[0x47] = plVar19[0x47] + -1;
    }
    _raw_spin_unlock(plVar1);
    uVar10 = 0;
  }
  goto LAB_0010a770;
LAB_0010ad04:
  if (uVar10 != 0) {
LAB_0010ad08:
    free_block_bdev(plVar19,uVar10,0);
  }
LAB_0010ad18:
  __free_pages(lVar11,0);
  lVar11 = param_4;
LAB_0010ad24:
  up_read(plVar19 + 4);
LAB_0010ad30:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar11);
  }
  return;
}



//------------------------------------------------------------
// writeback_limit_show @ 0010adc8 size=124
// signature: undefined writeback_limit_show(void)
// callers: []
//------------------------------------------------------------

long writeback_limit_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar2 + 0x20);
  _raw_spin_lock(lVar2 + 0x230);
  uVar3 = *(undefined8 *)(lVar2 + 0x238);
  _raw_spin_unlock(lVar2 + 0x230);
  up_read(lVar2 + 0x20);
  iVar1 = scnprintf(param_3,0x1000,"%llu\n",uVar3);
  return (long)iVar1;
}



//------------------------------------------------------------
// writeback_limit_store @ 0010ae48 size=184
// signature: undefined writeback_limit_store(void)
// callers: []
//------------------------------------------------------------

undefined8
writeback_limit_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 == 0) {
    down_read(lVar2 + 0x20);
    _raw_spin_lock(lVar2 + 0x230);
    *(undefined8 *)(lVar2 + 0x238) = local_40;
    _raw_spin_unlock(lVar2 + 0x230);
    up_read(lVar2 + 0x20);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// writeback_limit_enable_show @ 0010af04 size=124
// signature: undefined writeback_limit_enable_show(void)
// callers: []
//------------------------------------------------------------

long writeback_limit_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar3 + 0x20);
  _raw_spin_lock(lVar3 + 0x230);
  uVar1 = *(undefined1 *)(lVar3 + 0x234);
  _raw_spin_unlock(lVar3 + 0x230);
  up_read(lVar3 + 0x20);
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010c82e,uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// writeback_limit_enable_store @ 0010af84 size=192
// signature: undefined writeback_limit_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
writeback_limit_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 == 0) {
    down_read(lVar2 + 0x20);
    _raw_spin_lock(lVar2 + 0x230);
    *(bool *)(lVar2 + 0x234) = local_40 != 0;
    _raw_spin_unlock(lVar2 + 0x230);
    up_read(lVar2 + 0x20);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// writeback_pid_show @ 0010b048 size=60
// signature: undefined writeback_pid_show(void)
// callers: []
//------------------------------------------------------------

long writeback_pid_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",
                  (ulong)*(uint *)(*(long *)(*(long *)(param_1 + 0x3b0) + 0x58) + 0x338));
  return (long)iVar1;
}



//------------------------------------------------------------
// writeback_pid_store @ 0010b088 size=520
// signature: undefined writeback_pid_store(void)
// callers: []
//------------------------------------------------------------

long writeback_pid_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  int local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_4c = 0;
  lVar8 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  iVar5 = kstrtoint(param_3,10,&local_4c);
  if (iVar5 < 0) {
    param_4 = (long)iVar5;
    goto LAB_0010b264;
  }
  if (local_4c == 0) {
    *(undefined4 *)(lVar8 + 0x33c) = 1;
    _printk(&DAT_0010cf47,*(undefined4 *)(lVar8 + 0x338));
    goto LAB_0010b264;
  }
  iVar5 = mutex_trylock(lVar8 + 0x308);
  if (iVar5 == 0) {
    _printk(&DAT_0010c915,*(undefined4 *)(lVar8 + 0x338));
    param_4 = -0x10;
    goto LAB_0010b264;
  }
  *(undefined4 *)(lVar8 + 0x33c) = 0;
  *(int *)(lVar8 + 0x338) = local_4c;
  __rcu_read_lock();
  lVar6 = find_vpid(local_4c);
  if ((lVar6 == 0) || (lVar6 = pid_task(lVar6,0), lVar6 == 0)) {
    __rcu_read_unlock();
    _printk(&DAT_0010c952,local_4c);
    iVar5 = -3;
  }
  else {
    puVar1 = (uint *)(lVar6 + 0x40);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar2 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar2 == 0) {
      uVar7 = 2;
LAB_0010b210:
      refcount_warn_saturate(puVar1,uVar7);
    }
    else if ((int)(uVar2 + 1 | uVar2) < 0) {
      uVar7 = 1;
      goto LAB_0010b210;
    }
    __rcu_read_unlock();
    if (*(int *)(lVar8 + 0x33c) == 0) {
      iVar5 = zram_perform_task_eswapout(lVar8,lVar6);
    }
    else {
      _printk(&DAT_0010cf47,local_4c);
      iVar5 = -0x7d;
    }
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar2 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar2 - 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar2 == 1) {
      DataMemoryBarrier(2,1);
      __put_task_struct(lVar6);
    }
    else if ((int)uVar2 < 1) {
      refcount_warn_saturate(puVar1,3);
    }
  }
  *(undefined4 *)(lVar8 + 0x338) = 0;
  mutex_unlock(lVar8 + 0x308);
  lVar8 = (long)iVar5;
  if (-1 < iVar5 || iVar5 == -0x7d) {
    lVar8 = param_4;
  }
  param_4 = lVar8;
LAB_0010b264:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// am_app_launch_show @ 0010b2b0 size=52
// signature: undefined am_app_launch_show(void)
// callers: []
//------------------------------------------------------------

long am_app_launch_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",(ulong)am_app_launch);
  return (long)iVar1;
}



//------------------------------------------------------------
// am_app_launch_store @ 0010b2e8 size=184
// signature: undefined am_app_launch_store(void)
// callers: []
//------------------------------------------------------------

undefined8
am_app_launch_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar5 = kstrtoint(param_3,10,&local_2c);
  if ((iVar5 < 0) || (1 < local_2c)) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    Hint_Prefetch(0x10c3b0,2,0,1);
    do {
      uVar4 = am_app_launch;
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(0x10c3b0,0x10);
      if (bVar2) {
        am_app_launch = local_2c;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    DataMemoryBarrier(2,3);
    if (uVar4 != local_2c) {
      is_app_launch = local_2c != 0;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// prefetch_pid_show @ 0010b3a4 size=60
// signature: undefined prefetch_pid_show(void)
// callers: []
//------------------------------------------------------------

long prefetch_pid_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = sysfs_emit(param_3,&DAT_0010c82e,
                     *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x3b0) + 0x58) + 0x370));
  return (long)iVar1;
}



//------------------------------------------------------------
// prefetch_pid_store @ 0010b3e4 size=424
// signature: undefined prefetch_pid_store(void)
// callers: []
//------------------------------------------------------------

void prefetch_pid_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  undefined4 local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_4c = 0;
  lVar8 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  iVar5 = kstrtoint(param_3,10,&local_4c);
  if (iVar5 < 0) {
    lVar8 = (long)iVar5;
    goto LAB_0010b564;
  }
  iVar5 = mutex_trylock(lVar8 + 0x340);
  if (iVar5 == 0) {
    _printk(&DAT_0010cc45,*(undefined4 *)(lVar8 + 0x370));
    lVar8 = -0x10;
    goto LAB_0010b564;
  }
  *(undefined4 *)(lVar8 + 0x370) = local_4c;
  __rcu_read_lock();
  lVar6 = find_task_by_vpid(local_4c);
  if (lVar6 == 0) {
    __rcu_read_unlock();
    _printk(&DAT_0010c952,local_4c);
    iVar5 = -3;
  }
  else {
    puVar1 = (uint *)(lVar6 + 0x40);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar2 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar2 == 0) {
      uVar7 = 2;
LAB_0010b518:
      refcount_warn_saturate(puVar1,uVar7);
    }
    else if ((int)(uVar2 + 1 | uVar2) < 0) {
      uVar7 = 1;
      goto LAB_0010b518;
    }
    __rcu_read_unlock();
    iVar5 = zram_perform_task_prefetch(lVar8,lVar6);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar2 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar2 - 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar2 == 1) {
      DataMemoryBarrier(2,1);
      __put_task_struct(lVar6);
    }
    else if ((int)uVar2 < 1) {
      refcount_warn_saturate(puVar1,3);
    }
  }
  *(undefined4 *)(lVar8 + 0x370) = 0;
  mutex_unlock(lVar8 + 0x340);
  lVar8 = (long)iVar5;
  if (-1 < iVar5) {
    lVar8 = param_4;
  }
LAB_0010b564:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar8);
  }
  return;
}



//------------------------------------------------------------
// io_stat_show @ 0010b5ac size=116
// signature: undefined io_stat_show(void)
// callers: []
//------------------------------------------------------------

long io_stat_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar2 + 0x20);
  iVar1 = scnprintf(param_3,0x1000,"%8llu %8llu %8llu %8llu\n",*(undefined8 *)(lVar2 + 0x80),
                    *(undefined8 *)(lVar2 + 0x88),*(undefined8 *)(lVar2 + 0x90),
                    *(undefined8 *)(lVar2 + 0x98));
  up_read(lVar2 + 0x20);
  return (long)iVar1;
}



//------------------------------------------------------------
// mm_stat_show @ 0010b624 size=244
// signature: undefined mm_stat_show(void)
// callers: []
//------------------------------------------------------------

long mm_stat_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar3 + 0x20);
  if (*(long *)(lVar3 + 0x198) == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = zs_get_total_pages(*(undefined8 *)(lVar3 + 8));
    zs_pool_stats(*(undefined8 *)(lVar3 + 8),&local_40);
    lVar2 = lVar2 << 0xc;
  }
  iVar1 = scnprintf(param_3,0x1000,"%8llu %8llu %8llu %8lu %8ld %8llu %8lu %8llu %8llu\n",
                    *(long *)(lVar3 + 0xb8) << 0xc,*(undefined8 *)(lVar3 + 0x68),lVar2,
                    *(long *)(lVar3 + 0x60) << 0xc,*(long *)(lVar3 + 0xc0) << 0xc,
                    *(undefined8 *)(lVar3 + 0xa0),local_40,*(undefined8 *)(lVar3 + 0xa8),
                    *(undefined8 *)(lVar3 + 0xb0));
  up_read(lVar3 + 0x20);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// bd_stat_show @ 0010b71c size=216
// signature: undefined bd_stat_show(void)
// callers: []
//------------------------------------------------------------

long bd_stat_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar2 + 0x20);
  iVar1 = scnprintf(param_3,0x1000,
                    "%8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu %8llu\n"
                    ,*(undefined8 *)(lVar2 + 0xf0),*(undefined8 *)(lVar2 + 0xd8),
                    *(undefined8 *)(lVar2 + 0xe0),*(undefined8 *)(lVar2 + 0xe8),
                    *(undefined8 *)(lVar2 + 0xf8),*(long *)(lVar2 + 0x100) >> 0xc,
                    *(undefined8 *)(lVar2 + 0x108),*(long *)(lVar2 + 0x110) >> 0xc,
                    *(undefined8 *)(lVar2 + 0x118),*(undefined8 *)(lVar2 + 0x120),
                    *(undefined8 *)(lVar2 + 0x128),*(undefined8 *)(lVar2 + 0x130),
                    *(long *)(lVar2 + 0x138) >> 0xc,*(undefined8 *)(lVar2 + 0x140),
                    *(long *)(lVar2 + 0x148) >> 0xc,*(undefined8 *)(lVar2 + 0x150),
                    *(undefined8 *)(lVar2 + 0x158));
  up_read(lVar2 + 0x20);
  return (long)iVar1;
}



//------------------------------------------------------------
// bd_stat_store @ 0010b7f8 size=32
// signature: undefined bd_stat_store(void)
// callers: []
//------------------------------------------------------------

undefined8 bd_stat_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  *(undefined8 *)(lVar1 + 0x108) = 0;
  *(undefined8 *)(lVar1 + 0x110) = 0;
  *(undefined8 *)(lVar1 + 0x140) = 0;
  *(undefined8 *)(lVar1 + 0x148) = 0;
  return param_4;
}



//------------------------------------------------------------
// wb_duration_stats_show @ 0010b81c size=96
// signature: undefined wb_duration_stats_show(void)
// callers: []
//------------------------------------------------------------

long wb_duration_stats_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  iVar1 = scnprintf(param_3,0x1000,"%llu %llu %llu %llu %llu %llu\n",*(undefined8 *)(lVar2 + 0x168),
                    *(undefined8 *)(lVar2 + 0x170),*(undefined8 *)(lVar2 + 0x178),
                    *(undefined8 *)(lVar2 + 0x180),*(undefined8 *)(lVar2 + 0x188),
                    *(undefined8 *)(lVar2 + 400));
  return (long)iVar1;
}



//------------------------------------------------------------
// wb_duration_stats_store @ 0010b880 size=40
// signature: undefined wb_duration_stats_store(void)
// callers: []
//------------------------------------------------------------

undefined8
wb_duration_stats_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  *(undefined8 *)(lVar1 + 0x168) = 0;
  *(undefined8 *)(lVar1 + 0x170) = 0;
  *(undefined8 *)(lVar1 + 0x178) = 0;
  *(undefined8 *)(lVar1 + 0x180) = 0;
  *(undefined8 *)(lVar1 + 0x188) = 0;
  *(undefined8 *)(lVar1 + 400) = 0;
  return param_4;
}



//------------------------------------------------------------
// debug_stat_show @ 0010b8ac size=112
// signature: undefined debug_stat_show(void)
// callers: []
//------------------------------------------------------------

long debug_stat_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x58);
  down_read(lVar2 + 0x20);
  iVar1 = scnprintf(param_3,0x1000,"version: %d\n%8llu %8llu\n",1,*(undefined8 *)(lVar2 + 200),
                    *(undefined8 *)(lVar2 + 0xd0));
  up_read(lVar2 + 0x20);
  return (long)iVar1;
}



//------------------------------------------------------------
// read_block_state @ 0010b920 size=1008
// signature: undefined read_block_state(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong read_block_state(long param_1,ulong param_2,ulong param_3,ulong *param_4)

{
  long *plVar1;
  ulong *puVar2;
  char cVar3;
  long lVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  long lVar11;
  undefined8 *puVar12;
  uchar param6;
  uchar param7;
  uchar param8;
  uchar param9;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  long *plVar16;
  undefined1 auVar17 [16];
  
  plVar16 = *(long **)(param_1 + 0xd8);
  uVar13 = plVar16[0x33];
  lVar8 = kvmalloc_node(param_3,0xcc0,0xffffffff);
  if (lVar8 == 0) {
    return 0xfffffffffffffff4;
  }
  plVar1 = plVar16 + 4;
  down_read(plVar1);
  if (plVar16[0x33] == 0) {
    up_read(plVar1);
    uVar14 = 0xffffffffffffffea;
    goto LAB_0010bcb0;
  }
  uVar15 = *param_4;
  if (uVar15 < uVar13 >> 0xc) {
    uVar14 = 0;
    lVar4 = sp_el0;
LAB_0010b9b0:
    puVar2 = (ulong *)(*plVar16 + uVar15 * 0x28 + 8);
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    uVar9 = (uint)*puVar2;
    do {
      if ((uVar9 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar2,2,0,1);
        do {
          uVar10 = *puVar2;
          cVar3 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar6) {
            *puVar2 = uVar10 | 0x2000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (((uint)uVar10 >> 0xd & 1) == 0) goto LAB_0010ba3c;
      }
      lVar11 = *(long *)(lVar4 + 0x10) + -1;
      *(int *)(lVar4 + 0x10) = (int)lVar11;
      if ((lVar11 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
        preempt_schedule();
      }
      do {
        Yield();
      } while (((uint)*puVar2 >> 0xd & 1) != 0);
      *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
      uVar9 = (uint)*puVar2;
    } while( true );
  }
  uVar14 = 0;
LAB_0010bbb8:
  up_read(plVar1);
  if (uVar14 >> 0x1f != 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10bce8);
    (*pcVar5)();
  }
  __check_object_size(lVar8,uVar14,1);
  puVar12 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
     (uVar13 = param_2, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
    uVar13 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar15 = uVar14;
  if (uVar13 <= 0x8000000000 - uVar14) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar13 = daif;
      if ((uVar13 & 0x80) == 0) {
        uVar15 = daif;
        daif = uVar15 | 0xc0;
      }
      puVar12 = (undefined8 *)puVar12[1];
      uVar15 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar12;
      InstructionSynchronizationBarrier();
      daif = uVar13;
    }
    uVar15 = __arch_copy_to_user(puVar12,param_2 & 0xff7fffffffffffff,lVar8,uVar14);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar13 = daif;
      if ((uVar13 & 0x80) == 0) {
        uVar10 = daif;
        daif = uVar10 | 0xc0;
      }
      uVar10 = ttbr1_el1;
      ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar10 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar13;
    }
  }
  if (uVar15 != 0) {
    uVar14 = 0xfffffffffffffff2;
  }
LAB_0010bcb0:
  kvfree(lVar8);
  return uVar14;
LAB_0010ba3c:
  lVar11 = *plVar16;
  if ((*(ushort *)(lVar11 + (uVar15 & 0xffffffff) * 0x28 + 8) & 0xdfff) == 0) {
LAB_0010bb00:
    puVar2 = (ulong *)(lVar11 + uVar15 * 0x28 + 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar6) {
        *puVar2 = *puVar2 & 0xffffffffffffdfff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar11 = *(long *)(lVar4 + 0x10) + -1;
    *(int *)(lVar4 + 0x10) = (int)lVar11;
    if ((lVar11 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
      preempt_schedule();
    }
    uVar15 = uVar15 + 1;
    *param_4 = *param_4 + 1;
    if (uVar15 == uVar13 >> 0xc) goto LAB_0010bbb8;
    goto LAB_0010b9b0;
  }
  auVar17 = ns_to_timespec64(*(undefined8 *)(lVar11 + uVar15 * 0x28 + 0x10));
  uVar10 = *(ulong *)(*plVar16 + uVar15 * 0x28 + 8);
  param6 = '.';
  if ((uVar10 & 0x4000) != 0) {
    param6 = 's';
  }
  param7 = '.';
  if ((uVar10 & 0x8000) != 0) {
    param7 = 'w';
  }
  param8 = '.';
  if ((uVar10 & 0x20000) != 0) {
    param8 = 'h';
  }
  param9 = '.';
  if ((uVar10 & 0x40000) != 0) {
    param9 = 'i';
  }
  iVar7 = snprintf((char *)(lVar8 + uVar14),param_3,"%12zd %12lld.%06lu %c%c%c%c\n",uVar15,
                   auVar17._0_8_,auVar17._8_8_ / 1000,param6,param7,param8,param9);
  uVar10 = (ulong)iVar7;
  lVar11 = *plVar16;
  bVar6 = uVar10 <= param_3;
  param_3 = param_3 - uVar10;
  if (bVar6 && param_3 != 0) {
    uVar14 = uVar14 + uVar10;
    goto LAB_0010bb00;
  }
  puVar2 = (ulong *)(lVar11 + uVar15 * 0x28 + 8);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar6) {
      *puVar2 = *puVar2 & 0xffffffffffffdfff;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  lVar11 = *(long *)(lVar4 + 0x10) + -1;
  *(int *)(lVar4 + 0x10) = (int)lVar11;
  if ((lVar11 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
    preempt_schedule();
  }
  goto LAB_0010bbb8;
}



//------------------------------------------------------------
// zram_remove_cb @ 0010bd44 size=44
// signature: undefined zram_remove_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 zram_remove_cb(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = zram_remove(param_2);
  if (iVar2 != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10bd70);
    (*pcVar1)();
  }
  return 0;
}



//------------------------------------------------------------
// zcomp_available_algorithm @ 0010bdfc size=44
// signature: undefined zcomp_available_algorithm(void)
// callers: [comp_algorithm_store]
//------------------------------------------------------------

bool zcomp_available_algorithm(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = crypto_has_alg(param_1,2,0xf);
  return iVar1 == 1;
}



//------------------------------------------------------------
// zcomp_available_show @ 0010be2c size=416
// signature: undefined zcomp_available_show(void)
// callers: [comp_algorithm_show]
//------------------------------------------------------------

long zcomp_available_show(char *param_1,long param_2)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  iVar2 = strcmp(param_1,"lzo");
  pcVar1 = "[%s] ";
  if (iVar2 != 0) {
    pcVar1 = "%s ";
  }
  iVar3 = scnprintf(param_2,0xffe,pcVar1,&DAT_0010cde2);
  lVar8 = (long)iVar3;
  iVar3 = strcmp(param_1,"lzo-rle");
  pcVar1 = "[%s] ";
  if (iVar3 != 0) {
    pcVar1 = "%s ";
  }
  iVar4 = scnprintf(param_2 + lVar8,0xffe - lVar8,pcVar1,"lzo-rle");
  lVar8 = lVar8 + iVar4;
  iVar4 = strcmp(param_1,"lz4");
  pcVar1 = "[%s] ";
  if (iVar4 != 0) {
    pcVar1 = "%s ";
  }
  iVar5 = scnprintf(param_2 + lVar8,0xffe - lVar8,pcVar1,&DAT_0010d079);
  lVar8 = lVar8 + iVar5;
  iVar5 = strcmp(param_1,"zstd");
  lVar7 = 0xffe - lVar8;
  lVar6 = param_2 + lVar8;
  if (iVar5 == 0) {
    param_1 = "zstd";
  }
  else {
    iVar5 = scnprintf(lVar6,lVar7,&DAT_0010cbed,&DAT_0010c5ff);
    lVar8 = lVar8 + iVar5;
    if ((((iVar4 == 0) || (iVar3 == 0)) || (iVar2 == 0)) ||
       (iVar2 = crypto_has_alg(param_1,2,0xf), iVar2 != 1)) goto LAB_0010bf90;
    lVar6 = param_2 + lVar8;
    lVar7 = 0xffe - lVar8;
  }
  iVar2 = scnprintf(lVar6,lVar7,"[%s] ",param_1);
  lVar8 = lVar8 + iVar2;
LAB_0010bf90:
  iVar2 = scnprintf(param_2 + lVar8,0x1000 - lVar8,&DAT_0010ce41);
  return lVar8 + iVar2;
}



//------------------------------------------------------------
// zcomp_stream_get @ 0010bfd0 size=32
// signature: undefined zcomp_stream_get(void)
// callers: [zram_bvec_read, zram_bvec_rw, zram_handle_comp_page]
//------------------------------------------------------------

long zcomp_stream_get(long *param_1)

{
  long lVar1;
  
  lVar1 = sp_el0;
  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
  lVar1 = tpidr_el1;
  return lVar1 + *param_1;
}



//------------------------------------------------------------
// zcomp_stream_put @ 0010bff4 size=64
// signature: undefined zcomp_stream_put(void)
// callers: [zram_bvec_read, zram_bvec_rw, zram_handle_comp_page]
//------------------------------------------------------------

void zcomp_stream_put(void)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = tpidr_el1;
  lVar2 = sp_el0;
  lVar1 = *(long *)(lVar2 + 0x10) + -1;
  *(int *)(lVar2 + 0x10) = (int)lVar1;
  if ((lVar1 == 0) || (*(long *)(lVar2 + 0x10) == 0)) {
    preempt_schedule();
  }
  return;
}



//------------------------------------------------------------
// zcomp_compress @ 0010c038 size=52
// signature: undefined zcomp_compress(void)
// callers: [zram_bvec_rw]
//------------------------------------------------------------

void zcomp_compress(undefined8 *param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_3 = 0x2000;
  crypto_comp_compress(param_1[1],param_2,0x1000,*param_1,param_3);
  return;
}



//------------------------------------------------------------
// zcomp_decompress @ 0010c070 size=88
// signature: undefined zcomp_decompress(void)
// callers: [zram_bvec_read, zram_handle_comp_page]
//------------------------------------------------------------

void zcomp_decompress(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = sp_el0;
  lVar2 = *(long *)(lVar1 + 0x638);
  crypto_comp_decompress(*(undefined8 *)(param_1 + 8));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// zcomp_cpu_up_prepare @ 0010c0cc size=264
// signature: undefined zcomp_cpu_up_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 zcomp_cpu_up_prepare(uint param_1,long param_2)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10c1d4);
    (*pcVar2)();
  }
  plVar1 = (long *)(*(long *)(&__per_cpu_offset + (ulong)param_1 * 8) + *(long *)(param_2 + -0x10));
  lVar3 = crypto_alloc_base(*(undefined8 *)(param_2 + -8),2,0xf);
  plVar1[1] = lVar3;
  lVar3 = __get_free_pages(0xdc0,1);
  uVar4 = plVar1[1];
  *plVar1 = lVar3;
  if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
    if (lVar3 != 0) {
      lVar3 = __get_free_pages(0xdc0,1);
      plVar1[2] = lVar3;
      if (lVar3 != 0) {
        return 0;
      }
      uVar4 = plVar1[1];
      if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
        crypto_destroy_tfm(uVar4,uVar4);
      }
      free_pages(*plVar1,1);
      *plVar1 = 0;
      plVar1[1] = 0;
      lVar3 = plVar1[2];
      goto joined_r0x0010c174;
    }
    crypto_destroy_tfm(uVar4);
    lVar3 = *plVar1;
  }
  free_pages(lVar3,1);
  *plVar1 = 0;
  plVar1[1] = 0;
  lVar3 = plVar1[2];
joined_r0x0010c174:
  if (lVar3 != 0) {
    free_pages(lVar3,1);
    plVar1[2] = 0;
  }
  _printk(&DAT_0010c6a2);
  return 0xfffffff4;
}



//------------------------------------------------------------
// zcomp_cpu_dead @ 0010c1d8 size=128
// signature: undefined zcomp_cpu_dead(void)
// callers: []
//------------------------------------------------------------

undefined8 zcomp_cpu_dead(uint param_1,long param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  ulong uVar3;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10c258);
    (*pcVar2)();
  }
  puVar1 = (undefined8 *)
           (*(long *)(&__per_cpu_offset + (ulong)param_1 * 8) + *(long *)(param_2 + -0x10));
  uVar3 = puVar1[1];
  if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
    crypto_destroy_tfm(uVar3,uVar3);
  }
  free_pages(*puVar1,1);
  *puVar1 = 0;
  puVar1[1] = 0;
  if (puVar1[2] != 0) {
    free_pages(puVar1[2],1);
    puVar1[2] = 0;
  }
  return 0;
}



//------------------------------------------------------------
// zcomp_destroy @ 0010c25c size=68
// signature: undefined zcomp_destroy(void)
// callers: [zram_reset_device]
//------------------------------------------------------------

void zcomp_destroy(undefined8 *param_1)

{
  __cpuhp_state_remove_instance(0x44,param_1 + 2,1);
  free_percpu(*param_1);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// zcomp_create @ 0010c2a4 size=184
// signature: undefined zcomp_create(void)
// callers: [disksize_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * zcomp_create(long param_1)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  
  iVar1 = crypto_has_alg(param_1,2,0xf);
  if (iVar1 == 1) {
    plVar2 = (long *)kmalloc_trace(_snprintf,0xdc0,0x20);
    if (plVar2 == (long *)0x0) {
      plVar4 = (long *)0xfffffffffffffff4;
    }
    else {
      plVar2[1] = param_1;
      lVar3 = __alloc_percpu(0x18,8);
      *plVar2 = lVar3;
      if (lVar3 == 0) {
        plVar4 = (long *)0xfffffffffffffff4;
      }
      else {
        iVar1 = __cpuhp_state_add_instance(0x44,plVar2 + 2,1);
        if (-1 < iVar1) {
          return plVar2;
        }
        free_percpu(*plVar2);
        plVar4 = (long *)(long)iVar1;
      }
      kfree(plVar2);
    }
  }
  else {
    plVar4 = (long *)0xffffffffffffffea;
  }
  return plVar4;
}



//------------------------------------------------------------
// init_module @ 0010d4bc size=404
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = __cpuhp_setup_state(0x44,"block/zram:prepare",0,zcomp_cpu_up_prepare,zcomp_cpu_dead,1);
  if (-1 < iVar1) {
    iVar1 = __class_register(&zram_control_class,&zram_init___key);
    if (iVar1 == 0) {
      zram_debugfs_root = debugfs_create_dir(&DAT_0010cd58,0);
      zram_major = __register_blkdev(0,&DAT_0010cd58,0);
      if (zram_major < 1) {
        _printk(&DAT_0010c421);
        class_unregister(&zram_control_class);
        __cpuhp_remove_state(0x44,0);
        iVar1 = -0x10;
      }
      else {
        if (num_devices == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 0;
          do {
            mutex_lock(zram_index_mutex);
            iVar1 = zram_add();
            mutex_unlock(zram_index_mutex);
            if (iVar1 < 0) goto LAB_0010d5e4;
            if (iVar1 == 0) {
              mutex_lock(zram_index_mutex);
              uVar2 = idr_find(zram_index_idr,0);
              mutex_unlock(zram_index_mutex);
            }
            num_devices = num_devices + -1;
          } while (num_devices != 0);
        }
        iVar1 = zram_shrink_init(uVar2);
        if (iVar1 != 0) {
LAB_0010d5e4:
          destroy_devices();
        }
      }
    }
    else {
      _printk(&DAT_0010c6ef);
      __cpuhp_remove_state(0x44,0);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010d654 size=28
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  destroy_devices();
  return;
}



//------------------------------------------------------------
// _printk @ 00112000 size=1
// signature: undefined _printk(void)
// callers: [zram_perform_task_prefetch, zram_remove, zram_add, init_module, print_hex_dump_pages, zram_writeback_index, comp_algorithm_store, zram_writeback_oem_func, zram_bvec_rw, read_comp_from_bdev, zram_comp_page_end_io, zram_writeback_page_end_io, writeback_pid_store, zram_writeback_page, zram_wbd, disksize_store, zcomp_cpu_up_prepare, zram_show_mem, backing_dev_store, prefetch_pid_store, zram_perform_task_eswapout, zram_shrink_init, zram_handle_comp_page, handle_decomp_fail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_task_mm @ 00112008 size=1
// signature: undefined get_task_mm(void)
// callers: [zram_perform_task_prefetch, zram_perform_task_eswapout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_task_mm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read_killable @ 00112018 size=1
// signature: undefined down_read_killable(void)
// callers: [zram_perform_task_prefetch, zram_perform_task_eswapout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read_killable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walk_page_range @ 00112028 size=1
// signature: undefined walk_page_range(void)
// callers: [zram_perform_task_prefetch, zram_perform_task_eswapout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walk_page_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 00112038 size=1
// signature: undefined up_read(void)
// callers: [zram_perform_task_prefetch, mm_stat_show, zram_get_total_used_pages, backing_dev_show, compact_store, writeback_limit_enable_show, initstate_show, debug_stat_show, comp_algorithm_show, writeback_limit_show, io_stat_show, zram_meminfo, zram_show_mem, zram_perform_task_eswapout, idle_store, writeback_store, bd_stat_show, read_block_state, mem_used_max_store, writeback_limit_enable_store, writeback_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmput @ 00112040 size=1
// signature: undefined mmput(void)
// callers: [zram_perform_task_prefetch, zram_perform_task_eswapout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00112048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [zram_perform_task_prefetch, mm_stat_show, zram_wb_available, writeback_pid_store, reset_store, zram_submit_bio, backing_dev_store, zram_shrink_init, zram_handle_comp_page, mem_limit_store, zram_get_total_used_pages, am_app_launch_store, zram_bvec_read, zcomp_decompress, comp_algorithm_store, zram_bvec_rw, zram_rw_page, hot_remove_store, zram_wbd, zram_meminfo, prefetch_pid_store, zram_perform_task_eswapout, idle_store, writeback_store, mem_used_max_store, writeback_limit_enable_store, writeback_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mas_find @ 00112068 size=1
// signature: undefined mas_find(void)
// callers: [zram_perform_task_eswapout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mas_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_kprobe @ 00112070 size=1
// signature: undefined register_kprobe(void)
// callers: [zram_shrink_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_kprobe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_kprobe @ 00112078 size=1
// signature: undefined unregister_kprobe(void)
// callers: [zram_shrink_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_kprobe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00112088 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [zram_writeback_done_work, writeback_limit_show, prefetch_pte_range, writeback_limit_enable_show, writeback_store, zram_wb_available, writeback_limit_enable_store, eswapout_writeback_pte_range, writeback_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00112090 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [zram_writeback_done_work, writeback_limit_show, prefetch_pte_range, writeback_limit_enable_show, writeback_store, zram_wb_available, writeback_limit_enable_store, eswapout_writeback_pte_range, writeback_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmd_clear_bad @ 00112098 size=1
// signature: undefined pmd_clear_bad(void)
// callers: [prefetch_pte_range, eswapout_writeback_pte_range]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmd_clear_bad(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001120a0 size=1
// signature: undefined scnprintf(void)
// callers: [mm_stat_show, zcomp_available_show, max_comp_streams_show, writeback_limit_enable_show, initstate_show, debug_stat_show, hot_add_show, writeback_limit_show, wb_duration_stats_show, io_stat_show, disksize_show, zram_ext_version_show, bd_stat_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001120a8 size=1
// signature: undefined mutex_lock(void)
// callers: [hot_add_show, zram_remove, zram_get_total_used_pages, reset_store, init_module, reset_bdev, hot_remove_store, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_get_next @ 001120b0 size=1
// signature: undefined idr_get_next(void)
// callers: [zram_get_total_used_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_get_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read_trylock @ 001120b8 size=1
// signature: undefined down_read_trylock(void)
// callers: [zram_get_total_used_pages, zram_meminfo, zram_show_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_get_total_pages @ 001120c0 size=1
// signature: undefined zs_get_total_pages(void)
// callers: [mm_stat_show, zram_get_total_used_pages, zram_meminfo, zram_show_mem, zram_bvec_rw, mem_used_max_store, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_get_total_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001120c8 size=1
// signature: undefined mutex_unlock(void)
// callers: [hot_add_show, zram_remove, zram_get_total_used_pages, reset_store, init_module, prefetch_pid_store, reset_bdev, writeback_pid_store, hot_remove_store, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 001120d0 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 001120d8 size=1
// signature: undefined __class_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001120e0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [zram_add, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_blkdev @ 001120e8 size=1
// signature: undefined __register_blkdev(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_blkdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 001120f0 size=1
// signature: undefined idr_find(void)
// callers: [init_module, hot_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 001120f8 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [destroy_devices, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 00112100 size=1
// signature: undefined class_unregister(void)
// callers: [destroy_devices, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00112110 size=1
// signature: undefined kmalloc_trace(void)
// callers: [zram_add, zcomp_create, zram_writeback_index, backing_dev_store, read_comp_from_bdev, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00112118 size=1
// signature: undefined idr_alloc(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 00112120 size=1
// signature: undefined __init_rwsem(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00112128 size=1
// signature: undefined __mutex_init(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __blk_alloc_disk @ 00112130 size=1
// signature: undefined __blk_alloc_disk(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __blk_alloc_disk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00112138 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [zram_add, read_block_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_capacity @ 00112140 size=1
// signature: undefined set_capacity(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_capacity(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_flag_set @ 00112148 size=1
// signature: undefined blk_queue_flag_set(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_flag_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_flag_clear @ 00112150 size=1
// signature: undefined blk_queue_flag_clear(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_flag_clear(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_physical_block_size @ 00112158 size=1
// signature: undefined blk_queue_physical_block_size(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_physical_block_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_logical_block_size @ 00112160 size=1
// signature: undefined blk_queue_logical_block_size(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_logical_block_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_io_min @ 00112168 size=1
// signature: undefined blk_queue_io_min(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_io_min(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_io_opt @ 00112170 size=1
// signature: undefined blk_queue_io_opt(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_io_opt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_max_discard_sectors @ 00112178 size=1
// signature: undefined blk_queue_max_discard_sectors(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_max_discard_sectors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_queue_max_write_zeroes_sectors @ 00112180 size=1
// signature: undefined blk_queue_max_write_zeroes_sectors(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_queue_max_write_zeroes_sectors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add_disk @ 00112188 size=1
// signature: undefined device_add_disk(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add_disk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_disk @ 00112190 size=1
// signature: undefined put_disk(void)
// callers: [zram_remove, zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_disk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00112198 size=1
// signature: undefined idr_remove(void)
// callers: [zram_add, hot_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001121a0 size=1
// signature: undefined kfree(void)
// callers: [zram_remove, zram_wbd, zram_writeback_done_work, zcomp_destroy, zram_add, zcomp_create, zram_writeback_index, backing_dev_store, zram_writeback_oem_func, read_comp_from_bdev, zram_handle_comp_page, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001121a8 size=1
// signature: undefined strscpy(void)
// callers: [zram_add, comp_algorithm_store, backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001121b0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001121c0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [zram_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_for_each @ 001121d0 size=1
// signature: undefined idr_for_each(void)
// callers: [destroy_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_for_each(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001121d8 size=1
// signature: undefined debugfs_remove(void)
// callers: [zram_remove, destroy_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 001121e0 size=1
// signature: undefined idr_destroy(void)
// callers: [destroy_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_blkdev @ 001121e8 size=1
// signature: undefined unregister_blkdev(void)
// callers: [destroy_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_blkdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001121f0 size=1
// signature: undefined kstrtoint(void)
// callers: [am_app_launch_store, prefetch_pid_store, writeback_pid_store, hot_remove_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 001121f8 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [zram_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00112200 size=1
// signature: undefined kthread_stop(void)
// callers: [zram_remove, reset_store, reset_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sync_blockdev @ 00112208 size=1
// signature: undefined sync_blockdev(void)
// callers: [zram_remove, reset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sync_blockdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_gendisk @ 00112210 size=1
// signature: undefined del_gendisk(void)
// callers: [zram_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_gendisk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00112218 size=1
// signature: size_t strlen(char * __s)
// callers: [backing_dev_show, zram_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00112220 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [am_app_launch_show, zram_meminfo, writeback_pid_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncpy @ 00112228 size=1
// signature: char * strncpy(char * __dest, char * __src, size_t __n)
// callers: [zram_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00112230 size=1
// signature: undefined seq_printf(void)
// callers: [zram_meminfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 00112238 size=1
// signature: undefined down_write(void)
// callers: [disksize_store, comp_algorithm_store, backing_dev_store, zram_reset_device, mem_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_capacity_and_notify @ 00112240 size=1
// signature: undefined set_capacity_and_notify(void)
// callers: [disksize_store, zram_reset_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_capacity_and_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00112260 size=1
// signature: undefined _find_next_bit(void)
// callers: [zram_reset_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_destroy_pool @ 00112268 size=1
// signature: undefined zs_destroy_pool(void)
// callers: [zram_reset_device, zram_meta_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_destroy_pool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 00112270 size=1
// signature: undefined vfree(void)
// callers: [disksize_store, zram_reset_device, zram_meta_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00112278 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [zram_reset_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 00112280 size=1
// signature: undefined up_write(void)
// callers: [disksize_store, comp_algorithm_store, backing_dev_store, zram_reset_device, mem_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blkdev_put @ 00112288 size=1
// signature: undefined blkdev_put(void)
// callers: [backing_dev_store, reset_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blkdev_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// filp_close @ 00112290 size=1
// signature: undefined filp_close(void)
// callers: [backing_dev_store, reset_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void filp_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree @ 00112298 size=1
// signature: undefined kvfree(void)
// callers: [backing_dev_store, reset_bdev, read_block_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001122a0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [zram_writeback_done_work, zram_free_page, free_block_bdev, zram_writeback_clear_flag, zram_bvec_read, zram_writeback_oem_func, writeback_store, zram_bvec_rw, reset_bdev, zram_dec_wb_table, zram_handle_comp_page, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001122a8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [zram_writeback_done_work, zram_free_page, free_block_bdev, zram_writeback_clear_flag, zram_bvec_read, zram_writeback_oem_func, writeback_store, zram_bvec_rw, reset_bdev, zram_dec_wb_table, zram_handle_comp_page, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_free @ 001122b8 size=1
// signature: undefined zs_free(void)
// callers: [zram_free_page, zram_bvec_rw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_seconds @ 001122c0 size=1
// signature: undefined ktime_get_seconds(void)
// callers: [zram_writeback_done_work, zram_free_page, zram_bvec_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_seconds(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001122c8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [zram_free_page, zram_writeback_clear_flag, zram_bvec_read, list_move, zram_writeback_oem_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 001122d0 size=1
// signature: undefined preempt_schedule(void)
// callers: [zram_writeback_done_work, bit_spin_unlock, zram_writeback_clear_flag, zram_bvec_read, print_hex_dump_pages, zram_writeback_index, copy_to_buf, zram_writeback_oem_func, zram_bvec_rw, zram_slot_free_notify, zcomp_stream_put, zram_writeback_page, zram_wbd, zram_submit_bio, idle_store, writeback_store, read_block_state, zram_handle_comp_page, __kunmap_atomic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_start_io_acct @ 001122d8 size=1
// signature: undefined bio_start_io_acct(void)
// callers: [zram_submit_bio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_start_io_acct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_end_io_acct_remapped @ 001122e0 size=1
// signature: undefined bio_end_io_acct_remapped(void)
// callers: [zram_submit_bio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_end_io_acct_remapped(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_endio @ 001122e8 size=1
// signature: undefined bio_endio(void)
// callers: [zram_submit_bio, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_endio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 001122f0 size=1
// signature: undefined mutex_is_locked(void)
// callers: [zram_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bdev_start_io_acct @ 00112300 size=1
// signature: undefined bdev_start_io_acct(void)
// callers: [zram_rw_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bdev_start_io_acct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bdev_end_io_acct @ 00112308 size=1
// signature: undefined bdev_end_io_acct(void)
// callers: [zram_rw_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bdev_end_io_acct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// page_endio @ 00112310 size=1
// signature: undefined page_endio(void)
// callers: [zram_rw_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void page_endio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_dcache_page @ 00112318 size=1
// signature: undefined flush_dcache_page(void)
// callers: [zram_bvec_rw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_dcache_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_malloc @ 00112328 size=1
// signature: undefined zs_malloc(void)
// callers: [zram_bvec_rw, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_malloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_map_object @ 00112330 size=1
// signature: undefined zs_map_object(void)
// callers: [zram_bvec_read, zram_writeback_index, zram_bvec_rw, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_map_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00112338 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [zram_bvec_read, zram_writeback_index, copy_to_buf, comp_algorithm_store, zram_bvec_rw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_unmap_object @ 00112340 size=1
// signature: undefined zs_unmap_object(void)
// callers: [zram_bvec_read, zram_writeback_index, zram_bvec_rw, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_unmap_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00112348 size=1
// signature: undefined __list_add_valid(void)
// callers: [zram_writeback_clear_flag, list_move, zram_bvec_rw, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 00112350 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [idle_store, zram_bvec_rw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset64 @ 00112358 size=1
// signature: undefined memset64(void)
// callers: [zram_bvec_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memset64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_alloc_bioset @ 00112368 size=1
// signature: undefined bio_alloc_bioset(void)
// callers: [zram_bvec_read, read_comp_from_bdev, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_alloc_bioset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_add_page @ 00112370 size=1
// signature: undefined bio_add_page(void)
// callers: [zram_bvec_read, writeback_store, read_comp_from_bdev, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_add_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_chain @ 00112378 size=1
// signature: undefined bio_chain(void)
// callers: [zram_bvec_read, read_comp_from_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// submit_bio @ 00112380 size=1
// signature: undefined submit_bio(void)
// callers: [zram_bvec_read, read_comp_from_bdev, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void submit_bio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_put @ 00112388 size=1
// signature: undefined bio_put(void)
// callers: [zram_writeback_done_work, zram_bvec_read, read_comp_from_bdev, zram_handle_comp_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 00112390 size=1
// signature: undefined __alloc_pages(void)
// callers: [zram_writeback_index, writeback_store, read_comp_from_bdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 00112398 size=1
// signature: undefined __free_pages(void)
// callers: [zram_wbd, zram_writeback_done_work, zram_writeback_index, zram_writeback_oem_func, writeback_store, read_comp_from_bdev, free_zw_pages, zram_handle_comp_page, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 001123a0 size=1
// signature: undefined print_hex_dump(void)
// callers: [print_hex_dump_pages, zram_writeback_index, handle_decomp_fail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 001123a8 size=1
// signature: noreturn undefined panic(void)
// callers: [handle_decomp_fail]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_status_to_errno @ 001123b0 size=1
// signature: undefined blk_status_to_errno(void)
// callers: [zram_comp_page_end_io, zram_writeback_page_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_status_to_errno(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001123c0 size=1
// signature: undefined queue_work_on(void)
// callers: [zram_comp_page_end_io, zram_writeback_page_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memparse @ 001123c8 size=1
// signature: undefined memparse(void)
// callers: [disksize_store, mem_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memparse(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 001123d0 size=1
// signature: undefined vzalloc(void)
// callers: [disksize_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_create_pool @ 001123d8 size=1
// signature: undefined zs_create_pool(void)
// callers: [disksize_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_create_pool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_huge_class_size @ 001123e0 size=1
// signature: undefined zs_huge_class_size(void)
// callers: [disksize_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_huge_class_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001123e8 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [disksize_store, writeback_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read @ 001123f0 size=1
// signature: undefined down_read(void)
// callers: [mm_stat_show, backing_dev_show, compact_store, writeback_limit_enable_show, initstate_show, debug_stat_show, comp_algorithm_show, writeback_limit_show, io_stat_show, idle_store, writeback_store, bd_stat_show, read_block_state, mem_used_max_store, writeback_limit_enable_store, writeback_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 001123f8 size=1
// signature: undefined kstrtou16(void)
// callers: [reset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_compact @ 00112400 size=1
// signature: undefined zs_compact(void)
// callers: [compact_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_compact(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00112408 size=1
// signature: undefined kstrtoull(void)
// callers: [idle_store, mem_used_max_store, writeback_limit_enable_store, writeback_limit_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_streq @ 00112410 size=1
// signature: undefined sysfs_streq(void)
// callers: [idle_store, writeback_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_streq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00112420 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [comp_algorithm_store, backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00112428 size=1
// signature: undefined fortify_panic(void)
// callers: [comp_algorithm_store, backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// file_path @ 00112430 size=1
// signature: undefined file_path(void)
// callers: [backing_dev_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void file_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memmove @ 00112438 size=1
// signature: void * memmove(void * __dest, void * __src, size_t __n)
// callers: [backing_dev_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memmove(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// filp_open_block @ 00112440 size=1
// signature: undefined filp_open_block(void)
// callers: [backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void filp_open_block(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blkdev_get_by_dev @ 00112448 size=1
// signature: undefined blkdev_get_by_dev(void)
// callers: [backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blkdev_get_by_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvmalloc_node @ 00112450 size=1
// signature: undefined kvmalloc_node(void)
// callers: [backing_dev_store, read_block_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvmalloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00112458 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 00112460 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00112468 size=1
// signature: undefined wake_up_process(void)
// callers: [backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_setscheduler @ 00112470 size=1
// signature: int sched_setscheduler(__pid_t __pid, int __policy, sched_param * __param)
// callers: [backing_dev_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_setscheduler(__pid_t __pid,int __policy,sched_param *__param)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_freezable @ 00112478 size=1
// signature: undefined set_freezable(void)
// callers: [zram_wbd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_freezable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 00112480 size=1
// signature: undefined kthread_should_stop(void)
// callers: [zram_wbd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00112488 size=1
// signature: undefined init_wait_entry(void)
// callers: [zram_wbd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00112490 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [zram_wbd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00112498 size=1
// signature: undefined schedule(void)
// callers: [zram_wbd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001124a0 size=1
// signature: undefined finish_wait(void)
// callers: [zram_wbd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_zero_bit @ 001124c0 size=1
// signature: undefined _find_next_zero_bit(void)
// callers: [writeback_store, zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_zero_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _trace_android_vh_record_pcpu_rwsem_time_early @ 001124c8 size=1
// signature: undefined _trace_android_vh_record_pcpu_rwsem_time_early(void)
// callers: [zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _trace_android_vh_record_pcpu_rwsem_time_early(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _trace_android_vh_record_pcpu_rwsem_starttime @ 001124d0 size=1
// signature: undefined _trace_android_vh_record_pcpu_rwsem_starttime(void)
// callers: [zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _trace_android_vh_record_pcpu_rwsem_starttime(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_associate_blkg @ 001124d8 size=1
// signature: undefined bio_associate_blkg(void)
// callers: [zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_associate_blkg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 001124e0 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __percpu_down_read @ 001124e8 size=1
// signature: undefined __percpu_down_read(void)
// callers: [zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __percpu_down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rcuwait_wake_up @ 001124f0 size=1
// signature: undefined rcuwait_wake_up(void)
// callers: [zram_writeback_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rcuwait_wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bio_init @ 001124f8 size=1
// signature: undefined bio_init(void)
// callers: [writeback_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bio_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// submit_bio_wait @ 00112500 size=1
// signature: undefined submit_bio_wait(void)
// callers: [writeback_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void submit_bio_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 00112508 size=1
// signature: undefined kstrtoll(void)
// callers: [writeback_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 00112510 size=1
// signature: undefined mutex_trylock(void)
// callers: [prefetch_pid_store, writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00112518 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [prefetch_pid_store, writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_vpid @ 00112520 size=1
// signature: undefined find_vpid(void)
// callers: [writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_vpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pid_task @ 00112528 size=1
// signature: undefined pid_task(void)
// callers: [writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pid_task(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00112530 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [prefetch_pid_store, writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __put_task_struct @ 00112538 size=1
// signature: undefined __put_task_struct(void)
// callers: [prefetch_pid_store, writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __put_task_struct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00112540 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [prefetch_pid_store, writeback_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00112548 size=1
// signature: undefined sysfs_emit(void)
// callers: [prefetch_pid_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_task_by_vpid @ 00112550 size=1
// signature: undefined find_task_by_vpid(void)
// callers: [prefetch_pid_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_task_by_vpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// zs_pool_stats @ 00112558 size=1
// signature: undefined zs_pool_stats(void)
// callers: [mm_stat_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void zs_pool_stats(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ns_to_timespec64 @ 00112560 size=1
// signature: undefined ns_to_timespec64(void)
// callers: [read_block_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ns_to_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00112568 size=1
// signature: undefined __check_object_size(void)
// callers: [read_block_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00112578 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [read_block_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_has_alg @ 001125a8 size=1
// signature: undefined crypto_has_alg(void)
// callers: [zcomp_available_show, zcomp_create, zcomp_available_algorithm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_has_alg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001125b0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [zcomp_available_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_comp_compress @ 001125b8 size=1
// signature: undefined crypto_comp_compress(void)
// callers: [zcomp_compress]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_comp_compress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_comp_decompress @ 001125c0 size=1
// signature: undefined crypto_comp_decompress(void)
// callers: [zcomp_decompress]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_comp_decompress(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_alloc_base @ 001125c8 size=1
// signature: undefined crypto_alloc_base(void)
// callers: [zcomp_cpu_up_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_alloc_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_free_pages @ 001125d0 size=1
// signature: undefined __get_free_pages(void)
// callers: [zcomp_cpu_up_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_destroy_tfm @ 001125d8 size=1
// signature: undefined crypto_destroy_tfm(void)
// callers: [zcomp_cpu_up_prepare, zcomp_cpu_dead]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_destroy_tfm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 001125e0 size=1
// signature: undefined free_pages(void)
// callers: [zcomp_cpu_up_prepare, zcomp_cpu_dead]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_state_remove_instance @ 001125e8 size=1
// signature: undefined __cpuhp_state_remove_instance(void)
// callers: [zcomp_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_state_remove_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_percpu @ 001125f0 size=1
// signature: undefined free_percpu(void)
// callers: [zcomp_destroy, zcomp_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_percpu @ 001125f8 size=1
// signature: undefined __alloc_percpu(void)
// callers: [zcomp_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_state_add_instance @ 00112600 size=1
// signature: undefined __cpuhp_state_add_instance(void)
// callers: [zcomp_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_state_add_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



