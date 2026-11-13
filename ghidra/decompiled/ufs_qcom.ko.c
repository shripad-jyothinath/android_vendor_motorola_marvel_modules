// Decompiled by Ghidra 12.2
// Program: ufs_qcom.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_ufs_qcom_pwr_change_notify @ 00104c94 size=164
// signature: undefined __traceiter_ufs_qcom_pwr_change_notify(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_ufs_qcom_pwr_change_notify
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0011f3e8;
  plVar2 = DAT_0011f3e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x365839f4) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104d0c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_command @ 00104d3c size=164
// signature: undefined __traceiter_ufs_qcom_command(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_command
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f430;
  plVar2 = _DAT_0011f430;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x8342440) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104db4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_uic @ 00104de4 size=164
// signature: undefined __traceiter_ufs_qcom_uic(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_uic
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f478;
  plVar2 = _DAT_0011f478;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x510c3306) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104e5c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_hook_check_int_errors @ 00104e8c size=124
// signature: undefined __traceiter_ufs_qcom_hook_check_int_errors(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_hook_check_int_errors
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f4c0;
  plVar2 = _DAT_0011f4c0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4c44e7db) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104ee4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_shutdown @ 00104f0c size=100
// signature: undefined __traceiter_ufs_qcom_shutdown(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_ufs_qcom_shutdown(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f508;
  plVar2 = _DAT_0011f508;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xe742f40) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104f50);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_setup_clocks @ 00104f74 size=140
// signature: undefined __traceiter_ufs_qcom_setup_clocks(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_setup_clocks
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_0011f550 != (long *)0x0) {
    plVar2 = _DAT_0011f550;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x710a366f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104fd8);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1,param_5);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_clk_scale_notify @ 00105004 size=140
// signature: undefined __traceiter_ufs_qcom_clk_scale_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_clk_scale_notify
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_0011f598 != (long *)0x0) {
    plVar2 = _DAT_0011f598;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x710a366f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105068);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1,param_5);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_hce_enable_notify @ 00105094 size=124
// signature: undefined __traceiter_ufs_qcom_hce_enable_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_hce_enable_notify
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f5e0;
  plVar2 = _DAT_0011f5e0;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1050ec);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_link_startup_notify @ 00105114 size=124
// signature: undefined __traceiter_ufs_qcom_link_startup_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_link_startup_notify
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f628;
  plVar2 = _DAT_0011f628;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10516c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_suspend @ 00105194 size=172
// signature: undefined __traceiter_ufs_qcom_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_suspend
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f670;
  plVar2 = _DAT_0011f670;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x6001b492) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105214);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufs_qcom_resume @ 00105244 size=172
// signature: undefined __traceiter_ufs_qcom_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufs_qcom_resume
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f6b8;
  plVar2 = _DAT_0011f6b8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x6001b492) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1052c4);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_ufs_qcom_pwr_change_notify @ 001052f4 size=280
// signature: undefined trace_event_raw_event_ufs_qcom_pwr_change_notify(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_pwr_change_notify
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

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
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x20);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x20;
      strcpy((char *)(lVar3 + 0x20),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_7;
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
// perf_trace_ufs_qcom_pwr_change_notify @ 00105410 size=360
// signature: undefined perf_trace_ufs_qcom_pwr_change_notify(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_pwr_change_notify
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
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
  local_7c = param_6;
  local_78 = param_7;
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
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_7c;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x1c) = local_78;
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
// trace_event_raw_event_ufs_qcom_command @ 0010557c size=284
// signature: undefined trace_event_raw_event_ufs_qcom_command(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_command
               (long param_1,char *param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

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
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x20);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x20;
      strcpy((char *)(lVar3 + 0x20),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined1 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_7;
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
// perf_trace_ufs_qcom_command @ 0010569c size=364
// signature: undefined perf_trace_ufs_qcom_command(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_command
               (long param_1,char *param_2,undefined4 param_3,undefined1 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
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
  local_7c = param_6;
  local_78 = param_7;
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
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_7c;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined1 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x1c) = local_78;
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
// trace_event_raw_event_ufs_qcom_uic @ 0010580c size=280
// signature: undefined trace_event_raw_event_ufs_qcom_uic(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_uic
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

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
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x20);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x20;
      strcpy((char *)(lVar3 + 0x20),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_7;
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
// perf_trace_ufs_qcom_uic @ 00105928 size=360
// signature: undefined perf_trace_ufs_qcom_uic(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_uic
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
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
  local_7c = param_6;
  local_78 = param_7;
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
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_7c;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x1c) = local_78;
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
// trace_event_raw_event_ufs_qcom_hook_check_int_errors @ 00105a94 size=252
// signature: undefined trace_event_raw_event_ufs_qcom_hook_check_int_errors(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_hook_check_int_errors
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
// perf_trace_ufs_qcom_hook_check_int_errors @ 00105b94 size=336
// signature: undefined perf_trace_ufs_qcom_hook_check_int_errors(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_hook_check_int_errors
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

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
// trace_event_raw_event_ufs_qcom_shutdown @ 00105ce8 size=232
// signature: undefined trace_event_raw_event_ufs_qcom_shutdown(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_shutdown(long param_1,char *param_2)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0xc);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0xc;
      strcpy((char *)(lVar3 + 0xc),__s);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ufs_qcom_shutdown @ 00105dd4 size=316
// signature: undefined perf_trace_ufs_qcom_shutdown(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_shutdown(long param_1,char *param_2)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_58 = *(long *)(lVar5 + 0x638);
  local_60 = 0;
  local_64 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x14;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar3;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x1000c;
      strcpy((char *)(lVar5 + 0xc),__s);
      perf_trace_run_bpf_submit(lVar5,iVar1,local_64,param_1,1,local_60,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_ufs_qcom_clk_template @ 00105f14 size=268
// signature: undefined trace_event_raw_event_ufs_qcom_clk_template(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_clk_template
               (long param_1,char *param_2,undefined4 param_3,byte param_4,undefined4 param_5)

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
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x18);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x18;
      strcpy((char *)(lVar3 + 0x18),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(byte *)(lVar3 + 0x10) = param_4 & 1;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
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
// perf_trace_ufs_qcom_clk_template @ 00106024 size=356
// signature: undefined perf_trace_ufs_qcom_clk_template(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_clk_template
               (long param_1,char *param_2,undefined4 param_3,byte param_4,undefined4 param_5)

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
    iVar3 = ((int)sVar4 + 0x24U & 0xfffffff8) - 4;
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
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10018;
      strcpy((char *)(lVar5 + 0x18),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(byte *)(lVar5 + 0x10) = param_4 & 1;
      *(undefined4 *)(lVar5 + 0x14) = param_5;
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
// trace_event_raw_event_ufs_qcom_noify_template @ 0010618c size=252
// signature: undefined trace_event_raw_event_ufs_qcom_noify_template(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_noify_template
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
// perf_trace_ufs_qcom_noify_template @ 0010628c size=336
// signature: undefined perf_trace_ufs_qcom_noify_template(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_noify_template
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

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
// trace_event_raw_event_ufs_qcom_pm_template @ 001063e0 size=292
// signature: undefined trace_event_raw_event_ufs_qcom_pm_template(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufs_qcom_pm_template
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar1 + 0x24);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x24;
      strcpy((char *)(lVar3 + 0x24),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_7;
      *(undefined4 *)(lVar3 + 0x20) = param_8;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ufs_qcom_pm_template @ 00106508 size=364
// signature: undefined perf_trace_ufs_qcom_pm_template(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufs_qcom_pm_template
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_80 = param_6;
  local_7c = param_7;
  local_78 = param_8;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x2c;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined4 **)(local_70 + 0xf8) = &local_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x10024;
      strcpy((char *)(lVar5 + 0x24),__s);
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_80;
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x1c) = local_7c;
      *(undefined4 *)(lVar5 + 0x20) = local_78;
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
// __bpf_trace_ufs_qcom_pwr_change_notify @ 00106678 size=48
// signature: undefined __bpf_trace_ufs_qcom_pwr_change_notify(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_pwr_change_notify
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_command @ 001066ac size=48
// signature: undefined __bpf_trace_ufs_qcom_command(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_command
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined1 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_uic @ 001066e0 size=48
// signature: undefined __bpf_trace_ufs_qcom_uic(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_uic
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_hook_check_int_errors @ 00106714 size=36
// signature: undefined __bpf_trace_ufs_qcom_hook_check_int_errors(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_hook_check_int_errors
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_shutdown @ 0010673c size=28
// signature: undefined __bpf_trace_ufs_qcom_shutdown(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_shutdown(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_clk_template @ 0010675c size=40
// signature: undefined __bpf_trace_ufs_qcom_clk_template(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_clk_template
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,ulong param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4 & 1,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_noify_template @ 00106788 size=36
// signature: undefined __bpf_trace_ufs_qcom_noify_template(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_noify_template
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufs_qcom_pm_template @ 001067b0 size=52
// signature: undefined __bpf_trace_ufs_qcom_pm_template(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufs_qcom_pm_template
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  bpf_trace_run7(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



//------------------------------------------------------------
// ufsqcom_dump_regs @ 001067e8 size=280
// signature: undefined ufsqcom_dump_regs(void)
// callers: []
//------------------------------------------------------------

undefined8
ufsqcom_dump_regs(long param_1,long param_2,ulong param_3,undefined8 param_4,uint param_5)

{
  code *pcVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  
  if ((((uint)param_3 | (uint)param_2) & 3) == 0) {
    lVar5 = __kmalloc(param_3,0xb20);
    if (lVar5 == 0) {
      uVar4 = 0xfffffff4;
    }
    else {
      if (param_3 != 0) {
        if (6 < param_5) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x106900);
          (*pcVar1)();
        }
        uVar7 = 0;
        uVar6 = param_3;
        do {
          uVar3 = readl(*(long *)(param_1 + (ulong)param_5 * 0x18 + 0x13c0) + param_2 + uVar7);
          if ((((long)uVar7 < 0) || (param_3 < uVar7)) ||
             (bVar2 = uVar6 < 4, uVar6 = uVar6 - 4, bVar2)) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(1,0x1068fc);
            (*pcVar1)();
          }
          *(undefined4 *)(lVar5 + uVar7) = uVar3;
          uVar7 = uVar7 + 4;
        } while (uVar7 < param_3);
      }
      print_hex_dump(&DAT_00120383,param_4,(ulong)(4 < param_3) << 1,0x10,4,lVar5,param_3,0);
      kfree(lVar5);
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// readl @ 00106900 size=140
// signature: undefined readl(void)
// callers: [ufs_qcom_testbus_config, ufs_qcom_hook_send_command, ufs_qcom_pwr_change_notify, hibern8_count_show, ufs_qcom_hook_compl_command, ufs_qcom_dev_ref_clk_ctrl, ufs_qcom_reset_deassert, ufs_qcom_init, ufs_qcom_clk_scale_notify, ufsqcom_dump_regs, ufs_qcom_enable_hw_clk_gating, ufs_qcom_get_outstanding_cqs, ufs_qcom_save_regs, ufs_qcom_print_hw_debug_reg_all, ufs_qcom_link_startup_notify, ufs_qcom_dump_dbg_regs, ufs_qcom_config_esi, ufs_qcom_reset_assert, ufs_qcom_event_notify, ufs_qcom_setup_clocks, ufs_qcom_hce_enable_notify, __ufs_qcom_cfg_timers, ufs_qcom_hook_send_uic_command]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x106958,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_get_max_therm_state @ 00106990 size=16
// signature: undefined ufs_qcom_get_max_therm_state(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_get_max_therm_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 2;
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_get_cur_therm_state @ 001069a4 size=36
// signature: undefined ufs_qcom_get_cur_therm_state(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_get_cur_therm_state(long param_1,undefined8 *param_2)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x3b0) + 0x98);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1069c8);
    (*pcVar1)();
  }
  *param_2 = *(undefined8 *)(*(long *)(lVar2 + 0xb0) + 0x1e8);
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_set_cur_therm_state @ 001069cc size=328
// signature: undefined ufs_qcom_set_cur_therm_state(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_set_cur_therm_state(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar2 = *(long *)(param_1 + 0x3b0);
  lVar3 = *(long *)(lVar2 + 0x98);
  if (lVar3 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106b14);
    (*pcVar1)();
  }
  lVar4 = *(long *)(lVar3 + 0xb0);
  if (*(long *)(lVar4 + 0x1e8) != param_2) {
    if (param_2 - 1U < 2) {
      _dev_warn(lVar2,
                "Going into UFS host thermal mitigation state, performance may be impacted before UFS host thermal mitigation stops\n"
               );
      *(undefined4 *)(lVar4 + 0x2e4) = 1;
      cancel_dwork_unvote_cpufreq(lVar3);
      if (*(char *)(lVar4 + 0xc61) != '\0') {
        ufs_qcom_toggle_pri_affinity(lVar3,0);
      }
      ufshcd_auto_hibern8_update(lVar3,1000);
      lVar2 = __scsi_iterate_devices(*(undefined8 *)(lVar3 + 0x38),0);
      if (lVar2 != 0) {
        do {
          pm_runtime_set_autosuspend_delay(lVar2 + 0x1d8,100);
          lVar2 = __scsi_iterate_devices(*(undefined8 *)(lVar3 + 0x38),lVar2);
        } while (lVar2 != 0);
      }
    }
    else {
      if (param_2 != 0) {
        _dev_err(lVar2,"Invalid UFS thermal state (%d)\n",param_2);
        return 0xffffffea;
      }
      _dev_warn(lVar2,"UFS host thermal mitigation stops\n");
      *(undefined4 *)(lVar4 + 0x2e4) = 0;
      ufshcd_auto_hibern8_update(lVar3,0x5f4);
      lVar2 = __scsi_iterate_devices(*(undefined8 *)(lVar3 + 0x38),0);
      if (lVar2 != 0) {
        do {
          pm_runtime_set_autosuspend_delay(lVar2 + 0x1d8,3000);
          lVar2 = __scsi_iterate_devices(*(undefined8 *)(lVar3 + 0x38),lVar2);
        } while (lVar2 != 0);
      }
    }
    *(long *)(lVar4 + 0x1e8) = param_2;
  }
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_print_hw_debug_reg_all @ 00106b18 size=1816
// signature: undefined ufs_qcom_print_hw_debug_reg_all(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_print_hw_debug_reg_all(long *param_1,undefined8 param_2,code *param_3)

{
  byte bVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  int iVar6;
  long lVar7;
  
  if (param_1 == (long *)0x0) {
    _printk(&DAT_00121e7a,"ufs_qcom_print_hw_debug_reg_all");
  }
  else if (param_3 == (code *)0x0) {
    _dev_err(param_1[8],"%s: print_fn is NULL\n","ufs_qcom_print_hw_debug_reg_all");
  }
  else {
    lVar7 = param_1[0x16];
    if ((*(byte *)(lVar7 + 0xc0) & 1) != 0) {
      uVar3 = readl(*param_1 + 0xdc);
      writel(uVar3 | 0x20000,*param_1 + 0xdc);
      if (*(byte *)(lVar7 + 0xa6) < 6) {
        uVar5 = 0x1900;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x1d00;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106f2c);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x20,"UFS_UFS_DBG_RD_EDTL_RAM ",param_2);
        uVar5 = 0x1500;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x1900;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106f6c);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x80,"UFS_UFS_DBG_RD_DESC_RAM ",param_2);
        uVar5 = 0x1700;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x1b00;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106fb0);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_UFS_DBG_RD_PRDT_RAM ",param_2);
        uVar3 = readl(*param_1 + 0xdc);
        writel(uVar3 & 0xfffdffff,*param_1 + 0xdc);
        uVar5 = 0x800;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0xc00;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x107010);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x2c,"UFS_UFS_DBG_RD_REG_OCSC ",param_2);
        uVar5 = 0x100;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x500;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x107054);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,4,"UFS_DBG_RD_REG_UAWM ",param_2);
        uVar5 = 0x200;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x600;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x107098);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,4,"UFS_DBG_RD_REG_UARM ",param_2);
        uVar5 = 0x300;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x700;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x1070dc);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x30,"UFS_DBG_RD_REG_TXUC ",param_2);
        uVar5 = 0x400;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x800;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x10711c);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x1b,"UFS_DBG_RD_REG_RXUC ",param_2);
        uVar5 = 0x500;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x900;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x10715c);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x13,"UFS_DBG_RD_REG_DFC ",param_2);
        uVar5 = 0x600;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0xa00;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x10719c);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x22,"UFS_DBG_RD_REG_TRLUT ",param_2);
        bVar1 = *(byte *)(lVar7 + 0xa6);
        uVar4 = 9;
      }
      else {
        iVar6 = 3;
        do {
          writel(iVar6,*param_1 + 0x1000);
          if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106bc8);
            (*pcVar2)();
          }
          (*param_3)(param_1,0x1024,8,"UFS_UFS_DBG_RD_DESC_RAM ",param_2);
          iVar6 = iVar6 + 0x100;
        } while (iVar6 != 0x8003);
        iVar6 = 4;
        do {
          writel(iVar6,*param_1 + 0x1000);
          if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106c24);
            (*pcVar2)();
          }
          (*param_3)(param_1,0x1024,8,"UFS_UFS_DBG_RD_PRDT_RAM ",param_2);
          iVar6 = iVar6 + 0x100;
        } while (iVar6 != 0x4004);
        iVar6 = 5;
        do {
          writel(iVar6,*param_1 + 0x1000);
          if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106c80);
            (*pcVar2)();
          }
          (*param_3)(param_1,0x1024,8," UFS_UFS_DBG_RD_RESP_RAM ",param_2);
          iVar6 = iVar6 + 0x100;
        } while (iVar6 != 0x4005);
        iVar6 = 6;
        do {
          writel(iVar6,*param_1 + 0x1000);
          if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106cdc);
            (*pcVar2)();
          }
          (*param_3)(param_1,0x1024,8,"UFS_UFS_DBG_RD_EDTL_RAM ",param_2);
          iVar6 = iVar6 + 0x100;
        } while (iVar6 != 0x4006);
        uVar3 = readl(*param_1 + 0xdc);
        writel(uVar3 & 0xfffdffff,*param_1 + 0xdc);
        uVar5 = 0x800;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0xc00;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106d48);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_UFS_DBG_RD_REG_OCSC ",param_2);
        uVar5 = 0x100;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x500;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106d8c);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_DBG_RD_REG_UAWM ",param_2);
        uVar5 = 0x200;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x600;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106dd0);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_DBG_RD_REG_UARM ",param_2);
        uVar5 = 0x300;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x700;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106e14);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_DBG_RD_REG_TXUC ",param_2);
        uVar5 = 0x400;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x800;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106e54);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_DBG_RD_REG_RXUC ",param_2);
        uVar5 = 0x500;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0x900;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106e94);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_DBG_RD_REG_DFC ",param_2);
        uVar5 = 0x600;
        if (2 < *(byte *)(lVar7 + 0xa6)) {
          uVar5 = 0xa00;
        }
        if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x106ed4);
          (*pcVar2)();
        }
        (*param_3)(param_1,uVar5,0x40,"UFS_DBG_RD_REG_TRLUT ",param_2);
        bVar1 = *(byte *)(lVar7 + 0xa6);
        uVar4 = 0x40;
      }
      uVar5 = 0x700;
      if (2 < bVar1) {
        uVar5 = 0xb00;
      }
      if (*(int *)(param_3 + -4) != 0x271011b6) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x1071dc);
        (*pcVar2)();
      }
      (*param_3)(param_1,uVar5,uVar4,"UFS_DBG_RD_REG_TMRLUT ",param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// writel @ 00107230 size=136
// signature: undefined writel(void)
// callers: [ufs_qcom_testbus_config, ufs_qcom_hook_send_command, ufs_qcom_hook_compl_command, ufs_qcom_reset_deassert, ufs_qcom_hibern8_notify, ufs_qcom_enable_hw_clk_gating, ufs_qcom_print_hw_debug_reg_all, ufs_qcom_link_startup_notify, ufs_qcom_dump_dbg_regs, ufs_qcom_config_esi, ufs_qcom_reset_assert, ufs_qcom_hce_enable_notify, __ufs_qcom_cfg_timers]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x107248,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x107288,uVar1);
  return;
}



//------------------------------------------------------------
// ufs_qcom_testbus_config @ 001072bc size=404
// signature: undefined ufs_qcom_testbus_config(void)
// callers: [ufs_qcom_dump_dbg_regs, ufs_qcom_init, ufs_qcom_event_notify]
//------------------------------------------------------------

undefined8 ufs_qcom_testbus_config(long param_1)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  long lVar4;
  uint uVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  
  if (param_1 == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    lVar10 = *(long *)(param_1 + 0x10);
    lVar4 = sp_el0;
    if ((*(uint *)(lVar4 + 0x10) & 0xff0100) == 0) {
      uVar6 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38));
    }
    else {
      uVar6 = 0;
    }
    uVar7 = (ulong)(char)*(byte *)(param_1 + 0xc4);
    uVar8 = (uint)*(byte *)(param_1 + 0xc4);
    if (uVar7 < 0xc) {
      uVar1 = *(uint *)(&DAT_0011c470 + uVar7 * 4);
      uVar2 = *(uint *)(&DAT_0011c4a0 + uVar7 * 4);
      lVar9 = *(long *)(&DAT_0011c410 + uVar7 * 8);
      if ((*(uint *)(lVar4 + 0x10) & 0xff0100) == 0) {
        _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38),uVar6);
        uVar8 = (uint)*(byte *)(param_1 + 0xc4);
      }
      plVar11 = *(long **)(param_1 + 0x10);
      uVar5 = readl(*plVar11 + 0xdc);
      writel(uVar5 & 0xff800000 | uVar5 & 0x7ffff | (uVar8 & 0xf) << 0x13,*plVar11 + 0xdc);
      plVar11 = *(long **)(param_1 + 0x10);
      bVar3 = *(byte *)(param_1 + 0xc5);
      uVar8 = readl(*plVar11 + lVar9);
      writel(uVar8 & (uVar2 << (ulong)(uVar1 & 0x1f) ^ 0xffffffff) |
             (uVar2 & bVar3) << (ulong)(uVar1 & 0x1f),*plVar11 + lVar9);
      plVar11 = *(long **)(param_1 + 0x10);
      uVar8 = readl(*plVar11 + 0xdc);
      writel(uVar8 | 0x40000000,*plVar11 + 0xdc);
      plVar11 = *(long **)(param_1 + 0x10);
      uVar8 = readl(*plVar11 + 0xdc);
      writel(uVar8 | 0x40000,*plVar11 + 0xdc);
      DataSynchronizationBarrier(3,3,0);
      uVar6 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),
               "%s: UFS_CFG1[TEST_BUS_SEL} may not equal 0x%05X\n","ufs_qcom_testbus_cfg_is_ok",
               uVar8);
      uVar6 = 0xffffffff;
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_pwr_change_notify @ 00107454 size=140
// signature: undefined trace_raw_output_ufs_qcom_pwr_change_notify(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_pwr_change_notify(long param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(ushort *)(lVar4 + 8);
    uVar3 = trace_print_symbols_seq
                      (param_1 + 0x90,(long)*(int *)(lVar4 + 0xc),
                       trace_raw_output_ufs_qcom_pwr_change_notify_symbols);
    trace_event_printf(param_1,
                       "%s: status = %s, gear_rx = %d, pwr_rx = %d, hs_rate = %d, err = %d\n",
                       lVar4 + (ulong)uVar1,uVar3,*(undefined4 *)(lVar4 + 0x10),
                       *(undefined4 *)(lVar4 + 0x14),*(undefined4 *)(lVar4 + 0x18),
                       *(undefined4 *)(lVar4 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_command @ 001074e4 size=228
// signature: undefined trace_raw_output_ufs_qcom_command(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_command(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  ushort uVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x20f0);
  iVar6 = trace_raw_output_prep(param_1,param_3);
  if (iVar6 == 1) {
    uVar5 = *(ushort *)(lVar9 + 8);
    uVar7 = trace_print_symbols_seq
                      (param_1 + 0x90,(long)*(int *)(lVar9 + 0xc),
                       trace_raw_output_ufs_qcom_command_symbols);
    uVar1 = *(undefined4 *)(lVar9 + 0x14);
    uVar2 = *(undefined4 *)(lVar9 + 0x18);
    uVar3 = *(undefined4 *)(lVar9 + 0x1c);
    uVar4 = *(undefined1 *)(lVar9 + 0x10);
    uVar8 = trace_print_symbols_seq
                      (param_1 + 0x90,uVar4,trace_raw_output_ufs_qcom_command_symbols_64);
    trace_event_printf(param_1,"%s: %s: tag: %d, DB: 0x%x, size: %d, opcode: 0x%x (%s)\n",
                       lVar9 + (ulong)uVar5,uVar7,uVar1,uVar2,uVar3,uVar4,uVar8);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_uic @ 001075cc size=140
// signature: undefined trace_raw_output_ufs_qcom_uic(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_uic(long param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(ushort *)(lVar4 + 8);
    uVar3 = trace_print_symbols_seq
                      (param_1 + 0x90,(long)*(int *)(lVar4 + 0xc),
                       trace_raw_output_ufs_qcom_uic_symbols);
    trace_event_printf(param_1,"%s: %s: cmd: 0x%x, arg1: 0x%x, arg2: 0x%x, arg3: 0x%x\n",
                       lVar4 + (ulong)uVar1,uVar3,*(undefined4 *)(lVar4 + 0x10),
                       *(undefined4 *)(lVar4 + 0x14),*(undefined4 *)(lVar4 + 0x18),
                       *(undefined4 *)(lVar4 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_hook_check_int_errors @ 0010765c size=108
// signature: undefined trace_raw_output_ufs_qcom_hook_check_int_errors(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_hook_check_int_errors
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: err: 0x%x, uic_err: 0x%x\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_shutdown @ 001076cc size=104
// signature: undefined trace_raw_output_ufs_qcom_shutdown(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_shutdown(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: Going to Shutdown!\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_clk_template @ 00107738 size=140
// signature: undefined trace_raw_output_ufs_qcom_clk_template(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_clk_template(long param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(ushort *)(lVar4 + 8);
    uVar3 = trace_print_symbols_seq
                      (param_1 + 0x90,(long)*(int *)(lVar4 + 0xc),
                       trace_raw_output_ufs_qcom_clk_template_symbols);
    trace_event_printf(param_1,"%s: status = %s, on= %d, err = %d\n",lVar4 + (ulong)uVar1,uVar3,
                       *(undefined1 *)(lVar4 + 0x10),*(undefined4 *)(lVar4 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_noify_template @ 001077c8 size=136
// signature: undefined trace_raw_output_ufs_qcom_noify_template(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_noify_template(long param_1,undefined8 param_2,undefined8 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(ushort *)(lVar4 + 8);
    uVar3 = trace_print_symbols_seq
                      (param_1 + 0x90,(long)*(int *)(lVar4 + 0xc),
                       trace_raw_output_ufs_qcom_noify_template_symbols);
    trace_event_printf(param_1,"%s: status = %s, err = %d\n",lVar4 + (ulong)uVar1,uVar3,
                       *(undefined4 *)(lVar4 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufs_qcom_pm_template @ 00107854 size=244
// signature: undefined trace_raw_output_ufs_qcom_pm_template(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufs_qcom_pm_template(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0x20f0);
  iVar5 = trace_raw_output_prep(param_1,param_3);
  if (iVar5 == 1) {
    lVar1 = param_1 + 0x90;
    uVar4 = *(ushort *)(lVar9 + 8);
    uVar6 = trace_print_symbols_seq
                      (lVar1,(long)*(int *)(lVar9 + 0xc),
                       trace_raw_output_ufs_qcom_pm_template_symbols);
    uVar2 = *(undefined4 *)(lVar9 + 0x10);
    uVar3 = *(undefined4 *)(lVar9 + 0x14);
    uVar7 = trace_print_symbols_seq
                      (lVar1,(long)*(int *)(lVar9 + 0x18),
                       trace_raw_output_ufs_qcom_pm_template_symbols_89);
    uVar8 = trace_print_symbols_seq
                      (lVar1,(long)*(int *)(lVar9 + 0x1c),
                       trace_raw_output_ufs_qcom_pm_template_symbols_90);
    trace_event_printf(param_1,
                       "%s: pm_op = %s, rpm_lvl = %d, spm_lvl = %d, link_state = %s, dev_pwr_mode = %d, err = %d\n"
                       ,lVar9 + (ulong)uVar4,uVar6,uVar2,uVar3,uVar7,uVar8,
                       *(undefined4 *)(lVar9 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_ber_threshold_set @ 0010794c size=152
// signature: undefined ufs_qcom_ber_threshold_set(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_ber_threshold_set(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_1,0,&local_2c);
  uVar3 = 0xffffffea;
  if ((iVar2 == 0) && (local_2c < 0x20)) {
    override_ber_threshold = local_2c != 0;
    uVar3 = param_set_int(param_1,param_2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_ber_duration_set @ 001079e8 size=144
// signature: undefined ufs_qcom_ber_duration_set(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_ber_duration_set(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoll(param_1,0,&local_30);
  if (iVar2 == 0) {
    override_ber_duration = local_30 != 0;
    uVar3 = param_set_int(param_1,param_2);
  }
  else {
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// cancel_dwork_unvote_cpufreq @ 00107a78 size=288
// signature: undefined cancel_dwork_unvote_cpufreq(void)
// callers: [ufs_qcom_clk_scale_notify, ufs_qcom_suspend, ufs_qcom_set_cur_therm_state]
//------------------------------------------------------------

void cancel_dwork_unvote_cpufreq(long param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x107b98);
    (*pcVar4)();
  }
  lVar6 = *(long *)(param_1 + 0xb0);
  if (((*(char *)(lVar6 + 0x298) == '\0') &&
      (cancel_delayed_work_sync(lVar6 + 0x210), *(char *)(lVar6 + 0x20c) != '\0')) &&
     (*(undefined4 *)(lVar6 + 0x208) = 0, 0 < *(int *)(lVar6 + 0x2a8))) {
    lVar7 = 0;
    lVar8 = 0;
    do {
      puVar1 = (uint *)(*(long *)(lVar6 + 0x2a0) + lVar7);
      uVar2 = *puVar1;
      uVar3 = puVar1[1];
      cpus_read_lock();
      if ((*(ulong *)(&__cpu_online_mask + ((ulong)(uVar2 >> 3) & 0x1ffffff8)) >>
           ((ulong)uVar2 & 0x3f) & 1) == 0) {
        cpus_read_unlock();
LAB_00107b74:
        *(undefined1 *)(lVar6 + 0x20c) = 0;
      }
      else {
        if (0x1f < uVar2) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x107b94);
          (*pcVar4)();
        }
        iVar5 = freq_qos_update_request
                          (&qos_min_req + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8),uVar3);
        cpus_read_unlock();
        if (-1 < iVar5) goto LAB_00107b74;
        _dev_err(*(undefined8 *)(param_1 + 0x40),"fail set cpufreq-fmin_def %d\n",iVar5);
      }
      lVar8 = lVar8 + 1;
      lVar7 = lVar7 + 0xc;
    } while (lVar8 < *(int *)(lVar6 + 0x2a8));
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_toggle_pri_affinity @ 00107b98 size=204
// signature: undefined ufs_qcom_toggle_pri_affinity(void)
// callers: [ufs_qcom_set_cur_therm_state]
//------------------------------------------------------------

void ufs_qcom_toggle_pri_affinity(long param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x107c64);
    (*pcVar1)();
  }
  lVar6 = *(long *)(param_1 + 0xb0);
  if ((param_2 & 1) == 0) {
    uVar4 = 0;
    uVar3 = 0xfffffffc;
    uVar5 = 0x2000;
  }
  else {
    if (*(int *)(lVar6 + 0x2e4) != 0) {
      return;
    }
    uVar5 = 0;
    uVar3 = 4;
    uVar4 = 0x2000;
  }
  sched_set_boost(uVar3);
  *(uint *)(lVar6 + 0x2e0) = param_2 & 1;
  lVar7 = *(long *)(param_1 + 0xb0);
  lVar6 = lVar7 + 0x2e8;
  if ((param_2 & 1) == 0) {
    lVar6 = lVar7 + 0x2f0;
  }
  irq_modify_status(*(undefined4 *)(param_1 + 0xc0),uVar5,uVar4);
  iVar2 = __irq_apply_affinity_hint(*(undefined4 *)(param_1 + 0xc0),lVar6,1);
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(*(long *)(lVar7 + 0x10) + 0x40),"prime=%d, err=%d\n",param_2 & 1,iVar2)
    ;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_probe @ 00107c68 size=592
// signature: undefined ufs_qcom_probe(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_probe(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  byte *pbVar4;
  long lVar5;
  undefined8 uVar6;
  uint local_54;
  undefined8 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar5 + 0x638);
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  local_50 = 0;
  local_54 = 0;
  uVar3 = nvmem_cell_get(lVar1,"boot_conf");
  if (uVar3 < 0xfffffffffffff001) {
    pbVar4 = (byte *)nvmem_cell_read(uVar3,&local_50);
    if (pbVar4 < (byte *)0xfffffffffffff001) {
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"boot_device_type",&local_54,1,0);
      if (iVar2 < 0) {
        _dev_warn(lVar1,"boot_device_type not present\n");
      }
      else {
        is_bootdevice_ufs = local_54 == (*pbVar4 >> 1 & 0x1f);
        if (!(bool)is_bootdevice_ufs) {
          _dev_err(lVar1,"boot dev in reg = 0x%x boot dev in dtsi = 0x%x\n");
        }
      }
      kfree(pbVar4);
    }
    else {
      _dev_warn(lVar1,"nvmem cell read failed\n");
    }
    nvmem_cell_put(uVar3);
  }
  if (is_bootdevice_ufs == '\0') {
    _dev_err(lVar1,"UFS is not boot dev.\n");
  }
  else {
    lVar5 = of_find_property(uVar6,"secondary-storage",0);
    if ((lVar5 != 0) &&
       ((ufs_qcom_hosts == 0 || (*(int *)(*(long *)(ufs_qcom_hosts + 0x10) + 0x1394) != 1)))) {
      uVar6 = 0xfffffdfb;
      goto LAB_00107e48;
    }
    iVar2 = ufshcd_pltfrm_init(param_1,&ufs_hba_qcom_vops);
    if (iVar2 != 0) {
      uVar6 = dev_err_probe(lVar1,iVar2,"ufshcd_pltfrm_init() failed\n");
      goto LAB_00107e48;
    }
    tracepoint_probe_register
              (&__tracepoint_android_vh_ufs_send_command,ufs_qcom_hook_send_command,0);
    tracepoint_probe_register
              (&__tracepoint_android_vh_ufs_compl_command,ufs_qcom_hook_compl_command,0);
    tracepoint_probe_register
              (&__tracepoint_android_vh_ufs_send_uic_command,ufs_qcom_hook_send_uic_command,0);
    tracepoint_probe_register
              (&__tracepoint_android_vh_ufs_send_tm_command,ufs_qcom_hook_send_tm_command,0);
    tracepoint_probe_register
              (&__tracepoint_android_vh_ufs_check_int_errors,ufs_qcom_hook_check_int_errors,0);
    tracepoint_probe_register(&__tracepoint_android_vh_ufs_update_sdev,ufs_qcom_update_sdev,0);
    ufs_samsung_register_hooks();
    ufs_host_exception_event_hook(*(undefined8 *)(param_1 + 0xa8));
  }
  uVar6 = 0;
LAB_00107e48:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_remove @ 00107ebc size=300
// signature: undefined ufs_qcom_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ufs_qcom_remove(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  uint uVar10;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1 + 0x10,"UFS is not boot dev.\n");
  }
  else {
    lVar5 = *(long *)(param_1 + 0xa8);
    if (lVar5 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x107fe8);
      (*pcVar1)();
    }
    lVar8 = *(long *)(lVar5 + 0xb0);
    plVar9 = *(long **)(lVar8 + 0x1d8);
    lVar6 = *plVar9;
    __pm_runtime_resume(param_1 + 0x10,4);
    if ((int)plVar9[1] != 0) {
      uVar10 = 0;
      do {
        iVar3 = 0;
        lVar7 = *(long *)(lVar6 + 0x10);
        while ((uVar2 = _find_next_bit(lVar6,_nr_cpu_ids,(long)iVar3), uVar2 < _nr_cpu_ids &&
               ((*(long *)(lVar7 + 0x48) == 0 ||
                (iVar3 = dev_pm_qos_remove_request(lVar7), -1 < iVar3))))) {
          lVar7 = lVar7 + 0x50;
          iVar3 = uVar2 + 1;
        }
        uVar10 = uVar10 + 1;
        lVar6 = lVar6 + 0x60;
      } while (uVar10 < *(uint *)(plVar9 + 1));
    }
    uVar4 = msm_minidump_enabled();
    if ((uVar4 & 1) != 0) {
      atomic_notifier_chain_unregister(&panic_notifier_list,lVar8 + 0xc68);
    }
    ufsf_remove(*(long *)(lVar5 + 0xb0) + 0xd50);
    ufshcd_remove(lVar5);
    platform_msi_domain_free_irqs(*(undefined8 *)(lVar5 + 0x40));
  }
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_shutdown @ 00107fec size=332
// signature: undefined ufs_qcom_shutdown(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_shutdown(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1 + 0x10,"UFS is not boot dev.\n");
  }
  else {
    lVar6 = *(long *)(param_1 + 0xa8);
    if (lVar6 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x108138);
      (*pcVar1)();
    }
    lVar7 = *(long *)(lVar6 + 0xb0);
    if ((*(long *)(lVar7 + 0x2b0) != 0) && (*(char *)(lVar7 + 0x2b8) != '\0')) {
      lVar4 = tpidr_el1;
      ipc_log_string(*(long *)(lVar7 + 0x2b0),",%d,0xdead\n",*(undefined4 *)(&cpu_number + lVar4));
    }
    uVar3 = (ulong)*(byte *)(lVar7 + 0x2b8);
    if (*(byte *)(lVar7 + 0x2b8) != 0) {
      uVar3 = (*(ulong **)(lVar6 + 0x40))[0xe];
      if (uVar3 == 0) {
        uVar3 = **(ulong **)(lVar6 + 0x40);
      }
    }
    lVar4 = *(long *)(lVar6 + 0xb0);
    ufs_qcom_parse_reg_info(uVar3,lVar4,"qcom,vccq-shutdown",lVar4 + 0x188);
    puVar5 = *(undefined8 **)(lVar4 + 0x188);
    if ((puVar5 != (undefined8 *)0x0) && (*(char *)((long)puVar5 + 0x11) == '\0')) {
      iVar2 = regulator_count_voltages(*puVar5);
      if (((iVar2 < 1) ||
          (iVar2 = regulator_set_load(*puVar5,*(undefined4 *)((long)puVar5 + 0x14)), iVar2 == 0)) &&
         (iVar2 = regulator_enable(*puVar5), iVar2 == 0)) {
        *(undefined1 *)((long)puVar5 + 0x11) = 1;
      }
      else {
        _dev_err(*(undefined8 *)(lVar6 + 0x40),"%s: failed enable vccq_shutdown err=%d\n",
                 "ufs_qcom_enable_vccq_shutdown",iVar2);
      }
    }
    ufshcd_pltfrm_shutdown(param_1);
    if (*(char *)(lVar7 + 0xc63) == '\0') {
      lVar6 = *(long *)(*(long *)(lVar6 + 0xb0) + 0x128);
      if (lVar6 != 0) {
        gpiod_set_value_cansleep(lVar6,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_init @ 001081d8 size=4120
// signature: undefined ufs_qcom_init(void)
// callers: []
//------------------------------------------------------------

ulong ufs_qcom_init(long *param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  long lVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  long *plVar13;
  long lVar14;
  long lVar15;
  undefined *puVar16;
  ulong uVar17;
  byte *pbVar18;
  undefined8 uVar19;
  char *pcVar20;
  char *pcVar21;
  undefined4 uVar22;
  undefined8 uVar23;
  undefined8 *puVar24;
  long lVar25;
  ulong *puVar26;
  long lVar27;
  long *plVar28;
  undefined8 *local_80;
  undefined8 *local_78;
  undefined4 local_70;
  undefined1 local_6c;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar27 = param_1[8];
  local_6c = 0;
  local_70 = 0;
  lVar9 = devm_kmalloc(lVar27,0xed0,0xdc0);
  if (lVar9 == 0) {
    _dev_err(lVar27,"%s: no memory for qcom ufs host\n","ufs_qcom_init");
    uVar12 = 0xfffffff4;
    goto LAB_00108324;
  }
  *(long **)(lVar9 + 0x10) = param_1;
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1091f0);
    (*pcVar6)();
  }
  lVar10 = param_1[8];
  param_1[0x16] = lVar9;
  if (*(long *)(lVar10 + 0x2e8) != 0) {
    lVar11 = of_find_property(*(long *)(lVar10 + 0x2e8),"qcom,enable_crash_on_err",0);
    lVar10 = param_1[8];
    *(byte *)(lVar9 + 0x1f1) = lVar11 != 0 | crash_on_err & 1;
  }
  uVar12 = __devm_reset_control_get(lVar10,&DAT_0012173f,0,0,1,1);
  *(ulong *)(lVar9 + 200) = uVar12;
  if (uVar12 < 0xfffffffffffff001) {
    uVar23 = *(undefined8 *)(lVar27 + 0x2e8);
    *(undefined1 **)(lVar9 + 0xd0) = ufs_qcom_reset_ops;
    *(undefined8 *)(lVar9 + 0x108) = uVar23;
    uVar23 = *(undefined8 *)(*(long *)(lVar27 + 0x88) + 0x10);
    *(undefined4 *)(lVar9 + 0x120) = 1;
    *(undefined8 *)(lVar9 + 0xd8) = uVar23;
    iVar7 = devm_reset_controller_register(lVar27);
    if (iVar7 != 0) {
      _dev_warn(lVar27,"Failed to register reset controller\n");
    }
    uVar12 = devm_phy_get(lVar27,"ufsphy");
    *(ulong *)(lVar9 + 8) = uVar12;
    if (0xfffffffffffff000 < uVar12) {
      pcVar20 = "Failed to get PHY\n";
      goto LAB_00108314;
    }
    uVar12 = devm_gpiod_get_optional(lVar27,"reset",7);
    *(ulong *)(lVar9 + 0x128) = uVar12;
    if (uVar12 < 0xfffffffffffff001) {
      local_78 = (undefined8 *)((ulong)local_78 & 0xffffffff00000000);
      local_80 = (undefined8 *)((ulong)local_80 & 0xffffffff00000000);
      lVar10 = *(long *)(*(long *)(lVar9 + 0x10) + 0x40);
      uVar23 = *(undefined8 *)(lVar10 + 0x2e8);
      if (lVar10 == 0x10) {
        pcVar20 = "Null platform device!\n";
LAB_00108714:
        _dev_err(lVar10,pcVar20);
LAB_0010871c:
        _dev_err(lVar10,"Failed: getting bus_scale data\n");
      }
      else {
        plVar13 = (long *)devm_kmalloc(lVar10,0x28,0xdc0);
        if (plVar13 == (long *)0x0) goto LAB_0010871c;
        iVar7 = of_property_read_string(uVar23,"qcom,ufs-bus-bw,name",plVar13 + 4);
        if (iVar7 != 0) {
          _dev_err(lVar10,"Error: (%d) Bus name missing!\n",iVar7);
          goto LAB_0010871c;
        }
        puVar3 = (uint *)(plVar13 + 1);
        iVar7 = of_property_read_variable_u32_array(uVar23,"qcom,ufs-bus-bw,num-cases",puVar3,1,0);
        if (iVar7 < 0) {
          puVar16 = &DAT_001211c5;
          goto LAB_00108684;
        }
        lVar11 = devm_kmalloc(lVar10,(ulong)*puVar3 << 4,0xdc0);
        if (lVar11 == 0) goto LAB_0010871c;
        iVar7 = of_property_read_variable_u32_array
                          (uVar23,"qcom,ufs-bus-bw,num-paths",&local_78,1,0);
        if (iVar7 < 0) {
          puVar16 = &DAT_00121453;
LAB_00108684:
          _printk(puVar16);
          goto LAB_0010871c;
        }
        lVar14 = of_get_property(uVar23,"qcom,ufs-bus-bw,vectors-KBps",&local_80);
        if (lVar14 == 0) {
          puVar16 = &DAT_0011fe98;
          goto LAB_00108684;
        }
        if (*puVar3 != 0) {
          uVar8 = 0;
          uVar12 = (ulong)local_78 & 0xffffffff;
          do {
            puVar1 = (undefined4 *)(lVar11 + (long)(int)uVar8 * 0x10);
            *puVar1 = (int)uVar12;
            lVar15 = devm_kmalloc(lVar10,-(uVar12 >> 0x1f & 1) & 0xfffffff800000000 |
                                         (uVar12 & 0xffffffff) << 3,0xdc0);
            plVar28 = (long *)(puVar1 + 2);
            *plVar28 = lVar15;
            if (lVar15 == 0) {
              pcVar20 = "Error: Failed to alloc mem for vectors\n";
              goto LAB_00108714;
            }
            uVar12 = (ulong)local_78 & 0xffffffff;
            if (0 < (int)local_78) {
              lVar25 = 0;
              lVar15 = 0;
              do {
                iVar7 = (int)lVar15;
                lVar15 = lVar15 + 1;
                puVar2 = (uint *)(lVar14 + (long)(int)((iVar7 + uVar8 * (int)uVar12) * 2) * 4);
                uVar5 = *puVar2;
                uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
                *(uint *)(*plVar28 + lVar25) = uVar5 >> 0x10 | uVar5 << 0x10;
                uVar5 = puVar2[1];
                uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
                lVar4 = *plVar28 + lVar25;
                lVar25 = lVar25 + 8;
                *(uint *)(lVar4 + 4) = uVar5 >> 0x10 | uVar5 << 0x10;
                uVar12 = (ulong)(int)local_78;
              } while (lVar15 < (long)uVar12);
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < *puVar3);
        }
        pcVar20 = "ufs-ddr";
        *plVar13 = lVar11;
        *(long **)(lVar9 + 0x150) = plVar13;
        uVar12 = of_icc_get(lVar10,"ufs-ddr");
        puVar26 = (ulong *)(plVar13 + 2);
        *puVar26 = uVar12;
        if (uVar12 < 0xfffffffffffff001) {
          pcVar20 = "cpu-ufs";
          uVar12 = of_icc_get(lVar10,"cpu-ufs");
          puVar26 = (ulong *)(plVar13 + 3);
          *puVar26 = uVar12;
          if (0xfffffffffffff000 < uVar12) goto LAB_0010869c;
          lVar11 = *(long *)(*(long *)(lVar9 + 0x10) + 0x40);
          iVar7 = of_property_match_string
                            (*(undefined8 *)(lVar11 + 0x2e8),"qcom,bus-vector-names",&DAT_0012311b);
          if (iVar7 < 0) {
            _dev_err(lVar11,"%s: Invalid %s mode %d\n","ufs_qcom_get_bus_vote",&DAT_0012311b,iVar7);
          }
          *(int *)(lVar9 + 0x20) = iVar7;
          lVar11 = *(long *)(*(long *)(lVar9 + 0x10) + 0x40);
          iVar7 = of_property_match_string
                            (*(undefined8 *)(lVar11 + 0x2e8),"qcom,bus-vector-names",&DAT_00123697);
          if (iVar7 < 0) {
            _dev_err(lVar11,"%s: Invalid %s mode %d\n","ufs_qcom_get_bus_vote",&DAT_00123697,iVar7);
          }
          *(char **)(lVar9 + 0x30) = "max_bus_bw";
          *(int *)(lVar9 + 0x24) = iVar7;
          *(undefined2 *)(lVar9 + 0x38) = 0x1a4;
          *(code **)(lVar9 + 0x40) = show_ufs_to_mem_max_bus_bw;
          *(code **)(lVar9 + 0x48) = store_ufs_to_mem_max_bus_bw;
          iVar7 = device_create_file(lVar10);
          if (iVar7 != 0) {
            _dev_err(lVar10,"Error: (%d) Failed to create sysfs entries\n",iVar7);
          }
        }
        else {
LAB_0010869c:
          _dev_err(lVar10,"Error: (%d) failed getting %s path\n",uVar12,pcVar20);
          uVar12 = (ulong)(uint)*puVar26;
          if ((uint)*puVar26 != 0) goto LAB_00108320;
        }
      }
      uVar12 = readl(*param_1 + 0xe4);
      lVar10 = param_1[0x16];
      *(short *)(lVar9 + 0xa2) = (short)uVar12;
      *(byte *)(lVar9 + 0xa6) = (byte)(uVar12 >> 0x1c) & 0xf;
      *(ushort *)(lVar9 + 0xa4) = (ushort)(uVar12 >> 0x10) & 0xfff;
      if (*(byte *)(lVar10 + 0xa6) < 2) {
        lVar14 = param_1[8];
        lVar11 = platform_get_resource_byname(lVar14 + -0x10,0x200,"dev_ref_clk_ctrl_mem");
        if (lVar11 != 0) {
          uVar12 = devm_ioremap_resource(lVar14,lVar11);
          *(ulong *)(lVar10 + 0x98) = uVar12;
          if (uVar12 < 0xfffffffffffff001) {
            uVar22 = 0x20;
          }
          else {
            _dev_warn(lVar14,"%s: could not map dev_ref_clk_ctrl_mmio, err %ld\n",
                      "ufs_qcom_populate_ref_clk_ctrl",uVar12);
            uVar22 = 0x20;
            *(undefined8 *)(lVar10 + 0x98) = 0;
          }
          goto LAB_001087a8;
        }
      }
      else {
        uVar22 = 0x4000000;
        *(long *)(lVar10 + 0x98) = *param_1 + 0xdc;
LAB_001087a8:
        *(undefined4 *)(lVar10 + 0xbc) = uVar22;
      }
      if (*(byte *)(lVar9 + 0xa6) == 1) {
        uVar8 = 2;
      }
      else if (*(byte *)(lVar9 + 0xa6) < 4) {
        uVar8 = 3;
      }
      else {
        uVar8 = readl(**(long **)(lVar9 + 0x10) + 0xd0);
        uVar8 = uVar8 >> 4 & 7;
      }
      *(uint *)(lVar9 + 0x130) = uVar8;
      puVar24 = (undefined8 *)param_1[0x14d];
      *(code **)(lVar9 + 0x160) = ufs_qcom_vdd_hba_reg_notifier;
      devm_regulator_register_notifier(*puVar24,lVar9 + 0x160);
      iVar7 = ufs_qcom_phy_save_controller_version
                        (*(undefined8 *)(lVar9 + 8),*(undefined1 *)(lVar9 + 0xa6),
                         *(undefined2 *)(lVar9 + 0xa4),*(undefined2 *)(lVar9 + 0xa2));
      if (iVar7 == -0x205) {
        _printk(&DAT_00121eba,"ufs_qcom_init");
        goto LAB_00108388;
      }
      ufs_qcom_parse_reg_info(lVar9,"qcom,vddp-ref-clk",(long *)(lVar9 + 0x178));
      uVar8 = phy_init(*(undefined8 *)(lVar9 + 8));
      if (uVar8 != 0) {
        uVar12 = (ulong)uVar8;
        _dev_err(param_1[8],"%s: phy init failed, err %d\n","ufs_qcom_init",uVar12);
        goto LAB_00108320;
      }
      __mutex_init(lVar9 + 0x1a8,"&host->phy_mutex",&ufs_qcom_init___key);
      puVar24 = *(undefined8 **)(lVar9 + 0x178);
      if ((puVar24 == (undefined8 *)0x0) || (*(char *)((long)puVar24 + 0x11) != '\0')) {
LAB_001088a0:
        local_80 = (undefined8 *)((ulong)local_80 & 0xffffffff00000000);
        lVar10 = *(long *)((*(long **)(lVar9 + 0x10))[8] + 0x2e8);
        if (lVar10 != 0) {
          *(undefined4 *)(lVar9 + 0x134) = *(undefined4 *)(lVar9 + 0x130);
          puVar24 = (undefined8 *)(lVar9 + 0x144);
          *(undefined4 *)(lVar9 + 0x138) = *(undefined4 *)(lVar9 + 0x130);
          *(undefined8 *)(lVar9 + 0x13c) = 0x400000004;
          *puVar24 = 0x100000002;
          if (4 < *(byte *)(lVar9 + 0xa6)) {
            uVar8 = readl(**(long **)(lVar9 + 0x10) + 0x284c);
            if ((*(byte *)(lVar9 + 0xa6) == 5) && ((uVar8 & 0xc0) != 0)) {
              uVar22 = 1;
            }
            else {
              if ((*(byte *)(lVar9 + 0xa6) < 6) || ((uVar8 & 0xc0) == 0)) goto LAB_00108944;
              uVar22 = 2;
            }
            *(undefined4 *)puVar24 = uVar22;
            *(undefined4 *)(lVar9 + 0x148) = 2;
          }
LAB_00108944:
          of_property_read_variable_u32_array(lVar10,"limit-tx-hs-gear",lVar9 + 0x134,1,0);
          of_property_read_variable_u32_array(lVar10,"limit-rx-hs-gear",lVar9 + 0x138,1,0);
          of_property_read_variable_u32_array
                    (lVar10,"limit-tx-pwm-gear",(undefined8 *)(lVar9 + 0x13c),1,0);
          of_property_read_variable_u32_array(lVar10,"limit-rx-pwm-gear",lVar9 + 0x140,1,0);
          of_property_read_variable_u32_array(lVar10,"limit-rate",puVar24,1,0);
          of_property_read_variable_u32_array
                    (lVar10,"limit-phy-submode",(undefined4 *)(lVar9 + 0x148),1,0);
          of_property_read_variable_u32_array(lVar10,"ufs-dev-types",&local_80,1,0);
          lVar10 = of_find_property(lVar10,"limit-rate-ufs3",0);
          if ((lVar10 != 0) || ((int)local_80 != 0)) {
            local_78 = (undefined8 *)0x0;
            lVar10 = *(long *)(*(long *)(lVar9 + 0x10) + 0x40);
            uVar23 = *(undefined8 *)(lVar10 + 0x2e8);
            uVar12 = nvmem_cell_get(lVar10,"ufs_dev");
            if (uVar12 < 0xfffffffffffff001) {
              pbVar18 = (byte *)nvmem_cell_read(uVar12,&local_78);
              if (pbVar18 < (byte *)0xfffffffffffff001) {
                lVar10 = of_find_property(uVar23,"qcom,ufs-dev-revert",0);
                uVar8 = (uint)*pbVar18;
                if (lVar10 != 0) {
                  uVar8 = (uint)(uVar8 == 0);
                }
                *(uint *)(lVar9 + 0x148) = uVar8;
                *(bool *)(lVar9 + 0x159) = uVar8 != 0;
                uVar19 = *(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40);
                if (uVar8 == 0) {
                  _dev_info(uVar19,"(%s) UFS device is 2.x, phy_submode = %d\n",
                            "ufs_qcom_read_nvmem_cell");
                }
                else {
                  _dev_info(uVar19,"(%s) UFS device is 3.x, phy_submode = %d\n",
                            "ufs_qcom_read_nvmem_cell");
                  lVar10 = of_find_property(uVar23,"limit-rate-ufs3",0);
                  if (lVar10 != 0) {
                    *(undefined4 *)puVar24 = 1;
                  }
                }
                kfree(pbVar18);
              }
              else {
                _dev_err(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40),
                         "(%s) Failed to read from nvmem\n","ufs_qcom_read_nvmem_cell");
              }
              nvmem_cell_put(uVar12);
            }
            else {
              _dev_err(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40),
                       "(%s) Failed to get nvmem cell\n","ufs_qcom_read_nvmem_cell");
            }
          }
        }
        local_78 = (undefined8 *)0x0;
        local_80 = (undefined8 *)0x0;
        ufs_qcom_parse_reg_info(lVar9,"qcom,vccq-parent",&local_78);
        ufs_qcom_parse_reg_info(lVar9,"qcom,vccq2-parent",&local_80);
        if ((local_78 == (undefined8 *)0x0) || (local_80 == (undefined8 *)0x0)) {
          puVar24 = local_78;
          if (local_78 == (undefined8 *)0x0) {
            puVar24 = local_80;
          }
          *(undefined8 **)(lVar9 + 0x180) = puVar24;
          if (puVar24 != (undefined8 *)0x0) goto LAB_00108a88;
          _dev_info(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40),
                    "vccq or vccq2 parent node is not provided\n");
          *(undefined8 *)(lVar9 + 0x180) = 0;
LAB_00108acc:
          plVar13 = (long *)param_1[0x14e];
          if (plVar13 != param_1 + 0x14e) {
            do {
              pcVar20 = (char *)plVar13[3];
              iVar7 = strcmp(pcVar20,"core_clk_unipro");
              if (iVar7 == 0) {
                *(undefined1 *)((long)plVar13 + 0x2c) = 1;
                puVar24 = (undefined8 *)(lVar9 + 0x2d8);
LAB_00108b08:
                *puVar24 = plVar13;
              }
              else {
                iVar7 = strcmp(pcVar20,"ref_clk");
                puVar24 = (undefined8 *)(lVar9 + 0x2d0);
                if (iVar7 == 0) goto LAB_00108b08;
              }
              plVar13 = (long *)*plVar13;
            } while (plVar13 != param_1 + 0x14e);
          }
          uVar23 = *(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40);
          uVar12 = devm_clk_get(uVar23,"rx_lane0_sync_clk");
          if (uVar12 < 0xfffffffffffff001) {
            *(ulong *)(lVar9 + 0x70) = uVar12;
LAB_00108b6c:
            uVar17 = devm_clk_get(uVar23,"tx_lane0_sync_clk");
            if (0xfffffffffffff000 < uVar17) {
              if (((int)uVar17 != -0x205) &&
                 (_dev_err(uVar23,"failed to get %s err %d\n","tx_lane0_sync_clk",
                           uVar17 & 0xffffffff), (int)uVar17 == 0)) goto LAB_00108b8c;
              pcVar20 = "%s: failed to get tx_lane0_sync_clk, err %d\n";
LAB_00108fd4:
              pcVar21 = "ufs_qcom_init_lane_clks";
LAB_00108fdc:
              _dev_err(uVar23,pcVar20,pcVar21,uVar17 & 0xffffffff);
              uVar12 = uVar17 & 0xffffffff;
              iVar7 = (int)uVar17;
              goto joined_r0x00108fec;
            }
            *(ulong *)(lVar9 + 0x78) = uVar17;
LAB_00108b8c:
            if (1 < *(uint *)(*(long *)(lVar9 + 0x10) + 0xa84)) {
              uVar17 = devm_clk_get(uVar23,"rx_lane1_sync_clk");
              if (uVar17 < 0xfffffffffffff001) {
                *(ulong *)(lVar9 + 0x80) = uVar17;
              }
              else if (((int)uVar17 == -0x205) ||
                      (_dev_err(uVar23,"failed to get %s err %d\n","rx_lane1_sync_clk",
                                uVar17 & 0xffffffff), (int)uVar17 != 0)) {
                pcVar20 = "%s: failed to get rx_lane1_sync_clk, err %d\n";
                goto LAB_00108fd4;
              }
              uVar17 = devm_clk_get(uVar23,"tx_lane1_sync_clk");
              if (uVar17 < 0xfffffffffffff001) {
LAB_00108bec:
                *(ulong *)(lVar9 + 0x88) = uVar17;
                goto LAB_00108bf0;
              }
              if ((int)uVar17 != -0x205) {
                if ((int)uVar17 != -2) {
                  pcVar20 = "failed to get %s err %d\n";
                  pcVar21 = "tx_lane1_sync_clk";
                  goto LAB_00108fdc;
                }
                uVar17 = 0;
                goto LAB_00108bec;
              }
              uVar12 = uVar17 & 0xffffffff;
              goto LAB_00108ff0;
            }
          }
          else {
            iVar7 = (int)uVar12;
            if ((iVar7 != -0x205) &&
               (_dev_err(uVar23,"failed to get %s err %d\n","rx_lane0_sync_clk",uVar12 & 0xffffffff)
               , iVar7 == 0)) goto LAB_00108b6c;
            _dev_err(uVar23,"%s: failed to get rx_lane0_sync_clk, err %d\n",
                     "ufs_qcom_init_lane_clks",uVar12 & 0xffffffff);
joined_r0x00108fec:
            if (iVar7 != 0) {
LAB_00108ff0:
              if (*(long *)(lVar9 + 0x180) != 0) {
                ufs_qcom_disable_vreg();
              }
              goto LAB_00109000;
            }
          }
LAB_00108bf0:
          ufs_qcom_parse_pm_levels(param_1);
          ufs_qcom_parse_g4_workaround_flag(lVar9);
          ufs_qcom_parse_lpm(lVar9);
          if (*(char *)(lVar9 + 0x14c) != '\0') {
            pm_runtime_forbid(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40));
          }
          ufs_qcom_parse_wb(lVar9);
          ufs_qcom_parse_pbl_rst_workaround_flag(lVar9);
          ufs_qcom_parse_broken_ahit_workaround_flag(lVar9);
          ufs_qcom_set_caps(param_1);
          ufs_qcom_advertise_quirks(param_1);
          iVar7 = ufs_qcom_shared_ice_init(param_1);
          if (iVar7 != 0) {
            _dev_err(param_1[8],"Shared ICE Init failed, ret=%d\n",iVar7);
          }
          uVar17 = ufs_qcom_ice_init(lVar9);
          uVar12 = uVar17 & 0xffffffff;
          if ((int)uVar17 == 0) {
            ufshcd_qti_hba_init_crypto_capabilities(param_1);
            ufs_qcom_set_bus_vote(param_1,1);
            if ((((int)param_1[0x153] == 4) || ((int)param_1[0x153] == 1)) &&
               ((*(int *)((long)param_1 + 0xa9c) == 4 || (*(int *)((long)param_1 + 0xa9c) == 1)))) {
              ufs_qcom_dev_ref_clk_ctrl(lVar9,1);
            }
            if (*(uint *)(param_1[8] + 0x2fc) < 2) {
              (&ufs_qcom_hosts)[*(uint *)(param_1[8] + 0x2fc)] = lVar9;
            }
            *(undefined2 *)(lVar9 + 0xc4) = 0x250b;
            iVar7 = ufs_qcom_testbus_config(lVar9);
            if (iVar7 != 0) {
              _dev_warn(lVar27,"%s: failed to configure the testbus %d\n","ufs_qcom_init",iVar7);
            }
            ufs_qcom_init_sysfs(param_1);
            iVar7 = ufs_qcom_get_host_id(param_1);
            snprintf((char *)&local_70,5,"ufs%d",iVar7);
            uVar12 = devm_thermal_of_cooling_device_register
                               (lVar27,*(undefined8 *)(lVar27 + 0x2e8),&local_70,lVar27,
                                &ufs_thermal_ops);
            *(ulong *)(lVar9 + 0x1e0) = uVar12;
            if (uVar12 < 0xfffffffffffff001) {
              *(undefined8 *)(lVar9 + 0x1e8) = 0;
            }
            else {
              _dev_warn(lVar27,"Thermal mitigation registration failed: %d\n",uVar12);
            }
            ufs_qcom_save_host_ptr(param_1);
            ufs_qcom_populate_available_cpus(param_1);
            ufs_qcom_qos_init(param_1);
            ufs_qcom_parse_irq_affinity(param_1);
            lVar10 = param_1[0x16];
            *(long *)(lVar10 + 0xc50) = lVar10 + 0xc50;
            *(long *)(lVar10 + 0xc58) = lVar10 + 0xc50;
            *(char **)(lVar10 + 0x7b0) = "gear1-4";
            *(char **)(lVar10 + 0xc48) = "gear5";
            get_storage_info(param_1);
            if (storage_mfrid == 0x1ad) {
              uVar17 = pixel_init(param_1);
              uVar12 = uVar17 & 0xffffffff;
              if ((int)uVar17 != 0) goto LAB_00108324;
              pixel_init_manual_gc(param_1);
            }
            lVar10 = ipc_log_context_create(10,"ufs-qcom",0);
            *(long *)(lVar9 + 0x2b0) = lVar10;
            if (lVar10 == 0) {
              _dev_warn(lVar27,"IPC Log init - failed\n");
              uVar12 = msm_minidump_enabled();
            }
            else {
              uVar12 = msm_minidump_enabled();
            }
            if ((uVar12 & 1) != 0) {
              lVar27 = (long)iVar7;
              ufs_qcom_register_minidump(lVar9,0xed0,"UFS_QHOST",lVar27);
              ufs_qcom_register_minidump(param_1,0x14d8,"UFS_HBA",lVar27);
              ufs_qcom_register_minidump(param_1[7],0x9b0,"UFS_SHOST",lVar27);
              *(undefined4 *)(lVar9 + 0xc78) = 0x7ffffffe;
              *(code **)(lVar9 + 0xc68) = ufs_qcom_panic_handler;
              iVar7 = atomic_notifier_chain_register(&panic_notifier_list,lVar9 + 0xc68);
              if (iVar7 != 0) {
                _dev_err(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40),
                         "Fail to register UFS panic notifier\n");
              }
            }
            uVar12 = 0;
            goto LAB_00108324;
          }
          goto LAB_00108320;
        }
        puVar24 = local_80;
        if (*(char *)(lVar9 + 0x159) != '\0') {
          puVar24 = local_78;
        }
LAB_00108a88:
        *(undefined8 **)(lVar9 + 0x180) = puVar24;
        if (*(char *)((long)puVar24 + 0x11) != '\0') goto LAB_00108acc;
        iVar7 = regulator_count_voltages(*puVar24);
        if (((iVar7 < 1) ||
            (uVar12 = regulator_set_load(*puVar24,*(undefined4 *)((long)puVar24 + 0x14)),
            (int)uVar12 == 0)) && (uVar12 = regulator_enable(*puVar24), (int)uVar12 == 0)) {
          *(undefined1 *)((long)puVar24 + 0x11) = 1;
          goto LAB_00108acc;
        }
        uVar12 = uVar12 & 0xffffffff;
        _dev_err(lVar27,"%s: failed to enable %s err=%d\n","ufs_qcom_init",
                 *(undefined8 *)(*(long *)(lVar9 + 0x180) + 8),uVar12);
LAB_00109000:
        if (*(long *)(lVar9 + 0x178) != 0) {
          ufs_qcom_disable_vreg();
        }
      }
      else {
        iVar7 = regulator_count_voltages(*puVar24);
        if (((iVar7 < 1) ||
            (uVar12 = regulator_set_load(*puVar24,*(undefined4 *)((long)puVar24 + 0x14)),
            (int)uVar12 == 0)) && (uVar12 = regulator_enable(*puVar24), (int)uVar12 == 0)) {
          *(undefined1 *)((long)puVar24 + 0x11) = 1;
          goto LAB_001088a0;
        }
        uVar12 = uVar12 & 0xffffffff;
        _dev_err(lVar27,"%s: failed enabling ref clk supply: %d\n","ufs_qcom_init",uVar12);
      }
      phy_exit(*(undefined8 *)(lVar9 + 8));
    }
    else if ((int)uVar12 == -0x205) {
LAB_00108388:
      uVar12 = 0xfffffdfb;
    }
    else {
      uVar12 = uVar12 & 0xffffffff;
      _dev_err(lVar27,"failed to acquire reset gpio: %d\n",uVar12);
    }
  }
  else {
    pcVar20 = "Failed to get reset control\n";
LAB_00108314:
    uVar12 = dev_err_probe(lVar27,uVar12,pcVar20);
    uVar12 = uVar12 & 0xffffffff;
  }
LAB_00108320:
  param_1[0x16] = 0;
LAB_00108324:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12 & 0xffffffff;
}



//------------------------------------------------------------
// ufs_qcom_exit @ 001091f4 size=148
// signature: undefined ufs_qcom_exit(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_exit(long param_1)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x109288);
    (*pcVar1)();
  }
  lVar4 = *(long *)(param_1 + 0xb0);
  ufs_qcom_disable_lane_clks(lVar4);
  lVar6 = *(long *)(param_1 + 0xb0);
  uVar5 = *(undefined8 *)(lVar6 + 8);
  mutex_lock(lVar6 + 0x1a8);
  if ((*(char *)(lVar6 + 0x1a0) != '\0') && (iVar2 = phy_power_off(uVar5), iVar2 == 0)) {
    *(undefined1 *)(lVar6 + 0x1a0) = 0;
  }
  mutex_unlock(lVar6 + 0x1a8);
  phy_exit(*(undefined8 *)(lVar4 + 8));
  uVar3 = msm_minidump_enabled();
  if ((uVar3 & 1) != 0) {
    atomic_notifier_chain_unregister(&panic_notifier_list,lVar4 + 0xc68);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_get_ufs_hci_version @ 0010928c size=36
// signature: undefined ufs_qcom_get_ufs_hci_version(void)
// callers: []
//------------------------------------------------------------

undefined4 ufs_qcom_get_ufs_hci_version(long param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1092b0);
    (*pcVar1)();
  }
  uVar2 = 0x110;
  if (*(char *)(*(long *)(param_1 + 0xb0) + 0xa6) != '\x01') {
    uVar2 = 0x200;
  }
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_clk_scale_notify @ 001092b4 size=984
// signature: undefined ufs_qcom_clk_scale_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001093cc) */

int ufs_qcom_clk_scale_notify(long *param_1,uint param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  char *pcVar6;
  undefined8 uVar7;
  long lVar8;
  byte *pbVar9;
  long *plVar10;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10968c);
    (*pcVar1)();
  }
  lVar8 = param_1[0x16];
  uVar3 = readl(*param_1 + 0x34);
  if ((uVar3 & 1) == 0) {
    iVar2 = 0;
    goto LAB_0010964c;
  }
  if (param_3 == 0) {
    if (*(char *)((long)param_1 + 0x13ac) != '\0') {
      lVar5 = param_1[0x16];
      iVar2 = *(int *)(lVar5 + 0xc64);
      while (iVar2 != 0) {
        usleep_range_state(10000,20000,2);
        iVar2 = *(int *)(lVar5 + 0xc64);
      }
    }
    iVar2 = ufshcd_uic_hibern8_enter(param_1);
    if (iVar2 != 0) goto LAB_0010964c;
    pbVar9 = (byte *)param_1[0x16];
    if ((param_2 & 1) == 0) {
      local_5c = 0;
      iVar2 = 0;
      if (((*pbVar9 & 1) != 0) &&
         (iVar2 = ufshcd_dme_get_attr(param_1,0xd0020000,&local_5c,0), iVar2 == 0)) {
        if ((local_5c >> 8 & 1) == 0) {
          iVar2 = 0;
        }
        else {
          local_5c = local_5c & 0xfffffeff;
          iVar2 = ufshcd_dme_set_attr(param_1,0xd0020000,0,local_5c,0);
        }
      }
      cancel_dwork_unvote_cpufreq(param_1);
    }
    else {
      if ((*pbVar9 & 1) == 0) {
        iVar2 = 0;
      }
      else {
        __ufs_qcom_cfg_timers
                  (param_1,*(undefined4 *)(pbVar9 + 0x50),*(undefined4 *)(pbVar9 + 0x60),
                   *(undefined4 *)(pbVar9 + 0x68),0,1);
        iVar2 = ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode(param_1);
      }
      if ((*(char *)(lVar8 + 0x298) == '\0') && (*(int *)(lVar8 + 0x2e4) == 0)) {
        *(undefined4 *)(lVar8 + 0x208) = 0;
        queue_delayed_work_on(0x20,*(undefined8 *)(*(long *)(lVar8 + 0x1d8) + 0x10),lVar8 + 0x210,8)
        ;
      }
    }
    if (iVar2 != 0) goto LAB_001095f0;
LAB_0010951c:
    iVar2 = 0;
    *(uint *)(lVar8 + 500) = param_2 & 1;
    lVar5 = *(long *)(lVar8 + 0x2b0);
    if ((param_2 & 1) == 0) goto LAB_00109530;
LAB_00109600:
    if ((lVar5 == 0) || (*(char *)(lVar8 + 0x2b8) == '\0')) goto LAB_0010964c;
    lVar8 = tpidr_el1;
    pcVar6 = ",%d,^,%d,%d\n";
  }
  else {
    if ((param_2 & 1) == 0) {
      pbVar9 = (byte *)param_1[0x16];
      uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
      param_1[0x171] = 10;
      _raw_spin_unlock_irqrestore(*(undefined8 *)(param_1[7] + 0x38),uVar4);
      if ((*pbVar9 & 1) == 0) goto LAB_001093c4;
      __ufs_qcom_cfg_timers
                (param_1,*(undefined4 *)(pbVar9 + 0x50),*(undefined4 *)(pbVar9 + 0x60),
                 *(undefined4 *)(pbVar9 + 0x68),0,0);
      for (plVar10 = (long *)param_1[0x14e]; plVar10 != param_1 + 0x14e; plVar10 = (long *)*plVar10)
      {
        uVar3 = plVar10[2];
        if (((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) &&
           (iVar2 = strcmp((char *)plVar10[3],"core_clk_unipro"), iVar2 == 0)) {
          uVar4 = clk_get_rate(uVar3);
          iVar2 = (int)uVar4;
          if (iVar2 == 100000000) {
            uVar4 = 100;
            uVar7 = 4;
          }
          else if (iVar2 == 75000000) {
            uVar4 = 0x4b;
            uVar7 = 3;
          }
          else {
            if (iVar2 != 37500000) goto LAB_001095ac;
            uVar4 = 0x26;
            uVar7 = 2;
          }
          iVar2 = ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div(param_1,uVar4,uVar7,0);
          if (iVar2 == 0) goto LAB_001094e8;
          goto LAB_001095f0;
        }
      }
      uVar4 = 0;
LAB_001095ac:
      _dev_err(param_1[8],"unipro curr_freq=%u entry missing\n",uVar4);
      iVar2 = -0x16;
    }
    else {
      uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
      param_1[0x171] = 0x32;
      _raw_spin_unlock_irqrestore(*(undefined8 *)(param_1[7] + 0x38),uVar4);
LAB_001093c4:
      iVar2 = 0;
LAB_001094e8:
      if (lVar8 != -0x50) {
        __ufs_qcom_cfg_timers
                  (param_1,*(undefined4 *)(lVar8 + 0x50),*(undefined4 *)(lVar8 + 0x60),
                   *(undefined4 *)(lVar8 + 0x68),0,0);
        ufs_qcom_update_bus_bw_vote(lVar8);
        ufshcd_uic_hibern8_exit(param_1);
        goto LAB_0010951c;
      }
    }
LAB_001095f0:
    ufshcd_uic_hibern8_exit(param_1);
    lVar5 = *(long *)(lVar8 + 0x2b0);
    if ((param_2 & 1) != 0) goto LAB_00109600;
LAB_00109530:
    if ((lVar5 == 0) || (*(char *)(lVar8 + 0x2b8) == '\0')) goto LAB_0010964c;
    lVar8 = tpidr_el1;
    pcVar6 = ",%d,v,%d,%d\n";
  }
  ipc_log_string(lVar5,pcVar6,*(undefined4 *)(&cpu_number + lVar8),param_3,iVar2);
LAB_0010964c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ufs_qcom_setup_clocks @ 00109734 size=1252
// signature: undefined ufs_qcom_setup_clocks(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_setup_clocks(long param_1,uint param_2,int param_3)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  char *pcVar6;
  char *pcVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x109c18);
    (*pcVar2)();
  }
  lVar8 = *(long *)(param_1 + 0xb0);
  if (lVar8 == 0) {
    return 0;
  }
  uVar9 = *(undefined8 *)(lVar8 + 8);
  if (param_3 == 1) {
    if ((param_2 & 1) == 0) {
      lVar5 = lVar8;
      if ((*(uint *)(param_1 + 0x54) | 2) == 2) {
        ufs_qcom_phy_set_src_clk_h8_enter(uVar9);
        ufs_qcom_disable_lane_clks(lVar8);
        lVar5 = *(long *)(param_1 + 0xb0);
        if (lVar5 != 0) goto LAB_001099a0;
      }
      else {
LAB_001099a0:
        iVar3 = __ufs_qcom_set_bus_vote(lVar5,*(undefined4 *)(lVar5 + 0x20));
        if (iVar3 != 0) {
          uVar9 = *(undefined8 *)(param_1 + 0x40);
          pcVar6 = "%s: set bus vote failed %d\n";
          pcVar7 = "ufs_qcom_set_bus_vote";
LAB_00109c08:
          _dev_err(uVar9,pcVar6,pcVar7,iVar3);
          return iVar3;
        }
      }
      iVar3 = ufs_qcom_unvote_qos_all(param_1);
      idle_start = ktime_get();
      if (iVar3 != 0) goto LAB_00109aa4;
    }
    else {
      lVar5 = lVar8 + 0x1a8;
      mutex_lock(lVar5);
      if (*(char *)(lVar8 + 0x1a0) == '\0') {
        iVar3 = phy_power_on(uVar9);
        if (iVar3 != 0) {
          mutex_unlock(lVar5);
          uVar9 = *(undefined8 *)(param_1 + 0x40);
          pcVar6 = "%s: phy power on failed, ret = %d\n";
          goto LAB_00109c00;
        }
        *(undefined1 *)(lVar8 + 0x1a0) = 1;
      }
      mutex_unlock(lVar5);
      if ((((*(int *)(param_1 + 0xa98) == 4) || (*(int *)(param_1 + 0xa98) == 1)) &&
          ((*(int *)(param_1 + 0xa9c) == 4 || (*(int *)(param_1 + 0xa9c) == 1)))) &&
         ((*(long *)(lVar8 + 0x98) != 0 && (*(char *)(lVar8 + 0xa0) != '\x01')))) {
        uVar4 = readl_relaxed();
        writel_relaxed(*(uint *)(lVar8 + 0xbc) | uVar4,*(undefined8 *)(lVar8 + 0x98));
        readl(*(undefined8 *)(lVar8 + 0x98));
        usleep_range_state(0x32,0x3c,2);
        *(undefined1 *)(lVar8 + 0xa0) = 1;
      }
      lVar5 = ktime_get();
      idle_time = (lVar5 - idle_start) / 1000000 + idle_time;
      lVar5 = ktime_get();
      DAT_001253e8 = (lVar5 - idle_start) / 1000000 + DAT_001253e8;
    }
    iVar3 = 0;
    *(uint *)(lVar8 + 0x1f8) = param_2 & 1;
    lVar5 = *(long *)(lVar8 + 0x2b0);
  }
  else {
    if (param_3 != 0) {
LAB_00109964:
      iVar3 = 0;
      lVar5 = *(long *)(lVar8 + 0x2b0);
      goto joined_r0x001099d8;
    }
    bVar1 = (byte)param_2 & 1;
    if ((param_2 & 1) == 0) {
      if (*(int *)(param_1 + 0x54) == 1) goto LAB_00109964;
      if (*(char *)(param_1 + 0x13ac) != '\0') {
        iVar3 = *(int *)(lVar8 + 0xc64);
        while (iVar3 != 0) {
          usleep_range_state(10000,20000,2);
          iVar3 = *(int *)(lVar8 + 0xc64);
        }
      }
      uVar9 = *(undefined8 *)(*(long *)(lVar8 + 0x2d8) + 0x10);
      clk_disable(uVar9);
      clk_unprepare(uVar9);
      *(byte *)(*(long *)(lVar8 + 0x2d8) + 0x2d) = bVar1;
      if ((*(char *)(lVar8 + 0xc80) != '\0') && (*(long *)(lVar8 + 0xc88) != 0)) {
        *(undefined8 *)(lVar8 + 0xc88) = 0;
      }
      lVar10 = *(long *)(param_1 + 0xb0);
      lVar5 = lVar10 + 0x1a8;
      uVar9 = *(undefined8 *)(lVar10 + 8);
      mutex_lock(lVar5);
      if (*(char *)(lVar10 + 0x1a0) != '\0') {
        iVar3 = phy_power_off(uVar9);
        if (iVar3 != 0) {
          mutex_unlock(lVar5);
          uVar9 = *(undefined8 *)(param_1 + 0x40);
          pcVar6 = "%s: phy power off failed, ret=%d\n";
          goto LAB_00109c00;
        }
        *(undefined1 *)(lVar10 + 0x1a0) = 0;
      }
      mutex_unlock(lVar5);
      ufs_qcom_dev_ref_clk_ctrl(lVar8,0);
      uVar9 = *(undefined8 *)(*(long *)(lVar8 + 0x2d0) + 0x10);
      clk_disable(uVar9);
      clk_unprepare(uVar9);
      iVar3 = 0;
      *(byte *)(*(long *)(lVar8 + 0x2d0) + 0x2d) = bVar1;
    }
    else {
      iVar3 = *(int *)(lVar8 + 0x28);
      if (iVar3 == *(int *)(lVar8 + 0x20)) {
        ufs_qcom_update_bus_bw_vote(lVar8);
      }
      iVar3 = __ufs_qcom_set_bus_vote(lVar8,iVar3);
      if (iVar3 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: set bus vote failed %d\n",
                 "ufs_qcom_set_bus_vote",iVar3);
      }
      if (*(int *)(param_1 + 0x54) == 2) {
        iVar3 = ufs_qcom_enable_lane_clks(lVar8);
        if (iVar3 != 0) {
          uVar9 = *(undefined8 *)(param_1 + 0x40);
          pcVar6 = "%s: enable lane clks failed, ret=%d\n";
LAB_00109c00:
          pcVar7 = "ufs_qcom_setup_clocks";
          goto LAB_00109c08;
        }
        ufs_qcom_phy_set_src_clk_h8_exit(uVar9);
        iVar3 = 0;
      }
      if (*(char *)(*(long *)(lVar8 + 0x2d0) + 0x2d) == '\0') {
        uVar9 = *(undefined8 *)(*(long *)(lVar8 + 0x2d0) + 0x10);
        iVar3 = clk_prepare(uVar9);
        if (iVar3 == 0) {
          iVar3 = clk_enable(uVar9);
          if (iVar3 == 0) {
            *(byte *)(*(long *)(lVar8 + 0x2d0) + 0x2d) = bVar1;
            goto LAB_00109804;
          }
          clk_unprepare(uVar9);
        }
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: Fail dev-ref-clk enabled, ret=%d\n",
                 "ufs_qcom_setup_clocks",iVar3);
      }
LAB_00109804:
      if (*(char *)(*(long *)(lVar8 + 0x2d8) + 0x2d) == '\0') {
        uVar9 = *(undefined8 *)(*(long *)(lVar8 + 0x2d8) + 0x10);
        iVar3 = clk_prepare(uVar9);
        if (iVar3 == 0) {
          iVar3 = clk_enable(uVar9);
          if (iVar3 == 0) {
            *(byte *)(*(long *)(lVar8 + 0x2d8) + 0x2d) = bVar1;
            lVar5 = *(long *)(lVar8 + 0x2b0);
            goto joined_r0x001099d8;
          }
          clk_unprepare(uVar9);
        }
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: Fail core-unipro-clk enabled, ret=%d\n",
                 "ufs_qcom_setup_clocks",iVar3);
        lVar5 = *(long *)(lVar8 + 0x2b0);
        goto joined_r0x001099d8;
      }
    }
LAB_00109aa4:
    lVar5 = *(long *)(lVar8 + 0x2b0);
  }
joined_r0x001099d8:
  if ((lVar5 != 0) && (*(char *)(lVar8 + 0x2b8) != '\0')) {
    lVar8 = tpidr_el1;
    ipc_log_string(lVar5,",%d,#,%d,%d,%d\n",*(undefined4 *)(&cpu_number + lVar8),param_3,param_2 & 1
                   ,iVar3);
  }
  return iVar3;
}



//------------------------------------------------------------
// ufs_qcom_hce_enable_notify @ 00109cc0 size=1880
// signature: undefined ufs_qcom_hce_enable_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010a0e0) */
/* WARNING: Removing unreachable block (ram,0x0010a010) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ufs_qcom_hce_enable_notify(long param_1,int param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  int *piVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  uint *puVar15;
  uint *puVar16;
  ulong uVar17;
  undefined8 uVar18;
  ulong uVar19;
  long lVar20;
  char *pcVar21;
  long *plVar22;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10a40c);
    (*pcVar3)();
  }
  puVar16 = *(uint **)(param_1 + 0xb0);
  if (param_2 != 1) {
    if (param_2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: invalid status %d\n",
               "ufs_qcom_hce_enable_notify",param_2);
      iVar4 = -0x16;
      lVar7 = *(long *)(puVar16 + 0xac);
      goto joined_r0x0010a29c;
    }
    plVar22 = *(long **)(param_1 + 0xa70);
    puVar15 = puVar16;
    if (plVar22 != (long *)(param_1 + 0xa70)) {
      do {
        pcVar21 = (char *)plVar22[3];
        iVar4 = strcmp(pcVar21,"ref_clk");
        if (iVar4 != 0) {
          iVar4 = strcmp(pcVar21,"core_clk_ice");
          if (((iVar4 == 0) || (iVar4 = strcmp(pcVar21,"core_clk_ice_hw_ctl"), iVar4 == 0)) ||
             ((5 < *(byte *)((long)puVar16 + 0xa6) &&
              (iVar4 = strcmp(pcVar21,"core_clk"), iVar4 == 0)))) {
            uVar8 = 2;
          }
          else {
            uVar8 = 3;
          }
          qcom_clk_set_flags(plVar22[2],uVar8);
          qcom_clk_set_flags(plVar22[2],1);
          qcom_clk_set_flags(plVar22[2],5);
        }
        plVar22 = (long *)*plVar22;
      } while (plVar22 != (long *)(param_1 + 0xa70));
      puVar15 = *(uint **)(param_1 + 0xb0);
    }
    uVar8 = *(undefined8 *)(puVar15 + 2);
    uVar9 = 0xc;
    if (puVar15[0x51] == 2) {
      uVar9 = 0xd;
    }
    uVar6 = 0;
    if (3 < *(byte *)((long)puVar15 + 0xa6)) {
      uVar6 = puVar15[0x52];
    }
    phy_set_mode_ext(uVar8,uVar9,uVar6);
    lVar20 = *(long *)(param_1 + 0xb0);
    lVar7 = lVar20 + 0x1a8;
    uVar18 = *(undefined8 *)(lVar20 + 8);
    mutex_lock(lVar7);
    if (*(char *)(lVar20 + 0x1a0) == '\0') {
      iVar4 = phy_power_on(uVar18);
      if (iVar4 == 0) {
        *(undefined1 *)(lVar20 + 0x1a0) = 1;
        goto LAB_00109ef8;
      }
      mutex_unlock(lVar7);
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: phy power on failed, ret = %d\n",
               "ufs_qcom_power_up_sequence",iVar4);
    }
    else {
LAB_00109ef8:
      mutex_unlock(lVar7);
      iVar4 = phy_calibrate(uVar8);
      if (iVar4 == 0) {
        plVar22 = *(long **)(puVar15 + 4);
        uVar6 = *puVar15;
        uVar5 = readl(*plVar22 + 0xdc);
        writel(uVar5 & 0xfffffffe | uVar6 & 1,*plVar22 + 0xdc);
        if (4 < *(byte *)((long)puVar15 + 0xa6)) {
          plVar22 = *(long **)(puVar15 + 4);
          uVar6 = readl(*plVar22 + 0xd8);
          writel(uVar6 & 0xffffffdf,*plVar22 + 0xd8);
          plVar22 = *(long **)(puVar15 + 4);
          uVar6 = readl(*plVar22 + 0xd8);
          writel(uVar6 & 0xfffffffe,*plVar22 + 0xd8);
        }
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: Failed to calibrate PHY %d\n",
                 "ufs_qcom_power_up_sequence",iVar4);
      }
    }
    iVar4 = ufs_qcom_enable_lane_clks(puVar16);
    if (iVar4 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: enable lane clks failed,\tret=%d\n",
               "ufs_qcom_hce_enable_notify",iVar4);
    }
    ufs_qcom_ice_enable(puVar16);
    lVar7 = *(long *)(puVar16 + 0xac);
    goto joined_r0x0010a29c;
  }
  if (((byte)*puVar16 >> 4 & 1) != 0) {
    uVar6 = puVar16[0xb2];
    if (uVar6 == 2) {
      plVar22 = *(long **)(puVar16 + 4);
      local_80 = 0;
      local_78 = 0;
      if (plVar22 == (long *)0x0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10a4b4);
        (*pcVar3)();
      }
      iVar4 = of_property_read_variable_u32_array
                        (*(undefined8 *)(plVar22[0x16] + 0x2c0),"num-core",&local_80,4,4);
      if (iVar4 < 0) {
        if (iVar4 != 0) goto LAB_0010a3d8;
      }
      else {
        writel(2,*plVar22 + 0x260c);
        writel((uint)local_80 | local_80._4_4_ << 8 | (int)local_78 << 0x10 | local_78._4_4_ << 0x18
               ,*plVar22 + 0x2664);
      }
    }
    else {
      if (uVar6 != 1) {
        if (uVar6 == 0) {
          plVar22 = *(long **)(puVar16 + 4);
          local_80 = local_80 & 0xffffffff00000000;
          if (plVar22 == (long *)0x0) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10a4b0);
            (*pcVar3)();
          }
          iVar4 = of_property_read_variable_u32_array
                            (*(undefined8 *)(plVar22[0x16] + 0x2c0),"rx-alloc-percent",&local_80,1,0
                            );
          if (-1 < iVar4) {
            iVar4 = readl(*plVar22 + 0x2608);
            writel(0,*plVar22 + 0x260c);
            uVar6 = ((uint)local_80 * iVar4 + 0x32) / 100;
            uVar6 = uVar6 | (iVar4 - uVar6) * 0x100;
            local_80 = CONCAT44(local_80._4_4_,uVar6);
            writel(uVar6,*plVar22 + 0x2610);
            iVar4 = 0;
          }
          if (iVar4 == 0) goto LAB_0010a204;
        }
        else {
          _dev_err(*(undefined8 *)(*(long *)(puVar16 + 4) + 0x40),"Unknown shared ICE algo (%d)\n");
          iVar4 = -0x16;
        }
LAB_0010a3d8:
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: config shared ice failed, ret=%d\n",
                 "ufs_qcom_hce_enable_notify",iVar4);
        lVar7 = *(long *)(puVar16 + 0xac);
        goto joined_r0x0010a29c;
      }
      plVar22 = *(long **)(puVar16 + 4);
      local_78 = 0;
      uStack_70 = 0;
      local_80 = 0;
      if (plVar22 == (long *)0x0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10a4b8);
        (*pcVar3)();
      }
      local_88 = 0;
      lVar20 = plVar22[0x16];
      writel(1,*plVar22 + 0x260c);
      uVar17 = 0;
      lVar7 = 0x2618;
      uVar19 = 0x18;
      do {
        if (*(long *)(lVar20 + 0x2c0) == 0) {
          puVar15 = (uint *)(alg2_config + uVar19);
          uVar11 = uVar19 - 4;
          piVar10 = (int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 0x14);
          uVar6 = *(uint *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 8) |
                  *(int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 4) << 8;
          uVar5 = *(int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 0xc) << 0x18 |
                  *(int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 0x10) << 0x10;
          uVar13 = uVar19;
joined_r0x0010a110:
          uVar14 = 0x118 - uVar13;
          uVar12 = 0x118;
          if (0x118 < uVar13) goto LAB_0010a400;
        }
        else {
          snprintf((char *)&local_88,8,"%s%d",&DAT_001241d6,uVar17 & 0xffffffff);
          iVar4 = of_property_read_variable_u32_array
                            (*(undefined8 *)(lVar20 + 0x2c0),&local_88,&local_80,6,6);
          if (iVar4 < 1) {
            lVar2 = uVar17 * 0x1c;
            uVar13 = lVar2 + 0x18;
            uVar11 = lVar2 + 0x14;
            puVar15 = (uint *)(alg2_config + lVar2 + 0x18);
            uVar6 = *(uint *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 8) |
                    *(int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 4) << 8;
            uVar5 = *(int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 0xc) << 0x18 |
                    *(int *)(__ufs_qcom_cfg_timers_hs_fr_table_rB + uVar19 + 0x10) << 0x10;
            piVar10 = (int *)(alg2_config + lVar2 + 0x14);
            goto joined_r0x0010a110;
          }
          uVar12 = 0x18;
          uVar11 = 0x10;
          uVar6 = local_80._4_4_ | (uint)local_80 << 8;
          uVar5 = local_78._4_4_ << 0x10 | (int)local_78 << 0x18;
          uVar13 = 0x14;
          uVar14 = 4;
          puVar15 = (uint *)((long)&uStack_70 + 4);
          piVar10 = (int *)&uStack_70;
        }
        if ((((uVar14 < 4) || (uVar12 < uVar11)) || (uVar12 - uVar11 < 4)) ||
           ((uVar12 < uVar13 || (uVar12 - uVar13 < 4)))) {
LAB_0010a400:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x10a404);
          (*pcVar3)();
        }
        iVar4 = *piVar10;
        uVar1 = *puVar15;
        writel(uVar6 | 0x80000000,*plVar22 + lVar7 + -4);
        writel(uVar5 | iVar4 << 8 | uVar1,*plVar22 + lVar7);
        uVar17 = uVar17 + 1;
        lVar7 = lVar7 + 8;
        uVar19 = uVar19 + 0x1c;
      } while (uVar19 != 0x130);
    }
  }
LAB_0010a204:
  local_80 = local_80 & 0xffffffff00000000;
  lVar7 = _jiffies + 0x19;
  do {
    iVar4 = ufshcd_dme_get_attr(param_1,0x410000,&local_80,0);
    if ((iVar4 != 0) || ((uint)local_80 == 1)) break;
    usleep_range_state(100,200,2);
  } while (_jiffies - lVar7 < 0);
  if (lVar7 - _jiffies < 0) {
    iVar4 = ufshcd_dme_get_attr(param_1,0x410000,&local_80,0);
  }
  if (iVar4 == 0) {
    if ((uint)local_80 != 1) {
      uVar8 = *(undefined8 *)(param_1 + 0x40);
      pcVar21 = "%s: invalid TX_FSM_STATE = %d\n";
      iVar4 = (uint)local_80;
      goto LAB_0010a380;
    }
    iVar4 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(param_1 + 0x40);
    pcVar21 = "%s: unable to get TX_FSM_STATE, err %d\n";
LAB_0010a380:
    _dev_err(uVar8,pcVar21,"ufs_qcom_check_hibern8",iVar4);
  }
  ufs_qcom_enable_hw_clk_gating(param_1);
  lVar7 = *(long *)(puVar16 + 0xac);
joined_r0x0010a29c:
  if ((lVar7 != 0) && ((char)puVar16[0xae] != '\0')) {
    lVar20 = tpidr_el1;
    ipc_log_string(lVar7,",%d,-,%d,%d\n",*(undefined4 *)(&cpu_number + lVar20),param_2,iVar4);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// ufs_qcom_link_startup_notify @ 0010a4bc size=1148
// signature: undefined ufs_qcom_link_startup_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ufs_qcom_link_startup_notify(long *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  size_t sVar7;
  char *pcVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  byte *pbVar11;
  int local_60;
  uint local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  if (param_1 == (long *)0x0) goto LAB_0010a944;
  pbVar11 = (byte *)param_1[0x16];
  uVar9 = *(undefined8 *)(pbVar11 + 8);
  if (param_2 == 1) {
    local_5c = 0;
    iVar2 = ufshcd_dme_get_attr(param_1,0x15610000,&local_5c,0);
    if (iVar2 == 0) {
      ufs_qcom_phy_set_tx_lane_enable(uVar9,local_5c);
      iVar2 = ufshcd_get_local_unipro_ver(param_1);
      if (iVar2 == 2) {
        ufs_qcom_phy_ctrl_rx_linecfg(uVar9,0);
      }
      if ((*(char *)((long)param_1 + 0x8a) < '\0') &&
         ((*(byte *)((long)param_1 + 0xcd) >> 3 & 1) == 0)) {
        uVar5 = readl(*param_1 + 0xfc);
        writel(uVar5 | 0x3c,*param_1 + 0xfc);
      }
      DataSynchronizationBarrier(3,3,0);
    }
    else {
      _dev_err(param_1[8],"%s: couldn\'t read PA_CONNECTEDTXDATALANES %d\n",
               "ufs_qcom_get_connected_tx_lanes",iVar2);
    }
    local_60 = 0;
    iVar3 = ufshcd_dme_get_attr(param_1,0x15610000,&local_60,0);
    iVar2 = local_60;
    if (iVar3 != 0) {
      _dev_err(param_1[8],"%s: couldn\'t read PA_CONNECTEDTXDATALANES %d\n",
               "ufs_qcom_get_connected_tx_lanes",iVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a898);
      (*pcVar1)();
    }
    iVar3 = *(int *)((long)param_1 + 0xa84);
    if (local_60 != iVar3) {
      _dev_err(param_1[8],"%s: Tx lane mismatch [config,reported] [%d,%d]\n",
               "ufs_qcom_validate_link_params",iVar3,local_60);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a8c0);
      (*pcVar1)();
    }
    local_60 = 0;
    iVar4 = ufshcd_dme_get_attr(param_1,0x15810000,&local_60,0);
    if (iVar4 != 0) {
      _dev_err(param_1[8],"%s: couldn\'t read PA_CONNECTEDRXDATALANES %d\n",
               "ufs_qcom_get_connected_rx_lanes",iVar4);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a8e4);
      (*pcVar1)();
    }
    if (local_60 != *(int *)((long)param_1 + 0xa84)) {
      _dev_err(param_1[8],"%s: Rx lane mismatch [config,reported] [%d,%d]\n",
               "ufs_qcom_validate_link_params");
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a904);
      (*pcVar1)();
    }
    if (iVar2 != iVar3) {
      lVar6 = 0;
      local_5c = 0;
      do {
        iVar2 = *(int *)((long)&DAT_0011c274 + lVar6);
        uVar5 = ufshcd_dme_get_attr(param_1,iVar2 << 0x10,&local_5c,0);
        if (uVar5 == 0) {
          pcVar8 = "0x%04x: %d\n";
          uVar5 = local_5c;
        }
        else {
          pcVar8 = "Failed reading: 0x%04x, ret:%d\n";
        }
        _dev_err(param_1[8],pcVar8,iVar2,uVar5);
        lVar6 = lVar6 + 4;
      } while (lVar6 != 0xc0);
    }
LAB_0010a6a8:
    iVar2 = 0;
  }
  else {
    if (param_2 != 0) goto LAB_0010a6a8;
    puVar10 = (undefined8 *)param_1[8];
    lVar6 = of_find_property(puVar10[0x5d],"secondary-storage",0);
    if (lVar6 == 0) {
      sVar7 = strnlen(android_boot_dev,0x1e);
      if (0x1e < sVar7) {
        fortify_panic("strnlen");
LAB_0010a938:
        fortify_panic("__fortify_strlen");
LAB_0010a944:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a948);
        (*pcVar1)();
      }
      if (sVar7 != 0) {
        if (sVar7 == 0x1e) goto LAB_0010a938;
        pcVar8 = (char *)puVar10[0xe];
        if (pcVar8 == (char *)0x0) {
          pcVar8 = (char *)*puVar10;
        }
        iVar2 = strcmp(android_boot_dev,pcVar8);
        if (iVar2 != 0) {
          iVar2 = -0x13;
          goto LAB_0010a6fc;
        }
      }
    }
    ufshcd_dme_set_attr(param_1,0x15200000,0,*(undefined4 *)((long)param_1 + 0xa84),0);
    ufshcd_dme_set_attr(param_1,0x15400000,0,*(undefined4 *)((long)param_1 + 0xa84),0);
    iVar2 = __ufs_qcom_cfg_timers(param_1,1,5,0,1,0);
    if (iVar2 == 0) {
      ufs_qcom_phy_ctrl_rx_linecfg(uVar9,1);
      if (((*pbVar11 & 1) == 0) ||
         (iVar2 = ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode(param_1), iVar2 == 0)) {
        iVar2 = ufs_qcom_enable_hw_clk_gating(param_1);
        if (iVar2 == 0) {
          uVar5 = readl_relaxed(*(undefined8 *)(pbVar11 + 0x98));
          writel_relaxed(uVar5 | 0x80000000,*(undefined8 *)(pbVar11 + 0x98));
          DataSynchronizationBarrier(3,2,0);
          iVar2 = ufshcd_get_local_unipro_ver(param_1);
          if ((iVar2 == 2) || (iVar2 = ufshcd_dme_set_attr(param_1,0x155e0000,0,0,0), iVar2 == 0)) {
            if (pbVar11[0x191] == 0) goto LAB_0010a6a8;
            iVar2 = ufs_qcom_bypass_cfgready_signal(param_1);
          }
        }
      }
      else if (((link_failed_recovery != '\0') && (_jiffies - link_startup_life_time < 0)) &&
              (2 < (ulong)param_1[0xcc])) {
        _printk(&DAT_0012092a);
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10a7e8);
        (*pcVar1)();
      }
    }
    else {
      _dev_err(param_1[8],"%s: ufs_qcom_cfg_timers() failed\n","ufs_qcom_link_startup_notify");
      iVar2 = -0x16;
    }
  }
  if ((*(long *)(pbVar11 + 0x2b0) != 0) && (pbVar11[0x2b8] != 0)) {
    lVar6 = tpidr_el1;
    ipc_log_string(*(long *)(pbVar11 + 0x2b0),",%d,*,%d,%d\n",*(undefined4 *)(&cpu_number + lVar6),
                   param_2,iVar2);
  }
LAB_0010a6fc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ufs_qcom_pwr_change_notify @ 0010a9ec size=1292
// signature: undefined ufs_qcom_pwr_change_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ufs_qcom_pwr_change_notify(long param_1,int param_2,uint *param_3,uint *param_4)

{
  undefined8 uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  long lVar10;
  uint uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined4 local_5c;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10aef8);
    (*pcVar4)();
  }
  lVar10 = *(long *)(param_1 + 0xb0);
  if (param_4 == (uint *)0x0) {
    _printk(&DAT_00122ee3,"ufs_qcom_pwr_change_notify");
    if ((*(long *)(lVar10 + 0x2b0) != 0) && (*(char *)(lVar10 + 0x2b8) != '\0')) {
      lVar7 = tpidr_el1;
      ipc_log_string(*(long *)(lVar10 + 0x2b0),",%d,@,%d,%d,%d,%d,%d\n",
                     *(undefined4 *)(&cpu_number + lVar7),param_2,0,0,0,0xffffffea);
    }
    uVar12 = 0xffffffea;
    goto LAB_0010ad10;
  }
  uVar13 = *(undefined8 *)(lVar10 + 8);
  if ((link_failed_recovery != '\0') && (link_startup_life_time == 0)) {
    link_startup_life_time = _jiffies + 25000;
    _dev_err(*(undefined8 *)(param_1 + 0x40),"init link_startup_life_time jiffies 0x%x (0x%x)\n",
             _jiffies);
  }
  if ((link_failed_recovery != '\0') && (link_startup_life_time - _jiffies < 0)) {
    link_failed_recovery = '\0';
    _dev_err(*(undefined8 *)(param_1 + 0x40),"disable link_failed_recovery\n");
  }
  if (param_2 == 1) {
    iVar6 = __ufs_qcom_cfg_timers(param_1,*param_4,param_4[4],param_4[6],0,0);
    uVar12 = 0;
    if (iVar6 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: ufs_qcom_cfg_timers() failed\n",
               "ufs_qcom_pwr_change_notify");
      uVar12 = 0xffffffea;
    }
    ufs_qcom_phy_set_tx_lane_enable(uVar13,~(-1 << (ulong)(param_4[3] & 0x1f)));
    uVar13 = *(undefined8 *)(param_4 + 2);
    uVar1 = *(undefined8 *)(param_4 + 4);
    uVar9 = *(undefined8 *)param_4;
    *(uint *)(lVar10 + 0x68) = param_4[6];
    *(undefined8 *)(lVar10 + 0x58) = uVar13;
    *(undefined8 *)(lVar10 + 0x60) = uVar1;
    *(undefined8 *)(lVar10 + 0x50) = uVar9;
    ufs_qcom_update_bus_bw_vote(lVar10);
    if ((((*(int *)(param_1 + 0xa98) == 4) || (*(int *)(param_1 + 0xa98) == 1)) &&
        ((*(int *)(param_1 + 0xa9c) == 4 || (*(int *)(param_1 + 0xa9c) == 1)))) &&
       (((param_4[4] != 4 && (param_4[4] != 1)) || ((param_4[5] != 1 && (param_4[5] != 4)))))) {
      ufs_qcom_dev_ref_clk_ctrl(lVar10,0);
    }
    if ((iVar6 != 0) || ((override_ber_threshold & 1) != 0)) goto LAB_0010aca8;
    uVar5 = *param_4;
    if (5 < uVar5) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10aef0);
      (*pcVar4)();
    }
    if (0x30 < ((ulong)uVar5 << 3 | 4)) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x10aef4);
      (*pcVar4)();
    }
    uVar12 = 0;
    ber_threshold = *(undefined4 *)(ber_table + (ulong)uVar5 * 8 + 4);
    lVar7 = *(long *)(lVar10 + 0x2b0);
  }
  else if (param_2 == 0) {
    if (param_3[4] == 1) {
      uVar11 = *(uint *)(lVar10 + 0x144);
      uVar2 = *(uint *)(param_1 + 0xa84);
      uVar3 = *(uint *)(lVar10 + 0x134);
      uVar5 = *(uint *)(lVar10 + 0x138);
      param_4[4] = 1;
      param_4[5] = 1;
      if (uVar3 <= uVar5) {
        uVar5 = uVar3;
      }
      uVar3 = param_3[3];
      if (uVar2 <= param_3[3]) {
        uVar3 = uVar2;
      }
      param_4[3] = uVar3;
      uVar3 = param_3[2];
      if (uVar2 <= param_3[2]) {
        uVar3 = uVar2;
      }
      param_4[2] = uVar3;
      uVar2 = *param_3;
      uVar3 = param_3[1];
      param_4[6] = uVar11;
      if (uVar3 <= uVar2) {
        uVar2 = uVar3;
      }
      if (uVar5 <= uVar2) {
        uVar2 = uVar5;
      }
      *param_4 = uVar2;
      param_4[1] = uVar2;
      if ((((*(int *)(param_1 + 0xa98) != 4) && (*(int *)(param_1 + 0xa98) != 1)) ||
          ((*(int *)(param_1 + 0xa9c) != 1 && (*(int *)(param_1 + 0xa9c) != 4)))) &&
         ((*(long *)(lVar10 + 0x98) != 0 && (*(char *)(lVar10 + 0xa0) != '\x01')))) {
        uVar5 = readl_relaxed();
        writel_relaxed(*(uint *)(lVar10 + 0xbc) | uVar5,*(undefined8 *)(lVar10 + 0x98));
        readl(*(undefined8 *)(lVar10 + 0x98));
        usleep_range_state(0x32,0x3c,2);
        *(undefined1 *)(lVar10 + 0xa0) = 1;
      }
      if (3 < *(byte *)(lVar10 + 0xa6)) {
        uVar8 = 3;
        if (3 < param_4[1]) {
          uVar8 = 1;
        }
        ufshcd_dme_set_attr(param_1,0x15d40000,0,uVar8,0);
      }
      if ((*(byte *)(param_1 + 0xd6) >> 1 & 1) != 0) {
        local_5c = 0;
        uVar5 = param_4[3];
        iVar6 = ufs_qcom_phy_get_tx_hs_equalizer
                          (*(undefined8 *)(*(long *)(param_1 + 0xb0) + 8),param_4[1],&local_5c);
        if ((uVar5 != 0) && (iVar6 == 0)) {
          uVar11 = 0;
          do {
            iVar6 = ufshcd_dme_set_attr(param_1,uVar11 & 0xffff | 0x370000,0,local_5c,0);
            if (iVar6 != 0) {
              _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: failed equalizer lane %d\n",
                       "ufs_qcom_set_tx_hs_equalizer",uVar11);
            }
            uVar11 = uVar11 + 1;
          } while (uVar5 != uVar11);
        }
      }
      uVar12 = 0;
      lVar7 = *(long *)(lVar10 + 0x2b0);
    }
    else {
      _printk(&DAT_00121c75,"ufs_qcom_get_pwr_dev_param");
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: failed to determine capabilities\n",
               "ufs_qcom_pwr_change_notify");
      uVar12 = 0xffffffa1;
      lVar7 = *(long *)(lVar10 + 0x2b0);
    }
  }
  else {
    uVar12 = 0xffffffea;
LAB_0010aca8:
    lVar7 = *(long *)(lVar10 + 0x2b0);
  }
  if ((lVar7 != 0) && (*(char *)(lVar10 + 0x2b8) != '\0')) {
    lVar10 = tpidr_el1;
    ipc_log_string(lVar7,",%d,@,%d,%d,%d,%d,%d\n",*(undefined4 *)(&cpu_number + lVar10),param_2,
                   *param_4,param_4[4],param_4[6],uVar12);
  }
LAB_0010ad10:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// ufs_qcom_hibern8_notify @ 0010b05c size=124
// signature: undefined ufs_qcom_hibern8_notify(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_hibern8_notify(long *param_1,int param_2,int param_3)

{
  code *pcVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10b0dc);
    (*pcVar1)();
  }
  if (((param_2 == 0x18) && (param_3 == 1)) &&
     (lVar2 = param_1[0x16], *(char *)(lVar2 + 0x158) != '\0')) {
    if (*(int *)(lVar2 + 0x2c8) == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10b0d4);
      (*pcVar1)();
    }
    *(undefined1 *)(lVar2 + 0x158) = 0;
    writel(0x18,*param_1 + 0x2600);
    writel(0,*param_1 + 0x2600);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_apply_dev_quirks @ 0010b0e0 size=452
// signature: undefined ufs_qcom_apply_dev_quirks(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_apply_dev_quirks(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  uVar6 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38));
  *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x38) + 0xb8) + 0x168) = 3000;
  *(undefined4 *)(param_1 + 100) = 0xc05;
  *(undefined8 *)(param_1 + 0xb88) = 0x32;
  _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38),uVar6);
  if ((*(byte *)(param_1 + 0xd5) & 1) == 0) {
    iVar4 = 0;
  }
  else {
    local_2c = 0;
    iVar4 = ufshcd_dme_get_attr(param_1,0x90000000,&local_2c,0);
    if (iVar4 == 0) {
      iVar4 = ufshcd_dme_set_attr(param_1,0x90000000,0,local_2c | 0x1000,0);
    }
  }
  uVar1 = *(uint *)(param_1 + 0xd4);
  uVar2 = uVar1;
  if (*(short *)(param_1 + 0xa14) == 0x145) {
    *(uint *)(param_1 + 0xd4) = uVar1 | 0x80;
    uVar2 = uVar1 | 0x80;
  }
  if ((uVar1 >> 0xf & 1) == 0) goto joined_r0x0010b1a4;
  local_2c = 0;
  iVar5 = ufshcd_dme_get_attr(param_1,0x15a70000,&local_2c,0);
  if (iVar5 == 0) {
    iVar5 = ufshcd_dme_set_attr(param_1,0x15a70000,0,local_2c + 1,0);
    if (iVar5 != 0) {
      uVar6 = *(undefined8 *)(param_1 + 0x40);
      pcVar7 = "Failed updating PA_HIBERN8TIME: %d\n";
      goto LAB_0010b298;
    }
  }
  else {
    uVar6 = *(undefined8 *)(param_1 + 0x40);
    pcVar7 = "Failed getting PA_HIBERN8TIME: %d\n";
LAB_0010b298:
    _dev_err(uVar6,pcVar7,iVar5);
  }
  uVar2 = *(uint *)(param_1 + 0xd4);
joined_r0x0010b1a4:
  if (((uVar2 >> 0x10 & 1) != 0) &&
     (iVar5 = ufshcd_dme_set_attr(param_1,0x15520000,0,0x4a,1), iVar5 != 0)) {
    _dev_err(*(undefined8 *)(param_1 + 0x40),"Failed (%d) set PA_TX_HSG1_SYNC_LENGTH(%d)\n",iVar5,
             0x4a);
  }
  if (*(short *)(param_1 + 0xa14) == 300) {
    *(uint *)(param_1 + 0xd4) = *(uint *)(param_1 + 0xd4) | 0x40;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// ufs_qcom_fixup_dev_quirks @ 0010b2a8 size=72
// signature: undefined ufs_qcom_fixup_dev_quirks(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_fixup_dev_quirks(undefined8 param_1)

{
  ufshcd_fixup_dev_quirks(param_1,ufs_qcom_dev_fixups);
  if (storage_mfrid != 0x1ad) {
    ufsf_set_init(param_1);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_suspend @ 0010b2f4 size=500
// signature: undefined ufs_qcom_suspend(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_suspend(long param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  undefined8 *puVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10b4e8);
    (*pcVar1)();
  }
  lVar6 = *(long *)(param_1 + 0xb0);
  if (param_3 == 0) {
    if ((storage_mfrid == 0x1ad) || (iVar2 = ufsf_suspend(lVar6 + 0xd50,param_2 == 1), iVar2 == 0))
    {
      return 0;
    }
    return iVar2;
  }
  if (*(int *)(param_1 + 0x54) != 1) {
    ufs_qcom_disable_lane_clks(lVar6);
    puVar7 = *(undefined8 **)(lVar6 + 0x178);
    if (((puVar7 == (undefined8 *)0x0) || (*(int *)(param_1 + 0x54) != 0)) ||
       (*(char *)((long)puVar7 + 0x11) == '\0')) {
      iVar2 = 0;
    }
    else {
      iVar2 = regulator_disable(*puVar7);
      if ((iVar2 == 0) &&
         ((iVar2 = regulator_count_voltages(*puVar7), iVar2 < 1 ||
          (iVar2 = regulator_set_load(*puVar7,0), iVar2 == 0)))) {
        iVar2 = 0;
        *(undefined1 *)((long)puVar7 + 0x11) = 0;
      }
    }
    puVar7 = *(undefined8 **)(lVar6 + 0x180);
    if ((((puVar7 != (undefined8 *)0x0) && (*(char *)(param_1 + 0xa48) == '\0')) &&
        ((*(char *)((long)puVar7 + 0x11) != '\0' && (iVar3 = regulator_disable(*puVar7), iVar3 == 0)
         ))) && ((iVar3 = regulator_count_voltages(*puVar7), iVar3 < 1 ||
                 (iVar3 = regulator_set_load(*puVar7,0), iVar3 == 0)))) {
      *(undefined1 *)((long)puVar7 + 0x11) = 0;
    }
    if ((iVar2 != 0) || (iVar2 = ufs_qcom_unvote_qos_all(param_1), iVar2 != 0)) goto LAB_0010b3a8;
    if ((*(int *)(param_1 + 0x54) == 0) &&
       ((*(long *)(lVar6 + 0x128) != 0 &&
        (lVar4 = *(long *)(*(long *)(param_1 + 0xb0) + 0x128), lVar4 != 0)))) {
      gpiod_set_value_cansleep(lVar4,1);
    }
  }
  iVar2 = 0;
LAB_0010b3a8:
  if ((*(long *)(lVar6 + 0x2b0) != 0) && (*(char *)(lVar6 + 0x2b8) != '\0')) {
    lVar4 = tpidr_el1;
    ipc_log_string(*(long *)(lVar6 + 0x2b0),",%d,&,%d,%d,%d,%d,%d,%d\n",
                   *(undefined4 *)(&cpu_number + lVar4),param_2,*(undefined4 *)(param_1 + 0x58),
                   *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x54),
                   *(undefined4 *)(param_1 + 0x50),iVar2);
  }
  uVar5 = (ulong)*(byte *)(lVar6 + 0x2b8);
  if (*(byte *)(lVar6 + 0x2b8) != 0) {
    uVar5 = (*(ulong **)(param_1 + 0x40))[0xe];
    if (uVar5 == 0) {
      uVar5 = **(ulong **)(param_1 + 0x40);
    }
  }
  ufs_qcom_ice_disable(uVar5,lVar6);
  cancel_dwork_unvote_cpufreq(param_1);
  return iVar2;
}



//------------------------------------------------------------
// ufs_qcom_resume @ 0010b5a8 size=440
// signature: undefined ufs_qcom_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ufs_qcom_resume(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b760);
    (*pcVar2)();
  }
  lVar5 = *(long *)(param_1 + 0xb0);
  if (storage_mfrid != 0x1ad) {
    queue_work_on(0x20,_system_wq,lVar5 + 0xe38);
  }
  puVar6 = *(undefined8 **)(lVar5 + 0x178);
  if (((puVar6 != (undefined8 *)0x0) &&
      ((((3 < *(uint *)(param_1 + 0x58) || (3 < *(uint *)(param_1 + 0x5c))) &&
        (*(char *)((long)puVar6 + 0x11) == '\0')) &&
       ((iVar3 = regulator_count_voltages(*puVar6), iVar3 < 1 ||
        (iVar3 = regulator_set_load(*puVar6,*(undefined4 *)((long)puVar6 + 0x14)), iVar3 == 0))))))
     && (iVar3 = regulator_enable(*puVar6), iVar3 == 0)) {
    *(undefined1 *)((long)puVar6 + 0x11) = 1;
  }
  puVar6 = *(undefined8 **)(lVar5 + 0x180);
  if ((((puVar6 != (undefined8 *)0x0) && (*(char *)((long)puVar6 + 0x11) == '\0')) &&
      ((iVar3 = regulator_count_voltages(*puVar6), iVar3 < 1 ||
       (iVar3 = regulator_set_load(*puVar6,*(undefined4 *)((long)puVar6 + 0x14)), iVar3 == 0)))) &&
     (iVar3 = regulator_enable(*puVar6), iVar3 == 0)) {
    *(undefined1 *)((long)puVar6 + 0x11) = 1;
  }
  uVar4 = ufs_qcom_enable_lane_clks(lVar5);
  if ((int)uVar4 == 0) {
    if (*(char *)(lVar5 + 0xa6) == '\x06') {
      uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38));
      *(undefined8 *)(param_1 + 0xb88) = 5;
      _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38),uVar4);
    }
    if ((*(long *)(lVar5 + 0x2b0) != 0) && (*(char *)(lVar5 + 0x2b8) != '\0')) {
      lVar1 = tpidr_el1;
      ipc_log_string(*(long *)(lVar5 + 0x2b0),",%d,$,%d,%d,%d,%d,%d,%d\n",
                     *(undefined4 *)(&cpu_number + lVar1),param_2,*(undefined4 *)(param_1 + 0x58),
                     *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x54),
                     *(undefined4 *)(param_1 + 0x50),0);
    }
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// ufs_qcom_dump_dbg_regs @ 0010b818 size=3324
// signature: undefined ufs_qcom_dump_dbg_regs(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_dump_dbg_regs(long *param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  ulong uVar9;
  int iVar10;
  long lVar11;
  long lVar12;
  undefined *puVar13;
  undefined8 uVar14;
  ulong uVar15;
  long lVar16;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10c510);
    (*pcVar1)();
  }
  lVar16 = param_1[0x16];
  *(undefined1 *)(lVar16 + 0x1f0) = 1;
  uVar14 = *(undefined8 *)(lVar16 + 8);
  lVar11 = param_1[8];
  uVar3 = readl(*param_1 + 0x2700);
  _dev_err(lVar11,"HW_H8_ENTER_CNT=%d\n",uVar3);
  lVar11 = param_1[8];
  uVar3 = readl(*param_1 + 0x270c);
  _dev_err(lVar11,"HW_H8_EXIT_CNT=%d\n",uVar3);
  lVar11 = param_1[8];
  uVar3 = readl(*param_1 + 0x2704);
  _dev_err(lVar11,"SW_H8_ENTER_CNT=%d\n",uVar3);
  lVar11 = param_1[8];
  uVar3 = readl(*param_1 + 10000);
  _dev_err(lVar11,"SW_H8_EXIT_CNT=%d\n",uVar3);
  lVar11 = param_1[8];
  uVar3 = readl(*param_1 + 0x2708);
  _dev_err(lVar11,"SW_AFTER_HW_H8_ENTER_CNT=%d\n",uVar3);
  ufshcd_dump_regs(param_1,0xc0,0x40,"HCI Vendor Specific Registers ");
  ufshcd_dump_regs(param_1,0x2600,0x74,"HCI Shared ICE Registers ");
  if (*(char *)((long)param_1 + 0x13ac) != '\0') {
    ufshcd_dump_regs(param_1,0xd00,0x100,"HCI MCQ Debug Registers ");
  }
  lVar11 = param_1[0x16];
  if ((*(byte *)(lVar11 + 0xc0) & 1) != 0) {
    uVar4 = readl(*param_1 + 0xdc);
    writel(uVar4 | 0x20000,*param_1 + 0xdc);
    if (*(byte *)(lVar11 + 0xa6) < 6) {
      uVar6 = 0x1900;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x1d00;
      }
      ufshcd_dump_regs(param_1,uVar6,0x80,"UFS_UFS_DBG_RD_EDTL_RAM ");
      uVar6 = 0x1500;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x1900;
      }
      ufshcd_dump_regs(param_1,uVar6,0x200,"UFS_UFS_DBG_RD_DESC_RAM ");
      uVar6 = 0x1700;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x1b00;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_UFS_DBG_RD_PRDT_RAM ");
      uVar4 = readl(*param_1 + 0xdc);
      writel(uVar4 & 0xfffdffff,*param_1 + 0xdc);
      uVar6 = 0x800;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0xc00;
      }
      ufshcd_dump_regs(param_1,uVar6,0xb0,"UFS_UFS_DBG_RD_REG_OCSC ");
      uVar6 = 0x100;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x500;
      }
      ufshcd_dump_regs(param_1,uVar6,0x10,"UFS_DBG_RD_REG_UAWM ");
      uVar6 = 0x200;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x600;
      }
      ufshcd_dump_regs(param_1,uVar6,0x10,"UFS_DBG_RD_REG_UARM ");
      uVar6 = 0x300;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x700;
      }
      ufshcd_dump_regs(param_1,uVar6,0xc0,"UFS_DBG_RD_REG_TXUC ");
      uVar6 = 0x400;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x800;
      }
      ufshcd_dump_regs(param_1,uVar6,0x6c,"UFS_DBG_RD_REG_RXUC ");
      uVar6 = 0x500;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x900;
      }
      ufshcd_dump_regs(param_1,uVar6,0x4c,"UFS_DBG_RD_REG_DFC ");
      uVar6 = 0x600;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0xa00;
      }
      ufshcd_dump_regs(param_1,uVar6,0x88,"UFS_DBG_RD_REG_TRLUT ");
      uVar7 = 0x24;
      uVar6 = 0x700;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0xb00;
      }
    }
    else {
      iVar10 = 3;
      do {
        writel(iVar10,*param_1 + 0x1000);
        ufshcd_dump_regs(param_1,0x1024,0x20,"UFS_UFS_DBG_RD_DESC_RAM ");
        iVar10 = iVar10 + 0x100;
      } while (iVar10 != 0x8003);
      iVar10 = 4;
      do {
        writel(iVar10,*param_1 + 0x1000);
        ufshcd_dump_regs(param_1,0x1024,0x20,"UFS_UFS_DBG_RD_PRDT_RAM ");
        iVar10 = iVar10 + 0x100;
      } while (iVar10 != 0x4004);
      iVar10 = 5;
      do {
        writel(iVar10,*param_1 + 0x1000);
        ufshcd_dump_regs(param_1,0x1024,0x20," UFS_UFS_DBG_RD_RESP_RAM ");
        iVar10 = iVar10 + 0x100;
      } while (iVar10 != 0x4005);
      iVar10 = 6;
      do {
        writel(iVar10,*param_1 + 0x1000);
        ufshcd_dump_regs(param_1,0x1024,0x20,"UFS_UFS_DBG_RD_EDTL_RAM ");
        iVar10 = iVar10 + 0x100;
      } while (iVar10 != 0x4006);
      uVar4 = readl(*param_1 + 0xdc);
      writel(uVar4 & 0xfffdffff,*param_1 + 0xdc);
      uVar6 = 0x800;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0xc00;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_UFS_DBG_RD_REG_OCSC ");
      uVar6 = 0x100;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x500;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_DBG_RD_REG_UAWM ");
      uVar6 = 0x200;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x600;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_DBG_RD_REG_UARM ");
      uVar6 = 0x300;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x700;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_DBG_RD_REG_TXUC ");
      uVar6 = 0x400;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x800;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_DBG_RD_REG_RXUC ");
      uVar6 = 0x500;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0x900;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_DBG_RD_REG_DFC ");
      uVar6 = 0x600;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0xa00;
      }
      ufshcd_dump_regs(param_1,uVar6,0x100,"UFS_DBG_RD_REG_TRLUT ");
      uVar7 = 0x100;
      uVar6 = 0x700;
      if (2 < *(byte *)(lVar11 + 0xa6)) {
        uVar6 = 0xb00;
      }
    }
    ufshcd_dump_regs(param_1,uVar6,uVar7,"UFS_DBG_RD_REG_TMRLUT ");
  }
  ufs_qcom_ice_debug(lVar16);
  lVar11 = sp_el0;
  if ((*(uint *)(lVar11 + 0x10) & 0xff0100) == 0) {
    usleep_range_state(1000,0x44c,2);
    if (*(char *)((long)param_1 + 0x13ac) != '\0') {
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27b] + uVar15);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ HCI 1da0000-1da03f0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27b] + uVar15 + 0x400);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ HCI 1da0400-1da07f0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      puVar5 = (undefined4 *)kmalloc_trace(_enable_irq,0xb20,0x14);
      if (puVar5 != (undefined4 *)0x0) {
        uVar3 = readl(param_1[0x28a]);
        lVar11 = param_1[0x28a];
        *puVar5 = uVar3;
        uVar3 = readl(lVar11 + 4);
        lVar11 = param_1[0x28a];
        puVar5[1] = uVar3;
        uVar3 = readl(lVar11 + 8);
        lVar11 = param_1[0x28a];
        puVar5[2] = uVar3;
        uVar3 = readl(lVar11 + 0xc);
        lVar11 = param_1[0x28a];
        puVar5[3] = uVar3;
        uVar3 = readl(lVar11 + 0x10);
        puVar5[4] = uVar3;
        print_hex_dump(&DAT_00120383,"MCQ VS 1da4000-1da4010 ",2,0x10,4,puVar5,0x14,0);
        kfree(puVar5);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da5000-1da53f0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0x400);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da5400-1da57f0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0x800);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da5800-1da5bf0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0xc00);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da5c00-1da5ff0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0x1000);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da6000-1da63f0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0x1400);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da6400-1da67f0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0x1800);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da6800-1da6bf0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
      lVar11 = kmalloc_trace(_memcpy,0xb20,0x400);
      if (lVar11 != 0) {
        uVar15 = 0;
        do {
          uVar3 = readl(param_1[0x27e] + uVar15 + 0x1c00);
          *(undefined4 *)(lVar11 + uVar15) = uVar3;
          bVar2 = uVar15 < 0x3fc;
          uVar15 = uVar15 + 4;
        } while (bVar2);
        print_hex_dump(&DAT_00120383,"MCQ SQD 1da6c00-1da6ff0 ",2,0x10,4,lVar11,0x400,0);
        kfree(lVar11);
      }
      usleep_range_state(1000,0x44c,2);
    }
    ufshcd_dump_regs(param_1,0xe8,4,"UFS_TEST_BUS ");
    usleep_range_state(1000,0x44c,2);
    lVar12 = param_1[0x16];
    lVar11 = kmalloc_trace(_memcpy,0xcc0,0x400);
    if (lVar11 != 0) {
      puVar13 = (undefined *)0x0;
      uVar15 = 0;
      do {
        if (uVar15 < 0xc) {
          uVar9 = (ulong)(uint)(&DAT_0011c4d0)[uVar15];
          puVar13 = (&PTR_s_TSTBUS_UAWM_0011c500)[uVar15];
        }
        else {
          uVar9 = 0x20;
        }
        uVar8 = 0;
        *(char *)(lVar12 + 0xc4) = (char)uVar15;
        do {
          *(char *)(lVar12 + 0xc5) = (char)uVar8;
          ufs_qcom_testbus_config(lVar12);
          uVar3 = readl(*param_1 + 0xe8);
          *(undefined4 *)(lVar11 + uVar8 * 4) = uVar3;
          uVar8 = uVar8 + 1;
        } while (uVar9 != uVar8);
        print_hex_dump(&DAT_00120383,puVar13,2,0x10,4,lVar11,uVar9 << 2,0);
        uVar15 = uVar15 + 1;
      } while (uVar15 != 0xc);
      kfree(lVar11);
    }
    usleep_range_state(1000,0x44c,2);
    ufs_qcom_phy_dbg_register_dump(uVar14);
  }
  if (*(char *)(lVar16 + 0x1f1) != '\0') {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10c514);
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_device_reset @ 0010c518 size=448
// signature: undefined ufs_qcom_device_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_device_reset(long param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10c6d8);
    (*pcVar2)();
  }
  lVar5 = *(long *)(param_1 + 0xb0);
  *(undefined1 *)(lVar5 + 0xb8) = 1;
  if (*(long *)(lVar5 + 200) == 0) {
    _dev_warn(*(undefined8 *)(param_1 + 0x40),"%s: reset control not set\n","ufs_qcom_host_reset");
    *(undefined1 *)(lVar5 + 0x158) = 0;
    *(undefined1 *)(lVar5 + 0xb8) = 0;
  }
  else {
    cVar1 = *(char *)(param_1 + 0xc4);
    disable_irq(*(undefined4 *)(param_1 + 0xc0));
    *(undefined1 *)(param_1 + 0xc4) = 0;
    iVar3 = reset_control_assert(*(undefined8 *)(lVar5 + 200));
    if (iVar3 == 0) {
      usleep_range_state(200,0xd2,2);
      iVar3 = reset_control_deassert(*(undefined8 *)(lVar5 + 200));
      if (iVar3 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: core_reset deassert failed, err = %d\n",
                 "ufs_qcom_host_reset",iVar3);
      }
      usleep_range_state(1000,0x44c,2);
      ufs_qcom_ice_disable(lVar5);
      if (cVar1 != '\0') {
        enable_irq(*(undefined4 *)(param_1 + 0xc0));
        *(undefined1 *)(param_1 + 0xc4) = 1;
      }
      *(undefined1 *)(lVar5 + 0x158) = 0;
      *(undefined1 *)(lVar5 + 0xb8) = 0;
      if (iVar3 == 0) goto LAB_0010c5bc;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: core_reset assert failed, err = %d\n",
               "ufs_qcom_host_reset",iVar3);
      *(undefined1 *)(lVar5 + 0x158) = 0;
      *(undefined1 *)(lVar5 + 0xb8) = 0;
    }
    _dev_warn(*(undefined8 *)(param_1 + 0x40),"%s: host reset returned %d\n","ufs_qcom_device_reset"
              ,iVar3);
  }
LAB_0010c5bc:
  if (storage_mfrid != 0x1ad) {
    ufsf_reset_host(*(long *)(param_1 + 0xb0) + 0xd50);
  }
  if (*(long *)(lVar5 + 0x128) == 0) {
    uVar4 = 0xffffffa1;
  }
  else {
    lVar5 = *(long *)(*(long *)(param_1 + 0xb0) + 0x128);
    if (lVar5 != 0) {
      gpiod_set_value_cansleep(lVar5,1);
    }
    usleep_range_state(10,0xf,2);
    lVar5 = *(long *)(*(long *)(param_1 + 0xb0) + 0x128);
    if (lVar5 != 0) {
      gpiod_set_value_cansleep(lVar5,0);
    }
    usleep_range_state(10,0xf,2);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// ufs_qcom_config_scaling_param @ 0010c6dc size=36
// signature: undefined ufs_qcom_config_scaling_param(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_config_scaling_param(long param_1,long param_2,undefined8 *param_3)

{
  *(undefined8 *)(param_2 + 8) = 0x10000003c;
  *param_3 = 0x4100000046;
  *(undefined1 *)(param_1 + 0xcd1) = 1;
  return;
}



//------------------------------------------------------------
// ufs_qcom_event_notify @ 0010c704 size=1612
// signature: undefined ufs_qcom_event_notify(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_event_notify(long param_1,undefined8 param_2,uint *param_3)

{
  uint *puVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 uVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  undefined8 uVar17;
  ulong uVar18;
  long *plVar19;
  char *__s2;
  undefined8 *puVar20;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10cd50);
    (*pcVar7)();
  }
  lVar16 = *(long *)(param_1 + 0xb0);
  uVar17 = *(undefined8 *)(lVar16 + 8);
  ufsf_event_notify(param_1,param_2,*param_3);
  if ((int)param_2 != 0) {
    return;
  }
  uVar13 = *(uint *)(param_1 + 0xa88);
  if (5 < uVar13) goto LAB_0010cd44;
  uVar5 = *(uint *)(ber_table + (ulong)uVar13 * 8);
  uVar18 = (ulong)uVar5;
  if (1 < uVar5) {
    _dev_err(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),"%s: Invalid gear mode: %d\n",
             "ufs_qcom_update_ber_event",uVar5);
    goto LAB_0010cb68;
  }
  lVar11 = lVar16 + uVar18 * 0x498;
  uVar4 = *(uint *)(lVar11 + 800);
  uVar10 = (ulong)uVar4;
  if (0x1f < uVar4) goto LAB_0010cd44;
  uVar4 = *param_3;
  puVar1 = (uint *)(lVar11 + 800);
  *(uint *)(lVar16 + (ulong)uVar5 * 0x498 + uVar10 * 4 + 0x324) = uVar4;
  if ((uVar4 & 0xef) != 0) {
    uVar8 = readl(**(long **)(lVar16 + 0x10) + 0xcc);
    uVar10 = (ulong)*puVar1;
    if (0x1f < *puVar1) goto LAB_0010cd44;
    *(undefined4 *)(lVar16 + (ulong)uVar5 * 0x498 + uVar10 * 4 + 0x3a4) = uVar8;
  }
  *(uint *)(lVar16 + (ulong)uVar5 * 0x498 + uVar10 * 4 + 0x424) = uVar13;
  lVar11 = ktime_get();
  uVar4 = *puVar1;
  uVar10 = (ulong)uVar4;
  uVar13 = uVar4 - 0x1f;
  if (0x1e < uVar4 && uVar13 != 0) goto LAB_0010cd44;
  *(long *)(lVar16 + (ulong)uVar5 * 0x498 + uVar10 * 8 + 0x4a8) = lVar11;
  if (uVar4 == 0) {
    if (*(int *)(lVar16 + (ulong)uVar5 * 0x498 + 0x7a8) != 0) {
      uVar14 = 0x1f;
      goto LAB_0010c824;
    }
    lVar15 = 0;
  }
  else {
    uVar14 = (ulong)(uVar4 - 1);
LAB_0010c824:
    lVar15 = *(long *)(lVar16 + (ulong)uVar5 * 0x498 + uVar14 * 8 + 0x4a8);
  }
  lVar11 = (lVar11 - lVar15) / 1000000;
  *(long *)(lVar16 + (ulong)uVar5 * 0x498 + uVar10 * 8 + 0x6a8) = lVar11;
  if (1 < uVar5) {
LAB_0010cd48:
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(1,0x10cd4c);
    (*pcVar7)();
  }
  lVar15 = lVar16 + (ulong)uVar5 * 0x498;
  *(long *)(lVar15 + uVar10 * 8 + 0x5a8) = lVar11 - (&idle_time)[uVar18];
  (&idle_time)[uVar18] = 0;
  iVar9 = *(int *)(lVar15 + 0x7a8);
  if (uVar4 + 1 < 0x20) {
    uVar13 = uVar4 + 1;
  }
  *puVar1 = uVar13;
  *(int *)(lVar15 + 0x7a8) = iVar9 + 1;
  if (*(char *)(lVar16 + 0xc60) == '\0') {
    uVar4 = 0x1f;
    if (uVar13 != 0) {
      uVar4 = uVar13 - 1;
    }
    if (0x1f < uVar4) {
LAB_0010cd44:
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10cd48);
      (*pcVar7)();
    }
    if ((override_ber_threshold & 1) == 0) {
      uVar13 = *(uint *)(lVar16 + (ulong)uVar5 * 0x498 + (ulong)uVar4 * 4 + 0x424);
      uVar18 = (ulong)uVar13;
      if (5 < uVar13) goto LAB_0010cd44;
      if ((0x30 < (uVar18 << 3 | 4)) || (0x30 < (uVar18 << 3 | 4))) goto LAB_0010cd48;
      ber_threshold = *(uint *)(ber_table + uVar18 * 8 + 4);
    }
    if ((override_ber_duration & 1) == 0) {
      ber_mon_dur_ms = 3600000;
    }
    if (ber_threshold < *(uint *)(lVar15 + 0x7a8)) {
      uVar4 = *(uint *)(lVar15 + 0x7a8) - 1;
      lVar11 = 0;
      uVar13 = (uVar4 & 0x1f) + 1;
      do {
        uVar6 = uVar13 - 1;
        uVar13 = 0x1f;
        if (-1 < (int)uVar6) {
          uVar13 = uVar6;
        }
        lVar11 = *(long *)(lVar16 + (ulong)uVar5 * 0x498 + (ulong)uVar13 * 8 + 0x5a8) + lVar11;
      } while (uVar13 != (uVar4 - ber_threshold & 0x1f));
      if (lVar11 < ber_mon_dur_ms) {
        uVar12 = *(undefined8 *)(lVar16 + 8);
        *(undefined1 *)(lVar16 + 0xc60) = 1;
        ufs_qcom_save_regs(lVar16,0,0xa0,"host_regs ");
        ufs_qcom_save_regs(lVar16,0xc0,0x40,"HCI Vendor Specific Registers ");
        ufs_qcom_save_regs(lVar16,0x2600,0x74,"HCI Shared ICE Registers ");
        ufs_qcom_save_regs(lVar16,0xe8,4,"UFS_TEST_BUS ");
        uVar18 = 0;
        plVar2 = (long *)(lVar16 + 0xc50);
        lVar11 = sp_el0;
        do {
          __s2 = "UNKNOWN ";
          if (uVar18 < 0xc) {
            __s2 = (&PTR_s_TSTBUS_UAWM_0011c500)[uVar18];
          }
          for (plVar19 = (long *)*plVar2; plVar19 != plVar2; plVar19 = (long *)*plVar19) {
            if (((char *)plVar19[2] != (char *)0x0) &&
               (iVar9 = strcmp((char *)plVar19[2],__s2), iVar9 == 0)) goto LAB_0010caf8;
          }
          uVar13 = *(uint *)(lVar11 + 0x44) & 0x80000;
          *(uint *)(lVar11 + 0x44) = *(uint *)(lVar11 + 0x44) | 0x80000;
          plVar19 = (long *)devm_kmalloc(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),0x28,0xb20
                                        );
          if (plVar19 == (long *)0x0) {
LAB_0010cbc0:
            *(uint *)(lVar11 + 0x44) = *(uint *)(lVar11 + 0x44) & 0xfff7ffff | uVar13;
            break;
          }
          lVar15 = devm_kmalloc(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),0x80,0xb20);
          plVar19[3] = lVar15;
          if (lVar15 == 0) goto LAB_0010cbc0;
          *(uint *)(lVar11 + 0x44) = *(uint *)(lVar11 + 0x44) & 0xfff7ffff | uVar13;
          plVar19[2] = (long)__s2;
          plVar19[4] = 0x80;
          puVar20 = *(undefined8 **)(lVar16 + 0xc58);
          uVar10 = __list_add_valid(plVar19,puVar20,plVar2);
          if ((uVar10 & 1) != 0) {
            *(long **)(lVar16 + 0xc58) = plVar19;
            *plVar19 = (long)plVar2;
            plVar19[1] = (long)puVar20;
            *puVar20 = plVar19;
          }
LAB_0010caf8:
          lVar15 = 0;
          *(char *)(lVar16 + 0xc4) = (char)uVar18;
          do {
            *(char *)(lVar16 + 0xc5) = (char)lVar15;
            ufs_qcom_testbus_config(lVar16);
            uVar8 = readl(**(long **)(lVar16 + 0x10) + 0xe8);
            *(undefined4 *)(plVar19[3] + lVar15 * 4) = uVar8;
            lVar15 = lVar15 + 1;
          } while (lVar15 != 0x20);
          uVar18 = uVar18 + 1;
        } while (uVar18 != 0xc);
        ufs_qcom_phy_dbg_register_save(uVar12);
        iVar9 = 0;
        do {
          uVar13 = iVar9 + *(int *)(lVar16 + 800);
          uVar5 = -uVar13;
          uVar13 = uVar13 & 0x1f;
          if (-1 < (int)uVar5) {
            uVar13 = -(uVar5 & 0x1f);
          }
          if (0x1f < uVar13) goto LAB_0010cd44;
          lVar11 = (long)(int)uVar13;
          lVar15 = *(long *)(lVar16 + lVar11 * 8 + 0x4a8);
          if (lVar15 != 0) {
            lVar3 = lVar16 + lVar11 * 4;
            _dev_err(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),
                     "pa_err_%d=0x%x, err_code=0x%x, gear=%d, time=%lld us\n",lVar11,
                     *(undefined4 *)(lVar3 + 0x324),*(undefined4 *)(lVar3 + 0x3a4),
                     *(undefined4 *)(lVar3 + 0x424),lVar15 / 1000);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x20);
        _dev_err(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),"total %llu PA error on %s mode\n"
                 ,*(undefined4 *)(lVar16 + 0x7a8),*(undefined8 *)(lVar16 + 0x7b0));
        iVar9 = 0;
        do {
          uVar13 = iVar9 + *(int *)(lVar16 + 0x7b8);
          uVar5 = -uVar13;
          uVar13 = uVar13 & 0x1f;
          if (-1 < (int)uVar5) {
            uVar13 = -(uVar5 & 0x1f);
          }
          if (0x1f < uVar13) goto LAB_0010cd44;
          lVar11 = (long)(int)uVar13;
          lVar15 = *(long *)(lVar16 + lVar11 * 8 + 0x940);
          if (lVar15 != 0) {
            lVar3 = lVar16 + lVar11 * 4;
            _dev_err(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),
                     "pa_err_%d=0x%x, err_code=0x%x, gear=%d, time=%lld us\n",lVar11,
                     *(undefined4 *)(lVar3 + 0x7bc),*(undefined4 *)(lVar3 + 0x83c),
                     *(undefined4 *)(lVar3 + 0x8bc),lVar15 / 1000);
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 != 0x20);
        _dev_err(*(undefined8 *)(*(long *)(lVar16 + 0x10) + 0x40),"total %llu PA error on %s mode\n"
                 ,*(undefined4 *)(lVar16 + 0xc40),*(undefined8 *)(lVar16 + 0xc48));
        if (crash_on_ber != '\0') {
          ufs_qcom_phy_dbg_register_dump(uVar17);
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10cd44);
          (*pcVar7)();
        }
      }
    }
  }
LAB_0010cb68:
  if ((*(char *)(lVar16 + 0xc60) != '\0') &&
     (iVar9 = ___ratelimit(ufs_qcom_event_notify__rs,"ufs_qcom_event_notify"), iVar9 != 0)) {
    _dev_warn(*(undefined8 *)(param_1 + 0x40),"Warning: UFS BER exceeds threshold !!!\n");
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_mcq_config_resource @ 0010cd54 size=920
// signature: undefined ufs_qcom_mcq_config_resource(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_mcq_config_resource(undefined8 *param_1)

{
  int *piVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  
  lVar7 = param_1[8] + -0x10;
  memcpy(param_1 + 0x276,&ufs_res_info,0xa8);
  plVar3 = (long *)platform_get_resource_byname(lVar7,0x200,"ufs_mem");
  param_1[0x277] = plVar3;
  if (plVar3 == (long *)0x0) {
    _dev_info(param_1[8],"Resource %s not provided\n",param_1[0x276]);
LAB_0010cfb0:
    iVar2 = -0xc;
  }
  else {
    puVar8 = param_1 + 0x279;
    param_1[0x278] = *param_1;
    lVar4 = platform_get_resource_byname(lVar7,0x200,param_1[0x279]);
    param_1[0x27a] = lVar4;
    if (lVar4 == 0) {
      _dev_info(param_1[8],"Resource %s not provided\n",*puVar8);
    }
    else {
      uVar5 = devm_ioremap_resource();
      param_1[0x27b] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        lVar7 = 0x13d8;
        goto LAB_0010d07c;
      }
    }
    puVar8 = param_1 + 0x27c;
    lVar4 = platform_get_resource_byname(lVar7,0x200,param_1[0x27c]);
    param_1[0x27d] = lVar4;
    if (lVar4 == 0) {
      _dev_info(param_1[8],"Resource %s not provided\n",*puVar8);
    }
    else {
      uVar5 = devm_ioremap_resource();
      param_1[0x27e] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        lVar7 = 0x13f0;
        goto LAB_0010d07c;
      }
    }
    puVar8 = param_1 + 0x27f;
    lVar4 = platform_get_resource_byname(lVar7,0x200,param_1[0x27f]);
    param_1[0x280] = lVar4;
    if (lVar4 == 0) {
      _dev_info(param_1[8],"Resource %s not provided\n",*puVar8);
    }
    else {
      uVar5 = devm_ioremap_resource();
      param_1[0x281] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        lVar7 = 0x1408;
        goto LAB_0010d07c;
      }
    }
    puVar8 = param_1 + 0x282;
    lVar4 = platform_get_resource_byname(lVar7,0x200,param_1[0x282]);
    param_1[0x283] = lVar4;
    if (lVar4 == 0) {
      _dev_info(param_1[8],"Resource %s not provided\n",*puVar8);
    }
    else {
      uVar5 = devm_ioremap_resource();
      param_1[0x284] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        lVar7 = 0x1420;
        goto LAB_0010d07c;
      }
    }
    puVar8 = param_1 + 0x285;
    lVar4 = platform_get_resource_byname(lVar7,0x200,param_1[0x285]);
    param_1[0x286] = lVar4;
    if (lVar4 == 0) {
      _dev_info(param_1[8],"Resource %s not provided\n",*puVar8);
    }
    else {
      uVar5 = devm_ioremap_resource();
      param_1[0x287] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        lVar7 = 0x1438;
        goto LAB_0010d07c;
      }
    }
    puVar8 = param_1 + 0x288;
    lVar7 = platform_get_resource_byname(lVar7,0x200,param_1[0x288]);
    param_1[0x289] = lVar7;
    if (lVar7 == 0) {
      _dev_info(param_1[8],"Resource %s not provided\n",*puVar8);
      uVar5 = param_1[0x27b];
    }
    else {
      uVar5 = devm_ioremap_resource();
      param_1[0x28a] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        lVar7 = 0x1450;
LAB_0010d07c:
        piVar1 = (int *)((long)param_1 + lVar7);
        _dev_err(param_1[8],"Failed to map res %s, err=%d\n",*puVar8,uVar5);
        piVar1[0] = 0;
        piVar1[1] = 0;
        return *piVar1;
      }
      uVar5 = param_1[0x27b];
    }
    if (uVar5 == 0) {
      plVar6 = (long *)devm_kmalloc(param_1[8],0x60,0xdc0);
      if (plVar6 == (long *)0x0) goto LAB_0010cfb0;
      iVar2 = *(int *)(param_1 + 0x273);
      lVar7 = *plVar3 + ((ulong)(*(uint *)(param_1 + 0x12) >> 7) & 0x1fe00);
      *plVar6 = lVar7;
      plVar6[1] = (ulong)(uint)(iVar2 << 6) + lVar7 + -1;
      lVar7 = plVar3[3];
      plVar6[2] = (long)&DAT_001221fe;
      plVar6[3] = lVar7;
      iVar2 = insert_resource(&iomem_resource,plVar6);
      if (iVar2 != 0) {
        _dev_err(param_1[8],"Failed to insert MCQ resource, err=%d\n",iVar2);
        return iVar2;
      }
      uVar5 = devm_ioremap_resource(param_1[8],plVar6);
      param_1[0x27b] = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        _dev_err(param_1[8],"MCQ registers mapping failed, err=%d\n");
        iVar2 = *(int *)(param_1 + 0x27b);
        param_1[0x27b] = 0;
        remove_resource(plVar6);
        return iVar2;
      }
    }
    iVar2 = 0;
    param_1[0x28b] = uVar5;
  }
  return iVar2;
}



//------------------------------------------------------------
// ufs_qcom_get_hba_mac @ 0010d0f0 size=8
// signature: undefined ufs_qcom_get_hba_mac(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_get_hba_mac(void)

{
  return 0x40;
}



//------------------------------------------------------------
// ufs_qcom_op_runtime_config @ 0010d0fc size=168
// signature: undefined ufs_qcom_op_runtime_config(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_op_runtime_config(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  
  if ((*(long *)(param_1 + 0x13c0) == 0) || (lVar1 = *(long *)(param_1 + 0x13f0), lVar1 == 0)) {
    return 0xffffffea;
  }
  plVar2 = *(long **)(param_1 + 0x13e8);
  plVar3 = *(long **)(param_1 + 0x13b8);
  lVar4 = *plVar2;
  lVar5 = *plVar3;
  *(undefined8 *)(param_1 + 0x1478) = 0x100;
  *(long *)(param_1 + 0x1480) = lVar1;
  *(long *)(param_1 + 0x1470) = lVar4 - lVar5;
  lVar4 = *plVar2;
  lVar5 = *plVar3;
  *(undefined8 *)(param_1 + 0x1490) = 0x100;
  *(long *)(param_1 + 0x1498) = lVar1 + 0x40;
  *(long *)(param_1 + 0x1488) = (lVar4 - lVar5) + 0x40;
  lVar4 = *plVar2;
  lVar5 = *plVar3;
  *(long *)(param_1 + 0x14b0) = lVar1 + 0x80;
  *(undefined8 *)(param_1 + 0x14a8) = 0x100;
  *(long *)(param_1 + 0x14a0) = (lVar4 - lVar5) + 0x80;
  lVar4 = *plVar2;
  lVar5 = *plVar3;
  *(undefined8 *)(param_1 + 0x14c0) = 0x100;
  *(long *)(param_1 + 0x14c8) = lVar1 + 0xc0;
  *(long *)(param_1 + 0x14b8) = (lVar4 - lVar5) + 0xc0;
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_get_outstanding_cqs @ 0010d1a8 size=72
// signature: undefined ufs_qcom_get_outstanding_cqs(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_get_outstanding_cqs(long param_1,ulong *param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x1450) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = readl(*(long *)(param_1 + 0x1450) + 8);
    uVar2 = 0;
    *param_2 = uVar1 & 0xffffffff;
  }
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_config_esi @ 0010d1f4 size=568
// signature: undefined ufs_qcom_config_esi(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_config_esi(long *param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  long lVar6;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10d42c);
    (*pcVar1)();
  }
  lVar6 = param_1[0x16];
  if (*(char *)(lVar6 + 0xc62) == '\0') {
    iVar2 = platform_msi_domain_alloc_irqs
                      (param_1[8],(int)param_1[0x273] - *(int *)((long)param_1 + 0x13a4),
                       ufs_qcom_write_msi_msg);
    if (iVar2 == 0) {
      mutex_lock(*(long *)(param_1[8] + 0x288) + 0x10);
      puVar4 = (undefined4 *)msi_first_desc(param_1[8],0);
      while (puVar4 != (undefined4 *)0x0) {
        iVar2 = devm_request_threaded_irq
                          (param_1[8],*puVar4,ufs_qcom_mcq_esi_handler,0,0x80,"qcom-mcq-esi",puVar4)
        ;
        if (iVar2 != 0) {
          _dev_err(param_1[8],"%s: Fail to request IRQ for %d, err = %d\n","ufs_qcom_config_esi",
                   *puVar4,iVar2);
          goto LAB_0010d2c0;
        }
        puVar4 = (undefined4 *)msi_next_desc(param_1[8],0);
      }
      iVar2 = 0;
LAB_0010d2c0:
      *(undefined8 *)(*(long *)(param_1[8] + 0x288) + 0x50) = 0xffff;
      mutex_unlock(*(long *)(param_1[8] + 0x288) + 0x10);
      if (iVar2 == 0) {
        if (((*(char *)(lVar6 + 0xa6) == '\x06') && (*(short *)(lVar6 + 0xa4) == 0)) &&
           (*(short *)(lVar6 + 0xa2) == 0)) {
          uVar3 = readl(*param_1 + 0x271c);
          writel(uVar3 | 0x1f000,*param_1 + 0x271c);
        }
        ufshcd_mcq_enable_esi(param_1);
        ufs_qcom_set_esi_affinity_hint(param_1);
        __cpuhp_setup_state(200,"ufs_qcom:online",0,ufs_qcom_cpu_online,0,0);
        iVar2 = 0;
        *(undefined1 *)(lVar6 + 0xc62) = 1;
      }
      else {
        mutex_lock(*(long *)(param_1[8] + 0x288) + 0x10);
        puVar5 = (undefined4 *)msi_first_desc(param_1[8],0);
        while ((puVar5 != (undefined4 *)0x0 && (puVar5 != puVar4))) {
          devm_free_irq(param_1[8],*puVar5,param_1);
          puVar5 = (undefined4 *)msi_next_desc(param_1[8],0);
        }
        *(undefined8 *)(*(long *)(param_1[8] + 0x288) + 0x50) = 0xffff;
        mutex_unlock(*(long *)(param_1[8] + 0x288) + 0x10);
        platform_msi_domain_free_irqs(param_1[8]);
      }
    }
    else {
      _dev_err(param_1[8],"Failed to request Platform MSI %d\n",iVar2);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// ufs_qcom_vdd_hba_reg_notifier @ 0010d430 size=52
// signature: undefined ufs_qcom_vdd_hba_reg_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_vdd_hba_reg_notifier(long param_1,long param_2)

{
  if (((param_2 == 0x80) && (*(int *)(*(long *)(param_1 + -0x150) + 0x54) == 2)) &&
     (*(int *)(param_1 + 0x168) != 0)) {
    *(undefined1 *)(param_1 + -8) = 1;
  }
  return 1;
}



//------------------------------------------------------------
// ufs_qcom_parse_reg_info @ 0010d464 size=460
// signature: undefined ufs_qcom_parse_reg_info(void)
// callers: [ufs_qcom_init, ufs_qcom_shutdown]
//------------------------------------------------------------

void ufs_qcom_parse_reg_info(long param_1,char *param_2,long *param_3)

{
  int iVar1;
  ulong *puVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  char local_b8 [32];
  long local_98 [11];
  
  lVar4 = sp_el0;
  local_98[10] = *(long *)(lVar4 + 0x638);
  local_b8[0x10] = '\0';
  local_b8[0x11] = '\0';
  local_b8[0x12] = '\0';
  local_b8[0x13] = '\0';
  local_b8[0x14] = '\0';
  local_b8[0x15] = '\0';
  local_b8[0x16] = '\0';
  local_b8[0x17] = '\0';
  local_b8[0x18] = '\0';
  local_b8[0x19] = '\0';
  local_b8[0x1a] = '\0';
  local_b8[0x1b] = '\0';
  local_b8[0x1c] = '\0';
  local_b8[0x1d] = '\0';
  local_b8[0x1e] = '\0';
  local_b8[0x1f] = '\0';
  local_b8[0] = '\0';
  local_b8[1] = '\0';
  local_b8[2] = '\0';
  local_b8[3] = '\0';
  local_b8[4] = '\0';
  local_b8[5] = '\0';
  local_b8[6] = '\0';
  local_b8[7] = '\0';
  local_b8[8] = '\0';
  local_b8[9] = '\0';
  local_b8[10] = '\0';
  local_b8[0xb] = '\0';
  local_b8[0xc] = '\0';
  local_b8[0xd] = '\0';
  local_b8[0xe] = '\0';
  local_b8[0xf] = '\0';
  lVar4 = *(long *)(*(long *)(param_1 + 0x10) + 0x40);
  lVar5 = *(long *)(lVar4 + 0x2e8);
  if (lVar5 == 0) {
    _dev_err(lVar4,"%s: non DT initialization\n","ufs_qcom_parse_reg_info");
    puVar2 = (ulong *)0x0;
  }
  else {
    snprintf(local_b8,0x20,"%s-supply",param_2);
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
    iVar1 = __of_parse_phandle_with_args(lVar5,local_b8,0,0,0,local_98);
    if ((iVar1 != 0) || (local_98[0] == 0)) {
      _dev_info(lVar4,"%s: Unable to find %s regulator, assuming enabled\n",
                "ufs_qcom_parse_reg_info",local_b8);
      goto LAB_0010d56c;
    }
    puVar2 = (ulong *)devm_kmalloc(lVar4,0x18,0xdc0);
    if (puVar2 == (ulong *)0x0) goto LAB_0010d56c;
    puVar2[1] = (ulong)param_2;
    snprintf(local_b8,0x20,"%s-max-microamp",param_2);
    iVar1 = of_property_read_variable_u32_array(lVar5,local_b8,(long)puVar2 + 0x14,1,0);
    if (iVar1 < 0) {
      _dev_err(lVar4,"%s: unable to find %s err %d\n","ufs_qcom_parse_reg_info",local_b8,iVar1);
      goto LAB_0010d56c;
    }
    uVar3 = devm_regulator_get(lVar4,puVar2[1]);
    *puVar2 = uVar3;
    if ((0xfffffffffffff000 < uVar3) &&
       (_dev_err(lVar4,"%s: %s get failed, err=%d\n","ufs_qcom_parse_reg_info",puVar2[1],
                 uVar3 & 0xffffffff), (int)uVar3 != 0)) goto LAB_0010d56c;
  }
  *param_3 = (long)puVar2;
LAB_0010d56c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_pm_levels @ 0010d630 size=248
// signature: undefined ufs_qcom_parse_pm_levels(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_parse_pm_levels(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10d728);
    (*pcVar1)();
  }
  lVar4 = *(long *)(param_1 + 0xb0);
  lVar3 = *(long *)(*(long *)(param_1 + 0x40) + 0x2e8);
  local_40 = 7;
  local_3c = 7;
  if (lVar3 != 0) {
    iVar2 = of_property_read_variable_u32_array(lVar3,"rpm-level",&local_3c,1,0);
    if ((-1 < iVar2) && (local_3c < 7)) {
      *(uint *)(param_1 + 0x58) = local_3c;
    }
    iVar2 = of_property_read_variable_u32_array(lVar3,"spm-level",&local_40,1,0);
    if ((-1 < iVar2) && (local_40 < 7)) {
      *(uint *)(param_1 + 0x5c) = local_40;
    }
    lVar3 = of_find_property(lVar3,"set-ds-spm-level",0);
    if (lVar3 != 0) {
      *(undefined1 *)(lVar4 + 0x198) = 1;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_g4_workaround_flag @ 0010d728 size=80
// signature: undefined ufs_qcom_parse_g4_workaround_flag(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_parse_g4_workaround_flag(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x40) + 0x2e8);
  if (lVar1 != 0) {
    lVar1 = of_find_property(lVar1,"bypass-g4-cfgready",0);
    *(bool *)(param_1 + 0x191) = lVar1 != 0;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_lpm @ 0010d778 size=112
// signature: undefined ufs_qcom_parse_lpm(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_parse_lpm(long param_1)

{
  long lVar1;
  
  lVar1 = of_find_property(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x40) + 0x2e8),
                           "qcom,disable-lpm",0);
  *(bool *)(param_1 + 0x14c) = lVar1 != 0;
  if (lVar1 != 0) {
    _dev_info(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),"(%s) All LPM is disabled\n",
              "ufs_qcom_parse_lpm");
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_wb @ 0010d7e8 size=104
// signature: undefined ufs_qcom_parse_wb(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_parse_wb(long param_1)

{
  long lVar1;
  
  lVar1 = of_find_property(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x10) + 0x40) + 0x2e8),
                           "qcom,disable-wb-support",0);
  *(bool *)(param_1 + 0x318) = lVar1 != 0;
  if (lVar1 != 0) {
    _printk(&DAT_001233e1,"ufs_qcom_parse_wb");
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_pbl_rst_workaround_flag @ 0010d850 size=80
// signature: undefined ufs_qcom_parse_pbl_rst_workaround_flag(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_parse_pbl_rst_workaround_flag(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x40) + 0x2e8);
  if (lVar1 != 0) {
    lVar1 = of_find_property(lVar1,"qcom,bypass-pbl-rst-wa",0);
    *(bool *)(param_1 + 0xc63) = lVar1 != 0;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_broken_ahit_workaround_flag @ 0010d8a0 size=80
// signature: undefined ufs_qcom_parse_broken_ahit_workaround_flag(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_parse_broken_ahit_workaround_flag(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0x40) + 0x2e8);
  if (lVar1 != 0) {
    lVar1 = of_find_property(lVar1,"qcom,broken-ahit-wa",0);
    *(bool *)(param_1 + 0xc80) = lVar1 != 0;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_set_caps @ 0010d8f0 size=112
// signature: undefined ufs_qcom_set_caps(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_set_caps(long param_1)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10d960);
    (*pcVar3)();
  }
  puVar4 = *(undefined4 **)(param_1 + 0xb0);
  if (*(char *)(puVar4 + 0x53) == '\0') {
    *(uint *)(param_1 + 0xbf0) = *(uint *)(param_1 + 0xbf0) | 0x120f;
  }
  uVar1 = *(uint *)(param_1 + 0xbf0) | 0x80;
  if (*(char *)(puVar4 + 0xc6) != '\0') {
    uVar1 = *(uint *)(param_1 + 0xbf0);
  }
  *(uint *)(param_1 + 0xbf0) = uVar1 | 0x100;
  bVar2 = *(byte *)((long)puVar4 + 0xa6);
  if ((1 < bVar2) && (*puVar4 = 3, bVar2 != 2)) {
    uVar5 = 0x1f;
    if (bVar2 < 5) {
      uVar5 = 0xf;
    }
    *puVar4 = uVar5;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_advertise_quirks @ 0010d960 size=168
// signature: undefined ufs_qcom_advertise_quirks(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_advertise_quirks(long param_1)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  byte *pbVar5;
  uint uVar6;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10da08);
    (*pcVar4)();
  }
  pbVar5 = *(byte **)(param_1 + 0xb0);
  bVar2 = pbVar5[0xa6];
  if (bVar2 == 1) {
    uVar1 = *(uint *)(param_1 + 0xcc);
    uVar3 = uVar1 | 0x1a;
    *(uint *)(param_1 + 0xcc) = uVar3;
    uVar6 = uVar3;
    if ((*(short *)(pbVar5 + 0xa4) == 1) && (uVar6 = uVar1 | 0x1b, *(short *)(pbVar5 + 0xa2) != 1))
    {
      uVar6 = uVar3;
    }
    *(uint *)(param_1 + 0xcc) = uVar6 | 4;
    bVar2 = pbVar5[0xa6];
  }
  if (bVar2 == 2) {
    uVar6 = *(uint *)(param_1 + 0xcc);
    *(uint *)(param_1 + 0xcc) = uVar6 | 0x20;
    if ((*pbVar5 & 1) == 0) {
      *(uint *)(param_1 + 0xcc) = uVar6 | 0x3a;
    }
  }
  if ((pbVar5[0x14c] != 0) || (pbVar5[0xc80] != 0)) {
    *(uint *)(param_1 + 0xcc) = *(uint *)(param_1 + 0xcc) | 0x800;
  }
  *(uint *)(param_1 + 0xd0) = *(uint *)(param_1 + 0xd0) | 1;
  return;
}



//------------------------------------------------------------
// ufs_qcom_shared_ice_init @ 0010da08 size=352
// signature: undefined ufs_qcom_shared_ice_init(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

int ufs_qcom_shared_ice_init(long param_1)

{
  char *__s1;
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  byte *pbVar6;
  char *local_90;
  long local_88 [11];
  
  lVar4 = sp_el0;
  local_88[10] = *(long *)(lVar4 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10db68);
    (*pcVar1)();
  }
  pbVar6 = *(byte **)(param_1 + 0xb0);
  if ((*pbVar6 >> 4 & 1) == 0) {
    iVar3 = 0;
    goto LAB_0010db30;
  }
  local_90 = (char *)0x0;
  local_88[0] = 0;
  local_88[8] = 0;
  local_88[9] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[1] = 0;
  iVar2 = __of_parse_phandle_with_args
                    (*(undefined8 *)(*(long *)(param_1 + 0x40) + 0x2e8),"shared-ice-cfg",0,0,0,
                     local_88);
  iVar3 = -2;
  if ((iVar2 != 0) || (local_88[0] == 0)) goto LAB_0010db30;
  lVar4 = of_get_next_available_child(local_88[0],0);
  *(long *)(pbVar6 + 0x2c0) = lVar4;
  if (lVar4 == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x40),"Resort to default alg2\n");
    iVar3 = 0;
LAB_0010db28:
    uVar5 = 1;
  }
  else {
    iVar3 = of_property_read_string(lVar4,"alg-name",&local_90);
    __s1 = local_90;
    if (iVar3 < 0) goto LAB_0010db30;
    iVar2 = strcmp(local_90,"alg1");
    if (iVar2 == 0) {
      uVar5 = 0;
    }
    else {
      iVar2 = strcmp(__s1,"alg2");
      if (iVar2 == 0) goto LAB_0010db28;
      iVar2 = strcmp(__s1,"alg3");
      if (iVar2 != 0) {
        iVar3 = -0x3d;
        goto LAB_0010db30;
      }
      uVar5 = 2;
    }
  }
  *(undefined4 *)(pbVar6 + 0x2c8) = uVar5;
LAB_0010db30:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// ufs_qcom_set_bus_vote @ 0010db68 size=144
// signature: undefined ufs_qcom_set_bus_vote(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_set_bus_vote(long param_1,ulong param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10dbf8);
    (*pcVar1)();
  }
  lVar3 = *(long *)(param_1 + 0xb0);
  if (lVar3 != 0) {
    if ((param_2 & 1) == 0) {
      iVar2 = *(int *)(lVar3 + 0x20);
    }
    else {
      iVar2 = *(int *)(lVar3 + 0x28);
      if (iVar2 == *(int *)(lVar3 + 0x20)) {
        ufs_qcom_update_bus_bw_vote(lVar3);
      }
    }
    iVar2 = __ufs_qcom_set_bus_vote(lVar3,iVar2);
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: set bus vote failed %d\n",
               "ufs_qcom_set_bus_vote",iVar2);
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_dev_ref_clk_ctrl @ 0010dbf8 size=192
// signature: undefined ufs_qcom_dev_ref_clk_ctrl(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_init, ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

void ufs_qcom_dev_ref_clk_ctrl(long param_1,byte param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*(long *)(param_1 + 0x98) != 0) {
    if (*(byte *)(param_1 + 0xa0) != (param_2 & 1)) {
      uVar3 = readl_relaxed();
      uVar1 = *(uint *)(param_1 + 0xbc);
      if ((param_2 & 1) == 0) {
        uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + 0xa24);
        if (uVar2 == 0) {
          __const_udelay(0x10c7);
        }
        else {
          usleep_range_state((ulong)uVar2 + 10,(ulong)uVar2 + 0x14,2);
        }
        writel_relaxed(uVar3 & (uVar1 ^ 0xffffffff),*(undefined8 *)(param_1 + 0x98));
        readl(*(undefined8 *)(param_1 + 0x98));
      }
      else {
        writel_relaxed(uVar1 | uVar3,*(undefined8 *)(param_1 + 0x98));
        readl(*(undefined8 *)(param_1 + 0x98));
        usleep_range_state(0x32,0x3c,2);
      }
      *(byte *)(param_1 + 0xa0) = param_2 & 1;
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_init_sysfs @ 0010dcb8 size=88
// signature: undefined ufs_qcom_init_sysfs(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_init_sysfs(long param_1)

{
  int iVar1;
  
  iVar1 = sysfs_create_group(*(undefined8 *)(param_1 + 0x40),&ufs_qcom_sysfs_group);
  if (iVar1 != 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: Failed to create qcom sysfs group (err = %d)\n",
             "ufs_qcom_init_sysfs",iVar1);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_get_host_id @ 0010dd10 size=96
// signature: undefined ufs_qcom_get_host_id(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

uint ufs_qcom_get_host_id(long param_1)

{
  uint uVar1;
  
  uVar1 = of_alias_get_id(*(undefined8 *)(*(long *)(param_1 + 0x40) + 0x2e8),"ufshc");
  if (2 < uVar1) {
    _dev_err(*(undefined8 *)(param_1 + 0x40),"Failed to get host index %d\n");
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// ufs_qcom_save_host_ptr @ 0010dd70 size=156
// signature: undefined ufs_qcom_save_host_ptr(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_save_host_ptr(long param_1)

{
  code *pcVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10de0c);
    (*pcVar1)();
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x40) + 0x2e8);
  if (lVar3 != 0) {
    uVar5 = *(undefined8 *)(param_1 + 0xb0);
    uVar2 = of_alias_get_id(lVar3,"ufshc");
    if ((int)uVar2 < 1) {
      uVar5 = *(undefined8 *)(param_1 + 0x40);
      pcVar4 = "Failed to get host index %d\n";
    }
    else {
      if (uVar2 < 3) {
        if (1 < uVar2 - 1) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x10de08);
          (*pcVar1)();
        }
        (&ufs_qcom_hosts)[uVar2 - 1] = uVar5;
        return;
      }
      uVar5 = *(undefined8 *)(param_1 + 0x40);
      pcVar4 = "invalid host index %d\n";
    }
    _dev_err(uVar5,pcVar4);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_populate_available_cpus @ 0010de0c size=388
// signature: undefined ufs_qcom_populate_available_cpus(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_populate_available_cpus(long param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10df90);
    (*pcVar2)();
  }
  iVar4 = 0;
  lVar5 = *(long *)(param_1 + 0xb0);
  uVar6 = 0xffffffff;
  local_68 = 0xffffffffffffffff;
  local_60 = 0xffffffffffffffff;
  while( true ) {
    uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar3) break;
    if ((uVar3 & 0xffffffe0) != 0) goto LAB_0010dec0;
    uVar1 = *(uint *)(__bitmap_subset + (ulong)uVar3 * 0x38);
    if (uVar1 != (uint)uVar6) {
      if (3 < uVar1) goto LAB_0010dec0;
      *(uint *)((long)&local_68 + (ulong)uVar1 * 4) = uVar3;
      uVar6 = (ulong)uVar1;
    }
    iVar4 = uVar3 + 1;
  }
  if ((uint)local_68 != 0xffffffff) {
    if (0x1f < (uint)local_68) goto LAB_0010dec0;
    *(undefined8 *)(lVar5 + 0x2f8) =
         *(undefined8 *)(__bitmap_weight + (local_68 & 0xffffffff) * 0x38);
  }
  if (local_68._4_4_ != 0xffffffff) {
    if (0x1f < local_68._4_4_) goto LAB_0010dec0;
    *(undefined8 *)(lVar5 + 0x300) = *(undefined8 *)(__bitmap_weight + (ulong)local_68._4_4_ * 0x38)
    ;
  }
  if ((uint)local_60 != 0xffffffff) {
    if (0x1f < (uint)local_60) goto LAB_0010dec0;
    *(undefined8 *)(lVar5 + 0x308) =
         *(undefined8 *)(__bitmap_weight + (local_60 & 0xffffffff) * 0x38);
  }
  if (local_60._4_4_ != 0xffffffff) {
    if (0x1f < local_60._4_4_) {
LAB_0010dec0:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10dec4);
      (*pcVar2)();
    }
    *(undefined8 *)(lVar5 + 0x310) = *(undefined8 *)(__bitmap_weight + (ulong)local_60._4_4_ * 0x38)
    ;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_qos_init @ 0010df90 size=1848
// signature: undefined ufs_qcom_qos_init(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_qos_init(long param_1)

{
  char cVar1;
  code *pcVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  long *plVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  void *__dest;
  undefined8 *puVar13;
  long lVar14;
  long lVar15;
  char *pcVar16;
  ulong uVar17;
  undefined8 uVar18;
  ulong uVar19;
  long lVar20;
  long lVar21;
  undefined8 uVar22;
  int local_6c;
  long local_68;
  
  uVar22 = _enable_irq;
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  lVar20 = *(long *)(param_1 + 0x40);
  local_6c = 0;
  uVar18 = *(undefined8 *)(lVar20 + 0x2e8);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10e6c8);
    (*pcVar2)();
  }
  lVar21 = *(long *)(param_1 + 0xb0);
  *(undefined1 *)(lVar21 + 0x298) = 1;
  plVar8 = (long *)kmalloc_trace(uVar22,0xdc0,0x18);
  if (plVar8 == (long *)0x0) goto LAB_0010e654;
  *(long **)(lVar21 + 0x1d8) = plVar8;
  puVar13 = (undefined8 *)(lVar21 + 0x1d8);
  lVar9 = of_get_next_available_child(uVar18,0);
  if (lVar9 == 0) {
    *(undefined4 *)(plVar8 + 1) = 0;
LAB_0010e454:
    _dev_err(lVar20,"QoS groups undefined\n");
  }
  else {
    iVar6 = 0;
    do {
      lVar9 = of_get_next_available_child(uVar18,lVar9);
      iVar6 = iVar6 + -1;
    } while (lVar9 != 0);
    *(int *)(plVar8 + 1) = -iVar6;
    if (iVar6 == 0) goto LAB_0010e454;
    uVar19 = (ulong)(uint)-iVar6 * 0x60;
    plVar10 = (long *)__kmalloc(uVar19,0xdc0);
    if (plVar10 != (long *)0x0) {
      *plVar8 = (long)plVar10;
      lVar9 = of_get_next_available_child(uVar18,0);
      if (lVar9 != 0) {
        uVar17 = 0;
        do {
          of_property_read_variable_u32_array(lVar9,&DAT_0011fcf6,&local_6c,1,0);
          uVar4 = _nr_cpu_ids;
          if (uVar19 <= uVar17) goto LAB_0010e6b8;
          *plVar10 = (long)local_6c;
          uVar11 = __bitmap_subset(plVar10,&__cpu_possible_mask,uVar4);
          if ((uVar11 & 1) == 0) {
            _dev_err(lVar20,"Invalid group mask\n");
            goto LAB_0010e630;
          }
          lVar12 = of_find_property(lVar9,&DAT_0012047e,0);
          bVar3 = uVar19 < uVar17 + 0x5c;
          if (lVar12 == 0) {
            if (bVar3) goto LAB_0010e6b8;
            *(undefined1 *)((long)plVar10 + 0x5c) = 0;
          }
          else {
            if (bVar3) goto LAB_0010e6b8;
            *(undefined1 *)((long)plVar10 + 0x5c) = 1;
            *(undefined1 *)(lVar21 + 0x298) = 0;
          }
          uVar4 = of_property_count_elems_of_size(lVar9,&DAT_0012297d,4);
          uVar11 = (ulong)uVar4;
          if ((int)uVar4 < 1) {
            _dev_err(lVar20,"1 vote is needed, bailing out: %d\n",uVar11);
            goto LAB_0010e630;
          }
          lVar12 = __kmalloc(uVar11 << 2,0xcc0);
          if (uVar19 < (uVar17 | 8)) {
LAB_0010e6b8:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x10e6bc);
            (*pcVar2)();
          }
          plVar10[1] = lVar12;
          if (lVar12 == 0) goto LAB_0010e630;
          lVar12 = 0;
          iVar6 = 0;
          do {
            if (uVar19 < (uVar17 | 8)) goto LAB_0010e6b8;
            iVar5 = of_property_read_u32_index(lVar9,&DAT_0012297d,iVar6,plVar10[1] + lVar12);
            if (iVar5 != 0) goto LAB_0010e600;
            iVar6 = iVar6 + 1;
            lVar12 = lVar12 + 4;
          } while (uVar11 * 4 != lVar12);
          uVar22 = *(undefined8 *)(param_1 + 0x40);
          lVar12 = *(long *)(param_1 + 0xb0);
          iVar6 = of_property_count_elems_of_size(lVar9,"cpu_freq_vote",4);
          if (iVar6 < 1) {
            _dev_warn(uVar22,"no cpu_freq_vote found\n");
          }
          else {
            __dest = (void *)__kmalloc((long)(*(int *)(lVar12 + 0x2a8) + iVar6) * 0xc,0xdc0);
            if (__dest == (void *)0x0) {
              _dev_err(uVar22,"allocating memory for cpufreq info failed\n");
            }
            else {
              memcpy(__dest,*(void **)(lVar12 + 0x2a0),(long)*(int *)(lVar12 + 0x2a8) * 0xc);
              iVar5 = 0;
              do {
                of_property_read_u32_index
                          (lVar9,"cpu_freq_vote",iVar5,
                           (void *)((long)__dest + (long)(iVar5 + *(int *)(lVar12 + 0x2a8)) * 0xc));
                iVar5 = iVar5 + 1;
              } while (iVar6 != iVar5);
              kfree(*(undefined8 *)(lVar12 + 0x2a0));
              *(void **)(lVar12 + 0x2a0) = __dest;
              *(int *)(lVar12 + 0x2a8) = *(int *)(lVar12 + 0x2a8) + iVar6;
            }
          }
          if ((uVar19 < uVar17 + 0x50) || (uVar19 - (uVar17 + 0x50) < 8)) goto LAB_0010e6b8;
          plVar10[10] = lVar21;
          uVar17 = uVar17 + 0x60;
          plVar10 = plVar10 + 0xc;
          lVar9 = of_get_next_available_child(uVar18,lVar9);
        } while (lVar9 != 0);
      }
      lVar9 = *(long *)(param_1 + 0xb0);
      uVar22 = *(undefined8 *)(param_1 + 0x40);
      plVar10 = *(long **)(lVar9 + 0x1d8);
      lVar20 = *plVar10;
      if ((int)plVar10[1] != 0) {
        uVar19 = 0;
        uVar4 = _nr_cpu_ids;
        do {
          uVar17 = __bitmap_weight(lVar20,uVar4);
          puVar13 = (undefined8 *)__kmalloc((uVar17 & 0xffffffff) * 0x50,0xdc0);
          *(undefined8 **)(lVar20 + 0x10) = puVar13;
          if (puVar13 == (undefined8 *)0x0) goto LAB_0010e5e8;
          iVar6 = 0;
          while( true ) {
            uVar7 = _find_next_bit(lVar20,_nr_cpu_ids,(long)iVar6);
            uVar4 = _nr_cpu_ids;
            if (_nr_cpu_ids <= uVar7) break;
            puVar13[8] = 0;
            puVar13[9] = 0;
            puVar13[6] = 0;
            puVar13[7] = 0;
            puVar13[4] = 0;
            puVar13[5] = 0;
            puVar13[2] = 0;
            puVar13[3] = 0;
            *puVar13 = 0;
            puVar13[1] = 0;
            uVar18 = get_cpu_device(uVar7);
            iVar6 = dev_pm_qos_add_request(uVar18,puVar13,1,0x7fffffff);
            if (iVar6 < 0) {
              _dev_err(uVar22,"Fail (%d) add qos-req: grp-%d\n",iVar6,uVar19);
              if ((int)uVar19 != 0) goto LAB_0010e5ec;
              kfree(*(undefined8 *)(lVar20 + 0x10));
              goto LAB_0010e600;
            }
            puVar13 = puVar13 + 10;
            iVar6 = uVar7 + 1;
          }
          uVar7 = (int)uVar19 + 1;
          uVar19 = (ulong)uVar7;
          *(undefined8 *)(lVar20 + 0x20) = 0xfffffffe0;
          *(long *)(lVar20 + 0x28) = lVar20 + 0x28;
          *(long *)(lVar20 + 0x30) = lVar20 + 0x28;
          *(code **)(lVar20 + 0x38) = ufs_qcom_vote_work;
          lVar20 = lVar20 + 0x60;
        } while (uVar7 < *(uint *)(plVar10 + 1));
      }
      iVar6 = *(int *)(lVar9 + 0x2a8);
      if (iVar6 < 1) {
        uVar19 = 0;
        cVar1 = *(char *)(lVar9 + 0x298);
      }
      else {
        lVar12 = 0;
        uVar19 = 0;
        do {
          lVar14 = cpufreq_cpu_get(*(undefined4 *)(*(long *)(lVar9 + 0x2a0) + lVar12));
          if (lVar14 == 0) {
            pcVar16 = "Failed cpufreq policy,cpu=%u\n";
            iVar6 = *(int *)(*(long *)(lVar9 + 0x2a0) + lVar12);
            goto LAB_0010e5b4;
          }
          *(undefined4 *)(*(long *)(lVar9 + 0x2a0) + lVar12 + 4) = *(undefined4 *)(lVar14 + 0x2c);
          *(undefined4 *)(*(long *)(lVar9 + 0x2a0) + lVar12 + 8) = *(undefined4 *)(lVar14 + 0x28);
          cpufreq_cpu_put();
          iVar6 = *(int *)(lVar9 + 0x2a8);
          uVar19 = uVar19 + 1;
          lVar12 = lVar12 + 0xc;
        } while ((long)uVar19 < (long)iVar6);
        cVar1 = *(char *)(lVar9 + 0x298);
      }
      if (cVar1 == '\0') {
        if (iVar6 < 1) {
          iVar6 = -0x16;
        }
        else {
          lVar14 = 0;
          lVar12 = 0;
          do {
            uVar4 = *(uint *)(*(long *)(lVar9 + 0x2a0) + lVar14);
            uVar17 = (ulong)uVar4;
            lVar15 = cpufreq_cpu_get(uVar17);
            if (lVar15 == 0) {
              _dev_err(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40),
                       "Failed to get cpu(%u)freq policy\n",uVar17);
              iVar6 = -0x16;
              goto LAB_0010e5a4;
            }
            if (0x1f < uVar4) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10e6c4);
              (*pcVar2)();
            }
            iVar6 = freq_qos_add_request
                              (lVar15 + 0xa0,
                               &qos_min_req + *(long *)(&__per_cpu_offset + uVar17 * 8),1,0);
            cpufreq_cpu_put(lVar15);
            if (iVar6 < 0) {
              _dev_err(*(undefined8 *)(*(long *)(lVar9 + 0x10) + 0x40),
                       "Failed to add freq qos req(%u), err=%d\n",uVar17,iVar6);
              goto LAB_0010e5a4;
            }
            lVar12 = lVar12 + 1;
            lVar14 = lVar14 + 0xc;
          } while (lVar12 < *(int *)(lVar9 + 0x2a8));
          if (iVar6 == 0) {
            *(undefined8 *)(lVar9 + 0x210) = 0xfffffffe0;
            *(long *)(lVar9 + 0x218) = lVar9 + 0x218;
            *(long *)(lVar9 + 0x220) = lVar9 + 0x218;
            *(code **)(lVar9 + 0x228) = ufs_qcom_cpufreq_dwork;
            init_timer_key(lVar9 + 0x240,&delayed_work_timer_fn,0x200000,0,0);
            goto LAB_0010e5c0;
          }
        }
LAB_0010e5a4:
        pcVar16 = "Failed to register for freq_qos: %d\n";
LAB_0010e5b4:
        _dev_err(uVar22,pcVar16,iVar6);
        *(undefined1 *)(lVar9 + 0x298) = 1;
      }
LAB_0010e5c0:
      lVar9 = alloc_workqueue(&DAT_00120bae,0xe000a,1,"qc_ufs_qos_swq");
      plVar10[2] = lVar9;
      if (lVar9 != 0) goto LAB_0010e654;
LAB_0010e5e8:
      if ((int)uVar19 != 0) {
LAB_0010e5ec:
        puVar13 = (undefined8 *)(lVar20 + 0x10);
        do {
          uVar4 = (int)uVar19 - 1;
          uVar19 = (ulong)uVar4;
          kfree(*puVar13);
          puVar13 = puVar13 + -0xc;
        } while (uVar4 != 0);
      }
LAB_0010e600:
      if ((int)plVar8[1] != 0) {
        uVar4 = 0;
        puVar13 = (undefined8 *)(*plVar8 + 8);
        do {
          kfree(*puVar13);
          uVar4 = uVar4 + 1;
          puVar13 = puVar13 + 0xc;
        } while (uVar4 < *(uint *)(plVar8 + 1));
      }
LAB_0010e630:
      kfree(*plVar8);
      kfree(plVar8);
      puVar13 = (undefined8 *)(lVar21 + 0x2a0);
      plVar8 = *(long **)(lVar21 + 0x2a0);
      *(undefined8 *)(lVar21 + 0x1d8) = 0;
    }
  }
  kfree(plVar8);
  *puVar13 = 0;
LAB_0010e654:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_parse_irq_affinity @ 0010e6c8 size=336
// signature: undefined ufs_qcom_parse_irq_affinity(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_parse_irq_affinity(long param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  int local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10e818);
    (*pcVar2)();
  }
  lVar4 = *(long *)(param_1 + 0x40);
  local_4c = 0;
  lVar6 = *(long *)(param_1 + 0xb0);
  lVar5 = *(long *)(lVar4 + 0x2e8);
  if (lVar5 != 0) {
    of_property_read_variable_u32_array(lVar5,"qcom,prime-mask",&local_4c,1,0);
    uVar1 = _nr_cpu_ids;
    *(long *)(lVar6 + 0x2e8) = (long)local_4c;
    uVar3 = __bitmap_subset((undefined8 *)(lVar6 + 0x2e8),&__cpu_possible_mask,uVar1);
    if ((uVar3 & 1) == 0) {
      _dev_err(lVar4,"Invalid group prime mask\n");
      *(undefined8 *)(lVar6 + 0x2e8) = 0x80;
    }
    local_4c = 0;
    of_property_read_variable_u32_array(lVar5,"qcom,silver-mask",&local_4c,1,0);
    uVar1 = _nr_cpu_ids;
    *(long *)(lVar6 + 0x2f0) = (long)local_4c;
    uVar3 = __bitmap_subset((undefined8 *)(lVar6 + 0x2f0),&__cpu_possible_mask,uVar1);
    if ((uVar3 & 1) == 0) {
      _dev_err(lVar4,"Invalid group silver mask\n");
      *(undefined8 *)(lVar6 + 0x2f0) = 0xf;
      lVar4 = *(long *)(lVar6 + 0x2e8);
      goto joined_r0x0010e794;
    }
  }
  lVar4 = *(long *)(lVar6 + 0x2e8);
joined_r0x0010e794:
  if (lVar4 != 0) {
    *(undefined1 *)(lVar6 + 0xc61) = 1;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// get_storage_info @ 0010e818 size=232
// signature: undefined get_storage_info(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void get_storage_info(long param_1)

{
  int iVar1;
  long lVar2;
  char *__s1;
  undefined8 *puVar3;
  
  storage_mfrid = 0;
  lVar2 = of_find_node_opts_by_path("/chosen/mmi,storage",0);
  if (lVar2 != 0) {
    for (puVar3 = *(undefined8 **)(lVar2 + 0x60); puVar3 != (undefined8 *)0x0;
        puVar3 = (undefined8 *)puVar3[3]) {
      iVar1 = strcmp((char *)*puVar3,"manufacturer");
      if (((iVar1 == 0) && (__s1 = (char *)puVar3[2], __s1 != (char *)0x0)) &&
         ((iVar1 = strncasecmp(__s1,"SKHYNIX",8), iVar1 == 0 ||
          (iVar1 = strncasecmp(__s1,"HYNIX",6), iVar1 == 0)))) {
        storage_mfrid = 0x1ad;
      }
    }
    _dev_info(*(undefined8 *)(param_1 + 0x40),"manufacturer parsed from choosen is 0x%x\n",
              storage_mfrid);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_register_minidump @ 0010e900 size=240
// signature: undefined ufs_qcom_register_minidump(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_register_minidump
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  long local_50;
  long local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  uVar3 = msm_minidump_enabled();
  if ((uVar3 & 1) != 0) {
    scnprintf(&local_68,0xd,&DAT_00121c44,param_3,param_4);
    lVar1 = (param_1 << 8) >> 8;
    uVar3 = lVar1 + 0x8000000000;
    local_48 = _memstart_addr + uVar3;
    if (uVar3 >> 0x26 != 0) {
      local_48 = lVar1 - _kimage_voffset;
    }
    local_50 = param_1;
    local_40 = param_2;
    iVar2 = msm_minidump_add_region(&local_68);
    if (iVar2 < 0) {
      _printk(&DAT_0011fd18,param_3,iVar2);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_panic_handler @ 0010e9f4 size=480
// signature: undefined ufs_qcom_panic_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_panic_handler(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + -0xc58);
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"......dumping ufs info .......\n");
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"UFS Host state=%d\n",*(undefined4 *)(lVar2 + 0x1e8));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"outstanding reqs=0x%lx tasks=0x%lx\n",
           *(undefined8 *)(lVar2 + 0x80),*(undefined8 *)(lVar2 + 0x70));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"saved_err=0x%x, saved_uic_err=0x%x\n",
           *(undefined4 *)(lVar2 + 0x2c0),*(undefined4 *)(lVar2 + 0x2c4));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"Device power mode=%d, UIC link state=%d\n",
           *(undefined4 *)(lVar2 + 0x50),*(undefined4 *)(lVar2 + 0x54));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"PM in progress=%d, sys. suspended=%d\n",
           *(undefined4 *)(lVar2 + 0x60),*(undefined1 *)(lVar2 + 0xce1));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"Clk gate=%d\n",*(undefined4 *)(lVar2 + 0xb80));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),
           "last_hibern8_exit_tstamp at %lld us, hibern8_exit_cnt=%d\n",
           *(long *)(lVar2 + 0x2e0) / 1000,*(undefined4 *)(lVar2 + 0x2d8));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"last intr at %lld us, last intr status=0x%x\n",
           *(long *)(lVar2 + 0x2d0) / 1000,*(undefined4 *)(lVar2 + 0x2c8));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"error handling flags=0x%x, req. abort count=%d\n",
           *(undefined4 *)(lVar2 + 0x1f0),*(undefined4 *)(lVar2 + 0xa80));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),
           "hba->ufs_version=0x%x, Host capabilities=0x%x, caps=0x%x\n",
           *(undefined4 *)(lVar2 + 0x9c),*(undefined4 *)(lVar2 + 0x88),
           *(undefined4 *)(lVar2 + 0xbf0));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"quirks=0x%x, dev. quirks=0x%x\n",
           *(undefined4 *)(lVar2 + 0xcc),*(undefined4 *)(lVar2 + 0xd4));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"[RX, TX]: gear=[%d, %d], lane[%d, %d], rate = %d\n",
           *(undefined4 *)(lVar2 + 0xa88),*(undefined4 *)(lVar2 + 0xa8c),
           *(undefined4 *)(lVar2 + 0xa90),*(undefined4 *)(lVar2 + 0xa94),
           *(undefined4 *)(lVar2 + 0xaa0));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"UFS RPM level = %d\n",*(undefined4 *)(lVar2 + 0x58));
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"UFS SPM level = %d\n",*(undefined4 *)(lVar2 + 0x5c));
  lVar1 = *(long *)(lVar2 + 0x38);
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"host_blocked=%d\n host_failed =%d\n Host self-block=%d\n",
           *(undefined4 *)(lVar1 + 0x1b0),*(undefined4 *)(lVar1 + 0x1b4),
           *(ushort *)(lVar1 + 0x220) >> 2 & 1);
  _dev_err(*(undefined8 *)(lVar2 + 0x40),"............. ufs dump complete ..........\n");
  return 1;
}



//------------------------------------------------------------
// ufs_qcom_disable_vreg @ 0010ebd4 size=104
// signature: undefined ufs_qcom_disable_vreg(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void ufs_qcom_disable_vreg(undefined8 *param_1)

{
  code *pcVar1;
  int iVar2;
  
  if ((*(char *)((long)param_1 + 0x11) != '\0') && (iVar2 = regulator_disable(*param_1), iVar2 == 0)
     ) {
    if (param_1 == (undefined8 *)0x0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10ec3c);
      (*pcVar1)();
    }
    iVar2 = regulator_count_voltages(*param_1);
    if ((iVar2 < 1) || (iVar2 = regulator_set_load(*param_1,0), iVar2 == 0)) {
      *(undefined1 *)((long)param_1 + 0x11) = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_reset_assert @ 0010ec44 size=96
// signature: undefined ufs_qcom_reset_assert(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_reset_assert(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + -0xc0);
  uVar1 = readl(*plVar2 + 0xdc);
  writel(uVar1 | 2,*plVar2 + 0xdc);
  readl(*plVar2 + 0xdc);
  usleep_range_state(1000,0x44c,2);
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_reset_deassert @ 0010eca8 size=96
// signature: undefined ufs_qcom_reset_deassert(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_reset_deassert(long param_1)

{
  uint uVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + -0xc0);
  uVar1 = readl(*plVar2 + 0xdc);
  writel(uVar1 & 0xfffffffd,*plVar2 + 0xdc);
  readl(*plVar2 + 0xdc);
  usleep_range_state(1000,0x44c,2);
  return 0;
}



//------------------------------------------------------------
// show_ufs_to_mem_max_bus_bw @ 0010ed0c size=68
// signature: undefined show_ufs_to_mem_max_bus_bw(void)
// callers: []
//------------------------------------------------------------

long show_ufs_to_mem_max_bus_bw(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10ed50);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_00120448,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x2c));
  return (long)iVar2;
}



//------------------------------------------------------------
// store_ufs_to_mem_max_bus_bw @ 0010ed54 size=148
// signature: undefined store_ufs_to_mem_max_bus_bw(void)
// callers: []
//------------------------------------------------------------

undefined8
store_ufs_to_mem_max_bus_bw(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10ede8);
    (*pcVar1)();
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0xb0);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    *(bool *)(lVar3 + 0x2c) = local_2c != 0;
    ufs_qcom_update_bus_bw_vote(lVar3);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ufs_qcom_update_bus_bw_vote @ 0010ede8 size=464
// signature: undefined ufs_qcom_update_bus_bw_vote(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_set_bus_vote, store_ufs_to_mem_max_bus_bw, ufs_qcom_clk_scale_notify, ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

void ufs_qcom_update_bus_bw_vote(long param_1)

{
  char *param4;
  int *piVar1;
  uint param4_00;
  uint param5;
  int iVar2;
  int iVar3;
  long lVar4;
  int local_58 [8];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_58[4] = 0;
  local_58[5] = 0;
  local_58[6] = 0;
  local_58[7] = 0;
  local_58[0] = 0;
  local_58[1] = 0;
  local_58[2] = 0;
  local_58[3] = 0;
  param4_00 = *(uint *)(param_1 + 0x50);
  if (*(uint *)(param_1 + 0x50) <= *(uint *)(param_1 + 0x54)) {
    param4_00 = *(uint *)(param_1 + 0x54);
  }
  param5 = *(uint *)(param_1 + 0x58);
  if (*(uint *)(param_1 + 0x58) <= *(uint *)(param_1 + 0x5c)) {
    param5 = *(uint *)(param_1 + 0x5c);
  }
  if (param4_00 == 0) {
    param4_00 = 1;
  }
  iVar2 = *(int *)(param_1 + 0x60);
  if (param5 == 0) {
    param5 = 1;
  }
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 100);
    if (iVar2 != 0) goto LAB_0010ee70;
    local_58[0] = 0x4e494d;
    local_58[1] = 0;
  }
  else {
    if ((iVar2 != 1) && (iVar2 != 4)) {
      iVar2 = *(int *)(param_1 + 100);
LAB_0010ee70:
      if ((iVar2 != 4) && (iVar2 != 1)) {
        snprintf((char *)local_58,0x20,"%s_G%d_L%d","PWM",param4_00,param5);
        goto LAB_0010eeb8;
      }
    }
    param4 = "B";
    if (*(int *)(param_1 + 0x68) != 2) {
      param4 = "A";
    }
    snprintf((char *)local_58,0x20,"%s_R%s_G%d_L%d","HS",param4,param4_00,param5);
  }
LAB_0010eeb8:
  piVar1 = local_58;
  lVar4 = *(long *)(*(long *)(param_1 + 0x10) + 0x40);
  if (local_58[0] != 0x4e494d && *(char *)(param_1 + 0x2c) != '\0') {
    piVar1 = (int *)&DAT_00123697;
  }
  iVar2 = of_property_match_string(*(undefined8 *)(lVar4 + 0x2e8),"qcom,bus-vector-names",piVar1);
  if (iVar2 < 0) {
    _dev_err(lVar4,"%s: Invalid %s mode %d\n","ufs_qcom_get_bus_vote",local_58,iVar2);
  }
  else {
    iVar3 = __ufs_qcom_set_bus_vote(param_1,iVar2);
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x28) = iVar2;
      goto LAB_0010ef0c;
    }
    iVar2 = iVar3;
  }
  _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),"%s: failed %d\n",
           "ufs_qcom_update_bus_bw_vote",iVar2);
LAB_0010ef0c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __ufs_qcom_set_bus_vote @ 0010efb8 size=240
// signature: undefined __ufs_qcom_set_bus_vote(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_set_bus_vote, ufs_qcom_update_bus_bw_vote]
//------------------------------------------------------------

int __ufs_qcom_set_bus_vote(long param_1,uint param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  long *plVar7;
  
  plVar7 = *(long **)(param_1 + 0x150);
  uVar6 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40);
  if ((plVar7 == (long *)0x0) || (*(uint *)(plVar7 + 1) < param_2)) {
    _dev_err(uVar6,"Error: failed (%d) to get ib/ab\n",0xffffffea);
    return -0x16;
  }
  puVar5 = *(undefined4 **)(*plVar7 + (long)(int)param_2 * 0x10 + 8);
  uVar1 = puVar5[2];
  uVar2 = puVar5[3];
  iVar3 = icc_set_bw(plVar7[2],*puVar5,puVar5[1]);
  if (iVar3 == 0) {
    iVar3 = icc_set_bw(plVar7[3],uVar1,uVar2);
    if (iVar3 == 0) {
      *(uint *)(param_1 + 0x1c) = param_2;
      return 0;
    }
    pcVar4 = "cpu-ufs";
  }
  else {
    pcVar4 = "ufs-ddr";
  }
  _dev_err(uVar6,"Error: failed (%d) setting (%s) bus vote\n",iVar3,pcVar4);
  return iVar3;
}



//------------------------------------------------------------
// readl_relaxed @ 0010f0a8 size=124
// signature: undefined readl_relaxed(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_link_startup_notify, ufs_qcom_dev_ref_clk_ctrl, ufs_qcom_pwr_change_notify]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10f0f0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 0010f124 size=132
// signature: undefined writel_relaxed(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_link_startup_notify, ufs_qcom_dev_ref_clk_ctrl, ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10f13c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10f178,uVar1);
  return;
}



//------------------------------------------------------------
// err_state_show @ 0010f1ac size=68
// signature: undefined err_state_show(void)
// callers: []
//------------------------------------------------------------

long err_state_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f1f0);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x1f0));
  return (long)iVar2;
}



//------------------------------------------------------------
// power_mode_show @ 0010f1f4 size=168
// signature: undefined power_mode_show(void)
// callers: []
//------------------------------------------------------------

long power_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined4 uVar6;
  
  lVar5 = *(long *)(param_1 + 0x98);
  uVar1 = *(uint *)(lVar5 + 0xa98);
  if (uVar1 < 7) {
    uVar2 = *(uint *)(lVar5 + 0xa9c);
    if (uVar2 < 7) {
      if ((6 < uVar1) || (6 < uVar2)) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x10f29c);
        (*pcVar3)();
      }
      uVar6 = 0x41;
      if (*(int *)(lVar5 + 0xaa0) == 2) {
        uVar6 = 0x42;
      }
      iVar4 = scnprintf(param_3,0x1000,"[Rx,Tx]: Gear[%d,%d], Lane[%d,%d], PWR[%s,%s], Rate-%c\n",
                        *(undefined4 *)(lVar5 + 0xa88),*(undefined4 *)(lVar5 + 0xa8c),
                        *(undefined4 *)(lVar5 + 0xa90),*(undefined4 *)(lVar5 + 0xa94),
                        (&power_mode_show_names)[uVar1],(&power_mode_show_names)[uVar2],uVar6);
      return (long)iVar4;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10f298);
  (*pcVar3)();
}



//------------------------------------------------------------
// bus_speed_mode_show @ 0010f2a0 size=76
// signature: undefined bus_speed_mode_show(void)
// callers: []
//------------------------------------------------------------

long bus_speed_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f2ec);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(int *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 500) != 0);
  return (long)iVar2;
}



//------------------------------------------------------------
// clk_status_show @ 0010f2f0 size=76
// signature: undefined clk_status_show(void)
// callers: []
//------------------------------------------------------------

long clk_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f33c);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(int *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x1f8) != 0);
  return (long)iVar2;
}



//------------------------------------------------------------
// err_count_show @ 0010f340 size=704
// signature: undefined err_count_show(void)
// callers: []
//------------------------------------------------------------

long err_count_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  
  lVar10 = *(long *)(param_1 + 0x98);
  uVar5 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38));
  iVar8 = 0;
  iVar4 = 0;
  do {
    uVar1 = iVar4 + *(int *)(lVar10 + 0x2e8);
    uVar2 = -uVar1;
    uVar1 = uVar1 & 7;
    if (-1 < (int)uVar2) {
      uVar1 = -(uVar2 & 7);
    }
    if (7 < uVar1) goto LAB_0010f5fc;
    lVar6 = (long)(int)uVar1;
    lVar7 = *(long *)(lVar10 + lVar6 * 8 + 0x310);
    if (lVar7 != 0) {
      _dev_err(*(undefined8 *)(lVar10 + 0x40),"%s[%d] = 0x%x at %lld us\n","pa_err_cnt_total",lVar6,
               *(undefined4 *)(lVar10 + lVar6 * 4 + 0x2ec),lVar7 / 1000);
      iVar8 = iVar8 + 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
  _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38),uVar5);
  uVar5 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38));
  iVar9 = 0;
  iVar4 = 0;
  do {
    uVar1 = iVar4 + *(int *)(lVar10 + 0x358);
    uVar2 = -uVar1;
    uVar1 = uVar1 & 7;
    if (-1 < (int)uVar2) {
      uVar1 = -(uVar2 & 7);
    }
    if (7 < uVar1) goto LAB_0010f5fc;
    lVar6 = (long)(int)uVar1;
    lVar7 = *(long *)(lVar10 + lVar6 * 8 + 0x380);
    if (lVar7 != 0) {
      _dev_err(*(undefined8 *)(lVar10 + 0x40),"%s[%d] = 0x%x at %lld us\n","dl_err_cnt_total",lVar6,
               *(undefined4 *)(lVar10 + lVar6 * 4 + 0x35c),lVar7 / 1000);
      iVar9 = iVar9 + 1;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 8);
  _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38),uVar5);
  uVar5 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38));
  iVar11 = 0;
  iVar4 = 0;
  while( true ) {
    uVar1 = iVar4 + *(int *)(lVar10 + 0x4a8);
    uVar2 = -uVar1;
    uVar1 = uVar1 & 7;
    if (-1 < (int)uVar2) {
      uVar1 = -(uVar2 & 7);
    }
    if (7 < uVar1) break;
    lVar6 = (long)(int)uVar1;
    lVar7 = *(long *)(lVar10 + lVar6 * 8 + 0x4d0);
    if (lVar7 != 0) {
      _dev_err(*(undefined8 *)(lVar10 + 0x40),"%s[%d] = 0x%x at %lld us\n","dme_err_cnt",lVar6,
               *(undefined4 *)(lVar10 + lVar6 * 4 + 0x4ac),lVar7 / 1000);
      iVar11 = iVar11 + 1;
    }
    iVar4 = iVar4 + 1;
    if (iVar4 == 8) {
      _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(lVar10 + 0x38) + 0x38),uVar5);
      iVar4 = scnprintf(param_3,0x1000,"%s: %d\n%s: %d\n%s: %d\n%s: %d\n","pa_err_cnt_total",iVar8,
                        "dl_err_cnt_total",iVar9,"dme_err_cnt",iVar11,"req_abort_cnt",
                        *(undefined4 *)(lVar10 + 0xa80));
      return (long)iVar4;
    }
  }
LAB_0010f5fc:
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10f600);
  (*pcVar3)();
}



//------------------------------------------------------------
// dbg_state_show @ 0010f604 size=68
// signature: undefined dbg_state_show(void)
// callers: []
//------------------------------------------------------------

long dbg_state_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f648);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x2b8));
  return (long)iVar2;
}



//------------------------------------------------------------
// dbg_state_store @ 0010f64c size=168
// signature: undefined dbg_state_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dbg_state_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined1 local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f6f4);
    (*pcVar1)();
  }
  lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0xb0);
  local_3c[0] = 0;
  uVar3 = capable(0x15);
  if ((uVar3 & 1) == 0) {
    param_4 = 0xfffffffffffffff3;
  }
  else {
    iVar2 = kstrtobool(param_3,local_3c);
    if (iVar2 == 0) {
      *(undefined1 *)(lVar4 + 0x2b8) = local_3c[0];
    }
    else {
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// crash_on_err_show @ 0010f6f8 size=68
// signature: undefined crash_on_err_show(void)
// callers: []
//------------------------------------------------------------

long crash_on_err_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f73c);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x1f1));
  return (long)iVar2;
}



//------------------------------------------------------------
// crash_on_err_store @ 0010f740 size=168
// signature: undefined crash_on_err_store(void)
// callers: []
//------------------------------------------------------------

undefined8 crash_on_err_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined1 local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10f7e8);
    (*pcVar1)();
  }
  lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0xb0);
  local_3c[0] = 0;
  uVar3 = capable(0x15);
  if ((uVar3 & 1) == 0) {
    param_4 = 0xfffffffffffffff3;
  }
  else {
    iVar2 = kstrtobool(param_3,local_3c);
    if (iVar2 == 0) {
      *(undefined1 *)(lVar4 + 0x1f1) = local_3c[0];
    }
    else {
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// link_failed_recovery_show @ 0010f7ec size=56
// signature: undefined link_failed_recovery_show(void)
// callers: []
//------------------------------------------------------------

long link_failed_recovery_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0012090d,link_failed_recovery);
  return (long)iVar1;
}



//------------------------------------------------------------
// link_failed_recovery_store @ 0010f828 size=160
// signature: undefined link_failed_recovery_store(void)
// callers: []
//------------------------------------------------------------

undefined8
link_failed_recovery_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  uVar3 = capable(0x15);
  if ((uVar3 & 1) == 0) {
    param_4 = 0xfffffffffffffff3;
  }
  else {
    iVar2 = kstrtobool(param_3,local_2c);
    if (iVar2 == 0) {
      link_failed_recovery = local_2c[0];
      link_startup_life_time = 0xffffffffffffffff;
    }
    else {
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hibern8_count_show @ 0010f8cc size=308
// signature: undefined hibern8_count_show(void)
// callers: []
//------------------------------------------------------------

long hibern8_count_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  long *plVar7;
  
  plVar7 = *(long **)(param_1 + 0x98);
  __pm_runtime_resume(plVar7[8],4);
  ufshcd_hold(plVar7,0);
  uVar1 = readl(*plVar7 + 0x2700);
  uVar2 = readl(*plVar7 + 0x2704);
  uVar3 = readl(*plVar7 + 0x2708);
  uVar4 = readl(*plVar7 + 0x270c);
  uVar5 = readl(*plVar7 + 10000);
  ufshcd_release(plVar7);
  __pm_runtime_idle(plVar7[8],4);
  iVar6 = scnprintf(param_3,0x1000,"%s: %d\n%s: %d\n%s: %d\n%s: %d\n%s: %d\n","hw_h8_enter",uVar1,
                    "sw_h8_enter",uVar2,"sw_after_hw_h8_enter",uVar3,"hw_h8_exit",uVar4,"sw_h8_exit"
                    ,uVar5);
  return (long)iVar6;
}



//------------------------------------------------------------
// ber_th_exceeded_show @ 0010fa04 size=68
// signature: undefined ber_th_exceeded_show(void)
// callers: []
//------------------------------------------------------------

long ber_th_exceeded_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10fa48);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0xc60));
  return (long)iVar2;
}



//------------------------------------------------------------
// irq_affinity_support_show @ 0010fa4c size=68
// signature: undefined irq_affinity_support_show(void)
// callers: []
//------------------------------------------------------------

long irq_affinity_support_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10fa90);
    (*pcVar1)();
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0012090d,
                    *(undefined1 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0xc61));
  return (long)iVar2;
}



//------------------------------------------------------------
// irq_affinity_support_store @ 0010fa94 size=324
// signature: undefined irq_affinity_support_store(void)
// callers: []
//------------------------------------------------------------

undefined8
irq_affinity_support_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  char local_3c [4];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  if (lVar5 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10fbd8);
    (*pcVar1)();
  }
  lVar6 = *(long *)(lVar5 + 0xb0);
  local_3c[0] = '\0';
  uVar3 = capable(0x15);
  if ((uVar3 & 1) == 0) {
    param_4 = 0xfffffffffffffff3;
    goto LAB_0010fb5c;
  }
  iVar2 = kstrtobool(param_3,local_3c);
  if (iVar2 == 0) {
    if ((local_3c[0] != *(char *)(lVar6 + 0xc61)) && (*(long *)(lVar6 + 0x2e8) != 0)) {
      *(char *)(lVar6 + 0xc61) = local_3c[0];
      lVar6 = *(long *)(lVar5 + 0xb0);
      if (local_3c[0] == '\0') {
        irq_modify_status(*(undefined4 *)(lVar5 + 0xc0),0x2000,0);
        iVar2 = __irq_apply_affinity_hint(*(undefined4 *)(lVar5 + 0xc0),lVar6 + 0x2f0,1);
        if (-1 < iVar2) goto LAB_0010fb5c;
        lVar5 = *(long *)(lVar6 + 0x10);
        uVar4 = 0;
      }
      else {
        irq_modify_status(*(undefined4 *)(lVar5 + 0xc0),0,0x2000);
        iVar2 = __irq_apply_affinity_hint(*(undefined4 *)(lVar5 + 0xc0),lVar6 + 0x2e8,1);
        if (-1 < iVar2) goto LAB_0010fb5c;
        lVar5 = *(long *)(lVar6 + 0x10);
        uVar4 = 1;
      }
      _dev_err(*(undefined8 *)(lVar5 + 0x40),"prime=%d, err=%d\n",uVar4,iVar2);
      goto LAB_0010fb5c;
    }
  }
  param_4 = 0xffffffffffffffea;
LAB_0010fb5c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ufs_pm_mode_show @ 0010fbdc size=140
// signature: undefined ufs_pm_mode_show(void)
// callers: []
//------------------------------------------------------------

long ufs_pm_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10fc68);
    (*pcVar1)();
  }
  iVar2 = *(int *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0x19c);
  if (iVar2 == 2) {
    pcVar4 = "DEEPSLEEP\n";
    uVar3 = 0xc;
  }
  else if (iVar2 == 1) {
    pcVar4 = "S2R\n";
    uVar3 = 5;
  }
  else {
    if (iVar2 != 0) {
      iVar2 = -1;
      goto LAB_0010fc54;
    }
    pcVar4 = "NONE\n";
    uVar3 = 6;
  }
  iVar2 = scnprintf(param_3,uVar3,pcVar4);
LAB_0010fc54:
  return (long)iVar2;
}



//------------------------------------------------------------
// ufs_pm_mode_store @ 0010fc6c size=320
// signature: undefined ufs_pm_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_pm_mode_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined4 uVar4;
  long lVar5;
  long lVar6;
  char local_48 [16];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\0';
  local_48[0xb] = '\0';
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  if (lVar5 != 0) {
    if (param_3 == (char *)0x0) {
      param_4 = 0xffffffffffffffea;
      goto LAB_0010fd48;
    }
    lVar6 = *(long *)(lVar5 + 0xb0);
    uVar3 = strnlen(param_3,0xb);
    if (uVar3 == 0xffffffffffffffff) {
      fortify_panic("strnlen");
    }
    else {
      if (uVar3 != 0xb) {
        uVar3 = uVar3 + 1;
      }
      if (uVar3 < 0xd) {
        strscpy(local_48,param_3);
        iVar2 = strncasecmp(local_48,"NONE",4);
        if (iVar2 == 0) {
          *(undefined4 *)(lVar6 + 0x19c) = 0;
        }
        else {
          iVar2 = strncasecmp(local_48,"S2R",3);
          if (iVar2 == 0) {
            uVar4 = 1;
          }
          else {
            iVar2 = strncasecmp(local_48,"DEEPSLEEP",9);
            if (iVar2 != 0) {
              _dev_err(*(undefined8 *)(lVar5 + 0x40),"Invalid entry for ufs_pm_mode\n");
              goto LAB_0010fd48;
            }
            uVar4 = 2;
          }
          *(undefined4 *)(lVar6 + 0x19c) = uVar4;
        }
LAB_0010fd48:
        lVar5 = sp_el0;
        if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return param_4;
      }
    }
    fortify_panic("strscpy");
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10fdac);
  (*pcVar1)();
}



//------------------------------------------------------------
// ufs_qcom_vote_work @ 0010fdb0 size=200
// signature: undefined ufs_qcom_vote_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_vote_work(long param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  iVar1 = **(int **)(param_1 + -0x18);
  if (*(int *)(param_1 + 0x38) != iVar1) {
    iVar3 = 0;
    lVar4 = *(long *)(param_1 + -0x10);
    while (uVar2 = _find_next_bit(param_1 + -0x20,_nr_cpu_ids,(long)iVar3), uVar2 < _nr_cpu_ids) {
      iVar3 = dev_pm_qos_update_request(lVar4,iVar1);
      if (iVar3 < 0) {
        _dev_err(*(undefined8 *)(*(long *)(*(long *)(param_1 + 0x30) + 0x10) + 0x40),
                 "%s: update qos - failed: %d\n","ufs_qcom_vote_work",iVar3);
        return;
      }
      lVar4 = lVar4 + 0x50;
      iVar3 = uVar2 + 1;
    }
    *(int *)(param_1 + 0x38) = iVar1;
    *(undefined1 *)(param_1 + -8) = 1;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_cpufreq_dwork @ 0010fe7c size=632
// signature: undefined ufs_qcom_cpufreq_dwork(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_cpufreq_dwork(long param_1)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  
  uVar4 = *(uint *)(param_1 + -8);
  *(undefined4 *)(param_1 + -8) = 0;
  if (uVar4 < 0x41) {
    if ((0x1f < uVar4) || (*(char *)(param_1 + -4) == '\0')) goto LAB_0011008c;
    if (*(char *)(param_1 + 0xa51) != '\0') {
      lVar10 = *(long *)(param_1 + -0x200);
      if (lVar10 == 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1100f4);
        (*pcVar5)();
      }
      lVar9 = *(long *)(lVar10 + 0xb0);
      sched_set_boost(0xfffffffc);
      *(undefined4 *)(lVar9 + 0x2e0) = 0;
      lVar9 = *(long *)(lVar10 + 0xb0);
      irq_modify_status(*(undefined4 *)(lVar10 + 0xc0),0x2000,0);
      iVar6 = __irq_apply_affinity_hint(*(undefined4 *)(lVar10 + 0xc0),lVar9 + 0x2f0,1);
      if (iVar6 < 0) {
        lVar10 = *(long *)(lVar9 + 0x10);
        uVar8 = 0;
LAB_001100dc:
        _dev_err(*(undefined8 *)(lVar10 + 0x40),"prime=%d, err=%d\n",uVar8,iVar6);
      }
    }
  }
  else {
    if (*(char *)(param_1 + -4) != '\0') goto LAB_0011008c;
    if (*(char *)(param_1 + 0xa51) != '\0') {
      lVar10 = *(long *)(param_1 + -0x200);
      if (lVar10 == 0) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1100f0);
        (*pcVar5)();
      }
      lVar9 = *(long *)(lVar10 + 0xb0);
      if (*(int *)(lVar9 + 0x2e4) == 0) {
        sched_set_boost(4);
        *(undefined4 *)(lVar9 + 0x2e0) = 1;
        lVar9 = *(long *)(lVar10 + 0xb0);
        irq_modify_status(*(undefined4 *)(lVar10 + 0xc0),0,0x2000);
        iVar6 = __irq_apply_affinity_hint(*(undefined4 *)(lVar10 + 0xc0),lVar9 + 0x2e8,1);
        if (iVar6 < 0) {
          lVar10 = *(long *)(lVar9 + 0x10);
          uVar8 = 1;
          goto LAB_001100dc;
        }
      }
    }
  }
  *(undefined1 *)(param_1 + -4) = 1;
  if (0 < *(int *)(param_1 + 0x98)) {
    lVar9 = 0;
    lVar10 = 0;
    do {
      lVar2 = 4;
      if (0x40 < uVar4) {
        lVar2 = 8;
      }
      puVar1 = (uint *)(*(long *)(param_1 + 0x90) + lVar9);
      iVar6 = *(int *)((long)puVar1 + lVar2);
      uVar3 = *puVar1;
      cpus_read_lock();
      if ((*(ulong *)(&__cpu_online_mask + ((ulong)(uVar3 >> 3) & 0x1ffffff8)) >>
           ((ulong)uVar3 & 0x3f) & 1) == 0) {
        cpus_read_unlock();
LAB_00110074:
        if (iVar6 == *(int *)(*(long *)(param_1 + 0x90) + lVar9 + 4)) goto LAB_0010fff8;
      }
      else {
        if (0x1f < uVar3) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1100ec);
          (*pcVar5)();
        }
        iVar7 = freq_qos_update_request
                          (&qos_min_req + *(long *)(&__per_cpu_offset + (ulong)uVar3 * 8),iVar6);
        cpus_read_unlock();
        if (-1 < iVar7) goto LAB_00110074;
        _dev_err(*(undefined8 *)(*(long *)(param_1 + -0x200) + 0x40),
                 "fail set cpufreq-fmin,freq_val=%u,cpu=%u,err=%d\n",iVar6,
                 *(undefined4 *)(*(long *)(param_1 + 0x90) + lVar9),iVar7);
LAB_0010fff8:
        *(undefined1 *)(param_1 + -4) = 0;
      }
      lVar10 = lVar10 + 1;
      lVar9 = lVar9 + 0xc;
    } while (lVar10 < *(int *)(param_1 + 0x98));
  }
LAB_0011008c:
  queue_delayed_work_on(0x20,*(undefined8 *)(*(long *)(param_1 + -0x38) + 0x10),param_1,8);
  return;
}



//------------------------------------------------------------
// ufs_qcom_disable_lane_clks @ 001100f4 size=136
// signature: undefined ufs_qcom_disable_lane_clks(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_exit, ufs_qcom_suspend]
//------------------------------------------------------------

void ufs_qcom_disable_lane_clks(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(char *)(param_1 + 0x90) != '\0') {
    lVar1 = *(long *)(param_1 + 0x88);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x78);
    clk_disable(uVar2);
    clk_unprepare(uVar2);
    lVar1 = *(long *)(param_1 + 0x80);
    if (lVar1 != 0) {
      clk_disable(lVar1);
      clk_unprepare(lVar1);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x70);
    clk_disable(uVar2);
    clk_unprepare(uVar2);
    *(undefined1 *)(param_1 + 0x90) = 0;
  }
  return;
}



//------------------------------------------------------------
// __ufs_qcom_cfg_timers @ 0011017c size=812
// signature: undefined __ufs_qcom_cfg_timers(void)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_clk_scale_notify, ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

undefined8
__ufs_qcom_cfg_timers(long *param_1,uint param_2,int param_3,int param_4,uint param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  char *pcVar7;
  undefined8 uVar8;
  undefined1 *puVar9;
  ulong uVar10;
  ulong uVar11;
  ulong uVar12;
  byte *pbVar13;
  long *plVar14;
  
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1104a8);
    (*pcVar3)();
  }
  pbVar13 = (byte *)param_1[0x16];
  if (((((*pbVar13 & 1) != 0) &&
       (((*(byte *)(param_1 + 0x17e) >> 4 & 1) == 0 || ((*(byte *)((long)param_1 + 0xcc) & 1) != 0))
       )) && ((-1 < *(char *)((long)param_1 + 0x8a) ||
              ((*(byte *)((long)param_1 + 0xcd) >> 3 & 1) != 0)))) && (pbVar13[0xa6] < 4)) {
    return 0;
  }
  if (param_2 == 0) {
    lVar6 = param_1[8];
    pcVar7 = "%s: invalid gear = %d\n";
    param_4 = 0;
LAB_00110414:
    _dev_err(lVar6,pcVar7,"__ufs_qcom_cfg_timers",param_4);
    return 0xffffffea;
  }
  plVar14 = (long *)param_1[0x14e];
  if (plVar14 == param_1 + 0x14e) {
    uVar12 = 0;
  }
  else {
    uVar12 = 0;
    do {
      iVar4 = strcmp((char *)plVar14[3],"core_clk");
      if (iVar4 == 0) {
        if ((param_6 & 1) == 0) {
          uVar12 = clk_get_rate(plVar14[2]);
        }
        else {
          uVar12 = (ulong)*(uint *)(plVar14 + 4);
        }
      }
      plVar14 = (long *)*plVar14;
    } while (plVar14 != param_1 + 0x14e);
  }
  if (uVar12 < 0xf4241) {
    uVar12 = 1000000;
  }
  iVar4 = readl(*param_1 + 0xc0);
  if (iVar4 != (int)(uVar12 / 1000000)) {
    writel(uVar12 / 1000000 & 0xffffffff,*param_1 + 0xc0);
    readl(*param_1 + 0xc0);
  }
  if ((*pbVar13 & 1) != 0) {
    return 0;
  }
  switch(param_3) {
  case 1:
  case 4:
    break;
  case 2:
  case 5:
    if (4 < param_2) {
      lVar6 = param_1[8];
      uVar8 = 4;
      goto LAB_0011045c;
    }
    uVar10 = (ulong)(param_2 - 1);
    uVar11 = 0x20;
    puVar9 = &__ufs_qcom_cfg_timers_pwm_fr_table + uVar10 * 8;
    goto LAB_00110338;
  default:
    lVar6 = param_1[8];
    pcVar7 = "%s: invalid mode = %d\n";
    param_4 = param_3;
    goto LAB_00110414;
  }
  if (param_4 == 2) {
    if (3 < param_2) {
LAB_00110440:
      lVar6 = param_1[8];
      uVar8 = 3;
LAB_0011045c:
      _dev_err(lVar6,"%s: index %d exceeds table size %zu\n","__ufs_qcom_cfg_timers",param_2,uVar8);
      return 0xffffffea;
    }
    puVar9 = __ufs_qcom_cfg_timers_hs_fr_table_rB;
  }
  else {
    if (param_4 != 1) {
      lVar6 = param_1[8];
      pcVar7 = "%s: invalid rate = %d\n";
      goto LAB_00110414;
    }
    if (3 < param_2) goto LAB_00110440;
    puVar9 = __ufs_qcom_cfg_timers_hs_fr_table_rA;
  }
  uVar10 = (ulong)(param_2 - 1);
  puVar9 = puVar9 + uVar10 * 8;
  uVar11 = 0x18;
LAB_00110338:
  if (uVar11 < (uVar10 << 3 | 4)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x1104a4);
    (*pcVar3)();
  }
  uVar1 = *(uint *)(puVar9 + 4);
  uVar2 = 0;
  if (uVar12 != 0) {
    uVar2 = (uint)(1000000000 / uVar12);
  }
  uVar5 = readl(*param_1 + 0xc4);
  uVar1 = uVar1 | (uVar2 & 0x3fff) << 10;
  if (uVar5 != uVar1) {
    writel(uVar1,*param_1 + 0xc4);
    DataSynchronizationBarrier(3,3,0);
  }
  if (((param_5 & 1) != 0) && (pbVar13[0xa6] < 5)) {
    writel((int)(uVar12 / 1000) * 100,*param_1 + 0xd8);
    DataSynchronizationBarrier(3,3,0);
  }
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode @ 001104a8 size=352
// signature: undefined ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode(void)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_clk_scale_notify]
//------------------------------------------------------------

int ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0xa70);
  do {
    if (plVar5 == (long *)(param_1 + 0xa70)) {
      iVar1 = 0;
      iVar2 = -0x16;
LAB_001105d8:
      _dev_err(*(undefined8 *)(param_1 + 0x40),"unipro max_freq=%u entry missing\n",iVar1);
      dump_stack();
      return iVar2;
    }
    if (((plVar5[2] != 0) && ((ulong)plVar5[2] < 0xfffffffffffff001)) &&
       (iVar1 = strcmp((char *)plVar5[3],"core_clk_unipro"), iVar1 == 0)) {
      iVar1 = *(int *)(plVar5 + 4);
      iVar2 = -0x16;
      if (iVar1 < 0xc02a560) {
        if (iVar1 == 100000000) {
          uVar3 = 100;
          uVar4 = 4;
        }
        else {
          if (iVar1 != 150000000) goto LAB_001105d8;
          uVar3 = 0x96;
          uVar4 = 6;
        }
      }
      else if (iVar1 == 0xc02a560) {
        uVar3 = 0xca;
        uVar4 = 8;
      }
      else if (iVar1 == 300000000) {
        uVar3 = 300;
        uVar4 = 0xc;
      }
      else {
        if (iVar1 != 403000000) goto LAB_001105d8;
        uVar3 = 0x193;
        uVar4 = 0x10;
      }
      iVar2 = ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div(param_1,uVar3,uVar4,1);
      if (iVar2 == 0) {
        return 0;
      }
      goto LAB_001105d8;
    }
    plVar5 = (long *)*plVar5;
  } while( true );
}



//------------------------------------------------------------
// ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div @ 00110608 size=352
// signature: undefined ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div(void)
// callers: [ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode, ufs_qcom_clk_scale_notify]
//------------------------------------------------------------

void ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div
               (long param_1,uint param_2,uint param_3,ulong param_4)

{
  byte bVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  uint local_60;
  uint uStack_5c;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x110768);
    (*pcVar2)();
  }
  lVar5 = *(long *)(param_1 + 0xb0);
  local_60 = 0;
  uStack_5c = 0;
  bVar1 = *(byte *)(lVar5 + 0xa6);
  uVar4 = 0xfff;
  if (bVar1 < 4) {
    uVar4 = 0xff;
  }
  if (uVar4 < param_2) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = ufshcd_dme_get_attr(param_1,0xd0020000,&uStack_5c,0);
    if ((int)uVar3 == 0) {
      uStack_5c = uStack_5c & (uVar4 << ((ulong)(3 < bVar1) << 4) ^ 0xffffffff) |
                  param_2 << ((ulong)(3 < bVar1) << 4);
      if (((param_4 & 1) == 0) || (*(char *)(lVar5 + 0x14c) != '\0')) {
        uStack_5c = uStack_5c & 0xfffffeff;
      }
      else {
        uStack_5c = uStack_5c | 0x100;
      }
      uVar3 = ufshcd_dme_set_attr(param_1,0xd0020000,0,uStack_5c,0);
      if ((int)uVar3 == 0) {
        if (*(byte *)(lVar5 + 0xa6) < 4) {
          uVar3 = 0;
        }
        else {
          uVar3 = ufshcd_dme_get_attr(param_1,0x90070000,&local_60,0);
          if ((int)uVar3 == 0) {
            local_60 = local_60 & 0xffffffc0 | param_3;
            uVar3 = ufshcd_dme_set_attr(param_1,0x90070000,0,local_60,0);
          }
        }
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_enable_lane_clks @ 00110768 size=460
// signature: undefined ufs_qcom_enable_lane_clks(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_hce_enable_notify, ufs_qcom_resume]
//------------------------------------------------------------

int ufs_qcom_enable_lane_clks(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x90) != '\0') {
    return 0;
  }
  uVar3 = *(undefined8 *)(param_1 + 0x70);
  uVar2 = *(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40);
  iVar1 = clk_prepare(uVar3);
  if (iVar1 != 0) {
LAB_00110858:
    _dev_err(uVar2,"%s: %s enable failed %d\n","ufs_qcom_host_clk_enable","rx_lane0_sync_clk",iVar1)
    ;
    return iVar1;
  }
  iVar1 = clk_enable(uVar3);
  if (iVar1 != 0) {
    clk_unprepare(uVar3);
    goto LAB_00110858;
  }
  uVar3 = *(undefined8 *)(param_1 + 0x78);
  iVar1 = clk_prepare(uVar3);
  if (iVar1 == 0) {
    iVar1 = clk_enable(uVar3);
    if (iVar1 == 0) {
      if (*(uint *)(*(long *)(param_1 + 0x10) + 0xa84) < 2) {
LAB_00110834:
        *(undefined1 *)(param_1 + 0x90) = 1;
        return 0;
      }
      uVar3 = *(undefined8 *)(param_1 + 0x80);
      iVar1 = clk_prepare(uVar3);
      if (iVar1 == 0) {
        iVar1 = clk_enable(uVar3);
        if (iVar1 != 0) {
          clk_unprepare(uVar3);
          goto LAB_001108d0;
        }
        if ((*(long *)(param_1 + 0x88) == 0) ||
           (iVar1 = ufs_qcom_host_clk_enable(uVar2,"tx_lane1_sync_clk"), iVar1 == 0))
        goto LAB_00110834;
        uVar2 = *(undefined8 *)(param_1 + 0x80);
        clk_disable(uVar2);
        clk_unprepare(uVar2);
      }
      else {
LAB_001108d0:
        _dev_err(uVar2,"%s: %s enable failed %d\n","ufs_qcom_host_clk_enable","rx_lane1_sync_clk",
                 iVar1);
      }
      uVar2 = *(undefined8 *)(param_1 + 0x78);
      clk_disable(uVar2);
      clk_unprepare(uVar2);
      goto LAB_00110908;
    }
    clk_unprepare(uVar3);
  }
  _dev_err(uVar2,"%s: %s enable failed %d\n","ufs_qcom_host_clk_enable","tx_lane0_sync_clk",iVar1);
LAB_00110908:
  uVar2 = *(undefined8 *)(param_1 + 0x70);
  clk_disable(uVar2);
  clk_unprepare(uVar2);
  return iVar1;
}



//------------------------------------------------------------
// ufs_qcom_unvote_qos_all @ 00110934 size=300
// signature: undefined ufs_qcom_unvote_qos_all(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_suspend]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ufs_qcom_unvote_qos_all(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x110a60);
    (*pcVar1)();
  }
  plVar7 = *(long **)(*(long *)(param_1 + 0xb0) + 0x1d8);
  if ((plVar7 == (long *)0x0) || ((int)plVar7[1] == 0)) {
    iVar3 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = 0;
    lVar5 = *plVar7;
    do {
      flush_work(lVar5 + 0x20);
      if (*(char *)(lVar5 + 0x18) != '\0') {
        if (*(int *)(lVar5 + 0x58) == 0x7fffffff) {
          iVar3 = 0;
        }
        else {
          iVar3 = 0;
          lVar6 = *(long *)(lVar5 + 0x10);
          while( true ) {
            uVar2 = _find_next_bit(lVar5,_nr_cpu_ids,(long)iVar3);
            if (_nr_cpu_ids <= uVar2) break;
            iVar3 = dev_pm_qos_update_request(lVar6,0x7fffffff);
            if (iVar3 < 0) {
              _dev_err(*(undefined8 *)(param_1 + 0x40),"Failed (%d) removing qos grp(%d)\n",iVar3,
                       uVar4);
              goto LAB_00110994;
            }
            lVar6 = lVar6 + 0x50;
            iVar3 = uVar2 + 1;
          }
          iVar3 = 0;
          *(undefined1 *)(lVar5 + 0x18) = 0;
          *(undefined4 *)(lVar5 + 0x58) = 0x7fffffff;
        }
      }
LAB_00110994:
      uVar4 = uVar4 + 1;
      lVar5 = lVar5 + 0x60;
    } while (uVar4 < *(uint *)(plVar7 + 1));
  }
  return iVar3;
}



//------------------------------------------------------------
// ufs_qcom_host_clk_enable @ 00110a60 size=136
// signature: undefined ufs_qcom_host_clk_enable(void)
// callers: [ufs_qcom_enable_lane_clks]
//------------------------------------------------------------

int ufs_qcom_host_clk_enable(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = clk_prepare(param_3);
  if (iVar1 == 0) {
    iVar1 = clk_enable(param_3);
    if (iVar1 == 0) {
      return 0;
    }
    clk_unprepare(param_3);
  }
  _dev_err(param_1,"%s: %s enable failed %d\n","ufs_qcom_host_clk_enable",param_2,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// ufs_qcom_enable_hw_clk_gating @ 00110ae8 size=444
// signature: undefined ufs_qcom_enable_hw_clk_gating(void)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

void ufs_qcom_enable_hw_clk_gating(long *param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined8 uVar4;
  byte *pbVar5;
  long *plVar6;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x110ca4);
    (*pcVar2)();
  }
  pbVar5 = (byte *)param_1[0x16];
  uVar3 = readl(*param_1 + 0xe0);
  writel(uVar3 | 0xff,*param_1 + 0xe0);
  if (4 < pbVar5[0xa6]) {
    plVar6 = *(long **)(pbVar5 + 0x10);
    uVar3 = readl(*plVar6 + 0xfc);
    writel(uVar3 | 0x1800,*plVar6 + 0xfc);
  }
  readl(*param_1 + 0xe0);
  if ((*pbVar5 >> 2 & 1) != 0) {
    local_3c = 0;
    uVar4 = ufshcd_dme_get_attr(param_1,0xa00b0000,&local_3c,0);
    if ((int)uVar4 != 0) goto LAB_00110c54;
    local_3c = local_3c | 0x3ff;
    uVar4 = ufshcd_dme_set_attr(param_1,0xa00b0000,0,local_3c,0);
    if ((int)uVar4 != 0) goto LAB_00110c54;
    local_3c = 0;
    uVar4 = ufshcd_dme_get_attr(param_1,0x90040000,&local_3c,0);
    if ((int)uVar4 != 0) goto LAB_00110c54;
    local_3c = local_3c | 0x1ff;
    uVar4 = ufshcd_dme_set_attr(param_1,0x90040000,0,local_3c,0);
    if ((int)uVar4 != 0) goto LAB_00110c54;
    if (((pbVar5[0xa6] != 4) || (*(short *)(pbVar5 + 0xa4) != 0)) ||
       (*(short *)(pbVar5 + 0xa2) != 0)) {
      local_3c = 0;
      uVar4 = ufshcd_dme_get_attr(param_1,0xd0020000,&local_3c,0);
      if ((int)uVar4 == 0) {
        local_3c = local_3c | 0x200;
        uVar4 = ufshcd_dme_set_attr(param_1,0xd0020000,0,local_3c,0);
      }
      goto LAB_00110c54;
    }
    _dev_err(param_1[8],"%s: skipping DME_HW_CGC_EN set\n","ufs_qcom_enable_hw_clk_gating");
  }
  uVar4 = 0;
LAB_00110c54:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_bypass_cfgready_signal @ 00110ca4 size=212
// signature: undefined ufs_qcom_bypass_cfgready_signal(void)
// callers: [ufs_qcom_link_startup_notify]
//------------------------------------------------------------

void ufs_qcom_bypass_cfgready_signal(undefined8 param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  iVar3 = ufshcd_dme_get_attr(param_1,0x90000000,(long)&local_30 + 4,0);
  if (((iVar3 == 0) &&
      (iVar3 = ufshcd_dme_set_attr(param_1,0x90000000,0,local_30._4_4_ | 0x800000,0), iVar3 == 0))
     && (iVar3 = ufshcd_dme_get_attr(param_1,0x90050000,&local_30,0), iVar3 == 0)) {
    uVar1 = (uint)local_30 & 0xfbffff1f;
    local_30 = local_30 & 0xfffffffffbffff1f | 0x80;
    ufshcd_dme_set_attr(param_1,0x90050000,0,uVar1 | 0x80,0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_save_regs @ 00110d78 size=360
// signature: undefined ufs_qcom_save_regs(void)
// callers: [ufs_qcom_event_notify]
//------------------------------------------------------------

void ufs_qcom_save_regs(long param_1,long param_2,ulong param_3,char *param_4)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  long *plVar7;
  ulong uVar8;
  undefined8 *puVar9;
  
  if ((((uint)param_3 | (uint)param_2) & 3) == 0) {
    plVar1 = (long *)(param_1 + 0xc50);
    for (plVar7 = (long *)*plVar1; plVar7 != plVar1; plVar7 = (long *)*plVar7) {
      if (((char *)plVar7[2] != (char *)0x0) &&
         (iVar4 = strcmp((char *)plVar7[2],param_4), iVar4 == 0)) goto LAB_00110e68;
    }
    lVar3 = sp_el0;
    uVar2 = *(uint *)(lVar3 + 0x44) & 0x80000;
    *(uint *)(lVar3 + 0x44) = *(uint *)(lVar3 + 0x44) | 0x80000;
    plVar7 = (long *)devm_kmalloc(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),0x28,0xb20);
    if (plVar7 != (long *)0x0) {
      lVar6 = devm_kmalloc(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),param_3,0xb20);
      plVar7[3] = lVar6;
      if (lVar6 != 0) {
        *(uint *)(lVar3 + 0x44) = *(uint *)(lVar3 + 0x44) & 0xfff7ffff | uVar2;
        puVar9 = *(undefined8 **)(param_1 + 0xc58);
        plVar7[2] = (long)param_4;
        plVar7[4] = param_3;
        uVar8 = __list_add_valid(plVar7,puVar9,plVar1);
        if ((uVar8 & 1) != 0) {
          *(long **)(param_1 + 0xc58) = plVar7;
          *plVar7 = (long)plVar1;
          plVar7[1] = (long)puVar9;
          *puVar9 = plVar7;
        }
LAB_00110e68:
        if (param_3 == 0) {
          return;
        }
        uVar8 = 0;
        do {
          if (((param_2 != 0) || (uVar8 < 0x38)) || (0x48 < uVar8)) {
            uVar5 = readl(**(long **)(param_1 + 0x10) + param_2 + uVar8);
            *(undefined4 *)(plVar7[3] + uVar8) = uVar5;
          }
          uVar8 = uVar8 + 4;
        } while (uVar8 < param_3);
        return;
      }
    }
    *(uint *)(lVar3 + 0x44) = *(uint *)(lVar3 + 0x44) & 0xfff7ffff | uVar2;
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_write_msi_msg @ 00110ee4 size=36
// signature: undefined ufs_qcom_write_msi_msg(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_write_msi_msg(long param_1)

{
  ufshcd_mcq_config_esi(*(undefined8 *)(*(long *)(param_1 + 8) + 0x98));
  return;
}



//------------------------------------------------------------
// ufs_qcom_mcq_esi_handler @ 00110f0c size=224
// signature: undefined ufs_qcom_mcq_esi_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_mcq_esi_handler(undefined4 param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  
  lVar6 = *(long *)(*(long *)(param_2 + 8) + 0x98);
  if (lVar6 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x110fc8);
    (*pcVar5)();
  }
  lVar9 = *(long *)(lVar6 + 0xb0);
  uVar7 = (ulong)*(ushort *)(param_2 + 0x48);
  lVar8 = *(long *)(lVar6 + 0x1460);
  if ((*(long *)(lVar9 + 0x2b0) != 0) && (*(char *)(lVar9 + 0x2b8) != '\0')) {
    lVar4 = tpidr_el1;
    ipc_log_string(*(long *)(lVar9 + 0x2b0),",%d,!,%d,%u\n",*(undefined4 *)(&cpu_number + lVar4),
                   param_1,uVar7);
  }
  ufshcd_mcq_write_cqis(lVar6,1,uVar7);
  piVar1 = (int *)(lVar9 + 0xc64);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  ufshcd_mcq_poll_cqe_lock(lVar6,lVar8 + uVar7 * 0x90);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar3) {
      *piVar1 = *piVar1 + -1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return 1;
}



//------------------------------------------------------------
// ufs_qcom_set_esi_affinity_hint @ 00110ffc size=452
// signature: undefined ufs_qcom_set_esi_affinity_hint(void)
// callers: [ufs_qcom_config_esi, ufs_qcom_cpu_online]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_set_esi_affinity_hint(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ulong local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1111c0);
    (*pcVar1)();
  }
  lVar5 = *(long *)(param_1 + 0xb0);
  local_70 = 0;
  if (((*(long *)(lVar5 + 0x310) != 0) || (*(long *)(lVar5 + 0x308) != 0)) ||
     (*(long *)(lVar5 + 0x300) != 0)) {
    mutex_lock(*(long *)(*(long *)(param_1 + 0x40) + 0x288) + 0x10);
    puVar3 = (undefined4 *)msi_first_desc(*(undefined8 *)(param_1 + 0x40),0);
    if (puVar3 != (undefined4 *)0x0) {
      uVar6 = 0;
      uVar7 = 0;
      do {
        uVar8 = uVar7;
        if (*(ulong *)(lVar5 + 0x310) == 0) {
          if (((*(ulong *)(lVar5 + 0x308) == 0) ||
              (uVar4 = __bitmap_subset(&cpu_bit_bitmap +
                                       (ulong)(uVar6 >> 6) * -8 + (ulong)((uVar6 & 0x3f) + 1) * 8,
                                       (ulong *)(lVar5 + 0x300),_nr_cpu_ids), (uVar4 & 1) == 0)) ||
             (uVar8 = uVar7 + 1, 2 < uVar7)) {
            local_70 = *(ulong *)(lVar5 + 0x300);
            goto LAB_0011111c;
          }
          local_70 = *(ulong *)(lVar5 + 0x308);
          uVar7 = uVar8;
        }
        else {
          local_70 = *(ulong *)(lVar5 + 0x308) | *(ulong *)(lVar5 + 0x310);
LAB_0011111c:
          uVar7 = uVar8;
        }
        irq_modify_status(*puVar3,0,0x2000);
        iVar2 = __irq_apply_affinity_hint(*puVar3,&local_70,1);
        if (iVar2 < 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x40),
                   "%s: Failed to set affinity hint to cpu for ESI %d, err = %d\n",
                   "ufs_qcom_set_esi_affinity_hint",*puVar3,iVar2);
        }
        uVar6 = uVar6 + 1;
        puVar3 = (undefined4 *)msi_next_desc(*(undefined8 *)(param_1 + 0x40),0);
      } while (puVar3 != (undefined4 *)0x0);
    }
    *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x40) + 0x288) + 0x50) = 0xffff;
    mutex_unlock(*(long *)(*(long *)(param_1 + 0x40) + 0x288) + 0x10);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_cpu_online @ 001111c4 size=44
// signature: undefined ufs_qcom_cpu_online(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_cpu_online(void)

{
  ufs_qcom_set_esi_affinity_hint(*(undefined8 *)(ufs_qcom_hosts + 0x10));
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_hook_send_command @ 001111f4 size=824
// signature: undefined ufs_qcom_hook_send_command(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_qcom_hook_send_command(undefined8 param_1,long *param_2,long param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  int iVar14;
  ulong *puVar15;
  uint uVar16;
  long lVar17;
  long lVar18;
  long *plVar19;
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x800,0x1115b0);
    (*pcVar7)();
  }
  lVar18 = param_2[0x16];
  if ((*(char *)(lVar18 + 0x14c) == '\0') && (*(char *)(lVar18 + 0xc80) != '\0')) {
    uVar11 = _raw_spin_lock_irqsave(*(undefined8 *)(param_2[7] + 0x38));
    lVar12 = *(long *)(lVar18 + 0xc88);
    *(long *)(lVar18 + 0xc88) = lVar12 + 1;
    if (lVar12 == 0) {
      writel(0,*param_2 + 0x18);
    }
    _raw_spin_unlock_irqrestore(*(undefined8 *)(param_2[7] + 0x38),uVar11);
  }
  if (((param_3 != 0) && (lVar12 = *(long *)(param_3 + 0x40), lVar12 != 0)) &&
     (*(char *)(lVar12 + 0xd4) != '\0')) {
    if (lVar12 == 0x140) {
      uVar16 = 0;
    }
    else {
      uVar16 = *(uint *)(lVar12 + -0x114) >> 9;
    }
    lVar17 = param_2[0x16];
    if (*(long *)(lVar17 + 0x1d8) != 0) {
      if (((param_2[0xd] + (ulong)*(uint *)(param_3 + 0x50) * 0x98 != 0) &&
          (lVar13 = *(long *)(param_2[0xd] + (ulong)*(uint *)(param_3 + 0x50) * 0x98 + 0x40),
          lVar13 != 0)) &&
         ((lVar13 = lVar13 + -0x140, lVar13 != 0 && (uVar8 = blk_mq_rq_cpu(lVar13), -1 < (int)uVar8)
          ))) {
        plVar19 = *(long **)(lVar17 + 0x1d8);
        lVar13 = *plVar19;
        uVar9 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
        if ((uVar8 <= uVar9) && ((int)plVar19[1] != 0)) {
          iVar14 = 0;
          puVar15 = (ulong *)(lVar13 + ((ulong)(uVar8 >> 3) & 0x1ffffff8));
          do {
            if ((*puVar15 & 1L << ((ulong)uVar8 & 0x3f)) != 0) {
              lVar13 = *plVar19;
              if (lVar13 + (long)iVar14 * 0x60 != 0) {
                if (((*(char *)(lVar13 + (long)iVar14 * 0x60 + 0x5c) != '\0') &&
                    (*(char *)(lVar17 + 0x298) == '\0')) && (*(int *)(lVar17 + 500) != 0)) {
                  piVar1 = (int *)(lVar17 + 0x208);
                  Hint_Prefetch(piVar1,2,0,1);
                  do {
                    cVar5 = '\x01';
                    bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
                    if (bVar6) {
                      *piVar1 = *piVar1 + 1;
                      cVar5 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar5 != '\0');
                }
                if (*(char *)(lVar13 + (long)iVar14 * 0x60 + 0x18) == '\0') {
                  queue_work_on(0x20,*(undefined8 *)(*(long *)(lVar17 + 0x1d8) + 0x10),
                                lVar13 + (long)iVar14 * 0x60 + 0x20);
                }
              }
              break;
            }
            iVar14 = iVar14 + 1;
            puVar15 = puVar15 + 0xc;
          } while ((int)plVar19[1] != iVar14);
        }
      }
    }
    if (*(char *)((long)param_2 + 0x13ac) == '\0') {
      lVar12 = *(long *)(lVar18 + 0x2b0);
      if ((lVar12 != 0) && (*(char *)(lVar18 + 0x2b8) != '\0')) {
        lVar17 = tpidr_el1;
        uVar2 = *(undefined4 *)(param_3 + 0x50);
        uVar3 = *(undefined4 *)(&cpu_number + lVar17);
        uVar4 = *(undefined1 *)(*(long *)(param_3 + 0x40) + 0xd4);
        uVar10 = readl(*param_2 + 0x58);
        ipc_log_string(lVar12,",%d,<,%x,%d,%x,%d\n",uVar3,uVar4,uVar2,uVar10,uVar16);
      }
      if (*(char *)(lVar18 + 0x2b8) != '\0') {
        readl(*param_2 + 0x58);
      }
    }
    else if (lVar12 != 0x140) {
      if ((*(long *)(lVar18 + 0x2b0) != 0) && (*(char *)(lVar18 + 0x2b8) != '\0')) {
        lVar17 = tpidr_el1;
        ipc_log_string(*(long *)(lVar18 + 0x2b0),",%d,<,%x,%d,%d,%d\n",
                       *(undefined4 *)(&cpu_number + lVar17),
                       *(undefined1 *)(*(long *)(param_3 + 0x40) + 0xd4),
                       *(undefined4 *)(param_3 + 0x50),
                       *(undefined4 *)
                        (param_2[0x28c] +
                         (ulong)*(ushort *)(*(long *)(lVar12 + -0x130) + 0x194) * 0x90 + 0x44),
                       uVar16);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_hook_compl_command @ 00111680 size=548
// signature: undefined ufs_qcom_hook_compl_command(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_hook_compl_command(undefined8 param_1,long *param_2,long param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  long lVar4;
  code *pcVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x111954);
    (*pcVar5)();
  }
  lVar10 = param_2[0x16];
  if ((*(char *)(lVar10 + 0x14c) == '\0') && (*(char *)(lVar10 + 0xc80) != '\0')) {
    uVar7 = _raw_spin_lock_irqsave(*(undefined8 *)(param_2[7] + 0x38));
    lVar11 = *(long *)(lVar10 + 0xc88) + -1;
    *(long *)(lVar10 + 0xc88) = lVar11;
    if (lVar11 == 0) {
      writel(*(undefined4 *)((long)param_2 + 100),*param_2 + 0x18);
    }
    _raw_spin_unlock_irqrestore(*(undefined8 *)(param_2[7] + 0x38),uVar7);
  }
  if ((param_3 != 0) && (lVar11 = *(long *)(param_3 + 0x40), lVar11 != 0)) {
    if (lVar11 == 0x140) {
      if (*(char *)((long)param_2 + 0x13ac) != '\0') {
        return;
      }
      uVar8 = 0;
    }
    else {
      uVar8 = *(uint *)(lVar11 + -0x114) >> 9;
      if (*(char *)((long)param_2 + 0x13ac) != '\0') {
        if (*(long *)(lVar10 + 0x2b0) == 0) {
          return;
        }
        if (*(char *)(lVar10 + 0x2b8) == '\0') {
          return;
        }
        lVar9 = tpidr_el1;
        ipc_log_string(*(long *)(lVar10 + 0x2b0),",%d,>,%x,%d,%d,%d\n",
                       *(undefined4 *)(&cpu_number + lVar9),*(undefined1 *)(lVar11 + 0xd4),
                       *(undefined4 *)(param_3 + 0x50),
                       *(undefined4 *)
                        (param_2[0x28c] +
                         (ulong)*(ushort *)(*(long *)(lVar11 + -0x130) + 0x194) * 0x90 + 0x44),uVar8
                      );
        return;
      }
    }
    lVar9 = *(long *)(lVar10 + 0x2b0);
    if ((lVar9 != 0) && (*(char *)(lVar10 + 0x2b8) != '\0')) {
      lVar4 = tpidr_el1;
      uVar3 = *(undefined1 *)(lVar11 + 0xd4);
      uVar1 = *(undefined4 *)(param_3 + 0x50);
      uVar2 = *(undefined4 *)(&cpu_number + lVar4);
      uVar6 = readl(*param_2 + 0x58);
      ipc_log_string(lVar9,",%d,>,%x,%d,%x,%d\n",uVar2,uVar3,uVar1,uVar6,uVar8);
    }
    if (*(char *)(lVar10 + 0x2b8) != '\0') {
      readl(*param_2 + 0x58);
    }
    if (((*(char *)(lVar10 + 0xc61) != '\0') && (lVar11 != 0x140)) &&
       (*(int *)(lVar10 + 0x2e0) != 0)) {
      *(uint *)(lVar11 + -0x128) = *(uint *)(lVar11 + -0x128) | 0x800000;
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_hook_send_uic_command @ 00111a08 size=272
// signature: undefined ufs_qcom_hook_send_uic_command(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_hook_send_uic_command
               (undefined8 param_1,long *param_2,undefined4 *param_3,int param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined8 uVar7;
  long lVar8;
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x111b18);
    (*pcVar1)();
  }
  lVar8 = param_2[0x16];
  if (param_4 == 0) {
    uVar3 = param_3[2];
    uVar4 = param_3[3];
    uVar5 = *param_3;
    uVar2 = param_3[1];
    uVar7 = 0x28;
  }
  else {
    uVar2 = readl(*param_2 + 0x94);
    uVar3 = readl(*param_2 + 0x98);
    uVar4 = readl(*param_2 + 0x9c);
    uVar5 = readl(*param_2 + 0x90);
    uVar7 = 0x29;
  }
  lVar6 = *(long *)(lVar8 + 0x2b0);
  if ((lVar6 != 0) && (*(char *)(lVar8 + 0x2b8) != '\0')) {
    lVar8 = tpidr_el1;
    ipc_log_string(lVar6,",%d,%c,%x,%x,%x,%x\n",*(undefined4 *)(&cpu_number + lVar8),uVar7,uVar5,
                   uVar2,uVar3,uVar4);
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_hook_send_tm_command @ 00111cbc size=4
// signature: undefined ufs_qcom_hook_send_tm_command(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_hook_send_tm_command(void)

{
  return;
}



//------------------------------------------------------------
// ufs_qcom_hook_check_int_errors @ 00111cc4 size=156
// signature: undefined ufs_qcom_hook_check_int_errors(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_hook_check_int_errors(undefined8 param_1,long param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x111d60);
    (*pcVar2)();
  }
  if ((param_3 & 1) != 0) {
    lVar3 = *(long *)(*(long *)(param_2 + 0xb0) + 0x2b0);
    if ((lVar3 != 0) && (*(char *)(*(long *)(param_2 + 0xb0) + 0x2b8) != '\0')) {
      lVar1 = tpidr_el1;
      ipc_log_string(lVar3,",%d,_,%x,%x\n",*(undefined4 *)(&cpu_number + lVar1),
                     *(undefined4 *)(param_2 + 0x2b8),*(undefined4 *)(param_2 + 700));
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_update_sdev @ 00111e0c size=20
// signature: undefined ufs_qcom_update_sdev(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_update_sdev(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x15c) = *(ulong *)(param_2 + 0x15c) | 0x80000000000;
  return;
}



//------------------------------------------------------------
// ufs_qcom_suspend_prepare @ 00111e24 size=200
// signature: undefined ufs_qcom_suspend_prepare(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ufs_qcom_suspend_prepare(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1,"UFS is not boot dev.\n");
    return 0;
  }
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x111eec);
    (*pcVar1)();
  }
  lVar4 = *(long *)(lVar3 + 0xb0);
  *(undefined4 *)(lVar4 + 0x194) = *(undefined4 *)(lVar3 + 0x5c);
  if (*(int *)(lVar4 + 0x19c) == 2) {
    if (*(char *)(lVar4 + 0x198) == '\0') goto LAB_00111e94;
  }
  else if (((*(int *)(lVar4 + 0x19c) != 0) || (*(char *)(lVar4 + 0x198) == '\0')) ||
          (_pm_suspend_target_state != 3)) goto LAB_00111e94;
  *(undefined4 *)(lVar3 + 0x5c) = 5;
LAB_00111e94:
  if (*(int *)(lVar3 + 0x5c) != *(int *)(lVar4 + 0x194)) {
    _dev_info(param_1,"spm level is changed from %d to %d\n");
  }
  uVar2 = ufshcd_suspend_prepare(param_1);
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_resume_complete @ 00111ef0 size=92
// signature: undefined ufs_qcom_resume_complete(void)
// callers: []
//------------------------------------------------------------

void ufs_qcom_resume_complete(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1,"UFS is not boot dev.\n");
  }
  else {
    lVar2 = *(long *)(param_1 + 0x98);
    if (lVar2 == 0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x111f4c);
      (*pcVar1)();
    }
    lVar3 = *(long *)(lVar2 + 0xb0);
    if (*(char *)(lVar3 + 0x198) != '\0') {
      *(undefined4 *)(lVar2 + 0x5c) = *(undefined4 *)(lVar3 + 0x194);
    }
    *(undefined4 *)(lVar3 + 0x19c) = 0;
    ufshcd_resume_complete();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_system_suspend @ 00111f50 size=104
// signature: undefined ufs_qcom_system_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_system_suspend(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = of_find_property(*(undefined8 *)(param_1 + 0x2e8),"non-removable",0);
  if ((lVar1 == 0) || (is_bootdevice_ufs != '\0')) {
    uVar2 = ufshcd_system_suspend(param_1);
  }
  else {
    _dev_info(param_1,"UFS is not boot dev.\n");
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_system_resume @ 00111fbc size=60
// signature: undefined ufs_qcom_system_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_system_resume(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1,"UFS is not boot dev.\n");
    uVar1 = 0;
  }
  else {
    uVar1 = ufshcd_system_resume();
  }
  return uVar1;
}



//------------------------------------------------------------
// ufs_qcom_system_freeze @ 00111ffc size=80
// signature: undefined ufs_qcom_system_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_system_freeze(long param_1)

{
  undefined8 uVar1;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1,"UFS is not boot dev.\n");
    uVar1 = 0;
  }
  else {
    *(uint *)(*(long *)(param_1 + 0x98) + 0xbf0) =
         *(uint *)(*(long *)(param_1 + 0x98) + 0xbf0) & 0xffffedf0;
    uVar1 = ufshcd_system_freeze();
  }
  return uVar1;
}



//------------------------------------------------------------
// ufs_qcom_system_thaw @ 00112050 size=60
// signature: undefined ufs_qcom_system_thaw(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_system_thaw(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1,"UFS is not boot dev.\n");
    uVar1 = 0;
  }
  else {
    uVar1 = ufshcd_system_thaw();
  }
  return uVar1;
}



//------------------------------------------------------------
// ufs_qcom_system_restore @ 00112090 size=80
// signature: undefined ufs_qcom_system_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_system_restore(long param_1)

{
  undefined8 uVar1;
  
  if (is_bootdevice_ufs == '\0') {
    _dev_info(param_1,"UFS is not boot dev.\n");
    uVar1 = 0;
  }
  else {
    *(uint *)(*(long *)(param_1 + 0x98) + 0xbf0) =
         *(uint *)(*(long *)(param_1 + 0x98) + 0xbf0) | 0x120f;
    uVar1 = ufshcd_system_restore();
  }
  return uVar1;
}



//------------------------------------------------------------
// ufs_qcom_ice_init @ 00112190 size=412
// signature: undefined ufs_qcom_ice_init(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

ulong ufs_qcom_ice_init(long param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  char *pcVar4;
  ulong uVar5;
  long lVar6;
  undefined8 *puVar7;
  
  puVar7 = *(undefined8 **)(param_1 + 0x10);
  lVar6 = puVar7[8];
  uVar1 = readl(*puVar7);
  if ((uVar1 >> 0x1c & 1) == 0) {
    return 0;
  }
  lVar2 = platform_get_resource_byname(lVar6 + -0x10,0x200,"ufs_ice");
  if (lVar2 == 0) {
    pcVar4 = "ICE registers not found\n";
LAB_00112258:
    lVar2 = lVar6;
  }
  else {
    uVar3 = qcom_scm_ice_available();
    if ((uVar3 & 1) == 0) {
      pcVar4 = "ICE SCM interface not found\n";
      goto LAB_00112258;
    }
    uVar3 = devm_ioremap_resource(lVar6,lVar2);
    *(ulong *)(param_1 + 0xa8) = uVar3;
    if (0xfffffffffffff000 < uVar3) {
      return uVar3;
    }
    lVar2 = platform_get_resource_byname(lVar6 + -0x10,0x200,"ufs_ice_hwkm");
    if (lVar2 == 0) {
      pcVar4 = "ICE HWKM registers not found\n";
      goto LAB_00112258;
    }
    uVar3 = devm_ioremap_resource(lVar6,lVar2);
    *(ulong *)(param_1 + 0xb0) = uVar3;
    if (0xfffffffffffff000 < uVar3) {
      _dev_err(lVar6,"Failed to map ICE HWKM registers; err=%d\n",uVar3 & 0xffffffff);
      return uVar3 & 0xffffffff;
    }
    lVar2 = *(long *)(*(long *)(param_1 + 0x10) + 0x40);
    uVar3 = readl(*(long *)(param_1 + 0xa8) + 8);
    uVar5 = uVar3 >> 0x18 & 0xff;
    if ((uint)uVar5 < 3) {
      _dev_warn(lVar2,"Unsupported ICE version: v%d.%d.%d\n");
      goto LAB_00112260;
    }
    _dev_info(lVar2,"Found QC Inline Crypto Engine (ICE) v%d.%d.%d\n",uVar5,
              (uint)uVar3 >> 0x10 & 0xff,(uint)uVar3 & 0xffff);
    uVar3 = readl(*(long *)(param_1 + 0xa8) + 0x10);
    if ((uVar3 & 7) == 0) {
      return 0;
    }
    pcVar4 = "Fuses are blown; ICE is unusable!\n";
  }
  _dev_warn(lVar2,pcVar4);
LAB_00112260:
  _dev_warn(lVar6,"Disabling inline encryption support\n");
  *(uint *)(puVar7 + 0x17e) = *(uint *)(puVar7 + 0x17e) & 0xfffffeff;
  return 0;
}



//------------------------------------------------------------
// readl @ 0011232c size=140
// signature: undefined readl(void)
// callers: [ufs_qcom_ice_resume, ufs_qcom_ice_enable, ufs_qcom_ice_init]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x112384,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_ice_enable @ 001123bc size=236
// signature: undefined ufs_qcom_ice_enable(void)
// callers: [ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

undefined8 ufs_qcom_ice_enable(long param_1)

{
  uint uVar1;
  ulong uVar2;
  int iVar3;
  
  if ((*(byte *)(*(long *)(param_1 + 0x10) + 0xbf1) & 1) != 0) {
    uVar1 = readl(*(long *)(param_1 + 0xa8) + 0x1000);
    writel(uVar1 | 0xf000,*(long *)(param_1 + 0xa8) + 0x1000);
    uVar1 = readl(*(long *)(param_1 + 0xa8) + 0x1000);
    __const_udelay(0x53e3);
    writel(uVar1 | 0xd80f100,*(long *)(param_1 + 0xa8) + 0x1000);
    __const_udelay(0x53e3);
    if ((*(byte *)(*(long *)(param_1 + 0x10) + 0xbf1) & 1) != 0) {
      iVar3 = 100;
      do {
        uVar2 = readl(*(long *)(param_1 + 0xa8) + 0x70);
        if ((uVar2 >> 0x1c & 0xf) == 0) {
          if ((int)uVar2 == 0) {
            return 0;
          }
          break;
        }
        __const_udelay(0x346de);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),"BIST status error (%d)\n",
               0xffffff92);
      return 0xffffff92;
    }
  }
  return 0;
}



//------------------------------------------------------------
// ufs_qcom_ice_resume @ 001124ac size=140
// signature: undefined ufs_qcom_ice_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 ufs_qcom_ice_resume(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  
  if ((*(byte *)(*(long *)(param_1 + 0x10) + 0xbf1) & 1) == 0) {
LAB_00112500:
    uVar2 = 0;
  }
  else {
    iVar3 = 100;
    do {
      uVar1 = readl(*(long *)(param_1 + 0xa8) + 0x70);
      if ((uVar1 >> 0x1c & 0xf) == 0) {
        if ((int)uVar1 == 0) goto LAB_00112500;
        break;
      }
      __const_udelay(0x346de);
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar2 = 0xffffff92;
    _dev_err(*(undefined8 *)(*(long *)(param_1 + 0x10) + 0x40),"BIST status error (%d)\n",0xffffff92
            );
  }
  return uVar2;
}



//------------------------------------------------------------
// ufs_qcom_ice_disable @ 0011253c size=48
// signature: undefined ufs_qcom_ice_disable(void)
// callers: [ufs_qcom_device_reset, ufs_qcom_suspend]
//------------------------------------------------------------

void ufs_qcom_ice_disable(long param_1)

{
  if (((*(byte *)(*(long *)(param_1 + 0x10) + 0xbf1) & 1) != 0) &&
     ((*(byte *)(*(long *)(param_1 + 0x10) + 0xd0) & 1) != 0)) {
    crypto_qti_disable();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_ice_debug @ 00112570 size=100
// signature: undefined ufs_qcom_ice_debug(void)
// callers: [ufs_qcom_dump_dbg_regs]
//------------------------------------------------------------

void ufs_qcom_ice_debug(long param_1)

{
  long lVar1;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  if ((param_1 != 0) && ((*(byte *)(*(long *)(param_1 + 0x10) + 0xbf1) & 1) != 0)) {
    local_28 = *(undefined8 *)(param_1 + 0xa8);
    uStack_20 = *(undefined8 *)(param_1 + 0xb0);
    crypto_qti_debug(&local_28);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufs_qcom_ice_program_key @ 001125d8 size=568
// signature: undefined ufs_qcom_ice_program_key(void)
// callers: []
//------------------------------------------------------------

int ufs_qcom_ice_program_key(long param_1,undefined8 *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined8 local_a0;
  undefined8 *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_98 = (undefined8 *)0x0;
  uStack_90 = 0;
  local_a0 = 0;
  iVar8 = qtee_shmbridge_allocate_shm(0x40,&local_a0);
  if (iVar8 == 0) {
    if (*(char *)((long)param_2 + 0x43) < '\0') {
      pcVar1 = (char *)(*(long *)(param_1 + 0x1220) + (ulong)*(byte *)((long)param_2 + 0x41) * 4);
      cVar2 = *pcVar1;
      cVar3 = pcVar1[2];
      if ((cVar2 == '\0') && (cVar3 == '\x03')) {
        local_58._4_4_ = (uint)((ulong)param_2[6] >> 0x20);
        local_50._0_4_ = (uint)param_2[7];
        uVar9 = (uint)*param_2;
        uVar9 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
        uVar10 = (uint)((ulong)*param_2 >> 0x20);
        uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
        local_50._4_4_ = (uint)((ulong)param_2[7] >> 0x20);
        local_80._0_4_ = (uint)param_2[1];
        local_80._4_4_ = (uint)((ulong)param_2[1] >> 0x20);
        local_88 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
        uVar9 = ((uint)local_80 & 0xff00ff00) >> 8 | ((uint)local_80 & 0xff00ff) << 8;
        uVar10 = (local_80._4_4_ & 0xff00ff00) >> 8 | (local_80._4_4_ & 0xff00ff) << 8;
        local_78._0_4_ = (uint)param_2[2];
        local_78._4_4_ = (uint)((ulong)param_2[2] >> 0x20);
        local_80 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
        local_70._0_4_ = (uint)param_2[3];
        local_70._4_4_ = (uint)((ulong)param_2[3] >> 0x20);
        uVar9 = ((uint)local_78 & 0xff00ff00) >> 8 | ((uint)local_78 & 0xff00ff) << 8;
        uVar10 = (local_78._4_4_ & 0xff00ff00) >> 8 | (local_78._4_4_ & 0xff00ff) << 8;
        local_78 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
        uVar9 = ((uint)local_70 & 0xff00ff00) >> 8 | ((uint)local_70 & 0xff00ff) << 8;
        local_68._0_4_ = (uint)param_2[4];
        local_68._4_4_ = (uint)((ulong)param_2[4] >> 0x20);
        uVar10 = (local_70._4_4_ & 0xff00ff00) >> 8 | (local_70._4_4_ & 0xff00ff) << 8;
        local_60._0_4_ = (uint)param_2[5];
        local_60._4_4_ = (uint)((ulong)param_2[5] >> 0x20);
        uVar4 = ((uint)local_68 & 0xff00ff00) >> 8 | ((uint)local_68 & 0xff00ff) << 8;
        uVar5 = (local_68._4_4_ & 0xff00ff00) >> 8 | (local_68._4_4_ & 0xff00ff) << 8;
        local_70 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
        local_58._0_4_ = (uint)param_2[6];
        uVar9 = ((uint)local_50 & 0xff00ff00) >> 8 | ((uint)local_50 & 0xff00ff) << 8;
        local_68 = CONCAT44(uVar5 >> 0x10 | uVar5 << 0x10,uVar4 >> 0x10 | uVar4 << 0x10);
        uVar10 = (local_50._4_4_ & 0xff00ff00) >> 8 | (local_50._4_4_ & 0xff00ff) << 8;
        uVar4 = ((uint)local_60 & 0xff00ff00) >> 8 | ((uint)local_60 & 0xff00ff) << 8;
        uVar5 = ((uint)local_58 & 0xff00ff00) >> 8 | ((uint)local_58 & 0xff00ff) << 8;
        uVar6 = (local_58._4_4_ & 0xff00ff00) >> 8 | (local_58._4_4_ & 0xff00ff) << 8;
        local_50 = CONCAT44(uVar10 >> 0x10 | uVar10 << 0x10,uVar9 >> 0x10 | uVar9 << 0x10);
        uVar9 = (local_60._4_4_ & 0xff00ff00) >> 8 | (local_60._4_4_ & 0xff00ff) << 8;
        local_58 = CONCAT44(uVar6 >> 0x10 | uVar6 << 0x10,uVar5 >> 0x10 | uVar5 << 0x10);
        local_60 = CONCAT44(uVar9 >> 0x10 | uVar9 << 0x10,uVar4 >> 0x10 | uVar4 << 0x10);
        local_98[6] = local_58;
        local_98[7] = local_50;
        local_98[4] = local_68;
        local_98[5] = local_60;
        local_98[2] = local_78;
        local_98[3] = local_70;
        *local_98 = local_88;
        local_98[1] = local_80;
        qtee_shmbridge_flush_shm_buf(&local_a0);
        iVar8 = qcom_scm_config_set_ice_key(param_3,local_a0,0x40,3,*(undefined1 *)(param_2 + 8),10)
        ;
        if (iVar8 != 0) {
          _printk(&DAT_00123505,"ufs_qcom_ice_program_key",iVar8,param_3);
        }
        qtee_shmbridge_inv_shm_buf(&local_a0);
        qtee_shmbridge_free_shm(&local_a0);
        local_58 = 0;
        local_50 = 0;
        local_68 = 0;
        local_60 = 0;
        local_78 = 0;
        local_70 = 0;
        local_88 = 0;
        local_80 = 0;
      }
      else {
        iVar8 = ___ratelimit(&ufs_qcom_ice_program_key__rs,"ufs_qcom_ice_program_key");
        if (iVar8 != 0) {
          _dev_err(*(undefined8 *)(param_1 + 0x40),
                   "Unhandled crypto capability; algorithm_id=%d, key_size=%d\n",cVar2,cVar3);
        }
        iVar8 = -0x16;
      }
    }
    else {
      iVar8 = qcom_scm_ice_invalidate_key(param_3);
    }
  }
  else {
    iVar8 = -0xc;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// writel @ 00112810 size=136
// signature: undefined writel(void)
// callers: [ufs_qcom_ice_enable]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x112828,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x112868,uVar1);
  return;
}



//------------------------------------------------------------
// pixel_init_manual_gc @ 001128a0 size=244
// signature: undefined pixel_init_manual_gc(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void pixel_init_manual_gc(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  char local_40 [24];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112994);
    (*pcVar1)();
  }
  lVar4 = *(long *)(param_1 + 0xb0);
  local_40[0x10] = '\0';
  local_40[0x11] = '\0';
  local_40[0x12] = '\0';
  local_40[0x13] = '\0';
  local_40[0x14] = '\0';
  local_40[0] = '\0';
  local_40[1] = '\0';
  local_40[2] = '\0';
  local_40[3] = '\0';
  local_40[4] = '\0';
  local_40[5] = '\0';
  local_40[6] = '\0';
  local_40[7] = '\0';
  local_40[8] = '\0';
  local_40[9] = '\0';
  local_40[10] = '\0';
  local_40[0xb] = '\0';
  local_40[0xc] = '\0';
  local_40[0xd] = '\0';
  local_40[0xe] = '\0';
  local_40[0xf] = '\0';
  *(undefined4 *)(lVar4 + 0xcc0) = 3;
  *(undefined1 *)(lVar4 + 0xcc4) = 1;
  *(undefined8 *)(lVar4 + 0xd10) = 2000;
  hrtimer_init(lVar4 + 0xcc8,1,1);
  *(code **)(lVar4 + 0xcf0) = pixel_mgc_hrtimer_handler;
  *(undefined8 *)(lVar4 + 0xd18) = 0xfffffffe0;
  *(long *)(lVar4 + 0xd20) = lVar4 + 0xd20;
  *(long *)(lVar4 + 0xd28) = lVar4 + 0xd20;
  *(code **)(lVar4 + 0xd30) = pixel_mgc_hibern8_work;
  snprintf(local_40,0x15,"ufs_mgc_hibern8_work_%d",*(int *)(*(long *)(param_1 + 0x38) + 0x1bc));
  uVar2 = alloc_workqueue(&DAT_00120bae,0xe000a,1,local_40);
  lVar3 = sp_el0;
  lVar3 = *(long *)(lVar3 + 0x638);
  *(undefined8 *)(lVar4 + 0xd48) = uVar2;
  if (lVar3 != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// pixel_mgc_hrtimer_handler @ 00112998 size=44
// signature: undefined pixel_mgc_hrtimer_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 pixel_mgc_hrtimer_handler(long param_1)

{
  queue_work_on(0x20,*(undefined8 *)(param_1 + 0x80),param_1 + 0x50);
  return 0;
}



//------------------------------------------------------------
// pixel_mgc_hibern8_work @ 001129c8 size=48
// signature: undefined pixel_mgc_hibern8_work(void)
// callers: []
//------------------------------------------------------------

void pixel_mgc_hibern8_work(long param_1)

{
  __pm_runtime_idle(*(long *)(*(long *)(param_1 + -0xd08) + 0x48) + 0x1d8,4);
  return;
}



//------------------------------------------------------------
// pixel_init @ 001129fc size=104
// signature: undefined pixel_init(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

void pixel_init(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112a64);
    (*pcVar1)();
  }
  lVar3 = *(long *)(param_1 + 0xb0);
  iVar2 = tracepoint_probe_register
                    (&__tracepoint_android_vh_ufs_update_sysfs,pixel_ufs_update_sysfs,0);
  if (iVar2 == 0) {
    *(undefined8 *)(lVar3 + 0xc90) = 0xfffffffe0;
    *(long *)(lVar3 + 0xc98) = lVar3 + 0xc98;
    *(long *)(lVar3 + 0xca0) = lVar3 + 0xc98;
    *(code **)(lVar3 + 0xca8) = pixel_ufs_update_sysfs_work;
  }
  return;
}



//------------------------------------------------------------
// pixel_ufs_update_sysfs @ 00112a68 size=56
// signature: undefined pixel_ufs_update_sysfs(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pixel_ufs_update_sysfs(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112aa0);
    (*pcVar1)();
  }
  queue_work_on(0x20,_system_highpri_wq,*(long *)(param_2 + 0xb0) + 0xc90);
  return;
}



//------------------------------------------------------------
// pixel_ufs_update_sysfs_work @ 00112aa4 size=88
// signature: undefined pixel_ufs_update_sysfs_work(void)
// callers: []
//------------------------------------------------------------

void pixel_ufs_update_sysfs_work(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + -0xc80);
  iVar1 = sysfs_create_groups(*(undefined8 *)(lVar2 + 0x40),&pixel_sysfs_hid_groups);
  if (iVar1 != 0) {
    _dev_err(*(undefined8 *)(lVar2 + 0x40),"%s: Failed to add a pixel group\n",
             "pixel_ufs_update_sysfs_work");
  }
  return;
}



//------------------------------------------------------------
// manual_gc_show @ 00112b00 size=292
// signature: undefined manual_gc_show(void)
// callers: []
//------------------------------------------------------------

long manual_gc_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  int local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112c24);
    (*pcVar1)();
  }
  lVar5 = *(long *)(lVar4 + 0xb0);
  local_3c = 0;
  if (*(int *)(lVar5 + 0xcc0) == 2) {
    pcVar3 = "disabled\n";
    goto LAB_00112bd8;
  }
  if (*(char *)(lVar5 + 0xcc4) == '\0') {
LAB_00112bb0:
    pcVar3 = "bkops\n";
  }
  else {
    if ((*(byte *)(lVar4 + 0x1f0) & 1) == 0) {
      __pm_runtime_resume(*(long *)(lVar4 + 0x48) + 0x1d8,4);
      iVar2 = ufshcd_query_attr_retry(lVar4,3,0x13,0,0,&local_3c);
      __pm_runtime_idle(*(long *)(lVar4 + 0x48) + 0x1d8,4);
      *(bool *)(lVar5 + 0xcc4) = iVar2 == 0;
      if (iVar2 != 0) goto LAB_00112bb0;
    }
    pcVar3 = "off\n";
    if (local_3c != 0) {
      pcVar3 = "on\n";
    }
  }
LAB_00112bd8:
  iVar2 = scnprintf(param_3,0x1000,&DAT_00120bae,pcVar3);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// manual_gc_store @ 00112c28 size=480
// signature: undefined manual_gc_store(void)
// callers: []
//------------------------------------------------------------

undefined8 manual_gc_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  long lVar6;
  undefined1 uVar7;
  long lVar8;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  if (lVar6 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112e08);
    (*pcVar1)();
  }
  lVar8 = *(long *)(lVar6 + 0xb0);
  local_4c = 0;
  iVar2 = kstrtouint(param_3,0,&local_4c);
  if ((iVar2 == 0) && (local_4c < 4)) {
    if ((*(byte *)(lVar6 + 0x1f0) & 1) == 0) {
      if ((local_4c & 0xfffffffe) == 2) {
        *(uint *)(lVar8 + 0xcc0) = local_4c;
      }
      else if (*(int *)(lVar8 + 0xcc0) != 2) {
        if (*(char *)(lVar8 + 0xcc4) != '\0') {
          iVar2 = manual_gc_enable(lVar6,&local_4c);
          *(bool *)(lVar8 + 0xcc4) = iVar2 == 0;
        }
        __pm_runtime_resume(*(long *)(lVar6 + 0x48) + 0x1d8,4);
        if (*(char *)(lVar8 + 0xcc4) == '\0') {
          uVar5 = 3;
          if (local_4c == 1) {
            uVar5 = 1;
          }
          iVar3 = ufshcd_bkops_ctrl(lVar6,uVar5);
          iVar2 = -0xb;
          if (*(char *)(lVar6 + 0xa48) != '\0') {
            iVar2 = iVar3;
          }
        }
        else {
          iVar2 = 0;
        }
        if (0x30f < *(ushort *)(lVar6 + 0xa20)) {
          uVar5 = 6;
          if (local_4c != 1) {
            uVar5 = 7;
          }
          if (*(char *)(lVar6 + 0xa2d) == '\0') {
            uVar7 = *(undefined1 *)(lVar6 + 0xa2c);
          }
          else {
            uVar7 = 0;
          }
          ufshcd_query_flag_retry(lVar6,uVar5,0x10,uVar7,0);
          ufshcd_query_flag_retry(lVar6,uVar5,0xf,uVar7,0);
        }
        if (iVar2 == 0) {
          uVar4 = hrtimer_active(lVar8 + 0xcc8);
          if ((uVar4 & 1) == 0) {
            hrtimer_start_range_ns(lVar8 + 0xcc8,*(long *)(lVar8 + 0xd10) * 1000000,0,1);
            goto LAB_00112c88;
          }
        }
        __pm_runtime_idle(*(long *)(lVar6 + 0x48) + 0x1d8,4);
      }
    }
    else {
      param_4 = 0xfffffffffffffff0;
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
LAB_00112c88:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// manual_gc_enable @ 00112e08 size=124
// signature: undefined manual_gc_enable(void)
// callers: [manual_gc_store]
//------------------------------------------------------------

undefined4 manual_gc_enable(long param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0x1f0) & 1) == 0) {
    __pm_runtime_resume(*(long *)(param_1 + 0x48) + 0x1d8,4);
    uVar1 = ufshcd_query_attr_retry(param_1,4,0x12,0,0,param_2);
    __pm_runtime_idle(*(long *)(param_1 + 0x48) + 0x1d8,4);
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}



//------------------------------------------------------------
// manual_gc_hold_show @ 00112e88 size=68
// signature: undefined manual_gc_hold_show(void)
// callers: []
//------------------------------------------------------------

long manual_gc_hold_show(long param_1,undefined8 param_2,char *param_3)

{
  code *pcVar1;
  int iVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112ecc);
    (*pcVar1)();
  }
  iVar2 = snprintf(param_3,0x1000,"%lu\n",
                   *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x98) + 0xb0) + 0xd10));
  return (long)iVar2;
}



//------------------------------------------------------------
// manual_gc_hold_store @ 00112ed0 size=140
// signature: undefined manual_gc_hold_store(void)
// callers: []
//------------------------------------------------------------

undefined8
manual_gc_hold_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x112f5c);
    (*pcVar1)();
  }
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0xb0);
  local_30 = 0;
  iVar2 = kstrtoull(param_3,0,&local_30);
  if (iVar2 == 0) {
    *(undefined8 *)(lVar3 + 0xd10) = local_30;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// manual_gc_status_show @ 00112f60 size=296
// signature: undefined manual_gc_status_show(void)
// callers: []
//------------------------------------------------------------

long manual_gc_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  undefined4 local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x113088);
    (*pcVar1)();
  }
  lVar5 = *(long *)(lVar4 + 0xb0);
  local_3c = 0;
  if (*(int *)(lVar5 + 0xcc0) == 2) {
    pcVar3 = "disabled\n";
  }
  else {
    if (*(char *)(lVar5 + 0xcc4) != '\0') {
      if ((*(byte *)(lVar4 + 0x1f0) & 1) == 0) {
        __pm_runtime_resume(*(long *)(lVar4 + 0x48) + 0x1d8,4);
        iVar2 = ufshcd_query_attr_retry(lVar4,3,0x13,0,0,&local_3c);
        __pm_runtime_idle(*(long *)(lVar4 + 0x48) + 0x1d8,4);
        *(bool *)(lVar5 + 0xcc4) = iVar2 == 0;
        if (iVar2 != 0) goto LAB_00113018;
      }
      iVar2 = scnprintf(param_3,0x1000,&DAT_001209c0,local_3c);
      goto LAB_00113050;
    }
LAB_00113018:
    pcVar3 = "bkops\n";
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_00120bae,pcVar3);
LAB_00113050:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// ufsf_get_kernel_version @ 0011308c size=248
// signature: undefined ufsf_get_kernel_version(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufsf_get_kernel_version(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_60 = _DAT_0012b7e2;
  uStack_58 = _DAT_0012b7ea;
  local_50 = _DAT_0012b7f2;
  uStack_48 = _DAT_0012b7fa;
  local_80 = _DAT_0012b7c2;
  uStack_78 = _DAT_0012b7ca;
  local_88 = (char *)&local_80;
  local_70 = _DAT_0012b7d2;
  uStack_68 = _DAT_0012b7da;
  pcVar4 = strsep(&local_88,".");
  iVar2 = simple_strtol(pcVar4,0,10);
  pcVar4 = strsep(&local_88,".");
  iVar3 = simple_strtol(pcVar4,0,10);
  _printk(&DAT_00120574,"ufsf_get_kernel_version",0xf0,iVar2,iVar3);
  *(int *)(param_1 + 0x170) = iVar3 + iVar2 * 100;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufsf_device_check @ 00113188 size=1120
// signature: undefined ufsf_device_check(void)
// callers: [ufsf_device_check_work_handler]
//------------------------------------------------------------

void ufsf_device_check(long param_1)

{
  long *plVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined1 uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  long lVar15;
  uint local_6c;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1135e8);
    (*pcVar5)();
  }
  lVar13 = *(long *)(param_1 + 0xb0);
  _printk(&DAT_001212a0,"ufsf_init_ufs_ver_info",0xcf,*(undefined2 *)(param_1 + 0xa20));
  uVar4 = *(ushort *)(param_1 + 0xa20);
  if (uVar4 < 0x400) {
    uVar9 = 1;
    if ((uVar4 != 0x220) && (uVar4 != 0x310)) {
LAB_0011321c:
      uVar9 = 0xff;
    }
  }
  else {
    if ((uVar4 != 0x410) && (uVar4 != 0x400)) goto LAB_0011321c;
    uVar9 = 0;
  }
  *(undefined1 *)(lVar13 + 0xe68) = uVar9;
  _printk(&DAT_001247af,"ufsf_device_check",0xfc);
  bVar2 = *(byte *)(lVar13 + 0xe68);
  uVar11 = (ulong)bVar2;
  if (uVar11 == 0) {
    uVar10 = 0;
    uVar14 = 0xff;
  }
  else {
    if ((7 < bVar2) || (3 < bVar2)) goto LAB_001135d8;
    uVar14 = *(uint *)(ufsf_desc + uVar11 * 4);
    uVar10 = uVar11;
    if (3 < uVar11) {
LAB_001135dc:
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(1,0x1135e0);
      (*pcVar5)();
    }
  }
  uVar9 = (&ufsf_idn)[uVar10 * 4];
  puVar8 = (undefined1 *)__kmalloc(uVar14 & 0xff,0xcc0);
  if (puVar8 != (undefined1 *)0x0) {
    plVar1 = (long *)(lVar13 + 0xd50);
    local_6c = uVar14 & 0xff;
    lVar12 = *plVar1;
    __pm_runtime_resume(*(long *)(lVar12 + 0x48) + 0x1d8,4);
    iVar6 = ufshcd_query_descriptor_retry(lVar12,1,uVar9,0,uVar11,puVar8,&local_6c);
    if (iVar6 == 0) {
      __pm_runtime_idle(*(long *)(lVar12 + 0x48) + 0x1d8,4);
      *(uint *)(lVar13 + 0xd58) = (uint)(byte)puVar8[6];
      _printk(&DAT_001239f5,"ufsf_read_dev_desc",0x78);
      _printk(&DAT_00122c3f,"ufsf_read_dev_desc",0x7f,bVar2,*puVar8,*puVar8,puVar8[0x1f],
              puVar8[0x51],puVar8[0x52]);
      if (bVar2 == 0) {
        _printk(&DAT_00124241,"ufsf_read_dev_desc",0x84,puVar8[0xfd],puVar8[0xfe]);
      }
      _printk(&DAT_001209da,"ufsf_read_dev_desc",0x88,0x10401,&DAT_001212c5);
      ufshid_get_dev_info(plVar1,puVar8);
      kfree(puVar8);
      cVar3 = *(char *)(lVar13 + 0xe68);
      if (cVar3 == '\0') {
        uVar14 = 0xff;
        lVar12 = 2;
      }
      else {
        if (cVar3 != '\x01') {
LAB_001135d8:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1135dc);
          (*pcVar5)();
        }
        uVar14 = 0x5e;
        lVar12 = 3;
      }
      uVar9 = (&ufsf_idn)[lVar12 * 4];
      puVar8 = (undefined1 *)__kmalloc(uVar14,0xcc0);
      if (puVar8 == (undefined1 *)0x0) goto LAB_001132a4;
      lVar12 = *plVar1;
      local_6c = uVar14;
      __pm_runtime_resume(*(long *)(lVar12 + 0x48) + 0x1d8,4);
      iVar6 = ufshcd_query_descriptor_retry(lVar12,1,uVar9,0,cVar3,puVar8,&local_6c);
      if (iVar6 == 0) {
        __pm_runtime_idle(*(long *)(lVar12 + 0x48) + 0x1d8,4);
        iVar6 = ufshid_get_state(plVar1);
        if (iVar6 == 0) {
          ufshid_get_geo_info(plVar1,puVar8);
        }
        kfree(puVar8);
        iVar6 = 0;
        do {
          uVar11 = (ulong)*(byte *)(lVar13 + 0xe68);
          if (uVar11 == 0) {
            lVar12 = 4;
          }
          else {
            if (3 < *(byte *)(lVar13 + 0xe68)) goto LAB_001135d8;
            lVar12 = uVar11 + 4;
          }
          if ((0x20 < (ulong)(lVar12 * 4)) || (lVar12 == 8)) goto LAB_001135dc;
          bVar2 = ufsf_desc[lVar12 * 4];
          lVar12 = __kmalloc(bVar2,0xcc0);
          if (lVar12 != 0) {
            lVar15 = *plVar1;
            local_6c = (uint)bVar2;
            __pm_runtime_resume(*(long *)(lVar15 + 0x48) + 0x1d8,4);
            iVar7 = ufshcd_query_descriptor_retry(lVar15,1,2,iVar6,uVar11,lVar12,&local_6c);
            if (iVar7 == 0) {
              __pm_runtime_idle(*(long *)(lVar15 + 0x48) + 0x1d8,4);
            }
            else {
              _printk(&DAT_00122757,"ufsf_read_desc",0x5f,iVar7);
              __pm_runtime_idle(*(long *)(lVar15 + 0x48) + 0x1d8,4);
              _printk(&DAT_00121ae0,"ufsf_read_unit_desc",0xbe,iVar7);
            }
          }
          kfree(lVar12);
          iVar6 = iVar6 + 1;
        } while (iVar6 != 8);
        goto LAB_001132ac;
      }
    }
    _printk(&DAT_00122757,"ufsf_read_desc",0x5f,iVar6);
    __pm_runtime_idle(*(long *)(lVar12 + 0x48) + 0x1d8,4);
  }
LAB_001132a4:
  kfree(puVar8);
LAB_001132ac:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufsf_rpm_put_noidle @ 001135ec size=80
// signature: undefined ufsf_rpm_put_noidle(void)
// callers: [ufshid_allow_enter_suspend, ufshid_write_attr, ufshid_attr_show, ufshid_trigger_on, ufshid_read_attr_micron, ufshid_trigger_off, ufshid_issue_disable, ufshid_auto_hibern8_enable, micron_ufshid_trigger_work_fn, ufshid_resume_3_0, ufshid_attr_store, ufshid_read_attr]
//------------------------------------------------------------

void ufsf_rpm_put_noidle(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  
  piVar1 = (int *)(*(long *)(param_1 + 0x48) + 0x3d0);
  iVar5 = *(int *)(*(long *)(param_1 + 0x48) + 0x3d0);
  do {
    if (iVar5 == 0) {
      return;
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar5) goto LAB_00113618;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00113618:
    bVar4 = iVar5 == iVar2;
    iVar5 = iVar2;
    if (bVar4) {
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// ufsf_print_query_buf @ 00113654 size=488
// signature: undefined ufsf_print_query_buf(void)
// callers: [ufshid_sysfs_show_l2p_param_print]
//------------------------------------------------------------

void ufsf_print_query_buf(long param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  char local_168 [256];
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_168[0xf8] = '\0';
  local_168[0xf9] = '\0';
  local_168[0xfa] = '\0';
  local_168[0xfb] = '\0';
  local_168[0xfc] = '\0';
  local_168[0xfd] = '\0';
  local_168[0xfe] = '\0';
  local_168[0xe8] = '\0';
  local_168[0xe9] = '\0';
  local_168[0xea] = '\0';
  local_168[0xeb] = '\0';
  local_168[0xec] = '\0';
  local_168[0xed] = '\0';
  local_168[0xee] = '\0';
  local_168[0xef] = '\0';
  local_168[0xf0] = '\0';
  local_168[0xf1] = '\0';
  local_168[0xf2] = '\0';
  local_168[0xf3] = '\0';
  local_168[0xf4] = '\0';
  local_168[0xf5] = '\0';
  local_168[0xf6] = '\0';
  local_168[0xf7] = 0;
  local_168[0xd8] = '\0';
  local_168[0xd9] = '\0';
  local_168[0xda] = '\0';
  local_168[0xdb] = '\0';
  local_168[0xdc] = '\0';
  local_168[0xdd] = '\0';
  local_168[0xde] = '\0';
  local_168[0xdf] = '\0';
  local_168[0xe0] = '\0';
  local_168[0xe1] = '\0';
  local_168[0xe2] = '\0';
  local_168[0xe3] = '\0';
  local_168[0xe4] = '\0';
  local_168[0xe5] = '\0';
  local_168[0xe6] = '\0';
  local_168[0xe7] = '\0';
  local_168[200] = '\0';
  local_168[0xc9] = '\0';
  local_168[0xca] = '\0';
  local_168[0xcb] = '\0';
  local_168[0xcc] = '\0';
  local_168[0xcd] = '\0';
  local_168[0xce] = '\0';
  local_168[0xcf] = '\0';
  local_168[0xd0] = '\0';
  local_168[0xd1] = '\0';
  local_168[0xd2] = '\0';
  local_168[0xd3] = '\0';
  local_168[0xd4] = '\0';
  local_168[0xd5] = '\0';
  local_168[0xd6] = '\0';
  local_168[0xd7] = '\0';
  local_168[0xb8] = '\0';
  local_168[0xb9] = '\0';
  local_168[0xba] = '\0';
  local_168[0xbb] = '\0';
  local_168[0xbc] = '\0';
  local_168[0xbd] = '\0';
  local_168[0xbe] = '\0';
  local_168[0xbf] = '\0';
  local_168[0xc0] = '\0';
  local_168[0xc1] = '\0';
  local_168[0xc2] = '\0';
  local_168[0xc3] = '\0';
  local_168[0xc4] = '\0';
  local_168[0xc5] = '\0';
  local_168[0xc6] = '\0';
  local_168[199] = '\0';
  local_168[0xa8] = '\0';
  local_168[0xa9] = '\0';
  local_168[0xaa] = '\0';
  local_168[0xab] = '\0';
  local_168[0xac] = '\0';
  local_168[0xad] = '\0';
  local_168[0xae] = '\0';
  local_168[0xaf] = '\0';
  local_168[0xb0] = '\0';
  local_168[0xb1] = '\0';
  local_168[0xb2] = '\0';
  local_168[0xb3] = '\0';
  local_168[0xb4] = '\0';
  local_168[0xb5] = '\0';
  local_168[0xb6] = '\0';
  local_168[0xb7] = '\0';
  local_168[0x98] = '\0';
  local_168[0x99] = '\0';
  local_168[0x9a] = '\0';
  local_168[0x9b] = '\0';
  local_168[0x9c] = '\0';
  local_168[0x9d] = '\0';
  local_168[0x9e] = '\0';
  local_168[0x9f] = '\0';
  local_168[0xa0] = '\0';
  local_168[0xa1] = '\0';
  local_168[0xa2] = '\0';
  local_168[0xa3] = '\0';
  local_168[0xa4] = '\0';
  local_168[0xa5] = '\0';
  local_168[0xa6] = '\0';
  local_168[0xa7] = '\0';
  local_168[0x88] = '\0';
  local_168[0x89] = '\0';
  local_168[0x8a] = '\0';
  local_168[0x8b] = '\0';
  local_168[0x8c] = '\0';
  local_168[0x8d] = '\0';
  local_168[0x8e] = '\0';
  local_168[0x8f] = '\0';
  local_168[0x90] = '\0';
  local_168[0x91] = '\0';
  local_168[0x92] = '\0';
  local_168[0x93] = '\0';
  local_168[0x94] = '\0';
  local_168[0x95] = '\0';
  local_168[0x96] = '\0';
  local_168[0x97] = '\0';
  local_168[0x78] = '\0';
  local_168[0x79] = '\0';
  local_168[0x7a] = '\0';
  local_168[0x7b] = '\0';
  local_168[0x7c] = '\0';
  local_168[0x7d] = '\0';
  local_168[0x7e] = '\0';
  local_168[0x7f] = '\0';
  local_168[0x80] = '\0';
  local_168[0x81] = '\0';
  local_168[0x82] = '\0';
  local_168[0x83] = '\0';
  local_168[0x84] = '\0';
  local_168[0x85] = '\0';
  local_168[0x86] = '\0';
  local_168[0x87] = '\0';
  local_168[0x68] = '\0';
  local_168[0x69] = '\0';
  local_168[0x6a] = '\0';
  local_168[0x6b] = '\0';
  local_168[0x6c] = '\0';
  local_168[0x6d] = '\0';
  local_168[0x6e] = '\0';
  local_168[0x6f] = '\0';
  local_168[0x70] = '\0';
  local_168[0x71] = '\0';
  local_168[0x72] = '\0';
  local_168[0x73] = '\0';
  local_168[0x74] = '\0';
  local_168[0x75] = '\0';
  local_168[0x76] = '\0';
  local_168[0x77] = '\0';
  local_168[0x58] = '\0';
  local_168[0x59] = '\0';
  local_168[0x5a] = '\0';
  local_168[0x5b] = '\0';
  local_168[0x5c] = '\0';
  local_168[0x5d] = '\0';
  local_168[0x5e] = '\0';
  local_168[0x5f] = '\0';
  local_168[0x60] = '\0';
  local_168[0x61] = '\0';
  local_168[0x62] = '\0';
  local_168[99] = '\0';
  local_168[100] = '\0';
  local_168[0x65] = '\0';
  local_168[0x66] = '\0';
  local_168[0x67] = '\0';
  local_168[0x48] = '\0';
  local_168[0x49] = '\0';
  local_168[0x4a] = '\0';
  local_168[0x4b] = '\0';
  local_168[0x4c] = '\0';
  local_168[0x4d] = '\0';
  local_168[0x4e] = '\0';
  local_168[0x4f] = '\0';
  local_168[0x50] = '\0';
  local_168[0x51] = '\0';
  local_168[0x52] = '\0';
  local_168[0x53] = '\0';
  local_168[0x54] = '\0';
  local_168[0x55] = '\0';
  local_168[0x56] = '\0';
  local_168[0x57] = '\0';
  local_168[0x38] = '\0';
  local_168[0x39] = '\0';
  local_168[0x3a] = '\0';
  local_168[0x3b] = '\0';
  local_168[0x3c] = '\0';
  local_168[0x3d] = '\0';
  local_168[0x3e] = '\0';
  local_168[0x3f] = '\0';
  local_168[0x40] = '\0';
  local_168[0x41] = '\0';
  local_168[0x42] = '\0';
  local_168[0x43] = '\0';
  local_168[0x44] = '\0';
  local_168[0x45] = '\0';
  local_168[0x46] = '\0';
  local_168[0x47] = '\0';
  local_168[0x28] = '\0';
  local_168[0x29] = '\0';
  local_168[0x2a] = '\0';
  local_168[0x2b] = '\0';
  local_168[0x2c] = '\0';
  local_168[0x2d] = '\0';
  local_168[0x2e] = '\0';
  local_168[0x2f] = '\0';
  local_168[0x30] = '\0';
  local_168[0x31] = '\0';
  local_168[0x32] = '\0';
  local_168[0x33] = '\0';
  local_168[0x34] = '\0';
  local_168[0x35] = '\0';
  local_168[0x36] = '\0';
  local_168[0x37] = '\0';
  local_168[0x18] = '\0';
  local_168[0x19] = '\0';
  local_168[0x1a] = '\0';
  local_168[0x1b] = '\0';
  local_168[0x1c] = '\0';
  local_168[0x1d] = '\0';
  local_168[0x1e] = '\0';
  local_168[0x1f] = '\0';
  local_168[0x20] = '\0';
  local_168[0x21] = '\0';
  local_168[0x22] = '\0';
  local_168[0x23] = '\0';
  local_168[0x24] = '\0';
  local_168[0x25] = '\0';
  local_168[0x26] = '\0';
  local_168[0x27] = '\0';
  local_168[8] = '\0';
  local_168[9] = '\0';
  local_168[10] = '\0';
  local_168[0xb] = '\0';
  local_168[0xc] = '\0';
  local_168[0xd] = '\0';
  local_168[0xe] = '\0';
  local_168[0xf] = '\0';
  local_168[0x10] = '\0';
  local_168[0x11] = '\0';
  local_168[0x12] = '\0';
  local_168[0x13] = '\0';
  local_168[0x14] = '\0';
  local_168[0x15] = '\0';
  local_168[0x16] = '\0';
  local_168[0x17] = '\0';
  builtin_strncpy(local_168,"(0x00):",8);
  if ((int)param_2 < 1) {
    uVar3 = 7;
    builtin_strncpy(local_168,"(0x00):\n",8);
  }
  else {
    uVar6 = 0;
    if (0xfe < (int)param_2) {
      param_2 = 0xff;
    }
    uVar5 = 7;
    do {
      if (0xff < (uint)uVar5) goto LAB_00113834;
      iVar4 = snprintf(local_168 + uVar5,4," %.2X",(uint)*(byte *)(param_1 + uVar6));
      uVar6 = uVar6 + 1;
      uVar3 = iVar4 + (uint)uVar5;
      uVar5 = (ulong)uVar3;
      if ((uVar6 & 0xf) == 0) {
        if ((0xfe < uVar3) || (local_168[uVar5] = '\n', uVar3 == 0xfe)) goto LAB_00113834;
        if (0xfe < uVar3) goto LAB_001137b0;
        local_168[uVar5 + 1] = '\0';
        _printk(local_168);
        uVar3 = snprintf(local_168,8,"(0x%.2X):",(uint)uVar6);
        uVar5 = (ulong)uVar3;
      }
      else if ((uVar6 & 3) == 0) {
        if (0xff < uVar3) goto LAB_00113834;
        uVar5 = (ulong)(uVar3 + 2);
        local_168[(ulong)uVar3 + 2] = '\0';
        (local_168 + uVar3)[0] = ' ';
        (local_168 + uVar3)[1] = ':';
      }
      uVar3 = (uint)uVar5;
    } while (param_2 != uVar6);
    if ((0xfe < uVar3) || (local_168[uVar5] = '\n', uVar3 == 0xfe)) {
LAB_00113834:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x113838);
      (*pcVar2)();
    }
  }
  if (uVar3 < 0xff) {
    local_168[(ulong)uVar3 + 1] = '\0';
    _printk(local_168);
    lVar1 = sp_el0;
    if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
LAB_001137b0:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x1137b4);
  (*pcVar2)();
}



//------------------------------------------------------------
// ufsf_upiu_check_for_ccd @ 00113840 size=416
// signature: undefined ufsf_upiu_check_for_ccd(void)
// callers: [ufsf_compl_command]
//------------------------------------------------------------

void ufsf_upiu_check_for_ccd(long param_1,long param_2)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  void *__dest;
  
  if ((*(char *)(*(long *)(param_2 + 0x40) + 0xd4) == -0x40) &&
     (*(char *)(*(long *)(param_2 + 0x40) + 0xd5) == 'Q')) {
    lVar5 = *(long *)(param_2 + 0x10);
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x178) + -4) != -0x143e8628) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1138c4);
      (*pcVar2)();
    }
    iVar3 = (*(code *)**(undefined8 **)(param_1 + 0x178))(lVar5);
    uVar1 = *(ushort *)(*(long *)(param_2 + 0x10) + 0x20);
    if ((iVar3 == 8) && (uVar1 == 0x600)) {
      _printk(&DAT_0011fb17,"ufsf_upiu_check_for_ccd",0x14f);
    }
    else {
      _printk(&DAT_00122213,"ufsf_upiu_check_for_ccd",0x14b);
      _printk(&DAT_00122f49,"ufsf_upiu_check_for_ccd",0x14d,iVar3,uVar1 >> 8 | uVar1 << 8);
    }
    _printk(&DAT_001205aa,"ufsf_upiu_check_for_ccd",0x154,*(undefined1 *)(lVar5 + 0x22),
            *(undefined1 *)(lVar5 + 0x23),*(undefined1 *)(lVar5 + 0x24),
            *(undefined1 *)(lVar5 + 0x25),*(undefined1 *)(lVar5 + 0x26),
            *(undefined1 *)(lVar5 + 0x27));
    *(undefined4 *)(*(long *)(param_2 + 0x40) + 0x124) = 6;
    __dest = *(void **)(*(long *)(param_2 + 0x40) + 0x128);
    if (__dest != (void *)0x0) {
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0x178) + -4) != -0x143e8628) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1139ac);
        (*pcVar2)();
      }
      iVar3 = (*(code *)**(undefined8 **)(param_1 + 0x178))(*(undefined8 *)(param_2 + 0x10));
      if (iVar3 != 0) {
        uVar1 = *(ushort *)(*(long *)(param_2 + 0x10) + 0x20);
        uVar4 = (uint)(uVar1 >> 8) | (uVar1 & 0xff00ff) << 8;
        if (0x11 < uVar4) {
          uVar4 = 0x12;
        }
        memcpy(__dest,(void *)(*(long *)(param_2 + 0x10) + 0x22),(ulong)uVar4);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// ufsf_is_valid_lun @ 001139e4 size=12
// signature: undefined ufsf_is_valid_lun(void)
// callers: []
//------------------------------------------------------------

bool ufsf_is_valid_lun(int param_1)

{
  return param_1 < 8;
}



//------------------------------------------------------------
// ufsf_slave_configure @ 001139f4 size=140
// signature: undefined ufsf_slave_configure(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufsf_slave_configure(long param_1,long param_2)

{
  code *pcVar1;
  ulong uVar2;
  
  uVar2 = *(ulong *)(param_2 + 0x98);
  if ((int)uVar2 < 8) {
    if (7 < uVar2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x113a80);
      (*pcVar1)();
    }
    *(long *)(param_1 + uVar2 * 8 + 0x10) = param_2;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    _printk(&DAT_00122f81,"ufsf_slave_configure",0x16f,*(undefined4 *)(param_2 + 0x98),param_2,
            *(undefined8 *)(param_2 + 8));
    queue_work_on(0x20,_system_wq,param_1 + 0x58);
  }
  return;
}



//------------------------------------------------------------
// ufsf_prep_fn @ 00113a84 size=132
// signature: undefined ufsf_prep_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 ufsf_prep_fn(undefined8 param_1,long param_2)

{
  int iVar1;
  
  if (*(int *)(*(long *)(param_2 + 0x40) + 0xd6) == 0x30425048) {
    *(undefined1 *)(param_2 + 0x54) = 0x7f;
    _printk(&DAT_00123f43,"ufsf_prep_fn",0x17b,0x7f);
  }
  else {
    iVar1 = ufshid_get_state();
    if (iVar1 == 1) {
      ufshid_prep_fn(param_1,param_2);
    }
  }
  return 0;
}



//------------------------------------------------------------
// ufsf_reset_lu @ 00113b0c size=4
// signature: undefined ufsf_reset_lu(void)
// callers: []
//------------------------------------------------------------

void ufsf_reset_lu(void)

{
  return;
}



//------------------------------------------------------------
// ufsf_reset_host @ 00113b14 size=172
// signature: undefined ufsf_reset_host(void)
// callers: [ufs_qcom_device_reset]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufsf_reset_host(long *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  if ((char)param_1[10] != '\0') {
    lVar5 = *param_1;
    lVar6 = *(long *)(lVar5 + 0x38);
    uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(lVar6 + 0x38));
    uVar1 = *(uint *)(lVar5 + 0x1f0);
    _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar6 + 0x38),uVar4);
    if ((uVar1 & 1) != 0) {
      uVar2 = ufshid_get_state(param_1);
      _printk(&DAT_00120f8e,"ufsf_reset_host",0x1a7,uVar2);
      iVar3 = ufshid_get_state(param_1);
      if (iVar3 == 1) {
        ufshid_reset_host(param_1);
      }
      queue_work_on(0x20,_system_wq,param_1 + 0x17);
    }
  }
  return;
}



//------------------------------------------------------------
// ufsf_get_data_seg_len_6_1 @ 00113bc4 size=12
// signature: undefined ufsf_get_data_seg_len_6_1(void)
// callers: []
//------------------------------------------------------------

ushort ufsf_get_data_seg_len_6_1(long param_1)

{
  return *(ushort *)(param_1 + 10) >> 8 | *(ushort *)(param_1 + 10) << 8;
}



//------------------------------------------------------------
// ufsf_get_req_rsp_6_1 @ 00113bd4 size=8
// signature: undefined ufsf_get_req_rsp_6_1(void)
// callers: []
//------------------------------------------------------------

undefined1 ufsf_get_req_rsp_6_1(undefined1 *param_1)

{
  return *param_1;
}



//------------------------------------------------------------
// ufsf_get_rsp_upiu_result_6_1 @ 00113be0 size=12
// signature: undefined ufsf_get_rsp_upiu_result_6_1(void)
// callers: []
//------------------------------------------------------------

ushort ufsf_get_rsp_upiu_result_6_1(long param_1)

{
  return *(ushort *)(param_1 + 6) >> 8 | *(ushort *)(param_1 + 6) << 8;
}



//------------------------------------------------------------
// ufsf_get_data_seg_len_6_6 @ 00113bf0 size=16
// signature: undefined ufsf_get_data_seg_len_6_6(void)
// callers: []
//------------------------------------------------------------

ushort ufsf_get_data_seg_len_6_6(long param_1)

{
  return *(ushort *)(param_1 + 10) >> 8 | *(ushort *)(param_1 + 10) << 8;
}



//------------------------------------------------------------
// ufsf_get_req_rsp_6_6 @ 00113c04 size=8
// signature: undefined ufsf_get_req_rsp_6_6(void)
// callers: []
//------------------------------------------------------------

undefined1 ufsf_get_req_rsp_6_6(undefined1 *param_1)

{
  return *param_1;
}



//------------------------------------------------------------
// ufsf_get_rsp_upiu_result_6_6 @ 00113c10 size=8
// signature: undefined ufsf_get_rsp_upiu_result_6_6(void)
// callers: []
//------------------------------------------------------------

undefined1 ufsf_get_rsp_upiu_result_6_6(long param_1)

{
  return *(undefined1 *)(param_1 + 6);
}



//------------------------------------------------------------
// ufsf_compl_command @ 00113c1c size=272
// signature: undefined ufsf_compl_command(void)
// callers: [ufs_vh_compl_command]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufsf_compl_command(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x113d2c);
    (*pcVar3)();
  }
  if (*(long *)(param_2 + 0x40) != 0) {
    lVar5 = *(long *)(param_1 + 0xb0);
    if (*(long *)(lVar5 + 0xec8) != 0) {
      iVar1 = ufsf_get_tr_ocs(param_2,0);
      if (iVar1 == 0) {
        pcVar3 = *(code **)(*(long *)(lVar5 + 0xec8) + 8);
        if (*(int *)(pcVar3 + -4) != -0x143e8628) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x113c84);
          (*pcVar3)();
        }
        iVar1 = (*pcVar3)(*(undefined8 *)(param_2 + 0x10));
        if (iVar1 == 0x21) {
          pcVar3 = *(code **)(*(long *)(lVar5 + 0xec8) + 0x10);
          if (*(int *)(pcVar3 + -4) != -0x143e8628) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x113cb4);
            (*pcVar3)();
          }
          iVar1 = (*pcVar3)(*(undefined8 *)(param_2 + 0x10));
          if (iVar1 == 0) {
            ufsf_upiu_check_for_ccd(lVar5 + 0xd50,param_2);
          }
        }
      }
      iVar1 = *(int *)(param_1 + 0x8c);
      uVar4 = *(undefined8 *)(param_2 + 0x40);
      lVar5 = *(long *)(param_1 + 0xb0);
      iVar2 = _find_next_bit(param_1 + 0x80,(long)iVar1,0);
      if (((*(long *)(param_1 + 0x70) == 0) && (iVar1 <= iVar2)) &&
         (iVar1 = ufshid_is_hid_req(uVar4), iVar1 == 0)) {
        queue_work_on(0x20,_system_wq,lVar5 + 0xe90);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// ufs_samsung_register_hooks @ 00113d30 size=96
// signature: undefined ufs_samsung_register_hooks(void)
// callers: [ufs_qcom_probe]
//------------------------------------------------------------

void ufs_samsung_register_hooks(void)

{
  tracepoint_probe_register(&__tracepoint_android_vh_ufs_prepare_command,ufs_vh_prep_fn,0);
  tracepoint_probe_register(&__tracepoint_android_vh_ufs_compl_command,ufs_vh_compl_command,0);
  tracepoint_probe_register(&__tracepoint_android_vh_ufs_update_sdev,ufs_vh_update_sdev,0);
  return;
}



//------------------------------------------------------------
// ufs_vh_prep_fn @ 00113d94 size=160
// signature: undefined ufs_vh_prep_fn(void)
// callers: []
//------------------------------------------------------------

void ufs_vh_prep_fn(undefined8 param_1,long param_2,undefined8 param_3,long param_4,
                   undefined4 *param_5)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_2 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x113e34);
    (*pcVar2)();
  }
  if (*(int *)(*(long *)(param_4 + 0x40) + 0xd6) == 0x30425048) {
    *(undefined1 *)(param_4 + 0x54) = 0x7f;
    _printk(&DAT_00123f43,"ufsf_prep_fn",0x17b,0x7f);
  }
  else {
    lVar1 = *(long *)(param_2 + 0xb0) + 0xd50;
    iVar3 = ufshid_get_state(lVar1);
    if (iVar3 == 1) {
      ufshid_prep_fn(lVar1,param_4);
    }
  }
  *param_5 = 0;
  return;
}



//------------------------------------------------------------
// ufs_vh_compl_command @ 00113e38 size=36
// signature: undefined ufs_vh_compl_command(void)
// callers: []
//------------------------------------------------------------

void ufs_vh_compl_command(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ufsf_compl_command(param_2,param_3);
  return;
}



//------------------------------------------------------------
// ufs_vh_update_sdev @ 00113e60 size=156
// signature: undefined ufs_vh_update_sdev(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufs_vh_update_sdev(undefined8 param_1,long *param_2)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  
  if (*param_2 == -0x9b0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x113efc);
    (*pcVar1)();
  }
  uVar2 = param_2[0x13];
  if ((int)uVar2 < 8) {
    if (7 < uVar2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x113ef8);
      (*pcVar1)();
    }
    lVar3 = *(long *)(*param_2 + 0xa60);
    *(long **)(lVar3 + uVar2 * 8 + 0xd60) = param_2;
    *(int *)(lVar3 + 0xd5c) = *(int *)(lVar3 + 0xd5c) + 1;
    _printk(&DAT_00122f81,"ufsf_slave_configure",0x16f,(int)param_2[0x13],param_2,param_2[1]);
    queue_work_on(0x20,_system_wq,lVar3 + 0xda8);
  }
  return;
}



//------------------------------------------------------------
// ufsf_init @ 00113f00 size=176
// signature: undefined ufsf_init(void)
// callers: []
//------------------------------------------------------------

void ufsf_init(long param_1)

{
  int iVar1;
  undefined **ppuVar2;
  
  if (*(int *)(param_1 + 0x170) == 0x259) {
    ppuVar2 = &ufsf_6_1;
  }
  else {
    if (*(int *)(param_1 + 0x170) != 0x25e) {
      _printk(&DAT_00123528,"ufsf_init",0x243);
      goto LAB_00113f60;
    }
    ppuVar2 = &ufsf_6_6;
  }
  *(undefined ***)(param_1 + 0x178) = ppuVar2;
  if (*(char *)(param_1 + 0x118) == -1) {
    _printk(&DAT_00122fba,"ufsf_init",0x248);
  }
  else {
    iVar1 = ufshid_get_state(param_1);
    if (iVar1 == 0) {
      ufshid_init(param_1);
    }
  }
LAB_00113f60:
  *(undefined1 *)(param_1 + 0x50) = 1;
  return;
}



//------------------------------------------------------------
// ufsf_reset @ 00113fb4 size=56
// signature: undefined ufsf_reset(void)
// callers: []
//------------------------------------------------------------

void ufsf_reset(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = ufshid_get_state();
  if (iVar1 == -3) {
    ufshid_reset(param_1);
  }
  return;
}



//------------------------------------------------------------
// ufsf_remove @ 00113ff0 size=56
// signature: undefined ufsf_remove(void)
// callers: [ufs_qcom_remove]
//------------------------------------------------------------

void ufsf_remove(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = ufshid_get_state();
  if (iVar1 == 1) {
    ufshid_remove(param_1);
  }
  return;
}



//------------------------------------------------------------
// ufsf_set_init_state @ 0011402c size=64
// signature: undefined ufsf_set_init_state(void)
// callers: []
//------------------------------------------------------------

void ufsf_set_init_state(long param_1)

{
  *(undefined8 *)(param_1 + 0x140) = 0xfffffffe0;
  *(long *)(param_1 + 0x148) = param_1 + 0x148;
  *(long *)(param_1 + 0x150) = param_1 + 0x148;
  *(code **)(param_1 + 0x158) = ufsf_on_idle;
  ufshid_set_state(param_1,0);
  return;
}



//------------------------------------------------------------
// ufsf_on_idle @ 00114070 size=60
// signature: undefined ufsf_on_idle(void)
// callers: []
//------------------------------------------------------------

void ufsf_on_idle(long param_1)

{
  int iVar1;
  
  iVar1 = ufshid_get_state(param_1 + -0x140);
  if (iVar1 == 1) {
    ufshid_on_idle(param_1 + -0x140);
  }
  return;
}



//------------------------------------------------------------
// ufsf_set_init @ 001140b0 size=212
// signature: undefined ufsf_set_init(void)
// callers: [ufs_qcom_fixup_dev_quirks]
//------------------------------------------------------------

void ufsf_set_init(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x114184);
    (*pcVar1)();
  }
  lVar2 = *(long *)(param_1 + 0xb0);
  *(long *)(lVar2 + 0xd50) = param_1;
  *(undefined4 *)(lVar2 + 0xd5c) = 0;
  __mutex_init(lVar2 + 0xdd8,"&ufsf->device_check_lock",&ufsf_set_init___key);
  *(undefined8 *)(lVar2 + 0xda8) = 0xfffffffe0;
  *(long *)(lVar2 + 0xdb0) = lVar2 + 0xdb0;
  *(long *)(lVar2 + 0xdb8) = lVar2 + 0xdb0;
  *(code **)(lVar2 + 0xdc0) = ufsf_device_check_work_handler;
  *(undefined8 *)(lVar2 + 0xe08) = 0xfffffffe0;
  *(long *)(lVar2 + 0xe10) = lVar2 + 0xe10;
  *(long *)(lVar2 + 0xe18) = lVar2 + 0xe10;
  *(code **)(lVar2 + 0xe20) = ufsf_reset_wait_work_handler;
  *(undefined8 *)(lVar2 + 0xe38) = 0xfffffffe0;
  *(long *)(lVar2 + 0xe40) = lVar2 + 0xe40;
  *(long *)(lVar2 + 0xe48) = lVar2 + 0xe40;
  *(undefined8 *)(lVar2 + 0xe90) = 0xfffffffe0;
  *(code **)(lVar2 + 0xe50) = ufsf_resume_work_handler;
  *(long *)(lVar2 + 0xe98) = lVar2 + 0xe98;
  *(long *)(lVar2 + 0xea0) = lVar2 + 0xe98;
  *(code **)(lVar2 + 0xea8) = ufsf_on_idle;
  ufshid_set_state(lVar2 + 0xd50,0);
  return;
}



//------------------------------------------------------------
// ufsf_device_check_work_handler @ 00114188 size=436
// signature: undefined ufsf_device_check_work_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufsf_device_check_work_handler(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined **ppuVar5;
  undefined8 *puVar6;
  char *local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined1 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  mutex_lock(param_1 + 0x30);
  if (*(char *)(param_1 + -8) != '\0') goto LAB_001141c8;
  puVar6 = (undefined8 *)(param_1 + -0x58);
  ufsf_device_check(*puVar6);
  local_50 = 0;
  local_70 = _DAT_0012b7e2;
  uStack_68 = _DAT_0012b7ea;
  local_60 = _DAT_0012b7f2;
  uStack_58 = _DAT_0012b7fa;
  local_90 = _DAT_0012b7c2;
  uStack_88 = _DAT_0012b7ca;
  local_98 = (char *)&local_90;
  local_80 = _DAT_0012b7d2;
  uStack_78 = _DAT_0012b7da;
  pcVar4 = strsep(&local_98,".");
  iVar2 = simple_strtol(pcVar4,0,10);
  pcVar4 = strsep(&local_98,".");
  iVar3 = simple_strtol(pcVar4,0,10);
  _printk(&DAT_00120574,"ufsf_get_kernel_version",0xf0,iVar2,iVar3);
  iVar3 = iVar3 + iVar2 * 100;
  *(int *)(param_1 + 0x118) = iVar3;
  if (iVar3 == 0x259) {
    ppuVar5 = &ufsf_6_1;
LAB_001142d0:
    *(undefined ***)(param_1 + 0x120) = ppuVar5;
    if (*(char *)(param_1 + 0xc0) == -1) {
      _printk(&DAT_00122fba,"ufsf_init",0x248);
    }
    else {
      iVar3 = ufshid_get_state(puVar6);
      if (iVar3 == 0) {
        ufshid_init(puVar6);
      }
    }
  }
  else {
    if (iVar3 == 0x25e) {
      ppuVar5 = &ufsf_6_6;
      goto LAB_001142d0;
    }
    _printk(&DAT_00123528,"ufsf_init",0x243);
  }
  *(undefined1 *)(param_1 + -8) = 1;
LAB_001141c8:
  mutex_unlock(param_1 + 0x30);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufsf_reset_wait_work_handler @ 00114340 size=116
// signature: undefined ufsf_reset_wait_work_handler(void)
// callers: []
//------------------------------------------------------------

void ufsf_reset_wait_work_handler(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  
  plVar3 = (long *)(param_1 + -0xb8);
  lVar4 = *plVar3;
  lVar5 = *(long *)(lVar4 + 0x38);
  flush_work(lVar4 + 600);
  uVar2 = _raw_spin_lock_irqsave(*(undefined8 *)(lVar5 + 0x38));
  iVar1 = *(int *)(lVar4 + 0x1e8);
  _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar5 + 0x38),uVar2);
  if ((iVar1 == 1) && (iVar1 = ufshid_get_state(plVar3), iVar1 == -3)) {
    ufshid_reset(plVar3);
  }
  return;
}



//------------------------------------------------------------
// ufsf_resume_work_handler @ 001143b8 size=160
// signature: undefined ufsf_resume_work_handler(void)
// callers: []
//------------------------------------------------------------

void ufsf_resume_work_handler(long param_1)

{
  int iVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  
  plVar3 = (long *)(param_1 + -0xe8);
  lVar4 = *plVar3;
  iVar1 = *(int *)(lVar4 + 0x54);
  down(lVar4 + 0x238);
  __pm_runtime_resume(*(long *)(lVar4 + 0x48) + 0x1d8,4);
  if (((*(int *)(lVar4 + 0x50) == 1) && (*(int *)(lVar4 + 0x54) == 1)) &&
     (iVar2 = ufshid_get_state(plVar3), iVar2 == 2)) {
    ufshid_resume(plVar3,iVar1 == 0);
  }
  __pm_runtime_idle(*(long *)(lVar4 + 0x48) + 0x1d8,5);
  up(lVar4 + 0x238);
  return;
}



//------------------------------------------------------------
// ufsf_suspend @ 0011445c size=92
// signature: undefined ufsf_suspend(void)
// callers: [ufs_qcom_suspend]
//------------------------------------------------------------

undefined8 ufsf_suspend(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  iVar1 = work_busy(param_1 + 0xb8);
  if (iVar1 == 0) {
    iVar1 = ufshid_get_state(param_1);
    if (iVar1 == 1) {
      ufshid_suspend(param_1,param_2 & 1);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}



//------------------------------------------------------------
// ufsf_resume @ 001144bc size=64
// signature: undefined ufsf_resume(void)
// callers: []
//------------------------------------------------------------

void ufsf_resume(undefined8 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = ufshid_get_state();
  if (iVar1 == 2) {
    ufshid_resume(param_1,param_2 & 1);
  }
  return;
}



//------------------------------------------------------------
// ufsf_event_notify @ 00114500 size=104
// signature: undefined ufsf_event_notify(void)
// callers: [ufs_qcom_event_notify]
//------------------------------------------------------------

void ufsf_event_notify(long param_1,int param_2,int param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  if ((param_2 == 0xc) && (param_3 == 0)) {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x114524);
      (*pcVar2)();
    }
  }
  else if (param_2 == 10) {
    if (param_1 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x114568);
      (*pcVar2)();
    }
    lVar1 = *(long *)(param_1 + 0xb0) + 0xd50;
    iVar3 = ufshid_get_state(lVar1);
    if (iVar3 == 2) {
      ufshid_resume(lVar1,1);
    }
  }
  return;
}



//------------------------------------------------------------
// ufsf_vendor_exception_event_handler @ 0011456c size=32
// signature: undefined ufsf_vendor_exception_event_handler(void)
// callers: []
//------------------------------------------------------------

void ufsf_vendor_exception_event_handler(long param_1)

{
  ufsf_exception_event_handler(param_1 + -0x288);
  return;
}



//------------------------------------------------------------
// ufs_host_exception_event_hook @ 00114590 size=36
// signature: undefined ufs_host_exception_event_hook(void)
// callers: [ufs_qcom_probe]
//------------------------------------------------------------

void ufs_host_exception_event_hook(long param_1)

{
  *(undefined8 *)(param_1 + 0x288) = 0xfffffffe0;
  *(long *)(param_1 + 0x290) = param_1 + 0x290;
  *(long *)(param_1 + 0x298) = param_1 + 0x290;
  *(code **)(param_1 + 0x2a0) = ufsf_vendor_exception_event_handler;
  return;
}



//------------------------------------------------------------
// ufsf_query_attr_retry @ 001145b8 size=52
// signature: undefined ufsf_query_attr_retry(void)
// callers: []
//------------------------------------------------------------

void ufsf_query_attr_retry
               (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  code *pcVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1145ec);
    (*pcVar1)();
  }
  ufshcd_query_attr_retry
            (param_1,3,param_3,param_4,*(undefined1 *)(*(long *)(param_1 + 0xb0) + 0xe68),param_5);
  return;
}



//------------------------------------------------------------
// ufsf_query_flag_retry @ 001145f0 size=220
// signature: undefined ufsf_query_flag_retry(void)
// callers: []
//------------------------------------------------------------

int ufsf_query_flag_retry
              (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined8 param_5)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1146cc);
    (*pcVar2)();
  }
  uVar1 = *(undefined1 *)(*(long *)(param_1 + 0xb0) + 0xe68);
  iVar3 = ufsf_query_flag();
  if ((iVar3 == 0) ||
     (iVar3 = ufsf_query_flag(param_1,param_2,param_3,param_4,uVar1,param_5), iVar3 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = ufsf_query_flag(param_1,param_2,param_3,param_4,uVar1,param_5);
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x40),
               "%s: query flag, opcode %d, idn %d, failed with error %d after %d retries\n",
               "ufsf_query_flag_retry",param_2,param_3,iVar3,3);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// __traceiter_ufsfeature_command @ 001146d0 size=220
// signature: undefined __traceiter_ufsfeature_command(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_ufsfeature_command
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined8 param_9,undefined1 param_10,undefined1 param_11)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_0011f700;
  plVar2 = DAT_0011f700;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x2c2de344) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10,param_11);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114778);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_ufsfeature_upiu @ 001147b0 size=148
// signature: undefined __traceiter_ufsfeature_upiu(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_ufsfeature_upiu
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_0011f748;
  plVar2 = _DAT_0011f748;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x7d3b5ad6) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11481c);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_ufsfeature_command @ 00114848 size=324
// signature: undefined trace_event_raw_event_ufsfeature_command(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufsfeature_command
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined8 param_9,
               undefined1 param_10,undefined1 param_11)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_98,param_1,(long)iVar1 + 0x30);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x2e;
      strcpy((char *)(lVar3 + 0x2e),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_8;
      *(undefined8 *)(lVar3 + 0x20) = param_9;
      *(undefined4 *)(lVar3 + 0x28) = param_7;
      *(undefined1 *)(lVar3 + 0x2c) = param_10;
      *(undefined1 *)(lVar3 + 0x2d) = param_11;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ufsfeature_command @ 00114990 size=408
// signature: undefined perf_trace_ufsfeature_command(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufsfeature_command
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined8 param_9,
               undefined1 param_10,byte param_11)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_90 [12];
  uint local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_80 = param_3;
  local_7c = param_4;
  local_78 = param_5;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x3cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      local_84 = (uint)param_11;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x1002e;
      strcpy((char *)(lVar5 + 0x2e),__s);
      *(undefined4 *)(lVar5 + 0xc) = local_80;
      *(undefined4 *)(lVar5 + 0x10) = local_7c;
      *(undefined4 *)(lVar5 + 0x1c) = param_8;
      *(undefined4 *)(lVar5 + 0x14) = local_78;
      *(undefined4 *)(lVar5 + 0x18) = param_6;
      *(undefined8 *)(lVar5 + 0x20) = param_9;
      *(undefined4 *)(lVar5 + 0x28) = param_7;
      *(undefined1 *)(lVar5 + 0x2c) = param_10;
      *(char *)(lVar5 + 0x2d) = (char)local_84;
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
// trace_event_raw_event_ufsfeature_upiu @ 00114b2c size=300
// signature: undefined trace_event_raw_event_ufsfeature_upiu(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_ufsfeature_upiu
               (long param_1,char *param_2,undefined4 param_3,undefined8 *param_4,
               undefined8 *param_5,undefined4 param_6)

{
  int iVar1;
  char *__s;
  undefined8 uVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar3 = strlen(__s);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x30);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0x30;
      strcpy((char *)(lVar4 + 0x30),__s);
      *(undefined4 *)(lVar4 + 0xc) = param_3;
      uVar6 = *param_4;
      *(undefined4 *)(lVar4 + 0x18) = *(undefined4 *)(param_4 + 1);
      *(undefined8 *)(lVar4 + 0x10) = uVar6;
      uVar6 = *param_5;
      uVar2 = param_5[1];
      *(undefined4 *)(lVar4 + 0x2c) = param_6;
      *(undefined8 *)(lVar4 + 0x1c) = uVar6;
      *(undefined8 *)(lVar4 + 0x24) = uVar2;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_ufsfeature_upiu @ 00114c5c size=380
// signature: undefined perf_trace_ufsfeature_upiu(void)
// callers: []
//------------------------------------------------------------

void perf_trace_ufsfeature_upiu
               (long param_1,char *param_2,undefined4 param_3,undefined8 *param_4,
               undefined8 *param_5,undefined4 param_6)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  undefined8 uVar6;
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
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x3cU & 0xfffffff8) - 4;
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
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10030;
      strcpy((char *)(lVar5 + 0x30),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      uVar6 = *param_4;
      *(undefined4 *)(lVar5 + 0x18) = *(undefined4 *)(param_4 + 1);
      *(undefined8 *)(lVar5 + 0x10) = uVar6;
      uVar6 = param_5[1];
      *(undefined8 *)(lVar5 + 0x1c) = *param_5;
      *(undefined8 *)(lVar5 + 0x24) = uVar6;
      *(undefined4 *)(lVar5 + 0x2c) = local_78;
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
// __bpf_trace_ufsfeature_command @ 00114ddc size=80
// signature: undefined __bpf_trace_ufsfeature_command(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufsfeature_command
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined8 param_9,undefined1 param_10,undefined1 param_11)

{
  bpf_trace_run10(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                  param_11);
  return;
}



//------------------------------------------------------------
// __bpf_trace_ufsfeature_upiu @ 00114e30 size=36
// signature: undefined __bpf_trace_ufsfeature_upiu(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_ufsfeature_upiu
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
               undefined8 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// ufsf_wait_for_register @ 00114e58 size=196
// signature: undefined ufsf_wait_for_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
ufsf_wait_for_register
          (long *param_1,ulong param_2,uint param_3,uint param_4,long param_5,undefined4 param_6)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  undefined4 uVar4;
  
  lVar1 = _jiffies;
  lVar3 = __msecs_to_jiffies(param_6);
  do {
    uVar2 = readl(*param_1 + (param_2 & 0xffffffff));
    if ((uVar2 & param_3) == (param_4 & param_3)) {
      return 0;
    }
    usleep_range_state(param_5,param_5 + 0x32,2);
  } while (-1 < (lVar3 + lVar1) - _jiffies);
  uVar2 = readl(*param_1 + (param_2 & 0xffffffff));
  uVar4 = 0;
  if ((uVar2 & param_3) != (param_4 & param_3)) {
    uVar4 = 0xffffff92;
  }
  return uVar4;
}



//------------------------------------------------------------
// readl @ 00114f1c size=140
// signature: undefined readl(void)
// callers: [ufsf_clear_cmd, ufsf_mcq_sq_cleanup, ufsf_issue_tm_cmd, ufsf_wait_for_doorbell_clr, ufsf_wait_for_register]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x114f74,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// ufsf_issue_tm_cmd @ 00114fac size=1108
// signature: undefined ufsf_issue_tm_cmd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong ufsf_issue_tm_cmd(long *param_1,uint param_2,uint param_3,uint param_4,undefined1 *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  bool bVar7;
  undefined8 *puVar8;
  code *pcVar9;
  long lVar10;
  undefined1 uVar12;
  long lVar11;
  ulong uVar13;
  uint uVar14;
  ulong uVar15;
  ulong uVar16;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 *****local_78;
  undefined8 *****pppppuStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  local_78 = &local_78;
  lVar11 = param_1[7];
  local_88 = 0;
  uStack_80 = 0;
  pppppuStack_70 = local_78;
  uVar5 = blk_mq_alloc_request(param_1[0x33],0x23,0);
  if (uVar5 < 0xfffffffffffff001) {
    uVar1 = (param_2 & 0xff00ff00) >> 8 | (param_2 & 0xff00ff) << 8;
    uVar14 = uVar1 >> 0x10 | uVar1 << 0x10;
    *(undefined8 **)(uVar5 + 0x130) = &local_88;
    ufshcd_hold(param_1,0);
    uVar6 = _raw_spin_lock_irqsave(*(undefined8 *)(lVar11 + 0x38));
    uVar1 = *(uint *)(uVar5 + 0x20);
    if ((int)uVar1 < 0) {
      bVar7 = false;
    }
    else {
      bVar7 = (int)uVar1 < *(int *)((long)param_1 + 0x94);
    }
    uVar4 = (param_3 & 0xff00ff00) >> 8 | (param_3 & 0xff00ff) << 8;
    if ((!bVar7) && ((__ufsf_issue_tm_cmd___already_done & 1) == 0)) {
      __ufsf_issue_tm_cmd___already_done = 1;
      __warn_printk("Invalid tag %d\n",uVar1);
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x800,0x115400);
      (*pcVar9)();
    }
    *(ulong *)(param_1[0x34] + (long)(int)uVar1 * 8) = uVar5;
    puVar8 = (undefined8 *)(param_1[3] + (long)(int)uVar1 * 0x50);
    uVar2 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
    *puVar8 = 0x1000000;
    puVar8[1] = 0xf;
    *(uint *)(puVar8 + 2) = uVar14 >> 8 | uVar2 >> 0x10 | uVar2 << 0x10 | 4;
    *(uint *)((long)puVar8 + 0x14) = (param_4 & 0xff) << 8;
    *(undefined4 *)(puVar8 + 3) = 0;
    *(uint *)((long)puVar8 + 0x1c) = uVar14;
    *(uint *)(puVar8 + 4) = uVar4 >> 0x10 | uVar4 << 0x10;
    *(undefined8 *)((long)puVar8 + 0x24) = 0;
    *(undefined8 *)((long)puVar8 + 0x2c) = 0;
    *(undefined8 *)((long)puVar8 + 0x34) = 0;
    *(undefined8 *)((long)puVar8 + 0x3c) = 0;
    *(undefined8 *)((long)puVar8 + 0x44) = 0;
    *(undefined4 *)((long)puVar8 + 0x4c) = 0;
    if ((param_1[0x14] != 0) && (pcVar9 = *(code **)(param_1[0x14] + 0x50), pcVar9 != (code *)0x0))
    {
      if (*(int *)(pcVar9 + -4) != -0x316bd175) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x115128);
        (*pcVar9)();
      }
      (*pcVar9)(param_1,uVar1,param_4);
    }
    uVar16 = (ulong)(long)(int)uVar1 >> 6;
    uVar14 = 1 << (ulong)(uVar1 & 0x1f);
    uVar15 = 1L << ((long)(int)uVar1 & 0x3fU);
    lVar10 = *param_1;
    param_1[uVar16 + 0xe] = param_1[uVar16 + 0xe] | uVar15;
    writel(uVar14,lVar10 + 0x78);
    DataSynchronizationBarrier(3,2,0);
    _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar11 + 0x38),uVar6);
    ufsf_add_tm_upiu_trace(param_1,uVar1,6);
    iVar3 = wait_for_completion_io_timeout(&local_88,0x19);
    if (iVar3 == 0) {
      ufsf_add_tm_upiu_trace(param_1,uVar1,8);
      _dev_err(param_1[8],"%s: task management cmd 0x%.2x timed-out\n","__ufsf_issue_tm_cmd",
               param_4 & 0xff);
      if ((param_1[uVar16 + 0xe] & uVar15) == 0) {
        uVar12 = 0;
        uVar13 = 0xffffff92;
        uVar14 = 0xf;
      }
      else {
        uVar6 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
        writel((*(uint *)((long)param_1 + 0xcc) >> 6 & 1) - 1 ^ uVar14,*param_1 + 0x7c);
        _raw_spin_unlock_irqrestore(*(undefined8 *)(param_1[7] + 0x38),uVar6);
        lVar11 = _jiffies + 0xfa;
        do {
          uVar4 = readl(*param_1 + 0x78);
          if ((uVar4 & uVar14) == 0) goto LAB_00115354;
          usleep_range_state(1000,0x41a,2);
        } while (-1 < lVar11 - _jiffies);
        uVar4 = readl(*param_1 + 0x78);
        if ((uVar4 & uVar14) != 0) {
          _dev_err(param_1[8],"Clearing task management function with tag %d %s\n",uVar1,"failed");
          uVar6 = dev_driver_string(param_1[8]);
          lVar11 = ((long *)param_1[8])[0xe];
          if (lVar11 == 0) {
            lVar11 = *(long *)param_1[8];
          }
          __warn_printk("%s %s: %s: unable to clear tm cmd (slot %d) after timeout\n",uVar6,lVar11,
                        "__ufsf_issue_tm_cmd",uVar1);
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x800,0x1153e0);
          (*pcVar9)();
        }
LAB_00115354:
        _dev_err(param_1[8],"Clearing task management function with tag %d %s\n",uVar1,"succeeded");
        uVar12 = 0;
        uVar13 = 0xffffff92;
        uVar14 = 0xf;
      }
    }
    else {
      lVar11 = param_1[3] + (long)(int)uVar1 * 0x50;
      uVar14 = *(uint *)(lVar11 + 8);
      uVar12 = (undefined1)((uint)*(undefined4 *)(lVar11 + 0x3c) >> 0x18);
      ufsf_add_tm_upiu_trace(param_1,uVar1,7);
      uVar13 = 0;
    }
    uVar6 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
    *(undefined8 *)(param_1[0x34] + (long)*(int *)(uVar5 + 0x20) * 8) = 0;
    lVar11 = param_1[7];
    param_1[uVar16 + 0xe] = param_1[uVar16 + 0xe] & (uVar15 ^ 0xffffffffffffffff);
    _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar11 + 0x38),uVar6);
    ufshcd_release(param_1);
    blk_mq_free_request(uVar5);
    iVar3 = (int)uVar13;
  }
  else {
    uVar12 = 0;
    uVar14 = 0xf;
    uVar13 = uVar5 & 0xffffffff;
    iVar3 = (int)uVar5;
  }
  if (iVar3 != -0x6e) {
    if ((uVar14 & 0xf) == 0) {
      if (param_5 != (undefined1 *)0x0) {
        *param_5 = uVar12;
      }
    }
    else {
      _dev_err(param_1[8],"%s: failed, ocs = 0x%x\n","ufsf_issue_tm_cmd",uVar14 & 0xf);
    }
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13;
}



//------------------------------------------------------------
// ufsf_mcq_req_to_hwq @ 00115410 size=60
// signature: undefined ufsf_mcq_req_to_hwq(void)
// callers: []
//------------------------------------------------------------

long ufsf_mcq_req_to_hwq(long param_1,undefined8 param_2)

{
  ulong uVar1;
  
  uVar1 = blk_mq_unique_tag(param_2);
  return *(long *)(param_1 + 0x1460) + (uVar1 >> 0x10 & 0xffff) * 0x90;
}



//------------------------------------------------------------
// ufsf_mcq_sq_cleanup @ 00115450 size=752
// signature: undefined ufsf_mcq_sq_cleanup(void)
// callers: [ufsf_clear_cmd]
//------------------------------------------------------------

undefined4 ufsf_mcq_sq_cleanup(long param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  
  if ((*(byte *)(param_1 + 0xce) >> 5 & 1) != 0) {
    return 0xffffff92;
  }
  lVar13 = *(long *)(param_1 + 0x68);
  if (*(int *)(param_1 + 0x8c) - 1U == param_2) {
    lVar12 = *(long *)(param_1 + 0x1468);
  }
  else {
    lVar12 = *(long *)(lVar13 + (long)(int)param_2 * 0x98 + 0x40);
    if (lVar12 == 0) {
      return 0xffffffea;
    }
    uVar6 = blk_mq_unique_tag(lVar12 + -0x140);
    lVar12 = *(long *)(param_1 + 0x1460) + (uVar6 >> 0x10 & 0xffff) * 0x90;
  }
  iVar2 = *(int *)(lVar12 + 0x44);
  mutex_lock(lVar12 + 0x60);
  if ((*(byte *)(param_1 + 0xce) >> 5 & 1) == 0) {
    iVar3 = *(int *)(lVar12 + 0x44);
    writel(1,*(long *)(param_1 + 0x1480) + *(long *)(param_1 + 0x1478) * (long)iVar3 + 8);
    lVar11 = *(long *)(param_1 + 0x1480) + *(long *)(param_1 + 0x1478) * (long)iVar3 + 0x10;
    lVar5 = ktime_get();
    uVar6 = readl(lVar11);
    if ((uVar6 & 1) == 0) {
      do {
        lVar7 = ktime_get();
        if (lVar5 + 500000000 < lVar7) {
          uVar6 = readl(lVar11);
          break;
        }
        usleep_range_state(6,0x14,2);
        Yield();
        uVar6 = readl(lVar11);
      } while ((uVar6 & 1) == 0);
    }
    if ((uVar6 & 1) == 0) {
      uVar8 = *(undefined8 *)(param_1 + 0x40);
      pcVar9 = "ufsf_mcq_sq_stop";
LAB_001156c8:
      uVar10 = 0xffffff92;
      _dev_err(uVar8,"%s: failed. hwq-id=%d, err=%d\n",pcVar9,iVar3,0xffffff92);
      goto LAB_00115714;
    }
    lVar11 = *(long *)(param_1 + 0x1480) + *(long *)(param_1 + 0x1478) * (long)iVar2;
    writel(param_2 | (uint)*(byte *)(lVar13 + (long)(int)param_2 * 0x98 + 0x54) << 8,lVar11 + 0xc);
    writel(2,lVar11 + 8);
    lVar11 = lVar11 + 0x10;
    lVar13 = ktime_get();
    uVar4 = readl(lVar11);
    if ((uVar4 >> 1 & 1) == 0) {
      do {
        lVar5 = ktime_get();
        if (lVar13 + 500000000 < lVar5) {
          uVar4 = readl(lVar11);
          break;
        }
        usleep_range_state(6,0x14,2);
        Yield();
        uVar4 = readl(lVar11);
      } while ((uVar4 >> 1 & 1) == 0);
    }
    uVar10 = 0xffffff92;
    if ((uVar4 & 2) != 0) {
      uVar10 = 0;
    }
    if ((uVar4 >> 1 & 1) == 0) {
      uVar8 = *(undefined8 *)(param_1 + 0x40);
      uVar4 = readl(lVar11);
      _dev_err(uVar8,"%s: failed. hwq=%d, tag=%d err=%ld\n","ufsf_mcq_sq_cleanup",iVar2,param_2,
               uVar4 >> 4 & 0xf);
      bVar1 = *(byte *)(param_1 + 0xce);
    }
    else {
      bVar1 = *(byte *)(param_1 + 0xce);
    }
    if ((bVar1 >> 5 & 1) == 0) {
      iVar3 = *(int *)(lVar12 + 0x44);
      writel(0,*(long *)(param_1 + 0x1480) + *(long *)(param_1 + 0x1478) * (long)iVar3 + 8);
      lVar13 = *(long *)(param_1 + 0x1480) + *(long *)(param_1 + 0x1478) * (long)iVar3 + 0x10;
      lVar11 = ktime_get();
      uVar6 = readl(lVar13);
      if ((uVar6 & 1) != 0) {
        do {
          lVar5 = ktime_get();
          if (lVar11 + 500000000 < lVar5) {
            uVar6 = readl(lVar13);
            if ((uVar6 & 1) != 0) {
              uVar8 = *(undefined8 *)(param_1 + 0x40);
              pcVar9 = "ufsf_mcq_sq_start";
              goto LAB_001156c8;
            }
            break;
          }
          usleep_range_state(6,0x14,2);
          Yield();
          uVar6 = readl(lVar13);
        } while ((uVar6 & 1) != 0);
      }
      goto LAB_00115714;
    }
  }
  uVar10 = 0xffffff92;
LAB_00115714:
  mutex_unlock(lVar12 + 0x60);
  return uVar10;
}



//------------------------------------------------------------
// writel @ 00115740 size=136
// signature: undefined writel(void)
// callers: [ufsf_clear_cmd, ufsf_mcq_sq_cleanup, ufsf_issue_tm_cmd, ufsf_query_flag]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x115758,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x115798,uVar1);
  return;
}



//------------------------------------------------------------
// ufsf_get_tr_ocs @ 001157cc size=32
// signature: undefined ufsf_get_tr_ocs(void)
// callers: [ufsf_compl_command]
//------------------------------------------------------------

uint ufsf_get_tr_ocs(long *param_1,long param_2)

{
  uint *puVar1;
  
  if (param_2 == 0) {
    puVar1 = (uint *)(*param_1 + 8);
  }
  else {
    puVar1 = (uint *)(param_2 + 0x10);
  }
  return *puVar1 & 0xf;
}



//------------------------------------------------------------
// ufsf_query_flag @ 001157f0 size=2212
// signature: undefined ufsf_query_flag(void)
// callers: [ufsf_query_flag_retry]
//------------------------------------------------------------

uint ufsf_query_flag(long *param_1,int param_2,undefined4 param_3,undefined1 param_4,
                    undefined1 param_5,byte *param_6)

{
  long *plVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  uint uVar4;
  char cVar5;
  ushort uVar6;
  uint uVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined1 uVar10;
  byte *pbVar11;
  long lVar12;
  code *pcVar13;
  uint *puVar14;
  undefined8 *puVar15;
  ulong uVar16;
  int iVar17;
  ulong uVar18;
  uint uVar19;
  uint uVar20;
  undefined8 uVar21;
  long lVar22;
  long *plVar23;
  long lVar24;
  long lVar25;
  uint *puVar26;
  long lVar27;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 *****local_80;
  undefined8 *****pppppuStack_78;
  long local_70;
  
  lVar22 = sp_el0;
  local_70 = *(long *)(lVar22 + 0x638);
  if (param_1 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar13 = (code *)SoftwareBreakpoint(0x800,0x116098);
    (*pcVar13)();
  }
  ufshcd_hold(param_1,0);
  mutex_lock();
  param_1[0x138] = 0;
  param_1[0x13a] = 0;
  param_1[0x139] = 0;
  param_1[0x13c] = 0;
  param_1[0x13d] = 0;
  param_1[0x13e] = 0;
  *(char *)((long)param_1 + 0x9c4) = (char)param_2;
  *(char *)((long)param_1 + 0x9c5) = (char)param_3;
  *(undefined1 *)((long)param_1 + 0x9c6) = param_4;
  *(undefined1 *)((long)param_1 + 0x9c7) = param_5;
  if (param_2 - 6U < 3) {
    *(undefined1 *)(param_1 + 0x138) = 0x81;
  }
  else {
    if (param_2 != 5) {
      _dev_err(param_1[8],"%s: Expected query flag opcode but got = %d\n","ufsf_query_flag",param_2)
      ;
      uVar7 = 0xffffffea;
      goto LAB_00115e5c;
    }
    *(undefined1 *)(param_1 + 0x138) = 1;
    if (param_6 == (byte *)0x0) {
      _dev_err(param_1[8],"%s: Invalid argument for read request\n","ufsf_query_flag");
      uVar7 = 0xffffffea;
      goto LAB_00115e5c;
    }
  }
  local_80 = &local_80;
  uVar4 = *(uint *)(param_1 + 0x13);
  local_90 = 0;
  uStack_88 = 0;
  pppppuStack_78 = local_80;
  down_read();
  lVar22 = param_1[0xd];
  plVar23 = (long *)(lVar22 + (ulong)uVar4 * 0x98);
  if (plVar23[8] != 0) {
                    /* WARNING: Does not return */
    pcVar13 = (code *)SoftwareBreakpoint(0x800,0x115f54);
    (*pcVar13)();
  }
  plVar23[8] = 0;
  lVar25 = lVar22 + (ulong)uVar4 * 0x98;
  puVar26 = (uint *)(lVar25 + 0x50);
  *puVar26 = uVar4;
  *(undefined4 *)(lVar25 + 0x78) = 0xffffffff;
  pbVar11 = (byte *)(lVar25 + 0x54);
  pbVar11[0] = 0;
  pbVar11[1] = 1;
  *(undefined4 *)(param_1 + 0x130) = 1;
  iVar17 = 1;
  if (*(uint *)((long)param_1 + 0x9c) < 0x111) {
    iVar17 = 2;
  }
  puVar14 = (uint *)*plVar23;
  *(int *)(lVar25 + 0x4c) = iVar17;
  uVar7 = iVar17 << 0x1c;
  if (*(char *)(lVar25 + 0x55) != '\0') {
    uVar7 = iVar17 << 0x1c | 0x1000000;
  }
  if ((int)*(uint *)(lVar25 + 0x78) < 0) {
    uVar19 = 0;
    uVar20 = 0;
  }
  else {
    uVar7 = *(uint *)(lVar25 + 0x78) | uVar7 | 0x800000;
    lVar25 = lVar22 + (ulong)uVar4 * 0x98;
    uVar19 = *(uint *)(lVar25 + 0x80);
    uVar20 = *(uint *)(lVar25 + 0x84);
  }
  *puVar14 = uVar7;
  puVar14[1] = uVar19;
  *(undefined2 *)(puVar14 + 7) = 0;
  puVar14[2] = 0xf;
  puVar14[3] = uVar20;
  if ((int)param_1[0x130] == 0) {
    puVar14 = *(uint **)(lVar22 + (ulong)uVar4 * 0x98 + 8);
    puVar14[4] = 0;
    puVar14[5] = 0;
    puVar14[6] = 0;
    puVar14[7] = 0;
    puVar14[0] = 0;
    puVar14[1] = 0;
    puVar14[2] = 0;
    puVar14[3] = 0;
    uVar7 = *puVar26;
    puVar14[1] = 0;
    puVar14[2] = 0;
    uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
    *puVar14 = uVar7 >> 0x10 | uVar7 << 0x10;
LAB_00115a44:
    lVar25 = lVar22 + (ulong)uVar4 * 0x98;
    puVar15 = *(undefined8 **)(lVar25 + 0x10);
    *(undefined4 *)(puVar15 + 6) = 0;
    puVar15[4] = 0;
    puVar15[5] = 0;
    puVar15[2] = 0;
    puVar15[3] = 0;
    *puVar15 = 0;
    puVar15[1] = 0;
    param_1[0x137] = (long)&local_90;
    ufsf_add_query_upiu_trace(param_1,3,*(undefined8 *)(lVar25 + 8));
    lVar12 = param_1[0xd];
    puVar15 = (undefined8 *)(lVar12 + (ulong)uVar4 * 0x98);
    lVar24 = param_1[0x28d];
    lVar25 = ktime_get();
    puVar15[0xb] = lVar25;
    uVar8 = sched_clock();
    puVar15[0xc] = uVar8;
    puVar15[0xd] = 0;
    puVar15[0xe] = 0;
    lVar25 = param_1[0xd];
    lVar27 = *(long *)(lVar25 + (ulong)uVar4 * 0x98 + 0x40);
    if (lVar27 != 0) {
      lVar25 = lVar27 + -0x140;
    }
    lVar25 = ktime_get(lVar25);
    if ((*(byte *)(param_1 + 0x17e) >> 2 & 1) != 0) {
      uVar8 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
      lVar27 = param_1[0x180];
      *(int *)(param_1 + 0x180) = (int)lVar27 + 1;
      if ((*(char *)((long)param_1 + 0xccc) != '\0') && ((int)param_1[0xc] == 0)) {
        if ((int)lVar27 == 0) {
          queue_work_on(0x20,param_1[0x18c],param_1 + 0x193);
        }
        if (param_1[0x182] == 0) {
          param_1[0x182] = lVar25;
          param_1[0x181] = 0;
        }
        else if (*(char *)((long)param_1 + 0xccf) != '\0') goto LAB_00115b54;
        param_1[0x183] = lVar25;
        *(undefined1 *)((long)param_1 + 0xccf) = 1;
      }
LAB_00115b54:
      _raw_spin_unlock_irqrestore(*(undefined8 *)(param_1[7] + 0x38),uVar8);
    }
    if (((((puVar15 != (undefined8 *)0x0) && ((char)param_1[0x242] != '\0')) &&
         (lVar25 = *(long *)(lVar12 + (ulong)uVar4 * 0x98 + 0x40), lVar25 != 0)) &&
        ((param_1[0x231] == 0 || (param_1[0x231] == (ulong)*(uint *)(lVar25 + 0x108))))) &&
       (param_1[0x241] < (long)puVar15[0xb])) {
      ufsf_start_monitor(param_1,puVar15);
    }
    if (*(char *)((long)param_1 + 0x13ac) == '\0') {
      uVar8 = _raw_spin_lock_irqsave(param_1 + 0xf);
      if ((param_1[0x14] != 0) &&
         (pcVar13 = *(code **)(param_1[0x14] + 0x48), pcVar13 != (code *)0x0)) {
        lVar25 = lVar12 + (ulong)uVar4 * 0x98;
        if (*(int *)(pcVar13 + -4) != -0x2f3bff34) {
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x115c6c);
          (*pcVar13)();
        }
        (*pcVar13)(param_1,*(undefined4 *)(lVar25 + 0x50),*(long *)(lVar25 + 0x40) != 0);
      }
      lVar12 = lVar12 + (ulong)uVar4 * 0x98;
      uVar16 = (ulong)*(int *)(lVar12 + 0x50);
      uVar18 = uVar16 >> 6;
      param_1[uVar18 + 0x10] = 1L << (uVar16 & 0x3f) | param_1[uVar18 + 0x10];
      writel(1 << (ulong)(*(uint *)(lVar12 + 0x50) & 0x1f),*param_1 + 0x58);
      _raw_spin_unlock_irqrestore(param_1 + 0xf,uVar8);
    }
    else {
      puVar15 = (undefined8 *)*puVar15;
      _raw_spin_lock(lVar24 + 0x4c);
      uVar21 = puVar15[1];
      puVar2 = (undefined8 *)(*(long *)(lVar24 + 0x20) + (ulong)*(uint *)(lVar24 + 0x48));
      uVar8 = puVar15[2];
      uVar3 = puVar15[3];
      *puVar2 = *puVar15;
      puVar2[1] = uVar21;
      puVar2[2] = uVar8;
      puVar2[3] = uVar3;
      iVar17 = 0;
      if (*(int *)(lVar24 + 0x48) + 1 != *(int *)(lVar24 + 0x40)) {
        iVar17 = *(int *)(lVar24 + 0x48) + 1;
      }
      *(int *)(lVar24 + 0x48) = iVar17;
      writel(iVar17 << 5,*(undefined8 *)(lVar24 + 8));
      _raw_spin_unlock(lVar24 + 0x4c);
    }
    lVar25 = wait_for_completion_timeout(param_1[0x137],0x177);
    if (lVar25 == 0) {
      plVar1 = param_1 + 0xf;
      do {
        cVar5 = *(char *)((long)param_1 + 0x13ac);
        uVar7 = ufsf_clear_cmd(param_1,*puVar26);
        if (cVar5 != '\0') {
          param_1[0x137] = 0;
          goto LAB_00116034;
        }
        if (uVar7 == 0) {
          uVar8 = _raw_spin_lock_irqsave(plVar1);
          if ((*(ulong *)((long)param_1 +
                         ((ulong)(long)(int)*puVar26 >> 3 & 0x1ffffffffffffff8) + 0x80) >>
               ((long)(int)*puVar26 & 0x3fU) & 1) != 0) {
            param_1[0x137] = 0;
            uVar16 = (ulong)(long)(int)*puVar26 >> 3 & 0x1ffffffffffffff8;
            *(ulong *)((long)param_1 + uVar16 + 0x80) =
                 *(ulong *)((long)param_1 + uVar16 + 0x80) &
                 (1L << ((long)(int)*puVar26 & 0x3fU) ^ 0xffffffffffffffffU);
            _raw_spin_unlock_irqrestore(plVar1,uVar8);
            uVar8 = 5;
            uVar7 = 0xfffffff5;
            goto LAB_00115d60;
          }
        }
        else {
          _dev_err(param_1[8],"%s: failed to clear tag %d\n","ufsf_wait_for_dev_cmd",*puVar26);
          uVar8 = _raw_spin_lock_irqsave(plVar1);
          if ((*(ulong *)((long)param_1 +
                         ((ulong)(long)(int)*puVar26 >> 3 & 0x1ffffffffffffff8) + 0x80) >>
               ((long)(int)*puVar26 & 0x3fU) & 1) != 0) {
            param_1[0x137] = 0;
            _raw_spin_unlock_irqrestore(plVar1,uVar8);
            uVar8 = 5;
            uVar7 = 0xffffff92;
            goto LAB_00115d60;
          }
        }
        _raw_spin_unlock_irqrestore(plVar1,uVar8);
        lVar25 = wait_for_completion_timeout(param_1[0x137],1);
      } while (lVar25 == 0);
    }
    param_1[0x137] = 0;
    uVar7 = *(uint *)(*plVar23 + 8) & 0xf;
    if (uVar7 == 0) {
      param_1[0x5c] = 0;
      plVar23 = (long *)(lVar22 + (ulong)uVar4 * 0x98 + 0x10);
      uVar10 = *(undefined1 *)*plVar23;
      switch(uVar10) {
      case 0x20:
        if ((int)param_1[0x130] == 0) goto LAB_00115d58;
        lVar25 = param_1[8];
        pcVar9 = "%s: unexpected response %x\n";
        uVar10 = 0x20;
        break;
      case 0x21:
        if ((int)param_1[0x130] == 2) goto LAB_00115d58;
        lVar25 = param_1[8];
        pcVar9 = "%s: unexpected response %x\n";
        uVar10 = 0x21;
        break;
      default:
        lVar25 = param_1[8];
        pcVar9 = "%s: Invalid device management cmd response: %x\n";
        break;
      case 0x36:
        uVar6 = *(ushort *)((undefined1 *)*plVar23 + 6);
        uVar7 = uVar6 & 0xff;
        *(char *)(param_1 + 0x13c) = (char)uVar6;
        if (0xff < ((uint)(uVar6 >> 8) | (uVar6 & 0xff00ff) << 8)) {
LAB_00116034:
          if (uVar7 != 0) goto LAB_00115ce4;
LAB_00115d58:
          uVar7 = 0;
          uVar8 = 4;
          goto LAB_00115d60;
        }
        lVar25 = *plVar23;
        uVar21 = *(undefined8 *)(lVar25 + 0x14);
        uVar8 = *(undefined8 *)(lVar25 + 0xc);
        *(undefined4 *)((long)param_1 + 0x9f4) = *(undefined4 *)(lVar25 + 0x1c);
        *(undefined8 *)((long)param_1 + 0x9ec) = uVar21;
        *(undefined8 *)((long)param_1 + 0x9e4) = uVar8;
        if ((param_1[0x13b] == 0) || (lVar25 = *plVar23, *(char *)(lVar25 + 0xc) != '\x01'))
        goto LAB_00115d58;
        uVar7 = (uint)(*(ushort *)(lVar25 + 10) >> 8) | (*(ushort *)(lVar25 + 10) & 0xff00ff) << 8;
        if (uVar7 <= ((uint)(*(ushort *)((long)param_1 + 0x9ca) >> 8) |
                     (*(ushort *)((long)param_1 + 0x9ca) & 0xff00ff) << 8)) {
          memcpy((void *)param_1[0x13b],(void *)(lVar25 + 0x20),(ulong)uVar7);
          goto LAB_00115d58;
        }
        _dev_warn(param_1[8],"%s: rsp size %d is bigger than buffer size %d",
                  "ufsf_copy_query_response");
        goto LAB_00115f44;
      case 0x3f:
        _dev_err(param_1[8],"%s: Reject UPIU not fully implemented\n","ufsf_dev_cmd_completion");
        uVar8 = 5;
        uVar7 = 0xffffffff;
        goto LAB_00115d60;
      }
      _dev_err(lVar25,pcVar9,"ufsf_dev_cmd_completion",uVar10);
LAB_00115f44:
      uVar8 = 5;
      uVar7 = 0xffffffea;
    }
    else {
LAB_00115ce4:
      uVar8 = 5;
    }
LAB_00115d60:
    ufsf_add_query_upiu_trace(param_1,uVar8,*(undefined8 *)(lVar22 + (ulong)uVar4 * 0x98 + 0x10));
    up_read(param_1 + 0x1a4);
    if (uVar7 == 0) {
      if (param_6 == (byte *)0x0) {
        uVar7 = 0;
      }
      else {
        uVar7 = 0;
        *param_6 = *(byte *)((long)param_1 + 0x9ef) & 1;
      }
      goto LAB_00115e5c;
    }
  }
  else {
    if ((int)param_1[0x130] == 1) {
      uVar7 = (*puVar26 & 0xff00ff00 | (uint)*pbVar11 << 8 | 0x16000000) >> 8 |
              (*puVar26 & 0xff00ff) << 8;
      puVar14 = *(uint **)(lVar22 + (ulong)uVar4 * 0x98 + 8);
      uVar6 = *(ushort *)((long)param_1 + 0x9ca);
      *puVar14 = uVar7 >> 0x10 | uVar7 << 0x10;
      uVar19 = (uint)(uVar6 >> 8);
      uVar20 = uVar6 & 0xff00ff;
      uVar7 = (uVar20 | uVar19 << 8) << 0x10;
      puVar14[1] = (uint)*(byte *)(param_1 + 0x138) << 8;
      if (*(char *)((long)param_1 + 0x9c4) != '\x02') {
        uVar7 = 0;
      }
      puVar14[2] = uVar7;
      uVar8 = *(undefined8 *)((long)param_1 + 0x9c4);
      uVar21 = *(undefined8 *)((long)param_1 + 0x9cc);
      puVar14[7] = *(uint *)((long)param_1 + 0x9d4);
      *(undefined8 *)(puVar14 + 3) = uVar8;
      *(undefined8 *)(puVar14 + 5) = uVar21;
      if (*(char *)((long)param_1 + 0x9c4) == '\x02') {
        memcpy(puVar14 + 8,(void *)param_1[0x13b],(ulong)(uVar19 | uVar20 << 8));
      }
      goto LAB_00115a44;
    }
    up_read(param_1 + 0x1a4);
    uVar7 = 0xffffffea;
  }
  _dev_err(param_1[8],"%s: Sending flag query for idn %d failed, err = %d\n","ufsf_query_flag",
           param_3,uVar7);
LAB_00115e5c:
  mutex_unlock(param_1 + 0x131);
  ufshcd_release(param_1);
  lVar22 = sp_el0;
  if (*(long *)(lVar22 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// ufsf_scsi_unblock_requests @ 00116400 size=76
// signature: undefined ufsf_scsi_unblock_requests(void)
// callers: [ufshid_auto_hibern8_enable]
//------------------------------------------------------------

void ufsf_scsi_unblock_requests(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  piVar1 = (int *)(param_1 + 0xd60);
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
  DataMemoryBarrier(2,3);
  if (iVar2 + -1 == 0) {
    scsi_unblock_requests(*(undefined8 *)(param_1 + 0x38));
  }
  return;
}



//------------------------------------------------------------
// ufsf_scsi_block_requests @ 00116464 size=76
// signature: undefined ufsf_scsi_block_requests(void)
// callers: [ufshid_auto_hibern8_enable]
//------------------------------------------------------------

void ufsf_scsi_block_requests(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  piVar1 = (int *)(param_1 + 0xd60);
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
  if (iVar2 + 1 == 1) {
    scsi_block_requests(*(undefined8 *)(param_1 + 0x38));
  }
  return;
}



//------------------------------------------------------------
// ufsf_wait_for_doorbell_clr @ 001164cc size=408
// signature: undefined ufsf_wait_for_doorbell_clr(void)
// callers: [ufshid_auto_hibern8_enable]
//------------------------------------------------------------

undefined8 ufsf_wait_for_doorbell_clr(long *param_1,ulong param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  undefined8 uVar8;
  int iVar9;
  byte bVar10;
  long *plVar11;
  
  ufshcd_hold(param_1,0);
  uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
  lVar5 = ktime_get();
  if ((int)param_1[0x3d] == 1) {
    bVar1 = false;
    bVar10 = 0;
    do {
      iVar2 = readl(*param_1 + 0x78);
      plVar11 = (long *)param_1[7];
      plVar7 = (long *)*plVar11;
      if (plVar7 == plVar11) {
        iVar9 = 0;
        plVar7 = plVar11;
      }
      else {
        iVar9 = 0;
        do {
          iVar3 = sbitmap_weight(plVar7 + 4);
          plVar7 = (long *)*plVar7;
          iVar9 = iVar3 + iVar9;
        } while (plVar7 != (long *)param_1[7]);
      }
      if (iVar2 == 0 && iVar9 == 0 || bVar1) {
        if (!(bool)((iVar2 != 0 || iVar9 != 0) & bVar10)) {
          uVar8 = 0;
          goto LAB_00116604;
        }
        _dev_err(param_1[8],"%s: timedout waiting for doorbell to clear (tm=0x%x, tr=0x%x)\n",
                 "ufsf_wait_for_doorbell_clr",iVar2,iVar9);
        break;
      }
      _raw_spin_unlock_irqrestore(plVar7[7],uVar4);
      io_schedule_timeout(5);
      lVar6 = ktime_get();
      bVar1 = param_2 < (ulong)((lVar6 - lVar5) / 1000);
      bVar10 = bVar1 | bVar10;
      uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
    } while ((int)param_1[0x3d] == 1);
  }
  uVar8 = 0xfffffff0;
LAB_00116604:
  _raw_spin_unlock_irqrestore(*(undefined8 *)(param_1[7] + 0x38),uVar4);
  ufshcd_release(param_1);
  return uVar8;
}



//------------------------------------------------------------
// ufsf_get_bkops_status @ 00116668 size=48
// signature: undefined ufsf_get_bkops_status(void)
// callers: []
//------------------------------------------------------------

void ufsf_get_bkops_status(undefined8 param_1,undefined8 param_2)

{
  ufshcd_query_attr_retry(param_1,3,5,0,0,param_2);
  return;
}



//------------------------------------------------------------
// __ufsf_write_ee_control @ 0011669c size=96
// signature: undefined __ufsf_write_ee_control(void)
// callers: []
//------------------------------------------------------------

void __ufsf_write_ee_control(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = param_2;
  ufshcd_query_attr_retry(param_1,4,0xd,0,0,&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufsf_enable_ee @ 00116700 size=204
// signature: undefined ufsf_enable_ee(void)
// callers: []
//------------------------------------------------------------

int ufsf_enable_ee(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  mutex_lock(param_1 + 0x200);
  uVar1 = (uint)*(ushort *)(param_1 + 0x1fa) | param_2 & 0xffff;
  uVar2 = uVar1 | *(ushort *)(param_1 + 0x1fc);
  if (uVar2 != *(ushort *)(param_1 + 0x1f8)) {
    local_4c = uVar2;
    iVar4 = ufshcd_query_attr_retry(param_1,4,0xd,0,0,&local_4c);
    if (iVar4 != 0) goto LAB_0011678c;
  }
  iVar4 = 0;
  *(short *)(param_1 + 0x1f8) = (short)uVar2;
  *(short *)(param_1 + 0x1fa) = (short)uVar1;
LAB_0011678c:
  mutex_unlock(param_1 + 0x200);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// ufsf_disable_ee @ 001167d0 size=204
// signature: undefined ufsf_disable_ee(void)
// callers: []
//------------------------------------------------------------

int ufsf_disable_ee(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  mutex_lock(param_1 + 0x200);
  uVar1 = (uint)*(ushort *)(param_1 + 0x1fa) & (param_2 ^ 0xffffffff);
  uVar2 = uVar1 | *(ushort *)(param_1 + 0x1fc);
  if (uVar2 != *(ushort *)(param_1 + 0x1f8)) {
    local_4c = uVar2;
    iVar4 = ufshcd_query_attr_retry(param_1,4,0xd,0,0,&local_4c);
    if (iVar4 != 0) goto LAB_0011685c;
  }
  iVar4 = 0;
  *(short *)(param_1 + 0x1f8) = (short)uVar2;
  *(short *)(param_1 + 0x1fa) = (short)uVar1;
LAB_0011685c:
  mutex_unlock(param_1 + 0x200);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// ufsf_exception_event_handler @ 001168a0 size=780
// signature: undefined ufsf_exception_event_handler(void)
// callers: [ufsf_vendor_exception_event_handler]
//------------------------------------------------------------

void ufsf_exception_event_handler(long param_1)

{
  long lVar1;
  int *piVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  undefined8 uVar9;
  char *pcVar10;
  char *pcVar11;
  uint local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_54 = 0;
  piVar2 = (int *)(param_1 + 0xd60);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    iVar8 = *piVar2;
    cVar6 = '\x01';
    bVar7 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar7) {
      *piVar2 = iVar8 + 1;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar8 + 1 == 1) {
    scsi_block_requests(*(undefined8 *)(param_1 + 0x38));
  }
  iVar8 = ufshcd_query_attr_retry(param_1,3,0xe,0,0,&local_54);
  if (iVar8 != 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: failed to get exception status %d\n",
             "ufsf_exception_event_handler");
    goto LAB_001169ec;
  }
  _dev_info(*(undefined8 *)(param_1 + 0x40),"%s: status 0x%x\n","ufsf_exception_event_handler",
            local_54);
  uVar4 = *(ushort *)(param_1 + 0x1fa);
  if (((local_54 & uVar4) >> 2 & 1) != 0) {
    local_50 = 0;
    if (*(char *)(param_1 + 0xce8) == '\0') {
      iVar8 = ufshcd_query_attr_retry(param_1,3,5,0,0,&local_50);
      if (iVar8 == 0) {
        if (1 < local_50) goto LAB_0011697c;
        _dev_err(*(undefined8 *)(param_1 + 0x40),
                 "%s: device raised urgent BKOPS exception for bkops status %d\n",
                 "ufsf_bkops_exception_event_handler");
        *(uint *)(param_1 + 0xce4) = local_50;
        *(undefined1 *)(param_1 + 0xce8) = 1;
        cVar6 = *(char *)(param_1 + 0xa48);
        goto joined_r0x00116a84;
      }
      uVar9 = *(undefined8 *)(param_1 + 0x40);
      pcVar10 = "%s: failed to get BKOPS status %d\n";
      pcVar11 = "ufsf_bkops_exception_event_handler";
LAB_00116b3c:
      _dev_err(uVar9,pcVar10,pcVar11,iVar8);
      if (iVar8 < 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x40),"%s: failed to handle urgent bkops %d\n",
                 "ufsf_bkops_exception_event_handler",iVar8);
      }
    }
    else {
LAB_0011697c:
      cVar6 = *(char *)(param_1 + 0xa48);
joined_r0x00116a84:
      if (cVar6 == '\0') {
        iVar8 = ufshcd_query_flag_retry(param_1,6,4,0,0);
        if (iVar8 == 0) {
          *(undefined1 *)(param_1 + 0xa48) = 1;
          _dev_info(*(undefined8 *)(param_1 + 0x40),"%s: auto bkops - Enabled\n",
                    "ufsf_enable_auto_bkops");
          lVar1 = param_1 + 0x200;
          mutex_lock(lVar1);
          uVar3 = *(ushort *)(param_1 + 0x1fa) & 0xfffffffb;
          uVar5 = uVar3 | *(ushort *)(param_1 + 0x1fc);
          if ((uVar5 == *(ushort *)(param_1 + 0x1f8)) ||
             (local_4c = uVar5, iVar8 = ufshcd_query_attr_retry(param_1,4,0xd,0,0,&local_4c),
             iVar8 == 0)) {
            *(short *)(param_1 + 0x1f8) = (short)uVar5;
            *(short *)(param_1 + 0x1fa) = (short)uVar3;
            mutex_unlock(lVar1);
            goto LAB_00116984;
          }
          mutex_unlock(lVar1);
          uVar9 = *(undefined8 *)(param_1 + 0x40);
          pcVar10 = "%s: failed to disable exception event %d\n";
        }
        else {
          uVar9 = *(undefined8 *)(param_1 + 0x40);
          pcVar10 = "%s: failed to enable bkops %d\n";
        }
        pcVar11 = "ufsf_enable_auto_bkops";
        goto LAB_00116b3c;
      }
    }
LAB_00116984:
    uVar4 = *(ushort *)(param_1 + 0x1fa);
  }
  if ((local_54 & uVar4 & 0x18) != 0) {
    local_4c = 0;
    iVar8 = ufshcd_query_attr_retry(param_1,3,0x18,0,0,&local_4c);
    if (iVar8 == 0) {
      _dev_info(*(undefined8 *)(param_1 + 0x40),"exception Tcase %d\n",local_4c - 0x50);
    }
  }
LAB_001169ec:
  piVar2 = (int *)(param_1 + 0xd60);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    iVar8 = *piVar2;
    cVar6 = '\x01';
    bVar7 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar7) {
      *piVar2 = iVar8 + -1;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar8 + -1 == 0) {
    scsi_unblock_requests(*(undefined8 *)(param_1 + 0x38));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufsfeature_command @ 00116bdc size=264
// signature: undefined trace_raw_output_ufsfeature_command(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufsfeature_command(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  ushort uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  long lVar10;
  undefined8 uVar11;
  
  lVar10 = *(long *)(param_1 + 0x20f0);
  iVar7 = trace_raw_output_prep(param_1,param_3);
  if (iVar7 == 1) {
    uVar8 = trace_print_symbols_seq
                      (param_1 + 0x90,*(undefined4 *)(lVar10 + 0xc),
                       trace_raw_output_ufsfeature_command_symbols);
    uVar5 = *(undefined1 *)(lVar10 + 0x2c);
    uVar6 = *(ushort *)(lVar10 + 8);
    uVar1 = *(undefined4 *)(lVar10 + 0x10);
    uVar2 = *(undefined4 *)(lVar10 + 0x14);
    uVar3 = *(undefined4 *)(lVar10 + 0x28);
    uVar4 = *(undefined4 *)(lVar10 + 0x1c);
    uVar11 = *(undefined8 *)(lVar10 + 0x20);
    uVar9 = trace_print_symbols_seq
                      (param_1 + 0x90,uVar5,trace_raw_output_ufsfeature_command_symbols_49);
    trace_event_printf(param_1,
                       "%s: %s: tag: %u, DB: 0x%x, size: %d, IS: %u, LBA: %llu, opcode: 0x%x (%s), group_id: 0x%x, hwq_id: %d\n"
                       ,uVar8,lVar10 + (ulong)uVar6,uVar1,uVar2,uVar3,uVar4,uVar11,uVar5,uVar9,
                       *(undefined1 *)(lVar10 + 0x2d),*(undefined4 *)(lVar10 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_ufsfeature_upiu @ 00116ce8 size=236
// signature: undefined trace_raw_output_ufsfeature_upiu(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_ufsfeature_upiu(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  ushort uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x20f0);
  iVar3 = trace_raw_output_prep(param_1,param_3);
  if (iVar3 == 1) {
    lVar1 = param_1 + 0x90;
    uVar4 = trace_print_symbols_seq
                      (lVar1,*(undefined4 *)(lVar8 + 0xc),trace_raw_output_ufsfeature_upiu_symbols);
    uVar2 = *(ushort *)(lVar8 + 8);
    uVar5 = trace_print_hex_seq(lVar1,lVar8 + 0x10,0xc,0);
    uVar6 = trace_print_symbols_seq
                      (lVar1,*(undefined4 *)(lVar8 + 0x2c),
                       trace_raw_output_ufsfeature_upiu_symbols_68);
    uVar7 = trace_print_hex_seq(lVar1,lVar8 + 0x1c,0x10,0);
    trace_event_printf(param_1,"%s: %s: HDR:%s, %s:%s\n",uVar4,lVar8 + (ulong)uVar2,uVar5,uVar6,
                       uVar7);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// ufsf_add_tm_upiu_trace @ 00116dd4 size=92
// signature: undefined ufsf_add_tm_upiu_trace(void)
// callers: [ufsf_issue_tm_cmd]
//------------------------------------------------------------

void ufsf_add_tm_upiu_trace(long param_1,undefined8 param_2,int param_3)

{
  char *pcVar1;
  
  pcVar1 = "%s: UFS_TSF_TM_INPUT\n";
  if (param_3 != 6) {
    pcVar1 = "%s: UFS_TSF_TM_OUTPUT\n";
  }
  _dev_info(*(undefined8 *)(param_1 + 0x40),pcVar1,"ufsf_add_tm_upiu_trace");
  return;
}



//------------------------------------------------------------
// ufsf_add_query_upiu_trace @ 00116eb8 size=52
// signature: undefined ufsf_add_query_upiu_trace(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

void ufsf_add_query_upiu_trace(void)

{
  return;
}



//------------------------------------------------------------
// ufsf_start_monitor @ 00116fbc size=204
// signature: undefined ufsf_start_monitor(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

void ufsf_start_monitor(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = 0;
  cVar3 = *(char *)(*(long *)(param_2 + 0x40) + 0xd4);
  switch(cVar3) {
  case '\b':
  case '(':
    break;
  case '\t':
  case '\v':
  case '\f':
  case '\r':
  case '\x0e':
  case '\x0f':
  case '\x10':
  case '\x11':
  case '\x12':
  case '\x13':
  case '\x14':
  case '\x15':
  case '\x16':
  case '\x17':
  case '\x18':
  case '\x19':
  case '\x1a':
  case '\x1b':
  case '\x1c':
  case '\x1d':
  case '\x1e':
  case '\x1f':
  case ' ':
  case '!':
  case '\"':
  case '#':
  case '$':
  case '%':
  case '&':
  case '\'':
  case ')':
switchD_00117000_caseD_9:
    uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38));
    goto LAB_00117064;
  case '\n':
  case '*':
switchD_00117000_caseD_a:
    lVar6 = 1;
    break;
  default:
    if (cVar3 != -0x78) {
      if (cVar3 == -0x76) goto switchD_00117000_caseD_a;
      goto switchD_00117000_caseD_9;
    }
  }
  uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38));
  lVar1 = param_1 + lVar6 * 4;
  iVar2 = *(int *)(lVar1 + 0x11f0);
  *(int *)(lVar1 + 0x11f0) = iVar2 + 1;
  if (iVar2 == 0) {
    uVar5 = ktime_get();
    *(undefined8 *)(param_1 + lVar6 * 8 + 0x11f8) = uVar5;
  }
LAB_00117064:
  _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(param_1 + 0x38) + 0x38),uVar4);
  return;
}



//------------------------------------------------------------
// ufsf_clear_cmd @ 00117088 size=276
// signature: undefined ufsf_clear_cmd(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ufsf_clear_cmd(long *param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  if (*(char *)((long)param_1 + 0x13ac) == '\0') {
    uVar2 = 1 << (ulong)(param_2 & 0x1f);
    uVar5 = _raw_spin_lock_irqsave(*(undefined8 *)(param_1[7] + 0x38));
    writel(uVar2 ^ (*(int *)((long)param_1 + 0xcc) << 0x19) >> 0x1f ^ 0xffffffffU,*param_1 + 0x5c);
    _raw_spin_unlock_irqrestore(*(undefined8 *)(param_1[7] + 0x38),uVar5);
    lVar1 = _jiffies + 0xfa;
    do {
      uVar4 = readl(*param_1 + 0x58);
      if ((uVar4 & uVar2) == 0) {
        return 0;
      }
      usleep_range_state(1000,0x41a,2);
    } while (-1 < lVar1 - _jiffies);
    uVar4 = readl(*param_1 + 0x58);
    iVar3 = 0;
    if ((uVar4 & uVar2) != 0) {
      iVar3 = -0x6e;
    }
  }
  else {
    iVar3 = ufsf_mcq_sq_cleanup(param_1,param_2);
    if (iVar3 != 0) {
      _dev_err(param_1[8],"%s: failed tag=%d. err=%d\n","ufsf_clear_cmd",param_2,iVar3);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// ufshid_get_state @ 001171c0 size=8
// signature: undefined ufshid_get_state(void)
// callers: [ufsf_resume, ufsf_remove, ufsf_prep_fn, ufsf_on_idle, ufsf_reset, ufsf_init, ufsf_resume_work_handler, ufsf_device_check, ufs_vh_prep_fn, ufsf_device_check_work_handler, ufsf_reset_host, ufsf_event_notify, ufsf_reset_wait_work_handler, ufsf_suspend]
//------------------------------------------------------------

undefined4 ufshid_get_state(long param_1)

{
  return *(undefined4 *)(param_1 + 0x130);
}



//------------------------------------------------------------
// ufshid_set_state @ 001171cc size=8
// signature: undefined ufshid_set_state(void)
// callers: [ufsf_set_init, ufsf_set_init_state]
//------------------------------------------------------------

void ufshid_set_state(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x130) = param_2;
  return;
}



//------------------------------------------------------------
// ufshid_get_geo_info @ 001171d8 size=212
// signature: undefined ufshid_get_geo_info(void)
// callers: [ufsf_device_check]
//------------------------------------------------------------

void ufshid_get_geo_info(long param_1,long param_2)

{
  byte bVar1;
  uint uVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  
  plVar6 = *(long **)(param_1 + 0x138);
  if ((*(uint *)(plVar6 + 0x236) & 0xf00) != 0x100) {
    bVar1 = *(byte *)(*plVar6 + 0x118);
    if (bVar1 == 0) {
      uVar4 = 0xf9;
      lVar5 = 4;
    }
    else {
      if ((3 < bVar1) || (1 < bVar1)) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1172ac);
        (*pcVar3)();
      }
      uVar4 = (ulong)(byte)(&DAT_0011c89e)[bVar1];
      lVar5 = 5;
    }
    bVar1 = (&ufshid_desc)[lVar5];
    uVar2 = (*(uint *)(param_2 + uVar4) & 0xff00ff00) >> 8 |
            (*(uint *)(param_2 + uVar4) & 0xff00ff) << 8;
    *(uint *)((long)plVar6 + 0x10dc) = uVar2 >> 0x10 | uVar2 << 0x10;
    *(undefined1 *)(plVar6 + 0x21c) = *(undefined1 *)(param_2 + (ulong)bVar1);
    _printk(&DAT_0012329f,"ufshid_get_geo_info",0x10f);
    _printk(&DAT_0012456b,"ufshid_get_geo_info",0x111,(ulong)bVar1,(char)plVar6[0x21c]);
  }
  return;
}



//------------------------------------------------------------
// ufshid_get_dev_info @ 001172b0 size=360
// signature: undefined ufshid_get_dev_info(void)
// callers: [ufsf_device_check]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufshid_get_dev_info(long *param_1,long param_2)

{
  byte bVar1;
  code *pcVar2;
  undefined *puVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  param_1[0x27] = 0;
  if (*(short *)(*param_1 + 0xa14) == 0x1ce) {
    if ((char)param_1[0x23] == '\0') {
      if ((*(byte *)(param_2 + 0xfe) & 1) == 0) {
        puVar3 = &DAT_00123a27;
        uVar5 = 0x120;
        goto LAB_0011736c;
      }
    }
    else if ((*(byte *)(param_2 + 0x51) >> 2 & 1) == 0) {
      puVar3 = &DAT_00123a27;
      uVar5 = 0x127;
      goto LAB_0011736c;
    }
  }
  _printk(&DAT_00121024,"ufshid_get_dev_info",0x12d);
  plVar4 = (long *)kmalloc_trace(_remove_resource,0xdc0,0x11c0);
  param_1[0x27] = (long)plVar4;
  if (plVar4 != (long *)0x0) {
    bVar1 = *(byte *)(param_1 + 0x23);
    uVar6 = (ulong)bVar1;
    *plVar4 = (long)param_1;
    if (bVar1 == 0) {
      uVar6 = 0;
    }
    else if (5 < bVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x117418);
      (*pcVar2)();
    }
    if (5 < uVar6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x117414);
      (*pcVar2)();
    }
    *(uint *)(plVar4 + 0x236) =
         (uint)(*(ushort *)(param_2 + (ulong)(byte)(&ufshid_desc)[uVar6]) >> 8) |
         (*(ushort *)(param_2 + (ulong)(byte)(&ufshid_desc)[uVar6]) & 0xff00ff) << 8;
    _printk(&DAT_00121b6c,"ufshid_version_print",0xfb,0x305);
    _printk(&DAT_00122d11,"ufshid_version_print",0xfd,0x30401,&DAT_001212c5);
    return;
  }
  puVar3 = &DAT_00120750;
  uVar5 = 0x131;
LAB_0011736c:
  _printk(puVar3,"ufshid_get_dev_info",uVar5);
  *(undefined4 *)(param_1 + 0x26) = 0xfffffffe;
  return;
}



//------------------------------------------------------------
// ufshid_prep_fn @ 0011741c size=412
// signature: undefined ufshid_prep_fn(void)
// callers: [ufsf_prep_fn, ufs_vh_prep_fn]
//------------------------------------------------------------

void ufshid_prep_fn(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  ulong __n;
  ulong uVar7;
  
  lVar4 = *(long *)(param_2 + 0x40);
  if ((*(char *)(lVar4 + 0xd4) == ';') && (*(char *)(lVar4 + 0xd5) == '\x1d')) {
    lVar6 = *(long *)(param_1 + 0x138);
    if (*(char *)(lVar6 + 0x10e8) != '\0') {
      plVar5 = *(long **)(*(long *)(lVar4 + -0x108) + 0x78);
      uVar1 = *(uint *)(plVar5 + 1);
      uVar7 = *plVar5 << 6;
      if ((*(size_t *)(lVar6 + 0x10b0) == (long)(int)uVar1) &&
         (iVar3 = bcmp((void *)(lVar6 + 0xb0),
                       (void *)(uVar7 & 0xfffffffffff000 | 0xff00000000000000),
                       *(size_t *)(lVar6 + 0x10b0)), iVar3 == 0)) {
        _printk(&DAT_00120774,"ufshid_prep_fn",0x3d4);
      }
      else {
        uVar7 = uVar7 & 0xfffffffffff000;
        if (*(int *)((code *)**(undefined8 **)(lVar6 + 0x11b8) + -4) != 0x5322dfd) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1174f4);
          (*pcVar2)();
        }
        iVar3 = (*(code *)**(undefined8 **)(lVar6 + 0x11b8))
                          (lVar6,uVar7 | 0xff00000000000000,(ulong)uVar1);
        if (iVar3 == 0) {
          __n = (ulong)uVar1 & 0xffff;
          *(uint *)(lVar6 + 0xac) = (uint)*(byte *)(param_2 + 0x54);
          if ((0x1000 < (uVar1 & 0xffff)) && ((ufshid_set_lba_param___already_done & 1) == 0)) {
            ufshid_set_lba_param___already_done = 1;
            __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                          ,__n,"field \"hid_req->buf\" at drivers/ufs/host/HID_UFS31/ufshid.c:442",
                          0x1000);
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1175d0);
            (*pcVar2)();
          }
          memcpy((void *)(lVar6 + 0xb0),(void *)(uVar7 | 0xff00000000000000),__n);
          *(ulong *)(lVar6 + 0x10b0) = __n;
          *(undefined1 *)(lVar6 + 0x10e1) = 1;
        }
        else {
          _printk(&DAT_0011fff5,"ufshid_prep_fn",0x3da);
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// ufshid_suspend_3_0 @ 001175d8 size=484
// signature: undefined ufshid_suspend_3_0(void)
// callers: []
//------------------------------------------------------------

void ufshid_suspend_3_0(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x138);
  if (puVar3 != (undefined8 *)0x0) {
    if (*(int *)(puVar3 + 1) != 0) {
      if ((param_2 & 1) == 0) {
        _printk(&DAT_001224e8,"ufshid_suspend_3_0",0x4c2);
      }
      else {
        lVar2 = *(long *)*puVar3;
        if (*(uint *)(lVar2 + 0x5c) < 2) {
          local_3c = 0;
          iVar1 = ufshid_read_attr(puVar3,8,&local_3c);
          if (*(char *)(puVar3 + 0x231) != '\0') {
            _printk(&DAT_00121d58,"ufshid_is_in_progress",0x23a,*(undefined4 *)(puVar3 + 1),
                    *(undefined4 *)(*(long *)(*(long *)*puVar3 + 0x40) + 0x1f8),
                    *(undefined4 *)(*(long *)*puVar3 + 0xbdc),iVar1,local_3c);
          }
          if (((iVar1 == 0) && ((local_3c & 0xfffffffd) == 1)) &&
             (*(char *)(puVar3 + 0x231) != '\0')) {
            _printk(&DAT_00121600,"ufshid_suspend_3_0",0x4ba,*(undefined4 *)(puVar3 + 1),
                    *(undefined4 *)(*(long *)(*(long *)*puVar3 + 0x40) + 0x1f8),
                    *(undefined4 *)(*(long *)*puVar3 + 0xbdc));
          }
        }
        else {
          if (*(char *)(puVar3 + 0x231) != '\0') {
            _printk(&DAT_00123010,"ufshid_suspend_3_0",0x4bc,*(int *)(puVar3 + 1),
                    *(undefined4 *)(*(long *)(lVar2 + 0x40) + 0x1f8),*(undefined4 *)(lVar2 + 0xbdc))
            ;
          }
          iVar1 = ufshid_trigger_off(puVar3);
          if (iVar1 != 0) {
            _printk(&DAT_00123a5d,"ufshid_suspend_3_0",0x4bf,iVar1);
          }
        }
      }
    }
    *(undefined4 *)(param_1 + 0x130) = 2;
    *(undefined4 *)(puVar3 + 0x232) = 0;
    __init_swait_queue_head(puVar3 + 0x233,"&x->wait",&init_completion___key);
    cancel_delayed_work_sync(puVar3 + 2);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufshid_trigger_off @ 001177bc size=188
// signature: undefined ufshid_trigger_off(void)
// callers: [ufshid_get_analyze_and_in_work, ufshid_trigger_on, ufshid_sysfs_store_trigger, ufshid_remove, ufshid_hid_progress_chk_in_work, micron_ufshid_trigger_work_fn, ufshid_suspend_3_0]
//------------------------------------------------------------

undefined8 ufshid_trigger_off(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 1) != 0) {
    uVar1 = ufshid_hold_runtime_pm();
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    *(undefined4 *)(param_1 + 1) = 0;
    if (*(char *)(param_1 + 0x231) != '\0') {
      _printk(&DAT_00121baf,"ufshid_trigger_off",0x2f0,0,
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc));
    }
    *(undefined1 *)(param_1 + 0x21b) = 0;
    memset(param_1 + 0x15,0,0x1030);
    ufshid_issue_disable(param_1);
    ufshid_auto_hibern8_enable(param_1,1);
    ufshid_allow_enter_suspend(param_1);
    ufsf_rpm_put_noidle(*(undefined8 *)*param_1);
  }
  return 0;
}



//------------------------------------------------------------
// ufshid_resume_3_0 @ 0011787c size=336
// signature: undefined ufshid_resume_3_0(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufshid_resume_3_0(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 *puVar4;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x138);
  if (puVar4 == (undefined8 *)0x0) goto LAB_00117958;
  *(undefined4 *)(param_1 + 0x130) = 1;
  complete(puVar4 + 0x232);
  if (((param_2 & 1) == 0) || (*(char *)(puVar4 + 0x21d) == '\0')) {
LAB_0011792c:
    iVar1 = *(int *)(puVar4 + 1);
  }
  else {
    lVar3 = *(long *)*puVar4;
    local_3c = (uint)*(byte *)((long)puVar4 + 0x10e9);
    __pm_runtime_resume(*(long *)(lVar3 + 0x48) + 0x1d8,5);
    iVar1 = ufshcd_query_attr_retry(lVar3,4,0x8f,0,0,&local_3c);
    ufsf_rpm_put_noidle(lVar3);
    if ((iVar1 != 0) || (*(char *)(puVar4 + 0x231) == '\0')) goto LAB_0011792c;
    _printk(&DAT_0012253f,"ufshid_restore_attr",0x4a7,*(undefined4 *)(puVar4 + 1),
            *(undefined4 *)(*(long *)(*(long *)*puVar4 + 0x40) + 0x1f8),
            *(undefined4 *)(*(long *)*puVar4 + 0xbdc),0x8f,local_3c);
    iVar1 = *(int *)(puVar4 + 1);
  }
  if (iVar1 != 0) {
    uVar2 = __msecs_to_jiffies(*(undefined4 *)(puVar4 + 0x13));
    queue_delayed_work_on(0x20,_system_freezable_wq,puVar4 + 2,uVar2);
  }
LAB_00117958:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufshid_suspend_1_0 @ 001179d0 size=128
// signature: undefined ufshid_suspend_1_0(void)
// callers: []
//------------------------------------------------------------

void ufshid_suspend_1_0(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x138);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 8) != 0) {
      _printk(&DAT_00121056,"ufshid_suspend_1_0",0x4e9);
    }
    *(undefined4 *)(param_1 + 0x130) = 2;
    *(undefined4 *)(lVar1 + 0x1190) = 0;
    __init_swait_queue_head(lVar1 + 0x1198,"&x->wait",&init_completion___key);
    cancel_delayed_work_sync(lVar1 + 0x10);
  }
  return;
}



//------------------------------------------------------------
// ufshid_resume_1_0 @ 00117a54 size=100
// signature: undefined ufshid_resume_1_0(void)
// callers: []
//------------------------------------------------------------

void ufshid_resume_1_0(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x138);
  if (lVar1 != 0) {
    complete(lVar1 + 0x1190);
    if (*(int *)(lVar1 + 8) != 0) {
      _printk(&DAT_001242af,"ufshid_resume_1_0",0x4fc);
    }
    *(undefined4 *)(param_1 + 0x130) = 1;
  }
  return;
}



//------------------------------------------------------------
// ufshid_init @ 00117abc size=952
// signature: undefined ufshid_init(void)
// callers: [ufsf_device_check_work_handler, ufsf_init]
//------------------------------------------------------------

void ufshid_init(long *param_1)

{
  undefined8 *puVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  code *pcVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined8 uVar9;
  long *plVar10;
  uint local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  puVar7 = (undefined8 *)param_1[0x27];
  lVar8 = *param_1;
  _printk(&DAT_00123a85,"ufshid_init",0x522);
  if (puVar7 == (undefined8 *)0x0) {
    _printk(&DAT_001207a4,"ufshid_init",0x525);
  }
  else {
    *(undefined4 *)(puVar7 + 1) = 0;
    puVar7[0x13] = 0x64000007d0;
    if ((*(uint *)(puVar7 + 0x236) & 0xf00) == 0x200) {
      *(undefined1 *)(puVar7 + 0x21d) = 1;
      puVar7[0x237] = &ufshid_2_0;
      *(undefined1 *)(puVar7 + 0x21b) = 0;
      memset(puVar7 + 0x15,0,0x1030);
    }
    else if ((*(uint *)(puVar7 + 0x236) & 0xf00) == 0x100) {
      puVar7[0x237] = &ufshid_1_0;
    }
    else {
      puVar7[0x237] = &ufshid_3_0;
      if (*(short *)(lVar8 + 0xa14) == 0x1ce) {
        local_4c = 0;
        ufshid_read_attr(puVar7,0xb,&local_4c);
        *(byte *)(puVar7 + 0x21d) = (byte)local_4c & 1;
        if ((local_4c & 1) != 0) {
          *(undefined1 *)(puVar7 + 0x21b) = 0;
          memset(puVar7 + 0x15,0,0x1030);
          *(undefined1 *)((long)puVar7 + 0x10e9) = 0;
          ufshid_write_attr(puVar7,10,0);
        }
        *(undefined4 *)((long)puVar7 + 0x10e4) = 0xffffffff;
        ufshid_write_attr(puVar7,5,0xffffffff);
      }
    }
    sVar2 = *(short *)(lVar8 + 0xa14);
    if (sVar2 == 300) {
      puVar7[2] = 0xfffffffe0;
      pcVar6 = micron_ufshid_trigger_work_fn;
LAB_00117c50:
      puVar1 = puVar7 + 3;
      *puVar1 = puVar1;
      puVar7[4] = puVar1;
      puVar7[5] = pcVar6;
      init_timer_key(puVar7 + 8,&delayed_work_timer_fn,0x200000,0,0);
    }
    else if (sVar2 == 0x1ce) {
      puVar7[2] = 0xfffffffe0;
      pcVar6 = ufshid_trigger_work_fn;
      goto LAB_00117c50;
    }
    *(undefined2 *)(puVar7 + 0x231) = 1;
    if ((*(char *)(*param_1 + 0x8a) < '\0') && ((*(byte *)(*param_1 + 0xcd) >> 3 & 1) == 0)) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
    *(undefined1 *)((long)puVar7 + 0xa4) = uVar5;
    *(undefined4 *)(puVar7 + 0x14) = *(undefined4 *)(*param_1 + 100);
    puVar1 = puVar7 + 0x21e;
    uVar9 = *(undefined8 *)(*(long *)*puVar7 + 0x40);
    puVar7[0x230] = &ufshid_sysfs_entries;
    kobject_init(puVar1,ufshid_ktype);
    __mutex_init(puVar7 + 0x22a,"&hid->sysfs_lock",&ufshid_create_sysfs___key);
    _printk(&DAT_00123b1f,"ufshid_create_sysfs",0x8af,puVar1,uVar9);
    uVar9 = kobject_get(uVar9);
    iVar3 = kobject_add(puVar1,uVar9,"ufshid");
    if (iVar3 == 0) {
      plVar10 = (long *)puVar7[0x230];
      lVar8 = *plVar10;
      while (lVar8 != 0) {
        _printk(&DAT_00124083,"ufshid_create_sysfs",0x8b6);
        iVar3 = sysfs_create_file_ns(puVar1,plVar10,0);
        if (iVar3 != 0) {
          _printk(&DAT_001235c8,"ufshid_create_sysfs",0x8ba,*plVar10);
          uVar4 = kobject_uevent(puVar1,1);
          _printk(&DAT_00123ce8,"ufshid_create_sysfs",0x8c7,uVar4);
          kobject_del(puVar1);
          goto LAB_00117e18;
        }
        plVar10 = plVar10 + 4;
        lVar8 = *plVar10;
      }
      kobject_uevent(puVar1,0);
      _printk(&DAT_0011f91d,"ufshid_init",0x559);
      uVar4 = 1;
      goto LAB_00117e3c;
    }
    _printk(&DAT_00120840,"ufshid_create_sysfs",0x8c0);
LAB_00117e18:
    _printk(&DAT_0012459d,"ufshid_init",0x553);
    kfree(puVar7);
  }
  uVar4 = 0xfffffffe;
LAB_00117e3c:
  *(undefined4 *)(param_1 + 0x26) = uVar4;
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufshid_trigger_work_fn @ 00117e78 size=392
// signature: undefined ufshid_trigger_work_fn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufshid_trigger_work_fn(long param_1)

{
  char *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  long *plVar6;
  
  plVar6 = (long *)(param_1 + -0x10);
  if ((int)((long *)*plVar6)[0x26] == 1) {
    pcVar1 = (char *)(param_1 + 0x1178);
    if (*pcVar1 != '\0') {
      lVar5 = *(long *)*plVar6;
      _printk(&DAT_001213f0,"ufshid_trigger_work_fn",0x437,*(undefined4 *)(param_1 + -8),
              *(undefined4 *)(*(long *)(lVar5 + 0x40) + 0x1f8),*(undefined4 *)(lVar5 + 0xbdc));
    }
    lVar5 = param_1 + 0x1140;
    mutex_lock(lVar5);
    if (*(int *)(param_1 + -8) == 0) {
      if (*pcVar1 != '\0') {
        _printk(&DAT_00122010,"ufshid_trigger_work_fn",0x43c,0,
                *(undefined4 *)(*(long *)(*(long *)*plVar6 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*plVar6 + 0xbdc));
      }
    }
    else {
      pcVar4 = *(code **)(*(long *)(param_1 + 0x11a8) + 0x28);
      if (*(int *)(pcVar4 + -4) != -0x2b2df33c) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x117ef0);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(plVar6);
      if ((uVar2 & 1) != 0) {
        mutex_unlock(lVar5);
        uVar3 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x88));
        queue_delayed_work_on(0x20,_system_freezable_wq,param_1,uVar3);
        if (*pcVar1 == '\0') {
          return;
        }
        _printk(&DAT_0012080d,"ufshid_trigger_work_fn",0x44e,*(undefined4 *)(param_1 + -8),
                *(undefined4 *)(*(long *)(**(long **)(param_1 + -0x10) + 0x40) + 0x1f8),
                *(undefined4 *)(**(long **)(param_1 + -0x10) + 0xbdc));
        return;
      }
    }
    mutex_unlock(lVar5);
  }
  else {
    _printk(&DAT_00121337,"ufshid_is_not_present",0x67);
  }
  return;
}



//------------------------------------------------------------
// micron_ufshid_trigger_work_fn @ 00118004 size=900
// signature: undefined micron_ufshid_trigger_work_fn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void micron_ufshid_trigger_work_fn(long param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined *puVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  int local_54;
  int local_50;
  undefined1 local_4c [4];
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  plVar7 = (long *)(param_1 + -0x10);
  if ((int)((long *)*plVar7)[0x26] != 1) {
    _printk(&DAT_00121337,"ufshid_is_not_present",0x67);
    goto LAB_00118154;
  }
  pcVar1 = (char *)(param_1 + 0x1178);
  if (*pcVar1 != '\0') {
    lVar8 = *(long *)*plVar7;
    _printk(&DAT_001213f0,"micron_ufshid_trigger_work_fn",0x45c,*(undefined4 *)(param_1 + -8),
            *(undefined4 *)(*(long *)(lVar8 + 0x40) + 0x1f8),*(undefined4 *)(lVar8 + 0xbdc));
  }
  local_54 = 0;
  local_50 = 0;
  iVar4 = ufshid_read_attr_micron(plVar7,0x81,&local_54);
  if ((iVar4 == 0) && (iVar4 = ufshid_read_attr_micron(plVar7,0x82,&local_50), iVar4 == 0)) {
    if (*pcVar1 != '\0') {
      _printk(&DAT_00122048,"ufshid_get_analyze_and_issue_execute_micron",0x1ee,
              *(undefined4 *)(param_1 + -8),
              *(undefined4 *)(*(long *)(**(long **)(param_1 + -0x10) + 0x40) + 0x1f8),
              *(undefined4 *)(**(long **)(param_1 + -0x10) + 0xbdc),local_54,local_50);
    }
    if (local_50 != 1) {
      if (local_54 == 0) {
        iVar4 = 0;
        goto LAB_00118084;
      }
      local_4c[0] = 0;
      lVar8 = *(long *)*plVar7;
      __pm_runtime_resume(*(long *)(lVar8 + 0x48) + 0x1d8,4);
      iVar4 = ufshcd_query_flag_retry(lVar8,6,0x83,0,local_4c);
      if (iVar4 == 0) {
        if (*pcVar1 != '\0') {
          _printk(&DAT_00120d5c,"ufshid_set_flag",0xc4,*(undefined4 *)(param_1 + -8),
                  *(undefined4 *)(*(long *)(**(long **)(param_1 + -0x10) + 0x40) + 0x1f8),
                  *(undefined4 *)(**(long **)(param_1 + -0x10) + 0xbdc),0x83,local_4c[0]);
        }
      }
      else {
        _printk(&DAT_00123af4,"ufshid_set_flag",0xc0,0x83,iVar4);
      }
      lVar9 = *(long *)(lVar8 + 0x40);
      uVar5 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar9 + 0x220) = uVar5;
      ufsf_rpm_put_noidle(lVar8);
    }
    iVar4 = 1;
  }
  else {
    iVar4 = -0x16;
  }
LAB_00118084:
  lVar8 = param_1 + 0x1140;
  mutex_lock(lVar8);
  if (*(int *)(param_1 + -8) == 0) {
    if (*pcVar1 != '\0') {
      _printk(&DAT_00122010,"micron_ufshid_trigger_work_fn",0x462,0,
              *(undefined4 *)(*(long *)(*(long *)*plVar7 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*plVar7 + 0xbdc));
    }
LAB_001180d8:
    mutex_unlock(lVar8);
  }
  else {
    if (iVar4 == 1) {
      if (*pcVar1 != '\0') {
        puVar6 = &DAT_0012358e;
        uVar5 = 0x46f;
        uVar2 = *(undefined4 *)(*(long *)(**(long **)(param_1 + -0x10) + 0x40) + 0x1f8);
        uVar3 = *(undefined4 *)(**(long **)(param_1 + -0x10) + 0xbdc);
        iVar4 = *(int *)(param_1 + 0x88);
LAB_001182e4:
        _printk(puVar6,"micron_ufshid_trigger_work_fn",uVar5,*(int *)(param_1 + -8),uVar2,uVar3,
                iVar4);
      }
    }
    else if (iVar4 == 0) {
      iVar4 = ufshid_trigger_off(plVar7);
      if (iVar4 == 0) goto LAB_001180d8;
      _printk(&DAT_00120cb8,"micron_ufshid_trigger_work_fn",0x46b);
    }
    else if (*pcVar1 != '\0') {
      puVar6 = &DAT_00120a9b;
      uVar5 = 0x472;
      uVar2 = *(undefined4 *)(*(long *)(*(long *)*plVar7 + 0x40) + 0x1f8);
      uVar3 = *(undefined4 *)(*(long *)*plVar7 + 0xbdc);
      goto LAB_001182e4;
    }
    mutex_unlock(lVar8);
    uVar5 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x88));
    queue_delayed_work_on(0x20,_system_wq,param_1,uVar5);
    if (*pcVar1 != '\0') {
      _printk(&DAT_0012080d,"micron_ufshid_trigger_work_fn",0x47b,*(undefined4 *)(param_1 + -8),
              *(undefined4 *)(*(long *)(**(long **)(param_1 + -0x10) + 0x40) + 0x1f8),
              *(undefined4 *)(**(long **)(param_1 + -0x10) + 0xbdc));
    }
  }
LAB_00118154:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufshid_reset_host @ 0011838c size=52
// signature: undefined ufshid_reset_host(void)
// callers: [ufsf_reset_host]
//------------------------------------------------------------

void ufshid_reset_host(long param_1)

{
  if (*(long *)(param_1 + 0x138) != 0) {
    *(undefined4 *)(param_1 + 0x130) = 0xfffffffd;
    cancel_delayed_work_sync(*(long *)(param_1 + 0x138) + 0x10);
  }
  return;
}



//------------------------------------------------------------
// ufshid_reset @ 001183c4 size=156
// signature: undefined ufshid_reset(void)
// callers: [ufsf_reset, ufsf_reset_wait_work_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufshid_reset(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = param_1[0x27];
  if (lVar1 != 0) {
    lVar2 = *param_1;
    *(undefined4 *)(param_1 + 0x26) = 1;
    if (*(int *)(lVar1 + 8) != 0) {
      queue_delayed_work_on(0x20,_system_freezable_wq,lVar1 + 0x10,0);
    }
    if ((*(short *)(lVar2 + 0xa14) == 0x1ce) && (*(char *)(lVar1 + 0x10e8) != '\0')) {
      ufshid_write_attr(lVar1,10,*(undefined1 *)(lVar1 + 0x10e9));
    }
    _printk(&DAT_001202c2,"ufshid_reset",0x580);
  }
  return;
}



//------------------------------------------------------------
// ufshid_write_attr @ 00118460 size=356
// signature: undefined ufshid_write_attr(void)
// callers: [ufshid_init, ufshid_sysfs_show_color, ufshid_execute_query_op_and_frag_chk, ufshid_reset, ufshid_sysfs_store_l2p_defrag_threshold, ufshid_sysfs_store_hid_size, ufshid_hid_progress_chk_in_work, ufshid_sysfs_show_l2p_frag_lvl, ufshid_execute_query_hid_op, ufshid_sysfs_store_debug_op]
//------------------------------------------------------------

int ufshid_write_attr(long *param_1,uint param_2,undefined4 param_3)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  plVar5 = (long *)*param_1;
  lVar4 = *plVar5;
  local_4c = param_3;
  __pm_runtime_resume(*(long *)(lVar4 + 0x48) + 0x1d8,4);
  if (param_2 < 4) {
    if ((*(byte *)(*param_1 + 0x118) != 0) &&
       (param_2 = *(byte *)(*param_1 + 0x118) + param_2, 0xb < param_2)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1184d0);
      (*pcVar2)();
    }
  }
  else if (0xb < param_2) goto LAB_001185bc;
  if (param_2 < 0xc) {
    uVar1 = (&ufshid_idn)[param_2];
    iVar3 = ufshcd_query_attr_retry(lVar4,4,uVar1,0,(char)plVar5[0x23],&local_4c);
    if (iVar3 == 0) {
      if ((char)param_1[0x231] != '\0') {
        _printk(&DAT_001232d0,"ufshid_write_attr",0xad,(int)param_1[1],
                *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*param_1 + 0xbdc),uVar1,local_4c,local_4c);
      }
    }
    else {
      _printk(&DAT_001237e8,"ufshid_write_attr",0xa9,uVar1,iVar3);
    }
    ufsf_rpm_put_noidle(lVar4);
    lVar4 = sp_el0;
    if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar3;
  }
LAB_001185bc:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x1185c0);
  (*pcVar2)();
}



//------------------------------------------------------------
// ufshid_remove @ 001185c8 size=252
// signature: undefined ufshid_remove(void)
// callers: [ufsf_remove]
//------------------------------------------------------------

void ufshid_remove(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x138);
  if (lVar3 != 0) {
    _printk(&DAT_00124845,"ufshid_remove",0x594);
    mutex_lock(lVar3 + 0x1150);
    iVar1 = ufshid_trigger_off(lVar3);
    if (iVar1 != 0) {
      _printk(&DAT_00123a5d,"ufshid_remove",0x59a,iVar1);
    }
    uVar2 = kobject_uevent(lVar3 + 0x10f0,1);
    _printk(&DAT_00123ce8,"ufshid_remove_sysfs",0x588,uVar2);
    kobject_del(lVar3 + 0x10f0);
    *(undefined4 *)(param_1 + 0x130) = 0xfffffffe;
    mutex_unlock(lVar3 + 0x1150);
    cancel_delayed_work_sync(lVar3 + 0x10);
    kfree(lVar3);
    _printk(&DAT_00120a7c,"ufshid_remove",0x5a6);
  }
  return;
}



//------------------------------------------------------------
// ufshid_suspend @ 001186c8 size=72
// signature: undefined ufshid_suspend(void)
// callers: [ufsf_suspend]
//------------------------------------------------------------

void ufshid_suspend(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x138) + 0x11b8) + 8);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x1d5395bf) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x118700);
      (*pcVar1)();
    }
    (*pcVar1)(param_1,param_2 & 1);
  }
  return;
}



//------------------------------------------------------------
// ufshid_resume @ 00118714 size=72
// signature: undefined ufshid_resume(void)
// callers: [ufsf_resume, ufsf_event_notify, ufsf_resume_work_handler]
//------------------------------------------------------------

void ufshid_resume(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(*(long *)(param_1 + 0x138) + 0x11b8) + 0x10);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x1d5395bf) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11874c);
      (*pcVar1)();
    }
    (*pcVar1)(param_1,param_2 & 1);
  }
  return;
}



//------------------------------------------------------------
// ufshid_on_idle @ 00118760 size=108
// signature: undefined ufshid_on_idle(void)
// callers: [ufsf_on_idle]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ufshid_on_idle(long param_1)

{
  ulong *puVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x138);
  if (((lVar2 != 0) && ((*(uint *)(lVar2 + 0x11b0) & 0xf00) != 0x300)) && (*(int *)(lVar2 + 8) != 0)
     ) {
    puVar1 = (ulong *)(lVar2 + 0x10);
    if ((*puVar1 & 1) != 0) {
      cancel_delayed_work(puVar1);
    }
    queue_delayed_work_on(0x20,_system_freezable_wq,puVar1,*(undefined4 *)(lVar2 + 0x9c));
  }
  return;
}



//------------------------------------------------------------
// ufshid_is_hid_req @ 001187d0 size=36
// signature: undefined ufshid_is_hid_req(void)
// callers: [ufsf_compl_command]
//------------------------------------------------------------

bool ufshid_is_hid_req(long param_1)

{
  if (*(char *)(param_1 + 0xd4) == ';') {
    return *(char *)(param_1 + 0xd5) == '\x1d';
  }
  return false;
}



//------------------------------------------------------------
// ufshid_read_attr @ 001187f4 size=320
// signature: undefined ufshid_read_attr(void)
// callers: [ufshid_init, ufshid_sysfs_show_color, ufshid_execute_query_op_and_frag_chk, ufshid_sysfs_show_progress_ratio, ufshid_hid_progress_chk_in_work, ufshid_sysfs_show_l2p_frag_lvl, ufshid_sysfs_show_available_size, ufshid_sysfs_show_debug_op, ufshid_suspend_3_0, ufshid_sysfs_show_hid_state]
//------------------------------------------------------------

int ufshid_read_attr(long *param_1,uint param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = (long *)*param_1;
  lVar4 = *plVar5;
  __pm_runtime_resume(*(long *)(lVar4 + 0x48) + 0x1d8,4);
  if (param_2 < 4) {
    if ((*(byte *)(*param_1 + 0x118) != 0) &&
       (param_2 = *(byte *)(*param_1 + 0x118) + param_2, 0xb < param_2)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x118858);
      (*pcVar2)();
    }
  }
  else if (0xb < param_2) goto LAB_00118930;
  if (param_2 < 0xc) {
    uVar1 = (&ufshid_idn)[param_2];
    iVar3 = ufshcd_query_attr_retry(lVar4,3,uVar1,0,(char)plVar5[0x23],param_3);
    if (iVar3 == 0) {
      if ((char)param_1[0x231] != '\0') {
        _printk(&DAT_001245d3,"ufshid_read_attr",0x93,(int)param_1[1],
                *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*param_1 + 0xbdc),uVar1,*param_3,*param_3);
      }
    }
    else {
      _printk(&DAT_00121da0,"ufshid_read_attr",0x8e,uVar1,iVar3);
    }
    ufsf_rpm_put_noidle(lVar4);
    return iVar3;
  }
LAB_00118930:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x118934);
  (*pcVar2)();
}



//------------------------------------------------------------
// ufshid_hold_runtime_pm @ 00118934 size=220
// signature: undefined ufshid_hold_runtime_pm(void)
// callers: [ufshid_attr_show, ufshid_trigger_on, ufshid_trigger_off, ufshid_attr_store]
//------------------------------------------------------------

undefined8 ufshid_hold_runtime_pm(long *param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(*(long *)*param_1 + 0x48);
  if (((int)((long *)*param_1)[0x26] != 2) ||
     ((*(int *)(lVar1 + 0x3e4) == 2 && ((*(ushort *)(lVar1 + 0x3d8) & 7) == 0)))) {
    __pm_runtime_resume(lVar1 + 0x1d8,4);
    lVar1 = *param_1;
    if (*(int *)(lVar1 + 0x130) == 2) {
      lVar1 = wait_for_completion_timeout(param_1 + 0x232,500);
      if (lVar1 == 0) {
        _printk(&DAT_001227b7,"ufshid_hold_runtime_pm",0x2b8);
        return 0xffffff92;
      }
      lVar1 = *param_1;
    }
    if (*(int *)(lVar1 + 0x130) == 1) {
      return 0;
    }
    _printk(&DAT_00121337,"ufshid_is_not_present",0x67);
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// ufshid_issue_disable @ 00118a10 size=488
// signature: undefined ufshid_issue_disable(void)
// callers: [ufshid_trigger_off, ufshid_hid_progress_chk_in_work, ufshid_sysfs_show_l2p_frag_lvl]
//------------------------------------------------------------

void ufshid_issue_disable(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  int local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_3c = 0;
  if (*(short *)(*(long *)*param_1 + 0xa14) == 300) {
    iVar1 = ufshid_read_attr_micron(param_1,0x82,&local_3c);
    if (iVar1 == 0) {
      if (*(char *)(param_1 + 0x231) != '\0') {
        _printk(&DAT_00123cb4,"ufshid_issue_disable",0x208,*(undefined4 *)(param_1 + 1),
                *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*param_1 + 0xbdc),local_3c);
      }
      if (local_3c == 1) {
        lVar5 = *(long *)*param_1;
        __pm_runtime_resume(*(long *)(lVar5 + 0x48) + 0x1d8,4);
        iVar1 = ufshcd_query_flag_retry(lVar5,7,0x83,0,0);
        if (iVar1 == 0) {
          if (*(char *)(param_1 + 0x231) != '\0') {
            _printk(&DAT_0012229b,"ufshid_clear_flag",0xd9,*(undefined4 *)(param_1 + 1),
                    *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                    *(undefined4 *)(*(long *)*param_1 + 0xbdc),0x83);
          }
        }
        else {
          _printk(&DAT_00124002,"ufshid_clear_flag",0xd5,0x83,iVar1);
        }
        lVar4 = *(long *)(lVar5 + 0x40);
        uVar2 = ktime_get_mono_fast_ns();
        *(undefined8 *)(lVar4 + 0x220) = uVar2;
        ufsf_rpm_put_noidle(lVar5);
      }
    }
  }
  else {
    lVar5 = param_1[0x237];
    pcVar3 = *(code **)(lVar5 + 0x18);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x11c99d85) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x118afc);
        (*pcVar3)();
      }
      iVar1 = (*pcVar3)(param_1);
      if (iVar1 != 0) goto LAB_00118b34;
      lVar5 = param_1[0x237];
    }
    if (*(int *)(*(code **)(lVar5 + 0x20) + -4) != -0x2973480b) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x118b30);
      (*pcVar3)();
    }
    (**(code **)(lVar5 + 0x20))(param_1,0,&local_3c);
  }
LAB_00118b34:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ufshid_auto_hibern8_enable @ 00118bf8 size=420
// signature: undefined ufshid_auto_hibern8_enable(void)
// callers: [ufshid_sysfs_store_auto_hibern8_enable, ufshid_trigger_on, ufshid_trigger_off]
//------------------------------------------------------------

void ufshid_auto_hibern8_enable(undefined8 *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long *plVar4;
  
  plVar4 = *(long **)*param_1;
  if (((*(char *)((long)plVar4 + 0x8a) < '\0') && ((*(byte *)((long)plVar4 + 0xcd) >> 3 & 1) == 0))
     || (*(int *)(param_1 + 0x14) != 0)) {
    __pm_runtime_resume(plVar4[9] + 0x1d8,4);
    ufshcd_hold(plVar4,0);
    ufsf_scsi_block_requests(plVar4);
    ufsf_wait_for_doorbell_clr(plVar4,0xffffffffffffffff);
    uVar3 = _raw_spin_lock_irqsave(*(undefined8 *)(plVar4[7] + 0x38));
    iVar1 = readl(*plVar4 + 0x18);
    _printk(&DAT_00120c57,"ufshid_auto_hibern8_enable",0x260,iVar1);
    if ((param_2 != 0) == (iVar1 != 0)) {
      _printk(&DAT_00121fd6,"ufshid_auto_hibern8_enable",0x27c,*(undefined1 *)((long)param_1 + 0xa4)
             );
    }
    else {
      if (param_2 == 0) {
        uVar2 = 0;
        *(int *)(param_1 + 0x14) = iVar1;
      }
      else {
        uVar2 = *(undefined4 *)(param_1 + 0x14);
      }
      *(undefined4 *)((long)plVar4 + 100) = uVar2;
      writel(uVar2,*plVar4 + 0x18);
      DataSynchronizationBarrier(3,3,0);
      _printk(&DAT_001249ef,"ufshid_auto_hibern8_enable",0x274,*(undefined1 *)((long)param_1 + 0xa4)
             );
      *(bool *)((long)param_1 + 0xa4) = param_2 != 0;
      uVar2 = readl(*plVar4 + 0x18);
      _printk(&DAT_001227e7,"ufshid_auto_hibern8_enable",0x279,*(undefined1 *)((long)param_1 + 0xa4)
              ,uVar2);
    }
    _raw_spin_unlock_irqrestore(*(undefined8 *)(plVar4[7] + 0x38),uVar3);
    ufsf_scsi_unblock_requests(plVar4);
    ufshcd_release(plVar4);
    ufsf_rpm_put_noidle(plVar4);
  }
  return;
}



//------------------------------------------------------------
// ufshid_allow_enter_suspend @ 00118d9c size=192
// signature: undefined ufshid_allow_enter_suspend(void)
// callers: [ufshid_trigger_off, ufshid_sysfs_store_block_suspend]
//------------------------------------------------------------

void ufshid_allow_enter_suspend(undefined8 *param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  if (*(char *)((long)param_1 + 0x1189) != '\0') {
    lVar2 = *(long *)*param_1;
    lVar3 = *(long *)(lVar2 + 0x48);
    *(undefined1 *)((long)param_1 + 0x1189) = 0;
    ufshcd_release(lVar2);
    ufsf_rpm_put_noidle(lVar2);
    uVar1 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(lVar2 + 0x38) + 0x38));
    if (*(char *)(param_1 + 0x231) != '\0') {
      _printk(&DAT_0012402f,"ufshid_allow_enter_suspend",0x2dc,*(undefined4 *)(param_1 + 1),
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc),*(undefined4 *)(lVar3 + 0x3d0),
              *(undefined4 *)(lVar2 + 0xbdc));
    }
    _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(lVar2 + 0x38) + 0x38),uVar1);
  }
  return;
}



//------------------------------------------------------------
// ufshid_read_attr_micron @ 00118e5c size=256
// signature: undefined ufshid_read_attr_micron(void)
// callers: [ufshid_sysfs_show_color, ufshid_issue_disable, micron_ufshid_trigger_work_fn]
//------------------------------------------------------------

int ufshid_read_attr_micron(undefined8 *param_1,undefined1 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)*param_1;
  __pm_runtime_resume(*(long *)(lVar2 + 0x48) + 0x1d8,4);
  iVar1 = ufshcd_query_attr_retry(lVar2,3,param_2,0,0,param_3);
  if (iVar1 == 0) {
    if (*(char *)(param_1 + 0x231) != '\0') {
      _printk(&DAT_001245d3,"ufshid_read_attr_micron",0xf0,*(undefined4 *)(param_1 + 1),
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc),param_2,*param_3,*param_3);
    }
  }
  else {
    _printk(&DAT_00121da0,"ufshid_read_attr_micron",0xeb,param_2,iVar1);
  }
  ufsf_rpm_put_noidle(lVar2);
  return iVar1;
}



//------------------------------------------------------------
// readl @ 00118f5c size=140
// signature: undefined readl(void)
// callers: [ufshid_auto_hibern8_enable]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x118fb4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00118fe8 size=136
// signature: undefined writel(void)
// callers: [ufshid_auto_hibern8_enable]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x119000,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x119040,uVar1);
  return;
}



//------------------------------------------------------------
// ufshid_execute_query_op_and_frag_chk @ 00119074 size=196
// signature: undefined ufshid_execute_query_op_and_frag_chk(void)
// callers: []
//------------------------------------------------------------

undefined8
ufshid_execute_query_op_and_frag_chk(undefined8 *param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = ufshid_write_attr(param_1,0,param_2);
  if (iVar2 == 0) {
    msleep(200);
    iVar2 = ufshid_read_attr(param_1,2,param_3);
    if (iVar2 == 0) {
      if (*(char *)(param_1 + 0x231) != '\0') {
        uVar1 = *param_3;
        _printk(&DAT_00120035,"ufshid_execute_query_op_and_frag_chk",0x18c,
                *(undefined4 *)(param_1 + 1),
                *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*param_1 + 0xbdc),uVar1 & 0xf,uVar1 >> 0x1d & 1,
                uVar1 >> 0x1e & 1,uVar1 >> 0x1f);
      }
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// ufshid_get_analyze_and_in_work @ 0011913c size=460
// signature: undefined ufshid_get_analyze_and_in_work(void)
// callers: []
//------------------------------------------------------------

bool ufshid_get_analyze_and_in_work(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  bool bVar5;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = param_1[0x237];
  local_3c = 0;
  pcVar4 = *(code **)(lVar3 + 0x18);
  if (pcVar4 == (code *)0x0) {
LAB_001191a8:
    if (*(int *)(*(code **)(lVar3 + 0x20) + -4) != -0x2973480b) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1191d0);
      (*pcVar4)();
    }
    uVar1 = (**(code **)(lVar3 + 0x20))(param_1,2,&local_3c);
    if (uVar1 != 0) goto LAB_00119210;
    if (((local_3c & 0xf) != 0) &&
       ((*(char *)(param_1 + 0x21b) == '\0' ||
        (*(bool *)((long)param_1 + 0x10e1) = (local_3c & 0x20000000) == 0,
        (local_3c >> 0x1d & 1) != 0)))) {
      uVar1 = local_3c >> 0x1f;
      goto LAB_00119210;
    }
    uVar1 = 0xfffffff5;
    bVar5 = true;
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x11c99d85) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x119198);
      (*pcVar4)();
    }
    uVar1 = (*pcVar4)(param_1);
    if (uVar1 == 0) {
      lVar3 = param_1[0x237];
      goto LAB_001191a8;
    }
LAB_00119210:
    bVar5 = uVar1 == 0xfffffff5 || uVar1 == 1;
    if ((uVar1 != 1) && (uVar1 != 0xfffffff5)) {
      if (*(char *)(param_1 + 0x231) != '\0') {
        _printk(&DAT_00120c74,"ufshid_get_analyze_and_in_work",0x425,*(undefined4 *)(param_1 + 1),
                *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*param_1 + 0xbdc));
      }
      iVar2 = ufshid_trigger_off(param_1);
      if (iVar2 != 0) {
        _printk(&DAT_00120cb8,"ufshid_get_analyze_and_in_work",0x429);
      }
      goto LAB_00119284;
    }
  }
  if (*(char *)(param_1 + 0x231) != '\0') {
    _printk(&DAT_00121097,"ufshid_get_analyze_and_in_work",0x421,*(undefined4 *)(param_1 + 1),
            *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
            *(undefined4 *)(*(long *)*param_1 + 0xbdc),uVar1,*(undefined4 *)(param_1 + 0x13));
  }
LAB_00119284:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar5;
}



//------------------------------------------------------------
// ufshid_check_file_info_buf_2_0 @ 0011930c size=460
// signature: undefined ufshid_check_file_info_buf_2_0(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_check_file_info_buf_2_0(long param_1,byte *param_2,undefined2 param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  ulong *puVar12;
  
  _printk(&DAT_00120086,"ufshid_check_file_info_buf_2_0",0x33b,param_3);
  bVar1 = *param_2;
  uVar10 = (uint)bVar1;
  if ((bVar1 == 0) ||
     ((uint)*(byte *)(param_1 + 0x10e0) <= (uint)bVar1 &&
      (uint)bVar1 != (uint)*(byte *)(param_1 + 0x10e0))) {
    puVar6 = &DAT_001237bd;
    uVar5 = 0x341;
LAB_00119460:
    _printk(puVar6,"ufshid_check_file_info_buf_2_0",uVar5,uVar10);
    uVar5 = 0xffffffea;
  }
  else {
    uVar10 = 0;
    puVar12 = (ulong *)(param_2 + 8);
    do {
      uVar11 = (uint)puVar12[1];
      uVar4 = (*puVar12 & 0xff00ff00ff00ff00) >> 8 | (*puVar12 & 0xff00ff00ff00ff) << 8;
      uVar4 = (uVar4 & 0xffff0000ffff0000) >> 0x10 | (uVar4 & 0xffff0000ffff) << 0x10;
      uVar2 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
      uVar2 = uVar2 >> 0x10 | uVar2 << 0x10;
      _printk(&DAT_00122d3c,"ufshid_check_file_info_buf_2_0",0x351,uVar10,uVar4 >> 0x20,uVar2);
      if ((uVar11 == 0) || (uVar11 = (uint)(uVar4 >> 0x20), uVar11 == 0)) {
        puVar6 = &DAT_001200a1;
        uVar5 = 0x354;
        goto LAB_00119460;
      }
      if (*(uint *)(param_1 + 0x10dc) < uVar2) {
        _printk(&DAT_00123077,"ufshid_check_file_info_buf_2_0",0x35a,uVar10,uVar2);
        return 0xffffffea;
      }
      if (uVar10 != 0) {
        puVar9 = (uint *)(param_2 + 0x10);
        uVar8 = uVar10;
        do {
          uVar4 = (*(ulong *)(puVar9 + -2) & 0xff00ff00ff00ff00) >> 8 |
                  (*(ulong *)(puVar9 + -2) & 0xff00ff00ff00ff) << 8;
          uVar7 = (uint)(ushort)(uVar4 >> 0x30) | (uint)(uVar4 >> 0x10) & 0xffff0000;
          if ((uVar7 <= (uVar11 + uVar2) - 1) &&
             (uVar3 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8,
             uVar11 <= (uVar7 + (uVar3 >> 0x10 | uVar3 << 0x10)) - 1)) {
            _printk(&DAT_00121364,"ufshid_check_file_info_buf_2_0",0x368,uVar11,uVar2);
            return 0xffffffea;
          }
          puVar9 = puVar9 + 3;
          uVar8 = uVar8 - 1;
        } while (uVar8 != 0);
      }
      uVar10 = uVar10 + 1;
      puVar12 = (ulong *)((long)puVar12 + 0xc);
    } while (uVar10 != bVar1);
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// ufshid_issue_lba_list @ 001194dc size=636
// signature: undefined ufshid_issue_lba_list(void)
// callers: [ufshid_sysfs_show_color, ufshid_hid_progress_chk_in_work, ufshid_sysfs_show_l2p_frag_lvl]
//------------------------------------------------------------

int ufshid_issue_lba_list(long *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ushort local_40;
  long local_38;
  
  lVar4 = sp_el0;
  iVar3 = 0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_68 = &local_50;
  local_40 = 0;
  local_50 = 0;
  local_48 = 0;
  uStack_60 = 0;
  local_58 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((char)param_1[0x21b] != '\0') {
    lVar4 = param_1[0x216];
    if (lVar4 == 0) {
      _printk(&DAT_00121dcc,"ufshid_issue_lba_list",0x158,0);
      iVar3 = -0x16;
    }
    else {
      if (7 < *(uint *)((long)param_1 + 0xac)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x119758);
        (*pcVar2)();
      }
      lVar5 = *(long *)(*param_1 + (ulong)*(uint *)((long)param_1 + 0xac) * 8 + 0x10);
      if (lVar5 == 0) {
        _printk(&DAT_00121678,"ufshid_issue_lba_list",0x15e);
        iVar3 = -0x13;
      }
      else {
        plVar1 = param_1 + 0x16;
        local_48 = CONCAT17((char)((ulong)lVar4 >> 8),CONCAT16((char)((ulong)lVar4 >> 0x10),0x1d3b))
        ;
        local_40 = (ushort)(byte)lVar4;
        iVar3 = scsi_execute_cmd(lVar5,&local_48,0x23,plVar1,lVar4,0x1d4c,0,&local_78);
        if (iVar3 != 0) {
          _printk(&DAT_00121df8,"ufshid_issue_lba_list",0x16a,iVar3,0);
          iVar3 = scsi_execute_cmd(lVar5,&local_48,0x23,plVar1,(int)param_1[0x216],0x1d4c,0,
                                   &local_78);
          if (iVar3 != 0) {
            _printk(&DAT_00121df8,"ufshid_issue_lba_list",0x16a,iVar3,1);
            iVar3 = scsi_execute_cmd(lVar5,&local_48,0x23,plVar1,(int)param_1[0x216],0x1d4c,0,
                                     &local_78);
            if (iVar3 != 0) {
              _printk(&DAT_00121df8,"ufshid_issue_lba_list",0x16a,iVar3,2);
              _printk(&DAT_001242ea,"ufshid_issue_lba_list",0x16f,"failed");
              _printk(&DAT_001200ca,"ufshid_issue_lba_list",0x174,local_50 & 0xff,local_50._1_1_,
                      local_50._2_1_,local_50._3_1_);
              _printk(&DAT_001222cd,"ufshid_issue_lba_list",0x177,local_50._4_1_,local_50._5_1_,
                      local_50._6_1_,local_50._7_1_);
              goto LAB_0011952c;
            }
          }
        }
        _printk(&DAT_001242ea,"ufshid_issue_lba_list",0x16f,"success");
        iVar3 = 0;
      }
    }
  }
LAB_0011952c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// ufshid_check_file_info_buf_3_0 @ 0011975c size=452
// signature: undefined ufshid_check_file_info_buf_3_0(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_check_file_info_buf_3_0(long param_1,uint *param_2,undefined2 param_3)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  undefined8 uVar7;
  undefined *puVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  
  _printk(&DAT_00120086,"ufshid_check_file_info_buf_3_0",0x37c,param_3);
  bVar2 = (byte)*param_2;
  uVar11 = (uint)bVar2;
  if ((bVar2 == 0) ||
     ((uint)*(byte *)(param_1 + 0x10e0) <= (uint)bVar2 &&
      (uint)bVar2 != (uint)*(byte *)(param_1 + 0x10e0))) {
    puVar8 = &DAT_001237bd;
    uVar7 = 0x382;
LAB_001198a8:
    _printk(puVar8,"ufshid_check_file_info_buf_3_0",uVar7,uVar11);
    uVar7 = 0xffffffea;
  }
  else {
    uVar11 = 0;
    puVar6 = param_2;
    do {
      uVar9 = puVar6[2];
      uVar1 = puVar6[3];
      uVar3 = (uVar9 & 0xff00ff00) >> 8 | (uVar9 & 0xff00ff) << 8;
      uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
      uVar4 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      uVar4 = uVar4 >> 0x10 | uVar4 << 0x10;
      _printk(&DAT_00122d3c,"ufshid_check_file_info_buf_3_0",0x392,uVar11,uVar3,uVar4);
      if ((uVar9 == 0) || (uVar1 == 0)) {
        puVar8 = &DAT_001200a1;
        uVar7 = 0x395;
        goto LAB_001198a8;
      }
      if (*(uint *)(param_1 + 0x10dc) < uVar4) {
        _printk(&DAT_00123077,"ufshid_check_file_info_buf_3_0",0x39b,uVar11,uVar4);
        return 0xffffffea;
      }
      if (uVar11 != 0) {
        puVar10 = param_2 + 3;
        uVar9 = uVar11;
        do {
          uVar1 = (puVar10[-1] & 0xff00ff00) >> 8 | (puVar10[-1] & 0xff00ff) << 8;
          uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
          if ((uVar1 <= (uVar3 + uVar4) - 1) &&
             (uVar5 = (*puVar10 & 0xff00ff00) >> 8 | (*puVar10 & 0xff00ff) << 8,
             uVar3 <= (uVar1 + (uVar5 >> 0x10 | uVar5 << 0x10)) - 1)) {
            _printk(&DAT_00121364,"ufshid_check_file_info_buf_3_0",0x3a9,uVar3,uVar4);
            return 0xffffffea;
          }
          puVar10 = puVar10 + 2;
          uVar9 = uVar9 - 1;
        } while (uVar9 != 0);
      }
      uVar11 = uVar11 + 1;
      puVar6 = puVar6 + 2;
    } while (uVar11 != bVar2);
    uVar7 = 0;
  }
  return uVar7;
}



//------------------------------------------------------------
// ufshid_execute_query_hid_op @ 00119924 size=64
// signature: undefined ufshid_execute_query_hid_op(void)
// callers: []
//------------------------------------------------------------

void ufshid_execute_query_hid_op(long param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 2;
    if (*(char *)(param_1 + 0x10d8) != '\0') {
      uVar1 = 3;
    }
  }
  ufshid_write_attr(param_1,0,uVar1);
  return;
}



//------------------------------------------------------------
// ufshid_hid_progress_chk_in_work @ 00119968 size=712
// signature: undefined ufshid_hid_progress_chk_in_work(void)
// callers: []
//------------------------------------------------------------

void ufshid_hid_progress_chk_in_work(undefined8 *param_1)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  local_3c = 0;
  iVar3 = ufshid_read_attr(param_1,8,&local_3c);
  pcVar1 = (char *)(param_1 + 0x231);
  if (*pcVar1 == '\0') {
    if (iVar3 != 0) goto LAB_00119a18;
LAB_001199bc:
    if ((local_3c & 0xfffffffd) != 1) goto LAB_00119a18;
    if (*pcVar1 != '\0') {
      _printk(&DAT_0011fbd5,"ufshid_hid_progress_chk_in_work",0x3f7,*(undefined4 *)(param_1 + 1),
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc),*(undefined4 *)(param_1 + 0x13));
      uVar4 = 1;
      goto LAB_00119be0;
    }
  }
  else {
    _printk(&DAT_00121d58,"ufshid_is_in_progress",0x23a,*(undefined4 *)(param_1 + 1),
            *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
            *(undefined4 *)(*(long *)*param_1 + 0xbdc),iVar3,local_3c);
    if (iVar3 == 0) goto LAB_001199bc;
LAB_00119a18:
    iVar3 = ufshid_read_attr(param_1,7,&local_40);
    if (((iVar3 != 0) || (local_40 == 0)) || (local_40 == 100)) {
      if (*pcVar1 != '\0') {
        _printk(&DAT_00120d07,"ufshid_hid_progress_chk_in_work",0x403,*(undefined4 *)(param_1 + 1),
                *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                *(undefined4 *)(*(long *)*param_1 + 0xbdc),iVar3,*(undefined4 *)(param_1 + 1));
      }
      ufshid_issue_disable(param_1);
      msleep(200);
      local_3c = 0;
      iVar3 = ufshid_issue_lba_list(param_1);
      if ((iVar3 == 0) && (iVar3 = ufshid_write_attr(param_1,0,1), iVar3 == 0)) {
        msleep(200);
        iVar3 = ufshid_read_attr(param_1,8,&local_3c);
        if (iVar3 == 0) {
          if (local_3c == 2) {
            iVar3 = ufshid_read_attr(param_1,2,&local_40);
            if ((iVar3 == 0) && (*pcVar1 != '\0')) {
              _printk(&DAT_00120035,"ufshid_hid_progress_chk_in_work",0x40f,
                      *(undefined4 *)(param_1 + 1),
                      *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                      *(undefined4 *)(*(long *)*param_1 + 0xbdc),local_40 & 0xf,local_40 >> 0x1d & 1
                      ,local_40 >> 0x1e & 1,local_40 >> 0x1f);
            }
          }
          else {
            local_40 = 1;
          }
        }
      }
      uVar4 = ufshid_trigger_off(param_1);
      if ((int)uVar4 != 0) {
        _printk(&DAT_00120cb8,"ufshid_hid_progress_chk_in_work",0x414);
        uVar4 = 0;
      }
      goto LAB_00119be0;
    }
    if (*pcVar1 != '\0') {
      _printk(&DAT_001213ac,"ufshid_hid_progress_chk_in_work",0x3ff,*(undefined4 *)(param_1 + 1),
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc),0,*(undefined4 *)(param_1 + 0x13));
      uVar4 = 1;
      goto LAB_00119be0;
    }
  }
  uVar4 = 1;
LAB_00119be0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_show_version @ 00119c34 size=136
// signature: undefined ufshid_sysfs_show_version(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_version(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_0012487e,"ufshid_sysfs_show_version",0x5d9,*(undefined4 *)(param_1 + 0x11b0),0x30401,
          &DAT_001212c5);
  iVar1 = snprintf(param_2,0x1000,"HID version (%.4X) D/D version (%.6X%s)\n",
                   *(uint *)(param_1 + 0x11b0),0x30401,"");
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_show_color @ 00119cc0 size=812
// signature: undefined ufshid_sysfs_show_color(void)
// callers: []
//------------------------------------------------------------

void ufshid_sysfs_show_color(undefined8 *param_1,char *param_2)

{
  char *pcVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  code *pcVar8;
  uint uVar9;
  uint local_50;
  int local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  if (*(short *)(*(long *)*param_1 + 0xa14) == 300) {
    local_4c = 0;
    iVar4 = ufshid_read_attr_micron(param_1,0x81,&local_4c);
    if (iVar4 != 0) goto LAB_00119d90;
    pcVar1 = "RED";
    if (local_4c != 1) {
      pcVar1 = "UNKNOWN";
    }
    pcVar6 = "GREEN";
    if (local_4c != 0) {
      pcVar6 = pcVar1;
    }
LAB_00119e80:
    iVar4 = snprintf(param_2,0x1000,"%s\n",pcVar6);
    lVar5 = (long)iVar4;
  }
  else {
    if (*(short *)(*(long *)*param_1 + 0xa14) != 0x1ce) {
LAB_00119d90:
      lVar5 = -0x16;
      goto LAB_00119f34;
    }
    local_50 = 0;
    if (*(int *)(param_1 + 1) != 0) {
      _printk(&DAT_0012061b,"do_ufshid_sysfs_show_color_samsung",0x737);
      lVar5 = 8;
      param_2[8] = '\0';
      *(undefined8 *)param_2 = s_YELLOW_001210f8._0_8_;
      goto LAB_00119f34;
    }
    uVar7 = *(uint *)(param_1 + 0x236);
    if ((uVar7 & 0xf00) < 0x300) {
      lVar5 = param_1[0x237];
      pcVar8 = *(code **)(lVar5 + 0x18);
      if (pcVar8 == (code *)0x0) {
LAB_00119dcc:
        if (*(int *)(*(code **)(lVar5 + 0x20) + -4) != -0x2973480b) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x119df4);
          (*pcVar8)();
        }
        iVar4 = (**(code **)(lVar5 + 0x20))(param_1,1,&local_50);
        if (iVar4 == 0) {
          uVar9 = local_50 & 0xf;
          if ((uVar7 & 0xf00) != 0x100) goto LAB_00119e0c;
LAB_00119e3c:
          if (uVar9 < 4) {
            pcVar6 = (&PTR_DAT_0011c8e0)[uVar9];
            goto LAB_00119e80;
          }
          goto LAB_00119e9c;
        }
      }
      else {
        if (*(int *)(pcVar8 + -4) != 0x11c99d85) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x8229,0x119dc0);
          (*pcVar8)();
        }
        iVar4 = (*pcVar8)(param_1);
        if (iVar4 == 0) {
          lVar5 = param_1[0x237];
          goto LAB_00119dcc;
        }
      }
    }
    else {
      local_4c = 0;
      iVar4 = ufshid_issue_lba_list(param_1);
      uVar7 = 0;
      if (iVar4 == 0) {
        iVar4 = ufshid_write_attr(param_1,0,1);
        uVar7 = 0;
        if (iVar4 == 0) {
          msleep(200);
          iVar4 = ufshid_read_attr(param_1,8,&local_4c);
          if (iVar4 != 0) {
            uVar7 = 0;
            goto LAB_00119f10;
          }
          if (local_4c != 2) {
            uVar7 = 1;
            local_50 = 1;
            goto LAB_00119f10;
          }
          iVar4 = ufshid_read_attr(param_1,2,&local_50);
          uVar7 = local_50;
          if (iVar4 != 0) goto LAB_00119f10;
          uVar9 = local_50 & 0xf;
LAB_00119e0c:
          uVar7 = local_50 & 0x20000000;
          if (*(char *)(param_1 + 0x231) != '\0') {
            _printk(&DAT_00120035,"do_ufshid_sysfs_show_color_samsung",0x759,
                    *(undefined4 *)(param_1 + 1),
                    *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
                    *(undefined4 *)(*(long *)*param_1 + 0xbdc),uVar9,uVar7 >> 0x1d,
                    local_50 >> 0x1e & 1,local_50 >> 0x1f);
          }
          if ((uVar7 == 0) != (*(char *)(param_1 + 0x21b) != '\0')) goto LAB_00119e3c;
LAB_00119e9c:
          pcVar6 = "UNKNOWN";
          goto LAB_00119e80;
        }
      }
LAB_00119f10:
      if (uVar7 == 1) {
        _printk(&DAT_00124a1a,"do_ufshid_sysfs_show_color_samsung",0x743);
        lVar5 = 6;
        builtin_strncpy(param_2,"GREEN\n",7);
        goto LAB_00119f34;
      }
    }
    lVar5 = 0xe;
    uVar3 = CONCAT71(s_UNKOWN__Error_00124307._8_7_,s_UNKOWN__Error_00124307[7]);
    *(ulong *)param_2 = CONCAT17(s_UNKOWN__Error_00124307[7],s_UNKOWN__Error_00124307._0_7_);
    *(undefined8 *)(param_2 + 7) = uVar3;
  }
LAB_00119f34:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_show_trigger @ 00119ff0 size=96
// signature: undefined ufshid_sysfs_show_trigger(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_trigger(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_00124316,"ufshid_sysfs_show_trigger",0x5e2,*(undefined4 *)(param_1 + 8));
  iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(uint *)(param_1 + 8));
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_store_trigger @ 0011a054 size=232
// signature: undefined ufshid_sysfs_store_trigger(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_store_trigger(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull(param_2,0,&local_30);
  if ((iVar2 == 0) && (local_30 < 2)) {
    _printk(&DAT_00120ade,"ufshid_sysfs_store_trigger",0x5f3);
    if (local_30 != *(uint *)(param_1 + 8)) {
      if (local_30 == 0) {
        iVar2 = ufshid_trigger_off(param_1);
      }
      else {
        iVar2 = ufshid_trigger_on();
      }
      if (iVar2 != 0) {
        param_3 = (long)iVar2;
        _printk(&DAT_001240bd,"ufshid_sysfs_store_trigger",0x5fe,local_30,param_3);
      }
    }
  }
  else {
    param_3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_trigger_interval @ 0011a140 size=96
// signature: undefined ufshid_sysfs_show_trigger_interval(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_trigger_interval(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_001225db,"ufshid_sysfs_show_trigger_interval",0x608,*(undefined4 *)(param_1 + 0x98));
  iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(uint *)(param_1 + 0x98));
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_store_trigger_interval @ 0011a1a4 size=208
// signature: undefined ufshid_sysfs_store_trigger_interval(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_sysfs_store_trigger_interval(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_2,0,&local_2c);
  if (iVar2 == 0) {
    if (0xffffd952 < local_2c - 0x2711U) {
      *(int *)(param_1 + 0x98) = local_2c;
      _printk(&DAT_001225db,"ufshid_sysfs_store_trigger_interval",0x61f);
      goto LAB_0011a1e8;
    }
    _printk(&DAT_00123d2c,"ufshid_sysfs_store_trigger_interval",0x61a,100,10000);
  }
  param_3 = 0xffffffffffffffea;
LAB_0011a1e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_on_idle_delay @ 0011a278 size=96
// signature: undefined ufshid_sysfs_show_on_idle_delay(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_on_idle_delay(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_00123344,"ufshid_sysfs_show_on_idle_delay",0x627,*(undefined4 *)(param_1 + 0x9c));
  iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(uint *)(param_1 + 0x9c));
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_store_on_idle_delay @ 0011a2dc size=208
// signature: undefined ufshid_sysfs_store_on_idle_delay(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_sysfs_store_on_idle_delay(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_2,0,&local_2c);
  if (iVar2 == 0) {
    if (0xffffd8f8 < local_2c - 0x2711U) {
      *(int *)(param_1 + 0x9c) = local_2c;
      _printk(&DAT_00123344,"ufshid_sysfs_store_on_idle_delay",0x63d);
      goto LAB_0011a320;
    }
    _printk(&DAT_00121101,"ufshid_sysfs_store_on_idle_delay",0x638,10,10000);
  }
  param_3 = 0xffffffffffffffea;
LAB_0011a320:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_lba_trigger_mode @ 0011a3b0 size=136
// signature: undefined ufshid_sysfs_show_lba_trigger_mode(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_lba_trigger_mode(undefined8 *param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(short *)(*(long *)*param_1 + 0xa14) == 0x1ce) {
    _printk(&DAT_00120344,"ufshid_sysfs_show_lba_trigger_mode",0x67c,
            *(undefined1 *)(param_1 + 0x21b));
    iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(byte *)(param_1 + 0x21b));
    lVar2 = (long)iVar1;
  }
  else {
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// ufshid_sysfs_store_lba_trigger_mode @ 0011a43c size=276
// signature: undefined ufshid_sysfs_store_lba_trigger_mode(void)
// callers: []
//------------------------------------------------------------

undefined8
ufshid_sysfs_store_lba_trigger_mode(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (((*(short *)(*(long *)*param_1 + 0xa14) == 0x1ce) &&
      (iVar2 = kstrtoull(param_2,0,&local_30), iVar2 == 0)) && (local_30 < 2)) {
    if (*(int *)(param_1 + 1) == 0) {
      if (*(char *)(param_1 + 0x21d) == '\0') {
        _printk(&DAT_001216a3,"ufshid_sysfs_store_lba_trigger_mode",0x698);
        param_3 = 0xffffffffffffffff;
      }
      else if (local_30 == 0) {
        *(undefined1 *)(param_1 + 0x21b) = 0;
        memset(param_1 + 0x15,0,0x1030);
      }
      else {
        *(undefined1 *)(param_1 + 0x21b) = 1;
      }
    }
    else {
      _printk(&DAT_0012061b,"ufshid_sysfs_store_lba_trigger_mode",0x693);
      param_3 = 0xfffffffffffffff0;
    }
  }
  else {
    param_3 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_max_lba_range_size @ 0011a554 size=148
// signature: undefined ufshid_sysfs_show_max_lba_range_size(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_max_lba_range_size(long param_1,char *param_2)

{
  uint uVar1;
  int iVar2;
  char *__format;
  
  if ((*(uint *)(param_1 + 0x11b0) & 0xe00) == 0) {
    _printk(&DAT_0011fdfc,"ufshid_sysfs_show_max_lba_range_size",0x792);
    uVar1 = *(uint *)(param_1 + 0x11b0);
    __format = "hid ver %.4x\n";
  }
  else {
    _printk(&DAT_001220a9,"ufshid_sysfs_show_max_lba_range_size",0x796,
            *(undefined4 *)(param_1 + 0x10dc));
    uVar1 = *(uint *)(param_1 + 0x10dc);
    __format = "%u\n";
  }
  iVar2 = snprintf(param_2,0x1000,__format,(ulong)uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// ufshid_sysfs_show_max_lba_range_cnt @ 0011a5ec size=160
// signature: undefined ufshid_sysfs_show_max_lba_range_cnt(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_max_lba_range_cnt(long param_1,char *param_2)

{
  int iVar1;
  char *__format;
  ulong uVar2;
  
  if ((*(uint *)(param_1 + 0x11b0) & 0xe00) == 0) {
    _printk(&DAT_0011fdfc,"ufshid_sysfs_show_max_lba_range_cnt",0x79e);
    uVar2 = (ulong)*(uint *)(param_1 + 0x11b0);
    __format = "hid ver %.4x\n";
  }
  else {
    _printk(&DAT_0011fc27,"ufshid_sysfs_show_max_lba_range_cnt",0x7a2,
            *(undefined1 *)(param_1 + 0x10e0));
    uVar2 = (ulong)*(byte *)(param_1 + 0x10e0);
    __format = "%u\n";
  }
  iVar1 = snprintf(param_2,0x1000,__format,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_show_l2p_frag_lvl @ 0011a690 size=640
// signature: undefined ufshid_sysfs_show_l2p_frag_lvl(void)
// callers: []
//------------------------------------------------------------

void ufshid_sysfs_show_l2p_frag_lvl(undefined8 *param_1,char *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  char *__format;
  uint uVar7;
  uint local_30;
  int local_2c;
  long local_28;
  
  lVar6 = sp_el0;
  local_28 = *(long *)(lVar6 + 0x638);
  local_30 = 0;
  if (*(short *)(*(long *)*param_1 + 0xa14) != 0x1ce) {
    lVar6 = -0x16;
    goto LAB_0011a760;
  }
  if ((*(uint *)(param_1 + 0x236) & 0xf00) < 0x300) {
    _printk(&DAT_0011fdfc,"ufshid_sysfs_show_l2p_frag_lvl",0x6af);
    uVar7 = *(uint *)(param_1 + 0x236);
    __format = "hid ver %.4x\n";
LAB_0011a7ac:
    iVar5 = snprintf(param_2,0x1000,__format,(ulong)uVar7);
  }
  else {
    if (*(char *)(param_1 + 0x21b) == '\0') {
      _printk(&DAT_001216ce,"ufshid_sysfs_show_l2p_frag_lvl",0x6b4);
      lVar6 = 0xd;
      uVar2 = CONCAT62(s_L2P_DISABLED_001240f3._8_6_,s_L2P_DISABLED_001240f3._6_2_);
      *(ulong *)param_2 = CONCAT26(s_L2P_DISABLED_001240f3._6_2_,s_L2P_DISABLED_001240f3._0_6_);
      *(undefined8 *)(param_2 + 6) = uVar2;
      goto LAB_0011a760;
    }
    if (param_1[0x216] == 0) {
      _printk(&DAT_001220ce,"ufshid_sysfs_show_l2p_frag_lvl",0x6b9);
      lVar6 = 0xc;
      uVar2 = CONCAT53(s_PARAM_EMPTY_001230b0._8_5_,s_PARAM_EMPTY_001230b0._5_3_);
      *(ulong *)param_2 = CONCAT35(s_PARAM_EMPTY_001230b0._5_3_,s_PARAM_EMPTY_001230b0._0_5_);
      *(undefined8 *)(param_2 + 5) = uVar2;
      goto LAB_0011a760;
    }
    if (*(int *)(param_1 + 1) != 0) {
      _printk(&DAT_0012061b,"ufshid_sysfs_show_l2p_frag_lvl",0x6be);
      lVar6 = 0xe;
      uVar2 = CONCAT71(s_NOT_PERMITTED_00124647._8_7_,s_NOT_PERMITTED_00124647[7]);
      *(ulong *)param_2 = CONCAT17(s_NOT_PERMITTED_00124647[7],s_NOT_PERMITTED_00124647._0_7_);
      *(undefined8 *)(param_2 + 7) = uVar2;
      goto LAB_0011a760;
    }
    local_2c = 0;
    iVar5 = ufshid_issue_lba_list(param_1);
    if (iVar5 == 0) {
      iVar5 = ufshid_write_attr(param_1,0,1);
      if (iVar5 == 0) {
        msleep(200);
        iVar5 = ufshid_read_attr(param_1,8,&local_2c);
        if (iVar5 == 0) {
          if (local_2c == 2) {
            iVar5 = ufshid_read_attr(param_1,9,&local_30);
            if (iVar5 == 0) {
              ufshid_issue_disable(param_1);
              _printk(&DAT_00123368,"ufshid_sysfs_show_l2p_frag_lvl",0x6d1,local_30);
              __format = "%u\n";
              uVar7 = local_30;
              goto LAB_0011a7ac;
            }
            uVar7 = local_30;
          }
          else {
            uVar7 = 1;
            iVar5 = -0x16;
            local_30 = 1;
          }
          goto LAB_0011a754;
        }
      }
      iVar5 = -0x16;
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
    }
LAB_0011a754:
    if (uVar7 == 1) {
      _printk(&DAT_00124a1a,"ufshid_sysfs_show_l2p_frag_lvl",0x6c7);
      param_2[0x20] = '\0';
      uVar4 = s_UNKNOWN__Defrag_is_not_required_00120113._24_8_;
      uVar3 = s_UNKNOWN__Defrag_is_not_required_00120113._16_8_;
      uVar2 = s_UNKNOWN__Defrag_is_not_required_00120113._8_8_;
      lVar6 = 0x20;
      *(undefined8 *)param_2 = s_UNKNOWN__Defrag_is_not_required_00120113._0_8_;
      *(undefined8 *)(param_2 + 8) = uVar2;
      *(undefined8 *)(param_2 + 0x10) = uVar3;
      *(undefined8 *)(param_2 + 0x18) = uVar4;
      goto LAB_0011a760;
    }
  }
  lVar6 = (long)iVar5;
LAB_0011a760:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_show_l2p_defrag_threshold @ 0011a914 size=192
// signature: undefined ufshid_sysfs_show_l2p_defrag_threshold(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_l2p_defrag_threshold(undefined8 *param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  char *__format;
  ulong uVar3;
  
  if (*(short *)(*(long *)*param_1 + 0xa14) == 0x1ce) {
    if ((*(uint *)(param_1 + 0x236) & 0xf00) < 0x300) {
      _printk(&DAT_0011fdfc,"ufshid_sysfs_show_l2p_defrag_threshold",0x6e0);
      uVar3 = (ulong)*(uint *)(param_1 + 0x236);
      __format = "hid ver %.4x\n";
    }
    else {
      _printk(&DAT_0012381e,"ufshid_sysfs_show_l2p_defrag_threshold",0x6e4,
              *(undefined1 *)((long)param_1 + 0x10e9));
      uVar3 = (ulong)*(byte *)((long)param_1 + 0x10e9);
      __format = "%u\n";
    }
    iVar1 = snprintf(param_2,0x1000,__format,uVar3);
    lVar2 = (long)iVar1;
  }
  else {
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// ufshid_sysfs_store_l2p_defrag_threshold @ 0011a9d8 size=268
// signature: undefined ufshid_sysfs_store_l2p_defrag_threshold(void)
// callers: []
//------------------------------------------------------------

undefined8
ufshid_sysfs_store_l2p_defrag_threshold(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  byte local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  if (*(short *)(*(long *)*param_1 + 0xa14) == 0x1ce) {
    if ((*(uint *)(param_1 + 0x236) & 0xf00) < 0x300) {
      _printk(&DAT_0011fdfc,"ufshid_sysfs_store_l2p_defrag_threshold",0x6f5);
    }
    else {
      iVar2 = kstrtou8(param_2,0,local_3c);
      if ((((iVar2 == 0) && (*(char *)(param_1 + 0x21d) != '\0')) && (local_3c[0] < 0xb)) &&
         (iVar2 = ufshid_write_attr(param_1,10), iVar2 == 0)) {
        *(byte *)((long)param_1 + 0x10e9) = local_3c[0];
        _printk(&DAT_0012381e,"ufshid_sysfs_store_l2p_defrag_threshold",0x708);
        goto LAB_0011aa44;
      }
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_0011aa44:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_l2p_param_print @ 0011aae8 size=80
// signature: undefined ufshid_sysfs_show_l2p_param_print(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_l2p_param_print(long param_1,char *param_2)

{
  int iVar1;
  
  ufsf_print_query_buf(param_1 + 0xb0,*(undefined4 *)(param_1 + 0x10b0));
  iVar1 = snprintf(param_2,0x1000,"%s\n",param_1 + 0xb0);
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_show_progress_ratio @ 0011ab3c size=228
// signature: undefined ufshid_sysfs_show_progress_ratio(void)
// callers: []
//------------------------------------------------------------

void ufshid_sysfs_show_progress_ratio(long param_1,char *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  char *__format;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  if ((*(uint *)(param_1 + 0x11b0) & 0xf00) < 0x300) {
    _printk(&DAT_0011fdfc,"ufshid_sysfs_show_progress_ratio",0x7ab);
    uVar1 = *(uint *)(param_1 + 0x11b0);
    __format = "hid ver %.4x\n";
  }
  else {
    iVar3 = ufshid_read_attr(param_1,7,&local_2c);
    if (iVar3 != 0) {
      lVar4 = -0x16;
      goto LAB_0011ab90;
    }
    _printk(&DAT_001216fa,"ufshid_sysfs_show_progress_ratio",0x7b2,local_2c);
    __format = "%u\n";
    uVar1 = local_2c;
  }
  iVar3 = snprintf(param_2,0x1000,__format,(ulong)uVar1);
  lVar4 = (long)iVar3;
LAB_0011ab90:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_show_available_size @ 0011ac24 size=228
// signature: undefined ufshid_sysfs_show_available_size(void)
// callers: []
//------------------------------------------------------------

void ufshid_sysfs_show_available_size(long param_1,char *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  char *__format;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  if ((*(uint *)(param_1 + 0x11b0) & 0xf00) < 0x300) {
    _printk(&DAT_0011fdfc,"ufshid_sysfs_show_available_size",0x7bb);
    uVar1 = *(uint *)(param_1 + 0x11b0);
    __format = "hid ver %.4x\n";
  }
  else {
    iVar3 = ufshid_read_attr(param_1,6,&local_2c);
    if (iVar3 != 0) {
      lVar4 = -0x16;
      goto LAB_0011ac78;
    }
    _printk(&DAT_0011fe2b,"ufshid_sysfs_show_available_size",0x7c2,local_2c);
    __format = "%u\n";
    uVar1 = local_2c;
  }
  iVar3 = snprintf(param_2,0x1000,__format,(ulong)uVar1);
  lVar4 = (long)iVar3;
LAB_0011ac78:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_show_hid_size @ 0011ad0c size=200
// signature: undefined ufshid_sysfs_show_hid_size(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_hid_size(undefined8 *param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(short *)(*(long *)*param_1 + 0xa14) == 0x1ce) {
    if ((*(uint *)(param_1 + 0x236) & 0xf00) < 0x300) {
      _printk(&DAT_0011fdfc,"ufshid_sysfs_show_hid_size",0x64b);
      iVar1 = snprintf(param_2,0x1000,"hid ver %.4x\n",*(uint *)(param_1 + 0x236));
    }
    else {
      _printk(&DAT_00120134,"ufshid_sysfs_show_hid_size",0x64f,
              (ulong)*(uint *)((long)param_1 + 0x10e4) << 2);
      iVar1 = snprintf(param_2,0x1000,"%llu KB\n",(ulong)*(uint *)((long)param_1 + 0x10e4) << 2);
    }
    lVar2 = (long)iVar1;
  }
  else {
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// ufshid_sysfs_store_hid_size @ 0011add8 size=240
// signature: undefined ufshid_sysfs_store_hid_size(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_sysfs_store_hid_size(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if ((*(short *)(*(long *)*param_1 + 0xa14) == 0x1ce) &&
     (iVar2 = kstrtouint(param_2,0,&local_2c), iVar2 == 0)) {
    if ((*(uint *)(param_1 + 0x236) & 0xf00) < 0x300) {
      _printk(&DAT_0011fdfc,"ufshid_sysfs_store_hid_size",0x664);
    }
    else {
      iVar2 = ufshid_write_attr(param_1,5,local_2c);
      if (iVar2 == 0) {
        *(uint *)((long)param_1 + 0x10e4) = local_2c;
        _printk(&DAT_00120134,"ufshid_sysfs_store_hid_size",0x66e,(ulong)local_2c << 2);
        goto LAB_0011ae54;
      }
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_0011ae54:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_debug @ 0011aecc size=108
// signature: undefined ufshid_sysfs_show_debug(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_debug(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_001248b5,"ufshid_sysfs_show_debug",0x717,*(undefined1 *)(param_1 + 0x1188));
  iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(byte *)(param_1 + 0x1188));
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_store_debug @ 0011af3c size=172
// signature: undefined ufshid_sysfs_store_debug(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_sysfs_store_debug(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull(param_2,0,&local_30);
  if ((iVar2 == 0) && (local_30 < 2)) {
    *(bool *)(param_1 + 0x1188) = local_30 != 0;
    _printk(&DAT_001248b5,"ufshid_sysfs_store_debug",0x729);
  }
  else {
    param_3 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_hid_state @ 0011afec size=276
// signature: undefined ufshid_sysfs_show_hid_state(void)
// callers: []
//------------------------------------------------------------

void ufshid_sysfs_show_hid_state(long param_1,char *param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  if ((*(uint *)(param_1 + 0x11b0) & 0xf00) < 0x300) {
    _printk(&DAT_0011fdfc,"ufshid_sysfs_show_hid_state",0x7d3);
    iVar3 = snprintf(param_2,0x1000,"hid ver %.4x\n",*(uint *)(param_1 + 0x11b0));
  }
  else {
    iVar3 = ufshid_read_attr(param_1,8,&local_2c);
    if ((iVar3 != 0) || (4 < local_2c)) {
      lVar4 = -0x16;
      goto LAB_0011b04c;
    }
    _printk(&DAT_0012171b,"ufshid_sysfs_show_hid_state",0x7dd,
            (&ufshid_sysfs_show_hid_state_states)[local_2c]);
    if (4 < local_2c) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x11b100);
      (*pcVar2)();
    }
    iVar3 = snprintf(param_2,0x1000,"%s\n",(&ufshid_sysfs_show_hid_state_states)[local_2c]);
  }
  lVar4 = (long)iVar3;
LAB_0011b04c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_show_debug_op @ 0011b104 size=164
// signature: undefined ufshid_sysfs_show_debug_op(void)
// callers: []
//------------------------------------------------------------

void ufshid_sysfs_show_debug_op(undefined8 param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar2 = ufshid_read_attr(param_1,0,&local_2c);
  if (iVar2 == 0) {
    _printk(&DAT_00120667,"ufshid_sysfs_show_debug_op",0x7e9,local_2c);
    iVar2 = snprintf(param_2,0x1000,"%u\n",(ulong)local_2c);
    lVar3 = (long)iVar2;
  }
  else {
    lVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// ufshid_sysfs_store_debug_op @ 0011b1ac size=212
// signature: undefined ufshid_sysfs_store_debug_op(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_sysfs_store_debug_op(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull(param_2,0,&local_30);
  if ((iVar2 == 0) && (local_30 < 5)) {
    if (*(int *)(param_1 + 8) == 0) {
      iVar2 = ufshid_write_attr(param_1,0);
      if (iVar2 == 0) {
        _printk(&DAT_00120dc6,"ufshid_sysfs_store_debug_op",0x801,local_30);
        goto LAB_0011b214;
      }
    }
    else {
      _printk(&DAT_001230bd,"ufshid_sysfs_store_debug_op",0x7fa);
    }
  }
  param_3 = 0xffffffffffffffea;
LAB_0011b214:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_block_suspend @ 0011b284 size=108
// signature: undefined ufshid_sysfs_show_block_suspend(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_block_suspend(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_00123647,"ufshid_sysfs_show_block_suspend",0x808,*(undefined1 *)(param_1 + 0x1189));
  iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(byte *)(param_1 + 0x1189));
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_store_block_suspend @ 0011b2f4 size=224
// signature: undefined ufshid_sysfs_store_block_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 ufshid_sysfs_store_block_suspend(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar2 = kstrtoull(param_2,0,&local_40);
  if ((iVar2 == 0) && (local_40 < 2)) {
    _printk(&DAT_00120afd,"ufshid_sysfs_store_block_suspend",0x818);
    if (local_40 != *(byte *)(param_1 + 0x1189)) {
      if (local_40 == 0) {
        ufshid_allow_enter_suspend(param_1);
      }
      else {
        ufshid_block_enter_suspend();
      }
      *(byte *)(param_1 + 0x1189) = local_40 != 0;
    }
  }
  else {
    param_3 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_sysfs_show_auto_hibern8_enable @ 0011b3d8 size=96
// signature: undefined ufshid_sysfs_show_auto_hibern8_enable(void)
// callers: []
//------------------------------------------------------------

long ufshid_sysfs_show_auto_hibern8_enable(long param_1,char *param_2)

{
  int iVar1;
  
  _printk(&DAT_00120de8,"ufshid_sysfs_show_auto_hibern8_enable",0x82a,
          *(undefined1 *)(param_1 + 0xa4));
  iVar1 = snprintf(param_2,0x1000,"%d\n",(ulong)*(byte *)(param_1 + 0xa4));
  return (long)iVar1;
}



//------------------------------------------------------------
// ufshid_sysfs_store_auto_hibern8_enable @ 0011b43c size=140
// signature: undefined ufshid_sysfs_store_auto_hibern8_enable(void)
// callers: []
//------------------------------------------------------------

undefined8
ufshid_sysfs_store_auto_hibern8_enable(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull(param_2,0,&local_30);
  if ((iVar2 == 0) && (local_30 < 2)) {
    ufshid_auto_hibern8_enable(param_1);
  }
  else {
    param_3 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// ufshid_trigger_on @ 0011b4c8 size=392
// signature: undefined ufshid_trigger_on(void)
// callers: [ufshid_sysfs_store_trigger]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong ufshid_trigger_on(undefined8 *param_1)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  long lVar4;
  
  if (*(int *)(param_1 + 1) == 0) {
    lVar4 = *(long *)*param_1;
    uVar2 = ufshid_hold_runtime_pm();
    if ((int)uVar2 != 0) {
      return uVar2;
    }
    *(undefined4 *)(param_1 + 1) = 1;
    if (*(char *)(param_1 + 0x231) != '\0') {
      _printk(&DAT_00123b83,"ufshid_trigger_on",0x313,1,
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc));
    }
    ufshid_block_enter_suspend(param_1);
    ufshid_auto_hibern8_enable(param_1,0);
    if ((*(short *)(lVar4 + 0xa14) == 0x1ce) && (0x2ff < (*(uint *)(param_1 + 0x236) & 0xf00))) {
      lVar4 = param_1[0x237];
      pcVar3 = *(code **)(lVar4 + 0x18);
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x11c99d85) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x11b578);
          (*pcVar3)();
        }
        iVar1 = (*pcVar3)(param_1);
        if (iVar1 != 0) goto LAB_0011b5b4;
        lVar4 = param_1[0x237];
      }
      if (*(int *)(*(code **)(lVar4 + 0x20) + -4) != -0x2973480b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11b5ac);
        (*pcVar3)();
      }
      iVar1 = (**(code **)(lVar4 + 0x20))(param_1,4,0);
      if (iVar1 != 0) {
LAB_0011b5b4:
        ufsf_rpm_put_noidle(*(undefined8 *)*param_1);
        uVar2 = ufshid_trigger_off(param_1);
        if ((int)uVar2 == 0) {
          return uVar2;
        }
        _printk(&DAT_00123a5d,"ufshid_trigger_on",0x32c,uVar2 & 0xffffffff);
        return uVar2 & 0xffffffff;
      }
    }
    queue_delayed_work_on(0x20,_system_freezable_wq,param_1 + 2,0);
    ufsf_rpm_put_noidle(*(undefined8 *)*param_1);
  }
  return 0;
}



//------------------------------------------------------------
// ufshid_block_enter_suspend @ 0011b650 size=208
// signature: undefined ufshid_block_enter_suspend(void)
// callers: [ufshid_trigger_on, ufshid_sysfs_store_block_suspend]
//------------------------------------------------------------

void ufshid_block_enter_suspend(undefined8 *param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  if (*(char *)((long)param_1 + 0x1189) == '\0') {
    lVar2 = *(long *)*param_1;
    lVar3 = *(long *)(lVar2 + 0x48);
    *(undefined1 *)((long)param_1 + 0x1189) = 1;
    __pm_runtime_resume(*(long *)(lVar2 + 0x48) + 0x1d8,4);
    ufshcd_hold(lVar2,0);
    uVar1 = _raw_spin_lock_irqsave(*(undefined8 *)(*(long *)(lVar2 + 0x38) + 0x38));
    if (*(char *)(param_1 + 0x231) != '\0') {
      _printk(&DAT_0012402f,"ufshid_block_enter_suspend",0x298,*(undefined4 *)(param_1 + 1),
              *(undefined4 *)(*(long *)(*(long *)*param_1 + 0x40) + 0x1f8),
              *(undefined4 *)(*(long *)*param_1 + 0xbdc),*(undefined4 *)(lVar3 + 0x3d0),
              *(undefined4 *)(lVar2 + 0xbdc));
    }
    _raw_spin_unlock_irqrestore(*(undefined8 *)(*(long *)(lVar2 + 0x38) + 0x38),uVar1);
  }
  return;
}



//------------------------------------------------------------
// ufshid_attr_show @ 0011b724 size=176
// signature: undefined ufshid_attr_show(void)
// callers: []
//------------------------------------------------------------

long ufshid_attr_show(long param_1,long param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  
  if (*(long *)(param_2 + 0x10) == 0) {
    lVar4 = -5;
  }
  else {
    puVar1 = (undefined8 *)(param_1 + -0x10f0);
    iVar3 = ufshid_hold_runtime_pm(puVar1);
    if (iVar3 == 0) {
      mutex_lock(param_1 + 0x60);
      if (*(int *)(*(code **)(param_2 + 0x10) + -4) != -0x2bdbbecf) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11b7a0);
        (*pcVar2)();
      }
      lVar4 = (**(code **)(param_2 + 0x10))(puVar1,param_3);
      mutex_unlock(param_1 + 0x60);
      ufsf_rpm_put_noidle(*(undefined8 *)*puVar1);
    }
    else {
      lVar4 = (long)iVar3;
    }
  }
  return lVar4;
}



//------------------------------------------------------------
// ufshid_attr_store @ 0011b7d8 size=192
// signature: undefined ufshid_attr_store(void)
// callers: []
//------------------------------------------------------------

long ufshid_attr_store(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  
  if (*(long *)(param_2 + 0x18) == 0) {
    lVar4 = -5;
  }
  else {
    puVar1 = (undefined8 *)(param_1 + -0x10f0);
    iVar3 = ufshid_hold_runtime_pm(puVar1);
    if (iVar3 == 0) {
      mutex_lock(param_1 + 0x60);
      if (*(int *)(*(code **)(param_2 + 0x18) + -4) != 0x7328eede) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11b860);
        (*pcVar2)();
      }
      lVar4 = (**(code **)(param_2 + 0x18))(puVar1,param_3,param_4);
      mutex_unlock(param_1 + 0x60);
      ufsf_rpm_put_noidle(*(undefined8 *)*puVar1);
    }
    else {
      lVar4 = (long)iVar3;
    }
  }
  return lVar4;
}



//------------------------------------------------------------
// init_module @ 0011b958 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ufs_qcom_pltform,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0011b988 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ufs_qcom_pltform);
  return;
}



//------------------------------------------------------------
// strlen @ 0012b000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_ufs_qcom_uic, trace_event_raw_event_ufs_qcom_command, perf_trace_ufs_qcom_uic, trace_event_raw_event_ufs_qcom_pm_template, trace_event_raw_event_ufs_qcom_pwr_change_notify, trace_event_raw_event_ufs_qcom_hook_check_int_errors, perf_trace_ufs_qcom_pm_template, trace_event_raw_event_ufsfeature_upiu, trace_event_raw_event_ufs_qcom_shutdown, perf_trace_ufs_qcom_pwr_change_notify, perf_trace_ufs_qcom_shutdown, perf_trace_ufs_qcom_command, perf_trace_ufsfeature_command, trace_event_raw_event_ufsfeature_command, perf_trace_ufsfeature_upiu, perf_trace_ufs_qcom_hook_check_int_errors, perf_trace_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_noify_template, perf_trace_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0012b008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_ufs_qcom_uic, trace_event_raw_event_ufsfeature_command, trace_event_raw_event_ufs_qcom_command, trace_event_raw_event_ufs_qcom_pm_template, trace_event_raw_event_ufs_qcom_pwr_change_notify, trace_event_raw_event_ufs_qcom_hook_check_int_errors, trace_event_raw_event_ufsfeature_upiu, trace_event_raw_event_ufs_qcom_shutdown, trace_event_raw_event_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0012b010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_ufs_qcom_uic, trace_event_raw_event_ufs_qcom_command, perf_trace_ufs_qcom_uic, trace_event_raw_event_ufs_qcom_pm_template, trace_event_raw_event_ufs_qcom_pwr_change_notify, trace_event_raw_event_ufs_qcom_hook_check_int_errors, perf_trace_ufs_qcom_pm_template, trace_event_raw_event_ufsfeature_upiu, trace_event_raw_event_ufs_qcom_shutdown, perf_trace_ufs_qcom_pwr_change_notify, perf_trace_ufs_qcom_shutdown, perf_trace_ufs_qcom_command, perf_trace_ufsfeature_command, trace_event_raw_event_ufsfeature_command, perf_trace_ufsfeature_upiu, perf_trace_ufs_qcom_hook_check_int_errors, perf_trace_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_noify_template, perf_trace_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0012b018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_ufs_qcom_uic, trace_event_raw_event_ufsfeature_command, trace_event_raw_event_ufs_qcom_command, trace_event_raw_event_ufs_qcom_pm_template, trace_event_raw_event_ufs_qcom_pwr_change_notify, trace_event_raw_event_ufs_qcom_hook_check_int_errors, trace_event_raw_event_ufsfeature_upiu, trace_event_raw_event_ufs_qcom_shutdown, trace_event_raw_event_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0012b020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_ufs_qcom_uic, trace_event_raw_event_ufsfeature_command, trace_event_raw_event_ufs_qcom_command, trace_event_raw_event_ufs_qcom_pm_template, trace_event_raw_event_ufs_qcom_pwr_change_notify, trace_event_raw_event_ufs_qcom_hook_check_int_errors, trace_event_raw_event_ufsfeature_upiu, trace_event_raw_event_ufs_qcom_shutdown, trace_event_raw_event_ufs_qcom_clk_template, trace_event_raw_event_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0012b028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ufshid_sysfs_store_auto_hibern8_enable, ufshid_write_attr, irq_affinity_support_store, trace_event_raw_event_ufs_qcom_hook_check_int_errors, ufs_qcom_enable_hw_clk_gating, ufsf_issue_tm_cmd, ufshid_sysfs_show_available_size, ufshid_sysfs_store_block_suspend, ufshid_suspend_3_0, perf_trace_ufs_qcom_shutdown, ufs_qcom_set_esi_affinity_hint, ufs_qcom_parse_reg_info, ufs_qcom_ice_debug, trace_event_raw_event_ufsfeature_command, ufsf_exception_event_handler, ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div, ufshid_hid_progress_chk_in_work, perf_trace_ufs_qcom_clk_template, ufs_qcom_register_minidump, ufs_qcom_bypass_cfgready_signal, manual_gc_show, trace_event_raw_event_ufs_qcom_clk_template, perf_trace_ufs_qcom_noify_template, ufs_qcom_update_bus_bw_vote, trace_event_raw_event_ufs_qcom_command, ufs_qcom_apply_dev_quirks, dbg_state_store, manual_gc_store, ufshid_issue_lba_list, ufs_qcom_pwr_change_notify, ufsf_get_kernel_version, ufshid_sysfs_show_hid_state, ufs_qcom_parse_pm_levels, link_failed_recovery_store, ufshid_get_analyze_and_in_work, ufshid_sysfs_store_l2p_defrag_threshold, ufs_pm_mode_store, ufs_qcom_populate_available_cpus, pixel_init_manual_gc, ufs_qcom_ber_threshold_set, trace_event_raw_event_ufs_qcom_noify_template, ufshid_sysfs_store_debug_op, trace_event_raw_event_ufs_qcom_uic, ufshid_init, ufshid_sysfs_show_color, ufshid_sysfs_store_lba_trigger_mode, trace_event_raw_event_ufs_qcom_pm_template, ufshid_sysfs_store_hid_size, ufs_qcom_qos_init, ufs_qcom_ber_duration_set, store_ufs_to_mem_max_bus_bw, manual_gc_hold_store, micron_ufshid_trigger_work_fn, ufs_qcom_clk_scale_notify, ufshid_sysfs_store_trigger_interval, perf_trace_ufs_qcom_pwr_change_notify, ufsf_enable_ee, perf_trace_ufs_qcom_command, ufs_qcom_probe, ufs_qcom_link_startup_notify, crash_on_err_store, ufsf_print_query_buf, ufshid_sysfs_store_trigger, ufs_qcom_parse_irq_affinity, ufs_qcom_hce_enable_notify, ufshid_resume_3_0, ufshid_sysfs_show_debug_op, ufshid_sysfs_store_debug, ufs_qcom_ice_program_key, perf_trace_ufs_qcom_uic, manual_gc_status_show, ufshid_sysfs_show_progress_ratio, ufs_qcom_shared_ice_init, trace_event_raw_event_ufs_qcom_pwr_change_notify, perf_trace_ufs_qcom_pm_template, ufshid_issue_disable, trace_event_raw_event_ufsfeature_upiu, trace_event_raw_event_ufs_qcom_shutdown, perf_trace_ufsfeature_command, __ufsf_write_ee_control, ufshid_sysfs_store_on_idle_delay, perf_trace_ufsfeature_upiu, ufsf_device_check, ufsf_disable_ee, perf_trace_ufs_qcom_hook_check_int_errors, ufsf_device_check_work_handler, ufs_qcom_init, ufshid_sysfs_show_l2p_frag_lvl, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0012b030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_ufs_qcom_command, perf_trace_ufsfeature_command, perf_trace_ufs_qcom_uic, perf_trace_ufsfeature_upiu, perf_trace_ufs_qcom_hook_check_int_errors, perf_trace_ufs_qcom_pm_template, perf_trace_ufs_qcom_clk_template, perf_trace_ufs_qcom_pwr_change_notify, perf_trace_ufs_qcom_shutdown, perf_trace_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0012b038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_ufs_qcom_command, perf_trace_ufsfeature_command, perf_trace_ufs_qcom_uic, perf_trace_ufsfeature_upiu, perf_trace_ufs_qcom_hook_check_int_errors, perf_trace_ufs_qcom_pm_template, perf_trace_ufs_qcom_clk_template, perf_trace_ufs_qcom_pwr_change_notify, perf_trace_ufs_qcom_shutdown, perf_trace_ufs_qcom_noify_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run6 @ 0012b040 size=1
// signature: undefined bpf_trace_run6(void)
// callers: [__bpf_trace_ufs_qcom_uic, __bpf_trace_ufs_qcom_command, __bpf_trace_ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 0012b048 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_ufs_qcom_noify_template, __bpf_trace_ufs_qcom_hook_check_int_errors]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 0012b050 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_ufs_qcom_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0012b058 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_ufs_qcom_clk_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run7 @ 0012b060 size=1
// signature: undefined bpf_trace_run7(void)
// callers: [__bpf_trace_ufs_qcom_pm_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run7(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0012b068 size=1
// signature: undefined __kmalloc(void)
// callers: [ufsf_device_check, ufs_qcom_qos_init, ufsqcom_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// print_hex_dump @ 0012b070 size=1
// signature: undefined print_hex_dump(void)
// callers: [ufs_qcom_dump_dbg_regs, ufsqcom_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void print_hex_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0012b078 size=1
// signature: undefined kfree(void)
// callers: [ufshid_init, ufs_qcom_probe, ufsf_device_check, ufs_qcom_qos_init, ufshid_remove, ufs_qcom_init, ufs_qcom_dump_dbg_regs, ufsqcom_dump_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0012b080 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readl, readl, readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0012b088 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readl, readl, readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0012b090 size=1
// signature: undefined _dev_warn(void)
// callers: [ufs_qcom_set_cur_therm_state, ufs_qcom_probe, ufs_qcom_event_notify, ufs_qcom_qos_init, ufs_qcom_init, ufs_qcom_ice_init, ufs_qcom_device_reset, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_auto_hibern8_update @ 0012b098 size=1
// signature: undefined ufshcd_auto_hibern8_update(void)
// callers: [ufs_qcom_set_cur_therm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_auto_hibern8_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __scsi_iterate_devices @ 0012b0a0 size=1
// signature: undefined __scsi_iterate_devices(void)
// callers: [ufs_qcom_set_cur_therm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __scsi_iterate_devices(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 0012b0a8 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [ufs_qcom_set_cur_therm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0012b0b0 size=1
// signature: undefined _dev_err(void)
// callers: [pixel_ufs_update_sysfs_work, ufsf_mcq_sq_cleanup, ufs_qcom_config_esi, irq_affinity_support_store, __ufs_qcom_set_bus_vote, ufs_qcom_enable_hw_clk_gating, ufsf_issue_tm_cmd, ufs_qcom_toggle_pri_affinity, ufs_qcom_set_esi_affinity_hint, ufs_qcom_parse_reg_info, ufs_qcom_setup_clocks, ufs_qcom_set_bus_vote, ufsf_exception_event_handler, ufs_qcom_update_bus_bw_vote, ufs_qcom_apply_dev_quirks, ufs_qcom_event_notify, ufs_qcom_pwr_change_notify, ufs_qcom_print_hw_debug_reg_all, ufs_pm_mode_store, ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode, ufs_qcom_panic_handler, __ufs_qcom_cfg_timers, ufs_qcom_cpufreq_dwork, ufs_qcom_ice_enable, ufs_qcom_qos_init, ufs_qcom_get_host_id, ufs_qcom_clk_scale_notify, ufs_qcom_testbus_config, ufsf_clear_cmd, ufs_qcom_unvote_qos_all, ufs_qcom_set_cur_therm_state, ufs_qcom_probe, ufs_qcom_link_startup_notify, ufsf_query_flag_retry, ufs_qcom_parse_irq_affinity, ufs_qcom_hce_enable_notify, ufsf_wait_for_doorbell_clr, ufs_qcom_enable_lane_clks, ufs_qcom_device_reset, ufs_qcom_host_clk_enable, ufs_qcom_ice_program_key, err_count_show, ufs_qcom_shared_ice_init, ufs_qcom_ice_init, ufs_qcom_init_sysfs, ufs_qcom_ice_resume, ufs_qcom_vote_work, cancel_dwork_unvote_cpufreq, ufs_qcom_mcq_config_resource, ufs_qcom_init, ufs_qcom_dump_dbg_regs, ufs_qcom_save_host_ptr, ufsf_query_flag, ufs_qcom_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0012b0b8 size=1
// signature: undefined _printk(void)
// callers: [ufshid_write_attr, ufshid_auto_hibern8_enable, ufshid_suspend_1_0, ufshid_sysfs_show_max_lba_range_size, ufshid_sysfs_show_available_size, ufshid_sysfs_store_block_suspend, ufshid_read_attr, ufsf_slave_configure, ufshid_suspend_3_0, ufshid_execute_query_op_and_frag_chk, ufshid_sysfs_show_hid_size, ufshid_sysfs_show_auto_hibern8_enable, ufshid_hid_progress_chk_in_work, ufs_qcom_register_minidump, ufshid_trigger_work_fn, ufshid_check_file_info_buf_3_0, ufshid_issue_lba_list, ufshid_resume_1_0, ufs_qcom_pwr_change_notify, ufsf_get_kernel_version, ufshid_sysfs_show_debug, ufshid_sysfs_show_hid_state, ufshid_sysfs_show_max_lba_range_cnt, ufs_qcom_print_hw_debug_reg_all, ufshid_sysfs_show_l2p_defrag_threshold, ufshid_get_analyze_and_in_work, ufsf_upiu_check_for_ccd, ufshid_sysfs_store_l2p_defrag_threshold, ufshid_sysfs_show_block_suspend, ufshid_sysfs_store_debug_op, ufshid_init, ufshid_sysfs_show_version, ufshid_sysfs_show_color, ufshid_sysfs_store_lba_trigger_mode, ufshid_allow_enter_suspend, ufshid_sysfs_store_hid_size, ufsf_prep_fn, ufshid_get_geo_info, ufshid_sysfs_show_on_idle_delay, ufs_qcom_parse_wb, micron_ufshid_trigger_work_fn, ufshid_sysfs_store_trigger_interval, ufsf_init, ufs_vh_update_sdev, ufs_qcom_link_startup_notify, ufshid_read_attr_micron, ufsf_print_query_buf, ufs_vh_prep_fn, ufshid_sysfs_store_trigger, ufshid_trigger_off, ufshid_check_file_info_buf_2_0, ufshid_block_enter_suspend, ufshid_resume_3_0, ufshid_sysfs_show_debug_op, ufshid_sysfs_store_debug, ufs_qcom_ice_program_key, ufshid_sysfs_show_lba_trigger_mode, ufshid_trigger_on, ufshid_sysfs_show_progress_ratio, ufshid_issue_disable, ufshid_remove, ufshid_prep_fn, ufshid_sysfs_show_trigger_interval, ufshid_hold_runtime_pm, ufshid_sysfs_show_trigger, ufshid_sysfs_store_on_idle_delay, ufshid_reset, ufsf_device_check, ufshid_get_dev_info, ufsf_device_check_work_handler, ufs_qcom_init, ufshid_sysfs_show_l2p_frag_lvl, ufsf_reset_host]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0012b0c0 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel, writel, writel, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0012b0c8 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel, writel, writel, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0012b0d0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [ufshid_allow_enter_suspend, ufs_qcom_apply_dev_quirks, err_count_show, ufshid_auto_hibern8_enable, ufs_qcom_hook_compl_command, ufsf_issue_tm_cmd, ufs_qcom_clk_scale_notify, ufs_qcom_testbus_config, ufs_qcom_resume, ufsf_start_monitor, ufsf_clear_cmd, ufs_qcom_hook_send_command, ufshid_block_enter_suspend, ufsf_reset_host, ufsf_wait_for_doorbell_clr, ufsf_reset_wait_work_handler, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0012b0d8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [ufshid_allow_enter_suspend, ufs_qcom_apply_dev_quirks, err_count_show, ufshid_auto_hibern8_enable, ufs_qcom_hook_compl_command, ufsf_issue_tm_cmd, ufs_qcom_clk_scale_notify, ufs_qcom_testbus_config, ufs_qcom_resume, ufsf_start_monitor, ufsf_clear_cmd, ufs_qcom_hook_send_command, ufshid_block_enter_suspend, ufsf_reset_host, ufsf_wait_for_doorbell_clr, ufsf_reset_wait_work_handler, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0012b0e0 size=1
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
// platform_driver_unregister @ 0012b0e8 size=1
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
// trace_raw_output_prep @ 0012b0f0 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_ufs_qcom_uic, trace_raw_output_ufs_qcom_clk_template, trace_raw_output_ufs_qcom_hook_check_int_errors, trace_raw_output_ufsfeature_upiu, trace_raw_output_ufsfeature_command, trace_raw_output_ufs_qcom_command, trace_raw_output_ufs_qcom_noify_template, trace_raw_output_ufs_qcom_shutdown, trace_raw_output_ufs_qcom_pm_template, trace_raw_output_ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_symbols_seq @ 0012b0f8 size=1
// signature: undefined trace_print_symbols_seq(void)
// callers: [trace_raw_output_ufs_qcom_uic, trace_raw_output_ufs_qcom_clk_template, trace_raw_output_ufsfeature_upiu, trace_raw_output_ufsfeature_command, trace_raw_output_ufs_qcom_command, trace_raw_output_ufs_qcom_noify_template, trace_raw_output_ufs_qcom_pm_template, trace_raw_output_ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_symbols_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0012b100 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_ufs_qcom_uic, trace_raw_output_ufs_qcom_clk_template, trace_raw_output_ufs_qcom_hook_check_int_errors, trace_raw_output_ufsfeature_upiu, trace_raw_output_ufsfeature_command, trace_raw_output_ufs_qcom_command, trace_raw_output_ufs_qcom_noify_template, trace_raw_output_ufs_qcom_shutdown, trace_raw_output_ufs_qcom_pm_template, trace_raw_output_ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0012b108 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_ufs_qcom_uic, trace_raw_output_ufs_qcom_clk_template, trace_raw_output_ufs_qcom_hook_check_int_errors, trace_raw_output_ufsfeature_upiu, trace_raw_output_ufsfeature_command, trace_raw_output_ufs_qcom_command, trace_raw_output_ufs_qcom_noify_template, trace_raw_output_ufs_qcom_shutdown, trace_raw_output_ufs_qcom_pm_template, trace_raw_output_ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0012b110 size=1
// signature: undefined kstrtouint(void)
// callers: [ufshid_sysfs_store_on_idle_delay, ufshid_sysfs_store_hid_size, store_ufs_to_mem_max_bus_bw, ufs_qcom_ber_threshold_set, ufshid_sysfs_store_trigger_interval, manual_gc_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// param_set_int @ 0012b118 size=1
// signature: undefined param_set_int(void)
// callers: [ufs_qcom_ber_duration_set, ufs_qcom_ber_threshold_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void param_set_int(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 0012b120 size=1
// signature: undefined kstrtoll(void)
// callers: [ufs_qcom_ber_duration_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0012b128 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [ufshid_reset_host, cancel_dwork_unvote_cpufreq, ufshid_remove, ufshid_suspend_1_0, ufshid_suspend_3_0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_lock @ 0012b140 size=1
// signature: undefined cpus_read_lock(void)
// callers: [ufs_qcom_cpufreq_dwork, cancel_dwork_unvote_cpufreq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_update_request @ 0012b148 size=1
// signature: undefined freq_qos_update_request(void)
// callers: [ufs_qcom_cpufreq_dwork, cancel_dwork_unvote_cpufreq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_unlock @ 0012b150 size=1
// signature: undefined cpus_read_unlock(void)
// callers: [ufs_qcom_cpufreq_dwork, cancel_dwork_unvote_cpufreq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_set_boost @ 0012b158 size=1
// signature: undefined sched_set_boost(void)
// callers: [ufs_qcom_cpufreq_dwork, ufs_qcom_toggle_pri_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_set_boost(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_modify_status @ 0012b160 size=1
// signature: undefined irq_modify_status(void)
// callers: [ufs_qcom_set_esi_affinity_hint, irq_affinity_support_store, ufs_qcom_cpufreq_dwork, ufs_qcom_toggle_pri_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_modify_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_apply_affinity_hint @ 0012b168 size=1
// signature: undefined __irq_apply_affinity_hint(void)
// callers: [ufs_qcom_set_esi_affinity_hint, irq_affinity_support_store, ufs_qcom_cpufreq_dwork, ufs_qcom_toggle_pri_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_apply_affinity_hint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 0012b170 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [ufs_qcom_probe, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 0012b178 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [ufs_qcom_probe, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0012b180 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [ufs_qcom_parse_reg_info, ufs_qcom_parse_pm_levels, ufs_qcom_probe, ufs_qcom_qos_init, ufs_qcom_parse_irq_affinity, ufs_qcom_init, ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 0012b188 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [ufs_qcom_probe, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0012b190 size=1
// signature: undefined of_find_property(void)
// callers: [ufs_qcom_parse_pm_levels, ufs_qcom_parse_broken_ahit_workaround_flag, ufs_qcom_system_suspend, ufs_qcom_probe, ufs_qcom_link_startup_notify, ufs_qcom_parse_pbl_rst_workaround_flag, ufs_qcom_qos_init, ufs_qcom_init, ufs_qcom_parse_g4_workaround_flag, ufs_qcom_parse_wb, ufs_qcom_parse_lpm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_pltfrm_init @ 0012b198 size=1
// signature: undefined ufshcd_pltfrm_init(void)
// callers: [ufs_qcom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_pltfrm_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 0012b1a0 size=1
// signature: undefined dev_err_probe(void)
// callers: [ufs_qcom_probe, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 0012b1b0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [ufs_qcom_probe, ufs_samsung_register_hooks, pixel_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0012b1e0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [ufshid_write_attr, manual_gc_status_show, hibern8_count_show, ufshid_issue_disable, ufshid_auto_hibern8_enable, micron_ufshid_trigger_work_fn, manual_gc_store, ufshid_read_attr, ufshid_hold_runtime_pm, ufsf_resume_work_handler, ufs_qcom_remove, ufsf_device_check, manual_gc_enable, ufshid_read_attr_micron, ufshid_block_enter_suspend, ufshid_resume_3_0, manual_gc_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0012b1f0 size=1
// signature: undefined _find_next_bit(void)
// callers: [ufs_qcom_unvote_qos_all, ufs_qcom_remove, ufs_qcom_vote_work, ufsf_compl_command, ufs_qcom_populate_available_cpus, ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_remove_request @ 0012b1f8 size=1
// signature: undefined dev_pm_qos_remove_request(void)
// callers: [ufs_qcom_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_enabled @ 0012b200 size=1
// signature: undefined msm_minidump_enabled(void)
// callers: [ufs_qcom_remove, ufs_qcom_exit, ufs_qcom_init, ufs_qcom_register_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 0012b210 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [ufs_qcom_remove, ufs_qcom_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_remove @ 0012b218 size=1
// signature: undefined ufshcd_remove(void)
// callers: [ufs_qcom_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_msi_domain_free_irqs @ 0012b220 size=1
// signature: undefined platform_msi_domain_free_irqs(void)
// callers: [ufs_qcom_config_esi, ufs_qcom_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_msi_domain_free_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0012b228 size=1
// signature: undefined _dev_info(void)
// callers: [ufs_qcom_system_resume, ufs_qcom_system_restore, ufs_qcom_suspend_prepare, ufs_qcom_system_thaw, ufs_qcom_system_freeze, ufs_qcom_ice_init, ufs_qcom_parse_reg_info, ufs_qcom_system_suspend, ufsf_add_tm_upiu_trace, ufs_qcom_remove, ufsf_exception_event_handler, ufs_qcom_mcq_config_resource, ufs_qcom_resume_complete, ufs_qcom_init, get_storage_info, ufs_qcom_shutdown, ufs_qcom_parse_lpm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0012b238 size=1
// signature: undefined ipc_log_string(void)
// callers: [ufs_qcom_hook_check_int_errors, ufs_qcom_hook_compl_command, ufs_qcom_clk_scale_notify, ufs_qcom_pwr_change_notify, ufs_qcom_resume, ufs_qcom_suspend, ufs_qcom_setup_clocks, ufs_qcom_hook_send_uic_command, ufs_qcom_link_startup_notify, ufs_qcom_hook_send_command, ufs_qcom_hce_enable_notify, ufs_qcom_mcq_esi_handler, ufs_qcom_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_count_voltages @ 0012b240 size=1
// signature: undefined regulator_count_voltages(void)
// callers: [ufs_qcom_disable_vreg, ufs_qcom_init, ufs_qcom_resume, ufs_qcom_shutdown, ufs_qcom_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_count_voltages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 0012b248 size=1
// signature: undefined regulator_set_load(void)
// callers: [ufs_qcom_disable_vreg, ufs_qcom_init, ufs_qcom_resume, ufs_qcom_shutdown, ufs_qcom_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0012b250 size=1
// signature: undefined regulator_enable(void)
// callers: [ufs_qcom_init, ufs_qcom_resume, ufs_qcom_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_pltfrm_shutdown @ 0012b258 size=1
// signature: undefined ufshcd_pltfrm_shutdown(void)
// callers: [ufs_qcom_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_pltfrm_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_value_cansleep @ 0012b260 size=1
// signature: undefined gpiod_set_value_cansleep(void)
// callers: [ufs_qcom_device_reset, ufs_qcom_shutdown, ufs_qcom_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_value_cansleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0012b270 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ufs_qcom_parse_reg_info, ufs_qcom_event_notify, ufs_qcom_save_regs, ufs_qcom_mcq_config_resource, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 0012b278 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_reset_controller_register @ 0012b280 size=1
// signature: undefined devm_reset_controller_register(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_reset_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_phy_get @ 0012b288 size=1
// signature: undefined devm_phy_get(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_phy_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpiod_get_optional @ 0012b290 size=1
// signature: undefined devm_gpiod_get_optional(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpiod_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0012b298 size=1
// signature: undefined of_property_read_string(void)
// callers: [ufs_qcom_shared_ice_init, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0012b2a0 size=1
// signature: undefined of_get_property(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 0012b2a8 size=1
// signature: undefined of_icc_get(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 0012b2b0 size=1
// signature: undefined of_property_match_string(void)
// callers: [ufs_qcom_update_bus_bw_vote, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 0012b2b8 size=1
// signature: undefined device_create_file(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 0012b2c0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [ufs_qcom_mcq_config_resource, ufs_qcom_init, ufs_qcom_ice_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 0012b2c8 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [ufs_qcom_mcq_config_resource, ufs_qcom_init, ufs_qcom_ice_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register_notifier @ 0012b2d0 size=1
// signature: undefined devm_regulator_register_notifier(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_save_controller_version @ 0012b2d8 size=1
// signature: undefined ufs_qcom_phy_save_controller_version(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_save_controller_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_init @ 0012b2e0 size=1
// signature: undefined phy_init(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0012b2e8 size=1
// signature: undefined __mutex_init(void)
// callers: [ufshid_init, ufs_qcom_init, ufsf_set_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0012b2f0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_event_notify, ufs_qcom_save_regs, ufs_qcom_shared_ice_init, ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode, ufs_qcom_init, ufs_qcom_hce_enable_notify, get_storage_info, ufs_qcom_clk_scale_notify, __ufs_qcom_cfg_timers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0012b2f8 size=1
// signature: undefined devm_clk_get(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_forbid @ 0012b300 size=1
// signature: undefined pm_runtime_forbid(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_forbid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_qti_hba_init_crypto_capabilities @ 0012b308 size=1
// signature: undefined ufshcd_qti_hba_init_crypto_capabilities(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_qti_hba_init_crypto_capabilities(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0012b310 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [ufshid_sysfs_show_version, ufshid_sysfs_show_color, ufshid_sysfs_show_on_idle_delay, ufshid_sysfs_show_max_lba_range_size, ufshid_sysfs_show_available_size, ufs_qcom_parse_reg_info, ufsf_print_query_buf, ufshid_sysfs_show_hid_size, ufshid_sysfs_show_auto_hibern8_enable, ufs_qcom_hce_enable_notify, ufshid_sysfs_show_debug_op, ufshid_sysfs_show_lba_trigger_mode, ufs_qcom_update_bus_bw_vote, ufshid_sysfs_show_progress_ratio, ufshid_sysfs_show_trigger_interval, ufshid_sysfs_show_debug, ufshid_sysfs_show_hid_state, ufshid_sysfs_show_max_lba_range_cnt, ufshid_sysfs_show_trigger, ufshid_sysfs_show_l2p_defrag_threshold, ufs_qcom_init, ufshid_sysfs_show_l2p_frag_lvl, pixel_init_manual_gc, manual_gc_hold_show, ufshid_sysfs_show_block_suspend, ufshid_sysfs_show_l2p_param_print]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_cooling_device_register @ 0012b318 size=1
// signature: undefined devm_thermal_of_cooling_device_register(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0012b320 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 0012b328 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_exit @ 0012b330 size=1
// signature: undefined phy_exit(void)
// callers: [ufs_qcom_exit, ufs_qcom_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0012b338 size=1
// signature: undefined mutex_lock(void)
// callers: [ufsf_mcq_sq_cleanup, ufs_qcom_config_esi, ufshid_remove, micron_ufshid_trigger_work_fn, ufsf_enable_ee, ufs_qcom_set_esi_affinity_hint, ufs_qcom_setup_clocks, ufshid_attr_show, ufsf_disable_ee, ufs_qcom_exit, ufsf_exception_event_handler, ufsf_device_check_work_handler, ufs_qcom_hce_enable_notify, ufshid_attr_store, ufsf_query_flag, ufshid_trigger_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_power_off @ 0012b340 size=1
// signature: undefined phy_power_off(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_power_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0012b348 size=1
// signature: undefined mutex_unlock(void)
// callers: [ufsf_mcq_sq_cleanup, ufs_qcom_config_esi, ufshid_remove, micron_ufshid_trigger_work_fn, ufsf_enable_ee, ufs_qcom_set_esi_affinity_hint, ufs_qcom_setup_clocks, ufshid_attr_show, ufsf_disable_ee, ufs_qcom_exit, ufsf_exception_event_handler, ufsf_device_check_work_handler, ufs_qcom_hce_enable_notify, ufshid_attr_store, ufsf_query_flag, ufshid_trigger_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0012b350 size=1
// signature: undefined usleep_range_state(void)
// callers: [ufs_qcom_reset_deassert, ufsf_mcq_sq_cleanup, ufs_qcom_dev_ref_clk_ctrl, ufsf_issue_tm_cmd, ufs_qcom_clk_scale_notify, ufsf_wait_for_register, ufs_qcom_pwr_change_notify, ufs_qcom_setup_clocks, ufsf_clear_cmd, ufs_qcom_hce_enable_notify, ufs_qcom_dump_dbg_regs, ufs_qcom_reset_assert, ufs_qcom_device_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_uic_hibern8_enter @ 0012b358 size=1
// signature: undefined ufshcd_uic_hibern8_enter(void)
// callers: [ufs_qcom_clk_scale_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_uic_hibern8_enter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get_rate @ 0012b360 size=1
// signature: undefined clk_get_rate(void)
// callers: [ufs_qcom_clk_scale_notify, __ufs_qcom_cfg_timers]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_dme_get_attr @ 0012b368 size=1
// signature: undefined ufshcd_dme_get_attr(void)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_apply_dev_quirks, ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div, ufs_qcom_hce_enable_notify, ufs_qcom_enable_hw_clk_gating, ufs_qcom_clk_scale_notify, ufs_qcom_bypass_cfgready_signal]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_dme_get_attr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_uic_hibern8_exit @ 0012b370 size=1
// signature: undefined ufshcd_uic_hibern8_exit(void)
// callers: [ufs_qcom_clk_scale_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_uic_hibern8_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0012b378 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [ufs_qcom_cpufreq_dwork, ufshid_reset, ufshid_trigger_on, ufshid_on_idle, micron_ufshid_trigger_work_fn, ufs_qcom_clk_scale_notify, ufshid_resume_3_0, ufshid_trigger_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_dme_set_attr @ 0012b380 size=1
// signature: undefined ufshcd_dme_set_attr(void)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_apply_dev_quirks, ufs_qcom_set_dme_vs_core_clk_ctrl_clear_div, ufs_qcom_enable_hw_clk_gating, ufs_qcom_clk_scale_notify, ufs_qcom_bypass_cfgready_signal, ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_dme_set_attr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_set_src_clk_h8_exit @ 0012b388 size=1
// signature: undefined ufs_qcom_phy_set_src_clk_h8_exit(void)
// callers: [ufs_qcom_setup_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_set_src_clk_h8_exit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0012b390 size=1
// signature: undefined clk_prepare(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_enable_lane_clks, ufs_qcom_host_clk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0012b398 size=1
// signature: undefined clk_enable(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_enable_lane_clks, ufs_qcom_host_clk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_power_on @ 0012b3a0 size=1
// signature: undefined phy_power_on(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_power_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0012b3a8 size=1
// signature: undefined ktime_get(void)
// callers: [ufs_qcom_setup_clocks, ufsf_mcq_sq_cleanup, ufs_qcom_event_notify, ufsf_wait_for_doorbell_clr, ufsf_query_flag, ufsf_start_monitor]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_set_src_clk_h8_enter @ 0012b3b0 size=1
// signature: undefined ufs_qcom_phy_set_src_clk_h8_enter(void)
// callers: [ufs_qcom_setup_clocks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_set_src_clk_h8_enter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0012b3b8 size=1
// signature: undefined clk_disable(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_disable_lane_clks, ufs_qcom_enable_lane_clks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0012b3c0 size=1
// signature: undefined clk_unprepare(void)
// callers: [ufs_qcom_setup_clocks, ufs_qcom_disable_lane_clks, ufs_qcom_enable_lane_clks, ufs_qcom_host_clk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_clk_set_flags @ 0012b3c8 size=1
// signature: undefined qcom_clk_set_flags(void)
// callers: [ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_clk_set_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_set_mode_ext @ 0012b3d0 size=1
// signature: undefined phy_set_mode_ext(void)
// callers: [ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_set_mode_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_calibrate @ 0012b3d8 size=1
// signature: undefined phy_calibrate(void)
// callers: [ufs_qcom_hce_enable_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_calibrate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0012b3e8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [ufs_qcom_link_startup_notify, ufs_pm_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_set_tx_lane_enable @ 0012b3f0 size=1
// signature: undefined ufs_qcom_phy_set_tx_lane_enable(void)
// callers: [ufs_qcom_link_startup_notify, ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_set_tx_lane_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_get_local_unipro_ver @ 0012b3f8 size=1
// signature: undefined ufshcd_get_local_unipro_ver(void)
// callers: [ufs_qcom_link_startup_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_get_local_unipro_ver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_ctrl_rx_linecfg @ 0012b400 size=1
// signature: undefined ufs_qcom_phy_ctrl_rx_linecfg(void)
// callers: [ufs_qcom_link_startup_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_ctrl_rx_linecfg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0012b408 size=1
// signature: undefined fortify_panic(void)
// callers: [ufs_qcom_link_startup_notify, ufs_pm_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_get_tx_hs_equalizer @ 0012b410 size=1
// signature: undefined ufs_qcom_phy_get_tx_hs_equalizer(void)
// callers: [ufs_qcom_pwr_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_get_tx_hs_equalizer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_fixup_dev_quirks @ 0012b418 size=1
// signature: undefined ufshcd_fixup_dev_quirks(void)
// callers: [ufs_qcom_fixup_dev_quirks]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_fixup_dev_quirks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0012b420 size=1
// signature: undefined regulator_disable(void)
// callers: [ufs_qcom_disable_vreg, ufs_qcom_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0012b430 size=1
// signature: undefined queue_work_on(void)
// callers: [ufs_qcom_hook_send_command, ufsf_compl_command, ufsf_reset_host, pixel_ufs_update_sysfs, pixel_mgc_hrtimer_handler, ufsf_slave_configure, ufsf_query_flag, ufs_qcom_resume, ufs_vh_update_sdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_dump_regs @ 0012b438 size=1
// signature: undefined ufshcd_dump_regs(void)
// callers: [ufs_qcom_dump_dbg_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_dump_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0012b448 size=1
// signature: undefined kmalloc_trace(void)
// callers: [ufs_qcom_qos_init, ufshid_get_dev_info, ufs_qcom_dump_dbg_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_dbg_register_dump @ 0012b450 size=1
// signature: undefined ufs_qcom_phy_dbg_register_dump(void)
// callers: [ufs_qcom_event_notify, ufs_qcom_dump_dbg_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_dbg_register_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0012b458 size=1
// signature: undefined disable_irq(void)
// callers: [ufs_qcom_device_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 0012b460 size=1
// signature: undefined reset_control_assert(void)
// callers: [ufs_qcom_device_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 0012b468 size=1
// signature: undefined reset_control_deassert(void)
// callers: [ufs_qcom_device_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0012b470 size=1
// signature: undefined enable_irq(void)
// callers: [ufs_qcom_device_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0012b478 size=1
// signature: undefined __list_add_valid(void)
// callers: [ufs_qcom_event_notify, ufs_qcom_save_regs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0012b480 size=1
// signature: undefined ___ratelimit(void)
// callers: [ufs_qcom_ice_program_key, ufs_qcom_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufs_qcom_phy_dbg_register_save @ 0012b488 size=1
// signature: undefined ufs_qcom_phy_dbg_register_save(void)
// callers: [ufs_qcom_event_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufs_qcom_phy_dbg_register_save(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0012b490 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [ufsf_upiu_check_for_ccd, ufs_qcom_qos_init, ufs_qcom_mcq_config_resource, ufshid_prep_fn, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// insert_resource @ 0012b4a0 size=1
// signature: undefined insert_resource(void)
// callers: [ufs_qcom_mcq_config_resource]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void insert_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_resource @ 0012b4a8 size=1
// signature: undefined remove_resource(void)
// callers: [ufs_qcom_mcq_config_resource]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_msi_domain_alloc_irqs @ 0012b4b0 size=1
// signature: undefined platform_msi_domain_alloc_irqs(void)
// callers: [ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_msi_domain_alloc_irqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msi_first_desc @ 0012b4b8 size=1
// signature: undefined msi_first_desc(void)
// callers: [ufs_qcom_set_esi_affinity_hint, ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msi_first_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0012b4c0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msi_next_desc @ 0012b4c8 size=1
// signature: undefined msi_next_desc(void)
// callers: [ufs_qcom_set_esi_affinity_hint, ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msi_next_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 0012b4d0 size=1
// signature: undefined devm_free_irq(void)
// callers: [ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_mcq_enable_esi @ 0012b4d8 size=1
// signature: undefined ufshcd_mcq_enable_esi(void)
// callers: [ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_mcq_enable_esi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 0012b4e0 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [ufs_qcom_config_esi]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0012b4e8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [ufs_qcom_parse_reg_info, ufs_qcom_shared_ice_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 0012b4f0 size=1
// signature: undefined devm_regulator_get(void)
// callers: [ufs_qcom_parse_reg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0012b4f8 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [ufs_qcom_qos_init, ufs_qcom_shared_ice_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0012b500 size=1
// signature: undefined __const_udelay(void)
// callers: [ufs_qcom_ice_resume, ufs_qcom_ice_enable, ufs_qcom_dev_ref_clk_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0012b508 size=1
// signature: undefined sysfs_create_group(void)
// callers: [ufs_qcom_init_sysfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_alias_get_id @ 0012b510 size=1
// signature: undefined of_alias_get_id(void)
// callers: [ufs_qcom_get_host_id, ufs_qcom_save_host_ptr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_alias_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_subset @ 0012b528 size=1
// signature: undefined __bitmap_subset(void)
// callers: [ufs_qcom_set_esi_affinity_hint, ufs_qcom_qos_init, ufs_qcom_parse_irq_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_subset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0012b530 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0012b538 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 0012b540 size=1
// signature: undefined __bitmap_weight(void)
// callers: [ufs_qcom_hook_send_command, ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 0012b548 size=1
// signature: undefined get_cpu_device(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_request @ 0012b550 size=1
// signature: undefined dev_pm_qos_add_request(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get @ 0012b558 size=1
// signature: undefined cpufreq_cpu_get(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_put @ 0012b560 size=1
// signature: undefined cpufreq_cpu_put(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_add_request @ 0012b568 size=1
// signature: undefined freq_qos_add_request(void)
// callers: [ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0012b578 size=1
// signature: undefined init_timer_key(void)
// callers: [ufshid_init, ufs_qcom_qos_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0012b580 size=1
// signature: undefined alloc_workqueue(void)
// callers: [ufs_qcom_qos_init, pixel_init_manual_gc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 0012b588 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [get_storage_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncasecmp @ 0012b590 size=1
// signature: int strncasecmp(char * __s1, char * __s2, size_t __n)
// callers: [ufs_pm_mode_store, get_storage_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0012b598 size=1
// signature: undefined scnprintf(void)
// callers: [ber_th_exceeded_show, manual_gc_status_show, err_count_show, hibern8_count_show, clk_status_show, dbg_state_show, ufs_pm_mode_show, power_mode_show, bus_speed_mode_show, show_ufs_to_mem_max_bus_bw, err_state_show, irq_affinity_support_show, ufs_qcom_register_minidump, crash_on_err_show, manual_gc_show, link_failed_recovery_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 0012b5b0 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [ufs_qcom_register_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0012b5b8 size=1
// signature: undefined icc_set_bw(void)
// callers: [__ufs_qcom_set_bus_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// capable @ 0012b5c0 size=1
// signature: undefined capable(void)
// callers: [link_failed_recovery_store, dbg_state_store, irq_affinity_support_store, crash_on_err_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 0012b5c8 size=1
// signature: undefined kstrtobool(void)
// callers: [link_failed_recovery_store, dbg_state_store, irq_affinity_support_store, crash_on_err_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_hold @ 0012b5d0 size=1
// signature: undefined ufshcd_hold(void)
// callers: [hibern8_count_show, ufshid_block_enter_suspend, ufshid_auto_hibern8_enable, ufsf_issue_tm_cmd, ufsf_wait_for_doorbell_clr, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_hold(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_release @ 0012b5d8 size=1
// signature: undefined ufshcd_release(void)
// callers: [ufshid_allow_enter_suspend, hibern8_count_show, ufshid_auto_hibern8_enable, ufsf_issue_tm_cmd, ufsf_wait_for_doorbell_clr, ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0012b5e0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [manual_gc_status_show, ufsf_device_check, manual_gc_enable, hibern8_count_show, pixel_mgc_hibern8_work, manual_gc_show, manual_gc_store, ufsf_resume_work_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 0012b5e8 size=1
// signature: undefined strscpy(void)
// callers: [ufs_pm_mode_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_update_request @ 0012b5f0 size=1
// signature: undefined dev_pm_qos_update_request(void)
// callers: [ufs_qcom_unvote_qos_all, ufs_qcom_vote_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dump_stack @ 0012b5f8 size=1
// signature: undefined dump_stack(void)
// callers: [ufs_qcom_set_dme_vs_core_clk_ctrl_max_freq_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dump_stack(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 0012b600 size=1
// signature: undefined flush_work(void)
// callers: [ufs_qcom_unvote_qos_all, ufsf_reset_wait_work_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_mcq_config_esi @ 0012b608 size=1
// signature: undefined ufshcd_mcq_config_esi(void)
// callers: [ufs_qcom_write_msi_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_mcq_config_esi(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_mcq_write_cqis @ 0012b610 size=1
// signature: undefined ufshcd_mcq_write_cqis(void)
// callers: [ufs_qcom_mcq_esi_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_mcq_write_cqis(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_mcq_poll_cqe_lock @ 0012b620 size=1
// signature: undefined ufshcd_mcq_poll_cqe_lock(void)
// callers: [ufs_qcom_mcq_esi_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_mcq_poll_cqe_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_mq_rq_cpu @ 0012b630 size=1
// signature: undefined blk_mq_rq_cpu(void)
// callers: [ufs_qcom_hook_send_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_mq_rq_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_suspend_prepare @ 0012b640 size=1
// signature: undefined ufshcd_suspend_prepare(void)
// callers: [ufs_qcom_suspend_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_suspend_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_resume_complete @ 0012b648 size=1
// signature: undefined ufshcd_resume_complete(void)
// callers: [ufs_qcom_resume_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_resume_complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_system_suspend @ 0012b650 size=1
// signature: undefined ufshcd_system_suspend(void)
// callers: [ufs_qcom_system_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_system_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_system_resume @ 0012b658 size=1
// signature: undefined ufshcd_system_resume(void)
// callers: [ufs_qcom_system_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_system_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_system_freeze @ 0012b660 size=1
// signature: undefined ufshcd_system_freeze(void)
// callers: [ufs_qcom_system_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_system_freeze(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_system_thaw @ 0012b668 size=1
// signature: undefined ufshcd_system_thaw(void)
// callers: [ufs_qcom_system_thaw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_system_thaw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_system_restore @ 0012b670 size=1
// signature: undefined ufshcd_system_restore(void)
// callers: [ufs_qcom_system_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_system_restore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_ice_available @ 0012b6a8 size=1
// signature: undefined qcom_scm_ice_available(void)
// callers: [ufs_qcom_ice_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_ice_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_disable @ 0012b6b0 size=1
// signature: undefined crypto_qti_disable(void)
// callers: [ufs_qcom_ice_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_qti_debug @ 0012b6b8 size=1
// signature: undefined crypto_qti_debug(void)
// callers: [ufs_qcom_ice_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_qti_debug(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_allocate_shm @ 0012b6c0 size=1
// signature: undefined qtee_shmbridge_allocate_shm(void)
// callers: [ufs_qcom_ice_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_allocate_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_ice_invalidate_key @ 0012b6c8 size=1
// signature: undefined qcom_scm_ice_invalidate_key(void)
// callers: [ufs_qcom_ice_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_ice_invalidate_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_flush_shm_buf @ 0012b6d0 size=1
// signature: undefined qtee_shmbridge_flush_shm_buf(void)
// callers: [ufs_qcom_ice_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_flush_shm_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_config_set_ice_key @ 0012b6d8 size=1
// signature: undefined qcom_scm_config_set_ice_key(void)
// callers: [ufs_qcom_ice_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_config_set_ice_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_inv_shm_buf @ 0012b6e0 size=1
// signature: undefined qtee_shmbridge_inv_shm_buf(void)
// callers: [ufs_qcom_ice_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_inv_shm_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_free_shm @ 0012b6e8 size=1
// signature: undefined qtee_shmbridge_free_shm(void)
// callers: [ufs_qcom_ice_program_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_free_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 0012b6f0 size=1
// signature: undefined hrtimer_init(void)
// callers: [pixel_init_manual_gc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_groups @ 0012b708 size=1
// signature: undefined sysfs_create_groups(void)
// callers: [pixel_ufs_update_sysfs_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_groups(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_query_attr_retry @ 0012b710 size=1
// signature: undefined ufshcd_query_attr_retry(void)
// callers: [ufshid_write_attr, manual_gc_status_show, ufshid_read_attr, ufsf_enable_ee, ufsf_query_attr_retry, __ufsf_write_ee_control, manual_gc_enable, ufsf_disable_ee, ufshid_read_attr_micron, ufsf_exception_event_handler, ufsf_get_bkops_status, ufshid_resume_3_0, manual_gc_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_query_attr_retry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_bkops_ctrl @ 0012b718 size=1
// signature: undefined ufshcd_bkops_ctrl(void)
// callers: [manual_gc_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_bkops_ctrl(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_query_flag_retry @ 0012b720 size=1
// signature: undefined ufshcd_query_flag_retry(void)
// callers: [ufsf_exception_event_handler, ufshid_issue_disable, micron_ufshid_trigger_work_fn, manual_gc_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_query_flag_retry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 0012b728 size=1
// signature: undefined hrtimer_active(void)
// callers: [manual_gc_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 0012b730 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [manual_gc_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0012b738 size=1
// signature: undefined kstrtoull(void)
// callers: [ufshid_sysfs_store_auto_hibern8_enable, ufshid_sysfs_store_lba_trigger_mode, ufshid_sysfs_store_trigger, manual_gc_hold_store, ufshid_sysfs_store_block_suspend, ufshid_sysfs_store_debug_op, ufshid_sysfs_store_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0012b748 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [ufsf_device_check_work_handler, ufsf_get_kernel_version]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_strtol @ 0012b750 size=1
// signature: undefined simple_strtol(void)
// callers: [ufsf_device_check_work_handler, ufsf_get_kernel_version]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_strtol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ufshcd_query_descriptor_retry @ 0012b758 size=1
// signature: undefined ufshcd_query_descriptor_retry(void)
// callers: [ufsf_device_check]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ufshcd_query_descriptor_retry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down @ 0012b768 size=1
// signature: undefined down(void)
// callers: [ufsf_resume_work_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up @ 0012b770 size=1
// signature: undefined up(void)
// callers: [ufsf_resume_work_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// work_busy @ 0012b778 size=1
// signature: undefined work_busy(void)
// callers: [ufsf_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void work_busy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run10 @ 0012b780 size=1
// signature: undefined bpf_trace_run10(void)
// callers: [__bpf_trace_ufsfeature_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run10(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 0012b788 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_ufsfeature_upiu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0012b790 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [micron_ufshid_trigger_work_fn, ufshid_resume_3_0, ufsf_wait_for_register, ufshid_trigger_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_mq_alloc_request @ 0012b798 size=1
// signature: undefined blk_mq_alloc_request(void)
// callers: [ufsf_issue_tm_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_mq_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_io_timeout @ 0012b7a0 size=1
// signature: undefined wait_for_completion_io_timeout(void)
// callers: [ufsf_issue_tm_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_io_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_mq_free_request @ 0012b7a8 size=1
// signature: undefined blk_mq_free_request(void)
// callers: [ufsf_issue_tm_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_mq_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 0012b7b0 size=1
// signature: undefined dev_driver_string(void)
// callers: [ufsf_issue_tm_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0012b7b8 size=1
// signature: undefined __warn_printk(void)
// callers: [ufshid_prep_fn, ufsf_issue_tm_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blk_mq_unique_tag @ 0012b7c0 size=1
// signature: undefined blk_mq_unique_tag(void)
// callers: [ufsf_mcq_sq_cleanup, ufsf_mcq_req_to_hwq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blk_mq_unique_tag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read @ 0012b7c8 size=1
// signature: undefined down_read(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 0012b7d0 size=1
// signature: undefined sched_clock(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 0012b7d8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 0012b7e0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0012b7e8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [ufsf_query_flag, ufshid_hold_runtime_pm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 0012b7f0 size=1
// signature: undefined up_read(void)
// callers: [ufsf_query_flag]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_unblock_requests @ 0012b800 size=1
// signature: undefined scsi_unblock_requests(void)
// callers: [ufsf_exception_event_handler, ufsf_scsi_unblock_requests]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_unblock_requests(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_block_requests @ 0012b808 size=1
// signature: undefined scsi_block_requests(void)
// callers: [ufsf_exception_event_handler, ufsf_scsi_block_requests]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_block_requests(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sbitmap_weight @ 0012b810 size=1
// signature: undefined sbitmap_weight(void)
// callers: [ufsf_wait_for_doorbell_clr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sbitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// io_schedule_timeout @ 0012b818 size=1
// signature: undefined io_schedule_timeout(void)
// callers: [ufsf_wait_for_doorbell_clr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void io_schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_hex_seq @ 0012b820 size=1
// signature: undefined trace_print_hex_seq(void)
// callers: [trace_raw_output_ufsfeature_upiu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_hex_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bcmp @ 0012b838 size=1
// signature: int bcmp(void * __s1, void * __s2, size_t __n)
// callers: [ufshid_prep_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0012b840 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [ufshid_suspend_1_0, ufshid_suspend_3_0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0012b848 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [ufshid_init, ufshid_sysfs_store_lba_trigger_mode, ufshid_trigger_off]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0012b850 size=1
// signature: undefined complete(void)
// callers: [ufshid_resume_3_0, ufshid_resume_1_0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init @ 0012b860 size=1
// signature: undefined kobject_init(void)
// callers: [ufshid_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_get @ 0012b868 size=1
// signature: undefined kobject_get(void)
// callers: [ufshid_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_add @ 0012b870 size=1
// signature: undefined kobject_add(void)
// callers: [ufshid_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 0012b878 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [ufshid_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent @ 0012b880 size=1
// signature: undefined kobject_uevent(void)
// callers: [ufshid_init, ufshid_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_del @ 0012b888 size=1
// signature: undefined kobject_del(void)
// callers: [ufshid_init, ufshid_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 0012b890 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [ufshid_issue_disable, micron_ufshid_trigger_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 0012b898 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [ufshid_on_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0012b8a0 size=1
// signature: undefined msleep(void)
// callers: [ufshid_sysfs_show_color, ufshid_execute_query_op_and_frag_chk, ufshid_hid_progress_chk_in_work, ufshid_sysfs_show_l2p_frag_lvl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scsi_execute_cmd @ 0012b8a8 size=1
// signature: undefined scsi_execute_cmd(void)
// callers: [ufshid_issue_lba_list]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scsi_execute_cmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 0012b8b0 size=1
// signature: undefined kstrtou8(void)
// callers: [ufshid_sysfs_store_l2p_defrag_threshold]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



