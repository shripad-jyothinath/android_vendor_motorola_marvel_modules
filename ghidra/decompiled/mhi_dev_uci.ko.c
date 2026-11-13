// Decompiled by Ghidra 12.2
// Program: mhi_dev_uci.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 00100554 size=216
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __register_chrdev(0,0,0x100,"mhi_uci",mhidev_fops);
  if (-1 < iVar1) {
    DAT_00102c20 = iVar1;
    DAT_00102c18 = __class_create(&__this_module,"mhi_uci",&mhi_uci_init___key);
    if (DAT_00102c18 < 0xfffffffffffff001) {
      __mutex_init(&DAT_00102be8,"&mhi_uci_drv.lock",&mhi_uci_init___key_6);
      mhi_uci_drv = &mhi_uci_drv;
      DAT_00102be0 = &mhi_uci_drv;
      iVar1 = __mhi_driver_register(&mhi_uci_driver,&__this_module);
      if (iVar1 != 0) {
        class_destroy(DAT_00102c18);
      }
    }
    else {
      iVar1 = -0x13;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// mhi_uci_read @ 00100630 size=1284
// signature: undefined mhi_uci_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong mhi_uci_read(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  ulong uVar11;
  long *plVar12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  if (param_2 == 0) {
    uVar11 = 0xffffffffffffffea;
    goto LAB_001008ac;
  }
  lVar13 = *(long *)(param_1 + 0xd8);
  uVar10 = *(undefined8 *)(lVar13 + 0x20);
  if ((*(long *)(lVar13 + 0x160) != 0) && (*(int *)(lVar13 + 0x168) == 0)) {
    ipc_log_string(*(long *)(lVar13 + 0x160),"%s[D][%s] Client provided buf len:%lu\n",&DAT_0010234c
                   ,"mhi_uci_read",param_3);
  }
  lVar1 = lVar13 + 0x110;
  mutex_lock(lVar1);
  lVar2 = lVar13 + 0xe8;
  _raw_spin_lock_bh(lVar2);
  if (*(char *)(lVar13 + 0x154) == '\0') {
    _raw_spin_unlock_bh(lVar2);
LAB_0010089c:
    iVar5 = -0x200;
  }
  else {
    plVar14 = *(long **)(lVar13 + 0x100);
    if (plVar14 == (long *)0x0) {
      plVar15 = (long *)(lVar13 + 0xf0);
      if ((long *)*plVar15 == plVar15) {
        if ((*(long *)(lVar13 + 0x160) != 0) && (*(int *)(lVar13 + 0x168) == 0)) {
          ipc_log_string(*(long *)(lVar13 + 0x160),"%s[D][%s] No data available to read waiting\n",
                         &DAT_0010234c,"mhi_uci_read");
        }
        _raw_spin_unlock_bh(lVar2);
        if ((*(char *)(lVar13 + 0x154) != '\0') && ((long *)*plVar15 == plVar15)) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          while ((lVar7 = prepare_to_wait_event(lVar13 + 0xd0,&local_90,1),
                 *(char *)(lVar13 + 0x154) != '\0' && ((long *)*plVar15 == plVar15))) {
            if (lVar7 != 0) {
              if ((int)lVar7 != -0x200) goto LAB_00100a1c;
              if ((*(long *)(lVar13 + 0x160) != 0) && (*(uint *)(lVar13 + 0x168) < 2)) {
                ipc_log_string(*(long *)(lVar13 + 0x160),"%s[I][%s] Exit signal caught for node\n",
                               &DAT_0010234c,"mhi_uci_read");
              }
              goto LAB_0010089c;
            }
            schedule();
          }
          finish_wait(lVar13 + 0xd0,&local_90);
        }
LAB_00100a1c:
        _raw_spin_lock_bh(lVar2);
        if (*(char *)(lVar13 + 0x154) != '\0') {
          plVar14 = *(long **)(lVar13 + 0x100);
          if (plVar14 != (long *)0x0) goto LAB_001006cc;
          goto LAB_001008f8;
        }
        if ((*(long *)(lVar13 + 0x160) != 0) && (*(uint *)(lVar13 + 0x168) < 2)) {
          ipc_log_string(*(long *)(lVar13 + 0x160),"%s[I][%s] node is disabled\n",&DAT_0010234c,
                         "mhi_uci_read");
        }
        iVar5 = -0x200;
      }
      else {
LAB_001008f8:
        plVar12 = (long *)*plVar15;
        iVar5 = -5;
        if ((plVar12 != plVar15) && (plVar14 = plVar12 + -2, plVar14 != (long *)0x0)) {
          uVar11 = __list_del_entry_valid(plVar12);
          if ((uVar11 & 1) != 0) {
            lVar7 = *plVar12;
            plVar15 = (long *)plVar12[1];
            *(long **)(lVar7 + 8) = plVar15;
            *plVar15 = lVar7;
          }
          *plVar12 = -0x2152ffffffffff00;
          plVar12[1] = -0x2152fffffffffede;
          *(long **)(lVar13 + 0x100) = plVar14;
          *(long *)(lVar13 + 0x108) = plVar12[-1];
          if ((*(long *)(lVar13 + 0x160) != 0) && (*(int *)(lVar13 + 0x168) == 0)) {
            ipc_log_string(*(long *)(lVar13 + 0x160),"%s[D][%s] Got pkt of size:%zu\n",&DAT_0010234c
                           ,"mhi_uci_read");
            plVar14 = *(long **)(lVar13 + 0x100);
          }
          goto LAB_001006cc;
        }
      }
    }
    else {
LAB_001006cc:
      _raw_spin_unlock_bh(lVar2);
      uVar8 = *(ulong *)(lVar13 + 0x108);
      uVar11 = uVar8;
      if (param_3 <= uVar8) {
        uVar11 = param_3;
      }
      if (uVar11 >> 0x1f != 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100b18);
        (*pcVar4)();
      }
      lVar7 = *plVar14 + (plVar14[1] - uVar8);
      __check_object_size(lVar7,uVar11,1);
      puVar9 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
         (uVar8 = param_2, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
        uVar8 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar6 = uVar11;
      if (uVar8 <= 0x8000000000 - uVar11) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar6 = daif;
            daif = uVar6 | 0xc0;
          }
          puVar9 = (undefined8 *)puVar9[1];
          uVar6 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar9;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
        uVar6 = __arch_copy_to_user(puVar9,param_2 & 0xff7fffffffffffff,lVar7,uVar11);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar3 = daif;
            daif = uVar3 | 0xc0;
          }
          uVar3 = ttbr1_el1;
          ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar3 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
      }
      iVar5 = (int)uVar6;
      if (iVar5 != 0) goto LAB_001008a0;
      if ((*(long *)(lVar13 + 0x160) != 0) && (*(int *)(lVar13 + 0x168) == 0)) {
        ipc_log_string(*(long *)(lVar13 + 0x160),"%s[D][%s] Copied %lu of %lu bytes\n",&DAT_0010234c
                       ,"mhi_uci_read",uVar11,*(undefined8 *)(lVar13 + 0x108));
      }
      lVar7 = *(long *)(lVar13 + 0x108) - uVar11;
      *(long *)(lVar13 + 0x108) = lVar7;
      if (lVar7 != 0) {
LAB_00100850:
        if ((*(long *)(lVar13 + 0x160) != 0) && (*(int *)(lVar13 + 0x168) == 0)) {
          ipc_log_string(*(long *)(lVar13 + 0x160),"%s[D][%s] Returning %lu bytes\n",&DAT_0010234c,
                         "mhi_uci_read",uVar11);
        }
        mutex_unlock(lVar1);
        goto LAB_001008ac;
      }
      _raw_spin_lock_bh(lVar2);
      *(undefined8 *)(lVar13 + 0x100) = 0;
      if (*(char *)(lVar13 + 0x154) == '\0') {
        iVar5 = -0x200;
      }
      else {
        iVar5 = mhi_queue_buf(uVar10,2,*plVar14,*(undefined8 *)(lVar13 + 0x148),2);
        if (iVar5 == 0) {
          _raw_spin_unlock_bh(lVar2);
          goto LAB_00100850;
        }
      }
      _printk(&DAT_001021a1,"mhi_uci_read");
      if ((*(long *)(lVar13 + 0x160) != 0) && (*(uint *)(lVar13 + 0x168) < 3)) {
        ipc_log_string(*(long *)(lVar13 + 0x160),"%s[E][%s] Failed to recycle element\n",
                       &DAT_0010234c,"mhi_uci_read");
      }
      kfree(*plVar14);
    }
    _raw_spin_unlock_bh(lVar2);
  }
LAB_001008a0:
  mutex_unlock(lVar1);
  uVar11 = (ulong)iVar5;
LAB_001008ac:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// mhi_uci_write @ 00100b54 size=1172
// signature: undefined mhi_uci_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long mhi_uci_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  code *pcVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  undefined4 uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  undefined8 uVar15;
  ulong uVar16;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  lVar13 = -0x16;
  local_68 = *(long *)(lVar1 + 0x638);
  if ((param_2 != 0) && (param_3 != 0)) {
    lVar14 = *(long *)(param_1 + 0xd8);
    lVar1 = lVar14 + 0xa0;
    uVar15 = *(undefined8 *)(lVar14 + 0x20);
    mutex_lock(lVar1);
    lVar2 = lVar14 + 0x78;
    _raw_spin_lock_bh(lVar2);
    if (*(char *)(lVar14 + 0x154) == '\0') {
      _raw_spin_unlock_bh(lVar2);
LAB_00100e94:
      iVar8 = -0x200;
LAB_00100f44:
      mutex_unlock(lVar1);
      lVar13 = (long)iVar8;
    }
    else {
      lVar3 = lVar14 + 0x60;
      if ((*(long *)(lVar14 + 0x160) != 0) && (*(int *)(lVar14 + 0x168) == 0)) {
        ipc_log_string(*(long *)(lVar14 + 0x160),"%s[D][%s] Enter: to xfer:%lu bytes\n",
                       &DAT_0010234c,"mhi_uci_write",param_3);
      }
      lVar13 = 0;
      puVar5 = (undefined8 *)sp_el0;
      do {
        _raw_spin_unlock_bh(lVar2);
        if (*(char *)(lVar14 + 0x154) == '\0') {
LAB_00100e9c:
          if (*(long *)(lVar14 + 0x160) != 0) {
            if (*(uint *)(lVar14 + 0x168) < 2) {
              ipc_log_string(*(long *)(lVar14 + 0x160),
                             "%s[I][%s] Exit signal caught for node or not enabled\n",&DAT_0010234c,
                             "mhi_uci_write");
            }
            goto LAB_00100e94;
          }
          uVar10 = 0xfffffe00;
LAB_00100f40:
          iVar8 = (int)uVar10;
          goto LAB_00100f44;
        }
        iVar8 = mhi_get_free_desc_count(uVar15,1);
        if (iVar8 < 1) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          lVar9 = prepare_to_wait_event(lVar3,&local_90,1);
          if (*(char *)(lVar14 + 0x154) != '\0') {
            do {
              iVar8 = mhi_get_free_desc_count(uVar15,1);
              if (0 < iVar8) break;
              if (lVar9 != 0) {
                if ((int)lVar9 == -0x200) goto LAB_00100e9c;
                goto LAB_00100cb8;
              }
              schedule();
              lVar9 = prepare_to_wait_event(lVar3,&local_90,1);
            } while (*(char *)(lVar14 + 0x154) != '\0');
          }
          finish_wait(lVar3,&local_90);
        }
LAB_00100cb8:
        if (*(char *)(lVar14 + 0x154) == '\0') goto LAB_00100e9c;
        uVar16 = *(ulong *)(lVar14 + 0x140);
        uVar4 = param_3;
        if (uVar16 <= param_3) {
          uVar4 = uVar16;
        }
        lVar9 = __kmalloc(uVar4,0xcc0);
        if (lVar9 == 0) {
          _printk(&DAT_001022d2,"mhi_uci_write",uVar4);
          if (*(long *)(lVar14 + 0x160) == 0) {
            uVar10 = 0xfffffff4;
            goto LAB_00100f40;
          }
          if (*(uint *)(lVar14 + 0x168) < 3) {
            ipc_log_string(*(long *)(lVar14 + 0x160),"%s[E][%s] Failed to allocate memory %lu\n",
                           &DAT_0010234c,"mhi_uci_write",uVar4);
            iVar8 = -0xc;
          }
          else {
            iVar8 = -0xc;
          }
          goto LAB_00100f44;
        }
        if (uVar4 >> 0x1f != 0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x100e3c);
          (*pcVar7)();
        }
        __check_object_size(lVar9,uVar4,0);
        if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
           (uVar12 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
          uVar12 = param_2 & (long)(param_2 << 8) >> 8;
        }
        uVar10 = uVar4;
        if (uVar12 <= 0x8000000000 - uVar4) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar10 = daif;
            if ((uVar10 & 0x80) == 0) {
              uVar12 = daif;
              daif = uVar12 | 0xc0;
            }
            uVar12 = ttbr1_el1;
            ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar12 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar5[1];
            InstructionSynchronizationBarrier();
            daif = uVar10;
          }
          uVar10 = __arch_copy_from_user(lVar9,param_2 & 0xff7fffffffffffff,uVar4);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar6 = daif;
              daif = uVar6 | 0xc0;
            }
            uVar6 = ttbr1_el1;
            ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar6 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
        }
        if ((uVar10 != 0) && (memset((void *)(lVar9 + (uVar4 - uVar10)),0,uVar10), (int)uVar10 != 0)
           ) {
          kfree(lVar9);
          goto LAB_00100f40;
        }
        _raw_spin_lock_bh(lVar2);
        if (*(char *)(lVar14 + 0x154) == '\0') {
          iVar8 = -0x200;
LAB_00100ee0:
          kfree(lVar9);
          _raw_spin_unlock_bh(lVar2);
          goto LAB_00100f44;
        }
        uVar11 = 4;
        if (param_3 <= uVar16 || iVar8 < 2) {
          uVar11 = 2;
        }
        iVar8 = mhi_queue_buf(uVar15,1,lVar9,uVar4,uVar11);
        if (iVar8 != 0) goto LAB_00100ee0;
        param_3 = param_3 - uVar4;
        param_2 = param_2 + uVar4;
        lVar13 = uVar4 + lVar13;
      } while (param_3 != 0);
      _raw_spin_unlock_bh(lVar2);
      mutex_unlock(lVar1);
      if ((*(long *)(lVar14 + 0x160) != 0) && (*(int *)(lVar14 + 0x168) == 0)) {
        ipc_log_string(*(long *)(lVar14 + 0x160),"%s[D][%s] Exit: Number of bytes xferred:%lu\n",
                       &DAT_0010234c,"mhi_uci_write",lVar13);
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar13;
}



//------------------------------------------------------------
// mhi_uci_poll @ 00101008 size=520
// signature: undefined mhi_uci_poll(void)
// callers: []
//------------------------------------------------------------

uint mhi_uci_poll(long param_1,undefined8 *param_2)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xd8);
  uVar3 = *(undefined8 *)(lVar5 + 0x20);
  if (param_2 != (undefined8 *)0x0) {
    pcVar2 = (code *)*param_2;
    if (lVar5 + 0xd0 != 0 && pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101064);
        (*pcVar2)();
      }
      (*pcVar2)(param_1,lVar5 + 0xd0,param_2);
      DataMemoryBarrier(2,3);
      pcVar2 = (code *)*param_2;
    }
    if ((lVar5 + 0x60 != 0) && (pcVar2 != (code *)0x0)) {
      if (*(int *)(pcVar2 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10109c);
        (*pcVar2)();
      }
      (*pcVar2)(param_1,lVar5 + 0x60,param_2);
      DataMemoryBarrier(2,3);
    }
  }
  _raw_spin_lock_bh(lVar5 + 0xe8);
  if (*(char *)(lVar5 + 0x154) == '\0') {
    uVar4 = 8;
  }
  else {
    if ((*(long **)(lVar5 + 0xf0) == (long *)(lVar5 + 0xf0)) && (*(long *)(lVar5 + 0x100) == 0)) {
      uVar4 = 0;
      iVar1 = *(int *)(lVar5 + 0x158);
    }
    else {
      if ((*(long *)(lVar5 + 0x160) != 0) && (*(int *)(lVar5 + 0x168) == 0)) {
        ipc_log_string(*(long *)(lVar5 + 0x160),"%s[D][%s] Client can read from node\n",
                       &DAT_0010234c,"mhi_uci_poll");
      }
      uVar4 = 0x41;
      iVar1 = *(int *)(lVar5 + 0x158);
    }
    if (iVar1 != 0) {
      if ((*(long *)(lVar5 + 0x160) != 0) && (*(int *)(lVar5 + 0x168) == 0)) {
        ipc_log_string(*(long *)(lVar5 + 0x160),"%s[D][%s] Line status changed\n",&DAT_0010234c,
                       "mhi_uci_poll");
      }
      uVar4 = uVar4 | 2;
    }
  }
  _raw_spin_unlock_bh(lVar5 + 0xe8);
  _raw_spin_lock_bh(lVar5 + 0x78);
  if (*(char *)(lVar5 + 0x154) == '\0') {
    uVar4 = uVar4 | 8;
  }
  else {
    iVar1 = mhi_get_free_desc_count(uVar3,1);
    if (0 < iVar1) {
      if ((*(long *)(lVar5 + 0x160) != 0) && (*(int *)(lVar5 + 0x168) == 0)) {
        ipc_log_string(*(long *)(lVar5 + 0x160),"%s[D][%s] Client can write to node\n",&DAT_0010234c
                       ,"mhi_uci_poll");
      }
      uVar4 = uVar4 | 0x104;
    }
  }
  _raw_spin_unlock_bh(lVar5 + 0x78);
  if ((*(long *)(lVar5 + 0x160) != 0) && (*(uint *)(lVar5 + 0x168) < 2)) {
    ipc_log_string(*(long *)(lVar5 + 0x160),
                   "%s[I][%s] Client attempted to poll, returning mask 0x%x\n",&DAT_0010234c,
                   "mhi_uci_poll",uVar4);
  }
  return uVar4;
}



//------------------------------------------------------------
// mhi_uci_ioctl @ 00101214 size=188
// signature: undefined mhi_uci_ioctl(void)
// callers: []
//------------------------------------------------------------

ulong mhi_uci_ioctl(long param_1,int param_2,undefined8 param_3)

{
  long lVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xd8);
  lVar1 = *(long *)(lVar3 + 0x20);
  mutex_lock(lVar3 + 0x30);
  if (param_2 == 0x5415) {
    _raw_spin_lock_bh(lVar3 + 0xe8);
    uVar2 = (ulong)*(uint *)(lVar3 + 0x158);
  }
  else {
    if (*(char *)(lVar3 + 0x154) == '\0') {
      uVar2 = 0xfffffffffffffdfd;
      goto LAB_001012ac;
    }
    uVar2 = mhi_device_ioctl(lVar1,param_2,param_3);
    if (uVar2 != 0) goto LAB_001012ac;
    _raw_spin_lock_bh(lVar3 + 0xe8);
    *(undefined4 *)(lVar3 + 0x158) = *(undefined4 *)(lVar1 + 0x3d0);
  }
  _raw_spin_unlock_bh(lVar3 + 0xe8);
LAB_001012ac:
  mutex_unlock(lVar3 + 0x30);
  return uVar2;
}



//------------------------------------------------------------
// mhi_uci_open @ 001012d4 size=884
// signature: undefined mhi_uci_open(void)
// callers: []
//------------------------------------------------------------

int mhi_uci_open(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  int iVar9;
  long *plVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  
  mutex_lock(&DAT_00102be8);
  puVar12 = &mhi_uci_drv;
  do {
    puVar12 = (undefined8 *)*puVar12;
    if (puVar12 == &mhi_uci_drv) goto LAB_00101394;
  } while (*(int *)(puVar12 + 2) != *(int *)(param_1 + 0x4c));
  if (puVar12 == (undefined8 *)0x0) {
LAB_00101394:
    iVar5 = -5;
    goto LAB_00101494;
  }
  mutex_lock(puVar12 + 6);
  if (*(char *)((long)puVar12 + 0x154) == '\0') {
    _printk(&DAT_00102638,"mhi_uci_open");
    if ((puVar12[0x2c] == 0) || (2 < *(uint *)(puVar12 + 0x2d))) {
      iVar5 = -5;
    }
    else {
      ipc_log_string(puVar12[0x2c],"%s[E][%s] Node exist, but not in active state!\n",&DAT_0010234c,
                     "mhi_uci_open");
      iVar5 = -5;
    }
    goto LAB_0010148c;
  }
  iVar5 = *(int *)(puVar12 + 0x2a) + 1;
  *(int *)(puVar12 + 0x2a) = iVar5;
  if (puVar12[0x2c] == 0) {
    if (iVar5 == 2) goto LAB_001013a8;
LAB_00101480:
    iVar5 = 0;
    *(undefined8 **)(param_2 + 0xd8) = puVar12;
  }
  else {
    if (*(uint *)(puVar12 + 0x2d) < 2) {
      ipc_log_string(puVar12[0x2c],"%s[I][%s] Node open, ref counts %u\n",&DAT_0010234c,
                     "mhi_uci_open");
      iVar5 = *(int *)(puVar12 + 0x2a);
    }
    if (iVar5 != 2) goto LAB_00101480;
LAB_001013a8:
    if ((puVar12[0x2c] != 0) && (*(uint *)(puVar12 + 0x2d) < 2)) {
      ipc_log_string(puVar12[0x2c],"%s[I][%s] Starting channel\n",&DAT_0010234c,"mhi_uci_open");
    }
    iVar5 = mhi_prepare_for_transfer(puVar12[4]);
    if (iVar5 == 0) {
      uVar11 = puVar12[4];
      iVar6 = mhi_get_free_desc_count(uVar11,2);
      if (0 < iVar6) {
        uVar1 = puVar12[0x28];
        lVar2 = puVar12[0x29];
        iVar9 = 0;
        do {
          lVar7 = __kmalloc(uVar1,0xcc0);
          if (lVar7 == 0) {
            iVar5 = -0xc;
            goto LAB_001014d4;
          }
          *(long *)(lVar7 + lVar2) = lVar7;
          if ((puVar12[0x2c] != 0) && (*(int *)(puVar12 + 0x2d) == 0)) {
            ipc_log_string(puVar12[0x2c],"%s[D][%s] Allocated buf %d of %d size %ld\n",&DAT_0010234c
                           ,"mhi_queue_inbound",iVar9,iVar6,lVar2);
          }
          iVar5 = mhi_queue_buf(uVar11,2,lVar7,lVar2,2);
          if (iVar5 != 0) {
            kfree(lVar7);
            _printk(&DAT_0010246c,"mhi_queue_inbound",iVar9);
            if ((puVar12[0x2c] != 0) && (*(uint *)(puVar12 + 0x2d) < 3)) {
              ipc_log_string(puVar12[0x2c],"%s[E][%s] Failed to queue buffer %d\n",&DAT_0010234c,
                             "mhi_queue_inbound",iVar9);
            }
            goto LAB_001014d4;
          }
          iVar9 = iVar9 + 1;
        } while (iVar6 != iVar9);
        goto LAB_00101480;
      }
      iVar5 = -5;
LAB_001014d4:
      *(int *)(puVar12 + 0x2a) = *(int *)(puVar12 + 0x2a) + -1;
      mhi_unprepare_from_transfer(puVar12[4]);
      plVar4 = (long *)puVar12[0x1e];
      while (plVar4 != puVar12 + 0x1e) {
        plVar10 = (long *)*plVar4;
        uVar8 = __list_del_entry_valid(plVar4);
        if ((uVar8 & 1) != 0) {
          lVar2 = *plVar4;
          plVar3 = (long *)plVar4[1];
          *(long **)(lVar2 + 8) = plVar3;
          *plVar3 = lVar2;
        }
        *plVar4 = -0x2152ffffffffff00;
        plVar4[1] = -0x2152fffffffffede;
        kfree(plVar4[-2]);
        plVar4 = plVar10;
      }
    }
    else {
      _printk(&DAT_001023f0,"mhi_uci_open");
      if ((puVar12[0x2c] != 0) && (*(uint *)(puVar12 + 0x2d) < 3)) {
        ipc_log_string(puVar12[0x2c],"%s[E][%s] Error starting transfer channels\n",&DAT_0010234c,
                       "mhi_uci_open");
      }
      *(int *)(puVar12 + 0x2a) = *(int *)(puVar12 + 0x2a) + -1;
    }
  }
LAB_0010148c:
  mutex_unlock(puVar12 + 6);
LAB_00101494:
  mutex_unlock(&DAT_00102be8);
  return iVar5;
}



//------------------------------------------------------------
// mhi_uci_release @ 0010164c size=344
// signature: undefined mhi_uci_release(void)
// callers: []
//------------------------------------------------------------

undefined8 mhi_uci_release(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  long *plVar7;
  
  lVar6 = *(long *)(param_2 + 0xd8);
  mutex_lock(&DAT_00102be8);
  mutex_lock(lVar6 + 0x30);
  iVar3 = *(int *)(lVar6 + 0x150) + -1;
  *(int *)(lVar6 + 0x150) = iVar3;
  if (iVar3 == 1) {
    if ((*(long *)(lVar6 + 0x160) != 0) && (*(uint *)(lVar6 + 0x168) < 2)) {
      ipc_log_string(*(long *)(lVar6 + 0x160),"%s[I][%s] Last client left, closing node\n",
                     &DAT_0010234c,"mhi_uci_release");
    }
    if (*(char *)(lVar6 + 0x154) != '\0') {
      mhi_unprepare_from_transfer(*(undefined8 *)(lVar6 + 0x20));
    }
    plVar4 = *(long **)(lVar6 + 0xf0);
    while (plVar4 != (long *)(lVar6 + 0xf0)) {
      plVar7 = (long *)*plVar4;
      uVar5 = __list_del_entry_valid(plVar4);
      if ((uVar5 & 1) != 0) {
        lVar1 = *plVar4;
        plVar2 = (long *)plVar4[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      kfree(plVar4[-2]);
      plVar4 = plVar7;
    }
    if (*(undefined8 **)(lVar6 + 0x100) != (undefined8 *)0x0) {
      kfree(**(undefined8 **)(lVar6 + 0x100));
    }
    *(undefined8 *)(lVar6 + 0x100) = 0;
  }
  if ((*(long *)(lVar6 + 0x160) != 0) && (*(uint *)(lVar6 + 0x168) < 2)) {
    ipc_log_string(*(long *)(lVar6 + 0x160),"%s[I][%s] exit: ref_count:%d\n",&DAT_0010234c,
                   "mhi_uci_release",*(undefined4 *)(lVar6 + 0x150));
  }
  mutex_unlock(lVar6 + 0x30);
  mutex_unlock(&DAT_00102be8);
  return 0;
}



//------------------------------------------------------------
// mhi_uci_probe @ 001017a8 size=884
// signature: undefined mhi_uci_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 mhi_uci_probe(long param_1,long param_2)

{
  long *plVar1;
  long *plVar2;
  ulong *puVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  ulong uVar7;
  int iVar8;
  long *plVar9;
  ulong uVar10;
  long lVar11;
  char *param3;
  undefined4 uVar12;
  uint uVar13;
  ulong uVar14;
  char local_88 [32];
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  local_88[0x10] = '\0';
  local_88[0x11] = '\0';
  local_88[0x12] = '\0';
  local_88[0x13] = '\0';
  local_88[0x14] = '\0';
  local_88[0x15] = '\0';
  local_88[0x16] = '\0';
  local_88[0x17] = '\0';
  local_88[0x18] = '\0';
  local_88[0x19] = '\0';
  local_88[0x1a] = '\0';
  local_88[0x1b] = '\0';
  local_88[0x1c] = '\0';
  local_88[0x1d] = '\0';
  local_88[0x1e] = '\0';
  local_88[0x1f] = '\0';
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\0';
  local_88[4] = '\0';
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  local_88[8] = '\0';
  local_88[9] = '\0';
  local_88[10] = '\0';
  local_88[0xb] = '\0';
  local_88[0xc] = '\0';
  local_88[0xd] = '\0';
  local_88[0xe] = '\0';
  local_88[0xf] = '\0';
  plVar9 = (long *)kmalloc_trace(__raw_spin_unlock_irq,0xdc0,0x170);
  if (plVar9 == (long *)0x0) {
    uVar12 = 0xfffffff4;
  }
  else {
    plVar1 = plVar9 + 6;
    __mutex_init(plVar1,"&uci_dev->mutex",&mhi_uci_probe___key);
    plVar9[4] = param_1;
    uVar7 = uci_minors;
    uVar14 = (~uci_minors & 0xaaaaaaaaaaaaaaaa) >> 1 | (~uci_minors & 0x5555555555555555) << 1;
    uVar14 = (uVar14 & 0xcccccccccccccccc) >> 2 | (uVar14 & 0x3333333333333333) << 2;
    uVar14 = (uVar14 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar14 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar14 = (uVar14 & 0xff00ff00ff00ff00) >> 8 | (uVar14 & 0xff00ff00ff00ff) << 8;
    uVar14 = (uVar14 & 0xffff0000ffff0000) >> 0x10 | (uVar14 & 0xffff0000ffff) << 0x10;
    uVar14 = LZCOUNT(uVar14 >> 0x20 | uVar14 << 0x20);
    uVar13 = (uint)uVar14;
    if (uVar13 < 0x40) {
      plVar2 = (long *)(param_1 + 0x28);
      param3 = (char *)(*(undefined8 **)(param_1 + 0x88))[0xe];
      if (param3 == (char *)0x0) {
        param3 = (char *)**(undefined8 **)(param_1 + 0x88);
      }
      snprintf(local_88,0x20,"%s_pipe_%d",param3,*(int *)(param_1 + 0x3bc));
      mutex_lock(&DAT_00102be8);
      mutex_lock(plVar1);
      uVar6 = DAT_00102c18;
      uVar13 = uVar13 | DAT_00102c20 << 0x14;
      *(uint *)(plVar9 + 2) = uVar13;
      uVar10 = device_create(uVar6,plVar2,uVar13,plVar9,&DAT_00102324,local_88);
      plVar9[3] = uVar10;
      if (uVar10 < 0xfffffffffffff001) {
        puVar3 = &uci_minors + (uVar7 == 0xffffffffffffffff);
        Hint_Prefetch(puVar3,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
          if (bVar5) {
            *puVar3 = *puVar3 | 1L << (uVar14 & 0x3f);
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        lVar11 = *(long *)(param_1 + 0x98);
        if (lVar11 == 0) {
          lVar11 = *plVar2;
        }
        lVar11 = ipc_log_context_create(0x32,lVar11,0);
        plVar9[0x2c] = lVar11;
        *(undefined4 *)(plVar9 + 0x2d) = 2;
        iVar8 = sysfs_create_group(plVar2,mhi_uci_group);
        if (iVar8 != 0) {
          _printk(&DAT_00102385,"mhi_uci_probe");
          if ((plVar9[0x2c] != 0) && (*(uint *)(plVar9 + 0x2d) < 3)) {
            ipc_log_string(plVar9[0x2c],"%s[E][%s] Failed to create MHI UCI sysfs group\n",
                           &DAT_0010234c,"mhi_uci_probe");
          }
        }
        *(undefined4 *)(plVar9 + 0x1d) = 0;
        __mutex_init(plVar9 + 0x22,"&uci_chan->chan_lock",&mhi_uci_probe___key_44);
        __init_waitqueue_head(plVar9 + 0x1a,"&uci_chan->wq",&mhi_uci_probe___key_46);
        plVar9[0x1e] = (long)(plVar9 + 0x1e);
        plVar9[0x1f] = (long)(plVar9 + 0x1e);
        *(undefined4 *)(plVar9 + 0xf) = 0;
        __mutex_init(plVar9 + 0x14,"&uci_chan->chan_lock",&mhi_uci_probe___key_44);
        __init_waitqueue_head(plVar9 + 0xc,"&uci_chan->wq",&mhi_uci_probe___key_46);
        plVar9[0x10] = (long)(plVar9 + 0x10);
        plVar9[0x11] = (long)(plVar9 + 0x10);
        uVar14 = *(ulong *)(param_2 + 0x20);
        lVar11 = plVar9[0x2a];
        *(undefined1 *)((long)plVar9 + 0x154) = 1;
        *(long **)(param_1 + 0xc0) = plVar9;
        plVar2 = mhi_uci_drv;
        if (0xfffe < uVar14) {
          uVar14 = 0xffff;
        }
        *(int *)(plVar9 + 0x2a) = (int)lVar11 + 1;
        plVar9[0x28] = uVar14;
        plVar9[0x29] = uVar14 - 0x20;
        uVar14 = __list_add_valid(plVar9,&mhi_uci_drv,plVar2);
        if ((uVar14 & 1) != 0) {
          plVar2[1] = (long)plVar9;
          *plVar9 = (long)plVar2;
          plVar9[1] = (long)&mhi_uci_drv;
          mhi_uci_drv = plVar9;
        }
        mutex_unlock(plVar1);
        mutex_unlock(&DAT_00102be8);
        if ((plVar9[0x2c] != 0) && (*(uint *)(plVar9 + 0x2d) < 2)) {
          ipc_log_string(plVar9[0x2c],"%s[I][%s] channel:%s successfully probed\n",&DAT_0010234c,
                         "mhi_uci_probe",*(undefined8 *)(param_1 + 8));
        }
        uVar12 = 0;
      }
      else {
        mutex_unlock(plVar1);
        mutex_unlock(&DAT_00102be8);
        uVar12 = (undefined4)plVar9[3];
        kfree(plVar9);
      }
    }
    else {
      kfree(plVar9);
      uVar12 = 0xffffffe4;
    }
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// mhi_uci_remove @ 00101b38 size=476
// signature: undefined mhi_uci_remove(void)
// callers: []
//------------------------------------------------------------

void mhi_uci_remove(long param_1)

{
  long *plVar1;
  ulong *puVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  ulong uVar8;
  long *plVar9;
  
  plVar9 = *(long **)(param_1 + 0xc0);
  if ((plVar9[0x2c] != 0) && (*(uint *)(plVar9 + 0x2d) < 2)) {
    ipc_log_string(plVar9[0x2c],"%s[I][%s] Enter\n",&DAT_0010234c,"mhi_uci_remove");
  }
  mutex_lock(&DAT_00102be8);
  plVar1 = plVar9 + 6;
  mutex_lock(plVar1);
  _raw_spin_lock_irq(plVar9 + 0x1d);
  _raw_spin_lock_irq(plVar9 + 0xf);
  *(undefined1 *)((long)plVar9 + 0x154) = 0;
  _raw_spin_unlock_irq(plVar9 + 0xf);
  _raw_spin_unlock_irq(plVar9 + 0x1d);
  __wake_up(plVar9 + 0x1a,3,1,0);
  __wake_up(plVar9 + 0xc,3,1,0);
  device_destroy(DAT_00102c18,(int)plVar9[2]);
  plVar9[3] = 0;
  uVar8 = __list_del_entry_valid(plVar9);
  if ((uVar8 & 1) != 0) {
    lVar3 = *plVar9;
    plVar4 = (long *)plVar9[1];
    *(long **)(lVar3 + 8) = plVar4;
    *plVar4 = lVar3;
  }
  *plVar9 = -0x2152ffffffffff00;
  plVar9[1] = -0x2152fffffffffede;
  *(int *)(plVar9 + 0x2a) = (int)plVar9[0x2a] + -1;
  sysfs_remove_group(param_1 + 0x28,mhi_uci_group);
  if ((int)plVar9[0x2a] == 0) {
    mutex_unlock(plVar1);
    uVar5 = *(uint *)(plVar9 + 2);
    puVar2 = &uci_minors + ((ulong)(uVar5 >> 6) & 0x3fff);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar7) {
        *puVar2 = *puVar2 & (1L << ((ulong)uVar5 & 0x3f) ^ 0xffffffffffffffffU);
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    kfree(plVar9);
  }
  else {
    if ((plVar9[0x2c] != 0) && (*(uint *)(plVar9 + 0x2d) < 2)) {
      ipc_log_string(plVar9[0x2c],"%s[I][%s] Exit\n",&DAT_0010234c,"mhi_uci_remove");
    }
    mutex_unlock(plVar1);
  }
  mutex_unlock(&DAT_00102be8);
  return;
}



//------------------------------------------------------------
// mhi_ul_xfer_cb @ 00101d28 size=128
// signature: undefined mhi_ul_xfer_cb(void)
// callers: []
//------------------------------------------------------------

void mhi_ul_xfer_cb(long param_1,undefined8 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xc0);
  if ((*(long *)(lVar1 + 0x160) != 0) && (*(int *)(lVar1 + 0x168) == 0)) {
    ipc_log_string(*(long *)(lVar1 + 0x160),"%s[D][%s] status:%d xfer_len:%zu\n",&DAT_0010234c,
                   "mhi_ul_xfer_cb",*(undefined4 *)((long)param_2 + 0x14),param_2[1]);
  }
  kfree(*param_2);
  if (*(int *)((long)param_2 + 0x14) == 0) {
    __wake_up(lVar1 + 0x60,3,1,0);
  }
  return;
}



//------------------------------------------------------------
// mhi_dl_xfer_cb @ 00101dac size=288
// signature: undefined mhi_dl_xfer_cb(void)
// callers: []
//------------------------------------------------------------

void mhi_dl_xfer_cb(long param_1,long *param_2)

{
  long *plVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 *puVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0xc0);
  if ((*(long *)(lVar6 + 0x160) != 0) && (*(int *)(lVar6 + 0x168) == 0)) {
    ipc_log_string(*(long *)(lVar6 + 0x160),"%s[D][%s] status:%d receive_len:%zu\n",&DAT_0010234c,
                   "mhi_dl_xfer_cb",*(undefined4 *)((long)param_2 + 0x14),param_2[1]);
  }
  if (*(int *)((long)param_2 + 0x14) == -0x6b) {
    kfree(*param_2);
  }
  else {
    uVar3 = _raw_spin_lock_irqsave(lVar6 + 0xe8);
    plVar2 = (long *)(*param_2 + *(long *)(lVar6 + 0x148));
    *plVar2 = *param_2;
    plVar1 = plVar2 + 2;
    plVar2[1] = param_2[1];
    puVar5 = *(undefined8 **)(lVar6 + 0xf8);
    uVar4 = __list_add_valid(plVar1,puVar5,lVar6 + 0xf0);
    if ((uVar4 & 1) != 0) {
      *(long **)(lVar6 + 0xf8) = plVar1;
      *plVar1 = lVar6 + 0xf0;
      plVar2[3] = (long)puVar5;
      *puVar5 = plVar1;
    }
    _raw_spin_unlock_irqrestore(lVar6 + 0xe8,uVar3);
    if (*(long *)(param_1 + 0x170) != 0) {
      pm_wakeup_dev_event(param_1 + 0x28,0,1);
    }
    __wake_up(lVar6 + 0xd0,3,1,0);
  }
  return;
}



//------------------------------------------------------------
// mhi_status_cb @ 00101ed0 size=112
// signature: undefined mhi_status_cb(void)
// callers: []
//------------------------------------------------------------

void mhi_status_cb(long param_1,int param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_2 == 10) {
    lVar2 = *(long *)(param_1 + 0xc0);
    uVar1 = _raw_spin_lock_irqsave(lVar2 + 0xe8);
    *(undefined4 *)(lVar2 + 0x158) = *(undefined4 *)(param_1 + 0x3d0);
    _raw_spin_unlock_irqrestore(lVar2 + 0xe8,uVar1);
    __wake_up(lVar2 + 0xd0,3,1,0);
  }
  return;
}



//------------------------------------------------------------
// log_level_show @ 00101f44 size=104
// signature: undefined log_level_show(void)
// callers: []
//------------------------------------------------------------

long log_level_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    lVar3 = -5;
  }
  else {
    uVar1 = *(uint *)(*(long *)(param_1 + 0x98) + 0x168);
    if (uVar1 < 5) {
      pcVar4 = (&mhi_uci_log_level_str)[uVar1];
    }
    else {
      pcVar4 = "Mask all";
    }
    iVar2 = scnprintf(param_3,0x1000,"IPC log level begins from: %s\n",pcVar4);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// log_level_store @ 00101fb0 size=200
// signature: undefined log_level_store(void)
// callers: []
//------------------------------------------------------------

undefined8 log_level_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 < 0) {
    param_4 = 0xffffffffffffffea;
  }
  else if (lVar2 == 0) {
    param_4 = 0xfffffffffffffffb;
  }
  else {
    *(uint *)(lVar2 + 0x168) = local_2c;
    if ((*(long *)(lVar2 + 0x160) != 0) && (local_2c < 2)) {
      ipc_log_string(*(long *)(lVar2 + 0x160),"%s[I][%s] IPC log level changed to: %s\n",
                     &DAT_0010234c,"log_level_store",(&mhi_uci_log_level_str)[local_2c]);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cleanup_module @ 001020cc size=80
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (DAT_00102c20 != 0) {
    unregister_chrdev_region(DAT_00102c20 << 0x14);
    DAT_00102c20 = 0;
  }
  class_destroy(DAT_00102c18);
  mhi_driver_unregister(&mhi_uci_driver);
  return;
}



//------------------------------------------------------------
// __register_chrdev @ 00104000 size=1
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
// __class_create @ 00104008 size=1
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
// __mutex_init @ 00104010 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mhi_driver_register @ 00104018 size=1
// signature: undefined __mhi_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mhi_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00104020 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00104028 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_driver_unregister @ 00104030 size=1
// signature: undefined mhi_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00104038 size=1
// signature: undefined ipc_log_string(void)
// callers: [mhi_uci_release, log_level_store, mhi_uci_read, mhi_uci_write, mhi_uci_poll, mhi_ul_xfer_cb, mhi_uci_open, mhi_dl_xfer_cb, mhi_uci_remove, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104040 size=1
// signature: undefined mutex_lock(void)
// callers: [mhi_uci_release, mhi_uci_read, mhi_uci_ioctl, mhi_uci_write, mhi_uci_open, mhi_uci_remove, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 00104048 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [mhi_uci_read, mhi_uci_ioctl, mhi_uci_write, mhi_uci_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 00104050 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [mhi_uci_read, mhi_uci_ioctl, mhi_uci_write, mhi_uci_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00104058 size=1
// signature: undefined __check_object_size(void)
// callers: [mhi_uci_read, mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00104070 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [mhi_uci_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_queue_buf @ 00104078 size=1
// signature: undefined mhi_queue_buf(void)
// callers: [mhi_uci_read, mhi_uci_write, mhi_uci_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_queue_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104080 size=1
// signature: undefined mutex_unlock(void)
// callers: [mhi_uci_release, mhi_uci_read, mhi_uci_ioctl, mhi_uci_write, mhi_uci_open, mhi_uci_remove, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104088 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mhi_uci_release, mhi_uci_read, mhi_uci_open, mhi_uci_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00104090 size=1
// signature: undefined init_wait_entry(void)
// callers: [mhi_uci_read, mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00104098 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [mhi_uci_read, mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001040a0 size=1
// signature: undefined schedule(void)
// callers: [mhi_uci_read, mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001040a8 size=1
// signature: undefined finish_wait(void)
// callers: [mhi_uci_read, mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040b0 size=1
// signature: undefined _printk(void)
// callers: [mhi_uci_read, mhi_uci_write, mhi_uci_open, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040b8 size=1
// signature: undefined kfree(void)
// callers: [mhi_uci_release, mhi_uci_read, mhi_uci_write, mhi_ul_xfer_cb, mhi_uci_open, mhi_dl_xfer_cb, mhi_uci_remove, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040c0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [log_level_store, mhi_uci_read, mhi_uci_write, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_get_free_desc_count @ 001040d0 size=1
// signature: undefined mhi_get_free_desc_count(void)
// callers: [mhi_uci_write, mhi_uci_poll, mhi_uci_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_get_free_desc_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001040d8 size=1
// signature: undefined __kmalloc(void)
// callers: [mhi_uci_write, mhi_uci_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001040e0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001040e8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [mhi_uci_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_device_ioctl @ 001040f0 size=1
// signature: undefined mhi_device_ioctl(void)
// callers: [mhi_uci_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_device_ioctl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_prepare_for_transfer @ 001040f8 size=1
// signature: undefined mhi_prepare_for_transfer(void)
// callers: [mhi_uci_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_prepare_for_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_unprepare_from_transfer @ 00104100 size=1
// signature: undefined mhi_unprepare_from_transfer(void)
// callers: [mhi_uci_release, mhi_uci_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_unprepare_from_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104110 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00104118 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00104120 size=1
// signature: undefined device_create(void)
// callers: [mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00104128 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00104130 size=1
// signature: undefined sysfs_create_group(void)
// callers: [mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00104138 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104140 size=1
// signature: undefined __list_add_valid(void)
// callers: [mhi_dl_xfer_cb, mhi_uci_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 00104148 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [mhi_uci_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 00104150 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [mhi_uci_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00104158 size=1
// signature: undefined __wake_up(void)
// callers: [mhi_status_cb, mhi_ul_xfer_cb, mhi_dl_xfer_cb, mhi_uci_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00104160 size=1
// signature: undefined device_destroy(void)
// callers: [mhi_uci_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00104168 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [mhi_uci_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104170 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [mhi_status_cb, mhi_dl_xfer_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104178 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [mhi_status_cb, mhi_dl_xfer_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 00104180 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [mhi_dl_xfer_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00104188 size=1
// signature: undefined scnprintf(void)
// callers: [log_level_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00104190 size=1
// signature: undefined kstrtouint(void)
// callers: [log_level_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



