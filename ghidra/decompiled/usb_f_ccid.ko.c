// Decompiled by Ghidra 12.2
// Program: usb_f_ccid.ko
// Image base: 00100000

//------------------------------------------------------------
// ccid_alloc_inst @ 0010097c size=112
// signature: undefined ccid_alloc_inst(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long ccid_alloc_inst(void)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_config_group_init_type_name,0xdc0,0xc0);
  if (lVar1 == 0) {
    lVar1 = -0xc;
  }
  else {
    *(code **)(lVar1 + 0xa8) = ccid_set_inst_name;
    *(code **)(lVar1 + 0xb0) = ccid_free_inst;
    config_group_init_type_name(lVar1,&DAT_00103086,&ccid_func_type);
  }
  return lVar1;
}



//------------------------------------------------------------
// ccid_alloc @ 001009f0 size=88
// signature: undefined ccid_alloc(void)
// callers: []
//------------------------------------------------------------

undefined8 ccid_alloc(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xb8);
  *puVar1 = &DAT_00103013;
  puVar1[9] = ccid_function_bind;
  puVar1[10] = ccid_function_unbind;
  puVar1[0xd] = ccid_function_set_alt;
  puVar1[0xf] = ccid_function_disable;
  puVar1[0x10] = ccid_function_setup;
  puVar1[0xb] = ccid_free_func;
  return *(undefined8 *)(param_1 + 0xb8);
}



//------------------------------------------------------------
// ccid_set_inst_name @ 00100a4c size=764
// signature: undefined ccid_set_inst_name(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong ccid_set_inst_name(long param_1,char *param_2)

{
  long lVar1;
  uint uVar2;
  size_t sVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  sVar3 = strlen(param_2);
  if (0x28 < (int)sVar3 + 1) {
    uVar5 = 0xffffffdc;
    goto LAB_00100be0;
  }
  uVar5 = kmalloc_trace(_device_destroy,0xdc0,0x2b8);
  if (uVar5 == 0) {
    iVar6 = -0xc;
LAB_00100d28:
    _printk(&DAT_0010325f);
    uVar5 = (ulong)iVar6;
  }
  else {
    *(undefined4 *)(uVar5 + 0xdc) = 0;
    *(ulong *)(uVar5 + 0x110) = uVar5 + 0x110;
    *(ulong *)(uVar5 + 0x118) = uVar5 + 0x110;
    __init_waitqueue_head(uVar5 + 0x120,"&ccid_dev->ctrl_dev.tx_wait_q",&ccid_setup___key);
    __init_waitqueue_head(uVar5 + 0x1d8,"&ccid_dev->bulk_dev.read_wq",&ccid_setup___key_3);
    __init_waitqueue_head(uVar5 + 0x1f0,"&ccid_dev->bulk_dev.write_wq",&ccid_setup___key_5);
    *(ulong *)(uVar5 + 0x218) = uVar5 + 0x218;
    *(ulong *)(uVar5 + 0x220) = uVar5 + 0x218;
    mutex_lock(ccid_ida_lock);
    if (ccid_ida._8_8_ == 0) {
      local_4c = 0;
      uVar4 = __class_create(&__this_module,"ccid_usb",&ccid_alloc_chrdev_region___key);
      if (uVar4 < 0xfffffffffffff001) {
        ccid_class = uVar4;
        uVar2 = alloc_chrdev_region(&local_4c,0,4,"ccid_usb");
        if (uVar2 == 0) {
          major = local_4c >> 0x14;
          goto LAB_00100b88;
        }
        uVar4 = (ulong)uVar2;
        _printk(&DAT_0010335f,"ccid_alloc_chrdev_region",uVar4);
LAB_00100d0c:
        class_destroy(ccid_class);
        ccid_class = 0;
      }
      else {
        ccid_class = 0;
        _printk(&DAT_00102f25,"ccid_alloc_chrdev_region",uVar4 & 0xffffffff);
        if ((int)uVar4 == 0) goto LAB_00100b88;
      }
LAB_00100d14:
      iVar6 = (int)uVar4;
      mutex_unlock(ccid_ida_lock);
      kfree(uVar5);
      goto LAB_00100d28;
    }
LAB_00100b88:
    mutex_unlock(ccid_ida_lock);
    uVar2 = ccid_cdev_init(uVar5 + 0x140,&ccid_ctrl_fops,"ccid_ctrl");
    if (uVar2 != 0) {
      uVar4 = (ulong)uVar2;
      _printk(&DAT_0010317d,"ccid_setup",uVar4);
LAB_00100c84:
      mutex_lock(ccid_ida_lock);
      if (ccid_ida._8_8_ == 0) {
        if (major != 0) {
          unregister_chrdev_region(major << 0x14,4);
          major = 0;
        }
        if (ccid_class != 0) goto LAB_00100d0c;
      }
      goto LAB_00100d14;
    }
    uVar4 = ccid_cdev_init(uVar5 + 0x228,&ccid_bulk_fops,"ccid_bulk");
    if ((int)uVar4 != 0) {
      uVar4 = uVar4 & 0xffffffff;
      _printk(&DAT_00103018,"ccid_setup",uVar4);
      uVar2 = *(uint *)(uVar5 + 0x1c0);
      device_destroy(ccid_class);
      cdev_del(uVar5 + 0x140);
      ida_free(ccid_ida,uVar2 & 0xfffff);
      goto LAB_00100c84;
    }
  }
  if (uVar5 < 0xfffffffffffff001) {
    *(ulong *)(param_1 + 0xb8) = uVar5;
    uVar5 = 0;
  }
LAB_00100be0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// ccid_free_inst @ 00100d4c size=248
// signature: undefined ccid_free_inst(void)
// callers: []
//------------------------------------------------------------

void ccid_free_inst(long param_1)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  if (lVar2 != 0) {
    uVar1 = *(uint *)(lVar2 + 0x1c0);
    device_destroy(ccid_class);
    cdev_del(lVar2 + 0x140);
    ida_free(ccid_ida,uVar1 & 0xfffff);
    lVar2 = *(long *)(param_1 + 0xb8);
    uVar1 = *(uint *)(lVar2 + 0x2a8);
    device_destroy(ccid_class);
    cdev_del(lVar2 + 0x228);
    ida_free(ccid_ida,uVar1 & 0xfffff);
    mutex_lock(ccid_ida_lock);
    if (ccid_ida._8_8_ == 0) {
      if (major != 0) {
        unregister_chrdev_region(major << 0x14,4);
        major = 0;
      }
      if (ccid_class != 0) {
        class_destroy();
        ccid_class = 0;
      }
    }
    mutex_unlock(ccid_ida_lock);
    kfree(*(undefined8 *)(param_1 + 0xb8));
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// ccid_cdev_init @ 00100e44 size=268
// signature: undefined ccid_cdev_init(void)
// callers: [ccid_set_inst_name]
//------------------------------------------------------------

ulong ccid_cdev_init(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar1 = ida_alloc_range(ccid_ida,0,3,0xcc0);
  uVar4 = (ulong)uVar1;
  if ((int)uVar1 < 0) {
    _printk(&DAT_00103137,"ccid_cdev_init",uVar4);
  }
  else {
    cdev_init(param_1,param_2);
    uVar2 = cdev_add(param_1,uVar1 | major << 0x14,1);
    if (uVar2 == 0) {
      uVar3 = device_create(ccid_class,0,uVar1 | major << 0x14,0,param_3);
      if (uVar3 < 0xfffffffffffff001) {
        return 0;
      }
      cdev_del(param_1);
    }
    else {
      uVar3 = (ulong)uVar2;
      _printk(&DAT_001032b2,param_3);
    }
    ida_free(ccid_ida,uVar4);
    uVar4 = uVar3 & 0xffffffff;
  }
  return uVar4;
}



//------------------------------------------------------------
// ccid_ctrl_read @ 00100f54 size=504
// signature: undefined ccid_ctrl_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ccid_ctrl_read(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long lVar6;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0xd8);
  if (*(int *)(lVar6 + 0xe0) != 0) {
    if (3 < param_3) {
      param_3 = 4;
    }
    if ((*(int *)(lVar6 + 0x13c) == 0) && (*(int *)(lVar6 + 0xe0) != 0)) {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_60 = 0;
      init_wait_entry(&local_60,0);
      while ((lVar2 = prepare_to_wait_event(lVar6 + 0x120,&local_60,1), *(int *)(lVar6 + 0x13c) == 0
             && (*(int *)(lVar6 + 0xe0) != 0))) {
        if (lVar2 != 0) {
          if (-1 < (int)lVar2) goto LAB_00100ff8;
          param_3 = (ulong)(int)lVar2;
          goto LAB_001010f8;
        }
        schedule();
      }
      finish_wait(lVar6 + 0x120,&local_60);
    }
LAB_00100ff8:
    *(undefined4 *)(lVar6 + 0x13c) = 0;
    if (*(int *)(lVar6 + 0xe0) != 0) {
      __check_object_size(lVar6 + 0x138,param_3,1);
      puVar4 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
         (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar5 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar3 = param_3;
      if (uVar5 <= 0x8000000000 - param_3) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar5 = daif;
          if ((uVar5 & 0x80) == 0) {
            uVar3 = daif;
            daif = uVar3 | 0xc0;
          }
          puVar4 = (undefined8 *)puVar4[1];
          uVar3 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar4;
          InstructionSynchronizationBarrier();
          daif = uVar5;
        }
        uVar3 = __arch_copy_to_user(puVar4,param_2 & 0xff7fffffffffffff,lVar6 + 0x138,param_3);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar5 = daif;
          if ((uVar5 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          uVar1 = ttbr1_el1;
          ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar5;
        }
      }
      if ((int)uVar3 != 0) {
        param_3 = 0xfffffffffffffff2;
      }
      goto LAB_001010f8;
    }
  }
  param_3 = 0xffffffffffffffed;
LAB_001010f8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}



//------------------------------------------------------------
// ccid_ctrl_ioctl @ 00101168 size=884
// signature: undefined ccid_ctrl_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long ccid_ctrl_ioctl(long param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  int iVar2;
  size_t __n;
  undefined4 uVar3;
  undefined8 *puVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  
  lVar8 = *(long *)(param_1 + 0xd8);
  uVar5 = (uint)_cpu_hwcaps;
  if (param_2 == -0x7ffbbcfd) {
    puVar4 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_3, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar6 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar6) {
      return -0xe;
    }
    if ((uVar5 >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    lVar8 = __arch_copy_to_user(puVar4,param_3 & 0xff7fffffffffffff,lVar8 + 0x2b0,4);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    lVar7 = 0;
    if (lVar8 != 0) {
      lVar7 = -0xe;
    }
    return lVar7;
  }
  plVar9 = *(long **)(lVar8 + 0x100);
  lVar7 = *plVar9;
  if (param_2 == 0x40044302) {
    puVar4 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_3, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar6 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar6 < 0x7ffffffffd) {
      if ((uVar5 >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar4 = (undefined8 *)puVar4[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      __n = __arch_copy_from_user(puVar4,lVar7,param_3 & 0xff7fffffffffffff,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      if (__n == 0) {
        uVar3 = 4;
        goto LAB_00101354;
      }
    }
    else {
LAB_00101478:
      __n = 4;
    }
LAB_0010147c:
    memset((void *)((lVar7 - __n) + 4),0,__n);
    lVar8 = -0xe;
  }
  else {
    if (param_2 == 0x40044301) {
      puVar4 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
         (uVar6 = param_3, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar6 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (0x7ffffffffc < uVar6) goto LAB_00101478;
      if ((uVar5 >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar4 = (undefined8 *)puVar4[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      __n = __arch_copy_from_user(puVar4,lVar7,param_3 & 0xff7fffffffffffff,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      if (__n != 0) goto LAB_0010147c;
      uVar3 = 2;
LAB_00101354:
      *(undefined4 *)(plVar9 + 1) = uVar3;
    }
    iVar2 = usb_ep_queue(*(undefined8 *)(lVar8 + 0xe8),*(undefined8 *)(lVar8 + 0x100),0xcc0);
    if (iVar2 < 0) {
      _printk(&DAT_00102ef8,iVar2);
      lVar8 = (long)iVar2;
    }
    else {
      lVar8 = 0;
    }
  }
  return lVar8;
}



//------------------------------------------------------------
// ccid_ctrl_open @ 00101528 size=124
// signature: undefined ccid_ctrl_open(void)
// callers: []
//------------------------------------------------------------

undefined8 ccid_ctrl_open(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x290);
  if (*(int *)(lVar2 + -0x60) == 0) {
    uVar1 = 0xffffffed;
  }
  else if (*(int *)(lVar2 + -0x38) == 0) {
    *(undefined4 *)(lVar2 + -0x38) = 1;
    uVar1 = _raw_spin_lock_irqsave(lVar2 + -100);
    *(long *)(param_2 + 0xd8) = lVar2 + -0x140;
    _raw_spin_unlock_irqrestore(lVar2 + -100,uVar1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}



//------------------------------------------------------------
// ccid_ctrl_release @ 001015a8 size=16
// signature: undefined ccid_ctrl_release(void)
// callers: []
//------------------------------------------------------------

undefined8 ccid_ctrl_release(undefined8 param_1,long param_2)

{
  *(undefined4 *)(*(long *)(param_2 + 0xd8) + 0x108) = 0;
  return 0;
}



//------------------------------------------------------------
// ccid_bulk_read @ 001015bc size=1012
// signature: undefined ccid_bulk_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ccid_bulk_read(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  ushort uVar3;
  ulong uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  uint uVar14;
  long lVar15;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar15 = sp_el0;
  local_58 = *(long *)(lVar15 + 0x638);
  if (param_3 < 0x401) {
    lVar15 = *(long *)(param_1 + 0xd8);
    if (*(int *)(lVar15 + 0x1c8) == 0) {
      lVar1 = lVar15 + 0xdc;
      uVar3 = *(ushort *)(*(long *)(lVar15 + 0xf8) + 0x2e);
      uVar7 = _raw_spin_lock_irqsave(lVar1);
      if (*(int *)(lVar15 + 0xe0) != 0) {
        uVar11 = (uint)uVar3;
        lVar2 = lVar15 + 0x1d8;
        do {
          puVar12 = *(undefined8 **)(lVar15 + 0x208);
          *(uint *)(puVar12 + 1) = ((uint)param_3 + uVar11) - 1 & -uVar11;
          *(undefined4 *)(lVar15 + 0x210) = 0;
          _raw_spin_unlock_irqrestore(lVar1,uVar7);
          iVar6 = usb_ep_queue(*(undefined8 *)(lVar15 + 0xf8),puVar12,0xcc0);
          if (iVar6 < 0) {
            _printk(&DAT_00102f45,"ccid_bulk_read");
            uVar14 = 0xfffffffb;
            *(undefined4 *)(lVar15 + 0x1c8) = 1;
            goto LAB_00101914;
          }
          if (((*(int *)(lVar15 + 0x210) == 0) && (*(int *)(lVar15 + 0x1c8) == 0)) &&
             (*(int *)(lVar15 + 0xe0) != 0)) {
            local_68 = 0;
            uStack_60 = 0;
            local_78 = 0;
            uStack_70 = 0;
            local_80 = 0;
            init_wait_entry(&local_80,0);
            lVar8 = prepare_to_wait_event(lVar2,&local_80,1);
            if (*(int *)(lVar15 + 0x210) == 0) {
              do {
                if ((*(int *)(lVar15 + 0x1c8) != 0) || (*(int *)(lVar15 + 0xe0) == 0)) break;
                if (lVar8 != 0) {
                  uVar14 = (uint)lVar8;
                  if (-1 < (int)uVar14) goto LAB_001016b4;
                  *(undefined4 *)(lVar15 + 0x1c8) = 1;
                  usb_ep_dequeue(*(undefined8 *)(lVar15 + 0xf8),puVar12);
                  goto LAB_00101914;
                }
                schedule();
                lVar8 = prepare_to_wait_event(lVar2,&local_80,1);
              } while (*(int *)(lVar15 + 0x210) == 0);
            }
            finish_wait(lVar2,&local_80);
          }
LAB_001016b4:
          if (*(int *)(lVar15 + 0x1c8) != 0) {
            uVar14 = 0xfffffffb;
            goto LAB_00101914;
          }
          uVar7 = _raw_spin_lock_irqsave(lVar1);
          if (*(int *)(lVar15 + 0xe0) == 0) {
LAB_0010190c:
            _raw_spin_unlock_irqrestore(lVar1,uVar7);
            uVar14 = 0xffffffed;
            goto LAB_00101914;
          }
          uVar9 = (ulong)*(uint *)(puVar12 + 0xb);
          if (*(uint *)(puVar12 + 0xb) != 0) {
            if (param_3 < uVar9) {
              _printk(&DAT_001031a9,"ccid_bulk_read",uVar9,param_3);
              uVar9 = (ulong)*(uint *)(puVar12 + 0xb);
            }
            uVar14 = (uint)uVar9;
            if (param_3 <= uVar9) {
              uVar14 = (uint)param_3;
            }
            uVar9 = (ulong)uVar14;
            *(undefined4 *)(lVar15 + 0x1d0) = 1;
            _raw_spin_unlock_irqrestore(lVar1,uVar7);
            if ((int)uVar14 < 0) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101994);
              (*pcVar5)();
            }
            uVar7 = *puVar12;
            __check_object_size(uVar7,uVar9,1);
            puVar12 = (undefined8 *)sp_el0;
            if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
               (uVar10 = param_2, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
              uVar10 = param_2 & (long)(param_2 << 8) >> 8;
            }
            if (uVar10 <= 0x8000000000 - uVar9) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar10 = daif;
                if ((uVar10 & 0x80) == 0) {
                  uVar4 = daif;
                  daif = uVar4 | 0xc0;
                }
                puVar12 = (undefined8 *)puVar12[1];
                uVar4 = ttbr1_el1;
                ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar12;
                InstructionSynchronizationBarrier();
                daif = uVar10;
              }
              __arch_copy_to_user(puVar12,param_2 & 0xff7fffffffffffff,uVar7,uVar9);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar9 = daif;
                if ((uVar9 & 0x80) == 0) {
                  uVar10 = daif;
                  daif = uVar10 | 0xc0;
                }
                uVar10 = ttbr1_el1;
                ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar10 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar9;
              }
            }
            uVar7 = _raw_spin_lock_irqsave(lVar1);
            *(undefined4 *)(lVar15 + 0x1d0) = 0;
            if (*(int *)(lVar15 + 0xe0) == 0) {
              puVar12 = *(undefined8 **)(lVar15 + 0x208);
              if (puVar12 != (undefined8 *)0x0) {
                uVar13 = *(undefined8 *)(lVar15 + 0xf8);
                kfree(*puVar12);
                usb_ep_free_request(uVar13,puVar12);
              }
              goto LAB_0010190c;
            }
            _raw_spin_unlock_irqrestore(lVar1,uVar7);
            goto LAB_00101914;
          }
          _raw_spin_unlock_irqrestore(lVar1,uVar7);
          uVar7 = _raw_spin_lock_irqsave(lVar1);
        } while (*(int *)(lVar15 + 0xe0) != 0);
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar7);
      lVar15 = -0x13;
    }
    else {
      _printk(&DAT_00103071,"ccid_bulk_read");
      uVar14 = 0xfffffffb;
LAB_00101914:
      lVar15 = (long)(int)uVar14;
    }
  }
  else {
    _printk(&DAT_00103044,"ccid_bulk_read",0x400,param_3);
    lVar15 = -0xc;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar15);
  }
  return;
}



//------------------------------------------------------------
// ccid_bulk_write @ 001019d0 size=1268
// signature: undefined ccid_bulk_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ccid_bulk_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  long *plVar13;
  long lVar14;
  long *plVar15;
  long lVar16;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 0xd8);
  if (*(int *)(lVar16 + 0xe0) == 0) {
    lVar16 = -0x13;
    goto LAB_00101dec;
  }
  if (param_3 == 0) {
    _printk(&DAT_001030e6,"ccid_bulk_write");
    lVar16 = -0x13;
    goto LAB_00101dec;
  }
  if (0x20b < param_3) {
    _printk(&DAT_00102fb2,"ccid_bulk_write",0x20b,param_3);
    lVar16 = -0xc;
    goto LAB_00101dec;
  }
  lVar1 = lVar16 + 0xdc;
  plVar2 = (long *)(lVar16 + 0x218);
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  plVar15 = *(long **)(lVar16 + 0x218);
  if (plVar15 == plVar2) {
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
LAB_00101a9c:
    if (*(int *)(lVar16 + 0x1c8) != 0) goto LAB_00101dd0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_90 = 0;
    init_wait_entry(&local_90,0);
    lVar14 = lVar16 + 0x1f0;
    while( true ) {
      uVar9 = prepare_to_wait_event(lVar14,&local_90,1);
      uVar8 = _raw_spin_lock_irqsave(lVar1);
      plVar15 = (long *)*plVar2;
      if (plVar15 == plVar2) {
        _raw_spin_unlock_irqrestore(lVar1,uVar8);
        iVar7 = *(int *)(lVar16 + 0x1c8);
      }
      else {
        plVar13 = plVar15 + -8;
        uVar10 = __list_del_entry_valid(plVar15);
        if ((uVar10 & 1) != 0) {
          lVar3 = *plVar15;
          plVar4 = (long *)plVar15[1];
          *(long **)(lVar3 + 8) = plVar4;
          *plVar4 = lVar3;
        }
        *plVar15 = -0x2152ffffffffff00;
        plVar15[1] = -0x2152fffffffffede;
        _raw_spin_unlock_irqrestore(lVar1,uVar8);
        if (plVar13 != (long *)0x0) {
          finish_wait(lVar14,&local_90);
          iVar7 = *(int *)(lVar16 + 0x1c8);
          goto joined_r0x00101a80;
        }
        iVar7 = *(int *)(lVar16 + 0x1c8);
      }
      if (iVar7 != 0) {
        finish_wait(lVar14,&local_90);
        goto LAB_00101dd0;
      }
      if (uVar9 != 0) break;
      schedule();
    }
    if (-1 < (int)uVar9) goto LAB_00101dd0;
  }
  else {
    plVar13 = plVar15 + -8;
    uVar9 = __list_del_entry_valid(plVar15);
    if ((uVar9 & 1) != 0) {
      lVar14 = *plVar15;
      plVar4 = (long *)plVar15[1];
      *(long **)(lVar14 + 8) = plVar4;
      *plVar4 = lVar14;
    }
    *plVar15 = -0x2152ffffffffff00;
    plVar15[1] = -0x2152fffffffffede;
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
    if (plVar13 == (long *)0x0) goto LAB_00101a9c;
    iVar7 = *(int *)(lVar16 + 0x1c8);
joined_r0x00101a80:
    if (iVar7 == 0) {
      if (param_3 >> 0x1f != 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x101e28);
        (*pcVar6)();
      }
      lVar14 = *plVar13;
      __check_object_size(lVar14,param_3,0);
      puVar12 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
         (uVar9 = param_2, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
        uVar9 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar10 = param_3;
      if (uVar9 <= 0x8000000000 - param_3) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar10 = daif;
            daif = uVar10 | 0xc0;
          }
          puVar12 = (undefined8 *)puVar12[1];
          uVar10 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar10 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar12;
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        uVar10 = __arch_copy_from_user(puVar12,lVar14,param_2 & 0xff7fffffffffffff,param_3);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
      }
      if (uVar10 == 0) {
        *(int *)(plVar13 + 1) = (int)param_3;
        iVar7 = usb_ep_queue(*(undefined8 *)(lVar16 + 0xf0),plVar13,0xcc0);
        uVar9 = param_3;
        if (iVar7 < 0) {
          *(undefined4 *)(lVar16 + 0x1c8) = 1;
          uVar8 = _raw_spin_lock_irqsave(lVar1);
          puVar12 = *(undefined8 **)(lVar16 + 0x220);
          plVar15 = plVar13 + 8;
          uVar9 = __list_add_valid(plVar15,puVar12,plVar2);
          if ((uVar9 & 1) != 0) {
            *(long **)(lVar16 + 0x220) = plVar15;
            plVar13[8] = (long)plVar2;
            plVar13[9] = (long)puVar12;
            *puVar12 = plVar15;
          }
          _raw_spin_unlock_irqrestore(lVar1,uVar8);
          uVar8 = _raw_spin_lock_irqsave(lVar1);
          if (*(int *)(lVar16 + 0xe0) == 0) {
            _raw_spin_unlock_irqrestore(lVar1,uVar8);
            uVar11 = _raw_spin_lock_irqsave(lVar1);
            plVar15 = (long *)*plVar2;
            while (plVar15 != plVar2) {
              plVar13 = plVar15 + -8;
              uVar9 = __list_del_entry_valid(plVar15);
              if ((uVar9 & 1) != 0) {
                lVar14 = *plVar15;
                plVar4 = (long *)plVar15[1];
                *(long **)(lVar14 + 8) = plVar4;
                *plVar4 = lVar14;
              }
              *plVar15 = -0x2152ffffffffff00;
              plVar15[1] = -0x2152fffffffffede;
              _raw_spin_unlock_irqrestore(lVar1,uVar11);
              if (plVar13 == (long *)0x0) goto LAB_00101db0;
              uVar11 = *(undefined8 *)(lVar16 + 0xf0);
              kfree(*plVar13);
              usb_ep_free_request(uVar11,plVar13);
              uVar11 = _raw_spin_lock_irqsave(lVar1);
              plVar15 = *(long **)(lVar16 + 0x218);
            }
            _raw_spin_unlock_irqrestore(lVar1,uVar11);
LAB_00101db0:
            uVar9 = 0xffffffffffffffed;
          }
          else {
            uVar9 = 0xfffffffffffffffb;
          }
          _raw_spin_unlock_irqrestore(lVar1,uVar8);
        }
      }
      else {
        memset((void *)(lVar14 + (param_3 - uVar10)),0,uVar10);
        if (*(int *)(lVar16 + 0xe0) == 0) {
          uVar8 = *(undefined8 *)(lVar16 + 0xf0);
          kfree(*plVar13);
          usb_ep_free_request(uVar8,plVar13);
          uVar9 = 0xffffffffffffffed;
        }
        else {
          uVar8 = _raw_spin_lock_irqsave(lVar1);
          puVar12 = *(undefined8 **)(lVar16 + 0x220);
          plVar15 = plVar13 + 8;
          uVar9 = __list_add_valid(plVar15,puVar12,plVar2);
          if ((uVar9 & 1) != 0) {
            *(long **)(lVar16 + 0x220) = plVar15;
            plVar13[8] = (long)plVar2;
            plVar13[9] = (long)puVar12;
            *puVar12 = plVar15;
          }
          _raw_spin_unlock_irqrestore(lVar1,uVar8);
          uVar9 = 0xfffffffffffffff2;
        }
      }
      goto LAB_00101de8;
    }
LAB_00101dd0:
    _printk(&DAT_0010334d,"ccid_bulk_write");
    uVar9 = 0xfffffffffffffffb;
  }
LAB_00101de8:
  lVar16 = (long)(int)uVar9;
LAB_00101dec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar16);
  }
  return;
}



//------------------------------------------------------------
// ccid_bulk_open @ 00101ee4 size=132
// signature: undefined ccid_bulk_open(void)
// callers: []
//------------------------------------------------------------

undefined8 ccid_bulk_open(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x290);
  if (*(int *)(lVar2 + -0x148) == 0) {
    uVar1 = 0xffffffed;
  }
  else if (*(int *)(lVar2 + -0x5c) == 0) {
    *(undefined4 *)(lVar2 + -0x5c) = 1;
    *(undefined4 *)(lVar2 + -0x60) = 0;
    uVar1 = _raw_spin_lock_irqsave(lVar2 + -0x14c);
    *(long *)(param_2 + 0xd8) = lVar2 + -0x228;
    _raw_spin_unlock_irqrestore(lVar2 + -0x14c,uVar1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}



//------------------------------------------------------------
// ccid_bulk_release @ 00101f6c size=16
// signature: undefined ccid_bulk_release(void)
// callers: []
//------------------------------------------------------------

undefined8 ccid_bulk_release(undefined8 param_1,long param_2)

{
  *(undefined4 *)(*(long *)(param_2 + 0xd8) + 0x1cc) = 0;
  return 0;
}



//------------------------------------------------------------
// ccid_request_free @ 00101f7c size=64
// signature: undefined ccid_request_free(void)
// callers: [ccid_function_bind]
//------------------------------------------------------------

void ccid_request_free(undefined8 *param_1,undefined8 param_2)

{
  if (param_1 != (undefined8 *)0x0) {
    kfree(*param_1);
    usb_ep_free_request(param_2,param_1);
  }
  return;
}



//------------------------------------------------------------
// ccid_attr_release @ 00101fc0 size=28
// signature: undefined ccid_attr_release(void)
// callers: []
//------------------------------------------------------------

void ccid_attr_release(void)

{
  usb_put_function_instance();
  return;
}



//------------------------------------------------------------
// ccid_function_bind @ 00101fe0 size=1360
// signature: undefined ccid_function_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong ccid_function_bind(long param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  long *plVar9;
  undefined8 uVar10;
  long *plVar11;
  
  puVar8 = *(undefined8 **)(param_1 + 0x30);
  iVar3 = usb_interface_id();
  *(int *)(param_2 + 0xd8) = iVar3;
  if (iVar3 < 0) {
    _printk(&DAT_00103324,"ccid_function_bind");
    plVar9 = (long *)(ulong)*(uint *)(param_2 + 0xd8);
    goto LAB_0010250c;
  }
  ccid_interface_desc[2] = (char)iVar3;
  puVar4 = (undefined8 *)usb_ep_autoconfig(*puVar8,ccid_fs_notify_desc);
  if (puVar4 == (undefined8 *)0x0) {
    _printk(&DAT_00103102,"ccid_function_bind");
    plVar9 = (long *)0xffffffed;
    goto LAB_0010250c;
  }
  *(undefined8 **)(param_2 + 0xe8) = puVar4;
  *puVar4 = puVar8;
  puVar4 = (undefined8 *)usb_ep_autoconfig(*puVar8,ccid_fs_in_desc);
  if (puVar4 == (undefined8 *)0x0) {
    _printk(&DAT_00103395,"ccid_function_bind");
    plVar9 = (long *)0xffffffed;
  }
  else {
    *(undefined8 **)(param_2 + 0xf0) = puVar4;
    *puVar4 = puVar8;
    puVar4 = (undefined8 *)usb_ep_autoconfig(*puVar8,ccid_fs_out_desc);
    if (puVar4 == (undefined8 *)0x0) {
      _printk(&DAT_001031f4,"ccid_function_bind");
      plVar9 = (long *)0xffffffed;
    }
    else {
      *(undefined8 **)(param_2 + 0xf8) = puVar4;
      *puVar4 = puVar8;
      ccid_hs_in_desc[2] = ccid_fs_in_desc[2];
      ccid_ss_in_desc[2] = ccid_fs_in_desc[2];
      ccid_hs_out_desc[2] = ccid_fs_out_desc[2];
      ccid_hs_notify_desc[2] = ccid_fs_notify_desc[2];
      ccid_ss_out_desc[2] = ccid_fs_out_desc[2];
      ccid_ss_notify_desc[2] = ccid_fs_notify_desc[2];
      uVar5 = usb_assign_descriptors
                        (param_2,&ccid_fs_descs,&ccid_hs_descs,&ccid_ss_descs,&ccid_ss_descs);
      plVar9 = (long *)(uVar5 & 0xffffffff);
      if ((int)uVar5 == 0) {
        uVar10 = *(undefined8 *)(param_2 + 0xe8);
        plVar9 = (long *)usb_ep_alloc_request(uVar10,0xcc0);
        if (plVar9 == (long *)0x0) {
LAB_00102478:
          *(undefined8 *)(param_2 + 0x100) = 0xfffffffffffffff4;
LAB_00102480:
          _printk(&DAT_0010309d,"ccid_function_bind");
          plVar9 = (long *)0x0;
        }
        else {
          *(undefined4 *)(plVar9 + 1) = 4;
          lVar6 = kmalloc_trace(___class_create,0xcc0,4);
          *plVar9 = lVar6;
          if (lVar6 == 0) {
            usb_ep_free_request(uVar10,plVar9);
            goto LAB_00102478;
          }
          *(long **)(param_2 + 0x100) = plVar9;
          if ((long *)0xfffffffffffff000 < plVar9) goto LAB_00102480;
          plVar9[6] = (long)ccid_notify_complete;
          *(long *)(*(long *)(param_2 + 0x100) + 0x38) = param_2;
          uVar10 = *(undefined8 *)(param_2 + 0xf8);
          plVar9 = (long *)usb_ep_alloc_request(uVar10,0xcc0);
          if (plVar9 == (long *)0x0) {
LAB_001024a8:
            plVar9 = (long *)0xfffffffffffffff4;
LAB_001024ac:
            _printk(&DAT_001032d1,"ccid_function_bind");
            puVar8 = *(undefined8 **)(param_2 + 0x100);
          }
          else {
            *(undefined4 *)(plVar9 + 1) = 0x400;
            lVar6 = kmalloc_trace(_device_destroy,0xcc0,0x400);
            *plVar9 = lVar6;
            if (lVar6 == 0) {
              usb_ep_free_request(uVar10,plVar9);
              goto LAB_001024a8;
            }
            if ((long *)0xfffffffffffff000 < plVar9) goto LAB_001024ac;
            plVar9[6] = (long)ccid_bulk_complete_out;
            plVar9[7] = param_2;
            uVar10 = *(undefined8 *)(param_2 + 0xf0);
            *(long **)(param_2 + 0x208) = plVar9;
            plVar9 = (long *)usb_ep_alloc_request(uVar10,0xcc0);
            if (plVar9 == (long *)0x0) {
LAB_0010243c:
              plVar9 = (long *)0xfffffffffffffff4;
            }
            else {
              *(undefined4 *)(plVar9 + 1) = 0x20b;
              lVar6 = kmalloc_trace(_device_destroy,0xcc0,0x20b);
              *plVar9 = lVar6;
              if (lVar6 == 0) {
LAB_00102430:
                usb_ep_free_request(uVar10,plVar9);
                goto LAB_0010243c;
              }
              if (plVar9 < (long *)0xfffffffffffff001) {
                lVar6 = param_2 + 0xdc;
                lVar1 = param_2 + 0x218;
                plVar9[6] = (long)ccid_bulk_complete_in;
                plVar9[7] = param_2;
                uVar10 = _raw_spin_lock_irqsave(lVar6);
                plVar11 = *(long **)(param_2 + 0x220);
                plVar2 = plVar9 + 8;
                uVar5 = __list_add_valid(plVar2,plVar11,lVar1);
                if ((uVar5 & 1) != 0) {
                  *(long **)(param_2 + 0x220) = plVar2;
                  plVar9[8] = lVar1;
                  plVar9[9] = (long)plVar11;
                  *plVar11 = (long)plVar2;
                }
                _raw_spin_unlock_irqrestore(lVar6,uVar10);
                uVar10 = *(undefined8 *)(param_2 + 0xf0);
                plVar9 = (long *)usb_ep_alloc_request(uVar10,0xcc0);
                if (plVar9 == (long *)0x0) goto LAB_0010243c;
                *(undefined4 *)(plVar9 + 1) = 0x20b;
                lVar7 = kmalloc_trace(_device_destroy,0xcc0,0x20b);
                *plVar9 = lVar7;
                if (lVar7 == 0) goto LAB_00102430;
                if (plVar9 < (long *)0xfffffffffffff001) {
                  plVar9[6] = (long)ccid_bulk_complete_in;
                  plVar9[7] = param_2;
                  uVar10 = _raw_spin_lock_irqsave(lVar6);
                  plVar11 = *(long **)(param_2 + 0x220);
                  plVar2 = plVar9 + 8;
                  uVar5 = __list_add_valid(plVar2,plVar11,lVar1);
                  if ((uVar5 & 1) != 0) {
                    *(long **)(param_2 + 0x220) = plVar2;
                    plVar9[8] = lVar1;
                    plVar9[9] = (long)plVar11;
                    *plVar11 = (long)plVar2;
                  }
                  _raw_spin_unlock_irqrestore(lVar6,uVar10);
                  uVar10 = *(undefined8 *)(param_2 + 0xf0);
                  plVar9 = (long *)usb_ep_alloc_request(uVar10,0xcc0);
                  if (plVar9 == (long *)0x0) goto LAB_0010243c;
                  *(undefined4 *)(plVar9 + 1) = 0x20b;
                  lVar7 = kmalloc_trace(_device_destroy,0xcc0,0x20b);
                  *plVar9 = lVar7;
                  if (lVar7 == 0) goto LAB_00102430;
                  if (plVar9 < (long *)0xfffffffffffff001) {
                    plVar9[6] = (long)ccid_bulk_complete_in;
                    plVar9[7] = param_2;
                    uVar10 = _raw_spin_lock_irqsave(lVar6);
                    plVar11 = *(long **)(param_2 + 0x220);
                    plVar2 = plVar9 + 8;
                    uVar5 = __list_add_valid(plVar2,plVar11,lVar1);
                    if ((uVar5 & 1) != 0) {
                      *(long **)(param_2 + 0x220) = plVar2;
                      plVar9[8] = lVar1;
                      plVar9[9] = (long)plVar11;
                      *plVar11 = (long)plVar2;
                    }
                    _raw_spin_unlock_irqrestore(lVar6,uVar10);
                    uVar10 = *(undefined8 *)(param_2 + 0xf0);
                    plVar9 = (long *)usb_ep_alloc_request(uVar10,0xcc0);
                    if (plVar9 == (long *)0x0) goto LAB_0010243c;
                    *(undefined4 *)(plVar9 + 1) = 0x20b;
                    lVar7 = kmalloc_trace(_device_destroy,0xcc0,0x20b);
                    *plVar9 = lVar7;
                    if (lVar7 == 0) goto LAB_00102430;
                    if (plVar9 < (long *)0xfffffffffffff001) {
                      plVar9[6] = (long)ccid_bulk_complete_in;
                      plVar9[7] = param_2;
                      uVar10 = _raw_spin_lock_irqsave(lVar6);
                      plVar11 = *(long **)(param_2 + 0x220);
                      plVar2 = plVar9 + 8;
                      uVar5 = __list_add_valid(plVar2,plVar11,lVar1);
                      if ((uVar5 & 1) != 0) {
                        *(long **)(param_2 + 0x220) = plVar2;
                        plVar9[8] = lVar1;
                        plVar9[9] = (long)plVar11;
                        *plVar11 = (long)plVar2;
                      }
                      _raw_spin_unlock_irqrestore(lVar6,uVar10);
                      plVar9 = (long *)0x0;
                      goto LAB_0010250c;
                    }
                  }
                }
              }
            }
            _printk(&DAT_00103217,"ccid_function_bind");
            ccid_request_free(*(undefined8 *)(param_2 + 0x208),*(undefined8 *)(param_2 + 0xf8));
            puVar8 = *(undefined8 **)(param_2 + 0x100);
          }
          if (puVar8 != (undefined8 *)0x0) {
            uVar10 = *(undefined8 *)(param_2 + 0xe8);
            kfree(*puVar8);
            usb_ep_free_request(uVar10,puVar8);
          }
        }
        usb_free_all_descriptors(param_2);
      }
      **(undefined8 **)(param_2 + 0xf8) = 0;
      *(undefined8 *)(param_2 + 0xf8) = 0;
    }
    **(undefined8 **)(param_2 + 0xf0) = 0;
    *(undefined8 *)(param_2 + 0xf0) = 0;
  }
  **(undefined8 **)(param_2 + 0xe8) = 0;
  *(undefined8 *)(param_2 + 0xe8) = 0;
LAB_0010250c:
  return (ulong)plVar9 & 0xffffffff;
}



//------------------------------------------------------------
// ccid_function_unbind @ 00102534 size=292
// signature: undefined ccid_function_unbind(void)
// callers: []
//------------------------------------------------------------

void ccid_function_unbind(undefined8 param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long *plVar7;
  long *plVar8;
  
  puVar5 = *(undefined8 **)(param_2 + 0x100);
  if (puVar5 != (undefined8 *)0x0) {
    uVar6 = *(undefined8 *)(param_2 + 0xe8);
    kfree(*puVar5);
    usb_ep_free_request(uVar6,puVar5);
  }
  if ((*(int *)(param_2 + 0x1d0) == 0) &&
     (puVar5 = *(undefined8 **)(param_2 + 0x208), puVar5 != (undefined8 *)0x0)) {
    uVar6 = *(undefined8 *)(param_2 + 0xf8);
    kfree(*puVar5);
    usb_ep_free_request(uVar6,puVar5);
  }
  lVar1 = param_2 + 0xdc;
  uVar6 = _raw_spin_lock_irqsave(lVar1);
  plVar7 = *(long **)(param_2 + 0x218);
  while (plVar7 != (long *)(param_2 + 0x218)) {
    plVar8 = plVar7 + -8;
    uVar4 = __list_del_entry_valid(plVar7);
    if ((uVar4 & 1) != 0) {
      lVar2 = *plVar7;
      plVar3 = (long *)plVar7[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar7 = -0x2152ffffffffff00;
    plVar7[1] = -0x2152fffffffffede;
    _raw_spin_unlock_irqrestore(lVar1,uVar6);
    if (plVar8 == (long *)0x0) goto LAB_00102634;
    uVar6 = *(undefined8 *)(param_2 + 0xf0);
    kfree(*plVar8);
    usb_ep_free_request(uVar6,plVar8);
    uVar6 = _raw_spin_lock_irqsave(lVar1);
    plVar7 = *(long **)(param_2 + 0x218);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
LAB_00102634:
  usb_free_all_descriptors(param_2);
  return;
}



//------------------------------------------------------------
// ccid_function_set_alt @ 0010265c size=388
// signature: undefined ccid_function_set_alt(void)
// callers: []
//------------------------------------------------------------

int ccid_function_set_alt(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(*(long *)(param_1 + 0x30) + 0x30);
  iVar1 = config_ep_by_speed(*puVar4,param_1,*(undefined8 *)(param_1 + 0xe8));
  if (iVar1 != 0) {
    *(undefined8 *)(*(long *)(param_1 + 0xe8) + 0x38) = 0;
    puVar2 = &DAT_00102fe0;
    lVar3 = *(long *)(*(long *)(param_1 + 0xe8) + 8);
LAB_0010272c:
    _printk(puVar2,"ccid_function_set_alt",lVar3,iVar1);
    return iVar1;
  }
  iVar1 = usb_ep_enable();
  if (iVar1 != 0) {
    lVar3 = (*(long **)(param_1 + 0xe8))[1];
    puVar2 = &DAT_00102f8b;
    goto LAB_0010272c;
  }
  **(long **)(param_1 + 0xe8) = param_1;
  iVar1 = config_ep_by_speed(*puVar4,param_1,*(undefined8 *)(param_1 + 0xf0));
  if (iVar1 == 0) {
    iVar1 = usb_ep_enable();
    if (iVar1 == 0) {
      iVar1 = config_ep_by_speed(*puVar4,param_1,*(undefined8 *)(param_1 + 0xf8));
      if (iVar1 == 0) {
        iVar1 = usb_ep_enable();
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x2b0) = 1;
          *(undefined4 *)(param_1 + 0xe0) = 1;
          return 0;
        }
        lVar3 = *(long *)(param_1 + 0xf8);
        puVar2 = &DAT_00102f8b;
      }
      else {
        *(undefined8 *)(*(long *)(param_1 + 0xf8) + 0x38) = 0;
        puVar2 = &DAT_00102fe0;
        lVar3 = *(long *)(param_1 + 0xf8);
      }
      _printk(puVar2,"ccid_function_set_alt",*(undefined8 *)(lVar3 + 8),iVar1);
      usb_ep_disable(*(undefined8 *)(param_1 + 0xf0));
      goto LAB_001027b8;
    }
    lVar3 = *(long *)(param_1 + 0xf0);
    puVar2 = &DAT_00102f8b;
  }
  else {
    *(undefined8 *)(*(long *)(param_1 + 0xf0) + 0x38) = 0;
    puVar2 = &DAT_00102fe0;
    lVar3 = *(long *)(param_1 + 0xf0);
  }
  _printk(puVar2,"ccid_function_set_alt",*(undefined8 *)(lVar3 + 8),iVar1);
LAB_001027b8:
  usb_ep_disable(*(undefined8 *)(param_1 + 0xe8));
  **(undefined8 **)(param_1 + 0xe8) = 0;
  return iVar1;
}



//------------------------------------------------------------
// ccid_function_setup @ 001027e4 size=284
// signature: undefined ccid_function_setup(void)
// callers: []
//------------------------------------------------------------

int ccid_function_setup(long param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined8 *puVar6;
  long *plVar7;
  
  uVar1 = param_2[1];
  plVar7 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
  puVar6 = (undefined8 *)plVar7[1];
  if (*(int *)(param_1 + 0xe0) == 0) {
    return -0x6b;
  }
  uVar2 = *param_2 >> 8 | *param_2 << 8;
  uVar5 = (uint)param_2[3];
  if (uVar2 == 0xa103) {
    puVar4 = (undefined4 *)(ccid_class_desc + 0x13);
  }
  else {
    if (uVar2 != 0xa102) {
      if ((uVar2 != 0x2101) || (uVar5 != 0)) {
        return -0x5f;
      }
      *(char *)(param_1 + 0x139) = (char)uVar1;
      *(undefined1 *)(param_1 + 0x13b) = 0;
      *(undefined1 *)(param_1 + 0x138) = 1;
      *(char *)(param_1 + 0x13a) = (char)(uVar1 >> 8);
      *(undefined4 *)(param_1 + 0x13c) = 1;
      __wake_up(param_1 + 0x120,3,1,0);
      uVar5 = 0;
      goto LAB_0010287c;
    }
    puVar4 = (undefined4 *)(ccid_class_desc + 10);
  }
  if (3 < uVar5) {
    uVar5 = 4;
  }
  *(undefined4 *)*puVar6 = *puVar4;
LAB_0010287c:
  *(uint *)(puVar6 + 1) = uVar5;
  iVar3 = usb_ep_queue(*(undefined8 *)(*plVar7 + 0x40),puVar6,0xa20);
  if (iVar3 < 0) {
    _printk(&DAT_001031d9,iVar3);
  }
  return iVar3;
}



//------------------------------------------------------------
// ccid_function_disable @ 00102904 size=128
// signature: undefined ccid_function_disable(void)
// callers: []
//------------------------------------------------------------

void ccid_function_disable(long param_1)

{
  usb_ep_disable(*(undefined8 *)(param_1 + 0xe8));
  usb_ep_disable(*(undefined8 *)(param_1 + 0xf0));
  usb_ep_disable(*(undefined8 *)(param_1 + 0xf8));
  *(undefined4 *)(param_1 + 0x2b0) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  __wake_up(param_1 + 0x1f0,3,1,0);
  __wake_up(param_1 + 0x1d8,3,1,0);
  __wake_up(param_1 + 0x120,3,1,0);
  return;
}



//------------------------------------------------------------
// ccid_free_func @ 00102988 size=4
// signature: undefined ccid_free_func(void)
// callers: []
//------------------------------------------------------------

void ccid_free_func(void)

{
  return;
}



//------------------------------------------------------------
// ccid_notify_complete @ 00102990 size=64
// signature: undefined ccid_notify_complete(void)
// callers: []
//------------------------------------------------------------

void ccid_notify_complete(undefined8 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x54);
  if (((iVar1 != -0x6c) && (iVar1 != -0x68)) && (iVar1 != 0)) {
    _printk(&DAT_001032fe);
  }
  return;
}



//------------------------------------------------------------
// ccid_bulk_complete_out @ 001029d4 size=72
// signature: undefined ccid_bulk_complete_out(void)
// callers: []
//------------------------------------------------------------

void ccid_bulk_complete_out(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_2 + 0x38);
  if (*(int *)(param_2 + 0x54) != 0) {
    *(undefined4 *)(lVar1 + 0x1c8) = 1;
  }
  *(undefined4 *)(lVar1 + 0x210) = 1;
  __wake_up(lVar1 + 0x1d8,3,1,0);
  return;
}



//------------------------------------------------------------
// ccid_bulk_complete_in @ 00102a20 size=172
// signature: undefined ccid_bulk_complete_in(void)
// callers: []
//------------------------------------------------------------

void ccid_bulk_complete_in(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_2 + 0x38);
  if (*(int *)(param_2 + 0x54) != 0) {
    *(undefined4 *)(lVar5 + 0x1c8) = 1;
  }
  uVar2 = _raw_spin_lock_irqsave(lVar5 + 0xdc);
  plVar4 = *(long **)(lVar5 + 0x220);
  lVar1 = param_2 + 0x40;
  uVar3 = __list_add_valid(lVar1,plVar4,lVar5 + 0x218);
  if ((uVar3 & 1) != 0) {
    *(long *)(lVar5 + 0x220) = lVar1;
    *(long *)(param_2 + 0x40) = lVar5 + 0x218;
    *(long **)(param_2 + 0x48) = plVar4;
    *plVar4 = lVar1;
  }
  _raw_spin_unlock_irqrestore(lVar5 + 0xdc,uVar2);
  __wake_up(lVar5 + 0x1f0,3,1,0);
  return;
}



//------------------------------------------------------------
// init_module @ 00102bc0 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  usb_function_register(&ccidusb_func);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102be8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  usb_function_unregister(&ccidusb_func);
  return;
}



//------------------------------------------------------------
// usb_function_register @ 00105000 size=1
// signature: undefined usb_function_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_unregister @ 00105008 size=1
// signature: undefined usb_function_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105018 size=1
// signature: undefined kmalloc_trace(void)
// callers: [ccid_set_inst_name, ccid_function_bind, ccid_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 00105020 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [ccid_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00105028 size=1
// signature: size_t strlen(char * __s)
// callers: [ccid_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00105030 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [ccid_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105038 size=1
// signature: undefined mutex_lock(void)
// callers: [ccid_set_inst_name, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00105040 size=1
// signature: undefined __class_create(void)
// callers: [ccid_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00105048 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [ccid_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105050 size=1
// signature: undefined mutex_unlock(void)
// callers: [ccid_set_inst_name, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105058 size=1
// signature: undefined _printk(void)
// callers: [ccid_bulk_read, ccid_set_inst_name, ccid_cdev_init, ccid_function_bind, ccid_function_set_alt, ccid_function_setup, ccid_ctrl_ioctl, ccid_bulk_write, ccid_notify_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00105060 size=1
// signature: undefined device_destroy(void)
// callers: [ccid_set_inst_name, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00105068 size=1
// signature: undefined cdev_del(void)
// callers: [ccid_set_inst_name, ccid_cdev_init, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 00105070 size=1
// signature: undefined ida_free(void)
// callers: [ccid_set_inst_name, ccid_cdev_init, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00105078 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [ccid_set_inst_name, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00105080 size=1
// signature: undefined class_destroy(void)
// callers: [ccid_set_inst_name, ccid_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105088 size=1
// signature: undefined kfree(void)
// callers: [ccid_bulk_read, ccid_set_inst_name, ccid_function_bind, ccid_request_free, ccid_free_inst, ccid_function_unbind, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105090 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ccid_bulk_read, ccid_set_inst_name, ccid_ctrl_read, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00105098 size=1
// signature: undefined ida_alloc_range(void)
// callers: [ccid_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001050a0 size=1
// signature: undefined cdev_init(void)
// callers: [ccid_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001050a8 size=1
// signature: undefined cdev_add(void)
// callers: [ccid_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001050b0 size=1
// signature: undefined device_create(void)
// callers: [ccid_cdev_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 001050b8 size=1
// signature: undefined init_wait_entry(void)
// callers: [ccid_bulk_read, ccid_ctrl_read, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 001050c0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [ccid_bulk_read, ccid_ctrl_read, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001050c8 size=1
// signature: undefined schedule(void)
// callers: [ccid_bulk_read, ccid_ctrl_read, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001050d0 size=1
// signature: undefined finish_wait(void)
// callers: [ccid_bulk_read, ccid_ctrl_read, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001050d8 size=1
// signature: undefined __check_object_size(void)
// callers: [ccid_bulk_read, ccid_ctrl_read, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001050f0 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [ccid_bulk_read, ccid_ctrl_read, ccid_ctrl_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00105100 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [ccid_ctrl_ioctl, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_queue @ 00105108 size=1
// signature: undefined usb_ep_queue(void)
// callers: [ccid_bulk_read, ccid_function_setup, ccid_ctrl_ioctl, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00105110 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [ccid_ctrl_ioctl, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00105118 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [ccid_bulk_read, ccid_bulk_open, ccid_function_bind, ccid_bulk_complete_in, ccid_ctrl_open, ccid_function_unbind, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00105120 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [ccid_bulk_read, ccid_bulk_open, ccid_function_bind, ccid_bulk_complete_in, ccid_ctrl_open, ccid_function_unbind, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_dequeue @ 00105128 size=1
// signature: undefined usb_ep_dequeue(void)
// callers: [ccid_bulk_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_free_request @ 00105130 size=1
// signature: undefined usb_ep_free_request(void)
// callers: [ccid_bulk_read, ccid_function_bind, ccid_request_free, ccid_function_unbind, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105138 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [ccid_function_unbind, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105140 size=1
// signature: undefined __list_add_valid(void)
// callers: [ccid_function_bind, ccid_bulk_complete_in, ccid_bulk_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_put_function_instance @ 00105148 size=1
// signature: undefined usb_put_function_instance(void)
// callers: [ccid_attr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_put_function_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_interface_id @ 00105150 size=1
// signature: undefined usb_interface_id(void)
// callers: [ccid_function_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_interface_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_autoconfig @ 00105158 size=1
// signature: undefined usb_ep_autoconfig(void)
// callers: [ccid_function_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_autoconfig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_assign_descriptors @ 00105160 size=1
// signature: undefined usb_assign_descriptors(void)
// callers: [ccid_function_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_assign_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_alloc_request @ 00105168 size=1
// signature: undefined usb_ep_alloc_request(void)
// callers: [ccid_function_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_free_all_descriptors @ 00105170 size=1
// signature: undefined usb_free_all_descriptors(void)
// callers: [ccid_function_bind, ccid_function_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_free_all_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_ep_by_speed @ 00105178 size=1
// signature: undefined config_ep_by_speed(void)
// callers: [ccid_function_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_ep_by_speed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_enable @ 00105180 size=1
// signature: undefined usb_ep_enable(void)
// callers: [ccid_function_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_disable @ 00105188 size=1
// signature: undefined usb_ep_disable(void)
// callers: [ccid_function_set_alt, ccid_function_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00105190 size=1
// signature: undefined __wake_up(void)
// callers: [ccid_bulk_complete_out, ccid_function_setup, ccid_bulk_complete_in, ccid_function_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



