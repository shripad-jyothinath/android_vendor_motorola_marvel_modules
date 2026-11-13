// Decompiled by Ghidra 12.2
// Program: qcedev-mod_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// qcedev_sha_req_cb @ 00101af4 size=132
// signature: undefined qcedev_sha_req_cb(void)
// callers: []
//------------------------------------------------------------

void qcedev_sha_req_cb(long param_1,long *param_2,undefined4 *param_3)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  char cVar5;
  bool bVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  
  if (((param_1 != 0) && (plVar8 = *(long **)(param_1 + 0x80), plVar8 != (long *)0x0)) &&
     (lVar7 = *plVar8, lVar7 != 0)) {
    if (param_2 != (long *)0x0) {
      lVar3 = param_2[3];
      lVar2 = *param_2;
      lVar4 = param_2[1];
      plVar8[5] = param_2[2];
      plVar8[6] = lVar3;
      plVar8[3] = lVar2;
      plVar8[4] = lVar4;
    }
    if (param_3 != (undefined4 *)0x0) {
      *(undefined4 *)(plVar8 + 1) = *param_3;
      *(undefined4 *)((long)plVar8 + 0xc) = param_3[1];
    }
    puVar1 = (ulong *)(lVar7 + 0x120);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar9 = *puVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar6) {
        *puVar1 = uVar9 | 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar9 & 1) == 0) {
      __tasklet_schedule(lVar7 + 0x118);
    }
  }
  return;
}



//------------------------------------------------------------
// qcedev_cipher_req_cb @ 00101b8c size=224
// signature: undefined qcedev_cipher_req_cb(void)
// callers: []
//------------------------------------------------------------

void qcedev_cipher_req_cb(long param_1,undefined8 param_2,void *param_3)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  
  if (((param_1 != 0) && (*(long **)(param_1 + 0x80) != (long *)0x0)) &&
     (lVar8 = **(long **)(param_1 + 0x80), lVar8 != 0)) {
    if ((param_3 != (void *)0x0) && (lVar7 = *(long *)(lVar8 + 0x108), lVar7 != 0)) {
      uVar2 = *(uint *)(lVar7 + 0x2c0);
      if ((0x20 < uVar2) && ((qcedev_cipher_req_cb___already_done & 1) == 0)) {
        qcedev_cipher_req_cb___already_done = 1;
        __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                      (ulong)uVar2,
                      "field \"&qcedev_areq->cipher_op_req.iv[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:410"
                      ,0x20);
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101c58);
        (*pcVar5)();
      }
      memcpy((void *)(lVar7 + 0x2a0),param_3,(ulong)uVar2);
    }
    puVar1 = (ulong *)(lVar8 + 0x120);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar6 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar6 | 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar6 & 1) == 0) {
      __tasklet_schedule(lVar8 + 0x118);
    }
  }
  return;
}



//------------------------------------------------------------
// qcedev_offload_cipher_req_cb @ 00101c84 size=224
// signature: undefined qcedev_offload_cipher_req_cb(void)
// callers: []
//------------------------------------------------------------

void qcedev_offload_cipher_req_cb(long param_1,undefined8 param_2,void *param_3)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  
  if (((param_1 != 0) && (*(long **)(param_1 + 0x80) != (long *)0x0)) &&
     (lVar8 = **(long **)(param_1 + 0x80), lVar8 != 0)) {
    if ((param_3 != (void *)0x0) && (lVar7 = *(long *)(lVar8 + 0x108), lVar7 != 0)) {
      uVar2 = *(uint *)(lVar7 + 0x268);
      if ((0x20 < uVar2) && ((qcedev_offload_cipher_req_cb___already_done & 1) == 0)) {
        qcedev_offload_cipher_req_cb___already_done = 1;
        __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
                      (ulong)uVar2,
                      "field \"&qcedev_areq->offload_cipher_op_req.iv[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:538"
                      ,0x20);
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101d50);
        (*pcVar5)();
      }
      memcpy((void *)(lVar7 + 0x248),param_3,(ulong)uVar2);
    }
    puVar1 = (ulong *)(lVar8 + 0x120);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar6 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar6 | 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar6 & 1) == 0) {
      __tasklet_schedule(lVar8 + 0x118);
    }
  }
  return;
}



//------------------------------------------------------------
// qcedev_ioctl @ 00101d7c size=5080
// signature: undefined qcedev_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcedev_ioctl(long param_1,uint param_2,ulong param_3)

{
  undefined4 uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  size_t __n;
  long lVar6;
  undefined *puVar7;
  void *__s;
  uint uVar8;
  ulong uVar9;
  undefined8 *puVar10;
  ulong *puVar11;
  ulong uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  undefined8 local_1c0;
  undefined8 local_1b8;
  undefined8 uStack_1b0;
  undefined8 local_1a8;
  undefined8 uStack_1a0;
  undefined8 local_198;
  undefined8 uStack_190;
  undefined8 local_188;
  undefined8 uStack_180;
  uint local_178;
  undefined4 local_174 [16];
  undefined4 local_134 [17];
  undefined8 local_f0 [16];
  long local_70;
  
  lVar5 = sp_el0;
  local_70 = *(long *)(lVar5 + 0x638);
  lVar5 = kmalloc_trace(_kfree,0xdc0,0x400);
  if (lVar5 == 0) {
    lVar5 = -0xc;
    goto LAB_00102e78;
  }
  puVar11 = *(ulong **)(param_1 + 0xd8);
  uVar12 = *puVar11;
  *(ulong **)(lVar5 + 0x3c0) = puVar11;
  if ((uVar12 == 0) || (*(int *)(uVar12 + 0xf0) != 0x56434544)) {
    _printk(&DAT_00109379,"qcedev_ioctl",uVar12);
    iVar4 = -2;
    goto switchD_00101e60_caseD_c1408707;
  }
  if ((param_2 & 0xff00) != 0x8700) {
LAB_001025b8:
    iVar4 = -0x19;
    goto switchD_00101e60_caseD_c1408707;
  }
  *(undefined4 *)(lVar5 + 0x10) = 0;
  __init_swait_queue_head(lVar5 + 0x18,"&x->wait",&init_completion___key);
  iVar4 = -0x19;
  uVar8 = (uint)_cpu_hwcaps;
  if (-0x3eb778f7 < (int)param_2) {
    if (param_2 + 0x3d5f78ff < 2) {
      puVar10 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
         (uVar9 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
        uVar9 = param_3 & (long)(param_3 << 8) >> 8;
      }
      uVar13 = 0x7ffffffd60;
      if (0x7ffffffd60 < uVar9) {
        __n = 0x2a0;
LAB_00102f58:
        __s = (void *)((lVar5 - __n) + 0x2d8);
        goto LAB_00102f70;
      }
LAB_00102ff4:
      lVar6 = lVar5 + 0x38;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10[1];
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      __n = __arch_copy_from_user(lVar6,param_3 & 0xff7fffffffffffff,0x2a0);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      if (__n != 0) goto LAB_00102f58;
      *(undefined4 *)(lVar5 + 0x30) = 0;
      iVar4 = qcedev_check_cipher_params(lVar6,uVar12);
      if (iVar4 != 0) {
LAB_00102350:
        iVar4 = -0x16;
        goto switchD_00101e60_caseD_c1408707;
      }
      iVar4 = qcedev_vbuf_ablk_cipher(lVar5,puVar11);
      if (iVar4 != 0) goto switchD_00101e60_caseD_c1408707;
      if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
         (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
        uVar12 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar13 < uVar12) goto LAB_00102da8;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        uVar9 = ttbr1_el1;
        ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10[1];
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,lVar6,0x2a0);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        uVar9 = ttbr1_el1;
        ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      goto LAB_00102e60;
    }
    if (param_2 == 0xc148870a) {
      local_1c0 = 0;
      memset(&local_1b8,0,0x148);
      puVar10 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
         (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
        uVar12 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar12 < 0x7ffffffeb9) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar10[1];
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        lVar6 = __arch_copy_from_user(&local_1b8,param_3 & 0xff7fffffffffffff,0x148);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        if (lVar6 == 0) {
          if (0x10 < local_178) goto LAB_00102db0;
          if (local_178 != 0) {
            uVar12 = 0;
            puVar14 = &local_1b8;
            do {
              if (uVar12 == 0x10) goto LAB_00102fb0;
              iVar4 = qcedev_check_and_map_buffer
                                (puVar11,*(undefined4 *)puVar14,
                                 *(undefined4 *)((long)puVar14 + 0x84),
                                 *(undefined4 *)((long)puVar14 + 0x44),&local_1c0);
              if (iVar4 != 0) {
                uVar1 = *(undefined4 *)puVar14;
                puVar7 = &DAT_0010915b;
                goto LAB_00102ef4;
              }
              if (uVar12 == 0x10) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(1,0x102fe8);
                (*pcVar3)();
              }
              local_f0[uVar12] = local_1c0;
              _printk(&DAT_0010924e,"qcedev_ioctl",local_1c0,*(undefined4 *)puVar14);
              uVar12 = uVar12 + 1;
              puVar14 = (undefined8 *)((long)puVar14 + 4);
            } while (uVar12 < local_178);
          }
          if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
             (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
            uVar12 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar12 < 0x7ffffffeb9) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar12 = daif;
              if ((uVar12 & 0x80) == 0) {
                uVar9 = daif;
                daif = uVar9 | 0xc0;
              }
              uVar9 = ttbr1_el1;
              ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar10[1];
              InstructionSynchronizationBarrier();
              daif = uVar12;
            }
            lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_1b8,0x148);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar12 = daif;
              if ((uVar12 & 0x80) == 0) {
                uVar9 = daif;
                daif = uVar9 | 0xc0;
              }
              uVar9 = ttbr1_el1;
              ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar9 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar12;
            }
            goto LAB_00102e60;
          }
        }
      }
      goto LAB_00102da8;
    }
    if (param_2 != 0xc258870c) goto switchD_00101e60_caseD_c1408707;
    puVar10 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar12 = param_3 & (long)(param_3 << 8) >> 8;
    }
    lVar6 = lVar5 + 0x38;
    if (uVar12 < 0x7ffffffda9) {
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        uVar9 = ttbr1_el1;
        ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10[1];
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      __n = __arch_copy_from_user(lVar6,param_3 & 0xff7fffffffffffff,600);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        uVar9 = ttbr1_el1;
        ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      if (__n == 0) {
        *(undefined4 *)(lVar5 + 0x30) = 2;
        iVar4 = qcedev_check_offload_cipher_params(lVar6);
        if (iVar4 != 0) goto LAB_00102350;
        *(undefined4 *)(lVar5 + 0x288) = 0;
        iVar4 = qcedev_smmu_ablk_offload_cipher(lVar5,puVar11);
        if (iVar4 == 0) {
          if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
             (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
            uVar12 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar12 < 0x7ffffffda9) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar12 = daif;
              if ((uVar12 & 0x80) == 0) {
                uVar9 = daif;
                daif = uVar9 | 0xc0;
              }
              uVar9 = ttbr1_el1;
              ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar10[1];
              InstructionSynchronizationBarrier();
              daif = uVar12;
            }
            lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,lVar6,600);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar12 = daif;
              if ((uVar12 & 0x80) == 0) {
                uVar9 = daif;
                daif = uVar9 | 0xc0;
              }
              uVar9 = ttbr1_el1;
              ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar9 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar12;
            }
            goto LAB_00102e60;
          }
          goto LAB_00102da8;
        }
        goto switchD_00101e60_caseD_c1408707;
      }
    }
    else {
      __n = 600;
    }
    __s = (void *)((lVar6 - __n) + 600);
    goto LAB_00102f70;
  }
  switch(param_2) {
  case 0xc1408703:
    puVar10 = (undefined8 *)sp_el0;
    local_1a8 = 0;
    uStack_1a0 = 0;
    local_1b8 = 0;
    uStack_1b0 = 0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    lVar6 = lVar5 + 0x38;
    if (0x7ffffffec0 < uVar9) goto LAB_00102f44;
    if ((uVar8 >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10[1];
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    __n = __arch_copy_from_user(lVar6,param_3 & 0xff7fffffffffffff,0x140);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    if (__n == 0) {
      mutex_lock(&hash_access_lock);
      iVar4 = qcedev_check_sha_params(lVar6,uVar12);
      if (iVar4 != 0) goto LAB_001028f4;
      *(undefined4 *)(lVar5 + 0x30) = 1;
      iVar4 = qcedev_hash_init(lVar5,puVar11,&local_1b8);
      mutex_unlock(&hash_access_lock);
      if (iVar4 == 0) {
        if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
           (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
          uVar12 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar12 < 0x7ffffffec1) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar9 = daif;
              daif = uVar9 | 0xc0;
            }
            uVar9 = ttbr1_el1;
            ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar10[1];
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,lVar6,0x140);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar9 = daif;
              daif = uVar9 | 0xc0;
            }
            uVar9 = ttbr1_el1;
            ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar9 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          if (lVar6 == 0) {
            iVar4 = 0;
            *(undefined1 *)((long)puVar11 + 0xc2) = 1;
            break;
          }
        }
        goto LAB_00102da8;
      }
      break;
    }
    goto LAB_00102f48;
  case 0xc1408704:
    goto switchD_00101e60_caseD_c1408704;
  case 0xc1408705:
    if (*(char *)((long)puVar11 + 0xc2) != '\0') {
      puVar10 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
         (uVar9 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
        uVar9 = param_3 & (long)(param_3 << 8) >> 8;
      }
      lVar6 = lVar5 + 0x38;
      if (uVar9 < 0x7ffffffec1) {
        if ((uVar8 >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar10[1];
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        __n = __arch_copy_from_user(lVar6,param_3 & 0xff7fffffffffffff,0x140);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar13 = daif;
            daif = uVar13 | 0xc0;
          }
          uVar13 = ttbr1_el1;
          ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar13 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        if (__n != 0) goto LAB_00102f48;
        mutex_lock(&hash_access_lock);
        iVar4 = qcedev_check_sha_params(lVar6,uVar12);
        if (iVar4 != 0) goto LAB_001028f4;
        *(undefined4 *)(lVar5 + 0x30) = 1;
        iVar4 = qcedev_hash_final(lVar5,puVar11);
        if (iVar4 != 0) goto LAB_00102d4c;
        if (0x20 < (uint)puVar11[7]) goto LAB_00102f34;
        *(uint *)(lVar5 + 0x160) = (uint)puVar11[7];
        uVar8 = (uint)puVar11[7];
        uVar12 = (ulong)uVar8;
        if (0x2c0 < uVar8) goto LAB_00102fe8;
        if ((0x20 < uVar8) && ((qcedev_ioctl___already_done_9 & 1) == 0)) {
          qcedev_ioctl___already_done_9 = 1;
          __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                        ,uVar12,
                        "field \"&qcedev_areq->sha_op_req.digest[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:2376"
                        ,0x20);
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102fac);
          (*pcVar3)();
        }
        memcpy((void *)(lVar5 + 0x140),puVar11 + 3,uVar12);
        mutex_unlock(&hash_access_lock);
        if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
           (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
          uVar12 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar12 < 0x7ffffffec1) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar9 = daif;
              daif = uVar9 | 0xc0;
            }
            uVar9 = ttbr1_el1;
            ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar10[1];
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,lVar6,0x140);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar9 = daif;
              daif = uVar9 | 0xc0;
            }
            uVar9 = ttbr1_el1;
            ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar9 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          if (lVar6 == 0) {
            iVar4 = 0;
            *(undefined1 *)((long)puVar11 + 0xc2) = 0;
            break;
          }
        }
        goto LAB_00102da8;
      }
      goto LAB_00102f44;
    }
    _printk(&DAT_00109022,"qcedev_ioctl");
    iVar4 = -0x16;
    break;
  case 0xc1408706:
    puVar10 = (undefined8 *)sp_el0;
    local_1a8 = 0;
    uStack_1a0 = 0;
    local_1b8 = 0;
    uStack_1b0 = 0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    lVar6 = lVar5 + 0x38;
    if (0x7ffffffec0 < uVar9) goto LAB_00102f44;
    if ((uVar8 >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10[1];
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    __n = __arch_copy_from_user(lVar6,param_3 & 0xff7fffffffffffff,0x140);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar9 = daif;
      if ((uVar9 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar9;
    }
    if (__n != 0) goto LAB_00102f48;
    mutex_lock(&hash_access_lock);
    iVar4 = qcedev_check_sha_params(lVar6,uVar12);
    if (iVar4 == 0) {
      *(undefined4 *)(lVar5 + 0x30) = 1;
      qcedev_hash_init(lVar5,puVar11,&local_1b8);
      iVar4 = qcedev_sha_update(lVar5,puVar11,&local_1b8);
      if ((iVar4 == 0) && (iVar4 = qcedev_hash_final(lVar5,puVar11), iVar4 == 0)) {
        if ((uint)puVar11[7] < 0x21) {
          *(uint *)(lVar5 + 0x160) = (uint)puVar11[7];
          uVar8 = (uint)puVar11[7];
          uVar12 = (ulong)uVar8;
          if (0x2c0 < uVar8) {
LAB_00102fe8:
            uVar13 = 0x7ffffffec0;
            fortify_panic("memcpy");
            goto LAB_00102ff4;
          }
          if ((0x20 < uVar8) && ((qcedev_ioctl___already_done_11 & 1) == 0)) {
            qcedev_ioctl___already_done_11 = 1;
            __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                          ,uVar12,
                          "field \"&qcedev_areq->sha_op_req.digest[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:2424"
                          ,0x20);
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102fe0);
            (*pcVar3)();
          }
          memcpy((void *)(lVar5 + 0x140),puVar11 + 3,uVar12);
          mutex_unlock(&hash_access_lock);
          if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
             (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
            uVar12 = param_3 & (long)(param_3 << 8) >> 8;
          }
          if (uVar12 < 0x7ffffffec1) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar12 = daif;
              if ((uVar12 & 0x80) == 0) {
                uVar9 = daif;
                daif = uVar9 | 0xc0;
              }
              uVar9 = ttbr1_el1;
              ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar10[1];
              InstructionSynchronizationBarrier();
              daif = uVar12;
            }
            lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,lVar6,0x140);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar12 = daif;
              if ((uVar12 & 0x80) == 0) {
                uVar9 = daif;
                daif = uVar9 | 0xc0;
              }
              uVar9 = ttbr1_el1;
              ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar9 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar12;
            }
            goto LAB_00102e60;
          }
          goto LAB_00102da8;
        }
LAB_00102f34:
        _printk(&DAT_00109514);
        goto LAB_001028f4;
      }
      goto LAB_00102d4c;
    }
    goto LAB_001028f4;
  case 0xc1408707:
  case 0xc1408708:
    break;
  case 0xc1408709:
    if (*(char *)(uVar12 + 0x1c) == '\0') goto LAB_001025b8;
switchD_00101e60_caseD_c1408704:
    puVar10 = (undefined8 *)sp_el0;
    local_1a8 = 0;
    uStack_1a0 = 0;
    local_1b8 = 0;
    uStack_1b0 = 0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    lVar6 = lVar5 + 0x38;
    if (uVar9 < 0x7ffffffec1) {
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10[1];
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      __n = __arch_copy_from_user(lVar6,param_3 & 0xff7fffffffffffff,0x140);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      if (__n != 0) goto LAB_00102f48;
      mutex_lock(&hash_access_lock);
      iVar4 = qcedev_check_sha_params(lVar6,uVar12);
      if (iVar4 != 0) {
LAB_001028f4:
        mutex_unlock(&hash_access_lock);
        iVar4 = -0x16;
        break;
      }
      *(undefined4 *)(lVar5 + 0x30) = 1;
      if (*(int *)(lVar5 + 0x174) == 4) {
        iVar4 = qcedev_hash_cmac(lVar5,puVar11,&local_1b8);
      }
      else {
        if (*(char *)((long)puVar11 + 0xc2) == '\0') {
          _printk(&DAT_00109022,"qcedev_ioctl");
          goto LAB_001028f4;
        }
        iVar4 = qcedev_sha_update(lVar5,puVar11,&local_1b8);
      }
      if (iVar4 != 0) {
LAB_00102d4c:
        mutex_unlock(&hash_access_lock);
        break;
      }
      uVar8 = (uint)puVar11[7];
      if (0x20 < uVar8) {
        _printk(&DAT_00109514,uVar8);
        goto LAB_001028f4;
      }
      memcpy((void *)(lVar5 + 0x140),puVar11 + 3,(ulong)uVar8);
      mutex_unlock(&hash_access_lock);
      if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
         (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
        uVar12 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar12 < 0x7ffffffec1) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr1_el1 = puVar10[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar10[1];
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        lVar6 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,lVar6,0x140);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
LAB_00102e60:
        iVar4 = 0;
        if (lVar6 != 0) {
          iVar4 = -0xe;
        }
        break;
      }
    }
    else {
LAB_00102f44:
      __n = 0x140;
LAB_00102f48:
      __s = (void *)((lVar5 - __n) + 0x178);
LAB_00102f70:
      memset(__s,0,__n);
    }
LAB_00102da8:
    iVar4 = -0xe;
    break;
  default:
    if (param_2 != 0xc044870b) break;
    puVar10 = (undefined8 *)sp_el0;
    local_178 = 0;
    local_188 = 0;
    uStack_180 = 0;
    local_198 = 0;
    uStack_190 = 0;
    local_1a8 = 0;
    uStack_1a0 = 0;
    local_1b8 = 0;
    uStack_1b0 = 0;
    if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
       (uVar12 = param_3, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
      uVar12 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar12 < 0x7fffffffbd) {
      if ((uVar8 >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        puVar10 = (undefined8 *)puVar10[1];
        uVar9 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar10;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      lVar6 = __arch_copy_from_user(puVar10,&local_1b8,param_3 & 0xff7fffffffffffff,0x44);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        uVar9 = ttbr1_el1;
        ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      if (lVar6 == 0) {
        if (local_178 < 0x11) {
          if (local_178 != 0) {
            uVar12 = 0;
LAB_00102460:
            if (uVar12 == 0x10) {
LAB_00102fb0:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x102fb4);
              (*pcVar3)();
            }
            iVar4 = qcedev_check_and_unmap_buffer(puVar11,local_174[uVar12 - 0x11]);
            if (iVar4 == 0) goto code_r0x00102478;
            puVar7 = &DAT_00108eb2;
            uVar1 = local_174[uVar12 - 0x11];
LAB_00102ef4:
            _printk(puVar7,"qcedev_ioctl",uVar1,iVar4);
            break;
          }
LAB_00102488:
          iVar4 = 0;
        }
        else {
LAB_00102db0:
          _printk(&DAT_00109a07,"qcedev_ioctl");
          iVar4 = -0x16;
        }
        break;
      }
    }
    goto LAB_00102da8;
  }
switchD_00101e60_caseD_c1408707:
  kfree(lVar5);
  lVar5 = (long)iVar4;
LAB_00102e78:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
code_r0x00102478:
  uVar12 = uVar12 + 1;
  if (local_178 <= uVar12) goto LAB_00102488;
  goto LAB_00102460;
}



//------------------------------------------------------------
// qcedev_check_cipher_params @ 001032c4 size=928
// signature: undefined qcedev_check_cipher_params(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

undefined8 qcedev_check_cipher_params(uint *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  undefined *puVar4;
  char *pcVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  uint *puVar11;
  uint uVar12;
  
  if ((char)*param_1 == '\0') {
    uVar8 = param_1[0x86];
    uVar6 = (ulong)uVar8;
    if (((uVar8 == 0) || (uVar1 = param_1[0x87], uVar1 == 0)) || (0x10 < uVar8)) {
      puVar4 = &DAT_00109086;
    }
    else {
      uVar8 = param_1[0xa4];
      if ((2 < uVar8) || (uVar7 = param_1[0xa5], 6 < uVar7)) {
        puVar4 = &DAT_00108e04;
LAB_0010353c:
        pcVar5 = "qcedev_check_cipher_params";
LAB_00103544:
        _printk(puVar4,pcVar5,uVar8);
        return 0xffffffea;
      }
      if ((uVar7 == 3) && (*(char *)(param_2 + 0x1e) == '\0')) {
        puVar4 = &DAT_00108eda;
      }
      else {
        if (uVar8 == 2) {
          uVar8 = param_1[0x99];
          if (uVar8 == 0x18) {
            if (*(char *)(param_2 + 0x1d) == '\0') {
              puVar4 = &UNK_00109452;
LAB_0010361c:
              pcVar5 = "qcedev_check_cipher_key";
              goto LAB_00103638;
            }
          }
          else if (uVar8 == 0) {
            lVar9 = 0;
            do {
              if (*(char *)((long)param_1 + lVar9 + 0x221) != '\0') {
                puVar4 = &DAT_0010974f;
                goto LAB_0010361c;
              }
              lVar9 = lVar9 + 1;
            } while (lVar9 != 0x40);
            uVar8 = param_1[0xa6];
            if (((uVar8 & 0xfffffffe) != 2) && (*(int *)(param_2 + 8) == 0)) {
              puVar4 = &DAT_00108f96;
              goto LAB_00103654;
            }
          }
          else if (uVar7 == 3) {
            if ((uVar8 != 0x20) && (uVar8 != 0x40)) {
              puVar4 = &UNK_00108f00;
LAB_00103654:
              pcVar5 = "qcedev_check_cipher_key";
              goto LAB_00103544;
            }
          }
          else if ((uVar8 != 0x10) && (uVar8 != 0x20)) {
            puVar4 = &DAT_00109776;
            goto LAB_00103654;
          }
        }
        uVar8 = param_1[0xa3];
        if (uVar8 == 0) {
LAB_0010341c:
          if (uVar1 < uVar8) {
            puVar4 = &DAT_001098f4;
            uVar10 = (ulong)uVar1;
            goto LAB_0010360c;
          }
          uVar8 = param_1[0xa2];
          if (0x20 < uVar8) {
            puVar4 = &DAT_001099b9;
            goto LAB_0010353c;
          }
          if (0x40 < param_1[0x99]) {
            _printk(&DAT_00109aee,"qcedev_check_cipher_params",param_1[0x99]);
            return 0xffffffea;
          }
          if (uVar8 == 0) {
            if ((uVar7 == 1) || (uVar7 == 6)) goto LAB_0010346c;
            puVar4 = &DAT_00108e60;
          }
          else {
            if ((uVar7 != 6) && (uVar7 != 1)) {
LAB_0010346c:
              uVar10 = 0;
              uVar7 = 0;
              puVar11 = param_1 + 0x44;
              do {
                uVar8 = *puVar11;
                if ((*(long *)(puVar11 + -2) == 0) && (uVar8 != 0)) {
                  puVar4 = &DAT_001095e3;
                  uVar10 = uVar10 & 0xffffffff;
                  goto LAB_0010360c;
                }
                if (~uVar7 <= uVar8) {
                  puVar4 = &DAT_0010960f;
                  goto LAB_00103630;
                }
                uVar7 = uVar8 + uVar7;
                uVar10 = uVar10 + 1;
                puVar11 = puVar11 + 4;
              } while (uVar6 != uVar10);
              if (uVar7 != uVar1) {
                _printk(&DAT_001091ba,"qcedev_check_cipher_params");
                return 0xffffffea;
              }
              uVar10 = 0;
              uVar7 = 0;
              do {
                if (uVar10 == 0x10) {
LAB_00103660:
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103664);
                  (*pcVar3)();
                }
                uVar8 = param_1[4];
                if (*(long *)(param_1 + 2) == 0) {
                  if (uVar8 != 0) {
                    puVar4 = &DAT_00109c8b;
                    uVar10 = uVar10 & 0xffffffff;
                    goto LAB_0010360c;
                  }
                }
                else if (CARRY4(uVar7,uVar8)) {
                  puVar4 = &DAT_0010941d;
                  goto LAB_00103630;
                }
                uVar7 = uVar8 + uVar7;
                uVar10 = uVar10 + 1;
                param_1 = param_1 + 4;
              } while (uVar6 != uVar10);
              if (uVar7 == uVar1) {
                return 0;
              }
              puVar4 = &DAT_00109b97;
              uVar10 = (ulong)uVar7;
              uVar8 = uVar1;
LAB_0010360c:
              _printk(puVar4,"qcedev_check_cipher_params",uVar10,uVar8);
              return 0xffffffea;
            }
            puVar4 = &DAT_00109a32;
          }
        }
        else if (uVar7 == 2) {
          if (uVar8 < 0x10) {
            lVar9 = 0;
            uVar12 = uVar8;
            do {
              if (lVar9 == 0x100) goto LAB_00103660;
              uVar2 = *(uint *)((long)param_1 + lVar9 + 0x10);
              if (CARRY4(uVar2,uVar12)) {
                puVar4 = &DAT_00109393;
                goto LAB_00103630;
              }
              uVar12 = uVar2 + uVar12;
              lVar9 = lVar9 + 0x10;
            } while (uVar6 * 0x10 != lVar9);
            goto LAB_0010341c;
          }
          puVar4 = &DAT_00109ad3;
        }
        else {
          puVar4 = &DAT_001099d9;
        }
      }
    }
  }
  else {
    puVar4 = &DAT_00108cf9;
  }
LAB_00103630:
  pcVar5 = "qcedev_check_cipher_params";
LAB_00103638:
  _printk(puVar4,pcVar5);
  return 0xffffffea;
}



//------------------------------------------------------------
// qcedev_vbuf_ablk_cipher @ 00103664 size=1196
// signature: undefined qcedev_vbuf_ablk_cipher(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

int qcedev_vbuf_ablk_cipher(long param_1,undefined8 param_2)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  code *pcVar10;
  int iVar11;
  undefined4 *__s;
  undefined4 *__s_00;
  uint uVar12;
  undefined4 *puVar13;
  int *piVar14;
  ulong uVar15;
  uint uVar16;
  long lVar17;
  uint uVar18;
  ulong uVar19;
  uint uVar20;
  undefined4 local_314;
  undefined1 auStack_310 [8];
  long local_308;
  uint local_300 [130];
  uint local_f8;
  long local_70;
  
  lVar17 = sp_el0;
  local_70 = *(long *)(lVar17 + 0x638);
  uVar20 = 0xff00;
  local_314 = 0;
  if (*(int *)(param_1 + 0x2cc) == 2) {
    uVar20 = 0xff00 - *(int *)(param_1 + 0x2c4);
  }
  __s = (undefined4 *)kmalloc_large(0xff80,0xcc0);
  if (__s != (undefined4 *)0x0) {
    __s_00 = (undefined4 *)kmemdup((void *)(param_1 + 0x38),0x2a0,0xcc0);
    if (__s_00 != (undefined4 *)0x0) {
      if (uVar20 < *(uint *)(param_1 + 0x254)) {
        memcpy(auStack_310,(void *)(param_1 + 0x38),0x2a0);
        if (local_f8 != 0) {
          uVar18 = 0;
          plVar2 = (long *)(param_1 + 0x40);
          do {
            if (0xf < uVar18) goto LAB_00103b04;
            lVar17 = (long)(int)uVar18;
            plVar4 = plVar2 + lVar17 * 2;
            if (uVar20 < *(uint *)(plVar4 + 1)) {
              *(uint *)(param_1 + 0x48) = uVar20;
              if (uVar18 != 0) {
                *plVar2 = *plVar4;
              }
              *(uint *)(param_1 + 0x254) = uVar20;
              *(undefined4 *)(param_1 + 0x250) = 1;
              iVar11 = qcedev_vbuf_ablk_cipher_max_xfer(param_1,&local_314,param_2,__s);
              if (iVar11 < 0) goto LAB_00103ad0;
              uVar19 = lVar17 * 0x10 + 0x10;
              if ((0x2a0 < uVar19) || (uVar18 == 0x29)) goto LAB_00103b08;
              uVar12 = local_300[lVar17 * 4] - uVar20;
              *(uint *)(plVar4 + 1) = uVar12;
              if (0x2a0 < (lVar17 << 4 | 8U)) goto LAB_00103b08;
              lVar1 = *(long *)(auStack_310 + lVar17 * 0x10 + 8) + (ulong)uVar20;
              *plVar4 = lVar1;
              *(long *)(auStack_310 + lVar17 * 0x10 + 8) = lVar1;
              if ((0x2a0 < uVar19) || (uVar18 == 0x29)) goto LAB_00103b08;
              local_300[lVar17 * 4] = uVar12;
            }
            else {
              uVar12 = local_f8 - uVar18;
              if (local_f8 < uVar18 || uVar12 == 0) {
                uVar12 = 0;
                uVar19 = (ulong)uVar18;
                *(uint *)(param_1 + 0x254) = *(uint *)(param_1 + 0x2c4);
              }
              else {
                iVar11 = 0;
                piVar14 = (undefined4 *)(param_1 + 0x48) + (ulong)uVar18 * 4;
                uVar16 = *(uint *)(param_1 + 0x2c4);
                do {
                  if (uVar18 - 0x10 == iVar11) goto LAB_00103b04;
                  uVar3 = *piVar14 + uVar16;
                  if (uVar20 <= uVar3) {
                    uVar3 = uVar18 - iVar11;
                    uVar12 = 1 - iVar11;
                    *piVar14 = uVar20 - uVar16;
                    goto LAB_00103858;
                  }
                  iVar11 = iVar11 + -1;
                  piVar14 = piVar14 + 4;
                  uVar16 = uVar3;
                } while (uVar18 - local_f8 != iVar11);
                uVar20 = uVar3;
                uVar3 = local_f8;
LAB_00103858:
                uVar19 = (ulong)uVar3;
                *(uint *)(param_1 + 0x254) = uVar20;
                if ((0 < (int)uVar18) && (0 < (int)uVar12)) {
                  uVar15 = 0;
                  puVar13 = (undefined4 *)(param_1 + 0x48);
                  do {
                    uVar5 = uVar18 + uVar15;
                    if (0xf < ((uint)uVar5 | (uint)uVar15)) goto LAB_00103b04;
                    uVar15 = uVar15 + 1;
                    *puVar13 = (int)(plVar2 + (uVar5 & 0xffffffff) * 2)[1];
                    *(long *)(puVar13 + -2) = plVar2[(uVar5 & 0xffffffff) * 2];
                    puVar13 = puVar13 + 4;
                  } while (uVar12 != uVar15);
                }
              }
              *(uint *)(param_1 + 0x250) = uVar12;
              iVar11 = qcedev_vbuf_ablk_cipher_max_xfer(param_1,&local_314,param_2,__s);
              if (iVar11 < 0) {
LAB_00103ad0:
                memset(__s_00,0,0x2a0);
                memset(__s,0,0xff80);
                kfree(__s);
                goto LAB_00103a90;
              }
              uVar18 = (uint)uVar19;
              *(undefined4 *)(param_1 + 0x2c4) = 0;
              if (0xf < uVar18) goto LAB_00103b04;
              uVar15 = uVar19 << 4 | 8;
              if (0x2a0 < uVar15) {
LAB_00103b08:
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(1,0x103b0c);
                (*pcVar10)();
              }
              uVar20 = *(uint *)(plVar2 + uVar19 * 2 + 1);
              lVar17 = *(long *)(auStack_310 + uVar19 * 0x10 + 8) + (ulong)uVar20;
              plVar2[uVar19 * 2] = lVar17;
              if (0x28 < uVar18) goto LAB_00103b08;
              uVar12 = local_300[uVar19 * 4];
              uVar16 = uVar12 - uVar20;
              *(uint *)(plVar2 + uVar19 * 2 + 1) = uVar16;
              if ((0x2a0 < uVar15) ||
                 (*(long *)(auStack_310 + uVar19 * 0x10 + 8) = lVar17, 0x28 < uVar18))
              goto LAB_00103b08;
              local_300[uVar19 * 4] = uVar16;
              if (uVar12 == uVar20) {
                uVar18 = uVar18 + 1;
              }
            }
            *(undefined4 *)(param_1 + 0x2c4) = 0;
          } while ((uVar18 < local_f8) && (uVar20 = 0xff00, iVar11 == 0));
          goto LAB_0010399c;
        }
        iVar11 = 0;
        if (__s_00[0x86] != 0) goto LAB_001039a4;
LAB_001039f8:
        uVar20 = 0;
        iVar8 = __s_00[0x87];
      }
      else {
        iVar11 = qcedev_vbuf_ablk_cipher_max_xfer(param_1,&local_314,param_2,__s);
LAB_0010399c:
        if (__s_00[0x86] == 0) goto LAB_001039f8;
LAB_001039a4:
        uVar19 = 0;
        puVar13 = (undefined4 *)(param_1 + 0x48);
        puVar9 = __s_00;
        do {
          if (uVar19 == 0x10) {
LAB_00103b04:
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x103b08);
            (*pcVar10)();
          }
          uVar19 = uVar19 + 1;
          *puVar13 = puVar9[4];
          *(undefined8 *)(puVar13 + -2) = *(undefined8 *)(puVar9 + 2);
          puVar13 = puVar13 + 4;
          uVar20 = __s_00[0x86];
          puVar9 = puVar9 + 4;
        } while (uVar19 < uVar20);
        iVar8 = __s_00[0x87];
      }
      if (iVar8 != 0) {
        uVar19 = 0;
        uVar20 = 0;
        do {
          uVar15 = -(uVar19 >> 0x1f) & 0xfffffff000000000 | uVar19 << 4;
          uVar19 = (ulong)((int)uVar19 + 1);
          puVar6 = (undefined8 *)((long)__s_00 + uVar15 + 0x108);
          puVar7 = (undefined8 *)(param_1 + 0x140 + uVar15);
          *(undefined4 *)(puVar7 + 1) = *(undefined4 *)(puVar6 + 1);
          *puVar7 = *puVar6;
          uVar20 = *(int *)(puVar6 + 1) + uVar20;
        } while (uVar20 < (uint)__s_00[0x87]);
        uVar20 = __s_00[0x86];
      }
      *(uint *)(param_1 + 0x250) = uVar20;
      *(undefined4 *)(param_1 + 0x254) = __s_00[0x87];
      *(undefined4 *)(param_1 + 0x2c4) = __s_00[0xa3];
      memset(__s_00,0,0x2a0);
      memset(__s,0,0xff80);
      kfree(__s_00);
      __s_00 = __s;
LAB_00103a90:
      kfree(__s_00);
      goto LAB_00103a94;
    }
    memset(__s,0,0xff80);
    kfree(__s);
  }
  iVar11 = -0xc;
LAB_00103a94:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar11;
}



//------------------------------------------------------------
// qcedev_check_offload_cipher_params @ 00103b10 size=664
// signature: undefined qcedev_check_offload_cipher_params(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

undefined8 qcedev_check_offload_cipher_params(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  undefined *puVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  uint *puVar11;
  uint uVar12;
  
  uVar1 = *(uint *)(param_1 + 0x200);
  if (((uVar1 == 0) || (uVar2 = *(uint *)(param_1 + 0x204), uVar2 == 0)) || (0x10 < uVar1)) {
    puVar5 = &DAT_00109086;
    goto LAB_00103c80;
  }
  uVar8 = *(uint *)(param_1 + 0x244);
  if ((uVar8 == 2) && (*(uint *)(param_1 + 0x248) < 3)) {
    uVar8 = *(uint *)(param_1 + 0x20c);
    if (uVar8 == 0) {
      return 0xffffffea;
    }
    if ((uVar8 == 0x10) || (uVar8 == 0x20)) {
      if (0xf < *(byte *)(param_1 + 0x23c)) {
        return 0xffffffea;
      }
      uVar7 = *(uint *)(param_1 + 0x238);
      if (uVar7 != 0) {
        if (*(uint *)(param_1 + 0x248) != 2) {
          puVar5 = &DAT_001099d9;
LAB_00103c80:
          _printk(puVar5,"qcedev_check_offload_cipher_params");
          return 0xffffffea;
        }
        if (0xf < uVar7) {
          puVar5 = &DAT_00109ad3;
          goto LAB_00103c80;
        }
        lVar10 = 0;
        uVar12 = uVar7;
        do {
          if (lVar10 == 0x100) goto LAB_00103da4;
          uVar3 = *(uint *)(param_1 + 8 + lVar10);
          if (CARRY4(uVar3,uVar12)) {
            puVar5 = &DAT_00109a54;
            goto LAB_00103c80;
          }
          uVar12 = uVar3 + uVar12;
          lVar10 = lVar10 + 0x10;
        } while ((ulong)uVar1 * 0x10 != lVar10);
      }
      if (uVar2 < uVar7) {
        puVar5 = &DAT_001098f4;
        uVar9 = (ulong)uVar2;
LAB_00103d9c:
        _printk(puVar5,"qcedev_check_offload_cipher_params",uVar9,uVar7);
        return 0xffffffea;
      }
      uVar7 = *(uint *)(param_1 + 0x230);
      if (0x20 < uVar7) {
        puVar5 = &DAT_001099b9;
        pcVar6 = "qcedev_check_offload_cipher_params";
        goto LAB_00103ca4;
      }
      if (uVar8 < 0x41) {
        uVar8 = 0;
        uVar9 = 0;
        do {
          lVar10 = param_1 + (long)(int)uVar9 * 0x10;
          uVar7 = *(uint *)(lVar10 + 0x108);
          if ((*(long *)(lVar10 + 0x100) == 0) && (uVar7 != 0)) {
            puVar5 = &DAT_001095e3;
            goto LAB_00103d9c;
          }
          if (~uVar8 <= uVar7) {
            puVar5 = &DAT_00108be4;
            goto LAB_00103c80;
          }
          uVar8 = uVar7 + uVar8;
          uVar7 = (int)uVar9 + 1;
          uVar9 = (ulong)uVar7;
        } while (uVar1 != uVar7);
        if (uVar8 != uVar2) {
          _printk(&DAT_001091ba,"qcedev_check_offload_cipher_params");
          return 0xffffffea;
        }
        uVar9 = 0;
        uVar8 = 0;
        puVar11 = (uint *)(param_1 + 8);
        do {
          if (uVar9 == 0x10) {
LAB_00103da4:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x103da8);
            (*pcVar4)();
          }
          uVar7 = *puVar11;
          if (*(long *)(puVar11 + -2) == 0) {
            if (uVar7 != 0) {
              puVar5 = &DAT_00109c8b;
              uVar9 = uVar9 & 0xffffffff;
              goto LAB_00103d9c;
            }
          }
          else if (CARRY4(uVar8,uVar7)) {
            puVar5 = &DAT_00108d1d;
            goto LAB_00103c80;
          }
          uVar8 = uVar7 + uVar8;
          uVar9 = uVar9 + 1;
          puVar11 = puVar11 + 4;
        } while (uVar1 != uVar9);
        if (uVar8 == uVar2) {
          return 0;
        }
        puVar5 = &DAT_00109b97;
        uVar9 = (ulong)uVar8;
        uVar7 = uVar2;
        goto LAB_00103d9c;
      }
      puVar5 = &DAT_00109aee;
      goto LAB_00103c98;
    }
    puVar5 = &DAT_00109776;
    pcVar6 = "qcedev_check_offload_cipher_key";
  }
  else {
    puVar5 = &DAT_00108e04;
LAB_00103c98:
    pcVar6 = "qcedev_check_offload_cipher_params";
  }
  uVar7 = uVar8;
LAB_00103ca4:
  _printk(puVar5,pcVar6,uVar7);
  return 0xffffffea;
}



//------------------------------------------------------------
// qcedev_smmu_ablk_offload_cipher @ 00103da8 size=416
// signature: undefined qcedev_smmu_ablk_offload_cipher(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

int qcedev_smmu_ablk_offload_cipher(long param_1,undefined8 param_2)

{
  long *plVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined4 uVar9;
  ulong uVar10;
  ulong local_c0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  long local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  long local_78;
  undefined8 uStack_70;
  long local_68;
  
  local_c0 = 0;
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  if (*(int *)(param_1 + 0x280) == 2) {
    local_c0 = (ulong)*(uint *)(param_1 + 0x270);
  }
  *(undefined8 **)(param_1 + 0x310) = &local_88;
  *(undefined8 **)(param_1 + 0x318) = &local_a8;
  sg_init_table(&local_88,1);
  sg_init_table(&local_a8,1);
  uVar5 = (ulong)*(uint *)(param_1 + 0x238);
  if (*(uint *)(param_1 + 0x238) != 0) {
    uVar8 = 0;
    do {
      if (uVar8 == 0x10) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103f44);
        (*pcVar3)();
      }
      plVar1 = (long *)(param_1 + 0x38 + uVar8 * 0x10);
      lVar6 = *(long *)(param_1 + 0x138 + uVar8 * 0x10);
      uVar2 = *(uint *)(plVar1 + 1);
      uVar10 = (ulong)uVar2;
      lVar7 = *plVar1;
      *(long *)(param_1 + 0x308) = param_1 + 0x248;
      if (uVar2 != 0) {
        lVar6 = lVar6 + local_c0;
        lVar7 = lVar7 + local_c0;
        do {
          uVar5 = uVar10;
          if (0x3fffff < uVar10) {
            uVar5 = 0x400000;
          }
          uVar9 = (undefined4)uVar5;
          *(undefined4 *)(param_1 + 0x300) = uVar9;
          uStack_80 = CONCAT44(uVar9,(undefined4)uStack_80);
          uStack_a0 = CONCAT44(uVar9,(undefined4)uStack_a0);
          local_98 = lVar6;
          local_78 = lVar7;
          iVar4 = submit_req(param_1,param_2);
          if (iVar4 != 0) {
            _printk(&DAT_00109b4d,"qcedev_smmu_ablk_offload_cipher",iVar4);
            goto LAB_00103efc;
          }
          uVar10 = uVar10 - uVar5;
          lVar7 = lVar7 + uVar5;
          lVar6 = lVar6 + uVar5;
        } while (uVar10 != 0);
        uVar5 = (ulong)*(uint *)(param_1 + 0x238);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar5);
  }
  iVar4 = 0;
LAB_00103efc:
  *(undefined8 *)(param_1 + 0x310) = 0;
  *(undefined8 *)(param_1 + 0x318) = 0;
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qcedev_check_sha_params @ 00103f48 size=376
// signature: undefined qcedev_check_sha_params(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

undefined8 qcedev_check_sha_params(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined *puVar3;
  ulong uVar4;
  uint uVar5;
  long lVar6;
  
  uVar5 = *(uint *)(param_1 + 0x13c);
  if (uVar5 == 4) {
    if (*(char *)(param_2 + 0x1c) == '\0') {
      puVar3 = &DAT_00109ce3;
      goto LAB_00104084;
    }
    uVar4 = (ulong)*(uint *)(param_1 + 0x100);
    if (*(uint *)(param_1 + 0x100) - 0x11 < 0xfffffff0) goto LAB_00104014;
    if ((*(int *)(param_1 + 0x138) != 0x10) && (*(int *)(param_1 + 0x138) != 0x20)) {
      puVar3 = &DAT_00108af7;
      goto LAB_00104084;
    }
  }
  else {
    uVar4 = (ulong)*(uint *)(param_1 + 0x100);
    if (*(uint *)(param_1 + 0x100) - 0x11 < 0xfffffff0) {
LAB_00104014:
      _printk(&DAT_00109941,"qcedev_check_sha_params");
      return 0xffffffea;
    }
    if (4 < uVar5) {
      _printk(&DAT_00109d36,"qcedev_check_sha_params",uVar5);
      return 0xffffffea;
    }
    if ((uVar5 & 0xfffffffe) == 2) {
      if (*(long *)(param_1 + 0x130) == 0) {
        puVar3 = &DAT_00109201;
        goto LAB_00104084;
      }
      if (*(int *)(param_1 + 0x138) == 0) {
        _printk(&DAT_00109552,"qcedev_check_sha_params",0);
        return 0xffffffea;
      }
    }
  }
  lVar6 = 0;
  uVar5 = 0;
  while( true ) {
    if (lVar6 == 0x100) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1040c0);
      (*pcVar2)();
    }
    uVar1 = *(uint *)(param_1 + 8 + lVar6);
    if (CARRY4(uVar5,uVar1)) break;
    uVar5 = uVar1 + uVar5;
    lVar6 = lVar6 + 0x10;
    if (uVar4 * 0x10 == lVar6) {
      if (uVar5 == *(uint *)(param_1 + 0x104)) {
        return 0;
      }
      _printk(&DAT_00109b97,"qcedev_check_sha_params",uVar5);
      return 0xffffffea;
    }
  }
  puVar3 = &DAT_0010903c;
LAB_00104084:
  _printk(puVar3,"qcedev_check_sha_params");
  return 0xffffffea;
}



//------------------------------------------------------------
// qcedev_hash_init @ 001040c0 size=1484
// signature: undefined qcedev_hash_init(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcedev_hash_init(ulong param_1,long *param_2,ulong param_3)

{
  long lVar1;
  long *__src;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  undefined8 *extraout_x8;
  undefined8 *puVar9;
  undefined4 uVar10;
  uint uVar11;
  ulong uVar12;
  size_t __n;
  undefined1 *puVar13;
  long lVar14;
  undefined8 local_4c0;
  undefined8 uStack_4b8;
  undefined8 local_4b0;
  undefined8 uStack_4a8;
  undefined8 local_4a0;
  undefined8 uStack_498;
  undefined8 local_490;
  undefined8 uStack_488;
  undefined1 auStack_480 [16];
  undefined4 local_470;
  undefined4 local_450;
  undefined8 local_448;
  undefined4 local_440;
  undefined4 local_348;
  undefined4 local_344;
  undefined8 local_340;
  undefined8 uStack_338;
  undefined8 local_330;
  undefined8 uStack_328;
  undefined4 local_320;
  undefined4 local_30c;
  long *local_c0;
  long local_58;
  
  lVar14 = sp_el0;
  local_58 = *(long *)(lVar14 + 0x638);
  if (1 < *(uint *)(param_1 + 0x174)) {
    lVar14 = *param_2;
    if (*(uint *)(param_1 + 0x170) < 0x41) {
      *(undefined4 *)(param_2 + 0x18) = 0;
      param_2[0x16] = 0;
      param_2[0x17] = 0;
      param_2[0x14] = 0;
      param_2[0x15] = 0;
      param_2[0x12] = 0;
      param_2[0x13] = 0;
      param_2[0x10] = 0;
      param_2[0x11] = 0;
      param_2[0xe] = 0;
      param_2[0xf] = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
      param_2[10] = 0;
      param_2[0xb] = 0;
      param_2[8] = 0;
      param_2[9] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[1] = 0;
      *(undefined1 *)(param_2 + 0x10) = 1;
      lVar6 = DAT_0010a620;
      lVar5 = DAT_0010a618;
      lVar4 = DAT_0010a610;
      lVar3 = DAT_00108850;
      lVar1 = _std_init_vector_sha1_uint8;
      switch(*(undefined4 *)(param_1 + 0x174)) {
      case 0:
      case 2:
        uVar10 = 0x14;
        *(undefined4 *)(param_2 + 5) = 0xf0e1d2c3;
        param_2[3] = lVar1;
        param_2[4] = lVar3;
        break;
      case 1:
      case 3:
        uVar10 = 0x20;
        param_2[3] = _std_init_vector_sha256_uint8;
        param_2[4] = lVar4;
        param_2[5] = lVar5;
        param_2[6] = lVar6;
        break;
      default:
        goto switchD_001041f4_default;
      }
      *(undefined4 *)(param_2 + 7) = uVar10;
switchD_001041f4_default:
      *(undefined1 *)((long)param_2 + 0xc2) = 1;
      __n = (size_t)*(uint *)(param_1 + 0x170);
      if ((int)*(uint *)(param_1 + 0x170) < 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10464c);
        (*pcVar7)();
      }
      puVar13 = (undefined1 *)((long)param_2 + 0x82);
      param_1 = *(ulong *)(param_1 + 0x168);
      __check_object_size(puVar13,__n,0);
      puVar9 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
         (uVar12 = param_1, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
        uVar12 = param_1 & (long)(param_1 << 8) >> 8;
      }
      param_3 = __n;
      if (uVar12 <= 0x8000000000 - __n) {
LAB_00104678:
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar9[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar9[1];
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
        __n = __arch_copy_from_user(puVar13,param_1 & 0xff7fffffffffffff,param_3);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar12 = daif;
          if ((uVar12 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar12;
        }
      }
      if (__n != 0) {
        memset(puVar13 + (param_3 - __n),0,__n);
        iVar8 = -0xe;
        goto LAB_00104604;
      }
    }
    else {
      puVar13 = auStack_480;
      memset(auStack_480,0,0x400);
      local_490 = 0;
      uStack_488 = 0;
      local_4a0 = 0;
      uStack_498 = 0;
      local_4b0 = 0;
      uStack_4a8 = 0;
      local_4c0 = 0;
      uStack_4b8 = 0;
      local_470 = 0;
      __init_swait_queue_head((ulong)puVar13 | 0x18,"&x->wait",&init_completion___key);
      local_448 = *(undefined8 *)(param_1 + 0x168);
      local_440 = *(undefined4 *)(param_1 + 0x170);
      local_320 = 0;
      local_348 = 1;
      local_340 = 0;
      uStack_338 = 0;
      local_330 = 0;
      uStack_328 = 0;
      if (*(int *)(param_1 + 0x174) == 2) {
        local_30c = 0;
      }
      else if (*(int *)(param_1 + 0x174) == 3) {
        local_30c = 1;
      }
      local_450 = 1;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      param_2[8] = 0;
      param_2[9] = 0;
      param_2[10] = 0;
      param_2[0xb] = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
      param_2[0xe] = 0;
      param_2[0xf] = 0;
      param_2[0x10] = 0;
      param_2[0x11] = 0;
      param_2[0x12] = 0;
      param_2[0x13] = 0;
      param_2[0x14] = 0;
      param_2[0x15] = 0;
      param_2[0x16] = 0;
      param_2[0x17] = 0;
      *(undefined4 *)(param_2 + 0x18) = 0;
      *(undefined1 *)(param_2 + 0x10) = 1;
      lVar6 = DAT_0010a620;
      lVar5 = DAT_0010a618;
      lVar4 = DAT_0010a610;
      lVar3 = DAT_00108850;
      lVar1 = _std_init_vector_sha1_uint8;
      switch(local_30c) {
      case 0:
      case 2:
        uVar10 = 0x14;
        *(undefined4 *)(param_2 + 5) = 0xf0e1d2c3;
        param_2[3] = lVar1;
        param_2[4] = lVar3;
        break;
      case 1:
      case 3:
        uVar10 = 0x20;
        param_2[3] = _std_init_vector_sha256_uint8;
        param_2[4] = lVar4;
        param_2[5] = lVar5;
        param_2[6] = lVar6;
        break;
      default:
        goto switchD_001044b4_default;
      }
      *(undefined4 *)(param_2 + 7) = uVar10;
switchD_001044b4_default:
      *(undefined1 *)((long)param_2 + 0xc2) = 1;
      local_344 = local_440;
      local_c0 = param_2;
      iVar8 = qcedev_sha_update(auStack_480,param_2,param_3);
      if (iVar8 != 0) goto LAB_00104604;
      iVar8 = qcedev_sha_final(auStack_480,param_2);
      if (0x40 < *(uint *)(param_2 + 7)) {
        fortify_panic("memcpy");
        puVar9 = extraout_x8;
        goto LAB_00104678;
      }
      __src = param_2 + 3;
      memcpy(&local_4c0,__src,(ulong)*(uint *)(param_2 + 7));
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2[4] = 0;
      param_2[5] = 0;
      param_2[6] = 0;
      param_2[7] = 0;
      param_2[8] = 0;
      param_2[9] = 0;
      param_2[10] = 0;
      param_2[0xb] = 0;
      param_2[0xc] = 0;
      param_2[0xd] = 0;
      param_2[0xe] = 0;
      param_2[0xf] = 0;
      param_2[0x10] = 0;
      param_2[0x11] = 0;
      param_2[0x12] = 0;
      param_2[0x13] = 0;
      param_2[0x14] = 0;
      param_2[0x15] = 0;
      param_2[0x16] = 0;
      param_2[0x17] = 0;
      *(undefined4 *)(param_2 + 0x18) = 0;
      *(undefined1 *)(param_2 + 0x10) = 1;
      lVar6 = DAT_0010a620;
      lVar5 = DAT_0010a618;
      lVar4 = DAT_0010a610;
      lVar3 = DAT_00108850;
      lVar1 = _std_init_vector_sha1_uint8;
      switch(*(undefined4 *)(param_1 + 0x174)) {
      case 0:
      case 2:
        uVar11 = 0x14;
        *(undefined4 *)(param_2 + 5) = 0xf0e1d2c3;
        *__src = lVar1;
        param_2[4] = lVar3;
        break;
      case 1:
      case 3:
        uVar11 = 0x20;
        *__src = _std_init_vector_sha256_uint8;
        param_2[4] = lVar4;
        param_2[5] = lVar5;
        param_2[6] = lVar6;
        break;
      default:
        uVar11 = 0;
        goto LAB_001045ec;
      }
      *(uint *)(param_2 + 7) = uVar11;
LAB_001045ec:
      *(undefined1 *)((long)param_2 + 0xc2) = 1;
      memcpy((void *)((long)param_2 + 0x82),&local_4c0,(ulong)uVar11);
      if (iVar8 != 0) goto LAB_00104604;
    }
    if (*(char *)(lVar14 + 0x1b) == '\0') {
      *(undefined8 *)((long)param_2 + 0x74) = 0;
      *(undefined8 *)((long)param_2 + 0x6c) = 0;
      *(undefined8 *)((long)param_2 + 100) = 0;
      *(undefined8 *)((long)param_2 + 0x5c) = 0;
      *(undefined8 *)((long)param_2 + 0x54) = 0;
      *(undefined8 *)((long)param_2 + 0x4c) = 0;
      *(undefined8 *)((long)param_2 + 0x44) = 0;
      *(undefined8 *)((long)param_2 + 0x3c) = 0;
      lVar14 = 0;
      do {
        lVar1 = lVar14 + 1;
        *(byte *)((long)param_2 + lVar14 + 0x3c) = *(byte *)((long)param_2 + lVar14 + 0x82) ^ 0x36;
        lVar14 = lVar1;
      } while (lVar1 != 0x40);
      iVar8 = 0;
      *(undefined4 *)((long)param_2 + 0x7c) = 0x40;
    }
    else {
      iVar8 = 0;
    }
    goto LAB_00104604;
  }
  *(undefined4 *)(param_2 + 0x18) = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[10] = 0;
  param_2[0xb] = 0;
  param_2[8] = 0;
  param_2[9] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[1] = 0;
  *(undefined1 *)(param_2 + 0x10) = 1;
  lVar5 = DAT_0010a620;
  lVar4 = DAT_0010a618;
  lVar3 = DAT_0010a610;
  lVar1 = DAT_00108850;
  lVar14 = _std_init_vector_sha1_uint8;
  switch(*(undefined4 *)(param_1 + 0x174)) {
  case 0:
    uVar10 = 0x14;
    *(undefined4 *)(param_2 + 5) = 0xf0e1d2c3;
    param_2[3] = lVar14;
    param_2[4] = lVar1;
    break;
  case 1:
    uVar10 = 0x20;
    param_2[3] = _std_init_vector_sha256_uint8;
    param_2[4] = lVar3;
    param_2[5] = lVar4;
    param_2[6] = lVar5;
    break;
  default:
    goto switchD_00104160_default;
  }
  *(undefined4 *)(param_2 + 7) = uVar10;
switchD_00104160_default:
  iVar8 = 0;
  *(undefined1 *)((long)param_2 + 0xc2) = 1;
LAB_00104604:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// qcedev_hash_cmac @ 001046a8 size=920
// signature: undefined qcedev_hash_cmac(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 qcedev_hash_cmac(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  size_t __n;
  uint uVar2;
  uint uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  undefined4 uVar6;
  ulong uVar7;
  void *__s;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  uint *puVar11;
  ulong uVar12;
  void *pvVar13;
  
  uVar2 = *(uint *)(param_1 + 0x170);
  uVar12 = (ulong)uVar2;
  uVar3 = *(uint *)(param_1 + 0x13c);
  if ((uVar2 == 0x10) || (uVar2 == 0x20)) {
    lVar1 = param_2 + 0x82;
    uVar10 = *(ulong *)(param_1 + 0x168);
    __check_object_size(lVar1,uVar12,0);
    puVar4 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = uVar10, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar9 = uVar10 & (long)(uVar10 << 8) >> 8;
    }
    uVar7 = uVar12;
    if (uVar9 <= 0x8000000000 - uVar12) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar7 = daif;
          daif = uVar7 | 0xc0;
        }
        uVar7 = ttbr1_el1;
        ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4[1];
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      uVar7 = __arch_copy_from_user(lVar1,uVar10 & 0xff7fffffffffffff,uVar12);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar9 = daif;
          daif = uVar9 | 0xc0;
        }
        uVar9 = ttbr1_el1;
        ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar9 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if (uVar7 == 0) {
        if (0xffffff7f < uVar3) {
          return 0xffffffea;
        }
        __n = (ulong)uVar3 + 0x80;
        __s = (void *)__kmalloc(__n,0xcc0);
        if (__s == (void *)0x0) {
          return 0xfffffff4;
        }
        uVar12 = (ulong)*(uint *)(param_1 + 0x138);
        if (*(uint *)(param_1 + 0x138) != 0) {
          uVar10 = 0;
          puVar11 = (uint *)(param_1 + 0x40);
          pvVar13 = __s;
          do {
            if (uVar10 == 0x10) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x104a44);
              (*pcVar5)();
            }
            uVar9 = *(ulong *)(puVar11 + -2);
            if (uVar9 != 0) {
              uVar12 = (ulong)*puVar11;
              if ((int)*puVar11 < 0) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1049f8);
                (*pcVar5)();
              }
              __check_object_size(pvVar13,uVar12,0);
              if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
                 (uVar7 = uVar9, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
                uVar7 = uVar9 & (long)(uVar9 << 8) >> 8;
              }
              uVar8 = uVar12;
              if (uVar7 <= 0x8000000000 - uVar12) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar7 = daif;
                  if ((uVar7 & 0x80) == 0) {
                    uVar8 = daif;
                    daif = uVar8 | 0xc0;
                  }
                  uVar8 = ttbr1_el1;
                  ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar4[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar7;
                }
                uVar8 = __arch_copy_from_user(pvVar13,uVar9 & 0xff7fffffffffffff,uVar12);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar9 = daif;
                  if ((uVar9 & 0x80) == 0) {
                    uVar7 = daif;
                    daif = uVar7 | 0xc0;
                  }
                  uVar7 = ttbr1_el1;
                  ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar7 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar9;
                }
              }
              if (uVar8 != 0) {
                memset((void *)((long)pvVar13 + (uVar12 - uVar8)),0,uVar8);
                memset(__s,0,__n);
                kfree(__s);
                goto LAB_00104a38;
              }
              uVar12 = (ulong)*(uint *)(param_1 + 0x138);
            }
            uVar10 = uVar10 + 1;
            pvVar13 = (void *)((long)pvVar13 + (ulong)*puVar11);
            puVar11 = puVar11 + 4;
          } while (uVar10 < uVar12);
        }
        *(undefined8 *)(param_1 + 0x338) = param_3;
        sg_init_one(param_3,__s,(ulong)uVar3);
        *(uint *)(param_1 + 0x330) = uVar3;
        *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 0x160);
        uVar6 = submit_req(param_1);
        memset(__s,0,__n);
        kfree(__s);
        return uVar6;
      }
    }
    memset((void *)(lVar1 + (uVar12 - uVar7)),0,uVar7);
LAB_00104a38:
    uVar6 = 0xfffffff2;
  }
  else {
    _printk(&DAT_00108af7,"qcedev_hash_cmac");
    uVar6 = 0xffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// qcedev_hash_final @ 00104a74 size=560
// signature: undefined qcedev_hash_final(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

int qcedev_hash_final(long param_1,long *param_2)

{
  long lVar1;
  long *__src;
  long lVar2;
  int iVar3;
  void *__dest;
  long lVar4;
  undefined8 *__src_00;
  size_t __n;
  size_t __n_00;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  if (1 < *(uint *)(param_1 + 0x174)) {
    lVar4 = *param_2;
    iVar3 = qcedev_sha_final(param_1,param_2);
    if (*(char *)(lVar4 + 0x1b) != '\0') goto LAB_00104ae0;
    __src_00 = (undefined8 *)((long)param_2 + 0x3c);
    *__src_00 = 0;
    *(undefined8 *)((long)param_2 + 0x6c) = 0;
    *(undefined8 *)((long)param_2 + 0x74) = 0;
    *(undefined8 *)((long)param_2 + 0x5c) = 0;
    *(undefined8 *)((long)param_2 + 100) = 0;
    *(undefined8 *)((long)param_2 + 0x4c) = 0;
    *(undefined8 *)((long)param_2 + 0x54) = 0;
    *(undefined8 *)((long)param_2 + 0x44) = 0;
    lVar4 = 0;
    do {
      lVar1 = lVar4 + 1;
      *(byte *)((long)param_2 + lVar4 + 0x3c) = *(byte *)((long)param_2 + lVar4 + 0x82) ^ 0x5c;
      lVar4 = lVar1;
    } while (lVar1 != 0x40);
    __n = 0x40;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    *(undefined4 *)((long)param_2 + 0x7c) = 0x40;
    if (*(int *)(param_1 + 0x174) == 2) {
      __n_00 = 0x14;
    }
    else if (*(int *)(param_1 + 0x174) == 3) {
      __n_00 = 0x20;
    }
    else {
      __n_00 = 0;
      __n = 0;
    }
    __dest = (void *)__kmalloc(__n,0xcc0);
    if (__dest == (void *)0x0) {
      iVar3 = -0xc;
      goto LAB_00104ae0;
    }
    memcpy(__dest,__src_00,(ulong)*(uint *)((long)param_2 + 0x7c));
    *(undefined8 **)(param_1 + 0x338) = &local_78;
    sg_init_one(&local_78,__dest,__n);
    *(int *)(param_1 + 0x330) = (int)__n;
    memset(__src_00,0,__n);
    __src = param_2 + 3;
    memcpy(__src_00,__src,__n_00);
    *(int *)((long)param_2 + 0x7c) = (int)__n_00;
    param_2[1] = 0;
    *(undefined2 *)(param_2 + 0x10) = 1;
    lVar1 = DAT_00108850;
    lVar4 = _std_init_vector_sha1_uint8;
    iVar3 = *(int *)(param_1 + 0x174);
    if (iVar3 == 2) {
      *(undefined4 *)(param_2 + 7) = 0x14;
      *(undefined4 *)(param_2 + 5) = 0xf0e1d2c3;
      *__src = lVar4;
      param_2[4] = lVar1;
      iVar3 = *(int *)(param_1 + 0x174);
    }
    lVar2 = DAT_0010a620;
    lVar1 = DAT_0010a618;
    lVar4 = DAT_0010a610;
    if (iVar3 == 3) {
      *__src = _std_init_vector_sha256_uint8;
      param_2[4] = lVar4;
      param_2[5] = lVar1;
      param_2[6] = lVar2;
      *(undefined4 *)(param_2 + 7) = 0x20;
    }
    iVar3 = submit_req(param_1,param_2);
    *(undefined2 *)(param_2 + 0x10) = 0;
    memset(__dest,0,__n);
    kfree(__dest);
    *(undefined8 *)(param_1 + 0x338) = 0;
    if (iVar3 != 0) goto LAB_00104ae0;
  }
  iVar3 = qcedev_sha_final(param_1,param_2);
LAB_00104ae0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// init_module @ 00104ca8 size=204
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  long lVar1;
  char local_38 [16];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
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
  _debug_dent = debugfs_create_dir("qcedev",0);
  if (_debug_dent < 0xfffffffffffff001) {
    snprintf(local_38,0xf,"stats-%d",1);
    _debug_qcedev = 0;
    lVar1 = debugfs_create_file(local_38,0x1a4,_debug_dent,&_debug_qcedev,_debug_stats_ops);
    if (lVar1 == 0) {
      debugfs_remove(_debug_dent);
    }
  }
  __platform_driver_register(&qcedev_plat_driver,&__this_module);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104d78 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  debugfs_remove(_debug_dent);
  platform_driver_unregister(&qcedev_plat_driver);
  return;
}



//------------------------------------------------------------
// qcedev_vbuf_ablk_cipher_max_xfer @ 00104da8 size=1624
// signature: undefined qcedev_vbuf_ablk_cipher_max_xfer(void)
// callers: [qcedev_vbuf_ablk_cipher]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcedev_vbuf_ablk_cipher_max_xfer(long param_1,int *param_2,undefined8 param_3,long param_4)

{
  ulong *puVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  void *__s;
  uint uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  ulong uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  ulong *puVar16;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  iVar12 = *param_2;
  local_88 = 0;
  uStack_80 = 0;
  if (*(int *)(param_1 + 0x2cc) == 2) {
    uVar14 = *(uint *)(param_1 + 0x2c4);
    uVar9 = *(ulong *)(param_1 + 0x40);
  }
  else {
    uVar14 = 0;
    uVar9 = *(ulong *)(param_1 + 0x40);
  }
  if (uVar9 != 0) {
    uVar13 = (ulong)*(uint *)(param_1 + 0x48);
    if ((int)*(uint *)(param_1 + 0x48) < 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1053ec);
      (*pcVar2)();
    }
    lVar5 = param_4 + (ulong)uVar14;
    __check_object_size(lVar5,uVar13,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar15 = uVar9, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar15 = uVar9 & (long)(uVar9 << 8) >> 8;
    }
    uVar4 = uVar13;
    if (uVar15 <= 0x8000000000 - uVar13) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar4 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      uVar4 = __arch_copy_from_user(puVar8,lVar5,uVar9 & 0xff7fffffffffffff,uVar13);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar15 = daif;
          daif = uVar15 | 0xc0;
        }
        uVar15 = ttbr1_el1;
        ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar15 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
    }
    if (uVar4 != 0) {
      __s = (void *)(lVar5 + (uVar13 - uVar4));
LAB_001053c8:
      memset(__s,0,uVar4);
      iVar3 = -0xe;
      goto LAB_00105278;
    }
  }
  uVar9 = (ulong)*(uint *)(param_1 + 0x250);
  if (1 < *(uint *)(param_1 + 0x250)) {
    uVar13 = 1;
    puVar8 = (undefined8 *)sp_el0;
    lVar5 = param_4 + (ulong)(*(int *)(param_1 + 0x48) + uVar14);
    puVar10 = (uint *)(param_1 + 0x58);
    do {
      if (uVar13 == 0x10) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10540c);
        (*pcVar2)();
      }
      uVar15 = *(ulong *)(puVar10 + -2);
      if (uVar15 != 0) {
        uVar9 = (ulong)*puVar10;
        if ((int)*puVar10 < 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1053bc);
          (*pcVar2)();
        }
        __check_object_size(lVar5,uVar9,0);
        if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
           (uVar7 = uVar15, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
          uVar7 = uVar15 & (long)(uVar15 << 8) >> 8;
        }
        uVar4 = uVar9;
        if (uVar7 <= 0x8000000000 - uVar9) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar4 = daif;
            if ((uVar4 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            uVar7 = ttbr1_el1;
            ttbr1_el1 = puVar8[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar8[1];
            InstructionSynchronizationBarrier();
            daif = uVar4;
          }
          uVar4 = __arch_copy_from_user(lVar5,uVar15 & 0xff7fffffffffffff,uVar9);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            uVar7 = ttbr1_el1;
            ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
        }
        if (uVar4 != 0) {
          __s = (void *)((lVar5 - uVar4) + uVar9);
          goto LAB_001053c8;
        }
        uVar9 = (ulong)*(uint *)(param_1 + 0x250);
      }
      uVar13 = uVar13 + 1;
      lVar5 = lVar5 + (ulong)*puVar10;
      puVar10 = puVar10 + 4;
    } while (uVar13 < uVar9);
  }
  *(undefined8 **)(param_1 + 0x310) = &local_88;
  *(undefined8 **)(param_1 + 0x318) = &local_88;
  *(uint *)(param_1 + 0x254) = *(int *)(param_1 + 0x254) + uVar14;
  sg_init_one(&local_88,param_4);
  *(undefined4 *)(param_1 + 0x300) = *(undefined4 *)(param_1 + 0x254);
  *(long *)(param_1 + 0x308) = param_1 + 0x2a0;
  *(undefined4 *)(param_1 + 0x250) = 1;
  iVar3 = submit_req(param_1,param_3);
  uVar6 = *(int *)(param_1 + 0x254) - uVar14;
  *(uint *)(param_1 + 0x254) = uVar6;
  if (uVar6 != 0) {
    puVar8 = (undefined8 *)sp_el0;
    do {
      uVar13 = (ulong)uVar6;
      puVar1 = (ulong *)(param_1 + 0x140 + (long)iVar12 * 0x10);
      puVar16 = puVar1 + 1;
      uVar11 = (uint)*puVar16;
      uVar9 = (ulong)uVar11;
      if (uVar6 < uVar11) {
        if (iVar3 == 0) {
          if ((int)uVar6 < 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x105404);
            (*pcVar2)();
          }
          uVar9 = *puVar1;
          param_4 = param_4 + (ulong)uVar14;
          __check_object_size(param_4,uVar13,1);
          puVar8 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
             (uVar15 = uVar9, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
            uVar15 = uVar9 & (long)(uVar9 << 8) >> 8;
          }
          if (uVar15 <= 0x8000000000 - uVar13) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar15 = daif;
              if ((uVar15 & 0x80) == 0) {
                uVar4 = daif;
                daif = uVar4 | 0xc0;
              }
              puVar8 = (undefined8 *)puVar8[1];
              uVar4 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar8;
              InstructionSynchronizationBarrier();
              daif = uVar15;
            }
            lVar5 = __arch_copy_to_user(puVar8,uVar9 & 0xff7fffffffffffff,param_4,uVar13);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar9 = daif;
              if ((uVar9 & 0x80) == 0) {
                uVar13 = daif;
                daif = uVar13 | 0xc0;
              }
              uVar13 = ttbr1_el1;
              ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar13 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar9;
            }
            if (lVar5 == 0) {
              uVar6 = *(uint *)(param_1 + 0x254);
              uVar11 = (uint)*puVar16;
              goto LAB_00105250;
            }
          }
LAB_001053a0:
          iVar3 = -0xe;
          goto LAB_00105270;
        }
LAB_00105250:
        *(uint *)puVar16 = uVar11 - uVar6;
        *puVar1 = *puVar1 + (ulong)uVar6;
        *(undefined4 *)(param_1 + 0x254) = 0;
        break;
      }
      if (iVar3 == 0) {
        if ((int)uVar11 < 0) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1053e0);
          (*pcVar2)();
        }
        uVar13 = *puVar1;
        lVar5 = param_4 + (ulong)uVar14;
        __check_object_size(lVar5,uVar9,1);
        if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
           (uVar15 = uVar13, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
          uVar15 = uVar13 & (long)(uVar13 << 8) >> 8;
        }
        if (uVar15 <= 0x8000000000 - uVar9) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar15 = daif;
            if ((uVar15 & 0x80) == 0) {
              uVar4 = daif;
              daif = uVar4 | 0xc0;
            }
            uVar4 = ttbr1_el1;
            ttbr1_el1 = puVar8[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar8[1];
            InstructionSynchronizationBarrier();
            daif = uVar15;
          }
          uVar9 = __arch_copy_to_user(uVar13 & 0xff7fffffffffffff,lVar5,uVar9);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar15 = daif;
              daif = uVar15 | 0xc0;
            }
            uVar15 = ttbr1_el1;
            ttbr0_el1 = (uVar15 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar15 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
        }
        if (uVar9 != 0) goto LAB_001053a0;
        uVar11 = (uint)*puVar16;
        uVar6 = *(uint *)(param_1 + 0x254);
      }
      uVar6 = uVar6 - uVar11;
      iVar12 = iVar12 + 1;
      param_4 = param_4 + (ulong)uVar11;
      *(uint *)(param_1 + 0x254) = uVar6;
    } while (uVar6 != 0);
  }
  *param_2 = iVar12;
LAB_00105270:
  *(undefined8 *)(param_1 + 0x310) = 0;
  *(undefined8 *)(param_1 + 0x318) = 0;
LAB_00105278:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// submit_req @ 00105470 size=2252
// signature: undefined submit_req(void)
// callers: [qcedev_smmu_ablk_offload_cipher, qcedev_hash_final, qcedev_sha_update_max_xfer, qcedev_sha_final, qcedev_vbuf_ablk_cipher_max_xfer, qcedev_hash_cmac]
//------------------------------------------------------------

void submit_req(long *param_1,long *param_2)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  long lVar13;
  long *plVar14;
  undefined8 uVar15;
  undefined8 *puVar16;
  long lVar17;
  undefined8 local_120;
  code *local_118;
  long local_110;
  undefined8 local_108;
  ulong local_100;
  undefined8 local_f8;
  long local_f0;
  undefined8 local_e8;
  ulong local_e0;
  long local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  long local_c0;
  ulong local_b8;
  long local_b0;
  ulong local_a8;
  ulong local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar1 = sp_el0;
  plVar14 = param_1 + 0x7a;
  local_70 = *(long *)(lVar1 + 0x638);
  *(undefined4 *)(param_1 + 0x79) = 0;
  lVar13 = *param_2;
  __init_waitqueue_head(plVar14,"&qcedev_areq->wait_q",&submit_req___key);
  lVar1 = lVar13 + 0x110;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  uVar8 = 0;
  uVar15 = 0;
  iVar4 = 0;
  plVar2 = (long *)(lVar13 + 0xf8);
  do {
    if (*(long *)(lVar13 + 0x108) != 0) {
      puVar16 = *(undefined8 **)(lVar13 + 0x100);
      uVar6 = __list_add_valid(param_1,puVar16,plVar2);
      if ((uVar6 & 1) != 0) {
        *(long **)(lVar13 + 0x100) = param_1;
        *param_1 = (long)plVar2;
        param_1[1] = (long)puVar16;
        *puVar16 = param_1;
      }
      *(undefined2 *)(param_1 + 0x7d) = 1;
      local_108 = 0;
      local_100 = 0;
      local_118 = (code *)0x0;
      local_110 = 0;
      local_120 = (code *)0x0;
      init_wait_entry(&local_120,0);
      lVar7 = prepare_to_wait_event(plVar14,&local_120,1);
      if ((short)param_1[0x7d] == 0) {
        lVar17 = 0x4e2;
      }
      else {
        lVar17 = 0x4e2;
        do {
          if (lVar7 != 0) goto LAB_00105648;
          _raw_spin_unlock_irq(lVar1);
          lVar17 = schedule_timeout(lVar17);
          _raw_spin_lock_irq(lVar1);
          lVar7 = prepare_to_wait_event(plVar14,&local_120,1);
          if (lVar17 == 0 && (short)param_1[0x7d] == 0) {
            lVar17 = 1;
          }
        } while (((short)param_1[0x7d] != 0) && (lVar17 != 0));
      }
      lVar7 = lVar17;
      finish_wait(plVar14,&local_120);
LAB_00105648:
      if (((int)lVar7 != 0) && ((int)lVar7 != -0x200)) goto LAB_001054f8;
      _printk(&DAT_00109bc6,"submit_req");
      uVar6 = __list_del_entry_valid(param_1);
      if ((uVar6 & 1) != 0) {
        lVar7 = *param_1;
        plVar14 = (long *)param_1[1];
        *(long **)(lVar7 + 8) = plVar14;
        *plVar14 = lVar7;
      }
      *param_1 = -0x2152ffffffffff00;
      param_1[1] = -0x2152fffffffffede;
      *(undefined8 *)(lVar13 + 0x108) = 0;
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      goto LAB_00105b60;
    }
    *(long **)(lVar13 + 0x108) = param_1;
    *(undefined2 *)(param_1 + 0x7d) = 2;
    if ((int)param_1[6] == 2) {
      lVar7 = *(long *)(lVar13 + 0x108);
      local_80 = 0;
      local_78 = 0;
      local_90 = 0;
      local_88 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = 0;
      local_a8 = 0;
      local_c0 = 0;
      local_b8 = 0;
      local_d0 = 0;
      uStack_c8 = 0;
      local_e0 = 0;
      local_d8 = 0;
      local_f0 = 0;
      local_e8 = 0;
      local_100 = 0;
      local_f8 = 0;
      local_110 = 0;
      local_108 = 0;
      local_120 = (code *)0x0;
      local_118 = (code *)0x0;
      *(undefined8 *)(lVar7 + 0x380) = *(undefined8 *)(lVar7 + 0x3c0);
      if (*(int *)(lVar7 + 0x27c) == 2) {
        local_108 = 2;
        if (*(int *)(lVar7 + 0x280) != 0) {
          if (*(int *)(lVar7 + 0x280) != 2) goto LAB_001054f0;
          local_100 = 2;
        }
        if ((*(char *)(lVar7 + 0x276) == '\0') && (*(char *)(lVar7 + 0x277) == '\0')) {
          iVar4 = *(int *)(lVar7 + 0x284);
          if (6 < iVar4 - 1U) {
            if (iVar4 != 8) goto LAB_001054f0;
            goto LAB_001056cc;
          }
          local_108 = 0x100000002;
        }
        else {
          iVar4 = *(int *)(lVar7 + 0x284);
LAB_001056cc:
          local_108 = 2;
        }
        local_b0 = lVar7 + 0x248;
        local_a8 = *(ulong *)(lVar7 + 0x268);
        local_120 = (code *)0x1;
        local_b8 = (ulong)*(uint *)(lVar7 + 0x244);
        local_90 = CONCAT44(iVar4,2);
        if (*(char *)(lVar7 + 0x276) != '\0') {
          local_80 = 0x100000000;
        }
        cVar3 = *(char *)(lVar7 + 0x275);
        local_110 = lVar7 + 0x300;
        local_a0 = (ulong)*(uint *)(lVar7 + 0x23c);
        local_118 = qcedev_offload_cipher_req_cb;
        local_88 = (ulong)(cVar3 != '\0');
        if (cVar3 != '\0') {
          uVar12 = (uint)*(byte *)(lVar7 + 0x278) * 0x10 - 0xf;
          if (*(byte *)(lVar7 + 0x278) == 0) {
            uVar12 = 1;
          }
          uVar10 = 0;
          if (*(byte *)(lVar7 + 0x279) != 0) {
            uVar10 = (uint)*(byte *)(lVar7 + 0x279) * 0x100 - 0x100;
          }
          local_88 = CONCAT44(uVar10 | uVar12 | (uint)*(byte *)(lVar7 + 0x27a) << 0xc,
                              (uint)(cVar3 != '\0'));
        }
        local_80 = CONCAT44(local_80._4_4_,(uint)*(byte *)(lVar7 + 0x274));
        iVar4 = qce_ablk_cipher_req(*(undefined8 *)(lVar13 + 0xe0),&local_120);
        uVar8 = 0;
        if (iVar4 != 0) {
          uVar8 = 0xfffffffa;
        }
        *(undefined4 *)(lVar7 + 0x3c8) = uVar8;
        uVar8 = (undefined4)local_78;
      }
      else {
LAB_001054f0:
        iVar4 = -0x16;
      }
      uVar15 = 0x32;
      goto LAB_001054f8;
    }
    if ((int)param_1[6] == 0) {
      lVar7 = *(long *)(lVar13 + 0x108);
      local_80 = 0;
      local_78 = 0;
      local_90 = 0;
      local_88 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = 0;
      local_a8 = 0;
      local_c0 = 0;
      local_b8 = 0;
      local_d0 = 0;
      uStack_c8 = 0;
      local_e0 = 0;
      local_d8 = 0;
      local_f0 = 0;
      local_e8 = 0;
      local_100 = 0;
      local_f8 = 0;
      local_110 = 0;
      local_108 = 0;
      local_120 = (code *)0x0;
      local_118 = (code *)0x0;
      *(undefined8 *)(lVar7 + 0x380) = *(undefined8 *)(lVar7 + 0x3c0);
      if (*(char *)(lVar7 + 0x38) == '\x01') {
        _printk(&DAT_00108cf9,"start_cipher_req");
LAB_00105a0c:
        iVar4 = 0;
        uVar9 = 0;
      }
      else {
        uVar12 = *(uint *)(lVar7 + 0x2c8);
        if (uVar12 - 1 < 2) {
          local_108 = (ulong)uVar12;
        }
        else if (uVar12 != 0) goto LAB_00105a44;
        iVar4 = -0x16;
        uVar10 = 0;
        switch(*(undefined4 *)(lVar7 + 0x2cc)) {
        case 0:
        case 5:
          break;
        case 1:
        case 6:
          uVar10 = 1;
          break;
        case 2:
          local_100 = 2;
          if (uVar12 != 2) goto LAB_00105938;
          uVar12 = 0;
          goto LAB_00105944;
        case 3:
          uVar10 = 3;
          break;
        default:
          goto switchD_00105818_caseD_4;
        }
        local_100 = (ulong)uVar10;
LAB_00105938:
        uVar12 = (uint)(*(int *)(lVar7 + 0x2d0) != 1);
LAB_00105944:
        local_b0 = lVar7 + 0x2a0;
        local_108 = CONCAT44(uVar12,(undefined4)local_108);
        local_c0 = lVar7 + 0x259;
        local_a8 = (ulong)*(uint *)(lVar7 + 0x2c0);
        local_b8 = (ulong)*(uint *)(lVar7 + 0x29c);
        local_a0 = (ulong)*(uint *)(lVar7 + 0x254);
        if (*(uint *)(lVar7 + 0x29c) == 0) {
          if ((*(uint *)(lVar7 + 0x2d0) & 0xfffffffe) == 2) {
            local_120 = (code *)0x1;
            goto LAB_00105990;
          }
          lVar17 = 0;
          do {
            if (*(char *)(lVar7 + 0x259 + lVar17) != '\0') goto LAB_001059ec;
            lVar17 = lVar17 + 1;
          } while (lVar17 != 0x40);
          if (*(int *)(lVar13 + 8) == 1) goto LAB_00105974;
LAB_001059ec:
          uVar9 = 0xfffffffa;
          iVar4 = -0x16;
        }
        else {
LAB_00105974:
          local_120 = (code *)0x0;
LAB_00105990:
          local_110 = lVar7 + 0x300;
          local_90 = 0;
          local_118 = qcedev_cipher_req_cb;
          iVar4 = qce_ablk_cipher_req(*(undefined8 *)(lVar13 + 0xe0),&local_120);
          uVar8 = (undefined4)local_78;
          if (iVar4 == 0) goto LAB_00105a0c;
          uVar9 = 0xfffffffa;
        }
      }
      *(undefined4 *)(lVar7 + 0x3c8) = uVar9;
switchD_00105818_caseD_4:
      uVar15 = 0x5dc;
      goto LAB_001054f8;
    }
    lVar7 = *(long *)(lVar13 + 0x108);
    local_d8 = 0;
    local_d0 = 0;
    local_e8 = 0;
    local_e0 = 0;
    local_f8 = 0;
    local_f0 = 0;
    local_108 = 0;
    local_100 = 0;
    local_118 = (code *)0x0;
    local_110 = 0;
    local_120 = (code *)0x0;
    if (4 < *(uint *)(lVar7 + 0x174)) {
      _printk(&DAT_00109b26);
LAB_00105a44:
      iVar4 = -0x16;
      uVar15 = 0x5dc;
      goto LAB_001054f8;
    }
    lVar17 = *(long *)(lVar7 + 0x3c0);
    switch(*(uint *)(lVar7 + 0x174)) {
    case 2:
      if (*(char *)(lVar13 + 0x1b) != '\0') {
        uVar12 = 2;
LAB_00105834:
        local_f0 = lVar17 + 0x82;
        local_118 = (code *)(ulong)uVar12;
        local_e8 = 0x40;
      }
      break;
    case 3:
      if (*(char *)(lVar13 + 0x1b) != '\0') {
        uVar12 = 3;
        goto LAB_00105834;
      }
    case 1:
      local_118 = (code *)0x1;
      break;
    case 4:
      local_f0 = lVar17 + 0x82;
      *(long *)(lVar7 + 0x380) = lVar17;
      local_118 = (code *)0x4;
      local_e8 = (ulong)*(uint *)(lVar7 + 0x170);
      goto LAB_001058d0;
    }
    *(long *)(lVar7 + 0x380) = lVar17;
    local_100 = *(ulong *)(lVar17 + 8);
    local_110 = lVar17 + 0x18;
    local_f8 = *(undefined8 *)(lVar17 + 0x10);
    local_e8 = (ulong)CONCAT15(*(char *)(lVar17 + 0x81) != '\0',
                               CONCAT14(*(char *)(lVar17 + 0x80) != '\0',(undefined4)local_e8));
LAB_001058d0:
    local_120 = qcedev_sha_req_cb;
    local_d8 = lVar7 + 0x300;
    local_108 = *(ulong *)(lVar7 + 0x338);
    local_d0 = 0;
    local_e0 = (ulong)*(uint *)(lVar7 + 0x330);
    iVar4 = qce_process_sha_req(*(undefined8 *)(lVar13 + 0xe0),&local_120);
    uVar8 = 0;
    if (iVar4 != 0) {
      uVar8 = 0xfffffffa;
    }
    *(undefined4 *)(lVar7 + 0x3c8) = uVar8;
    uVar15 = 0x5dc;
    uVar8 = local_d0._4_4_;
LAB_001054f8:
  } while ((short)param_1[0x7d] != 2);
  if (iVar4 == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    *(undefined1 *)((long)param_1 + 0x3ea) = 0;
    uVar5 = __msecs_to_jiffies(uVar15);
    iVar4 = wait_for_completion_timeout(param_1 + 2,uVar5);
    if (iVar4 == 0) {
      _printk(&DAT_001097d1,"submit_req",uVar8);
      uVar5 = _raw_spin_lock_irqsave(lVar1);
      *(undefined1 *)((long)param_1 + 0x3ea) = 1;
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      uVar5 = *(undefined8 *)(lVar13 + 0xe0);
      local_120 = (code *)((ulong)local_120 & 0xffffffff00000000);
      *(undefined4 *)(param_1 + 0x51) = 0;
      qce_get_crypto_status(uVar5,&local_120);
      if (local_120._1_1_ == '\0') {
        if (local_120._2_1_ != '\0') {
          uVar9 = 3;
          goto LAB_00105c64;
        }
        if (local_120._3_1_ != '\0') {
          uVar9 = 1;
          goto LAB_00105c64;
        }
        if ((int)param_1[0x51] != 0) goto LAB_00105c68;
        _printk(&DAT_00109cb7,"submit_req");
        if ((short)param_1[0x7d] != 3) {
          uVar12 = 0;
          do {
            usleep_range_state(3000,5000,2);
            _printk(&DAT_001097f6,"submit_req",uVar12 + 1);
            uVar8 = 0;
            if (0x14b < uVar12) break;
            uVar12 = uVar12 + 1;
          } while ((short)param_1[0x7d] != 3);
          goto LAB_00105b64;
        }
      }
      else {
        uVar9 = 2;
LAB_00105c64:
        *(undefined4 *)(param_1 + 0x51) = uVar9;
LAB_00105c68:
        iVar4 = qce_manage_timeout(*(undefined8 *)(lVar13 + 0xe0),uVar8);
        if (iVar4 == 0) {
          req_done(lVar13);
          if ((int)param_1[0x51] == 0) goto LAB_00105afc;
        }
        else {
          _printk(&DAT_001096a1,"submit_req");
          req_done(lVar13);
          if ((int)param_1[0x51] == 0) goto LAB_00105ac4;
        }
      }
      uVar8 = 0;
      goto LAB_00105b64;
    }
  }
  else {
    *(undefined8 *)(lVar13 + 0x108) = 0;
    plVar14 = *(long **)(lVar13 + 0xf8);
    if (plVar14 != plVar2) {
      uVar6 = __list_del_entry_valid(plVar14);
      if ((uVar6 & 1) != 0) {
        lVar13 = *plVar14;
        plVar2 = (long *)plVar14[1];
        *(long **)(lVar13 + 8) = plVar2;
        *plVar2 = lVar13;
      }
      *(undefined2 *)(plVar14 + 0x7d) = 0;
      *plVar14 = -0x2152ffffffffff00;
      plVar14[1] = -0x2152fffffffffede;
      __wake_up(plVar14 + 0x7a,1,1,0);
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    *(undefined1 *)((long)param_1 + 0x3ea) = 0;
LAB_00105ac4:
    *(undefined4 *)(param_1 + 0x79) = 0xfffffffb;
  }
LAB_00105afc:
  if ((int)param_1[6] != 2) {
    if ((int)param_1[6] == 0) {
      if ((int)param_1[0x5a] == 1) {
        iVar4 = (int)param_1[0x79];
        piVar11 = &DAT_00109da8;
      }
      else {
        if ((int)param_1[0x5a] != 0) goto LAB_00105b60;
        iVar4 = (int)param_1[0x79];
        piVar11 = &_qcedev_stat;
      }
    }
    else {
      iVar4 = (int)param_1[0x79];
      piVar11 = (int *)&DAT_00109db0;
    }
    if (iVar4 != 0) {
      piVar11 = piVar11 + 1;
    }
    *piVar11 = *piVar11 + 1;
  }
LAB_00105b60:
  uVar8 = (undefined4)param_1[0x79];
LAB_00105b64:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// req_done @ 00105d40 size=188
// signature: undefined req_done(void)
// callers: [submit_req]
//------------------------------------------------------------

void req_done(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x110);
  lVar4 = *(long *)(param_1 + 0x108);
  *(undefined8 *)(param_1 + 0x108) = 0;
  if ((lVar4 != 0) && (*(undefined2 *)(lVar4 + 1000) = 3, *(char *)(lVar4 + 0x3ea) == '\0')) {
    complete(lVar4 + 0x10);
  }
  plVar5 = *(long **)(param_1 + 0xf8);
  if (plVar5 != (long *)(param_1 + 0xf8)) {
    uVar3 = __list_del_entry_valid(plVar5);
    if ((uVar3 & 1) != 0) {
      lVar4 = *plVar5;
      plVar1 = (long *)plVar5[1];
      *(long **)(lVar4 + 8) = plVar1;
      *plVar1 = lVar4;
    }
    *(undefined2 *)(plVar5 + 0x7d) = 0;
    *plVar5 = -0x2152ffffffffff00;
    plVar5[1] = -0x2152fffffffffede;
    __wake_up(plVar5 + 0x7a,1,1,0);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x110,uVar2);
  return;
}



//------------------------------------------------------------
// qcedev_sha_update @ 00105dfc size=1032
// signature: undefined qcedev_sha_update(void)
// callers: [qcedev_ioctl, qcedev_hash_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcedev_sha_update(long param_1,long param_2,undefined8 param_3)

{
  long *__src;
  long *plVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  code *pcVar5;
  int iVar6;
  void *__dest;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  long lVar15;
  uint uVar16;
  long local_1b0;
  uint local_1a8 [78];
  long local_70;
  
  lVar15 = sp_el0;
  local_70 = *(long *)(lVar15 + 0x638);
  if (*(char *)(param_2 + 0xc2) == '\0') {
    _printk(&DAT_00109022,"qcedev_sha_update");
    iVar6 = -0x16;
  }
  else if (*(uint *)(param_1 + 0x13c) < 0xff01) {
    iVar6 = qcedev_sha_update_max_xfer(param_1,param_2,param_3);
  }
  else {
    __dest = (void *)kmalloc_trace(_memset,0xcc0,0x140);
    if (__dest == (void *)0x0) {
      _printk(&DAT_00108c12,"qcedev_sha_update",0);
      iVar6 = -0xc;
    }
    else {
      __src = (long *)(param_1 + 0x38);
      memcpy(&local_1b0,__src,0x140);
      memcpy(__dest,__src,0x140);
      if (local_1a8[0x3e] == 0) {
        iVar6 = 0;
        uVar16 = *(uint *)((long)__dest + 0x100);
      }
      else {
        uVar16 = 0;
        do {
          if (0xf < uVar16) goto LAB_001061f8;
          lVar15 = (long)(int)uVar16;
          plVar1 = __src + lVar15 * 2;
          if (*(uint *)(plVar1 + 1) < 0xff01) {
            if (local_1a8[0x3e] < uVar16 || local_1a8[0x3e] - uVar16 == 0) {
              *(undefined8 *)(param_1 + 0x138) = 0;
              iVar6 = qcedev_sha_update_max_xfer(param_1,param_2,param_3);
            }
            else {
              lVar15 = (ulong)uVar16 * 0x10 + 0x40;
              uVar8 = 1;
              uVar11 = 0;
              do {
                if (uVar16 + uVar8 == 0x11) goto LAB_001061f8;
                uVar13 = *(int *)(param_1 + lVar15) + uVar11;
                if (0xfe < uVar13 >> 8) {
                  uVar13 = 0xff00;
                  uVar14 = (uVar16 + uVar8) - 1;
                  *(uint *)(param_1 + lVar15) = 0xff00 - uVar11;
                  goto LAB_00105ff8;
                }
                uVar8 = uVar8 + 1;
                lVar15 = lVar15 + 0x10;
                uVar11 = uVar13;
              } while ((uVar16 - local_1a8[0x3e]) + uVar8 != 1);
              uVar14 = local_1a8[0x3e];
              uVar8 = local_1a8[0x3e] - uVar16;
LAB_00105ff8:
              *(uint *)(param_1 + 0x13c) = uVar13;
              if ((0 < (int)uVar16) && (0 < (int)uVar8)) {
                uVar9 = 0;
                puVar12 = (undefined4 *)(param_1 + 0x40);
                do {
                  uVar7 = uVar16 + uVar9;
                  if (0xf < ((uint)uVar7 | (uint)uVar9)) goto LAB_001061f8;
                  uVar9 = uVar9 + 1;
                  *puVar12 = (int)(__src + (uVar7 & 0xffffffff) * 2)[1];
                  *(long *)(puVar12 + -2) = __src[(uVar7 & 0xffffffff) * 2];
                  puVar12 = puVar12 + 4;
                } while (uVar8 != uVar9);
              }
              *(uint *)(param_1 + 0x138) = uVar8;
              iVar6 = qcedev_sha_update_max_xfer(param_1,param_2,param_3);
              if (0xf < uVar14) goto LAB_001061f8;
              uVar16 = uVar14;
            }
            if (0x13 < uVar16) goto LAB_001061fc;
            uVar7 = (ulong)uVar16;
            uVar8 = *(uint *)(__src + (ulong)uVar16 * 2 + 1);
            uVar9 = uVar7 << 4 | 8;
            lVar15 = *(long *)(local_1a8 + (ulong)uVar16 * 4 + -2) + (ulong)uVar8;
            __src[uVar7 * 2] = lVar15;
            if (0x140 < uVar9) goto LAB_001061fc;
            uVar11 = local_1a8[uVar7 * 4];
            uVar13 = uVar11 - uVar8;
            *(uint *)(__src + (ulong)uVar16 * 2 + 1) = uVar13;
            if ((0x13 < uVar16) ||
               (*(long *)(local_1a8 + (ulong)uVar16 * 4 + -2) = lVar15, 0x140 < uVar9))
            goto LAB_001061fc;
            local_1a8[uVar7 * 4] = uVar13;
            if (uVar11 == uVar8) {
              uVar16 = uVar16 + 1;
            }
          }
          else {
            *(undefined4 *)(param_1 + 0x40) = 0xff00;
            if (uVar16 != 0) {
              *__src = *plVar1;
            }
            *(undefined8 *)(param_1 + 0x138) = 0xff0000000001;
            iVar6 = qcedev_sha_update_max_xfer(param_1,param_2,param_3);
            uVar9 = lVar15 << 4 | 8;
            if (0x140 < uVar9) {
LAB_001061fc:
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(1,0x106200);
              (*pcVar5)();
            }
            uVar8 = local_1a8[lVar15 * 4] - 0xff00;
            *(uint *)(plVar1 + 1) = uVar8;
            if ((0x140 < (ulong)(lVar15 * 0x10)) || (uVar16 == 0x14)) goto LAB_001061fc;
            lVar2 = *(long *)(local_1a8 + lVar15 * 4 + -2) + 0xff00;
            *plVar1 = lVar2;
            *(long *)(local_1a8 + lVar15 * 4 + -2) = lVar2;
            if (0x140 < uVar9) goto LAB_001061fc;
            local_1a8[lVar15 * 4] = uVar8;
          }
        } while ((uVar16 < local_1a8[0x3e]) && (iVar6 == 0));
        uVar16 = *(uint *)((long)__dest + 0x100);
      }
      if (uVar16 != 0) {
        lVar15 = 0;
        do {
          if (lVar15 == 0x100) {
LAB_001061f8:
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1061fc);
            (*pcVar5)();
          }
          puVar3 = (undefined8 *)((long)__dest + lVar15);
          lVar2 = param_1 + lVar15;
          lVar15 = lVar15 + 0x10;
          uVar10 = *puVar3;
          *(undefined4 *)(lVar2 + 0x40) = *(undefined4 *)(puVar3 + 1);
          *(undefined8 *)(lVar2 + 0x38) = uVar10;
        } while ((ulong)uVar16 * 0x10 != lVar15);
      }
      uVar4 = *(undefined4 *)((long)__dest + 0x104);
      *(uint *)(param_1 + 0x138) = uVar16;
      *(undefined4 *)(param_1 + 0x13c) = uVar4;
      memset(__dest,0,0x140);
      kfree(__dest);
    }
  }
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qcedev_sha_final @ 00106204 size=324
// signature: undefined qcedev_sha_final(void)
// callers: [qcedev_hash_final, qcedev_hash_init]
//------------------------------------------------------------

undefined4 qcedev_sha_final(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  void *__dest;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (*(char *)(param_2 + 0xc2) == '\0') {
    _printk(&DAT_00109022,"qcedev_sha_final");
    uVar3 = 0xffffffea;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0x7c);
    *(undefined1 *)(param_2 + 0x81) = 1;
    __dest = (void *)__kmalloc((ulong)(uVar1 + 0x80),0xcc0);
    if (__dest == (void *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      memcpy(__dest,(void *)(param_2 + 0x3c),(ulong)uVar1);
      *(undefined8 **)(param_1 + 0x338) = &local_68;
      sg_init_one(&local_68,__dest,uVar1);
      *(uint *)(param_1 + 0x330) = uVar1;
      uVar3 = submit_req(param_1,param_2);
      *(undefined2 *)(param_2 + 0x80) = 0;
      *(undefined8 *)(param_2 + 8) = 0;
      *(undefined4 *)(param_2 + 0x7c) = 0;
      *(undefined1 *)(param_2 + 0xc2) = 0;
      *(undefined8 *)(param_2 + 0x3c) = 0;
      *(undefined8 *)(param_2 + 0x44) = 0;
      *(undefined8 *)(param_2 + 0x4c) = 0;
      *(undefined8 *)(param_2 + 0x54) = 0;
      *(undefined8 *)(param_2 + 0x5c) = 0;
      *(undefined8 *)(param_2 + 100) = 0;
      *(undefined8 *)(param_2 + 0x6c) = 0;
      *(undefined8 *)(param_2 + 0x74) = 0;
      memset(__dest,0,(ulong)(uVar1 + 0x80));
      kfree(__dest);
      *(undefined8 *)(param_1 + 0x338) = 0;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// qcedev_sha_update_max_xfer @ 00106348 size=1468
// signature: undefined qcedev_sha_update_max_xfer(void)
// callers: [qcedev_sha_update]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 qcedev_sha_update_max_xfer(long param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  undefined4 uVar5;
  ulong uVar6;
  void *__dest;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long lVar12;
  ulong uVar13;
  int iVar14;
  void *pvVar15;
  ulong uVar16;
  uint *puVar17;
  
  uVar3 = *(uint *)(param_2 + 0x7c);
  uVar16 = (ulong)uVar3;
  iVar14 = *(int *)(param_1 + 0x13c);
  uVar1 = iVar14 + uVar3;
  if (uVar1 < 0x41) {
    if (0x40 < uVar3) {
LAB_00106928:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10692c);
      (*pcVar4)();
    }
    if (iVar14 != 0) {
      puVar11 = (undefined8 *)sp_el0;
      lVar12 = param_2 + uVar16 + 0x3c;
      lVar9 = 0;
      do {
        if (lVar9 + 0x10 == 0x110) goto LAB_00106928;
        lVar2 = param_1 + lVar9;
        uVar16 = *(ulong *)(lVar2 + 0x38);
        if (uVar16 != 0) {
          uVar13 = (ulong)*(uint *)(lVar2 + 0x40);
          if ((int)*(uint *)(lVar2 + 0x40) < 0) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x800,0x106874);
            (*pcVar4)();
          }
          __check_object_size(lVar12,uVar13,0);
          if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
             (uVar10 = uVar16, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
            uVar10 = uVar16 & (long)(uVar16 << 8) >> 8;
          }
          uVar6 = uVar13;
          if (uVar10 <= 0x8000000000 - uVar13) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar10 = daif;
              if ((uVar10 & 0x80) == 0) {
                uVar6 = daif;
                daif = uVar6 | 0xc0;
              }
              uVar6 = ttbr1_el1;
              ttbr1_el1 = puVar11[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar11[1];
              InstructionSynchronizationBarrier();
              daif = uVar10;
            }
            uVar6 = __arch_copy_from_user(lVar12,uVar16 & 0xff7fffffffffffff,uVar13);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar16 = daif;
              if ((uVar16 & 0x80) == 0) {
                uVar10 = daif;
                daif = uVar10 | 0xc0;
              }
              uVar10 = ttbr1_el1;
              ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar10 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar16;
            }
          }
          if (uVar6 != 0) {
            memset((void *)((lVar12 - uVar6) + uVar13),0,uVar6);
            return 0xfffffff2;
          }
        }
        iVar14 = iVar14 - *(uint *)(lVar2 + 0x40);
        lVar12 = lVar12 + (ulong)*(uint *)(lVar2 + 0x40);
        lVar9 = lVar9 + 0x10;
      } while (iVar14 != 0);
    }
    uVar5 = 0;
    *(uint *)(param_2 + 0x7c) = uVar1;
  }
  else {
    uVar13 = (ulong)(uVar1 + 0x80);
    __dest = (void *)__kmalloc(uVar13,0xcc0);
    if (__dest == (void *)0x0) {
      uVar5 = 0xfffffff4;
    }
    else {
      pvVar15 = __dest;
      if (uVar3 != 0) {
        memcpy(__dest,(void *)(param_2 + 0x3c),uVar16);
        pvVar15 = (void *)((long)__dest + uVar16);
      }
      uVar16 = *(ulong *)(param_1 + 0x38);
      if (uVar16 != 0) {
        uVar10 = (ulong)*(uint *)(param_1 + 0x40);
        if ((int)*(uint *)(param_1 + 0x40) < 0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1068d0);
          (*pcVar4)();
        }
        __check_object_size(pvVar15,uVar10,0);
        puVar11 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
           (uVar6 = uVar16, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
          uVar6 = uVar16 & (long)(uVar16 << 8) >> 8;
        }
        uVar7 = uVar10;
        if (uVar6 <= 0x8000000000 - uVar10) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar6 = daif;
            if ((uVar6 & 0x80) == 0) {
              uVar7 = daif;
              daif = uVar7 | 0xc0;
            }
            puVar11 = (undefined8 *)puVar11[1];
            uVar7 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar11 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar11;
            InstructionSynchronizationBarrier();
            daif = uVar6;
          }
          uVar7 = __arch_copy_from_user(puVar11,pvVar15,uVar16 & 0xff7fffffffffffff,uVar10);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar16 = daif;
            if ((uVar16 & 0x80) == 0) {
              uVar6 = daif;
              daif = uVar6 | 0xc0;
            }
            uVar6 = ttbr1_el1;
            ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar6 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar16;
          }
        }
        if (uVar7 != 0) {
          memset((void *)((long)pvVar15 + (uVar10 - uVar7)),0,uVar7);
          memset(__dest,0,uVar13);
LAB_001068c0:
          kfree(__dest);
          return 0xfffffff2;
        }
      }
      uVar16 = (ulong)*(uint *)(param_1 + 0x138);
      lVar12 = (long)pvVar15 + (ulong)*(uint *)(param_1 + 0x40);
      if (1 < *(uint *)(param_1 + 0x138)) {
        uVar10 = 1;
        puVar11 = (undefined8 *)sp_el0;
        puVar17 = (uint *)(param_1 + 0x50);
        do {
          if (uVar10 == 0x10) goto LAB_00106928;
          uVar6 = *(ulong *)(puVar17 + -2);
          if (uVar6 != 0) {
            uVar16 = (ulong)*puVar17;
            if ((int)*puVar17 < 0) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x800,0x106894);
              (*pcVar4)();
            }
            __check_object_size(lVar12,uVar16,0);
            if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
               (uVar7 = uVar6, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
              uVar7 = uVar6 & (long)(uVar6 << 8) >> 8;
            }
            uVar8 = uVar16;
            if (uVar7 <= 0x8000000000 - uVar16) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar7 = daif;
                if ((uVar7 & 0x80) == 0) {
                  uVar8 = daif;
                  daif = uVar8 | 0xc0;
                }
                uVar8 = ttbr1_el1;
                ttbr1_el1 = puVar11[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar11[1];
                InstructionSynchronizationBarrier();
                daif = uVar7;
              }
              uVar8 = __arch_copy_from_user(lVar12,uVar6 & 0xff7fffffffffffff,uVar16);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar6 = daif;
                if ((uVar6 & 0x80) == 0) {
                  uVar7 = daif;
                  daif = uVar7 | 0xc0;
                }
                uVar7 = ttbr1_el1;
                ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar7 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar6;
              }
            }
            if (uVar8 != 0) {
              memset((void *)((lVar12 - uVar8) + uVar16),0,uVar8);
              memset(__dest,0,uVar13);
              goto LAB_001068c0;
            }
            uVar16 = (ulong)*(uint *)(param_1 + 0x138);
          }
          uVar10 = uVar10 + 1;
          lVar12 = lVar12 + (ulong)*puVar17;
          puVar17 = puVar17 + 4;
        } while (uVar10 < uVar16);
      }
      uVar3 = (uVar1 - (uVar1 + 0x3f & 0xffffffc0)) + 0x40;
      uVar16 = (ulong)uVar3;
      *(undefined8 *)(param_1 + 0x338) = param_3;
      sg_init_one(param_3,__dest,uVar1 - uVar3);
      *(uint *)(param_1 + 0x330) = uVar1 - uVar3;
      if (uVar3 != 0) {
        *(undefined8 *)(param_2 + 0x3c) = 0;
        *(undefined8 *)(param_2 + 0x6c) = 0;
        *(undefined8 *)(param_2 + 0x74) = 0;
        *(undefined8 *)(param_2 + 0x5c) = 0;
        *(undefined8 *)(param_2 + 100) = 0;
        *(undefined8 *)(param_2 + 0x4c) = 0;
        *(undefined8 *)(param_2 + 0x54) = 0;
        *(undefined8 *)(param_2 + 0x44) = 0;
        if ((0x40 < uVar3) && ((qcedev_sha_update_max_xfer___already_done_73 & 1) == 0)) {
          qcedev_sha_update_max_xfer___already_done_73 = 1;
          __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                        ,uVar16,
                        "field \"&handle->sha_ctxt.trailing_buf[0]\" at ../vendor/qcom/opensource/securemsm-kernel/crypto-qti/qcedev.c:1026"
                        ,0x40);
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x106924);
          (*pcVar4)();
        }
        memcpy((undefined8 *)(param_2 + 0x3c),(void *)(lVar12 - uVar16),uVar16);
      }
      *(uint *)(param_2 + 0x7c) = uVar3;
      uVar5 = submit_req(param_1,param_2);
      *(undefined2 *)(param_2 + 0x80) = 0;
      memset(__dest,0,uVar13);
      kfree(__dest);
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// _debug_stats_read @ 00106960 size=340
// signature: undefined _debug_stats_read(void)
// callers: []
//------------------------------------------------------------

undefined8 _debug_stats_read(long param_1,undefined8 param_2,ulong param_3,undefined8 param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  uVar2 = scnprintf(_debug_read_buf,0x3ff,"\nQTI QCE dev driver %d Statistics:\n",
                    **(int **)(param_1 + 0xd8) + 1);
  if (uVar2 < 0x401) {
    iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0x3ff - uVar2),
                      "   Encryption operation success       : %d\n",DAT_00109da8);
    uVar2 = iVar3 + uVar2;
    if (uVar2 < 0x401) {
      iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0x3ff - uVar2),
                        "   Encryption operation fail   : %d\n",DAT_00109dac);
      uVar2 = iVar3 + uVar2;
      if (uVar2 < 0x401) {
        iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0x3ff - uVar2),
                          "   Decryption operation success     : %d\n",_qcedev_stat);
        uVar2 = iVar3 + uVar2;
        if (uVar2 < 0x401) {
          iVar3 = scnprintf(_debug_read_buf + uVar2,(long)(int)(0x3ff - uVar2),
                            "   Encryption operation fail          : %d\n",DAT_00109da4);
          uVar5 = (ulong)(int)(iVar3 + uVar2);
          if (param_3 < uVar5) {
            uVar4 = 0xffffffffffffffea;
          }
          else {
            uVar4 = simple_read_from_buffer(param_2,uVar5,param_4,_debug_read_buf,uVar5);
          }
          return uVar4;
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x106ab4);
  (*pcVar1)();
}



//------------------------------------------------------------
// _debug_stats_write @ 00106ab8 size=24
// signature: undefined _debug_stats_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _debug_stats_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  _DAT_00109da8 = 0;
  DAT_00109db0 = 0;
  __qcedev_stat = 0;
  return param_3;
}



//------------------------------------------------------------
// qcedev_probe @ 00106ad4 size=1200
// signature: undefined qcedev_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint qcedev_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  uint local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,qcedev");
  if (iVar1 == 0) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,qcedev,context-bank");
    if (iVar1 == 0) {
      uVar2 = 0xffffffea;
    }
    else {
      uVar2 = qcedev_parse_context_bank(param_1);
    }
    goto LAB_00106f48;
  }
  uVar2 = alloc_chrdev_region(&qcedev_device_no,0,1,&DAT_00109cfd);
  if ((int)uVar2 < 0) {
    _printk(&DAT_00109a78,uVar2);
    goto LAB_00106f48;
  }
  driver_class = __class_create(&__this_module,&DAT_00109cfd,&qcedev_probe_device___key);
  if (driver_class < 0xfffffffffffff001) {
    class_dev = device_create(driver_class,0,qcedev_device_no,0,&DAT_00109cfd);
    if (class_dev < 0xfffffffffffff001) {
      cdev_init(&DAT_0010a368,&qcedev_fops);
      _DAT_0010a3c8 = &__this_module;
      local_5c = cdev_add(&DAT_0010a368,qcedev_device_no & 0xfff00000,1);
      if ((int)local_5c < 0) {
        _printk(&DAT_00109d66,local_5c);
      }
      else {
        _DAT_0010a3f0 = 0;
        _DAT_0010a32c = 0;
        _DAT_0010a410 = &DAT_0010a410;
        _DAT_0010a418 = &DAT_0010a410;
        _DAT_0010a420 = 0;
        _DAT_0010a458 = &DAT_0010a458;
        _DAT_0010a460 = &DAT_0010a458;
        _DAT_0010a428 = 0;
        tasklet_init(&DAT_0010a430,req_done,&qce_dev);
        DAT_0010a358 = of_icc_get(param_1 + 0x10,"data_path");
        if (DAT_0010a358 < 0xfffffffffffff001) {
          iVar1 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,icc_avg_bw",&DAT_0010a360,1,0);
          if (iVar1 < 0) {
            _printk(&DAT_00108e38,"qcedev_probe_device");
            DAT_0010a360 = 0x180;
          }
          iVar1 = of_property_read_variable_u32_array
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,icc_peak_bw",&DAT_0010a364,1,0);
          if (iVar1 < 0) {
            _printk(&DAT_0010985d,"qcedev_probe_device");
            DAT_0010a364 = 0x180;
          }
          local_5c = icc_set_bw(DAT_0010a358,DAT_0010a360,DAT_0010a364);
          if (local_5c == 0) {
            lVar3 = qce_open(param_1,&local_5c);
            if (lVar3 == 0) {
              local_5c = 0xffffffed;
            }
            else {
              DAT_0010a3f8 = lVar3;
              local_5c = qce_set_irqs(lVar3,0);
              if (local_5c == 0) {
                local_5c = icc_set_bw(DAT_0010a358,0);
                if (local_5c == 0) {
                  DAT_0010a400 = param_1;
                  *(undefined4 **)(param_1 + 0xa8) = &qce_dev;
                  qce_hw_support(DAT_0010a3f8,&DAT_0010a330);
                  if (DAT_0010a33a == '\0') {
                    puVar5 = *(undefined4 **)(param_1 + 0xa0);
                    qce_dev = *puVar5;
                    DAT_0010a31c = puVar5[1];
                    DAT_0010a320 = puVar5[2];
                    DAT_0010a324 = puVar5[3];
                  }
                  else {
                    qce_dev = 0;
                    DAT_0010a31c = 0;
                    DAT_0010a324 = 1;
                    DAT_0010a320 = (uint)DAT_0010a33c;
                  }
                  DAT_0010a468 = qcedev_mem_new_client(0);
                  if (DAT_0010a468 == 0) {
                    puVar4 = &DAT_00109337;
                    goto LAB_00106eac;
                  }
                  local_5c = of_platform_populate
                                       (*(undefined8 *)(param_1 + 0x2f8),&qcedev_match,0,
                                        param_1 + 0x10);
                  if (local_5c == 0) {
                    uVar2 = 0;
                    goto LAB_00106f48;
                  }
                  _printk(&DAT_00109961,"qcedev_probe_device",local_5c);
                  if (DAT_0010a468 != 0) {
                    qcedev_mem_delete_client();
                  }
                  DAT_0010a468 = 0;
                }
                else {
                  puVar4 = &DAT_00108c3b;
LAB_00106eac:
                  _printk(puVar4,"qcedev_probe_device");
                }
                qce_close(lVar3);
              }
              else {
                _printk(&DAT_00109886,"qcedev_probe_device",local_5c);
              }
            }
            icc_set_bw(DAT_0010a358,0,0);
          }
          else {
            _printk(&DAT_00109644,"qcedev_probe_device");
          }
          if (DAT_0010a358 != 0) {
            icc_put();
          }
        }
        else {
          local_5c = (uint)DAT_0010a358;
          _printk(&DAT_0010982b,"qcedev_probe_device");
        }
        cdev_del(&DAT_0010a368);
      }
      device_destroy(driver_class,qcedev_device_no);
    }
    else {
      _printk(&DAT_00108bba,uVar2);
      local_5c = 0xfffffff4;
    }
    class_destroy(driver_class);
  }
  else {
    local_5c = 0xfffffff4;
    _printk(&DAT_0010906c,0xfffffff4);
  }
  unregister_chrdev_region(qcedev_device_no,1);
  DAT_0010a358 = 0;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  DAT_0010a3f8 = 0;
  DAT_0010a400 = 0;
  uVar2 = local_5c;
LAB_00106f48:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// qcedev_remove @ 00106f88 size=244
// signature: undefined qcedev_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcedev_remove(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 == 0) {
    return 0;
  }
  qcedev_ce_high_bw_req(lVar2,1);
  if (*(long *)(lVar2 + 0xe0) != 0) {
    qce_close();
  }
  mutex_lock(qcedev_sent_bw_req);
  iVar1 = *(int *)(lVar2 + 0x14);
  if (iVar1 == 1) {
    iVar1 = qce_set_irqs(*(undefined8 *)(lVar2 + 0xe0),0);
    if (iVar1 != 0) {
      _printk(&DAT_00109886,"qcedev_ce_high_bw_req",iVar1);
      goto LAB_00106ffc;
    }
    iVar1 = qcedev_control_clocks(lVar2,0);
    if (iVar1 != 0) goto LAB_00106ffc;
    iVar1 = *(int *)(lVar2 + 0x14);
  }
  *(int *)(lVar2 + 0x14) = iVar1 + -1;
LAB_00106ffc:
  mutex_unlock(qcedev_sent_bw_req);
  if (*(long *)(lVar2 + 0x40) != 0) {
    icc_put();
  }
  tasklet_kill(lVar2 + 0x118);
  cdev_del(lVar2 + 0x50);
  device_destroy(driver_class,qcedev_device_no);
  class_destroy(driver_class);
  unregister_chrdev_region(qcedev_device_no,1);
  return 0;
}



//------------------------------------------------------------
// qcedev_suspend @ 00107080 size=132
// signature: undefined qcedev_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 qcedev_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 != 0) {
    mutex_lock(qcedev_sent_bw_req);
    if (*(int *)(lVar2 + 0x14) != 0) {
      iVar1 = qce_set_irqs(*(undefined8 *)(lVar2 + 0xe0),0);
      if (iVar1 == 0) {
        qcedev_control_clocks(lVar2,0);
      }
      else {
        _printk(&DAT_00109886,"qcedev_suspend",iVar1);
      }
    }
    mutex_unlock(qcedev_sent_bw_req);
  }
  return 0;
}



//------------------------------------------------------------
// qcedev_resume @ 00107108 size=148
// signature: undefined qcedev_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 qcedev_resume(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa8);
  if (lVar2 != 0) {
    mutex_lock(qcedev_sent_bw_req);
    if (((*(int *)(lVar2 + 0x14) != 0) && (iVar1 = qcedev_control_clocks(lVar2,1), iVar1 == 0)) &&
       (iVar1 = qce_set_irqs(*(undefined8 *)(lVar2 + 0xe0),1), iVar1 != 0)) {
      _printk(&DAT_00108a91,"qcedev_resume",iVar1);
      qcedev_control_clocks(lVar2,0);
    }
    mutex_unlock(qcedev_sent_bw_req);
  }
  return 0;
}



//------------------------------------------------------------
// qcedev_open @ 001071a0 size=224
// signature: undefined qcedev_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcedev_open(long param_1,long param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 *puVar5;
  
  uVar4 = (ulong)*(uint *)(param_1 + 0x4c) & 0xfffff;
  uVar3 = (uint)uVar4;
  if (_DAT_0010a3f0 == uVar3) {
    if (1 < uVar3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x107280);
      (*pcVar1)();
    }
    puVar5 = &qce_dev + uVar4 * 0x56;
    if (puVar5 != (undefined4 *)0x0) {
      puVar2 = (undefined8 *)kmalloc_trace(_memset,0xdc0,0x108);
      if (puVar2 == (undefined8 *)0x0) {
        return 0xfffffff4;
      }
      *puVar2 = puVar5;
      *(undefined8 **)(param_2 + 0xd8) = puVar2;
      qcedev_ce_high_bw_req(puVar5,1);
      __mutex_init(puVar2 + 0x1b,"&handle->registeredbufs.lock",&qcedev_open___key);
      puVar2[0x19] = puVar2 + 0x19;
      puVar2[0x1a] = puVar2 + 0x19;
      return 0;
    }
  }
  _printk(&DAT_00109d7c,"qcedev_open");
  return 0xfffffffe;
}



//------------------------------------------------------------
// qcedev_release @ 00107284 size=264
// signature: undefined qcedev_release(void)
// callers: []
//------------------------------------------------------------

undefined8 qcedev_release(undefined8 param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = *(long **)(param_2 + 0xd8);
  lVar3 = *plVar2;
  if (lVar3 == 0) goto LAB_0010730c;
  if (*(int *)(lVar3 + 0xf0) != 0x56434544) {
    _printk(&DAT_00109379,"qcedev_release",lVar3);
  }
  mutex_lock(qcedev_sent_bw_req);
  iVar1 = *(int *)(lVar3 + 0x14);
  if (iVar1 == 1) {
    iVar1 = qce_set_irqs(*(undefined8 *)(lVar3 + 0xe0),0);
    if (iVar1 == 0) {
      iVar1 = qcedev_control_clocks(lVar3,0);
      if (iVar1 == 0) {
        iVar1 = *(int *)(lVar3 + 0x14);
        goto LAB_001072f8;
      }
    }
    else {
      _printk(&DAT_00109886,"qcedev_ce_high_bw_req",iVar1);
    }
  }
  else {
LAB_001072f8:
    *(int *)(lVar3 + 0x14) = iVar1 + -1;
  }
  mutex_unlock(qcedev_sent_bw_req);
LAB_0010730c:
  iVar1 = qcedev_unmap_all_buffers(plVar2);
  if (iVar1 != 0) {
    _printk(&DAT_00109c64,"qcedev_release");
  }
  kfree_sensitive(plVar2);
  *(undefined8 *)(param_2 + 0xd8) = 0;
  return 0;
}



//------------------------------------------------------------
// qcedev_ce_high_bw_req @ 0010738c size=244
// signature: undefined qcedev_ce_high_bw_req(void)
// callers: [qcedev_remove, qcedev_open]
//------------------------------------------------------------

void qcedev_ce_high_bw_req(long param_1,ulong param_2)

{
  int iVar1;
  
  mutex_lock(qcedev_sent_bw_req);
  iVar1 = *(int *)(param_1 + 0x14);
  if ((param_2 & 1) == 0) {
    if (iVar1 == 1) {
      iVar1 = qce_set_irqs(*(undefined8 *)(param_1 + 0xe0),0);
      if (iVar1 != 0) {
        _printk(&DAT_00109886,"qcedev_ce_high_bw_req",iVar1);
        goto LAB_001073f8;
      }
      iVar1 = qcedev_control_clocks(param_1,0);
      if (iVar1 != 0) goto LAB_001073f8;
      iVar1 = *(int *)(param_1 + 0x14);
    }
    iVar1 = iVar1 + -1;
  }
  else {
    if (iVar1 == 0) {
      iVar1 = qcedev_control_clocks(param_1,1);
      if (iVar1 != 0) goto LAB_001073f8;
      iVar1 = qce_set_irqs(*(undefined8 *)(param_1 + 0xe0),1);
      if (iVar1 != 0) {
        _printk(&DAT_00108a91,"qcedev_ce_high_bw_req",iVar1);
        qcedev_control_clocks(param_1,0);
        goto LAB_001073f8;
      }
      iVar1 = *(int *)(param_1 + 0x14);
    }
    iVar1 = iVar1 + 1;
  }
  *(int *)(param_1 + 0x14) = iVar1;
LAB_001073f8:
  mutex_unlock(qcedev_sent_bw_req);
  return;
}



//------------------------------------------------------------
// qcedev_control_clocks @ 00107480 size=496
// signature: undefined qcedev_control_clocks(void)
// callers: [qcedev_ce_high_bw_req, qcedev_suspend, qcedev_remove, qcedev_resume, qcedev_release]
//------------------------------------------------------------

int qcedev_control_clocks(long param_1,ulong param_2)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  bVar1 = (param_2 & 1) == 0;
  uVar4 = 2;
  if (bVar1) {
    uVar4 = 3;
  }
  uVar5 = 4;
  if (!bVar1) {
    uVar5 = 1;
  }
  if (*(char *)(param_1 + 0x2c) != '\0') {
    uVar5 = uVar4;
  }
  switch(uVar5) {
  case 1:
    iVar2 = qce_enable_clk(*(undefined8 *)(param_1 + 0xe0));
    if (iVar2 == 0) {
      iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x48),
                         *(undefined4 *)(param_1 + 0x4c));
      if (iVar2 == 0) {
        return 0;
      }
      _printk(&DAT_00108e96,"qcedev_control_clocks");
      iVar2 = qce_disable_clk(*(undefined8 *)(param_1 + 0xe0));
      if (iVar2 == 0) {
        return 0;
      }
      puVar3 = &DAT_00109360;
      goto LAB_00107634;
    }
    break;
  case 2:
    iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x48),
                       *(undefined4 *)(param_1 + 0x4c));
    if (iVar2 != 0) {
LAB_00107620:
      puVar3 = &DAT_00108e96;
      goto LAB_00107634;
    }
    iVar2 = qce_enable_clk(*(undefined8 *)(param_1 + 0xe0));
    if (iVar2 == 0) {
      return 0;
    }
    _printk(&DAT_00108c60,"qcedev_control_clocks");
    iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x40),0,0);
    if (iVar2 == 0) {
      return 0;
    }
    goto LAB_001075fc;
  case 3:
    iVar2 = qce_disable_clk(*(undefined8 *)(param_1 + 0xe0));
    if (iVar2 != 0) {
      puVar3 = &DAT_001096c3;
      goto LAB_00107634;
    }
    iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x40),0,0);
    if (iVar2 == 0) {
      return 0;
    }
    _printk(&DAT_001098b1,"qcedev_control_clocks");
    iVar2 = qce_enable_clk(*(undefined8 *)(param_1 + 0xe0));
    if (iVar2 == 0) {
      return 0;
    }
    break;
  case 4:
    iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x40),0,0);
    if (iVar2 == 0) {
      iVar2 = qce_disable_clk(*(undefined8 *)(param_1 + 0xe0));
      if (iVar2 == 0) {
        return 0;
      }
      _printk(&DAT_001096c3,"qcedev_control_clocks");
      iVar2 = icc_set_bw(*(undefined8 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x48),
                         *(undefined4 *)(param_1 + 0x4c));
      if (iVar2 == 0) {
        return 0;
      }
      goto LAB_00107620;
    }
LAB_001075fc:
    puVar3 = &DAT_001098b1;
    goto LAB_00107634;
  default:
    return -2;
  }
  puVar3 = &DAT_00108c60;
LAB_00107634:
  _printk(puVar3,"qcedev_control_clocks");
  return iVar2;
}



//------------------------------------------------------------
// qcedev_parse_context_bank @ 00107a5c size=496
// signature: undefined qcedev_parse_context_bank(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

undefined8 qcedev_parse_context_bank(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  long lVar8;
  
  if (param_1 == 0) {
    _printk(&DAT_00108fc1,"qcedev_parse_context_bank");
    return 0xffffffea;
  }
  plVar1 = (long *)(param_1 + 0x10);
  if (*(long *)(param_1 + 0x70) == 0) {
    lVar8 = *(long *)(param_1 + 0x80);
    if (lVar8 == 0) {
      lVar8 = *plVar1;
    }
    _printk(&DAT_001090ab,"qcedev_parse_context_bank",lVar8);
    return 0xffffffea;
  }
  lVar8 = *(long *)(*(long *)(param_1 + 0x70) + 0x98);
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  plVar3 = (long *)devm_kmalloc(plVar1,0x38,0xdc0);
  if (plVar3 == (long *)0x0) {
    _printk(&DAT_00109b73,"qcedev_parse_context_bank");
    return 0xfffffff4;
  }
  *plVar3 = (long)plVar3;
  plVar3[1] = (long)plVar3;
  puVar7 = *(undefined8 **)(lVar8 + 0x148);
  uVar4 = __list_add_valid(plVar3,puVar7,lVar8 + 0x140);
  if ((uVar4 & 1) != 0) {
    *(long **)(lVar8 + 0x148) = plVar3;
    *plVar3 = lVar8 + 0x140;
    plVar3[1] = (long)puVar7;
    *puVar7 = plVar3;
  }
  of_property_read_string(uVar6,"label",plVar3 + 2);
  lVar8 = of_find_property(uVar6,"qcom,secure-context-bank",0);
  *(bool *)((long)plVar3 + 0x24) = lVar8 != 0;
  if (plVar1 == (long *)0x0) {
    _printk(&DAT_00109681,"qcedev_setup_context_bank");
    uVar6 = 0xffffffea;
LAB_00107bf8:
    _printk(&DAT_001098cc,"qcedev_parse_context_bank",uVar6);
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar8 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar8 + 8) = plVar2;
      *plVar2 = lVar8;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    devm_kfree(plVar1,plVar3);
  }
  else {
    puVar5 = *(undefined4 **)(param_1 + 0x2c8);
    plVar3[5] = (long)plVar1;
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)devm_kmalloc(plVar1,0x10,0xdc0);
      *(undefined4 **)(param_1 + 0x2c8) = puVar5;
      if (puVar5 == (undefined4 *)0x0) {
        uVar6 = 0xfffffff4;
        goto LAB_00107bf8;
      }
    }
    *puVar5 = 0xffffffff;
    if (*(long *)(param_1 + 0x2c8) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0;
      *(undefined8 *)(*(long *)(param_1 + 0x2c8) + 8) = 0xffffffffffffffff;
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// qcedev_mem_new_client @ 00107c50 size=84
// signature: undefined qcedev_mem_new_client(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * qcedev_mem_new_client(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 == 0) {
    puVar1 = (undefined4 *)kmalloc_trace(_mutex_unlock,0xdc0,4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
    }
  }
  else {
    _printk(&DAT_00109aa9,"qcedev_mem_new_client");
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



//------------------------------------------------------------
// qcedev_mem_delete_client @ 00107ca8 size=28
// signature: undefined qcedev_mem_delete_client(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

void qcedev_mem_delete_client(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// qcedev_check_and_map_buffer @ 00107cc8 size=1160
// signature: undefined qcedev_check_and_map_buffer(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcedev_check_and_map_buffer(long *param_1,int param_2,uint param_3,uint param_4,long *param_5)

{
  long *plVar1;
  long *plVar2;
  char cVar3;
  bool bVar4;
  byte bVar5;
  ulong uVar6;
  undefined *puVar7;
  long *plVar8;
  ulong uVar9;
  uint uVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  undefined8 *puVar14;
  long *plVar15;
  ulong uVar16;
  int *piVar17;
  ulong uVar18;
  
  if ((((param_3 < param_4) && (-1 < param_2)) && (param_1 != (long *)0x0)) &&
     (param_5 != (long *)0x0)) {
    if ((*param_1 != 0) && (piVar17 = *(int **)(*param_1 + 0x150), piVar17 != (int *)0x0)) {
      if (*piVar17 != 0) {
        uVar18 = 0xffffffff;
        goto LAB_00108108;
      }
      plVar1 = param_1 + 0x1b;
      uVar16 = (ulong)param_3;
      plVar2 = param_1 + 0x19;
      mutex_lock(plVar1);
      plVar11 = plVar2;
      do {
        plVar11 = (long *)*plVar11;
        if (plVar11 == plVar2) {
          mutex_unlock(plVar1);
          plVar11 = (long *)kmalloc_trace(___arch_copy_to_user,0xdc0,0x58);
          if (plVar11 == (long *)0x0) {
            _printk(&DAT_00109195,"qcedev_check_and_map_buffer");
            uVar18 = 0xfffffff4;
            goto LAB_00108100;
          }
          if (*piVar17 != 0) {
            _printk(&DAT_00109aa9,"qcedev_map_buffer");
            uVar18 = 0xffffffff;
            goto LAB_00107f88;
          }
          uVar6 = dma_buf_get(param_2);
          uVar18 = 0xffffffea;
          if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) goto LAB_00107f88;
          if (*(long *)(*param_1 + 0x140) == *param_1 + 0x140) {
            puVar7 = &DAT_00108f79;
            goto LAB_00107f70;
          }
          bVar5 = mem_buf_dma_buf_exclusive_owner(uVar6);
          puVar7 = &DAT_0010998d;
          plVar15 = (long *)(*param_1 + 0x140);
          goto LAB_00107e40;
        }
      } while ((int)plVar11[9] != param_2);
      *param_5 = plVar11[7];
      uVar18 = plVar11[8];
      plVar11 = plVar11 + 10;
      Hint_Prefetch(plVar11,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(plVar11,0x10);
        if (bVar4) {
          *(int *)plVar11 = (int)*plVar11 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      mutex_unlock(plVar1);
      if (uVar16 < uVar18) goto LAB_001080bc;
      _printk(&DAT_00108abb,"qcedev_check_and_map_buffer",uVar16,uVar18,param_2);
      plVar11 = (long *)0x0;
      goto LAB_001080fc;
    }
    puVar7 = &DAT_0010922c;
  }
  else {
    puVar7 = &DAT_00108b1e;
  }
  _printk(puVar7,"qcedev_check_and_map_buffer");
  uVar18 = 0xffffffea;
  goto LAB_00108108;
  while (*(byte *)((long)plVar15 + 0x24) != ((bVar5 ^ 0xff) & 1)) {
LAB_00107e40:
    plVar15 = (long *)*plVar15;
    if (plVar15 == (long *)(*param_1 + 0x140)) goto LAB_00107f70;
  }
  if (plVar15 == (long *)0x0) {
    puVar7 = &DAT_0010998d;
LAB_00107f70:
    _printk(puVar7,"ion_map_buffer");
    uVar18 = 0xfffffffb;
LAB_00107f80:
    dma_buf_put(uVar6);
LAB_00107f88:
    _printk(&DAT_00109001,"qcedev_map_buffer");
    _printk(&DAT_001093d4,"qcedev_check_and_map_buffer",param_2,uVar18 & 0xffffffff);
  }
  else {
    uVar18 = dma_buf_attach(uVar6,plVar15[5]);
    if ((uVar18 == 0) || (0xfffffffffffff000 < uVar18)) {
      _printk(&DAT_00108dc0,"ion_map_buffer");
      if (uVar18 == 0) {
        uVar18 = 0xfffffff4;
        goto LAB_00107f80;
      }
LAB_00108054:
      dma_buf_put(uVar6);
      if ((int)uVar18 != 0) goto LAB_00107f88;
      lVar12 = plVar11[7];
      uVar9 = plVar11[8];
    }
    else {
      *(ulong *)(uVar18 + 0x48) = *(ulong *)(uVar18 + 0x48) | 0x20000;
      plVar8 = (long *)dma_buf_map_attachment(uVar18,0);
      if ((plVar8 == (long *)0x0) || ((long *)0xfffffffffffff000 < plVar8)) {
        uVar10 = 0xfffffff4;
        if (plVar8 != (long *)0x0) {
          uVar10 = (uint)plVar8;
        }
        _printk(&DAT_00108de4,"ion_map_buffer");
LAB_0010803c:
        dma_buf_detach(uVar6,uVar18);
        uVar18 = (ulong)uVar10;
        goto LAB_00108054;
      }
      if (*plVar8 == 0) {
        puVar7 = &DAT_00109401;
LAB_0010801c:
        _printk(puVar7,"ion_map_buffer");
        dma_buf_unmap_attachment(uVar18,plVar8,0);
        uVar10 = 0xfffffff4;
        goto LAB_0010803c;
      }
      lVar12 = *(long *)(*plVar8 + 0x10);
      plVar11[7] = lVar12;
      uVar10 = *(uint *)(*plVar8 + 0x18);
      uVar9 = (ulong)uVar10;
      plVar11[8] = uVar9;
      if (uVar10 < param_4) {
        puVar7 = &DAT_00109d01;
        goto LAB_0010801c;
      }
      plVar11[2] = plVar15[5];
      lVar13 = plVar15[6];
      plVar11[5] = uVar18;
      plVar11[6] = uVar6;
      *(int *)(plVar11 + 9) = param_2;
      plVar11[3] = lVar13;
      plVar11[4] = (long)plVar8;
    }
    *param_5 = lVar12;
    plVar15 = plVar11 + 10;
    Hint_Prefetch(plVar15,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(plVar15,0x10);
      if (bVar4) {
        *(int *)plVar15 = (int)*plVar15 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar16 < uVar9) {
      mutex_lock(plVar1);
      puVar14 = (undefined8 *)param_1[0x1a];
      uVar18 = __list_add_valid(plVar11,puVar14,plVar2);
      if ((uVar18 & 1) != 0) {
        param_1[0x1a] = (long)plVar11;
        *plVar11 = (long)plVar2;
        plVar11[1] = (long)puVar14;
        *puVar14 = plVar11;
      }
      mutex_unlock(plVar1);
LAB_001080bc:
      uVar18 = 0;
      *param_5 = *param_5 + uVar16;
      goto LAB_00108108;
    }
    _printk(&DAT_00108abb,"qcedev_check_and_map_buffer",uVar16,uVar9,param_2);
    qcedev_unmap_buffer(param_1,piVar17,plVar11);
LAB_001080fc:
    uVar18 = 0xffffffde;
  }
LAB_00108100:
  kfree(plVar11);
LAB_00108108:
  return uVar18 & 0xffffffff;
}



//------------------------------------------------------------
// qcedev_unmap_buffer @ 00108168 size=136
// signature: undefined qcedev_unmap_buffer(void)
// callers: [qcedev_check_and_map_buffer]
//------------------------------------------------------------

void qcedev_unmap_buffer(long *param_1,int *param_2,long param_3)

{
  if (*param_2 == 0) {
    if (*(long *)(*param_1 + 0x140) != *param_1 + 0x140) {
      dma_buf_unmap_attachment(*(undefined8 *)(param_3 + 0x28),*(undefined8 *)(param_3 + 0x20),0);
      dma_buf_detach(*(undefined8 *)(param_3 + 0x30),*(undefined8 *)(param_3 + 0x28));
      dma_buf_put(*(undefined8 *)(param_3 + 0x30));
    }
  }
  else {
    _printk(&DAT_00109aa9,"qcedev_unmap_buffer");
    _printk(&DAT_001090ee,"qcedev_unmap_buffer");
  }
  return;
}



//------------------------------------------------------------
// qcedev_check_and_unmap_buffer @ 001081f4 size=424
// signature: undefined qcedev_check_and_unmap_buffer(void)
// callers: [qcedev_ioctl]
//------------------------------------------------------------

undefined8 qcedev_check_and_unmap_buffer(long *param_1,int param_2)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  char cVar4;
  bool bVar5;
  ulong uVar6;
  undefined *puVar7;
  long *plVar8;
  int *piVar9;
  
  if ((param_1 == (long *)0x0) || (param_2 < 0)) {
    puVar7 = &DAT_00108b1e;
  }
  else {
    if ((*param_1 != 0) && (piVar9 = *(int **)(*param_1 + 0x150), piVar9 != (int *)0x0)) {
      if (*piVar9 != 0) {
        return 0xffffffff;
      }
      plVar1 = param_1 + 0x1b;
      mutex_lock(plVar1);
      plVar8 = param_1 + 0x19;
      do {
        plVar8 = (long *)*plVar8;
        if (plVar8 == param_1 + 0x19) {
          mutex_unlock(plVar1);
          _printk(&DAT_00108d95,"qcedev_check_and_unmap_buffer",param_2);
          return 0xffffffea;
        }
      } while ((int)plVar8[9] != param_2);
      plVar3 = plVar8 + 10;
      Hint_Prefetch(plVar3,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(plVar3,0x10);
        if (bVar5) {
          *(int *)plVar3 = (int)*plVar3 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if ((int)plVar8[10] == 0) {
        if (*piVar9 == 0) {
          if (*(long *)(*param_1 + 0x140) != *param_1 + 0x140) {
            dma_buf_unmap_attachment(plVar8[5],plVar8[4],0);
            dma_buf_detach(plVar8[6],plVar8[5]);
            dma_buf_put(plVar8[6]);
          }
        }
        else {
          _printk(&DAT_00109aa9,"qcedev_unmap_buffer");
          _printk(&DAT_001090ee,"qcedev_unmap_buffer");
        }
        uVar6 = __list_del_entry_valid(plVar8);
        if ((uVar6 & 1) != 0) {
          lVar2 = *plVar8;
          plVar3 = (long *)plVar8[1];
          *(long **)(lVar2 + 8) = plVar3;
          *plVar3 = lVar2;
        }
        *plVar8 = -0x2152ffffffffff00;
        plVar8[1] = -0x2152fffffffffede;
        kfree(plVar8);
      }
      mutex_unlock(plVar1);
      return 0;
    }
    puVar7 = &DAT_0010922c;
  }
  _printk(puVar7,"qcedev_check_and_unmap_buffer");
  return 0xffffffea;
}



//------------------------------------------------------------
// qcedev_unmap_all_buffers @ 001083b4 size=364
// signature: undefined qcedev_unmap_all_buffers(void)
// callers: [qcedev_release]
//------------------------------------------------------------

undefined8 qcedev_unmap_all_buffers(long *param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined *puVar4;
  long *plVar5;
  int *piVar6;
  long *plVar7;
  
  if (param_1 == (long *)0x0) {
    puVar4 = &DAT_00108b1e;
  }
  else {
    if ((*param_1 != 0) && (piVar6 = *(int **)(*param_1 + 0x150), piVar6 != (int *)0x0)) {
      if (*piVar6 != 0) {
        return 0xffffffff;
      }
      mutex_lock(param_1 + 0x1b);
      plVar7 = param_1 + 0x19;
      plVar5 = (long *)*plVar7;
      while (plVar5 != plVar7) {
        if (plVar5 != (long *)0x0) {
          if (*piVar6 == 0) {
            if (*(long *)(*param_1 + 0x140) != *param_1 + 0x140) {
              dma_buf_unmap_attachment(plVar5[5],plVar5[4],0);
              dma_buf_detach(plVar5[6],plVar5[5]);
              dma_buf_put(plVar5[6]);
            }
          }
          else {
            _printk(&DAT_00109aa9,"qcedev_unmap_buffer");
            _printk(&DAT_001090ee,"qcedev_unmap_buffer");
          }
        }
        uVar3 = __list_del_entry_valid(plVar5);
        if ((uVar3 & 1) != 0) {
          lVar1 = *plVar5;
          plVar2 = (long *)plVar5[1];
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        *plVar5 = -0x2152ffffffffff00;
        plVar5[1] = -0x2152fffffffffede;
        kfree(plVar5);
        plVar5 = (long *)*plVar7;
      }
      mutex_unlock(param_1 + 0x1b);
      return 0;
    }
    puVar4 = &DAT_0010922c;
  }
  _printk(puVar4,"qcedev_unmap_all_buffers");
  return 0xffffffea;
}



//------------------------------------------------------------
// __tasklet_schedule @ 0010d008 size=1
// signature: undefined __tasklet_schedule(void)
// callers: [qcedev_cipher_req_cb, qcedev_sha_req_cb, qcedev_offload_cipher_req_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tasklet_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010d010 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcedev_sha_update, qcedev_ioctl, qcedev_vbuf_ablk_cipher, qcedev_cipher_req_cb, qcedev_hash_final, qcedev_sha_update_max_xfer, qcedev_offload_cipher_req_cb, qcedev_sha_final, qcedev_hash_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010d018 size=1
// signature: undefined __warn_printk(void)
// callers: [qcedev_ioctl, qcedev_cipher_req_cb, qcedev_sha_update_max_xfer, qcedev_offload_cipher_req_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010d028 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcedev_check_and_map_buffer, qcedev_sha_update, qcedev_ioctl, qcedev_mem_new_client, qcedev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010d030 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcedev_ioctl, qcedev_hash_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0010d040 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [qcedev_ioctl, qcedev_sha_update_max_xfer, qcedev_hash_init, qcedev_vbuf_ablk_cipher_max_xfer, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010d048 size=1
// signature: undefined mutex_lock(void)
// callers: [qcedev_check_and_map_buffer, qcedev_unmap_all_buffers, qcedev_ce_high_bw_req, qcedev_ioctl, qcedev_suspend, qcedev_remove, qcedev_resume, qcedev_release, qcedev_check_and_unmap_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010d050 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcedev_check_and_map_buffer, qcedev_unmap_all_buffers, qcedev_ce_high_bw_req, qcedev_ioctl, qcedev_suspend, qcedev_remove, qcedev_resume, qcedev_release, qcedev_check_and_unmap_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0010d058 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [qcedev_ioctl, qcedev_vbuf_ablk_cipher_max_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010d060 size=1
// signature: undefined _printk(void)
// callers: [qcedev_check_sha_params, qcedev_sha_update, qcedev_ce_high_bw_req, qcedev_ioctl, qcedev_parse_context_bank, qcedev_check_cipher_params, qcedev_smmu_ablk_offload_cipher, qcedev_suspend, submit_req, qcedev_mem_new_client, qcedev_check_offload_cipher_params, qcedev_open, qcedev_check_and_map_buffer, qcedev_unmap_all_buffers, qcedev_unmap_buffer, qcedev_probe, qcedev_remove, qcedev_resume, qcedev_release, qcedev_check_and_unmap_buffer, qcedev_sha_final, qcedev_control_clocks, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010d068 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcedev_sha_update, qcedev_ioctl, qcedev_vbuf_ablk_cipher, qcedev_hash_final, qcedev_sha_update_max_xfer, qcedev_sha_final, qcedev_hash_init, qcedev_vbuf_ablk_cipher_max_xfer, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010d070 size=1
// signature: undefined kfree(void)
// callers: [qcedev_check_and_map_buffer, qcedev_sha_update, qcedev_unmap_all_buffers, qcedev_ioctl, qcedev_vbuf_ablk_cipher, qcedev_hash_final, qcedev_sha_update_max_xfer, qcedev_check_and_unmap_buffer, qcedev_sha_final, qcedev_mem_delete_client, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010d078 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcedev_sha_update, qcedev_ioctl, qcedev_vbuf_ablk_cipher, qcedev_smmu_ablk_offload_cipher, qcedev_probe, qcedev_hash_final, init_module, submit_req, qcedev_sha_final, qcedev_hash_init, qcedev_vbuf_ablk_cipher_max_xfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010d080 size=1
// signature: undefined fortify_panic(void)
// callers: [qcedev_ioctl, qcedev_hash_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 0010d090 size=1
// signature: undefined kmalloc_large(void)
// callers: [qcedev_vbuf_ablk_cipher]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 0010d098 size=1
// signature: undefined kmemdup(void)
// callers: [qcedev_vbuf_ablk_cipher]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 0010d0a0 size=1
// signature: undefined sg_init_table(void)
// callers: [qcedev_smmu_ablk_offload_cipher]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0010d0a8 size=1
// signature: undefined __check_object_size(void)
// callers: [qcedev_sha_update_max_xfer, qcedev_hash_init, qcedev_vbuf_ablk_cipher_max_xfer, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010d0b0 size=1
// signature: undefined __kmalloc(void)
// callers: [qcedev_hash_final, qcedev_sha_update_max_xfer, qcedev_sha_final, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_one @ 0010d0b8 size=1
// signature: undefined sg_init_one(void)
// callers: [qcedev_hash_final, qcedev_sha_update_max_xfer, qcedev_sha_final, qcedev_vbuf_ablk_cipher_max_xfer, qcedev_hash_cmac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010d0c0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010d0c8 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0010d0d0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0010d0d8 size=1
// signature: undefined debugfs_remove(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010d0e0 size=1
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
// platform_driver_unregister @ 0010d0e8 size=1
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
// __init_waitqueue_head @ 0010d0f0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010d0f8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [req_done, submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010d100 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcedev_check_and_map_buffer, qcedev_parse_context_bank, submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010d108 size=1
// signature: undefined init_wait_entry(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010d110 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 0010d118 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010d120 size=1
// signature: undefined schedule_timeout(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 0010d128 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010d130 size=1
// signature: undefined finish_wait(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_ablk_cipher_req @ 0010d138 size=1
// signature: undefined qce_ablk_cipher_req(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_ablk_cipher_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_process_sha_req @ 0010d140 size=1
// signature: undefined qce_process_sha_req(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_process_sha_req(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010d148 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcedev_unmap_all_buffers, qcedev_parse_context_bank, req_done, submit_req, qcedev_check_and_unmap_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010d150 size=1
// signature: undefined __wake_up(void)
// callers: [req_done, submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010d158 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [req_done, submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0010d160 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010d168 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_get_crypto_status @ 0010d170 size=1
// signature: undefined qce_get_crypto_status(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_get_crypto_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_manage_timeout @ 0010d178 size=1
// signature: undefined qce_manage_timeout(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_manage_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010d180 size=1
// signature: undefined usleep_range_state(void)
// callers: [submit_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010d188 size=1
// signature: undefined complete(void)
// callers: [req_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010d190 size=1
// signature: undefined scnprintf(void)
// callers: [_debug_stats_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 0010d198 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [_debug_stats_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 0010d1a0 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 0010d1a8 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0010d1b0 size=1
// signature: undefined __class_create(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0010d1b8 size=1
// signature: undefined device_create(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 0010d1c0 size=1
// signature: undefined cdev_init(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 0010d1c8 size=1
// signature: undefined cdev_add(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_init @ 0010d1d0 size=1
// signature: undefined tasklet_init(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 0010d1d8 size=1
// signature: undefined of_icc_get(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010d1e0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0010d1e8 size=1
// signature: undefined icc_set_bw(void)
// callers: [qcedev_probe, qcedev_control_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_open @ 0010d1f0 size=1
// signature: undefined qce_open(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_set_irqs @ 0010d1f8 size=1
// signature: undefined qce_set_irqs(void)
// callers: [qcedev_ce_high_bw_req, qcedev_probe, qcedev_suspend, qcedev_remove, qcedev_resume, qcedev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_set_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_hw_support @ 0010d200 size=1
// signature: undefined qce_hw_support(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_hw_support(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 0010d208 size=1
// signature: undefined of_platform_populate(void)
// callers: [qcedev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_close @ 0010d210 size=1
// signature: undefined qce_close(void)
// callers: [qcedev_probe, qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 0010d218 size=1
// signature: undefined icc_put(void)
// callers: [qcedev_probe, qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 0010d220 size=1
// signature: undefined cdev_del(void)
// callers: [qcedev_probe, qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 0010d228 size=1
// signature: undefined device_destroy(void)
// callers: [qcedev_probe, qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0010d230 size=1
// signature: undefined class_destroy(void)
// callers: [qcedev_probe, qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0010d238 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [qcedev_probe, qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_kill @ 0010d240 size=1
// signature: undefined tasklet_kill(void)
// callers: [qcedev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_kill(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010d248 size=1
// signature: undefined __mutex_init(void)
// callers: [qcedev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_sensitive @ 0010d250 size=1
// signature: undefined kfree_sensitive(void)
// callers: [qcedev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_enable_clk @ 0010d258 size=1
// signature: undefined qce_enable_clk(void)
// callers: [qcedev_control_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_enable_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qce_disable_clk @ 0010d260 size=1
// signature: undefined qce_disable_clk(void)
// callers: [qcedev_control_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qce_disable_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010d270 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcedev_parse_context_bank]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010d278 size=1
// signature: undefined of_property_read_string(void)
// callers: [qcedev_parse_context_bank]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010d280 size=1
// signature: undefined of_find_property(void)
// callers: [qcedev_parse_context_bank]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0010d288 size=1
// signature: undefined devm_kfree(void)
// callers: [qcedev_parse_context_bank]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get @ 0010d290 size=1
// signature: undefined dma_buf_get(void)
// callers: [qcedev_check_and_map_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_exclusive_owner @ 0010d298 size=1
// signature: undefined mem_buf_dma_buf_exclusive_owner(void)
// callers: [qcedev_check_and_map_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_exclusive_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_attach @ 0010d2a0 size=1
// signature: undefined dma_buf_attach(void)
// callers: [qcedev_check_and_map_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_map_attachment @ 0010d2a8 size=1
// signature: undefined dma_buf_map_attachment(void)
// callers: [qcedev_check_and_map_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_map_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 0010d2b0 size=1
// signature: undefined dma_buf_put(void)
// callers: [qcedev_check_and_map_buffer, qcedev_unmap_all_buffers, qcedev_unmap_buffer, qcedev_check_and_unmap_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_unmap_attachment @ 0010d2b8 size=1
// signature: undefined dma_buf_unmap_attachment(void)
// callers: [qcedev_check_and_map_buffer, qcedev_unmap_all_buffers, qcedev_unmap_buffer, qcedev_check_and_unmap_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_detach @ 0010d2c0 size=1
// signature: undefined dma_buf_detach(void)
// callers: [qcedev_check_and_map_buffer, qcedev_unmap_all_buffers, qcedev_unmap_buffer, qcedev_check_and_unmap_buffer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



