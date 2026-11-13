// Decompiled by Ghidra 12.2
// Program: goodix_fod_mmi.ko
// Image base: 00100000

//------------------------------------------------------------
// gf_ioctl @ 00100884 size=1924
// signature: undefined gf_ioctl(void)
// callers: [gf_compat_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gf_ioctl(undefined8 param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  size_t sVar4;
  long lVar5;
  uint uVar6;
  undefined8 *puVar7;
  uint uVar8;
  ulong uVar9;
  undefined1 local_44;
  undefined1 auStack_43 [7];
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  uVar6 = (uint)param_2;
  local_38 = 0;
  local_3c = 0;
  auStack_43[3] = 0x19;
  local_44 = 0;
  local_30 = 0;
  if ((uVar6 & 0xff00) != 0x6700) {
    uVar2 = 0xffffffffffffffed;
    goto switchD_00100958_caseD_6701;
  }
  if ((int)uVar6 < 0) {
    puVar7 = (undefined8 *)sp_el0;
LAB_001008e8:
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar9 <= 0x8000000000 - (ulong)(uVar6 >> 0x10 & 0x3fff)) goto LAB_00100920;
    goto LAB_00100918;
  }
  if ((uVar6 >> 0x1e & 1) != 0) {
    puVar7 = (undefined8 *)sp_el0;
    goto LAB_001008e8;
  }
LAB_00100920:
  uVar2 = 0;
  uVar8 = (uint)_cpu_hwcaps;
  if (0x4001670e < (int)uVar6) {
    if (0x4004670d < (int)uVar6) {
      if (uVar6 == 0x4004670e) {
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar9 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar9 < 0x7ffffffffd) {
          if ((uVar8 >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar1 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          sVar4 = __arch_copy_from_user(puVar7,&local_3c,param_3 & 0xff7fffffffffffff,4);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            uVar1 = ttbr1_el1;
            ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          if (sVar4 == 0) {
            nav_event_input(local_3c);
            uVar2 = 0;
            goto switchD_00100958_caseD_6701;
          }
        }
        else {
          sVar4 = 4;
        }
        memset(auStack_43 + (0xb - sVar4),0,sVar4);
        puVar3 = &DAT_00102d08;
LAB_00100f84:
        _printk(puVar3);
LAB_00100918:
        uVar2 = 0xfffffffffffffff2;
        goto switchD_00100958_caseD_6701;
      }
      if (uVar6 == 0x40086709) {
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar9 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar9 < 0x7ffffffff9) {
          if ((uVar8 >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar1 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          sVar4 = __arch_copy_from_user(puVar7,&local_38,param_3 & 0xff7fffffffffffff,8);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar9 = daif;
            if ((uVar9 & 0x80) == 0) {
              uVar1 = daif;
              daif = uVar1 | 0xc0;
            }
            uVar1 = ttbr1_el1;
            ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar1 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar9;
          }
          if (sVar4 == 0) {
            gf_kernel_key_input(&local_38);
            uVar2 = 0;
            goto switchD_00100958_caseD_6701;
          }
        }
        else {
          sVar4 = 8;
        }
        memset((void *)((long)&local_30 - sVar4),0,sVar4);
        puVar3 = &DAT_00102dcc;
        goto LAB_00100f84;
      }
      if (uVar6 != 0x4008670d) goto switchD_00100958_caseD_6705;
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar9 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (0x7ffffffff8 < uVar9) goto LAB_00100918;
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      lVar5 = __arch_copy_from_user(puVar7,&local_30,param_3 & 0xff7fffffffffffff,8);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      if (lVar5 != 0) goto LAB_00100918;
      _printk(&DAT_00103242,local_30 & 0xff);
      _printk(&DAT_00103269,local_30._1_1_);
      param_2 = local_30 >> 0x10 & 0xff;
      puVar3 = &DAT_001031b2;
      goto LAB_00100aa4;
    }
    if (uVar6 != 0x4001670f) {
      if (uVar6 == 0x40046705) goto switchD_00100958_caseD_6701;
      goto switchD_00100958_caseD_6705;
    }
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar9 >> 0x27 != 0) {
      sVar4 = 1;
LAB_00100f20:
      memset(auStack_43 + -sVar4,0,sVar4);
      puVar3 = &DAT_00102f94;
      goto LAB_00100f84;
    }
    if ((uVar8 >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar7 = (undefined8 *)puVar7[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar7;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    sVar4 = __arch_copy_from_user(puVar7,&local_44,param_3 & 0xff7fffffffffffff,1);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    if (sVar4 != 0) goto LAB_00100f20;
    goto LAB_00100c54;
  }
  switch(uVar6) {
  case 0x6701:
  case 0x6706:
  case 0x670a:
  case 0x670c:
    break;
  case 0x6702:
    gf_hw_reset(&gf,3);
    uVar2 = 0;
    break;
  case 0x6703:
    if (_DAT_00103628 == 0) {
      irq_set_irq_wake(DAT_00103624,1);
      enable_irq(DAT_00103624);
      uVar2 = 0;
      _DAT_00103628 = 1;
      break;
    }
    puVar3 = &DAT_0010342d;
    goto LAB_00100f10;
  case 0x6704:
    if (_DAT_00103628 != 0) {
      _DAT_00103628 = 0;
      disable_irq(DAT_00103624);
      irq_set_irq_wake(DAT_00103624,0);
      uVar2 = 0;
      break;
    }
    puVar3 = &DAT_0010303d;
LAB_00100f10:
    _printk(puVar3);
    uVar2 = 0;
    break;
  case 0x6705:
  case 0x6709:
  case 0x670b:
    goto switchD_00100958_caseD_6705;
  case 0x6707:
    gf_power_on(&gf);
    uVar2 = 0;
    break;
  case 0x6708:
    gf_power_off(&gf);
    uVar2 = 0;
    break;
  default:
    if (uVar6 == 0x80016700) {
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar9 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar9 >> 0x27 == 0) {
        if ((uVar8 >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          puVar7 = (undefined8 *)puVar7[1];
          uVar1 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar7;
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        lVar5 = __arch_copy_to_user(puVar7,param_3 & 0xff7fffffffffffff,auStack_43 + 3,1);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          uVar1 = ttbr1_el1;
          ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        uVar2 = 0;
        if (lVar5 != 0) {
          uVar2 = 0xfffffffffffffff2;
        }
        break;
      }
      goto LAB_00100918;
    }
    if (uVar6 == 0x8001670b) break;
    goto switchD_00100958_caseD_6705;
  }
switchD_00100958_caseD_6701:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
switchD_00100958_caseD_6705:
  puVar3 = &DAT_00102f02;
LAB_00100aa4:
  _printk(puVar3,param_2);
LAB_00100c54:
  uVar2 = 0;
  goto switchD_00100958_caseD_6701;
}



//------------------------------------------------------------
// gf_compat_ioctl @ 00101084 size=32
// signature: undefined gf_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

void gf_compat_ioctl(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  gf_ioctl(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// gf_open @ 001010a8 size=284
// signature: undefined gf_open(void)
// callers: []
//------------------------------------------------------------

undefined8 gf_open(long param_1,long param_2)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  
  mutex_lock(device_list_lock);
  ppuVar2 = &device_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &device_list) {
      _printk(&DAT_00103348,*(uint *)(param_1 + 0x4c) & 0xfffff);
      uVar1 = 0xfffffffa;
      goto LAB_00101190;
    }
  } while (*(int *)(ppuVar2 + -1) != *(int *)(param_1 + 0x4c));
  _printk(&DAT_001031d5);
  *(int *)(ppuVar2 + 6) = *(int *)(ppuVar2 + 6) + 1;
  *(undefined ***)(param_2 + 0xd8) = ppuVar2 + -1;
  nonseekable_open(param_1,param_2);
  _printk(&DAT_00103314,*(undefined4 *)((long)ppuVar2 + 0x5c));
  if (*(int *)(ppuVar2 + 6) == 1) {
    if (*(int *)(ppuVar2 + 0xc) == 0) {
      irq_set_irq_wake(*(undefined4 *)((long)ppuVar2 + 0x5c),1);
      enable_irq(*(undefined4 *)((long)ppuVar2 + 0x5c));
      *(undefined4 *)(ppuVar2 + 0xc) = 1;
    }
    else {
      _printk(&DAT_0010342d);
    }
  }
  gf_hw_reset(ppuVar2 + -1,3);
  uVar1 = 0;
LAB_00101190:
  mutex_unlock(device_list_lock);
  return uVar1;
}



//------------------------------------------------------------
// gf_release @ 001011c8 size=164
// signature: undefined gf_release(void)
// callers: []
//------------------------------------------------------------

undefined8 gf_release(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  mutex_lock(device_list_lock);
  lVar2 = *(long *)(param_2 + 0xd8);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  iVar1 = *(int *)(lVar2 + 0x38) + -1;
  *(int *)(lVar2 + 0x38) = iVar1;
  if (iVar1 == 0) {
    _printk(&DAT_00102e12,*(undefined4 *)(lVar2 + 100));
    if (*(int *)(lVar2 + 0x68) == 0) {
      _printk(&DAT_0010303d);
    }
    else {
      *(undefined4 *)(lVar2 + 0x68) = 0;
      disable_irq(*(undefined4 *)(lVar2 + 100));
      irq_set_irq_wake(*(undefined4 *)(lVar2 + 100),0);
    }
    gf_power_off(lVar2);
  }
  mutex_unlock(device_list_lock);
  return 0;
}



//------------------------------------------------------------
// gf_disable_irq @ 0010126c size=84
// signature: undefined gf_disable_irq(void)
// callers: [gf_probe]
//------------------------------------------------------------

void gf_disable_irq(long param_1)

{
  if (*(int *)(param_1 + 0x68) == 0) {
    _printk(&DAT_0010303d);
  }
  else {
    *(undefined4 *)(param_1 + 0x68) = 0;
    disable_irq(*(undefined4 *)(param_1 + 100));
    irq_set_irq_wake(*(undefined4 *)(param_1 + 100),0);
  }
  return;
}



//------------------------------------------------------------
// gf_kernel_key_input @ 001012c0 size=308
// signature: undefined gf_kernel_key_input(void)
// callers: [gf_ioctl]
//------------------------------------------------------------

void gf_kernel_key_input(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 1) {
    iVar2 = 0x66;
  }
  else if (iVar1 == 5) {
    iVar2 = 0xd4;
  }
  else if (iVar1 == 2) {
    iVar2 = 0x74;
  }
  else {
    iVar2 = iVar1;
  }
  _printk(&DAT_00102e6e,"gf_kernel_key_input",iVar2,iVar1,param_1[1]);
  iVar1 = *param_1;
  if ((iVar1 == 5) || (iVar1 == 2)) {
    if (param_1[1] != 1) {
      return;
    }
    input_event(DAT_001035f0,1,iVar2,1);
    input_event(DAT_001035f0,0,0,0);
    input_event(DAT_001035f0,1,iVar2,0);
    input_event(DAT_001035f0,0,0,0);
    iVar1 = *param_1;
  }
  if (iVar1 == 1) {
    input_event(DAT_001035f0,1,iVar2,param_1[1] != 0);
    input_event(DAT_001035f0,0,0,0);
  }
  return;
}



//------------------------------------------------------------
// nav_event_input @ 001013f4 size=240
// signature: undefined nav_event_input(void)
// callers: [gf_ioctl]
//------------------------------------------------------------

void nav_event_input(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0x6c;
  switch(param_1) {
  case 1:
  case 2:
    goto switchD_00101428_caseD_1;
  case 3:
    uVar1 = 0x67;
    break;
  case 4:
    break;
  case 5:
    uVar1 = 0x69;
    break;
  case 6:
    uVar1 = 0x6a;
    break;
  case 7:
    uVar1 = 0x72;
    break;
  case 8:
    uVar1 = 0xd8;
    break;
  case 9:
    uVar1 = 0xd9;
    break;
  case 10:
    uVar1 = 0x73;
    break;
  default:
    _printk(&DAT_00102c82,"nav_event_input",param_1);
    uVar1 = 0;
  }
  input_event(DAT_001035f0,1,uVar1,1);
  input_event(DAT_001035f0,0,0,0);
  input_event(DAT_001035f0,1,uVar1,0);
  input_event(DAT_001035f0,0,0,0);
switchD_00101428_caseD_1:
  return;
}



//------------------------------------------------------------
// gf_probe @ 001014e8 size=1140
// signature: undefined gf_probe(void)
// callers: []
//------------------------------------------------------------

int gf_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong uVar9;
  
  iVar6 = -0x16;
  DAT_001035c8 = &DAT_001035c8;
  DAT_001035d0 = (undefined **)&DAT_001035c8;
  DAT_001035fc = 0xffffffeaffffffea;
  DAT_00103604 = 0xffffffea;
  DAT_00103650 = 0;
  DAT_001035d8 = param_1;
  iVar5 = gf_parse_dts(&gf);
  if (iVar5 != 0) goto LAB_0010158c;
  mutex_lock(device_list_lock);
  uVar9 = ~(minors | 0xffffffff00000000);
  uVar9 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
  uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
  uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
  uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
  uVar7 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10;
  uVar9 = 0x20;
  if ((minors | 0xffffffff00000000) != 0xffffffffffffffff) {
    uVar9 = LZCOUNT(uVar7 >> 0x20 | uVar7 << 0x20);
  }
  if (uVar9 < 0x20) {
    gf = (uint)uVar9 | SPIDEV_MAJOR << 0x14;
    uVar7 = device_create(gf_class,DAT_001035d8 + 0x10,gf,&gf,"goodix_fp");
    puVar4 = device_list;
    if ((uVar7 < 0xfffffffffffff001) || ((uVar7 & 0xffffffff) == 0)) {
      Hint_Prefetch(0x103658,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(0x103658,0x10);
        if (bVar3) {
          cVar2 = ExclusiveMonitorsStatus();
          minors = minors | 1L << (uVar9 & 0x3f);
        }
      } while (cVar2 != '\0');
      uVar9 = __list_add_valid(&DAT_001035c8,&device_list,device_list);
      if ((uVar9 & 1) != 0) {
        *(undefined8 ***)(puVar4 + 8) = &DAT_001035c8;
        DAT_001035c8 = (undefined8 *)puVar4;
        DAT_001035d0 = &device_list;
        device_list = (undefined *)&DAT_001035c8;
      }
      mutex_unlock(device_list_lock);
      DAT_001035f0 = (undefined8 *)input_allocate_device();
      if (DAT_001035f0 != (undefined8 *)0x0) {
        input_set_capability(DAT_001035f0,1,0x66);
        input_set_capability(DAT_001035f0,1,0x8b);
        input_set_capability(DAT_001035f0,1,0x9e);
        input_set_capability(DAT_001035f0,1,0x74);
        input_set_capability(DAT_001035f0,1,0x67);
        input_set_capability(DAT_001035f0,1,0x6c);
        input_set_capability(DAT_001035f0,1,0x6a);
        input_set_capability(DAT_001035f0,1,0x69);
        input_set_capability(DAT_001035f0,1,0xd4);
        input_set_capability(DAT_001035f0,1,0x72);
        input_set_capability(DAT_001035f0,1,0x73);
        input_set_capability(DAT_001035f0,1,0xd9);
        input_set_capability(DAT_001035f0,1,0xd8);
        *DAT_001035f0 = "qwerty";
        iVar6 = input_register_device(DAT_001035f0);
        if (iVar6 == 0) goto LAB_00101610;
        _printk(&DAT_00102d48);
        goto LAB_001018a0;
      }
      _printk(&DAT_00102c1f,"gf_probe");
      iVar6 = -0xc;
    }
    else {
      gf = 0;
      mutex_unlock(device_list_lock);
LAB_00101610:
      DAT_00103638 = goodix_noti_block;
      DAT_00103640 = DAT_00102a68;
      DAT_00103648 = DAT_00102a70;
      uVar8 = gf_irq_num(&gf);
      DAT_00103624 = (int)uVar8;
      iVar6 = request_threaded_irq(uVar8,0,gf_irq,0x2001,&DAT_00103266,&gf);
      if (iVar6 == 0) {
        param_1 = param_1 + 0x10;
        gf_disable_irq(&gf);
        device_set_wakeup_capable(param_1,1);
        device_wakeup_enable(param_1);
        iVar6 = sysfs_create_group(param_1,attribute_group);
        if (iVar6 == 0) {
          _printk(&DAT_00102da0,1,2,4,2);
          _printk(&DAT_00103456,0);
          return 0;
        }
        _printk(&DAT_00103566,iVar6);
        device_wakeup_disable(param_1);
        device_set_wakeup_capable(param_1,0);
        if (DAT_00103624 != 0) {
          free_irq(DAT_00103624,&gf);
        }
      }
      else {
        _printk(&DAT_00103112,DAT_00103624);
      }
      input_unregister_device(DAT_001035f0);
LAB_001018a0:
      if (DAT_001035f0 != (undefined8 *)0x0) {
        input_free_device();
      }
    }
    if (gf == 0) goto LAB_0010158c;
    _printk(&DAT_00102cba,iVar6);
    mutex_lock(device_list_lock);
    uVar9 = __list_del_entry_valid(&DAT_001035c8);
    if ((uVar9 & 1) != 0) {
      DAT_001035c8[1] = DAT_001035d0;
      *DAT_001035d0 = (undefined *)DAT_001035c8;
    }
    DAT_001035c8 = (undefined8 *)0xdead000000000100;
    DAT_001035d0 = (undefined **)0xdead000000000122;
    device_destroy(gf_class,gf);
    uVar9 = (ulong)gf;
    puVar1 = &minors + ((ulong)(gf >> 6) & 0x3fff);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & (1L << (uVar9 & 0x3f) ^ 0xffffffffffffffffU);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  else {
    iVar6 = -0x13;
  }
  mutex_unlock(device_list_lock);
LAB_0010158c:
  gf_cleanup(&gf);
  return iVar6;
}



//------------------------------------------------------------
// gf_remove @ 00101980 size=304
// signature: undefined gf_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 gf_remove(void)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  
  lVar1 = DAT_001035d8 + 0x10;
  sysfs_remove_group(lVar1,attribute_group);
  device_wakeup_disable(lVar1);
  device_set_wakeup_capable(lVar1,0);
  if (DAT_00103624 != 0) {
    free_irq(DAT_00103624,&gf);
  }
  if (DAT_001035f0 != 0) {
    input_unregister_device();
  }
  mutex_lock(device_list_lock);
  uVar5 = __list_del_entry_valid(&DAT_001035c8);
  if ((uVar5 & 1) != 0) {
    *(long **)(DAT_001035c8 + 8) = DAT_001035d0;
    *DAT_001035d0 = DAT_001035c8;
  }
  DAT_001035c8 = 0xdead000000000100;
  DAT_001035d0 = (long *)0xdead000000000122;
  device_destroy(gf_class,gf);
  uVar5 = (ulong)gf;
  puVar2 = &minors + ((ulong)(gf >> 6) & 0x3fff);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar4) {
      *puVar2 = *puVar2 & (1L << (uVar5 & 0x3f) ^ 0xffffffffffffffffU);
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (DAT_001035f8 == 0) {
    gf_cleanup(&gf);
  }
  mutex_unlock(device_list_lock);
  return 0;
}



//------------------------------------------------------------
// gf_irq @ 00101ac4 size=108
// signature: undefined gf_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 gf_irq(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 1;
  pm_wakeup_dev_event(*(long *)(param_2 + 0x18) + 0x10,500,0);
  sendnlmsg(local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// goodix_fb_state_chg_callback @ 00101b34 size=8
// signature: undefined goodix_fb_state_chg_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_fb_state_chg_callback(void)

{
  return 1;
}



//------------------------------------------------------------
// dev_enable_set @ 00101b40 size=8
// signature: undefined dev_enable_set(void)
// callers: []
//------------------------------------------------------------

undefined8 dev_enable_set(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



//------------------------------------------------------------
// sendnlmsg @ 00101c14 size=232
// signature: undefined sendnlmsg(void)
// callers: [gf_irq]
//------------------------------------------------------------

int sendnlmsg(undefined1 *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  iVar1 = -0x13;
  if ((param_1 != (undefined1 *)0x0) && (nl_sk != 0 && pid != 0)) {
    lVar2 = __alloc_skb(0x30,0xa20,0,0xffffffff);
    if (lVar2 == 0) {
      iVar1 = -0xc;
    }
    else if (((*(int *)(lVar2 + 0x74) == 0) &&
             (0x2f < *(int *)(lVar2 + 0xd4) - *(int *)(lVar2 + 0xd0))) &&
            (lVar3 = __nlmsg_put(lVar2,0,0,0,0x20,0), lVar3 != 0)) {
      *(undefined8 *)(lVar2 + 0x34) = 0;
      *(undefined1 *)(lVar3 + 0x10) = *param_1;
      iVar1 = netlink_unicast(nl_sk,lVar2,pid,0x40);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
    else {
      kfree_skb_reason(lVar2,1);
      iVar1 = -0x5a;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// netlink_init @ 00101d00 size=152
// signature: undefined netlink_init(void)
// callers: [init_module]
//------------------------------------------------------------

void netlink_init(void)

{
  bool bVar1;
  long lVar2;
  undefined8 local_48;
  code *pcStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_28 = 0;
  uStack_20 = 0;
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  pcStack_40 = nl_data_ready;
  nl_sk = __netlink_kernel_create(&init_net,0x19,&__this_module,&local_48);
  bVar1 = nl_sk == 0;
  if (bVar1) {
    _printk(&DAT_00102ce9);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// nl_data_ready @ 00101d9c size=140
// signature: undefined nl_data_ready(void)
// callers: []
//------------------------------------------------------------

void nl_data_ready(long param_1)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  
  puVar1 = (uint *)(param_1 + 0xec);
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
    uVar5 = 2;
  }
  else {
    if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_00101dd0;
    uVar5 = 1;
  }
  refcount_warn_saturate(puVar1,uVar5);
LAB_00101dd0:
  if (0xf < *(uint *)(param_1 + 0x70)) {
    pid = *(undefined4 *)(*(long *)(param_1 + 0xe0) + 0xc);
  }
  kfree_skb_reason(param_1,1);
  return;
}



//------------------------------------------------------------
// netlink_exit @ 00101e38 size=64
// signature: undefined netlink_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void netlink_exit(void)

{
  if (nl_sk != 0) {
    netlink_kernel_release();
    nl_sk = 0;
  }
  _printk(&DAT_00102f38);
  return;
}



//------------------------------------------------------------
// gf_parse_dts @ 00101e7c size=792
// signature: undefined gf_parse_dts(void)
// callers: [gf_probe]
//------------------------------------------------------------

int gf_parse_dts(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x2f8);
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined8 *)(param_1 + 0x50) = 0;
  lVar1 = *(long *)(param_1 + 0x18) + 0x10;
  lVar5 = of_find_property(uVar8,"rgltr-ctrl-support",0);
  if (lVar5 == 0) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    _printk(&DAT_00102fdc);
    if (*(int *)(param_1 + 0x48) != 0) goto LAB_00101ecc;
  }
  else {
    *(undefined4 *)(param_1 + 0x48) = 1;
LAB_00101ecc:
    uVar6 = regulator_get(lVar1,"fp,vdd");
    *(ulong *)(param_1 + 0x50) = uVar6;
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
      *(undefined8 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      _printk(&DAT_0010313e);
    }
    else {
      iVar2 = of_property_read_variable_u32_array
                        (uVar8,"fp,voltage-range",(int *)(param_1 + 0x58),2,0);
      iVar3 = iVar2;
      if (-1 < iVar2) {
        iVar3 = 0;
      }
      if (iVar2 < 0) {
        *(undefined8 *)(param_1 + 0x58) = 0xffffffffffffffff;
      }
      iVar2 = regulator_count_voltages(*(undefined8 *)(param_1 + 0x50));
      if (0 < iVar2) {
        if ((0 < *(int *)(param_1 + 0x58)) && (0 < *(int *)(param_1 + 0x5c))) {
          iVar3 = regulator_set_voltage(*(undefined8 *)(param_1 + 0x50));
        }
        if (iVar3 != 0) {
          _printk(&DAT_00103372,"gf_parse_dts",iVar3);
        }
      }
    }
  }
  uVar4 = of_get_named_gpio_flags(uVar8,"fp-gpio-ven",0,0);
  *(uint *)(param_1 + 0x44) = uVar4;
  if ((int)uVar4 < 0) {
    _printk(&DAT_00102f4e);
  }
  else if (uVar4 < 0x200) {
    iVar3 = devm_gpio_request(lVar1,uVar4,"goodix_pwr");
    if (iVar3 != 0) {
      _printk(&DAT_0010329c,iVar3);
      goto LAB_00102160;
    }
    uVar7 = gpio_to_desc(*(undefined4 *)(param_1 + 0x44));
    gpiod_direction_output_raw(uVar7,1);
  }
  gf_power_on(param_1);
  iVar3 = of_get_named_gpio_flags(uVar8,"fp-gpio-reset",0,0);
  *(int *)(param_1 + 0x40) = iVar3;
  if (iVar3 < 0) {
    _printk(&DAT_001032cb);
    return *(int *)(param_1 + 0x40);
  }
  iVar3 = devm_gpio_request(lVar1,iVar3,"goodix_reset");
  if (iVar3 == 0) {
    uVar7 = gpio_to_desc(*(undefined4 *)(param_1 + 0x40));
    gpiod_direction_output_raw(uVar7,1);
    iVar3 = of_get_named_gpio_flags(uVar8,"fp-gpio-irq",0,0);
    *(int *)(param_1 + 0x3c) = iVar3;
    if (iVar3 < 0) {
      _printk(&DAT_0010315c);
      return *(int *)(param_1 + 0x3c);
    }
    iVar3 = devm_gpio_request(lVar1,iVar3,"goodix_irq");
    if (iVar3 == 0) {
      gpio_to_desc(*(undefined4 *)(param_1 + 0x3c));
      gpiod_direction_input();
      return 0;
    }
    _printk(&DAT_001033fe,iVar3);
    if (*(uint *)(param_1 + 0x40) < 0x200) {
      *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
    }
  }
  else {
    _printk(&DAT_0010307e,iVar3);
  }
  gf_power_off(param_1);
  if (*(uint *)(param_1 + 0x44) < 0x200) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
    _printk(&DAT_00103539);
  }
LAB_00102160:
  if ((*(ulong *)(param_1 + 0x50) != 0) && (*(ulong *)(param_1 + 0x50) < 0xfffffffffffff001)) {
    _printk(&DAT_001032f0,"gf_parse_dts");
    regulator_put(*(undefined8 *)(param_1 + 0x50));
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  return iVar3;
}



//------------------------------------------------------------
// gf_power_on @ 00102198 size=220
// signature: undefined gf_power_on(void)
// callers: [gf_ioctl, gf_parse_dts]
//------------------------------------------------------------

undefined4 gf_power_on(long param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    if (*(int *)(param_1 + 0x48) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      if ((*(ulong *)(param_1 + 0x50) != 0) && (*(ulong *)(param_1 + 0x50) < 0xfffffffffffff001)) {
        uVar1 = regulator_enable();
        _printk(&DAT_00103213,"gf_power_on",uVar1);
      }
    }
    if (*(uint *)(param_1 + 0x44) < 0x200) {
      uVar2 = gpio_to_desc();
      gpiod_direction_output_raw(uVar2,1);
      _printk(&DAT_001030be,"gf_power_on",*(undefined4 *)(param_1 + 0x44));
    }
    *(undefined4 *)(param_1 + 0x70) = 1;
    if ((*(int *)(param_1 + 0x48) != 0) || (*(uint *)(param_1 + 0x44) < 0x200)) {
      usleep_range_state(11000,12000,2);
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gf_power_off @ 00102278 size=180
// signature: undefined gf_power_off(void)
// callers: [gf_ioctl, gf_cleanup, gf_release, gf_parse_dts]
//------------------------------------------------------------

undefined4 gf_power_off(long param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x48) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      if ((*(ulong *)(param_1 + 0x50) != 0) && (*(ulong *)(param_1 + 0x50) < 0xfffffffffffff001)) {
        uVar1 = regulator_disable();
        _printk(&DAT_001033c2,"gf_power_off",uVar1);
      }
    }
    if (*(uint *)(param_1 + 0x44) < 0x200) {
      uVar2 = gpio_to_desc();
      gpiod_direction_output_raw(uVar2,0);
      _printk(&DAT_00103497,"gf_power_off",*(undefined4 *)(param_1 + 0x44));
    }
    *(undefined4 *)(param_1 + 0x70) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gf_cleanup @ 00102330 size=268
// signature: undefined gf_cleanup(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

void gf_cleanup(long param_1)

{
  int iVar1;
  
  _printk(&DAT_001030af,"gf_cleanup");
  if (*(uint *)(param_1 + 0x3c) < 0x200) {
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    _printk(&DAT_00102f71);
    iVar1 = *(int *)(param_1 + 0x48);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x48);
  }
  if (((iVar1 != 0) || (*(uint *)(param_1 + 0x44) < 0x200)) &&
     (gf_power_off(param_1), *(uint *)(param_1 + 0x44) < 0x200)) {
    *(undefined4 *)(param_1 + 0x44) = 0xffffffff;
    _printk(&DAT_00103539);
  }
  if (*(uint *)(param_1 + 0x40) < 0x200) {
    *(undefined4 *)(param_1 + 0x40) = 0xffffffff;
    _printk(&DAT_001031ee);
    iVar1 = *(int *)(param_1 + 0x48);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x48);
  }
  if (((iVar1 != 0) && (*(ulong *)(param_1 + 0x50) != 0)) &&
     (*(ulong *)(param_1 + 0x50) < 0xfffffffffffff001)) {
    _printk(&DAT_00102d7b,"gf_cleanup");
    regulator_put(*(undefined8 *)(param_1 + 0x50));
    *(undefined8 *)(param_1 + 0x50) = 0;
  }
  return;
}



//------------------------------------------------------------
// gf_hw_reset @ 00102440 size=176
// signature: undefined gf_hw_reset(void)
// callers: [gf_open, gf_ioctl]
//------------------------------------------------------------

undefined8 gf_hw_reset(long param_1,uint param_2)

{
  undefined8 uVar1;
  ulong uVar2;
  
  if (param_1 == 0) {
    _printk(&DAT_001034bc);
    uVar1 = 0xffffffed;
  }
  else {
    _printk(&DAT_00102ee4,"gf_hw_reset");
    uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x40));
    gpiod_direction_output_raw(uVar1,0);
    uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x40));
    gpiod_set_raw_value(uVar1,0);
    __const_udelay(0xc49c08);
    uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x40));
    gpiod_set_raw_value(uVar1,1);
    if (param_2 != 0) {
      uVar2 = (ulong)param_2;
      do {
        uVar2 = uVar2 - 1;
        __const_udelay(0x418958);
      } while (uVar2 != 0);
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gf_irq_num @ 001024f4 size=60
// signature: undefined gf_irq_num(void)
// callers: [gf_probe]
//------------------------------------------------------------

undefined8 gf_irq_num(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_001034bc);
    uVar1 = 0xffffffed;
  }
  else {
    gpio_to_desc(*(undefined4 *)(param_1 + 0x3c));
    uVar1 = gpiod_to_irq();
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 00102534 size=492
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  ulong uVar4;
  ulong uVar5;
  char *local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = of_find_node_opts_by_path("/chosen",0);
  local_40 = (char *)0x0;
  if (lVar2 == 0) {
    _printk(&DAT_00102eb7);
  }
  else {
    iVar1 = of_property_read_string(lVar2,"bootargs",&local_40);
    if (iVar1 == 0) {
      pcVar3 = strstr(local_40,"androidboot.disable_hw=1");
      _printk(&DAT_00102bf3,pcVar3);
      _printk(&DAT_001030e3,pcVar3 != (char *)0x0);
      if (pcVar3 != (char *)0x0) {
        _printk(&DAT_001034d3);
        uVar5 = 0xffffffed;
        goto LAB_001026ec;
      }
    }
    else {
      _printk(&DAT_001030e3,0);
    }
  }
  uVar4 = __register_chrdev(SPIDEV_MAJOR,0,0x100,"goodix_fp_spi",&gf_fops);
  uVar5 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    _printk(&DAT_00102e3b);
  }
  else {
    SPIDEV_MAJOR = (int)uVar4;
    gf_class = __class_create(&__this_module,"goodix_fp",&gf_init___key);
    if (gf_class < 0xfffffffffffff001) {
      iVar1 = __platform_driver_register(&gf_driver,&__this_module);
      if (iVar1 < 0) {
        class_destroy(gf_class);
        __unregister_chrdev(SPIDEV_MAJOR,0,0x100,PTR_s_goodix_fp_00103698);
        _printk(&DAT_001034fa);
      }
      netlink_init();
      _printk(&DAT_0010300e,iVar1);
      uVar5 = 0;
    }
    else {
      __unregister_chrdev(SPIDEV_MAJOR,0,0x100,PTR_s_goodix_fp_00103698);
      _printk(&DAT_0010317f);
      uVar5 = gf_class & 0xffffffff;
    }
  }
LAB_001026ec:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// cleanup_module @ 00102724 size=88
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  netlink_exit();
  platform_driver_unregister(&gf_driver);
  class_destroy(gf_class);
  __unregister_chrdev(SPIDEV_MAJOR,0,0x100,PTR_s_goodix_fp_00103698);
  return;
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00105000 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105008 size=1
// signature: undefined _printk(void)
// callers: [gf_power_off, init_module, gf_kernel_key_input, gf_power_on, gf_irq_num, gf_cleanup, gf_parse_dts, gf_open, gf_hw_reset, netlink_init, gf_ioctl, gf_probe, nav_event_input, gf_release, netlink_exit, gf_disable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00105010 size=1
// signature: undefined of_property_read_string(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 00105018 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_chrdev @ 00105020 size=1
// signature: undefined __register_chrdev(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00105028 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 00105030 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105038 size=1
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
// class_destroy @ 00105040 size=1
// signature: undefined class_destroy(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [netlink_init, init_module, gf_ioctl, gf_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00105050 size=1
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
// __arch_copy_from_user @ 00105068 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [gf_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00105070 size=1
// signature: undefined disable_irq(void)
// callers: [gf_ioctl, gf_release, gf_disable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00105078 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [gf_open, gf_ioctl, gf_release, gf_disable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00105080 size=1
// signature: undefined enable_irq(void)
// callers: [gf_open, gf_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00105088 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [gf_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00105090 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [gf_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001050a0 size=1
// signature: undefined mutex_lock(void)
// callers: [gf_open, gf_probe, gf_release, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nonseekable_open @ 001050a8 size=1
// signature: undefined nonseekable_open(void)
// callers: [gf_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001050b0 size=1
// signature: undefined mutex_unlock(void)
// callers: [gf_open, gf_probe, gf_release, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 001050b8 size=1
// signature: undefined input_event(void)
// callers: [gf_kernel_key_input, nav_event_input]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001050c0 size=1
// signature: undefined device_create(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 001050c8 size=1
// signature: undefined request_threaded_irq(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001050d0 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 001050d8 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 001050e0 size=1
// signature: undefined sysfs_create_group(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001050e8 size=1
// signature: undefined __list_add_valid(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_allocate_device @ 001050f0 size=1
// signature: undefined input_allocate_device(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_capability @ 001050f8 size=1
// signature: undefined input_set_capability(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 00105100 size=1
// signature: undefined input_register_device(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00105108 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00105110 size=1
// signature: undefined free_irq(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 00105118 size=1
// signature: undefined input_unregister_device(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_free_device @ 00105120 size=1
// signature: undefined input_free_device(void)
// callers: [gf_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_free_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105128 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00105130 size=1
// signature: undefined device_destroy(void)
// callers: [gf_probe, gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00105138 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [gf_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 00105140 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [gf_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00105148 size=1
// signature: undefined __alloc_skb(void)
// callers: [sendnlmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 00105150 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [nl_data_ready, sendnlmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __nlmsg_put @ 00105158 size=1
// signature: undefined __nlmsg_put(void)
// callers: [sendnlmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __nlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 00105160 size=1
// signature: undefined netlink_unicast(void)
// callers: [sendnlmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __netlink_kernel_create @ 00105170 size=1
// signature: undefined __netlink_kernel_create(void)
// callers: [netlink_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __netlink_kernel_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00105178 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [nl_data_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_kernel_release @ 00105180 size=1
// signature: undefined netlink_kernel_release(void)
// callers: [netlink_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_kernel_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105188 size=1
// signature: undefined of_find_property(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 00105190 size=1
// signature: undefined regulator_get(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105198 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 001051a0 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001051a8 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 001051b0 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request @ 001051b8 size=1
// signature: undefined devm_gpio_request(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 001051c0 size=1
// signature: undefined gpio_to_desc(void)
// callers: [gf_hw_reset, gf_power_off, gf_power_on, gf_irq_num, gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 001051c8 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [gf_hw_reset, gf_power_off, gf_power_on, gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 001051d0 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 001051d8 size=1
// signature: undefined regulator_put(void)
// callers: [gf_cleanup, gf_parse_dts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001051e0 size=1
// signature: undefined regulator_enable(void)
// callers: [gf_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001051e8 size=1
// signature: undefined usleep_range_state(void)
// callers: [gf_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001051f0 size=1
// signature: undefined regulator_disable(void)
// callers: [gf_power_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 001051f8 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [gf_hw_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00105200 size=1
// signature: undefined __const_udelay(void)
// callers: [gf_hw_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 00105208 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [gf_irq_num]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



