// Decompiled by Ghidra 12.2
// Program: sync_fence.ko
// Image base: 00100000

//------------------------------------------------------------
// spec_sync_wait_bind_array @ 0010061c size=336
// signature: undefined spec_sync_wait_bind_array(void)
// callers: []
//------------------------------------------------------------

void spec_sync_wait_bind_array(long param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((param_1 == 0) || (((uint)*(undefined8 *)(param_1 + 0x30) >> 0x10 & 1) == 0)) {
    _printk(&DAT_00101d12,"spec_sync_wait_bind_array");
    uVar2 = 0xffffffea;
  }
  else {
    if (((uint)*(undefined8 *)(param_1 + 0x30) >> 0x11 & 1) == 0) {
      lVar1 = __msecs_to_jiffies(param_2);
      uVar3 = (uint)*(undefined8 *)(param_1 + 0x30);
      if (((uint)(lVar1 == 0) & uVar3 >> 0x11) != 0) {
        lVar1 = 1;
      }
      if (((uVar3 >> 0x11 & 1) == 0) && (lVar1 != 0)) {
        local_48 = 0;
        uStack_40 = 0;
        local_58 = 0;
        uStack_50 = 0;
        local_60 = 0;
        lVar1 = __msecs_to_jiffies(param_2);
        init_wait_entry(&local_60,0);
        while( true ) {
          prepare_to_wait_event(&DAT_001021d0,&local_60,2);
          uVar3 = (uint)*(undefined8 *)(param_1 + 0x30);
          if (((uint)(lVar1 == 0) & uVar3 >> 0x11) != 0) {
            lVar1 = 1;
          }
          if (((uVar3 >> 0x11 & 1) != 0) || (lVar1 == 0)) break;
          lVar1 = schedule_timeout(lVar1);
        }
        finish_wait(&DAT_001021d0,&local_60);
      }
      if ((int)lVar1 == 0) {
        _printk(&DAT_001020cc,"spec_sync_wait_bind_array",param_2);
        uVar2 = 0xffffff92;
        goto LAB_00100700;
      }
    }
    uVar2 = 0;
  }
LAB_00100700:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// spec_sync_ioctl @ 00100770 size=3048
// signature: undefined spec_sync_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long spec_sync_ioctl(long param_1,int param_2,ulong param_3)

{
  uint *puVar1;
  int *piVar2;
  ulong *puVar3;
  int iVar4;
  bool bVar5;
  char cVar6;
  ulong uVar7;
  long *plVar8;
  code *pcVar9;
  bool bVar10;
  int iVar11;
  undefined4 uVar12;
  long lVar13;
  long lVar14;
  undefined4 *puVar15;
  size_t __n;
  undefined *puVar16;
  long lVar17;
  undefined8 *puVar18;
  long *plVar19;
  undefined8 uVar20;
  uint uVar21;
  ulong uVar22;
  undefined8 *puVar23;
  ulong uVar24;
  undefined8 *puVar25;
  int iVar26;
  size_t sVar27;
  long *plVar28;
  uint uVar29;
  ulong local_78;
  ulong local_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  uVar29 = (uint)_cpu_hwcaps;
  if (param_2 == -0x3ff7c1fb) {
    puVar25 = (undefined8 *)sp_el0;
    local_78 = CONCAT44(local_78._4_4_,*(undefined4 *)(*(long *)(param_1 + 0xd8) + 0x7c));
    if (((*(byte *)((long)puVar25 + 0x46) >> 5 & 1) != 0) ||
       (uVar22 = param_3, ((uint)*puVar25 >> 0x1a & 1) != 0)) {
      uVar22 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar22 < 0x7ffffffffd) {
      if ((uVar29 >> 0x1d & 1) == 0) {
        uVar22 = daif;
        if ((uVar22 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        puVar25 = (undefined8 *)puVar25[1];
        uVar24 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar25 & 0xffff000000000000 | uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar25;
        InstructionSynchronizationBarrier();
        daif = uVar22;
      }
      lVar13 = __arch_copy_to_user(puVar25,param_3 & 0xff7fffffffffffff,&local_78,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar22 = daif;
        if ((uVar22 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar22;
      }
LAB_00100d28:
      iVar11 = 0;
      if (lVar13 != 0) {
        iVar11 = -0xe;
      }
      goto LAB_001013cc;
    }
  }
  else if (param_2 == -0x3fefc1fd) {
    puVar25 = (undefined8 *)sp_el0;
    local_78 = 0;
    local_70 = 0;
    if (((*(byte *)((long)puVar25 + 0x46) >> 5 & 1) != 0) ||
       (uVar22 = param_3, ((uint)*puVar25 >> 0x1a & 1) != 0)) {
      uVar22 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar22 < 0x7ffffffff1) {
      if ((uVar29 >> 0x1d & 1) == 0) {
        uVar22 = daif;
        if ((uVar22 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr1_el1 = puVar25[1] & 0xffff000000000000 | uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar25[1];
        InstructionSynchronizationBarrier();
        daif = uVar22;
      }
      lVar13 = __arch_copy_from_user(&local_78,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar22 = daif;
        if ((uVar22 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar22;
      }
      if (lVar13 == 0) {
        puVar18 = (undefined8 *)sync_file_get_fence(local_78 & 0xffffffff);
        if (puVar18 == (undefined8 *)0x0) {
          _printk(&DAT_00101ece,"spec_sync_bind_array",local_78 & 0xffffffff);
          iVar11 = -0x16;
          goto LAB_001013cc;
        }
        if ((puVar18[6] & 1) == 0) {
          pcVar9 = *(code **)(puVar18[1] + 0x20);
          if (pcVar9 != (code *)0x0) {
            if (*(int *)(pcVar9 + -4) != -0xc4a187e) {
                    /* WARNING: Does not return */
              pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x100a04);
              (*pcVar9)();
            }
            uVar22 = (*pcVar9)(puVar18);
            if ((uVar22 & 1) != 0) {
              dma_fence_signal(puVar18);
              goto LAB_00100e90;
            }
          }
          mutex_lock(&DAT_00102190);
          puVar23 = &DAT_001021c0;
          do {
            puVar23 = (undefined8 *)*puVar23;
            if (puVar23 == &DAT_001021c0) {
              mutex_unlock(&DAT_00102190);
              puVar16 = &DAT_00101d28;
              goto LAB_00100e9c;
            }
          } while ((undefined8 *)puVar23[-1] != puVar18);
          mutex_unlock(&DAT_00102190);
          uVar22 = local_78;
          uVar29 = *(uint *)((long)puVar18 + 0x44);
          if (uVar29 != 0) {
            uVar21 = 0;
            do {
              lVar13 = *(long *)(puVar18[10] + (long)(int)uVar21 * 8);
              if ((*(long *)(lVar13 + 0x20) != -0x505252505052526) ||
                 (*(long *)(lVar13 + 0x28) != -0x105631ff10563200)) {
                uVar12 = dma_fence_get_status(puVar18);
                _printk(&DAT_00101e00,"spec_sync_bind_array",uVar22 & 0xffffffff,uVar12,puVar18[6]);
                goto LAB_00100ea8;
              }
              uVar21 = uVar21 + 1;
            } while (uVar29 != uVar21);
          }
          sVar27 = (ulong)uVar29 * 4;
          puVar15 = (undefined4 *)__kmalloc(sVar27,0xdc0);
          uVar22 = local_70;
          if (puVar15 == (undefined4 *)0x0) {
            iVar11 = -0xc;
          }
          else {
            if (uVar29 >> 0x1d != 0) {
                    /* WARNING: Does not return */
              pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101204);
              (*pcVar9)();
            }
            __check_object_size(puVar15,sVar27,0);
            if (((*(byte *)((long)puVar25 + 0x46) >> 5 & 1) != 0) ||
               (uVar24 = uVar22, ((uint)*puVar25 >> 0x1a & 1) != 0)) {
              uVar24 = uVar22 & (long)(uVar22 << 8) >> 8;
            }
            __n = sVar27;
            if (uVar24 <= (ulong)uVar29 * -4 + 0x8000000000) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar24 = daif;
                if ((uVar24 & 0x80) == 0) {
                  uVar7 = daif;
                  daif = uVar7 | 0xc0;
                }
                uVar7 = ttbr1_el1;
                ttbr1_el1 = puVar25[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar25[1];
                InstructionSynchronizationBarrier();
                daif = uVar24;
              }
              __n = __arch_copy_from_user(puVar15,uVar22 & 0xff7fffffffffffff,sVar27);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar22 = daif;
                if ((uVar22 & 0x80) == 0) {
                  uVar24 = daif;
                  daif = uVar24 | 0xc0;
                }
                uVar24 = ttbr1_el1;
                ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar24 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar22;
              }
            }
            if (__n == 0) {
              _raw_spin_lock(*puVar18);
              if (uVar29 == 0) {
LAB_00100d38:
                puVar3 = puVar18 + 6;
                Hint_Prefetch(puVar3,2,0,1);
                do {
                  cVar6 = '\x01';
                  bVar10 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                  if (bVar10) {
                    *puVar3 = *puVar3 & 0xfffffffffffffffb;
                    cVar6 = ExclusiveMonitorsStatus();
                  }
                } while (cVar6 != '\0');
                _raw_spin_unlock(*puVar18);
                dma_fence_enable_sw_signaling(puVar18);
                clear_fence_array_tracker(0);
                bVar10 = false;
                iVar26 = 0;
              }
              else {
                lVar13 = sync_file_get_fence(*puVar15);
                lVar14 = 0;
                if (lVar13 == 0) {
                  bVar10 = true;
                }
                else {
                  do {
                    *(long *)(puVar18[10] + lVar14 * 8) = lVar13;
                    if (DAT_00102160 != 0) {
                      piVar2 = (int *)(DAT_00102160 + 0x38);
                      Hint_Prefetch(piVar2,2,0,1);
                      do {
                        iVar11 = *piVar2;
                        cVar6 = '\x01';
                        bVar10 = (bool)ExclusiveMonitorPass(piVar2,0x10);
                        if (bVar10) {
                          *piVar2 = iVar11 + -1;
                          cVar6 = ExclusiveMonitorsStatus();
                        }
                      } while (cVar6 != '\0');
                      if (iVar11 == 1) {
                        DataMemoryBarrier(2,1);
                        dma_fence_release();
                      }
                      else if (iVar11 < 1) {
                        refcount_warn_saturate(piVar2,3);
                      }
                    }
                    uVar21 = (int)lVar14 + 1;
                    if (uVar21 == uVar29) goto LAB_00100d38;
                    lVar14 = (long)(int)uVar21;
                    lVar13 = sync_file_get_fence(puVar15[(int)uVar21]);
                  } while (lVar13 != 0);
                  bVar10 = uVar21 < uVar29;
                }
                _printk(&DAT_00101f1d,"spec_sync_bind_array",puVar15[lVar14],local_78 & 0xffffffff);
                iVar26 = -0x16;
              }
              puVar3 = puVar18 + 6;
              Hint_Prefetch(puVar3,2,0,1);
              do {
                cVar6 = '\x01';
                bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar5) {
                  *puVar3 = *puVar3 | 0x20000;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              __wake_up(&DAT_001021d0,3,0,0);
              iVar11 = 0;
              if (bVar10) {
                if ((puVar18[6] & 1) != 0) {
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101228);
                  (*pcVar9)();
                }
                *(undefined4 *)((long)puVar18 + 0x3c) = 0xffffffea;
                _raw_spin_unlock(*puVar18);
                dma_fence_signal(puVar18);
                clear_fence_array_tracker(0);
                iVar11 = iVar26;
              }
            }
            else {
              memset((void *)((long)puVar15 + (sVar27 - __n)),0,__n);
              iVar11 = -0xe;
            }
            kfree(puVar15);
          }
        }
        else {
LAB_00100e90:
          puVar16 = &DAT_0010200f;
LAB_00100e9c:
          _printk(puVar16,"spec_sync_bind_array",(uint)local_78);
LAB_00100ea8:
          iVar11 = -0x16;
        }
        piVar2 = (int *)(puVar18 + 7);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          iVar26 = *piVar2;
          cVar6 = '\x01';
          bVar10 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar10) {
            *piVar2 = iVar26 + -1;
            cVar6 = ExclusiveMonitorsStatus();
          }
        } while (cVar6 != '\0');
        if (iVar26 == 1) {
          DataMemoryBarrier(2,1);
          dma_fence_release();
        }
        else if (iVar26 < 1) {
          refcount_warn_saturate(piVar2,3);
        }
        goto LAB_001013cc;
      }
    }
  }
  else {
    if (param_2 != -0x3ff3c1fc) {
      iVar11 = -0x19;
      goto LAB_001013cc;
    }
    puVar25 = (undefined8 *)sp_el0;
    local_70 = local_70 & 0xffffffff00000000;
    local_78 = 0;
    if (((*(byte *)((long)puVar25 + 0x46) >> 5 & 1) != 0) ||
       (uVar22 = param_3, ((uint)*puVar25 >> 0x1a & 1) != 0)) {
      uVar22 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar22 < 0x7ffffffff5) {
      if ((uVar29 >> 0x1d & 1) == 0) {
        uVar22 = daif;
        if ((uVar22 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr1_el1 = puVar25[1] & 0xffff000000000000 | uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar25[1];
        InstructionSynchronizationBarrier();
        daif = uVar22;
      }
      lVar13 = __arch_copy_from_user(&local_78,param_3 & 0xff7fffffffffffff,0xc);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar22 = daif;
        if ((uVar22 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar22;
      }
      if (lVar13 == 0) {
        iVar11 = get_unused_fd_flags(0x80000);
        lVar13 = DAT_00102160;
        if (iVar11 < 0) {
          _printk(&DAT_00101fea,"spec_sync_create_array");
          goto LAB_001013cc;
        }
        if ((uint)local_78 - 0x21 < 0xffffffe0) {
          _printk(&DAT_00101cdc,"spec_sync_create_array");
          iVar26 = -0x22;
        }
        else {
          uVar22 = (local_78 & 0xffffffff) * 8;
          lVar14 = __kmalloc(uVar22,0xdc0);
          if (lVar14 == 0) {
            iVar26 = -0xc;
          }
          else {
            if ((uint)local_78 == 0) {
              uVar29 = 0;
            }
            else {
              uVar21 = 0;
              puVar1 = (uint *)(lVar13 + 0x38);
              do {
                if ((uVar22 <= (ulong)((long)(int)uVar21 * 8)) ||
                   (uVar22 <= (ulong)((long)(int)uVar21 * 8))) {
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(1,0x101230);
                  (*pcVar9)();
                }
                *(long *)(lVar14 + (long)(int)uVar21 * 8) = lVar13;
                if (lVar13 != 0) {
                  Hint_Prefetch(puVar1,2,0,1);
                  do {
                    uVar29 = *puVar1;
                    cVar6 = '\x01';
                    bVar10 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                    if (bVar10) {
                      *puVar1 = uVar29 + 1;
                      cVar6 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar6 != '\0');
                  if (uVar29 == 0) {
                    uVar20 = 2;
                  }
                  else {
                    if (-1 < (int)(uVar29 + 1 | uVar29)) goto LAB_00100f10;
                    uVar20 = 1;
                  }
                  refcount_warn_saturate(puVar1,uVar20);
                }
LAB_00100f10:
                uVar21 = uVar21 + 1;
                uVar29 = (uint)local_78;
              } while (uVar21 < (uint)local_78);
            }
            uVar22 = local_78 & 0x200000000;
            uVar20 = dma_fence_context_alloc(1);
            lVar17 = dma_fence_array_create(uVar29,lVar14,uVar20,0,uVar22 == 0);
            if (lVar17 == 0) {
              if ((uint)local_78 != 0) {
                uVar29 = 0;
                piVar2 = (int *)(lVar13 + 0x38);
                do {
                  if (lVar13 != 0) {
                    Hint_Prefetch(piVar2,2,0,1);
                    do {
                      iVar26 = *piVar2;
                      cVar6 = '\x01';
                      bVar10 = (bool)ExclusiveMonitorPass(piVar2,0x10);
                      if (bVar10) {
                        *piVar2 = iVar26 + -1;
                        cVar6 = ExclusiveMonitorsStatus();
                      }
                    } while (cVar6 != '\0');
                    if (iVar26 == 1) {
                      DataMemoryBarrier(2,1);
                      dma_fence_release(piVar2);
                    }
                    else if (iVar26 < 1) {
                      refcount_warn_saturate(piVar2,3);
                    }
                  }
                  uVar29 = uVar29 + 1;
                } while (uVar29 < (uint)local_78);
              }
              kfree(lVar14);
              iVar26 = -0x16;
            }
            else {
              puVar3 = (ulong *)(lVar17 + 0x30);
              Hint_Prefetch(puVar3,2,0,1);
              do {
                cVar6 = '\x01';
                bVar10 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar10) {
                  *puVar3 = *puVar3 | 4;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              puVar3 = (ulong *)(lVar17 + 0x30);
              Hint_Prefetch(puVar3,2,0,1);
              do {
                cVar6 = '\x01';
                bVar10 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar10) {
                  *puVar3 = *puVar3 | 0x10000;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              puVar18 = (undefined8 *)sync_file_create(lVar17);
              if (puVar18 == (undefined8 *)0x0) {
                _printk(&DAT_00101d84,"spec_sync_create_array");
                iVar26 = -0x16;
              }
              else {
                plVar19 = (long *)kmalloc_trace(_cpu_hwcaps,0xdc0,0x18);
                if (plVar19 != (long *)0x0) {
                  fd_install(iVar11);
                  plVar28 = plVar19 + 1;
                  *plVar19 = lVar17;
                  mutex_lock(&DAT_00102190);
                  plVar8 = DAT_001021c8;
                  uVar22 = __list_add_valid(plVar28,DAT_001021c8,&DAT_001021c0);
                  if ((uVar22 & 1) != 0) {
                    DAT_001021c8 = plVar28;
                    plVar19[1] = (long)&DAT_001021c0;
                    plVar19[2] = (long)plVar8;
                    *plVar8 = (long)plVar28;
                  }
                  mutex_unlock(&DAT_00102190);
                  local_70 = CONCAT44(local_70._4_4_,iVar11);
                  if (((*(byte *)((long)puVar25 + 0x46) >> 5 & 1) != 0) ||
                     (uVar22 = param_3, ((uint)*puVar25 >> 0x1a & 1) != 0)) {
                    uVar22 = param_3 & (long)(param_3 << 8) >> 8;
                  }
                  if (uVar22 < 0x7ffffffff5) {
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar22 = daif;
                      if ((uVar22 & 0x80) == 0) {
                        uVar24 = daif;
                        daif = uVar24 | 0xc0;
                      }
                      uVar24 = ttbr1_el1;
                      ttbr1_el1 = puVar25[1] & 0xffff000000000000 | uVar24 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      ttbr0_el1 = puVar25[1];
                      InstructionSynchronizationBarrier();
                      daif = uVar22;
                    }
                    lVar13 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_78,0xc);
                    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                      uVar22 = daif;
                      if ((uVar22 & 0x80) == 0) {
                        uVar24 = daif;
                        daif = uVar24 | 0xc0;
                      }
                      uVar24 = ttbr1_el1;
                      ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
                      InstructionSynchronizationBarrier();
                      ttbr1_el1 = uVar24 & 0xffffffffffff;
                      InstructionSynchronizationBarrier();
                      daif = uVar22;
                    }
                    goto LAB_00100d28;
                  }
                  goto LAB_00100c84;
                }
                fput(*puVar18);
                iVar26 = -0xc;
              }
              piVar2 = (int *)(lVar17 + 0x38);
              Hint_Prefetch(piVar2,2,0,1);
              do {
                iVar4 = *piVar2;
                cVar6 = '\x01';
                bVar10 = (bool)ExclusiveMonitorPass(piVar2,0x10);
                if (bVar10) {
                  *piVar2 = iVar4 + -1;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              if (iVar4 == 1) {
                DataMemoryBarrier(2,1);
                dma_fence_release();
              }
              else if (iVar4 < 1) {
                refcount_warn_saturate(piVar2,3);
              }
            }
          }
        }
        put_unused_fd(iVar11);
        iVar11 = iVar26;
        goto LAB_001013cc;
      }
    }
  }
LAB_00100c84:
  iVar11 = -0xe;
LAB_001013cc:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar11;
}



//------------------------------------------------------------
// spec_sync_open @ 0010144c size=412
// signature: undefined spec_sync_open(void)
// callers: []
//------------------------------------------------------------

undefined8 spec_sync_open(long param_1,long param_2)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  char local_38 [16];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  if (((param_1 == 0) || (param_2 == 0)) || (*(long *)(param_1 + 0x290) == 0)) {
    _printk(&DAT_00101da1,"spec_sync_open");
    uVar5 = 0xffffffea;
    goto LAB_00101534;
  }
  mutex_lock(&DAT_00102130);
  uVar5 = sp_el0;
  __get_task_comm(local_38,0x10,uVar5);
  if (DAT_00102168 < 2) {
    if (DAT_00102168 == 0) {
      DAT_0010217c = 0;
      DAT_00102184 = 0;
      DAT_0010216c = 0;
      DAT_00102174 = 0;
      uVar4 = strnlen(local_38,0x10);
      if ((uVar4 < 0x10) || (uVar4 == 0x20)) {
        if (uVar4 != 0x20) {
          uVar4 = uVar4 + 1;
        }
        if (uVar4 < 0x21) {
          strscpy(&DAT_0010216c,local_38);
          goto LAB_001015d8;
        }
      }
      else {
        fortify_panic("strnlen");
      }
      fortify_panic("strscpy");
    }
LAB_001015d8:
    Hint_Prefetch(0x102168,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(0x102168,0x10);
      if (bVar2) {
        cVar1 = ExclusiveMonitorsStatus();
        DAT_00102168 = DAT_00102168 + 1;
      }
    } while (cVar1 != '\0');
    uVar5 = 0;
    *(undefined8 **)(param_2 + 0xd8) = &sync_dev;
  }
  else {
    _printk(&DAT_00101f6b,"spec_fence_init_locked",2);
    _printk(&DAT_00102040,"spec_sync_open",&DAT_0010216c,local_38);
    uVar5 = 0xffffffef;
  }
  mutex_unlock(&DAT_00102130);
LAB_00101534:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// spec_sync_release @ 001015fc size=156
// signature: undefined spec_sync_release(void)
// callers: []
//------------------------------------------------------------

undefined8 spec_sync_release(undefined8 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = *(long *)(param_2 + 0xd8);
  mutex_lock(&DAT_00102130);
  if (*(int *)(lVar4 + 0x58) == 0) {
    _printk(&DAT_00101ea6,"spec_sync_release");
    uVar5 = 0xffffffed;
  }
  else {
    piVar1 = (int *)(lVar4 + 0x58);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    if (*(int *)(lVar4 + 0x58) == 0) {
      clear_fence_array_tracker(1);
    }
    uVar5 = 0;
  }
  mutex_unlock(&DAT_00102130);
  return uVar5;
}



//------------------------------------------------------------
// clear_fence_array_tracker @ 001016ac size=436
// signature: undefined clear_fence_array_tracker(void)
// callers: [spec_sync_ioctl, spec_sync_release]
//------------------------------------------------------------

void clear_fence_array_tracker(ulong param_1)

{
  int *piVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  ulong uVar7;
  code *pcVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  
  mutex_lock(&DAT_00102190);
  plVar9 = DAT_001021c0;
  if ((long **)DAT_001021c0 != &DAT_001021c0) {
    do {
      plVar11 = (long *)*plVar9;
      lVar10 = plVar9[-1];
      if ((*(ulong *)(lVar10 + 0x30) & 1) == 0) {
        pcVar8 = *(code **)(*(long *)(lVar10 + 8) + 0x20);
        bVar5 = false;
        if (pcVar8 == (code *)0x0) goto LAB_00101774;
        if (*(int *)(pcVar8 + -4) != -0xc4a187e) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x101760);
          (*pcVar8)();
        }
        uVar7 = (*pcVar8)(lVar10);
        if ((uVar7 & 1) != 0) {
          dma_fence_signal(lVar10);
          goto LAB_00101770;
        }
        bVar5 = false;
        bVar6 = false;
        if ((param_1 & 1) == 0) goto LAB_001017b8;
LAB_00101778:
        if (*(long *)(lVar10 + 0x50) == 0) {
          *(undefined4 *)(lVar10 + 0x44) = 0;
        }
        if (!bVar5) {
          piVar1 = (int *)(lVar10 + 0x48);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar3 = *piVar1;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar3 + -1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          DataMemoryBarrier(2,3);
          if (iVar3 + -1 == 0) {
            dma_fence_signal(lVar10);
          }
        }
LAB_001017bc:
        if (lVar10 != 0) {
          piVar1 = (int *)(lVar10 + 0x38);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar3 = *piVar1;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar3 + -1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          if (iVar3 == 1) {
            DataMemoryBarrier(2,1);
            dma_fence_release();
          }
          else if (iVar3 < 1) {
            refcount_warn_saturate(piVar1,3);
          }
        }
        uVar7 = __list_del_entry_valid(plVar9);
        if ((uVar7 & 1) != 0) {
          lVar10 = *plVar9;
          plVar2 = (long *)plVar9[1];
          *(long **)(lVar10 + 8) = plVar2;
          *plVar2 = lVar10;
        }
        *plVar9 = -0x2152ffffffffff00;
        plVar9[1] = -0x2152fffffffffede;
        kfree(plVar9 + -1);
      }
      else {
LAB_00101770:
        bVar5 = true;
LAB_00101774:
        bVar6 = bVar5;
        if ((param_1 & 1) != 0) goto LAB_00101778;
LAB_001017b8:
        if (bVar6) goto LAB_001017bc;
      }
      plVar9 = plVar11;
    } while ((long **)plVar11 != &DAT_001021c0);
  }
  mutex_unlock(&DAT_00102190);
  return;
}



//------------------------------------------------------------
// spec_fence_get_name_dummy @ 00101880 size=12
// signature: undefined spec_fence_get_name_dummy(void)
// callers: []
//------------------------------------------------------------

char * spec_fence_get_name_dummy(void)

{
  return "dummy_fence";
}



//------------------------------------------------------------
// init_module @ 001019ac size=632
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_module(void)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  
  sync_dev = __class_create(&__this_module,&DAT_00101e46,&spec_sync_register_device___key);
  if (sync_dev == 0) {
    _printk(&DAT_00101de2,"spec_sync_register_device","spec_sync_register_device");
  }
  else {
    iVar2 = alloc_chrdev_region(&DAT_00102118,0,1,"spec_sync");
    if (iVar2 == 0) {
      DAT_00102120 = device_create(sync_dev,0,DAT_00102118,&sync_dev,"spec_sync");
      if (DAT_00102120 < 0xfffffffffffff001) {
        DAT_00102128 = cdev_alloc();
        if (DAT_00102128 == 0) {
          _printk(&DAT_001020a4,"spec_sync_register_device","spec_sync_register_device");
        }
        else {
          cdev_init(DAT_00102128,&spec_sync_fops);
          lVar3 = DAT_00102128;
          uVar1 = DAT_00102118;
          *(undefined1 **)(DAT_00102128 + 0x60) = &__this_module;
          iVar2 = cdev_add(lVar3,uVar1,1);
          if (iVar2 == 0) {
            DAT_0010218c = 1;
            __mutex_init(&DAT_00102130,"&sync_dev.lock",&spec_sync_register_device___key_24);
            __mutex_init(&DAT_00102190,"&sync_dev.l_lock",&spec_sync_register_device___key_26);
            DAT_001021c0 = &DAT_001021c0;
            DAT_001021c8 = &DAT_001021c0;
            __init_waitqueue_head
                      (&DAT_001021d0,"&sync_dev.wait_queue",&spec_sync_register_device___key_28);
            lVar3 = kmalloc_trace(_put_unused_fd,0xdc0,0x48);
            if (lVar3 != 0) {
              *(undefined4 *)(lVar3 + 0x40) = 0;
              dma_fence_init(lVar3,dummy_spec_fence_ops,(undefined4 *)(lVar3 + 0x40),
                             0xfafadadafafadada,0xefa9ce00efa9ce00);
              DAT_00102160 = lVar3;
              return 0;
            }
          }
          else {
            _printk(&DAT_00101fab,"spec_sync_register_device","spec_sync_register_device");
          }
          cdev_del(DAT_00102128);
        }
        device_destroy(sync_dev,DAT_00102118);
      }
      else {
        _printk(&DAT_00101d65,"spec_sync_register_device","spec_sync_register_device");
      }
      unregister_chrdev_region(DAT_00102118,1);
    }
    else {
      _printk(&DAT_00101fc5,"spec_sync_register_device","spec_sync_register_device");
    }
    class_destroy(sync_dev);
  }
  _printk(&DAT_00101e65,"spec_sync_init","spec_sync_init");
  return 0xffffffed;
}



//------------------------------------------------------------
// cleanup_module @ 00101c28 size=164
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  cdev_del(DAT_00102128);
  device_destroy(sync_dev,DAT_00102118);
  unregister_chrdev_region(DAT_00102118,1);
  class_destroy(sync_dev);
  if (DAT_00102160 != 0) {
    piVar1 = (int *)(DAT_00102160 + 0x38);
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
      dma_fence_release();
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return;
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00104000 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [spec_sync_wait_bind_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00104008 size=1
// signature: undefined init_wait_entry(void)
// callers: [spec_sync_wait_bind_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00104010 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [spec_sync_wait_bind_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00104018 size=1
// signature: undefined schedule_timeout(void)
// callers: [spec_sync_wait_bind_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00104020 size=1
// signature: undefined finish_wait(void)
// callers: [spec_sync_wait_bind_array]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104028 size=1
// signature: undefined _printk(void)
// callers: [init_module, spec_sync_wait_bind_array, spec_sync_ioctl, spec_sync_open, spec_sync_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [spec_sync_wait_bind_array, spec_sync_ioctl, spec_sync_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00104048 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_unused_fd_flags @ 00104050 size=1
// signature: undefined get_unused_fd_flags(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_unused_fd_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00104058 size=1
// signature: undefined __kmalloc(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sync_file_get_fence @ 00104060 size=1
// signature: undefined sync_file_get_fence(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sync_file_get_fence(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104068 size=1
// signature: undefined mutex_lock(void)
// callers: [clear_fence_array_tracker, spec_sync_ioctl, spec_sync_open, spec_sync_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104070 size=1
// signature: undefined mutex_unlock(void)
// callers: [clear_fence_array_tracker, spec_sync_ioctl, spec_sync_open, spec_sync_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00104078 size=1
// signature: undefined __check_object_size(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00104080 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_release @ 00104088 size=1
// signature: undefined dma_fence_release(void)
// callers: [cleanup_module, clear_fence_array_tracker, spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00104090 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [cleanup_module, clear_fence_array_tracker, spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00104098 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001040a0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_enable_sw_signaling @ 001040a8 size=1
// signature: undefined dma_fence_enable_sw_signaling(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_enable_sw_signaling(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001040b0 size=1
// signature: undefined __wake_up(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_signal @ 001040b8 size=1
// signature: undefined dma_fence_signal(void)
// callers: [clear_fence_array_tracker, spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_signal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040c0 size=1
// signature: undefined kfree(void)
// callers: [clear_fence_array_tracker, spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_get_status @ 001040c8 size=1
// signature: undefined dma_fence_get_status(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_get_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_context_alloc @ 001040d0 size=1
// signature: undefined dma_fence_context_alloc(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_context_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_array_create @ 001040d8 size=1
// signature: undefined dma_fence_array_create(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_array_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sync_file_create @ 001040e0 size=1
// signature: undefined sync_file_create(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sync_file_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001040f0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [init_module, spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fd_install @ 001040f8 size=1
// signature: undefined fd_install(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fd_install(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104100 size=1
// signature: undefined __list_add_valid(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fput @ 00104108 size=1
// signature: undefined fput(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104110 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_unused_fd @ 00104120 size=1
// signature: undefined put_unused_fd(void)
// callers: [spec_sync_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_unused_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_task_comm @ 00104128 size=1
// signature: undefined __get_task_comm(void)
// callers: [spec_sync_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_task_comm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104130 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [spec_sync_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104138 size=1
// signature: undefined strscpy(void)
// callers: [spec_sync_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104140 size=1
// signature: undefined fortify_panic(void)
// callers: [spec_sync_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00104148 size=1
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
// alloc_chrdev_region @ 00104150 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00104158 size=1
// signature: undefined device_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_alloc @ 00104160 size=1
// signature: undefined cdev_alloc(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00104168 size=1
// signature: undefined cdev_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00104170 size=1
// signature: undefined cdev_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104178 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00104180 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_fence_init @ 00104188 size=1
// signature: undefined dma_fence_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_fence_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00104190 size=1
// signature: undefined cdev_del(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00104198 size=1
// signature: undefined device_destroy(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001041a0 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001041a8 size=1
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
// __list_del_entry_valid @ 001041b0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [clear_fence_array_tracker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



