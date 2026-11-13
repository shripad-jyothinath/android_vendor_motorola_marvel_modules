// Decompiled by Ghidra 12.2
// Program: qcom_rpmh.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_rpmh_tx_done @ 00101354 size=124
// signature: undefined __traceiter_rpmh_tx_done(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_rpmh_tx_done
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00107680;
  plVar2 = DAT_00107680;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1b12e410) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1013ac);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rpmh_send_msg @ 001013d4 size=148
// signature: undefined __traceiter_rpmh_send_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rpmh_send_msg
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001076c8;
  plVar2 = _DAT_001076c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4e575f09) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101440);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rpmh_solver_set @ 0010146c size=116
// signature: undefined __traceiter_rpmh_solver_set(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_rpmh_solver_set(undefined8 param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00107710 != (long *)0x0) {
    plVar2 = _DAT_00107710;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0xca6722e) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1014bc);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_rpmh_switch_channel @ 001014e4 size=124
// signature: undefined __traceiter_rpmh_switch_channel(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rpmh_switch_channel
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00107758;
  plVar2 = _DAT_00107758;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1d54e5a6) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10153c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rpmh_drv_enable @ 00101564 size=124
// signature: undefined __traceiter_rpmh_drv_enable(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rpmh_drv_enable(undefined8 param_1,undefined8 param_2,uint param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_001077a0 != (long *)0x0) {
    plVar2 = _DAT_001077a0;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x38937f44) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1015bc);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3 & 1,param_4);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// trace_event_raw_event_rpmh_tx_done @ 001015e4 size=276
// signature: undefined trace_event_raw_event_rpmh_tx_done(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rpmh_tx_done(long param_1,char *param_2,undefined4 param_3,long param_4)

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
      *(undefined4 *)(lVar3 + 0x10) = **(undefined4 **)(param_4 + 0x10);
      *(undefined4 *)(lVar3 + 0x14) = *(undefined4 *)(*(long *)(param_4 + 0x10) + 4);
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
// perf_trace_rpmh_tx_done @ 001016fc size=364
// signature: undefined perf_trace_rpmh_tx_done(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rpmh_tx_done(long param_1,char *param_2,undefined4 param_3,long param_4)

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
      *(undefined4 *)(lVar5 + 0x10) = **(undefined4 **)(param_4 + 0x10);
      *(undefined4 *)(lVar5 + 0x14) = *(undefined4 *)(*(long *)(param_4 + 0x10) + 4);
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
// trace_event_raw_event_rpmh_send_msg @ 0010186c size=304
// signature: undefined trace_event_raw_event_rpmh_send_msg(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rpmh_send_msg
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 *param_6)

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
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x24);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x21;
      strcpy((char *)(lVar3 + 0x21),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = *param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_6[1];
      *(bool *)(lVar3 + 0x20) = param_6[2] != 0;
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
// perf_trace_rpmh_send_msg @ 001019a0 size=380
// signature: undefined perf_trace_rpmh_send_msg(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rpmh_send_msg
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 *param_6)

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
  local_78 = param_5;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x2c;
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
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x10021;
      strcpy((char *)(lVar5 + 0x21),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x14) = local_78;
      *(undefined4 *)(lVar5 + 0x18) = *param_6;
      *(undefined4 *)(lVar5 + 0x1c) = param_6[1];
      *(bool *)(lVar5 + 0x20) = param_6[2] != 0;
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
// trace_event_raw_event_rpmh_solver_set @ 00101b20 size=244
// signature: undefined trace_event_raw_event_rpmh_solver_set(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rpmh_solver_set(long param_1,char *param_2,byte param_3)

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
    lVar3 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x10);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0xd;
      strcpy((char *)(lVar3 + 0xd),__s);
      *(byte *)(lVar3 + 0xc) = param_3 & 1;
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
// perf_trace_rpmh_solver_set @ 00101c18 size=332
// signature: undefined perf_trace_rpmh_solver_set(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rpmh_solver_set(long param_1,char *param_2,byte param_3)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
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
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x1cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar5 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x1000d;
      strcpy((char *)(lVar5 + 0xd),__s);
      *(byte *)(lVar5 + 0xc) = param_3 & 1;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_64,param_1,1,local_60,plVar1,0);
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
// trace_event_raw_event_rpmh_switch_channel @ 00101d68 size=252
// signature: undefined trace_event_raw_event_rpmh_switch_channel(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rpmh_switch_channel
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
// perf_trace_rpmh_switch_channel @ 00101e68 size=336
// signature: undefined perf_trace_rpmh_switch_channel(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rpmh_switch_channel
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
// trace_event_raw_event_rpmh_drv_enable @ 00101fbc size=260
// signature: undefined trace_event_raw_event_rpmh_drv_enable(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rpmh_drv_enable
               (long param_1,char *param_2,byte param_3,undefined4 param_4)

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
      *(byte *)(lVar3 + 0xc) = param_3 & 1;
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
// perf_trace_rpmh_drv_enable @ 001020c4 size=344
// signature: undefined perf_trace_rpmh_drv_enable(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rpmh_drv_enable(long param_1,char *param_2,byte param_3,undefined4 param_4)

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
      *(byte *)(lVar5 + 0xc) = param_3 & 1;
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
// __bpf_trace_rpmh_tx_done @ 00102220 size=32
// signature: undefined __bpf_trace_rpmh_tx_done(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rpmh_tx_done(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run3(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_rpmh_send_msg @ 00102244 size=40
// signature: undefined __bpf_trace_rpmh_send_msg(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rpmh_send_msg
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_rpmh_solver_set @ 00102270 size=32
// signature: undefined __bpf_trace_rpmh_solver_set(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rpmh_solver_set(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  bpf_trace_run2(param_1,param_2,param_3 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_rpmh_switch_channel @ 00102294 size=36
// signature: undefined __bpf_trace_rpmh_switch_channel(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rpmh_switch_channel
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_rpmh_drv_enable @ 001022bc size=36
// signature: undefined __bpf_trace_rpmh_drv_enable(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rpmh_drv_enable
               (undefined8 param_1,undefined8 param_2,ulong param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3 & 1,param_4);
  return;
}



//------------------------------------------------------------
// rpmh_rsc_get_channel @ 001022e4 size=136
// signature: undefined rpmh_rsc_get_channel(void)
// callers: [rpmh_write_sleep_and_wake, rpmh_init_fast_path, __rpmh_write, rpmh_write_batch, rpmh_write_sleep_and_wake_no_child, rpmh_update_fast_path]
//------------------------------------------------------------

undefined4 rpmh_rsc_get_channel(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_1 + 0x38) == 1) {
    uVar3 = 0;
  }
  else {
    do {
      uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                            (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50));
      uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) +
                            (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x54));
    } while (uVar2 != uVar1);
    if ((uVar1 & 1) == 0) {
      uVar3 = 0xfffffff0;
      if ((uVar1 & 2) != 0) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// readl_relaxed @ 0010236c size=124
// signature: undefined readl_relaxed(void)
// callers: [print_tcs_info, rpmh_rsc_is_tcs_completed, __tcs_buffer_write, rpmh_rsc_send_data, rpmh_rsc_debug_channel_busy, rpmh_rsc_update_fast_path, tcs_tx_done, rpmh_rsc_probe, rpmh_rsc_debug, rpmh_rsc_init_fast_path, __tcs_set_trigger, rpmh_rsc_get_channel, rpmh_rsc_ctrlr_is_busy, rpmh_rsc_pd_cb, rpmh_rsc_cpu_pm_callback, claim_tcs_for_req, rpmh_rsc_drv_enable, rpmh_rsc_restore_noirq]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1023b4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// rpmh_rsc_invalidate @ 001023ec size=68
// signature: undefined rpmh_rsc_invalidate(void)
// callers: [_rpmh_flush]
//------------------------------------------------------------

void rpmh_rsc_invalidate(undefined8 param_1,undefined4 param_2)

{
  tcs_invalidate(param_1,0,param_2);
  tcs_invalidate(param_1,1,param_2);
  return;
}



//------------------------------------------------------------
// tcs_invalidate @ 00102430 size=468
// signature: undefined tcs_invalidate(void)
// callers: [rpmh_rsc_invalidate]
//------------------------------------------------------------

void tcs_invalidate(long param_1,ulong param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  int *piVar8;
  int iVar9;
  
  if (1 < param_3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102604);
    (*pcVar2)();
  }
  lVar1 = param_1 + (ulong)param_3 * 0x150 + 0x68 + (param_2 & 0xffffffff) * 0x40;
  piVar8 = (int *)(lVar1 + 0x14);
  uVar7 = (ulong)(uint)(*piVar8 * *(int *)(lVar1 + 0x18));
  uVar4 = _find_first_bit((void *)(lVar1 + 0x38),uVar7);
  if (uVar4 != uVar7) {
    iVar5 = *piVar8;
    uVar6 = *(uint *)(lVar1 + 0x10);
    if (uVar6 < iVar5 + uVar6) {
      do {
        iVar5 = (*(int **)(param_1 + 0x28))[10];
        writel(0,*(long *)(param_1 + 0x20) + (long)iVar5 +
                 (ulong)(**(int **)(param_1 + 0x28) * uVar6));
        iVar9 = 1000000;
        do {
          iVar3 = readl(*(long *)(param_1 + 0x20) + (long)iVar5 +
                        (ulong)(**(int **)(param_1 + 0x28) * uVar6));
          if (iVar3 == 0) goto LAB_0010254c;
          __const_udelay(0x10c7);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        _printk(&DAT_00107c08,"qcom_rpmh",param_1,0,uVar6,iVar5);
LAB_0010254c:
        iVar5 = (*(int **)(param_1 + 0x28))[7];
        writel(0,*(long *)(param_1 + 0x20) + (long)iVar5 +
                 (ulong)(**(int **)(param_1 + 0x28) * uVar6));
        iVar9 = 1000000;
        do {
          iVar3 = readl(*(long *)(param_1 + 0x20) + (long)iVar5 +
                        (ulong)(**(int **)(param_1 + 0x28) * uVar6));
          if (iVar3 == 0) goto LAB_001024c4;
          __const_udelay(0x10c7);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        _printk(&DAT_00107c08,"qcom_rpmh",param_1,0,uVar6,iVar5);
LAB_001024c4:
        uVar6 = uVar6 + 1;
        iVar5 = *piVar8;
      } while (uVar6 < iVar5 + *(uint *)(lVar1 + 0x10));
    }
    memset((void *)(lVar1 + 0x38),0,
           (ulong)(*(int *)(lVar1 + 0x18) * iVar5 + 0x3fU >> 3 & 0x1ffffff8));
  }
  return;
}



//------------------------------------------------------------
// rpmh_rsc_send_data @ 00102608 size=972
// signature: undefined rpmh_rsc_send_data(void)
// callers: [__rpmh_write, rpmh_write_batch]
//------------------------------------------------------------

ulong rpmh_rsc_send_data(long param_1,uint *param_2,uint param_3)

{
  long lVar1;
  ulong *puVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  long lVar11;
  ulong uVar12;
  ulong uVar13;
  int iVar14;
  ulong uVar15;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  uVar7 = *param_2;
  if (uVar7 < 3) {
    if (1 < param_3) {
LAB_001029a8:
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1029ac);
      (*pcVar6)();
    }
    lVar11 = param_1 + (ulong)param_3 * 0x150;
    uVar12 = lVar11 + 0x68 + (ulong)uVar7 * 0x40;
    uVar13 = uVar12;
    if ((uVar7 == 2) && (uVar13 = lVar11 + 0xa8, *(int *)(uVar12 + 0x14) != 0)) {
      uVar13 = uVar12;
    }
    if (uVar13 < 0xfffffffffffff001) {
      lVar11 = param_1 + 0x310;
      _raw_spin_lock_irq(lVar11);
      if (*(char *)(param_1 + 0x40) == '\0') {
        uVar7 = claim_tcs_for_req(param_1,uVar13,param_2);
        if ((int)uVar7 < 0) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          lVar1 = param_1 + 0x318;
          prepare_to_wait_event(lVar1,&local_90,2);
          uVar7 = claim_tcs_for_req(param_1,uVar13,param_2);
          if ((int)uVar7 < 0) {
            do {
              _raw_spin_unlock_irq(lVar11);
              schedule();
              _raw_spin_lock_irq(lVar11);
              prepare_to_wait_event(lVar1,&local_90,2);
              uVar7 = claim_tcs_for_req(param_1,uVar13,param_2);
            } while ((int)uVar7 < 0);
          }
          finish_wait(lVar1,&local_90);
        }
        uVar10 = uVar7 - *(int *)(uVar13 + 0x10);
        if (2 < uVar10) goto LAB_001029a8;
        uVar15 = (ulong)uVar7;
        uVar12 = 1L << (uVar15 & 0x3f);
        *(uint **)(uVar13 + (ulong)uVar10 * 8 + 0x20) = param_2;
        puVar2 = (ulong *)(param_1 + 0x308 + (ulong)(uVar7 >> 6) * 8);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar5) {
            *puVar2 = *puVar2 | uVar12;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        iVar14 = 1000000;
        iVar3 = (*(int **)(param_1 + 0x28))[10];
        writel(0,*(long *)(param_1 + 0x20) + (long)iVar3 +
                 (ulong)(**(int **)(param_1 + 0x28) * uVar7));
        iVar9 = 1000000;
        do {
          iVar8 = readl(*(long *)(param_1 + 0x20) + (long)iVar3 +
                        (ulong)(**(int **)(param_1 + 0x28) * uVar7));
          if (iVar8 == 0) goto LAB_00102848;
          __const_udelay(0x10c7);
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        _printk(&DAT_00107c08,"qcom_rpmh",param_1,0,uVar7,iVar3);
LAB_00102848:
        iVar3 = (*(int **)(param_1 + 0x28))[7];
        writel(0,*(long *)(param_1 + 0x20) + (long)iVar3 +
                 (ulong)(**(int **)(param_1 + 0x28) * uVar7));
        do {
          iVar9 = readl(*(long *)(param_1 + 0x20) + (long)iVar3 +
                        (ulong)(**(int **)(param_1 + 0x28) * uVar7));
          if (iVar9 == 0) goto LAB_001028b8;
          __const_udelay(0x10c7);
          iVar14 = iVar14 + -1;
        } while (iVar14 != 0);
        _printk(&DAT_00107c08,"qcom_rpmh",param_1,0,uVar7,iVar3);
LAB_001028b8:
        if ((param_2[1] == 0) && ((*param_2 != 2 || (*(int *)(uVar13 + 8) == 2)))) {
          uVar10 = readl_relaxed(*(long *)(param_1 + 0x20) +
                                 (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x10));
          uVar10 = uVar10 & ((uint)(1L << (uVar15 & 0x3f)) ^ 0xffffffff);
        }
        else {
          uVar10 = readl_relaxed(*(long *)(param_1 + 0x20) +
                                 (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x10));
          uVar10 = uVar10 | (uint)(1L << (uVar15 & 0x3f));
        }
        writel_relaxed(uVar10,*(long *)(param_1 + 0x20) +
                              (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x10));
        __tcs_buffer_write(param_1,uVar7,0,param_2);
        __tcs_set_trigger(param_1,uVar7,1);
        ipc_log_string(*(undefined8 *)(param_1 + 0x540),"TCS trigger: m=%d wait_for_compl=%u",uVar7,
                       param_2[1]);
        if (param_2[1] == 0) {
          puVar2 = (ulong *)(param_1 + 0x308 + (ulong)(uVar7 >> 6) * 8);
          Hint_Prefetch(puVar2,2,0,1);
          do {
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
            if (bVar5) {
              *puVar2 = *puVar2 & (uVar12 ^ 0xffffffffffffffff);
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
        }
        _raw_spin_unlock_irq(lVar11);
        if (param_2[1] == 0) {
          __wake_up(param_1 + 0x318,3,1,0);
        }
        uVar13 = 0;
      }
      else {
        _raw_spin_unlock_irq(lVar11);
        uVar13 = 0xfffffff0;
      }
    }
  }
  else {
    uVar13 = 0xffffffffffffffea;
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13 & 0xffffffff;
}



//------------------------------------------------------------
// claim_tcs_for_req @ 001029e8 size=472
// signature: undefined claim_tcs_for_req(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

void claim_tcs_for_req(long param_1,long *param_2,long param_3)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  ulong local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  iVar6 = (int)param_2[2];
  local_70 = 0;
  iVar4 = iVar6;
  while( true ) {
    uVar3 = _find_next_bit(param_1 + 0x308,*(int *)((long)param_2 + 0x14) + iVar6,(long)iVar4);
    if ((uint)(*(int *)((long)param_2 + 0x14) + (int)param_2[2]) <= uVar3) break;
    local_70 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[10] +
                             (ulong)(**(int **)(param_1 + 0x28) * uVar3));
    local_70 = local_70 & 0xffffffff;
    iVar4 = 0;
    while (iVar4 = _find_next_bit(&local_70,(long)(int)param_2[3],(long)iVar4),
          iVar4 < (int)param_2[3]) {
      piVar1 = *(int **)(param_1 + 0x28);
      uVar5 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)piVar1[0xc] + (ulong)(*piVar1 * uVar3)
                            + (ulong)(uint)(piVar1[1] * iVar4));
      if (*(int *)(param_3 + 8) != 0) {
        uVar10 = 0;
        do {
          uVar7 = cmd_db_match_resource_addr
                            (*(undefined4 *)(*(long *)(param_3 + 0x10) + (long)(int)uVar10 * 0xc),
                             uVar5);
          if ((uVar7 & 1) != 0) goto LAB_00102b78;
          uVar10 = uVar10 + 1;
        } while (uVar10 < *(uint *)(param_3 + 8));
      }
      iVar4 = iVar4 + 1;
    }
    iVar6 = (int)param_2[2];
    iVar4 = uVar3 + 1;
  }
  lVar9 = *param_2;
  uVar8 = (ulong)(uint)(*(int *)((long)param_2 + 0x14) + (int)param_2[2]);
  uVar7 = _find_next_zero_bit(lVar9 + 0x308,uVar8);
  if (uVar7 < uVar8) {
    iVar4 = -100;
    do {
      iVar6 = readl_relaxed(*(long *)(lVar9 + 0x20) + (long)(*(int **)(lVar9 + 0x28))[9] +
                            (ulong)(uint)(**(int **)(lVar9 + 0x28) * (int)uVar7));
      if (iVar6 != 0) {
        uVar8 = uVar7 & 0xffffffff;
        break;
      }
      __const_udelay(0x10c7);
      bVar2 = iVar4 != -1;
      iVar4 = iVar4 + 1;
      uVar8 = 0xfffffff0;
    } while (bVar2);
  }
  else {
LAB_00102b78:
    uVar8 = 0xfffffff0;
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// __tcs_buffer_write @ 00102bc0 size=524
// signature: undefined __tcs_buffer_write(void)
// callers: [rpmh_rsc_write_ctrl_data, rpmh_rsc_send_data, rpmh_rsc_init_fast_path]
//------------------------------------------------------------

void __tcs_buffer_write(long param_1,int param_2,ulong param_3,long param_4)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint local_64;
  
  iVar3 = *(int *)(param_4 + 4);
  param_3 = param_3 & 0xffffffff;
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[7] +
                        (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  if (*(int *)(param_4 + 8) == 0) {
    local_64 = 0;
  }
  else {
    uVar9 = 0;
    local_64 = 0;
    uVar5 = sp_el0;
    do {
      puVar7 = (undefined4 *)(*(long *)(param_4 + 0x10) + (long)(int)uVar9 * 0xc);
      piVar2 = *(int **)(param_1 + 0x28);
      iVar4 = puVar7[2];
      uVar8 = (uint)param_3;
      uVar1 = 0x10008;
      if (iVar4 != 0 || iVar3 != 0) {
        uVar1 = 0x10108;
      }
      writel_relaxed(uVar1,*(long *)(param_1 + 0x20) + (long)piVar2[0xb] +
                           (ulong)(uint)(*piVar2 * param_2) + (ulong)(piVar2[1] * uVar8));
      piVar2 = *(int **)(param_1 + 0x28);
      writel_relaxed(*puVar7,*(long *)(param_1 + 0x20) + (long)piVar2[0xc] +
                             (ulong)(uint)(*piVar2 * param_2) + (ulong)(piVar2[1] * uVar8));
      piVar2 = *(int **)(param_1 + 0x28);
      writel_relaxed(puVar7[1],
                     *(long *)(param_1 + 0x20) + (long)piVar2[0xd] +
                     (ulong)(uint)(*piVar2 * param_2) + (ulong)(piVar2[1] * uVar8));
      local_64 = local_64 | (uint)(1L << (param_3 & 0x3f));
      uVar6 = iVar4 << (ulong)(uVar8 & 0x1f) | uVar6;
      ipc_log_string(*(undefined8 *)(param_1 + 0x540),
                     "TCS write: m=%d n=%d msgid=%#x addr=%#x data=%#x wait=%d",param_2,param_3,
                     uVar1,*puVar7,puVar7[1],puVar7[2]);
      uVar9 = uVar9 + 1;
      param_3 = (ulong)(uVar8 + 1);
    } while (uVar9 < *(uint *)(param_4 + 8));
  }
  writel_relaxed(uVar6,*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[7] +
                       (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[10] +
                        (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  writel_relaxed(uVar6 | local_64,
                 *(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[10] +
                 (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  return;
}



//------------------------------------------------------------
// __tcs_set_trigger @ 00102e88 size=520
// signature: undefined __tcs_set_trigger(void)
// callers: [rpmh_rsc_send_data, rpmh_rsc_update_fast_path, tcs_tx_done]
//------------------------------------------------------------

void __tcs_set_trigger(long param_1,int param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 1000000;
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[8] +
                        (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  uVar4 = uVar2 & 0xfeffffff;
  iVar1 = (*(int **)(param_1 + 0x28))[8];
  writel(uVar4,*(long *)(param_1 + 0x20) + (long)iVar1 +
               (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  iVar5 = 1000000;
  do {
    uVar3 = readl(*(long *)(param_1 + 0x20) + (long)iVar1 +
                  (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
    if (uVar3 == uVar4) goto LAB_00102f58;
    __const_udelay(0x10c7);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  _printk(&DAT_00107c08,"qcom_rpmh",param_1,uVar4,param_2,iVar1);
LAB_00102f58:
  iVar1 = (*(int **)(param_1 + 0x28))[8];
  uVar2 = uVar2 & 0xfefeffff;
  writel(uVar2,*(long *)(param_1 + 0x20) + (long)iVar1 +
               (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  iVar5 = 1000000;
  do {
    uVar4 = readl(*(long *)(param_1 + 0x20) + (long)iVar1 +
                  (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
    if (uVar4 == uVar2) goto LAB_00102fdc;
    __const_udelay(0x10c7);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  _printk(&DAT_00107c08,"qcom_rpmh",param_1,uVar2,param_2,iVar1);
LAB_00102fdc:
  if ((param_3 & 1) != 0) {
    iVar1 = (*(int **)(param_1 + 0x28))[8];
    writel(0x10000,*(long *)(param_1 + 0x20) + (long)iVar1 +
                   (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
    do {
      iVar5 = readl(*(long *)(param_1 + 0x20) + (long)iVar1 +
                    (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
      if (iVar5 == 0x10000) goto LAB_00103054;
      __const_udelay(0x10c7);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    _printk(&DAT_00107c08,"qcom_rpmh",param_1,0x10000,param_2,iVar1);
LAB_00103054:
    writel_relaxed(0x1010000,
                   *(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[8] +
                   (ulong)(uint)(**(int **)(param_1 + 0x28) * param_2));
  }
  return;
}



//------------------------------------------------------------
// rpmh_rsc_write_ctrl_data @ 00103094 size=312
// signature: undefined rpmh_rsc_write_ctrl_data(void)
// callers: [_rpmh_flush]
//------------------------------------------------------------

ulong rpmh_rsc_write_ctrl_data(long param_1,uint *param_2,uint param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  
  uVar4 = param_2[2];
  if (uVar4 == 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x540),"Empty num_cmds, returning");
  }
  else {
    uVar9 = *param_2;
    if (2 < uVar9) {
      uVar8 = 0xffffffffffffffea;
      goto LAB_001031ac;
    }
    if (1 < param_3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1031cc);
      (*pcVar2)();
    }
    lVar7 = param_1 + (ulong)param_3 * 0x150;
    uVar1 = lVar7 + 0x68 + (ulong)uVar9 * 0x40;
    uVar8 = uVar1;
    if ((uVar9 == 2) && (uVar8 = lVar7 + 0xa8, *(int *)(uVar1 + 0x14) != 0)) {
      uVar8 = uVar1;
    }
    if (0xfffffffffffff000 < uVar8) goto LAB_001031ac;
    iVar6 = *(int *)(uVar8 + 0x14);
    iVar5 = *(int *)(uVar8 + 0x18);
    uVar9 = 0;
    do {
      iVar3 = bitmap_find_next_zero_area_off
                        (uVar8 + 0x38,(long)(iVar5 * iVar6),(long)(int)uVar9,uVar4,0,0);
      iVar6 = *(int *)(uVar8 + 0x14);
      iVar5 = *(int *)(uVar8 + 0x18);
      if (iVar5 * iVar6 <= iVar3) {
        uVar8 = 0xfffffff4;
        goto LAB_001031ac;
      }
      uVar4 = param_2[2];
      uVar9 = iVar5 + uVar9;
    } while (uVar9 <= (uVar4 + iVar3) - 1);
    __bitmap_set(uVar8 + 0x38,iVar3,uVar4);
    iVar6 = *(int *)(uVar8 + 0x18);
    iVar5 = 0;
    if (iVar6 != 0) {
      iVar5 = iVar3 / iVar6;
    }
    __tcs_buffer_write(param_1,*(int *)(uVar8 + 0x10) + iVar5,iVar3 - iVar5 * iVar6,param_2);
  }
  uVar8 = 0;
LAB_001031ac:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// rpmh_rsc_debug_channel_busy @ 001031d0 size=368
// signature: undefined rpmh_rsc_debug_channel_busy(void)
// callers: [rpmh_drv_start, rpmh_drv_stop, rpmh_write_sleep_and_wake_no_child]
//------------------------------------------------------------

void rpmh_rsc_debug_channel_busy(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  _printk(&DAT_00107e66,"qcom_rpmh",param_1);
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x48));
  uVar3 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50));
  uVar4 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x54));
  uVar5 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x58));
  uVar6 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x40));
  uVar7 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x44));
  _printk(&DAT_00107bb2,"qcom_rpmh",uVar1,uVar2);
  _printk(&DAT_00107dab,"qcom_rpmh",uVar3,uVar4,uVar5);
  _printk(&DAT_00107dde,"qcom_rpmh",uVar6,uVar7);
  crm_dump_regs("cam_crm");
  crm_dump_drv_regs("cam_crm",*(undefined4 *)(param_1 + 0x30));
  return;
}



//------------------------------------------------------------
// rpmh_rsc_debug @ 00103344 size=792
// signature: undefined rpmh_rsc_debug(void)
// callers: [rpmh_write, rpmh_write_batch]
//------------------------------------------------------------

void rpmh_rsc_debug(long param_1,undefined8 param_2)

{
  uint uVar1;
  char *pcVar2;
  ulong uVar3;
  char cVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  int iVar9;
  ulong uVar10;
  int iVar11;
  undefined8 local_80;
  char local_78 [4];
  char local_74 [4];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar8 = irq_get_irq_data(*(undefined4 *)(param_1 + 0x3c));
  local_74[0] = '\0';
  local_78[0] = '\0';
  local_80 = 0;
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  _printk(&DAT_00107d34,"qcom_rpmh",param_1);
  iVar9 = *(int *)(param_1 + 0x34);
  iVar11 = 0;
  if (0 < iVar9) {
    uVar10 = 0;
    iVar11 = 0;
    do {
      if ((*(ulong *)(param_1 + 0x308 + (uVar10 >> 3 & 0x1ffffffffffffff8)) >> (uVar10 & 0x3f) & 1)
          != 0) {
        iVar11 = iVar11 + 1;
        print_tcs_info(param_1,uVar10 & 0xffffffff,&local_80,local_78);
        iVar9 = *(int *)(param_1 + 0x34);
      }
      uVar10 = uVar10 + 1;
    } while ((long)uVar10 < (long)iVar9);
  }
  if (lVar8 == 0) {
    _printk(&DAT_00107a22,"qcom_rpmh",param_1);
    goto LAB_0010358c;
  }
  irq_get_irqchip_state(*(undefined4 *)(param_1 + 0x3c),0,local_74);
  pcVar2 = "NOT PENDING";
  if (local_74[0] != '\0') {
    pcVar2 = "PENDING";
  }
  _printk(&DAT_00107a58,"qcom_rpmh",*(undefined8 *)(lVar8 + 8),pcVar2);
  uVar10 = completion_done(param_2);
  pcVar2 = "PENDING";
  if ((uVar10 & 1) == 0) {
    pcVar2 = "NOT PENDING";
  }
  _printk(&DAT_00107e95,"qcom_rpmh",pcVar2);
  uVar5 = local_80;
  uVar10 = 0;
  do {
    uVar1 = (uint)(-1L << (uVar10 & 0x3f)) & (uint)uVar5;
    uVar10 = ((ulong)uVar1 & 0x2a) >> 1 | ((ulong)uVar1 & 0x15) << 1;
    uVar3 = 6;
    if ((uVar1 & 0x3f) != 0) {
      uVar3 = LZCOUNT(((uVar10 & 0x3333333333333333) >> 2 |
                      ((uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x303030303030303) << 2) << 4)
                      << 0x38);
    }
    if (5 < uVar3) break;
    strlcat(&local_70,(&accl_str)[uVar3],0x14);
    strlcat(&local_70,&DAT_00107e73,0x14);
    uVar10 = uVar3 + 1;
  } while (uVar3 != 5);
  if ((local_74[0] == '\0' && iVar11 != 0) || (local_78[0] == '\0')) {
    _printk(&DAT_00107c90,"qcom_rpmh",&local_70);
  }
  else if (local_74[0] != '\0') {
    _printk(&DAT_00107b88,"qcom_rpmh");
  }
  if ((*(char *)(param_1 + 0x1b0) == '\0') || (*(int *)(param_1 + 0x17c) == 0)) {
LAB_00103554:
    cVar4 = *(char *)(param_1 + 0x300);
  }
  else {
    iVar9 = *(int *)(param_1 + 0x178);
    iVar7 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                          (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar9));
    if (iVar7 != 0) goto LAB_00103554;
    _printk(&DAT_00107f2a,"qcom_rpmh");
    print_tcs_info(param_1,iVar9,&local_80,local_78);
    cVar4 = *(char *)(param_1 + 0x300);
  }
  if ((cVar4 != '\0') && (*(int *)(param_1 + 0x2cc) != 0)) {
    iVar9 = *(int *)(param_1 + 0x2c8);
    iVar7 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                          (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar9));
    if (iVar7 == 0) {
      _printk(&DAT_00107f2a,"qcom_rpmh");
      print_tcs_info(param_1,iVar9,&local_80,local_78);
    }
  }
  if (iVar11 != 0) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10365c);
    (*pcVar6)();
  }
LAB_0010358c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// print_tcs_info @ 0010365c size=1136
// signature: undefined print_tcs_info(void)
// callers: [rpmh_rsc_debug]
//------------------------------------------------------------

void print_tcs_info(long param_1,ulong param_2,ulong *param_3,undefined8 param_4)

{
  undefined *puVar1;
  undefined *puVar2;
  char *pcVar3;
  int *piVar4;
  char cVar5;
  char cVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  uint uVar13;
  ulong uVar14;
  long lVar15;
  long lVar16;
  int iVar17;
  ulong uVar18;
  undefined4 *puVar19;
  ulong uVar20;
  ulong local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  uVar20 = 1L << (param_2 & 0x3f);
  cVar5 = *(char *)(param_1 + 0x1b0);
  lVar16 = param_1 + 0x68;
  iVar17 = (int)param_2;
  if ((cVar5 == '\0') || ((uVar20 & *(uint *)(param_1 + 0x74)) == 0)) {
    cVar6 = *(char *)(param_1 + 0x300);
    if ((cVar6 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x1c4)) != 0)) {
      lVar15 = 0;
LAB_001037a0:
      lVar16 = param_1 + 0x1b8;
      goto LAB_001037a4;
    }
    if ((cVar5 != '\0') && ((uVar20 & *(uint *)(param_1 + 0xb4)) != 0)) {
      lVar15 = 1;
      goto LAB_001037a4;
    }
    if ((cVar6 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x204)) != 0)) {
      lVar15 = 1;
      goto LAB_001037a0;
    }
    if ((cVar5 != '\0') && ((uVar20 & *(uint *)(param_1 + 0xf4)) != 0)) {
      lVar15 = 2;
      goto LAB_001037a4;
    }
    if ((cVar6 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x244)) != 0)) {
      lVar15 = 2;
      goto LAB_001037a0;
    }
    if ((cVar5 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x134)) != 0)) {
      lVar15 = 3;
      goto LAB_001037a4;
    }
    if ((cVar6 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x284)) != 0)) {
      lVar15 = 3;
      goto LAB_001037a0;
    }
    if ((cVar5 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x174)) != 0)) {
      lVar15 = 4;
      goto LAB_001037a4;
    }
    if ((cVar6 != '\0') && ((uVar20 & *(uint *)(param_1 + 0x2c4)) != 0)) {
      lVar15 = 4;
      goto LAB_001037a0;
    }
    lVar16 = 0;
    if (cVar5 != '\0') goto LAB_001037ac;
LAB_001037cc:
    if (*(char *)(param_1 + 0x300) != '\0') {
      lVar15 = param_1 + 0x1f8;
      if (*(int *)(param_1 + 0x24c) != 0) {
        lVar15 = param_1 + 0x238;
      }
      if ((uVar20 & *(uint *)(lVar15 + 0xc)) != 0) goto LAB_001037f4;
    }
    puVar19 = (undefined4 *)0x0;
  }
  else {
    lVar15 = 0;
LAB_001037a4:
    lVar16 = lVar16 + lVar15 * 0x40;
    if (cVar5 == '\0') goto LAB_001037cc;
LAB_001037ac:
    lVar15 = param_1 + 0xa8;
    if (*(int *)(param_1 + 0xfc) != 0) {
      lVar15 = param_1 + 0xe8;
    }
    if ((uVar20 & *(uint *)(lVar15 + 0xc)) == 0) goto LAB_001037cc;
LAB_001037f4:
    uVar10 = iVar17 - *(int *)(lVar15 + 0x10);
    if (2 < uVar10) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x103acc);
      (*pcVar7)();
    }
    puVar19 = *(undefined4 **)(lVar15 + (ulong)uVar10 * 8 + 0x20);
  }
  uVar18 = *(ulong *)(param_1 + ((ulong)(long)iVar17 >> 6) * 8 + 0x308);
  iVar9 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                        (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar17));
  uVar10 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[10] +
                         (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar17));
  local_70 = (ulong)uVar10;
  if ((lVar16 != 0) && (uVar10 != 0)) {
    if (puVar19 != (undefined4 *)0x0) {
      uVar11 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[8] +
                             (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar17));
      uVar14 = readl_relaxed(*(long *)(param_1 + 0x20) +
                             (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x14));
      puVar1 = &DAT_00107a55;
      if ((uVar18 & 1L << ((long)iVar17 & 0x3fU)) != 0) {
        puVar1 = &DAT_00107f01;
      }
      puVar2 = &DAT_00107f01;
      if (*(int *)(lVar16 + 8) != 2) {
        puVar2 = &DAT_00107a55;
      }
      _printk(&DAT_00107cca,"qcom_rpmh",puVar1,puVar2,*(int *)(lVar16 + 8),*puVar19,puVar19[1]);
      puVar1 = &DAT_00107b4d;
      if (iVar9 != 0) {
        puVar1 = &DAT_001079f0;
      }
      bVar8 = (uVar20 & uVar14 & 0xffffffff) != 0;
      pcVar3 = "COMPLETED";
      if (!bVar8) {
        pcVar3 = "PENDING";
      }
      _printk(&DAT_00107f79,"qcom_rpmh",param_2 & 0xffffffff,puVar1,uVar11,pcVar3);
      *(bool *)param_4 = bVar8;
    }
    iVar9 = 0;
    while (iVar9 = _find_next_bit(&local_70,(long)*(int *)(lVar16 + 0x18),(long)iVar9),
          iVar9 < *(int *)(lVar16 + 0x18)) {
      piVar4 = *(int **)(param_1 + 0x28);
      uVar10 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)piVar4[0xc] +
                             (ulong)(uint)(*piVar4 * iVar17) + (ulong)(uint)(piVar4[1] * iVar9));
      piVar4 = *(int **)(param_1 + 0x28);
      uVar11 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)piVar4[0xd] +
                             (ulong)(uint)(*piVar4 * iVar17) + (ulong)(uint)(piVar4[1] * iVar9));
      piVar4 = *(int **)(param_1 + 0x28);
      uVar12 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)piVar4[0xb] +
                             (ulong)(uint)(*piVar4 * iVar17) + (ulong)(uint)(piVar4[1] * iVar9));
      piVar4 = *(int **)(param_1 + 0x28);
      uVar13 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)piVar4[0xe] +
                             (ulong)(uint)(*piVar4 * iVar17) + (ulong)(uint)(piVar4[1] * iVar9));
      _printk(&DAT_00107e00,"qcom_rpmh",iVar9,uVar10,uVar11,uVar12,uVar13);
      if ((uVar13 & 0x10100) == 0x100) {
        *param_3 = *param_3 | 1L << (uVar10 >> 0x10 & 0xf);
      }
      iVar9 = iVar9 + 1;
    }
  }
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rpmh_rsc_mode_solver_set @ 00103ad0 size=152
// signature: undefined rpmh_rsc_mode_solver_set(void)
// callers: [rpmh_mode_solver_set]
//------------------------------------------------------------

undefined8 rpmh_rsc_mode_solver_set(long param_1,byte param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  iVar1 = _raw_spin_trylock(param_1 + 0x310);
  if (iVar1 == 0) {
    uVar3 = 0xfffffff0;
  }
  else {
    if (((param_2 & 1) == 0) || (uVar2 = rpmh_rsc_ctrlr_is_busy(param_1), (uVar2 & 1) == 0)) {
      *(byte *)(param_1 + 0x40) = param_2 & 1;
      ipc_log_string(*(undefined8 *)(param_1 + 0x540),"solver mode set: %d",param_2 & 1);
      uVar3 = 0;
    }
    else {
      uVar3 = 0xfffffff0;
    }
    _raw_spin_unlock(param_1 + 0x310);
  }
  return uVar3;
}



//------------------------------------------------------------
// rpmh_rsc_ctrlr_is_busy @ 00103c04 size=260
// signature: undefined rpmh_rsc_ctrlr_is_busy(void)
// callers: [rpmh_rsc_pd_cb, rpmh_rsc_cpu_pm_callback, rpmh_rsc_mode_solver_set]
//------------------------------------------------------------

undefined8 rpmh_rsc_ctrlr_is_busy(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  if (*(char *)(param_1 + 0x1b0) == '\0') {
LAB_00103c84:
    if (*(char *)(param_1 + 0x300) != '\0') {
      lVar1 = param_1 + 0x1f8;
      if (*(int *)(param_1 + 0x24c) != 0) {
        lVar1 = param_1 + 0x238;
      }
      uVar5 = (ulong)(uint)(*(int *)(lVar1 + 0x14) + *(int *)(lVar1 + 0x10));
      uVar3 = _find_next_bit(param_1 + 0x308,uVar5);
      if ((uVar3 < uVar5) ||
         ((*(int *)(param_1 + 0x2cc) != 0 &&
          (iVar2 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                                 (ulong)(uint)(**(int **)(param_1 + 0x28) *
                                              *(int *)(param_1 + 0x2c8))), iVar2 == 0))))
      goto LAB_00103cbc;
    }
    uVar4 = 0;
  }
  else {
    lVar1 = param_1 + 0xa8;
    if (*(int *)(param_1 + 0xfc) != 0) {
      lVar1 = param_1 + 0xe8;
    }
    uVar5 = (ulong)(uint)(*(int *)(lVar1 + 0x14) + *(int *)(lVar1 + 0x10));
    uVar3 = _find_next_bit(param_1 + 0x308,uVar5);
    if ((uVar5 <= uVar3) &&
       ((*(int *)(param_1 + 0x17c) == 0 ||
        (iVar2 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                               (ulong)(uint)(**(int **)(param_1 + 0x28) * *(int *)(param_1 + 0x178))
                              ), iVar2 != 0)))) goto LAB_00103c84;
LAB_00103cbc:
    uVar4 = 1;
  }
  return uVar4;
}



//------------------------------------------------------------
// rpmh_rsc_is_tcs_completed @ 00103d0c size=500
// signature: undefined rpmh_rsc_is_tcs_completed(void)
// callers: [rpmh_rsc_switch_channel, rpmh_rsc_drv_enable]
//------------------------------------------------------------

undefined8 rpmh_rsc_is_tcs_completed(long param_1,int param_2)

{
  uint uVar1;
  undefined8 uVar2;
  uint uVar3;
  
  uVar3 = 4;
  if (param_2 == 0) {
    uVar3 = 1;
  }
  uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
  if ((uVar1 & uVar3) == 0) {
    __const_udelay(0xa7c6);
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                          (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
    if ((uVar1 & uVar3) == 0) {
      __const_udelay(0xa7c6);
      uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                            (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
      if ((uVar1 & uVar3) == 0) {
        __const_udelay(0xa7c6);
        uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                              (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
        if ((uVar1 & uVar3) == 0) {
          __const_udelay(0xa7c6);
          uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                                (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
          if ((uVar1 & uVar3) == 0) {
            __const_udelay(0xa7c6);
            uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                                  (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
            if ((uVar1 & uVar3) == 0) {
              __const_udelay(0xa7c6);
              uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                                    (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
              if ((uVar1 & uVar3) == 0) {
                __const_udelay(0xa7c6);
                uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                                      (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
                if ((uVar1 & uVar3) == 0) {
                  __const_udelay(0xa7c6);
                  uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
                  if ((uVar1 & uVar3) == 0) {
                    __const_udelay(0xa7c6);
                    uVar1 = readl_relaxed(*(long *)(param_1 + 0x18) +
                                          (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
                    if ((uVar1 & uVar3) == 0) {
                      __const_udelay(0xa7c6);
                      uVar2 = 0xfffffff0;
                    }
                    else {
                      uVar2 = 0xfffffff0;
                    }
                    goto code_r0x00103e94;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  writel_relaxed(0x80000000,
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x4c));
  uVar2 = 0;
code_r0x00103e94:
  ipc_log_string(*(undefined8 *)(param_1 + 0x540),"channel switched to: %d ret: %d",param_2,uVar2);
  return 0;
}



//------------------------------------------------------------
// writel_relaxed @ 00103fac size=132
// signature: undefined writel_relaxed(void)
// callers: [rpmh_rsc_is_tcs_completed, rpmh_rsc_switch_channel, __tcs_buffer_write, rpmh_rsc_send_data, rpmh_rsc_update_fast_path, tcs_tx_done, rpmh_rsc_probe, rpmh_rsc_init_fast_path, __tcs_set_trigger, rpmh_rsc_drv_enable, rpmh_rsc_restore_noirq]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x103fc4,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x104000,uVar1);
  return;
}



//------------------------------------------------------------
// rpmh_rsc_switch_channel @ 00104034 size=84
// signature: undefined rpmh_rsc_switch_channel(void)
// callers: [rpmh_write_sleep_and_wake, rpmh_write_sleep_and_wake_no_child]
//------------------------------------------------------------

undefined8 rpmh_rsc_switch_channel(long param_1,ulong param_2)

{
  writel_relaxed(1L << (param_2 & 0x3f),
                 *(long *)(param_1 + 0x18) + (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50));
  rpmh_rsc_is_tcs_completed(param_1,param_2 & 0xffffffff);
  return 0;
}



//------------------------------------------------------------
// rpmh_rsc_drv_enable @ 0010408c size=444
// signature: undefined rpmh_rsc_drv_enable(void)
// callers: [rpmh_drv_start, rpmh_drv_stop]
//------------------------------------------------------------

int rpmh_rsc_drv_enable(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  
  _raw_spin_lock(param_1 + 0x310);
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) +
                        (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x58));
  uVar1 = param_2 & 1;
  if (uVar2 == uVar1) {
    iVar3 = -0x16;
  }
  else if ((param_2 & 1) == 0) {
    if (*(int *)(param_1 + 0x38) == 1) {
      lVar5 = 0;
    }
    else {
      do {
        uVar2 = readl_relaxed(*(long *)(param_1 + 0x18) +
                              (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50));
        uVar4 = readl_relaxed(*(long *)(param_1 + 0x18) +
                              (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x54));
      } while (uVar4 != uVar2);
      if ((uVar2 & 1) == 0) {
        lVar5 = 0;
        iVar3 = 0;
        if ((uVar2 >> 1 & 1) == 0) goto LAB_00104208;
      }
      else {
        lVar5 = 1;
      }
    }
    iVar3 = rpmh_flush(param_1 + 0x330,lVar5);
    if (iVar3 == 0) {
      writel_relaxed(1 << lVar5,
                     *(long *)(param_1 + 0x18) + (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50))
      ;
      rpmh_rsc_is_tcs_completed(param_1,lVar5);
      writel_relaxed(0,*(long *)(param_1 + 0x18) +
                       (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50));
      writel_relaxed(uVar1,*(long *)(param_1 + 0x18) +
                           (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x58));
    }
  }
  else {
    iVar3 = rpmh_flush(param_1 + 0x330,0);
    if (iVar3 == 0) {
      writel_relaxed(uVar1,*(long *)(param_1 + 0x18) +
                           (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x58));
      writel_relaxed(1,*(long *)(param_1 + 0x18) +
                       (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x50));
      rpmh_rsc_is_tcs_completed(param_1,0);
    }
  }
LAB_00104208:
  _raw_spin_unlock(param_1 + 0x310);
  ipc_log_string(*(undefined8 *)(param_1 + 0x540),"drv enable: %d ret: %d",uVar1,iVar3);
  return iVar3;
}



//------------------------------------------------------------
// rpmh_rsc_init_fast_path @ 001042ec size=168
// signature: undefined rpmh_rsc_init_fast_path(void)
// callers: [rpmh_init_fast_path]
//------------------------------------------------------------

undefined8 rpmh_rsc_init_fast_path(long param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (1 < param_3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104394);
    (*pcVar1)();
  }
  if (*(int *)(param_1 + (ulong)param_3 * 0x150 + 0x17c) == 0) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar4 = (ulong)*(uint *)(param_1 + (ulong)param_3 * 0x150 + 0x178);
    uVar2 = readl_relaxed(*(long *)(param_1 + 0x20) +
                          (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x10));
    writel_relaxed(uVar2 & ((uint)(1L << (uVar4 & 0x3f)) ^ 0xffffffff),
                   *(long *)(param_1 + 0x20) + (ulong)*(uint *)(*(long *)(param_1 + 0x28) + 0x10));
    __tcs_buffer_write(param_1,uVar4,0,param_2);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// rpmh_rsc_update_fast_path @ 00104398 size=452
// signature: undefined rpmh_rsc_update_fast_path(void)
// callers: [rpmh_update_fast_path]
//------------------------------------------------------------

undefined8 rpmh_rsc_update_fast_path(long param_1,long param_2,ulong param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  ulong uVar7;
  
  if (1 < param_4) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10455c);
    (*pcVar3)();
  }
  if (*(int *)(param_1 + (ulong)param_4 * 0x150 + 0x17c) == 0) {
    uVar5 = 0xffffffed;
  }
  else {
    iVar2 = *(int *)(param_1 + (ulong)param_4 * 0x150 + 0x178);
    iVar4 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                          (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar2));
    if (iVar4 == 0) {
      __const_udelay(0x10c7);
      iVar4 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                            (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar2));
      if (iVar4 == 0) {
        __const_udelay(0x10c7);
        iVar4 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                              (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar2));
        if (iVar4 == 0) {
          __const_udelay(0x10c7);
          iVar4 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                                (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar2));
          if (iVar4 == 0) {
            __const_udelay(0x10c7);
            iVar4 = readl_relaxed(*(long *)(param_1 + 0x20) + (long)(*(int **)(param_1 + 0x28))[9] +
                                  (ulong)(uint)(**(int **)(param_1 + 0x28) * iVar2));
            if (iVar4 == 0) {
              _printk(&DAT_00107e75,"qcom_rpmh");
              return 0xfffffff0;
            }
          }
        }
      }
    }
    uVar6 = *(uint *)(param_2 + 8);
    if (uVar6 != 0) {
      uVar7 = 0;
      do {
        if (((param_3 & 0xffffffff) >> (uVar7 & 0x3f) & 1) != 0) {
          piVar1 = *(int **)(param_1 + 0x28);
          writel_relaxed(*(undefined4 *)(*(long *)(param_2 + 0x10) + (long)(int)uVar7 * 0xc + 4),
                         *(long *)(param_1 + 0x20) + (long)piVar1[0xd] +
                         (ulong)(uint)(*piVar1 * iVar2) + (ulong)(uint)(piVar1[1] * (int)uVar7));
          uVar6 = *(uint *)(param_2 + 8);
        }
        uVar7 = uVar7 + 1;
      } while ((uint)uVar7 < uVar6);
    }
    __tcs_set_trigger(param_1,iVar2,1);
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// rpmh_rsc_get_device @ 00104560 size=208
// signature: undefined rpmh_rsc_get_device(void)
// callers: [rpmh_get_device]
//------------------------------------------------------------

undefined8 rpmh_rsc_get_device(char *param_1,uint param_2)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  ppuVar5 = &rpmh_rsc_dev_list;
  do {
    ppuVar5 = (undefined **)*ppuVar5;
    if (ppuVar5 == &rpmh_rsc_dev_list) {
      return 0xffffffffffffffed;
    }
    iVar1 = strcmp(param_1,(char *)(ppuVar5 + -5));
  } while (iVar1 != 0);
  if (((ppuVar5 + -5 < (undefined **)0xfffffffffffff000 ||
        ppuVar5 == (undefined **)0xfffffffffffff028) &&
      (iVar1 = strcmp(param_1,"cam_rsc"), iVar1 == 0)) &&
     (uVar2 = (ulong)*(uint *)((long)ppuVar5 + -0x14), 0 < (int)*(uint *)((long)ppuVar5 + -0x14))) {
    uVar3 = (ulong)param_2;
    uVar4 = uVar3;
    do {
      if ((uVar4 == 0) && (ppuVar5[-2][uVar3 * 0x550 + 0x41] != '\0')) {
        return *(undefined8 *)(ppuVar5[-2] + uVar3 * 0x550 + 0x538);
      }
      uVar4 = uVar4 - 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0xffffffffffffffed;
}



//------------------------------------------------------------
// trace_raw_output_rpmh_tx_done @ 00104634 size=112
// signature: undefined trace_raw_output_rpmh_tx_done(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rpmh_tx_done(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: ack: tcs-m: %d addr: %#x data: %#x\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rpmh_send_msg @ 001046a8 size=132
// signature: undefined trace_raw_output_rpmh_send_msg(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rpmh_send_msg(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "%s: send-msg: tcs(m): %d cmd(n): %d msgid: %#x addr: %#x data: %#x complete: %d\n"
                       ,lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c),
                       *(undefined1 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rpmh_solver_set @ 00104730 size=108
// signature: undefined trace_raw_output_rpmh_solver_set(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rpmh_solver_set(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: solver mode set: %d\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       *(undefined1 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rpmh_switch_channel @ 001047a0 size=108
// signature: undefined trace_raw_output_rpmh_switch_channel(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rpmh_switch_channel(long param_1,undefined8 param_2,undefined8 param_3)

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
// trace_raw_output_rpmh_drv_enable @ 00104810 size=112
// signature: undefined trace_raw_output_rpmh_drv_enable(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rpmh_drv_enable(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s: drv enable: %d ret: %d\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       *(undefined1 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// writel @ 00104880 size=136
// signature: undefined writel(void)
// callers: [tcs_invalidate, rpmh_rsc_send_data, __tcs_set_trigger]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x104898,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1048d8,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 00104908 size=140
// signature: undefined readl(void)
// callers: [tcs_invalidate, rpmh_rsc_send_data, __tcs_set_trigger]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x104960,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// rpmh_rsc_probe @ 00104998 size=2548
// signature: undefined rpmh_rsc_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong rpmh_rsc_probe(long param_1)

{
  long *plVar1;
  int *piVar2;
  undefined *puVar3;
  long *plVar4;
  long lVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined1 auVar9 [16];
  undefined *puVar10;
  code *pcVar11;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ulong uVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  long lVar22;
  long lVar23;
  int iVar24;
  long lVar25;
  long lVar26;
  long lVar27;
  long lVar28;
  long *plVar29;
  undefined8 uVar30;
  uint uVar31;
  ulong uVar32;
  undefined8 uVar33;
  long *plVar34;
  ulong local_b0;
  int local_a4;
  int iStack_a0;
  uint local_9c;
  uint local_98 [2];
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar18 = sp_el0;
  local_70 = *(long *)(lVar18 + 0x638);
  uVar30 = *(undefined8 *)(param_1 + 0x2f8);
  local_a4 = 0;
  iStack_a0 = 0;
  uVar17 = cmd_db_ready();
  uVar32 = uVar17 & 0xffffffff;
  if ((int)uVar17 != -0x205) {
    plVar1 = (long *)(param_1 + 0x10);
    if ((int)uVar17 == 0) {
      bVar12 = cmd_db_is_standalone();
      rpmh_standalone = bVar12 & 1;
      if ((bVar12 & 1) != 0) {
        _dev_info(plVar1,"RPMH is running in standalone mode.\n");
      }
      lVar18 = devm_kmalloc(plVar1,0x38,0xdc0);
      if (lVar18 != 0) {
        uVar13 = of_property_read_variable_u32_array(uVar30,"qcom,drv-count",&local_a4,1,0);
        uVar14 = uVar13;
        if (-1 < (int)uVar13) {
          uVar14 = 0;
        }
        uVar32 = (ulong)uVar14;
        if ((int)uVar13 < 0) goto LAB_001052bc;
        auVar9._8_8_ = 0;
        auVar9._0_8_ = (long)local_a4;
        if ((SUB168(auVar9 * ZEXT816(0x550),8) == 0) &&
           (lVar19 = devm_kmalloc(plVar1,(long)local_a4 * 0x550,0xdc0), lVar19 != 0)) {
          lVar20 = of_get_property(uVar30,"label",0);
          if ((lVar20 == 0) && (lVar20 = *(long *)(param_1 + 0x80), lVar20 == 0)) {
            lVar20 = *plVar1;
          }
          *(int *)(lVar18 + 0x14) = local_a4;
          *(long *)(lVar18 + 0x18) = lVar19;
          *(long **)(lVar18 + 0x20) = plVar1;
          scnprintf(lVar18,0x14,&DAT_00107b85,lVar20);
          lVar21 = of_get_next_child(uVar30,0);
          if (lVar21 != 0) {
            do {
              uVar17 = of_node_name_eq(lVar21,&DAT_00107c3e);
              if ((uVar17 & 1) != 0) {
                uVar32 = of_property_read_variable_u32_array(lVar21,"qcom,drv-id",&iStack_a0,1,0);
                if ((int)uVar32 < 0) goto LAB_00105374;
                scnprintf(lVar19 + (long)iStack_a0 * 0x550,0x14,"%s-drv-%d",lVar20);
                uVar32 = devm_platform_ioremap_resource(param_1,iStack_a0);
                *(ulong *)(lVar19 + (long)iStack_a0 * 0x550 + 0x18) = uVar32;
                if (0xfffffffffffff000 < uVar32) goto LAB_001052bc;
                lVar22 = kmalloc_trace(_dev_pm_genpd_add_notifier,0xdc0,0x390);
                if (lVar22 == 0) goto LAB_001052b8;
                lVar23 = *(long *)(param_1 + 0x80);
                *(long **)(lVar22 + 0x60) = plVar1;
                *(long *)(lVar22 + 0x2e8) = lVar21;
                lVar25 = lVar19 + (long)iStack_a0 * 0x550;
                *(int *)(lVar25 + 0x30) = iStack_a0;
                *(long *)(lVar25 + 0x548) = param_1;
                *(long *)(lVar25 + 0x538) = lVar22;
                if (lVar23 == 0) {
                  lVar23 = *plVar1;
                }
                dev_set_name(lVar22,"%s:%pOFn%d",lVar23,lVar21);
                uVar32 = device_register(lVar22);
                if ((int)uVar32 != 0) goto LAB_00105374;
                uVar14 = readl_relaxed(*(undefined8 *)(lVar19 + (long)iStack_a0 * 0x550 + 0x18));
                iVar24 = iStack_a0;
                lVar23 = lVar19 + (long)iStack_a0 * 0x550;
                puVar6 = rpmh_rsc_reg_offsets_ver_3_0;
                if ((uVar14 & 0xff0000) < 0x20001) {
                  puVar6 = rpmh_rsc_reg_offsets_ver_2_7;
                }
                *(undefined1 **)(lVar23 + 0x28) = puVar6;
                local_9c = 0;
                uVar33 = *(undefined8 *)(*(long *)(lVar23 + 0x538) + 0x2e8);
                uVar32 = of_property_read_variable_u32_array(uVar33,"qcom,tcs-offset",&local_9c,1,0)
                ;
                if ((int)uVar32 < 0) goto LAB_00105374;
                lVar25 = lVar19 + (long)iVar24 * 0x550;
                plVar34 = (long *)(lVar25 + 0x20);
                *plVar34 = *(long *)(lVar25 + 0x18) + (ulong)local_9c;
                plVar29 = (long *)(lVar25 + 0x28);
                uVar14 = readl_relaxed(*(long *)(lVar25 + 0x18) + (ulong)*(uint *)(*plVar29 + 0xc));
                iVar16 = *(int *)(lVar25 + 0x30);
                lVar25 = of_get_next_child(uVar33,0);
                if (lVar25 == 0) {
                  local_b0 = 0;
                }
                else {
                  uVar13 = iVar16 * 6;
                  piVar2 = (int *)(lVar19 + (long)iVar24 * 0x550 + 0x34);
                  local_b0 = 0;
                  do {
                    uVar17 = of_node_name_eq(lVar25,"channel");
                    if ((uVar17 & 1) != 0) {
                      local_80 = 0;
                      local_78 = 0;
                      local_90 = 0;
                      local_88 = 0;
                      local_98[0] = 0;
                      local_98[1] = 0;
                      if (2 < local_b0) {
LAB_00105388:
                    /* WARNING: Does not return */
                        pcVar11 = (code *)SoftwareBreakpoint(0x5512,0x10538c);
                        (*pcVar11)();
                      }
                      iVar16 = of_property_count_elems_of_size(lVar25,"qcom,tcs-config",4);
                      if (iVar16 == 10) {
                        uVar32 = of_property_read_u32_index(lVar25,"qcom,tcs-config",0,local_98);
                        if ((int)uVar32 != 0) goto LAB_00105374;
                        if (local_98[0] < 5) {
                          uVar32 = of_property_read_u32_index
                                             (lVar25,"qcom,tcs-config",1,(ulong)local_98 | 4);
                          if ((int)uVar32 != 0) goto LAB_00105374;
                          if (local_98[1] < 4) {
                            uVar32 = of_property_read_u32_index
                                               (lVar25,"qcom,tcs-config",2,&local_90);
                            if ((int)uVar32 != 0) goto LAB_00105374;
                            if ((uint)local_90 < 5) {
                              uVar32 = of_property_read_u32_index
                                                 (lVar25,"qcom,tcs-config",3,(long)&local_90 + 4);
                              if ((int)uVar32 != 0) goto LAB_00105374;
                              if (local_90._4_4_ < 4) {
                                uVar32 = of_property_read_u32_index
                                                   (lVar25,"qcom,tcs-config",4,&local_88);
                                if ((int)uVar32 != 0) goto LAB_00105374;
                                if ((uint)local_88 < 5) {
                                  uVar32 = of_property_read_u32_index
                                                     (lVar25,"qcom,tcs-config",5,(long)&local_88 + 4
                                                     );
                                  if ((int)uVar32 != 0) goto LAB_00105374;
                                  if (local_88._4_4_ < 4) {
                                    uVar32 = of_property_read_u32_index
                                                       (lVar25,"qcom,tcs-config",6,&local_80);
                                    if ((int)uVar32 != 0) goto LAB_00105374;
                                    if ((uint)local_80 < 5) {
                                      uVar32 = of_property_read_u32_index
                                                         (lVar25,"qcom,tcs-config",7,
                                                          (long)&local_80 + 4);
                                      if ((int)uVar32 != 0) goto LAB_00105374;
                                      if (local_80._4_4_ < 4) {
                                        uVar32 = of_property_read_u32_index
                                                           (lVar25,"qcom,tcs-config",8,&local_78);
                                        if ((int)uVar32 != 0) goto LAB_00105374;
                                        if ((uint)local_78 < 5) {
                                          uVar32 = of_property_read_u32_index
                                                             (lVar25,"qcom,tcs-config",9,
                                                              (long)&local_78 + 4);
                                          if ((int)uVar32 != 0) goto LAB_00105374;
                                          if (local_78._4_4_ < 4) {
                                            lVar27 = 0;
                                            lVar28 = lVar19 + (long)iVar24 * 0x550 +
                                                     local_b0 * 0x150;
                                            lVar26 = lVar28 + 0x68;
                                            uVar15 = 0;
                                            do {
                                              uVar8 = *(uint *)((long)local_98 + lVar27);
                                              if (5 < uVar8) goto LAB_00105388;
                                              plVar4 = (long *)(lVar26 + (ulong)uVar8 * 0x40);
                                              if (*plVar4 != 0) goto LAB_001052f8;
                                              *plVar4 = lVar23;
                                              *(uint *)(plVar4 + 1) = uVar8;
                                              uVar7 = *(uint *)((long)local_98 + lVar27 + 4);
                                              *(uint *)((long)plVar4 + 0x14) = uVar7;
                                              *(uint *)(plVar4 + 3) = uVar14 >> 0x1b;
                                              uVar31 = uVar15;
                                              if ((uVar7 != 0) && (uVar8 != 3)) {
                                                uVar31 = uVar7 + uVar15;
                                                uVar32 = 0xffffffea;
                                                if (((0x3f << (ulong)(uVar13 & 0x1f) & uVar14) >>
                                                     (ulong)(uVar13 & 0x1f) < uVar31) ||
                                                   (0x1f < uVar31)) goto LAB_001052bc;
                                                iVar16 = *piVar2;
                                                lVar5 = lVar26 + (ulong)uVar8 * 0x40;
                                                *(int *)(lVar5 + 0xc) =
                                                     ~(-1 << (ulong)(uVar7 & 0x1f)) <<
                                                     (ulong)(iVar16 + uVar15 & 0x1f);
                                                *(uint *)(lVar5 + 0x10) = iVar16 + uVar15;
                                              }
                                              lVar27 = lVar27 + 8;
                                              uVar15 = uVar31;
                                            } while (lVar27 != 0x28);
                                            uVar15 = readl_relaxed(*plVar34 +
                                                                   (ulong)*(uint *)(*plVar29 + 0x10)
                                                                  );
                                            if (1 < local_b0) goto LAB_00105388;
                                            writel_relaxed(*(uint *)(lVar28 + 0xf4) | uVar15,
                                                           *plVar34 +
                                                           (ulong)*(uint *)(*plVar29 + 0x10));
                                            lVar26 = lVar19 + (long)iVar24 * 0x550 +
                                                     local_b0 * 0x150;
                                            local_b0 = local_b0 + 1;
                                            *piVar2 = *piVar2 + uVar31;
                                            *(long *)(lVar26 + 0x1a8) = lVar23;
                                            *(undefined1 *)(lVar26 + 0x1b0) = 1;
                                            goto LAB_00104dc8;
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
LAB_001052f8:
                      uVar32 = 0xffffffea;
                      goto LAB_001052bc;
                    }
LAB_00104dc8:
                    lVar25 = of_get_next_child(uVar33,lVar25);
                  } while (lVar25 != 0);
                }
                lVar23 = lVar19 + (long)iStack_a0 * 0x550;
                *(int *)(lVar19 + (long)iVar24 * 0x550 + 0x38) = (int)local_b0;
                *(long *)(lVar22 + 0x98) = lVar23;
                *(undefined1 *)(lVar23 + 0x41) = 1;
              }
              lVar21 = of_get_next_child(uVar30,lVar21);
            } while (lVar21 != 0);
          }
          iStack_a0 = 0;
          iVar24 = local_a4;
          if (0 < local_a4) {
            do {
              if (*(char *)(lVar19 + (long)iStack_a0 * 0x550 + 0x41) != '\0') {
                lVar20 = lVar19 + (long)iStack_a0 * 0x550;
                uVar14 = readl_relaxed(*(long *)(lVar20 + 0x18) +
                                       (ulong)*(uint *)(*(long *)(lVar20 + 0x28) + 8));
                lVar20 = lVar19 + (long)iStack_a0 * 0x550;
                *(undefined4 *)(lVar20 + 0x310) = 0;
                *(undefined4 *)(lVar20 + 0x330) = 0;
                lVar20 = of_find_property(uVar30,"power-domains",0);
                iVar24 = iStack_a0;
                if (lVar20 == 0) {
                  if ((uVar14 >> 0x18 & 1) == 0) {
                    lVar20 = of_find_property(uVar30,"qcom,hw-channel",0);
                    if (lVar20 == 0) {
                      *(code **)(lVar19 + (long)iStack_a0 * 0x550 + 0x48) = rpmh_rsc_cpu_pm_callback
                      ;
                      cpu_pm_register_notifier();
                    }
                    else {
                      lVar20 = lVar19 + (long)iStack_a0 * 0x550;
                      *(undefined4 *)(lVar20 + 0x338) = 3;
                      *(undefined1 *)(lVar20 + 0x335) = 1;
                      *(undefined1 *)(lVar20 + 0x40) = 1;
                      *(undefined1 **)(lVar20 + 0x28) = rpmh_rsc_reg_offsets_ver_3_0_hw_channel;
                    }
                  }
                  else {
                    *(undefined4 *)(lVar19 + (long)iStack_a0 * 0x550 + 0x338) = 1;
                  }
                }
                else {
                  lVar20 = lVar19 + (long)iStack_a0 * 0x550;
                  pm_runtime_enable(*(long *)(lVar20 + 0x548) + 0x10);
                  uVar32 = dev_pm_domain_attach(*(long *)(lVar20 + 0x548) + 0x10,0);
                  if ((int)uVar32 != 0) goto LAB_00105374;
                  lVar21 = lVar19 + (long)iVar24 * 0x550;
                  lVar20 = *(long *)(lVar20 + 0x548);
                  *(code **)(lVar21 + 0x520) = rpmh_rsc_pd_cb;
                  uVar32 = dev_pm_genpd_add_notifier(lVar20 + 0x10,lVar21 + 0x520);
                  if ((int)uVar32 != 0) goto LAB_00105374;
                }
                __init_waitqueue_head
                          (lVar19 + (long)iStack_a0 * 0x550 + 0x318,"&drv[i].tcs_wait",
                           &rpmh_rsc_probe___key);
                *(undefined8 *)(lVar19 + (long)iStack_a0 * 0x550 + 0x308) = 0;
                lVar20 = devm_kmalloc(plVar1,8000,0xdc0);
                lVar21 = lVar19 + (long)iStack_a0 * 0x550;
                *(long *)(lVar21 + 0x518) = lVar20;
                if (lVar20 == 0) goto LAB_001052b8;
                lVar20 = 0;
                lVar22 = 0xfa;
                do {
                  lVar22 = lVar22 + -1;
                  lVar23 = *(long *)(lVar21 + 0x518) + lVar20;
                  lVar20 = lVar20 + 0x20;
                  *(long *)(lVar23 + 0x10) = lVar23 + 0x10;
                  *(long *)(lVar23 + 0x18) = lVar23 + 0x10;
                } while (lVar22 != 0);
                uVar17 = platform_get_irq(param_1,*(undefined4 *)
                                                   (lVar19 + (long)iStack_a0 * 0x550 + 0x30));
                uVar32 = uVar17 & 0xffffffff;
                if ((int)uVar17 < 0) goto LAB_001052bc;
                lVar20 = lVar19 + (long)iStack_a0 * 0x550;
                *(int *)(lVar20 + 0x3c) = (int)uVar17;
                uVar32 = devm_request_threaded_irq(plVar1,uVar32,tcs_tx_done,0,0x4004,lVar20,lVar20)
                ;
                if ((int)uVar32 != 0) goto LAB_00105374;
                uVar33 = ipc_log_context_create(2,lVar19 + (long)iStack_a0 * 0x550,0);
                uVar14 = __rsc_count;
                uVar17 = (ulong)__rsc_count;
                *(undefined8 *)(lVar19 + (long)iStack_a0 * 0x550 + 0x540) = uVar33;
                if ((int)uVar14 < 5) {
                  __rsc_count = uVar14 + 1;
                  if (5 < uVar14) {
                    /* WARNING: Does not return */
                    pcVar11 = (code *)SoftwareBreakpoint(1,0x1052b8);
                    (*pcVar11)();
                  }
                  *(long *)(__rsc_drv + uVar17 * 8) = lVar19 + (long)iStack_a0 * 0x550;
                }
                uVar32 = devm_of_platform_populate
                                   (*(undefined8 *)(lVar19 + (long)iStack_a0 * 0x550 + 0x538));
                if ((int)uVar32 != 0) goto LAB_00105374;
                iVar24 = local_a4;
              }
              iStack_a0 = iStack_a0 + 1;
            } while (iStack_a0 < iVar24);
          }
          puVar3 = (undefined *)(lVar18 + 0x28);
          *(undefined **)(lVar18 + 0x28) = puVar3;
          *(undefined **)(lVar18 + 0x30) = puVar3;
          puVar10 = PTR_rpmh_rsc_dev_list_00107428;
          uVar17 = __list_add_valid(puVar3,PTR_rpmh_rsc_dev_list_00107428,&rpmh_rsc_dev_list);
          if ((uVar17 & 1) != 0) {
            PTR_rpmh_rsc_dev_list_00107428 = puVar3;
            *(undefined ***)(lVar18 + 0x28) = &rpmh_rsc_dev_list;
            *(undefined **)(lVar18 + 0x30) = puVar10;
            *(undefined **)puVar10 = puVar3;
          }
          *(long *)(param_1 + 0xa8) = lVar18;
          uVar32 = devm_of_platform_populate(plVar1);
LAB_00105374:
          uVar32 = uVar32 & 0xffffffff;
          goto LAB_001052bc;
        }
      }
LAB_001052b8:
      uVar32 = 0xfffffff4;
    }
    else {
      _dev_err(plVar1,"Command DB not available (%d)\n",uVar17 & 0xffffffff);
    }
  }
LAB_001052bc:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar32 & 0xffffffff;
}



//------------------------------------------------------------
// rpmh_rsc_cpu_pm_callback @ 00105390 size=384
// signature: undefined rpmh_rsc_cpu_pm_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rpmh_rsc_cpu_pm_callback(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  int *piVar3;
  uint *puVar4;
  char cVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 uVar11;
  
  if (param_2 - 1U < 2) {
    piVar3 = (int *)(param_1 + 0x18);
    Hint_Prefetch(piVar3,2,0,1);
    do {
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar3,0x10);
      if (bVar6) {
        *piVar3 = *piVar3 + -1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    return 1;
  }
  if (param_2 != 0) {
    return 0;
  }
  puVar4 = (uint *)(param_1 + 0x18);
  Hint_Prefetch(puVar4,2,0,1);
  do {
    uVar1 = *puVar4 + 1;
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(puVar4,0x10);
    if (bVar6) {
      *puVar4 = uVar1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  DataMemoryBarrier(2,3);
  if (uVar1 < ___num_online_cpus) {
    return 1;
  }
  lVar2 = param_1 + 0x2c8;
  iVar7 = _raw_spin_trylock(lVar2);
  if (iVar7 == 0) {
    return 1;
  }
  if (*(int *)(param_1 + -0x10) == 1) {
LAB_00105414:
    uVar11 = 0;
  }
  else {
    do {
      uVar8 = readl_relaxed(*(long *)(param_1 + -0x30) +
                            (ulong)*(uint *)(*(long *)(param_1 + -0x20) + 0x50));
      uVar9 = readl_relaxed(*(long *)(param_1 + -0x30) +
                            (ulong)*(uint *)(*(long *)(param_1 + -0x20) + 0x54));
    } while (uVar9 != uVar8);
    if ((uVar8 & 1) == 0) {
      if ((uVar8 >> 1 & 1) == 0) goto LAB_00105488;
      goto LAB_00105414;
    }
    uVar11 = 1;
  }
  uVar10 = rpmh_rsc_ctrlr_is_busy(param_1 + -0x48);
  if (((uVar10 & 1) == 0) && (iVar7 = rpmh_flush(param_1 + 0x2e8,uVar11), iVar7 == 0)) {
    _raw_spin_unlock(lVar2);
    return 1;
  }
LAB_00105488:
  _raw_spin_unlock(lVar2);
  if (uVar1 < ___num_online_cpus) {
    return 1;
  }
  piVar3 = (int *)(param_1 + 0x18);
  Hint_Prefetch(piVar3,2,0,1);
  do {
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(piVar3,0x10);
    if (bVar6) {
      *piVar3 = *piVar3 + -1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  return 0x8002;
}



//------------------------------------------------------------
// tcs_tx_done @ 00105544 size=664
// signature: undefined tcs_tx_done(void)
// callers: []
//------------------------------------------------------------

undefined8 tcs_tx_done(undefined8 param_1,long param_2)

{
  ulong *puVar1;
  ulong uVar3;
  ulong uVar2;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  long *plVar7;
  code *pcVar8;
  uint uVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  int iVar13;
  long lVar14;
  long local_78;
  long lStack_70;
  long local_68;
  
  uVar10 = readl_relaxed(*(long *)(param_2 + 0x20) +
                         (ulong)*(uint *)(*(long *)(param_2 + 0x28) + 0x14));
  local_68 = param_2 + 0xe8;
  uVar11 = 0;
  local_78 = param_2 + 0x1f8;
  lStack_70 = param_2 + 0x238;
  uVar6 = sp_el0;
  do {
    uVar11 = -1L << (uVar11 & 0x3f) & uVar10 & 0xffffffff;
    uVar2 = (uVar11 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar11 & 0x5555555555555555) << 1;
    uVar2 = (uVar2 & 0xcccccccccccccccc) >> 2 | (uVar2 & 0x3333333333333333) << 2;
    uVar2 = (uVar2 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar2 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar3 = (uVar2 & 0xff00ff00ff00ff00) >> 8 | (uVar2 & 0xff00ff00ff00ff) << 8;
    uVar2 = 0x20;
    if (uVar11 != 0) {
      uVar2 = LZCOUNT((uVar3 >> 0x10 | (uVar3 & 0xffff0000ffff) << 0x10) << 0x20);
    }
    if (0x1f < uVar2) {
      return 1;
    }
    uVar11 = 1L << (uVar2 & 0x3f);
    if (*(char *)(param_2 + 0x1b0) == '\0') {
LAB_00105618:
      if (*(char *)(param_2 + 0x300) == '\0') goto LAB_0010568c;
      plVar7 = &local_78;
      if (*(int *)(param_2 + 0x24c) != 0) {
        plVar7 = &lStack_70;
      }
      lVar14 = *plVar7;
      if ((uVar11 & *(uint *)(lVar14 + 0xc)) == 0) goto LAB_0010568c;
      lVar12 = 1;
    }
    else {
      lVar14 = param_2 + 0xa8;
      if (*(int *)(param_2 + 0xfc) != 0) {
        lVar14 = local_68;
      }
      if ((uVar11 & *(uint *)(lVar14 + 0xc)) == 0) goto LAB_00105618;
      lVar12 = 0;
    }
    iVar13 = (int)uVar2;
    uVar9 = iVar13 - *(int *)(lVar14 + 0x10);
    if (2 < uVar9) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10588c);
      (*pcVar8)();
    }
    lVar14 = *(long *)(lVar14 + (ulong)uVar9 * 8 + 0x20);
    if (lVar14 == 0) {
LAB_0010568c:
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x800,0x105698);
      (*pcVar8)();
    }
    ipc_log_string(*(undefined8 *)(param_2 + 0x540),"IRQ response: m=%d",uVar2);
    __tcs_set_trigger(param_2,uVar2,0);
    writel_relaxed(0,*(long *)(param_2 + 0x20) + (long)(*(int **)(param_2 + 0x28))[10] +
                     (ulong)(uint)(**(int **)(param_2 + 0x28) * iVar13));
    writel_relaxed(0,*(long *)(param_2 + 0x20) + (long)(*(int **)(param_2 + 0x28))[7] +
                     (ulong)(uint)(**(int **)(param_2 + 0x28) * iVar13));
    writel_relaxed(uVar11 & 0xffffffff,
                   *(long *)(param_2 + 0x20) + (ulong)*(uint *)(*(long *)(param_2 + 0x28) + 0x18));
    uVar9 = readl_relaxed(*(long *)(param_2 + 0x20) + (long)(*(int **)(param_2 + 0x28))[8] +
                          (ulong)(uint)(**(int **)(param_2 + 0x28) * iVar13));
    writel_relaxed(uVar9 & 0xfeffffff,
                   *(long *)(param_2 + 0x20) + (long)(*(int **)(param_2 + 0x28))[8] +
                   (ulong)(uint)(**(int **)(param_2 + 0x28) * iVar13));
    _raw_spin_lock(param_2 + 0x310);
    puVar1 = (ulong *)(param_2 + 0x308);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & (uVar11 ^ 0xffffffffffffffff);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (*(int *)(param_2 + lVar12 * 0x150 + 0xfc) == 0) {
      uVar9 = readl_relaxed(*(long *)(param_2 + 0x20) +
                            (ulong)*(uint *)(*(long *)(param_2 + 0x28) + 0x10));
      writel_relaxed(uVar9 & ((uint)uVar11 ^ 0xffffffff),
                     *(long *)(param_2 + 0x20) + (ulong)*(uint *)(*(long *)(param_2 + 0x28) + 0x10))
      ;
    }
    _raw_spin_unlock(param_2 + 0x310);
    __wake_up(param_2 + 0x318,3,1,0);
    rpmh_tx_done(lVar14);
    uVar11 = uVar2 + 1;
    if (0x1e < uVar2) {
      return 1;
    }
  } while( true );
}



//------------------------------------------------------------
// rpmh_rsc_pd_cb @ 00105890 size=204
// signature: undefined rpmh_rsc_pd_cb(void)
// callers: []
//------------------------------------------------------------

undefined4 rpmh_rsc_pd_cb(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  if (param_2 != 0) {
    return 1;
  }
  if (*(int *)(param_1 + -0x4e8) != 1) {
    do {
      uVar1 = readl_relaxed(*(long *)(param_1 + -0x508) +
                            (ulong)*(uint *)(*(long *)(param_1 + -0x4f8) + 0x50));
      uVar2 = readl_relaxed(*(long *)(param_1 + -0x508) +
                            (ulong)*(uint *)(*(long *)(param_1 + -0x4f8) + 0x54));
    } while (uVar2 != uVar1);
    if ((uVar1 & 1) != 0) {
      uVar6 = 1;
      goto LAB_00105920;
    }
    if ((uVar1 >> 1 & 1) == 0) {
      return 0x8002;
    }
  }
  uVar6 = 0;
LAB_00105920:
  uVar4 = rpmh_rsc_ctrlr_is_busy(param_1 + -0x520);
  uVar5 = 0x8002;
  if ((uVar4 & 1) == 0) {
    iVar3 = _rpmh_flush(param_1 + -0x1f0,uVar6);
    uVar5 = 0x8002;
    if (iVar3 == 0) {
      uVar5 = 1;
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// rpmh_rsc_poweroff_noirq @ 00105960 size=8
// signature: undefined rpmh_rsc_poweroff_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 rpmh_rsc_poweroff_noirq(void)

{
  return 0;
}



//------------------------------------------------------------
// rpmh_rsc_restore_noirq @ 0010596c size=260
// signature: undefined rpmh_rsc_restore_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 rpmh_rsc_restore_noirq(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  long *plVar8;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (0 < *(int *)(lVar3 + 0x14)) {
    lVar4 = 0;
    lVar5 = 0x300;
    do {
      lVar6 = *(long *)(lVar3 + 0x18);
      lVar1 = lVar6 + lVar5;
      if (*(char *)(lVar1 + -0x2bf) != '\0') {
        plVar7 = (long *)(lVar1 + -0x2e0);
        plVar8 = (long *)(lVar1 + -0x2d8);
        if (*(char *)(lVar1 + -0x150) != '\0') {
          uVar2 = readl_relaxed(*plVar7 + (ulong)*(uint *)(*plVar8 + 0x10));
          writel_relaxed(*(uint *)(lVar6 + lVar5 + -0x20c) | uVar2,
                         *plVar7 + (ulong)*(uint *)(*plVar8 + 0x10));
        }
        if (*(char *)(lVar6 + lVar5) != '\0') {
          uVar2 = readl_relaxed(*plVar7 + (ulong)*(uint *)(*plVar8 + 0x10));
          writel_relaxed(*(uint *)(lVar6 + lVar5 + -0xbc) | uVar2,
                         *plVar7 + (ulong)*(uint *)(*plVar8 + 0x10));
        }
      }
      lVar4 = lVar4 + 1;
      lVar5 = lVar5 + 0x550;
    } while (lVar4 < *(int *)(lVar3 + 0x14));
  }
  return 0;
}



//------------------------------------------------------------
// rpmh_tx_done @ 00105aa4 size=36
// signature: undefined rpmh_tx_done(void)
// callers: [tcs_tx_done]
//------------------------------------------------------------

void rpmh_tx_done(long param_1)

{
  if (*(long *)(param_1 + 0xd8) != 0) {
    complete();
  }
  return;
}



//------------------------------------------------------------
// rpmh_write_async @ 00105acc size=344
// signature: undefined rpmh_write_async(void)
// callers: []
//------------------------------------------------------------

void rpmh_write_async(long param_1,uint param_2,void *param_3,uint param_4)

{
  char cVar1;
  undefined8 uVar2;
  long lVar3;
  ulong local_140;
  undefined8 local_138;
  undefined8 *local_130;
  undefined8 uStack_128;
  undefined8 local_120;
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
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  long lStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
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
  uStack_128 = 0;
  local_138 = 0;
  local_140 = (ulong)param_2;
  local_120 = 0;
  local_68 = 0;
  local_130 = &uStack_128;
  lStack_60 = param_1;
  if (rpmh_standalone == '\0') {
    lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    local_140 = (ulong)param_2;
    if ((param_2 == 2) && ((*(byte *)(lVar3 + 0x338) & 1) != 0)) {
      _raw_spin_lock(lVar3 + 0x330);
      cVar1 = *(char *)(lVar3 + 0x335);
      _raw_spin_unlock(lVar3 + 0x330);
      if (cVar1 != '\0') {
        uVar2 = 0xfffffff0;
        goto LAB_00105bec;
      }
    }
    uVar2 = 0xffffffea;
    if ((param_3 != (void *)0x0) && (0xffffffef < param_4 - 0x11)) {
      memcpy(&uStack_128,param_3,(ulong)param_4 * 0xc);
      local_140 = CONCAT44(local_140._4_4_,param_2);
      local_138 = CONCAT44(local_138._4_4_,param_4);
      local_130 = &uStack_128;
      uVar2 = __rpmh_write(param_1,param_2,&local_140);
    }
  }
  else {
    uVar2 = 0;
  }
LAB_00105bec:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// __rpmh_write @ 00105c24 size=488
// signature: undefined __rpmh_write(void)
// callers: [rpmh_write_async, rpmh_write]
//------------------------------------------------------------

ulong __rpmh_write(long param_1,int param_2,long param_3)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  bool bVar5;
  undefined8 uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  ulong uVar10;
  int iVar11;
  ulong uVar12;
  long lVar13;
  int *piVar14;
  long lVar15;
  uint uVar16;
  
  lVar13 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(int *)(param_3 + 8) != 0) {
    uVar16 = 0;
    lVar1 = lVar13 + 0x330;
    do {
      lVar15 = *(long *)(param_3 + 0x10);
      uVar6 = _raw_spin_lock_irqsave(lVar1);
      uVar2 = *(uint *)(lVar13 + 0x510);
      uVar10 = (ulong)uVar2;
      if (0xf9 < uVar2) {
LAB_00105dc4:
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        piVar14 = (int *)0xfffffff4;
        goto LAB_00105de4;
      }
      piVar8 = (int *)(lVar15 + (long)(int)uVar16 * 0xc);
      piVar9 = *(int **)(lVar13 + 0x518);
      if (uVar2 == 0) {
        uVar10 = 0;
      }
      else {
        uVar12 = 0;
        piVar14 = piVar9;
        do {
          if (*piVar14 == *piVar8) goto LAB_00105ce0;
          uVar12 = uVar12 + 1;
          piVar14 = piVar14 + 8;
        } while (uVar10 != uVar12);
      }
      (piVar9 + uVar10 * 8 + 1)[0] = -1;
      (piVar9 + uVar10 * 8 + 1)[1] = -1;
      *(int *)(lVar13 + 0x510) = *(int *)(lVar13 + 0x510) + 1;
      uVar12 = uVar10;
LAB_00105ce0:
      piVar14 = piVar9 + uVar12 * 8;
      if (piVar14 == (int *)0x0) goto LAB_00105dc4;
      iVar3 = piVar9[uVar12 * 8 + 1];
      *piVar14 = *piVar8;
      iVar7 = piVar9[uVar12 * 8 + 2];
      if (param_2 - 1U < 2) {
        iVar11 = *(int *)(lVar15 + (long)(int)uVar16 * 0xc + 4);
        piVar9[uVar12 * 8 + 2] = iVar11;
        if (iVar11 == iVar7) goto LAB_00105d58;
        iVar7 = iVar11;
        iVar11 = iVar3;
LAB_00105d44:
        if (iVar11 == -1) goto LAB_00105d58;
        bVar5 = iVar7 != -1;
      }
      else {
        if (param_2 == 0) {
          iVar11 = *(int *)(lVar15 + (long)(int)uVar16 * 0xc + 4);
          piVar9[uVar12 * 8 + 1] = iVar11;
          if (iVar11 != iVar3) goto LAB_00105d44;
        }
LAB_00105d58:
        bVar5 = false;
      }
      *(byte *)(lVar13 + 0x334) = *(byte *)(lVar13 + 0x334) | bVar5;
      _raw_spin_unlock_irqrestore(lVar1,uVar6);
      if ((int *)0xfffffffffffff000 < piVar14) goto LAB_00105de4;
      uVar16 = uVar16 + 1;
    } while (uVar16 < *(uint *)(param_3 + 8));
  }
  if (param_2 == 2) {
    uVar10 = daif;
    if ((uVar10 & 0x80) != 0) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x800,0x105e0c);
      (*pcVar4)();
    }
    uVar10 = rpmh_rsc_get_channel(lVar13);
    piVar14 = (int *)(uVar10 & 0xffffffff);
    if (-1 < (int)uVar10) {
      uVar10 = rpmh_rsc_send_data(lVar13,param_3,piVar14);
      piVar14 = (int *)(uVar10 & 0xffffffff);
    }
  }
  else {
    if (*(long *)(param_3 + 0xd8) != 0) {
      complete();
    }
    piVar14 = (int *)0x0;
  }
LAB_00105de4:
  return (ulong)piVar14 & 0xffffffff;
}



//------------------------------------------------------------
// rpmh_write @ 00105e14 size=400
// signature: undefined rpmh_write(void)
// callers: []
//------------------------------------------------------------

void rpmh_write(long param_1,int param_2,void *param_3,uint param_4)

{
  char cVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 ***local_160;
  undefined8 ***pppuStack_158;
  int local_150 [4];
  undefined8 *local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 *puStack_78;
  long local_70;
  long local_68;
  
  puStack_78 = (undefined1 *)&local_170;
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  local_160 = &local_160;
  local_80 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_150[1] = 1;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_150[2] = 0;
  local_150[3] = 0;
  local_138 = 0;
  pppuStack_158 = local_160;
  local_150[0] = param_2;
  local_140 = &local_138;
  puVar2 = &local_170;
  local_70 = param_1;
  if (rpmh_standalone == '\0') {
    lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    puVar2 = &local_170;
    if ((param_2 == 2) && (puVar2 = &local_170, (*(byte *)(lVar5 + 0x338) & 1) != 0)) {
      _raw_spin_lock(lVar5 + 0x330);
      cVar1 = *(char *)(lVar5 + 0x335);
      _raw_spin_unlock(lVar5 + 0x330);
      puVar2 = (undefined8 *)puStack_78;
      if (cVar1 != '\0') {
        uVar4 = 0xfffffff0;
        goto LAB_00105eb0;
      }
    }
    puStack_78 = (undefined1 *)puVar2;
    uVar4 = 0xffffffea;
    if ((param_3 == (void *)0x0) || (param_4 - 0x11 < 0xfffffff0)) goto LAB_00105eb0;
    memcpy(&local_138,param_3,(ulong)param_4 * 0xc);
    local_150[2] = param_4;
    local_150[0] = param_2;
    local_140 = &local_138;
    uVar4 = __rpmh_write(param_1,param_2,local_150);
    if ((int)uVar4 != 0) goto LAB_00105eb0;
    iVar3 = wait_for_completion_timeout(&local_170,0x9c4);
    puVar2 = (undefined8 *)puStack_78;
    if (iVar3 == 0) {
      rpmh_rsc_debug(lVar5,&local_170);
      uVar4 = 0xffffff92;
      goto LAB_00105eb0;
    }
  }
  puStack_78 = (undefined1 *)puVar2;
  uVar4 = 0;
LAB_00105eb0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// rpmh_write_batch @ 00105fa8 size=704
// signature: undefined rpmh_write_batch(void)
// callers: []
//------------------------------------------------------------

int rpmh_write_batch(long param_1,uint param_2,void *param_3,uint *param_4)

{
  long lVar1;
  void *__dest;
  uint uVar2;
  char cVar3;
  undefined8 *puVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 ****local_160;
  undefined8 ****ppppuStack_158;
  uint local_150 [4];
  undefined8 *local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined1 *puStack_78;
  long local_70;
  long local_68;
  
  puStack_78 = (undefined1 *)&local_170;
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_160 = &local_160;
  local_80 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_150[1] = 1;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_150[2] = 0;
  local_150[3] = 0;
  local_138 = 0;
  ppppuStack_158 = local_160;
  local_150[0] = param_2;
  local_140 = &local_138;
  puVar4 = &local_170;
  local_70 = param_1;
  if (rpmh_standalone == '\0') {
    lVar9 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    lVar1 = lVar9 + 0x330;
    if (param_2 != 2) {
      uVar7 = _raw_spin_lock_irqsave(lVar1);
      if (2 < param_2) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x106268);
        (*pcVar5)();
      }
      iVar6 = -0x16;
      lVar8 = lVar9 + (ulong)param_2 * 0xe8;
      *(undefined8 *)(lVar8 + 0x420) = 0;
      *(undefined8 *)(lVar8 + 0x418) = 0;
      *(undefined8 *)(lVar8 + 0x410) = 0;
      *(undefined8 *)(lVar8 + 0x408) = 0;
      *(undefined8 *)(lVar8 + 0x400) = 0;
      *(undefined8 *)(lVar8 + 0x3f8) = 0;
      *(undefined8 *)(lVar8 + 0x3f0) = 0;
      *(undefined8 *)(lVar8 + 1000) = 0;
      *(undefined8 *)(lVar8 + 0x3e0) = 0;
      *(undefined8 *)(lVar8 + 0x3d8) = 0;
      *(undefined8 *)(lVar8 + 0x3d0) = 0;
      *(undefined8 *)(lVar8 + 0x3c8) = 0;
      *(undefined8 *)(lVar8 + 0x3c0) = 0;
      *(undefined8 *)(lVar8 + 0x3b8) = 0;
      *(undefined8 *)(lVar8 + 0x3b0) = 0;
      *(undefined8 *)(lVar8 + 0x3a8) = 0;
      *(undefined8 *)(lVar8 + 0x3a0) = 0;
      *(undefined8 *)(lVar8 + 0x398) = 0;
      *(undefined8 *)(lVar8 + 0x390) = 0;
      *(undefined8 *)(lVar8 + 0x388) = 0;
      *(undefined8 *)(lVar8 + 0x380) = 0;
      *(undefined8 *)(lVar8 + 0x378) = 0;
      *(undefined8 *)(lVar8 + 0x370) = 0;
      *(undefined8 *)(lVar8 + 0x368) = 0;
      *(undefined8 *)(lVar8 + 0x360) = 0;
      *(undefined8 *)(lVar8 + 0x358) = 0;
      *(undefined8 *)(lVar8 + 0x350) = 0;
      *(undefined8 *)(lVar8 + 0x348) = 0;
      *(undefined8 *)(lVar8 + 0x340) = 0;
      if (param_3 != (void *)0x0) {
        uVar2 = *param_4;
        if (0xffffffef < uVar2 - 0x11) {
          __dest = (void *)(lVar9 + (ulong)param_2 * 0xe8 + 0x358);
          memcpy(__dest,param_3,(ulong)uVar2 * 0xc);
          iVar6 = 0;
          *(uint *)(lVar8 + 0x340) = param_2;
          *(void **)(lVar8 + 0x350) = __dest;
          *(uint *)(lVar8 + 0x348) = uVar2;
        }
      }
      *(undefined1 *)(lVar9 + 0x334) = 1;
      _raw_spin_unlock_irqrestore(lVar1,uVar7);
      goto LAB_00106184;
    }
    puStack_78 = (undefined1 *)&local_170;
    if ((*(byte *)(lVar9 + 0x338) & 1) != 0) {
      puStack_78 = (undefined1 *)&local_170;
      _raw_spin_lock(lVar1);
      cVar3 = *(char *)(lVar9 + 0x335);
      _raw_spin_unlock(lVar1);
      if (cVar3 != '\0') {
        iVar6 = -0x10;
        goto LAB_00106184;
      }
    }
    iVar6 = -0x16;
    if (param_3 == (void *)0x0) goto LAB_00106184;
    uVar2 = *param_4;
    if (uVar2 - 0x11 < 0xfffffff0) goto LAB_00106184;
    memcpy(&local_138,param_3,(ulong)uVar2 * 0xc);
    local_150[2] = uVar2;
    local_150[0] = 2;
    local_140 = &local_138;
    iVar6 = rpmh_rsc_get_channel(lVar9);
    if (iVar6 < 0) goto LAB_00106184;
    iVar6 = rpmh_rsc_send_data(lVar9,local_150,iVar6);
    if (iVar6 != 0) {
      _printk(&DAT_00107a7e,iVar6,*(undefined4 *)local_140);
      goto LAB_00106184;
    }
    iVar6 = wait_for_completion_timeout(&local_170,0x9c4);
    puVar4 = (undefined8 *)puStack_78;
    if (iVar6 == 0) {
      rpmh_rsc_debug(lVar9,&local_170);
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x106240);
      (*pcVar5)();
    }
  }
  puStack_78 = (undefined1 *)puVar4;
  iVar6 = 0;
LAB_00106184:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// _rpmh_flush @ 0010626c size=488
// signature: undefined _rpmh_flush(void)
// callers: [rpmh_write_sleep_and_wake, rpmh_rsc_pd_cb, rpmh_flush, rpmh_write_sleep_and_wake_no_child]
//------------------------------------------------------------

void _rpmh_flush(long param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  undefined8 local_158;
  undefined8 local_150;
  undefined4 *local_148;
  undefined4 local_140;
  int iStack_13c;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar7 = sp_el0;
  local_70 = *(long *)(lVar7 + 0x638);
  if (*(char *)(param_1 + 4) == '\0') {
    uVar4 = 0;
  }
  else {
    lVar7 = param_1 + -0x330;
    rpmh_rsc_invalidate(lVar7);
    uVar4 = rpmh_rsc_write_ctrl_data(lVar7,param_1 + 0x10,param_2);
    if (((int)uVar4 == 0) &&
       (uVar4 = rpmh_rsc_write_ctrl_data(lVar7,param_1 + 0xf8,param_2), (int)uVar4 == 0)) {
      uVar5 = *(uint *)(param_1 + 0x1e0);
      if (uVar5 != 0) {
        uVar6 = 0;
        do {
          puVar1 = (undefined4 *)(*(long *)(param_1 + 0x1e8) + (long)(int)uVar6 * 0x20);
          iVar2 = puVar1[1];
          if ((iVar2 != -1) && (iVar3 = puVar1[2], iVar3 != -1 && iVar2 != iVar3)) {
            local_80 = 0;
            uStack_78 = 0;
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            local_b0 = 0;
            uStack_a8 = 0;
            local_c0 = 0;
            uStack_b8 = 0;
            local_d0 = 0;
            uStack_c8 = 0;
            local_e0 = 0;
            uStack_d8 = 0;
            local_f0 = 0;
            uStack_e8 = 0;
            local_100 = 0;
            uStack_f8 = 0;
            local_110 = 0;
            uStack_108 = 0;
            local_120 = 0;
            uStack_118 = 0;
            local_130 = 0;
            uStack_128 = 0;
            uStack_138 = 0;
            local_158 = 0;
            _local_140 = CONCAT44(iVar2,*puVar1);
            local_150 = 1;
            local_148 = &local_140;
            uVar4 = rpmh_rsc_write_ctrl_data(lVar7,&local_158,param_2);
            if ((int)uVar4 != 0) goto LAB_00106308;
            local_80 = 0;
            uStack_78 = 0;
            local_90 = 0;
            uStack_88 = 0;
            local_a0 = 0;
            uStack_98 = 0;
            local_b0 = 0;
            uStack_a8 = 0;
            local_c0 = 0;
            uStack_b8 = 0;
            local_d0 = 0;
            uStack_c8 = 0;
            local_e0 = 0;
            uStack_d8 = 0;
            local_f0 = 0;
            uStack_e8 = 0;
            local_100 = 0;
            uStack_f8 = 0;
            local_110 = 0;
            uStack_108 = 0;
            local_120 = 0;
            uStack_118 = 0;
            local_130 = 0;
            uStack_128 = 0;
            uStack_138 = 0;
            local_158 = 0x100000001;
            _local_140 = CONCAT44(puVar1[2],*puVar1);
            local_150 = 1;
            local_148 = &local_140;
            uVar4 = rpmh_rsc_write_ctrl_data(lVar7,&local_158,param_2);
            if ((int)uVar4 != 0) goto LAB_00106308;
            uVar5 = *(uint *)(param_1 + 0x1e0);
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar5);
      }
      uVar4 = 0;
      *(undefined1 *)(param_1 + 4) = 0;
    }
  }
LAB_00106308:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// rpmh_flush @ 00106458 size=108
// signature: undefined rpmh_flush(void)
// callers: [rpmh_rsc_cpu_pm_callback, rpmh_rsc_drv_enable]
//------------------------------------------------------------

undefined4 rpmh_flush(undefined8 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (rpmh_standalone == '\0') {
    uVar2 = _raw_spin_lock_irqsave();
    uVar1 = _rpmh_flush(param_1,param_2);
    _raw_spin_unlock_irqrestore(param_1,uVar2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// rpmh_write_sleep_and_wake @ 001064c8 size=176
// signature: undefined rpmh_write_sleep_and_wake(void)
// callers: []
//------------------------------------------------------------

int rpmh_write_sleep_and_wake(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = rpmh_rsc_get_channel(lVar5);
  if (-1 < iVar2) {
    if (rpmh_standalone == '\0') {
      lVar1 = lVar5 + 0x330;
      uVar4 = _raw_spin_lock_irqsave(lVar1);
      iVar3 = _rpmh_flush(lVar1,iVar2);
      _raw_spin_unlock_irqrestore(lVar1,uVar4);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((*(byte *)(lVar5 + 0x338) >> 1 & 1) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = rpmh_rsc_switch_channel(lVar5,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// rpmh_write_sleep_and_wake_no_child @ 0010657c size=188
// signature: undefined rpmh_write_sleep_and_wake_no_child(void)
// callers: []
//------------------------------------------------------------

int rpmh_write_sleep_and_wake_no_child(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x98);
  iVar3 = rpmh_rsc_get_channel(lVar6);
  if (iVar3 < 0) {
    rpmh_rsc_debug_channel_busy(lVar6);
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10662c);
    (*pcVar2)();
  }
  if (rpmh_standalone == '\0') {
    lVar1 = lVar6 + 0x330;
    uVar5 = _raw_spin_lock_irqsave(lVar1);
    iVar4 = _rpmh_flush(lVar1,iVar3);
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    if (iVar4 != 0) {
      return iVar4;
    }
  }
  if (((*(byte *)(lVar6 + 0x338) >> 1 & 1) != 0) &&
     (iVar3 = rpmh_rsc_switch_channel(lVar6,iVar3), iVar3 != 0)) {
    rpmh_rsc_debug_channel_busy(lVar6);
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x106638);
    (*pcVar2)();
  }
  return 0;
}



//------------------------------------------------------------
// rpmh_invalidate @ 0010663c size=316
// signature: undefined rpmh_invalidate(void)
// callers: []
//------------------------------------------------------------

void rpmh_invalidate(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (rpmh_standalone == '\0') {
    lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    uVar1 = _raw_spin_lock_irqsave(lVar2 + 0x330);
    *(undefined8 *)(lVar2 + 0x340) = 0;
    *(undefined8 *)(lVar2 + 0x348) = 0;
    *(undefined8 *)(lVar2 + 0x350) = 0;
    *(undefined8 *)(lVar2 + 0x358) = 0;
    *(undefined8 *)(lVar2 + 0x360) = 0;
    *(undefined8 *)(lVar2 + 0x368) = 0;
    *(undefined8 *)(lVar2 + 0x370) = 0;
    *(undefined8 *)(lVar2 + 0x378) = 0;
    *(undefined8 *)(lVar2 + 0x380) = 0;
    *(undefined8 *)(lVar2 + 0x388) = 0;
    *(undefined8 *)(lVar2 + 0x390) = 0;
    *(undefined8 *)(lVar2 + 0x398) = 0;
    *(undefined8 *)(lVar2 + 0x3a0) = 0;
    *(undefined8 *)(lVar2 + 0x3a8) = 0;
    *(undefined8 *)(lVar2 + 0x3b0) = 0;
    *(undefined8 *)(lVar2 + 0x3b8) = 0;
    *(undefined8 *)(lVar2 + 0x3c0) = 0;
    *(undefined8 *)(lVar2 + 0x3c8) = 0;
    *(undefined8 *)(lVar2 + 0x3d0) = 0;
    *(undefined8 *)(lVar2 + 0x3d8) = 0;
    *(undefined8 *)(lVar2 + 0x3e0) = 0;
    *(undefined8 *)(lVar2 + 1000) = 0;
    *(undefined8 *)(lVar2 + 0x3f0) = 0;
    *(undefined8 *)(lVar2 + 0x3f8) = 0;
    *(undefined8 *)(lVar2 + 0x400) = 0;
    *(undefined8 *)(lVar2 + 0x408) = 0;
    *(undefined8 *)(lVar2 + 0x410) = 0;
    *(undefined8 *)(lVar2 + 0x418) = 0;
    *(undefined8 *)(lVar2 + 0x420) = 0;
    *(undefined8 *)(lVar2 + 0x508) = 0;
    *(undefined8 *)(lVar2 + 0x500) = 0;
    *(undefined8 *)(lVar2 + 0x4f8) = 0;
    *(undefined8 *)(lVar2 + 0x4f0) = 0;
    *(undefined8 *)(lVar2 + 0x4e8) = 0;
    *(undefined8 *)(lVar2 + 0x4e0) = 0;
    *(undefined8 *)(lVar2 + 0x4d8) = 0;
    *(undefined8 *)(lVar2 + 0x4d0) = 0;
    *(undefined8 *)(lVar2 + 0x4c8) = 0;
    *(undefined8 *)(lVar2 + 0x4c0) = 0;
    *(undefined8 *)(lVar2 + 0x4b8) = 0;
    *(undefined8 *)(lVar2 + 0x4b0) = 0;
    *(undefined8 *)(lVar2 + 0x4a8) = 0;
    *(undefined8 *)(lVar2 + 0x4a0) = 0;
    *(undefined8 *)(lVar2 + 0x498) = 0;
    *(undefined8 *)(lVar2 + 0x490) = 0;
    *(undefined8 *)(lVar2 + 0x488) = 0;
    *(undefined8 *)(lVar2 + 0x480) = 0;
    *(undefined8 *)(lVar2 + 0x478) = 0;
    *(undefined8 *)(lVar2 + 0x470) = 0;
    *(undefined8 *)(lVar2 + 0x468) = 0;
    *(undefined8 *)(lVar2 + 0x460) = 0;
    *(undefined8 *)(lVar2 + 0x458) = 0;
    *(undefined8 *)(lVar2 + 0x450) = 0;
    *(undefined8 *)(lVar2 + 0x448) = 0;
    *(undefined8 *)(lVar2 + 0x440) = 0;
    *(undefined8 *)(lVar2 + 0x438) = 0;
    *(undefined8 *)(lVar2 + 0x430) = 0;
    *(undefined8 *)(lVar2 + 0x428) = 0;
    *(undefined1 *)(lVar2 + 0x334) = 1;
    _raw_spin_unlock_irqrestore(lVar2 + 0x330,uVar1);
  }
  return;
}



//------------------------------------------------------------
// rpmh_mode_solver_set @ 0010677c size=140
// signature: undefined rpmh_mode_solver_set(void)
// callers: []
//------------------------------------------------------------

int rpmh_mode_solver_set(long param_1,byte param_2)

{
  int iVar1;
  long lVar2;
  
  if (rpmh_standalone == '\0') {
    lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    if ((*(byte *)(lVar2 + 0x338) & 1) == 0) {
      iVar1 = -0x16;
    }
    else {
      _raw_spin_lock(lVar2 + 0x330);
      iVar1 = rpmh_rsc_mode_solver_set(lVar2,param_2 & 1);
      if (iVar1 == 0) {
        *(byte *)(lVar2 + 0x335) = param_2 & 1;
      }
      _raw_spin_unlock(lVar2 + 0x330);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// rpmh_init_fast_path @ 0010680c size=168
// signature: undefined rpmh_init_fast_path(void)
// callers: []
//------------------------------------------------------------

int rpmh_init_fast_path(long param_1,undefined8 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  uStack_48 = 0;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x98);
  if (rpmh_standalone == '\0') {
    iVar2 = rpmh_rsc_get_channel(uVar3);
    if (-1 < iVar2) {
      local_50 = local_50 & 0xffffffff;
      uStack_48 = CONCAT44(uStack_48._4_4_,param_3);
      local_40 = param_2;
      iVar2 = rpmh_rsc_init_fast_path(uVar3,&local_50);
    }
  }
  else {
    iVar2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// rpmh_update_fast_path @ 001068b8 size=176
// signature: undefined rpmh_update_fast_path(void)
// callers: []
//------------------------------------------------------------

int rpmh_update_fast_path(long param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  uStack_48 = 0;
  uVar3 = *(undefined8 *)(*(long *)(param_1 + 0x60) + 0x98);
  if (rpmh_standalone == '\0') {
    iVar2 = rpmh_rsc_get_channel(uVar3);
    if (-1 < iVar2) {
      local_50 = local_50 & 0xffffffff;
      uStack_48 = CONCAT44(uStack_48._4_4_,param_3);
      local_40 = param_2;
      iVar2 = rpmh_rsc_update_fast_path(uVar3,&local_50,param_4);
    }
  }
  else {
    iVar2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// rpmh_get_device @ 0010696c size=28
// signature: undefined rpmh_get_device(void)
// callers: []
//------------------------------------------------------------

void rpmh_get_device(void)

{
  rpmh_rsc_get_device();
  return;
}



//------------------------------------------------------------
// rpmh_drv_start @ 0010698c size=80
// signature: undefined rpmh_drv_start(void)
// callers: []
//------------------------------------------------------------

undefined8 rpmh_drv_start(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (rpmh_standalone == '\0') {
    uVar3 = *(undefined8 *)(param_1 + 0x98);
    iVar2 = rpmh_rsc_drv_enable(uVar3,1);
    if (iVar2 != 0) {
      rpmh_rsc_debug_channel_busy(uVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1069dc);
      (*pcVar1)();
    }
  }
  return 0;
}



//------------------------------------------------------------
// rpmh_drv_stop @ 001069e0 size=80
// signature: undefined rpmh_drv_stop(void)
// callers: []
//------------------------------------------------------------

undefined8 rpmh_drv_stop(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (rpmh_standalone == '\0') {
    uVar3 = *(undefined8 *)(param_1 + 0x98);
    iVar2 = rpmh_rsc_drv_enable(uVar3,0);
    if (iVar2 != 0) {
      rpmh_rsc_debug_channel_busy(uVar3);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x106a30);
      (*pcVar1)();
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00106a84 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&rpmh_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// strlen @ 0010a000 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_rpmh_send_msg, trace_event_raw_event_rpmh_solver_set, perf_trace_rpmh_solver_set, trace_event_raw_event_rpmh_drv_enable, trace_event_raw_event_rpmh_tx_done, perf_trace_rpmh_switch_channel, perf_trace_rpmh_tx_done, perf_trace_rpmh_drv_enable, perf_trace_rpmh_send_msg, trace_event_raw_event_rpmh_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010a008 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_rpmh_send_msg, trace_event_raw_event_rpmh_solver_set, trace_event_raw_event_rpmh_drv_enable, trace_event_raw_event_rpmh_tx_done, trace_event_raw_event_rpmh_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0010a010 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_rpmh_send_msg, trace_event_raw_event_rpmh_solver_set, perf_trace_rpmh_solver_set, trace_event_raw_event_rpmh_drv_enable, trace_event_raw_event_rpmh_tx_done, perf_trace_rpmh_switch_channel, perf_trace_rpmh_tx_done, perf_trace_rpmh_drv_enable, perf_trace_rpmh_send_msg, trace_event_raw_event_rpmh_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010a018 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_rpmh_send_msg, trace_event_raw_event_rpmh_solver_set, trace_event_raw_event_rpmh_drv_enable, trace_event_raw_event_rpmh_tx_done, trace_event_raw_event_rpmh_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010a020 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_rpmh_send_msg, trace_event_raw_event_rpmh_solver_set, trace_event_raw_event_rpmh_drv_enable, trace_event_raw_event_rpmh_tx_done, trace_event_raw_event_rpmh_switch_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_event_raw_event_rpmh_send_msg, print_tcs_info, trace_event_raw_event_rpmh_drv_enable, rpmh_rsc_send_data, trace_event_raw_event_rpmh_tx_done, perf_trace_rpmh_switch_channel, rpmh_rsc_probe, rpmh_rsc_debug, perf_trace_rpmh_drv_enable, perf_trace_rpmh_send_msg, trace_event_raw_event_rpmh_switch_channel, rpmh_write_batch, rpmh_update_fast_path, trace_event_raw_event_rpmh_solver_set, _rpmh_flush, perf_trace_rpmh_solver_set, rpmh_write_async, rpmh_init_fast_path, perf_trace_rpmh_tx_done, claim_tcs_for_req, rpmh_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010a030 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_rpmh_solver_set, perf_trace_rpmh_switch_channel, perf_trace_rpmh_tx_done, perf_trace_rpmh_drv_enable, perf_trace_rpmh_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010a038 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_rpmh_solver_set, perf_trace_rpmh_switch_channel, perf_trace_rpmh_tx_done, perf_trace_rpmh_drv_enable, perf_trace_rpmh_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 0010a040 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_rpmh_switch_channel, __bpf_trace_rpmh_drv_enable, __bpf_trace_rpmh_tx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 0010a048 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_rpmh_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0010a050 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_rpmh_solver_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010a058 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010a060 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 0010a068 size=1
// signature: undefined _find_first_bit(void)
// callers: [tcs_invalidate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0010a070 size=1
// signature: undefined __const_udelay(void)
// callers: [rpmh_rsc_is_tcs_completed, tcs_invalidate, rpmh_rsc_send_data, rpmh_rsc_update_fast_path, claim_tcs_for_req, __tcs_set_trigger]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a078 size=1
// signature: undefined _printk(void)
// callers: [print_tcs_info, tcs_invalidate, rpmh_rsc_send_data, rpmh_rsc_debug_channel_busy, rpmh_rsc_update_fast_path, rpmh_rsc_debug, __tcs_set_trigger, rpmh_write_batch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010a080 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [tcs_invalidate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 0010a088 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 0010a090 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010a098 size=1
// signature: undefined init_wait_entry(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010a0a0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0010a0a8 size=1
// signature: undefined schedule(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010a0b0 size=1
// signature: undefined finish_wait(void)
// callers: [rpmh_rsc_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010a0c0 size=1
// signature: undefined ipc_log_string(void)
// callers: [rpmh_rsc_write_ctrl_data, rpmh_rsc_is_tcs_completed, __tcs_buffer_write, rpmh_rsc_send_data, tcs_tx_done, rpmh_rsc_drv_enable, rpmh_rsc_mode_solver_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010a0c8 size=1
// signature: undefined __wake_up(void)
// callers: [rpmh_rsc_send_data, tcs_tx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0010a0d0 size=1
// signature: undefined _find_next_bit(void)
// callers: [rpmh_rsc_ctrlr_is_busy, print_tcs_info, claim_tcs_for_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_match_resource_addr @ 0010a0d8 size=1
// signature: undefined cmd_db_match_resource_addr(void)
// callers: [claim_tcs_for_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_match_resource_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_zero_bit @ 0010a0e0 size=1
// signature: undefined _find_next_zero_bit(void)
// callers: [claim_tcs_for_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_zero_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bitmap_find_next_zero_area_off @ 0010a100 size=1
// signature: undefined bitmap_find_next_zero_area_off(void)
// callers: [rpmh_rsc_write_ctrl_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bitmap_find_next_zero_area_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_set @ 0010a108 size=1
// signature: undefined __bitmap_set(void)
// callers: [rpmh_rsc_write_ctrl_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_dump_regs @ 0010a110 size=1
// signature: undefined crm_dump_regs(void)
// callers: [rpmh_rsc_debug_channel_busy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_dump_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_dump_drv_regs @ 0010a118 size=1
// signature: undefined crm_dump_drv_regs(void)
// callers: [rpmh_rsc_debug_channel_busy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_dump_drv_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irq_data @ 0010a120 size=1
// signature: undefined irq_get_irq_data(void)
// callers: [rpmh_rsc_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irqchip_state @ 0010a128 size=1
// signature: undefined irq_get_irqchip_state(void)
// callers: [rpmh_rsc_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irqchip_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// completion_done @ 0010a130 size=1
// signature: undefined completion_done(void)
// callers: [rpmh_rsc_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 0010a138 size=1
// signature: undefined strlcat(void)
// callers: [rpmh_rsc_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_trylock @ 0010a140 size=1
// signature: undefined _raw_spin_trylock(void)
// callers: [rpmh_rsc_cpu_pm_callback, rpmh_rsc_mode_solver_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 0010a148 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [rpmh_mode_solver_set, tcs_tx_done, rpmh_write_async, rpmh_rsc_cpu_pm_callback, rpmh_write, rpmh_rsc_drv_enable, rpmh_write_batch, rpmh_rsc_mode_solver_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010a150 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010a158 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 0010a160 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [rpmh_mode_solver_set, tcs_tx_done, rpmh_write_async, rpmh_write, rpmh_rsc_drv_enable, rpmh_write_batch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010a168 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [rpmh_rsc_get_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a170 size=1
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
// trace_raw_output_prep @ 0010a178 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_rpmh_send_msg, trace_raw_output_rpmh_solver_set, trace_raw_output_rpmh_switch_channel, trace_raw_output_rpmh_drv_enable, trace_raw_output_rpmh_tx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010a180 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_rpmh_send_msg, trace_raw_output_rpmh_solver_set, trace_raw_output_rpmh_switch_channel, trace_raw_output_rpmh_drv_enable, trace_raw_output_rpmh_tx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010a188 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_rpmh_send_msg, trace_raw_output_rpmh_solver_set, trace_raw_output_rpmh_switch_channel, trace_raw_output_rpmh_drv_enable, trace_raw_output_rpmh_tx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_ready @ 0010a190 size=1
// signature: undefined cmd_db_ready(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_ready(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cmd_db_is_standalone @ 0010a198 size=1
// signature: undefined cmd_db_is_standalone(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cmd_db_is_standalone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010a1a0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010a1a8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0010a1b0 size=1
// signature: undefined of_get_property(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010a1b8 size=1
// signature: undefined scnprintf(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 0010a1c0 size=1
// signature: undefined of_get_next_child(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_node_name_eq @ 0010a1c8 size=1
// signature: undefined of_node_name_eq(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_node_name_eq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 0010a1d0 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a1e0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 0010a1e8 size=1
// signature: undefined dev_set_name(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 0010a1f0 size=1
// signature: undefined device_register(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0010a1f8 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0010a200 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_platform_populate @ 0010a208 size=1
// signature: undefined devm_of_platform_populate(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010a210 size=1
// signature: undefined of_find_property(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0010a218 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_attach @ 0010a220 size=1
// signature: undefined dev_pm_domain_attach(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_add_notifier @ 0010a228 size=1
// signature: undefined dev_pm_genpd_add_notifier(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_add_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_register_notifier @ 0010a230 size=1
// signature: undefined cpu_pm_register_notifier(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010a238 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0010a240 size=1
// signature: undefined platform_get_irq(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010a248 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010a250 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a258 size=1
// signature: undefined _dev_err(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010a260 size=1
// signature: undefined _dev_info(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010a268 size=1
// signature: undefined __list_add_valid(void)
// callers: [rpmh_rsc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010a288 size=1
// signature: undefined complete(void)
// callers: [rpmh_tx_done, __rpmh_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010a290 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [rpmh_write_async, rpmh_write, rpmh_write_batch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010a298 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [rpmh_invalidate, rpmh_write_sleep_and_wake, __rpmh_write, rpmh_write_batch, rpmh_flush, rpmh_write_sleep_and_wake_no_child]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010a2a0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [rpmh_invalidate, rpmh_write_sleep_and_wake, __rpmh_write, rpmh_write_batch, rpmh_flush, rpmh_write_sleep_and_wake_no_child]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010a2a8 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [rpmh_write, rpmh_write_batch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



