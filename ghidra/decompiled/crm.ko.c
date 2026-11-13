// Decompiled by Ghidra 12.2
// Program: crm.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_crm_cache_vcd_votes @ 00100a7c size=148
// signature: undefined __traceiter_crm_cache_vcd_votes(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_crm_cache_vcd_votes
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_001044b0;
  plVar2 = DAT_001044b0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x353e8bbc) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100ae8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_crm_write_vcd_votes @ 00100b14 size=148
// signature: undefined __traceiter_crm_write_vcd_votes(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_crm_write_vcd_votes
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001044f8;
  plVar2 = _DAT_001044f8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x353e8bbc) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100b80);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_crm_irq @ 00100bac size=140
// signature: undefined __traceiter_crm_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_crm_irq(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                   undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00104540;
  plVar2 = _DAT_00104540;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x284a242d) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100c10);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_crm_switch_channel @ 00100c3c size=124
// signature: undefined __traceiter_crm_switch_channel(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_crm_switch_channel
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00104588;
  plVar2 = _DAT_00104588;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x53dbb43a) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100c94);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_crm_vcd_votes @ 00100cbc size=272
// signature: undefined trace_event_raw_event_crm_vcd_votes(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_crm_vcd_votes
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x1c);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x1c;
      strcpy((char *)(lVar3 + 0x1c),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_crm_vcd_votes @ 00100dd0 size=348
// signature: undefined perf_trace_crm_vcd_votes(void)
// callers: []
//------------------------------------------------------------

void perf_trace_crm_vcd_votes
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [8];
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  local_78 = param_6;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x24;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x1001c;
      strcpy((char *)(lVar5 + 0x1c),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_78;
      perf_trace_run_bpf_submit(lVar5,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_crm_irq @ 00100f30 size=260
// signature: undefined trace_event_raw_event_crm_irq(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_crm_irq
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined8 param_5)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x20);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x20;
      strcpy((char *)(lVar3 + 0x20),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined8 *)(lVar3 + 0x18) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_crm_irq @ 00101038 size=348
// signature: undefined perf_trace_crm_irq(void)
// callers: []
//------------------------------------------------------------

void perf_trace_crm_irq(long param_1,char *param_2,undefined4 param_3,undefined4 param_4,
                       undefined8 param_5)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x2cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10020;
      strcpy((char *)(lVar5 + 0x20),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined8 *)(lVar5 + 0x18) = param_5;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_crm_switch_channel @ 00101198 size=252
// signature: undefined trace_event_raw_event_crm_switch_channel(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_crm_switch_channel
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x14);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x14;
      strcpy((char *)(lVar3 + 0x14),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_crm_switch_channel @ 00101298 size=336
// signature: undefined perf_trace_crm_switch_channel(void)
// callers: []
//------------------------------------------------------------

void perf_trace_crm_switch_channel(long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x1c;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x10014;
      strcpy((char *)(lVar5 + 0x14),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      perf_trace_run_bpf_submit(lVar5,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_crm_vcd_votes @ 001013ec size=44
// signature: undefined __bpf_trace_crm_vcd_votes(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_crm_vcd_votes
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_crm_irq @ 0010141c size=36
// signature: undefined __bpf_trace_crm_irq(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_crm_irq(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  bpf_trace_run4(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_crm_switch_channel @ 00101444 size=36
// signature: undefined __bpf_trace_crm_switch_channel(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_crm_switch_channel
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// crm_channel_switch_complete @ 0010146c size=200
// signature: undefined crm_channel_switch_complete(void)
// callers: [crm_switch_channel, crm_write_pwr_states]
//------------------------------------------------------------

undefined4 crm_channel_switch_complete(long param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar3 = 1;
  if ((int)param_2 != 0) {
    uVar3 = 2;
  }
  iVar1 = -99;
  do {
    iVar4 = iVar1;
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) +
                          (ulong)(uint)(*(int *)(*(long *)(param_1 + 0x28) + 0x30) +
                                       *(int *)(*(long *)(param_1 + 0x28) + 0x3c) *
                                       *(int *)(param_1 + 0x20)));
    __const_udelay(0x68dbc);
    iVar1 = iVar4 + 1;
  } while (1L << (param_2 & 0x3f) != (ulong)(uVar2 & uVar3) && iVar4 != 0);
  uVar5 = 0;
  if (iVar4 == 0) {
    uVar5 = 0xfffffff0;
  }
  ipc_log_string(param_1 + 4,*(undefined8 *)(param_1 + 0x90),"Switch Channel: ch: %u ret: %d",
                 param_2 & 0xffffffff,uVar5);
  return uVar5;
}



//------------------------------------------------------------
// crm_switch_channel @ 001015dc size=92
// signature: undefined crm_switch_channel(void)
// callers: []
//------------------------------------------------------------

void crm_switch_channel(long param_1,ulong param_2)

{
  writel_relaxed(1L << (param_2 & 0x3f),
                 *(long *)(param_1 + 0x18) +
                 (ulong)(uint)(*(int *)(*(long *)(param_1 + 0x28) + 0x34) +
                              *(int *)(*(long *)(param_1 + 0x28) + 0x3c) * *(int *)(param_1 + 0x20))
                );
  crm_channel_switch_complete(param_1,param_2 & 0xffffffff);
  return;
}



//------------------------------------------------------------
// crm_write_pwr_states @ 0010163c size=756
// signature: undefined crm_write_pwr_states(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_write_pwr_states(long param_1,uint param_2)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  int *piVar7;
  ulong uVar8;
  int *piVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  int *piVar13;
  ulong uVar14;
  long *plVar15;
  uint *puVar16;
  uint uVar17;
  uint uVar18;
  ulong uVar19;
  uint *puVar20;
  uint local_74;
  
  if ((param_1 == 0) || (*(uint *)(*(long *)(param_1 + 0x98) + 0x28) <= param_2)) {
    return 0xffffffea;
  }
  lVar6 = *(long *)(*(long *)(param_1 + 0x98) + 0x20);
  piVar13 = (int *)(lVar6 + (ulong)param_2 * 0x98);
  if (piVar13 == (int *)0x0) {
    return 0xffffffea;
  }
  if (*piVar13 == 1) {
    return 0xffffffea;
  }
  uVar8 = (ulong)param_2;
  lVar11 = lVar6 + uVar8 * 0x98;
  lVar1 = lVar11 + 0x84;
  _raw_spin_lock(lVar1);
  if (*(int *)(lVar11 + 0x24) == 0) {
LAB_001019c8:
    _raw_spin_unlock(lVar1);
  }
  else {
    lVar12 = lVar6 + uVar8 * 0x98;
    lVar11 = *(long *)(lVar12 + 0x28);
    piVar9 = (int *)(lVar12 + 0x20);
    plVar10 = (long *)(lVar12 + 0x18);
    local_74 = readl_relaxed(*plVar10 +
                             (ulong)(uint)(*(int *)(lVar11 + 0x34) +
                                          *(int *)(lVar11 + 0x3c) * *piVar9));
    if (local_74 == 0) {
      local_74 = 0;
    }
    else {
      if ((local_74 & 3) == 0) goto LAB_001019c8;
      local_74 = local_74 & 1;
    }
    uVar14 = 0;
    uVar2 = sp_el0;
    do {
      lVar11 = lVar6 + uVar8 * 0x98 + uVar14 * 0x28;
      puVar16 = (uint *)(lVar11 + 0x3c);
      uVar18 = *puVar16;
      if (uVar18 != 0) {
        uVar17 = 0;
        plVar15 = (long *)(lVar11 + 0x30);
        lVar11 = lVar6 + uVar8 * 0x98 + uVar14 * 0x28;
        puVar20 = (uint *)(lVar11 + 0x38);
        uVar5 = *puVar20;
        do {
          if (uVar5 != 0) {
            uVar19 = 0;
            do {
              uVar18 = (uint)uVar19;
              if (4 < uVar18) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x800,0x101804);
                (*pcVar3)();
              }
              piVar7 = *(int **)(lVar11 + 0x40);
              writel_relaxed(*(undefined4 *)
                              (*(long *)(*plVar15 + (long)(int)uVar17 * 8) +
                              (-(uVar19 >> 0x1f) & 0xfffffffc00000000 | uVar19 << 2)),
                             *plVar10 +
                             (ulong)(*piVar7 + piVar7[1] * *piVar9 + piVar7[uVar19 + 3] +
                                     *puVar16 * local_74 * piVar7[8] + piVar7[2] * uVar17));
              ipc_log_string(*(undefined8 *)(lVar6 + uVar8 * 0x98 + 0x90),
                             "Flush: type: %u resource_idx:%u pwr_state: %u data: %#x",
                             uVar14 & 0xffffffff,uVar17,uVar19,
                             *(undefined4 *)
                              (*(long *)(*plVar15 + (long)(int)uVar17 * 8) + (long)(int)uVar18 * 4))
              ;
              uVar5 = *puVar20;
              uVar19 = (ulong)(uVar18 + 1);
            } while (uVar18 + 1 < uVar5);
            uVar18 = *puVar16;
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < uVar18);
      }
      uVar14 = uVar14 + 1;
    } while (uVar14 != 2);
    lVar6 = *(long *)(lVar12 + 0x28);
    writel_relaxed(1 << (ulong)local_74,
                   *plVar10 +
                   (ulong)(uint)(*(int *)(lVar6 + 0x34) + *(int *)(lVar6 + 0x3c) * *piVar9));
    iVar4 = crm_channel_switch_complete(piVar13,local_74);
    _raw_spin_unlock(lVar1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  _crm_dump_drv_regs(piVar13);
  _crm_dump_regs(param_1);
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1019e4);
  (*pcVar3)();
}



//------------------------------------------------------------
// _crm_dump_drv_regs @ 001019e4 size=976
// signature: undefined _crm_dump_drv_regs(void)
// callers: [crm_write_pwr_states, crm_dump_drv_regs]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _crm_dump_drv_regs(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  undefined8 uVar9;
  uint uVar10;
  
  iVar3 = vmalloc_to_page(*(undefined8 *)(param_1 + 0x18));
  uVar10 = _memstart_addr;
  _printk(&DAT_00104760,&DAT_00104cc0,*(undefined4 *)(param_1 + 0x20));
  _raw_spin_lock(param_1 + 0x84);
  if (*(int *)(param_1 + 0x24) == 0) {
LAB_00101a7c:
    uVar9 = 0xfffffff0;
  }
  else {
    uVar4 = readl_relaxed(*(long *)(param_1 + 0x18) +
                          (ulong)(uint)(*(int *)(*(long *)(param_1 + 0x28) + 0x34) +
                                       *(int *)(*(long *)(param_1 + 0x28) + 0x3c) *
                                       *(int *)(param_1 + 0x20)));
    if (uVar4 == 0) {
      uVar4 = 0;
    }
    else {
      if ((uVar4 & 3) == 0) goto LAB_00101a7c;
      uVar4 = (uint)((uVar4 & 1) == 0);
    }
    uVar6 = *(uint *)(param_1 + 0x3c);
    iVar3 = (iVar3 + (uVar10 >> 0xc) * 0x40) * 0x40;
    if (uVar6 != 0) {
      uVar10 = 0;
      uVar8 = *(uint *)(param_1 + 0x38);
      do {
        if (uVar8 != 0) {
          uVar6 = 3;
          do {
            if (4 < uVar6 - 3) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101c54);
              (*pcVar2)();
            }
            piVar7 = *(int **)(param_1 + 0x40);
            uVar8 = *piVar7 + piVar7[1] * *(int *)(param_1 + 0x20) + piVar7[uVar6] +
                    *(int *)(param_1 + 0x3c) * uVar4 * piVar7[8] + piVar7[2] * uVar10;
            uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)uVar8);
            _printk(&DAT_00104896,&DAT_00104cc0,*(undefined4 *)(param_1 + 0x20),uVar4,&DAT_00104975,
                    uVar10,uVar6 - 3,uVar8 + iVar3,uVar5);
            uVar8 = *(uint *)(param_1 + 0x38);
            uVar1 = uVar6 - 2;
            uVar6 = uVar6 + 1;
          } while (uVar1 < uVar8);
          uVar6 = *(uint *)(param_1 + 0x3c);
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar6);
    }
    uVar10 = *(uint *)(param_1 + 100);
    if (uVar10 != 0) {
      uVar6 = 0;
      uVar8 = *(uint *)(param_1 + 0x60);
      do {
        if (uVar8 != 0) {
          uVar10 = 3;
          do {
            if (4 < uVar10 - 3) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101d2c);
              (*pcVar2)();
            }
            piVar7 = *(int **)(param_1 + 0x68);
            uVar8 = *piVar7 + piVar7[1] * *(int *)(param_1 + 0x20) + piVar7[uVar10] +
                    *(int *)(param_1 + 100) * uVar4 * piVar7[8] + piVar7[2] * uVar6;
            uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)uVar8);
            _printk(&DAT_00104896,&DAT_00104cc0,*(undefined4 *)(param_1 + 0x20),uVar4,&DAT_00104a5c,
                    uVar6,uVar10 - 3,uVar8 + iVar3,uVar5);
            uVar8 = *(uint *)(param_1 + 0x60);
            uVar1 = uVar10 - 2;
            uVar10 = uVar10 + 1;
          } while (uVar1 < uVar8);
          uVar10 = *(uint *)(param_1 + 100);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar10);
    }
    _printk(&DAT_001048e8,&DAT_00104cc0,*(undefined4 *)(param_1 + 0x20));
    if (*(int *)(param_1 + 0x3c) != 0) {
      uVar10 = 0;
      do {
        piVar7 = *(int **)(param_1 + 0x40);
        uVar4 = *piVar7 + piVar7[1] * *(int *)(param_1 + 0x20) + piVar7[9] + piVar7[2] * uVar10;
        uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)uVar4);
        _printk(&DAT_00104906,&DAT_00104cc0,uVar4 + iVar3,uVar5);
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(param_1 + 0x3c));
    }
    _printk(&DAT_00104841,&DAT_00104cc0,*(undefined4 *)(param_1 + 0x20));
    piVar7 = *(int **)(param_1 + 0x68);
    uVar10 = *piVar7 + piVar7[1] * *(int *)(param_1 + 0x20) + piVar7[10];
    uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)uVar10);
    _printk(&DAT_00104906,&DAT_00104cc0,uVar10 + iVar3,uVar5);
    uVar10 = *(int *)(*(long *)(param_1 + 0x28) + 0x30) +
             *(int *)(*(long *)(param_1 + 0x28) + 0x3c) * *(int *)(param_1 + 0x20);
    uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) + (ulong)uVar10);
    _printk(&DAT_00104906,&DAT_00104cc0,uVar10 + iVar3,uVar5);
    uVar9 = 0;
  }
  _raw_spin_unlock(param_1 + 0x84);
  return uVar9;
}



//------------------------------------------------------------
// _crm_dump_regs @ 00101db4 size=952
// signature: undefined _crm_dump_regs(void)
// callers: [crm_dump_regs, crm_write_pwr_states]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _crm_dump_regs(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  long lVar5;
  uint uVar6;
  
  lVar5 = *(long *)(param_1 + 0x98);
  _printk(&DAT_00104784,&DAT_00104cc0);
  iVar1 = vmalloc_to_page(*(undefined8 *)(lVar5 + 0x88));
  if (*(int *)(lVar5 + 0x90) != 0) {
    uVar6 = 0;
    iVar1 = (*(uint *)(lVar5 + 0x88) & 0xfff) + (iVar1 + (_memstart_addr >> 0xc) * 0x40) * 0x40;
    do {
      piVar4 = *(int **)(lVar5 + 0x98);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[7];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x88) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      piVar4 = *(int **)(lVar5 + 0x98);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[8];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x88) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(lVar5 + 0x90));
  }
  _printk(&DAT_00104794,&DAT_00104cc0);
  iVar1 = vmalloc_to_page(*(undefined8 *)(lVar5 + 0xb8));
  iVar1 = (*(uint *)(lVar5 + 0xb8) & 0xfff) + (iVar1 + (_memstart_addr >> 0xc) * 0x40) * 0x40;
  if (*(int *)(lVar5 + 0xc0) == 0) {
    uVar3 = 0;
  }
  else {
    uVar6 = 0;
    do {
      piVar4 = *(int **)(lVar5 + 200);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[9];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0xb8) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      uVar3 = *(uint *)(lVar5 + 0xc0);
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar3);
  }
  if (*(int *)(lVar5 + 0x90) + uVar3 != 0) {
    uVar6 = 0;
    do {
      piVar4 = *(int **)(lVar5 + 200);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[10];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0xb8) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      piVar4 = *(int **)(lVar5 + 200);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[0xb];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0xb8) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)(*(int *)(lVar5 + 0x90) + *(int *)(lVar5 + 0xc0)));
  }
  _printk(&DAT_00104979,&DAT_00104cc0);
  iVar1 = vmalloc_to_page(*(undefined8 *)(lVar5 + 0x58));
  if (*(int *)(lVar5 + 0x60) != 0) {
    uVar6 = 0;
    iVar1 = (*(uint *)(lVar5 + 0x58) & 0xfff) + (iVar1 + (_memstart_addr >> 0xc) * 0x40) * 0x40;
    do {
      piVar4 = *(int **)(lVar5 + 0x68);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[2];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x58) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      piVar4 = *(int **)(lVar5 + 0x68);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[3];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x58) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      piVar4 = *(int **)(lVar5 + 0x68);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[4];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x58) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      piVar4 = *(int **)(lVar5 + 0x68);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[5];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x58) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      piVar4 = *(int **)(lVar5 + 0x68);
      uVar3 = *piVar4 + piVar4[1] * uVar6 + piVar4[6];
      uVar2 = readl_relaxed(*(long *)(lVar5 + 0x58) + (ulong)uVar3);
      _printk(&DAT_00104906,&DAT_00104cc0,uVar3 + iVar1,uVar2);
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(lVar5 + 0x60));
  }
  return;
}



//------------------------------------------------------------
// crm_dump_drv_regs @ 00102170 size=152
// signature: undefined crm_dump_drv_regs(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_dump_drv_regs(char *param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined **ppuVar4;
  
  ppuVar4 = &crm_dev_list;
  do {
    ppuVar4 = (undefined **)*ppuVar4;
    if (ppuVar4 == &crm_dev_list) goto LAB_001021f0;
    iVar1 = strcmp(param_1,(char *)(ppuVar4 + -0x1a));
  } while (iVar1 != 0);
  puVar3 = ppuVar4[3];
  uVar2 = 0xffffffea;
  if (((puVar3 < (undefined *)0xfffffffffffff001) && (puVar3 != (undefined *)0x0)) &&
     (param_2 < *(uint *)(*(long *)(puVar3 + 0x98) + 0x28))) {
    if (*(long *)(*(long *)(puVar3 + 0x98) + 0x20) + (ulong)param_2 * 0x98 == 0) {
LAB_001021f0:
      uVar2 = 0xffffffea;
    }
    else {
      uVar2 = _crm_dump_drv_regs();
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// crm_get_device @ 0010220c size=96
// signature: undefined crm_get_device(void)
// callers: []
//------------------------------------------------------------

undefined * crm_get_device(char *param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  ppuVar2 = &crm_dev_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &crm_dev_list) {
      return (undefined *)0xffffffffffffffed;
    }
    iVar1 = strcmp(param_1,(char *)(ppuVar2 + -0x1a));
  } while (iVar1 != 0);
  return ppuVar2[3];
}



//------------------------------------------------------------
// crm_dump_regs @ 00102270 size=112
// signature: undefined crm_dump_regs(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_dump_regs(char *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  
  ppuVar3 = &crm_dev_list;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &crm_dev_list) goto LAB_001022bc;
    iVar1 = strcmp(param_1,(char *)(ppuVar3 + -0x1a));
  } while (iVar1 != 0);
  if (ppuVar3[3] < (undefined *)0xfffffffffffff001) {
    _crm_dump_regs();
    uVar2 = 0;
  }
  else {
LAB_001022bc:
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// crm_read_curr_perf_ol @ 001022e4 size=180
// signature: undefined crm_read_curr_perf_ol(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_read_curr_perf_ol(char *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long lVar4;
  int *piVar5;
  undefined **ppuVar6;
  
  ppuVar6 = &crm_dev_list;
  do {
    ppuVar6 = (undefined **)*ppuVar6;
    if (ppuVar6 == &crm_dev_list) goto LAB_0010237c;
    iVar1 = strcmp(param_1,(char *)(ppuVar6 + -0x1a));
  } while (iVar1 != 0);
  if ((ppuVar6[3] < (undefined *)0xfffffffffffff001) &&
     (lVar4 = *(long *)(ppuVar6[3] + 0x98), param_2 < *(uint *)(lVar4 + 0xc0))) {
    piVar5 = *(int **)(lVar4 + 200);
    uVar2 = readl_relaxed(*(long *)(lVar4 + 0xb8) +
                          (ulong)(*piVar5 + piVar5[1] * param_2 + piVar5[10]));
    uVar3 = 0;
    *param_3 = uVar2;
  }
  else {
LAB_0010237c:
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// crm_write_perf_ol @ 0010239c size=252
// signature: undefined crm_write_perf_ol(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_write_perf_ol(long param_1,int param_2,uint param_3,uint *param_4)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
LAB_00102480:
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x98);
    if (param_2 == 1) {
      if (*(uint *)(lVar3 + 0x38) <= param_3) goto LAB_00102480;
      plVar1 = (long *)(lVar3 + 0x30);
    }
    else {
      if ((param_2 != 0) || (*(uint *)(lVar3 + 0x28) <= param_3)) goto LAB_00102480;
      plVar1 = (long *)(lVar3 + 0x20);
    }
    uVar2 = 0xffffffea;
    if (param_4 != (uint *)0x0) {
      uVar2 = 0xffffffea;
      lVar3 = *plVar1;
      lVar4 = lVar3 + (ulong)param_3 * 0x98;
      if ((((lVar4 != 0) && (*param_4 < *(uint *)(lVar3 + (ulong)param_3 * 0x98 + 0x38))) &&
          (param_4[1] < *(uint *)(lVar3 + (ulong)param_3 * 0x98 + 0x3c))) && (param_4[2] < 8)) {
        crm_cache_vcd_votes(lVar4,0,param_4);
        uVar2 = 0;
        if (param_2 == 1) {
          uVar2 = crm_send_cmd(lVar4,0,param_4);
        }
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// crm_cache_vcd_votes @ 00102498 size=160
// signature: undefined crm_cache_vcd_votes(void)
// callers: [crm_write_perf_ol, crm_write_bw_vote]
//------------------------------------------------------------

void crm_cache_vcd_votes(long param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  
  uVar3 = param_3[2];
  uVar1 = *param_3;
  uVar2 = param_3[1];
  lVar4 = param_1 + (ulong)param_2 * 0x28;
  _raw_spin_lock(param_1 + 0x84);
  *(uint *)(*(long *)(*(long *)(lVar4 + 0x30) + (ulong)uVar2 * 8) + (ulong)uVar1 * 4) = uVar3;
  *(undefined1 *)(lVar4 + 0x48) = 1;
  _raw_spin_unlock(param_1 + 0x84);
  ipc_log_string(param_1 + 4,*(undefined8 *)(param_1 + 0x90),
                 "Cache: type: %u resource_idx:%u pwr_state: %u data: %#x",param_2,(ulong)uVar2,
                 (ulong)uVar1,uVar3);
  return;
}



//------------------------------------------------------------
// crm_send_cmd @ 001025e4 size=760
// signature: undefined crm_send_cmd(void)
// callers: [crm_write_perf_ol, crm_write_bw_vote]
//------------------------------------------------------------

void crm_send_cmd(long param_1,uint param_2,int *param_3)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  uint uVar9;
  long lVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  long lVar16;
  ulong uVar17;
  long *plVar18;
  undefined4 *puVar19;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  lVar1 = param_1 + 0x80;
  local_68 = *(long *)(lVar10 + 0x638);
  uVar17 = (ulong)param_2;
  iVar7 = *param_3;
  uVar2 = param_3[1];
  uVar3 = (ulong)uVar2;
  uVar4 = param_3[2];
  iVar5 = param_3[3];
  uVar8 = _raw_spin_lock_irqsave(lVar1);
  uVar9 = 0xc0000000;
  if ((char)iVar5 == '\0') {
    uVar9 = 0x40000000;
  }
  if (param_2 != 1) {
    uVar9 = 0;
  }
  uVar9 = uVar9 | uVar4;
  if (iVar7 == 2) {
    iVar12 = *(int *)(param_1 + 0x20);
    piVar11 = *(int **)(param_1 + uVar17 * 0x28 + 0x40);
    iVar13 = *piVar11;
    iVar14 = piVar11[1];
    iVar15 = piVar11[5];
  }
  else {
    if (iVar7 != 1) {
      if (iVar7 != 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x102760);
        (*pcVar6)();
      }
      plVar18 = (long *)(param_1 + uVar17 * 0x28 + 0x50);
      lVar10 = *plVar18;
      if (*(char *)(lVar10 + uVar3 * 0x50 + 0x30) != '\0') {
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_90 = 0;
        init_wait_entry(&local_90,0);
        while( true ) {
          prepare_to_wait_event(*plVar18 + uVar3 * 0x50 + 0x38,&local_90,2);
          if (*(char *)(*plVar18 + uVar3 * 0x50 + 0x30) == '\0') break;
          _raw_spin_unlock_irq(lVar1);
          schedule();
          _raw_spin_lock_irq(lVar1);
        }
        finish_wait(*plVar18 + uVar3 * 0x50 + 0x38,&local_90);
        lVar10 = *plVar18;
      }
      lVar16 = uVar3 * 0x50;
      puVar19 = (undefined4 *)(lVar10 + lVar16 + 0x10);
      *puVar19 = 0;
      __init_swait_queue_head(lVar10 + lVar16 + 0x18,"&x->wait",&init_completion___key);
      piVar11 = (int *)(*plVar18 + lVar16);
      piVar11[1] = param_3[1];
      *piVar11 = *param_3;
      piVar11[2] = param_3[2];
      *(char *)(piVar11 + 3) = (char)param_3[3];
      *(undefined1 *)(*plVar18 + lVar16 + 0x30) = 1;
      piVar11 = *(int **)(param_1 + uVar17 * 0x28 + 0x40);
      writel_relaxed(uVar9,*(long *)(param_1 + 0x18) +
                           (ulong)(*piVar11 + piVar11[1] * *(int *)(param_1 + 0x20) + piVar11[3] +
                                  piVar11[2] * uVar2));
      goto LAB_0010281c;
    }
    iVar12 = *(int *)(param_1 + 0x20);
    piVar11 = *(int **)(param_1 + uVar17 * 0x28 + 0x40);
    iVar13 = *piVar11;
    iVar14 = piVar11[1];
    iVar15 = piVar11[4];
  }
  writel_relaxed(uVar9,*(long *)(param_1 + 0x18) +
                       (ulong)(iVar13 + iVar14 * iVar12 + iVar15 + piVar11[2] * uVar2));
  puVar19 = (undefined4 *)0x0;
LAB_0010281c:
  _raw_spin_unlock_irqrestore(lVar1,uVar8);
  ipc_log_string(*(undefined8 *)(param_1 + 0x90),
                 "Write: type: %u resource_idx:%u pwr_state: %u data: %#x",param_2,uVar3,iVar7,uVar9
                );
  if (((char)iVar5 != '\0') && (puVar19 != (undefined4 *)0x0)) {
    iVar7 = wait_for_completion_timeout(puVar19,5000);
    if (iVar7 == 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1028a4);
      (*pcVar6)();
    }
    __wake_up(*(long *)(param_1 + uVar17 * 0x28 + 0x50) + uVar3 * 0x50 + 0x38,3,1,0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



//------------------------------------------------------------
// crm_write_bw_vote @ 0010298c size=252
// signature: undefined crm_write_bw_vote(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_write_bw_vote(long param_1,int param_2,uint param_3,uint *param_4)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if (param_1 == 0) {
LAB_00102a68:
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x98);
    if (param_2 == 1) {
      if (*(uint *)(lVar3 + 0x38) <= param_3) goto LAB_00102a68;
      plVar1 = (long *)(lVar3 + 0x30);
    }
    else {
      if ((param_2 != 0) || (*(uint *)(lVar3 + 0x28) <= param_3)) goto LAB_00102a68;
      plVar1 = (long *)(lVar3 + 0x20);
    }
    uVar2 = 0xffffffea;
    if (param_4 != (uint *)0x0) {
      uVar2 = 0xffffffea;
      lVar3 = *plVar1;
      lVar4 = lVar3 + (ulong)param_3 * 0x98;
      if ((((lVar4 != 0) && (*param_4 < *(uint *)(lVar3 + (ulong)param_3 * 0x98 + 0x60))) &&
          (param_4[1] < *(uint *)(lVar3 + (ulong)param_3 * 0x98 + 100))) &&
         ((param_4[2] >> 0x1d & 1) != 0)) {
        crm_cache_vcd_votes(lVar4,1,param_4);
        if (param_2 == 1) {
          uVar2 = crm_send_cmd(lVar4,1,param_4);
        }
        else {
          uVar2 = 0;
        }
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// trace_raw_output_crm_vcd_votes @ 00102a8c size=112
// signature: undefined trace_raw_output_crm_vcd_votes(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_crm_vcd_votes(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: vcd_type: %u resource_idx: %u pwr_state: %u data: %#x\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_crm_irq @ 00102b00 size=112
// signature: undefined trace_raw_output_crm_irq(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_crm_irq(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: IRQ vcd_type: %u resource_idx: %u irq_status: %lu\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined8 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_crm_switch_channel @ 00102b74 size=108
// signature: undefined trace_raw_output_crm_switch_channel(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_crm_switch_channel(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: channel switched to: %d ret: %d\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00102be0 size=124
// signature: undefined readl_relaxed(void)
// callers: [_crm_dump_drv_regs, crm_channel_switch_complete, crm_read_curr_perf_ol, crm_probe, crm_write_pwr_states, _crm_dump_regs, crm_vote_complete_irq]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102c28,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00102c5c size=132
// signature: undefined writel_relaxed(void)
// callers: [crm_set_chn_behave, crm_probe, crm_send_cmd, crm_switch_channel, crm_write_pwr_states, crm_vote_complete_irq]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102c74,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102cb0,uVar1);
  return;
}



//------------------------------------------------------------
// crm_probe @ 00102ce4 size=2188
// signature: undefined crm_probe(void)
// callers: []
//------------------------------------------------------------

void crm_probe(long param_1)

{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  long lVar10;
  int *piVar11;
  long lVar12;
  char *pcVar13;
  long lVar14;
  long lVar15;
  long *plVar16;
  undefined8 uVar17;
  uint *puVar18;
  uint uVar19;
  undefined4 *puVar20;
  uint local_80;
  long local_70;
  long local_68;
  
  lVar7 = sp_el0;
  plVar16 = (long *)(param_1 + 0x10);
  local_68 = *(long *)(lVar7 + 0x638);
  uVar17 = *(undefined8 *)(param_1 + 0x2f8);
  lVar7 = devm_kmalloc(plVar16,0xf8,0xdc0);
  if (lVar7 == 0) goto LAB_00102e6c;
  lVar8 = of_device_get_match_data(plVar16);
  *(long *)(lVar7 + 0xe0) = lVar8;
  if (lVar8 == 0) {
LAB_00103008:
    uVar9 = 0xffffffea;
  }
  else {
    lVar8 = of_get_property(uVar17,"label",0);
    if ((lVar8 == 0) && (lVar8 = *(long *)(param_1 + 0x80), lVar8 == 0)) {
      lVar8 = *plVar16;
    }
    *(long **)(lVar7 + 0xe8) = plVar16;
    *(long *)(lVar7 + 0xf0) = param_1;
    scnprintf(lVar7,0x14,&DAT_001048d2,lVar8);
    local_70 = 0;
    uVar9 = devm_platform_get_and_ioremap_resource(param_1,0,0);
    *(ulong *)(lVar7 + 0x18) = uVar9;
    if (uVar9 < 0xfffffffffffff001) {
      uVar9 = devm_platform_get_and_ioremap_resource(param_1,1,&local_70);
      *(ulong *)(lVar7 + 0x88) = uVar9;
      if (uVar9 < 0xfffffffffffff001) {
        pcVar13 = *(char **)(local_70 + 0x10);
        uVar9 = strnlen(pcVar13,0x14);
        if (uVar9 == 0xffffffffffffffff) {
LAB_00103558:
          fortify_panic("strnlen");
LAB_00103564:
          lVar7 = fortify_panic("strscpy");
          if ((**(char **)(lVar7 + 0xe0) != '\0') && (0 < *(int *)(lVar7 + 0x28))) {
            lVar12 = 0;
            lVar8 = 0;
            do {
              lVar10 = *(long *)(lVar7 + 0x20) + lVar12;
              writel_relaxed(1,*(long *)(lVar10 + 0x18) +
                               (ulong)(uint)(*(int *)(*(long *)(lVar10 + 0x28) + 0x38) +
                                            *(int *)(*(long *)(lVar10 + 0x28) + 0x3c) *
                                            *(int *)(lVar10 + 0x20)));
              lVar8 = lVar8 + 1;
              lVar12 = lVar12 + 0x98;
            } while (lVar8 < *(int *)(lVar7 + 0x28));
          }
          return;
        }
        if (uVar9 != 0x14) {
          uVar9 = uVar9 + 1;
        }
        if (0x14 < uVar9) goto LAB_00103564;
        strscpy(lVar7 + 0x70,pcVar13);
        uVar9 = devm_platform_get_and_ioremap_resource(param_1,2,&local_70);
        *(ulong *)(lVar7 + 0xb8) = uVar9;
        if (0xfffffffffffff000 < uVar9) goto LAB_00102e6c;
        pcVar13 = *(char **)(local_70 + 0x10);
        uVar9 = strnlen(pcVar13,0x14);
        if (uVar9 == 0xffffffffffffffff) goto LAB_00103558;
        if (uVar9 != 0x14) {
          uVar9 = uVar9 + 1;
        }
        if (0x14 < uVar9) goto LAB_00103564;
        strscpy(lVar7 + 0xa0,pcVar13);
        uVar9 = devm_platform_get_and_ioremap_resource(param_1,3,&local_70);
        *(ulong *)(lVar7 + 0x58) = uVar9;
        if (0xfffffffffffff000 < uVar9) goto LAB_00102e6c;
        pcVar13 = *(char **)(local_70 + 0x10);
        uVar9 = strnlen(pcVar13,0x14);
        if (uVar9 == 0xffffffffffffffff) goto LAB_00103558;
        if (uVar9 != 0x14) {
          uVar9 = uVar9 + 1;
        }
        if (0x14 < uVar9) goto LAB_00103564;
        strscpy(lVar7 + 0x40,pcVar13);
        iVar4 = readl_relaxed(*(long *)(lVar7 + 0x18) + 0xc);
        if (iVar4 == 0) goto LAB_00103008;
        readl_relaxed(*(undefined8 *)(lVar7 + 0x18));
        uVar5 = readl_relaxed(*(long *)(lVar7 + 0x18) + 4);
        *(uint *)(lVar7 + 0x2c) = uVar5 >> 4 & 0xf;
        iVar4 = of_property_count_elems_of_size(uVar17,"qcom,hw-drv-ids",4);
        *(int *)(lVar7 + 0x28) = iVar4;
        if (iVar4 < 0) {
          *(undefined4 *)(lVar7 + 0x28) = 0;
LAB_00102f28:
          iVar4 = of_property_count_elems_of_size(uVar17,"qcom,sw-drv-ids",4);
          *(int *)(lVar7 + 0x38) = iVar4;
          if (iVar4 < 0) {
            iVar4 = 0;
            *(undefined4 *)(lVar7 + 0x38) = 0;
          }
          else {
            uVar9 = crm_probe_get_drvs(lVar7,iVar4,"qcom,sw-drv-ids","sw_drv");
            *(ulong *)(lVar7 + 0x30) = uVar9;
            if (0xfffffffffffff000 < uVar9) goto LAB_00102f6c;
            iVar4 = *(int *)(lVar7 + 0x38);
            if ((int)(uVar5 >> 0x14 & 0xf) < iVar4) goto LAB_00103008;
          }
          if (((int)(uVar5 >> 0x10 & 0xf) < *(int *)(lVar7 + 0x28)) ||
             (iVar4 == 0 && *(int *)(lVar7 + 0x28) == 0)) goto LAB_00103008;
          uVar6 = readl_relaxed(*(long *)(lVar7 + 0x18) + 8);
          iVar4 = *(int *)(lVar7 + 0x28);
          uVar19 = uVar5 >> 8 & 0xf;
          uVar6 = uVar6 >> 0x1a & 0x1f;
          if (0 < iVar4) {
            iVar2 = (uVar5 & 0xf) << 2;
            lVar8 = 0;
            local_80 = uVar5 & 0xf;
            do {
              lVar12 = *(long *)(lVar7 + 0x20);
              if (*(char *)(lVar12 + lVar8 * 0x98 + 0x8c) != '\0') {
                puVar20 = (undefined4 *)(lVar12 + lVar8 * 0x98);
                *puVar20 = 0;
                *(undefined1 **)(puVar20 + 0x10) = hw_drv_perf_ol_vcd_regs;
                puVar20[0xe] = local_80;
                puVar20[0xf] = uVar19;
                lVar10 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),uVar19 << 3,0xdc0);
                plVar16 = (long *)(puVar20 + 0xc);
                *plVar16 = lVar10;
                if (lVar10 == 0) goto LAB_00102e6c;
                if (uVar19 != 0) {
                  lVar10 = 0;
                  do {
                    uVar17 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),iVar2,0xdc0);
                    *(undefined8 *)(*plVar16 + lVar10) = uVar17;
                    if (*(long *)(*plVar16 + lVar10) == 0) goto LAB_00102e6c;
                    lVar10 = lVar10 + 8;
                  } while ((ulong)uVar19 * 8 != lVar10);
                }
                lVar12 = lVar12 + lVar8 * 0x98;
                *(undefined1 **)(lVar12 + 0x68) = hw_drv_bw_vote_vcd_regs;
                *(uint *)(lVar12 + 0x60) = local_80;
                *(uint *)(lVar12 + 100) = uVar6;
                lVar10 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),uVar6 << 3,0xdc0);
                plVar16 = (long *)(lVar12 + 0x58);
                *plVar16 = lVar10;
                if (lVar10 == 0) goto LAB_00102e6c;
                if (uVar6 != 0) {
                  lVar12 = 0;
                  do {
                    uVar17 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),iVar2,0xdc0);
                    *(undefined8 *)(*plVar16 + lVar12) = uVar17;
                    if (*(long *)(*plVar16 + lVar12) == 0) goto LAB_00102e6c;
                    lVar12 = lVar12 + 8;
                  } while ((ulong)uVar6 * 8 != lVar12);
                }
                iVar4 = *(int *)(lVar7 + 0x28);
              }
              lVar8 = lVar8 + 1;
            } while (lVar8 < iVar4);
          }
          iVar4 = *(int *)(lVar7 + 0x38);
          if (0 < iVar4) {
            lVar8 = 0;
            do {
              lVar12 = *(long *)(lVar7 + 0x30);
              if (*(char *)(lVar12 + lVar8 * 0x98 + 0x8c) != '\0') {
                puVar20 = (undefined4 *)(lVar12 + lVar8 * 0x98);
                *puVar20 = 1;
                *(undefined1 **)(puVar20 + 0x10) = sw_drv_perf_ol_vcd_regs;
                puVar20[0xe] = 3;
                puVar20[0xf] = uVar19;
                lVar10 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),uVar19 << 3,0xdc0);
                plVar16 = (long *)(puVar20 + 0xc);
                *plVar16 = lVar10;
                if (lVar10 == 0) goto LAB_00102e6c;
                if (uVar19 != 0) {
                  lVar10 = 0;
                  do {
                    uVar17 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),0xc,0xdc0);
                    *(undefined8 *)(*plVar16 + lVar10) = uVar17;
                    if (*(long *)(*plVar16 + lVar10) == 0) goto LAB_00102e6c;
                    lVar10 = lVar10 + 8;
                  } while ((ulong)uVar19 * 8 != lVar10);
                }
                lVar12 = lVar12 + lVar8 * 0x98;
                *(undefined1 **)(lVar12 + 0x68) = sw_drv_bw_vote_vcd_regs;
                *(undefined4 *)(lVar12 + 0x60) = 3;
                *(uint *)(lVar12 + 100) = uVar6;
                lVar10 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),uVar6 << 3,0xdc0);
                plVar16 = (long *)(lVar12 + 0x58);
                *plVar16 = lVar10;
                if (lVar10 == 0) goto LAB_00102e6c;
                if (uVar6 != 0) {
                  lVar12 = 0;
                  do {
                    uVar17 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),0xc,0xdc0);
                    *(undefined8 *)(*plVar16 + lVar12) = uVar17;
                    if (*(long *)(*plVar16 + lVar12) == 0) goto LAB_00102e6c;
                    lVar12 = lVar12 + 8;
                  } while ((ulong)uVar6 * 8 != lVar12);
                }
                iVar4 = *(int *)(lVar7 + 0x38);
              }
              lVar8 = lVar8 + 1;
            } while (lVar8 < iVar4);
          }
          *(uint *)(lVar7 + 0x60) = uVar5 >> 0xc & 0xf;
          *(undefined1 **)(lVar7 + 0x68) = crmv_regs;
          *(uint *)(lVar7 + 0x90) = uVar5 >> 0x18 & 0xf;
          *(undefined1 **)(lVar7 + 200) = crmc_regs;
          *(undefined1 **)(lVar7 + 0x98) = crmb_regs;
          *(uint *)(lVar7 + 0xc0) = uVar19;
        }
        else {
          uVar9 = crm_probe_get_drvs(lVar7,iVar4,"qcom,hw-drv-ids","hw_drv");
          *(ulong *)(lVar7 + 0x20) = uVar9;
          if (uVar9 < 0xfffffffffffff001) goto LAB_00102f28;
LAB_00102f6c:
          if ((int)uVar9 != 0) goto LAB_0010300c;
          iVar4 = *(int *)(lVar7 + 0x38);
        }
        if (iVar4 != 0) {
          lVar8 = *(long *)(lVar7 + 0x30);
          uVar5 = platform_get_irq_byname(*(undefined8 *)(lVar7 + 0xf0),lVar7);
          uVar9 = (ulong)uVar5;
          if (((int)uVar5 < 0) ||
             (uVar9 = devm_request_threaded_irq
                                (*(undefined8 *)(lVar7 + 0xe8),uVar9,crm_vote_complete_irq,0,1,lVar7
                                 ,lVar7), (int)uVar9 != 0)) goto LAB_0010300c;
          iVar4 = *(int *)(lVar7 + 0x38);
          if (0 < iVar4) {
            lVar12 = 0;
            do {
              if (*(char *)(*(long *)(lVar7 + 0x30) + lVar12 * 0x98 + 0x8c) != '\0') {
                lVar14 = lVar8 + lVar12 * 0x98;
                *(uint *)(lVar14 + 0x88) = uVar5;
                puVar18 = (uint *)(lVar14 + 0x3c);
                *(undefined4 *)(lVar14 + 0x24) = 0;
                lVar10 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),(ulong)*puVar18 * 0x50,0xdc0);
                *(long *)(lVar14 + 0x50) = lVar10;
                if (lVar10 == 0) goto LAB_00102e6c;
                if (*puVar18 != 0) {
                  uVar19 = 0;
                  do {
                    __init_waitqueue_head
                              (*(long *)(lVar14 + 0x50) + (long)(int)uVar19 * 0x50 + 0x38,
                               "&vcd->sw_votes[k].wait",&crm_probe_get_irqs___key);
                    piVar11 = *(int **)(lVar8 + lVar12 * 0x98 + 0x40);
                    writel_relaxed(1,*(long *)(lVar14 + 0x18) +
                                     (ulong)(*piVar11 + piVar11[1] * *(int *)(lVar14 + 0x20) +
                                             piVar11[0xb] + piVar11[2] * uVar19));
                    uVar19 = uVar19 + 1;
                  } while (uVar19 < *puVar18);
                }
                lVar15 = lVar8 + lVar12 * 0x98;
                puVar18 = (uint *)(lVar15 + 100);
                lVar10 = devm_kmalloc(*(undefined8 *)(lVar7 + 0xe8),(ulong)*puVar18 * 0x50,0xdc0);
                plVar16 = (long *)(lVar15 + 0x78);
                *plVar16 = lVar10;
                if (lVar10 == 0) goto LAB_00102e6c;
                if (*puVar18 != 0) {
                  uVar19 = 0;
                  do {
                    __init_waitqueue_head
                              (*plVar16 + (long)(int)uVar19 * 0x50 + 0x38,"&vcd->sw_votes[k].wait",
                               &crm_probe_get_irqs___key);
                    piVar11 = *(int **)(lVar8 + lVar12 * 0x98 + 0x68);
                    writel_relaxed(1,*(long *)(lVar14 + 0x18) +
                                     (ulong)(*piVar11 + piVar11[1] * *(int *)(lVar14 + 0x20) +
                                             piVar11[0xb] + piVar11[2] * uVar19));
                    uVar19 = uVar19 + 1;
                  } while (uVar19 < *puVar18);
                }
                iVar4 = *(int *)(lVar7 + 0x38);
              }
              lVar12 = lVar12 + 1;
            } while (lVar12 < iVar4);
          }
        }
        crm_set_chn_behave(lVar7);
        puVar1 = (undefined *)(lVar7 + 0xd0);
        *(undefined **)(lVar7 + 0xd0) = puVar1;
        *(undefined **)(lVar7 + 0xd8) = puVar1;
        puVar3 = PTR_crm_dev_list_00104200;
        uVar9 = __list_add_valid(puVar1,PTR_crm_dev_list_00104200,&crm_dev_list);
        if ((uVar9 & 1) != 0) {
          PTR_crm_dev_list_00104200 = puVar1;
          *(undefined ***)(lVar7 + 0xd0) = &crm_dev_list;
          *(undefined **)(lVar7 + 0xd8) = puVar3;
          *(undefined **)puVar3 = puVar1;
        }
        uVar9 = 0;
        *(long *)(param_1 + 0xa8) = lVar7;
        goto LAB_0010300c;
      }
    }
LAB_00102e6c:
    uVar9 = 0xfffffff4;
  }
LAB_0010300c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// crm_set_chn_behave @ 00103570 size=136
// signature: undefined crm_set_chn_behave(void)
// callers: [crm_probe]
//------------------------------------------------------------

void crm_set_chn_behave(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if ((**(char **)(param_1 + 0xe0) != '\0') && (0 < *(int *)(param_1 + 0x28))) {
    lVar2 = 0;
    lVar3 = 0;
    do {
      lVar1 = *(long *)(param_1 + 0x20) + lVar2;
      writel_relaxed(1,*(long *)(lVar1 + 0x18) +
                       (ulong)(uint)(*(int *)(*(long *)(lVar1 + 0x28) + 0x38) +
                                    *(int *)(*(long *)(lVar1 + 0x28) + 0x3c) *
                                    *(int *)(lVar1 + 0x20)));
      lVar3 = lVar3 + 1;
      lVar2 = lVar2 + 0x98;
    } while (lVar3 < *(int *)(param_1 + 0x28));
  }
  return;
}



//------------------------------------------------------------
// crm_probe_get_drvs @ 001035f8 size=372
// signature: undefined crm_probe_get_drvs(void)
// callers: [crm_probe]
//------------------------------------------------------------

long crm_probe_get_drvs(long param_1,uint param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 *puVar9;
  
  if (param_2 == 0) {
    lVar4 = -0x16;
  }
  else {
    uVar7 = *(undefined8 *)(*(long *)(param_1 + 0xe8) + 0x2e8);
    lVar4 = devm_kmalloc(*(long *)(param_1 + 0xe8),(ulong)param_2 * 0x98,0xdc0);
    if (lVar4 != 0) {
      uVar6 = (ulong)param_2 * 4;
      lVar5 = __kmalloc(uVar6,0xdc0);
      if (lVar5 != 0) {
        iVar3 = of_property_read_variable_u32_array(uVar7,param_3,lVar5,(ulong)param_2,0);
        if (iVar3 < 0) {
          kfree(lVar5);
          return (long)iVar3;
        }
        if (0 < (int)param_2) {
          uVar8 = 0;
          puVar9 = (undefined8 *)(lVar4 + 0x90);
          do {
            if (uVar6 <= uVar8) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(1,0x10376c);
              (*pcVar2)();
            }
            uVar1 = *(undefined4 *)(lVar5 + uVar8);
            scnprintf((long)puVar9 + -0x8c,0x14,"%s_%s_%d",param_1,param_4,uVar1);
            uVar7 = *(undefined8 *)(param_1 + 0x18);
            *(undefined4 *)(puVar9 + -0xe) = uVar1;
            puVar9[-0xf] = uVar7;
            puVar9[-2] = 0;
            uVar7 = ipc_log_context_create(2,(long)puVar9 + -0x8c,0);
            *puVar9 = uVar7;
            uVar8 = uVar8 + 4;
            puVar9[-0xd] = chn_regs;
            uVar1 = *(undefined4 *)(param_1 + 0x2c);
            *(undefined1 *)((long)puVar9 + -4) = 1;
            *(undefined4 *)((long)puVar9 + -0x6c) = uVar1;
            puVar9 = puVar9 + 0x13;
          } while (uVar6 != uVar8);
        }
        kfree(lVar5);
        return lVar4;
      }
    }
    lVar4 = -0xc;
  }
  return lVar4;
}



//------------------------------------------------------------
// crm_vote_complete_irq @ 00103770 size=492
// signature: undefined crm_vote_complete_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 crm_vote_complete_irq(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  char *pcVar7;
  long lVar8;
  long lVar9;
  uint *puVar10;
  long lVar11;
  ulong uVar12;
  uint uVar13;
  long lVar14;
  
  iVar4 = *(int *)(param_2 + 0x38);
  if (0 < iVar4) {
    lVar11 = 0;
    uVar2 = sp_el0;
    do {
      lVar14 = *(long *)(param_2 + 0x30);
      if (*(char *)(lVar14 + lVar11 * 0x98 + 0x8c) != '\0') {
        lVar9 = lVar14 + lVar11 * 0x98;
        _raw_spin_lock();
        uVar12 = 0;
        do {
          puVar10 = (uint *)(lVar14 + lVar11 * 0x98 + uVar12 * 0x28 + 0x3c);
          if (*puVar10 != 0) {
            uVar13 = 0;
            lVar5 = lVar14 + lVar11 * 0x98 + uVar12 * 0x28;
            puVar1 = (undefined8 *)(lVar5 + 0x40);
            do {
              piVar6 = (int *)*puVar1;
              iVar4 = readl_relaxed(*(long *)(lVar9 + 0x18) +
                                    (ulong)(*piVar6 + piVar6[1] * *(int *)(lVar9 + 0x20) + piVar6[9]
                                           + piVar6[2] * uVar13));
              if (iVar4 != 0) {
                piVar6 = (int *)*puVar1;
                writel_relaxed(1,*(long *)(lVar9 + 0x18) +
                                 (ulong)(*piVar6 + piVar6[1] * *(int *)(lVar9 + 0x20) + piVar6[10] +
                                        piVar6[2] * uVar13));
                ipc_log_string(*(undefined8 *)(lVar9 + 0x90),
                               "IRQ: type: %u resource_idx:%u irq_status: %lu",uVar12 & 0xffffffff,
                               uVar13,iVar4);
                lVar8 = *(long *)(lVar5 + 0x50);
                pcVar7 = (char *)(lVar8 + (long)(int)uVar13 * 0x50 + 0x30);
                if (*pcVar7 == '\0') {
                    /* WARNING: Does not return */
                  pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10386c);
                  (*pcVar3)();
                }
                if (*(char *)(lVar8 + (long)(int)uVar13 * 0x50 + 0xc) != '\0') {
                  *pcVar7 = '\0';
                  complete(lVar8 + (long)(int)uVar13 * 0x50 + 0x10);
                }
              }
              uVar13 = uVar13 + 1;
            } while (uVar13 < *puVar10);
          }
          uVar12 = uVar12 + 1;
        } while (uVar12 != 2);
        _raw_spin_unlock(lVar9 + 0x80);
        iVar4 = *(int *)(param_2 + 0x38);
      }
      lVar11 = lVar11 + 1;
    } while (lVar11 < iVar4);
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 00103ae4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&crm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103b14 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&crm_driver);
  return;
}



//------------------------------------------------------------
// strlen @ 00107000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_crm_irq, perf_trace_crm_irq, trace_event_raw_event_crm_switch_channel, perf_trace_crm_vcd_votes, trace_event_raw_event_crm_vcd_votes, perf_trace_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00107008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_crm_irq, trace_event_raw_event_crm_switch_channel, trace_event_raw_event_crm_vcd_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00107010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_crm_irq, perf_trace_crm_irq, trace_event_raw_event_crm_switch_channel, perf_trace_crm_vcd_votes, trace_event_raw_event_crm_vcd_votes, perf_trace_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00107018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_crm_irq, trace_event_raw_event_crm_switch_channel, trace_event_raw_event_crm_vcd_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00107020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_crm_irq, trace_event_raw_event_crm_switch_channel, trace_event_raw_event_crm_vcd_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00107028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_crm_irq, perf_trace_crm_irq, crm_probe, crm_send_cmd, trace_event_raw_event_crm_switch_channel, perf_trace_crm_vcd_votes, trace_event_raw_event_crm_vcd_votes, perf_trace_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00107030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_crm_irq, perf_trace_crm_vcd_votes, perf_trace_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00107038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_crm_irq, perf_trace_crm_vcd_votes, perf_trace_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 00107040 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_crm_vcd_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00107048 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_crm_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00107050 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00107058 size=1
// signature: undefined __const_udelay(void)
// callers: [crm_channel_switch_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00107060 size=1
// signature: undefined ipc_log_string(void)
// callers: [crm_channel_switch_complete, crm_cache_vcd_votes, crm_send_cmd, crm_write_pwr_states, crm_vote_complete_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00107080 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [_crm_dump_drv_regs, crm_cache_vcd_votes, crm_write_pwr_states, crm_vote_complete_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00107088 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [_crm_dump_drv_regs, crm_cache_vcd_votes, crm_write_pwr_states, crm_vote_complete_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc_to_page @ 00107090 size=1
// signature: undefined vmalloc_to_page(void)
// callers: [_crm_dump_drv_regs, _crm_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc_to_page(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001070a0 size=1
// signature: undefined _printk(void)
// callers: [_crm_dump_drv_regs, _crm_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001070a8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [crm_dump_regs, crm_read_curr_perf_ol, crm_get_device, crm_dump_drv_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001070b0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 001070b8 size=1
// signature: undefined init_wait_entry(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 001070c0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 001070c8 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001070d0 size=1
// signature: undefined schedule(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 001070d8 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001070e0 size=1
// signature: undefined finish_wait(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001070e8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001070f0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 001070f8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00107100 size=1
// signature: undefined __wake_up(void)
// callers: [crm_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00107108 size=1
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
// platform_driver_unregister @ 00107110 size=1
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
// trace_raw_output_prep @ 00107118 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_crm_vcd_votes, trace_raw_output_crm_irq, trace_raw_output_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 00107120 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_crm_vcd_votes, trace_raw_output_crm_irq, trace_raw_output_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 00107128 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_crm_vcd_votes, trace_raw_output_crm_irq, trace_raw_output_crm_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00107130 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00107138 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00107140 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00107148 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00107150 size=1
// signature: undefined devm_kmalloc(void)
// callers: [crm_probe, crm_probe_get_drvs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00107158 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00107160 size=1
// signature: undefined of_get_property(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00107168 size=1
// signature: undefined scnprintf(void)
// callers: [crm_probe, crm_probe_get_drvs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_get_and_ioremap_resource @ 00107170 size=1
// signature: undefined devm_platform_get_and_ioremap_resource(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_get_and_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00107178 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00107180 size=1
// signature: undefined strscpy(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00107188 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00107190 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00107198 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 001071a0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001071a8 size=1
// signature: undefined __list_add_valid(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001071b0 size=1
// signature: undefined fortify_panic(void)
// callers: [crm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001071b8 size=1
// signature: undefined __kmalloc(void)
// callers: [crm_probe_get_drvs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001071c0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [crm_probe_get_drvs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001071c8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [crm_probe_get_drvs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001071d0 size=1
// signature: undefined kfree(void)
// callers: [crm_probe_get_drvs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001071d8 size=1
// signature: undefined complete(void)
// callers: [crm_vote_complete_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



