// Decompiled by Ghidra 12.2
// Program: rdbg.ko
// Image base: 00100000

//------------------------------------------------------------
// rdbg_probe @ 001003a4 size=588
// signature: undefined rdbg_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001005ec) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong rdbg_probe(long param_1)

{
  ulong *puVar1;
  long lVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char *param0;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  param0 = (char *)kmalloc_trace(_qcom_smem_state_get,0xdc0,0x20);
  if (param0 == (char *)0x0) {
LAB_00100594:
    uVar8 = 0xfffffff4;
  }
  else {
    if (0 < DAT_00101c64) {
      lVar10 = 0;
      lVar9 = 0;
      lVar11 = 0x50;
      do {
        if (lVar10 == 0x180) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1005ec);
          (*pcVar4)();
        }
        lVar12 = *(long *)((long)&proc_info + lVar10);
        if (lVar12 != 0) {
          iVar6 = snprintf(param0,0x20,"%s%d-out","qcom,smp2p-interrupt-rdbg-",(int)lVar9);
          if (0 < iVar6) {
            iVar6 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),param0);
            lVar2 = DAT_00101c68;
            if (iVar6 != 0) {
              if (DAT_00101c68 + lVar11 == 0x10) {
                uVar8 = 0xffffffea;
LAB_001005cc:
                _printk(&DAT_0010201f,"rdbg_probe",lVar12);
                goto LAB_00100598;
              }
              lVar7 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,smem-states",0);
              if (lVar7 != 0) {
                puVar1 = (ulong *)(lVar2 + lVar11);
                uVar8 = qcom_smem_state_get(param_1 + 0x10,"rdbg-smp2p-out",puVar1 + -1);
                *puVar1 = uVar8;
                if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
                  _printk(&DAT_0010227f);
                  uVar8 = *puVar1;
                  if ((int)uVar8 != 0) goto LAB_001005cc;
                }
              }
            }
            iVar6 = snprintf(param0,0x20,"%s%d-in","qcom,smp2p-interrupt-rdbg-",(int)lVar9);
            if (0 < iVar6) {
              iVar6 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),param0);
              if (iVar6 != 0) {
                lVar2 = DAT_00101c68 + lVar11;
                puVar3 = (undefined4 *)(lVar2 + -0x28);
                if (puVar3 == (undefined4 *)0x0) {
                  _printk(&DAT_001021cc,lVar12);
                }
                else {
                  uVar5 = of_irq_get_byname(*(undefined8 *)(param_1 + 0x2f8),"rdbg-smp2p-in");
                  *puVar3 = uVar5;
                  *(undefined4 *)(lVar2 + -0x24) = uVar5;
                }
              }
              goto LAB_00100448;
            }
          }
          _printk(&DAT_00102242);
          goto LAB_00100594;
        }
LAB_00100448:
        lVar9 = lVar9 + 1;
        lVar10 = lVar10 + 0x18;
        lVar11 = lVar11 + 0x1c8;
      } while (lVar9 < DAT_00101c64);
    }
    uVar8 = 0;
  }
LAB_00100598:
  kfree(param0);
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// rdbg_read @ 001005f4 size=988
// signature: undefined rdbg_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long rdbg_read(long param_1,ulong param_2,ulong param_3)

{
  ushort *puVar1;
  ulong uVar2;
  long lVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  undefined8 uVar10;
  char *pcVar11;
  ulong uVar12;
  undefined8 *puVar13;
  long lVar14;
  ulong uVar15;
  undefined8 *puVar16;
  
  puVar16 = *(undefined8 **)(param_1 + 0xd8);
  if (puVar16 == (undefined8 *)0x0) {
    _printk(&DAT_00102094);
    iVar9 = -0x16;
    goto LAB_0010092c;
  }
  iVar9 = wait_for_completion_interruptible(puVar16 + 1);
  if (iVar9 != 0) {
    _dev_err(*puVar16,"%s: Error in wait\n","rdbg_read");
    goto LAB_0010092c;
  }
  if (((*(int *)(puVar16 + 0x22) == 2) && (*(int *)puVar16[0x1a] == -0xff00ff)) &&
     (*(char *)puVar16[0x19] == '\x01')) {
    iVar9 = ((int *)puVar16[0x1a])[1];
    if (*(int *)(puVar16[0x1b] + 4) != iVar9) {
      *(int *)(puVar16[0x1b] + 4) = iVar9;
      if (*(int *)(puVar16 + 0x1d) != 0) {
        uVar12 = 0;
        lVar14 = 0x10;
        do {
          uVar12 = uVar12 + 1;
          *(undefined2 *)(puVar16[0x1b] + lVar14) = 0xffff;
          lVar14 = lVar14 + 4;
        } while (uVar12 < *(uint *)(puVar16 + 0x1d));
      }
      *(undefined4 *)(puVar16[0x1b] + 8) = 0;
      *(undefined4 *)(puVar16[0x1b] + 0xc) = 0;
      if (*(int *)(puVar16 + 0x18) == 1) {
        mutex_lock(puVar16[0x14]);
        if (*(int *)(puVar16[0x10] + 4) != iVar9) {
          *(int *)(puVar16[0x10] + 4) = iVar9;
          if (*(int *)(puVar16 + 0x13) != 0) {
            uVar12 = 0;
            lVar14 = 0x10;
            do {
              uVar12 = uVar12 + 1;
              *(undefined2 *)(puVar16[0x10] + lVar14) = 0xffff;
              lVar14 = lVar14 + 4;
            } while (uVar12 < *(uint *)(puVar16 + 0x13));
          }
          if (puVar16[0x17] != 0) {
            memset((void *)puVar16[0x17],0,(ulong)(*(int *)((long)puVar16 + 0xb4) + 1));
            *(undefined4 *)(puVar16 + 0x16) = 0;
          }
          *(undefined4 *)(puVar16[0x10] + 8) = 0;
          *(undefined4 *)(puVar16[0x10] + 0xc) = 0;
        }
        mutex_unlock(puVar16[0x14]);
      }
    }
  }
  piVar4 = (int *)puVar16[0x1a];
  if ((*(char *)puVar16[0x19] == '\x01') || (*piVar4 == -0xff00ff)) {
    uVar5 = *(uint *)(puVar16[0x1b] + 8);
    if (uVar5 == piVar4[2]) goto LAB_00100948;
    uVar6 = *(uint *)(puVar16 + 0x1d);
    puVar1 = (ushort *)(piVar4 + (ulong)uVar5 + 4);
    if (uVar6 <= *puVar1) goto LAB_00100948;
    uVar7 = 0;
    if (uVar6 != 0) {
      uVar7 = (uVar5 + 1) / uVar6;
    }
    *(uint *)(puVar16[0x1b] + 8) = (uVar5 + 1) - uVar7 * uVar6;
    DataSynchronizationBarrier(3,1,0);
    lVar14 = puVar16[0x1c] + (ulong)*puVar1 * 0x80;
    uVar2 = (ulong)puVar1[1] << 7;
    if (param_3 <= (ulong)puVar1[1] << 7) {
      uVar2 = param_3;
    }
    __check_object_size(lVar14,uVar2,1);
    puVar13 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar13 + 0x46) >> 5 & 1) != 0) ||
       (uVar15 = param_2, ((uint)*puVar13 >> 0x1a & 1) != 0)) {
      uVar15 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar12 = uVar2;
    if (uVar15 <= 0x8000000000 - uVar2) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar12 = daif;
        if ((uVar12 & 0x80) == 0) {
          uVar15 = daif;
          daif = uVar15 | 0xc0;
        }
        puVar13 = (undefined8 *)puVar13[1];
        uVar15 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar13 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar13;
        InstructionSynchronizationBarrier();
        daif = uVar12;
      }
      uVar12 = __arch_copy_to_user(puVar13,param_2 & 0xff7fffffffffffff,lVar14,uVar2);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar8 = daif;
          daif = uVar8 | 0xc0;
        }
        uVar8 = ttbr1_el1;
        ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar8 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
    }
    if ((int)uVar12 == 0) {
      if (puVar16[0x1e] != 0) {
        mutex_lock();
      }
      if ((*(char *)puVar16[0x19] == '\x01') || (*(int *)puVar16[0x1a] == -0xff00ff)) {
        lVar14 = lVar14 - puVar16[0x1c];
        lVar3 = lVar14 + 0x7f;
        if (-1 < lVar14) {
          lVar3 = lVar14;
        }
        if ((uint)(lVar3 >> 7) < *(uint *)(puVar16 + 0x1d)) {
          lVar14 = puVar16[0x1b] + (ulong)*(uint *)(puVar16[0x1b] + 0xc) * 4;
          *(short *)(lVar14 + 0x10) = (short)(lVar3 >> 7);
          *(undefined2 *)(lVar14 + 0x12) = 0;
          uVar6 = *(uint *)(puVar16 + 0x1d);
          uVar5 = *(int *)(puVar16[0x1b] + 0xc) + 1;
          uVar7 = 0;
          if (uVar6 != 0) {
            uVar7 = uVar5 / uVar6;
          }
          *(uint *)(puVar16[0x1b] + 0xc) = uVar5 - uVar7 * uVar6;
        }
      }
      if (puVar16[0x1e] != 0) {
        mutex_unlock();
      }
      iVar9 = (int)uVar2;
      goto LAB_0010092c;
    }
    uVar10 = *puVar16;
    pcVar11 = "%s: Error in copy_to_user(). Err code = %d\n";
  }
  else {
LAB_00100948:
    uVar10 = *puVar16;
    pcVar11 = "%s: Error in smq_recv(). Err code = %d\n";
    uVar12 = 0;
  }
  _dev_err(uVar10,pcVar11,"rdbg_read",uVar12);
  iVar9 = -0x3d;
LAB_0010092c:
  return (long)iVar9;
}



//------------------------------------------------------------
// rdbg_write @ 001009ec size=1128
// signature: undefined rdbg_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t rdbg_write(long param_1,ulong param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  undefined8 *puVar6;
  ulong uVar7;
  code *pcVar8;
  bool bVar9;
  size_t __n;
  long lVar10;
  uint uVar11;
  uint uVar12;
  long lVar13;
  ulong uVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  ulong uVar18;
  size_t sVar19;
  uint uVar20;
  bool bVar21;
  long lVar22;
  uint uVar23;
  
  lVar22 = *(long *)(param_1 + 0xd8);
  if (lVar22 == 0) {
    _printk(&DAT_00102094);
    sVar19 = 0xffffffffffffffea;
  }
  else {
    uVar1 = param_3 + 0x7f;
    sVar19 = (size_t)param_3;
    uVar3 = (int)uVar1 >> 7;
    puVar6 = (undefined8 *)sp_el0;
    uVar23 = 0;
    do {
      mutex_lock(*(undefined8 *)(lVar22 + 0xa0));
      piVar15 = *(int **)(lVar22 + 0x88);
      if (((*piVar15 == -0xff00fe) && (*(char *)(*(long *)(lVar22 + 0x78) + 1) == '\x01')) &&
         (lVar13 = *(long *)(lVar22 + 0x80), *(int *)(lVar13 + 4) == piVar15[1])) {
        while( true ) {
          uVar12 = *(uint *)(lVar13 + 0xc);
          if (uVar12 == piVar15[3]) break;
          uVar2 = *(uint *)(lVar22 + 0x98);
          if (uVar2 <= *(ushort *)(piVar15 + (ulong)uVar12 + 4)) goto LAB_00100ad0;
          uVar16 = 0;
          if (uVar2 != 0) {
            uVar16 = (uVar12 + 1) / uVar2;
          }
          *(uint *)(lVar13 + 0xc) = (uVar12 + 1) - uVar16 * uVar2;
          uVar14 = (ulong)*(ushort *)(piVar15 + (ulong)uVar12 + 4);
          bVar4 = *(byte *)(*(long *)(lVar22 + 0xb8) + uVar14);
          uVar12 = (uint)bVar4;
          if (bVar4 != 0) {
            do {
              uVar12 = uVar12 - 1;
              *(undefined1 *)(*(long *)(lVar22 + 0xb8) + uVar14) = 0;
              uVar14 = uVar14 + 1;
            } while (uVar12 != 0);
          }
          DataSynchronizationBarrier(3,1,0);
          lVar13 = *(long *)(lVar22 + 0x80);
          piVar15 = *(int **)(lVar22 + 0x88);
        }
      }
      uVar12 = *(uint *)(lVar22 + 0xb0);
      uVar14 = (ulong)uVar12;
      if (uVar3 == 1) {
        do {
          if (*(char *)(*(long *)(lVar22 + 0xb8) + uVar14) == '\0') {
            *(undefined1 *)(*(long *)(lVar22 + 0xb8) + uVar14) = 1;
            uVar2 = *(uint *)(lVar22 + 0xb4);
            uVar12 = *(int *)(lVar22 + 0xb0) + 1;
            uVar16 = 0;
            if (uVar2 != 0) {
              uVar16 = uVar12 / uVar2;
            }
            iVar5 = uVar12 - uVar16 * uVar2;
            goto LAB_00100c00;
          }
          uVar16 = *(uint *)(lVar22 + 0xb4);
          uVar2 = (int)uVar14 + 1;
          uVar11 = 0;
          if (uVar16 != 0) {
            uVar11 = uVar2 / uVar16;
          }
          uVar2 = uVar2 - uVar11 * uVar16;
          uVar14 = (ulong)uVar2;
          *(uint *)(lVar22 + 0xb0) = uVar2;
        } while (uVar12 != uVar2);
      }
      else {
        uVar2 = *(uint *)(lVar22 + 0xb4);
        uVar18 = uVar14;
        uVar12 = uVar2;
        uVar16 = 0;
        do {
          uVar11 = (uint)uVar14;
          uVar17 = (uint)*(byte *)(*(long *)(lVar22 + 0xb8) + uVar14);
          if (uVar17 == 0) {
            uVar17 = uVar11;
            if (uVar12 <= uVar11) {
              uVar17 = (uint)uVar18;
            }
            uVar18 = (ulong)uVar17;
            uVar17 = uVar12;
            if (uVar11 <= uVar12) {
              uVar17 = uVar11;
            }
            uVar14 = (ulong)uVar17;
            uVar20 = 1;
            if (uVar12 <= uVar11) {
              uVar20 = uVar16 + 1;
            }
            if (uVar20 != uVar3) goto LAB_00100b64;
            if (uVar1 < 0x80) {
              uVar12 = 0;
            }
            else {
              if (uVar11 <= uVar12) {
                uVar12 = uVar11;
              }
              uVar18 = (ulong)uVar3;
              do {
                *(char *)(*(long *)(lVar22 + 0xb8) + (ulong)uVar12) = (char)uVar18;
                uVar18 = uVar18 - 1;
                uVar12 = uVar12 + 1;
              } while (uVar18 != 0);
              uVar11 = *(uint *)(lVar22 + 0xb0);
              uVar12 = (uint)*(byte *)(*(long *)(lVar22 + 0xb8) + (ulong)uVar11);
            }
            iVar5 = uVar11 + uVar12 + -1;
LAB_00100c00:
            *(int *)(lVar22 + 0xb0) = iVar5;
            lVar13 = *(long *)(lVar22 + 0x90) + (ulong)(uint)((int)uVar14 << 7);
            if (param_3 < 0) {
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(0x800,0x100d5c);
              (*pcVar8)();
            }
            __check_object_size(lVar13,sVar19,0);
            if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
               (uVar18 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
              uVar18 = param_2 & (long)(param_2 << 8) >> 8;
            }
            __n = sVar19;
            if (uVar18 <= 0x8000000000 - sVar19) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar18 = daif;
                if ((uVar18 & 0x80) == 0) {
                  uVar7 = daif;
                  daif = uVar7 | 0xc0;
                }
                uVar7 = ttbr1_el1;
                ttbr1_el1 = puVar6[1] & 0xffff000000000000 | uVar7 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar6[1];
                InstructionSynchronizationBarrier();
                daif = uVar18;
              }
              __n = __arch_copy_from_user(lVar13,param_2 & 0xff7fffffffffffff,sVar19);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar18 = daif;
                if ((uVar18 & 0x80) == 0) {
                  uVar7 = daif;
                  daif = uVar7 | 0xc0;
                }
                uVar7 = ttbr1_el1;
                ttbr0_el1 = (uVar7 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar7 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar18;
              }
            }
            if ((__n != 0) && (memset((void *)(lVar13 + (sVar19 - __n)),0,__n), (int)__n != 0)) {
              if (lVar13 == 0) {
                bVar21 = false;
                goto LAB_00100d34;
              }
              bVar4 = *(byte *)(*(long *)(lVar22 + 0xb8) + uVar14);
              uVar12 = (uint)bVar4;
              if (bVar4 != 0) {
                do {
                  bVar21 = false;
                  uVar12 = uVar12 - 1;
                  *(undefined1 *)(*(long *)(lVar22 + 0xb8) + uVar14) = 0;
                  uVar14 = (ulong)((int)uVar14 + 1);
                } while (uVar12 != 0);
                goto LAB_00100d34;
              }
              break;
            }
            bVar21 = true;
            *(short *)(*(long *)(lVar22 + 0x80) + (ulong)*(uint *)(*(long *)(lVar22 + 0x80) + 8) * 4
                      + 0x10) = (short)uVar14;
            *(short *)(*(long *)(lVar22 + 0x80) + (ulong)*(uint *)(*(long *)(lVar22 + 0x80) + 8) * 4
                      + 0x12) = (short)(uVar1 >> 7);
            uVar2 = *(uint *)(lVar22 + 0x98);
            uVar12 = *(int *)(*(long *)(lVar22 + 0x80) + 8) + 1;
            uVar16 = 0;
            if (uVar2 != 0) {
              uVar16 = uVar12 / uVar2;
            }
            *(uint *)(*(long *)(lVar22 + 0x80) + 8) = uVar12 - uVar16 * uVar2;
            goto LAB_00100d34;
          }
          uVar20 = 0;
          uVar11 = (uVar11 + uVar17) - 1;
          uVar17 = uVar2;
LAB_00100b64:
          uVar12 = uVar17;
          uVar16 = 0;
          if (uVar2 != 0) {
            uVar16 = (uVar11 + 1) / uVar2;
          }
          uVar11 = (uVar11 + 1) - uVar16 * uVar2;
          uVar14 = (ulong)uVar11;
          *(uint *)(lVar22 + 0xb0) = uVar11;
          uVar16 = uVar20;
        } while ((uint)uVar18 != uVar11);
      }
LAB_00100ad0:
      bVar21 = false;
LAB_00100d34:
      mutex_unlock(*(undefined8 *)(lVar22 + 0xa0));
    } while ((!bVar21) && (bVar9 = uVar23 < 0x14, uVar23 = uVar23 + 1, bVar9));
    if (bVar21) {
      uVar3 = *(uint *)(lVar22 + 0x5c);
      lVar13 = lVar22 + (ulong)uVar3 * 4;
      lVar10 = 1L << ((ulong)(*(int *)(lVar22 + 0x48) + uVar3) & 0x3f);
      uVar1 = *(uint *)(lVar13 + 0x148) ^ (uint)lVar10;
      qcom_smem_state_update_bits(*(undefined8 *)(lVar22 + 0x50),lVar10,uVar1);
      *(uint *)(lVar13 + 0x148) = uVar1;
      *(uint *)(lVar22 + 0x5c) = uVar3 + 1 & 0x1f;
    }
    else {
      _printk(&DAT_001021ef);
      sVar19 = 0xffffffffffffffba;
    }
  }
  return sVar19;
}



//------------------------------------------------------------
// rdbg_open @ 00100e74 size=1828
// signature: undefined rdbg_open(void)
// callers: []
//------------------------------------------------------------

int rdbg_open(long param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  void *__s;
  char *pcVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  int *piVar8;
  uint *puVar9;
  long lVar10;
  uint uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong *puVar14;
  undefined8 *puVar15;
  long lVar16;
  long lVar17;
  long *plVar18;
  int *piVar19;
  ulong *puVar20;
  undefined1 *puVar21;
  
  lVar10 = DAT_00101c68;
  if ((param_1 == 0) || (DAT_00101c68 == 0)) {
    _printk(&DAT_00102181);
    return -0x13;
  }
  uVar12 = (ulong)*(uint *)(param_1 + 0x4c) & 0xfffff;
  puVar15 = (undefined8 *)(DAT_00101c68 + uVar12 * 0x1c8);
  if (*(char *)(puVar15 + 0xc) != '\0') {
    _dev_err(*puVar15,"%s: Device already opened\n","rdbg_open");
    return -0x11;
  }
  uVar11 = (uint)uVar12;
  if (0xf < uVar11) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101598);
    (*pcVar2)();
  }
  uVar13 = uVar12 * 0x18;
  if (uVar13 < 0x171) {
    uVar5 = *(ulong *)(&DAT_001027a8 + uVar12 * 0x18);
    puVar14 = (ulong *)(DAT_00101c68 + uVar12 * 0x1c8 + 0x70);
    *puVar14 = uVar5;
    if (uVar5 == 0) {
      _dev_err(*puVar15,"%s: smem not initialized\n","rdbg_open");
      return -0xc;
    }
    if (uVar12 * 0x18 < 0x179) {
      uVar1 = *(undefined4 *)(&DAT_001027a0 + uVar12 * 0x18);
      uVar5 = qcom_smem_get(0xffffffff,uVar1,puVar14);
      puVar20 = (ulong *)(lVar10 + uVar12 * 0x1c8 + 0x68);
      *puVar20 = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        _printk(&DAT_00101dec);
        uVar5 = *puVar20;
        if (uVar5 == 0xfffffffffffffffe) {
          uVar5 = qcom_smem_get(uVar12,uVar1,puVar14);
          *puVar20 = uVar5;
        }
      }
      if (uVar5 == 0) {
        _dev_err(*puVar15,"%s: Could not allocate smem memory\n","rdbg_open");
        _printk(&DAT_00101d68);
        return -0xc;
      }
      uVar6 = uVar5 + 9 & 0xfffffffffffffff8;
      uVar5 = ((long)(((int)uVar5 - (int)uVar6) + (int)(*puVar14 >> 1)) - 0x20U) / 0x88;
      iVar3 = (int)uVar5;
      if (0 < iVar3) {
        if (*(int *)((uVar5 & 0xffffffff) * 4 + uVar6 + (long)(iVar3 << 7) + 0x10) == -0xff00fe) {
          lVar16 = lVar10 + uVar12 * 0x1c8;
          *(undefined4 *)(lVar16 + 8) = 0;
          __init_swait_queue_head(lVar16 + 0x10,"&x->wait",&init_completion___key);
          if ((0x180 < uVar13) || (uVar11 == 0x10)) goto LAB_00101590;
          iVar3 = request_threaded_irq
                            (*(undefined4 *)(lVar16 + 0x2c),0,on_interrupt_from,0x2003,
                             (&proc_info)[uVar12 * 3],DAT_00101c68 + uVar12 * 0x1c8);
          if (iVar3 != 0) {
            _dev_err(*puVar15,"%s: Failed to register interrupt.Err=%d,irqid=%d.\n","rdbg_open",
                     iVar3,*(undefined4 *)(lVar16 + 0x2c));
            _printk(&DAT_00101e5d,iVar3);
            return iVar3;
          }
          lVar16 = lVar10 + uVar12 * 0x1c8;
          __mutex_init(lVar16 + 0x118,"&rdbgdata->write_mutex",&rdbg_open___key);
          piVar19 = (int *)(lVar16 + 0xa8);
          if (*piVar19 == -0xff0100) {
            pcVar4 = "%s: smq producer allocation failed\n";
          }
          else {
            puVar21 = (undefined1 *)*puVar20;
            pcVar4 = "%s: smq producer allocation failed\n";
            if ((puVar21 != (undefined1 *)0x0) && ((*puVar14 & 0x1fffffffe) != 0)) {
              uVar6 = *puVar14 >> 1;
              uVar13 = (ulong)(puVar21 + 9) & 0xfffffffffffffff8;
              uVar5 = ((long)(((int)uVar6 + (int)puVar21) - (int)uVar13) - 0x20U) / 0x88;
              uVar11 = (uint)uVar5;
              *(undefined1 **)(lVar16 + 0x78) = puVar21;
              *(long *)(lVar10 + uVar12 * 0x1c8 + 0xa0) = lVar16 + 0x118;
              if (0 < (int)uVar11) {
                lVar17 = lVar10 + uVar12 * 0x1c8;
                lVar16 = uVar13 + (long)(int)(uVar11 << 7);
                plVar18 = (long *)(lVar17 + 0x80);
                *plVar18 = lVar16;
                *(undefined4 *)(lVar17 + 0xc0) = 1;
                *(ulong *)(lVar17 + 0x88) = (uVar5 & 0xffffffff) * 4 + lVar16 + 0x10;
                *(ulong *)(lVar17 + 0x90) = uVar13;
                puVar9 = (uint *)(lVar17 + 0x98);
                *puVar9 = uVar11;
                *puVar21 = 1;
                if (*puVar9 != 0) {
                  uVar13 = 0;
                  lVar16 = 0x10;
                  do {
                    uVar13 = uVar13 + 1;
                    *(undefined2 *)(*plVar18 + lVar16) = 0xffff;
                    lVar16 = lVar16 + 4;
                    uVar11 = *puVar9;
                    uVar5 = (ulong)uVar11;
                  } while (uVar13 < uVar5);
                  if (1 < uVar11) {
                    lVar16 = __kmalloc(uVar5,0xdc0);
                    plVar7 = (long *)(lVar10 + uVar12 * 0x1c8 + 0xb8);
                    *plVar7 = lVar16;
                    if (lVar16 != 0) {
                      __s = (void *)*plVar7;
                      *(uint *)(lVar10 + uVar12 * 0x1c8 + 0xb4) = uVar11 - 1;
                      memset(__s,0,uVar5);
                      lVar16 = *plVar18;
                      *(undefined4 *)(lVar10 + uVar12 * 0x1c8 + 0xb0) = 0;
                      *(undefined4 *)(lVar16 + 8) = 0;
                      *(undefined4 *)(*plVar18 + 0xc) = 0;
                      piVar8 = (int *)*plVar18;
                      if (*piVar8 == -0xff00ff) {
                        piVar8[1] = piVar8[1] + 1;
                      }
                      else {
                        piVar8[1] = 1;
                        *(undefined4 *)*plVar18 = 0xff00ff01;
                      }
                      lVar16 = lVar10 + uVar12 * 0x1c8;
                      *piVar19 = -0xff0100;
                      piVar8 = (int *)(lVar16 + 0xf8);
                      if (*piVar8 == -0xff0100) {
                        pcVar4 = "%s: smq consumer allocation failed\n";
                      }
                      else {
                        puVar21 = puVar21 + uVar6;
                        pcVar4 = "%s: smq consumer allocation failed\n";
                        if ((puVar21 != (undefined1 *)0x0) && ((*puVar14 & 0x1fffffffe) != 0)) {
                          uVar13 = (ulong)(puVar21 + 9) & 0xfffffffffffffff8;
                          uVar5 = ((long)(((int)puVar21 - (int)uVar13) + (int)(*puVar14 >> 1)) -
                                  0x20U) / 0x88;
                          uVar11 = (uint)uVar5;
                          *(undefined1 **)(lVar16 + 200) = puVar21;
                          if (0 < (int)uVar11) {
                            lVar16 = uVar13 + (long)(int)(uVar11 << 7);
                            lVar10 = lVar10 + uVar12 * 0x1c8;
                            plVar18 = (long *)(lVar10 + 0xd8);
                            *plVar18 = (uVar5 & 0xffffffff) * 4 + lVar16 + 0x10;
                            *(ulong *)(lVar10 + 0xe0) = uVar13;
                            *(undefined4 *)(lVar10 + 0x110) = 2;
                            puVar9 = (uint *)(lVar10 + 0xe8);
                            *puVar9 = uVar11;
                            *(long *)(lVar10 + 0xd0) = lVar16;
                            puVar21[1] = 1;
                            if (*puVar9 != 0) {
                              uVar12 = 0;
                              lVar16 = 0x10;
                              do {
                                uVar12 = uVar12 + 1;
                                *(undefined2 *)(*plVar18 + lVar16) = 0xffff;
                                lVar16 = lVar16 + 4;
                              } while (uVar12 < *puVar9);
                            }
                            iVar3 = 0;
                            *(undefined4 *)(*plVar18 + 8) = 0;
                            *(undefined4 *)(*plVar18 + 0xc) = 0;
                            piVar19 = *(int **)(lVar10 + 0xd0);
                            if (*piVar19 == -0xff00ff) {
                              iVar3 = piVar19[1];
                            }
                            *(int *)(*plVar18 + 4) = iVar3;
                            *(undefined4 *)*plVar18 = 0xff00ff02;
                            *piVar8 = -0xff0100;
                            *(char *)(puVar15 + 0xc) = '\x01';
                            *(undefined8 **)(param_2 + 0xd8) = puVar15;
                            return 0;
                          }
                        }
                      }
                      goto LAB_00101468;
                    }
                  }
                  pcVar4 = "%s: smq producer allocation failed\n";
                }
              }
            }
          }
LAB_00101468:
          _dev_err(*puVar15,pcVar4,"initialize_smq");
          _dev_err(*puVar15,"Error initializing smq. Err=%d\n",0xfffffff4);
          _printk(&DAT_00101e87,0xfffffff4);
          if (*piVar19 == -0xff0100) {
            iVar3 = *(int *)(lVar10 + uVar12 * 0x1c8 + 0xc0);
            if (iVar3 == 2) {
              **(undefined4 **)(lVar10 + uVar12 * 0x1c8 + 0x88) = 0;
            }
            else if (iVar3 == 1) {
              lVar16 = lVar10 + uVar12 * 0x1c8;
              **(undefined4 **)(lVar16 + 0x80) = 0;
              kfree(*(undefined8 *)(lVar16 + 0xb8));
              *(undefined8 *)(lVar16 + 0xb8) = 0;
            }
            *piVar19 = 0;
          }
          piVar19 = (int *)(lVar10 + uVar12 * 0x1c8 + 0xf8);
          if (*piVar19 != -0xff0100) {
            return -0xc;
          }
          iVar3 = *(int *)(lVar10 + uVar12 * 0x1c8 + 0x110);
          if (iVar3 == 2) {
            **(undefined4 **)(lVar10 + uVar12 * 0x1c8 + 0xd8) = 0;
          }
          else if (iVar3 == 1) {
            lVar10 = lVar10 + uVar12 * 0x1c8;
            **(undefined4 **)(lVar10 + 0xd0) = 0;
            kfree(*(undefined8 *)(lVar10 + 0x108));
            *(undefined8 *)(lVar10 + 0x108) = 0;
          }
          *piVar19 = 0;
          return -0xc;
        }
        _printk(&DAT_0010221b,"check_subsystem_debug_enabled");
      }
      if ((uVar13 < 0x181) && (uVar11 != 0x10)) {
        _dev_err(*puVar15,"%s: Subsystem %s is not debug enabled\n","rdbg_open",
                 (&proc_info)[uVar12 * 3]);
        _printk(&DAT_00102257);
        return -0x46;
      }
    }
  }
LAB_00101590:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x101594);
  (*pcVar2)();
}



//------------------------------------------------------------
// rdbg_release @ 0010159c size=348
// signature: undefined rdbg_release(void)
// callers: []
//------------------------------------------------------------

undefined8 rdbg_release(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  uint uVar4;
  int *piVar5;
  long lVar6;
  
  lVar6 = DAT_00101c68;
  if ((param_1 == 0) || (DAT_00101c68 == 0)) {
    _printk(&DAT_00102181);
    uVar2 = 0xffffffed;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x4c) & 0xfffff;
    pcVar3 = (char *)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0x60);
    if (*pcVar3 != '\0') {
      *pcVar3 = '\0';
      complete(lVar6 + (ulong)uVar4 * 0x1c8 + 8);
      piVar5 = (int *)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0xa8);
      if (*piVar5 == -0xff0100) {
        iVar1 = *(int *)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0xc0);
        if (iVar1 == 2) {
          **(undefined4 **)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0x88) = 0;
        }
        else if (iVar1 == 1) {
          lVar6 = DAT_00101c68 + (ulong)uVar4 * 0x1c8;
          **(undefined4 **)(lVar6 + 0x80) = 0;
          kfree(*(undefined8 *)(lVar6 + 0xb8));
          *(undefined8 *)(lVar6 + 0xb8) = 0;
        }
        *piVar5 = 0;
      }
      piVar5 = (int *)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0xf8);
      if (*piVar5 == -0xff0100) {
        iVar1 = *(int *)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0x110);
        if (iVar1 == 2) {
          **(undefined4 **)(DAT_00101c68 + (ulong)uVar4 * 0x1c8 + 0xd8) = 0;
        }
        else if (iVar1 == 1) {
          lVar6 = DAT_00101c68 + (ulong)uVar4 * 0x1c8;
          **(undefined4 **)(lVar6 + 0xd0) = 0;
          kfree(*(undefined8 *)(lVar6 + 0x108));
          *(undefined8 *)(lVar6 + 0x108) = 0;
        }
        *piVar5 = 0;
      }
    }
    uVar2 = 0;
    *(undefined8 *)(param_2 + 0xd8) = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// on_interrupt_from @ 001016fc size=36
// signature: undefined on_interrupt_from(void)
// callers: []
//------------------------------------------------------------

undefined8 on_interrupt_from(undefined8 param_1,long param_2)

{
  complete(param_2 + 8);
  return 1;
}



//------------------------------------------------------------
// init_module @ 00101774 size=732
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  int iVar10;
  
  if (DAT_00101c64 - 0x11 < 0xfffffff0) {
    _printk(&DAT_0010219d);
    uVar7 = 0xffffffdf;
  }
  else {
    DAT_00101c68 = __kmalloc((ulong)DAT_00101c64 * 0x1c8,0xdc0);
    if (DAT_00101c68 == 0) {
      uVar7 = 0xfffffff4;
    }
    else {
      uVar4 = __platform_driver_register(&rdbg_driver,&__this_module);
      uVar7 = uVar4 & 0xffffffff;
      if ((int)uVar4 == 0) {
        uVar2 = alloc_chrdev_region(&DAT_00101c60,0,DAT_00101c64,"rdbgctl");
        if (uVar2 == 0) {
          uVar2 = DAT_00101c60 & 0xfff00000;
          cdev_init(&g_rdbg_instance,&rdbg_fops);
          DAT_00101c30 = &__this_module;
          uVar3 = cdev_add(&g_rdbg_instance,uVar2,DAT_00101c64);
          if (uVar3 == 0) {
            uVar7 = __class_create(&__this_module,&DAT_00102052,&rdbg_init___key);
            DAT_00101c58 = uVar7;
            if (uVar7 < 0xfffffffffffff001) {
              if (0 < (int)DAT_00101c64) {
                lVar8 = 0;
                lVar6 = 0;
                lVar9 = 0;
                iVar10 = 0;
                uVar3 = DAT_00101c64;
                do {
                  if (lVar9 == 0x10) {
                    /* WARNING: Does not return */
                    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101a4c);
                    (*pcVar1)();
                  }
                  if (lVar6 == 0x180) {
                    /* WARNING: Does not return */
                    pcVar1 = (code *)SoftwareBreakpoint(1,0x101a50);
                    (*pcVar1)();
                  }
                  if (*(long *)((long)&proc_info + lVar6) != 0) {
                    uVar5 = device_create(DAT_00101c58,0,uVar2 | (uint)lVar9,0,&DAT_00101f6b);
                    *(undefined8 *)(DAT_00101c68 + lVar8) = uVar5;
                    uVar7 = *(ulong *)(DAT_00101c68 + lVar8);
                    if (0xfffffffffffff000 < uVar7) {
                      _printk(&DAT_00101dd2);
                      if ((uint)lVar9 != 0) {
                        uVar4 = lVar9 + 1;
                        lVar9 = DAT_00101c68;
                        do {
                          uVar2 = (int)uVar4 - 2;
                          if (*(char *)(lVar9 + (ulong)uVar2 * 0x1c8 + 0x58) != '\0') {
                            device_destroy(DAT_00101c58,DAT_00101c60 & 0xfff00000 | uVar2);
                            lVar9 = DAT_00101c68;
                          }
                          uVar2 = (int)uVar4 - 1;
                          uVar4 = (ulong)uVar2;
                        } while (1 < (int)uVar2);
                      }
                      goto LAB_00101980;
                    }
                    iVar10 = iVar10 + 1;
                    *(undefined1 *)(DAT_00101c68 + lVar8 + 0x58) = 1;
                    uVar3 = DAT_00101c64;
                  }
                  lVar9 = lVar9 + 1;
                  lVar6 = lVar6 + 0x18;
                  lVar8 = lVar8 + 0x1c8;
                } while (lVar9 < (int)uVar3);
                if (iVar10 != 0) {
                  uVar7 = 0;
                  goto LAB_00101928;
                }
              }
              _printk(&DAT_001020ca);
              uVar7 = 0xffffffea;
LAB_00101980:
              class_destroy(DAT_00101c58);
            }
            else {
              _printk(&DAT_00102057);
            }
            cdev_del(&g_rdbg_instance);
          }
          else {
            uVar7 = (ulong)uVar3;
            _printk(&DAT_00101f56);
          }
          unregister_chrdev_region(DAT_00101c60,DAT_00101c64);
        }
        else {
          uVar7 = (ulong)uVar2;
          _printk(&DAT_00101f96);
        }
        kfree(DAT_00101c68);
      }
    }
  }
LAB_00101928:
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 00101a54 size=176
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (0 < DAT_00101c64) {
    lVar3 = 0;
    lVar4 = 0x58;
    lVar2 = DAT_00101c68;
    iVar1 = DAT_00101c64;
    do {
      if (*(char *)(lVar2 + lVar4) != '\0') {
        device_destroy(DAT_00101c58,DAT_00101c60 & 0xfff00000 | (uint)lVar3);
        lVar2 = DAT_00101c68;
        iVar1 = DAT_00101c64;
      }
      lVar3 = lVar3 + 1;
      lVar4 = lVar4 + 0x1c8;
    } while (lVar3 < iVar1);
  }
  class_destroy(DAT_00101c58);
  cdev_del(&g_rdbg_instance);
  unregister_chrdev_region(DAT_00101c60,1);
  kfree(DAT_00101c68);
  return;
}



//------------------------------------------------------------
// __kmalloc @ 00104000 size=1
// signature: undefined __kmalloc(void)
// callers: [rdbg_open, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104008 size=1
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
// alloc_chrdev_region @ 00104010 size=1
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
// cdev_init @ 00104018 size=1
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
// cdev_add @ 00104020 size=1
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
// __class_create @ 00104028 size=1
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
// device_create @ 00104030 size=1
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
// _printk @ 00104038 size=1
// signature: undefined _printk(void)
// callers: [rdbg_probe, rdbg_release, rdbg_open, init_module, rdbg_write, rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00104040 size=1
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
// cdev_del @ 00104048 size=1
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
// unregister_chrdev_region @ 00104050 size=1
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
// kfree @ 00104058 size=1
// signature: undefined kfree(void)
// callers: [rdbg_probe, rdbg_release, rdbg_open, init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00104060 size=1
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
// kmalloc_trace @ 00104070 size=1
// signature: undefined kmalloc_trace(void)
// callers: [rdbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 00104078 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [rdbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00104080 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [rdbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00104088 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [rdbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104090 size=1
// signature: undefined of_find_property(void)
// callers: [rdbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_get @ 00104098 size=1
// signature: undefined qcom_smem_state_get(void)
// callers: [rdbg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible @ 001040a0 size=1
// signature: undefined wait_for_completion_interruptible(void)
// callers: [rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001040a8 size=1
// signature: undefined mutex_lock(void)
// callers: [rdbg_write, rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001040b0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [rdbg_open, rdbg_write, rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001040b8 size=1
// signature: undefined mutex_unlock(void)
// callers: [rdbg_write, rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001040c0 size=1
// signature: undefined __check_object_size(void)
// callers: [rdbg_write, rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001040d8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001040e0 size=1
// signature: undefined _dev_err(void)
// callers: [rdbg_open, rdbg_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001040f0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [rdbg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_update_bits @ 001040f8 size=1
// signature: undefined qcom_smem_state_update_bits(void)
// callers: [rdbg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00104100 size=1
// signature: undefined qcom_smem_get(void)
// callers: [rdbg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104108 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [rdbg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00104110 size=1
// signature: undefined request_threaded_irq(void)
// callers: [rdbg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104118 size=1
// signature: undefined __mutex_init(void)
// callers: [rdbg_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00104120 size=1
// signature: undefined complete(void)
// callers: [rdbg_release, on_interrupt_from]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



