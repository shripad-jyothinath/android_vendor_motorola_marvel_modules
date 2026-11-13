// Decompiled by Ghidra 12.2
// Program: qcom_iommu_util.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_iommu_group_parse_phandle @ 00101e54 size=152
// signature: undefined qcom_iommu_group_parse_phandle(void)
// callers: []
//------------------------------------------------------------

void qcom_iommu_group_parse_phandle(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_78 [11];
  
  lVar3 = sp_el0;
  local_78[10] = *(long *)(lVar3 + 0x638);
  lVar3 = 0;
  if (*(long *)(param_1 + 0x2e8) != 0) {
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[0] = 0;
    local_78[1] = 0;
    iVar2 = __of_parse_phandle_with_args
                      (*(long *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_78);
    if ((iVar2 != 0) || (lVar3 = local_78[0], local_78[0] == 0)) {
      lVar3 = *(long *)(param_1 + 0x2e8);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_iommu_generate_dma_regions @ 00101ef0 size=96
// signature: undefined qcom_iommu_generate_dma_regions(void)
// callers: []
//------------------------------------------------------------

void qcom_iommu_generate_dma_regions(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  code *local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = insert_range;
  uStack_20 = param_2;
  of_property_walk_each_entry(param_1,"qcom,iommu-dma-addr-pool",&local_28);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// insert_range @ 00101f54 size=264
// signature: undefined insert_range(void)
// callers: []
//------------------------------------------------------------

undefined8 insert_range(uint *param_1,int param_2,int param_3,long *param_4)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  uint *puVar7;
  int iVar8;
  long *plVar9;
  long *plVar10;
  
  uVar3 = 0;
  if (param_2 != 0) {
    puVar7 = param_1;
    iVar8 = param_2;
    do {
      iVar8 = iVar8 + -1;
      uVar2 = (*puVar7 & 0xff00ff00) >> 8 | (*puVar7 & 0xff00ff) << 8;
      uVar3 = (ulong)(uVar2 >> 0x10 | uVar2 << 0x10) | uVar3 << 0x20;
      puVar7 = puVar7 + 1;
    } while (iVar8 != 0);
  }
  uVar6 = 0;
  if (param_3 != 0) {
    puVar7 = param_1 + param_2;
    do {
      param_3 = param_3 + -1;
      uVar2 = (*puVar7 & 0xff00ff00) >> 8 | (*puVar7 & 0xff00ff) << 8;
      uVar6 = (ulong)(uVar2 >> 0x10 | uVar2 << 0x10) | uVar6 << 0x20;
      puVar7 = puVar7 + 1;
    } while (param_3 != 0);
  }
  plVar9 = param_4;
  do {
    plVar9 = (long *)*plVar9;
    if (plVar9 == param_4) {
      plVar9 = param_4;
      break;
    }
    uVar1 = plVar9[2];
    if (uVar1 <= (uVar3 + uVar6) - 1 && uVar3 <= (uVar1 + plVar9[3]) - 1) {
      return 0xffffffea;
    }
  } while (uVar1 <= uVar3);
  puVar4 = (undefined8 *)iommu_alloc_resv_region(uVar3,uVar6,0,2,0xcc0);
  if (puVar4 == (undefined8 *)0x0) {
    uVar5 = 0xfffffff4;
  }
  else {
    plVar10 = (long *)plVar9[1];
    uVar3 = __list_add_valid(puVar4,plVar10,plVar9);
    if ((uVar3 & 1) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
      plVar9[1] = (long)puVar4;
      *puVar4 = plVar9;
      puVar4[1] = plVar10;
      *plVar10 = (long)puVar4;
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// of_property_walk_each_entry @ 0010205c size=396
// signature: undefined of_property_walk_each_entry(void)
// callers: [qcom_iommu_get_fast_iova_range, qcom_iommu_generate_resv_regions, qcom_iommu_generate_dma_regions]
//------------------------------------------------------------

void of_property_walk_each_entry(long param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  ulong uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  int local_9c;
  long local_98 [11];
  
  lVar9 = sp_el0;
  local_98[10] = *(long *)(lVar9 + 0x638);
  local_9c = 0;
  if (*(long *)(param_1 + 0x2e8) != 0) {
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
    iVar5 = __of_parse_phandle_with_args
                      (*(long *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_98);
    if (((iVar5 == 0) && (lVar9 = local_98[0], local_98[0] != 0)) ||
       (lVar9 = *(long *)(param_1 + 0x2e8), lVar9 != 0)) {
      uVar7 = of_get_property(lVar9,param_2,&local_9c);
      if (uVar7 == 0) {
        uVar8 = 0xffffffed;
        goto LAB_001021b4;
      }
      local_9c = local_9c >> 2;
      iVar5 = of_n_addr_cells(lVar9);
      iVar6 = of_n_size_cells(lVar9);
      if ((iVar5 != 0) && (iVar6 != 0)) {
        iVar1 = iVar6 + iVar5;
        iVar3 = 0;
        if (iVar1 != 0) {
          iVar3 = local_9c / iVar1;
        }
        if (local_9c == iVar3 * iVar1) {
          uVar2 = uVar7 + (long)local_9c * 4;
          if (uVar7 < uVar2) {
            do {
              if (*(int *)((code *)*param_3 + -4) != -0x7b566999) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x102170);
                (*pcVar4)();
              }
              uVar8 = (*(code *)*param_3)(uVar7,iVar5,iVar6,param_3[1]);
              if ((int)uVar8 != 0) goto LAB_001021b4;
              uVar7 = uVar7 + (long)iVar1 * 4;
            } while (uVar7 < uVar2);
          }
          uVar8 = 0;
          goto LAB_001021b4;
        }
      }
      _dev_err(param_1,"%s Invalid length %d. Address cells %d. Size cells %d\n",param_2,
               (long)local_9c,iVar5,iVar6);
    }
  }
  uVar8 = 0xffffffea;
LAB_001021b4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// qcom_iommu_generate_resv_regions @ 001021ec size=556
// signature: undefined qcom_iommu_generate_resv_regions(void)
// callers: []
//------------------------------------------------------------

void qcom_iommu_generate_resv_regions(undefined8 param_1,long ***param_2)

{
  long lVar1;
  undefined8 ****ppppuVar2;
  int iVar3;
  long ****pppplVar4;
  ulong uVar5;
  undefined8 ****ppppuVar6;
  long ***ppplVar7;
  long ****pppplVar8;
  undefined8 ****ppppuVar9;
  long ****local_88;
  long ****local_80;
  undefined8 ****local_78;
  undefined8 ****ppppuStack_70;
  code *local_68;
  undefined8 ****ppppuStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_88 = (long ****)&local_88;
  local_68 = insert_range;
  local_80 = local_88;
  local_78 = &local_78;
  ppppuStack_70 = &local_78;
  ppppuStack_60 = &local_78;
  iVar3 = of_property_walk_each_entry(param_1,"qcom,iommu-dma-addr-pool",&local_68);
  if (iVar3 != 0) goto LAB_001023e0;
  if ((undefined8 *****)local_78 != &local_78) {
    ppppuVar2 = local_78;
    ppppuVar9 = (undefined8 ****)0x0;
    do {
      ppppuVar6 = ppppuVar2;
      if (ppppuVar9 != (undefined8 ****)0x0) {
        lVar1 = (long)ppppuVar6[2] - ((long)ppppuVar9[3] + (long)ppppuVar9[2]);
        if (lVar1 != 0) {
          pppplVar4 = (long ****)
                      iommu_alloc_resv_region
                                ((long)ppppuVar9[3] + (long)ppppuVar9[2],lVar1,0,2,0xcc0);
          pppplVar8 = local_80;
          if (pppplVar4 == (long ****)0x0) goto LAB_001023b0;
          uVar5 = __list_add_valid(pppplVar4,local_80,&local_88);
          if ((uVar5 & 1) != 0) {
            *pppplVar4 = (long ***)&local_88;
            pppplVar4[1] = (long ***)pppplVar8;
            local_80 = pppplVar4;
            *pppplVar8 = (long ***)pppplVar4;
          }
        }
      }
      ppppuVar2 = (undefined8 ****)*ppppuVar6;
      ppppuVar9 = ppppuVar6;
    } while ((undefined8 *****)*ppppuVar6 != &local_78);
    if (local_78[2] == (undefined8 ***)0x0) {
LAB_00102320:
      if ((ppppuVar6[3] < (undefined8 ***)~(ulong)ppppuVar6[2]) &&
         (lVar1 = (long)ppppuVar6[3] + (long)ppppuVar6[2], lVar1 != 0)) {
        pppplVar4 = (long ****)iommu_alloc_resv_region(lVar1,-lVar1,0,2,0xcc0);
        pppplVar8 = local_80;
        if (pppplVar4 == (long ****)0x0) goto LAB_001023b0;
        uVar5 = __list_add_valid(pppplVar4,local_80,&local_88);
        if ((uVar5 & 1) != 0) {
          *pppplVar4 = (long ***)&local_88;
          pppplVar4[1] = (long ***)pppplVar8;
          local_80 = pppplVar4;
          *pppplVar8 = (long ***)pppplVar4;
        }
      }
      iommu_put_resv_regions(param_1,&local_78);
      pppplVar8 = local_80;
      if ((long *****)local_88 != &local_88) {
        ppplVar7 = (long ***)*param_2;
        local_88[1] = param_2;
        *param_2 = (long **)local_88;
        *pppplVar8 = ppplVar7;
        ppplVar7[1] = (long **)pppplVar8;
      }
      goto LAB_001023e0;
    }
    pppplVar4 = (long ****)iommu_alloc_resv_region(0,local_78[2],0,2,0xcc0);
    pppplVar8 = local_88;
    if (pppplVar4 != (long ****)0x0) {
      uVar5 = __list_add_valid(pppplVar4,&local_88,local_88);
      if ((uVar5 & 1) != 0) {
        pppplVar8[1] = (long ***)pppplVar4;
        *pppplVar4 = (long ***)pppplVar8;
        pppplVar4[1] = (long ***)&local_88;
        local_88 = pppplVar4;
      }
      goto LAB_00102320;
    }
LAB_001023b0:
    pppplVar8 = local_88;
    while ((long *****)pppplVar8 != &local_88) {
      pppplVar8 = (long ****)*pppplVar8;
      kfree();
    }
  }
  iommu_put_resv_regions(param_1,&local_78);
LAB_001023e0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_iommu_get_resv_regions @ 0010241c size=72
// signature: undefined qcom_iommu_get_resv_regions(void)
// callers: [__fast_smmu_setup_dma_ops]
//------------------------------------------------------------

void qcom_iommu_get_resv_regions(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = *(long *)(*(long *)(param_1 + 0x80) + 0xa0);
  if ((lVar1 != 0) && (pcVar2 = *(code **)(lVar1 + 0x30), pcVar2 != (code *)0x0)) {
    if (*(int *)(pcVar2 + -4) != 0x344b2e81) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102454);
      (*pcVar2)();
    }
    (*pcVar2)();
  }
  return;
}



//------------------------------------------------------------
// qcom_iommu_get_fast_iova_range @ 00102468 size=268
// signature: undefined qcom_iommu_get_fast_iova_range(void)
// callers: []
//------------------------------------------------------------

void qcom_iommu_get_fast_iova_range(long param_1,ulong *param_2,ulong *param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  ulong uVar4;
  code *local_68;
  ulong *local_60;
  ulong local_58;
  ulong uStack_50;
  ulong local_48;
  ulong uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar2 = 0xffffffea;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = get_addr_range;
  if (((param_1 != 0) && (param_2 != (ulong *)0x0)) && (param_3 != (ulong *)0x0)) {
    local_60 = &local_48;
    uVar2 = of_property_walk_each_entry(param_1,"qcom,iommu-dma-addr-pool",&local_68);
    if ((int)uVar2 != 0) {
      if ((int)uVar2 != -0x13) goto LAB_00102544;
      local_48 = 0;
      uStack_40 = 0xffffffff;
    }
    local_60 = &local_58;
    uVar2 = of_property_walk_each_entry(param_1,"qcom,iommu-geometry",&local_68);
    if ((int)uVar2 == -0x13) {
      uVar3 = 0;
      uVar4 = 0xffffffff;
    }
    else {
      if ((int)uVar2 != 0) goto LAB_00102544;
      uVar3 = local_58;
      uVar4 = uStack_50;
    }
    uVar2 = 0;
    if (local_48 <= uVar3) {
      uVar3 = local_48;
    }
    if (uVar4 <= uStack_40) {
      uVar4 = uStack_40;
    }
    *param_2 = uVar3;
    *param_3 = uVar4;
  }
LAB_00102544:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// get_addr_range @ 00102578 size=180
// signature: undefined get_addr_range(void)
// callers: []
//------------------------------------------------------------

undefined8 get_addr_range(uint *param_1,int param_2,int param_3,ulong *param_4)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  uint *puVar9;
  
  uVar6 = 0;
  if (param_2 != 0) {
    puVar9 = param_1;
    iVar7 = param_2;
    do {
      iVar7 = iVar7 + -1;
      uVar4 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8;
      uVar6 = (ulong)(uVar4 >> 0x10 | uVar4 << 0x10) | uVar6 << 0x20;
      puVar9 = puVar9 + 1;
    } while (iVar7 != 0);
  }
  uVar8 = 0;
  if (param_3 != 0) {
    puVar9 = param_1 + param_2;
    do {
      param_3 = param_3 + -1;
      uVar4 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8;
      uVar8 = (ulong)(uVar4 >> 0x10 | uVar4 << 0x10) | uVar8 << 0x20;
      puVar9 = puVar9 + 1;
    } while (param_3 != 0);
  }
  if ((uVar6 >> 0x20 == 0) && (uVar8 = (uVar6 + uVar8) - 1, uVar8 >> 0x20 == 0)) {
    uVar3 = *param_4;
    uVar5 = 0;
    uVar2 = uVar3;
    if (uVar6 <= uVar3) {
      uVar2 = uVar6;
    }
    uVar1 = uVar3;
    if (uVar6 != 0) {
      uVar1 = uVar2;
    }
    if (uVar3 != 0) {
      uVar6 = uVar1;
    }
    uVar2 = param_4[1];
    if (param_4[1] <= uVar8) {
      uVar2 = uVar8;
    }
    *param_4 = uVar6;
    param_4[1] = uVar2;
  }
  else {
    _printk(&DAT_0010ad07);
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// qcom_iommu_iova_to_phys_hard @ 00102630 size=72
// signature: undefined qcom_iommu_iova_to_phys_hard(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_iova_to_phys_hard(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xe0);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x595355bf) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102660);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_sid_switch @ 0010267c size=104
// signature: undefined qcom_iommu_sid_switch(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_sid_switch(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  lVar1 = iommu_get_domain_for_dev();
  if ((lVar1 == 0) || (pcVar3 = *(code **)(*(long *)(lVar1 + 8) + -0xd8), pcVar3 == (code *)0x0)) {
    uVar2 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x1b4fcab0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1026c8);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(param_1,param_2);
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_iommu_get_fault_ids @ 001026e8 size=72
// signature: undefined qcom_iommu_get_fault_ids(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_get_fault_ids(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xd0);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x52da15) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102718);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_skip_tlb_management @ 00102734 size=100
// signature: undefined qcom_skip_tlb_management(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_skip_tlb_management(undefined8 param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  lVar1 = iommu_get_domain_for_dev();
  if ((lVar1 == 0) || (pcVar3 = *(code **)(*(long *)(lVar1 + 8) + -0x90), pcVar3 == (code *)0x0)) {
    uVar2 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar3 + -4) != 0x6415190f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102778);
      (*pcVar3)();
    }
    (*pcVar3)(lVar1,param_2 & 1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_iommu_get_msi_size @ 0010279c size=200
// signature: undefined qcom_iommu_get_msi_size(void)
// callers: [__fast_smmu_setup_dma_ops]
//------------------------------------------------------------

void qcom_iommu_get_msi_size(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  long local_78 [11];
  
  lVar2 = sp_el0;
  local_78[10] = *(long *)(lVar2 + 0x638);
  if (*(long *)(param_1 + 0x2e8) != 0) {
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[0] = 0;
    local_78[1] = 0;
    iVar1 = __of_parse_phandle_with_args
                      (*(long *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_78);
    if (((iVar1 == 0) && (lVar2 = local_78[0], local_78[0] != 0)) ||
       (lVar2 = *(long *)(param_1 + 0x2e8), lVar2 != 0)) {
      iVar1 = of_property_read_variable_u32_array(lVar2,"qcom,iommu-msi-size",param_2,1,0);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
      goto LAB_00102838;
    }
  }
  iVar1 = -0x16;
LAB_00102838:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



//------------------------------------------------------------
// qcom_iommu_get_context_bank_nr @ 00102868 size=72
// signature: undefined qcom_iommu_get_context_bank_nr(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_get_context_bank_nr(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -200);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x1964a315) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102898);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_get_asid_nr @ 001028b4 size=72
// signature: undefined qcom_iommu_get_asid_nr(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_get_asid_nr(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xc0);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x1964a315) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1028e4);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_set_secure_vmid @ 00102900 size=72
// signature: undefined qcom_iommu_set_secure_vmid(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_set_secure_vmid(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xb8);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x186459c5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102930);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_set_fault_model @ 0010294c size=84
// signature: undefined qcom_iommu_set_fault_model(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_set_fault_model(long param_1,uint param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  uVar1 = 0xffffffea;
  if ((param_2 < 0x10) &&
     (pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xb0), pcVar2 != (code *)0x0)) {
    if (*(int *)(pcVar2 + -4) != -0x33189eb4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x102990);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_set_fault_handler_irq @ 001029a4 size=76
// signature: undefined qcom_iommu_set_fault_handler_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_set_fault_handler_irq(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xa8);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x3085c9fe) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1029d4);
      (*pcVar2)();
    }
    (*pcVar2)();
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_enable_s1_translation @ 001029f4 size=72
// signature: undefined qcom_iommu_enable_s1_translation(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_iommu_enable_s1_translation(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0xa0);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x1964a315) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102a24);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_get_mappings_configuration @ 00102a40 size=72
// signature: undefined qcom_iommu_get_mappings_configuration(void)
// callers: [__fast_smmu_setup_dma_ops]
//------------------------------------------------------------

undefined8 qcom_iommu_get_mappings_configuration(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(param_1 + 8) + -0x98);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x1964a315) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102a70);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_alloc_io_pgtable_ops @ 00102a8c size=252
// signature: undefined qcom_alloc_io_pgtable_ops(void)
// callers: []
//------------------------------------------------------------

uint * qcom_alloc_io_pgtable_ops(uint param_1,undefined8 *param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  uint *puVar4;
  undefined **ppuVar5;
  undefined8 uVar6;
  
  if (param_1 < 10) {
    puVar4 = (uint *)alloc_io_pgtable_ops(param_1,param_2,param_3);
    return puVar4;
  }
  if (param_1 == 0xffffffff) {
    ppuVar5 = &io_pgtable_av8l_fast_init_fns;
  }
  else {
    if (param_1 != 0xfffffffe) {
      _printk(&DAT_0010acea,param_1);
      return (uint *)0x0;
    }
    ppuVar5 = &qcom_io_pgtable_arm_64_lpae_s1_init_fns;
  }
  if (*(int *)(*ppuVar5 + -4) != 0x5f58a54) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102b14);
    (*pcVar3)();
  }
  puVar4 = (uint *)(*(code *)*ppuVar5)(param_2,param_3);
  if (puVar4 == (uint *)0x0) {
    return (uint *)0x0;
  }
  *puVar4 = param_1;
  *(undefined8 *)(puVar4 + 2) = param_3;
  uVar1 = param_2[2];
  uVar6 = *param_2;
  *(undefined8 *)(puVar4 + 6) = param_2[1];
  *(undefined8 *)(puVar4 + 8) = uVar1;
  *(undefined8 *)(puVar4 + 4) = uVar6;
  uVar6 = param_2[6];
  uVar1 = param_2[3];
  uVar2 = param_2[4];
  *(undefined8 *)(puVar4 + 0xe) = param_2[5];
  *(undefined8 *)(puVar4 + 0x10) = uVar6;
  *(undefined8 *)(puVar4 + 10) = uVar1;
  *(undefined8 *)(puVar4 + 0xc) = uVar2;
  uVar6 = param_2[10];
  uVar1 = param_2[7];
  uVar2 = param_2[8];
  *(undefined8 *)(puVar4 + 0x16) = param_2[9];
  *(undefined8 *)(puVar4 + 0x18) = uVar6;
  *(undefined8 *)(puVar4 + 0x12) = uVar1;
  *(undefined8 *)(puVar4 + 0x14) = uVar2;
  return puVar4 + 0x1a;
}



//------------------------------------------------------------
// qcom_free_io_pgtable_ops @ 00102b8c size=204
// signature: undefined qcom_free_io_pgtable_ops(void)
// callers: []
//------------------------------------------------------------

void qcom_free_io_pgtable_ops(long param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  undefined **ppuVar4;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + -0x68);
    if (uVar1 < 10) {
      free_io_pgtable_ops();
    }
    else {
      if (uVar1 == 0xffffffff) {
        ppuVar4 = &io_pgtable_av8l_fast_init_fns;
        puVar3 = *(undefined8 **)(param_1 + -0x38);
      }
      else {
        if (uVar1 != 0xfffffffe) {
          _printk(&DAT_0010acea);
          return;
        }
        ppuVar4 = &qcom_io_pgtable_arm_64_lpae_s1_init_fns;
        puVar3 = *(undefined8 **)(param_1 + -0x38);
      }
      if ((puVar3 != (undefined8 *)0x0) && (pcVar2 = (code *)*puVar3, pcVar2 != (code *)0x0)) {
        if (*(int *)(pcVar2 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102c10);
          (*pcVar2)();
        }
        (*pcVar2)(*(undefined8 *)(param_1 + -0x60));
      }
      if (*(int *)(ppuVar4[1] + -4) != -0x24ba1eb1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102c34);
        (*pcVar2)();
      }
      (*(code *)ppuVar4[1])((uint *)(param_1 + -0x68));
    }
  }
  return;
}



//------------------------------------------------------------
// init_iovad_attr @ 00102c5c size=188
// signature: undefined init_iovad_attr(void)
// callers: []
//------------------------------------------------------------

void init_iovad_attr(undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  uVar4 = *(undefined8 *)(param_2 + 0x2e8);
  local_2c = 0;
  lVar3 = of_find_property(uVar4,"qcom,iova-best-fit",0);
  if (lVar3 != 0) {
    *(ulong *)(param_3 + 0x80) = *(ulong *)(param_3 + 0x80) | 0x10000;
  }
  iVar2 = of_property_read_variable_u32_array(uVar4,"qcom,iova-max-align-shift",&local_2c,1,0);
  if (-1 < iVar2) {
    if (0xff < local_2c) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102ce0);
      (*pcVar1)();
    }
    *(ulong *)(param_3 + 0x80) = *(ulong *)(param_3 + 0x80) | (ulong)local_2c;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __qcom_alloc_insert_iova @ 00102d1c size=560
// signature: undefined __qcom_alloc_insert_iova(void)
// callers: []
//------------------------------------------------------------

void __qcom_alloc_insert_iova
               (undefined8 param_1,long param_2,ulong param_3,ulong param_4,long *param_5,
               uint param_6,undefined4 *param_7)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  long *plVar7;
  undefined4 uVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long local_68;
  
  if (((uint)*(ulong *)(param_2 + 0x80) >> 0x10 & 1) == 0) {
    uVar8 = 0xffffffea;
  }
  else {
    if ((param_6 & 1) == 0) {
      uVar11 = 0xffffffffffffffff;
    }
    else {
      uVar11 = 0;
      if (param_3 - 1 != 0) {
        uVar11 = 0x40 - LZCOUNT(param_3 - 1);
      }
      uVar13 = *(ulong *)(param_2 + 0x80) & 0xff;
      uVar9 = uVar11;
      if ((uVar13 != 0) &&
         (uVar9 = (*(ulong *)(param_2 + 0x20) & 0xaaaaaaaaaaaaaaaa) >> 1 |
                  (*(ulong *)(param_2 + 0x20) & 0x5555555555555555) << 1,
         uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2,
         uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4,
         uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8,
         uVar9 = (uVar9 & 0xffff0000ffff0000) >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10,
         uVar9 = (uVar13 - LZCOUNT(uVar9 >> 0x20 | uVar9 << 0x20)) + 0xc, uVar11 <= uVar9)) {
        uVar9 = uVar11;
      }
      uVar11 = -1L << (uVar9 & 0x3f);
    }
    uVar2 = _raw_spin_lock_irqsave(param_2);
    lVar10 = param_2 + 0x40;
    lVar3 = rb_prev(lVar10);
    lVar12 = 0;
    if (lVar3 == 0) {
      uVar9 = 0xffffffffffffffff;
      uVar13 = 0xffffffffffffffff;
    }
    else {
      uVar13 = 0xffffffffffffffff;
      uVar9 = 0xffffffffffffffff;
      lVar5 = lVar10;
      do {
        lVar10 = lVar3;
        uVar6 = *(ulong *)(lVar5 + 0x20);
        if (uVar6 <= param_4) {
          param_4 = uVar6;
        }
        uVar4 = param_4 - param_3 & uVar11;
        uVar6 = uVar6 + ~*(ulong *)(lVar10 + 0x18);
        if ((param_3 <= param_4 && *(ulong *)(lVar10 + 0x18) < uVar4) && uVar6 < uVar9) {
          uVar9 = uVar6;
          lVar12 = lVar5;
          uVar13 = uVar4;
          if (uVar6 == param_3) {
            if (uVar4 != 0xffffffffffffffff) goto LAB_00102e3c;
            goto LAB_00102ee4;
          }
        }
        lVar3 = rb_prev(lVar10);
        lVar5 = lVar10;
      } while (lVar3 != 0);
    }
    uVar6 = *(ulong *)(lVar10 + 0x20);
    if (uVar6 <= param_4) {
      param_4 = uVar6;
    }
    uVar4 = param_4 - param_3 & uVar11;
    lVar5 = lVar10;
    if ((param_4 < param_3 || uVar4 < *(ulong *)(param_2 + 0x28)) ||
        uVar9 <= uVar6 - *(ulong *)(param_2 + 0x28)) {
      lVar5 = lVar12;
      uVar4 = uVar13;
    }
    if (uVar4 == 0xffffffffffffffff) {
LAB_00102ee4:
      uVar8 = 0xfffffff4;
    }
    else {
LAB_00102e3c:
      local_68 = lVar5;
      plVar7 = (long *)(param_2 + 8);
      if (lVar5 != 0) {
        plVar7 = &local_68;
      }
      param_5[3] = param_3 + uVar4 + -1;
      param_5[4] = uVar4;
      lVar10 = *plVar7;
      if (*plVar7 == 0) {
        lVar3 = 0;
      }
      else {
        do {
          while( true ) {
            lVar3 = lVar10;
            if (uVar4 < *(ulong *)(lVar3 + 0x20)) break;
            if (uVar4 <= *(ulong *)(lVar3 + 0x20)) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x800,0x102f14);
              (*pcVar1)();
            }
            plVar7 = (long *)(lVar3 + 8);
            lVar10 = *plVar7;
            if (*plVar7 == 0) goto LAB_00102ef8;
          }
          plVar7 = (long *)(lVar3 + 0x10);
          lVar10 = *plVar7;
        } while (*plVar7 != 0);
      }
LAB_00102ef8:
      *param_5 = lVar3;
      param_5[1] = 0;
      param_5[2] = 0;
      *plVar7 = (long)param_5;
      rb_insert_color(param_5);
      uVar8 = 0;
    }
    _raw_spin_unlock_irqrestore(param_2,uVar2);
  }
  *param_7 = uVar8;
  return;
}



//------------------------------------------------------------
// __qcom_limit_align_shift @ 00102f50 size=48
// signature: undefined __qcom_limit_align_shift(void)
// callers: []
//------------------------------------------------------------

void __qcom_limit_align_shift(undefined8 param_1,long param_2,undefined8 param_3,ulong *param_4)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = *param_4;
  uVar2 = uVar1;
  if (((ulong)*(byte *)(param_2 + 0x80) != 0) &&
     (uVar2 = (*(ulong *)(param_2 + 0x20) & 0xaaaaaaaaaaaaaaaa) >> 1 |
              (*(ulong *)(param_2 + 0x20) & 0x5555555555555555) << 1,
     uVar2 = (uVar2 & 0xcccccccccccccccc) >> 2 | (uVar2 & 0x3333333333333333) << 2,
     uVar2 = (uVar2 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f0f0f0f0f) << 4,
     uVar2 = (uVar2 & 0xff00ff00ff00ff00) >> 8 | (uVar2 & 0xff00ff00ff00ff) << 8,
     uVar2 = (uVar2 & 0xffff0000ffff0000) >> 0x10 | (uVar2 & 0xffff0000ffff) << 0x10,
     uVar2 = ((ulong)*(byte *)(param_2 + 0x80) - LZCOUNT(uVar2 >> 0x20 | uVar2 << 0x20)) + 0xc,
     uVar1 <= uVar2)) {
    uVar2 = uVar1;
  }
  *param_4 = uVar2;
  return;
}



//------------------------------------------------------------
// qcom_pci_find_host_bridge @ 00102f84 size=20
// signature: undefined qcom_pci_find_host_bridge(void)
// callers: [__fast_smmu_setup_dma_ops]
//------------------------------------------------------------

undefined8 qcom_pci_find_host_bridge(long param_1)

{
  long lVar1;
  
  do {
    lVar1 = param_1;
    param_1 = *(long *)(lVar1 + 0x10);
  } while (param_1 != 0);
  return *(undefined8 *)(lVar1 + 0x138);
}



//------------------------------------------------------------
// qcom_arch_sync_dma_for_device @ 00102f9c size=112
// signature: undefined qcom_arch_sync_dma_for_device(void)
// callers: [fast_smmu_map_page, fast_smmu_sync_single_for_device, fast_smmu_sync_sg_for_device]
//------------------------------------------------------------

void qcom_arch_sync_dma_for_device(ulong param_1,undefined8 param_2,undefined4 param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  
  puVar2 = *(ulong **)(qcom_dma_iommu_dev + 0x2b0);
  if (puVar2 != (ulong *)0x0) {
    uVar3 = puVar2[2];
    while (uVar3 != 0) {
      if (*puVar2 <= param_1 && param_1 - *puVar2 < uVar3) {
        param_1 = param_1 - puVar2[3];
        goto LAB_00102ff8;
      }
      puVar1 = puVar2 + 6;
      puVar2 = puVar2 + 4;
      uVar3 = *puVar1;
    }
    param_1 = 0xffffffffffffffff;
  }
LAB_00102ff8:
  dma_sync_single_for_device(qcom_dma_iommu_dev,param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// qcom_arch_sync_dma_for_cpu @ 00103010 size=112
// signature: undefined qcom_arch_sync_dma_for_cpu(void)
// callers: [fast_smmu_sync_sg_for_cpu, fast_smmu_unmap_page, fast_smmu_sync_single_for_cpu]
//------------------------------------------------------------

void qcom_arch_sync_dma_for_cpu(ulong param_1,undefined8 param_2,undefined4 param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  ulong uVar3;
  
  puVar2 = *(ulong **)(qcom_dma_iommu_dev + 0x2b0);
  if (puVar2 != (ulong *)0x0) {
    uVar3 = puVar2[2];
    while (uVar3 != 0) {
      if (*puVar2 <= param_1 && param_1 - *puVar2 < uVar3) {
        param_1 = param_1 - puVar2[3];
        goto LAB_0010306c;
      }
      puVar1 = puVar2 + 6;
      puVar2 = puVar2 + 4;
      uVar3 = *puVar1;
    }
    param_1 = 0xffffffffffffffff;
  }
LAB_0010306c:
  dma_sync_single_for_cpu(qcom_dma_iommu_dev,param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// qcom_arch_dma_prep_coherent @ 00103084 size=132
// signature: undefined qcom_arch_dma_prep_coherent(void)
// callers: [__fast_smmu_alloc_contiguous, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_arch_dma_prep_coherent(long param_1,undefined8 param_2)

{
  ulong *puVar1;
  ulong uVar2;
  ulong *puVar3;
  ulong uVar4;
  
  puVar3 = *(ulong **)(qcom_dma_iommu_dev + 0x2b0);
  uVar2 = (param_1 + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000;
  if (puVar3 != (ulong *)0x0) {
    uVar4 = puVar3[2];
    while (uVar4 != 0) {
      if (*puVar3 <= uVar2 && uVar2 - *puVar3 < uVar4) {
        uVar2 = uVar2 - puVar3[3];
        goto LAB_001030f4;
      }
      puVar1 = puVar3 + 6;
      puVar3 = puVar3 + 4;
      uVar4 = *puVar1;
    }
    uVar2 = 0xffffffffffffffff;
  }
LAB_001030f4:
  dma_sync_single_for_device(qcom_dma_iommu_dev,uVar2,param_2,1);
  return;
}



//------------------------------------------------------------
// qcom_dma_alloc_from_contiguous @ 0010310c size=64
// signature: undefined qcom_dma_alloc_from_contiguous(void)
// callers: [__fast_smmu_alloc_contiguous]
//------------------------------------------------------------

void qcom_dma_alloc_from_contiguous(long param_1,undefined8 param_2,uint param_3,uint param_4)

{
  long lVar1;
  
  if ((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x2d8), *(long *)(param_1 + 0x2d8) == 0)) {
    lVar1 = qcom_dma_contiguous_default_area;
  }
  if (7 < param_3) {
    param_3 = 8;
  }
  cma_alloc(lVar1,param_2,param_3,param_4 & 1);
  return;
}



//------------------------------------------------------------
// qcom_dma_release_from_contiguous @ 00103150 size=56
// signature: undefined qcom_dma_release_from_contiguous(void)
// callers: [__fast_smmu_alloc_contiguous]
//------------------------------------------------------------

uint qcom_dma_release_from_contiguous(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  long lVar2;
  
  if ((param_1 == 0) || (lVar2 = *(long *)(param_1 + 0x2d8), *(long *)(param_1 + 0x2d8) == 0)) {
    lVar2 = qcom_dma_contiguous_default_area;
  }
  uVar1 = cma_release(lVar2,param_2,(long)param_3);
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_dma_alloc_contiguous @ 0010318c size=156
// signature: undefined qcom_dma_alloc_contiguous(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dma_alloc_contiguous(long param_1,ulong param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  
  if ((param_3 >> 10 & 1) == 0) {
    uVar2 = 0;
  }
  else {
    if (*(long *)(param_1 + 0x2d8) == 0) {
      if (param_2 < 0x1001) {
        return 0;
      }
      if (qcom_dma_contiguous_default_area == 0) {
        return 0;
      }
      iVar3 = 0x40 - (int)LZCOUNT(param_2 - 1 >> 0xc);
      lVar1 = qcom_dma_contiguous_default_area;
    }
    else {
      iVar3 = 0;
      if (0xfff < param_2 - 1) {
        iVar3 = 0x40 - (int)LZCOUNT(param_2 - 1 >> 0xc);
      }
      lVar1 = *(long *)(param_1 + 0x2d8);
    }
    if (7 < iVar3) {
      iVar3 = 8;
    }
    uVar2 = cma_alloc(lVar1,param_2 >> 0xc,iVar3,param_3 >> 0xd & 1);
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_dma_free_contiguous @ 0010322c size=116
// signature: undefined qcom_dma_free_contiguous(void)
// callers: [fast_smmu_free]
//------------------------------------------------------------

void qcom_dma_free_contiguous(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  
  if ((param_1 == 0) || (lVar2 = *(long *)(param_1 + 0x2d8), *(long *)(param_1 + 0x2d8) == 0)) {
    lVar2 = qcom_dma_contiguous_default_area;
  }
  uVar3 = cma_release(lVar2,param_2,param_3 + 0xfffU >> 0xc);
  if ((uVar3 & 1) == 0) {
    iVar1 = 0;
    if (0xfff < param_3 - 1U) {
      iVar1 = 0x40 - (int)LZCOUNT(param_3 - 1U >> 0xc);
    }
    __free_pages(param_2,iVar1);
  }
  return;
}



//------------------------------------------------------------
// qcom_dma_common_find_pages @ 001032a4 size=144
// signature: undefined qcom_dma_common_find_pages(void)
// callers: [fast_smmu_free]
//------------------------------------------------------------

undefined8 qcom_dma_common_find_pages(ulong param_1)

{
  long lVar1;
  
  mutex_lock(&rbtree_lock);
  for (lVar1 = *(long *)root; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x10)) {
    while (*(ulong *)(lVar1 + 0x18) <= param_1) {
      if (param_1 <= *(ulong *)(lVar1 + 0x18)) {
        mutex_unlock(&rbtree_lock);
        return *(undefined8 *)(lVar1 + 0x20);
      }
      lVar1 = *(long *)(lVar1 + 8);
      if (lVar1 == 0) goto LAB_00103300;
    }
  }
LAB_00103300:
  mutex_unlock(&rbtree_lock);
  return 0;
}



//------------------------------------------------------------
// qcom_dma_common_pages_remap @ 00103338 size=276
// signature: undefined qcom_dma_common_pages_remap(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_dma_common_pages_remap(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  
  plVar3 = (long *)kmalloc_trace(_gen_pool_alloc_algo_owner,0xdc0,0x28);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = vmap(param_1,param_2 + 0xfffU >> 0xc,0x10,param_3);
    if (uVar4 == 0) {
      kfree(plVar3);
    }
    else {
      plVar3[3] = uVar4;
      plVar3[4] = param_1;
      mutex_lock(&rbtree_lock);
      lVar1 = *(long *)root;
      if (*(long *)root == 0) {
        lVar6 = 0;
        plVar5 = (long *)root;
      }
      else {
        do {
          while (lVar6 = lVar1, *(ulong *)(lVar6 + 0x18) <= uVar4) {
            if (uVar4 <= *(ulong *)(lVar6 + 0x18)) {
              mutex_unlock(&rbtree_lock);
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x800,0x103434);
              (*pcVar2)();
            }
            plVar5 = (long *)(lVar6 + 8);
            lVar1 = *plVar5;
            if (*plVar5 == 0) goto LAB_001033e8;
          }
          plVar5 = (long *)(lVar6 + 0x10);
          lVar1 = *plVar5;
        } while (*plVar5 != 0);
      }
LAB_001033e8:
      *plVar3 = lVar6;
      plVar3[1] = 0;
      plVar3[2] = 0;
      *plVar5 = (long)plVar3;
      rb_insert_color(plVar3,root);
      mutex_unlock(&rbtree_lock);
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// qcom_dma_common_contiguous_remap @ 00103450 size=240
// signature: undefined qcom_dma_common_contiguous_remap(void)
// callers: [__fast_smmu_alloc_contiguous]
//------------------------------------------------------------

undefined8 qcom_dma_common_contiguous_remap(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  ulong uVar9;
  
  uVar6 = param_2 + 0xfff;
  uVar9 = uVar6 >> 0xc;
  if (((uVar9 & 0xffffffff) >> 0x1f != 0) ||
     (lVar1 = __kmalloc((long)(uVar9 << 0x20) >> 0x1d,0xcc0), lVar1 == 0)) {
    return 0;
  }
  if (0 < (int)uVar9) {
    uVar3 = uVar6 >> 0xc & 0xffffffff;
    if (uVar3 < 2) {
      lVar5 = 0;
    }
    else {
      uVar6 = uVar6 >> 0xc & 1;
      plVar7 = (long *)(lVar1 + 8);
      lVar5 = uVar3 - uVar6;
      lVar8 = lVar5;
      lVar4 = param_1;
      do {
        lVar8 = lVar8 + -2;
        plVar7[-1] = lVar4;
        *plVar7 = lVar4 + 0x40;
        lVar4 = lVar4 + 0x80;
        plVar7 = plVar7 + 2;
      } while (lVar8 != 0);
      if (uVar6 == 0) goto LAB_00103504;
    }
    param_1 = param_1 + lVar5 * 0x40;
    lVar4 = uVar3 - lVar5;
    plVar7 = (long *)(lVar1 + lVar5 * 8);
    do {
      *plVar7 = param_1;
      param_1 = param_1 + 0x40;
      lVar4 = lVar4 + -1;
      plVar7 = plVar7 + 1;
    } while (lVar4 != 0);
  }
LAB_00103504:
  uVar2 = vmap(lVar1,uVar9 & 0xffffffff,0x10,param_3);
  kfree(lVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_dma_common_free_remap @ 00103544 size=192
// signature: undefined qcom_dma_common_free_remap(void)
// callers: [qcom_dma_atomic_pool_exit, fast_smmu_free, atomic_pool_expand]
//------------------------------------------------------------

void qcom_dma_common_free_remap(ulong param_1)

{
  long lVar1;
  
  mutex_lock(&rbtree_lock);
  for (lVar1 = *(long *)root; lVar1 != 0; lVar1 = *(long *)(lVar1 + 0x10)) {
    while (*(ulong *)(lVar1 + 0x18) <= param_1) {
      if (param_1 <= *(ulong *)(lVar1 + 0x18)) {
        mutex_unlock(&rbtree_lock);
        mutex_lock(&rbtree_lock);
        rb_erase(lVar1,root);
        mutex_unlock(&rbtree_lock);
        kfree(lVar1);
        goto LAB_001035e8;
      }
      lVar1 = *(long *)(lVar1 + 8);
      if (lVar1 == 0) goto LAB_001035a4;
    }
  }
LAB_001035a4:
  mutex_unlock(&rbtree_lock);
LAB_001035e8:
  vunmap(param_1);
  return;
}



//------------------------------------------------------------
// qcom_dma_alloc_from_pool @ 00103608 size=220
// signature: undefined qcom_dma_alloc_from_pool(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * qcom_dma_alloc_from_pool(undefined8 param_1,size_t param_2,long *param_3)

{
  code *pcVar1;
  void *__s;
  ulong uVar2;
  
  if (atomic_pool == 0) {
    __warn_printk("coherent pool not initialised!\n");
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1036cc);
    (*pcVar1)();
  }
  __s = (void *)gen_pool_alloc_algo_owner
                          (atomic_pool,param_2,*(undefined8 *)(atomic_pool + 0x20),
                           *(undefined8 *)(atomic_pool + 0x28),0);
  if (__s != (void *)0x0) {
    uVar2 = gen_pool_virt_to_phys(atomic_pool,__s);
    *param_3 = (uVar2 >> 6 & 0x3ffffffffffffc0) + (_memstart_addr >> 0xc) * -0x40 + -0x200000000;
    memset(__s,0,param_2);
  }
  uVar2 = gen_pool_avail(atomic_pool);
  if (uVar2 < atomic_pool_size) {
    queue_work_on(0x20,_system_wq,&atomic_pool_work);
  }
  return __s;
}



//------------------------------------------------------------
// qcom_dma_free_from_pool @ 001036e8 size=100
// signature: undefined qcom_dma_free_from_pool(void)
// callers: [fast_smmu_free, fast_smmu_alloc]
//------------------------------------------------------------

undefined8 qcom_dma_free_from_pool(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (atomic_pool != 0) {
    uVar1 = gen_pool_has_addr();
    if ((uVar1 & 1) == 0) {
      uVar2 = 0;
    }
    else {
      gen_pool_free_owner(atomic_pool,param_2,param_3,0);
      uVar2 = 1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_dma_mmap_from_dev_coherent @ 00103750 size=8
// signature: undefined qcom_dma_mmap_from_dev_coherent(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dma_mmap_from_dev_coherent(void)

{
  return 0;
}



//------------------------------------------------------------
// qcom_dma_pgprot @ 0010375c size=32
// signature: undefined qcom_dma_pgprot(void)
// callers: []
//------------------------------------------------------------

ulong qcom_dma_pgprot(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = param_2 & 0xffffffffffffffe3 | 0x60000000000008;
  if ((*(byte *)(param_1 + 0x34c) & 0x20) != 0) {
    uVar1 = param_2;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_dma_info_to_prot @ 00103780 size=76
// signature: undefined qcom_dma_info_to_prot(void)
// callers: [fast_smmu_map_page, fast_smmu_map_sg, __fast_smmu_alloc_contiguous, fast_smmu_dma_map_resource, fast_smmu_alloc]
//------------------------------------------------------------

uint qcom_dma_info_to_prot(int param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 4;
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
  }
  uVar1 = (uint)(param_3 >> 4) & 0x20 | uVar1;
  if (param_1 == 2) {
    uVar2 = uVar1 | 2;
  }
  else {
    if (param_1 == 1) {
      return uVar1 | 1;
    }
    uVar2 = 0;
    if (param_1 == 0) {
      return uVar1 | 3;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_iommu_dma_prepare_map_sg @ 001037d0 size=252
// signature: undefined qcom_iommu_dma_prepare_map_sg(void)
// callers: [fast_smmu_map_sg]
//------------------------------------------------------------

long qcom_iommu_dma_prepare_map_sg(long param_1,long param_2,long param_3,int param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  
  if ((*(long *)(param_1 + 0x2b8) == 0) ||
     (uVar7 = *(ulong *)(*(long *)(param_1 + 0x2b8) + 8), uVar7 == 0)) {
    uVar7 = 0xffffffffffffffff;
  }
  if (param_4 < 1) {
    lVar5 = 0;
  }
  else {
    lVar5 = 0;
    lVar6 = 0;
    do {
      lVar2 = param_3;
      uVar1 = *(int *)(param_2 + 0x20) - 1U & *(uint *)(lVar2 + 8);
      *(uint *)(lVar2 + 0x18) = *(uint *)(lVar2 + 0xc);
      *(ulong *)(lVar2 + 0x10) = (ulong)uVar1;
      *(uint *)(lVar2 + 8) = *(uint *)(lVar2 + 8) - uVar1;
      uVar4 = (uVar7 + 1) - lVar5 & uVar7;
      uVar3 = ((ulong)*(uint *)(lVar2 + 0xc) + *(long *)(param_2 + 0x20) + (ulong)uVar1) - 1 &
              -*(long *)(param_2 + 0x20);
      *(int *)(lVar2 + 0xc) = (int)uVar3;
      if ((uVar4 != 0) && (uVar4 < uVar3 - 1)) {
        lVar5 = uVar4 + lVar5;
        *(int *)(lVar6 + 0xc) = *(int *)(lVar6 + 0xc) + (int)uVar4;
      }
      lVar5 = lVar5 + uVar3;
      param_3 = sg_next(lVar2);
      param_4 = param_4 + -1;
      lVar6 = lVar2;
    } while (param_4 != 0);
  }
  return lVar5;
}



//------------------------------------------------------------
// qcom_iommu_dma_finalise_sg @ 001038d0 size=376
// signature: undefined qcom_iommu_dma_finalise_sg(void)
// callers: [fast_smmu_map_sg]
//------------------------------------------------------------

int qcom_iommu_dma_finalise_sg(long param_1,long param_2,int param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int *piVar5;
  ulong uVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  int iVar10;
  ulong uVar11;
  int local_64;
  
  piVar5 = *(int **)(param_1 + 0x2b8);
  if (piVar5 == (int *)0x0) {
    uVar6 = 0xffffffffffffffff;
  }
  else {
    uVar6 = *(ulong *)(piVar5 + 2);
    local_64 = *piVar5;
    if (uVar6 == 0) {
      uVar6 = 0xffffffffffffffff;
    }
    if (local_64 != 0) goto joined_r0x0010396c;
  }
  local_64 = 0x10000;
joined_r0x0010396c:
  if (param_3 < 1) {
    iVar7 = 0;
  }
  else {
    uVar1 = *(uint *)(param_2 + 0xc);
    uVar2 = *(uint *)(param_2 + 0x18);
    iVar7 = (int)*(ulong *)(param_2 + 0x10);
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + iVar7;
    *(uint *)(param_2 + 0xc) = uVar2;
    *(ulong *)(param_2 + 0x10) = param_4 + (*(ulong *)(param_2 + 0x10) & 0xffffffff);
    lVar4 = sg_next(param_2);
    param_3 = param_3 + -1;
    if (param_3 == 0) {
      iVar7 = 1;
    }
    else {
      uVar8 = (ulong)uVar1 + param_4;
      uVar9 = 0;
      if (uVar1 <= uVar2 + iVar7) {
        uVar9 = uVar2;
      }
      iVar7 = 1;
      do {
        uVar1 = *(uint *)(lVar4 + 0xc);
        uVar11 = *(ulong *)(lVar4 + 0x10);
        uVar2 = *(uint *)(lVar4 + 0x18);
        *(undefined4 *)(lVar4 + 0x18) = 0;
        iVar10 = (int)uVar11;
        *(undefined8 *)(lVar4 + 0x10) = 0xffffffffffffffff;
        *(int *)(lVar4 + 8) = *(int *)(lVar4 + 8) + iVar10;
        *(uint *)(lVar4 + 0xc) = uVar2;
        if ((((uVar9 == 0) || (iVar10 != 0)) || ((uVar8 & uVar6) == 0)) ||
           (local_64 - uVar9 < uVar2)) {
          param_2 = sg_next(param_2);
          iVar7 = iVar7 + 1;
          *(ulong *)(param_2 + 0x10) = (uVar11 & 0xffffffff) + uVar8;
          uVar3 = uVar2;
        }
        else {
          uVar3 = uVar2 + uVar9;
        }
        uVar8 = uVar8 + uVar1;
        uVar9 = 0;
        if (uVar1 <= uVar2 + iVar10) {
          uVar9 = uVar3;
        }
        *(uint *)(param_2 + 0x18) = uVar3;
        lVar4 = sg_next(lVar4);
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  return iVar7;
}



//------------------------------------------------------------
// qcom_iommu_dma_invalidate_sg @ 00103a4c size=112
// signature: undefined qcom_iommu_dma_invalidate_sg(void)
// callers: [fast_smmu_map_sg]
//------------------------------------------------------------

void qcom_iommu_dma_invalidate_sg(long param_1,int param_2)

{
  if (0 < param_2) {
    do {
      if (*(long *)(param_1 + 0x10) != -1) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + (int)*(long *)(param_1 + 0x10);
      }
      if (*(int *)(param_1 + 0x18) != 0) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0x18);
      }
      *(undefined8 *)(param_1 + 0x10) = 0xffffffffffffffff;
      *(undefined4 *)(param_1 + 0x18) = 0;
      param_1 = sg_next();
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return;
}



//------------------------------------------------------------
// qcom_iommu_dma_mmap @ 00103ac0 size=344
// signature: undefined qcom_iommu_dma_mmap(void)
// callers: [fast_smmu_mmap_attrs]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
qcom_iommu_dma_mmap(long param_1,long *param_2,ulong param_3,undefined8 param_4,long param_5)

{
  undefined8 uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  uVar4 = param_2[0x10];
  uVar3 = param_5 + 0xfffU >> 0xc;
  uVar2 = param_2[3] & 0xffffffffffffffe3U | 0x60000000000008;
  if ((*(byte *)(param_1 + 0x34c) & 0x20) != 0) {
    uVar2 = param_2[3];
  }
  param_2[3] = uVar2;
  if ((uVar4 < uVar3) && ((ulong)(param_2[1] - *param_2) >> 0xc <= uVar3 - uVar4)) {
    uVar2 = is_vmalloc_addr(param_3);
    if ((uVar2 & 1) == 0) {
      lVar5 = (long)((((long)(param_3 << 8) >> 8) + 0x8000000000U >> 6 & 0x3ffffffffffffc0) +
                    (_memstart_addr >> 0xc) * 0x40) >> 6;
    }
    else {
      mutex_lock(&rbtree_lock);
      for (lVar5 = *(long *)root; lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x10)) {
        while (*(ulong *)(lVar5 + 0x18) <= param_3) {
          if (param_3 <= *(ulong *)(lVar5 + 0x18)) {
            mutex_unlock(&rbtree_lock);
            if (*(long *)(lVar5 + 0x20) != 0) {
              uVar1 = vm_map_pages(param_2,*(long *)(lVar5 + 0x20),uVar3);
              return uVar1;
            }
            goto LAB_00103b90;
          }
          lVar5 = *(long *)(lVar5 + 8);
          if (lVar5 == 0) goto LAB_00103b84;
        }
      }
LAB_00103b84:
      mutex_unlock(&rbtree_lock);
LAB_00103b90:
      lVar5 = vmalloc_to_pfn(param_3);
    }
    uVar1 = remap_pfn_range(param_2,*param_2,lVar5 + uVar4,param_2[1] - *param_2,param_2[3]);
  }
  else {
    uVar1 = 0xfffffffa;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_iommu_dma_get_sgtable @ 00103c1c size=312
// signature: undefined qcom_iommu_dma_get_sgtable(void)
// callers: [fast_smmu_get_sgtable]
//------------------------------------------------------------

undefined8
qcom_iommu_dma_get_sgtable
          (undefined8 param_1,long *param_2,ulong param_3,undefined8 param_4,long param_5)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong *puVar4;
  long lVar5;
  
  uVar2 = is_vmalloc_addr(param_3);
  if ((uVar2 & 1) == 0) {
    uVar2 = (((long)(param_3 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 - 0x200000000;
  }
  else {
    mutex_lock(&rbtree_lock);
    for (lVar5 = *(long *)root; lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x10)) {
      while (*(ulong *)(lVar5 + 0x18) <= param_3) {
        if (param_3 <= *(ulong *)(lVar5 + 0x18)) {
          mutex_unlock(&rbtree_lock);
          if (*(long *)(lVar5 + 0x20) != 0) {
            uVar3 = sg_alloc_table_from_pages_segment
                              (param_2,*(long *)(lVar5 + 0x20),param_5 + 0xfffU >> 0xc,0,param_5,
                               0xffffffff,0xcc0);
            return uVar3;
          }
          goto LAB_00103c9c;
        }
        lVar5 = *(long *)(lVar5 + 8);
        if (lVar5 == 0) goto LAB_00103c90;
      }
    }
LAB_00103c90:
    mutex_unlock(&rbtree_lock);
LAB_00103c9c:
    uVar2 = vmalloc_to_page(param_3);
  }
  uVar3 = sg_alloc_table(param_2,1,0xcc0);
  if ((int)uVar3 == 0) {
    if ((uVar2 & 3) != 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103d54);
      (*pcVar1)();
    }
    puVar4 = (ulong *)*param_2;
    uVar3 = 0;
    *(undefined4 *)(puVar4 + 1) = 0;
    *(uint *)((long)puVar4 + 0xc) = (int)param_5 + 0xfffU & 0xfffff000;
    *puVar4 = *puVar4 & 3 | uVar2;
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_dma_iommu_is_ready @ 00103d58 size=12
// signature: undefined qcom_dma_iommu_is_ready(void)
// callers: []
//------------------------------------------------------------

undefined1 qcom_dma_iommu_is_ready(void)

{
  return probe_finished;
}



//------------------------------------------------------------
// qcom_dma_iommu_generic_driver_exit @ 00103d68 size=36
// signature: undefined qcom_dma_iommu_generic_driver_exit(void)
// callers: []
//------------------------------------------------------------

void qcom_dma_iommu_generic_driver_exit(void)

{
  platform_driver_unregister(&qcom_dma_iommu_driver);
  return;
}



//------------------------------------------------------------
// qcom_dma_iommu_probe @ 00103d90 size=544
// signature: undefined qcom_dma_iommu_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_dma_iommu_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  char *pcVar5;
  ulong uVar6;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar3 + 0x638);
  qcom_dma_iommu_dev = lVar1;
  if ((*(byte *)(param_1 + 0x35c) >> 5 & 1) == 0) {
    iVar2 = of_reserved_mem_device_init_by_idx(lVar1,*(undefined8 *)(param_1 + 0x2f8),0);
    if (iVar2 != 0) goto LAB_00103e94;
    qcom_dma_contiguous_default_area = *(long *)(param_1 + 0x2e8);
    if (qcom_dma_contiguous_default_area != 0) {
      atomic_pool_work = 0xfffffffe0;
      uVar6 = __totalram_pages >> 0xd;
      if (0x3ff < uVar6) {
        uVar6 = 0x400;
      }
      uVar6 = uVar6 * 0x1000;
      if (uVar6 < 0x20001) {
        uVar6 = 0x20000;
      }
      DAT_0010b650 = &DAT_0010b650;
      DAT_0010b658 = &DAT_0010b650;
      local_3c = 0xcc0;
      DAT_0010b660 = atomic_pool_work_fn;
      atomic_pool_size = uVar6;
      lVar3 = gen_pool_create(0xc,0xffffffff);
      if (lVar3 == 0) {
        iVar2 = -0xc;
        atomic_pool = 0;
      }
      else {
        gen_pool_set_algo(lVar3,&gen_pool_first_fit_order_align,0);
        iVar2 = atomic_pool_expand(lVar3,uVar6,0xcc0);
        if (iVar2 == 0) {
          uVar6 = gen_pool_size(lVar3);
          puVar4 = &DAT_0010af93;
        }
        else {
          gen_pool_destroy(lVar3);
          lVar3 = 0;
          puVar4 = &DAT_0010afea;
        }
        _printk(puVar4,uVar6 >> 10,&local_3c);
        atomic_pool = lVar3;
        if (lVar3 == 0) {
          iVar2 = -0xc;
        }
        else {
          uVar6 = debugfs_create_dir("qcom_dma_pools",0);
          if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
            debugfs_create_ulong("pool_size",0x100,uVar6,&current_pool_size);
          }
          iVar2 = dma_set_mask(lVar1,0xffffffffffffffff);
          if (iVar2 == 0) {
            dma_set_coherent_mask(lVar1,0xffffffffffffffff);
            probe_finished = 1;
          }
          else {
            qcom_dma_atomic_pool_exit(lVar1);
          }
        }
      }
      goto LAB_00103e94;
    }
    pcVar5 = "Unable to find cma area\n";
  }
  else {
    pcVar5 = "Cannot be dma-coherent\n";
  }
  _dev_err(lVar1,pcVar5);
  iVar2 = -0x16;
LAB_00103e94:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_dma_iommu_remove @ 00103fb4 size=36
// signature: undefined qcom_dma_iommu_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_dma_iommu_remove(long param_1)

{
  qcom_dma_atomic_pool_exit(param_1 + 0x10);
  return 0;
}



//------------------------------------------------------------
// qcom_dma_atomic_pool_exit @ 00103fd8 size=180
// signature: undefined qcom_dma_atomic_pool_exit(void)
// callers: [qcom_dma_iommu_remove, qcom_dma_iommu_probe]
//------------------------------------------------------------

void qcom_dma_atomic_pool_exit(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  
  lVar1 = atomic_pool_size;
  lVar3 = gen_pool_alloc_algo_owner
                    (atomic_pool,atomic_pool_size,*(undefined8 *)(atomic_pool + 0x20),
                     *(undefined8 *)(atomic_pool + 0x28),0);
  if (lVar3 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x104074);
    (*pcVar2)();
  }
  gen_pool_free_owner(atomic_pool,lVar3,atomic_pool_size,0);
  gen_pool_destroy(atomic_pool);
  uVar4 = vmalloc_to_page(lVar3);
  qcom_dma_common_free_remap(lVar3);
  if ((param_1 == 0) || (lVar3 = *(long *)(param_1 + 0x2d8), *(long *)(param_1 + 0x2d8) == 0)) {
    lVar3 = qcom_dma_contiguous_default_area;
  }
  cma_release(lVar3,uVar4,(lVar1 << 0x14) >> 0x20);
  return;
}



//------------------------------------------------------------
// atomic_pool_work_fn @ 00104090 size=92
// signature: undefined atomic_pool_work_fn(void)
// callers: []
//------------------------------------------------------------

void atomic_pool_work_fn(void)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  lVar1 = atomic_pool;
  if (atomic_pool != 0) {
    uVar2 = gen_pool_avail(atomic_pool);
    if (uVar2 < atomic_pool_size) {
      uVar3 = gen_pool_size(lVar1);
      atomic_pool_expand(lVar1,uVar3,0xcc0);
    }
  }
  return;
}



//------------------------------------------------------------
// atomic_pool_expand @ 001040ec size=692
// signature: undefined atomic_pool_expand(void)
// callers: [atomic_pool_work_fn, qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int atomic_pool_expand(undefined8 param_1,long param_2,undefined4 param_3)

{
  ulong *puVar1;
  undefined8 uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong *puVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  long *plVar15;
  uint uVar16;
  long lVar17;
  
  uVar14 = 0x40 - (int)LZCOUNT(param_2 - 1U >> 0xc);
  if (9 < (int)uVar14) {
    uVar14 = 10;
  }
  uVar16 = 0;
  if (0xfff < param_2 - 1U) {
    uVar16 = uVar14;
  }
  while( true ) {
    if (qcom_dma_contiguous_default_area == 0) {
      uVar2 = tpidr_el1;
      lVar5 = __alloc_pages(uVar2,param_3,uVar16,0,0);
    }
    else {
      uVar14 = uVar16;
      if (7 < uVar16) {
        uVar14 = 8;
      }
      lVar5 = cma_alloc(qcom_dma_contiguous_default_area,(long)(1 << (ulong)(uVar16 & 0x1f)),uVar14,
                        0);
    }
    if (lVar5 != 0) break;
    uVar16 = uVar16 - 1;
    if (uVar16 == 0xffffffff) {
      return -0xc;
    }
  }
  lVar17 = (long)(1 << (ulong)(uVar16 + 0xc & 0x1f));
  puVar8 = *(ulong **)(qcom_dma_iommu_dev + 0x2b0);
  uVar7 = (lVar5 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40;
  if (puVar8 != (ulong *)0x0) {
    uVar11 = puVar8[2];
    while (uVar11 != 0) {
      if (*puVar8 <= uVar7 && uVar7 - *puVar8 < uVar11) {
        uVar7 = uVar7 - puVar8[3];
        goto LAB_0010421c;
      }
      puVar1 = puVar8 + 6;
      puVar8 = puVar8 + 4;
      uVar11 = *puVar1;
    }
    uVar7 = 0xffffffffffffffff;
  }
LAB_0010421c:
  dma_sync_single_for_device(qcom_dma_iommu_dev,uVar7,lVar17,1);
  uVar7 = lVar17 + 0xfff;
  uVar11 = uVar7 >> 0xc;
  uVar2 = 0x6800000000070b;
  if (arm64_use_ng_mappings != '\0') {
    uVar2 = 0x68000000000f0b;
  }
  if (((uVar11 & 0xffffffff) >> 0x1f == 0) &&
     (lVar6 = __kmalloc((long)(uVar11 << 0x20) >> 0x1d,0xcc0), lVar6 != 0)) {
    if (0 < (int)uVar11) {
      uVar9 = uVar7 >> 0xc & 0xffffffff;
      if (uVar9 < 2) {
        lVar12 = 0;
      }
      else {
        uVar7 = uVar7 >> 0xc & 1;
        plVar15 = (long *)(lVar6 + 8);
        lVar12 = uVar9 - uVar7;
        lVar13 = lVar12;
        lVar10 = lVar5;
        do {
          lVar13 = lVar13 + -2;
          plVar15[-1] = lVar10;
          *plVar15 = lVar10 + 0x40;
          lVar10 = lVar10 + 0x80;
          plVar15 = plVar15 + 2;
        } while (lVar13 != 0);
        if (uVar7 == 0) goto LAB_001042d0;
      }
      lVar10 = lVar12 - uVar9;
      lVar13 = lVar5 + lVar12 * 0x40;
      plVar15 = (long *)(lVar6 + lVar12 * 8);
      do {
        *plVar15 = lVar13;
        bVar3 = lVar10 != -1;
        lVar10 = lVar10 + 1;
        lVar13 = lVar13 + 0x40;
        plVar15 = plVar15 + 1;
      } while (bVar3);
    }
LAB_001042d0:
    lVar10 = vmap(lVar6,uVar11 & 0xffffffff,0x10,uVar2);
    kfree(lVar6);
    if (lVar10 != 0) {
      iVar4 = gen_pool_add_owner(param_1,lVar10,
                                 (lVar5 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) *
                                 0x40,lVar17,0xffffffff,0);
      if (iVar4 == 0) {
        current_pool_size = current_pool_size + lVar17;
        return 0;
      }
      qcom_dma_common_free_remap(lVar10);
      goto LAB_00104340;
    }
  }
  iVar4 = -0xc;
LAB_00104340:
  uVar7 = cma_release(qcom_dma_contiguous_default_area,lVar5,(long)(1 << (ulong)(uVar16 & 0x1f)));
  if ((uVar7 & 1) == 0) {
    __free_pages(lVar5,uVar16);
  }
  return iVar4;
}



//------------------------------------------------------------
// av8l_fast_map_public @ 001043a8 size=316
// signature: undefined av8l_fast_map_public(void)
// callers: [fast_smmu_map_page, __fast_smmu_alloc_contiguous, fast_smmu_alloc]
//------------------------------------------------------------

undefined8 av8l_fast_map_public(long param_1,ulong param_2,ulong param_3,ulong param_4,uint param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong *puVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  
  uVar5 = *(ulong *)(param_1 + 0x68);
  if (uVar5 <= param_2) {
    lVar7 = *(long *)(param_1 + 0x50);
    uVar9 = param_2 - (uVar5 & 0xffffffffffe00000) >> 0xc;
    uVar2 = lVar7 + uVar9 * 8;
    if (uVar2 < 0xfffffffffffff001) {
      if ((param_5 >> 4 & 1) == 0) {
        if ((param_5 >> 2 & 1) == 0) {
          uVar5 = 0x60000000000e03;
          if ((param_5 & 0x40) != 0) {
            uVar5 = 0x60000000000e0f;
          }
        }
        else {
          uVar5 = 0x60000000000e07;
        }
      }
      else {
        uVar5 = 0x60000000000e0b;
      }
      uVar6 = param_4 >> 0xc;
      uVar3 = 0xc0;
      if ((param_5 & 2) != 0) {
        uVar3 = 0x40;
      }
      if (0xfff < param_4) {
        uVar5 = uVar5 | uVar3;
        param_3 = param_3 & 0xfffffffff000;
        uVar3 = uVar6;
        if (uVar6 < 2) {
          uVar3 = 1;
        }
        if (uVar3 < 2) {
          uVar12 = 0;
          uVar11 = param_3;
        }
        else {
          uVar12 = uVar3 & 0xffffffffffffe;
          puVar8 = (ulong *)(lVar7 + uVar9 * 8 + 8);
          uVar11 = param_3 + uVar12 * 0x1000;
          uVar13 = uVar12;
          do {
            uVar1 = param_3 + 0x1000;
            uVar4 = uVar5 | param_3;
            param_3 = param_3 + 0x2000;
            uVar13 = uVar13 - 2;
            puVar8[-1] = uVar4;
            *puVar8 = uVar5 | uVar1;
            puVar8 = puVar8 + 2;
          } while (uVar13 != 0);
          if (uVar3 == uVar12) goto LAB_001044ac;
        }
        lVar10 = uVar3 - uVar12;
        puVar8 = (ulong *)(lVar7 + uVar12 * 8 + uVar9 * 8);
        do {
          uVar9 = uVar5 | uVar11;
          uVar11 = uVar11 + 0x1000;
          lVar10 = lVar10 + -1;
          *puVar8 = uVar9;
          puVar8 = puVar8 + 1;
        } while (lVar10 != 0);
      }
LAB_001044ac:
      av8l_clean_range(param_1 + -0x58,uVar2,uVar2 + uVar6 * 8);
      return 0;
    }
  }
  _printk(&DAT_0010b0de,param_2,uVar5);
  return 0xffffffea;
}



//------------------------------------------------------------
// av8l_fast_map @ 001044e8 size=316
// signature: undefined av8l_fast_map(void)
// callers: []
//------------------------------------------------------------

undefined8 av8l_fast_map(long param_1,ulong param_2,ulong param_3,ulong param_4,uint param_5)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  ulong *puVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  
  uVar5 = *(ulong *)(param_1 + 0x68);
  if (uVar5 <= param_2) {
    lVar7 = *(long *)(param_1 + 0x50);
    uVar9 = param_2 - (uVar5 & 0xffffffffffe00000) >> 0xc;
    uVar2 = lVar7 + uVar9 * 8;
    if (uVar2 < 0xfffffffffffff001) {
      if ((param_5 >> 4 & 1) == 0) {
        if ((param_5 >> 2 & 1) == 0) {
          uVar5 = 0x60000000000e03;
          if ((param_5 & 0x40) != 0) {
            uVar5 = 0x60000000000e0f;
          }
        }
        else {
          uVar5 = 0x60000000000e07;
        }
      }
      else {
        uVar5 = 0x60000000000e0b;
      }
      uVar6 = param_4 >> 0xc;
      uVar3 = 0xc0;
      if ((param_5 & 2) != 0) {
        uVar3 = 0x40;
      }
      if (0xfff < param_4) {
        uVar5 = uVar5 | uVar3;
        param_3 = param_3 & 0xfffffffff000;
        uVar3 = uVar6;
        if (uVar6 < 2) {
          uVar3 = 1;
        }
        if (uVar3 < 2) {
          uVar12 = 0;
          uVar11 = param_3;
        }
        else {
          uVar12 = uVar3 & 0xffffffffffffe;
          puVar8 = (ulong *)(lVar7 + uVar9 * 8 + 8);
          uVar11 = param_3 + uVar12 * 0x1000;
          uVar13 = uVar12;
          do {
            uVar1 = param_3 + 0x1000;
            uVar4 = uVar5 | param_3;
            param_3 = param_3 + 0x2000;
            uVar13 = uVar13 - 2;
            puVar8[-1] = uVar4;
            *puVar8 = uVar5 | uVar1;
            puVar8 = puVar8 + 2;
          } while (uVar13 != 0);
          if (uVar3 == uVar12) goto LAB_001045ec;
        }
        lVar10 = uVar3 - uVar12;
        puVar8 = (ulong *)(lVar7 + uVar12 * 8 + uVar9 * 8);
        do {
          uVar9 = uVar5 | uVar11;
          uVar11 = uVar11 + 0x1000;
          lVar10 = lVar10 + -1;
          *puVar8 = uVar9;
          puVar8 = puVar8 + 1;
        } while (lVar10 != 0);
      }
LAB_001045ec:
      av8l_clean_range(param_1 + -0x58,uVar2,uVar2 + uVar6 * 8);
      return 0;
    }
  }
  _printk(&DAT_0010b0de,param_2,uVar5);
  return 0xffffffea;
}



//------------------------------------------------------------
// av8l_fast_unmap_public @ 00104628 size=152
// signature: undefined av8l_fast_unmap_public(void)
// callers: [fast_smmu_unmap_sg, __fast_smmu_alloc_contiguous, fast_smmu_free, fast_smmu_unmap_page, fast_smmu_alloc]
//------------------------------------------------------------

ulong av8l_fast_unmap_public(long param_1,ulong param_2,ulong param_3)

{
  void *__s;
  ulong __n;
  
  if ((param_2 < *(ulong *)(param_1 + 0x68)) ||
     (__s = (void *)(*(long *)(param_1 + 0x50) +
                    (param_2 - (*(ulong *)(param_1 + 0x68) & 0xffffffffffe00000) >> 0xc) * 8),
     (void *)0xfffffffffffff000 < __s)) {
    _printk(&DAT_0010b0de);
    return 0;
  }
  __n = param_3 >> 9 & 0x7ffffffffffff8;
  memset(__s,0,__n);
  av8l_clean_range(param_1 + -0x58,__s,(long)__s + __n);
  return param_3;
}



//------------------------------------------------------------
// av8l_fast_map_sg_public @ 001046c4 size=476
// signature: undefined av8l_fast_map_sg_public(void)
// callers: [fast_smmu_map_sg]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
av8l_fast_map_sg_public
          (long param_1,ulong param_2,ulong *param_3,int param_4,uint param_5,long *param_6)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  ulong *puVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  ulong uVar15;
  
  if (param_4 != 0) {
    uVar15 = 0x60000000000e03;
    if ((param_5 & 0x40) != 0) {
      uVar15 = 0x60000000000e0f;
    }
    uVar1 = 0xc0;
    if ((param_5 & 2) != 0) {
      uVar1 = 0x40;
    }
    if ((param_5 & 4) != 0) {
      uVar15 = 0x60000000000e07;
    }
    if ((param_5 & 0x10) != 0) {
      uVar15 = 0x60000000000e0b;
    }
    iVar14 = 0;
    uVar15 = uVar15 | uVar1;
    do {
      if (param_2 < *(ulong *)(param_1 + 0x68)) {
LAB_00104868:
        _printk(&DAT_0010b0de,param_2);
      }
      else {
        lVar5 = *(long *)(param_1 + 0x50);
        uVar7 = param_2 - (*(ulong *)(param_1 + 0x68) & 0xffffffffffe00000) >> 0xc;
        uVar1 = lVar5 + uVar7 * 8;
        if (0xfffffffffffff000 < uVar1) goto LAB_00104868;
        uVar4 = (ulong)(*(uint *)((long)param_3 + 0xc) >> 0xc);
        if (0xfff < *(uint *)((long)param_3 + 0xc)) {
          uVar2 = uVar4;
          if (uVar4 < 2) {
            uVar2 = 1;
          }
          uVar11 = (ulong)(uint)param_3[1] +
                   ((*param_3 & 0x3fffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 +
                   0x8000000000 & 0xfffffffff000;
          if (uVar2 < 2) {
            uVar10 = 0;
            uVar9 = uVar11;
          }
          else {
            uVar10 = uVar2 & 0xffffe;
            puVar6 = (ulong *)(lVar5 + uVar7 * 8 + 8);
            uVar9 = uVar11 + uVar10 * 0x1000;
            uVar11 = uVar11 + 0x1000;
            uVar12 = uVar10;
            do {
              uVar13 = uVar11 - 0x1000;
              uVar3 = uVar15 | uVar11;
              uVar11 = uVar11 + 0x2000;
              uVar12 = uVar12 - 2;
              puVar6[-1] = uVar15 | uVar13;
              *puVar6 = uVar3;
              puVar6 = puVar6 + 2;
            } while (uVar12 != 0);
            if (uVar2 == uVar10) goto LAB_00104750;
          }
          lVar8 = uVar2 - uVar10;
          puVar6 = (ulong *)(lVar5 + uVar10 * 8 + uVar7 * 8);
          do {
            uVar7 = uVar15 | uVar9;
            uVar9 = uVar9 + 0x1000;
            lVar8 = lVar8 + -1;
            *puVar6 = uVar7;
            puVar6 = puVar6 + 1;
          } while (lVar8 != 0);
        }
LAB_00104750:
        av8l_clean_range(param_1 + -0x58,uVar1,uVar1 + uVar4 * 8);
      }
      iVar14 = iVar14 + 1;
      param_2 = param_2 + *(uint *)((long)param_3 + 0xc);
      *param_6 = *param_6 + (ulong)*(uint *)((long)param_3 + 0xc);
      param_3 = (ulong *)sg_next(param_3);
    } while (iVar14 != param_4);
  }
  return 0;
}



//------------------------------------------------------------
// av8l_fast_iova_to_phys_public @ 001048a4 size=140
// signature: undefined av8l_fast_iova_to_phys_public(void)
// callers: [fast_smmu_sync_single_for_device, fast_smmu_unmap_page, fast_smmu_sync_single_for_cpu]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong av8l_fast_iova_to_phys_public(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_2 >> 0x1b & 0xff8 | *(ulong *)(param_1 + 0x28));
  if ((~(uint)uVar1 & 3) == 0) {
    uVar1 = *(ulong *)((uVar1 & 0x7ffffff000 | param_2 >> 0x12 & 0xff8) - _memstart_addr |
                      0xffffff8000000000);
    if (((~(uint)uVar1 & 3) == 0) &&
       (uVar1 = *(ulong *)(((param_2 >> 9 & 0xff8) - _memstart_addr) + (uVar1 & 0x7ffffff000) |
                          0xffffff8000000000), (~(uint)uVar1 & 3) == 0)) {
      return uVar1 & 0xfffffffff000 | param_2 & 0xfff;
    }
  }
  return 0;
}



//------------------------------------------------------------
// av8l_fast_iova_to_phys @ 00104934 size=140
// signature: undefined av8l_fast_iova_to_phys(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong av8l_fast_iova_to_phys(long param_1,ulong param_2)

{
  ulong uVar1;
  
  uVar1 = *(ulong *)(param_2 >> 0x1b & 0xff8 | *(ulong *)(param_1 + 0x28));
  if ((~(uint)uVar1 & 3) == 0) {
    uVar1 = *(ulong *)((uVar1 & 0x7ffffff000 | param_2 >> 0x12 & 0xff8) - _memstart_addr |
                      0xffffff8000000000);
    if (((~(uint)uVar1 & 3) == 0) &&
       (uVar1 = *(ulong *)(((param_2 >> 9 & 0xff8) - _memstart_addr) + (uVar1 & 0x7ffffff000) |
                          0xffffff8000000000), (~(uint)uVar1 & 3) == 0)) {
      return uVar1 & 0xfffffffff000 | param_2 & 0xfff;
    }
  }
  return 0;
}



//------------------------------------------------------------
// av8l_fast_iova_coherent_public @ 001049c4 size=104
// signature: undefined av8l_fast_iova_coherent_public(void)
// callers: [fast_smmu_sync_single_for_device, fast_smmu_sync_sg_for_cpu, fast_smmu_sync_single_for_cpu, fast_smmu_sync_sg_for_device]
//------------------------------------------------------------

ulong av8l_fast_iova_coherent_public(long param_1,ulong param_2)

{
  ulong *puVar1;
  ulong uVar2;
  
  if ((param_2 < *(ulong *)(param_1 + 0x68)) ||
     (puVar1 = (ulong *)(*(long *)(param_1 + 0x50) +
                        (param_2 - (*(ulong *)(param_1 + 0x68) & 0xffffffffffe00000) >> 0xc) * 8),
     (ulong *)0xfffffffffffff000 < puVar1)) {
    _printk(&DAT_0010b0de);
  }
  else {
    uVar2 = *puVar1;
    if ((uVar2 & 0x1c) == 4) {
      return uVar2 >> 9 & 1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// av8l_fast_alloc_pgtable @ 00104a30 size=1340
// signature: undefined av8l_fast_alloc_pgtable(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long av8l_fast_alloc_pgtable(ulong *param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  ulong *puVar5;
  ulong uVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  int iVar18;
  
  lVar4 = kmalloc_trace(_memset,0xcc0,0xe0);
  if (lVar4 == 0) {
    return 0;
  }
  uVar16 = param_1[7];
  *(code **)(lVar4 + 0x68) = av8l_fast_map;
  *(code **)(lVar4 + 0x70) = av8l_fast_map_pages;
  *(code **)(lVar4 + 0x88) = av8l_fast_iova_to_phys;
  uVar2 = param_1[3];
  param_1[1] = 0x1000;
  *(code **)(lVar4 + 0x78) = av8l_fast_unmap;
  *(code **)(lVar4 + 0x80) = av8l_fast_unmap_pages;
  uVar9 = *param_1;
  uVar7 = (uint)uVar16 & 0xfffff81f;
  *(undefined4 *)(param_1 + 2) = 0x20;
  if ((char)uVar2 == '\0') {
    uVar8 = 0x40;
    if ((uVar9 & 0x40) != 0) {
      uVar8 = 0xc0;
    }
    uVar7 = uVar7 | uVar8;
  }
  else {
    uVar8 = (uint)uVar16 | 0x260;
    if ((uVar9 & 0x40000000) != 0) {
      uVar8 = uVar7 | 0x60;
    }
    uVar7 = uVar8 & 0xfffffa7f | 0x80;
    *(uint *)(param_1 + 7) = uVar7;
    if (((uint)uVar9 >> 6 & 1) != 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x104af8);
      (*pcVar3)();
    }
  }
  *(uint *)(param_1 + 7) = uVar7 & 0xffffffe7;
  switch(CONCAT44(*(int *)((long)param_1 + 0x14),*(int *)((long)param_1 + 0x14) + -0x20) >> 1 &
         0xffffffff) {
  case 0:
    uVar7 = uVar7 & 0xffffffe0;
    break;
  default:
    goto switchD_00104b40_caseD_1;
  case 2:
    uVar7 = uVar7 & 0xffffffe0 | 1;
    break;
  case 4:
    uVar7 = uVar7 & 0xffffffe0 | 2;
    break;
  case 5:
    uVar7 = uVar7 & 0xffffffe0 | 3;
    break;
  case 6:
    uVar7 = uVar7 & 0xffffffe0 | 4;
    break;
  case 8:
    uVar7 = uVar7 & 0xffffffe0 | 5;
  }
  uVar16 = param_1[0xe];
  uVar2 = param_1[0xf];
  *(uint *)(param_1 + 7) = uVar7 & 0xfffe07ff | 0x10000;
  param_1[8] = 0xfffffffff404ff44;
  puVar5 = (ulong *)kmalloc_large(0x4028,0x12000);
  if ((puVar5 != (ulong *)0x0) || (puVar5 = (ulong *)vmalloc(0x4028), puVar5 != (ulong *)0x0)) {
    uVar1 = tpidr_el1;
    uVar9 = __alloc_pages(uVar1,0xdc0,0,0,0);
    if (uVar9 != 0) {
      *puVar5 = uVar9;
      uVar9 = (uVar9 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
      *(ulong *)(lVar4 + 0x90) = uVar9;
      if (uVar16 < uVar2) {
        uVar10 = uVar16 >> 0x1e & 3;
        uVar13 = uVar2 - 1;
        lVar15 = 0;
        uVar9 = uVar16;
        do {
          lVar17 = lVar15;
          uVar1 = tpidr_el1;
          uVar6 = __alloc_pages(uVar1,0xdc0,0,0,0);
          if (uVar6 == 0) {
            uVar9 = (ulong)((int)lVar17 + 1);
            goto LAB_00104f18;
          }
          puVar5[lVar17 + 1] = uVar6;
          if ((ulong)(5 - (int)uVar10) - 1 == lVar17) goto LAB_00104f8c;
          uVar14 = uVar9 | 0x3fffffff;
          uVar11 = _memstart_addr >> 6;
          lVar15 = *(long *)(lVar4 + 0x90);
          uVar9 = (uVar9 & 0xffffffffc0000000) + 0x40000000;
          if (uVar13 <= uVar14) {
            uVar9 = uVar2;
          }
          *(ulong *)(lVar4 + uVar10 * 8 + 0x98 + lVar17 * 8) =
               (uVar6 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
          *(ulong *)(lVar15 + uVar10 * 8 + lVar17 * 8) =
               (uVar6 + (uVar11 & 0x3ffffffffffffc0) + 0x200000000) * 0x40 | 3;
          lVar15 = lVar17 + 1;
        } while (uVar9 < uVar2);
        av8l_clean_range(param_1,*(long *)(lVar4 + 0x90),*(long *)(lVar4 + 0x90) + 0x20);
        uVar9 = lVar17 + 2U;
        uVar6 = uVar16;
        do {
          lVar15 = uVar10 * 8;
          uVar11 = (uVar6 & 0xffffffffc0000000) + 0x40000000;
          if (uVar13 <= (uVar6 | 0x3fffffff)) {
            uVar11 = uVar2;
          }
          if (uVar6 < uVar11) {
            uVar7 = (uint)uVar6 >> 0x15 & 0x1ff;
            do {
              uVar1 = tpidr_el1;
              uVar14 = __alloc_pages(uVar1,0xdc0,0,0,0);
              if (uVar14 == 0) goto LAB_00104f18;
              iVar18 = (int)uVar9;
              if (((iVar18 == 0x805) ||
                  (0x4028 < (-(uVar9 >> 0x1f & 1) & 0xfffffff800000000 | (uVar9 & 0xffffffff) << 3))
                  ) || (0x4028 < (ulong)((long)iVar18 << 3))) goto LAB_00104f88;
              puVar5[iVar18] = uVar14;
              uVar9 = (uVar14 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
              av8l_clean_range(param_1,uVar9,uVar9 + 0x1000);
              if (3 < uVar10) goto LAB_00104f8c;
              if (lVar15 - 0x48U < 0xffffffffffffff20) goto LAB_00104f88;
              uVar9 = (ulong)(iVar18 + 1);
              uVar12 = uVar6 | 0x1fffff;
              *(ulong *)(*(long *)(lVar4 + lVar15 + 0x98) + (long)(int)uVar7 * 8) =
                   (uVar14 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40 | 3;
              uVar7 = uVar7 + 1;
              uVar6 = (uVar6 & 0xffffffffffe00000) + 0x200000;
              if (uVar13 <= uVar12) {
                uVar6 = uVar2;
              }
            } while (uVar6 < uVar11);
          }
          if (uVar10 == 4) {
LAB_00104f8c:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104f90);
            (*pcVar3)();
          }
          if (lVar15 - 0x48U < 0xffffffffffffff20) goto LAB_00104f88;
          lVar15 = *(long *)(lVar4 + uVar10 * 8 + 0x98);
          av8l_clean_range(param_1,lVar15,lVar15 + 0x1000);
          uVar10 = uVar10 + 1;
          uVar6 = uVar11;
        } while (uVar11 < uVar2);
        iVar18 = (int)(lVar17 + 2U);
      }
      else {
        av8l_clean_range(param_1,uVar9,uVar9 + 0x20);
        iVar18 = 1;
        uVar9 = 1;
      }
      uVar1 = 0x68000000000703;
      if (arm64_use_ng_mappings != '\0') {
        uVar1 = 0x68000000000f03;
      }
      lVar15 = vmap(puVar5 + iVar18,(int)uVar9 - iVar18,1,uVar1);
      *(long *)(lVar4 + 0xb8) = lVar15;
      if (lVar15 != 0) {
        *(ulong **)(lVar4 + 0xc0) = puVar5;
        lVar17 = _kimage_voffset;
        uVar13 = _memstart_addr;
        lVar15 = (*(long *)(lVar4 + 0x90) << 8) >> 8;
        uVar10 = lVar15 + 0x8000000000;
        *(ulong *)(lVar4 + 0xd0) = uVar16;
        *(ulong *)(lVar4 + 0xd8) = uVar2;
        uVar16 = uVar10 + uVar13;
        if (uVar10 >> 0x26 != 0) {
          uVar16 = lVar15 - lVar17;
        }
        *(int *)(lVar4 + 200) = (int)uVar9;
        param_1[6] = uVar16;
        return lVar4;
      }
LAB_00104f18:
      if (0 < (int)uVar9) {
        uVar16 = 0;
        do {
          if (uVar16 == 0x805) {
LAB_00104f88:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x104f8c);
            (*pcVar3)();
          }
          __free_pages(puVar5[uVar16],0);
          uVar16 = uVar16 + 1;
        } while ((uVar9 & 0xffffffff) != uVar16);
      }
    }
    kvfree(puVar5);
  }
switchD_00104b40_caseD_1:
  kfree(lVar4);
  return 0;
}



//------------------------------------------------------------
// av8l_fast_free_pgtable @ 00104f94 size=108
// signature: undefined av8l_fast_free_pgtable(void)
// callers: []
//------------------------------------------------------------

void av8l_fast_free_pgtable(long param_1)

{
  long lVar1;
  
  vunmap(*(undefined8 *)(param_1 + 0xb8));
  if (0 < *(int *)(param_1 + 200)) {
    lVar1 = 0;
    do {
      __free_pages(*(undefined8 *)(*(long *)(param_1 + 0xc0) + lVar1 * 8),0);
      lVar1 = lVar1 + 1;
    } while (lVar1 < *(int *)(param_1 + 200));
  }
  kvfree(*(undefined8 *)(param_1 + 0xc0));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// av8l_clean_range @ 00105000 size=388
// signature: undefined av8l_clean_range(void)
// callers: [av8l_fast_map, av8l_fast_map_pages, av8l_fast_unmap, av8l_fast_unmap_pages, av8l_fast_alloc_pgtable, av8l_fast_map_public, av8l_fast_unmap_public, av8l_fast_map_sg_public]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void av8l_clean_range(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  
  if (*(char *)(param_1 + 0x18) == '\0') {
    uVar6 = *(undefined8 *)(param_1 + 0x28);
    uVar2 = is_vmalloc_addr(param_2);
    uVar5 = param_2;
    if ((uVar2 & 1) == 0) {
      uVar5 = is_vmalloc_addr(param_2);
      if ((uVar5 & 1) == 0) {
        lVar1 = (long)(param_2 << 8) >> 8;
        uVar5 = lVar1 + 0x8000000000;
        lVar4 = _memstart_addr + uVar5;
        if (uVar5 >> 0x26 != 0) {
          lVar4 = lVar1 - _kimage_voffset;
        }
      }
      else {
        lVar4 = vmalloc_to_page(param_2);
        lVar4 = (param_2 & 0xfff) +
                (lVar4 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40;
      }
      dma_sync_single_for_device(uVar6,lVar4,param_3 - param_2,1);
    }
    else {
      while (uVar5 < param_3) {
        uVar5 = (param_2 & 0xfffffffffffff000) + 0x1000;
        uVar2 = param_3;
        if (uVar5 <= param_3) {
          uVar2 = uVar5;
        }
        uVar3 = is_vmalloc_addr(param_2);
        if ((uVar3 & 1) == 0) {
          lVar1 = (long)(param_2 << 8) >> 8;
          uVar3 = lVar1 + 0x8000000000;
          lVar4 = _memstart_addr + uVar3;
          if (uVar3 >> 0x26 != 0) {
            lVar4 = lVar1 - _kimage_voffset;
          }
        }
        else {
          lVar4 = vmalloc_to_page(param_2);
          lVar4 = (param_2 & 0xfff) +
                  (lVar4 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40;
        }
        dma_sync_single_for_device(uVar6,lVar4,uVar2 - param_2,1);
        param_2 = uVar2;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// av8l_fast_map_pages @ 00105188 size=336
// signature: undefined av8l_fast_map_pages(void)
// callers: []
//------------------------------------------------------------

undefined8
av8l_fast_map_pages(long param_1,ulong param_2,ulong param_3,long param_4,long param_5,uint param_6,
                   undefined8 param_7,ulong *param_8)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  ulong *puVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  
  uVar5 = *(ulong *)(param_1 + 0x68);
  if (uVar5 <= param_2) {
    lVar8 = *(long *)(param_1 + 0x50);
    uVar10 = param_2 - (uVar5 & 0xffffffffffe00000) >> 0xc;
    uVar2 = lVar8 + uVar10 * 8;
    if (uVar2 < 0xfffffffffffff001) {
      uVar5 = param_5 * param_4;
      if ((param_6 >> 4 & 1) == 0) {
        if ((param_6 >> 2 & 1) == 0) {
          uVar7 = 0x60000000000e03;
          if ((param_6 & 0x40) != 0) {
            uVar7 = 0x60000000000e0f;
          }
        }
        else {
          uVar7 = 0x60000000000e07;
        }
      }
      else {
        uVar7 = 0x60000000000e0b;
      }
      uVar6 = uVar5 >> 0xc;
      uVar3 = 0xc0;
      if ((param_6 & 2) != 0) {
        uVar3 = 0x40;
      }
      if (0xfff < uVar5) {
        uVar7 = uVar7 | uVar3;
        param_3 = param_3 & 0xfffffffff000;
        uVar3 = uVar6;
        if (uVar6 < 2) {
          uVar3 = 1;
        }
        if (uVar3 < 2) {
          uVar13 = 0;
          uVar12 = param_3;
        }
        else {
          uVar13 = uVar3 & 0xffffffffffffe;
          puVar9 = (ulong *)(lVar8 + uVar10 * 8 + 8);
          uVar12 = param_3 + uVar13 * 0x1000;
          uVar14 = uVar13;
          do {
            uVar1 = param_3 + 0x1000;
            uVar4 = uVar7 | param_3;
            param_3 = param_3 + 0x2000;
            uVar14 = uVar14 - 2;
            puVar9[-1] = uVar4;
            *puVar9 = uVar7 | uVar1;
            puVar9 = puVar9 + 2;
          } while (uVar14 != 0);
          if (uVar3 == uVar13) goto LAB_00105298;
        }
        lVar11 = uVar3 - uVar13;
        puVar9 = (ulong *)(lVar8 + uVar13 * 8 + uVar10 * 8);
        do {
          uVar10 = uVar7 | uVar12;
          uVar12 = uVar12 + 0x1000;
          lVar11 = lVar11 + -1;
          *puVar9 = uVar10;
          puVar9 = puVar9 + 1;
        } while (lVar11 != 0);
      }
LAB_00105298:
      av8l_clean_range(param_1 + -0x58,uVar2,uVar2 + uVar6 * 8);
      *param_8 = uVar5;
      return 0;
    }
  }
  _printk(&DAT_0010b0de,param_2,uVar5);
  return 0xffffffea;
}



//------------------------------------------------------------
// av8l_fast_unmap @ 001052dc size=200
// signature: undefined av8l_fast_unmap(void)
// callers: []
//------------------------------------------------------------

ulong av8l_fast_unmap(long param_1,ulong param_2,ulong param_3)

{
  void *__s;
  code *pcVar1;
  ulong __n;
  
  if ((param_2 < *(ulong *)(param_1 + 0x68)) ||
     (__s = (void *)(*(long *)(param_1 + 0x50) +
                    (param_2 - (*(ulong *)(param_1 + 0x68) & 0xffffffffffe00000) >> 0xc) * 8),
     (void *)0xfffffffffffff000 < __s)) {
    _printk(&DAT_0010b0de);
    return 0;
  }
  __n = param_3 >> 9 & 0x7ffffffffffff8;
  memset(__s,0,__n);
  av8l_clean_range(param_1 + -0x58,__s,(long)__s + __n);
  if (*(undefined8 **)(param_1 + -0x38) == (undefined8 *)0x0) {
    return param_3;
  }
  pcVar1 = (code *)**(undefined8 **)(param_1 + -0x38);
  if (pcVar1 == (code *)0x0) {
    return param_3;
  }
  if (*(int *)(pcVar1 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105374);
    (*pcVar1)();
  }
  (*pcVar1)(*(undefined8 *)(param_1 + -0x60));
  return param_3;
}



//------------------------------------------------------------
// av8l_fast_unmap_pages @ 001053a8 size=204
// signature: undefined av8l_fast_unmap_pages(void)
// callers: []
//------------------------------------------------------------

ulong av8l_fast_unmap_pages(long param_1,ulong param_2,long param_3,long param_4)

{
  void *__s;
  code *pcVar1;
  ulong uVar2;
  ulong __n;
  
  if ((param_2 < *(ulong *)(param_1 + 0x68)) ||
     (__s = (void *)(*(long *)(param_1 + 0x50) +
                    (param_2 - (*(ulong *)(param_1 + 0x68) & 0xffffffffffe00000) >> 0xc) * 8),
     (void *)0xfffffffffffff000 < __s)) {
    _printk(&DAT_0010b0de);
    uVar2 = 0;
  }
  else {
    uVar2 = param_4 * param_3;
    __n = uVar2 >> 9 & 0x7ffffffffffff8;
    memset(__s,0,__n);
    av8l_clean_range(param_1 + -0x58,__s,(long)__s + __n);
    if ((*(undefined8 **)(param_1 + -0x38) != (undefined8 *)0x0) &&
       (pcVar1 = (code *)**(undefined8 **)(param_1 + -0x38), pcVar1 != (code *)0x0)) {
      if (*(int *)(pcVar1 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105444);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(param_1 + -0x60));
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// fast_smmu_put_dma_cookie @ 00105484 size=220
// signature: undefined fast_smmu_put_dma_cookie(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_put_dma_cookie(ulong param_1)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  
  uVar1 = _raw_write_lock_irqsave(&mappings_lock);
  lVar3 = mappings;
  do {
    if (lVar3 == 0) {
LAB_001054b8:
      _raw_write_unlock_irqrestore(&mappings_lock,uVar1);
      return;
    }
    if (param_1 < *(ulong *)(lVar3 + -0x80)) {
      plVar2 = (long *)(lVar3 + 0x10);
    }
    else {
      if (param_1 <= *(ulong *)(lVar3 + -0x80)) {
        if (lVar3 + -0x88 != 0) {
          rb_erase(lVar3,&mappings);
          _raw_write_unlock_irqrestore(&mappings_lock,uVar1);
          if (*(long *)(lVar3 + -0x78) != 0) {
            put_iova_domain();
            kfree(*(undefined8 *)(lVar3 + -0x78));
          }
          if (*(long *)(lVar3 + -0x50) != 0) {
            kvfree();
          }
          if (*(long *)(lVar3 + -0x48) != 0) {
            kvfree();
          }
          kfree(lVar3 + -0x88);
          return;
        }
        goto LAB_001054b8;
      }
      plVar2 = (long *)(lVar3 + 8);
    }
    lVar3 = *plVar2;
  } while( true );
}



//------------------------------------------------------------
// fast_smmu_init_mapping @ 00105564 size=652
// signature: undefined fast_smmu_init_mapping(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fast_smmu_init_mapping(undefined8 param_1,ulong param_2,long param_3)

{
  ulong uVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  long lVar5;
  long *plVar6;
  char *pcVar7;
  ulong uVar8;
  long *plVar9;
  ulong uVar10;
  ulong uVar11;
  
  uVar3 = _raw_read_lock_irqsave(&mappings_lock);
  for (lVar5 = mappings; lVar5 != 0; lVar5 = *(long *)(lVar5 + 0x10)) {
    while (*(ulong *)(lVar5 + -0x80) <= param_2) {
      if (param_2 <= *(ulong *)(lVar5 + -0x80)) {
        _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
        if (lVar5 == 0x88) goto LAB_001055f4;
        pcVar7 = "Iova cookie already present\n";
        goto LAB_001057cc;
      }
      lVar5 = *(long *)(lVar5 + 8);
      if (lVar5 == 0) goto LAB_001055d0;
    }
  }
LAB_001055d0:
  _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
LAB_001055f4:
  if (param_3 == 0) {
    return 0xffffffea;
  }
  uVar1 = *(ulong *)(param_2 + 0x18);
  uVar8 = *(ulong *)(param_2 + 0x20);
  if (0xfffffffe < uVar8) {
    uVar8 = 0xffffffff;
  }
  if (uVar8 < uVar1 || uVar8 - uVar1 == 0) {
    pcVar7 = "Invalid domain geometry\n";
LAB_001057cc:
    _dev_err(param_1,pcVar7);
    return 0xffffffea;
  }
  puVar4 = (undefined8 *)kmalloc_trace(_memset,0xdc0,0xd0);
  if (puVar4 == (undefined8 *)0x0) {
    return 0xfffffff4;
  }
  uVar8 = (uVar8 - uVar1) + 1;
  uVar10 = uVar8 >> 0xc;
  puVar4[3] = uVar1;
  puVar4[4] = uVar8;
  uVar8 = uVar10 + 0x3f >> 3;
  uVar11 = uVar8 & 0xfffffff8;
  puVar4[5] = uVar10;
  *(uint *)(puVar4 + 6) = (uint)uVar8 & 0xfffffff8;
  lVar5 = __kmalloc(uVar11,0x12dc0);
  puVar4[7] = lVar5;
  if (lVar5 == 0) {
    lVar5 = vzalloc(uVar11);
    puVar4[7] = lVar5;
    if (lVar5 == 0) goto LAB_00105704;
  }
  lVar5 = __kmalloc(uVar11,0x12dc0);
  puVar4[8] = lVar5;
  if (lVar5 == 0) {
    lVar5 = vzalloc(uVar11);
    puVar4[8] = lVar5;
    if (lVar5 != 0) goto LAB_001056a0;
  }
  else {
LAB_001056a0:
    *(undefined4 *)(puVar4 + 0xd) = 0;
    __mutex_init(puVar4 + 0x14,"&fast->msi_cookie_init_lock",&__fast_smmu_create_mapping_sized___key
                );
    lVar5 = kmalloc_trace(_vmap,0xdc0,0x88);
    puVar4[2] = lVar5;
    if (lVar5 != 0) {
      init_iova_domain(lVar5,0x1000,uVar1 >> 0xc);
      if ((undefined8 *)0xfffffffffffff000 < puVar4) {
        return 0xfffffff4;
      }
      *puVar4 = param_1;
      puVar4[1] = param_2;
      uVar3 = _raw_write_lock_irqsave(&mappings_lock);
      plVar9 = &mappings;
      if (mappings == 0) {
        lVar5 = 0;
      }
      else {
        lVar2 = mappings;
        do {
          while (lVar5 = lVar2, *(ulong *)(lVar5 + -0x80) <= (ulong)puVar4[1]) {
            if ((ulong)puVar4[1] <= *(ulong *)(lVar5 + -0x80)) goto LAB_0010579c;
            plVar9 = (long *)(lVar5 + 8);
            lVar2 = *plVar9;
            if (*plVar9 == 0) goto LAB_00105780;
          }
          plVar9 = (long *)(lVar5 + 0x10);
          lVar2 = *plVar9;
        } while (*plVar9 != 0);
      }
LAB_00105780:
      plVar6 = puVar4 + 0x11;
      *plVar6 = lVar5;
      puVar4[0x12] = 0;
      puVar4[0x13] = 0;
      *plVar9 = (long)plVar6;
      rb_insert_color(plVar6,&mappings);
LAB_0010579c:
      _raw_write_unlock_irqrestore(&mappings_lock,uVar3);
      puVar4[0xc] = param_3;
      puVar4[0xe] = fast_smmu_notify;
      return 0;
    }
    kvfree(puVar4[8]);
  }
  kvfree(puVar4[7]);
LAB_00105704:
  kfree(puVar4);
  return 0xfffffff4;
}



//------------------------------------------------------------
// fast_smmu_notify @ 001057f4 size=268
// signature: undefined fast_smmu_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 fast_smmu_notify(long param_1,long param_2,long param_3)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (param_2 != 1) {
    __warn_printk("Unhandled notifier action");
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x105834);
    (*pcVar1)();
  }
  lVar3 = *(long *)(*(long *)(param_1 + -0x10) + 0x50);
  lVar2 = param_3 - lVar3;
  local_40 = lVar2 * 0x200;
  lVar2 = lVar2 >> 3;
  _dev_err(*(undefined8 *)(param_1 + -0x70),"Mapped over stale tlb at %pa\n",&local_40);
  _dev_err(*(undefined8 *)(param_1 + -0x70),"bitmap (failure at idx %lu):\n",lVar2);
  _dev_err(*(undefined8 *)(param_1 + -0x70),"ptep: %pK pmds: %pK diff: %lu\n",param_3,lVar3,lVar2);
  print_hex_dump(&DAT_0010adae,"bmap: ",1,0x20,8,*(undefined8 *)(param_1 + -0x38),
                 *(undefined4 *)(param_1 + -0x40),0);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// fast_smmu_setup_dma_ops @ 00105904 size=32
// signature: undefined fast_smmu_setup_dma_ops(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_setup_dma_ops(undefined8 param_1)

{
  __fast_smmu_setup_dma_ops(param_1,param_1);
  return;
}



//------------------------------------------------------------
// __fast_smmu_setup_dma_ops @ 00105928 size=1044
// signature: undefined __fast_smmu_setup_dma_ops(void)
// callers: [fast_smmu_setup_dma_ops]
//------------------------------------------------------------

void __fast_smmu_setup_dma_ops(undefined8 param_1,long param_2)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  undefined8 *puVar13;
  undefined8 *local_80;
  undefined1 *puStack_78;
  undefined4 uStack_6c;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar4 = iommu_get_domain_for_dev(param_2);
  if ((lVar4 != 0) && (uVar2 = qcom_iommu_get_mappings_configuration(), (uVar2 & 0x80000004) == 4))
  {
    uVar5 = iommu_get_domain_for_dev(param_2);
    if (uVar5 == 0) {
      lVar4 = -0x16;
LAB_00105a10:
      uVar5 = iommu_get_domain_for_dev(param_2);
      if (uVar5 == 0) {
        lVar12 = -0x16;
      }
      else {
        uVar6 = _raw_read_lock_irqsave(&mappings_lock);
        for (lVar12 = mappings; lVar12 != 0; lVar12 = *(long *)(lVar12 + 8)) {
          while (uVar5 < *(ulong *)(lVar12 + -0x80)) {
            lVar12 = *(long *)(lVar12 + 0x10);
            if (lVar12 == 0) goto LAB_00105a64;
          }
          if (uVar5 <= *(ulong *)(lVar12 + -0x80)) {
            lVar12 = lVar12 + -0x88;
            goto LAB_00105a78;
          }
        }
LAB_00105a64:
        lVar12 = 0;
LAB_00105a78:
        _raw_read_unlock_irqrestore(&mappings_lock,uVar6);
      }
      local_80 = &local_80;
      puStack_78 = (undefined1 *)&local_80;
      if (*(undefined **)(param_2 + 0x80) == &pci_bus_type) {
        local_80 = &local_80;
        puStack_78 = (undefined1 *)&local_80;
        lVar7 = qcom_pci_find_host_bridge(*(undefined8 *)(param_2 + -0xc0));
        uVar6 = _raw_spin_lock_irqsave(lVar4 + 0x68);
        for (puVar13 = *(undefined8 **)(lVar7 + 0x3b8); puVar13 != (undefined8 *)(lVar7 + 0x3b8);
            puVar13 = (undefined8 *)*puVar13) {
          plVar8 = (long *)puVar13[2];
          if (((plVar8[3] & 0x1f00U) == 0x200) || ((plVar8[3] & 0x1f00U) == 0x100)) {
            uVar9 = *plVar8 - puVar13[3] & 0xfffffffffffff000;
            uVar1 = *(ulong *)(lVar4 + 0x18);
            uVar10 = plVar8[1] + ~puVar13[3] | 0xfff;
            uVar5 = *(long *)(lVar4 + 0x20) + uVar1;
            uVar11 = uVar1;
            if (uVar1 <= uVar9) {
              uVar11 = uVar9;
            }
            if (uVar10 + 1 <= uVar5) {
              uVar5 = uVar10 + 1;
            }
            if (uVar11 < uVar5) {
              uVar11 = uVar11 - uVar1 >> 0xc;
              iVar3 = (int)(uVar5 - uVar1 >> 0xc) - (int)uVar11;
              __bitmap_set(*(undefined8 *)(lVar4 + 0x38),uVar11 & 0xffffffff,iVar3);
              __bitmap_set(*(undefined8 *)(lVar4 + 0x40),uVar11 & 0xffffffff,iVar3);
            }
          }
        }
        _raw_spin_unlock_irqrestore(lVar4 + 0x68,uVar6);
      }
      qcom_iommu_get_resv_regions(param_2,&local_80);
      uVar6 = _raw_spin_lock_irqsave(lVar12 + 0x68);
      puVar13 = local_80;
      if ((undefined8 **)local_80 != &local_80) {
        do {
          uVar11 = *(ulong *)(lVar4 + 0x18);
          uVar1 = puVar13[2];
          uVar5 = (uVar11 + *(long *)(lVar4 + 0x20)) - 1;
          uVar9 = (uVar1 + puVar13[3]) - 1;
          if (uVar9 <= uVar5) {
            uVar5 = uVar9;
          }
          uVar9 = 0;
          if (uVar11 <= uVar1) {
            uVar9 = uVar1 - uVar11;
          }
          uVar9 = uVar9 >> 0xc;
          iVar3 = ((int)(uVar5 - uVar11 >> 0xc) - (int)uVar9) + 1;
          __bitmap_set(*(undefined8 *)(lVar4 + 0x38),uVar9 & 0xffffffff,iVar3);
          __bitmap_set(*(undefined8 *)(lVar4 + 0x40),uVar9 & 0xffffffff,iVar3);
          puVar13 = (undefined8 *)*puVar13;
        } while ((undefined8 **)puVar13 != &local_80);
      }
      _raw_spin_unlock_irqrestore(lVar12 + 0x68,uVar6);
      iommu_put_resv_regions(param_2,&local_80);
      uStack_6c = 0;
      mutex_lock(lVar4 + 0xa0);
      lVar12 = lVar4 + 0x68;
      uVar6 = _raw_spin_lock_irqsave(lVar12);
      if ((*(long *)(*(long *)(lVar4 + 8) + 0x30) == 0) &&
         (iVar3 = qcom_iommu_get_msi_size(param_2,&uStack_6c), -1 < iVar3)) {
        lVar7 = __fast_smmu_alloc_iova(lVar4,uStack_6c);
        if (lVar7 == -1) {
          _dev_err(param_2,"iova allocator failed to reserve MSI range of size: 0x%x\n",uStack_6c);
        }
        else {
          _raw_spin_unlock_irqrestore(lVar12,uVar6);
          iVar3 = iommu_get_msi_cookie(*(undefined8 *)(lVar4 + 8),lVar7);
          uVar6 = _raw_spin_lock_irqsave(lVar12);
          if (iVar3 < 0) {
            _dev_err(param_2,"failed to obtain MSI iova cookie rc: %d\n",iVar3);
            __fast_smmu_free_iova(lVar4,lVar7,uStack_6c);
          }
        }
      }
      _raw_spin_unlock_irqrestore(lVar12,uVar6);
      mutex_unlock(lVar4 + 0xa0);
      *(undefined1 **)(param_2 + 0x290) = &fast_smmu_dma_ops;
    }
    else {
      uVar6 = _raw_read_lock_irqsave(&mappings_lock);
      for (lVar4 = mappings; lVar4 != 0; lVar4 = *(long *)(lVar4 + 8)) {
        while (uVar5 < *(ulong *)(lVar4 + -0x80)) {
          lVar4 = *(long *)(lVar4 + 0x10);
          if (lVar4 == 0) goto LAB_001059d4;
        }
        if (uVar5 <= *(ulong *)(lVar4 + -0x80)) {
          lVar4 = lVar4 + -0x88;
          _raw_read_unlock_irqrestore(&mappings_lock,uVar6);
          if (lVar4 == 0) goto LAB_001059f8;
          goto LAB_00105a10;
        }
      }
LAB_001059d4:
      _raw_read_unlock_irqrestore(&mappings_lock,uVar6);
LAB_001059f8:
      _dev_err(param_2,"Missing fastmap iova cookie\n");
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __fast_smmu_alloc_iova @ 00105d3c size=384
// signature: undefined __fast_smmu_alloc_iova(void)
// callers: [fast_smmu_map_page, fast_smmu_map_sg, __fast_smmu_alloc_contiguous, __fast_smmu_setup_dma_ops, fast_smmu_dma_map_resource, fast_smmu_alloc]
//------------------------------------------------------------

long __fast_smmu_alloc_iova(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  long lVar6;
  
  uVar5 = param_2 >> 0xc;
  lVar6 = *(long *)(param_1 + 8);
  lVar1 = 0;
  if (0xfff < param_2 - 1) {
    lVar1 = (long)~(-1 << (ulong)(-(int)LZCOUNT(param_2 - 1 >> 0xc) & 0x1f));
  }
  uVar2 = bitmap_find_next_zero_area_off
                    (*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x28),
                     *(undefined8 *)(param_1 + 0x48),uVar5 & 0xffffffff,lVar1,0);
  if (*(ulong *)(param_1 + 0x28) < uVar2) {
    uVar2 = bitmap_find_next_zero_area_off
                      (*(undefined8 *)(param_1 + 0x40),*(ulong *)(param_1 + 0x28),0,
                       uVar5 & 0xffffffff,lVar1,0);
    uVar3 = *(ulong *)(param_1 + 0x28);
    if (uVar3 < uVar2) {
      if (*(char *)(param_1 + 0x50) != '\0') {
        pcVar4 = *(code **)(*(long *)(lVar6 + 8) + 0x38);
        if (pcVar4 != (code *)0x0) {
          if (*(int *)(pcVar4 + -4) != -0x856fbb8) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x105e60);
            (*pcVar4)();
          }
          (*pcVar4)(lVar6);
          uVar3 = *(ulong *)(param_1 + 0x28);
        }
        memcpy(*(void **)(param_1 + 0x40),*(void **)(param_1 + 0x38),
               (ulong)((int)uVar3 + 0x3fU >> 3) & 0x1ffffff8);
        *(undefined1 *)(param_1 + 0x50) = 0;
        uVar2 = bitmap_find_next_zero_area_off
                          (*(undefined8 *)(param_1 + 0x40),*(undefined8 *)(param_1 + 0x28),0,
                           uVar5 & 0xffffffff,lVar1,0);
        if (uVar2 <= *(ulong *)(param_1 + 0x28)) goto LAB_00105db4;
      }
      return -1;
    }
  }
LAB_00105db4:
  __bitmap_set(*(undefined8 *)(param_1 + 0x38),uVar2 & 0xffffffff,uVar5 & 0xffffffff);
  __bitmap_set(*(undefined8 *)(param_1 + 0x40),uVar2 & 0xffffffff,uVar5 & 0xffffffff);
  *(ulong *)(param_1 + 0x48) = uVar2 + uVar5;
  if (*(ulong *)(param_1 + 0x28) <= uVar2 + uVar5) {
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  return *(long *)(param_1 + 0x18) + uVar2 * 0x1000;
}



//------------------------------------------------------------
// __fast_smmu_free_iova @ 00105ebc size=68
// signature: undefined __fast_smmu_free_iova(void)
// callers: [fast_smmu_map_page, __fast_smmu_setup_dma_ops, fast_smmu_alloc]
//------------------------------------------------------------

void __fast_smmu_free_iova(long param_1,long param_2,ulong param_3)

{
  __bitmap_clear(*(undefined8 *)(param_1 + 0x38),(ulong)(param_2 - *(long *)(param_1 + 0x18)) >> 0xc
                 ,param_3 >> 0xc);
  *(undefined1 *)(param_1 + 0x50) = 1;
  return;
}



//------------------------------------------------------------
// fast_smmu_alloc @ 00105f04 size=1620
// signature: undefined fast_smmu_alloc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong fast_smmu_alloc(long param_1,long param_2,long *param_3,uint param_4,ulong param_5)

{
  undefined8 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  uint uVar14;
  byte bVar15;
  long lVar16;
  ulong uVar17;
  ulong unaff_x30;
  long local_c8;
  undefined8 local_c0;
  long local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  long local_80;
  undefined8 uStack_78;
  ulong local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  uVar6 = iommu_get_domain_for_dev();
  if (uVar6 == 0) {
    puVar12 = (undefined8 *)0xffffffffffffffea;
  }
  else {
    uVar7 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar9 = mappings; lVar9 != 0; lVar9 = *(long *)(lVar9 + 0x10)) {
      while (*(ulong *)(lVar9 + -0x80) <= uVar6) {
        if (uVar6 <= *(ulong *)(lVar9 + -0x80)) {
          puVar12 = (undefined8 *)(lVar9 + -0x88);
          goto LAB_00105fb4;
        }
        lVar9 = *(long *)(lVar9 + 8);
        if (lVar9 == 0) goto LAB_00105fa0;
      }
    }
LAB_00105fa0:
    puVar12 = (undefined8 *)0x0;
LAB_00105fb4:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar7);
  }
  uVar6 = param_2 + 0xfff;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  local_b8 = 0;
  local_c8 = 0;
  uVar14 = (uint)param_5;
  if ((uVar14 >> 0xf & 1) == 0) {
    if ((uVar14 >> 0x10 & 1) == 0) {
      bVar15 = *(byte *)(param_1 + 0x34c) >> 5 & 1;
    }
    else {
      bVar15 = 0;
    }
  }
  else {
    bVar15 = 1;
  }
  uVar10 = uVar6 >> 0xc;
  uVar3 = qcom_dma_info_to_prot(0,bVar15,param_5);
  uVar17 = 0x68000000000703;
  if (arm64_use_ng_mappings != '\0') {
    uVar17 = 0x68000000000f03;
  }
  if (((param_5 & 4) == 0 & bVar15) == 0) {
    uVar17 = uVar17 | 0x60000000000008;
  }
  if (uVar6 >> 0x2c == 0) {
    uVar13 = uVar6 & 0xfffffffffffff000;
    uVar2 = param_4 | 0x100;
    *param_3 = -1;
    if ((param_4 >> 10 & 1) == 0) {
      local_70 = 0;
      uVar3 = qcom_dma_info_to_prot(0,bVar15,param_5);
      if (bVar15 == 0) {
        uVar17 = qcom_dma_alloc_from_pool(*puVar12,uVar13,&local_70,uVar2);
      }
      else {
        uVar7 = tpidr_el1;
        iVar4 = 0;
        if (uVar13 - 1 != 0xfff) {
          iVar4 = 0x40 - (int)LZCOUNT(uVar13 - 1 >> 0xc);
        }
        local_70 = __alloc_pages(uVar7,uVar2,iVar4,0,0);
        if (local_70 == 0) goto LAB_001064dc;
        uVar17 = (local_70 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
      }
      if (uVar17 == 0) goto LAB_001064e0;
      puVar8 = puVar12 + 0xd;
      uVar7 = _raw_spin_lock_irqsave(puVar8);
      lVar9 = __fast_smmu_alloc_iova(puVar12,uVar13);
      if (lVar9 == -1) {
        _dev_err(*puVar12,"no iova\n");
      }
      else {
        iVar4 = av8l_fast_map_public
                          (puVar12[0xc],lVar9,
                           (local_70 + (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) *
                           0x40,uVar13,uVar3);
        if (iVar4 == 0) {
          _raw_spin_unlock_irqrestore(puVar8,uVar7);
          *param_3 = lVar9;
          goto LAB_001064e0;
        }
        _dev_err(*puVar12,"no map public\n");
        __fast_smmu_free_iova(puVar12,lVar9,uVar13);
      }
      _raw_spin_unlock_irqrestore(puVar8,uVar7);
      if (bVar15 == 0) {
        qcom_dma_free_from_pool(*puVar12,uVar17,uVar13);
      }
      else {
        iVar4 = 0;
        if (uVar13 - 1 != 0xfff) {
          iVar4 = 0x40 - (int)LZCOUNT(uVar13 - 1 >> 0xc);
        }
        __free_pages(local_70,iVar4);
      }
    }
    else {
      if ((uVar14 >> 6 & 1) != 0) {
        uVar17 = __fast_smmu_alloc_contiguous(param_1,uVar13,param_3,uVar2,param_5);
        goto LAB_001064e0;
      }
      iVar4 = (int)uVar10;
      if ((uint)(iVar4 * 8) < 0x1001) {
        puVar8 = (undefined8 *)__kmalloc(iVar4 * 8,0xdc0);
      }
      else {
        puVar8 = (undefined8 *)vzalloc();
      }
      if (puVar8 == (undefined8 *)0x0) {
LAB_001064b8:
        _dev_err(param_1,"no pages\n");
      }
      else {
        if (iVar4 != 0) {
          uVar11 = 0;
          do {
            uVar7 = tpidr_el1;
            lVar9 = __alloc_pages(uVar7,param_4 | 0x2102,0,0,0);
            if (lVar9 == 0) {
              if (0 < (int)uVar11) {
                uVar6 = 0;
                do {
                  __free_pages(puVar8[uVar6],0);
                  uVar6 = uVar6 + 1;
                } while (uVar11 != uVar6);
              }
              kvfree(puVar8);
              goto LAB_001064b8;
            }
            puVar8[uVar11] = lVar9;
            uVar11 = uVar11 + 1;
          } while ((uVar6 >> 0xc & 0xffffffff) != uVar11);
        }
        iVar5 = sg_alloc_table_from_pages_segment(&local_80,puVar8,uVar10,0,uVar13,0xffffffff,uVar2)
        ;
        if (iVar5 == 0) {
          if (bVar15 == 0) {
            sg_miter_start(&local_c8,local_80,uStack_78._4_4_,4);
            while (uVar10 = sg_miter_next(&local_c8), (uVar10 & 1) != 0) {
              qcom_arch_dma_prep_coherent(local_c8,local_b8);
            }
            sg_miter_stop(&local_c8);
          }
          puVar1 = puVar12 + 0xd;
          uVar7 = _raw_spin_lock_irqsave(puVar1);
          lVar9 = __fast_smmu_alloc_iova(puVar12,uVar13);
          if (lVar9 == -1) {
            _dev_err(param_1,"no iova\n");
          }
          else {
            sg_miter_start(&local_c8,local_80,uStack_78._4_4_,5);
            uVar10 = sg_miter_next(&local_c8);
            if ((uVar10 & 1) != 0) {
              lVar16 = lVar9;
              do {
                iVar5 = av8l_fast_map_public
                                  (puVar12[0xc],lVar16,
                                   (local_c8 +
                                   (_memstart_addr >> 6 & 0x3ffffffffffffc0) + 0x200000000) * 0x40,
                                   local_b8,uVar3);
                if (iVar5 != 0) {
                  _dev_err(param_1,"no map public\n");
                  goto LAB_00106430;
                }
                lVar16 = local_b8 + lVar16;
                uVar10 = sg_miter_next(&local_c8);
              } while ((uVar10 & 1) != 0);
            }
            sg_miter_stop(&local_c8);
            _raw_spin_unlock_irqrestore(puVar1,uVar7);
            uVar10 = unaff_x30 & 0xff80007fffffffff;
            if ((unaff_x30 & 0x80000000000000) != 0) {
              uVar10 = unaff_x30 | 0xffffff8000000000;
            }
            uVar17 = qcom_dma_common_pages_remap(puVar8,uVar13,uVar17,uVar10);
            if (uVar17 != 0) {
              *param_3 = lVar9;
              sg_free_table(&local_80);
              goto LAB_001064e0;
            }
            _dev_err(param_1,"no common pages\n");
            uVar7 = _raw_spin_lock_irqsave(puVar1);
            av8l_fast_unmap_public(puVar12[0xc],lVar9,uVar13);
LAB_00106430:
            __fast_smmu_free_iova(puVar12,lVar9,uVar13);
          }
          _raw_spin_unlock_irqrestore(puVar1,uVar7);
          sg_free_table(&local_80);
        }
        else {
          _dev_err(param_1,"no sg tablen\n");
        }
        if (0 < iVar4) {
          uVar6 = uVar6 >> 0xc & 0xffffffff;
          puVar12 = puVar8;
          do {
            __free_pages(*puVar12,0);
            uVar6 = uVar6 - 1;
            puVar12 = puVar12 + 1;
          } while (uVar6 != 0);
        }
        kvfree(puVar8);
      }
    }
  }
  else {
    _dev_err(param_1,"count: %zx exceeds UNIT_MAX\n",uVar10);
  }
LAB_001064dc:
  uVar17 = 0;
LAB_001064e0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17;
}



//------------------------------------------------------------
// fast_smmu_free @ 00106564 size=480
// signature: undefined fast_smmu_free(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_free(undefined8 param_1,long param_2,long param_3,long param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  
  uVar2 = iommu_get_domain_for_dev();
  if (uVar2 == 0) {
    lVar9 = -0x16;
  }
  else {
    uVar3 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar9 = mappings; lVar9 != 0; lVar9 = *(long *)(lVar9 + 0x10)) {
      while (*(ulong *)(lVar9 + -0x80) <= uVar2) {
        if (uVar2 <= *(ulong *)(lVar9 + -0x80)) {
          lVar9 = lVar9 + -0x88;
          goto LAB_001065f8;
        }
        lVar9 = *(long *)(lVar9 + 8);
        if (lVar9 == 0) goto LAB_001065e4;
      }
    }
LAB_001065e4:
    lVar9 = 0;
LAB_001065f8:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
  }
  lVar1 = lVar9 + 0x68;
  uVar2 = param_2 + 0xfff;
  uVar8 = uVar2 & 0xfffffffffffff000;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  lVar4 = av8l_fast_unmap_public(*(undefined8 *)(lVar9 + 0x60),param_4,uVar8);
  if (lVar4 == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
  }
  else {
    __bitmap_clear(*(undefined8 *)(lVar9 + 0x38),(ulong)(param_4 - *(long *)(lVar9 + 0x18)) >> 0xc,
                   uVar2 >> 0xc & 0xffffffff);
    *(undefined1 *)(lVar9 + 0x50) = 1;
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
    uVar5 = qcom_dma_free_from_pool(param_1,param_3,uVar8);
    if ((uVar5 & 1) == 0) {
      uVar5 = is_vmalloc_addr(param_3);
      if ((uVar5 & 1) == 0) {
        lVar9 = (((param_3 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000;
      }
      else {
        puVar6 = (undefined8 *)qcom_dma_common_find_pages(param_3);
        if (puVar6 != (undefined8 *)0x0) {
          qcom_dma_common_free_remap(param_3,uVar8);
          if (0 < (int)(uVar2 >> 0xc)) {
            uVar2 = uVar2 >> 0xc & 0xffffffff;
            puVar7 = puVar6;
            do {
              __free_pages(*puVar7,0);
              uVar2 = uVar2 - 1;
              puVar7 = puVar7 + 1;
            } while (uVar2 != 0);
          }
          kvfree(puVar6);
          return;
        }
        lVar9 = vmalloc_to_page(param_3);
        qcom_dma_common_free_remap(param_3,uVar8);
      }
      if (lVar9 != 0) {
        qcom_dma_free_contiguous(param_1,lVar9,uVar8);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// fast_smmu_mmap_attrs @ 00106748 size=28
// signature: undefined fast_smmu_mmap_attrs(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_mmap_attrs(void)

{
  qcom_iommu_dma_mmap();
  return;
}



//------------------------------------------------------------
// fast_smmu_get_sgtable @ 00106768 size=28
// signature: undefined fast_smmu_get_sgtable(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_get_sgtable(void)

{
  qcom_iommu_dma_get_sgtable();
  return;
}



//------------------------------------------------------------
// fast_smmu_map_page @ 00106788 size=460
// signature: undefined fast_smmu_map_page(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long fast_smmu_map_page(long param_1,long param_2,long param_3,long param_4,undefined4 param_5,
                       undefined8 param_6)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  byte bVar10;
  
  uVar4 = iommu_get_domain_for_dev();
  if (uVar4 == 0) {
    lVar7 = -0x16;
  }
  else {
    uVar5 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar7 = mappings; lVar7 != 0; lVar7 = *(long *)(lVar7 + 8)) {
      while (uVar4 < *(ulong *)(lVar7 + -0x80)) {
        lVar7 = *(long *)(lVar7 + 0x10);
        if (lVar7 == 0) goto LAB_00106814;
      }
      if (uVar4 <= *(ulong *)(lVar7 + -0x80)) {
        lVar7 = lVar7 + -0x88;
        goto LAB_00106828;
      }
    }
LAB_00106814:
    lVar7 = 0;
LAB_00106828:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar5);
  }
  uVar4 = param_3 + (param_2 + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000;
  uVar9 = param_4 + (uVar4 & 0xfff) + 0xfff & 0xfffffffffffff000;
  uVar8 = (uint)param_6;
  if ((uVar8 >> 0xf & 1) == 0) {
    if ((uVar8 >> 0x10 & 1) == 0) {
      bVar10 = *(byte *)(param_1 + 0x34c) >> 5 & 1;
    }
    else {
      bVar10 = 0;
    }
    uVar2 = qcom_dma_info_to_prot(param_5,bVar10,param_6);
    if (((uVar8 >> 5 & 1) == 0) && (bVar10 == 0)) {
      qcom_arch_sync_dma_for_device(uVar4,param_4,param_5);
    }
  }
  else {
    uVar2 = qcom_dma_info_to_prot(param_5,1,param_6);
  }
  lVar1 = lVar7 + 0x68;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  lVar6 = __fast_smmu_alloc_iova(lVar7,uVar9);
  if (lVar6 != -1) {
    iVar3 = av8l_fast_map_public
                      (*(undefined8 *)(lVar7 + 0x60),lVar6,uVar4 & 0xfffffffffffff000,uVar9,uVar2);
    if (iVar3 == 0) {
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      return lVar6 + (uVar4 & 0xfff);
    }
    __fast_smmu_free_iova(lVar7,lVar6,param_4);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  return -1;
}



//------------------------------------------------------------
// fast_smmu_unmap_page @ 00106958 size=356
// signature: undefined fast_smmu_unmap_page(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_unmap_page(long param_1,ulong param_2,long param_3,undefined4 param_4,uint param_5)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  byte bVar5;
  long lVar6;
  
  uVar2 = iommu_get_domain_for_dev();
  if (uVar2 == 0) {
    lVar6 = -0x16;
  }
  else {
    uVar3 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar6 = mappings; lVar6 != 0; lVar6 = *(long *)(lVar6 + 0x10)) {
      while (*(ulong *)(lVar6 + -0x80) <= uVar2) {
        if (uVar2 <= *(ulong *)(lVar6 + -0x80)) {
          lVar6 = lVar6 + -0x88;
          goto LAB_001069f0;
        }
        lVar6 = *(long *)(lVar6 + 8);
        if (lVar6 == 0) goto LAB_001069dc;
      }
    }
LAB_001069dc:
    lVar6 = 0;
LAB_001069f0:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
  }
  uVar2 = param_3 + (param_2 & 0xfff) + 0xfff;
  if ((param_5 >> 0xf & 1) == 0) {
    if ((param_5 >> 0x10 & 1) == 0) {
      bVar5 = *(byte *)(param_1 + 0x34c) >> 5 & 1;
    }
    else {
      bVar5 = 0;
    }
    if (((param_5 >> 5 & 1) == 0) && (bVar5 == 0)) {
      lVar4 = av8l_fast_iova_to_phys_public(*(undefined8 *)(lVar6 + 0x60),param_2);
      if (lVar4 == 0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106abc);
        (*pcVar1)();
      }
      qcom_arch_sync_dma_for_cpu(lVar4,param_3,param_4);
    }
  }
  uVar3 = _raw_spin_lock_irqsave(lVar6 + 0x68);
  lVar4 = av8l_fast_unmap_public(*(undefined8 *)(lVar6 + 0x60),param_2,uVar2 & 0xfffffffffffff000);
  if (lVar4 != 0) {
    __bitmap_clear(*(undefined8 *)(lVar6 + 0x38),param_2 - *(long *)(lVar6 + 0x18) >> 0xc,
                   uVar2 >> 0xc);
    *(undefined1 *)(lVar6 + 0x50) = 1;
  }
  _raw_spin_unlock_irqrestore(lVar6 + 0x68,uVar3);
  return;
}



//------------------------------------------------------------
// fast_smmu_map_sg @ 00106ac4 size=472
// signature: undefined fast_smmu_map_sg(void)
// callers: []
//------------------------------------------------------------

undefined4
fast_smmu_map_sg(long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                undefined8 param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  byte bVar6;
  uint uVar7;
  long lVar8;
  undefined8 local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  uVar2 = iommu_get_domain_for_dev();
  uVar7 = (uint)param_5;
  if (uVar2 == 0) {
    lVar8 = -0x16;
  }
  else {
    uVar3 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar8 = mappings; lVar8 != 0; lVar8 = *(long *)(lVar8 + 0x10)) {
      while (*(ulong *)(lVar8 + -0x80) <= uVar2) {
        if (uVar2 <= *(ulong *)(lVar8 + -0x80)) {
          lVar8 = lVar8 + -0x88;
          goto LAB_00106b78;
        }
        lVar8 = *(long *)(lVar8 + 8);
        if (lVar8 == 0) goto LAB_00106b5c;
      }
    }
LAB_00106b5c:
    lVar8 = 0;
LAB_00106b78:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
  }
  if ((uVar7 >> 0xf & 1) == 0) {
    if ((uVar7 >> 0x10 & 1) == 0) {
      bVar6 = *(byte *)(param_1 + 0x34c) >> 5 & 1;
    }
    else {
      bVar6 = 0;
    }
  }
  else {
    bVar6 = 1;
  }
  uVar1 = qcom_dma_info_to_prot(param_4,bVar6,param_5);
  local_70 = 0;
  uVar3 = qcom_iommu_dma_prepare_map_sg(param_1,*(undefined8 *)(lVar8 + 0x10),param_2,param_3);
  uVar4 = _raw_spin_lock_irqsave(lVar8 + 0x68);
  lVar5 = __fast_smmu_alloc_iova(lVar8,uVar3);
  _raw_spin_unlock_irqrestore(lVar8 + 0x68,uVar4);
  if (lVar5 == -1) {
    qcom_iommu_dma_invalidate_sg(param_2,param_3);
    uVar1 = 0;
  }
  else {
    av8l_fast_map_sg_public(*(undefined8 *)(lVar8 + 0x60),lVar5,param_2,param_3,uVar1,&local_70);
    uVar1 = qcom_iommu_dma_finalise_sg(param_1,param_2,param_3,lVar5);
    if ((uVar7 >> 5 & 1) == 0) {
      fast_smmu_sync_sg_for_device(param_1,param_2,param_3,param_4);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}



//------------------------------------------------------------
// fast_smmu_unmap_sg @ 00106ca0 size=364
// signature: undefined fast_smmu_unmap_sg(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_unmap_sg(undefined8 param_1,long param_2,int param_3,undefined4 param_4,uint param_5)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  uVar2 = iommu_get_domain_for_dev();
  if (uVar2 == 0) {
    lVar6 = -0x16;
  }
  else {
    uVar3 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar6 = mappings; lVar6 != 0; lVar6 = *(long *)(lVar6 + 0x10)) {
      while (*(ulong *)(lVar6 + -0x80) <= uVar2) {
        if (uVar2 <= *(ulong *)(lVar6 + -0x80)) {
          lVar6 = lVar6 + -0x88;
          goto LAB_00106d38;
        }
        lVar6 = *(long *)(lVar6 + 8);
        if (lVar6 == 0) goto LAB_00106d20;
      }
    }
LAB_00106d20:
    lVar6 = 0;
LAB_00106d38:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
  }
  if ((param_5 >> 5 & 1) == 0) {
    fast_smmu_sync_sg_for_cpu(param_1,param_2,param_3,param_4);
  }
  uVar2 = *(ulong *)(param_2 + 0x10);
  lVar4 = sg_next(param_2);
  param_3 = param_3 + -1;
  if (0 < param_3) {
    do {
      lVar5 = lVar4;
      if (*(int *)(lVar5 + 0x18) == 0) break;
      lVar4 = sg_next();
      param_3 = param_3 + -1;
      param_2 = lVar5;
    } while (param_3 != 0);
  }
  uVar1 = (*(long *)(param_2 + 0x10) - (uVar2 & 0xfffffffffffff000)) +
          (ulong)*(uint *)(param_2 + 0x18) + 0xfff;
  lVar4 = av8l_fast_unmap_public(*(undefined8 *)(lVar6 + 0x60),uVar2,uVar1 & 0xfffffffffffff000);
  if (lVar4 != 0) {
    uVar3 = _raw_spin_lock_irqsave(lVar6 + 0x68);
    __bitmap_clear(*(undefined8 *)(lVar6 + 0x38),uVar2 - *(long *)(lVar6 + 0x18) >> 0xc,uVar1 >> 0xc
                  );
    *(undefined1 *)(lVar6 + 0x50) = 1;
    _raw_spin_unlock_irqrestore(lVar6 + 0x68,uVar3);
  }
  return;
}



//------------------------------------------------------------
// fast_smmu_dma_map_resource @ 00106e10 size=384
// signature: undefined fast_smmu_dma_map_resource(void)
// callers: []
//------------------------------------------------------------

long fast_smmu_dma_map_resource
               (undefined8 param_1,ulong param_2,long param_3,undefined4 param_4,undefined8 param_5)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  uVar4 = iommu_get_domain_for_dev();
  if (uVar4 == 0) {
    lVar7 = -0x16;
  }
  else {
    uVar5 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar7 = mappings; lVar7 != 0; lVar7 = *(long *)(lVar7 + 8)) {
      while (uVar4 < *(ulong *)(lVar7 + -0x80)) {
        lVar7 = *(long *)(lVar7 + 0x10);
        if (lVar7 == 0) goto LAB_00106e94;
      }
      if (uVar4 <= *(ulong *)(lVar7 + -0x80)) {
        lVar7 = lVar7 + -0x88;
        goto LAB_00106ea8;
      }
    }
LAB_00106e94:
    lVar7 = 0;
LAB_00106ea8:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar5);
  }
  lVar1 = lVar7 + 0x68;
  uVar4 = ((param_3 + (param_2 & 0xfff)) - 1 | 0xfff) + 1;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  lVar6 = __fast_smmu_alloc_iova(lVar7,uVar4);
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  if (lVar6 != -1) {
    uVar2 = qcom_dma_info_to_prot(param_4,0,param_5);
    iVar3 = iommu_map(*(undefined8 *)(lVar7 + 8),lVar6,param_2 & 0xfffffffffffff000,uVar4,
                      uVar2 | 0x10);
    if (iVar3 == 0) {
      return lVar6 + (param_2 & 0xfff);
    }
    uVar5 = _raw_spin_lock_irqsave(lVar1);
    __bitmap_clear(*(undefined8 *)(lVar7 + 0x38),(ulong)(lVar6 - *(long *)(lVar7 + 0x18)) >> 0xc,
                   uVar4 >> 0xc);
    *(undefined1 *)(lVar7 + 0x50) = 1;
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
  }
  return -1;
}



//------------------------------------------------------------
// fast_smmu_dma_unmap_resource @ 00106f94 size=268
// signature: undefined fast_smmu_dma_unmap_resource(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_dma_unmap_resource(undefined8 param_1,ulong param_2,long param_3)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  
  uVar1 = iommu_get_domain_for_dev();
  if (uVar1 == 0) {
    lVar3 = -0x16;
  }
  else {
    uVar2 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar3 = mappings; lVar3 != 0; lVar3 = *(long *)(lVar3 + 8)) {
      while (uVar1 < *(ulong *)(lVar3 + -0x80)) {
        lVar3 = *(long *)(lVar3 + 0x10);
        if (lVar3 == 0) goto LAB_00107008;
      }
      if (uVar1 <= *(ulong *)(lVar3 + -0x80)) {
        lVar3 = lVar3 + -0x88;
        goto LAB_0010701c;
      }
    }
LAB_00107008:
    lVar3 = 0;
LAB_0010701c:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar2);
  }
  uVar1 = ((param_3 + (param_2 & 0xfff)) - 1 | 0xfff) + 1;
  iommu_unmap(*(undefined8 *)(lVar3 + 8),param_2 & 0xfffffffffffff000,uVar1);
  uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x68);
  __bitmap_clear(*(undefined8 *)(lVar3 + 0x38),param_2 - *(long *)(lVar3 + 0x18) >> 0xc,uVar1 >> 0xc
                );
  *(undefined1 *)(lVar3 + 0x50) = 1;
  _raw_spin_unlock_irqrestore(lVar3 + 0x68,uVar2);
  return;
}



//------------------------------------------------------------
// fast_smmu_sync_single_for_cpu @ 001070a4 size=216
// signature: undefined fast_smmu_sync_single_for_cpu(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_sync_single_for_cpu
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = iommu_get_domain_for_dev();
  if (uVar2 == 0) {
    lVar4 = -0x16;
  }
  else {
    uVar3 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar4 = mappings; lVar4 != 0; lVar4 = *(long *)(lVar4 + 8)) {
      while (uVar2 < *(ulong *)(lVar4 + -0x80)) {
        lVar4 = *(long *)(lVar4 + 0x10);
        if (lVar4 == 0) goto LAB_00107118;
      }
      if (uVar2 <= *(ulong *)(lVar4 + -0x80)) {
        lVar4 = lVar4 + -0x88;
        goto LAB_0010712c;
      }
    }
LAB_00107118:
    lVar4 = 0;
LAB_0010712c:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
  }
  uVar2 = av8l_fast_iova_coherent_public(*(undefined8 *)(lVar4 + 0x60),param_2);
  if ((uVar2 & 1) == 0) {
    lVar4 = av8l_fast_iova_to_phys_public(*(undefined8 *)(lVar4 + 0x60),param_2);
    if (lVar4 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10717c);
      (*pcVar1)();
    }
    qcom_arch_sync_dma_for_cpu(lVar4,param_3,param_4);
  }
  return;
}



//------------------------------------------------------------
// fast_smmu_sync_single_for_device @ 00107184 size=216
// signature: undefined fast_smmu_sync_single_for_device(void)
// callers: []
//------------------------------------------------------------

void fast_smmu_sync_single_for_device
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = iommu_get_domain_for_dev();
  if (uVar2 == 0) {
    lVar4 = -0x16;
  }
  else {
    uVar3 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar4 = mappings; lVar4 != 0; lVar4 = *(long *)(lVar4 + 8)) {
      while (uVar2 < *(ulong *)(lVar4 + -0x80)) {
        lVar4 = *(long *)(lVar4 + 0x10);
        if (lVar4 == 0) goto LAB_001071f8;
      }
      if (uVar2 <= *(ulong *)(lVar4 + -0x80)) {
        lVar4 = lVar4 + -0x88;
        goto LAB_0010720c;
      }
    }
LAB_001071f8:
    lVar4 = 0;
LAB_0010720c:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar3);
  }
  uVar2 = av8l_fast_iova_coherent_public(*(undefined8 *)(lVar4 + 0x60),param_2);
  if ((uVar2 & 1) == 0) {
    lVar4 = av8l_fast_iova_to_phys_public(*(undefined8 *)(lVar4 + 0x60),param_2);
    if (lVar4 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10725c);
      (*pcVar1)();
    }
    qcom_arch_sync_dma_for_device(lVar4,param_3,param_4);
  }
  return;
}



//------------------------------------------------------------
// fast_smmu_sync_sg_for_cpu @ 00107264 size=272
// signature: undefined fast_smmu_sync_sg_for_cpu(void)
// callers: [fast_smmu_unmap_sg]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fast_smmu_sync_sg_for_cpu(undefined8 param_1,ulong *param_2,int param_3,undefined4 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  uVar3 = param_2[2];
  uVar1 = iommu_get_domain_for_dev();
  if (uVar1 == 0) {
    lVar4 = -0x16;
  }
  else {
    uVar2 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar4 = mappings; lVar4 != 0; lVar4 = *(long *)(lVar4 + 8)) {
      while (uVar1 < *(ulong *)(lVar4 + -0x80)) {
        lVar4 = *(long *)(lVar4 + 0x10);
        if (lVar4 == 0) goto LAB_001072e0;
      }
      if (uVar1 <= *(ulong *)(lVar4 + -0x80)) {
        lVar4 = lVar4 + -0x88;
        goto LAB_001072f4;
      }
    }
LAB_001072e0:
    lVar4 = 0;
LAB_001072f4:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar2);
  }
  uVar1 = av8l_fast_iova_coherent_public(*(undefined8 *)(lVar4 + 0x60),uVar3);
  if ((0 < param_3) && ((uVar1 & 1) == 0)) {
    do {
      qcom_arch_sync_dma_for_cpu
                ((ulong)(uint)param_2[1] +
                 ((*param_2 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 +
                 0x8000000000,*(undefined4 *)((long)param_2 + 0xc),param_4);
      param_2 = (ulong *)sg_next(param_2);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



//------------------------------------------------------------
// fast_smmu_sync_sg_for_device @ 00107378 size=272
// signature: undefined fast_smmu_sync_sg_for_device(void)
// callers: [fast_smmu_map_sg]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fast_smmu_sync_sg_for_device(undefined8 param_1,ulong *param_2,int param_3,undefined4 param_4)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  uVar3 = param_2[2];
  uVar1 = iommu_get_domain_for_dev();
  if (uVar1 == 0) {
    lVar4 = -0x16;
  }
  else {
    uVar2 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar4 = mappings; lVar4 != 0; lVar4 = *(long *)(lVar4 + 8)) {
      while (uVar1 < *(ulong *)(lVar4 + -0x80)) {
        lVar4 = *(long *)(lVar4 + 0x10);
        if (lVar4 == 0) goto LAB_001073f4;
      }
      if (uVar1 <= *(ulong *)(lVar4 + -0x80)) {
        lVar4 = lVar4 + -0x88;
        goto LAB_00107408;
      }
    }
LAB_001073f4:
    lVar4 = 0;
LAB_00107408:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar2);
  }
  uVar1 = av8l_fast_iova_coherent_public(*(undefined8 *)(lVar4 + 0x60),uVar3);
  if ((0 < param_3) && ((uVar1 & 1) == 0)) {
    do {
      qcom_arch_sync_dma_for_device
                ((ulong)(uint)param_2[1] +
                 ((*param_2 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 +
                 0x8000000000,*(undefined4 *)((long)param_2 + 0xc),param_4);
      param_2 = (ulong *)sg_next(param_2);
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



//------------------------------------------------------------
// __fast_smmu_alloc_contiguous @ 0010748c size=656
// signature: undefined __fast_smmu_alloc_contiguous(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * __fast_smmu_alloc_contiguous
                 (long param_1,ulong param_2,long *param_3,uint param_4,ulong param_5)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  byte bVar10;
  void *__s;
  
  uVar3 = iommu_get_domain_for_dev();
  uVar8 = (uint)param_5;
  if (uVar3 == 0) {
    lVar7 = -0x16;
    if ((uVar8 >> 0xf & 1) == 0) goto LAB_00107544;
LAB_00107528:
    bVar10 = 1;
  }
  else {
    uVar4 = _raw_read_lock_irqsave(&mappings_lock);
    for (lVar7 = mappings; lVar7 != 0; lVar7 = *(long *)(lVar7 + 8)) {
      while (uVar3 < *(ulong *)(lVar7 + -0x80)) {
        lVar7 = *(long *)(lVar7 + 0x10);
        if (lVar7 == 0) goto LAB_00107518;
      }
      if (uVar3 <= *(ulong *)(lVar7 + -0x80)) {
        lVar7 = lVar7 + -0x88;
        goto LAB_00107534;
      }
    }
LAB_00107518:
    lVar7 = 0;
LAB_00107534:
    _raw_read_unlock_irqrestore(&mappings_lock,uVar4);
    if ((uVar8 >> 0xf & 1) != 0) goto LAB_00107528;
LAB_00107544:
    if ((uVar8 >> 0x10 & 1) == 0) {
      bVar10 = *(byte *)(param_1 + 0x34c) >> 5 & 1;
    }
    else {
      bVar10 = 0;
    }
  }
  uVar1 = qcom_dma_info_to_prot(0,bVar10,param_5);
  uVar9 = param_2 >> 0xc;
  uVar3 = 0x68000000000703;
  if (arm64_use_ng_mappings != '\0') {
    uVar3 = 0x68000000000f03;
  }
  if (((param_5 & 4) == 0 & bVar10) == 0) {
    uVar3 = uVar3 | 0x60000000000008;
  }
  iVar2 = 0;
  if (0xfff < param_2 - 1) {
    iVar2 = 0x40 - (int)LZCOUNT(param_2 - 1 >> 0xc);
  }
  uVar5 = qcom_dma_alloc_from_contiguous(param_1,uVar9,iVar2,param_4 >> 0xd & 1);
  if (uVar5 != 0) {
    uVar4 = _raw_spin_lock_irqsave(lVar7 + 0x68);
    lVar6 = __fast_smmu_alloc_iova(lVar7,param_2);
    _raw_spin_unlock_irqrestore(lVar7 + 0x68,uVar4);
    if (lVar6 != -1) {
      iVar2 = av8l_fast_map_public
                        (*(undefined8 *)(lVar7 + 0x60),lVar6,
                         (uVar5 + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000,param_2,
                         uVar1);
      if (iVar2 == 0) {
        if (bVar10 != 0) {
          __s = (void *)((uVar5 & 0x3ffffffffffc0) << 6 | 0xff00000000000000);
LAB_001076f8:
          memset(__s,0,param_2);
          *param_3 = lVar6;
          return __s;
        }
        __s = (void *)qcom_dma_common_contiguous_remap
                                (uVar5,param_2,uVar3,__fast_smmu_alloc_contiguous);
        if (__s != (void *)0x0) {
          qcom_arch_dma_prep_coherent(uVar5,param_2);
          goto LAB_001076f8;
        }
        av8l_fast_unmap_public(*(undefined8 *)(lVar7 + 0x60),lVar6,param_2);
      }
      __bitmap_clear(*(undefined8 *)(lVar7 + 0x38),(ulong)(lVar6 - *(long *)(lVar7 + 0x18)) >> 0xc,
                     uVar9 & 0xffffffff);
      *(undefined1 *)(lVar7 + 0x50) = 1;
    }
    qcom_dma_release_from_contiguous(param_1,uVar5,uVar9 & 0xffffffff);
  }
  return (void *)0x0;
}



//------------------------------------------------------------
// qcom_arm_lpae_map_pages @ 00107730 size=352
// signature: undefined qcom_arm_lpae_map_pages(void)
// callers: [qcom_arm_lpae_map]
//------------------------------------------------------------

undefined4
qcom_arm_lpae_map_pages
          (long param_1,long param_2,ulong param_3,ulong param_4,long param_5,uint param_6,
          undefined4 param_7,undefined8 param_8)

{
  long lVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if (((param_4 == 0) || (param_5 == 0)) || ((*(ulong *)(param_1 + -0x50) & param_4) != param_4)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x107844);
    (*pcVar2)();
  }
  if ((param_2 >> ((ulong)*(uint *)(param_1 + -0x48) & 0x3f) !=
       (*(long *)(param_1 + -0x58) << 0x3a) >> 0x3f) ||
     (param_3 >> ((ulong)*(uint *)(param_1 + -0x44) & 0x3f) != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x107850);
    (*pcVar2)();
  }
  if ((param_6 & 3) == 0) {
    uVar3 = 0;
  }
  else {
    uVar5 = *(undefined8 *)(param_1 + 0x38);
    uVar3 = *(undefined4 *)(param_1 + 0x2c);
    uVar4 = arm_lpae_prot_to_pte(param_1 + -0x68,param_6);
    local_70 = _raw_spin_lock_irqsave(param_1 + 0x58);
    uVar3 = __arm_lpae_map(param_1 + -0x68,param_2,param_3,param_4,param_5,uVar4,uVar3,uVar5,0,0,
                           param_7,&local_70,param_8);
    _raw_spin_unlock_irqrestore(param_1 + 0x58,local_70);
    DataSynchronizationBarrier(3,2,0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// arm_lpae_prot_to_pte @ 00107898 size=220
// signature: undefined arm_lpae_prot_to_pte(void)
// callers: [qcom_arm_lpae_map_sg, qcom_arm_lpae_map_pages]
//------------------------------------------------------------

ulong arm_lpae_prot_to_pte(uint *param_1,uint param_2)

{
  ulong uVar1;
  uint uVar2;
  ulong uVar3;
  ulong uVar4;
  
  uVar2 = *param_1;
  if ((uVar2 == 0) || (uVar2 == 0xfffffffe)) {
    uVar4 = 0x880;
    if ((param_2 & 3) != 1) {
      uVar4 = 0x800;
    }
    uVar3 = uVar4 | 0x40;
    if ((param_2 & 0x20) != 0) {
      uVar3 = uVar4;
    }
  }
  else {
    uVar3 = (ulong)((param_2 & 3) << 6);
  }
  if ((uVar2 | 2) == 3) {
    if ((param_2 >> 4 & 1) == 0) {
      uVar4 = 0x14;
      if ((param_2 & 4) != 0) {
        uVar4 = 0x3c;
      }
      goto LAB_0010792c;
    }
  }
  else {
    if ((param_2 >> 4 & 1) != 0) {
      uVar4 = 8;
      goto LAB_0010792c;
    }
    if (((param_2 ^ 0xffffffff) & 0x84) == 0) {
      uVar4 = 0x14;
      goto LAB_0010792c;
    }
    if ((param_2 >> 2 & 1) == 0) {
      if ((param_2 >> 6 & 1) == 0) {
        uVar4 = (ulong)(param_2 >> 3 & 0x10);
      }
      else {
        uVar4 = 0xc;
      }
      goto LAB_0010792c;
    }
  }
  uVar4 = 4;
LAB_0010792c:
  uVar1 = 0x200;
  if ((param_2 & 4) != 0) {
    uVar1 = 0x300;
  }
  uVar3 = uVar3 | uVar4 | uVar1;
  if ((param_2 & 8) != 0) {
    uVar3 = uVar3 | 0x60000000000000;
  }
  uVar3 = ((ulong)param_1[4] & 1) << 5 | uVar3;
  if (uVar2 != 5) {
    uVar3 = uVar3 | 0x400;
  }
  return uVar3;
}



//------------------------------------------------------------
// __arm_lpae_map @ 00107974 size=1260
// signature: undefined __arm_lpae_map(void)
// callers: [qcom_arm_lpae_map_sg, qcom_arm_lpae_map_pages, __arm_lpae_map]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__arm_lpae_map(long param_1,ulong param_2,undefined8 param_3,long param_4,undefined8 param_5,
              undefined8 param_6,int param_7,long param_8,long param_9,long *param_10,
              undefined4 param_11,undefined8 *param_12,long *param_13)

{
  ulong *puVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  undefined8 uVar6;
  ulong uVar7;
  int iVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  long *local_68;
  
  uVar3 = *(uint *)(param_1 + 0x98);
  uVar7 = (ulong)(uVar3 * (4 - param_7) + 3);
  lVar9 = 1L << (uVar7 & 0x3f);
  if (*(int *)(param_1 + 0x94) == param_7) {
    iVar8 = *(int *)(param_1 + 0x90) - uVar3;
  }
  else {
    iVar8 = 0;
  }
  uVar2 = (uint)(param_2 >> (uVar7 & 0x3f)) & (-1 << (ulong)(iVar8 + uVar3 & 0x1f) ^ 0xffffffffU);
  puVar1 = (ulong *)(param_8 + (long)(int)uVar2 * 8);
  if (lVar9 == param_4) {
    if (param_10 == (long *)0x0) {
      iVar8 = (int)(1L << ((ulong)uVar3 & 0x3f)) - uVar2;
      if ((int)param_5 <= iVar8) {
        iVar8 = (int)param_5;
      }
      uVar6 = arm_lpae_init_pte(param_1,param_3,param_6,param_7,iVar8,puVar1,param_9,1);
      if (param_13 == (long *)0x0) {
        return uVar6;
      }
      if ((int)uVar6 == 0) {
        *param_13 = *param_13 + iVar8 * param_4;
        return uVar6;
      }
      return uVar6;
    }
    if (param_7 == 3) {
      lVar9 = 1L << ((ulong)(uVar3 * 2 + 3) & 0x3f);
      if ((param_10[2] != 0) && (*(char *)(param_1 + 0x28) == '\0')) {
        lVar4 = (param_10[4] << 8) >> 8;
        uVar7 = lVar4 + 0x8000000000;
        lVar11 = uVar7 + _memstart_addr;
        if (uVar7 >> 0x26 != 0) {
          lVar11 = lVar4 - _kimage_voffset;
        }
        dma_sync_single_for_device
                  (*(undefined8 *)(param_1 + 0x38),lVar11,(ulong)*(uint *)(param_10 + 5) << 3,1);
      }
      param_10[2] = param_8;
      param_10[3] = param_9;
      *(int *)(param_10 + 1) = (int)param_4;
      param_10[4] = (long)puVar1;
      *(undefined4 *)(param_10 + 5) = 1;
      *param_10 = (-lVar9 & param_2) + lVar9;
    }
    else {
      if ((param_10[2] != 0) && (*(char *)(param_1 + 0x28) == '\0')) {
        lVar11 = (param_10[4] << 8) >> 8;
        uVar7 = lVar11 + 0x8000000000;
        lVar9 = uVar7 + _memstart_addr;
        if (uVar7 >> 0x26 != 0) {
          lVar9 = lVar11 - _kimage_voffset;
        }
        dma_sync_single_for_device
                  (*(undefined8 *)(param_1 + 0x38),lVar9,(ulong)*(uint *)(param_10 + 5) << 3,1);
      }
      param_10[4] = 0;
      param_10[5] = 0;
      param_10[2] = 0;
      param_10[3] = 0;
      *param_10 = 0;
      param_10[1] = 0;
    }
    uVar6 = arm_lpae_init_pte(param_1,param_3,param_6,param_7,1,puVar1,param_9,param_7 != 3);
    if (param_13 == (long *)0x0) {
      return uVar6;
    }
    if ((int)uVar6 == 0) {
      *param_13 = *param_13 + param_4;
      return uVar6;
    }
    return uVar6;
  }
  if (2 < param_7) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x107e64);
    (*pcVar5)();
  }
  uVar7 = *puVar1;
  if (uVar7 == 0) {
    local_68 = param_13;
    lVar11 = 8L << ((ulong)uVar3 & 0x3f);
    _raw_spin_unlock_irqrestore(param_1 + 0xc0,*param_12);
    uVar10 = __arm_lpae_alloc_pages(param_1,lVar11,param_11,param_1 + 0x10);
    uVar6 = _raw_spin_lock_irqsave(param_1 + 0xc0);
    *param_12 = uVar6;
    if (uVar10 == 0) {
      return 0xfffffff4;
    }
    uVar7 = arm_lpae_install_table(uVar10,puVar1,0,param_1 + 0x10,0,param_1);
    if (uVar7 == 0) {
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0xb8) + -4) != -0xc04e067) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x107d40);
        (*pcVar5)();
      }
      (*(code *)**(undefined8 **)(param_1 + 0xb8))
                (*(undefined8 *)(param_1 + 8),uVar10,-lVar9 & param_2,lVar9);
      goto LAB_00107e10;
    }
    if (*(char *)(param_1 + 0x28) == '\0') {
      lVar4 = (long)(uVar10 << 8) >> 8;
      uVar10 = lVar4 + 0x8000000000;
      lVar9 = _memstart_addr + uVar10;
      if (uVar10 >> 0x26 != 0) {
        lVar9 = lVar4 - _kimage_voffset;
      }
      dma_unmap_page_attrs(*(undefined8 *)(param_1 + 0x38),lVar9,lVar11,1,0);
    }
    else {
      uVar10 = ((long)(uVar10 << 8) >> 8) + 0x8000000000;
    }
    qcom_io_pgtable_free_page((uVar10 >> 0xc) * 0x40 + -0x200000000);
  }
  else if ((*(char *)(param_1 + 0x28) == '\0') && ((uVar7 >> 0x37 & 1) == 0)) {
    lVar11 = (long)puVar1 * 0x100 >> 8;
    uVar10 = lVar11 + 0x8000000000;
    lVar9 = _memstart_addr + uVar10;
    if (uVar10 >> 0x26 != 0) {
      lVar9 = lVar11 - _kimage_voffset;
    }
    dma_sync_single_for_device(*(undefined8 *)(param_1 + 0x38),lVar9,8,1);
  }
  if ((uVar7 & 3) == 1) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x107dd8);
    (*pcVar5)();
  }
  uVar10 = uVar7 & 0xfffffffff000;
  if (0xffff < (ulong)(8L << ((ulong)*(uint *)(param_1 + 0x98) & 0x3f))) {
    uVar10 = uVar7 & 0x7fffff0000;
  }
  uVar10 = uVar10 - _memstart_addr | 0xffffff8000000000;
  local_68 = param_13;
LAB_00107e10:
  uVar6 = __arm_lpae_map(param_1,param_2,param_3,param_4,param_5,param_6,param_7 + 1,uVar10,puVar1,
                         param_10,param_11,param_12,local_68);
  return uVar6;
}



//------------------------------------------------------------
// qcom_arm_lpae_map @ 00107e6c size=44
// signature: undefined qcom_arm_lpae_map(void)
// callers: []
//------------------------------------------------------------

void qcom_arm_lpae_map(void)

{
  qcom_arm_lpae_map_pages();
  return;
}



//------------------------------------------------------------
// qcom_arm_lpae_map_sg @ 00107e9c size=1040
// signature: undefined qcom_arm_lpae_map_sg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_arm_lpae_map_sg
              (long param_1,long param_2,ulong *param_3,uint param_4,uint param_5,undefined4 param_6
              ,long *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  int *piVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  uint uVar15;
  long lVar16;
  ulong uVar17;
  ulong uVar18;
  undefined8 local_b0;
  ulong local_a8 [3];
  ulong *local_90;
  long local_88;
  ulong local_80;
  ulong local_78;
  long local_70;
  
  lVar16 = sp_el0;
  local_70 = *(long *)(lVar16 + 0x638);
  local_88 = 0;
  local_80 = 0;
  local_a8[2] = 0;
  local_90 = (ulong *)0x0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  *param_7 = 0;
  local_b0 = _raw_spin_lock_irqsave();
  piVar7 = (int *)(param_1 + -0x68);
  uVar18 = 0;
  uVar15 = 0;
  uVar10 = 0;
  do {
    uVar14 = (ulong)(uint)param_3[1] +
             ((*param_3 & 0x3fffffffffffffc) + (_memstart_addr >> 0xc) * 0x40) * 0x40 + 0x8000000000
    ;
    if (uVar18 == 0) {
LAB_00108194:
      uVar18 = (ulong)*(uint *)((long)param_3 + 0xc);
    }
    else {
      if (uVar14 != uVar18 + uVar10) {
        uVar8 = *(undefined8 *)(param_1 + 0x38);
        lVar16 = *param_7;
        uVar17 = lVar16 + param_2;
        uVar2 = *(undefined4 *)(param_1 + 0x2c);
        local_78 = uVar10;
        uVar6 = arm_lpae_prot_to_pte(piVar7,param_5);
        uVar13 = (*(ulong *)(param_1 + -0x50) & 0xaaaaaaaaaaaaaaaa) >> 1 |
                 (*(ulong *)(param_1 + -0x50) & 0x5555555555555555) << 1;
        uVar13 = (uVar13 & 0xcccccccccccccccc) >> 2 | (uVar13 & 0x3333333333333333) << 2;
        uVar13 = (uVar13 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar13 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar13 = (uVar13 & 0xff00ff00ff00ff00) >> 8 | (uVar13 & 0xff00ff00ff00ff) << 8;
        uVar13 = (uVar13 & 0xffff0000ffff0000) >> 0x10 | (uVar13 & 0xffff0000ffff) << 0x10;
        if (((ulong)(uint)(1 << (ulong)((uint)LZCOUNT(uVar13 >> 0x20 | uVar13 << 0x20) & 0x1f)) - 1
            & (uVar18 | uVar10 | uVar17)) == 0) {
          if (((long)(uVar17 + (uVar18 - 1)) >> ((ulong)*(uint *)(param_1 + -0x48) & 0x3f) !=
               (*(long *)(param_1 + -0x58) << 0x3a) >> 0x3f) ||
             ((uVar18 - 1) + uVar10 >> ((ulong)*(uint *)(param_1 + -0x44) & 0x3f) != 0)) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x800,0x108284);
            (*pcVar4)();
          }
          if ((param_5 & 3) == 0) {
            *param_7 = lVar16 + uVar18;
          }
          else {
            do {
              uVar9 = uVar17 | uVar10;
              uVar13 = (uVar9 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar9 & 0x5555555555555555) << 1;
              uVar13 = (uVar13 & 0xcccccccccccccccc) >> 2 | (uVar13 & 0x3333333333333333) << 2;
              uVar13 = (uVar13 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar13 & 0xf0f0f0f0f0f0f0f) << 4;
              uVar13 = (uVar13 & 0xff00ff00ff00ff00) >> 8 | (uVar13 & 0xff00ff00ff00ff) << 8;
              uVar13 = (uVar13 & 0xffff0000ffff0000) >> 0x10 | (uVar13 & 0xffff0000ffff) << 0x10;
              uVar12 = LZCOUNT(uVar13 >> 0x20 | uVar13 << 0x20);
              uVar13 = LZCOUNT(uVar18) ^ 0x3fU;
              if ((uint)uVar12 <= (uint)(LZCOUNT(uVar18) ^ 0x3fU) && uVar9 != 0) {
                uVar13 = uVar12;
              }
              uVar13 = *(ulong *)(param_1 + -0x50) & (-2L << (uVar13 & 0x3f) ^ 0xffffffffffffffffU);
              if (uVar13 == 0) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1082b0);
                (*pcVar4)();
              }
              lVar16 = 1L << ((LZCOUNT(uVar13) ^ 0x3fU) & 0x3f);
              if ((local_a8[2] == 0) || (local_a8[0] <= uVar17)) {
                iVar5 = __arm_lpae_map(piVar7,uVar17,uVar10,lVar16,1,uVar6,uVar2,uVar8,0,local_a8,
                                       param_6,&local_b0,0);
                if (iVar5 != 0) goto LAB_001081c8;
              }
              else {
                iVar5 = *(int *)(param_1 + 0x30);
                if (*(int *)(param_1 + 0x2c) == 3) {
                  iVar11 = *(int *)(param_1 + 0x28) - iVar5;
                }
                else {
                  iVar11 = 0;
                }
                uVar13 = uVar17 >> ((ulong)(iVar5 + 3) & 0x3f) &
                         (long)~(-1 << (ulong)(iVar11 + iVar5 & 0x1f));
                if ((*(ulong *)(local_a8[2] + uVar13 * 8) & 1) != 0) {
                    /* WARNING: Does not return */
                  pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1081c8);
                  (*pcVar4)();
                }
                uVar9 = 3;
                if (*piVar7 == 5) {
                  uVar9 = 1;
                }
                *(ulong *)(local_a8[2] + uVar13 * 8) =
                     (uVar10 | uVar10 >> 0x24) & 0xfffffffff000 | uVar6 | uVar9;
                if (local_90 != (ulong *)0x0) {
                  uVar10 = *local_90;
                  uVar1 = ((uint)(uVar10 >> 0x2a) & 0x1c00 | (uint)uVar10 >> 2 & 0x3ff) + 1;
                  *local_90 = (ulong)(uVar1 * 4 & 0xffc) | (ulong)(uVar1 >> 10 & 7) << 0x34 |
                              uVar10 & 0xff8ffffffffff003;
                }
                local_80 = CONCAT44(local_80._4_4_,(int)local_80 + 1);
                uVar10 = local_78;
              }
              uVar10 = uVar10 + lVar16;
              uVar17 = lVar16 + uVar17;
              uVar18 = uVar18 - lVar16;
              *param_7 = *param_7 + lVar16;
              local_78 = uVar10;
            } while (uVar18 != 0);
          }
          goto LAB_00108194;
        }
        _printk(&DAT_0010ad31,uVar17,&local_78,uVar18);
        iVar5 = -0x16;
LAB_001081c8:
        _raw_spin_unlock_irqrestore(param_1 + 0x58,local_b0);
        goto LAB_00108240;
      }
      uVar18 = uVar18 + *(uint *)((long)param_3 + 0xc);
      uVar14 = uVar10;
    }
    uVar15 = uVar15 + 1;
    if (uVar15 < param_4) {
      param_3 = (ulong *)sg_next(param_3);
    }
    uVar10 = uVar14;
  } while (uVar15 <= param_4);
  _raw_spin_unlock_irqrestore(param_1 + 0x58,local_b0);
  if ((local_a8[2] != 0) && (*(char *)(param_1 + -0x40) == '\0')) {
    lVar3 = (local_88 << 8) >> 8;
    uVar18 = lVar3 + 0x8000000000;
    lVar16 = uVar18 + _memstart_addr;
    if (uVar18 >> 0x26 != 0) {
      lVar16 = lVar3 - _kimage_voffset;
    }
    dma_sync_single_for_device
              (*(undefined8 *)(param_1 + -0x30),lVar16,(local_80 & 0xffffffff) << 3,1);
  }
  DataSynchronizationBarrier(3,2,0);
  iVar5 = 0;
LAB_00108240:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qcom_arm_lpae_unmap_pages @ 001082b4 size=308
// signature: undefined qcom_arm_lpae_unmap_pages(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_arm_lpae_unmap_pages(long param_1,long param_2,ulong param_3,long param_4,undefined8 param_5)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if (((param_3 == 0) || (param_4 == 0)) || ((*(ulong *)(param_1 + -0x50) & param_3) != param_3)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1083a4);
    (*pcVar2)();
  }
  if (param_2 >> ((ulong)*(uint *)(param_1 + -0x48) & 0x3f) !=
      (*(long *)(param_1 + -0x58) << 0x3a) >> 0x3f) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1083e4);
    (*pcVar2)();
  }
  uVar3 = *(undefined8 *)(param_1 + 0x38);
  local_60 = _raw_spin_lock_irqsave(param_1 + 0x58);
  uVar3 = __arm_lpae_unmap(param_1 + -0x68,param_5,param_2,param_3,param_4,
                           *(undefined4 *)(param_1 + 0x2c),uVar3,&local_60);
  pcVar2 = *(code **)(*(long *)(param_1 + 0x48) + 8);
  if (*(int *)(pcVar2 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108388);
    (*pcVar2)();
  }
  (*pcVar2)(*(undefined8 *)(param_1 + -0x60));
  _raw_spin_unlock_irqrestore(param_1 + 0x58,local_60);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// __arm_lpae_unmap @ 001083ec size=1972
// signature: undefined __arm_lpae_unmap(void)
// callers: [qcom_arm_lpae_unmap_pages, qcom_arm_lpae_unmap, __arm_lpae_unmap]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __arm_lpae_unmap(int *param_1,long param_2,ulong param_3,long param_4,undefined8 param_5,
                     int param_6,long param_7,undefined8 param_8)

{
  ulong *puVar1;
  void *__s;
  uint uVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  uint uVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  
  if (param_6 == 4) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x108b90);
    (*pcVar6)();
  }
  uVar4 = param_1[0x26];
  uVar17 = (ulong)uVar4;
  uVar9 = (ulong)(uVar4 * (4 - param_6) + 3);
  if (param_1[0x25] == param_6) {
    iVar11 = param_1[0x24] - uVar4;
  }
  else {
    iVar11 = 0;
  }
  uVar2 = (uint)(param_3 >> (uVar9 & 0x3f)) & (-1 << (ulong)(iVar11 + uVar4 & 0x1f) ^ 0xffffffffU);
  puVar1 = (ulong *)(param_7 + (long)(int)uVar2 * 8);
  uVar12 = *puVar1;
  if (uVar12 == 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x108b9c);
    (*pcVar6)();
  }
  uVar15 = 1L << (uVar17 & 0x3f);
  uVar16 = (uint)param_5;
  iVar11 = (int)uVar15;
  if (1L << (uVar9 & 0x3f) == param_4) {
    uVar14 = iVar11 - uVar2;
    if ((int)uVar16 <= (int)(iVar11 - uVar2)) {
      uVar14 = uVar16;
    }
    if ((int)uVar14 < 1) {
      uVar14 = 0;
    }
    else {
      lVar19 = 0;
      lVar20 = (long)(int)uVar2 * 0x800 + param_7 * 0x100;
      do {
        uVar17 = puVar1[lVar19];
        if (uVar17 == 0) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x108b58);
          (*pcVar6)();
        }
        puVar1[lVar19] = 0;
        if ((char)param_1[10] == '\0') {
          uVar9 = (lVar20 >> 8) + 0x8000000000;
          lVar18 = _memstart_addr + uVar9;
          if (uVar9 >> 0x26 != 0) {
            lVar18 = (lVar20 >> 8) - _kimage_voffset;
          }
          dma_sync_single_for_device(*(undefined8 *)(param_1 + 0xe),lVar18,8,1);
        }
        uVar9 = 3;
        if (*param_1 == 5 || param_6 != 3) {
          uVar9 = 1;
        }
        if ((uVar17 & 3) == uVar9) {
          if ((param_2 == 0) || (*(char *)(param_2 + 0x28) == '\0')) {
            DataMemoryBarrier(2,2);
          }
        }
        else {
          uVar9 = uVar17 & 0xfffffffff000;
          if (0xffff < (ulong)(8L << ((ulong)(uint)param_1[0x26] & 0x3f))) {
            uVar9 = (uVar17 & 0xfffffffff000) * 0x1000000001 & 0x7fffff0000;
          }
          __arm_lpae_free_pgtable(param_1,param_6 + 1,uVar9 - _memstart_addr | 0xffffff8000000000,1)
          ;
        }
        lVar19 = lVar19 + 1;
        lVar20 = lVar20 + 0x800;
      } while (uVar14 != (uint)lVar19);
    }
  }
  else {
    if ((param_6 != 2) || ((uVar12 & 3) == 1)) {
      uVar9 = 3;
      if (*param_1 == 5 || param_6 != 3) {
        uVar9 = 1;
      }
      if ((uVar12 & 3) == uVar9) {
        iVar7 = param_6 + 1;
        if (iVar7 == 4) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x108ba8);
          (*pcVar6)();
        }
        lVar19 = 8L << (uVar17 & 0x3f);
        uVar17 = __arm_lpae_alloc_pages(param_1,lVar19,0xa20);
        if (uVar17 == 0) {
          return 0;
        }
        lVar20 = 1L << ((ulong)(uVar4 * (3 - param_6) + 3) & 0x3f);
        if (lVar20 == param_4) {
          iVar5 = param_1[0x26];
          if (param_1[0x25] == iVar7) {
            iVar10 = param_1[0x24] - iVar5;
          }
          else {
            iVar10 = 0;
          }
          uVar4 = (uint)(param_3 >> ((ulong)(iVar5 * (3 - param_6) + 3) & 0x3f)) &
                  (-1 << (ulong)(iVar10 + iVar5 & 0x1f) ^ 0xffffffffU);
          uVar2 = iVar11 - uVar4;
          if ((int)uVar16 <= (int)(iVar11 - uVar4)) {
            uVar2 = uVar16;
          }
        }
        else {
          uVar2 = 0;
          uVar4 = 0xffffffff;
        }
        if (iVar11 < 1) {
          iVar11 = 0;
        }
        else {
          uVar9 = 0;
          iVar11 = 0;
          uVar8 = uVar12 & 0xfffffffff000;
          lVar18 = uVar17 << 8;
          if (0xffff < (ulong)(8L << ((ulong)(uint)param_1[0x26] & 0x3f))) {
            uVar8 = (uVar8 | (uVar8 >> 0xc) << 0x30) & 0xfffffffff0000;
          }
          do {
            uVar13 = 3;
            if (((long)uVar9 < (long)(int)uVar4) || ((long)(int)(uVar2 + uVar4) <= (long)uVar9)) {
              if (*param_1 == 5 || iVar7 != 3) {
                uVar13 = 1;
              }
              *(ulong *)(uVar17 + uVar9 * 8) =
                   uVar13 | uVar12 & 0x60000000000ffc | (uVar8 | uVar8 >> 0x24) & 0xfffffffff000;
              if ((char)param_1[10] == '\0') {
                uVar13 = (lVar18 >> 8) + 0x8000000000;
                lVar3 = _memstart_addr + uVar13;
                if (uVar13 >> 0x26 != 0) {
                  lVar3 = (lVar18 >> 8) - _kimage_voffset;
                }
                dma_sync_single_for_device(*(undefined8 *)(param_1 + 0xe),lVar3,8,1);
              }
              iVar11 = iVar11 + 1;
            }
            uVar9 = uVar9 + 1;
            uVar8 = uVar8 + lVar20;
            lVar18 = lVar18 + 0x800;
          } while ((uVar15 & 0xffffffff) != uVar9);
        }
        uVar9 = arm_lpae_install_table(uVar17,puVar1,uVar12,param_1 + 4,iVar11,param_1);
        if (uVar9 == uVar12) {
          if (-1 < (int)uVar4) {
            if (*(int *)((code *)**(undefined8 **)(param_1 + 0x2e) + -4) != -0xc04e067) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x108a4c);
              (*pcVar6)();
            }
            (*(code *)**(undefined8 **)(param_1 + 0x2e))
                      (*(undefined8 *)(param_1 + 2),uVar17,
                       0xdeaU - (1L << ((ulong)(param_1[0x26] * (2 - param_6) + 3) & 0x3f)) &
                       param_3);
            return (int)uVar2 * param_4;
          }
        }
        else {
          if ((char)param_1[10] == '\0') {
            lVar18 = (long)(uVar17 << 8) >> 8;
            uVar17 = lVar18 + 0x8000000000;
            lVar20 = _memstart_addr + uVar17;
            if (uVar17 >> 0x26 != 0) {
              lVar20 = lVar18 - _kimage_voffset;
            }
            dma_unmap_page_attrs(*(undefined8 *)(param_1 + 0xe),lVar20,lVar19,1,0);
          }
          else {
            uVar17 = ((long)(uVar17 << 8) >> 8) + 0x8000000000;
          }
          qcom_io_pgtable_free_page((uVar17 >> 0xc) * 0x40 + -0x200000000);
          if ((~(uint)uVar9 & 3) != 0) {
            return 0;
          }
          uVar17 = uVar9 & 0xfffffffff000;
          if (0xffff < (ulong)(8L << ((ulong)(uint)param_1[0x26] & 0x3f))) {
            uVar17 = uVar9 & 0x7fffff0000;
          }
          uVar17 = uVar17 - _memstart_addr | 0xffffff8000000000;
        }
      }
      else {
        uVar9 = uVar12 & 0xfffffffff000;
        if (0xffff < (ulong)(8L << (uVar17 & 0x3f))) {
          uVar9 = uVar12 & 0x7fffff0000;
        }
        uVar17 = uVar9 - _memstart_addr | 0xffffff8000000000;
      }
      lVar19 = __arm_lpae_unmap(param_1,param_2,param_3,param_4,param_5,param_6 + 1,uVar17,param_8);
      return lVar19;
    }
    uVar9 = uVar12 & 0xfffffffff000;
    if (0xffff < (ulong)(8L << (uVar17 & 0x3f))) {
      uVar9 = uVar12 & 0x7fffff0000;
    }
    uVar17 = uVar9 - _memstart_addr | 0xffffff8000000000;
    if (param_1[0x25] == 3) {
      iVar7 = param_1[0x24] - uVar4;
    }
    else {
      iVar7 = 0;
    }
    uVar4 = (uint)(param_3 >> ((ulong)(uVar4 + 3) & 0x3f)) &
            (-1 << (ulong)(iVar7 + uVar4 & 0x1f) ^ 0xffffffffU);
    uVar14 = iVar11 - uVar4;
    __s = (void *)(uVar17 + (long)(int)uVar4 * 8);
    if ((int)uVar16 <= (int)uVar14) {
      uVar14 = uVar16;
    }
    if (0 < (int)uVar14) {
      memset(__s,0,(ulong)uVar14 << 3);
    }
    if ((char)param_1[10] == '\0') {
      lVar19 = _memstart_addr + (long)__s + 0x8000000000U;
      if ((long)__s + 0x8000000000U >> 0x26 != 0) {
        lVar19 = (long)__s - _kimage_voffset;
      }
      dma_sync_single_for_device
                (*(undefined8 *)(param_1 + 0xe),lVar19,
                 -(ulong)(uVar14 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar14 << 3,1);
    }
    uVar9 = *puVar1;
    uVar4 = ((uint)(uVar9 >> 0x2a) & 0x1c00 | (uint)uVar9 >> 2 & 0x3ff) - uVar14;
    *puVar1 = (ulong)(uVar4 * 4 & 0xffc) | (ulong)(uVar4 >> 10 & 7) << 0x34 |
              uVar9 & 0xff8ffffffffff003;
    if ((uVar4 & 0x1fff) == 0) {
      iVar11 = param_1[0x26];
      *puVar1 = 0;
      lVar19 = 1L << ((ulong)(iVar11 * 2 + 3) & 0x3f);
      if ((char)param_1[10] == '\0') {
        lVar18 = (long)puVar1 * 0x100 >> 8;
        uVar9 = lVar18 + 0x8000000000;
        lVar20 = _memstart_addr + uVar9;
        if (uVar9 >> 0x26 != 0) {
          lVar20 = lVar18 - _kimage_voffset;
        }
        dma_sync_single_for_device(*(undefined8 *)(param_1 + 0xe),lVar20,8,1);
      }
      __arm_lpae_free_pgtable(param_1,3,uVar17,1);
      if (*(int *)(*(code **)(*(long *)(param_1 + 0x2e) + 8) + -4) != -0xc04e067) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x108818);
        (*pcVar6)();
      }
      (**(code **)(*(long *)(param_1 + 0x2e) + 8))
                (*(undefined8 *)(param_1 + 2),uVar17,-lVar19 & param_3,lVar19);
    }
  }
  return (int)uVar14 * param_4;
}



//------------------------------------------------------------
// qcom_arm_lpae_unmap @ 00108bb0 size=296
// signature: undefined qcom_arm_lpae_unmap(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_arm_lpae_unmap(long param_1,long param_2,ulong param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if ((param_3 == 0) || ((param_3 & (*(ulong *)(param_1 + -0x50) ^ 0xffffffffffffffff)) != 0)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x108c94);
    (*pcVar2)();
  }
  if (param_2 >> ((ulong)*(uint *)(param_1 + -0x48) & 0x3f) !=
      (*(long *)(param_1 + -0x58) << 0x3a) >> 0x3f) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x108cd4);
    (*pcVar2)();
  }
  uVar3 = *(undefined8 *)(param_1 + 0x38);
  local_60 = _raw_spin_lock_irqsave(param_1 + 0x58);
  uVar3 = __arm_lpae_unmap(param_1 + -0x68,param_4,param_2,param_3,1,*(undefined4 *)(param_1 + 0x2c)
                           ,uVar3,&local_60);
  pcVar2 = *(code **)(*(long *)(param_1 + 0x48) + 8);
  if (*(int *)(pcVar2 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108c78);
    (*pcVar2)();
  }
  (*pcVar2)(*(undefined8 *)(param_1 + -0x60));
  _raw_spin_unlock_irqrestore(param_1 + 0x58,local_60);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// arm_64_lpae_alloc_pgtable_s1 @ 00108ce0 size=580
// signature: undefined arm_64_lpae_alloc_pgtable_s1(void)
// callers: [qcom_alloc_io_pgtable_ops, arm_32_lpae_alloc_pgtable_s1]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long arm_64_lpae_alloc_pgtable_s1(ulong *param_1)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  long lVar7;
  
  if ((*param_1 & 0xffffffff3fffff9e) != 0) {
    return 0;
  }
  lVar3 = arm_lpae_alloc_pgtable();
  if (lVar3 == 0) {
    return 0;
  }
  uVar4 = (uint)param_1[7];
  if ((char)param_1[3] == '\0') {
    uVar6 = *param_1;
    if (((uint)uVar6 >> 6 & 1) == 0) {
      if ((int)(uint)uVar6 < 0) {
        uVar4 = uVar4 & 0xfffff99f | 0x1c0;
      }
      else {
        uVar4 = uVar4 & 0xfffff81f | 0x40;
      }
    }
    else {
      uVar4 = uVar4 & 0xfffff81f | 0xc0;
    }
    *(uint *)(param_1 + 7) = uVar4;
  }
  else {
    uVar6 = *param_1;
    uVar5 = uVar4 | 0x260;
    if ((uVar6 & 0x40000000) != 0) {
      uVar5 = uVar4 & 0xfffff81f | 0x60;
    }
    uVar4 = uVar5 & 0xfffffa7f | 0x80;
    *(uint *)(param_1 + 7) = uVar4;
    if ((uVar6 & 0x80000040) != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x108d78);
      (*pcVar2)();
    }
  }
  uVar6 = uVar6 & 0x20;
  lVar7 = 8L << ((ulong)*(uint *)(lVar3 + 0x98) & 0x3f);
  if (lVar7 == 0x10000) {
    uVar5 = 8;
    if (uVar6 != 0) {
      uVar5 = 0x18;
    }
LAB_00108e08:
    uVar4 = uVar4 & 0xffffffe7 | uVar5;
    *(uint *)(param_1 + 7) = uVar4;
  }
  else {
    if (lVar7 == 0x4000) {
      uVar5 = 0x10;
      if (uVar6 != 0) {
        uVar5 = 8;
      }
      goto LAB_00108e08;
    }
    if (lVar7 == 0x1000) {
      uVar5 = (uint)(uVar6 >> 1);
      goto LAB_00108e08;
    }
  }
  switch(CONCAT44(*(int *)((long)param_1 + 0x14),*(int *)((long)param_1 + 0x14) + -0x20) >> 1 &
         0xffffffff) {
  case 0:
    uVar4 = uVar4 & 0xfffffff8;
    break;
  default:
    goto switchD_00108e3c_caseD_1;
  case 2:
    uVar4 = uVar4 & 0xfffffff8 | 1;
    break;
  case 4:
    uVar4 = uVar4 & 0xfffffff8 | 2;
    break;
  case 5:
    uVar4 = uVar4 & 0xfffffff8 | 3;
    break;
  case 6:
    uVar4 = uVar4 & 0xfffffff8 | 4;
    break;
  case 8:
    uVar4 = uVar4 & 0xfffffff8 | 5;
    break;
  case 10:
    uVar4 = uVar4 & 0xfffffff8 | 6;
  }
  *(uint *)(param_1 + 7) =
       uVar4 & 0xfffe0000 | uVar4 & 0x7ff | ((uint)((int)param_1[2] * -0x800) >> 0xb & 0x3f) << 0xb;
  param_1[8] = 0xefe4f404ff44;
  lVar7 = __arm_lpae_alloc_pages(lVar3,8L << ((ulong)*(uint *)(lVar3 + 0x90) & 0x3f),0xcc0,param_1);
  *(long *)(lVar3 + 0xa0) = lVar7;
  if (lVar7 != 0) {
    DataSynchronizationBarrier(3,2,0);
    lVar7 = (*(long *)(lVar3 + 0xa0) << 8) >> 8;
    uVar6 = lVar7 + 0x8000000000;
    uVar1 = uVar6 + _memstart_addr;
    if (uVar6 >> 0x26 != 0) {
      uVar1 = lVar7 - _kimage_voffset;
    }
    param_1[6] = uVar1;
    return lVar3;
  }
switchD_00108e3c_caseD_1:
  qcom_io_pgtable_allocator_unregister(*(undefined4 *)(lVar3 + 0xa8));
  kfree(lVar3);
  return 0;
}



//------------------------------------------------------------
// arm_lpae_free_pgtable @ 00108f2c size=68
// signature: undefined arm_lpae_free_pgtable(void)
// callers: [qcom_free_io_pgtable_ops]
//------------------------------------------------------------

void arm_lpae_free_pgtable(long param_1)

{
  __arm_lpae_free_pgtable(param_1,*(undefined4 *)(param_1 + 0x94),*(undefined8 *)(param_1 + 0xa0),0)
  ;
  qcom_io_pgtable_allocator_unregister(*(undefined4 *)(param_1 + 0xa8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// arm_64_lpae_alloc_pgtable_s2 @ 00108f74 size=500
// signature: undefined arm_64_lpae_alloc_pgtable_s2(void)
// callers: [arm_32_lpae_alloc_pgtable_s2]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long arm_64_lpae_alloc_pgtable_s2(long *param_1)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  
  if (*param_1 != 0) {
    return 0;
  }
  lVar4 = arm_lpae_alloc_pgtable();
  if (lVar4 == 0) {
    return 0;
  }
  if ((*(int *)(lVar4 + 0x94) == 0) &&
     ((ulong)(8L << ((ulong)*(uint *)(lVar4 + 0x90) & 0x3f)) < 0x88)) {
    *(uint *)(lVar4 + 0x90) = *(int *)(lVar4 + 0x98) + *(uint *)(lVar4 + 0x90);
    *(undefined4 *)(lVar4 + 0x94) = 1;
  }
  uVar2 = *(uint *)(param_1 + 7);
  uVar5 = 0x40;
  if ((char)param_1[3] != '\0') {
    uVar5 = 0x2e0;
  }
  uVar7 = uVar2 & 0xfffff81f | uVar5;
  *(uint *)(param_1 + 7) = uVar7;
  uVar6 = *(uint *)(lVar4 + 0x94);
  lVar8 = 8L << ((ulong)*(uint *)(lVar4 + 0x98) & 0x3f);
  if (lVar8 == 0x10000) {
    uVar7 = uVar2 & 0xfffff807 | uVar5 | 8;
LAB_00109054:
    *(uint *)(param_1 + 7) = uVar7;
  }
  else {
    if (lVar8 == 0x4000) {
      uVar7 = uVar2 & 0xfffff807 | uVar5 | 0x10;
      goto LAB_00109054;
    }
    if (lVar8 == 0x1000) {
      uVar6 = uVar6 + 1;
      uVar7 = uVar2 & 0xfffff807 | uVar5;
      goto LAB_00109054;
    }
  }
  switch(CONCAT44(*(int *)((long)param_1 + 0x14),*(int *)((long)param_1 + 0x14) + -0x20) >> 1 &
         0xffffffff) {
  case 0:
    uVar7 = uVar7 & 0xfffffff8;
    break;
  default:
    goto switchD_00109080_caseD_1;
  case 2:
    uVar7 = uVar7 & 0xfffffff8 | 1;
    break;
  case 4:
    uVar7 = uVar7 & 0xfffffff8 | 2;
    break;
  case 5:
    uVar7 = uVar7 & 0xfffffff8 | 3;
    break;
  case 6:
    uVar7 = uVar7 & 0xfffffff8 | 4;
    break;
  case 8:
    uVar7 = uVar7 & 0xfffffff8 | 5;
    break;
  case 10:
    uVar7 = uVar7 & 0xfffffff8 | 6;
  }
  *(uint *)(param_1 + 7) =
       ((int)param_1[2] * -0x2000 & 0x7e000U | (uVar6 & 3) << 0xb | uVar7 & 0xfff807ff) ^ 0x1800;
  lVar8 = __arm_lpae_alloc_pages(lVar4,8L << ((ulong)*(uint *)(lVar4 + 0x90) & 0x3f),0xcc0,param_1);
  *(long *)(lVar4 + 0xa0) = lVar8;
  if (lVar8 != 0) {
    DataSynchronizationBarrier(3,2,0);
    lVar3 = (*(long *)(lVar4 + 0xa0) << 8) >> 8;
    uVar1 = lVar3 + 0x8000000000;
    lVar8 = uVar1 + _memstart_addr;
    if (uVar1 >> 0x26 != 0) {
      lVar8 = lVar3 - _kimage_voffset;
    }
    param_1[6] = lVar8;
    return lVar4;
  }
switchD_00109080_caseD_1:
  qcom_io_pgtable_allocator_unregister(*(undefined4 *)(lVar4 + 0xa8));
  kfree(lVar4);
  return 0;
}



//------------------------------------------------------------
// arm_32_lpae_alloc_pgtable_s1 @ 0010916c size=80
// signature: undefined arm_32_lpae_alloc_pgtable_s1(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_32_lpae_alloc_pgtable_s1(long param_1)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 0x10) < 0x21) && (*(uint *)(param_1 + 0x14) < 0x29)) {
    *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) & 0x40201000;
    uVar1 = arm_64_lpae_alloc_pgtable_s1();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// arm_32_lpae_alloc_pgtable_s2 @ 001091c0 size=80
// signature: undefined arm_32_lpae_alloc_pgtable_s2(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_32_lpae_alloc_pgtable_s2(long param_1)

{
  undefined8 uVar1;
  
  if ((*(uint *)(param_1 + 0x10) < 0x29) && (*(uint *)(param_1 + 0x14) < 0x29)) {
    *(ulong *)(param_1 + 8) = *(ulong *)(param_1 + 8) & 0x40201000;
    uVar1 = arm_64_lpae_alloc_pgtable_s2();
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// arm_mali_lpae_alloc_pgtable @ 00109214 size=260
// signature: undefined arm_mali_lpae_alloc_pgtable(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long arm_mali_lpae_alloc_pgtable(long *param_1)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  if (((*param_1 == 0) && (*(uint *)(param_1 + 2) < 0x31)) &&
     (*(uint *)((long)param_1 + 0x14) < 0x29)) {
    param_1[1] = param_1[1] & 0x40201000;
    lVar3 = arm_lpae_alloc_pgtable(param_1);
    if (lVar3 == 0) {
      return 0;
    }
    if (0 < *(int *)(lVar3 + 0x94)) {
      *(undefined8 *)(lVar3 + 0x90) = 0;
    }
    param_1[7] = 0x888d88;
    lVar4 = __arm_lpae_alloc_pages
                      (lVar3,8L << ((ulong)*(uint *)(lVar3 + 0x90) & 0x3f),0xcc0,param_1);
    *(long *)(lVar3 + 0xa0) = lVar4;
    if (lVar4 != 0) {
      DataSynchronizationBarrier(3,2,0);
      lVar4 = (*(long *)(lVar3 + 0xa0) << 8) >> 8;
      uVar1 = lVar4 + 0x8000000000;
      uVar2 = uVar1 + _memstart_addr;
      if (uVar1 >> 0x26 != 0) {
        uVar2 = lVar4 - _kimage_voffset;
      }
      param_1[6] = uVar2 | 7;
      return lVar3;
    }
    qcom_io_pgtable_allocator_unregister(*(undefined4 *)(lVar3 + 0xa8));
    kfree(lVar3);
  }
  return 0;
}



//------------------------------------------------------------
// arm_lpae_init_pte @ 00109318 size=420
// signature: undefined arm_lpae_init_pte(void)
// callers: [__arm_lpae_map]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
arm_lpae_init_pte(int *param_1,long param_2,ulong param_3,int param_4,uint param_5,byte *param_6,
                 ulong *param_7,uint param_8)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  ulong uVar7;
  byte *pbVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  
  uVar6 = (ulong)param_5;
  if (0 < (int)param_5) {
    uVar9 = uVar6;
    pbVar8 = param_6;
    do {
      if ((*pbVar8 & 1) != 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1093a4);
        (*pcVar5)();
      }
      pbVar8 = pbVar8 + 8;
      uVar9 = uVar9 - 1;
    } while (uVar9 != 0);
  }
  uVar9 = 3;
  if (*param_1 == 5 || param_4 != 3) {
    uVar9 = 1;
  }
  if (0 < (int)param_5) {
    uVar9 = uVar9 | param_3;
    uVar7 = (ulong)(param_1[0x26] * (4 - param_4) + 3);
    if (param_5 == 1) {
      uVar10 = 0;
    }
    else {
      uVar11 = 0;
      uVar10 = uVar6 & 0xfffffffe;
      do {
        uVar2 = (uVar11 << (uVar7 & 0x3f)) + param_2;
        uVar3 = (uVar11 + 1 << (uVar7 & 0x3f)) + param_2;
        lVar1 = uVar11 * 8;
        uVar11 = uVar11 + 2;
        *(ulong *)(param_6 + lVar1) = uVar9 | (uVar2 | uVar2 >> 0x24) & 0xfffffffff000;
        *(ulong *)((long)(param_6 + lVar1) + 8) = uVar9 | (uVar3 | uVar3 >> 0x24) & 0xfffffffff000;
      } while (uVar11 != uVar10);
      if (uVar10 == uVar6) goto LAB_0010941c;
    }
    do {
      uVar11 = (uVar10 << (uVar7 & 0x3f)) + param_2;
      *(ulong *)(param_6 + uVar10 * 8) = uVar9 | (uVar11 | uVar11 >> 0x24) & 0xfffffffff000;
      uVar10 = uVar10 + 1;
    } while (uVar6 != uVar10);
  }
LAB_0010941c:
  if (((param_8 & 1) != 0) && ((char)param_1[10] == '\0')) {
    lVar4 = ((long)param_6 << 8) >> 8;
    uVar6 = lVar4 + 0x8000000000;
    lVar1 = _memstart_addr + uVar6;
    if (uVar6 >> 0x26 != 0) {
      lVar1 = lVar4 - _kimage_voffset;
    }
    dma_sync_single_for_device
              (*(undefined8 *)(param_1 + 0xe),lVar1,
               -(ulong)(param_5 >> 0x1f) & 0xfffffff800000000 | (ulong)param_5 << 3,1);
  }
  if (param_7 != (ulong *)0x0) {
    uVar6 = *param_7;
    param_5 = ((uint)(uVar6 >> 0x2a) & 0x1c00 | (uint)uVar6 >> 2 & 0x3ff) + param_5;
    *param_7 = (ulong)(param_5 * 4 & 0xffc) | (ulong)(param_5 >> 10 & 7) << 0x34 |
               uVar6 & 0xff8ffffffffff003;
  }
  return 0;
}



//------------------------------------------------------------
// __arm_lpae_alloc_pages @ 001094c0 size=360
// signature: undefined __arm_lpae_alloc_pages(void)
// callers: [__arm_lpae_map, __arm_lpae_unmap, arm_64_lpae_alloc_pgtable_s1, arm_64_lpae_alloc_pgtable_s2, arm_mali_lpae_alloc_pgtable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong __arm_lpae_alloc_pages(long param_1,undefined8 param_2,uint param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  
  plVar8 = *(long **)(param_4 + 0x28);
  uVar3 = qcom_io_pgtable_alloc_page(*(undefined4 *)(param_1 + 0xa8),param_3 | 0x100);
  if (uVar3 != 0) {
    uVar9 = (uVar3 & 0x3ffffffffffc0) << 6 | 0xff00000000000000;
    if (*(char *)(param_4 + 0x18) != '\0') {
      return uVar9;
    }
    uVar4 = is_vmalloc_addr(uVar9);
    if (((uVar4 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
      dma_map_single_attrs___already_done = 1;
      uVar6 = dev_driver_string(plVar8);
      lVar7 = plVar8[0xe];
      if (lVar7 == 0) {
        lVar7 = *plVar8;
      }
      __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar6,lVar7);
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x109630);
      (*pcVar2)();
    }
    if ((uVar4 & 1) == 0) {
      lVar7 = (long)((uVar3 & 0x3ffffffffffc0) << 0xe) >> 8;
      uVar4 = lVar7 + 0x8000000000;
      lVar5 = dma_map_page_attrs(plVar8,(uVar4 >> 0xc) * 0x40 + -0x200000000,0,param_2,1,0);
      if (lVar5 != -1) {
        lVar1 = _memstart_addr + uVar4;
        if (uVar4 >> 0x26 != 0) {
          lVar1 = lVar7 - _kimage_voffset;
        }
        if (lVar5 == lVar1) {
          return uVar9;
        }
        _dev_err(plVar8,"Cannot accommodate DMA translation for IOMMU page tables\n");
        dma_unmap_page_attrs(plVar8,lVar5,param_2,1,0);
      }
    }
    qcom_io_pgtable_free_page(uVar3);
  }
  return 0;
}



//------------------------------------------------------------
// arm_lpae_install_table @ 00109638 size=372
// signature: undefined arm_lpae_install_table(void)
// callers: [__arm_lpae_map, __arm_lpae_unmap]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong arm_lpae_install_table
                (long param_1,ulong *param_2,ulong param_3,ulong *param_4,uint param_5,long param_6,
                undefined8 *param_7)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  code *pcVar7;
  ulong uVar8;
  ulong uVar9;
  
  _raw_spin_unlock_irqrestore(param_6 + 0xc0,*param_7);
  pcVar7 = *(code **)(*(long *)(param_6 + 0xb0) + 0x10);
  if (*(int *)(pcVar7 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1096a4);
    (*pcVar7)();
  }
  (*pcVar7)(*(undefined8 *)(param_6 + 8));
  uVar6 = _raw_spin_lock_irqsave(param_6 + 0xc0);
  lVar2 = (param_1 << 8) >> 8;
  *param_7 = uVar6;
  uVar8 = lVar2 + 0x8000000000;
  DataMemoryBarrier(0,2);
  uVar9 = _memstart_addr + uVar8;
  if (uVar8 >> 0x26 != 0) {
    uVar9 = lVar2 - _kimage_voffset;
  }
  uVar8 = 3;
  if ((*param_4 & 1) != 0) {
    uVar8 = 0x8000000000000003;
  }
  uVar8 = uVar9 & 0xff8ffffffffff000 |
          uVar8 | (ulong)((param_5 & 0x3ff) << 2) | (ulong)(param_5 >> 10 & 7) << 0x34;
  Hint_Prefetch(param_2,2,0,1);
  do {
    uVar9 = *param_2;
    if (uVar9 != param_3) break;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(param_2,0x10);
    if (bVar5) {
      *param_2 = uVar8;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (((char)param_4[3] == '\0') && ((uVar9 >> 0x37 & 1) == 0)) {
    lVar3 = ((long)param_2 << 8) >> 8;
    uVar1 = lVar3 + 0x8000000000;
    lVar2 = _memstart_addr + uVar1;
    if (uVar1 >> 0x26 != 0) {
      lVar2 = lVar3 - _kimage_voffset;
    }
    dma_sync_single_for_device(param_4[5],lVar2,8,1);
    if (uVar9 == param_3) {
      *param_2 = uVar8 | 0x80000000000000;
    }
  }
  return uVar9;
}



//------------------------------------------------------------
// __arm_lpae_free_pgtable @ 001097d0 size=500
// signature: undefined __arm_lpae_free_pgtable(void)
// callers: [__arm_lpae_free_pgtable, __arm_lpae_unmap, arm_lpae_free_pgtable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __arm_lpae_free_pgtable(int *param_1,int param_2,ulong *param_3,uint param_4)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong *puVar7;
  long lVar8;
  
  lVar8 = 0x90;
  if (param_1[0x25] != param_2) {
    lVar8 = 0x98;
  }
  lVar4 = 8L << ((ulong)*(uint *)((long)param_1 + lVar8) & 0x3f);
  lVar8 = 0;
  if (param_2 != 3) {
    lVar8 = lVar4;
  }
  uVar5 = *(undefined8 *)(param_1 + 2);
  if (lVar8 != 0) {
    puVar7 = param_3;
    do {
      uVar6 = *puVar7;
      if (uVar6 != 0) {
        uVar1 = 3;
        if (*param_1 == 5 || param_2 != 3) {
          uVar1 = 1;
        }
        if ((uVar6 & 3) != uVar1) {
          uVar1 = uVar6 & 0xfffffffff000;
          if (0xffff < (ulong)(8L << ((ulong)(uint)param_1[0x26] & 0x3f))) {
            uVar1 = uVar6 & 0x7fffff0000;
          }
          __arm_lpae_free_pgtable
                    (param_1,param_2 + 1,uVar1 - _memstart_addr | 0xffffff8000000000,param_4 & 1);
        }
      }
      lVar8 = lVar8 + -8;
      puVar7 = puVar7 + 1;
    } while (lVar8 != 0);
  }
  if ((char)param_1[10] == '\0') {
    lVar2 = ((long)param_3 << 8) >> 8;
    uVar6 = lVar2 + 0x8000000000;
    lVar8 = _memstart_addr + uVar6;
    if (uVar6 >> 0x26 != 0) {
      lVar8 = lVar2 - _kimage_voffset;
    }
    dma_unmap_page_attrs(*(undefined8 *)(param_1 + 0xe),lVar8,lVar4,1,0);
  }
  if ((param_4 & 1) == 0) {
    qcom_io_pgtable_free_page
              (((((long)param_3 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x200000000);
  }
  else {
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x2c) + -4) != -0x2d4a22e1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1098ec);
      (*pcVar3)();
    }
    (*(code *)**(undefined8 **)(param_1 + 0x2c))(uVar5,param_3);
  }
  if (*(int *)(*(code **)(*(long *)(param_1 + 0x2e) + 8) + -4) != -0xc04e067) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10999c);
    (*pcVar3)();
  }
  (**(code **)(*(long *)(param_1 + 0x2e) + 8))
            (*(undefined8 *)(param_1 + 2),param_3,0,
             1L << ((ulong)(param_1[0x26] * (5 - param_2) + 3) & 0x3f));
  return;
}



//------------------------------------------------------------
// arm_lpae_alloc_pgtable @ 001099c4 size=404
// signature: undefined arm_lpae_alloc_pgtable(void)
// callers: [arm_64_lpae_alloc_pgtable_s1, arm_64_lpae_alloc_pgtable_s2, arm_mali_lpae_alloc_pgtable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long arm_lpae_alloc_pgtable(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  ulong uVar13;
  long lVar14;
  
  uVar10 = *(ulong *)(param_1 + 8);
  uVar11 = 0x40201000;
  if (((uint)uVar10 >> 0xc & 1) == 0) {
    if ((uVar10 & 0xfff) == 0) {
      if ((uVar10 & 0xfffffffffffff000) != 0) {
        uVar13 = (uVar10 & 0xaaaaaaaaaaaaa000) >> 1 | (uVar10 & 0x5555555555555000) << 1;
        uVar13 = (uVar13 & 0xcccccccccccccccc) >> 2 | (uVar13 & 0x3333333333333333) << 2;
        uVar13 = (uVar13 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar13 & 0xf0f0f0f0f0f0f0f) << 4;
        uVar13 = (uVar13 & 0xff00ff00ff00ff00) >> 8 | (uVar13 & 0xff00ff00ff00ff) << 8;
        uVar13 = (uVar13 & 0xffff0000ffff0000) >> 0x10 | (uVar13 & 0xffff0000ffff) << 0x10;
        uVar13 = LZCOUNT(uVar13 >> 0x20 | uVar13 << 0x20);
        goto LAB_00109a0c;
      }
    }
    else {
      uVar13 = LZCOUNT(uVar10 & 0xfff) ^ 0x3f;
LAB_00109a0c:
      lVar14 = 1L << (uVar13 & 0x3f);
      if (lVar14 == 0x1000) goto LAB_00109a40;
      if (lVar14 == 0x10000) {
        uVar11 = 0x40020010000;
        if (*(uint *)(param_1 + 0x14) < 0x31) {
          uVar11 = 0x20010000;
        }
        uVar12 = 0x34;
        goto LAB_00109a44;
      }
      if (lVar14 == 0x4000) {
        uVar12 = 0x30;
        uVar11 = 0x2004000;
        goto LAB_00109a44;
      }
    }
    uVar11 = 0;
  }
LAB_00109a40:
  uVar12 = 0x30;
LAB_00109a44:
  *(ulong *)(param_1 + 8) = uVar11 & uVar10;
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar12 <= *(uint *)(param_1 + 0x10)) {
    uVar1 = uVar12;
  }
  uVar2 = *(uint *)(param_1 + 0x14);
  if (uVar12 <= *(uint *)(param_1 + 0x14)) {
    uVar2 = uVar12;
  }
  *(uint *)(param_1 + 0x10) = uVar1;
  *(uint *)(param_1 + 0x14) = uVar2;
  if ((uVar11 & uVar10 & 0x15000) != 0) {
    lVar14 = kmalloc_trace(_memset,0xcc0,200);
    if (lVar14 == 0) {
      return 0;
    }
    iVar8 = *(int *)(param_1 + 0x10);
    uVar11 = (*(ulong *)(param_1 + 8) & 0xaaaaaaaaaaaaaaaa) >> 1 |
             (*(ulong *)(param_1 + 8) & 0x5555555555555555) << 1;
    uVar11 = (uVar11 & 0xcccccccccccccccc) >> 2 | (uVar11 & 0x3333333333333333) << 2;
    uVar11 = (uVar11 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar11 = (uVar11 & 0xff00ff00ff00ff00) >> 8 | (uVar11 & 0xff00ff00ff00ff) << 8;
    uVar11 = (uVar11 & 0xffff0000ffff0000) >> 0x10 | (uVar11 & 0xffff0000ffff) << 0x10;
    iVar9 = (int)LZCOUNT(uVar11 >> 0x20 | uVar11 << 0x20);
    iVar7 = iVar9 + -3;
    *(code **)(lVar14 + 0x68) = qcom_arm_lpae_map;
    *(code **)(lVar14 + 0x70) = qcom_arm_lpae_map_pages;
    iVar6 = 0;
    if (iVar7 != 0) {
      iVar6 = (iVar8 + -4) / iVar7;
    }
    uVar5 = *(undefined4 *)(param_1 + 0x68);
    *(undefined4 *)(lVar14 + 0xc0) = 0;
    *(code **)(lVar14 + 0x78) = qcom_arm_lpae_unmap;
    *(code **)(lVar14 + 0x80) = qcom_arm_lpae_unmap_pages;
    *(undefined4 *)(lVar14 + 0xa8) = uVar5;
    *(code **)(lVar14 + 0x88) = arm_lpae_iova_to_phys;
    uVar3 = *(undefined8 *)(param_1 + 0x58);
    uVar4 = *(undefined8 *)(param_1 + 0x60);
    *(int *)(lVar14 + 0x94) = 4 - iVar6;
    *(int *)(lVar14 + 0x98) = iVar7;
    *(undefined8 *)(lVar14 + 0xb0) = uVar3;
    *(undefined8 *)(lVar14 + 0xb8) = uVar4;
    *(int *)(lVar14 + 0x90) = (iVar8 - iVar9) + (iVar7 - iVar7 * iVar6);
    iVar8 = qcom_io_pgtable_allocator_register();
    if (iVar8 == 0) {
      return lVar14;
    }
    kfree(lVar14);
  }
  return 0;
}



//------------------------------------------------------------
// arm_lpae_iova_to_phys @ 00109b5c size=356
// signature: undefined arm_lpae_iova_to_phys(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong arm_lpae_iova_to_phys(long param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  
  lVar1 = param_1 + 0x58;
  uVar8 = *(ulong *)(param_1 + 0x38);
  iVar7 = *(int *)(param_1 + 0x2c);
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  if (uVar8 != 0) {
    uVar3 = *(uint *)(param_1 + 0x30);
    uVar4 = uVar3 * (4 - iVar7) + 3;
    do {
      if (*(int *)(param_1 + 0x2c) == iVar7) {
        iVar6 = *(int *)(param_1 + 0x28) - uVar3;
      }
      else {
        iVar6 = 0;
      }
      uVar8 = *(ulong *)(uVar8 + (param_2 >> ((ulong)uVar4 & 0x3f) &
                                 (long)~(-1 << (ulong)(iVar6 + uVar3 & 0x1f))) * 8);
      if (uVar8 == 0) break;
      uVar2 = 3;
      if (*(int *)(param_1 + -0x68) == 5 || iVar7 != 3) {
        uVar2 = 1;
      }
      if ((uVar8 & 3) == uVar2) {
        _raw_spin_unlock_irqrestore(lVar1,uVar5);
        uVar2 = uVar8 & 0xfffffffff000;
        if (0xffff < (ulong)(8L << ((ulong)*(uint *)(param_1 + 0x30) & 0x3f))) {
          uVar2 = (uVar8 & 0xfffffffff000) * 0x1000000001 & 0xfffffffff0000;
        }
        return uVar2 | param_2 & (-1L << ((ulong)(*(uint *)(param_1 + 0x30) * (4 - iVar7) + 3) &
                                         0x3f) ^ 0xffffffffffffffffU);
      }
      iVar7 = iVar7 + 1;
      uVar4 = uVar4 - uVar3;
      uVar2 = uVar8 & 0xfffffffff000;
      if (0xffff < (ulong)(8L << ((ulong)uVar3 & 0x3f))) {
        uVar2 = (uVar8 & 0xfffffffff000) * 0x1000000001 & 0x7fffff0000;
      }
      uVar8 = uVar2 - _memstart_addr | 0xffffff8000000000;
    } while (iVar7 < 4);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  return 0;
}



//------------------------------------------------------------
// qcom_io_pgtable_allocator_register @ 00109cc4 size=296
// signature: undefined qcom_io_pgtable_allocator_register(void)
// callers: [arm_lpae_alloc_pgtable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_io_pgtable_allocator_register(undefined4 param_1)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  undefined4 *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  uint uVar9;
  
  mutex_lock(&page_pool_xa_lock);
  lVar4 = xa_load(&page_pool_xa,param_1);
  if (lVar4 == 0) {
    puVar5 = (undefined4 *)kmalloc_trace(_gen_pool_alloc_algo_owner,0xa20,0x20);
    if (puVar5 == (undefined4 *)0x0) {
      uVar8 = 0xfffffff4;
    }
    else {
      *puVar5 = param_1;
      puVar5[1] = 1;
      puVar5[2] = 0;
      *(undefined4 **)(puVar5 + 4) = puVar5 + 4;
      *(undefined4 **)(puVar5 + 6) = puVar5 + 4;
      uVar6 = xa_store(&page_pool_xa,param_1,puVar5,0xa20);
      uVar9 = (uint)(uVar6 >> 2);
      if ((uVar6 & 3) != 2 || uVar6 < 0xffffffffffffc006) {
        uVar9 = 0;
      }
      uVar8 = (ulong)uVar9;
      if ((int)uVar9 < 0) {
        kfree(puVar5);
        uVar8 = uVar6 >> 2 & 0xffffffff;
      }
    }
    goto LAB_00109d24;
  }
  puVar1 = (uint *)(lVar4 + 4);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar9 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar9 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar9 == 0) {
    uVar7 = 2;
LAB_00109df0:
    refcount_warn_saturate(puVar1,uVar7);
  }
  else if ((int)(uVar9 + 1 | uVar9) < 0) {
    uVar7 = 1;
    goto LAB_00109df0;
  }
  uVar8 = 0;
LAB_00109d24:
  mutex_unlock(&page_pool_xa_lock);
  return uVar8;
}



//------------------------------------------------------------
// qcom_io_pgtable_allocator_unregister @ 00109dfc size=584
// signature: undefined qcom_io_pgtable_allocator_unregister(void)
// callers: [arm_lpae_free_pgtable, arm_64_lpae_alloc_pgtable_s1, arm_64_lpae_alloc_pgtable_s2, arm_mali_lpae_alloc_pgtable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_io_pgtable_allocator_unregister(undefined4 param_1)

{
  long lVar1;
  long *plVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  int iVar8;
  uint *puVar9;
  ulong uVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  ulong local_78 [3];
  
  lVar1 = sp_el0;
  local_78[2] = *(long *)(lVar1 + 0x638);
  mutex_lock(&page_pool_xa_lock);
  puVar9 = (uint *)xa_load(&page_pool_xa,param_1);
  puVar12 = puVar9 + 1;
  Hint_Prefetch(puVar12,2,0,1);
  do {
    uVar4 = *puVar12;
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(puVar12,0x10);
    if (bVar6) {
      *puVar12 = uVar4 - 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  if (uVar4 == 1) {
    DataMemoryBarrier(2,1);
    uVar4 = *puVar9;
    xa_erase(&page_pool_xa,uVar4);
    puVar13 = puVar9 + 4;
    puVar12 = *(uint **)puVar13;
    if ((puVar12 != puVar13) && (puVar11 = puVar12 + -2, puVar11 != (uint *)0x0)) {
      uVar10 = __list_del_entry_valid(puVar12);
      if ((uVar10 & 1) != 0) {
        lVar1 = *(long *)puVar12;
        plVar2 = *(long **)(puVar12 + 2);
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      puVar12[0] = 0x100;
      puVar12[1] = 0xdead0000;
      puVar12[2] = 0x122;
      puVar12[3] = 0xdead0000;
      Hint_Prefetch(0x10b6b0,2,0,1);
      do {
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(0x10b6b0,0x10);
        if (bVar6) {
          cVar5 = ExclusiveMonitorsStatus();
          page_pool_count = page_pool_count + -1;
        }
      } while (cVar5 != '\0');
      while( true ) {
        dec_node_page_state(puVar11,0x22);
        if (uVar4 != 0) {
          uVar3 = *puVar9;
          local_78[0] = 1L << ((ulong)uVar3 & 0x3f) | 8;
          local_78[1] = 0x700000003;
          iVar8 = qcom_scm_assign_mem((long)(puVar11 + (_memstart_addr >> 0xc) * 0x10) * 0x40 +
                                      0x8000000000,0x1000,local_78,local_78 + 1,1);
          if (iVar8 != 0) {
            __warn_printk("failed to unassign memory from VMID: %u rc: %d\n",(ulong)uVar3,iVar8);
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x800,0x109fa4);
            (*pcVar7)();
          }
        }
        __free_pages(puVar11,0);
        puVar12 = *(uint **)puVar13;
        if ((puVar12 == puVar13) || (puVar11 = puVar12 + -2, puVar11 == (uint *)0x0)) break;
        uVar10 = __list_del_entry_valid(puVar12);
        if ((uVar10 & 1) != 0) {
          lVar1 = *(long *)puVar12;
          plVar2 = *(long **)(puVar12 + 2);
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        puVar12[0] = 0x100;
        puVar12[1] = 0xdead0000;
        puVar12[2] = 0x122;
        puVar12[3] = 0xdead0000;
        Hint_Prefetch(0x10b6b0,2,0,1);
        do {
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(0x10b6b0,0x10);
          if (bVar6) {
            cVar5 = ExclusiveMonitorsStatus();
            page_pool_count = page_pool_count + -1;
          }
        } while (cVar5 != '\0');
      }
    }
    kfree(puVar9);
  }
  else if ((int)uVar4 < 1) {
    refcount_warn_saturate(puVar12,3);
  }
  mutex_unlock(&page_pool_xa_lock);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_io_pgtable_alloc_page @ 0010a074 size=452
// signature: undefined qcom_io_pgtable_alloc_page(void)
// callers: [__arm_lpae_alloc_pages]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * qcom_io_pgtable_alloc_page(uint param_1,uint param_2)

{
  long lVar1;
  long *plVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  long *plVar10;
  long *plVar11;
  undefined8 local_70;
  undefined8 local_68;
  uint local_60;
  undefined4 uStack_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if ((param_1 != 0) && ((param_2 >> 10 & 1) == 0)) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10a228);
    (*pcVar5)();
  }
  lVar7 = xa_load(&page_pool_xa,(ulong)param_1);
  lVar1 = lVar7 + 8;
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  plVar11 = *(long **)(lVar7 + 0x10);
  if ((plVar11 == (long *)(lVar7 + 0x10)) || (plVar10 = plVar11 + -1, plVar10 == (long *)0x0)) {
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
    uVar8 = tpidr_el1;
    plVar10 = (long *)__alloc_pages(uVar8,param_2,0,0,0);
    if (plVar10 != (long *)0x0) {
      if (param_1 != 0) {
        local_68 = 0x600000003;
        local_70 = 8;
        uStack_5c = 4;
        local_60 = param_1;
        iVar6 = qcom_scm_assign_mem((long)(plVar10 + (_memstart_addr >> 0xc) * 8) * 0x40 +
                                    0x8000000000,0x1000,&local_70,&local_68,2);
        if (iVar6 != 0) {
          __warn_printk("failed to assign memory to VMID: %u rc:%d\n",param_1,iVar6);
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10a21c);
          (*pcVar5)();
        }
      }
      plVar10[5] = (ulong)param_1;
    }
  }
  else {
    uVar9 = __list_del_entry_valid(plVar11);
    if ((uVar9 & 1) != 0) {
      lVar7 = *plVar11;
      plVar2 = (long *)plVar11[1];
      *(long **)(lVar7 + 8) = plVar2;
      *plVar2 = lVar7;
    }
    *plVar11 = -0x2152ffffffffff00;
    plVar11[1] = -0x2152fffffffffede;
    Hint_Prefetch(0x10b6b0,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(0x10b6b0,0x10);
      if (bVar4) {
        cVar3 = ExclusiveMonitorsStatus();
        page_pool_count = page_pool_count + -1;
      }
    } while (cVar3 != '\0');
    dec_node_page_state(plVar10,0x22);
    _raw_spin_unlock_irqrestore(lVar1,uVar8);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar10;
}



//------------------------------------------------------------
// qcom_io_pgtable_free_page @ 0010a250 size=212
// signature: undefined qcom_io_pgtable_free_page(void)
// callers: [__arm_lpae_free_pgtable, __arm_lpae_map, __arm_lpae_alloc_pages, __arm_lpae_unmap]
//------------------------------------------------------------

void qcom_io_pgtable_free_page(ulong param_1)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  
  lVar1 = param_1 + 8;
  lVar4 = xa_load(&page_pool_xa,*(undefined4 *)(param_1 + 0x28));
  clear_page((param_1 & 0x3ffffffffffc0) << 6 | 0xff00000000000000);
  uVar5 = _raw_spin_lock_irqsave(lVar4 + 8);
  plVar7 = (long *)(lVar4 + 0x10);
  lVar8 = *plVar7;
  uVar6 = __list_add_valid(lVar1,plVar7,lVar8);
  if ((uVar6 & 1) != 0) {
    *(long *)(lVar8 + 8) = lVar1;
    *(long *)(param_1 + 8) = lVar8;
    *(long **)(param_1 + 0x10) = plVar7;
    *plVar7 = lVar1;
  }
  Hint_Prefetch(0x10b6b0,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(0x10b6b0,0x10);
    if (bVar3) {
      cVar2 = ExclusiveMonitorsStatus();
      page_pool_count = page_pool_count + 1;
    }
  } while (cVar2 != '\0');
  inc_node_page_state(param_1,0x22);
  _raw_spin_unlock_irqrestore(lVar4 + 8,uVar5);
  return;
}



//------------------------------------------------------------
// qcom_io_pgtable_alloc_init @ 0010a340 size=44
// signature: undefined qcom_io_pgtable_alloc_init(void)
// callers: []
//------------------------------------------------------------

void qcom_io_pgtable_alloc_init(void)

{
  register_shrinker(&io_pgtable_alloc_shrinker,"io_pgtable_alloc");
  return;
}



//------------------------------------------------------------
// qcom_io_pgtable_alloc_exit @ 0010a370 size=36
// signature: undefined qcom_io_pgtable_alloc_exit(void)
// callers: []
//------------------------------------------------------------

void qcom_io_pgtable_alloc_exit(void)

{
  unregister_shrinker(&io_pgtable_alloc_shrinker);
  return;
}



//------------------------------------------------------------
// io_pgtable_alloc_count_objects @ 0010a398 size=24
// signature: undefined io_pgtable_alloc_count_objects(void)
// callers: []
//------------------------------------------------------------

long io_pgtable_alloc_count_objects(void)

{
  long lVar1;
  
  lVar1 = -2;
  if (page_pool_count != 0) {
    lVar1 = page_pool_count;
  }
  return lVar1;
}



//------------------------------------------------------------
// io_pgtable_alloc_scan_objects @ 0010a3b4 size=680
// signature: undefined io_pgtable_alloc_scan_objects(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong io_pgtable_alloc_scan_objects(undefined8 param_1,long param_2)

{
  long ****pppplVar1;
  long ****pppplVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  ulong uVar10;
  long ****pppplVar11;
  ulong uVar12;
  long *****ppppplVar13;
  long lVar14;
  long *****ppppplVar15;
  long lVar16;
  long lVar17;
  long *****local_90;
  long *****local_88;
  undefined8 local_80;
  ulong local_78 [3];
  
  lVar7 = sp_el0;
  local_90 = (long *****)&local_90;
  local_78[2] = *(long *)(lVar7 + 0x638);
  uVar12 = *(ulong *)(param_2 + 8);
  local_88 = local_90;
  mutex_lock(&page_pool_xa_lock);
  local_80 = 0;
  lVar7 = xa_find(&page_pool_xa,&local_80,0xffffffffffffffff,8);
  if (lVar7 == 0) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0;
    do {
      lVar14 = uVar12 - uVar10;
      uVar8 = _raw_spin_lock_irqsave(lVar7 + 8);
      if (lVar14 == 0) {
        lVar17 = 0;
      }
      else {
        lVar16 = 0;
        do {
          ppppplVar13 = *(long ******)(lVar7 + 0x10);
          lVar17 = lVar16;
          if (ppppplVar13 == (long *****)(lVar7 + 0x10) || ppppplVar13 + -1 == (long *****)0x0)
          break;
          uVar9 = __list_del_entry_valid(ppppplVar13);
          if ((uVar9 & 1) != 0) {
            pppplVar11 = *ppppplVar13;
            pppplVar1 = ppppplVar13[1];
            pppplVar11[1] = (long ***)pppplVar1;
            *pppplVar1 = (long ***)pppplVar11;
          }
          *ppppplVar13 = (long ****)0xdead000000000100;
          ppppplVar13[1] = (long ****)0xdead000000000122;
          Hint_Prefetch(0x10b6b0,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(0x10b6b0,0x10);
            if (bVar4) {
              cVar3 = ExclusiveMonitorsStatus();
              page_pool_count = page_pool_count + -1;
            }
          } while (cVar3 != '\0');
          dec_node_page_state(ppppplVar13 + -1,0x22);
          ppppplVar15 = local_90;
          uVar9 = __list_add_valid(ppppplVar13,&local_90,local_90);
          if ((uVar9 & 1) != 0) {
            ppppplVar15[1] = (long ****)ppppplVar13;
            *ppppplVar13 = (long ****)ppppplVar15;
            ppppplVar13[1] = (long ****)&local_90;
            local_90 = ppppplVar13;
          }
          lVar16 = lVar16 + 1;
          lVar17 = lVar14;
        } while (lVar14 != lVar16);
      }
      _raw_spin_unlock_irqrestore(lVar7 + 8,uVar8);
      uVar10 = lVar17 + uVar10;
    } while ((uVar10 < uVar12) &&
            (lVar7 = xa_find_after(&page_pool_xa,&local_80,0xffffffffffffffff,8), lVar7 != 0));
  }
  mutex_unlock(&page_pool_xa_lock);
  if ((long ******)local_90 != &local_90) {
    ppppplVar13 = local_90;
    do {
      ppppplVar15 = (long *****)*ppppplVar13;
      pppplVar11 = ppppplVar13[4];
      uVar12 = __list_del_entry_valid(ppppplVar13);
      if ((uVar12 & 1) != 0) {
        pppplVar1 = *ppppplVar13;
        pppplVar2 = ppppplVar13[1];
        pppplVar1[1] = (long ***)pppplVar2;
        *pppplVar2 = (long ***)pppplVar1;
      }
      *ppppplVar13 = (long ****)0xdead000000000100;
      ppppplVar13[1] = (long ****)0xdead000000000122;
      if ((int)pppplVar11 != 0) {
        local_78[0] = 1L << ((ulong)pppplVar11 & 0x3f) | 8;
        local_78[1] = 0x700000003;
        iVar6 = qcom_scm_assign_mem((long)(ppppplVar13 + -1 + (_memstart_addr >> 0xc) * 8) * 0x40 +
                                    0x8000000000,0x1000,local_78,local_78 + 1,1);
        if (iVar6 != 0) {
          __warn_printk("failed to unassign memory from VMID: %u rc: %d\n",
                        (ulong)pppplVar11 & 0xffffffff,iVar6);
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10a620);
          (*pcVar5)();
        }
      }
      __free_pages(ppppplVar13 + -1,0);
      ppppplVar13 = ppppplVar15;
    } while ((long ******)ppppplVar15 != &local_90);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_78[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// init_module @ 0010a93c size=404
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  ulong uVar4;
  
  if (init_table == (undefined *)0x0) {
LAB_0010a9a4:
    iVar2 = android_rvh_probe_register
                      (&__tracepoint_android_rvh_iommu_iovad_init_alloc_algo,init_iovad_attr,0);
    if (iVar2 != 0) {
      _printk(&DAT_0010ae2d);
    }
    iVar2 = android_rvh_probe_register
                      (&__tracepoint_android_rvh_iommu_alloc_insert_iova,__qcom_alloc_insert_iova,0)
    ;
    if (iVar2 != 0) {
      _printk(&DAT_0010ae9d);
    }
    iVar2 = android_rvh_probe_register
                      (&__tracepoint_android_rvh_iommu_limit_align_shift,__qcom_limit_align_shift,0)
    ;
    if (iVar2 != 0) {
      _printk(&DAT_0010ac4a);
    }
    iVar2 = 0;
  }
  else {
    pcVar1 = (code *)init_table;
    uVar4 = 0;
    while( true ) {
      if (*(int *)(pcVar1 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a980);
        (*pcVar1)();
      }
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) break;
      if (uVar4 - 0x20 < 0xffffffffffffffd8) goto LAB_0010aac8;
      pcVar1 = *(code **)((long)&PTR_qcom_dma_iommu_generic_driver_init_0010b218 + uVar4);
      uVar4 = uVar4 + 8;
      if (pcVar1 == (code *)0x0) goto LAB_0010a9a4;
    }
    if (0x27 < uVar4) goto LAB_0010aac8;
    _printk(&DAT_0010ae8a,*(undefined8 *)((long)&init_table + uVar4),iVar2);
    if (0x2f < uVar4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10aad0);
      (*pcVar1)();
    }
    pcVar3 = "alias=of:N*T*Cqcom,iommu-dmaC*" + uVar4 + 0x18;
    while ((char *)0x10b307 < pcVar3) {
      if (0x20 < uVar4 - 8) {
LAB_0010aac8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x10aacc);
        (*pcVar1)();
      }
      pcVar1 = *(code **)("alias=of:N*T*Cqcom,iommu-dmaC*" + uVar4 + 0x18);
      if (pcVar1 != (code *)0x0) {
        if (*(int *)(pcVar1 + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10aab0);
          (*pcVar1)();
        }
        (*pcVar1)();
      }
      pcVar3 = "alias=of:N*T*Cqcom,iommu-dmaC*" + uVar4 + 0x10;
      uVar4 = uVar4 - 8;
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_dma_iommu_generic_driver_init @ 0010aad4 size=44
// signature: undefined qcom_dma_iommu_generic_driver_init(void)
// callers: []
//------------------------------------------------------------

void qcom_dma_iommu_generic_driver_init(void)

{
  __platform_driver_register(&qcom_dma_iommu_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// dma_mapping_fast_init @ 0010ab04 size=48
// signature: undefined dma_mapping_fast_init(void)
// callers: [init_module]
//------------------------------------------------------------

void dma_mapping_fast_init(void)

{
  android_rvh_probe_register
            (&__tracepoint_android_rvh_iommu_setup_dma_ops,__fast_smmu_setup_dma_ops,0);
  return;
}



//------------------------------------------------------------
// qcom_arm_lpae_do_selftests @ 0010ab38 size=8
// signature: undefined qcom_arm_lpae_do_selftests(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_arm_lpae_do_selftests(void)

{
  return 0;
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010e000 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [of_property_walk_each_entry, qcom_iommu_get_msi_size, qcom_iommu_group_parse_phandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010e008 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_io_pgtable_alloc_page, qcom_arm_lpae_map_pages, qcom_iommu_group_parse_phandle, qcom_iommu_generate_resv_regions, __fast_smmu_setup_dma_ops, fast_smmu_notify, qcom_iommu_generate_dma_regions, init_iovad_attr, qcom_dma_iommu_probe, fast_smmu_alloc, qcom_iommu_get_fast_iova_range, fast_smmu_map_sg, qcom_arm_lpae_map_sg, qcom_arm_lpae_unmap_pages, qcom_io_pgtable_allocator_unregister, of_property_walk_each_entry, qcom_iommu_get_msi_size, qcom_arm_lpae_unmap, io_pgtable_alloc_scan_objects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_alloc_resv_region @ 0010e010 size=1
// signature: undefined iommu_alloc_resv_region(void)
// callers: [insert_range, qcom_iommu_generate_resv_regions]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_alloc_resv_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010e018 size=1
// signature: undefined __list_add_valid(void)
// callers: [insert_range, qcom_io_pgtable_free_page, io_pgtable_alloc_scan_objects, qcom_iommu_generate_resv_regions]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0010e020 size=1
// signature: undefined of_get_property(void)
// callers: [of_property_walk_each_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_n_addr_cells @ 0010e028 size=1
// signature: undefined of_n_addr_cells(void)
// callers: [of_property_walk_each_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_n_addr_cells(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_n_size_cells @ 0010e030 size=1
// signature: undefined of_n_size_cells(void)
// callers: [of_property_walk_each_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_n_size_cells(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010e038 size=1
// signature: undefined _dev_err(void)
// callers: [of_property_walk_each_entry, fast_smmu_init_mapping, __fast_smmu_setup_dma_ops, __arm_lpae_alloc_pages, fast_smmu_notify, qcom_dma_iommu_probe, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_put_resv_regions @ 0010e040 size=1
// signature: undefined iommu_put_resv_regions(void)
// callers: [qcom_iommu_generate_resv_regions, __fast_smmu_setup_dma_ops]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_put_resv_regions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010e048 size=1
// signature: undefined kfree(void)
// callers: [qcom_dma_common_contiguous_remap, arm_lpae_alloc_pgtable, qcom_iommu_generate_resv_regions, av8l_fast_free_pgtable, av8l_fast_alloc_pgtable, arm_64_lpae_alloc_pgtable_s2, arm_mali_lpae_alloc_pgtable, qcom_dma_common_free_remap, qcom_io_pgtable_allocator_unregister, fast_smmu_init_mapping, fast_smmu_put_dma_cookie, arm_lpae_free_pgtable, arm_64_lpae_alloc_pgtable_s1, atomic_pool_expand, qcom_dma_common_pages_remap, qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010e050 size=1
// signature: undefined _printk(void)
// callers: [qcom_free_io_pgtable_ops, av8l_fast_map_pages, get_addr_range, av8l_fast_unmap_pages, av8l_fast_map_public, qcom_dma_iommu_probe, av8l_fast_unmap_public, av8l_fast_iova_coherent_public, qcom_arm_lpae_map_sg, qcom_alloc_io_pgtable_ops, av8l_fast_map, av8l_fast_unmap, init_module, av8l_fast_map_sg_public]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_get_domain_for_dev @ 0010e058 size=1
// signature: undefined iommu_get_domain_for_dev(void)
// callers: [fast_smmu_map_page, fast_smmu_unmap_sg, fast_smmu_dma_unmap_resource, fast_smmu_sync_sg_for_cpu, qcom_iommu_sid_switch, __fast_smmu_setup_dma_ops, fast_smmu_dma_map_resource, qcom_skip_tlb_management, fast_smmu_unmap_page, fast_smmu_sync_single_for_cpu, fast_smmu_alloc, fast_smmu_sync_sg_for_device, fast_smmu_map_sg, fast_smmu_sync_single_for_device, __fast_smmu_alloc_contiguous, fast_smmu_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_domain_for_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010e060 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_iommu_get_msi_size, init_iovad_attr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_io_pgtable_ops @ 0010e068 size=1
// signature: undefined alloc_io_pgtable_ops(void)
// callers: [qcom_alloc_io_pgtable_ops]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_io_pgtable_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_io_pgtable_ops @ 0010e070 size=1
// signature: undefined free_io_pgtable_ops(void)
// callers: [qcom_free_io_pgtable_ops]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_io_pgtable_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// android_rvh_probe_register @ 0010e080 size=1
// signature: undefined android_rvh_probe_register(void)
// callers: [init_module, dma_mapping_fast_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void android_rvh_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010e098 size=1
// signature: undefined of_find_property(void)
// callers: [init_iovad_attr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010e0a0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [fast_smmu_map_page, qcom_io_pgtable_alloc_page, fast_smmu_unmap_sg, fast_smmu_dma_unmap_resource, qcom_arm_lpae_map_pages, qcom_io_pgtable_free_page, __qcom_alloc_insert_iova, __fast_smmu_setup_dma_ops, fast_smmu_dma_map_resource, arm_lpae_iova_to_phys, fast_smmu_unmap_page, fast_smmu_alloc, fast_smmu_map_sg, qcom_arm_lpae_map_sg, qcom_arm_lpae_unmap_pages, arm_lpae_install_table, qcom_arm_lpae_unmap, io_pgtable_alloc_scan_objects, __fast_smmu_alloc_contiguous, __arm_lpae_map, fast_smmu_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_prev @ 0010e0a8 size=1
// signature: undefined rb_prev(void)
// callers: [__qcom_alloc_insert_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_prev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_insert_color @ 0010e0b0 size=1
// signature: undefined rb_insert_color(void)
// callers: [fast_smmu_init_mapping, __qcom_alloc_insert_iova, qcom_dma_common_pages_remap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_insert_color(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010e0b8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [fast_smmu_map_page, qcom_io_pgtable_alloc_page, fast_smmu_unmap_sg, fast_smmu_dma_unmap_resource, qcom_arm_lpae_map_pages, qcom_io_pgtable_free_page, __qcom_alloc_insert_iova, __fast_smmu_setup_dma_ops, fast_smmu_dma_map_resource, arm_lpae_iova_to_phys, fast_smmu_unmap_page, fast_smmu_alloc, fast_smmu_map_sg, qcom_arm_lpae_map_sg, qcom_arm_lpae_unmap_pages, arm_lpae_install_table, qcom_arm_lpae_unmap, io_pgtable_alloc_scan_objects, __fast_smmu_alloc_contiguous, __arm_lpae_map, fast_smmu_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_device @ 0010e0c0 size=1
// signature: undefined dma_sync_single_for_device(void)
// callers: [qcom_arm_lpae_map_sg, qcom_arch_dma_prep_coherent, arm_lpae_init_pte, arm_lpae_install_table, __arm_lpae_map, __arm_lpae_unmap, atomic_pool_expand, av8l_clean_range, qcom_arch_sync_dma_for_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_cpu @ 0010e0c8 size=1
// signature: undefined dma_sync_single_for_cpu(void)
// callers: [qcom_arch_sync_dma_for_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_alloc @ 0010e0d8 size=1
// signature: undefined cma_alloc(void)
// callers: [qcom_dma_alloc_contiguous, qcom_dma_alloc_from_contiguous, atomic_pool_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cma_release @ 0010e0e0 size=1
// signature: undefined cma_release(void)
// callers: [qcom_dma_release_from_contiguous, qcom_dma_atomic_pool_exit, qcom_dma_free_contiguous, atomic_pool_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cma_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __free_pages @ 0010e0e8 size=1
// signature: undefined __free_pages(void)
// callers: [qcom_io_pgtable_allocator_unregister, qcom_dma_free_contiguous, io_pgtable_alloc_scan_objects, av8l_fast_free_pgtable, av8l_fast_alloc_pgtable, fast_smmu_free, atomic_pool_expand, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010e0f0 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_dma_common_free_remap, qcom_iommu_dma_mmap, qcom_io_pgtable_allocator_unregister, qcom_iommu_dma_get_sgtable, io_pgtable_alloc_scan_objects, __fast_smmu_setup_dma_ops, qcom_dma_common_find_pages, qcom_dma_common_pages_remap, qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010e0f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_dma_common_free_remap, qcom_iommu_dma_mmap, qcom_io_pgtable_allocator_unregister, qcom_iommu_dma_get_sgtable, io_pgtable_alloc_scan_objects, __fast_smmu_setup_dma_ops, qcom_dma_common_find_pages, qcom_dma_common_pages_remap, qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010e108 size=1
// signature: undefined kmalloc_trace(void)
// callers: [fast_smmu_init_mapping, arm_lpae_alloc_pgtable, av8l_fast_alloc_pgtable, qcom_dma_common_pages_remap, qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmap @ 0010e110 size=1
// signature: undefined vmap(void)
// callers: [qcom_dma_common_contiguous_remap, av8l_fast_alloc_pgtable, atomic_pool_expand, qcom_dma_common_pages_remap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010e118 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_dma_common_contiguous_remap, fast_smmu_init_mapping, atomic_pool_expand, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rb_erase @ 0010e120 size=1
// signature: undefined rb_erase(void)
// callers: [qcom_dma_common_free_remap, fast_smmu_put_dma_cookie]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rb_erase(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vunmap @ 0010e128 size=1
// signature: undefined vunmap(void)
// callers: [qcom_dma_common_free_remap, av8l_fast_free_pgtable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vunmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_alloc_algo_owner @ 0010e130 size=1
// signature: undefined gen_pool_alloc_algo_owner(void)
// callers: [qcom_dma_atomic_pool_exit, qcom_dma_alloc_from_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_alloc_algo_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_virt_to_phys @ 0010e138 size=1
// signature: undefined gen_pool_virt_to_phys(void)
// callers: [qcom_dma_alloc_from_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_virt_to_phys(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010e140 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_dma_alloc_from_pool, av8l_fast_unmap, __fast_smmu_alloc_contiguous, av8l_fast_unmap_pages, __arm_lpae_unmap, av8l_fast_unmap_public]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_avail @ 0010e148 size=1
// signature: undefined gen_pool_avail(void)
// callers: [qcom_dma_alloc_from_pool, atomic_pool_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_avail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010e158 size=1
// signature: undefined queue_work_on(void)
// callers: [qcom_dma_alloc_from_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010e160 size=1
// signature: undefined __warn_printk(void)
// callers: [qcom_io_pgtable_alloc_page, qcom_io_pgtable_allocator_unregister, qcom_dma_alloc_from_pool, io_pgtable_alloc_scan_objects, __arm_lpae_alloc_pages, fast_smmu_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_has_addr @ 0010e168 size=1
// signature: undefined gen_pool_has_addr(void)
// callers: [qcom_dma_free_from_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_has_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_free_owner @ 0010e170 size=1
// signature: undefined gen_pool_free_owner(void)
// callers: [qcom_dma_atomic_pool_exit, qcom_dma_free_from_pool]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_free_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 0010e178 size=1
// signature: undefined sg_next(void)
// callers: [qcom_iommu_dma_finalise_sg, qcom_arm_lpae_map_sg, fast_smmu_unmap_sg, fast_smmu_sync_sg_for_cpu, qcom_iommu_dma_prepare_map_sg, qcom_iommu_dma_invalidate_sg, av8l_fast_map_sg_public, fast_smmu_sync_sg_for_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 0010e180 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [qcom_iommu_dma_mmap, qcom_iommu_dma_get_sgtable, __arm_lpae_alloc_pages, fast_smmu_free, av8l_clean_range]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_pfn @ 0010e188 size=1
// signature: undefined vmalloc_to_pfn(void)
// callers: [qcom_iommu_dma_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_pfn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remap_pfn_range @ 0010e190 size=1
// signature: undefined remap_pfn_range(void)
// callers: [qcom_iommu_dma_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vm_map_pages @ 0010e198 size=1
// signature: undefined vm_map_pages(void)
// callers: [qcom_iommu_dma_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vm_map_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_page @ 0010e1a0 size=1
// signature: undefined vmalloc_to_page(void)
// callers: [qcom_iommu_dma_get_sgtable, qcom_dma_atomic_pool_exit, fast_smmu_free, av8l_clean_range]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table @ 0010e1a8 size=1
// signature: undefined sg_alloc_table(void)
// callers: [qcom_iommu_dma_get_sgtable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_alloc_table_from_pages_segment @ 0010e1b0 size=1
// signature: undefined sg_alloc_table_from_pages_segment(void)
// callers: [qcom_iommu_dma_get_sgtable, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_alloc_table_from_pages_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010e1b8 size=1
// signature: undefined __platform_driver_register(void)
// callers: [qcom_dma_iommu_generic_driver_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 0010e1c0 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [qcom_dma_iommu_generic_driver_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_reserved_mem_device_init_by_idx @ 0010e1c8 size=1
// signature: undefined of_reserved_mem_device_init_by_idx(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_reserved_mem_device_init_by_idx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_create @ 0010e1d8 size=1
// signature: undefined gen_pool_create(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_set_algo @ 0010e1e8 size=1
// signature: undefined gen_pool_set_algo(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_set_algo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_size @ 0010e1f0 size=1
// signature: undefined gen_pool_size(void)
// callers: [atomic_pool_work_fn, qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_destroy @ 0010e1f8 size=1
// signature: undefined gen_pool_destroy(void)
// callers: [qcom_dma_atomic_pool_exit, qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010e200 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_ulong @ 0010e208 size=1
// signature: undefined debugfs_create_ulong(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_ulong(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0010e210 size=1
// signature: undefined dma_set_mask(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0010e218 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [qcom_dma_iommu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 0010e220 size=1
// signature: undefined __alloc_pages(void)
// callers: [qcom_io_pgtable_alloc_page, av8l_fast_alloc_pgtable, atomic_pool_expand, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_add_owner @ 0010e230 size=1
// signature: undefined gen_pool_add_owner(void)
// callers: [atomic_pool_expand]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_add_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 0010e238 size=1
// signature: undefined kmalloc_large(void)
// callers: [av8l_fast_alloc_pgtable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 0010e240 size=1
// signature: undefined vmalloc(void)
// callers: [av8l_fast_alloc_pgtable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree @ 0010e258 size=1
// signature: undefined kvfree(void)
// callers: [fast_smmu_init_mapping, fast_smmu_put_dma_cookie, av8l_fast_free_pgtable, av8l_fast_alloc_pgtable, fast_smmu_free, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irqsave @ 0010e260 size=1
// signature: undefined _raw_write_lock_irqsave(void)
// callers: [fast_smmu_init_mapping, fast_smmu_put_dma_cookie]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irqrestore @ 0010e268 size=1
// signature: undefined _raw_write_unlock_irqrestore(void)
// callers: [fast_smmu_init_mapping, fast_smmu_put_dma_cookie]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_iova_domain @ 0010e270 size=1
// signature: undefined put_iova_domain(void)
// callers: [fast_smmu_put_dma_cookie]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_iova_domain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irqsave @ 0010e278 size=1
// signature: undefined _raw_read_lock_irqsave(void)
// callers: [fast_smmu_map_page, fast_smmu_unmap_sg, fast_smmu_dma_unmap_resource, fast_smmu_sync_sg_for_cpu, __fast_smmu_setup_dma_ops, fast_smmu_dma_map_resource, fast_smmu_unmap_page, fast_smmu_sync_single_for_cpu, fast_smmu_alloc, fast_smmu_sync_sg_for_device, fast_smmu_map_sg, fast_smmu_init_mapping, fast_smmu_sync_single_for_device, __fast_smmu_alloc_contiguous, fast_smmu_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irqrestore @ 0010e280 size=1
// signature: undefined _raw_read_unlock_irqrestore(void)
// callers: [fast_smmu_map_page, fast_smmu_unmap_sg, fast_smmu_dma_unmap_resource, fast_smmu_sync_sg_for_cpu, __fast_smmu_setup_dma_ops, fast_smmu_dma_map_resource, fast_smmu_unmap_page, fast_smmu_sync_single_for_cpu, fast_smmu_alloc, fast_smmu_sync_sg_for_device, fast_smmu_map_sg, fast_smmu_init_mapping, fast_smmu_sync_single_for_device, __fast_smmu_alloc_contiguous, fast_smmu_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 0010e288 size=1
// signature: undefined vzalloc(void)
// callers: [fast_smmu_init_mapping, fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010e290 size=1
// signature: undefined __mutex_init(void)
// callers: [fast_smmu_init_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_iova_domain @ 0010e298 size=1
// signature: undefined init_iova_domain(void)
// callers: [fast_smmu_init_mapping]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_iova_domain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 0010e2a0 size=1
// signature: undefined print_hex_dump(void)
// callers: [fast_smmu_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_set @ 0010e2b0 size=1
// signature: undefined __bitmap_set(void)
// callers: [__fast_smmu_alloc_iova, __fast_smmu_setup_dma_ops]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_get_msi_cookie @ 0010e2b8 size=1
// signature: undefined iommu_get_msi_cookie(void)
// callers: [__fast_smmu_setup_dma_ops]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_msi_cookie(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bitmap_find_next_zero_area_off @ 0010e2c8 size=1
// signature: undefined bitmap_find_next_zero_area_off(void)
// callers: [__fast_smmu_alloc_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bitmap_find_next_zero_area_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010e2d0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [__fast_smmu_alloc_iova]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_clear @ 0010e2d8 size=1
// signature: undefined __bitmap_clear(void)
// callers: [fast_smmu_unmap_sg, fast_smmu_dma_unmap_resource, __fast_smmu_alloc_contiguous, fast_smmu_dma_map_resource, __fast_smmu_free_iova, fast_smmu_free, fast_smmu_unmap_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_clear(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_start @ 0010e2e0 size=1
// signature: undefined sg_miter_start(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_start(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_next @ 0010e2e8 size=1
// signature: undefined sg_miter_next(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_miter_stop @ 0010e2f0 size=1
// signature: undefined sg_miter_stop(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_miter_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_free_table @ 0010e2f8 size=1
// signature: undefined sg_free_table(void)
// callers: [fast_smmu_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_free_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_map @ 0010e300 size=1
// signature: undefined iommu_map(void)
// callers: [fast_smmu_dma_map_resource]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_unmap @ 0010e308 size=1
// signature: undefined iommu_unmap(void)
// callers: [fast_smmu_dma_unmap_resource]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_unmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 0010e310 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [__arm_lpae_free_pgtable, __arm_lpae_map, __arm_lpae_alloc_pages, __arm_lpae_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 0010e318 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [__arm_lpae_alloc_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 0010e320 size=1
// signature: undefined dev_driver_string(void)
// callers: [__arm_lpae_alloc_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_load @ 0010e330 size=1
// signature: undefined xa_load(void)
// callers: [qcom_io_pgtable_alloc_page, qcom_io_pgtable_allocator_unregister, qcom_io_pgtable_free_page, qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_store @ 0010e338 size=1
// signature: undefined xa_store(void)
// callers: [qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_store(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010e340 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [qcom_io_pgtable_allocator_unregister, qcom_io_pgtable_allocator_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_erase @ 0010e348 size=1
// signature: undefined xa_erase(void)
// callers: [qcom_io_pgtable_allocator_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_erase(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010e350 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_io_pgtable_alloc_page, qcom_io_pgtable_allocator_unregister, io_pgtable_alloc_scan_objects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dec_node_page_state @ 0010e358 size=1
// signature: undefined dec_node_page_state(void)
// callers: [qcom_io_pgtable_alloc_page, qcom_io_pgtable_allocator_unregister, io_pgtable_alloc_scan_objects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dec_node_page_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 0010e360 size=1
// signature: undefined qcom_scm_assign_mem(void)
// callers: [qcom_io_pgtable_alloc_page, qcom_io_pgtable_allocator_unregister, io_pgtable_alloc_scan_objects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_assign_mem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clear_page @ 0010e368 size=1
// signature: undefined clear_page(void)
// callers: [qcom_io_pgtable_free_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clear_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// inc_node_page_state @ 0010e370 size=1
// signature: undefined inc_node_page_state(void)
// callers: [qcom_io_pgtable_free_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void inc_node_page_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_shrinker @ 0010e378 size=1
// signature: undefined register_shrinker(void)
// callers: [qcom_io_pgtable_alloc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_shrinker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_shrinker @ 0010e380 size=1
// signature: undefined unregister_shrinker(void)
// callers: [qcom_io_pgtable_alloc_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_shrinker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_find @ 0010e388 size=1
// signature: undefined xa_find(void)
// callers: [io_pgtable_alloc_scan_objects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_find_after @ 0010e390 size=1
// signature: undefined xa_find_after(void)
// callers: [io_pgtable_alloc_scan_objects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_find_after(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



