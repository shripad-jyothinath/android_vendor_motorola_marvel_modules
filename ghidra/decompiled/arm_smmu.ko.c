// Decompiled by Ghidra 12.2
// Program: arm_smmu.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_tlbi_start @ 001034d4 size=100
// signature: undefined __traceiter_tlbi_start(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_tlbi_start(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00115310;
  plVar2 = DAT_00115310;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5f25cf8b) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103518);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_tlbi_end @ 0010353c size=100
// signature: undefined __traceiter_tlbi_end(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_tlbi_end(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115358;
  plVar2 = _DAT_00115358;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5f25cf8b) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103580);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_iommu_pgtable_add @ 001035a4 size=140
// signature: undefined __traceiter_iommu_pgtable_add(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_iommu_pgtable_add
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001153a0;
  plVar2 = _DAT_001153a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x437bd49e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103608);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_iommu_pgtable_remove @ 00103634 size=140
// signature: undefined __traceiter_iommu_pgtable_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_iommu_pgtable_remove
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001153e8;
  plVar2 = _DAT_001153e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x437bd49e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103698);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_map_pages @ 001036c4 size=140
// signature: undefined __traceiter_map_pages(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_map_pages
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115430;
  plVar2 = _DAT_00115430;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1b3f0036) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103728);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_unmap_pages @ 00103754 size=140
// signature: undefined __traceiter_unmap_pages(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_unmap_pages
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115478;
  plVar2 = _DAT_00115478;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1b3f0036) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1037b8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_map_sg @ 001037e4 size=140
// signature: undefined __traceiter_map_sg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_map_sg(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                  undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001154c0;
  plVar2 = _DAT_001154c0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x2da521f1) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103848);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_tlbsync_timeout @ 00103874 size=100
// signature: undefined __traceiter_tlbsync_timeout(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_tlbsync_timeout(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115508;
  plVar2 = _DAT_00115508;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x8584eca) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1038b8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_smmu_init @ 001038dc size=100
// signature: undefined __traceiter_smmu_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_smmu_init(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115550;
  plVar2 = _DAT_00115550;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4d7d0c96) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103920);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_iommu_tlbi @ 00103944 size=264
// signature: undefined trace_event_raw_event_iommu_tlbi(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_iommu_tlbi(long param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
    if (pcVar2 == (char *)0x0) {
      pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
      pcVar2 = "(null)";
      if (pcVar6 != (char *)0x0) {
        pcVar2 = pcVar6;
      }
    }
    sVar3 = strlen(pcVar2);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0xc);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0xc;
      pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar2 == (char *)0x0) {
        pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar2 = "(null)";
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6;
        }
      }
      strcpy((char *)(lVar4 + 0xc),pcVar2);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_iommu_tlbi @ 00103a50 size=360
// signature: undefined perf_trace_iommu_tlbi(void)
// callers: []
//------------------------------------------------------------

void perf_trace_iommu_tlbi(long param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  char *pcVar7;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60 = 0;
  local_64 = 0;
  pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
  if (pcVar4 == (char *)0x0) {
    pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
    pcVar4 = "(null)";
    if (pcVar7 != (char *)0x0) {
      pcVar4 = pcVar7;
    }
  }
  sVar5 = strlen(pcVar4);
  lVar6 = tpidr_el1;
  plVar2 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar5 & 0xfffffff8) + 0x14;
    lVar6 = perf_trace_buf_alloc(iVar1,&local_60,&local_64);
    if (lVar6 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar3;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar6 + 8) = (uint)sVar5 * 0x10000 + 0x1000c;
      pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar4 == (char *)0x0) {
        pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar4 = "(null)";
        if (pcVar7 != (char *)0x0) {
          pcVar4 = pcVar7;
        }
      }
      strcpy((char *)(lVar6 + 0xc),pcVar4);
      perf_trace_run_bpf_submit(lVar6,iVar1,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_iommu_pgtable @ 00103bbc size=296
// signature: undefined trace_event_raw_event_iommu_pgtable(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_iommu_pgtable
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
    if (pcVar2 == (char *)0x0) {
      pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
      pcVar2 = "(null)";
      if (pcVar6 != (char *)0x0) {
        pcVar2 = pcVar6;
      }
    }
    sVar3 = strlen(pcVar2);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x28);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0x28;
      pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar2 == (char *)0x0) {
        pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar2 = "(null)";
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6;
        }
      }
      strcpy((char *)(lVar4 + 0x28),pcVar2);
      *(undefined8 *)(lVar4 + 0x10) = param_3;
      *(undefined8 *)(lVar4 + 0x18) = param_4;
      *(undefined8 *)(lVar4 + 0x20) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_iommu_pgtable @ 00103ce8 size=392
// signature: undefined perf_trace_iommu_pgtable(void)
// callers: []
//------------------------------------------------------------

void perf_trace_iommu_pgtable
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  char *pcVar7;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = 0;
  local_74 = 0;
  pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
  if (pcVar4 == (char *)0x0) {
    pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
    pcVar4 = "(null)";
    if (pcVar7 != (char *)0x0) {
      pcVar4 = pcVar7;
    }
  }
  sVar5 = strlen(pcVar4);
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar5 + 0x34U & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar6 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar6 + 8) = (int)sVar5 * 0x10000 + 0x10028;
      pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar4 == (char *)0x0) {
        pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar4 = "(null)";
        if (pcVar7 != (char *)0x0) {
          pcVar4 = pcVar7;
        }
      }
      strcpy((char *)(lVar6 + 0x28),pcVar4);
      *(undefined8 *)(lVar6 + 0x10) = param_3;
      *(undefined8 *)(lVar6 + 0x18) = param_4;
      *(undefined8 *)(lVar6 + 0x20) = param_5;
      perf_trace_run_bpf_submit(lVar6,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_iommu_map_pages @ 00103e74 size=296
// signature: undefined trace_event_raw_event_iommu_map_pages(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_iommu_map_pages
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
    if (pcVar2 == (char *)0x0) {
      pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
      pcVar2 = "(null)";
      if (pcVar6 != (char *)0x0) {
        pcVar2 = pcVar6;
      }
    }
    sVar3 = strlen(pcVar2);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x28);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0x28;
      pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar2 == (char *)0x0) {
        pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar2 = "(null)";
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6;
        }
      }
      strcpy((char *)(lVar4 + 0x28),pcVar2);
      *(undefined8 *)(lVar4 + 0x10) = param_3;
      *(undefined8 *)(lVar4 + 0x18) = param_4;
      *(undefined8 *)(lVar4 + 0x20) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_iommu_map_pages @ 00103fa0 size=392
// signature: undefined perf_trace_iommu_map_pages(void)
// callers: []
//------------------------------------------------------------

void perf_trace_iommu_map_pages
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4,undefined8 param_5)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  char *pcVar7;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = 0;
  local_74 = 0;
  pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
  if (pcVar4 == (char *)0x0) {
    pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
    pcVar4 = "(null)";
    if (pcVar7 != (char *)0x0) {
      pcVar4 = pcVar7;
    }
  }
  sVar5 = strlen(pcVar4);
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar5 + 0x34U & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar6 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar6 + 8) = (int)sVar5 * 0x10000 + 0x10028;
      pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar4 == (char *)0x0) {
        pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar4 = "(null)";
        if (pcVar7 != (char *)0x0) {
          pcVar4 = pcVar7;
        }
      }
      strcpy((char *)(lVar6 + 0x28),pcVar4);
      *(undefined8 *)(lVar6 + 0x10) = param_3;
      *(undefined8 *)(lVar6 + 0x18) = param_4;
      *(undefined8 *)(lVar6 + 0x20) = param_5;
      perf_trace_run_bpf_submit(lVar6,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_map_sg @ 0010412c size=332
// signature: undefined trace_event_raw_event_map_sg(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_map_sg
               (long param_1,long param_2,undefined8 param_3,long param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
    if (pcVar2 == (char *)0x0) {
      pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
      pcVar2 = "(null)";
      if (pcVar6 != (char *)0x0) {
        pcVar2 = pcVar6;
      }
    }
    sVar3 = strlen(pcVar2);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x20);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0x20;
      pcVar2 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar2 == (char *)0x0) {
        pcVar6 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar2 = "(null)";
        if (pcVar6 != (char *)0x0) {
          pcVar2 = pcVar6;
        }
      }
      strcpy((char *)(lVar4 + 0x20),pcVar2);
      *(undefined8 *)(lVar4 + 0x10) = param_3;
      lVar7 = 0;
      for (; param_5 != 0; param_5 = param_5 + -1) {
        lVar7 = lVar7 + (ulong)*(uint *)(param_4 + 0xc);
        param_4 = sg_next(param_4);
      }
      *(long *)(lVar4 + 0x18) = lVar7;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_map_sg @ 0010427c size=428
// signature: undefined perf_trace_map_sg(void)
// callers: []
//------------------------------------------------------------

void perf_trace_map_sg(long param_1,long param_2,undefined8 param_3,long param_4,int param_5)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  char *pcVar7;
  long lVar8;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = 0;
  local_74 = 0;
  pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
  if (pcVar4 == (char *)0x0) {
    pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
    pcVar4 = "(null)";
    if (pcVar7 != (char *)0x0) {
      pcVar4 = pcVar7;
    }
  }
  sVar5 = strlen(pcVar4);
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar5 + 0x2cU & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar6 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar6 + 8) = (int)sVar5 * 0x10000 + 0x10020;
      pcVar4 = (char *)(*(undefined8 **)(param_2 + 8))[0xe];
      if (pcVar4 == (char *)0x0) {
        pcVar7 = (char *)**(undefined8 **)(param_2 + 8);
        pcVar4 = "(null)";
        if (pcVar7 != (char *)0x0) {
          pcVar4 = pcVar7;
        }
      }
      strcpy((char *)(lVar6 + 0x20),pcVar4);
      *(undefined8 *)(lVar6 + 0x10) = param_3;
      lVar8 = 0;
      for (; param_5 != 0; param_5 = param_5 + -1) {
        lVar8 = lVar8 + (ulong)*(uint *)(param_4 + 0xc);
        param_4 = sg_next(param_4);
      }
      *(long *)(lVar6 + 0x18) = lVar8;
      perf_trace_run_bpf_submit(lVar6,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_tlbsync_timeout @ 0010442c size=256
// signature: undefined trace_event_raw_event_tlbsync_timeout(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_tlbsync_timeout(long param_1,undefined8 *param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    pcVar2 = (char *)param_2[0xe];
    if (pcVar2 == (char *)0x0) {
      pcVar2 = "(null)";
      if ((char *)*param_2 != (char *)0x0) {
        pcVar2 = (char *)*param_2;
      }
    }
    sVar3 = strlen(pcVar2);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0xc);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0xc;
      pcVar2 = (char *)param_2[0xe];
      if (pcVar2 == (char *)0x0) {
        pcVar2 = "(null)";
        if ((char *)*param_2 != (char *)0x0) {
          pcVar2 = (char *)*param_2;
        }
      }
      strcpy((char *)(lVar4 + 0xc),pcVar2);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_tlbsync_timeout @ 00104530 size=352
// signature: undefined perf_trace_tlbsync_timeout(void)
// callers: []
//------------------------------------------------------------

void perf_trace_tlbsync_timeout(long param_1,undefined8 *param_2)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  char *pcVar4;
  size_t sVar5;
  long lVar6;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  pcVar4 = (char *)param_2[0xe];
  local_60 = 0;
  local_64 = 0;
  if (pcVar4 == (char *)0x0) {
    pcVar4 = "(null)";
    if ((char *)*param_2 != (char *)0x0) {
      pcVar4 = (char *)*param_2;
    }
  }
  sVar5 = strlen(pcVar4);
  lVar6 = tpidr_el1;
  plVar2 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar5 & 0xfffffff8) + 0x14;
    lVar6 = perf_trace_buf_alloc(iVar1,&local_60,&local_64);
    if (lVar6 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar3;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar6 + 8) = (uint)sVar5 * 0x10000 + 0x1000c;
      pcVar4 = (char *)param_2[0xe];
      if (pcVar4 == (char *)0x0) {
        pcVar4 = "(null)";
        if ((char *)*param_2 != (char *)0x0) {
          pcVar4 = (char *)*param_2;
        }
      }
      strcpy((char *)(lVar6 + 0xc),pcVar4);
      perf_trace_run_bpf_submit(lVar6,iVar1,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_smmu_init @ 00104694 size=168
// signature: undefined trace_event_raw_event_smmu_init(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_smmu_init(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_smmu_init @ 00104740 size=236
// signature: undefined perf_trace_smmu_init(void)
// callers: []
//------------------------------------------------------------

void perf_trace_smmu_init(long param_1,undefined8 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0x14,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_iommu_tlbi @ 00104830 size=28
// signature: undefined __bpf_trace_iommu_tlbi(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_iommu_tlbi(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_iommu_pgtable @ 00104850 size=28
// signature: undefined __bpf_trace_iommu_pgtable(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_iommu_pgtable(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_iommu_map_pages @ 00104870 size=28
// signature: undefined __bpf_trace_iommu_map_pages(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_iommu_map_pages(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_map_sg @ 00104890 size=32
// signature: undefined __bpf_trace_map_sg(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_map_sg(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_tlbsync_timeout @ 001048b4 size=28
// signature: undefined __bpf_trace_tlbsync_timeout(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_tlbsync_timeout(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_smmu_init @ 001048d4 size=28
// signature: undefined __bpf_trace_smmu_init(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_smmu_init(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// arm_smmu_write_context_bank @ 001048f4 size=1544
// signature: undefined arm_smmu_write_context_bank(void)
// callers: [qcom_adreno_smmu_set_ttbr0_cfg, arm_smmu_device_reset, arm_smmu_attach_dev, __arm_smmu_sid_switch, arm_smmu_domain_free]
//------------------------------------------------------------

void arm_smmu_write_context_bank(long param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  
  lVar8 = *(long *)(param_1 + 0x50);
  puVar9 = (undefined8 *)(lVar8 + (long)param_2 * 0x30);
  lVar10 = puVar9[5];
  if (lVar10 == 0) {
    iVar3 = *(int *)(param_1 + 0x18) + param_2;
    if ((*(long *)(param_1 + 0x30) != 0) &&
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 != (code *)0x0)) {
      uVar5 = 0;
      goto LAB_00104eb4;
    }
    uVar4 = *(uint *)(param_1 + 0x1c);
    uVar5 = 0;
    goto LAB_00104cd0;
  }
  iVar1 = param_2 * 4;
  iVar3 = *(int *)(lVar10 + 0xc);
  if (*(int *)(param_1 + 0x28) != 0) {
    bVar2 = *(int *)(lVar10 + 0x10) == 1;
    uVar4 = (uint)bVar2;
    if ((*(byte *)(param_1 + 0x20) >> 6 & 1) != 0) {
      uVar4 = (uint)bVar2 | (uint)*(ushort *)(lVar10 + 2) << 0x10;
    }
    if ((*(long *)(param_1 + 0x30) == 0) ||
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
      writel_relaxed(uVar4,*(long *)(param_1 + 8) +
                           (long)(1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
                           (long)(iVar1 + 0x800));
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104d74);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,1);
    }
  }
  uVar4 = (*(uint *)(lVar10 + 0xc) & 3) << 0x10;
  if (*(uint *)(param_1 + 0x28) < 2) {
    uVar4 = uVar4 | (uint)*(byte *)(lVar10 + 1) << 0x18;
  }
  if (iVar3 == 0) {
    if ((*(byte *)(param_1 + 0x20) >> 6 & 1) == 0) {
      uVar6 = (uint)*(byte *)(lVar10 + 2);
      goto LAB_001049e4;
    }
  }
  else {
    uVar6 = 0xf300;
LAB_001049e4:
    uVar4 = uVar4 | uVar6;
  }
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(uVar4,*(long *)(param_1 + 8) +
                         (long)(1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)iVar1);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104d20);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,1,iVar1);
  }
  if ((iVar3 != 0) && (*(int *)(param_1 + 0x28) != 0)) {
    iVar1 = *(int *)(param_1 + 0x18) + param_2;
    if ((*(long *)(param_1 + 0x30) == 0) ||
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
      writel_relaxed(*(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x14),
                     *(long *)(param_1 + 8) +
                     (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x10);
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104ea4);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,iVar1,0x10);
    }
  }
  iVar1 = *(int *)(param_1 + 0x18) + param_2;
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(*(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x10),
                   *(long *)(param_1 + 8) +
                   (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x30);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104d4c);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,iVar1,0x30);
  }
  iVar1 = *(int *)(param_1 + 0x18) + param_2;
  if (*(int *)(lVar10 + 0x10) == 3) {
    if ((*(long *)(param_1 + 0x30) == 0) ||
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
      writel_relaxed(*(undefined2 *)(lVar10 + 2),
                     *(long *)(param_1 + 8) +
                     (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x34);
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104dfc);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,iVar1,0x34);
    }
    iVar1 = *(int *)(param_1 + 0x18) + param_2;
    if ((*(long *)(param_1 + 0x30) == 0) ||
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
      writel_relaxed(*(undefined4 *)puVar9,
                     *(long *)(param_1 + 8) +
                     (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x20);
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104e24);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,iVar1,0x20);
    }
    iVar1 = *(int *)(param_1 + 0x18) + param_2;
    if ((*(long *)(param_1 + 0x30) == 0) ||
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
      writel_relaxed(*(undefined4 *)(puVar9 + 1),
                     *(long *)(param_1 + 8) +
                     (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x28);
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104e4c);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,iVar1,0x28);
    }
    if (iVar3 != 0) {
LAB_00104bd0:
      iVar3 = *(int *)(param_1 + 0x18) + param_2;
      if ((*(long *)(param_1 + 0x30) == 0) ||
         (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
        writel_relaxed(*(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x18),
                       *(long *)(param_1 + 8) +
                       (long)(iVar3 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x38);
      }
      else {
        if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104dac);
          (*pcVar7)();
        }
        (*pcVar7)(param_1,iVar3,0x38);
      }
      iVar3 = *(int *)(param_1 + 0x18) + param_2;
      if ((*(long *)(param_1 + 0x30) == 0) ||
         (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar7 == (code *)0x0)) {
        writel_relaxed(*(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x1c),
                       *(long *)(param_1 + 8) +
                       (long)(iVar3 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x3c);
      }
      else {
        if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104dd4);
          (*pcVar7)();
        }
        (*pcVar7)(param_1,iVar3,0x3c);
      }
    }
  }
  else {
    if ((*(long *)(param_1 + 0x30) == 0) ||
       (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 0x18), pcVar7 == (code *)0x0)) {
      writeq_relaxed(*puVar9,*(long *)(param_1 + 8) +
                             (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x20);
    }
    else {
      if (*(int *)(pcVar7 + -4) != 0x6bc70ae0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104e78);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,iVar1,0x20);
    }
    if (iVar3 != 0) {
      iVar3 = *(int *)(param_1 + 0x18) + param_2;
      if ((*(long *)(param_1 + 0x30) == 0) ||
         (pcVar7 = *(code **)(*(long *)(param_1 + 0x30) + 0x18), pcVar7 == (code *)0x0)) {
        writeq_relaxed(puVar9[1],
                       *(long *)(param_1 + 8) +
                       (long)(iVar3 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 0x28);
      }
      else {
        if (*(int *)(pcVar7 + -4) != 0x6bc70ae0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104ef4);
          (*pcVar7)();
        }
        (*pcVar7)(param_1,iVar3,0x28);
      }
      goto LAB_00104bd0;
    }
  }
  lVar10 = *(long *)(param_1 + 0x30);
  if (lVar10 == 0) {
    iVar3 = *(int *)(param_1 + 0x18) + param_2;
    uVar5 = *(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x20);
  }
  else {
    pcVar7 = *(code **)(lVar10 + 0x90);
    if (pcVar7 != (code *)0x0) {
      if (*(int *)(pcVar7 + -4) != 0x3eaedfb5) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x104c8c);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,param_2,*(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x20));
      return;
    }
    pcVar7 = *(code **)(lVar10 + 8);
    iVar3 = *(int *)(param_1 + 0x18) + param_2;
    uVar5 = *(undefined4 *)(lVar8 + (long)param_2 * 0x30 + 0x20);
    if (pcVar7 != (code *)0x0) {
LAB_00104eb4:
      if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104ecc);
        (*pcVar7)();
      }
      (*pcVar7)(param_1,iVar3,0,uVar5);
      return;
    }
  }
  uVar4 = *(uint *)(param_1 + 0x1c);
LAB_00104cd0:
  writel_relaxed(uVar5,*(long *)(param_1 + 8) + (long)(iVar3 << (ulong)(uVar4 & 0x1f)));
  return;
}



//------------------------------------------------------------
// trace_raw_output_iommu_tlbi @ 00104f00 size=104
// signature: undefined trace_raw_output_iommu_tlbi(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_iommu_tlbi(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"group=%s\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_iommu_pgtable @ 00104f6c size=112
// signature: undefined trace_raw_output_iommu_pgtable(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_iommu_pgtable(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"group=%s table_base_iova=%lx table_ipa=%llx table_size=%zx\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_iommu_map_pages @ 00104fe0 size=116
// signature: undefined trace_raw_output_iommu_map_pages(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_iommu_map_pages(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"group=%s iova=%lx size=%zx pgsize=%zx pgcount=%zx\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(long *)(lVar2 + 0x20) * *(long *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_map_sg @ 00105058 size=108
// signature: undefined trace_raw_output_map_sg(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_map_sg(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"group=%s iova=%lx size=%lx\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_tlbsync_timeout @ 001050c8 size=104
// signature: undefined trace_raw_output_tlbsync_timeout(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_tlbsync_timeout(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"smmu=%s\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_smmu_init @ 00105134 size=100
// signature: undefined trace_raw_output_smmu_init(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_smmu_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"ARM SMMU init latency: %lld us\n",*(undefined8 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00105198 size=132
// signature: undefined writel_relaxed(void)
// callers: [arm_smmu_test_smr_masks, arm_smmu_tlb_inv_context_s2, arm_smmu_context_fault, arm_smmu_release_device, arm_smmu_tlb_inv_context_s1, __arm_smmu_sid_switch, arm_smmu_write_s2cr, arm_smmu_tlb_add_page_s2_v1, arm_smmu_rmr_install_bypass_smr, arm_smmu_global_fault, __arm_smmu_iova_to_phys_hard, arm_smmu_device_reset, arm_smmu_enable_s1_translation, arm_smmu_tlb_inv_range_s1, arm_smmu_tlb_inv_range_s2, arm_smmu_device_shutdown, arm_smmu_master_alloc_smes, __arm_smmu_tlb_sync, arm_smmu_write_context_bank]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1051b0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1051ec,uVar1);
  return;
}



//------------------------------------------------------------
// writeq_relaxed @ 0010521c size=124
// signature: undefined writeq_relaxed(void)
// callers: [__arm_smmu_iova_to_phys_hard, arm_smmu_tlb_inv_range_s1, arm_smmu_tlb_inv_range_s2, arm_smmu_write_context_bank]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x105268,uVar1);
  return;
}



//------------------------------------------------------------
// arm_smmu_device_probe @ 0010529c size=1564
// signature: undefined arm_smmu_device_probe(void)
// callers: []
//------------------------------------------------------------

ulong arm_smmu_device_probe(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  undefined8 *puVar12;
  ulong uVar13;
  char *pcVar14;
  undefined1 *puVar15;
  code *pcVar16;
  uint local_64;
  long *local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_60 = (long *)0x0;
  local_64 = 0;
  uVar7 = qcom_dma_iommu_is_ready();
  if ((uVar7 & 1) == 0) {
    uVar7 = 0xfffffdfb;
    goto LAB_001057f8;
  }
  lVar1 = param_1 + 0x10;
  plVar8 = (long *)devm_kmalloc(lVar1,0x140,0xdc0);
  if (plVar8 == (long *)0x0) {
    _dev_err(lVar1,"failed to allocate arm_smmu_device\n");
    uVar7 = 0xfffffff4;
    goto LAB_001057f8;
  }
  lVar9 = *(long *)(param_1 + 0x2f8);
  *plVar8 = lVar1;
  if (lVar9 == 0) {
    uVar7 = 0xffffffed;
    goto LAB_001057f8;
  }
  iVar4 = of_property_read_variable_u32_array(lVar9,"#global-interrupts",&local_64,1,0);
  if (iVar4 < 0) {
    uVar13 = dev_err_probe(lVar1,0xffffffed,"missing #global-interrupts property\n");
    uVar7 = uVar13 & 0xffffffff;
    if ((int)uVar13 != 0) goto LAB_001057f8;
  }
  else {
    puVar10 = (undefined4 *)of_device_get_match_data(lVar1);
    *(undefined4 *)(plVar8 + 5) = *puVar10;
    uVar11 = *(undefined8 *)(param_1 + 0x2f8);
    *(undefined4 *)((long)plVar8 + 0x2c) = puVar10[1];
    lVar9 = of_find_property(uVar11,"mmu-masters",0);
    if (lVar9 == 0) {
      if (using_legacy_binding == 1) goto LAB_00105654;
      puVar15 = &using_generic_binding;
    }
    else {
      if ((using_generic_binding & 1) != 0) {
LAB_00105654:
        _dev_err(lVar1,"not probing due to mismatched DT properties\n");
        uVar7 = 0xffffffed;
        goto LAB_001057f8;
      }
      puVar15 = &using_legacy_binding;
      if ((using_legacy_binding & 1) == 0) {
        _printk(&DAT_00119a83,&DAT_00119423);
        puVar15 = &using_legacy_binding;
      }
    }
    uVar11 = *(undefined8 *)(param_1 + 0x2f8);
    *puVar15 = 1;
    uVar7 = of_dma_is_coherent(uVar11);
    if ((uVar7 & 1) != 0) {
      *(uint *)(plVar8 + 4) = *(uint *)(plVar8 + 4) | 1;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,fatal-asf",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 1;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,use-3-lvl-tables",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 4;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,no-asid-retention",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 8;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,disable-atos",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 0x10;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,context-fault-retry",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 0x20;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,multi-match-handoff-smr",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 0x40;
    }
    lVar9 = of_find_property(*(undefined8 *)(*plVar8 + 0x2e8),"qcom,ignore-numpagendxb",0);
    if (lVar9 != 0) {
      *(uint *)((long)plVar8 + 0x24) = *(uint *)((long)plVar8 + 0x24) | 0x80;
    }
  }
  uVar7 = devm_platform_get_and_ioremap_resource(param_1,0,&local_60);
  plVar8[1] = uVar7;
  if (0xfffffffffffff000 < uVar7) goto LAB_001057f8;
  plVar8[2] = *local_60;
  *(int *)(plVar8 + 3) = ((int)local_60[1] - (int)*local_60) + 1;
  puVar12 = (undefined8 *)arm_smmu_impl_init(plVar8);
  if ((undefined8 *)0xfffffffffffff000 < puVar12) {
    uVar7 = (ulong)puVar12 & 0xffffffff;
    goto LAB_001057f8;
  }
  uVar5 = platform_irq_count(param_1);
  uVar3 = uVar5 - local_64;
  *(uint *)(puVar12 + 0x19) = uVar3;
  if ((int)uVar3 < 1) {
    iVar4 = local_64 + 1;
    pcVar14 = "found %d interrupts but expected at least %d\n";
    iVar6 = -0x13;
LAB_0010562c:
    uVar7 = dev_err_probe(lVar1,iVar6,pcVar14,uVar5,iVar4);
    uVar7 = uVar7 & 0xffffffff;
    goto LAB_001057f8;
  }
  lVar9 = devm_kmalloc(lVar1,(ulong)uVar3 << 2,0xdc0);
  puVar12[0x1a] = lVar9;
  if (lVar9 == 0) {
    uVar7 = dev_err_probe(lVar1,0xfffffff4,"failed to allocate %d irqs\n");
    uVar7 = uVar7 & 0xffffffff;
    goto LAB_001057f8;
  }
  if (0 < *(int *)(puVar12 + 0x19)) {
    lVar9 = 0;
    do {
      uVar13 = platform_get_irq(param_1,(int)lVar9 + local_64);
      uVar7 = uVar13 & 0xffffffff;
      if ((int)uVar13 < 0) {
        _dev_err(lVar1,"failed to get irq index %d, error: %d\n",local_64 + (int)lVar9,uVar7);
        goto LAB_001057f8;
      }
      *(int *)(puVar12[0x1a] + lVar9 * 4) = (int)uVar13;
      lVar9 = lVar9 + 1;
    } while (lVar9 < *(int *)(puVar12 + 0x19));
  }
  uVar7 = arm_smmu_init_power_resources(lVar1);
  puVar12[0x25] = uVar7;
  if (0xfffffffffffff000 < uVar7) {
    uVar7 = uVar7 & 0xffffffff;
    goto LAB_001057f8;
  }
  uVar13 = arm_smmu_power_on();
  uVar7 = uVar13 & 0xffffffff;
  if ((int)uVar13 != 0) goto LAB_001057f8;
  uVar13 = arm_smmu_device_cfg_probe(puVar12);
  uVar7 = uVar13 & 0xffffffff;
  if ((int)uVar13 == 0) {
    if (*(int *)(puVar12 + 5) == 2) {
      if (*(uint *)(puVar12 + 0x19) < *(uint *)(puVar12 + 7)) {
        _dev_err(lVar1,"found only %d context irq(s) but %d required\n");
        uVar7 = 0xffffffed;
        goto LAB_00105688;
      }
      *(uint *)(puVar12 + 0x19) = *(uint *)(puVar12 + 7);
    }
    if ((puVar12[6] == 0) || (pcVar16 = *(code **)(puVar12[6] + 0x70), pcVar16 == (code *)0x0)) {
      pcVar16 = arm_smmu_global_fault;
    }
    if (local_64 != 0) {
      uVar5 = 0;
      do {
        uVar13 = platform_get_irq(param_1,uVar5);
        uVar7 = uVar13 & 0xffffffff;
        iVar4 = (int)uVar13;
        if (iVar4 < 0) goto LAB_001057f8;
        iVar6 = devm_request_threaded_irq
                          (lVar1,uVar7,pcVar16,0,0x80,"arm-smmu global fault",puVar12);
        if (iVar6 != 0) {
          pcVar14 = "failed to request global IRQ %d (%u)\n";
          goto LAB_0010562c;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < local_64);
    }
    local_60 = (long *)platform_get_resource(param_1,0x200,0);
    if (local_60 == (long *)0x0) {
      _dev_err(lVar1,"Failed to get mem resource\n");
      uVar7 = 0xfffffffa;
    }
    else {
      puVar12[0x26] = *local_60;
      uVar13 = arm_smmu_handoff_cbs(puVar12);
      uVar7 = uVar13 & 0xffffffff;
      if ((int)uVar13 == 0) {
        puVar2 = puVar12 + 0x1d;
        uVar5 = iommu_device_sysfs_add(puVar2,*puVar12,0,"smmu.%pa",puVar12 + 2);
        if (uVar5 == 0) {
          uVar5 = iommu_device_register(puVar2,&PTR_arm_smmu_capable_00114c70,lVar1);
          if (uVar5 == 0) {
            *(undefined8 **)(param_1 + 0xa8) = puVar12;
            arm_smmu_rmr_install_bypass_smr(puVar12);
            arm_smmu_device_reset(puVar12);
            arm_smmu_test_smr_masks(puVar12);
            if (*(int *)(puVar12[0x25] + 0x20) != 0) {
              __pm_runtime_set_status(lVar1,0);
              pm_runtime_enable(lVar1);
            }
            uVar7 = 0;
            goto LAB_001057f8;
          }
          uVar7 = (ulong)uVar5;
          _dev_err(lVar1,"Failed to register iommu\n");
          iommu_device_sysfs_remove(puVar2);
        }
        else {
          uVar7 = (ulong)uVar5;
          _dev_err(lVar1,"Failed to register iommu in sysfs\n");
        }
      }
    }
  }
LAB_00105688:
  arm_smmu_power_off(puVar12,puVar12[0x25]);
LAB_001057f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// arm_smmu_device_remove @ 001058bc size=84
// signature: undefined arm_smmu_device_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_device_remove(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0xa8) == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    lVar1 = *(long *)(param_1 + 0xa8) + 0xe8;
    iommu_device_unregister(lVar1);
    iommu_device_sysfs_remove(lVar1);
    arm_smmu_device_shutdown(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// arm_smmu_device_shutdown @ 00105914 size=404
// signature: undefined arm_smmu_device_shutdown(void)
// callers: [arm_smmu_device_remove]
//------------------------------------------------------------

void arm_smmu_device_shutdown(long param_1)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  code *pcVar9;
  long *plVar10;
  
  plVar10 = *(long **)(param_1 + 0xa8);
  if (plVar10 != (long *)0x0) {
    lVar7 = _find_first_bit(plVar10 + 8,0x80);
    if (lVar7 == 0x80) {
      lVar7 = plVar10[6];
    }
    else {
      _dev_notice(param_1 + 0x10,"disabling translation\n");
      lVar7 = plVar10[6];
    }
    if ((lVar7 != 0) && (pcVar9 = *(code **)(lVar7 + 0x50), pcVar9 != (code *)0x0)) {
      if (*(int *)(pcVar9 + -4) != 0x59243587) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x105970);
        (*pcVar9)();
      }
      (*pcVar9)(plVar10);
    }
    lVar7 = *plVar10;
    if (((*(ushort *)(lVar7 + 0x200) & 7) == 0) && (iVar6 = __pm_runtime_resume(lVar7,4), iVar6 < 0)
       ) {
      piVar1 = (int *)(lVar7 + 0x1f8);
      iVar6 = *(int *)(lVar7 + 0x1f8);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar3 = *piVar1;
          if (iVar3 != iVar6) goto LAB_00105a3c;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = iVar6 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
LAB_00105a3c:
        bVar5 = iVar6 != iVar3;
        iVar6 = iVar3;
      } while (bVar5);
    }
    if ((plVar10[6] == 0) || (pcVar9 = *(code **)(plVar10[6] + 8), pcVar9 == (code *)0x0)) {
      writel_relaxed(1,plVar10[1]);
    }
    else {
      if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x105ab4);
        (*pcVar9)();
      }
      (*pcVar9)(plVar10,0,0,1);
    }
    lVar7 = *plVar10;
    uVar2 = *(ushort *)(lVar7 + 0x200);
    if ((uVar2 & 7) == 0) {
      uVar8 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar7 + 0x220) = uVar8;
      __pm_runtime_suspend(*plVar10,0xd);
      lVar7 = *plVar10;
      uVar2 = *(ushort *)(lVar7 + 0x200);
    }
    if ((uVar2 & 7) == 0) {
      pm_runtime_force_suspend(lVar7);
    }
    else {
      arm_smmu_power_off(plVar10,plVar10[0x25]);
    }
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_device_cfg_probe @ 00105abc size=1788
// signature: undefined arm_smmu_device_cfg_probe(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void arm_smmu_device_cfg_probe(long *param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined *puVar9;
  undefined4 uVar10;
  uint uVar11;
  code *pcVar12;
  uint uVar13;
  ulong uVar14;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  uVar4 = *(uint *)(param_1 + 4);
  local_40 = 0;
  _dev_notice(*param_1,"probing hardware configuration...\n");
  uVar10 = 1;
  if ((int)param_1[5] == 2) {
    uVar10 = 2;
  }
  _dev_notice(*param_1,"SMMUv%d with:\n",uVar10);
  if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
     (pcVar12 = *(code **)param_1[6], pcVar12 == (code *)0x0)) {
    uVar5 = readl_relaxed(param_1[1] + 0x20);
  }
  else {
    if (*(int *)(pcVar12 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x10614c);
      (*pcVar12)();
    }
    uVar5 = (*pcVar12)(param_1,0,0x20);
  }
  if (force_stage == 2) {
    uVar14 = (ulong)((uint)uVar5 & 0xafffffff);
LAB_00105b5c:
    if (((uint)uVar14 >> 0x1d & 1) == 0) goto LAB_00105b60;
LAB_00105e20:
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 8;
    _dev_notice(*param_1,"\tstage 2 translation\n");
    uVar11 = (uint)uVar14;
  }
  else {
    if (force_stage == 1) {
      uVar5 = (ulong)((uint)uVar5 & 0xcfffffff);
    }
    uVar14 = uVar5 & 0xffffffff;
    if (((uint)uVar5 >> 0x1e & 1) == 0) goto LAB_00105b5c;
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
    _dev_notice(*param_1,"\tstage 1 translation\n");
    if (((uint)uVar5 >> 0x1d & 1) != 0) goto LAB_00105e20;
LAB_00105b60:
    uVar11 = (uint)uVar14;
  }
  if ((uVar11 >> 0x1c & 1) != 0) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
    _dev_notice(*param_1,"\tnested translation\n");
  }
  if ((*(uint *)(param_1 + 4) & 0xc) == 0) {
    lVar6 = *param_1;
    pcVar8 = "\tno translation support!\n";
LAB_00105ed4:
    _dev_err(lVar6,pcVar8);
    uVar7 = 0xffffffed;
  }
  else {
    uVar4 = uVar4 & 1;
    uVar11 = (uint)uVar14;
    if (((uVar11 >> 0x1e & 1) == 0) || ((1 < *(uint *)(param_1 + 5) && ((uVar11 >> 0x1a & 1) != 0)))
       ) {
      if (uVar4 != 0) goto LAB_00105eb0;
LAB_00105b90:
      if ((uVar14 & 0x4000) != 0) {
        puVar9 = &DAT_001195d8;
        goto LAB_00105eb8;
      }
    }
    else {
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x20;
      _dev_notice(*param_1,"\taddress translation ops\n");
      if (uVar4 == 0) goto LAB_00105b90;
LAB_00105eb0:
      puVar9 = &DAT_00119084;
LAB_00105eb8:
      _dev_notice(*param_1,"\t%scoherent table walk\n",puVar9);
    }
    if (uVar4 != (uint)((uVar14 & 0x4000) >> 0xe)) {
      _dev_notice(*param_1,"\t(IDR0.CTTW overridden by FW configuration)\n");
    }
    if (((int)param_1[5] == 2) && ((uVar11 >> 8 & 1) != 0)) {
      uVar4 = 0x10000;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x1000;
    }
    else {
      uVar4 = 1 << (ulong)(uVar11 >> 9 & 0xf);
    }
    *(short *)(param_1 + 0xc) = (short)uVar4 + -1;
    if ((uVar11 >> 0x1b & 1) == 0) {
LAB_00105bdc:
      lVar6 = devm_kmalloc(*param_1,(ulong)uVar4 * 0x18,0xcc0);
      param_1[0xe] = lVar6;
      if (lVar6 != 0) {
        lVar6 = 0;
        uVar5 = (ulong)uVar4;
        do {
          puVar1 = (undefined8 *)(param_1[0xe] + lVar6);
          uVar10 = 1;
          if (disable_bypass != '\0') {
            uVar10 = 2;
          }
          lVar6 = lVar6 + 0x18;
          uVar5 = uVar5 - 1;
          *puVar1 = 0;
          *(undefined4 *)(puVar1 + 1) = 0;
          *(undefined4 *)((long)puVar1 + 0xc) = uVar10;
          puVar1[2] = 0;
        } while (uVar5 != 0);
        iVar3 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*param_1 + 0x2e8),"qcom,num-smr-override",
                           (long)&local_40 + 4,1,0);
        uVar2 = uVar4;
        if (local_40._4_4_ <= uVar4) {
          uVar2 = local_40._4_4_;
        }
        if (-1 < iVar3) {
          uVar4 = uVar2;
        }
        *(uint *)((long)param_1 + 0x5c) = uVar4;
        __mutex_init(param_1 + 0xf,"&smmu->stream_map_mutex",&arm_smmu_device_cfg_probe___key);
        *(undefined4 *)(param_1 + 0x1c) = 0;
        if ((*(uint *)(param_1 + 5) < 2) || ((uVar11 >> 0x19 & 1) == 0)) {
          uVar4 = *(uint *)(param_1 + 4);
          *(uint *)(param_1 + 4) = uVar4 | 0x400;
          if ((uVar11 >> 0x18 & 1) == 0) {
            *(uint *)(param_1 + 4) = uVar4 | 0xc00;
          }
        }
        if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
           (pcVar12 = *(code **)param_1[6], pcVar12 == (code *)0x0)) {
          uVar4 = readl_relaxed(param_1[1] + 0x24);
        }
        else {
          if (*(int *)(pcVar12 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x1061ac);
            (*pcVar12)();
          }
          uVar4 = (*pcVar12)(param_1,0,0x24);
        }
        uVar2 = uVar4 >> 0x1c & 7;
        uVar11 = 0xc;
        if ((int)uVar4 < 0) {
          uVar11 = 0x10;
        }
        uVar13 = 2 << (ulong)uVar2;
        *(uint *)((long)param_1 + 0x1c) = uVar11;
        if ((int)param_1[3] != (4 << (ulong)uVar2) << (ulong)uVar11) {
          _dev_warn(*param_1,
                    "SMMU address space size (0x%x) differs from mapped region size (0x%x)!\n");
        }
        if (*(char *)((long)param_1 + 0x24) < '\0') {
          uVar13 = (*(uint *)(param_1 + 3) >> 1) >> (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f);
        }
        *(uint *)(param_1 + 3) = uVar13;
        *(uint *)(param_1 + 7) = uVar4 & 0xff;
        *(uint *)((long)param_1 + 0x3c) = uVar4 >> 0x10 & 0xff;
        iVar3 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*param_1 + 0x2e8),"qcom,num-context-banks-override",
                           &local_40,1,0);
        uVar4 = *(uint *)(param_1 + 7);
        if ((-1 < iVar3) && ((uint)local_40 < uVar4)) {
          *(uint *)(param_1 + 7) = (uint)local_40;
          uVar4 = (uint)local_40;
        }
        lVar6 = *param_1;
        if (uVar4 < *(uint *)((long)param_1 + 0x3c)) {
          pcVar8 = "impossible number of S2 context banks!\n";
          goto LAB_00105ed4;
        }
        _dev_notice(lVar6,"\t%u context banks (%u stage-2 only)\n");
        lVar6 = devm_kmalloc(*param_1,(ulong)*(uint *)(param_1 + 7) * 0x30,0xdc0);
        param_1[10] = lVar6;
        if (lVar6 != 0) {
          uVar4 = arm_smmu_readl(param_1,0,0x28);
          if ((uVar4 & 0xf) < 5) {
            lVar6 = *(long *)(&DAT_00115eb8 + (ulong)(uVar4 & 0xf) * 8);
          }
          else {
            lVar6 = 0x30;
          }
          uVar11 = uVar4 >> 4 & 0xf;
          param_1[0x16] = lVar6;
          if (uVar11 < 5) {
            uVar5 = *(ulong *)(&DAT_00115eb8 + (ulong)uVar11 * 8);
          }
          else {
            uVar5 = 0x30;
          }
          param_1[0x17] = uVar5;
          if ((uVar4 >> 0xf & 1) != 0) {
            *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x40;
          }
          iVar3 = dma_set_mask_and_coherent(*param_1,~(-1L << (uVar5 & 0x3f)));
          if (iVar3 != 0) {
            _dev_warn(*param_1,"failed to set DMA mask for table walker\n");
          }
          if (*(uint *)(param_1 + 5) < 2) {
            param_1[0x15] = param_1[0x16];
            if (*(uint *)(param_1 + 5) == 1) {
LAB_00105ff4:
              *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x200;
            }
          }
          else {
            uVar11 = uVar4 >> 8 & 0xf;
            if (uVar11 < 5) {
              lVar6 = *(long *)(&DAT_00115eb8 + (ulong)uVar11 * 8);
            }
            else {
              lVar6 = 0x30;
            }
            param_1[0x15] = lVar6;
            if ((uVar4 >> 0xc & 1) != 0) {
              *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x80;
            }
            if ((uVar4 >> 0xd & 1) != 0) {
              *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x100;
            }
            if ((uVar4 >> 0xe & 1) != 0) goto LAB_00105ff4;
          }
          if ((param_1[6] != 0) && (pcVar12 = *(code **)(param_1[6] + 0x20), pcVar12 != (code *)0x0)
             ) {
            if (*(int *)(pcVar12 + -4) != -0x4c2d91e) {
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x10602c);
              (*pcVar12)();
            }
            uVar7 = (*pcVar12)(param_1);
            if ((int)uVar7 != 0) goto LAB_00105dc4;
          }
          uVar4 = *(uint *)(param_1 + 4);
          if ((uVar4 >> 0xb & 1) != 0) {
            param_1[0x18] = param_1[0x18] | 0x1111000;
          }
          if ((uVar4 & 0x480) != 0) {
            param_1[0x18] = param_1[0x18] | 0x40201000;
          }
          if ((uVar4 >> 8 & 1) != 0) {
            param_1[0x18] = param_1[0x18] | 0x2004000;
          }
          if ((uVar4 >> 9 & 1) != 0) {
            param_1[0x18] = param_1[0x18] | 0x20010000;
          }
          uVar5 = 0;
          if (_DAT_00114ce8 != 0xffffffffffffffff) {
            uVar5 = _DAT_00114ce8;
          }
          _DAT_00114ce8 = param_1[0x18] | uVar5;
          _dev_notice(*param_1,"\tSupported page sizes: 0x%08lx\n",param_1[0x18]);
          uVar4 = *(uint *)(param_1 + 4);
          if ((uVar4 >> 2 & 1) != 0) {
            _dev_notice(*param_1,"\tStage-1: %lu-bit VA -> %lu-bit IPA\n",param_1[0x15],
                        param_1[0x16]);
            uVar4 = *(uint *)(param_1 + 4);
          }
          if ((uVar4 >> 3 & 1) != 0) {
            _dev_notice(*param_1,"\tStage-2: %lu-bit IPA -> %lu-bit PA\n",param_1[0x16],
                        param_1[0x17]);
          }
          uVar7 = 0;
          goto LAB_00105dc4;
        }
      }
    }
    else {
      uVar4 = uVar11 & 0xff;
      lVar6 = *param_1;
      *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 2;
      if ((uVar14 & 0xff) == 0) {
        pcVar8 = "stream-matching supported, but no SMRs present!\n";
        goto LAB_00105ed4;
      }
      lVar6 = devm_kmalloc(lVar6,uVar4 << 3,0xdc0);
      param_1[0xd] = lVar6;
      if (lVar6 != 0) {
        _dev_notice(*param_1,"\tstream matching with %u register groups",uVar4);
        goto LAB_00105bdc;
      }
    }
    uVar7 = 0xfffffff4;
  }
LAB_00105dc4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_global_fault @ 001061bc size=720
// signature: undefined arm_smmu_global_fault(void)
// callers: []
//------------------------------------------------------------

undefined4 arm_smmu_global_fault(undefined8 param_1,long *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined8 uVar10;
  code *pcVar11;
  long lVar12;
  
  lVar12 = *param_2;
  if (((*(ushort *)(lVar12 + 0x200) & 7) == 0) && (iVar5 = __pm_runtime_resume(lVar12,4), iVar5 < 0)
     ) {
    piVar1 = (int *)(lVar12 + 0x1f8);
    iVar5 = *(int *)(lVar12 + 0x1f8);
    do {
      if (iVar5 == 0) {
        return 0;
      }
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar5) goto LAB_001062e8;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar5 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_001062e8:
      bVar4 = iVar5 == iVar2;
      iVar5 = iVar2;
      if (bVar4) {
        return 0;
      }
    } while( true );
  }
  if (((undefined8 *)param_2[6] == (undefined8 *)0x0) ||
     (pcVar11 = *(code **)param_2[6], pcVar11 == (code *)0x0)) {
    uVar6 = readl_relaxed(param_2[1] + 0x48);
  }
  else {
    if (*(int *)(pcVar11 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x106398);
      (*pcVar11)();
    }
    uVar6 = (*pcVar11)(param_2,0,0x48);
  }
  if (((undefined8 *)param_2[6] == (undefined8 *)0x0) ||
     (pcVar11 = *(code **)param_2[6], pcVar11 == (code *)0x0)) {
    uVar7 = readl_relaxed(param_2[1] + 0x50);
  }
  else {
    if (*(int *)(pcVar11 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1063c4);
      (*pcVar11)();
    }
    uVar7 = (*pcVar11)(param_2,0,0x50);
  }
  if (((undefined8 *)param_2[6] == (undefined8 *)0x0) ||
     (pcVar11 = *(code **)param_2[6], pcVar11 == (code *)0x0)) {
    uVar8 = readl_relaxed(param_2[1] + 0x54);
  }
  else {
    if (*(int *)(pcVar11 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1063f0);
      (*pcVar11)();
    }
    uVar8 = (*pcVar11)(param_2,0,0x54);
  }
  if (((undefined8 *)param_2[6] == (undefined8 *)0x0) ||
     (pcVar11 = *(code **)param_2[6], pcVar11 == (code *)0x0)) {
    uVar9 = readl_relaxed(param_2[1] + 0x58);
  }
  else {
    if (*(int *)(pcVar11 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10641c);
      (*pcVar11)();
    }
    uVar9 = (*pcVar11)(param_2,0,0x58);
  }
  if (uVar6 == 0) {
    lVar12 = *param_2;
    uVar7 = 0;
    goto LAB_0010642c;
  }
  iVar5 = ___ratelimit(arm_smmu_global_fault_rs,"arm_smmu_global_fault");
  if (iVar5 == 0) {
    lVar12 = param_2[6];
    if (lVar12 == 0) goto LAB_001062a4;
LAB_0010629c:
    pcVar11 = *(code **)(lVar12 + 8);
    if (pcVar11 == (code *)0x0) goto LAB_001062a4;
    if (*(int *)(pcVar11 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x106490);
      (*pcVar11)();
    }
    (*pcVar11)(param_2,0,0x48,uVar6);
  }
  else {
    if ((uVar6 >> 1 & 1) == 0) {
      _dev_err(*param_2,"Unexpected global fault, this could be serious\n");
    }
    else {
      _dev_err(*param_2,
               "Blocked unknown Stream ID 0x%hx; boot with \"arm-smmu.disable_bypass=0\" to allow, but this may have security implications\n"
               ,uVar8 & 0xffff);
    }
    _dev_err(*param_2,"\tGFSR 0x%08x, GFSYNR0 0x%08x, GFSYNR1 0x%08x, GFSYNR2 0x%08x\n",uVar6,uVar7,
             uVar8,uVar9);
    lVar12 = param_2[6];
    if (lVar12 != 0) goto LAB_0010629c;
LAB_001062a4:
    writel_relaxed(uVar6,param_2[1] + 0x48);
  }
  lVar12 = *param_2;
  uVar7 = 1;
LAB_0010642c:
  if ((*(ushort *)(lVar12 + 0x200) & 7) == 0) {
    uVar10 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar12 + 0x220) = uVar10;
    __pm_runtime_suspend(*param_2,0xd);
  }
  return uVar7;
}



//------------------------------------------------------------
// arm_smmu_handoff_cbs @ 001064a0 size=920
// signature: undefined arm_smmu_handoff_cbs(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

undefined8 arm_smmu_handoff_cbs(long *param_1)

{
  undefined2 *puVar1;
  long lVar2;
  undefined4 uVar3;
  int iVar4;
  byte bVar5;
  byte bVar6;
  uint uVar7;
  bool bVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  code *pcVar14;
  ulong uVar15;
  uint uVar16;
  ulong uVar17;
  char *pcVar18;
  undefined1 uVar19;
  
  lVar12 = of_get_property(*(undefined8 *)(*param_1 + 0x2e8),"qcom,handoff-smrs",0);
  if ((lVar12 != 0) &&
     (uVar9 = of_property_count_elems_of_size
                        (*(undefined8 *)(*param_1 + 0x2e8),"qcom,handoff-smrs",8), -1 < (int)uVar9))
  {
    uVar17 = (ulong)uVar9 * 8;
    lVar13 = __kmalloc(uVar17,0xdc0);
    if (lVar13 == 0) {
      return 0xfffffff4;
    }
    bVar8 = uVar9 == 0;
    if (uVar9 == 0) {
      bVar8 = true;
      iVar4 = *(int *)((long)param_1 + 0x5c);
    }
    else {
      uVar15 = 0;
      do {
        if (uVar17 < uVar15 + 2) {
LAB_00106834:
                    /* WARNING: Does not return */
          pcVar14 = (code *)SoftwareBreakpoint(1,0x106838);
          (*pcVar14)();
        }
        uVar3 = *(undefined4 *)(lVar12 + uVar15);
        *(ushort *)(lVar13 + uVar15 + 2) =
             (ushort)(byte)((uint)uVar3 >> 0x18) | (ushort)((uint)uVar3 >> 8) & 0xff00;
        if ((uVar17 <= uVar15) ||
           (uVar3 = ((undefined4 *)(lVar12 + uVar15))[1],
           *(ushort *)(lVar13 + uVar15) =
                (ushort)(byte)((uint)uVar3 >> 0x18) | (ushort)((uint)uVar3 >> 8) & 0xff00,
           uVar17 < uVar15 + 4)) goto LAB_00106834;
        lVar2 = lVar13 + uVar15;
        *(undefined1 *)(lVar2 + 4) = 1;
        if (uVar17 < uVar15 + 6) goto LAB_00106834;
        uVar15 = uVar15 + 8;
        *(undefined1 *)(lVar2 + 6) = 1;
      } while (uVar17 != uVar15);
      iVar4 = *(int *)((long)param_1 + 0x5c);
    }
    if (iVar4 != 0) {
      uVar16 = 0;
      do {
        iVar4 = uVar16 * 4;
        if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
           (pcVar14 = *(code **)param_1[6], pcVar14 == (code *)0x0)) {
          uVar10 = readl_relaxed(param_1[1] + (long)(iVar4 + 0x800));
        }
        else {
          if (*(int *)(pcVar14 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x1067a8);
            (*pcVar14)();
          }
          uVar10 = (*pcVar14)(param_1,0);
        }
        if ((*(byte *)((long)param_1 + 0x21) >> 4 & 1) == 0) {
          if ((int)uVar10 < 0) {
            uVar7 = uVar10 >> 0x10 & 0x7fff;
            uVar19 = 1;
            goto joined_r0x00106660;
          }
        }
        else {
          if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
             (pcVar14 = *(code **)param_1[6], pcVar14 == (code *)0x0)) {
            uVar11 = readl_relaxed(param_1[1] + (long)(iVar4 + 0xc00));
          }
          else {
            if (*(int *)(pcVar14 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x1067d0);
              (*pcVar14)();
            }
            uVar11 = (*pcVar14)(param_1,0);
          }
          if ((uVar11 >> 10 & 1) != 0) {
            uVar7 = uVar10 >> 0x10;
            uVar19 = (undefined1)((uVar11 & 0x400) >> 10);
joined_r0x00106660:
            if (!bVar8) {
              uVar17 = 0;
              pcVar18 = (char *)(lVar13 + 4);
              do {
                if (((*pcVar18 != '\0') && ((uVar7 & (*(ushort *)(pcVar18 + -4) ^ 0xffffffff)) == 0)
                    ) && ((((uint)*(ushort *)(pcVar18 + -2) ^ uVar10 & 0xffff) &
                          (*(ushort *)(pcVar18 + -4) ^ 0xffffffff)) == 0)) {
                  if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
                     (pcVar14 = *(code **)param_1[6], pcVar14 == (code *)0x0)) {
                    uVar11 = readl_relaxed(param_1[1] + (long)(iVar4 + 0xc00));
                  }
                  else {
                    if (*(int *)(pcVar14 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                      pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x1067fc);
                      (*pcVar14)();
                    }
                    uVar11 = (*pcVar14)(param_1,0);
                  }
                  puVar1 = (undefined2 *)(param_1[0xd] + (ulong)uVar16 * 8);
                  *puVar1 = (short)uVar7;
                  puVar1[1] = (short)uVar10;
                  *(undefined1 *)(puVar1 + 2) = uVar19;
                  *(undefined2 *)((long)puVar1 + 5) = 0x100;
                  *(undefined1 *)((long)puVar1 + 7) = 0;
                  lVar12 = ((ulong)uVar16 + (ulong)uVar16 * 2) * 8;
                  *(undefined8 *)(param_1[0xe] + lVar12) = 0;
                  *(undefined4 *)(param_1[0xe] + lVar12 + 8) = 0;
                  *(uint *)(param_1[0xe] + lVar12 + 0xc) = uVar11 >> 0x10 & 3;
                  *(uint *)(param_1[0xe] + lVar12 + 0x10) = uVar11 >> 0x18 & 3;
                  *(char *)(param_1[0xe] + lVar12 + 0x14) = (char)uVar11;
                  *(undefined1 *)(param_1[0xe] + lVar12 + 0x15) = 1;
                  bVar5 = *(byte *)(param_1[0xe] + lVar12 + 0x14);
                  uVar15 = (ulong)(bVar5 >> 3) & 0x18;
                  bVar6 = *(byte *)((long)param_1 + 0x24);
                  *(ulong *)((long)param_1 + uVar15 + 0x40) =
                       1L << ((ulong)bVar5 & 0x3f) | *(ulong *)((long)param_1 + uVar15 + 0x40);
                  if ((bVar6 >> 6 & 1) == 0) {
                    *pcVar18 = '\0';
                    *(undefined1 *)(lVar13 + (uVar17 & 0xffffffff) * 8 + 6) = 0;
                  }
                  break;
                }
                uVar17 = uVar17 + 1;
                pcVar18 = pcVar18 + 8;
              } while (uVar9 != uVar17);
            }
          }
        }
        uVar16 = uVar16 + 1;
      } while (uVar16 < *(uint *)((long)param_1 + 0x5c));
    }
    kfree(lVar13);
  }
  return 0;
}



//------------------------------------------------------------
// arm_smmu_rmr_install_bypass_smr @ 00106838 size=604
// signature: undefined arm_smmu_rmr_install_bypass_smr(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

void arm_smmu_rmr_install_bypass_smr(undefined8 *param_1)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  code *pcVar7;
  undefined8 ****ppppuVar8;
  ulong uVar9;
  ulong uVar10;
  long lVar11;
  uint uVar12;
  long lVar13;
  undefined8 ****local_38;
  undefined8 ****local_30;
  long local_28;
  
  lVar11 = sp_el0;
  local_38 = &local_38;
  local_28 = *(long *)(lVar11 + 0x638);
  local_30 = local_38;
  dev_fwnode(*param_1);
  if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
     (pcVar7 = *(code **)param_1[6], pcVar7 == (code *)0x0)) {
    uVar3 = readl_relaxed(param_1[1]);
  }
  else {
    if (*(int *)(pcVar7 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106a5c);
      (*pcVar7)();
    }
    uVar3 = (*pcVar7)(param_1,0,0);
  }
  if ((param_1[6] == 0) || (pcVar7 = *(code **)(param_1[6] + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(uVar3 | 1,param_1[1]);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106a88);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,0,0);
  }
  puVar6 = &DAT_00118a71;
  iVar5 = 0;
  ppppuVar8 = local_38;
  if ((undefined8 *****)local_38 != &local_38) {
    do {
      uVar3 = *(uint *)(ppppuVar8 + 7);
      if (uVar3 != 0) {
        uVar9 = 0;
        do {
          uVar2 = *(ushort *)
                   ((long)ppppuVar8[6] + (-(uVar9 >> 0x1f) & 0xfffffffc00000000 | uVar9 << 2));
          uVar10 = (ulong)uVar2;
          lVar11 = param_1[0xd];
          if (lVar11 == 0) {
LAB_001068ec:
            lVar13 = param_1[0xe];
            iVar4 = *(int *)(lVar13 + uVar10 * 0x18 + 8);
            if (iVar4 == 0) {
              lVar13 = uVar10 * 8;
              *(ushort *)(lVar11 + lVar13 + 2) = uVar2;
              *(undefined2 *)(param_1[0xd] + lVar13) = 0;
              *(undefined1 *)(param_1[0xd] + lVar13 + 4) = 1;
              *(undefined1 *)(param_1[0xd] + lVar13 + 6) = 1;
              lVar13 = param_1[0xe];
              iVar4 = *(int *)(lVar13 + uVar10 * 0x18 + 8);
            }
            lVar11 = uVar10 * 0x18;
            iVar5 = iVar5 + 1;
            *(int *)(lVar13 + lVar11 + 8) = iVar4 + 1;
            *(undefined4 *)(param_1[0xe] + lVar11 + 0xc) = 1;
            *(undefined4 *)(param_1[0xe] + lVar11 + 0x10) = 0;
            uVar3 = *(uint *)(ppppuVar8 + 7);
          }
          else if (*(uint *)((long)param_1 + 0x5c) != 0) {
            uVar12 = 0;
            uVar10 = 0xffffffe4;
            do {
              if (*(char *)(lVar11 + (long)(int)uVar12 * 8 + 6) != '\0') {
                uVar10 = (ulong)uVar12;
                if (*(short *)(lVar11 + (long)(int)uVar12 * 8) != -1) goto LAB_00106934;
                break;
              }
              uVar1 = uVar12;
              if (-1 < (int)(uint)uVar10) {
                uVar1 = (uint)uVar10;
              }
              uVar10 = (ulong)uVar1;
              uVar12 = uVar12 + 1;
            } while (*(uint *)((long)param_1 + 0x5c) != uVar12);
            if (-1 < (int)uVar10) goto LAB_001068ec;
          }
LAB_00106934:
          uVar12 = (int)uVar9 + 1;
          uVar9 = (ulong)uVar12;
        } while (uVar12 < uVar3);
      }
      ppppuVar8 = (undefined8 ****)*ppppuVar8;
    } while ((undefined8 *****)ppppuVar8 != &local_38);
    puVar6 = &DAT_00119084;
    if (iVar5 != 1) {
      puVar6 = &DAT_00118a71;
    }
  }
  _dev_notice(*param_1,"\tpreserved %d boot mapping%s\n",iVar5,puVar6);
  dev_fwnode(*param_1);
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_device_reset @ 00106a94 size=1092
// signature: undefined arm_smmu_device_reset(void)
// callers: [arm_smmu_device_probe, arm_smmu_pm_resume, arm_smmu_pm_restore_early]
//------------------------------------------------------------

void arm_smmu_device_reset(undefined8 *param_1)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  code *pcVar7;
  long lVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
     (pcVar7 = *(code **)param_1[6], pcVar7 == (code *)0x0)) {
    uVar3 = readl_relaxed(param_1[1] + 0x48);
  }
  else {
    if (*(int *)(pcVar7 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106dd8);
      (*pcVar7)();
    }
    uVar3 = (*pcVar7)(param_1,0,0x48);
  }
  if ((param_1[6] == 0) || (pcVar7 = *(code **)(param_1[6] + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(uVar3,param_1[1] + 0x48);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106e04);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,0,0x48);
  }
  mutex_lock(param_1 + 0xf);
  if (*(int *)((long)param_1 + 0x5c) != 0) {
    uVar4 = 0;
    iVar5 = 0x800;
    do {
      arm_smmu_write_s2cr(param_1,uVar4);
      lVar8 = param_1[0xd];
      if (lVar8 != 0) {
        puVar1 = (undefined2 *)(lVar8 + (long)(int)uVar4 * 8);
        uVar10 = CONCAT22(*puVar1,puVar1[1]);
        if (((*(byte *)((long)param_1 + 0x21) >> 4 & 1) == 0) &&
           (*(char *)(lVar8 + (long)(int)uVar4 * 8 + 4) != '\0')) {
          uVar10 = uVar10 | 0x80000000;
        }
        if ((param_1[6] == 0) || (pcVar7 = *(code **)(param_1[6] + 8), pcVar7 == (code *)0x0)) {
          writel_relaxed(uVar10,param_1[1] + (long)iVar5);
        }
        else {
          if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106bac);
            (*pcVar7)();
          }
          (*pcVar7)(param_1,0,iVar5);
        }
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar4 < *(uint *)((long)param_1 + 0x5c));
  }
  mutex_unlock(param_1 + 0xf);
  if (*(int *)(param_1 + 7) != 0) {
    uVar4 = 0;
    do {
      arm_smmu_write_context_bank(param_1,uVar4);
      if ((param_1[6] == 0) || (pcVar7 = *(code **)(param_1[6] + 8), pcVar7 == (code *)0x0)) {
        writel_relaxed(0xc00001fe,
                       param_1[1] +
                       (long)(int)(uVar4 + *(int *)(param_1 + 3) <<
                                  (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f)) + 0x58);
      }
      else {
        if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106c48);
          (*pcVar7)();
        }
        (*pcVar7)(param_1,uVar4 + *(int *)(param_1 + 3),0x58,0xc00001fe);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 7));
  }
  if ((param_1[6] == 0) || (pcVar7 = *(code **)(param_1[6] + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(0xffffffff,param_1[1] + 0x6c);
    lVar8 = param_1[6];
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106e34);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,0,0x6c,0xffffffff);
    lVar8 = param_1[6];
  }
  if ((lVar8 == 0) || (pcVar7 = *(code **)(lVar8 + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(0xffffffff,param_1[1] + 0x68);
    puVar9 = (undefined8 *)param_1[6];
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106e6c);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,0,0x68,0xffffffff);
    puVar9 = (undefined8 *)param_1[6];
  }
  if ((puVar9 == (undefined8 *)0x0) || (pcVar7 = (code *)*puVar9, pcVar7 == (code *)0x0)) {
    uVar4 = readl_relaxed(param_1[1]);
  }
  else {
    if (*(int *)(pcVar7 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106ea0);
      (*pcVar7)();
    }
    uVar4 = (*pcVar7)(param_1,0,0);
  }
  uVar2 = *(uint *)(param_1 + 4);
  uVar10 = 0x1836;
  if (disable_bypass != '\0') {
    uVar10 = 0x1c36;
  }
  if ((param_1[6] != 0) && (pcVar7 = *(code **)(param_1[6] + 0x28), pcVar7 != (code *)0x0)) {
    if (*(int *)(pcVar7 + -4) != -0x4c2d91e) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106d0c);
      (*pcVar7)();
    }
    (*pcVar7)(param_1);
  }
  uVar4 = uVar4 & 0xff3f03c8 | uVar10 | (uVar2 & 0x40) << 0x19 | uVar2 >> 9 & 8 | 0xc00000;
  uVar6 = _raw_spin_lock_irqsave(param_1 + 0x1c);
  iVar5 = __arm_smmu_tlb_sync(param_1,0,0x70,0x74);
  if ((iVar5 != 0) &&
     (iVar5 = ___ratelimit(arm_smmu_tlb_sync_global__rs,"arm_smmu_tlb_sync_global"), iVar5 != 0)) {
    _dev_err(*param_1,"TLB global sync failed!\n");
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x1c,uVar6);
  if ((param_1[6] == 0) || (pcVar7 = *(code **)(param_1[6] + 8), pcVar7 == (code *)0x0)) {
    writel_relaxed(uVar4,param_1[1]);
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x106ed0);
      (*pcVar7)();
    }
    (*pcVar7)(param_1,0,0,uVar4);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_test_smr_masks @ 00106ed8 size=424
// signature: undefined arm_smmu_test_smr_masks(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

void arm_smmu_test_smr_masks(long param_1)

{
  ushort uVar1;
  undefined2 extraout_var;
  undefined2 uVar2;
  undefined2 extraout_var_00;
  code *pcVar3;
  undefined8 *puVar4;
  int iVar5;
  int iVar6;
  
  if ((*(long *)(param_1 + 0x68) != 0) && (*(int *)(param_1 + 0x5c) != 0)) {
    iVar5 = 0;
    iVar6 = 0x800;
    do {
      if (*(char *)(*(long *)(param_1 + 0x68) + (long)iVar5 * 8 + 4) == '\0') {
        if ((*(long *)(param_1 + 0x30) == 0) ||
           (pcVar3 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar3 == (code *)0x0)) {
          writel_relaxed(*(undefined2 *)(param_1 + 0x60),*(long *)(param_1 + 8) + (long)iVar6);
          puVar4 = *(undefined8 **)(param_1 + 0x30);
        }
        else {
          if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106fe4);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,0,iVar6);
          puVar4 = *(undefined8 **)(param_1 + 0x30);
        }
        if ((puVar4 == (undefined8 *)0x0) || (pcVar3 = (code *)*puVar4, pcVar3 == (code *)0x0)) {
          uVar1 = readl_relaxed(*(long *)(param_1 + 8) + (long)iVar6);
        }
        else {
          if (*(int *)(pcVar3 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107018);
            (*pcVar3)();
          }
          uVar1 = (*pcVar3)(param_1,0,iVar6);
        }
        *(ushort *)(param_1 + 0x60) = uVar1;
        if ((*(long *)(param_1 + 0x30) == 0) ||
           (pcVar3 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar3 == (code *)0x0)) {
          writel_relaxed((uint)uVar1 << 0x10,*(long *)(param_1 + 8) + (long)iVar6);
          puVar4 = *(undefined8 **)(param_1 + 0x30);
        }
        else {
          if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107044);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,0,iVar6);
          puVar4 = *(undefined8 **)(param_1 + 0x30);
        }
        if ((puVar4 == (undefined8 *)0x0) || (pcVar3 = (code *)*puVar4, pcVar3 == (code *)0x0)) {
          readl_relaxed(*(long *)(param_1 + 8) + (long)iVar6);
          uVar2 = extraout_var;
        }
        else {
          if (*(int *)(pcVar3 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107078);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,0,iVar6);
          uVar2 = extraout_var_00;
        }
        *(undefined2 *)(param_1 + 0x62) = uVar2;
        return;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 4;
    } while (*(int *)(param_1 + 0x5c) != iVar5);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_readl @ 00107080 size=96
// signature: undefined arm_smmu_readl(void)
// callers: [arm_smmu_device_cfg_probe]
//------------------------------------------------------------

void arm_smmu_readl(long param_1,int param_2,int param_3)

{
  code *pcVar1;
  
  if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
     (pcVar1 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar1 == (code *)0x0)) {
    readl_relaxed(*(long *)(param_1 + 8) +
                  (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)param_3);
  }
  else {
    if (*(int *)(pcVar1 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1070d8);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// dma_set_mask_and_coherent @ 001070e0 size=76
// signature: undefined dma_set_mask_and_coherent(void)
// callers: [arm_smmu_device_cfg_probe]
//------------------------------------------------------------

int dma_set_mask_and_coherent(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = dma_set_mask();
  if (iVar1 == 0) {
    dma_set_coherent_mask(param_1,param_2);
  }
  return iVar1;
}



//------------------------------------------------------------
// readl_relaxed @ 0010712c size=124
// signature: undefined readl_relaxed(void)
// callers: [arm_smmu_test_smr_masks, arm_smmu_rmr_install_bypass_smr, arm_smmu_readl, arm_smmu_global_fault, arm_smmu_device_reset, arm_smmu_device_cfg_probe, arm_smmu_context_fault, arm_smmu_handoff_cbs, arm_smmu_get_fault_ids, __arm_smmu_tlb_sync]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x107174,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// arm_smmu_rpm_get @ 001071a8 size=136
// signature: undefined arm_smmu_rpm_get(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

void arm_smmu_rpm_get(long *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  
  lVar6 = *param_1;
  if (((*(ushort *)(lVar6 + 0x200) & 7) == 0) && (iVar5 = __pm_runtime_resume(lVar6,4), iVar5 < 0))
  {
    piVar1 = (int *)(lVar6 + 0x1f8);
    iVar5 = *(int *)(lVar6 + 0x1f8);
    do {
      if (iVar5 == 0) {
        return;
      }
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar5) goto LAB_00107210;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar5 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_00107210:
      bVar4 = iVar5 != iVar2;
      iVar5 = iVar2;
    } while (bVar4);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_rpm_put @ 00107244 size=72
// signature: undefined arm_smmu_rpm_put(void)
// callers: [arm_smmu_probe_device]
//------------------------------------------------------------

void arm_smmu_rpm_put(long *param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *param_1;
  if ((*(ushort *)(lVar2 + 0x200) & 7) == 0) {
    uVar1 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar2 + 0x220) = uVar1;
    __pm_runtime_suspend(*param_1,0xd);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_iova_to_phys_hard @ 00107290 size=328
// signature: undefined arm_smmu_iova_to_phys_hard(void)
// callers: [arm_smmu_context_fault]
//------------------------------------------------------------

undefined8 arm_smmu_iova_to_phys_hard(long param_1,undefined8 *param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  code *pcVar8;
  long *plVar9;
  long lVar10;
  long *plVar11;
  
  plVar9 = (long *)(param_1 + -0xc0);
  plVar11 = (long *)*plVar9;
  if ((*(byte *)((long)plVar11 + 0x24) >> 4 & 1) != 0) {
    return 0;
  }
  lVar10 = *plVar11;
  if (((*(ushort *)(lVar10 + 0x200) & 7) != 0) ||
     (iVar5 = __pm_runtime_resume(lVar10,4), -1 < iVar5)) {
    if ((plVar11[6] == 0) || (pcVar8 = *(code **)(plVar11[6] + 0x40), pcVar8 == (code *)0x0)) {
      if (((*(byte *)(*plVar9 + 0x20) >> 5 & 1) == 0) || (*(int *)(param_1 + -0x78) != 0)) {
        uVar6 = 0;
      }
      else {
        uVar6 = __arm_smmu_iova_to_phys_hard(param_1,*param_2);
      }
    }
    else {
      if (*(int *)(pcVar8 + -4) != 0x34edc110) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x107310);
        (*pcVar8)();
      }
      uVar6 = (*pcVar8)(plVar9,param_2);
    }
    lVar10 = *plVar11;
    if ((*(ushort *)(lVar10 + 0x200) & 7) == 0) {
      uVar7 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar10 + 0x220) = uVar7;
      __pm_runtime_suspend(*plVar11,0xd);
    }
    return uVar6;
  }
  piVar1 = (int *)(lVar10 + 0x1f8);
  iVar5 = *(int *)(lVar10 + 0x1f8);
  do {
    if (iVar5 == 0) {
      return 0;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar5) goto LAB_0010735c;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010735c:
    bVar4 = iVar5 == iVar2;
    iVar5 = iVar2;
    if (bVar4) {
      return 0;
    }
  } while( true );
}



//------------------------------------------------------------
// arm_smmu_sid_switch @ 001073f0 size=76
// signature: undefined arm_smmu_sid_switch(void)
// callers: []
//------------------------------------------------------------

undefined4 arm_smmu_sid_switch(undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = iommu_group_get();
  uVar1 = iommu_group_for_each_dev(uVar2,param_2,__arm_smmu_sid_switch);
  iommu_group_put(uVar2);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_get_fault_ids @ 00107440 size=476
// signature: undefined arm_smmu_get_fault_ids(void)
// callers: []
//------------------------------------------------------------

int arm_smmu_get_fault_ids(long param_1,uint *param_2)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  undefined8 uVar9;
  code *pcVar10;
  int iVar11;
  long *plVar12;
  long lVar13;
  
  iVar6 = -0x16;
  if ((param_1 != 0) && (param_2 != (uint *)0x0)) {
    plVar12 = *(long **)(param_1 + -0xc0);
    bVar2 = *(byte *)(param_1 + -0x90);
    lVar13 = *plVar12;
    if (((*(ushort *)(lVar13 + 0x200) & 7) == 0) &&
       (iVar6 = __pm_runtime_resume(lVar13,4), iVar6 < 0)) {
      piVar1 = (int *)(lVar13 + 0x1f8);
      iVar11 = *(int *)(lVar13 + 0x1f8);
      do {
        if (iVar11 == 0) {
          return iVar6;
        }
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar3 = *piVar1;
          if (iVar3 != iVar11) goto LAB_001075ac;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = iVar11 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
LAB_001075ac:
        bVar5 = iVar11 != iVar3;
        iVar11 = iVar3;
      } while (bVar5);
    }
    else {
      iVar6 = (int)plVar12[3] + (uint)bVar2;
      if (((undefined8 *)plVar12[6] == (undefined8 *)0x0) ||
         (pcVar10 = *(code **)plVar12[6], pcVar10 == (code *)0x0)) {
        uVar8 = readl_relaxed(plVar12[1] +
                              (long)(iVar6 << (ulong)(*(uint *)((long)plVar12 + 0x1c) & 0x1f)) +
                              0x58);
      }
      else {
        if (*(int *)(pcVar10 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107600);
          (*pcVar10)();
        }
        uVar8 = (*pcVar10)(plVar12,iVar6,0x58);
      }
      if ((uVar8 & 0xc00001fe) == 0) {
        lVar13 = *plVar12;
        if ((*(ushort *)(lVar13 + 0x200) & 7) == 0) {
          uVar9 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar13 + 0x220) = uVar9;
          __pm_runtime_suspend(*plVar12,0xd);
        }
        iVar6 = -0x16;
      }
      else {
        iVar6 = (int)plVar12[3] + (uint)bVar2;
        if (((undefined8 *)plVar12[6] == (undefined8 *)0x0) ||
           (pcVar10 = *(code **)plVar12[6], pcVar10 == (code *)0x0)) {
          uVar7 = readl_relaxed(plVar12[1] +
                                (long)(iVar6 << (ulong)(*(uint *)((long)plVar12 + 0x1c) & 0x1f)) +
                                0x6c);
        }
        else {
          if (*(int *)(pcVar10 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107628);
            (*pcVar10)();
          }
          uVar7 = (*pcVar10)(plVar12,iVar6,0x6c);
        }
        lVar13 = *plVar12;
        if ((*(ushort *)(lVar13 + 0x200) & 7) == 0) {
          uVar9 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar13 + 0x220) = uVar9;
          __pm_runtime_suspend(*plVar12,0xd);
        }
        iVar6 = 0;
        *param_2 = uVar7 >> 0xd & 7;
        param_2[1] = uVar7 >> 8 & 0x1f;
        param_2[2] = uVar7 & 0xff;
      }
    }
  }
  return iVar6;
}



//------------------------------------------------------------
// arm_smmu_get_context_bank_nr @ 00107634 size=80
// signature: undefined arm_smmu_get_context_bank_nr(void)
// callers: []
//------------------------------------------------------------

ulong arm_smmu_get_context_bank_nr(long param_1)

{
  ulong uVar1;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = (ulong)*(byte *)(param_1 + -0x90);
  }
  mutex_unlock(param_1 + -0x70);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_get_asid_nr @ 00107688 size=80
// signature: undefined arm_smmu_get_asid_nr(void)
// callers: []
//------------------------------------------------------------

ulong arm_smmu_get_asid_nr(long param_1)

{
  ulong uVar1;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = (ulong)*(ushort *)(param_1 + -0x8e);
  }
  mutex_unlock(param_1 + -0x70);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_set_secure_vmid @ 001076dc size=128
// signature: undefined arm_smmu_set_secure_vmid(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_set_secure_vmid(long param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    if (*(int *)(param_1 + -0x34) != -1) {
      __warn_printk("secure vmid already set");
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10775c);
      (*pcVar1)();
    }
    uVar2 = 0;
    *(undefined4 *)(param_1 + -0x34) = param_2;
  }
  else {
    uVar2 = 0xffffffff;
  }
  mutex_unlock(param_1 + -0x70);
  return uVar2;
}



//------------------------------------------------------------
// arm_smmu_set_fault_model @ 00107764 size=104
// signature: undefined arm_smmu_set_fault_model(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_set_fault_model(long param_1,byte param_2)

{
  undefined8 uVar1;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    uVar1 = 0;
    *(byte *)(param_1 + -0x38) = *(byte *)(param_1 + -0x38) & 0xf0 | param_2 & 0xf;
  }
  else {
    uVar1 = 0xffffffff;
  }
  mutex_unlock(param_1 + -0x70);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_set_fault_handler_irq @ 001077d0 size=8
// signature: undefined arm_smmu_set_fault_handler_irq(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_set_fault_handler_irq(long param_1,undefined8 param_2,undefined8 param_3)

{
  *(undefined8 *)(param_1 + -0x30) = param_2;
  *(undefined8 *)(param_1 + -0x28) = param_3;
  return;
}



//------------------------------------------------------------
// arm_smmu_enable_s1_translation @ 001077dc size=496
// signature: undefined arm_smmu_enable_s1_translation(void)
// callers: []
//------------------------------------------------------------

int arm_smmu_enable_s1_translation(long param_1)

{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  code *pcVar10;
  int iVar11;
  long *plVar12;
  long lVar13;
  
  plVar12 = *(long **)(param_1 + -0xc0);
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    iVar7 = -1;
  }
  else if (*(char *)(param_1 + -0x36) == '\0') {
    iVar7 = 0;
  }
  else {
    lVar13 = *plVar12;
    if (((*(ushort *)(lVar13 + 0x200) & 7) == 0) &&
       (iVar7 = __pm_runtime_resume(lVar13,4), iVar7 < 0)) {
      piVar1 = (int *)(lVar13 + 0x1f8);
      iVar11 = *(int *)(lVar13 + 0x1f8);
      do {
        if (iVar11 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar4 = *piVar1;
          if (iVar4 != iVar11) goto LAB_00107984;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = iVar11 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
LAB_00107984:
        bVar6 = iVar11 != iVar4;
        iVar11 = iVar4;
      } while (bVar6);
    }
    else {
      uVar3 = *(ushort *)(param_1 + -0x88);
      bVar2 = *(byte *)(param_1 + -0x90);
      uVar9 = 0x46;
      if (*(int *)(param_1 + -0x84) != 0) {
        uVar9 = 0x1046;
      }
      *(ushort *)(param_1 + -0x88) = uVar3 | 0x4000;
      uVar9 = (uVar3 & 3) << 0x1a |
              uVar9 | (uVar3 & 0xc000 | 0x4000) >> 0xe |
              uVar3 >> 3 & 0x100 | uVar3 >> 5 & 0x80 | uVar3 >> 8 & 0x20 | (uVar3 >> 2 & 3) << 0x18
              | (uVar3 & 0x30) << 0x12 | (uVar3 & 0x40) << 0xe | (uVar3 & 0x780) << 9;
      *(uint *)(plVar12[10] + (ulong)bVar2 * 0x30 + 0x20) = uVar9;
      iVar7 = (int)plVar12[3] + (uint)bVar2;
      if ((plVar12[6] == 0) || (pcVar10 = *(code **)(plVar12[6] + 8), pcVar10 == (code *)0x0)) {
        writel_relaxed(uVar9,plVar12[1] +
                             (long)(iVar7 << (ulong)(*(uint *)((long)plVar12 + 0x1c) & 0x1f)));
      }
      else {
        if (*(int *)(pcVar10 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1079d8);
          (*pcVar10)();
        }
        (*pcVar10)(plVar12,iVar7,0);
      }
      lVar13 = *plVar12;
      if ((*(ushort *)(lVar13 + 0x200) & 7) == 0) {
        uVar8 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar13 + 0x220) = uVar8;
        __pm_runtime_suspend(*plVar12,0xd);
      }
      iVar7 = 0;
      *(undefined1 *)(param_1 + -0x36) = 0;
    }
  }
  mutex_unlock(param_1 + -0x70);
  return iVar7;
}



//------------------------------------------------------------
// arm_smmu_get_mappings_configuration @ 001079e4 size=84
// signature: undefined arm_smmu_get_mappings_configuration(void)
// callers: []
//------------------------------------------------------------

uint arm_smmu_get_mappings_configuration(long param_1)

{
  uint uVar1;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(byte *)(param_1 + -0x37) & 7;
  }
  mutex_unlock(param_1 + -0x70);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_skip_tlb_management @ 00107a3c size=76
// signature: undefined arm_smmu_skip_tlb_management(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_skip_tlb_management(long param_1,undefined1 param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + -0x20);
  *(undefined1 *)(param_1 + 0xdd) = param_2;
  _raw_spin_unlock_irqrestore(param_1 + -0x20,uVar1);
  return;
}



//------------------------------------------------------------
// arm_smmu_capable @ 00107a8c size=88
// signature: undefined arm_smmu_capable(void)
// callers: []
//------------------------------------------------------------

bool arm_smmu_capable(long param_1,int param_2)

{
  int iVar1;
  long *plVar2;
  
  plVar2 = (long *)0x0;
  if (*(long *)(param_1 + 0x338) != 0) {
    plVar2 = *(long **)(*(long *)(param_1 + 0x338) + 0x50);
  }
  if (param_2 != 2) {
    if (param_2 != 0) {
      return false;
    }
    if ((*(byte *)(*plVar2 + 0x20) & 1) == 0) {
      iVar1 = device_get_dma_attr();
      return iVar1 == 2;
    }
  }
  return true;
}



//------------------------------------------------------------
// arm_smmu_domain_alloc @ 00107ae8 size=152
// signature: undefined arm_smmu_domain_alloc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long arm_smmu_domain_alloc(uint param_1)

{
  long lVar1;
  long lVar2;
  
  if ((((param_1 == 1) || (param_1 == 4)) ||
      ((lVar2 = 0, (param_1 & 0xfffffff7) == 3 && ((using_legacy_binding & 1) == 0)))) &&
     (lVar1 = kmalloc_trace(_bus_for_each_dev,0xdc0,0x1a0), lVar2 = lVar1, lVar1 != 0)) {
    __mutex_init(lVar1 + 0x50,"&smmu_domain->init_mutex",&arm_smmu_domain_alloc___key);
    lVar2 = lVar1 + 0xc0;
    *(undefined8 *)(lVar1 + 0x80) = 0;
    *(undefined4 *)(lVar1 + 0xa0) = 0;
    *(undefined4 *)(lVar1 + 0x8c) = 0xffffffff;
  }
  return lVar2;
}



//------------------------------------------------------------
// arm_smmu_probe_device @ 00107b84 size=612
// signature: undefined arm_smmu_probe_device(void)
// callers: []
//------------------------------------------------------------

long * arm_smmu_probe_device(long param_1)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  long lVar9;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  long *plVar13;
  undefined8 *puVar14;
  uint uVar15;
  
  if (*(long *)(param_1 + 0x338) == 0) {
    if ((using_legacy_binding & 1) == 0) {
      return (long *)0xffffffffffffffed;
    }
  }
  else if ((using_legacy_binding & 1) == 0) {
    puVar14 = *(undefined8 **)(*(long *)(param_1 + 0x338) + 0x40);
    if ((puVar14 == (undefined8 *)0x0) || ((undefined **)*puVar14 != &PTR_arm_smmu_capable_00114c70)
       ) {
      return (long *)0xffffffffffffffed;
    }
    lVar9 = driver_find_device(&PTR_s_arm_smmu_00114b50,0,puVar14[1],&device_match_fwnode);
    put_device();
    if (lVar9 == 0) {
      return (long *)0xffffffffffffffed;
    }
    plVar13 = *(long **)(lVar9 + 0x98);
    if (plVar13 == (long *)0x0) {
      return (long *)0xffffffffffffffed;
    }
    uVar3 = *(uint *)((long)puVar14 + 0x14);
    if (uVar3 != 0) {
      uVar11 = (uint)*(ushort *)(plVar13 + 0xc);
      uVar15 = 0;
      do {
        uVar4 = *(uint *)((long)puVar14 + (long)(int)uVar15 * 4 + 0x18);
        uVar2 = uVar4 & 0xffff;
        if ((uVar2 & ~(uint)*(ushort *)(plVar13 + 0xc)) != 0) {
          pcVar10 = "stream ID 0x%x out of range for SMMU (0x%x)\n";
LAB_00107df0:
          _dev_err(param_1,pcVar10,uVar2,uVar11);
          iVar8 = -0x16;
          goto LAB_00107d24;
        }
        uVar2 = uVar4 >> 0x10;
        if ((uVar2 & (*(ushort *)((long)plVar13 + 0x62) ^ 0xffffffff)) != 0) {
          pcVar10 = "SMR mask 0x%x out of range for SMMU (0x%x)\n";
          uVar11 = (uint)*(ushort *)((long)plVar13 + 0x62);
          goto LAB_00107df0;
        }
        uVar15 = uVar15 + 1;
      } while (uVar3 != uVar15);
    }
    puVar14 = (undefined8 *)__kmalloc((long)(int)uVar3 * 2 + 8,0xdc0);
    if (puVar14 == (undefined8 *)0x0) {
      iVar8 = -0xc;
      goto LAB_00107d24;
    }
    lVar9 = *(long *)(param_1 + 0x338);
    *puVar14 = plVar13;
    *(undefined8 **)(lVar9 + 0x50) = puVar14;
    if (uVar3 != 0) {
      uVar15 = uVar3;
      if ((uVar3 != 1) && (-1 < (int)(uVar3 - 1))) {
        uVar15 = uVar3 & 1;
        uVar11 = uVar3 & 0xfffffffe;
        uVar2 = uVar3;
        do {
          uVar11 = uVar11 - 2;
          *(undefined2 *)((long)puVar14 + (long)(int)(uVar2 - 2) * 2 + 8) = 0xffff;
          *(undefined2 *)((long)puVar14 + (long)(int)(uVar2 - 1) * 2 + 8) = 0xffff;
          uVar2 = uVar2 - 2;
        } while (uVar11 != 0);
        if (uVar3 == (uVar3 & 0xfffffffe)) goto LAB_00107cd4;
      }
      iVar8 = uVar15 - 1;
      do {
        lVar9 = (long)iVar8;
        iVar8 = iVar8 + -1;
        *(undefined2 *)((long)puVar14 + lVar9 * 2 + 8) = 0xffff;
      } while (iVar8 != -1);
    }
LAB_00107cd4:
    lVar9 = *plVar13;
    if (((*(ushort *)(lVar9 + 0x200) & 7) == 0) && (iVar8 = __pm_runtime_resume(lVar9,4), iVar8 < 0)
       ) {
      piVar1 = (int *)(lVar9 + 0x1f8);
      iVar12 = *(int *)(lVar9 + 0x1f8);
      do {
        if (iVar12 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar5 = *piVar1;
          if (iVar5 != iVar12) goto LAB_00107d9c;
          cVar6 = '\x01';
          bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar7) {
            *piVar1 = iVar12 + -1;
            cVar6 = ExclusiveMonitorsStatus();
          }
        } while (cVar6 != '\0');
        DataMemoryBarrier(2,3);
LAB_00107d9c:
        bVar7 = iVar12 != iVar5;
        iVar12 = iVar5;
      } while (bVar7);
    }
    else {
      iVar8 = arm_smmu_master_alloc_smes(param_1);
      arm_smmu_rpm_put(plVar13);
      if (iVar8 == 0) {
        device_link_add(param_1,*plVar13,0x14);
        return plVar13 + 0x1d;
      }
    }
    kfree(puVar14);
    goto LAB_00107d24;
  }
  iVar8 = -0x13;
LAB_00107d24:
  iommu_fwspec_free(param_1);
  return (long *)(long)iVar8;
}



//------------------------------------------------------------
// arm_smmu_release_device @ 00107e00 size=640
// signature: undefined arm_smmu_release_device(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_release_device(long param_1)

{
  int *piVar1;
  undefined2 *puVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  int iVar9;
  long lVar10;
  code *pcVar11;
  long lVar12;
  undefined8 *puVar13;
  long *plVar14;
  short *psVar15;
  long *plVar16;
  undefined8 *puVar17;
  uint uVar18;
  undefined4 uVar19;
  
  lVar10 = *(long *)(param_1 + 0x338);
  if (((lVar10 != 0) && (puVar17 = *(undefined8 **)(lVar10 + 0x40), puVar17 != (undefined8 *)0x0))
     && ((undefined **)*puVar17 == &PTR_arm_smmu_capable_00114c70)) {
    plVar14 = *(long **)(lVar10 + 0x50);
    lVar10 = *(long *)*plVar14;
    if (((*(ushort *)(lVar10 + 0x200) & 7) == 0) &&
       (iVar7 = __pm_runtime_resume(lVar10,4), iVar7 < 0)) {
      piVar1 = (int *)(lVar10 + 0x1f8);
      iVar7 = *(int *)(lVar10 + 0x1f8);
      do {
        if (iVar7 == 0) {
          return;
        }
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar9 = *piVar1;
          if (iVar9 != iVar7) goto LAB_00108060;
          cVar3 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = iVar7 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00108060:
        bVar6 = iVar7 != iVar9;
        iVar7 = iVar9;
      } while (bVar6);
    }
    else {
      lVar10 = *plVar14;
      mutex_lock();
      if (*(int *)((long)puVar17 + 0x14) != 0) {
        uVar18 = 0;
        do {
          psVar15 = (short *)((long)plVar14 + (long)(int)uVar18 * 2 + 8);
          iVar9 = (int)*psVar15;
          lVar12 = *(long *)(lVar10 + 0x70) + (long)iVar9 * 0x18;
          cVar3 = *(char *)(lVar12 + 0x15);
          iVar7 = *(int *)(lVar12 + 8) + -1;
          uVar4 = *(undefined1 *)(lVar12 + 0x14);
          *(int *)(lVar12 + 8) = iVar7;
          if (iVar7 == 0) {
            lVar12 = (long)iVar9;
            puVar13 = (undefined8 *)(*(long *)(lVar10 + 0x70) + (long)iVar9 * 0x18);
            uVar19 = 1;
            if (disable_bypass != '\0') {
              uVar19 = 2;
            }
            *puVar13 = 0;
            puVar13[2] = 0;
            *(undefined4 *)(puVar13 + 1) = 0;
            *(undefined4 *)((long)puVar13 + 0xc) = uVar19;
            if (cVar3 == '\0') {
              if (*(long *)(lVar10 + 0x68) != 0) {
                *(undefined1 *)(*(long *)(lVar10 + 0x68) + lVar12 * 8 + 4) = 0;
                *(undefined1 *)(*(long *)(lVar10 + 0x68) + lVar12 * 8 + 6) = 0;
              }
            }
            else {
              *(undefined1 *)(*(long *)(lVar10 + 0x70) + lVar12 * 0x18 + 0x15) = 1;
              *(undefined1 *)(*(long *)(lVar10 + 0x70) + lVar12 * 0x18 + 0x14) = uVar4;
            }
            arm_smmu_write_s2cr(lVar10);
            if (*(long *)(lVar10 + 0x68) != 0) {
              puVar2 = (undefined2 *)(*(long *)(lVar10 + 0x68) + lVar12 * 8);
              uVar5 = CONCAT22(*puVar2,puVar2[1]);
              if (((*(byte *)(lVar10 + 0x21) >> 4 & 1) == 0) && (*(char *)(puVar2 + 2) != '\0')) {
                uVar5 = uVar5 | 0x80000000;
              }
              if ((*(long *)(lVar10 + 0x30) == 0) ||
                 (pcVar11 = *(code **)(*(long *)(lVar10 + 0x30) + 8), pcVar11 == (code *)0x0)) {
                writel_relaxed(uVar5,*(long *)(lVar10 + 8) + lVar12 * 4 + 0x800);
              }
              else {
                if (*(int *)(pcVar11 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                  pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x107fcc);
                  (*pcVar11)();
                }
                (*pcVar11)(lVar10,0);
              }
            }
          }
          *psVar15 = -1;
          uVar18 = uVar18 + 1;
        } while (uVar18 < *(uint *)((long)puVar17 + 0x14));
      }
      mutex_unlock(lVar10 + 0x78);
      plVar16 = (long *)*plVar14;
      lVar10 = *plVar16;
      if ((*(ushort *)(lVar10 + 0x200) & 7) == 0) {
        uVar8 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar10 + 0x220) = uVar8;
        __pm_runtime_suspend(*plVar16,0xd);
      }
      *(undefined8 *)(*(long *)(param_1 + 0x338) + 0x50) = 0;
      kfree(plVar14);
    }
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_probe_finalize @ 00108098 size=88
// signature: undefined arm_smmu_probe_finalize(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_probe_finalize(long param_1)

{
  long *plVar1;
  long lVar2;
  code *pcVar3;
  
  plVar1 = (long *)0x0;
  if (*(long *)(param_1 + 0x338) != 0) {
    plVar1 = *(long **)(*(long *)(param_1 + 0x338) + 0x50);
  }
  lVar2 = *(long *)(*plVar1 + 0x30);
  if ((lVar2 != 0) && (pcVar3 = *(code **)(lVar2 + 0x98), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != 0x3fb12c47) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1080e0);
      (*pcVar3)();
    }
    (*pcVar3)(*plVar1,param_1);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_device_group @ 001080f4 size=648
// signature: undefined arm_smmu_device_group(void)
// callers: []
//------------------------------------------------------------

ulong arm_smmu_device_group(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  long local_a8;
  ulong local_a0;
  long local_98 [11];
  
  lVar4 = sp_el0;
  local_98[10] = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x338);
  if (lVar4 == 0) {
    plVar8 = (long *)0x0;
    lVar4 = 0;
  }
  else {
    plVar8 = *(long **)(lVar4 + 0x50);
    lVar4 = *(long *)(lVar4 + 0x40);
  }
  lVar9 = *plVar8;
  mutex_lock(lVar9 + 0x78);
  local_a0 = 0;
  local_98[0] = 0;
  local_98[8] = 0;
  local_98[9] = 0;
  local_98[6] = 0;
  local_98[7] = 0;
  local_98[4] = 0;
  local_98[5] = 0;
  local_98[2] = 0;
  local_98[3] = 0;
  local_98[1] = 0;
  iVar2 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_98);
  local_a8 = local_98[0];
  if (iVar2 != 0) {
    local_a8 = 0;
  }
  if (local_a8 == 0) {
LAB_001081e8:
    if (*(int *)(lVar4 + 0x14) != 0) {
      iVar2 = 0;
      uVar6 = 0;
      do {
        uVar7 = *(ulong *)(*(long *)(lVar9 + 0x70) +
                          (long)(int)*(short *)((long)plVar8 + (long)iVar2 * 2 + 8) * 0x18);
        if ((uVar6 != 0) && (uVar7 != 0 && uVar6 != uVar7)) {
          _dev_err(param_1,"ID:%x IDX:%x is already in a group!\n",
                   *(undefined4 *)(lVar4 + (long)iVar2 * 4 + 0x18));
          uVar7 = 0xffffffffffffffea;
          goto LAB_00108324;
        }
        iVar2 = iVar2 + 1;
        uVar6 = uVar7;
      } while (*(int *)(lVar4 + 0x14) != iVar2);
      if (uVar7 != 0) {
        iommu_group_ref_get(uVar7);
        goto LAB_001082a0;
      }
    }
    if (*(undefined **)(param_1 + 0x80) == &pci_bus_type) {
      uVar7 = pci_device_group(param_1);
    }
    else {
      uVar7 = generic_device_group();
    }
    if (0xfffffffffffff000 < uVar7) {
      uVar7 = 0;
      goto LAB_00108324;
    }
  }
  else {
    iVar2 = bus_for_each_dev(&platform_bus_type,0,&local_a8,__bus_lookup_iommu_group);
    if ((iVar2 < 1) &&
       (iVar2 = bus_for_each_dev(&pci_bus_type,0,&local_a8,__bus_lookup_iommu_group), iVar2 < 1)) {
      uVar7 = generic_device_group(param_1);
      if (0xfffffffffffff000 < uVar7) goto LAB_001081e8;
    }
    else {
      uVar7 = local_a0;
    }
    if (uVar7 == 0) goto LAB_001081e8;
  }
LAB_001082a0:
  if (uVar7 < 0xfffffffffffff001) {
    if ((*(long *)(lVar9 + 0x30) != 0) &&
       (pcVar5 = *(code **)(*(long *)(lVar9 + 0x30) + 0x58), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != 0x439f45ad) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1082d8);
        (*pcVar5)();
      }
      iVar2 = (*pcVar5)(param_1,uVar7);
      if (iVar2 != 0) {
        iommu_group_put(uVar7);
        uVar7 = 0xffffffffffffffea;
        goto LAB_00108324;
      }
    }
    if (*(int *)(lVar4 + 0x14) != 0) {
      uVar3 = 0;
      do {
        lVar1 = (long)(int)uVar3;
        uVar3 = uVar3 + 1;
        *(ulong *)(*(long *)(lVar9 + 0x70) +
                  (long)(int)*(short *)((long)plVar8 + lVar1 * 2 + 8) * 0x18) = uVar7;
      } while (uVar3 < *(uint *)(lVar4 + 0x14));
    }
  }
LAB_00108324:
  mutex_unlock(lVar9 + 0x78);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// arm_smmu_get_resv_regions @ 00108380 size=136
// signature: undefined arm_smmu_get_resv_regions(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_get_resv_regions(undefined8 param_1,long param_2)

{
  long *plVar1;
  ulong uVar2;
  long *plVar3;
  
  plVar1 = (long *)iommu_alloc_resv_region(0x8000000,0x100000,0x1a,4,0xcc0);
  if (plVar1 != (long *)0x0) {
    plVar3 = *(long **)(param_2 + 8);
    uVar2 = __list_add_valid(plVar1,plVar3,param_2);
    if ((uVar2 & 1) != 0) {
      *(long **)(param_2 + 8) = plVar1;
      *plVar1 = param_2;
      plVar1[1] = (long)plVar3;
      *plVar3 = (long)plVar1;
    }
    iommu_dma_get_resv_regions(param_1,param_2);
    qcom_iommu_generate_resv_regions(param_1,param_2);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_of_xlate @ 0010840c size=184
// signature: undefined arm_smmu_of_xlate(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_of_xlate(undefined8 param_1,undefined8 *param_2)

{
  ushort uVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  if (*(int *)(param_2 + 1) < 1) {
    uVar3 = 0;
LAB_0010845c:
    uVar5 = uVar3;
    iVar4 = of_property_read_variable_u32_array
                      (*param_2,"stream-match-mask",(long)&local_30 + 4,1,0);
    if (iVar4 < 0) goto LAB_00108488;
    iVar4 = local_30._4_4_;
  }
  else {
    uVar1 = *(ushort *)((long)param_2 + 0xc);
    uVar5 = (uint)uVar1;
    local_30 = (ulong)uVar1;
    uVar3 = (uint)uVar1;
    if (*(int *)(param_2 + 1) == 1) goto LAB_0010845c;
    iVar4 = *(int *)(param_2 + 2);
  }
  local_30 = CONCAT44(local_30._4_4_,uVar5 | iVar4 << 0x10);
LAB_00108488:
  iommu_fwspec_add_ids(param_1,&local_30,1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_def_domain_type @ 001084c8 size=116
// signature: undefined arm_smmu_def_domain_type(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_def_domain_type(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  
  if ((*(long *)(param_1 + 0x338) != 0) &&
     (plVar2 = *(long **)(*(long *)(param_1 + 0x338) + 0x50), plVar2 != (long *)0x0)) {
    if ((using_legacy_binding & 1) != 0) {
      return 4;
    }
    lVar3 = *(long *)(*plVar2 + 0x30);
    if ((lVar3 != 0) && (pcVar4 = *(code **)(lVar3 + 0x68), pcVar4 != (code *)0x0)) {
      if (*(int *)(pcVar4 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x108524);
        (*pcVar4)();
      }
      uVar1 = (*pcVar4)();
      return uVar1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// arm_smmu_attach_dev @ 00108540 size=2804
// signature: undefined arm_smmu_attach_dev(void)
// callers: []
//------------------------------------------------------------

ulong arm_smmu_attach_dev(int *param_1,long param_2)

{
  ulong *puVar1;
  undefined4 uVar2;
  short sVar3;
  char cVar4;
  char *pcVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  byte bVar12;
  long lVar13;
  long lVar14;
  undefined **ppuVar15;
  long *plVar16;
  code *pcVar17;
  long *plVar18;
  ulong uVar19;
  uint *puVar20;
  ulong uVar21;
  int iVar22;
  int iVar23;
  long *plVar24;
  undefined8 *puVar25;
  undefined8 *puVar26;
  ushort uVar27;
  uint uVar28;
  int iVar29;
  int *piVar30;
  int *piVar31;
  ulong local_d0;
  int local_c4;
  char *local_c0;
  long local_b8 [11];
  
  lVar13 = sp_el0;
  local_b8[10] = *(long *)(lVar13 + 0x638);
  lVar13 = *(long *)(param_2 + 0x338);
  if (((lVar13 == 0) || (puVar25 = *(undefined8 **)(lVar13 + 0x40), puVar25 == (undefined8 *)0x0))
     || ((undefined **)*puVar25 != &PTR_arm_smmu_capable_00114c70)) {
    _dev_err(param_2,"cannot attach to SMMU, is it on the same bus?\n");
    uVar9 = 0xfffffffa;
    goto LAB_001089c0;
  }
  puVar26 = *(undefined8 **)(lVar13 + 0x50);
  if (puVar26 == (undefined8 *)0x0) {
    uVar9 = 0xffffffed;
    goto LAB_001089c0;
  }
  plVar24 = (long *)*puVar26;
  lVar13 = *plVar24;
  if (((*(ushort *)(lVar13 + 0x200) & 7) == 0) &&
     (uVar9 = __pm_runtime_resume(lVar13,4), (int)uVar9 < 0)) {
    uVar9 = uVar9 & 0xffffffff;
    piVar30 = (int *)(lVar13 + 0x1f8);
    iVar7 = *(int *)(lVar13 + 0x1f8);
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar30,2,0,1);
      do {
        iVar29 = *piVar30;
        if (iVar29 != iVar7) goto LAB_001086ac;
        cVar4 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar30,0x10);
        if (bVar6) {
          *piVar30 = iVar7 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_001086ac:
      bVar6 = iVar7 != iVar29;
      iVar7 = iVar29;
    } while (bVar6);
    goto LAB_001089c0;
  }
  piVar30 = param_1 + -0x1c;
  plVar16 = (long *)(param_1 + -0x30);
  mutex_lock(piVar30);
  if (*(long *)(param_1 + -0x30) == 0) {
    *(long *)(param_1 + -0x2e) = param_2;
    local_c0 = (char *)0x0;
    local_c4 = 0;
    if (*(long *)(param_2 + 0x2e8) != 0) {
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
      iVar7 = __of_parse_phandle_with_args
                        (*(long *)(param_2 + 0x2e8),"qcom,iommu-group",0,0,0,local_b8);
      if (((iVar7 == 0) && (lVar13 = local_b8[0], local_b8[0] != 0)) ||
         (lVar13 = *(long *)(param_2 + 0x2e8), lVar13 != 0)) {
        iVar7 = of_property_read_string(lVar13,"qcom,iommu-dma",&local_c0);
        if (iVar7 != 0) {
          local_c0 = "default";
        }
        pcVar5 = local_c0;
        iVar7 = strcmp(local_c0,"bypass");
        if (iVar7 == 0) {
          bVar12 = 1;
LAB_0010874c:
          *(byte *)((long)param_1 + -0x37) = *(byte *)((long)param_1 + -0x37) | bVar12;
        }
        else {
          iVar7 = strcmp(pcVar5,"fastmap");
          if (iVar7 == 0) {
            bVar12 = 6;
            goto LAB_0010874c;
          }
          iVar7 = strcmp(pcVar5,"atomic");
          if (iVar7 == 0) {
            bVar12 = 2;
            goto LAB_0010874c;
          }
          iVar7 = strcmp(pcVar5,"disabled");
          if (iVar7 == 0) goto LAB_001088c4;
        }
        iVar7 = of_property_match_string(lVar13,"qcom,iommu-faults","stall-disable");
        if (-1 < iVar7) {
          *(byte *)(param_1 + -0xe) = *(byte *)(param_1 + -0xe) | 4;
        }
        iVar7 = of_property_match_string(lVar13,"qcom,iommu-faults","no-CFRE");
        if (-1 < iVar7) {
          *(byte *)(param_1 + -0xe) = *(byte *)(param_1 + -0xe) | 2;
        }
        iVar7 = of_property_match_string(lVar13,"qcom,iommu-faults","HUPCF");
        if (-1 < iVar7) {
          *(byte *)(param_1 + -0xe) = *(byte *)(param_1 + -0xe) | 8;
        }
        iVar7 = of_property_match_string(lVar13,"qcom,iommu-faults","non-fatal");
        if (-1 < iVar7) {
          *(byte *)(param_1 + -0xe) = *(byte *)(param_1 + -0xe) | 1;
        }
        iVar7 = of_property_read_variable_u32_array(lVar13,"qcom,iommu-vmid",&local_c4,1,0);
        if (-1 < iVar7) {
          param_1[-0xd] = local_c4;
        }
        iVar7 = of_property_read_string(lVar13,"qcom,iommu-pagetable",&local_c0);
        if (iVar7 != 0) {
          local_c0 = "disabled";
        }
        pcVar5 = local_c0;
        iVar7 = strcmp(local_c0,"coherent");
        if (iVar7 == 0) {
          *(undefined1 *)(param_1 + -0x28) = 1;
        }
        else {
          iVar7 = strcmp(pcVar5,"LLC");
          if (iVar7 == 0) {
            uVar10 = 0x40;
          }
          else {
            iVar7 = strcmp(pcVar5,"LLC_NWA");
            if (iVar7 != 0) goto LAB_001088a4;
            uVar10 = 0x80000000;
          }
          *(undefined8 *)(param_1 + -0x2a) = uVar10;
        }
LAB_001088a4:
        lVar13 = of_find_property(lVar13,"qcom,iommu-earlymap",0);
        if (lVar13 != 0) {
          *(undefined1 *)((long)param_1 + -0x36) = 1;
        }
      }
    }
LAB_001088c4:
    if (*param_1 == 4) {
      *(long **)(param_1 + -0x30) = plVar24;
      param_1[-0x1e] = 3;
      goto LAB_001088dc;
    }
    uVar8 = *(uint *)(plVar24 + 4);
    if ((uVar8 >> 2 & 1) != 0) {
      if ((uVar8 >> 3 & 1) == 0) goto LAB_00108a30;
LAB_00108a14:
      if ((uVar8 >> 10 & 1) == 0) goto LAB_00108a18;
LAB_00108a3c:
      param_1[-0x20] = 2;
      if ((*(uint *)(plVar24 + 4) & 0x380) == 0) goto LAB_00108a50;
LAB_00108a20:
      iVar7 = 1;
      param_1[-0x20] = 1;
LAB_00108a58:
      if (param_1[-0x1e] - 1U < 2) {
        param_1[-0x21] = 0;
        uVar19 = plVar24[0x16];
        local_d0 = plVar24[0x17];
        uVar9 = uVar19;
        if (0x27 < uVar19) {
          uVar9 = 0x28;
        }
        uVar11 = local_d0;
        if (0x27 < local_d0) {
          uVar11 = 0x28;
        }
        bVar6 = iVar7 != 1;
        if (bVar6) {
          local_d0 = uVar11;
        }
        if (bVar6) {
          uVar19 = uVar9;
        }
        iVar7 = 3;
        if (bVar6) {
          iVar7 = 1;
        }
        if ((int)plVar24[5] == 2) {
          iVar29 = 0;
          ppuVar15 = &arm_smmu_s2_tlb_ops_v2;
        }
        else {
          iVar29 = 0;
          ppuVar15 = &arm_smmu_s2_tlb_ops_v1;
        }
      }
      else {
        if (param_1[-0x1e] != 0) goto LAB_00108b08;
        param_1[-0x21] = 1;
        uVar19 = plVar24[0x15];
        local_d0 = plVar24[0x16];
        iVar29 = *(int *)((long)plVar24 + 0x3c);
        if (iVar7 == 2) {
          if (0x1f < uVar19) {
            uVar19 = 0x20;
          }
          iVar7 = 0;
          if (0x27 < local_d0) {
            local_d0 = 0x28;
          }
        }
        else {
          if (iVar7 == 1) {
            uVar9 = uVar19;
            if (0x26 < uVar19) {
              uVar9 = 0x27;
            }
            iVar7 = -2;
            ppuVar15 = &arm_smmu_s1_tlb_ops;
            if ((*(byte *)((long)plVar24 + 0x24) & 4) != 0) {
              uVar19 = uVar9;
            }
            goto LAB_00108b9c;
          }
          if (0x1f < uVar19) {
            uVar19 = 0x20;
          }
          if (0x1f < local_d0) {
            local_d0 = 0x20;
          }
          iVar7 = 4;
        }
        ppuVar15 = &arm_smmu_s1_tlb_ops;
      }
LAB_00108b9c:
      *(undefined ***)(param_1 + -0x26) = ppuVar15;
      if ((*(byte *)((long)param_1 + -0x37) >> 2 & 1) == 0) {
        if (param_1[-0xd] != -1) {
          param_1[0x30] = param_1[-0xd];
        }
      }
      else {
        uVar8 = qcom_iommu_get_fast_iova_range(param_2,param_1 + 0x32,param_1 + 0x34);
        if ((int)uVar8 < 0) {
          uVar9 = (ulong)uVar8;
          goto LAB_00108d08;
        }
        iVar7 = -1;
      }
      if ((plVar24[6] == 0) || (pcVar17 = *(code **)(plVar24[6] + 0x80), pcVar17 == (code *)0x0)) {
        lVar13 = *(long *)(param_2 + 0x338);
        if (lVar13 == 0) {
          lVar14 = 0;
          plVar18 = (long *)0x0;
        }
        else {
          lVar14 = *(long *)(lVar13 + 0x40);
          plVar18 = *(long **)(lVar13 + 0x50);
        }
        lVar13 = plVar24[7];
        if (*(int *)(lVar14 + 0x14) != 0) {
          iVar22 = 0;
          do {
            iVar23 = (int)*(short *)((long)plVar18 + (long)iVar22 * 2 + 8);
            if (*(char *)(*(long *)(*plVar18 + 0x70) + (long)iVar23 * 0x18 + 0x15) != '\0') {
              uVar8 = (uint)*(byte *)(*(long *)(*plVar18 + 0x70) + (long)iVar23 * 0x18 + 0x14);
              goto LAB_00108d28;
            }
            iVar22 = iVar22 + 1;
          } while (*(int *)(lVar14 + 0x14) != iVar22);
        }
        do {
          uVar9 = _find_next_zero_bit(plVar24 + 8,(long)(int)lVar13,(long)iVar29);
          if ((int)lVar13 == (int)uVar9) {
            uVar9 = 0xffffffe4;
            goto LAB_00108d08;
          }
          uVar11 = 1L << (uVar9 & 0x3f);
          puVar1 = (ulong *)(plVar24 + 8 + (uVar9 >> 6 & 0x3ffffff));
          Hint_Prefetch(puVar1,2,0,1);
          do {
            uVar21 = *puVar1;
            cVar4 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar6) {
              *puVar1 = uVar21 | uVar11;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          DataMemoryBarrier(2,3);
        } while ((uVar21 & uVar11) != 0);
      }
      else {
        if (*(int *)(pcVar17 + -4) != -0x44b4e336) {
                    /* WARNING: Does not return */
          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x108c10);
          (*pcVar17)();
        }
        uVar9 = (*pcVar17)(plVar16,plVar24,param_2,iVar29);
        uVar9 = uVar9 & 0xffffffff;
      }
      uVar8 = (uint)uVar9;
      if ((int)uVar8 < 0) goto LAB_00108d08;
LAB_00108d28:
      uVar27 = (ushort)uVar8;
      *(long **)(param_1 + -0x30) = plVar24;
      *(char *)(param_1 + -0x24) = (char)uVar8;
      if (*(uint *)(plVar24 + 5) < 2) {
        puVar20 = (uint *)(plVar24 + 0xb);
        Hint_Prefetch(puVar20,2,0,1);
        do {
          uVar8 = *puVar20 + 1;
          cVar4 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar20,0x10);
          if (bVar6) {
            *puVar20 = uVar8;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
        *(char *)((long)param_1 + -0x8f) = (char)uVar8;
        iVar29 = (int)plVar24[0x19];
        uVar27 = (ushort)*(byte *)(param_1 + -0x24);
        cVar4 = '\0';
        if (iVar29 != 0) {
          cVar4 = (char)((int)(uVar8 & 0xff) / iVar29);
        }
        *(char *)((long)param_1 + -0x8f) = (char)uVar8 - cVar4 * (char)plVar24[0x19];
      }
      else {
        *(char *)((long)param_1 + -0x8f) = (char)uVar8;
      }
      uVar27 = uVar27 & 0xff;
      if (param_1[-0x1e] == 1) {
        uVar27 = uVar27 + 1;
      }
      *(ushort *)((long)param_1 + -0x8e) = uVar27;
      *(undefined ***)(param_1 + 0x2c) = &arm_smmu_iotlb_ops;
      *(undefined ***)(param_1 + 0x2e) = &arm_smmu_pgtable_log_ops;
      lVar13 = plVar24[0x18];
      if ((char)param_1[-0x28] == '\0') {
        bVar12 = 0;
        if ((long *)*plVar16 != (long *)0x0) {
          lVar14 = *(long *)*plVar16;
          bVar12 = 0;
          if (lVar14 != 0) {
            bVar12 = *(byte *)(lVar14 + 0x34c) >> 5 & 1;
          }
        }
      }
      else {
        bVar12 = 1;
      }
      lVar14 = *plVar24;
      param_1[0x16] = 0;
      param_1[0x17] = 0;
      *(long *)(param_1 + 0x18) = lVar13;
      param_1[0x1a] = (int)uVar19;
      param_1[0x1b] = (int)local_d0;
      *(byte *)(param_1 + 0x1c) = bVar12;
      param_1[0x22] = 0;
      param_1[0x23] = 0;
      param_1[0x24] = 0;
      param_1[0x25] = 0;
      puVar1 = (ulong *)(param_1 + 0x16);
      *(undefined8 *)(param_1 + 0x1e) = *(undefined8 *)(param_1 + -0x26);
      *(long *)(param_1 + 0x20) = lVar14;
      param_1[0x26] = 0;
      param_1[0x27] = 0;
      param_1[0x28] = 0;
      param_1[0x29] = 0;
      param_1[0x2a] = 0;
      param_1[0x2b] = 0;
      if ((plVar24[6] != 0) && (pcVar17 = *(code **)(plVar24[6] + 0x30), pcVar17 != (code *)0x0)) {
        if (*(int *)(pcVar17 + -4) != -0x442d4517) {
                    /* WARNING: Does not return */
          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x108e0c);
          (*pcVar17)();
        }
        uVar11 = (*pcVar17)(plVar16,puVar1,param_2);
        uVar9 = uVar11 & 0xffffffff;
        if ((int)uVar11 == 0) goto LAB_00108e18;
LAB_00108efc:
        bVar12 = *(byte *)(param_1 + -0x24);
        puVar1 = (ulong *)(plVar24 + (ulong)(bVar12 >> 6) + 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar4 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar6) {
            *puVar1 = *puVar1 & (1L << ((ulong)bVar12 & 0x3f) ^ 0xffffffffffffffffU);
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        *plVar16 = 0;
        mutex_unlock(piVar30);
        if (-1 < (int)uVar9) goto LAB_001088e4;
        goto LAB_0010899c;
      }
LAB_00108e18:
      if (*(ulong *)(param_1 + -0x2a) != 0) {
        *puVar1 = *puVar1 | *(ulong *)(param_1 + -0x2a);
      }
      lVar13 = qcom_alloc_io_pgtable_ops(iVar7,puVar1,plVar16);
      if (lVar13 == 0) {
        uVar9 = 0xfffffff4;
        goto LAB_00108efc;
      }
      piVar31 = param_1 + -2;
      param_1[0x36] = iVar7;
      uVar8 = iommu_logger_register(piVar31,param_1,*(undefined8 *)(param_1 + -0x2e),lVar13 + -0x68)
      ;
      if (uVar8 != 0) {
        _dev_err(param_2,"Log registration failed\n");
LAB_00108ef0:
        uVar9 = (ulong)uVar8;
        qcom_free_io_pgtable_ops(*(undefined8 *)(param_1 + -0x2c));
        goto LAB_00108efc;
      }
      uVar9 = -1L << (uVar19 & 0x3f);
      *(undefined8 *)(param_1 + 4) = *(undefined8 *)(param_1 + 0x18);
      if ((*(byte *)(param_1 + 0x16) >> 5 & 1) == 0) {
        uVar19 = ~uVar9;
      }
      else {
        uVar19 = 0xffffffffffffffff;
        *(ulong *)(param_1 + 6) = uVar9;
      }
      bVar12 = *(byte *)((long)param_1 + -0x37);
      *(ulong *)(param_1 + 8) = uVar19;
      *(undefined1 *)(param_1 + 10) = 1;
      if ((bVar12 >> 2 & 1) != 0) {
        uVar8 = fast_smmu_init_mapping(param_2,param_1,lVar13);
        if (uVar8 != 0) {
          iommu_logger_unregister(*(undefined8 *)piVar31);
          piVar31[0] = 0;
          piVar31[1] = 0;
          goto LAB_00108ef0;
        }
        bVar12 = *(byte *)((long)param_1 + -0x37);
      }
      if ((bVar12 >> 1 & 1) != 0) {
        *(undefined1 *)(param_1 + 0x37) = 1;
        arm_smmu_rpm_get(plVar24);
      }
      arm_smmu_init_context_bank(plVar16,puVar1);
      if ((plVar24[6] != 0) && (pcVar17 = *(code **)(plVar24[6] + 0x38), pcVar17 != (code *)0x0)) {
        if (*(int *)(pcVar17 + -4) != -0x5ed3a7bf) {
                    /* WARNING: Does not return */
          pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x108f88);
          (*pcVar17)();
        }
        (*pcVar17)(plVar16,param_2);
      }
      arm_smmu_write_context_bank(plVar24,(char)param_1[-0x24]);
      uVar2 = *(undefined4 *)(plVar24[0x1a] + (ulong)*(byte *)((long)param_1 + -0x8f) * 4);
      if ((plVar24[6] == 0) || (pcVar17 = *(code **)(plVar24[6] + 0x78), pcVar17 == (code *)0x0)) {
        pcVar17 = arm_smmu_context_fault;
      }
      iVar7 = devm_request_threaded_irq
                        (*plVar24,uVar2,arm_smmu_context_fault_irq,pcVar17,0x2080,
                         "arm-smmu-context-fault",param_1);
      if (iVar7 < 0) {
        _dev_err(*plVar24,"failed to request context IRQ %d (%u)\n",
                 *(undefined1 *)((long)param_1 + -0x8f),uVar2);
        *(undefined1 *)((long)param_1 + -0x8f) = 0xff;
      }
      mutex_unlock(piVar30);
      *(long *)(param_1 + -0x2c) = lVar13;
      goto LAB_001088e4;
    }
    param_1[-0x1e] = 1;
    uVar8 = *(uint *)(plVar24 + 4);
    if ((uVar8 >> 3 & 1) != 0) goto LAB_00108a14;
LAB_00108a30:
    param_1[-0x1e] = 0;
    uVar8 = *(uint *)(plVar24 + 4);
    if ((uVar8 >> 10 & 1) != 0) goto LAB_00108a3c;
LAB_00108a18:
    if ((uVar8 & 0x380) != 0) goto LAB_00108a20;
LAB_00108a50:
    iVar7 = param_1[-0x20];
    if (iVar7 != 0) goto LAB_00108a58;
LAB_00108b08:
    uVar9 = 0xffffffea;
LAB_00108d08:
    mutex_unlock(piVar30);
  }
  else {
LAB_001088dc:
    mutex_unlock(piVar30);
LAB_001088e4:
    if ((long *)*plVar16 == plVar24) {
      iVar7 = param_1[-0x1e];
      lVar13 = plVar24[0xe];
      iVar29 = param_1[-0x24];
      mutex_lock(plVar24 + 0xf);
      uVar8 = *(uint *)((long)puVar25 + 0x14);
      if (uVar8 != 0) {
        uVar28 = 0;
        do {
          sVar3 = *(short *)((long)puVar26 + (long)(int)uVar28 * 2 + 8);
          puVar20 = (uint *)(lVar13 + (long)(int)sVar3 * 0x18 + 0xc);
          if ((*puVar20 != (uint)(iVar7 == 3)) ||
             ((char)iVar29 != *(char *)(lVar13 + (long)(int)sVar3 * 0x18 + 0x14))) {
            lVar14 = lVar13 + (long)(int)sVar3 * 0x18;
            *puVar20 = (uint)(iVar7 == 3);
            *(undefined4 *)(lVar14 + 0x10) = 0;
            *(char *)(lVar14 + 0x14) = (char)iVar29;
            arm_smmu_write_s2cr(plVar24);
            uVar8 = *(uint *)((long)puVar25 + 0x14);
          }
          uVar28 = uVar28 + 1;
        } while (uVar28 < uVar8);
      }
      mutex_unlock(plVar24 + 0xf);
      pm_runtime_set_autosuspend_delay(*plVar24,0x14);
      __pm_runtime_use_autosuspend(*plVar24,1);
      uVar9 = 0;
    }
    else {
      plVar16 = *(long **)*plVar16;
      lVar13 = plVar16[0xe];
      if (lVar13 == 0) {
        lVar13 = *plVar16;
      }
      lVar14 = ((long *)*plVar24)[0xe];
      if (lVar14 == 0) {
        lVar14 = *(long *)*plVar24;
      }
      _dev_err(param_2,"cannot attach to SMMU %s whilst already attached to domain on SMMU %s\n",
               lVar13,lVar14);
      uVar9 = 0xffffffea;
    }
  }
LAB_0010899c:
  lVar13 = *plVar24;
  if ((*(ushort *)(lVar13 + 0x200) & 7) == 0) {
    uVar10 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar13 + 0x220) = uVar10;
    __pm_runtime_suspend(*plVar24,0xd);
  }
LAB_001089c0:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// arm_smmu_map_pages @ 00109078 size=392
// signature: undefined arm_smmu_map_pages(void)
// callers: []
//------------------------------------------------------------

int arm_smmu_map_pages(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                      undefined8 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  int iVar9;
  long lVar10;
  long *plVar11;
  long lVar12;
  
  plVar11 = *(long **)(param_1 + -0xc0);
  lVar12 = *(long *)(param_1 + -0xb0);
  if (lVar12 == 0) {
    iVar6 = -0x13;
  }
  else {
    lVar10 = *plVar11;
    if (((*(ushort *)(lVar10 + 0x200) & 7) == 0) &&
       (iVar6 = __pm_runtime_resume(lVar10,4), iVar6 < 0)) {
      piVar1 = (int *)(lVar10 + 0x1f8);
      iVar9 = *(int *)(lVar10 + 0x1f8);
      do {
        if (iVar9 == 0) {
          return iVar6;
        }
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar9) goto LAB_001091e0;
          cVar3 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar5) {
            *piVar1 = iVar9 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_001091e0:
        bVar5 = iVar9 != iVar2;
        iVar9 = iVar2;
      } while (bVar5);
    }
    else {
      uVar8 = 0xcc0;
      if ((*(byte *)(param_1 + -0x37) & 2) != 0) {
        uVar8 = 0xa20;
      }
      if (*(int *)(*(code **)(lVar12 + 8) + -4) != -0x358afb1b) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x109144);
        (*pcVar4)();
      }
      iVar6 = (**(code **)(lVar12 + 8))
                        (lVar12,param_2,param_3,param_4,param_5,param_6,uVar8,param_8);
      lVar12 = *plVar11;
      if ((*(ushort *)(lVar12 + 0x200) & 7) == 0) {
        uVar7 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar12 + 0x220) = uVar7;
        __pm_runtime_suspend(*plVar11,0xd);
      }
      if (iVar6 == 0) {
        iVar6 = 0;
      }
    }
  }
  return iVar6;
}



//------------------------------------------------------------
// arm_smmu_unmap_pages @ 001092bc size=124
// signature: undefined arm_smmu_unmap_pages(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_unmap_pages(long param_1)

{
  code *pcVar1;
  
  if (*(long *)(param_1 + -0xb0) != 0) {
    pcVar1 = *(code **)(*(long *)(param_1 + -0xb0) + 0x18);
    if (*(int *)(pcVar1 + -4) != -0x64613007) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10930c);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_flush_iotlb_all @ 001093f0 size=364
// signature: undefined arm_smmu_flush_iotlb_all(void)
// callers: [arm_smmu_iotlb_sync]
//------------------------------------------------------------

void arm_smmu_flush_iotlb_all(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  
  plVar11 = *(long **)(param_1 + -0xc0);
  lVar9 = param_1 + -0x20;
  uVar7 = _raw_spin_lock_irqsave(lVar9);
  if (*(char *)(param_1 + 0xdd) == '\0') {
    _raw_spin_unlock_irqrestore(lVar9,uVar7);
    if (*(long *)(param_1 + -0x98) != 0) {
      lVar10 = *plVar11;
      if (((*(ushort *)(lVar10 + 0x200) & 7) == 0) &&
         (iVar6 = __pm_runtime_resume(lVar10,4), iVar6 < 0)) {
        piVar1 = (int *)(lVar10 + 0x1f8);
        iVar6 = *(int *)(lVar10 + 0x1f8);
        do {
          if (iVar6 == 0) break;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar6) goto LAB_0010953c;
            cVar3 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar6 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_0010953c:
          bVar5 = iVar6 != iVar2;
          iVar6 = iVar2;
        } while (bVar5);
      }
      uVar7 = _raw_spin_lock_irqsave(lVar9);
      if (*(char *)(param_1 + 0xdd) == '\0') {
        if (*(int *)((code *)**(undefined8 **)(param_1 + -0x98) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1094b8);
          (*pcVar4)();
        }
        (*(code *)**(undefined8 **)(param_1 + -0x98))((undefined8 *)(param_1 + -0xc0));
        puVar8 = *(undefined8 **)(param_1 + -0x18);
        *(undefined1 *)(param_1 + -0x10) = 0;
        while (puVar8 != (undefined8 *)0x0) {
          *(undefined8 *)(param_1 + -0x18) = *puVar8;
          qcom_io_pgtable_free_page(puVar8 + -1);
          puVar8 = *(undefined8 **)(param_1 + -0x18);
        }
        *(undefined8 *)(param_1 + -0x18) = 0;
      }
      _raw_spin_unlock_irqrestore(lVar9,uVar7);
      lVar9 = *plVar11;
      if ((*(ushort *)(lVar9 + 0x200) & 7) == 0) {
        uVar7 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar9 + 0x220) = uVar7;
        __pm_runtime_suspend(*plVar11,0xd);
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + -0x10) = 0;
    _raw_spin_unlock_irqrestore(lVar9,uVar7);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_iotlb_sync @ 00109574 size=36
// signature: undefined arm_smmu_iotlb_sync(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_iotlb_sync(long param_1)

{
  if (*(long *)(param_1 + -0xc0) != 0) {
    arm_smmu_flush_iotlb_all();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_iova_to_phys @ 0010959c size=292
// signature: undefined arm_smmu_iova_to_phys(void)
// callers: [arm_smmu_context_fault]
//------------------------------------------------------------

undefined8 arm_smmu_iova_to_phys(long param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  code *pcVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long *plVar10;
  
  lVar7 = *(long *)(param_1 + -0xb0);
  if (lVar7 == 0) {
LAB_001096b8:
    uVar8 = 0;
  }
  else {
    plVar10 = *(long **)(param_1 + -0xc0);
    if (((*(byte *)(plVar10 + 4) >> 5 & 1) == 0) || (*(int *)(param_1 + -0x78) != 0)) {
      if (*(int *)(*(code **)(lVar7 + 0x20) + -4) != 0x126bd94e) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1095f4);
        (*pcVar4)();
      }
      uVar8 = (**(code **)(lVar7 + 0x20))(lVar7,param_2);
    }
    else {
      lVar7 = *plVar10;
      if (((*(ushort *)(lVar7 + 0x200) & 7) == 0) &&
         (iVar6 = __pm_runtime_resume(lVar7,4), iVar6 < 0)) {
        piVar1 = (int *)(lVar7 + 0x1f8);
        iVar6 = *(int *)(lVar7 + 0x1f8);
        do {
          if (iVar6 == 0) goto LAB_001096b8;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar6) goto LAB_00109680;
            cVar3 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar6 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_00109680:
          uVar8 = 0;
          bVar5 = iVar6 != iVar2;
          iVar6 = iVar2;
        } while (bVar5);
      }
      else {
        uVar8 = __arm_smmu_iova_to_phys_hard(param_1,param_2);
        lVar7 = *plVar10;
        if ((*(ushort *)(lVar7 + 0x200) & 7) == 0) {
          uVar9 = ktime_get_mono_fast_ns();
          *(undefined8 *)(lVar7 + 0x220) = uVar9;
          __pm_runtime_suspend(*plVar10,0xd);
        }
      }
    }
  }
  return uVar8;
}



//------------------------------------------------------------
// arm_smmu_enable_nesting @ 001096d8 size=96
// signature: undefined arm_smmu_enable_nesting(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_enable_nesting(long param_1)

{
  undefined8 uVar1;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + -0x78) = 2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  mutex_unlock(param_1 + -0x70);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_set_pgtable_quirks @ 0010973c size=96
// signature: undefined arm_smmu_set_pgtable_quirks(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_set_pgtable_quirks(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  mutex_lock(param_1 + -0x70);
  if (*(long *)(param_1 + -0xc0) == 0) {
    uVar1 = 0;
    *(undefined8 *)(param_1 + -0xa8) = param_2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  mutex_unlock(param_1 + -0x70);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_domain_free @ 001097a0 size=496
// signature: undefined arm_smmu_domain_free(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_domain_free(int *param_1)

{
  int *piVar1;
  ulong *puVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  long *plVar9;
  long lVar10;
  
  if ((*(byte *)((long)param_1 + -0x37) >> 2 & 1) != 0) {
    fast_smmu_put_dma_cookie(param_1);
  }
  plVar9 = *(long **)(param_1 + -0x30);
  if ((plVar9 == (long *)0x0) || (*param_1 == 4)) goto LAB_00109910;
  lVar10 = *plVar9;
  if (((*(ushort *)(lVar10 + 0x200) & 7) == 0) && (iVar7 = __pm_runtime_resume(lVar10,4), iVar7 < 0)
     ) {
    piVar1 = (int *)(lVar10 + 0x1f8);
    iVar7 = *(int *)(lVar10 + 0x1f8);
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar4 = *piVar1;
        if (iVar4 != iVar7) goto LAB_0010995c;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = iVar7 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010995c:
      bVar6 = iVar7 != iVar4;
      iVar7 = iVar4;
    } while (bVar6);
    goto LAB_00109910;
  }
  if (((char)param_1[0x37] != '\0') && (lVar10 = *plVar9, (*(ushort *)(lVar10 + 0x200) & 7) == 0)) {
    uVar8 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar10 + 0x220) = uVar8;
    __pm_runtime_suspend(*plVar9,0xd);
  }
  *(undefined8 *)(plVar9[10] + (ulong)*(byte *)(param_1 + -0x24) * 0x30 + 0x28) = 0;
  arm_smmu_write_context_bank(plVar9,(char)param_1[-0x24]);
  if ((ulong)*(byte *)((long)param_1 + -0x8f) != 0xff) {
    devm_free_irq(*plVar9,*(undefined4 *)
                           (plVar9[0x1a] + (ulong)*(byte *)((long)param_1 + -0x8f) * 4),param_1);
  }
  qcom_free_io_pgtable_ops(*(undefined8 *)(param_1 + -0x2c));
  bVar3 = *(byte *)(param_1 + -0x24);
  if (*(int *)((long)plVar9 + 0x5c) == 0) {
LAB_001098d0:
    puVar2 = (ulong *)(plVar9 + (ulong)(bVar3 >> 6) + 8);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar6) {
        *puVar2 = *puVar2 & (1L << ((ulong)bVar3 & 0x3f) ^ 0xffffffffffffffffU);
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
  }
  else {
    bVar6 = false;
    iVar7 = 0;
    do {
      if (bVar3 == *(byte *)(plVar9[0xe] + (long)iVar7 * 0x18 + 0x14)) {
        bVar6 = (bool)(*(char *)(plVar9[0xe] + (long)iVar7 * 0x18 + 0x15) != '\0' | bVar6);
      }
      iVar7 = iVar7 + 1;
    } while (*(int *)((long)plVar9 + 0x5c) != iVar7);
    if (!bVar6) goto LAB_001098d0;
  }
  lVar10 = *plVar9;
  if ((*(ushort *)(lVar10 + 0x200) & 7) == 0) {
    uVar8 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar10 + 0x220) = uVar8;
    __pm_runtime_suspend(*plVar9,0xd);
  }
LAB_00109910:
  iommu_logger_unregister(*(undefined8 *)(param_1 + -2));
  kfree(param_1 + -0x30);
  return;
}



//------------------------------------------------------------
// __arm_smmu_iova_to_phys_hard @ 001099ac size=688
// signature: undefined __arm_smmu_iova_to_phys_hard(void)
// callers: [arm_smmu_iova_to_phys, arm_smmu_iova_to_phys_hard]
//------------------------------------------------------------

void __arm_smmu_iova_to_phys_hard(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  byte bVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  code *pcVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 *puVar11;
  long lVar12;
  ulong local_70;
  long local_68;
  
  lVar12 = sp_el0;
  lVar10 = param_1 + -0x40;
  local_68 = *(long *)(lVar12 + 0x638);
  puVar11 = *(undefined8 **)(param_1 + -0xc0);
  lVar12 = *(long *)(param_1 + -0xb0);
  bVar3 = *(byte *)(param_1 + -0x90);
  uVar9 = *puVar11;
  local_70 = param_2;
  uVar4 = _raw_spin_lock_irqsave(lVar10);
  iVar2 = *(int *)(puVar11 + 3) + (uint)bVar3;
  if (*(int *)(param_1 + -0x80) == 1) {
    if ((puVar11[6] == 0) || (pcVar8 = *(code **)(puVar11[6] + 0x18), pcVar8 == (code *)0x0)) {
      writeq_relaxed(param_2 & 0xfffffffffffff000,
                     puVar11[1] + (long)(iVar2 << (ulong)(*(uint *)((long)puVar11 + 0x1c) & 0x1f)) +
                     0x800);
    }
    else {
      if (*(int *)(pcVar8 + -4) != 0x6bc70ae0) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x109c28);
        (*pcVar8)();
      }
      (*pcVar8)(puVar11,iVar2,0x800);
    }
  }
  else if ((puVar11[6] == 0) || (pcVar8 = *(code **)(puVar11[6] + 8), pcVar8 == (code *)0x0)) {
    writel_relaxed(param_2 & 0xfffff000,
                   puVar11[1] + (long)(iVar2 << (ulong)(*(uint *)((long)puVar11 + 0x1c) & 0x1f)) +
                   0x800);
  }
  else {
    if (*(int *)(pcVar8 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x109c50);
      (*pcVar8)();
    }
    (*pcVar8)(puVar11,iVar2,0x800);
  }
  lVar1 = puVar11[1] +
          (long)(int)(*(int *)(puVar11 + 3) + (uint)bVar3 <<
                     (ulong)(*(uint *)((long)puVar11 + 0x1c) & 0x1f)) + 0x8f0;
  lVar5 = ktime_get();
  uVar6 = readl(lVar1);
  if ((uVar6 & 1) != 0) {
    do {
      lVar7 = ktime_get();
      if (lVar5 + 50000 < lVar7) {
        uVar6 = readl(lVar1);
        break;
      }
      __const_udelay(0x53e3);
      Yield();
      uVar6 = readl(lVar1);
    } while ((uVar6 & 1) != 0);
  }
  if ((uVar6 & 1) == 0) {
    if ((puVar11[6] == 0) || (pcVar8 = *(code **)(puVar11[6] + 0x10), pcVar8 == (code *)0x0)) {
      uVar6 = readq_relaxed(puVar11[1] +
                            (long)(int)(*(int *)(puVar11 + 3) + (uint)bVar3 <<
                                       (ulong)(*(uint *)((long)puVar11 + 0x1c) & 0x1f)) + 0x50);
    }
    else {
      if (*(int *)(pcVar8 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x109c00);
        (*pcVar8)();
      }
      uVar6 = (*pcVar8)(puVar11,*(int *)(puVar11 + 3) + (uint)bVar3,0x50);
    }
    _raw_spin_unlock_irqrestore(lVar10,uVar4);
    if ((uVar6 & 1) == 0) {
      uVar6 = uVar6 & 0xfffffff000 | param_2 & 0xfff;
    }
    else {
      _dev_err(uVar9,"translation fault!\n");
      _dev_err(uVar9,"PAR = 0x%llx\n",uVar6);
      uVar6 = 0;
    }
  }
  else {
    _raw_spin_unlock_irqrestore(lVar10,uVar4);
    _dev_err(uVar9,"iova to phys timed out on %pad. Falling back to software table walk.\n",
             &local_70);
    pcVar8 = *(code **)(lVar12 + 0x20);
    if (*(int *)(pcVar8 + -4) != 0x126bd94e) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x109bac);
      (*pcVar8)();
    }
    uVar6 = (*pcVar8)(lVar12,local_70);
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// readl @ 00109c5c size=140
// signature: undefined readl(void)
// callers: [__arm_smmu_iova_to_phys_hard]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x109cb4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readq_relaxed @ 00109ce8 size=124
// signature: undefined readq_relaxed(void)
// callers: [__arm_smmu_iova_to_phys_hard, arm_smmu_context_fault]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x109d30,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// __arm_smmu_sid_switch @ 00109d68 size=508
// signature: undefined __arm_smmu_sid_switch(void)
// callers: []
//------------------------------------------------------------

undefined8 __arm_smmu_sid_switch(long param_1,int param_2)

{
  int *piVar1;
  undefined2 *puVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  undefined8 uVar9;
  long lVar10;
  code *pcVar11;
  long *plVar12;
  long lVar13;
  undefined8 *puVar14;
  uint uVar15;
  
  lVar10 = *(long *)(param_1 + 0x338);
  if (lVar10 != 0) {
    lVar13 = *(long *)(lVar10 + 0x40);
    puVar14 = *(undefined8 **)(lVar10 + 0x50);
    if (lVar13 != 0 && puVar14 != (undefined8 *)0x0) {
      plVar12 = (long *)*puVar14;
      lVar10 = *plVar12;
      if (((*(ushort *)(lVar10 + 0x200) & 7) == 0) &&
         (iVar8 = __pm_runtime_resume(lVar10,4), iVar8 < 0)) {
        piVar1 = (int *)(lVar10 + 0x1f8);
        iVar8 = *(int *)(lVar10 + 0x1f8);
        do {
          if (iVar8 == 0) break;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar4 = *piVar1;
            if (iVar4 != iVar8) goto LAB_00109f44;
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar7) {
              *piVar1 = iVar8 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          DataMemoryBarrier(2,3);
LAB_00109f44:
          bVar7 = iVar8 != iVar4;
          iVar8 = iVar4;
        } while (bVar7);
      }
      mutex_lock(plVar12 + 0xf);
      if ((param_2 == 0) && (*(int *)(lVar13 + 0x14) != 0)) {
        arm_smmu_write_context_bank
                  (plVar12,*(undefined1 *)
                            (plVar12[0xe] + (long)(int)*(short *)(puVar14 + 1) * 0x18 + 0x14));
      }
      if (*(int *)(lVar13 + 0x14) != 0) {
        uVar15 = 0;
        do {
          sVar3 = *(short *)((long)puVar14 + (long)(int)uVar15 * 2 + 8);
          iVar8 = (int)sVar3;
          *(bool *)(plVar12[0xd] + (long)iVar8 * 8 + 4) = param_2 == 0;
          arm_smmu_write_s2cr(plVar12,(int)sVar3);
          if (plVar12[0xd] != 0) {
            puVar2 = (undefined2 *)(plVar12[0xd] + (long)iVar8 * 8);
            uVar5 = CONCAT22(*puVar2,puVar2[1]);
            if (((*(byte *)((long)plVar12 + 0x21) >> 4 & 1) == 0) && (*(char *)(puVar2 + 2) != '\0')
               ) {
              uVar5 = uVar5 | 0x80000000;
            }
            if ((plVar12[6] == 0) || (pcVar11 = *(code **)(plVar12[6] + 8), pcVar11 == (code *)0x0))
            {
              writel_relaxed(uVar5,plVar12[1] + (long)iVar8 * 4 + 0x800);
            }
            else {
              if (*(int *)(pcVar11 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x109ec4);
                (*pcVar11)();
              }
              (*pcVar11)(plVar12,0);
            }
          }
          uVar15 = uVar15 + 1;
        } while (uVar15 < *(uint *)(lVar13 + 0x14));
      }
      mutex_unlock(plVar12 + 0xf);
      DataSynchronizationBarrier(3,2,0);
      lVar10 = *plVar12;
      if ((*(ushort *)(lVar10 + 0x200) & 7) == 0) {
        uVar9 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar10 + 0x220) = uVar9;
        __pm_runtime_suspend(*plVar12,0xd);
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// arm_smmu_write_s2cr @ 00109f78 size=220
// signature: undefined arm_smmu_write_s2cr(void)
// callers: [arm_smmu_device_reset, arm_smmu_attach_dev, arm_smmu_master_alloc_smes, arm_smmu_release_device, __arm_smmu_sid_switch]
//------------------------------------------------------------

void arm_smmu_write_s2cr(long param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  
  lVar3 = *(long *)(param_1 + 0x30);
  if ((lVar3 == 0) || (pcVar4 = *(code **)(lVar3 + 0x88), pcVar4 == (code *)0x0)) {
    lVar5 = *(long *)(param_1 + 0x70) + (long)param_2 * 0x18;
    uVar1 = (*(uint *)(lVar5 + 0xc) & 3) << 0x10 | (*(uint *)(lVar5 + 0x10) & 3) << 0x18 |
            (uint)*(byte *)(lVar5 + 0x14);
    uVar2 = uVar1 | 0x300;
    if (((*(byte *)(param_1 + 0x21) >> 4 & 1) != 0) && (*(long *)(param_1 + 0x68) != 0)) {
      if (*(char *)(*(long *)(param_1 + 0x68) + (long)param_2 * 8 + 4) != '\0') {
        uVar2 = uVar1 | 0x700;
      }
    }
    if ((lVar3 == 0) || (pcVar4 = *(code **)(lVar3 + 8), pcVar4 == (code *)0x0)) {
      writel_relaxed(uVar2,*(long *)(param_1 + 8) + (long)(param_2 * 4 + 0xc00));
    }
    else {
      if (*(int *)(pcVar4 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10a04c);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,0);
    }
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x2c3bdc01) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x109fb0);
      (*pcVar4)();
    }
    (*pcVar4)();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_master_alloc_smes @ 0010a054 size=976
// signature: undefined arm_smmu_master_alloc_smes(void)
// callers: [arm_smmu_probe_device]
//------------------------------------------------------------

uint arm_smmu_master_alloc_smes(long param_1)

{
  undefined2 *puVar1;
  ushort *puVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  undefined1 uVar6;
  ushort uVar7;
  short sVar8;
  int iVar9;
  code *pcVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  undefined4 uVar15;
  short *psVar16;
  long lVar17;
  ulong uVar18;
  undefined8 *puVar19;
  long lVar20;
  uint uVar21;
  uint uVar22;
  long *plVar23;
  long lVar24;
  long lVar25;
  long local_a8 [11];
  
  lVar13 = sp_el0;
  local_a8[10] = *(long *)(lVar13 + 0x638);
  lVar13 = *(long *)(param_1 + 0x338);
  if (lVar13 == 0) {
    lVar24 = 0;
    plVar23 = (long *)0x0;
  }
  else {
    lVar24 = *(long *)(lVar13 + 0x40);
    plVar23 = *(long **)(lVar13 + 0x50);
  }
  lVar20 = *plVar23;
  lVar25 = *(long *)(lVar20 + 0x68);
  lVar13 = 0;
  if (*(long *)(param_1 + 0x2e8) != 0) {
    local_a8[8] = 0;
    local_a8[9] = 0;
    local_a8[6] = 0;
    local_a8[7] = 0;
    local_a8[4] = 0;
    local_a8[5] = 0;
    local_a8[2] = 0;
    local_a8[3] = 0;
    local_a8[0] = 0;
    local_a8[1] = 0;
    iVar11 = __of_parse_phandle_with_args
                       (*(long *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_a8);
    if ((iVar11 != 0) || (lVar13 = local_a8[0], local_a8[0] == 0)) {
      lVar13 = *(long *)(param_1 + 0x2e8);
    }
  }
  lVar12 = of_find_property(lVar13,"qcom,iommu-defer-smr-config",0);
  lVar13 = lVar20 + 0x78;
  mutex_lock(lVar13);
  if (*(int *)(lVar24 + 0x14) != 0) {
    uVar14 = 0;
    iVar11 = -1;
    do {
      psVar16 = (short *)((long)plVar23 + (long)(int)uVar14 * 2 + 8);
      if (*psVar16 != -1) {
        uVar22 = 0xffffffef;
LAB_0010a24c:
        if (uVar14 != 0) {
          do {
            psVar16 = (short *)((long)plVar23 + (long)iVar11 * 2 + 8);
            sVar8 = *psVar16;
            lVar24 = *(long *)(lVar20 + 0x70) + (long)(int)sVar8 * 0x18;
            cVar5 = *(char *)(lVar24 + 0x15);
            iVar9 = *(int *)(lVar24 + 8) + -1;
            uVar6 = *(undefined1 *)(lVar24 + 0x14);
            *(int *)(lVar24 + 8) = iVar9;
            if (iVar9 == 0) {
              puVar19 = (undefined8 *)(*(long *)(lVar20 + 0x70) + (long)(int)sVar8 * 0x18);
              uVar15 = 1;
              if (disable_bypass != '\0') {
                uVar15 = 2;
              }
              *puVar19 = 0;
              *(undefined4 *)(puVar19 + 1) = 0;
              *(undefined4 *)((long)puVar19 + 0xc) = uVar15;
              puVar19[2] = 0;
              if (cVar5 == '\0') {
                if (*(long *)(lVar20 + 0x68) != 0) {
                  lVar24 = (long)sVar8 * 8;
                  *(undefined1 *)(*(long *)(lVar20 + 0x68) + lVar24 + 4) = 0;
                  *(undefined1 *)(*(long *)(lVar20 + 0x68) + lVar24 + 6) = 0;
                }
              }
              else {
                lVar24 = (long)sVar8 * 0x18;
                *(undefined1 *)(*(long *)(lVar20 + 0x70) + lVar24 + 0x15) = 1;
                *(undefined1 *)(*(long *)(lVar20 + 0x70) + lVar24 + 0x14) = uVar6;
              }
            }
            iVar11 = iVar11 + -1;
            *psVar16 = -1;
          } while (iVar11 != -1);
        }
        mutex_unlock(lVar13);
        goto LAB_0010a3dc;
      }
      lVar17 = *(long *)(lVar20 + 0x68);
      uVar4 = *(uint *)(lVar24 + (long)(int)uVar14 * 4 + 0x18);
      if (lVar17 != 0) {
        if (*(uint *)(lVar20 + 0x5c) == 0) {
          uVar22 = 0xffffffe4;
        }
        else {
          uVar21 = 0xffffffe4;
          uVar3 = 0;
          do {
            uVar22 = uVar3;
            if (*(char *)(lVar17 + (long)(int)uVar22 * 8 + 6) == '\0') {
              uVar3 = uVar22;
              if (-1 < (int)uVar21) {
                uVar3 = uVar21;
              }
              uVar21 = uVar3;
            }
            else {
              puVar2 = (ushort *)(lVar17 + (long)(int)uVar22 * 8);
              uVar7 = *puVar2;
              uVar3 = (uint)puVar2[1] ^ uVar4 & 0xffff;
              if ((uVar4 >> 0x10 & (uVar7 ^ 0xffffffff)) == 0 && (uVar3 & (uVar7 ^ 0xffffffff)) == 0
                 ) break;
              if ((uVar3 & (((uint)uVar7 | uVar4 >> 0x10) ^ 0xffffffff)) == 0) {
                uVar22 = 0xffffffea;
                goto LAB_0010a24c;
              }
            }
            uVar3 = uVar22 + 1;
            uVar22 = uVar21;
          } while (*(uint *)(lVar20 + 0x5c) != uVar3);
          if (-1 < (int)uVar22) goto LAB_0010a214;
        }
        goto LAB_0010a24c;
      }
      uVar22 = uVar4 & 0xffff;
LAB_0010a214:
      uVar18 = (ulong)uVar22;
      if (lVar25 != 0) {
        if (*(int *)(*(long *)(lVar20 + 0x70) + (ulong)uVar22 * 0x18 + 8) == 0) {
          puVar1 = (undefined2 *)(lVar25 + uVar18 * 8);
          puVar1[1] = (short)uVar4;
          *puVar1 = (short)(uVar4 >> 0x10);
          *(bool *)(puVar1 + 2) = lVar12 == 0;
          *(undefined1 *)(puVar1 + 3) = 1;
        }
        else if ((bool)*(char *)(lVar25 + uVar18 * 8 + 4) != (lVar12 == 0)) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x10a244);
          (*pcVar10)();
        }
      }
      uVar14 = uVar14 + 1;
      iVar11 = iVar11 + 1;
      lVar17 = *(long *)(lVar20 + 0x70) + uVar18 * 0x18;
      *(int *)(lVar17 + 8) = *(int *)(lVar17 + 8) + 1;
      *psVar16 = (short)uVar22;
    } while (uVar14 < *(uint *)(lVar24 + 0x14));
  }
  mutex_unlock(lVar13);
  if (*(int *)(lVar24 + 0x14) != 0) {
    uVar14 = 0;
    do {
      sVar8 = *(short *)((long)plVar23 + (long)(int)uVar14 * 2 + 8);
      arm_smmu_write_s2cr(lVar20,(int)sVar8);
      lVar13 = *(long *)(lVar20 + 0x68);
      if (lVar13 != 0) {
        puVar1 = (undefined2 *)(lVar13 + (long)(int)sVar8 * 8);
        uVar22 = CONCAT22(*puVar1,puVar1[1]);
        if ((*(byte *)(lVar20 + 0x21) >> 4 & 1) == 0) {
          if (*(char *)(lVar13 + (long)(int)sVar8 * 8 + 4) != '\0') {
            uVar22 = uVar22 | 0x80000000;
          }
        }
        if ((*(long *)(lVar20 + 0x30) == 0) ||
           (pcVar10 = *(code **)(*(long *)(lVar20 + 0x30) + 8), pcVar10 == (code *)0x0)) {
          writel_relaxed(uVar22,*(long *)(lVar20 + 8) + (long)(int)sVar8 * 4 + 0x800);
        }
        else {
          if (*(int *)(pcVar10 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10a3d0);
            (*pcVar10)();
          }
          (*pcVar10)(lVar20,0);
        }
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 < *(uint *)(lVar24 + 0x14));
  }
  uVar22 = 0;
LAB_0010a3dc:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar22;
}



//------------------------------------------------------------
// __bus_lookup_iommu_group @ 0010a42c size=204
// signature: undefined __bus_lookup_iommu_group(void)
// callers: []
//------------------------------------------------------------

void __bus_lookup_iommu_group(long param_1,long *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long local_88 [11];
  
  lVar3 = sp_el0;
  local_88[10] = *(long *)(lVar3 + 0x638);
  lVar3 = iommu_group_get();
  uVar4 = 0;
  if (lVar3 != 0) {
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
    iVar2 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_88);
    lVar1 = local_88[0];
    if (iVar2 != 0) {
      lVar1 = 0;
    }
    if (lVar1 == *param_2) {
      uVar4 = 1;
      param_2[1] = lVar3;
    }
    else {
      iommu_group_put(lVar3);
      uVar4 = 0;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_init_context_bank @ 0010a4f8 size=720
// signature: undefined arm_smmu_init_context_bank(void)
// callers: [arm_smmu_pm_restore_early, arm_smmu_attach_dev]
//------------------------------------------------------------

void arm_smmu_init_context_bank(long *param_1,ulong *param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  ulong *puVar5;
  long lVar6;
  uint *puVar7;
  ulong uVar8;
  uint *puVar9;
  ulong uVar10;
  long lVar11;
  ulong uVar12;
  
  iVar1 = *(int *)((long)param_1 + 0x3c);
  lVar11 = *(long *)(*param_1 + 0x50);
  uVar12 = (ulong)*(byte *)(param_1 + 6);
  puVar5 = (ulong *)(lVar11 + uVar12 * 0x30);
  puVar5[5] = (ulong)(param_1 + 6);
  if (iVar1 == 0) {
    uVar4 = (uint)param_2[7];
    *(uint *)(lVar11 + uVar12 * 0x30 + 0x10) =
         (uVar4 & 0x18) << 0xb | (uVar4 & 7) << 0x10 | (uVar4 & 0x60) << 7 | (uVar4 & 0x180) << 3 |
         uVar4 >> 1 & 0x300 | uVar4 >> 5 & 0xc0 | uVar4 >> 0xd & 0x3f | 0x80000000;
    *puVar5 = param_2[6];
  }
  else {
    if ((int)param_1[8] == 3) {
      *(undefined4 *)(lVar11 + uVar12 * 0x30 + 0x10) = *(undefined4 *)((long)param_2 + 0x34);
    }
    else {
      uVar4 = (uint)param_2[7];
      uVar4 = (uVar4 & 0x60) << 7 | (uVar4 >> 3 & 3) << 0xe | (uVar4 >> 7 & 3) << 10 |
              uVar4 >> 1 & 0x300 | uVar4 >> 0xb & 0x3f;
      lVar6 = lVar11 + uVar12 * 0x30;
      uVar3 = uVar4 | 0x800000;
      if ((*param_2 & 0x20) != 0) {
        uVar3 = uVar4 << 0x10 | 0x80;
      }
      puVar9 = (uint *)(lVar6 + 0x10);
      *puVar9 = uVar3;
      uVar8 = param_2[7];
      puVar7 = (uint *)(lVar6 + 0x14);
      *puVar7 = (uint)uVar8 & 7 | 0x38000;
      if ((int)param_1[8] == 1) {
        *puVar7 = (uint)uVar8 & 7 | 0x38010;
      }
      else {
        *puVar9 = uVar3 | 0x80000000;
      }
    }
    if ((int)param_1[8] == 3) {
      uVar8 = (ulong)(uint)param_2[6];
      puVar5[1] = 0;
LAB_0010a66c:
      *puVar5 = uVar8;
    }
    else {
      uVar8 = (ulong)*(ushort *)((long)param_1 + 0x32) << 0x30;
      *puVar5 = uVar8;
      uVar10 = (ulong)*(ushort *)((long)param_1 + 0x32) << 0x30;
      puVar5[1] = uVar10;
      if (((byte)*param_2 >> 5 & 1) == 0) {
        uVar8 = param_2[6] | uVar8;
        goto LAB_0010a66c;
      }
      puVar5[1] = param_2[6] | uVar10;
    }
    if ((int)param_1[8] == 3) {
      lVar6 = lVar11 + uVar12 * 0x30;
      *(undefined4 *)(lVar6 + 0x18) = *(undefined4 *)((long)param_2 + 0x3c);
      *(int *)(lVar6 + 0x1c) = (int)param_2[7];
    }
    else {
      lVar6 = lVar11 + uVar12 * 0x30;
      *(int *)(lVar6 + 0x18) = (int)param_2[8];
      *(undefined4 *)(lVar6 + 0x1c) = *(undefined4 *)((long)param_2 + 0x44);
    }
  }
  *(undefined4 *)(param_1 + 7) = 0;
  uVar8 = of_dma_is_coherent(*(undefined8 *)(param_1[1] + 0x2e8));
  bVar2 = *(byte *)(param_1 + 0x11);
  uVar4 = *(ushort *)(param_1 + 7) & 0xffffc000 | 0x7da;
  if ((uVar8 & 1) == 0) {
    uVar4 = *(ushort *)(param_1 + 7) | 0x30;
  }
  uVar4 = (uVar4 & 0xffffc000 | ((bVar2 & 2) >> 1) << 0xd | ((bVar2 & 4) >> 2) << 0xc |
          uVar4 & 0x7ff | (bVar2 >> 3 & 1) << 0xb) ^ 0x3000;
  *(short *)(param_1 + 7) = (short)uVar4;
  if ((*(byte *)((long)param_1 + 0x89) & 1) == 0) {
    if ((iVar1 != 0) && (*(char *)((long)param_1 + 0x8a) != '\0')) goto LAB_0010a738;
  }
  else if (iVar1 != 0) goto LAB_0010a738;
  uVar4 = uVar4 | 0x4000;
  *(short *)(param_1 + 7) = (short)uVar4;
LAB_0010a738:
  uVar3 = 0x46;
  if (*(int *)((long)param_1 + 0x3c) != 0) {
    uVar3 = 0x1046;
  }
  *(uint *)(lVar11 + uVar12 * 0x30 + 0x20) =
       (uVar4 & 3) << 0x1a |
       uVar3 | uVar4 >> 0xe | uVar4 >> 3 & 0x100 | uVar4 >> 5 & 0x80 | uVar4 >> 8 & 0x20 |
       (uVar4 >> 2 & 3) << 0x18 |
       (uVar4 & 0x30) << 0x12 | (uVar4 & 0x40) << 0xe | (uVar4 & 0x780) << 9;
  return;
}



//------------------------------------------------------------
// arm_smmu_context_fault @ 0010a7cc size=3556
// signature: undefined arm_smmu_context_fault(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_context_fault(undefined8 param_1,long param_2)

{
  int *piVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined *puVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined *puVar10;
  char *pcVar11;
  long *plVar12;
  int iVar13;
  byte bVar14;
  char cVar15;
  bool bVar16;
  undefined2 uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  ulong uVar26;
  undefined8 uVar27;
  ulong uVar28;
  long lVar29;
  undefined8 uVar30;
  long lVar31;
  code *pcVar32;
  undefined8 *puVar33;
  long *plVar34;
  uint uVar35;
  long lVar36;
  undefined8 local_98;
  uint local_90;
  uint uStack_8c;
  long local_88;
  long local_80;
  long local_78;
  undefined8 local_70;
  long local_68;
  
  lVar36 = sp_el0;
  local_68 = *(long *)(lVar36 + 0x638);
  plVar34 = *(long **)(param_2 + -0xc0);
  bVar14 = *(byte *)(param_2 + -0x90);
  lVar36 = *plVar34;
  if (((*(ushort *)(lVar36 + 0x200) & 7) == 0) &&
     (iVar18 = __pm_runtime_resume(lVar36,4), iVar18 < 0)) {
    piVar1 = (int *)(lVar36 + 0x1f8);
    iVar18 = *(int *)(lVar36 + 0x1f8);
    do {
      if (iVar18 == 0) {
        uVar27 = 0;
        break;
      }
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar13 = *piVar1;
        if (iVar13 != iVar18) goto LAB_0010a9e0;
        cVar15 = '\x01';
        bVar16 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar16) {
          *piVar1 = iVar18 + -1;
          cVar15 = ExclusiveMonitorsStatus();
        }
      } while (cVar15 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010a9e0:
      uVar27 = 0;
      bVar16 = iVar18 != iVar13;
      iVar18 = iVar13;
    } while (bVar16);
    goto LAB_0010b258;
  }
  iVar18 = (int)plVar34[3] + (uint)bVar14;
  if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
     (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
    uVar19 = readl_relaxed(plVar34[1] +
                           (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) + 0x58)
    ;
  }
  else {
    if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b14c);
      (*pcVar32)();
    }
    uVar19 = (*pcVar32)(plVar34,iVar18,0x58);
  }
  if ((uVar19 & 0xc00001fe) == 0) {
    uVar27 = 0;
  }
  else {
    if (((*(byte *)((long)plVar34 + 0x24) & 1) != 0) && ((uVar19 >> 7 & 1) != 0)) {
      _dev_err(*plVar34,"Took an address size fault.  Refusing to recover.\n");
                    /* WARNING: Does not return */
      pcVar32 = (code *)SoftwareBreakpoint(0x800,0x10b5c4);
      (*pcVar32)();
    }
    iVar18 = (int)plVar34[3] + (uint)bVar14;
    if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
       (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
      uVar26 = readl_relaxed(plVar34[1] +
                             (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                             0x58);
    }
    else {
      if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
        pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b174);
        (*pcVar32)();
      }
      uVar26 = (*pcVar32)(plVar34,iVar18,0x58);
    }
    uVar21 = (uint)bVar14;
    iVar18 = (int)plVar34[3] + uVar21;
    if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
       (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
      uVar20 = readl_relaxed(plVar34[1] +
                             (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                             0x68);
    }
    else {
      if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
        pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b19c);
        (*pcVar32)();
      }
      uVar20 = (*pcVar32)(plVar34,iVar18,0x68);
    }
    iVar18 = (int)plVar34[3] + uVar21;
    if ((plVar34[6] == 0) || (pcVar32 = *(code **)(plVar34[6] + 0x10), pcVar32 == (code *)0x0)) {
      uVar27 = readq_relaxed(plVar34[1] +
                             (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                             0x60);
    }
    else {
      if (*(int *)(pcVar32 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
        pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b1c4);
        (*pcVar32)();
      }
      uVar27 = (*pcVar32)(plVar34,iVar18,0x60);
    }
    iVar18 = report_iommu_fault(param_2,*plVar34,uVar27,
                                (uint)uVar26 & 0x18 | ((uint)((uVar26 & 0xffffffff) >> 1) & 1) << 2
                                | (uint)uVar26 >> 0x19 & 0x20 | uVar20 >> 4 & 1);
    if (iVar18 != -0x10) {
      uVar20 = (uint)bVar14;
      if (iVar18 == -0x26) {
        iVar18 = ___ratelimit(arm_smmu_context_fault__rs,"arm_smmu_context_fault");
        if (iVar18 == 0) {
          bVar14 = *(byte *)(param_2 + -0x38);
        }
        else {
          iVar18 = (int)plVar34[3] + uVar21;
          lVar36 = *(long *)(plVar34[10] + (ulong)uVar21 * 0x30 + 0x28);
          iVar13 = *(int *)(lVar36 + 0xc);
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar21 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x58);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b2ec);
              (*pcVar32)();
            }
            uVar21 = (*pcVar32)(plVar34,iVar18,0x58);
          }
          uVar35 = (uint)bVar14;
          iVar18 = (int)plVar34[3] + uVar35;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar22 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x68);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b314);
              (*pcVar32)();
            }
            uVar22 = (*pcVar32)(plVar34,iVar18,0x68);
          }
          iVar18 = (int)plVar34[3] + uVar35;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar23 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x6c);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b33c);
              (*pcVar32)();
            }
            uVar23 = (*pcVar32)(plVar34,iVar18,0x6c);
          }
          iVar18 = (int)plVar34[3] + uVar35;
          if ((plVar34[6] == 0) || (pcVar32 = *(code **)(plVar34[6] + 0x10), pcVar32 == (code *)0x0)
             ) {
            uVar27 = readq_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x60);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b364);
              (*pcVar32)();
            }
            uVar27 = (*pcVar32)(plVar34,iVar18,0x60);
          }
          uVar26 = (ulong)bVar14 << 2 | 0x400;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar17 = readl_relaxed(plVar34[1] +
                                   (long)(1 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                                   uVar26);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b390);
              (*pcVar32)();
            }
            uVar17 = (*pcVar32)(plVar34,1,uVar26);
          }
          lVar31 = (*(long **)(param_2 + -0xb8))[0xe];
          if (lVar31 == 0) {
            lVar31 = **(long **)(param_2 + -0xb8);
          }
          _dev_err(*plVar34,"Unhandled arm-smmu context fault from %s!\n",lVar31);
          _dev_err(*plVar34,"FAR    = 0x%016lx\n",uVar27);
          lVar31 = *plVar34;
          iVar18 = (int)plVar34[3] + uVar35;
          if ((plVar34[6] == 0) || (pcVar32 = *(code **)(plVar34[6] + 0x10), pcVar32 == (code *)0x0)
             ) {
            uVar27 = readq_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x50);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b3b8);
              (*pcVar32)();
            }
            uVar27 = (*pcVar32)(plVar34,iVar18,0x50);
          }
          _dev_err(lVar31,"PAR    = 0x%pK\n",uVar27);
          bVar16 = (uVar22 & 0x10) != 0;
          pcVar2 = "TF R ";
          if (bVar16) {
            pcVar2 = "TF W ";
          }
          pcVar3 = "PF R ";
          if (bVar16) {
            pcVar3 = "PF W ";
          }
          pcVar4 = "";
          if ((uVar21 & 2) != 0) {
            pcVar4 = pcVar2;
          }
          puVar5 = &DAT_00119084;
          if ((uVar21 & 4) != 0) {
            puVar5 = &DAT_00119020;
          }
          pcVar2 = "";
          if ((uVar21 & 8) != 0) {
            pcVar2 = pcVar3;
          }
          puVar6 = &DAT_00119084;
          if ((uVar21 & 0x10) != 0) {
            puVar6 = &DAT_00118a6d;
          }
          pcVar3 = "";
          if ((uVar21 & 0x20) != 0) {
            pcVar3 = "TLBMCF ";
          }
          pcVar7 = "";
          if ((uVar21 & 0x40) != 0) {
            pcVar7 = "TLBLKF ";
          }
          puVar8 = &DAT_00119084;
          if ((uVar21 & 0x80) != 0) {
            puVar8 = &DAT_00119099;
          }
          puVar9 = &DAT_00119084;
          if ((uVar21 & 0x100) != 0) {
            puVar9 = &DAT_00118bff;
          }
          puVar10 = &DAT_00119084;
          if ((uVar21 & 0x40000000) != 0) {
            puVar10 = &DAT_001197fb;
          }
          pcVar11 = "";
          if ((int)uVar21 < 0) {
            pcVar11 = "MULTI ";
          }
          _dev_err(*plVar34,"FSR    = 0x%08x [%s%s%s%s%s%s%s%s%s%s]\n",uVar21,pcVar4,puVar5,pcVar2,
                   puVar6,pcVar3,pcVar7,puVar8,puVar9,puVar10,pcVar11);
          _dev_err(*plVar34,"FSYNR0    = 0x%x\n",uVar22);
          _dev_err(*plVar34,"FSYNR1    = 0x%x\n",uVar23);
          _dev_err(*plVar34,"context bank#    = 0x%x\n",uVar35);
          lVar31 = *plVar34;
          iVar18 = (int)plVar34[3] + uVar35;
          puVar33 = (undefined8 *)plVar34[6];
          if (*(int *)(lVar36 + 0x10) == 3) {
            if ((puVar33 == (undefined8 *)0x0) ||
               (pcVar32 = (code *)*puVar33, pcVar32 == (code *)0x0)) {
              uVar24 = readl_relaxed(plVar34[1] +
                                     (long)(iVar18 <<
                                           (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) + 0x20);
            }
            else {
              if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b528);
                (*pcVar32)();
              }
              uVar24 = (*pcVar32)(plVar34,iVar18,0x20);
            }
            _dev_err(lVar31,"TTBR0  = 0x%pK\n",uVar24);
            lVar36 = *plVar34;
            iVar18 = (int)plVar34[3] + uVar20;
            if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
               (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
              uVar28 = readl_relaxed(plVar34[1] +
                                     (long)(iVar18 <<
                                           (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) + 0x28);
              uVar28 = uVar28 & 0xffffffff;
            }
            else {
              if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b550);
                (*pcVar32)();
              }
              uVar28 = (*pcVar32)(plVar34,iVar18,0x28);
              uVar28 = uVar28 & 0xffffffff;
            }
LAB_0010addc:
            _dev_err(lVar36,"TTBR1  = 0x%pK\n",uVar28);
          }
          else {
            if ((puVar33 == (undefined8 *)0x0) ||
               (pcVar32 = (code *)puVar33[2], pcVar32 == (code *)0x0)) {
              uVar27 = readq_relaxed(plVar34[1] +
                                     (long)(iVar18 <<
                                           (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) + 0x20);
            }
            else {
              if (*(int *)(pcVar32 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
                pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b57c);
                (*pcVar32)();
              }
              uVar27 = (*pcVar32)(plVar34,iVar18,0x20);
            }
            _dev_err(lVar31,"TTBR0  = 0x%pK\n",uVar27);
            if (iVar13 != 0) {
              lVar36 = *plVar34;
              iVar18 = (int)plVar34[3] + uVar20;
              if ((plVar34[6] == 0) ||
                 (pcVar32 = *(code **)(plVar34[6] + 0x10), pcVar32 == (code *)0x0)) {
                uVar28 = readq_relaxed(plVar34[1] +
                                       (long)(iVar18 <<
                                             (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) + 0x28
                                      );
              }
              else {
                if (*(int *)(pcVar32 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
                  pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b5a8);
                  (*pcVar32)();
                }
                uVar28 = (*pcVar32)(plVar34,iVar18,0x28);
              }
              goto LAB_0010addc;
            }
          }
          lVar36 = *plVar34;
          iVar18 = (int)plVar34[3] + uVar35;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar24 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                  );
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b3e0);
              (*pcVar32)();
            }
            uVar24 = (*pcVar32)(plVar34,iVar18,0);
          }
          lVar31 = (ulong)bVar14 * 4;
          iVar18 = (int)plVar34[3] + uVar35;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar25 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 4);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b408);
              (*pcVar32)();
            }
            uVar25 = (*pcVar32)(plVar34,iVar18,4);
          }
          _dev_err(lVar36,"SCTLR  = 0x%08x ACTLR  = 0x%08x\n",uVar24,uVar25);
          lVar36 = *plVar34;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar24 = readl_relaxed(plVar34[1] +
                                   (long)(1 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                                   lVar31);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b434);
              (*pcVar32)();
            }
            uVar24 = (*pcVar32)(plVar34,1,lVar31);
          }
          _dev_err(lVar36,"CBAR  = 0x%08x\n",uVar24);
          lVar36 = *plVar34;
          iVar18 = (int)plVar34[3] + uVar20;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar24 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x38);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b45c);
              (*pcVar32)();
            }
            uVar24 = (*pcVar32)(plVar34,iVar18,0x38);
          }
          iVar18 = (int)plVar34[3] + uVar20;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar25 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x3c);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b484);
              (*pcVar32)();
            }
            uVar25 = (*pcVar32)(plVar34,iVar18,0x3c);
          }
          _dev_err(lVar36,"MAIR0   = 0x%08x MAIR1   = 0x%08x\n",uVar24,uVar25);
          _dev_err(*plVar34,"SID = 0x%x\n",uVar17);
          _dev_err(*plVar34,"Client info: BID=0x%lx, PID=0x%lx, MID=0x%lx\n",uVar23 >> 0xd & 7,
                   uVar23 >> 8 & 0x1f,uVar23 & 0xff);
          local_88 = 0;
          local_80 = 0;
          iVar18 = (int)plVar34[3] + uVar20;
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uVar21 = readl_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x68);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b4ac);
              (*pcVar32)();
            }
            uVar21 = (*pcVar32)(plVar34,iVar18,0x68);
          }
          iVar18 = (int)plVar34[3] + uVar20;
          if ((plVar34[6] == 0) || (pcVar32 = *(code **)(plVar34[6] + 0x10), pcVar32 == (code *)0x0)
             ) {
            uVar27 = readq_relaxed(plVar34[1] +
                                   (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f))
                                   + 0x60);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b4d4);
              (*pcVar32)();
            }
            uVar27 = (*pcVar32)(plVar34,iVar18,0x60);
          }
          if (((undefined8 *)plVar34[6] == (undefined8 *)0x0) ||
             (pcVar32 = *(code **)plVar34[6], pcVar32 == (code *)0x0)) {
            uStack_8c = readl_relaxed(plVar34[1] +
                                      (long)(1 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                                      uVar26);
          }
          else {
            if (*(int *)(pcVar32 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b500);
              (*pcVar32)();
            }
            uStack_8c = (*pcVar32)(plVar34,1,uVar26);
          }
          local_70 = arm_smmu_iova_to_phys(param_2,uVar27);
          _dev_err(*plVar34,"soft iova-to-phys=%pa\n",&local_70);
          uVar21 = uVar21 >> 4 & 7;
          uStack_8c = uStack_8c & 0xffff;
          local_98 = uVar27;
          local_90 = uVar21;
          lVar36 = arm_smmu_iova_to_phys_hard(param_2,&local_98);
          local_78 = lVar36;
          if (lVar36 == 0) {
            local_90 = 2;
            lVar31 = arm_smmu_iova_to_phys_hard(param_2,&local_98);
            local_80 = lVar31;
          }
          else {
            lVar31 = 0;
          }
          pcVar32 = *(code **)(*(long *)(param_2 + 8) + 0x38);
          if (pcVar32 != (code *)0x0) {
            if (*(int *)(pcVar32 + -4) != -0x856fbb8) {
                    /* WARNING: Does not return */
              pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b09c);
              (*pcVar32)();
            }
            (*pcVar32)(param_2);
          }
          local_90 = uVar21;
          lVar29 = arm_smmu_iova_to_phys_hard(param_2,&local_98);
          local_88 = lVar29;
          if ((lVar36 == 0) && (lVar31 != 0)) {
            _dev_err(*plVar34,
                     "ATOS results differed across access privileges...\nBefore: %pa After: %pa\n",
                     &local_78,&local_80);
            lVar36 = local_78;
          }
          if (lVar36 != lVar29) {
            _dev_err(*plVar34,"ATOS results differed across TLBIALL...\nBefore: %pa After: %pa\n",
                     &local_78,&local_88);
            lVar29 = local_78;
          }
          plVar12 = &local_88;
          if (lVar29 != 0) {
            plVar12 = &local_78;
          }
          _dev_err(*plVar34,"hard iova-to-phys (ATOS)=%pa\n",plVar12);
          bVar14 = *(byte *)(param_2 + -0x38);
        }
        if ((bVar14 & 1) == 0) {
                    /* WARNING: Does not return */
          pcVar32 = (code *)SoftwareBreakpoint(0x800,0x10b12c);
          (*pcVar32)();
        }
      }
      iVar18 = (int)plVar34[3] + uVar20;
      if ((plVar34[6] == 0) || (pcVar32 = *(code **)(plVar34[6] + 8), pcVar32 == (code *)0x0)) {
        writel_relaxed(uVar19,plVar34[1] +
                              (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) +
                              0x58);
        DataSynchronizationBarrier(3,2,0);
      }
      else {
        if (*(int *)(pcVar32 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b1f0);
          (*pcVar32)();
        }
        (*pcVar32)(plVar34,iVar18,0x58,uVar19);
        DataSynchronizationBarrier(3,2,0);
      }
      if ((uVar19 >> 0x1e & 1) != 0) {
        iVar18 = (int)plVar34[3] + uVar20;
        if ((plVar34[6] == 0) || (pcVar32 = *(code **)(plVar34[6] + 8), pcVar32 == (code *)0x0)) {
          uVar27 = 1;
          writel_relaxed(1,plVar34[1] +
                           (long)(iVar18 << (ulong)(*(uint *)((long)plVar34 + 0x1c) & 0x1f)) + 8);
        }
        else {
          uVar27 = 1;
          if (*(int *)(pcVar32 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
            pcVar32 = (code *)SoftwareBreakpoint(0x8228,0x10b2c4);
            (*pcVar32)();
          }
          (*pcVar32)(plVar34,iVar18,8,1);
        }
        goto LAB_0010b234;
      }
    }
    uVar27 = 1;
  }
LAB_0010b234:
  lVar36 = *plVar34;
  if ((*(ushort *)(lVar36 + 0x200) & 7) == 0) {
    uVar30 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar36 + 0x220) = uVar30;
    __pm_runtime_suspend(*plVar34,0xd);
  }
LAB_0010b258:
  lVar36 = sp_el0;
  if (*(long *)(lVar36 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar27;
}



//------------------------------------------------------------
// arm_smmu_context_fault_irq @ 0010b5c8 size=76
// signature: undefined arm_smmu_context_fault_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_context_fault_irq(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_2 + -0x30);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x2532e06a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x10b600);
      (*pcVar1)();
    }
    (*pcVar1)(param_2,*(undefined8 *)(param_2 + -0x28));
  }
  return 2;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_context_s1 @ 0010b618 size=164
// signature: undefined arm_smmu_tlb_inv_context_s1(void)
// callers: [arm_smmu_tlb_inv_walk_s1]
//------------------------------------------------------------

void arm_smmu_tlb_inv_context_s1(long *param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  
  DataSynchronizationBarrier(3,2,0);
  lVar2 = *param_1;
  iVar1 = *(int *)(lVar2 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(long *)(lVar2 + 0x30) == 0) ||
     (pcVar3 = *(code **)(*(long *)(lVar2 + 0x30) + 8), pcVar3 == (code *)0x0)) {
    writel_relaxed(*(undefined2 *)((long)param_1 + 0x32),
                   *(long *)(lVar2 + 8) + (long)(iVar1 << (ulong)(*(uint *)(lVar2 + 0x1c) & 0x1f)) +
                   0x610);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10b6b4);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2,iVar1,0x610);
  }
  arm_smmu_tlb_sync_context(param_1);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_walk_s1 @ 0010b7f0 size=76
// signature: undefined arm_smmu_tlb_inv_walk_s1(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_inv_walk_s1(void)

{
  long in_x3;
  
  if (*(char *)(in_x3 + 0x44) == '\0') {
    arm_smmu_tlb_inv_range_s1();
    arm_smmu_tlb_sync_context(in_x3);
  }
  else {
    arm_smmu_tlb_inv_context_s1(in_x3);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_add_page_s1 @ 0010b840 size=40
// signature: undefined arm_smmu_tlb_add_page_s1(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_add_page_s1
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  arm_smmu_tlb_inv_range_s1(param_2,param_3,param_3,param_4,0x620);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_sync_context @ 0010b868 size=172
// signature: undefined arm_smmu_tlb_sync_context(void)
// callers: [arm_smmu_tlb_inv_walk_s2, arm_smmu_tlb_inv_context_s1, arm_smmu_tlb_inv_walk_s1]
//------------------------------------------------------------

void arm_smmu_tlb_sync_context(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)*param_1;
  uVar2 = _raw_spin_lock_irqsave((long)param_1 + 0x84);
  iVar1 = __arm_smmu_tlb_sync(puVar4,*(int *)(puVar4 + 3) + (uint)*(byte *)(param_1 + 6),0x7f0,0x7f4
                             );
  if ((iVar1 != 0) &&
     (iVar1 = ___ratelimit(arm_smmu_tlb_sync_context__rs,"arm_smmu_tlb_sync_context"), iVar1 != 0))
  {
    lVar3 = ((long *)param_1[1])[0xe];
    if (lVar3 == 0) {
      lVar3 = *(long *)param_1[1];
    }
    _dev_err(*puVar4,"TLB sync on cb%d failed for device %s\n",*(undefined1 *)(param_1 + 6),lVar3);
  }
  _raw_spin_unlock_irqrestore((long)param_1 + 0x84,uVar2);
  return;
}



//------------------------------------------------------------
// __arm_smmu_tlb_sync @ 0010b914 size=372
// signature: undefined __arm_smmu_tlb_sync(void)
// callers: [arm_smmu_tlb_inv_context_s2, arm_smmu_tlb_sync_context, arm_smmu_device_reset]
//------------------------------------------------------------

undefined8 __arm_smmu_tlb_sync(long param_1,int param_2,undefined8 param_3,int param_4)

{
  ulong uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
    writel_relaxed(0xffffffff,
                   *(long *)(param_1 + 8) +
                   (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)(int)param_3
                  );
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10ba80);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,param_2,param_3,0xffffffff);
  }
  uVar3 = 1;
  uVar4 = 1;
  while( true ) {
    if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
       (pcVar2 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar2 == (code *)0x0)) {
      uVar1 = readl_relaxed(*(long *)(param_1 + 8) + (long)param_4 +
                            (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
    }
    else {
      if (*(int *)(pcVar2 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10b9f4);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_1,param_2,param_4);
    }
    if ((uVar1 & 1) == 0) break;
    Yield();
    __udelay(uVar4);
    uVar4 = uVar4 << (uVar4 < 1000);
    uVar3 = uVar4 + uVar3;
    if (499999 < uVar3) {
      if ((*(long *)(param_1 + 0x30) != 0) &&
         (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 0x48), pcVar2 != (code *)0x0)) {
        if (*(int *)(pcVar2 + -4) != 0x59243587) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10ba38);
          (*pcVar2)();
        }
        (*pcVar2)(param_1);
      }
      return 0xffffffea;
    }
  }
  return 0;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_range_s1 @ 0010bb20 size=364
// signature: undefined arm_smmu_tlb_inv_range_s1(void)
// callers: [arm_smmu_tlb_add_page_s1, arm_smmu_tlb_inv_walk_s1]
//------------------------------------------------------------

void arm_smmu_tlb_inv_range_s1(ulong param_1,long param_2,ulong param_3,long *param_4,uint param_5)

{
  int iVar1;
  byte bVar2;
  ushort uVar3;
  code *pcVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  
  lVar5 = *param_4;
  bVar2 = *(byte *)(param_4 + 6);
  if ((*(byte *)(lVar5 + 0x20) & 1) != 0) {
    DataSynchronizationBarrier(3,2,0);
  }
  uVar3 = *(ushort *)((long)param_4 + 0x32);
  if ((int)param_4[8] == 1) {
    uVar6 = (ulong)uVar3 << 0x30 | param_1 >> 0xc;
    param_2 = -param_2;
    do {
      iVar1 = *(int *)(lVar5 + 0x18) + (uint)bVar2;
      if ((*(long *)(lVar5 + 0x30) == 0) ||
         (pcVar4 = *(code **)(*(long *)(lVar5 + 0x30) + 0x18), pcVar4 == (code *)0x0)) {
        writeq_relaxed(uVar6,*(long *)(lVar5 + 8) + (ulong)param_5 +
                             (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)));
      }
      else {
        if (*(int *)(pcVar4 + -4) != 0x6bc70ae0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10bbe8);
          (*pcVar4)();
        }
        (*pcVar4)(lVar5,iVar1,param_5,uVar6);
      }
      uVar6 = uVar6 + (param_3 >> 0xc);
      param_2 = param_2 + param_3;
    } while (param_2 != 0);
  }
  else {
    lVar7 = 0;
    do {
      iVar1 = *(int *)(lVar5 + 0x18) + (uint)bVar2;
      if ((*(long *)(lVar5 + 0x30) == 0) ||
         (pcVar4 = *(code **)(*(long *)(lVar5 + 0x30) + 8), pcVar4 == (code *)0x0)) {
        writel_relaxed((param_1 & 0xfffffffffffff000 | (ulong)uVar3) + lVar7 & 0xffffffff,
                       *(long *)(lVar5 + 8) + (long)(int)param_5 +
                       (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)));
      }
      else {
        if (*(int *)(pcVar4 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10bc68);
          (*pcVar4)();
        }
        (*pcVar4)(lVar5,iVar1,param_5);
      }
      lVar7 = lVar7 + param_3;
    } while (param_2 != lVar7);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_context_s2 @ 0010bc90 size=224
// signature: undefined arm_smmu_tlb_inv_context_s2(void)
// callers: [arm_smmu_tlb_inv_walk_s2_v1]
//------------------------------------------------------------

void arm_smmu_tlb_inv_context_s2(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  puVar4 = (undefined8 *)*param_1;
  DataSynchronizationBarrier(3,2,0);
  if ((puVar4[6] == 0) || (pcVar3 = *(code **)(puVar4[6] + 8), pcVar3 == (code *)0x0)) {
    writel_relaxed(*(undefined2 *)((long)param_1 + 0x32),puVar4[1] + 100);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10bd68);
      (*pcVar3)();
    }
    (*pcVar3)(puVar4,0,100);
  }
  uVar2 = _raw_spin_lock_irqsave(puVar4 + 0x1c);
  iVar1 = __arm_smmu_tlb_sync(puVar4,0,0x70,0x74);
  if ((iVar1 != 0) &&
     (iVar1 = ___ratelimit(arm_smmu_tlb_sync_global__rs,"arm_smmu_tlb_sync_global"), iVar1 != 0)) {
    _dev_err(*puVar4,"TLB global sync failed!\n");
  }
  _raw_spin_unlock_irqrestore(puVar4 + 0x1c,uVar2);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_walk_s2 @ 0010bd74 size=52
// signature: undefined arm_smmu_tlb_inv_walk_s2(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_inv_walk_s2(void)

{
  undefined8 in_x3;
  
  arm_smmu_tlb_inv_range_s2();
  arm_smmu_tlb_sync_context(in_x3);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_add_page_s2 @ 0010bdac size=40
// signature: undefined arm_smmu_tlb_add_page_s2(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_add_page_s2
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  arm_smmu_tlb_inv_range_s2(param_2,param_3,param_3,param_4,0x638);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_range_s2 @ 0010bdd4 size=332
// signature: undefined arm_smmu_tlb_inv_range_s2(void)
// callers: [arm_smmu_tlb_add_page_s2, arm_smmu_tlb_inv_walk_s2]
//------------------------------------------------------------

void arm_smmu_tlb_inv_range_s2(ulong param_1,long param_2,ulong param_3,long *param_4,uint param_5)

{
  int iVar1;
  byte bVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *param_4;
  bVar2 = *(byte *)(param_4 + 6);
  if ((*(byte *)(lVar4 + 0x20) & 1) != 0) {
    DataSynchronizationBarrier(3,2,0);
  }
  param_1 = param_1 >> 0xc;
  param_2 = -param_2;
  do {
    iVar1 = *(int *)(lVar4 + 0x18) + (uint)bVar2;
    if ((int)param_4[8] == 1) {
      if ((*(long *)(lVar4 + 0x30) == 0) ||
         (pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 0x18), pcVar3 == (code *)0x0)) {
        writeq_relaxed(param_1,*(long *)(lVar4 + 8) + (ulong)param_5 +
                               (long)(iVar1 << (ulong)(*(uint *)(lVar4 + 0x1c) & 0x1f)));
      }
      else {
        if (*(int *)(pcVar3 + -4) != 0x6bc70ae0) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10bef8);
          (*pcVar3)();
        }
        (*pcVar3)(lVar4,iVar1,param_5,param_1);
      }
    }
    else if ((*(long *)(lVar4 + 0x30) == 0) ||
            (pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 8), pcVar3 == (code *)0x0)) {
      writel_relaxed(param_1 & 0xffffffff,
                     *(long *)(lVar4 + 8) + (long)(int)param_5 +
                     (long)(iVar1 << (ulong)(*(uint *)(lVar4 + 0x1c) & 0x1f)));
    }
    else {
      if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10becc);
        (*pcVar3)();
      }
      (*pcVar3)(lVar4,iVar1,param_5,param_1 & 0xffffffff);
    }
    param_1 = param_1 + (param_3 >> 0xc);
    param_2 = param_2 + param_3;
  } while (param_2 != 0);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_inv_walk_s2_v1 @ 0010bf24 size=32
// signature: undefined arm_smmu_tlb_inv_walk_s2_v1(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_inv_walk_s2_v1(void)

{
  undefined8 in_x3;
  
  arm_smmu_tlb_inv_context_s2(in_x3);
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_add_page_s2_v1 @ 0010bf48 size=116
// signature: undefined arm_smmu_tlb_add_page_s2_v1(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_add_page_s2_v1(void)

{
  long lVar1;
  long *in_x3;
  code *pcVar2;
  
  lVar1 = *in_x3;
  if ((*(byte *)(lVar1 + 0x20) & 1) != 0) {
    DataSynchronizationBarrier(3,2,0);
  }
  if ((*(long *)(lVar1 + 0x30) == 0) ||
     (pcVar2 = *(code **)(*(long *)(lVar1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
    writel_relaxed(*(undefined2 *)((long)in_x3 + 0x32),*(long *)(lVar1 + 8) + 100);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10bfb4);
      (*pcVar2)();
    }
    (*pcVar2)(lVar1,0,100);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_tlb_add_walk_page @ 0010bfc0 size=116
// signature: undefined arm_smmu_tlb_add_walk_page(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_tlb_add_walk_page(long param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0xa0);
  puVar1 = (undefined8 *)((((param_2 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 + -0x1fffffff8);
  *(undefined1 *)(param_1 + 0xb0) = 1;
  *puVar1 = *(undefined8 *)(param_1 + 0xa8);
  *(undefined8 **)(param_1 + 0xa8) = puVar1;
  _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar2);
  return;
}



//------------------------------------------------------------
// arm_smmu_qcom_tlb_add_inv @ 0010c038 size=72
// signature: undefined arm_smmu_qcom_tlb_add_inv(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_qcom_tlb_add_inv(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0xa0);
  *(byte *)(param_1 + 0xb0) = *(byte *)(param_1 + 0x19d) ^ 1;
  _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar1);
  return;
}



//------------------------------------------------------------
// arm_smmu_qcom_tlb_sync @ 0010c084 size=356
// signature: undefined arm_smmu_qcom_tlb_sync(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_qcom_tlb_sync(undefined8 *param_1)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  code *pcVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long *plVar10;
  long lVar11;
  
  puVar1 = param_1 + 0x14;
  uVar8 = _raw_spin_lock_irqsave(puVar1);
  if (*(char *)((long)param_1 + 0x19d) == '\0') {
    _raw_spin_unlock_irqrestore(puVar1,uVar8);
    lVar11 = *(long *)*param_1;
    if (((*(ushort *)(lVar11 + 0x200) & 7) == 0) &&
       (iVar7 = __pm_runtime_resume(lVar11,4), iVar7 < 0)) {
      piVar2 = (int *)(lVar11 + 0x1f8);
      iVar7 = *(int *)(lVar11 + 0x1f8);
      do {
        if (iVar7 == 0) break;
        Hint_Prefetch(piVar2,2,0,1);
        do {
          iVar3 = *piVar2;
          if (iVar3 != iVar7) goto LAB_0010c1c8;
          cVar4 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar6) {
            *piVar2 = iVar7 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
LAB_0010c1c8:
        bVar6 = iVar7 != iVar3;
        iVar7 = iVar3;
      } while (bVar6);
    }
    uVar8 = _raw_spin_lock_irqsave(puVar1);
    if ((*(char *)((long)param_1 + 0x19d) == '\0') && (*(char *)(param_1 + 0x16) != '\0')) {
      if (*(int *)(*(code **)param_1[5] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10c130);
        (*pcVar5)();
      }
      (**(code **)param_1[5])(param_1);
      puVar9 = (undefined8 *)param_1[0x15];
      *(undefined1 *)(param_1 + 0x16) = 0;
      while (puVar9 != (undefined8 *)0x0) {
        param_1[0x15] = *puVar9;
        qcom_io_pgtable_free_page(puVar9 + -1);
        puVar9 = (undefined8 *)param_1[0x15];
      }
      param_1[0x15] = 0;
    }
    _raw_spin_unlock_irqrestore(puVar1,uVar8);
    plVar10 = (long *)*param_1;
    lVar11 = *plVar10;
    if ((*(ushort *)(lVar11 + 0x200) & 7) == 0) {
      uVar8 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar11 + 0x220) = uVar8;
      __pm_runtime_suspend(*plVar10,0xd);
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x16) = 0;
    _raw_spin_unlock_irqrestore(puVar1,uVar8);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_log_new_table @ 0010c200 size=92
// signature: undefined arm_smmu_log_new_table(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void arm_smmu_log_new_table(void)

{
  return;
}



//------------------------------------------------------------
// arm_smmu_log_remove_table @ 0010c310 size=92
// signature: undefined arm_smmu_log_remove_table(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void arm_smmu_log_remove_table(void)

{
  return;
}



//------------------------------------------------------------
// arm_smmu_pm_prepare @ 0010c420 size=164
// signature: undefined arm_smmu_pm_prepare(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_pm_prepare(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar5 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2e8),"qcom,adreno-smmu");
  if ((int)uVar5 != 0) {
    if (((*(int *)(param_1 + 0x20c) != 2) || ((*(ushort *)(param_1 + 0x200) & 7) != 0)) &&
       (*(int *)(param_1 + 0x1f8) == 1)) {
      iVar4 = __pm_runtime_suspend(param_1,4);
      piVar1 = (int *)(param_1 + 0x1f8);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (iVar4 < 0) {
        _dev_err(param_1,"sync supend failed to suspend the rpm\n");
        return 0xfffffff5;
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// arm_smmu_pm_suspend @ 0010c4d8 size=112
// signature: undefined arm_smmu_pm_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 arm_smmu_pm_suspend(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (_pm_suspend_target_state == 3) {
    uVar1 = arm_smmu_pm_freeze_late();
  }
  else {
    lVar2 = *(long *)(param_1 + 0x98);
    if ((*(int *)(param_1 + 0x20c) != 2) || ((*(ushort *)(param_1 + 0x200) & 7) != 0)) {
      arm_smmu_power_off(lVar2,*(undefined8 *)(lVar2 + 0x128));
    }
    clk_bulk_unprepare(*(undefined4 *)(lVar2 + 0xcc),*(undefined8 *)(lVar2 + 0xd8));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_pm_resume @ 0010c54c size=180
// signature: undefined arm_smmu_pm_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int arm_smmu_pm_resume(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (_pm_suspend_target_state == 3) {
    iVar1 = arm_smmu_pm_restore_early(param_1);
  }
  else {
    lVar2 = *(long *)(param_1 + 0x98);
    iVar1 = clk_bulk_prepare(*(undefined4 *)(lVar2 + 0xcc),*(undefined8 *)(lVar2 + 0xd8));
    if (iVar1 == 0) {
      if ((*(int *)(param_1 + 0x20c) == 2) && ((*(ushort *)(param_1 + 0x200) & 7) == 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = arm_smmu_power_on(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x128));
        if (iVar1 == 0) {
          arm_smmu_device_reset(lVar2);
        }
        else {
          clk_bulk_unprepare(*(undefined4 *)(lVar2 + 0xcc),*(undefined8 *)(lVar2 + 0xd8));
        }
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// arm_smmu_pm_freeze_late @ 0010c604 size=220
// signature: undefined arm_smmu_pm_freeze_late(void)
// callers: [arm_smmu_pm_suspend]
//------------------------------------------------------------

int arm_smmu_pm_freeze_late(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined8 *puVar5;
  
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  iVar1 = arm_smmu_power_on(puVar5[0x25]);
  if (iVar1 == 0) {
    uVar2 = *(uint *)(puVar5 + 7);
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        if (((puVar5[10] + (long)(int)uVar3 * 0x30 != 0) &&
            (lVar4 = *(long *)(puVar5[10] + (long)(int)uVar3 * 0x30 + 0x28),
            lVar4 != 0 && lVar4 != 0x30)) && (*(int *)(lVar4 + 0x5c) != -1)) {
          qcom_free_io_pgtable_ops(*(undefined8 *)(lVar4 + -0x20));
          uVar2 = *(uint *)(puVar5 + 7);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    arm_smmu_power_off(*(long *)(param_1 + 0x98),*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x128))
    ;
    arm_smmu_power_off(puVar5,puVar5[0x25]);
    iVar1 = 0;
  }
  else {
    _dev_err(*puVar5,"Couldn\'t power on the smmu during pm freeze: %d\n",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// arm_smmu_pm_restore_early @ 0010c6e4 size=340
// signature: undefined arm_smmu_pm_restore_early(void)
// callers: [arm_smmu_pm_resume]
//------------------------------------------------------------

int arm_smmu_pm_restore_early(long *param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  undefined8 *puVar4;
  uint uVar5;
  long lVar6;
  
  puVar4 = (undefined8 *)param_1[0x13];
  uVar3 = *(uint *)(puVar4 + 7);
  if (uVar3 != 0) {
    uVar5 = 0;
    do {
      lVar6 = *(long *)(puVar4[10] + (long)(int)uVar5 * 0x30 + 0x28);
      if ((lVar6 != 0) && (*(int *)(lVar6 + 0x5c) != -1)) {
        lVar2 = qcom_alloc_io_pgtable_ops(*(undefined4 *)(lVar6 + 0x168),lVar6 + 0xe8,lVar6 + -0x30)
        ;
        if (lVar2 == 0) {
          lVar6 = param_1[0xe];
          if (lVar6 == 0) {
            lVar6 = *param_1;
          }
          _dev_err(*puVar4,"failed to allocate page tables\tduring pm restore for cxt %d %s\n",uVar5
                   ,lVar6);
          return -0xc;
        }
        *(long *)(lVar6 + -0x20) = lVar2;
        arm_smmu_init_context_bank(lVar6 + -0x30,lVar6 + 0xe8);
        uVar3 = *(uint *)(puVar4 + 7);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar3);
    puVar4 = (undefined8 *)param_1[0x13];
  }
  iVar1 = clk_bulk_prepare(*(undefined4 *)((long)puVar4 + 0xcc),puVar4[0x1b]);
  if (iVar1 == 0) {
    if ((*(int *)((long)param_1 + 0x20c) == 2) && ((*(ushort *)(param_1 + 0x40) & 7) == 0)) {
      return 0;
    }
    iVar1 = arm_smmu_power_on(*(undefined8 *)(param_1[0x13] + 0x128));
    if (iVar1 == 0) {
      arm_smmu_device_reset(puVar4);
      return 0;
    }
    clk_bulk_unprepare(*(undefined4 *)((long)puVar4 + 0xcc),puVar4[0x1b]);
  }
  _dev_err(param_1,"Failed to resume\n");
  return iVar1;
}



//------------------------------------------------------------
// arm_smmu_runtime_suspend @ 0010c83c size=40
// signature: undefined arm_smmu_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_runtime_suspend(long param_1)

{
  arm_smmu_power_off(*(long *)(param_1 + 0x98),*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x128));
  return 0;
}



//------------------------------------------------------------
// arm_smmu_runtime_resume @ 0010c868 size=36
// signature: undefined arm_smmu_runtime_resume(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_runtime_resume(long param_1)

{
  arm_smmu_power_on(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x128));
  return;
}



//------------------------------------------------------------
// arm_mmu500_reset @ 0010c8d0 size=512
// signature: undefined arm_mmu500_reset(void)
// callers: [qcom_smmu500_reset]
//------------------------------------------------------------

undefined8 arm_mmu500_reset(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  code *pcVar5;
  
  if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
     (pcVar5 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar5 == (code *)0x0)) {
    uVar4 = readl_relaxed(*(long *)(param_1 + 8) + 0x3c);
  }
  else {
    if (*(int *)(pcVar5 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10ca58);
      (*pcVar5)();
    }
    uVar4 = (*pcVar5)(param_1,0,0x3c);
  }
  if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
     (pcVar5 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar5 == (code *)0x0)) {
    uVar2 = readl_relaxed(*(long *)(param_1 + 8) + 0x10);
  }
  else {
    if (*(int *)(pcVar5 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10ca84);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,0,0x10);
  }
  if ((uVar4 & 0xe0) != 0) {
    uVar2 = uVar2 & 0xfbfffaff;
  }
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar5 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar5 == (code *)0x0)) {
    writel_relaxed(uVar2 | 0x500,*(long *)(param_1 + 8) + 0x10);
    iVar1 = *(int *)(param_1 + 0x38);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10cab0);
      (*pcVar5)();
    }
    (*pcVar5)(param_1,0,0x10);
    iVar1 = *(int *)(param_1 + 0x38);
  }
  if (iVar1 != 0) {
    uVar2 = 0;
    do {
      iVar1 = uVar2 + *(int *)(param_1 + 0x18);
      if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
         (pcVar5 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar5 == (code *)0x0)) {
        uVar3 = readl_relaxed(*(long *)(param_1 + 8) +
                              (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 4);
      }
      else {
        if (*(int *)(pcVar5 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10ca04);
          (*pcVar5)();
        }
        uVar3 = (*pcVar5)(param_1,iVar1,4);
      }
      iVar1 = uVar2 + *(int *)(param_1 + 0x18);
      if ((*(long *)(param_1 + 0x30) == 0) ||
         (pcVar5 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar5 == (code *)0x0)) {
        writel_relaxed(uVar3 & 0xfffffffd,
                       *(long *)(param_1 + 8) +
                       (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + 4);
      }
      else {
        if (*(int *)(pcVar5 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10ca2c);
          (*pcVar5)();
        }
        (*pcVar5)(param_1,iVar1,4);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x38));
  }
  return 0;
}



//------------------------------------------------------------
// arm_smmu_impl_init @ 0010cad4 size=360
// signature: undefined arm_smmu_impl_init(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

long arm_smmu_impl_init(long *param_1)

{
  int iVar1;
  long lVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  
  if (*(int *)((long)param_1 + 0x2c) == 2) {
    lVar2 = devm_krealloc(*param_1,param_1,0x148,0xcc0);
    if (lVar2 == 0) {
      return -0xc;
    }
    puVar3 = cavium_impl;
  }
  else {
    uVar4 = *(undefined8 *)(*param_1 + 0x2e8);
    if (*(int *)((long)param_1 + 0x2c) == 1) {
      param_1[6] = (long)&arm_mmu500_impl;
    }
    lVar2 = of_find_property(uVar4,"calxeda,smmu-secure-config-access",0);
    if (lVar2 != 0) {
      param_1[6] = (long)&calxeda_impl;
    }
    iVar1 = of_device_is_compatible(uVar4,"nvidia,tegra234-smmu");
    if (((iVar1 != 0) || (iVar1 = of_device_is_compatible(uVar4,"nvidia,tegra194-smmu"), iVar1 != 0)
        ) || (iVar1 = of_device_is_compatible(uVar4,"nvidia,tegra186-smmu"), iVar1 != 0)) {
      lVar2 = nvidia_smmu_impl_init(param_1);
      return lVar2;
    }
    iVar1 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,qsmmu-v500");
    if (iVar1 != 0) {
      lVar2 = qsmmuv500_impl_init(param_1);
      return lVar2;
    }
    iVar1 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,smmu-v2");
    if (iVar1 != 0) {
      lVar2 = qsmmuv2_impl_init(param_1);
      return lVar2;
    }
    lVar2 = qcom_smmu_impl_init(param_1);
    iVar1 = of_device_is_compatible(uVar4,"marvell,ap806-smmu-500");
    if (iVar1 == 0) {
      return lVar2;
    }
    puVar3 = mrvl_mmu500_impl;
  }
  *(undefined1 **)(lVar2 + 0x30) = puVar3;
  return lVar2;
}



//------------------------------------------------------------
// readl_relaxed @ 0010cc3c size=124
// signature: undefined readl_relaxed(void)
// callers: [arm_mmu500_reset, mrvl_mmu500_readq, arm_smmu_read_ns]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x10cc84,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 0010ccb8 size=132
// signature: undefined writel_relaxed(void)
// callers: [arm_mmu500_reset, mrvl_mmu500_writeq, arm_smmu_write_ns]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10ccd0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10cd0c,uVar1);
  return;
}



//------------------------------------------------------------
// cavium_cfg_probe @ 0010cd40 size=96
// signature: undefined cavium_cfg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 cavium_cfg_probe(undefined8 *param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  Hint_Prefetch(0x1182c8,2,0,1);
  do {
    iVar3 = cavium_cfg_probe_context_count;
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(0x1182c8,0x10);
    if (bVar2) {
      cVar1 = ExclusiveMonitorsStatus();
      cavium_cfg_probe_context_count = cavium_cfg_probe_context_count + *(int *)(param_1 + 7);
    }
  } while (cVar1 != '\0');
  DataMemoryBarrier(2,3);
  *(int *)(param_1 + 0x28) = iVar3;
  _dev_notice(*param_1,"\tenabling workaround for Cavium erratum 27704\n");
  return 0;
}



//------------------------------------------------------------
// cavium_init_context @ 0010cdb0 size=32
// signature: undefined cavium_init_context(void)
// callers: []
//------------------------------------------------------------

undefined8 cavium_init_context(long *param_1)

{
  *(short *)((long)param_1 + 0x32) = *(short *)((long)param_1 + 0x32) + *(short *)(*param_1 + 0x140)
  ;
  return 0;
}



//------------------------------------------------------------
// arm_smmu_read_ns @ 0010cdd4 size=104
// signature: undefined arm_smmu_read_ns(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_read_ns(long param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    if ((((param_3 - 0x48U < 0x11) && ((1 << (ulong)(param_3 - 0x48U & 0x1f) & 0x11101U) != 0)) ||
        (param_3 == 0x10)) || (param_3 == 0)) {
      param_3 = param_3 + 0x400;
    }
  }
  readl_relaxed(*(long *)(param_1 + 8) +
                (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)param_3);
  return;
}



//------------------------------------------------------------
// arm_smmu_write_ns @ 0010ce40 size=108
// signature: undefined arm_smmu_write_ns(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_write_ns(long param_1,int param_2,int param_3,undefined4 param_4)

{
  if (param_2 == 0) {
    if ((((param_3 - 0x48U < 0x11) && ((1 << (ulong)(param_3 - 0x48U & 0x1f) & 0x11101U) != 0)) ||
        (param_3 == 0x10)) || (param_3 == 0)) {
      param_3 = param_3 + 0x400;
    }
  }
  writel_relaxed(param_4,*(long *)(param_1 + 8) +
                         (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
                         (long)param_3);
  return;
}



//------------------------------------------------------------
// mrvl_mmu500_readq @ 0010ceb0 size=80
// signature: undefined mrvl_mmu500_readq(void)
// callers: []
//------------------------------------------------------------

ulong mrvl_mmu500_readq(long param_1,int param_2,int param_3)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  
  lVar1 = *(long *)(param_1 + 8) + (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
          (long)param_3;
  lVar2 = readl_relaxed(lVar1 + 4);
  uVar3 = readl_relaxed(lVar1);
  return uVar3 & 0xffffffff | lVar2 << 0x20;
}



//------------------------------------------------------------
// mrvl_mmu500_writeq @ 0010cf04 size=84
// signature: undefined mrvl_mmu500_writeq(void)
// callers: []
//------------------------------------------------------------

void mrvl_mmu500_writeq(long param_1,int param_2,int param_3,ulong param_4)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 8) + (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
          (long)param_3;
  writel_relaxed(param_4 >> 0x20,lVar1 + 4);
  writel_relaxed(param_4 & 0xffffffff,lVar1);
  return;
}



//------------------------------------------------------------
// mrvl_mmu500_cfg_probe @ 0010cf5c size=24
// signature: undefined mrvl_mmu500_cfg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 mrvl_mmu500_cfg_probe(long param_1)

{
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffc7f;
  return 0;
}



//------------------------------------------------------------
// nvidia_smmu_impl_init @ 0010cf7c size=220
// signature: undefined nvidia_smmu_impl_init(void)
// callers: [arm_smmu_impl_init]
//------------------------------------------------------------

ulong nvidia_smmu_impl_init(long *param_1)

{
  undefined **ppuVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  
  lVar6 = *param_1;
  uVar2 = devm_krealloc(lVar6,param_1,0x160,0xcc0);
  if (uVar2 == 0) {
    uVar3 = 0xfffffffffffffff4;
  }
  else {
    uVar3 = devm_tegra_memory_controller_get(lVar6);
    *(ulong *)(uVar2 + 0x158) = uVar3;
    if (uVar3 < 0xfffffffffffff001) {
      *(long *)(uVar2 + 0x140) = param_1[1];
      *(int *)(uVar2 + 0x150) = *(int *)(uVar2 + 0x150) + 1;
      lVar4 = platform_get_resource(lVar6 + -0x10,0x200,1);
      if (lVar4 == 0) {
        iVar5 = *(int *)(uVar2 + 0x150);
      }
      else {
        uVar3 = devm_ioremap_resource(lVar6,lVar4);
        *(ulong *)(uVar2 + 0x148) = uVar3;
        if (0xfffffffffffff000 < uVar3) {
          return uVar3;
        }
        iVar5 = *(int *)(uVar2 + 0x150) + 1;
        *(int *)(uVar2 + 0x150) = iVar5;
      }
      ppuVar1 = (undefined **)&nvidia_smmu_single_impl;
      if (iVar5 != 1) {
        ppuVar1 = &nvidia_smmu_impl;
      }
      *(undefined ***)(uVar2 + 0x30) = ppuVar1;
      uVar3 = uVar2;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// nvidia_smmu_init_context @ 0010d05c size=112
// signature: undefined nvidia_smmu_init_context(void)
// callers: []
//------------------------------------------------------------

undefined8 nvidia_smmu_init_context(undefined8 *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  
  plVar3 = (long *)*param_1;
  uVar2 = *(undefined8 *)(*plVar3 + 0x2e8);
  iVar1 = of_device_is_compatible(uVar2,"nvidia,tegra234-smmu");
  if ((iVar1 != 0) || (iVar1 = of_device_is_compatible(uVar2,"nvidia,tegra194-smmu"), iVar1 != 0)) {
    plVar3[0x18] = 0x1000;
    *(undefined8 *)(param_2 + 8) = 0x1000;
  }
  return 0;
}



//------------------------------------------------------------
// nvidia_smmu_probe_finalize @ 0010d0d0 size=88
// signature: undefined nvidia_smmu_probe_finalize(void)
// callers: []
//------------------------------------------------------------

void nvidia_smmu_probe_finalize(undefined8 *param_1,long *param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = tegra_mc_probe_device(param_1[0x2b]);
  if (iVar1 < 0) {
    lVar2 = param_2[0xe];
    if (lVar2 == 0) {
      lVar2 = *param_2;
    }
    _dev_err(*param_1,"memory controller probe failed for %s: %d\n",lVar2,iVar1);
  }
  return;
}



//------------------------------------------------------------
// nvidia_smmu_read_reg @ 0010d12c size=48
// signature: undefined nvidia_smmu_read_reg(void)
// callers: []
//------------------------------------------------------------

void nvidia_smmu_read_reg(long param_1,int param_2,int param_3)

{
  readl_relaxed(*(long *)(param_1 + 0x140) +
                (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)param_3);
  return;
}



//------------------------------------------------------------
// nvidia_smmu_write_reg @ 0010d160 size=148
// signature: undefined nvidia_smmu_write_reg(void)
// callers: []
//------------------------------------------------------------

void nvidia_smmu_write_reg(long param_1,int param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x150) != 0) {
    writel_relaxed(param_4,*(long *)(param_1 + 0x140) +
                           (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
                           (long)param_3);
    if ((1 < *(uint *)(param_1 + 0x150)) &&
       (writel_relaxed(param_4,*(long *)(param_1 + 0x148) +
                               (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
                               (long)param_3), 2 < *(uint *)(param_1 + 0x150))) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10d1f4);
      (*pcVar1)();
    }
  }
  return;
}



//------------------------------------------------------------
// nvidia_smmu_read_reg64 @ 0010d1f8 size=48
// signature: undefined nvidia_smmu_read_reg64(void)
// callers: []
//------------------------------------------------------------

void nvidia_smmu_read_reg64(long param_1,int param_2,int param_3)

{
  readq_relaxed(*(long *)(param_1 + 0x140) +
                (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)param_3);
  return;
}



//------------------------------------------------------------
// nvidia_smmu_write_reg64 @ 0010d22c size=148
// signature: undefined nvidia_smmu_write_reg64(void)
// callers: []
//------------------------------------------------------------

void nvidia_smmu_write_reg64(long param_1,int param_2,int param_3,undefined8 param_4)

{
  code *pcVar1;
  
  if (*(int *)(param_1 + 0x150) != 0) {
    writeq_relaxed(param_4,*(long *)(param_1 + 0x140) +
                           (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
                           (long)param_3);
    if ((1 < *(uint *)(param_1 + 0x150)) &&
       (writeq_relaxed(param_4,*(long *)(param_1 + 0x148) +
                               (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) +
                               (long)param_3), 2 < *(uint *)(param_1 + 0x150))) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10d2c0);
      (*pcVar1)();
    }
  }
  return;
}



//------------------------------------------------------------
// nvidia_smmu_reset @ 0010d2c4 size=124
// signature: undefined nvidia_smmu_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 nvidia_smmu_reset(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if (*(int *)(param_1 + 0x150) != 0) {
    lVar1 = *(long *)(param_1 + 0x140) + 0x48;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3,lVar1);
    if (1 < *(uint *)(param_1 + 0x150)) {
      lVar1 = *(long *)(param_1 + 0x148) + 0x48;
      uVar3 = readl_relaxed(lVar1);
      writel_relaxed(uVar3,lVar1);
      if (2 < *(uint *)(param_1 + 0x150)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10d340);
        (*pcVar2)();
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// nvidia_smmu_tlb_sync @ 0010d344 size=348
// signature: undefined nvidia_smmu_tlb_sync(void)
// callers: []
//------------------------------------------------------------

void nvidia_smmu_tlb_sync(undefined8 *param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  
  if ((param_1[6] == 0) || (pcVar5 = *(code **)(param_1[6] + 8), pcVar5 == (code *)0x0)) {
    writel_relaxed(0,param_1[1] + (long)(param_2 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                     + (long)param_3);
  }
  else {
    if (*(int *)(pcVar5 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10d494);
      (*pcVar5)();
    }
    (*pcVar5)(param_1,param_2,param_3,0);
  }
  uVar6 = 1;
  do {
    iVar4 = -10;
    do {
      if (*(int *)(param_1 + 0x2a) == 0) {
        return;
      }
      uVar2 = readl_relaxed(param_1[0x28] + (long)param_4 +
                            (long)(param_2 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f)));
      if (1 < *(uint *)(param_1 + 0x2a)) {
        uVar3 = readl_relaxed(param_1[0x29] + (long)param_4 +
                              (long)(param_2 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f)));
        if (2 < *(uint *)(param_1 + 0x2a)) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10d4a0);
          (*pcVar5)();
        }
        uVar2 = uVar3 | uVar2;
      }
      if ((uVar2 & 1) == 0) {
        return;
      }
      Yield();
      bVar1 = iVar4 != -1;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    __udelay(uVar6);
    uVar6 = uVar6 << 1;
    if (499999 < uVar6) {
      iVar4 = ___ratelimit(&nvidia_smmu_tlb_sync__rs,"nvidia_smmu_tlb_sync");
      if (iVar4 != 0) {
        _dev_err(*param_1,"TLB sync timed out -- SMMU may be deadlocked\n");
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// nvidia_smmu_global_fault @ 0010d4a4 size=468
// signature: undefined nvidia_smmu_global_fault(void)
// callers: []
//------------------------------------------------------------

undefined8 nvidia_smmu_global_fault(undefined8 param_1,undefined8 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  
  if (*(int *)(param_2 + 0x2a) == 0) {
    uVar7 = 0;
  }
  else {
    lVar8 = param_2[0x28];
    iVar2 = readl_relaxed(lVar8 + 0x48);
    if (iVar2 == 0) {
      uVar7 = 0;
    }
    else {
      uVar3 = readl_relaxed(lVar8 + 0x50);
      uVar4 = readl_relaxed(lVar8 + 0x54);
      uVar5 = readl_relaxed(lVar8 + 0x58);
      iVar6 = ___ratelimit(nvidia_smmu_global_fault_inst__rs,"nvidia_smmu_global_fault_inst");
      if (iVar6 != 0) {
        _dev_err(*param_2,"Unexpected global fault, this could be serious\n");
      }
      iVar6 = ___ratelimit(nvidia_smmu_global_fault_inst__rs_5,"nvidia_smmu_global_fault_inst");
      if (iVar6 != 0) {
        _dev_err(*param_2,"\tGFSR 0x%08x, GFSYNR0 0x%08x, GFSYNR1 0x%08x, GFSYNR2 0x%08x\n",iVar2,
                 uVar3,uVar4,uVar5);
      }
      writel_relaxed(iVar2,lVar8 + 0x48);
      uVar7 = 1;
    }
    if (1 < *(uint *)(param_2 + 0x2a)) {
      lVar8 = param_2[0x29];
      iVar2 = readl_relaxed(lVar8 + 0x48);
      if (iVar2 != 0) {
        uVar3 = readl_relaxed(lVar8 + 0x50);
        uVar4 = readl_relaxed(lVar8 + 0x54);
        uVar5 = readl_relaxed(lVar8 + 0x58);
        iVar6 = ___ratelimit(nvidia_smmu_global_fault_inst__rs,"nvidia_smmu_global_fault_inst");
        if (iVar6 != 0) {
          _dev_err(*param_2,"Unexpected global fault, this could be serious\n");
        }
        iVar6 = ___ratelimit(nvidia_smmu_global_fault_inst__rs_5,"nvidia_smmu_global_fault_inst");
        if (iVar6 != 0) {
          _dev_err(*param_2,"\tGFSR 0x%08x, GFSYNR0 0x%08x, GFSYNR1 0x%08x, GFSYNR2 0x%08x\n",iVar2,
                   uVar3,uVar4,uVar5);
        }
        writel_relaxed(iVar2,lVar8 + 0x48);
        uVar7 = 1;
      }
      if (2 < *(uint *)(param_2 + 0x2a)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10d678);
        (*pcVar1)();
      }
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// nvidia_smmu_context_fault @ 0010d67c size=368
// signature: undefined nvidia_smmu_context_fault(void)
// callers: []
//------------------------------------------------------------

undefined8 nvidia_smmu_context_fault(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  undefined8 uVar11;
  uint uVar12;
  long lVar13;
  undefined8 *puVar14;
  
  puVar14 = *(undefined8 **)(param_2 + -0xc0);
  uVar8 = (ulong)*(uint *)(puVar14 + 0x2a);
  if (*(uint *)(puVar14 + 0x2a) == 0) {
    uVar11 = 0;
  }
  else {
    uVar9 = 0;
    uVar11 = 0;
    uVar7 = *(uint *)(puVar14 + 7);
    do {
      if (uVar7 != 0) {
        if (1 < uVar9) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10d7ec);
          (*pcVar2)();
        }
        uVar12 = 0;
        iVar10 = 0x400;
        do {
          uVar7 = *(uint *)((long)puVar14 + 0x1c);
          lVar13 = puVar14[uVar9 + 0x28];
          lVar1 = lVar13 + (int)(uVar12 + *(int *)(puVar14 + 3) << (ulong)(uVar7 & 0x1f));
          uVar3 = readl_relaxed(lVar1 + 0x58);
          if ((uVar3 & 0xc00001fe) != 0) {
            uVar4 = readl_relaxed(lVar1 + 0x68);
            uVar11 = readq_relaxed(lVar1 + 0x60);
            uVar5 = readl_relaxed(lVar13 + (1 << (ulong)(uVar7 & 0x1f)) + (long)iVar10);
            iVar6 = ___ratelimit(nvidia_smmu_context_fault_bank__rs,"nvidia_smmu_context_fault_bank"
                                );
            if (iVar6 != 0) {
              _dev_err(*puVar14,
                       "Unhandled context fault: fsr=0x%x, iova=0x%08lx, fsynr=0x%x, cbfrsynra=0x%x, cb=%d\n"
                       ,uVar3,uVar11,uVar4,uVar5,uVar12);
            }
            writel_relaxed(uVar3,lVar1 + 0x58);
            uVar11 = 1;
          }
          uVar7 = *(uint *)(puVar14 + 7);
          uVar12 = uVar12 + 1;
          iVar10 = iVar10 + 4;
        } while (uVar12 < uVar7);
        uVar8 = (ulong)*(uint *)(puVar14 + 0x2a);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < uVar8);
  }
  return uVar11;
}



//------------------------------------------------------------
// readl_relaxed @ 0010d7ec size=124
// signature: undefined readl_relaxed(void)
// callers: [nvidia_smmu_reset, nvidia_smmu_global_fault, nvidia_smmu_read_reg, nvidia_smmu_tlb_sync, nvidia_smmu_context_fault]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x10d834,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 0010d868 size=132
// signature: undefined writel_relaxed(void)
// callers: [nvidia_smmu_reset, nvidia_smmu_global_fault, nvidia_smmu_write_reg, nvidia_smmu_tlb_sync, nvidia_smmu_context_fault]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10d880,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10d8bc,uVar1);
  return;
}



//------------------------------------------------------------
// readq_relaxed @ 0010d8ec size=124
// signature: undefined readq_relaxed(void)
// callers: [nvidia_smmu_context_fault, nvidia_smmu_read_reg64]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x10d934,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writeq_relaxed @ 0010d968 size=124
// signature: undefined writeq_relaxed(void)
// callers: [nvidia_smmu_write_reg64]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x10d9b4,uVar1);
  return;
}



//------------------------------------------------------------
// arm_tbu_micro_idle_wake @ 0010d9f0 size=76
// signature: undefined arm_tbu_micro_idle_wake(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_tbu_micro_idle_wake(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*param_1 + 0x98);
  if (*(char *)(lVar3 + 0x58) == '\0') {
    uVar2 = 0;
  }
  else {
    iVar1 = 1 << (ulong)(*(uint *)(lVar3 + 0x38) >> 10 & 0x1f);
    uVar2 = __arm_tbu_micro_idle_cfg(*(undefined8 *)(lVar3 + 0x18),iVar1,iVar1);
  }
  return uVar2;
}



//------------------------------------------------------------
// __arm_tbu_micro_idle_cfg @ 0010da3c size=504
// signature: undefined __arm_tbu_micro_idle_cfg(void)
// callers: [arm_tbu_micro_idle_allow, arm_tbu_micro_idle_wake]
//------------------------------------------------------------

undefined8 __arm_tbu_micro_idle_cfg(undefined8 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  code *pcVar8;
  
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0x1c);
  if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
     (pcVar8 = *(code **)param_1[6], pcVar8 == (code *)0x0)) {
    uVar2 = readl_relaxed(param_1[1] + (long)(7 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                          + 0x5f8);
  }
  else {
    if (*(int *)(pcVar8 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10dbfc);
      (*pcVar8)();
    }
    uVar2 = (*pcVar8)(param_1,7,0x5f8);
  }
  uVar2 = uVar2 & (param_3 ^ 0xffffffff) | param_2;
  if ((param_1[6] == 0) || (pcVar8 = *(code **)(param_1[6] + 8), pcVar8 == (code *)0x0)) {
    writel_relaxed(uVar2,param_1[1] + (long)(7 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f)) +
                         0x5f8);
  }
  else {
    if (*(int *)(pcVar8 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10dc2c);
      (*pcVar8)();
    }
    (*pcVar8)(param_1,7,0x5f8,uVar2);
  }
  lVar7 = param_1[1] + (long)(7 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f)) + 0x5fc;
  lVar5 = ktime_get();
  uVar3 = readl(lVar7);
  uVar1 = uVar3 & param_3;
  if (uVar1 != param_2) {
    do {
      lVar6 = ktime_get();
      if (lVar5 + 200000 < lVar6) {
        uVar3 = readl(lVar7);
        uVar1 = uVar3 & param_3;
        break;
      }
      Yield();
      uVar3 = readl(lVar7);
      uVar1 = uVar3 & param_3;
    } while (uVar1 != param_2);
  }
  if (uVar1 == param_2) {
    __const_udelay(0x53e3);
    _raw_spin_unlock_irqrestore(param_1 + 0x1c,uVar4);
    return 0;
  }
  uVar4 = dev_driver_string(*param_1);
  lVar7 = ((long *)*param_1)[0xe];
  if (lVar7 == 0) {
    lVar7 = *(long *)*param_1;
  }
  __warn_printk("%s %s: Timed out configuring micro idle! %x instead of %x\n",uVar4,lVar7,uVar3,
                uVar2);
                    /* WARNING: Does not return */
  pcVar8 = (code *)SoftwareBreakpoint(0x800,0x10dba0);
  (*pcVar8)();
}



//------------------------------------------------------------
// arm_tbu_micro_idle_allow @ 0010dc38 size=68
// signature: undefined arm_tbu_micro_idle_allow(void)
// callers: []
//------------------------------------------------------------

void arm_tbu_micro_idle_allow(long *param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*param_1 + 0x98);
  if (*(char *)(lVar1 + 0x58) != '\0') {
    __arm_tbu_micro_idle_cfg
              (*(undefined8 *)(lVar1 + 0x18),0,1 << (ulong)(*(uint *)(lVar1 + 0x38) >> 10 & 0x1f));
  }
  return;
}



//------------------------------------------------------------
// qsmmuv500_tbu_probe @ 0010dc80 size=704
// signature: undefined qsmmuv500_tbu_probe(void)
// callers: []
//------------------------------------------------------------

void qsmmuv500_tbu_probe(long param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  uint *puVar9;
  char *pcVar10;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  lVar8 = param_1 + 0x10;
  local_38 = *(long *)(lVar4 + 0x638);
  local_3c = 0;
  lVar4 = devm_kmalloc(lVar8,0x58,0xdc0);
  if (lVar4 == 0) {
LAB_0010dec4:
    uVar5 = 0xfffffff4;
  }
  else {
    *(long *)(lVar4 + 0x10) = lVar8;
    uVar5 = arm_smmu_init_power_resources(lVar8);
    *(ulong *)(lVar4 + 0x30) = uVar5;
    if (0xfffffffffffff000 < uVar5) goto LAB_0010def0;
    iVar2 = of_device_is_compatible(*(undefined8 *)(param_1 + 0x2f8),"qcom,qtb500");
    if (iVar2 == 0) {
      uVar6 = devm_krealloc(lVar8,lVar4,0x60,0xcc0);
      if (uVar6 != 0) {
        *(undefined ***)(uVar6 + 0x28) = &arm_tbu_impl;
        lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,micro-idle",0);
        *(bool *)(uVar6 + 0x58) = lVar4 != 0;
        if (lVar4 != 0) {
          *(code **)(*(long *)(uVar6 + 0x30) + 0x68) = arm_tbu_micro_idle_wake;
          *(code **)(*(long *)(uVar6 + 0x30) + 0x70) = arm_tbu_micro_idle_allow;
        }
        goto joined_r0x0010de08;
      }
    }
    else {
      uVar6 = devm_krealloc(lVar8,lVar4,0x70,0xcc0);
      if (uVar6 != 0) {
        *(undefined ***)(uVar6 + 0x28) = &qtb500_impl;
        iVar2 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,num-qtb-ports",uVar6 + 0x5c,1,0);
        if (iVar2 < 0) {
          uVar6 = (ulong)iVar2;
        }
        else {
          lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,no-qtb-atos-halt",0);
          *(bool *)(uVar6 + 0x58) = lVar4 != 0;
          lVar4 = platform_get_resource_byname(param_1,0x200,"transactiontracker-base");
          if (lVar4 == 0) {
            *(undefined8 *)(uVar6 + 0x68) = 0;
            pcVar10 = "Unable to get the transactiontracker-base\n";
          }
          else {
            uVar5 = devm_ioremap_resource(lVar8,lVar4);
            *(ulong *)(uVar6 + 0x68) = uVar5;
            if (uVar5 < 0xfffffffffffff001) goto joined_r0x0010de08;
            pcVar10 = "devm_ioremap failure for transaction tracker\n";
          }
          _dev_info(lVar8,pcVar10);
        }
joined_r0x0010de08:
        if (0xfffffffffffff000 < uVar6) {
          uVar5 = uVar6 & 0xffffffff;
          goto LAB_0010def0;
        }
        *(ulong *)uVar6 = uVar6;
        *(ulong *)(uVar6 + 8) = uVar6;
        *(undefined4 *)(uVar6 + 0x44) = 0;
        plVar7 = (long *)platform_get_resource(param_1,0x200,0);
        if (plVar7 == (long *)0x0) {
          uVar5 = 0xffffffea;
          goto LAB_0010def0;
        }
        lVar8 = devm_ioremap(lVar8,*plVar7,(plVar7[1] - *plVar7) + 1);
        *(long *)(uVar6 + 0x20) = lVar8;
        if (lVar8 != 0) {
          puVar9 = (uint *)of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,stream-id-range",
                                           &local_3c);
          uVar5 = 0xffffffea;
          if ((puVar9 != (uint *)0x0) && (7 < local_3c)) {
            uVar1 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8;
            *(uint *)(uVar6 + 0x38) = uVar1 >> 0x10 | uVar1 << 0x10;
            uVar1 = (puVar9[1] & 0xff00ff00) >> 8 | (puVar9[1] & 0xff00ff) << 8;
            *(uint *)(uVar6 + 0x3c) = uVar1 >> 0x10 | uVar1 << 0x10;
            uVar3 = of_property_read_variable_u32_array
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,iova-width",uVar6 + 0x40,1,0);
            uVar1 = uVar3;
            if (-1 < (int)uVar3) {
              uVar1 = 0;
            }
            uVar5 = (ulong)uVar1;
            if (-1 < (int)uVar3) {
              uVar5 = 0;
              *(ulong *)(param_1 + 0xa8) = uVar6;
            }
          }
          goto LAB_0010def0;
        }
        goto LAB_0010dec4;
      }
    }
    uVar5 = 0xfffffff4;
  }
LAB_0010def0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qsmmuv500_create @ 0010df44 size=208
// signature: undefined qsmmuv500_create(void)
// callers: [qsmmuv500_impl_init]
//------------------------------------------------------------

long qsmmuv500_create(long *param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *param_1;
  lVar2 = devm_krealloc(lVar3,param_1,0x1a0,0xdc0);
  if (lVar2 == 0) {
    lVar2 = -0xc;
  }
  else {
    *(long *)(lVar2 + 0x140) = lVar2 + 0x140;
    *(long *)(lVar2 + 0x148) = lVar2 + 0x140;
    *(undefined4 *)(lVar2 + 400) = 0;
    *(undefined8 *)(lVar2 + 0x160) = 0xfffffffe0;
    *(long *)(lVar2 + 0x168) = lVar2 + 0x168;
    *(long *)(lVar2 + 0x170) = lVar2 + 0x168;
    *(code **)(lVar2 + 0x178) = qsmmuv500_log_outstanding_transactions;
    *(undefined8 *)(lVar2 + 0x30) = param_2;
    iVar1 = qsmmuv500_read_actlr_tbl();
    if ((iVar1 == 0) &&
       (iVar1 = of_platform_populate(*(undefined8 *)(lVar3 + 0x2e8),0,0,lVar3), iVar1 == 0)) {
      iVar1 = device_for_each_child(lVar3,lVar2,qsmmuv500_tbu_register);
      if (iVar1 != 0) {
        lVar2 = -0x205;
      }
    }
    else {
      lVar2 = (long)iVar1;
    }
  }
  return lVar2;
}



//------------------------------------------------------------
// qsmmuv500_log_outstanding_transactions @ 0010e018 size=368
// signature: undefined qsmmuv500_log_outstanding_transactions(void)
// callers: []
//------------------------------------------------------------

void qsmmuv500_log_outstanding_transactions(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  long *plVar4;
  
  puVar3 = (undefined8 *)(param_1 + -0x160);
  iVar2 = mutex_trylock(capture_reg_lock);
  if (iVar2 == 0) {
    iVar2 = ___ratelimit(qsmmuv500_log_outstanding_transactions__rs,
                         "qsmmuv500_log_outstanding_transactions");
    if (iVar2 != 0) {
      _dev_warn(*puVar3,"Tnx snapshot regs in use, not dumping OT tnxs.\n");
    }
  }
  else {
    iVar2 = arm_smmu_power_on(*(undefined8 *)(param_1 + -0x38));
    if (iVar2 == 0) {
      for (plVar4 = *(long **)(param_1 + -0x20); plVar4 != (long *)(param_1 + -0x20);
          plVar4 = (long *)*plVar4) {
        iVar2 = arm_smmu_power_on(plVar4[6]);
        if (iVar2 == 0) {
          if (*(int *)(*(code **)(plVar4[5] + 0x28) + -4) != 0x58f642d7) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10e108);
            (*pcVar1)();
          }
          (**(code **)(plVar4[5] + 0x28))(plVar4);
          arm_smmu_power_off(puVar3,plVar4[6]);
        }
        else {
          iVar2 = ___ratelimit(qsmmuv500_log_outstanding_transactions__rs_25,
                               "qsmmuv500_log_outstanding_transactions");
          if (iVar2 != 0) {
            _dev_err(plVar4[2],"%s: Failed to power on TBU.\n",
                     "qsmmuv500_log_outstanding_transactions");
          }
        }
      }
      arm_smmu_power_off(puVar3,*(undefined8 *)(param_1 + -0x38));
    }
    else {
      iVar2 = ___ratelimit(qsmmuv500_log_outstanding_transactions__rs_23,
                           "qsmmuv500_log_outstanding_transactions");
      if (iVar2 != 0) {
        _dev_err(*puVar3,"%s: Failed to power on SMMU.\n","qsmmuv500_log_outstanding_transactions");
      }
    }
    mutex_unlock(capture_reg_lock);
  }
  return;
}



//------------------------------------------------------------
// qsmmuv500_read_actlr_tbl @ 0010e188 size=232
// signature: undefined qsmmuv500_read_actlr_tbl(void)
// callers: [qsmmuv500_impl_init, qsmmuv500_create]
//------------------------------------------------------------

undefined8 qsmmuv500_read_actlr_tbl(long *param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  
  lVar8 = *param_1;
  puVar4 = (undefined4 *)of_get_property(*(undefined8 *)(lVar8 + 0x2e8),"qcom,actlr",0);
  if ((puVar4 == (undefined4 *)0x0) ||
     (uVar3 = of_property_count_elems_of_size(*(undefined8 *)(lVar8 + 0x2e8),"qcom,actlr",0xc),
     (int)uVar3 < 0)) {
    uVar7 = 0;
  }
  else {
    uVar9 = (ulong)uVar3;
    puVar5 = (ushort *)devm_kmalloc(lVar8,(uVar9 + (ulong)uVar3 * 2) * 4,0xdc0);
    if (puVar5 == (ushort *)0x0) {
      uVar7 = 0xfffffff4;
    }
    else {
      if (uVar3 != 0) {
        puVar6 = puVar5;
        do {
          uVar9 = uVar9 - 1;
          puVar6[1] = (ushort)(byte)((uint)*puVar4 >> 0x18) | (ushort)((uint)*puVar4 >> 8) & 0xff00;
          *puVar6 = (ushort)(byte)((uint)puVar4[1] >> 0x18) |
                    (ushort)((uint)puVar4[1] >> 8) & 0xff00;
          puVar1 = puVar4 + 2;
          puVar4 = puVar4 + 3;
          uVar2 = (*puVar1 & 0xff00ff00) >> 8 | (*puVar1 & 0xff00ff) << 8;
          *(uint *)(puVar6 + 4) = uVar2 >> 0x10 | uVar2 << 0x10;
          puVar6 = puVar6 + 6;
        } while (uVar9 != 0);
      }
      uVar7 = 0;
      param_1[0x2a] = (long)puVar5;
      *(uint *)(param_1 + 0x2b) = uVar3;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// qsmmuv500_tbu_register @ 0010e274 size=432
// signature: undefined qsmmuv500_tbu_register(void)
// callers: []
//------------------------------------------------------------

int qsmmuv500_tbu_register(long param_1,long param_2)

{
  uint uVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  ulong uVar7;
  
  if (*(long *)(param_1 + 0x88) == 0) {
    _dev_err(param_1,"TBU failed probe, QSMMUV500 cannot continue!\n");
    iVar3 = -0x16;
  }
  else {
    plVar5 = *(long **)(param_1 + 0x98);
    plVar2 = (long *)(param_2 + 0x140);
    *plVar5 = (long)plVar5;
    plVar5[1] = (long)plVar5;
    plVar5[3] = param_2;
    lVar6 = *(long *)(param_2 + 0x140);
    uVar4 = __list_add_valid(plVar5,plVar2,lVar6);
    if ((uVar4 & 1) != 0) {
      *(long **)(lVar6 + 8) = plVar5;
      *plVar5 = lVar6;
      plVar5[1] = (long)plVar2;
      *plVar2 = (long)plVar5;
    }
    uVar4 = 0xffffffff;
    do {
      uVar1 = (int)uVar4 + 1;
      uVar4 = (ulong)uVar1;
      lVar6 = platform_get_resource(param_1 + -0x10,0x400,uVar4);
    } while (lVar6 != 0);
    lVar6 = devm_kmalloc(param_1,-(ulong)(uVar1 >> 0x1f) & 0xfffffffc00000000 | uVar4 << 2,0xdc0);
    plVar5[10] = lVar6;
    if (lVar6 == 0) {
      iVar3 = -0xc;
    }
    else {
      if (0 < (int)uVar1) {
        uVar7 = 0;
        do {
          iVar3 = platform_get_irq(param_1 + -0x10,uVar7 & 0xffffffff);
          if (iVar3 < 0) {
            _dev_err(param_1,"failed to get irq index %d\n",uVar7 & 0xffffffff);
            return -0x13;
          }
          *(int *)(plVar5[10] + uVar7 * 4) = iVar3;
          iVar3 = devm_request_threaded_irq
                            (plVar5[2],*(undefined4 *)(plVar5[10] + uVar7 * 4),0,
                             arm_smmu_debug_capture_bus_match,0x2080,"capture bus",plVar5);
          if (iVar3 != 0) {
            _dev_err(param_1,"failed to request capture bus irq%d (%u)\n",uVar7 & 0xffffffff,
                     *(undefined4 *)(plVar5[10] + uVar7 * 4));
            return iVar3;
          }
          uVar7 = uVar7 + 1;
        } while (uVar4 != uVar7);
      }
      of_device_is_compatible(*(undefined8 *)(plVar5[2] + 0x2e8),"qcom,qtb500");
      of_device_is_compatible(*(undefined8 *)(plVar5[2] + 0x2e8),"qcom,qtb500");
      iVar3 = 0;
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// qsmmuv500_impl_init @ 0010e428 size=232
// signature: undefined qsmmuv500_impl_init(void)
// callers: [arm_smmu_impl_init]
//------------------------------------------------------------

long qsmmuv500_impl_init(long *param_1)

{
  int iVar1;
  long lVar2;
  undefined1 *puVar3;
  
  iVar1 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,adreno-smmu");
  if (iVar1 == 0) {
    iVar1 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,virt-smmu");
    if (iVar1 != 0) {
      lVar2 = devm_krealloc(*param_1,param_1,0x1a0,0xdc0);
      if (lVar2 == 0) {
        return -0xc;
      }
      *(long *)(lVar2 + 0x140) = lVar2 + 0x140;
      *(long *)(lVar2 + 0x148) = lVar2 + 0x140;
      *(undefined4 *)(lVar2 + 400) = 0;
      *(undefined8 *)(lVar2 + 0x160) = 0xfffffffe0;
      *(long *)(lVar2 + 0x168) = lVar2 + 0x168;
      *(long *)(lVar2 + 0x170) = lVar2 + 0x168;
      *(code **)(lVar2 + 0x178) = qsmmuv500_log_outstanding_transactions;
      *(undefined1 **)(lVar2 + 0x30) = qsmmuv500_virt_impl;
      iVar1 = qsmmuv500_read_actlr_tbl();
      if (iVar1 == 0) {
        return lVar2;
      }
      return (long)iVar1;
    }
    puVar3 = qsmmuv500_impl;
  }
  else {
    puVar3 = qsmmuv500_adreno_impl;
  }
  lVar2 = qsmmuv500_create(param_1,puVar3);
  return lVar2;
}



//------------------------------------------------------------
// qcom_smmu_impl_init @ 0010e514 size=204
// signature: undefined qcom_smmu_impl_init(void)
// callers: [arm_smmu_impl_init]
//------------------------------------------------------------

long * qcom_smmu_impl_init(long *param_1)

{
  int iVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
  
  uVar6 = *(undefined8 *)(*param_1 + 0x2e8);
  iVar1 = of_device_is_compatible(uVar6,"qcom,adreno-smmu");
  if (iVar1 == 0) {
    lVar4 = of_match_node(qcom_smmu_impl_of_match,uVar6);
    if (lVar4 == 0) {
      return param_1;
    }
    uVar2 = qcom_scm_is_available();
    if ((uVar2 & 1) == 0) {
      return (long *)0xfffffffffffffdfb;
    }
    plVar3 = (long *)devm_krealloc(*param_1,param_1,0x150,0xcc0);
    if (plVar3 == (long *)0x0) {
      return (long *)0xfffffffffffffff4;
    }
    puVar5 = qcom_smmu_impl;
  }
  else {
    uVar2 = qcom_scm_is_available();
    if ((uVar2 & 1) == 0) {
      return (long *)0xfffffffffffffdfb;
    }
    plVar3 = (long *)devm_krealloc(*param_1,param_1,0x150,0xcc0);
    if (plVar3 == (long *)0x0) {
      return (long *)0xfffffffffffffff4;
    }
    puVar5 = qcom_adreno_smmu_impl;
  }
  plVar3[6] = (long)puVar5;
  plVar3[0x28] = 0;
  return plVar3;
}



//------------------------------------------------------------
// qsmmuv2_impl_init @ 0010e5e4 size=456
// signature: undefined qsmmuv2_impl_init(void)
// callers: [arm_smmu_impl_init]
//------------------------------------------------------------

undefined4 * qsmmuv2_impl_init(long *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  undefined4 *__dest;
  long lVar12;
  uint local_4c;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  puVar7 = (undefined4 *)devm_kmalloc(*param_1,0x158,0xdc0);
  if (puVar7 != (undefined4 *)0x0) {
    __dest = puVar7 + 6;
    *puVar7 = 0;
    memcpy(__dest,param_1,0x140);
    iVar6 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,adreno-smmu");
    lVar12 = *(long *)(puVar7 + 6);
    puVar4 = qsmmuv2_impl;
    if (iVar6 != 0) {
      puVar4 = qsmmuv2_adreno_impl;
    }
    uVar8 = *(undefined8 *)(lVar12 + 0x2e8);
    local_4c = 0;
    *(undefined1 **)(puVar7 + 0x12) = puVar4;
    lVar9 = of_find_property(uVar8,"attach-impl-defs",&local_4c);
    if (lVar9 == 0) goto LAB_0010e748;
    uVar3 = (int)local_4c >> 2;
    if ((local_4c >> 2 & 1) != 0) {
      local_4c = uVar3;
      _dev_err(lVar12,"Invalid number of attach-impl-defs registers: %d\n");
      __dest = (undefined4 *)0xffffffffffffffea;
      goto LAB_0010e748;
    }
    local_4c = uVar3;
    lVar9 = devm_kmalloc(lVar12,-(ulong)(uVar3 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar3 << 3,
                         0xdc0);
    if ((lVar9 != 0) && (lVar10 = __kmalloc((long)(int)local_4c << 3,0xdc0), lVar10 != 0)) {
      iVar6 = of_property_read_variable_u32_array
                        (*(undefined8 *)(lVar12 + 0x2e8),"attach-impl-defs",lVar10,
                         (long)(int)local_4c,0);
      if (iVar6 < 0) {
        kfree(lVar10);
        __dest = (undefined4 *)(long)iVar6;
      }
      else {
        if (0 < (int)local_4c) {
          uVar11 = 0;
          do {
            lVar12 = uVar11 * 4;
            uVar11 = uVar11 + 2;
            puVar1 = (undefined4 *)(lVar10 + lVar12);
            puVar2 = (undefined4 *)(lVar9 + lVar12);
            uVar5 = puVar1[1];
            *puVar2 = *puVar1;
            puVar2[1] = uVar5;
          } while (uVar11 < local_4c);
        }
        kfree(lVar10);
        *(long *)(puVar7 + 2) = lVar9;
        uVar3 = local_4c;
        if ((int)local_4c < 0) {
          uVar3 = local_4c + 1;
        }
        puVar7[4] = (int)uVar3 >> 1;
      }
      goto LAB_0010e748;
    }
  }
  __dest = (undefined4 *)0xfffffffffffffff4;
LAB_0010e748:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __dest;
}



//------------------------------------------------------------
// readl @ 0010e7ac size=140
// signature: undefined readl(void)
// callers: [__arm_tbu_micro_idle_cfg, qsmmuv2_iova_to_phys_hard, qsmmuv2_wait_for_halt, arm_tbu_halt_poll]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x10e804,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readl_relaxed @ 0010e838 size=124
// signature: undefined readl_relaxed(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_tbu_halt_req, qsmmuv500_cfg_probe, qsmmuv2_iova_to_phys_hard, qsmmuv500_tlb_sync_timeout, qsmmuv2_tlb_sync_timeout, arm_tbu_write_sync, qsmmuv2_device_reset, qcom_smmu_tlb_sync, arm_tbu_resume, qcom_adreno_smmu_get_fault_info, arm_tbu_trigger_atos, __arm_tbu_micro_idle_cfg, qcom_smmu_cfg_probe, qtb500_tbu_write_sync, arm_tbu_halt_poll]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x10e880,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 0010e8b4 size=132
// signature: undefined writel_relaxed(void)
// callers: [qsmmuv500_iova_to_phys_hard, qcom_adreno_smmu_resume_translation, arm_tbu_halt_req, qsmmuv500_cfg_probe, qsmmuv2_init_cb, qsmmuv2_iova_to_phys_hard, qsmmuv500_init_cb, qsmmuv2_device_reset, qcom_smmu_write_s2cr, qcom_smmu_tlb_sync, arm_tbu_resume, arm_tbu_trigger_atos, __arm_tbu_micro_idle_cfg, qcom_smmu_cfg_probe, qcom_adreno_smmu_write_sctlr, arm_tbu_halt_poll]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10e8cc,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10e908,uVar1);
  return;
}



//------------------------------------------------------------
// qtb500_tbu_halt_req @ 0010e93c size=72
// signature: undefined qtb500_tbu_halt_req(void)
// callers: []
//------------------------------------------------------------

undefined8 qtb500_tbu_halt_req(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  if (*(char *)(param_1 + 0x58) == '\0') {
    lVar1 = *(long *)(param_1 + 0x20) + 0x410;
    uVar2 = readq_relaxed(lVar1);
    writeq_relaxed(uVar2 | 1,lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// qtb500_tbu_halt_poll @ 0010e988 size=184
// signature: undefined qtb500_tbu_halt_poll(void)
// callers: []
//------------------------------------------------------------

undefined8 qtb500_tbu_halt_poll(long param_1)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  if (*(char *)(param_1 + 0x58) == '\0') {
    lVar5 = *(long *)(param_1 + 0x20);
    lVar2 = ktime_get();
    lVar1 = lVar5 + 0x418;
    uVar3 = readq(lVar1);
    if ((uVar3 & 1) == 0) {
      do {
        lVar4 = ktime_get();
        if (lVar2 + 100000 < lVar4) {
          uVar3 = readq(lVar1);
          break;
        }
        Yield();
        uVar3 = readq(lVar1);
      } while ((uVar3 & 1) == 0);
    }
    if ((uVar3 & 1) == 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x10),"Couldn\'t halt QTB\n");
      lVar5 = lVar5 + 0x410;
      uVar3 = readq_relaxed(lVar5);
      writeq_relaxed(uVar3 & 0xfffffffffffffffe,lVar5);
      return 0xffffff92;
    }
  }
  return 0;
}



//------------------------------------------------------------
// qtb500_tbu_resume @ 0010ea44 size=68
// signature: undefined qtb500_tbu_resume(void)
// callers: []
//------------------------------------------------------------

void qtb500_tbu_resume(long param_1)

{
  long lVar1;
  ulong uVar2;
  
  if (*(char *)(param_1 + 0x58) == '\0') {
    lVar1 = *(long *)(param_1 + 0x20) + 0x410;
    uVar2 = readq_relaxed(lVar1);
    writeq_relaxed(uVar2 & 0xfffffffffffffffe,lVar1);
  }
  return;
}



//------------------------------------------------------------
// qtb500_trigger_atos @ 0010ea8c size=352
// signature: undefined qtb500_trigger_atos(void)
// callers: []
//------------------------------------------------------------

ulong qtb500_trigger_atos(long param_1,undefined8 param_2,uint param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  uVar5 = param_4 & 0xffffffff;
  lVar6 = *(long *)(param_1 + 0x20);
  writeq_relaxed((ulong)(param_3 & 0x3ff) | (uVar5 >> 3 & 1) << 0x14,lVar6 + 0x430);
  writeq_relaxed(((uVar5 >> 1 & 1) << 0xd | param_4 & 9 | (uVar5 >> 2 & 1) << 0xc) ^ 0x408,
                 lVar6 + 0x438);
  writeq_relaxed(param_2,lVar6 + 0x440);
  writeq_relaxed(1,lVar6 + 0x448);
  lVar3 = ktime_get();
  lVar1 = lVar6 + 0x458;
  while ((uVar5 = readq_relaxed(lVar6 + 0x450), (uVar5 & 1) == 0 &&
         (uVar5 = readq_relaxed(lVar1), (uVar5 & 1) == 0))) {
    lVar4 = ktime_get();
    if (lVar3 + 100000 < lVar4) {
      uVar5 = readq_relaxed(lVar1);
      if ((uVar5 & 1) == 0) {
        iVar2 = ___ratelimit(qtb500_trigger_atos__rs,"qtb500_trigger_atos");
        if (iVar2 == 0) {
          uVar5 = 0;
        }
        else {
          _dev_err(*(undefined8 *)(param_1 + 0x10),"ECATS translation timed out!\n");
          uVar5 = 0;
        }
      }
      else {
LAB_0010ebb8:
        _dev_err(*(undefined8 *)(param_1 + 0x10),
                 "ECATS generated a fault interrupt! OUTFLD0 = 0x%llx SID = 0x%x\n",uVar5,param_3);
        uVar5 = 0;
      }
LAB_0010eb90:
      writeq_relaxed(0,lVar6 + 0x448);
      return uVar5;
    }
  }
  uVar5 = readq_relaxed(lVar1);
  if ((uVar5 & 1) != 0) goto LAB_0010ebb8;
  uVar5 = uVar5 >> 0xc;
  goto LAB_0010eb90;
}



//------------------------------------------------------------
// qtb500_tbu_write_sync @ 0010ebf0 size=32
// signature: undefined qtb500_tbu_write_sync(void)
// callers: []
//------------------------------------------------------------

void qtb500_tbu_write_sync(long param_1)

{
  readl_relaxed(*(undefined8 *)(param_1 + 0x20));
  return;
}



//------------------------------------------------------------
// qtb500_log_outstanding_transactions @ 0010ec14 size=128
// signature: undefined qtb500_log_outstanding_transactions(void)
// callers: []
//------------------------------------------------------------

void qtb500_log_outstanding_transactions(long param_1)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x5c) != 0) {
    uVar2 = 0;
    lVar3 = *(long *)(param_1 + 0x20);
    iVar4 = 0xc10;
    do {
      uVar1 = readq_relaxed(lVar3 + iVar4);
      _dev_err(*(undefined8 *)(param_1 + 0x10),"port %d outstanding transactions bitmap: 0x%llx\n",
               uVar2,uVar1);
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x10;
    } while (uVar2 < *(uint *)(param_1 + 0x5c));
  }
  return;
}



//------------------------------------------------------------
// readq_relaxed @ 0010ec94 size=124
// signature: undefined readq_relaxed(void)
// callers: [qtb500_tbu_resume, qcom_adreno_smmu_get_fault_info, qtb500_log_outstanding_transactions, arm_tbu_trigger_atos, qsmmuv2_iova_to_phys_hard, qtb500_tbu_halt_poll, qtb500_trigger_atos, arm_tbu_log_outstanding_transactions, qtb500_tbu_halt_req]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x10ecdc,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writeq_relaxed @ 0010ed10 size=124
// signature: undefined writeq_relaxed(void)
// callers: [qtb500_tbu_resume, arm_tbu_trigger_atos, qsmmuv2_iova_to_phys_hard, qtb500_tbu_halt_poll, qtb500_trigger_atos, arm_tbu_log_outstanding_transactions, qtb500_tbu_halt_req]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x10ed5c,uVar1);
  return;
}



//------------------------------------------------------------
// readq @ 0010ed8c size=136
// signature: undefined readq(void)
// callers: [qtb500_tbu_halt_poll, arm_tbu_log_outstanding_transactions]
//------------------------------------------------------------

undefined8 readq(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x40,param_1,0x10ede0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// arm_tbu_halt_req @ 0010ee18 size=60
// signature: undefined arm_tbu_halt_req(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_tbu_halt_req(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  uVar1 = readl_relaxed(uVar2);
  writel_relaxed(uVar1 | 0x10000,uVar2);
  return 0;
}



//------------------------------------------------------------
// arm_tbu_halt_poll @ 0010ee58 size=172
// signature: undefined arm_tbu_halt_poll(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_tbu_halt_poll(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x20);
  lVar3 = ktime_get();
  lVar1 = lVar6 + 0x20;
  uVar2 = readl(lVar1);
  if ((uVar2 >> 1 & 1) == 0) {
    do {
      lVar4 = ktime_get();
      if (lVar3 + 100000 < lVar4) {
        uVar2 = readl(lVar1);
        break;
      }
      Yield();
      uVar2 = readl(lVar1);
    } while ((uVar2 >> 1 & 1) == 0);
  }
  if ((uVar2 >> 1 & 1) == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x10),"Couldn\'t halt TBU!\n");
    uVar2 = readl_relaxed(lVar6);
    writel_relaxed(uVar2 & 0xfffeffff,lVar6);
    uVar5 = 0xffffff92;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// arm_tbu_resume @ 0010ef08 size=56
// signature: undefined arm_tbu_resume(void)
// callers: []
//------------------------------------------------------------

void arm_tbu_resume(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x20);
  uVar1 = readl_relaxed(uVar2);
  writel_relaxed(uVar1 & 0xfffeffff,uVar2);
  return;
}



//------------------------------------------------------------
// arm_tbu_trigger_atos @ 0010ef44 size=412
// signature: undefined arm_tbu_trigger_atos(void)
// callers: []
//------------------------------------------------------------

ulong arm_tbu_trigger_atos(long param_1,undefined8 param_2,uint param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = *(long *)(param_1 + 0x20);
  uVar4 = readq_relaxed(lVar7);
  writeq_relaxed(uVar4 & 0xfffffffffffffc00 | (ulong)(param_3 & 0x3ff),lVar7);
  writeq_relaxed(param_2,lVar7 + 8);
  writeq_relaxed(0xff000000000,lVar7 + 0x30);
  uVar4 = 0xbc;
  if ((param_4 & 1) != 0) {
    uVar4 = 0xbe;
  }
  writeq_relaxed((ulong)(uint)((int)param_4 << 6) & 0x100 | ((param_4 & 0xffffffff) >> 1 & 1) << 6 |
                 uVar4 | 1,lVar7 + 0x18);
  lVar5 = ktime_get();
  lVar1 = lVar7 + 0x28;
  while ((uVar4 = readl_relaxed(lVar7 + 0x20), (uVar4 & 1) != 0 &&
         (uVar4 = readl_relaxed(lVar1), (uVar4 & 1) == 0))) {
    lVar6 = ktime_get();
    if (lVar5 + 100000 < lVar6) {
      uVar4 = readq_relaxed(lVar1);
      if ((uVar4 & 1) == 0) {
        iVar2 = ___ratelimit(arm_tbu_trigger_atos__rs,"arm_tbu_trigger_atos");
        if (iVar2 == 0) {
          uVar4 = 0;
        }
        else {
          _dev_err(*(undefined8 *)(param_1 + 0x10),"ECATS translation timed out!\n");
          uVar4 = 0;
        }
      }
      else {
LAB_0010f0ac:
        _dev_err(*(undefined8 *)(param_1 + 0x10),
                 "ECATS generated a fault interrupt! PAR = %llx, SID=0x%x\n",uVar4,param_3);
        uVar4 = 0;
      }
LAB_0010f060:
      writeq_relaxed(0,lVar7 + 0x18);
      writeq_relaxed(0,lVar7 + 8);
      uVar3 = readl_relaxed(lVar7);
      writel_relaxed(uVar3 & 0xfffffc00,lVar7);
      return uVar4;
    }
  }
  uVar4 = readq_relaxed(lVar1);
  if ((uVar4 & 1) != 0) goto LAB_0010f0ac;
  uVar4 = uVar4 >> 0xc & 0xfffffffff;
  goto LAB_0010f060;
}



//------------------------------------------------------------
// arm_tbu_write_sync @ 0010f0e4 size=36
// signature: undefined arm_tbu_write_sync(void)
// callers: []
//------------------------------------------------------------

void arm_tbu_write_sync(long param_1)

{
  readl_relaxed(*(long *)(param_1 + 0x20) + 0x20);
  return;
}



//------------------------------------------------------------
// arm_tbu_log_outstanding_transactions @ 0010f10c size=304
// signature: undefined arm_tbu_log_outstanding_transactions(void)
// callers: []
//------------------------------------------------------------

void arm_tbu_log_outstanding_transactions(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x20);
  lVar1 = lVar8 + 0x130;
  uVar3 = readq_relaxed(lVar1);
  writeq_relaxed(uVar3 | 0x80,lVar1);
  writeq_relaxed(uVar3 & 0xfffffffffffb7f3f | 0x40000,lVar1);
  lVar4 = ktime_get();
  lVar1 = lVar8 + 0x178;
  uVar5 = readq(lVar1);
  if ((uVar5 & 1) == 0) {
    do {
      lVar6 = ktime_get();
      if (lVar4 + 100000 < lVar6) {
        uVar5 = readq(lVar1);
        break;
      }
      Yield();
      uVar5 = readq(lVar1);
    } while ((uVar5 & 1) == 0);
  }
  if ((uVar5 & 1) == 0) {
    iVar2 = ___ratelimit(arm_tbu_log_outstanding_transactions__rs,
                         "arm_tbu_log_outstanding_transactions");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x10),"Timeout on TNX snapshot poll\n");
    }
  }
  else {
    uVar7 = readq_relaxed(lVar8 + 0x138);
    iVar2 = ___ratelimit(arm_tbu_log_outstanding_transactions__rs_20,
                         "arm_tbu_log_outstanding_transactions");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x10),"Outstanding Transaction Bitmap: 0x%llx\n",uVar7);
    }
  }
  writeq_relaxed(uVar3 & 0xfffffffffffb7f3f,*(long *)(param_1 + 0x20) + 0x130);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_capture_bus_match @ 0010f240 size=676
// signature: undefined arm_smmu_debug_capture_bus_match(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_debug_capture_bus_match(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar1 = *(undefined8 **)(param_2 + 0x18);
  uVar5 = *(undefined8 *)(param_2 + 0x20);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  iVar3 = arm_smmu_power_on(puVar1[0x25]);
  if (iVar3 == 0) {
    iVar3 = arm_smmu_power_on(*(undefined8 *)(param_2 + 0x30));
    if (iVar3 == 0) {
      iVar3 = mutex_trylock(capture_reg_lock);
      if (iVar3 != 0) {
        uVar4 = arm_smmu_debug_get_tnx_tcr_cntl(uVar5);
        arm_smmu_debug_get_mask_and_match(uVar5,&local_50,&local_68);
        arm_smmu_debug_get_capture_snapshot(uVar5,&local_a8);
        arm_smmu_debug_clear_intr_and_validbits(uVar5);
        mutex_unlock(capture_reg_lock);
        arm_smmu_power_off(*(undefined8 *)(param_2 + 0x18),*(undefined8 *)(param_2 + 0x30));
        arm_smmu_power_off(puVar1,puVar1[0x25]);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"TNX_TCR_CNTL : 0x%0llx\n",uVar4);
        uVar5 = 1;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Mask_%d : 0x%0llx\n",1,local_50);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Match_%d : 0x%0llx\n",1,local_68);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Mask_%d : 0x%0llx\n",2,local_48);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Match_%d : 0x%0llx\n",2,local_60);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Mask_%d : 0x%0llx\n",3,local_40);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Match_%d : 0x%0llx\n",3,local_58);
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",1,1,local_a8)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",1,2,local_a0)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",2,1,local_98)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",2,2,local_90)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",3,1,local_88)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",3,2,local_80)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",4,1,local_78)
        ;
        _dev_info(*(undefined8 *)(param_2 + 0x10),"Capture_%d_Snapshot_%d : 0x%0llx\n",4,2,local_70)
        ;
        goto LAB_0010f2dc;
      }
      iVar3 = ___ratelimit(arm_smmu_debug_capture_bus_match__rs,"arm_smmu_debug_capture_bus_match");
      if (iVar3 != 0) {
        _dev_warn(*puVar1,"capture bus regs in use, not dumping it.\n");
      }
    }
    else {
      arm_smmu_power_off(puVar1,puVar1[0x25]);
    }
  }
  uVar5 = 0;
LAB_0010f2dc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// qsmmuv500_cfg_probe @ 0010f4e8 size=280
// signature: undefined qsmmuv500_cfg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 qsmmuv500_cfg_probe(long param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  
  if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
     (pcVar2 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar2 == (code *)0x0)) {
    uVar1 = readl_relaxed(*(long *)(param_1 + 8) + 0x10);
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10f594);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,0,0x10);
  }
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
    writel_relaxed(uVar1 & 0xfbffffff,*(long *)(param_1 + 8) + 0x10);
    puVar3 = *(undefined8 **)(param_1 + 0x30);
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10f5c0);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,0,0x10);
    puVar3 = *(undefined8 **)(param_1 + 0x30);
  }
  if ((puVar3 == (undefined8 *)0x0) || (pcVar2 = (code *)*puVar3, pcVar2 == (code *)0x0)) {
    uVar1 = readl_relaxed(*(long *)(param_1 + 8) + 0x10);
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10f5f4);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,0,0x10);
  }
  if ((uVar1 >> 0x1a & 1) != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10f600);
    (*pcVar2)();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_adreno_smmu_init_context @ 0010f608 size=348
// signature: undefined qcom_adreno_smmu_init_context(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_adreno_smmu_init_context(undefined8 *param_1,ulong *param_2,long param_3)

{
  ulong uVar1;
  ulong uVar2;
  ulong uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  uint uVar8;
  undefined8 uVar9;
  long *plVar10;
  
  uVar9 = *(undefined8 *)(*(long *)*param_1 + 0x2e8);
  *(undefined1 *)((long)param_1 + 0x44) = 1;
  lVar7 = 0;
  if (*(long *)(param_3 + 0x338) != 0) {
    lVar7 = *(long *)(*(long *)(param_3 + 0x338) + 0x40);
  }
  uVar4 = *(uint *)(lVar7 + 0x14);
  if (uVar4 != 0) {
    if ((*(ushort *)(lVar7 + 0x18) & 0xfffe) != 0) {
      uVar5 = 1;
      do {
        uVar8 = uVar5;
        if (uVar4 == uVar8) break;
        uVar5 = uVar8 + 1;
      } while ((*(uint *)(lVar7 + (long)(int)uVar8 * 4 + 0x18) & 0xfffe) != 0);
      if (uVar4 <= uVar8) {
        return 0;
      }
    }
    iVar6 = of_device_is_compatible
                      (*(undefined8 *)(*(long *)*param_1 + 0x2e8),"qcom,msm8996-smmu-v2");
    if (((iVar6 == 0) && (*(int *)(param_1 + 9) == 0)) && (*(int *)(param_1 + 8) == 1)) {
      *param_2 = *param_2 | 0x20;
    }
    plVar10 = *(long **)(param_3 + 0x98);
    *plVar10 = (long)param_1;
    plVar10[1] = (long)qcom_adreno_smmu_get_ttbr1_cfg;
    plVar10[2] = (long)qcom_adreno_smmu_set_ttbr0_cfg;
    plVar10[3] = (long)qcom_adreno_smmu_get_fault_info;
    uVar2 = param_2[3];
    uVar1 = *param_2;
    uVar3 = param_2[1];
    plVar10[8] = param_2[2];
    plVar10[9] = uVar2;
    plVar10[6] = uVar1;
    plVar10[7] = uVar3;
    uVar2 = param_2[7];
    uVar1 = param_2[4];
    uVar3 = param_2[5];
    plVar10[0xc] = param_2[6];
    plVar10[0xd] = uVar2;
    plVar10[10] = uVar1;
    plVar10[0xb] = uVar3;
    uVar2 = param_2[0xb];
    uVar1 = param_2[8];
    uVar3 = param_2[9];
    plVar10[0x10] = param_2[10];
    plVar10[0x11] = uVar2;
    plVar10[0xe] = uVar1;
    plVar10[0xf] = uVar3;
    uVar2 = param_2[0xf];
    uVar1 = param_2[0xc];
    uVar3 = param_2[0xd];
    plVar10[0x14] = param_2[0xe];
    plVar10[0x15] = uVar2;
    plVar10[0x12] = uVar1;
    plVar10[0x13] = uVar3;
    lVar7 = of_match_node(qcom_smmu_impl_of_match,uVar9);
    if (lVar7 != 0) {
      plVar10[4] = (long)qcom_adreno_smmu_set_stall;
      plVar10[5] = (long)qcom_adreno_smmu_resume_translation;
    }
  }
  return 0;
}



//------------------------------------------------------------
// qsmmuv500_init_cb @ 0010f768 size=200
// signature: undefined qsmmuv500_init_cb(void)
// callers: []
//------------------------------------------------------------

void qsmmuv500_init_cb(long *param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *param_1;
  pcVar2 = (char *)iommu_group_get_iommudata(*(undefined8 *)(param_2 + 0x330));
  if (*pcVar2 != '\0') {
    iVar1 = *(int *)(lVar4 + 0x18) + (uint)*(byte *)(param_1 + 6);
    if ((*(long *)(lVar4 + 0x30) == 0) ||
       (pcVar3 = *(code **)(*(long *)(lVar4 + 0x30) + 8), pcVar3 == (code *)0x0)) {
      writel_relaxed(*(undefined4 *)(pcVar2 + 4),
                     *(long *)(lVar4 + 8) + (long)(iVar1 << (ulong)(*(uint *)(lVar4 + 0x1c) & 0x1f))
                     + 4);
    }
    else {
      if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10f828);
        (*pcVar3)();
      }
      (*pcVar3)(lVar4,iVar1,4);
    }
    pcVar3 = *(code **)(param_1[0x19] + 0x38);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != -0x856fbb8) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10f7f4);
        (*pcVar3)();
      }
      (*pcVar3)(param_1 + 0x18);
    }
  }
  return;
}



//------------------------------------------------------------
// qsmmuv500_iova_to_phys_hard @ 0010f834 size=2272
// signature: undefined qsmmuv500_iova_to_phys_hard(void)
// callers: []
//------------------------------------------------------------

long qsmmuv500_iova_to_phys_hard(long *param_1,ulong *param_2)

{
  long lVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  ulong uVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined8 uVar12;
  code *pcVar13;
  long *plVar14;
  long lVar15;
  ulong uVar16;
  long lVar17;
  long lVar18;
  uint uVar19;
  ulong local_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  uVar16 = *param_2;
  lVar15 = *param_1;
  uVar5 = param_2[1];
  uVar2 = *(uint *)((long)param_2 + 0xc);
  bVar3 = *(byte *)(param_1 + 6);
  plVar14 = *(long **)(lVar15 + 0x140);
  do {
    local_70 = uVar16;
    if (plVar14 == (long *)(lVar15 + 0x140)) {
LAB_0010f8ec:
      lVar17 = 0;
LAB_0010f8f0:
      lVar15 = sp_el0;
      if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return lVar17;
    }
    if ((*(uint *)(plVar14 + 7) <= uVar2) &&
       (uVar2 < *(int *)((long)plVar14 + 0x3c) + *(uint *)(plVar14 + 7))) {
      if ((plVar14 != (long *)0x0) && (iVar7 = arm_smmu_power_on(plVar14[6]), iVar7 == 0)) {
        if (uVar16 >> ((ulong)*(uint *)(plVar14 + 8) & 0x3f) == 0) {
          lVar18 = *param_1;
          bVar4 = *(byte *)(param_1 + 6);
          lVar17 = of_find_property(*(undefined8 *)(plVar14[2] + 0x2e8),"qcom,opt-out-tbu-halting",0
                                   );
          if (lVar17 == 0) {
            lVar1 = (long)plVar14 + 0x44;
            uVar12 = _raw_spin_lock_irqsave(lVar1);
            if (*(int *)(plVar14 + 9) == 0) {
              if (*(int *)(*(code **)plVar14[5] + -4) != 0x21f83a90) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fcb8);
                (*pcVar13)();
              }
              iVar7 = (**(code **)plVar14[5])(plVar14);
              if (iVar7 == 0) {
                iVar7 = *(int *)(lVar18 + 0x18) + (uint)bVar4;
                if ((*(undefined8 **)(lVar18 + 0x30) == (undefined8 *)0x0) ||
                   (pcVar13 = (code *)**(undefined8 **)(lVar18 + 0x30), pcVar13 == (code *)0x0)) {
                  uVar8 = readl_relaxed(*(long *)(lVar18 + 8) +
                                        (long)(iVar7 << (ulong)(*(uint *)(lVar18 + 0x1c) & 0x1f)) +
                                        0x58);
                }
                else {
                  if (*(int *)(pcVar13 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x110034);
                    (*pcVar13)();
                  }
                  uVar8 = (*pcVar13)(lVar18,iVar7,0x58);
                }
                if ((uVar8 >> 0x1e & 1) != 0) {
                  iVar7 = *(int *)(lVar18 + 0x18) + (uint)bVar4;
                  if ((*(undefined8 **)(lVar18 + 0x30) == (undefined8 *)0x0) ||
                     (pcVar13 = (code *)**(undefined8 **)(lVar18 + 0x30), pcVar13 == (code *)0x0)) {
                    uVar11 = readl_relaxed(*(long *)(lVar18 + 8) +
                                           (long)(iVar7 << (ulong)(*(uint *)(lVar18 + 0x1c) & 0x1f))
                                          );
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x110064);
                      (*pcVar13)();
                    }
                    uVar11 = (*pcVar13)(lVar18,iVar7,0);
                  }
                  uVar9 = (uint)bVar4;
                  iVar7 = *(int *)(lVar18 + 0x18) + uVar9;
                  if ((*(long *)(lVar18 + 0x30) == 0) ||
                     (pcVar13 = *(code **)(*(long *)(lVar18 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                    writel_relaxed(uVar11 & 0xffffff3f,
                                   *(long *)(lVar18 + 8) +
                                   (long)(iVar7 << (ulong)(*(uint *)(lVar18 + 0x1c) & 0x1f)));
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x11008c);
                      (*pcVar13)();
                    }
                    (*pcVar13)(lVar18,iVar7,0);
                  }
                  iVar7 = *(int *)(lVar18 + 0x18) + uVar9;
                  if ((*(long *)(lVar18 + 0x30) == 0) ||
                     (pcVar13 = *(code **)(*(long *)(lVar18 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                    writel_relaxed(uVar8,*(long *)(lVar18 + 8) +
                                         (long)(iVar7 << (ulong)(*(uint *)(lVar18 + 0x1c) & 0x1f)) +
                                         0x58);
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1100b8);
                      (*pcVar13)();
                    }
                    (*pcVar13)(lVar18,iVar7,0x58,uVar8);
                  }
                  DataSynchronizationBarrier(3,2,0);
                  iVar7 = *(int *)(lVar18 + 0x18) + uVar9;
                  if ((*(long *)(lVar18 + 0x30) == 0) ||
                     (pcVar13 = *(code **)(*(long *)(lVar18 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                    writel_relaxed(1,*(long *)(lVar18 + 8) +
                                     (long)(iVar7 << (ulong)(*(uint *)(lVar18 + 0x1c) & 0x1f)) + 8);
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1100e4);
                      (*pcVar13)();
                    }
                    (*pcVar13)(lVar18,iVar7,8,1);
                  }
                  iVar7 = *(int *)(lVar18 + 0x18) + uVar9;
                  if ((*(long *)(lVar18 + 0x30) == 0) ||
                     (pcVar13 = *(code **)(*(long *)(lVar18 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                    writel_relaxed(uVar11,*(long *)(lVar18 + 8) +
                                          (long)(iVar7 << (ulong)(*(uint *)(lVar18 + 0x1c) & 0x1f)))
                    ;
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x110110);
                      (*pcVar13)();
                    }
                    (*pcVar13)(lVar18,iVar7,0,uVar11);
                  }
                }
                if (*(int *)(*(code **)(plVar14[5] + 8) + -4) != 0x21f83a90) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fe20);
                  (*pcVar13)();
                }
                iVar7 = (**(code **)(plVar14[5] + 8))(plVar14);
                if (iVar7 == 0) {
                  iVar7 = 1;
                  goto LAB_0010f96c;
                }
              }
              _raw_spin_unlock_irqrestore(lVar1,uVar12);
              lVar17 = 0;
            }
            else {
              iVar7 = *(int *)(plVar14 + 9) + 1;
LAB_0010f96c:
              *(int *)(plVar14 + 9) = iVar7;
              _raw_spin_unlock_irqrestore(lVar1,uVar12);
              iVar7 = *(int *)(lVar15 + 0x18) + (uint)bVar3;
              if ((*(undefined8 **)(lVar15 + 0x30) == (undefined8 *)0x0) ||
                 (pcVar13 = (code *)**(undefined8 **)(lVar15 + 0x30), pcVar13 == (code *)0x0)) {
                uVar8 = readl_relaxed(*(long *)(lVar15 + 8) +
                                      (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)));
              }
              else {
                if (*(int *)(pcVar13 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10ff30);
                  (*pcVar13)();
                }
                uVar8 = (*pcVar13)(lVar15,iVar7,0);
              }
              iVar7 = *(int *)(lVar15 + 0x18) + (uint)bVar3;
              if ((*(long *)(lVar15 + 0x30) == 0) ||
                 (pcVar13 = *(code **)(*(long *)(lVar15 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                writel_relaxed(uVar8 & 0xffffff3f,
                               *(long *)(lVar15 + 8) +
                               (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)));
              }
              else {
                if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10ff58);
                  (*pcVar13)();
                }
                (*pcVar13)(lVar15,iVar7,0);
              }
              uVar11 = (uint)bVar3;
              iVar7 = *(int *)(lVar15 + 0x18) + uVar11;
              if ((*(undefined8 **)(lVar15 + 0x30) == (undefined8 *)0x0) ||
                 (pcVar13 = (code *)**(undefined8 **)(lVar15 + 0x30), pcVar13 == (code *)0x0)) {
                uVar9 = readl_relaxed(*(long *)(lVar15 + 8) +
                                      (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)) +
                                      0x58);
              }
              else {
                if (*(int *)(pcVar13 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10ff80);
                  (*pcVar13)();
                }
                uVar9 = (*pcVar13)(lVar15,iVar7,0x58);
              }
              uVar19 = (uint)bVar3;
              if ((uVar9 & 0xc00001fe) != 0) {
                iVar7 = *(int *)(lVar15 + 0x18) + uVar11;
                if ((*(long *)(lVar15 + 0x30) == 0) ||
                   (pcVar13 = *(code **)(*(long *)(lVar15 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                  writel_relaxed(uVar9,*(long *)(lVar15 + 8) +
                                       (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)) +
                                       0x58);
                  DataSynchronizationBarrier(3,2,0);
                }
                else {
                  if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10ffd4);
                    (*pcVar13)();
                  }
                  (*pcVar13)(lVar15,iVar7,0x58,uVar9);
                  DataSynchronizationBarrier(3,2,0);
                }
                if ((uVar9 >> 0x1e & 1) != 0) {
                  iVar7 = *(int *)(lVar15 + 0x18) + uVar19;
                  if ((*(long *)(lVar15 + 0x30) == 0) ||
                     (pcVar13 = *(code **)(*(long *)(lVar15 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                    writel_relaxed(1,*(long *)(lVar15 + 8) +
                                     (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)) + 8);
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x110008);
                      (*pcVar13)();
                    }
                    (*pcVar13)(lVar15,iVar7,8,1);
                  }
                }
              }
              uVar12 = _raw_spin_lock_irqsave();
              uVar9 = 0;
              do {
                if (*(int *)(*(code **)(plVar14[5] + 0x18) + -4) != -0x2d1fa720) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fadc);
                  (*pcVar13)();
                }
                lVar17 = (**(code **)(plVar14[5] + 0x18))(plVar14,uVar16,uVar2,(int)uVar5);
                iVar7 = *(int *)(lVar15 + 0x18) + uVar19;
                if ((*(undefined8 **)(lVar15 + 0x30) == (undefined8 *)0x0) ||
                   (pcVar13 = (code *)**(undefined8 **)(lVar15 + 0x30), pcVar13 == (code *)0x0)) {
                  uVar10 = readl_relaxed(*(long *)(lVar15 + 8) +
                                         (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)) +
                                         0x58);
                }
                else {
                  if (*(int *)(pcVar13 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fbc8);
                    (*pcVar13)();
                  }
                  uVar10 = (*pcVar13)(lVar15,iVar7,0x58);
                }
                if ((uVar10 & 0xc00001fe) != 0) {
                  iVar7 = *(int *)(lVar15 + 0x18) + uVar11;
                  if ((*(long *)(lVar15 + 0x30) == 0) ||
                     (pcVar13 = *(code **)(*(long *)(lVar15 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                    writel_relaxed(uVar10,*(long *)(lVar15 + 8) +
                                          (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f))
                                          + 0x58);
                    DataSynchronizationBarrier(3,2,0);
                  }
                  else {
                    if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fbf4);
                      (*pcVar13)();
                    }
                    (*pcVar13)(lVar15,iVar7,0x58,uVar10);
                    DataSynchronizationBarrier(3,2,0);
                  }
                  if ((uVar10 >> 0x1e & 1) != 0) {
                    iVar7 = *(int *)(lVar15 + 0x18) + uVar11;
                    if ((*(long *)(lVar15 + 0x30) == 0) ||
                       (pcVar13 = *(code **)(*(long *)(lVar15 + 0x30) + 8), pcVar13 == (code *)0x0))
                    {
                      writel_relaxed(1,*(long *)(lVar15 + 8) +
                                       (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)) + 8
                                    );
                    }
                    else {
                      if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fc28);
                        (*pcVar13)();
                      }
                      (*pcVar13)(lVar15,iVar7,8,1);
                    }
                  }
                }
              } while ((lVar17 == 0) && (bVar6 = uVar9 < 2, uVar9 = uVar9 + 1, bVar6));
              iVar7 = *(int *)(lVar15 + 0x18) + uVar19;
              if ((*(long *)(lVar15 + 0x30) == 0) ||
                 (pcVar13 = *(code **)(*(long *)(lVar15 + 0x30) + 8), pcVar13 == (code *)0x0)) {
                writel_relaxed(uVar8,*(long *)(lVar15 + 8) +
                                     (long)(iVar7 << (ulong)(*(uint *)(lVar15 + 0x1c) & 0x1f)));
              }
              else {
                if (*(int *)(pcVar13 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10ffa8);
                  (*pcVar13)();
                }
                (*pcVar13)(lVar15,iVar7,0);
              }
              _raw_spin_unlock_irqrestore(lVar15 + 400,uVar12);
              uVar12 = _raw_spin_lock_irqsave(lVar1);
              iVar7 = *(int *)(plVar14 + 9) + -1;
              if (iVar7 == 0) {
                if (*(int *)(*(code **)(plVar14[5] + 0x10) + -4) != 0x58f642d7) {
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fe64);
                  (*pcVar13)();
                }
                (**(code **)(plVar14[5] + 0x10))(plVar14);
                *(undefined4 *)(plVar14 + 9) = 0;
              }
              else {
                if (*(int *)(plVar14 + 9) == 0) {
                  lVar15 = ((long *)plVar14[2])[0xe];
                  if (lVar15 == 0) {
                    lVar15 = *(long *)plVar14[2];
                  }
                  __warn_printk("%s bad tbu->halt_count",lVar15);
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x800,0x10ff0c);
                  (*pcVar13)();
                }
                *(int *)(plVar14 + 9) = iVar7;
              }
              _raw_spin_unlock_irqrestore(lVar1,uVar12);
            }
          }
          else {
            _dev_notice(plVar14[2],"TBU opted-out for halting!\n");
            lVar17 = 0;
          }
          if (*(int *)(*(code **)(plVar14[5] + 0x20) + -4) != 0x58f642d7) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10fe9c);
            (*pcVar13)();
          }
          (**(code **)(plVar14[5] + 0x20))(plVar14);
          DataSynchronizationBarrier(3,1,0);
          arm_smmu_power_off(plVar14[3],plVar14[6]);
          goto LAB_0010f8f0;
        }
        iVar7 = ___ratelimit(qsmmuv500_iova_to_phys__rs,"qsmmuv500_iova_to_phys");
        if (iVar7 != 0) {
          _dev_err(plVar14[2],"ECATS: address too large: %pad\n",&local_70);
        }
      }
      goto LAB_0010f8ec;
    }
    plVar14 = (long *)*plVar14;
  } while( true );
}



//------------------------------------------------------------
// qsmmuv500_tlb_sync_timeout @ 0011011c size=912
// signature: undefined qsmmuv500_tlb_sync_timeout(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qsmmuv500_tlb_sync_timeout(undefined8 *param_1)

{
  char *pcVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  undefined8 *puVar9;
  code *pcVar10;
  ulong uVar11;
  undefined8 *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  ulong uVar17;
  undefined8 local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_70 = 0;
  iVar3 = ___ratelimit(qsmmuv500_tlb_sync_timeout__rs_42,"qsmmuv500_tlb_sync_timeout");
  if (iVar3 == 0) {
    puVar9 = (undefined8 *)param_1[6];
    if (puVar9 == (undefined8 *)0x0) goto LAB_0011017c;
LAB_00110174:
    pcVar10 = (code *)*puVar9;
    if (pcVar10 == (code *)0x0) goto LAB_0011017c;
    if (*(int *)(pcVar10 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1101f4);
      (*pcVar10)();
    }
    uVar4 = (*pcVar10)(param_1,7,0x5dc);
    if (uVar4 == 0) goto LAB_00110200;
LAB_001101a0:
    uVar16 = uVar4 & 1;
    uVar14 = uVar4 >> 1 & 0x7fff;
    uVar13 = uVar4 >> 0x10 & 1;
    uVar15 = uVar4 >> 0x11;
  }
  else {
    _dev_err(*param_1,"TLB sync timed out -- SMMU may be deadlocked\n");
    puVar9 = (undefined8 *)param_1[6];
    if (puVar9 != (undefined8 *)0x0) goto LAB_00110174;
LAB_0011017c:
    uVar4 = readl_relaxed(param_1[1] + (long)(7 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                          + 0x5dc);
    if (uVar4 != 0) goto LAB_001101a0;
LAB_00110200:
    uVar15 = 0;
    uVar14 = 0;
    uVar13 = 0;
    uVar16 = 0;
  }
  iVar3 = qcom_scm_io_readl(param_1[0x26] + 0x2204,(long)&local_70 + 4);
  if (iVar3 == 0) {
    iVar3 = qcom_scm_io_readl(param_1[0x26] + 0x2670,&local_70);
    uVar11 = local_70;
    if (iVar3 == 0) {
      if (local_70._4_4_ == 0) {
LAB_00110260:
        uVar16 = 0;
      }
      else if (uVar13 == 0) {
        if (uVar16 == 0) goto LAB_00110260;
        uVar16 = local_70._4_4_ & (uVar14 ^ 0xffffffff);
      }
      else {
        uVar16 = local_70._4_4_ & (uVar15 ^ 0xffffffff);
      }
      uVar14 = (uint)local_70;
      iVar3 = ___ratelimit(qsmmuv500_tlb_sync_timeout__rs,"qsmmuv500_tlb_sync_timeout");
      if (iVar3 != 0) {
        _dev_err(*param_1,"TBU ACK 0x%x TBU PWR 0x%x TCU sync_inv 0x%x\n",uVar4,local_70._4_4_,
                 local_70 & 0xffffffff);
        pcVar7 = "completed";
        if ((uVar11 & 0x10000) != 0) {
          pcVar7 = "pending";
        }
        pcVar1 = "completed";
        if ((uVar14 >> 0x14 & 1) != 0) {
          pcVar1 = "pending";
        }
        _dev_err(*param_1,"TCU invalidation %s, TCU sync %s\n",pcVar7,pcVar1);
        uVar11 = 0;
        puVar2 = &DAT_001192fc;
        if (uVar13 != 0) {
          puVar2 = &DAT_001190ba;
        }
        puVar9 = param_1 + 0x28;
        pcVar7 = "check for TBU power status";
        if (uVar13 != 0) {
          pcVar7 = "check pending transactions on TBU";
        }
        do {
          uVar11 = -1L << (uVar11 & 0x3f) & (ulong)uVar16;
          uVar11 = (uVar11 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar11 & 0x5555555555555555) << 1;
          uVar11 = (uVar11 & 0xcccccccccccccccc) >> 2 | (uVar11 & 0x3333333333333333) << 2;
          uVar11 = (uVar11 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar11 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar11 = (uVar11 & 0xff00ff00ff00ff00) >> 8 | (uVar11 & 0xff00ff00ff00ff) << 8;
          uVar17 = LZCOUNT((uVar11 >> 0x10 | (uVar11 & 0xffff0000ffff) << 0x10) << 0x20);
          if (0x3f < uVar17) break;
          puVar12 = (undefined8 *)*puVar9;
          if (puVar12 != puVar9) {
            uVar4 = ((uint)uVar17 & 0x3f) * 0x400;
            do {
              if ((*(uint *)(puVar12 + 7) <= uVar4) &&
                 (uVar4 < *(int *)((long)puVar12 + 0x3c) + *(uint *)(puVar12 + 7))) {
                if (puVar12 != (undefined8 *)0x0) {
                  lVar8 = ((long *)puVar12[2])[0xe];
                  if (lVar8 == 0) {
                    lVar8 = *(long *)puVar12[2];
                  }
                  _dev_err(*param_1,"TBU %s ack pending for TBU %s, %s\n",puVar2,lVar8,pcVar7);
                }
                break;
              }
              puVar12 = (undefined8 *)*puVar12;
            } while (puVar12 != puVar9);
          }
          uVar11 = uVar17 + 1;
        } while (uVar17 < 0x3f);
      }
      if ((uVar14 >> 0x14 & 1) != 0) {
        queue_work_on(0x20,_system_wq,param_1 + 0x2c);
      }
      goto LAB_00110350;
    }
    iVar5 = ___ratelimit(qsmmuv500_tlb_sync_timeout__rs_46,"qsmmuv500_tlb_sync_timeout");
    if (iVar5 != 0) {
      uVar6 = *param_1;
      pcVar7 = "SCM read of TBU sync/inv prog fails: %d\n";
      goto LAB_001102f0;
    }
  }
  else {
    iVar5 = ___ratelimit(qsmmuv500_tlb_sync_timeout__rs_44,"qsmmuv500_tlb_sync_timeout");
    if (iVar5 != 0) {
      uVar6 = *param_1;
      pcVar7 = "SCM read of TBU power status fails: %d\n";
LAB_001102f0:
      _dev_err(uVar6,pcVar7,iVar3);
    }
  }
  if (uVar4 != 0) {
    puVar2 = &DAT_001192fc;
    if (uVar13 != 0) {
      puVar2 = &DAT_001190ba;
      uVar14 = uVar15;
    }
    pcVar7 = "check for TBU power status";
    if (uVar13 != 0) {
      pcVar7 = "check pending transactions on TBU";
    }
    _dev_err(*param_1,"TBU %s ack pending, got ack for TBUs %d, %s\n",puVar2,uVar14,pcVar7);
  }
  _dev_err(*param_1,"TBU SYNC_INV_ACK reg 0x%x\n",uVar4);
LAB_00110350:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qsmmuv500_device_remove @ 001104b0 size=32
// signature: undefined qsmmuv500_device_remove(void)
// callers: []
//------------------------------------------------------------

void qsmmuv500_device_remove(long param_1)

{
  cancel_work_sync(param_1 + 0x160);
  return;
}



//------------------------------------------------------------
// qsmmuv500_device_group @ 001104d4 size=384
// signature: undefined qsmmuv500_device_group(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qsmmuv500_device_group(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ushort *puVar9;
  long lVar10;
  long *plVar11;
  
  lVar4 = *(long *)(param_1 + 0x338);
  if (lVar4 != 0) {
    lVar10 = *(long *)(lVar4 + 0x40);
    plVar11 = *(long **)(lVar4 + 0x50);
    if (lVar10 != 0 && plVar11 != (long *)0x0) {
      lVar4 = *plVar11;
      pcVar3 = (char *)iommu_group_get_iommudata(param_2);
      if (pcVar3 == (char *)0x0) {
        pcVar3 = (char *)kmalloc_trace(_device_link_add,0xdc0,8);
        if (pcVar3 == (char *)0x0) {
          return 0xfffffff4;
        }
        iommu_group_set_iommudata(param_2,pcVar3,qsmmuv500_release_group_iommudata);
        uVar1 = *(uint *)(lVar4 + 0x158);
      }
      else {
        uVar1 = *(uint *)(lVar4 + 0x158);
      }
      if (uVar1 != 0) {
        uVar7 = (ulong)uVar1;
        uVar6 = (ulong)*(uint *)(lVar10 + 0x14);
        uVar5 = 0;
        uVar8 = uVar6;
        do {
          if (uVar8 != 0) {
            uVar8 = 0;
            puVar9 = (ushort *)(*(long *)(lVar4 + 0x150) + uVar5 * 0xc);
            iVar2 = *(int *)(puVar9 + 4);
            do {
              uVar7 = (long)*(short *)((long)plVar11 + uVar8 * 2 + 8) & 0xffffffff;
              if (((*(ushort *)(*(long *)(lVar4 + 0x68) + uVar7 * 8) & (*puVar9 ^ 0xffff)) == 0) &&
                 ((ushort)((*(ushort *)(*(long *)(lVar4 + 0x68) + uVar7 * 8 + 2) ^ puVar9[1]) &
                          (*puVar9 ^ 0xffff)) == 0)) {
                if (*pcVar3 == '\0') {
                  *(int *)(pcVar3 + 4) = iVar2;
                  *pcVar3 = '\x01';
                  uVar6 = (ulong)*(uint *)(lVar10 + 0x14);
                }
                else if (*(int *)(pcVar3 + 4) != iVar2) {
                  _dev_err(param_1,"Invalid actlr setting\n");
                  return 0xffffffea;
                }
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar6);
            uVar7 = (ulong)*(uint *)(lVar4 + 0x158);
            uVar8 = uVar6;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar7);
      }
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// qcom_def_domain_type @ 00110658 size=292
// signature: undefined qcom_def_domain_type(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_def_domain_type(long param_1)

{
  char *__s1;
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  char *local_80;
  long local_78 [11];
  
  lVar2 = sp_el0;
  local_78[10] = *(long *)(lVar2 + 0x638);
  local_80 = (char *)0x0;
  local_78[0] = 0;
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[1] = 0;
  iVar1 = __of_parse_phandle_with_args
                    (*(undefined8 *)(param_1 + 0x2e8),"qcom,iommu-group",0,0,0,local_78);
  if ((iVar1 != 0) || (lVar2 = local_78[0], local_78[0] == 0)) {
    lVar2 = *(long *)(param_1 + 0x2e8);
  }
  iVar1 = of_property_read_string(lVar2,"qcom,iommu-dma",&local_80);
  if (iVar1 != 0) {
    local_80 = "default";
  }
  __s1 = local_80;
  iVar1 = strcmp(local_80,"fastmap");
  if ((iVar1 == 0) || (iVar1 = strcmp(__s1,"bypass"), iVar1 == 0)) {
    uVar3 = 1;
  }
  else {
    iVar1 = strcmp(__s1,"atomic");
    uVar3 = 3;
    if (iVar1 != 0) {
      iVar1 = strcmp(__s1,"disabled");
      uVar3 = 3;
      if (iVar1 == 0) {
        uVar3 = 4;
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_adreno_smmu_alloc_context_bank @ 00110780 size=228
// signature: undefined qcom_adreno_smmu_alloc_context_bank(void)
// callers: []
//------------------------------------------------------------

ulong qcom_adreno_smmu_alloc_context_bank(undefined8 param_1,long param_2,long param_3)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  ulong uVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  undefined8 uVar12;
  
  lVar8 = 0;
  if (*(long *)(param_3 + 0x338) != 0) {
    lVar8 = *(long *)(*(long *)(param_3 + 0x338) + 0x40);
  }
  uVar2 = *(uint *)(lVar8 + 0x14);
  if (uVar2 == 0) {
LAB_001107ec:
    iVar7 = *(int *)(param_2 + 0x38);
    uVar12 = 2;
  }
  else {
    if ((*(ushort *)(lVar8 + 0x18) & 0xfffe) != 0) {
      uVar5 = 1;
      do {
        uVar11 = uVar5;
        if (uVar2 == uVar11) break;
        uVar5 = uVar11 + 1;
      } while ((*(uint *)(lVar8 + (long)(int)uVar11 * 4 + 0x18) & 0xfffe) != 0);
      if (uVar2 <= uVar11) goto LAB_001107ec;
    }
    uVar12 = 0;
    iVar7 = 2;
  }
  do {
    uVar6 = _find_next_zero_bit(param_2 + 0x40,(long)iVar7,uVar12);
    if (iVar7 == (int)uVar6) {
      return 0xffffffe4;
    }
    uVar9 = 1L << (uVar6 & 0x3f);
    puVar1 = (ulong *)(param_2 + 0x40 + (uVar6 >> 6 & 0x3ffffff) * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar10 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar10 | uVar9;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
  } while ((uVar10 & uVar9) != 0);
  return uVar6;
}



//------------------------------------------------------------
// qcom_adreno_smmu_get_ttbr1_cfg @ 0011087c size=12
// signature: undefined qcom_adreno_smmu_get_ttbr1_cfg(void)
// callers: []
//------------------------------------------------------------

long qcom_adreno_smmu_get_ttbr1_cfg(long param_1)

{
  return *(long *)(param_1 + 0x10) + -0x58;
}



//------------------------------------------------------------
// qcom_adreno_smmu_set_ttbr0_cfg @ 0011088c size=296
// signature: undefined qcom_adreno_smmu_set_ttbr0_cfg(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_adreno_smmu_set_ttbr0_cfg(long *param_1,ulong *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong *puVar4;
  long lVar5;
  undefined1 *puVar6;
  ulong uVar7;
  ulong uVar8;
  ulong *puVar9;
  
  uVar7 = (ulong)*(byte *)(param_1 + 6);
  lVar5 = *(long *)(*param_1 + 0x50);
  puVar4 = (ulong *)(lVar5 + uVar7 * 0x30);
  puVar9 = puVar4 + 2;
  uVar2 = (uint)*puVar9;
  if ((uVar2 >> 0x17 & 1) == 0) {
    if (param_2 == (ulong *)0x0) {
      if ((uVar2 >> 7 & 1) != 0) goto LAB_001109a4;
      uVar2 = *(uint *)(param_1[2] + -0x20);
      uVar2 = (uVar2 & 0x60) << 7 | (uVar2 >> 3 & 3) << 0xe | (uVar2 >> 7 & 3) << 10 |
              uVar2 >> 1 & 0x300 | uVar2 >> 0xb & 0x3f;
      uVar1 = uVar2 | 0x800000;
      if ((*(ulong *)(param_1[2] + -0x58) & 0x20) != 0) {
        uVar1 = uVar2 << 0x10 | 0x80;
      }
      puVar6 = *(undefined1 **)(lVar5 + uVar7 * 0x30 + 0x28);
      *(uint *)puVar9 = uVar1;
      uVar8 = (ulong)*(ushort *)(puVar6 + 2) << 0x30;
    }
    else {
      if ((uVar2 >> 7 & 1) == 0) goto LAB_001109a4;
      uVar1 = (uint)param_2[7];
      uVar1 = (uVar1 & 0x60) << 7 | (uVar1 >> 3 & 3) << 0xe | (uVar1 >> 7 & 3) << 10 |
              uVar1 >> 1 & 0x300 | uVar1 >> 0xb & 0x3f;
      if ((*param_2 & 0x20) != 0) {
        uVar1 = uVar1 << 0x10;
      }
      *(uint *)puVar9 = uVar1 | uVar2 & 0xff7fff7f;
      uVar8 = param_2[6];
      puVar6 = *(undefined1 **)(lVar5 + uVar7 * 0x30 + 0x28);
      *puVar4 = uVar8;
      uVar8 = uVar8 | (ulong)*(ushort *)(puVar6 + 2) << 0x30;
    }
    *puVar4 = uVar8;
    arm_smmu_write_context_bank(*param_1,*puVar6);
    uVar3 = 0;
  }
  else {
LAB_001109a4:
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_adreno_smmu_get_fault_info @ 001109b8 size=728
// signature: undefined qcom_adreno_smmu_get_fault_info(void)
// callers: []
//------------------------------------------------------------

void qcom_adreno_smmu_get_fault_info(long *param_1,undefined8 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = *param_1;
  iVar1 = *(int *)(lVar5 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(undefined8 **)(lVar5 + 0x30) == (undefined8 *)0x0) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar5 + 0x30), pcVar4 == (code *)0x0)) {
    uVar2 = readl_relaxed(*(long *)(lVar5 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) + 0x58);
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110b98);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(lVar5,iVar1,0x58);
  }
  *(undefined4 *)((long)param_2 + 0x14) = uVar2;
  iVar1 = *(int *)(lVar5 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(undefined8 **)(lVar5 + 0x30) == (undefined8 *)0x0) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar5 + 0x30), pcVar4 == (code *)0x0)) {
    uVar2 = readl_relaxed(*(long *)(lVar5 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) + 0x68);
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110bc0);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(lVar5,iVar1,0x68);
  }
  *(undefined4 *)(param_2 + 3) = uVar2;
  iVar1 = *(int *)(lVar5 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(undefined8 **)(lVar5 + 0x30) == (undefined8 *)0x0) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar5 + 0x30), pcVar4 == (code *)0x0)) {
    uVar2 = readl_relaxed(*(long *)(lVar5 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) + 0x6c);
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110be8);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(lVar5,iVar1,0x6c);
  }
  *(undefined4 *)((long)param_2 + 0x1c) = uVar2;
  iVar1 = *(int *)(lVar5 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(long *)(lVar5 + 0x30) == 0) ||
     (pcVar4 = *(code **)(*(long *)(lVar5 + 0x30) + 0x10), pcVar4 == (code *)0x0)) {
    uVar3 = readq_relaxed(*(long *)(lVar5 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) + 0x60);
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110c10);
      (*pcVar4)();
    }
    uVar3 = (*pcVar4)(lVar5,iVar1,0x60);
  }
  *param_2 = uVar3;
  if ((*(undefined8 **)(lVar5 + 0x30) == (undefined8 *)0x0) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar5 + 0x30), pcVar4 == (code *)0x0)) {
    uVar2 = readl_relaxed(*(long *)(lVar5 + 8) +
                          (long)(1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) +
                          ((ulong)*(byte *)(param_1 + 6) << 2 | 0x400));
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110c38);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(lVar5,1);
  }
  *(undefined4 *)(param_2 + 4) = uVar2;
  iVar1 = *(int *)(lVar5 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(long *)(lVar5 + 0x30) == 0) ||
     (pcVar4 = *(code **)(*(long *)(lVar5 + 0x30) + 0x10), pcVar4 == (code *)0x0)) {
    uVar3 = readq_relaxed(*(long *)(lVar5 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) + 0x20);
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110c60);
      (*pcVar4)();
    }
    uVar3 = (*pcVar4)(lVar5,iVar1,0x20);
  }
  param_2[1] = uVar3;
  iVar1 = *(int *)(lVar5 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(undefined8 **)(lVar5 + 0x30) == (undefined8 *)0x0) ||
     (pcVar4 = (code *)**(undefined8 **)(lVar5 + 0x30), pcVar4 == (code *)0x0)) {
    uVar2 = readl_relaxed(*(long *)(lVar5 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar5 + 0x1c) & 0x1f)) + 0x34);
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x110c88);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)(lVar5,iVar1,0x34);
  }
  *(undefined4 *)(param_2 + 2) = uVar2;
  return;
}



//------------------------------------------------------------
// qcom_adreno_smmu_set_stall @ 00110c94 size=44
// signature: undefined qcom_adreno_smmu_set_stall(void)
// callers: []
//------------------------------------------------------------

void qcom_adreno_smmu_set_stall(long *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(*param_1 + 0x14c);
  uVar3 = (uint)(1L << ((ulong)*(byte *)(param_1 + 6) & 0x3f));
  uVar1 = uVar2 | uVar3;
  if ((param_2 & 1) == 0) {
    uVar1 = uVar2 & (uVar3 ^ 0xffffffff);
  }
  *(uint *)(*param_1 + 0x14c) = uVar1;
  return;
}



//------------------------------------------------------------
// qcom_adreno_smmu_resume_translation @ 00110cc4 size=128
// signature: undefined qcom_adreno_smmu_resume_translation(void)
// callers: []
//------------------------------------------------------------

void qcom_adreno_smmu_resume_translation(long *param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *param_1;
  iVar1 = *(int *)(lVar2 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(long *)(lVar2 + 0x30) == 0) ||
     (pcVar3 = *(code **)(*(long *)(lVar2 + 0x30) + 8), pcVar3 == (code *)0x0)) {
    writel_relaxed(param_2 & 1,
                   *(long *)(lVar2 + 8) + (long)(iVar1 << (ulong)(*(uint *)(lVar2 + 0x1c) & 0x1f)) +
                   8);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x110d3c);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2,iVar1,8);
  }
  return;
}



//------------------------------------------------------------
// qsmmuv500_release_group_iommudata @ 00110d48 size=28
// signature: undefined qsmmuv500_release_group_iommudata(void)
// callers: []
//------------------------------------------------------------

void qsmmuv500_release_group_iommudata(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// qcom_smmu500_reset @ 00110d68 size=112
// signature: undefined qcom_smmu500_reset(void)
// callers: []
//------------------------------------------------------------

ulong qcom_smmu500_reset(long *param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(*param_1 + 0x2e8);
  arm_mmu500_reset();
  uVar2 = of_device_is_compatible(uVar3,"qcom,sdm845-smmu-500");
  if ((int)uVar2 != 0) {
    uVar1 = qcom_scm_qsmmu500_wait_safe_toggle(0);
    uVar2 = 0;
    if (uVar1 != 0) {
      _dev_warn(*param_1,"Failed to turn off SAFE logic\n");
      uVar2 = (ulong)uVar1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_smmu_tlb_sync @ 00110ddc size=304
// signature: undefined qcom_smmu_tlb_sync(void)
// callers: []
//------------------------------------------------------------

void qcom_smmu_tlb_sync(long param_1,int param_2,undefined8 param_3,int param_4)

{
  bool bVar1;
  ulong uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar3 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar3 == (code *)0x0)) {
    writel_relaxed(0xffffffff,
                   *(long *)(param_1 + 8) +
                   (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)) + (long)(int)param_3
                  );
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x110f04);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,param_2,param_3,0xffffffff);
  }
  uVar4 = 1;
  do {
    iVar5 = -10;
    do {
      if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
         (pcVar3 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar3 == (code *)0x0)) {
        uVar2 = readl_relaxed(*(long *)(param_1 + 8) + (long)param_4 +
                              (long)(param_2 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
      }
      else {
        if (*(int *)(pcVar3 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x110ea4);
          (*pcVar3)();
        }
        uVar2 = (*pcVar3)(param_1,param_2,param_4);
      }
      if ((uVar2 & 1) == 0) {
        return;
      }
      Yield();
      bVar1 = iVar5 != -1;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    __udelay(uVar4);
    uVar4 = uVar4 << 1;
    if (499999 < uVar4) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// qcom_smmu_def_domain_type @ 00110f10 size=52
// signature: undefined qcom_smmu_def_domain_type(void)
// callers: []
//------------------------------------------------------------

long qcom_smmu_def_domain_type(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = of_match_device(&qcom_smmu_client_of_match,param_1);
  return (ulong)(lVar1 != 0) << 2;
}



//------------------------------------------------------------
// qcom_adreno_smmu_write_sctlr @ 00110f48 size=136
// signature: undefined qcom_adreno_smmu_write_sctlr(void)
// callers: []
//------------------------------------------------------------

void qcom_adreno_smmu_write_sctlr(long param_1,ulong param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  
  uVar2 = 0x100;
  if ((*(uint *)(param_1 + 0x14c) >> (param_2 & 0x3f) & 1) != 0) {
    uVar2 = 0x180;
  }
  iVar1 = *(int *)(param_1 + 0x18) + (int)param_2;
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar3 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar3 == (code *)0x0)) {
    writel_relaxed(uVar2 | param_3,
                   *(long *)(param_1 + 8) +
                   (long)(iVar1 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x110fc8);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,iVar1,0);
  }
  return;
}



//------------------------------------------------------------
// qcom_smmu_cfg_probe @ 00110fd4 size=824
// signature: undefined qcom_smmu_cfg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smmu_cfg_probe(long *param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  code *pcVar8;
  undefined8 *puVar9;
  int iVar10;
  ulong uVar11;
  
  iVar4 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,msm8998-smmu-v2");
  if ((iVar4 != 0) && ((int)param_1[7] == 0xd)) {
    *(undefined4 *)(param_1 + 7) = 0xc;
  }
  uVar5 = *(uint *)((long)param_1 + 0x5c);
  if (0x80 < uVar5) {
    _dev_notice(*param_1,"\tLimiting the stream matching groups to 128\n");
    uVar5 = 0x80;
    *(undefined4 *)((long)param_1 + 0x5c) = 0x80;
  }
  uVar5 = uVar5 * 4 + 0xbfc;
  if ((param_1[6] == 0) || (pcVar8 = *(code **)(param_1[6] + 8), pcVar8 == (code *)0x0)) {
    writel_relaxed(0x100ff,param_1[1] + (ulong)uVar5);
    puVar9 = (undefined8 *)param_1[6];
    if (puVar9 != (undefined8 *)0x0) goto LAB_0011105c;
LAB_00111064:
    uVar5 = readl_relaxed(param_1[1] + (ulong)uVar5);
  }
  else {
    if (*(int *)(pcVar8 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x111244);
      (*pcVar8)();
    }
    (*pcVar8)(param_1,0,uVar5,0x100ff);
    puVar9 = (undefined8 *)param_1[6];
    if (puVar9 == (undefined8 *)0x0) goto LAB_00111064;
LAB_0011105c:
    pcVar8 = (code *)*puVar9;
    if (pcVar8 == (code *)0x0) goto LAB_00111064;
    if (*(int *)(pcVar8 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x111278);
      (*pcVar8)();
    }
    uVar5 = (*pcVar8)(param_1,0,uVar5);
  }
  if ((uVar5 & 0x30000) != 0x10000) {
    uVar5 = *(byte *)(param_1 + 7) - 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(char *)((long)param_1 + 0x149) = (char)uVar5;
    puVar1 = (ulong *)(param_1 + ((ulong)(uVar5 >> 6) & 3) + 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 1L << ((ulong)uVar5 & 0x3f);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    iVar4 = (int)param_1[3] + (uint)*(byte *)((long)param_1 + 0x149);
    if ((param_1[6] == 0) || (pcVar8 = *(code **)(param_1[6] + 8), pcVar8 == (code *)0x0)) {
      writel_relaxed(0,param_1[1] + (long)(iVar4 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                    );
    }
    else {
      if (*(int *)(pcVar8 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1112a4);
        (*pcVar8)();
      }
      (*pcVar8)(param_1,iVar4,0,0);
    }
    lVar7 = (ulong)*(byte *)((long)param_1 + 0x149) * 4;
    if ((param_1[6] != 0) && (pcVar8 = *(code **)(param_1[6] + 8), pcVar8 != (code *)0x0)) {
      if (*(int *)(pcVar8 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1112d0);
        (*pcVar8)();
      }
      (*pcVar8)(param_1,1,lVar7,0x10000);
      iVar4 = *(int *)((long)param_1 + 0x5c);
      goto joined_r0x001112d8;
    }
    writel_relaxed(0x10000,param_1[1] + (long)(1 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                           + lVar7);
  }
  iVar4 = *(int *)((long)param_1 + 0x5c);
joined_r0x001112d8:
  if (iVar4 != 0) {
    uVar11 = 0;
    iVar4 = 0x800;
    do {
      iVar10 = (int)uVar11;
      if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
         (pcVar8 = *(code **)param_1[6], pcVar8 == (code *)0x0)) {
        iVar6 = readl_relaxed(param_1[1] + (long)iVar4);
      }
      else {
        if (*(int *)(pcVar8 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1111f0);
          (*pcVar8)();
        }
        iVar6 = (*pcVar8)(param_1,0,iVar4);
      }
      if (iVar6 < 0) {
        uVar11 = -(uVar11 >> 0x1f) & 0xfffffff800000000 | uVar11 << 3;
        *(short *)(param_1[0xd] + uVar11 + 2) = (short)iVar6;
        *(ushort *)(param_1[0xd] + uVar11) = (ushort)((uint)iVar6 >> 0x10) & 0x7fff;
        *(undefined1 *)(param_1[0xd] + uVar11 + 4) = 1;
        *(undefined1 *)(param_1[0xd] + uVar11 + 6) = 1;
        lVar7 = ((long)iVar10 + (long)iVar10 * 2) * 8;
        *(undefined4 *)(param_1[0xe] + lVar7 + 0xc) = 1;
        *(undefined4 *)(param_1[0xe] + lVar7 + 0x10) = 0;
        *(undefined1 *)(param_1[0xe] + lVar7 + 0x14) = 0xff;
      }
      uVar11 = (ulong)(iVar10 + 1U);
      iVar4 = iVar4 + 4;
    } while (iVar10 + 1U < *(uint *)((long)param_1 + 0x5c));
  }
  return 0;
}



//------------------------------------------------------------
// qcom_smmu_init_context @ 00111318 size=20
// signature: undefined qcom_smmu_init_context(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_smmu_init_context(long param_1)

{
  *(undefined1 *)(param_1 + 0x44) = 1;
  return 0;
}



//------------------------------------------------------------
// qcom_smmu_write_s2cr @ 00111330 size=188
// signature: undefined qcom_smmu_write_s2cr(void)
// callers: []
//------------------------------------------------------------

void qcom_smmu_write_s2cr(long param_1,int param_2)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x70) + (long)param_2 * 0x18;
  uVar1 = (uint)*(byte *)(lVar4 + 0x14);
  uVar3 = *(uint *)(lVar4 + 0xc);
  if (*(char *)(param_1 + 0x148) != '\0') {
    if (uVar3 == 2) {
      uVar1 = 0xff;
      uVar3 = 1;
    }
    else if (uVar3 == 1) {
      uVar1 = (uint)*(byte *)(param_1 + 0x149);
      uVar3 = 0;
    }
  }
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
    writel_relaxed(uVar1 | (uVar3 & 3) << 0x10 |
                   (*(uint *)(*(long *)(param_1 + 0x70) + (long)param_2 * 0x18 + 0x10) & 3) << 0x18,
                   *(long *)(param_1 + 8) + (long)(param_2 * 4 + 0xc00));
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1113e4);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,0);
  }
  return;
}



//------------------------------------------------------------
// qsmmuv2_device_reset @ 001113f0 size=532
// signature: undefined qsmmuv2_device_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 qsmmuv2_device_reset(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  undefined4 *puVar4;
  ulong uVar5;
  
  lVar3 = *(long *)(param_1 + -0x10);
  if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
     (pcVar2 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar2 == (code *)0x0)) {
    uVar1 = readl_relaxed(*(long *)(param_1 + 8) +
                          (long)(6 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x111578);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,6,0);
  }
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
    writel_relaxed(uVar1 | 4,
                   *(long *)(param_1 + 8) + (long)(6 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1115a4);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,6,0);
  }
  qsmmuv2_wait_for_halt(param_1);
  if (*(int *)(param_1 + -8) != 0) {
    uVar5 = 0;
    puVar4 = (undefined4 *)(lVar3 + 4);
    do {
      if ((*(long *)(param_1 + 0x30) == 0) ||
         (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
        writel_relaxed(*puVar4,*(long *)(param_1 + 8) + (long)(int)puVar4[-1]);
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1114dc);
          (*pcVar2)();
        }
        (*pcVar2)(param_1,0);
      }
      uVar5 = uVar5 + 1;
      puVar4 = puVar4 + 2;
    } while (uVar5 < *(uint *)(param_1 + -8));
  }
  if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
     (pcVar2 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar2 == (code *)0x0)) {
    uVar1 = readl_relaxed(*(long *)(param_1 + 8) +
                          (long)(6 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1115d0);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,6,0);
  }
  if ((*(long *)(param_1 + 0x30) == 0) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x30) + 8), pcVar2 == (code *)0x0)) {
    writel_relaxed(uVar1 & 0xfffffffb,
                   *(long *)(param_1 + 8) + (long)(6 << (ulong)(*(uint *)(param_1 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1115fc);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,6,0);
  }
  return 0;
}



//------------------------------------------------------------
// qsmmuv2_init_cb @ 00111608 size=176
// signature: undefined qsmmuv2_init_cb(void)
// callers: []
//------------------------------------------------------------

void qsmmuv2_init_cb(long *param_1)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  lVar2 = *param_1;
  puVar4 = (undefined8 *)param_1[5];
  iVar1 = *(int *)(lVar2 + 0x18) + (uint)*(byte *)(param_1 + 6);
  if ((*(long *)(lVar2 + 0x30) == 0) ||
     (pcVar3 = *(code **)(*(long *)(lVar2 + 0x30) + 8), pcVar3 == (code *)0x0)) {
    writel_relaxed(0x70000000,
                   *(long *)(lVar2 + 8) + (long)(iVar1 << (ulong)(*(uint *)(lVar2 + 0x1c) & 0x1f)) +
                   4);
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1116b0);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2,iVar1,4,0x70000000);
  }
  if (*(int *)((code *)*puVar4 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11167c);
    (*pcVar3)();
  }
  (*(code *)*puVar4)(param_1);
  return;
}



//------------------------------------------------------------
// qsmmuv2_iova_to_phys_hard @ 001116bc size=1616
// signature: undefined qsmmuv2_iova_to_phys_hard(void)
// callers: []
//------------------------------------------------------------

ulong qsmmuv2_iova_to_phys_hard(long *param_1,ulong *param_2)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  code *pcVar9;
  long lVar10;
  long lVar11;
  undefined8 uVar12;
  undefined8 *puVar13;
  uint uVar14;
  ulong uVar15;
  ulong local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  lVar11 = *param_1;
  bVar2 = *(byte *)(param_1 + 6);
  uVar15 = *param_2;
  uVar5 = _raw_spin_lock_irqsave(lVar11 + -0x18);
  if ((*(undefined8 **)(lVar11 + 0x30) == (undefined8 *)0x0) ||
     (pcVar9 = (code *)**(undefined8 **)(lVar11 + 0x30), pcVar9 == (code *)0x0)) {
    uVar3 = readl_relaxed(*(long *)(lVar11 + 8) +
                          (long)(6 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111af8);
      (*pcVar9)();
    }
    uVar3 = (*pcVar9)(lVar11,6,0);
  }
  if ((*(long *)(lVar11 + 0x30) == 0) ||
     (pcVar9 = *(code **)(*(long *)(lVar11 + 0x30) + 8), pcVar9 == (code *)0x0)) {
    writel_relaxed(uVar3 | 4,
                   *(long *)(lVar11 + 8) + (long)(6 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111b24);
      (*pcVar9)();
    }
    (*pcVar9)(lVar11,6,0);
  }
  iVar1 = *(int *)(lVar11 + 0x18) + (uint)bVar2;
  if ((*(undefined8 **)(lVar11 + 0x30) == (undefined8 *)0x0) ||
     (pcVar9 = (code *)**(undefined8 **)(lVar11 + 0x30), pcVar9 == (code *)0x0)) {
    uVar3 = readl_relaxed(*(long *)(lVar11 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111b4c);
      (*pcVar9)();
    }
    uVar3 = (*pcVar9)(lVar11,iVar1,0);
  }
  iVar1 = *(int *)(lVar11 + 0x18) + (uint)bVar2;
  if ((*(long *)(lVar11 + 0x30) == 0) ||
     (pcVar9 = *(code **)(*(long *)(lVar11 + 0x30) + 8), pcVar9 == (code *)0x0)) {
    writel_relaxed(uVar3 & 0xffffff7f,
                   *(long *)(lVar11 + 8) + (long)(iVar1 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f))
                  );
  }
  else {
    if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111b74);
      (*pcVar9)();
    }
    (*pcVar9)(lVar11,iVar1,0);
  }
  uVar14 = (uint)bVar2;
  iVar1 = *(int *)(lVar11 + 0x18) + uVar14;
  if ((*(undefined8 **)(lVar11 + 0x30) == (undefined8 *)0x0) ||
     (pcVar9 = (code *)**(undefined8 **)(lVar11 + 0x30), pcVar9 == (code *)0x0)) {
    uVar4 = readl_relaxed(*(long *)(lVar11 + 8) +
                          (long)(iVar1 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)) + 0x58);
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111b9c);
      (*pcVar9)();
    }
    uVar4 = (*pcVar9)(lVar11,iVar1,0x58);
  }
  if ((uVar4 & 0xc00001fe) != 0) {
    iVar1 = *(int *)(lVar11 + 0x18) + uVar14;
    if ((*(long *)(lVar11 + 0x30) == 0) ||
       (pcVar9 = *(code **)(*(long *)(lVar11 + 0x30) + 8), pcVar9 == (code *)0x0)) {
      writel_relaxed(uVar4,*(long *)(lVar11 + 8) +
                           (long)(iVar1 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)) + 0x58);
      DataSynchronizationBarrier(3,2,0);
    }
    else {
      if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111c7c);
        (*pcVar9)();
      }
      (*pcVar9)(lVar11,iVar1,0x58,uVar4);
      DataSynchronizationBarrier(3,2,0);
    }
    if ((uVar4 >> 0x1e & 1) != 0) {
      iVar1 = *(int *)(lVar11 + 0x18) + uVar14;
      if ((*(long *)(lVar11 + 0x30) == 0) ||
         (pcVar9 = *(code **)(*(long *)(lVar11 + 0x30) + 8), pcVar9 == (code *)0x0)) {
        writel_relaxed(1,*(long *)(lVar11 + 8) +
                         (long)(iVar1 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)) + 8);
      }
      else {
        if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111d00);
          (*pcVar9)();
        }
        (*pcVar9)(lVar11,iVar1,8,1);
      }
    }
  }
  qsmmuv2_wait_for_halt(lVar11);
  puVar13 = (undefined8 *)*param_1;
  bVar2 = *(byte *)(param_1 + 6);
  uVar12 = *puVar13;
  iVar1 = *(int *)(puVar13 + 3) + (uint)bVar2;
  local_70 = uVar15;
  if ((int)param_1[8] == 1) {
    if ((puVar13[6] == 0) || (pcVar9 = *(code **)(puVar13[6] + 0x18), pcVar9 == (code *)0x0)) {
      writeq_relaxed(uVar15 & 0xfffffffffffff000,
                     puVar13[1] + (long)(iVar1 << (ulong)(*(uint *)((long)puVar13 + 0x1c) & 0x1f)) +
                     0x800);
    }
    else {
      if (*(int *)(pcVar9 + -4) != 0x6bc70ae0) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111cac);
        (*pcVar9)();
      }
      (*pcVar9)(puVar13,iVar1,0x800);
    }
  }
  else if ((puVar13[6] == 0) || (pcVar9 = *(code **)(puVar13[6] + 8), pcVar9 == (code *)0x0)) {
    writel_relaxed(uVar15 & 0xfffff000,
                   puVar13[1] + (long)(iVar1 << (ulong)(*(uint *)((long)puVar13 + 0x1c) & 0x1f)) +
                   0x800);
  }
  else {
    if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111cd4);
      (*pcVar9)();
    }
    (*pcVar9)(puVar13,iVar1,0x800);
  }
  iVar1 = *(int *)(puVar13 + 3);
  uVar4 = *(uint *)((long)puVar13 + 0x1c);
  lVar10 = puVar13[1];
  lVar6 = ktime_get();
  lVar10 = lVar10 + (int)(iVar1 + (uint)bVar2 << (ulong)(uVar4 & 0x1f)) + 0x8f0;
  uVar7 = readl(lVar10);
  if ((uVar7 & 1) != 0) {
    do {
      lVar8 = ktime_get();
      if (lVar6 + 50000 < lVar8) {
        uVar7 = readl(lVar10);
        break;
      }
      __const_udelay(0x53e3);
      Yield();
      uVar7 = readl(lVar10);
    } while ((uVar7 & 1) != 0);
  }
  if ((uVar7 & 1) == 0) {
    if ((puVar13[6] == 0) || (pcVar9 = *(code **)(puVar13[6] + 0x10), pcVar9 == (code *)0x0)) {
      uVar7 = readq_relaxed(puVar13[1] +
                            (long)(int)(*(int *)(puVar13 + 3) + (uint)bVar2 <<
                                       (ulong)(*(uint *)((long)puVar13 + 0x1c) & 0x1f)) + 0x50);
    }
    else {
      if (*(int *)(pcVar9 + -4) != 0x7ce96f14) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111c50);
        (*pcVar9)();
      }
      uVar7 = (*pcVar9)(puVar13,*(int *)(puVar13 + 3) + (uint)bVar2,0x50);
    }
    if ((uVar7 & 1) == 0) {
      uVar15 = uVar7 & 0xfffffffff000 | uVar15 & 0xfff;
    }
    else {
      _dev_err(uVar12,"translation fault!\n");
      _dev_err(uVar12,"PAR = 0x%llx\n",uVar7);
      uVar15 = 0;
    }
  }
  else {
    _dev_err(uVar12,"iova to phys timed out on %pad.\n",&local_70);
    uVar15 = 0;
  }
  iVar1 = *(int *)(lVar11 + 0x18) + uVar14;
  if ((*(long *)(lVar11 + 0x30) == 0) ||
     (pcVar9 = *(code **)(*(long *)(lVar11 + 0x30) + 8), pcVar9 == (code *)0x0)) {
    writel_relaxed(uVar3,*(long *)(lVar11 + 8) +
                         (long)(iVar1 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)));
    puVar13 = *(undefined8 **)(lVar11 + 0x30);
  }
  else {
    if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111bc8);
      (*pcVar9)();
    }
    (*pcVar9)(lVar11,iVar1,0,uVar3);
    puVar13 = *(undefined8 **)(lVar11 + 0x30);
  }
  if ((puVar13 == (undefined8 *)0x0) || (pcVar9 = (code *)*puVar13, pcVar9 == (code *)0x0)) {
    uVar3 = readl_relaxed(*(long *)(lVar11 + 8) +
                          (long)(6 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar9 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111bfc);
      (*pcVar9)();
    }
    uVar3 = (*pcVar9)(lVar11,6,0);
  }
  if ((*(long *)(lVar11 + 0x30) == 0) ||
     (pcVar9 = *(code **)(*(long *)(lVar11 + 0x30) + 8), pcVar9 == (code *)0x0)) {
    writel_relaxed(uVar3 & 0xfffffffb,
                   *(long *)(lVar11 + 8) + (long)(6 << (ulong)(*(uint *)(lVar11 + 0x1c) & 0x1f)));
  }
  else {
    if (*(int *)(pcVar9 + -4) != -0x6a7e488b) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x111c28);
      (*pcVar9)();
    }
    (*pcVar9)(lVar11,6,0);
  }
  _raw_spin_unlock_irqrestore(lVar11 + -0x18,uVar5);
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}



//------------------------------------------------------------
// qsmmuv2_tlb_sync_timeout @ 00111d10 size=332
// signature: undefined qsmmuv2_tlb_sync_timeout(void)
// callers: []
//------------------------------------------------------------

void qsmmuv2_tlb_sync_timeout(undefined8 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  code *pcVar5;
  
  iVar1 = ___ratelimit(qsmmuv2_tlb_sync_timeout__rs,"qsmmuv2_tlb_sync_timeout");
  if (iVar1 == 0) {
    puVar4 = (undefined8 *)param_1[6];
  }
  else {
    _dev_err(*param_1,"TLB sync timed out -- SMMU may be deadlocked\n");
    puVar4 = (undefined8 *)param_1[6];
  }
  if ((puVar4 == (undefined8 *)0x0) || (pcVar5 = (code *)*puVar4, pcVar5 == (code *)0x0)) {
    uVar2 = readl_relaxed(param_1[1] + (long)(6 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                          + 0x50);
  }
  else {
    if (*(int *)(pcVar5 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x111e28);
      (*pcVar5)();
    }
    uVar2 = (*pcVar5)(param_1,6,0x50);
  }
  if (((undefined8 *)param_1[6] == (undefined8 *)0x0) ||
     (pcVar5 = *(code **)param_1[6], pcVar5 == (code *)0x0)) {
    uVar3 = readl_relaxed(param_1[1] + (long)(6 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f))
                          + 0x54);
  }
  else {
    if (*(int *)(pcVar5 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x111e54);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)(param_1,6,0x54);
  }
  iVar1 = ___ratelimit(qsmmuv2_tlb_sync_timeout__rs_76,"qsmmuv2_tlb_sync_timeout");
  if (iVar1 != 0) {
    _dev_err(*param_1,"clk on 0x%x, clk on client 0x%x status\n",uVar2,uVar3);
  }
  return;
}



//------------------------------------------------------------
// qsmmuv2_wait_for_halt @ 00111e5c size=156
// signature: undefined qsmmuv2_wait_for_halt(void)
// callers: [qsmmuv2_iova_to_phys_hard, qsmmuv2_device_reset]
//------------------------------------------------------------

void qsmmuv2_wait_for_halt(undefined8 *param_1)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  
  uVar2 = *param_1;
  lVar1 = param_1[1] + (long)(6 << (ulong)(*(uint *)((long)param_1 + 0x1c) & 0x1f));
  lVar4 = ktime_get();
  uVar3 = readl(lVar1);
  if ((uVar3 >> 3 & 1) == 0) {
    do {
      lVar5 = ktime_get();
      if (lVar4 + 30000000 < lVar5) {
        uVar3 = readl(lVar1);
        break;
      }
      Yield();
      uVar3 = readl(lVar1);
    } while ((uVar3 >> 3 & 1) == 0);
  }
  if ((uVar3 >> 3 & 1) == 0) {
    _dev_err(uVar2,"Couldn\'t halt SMMU!\n");
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_power_on @ 00111f0c size=536
// signature: undefined arm_smmu_power_on(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_device_probe, arm_smmu_pm_resume, arm_smmu_pm_restore_early, arm_smmu_debug_capture_bus_match, qsmmuv500_log_outstanding_transactions, arm_smmu_pm_freeze_late, arm_smmu_runtime_resume]
//------------------------------------------------------------

int arm_smmu_power_on(undefined8 *param_1)

{
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  
  mutex_lock(param_1 + 6);
  if (*(int *)(param_1 + 0xc) < 1) {
    if (param_1[5] != 0) {
      iVar4 = icc_set_bw(param_1[5],0,1000);
      if (iVar4 != 0) goto LAB_00111f50;
    }
    uVar1 = *(uint *)(param_1 + 4);
    if (0 < (int)uVar1) {
      lVar6 = param_1[3];
      uVar8 = 0;
      puVar9 = (undefined8 *)(lVar6 + 0x10);
      do {
        iVar4 = regulator_enable(*puVar9);
        if (iVar4 != 0) {
          if (uVar8 != 0) {
            lVar7 = uVar8 + 1;
            do {
              regulator_disable(*(undefined8 *)(lVar6 + (ulong)((int)lVar7 - 2) * 0x20 + 0x10));
              lVar7 = lVar7 + -1;
            } while (1 < lVar7);
          }
          goto LAB_0011206c;
        }
        uVar8 = uVar8 + 1;
        puVar9 = puVar9 + 4;
      } while (uVar1 != uVar8);
    }
    if (0 < *(int *)(param_1 + 2)) {
      uVar8 = 0;
      lVar6 = 8;
      do {
        iVar4 = clk_prepare(*(undefined8 *)(param_1[1] + uVar8 * 8));
        if (iVar4 != 0) {
          _dev_err(*param_1,"Couldn\'t prepare clock #%d\n",uVar8 & 0xffffffff);
          if ((int)uVar8 != 0) {
            lVar6 = -lVar6;
            do {
              clk_unprepare(*(undefined8 *)(param_1[1] + lVar6));
              bVar3 = lVar6 != 0;
              lVar6 = lVar6 + -8;
            } while (bVar3);
          }
          goto LAB_00112034;
        }
        uVar8 = uVar8 + 1;
        lVar6 = lVar6 + -8;
      } while ((long)uVar8 < (long)*(int *)(param_1 + 2));
    }
    iVar4 = arm_smmu_enable_clocks(param_1);
    if (iVar4 != 0) {
LAB_00112010:
      if (*(int *)(param_1 + 2) != 0) {
        iVar5 = *(int *)(param_1 + 2) + -1;
        do {
          clk_unprepare(*(undefined8 *)(param_1[1] + (long)iVar5 * 8));
          iVar5 = iVar5 + -1;
        } while (iVar5 != -1);
      }
LAB_00112034:
      regulator_bulk_disable(*(undefined4 *)(param_1 + 4),param_1[3]);
LAB_0011206c:
      if ((param_1[5] != 0) && (iVar5 = icc_set_bw(param_1[5],0,0), iVar5 != 0)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x112088);
        (*pcVar2)();
      }
      goto LAB_00111f50;
    }
    pcVar2 = (code *)param_1[0xd];
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != 0x69dfc376) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1120b0);
        (*pcVar2)();
      }
      iVar4 = (*pcVar2)(param_1);
      if (iVar4 != 0) {
        if (*(int *)(param_1 + 2) != 0) {
          iVar5 = *(int *)(param_1 + 2) + -1;
          do {
            clk_disable(*(undefined8 *)(param_1[1] + (long)iVar5 * 8));
            iVar5 = iVar5 + -1;
          } while (iVar5 != -1);
          goto LAB_00112010;
        }
        goto LAB_00112034;
      }
    }
    iVar5 = 1;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + 1;
  }
  iVar4 = 0;
  *(int *)(param_1 + 0xc) = iVar5;
LAB_00111f50:
  mutex_unlock(param_1 + 6);
  return iVar4;
}



//------------------------------------------------------------
// arm_smmu_enable_clocks @ 00112128 size=168
// signature: undefined arm_smmu_enable_clocks(void)
// callers: [arm_smmu_power_on]
//------------------------------------------------------------

int arm_smmu_enable_clocks(undefined8 *param_1)

{
  bool bVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  
  if (0 < *(int *)(param_1 + 2)) {
    uVar3 = 0;
    lVar4 = 8;
    do {
      iVar2 = clk_enable(*(undefined8 *)(param_1[1] + uVar3 * 8));
      if (iVar2 != 0) {
        _dev_err(*param_1,"Couldn\'t enable clock #%d\n",uVar3 & 0xffffffff);
        if ((int)uVar3 == 0) {
          return iVar2;
        }
        lVar4 = -lVar4;
        do {
          clk_disable(*(undefined8 *)(param_1[1] + lVar4));
          bVar1 = lVar4 != 0;
          lVar4 = lVar4 + -8;
        } while (bVar1);
        return iVar2;
      }
      uVar3 = uVar3 + 1;
      lVar4 = lVar4 + -8;
    } while ((long)uVar3 < (long)*(int *)(param_1 + 2));
  }
  return 0;
}



//------------------------------------------------------------
// arm_smmu_power_off @ 001121d4 size=364
// signature: undefined arm_smmu_power_off(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_device_probe, arm_smmu_runtime_suspend, arm_smmu_debug_capture_bus_match, qsmmuv500_log_outstanding_transactions, arm_smmu_pm_suspend, arm_smmu_device_shutdown, arm_smmu_pm_freeze_late]
//------------------------------------------------------------

void arm_smmu_power_off(long param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  
  mutex_lock(param_2 + 6);
  iVar1 = *(int *)(param_2 + 0xc);
  if (iVar1 == 0) {
    lVar2 = ((long *)*param_2)[0xe];
    if (lVar2 == 0) {
      lVar2 = *(long *)*param_2;
    }
    __warn_printk("%s: Bad power count\n",lVar2);
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x112238);
    (*pcVar3)();
  }
  if (iVar1 < 2) {
    pcVar3 = (code *)param_2[0xe];
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x2e807006) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x112260);
        (*pcVar3)();
      }
      (*pcVar3)(param_2);
    }
    if (param_1 != 0) {
      if ((*(undefined8 **)(param_1 + 0x30) == (undefined8 *)0x0) ||
         (pcVar3 = (code *)**(undefined8 **)(param_1 + 0x30), pcVar3 == (code *)0x0)) {
        readl_relaxed(*(long *)(param_1 + 8) + 0x20);
      }
      else {
        if (*(int *)(pcVar3 + -4) != 0x2f125b4d) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x112340);
          (*pcVar3)();
        }
        (*pcVar3)(param_1,0,0x20);
      }
      DataSynchronizationBarrier(3,1,0);
    }
    if (*(int *)(param_2 + 2) != 0) {
      iVar1 = *(int *)(param_2 + 2) + -1;
      do {
        clk_disable(*(undefined8 *)(param_2[1] + (long)iVar1 * 8));
        iVar1 = iVar1 + -1;
      } while (iVar1 != -1);
      if (*(int *)(param_2 + 2) != 0) {
        iVar1 = *(int *)(param_2 + 2) + -1;
        do {
          clk_unprepare(*(undefined8 *)(param_2[1] + (long)iVar1 * 8));
          iVar1 = iVar1 + -1;
        } while (iVar1 != -1);
      }
    }
    regulator_bulk_disable(*(undefined4 *)(param_2 + 4),param_2[3]);
    if ((param_2[5] != 0) && (iVar1 = icc_set_bw(param_2[5],0,0), iVar1 != 0)) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x112318);
      (*pcVar3)();
    }
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  else {
    *(int *)(param_2 + 0xc) = iVar1 + -1;
  }
  mutex_unlock(param_2 + 6);
  return;
}



//------------------------------------------------------------
// arm_smmu_init_power_resources @ 0011234c size=716
// signature: undefined arm_smmu_init_power_resources(void)
// callers: [arm_smmu_device_probe, qsmmuv500_tbu_probe]
//------------------------------------------------------------

long * arm_smmu_init_power_resources(long param_1)

{
  uint uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  
  plVar3 = (long *)devm_kmalloc(param_1,0x78,0xdc0);
  if (plVar3 == (long *)0x0) {
    return (long *)0xfffffffffffffff4;
  }
  *plVar3 = param_1;
  __mutex_init(plVar3 + 6,"&pwr->power_lock",&arm_smmu_init_power_resources___key);
  lVar9 = *plVar3;
  uVar1 = of_property_read_string_helper(*(undefined8 *)(lVar9 + 0x2e8),"clock-names",0,0,0);
  *(uint *)(plVar3 + 2) = uVar1;
  if ((int)uVar1 < 1) {
    *(undefined4 *)(plVar3 + 2) = 0;
  }
  else {
    lVar4 = devm_kmalloc(lVar9,(ulong)uVar1 << 3,0xdc0);
    plVar3[1] = lVar4;
    if (lVar4 == 0) {
      return (long *)0xfffffffffffffff4;
    }
    uVar5 = of_find_property(*(undefined8 *)(lVar9 + 0x2e8),"clock-names",0);
    lVar4 = of_prop_next_string(uVar5,0);
    if (lVar4 != 0) {
      iVar2 = 0;
      do {
        uVar6 = devm_clk_get(lVar9,lVar4);
        if (0xfffffffffffff000 < uVar6) {
          _dev_err(lVar9,"Couldn\'t get clock: %s\n",lVar4);
          if ((int)uVar6 != 0) {
            return (long *)(long)(int)uVar6;
          }
          break;
        }
        lVar7 = clk_get_rate(uVar6);
        if (lVar7 == 0) {
          uVar8 = clk_round_rate(uVar6,1000);
          clk_set_rate(uVar6,uVar8);
        }
        *(ulong *)(plVar3[1] + (long)iVar2 * 8) = uVar6;
        iVar2 = iVar2 + 1;
        lVar4 = of_prop_next_string(uVar5,lVar4);
      } while (lVar4 != 0);
    }
  }
  lVar9 = *plVar3;
  uVar1 = of_property_read_string_helper
                    (*(undefined8 *)(lVar9 + 0x2e8),"qcom,regulator-names",0,0,0);
  *(uint *)(plVar3 + 4) = uVar1;
  if ((int)uVar1 < 1) {
    *(undefined4 *)(plVar3 + 4) = 0;
  }
  else {
    lVar4 = devm_kmalloc(lVar9,(ulong)uVar1 << 5,0xdc0);
    plVar3[3] = lVar4;
    if (lVar4 == 0) {
      return (long *)0xfffffffffffffff4;
    }
    uVar5 = of_find_property(*(undefined8 *)(lVar9 + 0x2e8),"qcom,regulator-names",0);
    lVar4 = of_prop_next_string(uVar5,0);
    if (lVar4 != 0) {
      uVar6 = 0;
      do {
        *(long *)(plVar3[3] + (-(uVar6 >> 0x1f) & 0xffffffe000000000 | uVar6 << 5)) = lVar4;
        lVar4 = of_prop_next_string(uVar5);
        uVar6 = (ulong)((int)uVar6 + 1);
      } while (lVar4 != 0);
    }
    iVar2 = devm_regulator_bulk_get(lVar9,(int)plVar3[4],plVar3[3]);
    if (iVar2 != 0) {
      return (long *)(long)iVar2;
    }
  }
  lVar4 = *plVar3;
  lVar9 = of_find_property(*(undefined8 *)(lVar4 + 0x2e8),"interconnects",0);
  if (lVar9 == 0) {
    return plVar3;
  }
  uVar6 = devm_of_icc_get(lVar4,0);
  plVar3[5] = uVar6;
  if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
    lVar9 = of_find_property(*(undefined8 *)(lVar4 + 0x2e8),"qcom,active-only",0);
    if (lVar9 == 0) {
      return plVar3;
    }
    icc_set_tag(plVar3[5],3);
    return plVar3;
  }
  if (uVar6 == 0xfffffffffffffdfb) {
    lVar9 = -0x205;
  }
  else {
    _dev_err(lVar4,"Unable to read interconnect path from devicetree rc: %ld\n");
    lVar9 = plVar3[5];
    if (lVar9 == 0) {
      iVar2 = -0x16;
      goto LAB_001125b8;
    }
  }
  iVar2 = (int)lVar9;
  if (iVar2 == 0) {
    return plVar3;
  }
LAB_001125b8:
  return (long *)(long)iVar2;
}



//------------------------------------------------------------
// readl_relaxed @ 00112618 size=124
// signature: undefined readl_relaxed(void)
// callers: [arm_smmu_power_off]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x112660,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_debugchain_load @ 0011269c size=68
// signature: undefined arm_smmu_debug_qtb_debugchain_load(void)
// callers: []
//------------------------------------------------------------

int arm_smmu_debug_qtb_debugchain_load(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  readl_relaxed(param_1 + 8);
  uVar2 = readl_relaxed(param_1 + 0x18);
  uVar1 = uVar2 >> 5 & 0x3ffffff;
  if ((uVar2 & 0x1f) != 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1 + 1;
}



//------------------------------------------------------------
// readl_relaxed @ 001126e0 size=124
// signature: undefined readl_relaxed(void)
// callers: [arm_smmu_debug_dump_tbu_testbus, arm_smmu_debug_dump_debugchain, arm_smmu_debug_tcu_testbus_select, arm_smmu_debug_dump_tcu_testbus, arm_smmu_debug_qtb_transtracker_get_config, arm_smmu_debug_tbu_testbus_select, arm_smmu_debug_qtb_transtrac_collect, arm_smmu_debug_tbu_testbus_output, arm_smmu_debug_qtb_debugchain_load, arm_smmu_debug_qtb_transtracker_getfilter, arm_smmu_debug_qtb_debugchain_dump, arm_smmu_debug_get_capture_snapshot, arm_smmu_debug_dump_qtb_regs]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x112728,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_debugchain_dump @ 00112760 size=60
// signature: undefined arm_smmu_debug_qtb_debugchain_dump(void)
// callers: []
//------------------------------------------------------------

uint arm_smmu_debug_qtb_debugchain_dump(long param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = readl_relaxed(param_1 + 0x10);
  iVar2 = readl_relaxed(param_1 + 0x14);
  return uVar1 | iVar2 << 0x1f;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_transtracker_set_config @ 001127a0 size=76
// signature: undefined arm_smmu_debug_qtb_transtracker_set_config(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_qtb_transtracker_set_config(long param_1,long param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xa1;
  if (param_2 != 0) {
    uVar1 = 0x121;
  }
  writel_relaxed(uVar1,param_1 + 8);
  writel_relaxed(0,param_1 + 0x30);
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 001127ec size=132
// signature: undefined writel_relaxed(void)
// callers: [arm_smmu_debug_dump_tbu_testbus, arm_smmu_debug_qtb_transtracker_setfilter, arm_smmu_debug_qtb_transtrac_reset, arm_smmu_debug_tcu_testbus_select, arm_smmu_debug_dump_tcu_testbus, arm_smmu_debug_qtb_transtracker_set_config, arm_smmu_debug_tbu_testbus_select]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x112804,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x112840,uVar1);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_transtracker_get_config @ 00112874 size=36
// signature: undefined arm_smmu_debug_qtb_transtracker_get_config(void)
// callers: []
//------------------------------------------------------------

undefined4 arm_smmu_debug_qtb_transtracker_get_config(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = readl_relaxed(param_1 + 8);
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_transtracker_setfilter @ 0011289c size=208
// signature: undefined arm_smmu_debug_qtb_transtracker_setfilter(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_qtb_transtracker_setfilter(long param_1,long param_2,long param_3,int param_4)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_2 == 3) {
    if (param_4 != 2) {
      if (param_4 == 1) {
        writel_relaxed((int)param_3,param_1 + 0x128);
      }
      goto LAB_00112938;
    }
    lVar2 = param_1 + 0x128;
  }
  else {
    if (param_2 != 2) {
      if (param_2 == 1) {
        if (param_3 - 2U < 4) {
          uVar1 = *(undefined4 *)(&DAT_0011a504 + (param_3 - 2U) * 4);
        }
        else {
          uVar1 = 3;
        }
        writel_relaxed(uVar1,param_1 + 0x168);
      }
      goto LAB_00112938;
    }
    if ((param_4 != 2) && (param_4 != 1)) goto LAB_00112938;
    lVar2 = param_1 + 0x120;
  }
  writeq_relaxed(param_3,lVar2);
LAB_00112938:
  writel_relaxed(0x1f,param_1 + 0x138);
  writel_relaxed(0xe3ef,param_1 + 0x170);
  writel_relaxed(0x1ff,param_1 + 0x188);
  return;
}



//------------------------------------------------------------
// writeq_relaxed @ 0011296c size=124
// signature: undefined writeq_relaxed(void)
// callers: [arm_smmu_debug_qtb_transtracker_setfilter, arm_smmu_debug_qtb_transtrac_reset, arm_smmu_debug_set_mask_and_match, arm_smmu_debug_set_tnx_tcr_cntl, arm_smmu_debug_clear_intr_and_validbits]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x1129b8,uVar1);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_transtracker_getfilter @ 001129ec size=180
// signature: undefined arm_smmu_debug_qtb_transtracker_getfilter(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_qtb_transtracker_getfilter(long param_1,ulong *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  
  if (param_3 == 2) {
    uVar3 = readl_relaxed(param_1 + 0x168);
    *param_2 = uVar3 & 0xffffffff;
    uVar1 = readl_relaxed(param_1 + 0x120);
    uVar2 = readl_relaxed(param_1 + 0x124);
    param_2[1] = (ulong)(uVar2 | uVar1);
    uVar1 = readl_relaxed(param_1 + 0x128);
    uVar2 = readl_relaxed(param_1 + 300);
    uVar3 = (ulong)(uVar2 | uVar1);
  }
  else {
    if (param_3 != 1) {
      return;
    }
    uVar3 = readl_relaxed(param_1 + 0x168);
    *param_2 = uVar3 & 0xffffffff;
    uVar3 = readq_relaxed(param_1 + 0x120);
    param_2[1] = uVar3;
    uVar3 = readq_relaxed(param_1 + 0x128);
  }
  param_2[2] = uVar3;
  return;
}



//------------------------------------------------------------
// readq_relaxed @ 00112aa0 size=124
// signature: undefined readq_relaxed(void)
// callers: [arm_smmu_debug_qtb_transtracker_getfilter, arm_smmu_debug_get_mask_and_match, arm_smmu_debug_get_capture_snapshot, arm_smmu_debug_set_tnx_tcr_cntl, arm_smmu_debug_get_tnx_tcr_cntl]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x112ae8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_transtrac_collect @ 00112b20 size=752
// signature: undefined arm_smmu_debug_qtb_transtrac_collect(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_qtb_transtrac_collect
               (long param_1,long param_2,long param_3,long param_4,int param_5)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  ulong *puVar6;
  ulong *puVar7;
  ulong *puVar8;
  long lVar9;
  
  lVar5 = 0;
  puVar6 = (ulong *)(param_4 + 8);
  puVar7 = (ulong *)(param_2 + 0x20);
  puVar8 = (ulong *)(param_3 + 0x40);
  lVar9 = -0x40;
  do {
    uVar4 = readl_relaxed(param_1 + lVar9 + 0x90);
    puVar6[-1] = uVar4 & 0xffffffff;
    uVar4 = readl_relaxed(param_1 + lVar9 + 0xe0);
    *puVar6 = uVar4 & 0xffffffff;
    if (param_5 == 1) {
      lVar1 = param_1 + lVar5;
      uVar2 = readl_relaxed(lVar1 + 0x200);
      uVar3 = readl_relaxed(lVar1 + 0x204);
      puVar7[-4] = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x200);
      uVar3 = readl_relaxed(lVar1 + 0x204);
      puVar7[-3] = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x208);
      uVar3 = readl_relaxed(lVar1 + 0x20c);
      puVar7[-2] = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x208);
      uVar3 = readl_relaxed(lVar1 + 0x20c);
      puVar7[-1] = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x210);
      uVar3 = readl_relaxed(lVar1 + 0x214);
      *puVar7 = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x210);
      uVar3 = readl_relaxed(lVar1 + 0x214);
      puVar7[1] = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x218);
      uVar3 = readl_relaxed(lVar1 + 0x21c);
      puVar7[2] = (ulong)(uVar3 | uVar2);
      uVar2 = readl_relaxed(lVar1 + 0x218);
      uVar3 = readl_relaxed(lVar1 + 0x21c);
      puVar7[3] = (ulong)(uVar3 | uVar2);
    }
    else if (param_5 == 2) {
      lVar1 = param_1 + lVar5;
      uVar4 = readl_relaxed(lVar1 + 0x200);
      puVar8[-8] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x204);
      puVar8[-7] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x200);
      puVar8[-6] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x204);
      puVar8[-5] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x208);
      puVar8[-4] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x20c);
      puVar8[-3] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x208);
      puVar8[-2] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x20c);
      puVar8[-1] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x210);
      *puVar8 = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x214);
      puVar8[1] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x210);
      puVar8[2] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x214);
      puVar8[3] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x218);
      puVar8[4] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x21c);
      puVar8[5] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x218);
      puVar8[6] = uVar4 & 0xffffffff;
      uVar4 = readl_relaxed(lVar1 + 0x21c);
      puVar8[7] = uVar4 & 0xffffffff;
    }
    puVar6 = puVar6 + 2;
    lVar5 = lVar5 + 0x20;
    lVar9 = lVar9 + 8;
    puVar7 = puVar7 + 8;
    puVar8 = puVar8 + 0x10;
  } while (lVar5 != 0x100);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_qtb_transtrac_reset @ 00112e14 size=240
// signature: undefined arm_smmu_debug_qtb_transtrac_reset(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_qtb_transtrac_reset(long param_1)

{
  writel_relaxed(0,param_1 + 8);
  writel_relaxed(1,param_1 + 0x30);
  writel_relaxed(0,param_1 + 0x168);
  writeq_relaxed(0,param_1 + 0x120);
  writeq_relaxed(0,param_1 + 0x128);
  writel_relaxed(0,param_1 + 0x138);
  writel_relaxed(0,param_1 + 0x148);
  writel_relaxed(0,param_1 + 0x150);
  writel_relaxed(0,param_1 + 0x158);
  writel_relaxed(0,param_1 + 0x160);
  writel_relaxed(0,param_1 + 0x170);
  writel_relaxed(0,param_1 + 0x178);
  writel_relaxed(0,param_1 + 0x180);
  writel_relaxed(0,param_1 + 0x188);
  writel_relaxed(0,param_1 + 400);
  writel_relaxed(0,param_1 + 0x198);
  writel_relaxed(0,param_1 + 0x1a0);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_dump_debugchain @ 00112f08 size=216
// signature: undefined arm_smmu_debug_dump_debugchain(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_dump_debugchain(undefined8 param_1,long param_2)

{
  long lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  
  readl_relaxed(param_2 + 8);
  uVar5 = readl_relaxed(param_2 + 0x18);
  uVar3 = (uint)uVar5 >> 5 & 0x3ffffff;
  bVar2 = (uVar5 & 0x1f) != 0;
  if (bVar2) {
    uVar3 = uVar3 + 1;
  }
  uVar5 = uVar5 >> 5 & 0x3ffffff;
  if (bVar2) {
    uVar5 = uVar5 + 1;
  }
  _dev_info(param_1,"Dumping Debug chain: Length : %d\n",uVar3 + 1);
  readl_relaxed(param_2 + 0x10);
  readl_relaxed(param_2 + 0x14);
  lVar6 = 0;
  do {
    uVar3 = readl_relaxed(param_2 + 0x10);
    iVar4 = readl_relaxed(param_2 + 0x14);
    lVar1 = lVar6 + 1;
    _dev_info(param_1,"Debug chain: Index :%ld, val : 0x%lx\n",lVar6,uVar3 | iVar4 << 0x1f);
    lVar6 = lVar1;
  } while (uVar5 + 2 != lVar1);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_dump_qtb_regs @ 00112fe4 size=92
// signature: undefined arm_smmu_debug_dump_qtb_regs(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_dump_qtb_regs(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = readl_relaxed(param_2 + 0xc00);
  uVar2 = readl_relaxed(param_2 + 0xc08);
  _dev_info(param_1,"QSMSTATUS: 0x%lx IDLESTATUS: 0x%lx\n",uVar1,uVar2);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_tbu_testbus_select @ 00113044 size=64
// signature: undefined arm_smmu_debug_tbu_testbus_select(void)
// callers: []
//------------------------------------------------------------

undefined8 arm_smmu_debug_tbu_testbus_select(long param_1,ulong param_2,undefined4 param_3)

{
  undefined8 uVar1;
  
  if ((param_2 & 1) == 0) {
    uVar1 = readl_relaxed(param_1 + 0x50);
  }
  else {
    writel_relaxed(param_3,param_1 + 0x50);
    DataSynchronizationBarrier(3,2,0);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// arm_smmu_debug_tbu_testbus_output @ 00113088 size=32
// signature: undefined arm_smmu_debug_tbu_testbus_output(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_tbu_testbus_output(long param_1)

{
  readl_relaxed(param_1 + 0x58);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_tcu_testbus_select @ 001130ac size=280
// signature: undefined arm_smmu_debug_tcu_testbus_select(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_tcu_testbus_select
               (long param_1,long param_2,int param_3,uint param_4,undefined4 param_5)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (param_3 == 1) {
    if ((param_4 & 1) == 0) {
      uVar4 = readl_relaxed(param_2 + 0x28);
    }
    else {
      writel_relaxed(param_5,param_2 + 8);
      DataSynchronizationBarrier(3,2,0);
      uVar4 = 0;
    }
  }
  else if ((param_4 & 1) == 0) {
    iVar2 = qcom_scm_io_readl(param_1 + 0x25e4,&local_2c);
    if (iVar2 == 0) {
      uVar4 = (ulong)local_2c;
    }
    else {
      uVar4 = ___ratelimit(arm_smmu_debug_tcu_testbus_select__rs_4,
                           "arm_smmu_debug_tcu_testbus_select");
      if ((int)uVar4 != 0) {
        _printk(&DAT_00118b94,iVar2);
        uVar4 = 0;
      }
    }
  }
  else {
    iVar2 = qcom_scm_io_writel(param_1 + 0x25e4,param_5);
    if (iVar2 != 0) {
      iVar3 = ___ratelimit(&arm_smmu_debug_tcu_testbus_select__rs,
                           "arm_smmu_debug_tcu_testbus_select");
      if (iVar3 != 0) {
        _printk(&DAT_00118b94,iVar2);
      }
    }
    DataSynchronizationBarrier(3,2,0);
    uVar4 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_tcu_testbus_output @ 001131c8 size=156
// signature: undefined arm_smmu_debug_tcu_testbus_output(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_tcu_testbus_output(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = qcom_scm_io_readl(param_1 + 0x25e8,&local_2c);
  if (iVar2 == 0) {
    uVar3 = (ulong)local_2c;
  }
  else {
    uVar3 = ___ratelimit(arm_smmu_debug_tcu_testbus_output__rs,"arm_smmu_debug_tcu_testbus_output");
    if ((int)uVar3 != 0) {
      _printk(&DAT_00118dc5,iVar2);
      uVar3 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_dump_tbu_testbus @ 00113268 size=888
// signature: undefined arm_smmu_debug_dump_tbu_testbus(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_dump_tbu_testbus(undefined8 param_1,long param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((param_3 & 1) != 0) {
    _dev_info(param_1,"Dumping TBU clk gate controller:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0x40,lVar1);
    DataSynchronizationBarrier(3,2,0);
    uVar4 = readl_relaxed(lVar1);
    uVar5 = readl_relaxed(param_2 + 0x58);
    _dev_info(param_1,"testbus_sel: 0x%lx val: 0x%llx\n",uVar4,uVar5);
  }
  if ((param_3 >> 1 & 1) != 0) {
    _dev_info(param_1,"Dumping TBU qns4 a2q test bus:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0x80,lVar1);
    uVar3 = 0;
    DataSynchronizationBarrier(3,2,0);
    do {
      uVar2 = readl_relaxed(lVar1);
      writel_relaxed(uVar2 & 0xffffffe0 | uVar3,lVar1);
      DataSynchronizationBarrier(3,2,0);
      uVar4 = readl_relaxed(lVar1);
      uVar5 = readl_relaxed(param_2 + 0x58);
      _dev_info(param_1,"testbus_sel: 0x%lx Index: %d val: 0x%llx\n",uVar4,uVar3,uVar5);
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x20);
  }
  if ((param_3 >> 2 & 1) != 0) {
    _dev_info(param_1,"Dumping qns4 q2a test bus:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0xa0,lVar1);
    uVar3 = 0;
    DataSynchronizationBarrier(3,2,0);
    do {
      uVar2 = readl_relaxed(lVar1);
      writel_relaxed(uVar2 & 0xffffffe0 | uVar3,lVar1);
      DataSynchronizationBarrier(3,2,0);
      uVar4 = readl_relaxed(lVar1);
      uVar5 = readl_relaxed(param_2 + 0x58);
      _dev_info(param_1,"testbus_sel: 0x%lx Index: %d val: 0x%llx\n",uVar4,uVar3,uVar5);
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x20);
  }
  if ((param_3 >> 3 & 1) != 0) {
    _dev_info(param_1,"Dumping multi master qchannel:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0xc0,lVar1);
    DataSynchronizationBarrier(3,2,0);
    uVar4 = readl_relaxed(lVar1);
    uVar5 = readl_relaxed(param_2 + 0x58);
    _dev_info(param_1,"testbus_sel: 0x%lx val: 0x%llx\n",uVar4,uVar5);
  }
  if ((param_3 >> 4 & 1) != 0) {
    _dev_info(param_1,"Dumping tbu clk gate controller ext:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0x100,lVar1);
    DataSynchronizationBarrier(3,2,0);
    uVar4 = readl_relaxed(lVar1);
    uVar5 = readl_relaxed(param_2 + 0x58);
    _dev_info(param_1,"testbus_sel: 0x%lx val: 0x%llx\n",uVar4,uVar5);
  }
  if ((param_3 >> 5 & 1) != 0) {
    _dev_info(param_1,"Dumping tbu low power status:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0x140,lVar1);
    DataSynchronizationBarrier(3,2,0);
    uVar4 = readl_relaxed(lVar1);
    uVar5 = readl_relaxed(param_2 + 0x58);
    _dev_info(param_1,"testbus_sel: 0x%lx val: 0x%llx\n",uVar4,uVar5);
  }
  if ((param_3 >> 6 & 1) != 0) {
    _dev_info(param_1,"Dumping tbu qns4 vld rdy:\n");
    lVar1 = param_2 + 0x50;
    uVar3 = readl_relaxed(lVar1);
    writel_relaxed(uVar3 & 0xfffffe00 | 0x180,lVar1);
    DataSynchronizationBarrier(3,2,0);
    uVar4 = readl_relaxed(lVar1);
    uVar5 = readl_relaxed(param_2 + 0x58);
    _dev_info(param_1,"testbus_sel: 0x%lx val: 0x%llx\n",uVar4,uVar5);
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_dump_tcu_testbus @ 001135e4 size=724
// signature: undefined arm_smmu_debug_dump_tcu_testbus(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_dump_tcu_testbus(undefined8 param_1,long param_2,long param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 local_6c;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  if ((param_4 & 1) != 0) {
    _dev_info(param_1,"Dumping TCU cache testbus:\n");
    arm_smmu_debug_program_tcu_testbus(param_1,param_2,0xfffffffffffffeff,0,1,0,0);
    arm_smmu_debug_program_tcu_testbus(param_1,param_2,0xffffffffffffff00,0,0x20,2,1);
  }
  if ((param_4 >> 1 & 1) != 0) {
    _dev_info(param_1,"Dumping TCU PTW test bus:\n");
    arm_smmu_debug_program_tcu_testbus(param_1,param_2,1,0x100,0x101,0,0);
    arm_smmu_debug_program_tcu_testbus(param_1,param_2,0xffffffffffffff03,0,3,2,1);
    iVar7 = 0x20;
    do {
      iVar1 = iVar7 + 1;
      arm_smmu_debug_program_tcu_testbus(param_1,param_2,0xffffffffffffff00,iVar7,iVar1,2,1);
      arm_smmu_debug_program_tcu_testbus(param_1,param_2,0xfffffffffffffffc,3,4,0,0);
      local_6c = 0;
      iVar5 = qcom_scm_io_readl(param_2 + 0x25e4,&local_6c);
      if (iVar5 == 0) {
        uVar4 = local_6c;
      }
      else {
        iVar6 = ___ratelimit(arm_smmu_debug_tcu_testbus_select__rs_4,
                             "arm_smmu_debug_tcu_testbus_select");
        if (iVar6 != 0) {
          _printk(&DAT_00118b94,iVar5);
        }
        uVar4 = 0;
      }
      local_6c = 0;
      iVar5 = qcom_scm_io_readl(param_2 + 0x25e8,&local_6c);
      if (iVar5 == 0) {
        uVar3 = local_6c;
      }
      else {
        iVar6 = ___ratelimit(arm_smmu_debug_tcu_testbus_output__rs,
                             "arm_smmu_debug_tcu_testbus_output");
        if (iVar6 != 0) {
          _printk(&DAT_00118dc5,iVar5);
        }
        uVar3 = 0;
      }
      _dev_info(param_1,"testbus_sel: 0x%lx Index: %d val: 0x%lx\n",uVar4,iVar7,uVar3);
      iVar7 = iVar1;
    } while (iVar1 != 0x40);
  }
  if ((param_4 >> 2 & 1) != 0) {
    _dev_info(param_1,"Dumping TCU CD testbus:\n");
    arm_smmu_debug_program_tcu_testbus(param_1,param_2,0x100,0,1,0,0);
    arm_smmu_debug_program_tcu_testbus(param_1,param_2,0xffffffffffffff00,1,2,3,1);
  }
  writel_relaxed(0x300,param_3 + 8);
  DataSynchronizationBarrier(3,2,0);
  uVar4 = readl_relaxed(param_3 + 0x28);
  _dev_info(param_1,"Programming Tcu clk gate controller: testbus_sel: 0x%lx\n",uVar4);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_program_tcu_testbus @ 001138b8 size=528
// signature: undefined arm_smmu_debug_program_tcu_testbus(void)
// callers: [arm_smmu_debug_dump_tcu_testbus]
//------------------------------------------------------------

void arm_smmu_debug_program_tcu_testbus
               (undefined8 param_1,long param_2,uint param_3,int param_4,int param_5,uint param_6,
               uint param_7)

{
  long lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if (param_4 < param_5) {
    lVar1 = param_2 + 0x25e4;
    do {
      local_6c = 0;
      iVar2 = qcom_scm_io_readl(lVar1,&local_6c);
      if (iVar2 == 0) {
        uVar5 = local_6c;
      }
      else {
        iVar3 = ___ratelimit(arm_smmu_debug_tcu_testbus_select__rs_4,
                             "arm_smmu_debug_tcu_testbus_select");
        if (iVar3 == 0) {
          uVar5 = 0;
        }
        else {
          _printk(&DAT_00118b94,iVar2);
          uVar5 = 0;
        }
      }
      iVar2 = qcom_scm_io_writel(lVar1,uVar5 & param_3 | param_4 << (ulong)(param_6 & 0x1f));
      if (iVar2 != 0) {
        iVar3 = ___ratelimit(&arm_smmu_debug_tcu_testbus_select__rs,
                             "arm_smmu_debug_tcu_testbus_select");
        if (iVar3 != 0) {
          _printk(&DAT_00118b94,iVar2);
        }
      }
      DataSynchronizationBarrier(3,2,0);
      if ((param_7 & 1) != 0) {
        local_6c = 0;
        iVar2 = qcom_scm_io_readl(lVar1,&local_6c);
        if (iVar2 == 0) {
          uVar5 = local_6c;
        }
        else {
          iVar3 = ___ratelimit(arm_smmu_debug_tcu_testbus_select__rs_4,
                               "arm_smmu_debug_tcu_testbus_select");
          if (iVar3 != 0) {
            _printk(&DAT_00118b94,iVar2);
          }
          uVar5 = 0;
        }
        local_6c = 0;
        iVar2 = qcom_scm_io_readl(param_2 + 0x25e8,&local_6c);
        if (iVar2 == 0) {
          uVar4 = local_6c;
        }
        else {
          iVar3 = ___ratelimit(arm_smmu_debug_tcu_testbus_output__rs,
                               "arm_smmu_debug_tcu_testbus_output");
          if (iVar3 != 0) {
            _printk(&DAT_00118dc5,iVar2);
          }
          uVar4 = 0;
        }
        _dev_info(param_1,"testbus_sel: 0x%lx Index: %d val: 0x%lx\n",uVar5,param_4,uVar4);
      }
      param_4 = param_4 + 1;
    } while (param_5 != param_4);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_set_tnx_tcr_cntl @ 00113acc size=108
// signature: undefined arm_smmu_debug_set_tnx_tcr_cntl(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_set_tnx_tcr_cntl(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = readq_relaxed(param_1 + 0x130);
  if ((uVar1 >> 0x12 & 1) == 0) {
    writeq_relaxed(param_2,param_1 + 0x130);
  }
  else {
    iVar2 = ___ratelimit(arm_smmu_debug_set_tnx_tcr_cntl__rs,"arm_smmu_debug_set_tnx_tcr_cntl");
    if (iVar2 != 0) {
      _printk(&DAT_00118abc);
    }
  }
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_get_tnx_tcr_cntl @ 00113b3c size=32
// signature: undefined arm_smmu_debug_get_tnx_tcr_cntl(void)
// callers: [arm_smmu_debug_capture_bus_match]
//------------------------------------------------------------

void arm_smmu_debug_get_tnx_tcr_cntl(long param_1)

{
  readq_relaxed(param_1 + 0x130);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_set_mask_and_match @ 00113b60 size=64
// signature: undefined arm_smmu_debug_set_mask_and_match(void)
// callers: []
//------------------------------------------------------------

void arm_smmu_debug_set_mask_and_match
               (long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  param_1 = param_1 + param_2 * 8;
  writeq_relaxed(param_3,param_1 + 0xf8);
  writeq_relaxed(param_4,param_1 + 0x110);
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_get_mask_and_match @ 00113ba4 size=144
// signature: undefined arm_smmu_debug_get_mask_and_match(void)
// callers: [arm_smmu_debug_capture_bus_match]
//------------------------------------------------------------

void arm_smmu_debug_get_mask_and_match(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = readq_relaxed(param_1 + 0x100);
  *param_2 = uVar1;
  uVar1 = readq_relaxed(param_1 + 0x118);
  *param_3 = uVar1;
  uVar1 = readq_relaxed(param_1 + 0x108);
  param_2[1] = uVar1;
  uVar1 = readq_relaxed(param_1 + 0x120);
  param_3[1] = uVar1;
  uVar1 = readq_relaxed(param_1 + 0x110);
  param_2[2] = uVar1;
  uVar1 = readq_relaxed(param_1 + 0x128);
  param_3[2] = uVar1;
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_get_capture_snapshot @ 00113c38 size=268
// signature: undefined arm_smmu_debug_get_capture_snapshot(void)
// callers: [arm_smmu_debug_capture_bus_match]
//------------------------------------------------------------

void arm_smmu_debug_get_capture_snapshot(long param_1,undefined8 *param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar3 = 0xdededede;
  uVar1 = readl_relaxed(param_1 + 0x178);
  if ((uVar1 & 1) == 0) {
    *param_2 = 0xdededede;
    param_2[1] = 0xdededede;
  }
  else {
    uVar2 = readq_relaxed(param_1 + 0x138);
    *param_2 = uVar2;
    uVar2 = readq_relaxed(param_1 + 0x140);
    param_2[1] = uVar2;
  }
  if ((uVar1 >> 1 & 1) == 0) {
    param_2[2] = 0xdededede;
    param_2[3] = 0xdededede;
  }
  else {
    uVar2 = readq_relaxed(param_1 + 0x148);
    param_2[2] = uVar2;
    uVar2 = readq_relaxed(param_1 + 0x150);
    param_2[3] = uVar2;
  }
  if ((uVar1 >> 2 & 1) == 0) {
    param_2[4] = 0xdededede;
    param_2[5] = 0xdededede;
  }
  else {
    uVar2 = readq_relaxed(param_1 + 0x158);
    param_2[4] = uVar2;
    uVar2 = readq_relaxed(param_1 + 0x160);
    param_2[5] = uVar2;
  }
  if ((uVar1 >> 3 & 1) == 0) {
    param_2[6] = 0xdededede;
  }
  else {
    uVar3 = readq_relaxed(param_1 + 0x168);
    param_2[6] = uVar3;
    uVar3 = readq_relaxed(param_1 + 0x170);
  }
  param_2[7] = uVar3;
  return;
}



//------------------------------------------------------------
// arm_smmu_debug_clear_intr_and_validbits @ 00113d48 size=36
// signature: undefined arm_smmu_debug_clear_intr_and_validbits(void)
// callers: [arm_smmu_debug_capture_bus_match]
//------------------------------------------------------------

void arm_smmu_debug_clear_intr_and_validbits(long param_1)

{
  writeq_relaxed(0x81,param_1 + 0x130);
  return;
}



//------------------------------------------------------------
// init_module @ 00113d9c size=168
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  ktime_get();
  iVar1 = __platform_driver_register(&qsmmuv500_tbu_driver,&__this_module);
  if (iVar1 == 0) {
    iVar1 = __platform_driver_register(&arm_smmu_driver,&__this_module);
    if (iVar1 == 0) {
      ktime_get();
      iVar1 = 0;
    }
    else {
      platform_driver_unregister(&qsmmuv500_tbu_driver);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00113ee8 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&arm_smmu_driver);
  platform_driver_unregister(&qsmmuv500_tbu_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 0011e000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_iommu_tlbi, perf_trace_iommu_map_pages, trace_event_raw_event_map_sg, perf_trace_tlbsync_timeout, perf_trace_iommu_tlbi, perf_trace_iommu_pgtable, trace_event_raw_event_tlbsync_timeout, trace_event_raw_event_iommu_pgtable, trace_event_raw_event_iommu_map_pages, perf_trace_map_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0011e008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_iommu_tlbi, trace_event_raw_event_smmu_init, trace_event_raw_event_map_sg, trace_event_raw_event_tlbsync_timeout, trace_event_raw_event_iommu_pgtable, trace_event_raw_event_iommu_map_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0011e010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_iommu_tlbi, perf_trace_iommu_map_pages, trace_event_raw_event_map_sg, perf_trace_tlbsync_timeout, perf_trace_iommu_tlbi, perf_trace_iommu_pgtable, trace_event_raw_event_tlbsync_timeout, trace_event_raw_event_iommu_pgtable, trace_event_raw_event_iommu_map_pages, perf_trace_map_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0011e018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_iommu_tlbi, trace_event_raw_event_smmu_init, trace_event_raw_event_map_sg, trace_event_raw_event_tlbsync_timeout, trace_event_raw_event_iommu_pgtable, trace_event_raw_event_iommu_map_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0011e020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_iommu_tlbi, trace_event_raw_event_smmu_init, trace_event_raw_event_map_sg, trace_event_raw_event_tlbsync_timeout, trace_event_raw_event_iommu_pgtable, trace_event_raw_event_iommu_map_pages]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011e028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_iommu_tlbi, arm_smmu_device_cfg_probe, trace_event_raw_event_map_sg, arm_smmu_debug_tcu_testbus_select, arm_smmu_debug_dump_tcu_testbus, trace_event_raw_event_tlbsync_timeout, arm_smmu_of_xlate, perf_trace_iommu_map_pages, arm_smmu_debug_capture_bus_match, arm_smmu_attach_dev, arm_smmu_master_alloc_smes, trace_event_raw_event_iommu_map_pages, qsmmuv500_iova_to_phys_hard, arm_smmu_device_probe, trace_event_raw_event_smmu_init, qsmmuv2_iova_to_phys_hard, qsmmuv500_tlb_sync_timeout, perf_trace_tlbsync_timeout, perf_trace_iommu_tlbi, arm_smmu_context_fault, trace_event_raw_event_iommu_pgtable, arm_smmu_debug_program_tcu_testbus, arm_smmu_device_group, __bus_lookup_iommu_group, arm_smmu_rmr_install_bypass_smr, __arm_smmu_iova_to_phys_hard, qsmmuv500_tbu_probe, qsmmuv2_impl_init, qcom_def_domain_type, perf_trace_iommu_pgtable, perf_trace_smmu_init, perf_trace_map_sg, arm_smmu_debug_tcu_testbus_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0011e030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_iommu_map_pages, perf_trace_tlbsync_timeout, perf_trace_iommu_tlbi, perf_trace_iommu_pgtable, perf_trace_smmu_init, perf_trace_map_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0011e038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_iommu_map_pages, perf_trace_tlbsync_timeout, perf_trace_iommu_tlbi, perf_trace_iommu_pgtable, perf_trace_smmu_init, perf_trace_map_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 0011e040 size=1
// signature: undefined sg_next(void)
// callers: [trace_event_raw_event_map_sg, perf_trace_map_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 0011e048 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_smmu_init, __bpf_trace_iommu_tlbi, __bpf_trace_tlbsync_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0011e050 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_map_sg, __bpf_trace_iommu_map_pages, __bpf_trace_iommu_pgtable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0011e058 size=1
// signature: undefined ktime_get(void)
// callers: [arm_tbu_trigger_atos, __arm_smmu_iova_to_phys_hard, __arm_tbu_micro_idle_cfg, qsmmuv2_iova_to_phys_hard, init_module, qsmmuv2_wait_for_halt, qtb500_tbu_halt_poll, qtb500_trigger_atos, arm_tbu_log_outstanding_transactions, arm_tbu_halt_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0011e060 size=1
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
// platform_driver_unregister @ 0011e068 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0011e088 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_smmu_init, trace_raw_output_map_sg, trace_raw_output_iommu_tlbi, trace_raw_output_iommu_pgtable, trace_raw_output_iommu_map_pages, trace_raw_output_tlbsync_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0011e090 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_smmu_init, trace_raw_output_map_sg, trace_raw_output_iommu_tlbi, trace_raw_output_iommu_pgtable, trace_raw_output_iommu_map_pages, trace_raw_output_tlbsync_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0011e098 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_smmu_init, trace_raw_output_map_sg, trace_raw_output_iommu_tlbi, trace_raw_output_iommu_pgtable, trace_raw_output_iommu_map_pages, trace_raw_output_tlbsync_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0011e0a0 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed, writel_relaxed, writeq_relaxed, writeq_relaxed, writel_relaxed, writeq_relaxed, writel_relaxed, writeq_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0011e0a8 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed, writel_relaxed, writeq_relaxed, writeq_relaxed, writel_relaxed, writeq_relaxed, writel_relaxed, writeq_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dma_iommu_is_ready @ 0011e0b0 size=1
// signature: undefined qcom_dma_iommu_is_ready(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dma_iommu_is_ready(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0011e0b8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qsmmuv500_read_actlr_tbl, arm_smmu_device_probe, qsmmuv500_tbu_probe, arm_smmu_device_cfg_probe, qsmmuv2_impl_init, arm_smmu_init_power_resources, qsmmuv500_tbu_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0011e0c0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [arm_smmu_device_probe, qsmmuv500_tbu_probe, arm_smmu_device_cfg_probe, qsmmuv2_impl_init, arm_smmu_attach_dev, arm_smmu_of_xlate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 0011e0c8 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011e0d0 size=1
// signature: undefined of_find_property(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_device_probe, qsmmuv500_tbu_probe, qsmmuv2_impl_init, arm_smmu_init_power_resources, arm_smmu_attach_dev, arm_smmu_impl_init, arm_smmu_master_alloc_smes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011e0d8 size=1
// signature: undefined _printk(void)
// callers: [arm_smmu_device_probe, arm_smmu_debug_tcu_testbus_select, arm_smmu_debug_dump_tcu_testbus, arm_smmu_debug_set_tnx_tcr_cntl, arm_smmu_debug_program_tcu_testbus, arm_smmu_debug_tcu_testbus_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 0011e0e0 size=1
// signature: undefined dev_err_probe(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_is_coherent @ 0011e0e8 size=1
// signature: undefined of_dma_is_coherent(void)
// callers: [arm_smmu_init_context_bank, arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_is_coherent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_get_and_ioremap_resource @ 0011e0f0 size=1
// signature: undefined devm_platform_get_and_ioremap_resource(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_get_and_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_irq_count @ 0011e0f8 size=1
// signature: undefined platform_irq_count(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_irq_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0011e100 size=1
// signature: undefined platform_get_irq(void)
// callers: [arm_smmu_device_probe, qsmmuv500_tbu_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0011e108 size=1
// signature: undefined _dev_err(void)
// callers: [arm_smmu_tlb_inv_context_s2, arm_smmu_power_on, arm_smmu_device_cfg_probe, qsmmuv2_tlb_sync_timeout, arm_smmu_pm_freeze_late, arm_smmu_global_fault, nvidia_smmu_global_fault, qtb500_log_outstanding_transactions, arm_smmu_device_reset, nvidia_smmu_context_fault, arm_smmu_pm_restore_early, qsmmuv2_wait_for_halt, arm_smmu_init_power_resources, qtb500_trigger_atos, arm_tbu_log_outstanding_transactions, arm_smmu_attach_dev, qsmmuv500_tbu_register, qsmmuv500_iova_to_phys_hard, arm_smmu_device_probe, qsmmuv500_device_group, arm_smmu_tlb_sync_context, qsmmuv2_iova_to_phys_hard, qsmmuv500_tlb_sync_timeout, qtb500_tbu_halt_poll, qsmmuv500_log_outstanding_transactions, arm_smmu_context_fault, arm_smmu_enable_clocks, arm_smmu_device_group, arm_tbu_trigger_atos, __arm_smmu_iova_to_phys_hard, nvidia_smmu_tlb_sync, arm_smmu_pm_prepare, arm_smmu_probe_device, qsmmuv2_impl_init, nvidia_smmu_probe_finalize, arm_tbu_halt_poll]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0011e110 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [arm_smmu_device_probe, arm_smmu_attach_dev, qsmmuv500_tbu_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 0011e118 size=1
// signature: undefined platform_get_resource(void)
// callers: [arm_smmu_device_probe, qsmmuv500_tbu_probe, nvidia_smmu_impl_init, qsmmuv500_tbu_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_device_sysfs_add @ 0011e120 size=1
// signature: undefined iommu_device_sysfs_add(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_device_sysfs_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_device_register @ 0011e128 size=1
// signature: undefined iommu_device_register(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0011e130 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0011e138 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [arm_smmu_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_device_sysfs_remove @ 0011e140 size=1
// signature: undefined iommu_device_sysfs_remove(void)
// callers: [arm_smmu_device_probe, arm_smmu_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_device_sysfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_device_unregister @ 0011e148 size=1
// signature: undefined iommu_device_unregister(void)
// callers: [arm_smmu_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 0011e150 size=1
// signature: undefined _find_first_bit(void)
// callers: [arm_smmu_device_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0011e158 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [arm_smmu_qcom_tlb_sync, arm_smmu_flush_iotlb_all, arm_smmu_iova_to_phys, arm_smmu_context_fault, arm_smmu_get_fault_ids, arm_smmu_rpm_get, arm_smmu_release_device, __arm_smmu_sid_switch, arm_smmu_domain_free, arm_smmu_global_fault, arm_smmu_enable_s1_translation, arm_smmu_probe_device, arm_smmu_map_pages, arm_smmu_attach_dev, arm_smmu_iova_to_phys_hard, arm_smmu_device_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0011e160 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [arm_smmu_rpm_put, arm_smmu_qcom_tlb_sync, arm_smmu_flush_iotlb_all, arm_smmu_iova_to_phys, arm_smmu_context_fault, arm_smmu_get_fault_ids, arm_smmu_release_device, __arm_smmu_sid_switch, arm_smmu_domain_free, arm_smmu_global_fault, arm_smmu_enable_s1_translation, arm_smmu_map_pages, arm_smmu_attach_dev, arm_smmu_iova_to_phys_hard, arm_smmu_device_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0011e168 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [arm_smmu_rpm_put, arm_smmu_qcom_tlb_sync, arm_smmu_flush_iotlb_all, arm_smmu_iova_to_phys, arm_smmu_context_fault, arm_smmu_get_fault_ids, arm_smmu_release_device, __arm_smmu_sid_switch, arm_smmu_domain_free, arm_smmu_global_fault, arm_smmu_enable_s1_translation, arm_smmu_pm_prepare, arm_smmu_map_pages, arm_smmu_attach_dev, arm_smmu_iova_to_phys_hard, arm_smmu_device_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_force_suspend @ 0011e170 size=1
// signature: undefined pm_runtime_force_suspend(void)
// callers: [arm_smmu_device_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_force_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_notice @ 0011e180 size=1
// signature: undefined _dev_notice(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_rmr_install_bypass_smr, arm_smmu_device_cfg_probe, cavium_cfg_probe, qcom_smmu_cfg_probe, arm_smmu_device_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_notice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0011e188 size=1
// signature: undefined __mutex_init(void)
// callers: [arm_smmu_device_cfg_probe, arm_smmu_init_power_resources, arm_smmu_domain_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0011e190 size=1
// signature: undefined _dev_warn(void)
// callers: [arm_smmu_device_cfg_probe, arm_smmu_debug_capture_bus_match, qsmmuv500_log_outstanding_transactions, qcom_smmu500_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0011e198 size=1
// signature: undefined ___ratelimit(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_tlb_inv_context_s2, arm_smmu_tlb_sync_context, qsmmuv500_tlb_sync_timeout, qsmmuv2_tlb_sync_timeout, arm_smmu_debug_tcu_testbus_select, qsmmuv500_log_outstanding_transactions, arm_smmu_debug_dump_tcu_testbus, arm_smmu_context_fault, arm_smmu_debug_program_tcu_testbus, arm_smmu_global_fault, nvidia_smmu_global_fault, arm_tbu_trigger_atos, nvidia_smmu_tlb_sync, arm_smmu_device_reset, nvidia_smmu_context_fault, qtb500_trigger_atos, arm_smmu_debug_capture_bus_match, arm_tbu_log_outstanding_transactions, arm_smmu_debug_set_tnx_tcr_cntl, arm_smmu_debug_tcu_testbus_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0011e1a0 size=1
// signature: undefined of_get_property(void)
// callers: [qsmmuv500_read_actlr_tbl, qsmmuv500_tbu_probe, arm_smmu_handoff_cbs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0011e1a8 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qsmmuv500_read_actlr_tbl, arm_smmu_handoff_cbs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0011e1b0 size=1
// signature: undefined __kmalloc(void)
// callers: [arm_smmu_probe_device, qsmmuv2_impl_init, arm_smmu_handoff_cbs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011e1b8 size=1
// signature: undefined kfree(void)
// callers: [qsmmuv500_release_group_iommudata, arm_smmu_probe_device, qsmmuv2_impl_init, arm_smmu_handoff_cbs, arm_smmu_release_device, arm_smmu_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_fwnode @ 0011e1c0 size=1
// signature: undefined dev_fwnode(void)
// callers: [arm_smmu_rmr_install_bypass_smr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011e1c8 size=1
// signature: undefined mutex_lock(void)
// callers: [arm_smmu_set_pgtable_quirks, arm_smmu_power_on, arm_smmu_power_off, arm_smmu_get_asid_nr, arm_smmu_get_context_bank_nr, arm_smmu_set_secure_vmid, arm_smmu_get_mappings_configuration, arm_smmu_release_device, __arm_smmu_sid_switch, arm_smmu_device_group, arm_smmu_set_fault_model, arm_smmu_device_reset, arm_smmu_enable_s1_translation, arm_smmu_attach_dev, arm_smmu_master_alloc_smes, arm_smmu_enable_nesting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011e1d0 size=1
// signature: undefined mutex_unlock(void)
// callers: [arm_smmu_set_pgtable_quirks, arm_smmu_power_on, arm_smmu_power_off, arm_smmu_get_asid_nr, arm_smmu_get_context_bank_nr, qsmmuv500_log_outstanding_transactions, arm_smmu_set_secure_vmid, arm_smmu_get_mappings_configuration, arm_smmu_release_device, __arm_smmu_sid_switch, arm_smmu_device_group, arm_smmu_set_fault_model, arm_smmu_device_reset, arm_smmu_enable_s1_translation, arm_smmu_debug_capture_bus_match, arm_smmu_attach_dev, arm_smmu_master_alloc_smes, arm_smmu_enable_nesting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0011e1d8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_tlb_inv_context_s2, __arm_smmu_iova_to_phys_hard, arm_smmu_tlb_sync_context, arm_smmu_qcom_tlb_sync, __arm_tbu_micro_idle_cfg, qsmmuv2_iova_to_phys_hard, arm_smmu_device_reset, arm_smmu_skip_tlb_management, arm_smmu_flush_iotlb_all, arm_smmu_tlb_add_walk_page, arm_smmu_qcom_tlb_add_inv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0011e1e0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qsmmuv500_iova_to_phys_hard, arm_smmu_tlb_inv_context_s2, __arm_smmu_iova_to_phys_hard, arm_smmu_tlb_sync_context, arm_smmu_qcom_tlb_sync, __arm_tbu_micro_idle_cfg, qsmmuv2_iova_to_phys_hard, arm_smmu_device_reset, arm_smmu_skip_tlb_management, arm_smmu_flush_iotlb_all, arm_smmu_tlb_add_walk_page, arm_smmu_qcom_tlb_add_inv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0011e1e8 size=1
// signature: undefined dma_set_mask(void)
// callers: [dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0011e1f0 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0011e1f8 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readq_relaxed, readq_relaxed, readl_relaxed, readq_relaxed, readl_relaxed, readl_relaxed, readq_relaxed, readl_relaxed, readl_relaxed, readl, readq, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0011e200 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readq_relaxed, readq_relaxed, readl_relaxed, readq_relaxed, readl_relaxed, readl_relaxed, readq_relaxed, readl_relaxed, readl_relaxed, readl, readq, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_get @ 0011e208 size=1
// signature: undefined iommu_group_get(void)
// callers: [__bus_lookup_iommu_group, arm_smmu_sid_switch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_for_each_dev @ 0011e210 size=1
// signature: undefined iommu_group_for_each_dev(void)
// callers: [arm_smmu_sid_switch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_for_each_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_put @ 0011e218 size=1
// signature: undefined iommu_group_put(void)
// callers: [__bus_lookup_iommu_group, arm_smmu_sid_switch, arm_smmu_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0011e220 size=1
// signature: undefined __warn_printk(void)
// callers: [qsmmuv500_iova_to_phys_hard, __arm_tbu_micro_idle_cfg, arm_smmu_power_off, arm_smmu_set_secure_vmid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_get_dma_attr @ 0011e228 size=1
// signature: undefined device_get_dma_attr(void)
// callers: [arm_smmu_capable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_dma_attr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0011e238 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qsmmuv500_device_group, arm_smmu_domain_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_find_device @ 0011e248 size=1
// signature: undefined driver_find_device(void)
// callers: [arm_smmu_probe_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_find_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 0011e250 size=1
// signature: undefined put_device(void)
// callers: [arm_smmu_probe_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_fwspec_free @ 0011e258 size=1
// signature: undefined iommu_fwspec_free(void)
// callers: [arm_smmu_probe_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_fwspec_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_link_add @ 0011e260 size=1
// signature: undefined device_link_add(void)
// callers: [arm_smmu_probe_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_link_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0011e268 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [__bus_lookup_iommu_group, arm_smmu_attach_dev, qcom_def_domain_type, arm_smmu_master_alloc_smes, arm_smmu_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_for_each_dev @ 0011e278 size=1
// signature: undefined bus_for_each_dev(void)
// callers: [arm_smmu_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_for_each_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_ref_get @ 0011e288 size=1
// signature: undefined iommu_group_ref_get(void)
// callers: [arm_smmu_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_ref_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// generic_device_group @ 0011e290 size=1
// signature: undefined generic_device_group(void)
// callers: [arm_smmu_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void generic_device_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_device_group @ 0011e298 size=1
// signature: undefined pci_device_group(void)
// callers: [arm_smmu_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_device_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_alloc_resv_region @ 0011e2a0 size=1
// signature: undefined iommu_alloc_resv_region(void)
// callers: [arm_smmu_get_resv_regions]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_alloc_resv_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0011e2a8 size=1
// signature: undefined __list_add_valid(void)
// callers: [arm_smmu_get_resv_regions, qsmmuv500_tbu_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_dma_get_resv_regions @ 0011e2b0 size=1
// signature: undefined iommu_dma_get_resv_regions(void)
// callers: [arm_smmu_get_resv_regions]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_dma_get_resv_regions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_iommu_generate_resv_regions @ 0011e2b8 size=1
// signature: undefined qcom_iommu_generate_resv_regions(void)
// callers: [arm_smmu_get_resv_regions]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_iommu_generate_resv_regions(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_fwspec_add_ids @ 0011e2c0 size=1
// signature: undefined iommu_fwspec_add_ids(void)
// callers: [arm_smmu_of_xlate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_fwspec_add_ids(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0011e2c8 size=1
// signature: undefined of_property_read_string(void)
// callers: [arm_smmu_attach_dev, qcom_def_domain_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0011e2d0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [arm_smmu_attach_dev, qcom_def_domain_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 0011e2d8 size=1
// signature: undefined of_property_match_string(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0011e2e0 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 0011e2e8 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_iommu_get_fast_iova_range @ 0011e2f0 size=1
// signature: undefined qcom_iommu_get_fast_iova_range(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_iommu_get_fast_iova_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_zero_bit @ 0011e2f8 size=1
// signature: undefined _find_next_zero_bit(void)
// callers: [qcom_adreno_smmu_alloc_context_bank, arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_zero_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_alloc_io_pgtable_ops @ 0011e300 size=1
// signature: undefined qcom_alloc_io_pgtable_ops(void)
// callers: [arm_smmu_pm_restore_early, arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_alloc_io_pgtable_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_logger_register @ 0011e308 size=1
// signature: undefined iommu_logger_register(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_logger_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fast_smmu_init_mapping @ 0011e310 size=1
// signature: undefined fast_smmu_init_mapping(void)
// callers: [arm_smmu_attach_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fast_smmu_init_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_logger_unregister @ 0011e318 size=1
// signature: undefined iommu_logger_unregister(void)
// callers: [arm_smmu_attach_dev, arm_smmu_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_logger_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_free_io_pgtable_ops @ 0011e320 size=1
// signature: undefined qcom_free_io_pgtable_ops(void)
// callers: [arm_smmu_attach_dev, arm_smmu_pm_freeze_late, arm_smmu_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_free_io_pgtable_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_io_pgtable_free_page @ 0011e328 size=1
// signature: undefined qcom_io_pgtable_free_page(void)
// callers: [arm_smmu_qcom_tlb_sync, arm_smmu_flush_iotlb_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_io_pgtable_free_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fast_smmu_put_dma_cookie @ 0011e330 size=1
// signature: undefined fast_smmu_put_dma_cookie(void)
// callers: [arm_smmu_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fast_smmu_put_dma_cookie(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 0011e338 size=1
// signature: undefined devm_free_irq(void)
// callers: [arm_smmu_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0011e340 size=1
// signature: undefined __const_udelay(void)
// callers: [__arm_smmu_iova_to_phys_hard, __arm_tbu_micro_idle_cfg, qsmmuv2_iova_to_phys_hard]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// report_iommu_fault @ 0011e348 size=1
// signature: undefined report_iommu_fault(void)
// callers: [arm_smmu_context_fault]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void report_iommu_fault(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udelay @ 0011e350 size=1
// signature: undefined __udelay(void)
// callers: [nvidia_smmu_tlb_sync, qcom_smmu_tlb_sync, __arm_smmu_tlb_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 0011e368 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [nvidia_smmu_init_context, qsmmuv500_impl_init, qsmmuv500_tbu_probe, arm_smmu_pm_prepare, qcom_smmu_impl_init, qsmmuv2_impl_init, qcom_smmu_cfg_probe, qsmmuv500_tbu_register, arm_smmu_impl_init, qcom_smmu500_reset, qcom_adreno_smmu_init_context]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_unprepare @ 0011e378 size=1
// signature: undefined clk_bulk_unprepare(void)
// callers: [arm_smmu_pm_resume, arm_smmu_pm_restore_early, arm_smmu_pm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_bulk_prepare @ 0011e380 size=1
// signature: undefined clk_bulk_prepare(void)
// callers: [arm_smmu_pm_resume, arm_smmu_pm_restore_early]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_bulk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_krealloc @ 0011e3a8 size=1
// signature: undefined devm_krealloc(void)
// callers: [qsmmuv500_impl_init, qsmmuv500_tbu_probe, qcom_smmu_impl_init, qsmmuv500_create, nvidia_smmu_impl_init, arm_smmu_impl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_tegra_memory_controller_get @ 0011e3b0 size=1
// signature: undefined devm_tegra_memory_controller_get(void)
// callers: [nvidia_smmu_impl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_tegra_memory_controller_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0011e3b8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qsmmuv500_tbu_probe, nvidia_smmu_impl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tegra_mc_probe_device @ 0011e3c0 size=1
// signature: undefined tegra_mc_probe_device(void)
// callers: [nvidia_smmu_probe_finalize]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tegra_mc_probe_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 0011e3c8 size=1
// signature: undefined dev_driver_string(void)
// callers: [__arm_tbu_micro_idle_cfg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 0011e3d0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qsmmuv500_tbu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0011e3d8 size=1
// signature: undefined devm_ioremap(void)
// callers: [qsmmuv500_tbu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0011e3e0 size=1
// signature: undefined _dev_info(void)
// callers: [arm_smmu_debug_dump_tbu_testbus, qsmmuv500_tbu_probe, arm_smmu_debug_dump_debugchain, arm_smmu_debug_capture_bus_match, arm_smmu_debug_dump_tcu_testbus, arm_smmu_debug_dump_qtb_regs, arm_smmu_debug_program_tcu_testbus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 0011e3e8 size=1
// signature: undefined of_platform_populate(void)
// callers: [qsmmuv500_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 0011e3f0 size=1
// signature: undefined device_for_each_child(void)
// callers: [qsmmuv500_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 0011e3f8 size=1
// signature: undefined mutex_trylock(void)
// callers: [arm_smmu_debug_capture_bus_match, qsmmuv500_log_outstanding_transactions]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_is_available @ 0011e400 size=1
// signature: undefined qcom_scm_is_available(void)
// callers: [qcom_smmu_impl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 0011e408 size=1
// signature: undefined of_match_node(void)
// callers: [qcom_smmu_impl_init, qcom_adreno_smmu_init_context]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0011e410 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qsmmuv2_impl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_get_iommudata @ 0011e418 size=1
// signature: undefined iommu_group_get_iommudata(void)
// callers: [qsmmuv500_device_group, qsmmuv500_init_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_get_iommudata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 0011e420 size=1
// signature: undefined qcom_scm_io_readl(void)
// callers: [qsmmuv500_tlb_sync_timeout, arm_smmu_debug_tcu_testbus_select, arm_smmu_debug_dump_tcu_testbus, arm_smmu_debug_program_tcu_testbus, arm_smmu_debug_tcu_testbus_output]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_readl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0011e430 size=1
// signature: undefined queue_work_on(void)
// callers: [qsmmuv500_tlb_sync_timeout]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0011e438 size=1
// signature: undefined cancel_work_sync(void)
// callers: [qsmmuv500_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_group_set_iommudata @ 0011e440 size=1
// signature: undefined iommu_group_set_iommudata(void)
// callers: [qsmmuv500_device_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_group_set_iommudata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_qsmmu500_wait_safe_toggle @ 0011e448 size=1
// signature: undefined qcom_scm_qsmmu500_wait_safe_toggle(void)
// callers: [qcom_smmu500_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_qsmmu500_wait_safe_toggle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 0011e450 size=1
// signature: undefined of_match_device(void)
// callers: [qcom_smmu_def_domain_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0011e458 size=1
// signature: undefined icc_set_bw(void)
// callers: [arm_smmu_power_on, arm_smmu_power_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0011e460 size=1
// signature: undefined regulator_enable(void)
// callers: [arm_smmu_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0011e468 size=1
// signature: undefined clk_prepare(void)
// callers: [arm_smmu_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0011e470 size=1
// signature: undefined clk_unprepare(void)
// callers: [arm_smmu_power_on, arm_smmu_power_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_bulk_disable @ 0011e478 size=1
// signature: undefined regulator_bulk_disable(void)
// callers: [arm_smmu_power_on, arm_smmu_power_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_bulk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0011e480 size=1
// signature: undefined regulator_disable(void)
// callers: [arm_smmu_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0011e488 size=1
// signature: undefined clk_disable(void)
// callers: [arm_smmu_power_on, arm_smmu_power_off, arm_smmu_enable_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0011e490 size=1
// signature: undefined clk_enable(void)
// callers: [arm_smmu_enable_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0011e498 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_prop_next_string @ 0011e4a0 size=1
// signature: undefined of_prop_next_string(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_prop_next_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0011e4a8 size=1
// signature: undefined devm_clk_get(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 0011e4b0 size=1
// signature: undefined clk_get_rate(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_round_rate @ 0011e4b8 size=1
// signature: undefined clk_round_rate(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_round_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 0011e4c0 size=1
// signature: undefined clk_set_rate(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_bulk_get @ 0011e4c8 size=1
// signature: undefined devm_regulator_bulk_get(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_bulk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_icc_get @ 0011e4d0 size=1
// signature: undefined devm_of_icc_get(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_tag @ 0011e4d8 size=1
// signature: undefined icc_set_tag(void)
// callers: [arm_smmu_init_power_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_tag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 0011e4e0 size=1
// signature: undefined qcom_scm_io_writel(void)
// callers: [arm_smmu_debug_tcu_testbus_select, arm_smmu_debug_program_tcu_testbus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_io_writel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



