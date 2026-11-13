// Decompiled by Ghidra 12.2
// Program: msm_dma_iommu_mapping.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_dma_map_sg_attrs @ 0010027c size=1644
// signature: undefined msm_dma_map_sg_attrs(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong msm_dma_map_sg_attrs
                (ulong param_1,ulong *param_2,ulong param_3,int param_4,ulong param_5,ulong param_6)

{
  byte bVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  long lVar5;
  ulong *puVar6;
  int iVar7;
  undefined *puVar8;
  ulong *puVar9;
  ulong *puVar10;
  ulong uVar11;
  ulong uVar12;
  int iVar13;
  ulong uVar14;
  uint uVar15;
  ulong uVar16;
  ulong *puVar17;
  ulong *puVar18;
  undefined8 uVar19;
  ulong *puVar20;
  ulong *local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  if ((param_1 == 0) || (0xfffffffffffff000 < param_1)) {
    puVar8 = &DAT_00101063;
  }
  else if ((param_2 == (ulong *)0x0) || ((ulong *)0xfffffffffffff000 < param_2)) {
    puVar8 = &DAT_0010120f;
  }
  else {
    if ((param_5 != 0) && (param_5 < 0xfffffffffffff001)) {
      mutex_lock(&msm_iommu_map_mutex);
      uVar15 = (uint)param_6;
      iVar13 = (int)param_3;
      if (iommu_root != (ulong *)0x0) {
        puVar17 = iommu_root;
LAB_00100318:
        do {
          if (*(ulong *)(param_5 + 0xa0) < puVar17[0xc]) goto LAB_0010030c;
          if (*(ulong *)(param_5 + 0xa0) <= puVar17[0xc]) {
            puVar20 = puVar17 + 5;
            Hint_Prefetch(puVar20,2,0,1);
            do {
              uVar4 = (uint)*puVar20;
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar20,0x10);
              if (bVar3) {
                *(uint *)puVar20 = uVar4 + 1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            if (uVar4 == 0) {
              uVar19 = 2;
LAB_00100840:
              refcount_warn_saturate(puVar20,uVar19);
            }
            else if ((int)(uVar4 + 1 | uVar4) < 0) {
              uVar19 = 1;
              goto LAB_00100840;
            }
            goto LAB_001004a4;
          }
          puVar17 = (ulong *)puVar17[1];
        } while (puVar17 != (ulong *)0x0);
      }
LAB_00100334:
      puVar17 = (ulong *)kmalloc_trace(_memstart_addr,0xdc0,0x68);
      if (puVar17 == (ulong *)0x0) {
        mutex_unlock(&msm_iommu_map_mutex);
        uVar11 = 0xfffffff4;
        goto LAB_001008b8;
      }
      puVar17[3] = (ulong)(puVar17 + 3);
      puVar17[4] = (ulong)(puVar17 + 3);
      uVar11 = *(ulong *)(param_5 + 0xa0);
      puVar18 = puVar17 + 5;
      *(uint *)puVar18 = 1;
      puVar17[0xc] = uVar11;
      __mutex_init(puVar17 + 6,"&meta->lock",&msm_iommu_meta_create___key);
      puVar20 = (ulong *)&iommu_root;
      puVar6 = iommu_root;
      if (iommu_root == (ulong *)0x0) {
        puVar10 = (ulong *)0x0;
      }
      else {
        do {
          puVar10 = puVar6;
          if (puVar17[0xc] < puVar10[0xc]) {
            puVar20 = puVar10 + 2;
          }
          else if (puVar10[0xc] < puVar17[0xc]) {
            puVar20 = puVar10 + 1;
          }
          else {
            _printk(&DAT_001011ed,"msm_iommu_meta_add");
          }
          puVar6 = (ulong *)*puVar20;
        } while ((ulong *)*puVar20 != (ulong *)0x0);
      }
      *puVar17 = (ulong)puVar10;
      puVar17[1] = 0;
      puVar17[2] = 0;
      *puVar20 = (ulong)puVar17;
      rb_insert_color(puVar17,&iommu_root);
      if ((ulong *)0xfffffffffffff000 < puVar17) {
        mutex_unlock(&msm_iommu_map_mutex);
        uVar11 = (ulong)puVar17 & 0xffffffff;
        goto LAB_001008b8;
      }
      if ((uVar15 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar18,2,0,1);
        do {
          uVar4 = (uint)*puVar18;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar18,0x10);
          if (bVar3) {
            *(uint *)puVar18 = uVar4 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (uVar4 == 0) {
          uVar19 = 2;
        }
        else {
          uVar19 = 1;
          bVar3 = true;
          if (-1 < (int)(uVar4 + 1 | uVar4)) goto LAB_001004a8;
        }
        refcount_warn_saturate(puVar18,uVar19);
        bVar3 = true;
      }
      else {
LAB_001004a4:
        bVar3 = false;
      }
LAB_001004a8:
      param_3 = param_3 & 0xffffffff;
      mutex_unlock(&msm_iommu_map_mutex);
      puVar20 = puVar17 + 6;
      mutex_lock(puVar20);
      puVar6 = puVar17 + 3;
      puVar18 = puVar6;
      do {
        puVar18 = (ulong *)*puVar18;
        if (puVar18 == puVar6) goto LAB_001005d8;
      } while (puVar18[5] != param_1);
      if (puVar18 == (ulong *)0x0) {
LAB_001005d8:
        puVar18 = (ulong *)kmalloc_trace(_memstart_addr,0xcc0,0x60);
        if (puVar18 == (ulong *)0x0) {
          uVar11 = 0xfffffff4;
        }
        else {
          uVar16 = dma_map_sg_attrs(param_1,param_2,param_3,param_4,param_6);
          uVar11 = uVar16 & 0xffffffff;
          if ((int)uVar16 != 0) {
            local_78 = (ulong *)0x0;
            uStack_70 = 0;
            iVar7 = sg_alloc_table(&local_78,param_3,0xcc0);
            if (iVar7 == 0) {
              if (0 < iVar13) {
                puVar10 = param_2;
                puVar9 = local_78;
                do {
                  uVar14 = puVar10[3];
                  uVar16 = *puVar10;
                  uVar12 = puVar10[1];
                  puVar9[2] = puVar10[2];
                  puVar9[3] = uVar14;
                  *puVar9 = uVar16;
                  puVar9[1] = uVar12;
                  puVar9 = (ulong *)sg_next(puVar9);
                  puVar10 = (ulong *)sg_next(puVar10);
                  uVar4 = (int)param_3 - 1;
                  param_3 = (ulong)uVar4;
                } while (uVar4 != 0);
              }
              puVar18[6] = (ulong)local_78;
              if (local_78 != (ulong *)0x0) {
                puVar10 = puVar18 + 9;
                *(uint *)puVar10 = 1;
                uVar14 = _memstart_addr;
                puVar18[5] = param_1;
                uVar12 = *param_2;
                *(int *)(puVar18 + 7) = iVar13;
                *(int *)((long)puVar18 + 0x3c) = param_4;
                uVar16 = param_2[1];
                puVar18[10] = param_6;
                puVar18[0xb] = (ulong)(uint)uVar16 +
                               ((uVar12 & 0x3fffffffffffffc) +
                               (uVar14 >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40;
                if ((uVar15 >> 0xd & 1) == 0) {
                  Hint_Prefetch(puVar10,2,0,1);
                  do {
                    uVar15 = (uint)*puVar10;
                    cVar2 = '\x01';
                    bVar3 = (bool)ExclusiveMonitorPass(puVar10,0x10);
                    if (bVar3) {
                      *(uint *)puVar10 = uVar15 + 1;
                      cVar2 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar2 != '\0');
                  if (uVar15 == 0) {
                    uVar19 = 2;
                  }
                  else {
                    if (-1 < (int)(uVar15 + 1 | uVar15)) goto LAB_00100774;
                    uVar19 = 1;
                  }
                  refcount_warn_saturate(puVar10,uVar19);
                }
LAB_00100774:
                puVar18[8] = (ulong)puVar17;
                *puVar18 = (ulong)puVar18;
                puVar18[1] = (ulong)puVar18;
                uVar14 = puVar17[3];
                uVar16 = __list_add_valid(puVar18,puVar6,uVar14);
                if ((uVar16 & 1) != 0) {
                  *(ulong **)(uVar14 + 8) = puVar18;
                  *puVar18 = uVar14;
                  puVar18[1] = (ulong)puVar6;
                  *puVar6 = (ulong)puVar18;
                }
                goto LAB_001008b0;
              }
              uVar11 = 0xfffffff4;
            }
            else {
              uVar11 = 0xfffffff4;
              puVar18[6] = 0;
            }
          }
          kfree(puVar18);
        }
        mutex_unlock(puVar20);
        if (puVar17 < (ulong *)0xfffffffffffff001) {
          if (bVar3) {
            msm_iommu_meta_put(puVar17);
          }
          msm_iommu_meta_put(puVar17);
        }
        goto LAB_001008b8;
      }
      iVar7 = *(int *)((long)puVar18 + 0x3c);
      if (((((int)puVar18[7] == iVar13) && (iVar7 == param_4)) &&
          (iVar7 = param_4, ((puVar18[10] ^ param_6) & 0xffffffffffffffdf) == 0)) &&
         ((ulong)(uint)param_2[1] +
          ((*param_2 & 0x3fffffffffffffc) + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000)
          * 0x40 == puVar18[0xb])) {
        if (0 < iVar13) {
          uVar16 = puVar18[6];
          uVar11 = param_3;
          do {
            param_2[2] = *(ulong *)(uVar16 + 0x10);
            *(undefined4 *)(param_2 + 3) = *(undefined4 *)(uVar16 + 0x18);
            if ((*(int *)(uVar16 + 0x18) == 0) ||
               (param_2 = (ulong *)sg_next(param_2), param_2 == (ulong *)0x0)) break;
            uVar16 = sg_next(uVar16);
            uVar4 = (int)uVar11 - 1;
            uVar11 = (ulong)uVar4;
          } while (uVar4 != 0);
        }
        puVar17 = puVar18 + 9;
        Hint_Prefetch(puVar17,2,0,1);
        do {
          uVar4 = (uint)*puVar17;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar17,0x10);
          if (bVar3) {
            *(uint *)puVar17 = uVar4 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        if (uVar4 == 0) {
          uVar19 = 2;
LAB_00100898:
          refcount_warn_saturate(puVar17,uVar19);
          if ((uVar15 >> 5 & 1) != 0) goto LAB_001008a0;
LAB_001005bc:
          dma_sync_sg_for_device
                    (param_1,puVar18[6],(int)puVar18[7],*(undefined4 *)((long)puVar18 + 0x3c));
          bVar1 = *(byte *)(param_1 + 0x34c);
        }
        else {
          if ((int)(uVar4 + 1 | uVar4) < 0) {
            uVar19 = 1;
            goto LAB_00100898;
          }
          if ((uVar15 >> 5 & 1) == 0) goto LAB_001005bc;
LAB_001008a0:
          bVar1 = *(byte *)(param_1 + 0x34c);
        }
        if ((bVar1 >> 5 & 1) != 0) {
          DataMemoryBarrier(2,3);
        }
        uVar11 = param_3;
      }
      else {
        _dev_err(param_1,
                 "lazy map request differs:\nreq dir:%d, original dir:%d\nreq nents:%d, original nents:%d\nreq map attrs:%lu, original map attrs:%lu\nreq buffer start address differs:%d\n"
                 ,param_4,iVar7,param_3,(int)puVar18[7],param_6,puVar18[10],
                 (ulong)(uint)param_2[1] +
                 ((*param_2 & 0x3fffffffffffffc) +
                 (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40 != puVar18[0xb]);
        uVar11 = 0xffffffea;
      }
LAB_001008b0:
      mutex_unlock(puVar20);
      goto LAB_001008b8;
    }
    puVar8 = &DAT_00100fb0;
  }
  _printk(puVar8,"msm_dma_map_sg_attrs");
  uVar11 = 0xffffffea;
LAB_001008b8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
LAB_0010030c:
  puVar17 = (ulong *)puVar17[2];
  if (puVar17 == (ulong *)0x0) goto LAB_00100334;
  goto LAB_00100318;
}



//------------------------------------------------------------
// msm_dma_unmap_sg_attrs @ 00100920 size=444
// signature: undefined msm_dma_unmap_sg_attrs(void)
// callers: []
//------------------------------------------------------------

void msm_dma_unmap_sg_attrs
               (long param_1,undefined8 param_2,undefined8 param_3,int param_4,long param_5,
               long param_6)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  long lVar6;
  long *plVar7;
  
  mutex_lock(&msm_iommu_map_mutex);
  if (iommu_root != 0) {
    lVar6 = iommu_root;
    do {
      while (*(ulong *)(lVar6 + 0x60) <= *(ulong *)(param_5 + 0xa0)) {
        if (*(ulong *)(param_5 + 0xa0) <= *(ulong *)(lVar6 + 0x60)) {
          mutex_unlock(&msm_iommu_map_mutex);
          mutex_lock(lVar6 + 0x30);
          plVar7 = (long *)(lVar6 + 0x18);
          goto LAB_001009f8;
        }
        lVar6 = *(long *)(lVar6 + 8);
        if (lVar6 == 0) goto LAB_00100994;
      }
      lVar6 = *(long *)(lVar6 + 0x10);
    } while (lVar6 != 0);
  }
LAB_00100994:
  __warn_printk("%s: (%pK) was never mapped\n","msm_dma_unmap_sg_attrs",param_5);
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1009b8);
  (*pcVar5)();
  while (plVar7[5] != param_1) {
LAB_001009f8:
    plVar7 = (long *)*plVar7;
    if (plVar7 == (long *)(lVar6 + 0x18)) goto LAB_00100a84;
  }
  if (plVar7 != (long *)0x0) {
    if (*(int *)((long)plVar7 + 0x3c) != param_4) {
      __warn_printk("%s: (%pK) dir:%d differs from original dir:%d\n","msm_dma_unmap_sg_attrs",
                    param_5,param_4);
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100a40);
      (*pcVar5)();
    }
    if ((param_6 != 0) && (((uint)param_6 >> 5 & 1) == 0)) {
      dma_sync_sg_for_cpu(param_1,plVar7[6],*(undefined4 *)(plVar7 + 7),param_4);
    }
    piVar1 = (int *)(plVar7 + 9);
    plVar7[10] = param_6;
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
      msm_iommu_map_release();
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
    mutex_unlock(lVar6 + 0x30);
    msm_iommu_meta_put(lVar6);
    return;
  }
LAB_00100a84:
  __warn_printk("%s: (%pK) was never mapped for device  %p\n","msm_dma_unmap_sg_attrs",param_5,
                param_1);
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100aa8);
  (*pcVar5)();
}



//------------------------------------------------------------
// msm_iommu_map_release @ 00100af8 size=188
// signature: undefined msm_iommu_map_release(void)
// callers: [msm_dma_unmap_all_for_dev, msm_dma_unmap_sg_attrs, msm_dma_buf_freed]
//------------------------------------------------------------

void msm_iommu_map_release(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 local_38;
  undefined4 local_30;
  undefined4 uStack_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = *(undefined4 *)(param_1 + -0x10);
  local_38 = *(undefined8 *)(param_1 + -0x18);
  uStack_2c = local_30;
  uVar3 = __list_del_entry_valid(param_1 + -0x48);
  if ((uVar3 & 1) != 0) {
    lVar1 = *(long *)(param_1 + -0x48);
    plVar2 = *(long **)(param_1 + -0x40);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(param_1 + -0x48) = 0xdead000000000100;
  *(undefined8 *)(param_1 + -0x40) = 0xdead000000000122;
  if (((uint)*(ulong *)(param_1 + 8) >> 5 & 1) == 0) {
    *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) | 0x20;
  }
  dma_unmap_sg_attrs(*(undefined8 *)(param_1 + -0x20),*(undefined8 *)(param_1 + -0x18),
                     *(undefined4 *)(param_1 + -0x10),*(undefined4 *)(param_1 + -0xc));
  sg_free_table(&local_38);
  kfree(param_1 + -0x48);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_iommu_meta_put @ 00100bb4 size=196
// signature: undefined msm_iommu_meta_put(void)
// callers: [msm_dma_unmap_sg_attrs, msm_dma_map_sg_attrs, msm_dma_buf_freed]
//------------------------------------------------------------

void msm_iommu_meta_put(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  
  mutex_lock(&msm_iommu_map_mutex);
  piVar1 = (int *)(param_1 + 0x28);
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
    if (*(long **)(param_1 + 0x18) != (long *)(param_1 + 0x18)) {
      __warn_printk("%s: DMA Buffer %pK being destroyed with outstanding iommu mappings!\n",
                    "msm_iommu_meta_destroy",*(undefined8 *)(param_1 + 0x60));
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x100c1c);
      (*pcVar5)();
    }
    rb_erase(param_1,&iommu_root);
    kfree(param_1);
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
  mutex_unlock(&msm_iommu_map_mutex);
  return;
}



//------------------------------------------------------------
// msm_dma_unmap_all_for_dev @ 00100c8c size=292
// signature: undefined msm_dma_unmap_all_for_dev(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_dma_unmap_all_for_dev(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  long *plVar8;
  
  mutex_lock(&msm_iommu_map_mutex);
  lVar6 = rb_first(&iommu_root);
  if (lVar6 == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
    do {
      mutex_lock(lVar6 + 0x30);
      plVar8 = (long *)*(long *)(lVar6 + 0x18);
      while (plVar5 = plVar8, plVar5 != (long *)(lVar6 + 0x18)) {
        plVar8 = (long *)*plVar5;
        if (plVar5[5] == param_1) {
          piVar1 = (int *)(plVar5 + 9);
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
            msm_iommu_map_release();
          }
          else if (iVar2 < 1) {
            refcount_warn_saturate(piVar1,3);
            uVar7 = 0xffffffea;
          }
          else {
            uVar7 = 0xffffffea;
          }
        }
      }
      mutex_unlock(lVar6 + 0x30);
      lVar6 = rb_next(lVar6);
    } while (lVar6 != 0);
  }
  mutex_unlock(&msm_iommu_map_mutex);
  return uVar7;
}



//------------------------------------------------------------
// msm_dma_buf_freed @ 00100dc0 size=336
// signature: undefined msm_dma_buf_freed(void)
// callers: []
//------------------------------------------------------------

void msm_dma_buf_freed(ulong param_1)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int *piVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  
  mutex_lock(&msm_iommu_map_mutex);
  for (lVar6 = iommu_root; lVar6 != 0; lVar6 = *(long *)(lVar6 + 0x10)) {
    while (*(ulong *)(lVar6 + 0x60) <= param_1) {
      if (param_1 <= *(ulong *)(lVar6 + 0x60)) {
        mutex_unlock(&msm_iommu_map_mutex);
        mutex_lock(lVar6 + 0x30);
        plVar7 = (long *)(lVar6 + 0x18);
        plVar8 = (long *)*plVar7;
        while (plVar8 != plVar7) {
          piVar5 = (int *)(plVar8 + 9);
          plVar8 = (long *)*plVar8;
          Hint_Prefetch(piVar5,2,0,1);
          do {
            iVar1 = *piVar5;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar5,0x10);
            if (bVar3) {
              *piVar5 = iVar1 + -1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (iVar1 == 1) {
            DataMemoryBarrier(2,1);
            msm_iommu_map_release();
          }
          else if (iVar1 < 1) {
            refcount_warn_saturate(piVar5,3);
          }
        }
        if ((long *)*plVar7 != plVar7) {
          __warn_printk("%s: DMA buffer %pK destroyed with outstanding iommu mappings\n",
                        "msm_dma_buf_freed",*(undefined8 *)(lVar6 + 0x60));
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100ee8);
          (*pcVar4)();
        }
        *(long *)(lVar6 + 0x18) = lVar6 + 0x18;
        *(long **)(lVar6 + 0x20) = plVar7;
        mutex_unlock(lVar6 + 0x30);
        msm_iommu_meta_put(lVar6);
        return;
      }
      lVar6 = *(long *)(lVar6 + 8);
      if (lVar6 == 0) goto LAB_00100e20;
    }
  }
LAB_00100e20:
  mutex_unlock(&msm_iommu_map_mutex);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00102000 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_dma_unmap_all_for_dev, msm_dma_unmap_sg_attrs, msm_iommu_meta_put, msm_dma_map_sg_attrs, msm_dma_buf_freed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102010 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00102018 size=1
// signature: undefined __mutex_init(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102020 size=1
// signature: undefined _printk(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102028 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_dma_unmap_all_for_dev, msm_dma_unmap_sg_attrs, msm_iommu_meta_put, msm_dma_map_sg_attrs, msm_dma_buf_freed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_insert_color @ 00102038 size=1
// signature: undefined rb_insert_color(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_insert_color(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 00102048 size=1
// signature: undefined sg_next(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_sg_for_device @ 00102050 size=1
// signature: undefined dma_sync_sg_for_device(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_sg_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_sg_attrs @ 00102058 size=1
// signature: undefined dma_map_sg_attrs(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table @ 00102060 size=1
// signature: undefined sg_alloc_table(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102068 size=1
// signature: undefined kfree(void)
// callers: [msm_iommu_meta_put, msm_dma_map_sg_attrs, msm_iommu_map_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102070 size=1
// signature: undefined __list_add_valid(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102078 size=1
// signature: undefined _dev_err(void)
// callers: [msm_dma_map_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00102080 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [msm_dma_unmap_all_for_dev, msm_dma_unmap_sg_attrs, msm_iommu_meta_put, msm_dma_map_sg_attrs, msm_dma_buf_freed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_dma_map_sg_attrs, msm_iommu_map_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00102090 size=1
// signature: undefined __warn_printk(void)
// callers: [msm_dma_unmap_sg_attrs, msm_iommu_meta_put, msm_dma_buf_freed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_sg_for_cpu @ 00102098 size=1
// signature: undefined dma_sync_sg_for_cpu(void)
// callers: [msm_dma_unmap_sg_attrs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_sg_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001020a0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [msm_iommu_map_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_sg_attrs @ 001020a8 size=1
// signature: undefined dma_unmap_sg_attrs(void)
// callers: [msm_iommu_map_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 001020b0 size=1
// signature: undefined sg_free_table(void)
// callers: [msm_iommu_map_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_erase @ 001020b8 size=1
// signature: undefined rb_erase(void)
// callers: [msm_iommu_meta_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_erase(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_first @ 001020c0 size=1
// signature: undefined rb_first(void)
// callers: [msm_dma_unmap_all_for_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_first(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_next @ 001020c8 size=1
// signature: undefined rb_next(void)
// callers: [msm_dma_unmap_all_for_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



