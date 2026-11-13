// Decompiled by Ghidra 12.2
// Program: sg.ko
// Image base: 00100000

//------------------------------------------------------------
// sg_add_device @ 00102124 size=916
// signature: undefined sg_add_device(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong sg_add_device(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  
  lVar8 = *(long *)(param_1 + 0x60);
  lVar4 = cdev_alloc();
  if (lVar4 == 0) {
    _printk(&DAT_0010900c,"sg_add_device");
    plVar5 = (long *)0xfffffff4;
    goto LAB_001023e4;
  }
  *(undefined1 **)(lVar4 + 0x60) = &__this_module;
  *(undefined ***)(lVar4 + 0x68) = &sg_fops;
  lVar9 = lVar8 + -0x1d8;
  lVar11 = *(long *)(lVar8 + -0x1d0);
  plVar5 = (long *)kmalloc_trace(_idr_preload,0xdc0,0xb0);
  if (plVar5 == (long *)0x0) {
    sdev_prefix_printk(&DAT_00108e96,lVar9,0,"%s: kmalloc Sg_device failure\n","sg_alloc");
    plVar5 = (long *)0xfffffffffffffff4;
LAB_00102448:
    _printk(&DAT_001090a1,"sg_add_device");
  }
  else {
    idr_preload(0xcc0);
    uVar6 = _raw_write_lock_irqsave(&sg_index_lock);
    uVar2 = idr_alloc(sg_index_idr,plVar5,0,0x8000,0x800);
    if ((int)uVar2 < 0) {
      if (uVar2 == 0xffffffe4) {
        sdev_prefix_printk(&DAT_00108e96,lVar9,0,
                           "Unable to attach sg device type=%d, minor number exceeds %d\n",
                           *(undefined1 *)(lVar8 + -0x128),0x7fff);
        uVar2 = 0xffffffed;
      }
      else {
        sdev_prefix_printk(&DAT_00108e96,lVar9,0,"%s: idr allocation Sg_device failure: %d\n",
                           "sg_alloc",uVar2);
      }
    }
    else {
      sprintf((char *)((long)plVar5 + 0x7d),"sg%d",(ulong)uVar2);
      *plVar5 = lVar9;
      __mutex_init(plVar5 + 4,"&sdp->open_rel_lock",&sg_alloc___key);
      plVar5[0xb] = (long)(plVar5 + 0xb);
      plVar5[0xc] = (long)(plVar5 + 0xb);
      __init_waitqueue_head(plVar5 + 1,"&sdp->open_wait",&sg_alloc___key_31);
      *(undefined4 *)(plVar5 + 0xe) = 0;
      plVar5[0xd] = 0;
      *(uint *)(plVar5 + 10) = (uint)*(ushort *)(lVar11 + 0x240);
      *(uint *)((long)plVar5 + 0x54) = uVar2;
      uVar2 = 0;
      *(undefined4 *)(plVar5 + 0x15) = 1;
    }
    _raw_write_unlock_irqrestore(&sg_index_lock,uVar6);
    uVar6 = tpidr_el1;
    lVar1 = sp_el0;
    lVar11 = *(long *)(lVar1 + 0x10) + -1;
    *(int *)(lVar1 + 0x10) = (int)lVar11;
    if ((lVar11 == 0) || (*(long *)(lVar1 + 0x10) == 0)) {
      preempt_schedule();
    }
    if (uVar2 != 0) {
      kfree(plVar5);
      plVar5 = (long *)(long)(int)uVar2;
    }
    if ((long *)0xfffffffffffff000 < plVar5) goto LAB_00102448;
    uVar7 = cdev_add(lVar4,*(uint *)((long)plVar5 + 0x54) | 0x1500000,1);
    uVar10 = uVar7 & 0xffffffff;
    if ((int)uVar7 == 0) {
      plVar5[0x14] = lVar4;
      if (sg_sysfs_valid == '\x01') {
        uVar10 = device_create(sg_sysfs_class,*(undefined8 *)(param_1 + 0x60),
                               *(uint *)((long)plVar5 + 0x54) | 0x1500000,plVar5,&DAT_00108eab,
                               (long)plVar5 + 0x7d);
        if (0xfffffffffffff000 < uVar10) {
          _printk(&DAT_00108eae,"sg_add_device");
          goto LAB_00102308;
        }
        iVar3 = sysfs_create_link(lVar8,uVar10,"generic");
        if (iVar3 != 0) {
          _printk(&DAT_00109048,"sg_add_device",*(undefined4 *)((long)plVar5 + 0x54));
        }
      }
      else {
        _printk(&DAT_00109025,"sg_add_device");
      }
      sdev_prefix_printk(&DAT_00108fa4,lVar9,0,"Attached scsi generic sg%d type %d\n",
                         *(undefined4 *)((long)plVar5 + 0x54),*(undefined1 *)(lVar8 + -0x128));
      *(long **)(param_1 + 0x98) = plVar5;
      plVar5 = (long *)0x0;
      goto LAB_001023e4;
    }
LAB_00102308:
    uVar6 = _raw_write_lock_irqsave(&sg_index_lock);
    idr_remove(sg_index_idr,*(undefined4 *)((long)plVar5 + 0x54));
    _raw_write_unlock_irqrestore(&sg_index_lock,uVar6);
    kfree(plVar5);
    plVar5 = (long *)(uVar10 & 0xffffffff);
  }
  cdev_del(lVar4);
LAB_001023e4:
  return (ulong)plVar5 & 0xffffffff;
}



//------------------------------------------------------------
// sg_remove_device @ 001024bc size=392
// signature: undefined sg_remove_device(void)
// callers: []
//------------------------------------------------------------

void sg_remove_device(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  
  lVar6 = *(long *)(param_1 + 0x98);
  if (lVar6 != 0) {
    uVar7 = *(undefined8 *)(param_1 + 0x60);
    piVar1 = (int *)(lVar6 + 0x70);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar2 + 1 < 2) {
      uVar5 = _raw_read_lock_irqsave(lVar6 + 0x68);
      for (plVar8 = *(long **)(lVar6 + 0x58); plVar8 != (long *)(lVar6 + 0x58);
          plVar8 = (long *)*plVar8) {
        __wake_up(plVar8 + 3,1,0,0);
        kill_fasync(plVar8 + 0x14,0x1d,6);
      }
      __wake_up(lVar6 + 8,1,0,0);
      _raw_read_unlock_irqrestore(lVar6 + 0x68,uVar5);
      sysfs_remove_link(uVar7,"generic");
      device_destroy(sg_sysfs_class,*(uint *)(lVar6 + 0x54) | 0x1500000);
      cdev_del(*(undefined8 *)(lVar6 + 0xa0));
      piVar1 = (int *)(lVar6 + 0xa8);
      *(undefined8 *)(lVar6 + 0xa0) = 0;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar2 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (iVar2 == 1) {
        DataMemoryBarrier(2,1);
        uVar7 = _raw_write_lock_irqsave(&sg_index_lock);
        idr_remove(sg_index_idr,*(undefined4 *)(lVar6 + 0x54));
        _raw_write_unlock_irqrestore(&sg_index_lock,uVar7);
        kfree(lVar6);
      }
      else if (iVar2 < 1) {
        refcount_warn_saturate(piVar1,3);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// sg_read @ 00102670 size=2164
// signature: undefined sg_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001029e8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long sg_read(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined4 *puVar11;
  ulong uVar12;
  int iVar13;
  uint uVar14;
  ulong uVar15;
  long lVar16;
  long *plVar17;
  long lVar18;
  long *plVar19;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  char local_6c [4];
  long local_68;
  
  lVar16 = sp_el0;
  puVar4 = (undefined8 *)sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  if (*(long *)(param_1 + 0xa0) != puVar4[0x106]) {
    if ((sg_check_file_access___already_done & 1) == 0) {
      sg_check_file_access___already_done = 1;
      uVar8 = __task_pid_nr_ns(puVar4,1,0);
      _printk(&DAT_00108fa7,"sg_read",uVar8,puVar4 + 0x109);
    }
    lVar16 = -1;
    goto LAB_001027d0;
  }
  lVar16 = *(long *)(param_1 + 0xd8);
  if ((lVar16 == 0) || (lVar18 = *(long *)(lVar16 + 0x10), lVar18 == 0)) {
    lVar16 = -6;
    goto LAB_001027d0;
  }
  iVar7 = -1;
  if ((0x23 < param_3) && (*(char *)(lVar16 + 0x1428) != '\0')) {
    uVar12 = param_2 + 4;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar15 = uVar12, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar15 = uVar12 & (long)(uVar12 * 0x100) >> 8;
    }
    if (0x7ffffffffc < uVar15) {
LAB_001027c0:
      lVar16 = -0xe;
      goto LAB_001027d0;
    }
    uVar14 = (uint)_cpu_hwcaps;
    if ((uVar14 >> 0x1d & 1) == 0) {
      uVar15 = daif;
      if ((uVar15 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      uVar5 = ttbr1_el1;
      ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4[1];
      InstructionSynchronizationBarrier();
      daif = uVar15;
    }
    if ((uVar14 >> 0x1d & 1) == 0) {
      uVar15 = daif;
      if ((uVar15 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      uVar5 = ttbr1_el1;
      ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar15;
    }
    if (*(int *)(uVar12 & 0xff7fffffffffffff) < 0) {
      if ((param_3 < 0x40) || (((uint)*puVar4 >> 0x16 & 1) == 0)) {
        if (param_3 < 0x58) {
          iVar7 = -1;
        }
        else {
          uVar12 = param_2 + 0x30;
          if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = uVar12, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
            uVar15 = uVar12 & (long)(uVar12 * 0x100) >> 8;
          }
          if (0x7ffffffffc < uVar15) goto LAB_001027c0;
          uaccess_ttbr0_enable();
          iVar7 = *(int *)(uVar12 & 0xff7fffffffffffff);
          uaccess_ttbr0_disable();
        }
      }
      else {
        uVar12 = param_2 + 0x24;
        if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
           (uVar15 = uVar12, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
          uVar15 = uVar12 & (long)(uVar12 * 0x100) >> 8;
        }
        if (0x7ffffffffc < uVar15) goto LAB_001027c0;
        if ((uVar14 >> 0x1d & 1) == 0) {
          uVar15 = daif;
          if ((uVar15 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar4[1];
          InstructionSynchronizationBarrier();
          daif = uVar15;
        }
        iVar7 = *(int *)(uVar12 & 0xff7fffffffffffff);
        if ((uVar14 >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          uVar15 = ttbr1_el1;
          ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
      }
    }
    else {
      uVar12 = param_2 + 8;
      if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
         (uVar15 = uVar12, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar15 = uVar12 & (long)(uVar12 * 0x100) >> 8;
      }
      if (0x7ffffffffc < uVar15) goto LAB_001027c0;
      if ((uVar14 >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4[1];
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      iVar7 = *(int *)(uVar12 & 0xff7fffffffffffff);
      if ((uVar14 >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar15 = daif;
          daif = uVar15 | 0xc0;
        }
        uVar15 = ttbr1_el1;
        ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar15 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
    }
  }
  lVar1 = lVar16 + 0x30;
  local_6c[0] = '\0';
  uVar9 = _raw_write_lock_irqsave(lVar1);
  plVar17 = (long *)(lVar16 + 0x90);
  plVar19 = (long *)*plVar17;
  if (plVar19 != plVar17) {
    local_6c[0] = '\0';
    do {
      if ((*(char *)((long)plVar19 + 0xf2) == '\0') &&
         ((iVar7 == -1 || ((int)plVar19[0xd] == iVar7)))) {
        if (*(char *)((long)plVar19 + 0xf3) == '\0') {
          local_6c[0] = '\x01';
        }
        else if (*(char *)((long)plVar19 + 0xf3) == '\x01') {
          *(undefined1 *)((long)plVar19 + 0xf3) = 2;
          _raw_write_unlock_irqrestore(lVar1,uVar9);
          if (plVar19 == (long *)0x0) goto LAB_00102a84;
          goto LAB_00102aa4;
        }
      }
      plVar19 = (long *)*plVar19;
    } while (plVar19 != plVar17);
  }
  _raw_write_unlock_irqrestore(lVar1,uVar9);
LAB_00102a84:
  if ((*(byte *)(param_1 + 0x41) >> 3 & 1) != 0) {
    lVar16 = -0xb;
    goto LAB_001027d0;
  }
  plVar19 = (long *)sg_get_rq_mark(lVar16,iVar7,local_6c);
  if (plVar19 != (long *)0x0) {
LAB_00102aa4:
    iVar7 = (int)plVar19[7];
joined_r0x00102bec:
    if (iVar7 != 0) {
      lVar16 = sg_new_read(lVar16,param_2,param_3,plVar19);
      goto LAB_001027d0;
    }
    puVar11 = (undefined4 *)kmalloc_trace(___mutex_init,0xdc0,0x24);
    if (puVar11 == (undefined4 *)0x0) {
      lVar16 = -0xc;
      goto LAB_001027d0;
    }
    lVar18 = plVar19[0xc];
    *puVar11 = (int)lVar18;
    puVar11[1] = (int)lVar18;
    puVar11[2] = (int)plVar19[0xd];
    if (*(byte *)((long)plVar19 + 0x35) < 0xc0) {
      uVar14 = 0;
    }
    else {
      uVar14 = (uint)((char)plVar19[8] == '\f');
    }
    uVar3 = puVar11[4];
    puVar11[4] = uVar3 & 0xfffffffe | uVar14;
    uVar14 = uVar14 | (*(byte *)((long)plVar19 + 0x79) & 0x1f) << 1;
    puVar11[4] = uVar3 & 0xffffffc0 | uVar14;
    uVar14 = uVar14 | (*(ushort *)((long)plVar19 + 0x7c) & 0xff) << 6;
    puVar11[4] = uVar3 & 0xffffc000 | uVar14;
    puVar11[4] = uVar3 & 0xffc00000 | uVar14 | (uint)*(byte *)((long)plVar19 + 0x7e) << 0xe;
    if (((*(byte *)((long)plVar19 + 0x79) & 1) != 0) ||
       (((*(byte *)(plVar19 + 0x12) ^ 0xff) & 0x70) == 0)) {
      puVar11[4] = uVar3 & 0xffc00000 | uVar14 | 0x20000;
      lVar18 = plVar19[0x13];
      *(long *)(puVar11 + 5) = plVar19[0x12];
      *(long *)(puVar11 + 7) = lVar18;
    }
    iVar7 = 0;
    iVar13 = 0;
    switch(*(undefined2 *)((long)plVar19 + 0x7c)) {
    case 0:
    case 10:
    case 0xb:
      break;
    case 1:
    case 2:
    case 3:
      iVar13 = 5;
      iVar7 = 0x10;
      break;
    default:
      iVar7 = 5;
      iVar13 = 5;
      break;
    case 7:
      iVar7 = 5;
      iVar13 = 5;
      if ((char)plVar19[0x12] == '\0') {
        iVar7 = 0;
        if (*(char *)((long)plVar19 + 0x79) != '\0') {
          iVar7 = 5;
        }
        iVar13 = iVar7;
      }
    }
    puVar11[3] = iVar7;
    if (param_3 < 0x24) {
      uVar12 = 0;
      if (iVar13 != 0) {
        uVar12 = 0xfffffffffffffffb;
      }
LAB_00102dd4:
      sg_finish_rem_req(plVar19);
      sg_remove_request(lVar16,plVar19);
      lVar16 = (long)(int)uVar12;
    }
    else {
      if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
         (uVar12 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar12 = param_2 & (long)(param_2 << 8) >> 8;
      }
      if (uVar12 < 0x7fffffffdd) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          uVar15 = ttbr1_el1;
          ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar4[1];
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        lVar18 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,puVar11,0x24);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar15 = daif;
            daif = uVar15 | 0xc0;
          }
          uVar15 = ttbr1_el1;
          ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar15 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        if (lVar18 == 0) {
          uVar12 = (long)(int)puVar11[1];
          if (param_3 <= (ulong)(long)(int)puVar11[1]) {
            uVar12 = param_3;
          }
          if ((uVar12 < 0x25) ||
             (iVar7 = sg_read_oxfer(plVar19,param_2 + 0x24,(int)uVar12 + -0x24), iVar7 == 0))
          goto LAB_00102dd4;
        }
      }
      lVar16 = -0xe;
    }
    kfree(puVar11);
    goto LAB_001027d0;
  }
  if ((local_6c[0] != '\0') || (*(int *)(lVar18 + 0x70) == 0)) {
    local_80 = 0;
    uStack_78 = 0;
    local_90 = 0;
    uStack_88 = 0;
    local_98 = 0;
    init_wait_entry(&local_98,0);
    lVar2 = lVar16 + 0x18;
    do {
      lVar10 = prepare_to_wait_event(lVar2,&local_98,1);
      uVar9 = _raw_write_lock_irqsave(lVar1);
      plVar19 = (long *)*plVar17;
      if (plVar19 == plVar17) {
        bVar6 = false;
      }
      else {
        bVar6 = false;
        do {
          if ((*(char *)((long)plVar19 + 0xf2) == '\0') &&
             ((iVar7 == -1 || ((int)plVar19[0xd] == iVar7)))) {
            if (*(char *)((long)plVar19 + 0xf3) == '\0') {
              bVar6 = true;
            }
            else if (*(char *)((long)plVar19 + 0xf3) == '\x01') {
              *(undefined1 *)((long)plVar19 + 0xf3) = 2;
              _raw_write_unlock_irqrestore(lVar1,uVar9);
              if (plVar19 == (long *)0x0) goto LAB_00102b8c;
              local_6c[0] = bVar6;
              finish_wait(lVar2,&local_98);
              iVar7 = (int)plVar19[7];
              goto joined_r0x00102bec;
            }
          }
          plVar19 = (long *)*plVar19;
        } while (plVar19 != plVar17);
      }
      _raw_write_unlock_irqrestore(lVar1,uVar9);
LAB_00102b8c:
      if ((!bVar6) && (*(int *)(lVar18 + 0x70) != 0)) {
        finish_wait(lVar2,&local_98);
        break;
      }
      if (lVar10 != 0) goto LAB_00102ba8;
      schedule();
    } while( true );
  }
LAB_00102bc8:
  lVar10 = -0x13;
  goto LAB_00102bcc;
LAB_00102ba8:
  if ((int)lVar10 == 0) goto LAB_00102bc8;
LAB_00102bcc:
  lVar16 = (long)(int)lVar10;
LAB_001027d0:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar16;
}



//------------------------------------------------------------
// sg_write @ 00102f48 size=1384
// signature: undefined sg_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sg_write(long param_1,ulong param_2,ulong param_3)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 *puVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  uint uVar17;
  ulong local_190 [31];
  undefined4 local_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  long local_68;
  
  lVar16 = sp_el0;
  puVar5 = (undefined8 *)sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_98 = 0;
  local_190[0x1d] = 0;
  local_190[0x1e] = 0;
  local_190[0x1b] = 0;
  local_190[0x1c] = 0;
  local_190[0x19] = 0;
  local_190[0x1a] = 0;
  local_190[0x17] = 0;
  local_190[0x18] = 0;
  local_190[0x15] = 0;
  local_190[0x16] = 0;
  local_190[0x13] = 0;
  local_190[0x14] = 0;
  local_190[0x11] = 0;
  local_190[0x12] = 0;
  local_190[0xf] = 0;
  local_190[0x10] = 0;
  local_190[0xd] = 0;
  local_190[0xe] = 0;
  local_190[0xb] = 0;
  local_190[0xc] = 0;
  local_190[9] = 0;
  local_190[10] = 0;
  local_190[7] = 0;
  local_190[8] = 0;
  local_190[5] = 0;
  local_190[6] = 0;
  local_190[3] = 0;
  local_190[4] = 0;
  local_190[1] = 0;
  local_190[2] = 0;
  local_190[0] = 0;
  if (*(long *)(param_1 + 0xa0) != puVar5[0x106]) {
    if ((sg_check_file_access___already_done & 1) == 0) {
      sg_check_file_access___already_done = 1;
      uVar8 = __task_pid_nr_ns(puVar5,1,0);
      _printk(&DAT_00108fa7,"sg_write",uVar8,puVar5 + 0x109);
    }
    uVar10 = 0xffffffffffffffff;
    goto LAB_00103118;
  }
  lVar16 = *(long *)(param_1 + 0xd8);
  if ((lVar16 != 0) && (puVar13 = *(undefined8 **)(lVar16 + 0x10), puVar13 != (undefined8 *)0x0)) {
    if (*(int *)(puVar13 + 0xe) != 0) {
      uVar10 = 0xffffffffffffffed;
      goto LAB_00103118;
    }
    if (((*(byte *)(param_1 + 0x41) >> 3 & 1) != 0) ||
       (iVar7 = scsi_block_when_processing_errors(*puVar13), iVar7 != 0)) {
      if (param_3 < 0x24) {
LAB_0010310c:
        uVar10 = 0xfffffffffffffffb;
      }
      else {
        if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
           (uVar10 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
          uVar10 = param_2 & (long)(param_2 << 8) >> 8;
        }
        if (uVar10 < 0x7fffffffdd) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar10 = daif;
            if ((uVar10 & 0x80) == 0) {
              uVar14 = daif;
              daif = uVar14 | 0xc0;
            }
            uVar14 = ttbr1_el1;
            ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar5[1];
            InstructionSynchronizationBarrier();
            daif = uVar10;
          }
          lVar11 = __arch_copy_from_user(&local_90,param_2 & 0xff7fffffffffffff,0x24);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar10 = daif;
            if ((uVar10 & 0x80) == 0) {
              uVar14 = daif;
              daif = uVar14 | 0xc0;
            }
            uVar14 = ttbr1_el1;
            ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar14 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar10;
          }
          if (lVar11 == 0) {
            if (local_90 < 0) {
              uVar10 = sg_new_write(lVar16,param_1,param_2,param_3,0,0,0);
              goto LAB_00103118;
            }
            if (param_3 < 0x2a) goto LAB_0010310c;
            param_2 = param_2 + 0x24;
            if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
               (uVar10 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
              uVar10 = param_2 & (long)(param_2 * 0x100) >> 8;
            }
            if (uVar10 >> 0x27 == 0) {
              uaccess_ttbr0_enable();
              bVar3 = *(byte *)(param_2 & 0xff7fffffffffffff);
              uaccess_ttbr0_disable();
              lVar11 = sg_add_request(lVar16);
              if (lVar11 == 0) {
                uVar10 = 0xffffffffffffffdf;
              }
              else {
                mutex_lock(lVar16 + 0x38);
                bVar2 = *(byte *)(lVar16 + 0x142a);
                uVar17 = (uint)bVar2;
                if (bVar2 == 0) {
                  uVar17 = (uint)(byte)(&scsi_command_size_tbl)[bVar3 >> 5];
                  if ((0xbf < bVar3) && ((local_80 & 1) != 0)) {
                    uVar17 = 0xc;
                  }
                }
                else {
                  *(byte *)(lVar16 + 0x142a) = 0;
                }
                mutex_unlock(lVar16 + 0x38);
                uVar4 = (int)param_3 - uVar17;
                uVar1 = local_90._4_4_;
                if ((int)local_90._4_4_ <= (int)uVar4) {
                  uVar1 = uVar4;
                }
                iVar7 = uVar4 - 0x24;
                if (iVar7 < 0) {
                  sg_remove_request(lVar16,lVar11);
                  uVar10 = 0xfffffffffffffffb;
                }
                else {
                  uVar10 = (ulong)uVar17;
                  *(undefined4 *)(lVar11 + 0x38) = 0;
                  *(char *)(lVar11 + 0x40) = (char)uVar17;
                  *(undefined2 *)(lVar11 + 0x42) = 0;
                  *(undefined1 *)(lVar11 + 0x41) = 0;
                  if (iVar7 == 0) {
                    lVar15 = 0;
                    uVar8 = 0xfffffffd;
                    if ((int)(uVar1 - 0x24) < 1) {
                      uVar8 = 0xffffffff;
                    }
                  }
                  else {
                    uVar8 = 0xfffffffc;
                    if (local_90._4_4_ < 0x25) {
                      uVar8 = 0xfffffffe;
                    }
                    lVar15 = param_2 + uVar10;
                  }
                  *(uint *)(lVar11 + 0x44) = uVar1 - 0x24;
                  *(undefined4 *)(lVar11 + 0x3c) = uVar8;
                  *(long *)(lVar11 + 0x48) = lVar15;
                  *(undefined8 *)(lVar11 + 0x58) = 0;
                  *(uint *)(lVar11 + 0x60) = local_90._4_4_;
                  *(int *)(lVar11 + 100) = iVar7;
                  *(undefined4 *)(lVar11 + 0x68) = (undefined4)local_88;
                  *(undefined8 *)(lVar11 + 0x70) = 0;
                  if (uVar17 < 0xfd) {
                    __check_object_size(local_190,uVar10,0);
                    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
                       (uVar14 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
                      uVar14 = param_2 & (long)(param_2 * 0x100) >> 8;
                    }
                    uVar12 = uVar10;
                    if (uVar14 <= 0x8000000000 - uVar10) {
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar14 = daif;
                        if ((uVar14 & 0x80) == 0) {
                          uVar12 = daif;
                          daif = uVar12 | 0xc0;
                        }
                        uVar12 = ttbr1_el1;
                        ttbr1_el1 = puVar5[1] & 0xffff000000000000 | uVar12 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        ttbr0_el1 = puVar5[1];
                        InstructionSynchronizationBarrier();
                        daif = uVar14;
                      }
                      uVar12 = __arch_copy_from_user(local_190,param_2 & 0xff7fffffffffffff,uVar10);
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar14 = daif;
                        if ((uVar14 & 0x80) == 0) {
                          uVar6 = daif;
                          daif = uVar6 | 0xc0;
                        }
                        uVar6 = ttbr1_el1;
                        ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
                        InstructionSynchronizationBarrier();
                        ttbr1_el1 = uVar6 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        daif = uVar14;
                      }
                    }
                    if (uVar12 == 0) {
                      if ((*(int *)(lVar11 + 0x3c) == -4) &&
                         (iVar9 = ___ratelimit(sg_write__rs,"sg_write"), iVar9 != 0)) {
                        _printk(&DAT_00108dc8,local_90._4_4_ + -0x24,iVar7,local_190[0] & 0xff,
                                puVar5 + 0x109);
                      }
                      iVar7 = sg_common_write(lVar16,lVar11,local_190,*(undefined4 *)(lVar16 + 0x68)
                                             );
                      uVar10 = (long)iVar7;
                      if (-1 < iVar7) {
                        uVar10 = param_3;
                      }
                      goto LAB_00103118;
                    }
                    memset((void *)((long)local_190 + (uVar10 - uVar12)),0,uVar12);
                  }
                  else {
                    __copy_overflow(0xfc,uVar10);
                  }
                  sg_remove_request(lVar16,lVar11);
                  uVar10 = 0xfffffffffffffff2;
                }
              }
              goto LAB_00103118;
            }
          }
        }
        uVar10 = 0xfffffffffffffff2;
      }
      goto LAB_00103118;
    }
  }
  uVar10 = 0xfffffffffffffffa;
LAB_00103118:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// sg_poll @ 001034e4 size=300
// signature: undefined sg_poll(void)
// callers: []
//------------------------------------------------------------

uint sg_poll(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  code *pcVar3;
  long *plVar4;
  long *plVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  int iVar9;
  
  lVar7 = *(long *)(param_1 + 0xd8);
  if ((lVar7 == 0) || (lVar8 = *(long *)(lVar7 + 0x10), lVar8 == 0)) {
    uVar1 = 8;
  }
  else {
    if (((param_2 != (undefined8 *)0x0) && (lVar7 != -0x18)) &&
       (pcVar3 = (code *)*param_2, pcVar3 != (code *)0x0)) {
      if (*(int *)(pcVar3 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10353c);
        (*pcVar3)();
      }
      (*pcVar3)();
      DataMemoryBarrier(2,3);
    }
    uVar2 = _raw_read_lock_irqsave(lVar7 + 0x30);
    plVar4 = (long *)(lVar7 + 0x90);
    plVar5 = (long *)*plVar4;
    if (plVar5 == plVar4) {
      iVar9 = 0;
      uVar6 = 0;
    }
    else {
      uVar6 = 0;
      iVar9 = 0;
      do {
        if (uVar6 == 0) {
          if (*(char *)((long)plVar5 + 0xf3) == '\x01') {
            uVar6 = 0x41;
            if (*(char *)((long)plVar5 + 0xf2) != '\0') {
              uVar6 = 0;
            }
          }
          else {
            uVar6 = 0;
          }
        }
        plVar5 = (long *)*plVar5;
        iVar9 = iVar9 + 1;
      } while (plVar5 != plVar4);
    }
    _raw_read_unlock_irqrestore(lVar7 + 0x30,uVar2);
    if (*(int *)(lVar8 + 0x70) == 0) {
      uVar1 = uVar6 | 0x104;
      if (*(char *)(lVar7 + 0x1429) == '\0') {
        if (iVar9 != 0) {
          uVar1 = uVar6;
        }
      }
      else if (0xf < iVar9) {
        uVar1 = uVar6;
      }
    }
    else {
      uVar1 = uVar6 | 0x10;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// sg_ioctl @ 00103614 size=7480
// signature: undefined sg_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00103cb8) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long sg_ioctl(long param_1,int param_2,ulong param_3)

{
  short *psVar1;
  char cVar2;
  undefined8 *puVar3;
  ulong uVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  undefined8 uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  long lVar16;
  long *plVar17;
  char *pcVar18;
  long lVar19;
  undefined8 *puVar20;
  long *plVar21;
  long *plVar22;
  long local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 0xd8);
  if ((lVar16 == 0) || (plVar21 = *(long **)(lVar16 + 0x10), plVar21 == (long *)0x0)) {
LAB_00104894:
    lVar19 = -6;
    goto switchD_001036b0_caseD_2279;
  }
  local_98 = 0;
  uVar7 = *(uint *)(param_1 + 0x40) & 3;
  uVar15 = (uint)_cpu_hwcaps;
  if (param_2 < 0x2201) {
    switch(param_2) {
    case 0x1267:
      puVar20 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
         (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
        uVar14 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (0x7ffffffffc < uVar14) goto LAB_00104b10;
      uVar7 = *(uint *)(*(long *)(*plVar21 + 8) + 0x204);
      if (0x3ffffe < uVar7) {
        uVar7 = 0x3fffff;
      }
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      *(uint *)(param_3 & 0xff7fffffffffffff) = uVar7 << 9;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      goto LAB_00104ae8;
    case 0x1268:
    case 0x1269:
    case 0x126a:
    case 0x126b:
    case 0x126c:
    case 0x126d:
    case 0x126e:
    case 0x126f:
    case 0x1270:
    case 0x1271:
    case 0x1272:
    case 0x1273:
      break;
    case 0x1274:
    case 0x1275:
    case 0x1276:
switchD_001037f4_caseD_1274:
      lVar19 = -0x19;
      goto switchD_001036b0_caseD_2279;
    default:
      if (param_2 == -0x3fb7ed8d) goto switchD_001037f4_caseD_1274;
      if (param_2 == 1) {
        if ((int)plVar21[0xe] != 0) goto LAB_00103904;
        iVar8 = scsi_ioctl(*plVar21,*(undefined4 *)(param_1 + 0x44),1,param_3);
        lVar19 = (long)iVar8;
        goto LAB_00104aec;
      }
    }
switchD_001036b0_caseD_2204:
    if (uVar7 != 2) {
      lVar19 = -1;
      goto switchD_001036b0_caseD_2279;
    }
LAB_00103960:
    iVar6 = scsi_ioctl_block_when_processing_errors
                      (*plVar21,param_2,*(uint *)(param_1 + 0x40) >> 0xb & 1);
    iVar8 = -0x203;
    if (iVar6 != 0) {
      iVar8 = iVar6;
    }
    lVar19 = (long)iVar8;
    goto LAB_00104aec;
  }
  if (0x88 < param_2 - 0x2201U) {
    if ((param_2 - 0x5382U < 5) && ((1 << (ulong)(param_2 - 0x5382U & 0x1f) & 0x19U) != 0))
    goto switchD_001036b0_caseD_2205;
    goto switchD_001036b0_caseD_2204;
  }
  lVar19 = 0;
  switch(param_2) {
  case 0x2201:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      uVar7 = *(uint *)(param_3 & 0xff7fffffffffffff);
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if ((int)uVar7 < 0) {
        lVar19 = -5;
      }
      else {
        if (0x33333331 < uVar7) {
          uVar7 = 0x33333332;
        }
        lVar19 = 0;
        *(uint *)(lVar16 + 0x68) = (uVar7 / 100) * 0xfa + ((uVar7 % 100) * 0xfa) / 100;
        *(uint *)(lVar16 + 0x6c) = uVar7;
      }
      goto switchD_001036b0_caseD_2279;
    }
    goto LAB_001042bc;
  case 0x2202:
    lVar19 = (long)*(int *)(lVar16 + 0x6c);
    goto LAB_00104aec;
  case 0x2203:
    if ((int)plVar21[0xe] != 0) {
LAB_00103904:
      lVar19 = -0x13;
      goto switchD_001036b0_caseD_2279;
    }
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(uint *)(param_3 & 0xff7fffffffffffff) =
         *(byte *)(*(long *)(*(long *)*plVar21 + 0xb8) + 0x148) >> 3 & 1;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  default:
    goto switchD_001036b0_caseD_2204;
  case 0x2205:
  case 0x2284:
switchD_001036b0_caseD_2205:
    if ((int)plVar21[0xe] != 0) goto LAB_00103904;
    goto LAB_00103960;
  case 0x2270:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) {
LAB_00104b10:
      lVar19 = -0xe;
      goto switchD_001036b0_caseD_2279;
    }
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(uint *)(param_3 & 0xff7fffffffffffff) = (uint)*(byte *)(lVar16 + 0x1429);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x2271:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      lVar19 = 0;
      *(bool *)(lVar16 + 0x1429) = *(int *)(param_3 & 0xff7fffffffffffff) != 0;
      goto switchD_001036b0_caseD_2279;
    }
    goto LAB_001042bc;
  case 0x2272:
    uVar7 = *(uint *)(*(long *)(*plVar21 + 8) + 0x204);
    puVar20 = (undefined8 *)sp_el0;
    if (0x3ffffe < uVar7) {
      uVar7 = 0x3fffff;
    }
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    iVar8 = *(int *)(lVar16 + 0x78);
    if ((int)(uVar7 * 0x200) <= *(int *)(lVar16 + 0x78)) {
      iVar8 = uVar7 * 0x200;
    }
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(int *)(param_3 & 0xff7fffffffffffff) = iVar8;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x2275:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      iVar8 = *(int *)(param_3 & 0xff7fffffffffffff);
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if (iVar8 < 0) {
        lVar19 = -0x16;
      }
      else {
        lVar19 = lVar16 + 0x38;
        uVar7 = *(uint *)(*(long *)(*plVar21 + 8) + 0x204);
        if (0x3ffffe < uVar7) {
          uVar7 = 0x3fffff;
        }
        if ((int)(uVar7 * 0x200) <= iVar8) {
          iVar8 = uVar7 * 0x200;
        }
        mutex_lock(lVar19);
        if (iVar8 != *(int *)(lVar16 + 0x78)) {
          if ((*(char *)(lVar16 + 0x142c) != '\0') || (*(char *)(lVar16 + 0x142d) != '\0')) {
            mutex_unlock(lVar19);
            lVar19 = -0x10;
            goto switchD_001036b0_caseD_2279;
          }
          lVar11 = *(long *)(lVar16 + 0x80);
          psVar1 = (short *)(lVar16 + 0x70);
          if (((lVar11 != 0) && (*(int *)(lVar16 + 0x74) != 0)) &&
             (*(char *)(lVar16 + 0x8c) == '\0')) {
            if (*psVar1 != 0) {
              uVar14 = 0;
              do {
                lVar11 = *(long *)(lVar16 + 0x80);
                lVar12 = *(long *)(lVar11 + uVar14 * 8);
                if (lVar12 == 0) goto LAB_00105184;
                __free_pages(lVar12,*(undefined4 *)(lVar16 + 0x88));
                uVar14 = uVar14 + 1;
              } while (uVar14 < *(ushort *)(lVar16 + 0x70));
              lVar11 = *(long *)(lVar16 + 0x80);
            }
LAB_00105184:
            kfree(lVar11);
          }
          *(undefined8 *)(lVar16 + 0x80) = 0;
          *(undefined8 *)(lVar16 + 0x88) = 0;
          psVar1[0] = 0;
          psVar1[1] = 0;
          psVar1[2] = 0;
          psVar1[3] = 0;
          *(undefined8 *)(lVar16 + 0x78) = 0;
          sg_build_reserve(lVar16,iVar8);
        }
        mutex_unlock(lVar19);
        lVar19 = 0;
      }
      goto switchD_001036b0_caseD_2279;
    }
    lVar19 = -0xe;
    goto LAB_00104aec;
  case 0x2276:
    if ((int)plVar21[0xe] == 0) {
      local_78 = 0;
      plVar17 = (long *)*plVar21;
      local_88 = CONCAT44((int)plVar17[0x13],(int)plVar17[0x12]);
      local_90 = CONCAT44(*(undefined4 *)((long)plVar17 + 0x94),*(undefined4 *)(*plVar17 + 0x1bc));
      puVar20 = (undefined8 *)sp_el0;
      local_80 = CONCAT26((short)plVar17[0xe],
                          CONCAT24(*(undefined2 *)(*plVar17 + 0x1f0),(uint)*(byte *)(plVar17 + 0x16)
                                  ));
      if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
         (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
        uVar14 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar14 < 0x7fffffffe1) {
        if ((uVar15 >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          puVar20 = (undefined8 *)puVar20[1];
          uVar13 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar20 & 0xffff000000000000 | uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        lVar16 = __arch_copy_to_user(puVar20,param_3 & 0xff7fffffffffffff,&local_90,0x20);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        lVar19 = 0;
        if (lVar16 != 0) {
          lVar19 = -0xe;
        }
      }
      else {
        lVar19 = -0xe;
      }
    }
    else {
      lVar19 = -0x13;
    }
    goto LAB_00104aec;
  case 0x2279:
    goto switchD_001036b0_caseD_2279;
  case 0x227a:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(undefined4 *)(param_3 & 0xff7fffffffffffff) = 0;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x227b:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      lVar19 = 0;
      *(bool *)(lVar16 + 0x1428) = *(int *)(param_3 & 0xff7fffffffffffff) != 0;
      goto switchD_001036b0_caseD_2279;
    }
    goto LAB_001042bc;
  case 0x227c:
    lVar19 = lVar16 + 0x30;
    uVar10 = _raw_read_lock_irqsave(lVar19);
    for (puVar20 = *(undefined8 **)(lVar16 + 0x90); puVar20 != (undefined8 *)(lVar16 + 0x90);
        puVar20 = (undefined8 *)*puVar20) {
      if ((*(char *)((long)puVar20 + 0xf3) == '\x01') && (*(char *)((long)puVar20 + 0xf2) == '\0'))
      {
        _raw_read_unlock_irqrestore(lVar19,uVar10);
        puVar3 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
           (uVar14 = param_3, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
          uVar14 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (0x7ffffffffc < uVar14) goto LAB_00104b10;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar3[1];
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        *(undefined4 *)(param_3 & 0xff7fffffffffffff) = *(undefined4 *)(puVar20 + 0xd);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        goto LAB_00104ae8;
      }
    }
    _raw_read_unlock_irqrestore(lVar19,uVar10);
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(undefined4 *)(param_3 & 0xff7fffffffffffff) = 0xffffffff;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x227d:
    uVar10 = _raw_read_lock_irqsave(lVar16 + 0x30);
    plVar22 = (long *)(lVar16 + 0x90);
    plVar17 = (long *)*plVar22;
    if (plVar17 == plVar22) {
      iVar8 = 0;
    }
    else {
      iVar8 = 0;
      do {
        if ((*(char *)((long)plVar17 + 0xf3) == '\x01') && (*(char *)((long)plVar17 + 0xf2) == '\0')
           ) {
          iVar8 = iVar8 + 1;
        }
        plVar17 = (long *)*plVar17;
      } while (plVar17 != plVar22);
    }
    _raw_read_unlock_irqrestore(lVar16 + 0x30,uVar10);
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(int *)(param_3 & 0xff7fffffffffffff) = iVar8;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x227e:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      lVar19 = 0;
      *(char *)((long)plVar21 + 0x7c) = (char)*(undefined4 *)(param_3 & 0xff7fffffffffffff);
      goto switchD_001036b0_caseD_2279;
    }
    goto LAB_001042bc;
  case 0x227f:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(int *)(param_3 & 0xff7fffffffffffff) = (int)plVar21[10];
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x2282:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(undefined4 *)(param_3 & 0xff7fffffffffffff) = 0x7748;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x2283:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      iVar8 = *(int *)(param_3 & 0xff7fffffffffffff);
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if (iVar8 < 0xfd) {
        lVar19 = 0;
        if (iVar8 < 1) {
          iVar8 = 0;
        }
        *(char *)(lVar16 + 0x142a) = (char)iVar8;
        goto switchD_001036b0_caseD_2279;
      }
LAB_001042b4:
      lVar19 = -0xc;
      goto switchD_001036b0_caseD_2279;
    }
    goto LAB_001042bc;
  case 0x2285:
    if ((int)plVar21[0xe] != 0) goto LAB_00103904;
    iVar8 = scsi_block_when_processing_errors(*plVar21);
    if (iVar8 == 0) goto LAB_00104894;
    iVar8 = sg_new_write(lVar16,param_1,param_3,0x58,uVar7 != 2,1,&local_98);
    lVar19 = local_98;
    if (iVar8 < 0) {
      lVar19 = (long)iVar8;
    }
    else {
      lVar11 = lVar16 + 0x30;
      uVar10 = _raw_read_lock_irqsave(lVar11);
      cVar2 = *(char *)(lVar19 + 0xf3);
      _raw_read_unlock_irqrestore(lVar11,uVar10);
      if (cVar2 == '\0') {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        local_80 = 0;
        local_90 = 0;
        init_wait_entry(&local_90,0);
        while( true ) {
          lVar12 = prepare_to_wait_event(lVar16 + 0x18,&local_90,1);
          lVar19 = local_98;
          uVar10 = _raw_read_lock_irqsave(lVar11);
          cVar2 = *(char *)(lVar19 + 0xf3);
          _raw_read_unlock_irqrestore(lVar11,uVar10);
          if (cVar2 != '\0') break;
          if (lVar12 != 0) goto LAB_001050d0;
          schedule();
        }
        finish_wait(lVar16 + 0x18,&local_90);
        lVar12 = 0;
LAB_001050d0:
        lVar19 = (long)(int)lVar12;
      }
      else {
        lVar19 = 0;
      }
      _raw_write_lock_irq(lVar11);
      if (*(char *)(local_98 + 0xf3) == '\0') {
        *(undefined1 *)(local_98 + 0xf1) = 1;
        _raw_write_unlock_irq(lVar11);
      }
      else {
        *(undefined1 *)(local_98 + 0xf3) = 2;
        _raw_write_unlock_irq(lVar11);
        iVar8 = sg_new_read(lVar16,param_3,0x58,local_98);
        if (-1 < iVar8) {
          iVar8 = 0;
        }
        lVar19 = (long)iVar8;
      }
    }
    goto LAB_00104aec;
  case 0x2286:
    pcVar9 = (char *)kmalloc_trace(__raw_write_unlock_irqrestore,0xdc0,0x180);
    if (pcVar9 == (char *)0x0) goto LAB_001042b4;
    uVar10 = _raw_read_lock_irqsave(lVar16 + 0x30);
    plVar17 = (long *)(lVar16 + 0x90);
    plVar22 = (long *)*plVar17;
    if (plVar22 != plVar17) {
      pcVar18 = pcVar9;
      uVar14 = 0;
      do {
        *pcVar18 = *(char *)((long)plVar22 + 0xf3) + '\x01';
        pcVar18[3] = (byte)*(undefined2 *)((long)plVar22 + 0x7c) & *(byte *)((long)plVar22 + 0x79) &
                     (byte)*(undefined2 *)((long)plVar22 + 0x7e);
        if (*(char *)((long)plVar22 + 0xf3) == '\0') {
          uVar7 = jiffies_to_msecs(_jiffies);
          iVar8 = 0;
          if (*(uint *)((long)plVar22 + 0x84) <= uVar7) {
            iVar8 = uVar7 - *(uint *)((long)plVar22 + 0x84);
          }
        }
        else {
          iVar8 = *(int *)((long)plVar22 + 0x84);
        }
        *(int *)(pcVar18 + 0x10) = iVar8;
        pcVar18[1] = *(char *)((long)plVar22 + 0xf1);
        pcVar18[2] = *(char *)((long)plVar22 + 0xf2);
        *(int *)(pcVar18 + 4) = (int)plVar22[0xd];
        *(long *)(pcVar18 + 8) = plVar22[0xe];
        plVar22 = (long *)*plVar22;
        if (plVar22 == plVar17) break;
        bVar5 = uVar14 < 0xf;
        pcVar18 = pcVar18 + 0x18;
        uVar14 = uVar14 + 1;
      } while (bVar5);
    }
    _raw_read_unlock_irqrestore(lVar16 + 0x30,uVar10);
    puVar20 = (undefined8 *)sp_el0;
    if (((uint)*puVar20 >> 0x16 & 1) == 0) {
      if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
         (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
        uVar14 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar14 < 0x7ffffffe81) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20[1];
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        iVar8 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,pcVar9,0x180);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        if (iVar8 == 0) goto LAB_0010502c;
      }
LAB_00103f44:
      lVar19 = -0xe;
    }
    else {
      lVar16 = 0;
      lVar19 = param_3 * 0x100 + 0x1000;
      pcVar18 = pcVar9;
      do {
        uVar14 = param_3 + lVar16;
        if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = uVar14, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
          uVar13 = uVar14 & lVar19 + -0x1000 >> 8;
        }
        if (0x7ffffffff8 < uVar13) goto LAB_00103f44;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar4 = daif;
            daif = uVar4 | 0xc0;
          }
          uVar4 = ttbr1_el1;
          ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        lVar11 = __arch_copy_to_user(uVar14 & 0xff7fffffffffffff,pcVar18,8);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        if (lVar11 != 0) goto LAB_00103f44;
        uVar14 = param_3 + lVar16 + 8;
        if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = uVar14, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
          uVar13 = uVar14 & lVar19 + -0x800 >> 8;
        }
        if (0x7ffffffffc < uVar13) goto LAB_00103f44;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar4 = daif;
            daif = uVar4 | 0xc0;
          }
          uVar4 = ttbr1_el1;
          ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        *(undefined4 *)(uVar14 & 0xff7fffffffffffff) = *(undefined4 *)(pcVar18 + 8);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        uVar14 = param_3 + lVar16 + 0xc;
        if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = uVar14, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
          uVar13 = uVar14 & lVar19 + -0x400 >> 8;
        }
        if (0x7ffffffffc < uVar13) goto LAB_00103f44;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar4 = daif;
            daif = uVar4 | 0xc0;
          }
          uVar4 = ttbr1_el1;
          ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        *(undefined4 *)(uVar14 & 0xff7fffffffffffff) = *(undefined4 *)(pcVar18 + 0x10);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        uVar14 = param_3 + lVar16 + 0x10;
        if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = uVar14, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
          uVar13 = uVar14 & lVar19 >> 8;
        }
        if (0x7ffffffffc < uVar13) goto LAB_00103f44;
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar4 = daif;
            daif = uVar4 | 0xc0;
          }
          uVar4 = ttbr1_el1;
          ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        *(undefined4 *)(uVar14 & 0xff7fffffffffffff) = *(undefined4 *)(pcVar18 + 0x14);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar14 = daif;
          if ((uVar14 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar14;
        }
        lVar16 = lVar16 + 0x14;
        lVar19 = lVar19 + 0x1400;
        pcVar18 = pcVar18 + 0x18;
      } while (lVar16 != 0x140);
LAB_0010502c:
      lVar19 = 0;
    }
    kfree(pcVar9);
    goto LAB_00104aec;
  case 0x2287:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar14 < 0x7ffffffffd) {
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar20[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if ((uVar15 >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      lVar19 = 0;
      *(char *)(lVar16 + 0x142b) = (char)*(undefined4 *)(param_3 & 0xff7fffffffffffff);
      goto switchD_001036b0_caseD_2279;
    }
LAB_001042bc:
    lVar19 = -0xe;
    goto LAB_00104aec;
  case 0x2288:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(uint *)(param_3 & 0xff7fffffffffffff) = (uint)*(byte *)(lVar16 + 0x142b);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    break;
  case 0x2289:
    puVar20 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
      uVar14 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7ffffffffc < uVar14) goto LAB_00104b10;
    if ((uVar15 >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar20[1];
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
    *(uint *)(param_3 & 0xff7fffffffffffff) = (uint)(*plVar21 != 0);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar14 = daif;
      if ((uVar14 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar14;
    }
  }
LAB_00104ae8:
  lVar19 = 0;
LAB_00104aec:
  if ((int)lVar19 == -0x203) {
    iVar8 = scsi_ioctl(*plVar21,*(undefined4 *)(param_1 + 0x44),param_2,param_3);
    lVar19 = (long)iVar8;
  }
switchD_001036b0_caseD_2279:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar19;
}



//------------------------------------------------------------
// sg_mmap @ 001055a8 size=224
// signature: undefined sg_mmap(void)
// callers: []
//------------------------------------------------------------

undefined8 sg_mmap(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  uVar4 = 0xfffffffa;
  if (((param_1 != 0) && (param_2 != (long *)0x0)) &&
     (lVar5 = *(long *)(param_1 + 0xd8), lVar5 != 0)) {
    if (param_2[0x10] == 0) {
      lVar1 = *param_2;
      lVar2 = param_2[1];
      mutex_lock(lVar5 + 0x38);
      if ((ulong)*(uint *)(lVar5 + 0x78) < (ulong)(lVar2 - lVar1)) {
        uVar4 = 0xfffffff4;
      }
      else {
        *(undefined1 *)(lVar5 + 0x142c) = 1;
        iVar3 = *(int *)(param_2[2] + 0xb0);
        if ((int)param_2[5] != iVar3) {
          down_write(param_2[6]);
          *(int *)(param_2 + 5) = iVar3;
          up_write(param_2[6]);
        }
        uVar4 = 0;
        param_2[0x12] = lVar5;
        param_2[4] = param_2[4] | 0x4044000;
        param_2[0xf] = (long)sg_mmap_vm_ops;
      }
      mutex_unlock(lVar5 + 0x38);
    }
    else {
      uVar4 = 0xffffffea;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// sg_open @ 0010568c size=680
// signature: undefined sg_open(void)
// callers: []
//------------------------------------------------------------

ulong sg_open(long param_1,long param_2)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  long *plVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  
  uVar6 = *(uint *)(param_1 + 0x4c);
  uVar2 = *(uint *)(param_2 + 0x40);
  nonseekable_open();
  if ((uVar2 & 0x83) == 0x80) {
    uVar11 = 0xffffffff;
    goto LAB_00105720;
  }
  uVar7 = _raw_read_lock_irqsave(&sg_index_lock);
  plVar8 = (long *)idr_find(sg_index_idr,uVar6 & 0xfffff);
  if (plVar8 == (long *)0x0) {
    plVar8 = (long *)0xfffffffffffffffa;
LAB_0010570c:
    _raw_read_unlock_irqrestore(&sg_index_lock,uVar7);
  }
  else {
    if ((int)plVar8[0xe] != 0) {
      plVar8 = (long *)0xffffffffffffffed;
      goto LAB_0010570c;
    }
    puVar1 = (uint *)(plVar8 + 0x15);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar6 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar6 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar6 == 0) {
      uVar10 = 2;
LAB_0010590c:
      refcount_warn_saturate(puVar1,uVar10);
    }
    else if ((int)(uVar6 + 1 | uVar6) < 0) {
      uVar10 = 1;
      goto LAB_0010590c;
    }
    _raw_read_unlock_irqrestore(&sg_index_lock,uVar7);
    if (plVar8 < (long *)0xfffffffffffff001) {
      uVar9 = scsi_device_get(*plVar8);
      uVar11 = uVar9 & 0xffffffff;
      if ((int)uVar9 == 0) {
        uVar9 = scsi_autopm_get_device(*plVar8);
        uVar11 = uVar9 & 0xffffffff;
        if ((int)uVar9 == 0) {
          if ((uVar2 >> 0xb & 1) == 0) {
            iVar5 = scsi_block_when_processing_errors(*plVar8);
            if (iVar5 != 0) {
              mutex_lock(plVar8 + 4);
              uVar6 = open_wait(plVar8,uVar2);
              if (uVar6 == 0) {
                if ((uVar2 >> 7 & 1) != 0) goto LAB_0010586c;
                goto LAB_00105874;
              }
              uVar11 = (ulong)uVar6;
              goto LAB_001057f4;
            }
            uVar11 = 0xfffffffa;
          }
          else {
            mutex_lock(plVar8 + 4);
            if ((uVar2 >> 7 & 1) == 0) {
              if (*(char *)((long)plVar8 + 0x74) != '\0') {
LAB_001057f0:
                uVar11 = 0xfffffff0;
                goto LAB_001057f4;
              }
            }
            else {
              if (0 < (int)plVar8[0xf]) goto LAB_001057f0;
LAB_0010586c:
              *(undefined1 *)((long)plVar8 + 0x74) = 1;
            }
LAB_00105874:
            if ((int)plVar8[0xf] < 1) {
              *(undefined1 *)((long)plVar8 + 0x7c) = 0;
              *(uint *)(plVar8 + 10) = (uint)*(ushort *)(*(long *)(*plVar8 + 8) + 0x240);
            }
            uVar11 = sg_add_sfp(plVar8);
            if (uVar11 < 0xfffffffffffff001) {
              *(ulong *)(param_2 + 0xd8) = uVar11;
              *(int *)(plVar8 + 0xf) = (int)plVar8[0xf] + 1;
              mutex_unlock(plVar8 + 4);
              uVar11 = 0;
              goto LAB_00105814;
            }
            if ((uVar2 >> 7 & 1) != 0) {
              *(undefined1 *)((long)plVar8 + 0x74) = 0;
              __wake_up(plVar8 + 1,1,1,0);
            }
LAB_001057f4:
            mutex_unlock(plVar8 + 4);
          }
          scsi_autopm_put_device(*plVar8);
        }
        scsi_device_put(*plVar8);
      }
LAB_00105814:
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar6 = *puVar1;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = uVar6 - 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (uVar6 == 1) {
        DataMemoryBarrier(2,1);
        uVar7 = _raw_write_lock_irqsave(&sg_index_lock);
        idr_remove(sg_index_idr,*(undefined4 *)((long)plVar8 + 0x54));
        _raw_write_unlock_irqrestore(&sg_index_lock,uVar7);
        kfree(plVar8);
      }
      else if ((int)uVar6 < 1) {
        refcount_warn_saturate(puVar1,3);
      }
      goto LAB_00105720;
    }
  }
  uVar11 = (ulong)plVar8 & 0xffffffff;
LAB_00105720:
  return uVar11 & 0xffffffff;
}



//------------------------------------------------------------
// sg_release @ 00105954 size=364
// signature: undefined sg_release(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sg_release(undefined8 param_1,long param_2)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  long *plVar9;
  undefined8 *puVar10;
  
  plVar9 = *(long **)(param_2 + 0xd8);
  if ((plVar9 == (long *)0x0) || (puVar10 = (undefined8 *)plVar9[2], puVar10 == (undefined8 *)0x0))
  {
    return 0xfffffffa;
  }
  mutex_lock(puVar10 + 4);
  scsi_autopm_put_device(*puVar10);
  iVar3 = *(int *)(puVar10 + 0xf);
  *(int *)(puVar10 + 0xf) = iVar3 + -1;
  if (*(char *)((long)puVar10 + 0x74) == '\0') {
    if (iVar3 + -1 != 0) goto LAB_001059c8;
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
    *(undefined1 *)((long)puVar10 + 0x74) = 0;
  }
  __wake_up(puVar10 + 1,1,uVar7,0);
LAB_001059c8:
  mutex_unlock(puVar10 + 4);
  plVar2 = plVar9 + 0x286;
  Hint_Prefetch(plVar2,2,0,1);
  do {
    iVar3 = (int)*plVar2;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(plVar2,0x10);
    if (bVar5) {
      *(int *)plVar2 = iVar3 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (iVar3 == 1) {
    DataMemoryBarrier(2,1);
    lVar8 = plVar9[2];
    uVar7 = _raw_write_lock_irqsave(lVar8 + 0x68);
    uVar6 = __list_del_entry_valid(plVar9);
    if ((uVar6 & 1) != 0) {
      lVar1 = *plVar9;
      plVar2 = (long *)plVar9[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar9 = -0x2152ffffffffff00;
    plVar9[1] = -0x2152fffffffffede;
    _raw_write_unlock_irqrestore(lVar8 + 0x68,uVar7);
    plVar9[0x287] = 0xfffffffe0;
    plVar9[0x288] = (long)(plVar9 + 0x288);
    plVar9[0x289] = (long)(plVar9 + 0x288);
    plVar9[0x28a] = (long)sg_remove_sfp_usercontext;
    queue_work_on(0x20,_system_wq,plVar9 + 0x287);
  }
  else if (iVar3 < 1) {
    refcount_warn_saturate(plVar2,3);
  }
  return 0;
}



//------------------------------------------------------------
// sg_fasync @ 00105ad4 size=56
// signature: undefined sg_fasync(void)
// callers: []
//------------------------------------------------------------

undefined8 sg_fasync(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if ((*(long *)(param_2 + 0xd8) == 0) || (*(long *)(*(long *)(param_2 + 0xd8) + 0x10) == 0)) {
    uVar1 = 0xfffffffa;
  }
  else {
    uVar1 = fasync_helper();
  }
  return uVar1;
}



//------------------------------------------------------------
// sg_get_rq_mark @ 00105b0c size=188
// signature: undefined sg_get_rq_mark(void)
// callers: [sg_read]
//------------------------------------------------------------

long sg_get_rq_mark(long param_1,int param_2,undefined1 *param_3)

{
  undefined8 uVar1;
  long *plVar2;
  
  *param_3 = 0;
  uVar1 = _raw_write_lock_irqsave(param_1 + 0x30);
  plVar2 = *(long **)(param_1 + 0x90);
  do {
    if (plVar2 == (long *)(param_1 + 0x90)) {
      plVar2 = (long *)0x0;
LAB_00105ba4:
      _raw_write_unlock_irqrestore(param_1 + 0x30,uVar1);
      return (long)plVar2;
    }
    if ((*(char *)((long)plVar2 + 0xf2) == '\0') &&
       ((param_2 == -1 || (*(int *)(plVar2 + 0xd) == param_2)))) {
      if (*(char *)((long)plVar2 + 0xf3) == '\0') {
        *param_3 = 1;
      }
      else if (*(char *)((long)plVar2 + 0xf3) == '\x01') {
        *(undefined1 *)((long)plVar2 + 0xf3) = 2;
        goto LAB_00105ba4;
      }
    }
    plVar2 = (long *)*plVar2;
  } while( true );
}



//------------------------------------------------------------
// sg_new_read @ 00105bc8 size=540
// signature: undefined sg_new_read(void)
// callers: [sg_ioctl, sg_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong sg_new_read(undefined8 param_1,undefined8 param_2,ulong param_3,long param_4)

{
  uint uVar1;
  byte bVar2;
  undefined8 *puVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  
  puVar3 = (undefined8 *)sp_el0;
  if (((uint)*puVar3 >> 0x16 & 1) == 0) {
    if (param_3 < 0x58) {
LAB_00105d38:
      iVar5 = -0x16;
      goto LAB_00105d80;
    }
  }
  else if (param_3 < 0x40) goto LAB_00105d38;
  bVar2 = *(byte *)(param_4 + 0x41);
  *(undefined1 *)(param_4 + 0x7b) = 0;
  if (((bVar2 == 0) || (uVar11 = *(ulong *)(param_4 + 0x58), uVar11 == 0)) ||
     (((*(byte *)(param_4 + 0x79) & 1) == 0 && (((*(byte *)(param_4 + 0x90) ^ 0xff) & 0x70) != 0))))
  {
LAB_00105d4c:
    if (((*(char *)(param_4 + 0x79) != '\0') || (*(short *)(param_4 + 0x7c) != 0)) ||
       (*(short *)(param_4 + 0x7e) != 0)) {
      *(uint *)(param_4 + 0x88) = *(uint *)(param_4 + 0x88) | 1;
    }
    iVar5 = put_sg_io_hdr(param_4 + 0x38,param_2);
  }
  else {
    uVar8 = (uint)bVar2;
    if (0x5f < bVar2) {
      uVar8 = 0x60;
    }
    uVar1 = *(byte *)(param_4 + 0x97) + 8;
    if (uVar8 <= uVar1) {
      uVar1 = uVar8;
    }
    uVar10 = (ulong)uVar1;
    __check_object_size(param_4 + 0x90,uVar10,1);
    if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = uVar11, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
      uVar9 = uVar11 & (long)(uVar11 << 8) >> 8;
    }
    if (uVar9 <= 0x8000000000 - uVar10) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar3[1];
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      lVar7 = __arch_copy_to_user(uVar11 & 0xff7fffffffffffff,param_4 + 0x90,uVar10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        uVar10 = ttbr1_el1;
        ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      if (lVar7 == 0) {
        *(char *)(param_4 + 0x7b) = (char)uVar1;
        *(undefined2 *)(param_4 + 0x7e) = 8;
        goto LAB_00105d4c;
      }
    }
    iVar5 = -0xe;
  }
LAB_00105d80:
  iVar6 = sg_finish_rem_req(param_4);
  sg_remove_request(param_1,param_4);
  if (iVar6 != 0) {
    param_3 = (long)iVar6;
  }
  if (iVar5 != 0) {
    param_3 = (long)iVar5;
  }
  return param_3;
}



//------------------------------------------------------------
// sg_read_oxfer @ 00105dfc size=828
// signature: undefined sg_read_oxfer(void)
// callers: [sg_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sg_read_oxfer(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 *puVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  
  if (((param_2 != 0) && (0 < (int)param_3)) && (*(short *)(param_1 + 0x18) != 0)) {
    lVar10 = 0;
    uVar12 = 0;
    puVar7 = (undefined8 *)sp_el0;
    uVar1 = *(int *)(param_1 + 0x30) + 0xc;
    lVar11 = param_2 << 8;
    uVar2 = 1 << (ulong)(uVar1 & 0x1f);
    lVar9 = (long)(int)uVar2;
    do {
      lVar8 = *(long *)(*(long *)(param_1 + 0x28) + uVar12 * 8);
      if (lVar8 == 0) {
        return 0;
      }
      uVar5 = lVar8 << 6;
      if ((int)param_3 < (int)uVar2) {
        uVar12 = (ulong)param_3;
        uVar5 = uVar5 & 0xfffffffffff000 | 0xff00000000000000;
        __check_object_size(uVar5,uVar12,1);
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar6 = param_2 + lVar10, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar6 = param_2 + lVar10 & lVar11 >> 8;
        }
        if (uVar6 <= 0x8000000000 - uVar12) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar6 = daif;
            if ((uVar6 & 0x80) == 0) {
              uVar3 = daif;
              daif = uVar3 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar3 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar6;
          }
          lVar10 = __arch_copy_to_user(puVar7,param_2 + lVar10 & 0xff7fffffffffffff,uVar5,uVar12);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar5 = daif;
              daif = uVar5 | 0xc0;
            }
            uVar5 = ttbr1_el1;
            ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar5 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          if (lVar10 == 0) {
            return 0;
          }
        }
        return 0xfffffff2;
      }
      if (uVar1 == 0x1f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x106148);
        (*pcVar4)();
      }
      uVar5 = uVar5 & 0xfffffffffff000 | 0xff00000000000000;
      __check_object_size(uVar5,lVar9,1);
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar6 = param_2 + lVar10, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar6 = param_2 + lVar10 & lVar11 >> 8;
      }
      if (0x8000000000U - lVar9 < uVar6) {
        return 0xfffffff2;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr1_el1 = puVar7[1] & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7[1];
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      lVar8 = __arch_copy_to_user(param_2 + lVar10 & 0xff7fffffffffffff,uVar5,lVar9);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        uVar6 = ttbr1_el1;
        ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      if (lVar8 != 0) {
        return 0xfffffff2;
      }
      if ((int)(param_3 - uVar2) < 1) {
        return 0;
      }
      uVar12 = uVar12 + 1;
      lVar10 = lVar10 + lVar9;
      lVar11 = lVar11 + (-(ulong)(uVar2 >> 0x1f) & 0xffffff0000000000 | (ulong)uVar2 << 8);
      param_3 = param_3 - uVar2;
    } while (uVar12 < *(ushort *)(param_1 + 0x18));
  }
  return 0;
}



//------------------------------------------------------------
// sg_finish_rem_req @ 0010617c size=232
// signature: undefined sg_finish_rem_req(void)
// callers: [sg_rq_end_io_usercontext, sg_new_read, sg_common_write, sg_read, sg_remove_sfp_usercontext]
//------------------------------------------------------------

undefined4 sg_finish_rem_req(long param_1)

{
  short *psVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = *(long *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x100) == 0) {
    uVar2 = 0;
    lVar3 = *(long *)(param_1 + 0xf8);
  }
  else {
    uVar2 = blk_rq_unmap_user();
    lVar3 = *(long *)(param_1 + 0xf8);
  }
  if (lVar3 != 0) {
    blk_mq_free_request();
  }
  if (*(char *)(param_1 + 0xf0) == '\0') {
    lVar4 = *(long *)(param_1 + 0x28);
    psVar1 = (short *)(param_1 + 0x18);
    if (((lVar4 != 0) && (*(int *)(param_1 + 0x1c) != 0)) && (*(char *)(param_1 + 0x34) == '\0')) {
      if (*psVar1 != 0) {
        uVar5 = 0;
        do {
          lVar4 = *(long *)(param_1 + 0x28);
          lVar3 = *(long *)(lVar4 + uVar5 * 8);
          if (lVar3 == 0) goto LAB_00106240;
          __free_pages(lVar3,*(undefined4 *)(param_1 + 0x30));
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(ushort *)(param_1 + 0x18));
        lVar4 = *(long *)(param_1 + 0x28);
      }
LAB_00106240:
      kfree(lVar4);
    }
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined8 *)(param_1 + 0x30) = 0;
    psVar1[0] = 0;
    psVar1[1] = 0;
    psVar1[2] = 0;
    psVar1[3] = 0;
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  else {
    *(undefined2 *)(param_1 + 0x18) = 0;
    *(undefined8 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined8 *)(param_1 + 0x1c) = 0;
    *(undefined1 *)(param_1 + 0xf0) = 0;
    *(undefined1 *)(lVar4 + 0x142d) = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// sg_remove_request @ 00106264 size=196
// signature: undefined sg_remove_request(void)
// callers: [sg_rq_end_io_usercontext, sg_write, sg_new_read, sg_new_write, sg_common_write, sg_read]
//------------------------------------------------------------

void sg_remove_request(long param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (((param_1 != 0) && (param_2 != (long *)0x0)) &&
     (*(long **)(param_1 + 0x90) != (long *)(param_1 + 0x90))) {
    uVar3 = _raw_write_lock_irqsave(param_1 + 0x30);
    if ((long *)*param_2 != param_2) {
      uVar4 = __list_del_entry_valid(param_2);
      if ((uVar4 & 1) != 0) {
        lVar1 = *param_2;
        plVar2 = (long *)param_2[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      param_2[2] = 0;
      *param_2 = -0x2152ffffffffff00;
      param_2[1] = -0x2152fffffffffede;
    }
    _raw_write_unlock_irqrestore(param_1 + 0x30,uVar3);
    if (*(int *)(*(long *)(param_1 + 0x10) + 0x70) != 0) {
      __wake_up(param_1 + 0x18,1,0,0);
    }
  }
  return;
}



//------------------------------------------------------------
// uaccess_ttbr0_enable @ 00106328 size=72
// signature: undefined uaccess_ttbr0_enable(void)
// callers: [sg_write, sg_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uaccess_ttbr0_enable(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    lVar1 = sp_el0;
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  return;
}



//------------------------------------------------------------
// FUN_00106374 @ 00106374 size=16
// signature: undefined FUN_00106374(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00106374(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar2 = daif;
    if ((uVar2 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    lVar1 = sp_el0;
    uVar3 = ttbr1_el1;
    ttbr1_el1 = *(ulong *)(lVar1 + 8) & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = *(ulong *)(lVar1 + 8);
    InstructionSynchronizationBarrier();
    daif = uVar2;
  }
  return;
}



//------------------------------------------------------------
// uaccess_ttbr0_disable @ 0010638c size=64
// signature: undefined uaccess_ttbr0_disable(void)
// callers: [sg_write, sg_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void uaccess_ttbr0_disable(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar1 = daif;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = daif;
      daif = uVar2 | 0xc0;
    }
    uVar2 = ttbr1_el1;
    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar2 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar1;
  }
  return;
}



//------------------------------------------------------------
// FUN_001063d0 @ 001063d0 size=16
// signature: undefined FUN_001063d0(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_001063d0(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar1 = daif;
    if ((uVar1 & 0x80) == 0) {
      uVar2 = daif;
      daif = uVar2 | 0xc0;
    }
    uVar2 = ttbr1_el1;
    ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar2 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar1;
  }
  return;
}



//------------------------------------------------------------
// sg_new_write @ 001063e8 size=1272
// signature: undefined sg_new_write(void)
// callers: [sg_write, sg_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong sg_new_write(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4,int param_5,
                  undefined1 param_6,undefined8 *param_7)

{
  long lVar1;
  long *plVar2;
  byte bVar3;
  int iVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 *puVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
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
  undefined4 local_78;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  local_78 = 0;
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
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  local_128 = 0;
  uStack_120 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_170 = 0;
  if (param_4 < 0x58) {
LAB_00106464:
    param_4 = 0xffffffffffffffea;
  }
  else {
    *(undefined1 *)(param_1 + 0x1429) = 1;
    plVar5 = (long *)sg_add_request();
    if (plVar5 == (long *)0x0) {
      param_4 = 0xffffffffffffffdf;
      goto LAB_001066cc;
    }
    *(undefined1 *)((long)plVar5 + 0xf2) = param_6;
    iVar4 = get_sg_io_hdr(plVar5 + 7,param_3);
    if (iVar4 != 0) {
      if ((param_1 != 0) && (*(long **)(param_1 + 0x90) != (long *)(param_1 + 0x90))) {
        uVar6 = _raw_write_lock_irqsave(param_1 + 0x30);
        if ((long *)*plVar5 != plVar5) {
          uVar7 = __list_del_entry_valid(plVar5);
          if ((uVar7 & 1) != 0) {
            lVar1 = *plVar5;
            plVar2 = (long *)plVar5[1];
            *(long **)(lVar1 + 8) = plVar2;
            *plVar2 = lVar1;
          }
          plVar5[2] = 0;
          *plVar5 = -0x2152ffffffffff00;
          plVar5[1] = -0x2152fffffffffede;
        }
        _raw_write_unlock_irqrestore(param_1 + 0x30,uVar6);
        if (*(int *)(*(long *)(param_1 + 0x10) + 0x70) != 0) {
          __wake_up(param_1 + 0x18,1,0,0);
          param_4 = 0xfffffffffffffff2;
          goto LAB_001066cc;
        }
      }
      param_4 = 0xfffffffffffffff2;
      goto LAB_001066cc;
    }
    if ((int)plVar5[7] != 0x53) {
      if ((param_1 != 0) && (*(long **)(param_1 + 0x90) != (long *)(param_1 + 0x90))) {
        uVar6 = _raw_write_lock_irqsave(param_1 + 0x30);
        if ((long *)*plVar5 != plVar5) {
          uVar7 = __list_del_entry_valid(plVar5);
          if ((uVar7 & 1) != 0) {
            lVar1 = *plVar5;
            plVar2 = (long *)plVar5[1];
            *(long **)(lVar1 + 8) = plVar2;
            *plVar2 = lVar1;
          }
          plVar5[2] = 0;
          *plVar5 = -0x2152ffffffffff00;
          plVar5[1] = -0x2152fffffffffede;
        }
        _raw_write_unlock_irqrestore(param_1 + 0x30,uVar6);
        if (*(int *)(*(long *)(param_1 + 0x10) + 0x70) != 0) {
          __wake_up(param_1 + 0x18,1,0,0);
          param_4 = 0xffffffffffffffda;
          goto LAB_001066cc;
        }
      }
      param_4 = 0xffffffffffffffda;
      goto LAB_001066cc;
    }
    if ((*(uint *)((long)plVar5 + 100) >> 2 & 1) != 0) {
      if (*(uint *)(param_1 + 0x78) < *(uint *)((long)plVar5 + 0x44)) {
        sg_remove_request(param_1,plVar5);
        param_4 = 0xfffffffffffffff4;
        goto LAB_001066cc;
      }
      if ((*(uint *)((long)plVar5 + 100) & 1) != 0) {
        sg_remove_request(param_1,plVar5);
        goto LAB_00106464;
      }
      if (*(char *)(param_1 + 0x142d) != '\0') {
        sg_remove_request(param_1,plVar5);
        param_4 = 0xfffffffffffffff0;
        goto LAB_001066cc;
      }
    }
    uVar7 = __msecs_to_jiffies((int)plVar5[0xc]);
    uVar12 = plVar5[10];
    if (0x7ffffffe < uVar7) {
      uVar7 = 0x7fffffff;
    }
    if (uVar12 != 0) {
      bVar3 = *(byte *)(plVar5 + 8);
      uVar11 = (ulong)bVar3;
      if ((5 < bVar3) && (2 < bVar3 - 0xfd)) {
        __check_object_size(&local_170,uVar11,0);
        puVar9 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
           (uVar10 = uVar12, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
          uVar10 = uVar12 & (long)(uVar12 << 8) >> 8;
        }
        uVar8 = uVar11;
        if (uVar10 <= 0x8000000000 - uVar11) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar10 = daif;
            if ((uVar10 & 0x80) == 0) {
              uVar8 = daif;
              daif = uVar8 | 0xc0;
            }
            puVar9 = (undefined8 *)puVar9[1];
            uVar8 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar8 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar9;
            InstructionSynchronizationBarrier();
            daif = uVar10;
          }
          uVar8 = __arch_copy_from_user(puVar9,&local_170,uVar12 & 0xff7fffffffffffff,uVar11);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar10 = daif;
              daif = uVar10 | 0xc0;
            }
            uVar10 = ttbr1_el1;
            ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar10 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          if (uVar8 == 0) {
            if ((param_5 == 0) || (iVar4 = sg_allow_access(param_2,&local_170), iVar4 == 0)) {
              iVar4 = sg_common_write(param_1,plVar5,&local_170,uVar7 & 0xffffffff);
              if (iVar4 < 0) {
                param_4 = (ulong)iVar4;
              }
              else if (param_7 != (undefined8 *)0x0) {
                *param_7 = plVar5;
              }
            }
            else {
              sg_remove_request(param_1,plVar5);
              param_4 = 0xffffffffffffffff;
            }
            goto LAB_001066cc;
          }
        }
        memset((void *)((long)&local_170 + (uVar11 - uVar8)),0,uVar8);
        sg_remove_request(param_1,plVar5);
        param_4 = 0xfffffffffffffff2;
        goto LAB_001066cc;
      }
    }
    if ((param_1 != 0) && (*(long **)(param_1 + 0x90) != (long *)(param_1 + 0x90))) {
      uVar6 = _raw_write_lock_irqsave(param_1 + 0x30);
      if ((long *)*plVar5 != plVar5) {
        uVar7 = __list_del_entry_valid(plVar5);
        if ((uVar7 & 1) != 0) {
          lVar1 = *plVar5;
          plVar2 = (long *)plVar5[1];
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        plVar5[2] = 0;
        *plVar5 = -0x2152ffffffffff00;
        plVar5[1] = -0x2152fffffffffede;
      }
      _raw_write_unlock_irqrestore(param_1 + 0x30,uVar6);
      if (*(int *)(*(long *)(param_1 + 0x10) + 0x70) != 0) {
        __wake_up(param_1 + 0x18,1,0,0);
      }
    }
    param_4 = 0xffffffffffffffa6;
  }
LAB_001066cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sg_add_request @ 001068f8 size=444
// signature: undefined sg_add_request(void)
// callers: [sg_write, sg_new_write]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * sg_add_request(long param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  undefined8 *__s;
  undefined8 *puVar6;
  
  uVar2 = _raw_write_lock_irqsave(param_1 + 0x30);
  plVar5 = (long *)(param_1 + 0x90);
  __s = (undefined8 *)(param_1 + 0xa8);
  if ((long *)*plVar5 != plVar5) {
    if (*(char *)(param_1 + 0x1429) == '\0') {
LAB_001069c4:
      __s = (undefined8 *)0x0;
      goto LAB_00106a8c;
    }
    if (*(long *)(param_1 + 0xb8) != 0) {
      if (*(long *)(param_1 + 0x1f0) == 0) {
        __s = (undefined8 *)(param_1 + 0x1e0);
      }
      else if (*(long *)(param_1 + 0x328) == 0) {
        __s = (undefined8 *)(param_1 + 0x318);
      }
      else if (*(long *)(param_1 + 0x460) == 0) {
        __s = (undefined8 *)(param_1 + 0x450);
      }
      else if (*(long *)(param_1 + 0x598) == 0) {
        __s = (undefined8 *)(param_1 + 0x588);
      }
      else if (*(long *)(param_1 + 0x6d0) == 0) {
        __s = (undefined8 *)(param_1 + 0x6c0);
      }
      else if (*(long *)(param_1 + 0x808) == 0) {
        __s = (undefined8 *)(param_1 + 0x7f8);
      }
      else if (*(long *)(param_1 + 0x940) == 0) {
        __s = (undefined8 *)(param_1 + 0x930);
      }
      else if (*(long *)(param_1 + 0xa78) == 0) {
        __s = (undefined8 *)(param_1 + 0xa68);
      }
      else if (*(long *)(param_1 + 0xbb0) == 0) {
        __s = (undefined8 *)(param_1 + 0xba0);
      }
      else if (*(long *)(param_1 + 0xce8) == 0) {
        __s = (undefined8 *)(param_1 + 0xcd8);
      }
      else if (*(long *)(param_1 + 0xe20) == 0) {
        __s = (undefined8 *)(param_1 + 0xe10);
      }
      else if (*(long *)(param_1 + 0xf58) == 0) {
        __s = (undefined8 *)(param_1 + 0xf48);
      }
      else {
        if (*(long *)(param_1 + 0x1090) == 0) {
          lVar4 = 0x1080;
        }
        else if (*(long *)(param_1 + 0x11c8) == 0) {
          lVar4 = 0x11b8;
        }
        else {
          if (*(long *)(param_1 + 0x1300) != 0) goto LAB_001069c4;
          lVar4 = 0x12f0;
        }
        __s = (undefined8 *)(param_1 + lVar4);
      }
    }
  }
  memset(__s,0,0x138);
  __s[2] = param_1;
  uVar1 = jiffies_to_msecs(_jiffies);
  *(undefined4 *)((long)__s + 0x84) = uVar1;
  puVar6 = *(undefined8 **)(param_1 + 0x98);
  uVar3 = __list_add_valid(__s,puVar6,plVar5);
  if ((uVar3 & 1) != 0) {
    *(undefined8 **)(param_1 + 0x98) = __s;
    *__s = plVar5;
    __s[1] = puVar6;
    *puVar6 = __s;
  }
LAB_00106a8c:
  _raw_write_unlock_irqrestore(param_1 + 0x30,uVar2);
  return __s;
}



//------------------------------------------------------------
// sg_common_write @ 00106ab4 size=944
// signature: undefined sg_common_write(void)
// callers: [sg_write, sg_new_write]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong sg_common_write(long param_1,long param_2,undefined1 *param_3,undefined4 param_4)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 uVar4;
  short sVar5;
  char cVar6;
  bool bVar7;
  uint uVar8;
  undefined4 uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  ulong uVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar18 = sp_el0;
  local_68 = *(long *)(lVar18 + 0x638);
  uVar4 = *param_3;
  uVar2 = *(uint *)(param_2 + 0x44);
  lVar18 = *(long *)(param_1 + 0x10);
  *(undefined2 *)(param_2 + 0x78) = 0;
  *(undefined1 *)(param_2 + 0x35) = uVar4;
  *(undefined1 *)(param_2 + 0x7a) = 0;
  *(undefined4 *)(param_2 + 0x88) = 0;
  *(undefined8 *)(param_2 + 0x7c) = 0;
  if (uVar2 >> 0x1c != 0) {
    sg_remove_request(param_1,param_2);
    uVar15 = 0xffffffea;
    goto LAB_00106e04;
  }
  lVar16 = *(long *)(param_2 + 0x10);
  iVar3 = *(int *)(param_2 + 0x3c);
  sVar5 = *(short *)(param_2 + 0x42);
  uVar9 = 0x22;
  if (iVar3 == -2) {
    uVar9 = 0x23;
  }
  local_80 = 0;
  lVar17 = *(long *)(**(long **)(lVar16 + 0x10) + 8);
  local_78 = 0;
  local_70 = 0;
  uVar10 = scsi_alloc_request(lVar17,uVar9,0);
  if (uVar10 < 0xfffffffffffff001) {
    if (0x20 < (ulong)*(byte *)(param_2 + 0x40)) {
      blk_mq_free_request(uVar10);
      uVar15 = 0xffffffea;
      goto LAB_00106d1c;
    }
    memcpy((void *)(uVar10 + 0x214),param_3,(ulong)*(byte *)(param_2 + 0x40));
    *(ushort *)(uVar10 + 0x20c) = (ushort)*(byte *)(param_2 + 0x40);
    *(ulong *)(param_2 + 0xf8) = uVar10;
    *(long *)(uVar10 + 0x130) = param_2;
    *(undefined4 *)(uVar10 + 0x204) = 0;
    if ((uVar2 == 0) || (iVar3 == -1)) goto LAB_00106d54;
    if ((sg_allow_dio == 0) ||
       ((((*(byte *)(param_2 + 100) & 1) == 0 || (iVar3 == -5)) || (sVar5 != 0)))) {
LAB_00106c2c:
      lVar17 = lVar16 + 0x38;
      mutex_lock(lVar17);
      if ((*(uint *)(lVar16 + 0x78) < uVar2) || (*(char *)(lVar16 + 0x142d) != '\0')) {
        if ((*(byte *)(param_2 + 100) >> 2 & 1) == 0) {
          uVar8 = sg_build_indirect(param_2 + 0x18,lVar16,uVar2);
          if (uVar8 == 0) goto LAB_00106cac;
        }
        else {
          uVar8 = 0xfffffff4;
          if (uVar2 <= *(uint *)(lVar16 + 0x78)) {
            uVar8 = 0xfffffff0;
          }
        }
        uVar15 = (ulong)uVar8;
        mutex_unlock(lVar17);
        goto LAB_00106d1c;
      }
      *(char *)(lVar16 + 0x142d) = '\x01';
      sg_link_reserve(lVar16,param_2,uVar2);
LAB_00106cac:
      mutex_unlock(lVar17);
      uVar14 = local_70;
      uVar15 = *(ulong *)(param_2 + 0x48);
      bVar7 = false;
      puVar12 = &local_80;
      local_80 = *(undefined8 *)(param_2 + 0x28);
      local_70._6_2_ = SUB82(uVar14,6);
      local_70._0_6_ =
           CONCAT15(iVar3 == -4,
                    CONCAT14(uVar15 == 0,
                             CONCAT22(*(undefined2 *)(param_2 + 0x18),
                                      (short)*(undefined4 *)(param_2 + 0x30))));
      local_78 = 0;
    }
    else {
      uVar15 = *(ulong *)(param_2 + 0x48);
      if (lVar17 == 0) {
        uVar8 = 0x1ff;
      }
      else {
        uVar8 = *(uint *)(lVar17 + 0x250);
      }
      uVar8 = *(uint *)(lVar17 + 0x108) | uVar8;
      if (((uVar8 & uVar15) != 0) || ((uVar8 & uVar2) != 0)) goto LAB_00106c2c;
      puVar12 = (undefined8 *)0x0;
      bVar7 = true;
    }
    uVar11 = blk_rq_map_user_io(uVar10,puVar12,uVar15,*(undefined4 *)(param_2 + 0x44),0xa20,
                                sVar5 != 0,sVar5,1,iVar3 == -2);
    uVar15 = uVar11 & 0xffffffff;
    if ((int)uVar11 != 0) goto LAB_00106d1c;
    *(undefined8 *)(param_2 + 0x100) = *(undefined8 *)(uVar10 + 0x38);
    if (bVar7) {
      *(undefined1 *)(param_2 + 0x34) = 1;
      *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) | 2;
    }
  }
  else {
    uVar15 = uVar10 & 0xffffffff;
    if ((int)uVar10 != 0) {
LAB_00106d1c:
      sg_finish_rem_req(param_2);
      sg_remove_request(param_1,param_2);
      goto LAB_00106e04;
    }
  }
LAB_00106d54:
  if (*(int *)(lVar18 + 0x70) != 0) {
    if (*(long *)(param_2 + 0x100) != 0) {
      blk_mq_free_request(*(undefined8 *)(param_2 + 0xf8));
      *(undefined8 *)(param_2 + 0xf8) = 0;
    }
    sg_finish_rem_req(param_2);
    sg_remove_request(param_1,param_2);
    uVar15 = 0xffffffed;
    goto LAB_00106e04;
  }
  uVar9 = jiffies_to_msecs(_jiffies);
  *(undefined4 *)(param_2 + 0x84) = uVar9;
  if ((*(int *)(param_2 + 0x38) == 0) || ((*(byte *)(param_2 + 100) >> 4 & 1) == 0)) {
    uVar14 = 1;
  }
  else {
    uVar14 = 0;
  }
  puVar1 = (uint *)(param_1 + 0x1430);
  *(undefined4 *)(*(long *)(param_2 + 0xf8) + 0x28) = param_4;
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar2 = *puVar1;
    cVar6 = '\x01';
    bVar7 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar7) {
      *puVar1 = uVar2 + 1;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  if (uVar2 == 0) {
    uVar13 = 2;
LAB_00106e68:
    refcount_warn_saturate(puVar1,uVar13);
  }
  else if ((int)(uVar2 + 1 | uVar2) < 0) {
    uVar13 = 1;
    goto LAB_00106e68;
  }
  *(code **)(*(long *)(param_2 + 0xf8) + 0x128) = sg_rq_end_io;
  blk_execute_rq_nowait(*(undefined8 *)(param_2 + 0xf8),uVar14);
  uVar15 = 0;
LAB_00106e04:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}



//------------------------------------------------------------
// sg_allow_access @ 00106e70 size=80
// signature: undefined sg_allow_access(void)
// callers: [sg_new_write]
//------------------------------------------------------------

int sg_allow_access(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  
  if (*(char *)(**(long **)(*(long *)(param_1 + 0xd8) + 0x10) + 0xb0) == '\x06') {
    iVar2 = 0;
  }
  else {
    uVar1 = scsi_cmd_allowed(param_2,*(undefined4 *)(param_1 + 0x44));
    iVar2 = (uVar1 & 1) - 1;
  }
  return iVar2;
}



//------------------------------------------------------------
// sg_rq_end_io @ 00106ec4 size=808
// signature: undefined sg_rq_end_io(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sg_rq_end_io(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  code *pcVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long *plVar12;
  undefined8 uVar13;
  long lVar14;
  long *plVar15;
  undefined8 local_50;
  long local_48;
  
  lVar14 = sp_el0;
  local_48 = *(long *)(lVar14 + 0x638);
  lVar14 = *(long *)(param_1 + 0x130);
  if (*(char *)(lVar14 + 0xf3) != '\0') {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x107124);
    (*pcVar8)();
  }
  plVar12 = *(long **)(lVar14 + 0x10);
  if (plVar12 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x800,0x10712c);
    (*pcVar8)();
  }
  plVar15 = (long *)plVar12[2];
  if ((int)plVar15[0xe] != 0) {
    _printk(&DAT_00108ecd,"sg_rq_end_io");
  }
  uVar13 = *(undefined8 *)(param_1 + 0x268);
  uVar5 = *(uint *)(param_1 + 0x290);
  *(undefined4 *)(lVar14 + 0x80) = *(undefined4 *)(param_1 + 0x260);
  uVar9 = jiffies_to_msecs(_jiffies);
  iVar1 = 0;
  if (*(uint *)(lVar14 + 0x84) <= uVar9) {
    iVar1 = uVar9 - *(uint *)(lVar14 + 0x84);
  }
  *(int *)(lVar14 + 0x84) = iVar1;
  if (uVar5 != 0) {
    uVar9 = uVar5 >> 1 & 0x7f;
    *(char *)(lVar14 + 0x78) = (char)uVar5;
    *(undefined1 *)(lVar14 + 0x7a) = 0;
    *(char *)(lVar14 + 0x79) = (char)uVar9;
    *(ushort *)(lVar14 + 0x7c) = (ushort)(uVar5 >> 0x10) & 0xff;
    *(ushort *)(lVar14 + 0x7e) = (ushort)(byte)(uVar5 >> 0x18);
    local_50 = 0;
    if ((*(char *)((long)plVar15 + 0x7c) != '\0') && ((uVar9 | 0x10) == 0x11)) {
      __scsi_print_sense(*plVar15,"sg_rq_end_io",uVar13,0x60);
    }
    if ((((uVar5 >> 0x18 != 0) &&
         (uVar10 = scsi_normalize_sense(uVar13,0x60,&local_50), (uVar10 & 1) != 0)) &&
        ((0x6f < (byte)local_50 & (byte)local_50) == 0)) && (local_50._1_1_ == '\x06')) {
      uVar10 = *(ulong *)(*plVar15 + 0x15c);
      if ((uVar10 & 1) != 0) {
        *(ulong *)(*plVar15 + 0x15c) = uVar10 | 2;
      }
    }
  }
  if (*(int *)(param_1 + 0x264) != 0) {
    puVar11 = *(undefined8 **)(param_1 + 0x268);
    uVar3 = puVar11[3];
    uVar13 = *puVar11;
    uVar4 = puVar11[1];
    *(undefined8 *)(lVar14 + 0xa0) = puVar11[2];
    *(undefined8 *)(lVar14 + 0xa8) = uVar3;
    *(undefined8 *)(lVar14 + 0x90) = uVar13;
    *(undefined8 *)(lVar14 + 0x98) = uVar4;
    uVar3 = puVar11[7];
    uVar13 = puVar11[4];
    uVar4 = puVar11[5];
    *(undefined8 *)(lVar14 + 0xc0) = puVar11[6];
    *(undefined8 *)(lVar14 + 200) = uVar3;
    *(undefined8 *)(lVar14 + 0xb0) = uVar13;
    *(undefined8 *)(lVar14 + 0xb8) = uVar4;
    uVar3 = puVar11[0xb];
    uVar13 = puVar11[8];
    uVar4 = puVar11[9];
    *(undefined8 *)(lVar14 + 0xe0) = puVar11[10];
    *(undefined8 *)(lVar14 + 0xe8) = uVar3;
    *(undefined8 *)(lVar14 + 0xd0) = uVar13;
    *(undefined8 *)(lVar14 + 0xd8) = uVar4;
  }
  *(undefined8 *)(lVar14 + 0xf8) = 0;
  blk_mq_free_request(param_1);
  plVar15 = plVar12 + 6;
  uVar13 = _raw_write_lock_irqsave(plVar15);
  if (*(char *)(lVar14 + 0xf1) == '\0') {
LAB_00107040:
    *(undefined1 *)(lVar14 + 0xf3) = 1;
    _raw_write_unlock_irqrestore(plVar15,uVar13);
    __wake_up(plVar12 + 3,1,1,0);
    kill_fasync(plVar12 + 0x14,0x1d,1);
    plVar15 = plVar12 + 0x286;
    Hint_Prefetch(plVar15,2,0,1);
    do {
      iVar1 = (int)*plVar15;
      cVar6 = '\x01';
      bVar7 = (bool)ExclusiveMonitorPass(plVar15,0x10);
      if (bVar7) {
        *(int *)plVar15 = iVar1 + -1;
        cVar6 = ExclusiveMonitorsStatus();
      }
    } while (cVar6 != '\0');
    if (iVar1 != 1) {
      if (iVar1 < 1) {
        refcount_warn_saturate(plVar15,3);
      }
      goto LAB_001071c0;
    }
    DataMemoryBarrier(2,1);
    lVar14 = plVar12[2];
    uVar13 = _raw_write_lock_irqsave(lVar14 + 0x68);
    uVar10 = __list_del_entry_valid(plVar12);
    if ((uVar10 & 1) != 0) {
      lVar2 = *plVar12;
      plVar15 = (long *)plVar12[1];
      *(long **)(lVar2 + 8) = plVar15;
      *plVar15 = lVar2;
    }
    *plVar12 = -0x2152ffffffffff00;
    plVar12[1] = -0x2152fffffffffede;
    _raw_write_unlock_irqrestore(lVar14 + 0x68,uVar13);
    plVar12[0x287] = 0xfffffffe0;
    plVar12[0x288] = (long)(plVar12 + 0x288);
    plVar12[0x289] = (long)(plVar12 + 0x288);
    plVar12[0x28a] = (long)sg_remove_sfp_usercontext;
    plVar12 = plVar12 + 0x287;
    uVar13 = _system_wq;
  }
  else {
    if (*(char *)((long)plVar12 + 0x142b) != '\0') {
      *(undefined1 *)(lVar14 + 0xf2) = 0;
      goto LAB_00107040;
    }
    *(undefined1 *)(lVar14 + 0xf3) = 0;
    _raw_write_unlock_irqrestore(plVar15,uVar13);
    plVar12 = (long *)(lVar14 + 0x108);
    *(undefined8 *)(lVar14 + 0x108) = 0xfffffffe0;
    *(long *)(lVar14 + 0x110) = lVar14 + 0x110;
    *(long *)(lVar14 + 0x118) = lVar14 + 0x110;
    uVar13 = _system_wq;
    *(code **)(lVar14 + 0x120) = sg_rq_end_io_usercontext;
  }
  queue_work_on(0x20,uVar13,plVar12);
LAB_001071c0:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// sg_link_reserve @ 00107204 size=100
// signature: undefined sg_link_reserve(void)
// callers: [sg_common_write]
//------------------------------------------------------------

void sg_link_reserve(long param_1,long param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  
  *(undefined1 *)(param_2 + 0xf0) = 1;
  if (*(ushort *)(param_1 + 0x70) != 0) {
    uVar3 = 0;
    iVar1 = 1 << (ulong)(*(int *)(param_1 + 0x88) + 0xcU & 0x1f);
    iVar4 = iVar1 + param_3;
    do {
      iVar4 = iVar4 - iVar1;
      uVar3 = uVar3 + 1;
      if (iVar4 <= iVar1) {
        *(short *)(param_2 + 0x18) = (short)uVar3;
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x74);
        uVar2 = *(undefined8 *)(param_1 + 0x80);
        *(int *)(param_2 + 0x20) = param_3;
        *(undefined8 *)(param_2 + 0x28) = uVar2;
        *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(param_1 + 0x88);
        return;
      }
    } while (*(ushort *)(param_1 + 0x70) != uVar3);
  }
  return;
}



//------------------------------------------------------------
// sg_build_indirect @ 00107268 size=540
// signature: undefined sg_build_indirect(void)
// callers: [sg_build_reserve, sg_common_write]
//------------------------------------------------------------

uint sg_build_indirect(undefined2 *param_1,long param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  
  if (param_3 < 0) {
    uVar9 = 0xfffffff2;
  }
  else {
    uVar9 = *(uint *)(*(long *)(param_2 + 0x10) + 0x50);
    uVar13 = (ulong)uVar9;
    uVar2 = 0x200;
    if (param_3 != 0) {
      uVar2 = param_3 + 0x1ffU & 0xfffffe00;
    }
    lVar7 = __kmalloc((long)(int)(uVar9 << 3),0x2b20);
    *(long *)(param_1 + 8) = lVar7;
    if (lVar7 == 0) {
      uVar9 = 0xfffffff4;
    }
    else {
      *(uint *)(param_1 + 2) = uVar9 << 3;
      if (-1 < (int)uVar9) {
        lVar7 = (long)(int)scatter_elem_sz;
        if (scatter_elem_sz != scatter_elem_sz_prev) {
          if (scatter_elem_sz < 0x1000) {
            scatter_elem_sz = 0x1000;
          }
          scatter_elem_sz_prev = scatter_elem_sz;
        }
        iVar3 = 0;
        if (0xfff < lVar7 - 1U) {
          iVar3 = 0x40 - (int)LZCOUNT(lVar7 - 1U >> 0xc);
        }
        bVar6 = uVar9 == 0;
        iVar10 = iVar3;
        do {
          if (bVar6 || 0 >= (int)uVar2) {
            uVar14 = 0;
            iVar10 = iVar3;
            bVar1 = 0 < (int)uVar2;
LAB_0010742c:
            uVar9 = 0xfffffff4;
            if (!bVar1) {
              uVar9 = 0;
            }
            *(int *)(param_1 + 0xc) = iVar10;
            *param_1 = (short)uVar14;
            *(uint *)(param_1 + 4) = uVar2;
            return uVar9;
          }
          uVar14 = 0;
          uVar9 = 1 << (ulong)(iVar10 + 0xcU & 0x1f);
          uVar11 = uVar2;
          while( true ) {
            uVar5 = scatter_elem_sz_prev;
            uVar8 = tpidr_el1;
            uVar8 = __alloc_pages(uVar8,0x42b20,iVar10,0,0);
            *(undefined8 *)(*(long *)(param_1 + 8) + uVar14 * 8) = uVar8;
            if (*(long *)(*(long *)(param_1 + 8) + uVar14 * 8) == 0) break;
            uVar4 = uVar11;
            if ((int)uVar5 <= (int)uVar11) {
              uVar4 = uVar5;
            }
            if ((uVar4 == scatter_elem_sz_prev) && ((int)scatter_elem_sz_prev < (int)uVar9)) {
              scatter_elem_sz = uVar9;
              scatter_elem_sz_prev = uVar9;
            }
            uVar14 = uVar14 + 1;
            bVar1 = 0 < (int)(uVar11 - uVar9);
            if (((int)(uVar11 - uVar9) < 1) || (uVar11 = uVar11 - uVar9, uVar13 <= uVar14))
            goto LAB_0010742c;
          }
          if (uVar14 != 0) {
            uVar12 = 0;
            do {
              __free_pages(*(undefined8 *)(*(long *)(param_1 + 8) + uVar12 * 8),iVar10);
              uVar12 = uVar12 + 1;
            } while (uVar14 != uVar12);
          }
          uVar9 = 0xfffffff4;
          bVar1 = 0 < iVar10;
          iVar10 = iVar10 + -1;
        } while (bVar1);
      }
    }
  }
  return uVar9;
}



//------------------------------------------------------------
// sg_rq_end_io_usercontext @ 00107488 size=276
// signature: undefined sg_rq_end_io_usercontext(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sg_rq_end_io_usercontext(long param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  
  plVar9 = *(long **)(param_1 + -0xf8);
  sg_finish_rem_req(param_1 + -0x108);
  sg_remove_request(plVar9,param_1 + -0x108);
  plVar2 = plVar9 + 0x286;
  Hint_Prefetch(plVar2,2,0,1);
  do {
    iVar3 = (int)*plVar2;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(plVar2,0x10);
    if (bVar5) {
      *(int *)plVar2 = iVar3 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (iVar3 == 1) {
    DataMemoryBarrier(2,1);
    lVar8 = plVar9[2];
    uVar6 = _raw_write_lock_irqsave(lVar8 + 0x68);
    uVar7 = __list_del_entry_valid(plVar9);
    if ((uVar7 & 1) != 0) {
      lVar1 = *plVar9;
      plVar2 = (long *)plVar9[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar9 = -0x2152ffffffffff00;
    plVar9[1] = -0x2152fffffffffede;
    _raw_write_unlock_irqrestore(lVar8 + 0x68,uVar6);
    plVar9[0x287] = 0xfffffffe0;
    plVar9[0x288] = (long)(plVar9 + 0x288);
    plVar9[0x289] = (long)(plVar9 + 0x288);
    plVar9[0x28a] = (long)sg_remove_sfp_usercontext;
    queue_work_on(0x20,_system_wq,plVar9 + 0x287);
  }
  else if (iVar3 < 1) {
    refcount_warn_saturate(plVar2,3);
  }
  return;
}



//------------------------------------------------------------
// sg_remove_sfp_usercontext @ 001075b0 size=492
// signature: undefined sg_remove_sfp_usercontext(void)
// callers: []
//------------------------------------------------------------

void sg_remove_sfp_usercontext(long param_1)

{
  long *plVar1;
  ushort *puVar2;
  long *plVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  undefined8 *puVar11;
  int *piVar12;
  long *plVar13;
  
  puVar11 = *(undefined8 **)(param_1 + -0x1428);
  uVar7 = _raw_write_lock_irqsave(param_1 + -0x1408);
  plVar1 = (long *)(param_1 + -0x13a8);
  plVar13 = (long *)*plVar1;
  while (plVar13 != plVar1) {
    sg_finish_rem_req(plVar13);
    uVar8 = __list_del_entry_valid(plVar13);
    if ((uVar8 & 1) != 0) {
      lVar9 = *plVar13;
      plVar3 = (long *)plVar13[1];
      *(long **)(lVar9 + 8) = plVar3;
      *plVar3 = lVar9;
    }
    plVar13[2] = 0;
    *plVar13 = -0x2152ffffffffff00;
    plVar13[1] = -0x2152fffffffffede;
    plVar13 = (long *)*plVar1;
  }
  _raw_write_unlock_irqrestore(param_1 + -0x1408,uVar7);
  if (*(int *)(param_1 + -0x13c0) != 0) {
    plVar1 = (long *)(param_1 + -0x13b8);
    puVar2 = (ushort *)(param_1 + -0x13c8);
    lVar9 = *plVar1;
    if (((lVar9 != 0) && (*(int *)(param_1 + -0x13c4) != 0)) &&
       (*(char *)(param_1 + -0x13ac) == '\0')) {
      if (*puVar2 != 0) {
        uVar8 = 0;
        do {
          lVar9 = *plVar1;
          lVar10 = *(long *)(lVar9 + uVar8 * 8);
          if (lVar10 == 0) goto LAB_001076d8;
          __free_pages(lVar10,*(undefined4 *)(param_1 + -0x13b0));
          uVar8 = uVar8 + 1;
        } while (uVar8 < *puVar2);
        lVar9 = *plVar1;
      }
LAB_001076d8:
      kfree(lVar9);
    }
    *(undefined8 *)(param_1 + -0x13b8) = 0;
    *(undefined8 *)(param_1 + -0x13b0) = 0;
    puVar2[0] = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(undefined8 *)(param_1 + -0x13c0) = 0;
  }
  kfree(param_1 + -0x1438);
  piVar12 = (int *)(puVar11 + 0x15);
  scsi_device_put(*puVar11);
  Hint_Prefetch(piVar12,2,0,1);
  do {
    iVar4 = *piVar12;
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(piVar12,0x10);
    if (bVar6) {
      *piVar12 = iVar4 + -1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  if (iVar4 == 1) {
    DataMemoryBarrier(2,1);
    uVar7 = _raw_write_lock_irqsave(&sg_index_lock);
    idr_remove(sg_index_idr,*(undefined4 *)((long)puVar11 + 0x54));
    _raw_write_unlock_irqrestore(&sg_index_lock,uVar7);
    kfree(puVar11);
  }
  else if (iVar4 < 1) {
    refcount_warn_saturate(piVar12,3);
  }
  module_put(&__this_module);
  return;
}



//------------------------------------------------------------
// sg_build_reserve @ 001077ac size=204
// signature: undefined sg_build_reserve(void)
// callers: [sg_add_sfp, sg_ioctl]
//------------------------------------------------------------

void sg_build_reserve(long param_1,uint param_2)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  
  psVar1 = (short *)(param_1 + 0x70);
  do {
    if (param_2 < 0x1001) {
      param_2 = 0x1000;
    }
    iVar3 = sg_build_indirect(psVar1,param_1,param_2);
    if (iVar3 == 0) {
      return;
    }
    lVar4 = *(long *)(param_1 + 0x80);
    if (((lVar4 != 0) && (*(int *)(param_1 + 0x74) != 0)) && (*(char *)(param_1 + 0x8c) == '\0')) {
      if (*psVar1 != 0) {
        uVar6 = 0;
        do {
          lVar4 = *(long *)(param_1 + 0x80);
          lVar5 = *(long *)(lVar4 + uVar6 * 8);
          if (lVar5 == 0) goto LAB_001077d8;
          __free_pages(lVar5,*(undefined4 *)(param_1 + 0x88));
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(ushort *)(param_1 + 0x70));
        lVar4 = *(long *)(param_1 + 0x80);
      }
LAB_001077d8:
      kfree(lVar4);
    }
    uVar2 = param_2 >> 1;
    *(undefined8 *)(param_1 + 0x80) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
    psVar1[0] = 0;
    psVar1[1] = 0;
    psVar1[2] = 0;
    psVar1[3] = 0;
    *(undefined8 *)(param_1 + 0x78) = 0;
    param_2 = (int)param_2 >> 1;
    if (uVar2 < 0x801) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// sg_vma_fault @ 0010787c size=208
// signature: undefined sg_vma_fault(void)
// callers: []
//------------------------------------------------------------

undefined8 sg_vma_fault(undefined8 *param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong *puVar10;
  ulong uVar11;
  
  puVar10 = (ulong *)*param_1;
  if ((((puVar10 != (ulong *)0x0) && (uVar5 = puVar10[0x12], uVar5 != 0)) &&
      ((ulong)(param_1[2] << 0xc) < (ulong)*(uint *)(uVar5 + 0x78))) &&
     (*(ushort *)(uVar5 + 0x70) != 0)) {
    lVar7 = 0;
    uVar9 = *puVar10;
    uVar11 = (ulong)(1 << (ulong)(*(int *)(uVar5 + 0x88) + 0xcU & 0x1f));
    uVar8 = param_1[2] << 0xc;
    do {
      uVar4 = puVar10[1] - uVar9;
      if (puVar10[1] < uVar9 || uVar4 == 0) {
        return 2;
      }
      if (uVar11 <= uVar4) {
        uVar4 = uVar11;
      }
      if (uVar8 < uVar4) {
        lVar7 = *(long *)(*(long *)(uVar5 + 0x80) + lVar7) + (uVar8 >> 0xc) * 0x40;
        lVar6 = lVar7;
        if ((*(ulong *)(lVar7 + 8) & 1) != 0) {
          lVar6 = *(ulong *)(lVar7 + 8) - 1;
        }
        piVar1 = (int *)(lVar6 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = *piVar1 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        param_1[10] = lVar7;
        return 0;
      }
      uVar9 = uVar4 + uVar9;
      lVar7 = lVar7 + 8;
      uVar8 = uVar8 - uVar4;
    } while ((uint)*(ushort *)(uVar5 + 0x70) * 8 != (int)lVar7);
  }
  return 2;
}



//------------------------------------------------------------
// open_wait @ 00107958 size=480
// signature: undefined open_wait(void)
// callers: [sg_open]
//------------------------------------------------------------

ulong open_wait(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x20;
  lVar2 = param_1 + 8;
  if ((param_2 >> 7 & 1) == 0) {
    do {
      if (*(char *)(param_1 + 0x74) == '\0') goto LAB_00107af8;
      mutex_unlock(lVar1);
      if ((*(int *)(param_1 + 0x70) == 0) && (*(char *)(param_1 + 0x74) != '\0')) {
        local_48 = 0;
        uStack_40 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_60 = 0;
        init_wait_entry(&local_60,0);
        uVar3 = prepare_to_wait_event(lVar2,&local_60,1);
        if (*(int *)(param_1 + 0x70) == 0) {
          do {
            if (*(char *)(param_1 + 0x74) == '\0') break;
            if (uVar3 != 0) {
              mutex_lock(lVar1);
              if ((int)uVar3 == 0) goto LAB_001079f0;
              goto LAB_00107b04;
            }
            schedule();
            uVar3 = prepare_to_wait_event(lVar2,&local_60,1);
          } while (*(int *)(param_1 + 0x70) == 0);
        }
        finish_wait(lVar2,&local_60);
      }
      mutex_lock(lVar1);
LAB_001079f0:
    } while (*(int *)(param_1 + 0x70) == 0);
  }
  else {
    do {
      if (*(int *)(param_1 + 0x78) < 1) goto LAB_00107af8;
      mutex_unlock(lVar1);
      if ((*(int *)(param_1 + 0x70) == 0) && (*(int *)(param_1 + 0x78) != 0)) {
        local_48 = 0;
        uStack_40 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_60 = 0;
        init_wait_entry(&local_60,0);
        uVar3 = prepare_to_wait_event(lVar2,&local_60,1);
        if (*(int *)(param_1 + 0x70) == 0) {
          do {
            if (*(int *)(param_1 + 0x78) == 0) break;
            if (uVar3 != 0) {
              mutex_lock(lVar1);
              if ((int)uVar3 == 0) goto LAB_00107aa8;
              goto LAB_00107b04;
            }
            schedule();
            uVar3 = prepare_to_wait_event(lVar2,&local_60,1);
          } while (*(int *)(param_1 + 0x70) == 0);
        }
        finish_wait(lVar2,&local_60);
      }
      mutex_lock(lVar1);
LAB_00107aa8:
    } while (*(int *)(param_1 + 0x70) == 0);
  }
  uVar3 = 0xffffffed;
LAB_00107b04:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
LAB_00107af8:
  uVar3 = 0;
  goto LAB_00107b04;
}



//------------------------------------------------------------
// sg_add_sfp @ 00107b38 size=456
// signature: undefined sg_add_sfp(void)
// callers: [sg_open]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * sg_add_sfp(long *param_1)

{
  long *plVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  uint *puVar9;
  undefined8 *puVar10;
  
  plVar5 = (long *)kmalloc_trace(_cdev_del,0x2b20,0x1468);
  if (plVar5 == (long *)0x0) {
    return (long *)0xfffffffffffffff4;
  }
  __init_waitqueue_head(plVar5 + 3,"&sfp->read_wait",&sg_add_sfp___key);
  plVar5[6] = 0;
  plVar5[0x12] = (long)(plVar5 + 0x12);
  plVar5[0x13] = (long)(plVar5 + 0x12);
  *(undefined4 *)(plVar5 + 0x286) = 1;
  __mutex_init(plVar5 + 7,"&sfp->f_mutex",&sg_add_sfp___key_23);
  *(undefined2 *)(plVar5 + 0x285) = 0;
  *(undefined1 *)((long)plVar5 + 0x142b) = 0;
  plVar1 = param_1 + 0xd;
  plVar5[2] = (long)param_1;
  plVar5[0xd] = 0x177000003a98;
  uVar6 = _raw_write_lock_irqsave(plVar1);
  if ((int)param_1[0xe] != 0) {
    _raw_write_unlock_irqrestore(plVar1,uVar6);
    kfree(plVar5);
    return (long *)0xffffffffffffffed;
  }
  puVar10 = (undefined8 *)param_1[0xc];
  uVar7 = __list_add_valid(plVar5,puVar10,param_1 + 0xb);
  if ((uVar7 & 1) != 0) {
    param_1[0xc] = (long)plVar5;
    *plVar5 = (long)(param_1 + 0xb);
    plVar5[1] = (long)puVar10;
    *puVar10 = plVar5;
  }
  _raw_write_unlock_irqrestore(plVar1,uVar6);
  if (sg_big_buff != def_reserved_size) {
    sg_big_buff = def_reserved_size;
  }
  puVar9 = (uint *)(param_1 + 0x15);
  uVar8 = *(uint *)(*(long *)(*param_1 + 8) + 0x204);
  if (0x3ffffe < uVar8) {
    uVar8 = 0x3fffff;
  }
  iVar2 = sg_big_buff;
  if ((int)(uVar8 * 0x200) <= sg_big_buff) {
    iVar2 = uVar8 * 0x200;
  }
  sg_build_reserve(plVar5,iVar2);
  Hint_Prefetch(puVar9,2,0,1);
  do {
    uVar8 = *puVar9;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar9,0x10);
    if (bVar4) {
      *puVar9 = uVar8 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar8 == 0) {
    uVar6 = 2;
  }
  else {
    if (-1 < (int)(uVar8 + 1 | uVar8)) goto LAB_00107ca8;
    uVar6 = 1;
  }
  refcount_warn_saturate(puVar9,uVar6);
LAB_00107ca8:
  __module_get(&__this_module);
  return plVar5;
}



//------------------------------------------------------------
// init_module @ 001082b8 size=272
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  ulong uVar1;
  ulong uVar2;
  
  if (scatter_elem_sz < 0x1000) {
    scatter_elem_sz = 0x1000;
    scatter_elem_sz_prev = 0x1000;
  }
  if (-1 < def_reserved_size) {
    sg_big_buff = def_reserved_size;
  }
  def_reserved_size = sg_big_buff;
  uVar1 = register_chrdev_region(0x1500000,0x8000,&DAT_00108eca);
  uVar2 = uVar1 & 0xffffffff;
  if ((int)uVar1 == 0) {
    uVar2 = __class_create(&__this_module,"scsi_generic",&init_sg___key);
    sg_sysfs_class = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      sg_sysfs_valid = 1;
      uVar1 = scsi_register_interface(sg_interface);
      uVar2 = uVar1 & 0xffffffff;
      if ((int)uVar1 == 0) goto LAB_001083b4;
      class_destroy(sg_sysfs_class);
      if (hdr == 0) {
        hdr = register_sysctl("kernel",&sg_sysctls);
      }
    }
    unregister_chrdev_region(0x1500000,0x8000);
  }
LAB_001083b4:
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 001083cc size=96
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (hdr != 0) {
    unregister_sysctl_table();
  }
  class_interface_unregister(sg_interface);
  class_destroy(sg_sysfs_class);
  sg_sysfs_valid = 0;
  unregister_chrdev_region(0x1500000,0x8000);
  idr_destroy(sg_index_idr);
  return;
}



//------------------------------------------------------------
// register_chrdev_region @ 0010b000 size=1
// signature: undefined register_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0010b008 size=1
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
// scsi_register_interface @ 0010b010 size=1
// signature: undefined scsi_register_interface(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_register_interface(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0010b018 size=1
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
// register_sysctl @ 0010b020 size=1
// signature: undefined register_sysctl(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_sysctl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0010b028 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_sysctl_table @ 0010b030 size=1
// signature: undefined unregister_sysctl_table(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_sysctl_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_interface_unregister @ 0010b038 size=1
// signature: undefined class_interface_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_interface_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 0010b040 size=1
// signature: undefined idr_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_alloc @ 0010b048 size=1
// signature: undefined cdev_alloc(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010b058 size=1
// signature: undefined kmalloc_trace(void)
// callers: [sg_add_device, sg_add_sfp, sg_ioctl, sg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_preload @ 0010b060 size=1
// signature: undefined idr_preload(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_preload(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irqsave @ 0010b068 size=1
// signature: undefined _raw_write_lock_irqsave(void)
// callers: [sg_remove_request, sg_add_device, sg_remove_device, sg_add_sfp, sg_open, sg_new_write, sg_remove_sfp_usercontext, sg_get_rq_mark, sg_rq_end_io_usercontext, sg_add_request, sg_read, sg_release, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 0010b070 size=1
// signature: undefined idr_alloc(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 0010b078 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010b080 size=1
// signature: undefined __mutex_init(void)
// callers: [sg_add_device, sg_add_sfp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010b088 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [sg_add_device, sg_add_sfp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sdev_prefix_printk @ 0010b090 size=1
// signature: undefined sdev_prefix_printk(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sdev_prefix_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irqrestore @ 0010b098 size=1
// signature: undefined _raw_write_unlock_irqrestore(void)
// callers: [sg_remove_request, sg_add_device, sg_remove_device, sg_add_sfp, sg_open, sg_new_write, sg_remove_sfp_usercontext, sg_get_rq_mark, sg_rq_end_io_usercontext, sg_add_request, sg_read, sg_release, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010b0a0 size=1
// signature: undefined kfree(void)
// callers: [sg_add_device, sg_finish_rem_req, sg_build_reserve, sg_remove_device, sg_add_sfp, sg_ioctl, sg_open, sg_read, sg_remove_sfp_usercontext]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 0010b0a8 size=1
// signature: undefined cdev_add(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 0010b0b0 size=1
// signature: undefined idr_remove(void)
// callers: [sg_add_device, sg_remove_device, sg_open, sg_remove_sfp_usercontext]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 0010b0b8 size=1
// signature: undefined cdev_del(void)
// callers: [sg_add_device, sg_remove_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0010b0c0 size=1
// signature: undefined device_create(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_link @ 0010b0c8 size=1
// signature: undefined sysfs_create_link(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010b0d0 size=1
// signature: undefined _printk(void)
// callers: [sg_add_device, sg_write, sg_read, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 0010b0d8 size=1
// signature: undefined preempt_schedule(void)
// callers: [sg_add_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irqsave @ 0010b0e8 size=1
// signature: undefined _raw_read_lock_irqsave(void)
// callers: [sg_poll, sg_remove_device, sg_ioctl, sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010b0f0 size=1
// signature: undefined __wake_up(void)
// callers: [sg_remove_request, sg_remove_device, sg_open, sg_new_write, sg_release, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kill_fasync @ 0010b0f8 size=1
// signature: undefined kill_fasync(void)
// callers: [sg_remove_device, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kill_fasync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irqrestore @ 0010b100 size=1
// signature: undefined _raw_read_unlock_irqrestore(void)
// callers: [sg_poll, sg_remove_device, sg_ioctl, sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_link @ 0010b108 size=1
// signature: undefined sysfs_remove_link(void)
// callers: [sg_remove_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 0010b110 size=1
// signature: undefined device_destroy(void)
// callers: [sg_remove_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010b118 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [sg_rq_end_io_usercontext, sg_remove_device, sg_add_sfp, sg_open, sg_common_write, sg_remove_sfp_usercontext, sg_release, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010b128 size=1
// signature: undefined init_wait_entry(void)
// callers: [open_wait, sg_ioctl, sg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010b130 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [open_wait, sg_ioctl, sg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0010b138 size=1
// signature: undefined schedule(void)
// callers: [open_wait, sg_ioctl, sg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010b140 size=1
// signature: undefined finish_wait(void)
// callers: [open_wait, sg_ioctl, sg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0010b148 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [sg_new_read, sg_ioctl, sg_read, sg_read_oxfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __task_pid_nr_ns @ 0010b150 size=1
// signature: undefined __task_pid_nr_ns(void)
// callers: [sg_write, sg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __task_pid_nr_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010b158 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [open_wait, sg_write, sg_ioctl, sg_new_write, sg_common_write, sg_read, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_block_when_processing_errors @ 0010b168 size=1
// signature: undefined scsi_block_when_processing_errors(void)
// callers: [sg_write, sg_ioctl, sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_block_when_processing_errors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0010b170 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [sg_write, sg_new_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010b178 size=1
// signature: undefined mutex_lock(void)
// callers: [open_wait, sg_write, sg_ioctl, sg_open, sg_mmap, sg_common_write, sg_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010b188 size=1
// signature: undefined mutex_unlock(void)
// callers: [open_wait, sg_write, sg_ioctl, sg_open, sg_mmap, sg_common_write, sg_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0010b190 size=1
// signature: undefined __check_object_size(void)
// callers: [sg_write, sg_new_read, sg_new_write, sg_read_oxfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010b198 size=1
// signature: undefined ___ratelimit(void)
// callers: [sg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __copy_overflow @ 0010b1a0 size=1
// signature: undefined __copy_overflow(void)
// callers: [sg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __copy_overflow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010b1a8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [sg_write, sg_add_request, sg_new_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_ioctl @ 0010b1b0 size=1
// signature: undefined scsi_ioctl(void)
// callers: [sg_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_ioctl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_ioctl_block_when_processing_errors @ 0010b1b8 size=1
// signature: undefined scsi_ioctl_block_when_processing_errors(void)
// callers: [sg_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_ioctl_block_when_processing_errors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 0010b1c8 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [sg_ioctl, sg_add_request, sg_common_write, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irq @ 0010b1d0 size=1
// signature: undefined _raw_write_lock_irq(void)
// callers: [sg_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irq @ 0010b1d8 size=1
// signature: undefined _raw_write_unlock_irq(void)
// callers: [sg_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 0010b1e0 size=1
// signature: undefined __free_pages(void)
// callers: [sg_finish_rem_req, sg_build_reserve, sg_ioctl, sg_build_indirect, sg_remove_sfp_usercontext]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 0010b1e8 size=1
// signature: undefined down_write(void)
// callers: [sg_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 0010b1f0 size=1
// signature: undefined up_write(void)
// callers: [sg_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nonseekable_open @ 0010b1f8 size=1
// signature: undefined nonseekable_open(void)
// callers: [sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 0010b200 size=1
// signature: undefined idr_find(void)
// callers: [sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_device_get @ 0010b208 size=1
// signature: undefined scsi_device_get(void)
// callers: [sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_device_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_autopm_get_device @ 0010b210 size=1
// signature: undefined scsi_autopm_get_device(void)
// callers: [sg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_autopm_get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_autopm_put_device @ 0010b218 size=1
// signature: undefined scsi_autopm_put_device(void)
// callers: [sg_open, sg_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_autopm_put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_device_put @ 0010b220 size=1
// signature: undefined scsi_device_put(void)
// callers: [sg_open, sg_remove_sfp_usercontext]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_device_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010b228 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [sg_remove_request, sg_rq_end_io_usercontext, sg_new_write, sg_remove_sfp_usercontext, sg_release, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010b238 size=1
// signature: undefined queue_work_on(void)
// callers: [sg_rq_end_io_usercontext, sg_release, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fasync_helper @ 0010b240 size=1
// signature: undefined fasync_helper(void)
// callers: [sg_fasync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fasync_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_sg_io_hdr @ 0010b248 size=1
// signature: undefined put_sg_io_hdr(void)
// callers: [sg_new_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_sg_io_hdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_rq_unmap_user @ 0010b258 size=1
// signature: undefined blk_rq_unmap_user(void)
// callers: [sg_finish_rem_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_rq_unmap_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_mq_free_request @ 0010b260 size=1
// signature: undefined blk_mq_free_request(void)
// callers: [sg_finish_rem_req, sg_common_write, sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_mq_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_sg_io_hdr @ 0010b268 size=1
// signature: undefined get_sg_io_hdr(void)
// callers: [sg_new_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_sg_io_hdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0010b270 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [sg_new_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010b278 size=1
// signature: undefined __list_add_valid(void)
// callers: [sg_add_sfp, sg_add_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_alloc_request @ 0010b280 size=1
// signature: undefined scsi_alloc_request(void)
// callers: [sg_common_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010b288 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [sg_common_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_rq_map_user_io @ 0010b290 size=1
// signature: undefined blk_rq_map_user_io(void)
// callers: [sg_common_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_rq_map_user_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_execute_rq_nowait @ 0010b298 size=1
// signature: undefined blk_execute_rq_nowait(void)
// callers: [sg_common_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_execute_rq_nowait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_cmd_allowed @ 0010b2a0 size=1
// signature: undefined scsi_cmd_allowed(void)
// callers: [sg_allow_access]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_cmd_allowed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __scsi_print_sense @ 0010b2a8 size=1
// signature: undefined __scsi_print_sense(void)
// callers: [sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __scsi_print_sense(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_normalize_sense @ 0010b2b0 size=1
// signature: undefined scsi_normalize_sense(void)
// callers: [sg_rq_end_io]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_normalize_sense(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010b2b8 size=1
// signature: undefined __kmalloc(void)
// callers: [sg_build_indirect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 0010b2c0 size=1
// signature: undefined __alloc_pages(void)
// callers: [sg_build_indirect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 0010b2c8 size=1
// signature: undefined module_put(void)
// callers: [sg_remove_sfp_usercontext]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __module_get @ 0010b2d0 size=1
// signature: undefined __module_get(void)
// callers: [sg_add_sfp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



