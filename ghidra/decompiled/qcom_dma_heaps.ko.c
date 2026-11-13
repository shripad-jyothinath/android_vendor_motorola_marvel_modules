// Decompiled by Ghidra 12.2
// Program: qcom_dma_heaps.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_store_dma_buf_fops @ 00101a7c size=32
// signature: undefined qcom_store_dma_buf_fops(void)
// callers: [__carveout_heap_allocate, system_heap_allocate, system_heap_allocate, cma_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

void qcom_store_dma_buf_fops(long param_1)

{
  if (dma_buf_cached_fops == -0x16) {
    dma_buf_cached_fops = *(undefined8 *)(param_1 + 0x28);
    return;
  }
  return;
}



//------------------------------------------------------------
// qcom_is_dma_buf_file @ 00101aa0 size=24
// signature: undefined qcom_is_dma_buf_file(void)
// callers: []
//------------------------------------------------------------

bool qcom_is_dma_buf_file(long param_1)

{
  return *(long *)(param_1 + 0x28) == dma_buf_cached_fops;
}



//------------------------------------------------------------
// qcom_dma_heap_probe @ 00101abc size=424
// signature: undefined qcom_dma_heap_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_dma_heap_probe(undefined8 param_1)

{
  int *piVar1;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  qcom_system_heap_create("qcom,system","system",0);
  qcom_secure_system_heap_create("qcom,secure-pixel",0,0x80000);
  qcom_secure_system_heap_create("qcom,secure-non-pixel",0,0x100000);
  piVar1 = (int *)parse_heap_dt(param_1);
  piVar5 = piVar1;
  if ((piVar1 != (int *)0x0) && (piVar1 < (int *)0xfffffffffffff001)) {
    if (*piVar1 < 1) {
      piVar5 = (int *)0x0;
    }
    else {
      lVar6 = 0;
      lVar7 = 0;
      piVar4 = (int *)0x0;
      do {
        lVar8 = *(long *)(piVar1 + 2);
        piVar5 = (int *)0xffffffea;
        switch(*(undefined4 *)(lVar8 + lVar6)) {
        case 0:
          uVar2 = qcom_secure_carveout_heap_create();
          iVar3 = (int)uVar2;
          break;
        case 1:
          uVar2 = qcom_carveout_heap_create();
          iVar3 = (int)uVar2;
          break;
        case 2:
          uVar2 = qcom_add_cma_heap();
          iVar3 = (int)uVar2;
          break;
        case 3:
        case 4:
          goto switchD_00101b9c_caseD_3;
        default:
          _printk(&DAT_00109f8f,"qcom_dma_heap_probe");
          iVar3 = (int)piVar4;
          piVar5 = piVar4;
          goto joined_r0x00101bbc;
        }
        piVar5 = (int *)(uVar2 & 0xffffffff);
joined_r0x00101bbc:
        if (iVar3 == 0) {
          _printk(&DAT_0010a0de,"qcom_dma_heap_probe",*(undefined8 *)(lVar8 + lVar6 + 8));
        }
        else {
switchD_00101b9c_caseD_3:
          _printk(&DAT_0010a049,"qcom_dma_heap_probe",*(undefined8 *)(lVar8 + lVar6 + 8),piVar5);
        }
        lVar7 = lVar7 + 1;
        lVar6 = lVar6 + 0x38;
        piVar4 = piVar5;
      } while (lVar7 < *piVar1);
    }
    free_pdata(piVar1);
    dma_buf_cached_fops = 0xffffffffffffffea;
  }
  return (ulong)piVar5 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_dma_heaps_freeze @ 00101c68 size=128
// signature: undefined qcom_dma_heaps_freeze(void)
// callers: []
//------------------------------------------------------------

int qcom_dma_heaps_freeze(void)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = qcom_secure_carveout_heap_freeze();
  if (iVar1 == 0) {
    iVar1 = qcom_secure_system_heap_freeze();
    if (iVar1 == 0) {
      return 0;
    }
    _printk(&DAT_0010a28b,iVar1);
    iVar1 = qcom_secure_carveout_heap_restore();
    if (iVar1 == 0) {
      return -0x10;
    }
    puVar2 = &DAT_00109af0;
  }
  else {
    puVar2 = &DAT_00109de6;
  }
  _printk(puVar2,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// qcom_dma_heaps_restore @ 00101cec size=96
// signature: undefined qcom_dma_heaps_restore(void)
// callers: []
//------------------------------------------------------------

int qcom_dma_heaps_restore(void)

{
  int iVar1;
  
  iVar1 = qcom_secure_carveout_heap_restore();
  if (iVar1 != 0) {
    _printk(&DAT_00109af0,iVar1);
  }
  iVar1 = qcom_secure_system_heap_restore();
  if (iVar1 != 0) {
    _printk(&DAT_0010a34c,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// free_pdata @ 00101d50 size=52
// signature: undefined free_pdata(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

void free_pdata(long param_1)

{
  kfree(*(undefined8 *)(param_1 + 8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// parse_heap_dt @ 00101d88 size=1088
// signature: undefined parse_heap_dt(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * parse_heap_dt(long param_1)

{
  uint uVar1;
  undefined1 auVar2 [16];
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  long lVar7;
  undefined8 *puVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  ulong uVar12;
  long lVar13;
  uint uVar14;
  long local_b8 [11];
  
  lVar7 = sp_el0;
  local_b8[10] = *(long *)(lVar7 + 0x638);
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  puVar6 = (uint *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x10);
  if (puVar6 != (uint *)0x0) {
    lVar7 = of_get_next_available_child(uVar11,0);
    uVar12 = (ulong)*puVar6;
    if (lVar7 != 0) {
      do {
        uVar14 = (int)uVar12 + 1;
        uVar12 = (ulong)uVar14;
        *puVar6 = uVar14;
        lVar7 = of_get_next_available_child(uVar11,lVar7);
      } while (lVar7 != 0);
    }
    iVar4 = (int)uVar12;
    if (iVar4 == 0) goto LAB_00102188;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = (long)iVar4;
    if (SUB168(auVar2 * ZEXT816(0x38),8) == 0) {
      lVar7 = __kmalloc((-(uVar12 >> 0x1f) & 0xffffffc000000000 | uVar12 << 6) + (long)iVar4 * -8,
                        0xdc0);
      *(long *)(puVar6 + 2) = lVar7;
      if (lVar7 != 0) {
        puVar8 = (undefined8 *)of_get_next_available_child(uVar11,0);
        if (puVar8 != (undefined8 *)0x0) {
          uVar14 = 0xffffffff;
          do {
            lVar7 = of_platform_device_create(puVar8,0,param_1 + 0x10);
            if (lVar7 == 0) {
              _printk(&DAT_0010a3dc,*puVar8);
              iVar4 = -0x16;
              goto LAB_00102094;
            }
            uVar1 = uVar14 + 1;
            of_dma_configure_id(lVar7 + 0x10,puVar8,1,0);
            lVar10 = (-(ulong)(uVar1 >> 0x1f) & 0xffffffc000000000 | (ulong)uVar1 << 6) +
                     (long)(int)uVar1 * -8;
            *(long *)(*(long *)(puVar6 + 2) + lVar10 + 0x20) = lVar7 + 0x10;
            lVar7 = *(long *)(puVar6 + 2);
            iVar4 = of_property_read_string(puVar8,"qcom,dma-heap-name",lVar7 + lVar10 + 8);
            if (iVar4 != 0) {
LAB_00102074:
              __warn_printk("%s: Unable to populate heap %s, err: %d\n","populate_heap",puVar8[2],
                            iVar4);
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102094);
              (*pcVar3)();
            }
            iVar4 = of_property_read_variable_u32_array
                              (puVar8,"qcom,dma-heap-type",lVar7 + (long)(int)uVar1 * 0x38,1,0);
            if (iVar4 < 0) {
              _printk(&DAT_0010a3fa,"qcom,dma-heap-type",puVar8[2],iVar4);
              goto LAB_00102074;
            }
            lVar10 = of_find_property(puVar8,"qcom,uncached-heap",0);
            lVar9 = lVar7 + (long)(int)uVar1 * 0x38;
            *(bool *)(lVar9 + 0x28) = lVar10 != 0;
            iVar4 = of_property_read_variable_u32_array(puVar8,"qcom,token",lVar9 + 0x2c,1,0);
            if (-1 < iVar4) {
              iVar4 = 0;
            }
            if ((iVar4 != 0) && (iVar4 != -0x16)) goto LAB_00102074;
            iVar4 = of_property_read_variable_u32_array
                              (puVar8,"qcom,max-align",lVar7 + (long)(int)uVar1 * 0x38 + 0x30,1,0);
            if (-1 < iVar4) {
              iVar4 = 0;
            }
            if ((iVar4 != -0x16) && (iVar4 != 0)) goto LAB_00102074;
            local_b8[8] = 0;
            local_b8[9] = 0;
            local_b8[6] = 0;
            local_b8[7] = 0;
            local_b8[4] = 0;
            local_b8[5] = 0;
            local_b8[2] = 0;
            local_b8[3] = 0;
            local_b8[0] = 0;
            local_b8[1] = 0;
            iVar4 = __of_parse_phandle_with_args(puVar8,"memory-region",0,0,0,local_b8);
            lVar7 = local_b8[0];
            if ((iVar4 == 0) && (local_b8[0] != 0)) {
              lVar9 = *(long *)(puVar6 + 2);
              lVar13 = *(long *)(lVar9 + (long)(int)uVar1 * 0x38 + 0x20);
              lVar10 = of_reserved_mem_lookup(local_b8[0]);
              if (lVar10 == 0) {
                _dev_err(lVar13,"Failed to find reserved memory region\n");
                iVar4 = -0x16;
              }
              else {
                if ((*(long *)(lVar10 + 0x18) == 0) ||
                   (iVar4 = of_reserved_mem_device_init_by_idx
                                      (lVar13,*(undefined8 *)(lVar13 + 0x2e8),0), iVar4 == 0)) {
                  lVar9 = lVar9 + (long)(int)uVar1 * 0x38;
                  *(undefined8 *)(lVar9 + 0x10) = *(undefined8 *)(lVar10 + 0x20);
                  *(undefined8 *)(lVar9 + 0x18) = *(undefined8 *)(lVar10 + 0x28);
                  lVar7 = of_find_property(lVar7,"no-map",0);
                  *(bool *)(lVar9 + 0x29) = lVar7 != 0;
                  goto LAB_00101eb0;
                }
                _dev_err(lVar13,"Failed to initialize memory region rc: %d\n",iVar4);
              }
LAB_00102094:
              lVar7 = *(long *)(puVar6 + 2);
              if (-1 < (int)uVar14) {
                do {
                  lVar10 = *(long *)(lVar7 + (ulong)uVar14 * 0x38 + 0x20);
                  local_b8[8] = 0;
                  local_b8[9] = 0;
                  local_b8[6] = 0;
                  local_b8[7] = 0;
                  local_b8[4] = 0;
                  local_b8[5] = 0;
                  local_b8[2] = 0;
                  local_b8[3] = 0;
                  local_b8[0] = 0;
                  local_b8[1] = 0;
                  iVar5 = __of_parse_phandle_with_args
                                    (*(undefined8 *)(lVar10 + 0x2e8),"memory-region",0,0,0,local_b8)
                  ;
                  if (iVar5 == 0 && local_b8[0] != 0) {
                    of_reserved_mem_device_release(lVar10);
                  }
                  uVar14 = uVar14 - 1;
                } while (-1 < (int)uVar14);
                lVar7 = *(long *)(puVar6 + 2);
              }
              kfree(lVar7);
              kfree(puVar6);
              puVar6 = (uint *)(long)iVar4;
              break;
            }
LAB_00101eb0:
            puVar8 = (undefined8 *)of_get_next_available_child(uVar11,puVar8);
            uVar14 = uVar14 + 1;
          } while (puVar8 != (undefined8 *)0x0);
        }
        goto LAB_00102188;
      }
    }
    else {
      puVar6[2] = 0;
      puVar6[3] = 0;
    }
    kfree(puVar6);
  }
  puVar6 = (uint *)0xfffffffffffffff4;
LAB_00102188:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar6;
}



//------------------------------------------------------------
// proxy_invalid_map @ 001021cc size=32
// signature: undefined proxy_invalid_map(void)
// callers: [qcom_sg_map_dma_buf]
//------------------------------------------------------------

void proxy_invalid_map(void)

{
  code *pcVar1;
  
  __warn_printk("Trying to map with SMMU proxy driver when it has not fully probed!\n");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1021ec);
  (*pcVar1)();
}



//------------------------------------------------------------
// proxy_invalid_unmap @ 001021fc size=28
// signature: undefined proxy_invalid_unmap(void)
// callers: [qcom_sg_unmap_dma_buf]
//------------------------------------------------------------

void proxy_invalid_unmap(void)

{
  code *pcVar1;
  
  __warn_printk("Trying to unmap with SMMU proxy driver when it has not fully probed!\n");
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102218);
  (*pcVar1)();
}



//------------------------------------------------------------
// qcom_sg_attach @ 00102228 size=340
// signature: undefined qcom_sg_attach(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_sg_attach(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  ulong *puVar10;
  ulong *puVar11;
  uint uVar12;
  
  lVar7 = *(long *)(param_1 + 0xa0);
  puVar4 = (undefined8 *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x28);
  if (puVar4 != (undefined8 *)0x0) {
    puVar5 = (undefined8 *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x10);
    if (puVar5 != (undefined8 *)0x0) {
      iVar3 = sg_alloc_table(puVar5,*(undefined4 *)(lVar7 + 0x5c),0xcc0);
      if (iVar3 == 0) {
        if (*(int *)(lVar7 + 0x5c) != 0) {
          uVar12 = 0;
          puVar11 = *(ulong **)(lVar7 + 0x50);
          puVar10 = (ulong *)*puVar5;
          do {
            uVar6 = puVar11[1];
            uVar2 = *(undefined4 *)((long)puVar11 + 0xc);
            *puVar10 = *puVar11 & 0xfffffffffffffffc | *puVar10 & 3;
            *(int *)(puVar10 + 1) = (int)uVar6;
            *(undefined4 *)((long)puVar10 + 0xc) = uVar2;
            puVar10 = (ulong *)sg_next(puVar10);
            uVar12 = uVar12 + 1;
            puVar11 = (ulong *)sg_next(puVar11);
          } while (uVar12 < *(uint *)(lVar7 + 0x5c));
        }
        if (puVar5 < (undefined8 *)0xfffffffffffff001) {
          puVar1 = puVar4 + 2;
          *puVar4 = *(undefined8 *)(param_2 + 8);
          puVar4[1] = puVar5;
          puVar4[2] = puVar1;
          puVar4[3] = puVar1;
          *(undefined1 *)(puVar4 + 4) = 0;
          *(undefined8 **)(param_2 + 0x40) = puVar4;
          mutex_lock(lVar7 + 0x18);
          plVar8 = (long *)(lVar7 + 8);
          lVar9 = *plVar8;
          uVar6 = __list_add_valid(puVar1,plVar8,lVar9);
          if ((uVar6 & 1) != 0) {
            *(undefined8 **)(lVar9 + 8) = puVar1;
            puVar4[2] = lVar9;
            puVar4[3] = plVar8;
            *plVar8 = (long)puVar1;
          }
          mutex_unlock(lVar7 + 0x18);
          return 0;
        }
      }
      else {
        kfree(puVar5);
      }
    }
    kfree(puVar4);
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// qcom_sg_detach @ 00102380 size=128
// signature: undefined qcom_sg_detach(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_detach(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_2 + 0x40);
  lVar1 = *(long *)(param_1 + 0xa0) + 0x18;
  mutex_lock(lVar1);
  uVar4 = __list_del_entry_valid(lVar5 + 0x10);
  if ((uVar4 & 1) != 0) {
    lVar2 = *(long *)(lVar5 + 0x10);
    plVar3 = *(long **)(lVar5 + 0x18);
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
  }
  *(undefined8 *)(lVar5 + 0x10) = 0xdead000000000100;
  *(undefined8 *)(lVar5 + 0x18) = 0xdead000000000122;
  mutex_unlock(lVar1);
  sg_free_table(*(undefined8 *)(lVar5 + 8));
  kfree(*(undefined8 *)(lVar5 + 8));
  kfree(lVar5);
  return;
}



//------------------------------------------------------------
// qcom_sg_map_dma_buf @ 00102404 size=328
// signature: undefined qcom_sg_map_dma_buf(void)
// callers: []
//------------------------------------------------------------

undefined8 * qcom_sg_map_dma_buf(long *param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  
  lVar1 = param_1[8];
  uVar7 = param_1[9];
  lVar8 = *(long *)(*param_1 + 0xa0);
  puVar5 = *(undefined8 **)(lVar1 + 8);
  uVar6 = *(undefined8 *)(lVar8 + 0x78);
  if ((smmu_proxy_callback_ops_0 != (undefined *)0x0) && (((uint)uVar7 >> 0x12 & 1) != 0)) {
    if (*(int *)(smmu_proxy_callback_ops_0 + -4) != 0x1d544ccd) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10246c);
      (*pcVar2)();
    }
    iVar3 = (*(code *)smmu_proxy_callback_ops_0)(param_1[1],puVar5);
    if (iVar3 == 0) {
      return puVar5;
    }
    return (undefined8 *)(long)iVar3;
  }
  mutex_lock(lVar8 + 0x18);
  mem_buf_vmperm_pin(uVar6);
  if ((*(char *)(lVar8 + 0x70) != '\0') || (uVar4 = mem_buf_vmperm_can_cmo(uVar6), (uVar4 & 1) == 0)
     ) {
    uVar7 = uVar7 | 0x20;
  }
  if (((uint)uVar7 >> 0x11 & 1) == 0) {
    if (*(char *)(lVar1 + 0x20) == '\0') {
      iVar3 = dma_map_sgtable(param_1[1],puVar5,param_2,uVar7);
      if (iVar3 == 0) {
LAB_001024f4:
        *(undefined1 *)(lVar1 + 0x20) = 1;
        goto LAB_0010251c;
      }
    }
    else {
      _dev_err(param_1[1],"Error: Dma-buf is already mapped!\n");
      iVar3 = -0x10;
    }
  }
  else {
    iVar3 = msm_dma_map_sg_attrs
                      (param_1[1],*puVar5,*(undefined4 *)((long)puVar5 + 0xc),param_2,*param_1,uVar7
                      );
    if (-1 < iVar3) {
      if (iVar3 != 0) {
        *(int *)(puVar5 + 1) = iVar3;
        goto LAB_001024f4;
      }
      iVar3 = -0x16;
    }
  }
  puVar5 = (undefined8 *)(long)iVar3;
  mem_buf_vmperm_unpin(uVar6);
LAB_0010251c:
  mutex_unlock(lVar8 + 0x18);
  return puVar5;
}



//------------------------------------------------------------
// qcom_sg_unmap_dma_buf @ 00102550 size=264
// signature: undefined qcom_sg_unmap_dma_buf(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_unmap_dma_buf(long *param_1,undefined8 *param_2,undefined4 param_3)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  uVar3 = param_1[9];
  if (smmu_proxy_callback_ops_1 == (undefined *)0x0 || (uVar3 & 0x40000) == 0) {
    lVar6 = *(long *)(*param_1 + 0xa0);
    lVar5 = param_1[8];
    uVar4 = *(undefined8 *)(lVar6 + 0x78);
    mutex_lock(lVar6 + 0x18);
    if ((*(char *)(lVar6 + 0x70) != '\0') ||
       (uVar2 = mem_buf_vmperm_can_cmo(uVar4), (uVar2 & 1) == 0)) {
      uVar3 = uVar3 | 0x20;
    }
    *(undefined1 *)(lVar5 + 0x20) = 0;
    if (((uint)uVar3 >> 0x11 & 1) == 0) {
      dma_unmap_sg_attrs(param_1[1],*param_2,*(undefined4 *)((long)param_2 + 0xc),param_3,uVar3);
    }
    else {
      msm_dma_unmap_sg_attrs
                (param_1[1],*param_2,*(undefined4 *)(param_2 + 1),param_3,*param_1,uVar3);
    }
    mem_buf_vmperm_unpin(uVar4);
    mutex_unlock(lVar6 + 0x18);
  }
  else {
    if (*(int *)(smmu_proxy_callback_ops_1 + -4) != 0x6ac3cc16) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10260c);
      (*pcVar1)();
    }
    (*(code *)smmu_proxy_callback_ops_1)(param_1[1],param_2);
  }
  return;
}



//------------------------------------------------------------
// qcom_sg_dma_buf_begin_cpu_access @ 0010265c size=144
// signature: undefined qcom_sg_dma_buf_begin_cpu_access(void)
// callers: [ubwcp_dma_buf_begin_cpu_access]
//------------------------------------------------------------

undefined8 qcom_sg_dma_buf_begin_cpu_access(long param_1,undefined4 param_2)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(param_1 + 0xa0);
  if (*(char *)(lVar2 + 0x70) == '\0') {
    mutex_lock(lVar2 + 0x18);
    uVar1 = mem_buf_vmperm_can_cmo(*(undefined8 *)(lVar2 + 0x78));
    if ((uVar1 & 1) != 0) {
      for (puVar3 = *(undefined8 **)(lVar2 + 8); puVar3 != (undefined8 *)(lVar2 + 8);
          puVar3 = (undefined8 *)*puVar3) {
        if (*(char *)(puVar3 + 2) != '\0') {
          dma_sync_sg_for_cpu(puVar3[-2],*(undefined8 *)puVar3[-1],
                              *(undefined4 *)((long)puVar3[-1] + 0xc),param_2);
        }
      }
    }
    mutex_unlock(lVar2 + 0x18);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_sg_dma_buf_end_cpu_access @ 001026f0 size=144
// signature: undefined qcom_sg_dma_buf_end_cpu_access(void)
// callers: [ubwcp_dma_buf_end_cpu_access]
//------------------------------------------------------------

undefined8 qcom_sg_dma_buf_end_cpu_access(long param_1,undefined4 param_2)

{
  ulong uVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(param_1 + 0xa0);
  if (*(char *)(lVar2 + 0x70) == '\0') {
    mutex_lock(lVar2 + 0x18);
    uVar1 = mem_buf_vmperm_can_cmo(*(undefined8 *)(lVar2 + 0x78));
    if ((uVar1 & 1) != 0) {
      for (puVar3 = *(undefined8 **)(lVar2 + 8); puVar3 != (undefined8 *)(lVar2 + 8);
          puVar3 = (undefined8 *)*puVar3) {
        if (*(char *)(puVar3 + 2) != '\0') {
          dma_sync_sg_for_device
                    (puVar3[-2],*(undefined8 *)puVar3[-1],*(undefined4 *)((long)puVar3[-1] + 0xc),
                     param_2);
        }
      }
    }
    mutex_unlock(lVar2 + 0x18);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_sg_dma_buf_begin_cpu_access_partial @ 00102784 size=216
// signature: undefined qcom_sg_dma_buf_begin_cpu_access_partial(void)
// callers: [ubwcp_dma_buf_begin_cpu_access_partial]
//------------------------------------------------------------

undefined4
qcom_sg_dma_buf_begin_cpu_access_partial
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  lVar3 = *(long *)(param_1 + 0xa0);
  if (*(char *)(lVar3 + 0x70) != '\0') {
    return 0;
  }
  mutex_lock(lVar3 + 0x18);
  uVar2 = mem_buf_vmperm_can_cmo(*(undefined8 *)(lVar3 + 0x78));
  if ((uVar2 & 1) != 0) {
    plVar4 = (long *)(lVar3 + 8);
    plVar5 = (long *)*plVar4;
    if (plVar5 != plVar4) {
      uVar1 = 0;
      do {
        if ((char)plVar5[2] != '\0') {
          uVar1 = sgl_sync_range(plVar5[-2],*(undefined8 *)plVar5[-1],
                                 *(undefined4 *)(plVar5[-1] + 0xc),param_3,param_4,param_2,1);
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != plVar4);
      goto LAB_00102834;
    }
  }
  uVar1 = 0;
LAB_00102834:
  mutex_unlock(lVar3 + 0x18);
  return uVar1;
}



//------------------------------------------------------------
// sgl_sync_range @ 0010285c size=456
// signature: undefined sgl_sync_range(void)
// callers: [qcom_sg_dma_buf_end_cpu_access_partial, qcom_sg_dma_buf_begin_cpu_access_partial]
//------------------------------------------------------------

undefined8
sgl_sync_range(long *param_1,long param_2,int param_3,ulong param_4,ulong param_5,undefined4 param_6
              ,uint param_7)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  
  if (param_3 != 0) {
    if (((*(int *)(param_2 + 0x18) == 0) || (lVar4 = sg_next(param_2), param_3 == 1)) ||
       (*(int *)(lVar4 + 0x18) == 0)) {
      uVar8 = (ulong)*(uint *)(param_2 + 0xc);
      lVar4 = *(long *)(param_2 + 0x10);
      if (param_4 < uVar8) {
        uVar6 = (ulong)(*(uint *)(param_2 + 0xc) - (int)param_4);
        uVar7 = param_5;
        if (uVar6 <= param_5) {
          uVar7 = uVar6;
        }
        if ((param_7 & 1) == 0) {
          dma_sync_single_for_device(param_1,lVar4 + (param_4 & 0xffffffff),uVar7,param_6);
        }
        else {
          dma_sync_single_for_cpu();
        }
        param_5 = param_5 - uVar7;
        if (param_5 == 0) {
          return 0;
        }
        param_4 = uVar7 + param_4;
        uVar7 = (ulong)*(uint *)(param_2 + 0xc);
      }
      else {
        uVar7 = uVar8;
      }
      lVar5 = sg_next(param_2);
      param_3 = param_3 + -1;
      if (param_3 != 0) {
        lVar4 = lVar4 + uVar7;
        do {
          uVar2 = *(uint *)(lVar5 + 0xc);
          uVar1 = uVar2 + (int)uVar8;
          uVar8 = (ulong)uVar1;
          if (param_4 < uVar8) {
            uVar1 = uVar1 - (int)param_4;
            uVar7 = param_5;
            if (uVar1 <= param_5) {
              uVar7 = (ulong)uVar1;
            }
            if ((param_7 & 1) == 0) {
              dma_sync_single_for_device(param_1,lVar4 + (ulong)(uVar2 - uVar1),uVar7,param_6);
            }
            else {
              dma_sync_single_for_cpu();
            }
            param_5 = param_5 - uVar7;
            if (param_5 == 0) {
              return 0;
            }
            param_4 = uVar7 + param_4;
            uVar2 = *(uint *)(lVar5 + 0xc);
          }
          lVar4 = lVar4 + (ulong)uVar2;
          lVar5 = sg_next(lVar5);
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
    }
    else if (param_1[0x52] != 0) {
      iVar3 = ___ratelimit(sgl_sync_range__rs,"sgl_sync_range");
      if (iVar3 == 0) {
        return 0xffffffea;
      }
      lVar4 = param_1[0xe];
      if (lVar4 == 0) {
        lVar4 = *param_1;
      }
      _printk(&DAT_0010a378,lVar4);
      return 0xffffffea;
    }
  }
  return 0;
}



//------------------------------------------------------------
// qcom_sg_dma_buf_end_cpu_access_partial @ 00102a28 size=216
// signature: undefined qcom_sg_dma_buf_end_cpu_access_partial(void)
// callers: [ubwcp_dma_buf_end_cpu_access_partial]
//------------------------------------------------------------

undefined4
qcom_sg_dma_buf_end_cpu_access_partial
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  lVar3 = *(long *)(param_1 + 0xa0);
  if (*(char *)(lVar3 + 0x70) != '\0') {
    return 0;
  }
  mutex_lock(lVar3 + 0x18);
  uVar2 = mem_buf_vmperm_can_cmo(*(undefined8 *)(lVar3 + 0x78));
  if ((uVar2 & 1) != 0) {
    plVar4 = (long *)(lVar3 + 8);
    plVar5 = (long *)*plVar4;
    if (plVar5 != plVar4) {
      uVar1 = 0;
      do {
        if ((char)plVar5[2] != '\0') {
          uVar1 = sgl_sync_range(plVar5[-2],*(undefined8 *)plVar5[-1],
                                 *(undefined4 *)(plVar5[-1] + 0xc),param_3,param_4,param_2,0);
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != plVar4);
      goto LAB_00102ad8;
    }
  }
  uVar1 = 0;
LAB_00102ad8:
  mutex_unlock(lVar3 + 0x18);
  return uVar1;
}



//------------------------------------------------------------
// qcom_sg_mmap @ 00102b04 size=368
// signature: undefined qcom_sg_mmap(void)
// callers: [ubwcp_mmap]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_sg_mmap(long param_1,ulong *param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong *puVar6;
  long lVar7;
  uint uVar8;
  
  lVar7 = *(long *)(param_1 + 0xa0);
  uVar4 = *param_2;
  uVar5 = param_2[0x10];
  mem_buf_vmperm_pin(*(undefined8 *)(lVar7 + 0x78));
  uVar2 = mem_buf_vmperm_can_mmap(*(undefined8 *)(lVar7 + 0x78),param_2);
  if ((uVar2 & 1) == 0) {
    iVar1 = -1;
LAB_00102c38:
    mem_buf_vmperm_unpin(*(undefined8 *)(lVar7 + 0x78));
  }
  else {
    param_2[0xf] = (ulong)&qcom_sg_vm_ops;
    param_2[0x12] = *(ulong *)(lVar7 + 0x78);
    if (*(char *)(lVar7 + 0x70) != '\0') {
      param_2[3] = param_2[3] & 0xffffffffffffffe3 | 0x60000000000008;
    }
    if (*(int *)(lVar7 + 0x58) != 0) {
      uVar8 = 0;
      puVar6 = *(ulong **)(lVar7 + 0x50);
      uVar2 = uVar5 << 0xc;
      do {
        uVar3 = (ulong)*(uint *)((long)puVar6 + 0xc);
        uVar5 = uVar2 - uVar3;
        if (uVar2 < uVar3) {
          uVar5 = uVar3 - uVar2;
          if (param_2[1] - uVar4 <= uVar3 - uVar2) {
            uVar5 = param_2[1] - uVar4;
          }
          iVar1 = remap_pfn_range(param_2,uVar4,
                                  (long)((*puVar6 & 0xfffffffffffffffc) + (uVar2 >> 0xc) * 0x40 +
                                         (_memstart_addr >> 0xc) * 0x40 + 0x200000000) >> 6,uVar5,
                                  param_2[3]);
          if (iVar1 != 0) goto LAB_00102c38;
          uVar4 = uVar5 + uVar4;
          if (param_2[1] <= uVar4) break;
          uVar5 = 0;
        }
        uVar8 = uVar8 + 1;
        puVar6 = (ulong *)sg_next(puVar6);
        uVar2 = uVar5;
      } while (uVar8 < *(uint *)(lVar7 + 0x58));
    }
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_sg_do_vmap @ 00102c78 size=356
// signature: undefined qcom_sg_do_vmap(void)
// callers: [qcom_sg_vmap]
//------------------------------------------------------------

void qcom_sg_do_vmap(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong *local_60;
  ulong local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  uVar1 = *(long *)(param_1 + 0x48) + 0xfff;
  uVar8 = -(uVar1 >> 0x2b & 1) & 0xfffffff800000000 | (uVar1 >> 0xc & 0xffffffff) << 3;
  lVar4 = vmalloc(uVar8);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = (ulong *)0x0;
  if (lVar4 == 0) {
    lVar4 = -0xc;
  }
  else {
    uVar2 = 0x68000000000703;
    if (arm64_use_ng_mappings != '\0') {
      uVar2 = 0x68000000000f03;
    }
    if (*(char *)(param_1 + 0x70) != '\0') {
      uVar2 = uVar2 | 0x60000000000008;
    }
    __sg_page_iter_start
              (&local_60,*(undefined8 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x5c),0);
    uVar5 = __sg_page_iter_next(&local_60);
    if ((uVar5 & 1) != 0) {
      uVar5 = 0;
      do {
        if ((long)(uVar1 * 0x100000) >> 0x20 <= (long)uVar5 >> 3) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102d70);
          (*pcVar3)();
        }
        if (((long)uVar5 < 0) || (uVar8 <= uVar5)) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x102d78);
          (*pcVar3)();
        }
        *(ulong *)(lVar4 + uVar5) =
             (*local_60 & 0xfffffffffffffffc) + (local_58 & 0xffffffff) * 0x40;
        uVar6 = __sg_page_iter_next(&local_60);
        uVar5 = uVar5 + 8;
      } while ((uVar6 & 1) != 0);
    }
    lVar7 = vmap(lVar4,uVar1 >> 0xc & 0xffffffff,4,uVar2);
    vfree(lVar4);
    lVar4 = -0xc;
    if (lVar7 != 0) {
      lVar4 = lVar7;
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_sg_vmap @ 00102de4 size=200
// signature: undefined qcom_sg_vmap(void)
// callers: [ubwcp_vmap]
//------------------------------------------------------------

ulong qcom_sg_vmap(long param_1,ulong *param_2)

{
  ulong uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa0);
  mem_buf_vmperm_pin(*(undefined8 *)(lVar2 + 0x78));
  uVar1 = mem_buf_vmperm_can_vmap(*(undefined8 *)(lVar2 + 0x78));
  if ((uVar1 & 1) == 0) {
    mem_buf_vmperm_unpin(*(undefined8 *)(lVar2 + 0x78));
    uVar1 = 0xffffffff;
    goto LAB_00102e94;
  }
  mutex_lock(lVar2 + 0x18);
  if (*(int *)(lVar2 + 0x60) == 0) {
    uVar1 = qcom_sg_do_vmap(lVar2);
    if (uVar1 < 0xfffffffffffff001) {
      *(ulong *)(lVar2 + 0x68) = uVar1;
      *(int *)(lVar2 + 0x60) = *(int *)(lVar2 + 0x60) + 1;
      *param_2 = uVar1;
      goto LAB_00102e88;
    }
    mem_buf_vmperm_unpin(*(undefined8 *)(lVar2 + 0x78));
  }
  else {
    *(int *)(lVar2 + 0x60) = *(int *)(lVar2 + 0x60) + 1;
    *param_2 = *(ulong *)(lVar2 + 0x68);
LAB_00102e88:
    uVar1 = 0;
    *(undefined1 *)(param_2 + 1) = 0;
  }
  mutex_unlock(lVar2 + 0x18);
LAB_00102e94:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_sg_vunmap @ 00102eb0 size=108
// signature: undefined qcom_sg_vunmap(void)
// callers: [ubwcp_vunmap]
//------------------------------------------------------------

void qcom_sg_vunmap(long param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xa0);
  mutex_lock(lVar2 + 0x18);
  iVar1 = *(int *)(lVar2 + 0x60) + -1;
  *(int *)(lVar2 + 0x60) = iVar1;
  if (iVar1 == 0) {
    vunmap(*(undefined8 *)(lVar2 + 0x68));
    *(undefined8 *)(lVar2 + 0x68) = 0;
  }
  mem_buf_vmperm_unpin(*(undefined8 *)(lVar2 + 0x78));
  mutex_unlock(lVar2 + 0x18);
  *param_2 = 0;
  param_2[1] = 0;
  return;
}



//------------------------------------------------------------
// qcom_sg_buffer_init @ 00102f20 size=80
// signature: undefined qcom_sg_buffer_init(void)
// callers: [__carveout_heap_allocate, system_heap_allocate, system_qcom_sg_buffer_alloc, cma_heap_allocate]
//------------------------------------------------------------

void qcom_sg_buffer_init(long param_1)

{
  *(long *)(param_1 + 8) = param_1 + 8;
  *(long *)(param_1 + 0x10) = param_1 + 8;
  __mutex_init(param_1 + 0x18,"&buffer->lock",&qcom_sg_buffer_init___key);
  *(undefined4 *)(param_1 + 0xa8) = 1;
  return;
}



//------------------------------------------------------------
// qcom_sg_release @ 00102f74 size=84
// signature: undefined qcom_sg_release(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_release(long param_1)

{
  code *pcVar1;
  
  mem_buf_vmperm_free(*(undefined8 *)(param_1 + -0x30));
  pcVar1 = *(code **)(param_1 + -8);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != -0x7ec62ade) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102fb4);
      (*pcVar1)();
    }
    (*pcVar1)(param_1 + -0xa8);
  }
  return;
}



//------------------------------------------------------------
// qcom_sg_dmabuf_release @ 00102fcc size=172
// signature: undefined qcom_sg_dmabuf_release(void)
// callers: [ubwcp_release]
//------------------------------------------------------------

void qcom_sg_dmabuf_release(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0xa0);
  mem_buf_vmperm_try_reclaim(*(undefined8 *)(lVar6 + 0x78),0);
  msm_dma_buf_freed(lVar6);
  piVar1 = (int *)(lVar6 + 0xa8);
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
    mem_buf_vmperm_free(*(undefined8 *)(lVar6 + 0x78));
    pcVar5 = *(code **)(lVar6 + 0xa0);
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(pcVar5 + -4) != -0x7ec62ade) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10303c);
        (*pcVar5)();
      }
      (*pcVar5)(lVar6);
    }
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
  return;
}



//------------------------------------------------------------
// qcom_sg_lookup_vmperm @ 0010308c size=12
// signature: undefined qcom_sg_lookup_vmperm(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_sg_lookup_vmperm(long param_1)

{
  return *(undefined8 *)(*(long *)(param_1 + 0xa0) + 0x78);
}



//------------------------------------------------------------
// qti_smmu_proxy_register_callbacks @ 0010309c size=28
// signature: undefined qti_smmu_proxy_register_callbacks(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_smmu_proxy_register_callbacks(undefined *param_1,undefined *param_2)

{
  smmu_proxy_callback_ops_0 = param_1;
  smmu_proxy_callback_ops_1 = param_2;
  return 0;
}



//------------------------------------------------------------
// qcom_sg_vm_ops_open @ 001030bc size=32
// signature: undefined qcom_sg_vm_ops_open(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_vm_ops_open(long param_1)

{
  mem_buf_vmperm_pin(*(undefined8 *)(param_1 + 0x90));
  return;
}



//------------------------------------------------------------
// qcom_sg_vm_ops_close @ 001030e0 size=32
// signature: undefined qcom_sg_vm_ops_close(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_vm_ops_close(long param_1)

{
  mem_buf_vmperm_unpin(*(undefined8 *)(param_1 + 0x90));
  return;
}



//------------------------------------------------------------
// dynamic_pool_gfp_zone @ 00103104 size=24
// signature: undefined dynamic_pool_gfp_zone(void)
// callers: []
//------------------------------------------------------------

uint dynamic_pool_gfp_zone(uint param_1)

{
  return 0x250015U >> (ulong)((param_1 & 0xf) << 1) & 3;
}



//------------------------------------------------------------
// dynamic_pool_zone_watermark_ok_safe @ 00103120 size=408
// signature: undefined dynamic_pool_zone_watermark_ok_safe(void)
// callers: [system_heap_refill_worker]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dynamic_pool_zone_watermark_ok_safe(long param_1,uint param_2,long param_3,uint param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  
  uVar4 = *(ulong *)(param_1 + 0x5c0);
  if ((long)uVar4 < 1) {
    uVar4 = 0;
  }
  if ((*(ulong *)(param_1 + 0x580) != 0) && (uVar4 < *(ulong *)(param_1 + 0x580))) {
    iVar3 = 0;
    uVar4 = *(ulong *)(param_1 + 0x5c0);
    while (uVar2 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)iVar3), uVar2 < _nr_cpu_ids)
    {
      if ((uVar2 & 0xffffffe0) != 0) goto LAB_001032b4;
      uVar4 = uVar4 + (long)*(char *)(*(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) +
                                     *(long *)(param_1 + 0x60));
      iVar3 = uVar2 + 1;
    }
    if ((long)uVar4 < 1) {
      uVar4 = 0;
    }
  }
  lVar6 = *(long *)(param_1 + 0x610);
  if (3 < param_4) {
LAB_001032b4:
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1032b8);
    (*pcVar1)();
  }
  if (lVar6 < 1) {
    lVar6 = 0;
  }
  if (*(long *)(param_1 + (ulong)param_4 * 8 + 0x30) + param_3 <
      (long)((uVar4 - (*(long *)(param_1 + 0x28) + (long)~(-1 << (ulong)(param_2 & 0x1f)))) - lVar6)
     ) {
    if (param_2 == 0) {
      return 1;
    }
    if ((int)param_2 < 0xb) {
      uVar2 = param_2;
      if (param_2 < 0xd) {
        uVar2 = 0xc;
      }
      lVar6 = (ulong)uVar2 - (ulong)param_2;
      plVar5 = (long *)(param_1 + (ulong)param_2 * 0x68 + 0x120);
      do {
        if (lVar6 == 0) goto LAB_001032b4;
        if (*plVar5 != 0) {
          if (plVar5 + -0xc != (long *)plVar5[-0xc]) {
            return 1;
          }
          if (plVar5 + -10 != (long *)plVar5[-10]) {
            return 1;
          }
          if (plVar5 + -8 != (long *)plVar5[-8]) {
            return 1;
          }
        }
        param_2 = param_2 + 1;
        plVar5 = plVar5 + 0xd;
        lVar6 = lVar6 + -1;
      } while ((int)param_2 < 0xb);
    }
  }
  return 0;
}



//------------------------------------------------------------
// qcom_system_heap_free @ 001032bc size=56
// signature: undefined qcom_system_heap_free(void)
// callers: [ubwcp_allocate]
//------------------------------------------------------------

void qcom_system_heap_free(long param_1)

{
  deferred_free(param_1 + 0x80,system_heap_buf_free,*(long *)(param_1 + 0x48) + 0xfffU >> 0xc);
  return;
}



//------------------------------------------------------------
// system_heap_buf_free @ 001032f8 size=804
// signature: undefined system_heap_buf_free(void)
// callers: []
//------------------------------------------------------------

void system_heap_buf_free(long param_1,int param_2)

{
  int *piVar1;
  undefined8 uVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  void *pvVar10;
  ulong *puVar11;
  undefined1 uVar12;
  uint uVar13;
  long lVar14;
  ulong uVar15;
  ulong *puVar16;
  ulong *puVar17;
  uint uVar18;
  ulong *local_188;
  ulong local_180;
  undefined8 uStack_178;
  long local_170 [34];
  
  lVar7 = sp_el0;
  local_170[0x20] = *(long *)(lVar7 + 0x638);
  lVar7 = dma_heap_get_drvdata(*(undefined8 *)(param_1 + -0x80));
  if (param_2 == 0) {
    local_180 = 0;
    uStack_178 = 0;
    local_188 = (ulong *)0x0;
    local_170[0x1e] = 0;
    local_170[0x1f] = 0;
    local_170[0x1c] = 0;
    local_170[0x1d] = 0;
    local_170[0x1a] = 0;
    local_170[0x1b] = 0;
    local_170[0x18] = 0;
    local_170[0x19] = 0;
    local_170[0x16] = 0;
    local_170[0x17] = 0;
    local_170[0x14] = 0;
    local_170[0x15] = 0;
    local_170[0x12] = 0;
    local_170[0x13] = 0;
    local_170[0x10] = 0;
    local_170[0x11] = 0;
    local_170[0xe] = 0;
    local_170[0xf] = 0;
    local_170[0xc] = 0;
    local_170[0xd] = 0;
    local_170[10] = 0;
    local_170[0xb] = 0;
    local_170[8] = 0;
    local_170[9] = 0;
    local_170[6] = 0;
    local_170[7] = 0;
    local_170[4] = 0;
    local_170[5] = 0;
    local_170[2] = 0;
    local_170[3] = 0;
    local_170[0] = 0;
    local_170[1] = 0;
    __sg_page_iter_start
              (&local_188,*(undefined8 *)(param_1 + -0x30),*(undefined4 *)(param_1 + -0x24),0);
    uVar8 = __sg_page_iter_next(&local_188);
    if ((uVar8 & 1) != 0) {
      uVar8 = 0;
      uVar15 = 1;
      do {
        local_170[uVar8] = (*local_188 & 0xfffffffffffffffc) + (local_180 & 0xffffffff) * 0x40;
        if ((int)uVar15 == 0x20) {
          uVar2 = 0x68000000000703;
          if (arm64_use_ng_mappings != '\0') {
            uVar2 = 0x68000000000f03;
          }
          pvVar10 = (void *)vmap(local_170,0x20,4,uVar2);
          if (pvVar10 == (void *)0x0) goto LAB_00103498;
          memset(pvVar10,0,0x20000);
          vunmap(pvVar10);
          uVar15 = __sg_page_iter_next(&local_188);
          uVar8 = 0;
          if ((uVar15 & 1) == 0) break;
        }
        else {
          uVar9 = __sg_page_iter_next(&local_188);
          uVar8 = uVar15;
          if ((uVar9 & 1) == 0) {
            uVar2 = 0x68000000000703;
            if (arm64_use_ng_mappings != '\0') {
              uVar2 = 0x68000000000f03;
            }
            pvVar10 = (void *)vmap(local_170,uVar15,4,uVar2);
            if (pvVar10 != (void *)0x0) {
              memset(pvVar10,0,uVar15 << 0xc);
              vunmap(pvVar10);
              break;
            }
LAB_00103498:
            param_2 = 1;
            goto LAB_0010349c;
          }
        }
        uVar15 = (ulong)((uint)uVar8 + 1);
        if (0x1f < (uint)uVar8) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x103634);
          (*pcVar6)();
        }
      } while( true );
    }
    param_2 = 0;
  }
LAB_0010349c:
  if (*(int *)(param_1 + -0x28) != 0) {
    uVar18 = 0;
    puVar16 = *(ulong **)(param_1 + -0x30);
    do {
      puVar17 = (ulong *)(*puVar16 & 0xfffffffffffffffc);
      if (param_2 == 1) {
LAB_00103578:
        uVar13 = (uint)*puVar17;
joined_r0x0010357c:
        if ((uVar13 >> 0x10 & 1) == 0) {
          uVar12 = 0;
        }
        else {
          uVar12 = *(undefined1 *)((long)puVar17 + 0x51);
        }
        __free_pages(puVar17,uVar12);
      }
      else {
        uVar8 = *puVar17;
        if ((((uint)uVar8 >> 0x10 & 1) == 0) || (*(char *)((long)puVar17 + 0x51) != '\t')) {
          uVar8 = *puVar17;
          if ((((uint)uVar8 >> 0x10 & 1) == 0) || (*(char *)((long)puVar17 + 0x51) != '\x04')) {
            uVar8 = *puVar17;
            if (((uint)uVar8 >> 0x10 & 1) == 0) {
              lVar14 = 2;
            }
            else {
              lVar14 = 2;
              if (*(char *)((long)puVar17 + 0x51) != '\0') {
                lVar14 = 3;
              }
            }
          }
          else {
            lVar14 = 1;
          }
        }
        else {
          lVar14 = 0;
        }
        if (uVar8 >> 0x3e == 2) {
          puVar11 = puVar17;
          if ((puVar17[1] & 1) != 0) {
            puVar11 = (ulong *)(puVar17[1] - 1);
          }
          piVar1 = (int *)((long)puVar11 + 0x34);
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
          if (iVar3 + -1 != 0) goto LAB_00103578;
          __folio_put();
          uVar13 = (uint)*puVar17;
          goto joined_r0x0010357c;
        }
        dynamic_page_pool_free(*(undefined8 *)(*(long *)(lVar7 + 8) + lVar14 * 8),puVar17);
      }
      uVar18 = uVar18 + 1;
      puVar16 = (ulong *)sg_next(puVar16);
    } while (uVar18 < *(uint *)(param_1 + -0x28));
  }
  sg_free_table((undefined8 *)(param_1 + -0x30));
  kfree((undefined8 *)(param_1 + -0x80));
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_170[0x20]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_sys_heap_alloc_largest_available @ 0010363c size=608
// signature: undefined qcom_sys_heap_alloc_largest_available(void)
// callers: [system_heap_allocate, system_qcom_sg_buffer_alloc, secure_system_heap_prefetch_work]
//------------------------------------------------------------

long qcom_sys_heap_alloc_largest_available(long *param_1,ulong param_2,uint param_3,byte param_4)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  long *plVar5;
  
  if ((0x1fffff < param_2) && (8 < param_3)) {
    uVar1 = _raw_spin_lock_irqsave(*param_1 + 0x40);
    piVar4 = (int *)*param_1;
    if ((*piVar4 == 0) && (piVar4[1] == 0)) {
      lVar2 = 0;
    }
    else {
      lVar2 = dynamic_page_pool_remove(piVar4,*piVar4 != 0);
    }
    _raw_spin_unlock_irqrestore(*param_1 + 0x40,uVar1);
    lVar3 = -0x5f;
    if ((lVar2 == 0 & param_4) == 0) {
      lVar3 = lVar2;
    }
    if ((lVar2 == 0) && ((param_4 & 1) == 0)) {
      uVar1 = tpidr_el1;
      lVar3 = __alloc_pages(uVar1,*(undefined4 *)(*param_1 + 0x44),*(undefined4 *)(*param_1 + 0x48),
                            0,0);
      if (lVar3 == 0) goto LAB_0010374c;
    }
    plVar5 = param_1;
    goto LAB_001036fc;
  }
LAB_0010374c:
  if ((param_2 < 0x10000) || (param_3 < 4)) {
    if (param_2 < 0x1000) {
      return 0;
    }
  }
  else {
    plVar5 = param_1 + 1;
    uVar1 = _raw_spin_lock_irqsave(*plVar5 + 0x40);
    piVar4 = (int *)*plVar5;
    if ((*piVar4 == 0) && (piVar4[1] == 0)) {
      lVar2 = 0;
    }
    else {
      lVar2 = dynamic_page_pool_remove(piVar4,*piVar4 != 0);
    }
    _raw_spin_unlock_irqrestore(*plVar5 + 0x40,uVar1);
    lVar3 = -0x5f;
    if ((lVar2 == 0 & param_4) == 0) {
      lVar3 = lVar2;
    }
    if ((lVar2 != 0) || ((param_4 & 1) != 0)) goto LAB_001036fc;
    uVar1 = tpidr_el1;
    lVar3 = __alloc_pages(uVar1,*(undefined4 *)(*plVar5 + 0x44),*(undefined4 *)(*plVar5 + 0x48),0,0)
    ;
    if (lVar3 != 0) goto LAB_001036fc;
  }
  plVar5 = param_1 + 2;
  uVar1 = _raw_spin_lock_irqsave(*plVar5 + 0x40);
  piVar4 = (int *)*plVar5;
  if ((*piVar4 == 0) && (piVar4[1] == 0)) {
    lVar2 = 0;
  }
  else {
    lVar2 = dynamic_page_pool_remove(piVar4,*piVar4 != 0);
  }
  _raw_spin_unlock_irqrestore(*plVar5 + 0x40,uVar1);
  lVar3 = -0x5f;
  if ((lVar2 == 0 & param_4) == 0) {
    lVar3 = lVar2;
  }
  if ((lVar2 == 0) && ((param_4 & 1) == 0)) {
    uVar1 = tpidr_el1;
    lVar3 = __alloc_pages(uVar1,*(undefined4 *)(*plVar5 + 0x44),*(undefined4 *)(*plVar5 + 0x48),0,0)
    ;
    if (lVar3 == 0) {
      return 0;
    }
  }
LAB_001036fc:
  lVar2 = *plVar5;
  if ((*(uint *)(lVar2 + 0x48) != 0) &&
     (*(int *)(lVar2 + 8) < (int)(0x2800L >> ((ulong)*(uint *)(lVar2 + 0x48) & 0x3f)))) {
    wake_up_process(*(undefined8 *)(lVar2 + 0x38));
  }
  return lVar3;
}



//------------------------------------------------------------
// system_qcom_sg_buffer_alloc @ 001038b0 size=808
// signature: undefined system_qcom_sg_buffer_alloc(void)
// callers: [system_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

void system_qcom_sg_buffer_alloc(undefined8 param_1,undefined8 *param_2,long param_3,uint param_4)

{
  ulong ****ppppuVar1;
  ulong ****ppppuVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  code *pcVar7;
  int iVar8;
  int *piVar9;
  undefined8 *puVar10;
  ulong uVar11;
  undefined8 uVar12;
  undefined1 uVar13;
  ulong *****pppppuVar14;
  ulong *****pppppuVar15;
  ulong *****pppppuVar16;
  ulong *puVar17;
  ulong *****pppppuVar18;
  ulong *****local_78;
  ulong *****local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  piVar9 = (int *)dma_heap_get_drvdata();
  qcom_sg_buffer_init(param_2);
  *param_2 = param_1;
  param_2[9] = param_3;
  iVar3 = *piVar9;
  iVar8 = 0;
  param_2[0x14] = qcom_system_heap_free;
  *(bool *)(param_2 + 0xe) = iVar3 != 0;
  local_78 = (ulong *****)&local_78;
  local_70 = (ulong *****)&local_78;
  if (param_3 != 0) {
    uVar13 = 9;
    puVar17 = (ulong *)sp_el0;
    do {
      if ((((*puVar17 & 1) != 0) && ((*(byte *)((long)puVar17 + 0x8c9) & 1) != 0)) ||
         (puVar10 = (undefined8 *)
                    qcom_sys_heap_alloc_largest_available
                              (*(undefined8 *)(piVar9 + 2),param_3,uVar13,param_4 & 1),
         pppppuVar16 = local_70, puVar10 == (undefined8 *)0x0)) goto LAB_001039fc;
      pppppuVar14 = (ulong *****)(puVar10 + 1);
      uVar11 = __list_add_valid(pppppuVar14,local_70,&local_78);
      if ((uVar11 & 1) != 0) {
        puVar10[1] = &local_78;
        puVar10[2] = pppppuVar16;
        local_70 = pppppuVar14;
        *pppppuVar16 = (ulong ****)pppppuVar14;
      }
      if (((uint)*puVar10 >> 0x10 & 1) == 0) {
        uVar11 = 0;
        if (((uint)*puVar10 >> 0x10 & 1) == 0) goto LAB_001039d8;
LAB_00103950:
        uVar13 = *(undefined1 *)((long)puVar10 + 0x51);
      }
      else {
        uVar11 = (ulong)*(byte *)((long)puVar10 + 0x51);
        if (((uint)*puVar10 >> 0x10 & 1) != 0) goto LAB_00103950;
LAB_001039d8:
        uVar13 = 0;
      }
      iVar8 = iVar8 + 1;
      param_3 = (-0x1000L << (uVar11 & 0x3f)) + param_3;
    } while (param_3 != 0);
  }
  puVar10 = param_2 + 10;
  iVar8 = sg_alloc_table(puVar10,iVar8,0xcc0);
  if (iVar8 == 0) {
    if ((ulong ******)local_78 != &local_78) {
      puVar17 = (ulong *)*puVar10;
      pppppuVar16 = local_78;
      do {
        pppppuVar14 = pppppuVar16 + -1;
        if (((uint)*pppppuVar14 >> 0x10 & 1) == 0) {
          uVar11 = 0;
        }
        else {
          uVar11 = (ulong)*(byte *)((long)pppppuVar16 + 0x49);
        }
        if (((ulong)pppppuVar14 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x103bf0);
          (*pcVar7)();
        }
        pppppuVar18 = (ulong *****)*pppppuVar16;
        *(undefined4 *)(puVar17 + 1) = 0;
        *(int *)((long)puVar17 + 0xc) = (int)(0x1000L << (uVar11 & 0x3f));
        *puVar17 = *puVar17 & 3 | (ulong)pppppuVar14;
        puVar17 = (ulong *)sg_next(puVar17);
        uVar11 = __list_del_entry_valid(pppppuVar16);
        if ((uVar11 & 1) != 0) {
          ppppuVar1 = *pppppuVar16;
          ppppuVar2 = pppppuVar16[1];
          ppppuVar1[1] = (ulong ***)ppppuVar2;
          *ppppuVar2 = (ulong ***)ppppuVar1;
        }
        *pppppuVar16 = (ulong ****)0xdead000000000100;
        pppppuVar16[1] = (ulong ****)0xdead000000000122;
        pppppuVar16 = pppppuVar18;
      } while ((ulong ******)pppppuVar18 != &local_78);
    }
    if (*(char *)(param_2 + 0xe) != '\0') {
      uVar12 = dma_heap_get_dev(param_1);
      dma_map_sgtable(uVar12,puVar10,0,0);
      uVar12 = dma_heap_get_dev(param_1);
      dma_unmap_sg_attrs(uVar12,param_2[10],*(undefined4 *)((long)param_2 + 0x5c),0,0);
    }
    uVar12 = 0;
  }
  else {
LAB_001039fc:
    pppppuVar16 = local_78;
    while ((ulong ******)pppppuVar16 != &local_78) {
      pppppuVar18 = (ulong *****)*pppppuVar16;
      pppppuVar14 = pppppuVar16 + -1;
      if ((ulong)*pppppuVar14 >> 0x3e == 2) {
        pppppuVar15 = pppppuVar14;
        if (((ulong)*pppppuVar16 & 1) != 0) {
          pppppuVar15 = (ulong *****)((long)*pppppuVar16 + -1);
        }
        piVar9 = (int *)((long)pppppuVar15 + 0x34);
        Hint_Prefetch(piVar9,2,0,1);
        do {
          iVar8 = *piVar9;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar9,0x10);
          if (bVar5) {
            *piVar9 = iVar8 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar8 + -1 != 0) goto LAB_00103a6c;
        __folio_put(pppppuVar15);
        if (((uint)*pppppuVar14 >> 0x10 & 1) != 0) goto LAB_00103a18;
LAB_00103a74:
        uVar13 = 0;
      }
      else {
LAB_00103a6c:
        if (((uint)*pppppuVar14 >> 0x10 & 1) == 0) goto LAB_00103a74;
LAB_00103a18:
        uVar13 = *(undefined1 *)((long)pppppuVar16 + 0x49);
      }
      __free_pages(pppppuVar14,uVar13);
      pppppuVar16 = pppppuVar18;
    }
    uVar12 = 0xfffffff4;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar12);
  }
  return;
}



//------------------------------------------------------------
// qcom_system_heap_create @ 00103bf4 size=644
// signature: undefined qcom_system_heap_create(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_system_heap_create(long param_1,long param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  uint *puVar4;
  ulong uVar5;
  long local_98;
  undefined **local_90;
  uint *local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_90 = (undefined **)0x0;
  local_88 = (uint *)0x0;
  local_98 = 0;
  uVar3 = dynamic_page_pool_init_shrinker();
  uVar5 = uVar3 & 0xffffffff;
  if ((int)uVar3 == 0) {
    puVar4 = (uint *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x10);
    if (puVar4 == (uint *)0x0) {
      uVar5 = 0xfffffff4;
    }
    else {
      *puVar4 = param_3 & 1;
      local_90 = &system_heap_ops;
      local_98 = param_1;
      local_88 = puVar4;
      uVar5 = dynamic_page_pool_create_pools(0,0);
      *(ulong *)(puVar4 + 2) = uVar5;
      if (uVar5 < 0xfffffffffffff001) {
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        local_80 = 0;
        local_70 = 10;
        uVar5 = kthread_create_on_node
                          (system_heap_refill_worker,uVar5,0xffffffff,"%s-pool-refill-thread",
                           param_1);
        if (uVar5 < 0xfffffffffffff001) {
          wake_up_process(uVar5);
          uVar2 = sched_setattr(uVar5,&local_80);
          if (uVar2 == 0) {
            *(ulong *)(**(long **)(puVar4 + 2) + 0x38) = uVar5;
            *(ulong *)(*(long *)(*(long *)(puVar4 + 2) + 8) + 0x38) = uVar5;
            *(ulong *)(*(long *)(*(long *)(puVar4 + 2) + 0x10) + 0x38) = uVar5;
            goto LAB_00103d3c;
          }
          _printk(&DAT_00109b3f,"system_heap_create_refill_worker",param_1,(ulong)uVar2);
          kthread_stop(uVar5);
          uVar5 = (ulong)uVar2;
        }
        else {
          _printk(&DAT_00109a29,"system_heap_create_refill_worker",param_1,uVar5);
          if ((int)uVar5 == 0) {
LAB_00103d3c:
            uVar5 = dma_heap_add(&local_98);
            if (uVar5 < 0xfffffffffffff001) {
              if ((param_3 & 1) != 0) {
                dma_heap_get_dev(uVar5);
                dma_coerce_mask_and_coherent();
              }
              _printk(&DAT_00109766,"qcom_system_heap_create",param_1);
              if (param_2 != 0) {
                local_98 = param_2;
                uVar5 = dma_heap_add(&local_98);
                if (uVar5 < 0xfffffffffffff001) {
                  dma_heap_get_dev(uVar5);
                  dma_coerce_mask_and_coherent();
                  _printk(&DAT_00109766,"qcom_system_heap_create",param_2);
                }
                else {
                  _printk(&DAT_0010980e,"qcom_system_heap_create",param_2);
                }
              }
              goto LAB_00103dbc;
            }
            kthread_stop(*(undefined8 *)(**(long **)(puVar4 + 2) + 0x38));
          }
        }
        dynamic_page_pool_release_pools(*(undefined8 *)(puVar4 + 2));
      }
      else {
        uVar5 = uVar5 & 0xffffffff;
      }
      kfree(puVar4);
    }
  }
  _printk(&DAT_0010980e,"qcom_system_heap_create",param_1,uVar5 & 0xffffffff);
LAB_00103dbc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dma_coerce_mask_and_coherent @ 00103e78 size=68
// signature: undefined dma_coerce_mask_and_coherent(void)
// callers: [qcom_system_heap_create]
//------------------------------------------------------------

void dma_coerce_mask_and_coherent(long param_1)

{
  int iVar1;
  
  *(long *)(param_1 + 0x298) = param_1 + 0x2a0;
  iVar1 = dma_set_mask(param_1,0xffffffffffffffff);
  if (iVar1 == 0) {
    dma_set_coherent_mask(param_1,0xffffffffffffffff);
  }
  return;
}



//------------------------------------------------------------
// system_heap_allocate @ 00103ec0 size=368
// signature: undefined system_heap_allocate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong system_heap_allocate(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined *local_80;
  undefined *puStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  long local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_50 = DAT_00109010;
  uStack_48 = DAT_00109018;
  local_40 = DAT_00109020;
  local_70 = DAT_00108ff0;
  local_68 = DAT_00108ff8;
  local_60 = DAT_00109000;
  uStack_58 = DAT_00109008;
  local_80 = PTR_s_qcom_dma_heaps_00108fe0;
  puStack_78 = PTR___this_module_00108fe8;
  lVar2 = kmalloc_trace(_of_get_next_available_child,0xdc0,0xb0);
  if (lVar2 == 0) {
    uVar3 = 0xfffffffffffffff4;
  }
  else {
    iVar1 = system_qcom_sg_buffer_alloc(param_1,lVar2,param_2,0);
    if (iVar1 == 0) {
      uVar3 = mem_buf_vmperm_alloc(lVar2 + 0x50,qcom_sg_release,lVar2 + 0xa8);
      *(ulong *)(lVar2 + 0x78) = uVar3;
      if (uVar3 < 0xfffffffffffff001) {
        local_80 = (undefined *)dma_heap_get_name(param_1);
        local_68 = *(undefined8 *)(lVar2 + 0x48);
        local_60 = CONCAT44(local_60._4_4_,param_3);
        local_50 = lVar2;
        uVar3 = mem_buf_dma_buf_export(&local_80,&qcom_sg_buf_ops);
        if (uVar3 < 0xfffffffffffff001) {
          qcom_store_dma_buf_fops(*(undefined8 *)(uVar3 + 8));
          goto LAB_00103ff0;
        }
        mem_buf_vmperm_free(*(undefined8 *)(lVar2 + 0x78));
      }
      iVar1 = (int)uVar3;
      deferred_free(lVar2 + 0x80,system_heap_buf_free,*(long *)(lVar2 + 0x48) + 0xfffU >> 0xc);
    }
    else {
      kfree(lVar2);
    }
    uVar3 = (ulong)iVar1;
  }
LAB_00103ff0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// get_pool_size_bytes @ 00104034 size=104
// signature: undefined get_pool_size_bytes(void)
// callers: []
//------------------------------------------------------------

long get_pool_size_bytes(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = dma_heap_get_drvdata();
  iVar1 = dynamic_page_pool_total(**(undefined8 **)(lVar4 + 8),1);
  iVar2 = dynamic_page_pool_total(*(undefined8 *)(*(long *)(lVar4 + 8) + 8),1);
  iVar3 = dynamic_page_pool_total(*(undefined8 *)(*(long *)(lVar4 + 8) + 0x10),1);
  return ((long)iVar1 + (long)iVar2 + (long)iVar3) * 0x1000;
}



//------------------------------------------------------------
// system_heap_refill_worker @ 001040a0 size=668
// signature: undefined system_heap_refill_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 system_heap_refill_worker(long param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  
  lVar10 = 0;
  lVar2 = sp_el0;
  do {
    lVar7 = *(long *)(param_1 + lVar10 * 8);
    uVar8 = *(uint *)(lVar7 + 0x48);
    if (((*(int *)(lVar7 + 8) < (int)(0x2800L >> ((ulong)uVar8 & 0x3f))) && (uVar8 != 0)) &&
       (uVar1 = *(uint *)(lVar7 + 0x44),
       *(int *)(lVar7 + 8) < (int)(0x6400L >> ((ulong)uVar8 & 0x3f)))) {
      while( true ) {
        uVar8 = *(uint *)(lVar7 + 0x44);
        lVar4 = ktime_get();
        if (lVar4 - *(long *)(lVar7 + 0x30) < 10000000) break;
        uVar6 = tpidr_el1;
        uVar9 = (ulong)(0x250015 >> (((ulong)uVar8 & 0xf) << 1)) & 3;
        iVar3 = strcmp(*(char **)(&kasan_flag_enabled + uVar9 * 0x640),"DMA32");
        if (iVar3 != 0) {
          lVar4 = uVar9 * 0x640;
          uVar5 = dynamic_pool_zone_watermark_ok_safe
                            (&contig_page_data + lVar4,*(uint *)(lVar7 + 0x48),
                             (long)((1 << (ulong)(*(uint *)(lVar7 + 0x48) & 0x1f)) +
                                   *(int *)(schedule + lVar4) + *(int *)(strcmp + lVar4)),uVar9);
          if ((uVar5 & 1) != 0) goto LAB_001041a4;
LAB_001042d4:
          uVar6 = ktime_get();
          *(undefined8 *)(lVar7 + 0x30) = uVar6;
          break;
        }
LAB_001041a4:
        uVar8 = (uint)uVar9;
        if (uVar8 != 0) {
          uVar6 = tpidr_el1;
          iVar3 = strcmp(*(char **)(&kasan_flag_enabled + (long)(int)(uVar8 - 1) * 0x640),"DMA32");
          if (iVar3 != 0) {
            lVar4 = (long)(int)(uVar8 - 1) * 0x640;
            uVar5 = dynamic_pool_zone_watermark_ok_safe
                              (&contig_page_data + lVar4,*(uint *)(lVar7 + 0x48),
                               (long)((1 << (ulong)(*(uint *)(lVar7 + 0x48) & 0x1f)) +
                                     *(int *)(schedule + lVar4) + *(int *)(strcmp + lVar4)),uVar9);
            if ((uVar5 & 1) == 0) goto LAB_001042d4;
          }
          if (1 < uVar8) {
            uVar6 = tpidr_el1;
            iVar3 = strcmp(*(char **)(&kasan_flag_enabled + (long)(int)(uVar8 - 2) * 0x640),"DMA32")
            ;
            if (iVar3 != 0) {
              lVar4 = (long)(int)(uVar8 - 2) * 0x640;
              uVar5 = dynamic_pool_zone_watermark_ok_safe
                                (&contig_page_data + lVar4,*(uint *)(lVar7 + 0x48),
                                 (long)((1 << (ulong)(*(uint *)(lVar7 + 0x48) & 0x1f)) +
                                       *(int *)(schedule + lVar4) + *(int *)(strcmp + lVar4)),uVar9)
              ;
              if ((uVar5 & 1) == 0) goto LAB_001042d4;
            }
            if (uVar8 == 3) {
              uVar6 = tpidr_el1;
              iVar3 = strcmp(_kasan_flag_enabled,"DMA32");
              if ((iVar3 != 0) &&
                 (uVar9 = dynamic_pool_zone_watermark_ok_safe
                                    (&contig_page_data,*(uint *)(lVar7 + 0x48),
                                     (long)((1 << (ulong)(*(uint *)(lVar7 + 0x48) & 0x1f)) +
                                           _schedule + _strcmp),uVar9), (uVar9 & 1) == 0))
              goto LAB_001042d4;
            }
          }
        }
        uVar6 = tpidr_el1;
        lVar4 = __alloc_pages(uVar6,uVar1 & 0xfffeffff | 0xc00,*(undefined4 *)(lVar7 + 0x48),0,0);
        if ((lVar4 == 0) ||
           (dynamic_page_pool_add(lVar7,lVar4),
           (int)(0x6400L >> ((ulong)*(uint *)(lVar7 + 0x48) & 0x3f)) <= *(int *)(lVar7 + 8))) break;
      }
    }
    lVar10 = lVar10 + 1;
    if (lVar10 == 3) {
      *(undefined4 *)(lVar2 + 0x30) = 1;
      DataMemoryBarrier(2,3);
      uVar9 = kthread_should_stop();
      if ((uVar9 & 1) != 0) {
        *(undefined4 *)(lVar2 + 0x30) = 0;
        DataMemoryBarrier(2,3);
        return 0;
      }
      schedule();
      *(undefined4 *)(lVar2 + 0x30) = 0;
      lVar10 = 0;
      DataMemoryBarrier(2,3);
    }
  } while( true );
}



//------------------------------------------------------------
// dynamic_page_pool_add @ 00104360 size=212
// signature: undefined dynamic_page_pool_add(void)
// callers: [system_heap_refill_worker, dynamic_page_pool_free]
//------------------------------------------------------------

void dynamic_page_pool_add(long param_1,long param_2)

{
  long lVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  ulong uVar6;
  long *plVar7;
  
  uVar5 = _raw_spin_lock_irqsave(param_1 + 0x40);
  plVar7 = *(long **)(param_1 + 0x28);
  lVar1 = param_2 + 8;
  uVar6 = __list_add_valid(lVar1,plVar7,param_1 + 0x20);
  if ((uVar6 & 1) != 0) {
    *(long *)(param_1 + 0x28) = lVar1;
    *(long *)(param_2 + 8) = param_1 + 0x20;
    *(long **)(param_2 + 0x10) = plVar7;
    *plVar7 = lVar1;
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  piVar2 = (int *)(param_1 + 8);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar4) {
      *piVar2 = *piVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  mod_node_page_state(&contig_page_data,0x22,(long)(1 << (ulong)(*(uint *)(param_1 + 0x48) & 0x1f)))
  ;
  _raw_spin_unlock_irqrestore(param_1 + 0x40,uVar5);
  return;
}



//------------------------------------------------------------
// dynamic_page_pool_remove @ 00104444 size=208
// signature: undefined dynamic_page_pool_remove(void)
// callers: [system_heap_allocate, qcom_sys_heap_alloc_largest_available]
//------------------------------------------------------------

long * dynamic_page_pool_remove(int *param_1,ulong param_2)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  ulong uVar7;
  long *plVar8;
  
  if ((param_2 & 1) == 0) {
    if (param_1[1] == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x104520);
      (*pcVar6)();
    }
    plVar8 = *(long **)(param_1 + 8);
    param_1[1] = param_1[1] + -1;
  }
  else {
    if (*param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10451c);
      (*pcVar6)();
    }
    plVar8 = *(long **)(param_1 + 4);
    *param_1 = *param_1 + -1;
  }
  piVar1 = param_1 + 2;
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar5) {
      *piVar1 = *piVar1 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  uVar7 = __list_del_entry_valid(plVar8);
  if ((uVar7 & 1) != 0) {
    lVar2 = *plVar8;
    plVar3 = (long *)plVar8[1];
    *(long **)(lVar2 + 8) = plVar3;
    *plVar3 = lVar2;
  }
  *plVar8 = -0x2152ffffffffff00;
  plVar8[1] = -0x2152fffffffffede;
  mod_node_page_state(&contig_page_data,0x22,-1L << ((long)param_1[0x12] & 0x3fU));
  return plVar8 + -1;
}



//------------------------------------------------------------
// dynamic_page_pool_free @ 00104524 size=64
// signature: undefined dynamic_page_pool_free(void)
// callers: [system_heap_allocate, system_heap_buf_free, system_heap_free, secure_system_heap_prefetch_work]
//------------------------------------------------------------

void dynamic_page_pool_free(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  uint uVar2;
  
  if (((uint)*param_2 >> 0x10 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)*(byte *)((long)param_2 + 0x51);
  }
  if (*(uint *)(param_1 + 0x48) != uVar2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x104564);
    (*pcVar1)();
  }
  dynamic_page_pool_add();
  return;
}



//------------------------------------------------------------
// dynamic_page_pool_total @ 00104568 size=28
// signature: undefined dynamic_page_pool_total(void)
// callers: [get_pool_size_bytes, get_pool_size_bytes]
//------------------------------------------------------------

int dynamic_page_pool_total(int *param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if ((param_2 & 1) != 0) {
    iVar1 = *param_1 + iVar1;
  }
  return iVar1 << (ulong)(param_1[0x12] & 0x1f);
}



//------------------------------------------------------------
// dynamic_page_pool_create @ 00104588 size=192
// signature: undefined dynamic_page_pool_create(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * dynamic_page_pool_create(uint param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  ulong uVar4;
  
  puVar3 = (undefined8 *)kmalloc_trace(_of_property_read_string,0xcc0,0x70);
  if (puVar3 != (undefined8 *)0x0) {
    *puVar3 = 0;
    puVar3[4] = puVar3 + 4;
    puVar3[5] = puVar3 + 4;
    puVar3[2] = puVar3 + 2;
    puVar3[3] = puVar3 + 2;
    *(uint *)((long)puVar3 + 0x44) = param_1 | 0x40000;
    *(undefined4 *)(puVar3 + 9) = param_2;
    *(undefined4 *)(puVar3 + 8) = 0;
    mutex_lock(&pool_list_lock);
    puVar2 = pool_list;
    puVar1 = puVar3 + 10;
    uVar4 = __list_add_valid(puVar1,&pool_list,pool_list);
    if ((uVar4 & 1) != 0) {
      *(undefined8 **)(puVar2 + 8) = puVar1;
      puVar3[10] = puVar2;
      puVar3[0xb] = &pool_list;
      pool_list = (undefined *)puVar1;
    }
    mutex_unlock(&pool_list_lock);
  }
  return puVar3;
}



//------------------------------------------------------------
// dynamic_page_pool_destroy @ 0010464c size=612
// signature: undefined dynamic_page_pool_destroy(void)
// callers: [dynamic_page_pool_create_pools, dynamic_page_pool_release_pools]
//------------------------------------------------------------

void dynamic_page_pool_destroy(int *param_1)

{
  int *piVar1;
  long lVar2;
  long ***ppplVar3;
  long *plVar4;
  long ***ppplVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  ulong uVar9;
  undefined8 uVar10;
  code *pcVar11;
  long ****pppplVar12;
  long ****pppplVar13;
  long ****local_78;
  long ****local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_78 = (long ****)&local_78;
  local_70 = (long ****)&local_78;
  mutex_lock(&pool_list_lock);
  uVar9 = __list_del_entry_valid(param_1 + 0x14);
  if ((uVar9 & 1) != 0) {
    lVar2 = *(long *)(param_1 + 0x14);
    plVar4 = *(long **)(param_1 + 0x16);
    *(long **)(lVar2 + 8) = plVar4;
    *plVar4 = lVar2;
  }
  param_1[0x14] = 0x100;
  param_1[0x15] = -0x21530000;
  param_1[0x16] = 0x122;
  param_1[0x17] = -0x21530000;
  mutex_unlock(&pool_list_lock);
  uVar10 = _raw_spin_lock_irqsave(param_1 + 0x10);
  iVar8 = 0;
  do {
    if (param_1[1] == 0) {
      if (*param_1 == 0) break;
      pppplVar13 = *(long *****)(param_1 + 4);
      *param_1 = *param_1 + -1;
      piVar1 = param_1 + 2;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar7) {
          *piVar1 = *piVar1 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
    }
    else {
      pppplVar13 = *(long *****)(param_1 + 8);
      param_1[1] = param_1[1] + -1;
      piVar1 = param_1 + 2;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar7) {
          *piVar1 = *piVar1 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
    }
    uVar9 = __list_del_entry_valid(pppplVar13);
    if ((uVar9 & 1) != 0) {
      ppplVar3 = *pppplVar13;
      ppplVar5 = pppplVar13[1];
      ppplVar3[1] = (long **)ppplVar5;
      *ppplVar5 = (long **)ppplVar3;
    }
    *pppplVar13 = (long ***)0xdead000000000100;
    pppplVar13[1] = (long ***)0xdead000000000122;
    mod_node_page_state(&contig_page_data,0x22,-1L << ((long)param_1[0x12] & 0x3fU));
    pppplVar12 = local_78;
    uVar9 = __list_add_valid(pppplVar13,&local_78,local_78);
    if ((uVar9 & 1) != 0) {
      pppplVar12[1] = (long ***)pppplVar13;
      *pppplVar13 = (long ***)pppplVar12;
      pppplVar13[1] = (long ***)&local_78;
      local_78 = pppplVar13;
    }
    iVar8 = iVar8 + 1;
  } while( true );
  _raw_spin_unlock_irqrestore(param_1 + 0x10,uVar10);
  if ((iVar8 != 0) && (pcVar11 = *(code **)(param_1 + 0x1a), pcVar11 != (code *)0x0)) {
    if (*(int *)(pcVar11 + -4) != -0x2cd4de3c) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104814);
      (*pcVar11)();
    }
    iVar8 = (*pcVar11)(param_1,&local_78,iVar8);
    if (iVar8 != 0) {
      _printk(&DAT_0010a2b6);
      goto LAB_00104834;
    }
  }
  pppplVar13 = local_78;
  while ((long *****)pppplVar13 != &local_78) {
    pppplVar12 = (long ****)*pppplVar13;
    uVar9 = __list_del_entry_valid(pppplVar13);
    if ((uVar9 & 1) != 0) {
      ppplVar3 = *pppplVar13;
      ppplVar5 = pppplVar13[1];
      ppplVar3[1] = (long **)ppplVar5;
      *ppplVar5 = (long **)ppplVar3;
    }
    *pppplVar13 = (long ***)0xdead000000000100;
    pppplVar13[1] = (long ***)0xdead000000000122;
    __free_pages(pppplVar13 + -1,param_1[0x12]);
    pppplVar13 = pppplVar12;
  }
  kfree(param_1);
LAB_00104834:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dynamic_page_pool_shrink_high_and_low @ 001048c8 size=132
// signature: undefined dynamic_page_pool_shrink_high_and_low(void)
// callers: [secure_system_heap_prefetch_work]
//------------------------------------------------------------

void dynamic_page_pool_shrink_high_and_low(undefined8 *param_1,uint param_2,int param_3)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = (ulong)param_2;
  mutex_lock(&pool_list_lock);
  if (0 < (int)param_2) {
    do {
      uVar2 = uVar2 - 1;
      iVar1 = dynamic_page_pool_do_shrink(*param_1,2,param_3);
      param_3 = param_3 - iVar1;
      param_1 = param_1 + 1;
    } while (0 < param_3 && uVar2 != 0);
  }
  mutex_unlock(&pool_list_lock);
  return;
}



//------------------------------------------------------------
// dynamic_page_pool_do_shrink @ 0010494c size=664
// signature: undefined dynamic_page_pool_do_shrink(void)
// callers: [dynamic_page_pool_shrink_count, dynamic_page_pool_shrink_scan, dynamic_page_pool_shrink_high_and_low]
//------------------------------------------------------------

int dynamic_page_pool_do_shrink(int *param_1,uint param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  long ***ppplVar4;
  long ***ppplVar5;
  char cVar6;
  bool bVar7;
  long lVar8;
  int iVar9;
  undefined8 uVar10;
  ulong uVar11;
  code *pcVar12;
  int iVar13;
  long ****pppplVar14;
  long ****pppplVar15;
  long ****local_78;
  long ****local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_78 = (long ****)&local_78;
  lVar8 = sp_el0;
  uVar3 = *(uint *)(lVar8 + 0x44) & 0x20000;
  local_70 = local_78;
  if (param_3 == 0) {
    iVar13 = param_1[1];
    if (uVar3 != 0 || (param_2 & 2) != 0) {
      iVar13 = *param_1 + iVar13;
    }
    iVar13 = iVar13 << (ulong)(param_1[0x12] & 0x1f);
  }
  else {
    if (param_3 < 1) {
      iVar13 = 0;
    }
    else {
      iVar13 = 0;
      piVar1 = param_1 + 0x10;
      do {
        uVar10 = _raw_spin_lock_irqsave(piVar1);
        if (param_1[1] == 0) {
          if ((uVar3 == 0 && (param_2 & 2) == 0) || (*param_1 == 0)) {
            _raw_spin_unlock_irqrestore(piVar1,uVar10);
            break;
          }
          pppplVar14 = *(long *****)(param_1 + 4);
          *param_1 = *param_1 + -1;
          piVar2 = param_1 + 2;
          Hint_Prefetch(piVar2,2,0,1);
          do {
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar7) {
              *piVar2 = *piVar2 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
        }
        else {
          pppplVar14 = *(long *****)(param_1 + 8);
          param_1[1] = param_1[1] + -1;
          piVar2 = param_1 + 2;
          Hint_Prefetch(piVar2,2,0,1);
          do {
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar7) {
              *piVar2 = *piVar2 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
        }
        uVar11 = __list_del_entry_valid(pppplVar14);
        if ((uVar11 & 1) != 0) {
          ppplVar4 = *pppplVar14;
          ppplVar5 = pppplVar14[1];
          ppplVar4[1] = (long **)ppplVar5;
          *ppplVar5 = (long **)ppplVar4;
        }
        *pppplVar14 = (long ***)0xdead000000000100;
        pppplVar14[1] = (long ***)0xdead000000000122;
        mod_node_page_state(&contig_page_data,0x22,-1L << ((long)param_1[0x12] & 0x3fU));
        _raw_spin_unlock_irqrestore(piVar1,uVar10);
        pppplVar15 = local_78;
        uVar11 = __list_add_valid(pppplVar14,&local_78,local_78);
        if ((uVar11 & 1) != 0) {
          pppplVar15[1] = (long ***)pppplVar14;
          *pppplVar14 = (long ***)pppplVar15;
          pppplVar14[1] = (long ***)&local_78;
          local_78 = pppplVar14;
        }
        iVar13 = (1 << (ulong)(param_1[0x12] & 0x1f)) + iVar13;
      } while (iVar13 < param_3);
      if ((iVar13 != 0) && (pcVar12 = *(code **)(param_1 + 0x1a), pcVar12 != (code *)0x0)) {
        if (*(int *)(pcVar12 + -4) != -0x2cd4de3c) {
                    /* WARNING: Does not return */
          pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x104b50);
          (*pcVar12)();
        }
        iVar9 = (*pcVar12)(param_1,&local_78,iVar13 >> (param_1[0x12] & 0x1fU));
        if (iVar9 != 0) {
          _printk(&DAT_001098c5);
          iVar13 = 0;
          goto LAB_00104b68;
        }
      }
    }
    pppplVar14 = local_78;
    while ((long *****)pppplVar14 != &local_78) {
      pppplVar15 = (long ****)*pppplVar14;
      uVar11 = __list_del_entry_valid(pppplVar14);
      if ((uVar11 & 1) != 0) {
        ppplVar4 = *pppplVar14;
        ppplVar5 = pppplVar14[1];
        ppplVar4[1] = (long **)ppplVar5;
        *ppplVar5 = (long **)ppplVar4;
      }
      *pppplVar14 = (long ***)0xdead000000000100;
      pppplVar14[1] = (long ***)0xdead000000000122;
      __free_pages(pppplVar14 + -1,param_1[0x12]);
      pppplVar14 = pppplVar15;
    }
  }
LAB_00104b68:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar13;
}



//------------------------------------------------------------
// dynamic_page_pool_create_pools @ 00104c04 size=732
// signature: undefined dynamic_page_pool_create_pools(void)
// callers: [qcom_system_heap_create, qcom_secure_system_heap_restore, qcom_secure_system_heap_create]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * dynamic_page_pool_create_pools(undefined4 param_1,undefined8 param_2)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  
  puVar3 = (undefined8 *)kmalloc_trace(_of_dma_configure_id,0xcc0,0x18);
  if (puVar3 == (undefined8 *)0x0) {
    return (undefined8 *)0xfffffffffffffff4;
  }
  puVar4 = (undefined8 *)kmalloc_trace(_of_property_read_string,0xcc0,0x70);
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = 0;
    puVar4[4] = puVar4 + 4;
    puVar4[5] = puVar4 + 4;
    puVar4[2] = puVar4 + 2;
    puVar4[3] = puVar4 + 2;
    *(undefined4 *)((long)puVar4 + 0x44) = 0x1521c2;
    *(undefined4 *)(puVar4 + 9) = 9;
    *(undefined4 *)(puVar4 + 8) = 0;
    mutex_lock(&pool_list_lock);
    puVar2 = pool_list;
    puVar6 = puVar4 + 10;
    uVar5 = __list_add_valid(puVar6,&pool_list,pool_list);
    if ((uVar5 & 1) != 0) {
      *(undefined8 **)(puVar2 + 8) = puVar6;
      puVar4[10] = puVar2;
      puVar4[0xb] = &pool_list;
      pool_list = (undefined *)puVar6;
    }
    mutex_unlock(&pool_list_lock);
  }
  *puVar3 = puVar4;
  *(undefined4 *)(puVar4 + 0xc) = param_1;
  puVar4[0xd] = param_2;
  *(undefined4 *)(puVar4 + 1) = 0;
  puVar4[6] = 0;
  if ((puVar4 == (undefined8 *)0x0) || ((undefined8 *)0xfffffffffffff000 < puVar4)) {
    _printk(&DAT_001099b6,"dynamic_page_pool_create_pools",9);
  }
  else {
    puVar4 = (undefined8 *)kmalloc_trace(_of_property_read_string,0xcc0,0x70);
    if (puVar4 != (undefined8 *)0x0) {
      *puVar4 = 0;
      puVar4[4] = puVar4 + 4;
      puVar4[5] = puVar4 + 4;
      puVar4[2] = puVar4 + 2;
      puVar4[3] = puVar4 + 2;
      *(undefined4 *)((long)puVar4 + 0x44) = 0x1521c2;
      *(undefined4 *)(puVar4 + 9) = 4;
      *(undefined4 *)(puVar4 + 8) = 0;
      mutex_lock(&pool_list_lock);
      puVar2 = pool_list;
      puVar6 = puVar4 + 10;
      uVar5 = __list_add_valid(puVar6,&pool_list,pool_list);
      if ((uVar5 & 1) != 0) {
        *(undefined8 **)(puVar2 + 8) = puVar6;
        puVar4[10] = puVar2;
        puVar4[0xb] = &pool_list;
        pool_list = (undefined *)puVar6;
      }
      mutex_unlock(&pool_list_lock);
    }
    puVar3[1] = puVar4;
    *(undefined4 *)(puVar4 + 0xc) = param_1;
    puVar4[0xd] = param_2;
    *(undefined4 *)(puVar4 + 1) = 0;
    puVar4[6] = 0;
    if (puVar4 == (undefined8 *)0x0 || (undefined8 *)0xfffffffffffff000 < puVar4) {
      _printk(&DAT_001099b6,"dynamic_page_pool_create_pools",4);
      uVar7 = *puVar3;
    }
    else {
      puVar6 = (undefined8 *)kmalloc_trace(_of_property_read_string,0xcc0,0x70);
      if (puVar6 != (undefined8 *)0x0) {
        *puVar6 = 0;
        puVar6[4] = puVar6 + 4;
        puVar6[5] = puVar6 + 4;
        puVar6[2] = puVar6 + 2;
        puVar6[3] = puVar6 + 2;
        *(undefined4 *)(puVar6 + 9) = 0;
        puVar6[8] = 0x140dc200000000;
        mutex_lock(&pool_list_lock);
        puVar2 = pool_list;
        puVar1 = puVar6 + 10;
        uVar5 = __list_add_valid(puVar1,&pool_list,pool_list);
        if ((uVar5 & 1) != 0) {
          *(undefined8 **)(puVar2 + 8) = puVar1;
          puVar6[10] = puVar2;
          puVar6[0xb] = &pool_list;
          pool_list = (undefined *)puVar1;
        }
        mutex_unlock(&pool_list_lock);
      }
      puVar3[2] = puVar6;
      *(undefined4 *)(puVar6 + 0xc) = param_1;
      puVar6[0xd] = param_2;
      *(undefined4 *)(puVar6 + 1) = 0;
      puVar6[6] = 0;
      if ((puVar6 != (undefined8 *)0x0) && (puVar6 < (undefined8 *)0xfffffffffffff001)) {
        return puVar3;
      }
      _printk(&DAT_001099b6,"dynamic_page_pool_create_pools",0);
      dynamic_page_pool_destroy(*puVar3);
      if (puVar4 == (undefined8 *)0x0 || (undefined8 *)0xfffffffffffff000 < puVar4)
      goto LAB_00104eb0;
      uVar7 = puVar3[1];
    }
    dynamic_page_pool_destroy(uVar7);
  }
LAB_00104eb0:
  kfree(puVar3);
  return (undefined8 *)0xfffffffffffffff4;
}



//------------------------------------------------------------
// dynamic_page_pool_release_pools @ 00104ee4 size=68
// signature: undefined dynamic_page_pool_release_pools(void)
// callers: [qcom_system_heap_create, qcom_secure_system_heap_freeze, qcom_secure_system_heap_create]
//------------------------------------------------------------

void dynamic_page_pool_release_pools(undefined8 *param_1)

{
  dynamic_page_pool_destroy(*param_1);
  dynamic_page_pool_destroy(param_1[1]);
  dynamic_page_pool_destroy(param_1[2]);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// dynamic_page_pool_init_shrinker @ 00104f2c size=84
// signature: undefined dynamic_page_pool_init_shrinker(void)
// callers: [qcom_system_heap_create, qcom_secure_system_heap_create]
//------------------------------------------------------------

undefined8 dynamic_page_pool_init_shrinker(void)

{
  undefined8 uVar1;
  
  if ((dynamic_page_pool_init_shrinker_registered & 1) == 0) {
    uVar1 = register_shrinker(&pool_shrinker,"dynamic_page_pool");
    if ((int)uVar1 == 0) {
      dynamic_page_pool_init_shrinker_registered = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// dynamic_page_pool_shrink_count @ 00104f84 size=140
// signature: undefined dynamic_page_pool_shrink_count(void)
// callers: []
//------------------------------------------------------------

long dynamic_page_pool_shrink_count(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  undefined **ppuVar4;
  int iVar5;
  
  uVar1 = *param_2;
  mutex_lock(&pool_list_lock);
  if ((undefined **)pool_list == &pool_list) {
    lVar3 = 0;
  }
  else {
    iVar5 = 0;
    ppuVar4 = (undefined **)pool_list;
    do {
      iVar2 = dynamic_page_pool_do_shrink(ppuVar4 + -10,uVar1,0);
      ppuVar4 = (undefined **)*ppuVar4;
      iVar5 = iVar2 + iVar5;
    } while (ppuVar4 != &pool_list);
    lVar3 = (long)iVar5;
  }
  mutex_unlock(&pool_list_lock);
  return lVar3;
}



//------------------------------------------------------------
// dynamic_page_pool_shrink_scan @ 00105014 size=176
// signature: undefined dynamic_page_pool_shrink_scan(void)
// callers: []
//------------------------------------------------------------

long dynamic_page_pool_shrink_scan(undefined8 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined **ppuVar5;
  int iVar6;
  
  iVar3 = param_2[2];
  if (iVar3 == 0) {
    lVar4 = 0;
  }
  else {
    uVar1 = *param_2;
    mutex_lock(&pool_list_lock);
    if ((undefined **)pool_list == &pool_list) {
      lVar4 = 0;
    }
    else {
      iVar6 = 0;
      ppuVar5 = (undefined **)pool_list;
      do {
        iVar2 = dynamic_page_pool_do_shrink(ppuVar5 + -10,uVar1,iVar3);
        iVar3 = iVar3 - iVar2;
        iVar6 = iVar2 + iVar6;
        if (iVar3 < 1) break;
        ppuVar5 = (undefined **)*ppuVar5;
      } while (ppuVar5 != &pool_list);
      lVar4 = (long)iVar6;
    }
    mutex_unlock(&pool_list_lock);
  }
  return lVar4;
}



//------------------------------------------------------------
// qcom_secure_system_heap_prefetch @ 001050c8 size=32
// signature: undefined qcom_secure_system_heap_prefetch(void)
// callers: []
//------------------------------------------------------------

void qcom_secure_system_heap_prefetch(undefined8 param_1,undefined8 param_2)

{
  __qcom_secure_system_heap_resize(param_1,param_2,0);
  return;
}



//------------------------------------------------------------
// __qcom_secure_system_heap_resize @ 001050e8 size=656
// signature: undefined __qcom_secure_system_heap_resize(void)
// callers: [qcom_secure_system_heap_drain, qcom_secure_system_heap_prefetch]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __qcom_secure_system_heap_resize(long param_1,ulong param_2,byte param_3)

{
  long *plVar1;
  undefined8 uVar2;
  char *pcVar3;
  long lVar4;
  long ****pppplVar5;
  long ****pppplVar6;
  long *****ppppplVar7;
  undefined **ppuVar8;
  long *****ppppplVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined **ppuVar12;
  ulong uVar13;
  undefined **ppuVar14;
  undefined **ppuVar15;
  long *****local_78;
  long *****local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_78 = (long *****)&local_78;
  local_70 = local_78;
  if ((param_1 == 0) || (0x20 < param_2)) {
    pcVar3 = "drain";
    if ((param_3 & 1) == 0) {
      pcVar3 = "prefetch";
    }
    _printk(&DAT_00109e70,"__qcom_secure_system_heap_resize",pcVar3);
    uVar11 = 0xffffffea;
  }
  else {
    if (param_2 != 0) {
      uVar13 = 0;
      ppuVar14 = (undefined **)0x0;
      do {
        ppuVar12 = &secure_heaps;
        do {
          ppuVar12 = (undefined **)*ppuVar12;
          ppuVar15 = ppuVar14;
          if (ppuVar12 == &secure_heaps) break;
          ppuVar15 = ppuVar12 + -2;
          ppuVar8 = (undefined **)dma_heap_get_drvdata(*(undefined8 *)(param_1 + 8));
        } while (ppuVar15 != ppuVar8);
        if (ppuVar15 == (undefined **)0x0) {
          uVar11 = dma_heap_get_name(*(undefined8 *)(param_1 + 8));
          _printk(&DAT_0010a07f,"__qcom_secure_system_heap_resize",uVar11);
          uVar11 = 0xffffffea;
LAB_001052bc:
          ppppplVar7 = local_78;
          while ((long ******)ppppplVar7 != &local_78) {
            ppppplVar9 = (long *****)*ppppplVar7;
            uVar13 = __list_del_entry_valid(ppppplVar7);
            if ((uVar13 & 1) != 0) {
              pppplVar5 = *ppppplVar7;
              pppplVar6 = ppppplVar7[1];
              pppplVar5[1] = (long ***)pppplVar6;
              *pppplVar6 = (long ***)pppplVar5;
            }
            *ppppplVar7 = (long ****)0xdead000000000100;
            ppppplVar7[1] = (long ****)0xdead000000000122;
            kfree(ppppplVar7);
            ppppplVar7 = ppppplVar9;
          }
          goto LAB_0010527c;
        }
        ppppplVar9 = (long *****)kmalloc_trace(_of_dma_configure_id,0xcc0,0x28);
        ppppplVar7 = local_70;
        if (ppppplVar9 == (long *****)0x0) {
          uVar11 = 0xfffffff4;
          goto LAB_001052bc;
        }
        plVar1 = (long *)(param_1 + uVar13 * 0x10);
        *(byte *)(ppppplVar9 + 4) = param_3 & 1;
        lVar4 = *plVar1;
        ppppplVar9[2] = (long ****)plVar1[1];
        ppppplVar9[3] = (long ****)(lVar4 + 0xfffU & 0xfffffffffffff000);
        *ppppplVar9 = (long ****)ppppplVar9;
        ppppplVar9[1] = (long ****)ppppplVar9;
        uVar10 = __list_add_valid(ppppplVar9,local_70,&local_78);
        if ((uVar10 & 1) != 0) {
          *ppppplVar9 = (long ****)&local_78;
          ppppplVar9[1] = (long ****)ppppplVar7;
          local_70 = ppppplVar9;
          *ppppplVar7 = (long ****)ppppplVar9;
        }
        uVar13 = (ulong)((int)uVar13 + 1);
        ppuVar14 = ppuVar15;
      } while (uVar13 < param_2);
    }
    uVar11 = _raw_spin_lock_irqsave(&work_lock);
    if ((long ******)local_78 != &local_78) {
      local_78[1] = (long ****)PTR_prefetch_list_00109658;
      *(long ******)PTR_prefetch_list_00109658 = local_78;
      *local_70 = (long ****)&prefetch_list;
      PTR_prefetch_list_00109658 = (undefined *)local_70;
      local_78 = (long *****)&local_78;
      local_70 = (long *****)&local_78;
    }
    uVar2 = 0xfa;
    if ((param_3 & 1) == 0) {
      uVar2 = 0;
    }
    queue_delayed_work_on(0x20,prefetch_wq,&prefetch_work,uVar2);
    _raw_spin_unlock_irqrestore(&work_lock,uVar11);
    uVar11 = 0;
  }
LAB_0010527c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// qcom_secure_system_heap_drain @ 0010537c size=32
// signature: undefined qcom_secure_system_heap_drain(void)
// callers: []
//------------------------------------------------------------

void qcom_secure_system_heap_drain(undefined8 param_1,undefined8 param_2)

{
  __qcom_secure_system_heap_resize(param_1,param_2,1);
  return;
}



//------------------------------------------------------------
// qcom_secure_system_heap_freeze @ 001053a0 size=128
// signature: undefined qcom_secure_system_heap_freeze(void)
// callers: [qcom_dma_heaps_freeze]
//------------------------------------------------------------

undefined8 qcom_secure_system_heap_freeze(void)

{
  undefined **ppuVar1;
  
  cancel_delayed_work_sync(&prefetch_work);
  ppuVar1 = (undefined **)secure_heaps;
  while( true ) {
    if (ppuVar1 == &secure_heaps) {
      return 0;
    }
    if (ppuVar1[2] != (undefined *)0x0) break;
    dynamic_page_pool_release_pools(ppuVar1[-2]);
    ppuVar1 = (undefined **)*ppuVar1;
  }
  _printk(&DAT_0010a455,"qcom_secure_system_heap_freeze",ppuVar1[2],*(undefined4 *)(ppuVar1 + -1));
  return 0xfffffff0;
}



//------------------------------------------------------------
// qcom_secure_system_heap_restore @ 00105424 size=160
// signature: undefined qcom_secure_system_heap_restore(void)
// callers: [qcom_dma_heaps_restore]
//------------------------------------------------------------

undefined8 qcom_secure_system_heap_restore(void)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  ppuVar2 = (undefined **)secure_heaps;
  if ((undefined **)secure_heaps != &secure_heaps) {
    do {
      puVar1 = (undefined *)
               dynamic_page_pool_create_pools(*(undefined4 *)(ppuVar2 + -1),free_secure_pages);
      ppuVar2[-2] = puVar1;
      if ((undefined *)0xfffffffffffff000 < puVar1) {
        _printk(&DAT_00109b86,"qcom_secure_system_heap_restore",*(undefined4 *)(ppuVar2 + -1),puVar1
               );
      }
      ppuVar2 = (undefined **)*ppuVar2;
    } while (ppuVar2 != &secure_heaps);
  }
  return 0;
}



//------------------------------------------------------------
// free_secure_pages @ 001054c8 size=268
// signature: undefined free_secure_pages(void)
// callers: []
//------------------------------------------------------------

void free_secure_pages(long param_1,long *param_2,int param_3)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  ulong *puVar5;
  long *plVar6;
  ulong uVar7;
  long *plVar8;
  ulong *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (ulong *)0x0;
  uStack_40 = 0;
  if (param_3 == 0) {
    bVar3 = false;
  }
  else {
    iVar4 = sg_alloc_table(&local_48,param_3,0xcc0);
    if (iVar4 == 0) {
      plVar8 = (long *)*param_2;
      if (plVar8 != param_2) {
        puVar5 = local_48;
        do {
          plVar6 = plVar8 + -1;
          if (((uint)*plVar6 >> 0x10 & 1) == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = (ulong)*(byte *)((long)plVar8 + 0x49);
          }
          if (((ulong)plVar6 & 3) != 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1055d4);
            (*pcVar2)();
          }
          *(undefined4 *)(puVar5 + 1) = 0;
          *(int *)((long)puVar5 + 0xc) = (int)(0x1000L << (uVar7 & 0x3f));
          *puVar5 = *puVar5 & 3 | (ulong)plVar6;
          puVar5 = (ulong *)sg_next();
          plVar8 = (long *)*plVar8;
        } while (plVar8 != param_2);
      }
      iVar4 = hyp_unassign_sg_from_flags(&local_48,(long)*(int *)(param_1 + 0x60),1);
      sg_free_table(&local_48);
      bVar3 = iVar4 != 0;
    }
    else {
      bVar3 = true;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_secure_system_heap_create @ 001055d8 size=648
// signature: undefined qcom_secure_system_heap_create(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_secure_system_heap_create(long param_1,long param_2,int param_3)

{
  ulong *puVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong *puVar6;
  ulong uVar7;
  long local_60;
  undefined **local_58;
  ulong *local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = (undefined **)0x0;
  local_50 = (ulong *)0x0;
  local_60 = 0;
  iVar3 = get_secure_vmid((long)param_3);
  if ((iVar3 == -0x16) || (lVar4 = __sw_hweight64((long)param_3), lVar4 != 1)) {
    _printk(&DAT_00109fcc);
    uVar7 = 0xffffffea;
  }
  else {
    uVar5 = dynamic_page_pool_init_shrinker();
    uVar7 = uVar5 & 0xffffffff;
    if ((int)uVar5 == 0) {
      if ((create_prefetch_workqueue_registered & 1) == 0) {
        prefetch_work = 0xfffffffe0;
        DAT_00109230 = &DAT_00109230;
        DAT_00109238 = &DAT_00109230;
        DAT_00109240 = secure_system_heap_prefetch_work;
        init_timer_key(&DAT_00109258,&delayed_work_timer_fn,0x200000,0,0);
        prefetch_wq = alloc_workqueue("system_secure_prefetch_wq",6,0);
        if (prefetch_wq != 0) {
          create_prefetch_workqueue_registered = 1;
          goto LAB_00105728;
        }
        _printk(&DAT_00109cc0);
      }
      else {
LAB_00105728:
        puVar6 = (ulong *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x28);
        if (puVar6 != (ulong *)0x0) {
          *(int *)(puVar6 + 1) = param_3;
          uVar7 = dynamic_page_pool_create_pools(param_3,free_secure_pages);
          *puVar6 = uVar7;
          if (uVar7 < 0xfffffffffffff001) {
            local_58 = &system_heap_ops;
            local_60 = param_1;
            local_50 = puVar6;
            uVar7 = dma_heap_add(&local_60);
            if (uVar7 < 0xfffffffffffff001) {
              dma_heap_get_dev(uVar7);
              dma_coerce_mask_and_coherent();
              puVar2 = secure_heaps;
              puVar1 = puVar6 + 2;
              uVar7 = __list_add_valid(puVar1,&secure_heaps,secure_heaps);
              if ((uVar7 & 1) != 0) {
                *(ulong **)(puVar2 + 8) = puVar1;
                puVar6[2] = (ulong)puVar2;
                puVar6[3] = (ulong)&secure_heaps;
                secure_heaps = (undefined *)puVar1;
              }
              _printk(&DAT_00109766,"qcom_secure_system_heap_create",param_1);
              if (param_2 != 0) {
                local_60 = param_2;
                uVar7 = dma_heap_add(&local_60);
                if (uVar7 < 0xfffffffffffff001) {
                  dma_heap_get_dev(uVar7);
                  dma_coerce_mask_and_coherent();
                  _printk(&DAT_00109766,"qcom_secure_system_heap_create",param_2);
                }
                else {
                  _printk(&DAT_0010980e,"qcom_secure_system_heap_create",param_2);
                }
              }
              goto LAB_001056f0;
            }
            dynamic_page_pool_release_pools(*puVar6);
          }
          kfree(puVar6);
          goto LAB_001056d4;
        }
      }
      uVar7 = 0xfffffff4;
    }
  }
LAB_001056d4:
  _printk(&DAT_0010980e,"qcom_secure_system_heap_create",param_1,uVar7 & 0xffffffff);
LAB_001056f0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dma_coerce_mask_and_coherent @ 00105860 size=68
// signature: undefined dma_coerce_mask_and_coherent(void)
// callers: [qcom_secure_system_heap_create]
//------------------------------------------------------------

void dma_coerce_mask_and_coherent(long param_1)

{
  int iVar1;
  
  *(long *)(param_1 + 0x298) = param_1 + 0x2a0;
  iVar1 = dma_set_mask(param_1,0xffffffffffffffff);
  if (iVar1 == 0) {
    dma_set_coherent_mask(param_1,0xffffffffffffffff);
  }
  return;
}



//------------------------------------------------------------
// secure_system_heap_prefetch_work @ 001058a8 size=1256
// signature: undefined secure_system_heap_prefetch_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void secure_system_heap_prefetch_work(void)

{
  undefined *puVar1;
  undefined *puVar2;
  char cVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long *plVar7;
  ulong uVar8;
  long lVar9;
  undefined8 *puVar10;
  long *plVar11;
  ulong *puVar12;
  undefined1 uVar13;
  long ****pppplVar14;
  uint uVar15;
  long ****pppplVar16;
  undefined **ppuVar17;
  undefined **ppuVar18;
  undefined *puVar19;
  long ****local_78;
  long ****local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  uVar6 = _raw_spin_lock_irqsave(&work_lock);
  if ((undefined **)prefetch_list != &prefetch_list) {
    ppuVar17 = (undefined **)prefetch_list;
    do {
      ppuVar18 = (undefined **)*ppuVar17;
      uVar8 = __list_del_entry_valid(ppuVar17);
      if ((uVar8 & 1) != 0) {
        puVar1 = *ppuVar17;
        plVar7 = (long *)ppuVar17[1];
        *(long **)(puVar1 + 8) = plVar7;
        *plVar7 = (long)puVar1;
      }
      *ppuVar17 = (undefined *)0xdead000000000100;
      ppuVar17[1] = (undefined *)0xdead000000000122;
      _raw_spin_unlock_irqrestore(&work_lock,uVar6);
      cVar3 = *(char *)(ppuVar17 + 4);
      plVar7 = (long *)dma_heap_get_drvdata(ppuVar17[2]);
      if (cVar3 == '\0') {
        puVar1 = ppuVar17[2];
        puVar2 = ppuVar17[3];
        local_78 = (long ****)&local_78;
        local_70 = (long ****)&local_78;
        if (get_sys_heap_page_pool_qcom_sys_heap_pools == 0) {
          lVar9 = dma_heap_find("qcom,system");
          if (lVar9 == 0) {
            _printk(&DAT_00109960);
          }
          else {
            lVar9 = dma_heap_get_drvdata();
            get_sys_heap_page_pool_qcom_sys_heap_pools = *(long *)(lVar9 + 8);
          }
          if (get_sys_heap_page_pool_qcom_sys_heap_pools == 0) {
            _printk(&DAT_00109d04,"get_pages");
            goto LAB_00105950;
          }
        }
        lVar9 = get_sys_heap_page_pool_qcom_sys_heap_pools;
        iVar5 = 0;
        if (puVar2 != (undefined *)0x0) {
          uVar13 = 9;
          puVar19 = puVar2;
          do {
            puVar10 = (undefined8 *)qcom_sys_heap_alloc_largest_available(lVar9,puVar19,uVar13,0);
            pppplVar16 = local_70;
            if (puVar10 == (undefined8 *)0x0) {
              _printk(&DAT_0010a139,"get_pages",puVar19,puVar2);
              plVar11 = (long *)0xfffffffffffffff4;
              goto LAB_00105bcc;
            }
            pppplVar14 = (long ****)(puVar10 + 1);
            uVar8 = __list_add_valid(pppplVar14,local_70,&local_78);
            if ((uVar8 & 1) != 0) {
              puVar10[1] = &local_78;
              puVar10[2] = pppplVar16;
              local_70 = pppplVar14;
              *pppplVar16 = (long ***)pppplVar14;
            }
            if (((uint)*puVar10 >> 0x10 & 1) == 0) {
              uVar8 = 0;
              if (((uint)*puVar10 >> 0x10 & 1) != 0) goto LAB_001059e4;
LAB_00105a60:
              uVar13 = 0;
            }
            else {
              uVar8 = (ulong)*(byte *)((long)puVar10 + 0x51);
              if (((uint)*puVar10 >> 0x10 & 1) == 0) goto LAB_00105a60;
LAB_001059e4:
              uVar13 = *(undefined1 *)((long)puVar10 + 0x51);
            }
            iVar5 = iVar5 + 1;
            puVar19 = puVar19 + (-0x1000L << (uVar8 & 0x3f));
          } while (puVar19 != (undefined *)0x0);
        }
        plVar11 = (long *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x10);
        if (plVar11 == (long *)0x0) {
          plVar11 = (long *)0xfffffffffffffff4;
LAB_00105bcc:
          pppplVar16 = local_78;
          while ((long *****)pppplVar16 != &local_78) {
            pppplVar14 = pppplVar16 + -1;
            if (((uint)*pppplVar14 >> 0x10 & 1) == 0) {
              uVar13 = 0;
            }
            else {
              uVar13 = *(undefined1 *)((long)pppplVar16 + 0x49);
            }
            pppplVar16 = (long ****)*pppplVar16;
            __free_pages(pppplVar14,uVar13);
          }
        }
        else {
          iVar5 = sg_alloc_table(plVar11,iVar5,0xcc0);
          if (iVar5 != 0) {
            _printk(&DAT_00109d3a,"get_pages",iVar5);
            kfree(plVar11);
            plVar11 = (long *)(long)iVar5;
            goto LAB_00105bcc;
          }
          if ((long *****)local_78 != &local_78) {
            puVar12 = (ulong *)*plVar11;
            pppplVar16 = local_78;
            do {
              pppplVar14 = pppplVar16 + -1;
              if (((uint)*pppplVar14 >> 0x10 & 1) == 0) {
                uVar8 = 0;
              }
              else {
                uVar8 = (ulong)*(byte *)((long)pppplVar16 + 0x49);
              }
              if (((ulong)pppplVar14 & 3) != 0) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105d90);
                (*pcVar4)();
              }
              *(undefined4 *)(puVar12 + 1) = 0;
              *(int *)((long)puVar12 + 0xc) = (int)(0x1000L << (uVar8 & 0x3f));
              *puVar12 = *puVar12 & 3 | (ulong)pppplVar14;
              puVar12 = (ulong *)sg_next();
              pppplVar16 = (long ****)*pppplVar16;
            } while ((long *****)pppplVar16 != &local_78);
          }
          uVar6 = dma_heap_get_dev(puVar1);
          dma_map_sgtable(uVar6,plVar11,0,0);
          uVar6 = dma_heap_get_dev(puVar1);
          dma_unmap_sg_attrs(uVar6,*plVar11,*(undefined4 *)((long)plVar11 + 0xc),0,0);
        }
        if (plVar11 < (long *)0xfffffffffffff001) {
          iVar5 = hyp_assign_sg_from_flags(plVar11,(long)(int)plVar7[1],1);
          if (iVar5 == 0) {
            if (*(int *)((long)plVar11 + 0xc) != 0) {
              uVar15 = 0;
              puVar12 = (ulong *)*plVar11;
              do {
                puVar10 = (undefined8 *)(*puVar12 & 0xfffffffffffffffc);
                if ((((uint)*puVar10 >> 0x10 & 1) == 0) || (*(char *)((long)puVar10 + 0x51) != '\t')
                   ) {
                  if ((((uint)*puVar10 >> 0x10 & 1) == 0) ||
                     (*(char *)((long)puVar10 + 0x51) != '\x04')) {
                    if (((uint)*puVar10 >> 0x10 & 1) == 0) {
                      lVar9 = 2;
                    }
                    else {
                      lVar9 = 2;
                      if (*(char *)((long)puVar10 + 0x51) != '\0') {
                        lVar9 = 3;
                      }
                    }
                  }
                  else {
                    lVar9 = 1;
                  }
                }
                else {
                  lVar9 = 0;
                }
                dynamic_page_pool_free(*(undefined8 *)(*plVar7 + lVar9 * 8));
                uVar15 = uVar15 + 1;
                puVar12 = (ulong *)sg_next(puVar12);
              } while (uVar15 < *(uint *)((long)plVar11 + 0xc));
            }
          }
          else if (*(int *)((long)plVar11 + 0xc) != 0) {
            uVar15 = 0;
            puVar12 = (ulong *)*plVar11;
            do {
              puVar10 = (undefined8 *)(*puVar12 & 0xfffffffffffffffc);
              if (((uint)*puVar10 >> 0x10 & 1) == 0) {
                uVar13 = 0;
              }
              else {
                uVar13 = *(undefined1 *)((long)puVar10 + 0x51);
              }
              __free_pages(puVar10,uVar13);
              uVar15 = uVar15 + 1;
              puVar12 = (ulong *)sg_next(puVar12);
            } while (uVar15 < *(uint *)((long)plVar11 + 0xc));
          }
          sg_free_table(plVar11);
        }
      }
      else {
        dynamic_page_pool_shrink_high_and_low(*plVar7,3,(ulong)ppuVar17[3] >> 0xc);
      }
LAB_00105950:
      kfree(ppuVar17);
      uVar6 = _raw_spin_lock_irqsave(&work_lock);
      ppuVar17 = ppuVar18;
    } while (ppuVar18 != &prefetch_list);
  }
  _raw_spin_unlock_irqrestore(&work_lock,uVar6);
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// system_heap_allocate @ 00105d94 size=1640
// signature: undefined system_heap_allocate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong system_heap_allocate(undefined8 param_1,ulong param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  ulong *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  undefined1 uVar12;
  int *piVar13;
  int iVar14;
  long *****ppppplVar15;
  long *****ppppplVar16;
  long *****ppppplVar17;
  long *plVar18;
  int iVar19;
  ulong uVar20;
  byte bVar21;
  undefined8 local_f0;
  long *****local_e8;
  long *****local_e0;
  long *****local_d8;
  long *****local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined *local_b8;
  undefined *puStack_b0;
  undefined *local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long local_70;
  
  lVar8 = sp_el0;
  local_70 = *(long *)(lVar8 + 0x638);
  local_c8 = 0;
  uStack_c0 = 0;
  local_f0 = 0;
  local_88 = DAT_00109068;
  uStack_80 = DAT_00109070;
  local_78 = DAT_00109078;
  local_a8 = DAT_00109048;
  uStack_a0 = DAT_00109050;
  local_d8 = (long *****)&local_d8;
  local_98 = DAT_00109058;
  uStack_90 = DAT_00109060;
  local_b8 = PTR_s_qcom_dma_heaps_00109038;
  puStack_b0 = PTR___this_module_00109040;
  local_e8 = (long *****)&local_e8;
  local_e0 = local_e8;
  local_d0 = local_d8;
  puVar6 = (undefined8 *)kmalloc_trace(_of_get_next_available_child,0xdc0,0xb0);
  if (puVar6 == (undefined8 *)0x0) {
    uVar20 = 0xfffffffffffffff4;
    goto LAB_00106384;
  }
  plVar7 = (long *)dma_heap_get_drvdata(param_1);
  qcom_sg_buffer_init(puVar6);
  *puVar6 = param_1;
  puVar6[9] = param_2;
  *(undefined1 *)(puVar6 + 0xe) = 1;
  puVar6[0x14] = system_heap_free;
  if (param_2 == 0) {
    iVar14 = 0;
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    iVar14 = 0;
    bVar21 = 9;
    puVar3 = (ulong *)sp_el0;
    uVar20 = param_2;
    do {
      if (((*puVar3 & 1) != 0) && ((*(byte *)((long)puVar3 + 0x8c9) & 1) != 0)) {
LAB_0010612c:
        iVar4 = 0;
LAB_00106130:
        iVar19 = -0xc;
        goto LAB_001062a4;
      }
      plVar18 = (long *)*plVar7;
      if (get_sys_heap_page_pool_qcom_sys_heap_pools == 0) {
        lVar8 = dma_heap_find("qcom,system");
        if (lVar8 == 0) {
          _printk(&DAT_00109960);
          if (get_sys_heap_page_pool_qcom_sys_heap_pools == 0) goto LAB_001060dc;
          goto LAB_00105ee4;
        }
        lVar8 = dma_heap_get_drvdata();
        get_sys_heap_page_pool_qcom_sys_heap_pools = *(long *)(lVar8 + 8);
        if (get_sys_heap_page_pool_qcom_sys_heap_pools != 0) goto LAB_00105ee4;
LAB_001060dc:
        iVar4 = (int)get_sys_heap_page_pool_qcom_sys_heap_pools;
        _printk(&DAT_00109d04,"alloc_largest_available");
        goto LAB_00106130;
      }
LAB_00105ee4:
      lVar8 = get_sys_heap_page_pool_qcom_sys_heap_pools;
      if ((bVar21 < 9) || (uVar20 < 0x200000)) {
LAB_00105f40:
        if (bVar21 < 4) {
LAB_00105fb4:
          if (0xfff < uVar20) goto LAB_00105fcc;
        }
        else {
LAB_00105f48:
          if (uVar20 < 0x10000) goto LAB_00105fb4;
          uVar9 = _raw_spin_lock_irqsave(plVar18[1] + 0x40);
          piVar13 = (int *)plVar18[1];
          if ((*piVar13 == 0) && (piVar13[1] == 0)) {
            _raw_spin_unlock_irqrestore(piVar13 + 0x10,uVar9);
          }
          else {
            puVar10 = (undefined8 *)dynamic_page_pool_remove(piVar13,*piVar13 != 0);
            _raw_spin_unlock_irqrestore(plVar18[1] + 0x40,uVar9);
            if (puVar10 != (undefined8 *)0x0) goto LAB_00106018;
          }
LAB_00105fcc:
          uVar9 = _raw_spin_lock_irqsave(plVar18[2] + 0x40);
          piVar13 = (int *)plVar18[2];
          if ((*piVar13 == 0) && (piVar13[1] == 0)) {
            _raw_spin_unlock_irqrestore(piVar13 + 0x10,uVar9);
          }
          else {
            puVar10 = (undefined8 *)dynamic_page_pool_remove(piVar13,*piVar13 != 0);
            _raw_spin_unlock_irqrestore(plVar18[2] + 0x40,uVar9);
            if (puVar10 != (undefined8 *)0x0) goto LAB_00106018;
          }
        }
        puVar10 = (undefined8 *)qcom_sys_heap_alloc_largest_available(lVar8,uVar20,bVar21,0);
        ppppplVar15 = local_e0;
        if (puVar10 == (undefined8 *)0x0) goto LAB_0010612c;
        ppppplVar16 = (long *****)(puVar10 + 1);
        iVar14 = iVar14 + 1;
        uVar11 = __list_add_valid(ppppplVar16,local_e0,&local_e8);
        if ((uVar11 & 1) != 0) {
          ppppplVar17 = (long *****)&local_e8;
          local_e0 = ppppplVar16;
          goto LAB_00106090;
        }
      }
      else {
        uVar9 = _raw_spin_lock_irqsave(*plVar18 + 0x40);
        piVar13 = (int *)*plVar18;
        if ((*piVar13 == 0) && (piVar13[1] == 0)) {
          _raw_spin_unlock_irqrestore(piVar13 + 0x10,uVar9);
          if (3 < bVar21) goto LAB_00105f48;
          goto LAB_00105fb4;
        }
        puVar10 = (undefined8 *)dynamic_page_pool_remove(piVar13,*piVar13 != 0);
        _raw_spin_unlock_irqrestore(*plVar18 + 0x40,uVar9);
        if (puVar10 == (undefined8 *)0x0) goto LAB_00105f40;
LAB_00106018:
        ppppplVar15 = local_d0;
        ppppplVar16 = (long *****)(puVar10 + 1);
        uVar11 = __list_add_valid(ppppplVar16,local_d0,&local_d8);
        if ((uVar11 & 1) != 0) {
          ppppplVar17 = (long *****)&local_d8;
          local_d0 = ppppplVar16;
LAB_00106090:
          puVar10[1] = ppppplVar17;
          puVar10[2] = ppppplVar15;
          *ppppplVar15 = (long ****)ppppplVar16;
        }
      }
      if (((uint)*puVar10 >> 0x10 & 1) == 0) {
        uVar11 = 0;
        if (((uint)*puVar10 >> 0x10 & 1) != 0) goto LAB_00105e88;
LAB_001060bc:
        bVar21 = 0;
      }
      else {
        uVar11 = (ulong)*(byte *)((long)puVar10 + 0x51);
        if (((uint)*puVar10 >> 0x10 & 1) == 0) goto LAB_001060bc;
LAB_00105e88:
        bVar21 = *(byte *)((long)puVar10 + 0x51);
      }
      iVar4 = iVar4 + 1;
      uVar20 = (-0x1000L << (uVar11 & 0x3f)) + uVar20;
    } while (uVar20 != 0);
  }
  puVar10 = puVar6 + 10;
  iVar4 = sg_alloc_table(puVar10,iVar4,0xcc0);
  if (iVar4 == 0) {
    uVar9 = *puVar10;
    if (iVar14 == 0) {
      page_list_merge(&local_d8,&local_e8,uVar9,0);
LAB_0010617c:
      uVar5 = msm_secure_get_vmid_perms((int)plVar7[1]);
      local_f0._4_4_ = uVar5;
      uVar5 = get_secure_vmid((long)(int)plVar7[1]);
      local_f0 = CONCAT44(local_f0._4_4_,uVar5);
      uVar20 = mem_buf_vmperm_alloc_staticvm
                         (puVar10,&local_f0,(long)&local_f0 + 4,1,qcom_sg_release,puVar6 + 0x15);
      puVar6[0xf] = uVar20;
      if (uVar20 < 0xfffffffffffff001) {
        local_b8 = (undefined *)dma_heap_get_name(param_1);
        uStack_a0 = puVar6[9];
        local_a8 = &DAT_00109508;
        local_98 = CONCAT44(local_98._4_4_,param_3);
        local_88 = puVar6;
        uVar20 = mem_buf_dma_buf_export(&local_b8);
        if (uVar20 < 0xfffffffffffff001) {
          qcom_store_dma_buf_fops(*(undefined8 *)(uVar20 + 8));
          if (iVar14 != 0) {
            sg_free_table(&local_c8);
          }
          plVar7 = plVar7 + 4;
          Hint_Prefetch(plVar7,2,0,1);
          do {
            cVar1 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(plVar7,0x10);
            if (bVar2) {
              *plVar7 = *plVar7 + param_2;
              cVar1 = ExclusiveMonitorsStatus();
            }
          } while (cVar1 != '\0');
          goto LAB_00106384;
        }
        mem_buf_vmperm_free(puVar6[0xf]);
      }
      iVar19 = (int)uVar20;
      iVar4 = hyp_unassign_sg_from_flags(&local_c8,(long)(int)plVar7[1],1);
      if (iVar14 != 0) {
LAB_00106294:
        sg_free_table(&local_c8);
      }
    }
    else {
      iVar4 = sg_alloc_table(&local_c8,iVar14,0xcc0);
      if (iVar4 == 0) {
        page_list_merge(&local_d8,&local_e8,uVar9,local_c8);
        uVar9 = dma_heap_get_dev(param_1);
        dma_map_sgtable(uVar9,&local_c8,0,0);
        uVar9 = dma_heap_get_dev(param_1);
        dma_unmap_sg_attrs(uVar9,local_c8,uStack_c0._4_4_,0,0);
        iVar4 = hyp_assign_sg_from_flags(&local_c8,(long)(int)plVar7[1],1);
        if (iVar4 == 0) goto LAB_0010617c;
        iVar19 = -0xc;
        goto LAB_00106294;
      }
      iVar4 = 0;
      iVar19 = -0xc;
    }
    sg_free_table(puVar10);
  }
  else {
    iVar4 = 0;
    iVar19 = -0xc;
  }
LAB_001062a4:
  ppppplVar15 = local_e8;
  ppppplVar16 = local_d8;
  while (local_e8 = ppppplVar15, (long ******)ppppplVar16 != &local_d8) {
    ppppplVar15 = ppppplVar16 + -1;
    ppppplVar17 = (long *****)*ppppplVar16;
    if ((((uint)*ppppplVar15 >> 0x10 & 1) == 0) || (*(char *)((long)ppppplVar16 + 0x49) != '\t')) {
      if ((((uint)*ppppplVar15 >> 0x10 & 1) == 0) || (*(char *)((long)ppppplVar16 + 0x49) != '\x04')
         ) {
        if (((uint)*ppppplVar15 >> 0x10 & 1) == 0) {
          lVar8 = 2;
        }
        else {
          lVar8 = 2;
          if (*(char *)((long)ppppplVar16 + 0x49) != '\0') {
            lVar8 = 3;
          }
        }
      }
      else {
        lVar8 = 1;
      }
    }
    else {
      lVar8 = 0;
    }
    dynamic_page_pool_free(*(undefined8 *)(*plVar7 + lVar8 * 8));
    ppppplVar15 = local_e8;
    ppppplVar16 = ppppplVar17;
  }
  if ((iVar4 == 0) && ((long ******)ppppplVar15 != &local_e8)) {
    do {
      ppppplVar16 = ppppplVar15 + -1;
      if (((uint)*ppppplVar16 >> 0x10 & 1) == 0) {
        uVar12 = 0;
      }
      else {
        uVar12 = *(undefined1 *)((long)ppppplVar15 + 0x49);
      }
      ppppplVar15 = (long *****)*ppppplVar15;
      __free_pages(ppppplVar16,uVar12);
    } while ((long ******)ppppplVar15 != &local_e8);
  }
  kfree(puVar6);
  uVar20 = (ulong)iVar19;
LAB_00106384:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20;
}



//------------------------------------------------------------
// get_pool_size_bytes @ 0010640c size=104
// signature: undefined get_pool_size_bytes(void)
// callers: []
//------------------------------------------------------------

long get_pool_size_bytes(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = (long *)dma_heap_get_drvdata();
  iVar1 = dynamic_page_pool_total(*(undefined8 *)*plVar4,1);
  iVar2 = dynamic_page_pool_total(*(undefined8 *)(*plVar4 + 8),1);
  iVar3 = dynamic_page_pool_total(*(undefined8 *)(*plVar4 + 0x10),1);
  return ((long)iVar1 + (long)iVar2 + (long)iVar3) * 0x1000;
}



//------------------------------------------------------------
// system_heap_free @ 00106478 size=276
// signature: undefined system_heap_free(void)
// callers: []
//------------------------------------------------------------

void system_heap_free(undefined8 *param_1)

{
  char cVar1;
  bool bVar2;
  long *plVar3;
  undefined8 *puVar4;
  long lVar5;
  ulong *puVar6;
  uint uVar7;
  
  plVar3 = (long *)dma_heap_get_drvdata(*param_1);
  if (*(int *)(param_1 + 0xb) != 0) {
    uVar7 = 0;
    puVar6 = (ulong *)param_1[10];
    do {
      puVar4 = (undefined8 *)(*puVar6 & 0xfffffffffffffffc);
      if ((((uint)*puVar4 >> 0x10 & 1) == 0) || (*(char *)((long)puVar4 + 0x51) != '\t')) {
        if ((((uint)*puVar4 >> 0x10 & 1) == 0) || (*(char *)((long)puVar4 + 0x51) != '\x04')) {
          if (((uint)*puVar4 >> 0x10 & 1) == 0) {
            lVar5 = 2;
          }
          else {
            lVar5 = 2;
            if (*(char *)((long)puVar4 + 0x51) != '\0') {
              lVar5 = 3;
            }
          }
        }
        else {
          lVar5 = 1;
        }
      }
      else {
        lVar5 = 0;
      }
      dynamic_page_pool_free(*(undefined8 *)(*plVar3 + lVar5 * 8));
      uVar7 = uVar7 + 1;
      puVar6 = (ulong *)sg_next(puVar6);
    } while (uVar7 < *(uint *)(param_1 + 0xb));
  }
  lVar5 = param_1[9];
  plVar3 = plVar3 + 4;
  Hint_Prefetch(plVar3,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(plVar3,0x10);
    if (bVar2) {
      *plVar3 = *plVar3 - lVar5;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  sg_free_table(param_1 + 10);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// page_list_merge @ 00106598 size=472
// signature: undefined page_list_merge(void)
// callers: [system_heap_allocate]
//------------------------------------------------------------

void page_list_merge(long *param_1,long *param_2,ulong *param_3,ulong *param_4)

{
  code *pcVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  puVar4 = (undefined8 *)(*param_1 + -8);
  puVar5 = (undefined8 *)(*param_2 + -8);
  do {
    if ((puVar4 + 1 == param_1) || (puVar5 + 1 == param_2)) {
      if (puVar5 + 1 != param_2) {
        if (((uint)*puVar5 >> 0x10 & 1) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (ulong)*(byte *)((long)puVar5 + 0x51);
        }
        if (((ulong)puVar5 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106764);
          (*pcVar1)();
        }
        goto LAB_001066ec;
      }
      if (puVar4 + 1 != param_1) {
        if (((uint)*puVar4 >> 0x10 & 1) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (ulong)*(byte *)((long)puVar4 + 0x51);
        }
        if (((ulong)puVar4 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106770);
          (*pcVar1)();
        }
        goto LAB_00106720;
      }
    }
    else {
      if (((uint)*puVar5 >> 0x10 & 1) == 0) {
        uVar2 = 0;
        if (((uint)*puVar4 >> 0x10 & 1) != 0) goto LAB_00106648;
LAB_00106674:
        uVar3 = 0;
      }
      else {
        uVar2 = (ulong)*(byte *)((long)puVar5 + 0x51);
        if (((uint)*puVar4 >> 0x10 & 1) == 0) goto LAB_00106674;
LAB_00106648:
        uVar3 = (ulong)*(byte *)((long)puVar4 + 0x51);
      }
      if ((ulong)(0x1000L << (uVar2 & 0x3f)) < (ulong)(0x1000L << (uVar3 & 0x3f))) {
        if (((uint)*puVar4 >> 0x10 & 1) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (ulong)*(byte *)((long)puVar4 + 0x51);
        }
        if (((ulong)puVar4 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106768);
          (*pcVar1)();
        }
LAB_00106720:
        *(undefined4 *)(param_3 + 1) = 0;
        *(int *)((long)param_3 + 0xc) = (int)(0x1000L << (uVar2 & 0x3f));
        *param_3 = *param_3 & 3 | (ulong)puVar4;
        puVar4 = (undefined8 *)(puVar4[1] + -8);
      }
      else {
        if (((uint)*puVar5 >> 0x10 & 1) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (ulong)*(byte *)((long)puVar5 + 0x51);
        }
        if (((ulong)puVar5 & 3) != 0) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10676c);
          (*pcVar1)();
        }
LAB_001066ec:
        *(undefined4 *)(param_3 + 1) = 0;
        *(int *)((long)param_3 + 0xc) = (int)(0x1000L << (uVar2 & 0x3f));
        *param_3 = *param_3 & 3 | (ulong)puVar5;
        if (((uint)*puVar5 >> 0x10 & 1) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (ulong)*(byte *)((long)puVar5 + 0x51);
        }
        *(undefined4 *)(param_4 + 1) = 0;
        *(int *)((long)param_4 + 0xc) = (int)(0x1000L << (uVar2 & 0x3f));
        *param_4 = *param_4 & 3 | (ulong)puVar5;
        puVar5 = (undefined8 *)(puVar5[1] + -8);
        param_4 = (ulong *)sg_next(param_4);
      }
    }
    param_3 = (ulong *)sg_next(param_3);
    if (param_3 == (ulong *)0x0) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// get_secure_vmid @ 00106774 size=176
// signature: undefined get_secure_vmid(void)
// callers: [system_heap_allocate, qcom_secure_system_heap_create]
//------------------------------------------------------------

undefined4 get_secure_vmid(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 >> 0x10 & 1) != 0) {
    return 1;
  }
  if ((param_1 >> 0x11 & 1) != 0) {
    return 8;
  }
  if ((param_1 >> 0x12 & 1) != 0) {
    return 9;
  }
  if ((param_1 >> 0x13 & 1) != 0) {
    return 10;
  }
  if ((param_1 >> 0x14 & 1) != 0) {
    return 0xb;
  }
  if ((param_1 >> 0x15 & 1) != 0) {
    return 0xd;
  }
  if ((param_1 >> 0x19 & 1) != 0) {
    return 0x11;
  }
  if ((param_1 >> 0x1a & 1) != 0) {
    return 0x12;
  }
  if ((param_1 >> 0x1b & 1) != 0) {
    return 0x1d;
  }
  if ((param_1 >> 0x17 & 1) != 0) {
    return 0x1a;
  }
  if ((param_1 >> 0x18 & 1) != 0) {
    return 0x22;
  }
  if ((param_1 >> 0x1e & 1) != 0) {
    return 0x24;
  }
  if ((param_1 >> 0x1d & 1) != 0) {
    return 0x2a;
  }
  uVar1 = 0xffffffea;
  if ((param_1 & 0x10000000) != 0) {
    uVar1 = 0xf;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_is_buffer_hlos_accessible @ 00106828 size=16
// signature: undefined qcom_is_buffer_hlos_accessible(void)
// callers: [sc_heap_free]
//------------------------------------------------------------

bool qcom_is_buffer_hlos_accessible(ulong param_1)

{
  return (param_1 & 0x40400000) != 0;
}



//------------------------------------------------------------
// hyp_unassign_sg_from_flags @ 0010683c size=384
// signature: undefined hyp_unassign_sg_from_flags(void)
// callers: [system_heap_allocate, free_secure_pages]
//------------------------------------------------------------

int hyp_unassign_sg_from_flags(undefined8 *param_1,ulong param_2,ulong param_3)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  ulong *puVar6;
  uint uVar7;
  undefined4 local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  uVar4 = __sw_hweight64(param_2 & 0x7fff8000);
  if (((uVar4 & 0xffffffff) >> 0x1f == 0) &&
     (lVar5 = __kmalloc((long)(uVar4 << 0x20) >> 0x1e,0xdc0), lVar5 != 0)) {
    iVar3 = populate_vm_list(param_2,lVar5,uVar4 & 0xffffffff);
    if (iVar3 == 0) {
      local_50 = 7;
      uStack_4c = 3;
      if ((int)uVar4 < 1) {
        _printk(&DAT_00109eb4,"hyp_unassign_sg");
        iVar3 = -0x16;
      }
      else {
        iVar3 = hyp_assign_table(param_1,lVar5,uVar4 & 0xffffffff,&uStack_4c,&local_50,1);
        if ((iVar3 == 0) && ((param_3 & 1) != 0)) {
          if (*(int *)(param_1 + 1) != 0) {
            uVar7 = 0;
            puVar6 = (ulong *)*param_1;
            do {
              puVar6 = (ulong *)(*puVar6 & 0xfffffffffffffffc);
              Hint_Prefetch(puVar6,2,0,1);
              do {
                cVar1 = '\x01';
                bVar2 = (bool)ExclusiveMonitorPass(puVar6,0x10);
                if (bVar2) {
                  *puVar6 = *puVar6 & 0xffffffffffffdfff;
                  cVar1 = ExclusiveMonitorsStatus();
                }
              } while (cVar1 != '\0');
              uVar7 = uVar7 + 1;
              puVar6 = (ulong *)sg_next();
            } while (uVar7 < *(uint *)(param_1 + 1));
          }
          iVar3 = 0;
        }
      }
    }
    else {
      _printk(&DAT_001098f2,"hyp_unassign_sg_from_flags");
    }
    kfree(lVar5);
  }
  else {
    iVar3 = -0xc;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// populate_vm_list @ 001069c0 size=288
// signature: undefined populate_vm_list(void)
// callers: [get_vmperm_from_ion_flags, hyp_assign_sg_from_flags, hyp_unassign_sg_from_flags]
//------------------------------------------------------------

undefined8 populate_vm_list(ulong param_1,long param_2,int param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  
  if ((param_1 & 0x7fff8000) == 0) {
    return 0xffffffea;
  }
  uVar4 = 0;
  do {
    param_3 = param_3 + -1;
    uVar4 = -1L << (uVar4 & 0x3f) & param_1 & 0x7fff8000;
    uVar4 = (uVar4 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar4 & 0x5555555555555555) << 1;
    uVar4 = (uVar4 & 0xcccccccccccccccc) >> 2 | (uVar4 & 0x3333333333333333) << 2;
    uVar4 = (uVar4 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar4 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar2 = (uVar4 & 0xff00ff00ff00ff00) >> 8;
    uVar2 = LZCOUNT(((uVar2 & 0xffff0000ffff0000 | (uVar4 & 0xff00ff00ff00ff) << 8) >> 0x10 |
                    (uVar2 & 0xffff0000ffff) << 0x10) << 0x20);
    if (0x3f < uVar2) {
      return 0;
    }
    uVar1 = 1;
    uVar4 = 1L << (uVar2 & 0x3f);
    uVar3 = (uint)uVar4;
    if ((uVar3 >> 0x10 & 1) == 0) {
      if ((uVar3 >> 0x11 & 1) == 0) {
        if ((uVar3 >> 0x12 & 1) == 0) {
          if ((uVar3 >> 0x13 & 1) == 0) {
            if ((uVar3 >> 0x14 & 1) == 0) {
              if ((uVar3 >> 0x15 & 1) == 0) {
                if ((uVar3 >> 0x19 & 1) == 0) {
                  if ((uVar3 >> 0x1a & 1) == 0) {
                    if ((uVar3 >> 0x1b & 1) == 0) {
                      if ((uVar3 >> 0x17 & 1) == 0) {
                        if ((uVar3 >> 0x18 & 1) == 0) {
                          if ((uVar3 >> 0x1e & 1) == 0) {
                            if ((uVar3 >> 0x1d & 1) == 0) {
                              uVar1 = 0xffffffea;
                              if ((uVar4 & 0x10000000) != 0) {
                                uVar1 = 0xf;
                              }
                            }
                            else {
                              uVar1 = 0x2a;
                            }
                          }
                          else {
                            uVar1 = 0x24;
                          }
                        }
                        else {
                          uVar1 = 0x22;
                        }
                      }
                      else {
                        uVar1 = 0x1a;
                      }
                    }
                    else {
                      uVar1 = 0x1d;
                    }
                  }
                  else {
                    uVar1 = 0x12;
                  }
                }
                else {
                  uVar1 = 0x11;
                }
              }
              else {
                uVar1 = 0xd;
              }
            }
            else {
              uVar1 = 0xb;
            }
          }
          else {
            uVar1 = 10;
          }
        }
        else {
          uVar1 = 9;
        }
      }
      else {
        uVar1 = 8;
      }
    }
    if (0x7fffffff < uVar1 && (uVar4 & 0x400000) != 0) {
      uVar1 = 3;
    }
    if ((int)uVar1 < 0) {
      return 0xffffffea;
    }
    if (param_3 == -1) {
      return 0xffffffea;
    }
    *(uint *)(param_2 + (long)param_3 * 4) = uVar1;
    uVar4 = uVar2 + 1;
  } while (uVar2 < 0x3f);
  return 0;
}



//------------------------------------------------------------
// hyp_assign_sg_from_flags @ 00106ae4 size=488
// signature: undefined hyp_assign_sg_from_flags(void)
// callers: [system_heap_allocate, secure_system_heap_prefetch_work]
//------------------------------------------------------------

int hyp_assign_sg_from_flags(undefined8 *param_1,ulong param_2,ulong param_3)

{
  char cVar1;
  bool bVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong *puVar10;
  uint uVar11;
  ulong uVar12;
  undefined4 local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  uVar7 = __sw_hweight64(param_2 & 0x7fff8000);
  if (((uVar7 & 0xffffffff) >> 0x1f == 0) &&
     (lVar8 = __kmalloc((long)(uVar7 << 0x20) >> 0x1e,0xdc0), lVar8 != 0)) {
    iVar5 = populate_vm_list(param_2,lVar8,uVar7 & 0xffffffff);
    if (iVar5 == 0) {
      local_5c = 3;
      if ((int)uVar7 < 1) {
        _printk(&DAT_00109ef1,"hyp_assign_sg");
        iVar5 = -0x16;
      }
      else {
        uVar3 = (uVar7 & 0xffffffff) * 4;
        lVar9 = __kmalloc(uVar3,0xdc0);
        if (lVar9 == 0) {
          iVar5 = -0xc;
        }
        else {
          uVar12 = 0;
          do {
            uVar6 = msm_secure_get_vmid_perms(*(undefined4 *)(lVar8 + uVar12));
            if ((uVar3 == uVar12) || (uVar3 <= uVar12)) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(1,0x106ccc);
              (*pcVar4)();
            }
            *(undefined4 *)(lVar9 + uVar12) = uVar6;
            uVar12 = uVar12 + 4;
          } while (uVar3 != uVar12);
          iVar5 = hyp_assign_table(param_1,&local_5c,1,lVar8,lVar9,uVar7 & 0xffffffff);
          if (iVar5 == 0) {
            if (((param_3 & 1) != 0) && (*(int *)(param_1 + 1) != 0)) {
              uVar11 = 0;
              puVar10 = (ulong *)*param_1;
              do {
                puVar10 = (ulong *)(*puVar10 & 0xfffffffffffffffc);
                Hint_Prefetch(puVar10,2,0,1);
                do {
                  cVar1 = '\x01';
                  bVar2 = (bool)ExclusiveMonitorPass(puVar10,0x10);
                  if (bVar2) {
                    *puVar10 = *puVar10 | 0x2000;
                    cVar1 = ExclusiveMonitorsStatus();
                  }
                } while (cVar1 != '\0');
                uVar11 = uVar11 + 1;
                puVar10 = (ulong *)sg_next();
              } while (uVar11 < *(uint *)(param_1 + 1));
            }
          }
          else {
            _printk(&DAT_00109aaf,"hyp_assign_sg");
          }
          kfree(lVar9);
        }
      }
    }
    else {
      _printk(&DAT_0010a2eb,"hyp_assign_sg_from_flags");
    }
    kfree(lVar8);
  }
  else {
    iVar5 = -0xc;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// get_vmperm_from_ion_flags @ 00106cd4 size=296
// signature: undefined get_vmperm_from_ion_flags(void)
// callers: [carveout_setup_vmperm, hyp_assign_from_flags]
//------------------------------------------------------------

undefined8
get_vmperm_from_ion_flags(ulong param_1,undefined8 *param_2,undefined8 *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  ulong uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  uVar4 = 0xffffffea;
  if (((param_2 != (undefined8 *)0x0) && (param_3 != (undefined8 *)0x0)) && (param_4 != (uint *)0x0)
     ) {
    uVar1 = __sw_hweight64(param_1);
    puVar5 = (undefined4 *)__kmalloc((ulong)uVar1 << 2,0xdc0);
    if (puVar5 != (undefined4 *)0x0) {
      puVar6 = (undefined4 *)__kmalloc((ulong)uVar1 << 2,0xdc0);
      if (puVar6 != (undefined4 *)0x0) {
        if (((param_1 & 0xffffffff80007fff) != 0) ||
           (iVar2 = populate_vm_list(param_1,puVar5,uVar1), iVar2 != 0)) {
          _printk(&DAT_0010a0a6,"get_vmperm_from_ion_flags",param_1);
          kfree(puVar6);
          kfree(puVar5);
          return 0xffffffea;
        }
        if (uVar1 != 0) {
          uVar7 = (ulong)uVar1;
          puVar8 = puVar6;
          puVar9 = puVar5;
          do {
            uVar3 = msm_secure_get_vmid_perms(*puVar9);
            uVar7 = uVar7 - 1;
            *puVar8 = uVar3;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          } while (uVar7 != 0);
        }
        *param_2 = puVar5;
        *param_3 = puVar6;
        *param_4 = uVar1;
        return 0;
      }
      kfree(puVar5);
    }
    uVar4 = 0xfffffff4;
  }
  return uVar4;
}



//------------------------------------------------------------
// hyp_assign_from_flags @ 00106e00 size=324
// signature: undefined hyp_assign_from_flags(void)
// callers: [qcom_secure_carveout_heap_create, qcom_secure_carveout_heap_restore]
//------------------------------------------------------------

int hyp_assign_from_flags(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  undefined8 local_68;
  uint local_5c;
  long local_58;
  long local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_50 = 0;
  local_58 = 0;
  local_5c = 0;
  local_68 = 8;
  iVar3 = get_vmperm_from_ion_flags(param_3,&local_50,&local_58,&local_5c);
  if (iVar3 == 0) {
    lVar4 = __kmalloc((ulong)local_5c << 3,0xdc0);
    if (lVar4 == 0) {
      iVar3 = -0xc;
    }
    else {
      if (local_5c != 0) {
        uVar5 = 0;
        do {
          uVar6 = -(uVar5 >> 0x1f) & 0xfffffffc00000000 | uVar5 << 2;
          puVar1 = (undefined4 *)(lVar4 + (long)(int)uVar5 * 8);
          uVar2 = (int)uVar5 + 1;
          uVar5 = (ulong)uVar2;
          *puVar1 = *(undefined4 *)(local_50 + uVar6);
          puVar1[1] = *(undefined4 *)(local_58 + uVar6);
        } while (local_5c != uVar2);
      }
      iVar3 = qcom_scm_assign_mem(param_1,param_2,&local_68,lVar4);
      if (iVar3 != 0) {
        _printk(&DAT_0010a172,"hyp_assign_from_flags",param_3);
      }
      kfree(lVar4);
    }
    kfree(local_58);
    kfree(local_50);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// cma_heap_allocate @ 00106f48 size=836
// signature: undefined cma_heap_allocate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong cma_heap_allocate(long param_1,long param_2,undefined4 param_3)

{
  long *plVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 *puVar7;
  long *plVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong *puVar13;
  ulong __n;
  ulong uVar14;
  ulong uVar15;
  undefined *local_b0;
  undefined *puStack_a8;
  undefined8 local_a0;
  long local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  long *local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_80 = DAT_001090b0;
  uStack_78 = DAT_001090b8;
  local_70 = DAT_001090c0;
  local_a0 = DAT_00109090;
  local_98 = DAT_00109098;
  local_90 = DAT_001090a0;
  uStack_88 = DAT_001090a8;
  local_b0 = PTR_s_qcom_dma_heaps_00109080;
  puStack_a8 = PTR___this_module_00109088;
  puVar7 = (undefined8 *)dma_heap_get_drvdata();
  plVar8 = (long *)kmalloc_trace(_of_get_next_available_child,0xdc0,0xc0);
  if (plVar8 == (long *)0x0) {
    uVar15 = 0xfffffffffffffff4;
    goto LAB_00107250;
  }
  uVar3 = *(uint *)(puVar7 + 1);
  __n = param_2 + 0xfffU & 0xfffffffffffff000;
  uVar14 = param_2 + 0xfffU >> 0xc;
  qcom_sg_buffer_init(plVar8 + 2);
  plVar8[2] = param_1;
  plVar8[0xb] = __n;
  uVar4 = *(undefined1 *)((long)puVar7 + 0xc);
  plVar8[0x16] = (long)cma_heap_free;
  *(undefined1 *)(plVar8 + 0x10) = uVar4;
  if (*(char *)((long)puVar7 + 0xd) == '\0') {
    uVar2 = 0;
    if (__n - 1 != 0xfff) {
      uVar2 = 0x40 - (int)LZCOUNT(__n - 1 >> 0xc);
    }
    if ((ulong)(long)(int)uVar2 <= (ulong)uVar3) {
      uVar3 = uVar2;
    }
    uVar11 = cma_alloc(*puVar7,uVar14,uVar3,0);
    if (uVar11 != 0) {
      memset((void *)((uVar11 & 0x3ffffffffffc0) << 6 | 0xff00000000000000),0,__n);
      goto LAB_001070f8;
    }
LAB_00107240:
    iVar6 = -0xc;
  }
  else {
    uVar9 = dma_heap_get_dev(param_1);
    iVar6 = dma_set_mask(uVar9,0xffffffffffffffff);
    if (iVar6 == 0) {
      dma_set_coherent_mask(uVar9,0xffffffffffffffff);
    }
    lVar10 = dma_alloc_attrs(uVar9,__n,plVar8 + 1,0xcc0,4);
    *plVar8 = lVar10;
    if (lVar10 == 0) {
      _dev_err(uVar9,"failed to allocate buffer\n");
      goto LAB_00107240;
    }
    uVar11 = (((ulong)plVar8[1] >> 6 & 0x3ffffffffffffc0) + (_memstart_addr >> 0xc) * -0x40) -
             0x200000000;
LAB_001070f8:
    plVar1 = plVar8 + 0xc;
    iVar6 = sg_alloc_table(plVar1,1,0xcc0);
    if (iVar6 == 0) {
      if ((uVar11 & 3) != 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x107294);
        (*pcVar5)();
      }
      puVar13 = (ulong *)plVar8[0xc];
      *(undefined4 *)(puVar13 + 1) = 0;
      *(int *)((long)puVar13 + 0xc) = (int)__n;
      *puVar13 = *puVar13 & 3 | uVar11;
      uVar12 = mem_buf_vmperm_alloc(plVar1,qcom_sg_release,plVar8 + 0x17);
      uVar15 = 0;
      plVar8[0x11] = uVar12;
      if (uVar12 < 0xfffffffffffff001) {
        if (((char)plVar8[0x10] != '\0') && (*(char *)((long)puVar7 + 0xd) == '\0')) {
          uVar9 = dma_heap_get_dev(param_1);
          dma_map_sgtable(uVar9,plVar1,0,0);
          uVar9 = dma_heap_get_dev(param_1);
          dma_unmap_sg_attrs(uVar9,plVar8[0xc],*(undefined4 *)((long)plVar8 + 0x6c),0,0);
        }
        local_b0 = (undefined *)dma_heap_get_name(param_1);
        local_98 = plVar8[0xb];
        local_90 = CONCAT44(local_90._4_4_,param_3);
        local_80 = plVar8 + 2;
        uVar15 = mem_buf_dma_buf_export(&local_b0,&qcom_sg_buf_ops);
        if (uVar15 < 0xfffffffffffff001) {
          qcom_store_dma_buf_fops(*(undefined8 *)(uVar15 + 8));
          goto LAB_00107250;
        }
        mem_buf_vmperm_free(plVar8[0x11]);
      }
      iVar6 = (int)uVar15;
      sg_free_table(plVar1);
      lVar10 = *plVar8;
    }
    else {
      lVar10 = *plVar8;
    }
    if (lVar10 == 0) {
      cma_release(*puVar7,uVar11,uVar14);
    }
    else {
      uVar9 = dma_heap_get_dev(param_1);
      dma_free_attrs(uVar9,__n,*plVar8,plVar8[1],0);
    }
  }
  kfree(plVar8);
  uVar15 = (ulong)iVar6;
LAB_00107250:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}



//------------------------------------------------------------
// cma_heap_free @ 00107298 size=132
// signature: undefined cma_heap_free(void)
// callers: []
//------------------------------------------------------------

void cma_heap_free(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)dma_heap_get_drvdata(*param_1);
  if (param_1[-2] == 0) {
    cma_release(*puVar1,*(ulong *)param_1[10] & 0xfffffffffffffffc,(ulong)param_1[9] >> 0xc);
  }
  else {
    uVar2 = dma_heap_get_dev(*param_1);
    dma_free_attrs(uVar2,param_1[9] + 0xfff & 0xfffffffffffff000,param_1[-2],param_1[-1],0);
  }
  sg_free_table(param_1 + 10);
  kfree(param_1 + -2);
  return;
}



//------------------------------------------------------------
// qcom_add_cma_heap @ 00107320 size=432
// signature: undefined qcom_add_cma_heap(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_add_cma_heap(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 local_a0;
  undefined **ppuStack_98;
  undefined8 *local_90;
  long local_88 [11];
  
  lVar4 = sp_el0;
  local_88[10] = *(long *)(lVar4 + 0x638);
  puVar2 = (undefined8 *)kmalloc_trace(_of_dma_configure_id,0xdc0,0x10);
  if (puVar2 == (undefined8 *)0x0) {
    uVar3 = 0xfffffff4;
  }
  else {
    local_a0 = *(undefined8 *)(param_1 + 8);
    uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x2d8);
    iVar1 = 8;
    if (*(int *)(param_1 + 0x30) != 0) {
      iVar1 = *(int *)(param_1 + 0x30);
    }
    *(undefined1 *)((long)puVar2 + 0xc) = *(undefined1 *)(param_1 + 0x28);
    *puVar2 = uVar5;
    *(int *)(puVar2 + 1) = iVar1;
    ppuStack_98 = &cma_heap_ops;
    local_90 = puVar2;
    uVar3 = dma_heap_add(&local_a0);
    if (uVar3 < 0xfffffffffffff001) {
      if (*(char *)((long)puVar2 + 0xc) != '\0') {
        lVar4 = dma_heap_get_dev(uVar3);
        *(long *)(lVar4 + 0x298) = lVar4 + 0x2a0;
        iVar1 = dma_set_mask(lVar4,0xffffffffffffffff);
        if (iVar1 == 0) {
          dma_set_coherent_mask(lVar4,0xffffffffffffffff);
        }
      }
      local_88[8] = 0;
      local_88[9] = 0;
      local_88[6] = 0;
      local_88[7] = 0;
      local_88[4] = 0;
      local_88[5] = 0;
      local_88[2] = 0;
      local_88[3] = 0;
      local_88[0] = 0;
      local_88[1] = 0;
      iVar1 = __of_parse_phandle_with_args
                        (*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x2e8),"memory-region",0,0,0,
                         local_88);
      if ((iVar1 == 0) && (local_88[0] != 0)) {
        lVar4 = of_find_property(local_88[0],"no-map",0);
        *(bool *)((long)puVar2 + 0xd) = lVar4 != 0;
        if ((lVar4 == 0) || (lVar4 = dma_heap_get_dev(uVar3), *(long *)(lVar4 + 0x2d0) != 0)) {
          uVar3 = 0;
        }
        else {
          uVar5 = *(undefined8 *)(*(long *)(param_1 + 0x20) + 0x2d0);
          lVar4 = dma_heap_get_dev(uVar3);
          uVar3 = 0;
          *(undefined8 *)(lVar4 + 0x2d0) = uVar5;
        }
      }
      else {
        uVar3 = 0;
        *(undefined1 *)((long)puVar2 + 0xd) = 0;
      }
    }
    else {
      kfree(puVar2);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// pages_sync_for_device @ 001074d4 size=200
// signature: undefined pages_sync_for_device(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pages_sync_for_device(undefined8 param_1,ulong param_2,uint param_3,undefined4 param_4)

{
  long lVar1;
  code *pcVar2;
  ulong local_58;
  long local_50;
  long local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_50 = 0;
  sg_init_table(&local_58,1);
  if ((param_2 & 3) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10759c);
    (*pcVar2)();
  }
  local_58 = local_58 & 3 | param_2;
  local_50 = (ulong)param_3 << 0x20;
  local_48 = (param_2 + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000;
  dma_sync_sg_for_device(param_1,&local_58,1,param_4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// carveout_setup_vmperm @ 001075a0 size=208
// signature: undefined carveout_setup_vmperm(void)
// callers: [__carveout_heap_allocate]
//------------------------------------------------------------

long carveout_setup_vmperm(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_3c = 0;
  if (*(char *)(param_1 + 0x58) == '\0') {
    lVar3 = mem_buf_vmperm_alloc(param_2 + 0x50,qcom_sg_release,param_2 + 0xa8);
  }
  else {
    iVar2 = get_vmperm_from_ion_flags(*(undefined4 *)(param_1 + -8),&local_30,&local_38,&local_3c);
    if (iVar2 == 0) {
      lVar3 = mem_buf_vmperm_alloc_staticvm
                        (param_2 + 0x50,local_30,local_38,local_3c,qcom_sg_release,param_2 + 0xa8);
      kfree(local_30);
      kfree(local_38);
    }
    else {
      lVar3 = (long)iVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// qcom_carveout_heap_create @ 00107674 size=288
// signature: undefined qcom_carveout_heap_create(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_carveout_heap_create(long param_1)

{
  long lVar1;
  ulong *puVar2;
  ulong uVar3;
  ulong uVar4;
  undefined8 local_50;
  undefined **local_48;
  ulong *local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (undefined **)0x0;
  local_40 = (ulong *)0x0;
  local_50 = 0;
  if (*(char *)(param_1 + 0x29) == '\0') {
    _printk(&DAT_00109788);
    uVar3 = 0xffffffea;
  }
  else {
    puVar2 = (ulong *)kmalloc_trace(_of_property_read_string,0xdc0,0x78);
    if (puVar2 == (ulong *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      uVar3 = __carveout_heap_init(param_1,puVar2,0);
      uVar4 = uVar3 & 0xffffffff;
      if ((int)uVar3 == 0) {
        local_50 = *(undefined8 *)(param_1 + 8);
        *(undefined1 *)(puVar2 + 0xb) = 0;
        *(undefined1 *)(puVar2 + 0xe) = 1;
        local_48 = &carveout_heap_ops;
        local_40 = puVar2;
        uVar4 = dma_heap_add(&local_50);
        uVar3 = 0;
        *puVar2 = uVar4;
        if (uVar4 < 0xfffffffffffff001) goto LAB_00107750;
        down_write(puVar2 + 1);
        if (puVar2[9] != 0) {
          gen_pool_destroy();
        }
        up_write(puVar2 + 1);
      }
      kfree(puVar2);
      uVar3 = uVar4 & 0xffffffff;
    }
  }
LAB_00107750:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __carveout_heap_init @ 00107794 size=216
// signature: undefined __carveout_heap_init(void)
// callers: [qcom_carveout_heap_create, qcom_secure_carveout_heap_create]
//------------------------------------------------------------

undefined8 __carveout_heap_init(long param_1,long param_2,ulong param_3)

{
  ulong uVar1;
  size_t __n;
  void *__s;
  long lVar2;
  undefined8 uVar3;
  
  *(undefined8 *)(param_2 + 0x50) = *(undefined8 *)(param_1 + 0x20);
  uVar1 = *(ulong *)(param_1 + 0x10);
  __n = *(size_t *)(param_1 + 0x18);
  if ((param_3 & 1) == 0) {
    uVar3 = 0x6800000000070b;
    if (arm64_use_ng_mappings != '\0') {
      uVar3 = 0x68000000000f0b;
    }
    __s = (void *)ioremap_prot(uVar1 & 0xfffffffffffff000,__n,uVar3);
    if (__s != (void *)0x0) {
      memset(__s,0,__n);
      iounmap(__s);
      goto LAB_00107800;
    }
  }
  else {
LAB_00107800:
    lVar2 = gen_pool_create(0xc,0xffffffff);
    *(long *)(param_2 + 0x48) = lVar2;
    if (lVar2 != 0) {
      *(ulong *)(param_2 + 0x60) = uVar1;
      *(size_t *)(param_2 + 0x68) = __n;
      gen_pool_add_owner(lVar2,uVar1,0xffffffffffffffff,__n,0xffffffff,0);
      uVar3 = 0;
      goto LAB_0010783c;
    }
  }
  uVar3 = 0xfffffff4;
LAB_0010783c:
  __init_rwsem(param_2 + 8,"&carveout_heap->mem_sem",&__carveout_heap_init___key);
  return uVar3;
}



//------------------------------------------------------------
// qcom_secure_carveout_heap_freeze @ 00107870 size=112
// signature: undefined qcom_secure_carveout_heap_freeze(void)
// callers: [qcom_dma_heaps_freeze]
//------------------------------------------------------------

undefined8 qcom_secure_carveout_heap_freeze(void)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  undefined *puVar3;
  
  ppuVar2 = &secure_carveout_heaps;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &secure_carveout_heaps) {
      return 0;
    }
    puVar3 = ppuVar2[2];
  } while (puVar3 == (undefined *)0x0);
  uVar1 = dma_heap_get_name(ppuVar2[-0xf]);
  _printk(&DAT_00109d7e,"qcom_secure_carveout_heap_freeze",uVar1,puVar3);
  return 0xfffffff0;
}



//------------------------------------------------------------
// qcom_secure_carveout_heap_restore @ 001078e4 size=80
// signature: undefined qcom_secure_carveout_heap_restore(void)
// callers: [qcom_dma_heaps_freeze, qcom_dma_heaps_restore]
//------------------------------------------------------------

undefined8 qcom_secure_carveout_heap_restore(void)

{
  code *pcVar1;
  int iVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &secure_carveout_heaps;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &secure_carveout_heaps) {
      return 0;
    }
    iVar2 = hyp_assign_from_flags(ppuVar3[-3],ppuVar3[-2],*(undefined4 *)(ppuVar3 + -0x10));
  } while (iVar2 == 0);
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x107920);
  (*pcVar1)();
}



//------------------------------------------------------------
// qcom_secure_carveout_heap_create @ 00107938 size=500
// signature: undefined qcom_secure_carveout_heap_create(void)
// callers: [qcom_dma_heap_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_secure_carveout_heap_create(long param_1)

{
  undefined4 *puVar1;
  undefined *puVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 local_b0;
  undefined **local_a8;
  undefined4 *local_a0;
  long local_98 [11];
  
  lVar7 = sp_el0;
  local_98[10] = *(long *)(lVar7 + 0x638);
  local_a8 = (undefined **)0x0;
  local_a0 = (undefined4 *)0x0;
  local_b0 = 0;
  if (*(char *)(param_1 + 0x29) == '\0') {
    _printk(&DAT_00109beb);
    uVar9 = 0xffffffea;
  }
  else {
    puVar6 = (undefined4 *)kmalloc_trace(_of_get_next_available_child,0xdc0,0x98);
    if (puVar6 == (undefined4 *)0x0) {
      uVar9 = 0xfffffff4;
    }
    else {
      local_98[8] = 0;
      local_98[9] = 0;
      local_98[6] = 0;
      local_98[7] = 0;
      local_98[4] = 0;
      local_98[5] = 0;
      local_98[2] = 0;
      local_98[3] = 0;
      local_98[0] = 0;
      local_98[1] = 0;
      iVar4 = __of_parse_phandle_with_args
                        (*(undefined8 *)(*(long *)(param_1 + 0x20) + 0x2e8),"memory-region",0,0,0,
                         local_98);
      bVar3 = false;
      if ((iVar4 == 0) && (local_98[0] != 0)) {
        lVar7 = of_find_property(local_98[0],"qcom,unmapped",0);
        bVar3 = lVar7 != 0;
      }
      *(bool *)(puVar6 + 1) = bVar3;
      uVar8 = __carveout_heap_init(param_1,puVar6 + 2);
      uVar9 = uVar8 & 0xffffffff;
      if ((int)uVar8 == 0) {
        if ((*(char *)(puVar6 + 1) == '\0') &&
           (uVar5 = hyp_assign_from_flags
                              (*(undefined8 *)(param_1 + 0x10),*(undefined8 *)(param_1 + 0x18),
                               *(undefined4 *)(param_1 + 0x2c)), uVar5 != 0)) {
          uVar9 = (ulong)uVar5;
          _printk(&DAT_00109857,*(undefined4 *)(param_1 + 0x2c));
        }
        else {
          local_b0 = *(undefined8 *)(param_1 + 8);
          *puVar6 = *(undefined4 *)(param_1 + 0x2c);
          *(undefined1 *)(puVar6 + 0x18) = 1;
          *(undefined1 *)(puVar6 + 0x1e) = 1;
          local_a8 = &sc_heap_ops;
          local_a0 = puVar6;
          uVar9 = dma_heap_add(&local_b0);
          *(ulong *)(puVar6 + 2) = uVar9;
          puVar2 = secure_carveout_heaps;
          if (uVar9 < 0xfffffffffffff001) {
            puVar1 = puVar6 + 0x20;
            uVar8 = __list_add_valid(puVar1,&secure_carveout_heaps,secure_carveout_heaps);
            uVar9 = 0;
            if ((uVar8 & 1) != 0) {
              *(undefined4 **)(puVar2 + 8) = puVar1;
              *(undefined **)(puVar6 + 0x20) = puVar2;
              *(undefined ***)(puVar6 + 0x22) = &secure_carveout_heaps;
              secure_carveout_heaps = (undefined *)puVar1;
            }
            goto LAB_00107a90;
          }
        }
        down_write(puVar6 + 4);
        if (*(long *)(puVar6 + 0x14) != 0) {
          gen_pool_destroy();
        }
        up_write(puVar6 + 4);
      }
      kfree(puVar6);
    }
  }
LAB_00107a90:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// carveout_heap_allocate @ 00107b30 size=64
// signature: undefined carveout_heap_allocate(void)
// callers: []
//------------------------------------------------------------

void carveout_heap_allocate(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  uVar1 = dma_heap_get_drvdata();
  __carveout_heap_allocate(uVar1,param_2,param_3,carveout_heap_free);
  return;
}



//------------------------------------------------------------
// __carveout_heap_allocate @ 00107b70 size=552
// signature: undefined __carveout_heap_allocate(void)
// callers: [sc_heap_allocate, carveout_heap_allocate]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __carveout_heap_allocate
                (undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  ulong *puVar9;
  ulong uVar10;
  undefined *local_a0;
  undefined *puStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 *local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_70 = DAT_00109118;
  uStack_68 = DAT_00109120;
  local_60 = DAT_00109128;
  local_90 = DAT_001090f8;
  local_88 = DAT_00109100;
  local_80 = DAT_00109108;
  uStack_78 = DAT_00109110;
  local_a0 = PTR_s_qcom_dma_heaps_001090e8;
  puStack_98 = PTR___this_module_001090f0;
  puVar4 = (undefined8 *)kmalloc_trace(_of_get_next_available_child,0xdc0,0xb0);
  if (puVar4 == (undefined8 *)0x0) {
    uVar10 = 0xfffffffffffffff4;
    goto LAB_00107d48;
  }
  qcom_sg_buffer_init();
  puVar4[0x14] = param_4;
  uVar8 = *param_1;
  uVar2 = *(undefined1 *)(param_1 + 0xe);
  puVar4[9] = param_2;
  *puVar4 = uVar8;
  *(undefined1 *)(puVar4 + 0xe) = uVar2;
  iVar3 = sg_alloc_table(puVar4 + 10,1,0xcc0);
  if (iVar3 == 0) {
    puVar1 = param_1 + 1;
    down_read(puVar1);
    lVar5 = param_1[9];
    if ((lVar5 == 0) ||
       (uVar6 = gen_pool_alloc_algo_owner
                          (lVar5,param_2,*(undefined8 *)(lVar5 + 0x20),*(undefined8 *)(lVar5 + 0x28)
                           ,0), uVar6 == 0)) {
      iVar3 = -0xc;
LAB_00107d2c:
      up_read(puVar1);
    }
    else {
      up_read(puVar1);
      lVar5 = _memstart_addr;
      if (uVar6 != 0xffffffffffffffff) {
        puVar9 = (ulong *)puVar4[10];
        *(undefined4 *)(puVar9 + 1) = 0;
        *(int *)((long)puVar9 + 0xc) = (int)param_2;
        *puVar9 = ((uVar6 >> 6 & 0x3ffffffffffffc0) + (lVar5 >> 0xc) * -0x40 | *puVar9 & 3) -
                  0x200000000;
        uVar7 = carveout_setup_vmperm(param_1,puVar4);
        uVar10 = 0;
        puVar4[0xf] = uVar7;
        if (uVar7 < 0xfffffffffffff001) {
          local_a0 = (undefined *)dma_heap_get_name(*param_1);
          local_88 = puVar4[9];
          local_80 = CONCAT44(local_80._4_4_,param_3);
          local_70 = puVar4;
          uVar10 = mem_buf_dma_buf_export(&local_a0,&qcom_sg_buf_ops);
          if (uVar10 < 0xfffffffffffff001) {
            qcom_store_dma_buf_fops(*(undefined8 *)(uVar10 + 8));
            goto LAB_00107d48;
          }
          mem_buf_vmperm_free(puVar4[0xf]);
        }
        iVar3 = (int)uVar10;
        down_read(puVar1);
        if (param_1[9] != 0) {
          gen_pool_free_owner(param_1[9],uVar6,param_2,0);
        }
        goto LAB_00107d2c;
      }
      iVar3 = -0xc;
    }
    sg_free_table(puVar4 + 10);
  }
  kfree(puVar4);
  uVar10 = (ulong)iVar3;
LAB_00107d48:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// carveout_heap_free @ 00107d9c size=272
// signature: undefined carveout_heap_free(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void carveout_heap_free(undefined8 *param_1)

{
  ulong uVar1;
  long lVar2;
  void *__s;
  size_t __n;
  undefined8 uVar3;
  ulong uVar4;
  
  uVar1 = _memstart_addr;
  uVar4 = *(ulong *)param_1[10] & 0xfffffffffffffffc;
  lVar2 = dma_heap_get_drvdata(*param_1);
  __n = param_1[9];
  uVar3 = 0x6800000000070b;
  if (arm64_use_ng_mappings != '\0') {
    uVar3 = 0x68000000000f0b;
  }
  __s = (void *)ioremap_prot((uVar4 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) *
                             0x40,__n,uVar3);
  if (__s != (void *)0x0) {
    memset(__s,0,__n);
    iounmap(__s);
  }
  uVar3 = param_1[9];
  down_read(lVar2 + 8);
  if (*(long *)(lVar2 + 0x48) != 0) {
    gen_pool_free_owner(*(long *)(lVar2 + 0x48),
                        (uVar4 + (uVar1 >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40,uVar3,0);
  }
  up_read(lVar2 + 8);
  sg_free_table(param_1 + 10);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// sc_heap_allocate @ 00107eb0 size=120
// signature: undefined sc_heap_allocate(void)
// callers: []
//------------------------------------------------------------

void sc_heap_allocate(undefined8 param_1,long param_2,undefined8 param_3)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = dma_heap_get_drvdata();
  uVar5 = __carveout_heap_allocate(lVar4 + 8,param_2,param_3,sc_heap_free);
  if (uVar5 < 0xfffffffffffff001) {
    plVar1 = (long *)(lVar4 + 0x90);
    Hint_Prefetch(plVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar3) {
        *plVar1 = *plVar1 + param_2;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return;
}



//------------------------------------------------------------
// sc_heap_free @ 00107f34 size=320
// signature: undefined sc_heap_free(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sc_heap_free(undefined8 *param_1)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  undefined4 *puVar5;
  ulong uVar6;
  void *__s;
  long lVar7;
  size_t __n;
  undefined8 uVar8;
  ulong uVar9;
  
  uVar4 = _memstart_addr;
  uVar9 = *(ulong *)param_1[10] & 0xfffffffffffffffc;
  puVar5 = (undefined4 *)dma_heap_get_drvdata(*param_1);
  uVar6 = qcom_is_buffer_hlos_accessible(*puVar5);
  if ((uVar6 & 1) != 0) {
    __n = param_1[9];
    uVar8 = 0x6800000000070b;
    if (arm64_use_ng_mappings != '\0') {
      uVar8 = 0x68000000000f0b;
    }
    __s = (void *)ioremap_prot((uVar9 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) *
                               0x40,__n,uVar8);
    if (__s != (void *)0x0) {
      memset(__s,0,__n);
      iounmap(__s);
    }
  }
  uVar8 = param_1[9];
  down_read(puVar5 + 4);
  if (*(long *)(puVar5 + 0x14) != 0) {
    gen_pool_free_owner(*(long *)(puVar5 + 0x14),
                        (uVar9 + (uVar4 >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40,uVar8,0);
  }
  up_read(puVar5 + 4);
  sg_free_table(param_1 + 10);
  lVar7 = param_1[9];
  plVar1 = (long *)(puVar5 + 0x24);
  Hint_Prefetch(plVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
    if (bVar3) {
      *plVar1 = *plVar1 - lVar7;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// ubwcp_release @ 00108084 size=128
// signature: undefined ubwcp_release(void)
// callers: []
//------------------------------------------------------------

void ubwcp_release(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  if (*(char *)(*(long *)(param_1 + 0xa0) + 0xb0) != '\0') {
    if (*(int *)(DAT_001092f0 + -4) != 0x17719b07) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1080c8);
      (*pcVar1)();
    }
    iVar2 = (*DAT_001092f0)(param_1);
    if (iVar2 != 0) {
      _printk(&DAT_001099ee,"ubwcp_release",iVar2);
      return;
    }
  }
  qcom_sg_dmabuf_release(param_1);
  return;
}



//------------------------------------------------------------
// ubwcp_dma_buf_begin_cpu_access @ 00108108 size=148
// signature: undefined ubwcp_dma_buf_begin_cpu_access(void)
// callers: []
//------------------------------------------------------------

undefined4 ubwcp_dma_buf_begin_cpu_access(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xa0);
  lVar1 = lVar4 + 0xb8;
  down_read(lVar1);
  if (*(char *)(lVar4 + 0xf8) == '\0') {
    if (*(int *)(DAT_001092f8 + -4) != 0x3b167821) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108174);
      (*pcVar2)();
    }
    uVar3 = (*DAT_001092f8)(param_1,param_2);
  }
  else {
    uVar3 = qcom_sg_dma_buf_begin_cpu_access(param_1,param_2);
  }
  up_read(lVar1);
  return uVar3;
}



//------------------------------------------------------------
// ubwcp_dma_buf_begin_cpu_access_partial @ 001081a0 size=152
// signature: undefined ubwcp_dma_buf_begin_cpu_access_partial(void)
// callers: []
//------------------------------------------------------------

undefined4
ubwcp_dma_buf_begin_cpu_access_partial
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xa0);
  lVar1 = lVar3 + 0xb8;
  down_read(lVar1);
  if (*(char *)(lVar3 + 0xf8) == '\0') {
    _printk(&DAT_001097c7,"ubwcp_dma_buf_begin_cpu_access_partial");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = qcom_sg_dma_buf_begin_cpu_access_partial(param_1,param_2,param_3,param_4);
  }
  up_read(lVar1);
  return uVar2;
}



//------------------------------------------------------------
// ubwcp_dma_buf_end_cpu_access @ 0010823c size=148
// signature: undefined ubwcp_dma_buf_end_cpu_access(void)
// callers: []
//------------------------------------------------------------

undefined4 ubwcp_dma_buf_end_cpu_access(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xa0);
  lVar1 = lVar4 + 0xb8;
  down_read(lVar1);
  if (*(char *)(lVar4 + 0xf8) == '\0') {
    if (*(int *)(DAT_00109300 + -4) != 0x3b167821) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1082a8);
      (*pcVar2)();
    }
    uVar3 = (*DAT_00109300)(param_1,param_2);
  }
  else {
    uVar3 = qcom_sg_dma_buf_end_cpu_access(param_1,param_2);
  }
  up_read(lVar1);
  return uVar3;
}



//------------------------------------------------------------
// ubwcp_dma_buf_end_cpu_access_partial @ 001082d4 size=152
// signature: undefined ubwcp_dma_buf_end_cpu_access_partial(void)
// callers: []
//------------------------------------------------------------

undefined4
ubwcp_dma_buf_end_cpu_access_partial
          (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xa0);
  lVar1 = lVar3 + 0xb8;
  down_read(lVar1);
  if (*(char *)(lVar3 + 0xf8) == '\0') {
    _printk(&DAT_001097c7,"ubwcp_dma_buf_end_cpu_access_partial");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = qcom_sg_dma_buf_end_cpu_access_partial(param_1,param_2,param_3,param_4);
  }
  up_read(lVar1);
  return uVar2;
}



//------------------------------------------------------------
// ubwcp_mmap @ 00108370 size=312
// signature: undefined ubwcp_mmap(void)
// callers: []
//------------------------------------------------------------

int ubwcp_mmap(long param_1,long *param_2)

{
  int *piVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = *(long *)(param_1 + 0xa0);
  lVar2 = *param_2;
  lVar7 = param_2[1];
  lVar9 = param_2[0x10];
  down_read(lVar8 + 0xb8);
  if (*(char *)(lVar8 + 0xf8) == '\0') {
    lVar7 = lVar7 - lVar2;
    if (*(ulong *)(lVar8 + 0x108) < (ulong)(lVar7 + lVar9 * 0x1000)) {
      _printk(&DAT_001097ec);
      iVar5 = -0x16;
    }
    else {
      mem_buf_vmperm_pin(*(undefined8 *)(lVar8 + 0x78));
      uVar6 = mem_buf_vmperm_can_mmap(*(undefined8 *)(lVar8 + 0x78),param_2);
      if ((uVar6 & 1) == 0) {
        mem_buf_vmperm_unpin(*(undefined8 *)(lVar8 + 0x78));
        iVar5 = -1;
      }
      else {
        param_2[0x12] = lVar8;
        param_2[0xf] = (long)&qcom_sg_vm_ops;
        iVar5 = remap_pfn_range(param_2,lVar2,lVar9 * 0x1000 + (*(ulong *)(lVar8 + 0x100) >> 0xc),
                                lVar7,param_2[3]);
        if (iVar5 == 0) {
          piVar1 = (int *)(lVar8 + 0xfc);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = *piVar1 + 1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          iVar5 = 0;
        }
        else {
          mem_buf_vmperm_unpin(*(undefined8 *)(lVar8 + 0x78));
        }
      }
    }
  }
  else {
    iVar5 = qcom_sg_mmap(param_1,param_2);
  }
  up_read(lVar8 + 0xb8);
  return iVar5;
}



//------------------------------------------------------------
// ubwcp_vmap @ 001084b8 size=168
// signature: undefined ubwcp_vmap(void)
// callers: []
//------------------------------------------------------------

int ubwcp_vmap(long param_1,undefined8 param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xa0);
  down_read(lVar5 + 0xb8);
  if (*(char *)(lVar5 + 0xf8) == '\0') {
    _printk(&DAT_001097c7,"ubwcp_vmap");
    iVar4 = -0x16;
  }
  else {
    iVar4 = qcom_sg_vmap(param_1,param_2);
    if (iVar4 == 0) {
      piVar1 = (int *)(lVar5 + 0xfc);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      iVar4 = 0;
    }
  }
  up_read(lVar5 + 0xb8);
  return iVar4;
}



//------------------------------------------------------------
// ubwcp_vunmap @ 00108570 size=168
// signature: undefined ubwcp_vunmap(void)
// callers: []
//------------------------------------------------------------

void ubwcp_vunmap(long param_1,undefined8 param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xa0);
  down_read(lVar5 + 0xb8);
  if (*(char *)(lVar5 + 0xf8) == '\0') {
    _printk(&DAT_001097c7,"ubwcp_vunmap");
  }
  else {
    qcom_sg_vunmap(param_1,param_2);
  }
  if (*(int *)(lVar5 + 0xfc) < 1) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x108604);
    (*pcVar4)();
  }
  piVar1 = (int *)(lVar5 + 0xfc);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  up_read(lVar5 + 0xb8);
  return;
}



//------------------------------------------------------------
// msm_ubwcp_dma_buf_configure_mmap @ 0010862c size=212
// signature: undefined msm_ubwcp_dma_buf_configure_mmap(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_ubwcp_dma_buf_configure_mmap(long param_1,byte param_2,undefined8 param_3,undefined8 param_4)

{
  undefined1 *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x20) == 0x109690) {
    if ((((uint)param_4 | (uint)param_3) & 0xfff) == 0) {
      lVar3 = *(long *)(param_1 + 0xa0);
      down_write(lVar3 + 0xb8);
      if (*(int *)(lVar3 + 0xfc) == 0) {
        uVar2 = 0;
        *(undefined8 *)(lVar3 + 0x100) = param_3;
        *(undefined8 *)(lVar3 + 0x108) = param_4;
        *(byte *)(lVar3 + 0xf8) = param_2 & 1;
      }
      else {
        _printk(&DAT_00109e3c,"msm_ubwcp_dma_buf_configure_mmap");
        uVar2 = 0xffffffea;
      }
      up_write(lVar3 + 0xb8);
      return uVar2;
    }
    puVar1 = &DAT_0010a30f;
  }
  else {
    puVar1 = &DAT_001098a1;
  }
  _printk(puVar1,"msm_ubwcp_dma_buf_configure_mmap");
  return 0xffffffea;
}



//------------------------------------------------------------
// qcom_ubwcp_heap_create @ 00108704 size=380
// signature: undefined qcom_ubwcp_heap_create(void)
// callers: [msm_ubwcp_set_ops]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_ubwcp_heap_create(undefined8 param_1,byte param_2)

{
  long lVar1;
  uint uVar2;
  byte *pbVar3;
  ulong uVar4;
  undefined8 local_50;
  undefined **local_48;
  byte *local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = (undefined **)0x0;
  local_40 = (byte *)0x0;
  local_50 = 0;
  if ((qcom_ubwcp_heap_create_vmap_registered & 1) == 0) {
    uVar2 = tracepoint_probe_register
                      (&__tracepoint_android_vh_ignore_dmabuf_vmap_bounds,ignore_vmap_bounds_check,0
                      );
    if (uVar2 == 0) {
      qcom_ubwcp_heap_create_vmap_registered = 1;
      goto LAB_00108768;
    }
    uVar4 = (ulong)uVar2;
    _printk(&DAT_00109f0c,"qcom_ubwcp_heap_create");
  }
  else {
LAB_00108768:
    sys_heap = dma_heap_find("qcom,system");
    if (sys_heap == 0) {
      _printk(&DAT_00109a6a,"qcom_ubwcp_heap_create");
      uVar4 = 0xffffffea;
    }
    else {
      pbVar3 = (byte *)kmalloc_trace(_of_dma_configure_id,0xdc0,1);
      if (pbVar3 == (byte *)0x0) {
        uVar4 = 0xfffffff4;
      }
      else {
        *pbVar3 = param_2 & 1;
        local_48 = &ubwcp_heap_ops;
        local_50 = param_1;
        local_40 = pbVar3;
        uVar4 = dma_heap_add(&local_50);
        if (uVar4 < 0xfffffffffffff001) {
          _printk(&DAT_00109766,"qcom_ubwcp_heap_create",param_1);
          uVar4 = 0;
          goto LAB_0010882c;
        }
      }
      kfree(pbVar3);
    }
  }
  _printk(&DAT_0010980e,"qcom_ubwcp_heap_create",param_1,uVar4 & 0xffffffff);
LAB_0010882c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// ignore_vmap_bounds_check @ 00108884 size=48
// signature: undefined ignore_vmap_bounds_check(void)
// callers: []
//------------------------------------------------------------

void ignore_vmap_bounds_check(undefined8 param_1,long param_2,byte *param_3)

{
  if (*(long *)(param_2 + 0x20) == 0x109690) {
    *param_3 = *(byte *)(*(long *)(param_2 + 0xa0) + 0xf8) ^ 1;
    return;
  }
  *param_3 = 0;
  return;
}



//------------------------------------------------------------
// msm_ubwcp_set_ops @ 001088b8 size=100
// signature: undefined msm_ubwcp_set_ops(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_ubwcp_set_ops(long param_1,long param_2,long param_3,long param_4)

{
  undefined8 uVar1;
  
  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {
    _printk(&DAT_00109982,"msm_ubwcp_set_ops");
    uVar1 = 0xffffffea;
  }
  else {
    ubwcp_driver_ops = param_1;
    DAT_001092f0 = param_2;
    DAT_001092f8 = param_3;
    DAT_00109300 = param_4;
    uVar1 = qcom_ubwcp_heap_create("qcom,ubwcp",0);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_sg_vm_ops_open @ 00108920 size=68
// signature: undefined qcom_sg_vm_ops_open(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_vm_ops_open(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x90);
  piVar1 = (int *)(lVar4 + 0xfc);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  mem_buf_vmperm_pin(*(undefined8 *)(lVar4 + 0x78));
  return;
}



//------------------------------------------------------------
// qcom_sg_vm_ops_close @ 00108974 size=72
// signature: undefined qcom_sg_vm_ops_close(void)
// callers: []
//------------------------------------------------------------

void qcom_sg_vm_ops_close(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x90);
  piVar1 = (int *)(lVar4 + 0xfc);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  mem_buf_vmperm_unpin(*(undefined8 *)(lVar4 + 0x78));
  return;
}



//------------------------------------------------------------
// ubwcp_allocate @ 001089cc size=472
// signature: undefined ubwcp_allocate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong ubwcp_allocate(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined1 *puVar3;
  long lVar4;
  ulong uVar5;
  undefined *local_90;
  undefined *puStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  long local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_60 = DAT_00109200;
  uStack_58 = DAT_00109208;
  local_50 = DAT_00109210;
  local_80 = DAT_001091e0;
  local_78 = DAT_001091e8;
  local_70 = DAT_001091f0;
  uStack_68 = DAT_001091f8;
  local_90 = PTR_s_qcom_dma_heaps_001091d0;
  puStack_88 = PTR___this_module_001091d8;
  puVar3 = (undefined1 *)dma_heap_get_drvdata();
  lVar4 = kmalloc_trace(___of_parse_phandle_with_args,0xdc0,0x110);
  if (lVar4 == 0) {
    uVar5 = 0xfffffffffffffff4;
  }
  else {
    __init_rwsem(lVar4 + 0xb8,"&buffer->linear_mode_sem",&ubwcp_allocate___key);
    iVar2 = system_qcom_sg_buffer_alloc(sys_heap,lVar4,param_2,*puVar3);
    if (iVar2 == 0) {
      uVar5 = mem_buf_vmperm_alloc(lVar4 + 0x50,qcom_sg_release,lVar4 + 0xa8);
      *(ulong *)(lVar4 + 0x78) = uVar5;
      if (uVar5 < 0xfffffffffffff001) {
        *(undefined1 *)(lVar4 + 0xf8) = 1;
        local_90 = (undefined *)dma_heap_get_name(param_1);
        local_78 = *(undefined8 *)(lVar4 + 0x48);
        local_70 = CONCAT44(local_70._4_4_,param_3);
        local_60 = lVar4;
        uVar5 = mem_buf_dma_buf_export(&local_90,&ubwcp_ops);
        if (uVar5 < 0xfffffffffffff001) {
          qcom_store_dma_buf_fops(*(undefined8 *)(uVar5 + 8));
          if (*(int *)(ubwcp_driver_ops + -4) != 0x17719b07) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108b78);
            (*pcVar1)();
          }
          iVar2 = (*ubwcp_driver_ops)(uVar5);
          if (iVar2 == 0) {
            *(undefined1 *)(lVar4 + 0xb0) = 1;
          }
          else {
            dma_buf_put(uVar5);
            uVar5 = (ulong)iVar2;
          }
          goto LAB_00108b18;
        }
        mem_buf_vmperm_free(*(undefined8 *)(lVar4 + 0x78));
      }
      iVar2 = (int)uVar5;
      qcom_system_heap_free(lVar4);
    }
    else {
      kfree(lVar4);
    }
    uVar5 = (ulong)iVar2;
  }
LAB_00108b18:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// init_module @ 00108cb8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_dma_heap_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 0010d000 size=1
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
// _printk @ 0010d008 size=1
// signature: undefined _printk(void)
// callers: [dynamic_page_pool_create_pools, ubwcp_mmap, qcom_dma_heaps_freeze, qcom_secure_system_heap_freeze, get_vmperm_from_ion_flags, qcom_dma_heaps_restore, qcom_secure_carveout_heap_create, qcom_secure_system_heap_restore, dynamic_page_pool_do_shrink, hyp_unassign_sg_from_flags, ubwcp_dma_buf_end_cpu_access_partial, qcom_secure_carveout_heap_freeze, qcom_carveout_heap_create, qcom_ubwcp_heap_create, sgl_sync_range, ubwcp_dma_buf_begin_cpu_access_partial, ubwcp_vmap, ubwcp_vunmap, dynamic_page_pool_destroy, parse_heap_dt, __qcom_secure_system_heap_resize, msm_ubwcp_dma_buf_configure_mmap, ubwcp_release, msm_ubwcp_set_ops, hyp_assign_from_flags, secure_system_heap_prefetch_work, qcom_secure_system_heap_create, qcom_system_heap_create, qcom_dma_heap_probe, system_heap_allocate, hyp_assign_sg_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010d010 size=1
// signature: undefined kfree(void)
// callers: [dynamic_page_pool_create_pools, qcom_sg_attach, carveout_setup_vmperm, qcom_sg_detach, sc_heap_free, get_vmperm_from_ion_flags, qcom_secure_carveout_heap_create, hyp_unassign_sg_from_flags, cma_heap_free, qcom_carveout_heap_create, qcom_ubwcp_heap_create, system_heap_allocate, dynamic_page_pool_destroy, cma_heap_allocate, parse_heap_dt, free_pdata, __carveout_heap_allocate, system_heap_buf_free, __qcom_secure_system_heap_resize, hyp_assign_from_flags, secure_system_heap_prefetch_work, qcom_secure_system_heap_create, qcom_add_cma_heap, carveout_heap_free, qcom_system_heap_create, system_heap_free, system_heap_allocate, hyp_assign_sg_from_flags, dynamic_page_pool_release_pools, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010d020 size=1
// signature: undefined kmalloc_trace(void)
// callers: [dynamic_page_pool_create_pools, qcom_sg_attach, __carveout_heap_allocate, __qcom_secure_system_heap_resize, secure_system_heap_prefetch_work, qcom_secure_system_heap_create, qcom_add_cma_heap, qcom_secure_carveout_heap_create, dynamic_page_pool_create, qcom_system_heap_create, qcom_carveout_heap_create, qcom_ubwcp_heap_create, system_heap_allocate, system_heap_allocate, cma_heap_allocate, parse_heap_dt, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010d028 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010d030 size=1
// signature: undefined __kmalloc(void)
// callers: [hyp_assign_from_flags, get_vmperm_from_ion_flags, hyp_assign_sg_from_flags, parse_heap_dt, hyp_unassign_sg_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010d038 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_add_cma_heap, qcom_secure_carveout_heap_create, parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_device_create @ 0010d040 size=1
// signature: undefined of_platform_device_create(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_configure_id @ 0010d048 size=1
// signature: undefined of_dma_configure_id(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_configure_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010d050 size=1
// signature: undefined of_property_read_string(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010d058 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010d060 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_add_cma_heap, qcom_secure_carveout_heap_create, parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_lookup @ 0010d068 size=1
// signature: undefined of_reserved_mem_lookup(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 0010d070 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d078 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_sg_map_dma_buf, cma_heap_allocate, parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010d080 size=1
// signature: undefined __warn_printk(void)
// callers: [proxy_invalid_map, proxy_invalid_unmap, parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_release @ 0010d088 size=1
// signature: undefined of_reserved_mem_device_release(void)
// callers: [parse_heap_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010d090 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [carveout_setup_vmperm, qcom_sg_do_vmap, qcom_secure_carveout_heap_create, system_qcom_sg_buffer_alloc, dynamic_page_pool_do_shrink, free_secure_pages, hyp_unassign_sg_from_flags, qcom_carveout_heap_create, qcom_ubwcp_heap_create, system_heap_allocate, dynamic_page_pool_destroy, cma_heap_allocate, parse_heap_dt, __carveout_heap_allocate, system_heap_buf_free, __qcom_secure_system_heap_resize, hyp_assign_from_flags, secure_system_heap_prefetch_work, qcom_secure_system_heap_create, qcom_add_cma_heap, pages_sync_for_device, qcom_system_heap_create, system_heap_allocate, hyp_assign_sg_from_flags, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table @ 0010d098 size=1
// signature: undefined sg_alloc_table(void)
// callers: [qcom_sg_attach, __carveout_heap_allocate, system_heap_allocate, secure_system_heap_prefetch_work, system_qcom_sg_buffer_alloc, cma_heap_allocate, free_secure_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 0010d0a0 size=1
// signature: undefined sg_next(void)
// callers: [qcom_sg_attach, system_heap_buf_free, system_heap_free, sgl_sync_range, secure_system_heap_prefetch_work, hyp_assign_sg_from_flags, system_qcom_sg_buffer_alloc, page_list_merge, qcom_sg_mmap, free_secure_pages, hyp_unassign_sg_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010d0a8 size=1
// signature: undefined mutex_lock(void)
// callers: [dynamic_page_pool_create_pools, qcom_sg_attach, qcom_sg_detach, qcom_sg_dma_buf_end_cpu_access_partial, qcom_sg_map_dma_buf, dynamic_page_pool_shrink_high_and_low, dynamic_page_pool_shrink_count, dynamic_page_pool_shrink_scan, qcom_sg_dma_buf_end_cpu_access, dynamic_page_pool_create, qcom_sg_vunmap, qcom_sg_dma_buf_begin_cpu_access_partial, qcom_sg_vmap, qcom_sg_unmap_dma_buf, dynamic_page_pool_destroy, qcom_sg_dma_buf_begin_cpu_access]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010d0b0 size=1
// signature: undefined __list_add_valid(void)
// callers: [dynamic_page_pool_create_pools, qcom_sg_attach, __qcom_secure_system_heap_resize, dynamic_page_pool_add, system_heap_allocate, secure_system_heap_prefetch_work, qcom_secure_system_heap_create, qcom_secure_carveout_heap_create, system_qcom_sg_buffer_alloc, dynamic_page_pool_do_shrink, dynamic_page_pool_destroy, dynamic_page_pool_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010d0b8 size=1
// signature: undefined mutex_unlock(void)
// callers: [dynamic_page_pool_create_pools, qcom_sg_attach, qcom_sg_detach, qcom_sg_dma_buf_end_cpu_access_partial, qcom_sg_map_dma_buf, dynamic_page_pool_shrink_high_and_low, dynamic_page_pool_shrink_count, dynamic_page_pool_shrink_scan, qcom_sg_dma_buf_end_cpu_access, dynamic_page_pool_create, qcom_sg_vunmap, qcom_sg_dma_buf_begin_cpu_access_partial, qcom_sg_vmap, qcom_sg_unmap_dma_buf, dynamic_page_pool_destroy, qcom_sg_dma_buf_begin_cpu_access]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010d0c0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [__qcom_secure_system_heap_resize, qcom_sg_detach, secure_system_heap_prefetch_work, system_qcom_sg_buffer_alloc, dynamic_page_pool_remove, dynamic_page_pool_do_shrink, dynamic_page_pool_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 0010d0c8 size=1
// signature: undefined sg_free_table(void)
// callers: [__carveout_heap_allocate, system_heap_buf_free, system_heap_free, qcom_sg_detach, system_heap_allocate, sc_heap_free, secure_system_heap_prefetch_work, cma_heap_allocate, carveout_heap_free, free_secure_pages, cma_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_pin @ 0010d0d0 size=1
// signature: undefined mem_buf_vmperm_pin(void)
// callers: [ubwcp_mmap, qcom_sg_vm_ops_open, qcom_sg_vmap, qcom_sg_map_dma_buf, qcom_sg_vm_ops_open, qcom_sg_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_pin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_can_cmo @ 0010d0d8 size=1
// signature: undefined mem_buf_vmperm_can_cmo(void)
// callers: [qcom_sg_dma_buf_begin_cpu_access_partial, qcom_sg_dma_buf_end_cpu_access_partial, qcom_sg_map_dma_buf, qcom_sg_unmap_dma_buf, qcom_sg_dma_buf_begin_cpu_access, qcom_sg_dma_buf_end_cpu_access]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_can_cmo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_sgtable @ 0010d0e0 size=1
// signature: undefined dma_map_sgtable(void)
// callers: [system_heap_allocate, secure_system_heap_prefetch_work, qcom_sg_map_dma_buf, system_qcom_sg_buffer_alloc, cma_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_sgtable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_dma_map_sg_attrs @ 0010d0e8 size=1
// signature: undefined msm_dma_map_sg_attrs(void)
// callers: [qcom_sg_map_dma_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_dma_map_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_unpin @ 0010d0f0 size=1
// signature: undefined mem_buf_vmperm_unpin(void)
// callers: [qcom_sg_vm_ops_close, qcom_sg_vunmap, ubwcp_mmap, qcom_sg_vm_ops_close, qcom_sg_vmap, qcom_sg_map_dma_buf, qcom_sg_unmap_dma_buf, qcom_sg_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_unpin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_sg_attrs @ 0010d0f8 size=1
// signature: undefined dma_unmap_sg_attrs(void)
// callers: [system_heap_allocate, secure_system_heap_prefetch_work, system_qcom_sg_buffer_alloc, qcom_sg_unmap_dma_buf, cma_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_dma_unmap_sg_attrs @ 0010d100 size=1
// signature: undefined msm_dma_unmap_sg_attrs(void)
// callers: [qcom_sg_unmap_dma_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_dma_unmap_sg_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_sg_for_cpu @ 0010d108 size=1
// signature: undefined dma_sync_sg_for_cpu(void)
// callers: [qcom_sg_dma_buf_begin_cpu_access]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_sg_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_sg_for_device @ 0010d110 size=1
// signature: undefined dma_sync_sg_for_device(void)
// callers: [pages_sync_for_device, qcom_sg_dma_buf_end_cpu_access]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_sg_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010d118 size=1
// signature: undefined ___ratelimit(void)
// callers: [sgl_sync_range]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_cpu @ 0010d120 size=1
// signature: undefined dma_sync_single_for_cpu(void)
// callers: [sgl_sync_range]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_device @ 0010d128 size=1
// signature: undefined dma_sync_single_for_device(void)
// callers: [sgl_sync_range]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_can_mmap @ 0010d130 size=1
// signature: undefined mem_buf_vmperm_can_mmap(void)
// callers: [ubwcp_mmap, qcom_sg_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_can_mmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remap_pfn_range @ 0010d140 size=1
// signature: undefined remap_pfn_range(void)
// callers: [ubwcp_mmap, qcom_sg_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 0010d148 size=1
// signature: undefined vmalloc(void)
// callers: [qcom_sg_do_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_start @ 0010d158 size=1
// signature: undefined __sg_page_iter_start(void)
// callers: [system_heap_buf_free, qcom_sg_do_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sg_page_iter_next @ 0010d160 size=1
// signature: undefined __sg_page_iter_next(void)
// callers: [system_heap_buf_free, qcom_sg_do_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sg_page_iter_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmap @ 0010d168 size=1
// signature: undefined vmap(void)
// callers: [system_heap_buf_free, qcom_sg_do_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 0010d170 size=1
// signature: undefined vfree(void)
// callers: [qcom_sg_do_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_can_vmap @ 0010d178 size=1
// signature: undefined mem_buf_vmperm_can_vmap(void)
// callers: [qcom_sg_vmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_can_vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vunmap @ 0010d180 size=1
// signature: undefined vunmap(void)
// callers: [qcom_sg_vunmap, system_heap_buf_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010d188 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_sg_buffer_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_free @ 0010d190 size=1
// signature: undefined mem_buf_vmperm_free(void)
// callers: [qcom_sg_release, __carveout_heap_allocate, system_heap_allocate, system_heap_allocate, qcom_sg_dmabuf_release, cma_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_try_reclaim @ 0010d198 size=1
// signature: undefined mem_buf_vmperm_try_reclaim(void)
// callers: [qcom_sg_dmabuf_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_try_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_dma_buf_freed @ 0010d1a0 size=1
// signature: undefined msm_dma_buf_freed(void)
// callers: [qcom_sg_dmabuf_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_dma_buf_freed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010d1b0 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [qcom_sg_dmabuf_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0010d1d0 size=1
// signature: undefined _find_next_bit(void)
// callers: [dynamic_pool_zone_watermark_ok_safe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// deferred_free @ 0010d1d8 size=1
// signature: undefined deferred_free(void)
// callers: [qcom_system_heap_free, system_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void deferred_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_get_drvdata @ 0010d1e0 size=1
// signature: undefined dma_heap_get_drvdata(void)
// callers: [get_pool_size_bytes, system_heap_buf_free, __qcom_secure_system_heap_resize, get_pool_size_bytes, sc_heap_free, secure_system_heap_prefetch_work, carveout_heap_allocate, system_qcom_sg_buffer_alloc, carveout_heap_free, cma_heap_free, system_heap_free, system_heap_allocate, sc_heap_allocate, cma_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010d1e8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [system_heap_buf_free, sc_heap_free, __carveout_heap_init, cma_heap_allocate, carveout_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 0010d1f0 size=1
// signature: undefined __free_pages(void)
// callers: [system_heap_buf_free, system_heap_allocate, secure_system_heap_prefetch_work, system_qcom_sg_buffer_alloc, dynamic_page_pool_do_shrink, dynamic_page_pool_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __folio_put @ 0010d208 size=1
// signature: undefined __folio_put(void)
// callers: [system_heap_buf_free, system_qcom_sg_buffer_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __folio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010d210 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [__qcom_secure_system_heap_resize, dynamic_page_pool_add, system_heap_allocate, secure_system_heap_prefetch_work, qcom_sys_heap_alloc_largest_available, dynamic_page_pool_do_shrink, dynamic_page_pool_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010d218 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [__qcom_secure_system_heap_resize, dynamic_page_pool_add, system_heap_allocate, secure_system_heap_prefetch_work, qcom_sys_heap_alloc_largest_available, dynamic_page_pool_do_shrink, dynamic_page_pool_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 0010d220 size=1
// signature: undefined __alloc_pages(void)
// callers: [qcom_sys_heap_alloc_largest_available, system_heap_refill_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0010d228 size=1
// signature: undefined wake_up_process(void)
// callers: [qcom_system_heap_create, qcom_sys_heap_alloc_largest_available]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_get_dev @ 0010d240 size=1
// signature: undefined dma_heap_get_dev(void)
// callers: [qcom_system_heap_create, system_heap_allocate, secure_system_heap_prefetch_work, qcom_secure_system_heap_create, qcom_add_cma_heap, system_qcom_sg_buffer_alloc, cma_heap_allocate, cma_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_get_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0010d248 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [qcom_system_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_setattr @ 0010d250 size=1
// signature: undefined sched_setattr(void)
// callers: [qcom_system_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_setattr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_add @ 0010d258 size=1
// signature: undefined dma_heap_add(void)
// callers: [qcom_system_heap_create, qcom_carveout_heap_create, qcom_ubwcp_heap_create, qcom_secure_system_heap_create, qcom_add_cma_heap, qcom_secure_carveout_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 0010d260 size=1
// signature: undefined kthread_stop(void)
// callers: [qcom_system_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0010d268 size=1
// signature: undefined dma_set_mask(void)
// callers: [dma_coerce_mask_and_coherent, qcom_add_cma_heap, dma_coerce_mask_and_coherent, cma_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0010d270 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [dma_coerce_mask_and_coherent, qcom_add_cma_heap, dma_coerce_mask_and_coherent, cma_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc @ 0010d278 size=1
// signature: undefined mem_buf_vmperm_alloc(void)
// callers: [carveout_setup_vmperm, system_heap_allocate, cma_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_get_name @ 0010d280 size=1
// signature: undefined dma_heap_get_name(void)
// callers: [qcom_secure_carveout_heap_freeze, __carveout_heap_allocate, __qcom_secure_system_heap_resize, system_heap_allocate, system_heap_allocate, cma_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_get_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_export @ 0010d288 size=1
// signature: undefined mem_buf_dma_buf_export(void)
// callers: [__carveout_heap_allocate, system_heap_allocate, system_heap_allocate, cma_heap_allocate, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_export(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0010d298 size=1
// signature: undefined ktime_get(void)
// callers: [system_heap_refill_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010d2a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [system_heap_refill_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 0010d2a8 size=1
// signature: undefined kthread_should_stop(void)
// callers: [system_heap_refill_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0010d2b0 size=1
// signature: undefined schedule(void)
// callers: [system_heap_refill_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_node_page_state @ 0010d2b8 size=1
// signature: undefined mod_node_page_state(void)
// callers: [dynamic_page_pool_add, dynamic_page_pool_remove, dynamic_page_pool_do_shrink, dynamic_page_pool_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_node_page_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_shrinker @ 0010d2c0 size=1
// signature: undefined register_shrinker(void)
// callers: [dynamic_page_pool_init_shrinker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_shrinker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0010d2c8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [__qcom_secure_system_heap_resize]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0010d2d0 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [qcom_secure_system_heap_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight64 @ 0010d2d8 size=1
// signature: undefined __sw_hweight64(void)
// callers: [qcom_secure_system_heap_create, get_vmperm_from_ion_flags, hyp_assign_sg_from_flags, hyp_unassign_sg_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0010d2e8 size=1
// signature: undefined init_timer_key(void)
// callers: [qcom_secure_system_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010d2f0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [qcom_secure_system_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_heap_find @ 0010d2f8 size=1
// signature: undefined dma_heap_find(void)
// callers: [qcom_ubwcp_heap_create, system_heap_allocate, secure_system_heap_prefetch_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_heap_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_secure_get_vmid_perms @ 0010d300 size=1
// signature: undefined msm_secure_get_vmid_perms(void)
// callers: [system_heap_allocate, get_vmperm_from_ion_flags, hyp_assign_sg_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_secure_get_vmid_perms(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_vmperm_alloc_staticvm @ 0010d308 size=1
// signature: undefined mem_buf_vmperm_alloc_staticvm(void)
// callers: [carveout_setup_vmperm, system_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_vmperm_alloc_staticvm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hyp_assign_table @ 0010d310 size=1
// signature: undefined hyp_assign_table(void)
// callers: [hyp_assign_sg_from_flags, hyp_unassign_sg_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hyp_assign_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 0010d318 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [hyp_assign_from_flags]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 0010d320 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [cma_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_alloc @ 0010d328 size=1
// signature: undefined cma_alloc(void)
// callers: [cma_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 0010d338 size=1
// signature: undefined dma_free_attrs(void)
// callers: [cma_heap_allocate, cma_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_release @ 0010d340 size=1
// signature: undefined cma_release(void)
// callers: [cma_heap_allocate, cma_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 0010d348 size=1
// signature: undefined sg_init_table(void)
// callers: [pages_sync_for_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 0010d350 size=1
// signature: undefined down_write(void)
// callers: [msm_ubwcp_dma_buf_configure_mmap, qcom_carveout_heap_create, qcom_secure_carveout_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_destroy @ 0010d358 size=1
// signature: undefined gen_pool_destroy(void)
// callers: [qcom_carveout_heap_create, qcom_secure_carveout_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 0010d360 size=1
// signature: undefined up_write(void)
// callers: [msm_ubwcp_dma_buf_configure_mmap, qcom_carveout_heap_create, qcom_secure_carveout_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 0010d368 size=1
// signature: undefined ioremap_prot(void)
// callers: [sc_heap_free, __carveout_heap_init, carveout_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 0010d370 size=1
// signature: undefined iounmap(void)
// callers: [sc_heap_free, __carveout_heap_init, carveout_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_create @ 0010d378 size=1
// signature: undefined gen_pool_create(void)
// callers: [__carveout_heap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_add_owner @ 0010d380 size=1
// signature: undefined gen_pool_add_owner(void)
// callers: [__carveout_heap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_add_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 0010d388 size=1
// signature: undefined __init_rwsem(void)
// callers: [__carveout_heap_init, ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read @ 0010d390 size=1
// signature: undefined down_read(void)
// callers: [__carveout_heap_allocate, ubwcp_dma_buf_end_cpu_access, ubwcp_mmap, sc_heap_free, ubwcp_dma_buf_begin_cpu_access, ubwcp_dma_buf_begin_cpu_access_partial, ubwcp_vmap, ubwcp_vunmap, carveout_heap_free, ubwcp_dma_buf_end_cpu_access_partial]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_alloc_algo_owner @ 0010d398 size=1
// signature: undefined gen_pool_alloc_algo_owner(void)
// callers: [__carveout_heap_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_alloc_algo_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 0010d3a0 size=1
// signature: undefined up_read(void)
// callers: [__carveout_heap_allocate, ubwcp_dma_buf_end_cpu_access, ubwcp_mmap, sc_heap_free, ubwcp_dma_buf_begin_cpu_access, ubwcp_dma_buf_begin_cpu_access_partial, ubwcp_vmap, ubwcp_vunmap, carveout_heap_free, ubwcp_dma_buf_end_cpu_access_partial]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_free_owner @ 0010d3a8 size=1
// signature: undefined gen_pool_free_owner(void)
// callers: [__carveout_heap_allocate, sc_heap_free, carveout_heap_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_free_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 0010d3b8 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [qcom_ubwcp_heap_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 0010d3c0 size=1
// signature: undefined dma_buf_put(void)
// callers: [ubwcp_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



