// Decompiled by Ghidra 12.2
// Program: qcom-hv-haptics.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_qcom_haptics_fifo_hw_status @ 001020c4 size=140
// signature: undefined __traceiter_qcom_haptics_fifo_hw_status(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_qcom_haptics_fifo_hw_status
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5)

{
  code *pcVar1;
  long *plVar2;
  
  if (DAT_00111710 != (long *)0x0) {
    plVar2 = DAT_00111710;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x18ce67b3) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102128);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1,param_5 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_qcom_haptics_fifo_prgm_status @ 00102154 size=124
// signature: undefined __traceiter_qcom_haptics_fifo_prgm_status(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_qcom_haptics_fifo_prgm_status
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00111758;
  plVar2 = _DAT_00111758;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7b62ce0c) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1021ac);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_qcom_haptics_play @ 001021d4 size=100
// signature: undefined __traceiter_qcom_haptics_play(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_qcom_haptics_play(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_001117a0 != (long *)0x0) {
    plVar2 = _DAT_001117a0;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x722f0ed1) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102218);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2 & 1);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_qcom_haptics_status @ 0010223c size=124
// signature: undefined __traceiter_qcom_haptics_status(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_qcom_haptics_status
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001117e8;
  plVar2 = _DAT_001117e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce28142) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102294);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_qcom_haptics_fifo_hw_status @ 001022bc size=208
// signature: undefined trace_event_raw_event_qcom_haptics_fifo_hw_status(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qcom_haptics_fifo_hw_status
               (long param_1,undefined4 param_2,undefined4 param_3,byte param_4,byte param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(byte *)(lVar1 + 0x10) = param_4 & 1;
    *(byte *)(lVar1 + 0x11) = param_5 & 1;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qcom_haptics_fifo_hw_status @ 00102390 size=280
// signature: undefined perf_trace_qcom_haptics_fifo_hw_status(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qcom_haptics_fifo_hw_status
               (long param_1,undefined4 param_2,undefined4 param_3,byte param_4,byte param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(byte *)(lVar3 + 0x10) = param_4 & 1;
    *(byte *)(lVar3 + 0x11) = param_5 & 1;
    perf_trace_run_bpf_submit(lVar3,0x14,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qcom_haptics_fifo_prgm_status @ 001024ac size=192
// signature: undefined trace_event_raw_event_qcom_haptics_fifo_prgm_status(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qcom_haptics_fifo_prgm_status
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qcom_haptics_fifo_prgm_status @ 00102570 size=256
// signature: undefined perf_trace_qcom_haptics_fifo_prgm_status(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qcom_haptics_fifo_prgm_status
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qcom_haptics_play @ 00102674 size=172
// signature: undefined trace_event_raw_event_qcom_haptics_play(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qcom_haptics_play(long param_1,byte param_2)

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
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0xc), lVar1 != 0)) {
    *(byte *)(lVar1 + 8) = param_2 & 1;
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
// perf_trace_qcom_haptics_play @ 00102724 size=240
// signature: undefined perf_trace_qcom_haptics_play(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qcom_haptics_play(long param_1,byte param_2)

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
     (lVar3 = perf_trace_buf_alloc(0xc,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(byte *)(lVar3 + 8) = param_2 & 1;
    perf_trace_run_bpf_submit(lVar3,0xc,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qcom_haptics_status @ 00102818 size=256
// signature: undefined trace_event_raw_event_qcom_haptics_status(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qcom_haptics_status
               (long param_1,char *param_2,undefined1 param_3,undefined1 param_4)

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
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x10);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0xe;
      strcpy((char *)(lVar3 + 0xe),__s);
      *(undefined1 *)(lVar3 + 0xc) = param_3;
      *(undefined1 *)(lVar3 + 0xd) = param_4;
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
// perf_trace_qcom_haptics_status @ 0010291c size=344
// signature: undefined perf_trace_qcom_haptics_status(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qcom_haptics_status
               (long param_1,char *param_2,undefined1 param_3,undefined1 param_4)

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
    iVar3 = ((int)sVar4 + 0x1cU & 0xfffffff8) - 4;
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
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x1000e;
      strcpy((char *)(lVar5 + 0xe),__s);
      *(undefined1 *)(lVar5 + 0xc) = param_3;
      *(undefined1 *)(lVar5 + 0xd) = param_4;
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
// __bpf_trace_qcom_haptics_fifo_hw_status @ 00102a78 size=44
// signature: undefined __bpf_trace_qcom_haptics_fifo_hw_status(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qcom_haptics_fifo_hw_status
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,ulong param_4,ulong param_5
               )

{
  bpf_trace_run4(param_1,param_2,param_3,param_4 & 1,param_5 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qcom_haptics_fifo_prgm_status @ 00102aa8 size=40
// signature: undefined __bpf_trace_qcom_haptics_fifo_prgm_status(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qcom_haptics_fifo_prgm_status
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qcom_haptics_play @ 00102ad4 size=32
// signature: undefined __bpf_trace_qcom_haptics_play(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qcom_haptics_play(undefined8 param_1,ulong param_2)

{
  bpf_trace_run1(param_1,param_2 & 1);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qcom_haptics_status @ 00102af8 size=36
// signature: undefined __bpf_trace_qcom_haptics_status(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qcom_haptics_status
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// haptics_remove_debugfs @ 00102b20 size=32
// signature: undefined haptics_remove_debugfs(void)
// callers: []
//------------------------------------------------------------

void haptics_remove_debugfs(long param_1)

{
  debugfs_remove(*(undefined8 *)(param_1 + 0x128));
  return;
}



//------------------------------------------------------------
// haptics_create_debugfs @ 00102b44 size=276
// signature: undefined haptics_create_debugfs(void)
// callers: [haptics_probe]
//------------------------------------------------------------

ulong haptics_create_debugfs(undefined8 *param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  uVar1 = debugfs_create_dir("haptics",0);
  if (uVar1 < 0xfffffffffffff001) {
    uVar2 = haptics_add_debugfs(uVar1,param_1[0xd],*(undefined4 *)(param_1 + 0x68),"effect");
    if ((-1 < (int)uVar2) &&
       (uVar2 = haptics_add_debugfs(uVar1,param_1[0xe],*(undefined4 *)((long)param_1 + 0x344),
                                    "primitive"), -1 < (int)uVar2)) {
      uVar2 = debugfs_create_file_unsafe
                        ("preload_effect_idx",0x1a4,uVar1,param_1,&preload_effect_idx_dbgfs_ops);
      if (uVar2 < 0xfffffffffffff001) {
        debugfs_create_u32("fifo_empty_thresh",0x180,uVar1,param_1 + 0xb);
        param_1[0x25] = uVar1;
        uVar1 = 0;
        goto LAB_00102c08;
      }
      _dev_err(*param_1,"create preload_effect_idx debugfs failed, rc=%d\n",uVar2 & 0xffffffff);
    }
    uVar1 = uVar2 & 0xffffffff;
    debugfs_remove(param_1[0x25]);
  }
  else {
    _dev_err(*param_1,"create haptics debugfs directory failed, rc=%d\n",uVar1 & 0xffffffff);
  }
LAB_00102c08:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// haptics_add_debugfs @ 00102c58 size=844
// signature: undefined haptics_add_debugfs(void)
// callers: [haptics_create_debugfs]
//------------------------------------------------------------

ulong haptics_add_debugfs(undefined8 param_1,long *param_2,uint param_3,undefined8 param_4)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  char *pcVar5;
  undefined **ppuVar6;
  ulong uVar7;
  undefined7 uStack_78;
  undefined1 local_71;
  undefined7 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uStack_70 = 0;
  uStack_78 = 0;
  local_71 = 0;
  if ((int)param_3 < 1) {
    uVar3 = 0;
  }
  else {
    uVar7 = (ulong)param_3;
    do {
      scnprintf(&uStack_78,0xf,&DAT_00112669,param_4,(int)param_2[3]);
      uVar2 = debugfs_create_dir(&uStack_78,param_1);
      if (0xfffffffffffff000 < uVar2) {
        _printk(&DAT_00113073,&uStack_78,uVar2 & 0xffffffff);
        uVar3 = uVar2 & 0xffffffff;
        break;
      }
      uVar3 = debugfs_create_file_unsafe("vmax_mv",0x1a4,uVar2,param_2,&vmax_debugfs_ops);
      if ((uVar3 < 0xfffffffffffff001) &&
         (uVar3 = debugfs_create_file_unsafe
                            ("lra_auto_res_en",0x1a4,uVar2,param_2,&auto_res_en_debugfs_ops),
         uVar3 < 0xfffffffffffff001)) {
        if (*param_2 != 0) {
          uVar4 = debugfs_create_dir("pattern",uVar2);
          if (uVar4 < 0xfffffffffffff001) {
            uVar3 = debugfs_create_file("samples",0x1a4,uVar4,param_2,pattern_s_dbgfs_ops);
            if (uVar3 < 0xfffffffffffff001) {
              pcVar5 = "play_rate_us";
              ppuVar6 = &pattern_play_rate_dbgfs_ops;
LAB_00102e24:
              uVar3 = debugfs_create_file_unsafe(pcVar5,0x1a4,uVar4,param_2,ppuVar6);
              if (uVar3 < 0xfffffffffffff001) goto LAB_00102e34;
            }
          }
          else {
LAB_00102dd4:
            uVar3 = uVar4;
          }
          goto LAB_00102f10;
        }
        if (param_2[1] != 0) {
          uVar4 = debugfs_create_dir(&DAT_00111c91,uVar2);
          if (0xfffffffffffff000 < uVar4) goto LAB_00102dd4;
          uVar3 = debugfs_create_file("samples",0x1a4,uVar4,param_2,&fifo_s_dbgfs_ops);
          if (uVar3 < 0xfffffffffffff001) {
            pcVar5 = "period";
            ppuVar6 = &fifo_period_dbgfs_ops;
            goto LAB_00102e24;
          }
          goto LAB_00102f10;
        }
LAB_00102e34:
        if (param_2[2] != 0) {
          uVar2 = debugfs_create_dir("brake",uVar2);
          if (uVar2 < 0xfffffffffffff001) {
            uVar3 = debugfs_create_file("samples",0x1a4,uVar2,param_2,brake_s_dbgfs_ops);
            if ((((uVar3 < 0xfffffffffffff001) &&
                 (uVar3 = debugfs_create_file(&DAT_00111fe0,0x1a4,uVar2,param_2,brake_mode_dbgfs_ops
                                             ), uVar3 < 0xfffffffffffff001)) &&
                (uVar3 = debugfs_create_file_unsafe
                                   ("enable",0x1a4,uVar2,param_2,&brake_en_dbgfs_ops),
                uVar3 < 0xfffffffffffff001)) &&
               (uVar3 = debugfs_create_file_unsafe
                                  ("sine_gain",0x1a4,uVar2,param_2,&brake_sine_gain_dbgfs_ops),
               uVar3 < 0xfffffffffffff001)) goto LAB_00102f24;
          }
          else {
            uVar3 = uVar2;
          }
          goto LAB_00102f10;
        }
LAB_00102f24:
        uVar3 = 0;
      }
      else {
LAB_00102f10:
        if ((int)uVar3 < 0) {
          _printk(&DAT_00111b38,&uStack_78,uVar3 & 0xffffffff);
          break;
        }
      }
      param_2 = param_2 + 6;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// trace_raw_output_qcom_haptics_fifo_hw_status @ 00102fa8 size=108
// signature: undefined trace_raw_output_qcom_haptics_fifo_hw_status(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qcom_haptics_fifo_hw_status
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "FIFO HW status: filled = %u, available = %u, full = %d, empty = %d\n\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined1 *)(lVar2 + 0x10),*(undefined1 *)(lVar2 + 0x11));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qcom_haptics_fifo_prgm_status @ 00103018 size=104
// signature: undefined trace_raw_output_qcom_haptics_fifo_prgm_status(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qcom_haptics_fifo_prgm_status
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "FIFO program status: writing %u bytes, written %u bytes, total %u bytes\n\n"
                       ,*(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qcom_haptics_play @ 00103084 size=100
// signature: undefined trace_raw_output_qcom_haptics_play(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qcom_haptics_play(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"play enable: %d\n\n",*(undefined1 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qcom_haptics_status @ 001030ec size=112
// signature: undefined trace_raw_output_qcom_haptics_status(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qcom_haptics_status(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"haptics %s status: MSB %#x, LSB %#x\n\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined1 *)(lVar2 + 0xc),
                       *(undefined1 *)(lVar2 + 0xd));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// vmax_debugfs_ops_open @ 00103160 size=52
// signature: undefined vmax_debugfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void vmax_debugfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,vmax_dbgfs_read,vmax_dbgfs_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// vmax_dbgfs_read @ 00103198 size=16
// signature: undefined vmax_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 vmax_dbgfs_read(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x1c);
  return 0;
}



//------------------------------------------------------------
// vmax_dbgfs_write @ 001031ac size=28
// signature: undefined vmax_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 vmax_dbgfs_write(long param_1,ulong param_2)

{
  if (10999 < param_2) {
    param_2 = 11000;
  }
  *(int *)(param_1 + 0x1c) = (int)param_2;
  return 0;
}



//------------------------------------------------------------
// auto_res_en_debugfs_ops_open @ 001031cc size=52
// signature: undefined auto_res_en_debugfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void auto_res_en_debugfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,auto_res_en_dbgfs_read,auto_res_en_dbgfs_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// auto_res_en_dbgfs_read @ 00103204 size=24
// signature: undefined auto_res_en_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 auto_res_en_dbgfs_read(long param_1,ulong *param_2)

{
  *param_2 = (ulong)(*(char *)(param_1 + 0x2c) == '\0');
  return 0;
}



//------------------------------------------------------------
// auto_res_en_dbgfs_write @ 00103220 size=24
// signature: undefined auto_res_en_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 auto_res_en_dbgfs_write(long param_1,long param_2)

{
  *(bool *)(param_1 + 0x2c) = param_2 == 0;
  return 0;
}



//------------------------------------------------------------
// pattern_s_dbgfs_read @ 0010323c size=344
// signature: undefined pattern_s_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long pattern_s_dbgfs_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  
  plVar8 = *(long **)(param_1 + 0xd8);
  if (*plVar8 == 0) {
    lVar5 = 0;
  }
  else {
    lVar5 = kmalloc_trace(_kstrtouint,0xdc0,0x180);
    if (lVar5 == 0) {
      lVar5 = -0xc;
    }
    else {
      lVar6 = 0;
      uVar7 = 0;
      do {
        iVar4 = scnprintf(lVar5 + uVar7,0x180 - (int)uVar7,"0x%03x  ",
                          *(undefined2 *)(*plVar8 + lVar6));
        uVar2 = *(uint *)(*plVar8 + lVar6 + 4);
        if (0xe < uVar2) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103394);
          (*pcVar3)();
        }
        uVar1 = iVar4 + (int)uVar7;
        iVar4 = scnprintf(lVar5 + (ulong)uVar1,0x180 - uVar1,"%s(0x%02x)  ",(&period_str)[uVar2]);
        uVar1 = iVar4 + uVar1;
        iVar4 = scnprintf(lVar5 + (ulong)uVar1,0x180 - uVar1,"F_LRA_X2(%1d)\n",
                          *(undefined1 *)(*plVar8 + lVar6 + 8));
        lVar6 = lVar6 + 0xc;
        uVar7 = (ulong)(iVar4 + uVar1);
      } while (lVar6 != 0x60);
      iVar4 = simple_read_from_buffer(param_2,param_3,param_4,lVar5,uVar7);
      kfree(lVar5);
      lVar5 = (long)iVar4;
    }
  }
  return lVar5;
}



//------------------------------------------------------------
// pattern_s_dbgfs_write @ 00103398 size=1688
// signature: undefined pattern_s_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00103a10) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long pattern_s_dbgfs_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  long lVar1;
  ulong uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  char *pcVar14;
  ulong uVar15;
  char *pcVar16;
  undefined *puVar17;
  undefined2 uVar18;
  uint uVar19;
  undefined2 uVar20;
  uint uVar21;
  uint uVar22;
  undefined8 *puVar23;
  uint uVar24;
  ulong uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  long lVar31;
  uint uVar32;
  uint uVar33;
  long *plVar34;
  uint uVar35;
  uint uVar36;
  undefined2 *puVar37;
  uint local_f4;
  char *local_f0;
  undefined2 local_e8;
  undefined1 local_e6;
  undefined2 local_e4;
  undefined1 local_e2;
  undefined2 local_e0;
  undefined1 local_de;
  undefined2 local_dc;
  undefined1 local_da;
  undefined2 local_d8;
  undefined1 local_d6;
  undefined2 local_d4;
  undefined1 local_d2;
  undefined2 local_d0;
  undefined1 local_ce;
  undefined2 local_cc;
  undefined1 local_ca;
  uint local_c8 [24];
  long local_68;
  
  lVar31 = sp_el0;
  local_68 = *(long *)(lVar31 + 0x638);
  plVar34 = *(long **)(param_1 + 0xd8);
  local_cc = 0;
  local_ca = 0;
  local_d0 = 0;
  local_ce = 0;
  local_d4 = 0;
  local_d2 = 0;
  local_d8 = 0;
  local_d6 = 0;
  local_dc = 0;
  local_da = 0;
  local_e0 = 0;
  local_de = 0;
  local_e4 = 0;
  local_e2 = 0;
  local_e6 = 0;
  local_e8 = 0;
  local_f0 = (char *)0x0;
  local_f4 = 0;
  local_c8[0x16] = 0;
  local_c8[0x17] = 0;
  local_c8[0x12] = 0;
  local_c8[0x13] = 0;
  local_c8[0x14] = 0;
  local_c8[0x15] = 0;
  local_c8[0xe] = 0;
  local_c8[0xf] = 0;
  local_c8[0x10] = 0;
  local_c8[0x11] = 0;
  local_c8[10] = 0;
  local_c8[0xb] = 0;
  local_c8[0xc] = 0;
  local_c8[0xd] = 0;
  local_c8[6] = 0;
  local_c8[7] = 0;
  local_c8[8] = 0;
  local_c8[9] = 0;
  local_c8[2] = 0;
  local_c8[3] = 0;
  local_c8[4] = 0;
  local_c8[5] = 0;
  local_c8[0] = 0;
  local_c8[1] = 0;
  if (0x180 < param_3) {
    lVar31 = -0x16;
    goto LAB_00103808;
  }
  pcVar14 = (char *)kmalloc_trace(_kstrtouint,0xdc0,0x181);
  if (pcVar14 == (char *)0x0) {
    lVar31 = -0xc;
    goto LAB_00103808;
  }
  local_f0 = pcVar14;
  __check_object_size(pcVar14,param_3,0);
  puVar23 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar23 + 0x46) >> 5 & 1) != 0) ||
     (uVar25 = param_2, ((uint)*puVar23 >> 0x1a & 1) != 0)) {
    uVar25 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar15 = param_3;
  if (uVar25 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar25 = daif;
      if ((uVar25 & 0x80) == 0) {
        uVar15 = daif;
        daif = uVar15 | 0xc0;
      }
      puVar23 = (undefined8 *)puVar23[1];
      uVar15 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar23 & 0xffff000000000000 | uVar15 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar23;
      InstructionSynchronizationBarrier();
      daif = uVar25;
    }
    uVar15 = __arch_copy_from_user(puVar23,pcVar14,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar25 = daif;
      if ((uVar25 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar25;
    }
  }
  if ((uVar15 == 0) || (memset(pcVar14 + (param_3 - uVar15),0,uVar15), (int)uVar15 < 1)) {
    local_f0[param_3] = '\0';
    *param_4 = *param_4 + param_3;
    pcVar16 = strsep(&local_f0," ");
    if (pcVar16 == (char *)0x0) {
      bVar3 = false;
      bVar4 = false;
      bVar5 = false;
      uVar22 = 0;
      uVar24 = 0;
      uVar26 = 0;
      uVar27 = 0;
      uVar28 = 0;
      uVar29 = 0;
LAB_001036a4:
      bVar6 = false;
      uVar30 = 0;
      uVar12 = 0;
LAB_001036a8:
      uVar18 = 0;
      bVar7 = false;
      uVar19 = 0;
LAB_001036b4:
      bVar8 = false;
      uVar36 = 0;
      uVar21 = 0;
LAB_001036c0:
      bVar9 = false;
      uVar32 = 0;
      uVar33 = 0;
LAB_001036cc:
      uVar20 = (undefined2)uVar36;
      bVar10 = false;
      uVar35 = 0;
      uVar36 = 0;
LAB_001036d8:
      puVar37 = (undefined2 *)*plVar34;
      *puVar37 = (short)uVar22;
      *(uint *)(puVar37 + 2) = uVar24;
      puVar37[1] = 0;
      *(undefined2 *)((long)puVar37 + 9) = local_cc;
      *(undefined1 *)((long)puVar37 + 0xb) = local_ca;
      *(bool *)(puVar37 + 4) = bVar3;
      *(undefined2 *)((long)puVar37 + 0x15) = local_d0;
      *(undefined1 *)((long)puVar37 + 0x17) = local_ce;
      puVar37[6] = (short)uVar26;
      *(undefined2 *)((long)puVar37 + 0x21) = local_d4;
      *(undefined1 *)((long)puVar37 + 0x23) = local_d2;
      puVar37[7] = 0;
      *(undefined2 *)((long)puVar37 + 0x2d) = local_d8;
      *(undefined1 *)((long)puVar37 + 0x2f) = local_d6;
      *(uint *)(puVar37 + 8) = uVar27;
      *(undefined1 *)((long)puVar37 + 0x3b) = local_da;
      *(undefined2 *)((long)puVar37 + 0x39) = local_dc;
      *(bool *)(puVar37 + 10) = bVar4;
      *(undefined1 *)((long)puVar37 + 0x47) = local_de;
      *(undefined2 *)((long)puVar37 + 0x45) = local_e0;
      puVar37[0xc] = (short)uVar28;
      *(undefined1 *)((long)puVar37 + 0x53) = local_e2;
      *(undefined2 *)((long)puVar37 + 0x51) = local_e4;
      puVar37[0xd] = 0;
      *(uint *)(puVar37 + 0xe) = uVar29;
      *(bool *)(puVar37 + 0x10) = bVar5;
      puVar37[0x12] = (short)uVar30;
      puVar37[0x13] = 0;
      *(uint *)(puVar37 + 0x14) = uVar12;
      *(bool *)(puVar37 + 0x16) = bVar6;
      puVar37[0x18] = uVar18;
      puVar37[0x19] = 0;
      *(uint *)(puVar37 + 0x1a) = uVar19;
      *(bool *)(puVar37 + 0x1c) = bVar7;
      puVar37[0x1e] = uVar20;
      puVar37[0x1f] = 0;
      *(uint *)(puVar37 + 0x20) = uVar21;
      *(bool *)(puVar37 + 0x22) = bVar8;
      puVar37[0x24] = (short)uVar32;
      puVar37[0x25] = 0;
      *(uint *)(puVar37 + 0x26) = uVar33;
      *(bool *)(puVar37 + 0x28) = bVar9;
      puVar37[0x2a] = (short)uVar35;
      puVar37[0x2b] = 0;
      *(uint *)(puVar37 + 0x2c) = uVar36;
      *(bool *)(puVar37 + 0x2e) = bVar10;
      *(undefined1 *)((long)puVar37 + 0x5f) = local_e6;
      *(undefined2 *)((long)puVar37 + 0x5d) = local_e8;
      lVar31 = *plVar34;
      uVar13 = get_pattern_play_length_us(lVar31);
      *(undefined4 *)(lVar31 + 100) = uVar13;
      if (*(int *)(*plVar34 + 100) != -0x16) {
        lVar31 = (long)(int)param_3;
        goto LAB_00103800;
      }
      puVar17 = &DAT_00113300;
    }
    else {
      lVar31 = 0;
      do {
        iVar11 = kstrtouint(pcVar16,0,&local_f4);
        if (iVar11 < 0) {
          lVar31 = -0x16;
          goto LAB_00103800;
        }
        if (lVar31 == 0x18) {
          puVar17 = &DAT_00112249;
          goto LAB_001039d8;
        }
        lVar1 = lVar31 + 1;
        local_c8[lVar31] = local_f4;
        pcVar16 = strsep(&local_f0," ");
        lVar31 = lVar1;
      } while (pcVar16 != (char *)0x0);
      uVar35 = (uint)lVar1;
      if ((uVar35 + ((uVar35 & 0xff) / 3) * -3 & 0xff) != 0) {
        _printk(&DAT_001127ec);
        if (2 < uVar35) goto LAB_00103650;
LAB_001035e4:
        bVar3 = false;
        uVar22 = 0;
        uVar24 = 0;
LAB_00103684:
        bVar4 = false;
        uVar26 = 0;
        uVar27 = 0;
LAB_00103690:
        bVar5 = false;
        uVar28 = 0;
        uVar29 = 0;
        goto LAB_001036a4;
      }
      if (uVar35 < 3) goto LAB_001035e4;
LAB_00103650:
      if (((local_c8[0] < 0x200) && (local_c8[1] < 7)) && (local_c8[2] < 2)) {
        bVar3 = local_c8[2] != 0;
        uVar22 = local_c8[0];
        uVar24 = local_c8[1];
        if (uVar35 < 6) goto LAB_00103684;
        if (((0x1ff < local_c8[3]) || (6 < local_c8[4])) || (1 < local_c8[5])) goto LAB_001039c4;
        bVar4 = local_c8[5] != 0;
        uVar26 = local_c8[3];
        uVar27 = local_c8[4];
        if (uVar35 - 6 < 3) goto LAB_00103690;
        if (((0x1ff < local_c8[6]) || (6 < local_c8[7])) || (1 < local_c8[8])) goto LAB_001039c4;
        bVar5 = local_c8[8] != 0;
        uVar28 = local_c8[6];
        uVar29 = local_c8[7];
        if (uVar35 - 9 < 3) goto LAB_001036a4;
        if (((0x1ff < local_c8[9]) || (6 < local_c8[10])) || (1 < local_c8[0xb])) goto LAB_001039c4;
        bVar6 = local_c8[0xb] != 0;
        uVar30 = local_c8[9];
        uVar12 = local_c8[10];
        if (uVar35 - 0xc < 3) goto LAB_001036a8;
        uVar18 = (undefined2)local_c8[0xc];
        if (((0x1ff < local_c8[0xc]) || (6 < local_c8[0xd])) || (1 < local_c8[0xe]))
        goto LAB_001039c4;
        bVar7 = local_c8[0xe] != 0;
        uVar19 = local_c8[0xd];
        if (uVar35 - 0xf < 3) goto LAB_001036b4;
        uVar20 = (undefined2)local_c8[0xf];
        if (((0x1ff < local_c8[0xf]) || (6 < local_c8[0x10])) || (1 < local_c8[0x11]))
        goto LAB_001039c4;
        bVar8 = local_c8[0x11] != 0;
        uVar36 = local_c8[0xf];
        uVar21 = local_c8[0x10];
        if (uVar35 - 0x12 < 3) goto LAB_001036c0;
        if (((0x1ff < local_c8[0x12]) || (6 < local_c8[0x13])) || (1 < local_c8[0x14]))
        goto LAB_001039c4;
        bVar9 = local_c8[0x14] != 0;
        uVar32 = local_c8[0x12];
        uVar33 = local_c8[0x13];
        if (uVar35 - 0x15 < 3) goto LAB_001036cc;
        if (((0x1ff < local_c8[0x15]) || (6 < local_c8[0x16])) || (1 < local_c8[0x17]))
        goto LAB_001039c4;
        bVar10 = local_c8[0x17] != 0;
        uVar35 = local_c8[0x15];
        uVar36 = local_c8[0x16];
        goto LAB_001036d8;
      }
LAB_001039c4:
      puVar17 = &DAT_001139bb;
    }
LAB_001039d8:
    _printk(puVar17);
    lVar31 = -0x16;
  }
  else {
    lVar31 = -0xe;
  }
LAB_00103800:
  kfree(pcVar14);
LAB_00103808:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar31;
}



//------------------------------------------------------------
// get_pattern_play_length_us @ 00103a48 size=1160
// signature: undefined get_pattern_play_length_us(void)
// callers: [haptics_parse_per_effect_dt, pattern_s_dbgfs_write, pattern_play_rate_us_dbgfs_write]
//------------------------------------------------------------

uint get_pattern_play_length_us(short *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  uint uVar15;
  bool bVar16;
  
  if (param_1 != (short *)0x0) {
    if (param_1[0x2a] == 0) {
      if (param_1[0x24] == 0) {
        if (param_1[0x1e] == 0) {
          if (param_1[0x18] == 0) {
            if (param_1[0x12] == 0) {
              if (param_1[0xc] == 0) {
                if (param_1[6] == 0) {
                  if (*param_1 == 0) {
                    return 0;
                  }
                  bVar9 = false;
                  bVar8 = false;
                  bVar7 = false;
                  bVar16 = false;
                  bVar14 = false;
                  bVar13 = false;
                  bVar10 = true;
                }
                else {
                  bVar10 = false;
                  bVar8 = false;
                  bVar7 = false;
                  bVar16 = false;
                  bVar14 = false;
                  bVar13 = false;
                  bVar9 = true;
                }
              }
              else {
                bVar10 = false;
                bVar9 = false;
                bVar7 = false;
                bVar16 = false;
                bVar14 = false;
                bVar13 = false;
                bVar8 = true;
              }
            }
            else {
              bVar10 = false;
              bVar9 = false;
              bVar8 = false;
              bVar16 = false;
              bVar14 = false;
              bVar13 = false;
              bVar7 = true;
            }
          }
          else {
            bVar10 = false;
            bVar9 = false;
            bVar8 = false;
            bVar7 = false;
            bVar14 = false;
            bVar13 = false;
            bVar16 = true;
          }
        }
        else {
          bVar10 = false;
          bVar9 = false;
          bVar8 = false;
          bVar7 = false;
          bVar16 = false;
          bVar13 = false;
          bVar14 = true;
        }
      }
      else {
        bVar10 = false;
        bVar9 = false;
        bVar8 = false;
        bVar7 = false;
        bVar16 = false;
        bVar14 = false;
        bVar13 = true;
      }
    }
    else {
      bVar10 = false;
      bVar9 = false;
      bVar8 = false;
      bVar7 = false;
      bVar16 = false;
      bVar14 = false;
      bVar13 = false;
    }
    if (*(uint *)(param_1 + 2) < 7) {
      uVar15 = *(uint *)(param_1 + 0x30);
      uVar1 = uVar15 << 3;
      uVar2 = uVar15 << 2;
      uVar3 = uVar15 << 1;
      uVar4 = uVar15 >> 3;
      uVar5 = uVar15 >> 2;
      uVar6 = uVar15 >> 1;
      uVar12 = uVar15;
      switch(*(uint *)(param_1 + 2)) {
      case 1:
        uVar12 = uVar6;
        break;
      case 2:
        uVar12 = uVar5;
        break;
      case 3:
        uVar12 = uVar4;
        break;
      case 4:
        uVar12 = uVar3;
        break;
      case 5:
        uVar12 = uVar2;
        break;
      case 6:
        uVar12 = uVar1;
      }
      uVar12 = uVar12 >> (ulong)(*(byte *)(param_1 + 4) & 0x1f);
      if (bVar10) {
        return uVar12;
      }
      uVar11 = uVar15;
      switch(*(undefined4 *)(param_1 + 8)) {
      case 0:
        break;
      case 1:
        uVar11 = uVar6;
        break;
      case 2:
        uVar11 = uVar5;
        break;
      case 3:
        uVar11 = uVar4;
        break;
      case 4:
        uVar11 = uVar3;
        break;
      case 5:
        uVar11 = uVar2;
        break;
      case 6:
        uVar11 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      uVar12 = (uVar11 >> (ulong)(*(byte *)(param_1 + 10) & 0x1f)) + uVar12;
      if (bVar9) {
        return uVar12;
      }
      uVar11 = uVar15;
      switch(*(undefined4 *)(param_1 + 0xe)) {
      case 0:
        break;
      case 1:
        uVar11 = uVar6;
        break;
      case 2:
        uVar11 = uVar5;
        break;
      case 3:
        uVar11 = uVar4;
        break;
      case 4:
        uVar11 = uVar3;
        break;
      case 5:
        uVar11 = uVar2;
        break;
      case 6:
        uVar11 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      uVar12 = (uVar11 >> (ulong)(*(byte *)(param_1 + 0x10) & 0x1f)) + uVar12;
      if (bVar8) {
        return uVar12;
      }
      uVar11 = uVar15;
      switch(*(undefined4 *)(param_1 + 0x14)) {
      case 0:
        break;
      case 1:
        uVar11 = uVar6;
        break;
      case 2:
        uVar11 = uVar5;
        break;
      case 3:
        uVar11 = uVar4;
        break;
      case 4:
        uVar11 = uVar3;
        break;
      case 5:
        uVar11 = uVar2;
        break;
      case 6:
        uVar11 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      uVar12 = (uVar11 >> (ulong)(*(byte *)(param_1 + 0x16) & 0x1f)) + uVar12;
      if (bVar7) {
        return uVar12;
      }
      uVar11 = uVar15;
      switch(*(undefined4 *)(param_1 + 0x1a)) {
      case 0:
        break;
      case 1:
        uVar11 = uVar6;
        break;
      case 2:
        uVar11 = uVar5;
        break;
      case 3:
        uVar11 = uVar4;
        break;
      case 4:
        uVar11 = uVar3;
        break;
      case 5:
        uVar11 = uVar2;
        break;
      case 6:
        uVar11 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      uVar12 = (uVar11 >> (ulong)(*(byte *)(param_1 + 0x1c) & 0x1f)) + uVar12;
      if (bVar16) {
        return uVar12;
      }
      uVar11 = uVar15;
      switch(*(undefined4 *)(param_1 + 0x20)) {
      case 0:
        break;
      case 1:
        uVar11 = uVar6;
        break;
      case 2:
        uVar11 = uVar5;
        break;
      case 3:
        uVar11 = uVar4;
        break;
      case 4:
        uVar11 = uVar3;
        break;
      case 5:
        uVar11 = uVar2;
        break;
      case 6:
        uVar11 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      uVar12 = (uVar11 >> (ulong)(*(byte *)(param_1 + 0x22) & 0x1f)) + uVar12;
      if (bVar14) {
        return uVar12;
      }
      uVar11 = uVar15;
      switch(*(undefined4 *)(param_1 + 0x26)) {
      case 0:
        break;
      case 1:
        uVar11 = uVar6;
        break;
      case 2:
        uVar11 = uVar5;
        break;
      case 3:
        uVar11 = uVar4;
        break;
      case 4:
        uVar11 = uVar3;
        break;
      case 5:
        uVar11 = uVar2;
        break;
      case 6:
        uVar11 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      uVar12 = (uVar11 >> (ulong)(*(byte *)(param_1 + 0x28) & 0x1f)) + uVar12;
      if (bVar13) {
        return uVar12;
      }
      switch(*(undefined4 *)(param_1 + 0x2c)) {
      case 0:
        break;
      case 1:
        uVar15 = uVar6;
        break;
      case 2:
        uVar15 = uVar5;
        break;
      case 3:
        uVar15 = uVar4;
        break;
      case 4:
        uVar15 = uVar3;
        break;
      case 5:
        uVar15 = uVar2;
        break;
      case 6:
        uVar15 = uVar1;
        break;
      default:
        goto LAB_00103e90;
      }
      return (uVar15 >> (ulong)(*(byte *)(param_1 + 0x2e) & 0x1f)) + uVar12;
    }
  }
LAB_00103e90:
  return 0xffffffea;
}



//------------------------------------------------------------
// pattern_play_rate_dbgfs_ops_open @ 00103ed4 size=52
// signature: undefined pattern_play_rate_dbgfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void pattern_play_rate_dbgfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,pattern_play_rate_us_dbgfs_read,pattern_play_rate_us_dbgfs_write,
                   "%llu\n");
  return;
}



//------------------------------------------------------------
// pattern_play_rate_us_dbgfs_read @ 00103f0c size=20
// signature: undefined pattern_play_rate_us_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 pattern_play_rate_us_dbgfs_read(long *param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(*param_1 + 0x60);
  return 0;
}



//------------------------------------------------------------
// pattern_play_rate_us_dbgfs_write @ 00103f24 size=112
// signature: undefined pattern_play_rate_us_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 pattern_play_rate_us_dbgfs_write(long *param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (0x4ffa < param_2) {
    param_2 = 0x4ffb;
  }
  *(int *)(*param_1 + 0x60) = (int)param_2;
  lVar3 = *param_1;
  uVar1 = get_pattern_play_length_us(lVar3);
  *(undefined4 *)(lVar3 + 100) = uVar1;
  if (*(int *)(*param_1 + 100) == -0x16) {
    _printk(&DAT_00113300);
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// fifo_s_dbgfs_read @ 00103f98 size=268
// signature: undefined fifo_s_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

long fifo_s_dbgfs_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  ulong uVar5;
  uint uVar6;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0xd8) + 8);
  uVar1 = (int)plVar4[1] << 3 | 1;
  lVar3 = __kmalloc(uVar1,0xdc0);
  if (lVar3 == 0) {
    lVar3 = -0xc;
  }
  else {
    if ((int)plVar4[1] == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = 0;
      uVar6 = 0;
      do {
        iVar2 = scnprintf(lVar3 + uVar5,uVar1 - (int)uVar5,&DAT_00113c87,
                          (long)*(char *)(*plVar4 + (long)(int)uVar6));
        uVar5 = (ulong)(uint)(iVar2 + (int)uVar5);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(plVar4 + 1));
    }
    iVar2 = scnprintf(lVar3 + uVar5,uVar1 - (int)uVar5,&DAT_001120d7,&DAT_001135f6);
    iVar2 = simple_read_from_buffer(param_2,param_3,param_4,lVar3,iVar2 + (int)uVar5);
    kfree(lVar3);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// fifo_s_dbgfs_write @ 001040a8 size=980
// signature: undefined fifo_s_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void fifo_s_dbgfs_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  char *pcVar6;
  ulong uVar7;
  void *__src;
  char *pcVar8;
  uint uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  int iVar12;
  uint uVar13;
  long *plVar14;
  long lVar15;
  int local_64;
  char *local_60;
  long local_58;
  
  lVar15 = sp_el0;
  local_58 = *(long *)(lVar15 + 0x638);
  lVar15 = *(long *)(param_1 + 0xd8);
  local_64 = 0;
  plVar14 = *(long **)(lVar15 + 8);
  pcVar6 = (char *)__kmalloc(param_3 + 1,0xdc0);
  if (pcVar6 == (char *)0x0) {
    lVar15 = -0xc;
    goto LAB_00104400;
  }
  local_60 = pcVar6;
  if (param_3 >> 0x1f != 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10443c);
    (*pcVar4)();
  }
  __check_object_size(pcVar6,param_3,0);
  puVar10 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
     (uVar11 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
    uVar11 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar7 = param_3;
  if (uVar11 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar7 = daif;
        daif = uVar7 | 0xc0;
      }
      puVar10 = (undefined8 *)puVar10[1];
      uVar7 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10;
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
    uVar7 = __arch_copy_from_user(puVar10,pcVar6,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
  }
  if ((uVar7 == 0) || (memset(pcVar6 + (param_3 - uVar7),0,uVar7), (int)uVar7 < 1)) {
    local_60[param_3] = '\0';
    *param_4 = *param_4 + param_3;
    __src = (void *)__kmalloc((int)plVar14[1],0xdc0);
    if (__src == (void *)0x0) {
      iVar5 = -0xc;
    }
    else {
      uVar13 = 0;
      do {
        pcVar8 = strsep(&local_60," ");
        if (pcVar8 == (char *)0x0) {
          uVar9 = *(uint *)(plVar14 + 1);
          break;
        }
        iVar5 = kstrtoint(pcVar8,0,&local_64);
        if (iVar5 < 0) goto LAB_001043e8;
        if (0xff < local_64) {
          local_64 = 0xff;
        }
        *(char *)((long)__src + (long)(int)uVar13) = (char)local_64;
        uVar13 = uVar13 + 1;
        uVar9 = *(uint *)(plVar14 + 1);
      } while (uVar13 < uVar9);
      memcpy((void *)*plVar14,__src,(ulong)uVar9);
      if (plVar14 == (long *)0x0) {
switchD_00104300_caseD_4:
        *(undefined4 *)(plVar14 + 2) = 0xffffffea;
LAB_001043dc:
        _printk(&DAT_001134c9);
LAB_001043e8:
        param_3 = 0xffffffffffffffea;
      }
      else {
        iVar1 = (int)plVar14[1];
        iVar5 = iVar1 + -1;
        if (-1 < iVar5) {
          iVar5 = 0;
        }
        iVar12 = iVar1 + 1;
        do {
          uVar13 = iVar12 - 2;
          if ((int)uVar13 < 1) {
            iVar12 = iVar5 + 1;
            break;
          }
          iVar12 = iVar12 + -1;
        } while (*(char *)(*plVar14 + (ulong)uVar13) == '\0');
        if (0xd < *(uint *)((long)plVar14 + 0xc)) goto switchD_00104300_caseD_4;
        uVar13 = iVar12 * *(int *)(lVar15 + 0x20);
        switch(*(uint *)((long)plVar14 + 0xc)) {
        case 0:
          *(uint *)(plVar14 + 2) = uVar13;
          if (uVar13 != 0xffffffea) break;
          goto LAB_001043dc;
        case 1:
          *(uint *)(plVar14 + 2) = uVar13 >> 1;
          break;
        case 2:
          *(uint *)(plVar14 + 2) = uVar13 >> 2;
          break;
        case 3:
          *(uint *)(plVar14 + 2) = uVar13 >> 3;
          break;
        default:
          goto switchD_00104300_caseD_4;
        case 8:
          *(uint *)(plVar14 + 2) = (uint)(iVar1 * 1000) >> 3;
          break;
        case 9:
          *(uint *)(plVar14 + 2) = (uint)(iVar1 * 1000) >> 4;
          break;
        case 10:
          *(uint *)(plVar14 + 2) = (uint)(iVar1 * 1000) / 0x18;
          break;
        case 0xb:
          *(uint *)(plVar14 + 2) = (uint)(iVar1 * 1000) >> 5;
          break;
        case 0xc:
          *(uint *)(plVar14 + 2) = (uint)(iVar1 * 10000) / 0x1b9;
          break;
        case 0xd:
          *(uint *)(plVar14 + 2) = (uint)(iVar1 * 1000) / 0x30;
        }
      }
      iVar5 = (int)param_3;
      kfree(__src);
    }
  }
  else {
    iVar5 = -0xe;
  }
  kfree(pcVar6);
  lVar15 = (long)iVar5;
LAB_00104400:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar15);
  }
  return;
}



//------------------------------------------------------------
// fifo_period_dbgfs_ops_open @ 0010449c size=52
// signature: undefined fifo_period_dbgfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void fifo_period_dbgfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,fifo_period_dbgfs_read,fifo_period_dbgfs_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// fifo_period_dbgfs_read @ 001044d4 size=20
// signature: undefined fifo_period_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 fifo_period_dbgfs_read(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 8) + 0xc);
  return 0;
}



//------------------------------------------------------------
// fifo_period_dbgfs_write @ 001044ec size=360
// signature: undefined fifo_period_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 fifo_period_dbgfs_write(long param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = (uint)param_2;
  if (0xd < param_2) {
    return 0xffffffea;
  }
  plVar4 = *(long **)(param_1 + 8);
  *(uint *)((long)plVar4 + 0xc) = uVar3;
  if (plVar4 != (long *)0x0) {
    iVar1 = (int)plVar4[1];
    iVar2 = iVar1 + -1;
    if (-1 < iVar2) {
      iVar2 = 0;
    }
    iVar6 = iVar1 + 1;
    do {
      uVar5 = iVar6 - 2;
      if ((int)uVar5 < 1) {
        iVar6 = iVar2 + 1;
        break;
      }
      iVar6 = iVar6 + -1;
    } while (*(char *)(*plVar4 + (ulong)uVar5) == '\0');
    if (uVar3 < 0xe) {
      uVar5 = iVar6 * *(int *)(param_1 + 0x20);
      switch(uVar3) {
      case 0:
        *(uint *)(plVar4 + 2) = uVar5;
        if (uVar5 != 0xffffffea) {
          return 0;
        }
        goto LAB_00104644;
      case 1:
        uVar5 = uVar5 >> 1;
        break;
      case 2:
        uVar5 = uVar5 >> 2;
        break;
      case 3:
        uVar5 = uVar5 >> 3;
        break;
      default:
        goto switchD_00104578_caseD_4;
      case 8:
        uVar5 = (uint)(iVar1 * 1000) >> 3;
        break;
      case 9:
        uVar5 = (uint)(iVar1 * 1000) >> 4;
        break;
      case 10:
        uVar5 = (uint)(iVar1 * 1000) / 0x18;
        break;
      case 0xb:
        uVar5 = (uint)(iVar1 * 1000) >> 5;
        break;
      case 0xc:
        uVar5 = (uint)(iVar1 * 10000) / 0x1b9;
        break;
      case 0xd:
        uVar5 = (uint)(iVar1 * 1000) / 0x30;
      }
      *(uint *)(plVar4 + 2) = uVar5;
      return 0;
    }
  }
switchD_00104578_caseD_4:
  *(undefined4 *)(plVar4 + 2) = 0xffffffea;
LAB_00104644:
  _printk(&DAT_001134c9);
  return 0xffffffea;
}



//------------------------------------------------------------
// brake_s_dbgfs_read @ 00104658 size=380
// signature: undefined brake_s_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long brake_s_dbgfs_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined1 *puVar4;
  
  puVar4 = *(undefined1 **)(*(long *)(param_1 + 0xd8) + 0x10);
  lVar3 = kmalloc_trace(___arch_copy_from_user,0xdc0,0x41);
  if (lVar3 == 0) {
    lVar3 = -0xc;
  }
  else {
    uVar1 = scnprintf(lVar3,0x41,"0x%02x ",*puVar4);
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[1]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[2]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[3]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[4]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[5]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[6]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,"0x%02x ",puVar4[7]);
    uVar1 = iVar2 + uVar1;
    iVar2 = scnprintf(lVar3 + (ulong)uVar1,0x41 - uVar1,&DAT_001120d7,&DAT_001135f6);
    iVar2 = simple_read_from_buffer(param_2,param_3,param_4,lVar3,iVar2 + uVar1);
    kfree(lVar3);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// brake_s_dbgfs_write @ 001047d8 size=1444
// signature: undefined brake_s_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long brake_s_dbgfs_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  char cVar6;
  int iVar7;
  char *pcVar8;
  ulong uVar9;
  char *pcVar10;
  undefined8 *puVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  ulong *puVar15;
  long lVar16;
  ulong uVar17;
  uint uVar18;
  uint uVar19;
  ulong uVar20;
  uint local_74;
  char *local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 0xd8);
  local_74 = 0;
  puVar15 = *(ulong **)(lVar16 + 0x10);
  if (0x40 < param_3) {
    lVar16 = -0x16;
    goto LAB_00104c7c;
  }
  pcVar8 = (char *)kmalloc_trace(___arch_copy_from_user,0xdc0,0x41);
  if (pcVar8 == (char *)0x0) {
    lVar16 = -0xc;
    goto LAB_00104c7c;
  }
  local_70 = pcVar8;
  __check_object_size(pcVar8,param_3,0);
  puVar11 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar11 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar11 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar9 = param_3;
  if (uVar12 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar9 = daif;
        daif = uVar9 | 0xc0;
      }
      puVar11 = (undefined8 *)puVar11[1];
      uVar9 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar11 & 0xffff000000000000 | uVar9 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar11;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    uVar9 = __arch_copy_from_user(puVar11,pcVar8,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar13 = daif;
        daif = uVar13 | 0xc0;
      }
      uVar13 = ttbr1_el1;
      ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar13 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
  }
  if ((uVar9 == 0) || (memset(pcVar8 + (param_3 - uVar9),0,uVar9), (int)uVar9 < 1)) {
    local_70[param_3] = '\0';
    *param_4 = *param_4 + param_3;
    pcVar10 = strsep(&local_70," ");
    if (pcVar10 == (char *)0x0) {
      uVar9 = 0;
      uVar17 = 0;
      uVar20 = 0;
      uVar19 = 0;
      uVar18 = 0;
      uVar12 = 0;
      uVar14 = 0;
      uVar13 = 0;
    }
    else {
      iVar7 = kstrtouint(pcVar10,0,&local_74);
      if (iVar7 < 0) {
LAB_00104b24:
        lVar16 = -0x16;
        goto LAB_00104c74;
      }
      uVar13 = (ulong)local_74;
      if (0xff < local_74) {
        uVar13 = 0xff;
        local_74 = 0xff;
      }
      pcVar10 = strsep(&local_70," ");
      if (pcVar10 == (char *)0x0) {
        uVar9 = 0;
        uVar17 = 0;
        uVar20 = 0;
        uVar19 = 0;
        uVar18 = 0;
        uVar12 = 0;
        uVar14 = 0;
      }
      else {
        iVar7 = kstrtouint(pcVar10,0,&local_74);
        if (iVar7 < 0) goto LAB_00104b24;
        uVar14 = (ulong)local_74;
        if (0xff < local_74) {
          uVar14 = 0xff;
          local_74 = 0xff;
        }
        pcVar10 = strsep(&local_70," ");
        if (pcVar10 == (char *)0x0) {
          uVar9 = 0;
          uVar17 = 0;
          uVar20 = 0;
          uVar19 = 0;
          uVar18 = 0;
          uVar12 = 0;
        }
        else {
          iVar7 = kstrtouint(pcVar10,0,&local_74);
          if (iVar7 < 0) goto LAB_00104b24;
          uVar12 = (ulong)local_74;
          if (0xff < local_74) {
            uVar12 = 0xff;
            local_74 = 0xff;
          }
          pcVar10 = strsep(&local_70," ");
          if (pcVar10 == (char *)0x0) {
            uVar9 = 0;
            uVar17 = 0;
            uVar20 = 0;
            uVar19 = 0;
            uVar18 = 0;
          }
          else {
            iVar7 = kstrtouint(pcVar10,0,&local_74);
            if (iVar7 < 0) goto LAB_00104b24;
            if (0xff < local_74) {
              local_74 = 0xff;
            }
            uVar18 = local_74 & 0xff;
            pcVar10 = strsep(&local_70," ");
            if (pcVar10 == (char *)0x0) {
              uVar9 = 0;
              uVar17 = 0;
              uVar20 = 0;
              uVar19 = 0;
            }
            else {
              iVar7 = kstrtouint(pcVar10,0,&local_74);
              if (iVar7 < 0) goto LAB_00104b24;
              if (0xff < local_74) {
                local_74 = 0xff;
              }
              uVar19 = local_74 & 0xff;
              pcVar10 = strsep(&local_70," ");
              if (pcVar10 == (char *)0x0) {
                uVar9 = 0;
                uVar17 = 0;
                uVar20 = 0;
              }
              else {
                iVar7 = kstrtouint(pcVar10,0,&local_74);
                if (iVar7 < 0) goto LAB_00104b24;
                if (0xff < local_74) {
                  local_74 = 0xff;
                }
                uVar20 = (ulong)(local_74 & 0xff);
                pcVar10 = strsep(&local_70," ");
                if (pcVar10 == (char *)0x0) {
                  uVar9 = 0;
                  uVar17 = 0;
                }
                else {
                  iVar7 = kstrtouint(pcVar10,0,&local_74);
                  if (iVar7 < 0) goto LAB_00104b24;
                  if (0xff < local_74) {
                    local_74 = 0xff;
                  }
                  uVar17 = (ulong)(local_74 & 0xff);
                  pcVar10 = strsep(&local_70," ");
                  if (pcVar10 == (char *)0x0) {
                    uVar9 = 0;
                  }
                  else {
                    iVar7 = kstrtouint(pcVar10,0,&local_74);
                    if (iVar7 < 0) goto LAB_00104b24;
                    uVar9 = (ulong)local_74;
                    if (0xff < local_74) {
                      uVar9 = 0xff;
                      local_74 = 0xff;
                    }
                    uVar9 = uVar9 << 0x38;
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar12 = uVar20 << 0x28 | uVar17 << 0x30 | (ulong)uVar19 << 0x20 | (ulong)uVar18 << 0x18 |
             (uVar12 & 0xff) << 0x10;
    uVar14 = uVar9 | (uVar14 & 0xff) << 8 | uVar12;
    uVar1 = (uint)puVar15[1] & 0xfffffffe;
    uVar3 = (uint)uVar12 >> 0x10 & 0xff;
    uVar4 = (uint)uVar14 >> 8 & 0xff;
    *puVar15 = uVar14 | uVar13 & 0xff;
    cVar6 = (char)(uVar9 >> 0x38);
    if (uVar1 != 2) {
      *(bool *)(puVar15 + 3) =
           (((cVar6 == '\0' && (int)uVar17 == 0) &&
            (((int)uVar20 == 0 && uVar19 == 0) && uVar18 == 0)) && uVar3 == 0) && uVar4 == 0;
    }
    if ((puVar15 == (ulong *)0x0) || ((char)puVar15[3] != '\0')) {
      uVar18 = 0;
    }
    else {
      uVar2 = *(uint *)(lVar16 + 0x20);
      if (uVar1 == 2) {
        uVar18 = (uVar2 & 0xfffffff) << 3;
      }
      else {
        if (cVar6 == '\0') {
          if ((int)uVar17 == 0) {
            if ((int)uVar20 == 0) {
              if (uVar19 == 0) {
                if (uVar18 == 0) {
                  if (uVar3 == 0) {
                    if (uVar4 == 0) {
                      uVar18 = (uint)((uVar13 & 0xff) != 0);
                    }
                    else {
                      uVar18 = 2;
                    }
                  }
                  else {
                    uVar18 = 3;
                  }
                }
                else {
                  uVar18 = 4;
                }
              }
              else {
                uVar18 = 5;
              }
            }
            else {
              uVar18 = 6;
            }
          }
          else {
            uVar18 = 7;
          }
        }
        else {
          uVar18 = 8;
        }
        uVar18 = uVar18 * uVar2 >> 1;
      }
    }
    lVar16 = (long)(int)param_3;
    *(uint *)((long)puVar15 + 0x14) = uVar18;
  }
  else {
    lVar16 = -0xe;
  }
LAB_00104c74:
  kfree(pcVar8);
LAB_00104c7c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar16;
}



//------------------------------------------------------------
// brake_mode_dbgfs_read @ 00104d98 size=188
// signature: undefined brake_mode_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

long brake_mode_dbgfs_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uVar1 = *(uint *)(*(long *)(*(long *)(param_1 + 0xd8) + 0x10) + 8);
  if (3 < uVar1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x104e50);
    (*pcVar3)();
  }
  uVar4 = scnprintf(&local_50,0x18,&DAT_001130a8,(&brake_str)[uVar1]);
  iVar5 = simple_read_from_buffer(param_2,param_3,param_4,&local_50,uVar4);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar5;
}



//------------------------------------------------------------
// brake_mode_dbgfs_write @ 00104e58 size=564
// signature: undefined brake_mode_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long brake_mode_dbgfs_write(long param_1,ulong param_2,ulong param_3,long *param_4)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  char *__s1;
  ulong uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  
  lVar9 = *(long *)(*(long *)(param_1 + 0xd8) + 0x10);
  __s1 = (char *)__kmalloc(param_3 + 1,0xdc0);
  if (__s1 == (char *)0x0) {
    return -0xc;
  }
  if (param_3 >> 0x1f != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x105050);
    (*pcVar2)();
  }
  __check_object_size(__s1,param_3,0);
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar8 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar4 = param_3;
  if (uVar8 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    uVar4 = __arch_copy_from_user(puVar6,__s1,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
  }
  if ((uVar4 == 0) || (memset(__s1 + (param_3 - uVar4),0,uVar4), (int)uVar4 < 1)) {
    lVar7 = *param_4;
    __s1[param_3] = '\0';
    *param_4 = lVar7 + param_3;
    iVar3 = strcmp(__s1,"open-loop");
    if (iVar3 == 0) {
      *(undefined4 *)(lVar9 + 8) = 0;
    }
    else {
      iVar3 = strcmp(__s1,"close-loop");
      if (iVar3 == 0) {
        uVar5 = 1;
      }
      else {
        iVar3 = strcmp(__s1,"predictive");
        if (iVar3 == 0) {
          uVar5 = 2;
        }
        else {
          iVar3 = strcmp(__s1,"auto");
          if (iVar3 != 0) {
            _printk(&DAT_00112826,__s1);
            param_3 = 0xffffffffffffffea;
            goto LAB_0010500c;
          }
          uVar5 = 3;
        }
      }
      *(undefined4 *)(lVar9 + 8) = uVar5;
    }
  }
  else {
    param_3 = 0xfffffffffffffff2;
  }
LAB_0010500c:
  kfree(__s1);
  return (long)(int)param_3;
}



//------------------------------------------------------------
// brake_en_dbgfs_ops_open @ 001050ac size=52
// signature: undefined brake_en_dbgfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void brake_en_dbgfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,brake_en_dbgfs_read,brake_en_dbgfs_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// brake_en_dbgfs_read @ 001050e4 size=28
// signature: undefined brake_en_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 brake_en_dbgfs_read(long param_1,ulong *param_2)

{
  *param_2 = (ulong)(*(char *)(*(long *)(param_1 + 0x10) + 0x18) == '\0');
  return 0;
}



//------------------------------------------------------------
// brake_en_dbgfs_write @ 00105104 size=24
// signature: undefined brake_en_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 brake_en_dbgfs_write(long param_1,long param_2)

{
  *(bool *)(*(long *)(param_1 + 0x10) + 0x18) = param_2 == 0;
  return 0;
}



//------------------------------------------------------------
// brake_sine_gain_dbgfs_ops_open @ 00105120 size=52
// signature: undefined brake_sine_gain_dbgfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void brake_sine_gain_dbgfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,brake_sine_gain_dbgfs_read,brake_sine_gain_dbgfs_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// brake_sine_gain_dbgfs_read @ 00105158 size=20
// signature: undefined brake_sine_gain_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 brake_sine_gain_dbgfs_read(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x10) + 0x10);
  return 0;
}



//------------------------------------------------------------
// brake_sine_gain_dbgfs_write @ 00105170 size=32
// signature: undefined brake_sine_gain_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 brake_sine_gain_dbgfs_write(long param_1,ulong param_2)

{
  if (param_2 < 4) {
    *(int *)(*(long *)(param_1 + 0x10) + 0x10) = (int)param_2;
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// preload_effect_idx_dbgfs_ops_open @ 00105194 size=52
// signature: undefined preload_effect_idx_dbgfs_ops_open(void)
// callers: []
//------------------------------------------------------------

void preload_effect_idx_dbgfs_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,preload_effect_idx_dbgfs_read,preload_effect_idx_dbgfs_write,
                   "%llu\n");
  return;
}



//------------------------------------------------------------
// preload_effect_idx_dbgfs_read @ 001051cc size=16
// signature: undefined preload_effect_idx_dbgfs_read(void)
// callers: []
//------------------------------------------------------------

undefined8 preload_effect_idx_dbgfs_read(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x54);
  return 0;
}



//------------------------------------------------------------
// preload_effect_idx_dbgfs_write @ 001051e0 size=240
// signature: undefined preload_effect_idx_dbgfs_write(void)
// callers: []
//------------------------------------------------------------

undefined8 preload_effect_idx_dbgfs_write(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 0x340);
  if (iVar1 != 0) {
    iVar4 = 0;
    do {
      if (*(uint *)(*(long *)(param_1 + 0x68) + (long)iVar4 * 0x30 + 0x18) == param_2) {
        if (iVar1 == iVar4) {
          return 0xffffffea;
        }
        lVar6 = *(long *)(param_1 + 0x68);
        iVar7 = 0;
        plVar5 = (long *)(lVar6 + (long)iVar4 * 0x30);
        if (iVar1 == 0) goto LAB_00105284;
        goto LAB_00105264;
      }
      iVar4 = iVar4 + 1;
    } while (iVar1 != iVar4);
  }
  return 0xffffffea;
  while (iVar7 = iVar7 + 1, iVar1 != iVar7) {
LAB_00105264:
    if (*(int *)(lVar6 + (long)iVar7 * 0x30 + 0x18) == *(int *)(param_1 + 0x54)) goto LAB_00105284;
  }
  iVar7 = iVar1;
LAB_00105284:
  *(int *)(param_1 + 0x54) = (int)param_2;
  *(undefined1 *)(*plVar5 + 0x68) = 1;
  lVar3 = *plVar5;
  *(undefined4 *)(lVar6 + (long)iVar4 * 0x30 + 0x24) = 3;
  uVar2 = haptics_set_pattern(param_1,lVar3,3);
  if (-1 < (int)uVar2) {
    plVar5 = (long *)(lVar6 + (long)iVar7 * 0x30);
    uVar2 = 0;
    *(undefined4 *)((long)plVar5 + 0x24) = 2;
    *(undefined1 *)(*plVar5 + 0x68) = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// haptics_set_pattern @ 001052d0 size=796
// signature: undefined haptics_set_pattern(void)
// callers: [preload_effect_idx_dbgfs_write, haptics_upload_effect, haptics_start_lra_calibrate, haptics_hw_init]
//------------------------------------------------------------

int haptics_set_pattern(undefined8 *param_1,undefined2 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong uVar7;
  byte local_64 [4];
  undefined8 local_60;
  undefined8 local_58;
  ulong local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_60 = 0;
  if (param_3 - 4U < 0xfffffffe) {
    _dev_err(*param_1,"no pattern src specified!\n");
    iVar4 = -0x16;
  }
  else {
    local_64[0] = 0;
    uVar2 = *(uint *)(param_2 + 0x30);
    uVar7 = (ulong)uVar2;
    if ((*(byte *)(param_1 + 0x6b) >> 2 & 1) != 0) {
      uVar1 = *(int *)(param_1 + 0x69) + 0x72U & 0xffff;
      iVar4 = regmap_bulk_read(param_1[1],uVar1,local_64,1);
      if (iVar4 < 0) {
        _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar1,iVar4);
        goto LAB_0010551c;
      }
      if ((local_64[0] & 0xc) == 4) {
        uVar7 = SUB168((ZEXT416(uVar2) * (undefined1  [16])0x400) / (undefined1  [16])0x3e8,0);
      }
    }
    iVar4 = 0x32;
    if (param_3 != 3) {
      iVar4 = 0x30;
    }
    uVar2 = *(int *)((long)param_1 + 0x34c) + iVar4 & 0xffff;
    local_60 = CONCAT71(local_60._1_7_,(char)((uVar7 & 0xffffffff) / 0x500)) & 0xffffffffffffff0f;
    local_60._0_2_ = CONCAT11((char)((uVar7 & 0xffffffff) / 5),(undefined1)local_60);
    iVar4 = regmap_bulk_write(param_1[1],uVar2,&local_60,2);
    if (iVar4 < 0) {
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar2,iVar4);
      uVar5 = *param_1;
      pcVar6 = "update pattern TLRA failed, rc=%d\n";
    }
    else {
      local_60._0_4_ =
           CONCAT13(*(byte *)(param_2 + 8) & 7 | *(char *)(param_2 + 10) << 7,
                    CONCAT21(CONCAT11((char)*param_2,(char)((ushort)*param_2 >> 8)),
                             *(byte *)(param_2 + 2) & 7 | *(char *)(param_2 + 4) << 7)) & 0xffff01ff
      ;
      local_60._0_5_ = (uint5)(uint)local_60;
      local_60._0_7_ =
           CONCAT16(*(byte *)(param_2 + 0xe) & 7 | *(char *)(param_2 + 0x10) << 7,
                    CONCAT15((char)param_2[6],(uint5)local_60));
      local_60 = CONCAT17((char)((ushort)param_2[0xc] >> 8),(undefined7)local_60) &
                 0x1ffffffffffffff;
      local_60 = CONCAT35(local_60._5_3_,CONCAT14((char)((ushort)param_2[6] >> 8),(uint)local_60)) &
                 0xffffff01ffffffff;
      local_58._0_4_ = (uint)(byte)param_2[0x12] << 0x18;
      uVar2 = (uint)(int)local_58 >> 0x10;
      local_58._0_2_ =
           CONCAT11(*(byte *)(param_2 + 0x14) & 7 | *(char *)(param_2 + 0x16) << 7,
                    (char)param_2[0xc]);
      local_58._0_5_ =
           CONCAT14(*(byte *)(param_2 + 0x1a) & 7 | *(char *)(param_2 + 0x1c) << 7,
                    CONCAT22((short)uVar2,(undefined2)local_58));
      iVar4 = 0x50;
      if (param_3 != 3) {
        iVar4 = 0x34;
      }
      local_58 = CONCAT17(*(byte *)(param_2 + 0x20) & 7 | *(char *)(param_2 + 0x22) << 7,
                          CONCAT16((char)param_2[0x18],
                                   CONCAT15((char)((ushort)param_2[0x18] >> 8),
                                            (int5)CONCAT53((uint5)local_58 >> 0x18,
                                                           CONCAT12((char)((ushort)param_2[0x12] >>
                                                                          8),(undefined2)local_58)))
                                  )) & 0xffff01ffff01ffff;
      uVar2 = *(int *)((long)param_1 + 0x34c) + iVar4 & 0xffff;
      local_50 = CONCAT17((char)param_2[0x2a],
                          CONCAT16((char)((ushort)param_2[0x2a] >> 8),
                                   CONCAT15(*(byte *)(param_2 + 0x2c) & 7 |
                                            *(char *)(param_2 + 0x2e) << 7,
                                            CONCAT14((char)param_2[0x24],
                                                     CONCAT13((char)((ushort)param_2[0x24] >> 8),
                                                              CONCAT12(*(byte *)(param_2 + 0x26) & 7
                                                                       | *(char *)(param_2 + 0x28)
                                                                         << 7,CONCAT11((char)param_2
                                                  [0x1e],(char)((ushort)param_2[0x1e] >> 8)))))))) &
                 0xff01ffff01ffff01;
      iVar4 = regmap_bulk_write(param_1[1],uVar2,&local_60,0x18);
      if (-1 < iVar4) {
        iVar4 = 0;
        goto LAB_0010551c;
      }
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar2,iVar4);
      uVar5 = *param_1;
      pcVar6 = "write pattern data failed, rc=%d\n";
    }
    _dev_err(uVar5,pcVar6,iVar4);
  }
LAB_0010551c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// haptics_probe @ 001055f0 size=5284
// signature: undefined haptics_probe(void)
// callers: []
//------------------------------------------------------------

ulong haptics_probe(long param_1)

{
  char cVar1;
  bool bVar2;
  undefined1 auVar3 [16];
  undefined1 auVar4 [16];
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  ulong *puVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  uint *puVar14;
  long lVar15;
  char *pcVar16;
  undefined1 uVar17;
  undefined8 *puVar18;
  int iVar19;
  ulong uVar20;
  ulong *puVar21;
  ulong uVar22;
  undefined8 local_b8;
  uint local_b0;
  byte local_ac [4];
  ulong local_a8 [2];
  ulong *local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar12 = sp_el0;
  uVar20 = param_1 + 0x10;
  local_58 = *(long *)(lVar12 + 0x638);
  local_b0 = 0;
  local_b8 = 0;
  puVar9 = (ulong *)devm_kmalloc(uVar20,0x400,0xdc0);
  if ((puVar9 == (ulong *)0x0) ||
     (puVar10 = (undefined8 *)devm_input_allocate_device(uVar20), puVar10 == (undefined8 *)0x0)) {
    uVar20 = 0xfffffff4;
    goto LAB_00105654;
  }
  uVar11 = *(undefined8 *)(param_1 + 0x70);
  *puVar9 = uVar20;
  uVar20 = dev_get_regmap(uVar11,0);
  puVar9[1] = uVar20;
  if (uVar20 == 0) {
    _dev_err(*puVar9,"Get regmap failed\n");
    uVar20 = 0xfffffffa;
    goto LAB_00105654;
  }
  uVar22 = *puVar9;
  uVar11 = *(undefined8 *)(uVar22 + 0x2e8);
  lVar12 = of_find_property(uVar11,"qcom,hpwr-supply",0);
  if (lVar12 == 0) {
LAB_001056e4:
    lVar12 = of_find_property(uVar11,"nvmem-cells",0);
    if (lVar12 != 0) {
      uVar13 = devm_nvmem_cell_get(*puVar9,"hap_cl_brake");
      puVar9[0x38] = uVar13;
      if (uVar13 < 0xfffffffffffff001) goto LAB_00105778;
      if ((int)uVar13 == -0x205) goto LAB_001057b4;
      uVar22 = *puVar9;
      pcVar16 = "Failed to get nvmem-cells, rc=%d\n";
LAB_00105960:
      uVar20 = uVar13 & 0xffffffff;
      _dev_err(uVar22,pcVar16,uVar20);
      if ((int)uVar13 < 0) goto LAB_00105ef8;
      goto LAB_0010596c;
    }
LAB_00105778:
    lVar12 = of_find_property(uVar11,"nvmem",0);
    if (lVar12 != 0) {
      uVar13 = devm_nvmem_device_get(*puVar9,"hap_cfg_sdam");
      puVar9[0x39] = uVar13;
      if (0xfffffffffffff000 < uVar13) {
        if ((int)uVar13 == -0x205) goto LAB_001057b4;
        uVar22 = *puVar9;
        pcVar16 = "Failed to get hap_cfg nvmem device, rc=%d\n";
        goto LAB_00105960;
      }
    }
    lVar12 = of_find_property(uVar11,"qcom,pbs-client",0);
    if (lVar12 != 0) {
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = (ulong *)0x0;
      uStack_90 = 0;
      local_a8[0] = 0;
      local_a8[1] = 0;
      iVar7 = __of_parse_phandle_with_args(uVar11,"qcom,pbs-client",0,0,0,local_a8);
      uVar20 = local_a8[0];
      if (iVar7 != 0) {
        uVar20 = 0;
      }
      puVar9[0x3a] = uVar20;
      if (uVar20 == 0) {
        _dev_err(*puVar9,"Failed to get PBS client\n");
        uVar20 = 0xffffffed;
        goto LAB_00105ef8;
      }
    }
    puVar14 = (uint *)__of_get_address(uVar11,0,0xffffffff,0,0);
    if (puVar14 == (uint *)0x0) {
      uVar20 = *puVar9;
      pcVar16 = "Read HAPTICS_CFG address failed\n";
LAB_001058d4:
      _dev_err(uVar20,pcVar16);
LAB_001058d8:
      uVar20 = 0xffffffea;
      if (puVar9[0x3a] != 0) {
LAB_001058e4:
        puVar9[0x3a] = 0;
      }
      goto LAB_00105ef8;
    }
    uVar5 = (*puVar14 & 0xff00ff00) >> 8 | (*puVar14 & 0xff00ff) << 8;
    *(uint *)(puVar9 + 0x69) = uVar5 >> 0x10 | uVar5 << 0x10;
    puVar14 = (uint *)__of_get_address(uVar11,1,0xffffffff,0,0);
    if (puVar14 == (uint *)0x0) {
      uVar20 = *puVar9;
      pcVar16 = "Read HAPTICS_PATTERN address failed\n";
      goto LAB_001058d4;
    }
    uVar5 = (*puVar14 & 0xff00ff00) >> 8 | (*puVar14 & 0xff00ff) << 8;
    *(uint *)((long)puVar9 + 0x34c) = uVar5 >> 0x10 | uVar5 << 0x10;
    puVar14 = (uint *)__of_get_address(uVar11,2,0xffffffff,0,0);
    if (puVar14 == (uint *)0x0) {
      if ((puVar9[0x4e] == 0) && ((int)puVar9[0x6d] != 3)) {
        uVar20 = *puVar9;
        pcVar16 = "Read HAPTICS_HBOOST address failed\n";
        goto LAB_001058d4;
      }
    }
    else {
      uVar5 = (*puVar14 & 0xff00ff00) >> 8 | (*puVar14 & 0xff00ff) << 8;
      *(uint *)(puVar9 + 0x6a) = uVar5 >> 0x10 | uVar5 << 0x10;
    }
    local_a8[0] = local_a8[0] & 0xffffffffffff0000;
    uVar5 = (int)puVar9[0x69] + 1U & 0xffff;
    uVar20 = regmap_bulk_read(puVar9[1],uVar5,local_a8,1);
    if ((int)uVar20 < 0) {
LAB_00105ec0:
      uVar20 = uVar20 & 0xffffffff;
      _dev_err(*puVar9,"read addr %#x failed, rc=%d\n",uVar5,uVar20);
LAB_00105edc:
      uVar22 = *puVar9;
      pcVar16 = "Get revision failed, rc=%d\n";
LAB_00105ee8:
      _dev_err(uVar22,pcVar16,uVar20);
      if (puVar9[0x3a] == 0) goto LAB_00105ef8;
      goto LAB_001058e4;
    }
    uVar5 = *(int *)((long)puVar9 + 0x34c) + 1U & 0xffff;
    *(undefined1 *)(puVar9 + 0x6c) = (undefined1)local_a8[0];
    uVar20 = regmap_bulk_read(puVar9[1],uVar5,local_a8,1);
    if ((int)uVar20 < 0) goto LAB_00105ec0;
    *(undefined1 *)((long)puVar9 + 0x361) = (undefined1)local_a8[0];
    if ((puVar9[0x4e] == 0) && ((int)puVar9[0x6d] != 3)) {
      uVar5 = (uint)(ushort)puVar9[0x6a];
      uVar20 = regmap_bulk_read(puVar9[1],uVar5,local_a8,2);
      if ((int)uVar20 < 0) goto LAB_00105ec0;
      *(undefined2 *)((long)puVar9 + 0x364) = (undefined2)local_a8[0];
      _dev_info(*puVar9,"haptics revision: HAP_CFG %#x, HAP_PTN %#x, HAP_HBST %#x\n",
                (char)puVar9[0x6c],*(undefined1 *)((long)puVar9 + 0x361));
    }
    else {
      _dev_info(*puVar9,"haptics revision: HAP_CFG %#x, HAP_PTN %#x\n",(char)puVar9[0x6c]);
    }
    cVar1 = (char)puVar9[0x6c];
    if (cVar1 != '\x04') {
      if (cVar1 == '\x03') {
        uVar5 = (uint)*(byte *)((long)puVar9 + 0x361);
        if (*(byte *)((long)puVar9 + 0x361) != 3) goto LAB_001060f4;
        goto LAB_00105f84;
      }
      if ((cVar1 == '\x02') &&
         (uVar5 = (uint)*(byte *)((long)puVar9 + 0x361), *(byte *)((long)puVar9 + 0x361) == 2))
      goto LAB_00105f84;
LAB_001060f4:
      _dev_err(*puVar9,"haptics revision is not supported\n");
      uVar20 = 0xffffffa1;
      goto LAB_00105edc;
    }
    uVar5 = (uint)*(byte *)((long)puVar9 + 0x361);
    if (*(byte *)((long)puVar9 + 0x361) != 4) goto LAB_001060f4;
LAB_00105f84:
    *(uint *)(puVar9 + 0x6d) = uVar5;
    iVar7 = platform_get_irq_byname(uVar22 - 0x10,"fifo-empty");
    *(int *)(puVar9 + 0x67) = iVar7;
    if (iVar7 == 0) {
      uVar20 = *puVar9;
      pcVar16 = "Get fifo-empty IRQ failed\n";
      goto LAB_001058d4;
    }
    puVar14 = (uint *)((long)puVar9 + 0x34);
    *puVar14 = 5000;
    of_property_read_variable_u32_array(uVar11,"qcom,vmax-mv",puVar14,1,0);
    uVar5 = *puVar14;
    if (0x55e < uVar5 >> 3) {
      uVar20 = *puVar9;
      pcVar16 = "qcom,vmax-mv (%d) exceed the max value: %d\n";
      uVar8 = 11000;
LAB_00106858:
      _dev_err(uVar20,pcVar16,uVar5,uVar8);
      goto LAB_001058d8;
    }
    *(undefined4 *)(puVar9 + 7) = 0;
    uVar5 = (int)puVar9[0x6d] - 2;
    if (uVar5 < 3) {
      uVar5 = *(uint *)(&DAT_00110c10 + (long)(int)uVar5 * 4);
    }
    else {
      _printk(&DAT_00111ba3);
      uVar5 = 0;
    }
    puVar21 = puVar9 + 0xb;
    *(uint *)puVar21 = uVar5;
    of_property_read_variable_u32_array(uVar11,"qcom,fifo-empty-threshold",puVar21,1,0);
    iVar7 = (int)puVar9[0x6d];
    uVar5 = (uint)*puVar21;
    if (iVar7 != 2) {
      if (iVar7 == 4) {
        uVar6 = 0x280;
        if (*(uint *)((long)puVar9 + 0xec) != 0) {
          uVar6 = *(uint *)((long)puVar9 + 0xec);
        }
        goto LAB_00106174;
      }
      if (iVar7 == 3) {
        uVar6 = 0x400;
        goto LAB_00106174;
      }
      _printk(&DAT_00111ba3);
      uVar5 = (uint)*puVar21;
LAB_00106838:
      uVar20 = *puVar9;
      uVar8 = get_max_fifo_samples(puVar9);
      pcVar16 = "FIFO empty threshold (%d) should be less than %d\n";
      goto LAB_00106858;
    }
    uVar6 = 0x280;
LAB_00106174:
    if (uVar6 <= uVar5) goto LAB_00106838;
    puVar21 = puVar9 + 4;
    *(uint *)puVar21 = 3;
    of_property_read_variable_u32_array(uVar11,"qcom,brake-mode",puVar21,1,0);
    uVar5 = (uint)*puVar21;
    if (3 < uVar5) {
      uVar20 = *puVar9;
      pcVar16 = "Can\'t support brake mode: %d\n";
LAB_0010680c:
      _dev_err(uVar20,pcVar16,uVar5);
      goto LAB_001058d8;
    }
    lVar12 = of_find_property(uVar11,"qcom,brake-disable",0);
    *(bool *)(puVar9 + 6) = lVar12 != 0;
    iVar7 = of_property_count_elems_of_size(uVar11,"qcom,brake-pattern",1);
    if (8 < iVar7) {
      uVar20 = *puVar9;
      pcVar16 = "more than %d brake samples\n";
      uVar5 = 8;
      goto LAB_0010680c;
    }
    if (0 < iVar7) {
      uVar5 = of_property_read_variable_u8_array(uVar11,"qcom,brake-pattern",puVar9 + 3,iVar7,0);
      if (-1 < (int)uVar5) {
        if ((*puVar21 & 0xfffffffe) != 2) {
          if (((((*(char *)((long)puVar9 + 0x1f) == '\0') &&
                (*(char *)((long)puVar9 + 0x1e) == '\0')) &&
               (*(char *)((long)puVar9 + 0x1d) == '\0')) &&
              ((*(char *)((long)puVar9 + 0x1c) == '\0' && (*(char *)((long)puVar9 + 0x1b) == '\0')))
              ) && ((*(char *)((long)puVar9 + 0x1a) == '\0' &&
                    (*(char *)((long)puVar9 + 0x19) == '\0')))) goto LAB_001062a4;
          uVar17 = 0;
          goto LAB_001062a8;
        }
        goto LAB_001062ac;
      }
      uVar20 = (ulong)uVar5;
      uVar22 = *puVar9;
      pcVar16 = "Read brake-pattern failed, rc=%d\n";
      goto LAB_00105ee8;
    }
    if ((uint)*puVar21 < 2) {
LAB_001062a4:
      uVar17 = 1;
LAB_001062a8:
      *(undefined1 *)(puVar9 + 6) = uVar17;
    }
LAB_001062ac:
    lVar12 = of_find_property(uVar11,"qcom,use-erm",0);
    *(bool *)((long)puVar9 + 100) = lVar12 != 0;
    if (lVar12 == 0) {
      uVar11 = *(undefined8 *)(*puVar9 + 0x2e8);
      uVar5 = of_property_read_variable_u32_array
                        (uVar11,"qcom,lra-period-us",(uint *)((long)puVar9 + 0x3c),1,0);
      if ((int)uVar5 < 0) {
        uVar20 = (ulong)uVar5;
        _dev_err(*puVar9,"Read T-LRA failed, rc=%d\n",uVar20);
      }
      else {
        uVar5 = *(uint *)((long)puVar9 + 0x3c);
        if (uVar5 < 0x4ffc) {
          puVar21 = puVar9 + 0xc;
          *(uint *)puVar21 = 1;
          of_property_read_variable_u32_array(uVar11,"qcom,drv-sig-shape",puVar21,1,0);
          if ((uint)*puVar21 < 3) {
            puVar14 = (uint *)((long)puVar9 + 0x24);
            *puVar14 = 1;
            of_property_read_variable_u32_array(uVar11,"qcom,brake-sig-shape",puVar14,1,0);
            if (*puVar14 < 3) {
              if (*puVar14 == 1) {
                puVar21 = puVar9 + 5;
                *(uint *)puVar21 = 0;
                of_property_read_variable_u32_array(uVar11,"qcom,brake-sine-gain",puVar21,1,0);
                if (3 < (uint)*puVar21) {
                  uVar20 = *puVar9;
                  pcVar16 = "Can\'t support brake sine gain: %d\n";
                  goto LAB_0010696c;
                }
              }
              if ((int)puVar9[0x6d] == 4) {
                lVar12 = of_find_property(uVar11,"qcom,rt-imp-detect",0);
                *(bool *)((long)puVar9 + 0x65) = lVar12 != 0;
              }
              goto LAB_001062dc;
            }
            uVar20 = *puVar9;
            pcVar16 = "Can\'t support brake shape: %d\n";
          }
          else {
            uVar20 = *puVar9;
            pcVar16 = "Can\'t support drive shape: %d\n";
          }
LAB_0010696c:
          _dev_err(uVar20,pcVar16);
        }
        else {
          _dev_err(*puVar9,"qcom,lra-period-us (%d) exceed the max value: %d\n",uVar5,0x4ffb);
        }
        uVar20 = 0xffffffea;
      }
      uVar22 = *puVar9;
      pcVar16 = "Parse device-tree for LRA failed, rc=%d\n";
      goto LAB_00105ee8;
    }
    *(undefined4 *)(puVar9 + 0xc) = 2;
    *(undefined4 *)((long)puVar9 + 0x24) = 2;
LAB_001062dc:
    *(undefined4 *)((long)puVar9 + 0x54) = 0xffffffea;
    uVar11 = *(undefined8 *)(*puVar9 + 0x2e8);
    lVar12 = of_get_next_available_child(uVar11,0);
    if (lVar12 != 0) {
      iVar7 = 0;
      do {
        lVar15 = of_find_property(lVar12,"qcom,effect-id",0);
        if (lVar15 != 0) {
          iVar7 = iVar7 + 1;
        }
        lVar12 = of_get_next_available_child(uVar11,lVar12);
      } while (lVar12 != 0);
      if (iVar7 != 0) {
        auVar3._8_8_ = 0;
        auVar3._0_8_ = (long)iVar7;
        if (SUB168(auVar3 * ZEXT816(0x30),8) == 0) {
          uVar20 = devm_kmalloc(*puVar9,((long)iVar7 + (long)iVar7 * 2) * 0x10,0xdc0);
          puVar9[0xd] = uVar20;
          if (uVar20 != 0) {
            lVar12 = of_get_next_available_child(uVar11,0);
            if (lVar12 == 0) {
              iVar7 = 0;
            }
            else {
              iVar7 = 0;
              do {
                lVar15 = of_find_property(lVar12,"qcom,effect-id",0);
                if (lVar15 != 0) {
                  uVar5 = of_property_read_variable_u32_array
                                    (lVar12,"qcom,effect-id",puVar9[0xd] + (long)iVar7 * 0x30 + 0x18
                                     ,1,0);
                  if ((int)uVar5 < 0) {
                    uVar20 = (ulong)uVar5;
                    _dev_err(*puVar9,"Read qcom,effect-id failed, rc=%d\n",uVar20);
                    goto LAB_0010699c;
                  }
                  uVar5 = haptics_parse_per_effect_dt
                                    (puVar9,lVar12,puVar9[0xd] + (long)iVar7 * 0x30);
                  if ((int)uVar5 < 0) {
                    uVar20 = (ulong)uVar5;
                    _dev_err(*puVar9,"parse effect %d failed, rc=%d\n",iVar7,uVar20);
                    goto LAB_0010699c;
                  }
                  iVar7 = iVar7 + 1;
                }
                lVar12 = of_get_next_available_child(uVar11,lVar12);
              } while (lVar12 != 0);
            }
            *(int *)(puVar9 + 0x68) = iVar7;
            __dump_effects(puVar9[0xd],iVar7);
            goto LAB_0010667c;
          }
          uVar20 = 0xfffffff4;
        }
        else {
          uVar20 = 0xfffffff4;
          puVar9[0xd] = 0;
        }
LAB_0010699c:
        uVar22 = *puVar9;
        pcVar16 = "Parse device-tree for effects failed, rc=%d\n";
        goto LAB_00105ee8;
      }
    }
LAB_0010667c:
    uVar11 = *(undefined8 *)(*puVar9 + 0x2e8);
    lVar12 = of_get_next_available_child(uVar11,0);
    if (lVar12 != 0) {
      iVar7 = 0;
      do {
        lVar15 = of_find_property(lVar12,"qcom,primitive-id",0);
        if (lVar15 != 0) {
          iVar7 = iVar7 + 1;
        }
        lVar12 = of_get_next_available_child(uVar11,lVar12);
      } while (lVar12 != 0);
      if (iVar7 != 0) {
        auVar4._8_8_ = 0;
        auVar4._0_8_ = (long)iVar7;
        if (SUB168(auVar4 * ZEXT816(0x30),8) == 0) {
          uVar20 = devm_kmalloc(*puVar9,((long)iVar7 + (long)iVar7 * 2) * 0x10,0xdc0);
          puVar9[0xe] = uVar20;
          if (uVar20 != 0) {
            lVar12 = of_get_next_available_child(uVar11,0);
            if (lVar12 == 0) {
              iVar7 = 0;
            }
            else {
              iVar7 = 0;
              do {
                lVar15 = of_find_property(lVar12,"qcom,primitive-id",0);
                if (lVar15 != 0) {
                  uVar5 = of_property_read_variable_u32_array
                                    (lVar12,"qcom,primitive-id",
                                     puVar9[0xe] + (long)iVar7 * 0x30 + 0x18,1,0);
                  if ((int)uVar5 < 0) {
                    uVar20 = (ulong)uVar5;
                    _dev_err(*puVar9,"Read qcom,primitive-id failed, rc=%d\n",uVar20);
                    goto LAB_001069e4;
                  }
                  uVar5 = haptics_parse_per_effect_dt
                                    (puVar9,lVar12,puVar9[0xe] + (long)iVar7 * 0x30);
                  if ((int)uVar5 < 0) {
                    uVar20 = (ulong)uVar5;
                    _dev_err(*puVar9,"parse primitive %d failed, rc=%d\n",iVar7,uVar20);
                    goto LAB_001069e4;
                  }
                  iVar7 = iVar7 + 1;
                }
                lVar12 = of_get_next_available_child(uVar11,lVar12);
              } while (lVar12 != 0);
            }
            *(int *)((long)puVar9 + 0x344) = iVar7;
            __dump_effects(puVar9[0xe],iVar7);
            goto LAB_0010596c;
          }
          uVar20 = 0xfffffff4;
        }
        else {
          uVar20 = 0xfffffff4;
          puVar9[0xe] = 0;
        }
LAB_001069e4:
        uVar22 = *puVar9;
        pcVar16 = "Parse device-tree for primitives failed, rc=%d\n";
        goto LAB_00105ee8;
      }
    }
LAB_0010596c:
    uVar20 = devm_kmalloc(*puVar9,0x30,0xdc0);
    puVar9[0xf] = uVar20;
    if (uVar20 == 0) {
LAB_00105f10:
      uVar20 = 0xfffffff4;
      _dev_err(*puVar9,"Init custom effect failed, rc=%d\n",0xfffffff4);
      goto LAB_00105654;
    }
    uVar11 = devm_kmalloc(*puVar9,0x18,0xdc0);
    *(undefined8 *)(puVar9[0xf] + 8) = uVar11;
    if (((undefined8 *)puVar9[0xf])[1] == 0) goto LAB_00105f10;
    *(undefined8 *)puVar9[0xf] = 0;
    *(undefined8 *)(puVar9[0xf] + 0x10) = 0;
    *(undefined4 *)(puVar9[0xf] + 0x18) = 0xffffffff;
    *(undefined4 *)(puVar9[0xf] + 0x1c) = *(undefined4 *)((long)puVar9 + 0x34);
    *(undefined4 *)(puVar9[0xf] + 0x20) = *(undefined4 *)((long)puVar9 + 0x3c);
    *(undefined4 *)(puVar9[0xf] + 0x24) = 0;
    *(undefined1 *)(puVar9[0xf] + 0x2c) = 1;
    __mutex_init(puVar9 + 0x5b,"&chip->vmax_lock",&haptics_probe___key);
    uVar5 = haptics_hw_init(puVar9);
    if ((int)uVar5 < 0) {
      uVar20 = (ulong)uVar5;
      uVar22 = *puVar9;
      pcVar16 = "Initialize HW failed, rc = %d\n";
      goto LAB_00105f04;
    }
    if ((int)puVar9[0x6d] != 3) {
      local_88 = 0;
      uStack_80 = 0;
      local_98 = (ulong *)0x0;
      uStack_90 = 0;
      uVar5 = (int)puVar9[0x69] + 0x4eU & 0xffff;
      local_a8[1] = 0;
      local_ac[0] = 0;
      uVar6 = regmap_bulk_read(puVar9[1],uVar5,local_ac,1);
      if ((int)uVar6 < 0) {
        uVar20 = (ulong)uVar6;
        _dev_err(*puVar9,"read addr %#x failed, rc=%d\n",uVar5,uVar20);
        _dev_err(*puVar9,"Failed to read SWR_ACCESS, rc=%d\n",uVar20);
      }
      else {
        local_a8[0] = *puVar9;
        *(bool *)((long)puVar9 + 0x36d) = 0xdf < local_ac[0];
        local_ac[0] = local_ac[0] & 0xe0;
        local_98 = puVar9;
        uVar20 = devm_regulator_register(local_a8[0],&swr_slave_reg_rdesc,local_a8);
        puVar9[0x37] = uVar20;
        if (uVar20 < 0xfffffffffffff001) goto LAB_00105a90;
        puVar9[0x37] = 0;
        if ((int)uVar20 == -0x205) {
          uVar20 = 0xfffffdfb;
        }
        else {
          _dev_err(*puVar9,"register swr-slave-reg regulator failed, rc=%d\n",uVar20 & 0xffffffff);
          if (-1 < (int)uVar20) goto LAB_00105a90;
        }
      }
      _dev_err(*puVar9,"Initialize swr slave regulator failed, rc = %d\n",uVar20 & 0xffffffff);
      goto LAB_00105654;
    }
LAB_00105a90:
    uVar5 = devm_request_threaded_irq
                      (*puVar9,(int)puVar9[0x67],0,fifo_empty_irq_handler,0x2000,"fifo-empty",puVar9
                      );
    if ((int)uVar5 < 0) {
      uVar20 = (ulong)uVar5;
      uVar22 = *puVar9;
      pcVar16 = "request fifo-empty IRQ failed, rc=%d\n";
    }
    else {
      __mutex_init(puVar9 + 0x14,"&chip->play.lock",&haptics_probe___key_113);
      disable_irq_nosync((int)puVar9[0x67]);
      *(undefined1 *)((long)puVar9 + 0x36c) = 0;
      hrtimer_init(puVar9 + 0x4f,1,1);
      puVar9[0x54] = (ulong)haptics_disable_hbst_timer;
      puVar9[0x26] = 0xfffffffe0;
      puVar9[0x27] = (ulong)(puVar9 + 0x27);
      puVar9[0x28] = (ulong)(puVar9 + 0x27);
      puVar9[0x29] = (ulong)haptics_stop_constant_effect_play;
      init_timer_key(puVar9 + 0x2c,&delayed_work_timer_fn,0x200000,0,0);
      puVar9[0x61] = 0xfffffffe0;
      puVar9[0x62] = (ulong)(puVar9 + 0x62);
      puVar9[99] = (ulong)(puVar9 + 0x62);
      puVar9[100] = (ulong)haptics_set_gain_work;
      *(undefined4 *)(puVar9 + 0x13) = 0;
      *(undefined4 *)((long)puVar9 + 0x94) = 0;
      *(undefined4 *)((long)puVar9 + 0x9c) = 0;
      *puVar10 = "qcom-hv-haptics";
      puVar10[0x5b] = puVar9;
      puVar9[2] = (ulong)puVar10;
      input_set_capability(puVar10,0x15,0x52);
      input_set_capability(puVar10,0x15,0x60);
      if (((int)puVar9[0x68] == 0) && (*(int *)((long)puVar9 + 0x344) == 0)) {
        iVar19 = 0;
        iVar7 = 0;
      }
      else {
        input_set_capability(puVar10,0x15,0x51);
        input_set_capability(puVar10,0x15,0x5d);
        iVar7 = (int)puVar9[0x68];
        iVar19 = *(int *)((long)puVar9 + 0x344);
      }
      if (0x40 < (uint)(iVar19 + iVar7)) {
        _dev_err(*puVar9,"Effects count cannot be more than %d\n",0x40);
        iVar7 = (int)puVar9[0x68];
      }
      iVar7 = iVar7 + *(int *)((long)puVar9 + 0x344);
      iVar19 = 0x40;
      if (iVar7 + 1U < 0x40) {
        iVar19 = iVar7 + 1;
      }
      uVar5 = input_ff_create(puVar10,iVar19);
      if (-1 < (int)uVar5) {
        puVar18 = (undefined8 *)puVar10[0x1f];
        *puVar18 = haptics_upload_effect;
        puVar18[1] = haptics_erase;
        puVar18[2] = haptics_playback;
        puVar18[3] = haptics_set_gain;
        uVar22 = input_register_device(puVar10);
        uVar20 = uVar22 & 0xffffffff;
        uVar13 = *puVar9;
        if ((int)uVar22 < 0) {
          pcVar16 = "register input device failed, rc=%d\n";
LAB_001060c0:
          _dev_err(uVar13,pcVar16,uVar20);
        }
        else {
          *(ulong **)(uVar13 + 0x98) = puVar9;
          puVar9[0x3b] = (ulong)"qcom-haptics";
          puVar9[0x3d] = (ulong)&hap_class_groups;
          uVar5 = __class_register(puVar9 + 0x3b,&haptics_probe___key_119);
          if ((int)uVar5 < 0) {
            uVar20 = (ulong)uVar5;
            uVar13 = *puVar9;
            pcVar16 = "register hap_class failed, rc=%d\n";
            goto LAB_001060c0;
          }
          puVar9[0x58] = (ulong)haptics_boost_notifier;
          register_hboost_event_notifier(puVar9 + 0x58);
          uVar6 = of_property_read_variable_u32_array
                            (*(undefined8 *)(*puVar9 + 0x2e8),"moto,wf-vmax-mv",(long)puVar9 + 0x3fc
                             ,1,0);
          uVar5 = uVar6;
          if (-1 < (int)uVar6) {
            uVar5 = 0;
          }
          uVar20 = (ulong)uVar5;
          if ((int)uVar6 < 0) {
            _dev_info(*puVar9,"No voltage config,use default value:9000mV\n");
            *(undefined4 *)((long)puVar9 + 0x3fc) = 9000;
          }
          uVar22 = kmalloc_large(16000,0xcc0);
          puVar9[0x6f] = uVar22;
          if (uVar22 != 0) {
            uVar22 = __get_free_pages(0xcc0,2);
            puVar9[0x70] = uVar22;
            if (uVar22 != 0) {
              puVar21 = (ulong *)((((long)(uVar22 << 8) >> 8) + 0x8000000000U >> 6 &
                                  0x3ffffffffffffc0) - 0x200000000);
              Hint_Prefetch(puVar21,2,0,1);
              do {
                cVar1 = '\x01';
                bVar2 = (bool)ExclusiveMonitorPass(puVar21,0x10);
                if (bVar2) {
                  *puVar21 = *puVar21 | 0x1000;
                  cVar1 = ExclusiveMonitorsStatus();
                }
              } while (cVar1 != '\0');
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar20 + 8) = uVar20 + 0x400;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0x408) = uVar22 + 0x800;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x808) = uVar20 + 0xc00;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0xc08) = uVar22 + 0x1000;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x1008) = uVar20 + 0x1400;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0x1408) = uVar22 + 0x1800;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x1808) = uVar20 + 0x1c00;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0x1c08) = uVar22 + 0x2000;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x2008) = uVar20 + 0x2400;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0x2408) = uVar22 + 0x2800;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x2808) = uVar20 + 0x2c00;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0x2c08) = uVar22 + 0x3000;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x3008) = uVar20 + 0x3400;
              uVar22 = puVar9[0x70];
              *(ulong *)(uVar20 + 0x3408) = uVar22 + 0x3800;
              uVar20 = puVar9[0x70];
              *(ulong *)(uVar22 + 0x3808) = uVar20 + 0x3c00;
              *(ulong *)(uVar20 + 0x3c08) = puVar9[0x70];
              puVar9[0x72] = 0xfffffffe0;
              puVar9[0x73] = (ulong)(puVar9 + 0x73);
              puVar9[0x74] = (ulong)(puVar9 + 0x73);
              puVar9[0x75] = (ulong)richtap_work_proc;
              puVar9[0x78] = 0xfffffffe0;
              puVar9[0x79] = (ulong)(puVar9 + 0x79);
              puVar9[0x7a] = (ulong)(puVar9 + 0x79);
              puVar9[0x7b] = (ulong)richtap_erase_work_proc;
              misc_register(richtap_misc);
              *(undefined4 *)((long)puVar9 + 0x3f4) = 0;
              g_richtap_ptr = puVar9;
              iVar7 = haptics_create_debugfs(puVar9);
              if (iVar7 < 0) {
                _dev_err(*puVar9,"Creating debugfs failed, rc=%d\n",iVar7);
              }
              lVar12 = of_find_property(*(undefined8 *)(*puVar9 + 0x2e8),"moto,cal_again",0);
              if (lVar12 != 0) {
                uVar5 = 0;
                if ((uint)puVar9[8] != 0) {
                  uVar5 = 1000000 / (uint)puVar9[8];
                }
                _dev_err(*puVar9,"In XBL cal F0 is %d Hz\n",uVar5);
                iVar7 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(*puVar9 + 0x2e8),"moto,lra-period-us-min",
                                   &local_b0,1,0);
                if (iVar7 < 0) {
                  _dev_err(*puVar9,"Read T-LRA-min failed, rc=%d\n");
                }
                else {
                  iVar7 = of_property_read_variable_u32_array
                                    (*(undefined8 *)(*puVar9 + 0x2e8),"moto,lra-period-us-max",
                                     (long)&local_b8 + 4,1,0);
                  if (iVar7 < 0) {
                    _dev_err(*puVar9,"Read T-LRA-max failed, rc=%d\n",iVar7);
                  }
                  else if (((uint)puVar9[8] < local_b0) || (local_b8._4_4_ < (uint)puVar9[8])) {
                    _dev_err(*puVar9,"The start up cal fail, cal again in kernel\n");
                    iVar7 = haptics_start_lra_calibrate(puVar9);
                    if (iVar7 < 0) {
                      _dev_err(*puVar9,"Cal again failed in kernel\n");
                    }
                    else {
                      uVar5 = 0;
                      if ((uint)puVar9[8] != 0) {
                        uVar5 = 1000000 / (uint)puVar9[8];
                      }
                      _dev_err(*puVar9,"Latest cal F0 is %d Hz\n",uVar5);
                      if (((uint)puVar9[8] < local_b0) || (local_b8._4_4_ < (uint)puVar9[8])) {
                        iVar7 = of_property_read_variable_u32_array
                                          (*(undefined8 *)(*puVar9 + 0x2e8),
                                           "moto,lra-period-cal-count",&local_b8,1,0);
                        if (iVar7 < 0) {
                          _dev_err(*puVar9,"Read cal-count failed, rc=%d\n",iVar7);
                          uVar20 = 0x244;
                          local_b8 = CONCAT44(local_b8._4_4_,0x244);
                        }
                        else {
                          uVar20 = local_b8 & 0xffffffff;
                        }
                        uVar5 = 0;
                        if (*(uint *)((long)puVar9 + 0x3c) != 0) {
                          uVar5 = 1000000 / *(uint *)((long)puVar9 + 0x3c);
                        }
                        _dev_err(*puVar9,
                                 "Failure of all cal, set manual freq to %dHz, f0_count to %d\n",
                                 uVar5,uVar20);
                        *(undefined4 *)(puVar9 + 8) = *(undefined4 *)((long)puVar9 + 0x3c);
                        *(short *)((long)puVar9 + 0x5c) = (short)local_b8;
                        iVar7 = haptics_config_openloop_lra_period(puVar9);
                        if (iVar7 < 0) {
                          _dev_err(*puVar9,"Config manual freq failed, rc=%d\n",iVar7);
                        }
                        iVar7 = haptics_set_manual_rc_clk_cal(puVar9);
                        if (iVar7 < 0) {
                          _dev_err(*puVar9,"Config manual cal count failed, rc=%d\n",iVar7);
                        }
                      }
                    }
                  }
                }
              }
              uVar20 = 0;
              goto LAB_00105654;
            }
            _dev_err(*puVar9,"Error __get_free_pages failed\n");
            kfree(puVar9[0x6f]);
          }
        }
        input_ff_destroy(puVar9[2]);
        goto LAB_00105654;
      }
      uVar20 = (ulong)uVar5;
      uVar22 = *puVar9;
      pcVar16 = "create input FF device failed, rc=%d\n";
    }
  }
  else {
    uVar20 = devm_regulator_get(*puVar9,"qcom,hpwr");
    puVar9[0x4e] = uVar20;
    if (uVar20 < 0xfffffffffffff001) {
      uVar5 = of_property_read_variable_u32_array
                        (uVar11,"qcom,hpwr-voltage-mv",(int *)((long)puVar9 + 0x33c),1,0);
      if ((int)uVar5 < 0) {
        uVar20 = (ulong)uVar5;
        _dev_err(*puVar9,"Failed to read qcom,hpwr-voltage-mv, rc=%d\n",uVar20);
      }
      else {
        if (0xfffff05f < *(int *)((long)puVar9 + 0x33c) - 0xfa1U) goto LAB_001056e4;
        uVar20 = 0xffffffea;
      }
    }
    else if ((int)uVar20 == -0x205) {
LAB_001057b4:
      uVar20 = 0xfffffdfb;
    }
    else {
      _dev_err(*puVar9,"Failed to get qcom,hpwr-supply, rc=%d\n",uVar20 & 0xffffffff);
      if (-1 < (int)uVar20) goto LAB_001056e4;
    }
LAB_00105ef8:
    uVar22 = *puVar9;
    pcVar16 = "Parse device-tree failed, rc = %d\n";
  }
LAB_00105f04:
  _dev_err(uVar22,pcVar16,uVar20 & 0xffffffff);
LAB_00105654:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar20 & 0xffffffff;
}



//------------------------------------------------------------
// haptics_remove @ 00106aa8 size=100
// signature: undefined haptics_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_remove(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  unregister_hboost_event_notifier(plVar1 + 0x58);
  class_unregister(plVar1 + 0x3b);
  debugfs_remove(plVar1[0x25]);
  kfree(plVar1[0x6f]);
  free_pages(plVar1[0x70],2);
  input_unregister_device(plVar1[2]);
  *(undefined8 *)(*plVar1 + 0x98) = 0;
  return 0;
}



//------------------------------------------------------------
// haptics_shutdown @ 00106b10 size=68
// signature: undefined haptics_shutdown(void)
// callers: []
//------------------------------------------------------------

void haptics_shutdown(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  haptics_suspend_config(*plVar1);
  if (0 < *(int *)(*(long *)(*plVar1 + 0x98) + 0x338)) {
    devm_free_irq();
  }
  return;
}



//------------------------------------------------------------
// haptics_hw_init @ 00106b54 size=2180
// signature: undefined haptics_hw_init(void)
// callers: [haptics_probe, haptics_restore]
//------------------------------------------------------------

int haptics_hw_init(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  ulong uVar9;
  int iVar10;
  undefined8 *puVar11;
  long lVar12;
  undefined2 uVar13;
  long lVar14;
  uint uVar15;
  uint uVar16;
  long *plVar17;
  uint local_6c;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  iVar5 = *(int *)(param_1 + 0x6d);
  if (iVar5 != 2) {
    if (iVar5 == 3) goto LAB_00106be0;
    if (iVar5 == 4) {
      uVar16 = *(uint *)(param_1 + 0x6b) | 2;
      if (*(short *)((long)param_1 + 0x364) != 1) {
        uVar16 = *(uint *)(param_1 + 0x6b);
      }
      *(uint *)(param_1 + 0x6b) = uVar16 | 0x100;
      _dev_err(*param_1,"HW type %d wa_flag: %#x\n");
      goto LAB_00106be0;
    }
    uVar7 = *param_1;
    pcVar8 = "HW type %d does not match\n";
LAB_00106ed0:
    _dev_err(uVar7,pcVar8,iVar5);
    iVar5 = -0x16;
    goto LAB_00106f98;
  }
  *(uint *)(param_1 + 0x6b) = *(uint *)(param_1 + 0x6b) | 0x1f;
LAB_00106be0:
  local_6c = local_6c & 0xffff0000;
  if (param_1[0x38] != 0) {
    iVar5 = haptics_get_status_data(param_1,6,&local_6c);
    if (iVar5 < 0) goto LAB_00106f98;
    iVar5 = nvmem_cell_write(param_1[0x38],(ulong)&local_6c | 1,1);
    if (iVar5 < 0) {
      _dev_err(*param_1,"store RNAT/RCAL to SDAM failed, rc=%d\n",iVar5);
      goto LAB_00106f98;
    }
  }
  local_6c = local_6c & 0xffffff00;
  if ((param_1[0x4e] == 0) && (*(int *)(param_1 + 0x6d) != 3)) {
    uVar16 = *(int *)(param_1 + 0x6a) + 0x70U & 0xffff;
    iVar5 = regmap_bulk_read(param_1[1],uVar16,&local_6c,1);
    if (-1 < iVar5) {
      *(byte *)((long)param_1 + 0x36e) = (byte)local_6c & 1;
      goto LAB_00106c60;
    }
    goto LAB_00106ea4;
  }
LAB_00106c60:
  *(undefined1 *)(param_1 + 0x6e) = 1;
  *(undefined2 *)((long)param_1 + 0x366) = 11000;
  if (*(int *)(param_1 + 0x6d) - 3U < 2) {
    uVar16 = *(int *)(param_1 + 0x69) + 0xdU & 0xffff;
    iVar5 = regmap_bulk_read(param_1[1],uVar16,&local_6c,1);
    if (iVar5 < 0) goto LAB_00106ea4;
    uVar13 = 6000;
    if ((local_6c & 2) != 0) {
      uVar13 = 10000;
    }
    *(char *)(param_1 + 0x6e) = (char)((local_6c & 2) >> 1);
    *(undefined2 *)((long)param_1 + 0x366) = uVar13;
  }
  *(undefined4 *)((long)param_1 + 0x354) = 10000;
  iVar5 = haptics_set_vmax_mv(param_1,*(undefined4 *)((long)param_1 + 0x34));
  if (iVar5 < 0) goto LAB_00106f98;
  regmap_update_bits_base
            (param_1[1],*(int *)(param_1 + 0x69) + 0x49U & 0xffff,0x13,
             *(undefined1 *)(param_1 + 0xc),0,0,0);
  regmap_update_bits_base
            (param_1[1],*(int *)(param_1 + 0x69) + 0x50U & 0xffff,0xcf,
             (*(uint *)(param_1 + 4) & 3) << 6 | (*(uint *)(param_1 + 5) & 3) << 2 |
             *(uint *)((long)param_1 + 0x24) & 3,0,0,0);
  local_6c = local_6c & 0xffffff00;
  if (*(int *)(param_1 + 0x6d) != 3) goto LAB_00106dc4;
  if (param_1[0x4e] == 0) {
    uVar16 = *(int *)(param_1 + 0x69) + 0x80U & 0xffff;
    iVar5 = regmap_bulk_read(param_1[1],uVar16,&local_6c,1);
    if (-1 < iVar5) {
      *(char *)((long)param_1 + 0x362) = (char)(local_6c & 3);
      if ((*(int *)((long)param_1 + 0x33c) == 0) && ((local_6c & 3) == 1)) {
        uVar16 = *(int *)(param_1 + 0x69) + 0x84U & 0xffff;
        iVar5 = regmap_bulk_read(param_1[1],uVar16,&local_6c,1);
        if (iVar5 < 0) goto LAB_00106ea4;
        *(uint *)((long)param_1 + 0x33c) = (local_6c & 0xff) << 5;
      }
LAB_00106dc4:
      if ((param_1[0x4e] != 0) || (*(int *)(param_1 + 0x6d) == 3)) goto LAB_00106dd8;
      goto LAB_00106e00;
    }
LAB_00106ea4:
    uVar7 = *param_1;
    pcVar8 = "read addr %#x failed, rc=%d\n";
  }
  else {
LAB_00106dd8:
    regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 0x68U & 0xffff,1,1,0,0,0);
LAB_00106e00:
    if (*(char *)((long)param_1 + 100) != '\0') goto LAB_00106e08;
    regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 0x72U & 0xffff,0xc,4,0,0,0);
    iVar5 = *(int *)((long)param_1 + 0x3c);
    iVar6 = haptics_get_closeloop_lra_period(param_1,1);
    if ((iVar6 != 0) || (iVar10 = *(int *)(param_1 + 8), *(int *)(param_1 + 8) == 0)) {
      _dev_warn(*param_1,"get closeloop LRA period failed, rc=%d\n",iVar6);
      iVar10 = iVar5;
    }
    iVar5 = haptics_config_openloop_lra_period(param_1,iVar10);
    if (iVar5 < 0) goto LAB_00106f98;
    iVar5 = *(int *)((long)param_1 + 0x54);
    if (iVar5 != -0x16) {
      iVar6 = *(int *)(param_1 + 0x68);
      if (iVar6 == 0) {
        iVar10 = 0;
LAB_00106efc:
        if (iVar10 != iVar6) {
          puVar11 = (undefined8 *)(param_1[0xd] + (long)iVar10 * 0x30);
          iVar5 = haptics_set_pattern(param_1,*puVar11,*(undefined4 *)((long)puVar11 + 0x24));
          if (iVar5 < 0) goto LAB_00106f98;
          goto LAB_00106f24;
        }
      }
      else {
        iVar10 = 0;
        do {
          if (*(int *)(param_1[0xd] + (long)iVar10 * 0x30 + 0x18) == iVar5) goto LAB_00106efc;
          iVar10 = iVar10 + 1;
        } while (iVar6 != iVar10);
      }
      uVar7 = *param_1;
      pcVar8 = "preload effect %d is not found\n";
      goto LAB_00106ed0;
    }
LAB_00106f24:
    if (*(int *)(param_1 + 0x6d) != 4) {
LAB_00106e08:
      iVar5 = 0;
      goto LAB_00106f98;
    }
    param_1[0x1d] = 0x80000000800;
    *(undefined4 *)((long)param_1 + 0xf4) = 0x580;
    *(undefined4 *)(param_1 + 0x20) = 0x580;
    *(undefined1 *)(param_1 + 0x1e) = 1;
    *(undefined4 *)((long)param_1 + 0x10c) = 0x3e0;
    *(undefined4 *)(param_1 + 0x23) = 0x3e0;
    *(undefined4 *)((long)param_1 + 0x124) = 0xe;
    if (*(int *)(param_1 + 0x68) == 0) {
      uVar9 = 0;
    }
    else {
      uVar16 = 0;
      do {
        plVar17 = (long *)(param_1[0xd] + (long)(int)uVar16 * 0x30 + 8);
        lVar14 = *plVar17;
        if ((lVar14 != 0) && (*(char *)(lVar14 + 0x14) != '\0')) {
          if (*(int *)((long)param_1 + 0x124) == 0xe) {
            *(int *)((long)param_1 + 0x124) = *(int *)(lVar14 + 0xc);
            lVar14 = *plVar17;
LAB_00107040:
            uVar15 = *(int *)(lVar14 + 8) + 0x1fU & 0xffffffe0;
            uVar3 = *(int *)((long)param_1 + 0xec) - uVar15;
            if (uVar3 < 0x280) {
              uVar7 = *param_1;
              pcVar8 = "not enough space for preload FIFO effect\n";
              goto LAB_001070f0;
            }
            if ((*(char *)(param_1 + 0x24) == '\0') && (uVar15 <= *(uint *)(param_1 + 0x23))) {
              lVar14 = 3;
LAB_00106fd8:
              *(uint *)((long)param_1 + 0xec) = uVar3;
              lVar12 = param_1[0xd] + (long)(int)uVar16 * 0x30;
              *(undefined1 *)((long)param_1 + lVar14 * 0xc + 0xfc) = 1;
              *(uint *)((long)param_1 + lVar14 * 0xc + 0xf8) = uVar15;
              *(undefined4 *)(lVar12 + 0x24) = 5;
              *(int *)(lVar12 + 0x28) = (int)lVar14;
              goto LAB_00106ff0;
            }
            if ((*(char *)((long)param_1 + 0x114) == '\0') &&
               (uVar15 <= *(uint *)((long)param_1 + 0x10c))) {
              lVar14 = 2;
              goto LAB_00106fd8;
            }
            if ((*(char *)(param_1 + 0x21) == '\0') && (uVar15 <= *(uint *)(param_1 + 0x20))) {
              lVar14 = 1;
              goto LAB_00106fd8;
            }
            if ((*(char *)((long)param_1 + 0xfc) == '\0') &&
               (uVar15 <= *(uint *)((long)param_1 + 0xf4))) {
              lVar14 = 0;
              goto LAB_00106fd8;
            }
            _dev_warn(*param_1,"no PAT_MEM source available\n");
            *(undefined1 *)(*plVar17 + 0x14) = 0;
          }
          else {
            if (*(int *)((long)param_1 + 0x124) == *(int *)(lVar14 + 0xc)) goto LAB_00107040;
            uVar7 = *param_1;
            pcVar8 = "PATx_MEM sources only support one play rate\n";
LAB_001070f0:
            _dev_warn(uVar7,pcVar8);
          }
          *(undefined1 *)(*plVar17 + 0x14) = 0;
        }
LAB_00106ff0:
        uVar16 = uVar16 + 1;
      } while (uVar16 < *(uint *)(param_1 + 0x68));
      uVar16 = *(uint *)((long)param_1 + 0xec);
      local_6c = 0;
      uVar15 = uVar16 & 0x7f;
      if ((uVar16 & 0x7f) != 0) {
        uVar16 = uVar16 & 0xffffff80;
        *(uint *)((long)param_1 + 0xec) = uVar16;
        *(uint *)(param_1 + 0x1f) = *(int *)(param_1 + 0x1f) + uVar15;
      }
      uVar9 = (ulong)uVar16;
      if ((uVar16 & 0x7f80) == 0) {
        _dev_err(*param_1,"fifo length %d is less than %d\n",uVar9,0x80);
        iVar5 = -0x16;
        goto LAB_00106f98;
      }
    }
    uVar16 = *(int *)((long)param_1 + 0x34c) + 0xa0U & 0xffff;
    local_6c = (uint)((char)(uVar9 >> 7) - 1U & 0xf | 0x80);
    iVar5 = regmap_bulk_write(param_1[1],uVar16,&local_6c,1);
    if (-1 < iVar5) {
      uVar15 = *(uint *)(param_1 + 0x1f);
      if (*(uint *)((long)param_1 + 0xf4) <= *(uint *)(param_1 + 0x1f)) {
        uVar15 = *(uint *)((long)param_1 + 0xf4);
      }
      uVar3 = *(uint *)((long)param_1 + 0x104);
      if (*(uint *)(param_1 + 0x20) <= *(uint *)((long)param_1 + 0x104)) {
        uVar3 = *(uint *)(param_1 + 0x20);
      }
      uVar1 = *(uint *)(param_1 + 0x22);
      if (*(uint *)((long)param_1 + 0x10c) <= *(uint *)(param_1 + 0x22)) {
        uVar1 = *(uint *)((long)param_1 + 0x10c);
      }
      uVar2 = *(uint *)((long)param_1 + 0x11c);
      if (*(uint *)(param_1 + 0x23) <= *(uint *)((long)param_1 + 0x11c)) {
        uVar2 = *(uint *)(param_1 + 0x23);
      }
      uVar16 = *(int *)((long)param_1 + 0x34c) + 0xa1U & 0xffff;
      local_6c = CONCAT13((char)(uVar2 >> 5),
                          CONCAT12((char)(uVar1 >> 5),
                                   CONCAT11((char)(uVar3 >> 5),(char)(uVar15 >> 5))));
      iVar5 = regmap_bulk_write(param_1[1],uVar16,&local_6c,4);
      if (-1 < iVar5) {
        regmap_update_bits_base
                  (param_1[1],*(int *)((long)param_1 + 0x34c) + 0x24U & 0xffff,0xf0,
                   (*(uint *)((long)param_1 + 0x124) & 0xf) << 4,0,0,0);
        uVar16 = *(uint *)(param_1 + 0x68);
        if (uVar16 != 0) {
          uVar15 = 0;
          do {
            lVar14 = param_1[0xd];
            plVar17 = *(long **)(lVar14 + (long)(int)uVar15 * 0x30 + 8);
            if ((plVar17 == (long *)0x0) || (*(char *)((long)plVar17 + 0x14) == '\0'))
            goto LAB_00107264;
            if (*(int *)(lVar14 + (long)(int)uVar15 * 0x30 + 0x24) != 5) {
              uVar7 = *param_1;
              pcVar8 = "effect %d pattern_src is not PATTERN_MEM\n";
              iVar5 = *(int *)(lVar14 + (long)(int)uVar15 * 0x30 + 0x18);
              goto LAB_00106ed0;
            }
            lVar12 = *plVar17;
            if (lVar12 == 0) {
              _dev_err(*param_1,"no data available to update PAT_MEM\n");
              iVar5 = -0x16;
              break;
            }
            if (*(int *)(param_1 + 0x6d) == 4) {
              lVar4 = plVar17[1];
              uVar16 = *(int *)((long)param_1 + 0x34c) + 0x2dU & 0xffff;
              local_6c = CONCAT31(local_6c._1_3_,
                                  (char)((*(uint *)(lVar14 + (long)(int)uVar15 * 0x30 + 0x28) & 3)
                                        << 4)) | 0x81;
              iVar5 = regmap_bulk_write(param_1[1],uVar16,&local_6c,1);
              if (-1 < iVar5) {
                uVar16 = *(int *)((long)param_1 + 0x34c) + 0x2dU & 0xffff;
                local_6c = local_6c & 0xfffffffe;
                iVar5 = regmap_bulk_write(param_1[1],uVar16,&local_6c,1);
                if (-1 < iVar5) {
                  iVar5 = haptics_update_memory_data(param_1,lVar12,(int)lVar4);
                  regmap_update_bits_base
                            (param_1[1],*(int *)((long)param_1 + 0x34c) + 0x2dU & 0xffff,0x80,0,0,0,
                             0);
                  if (-1 < iVar5) {
                    uVar16 = *(uint *)(param_1 + 0x68);
                    goto LAB_00107264;
                  }
                  break;
                }
              }
              uVar7 = *param_1;
              pcVar8 = "write addr %#x failed, rc=%d\n";
              goto LAB_00106eb8;
            }
LAB_00107264:
            iVar5 = 0;
            uVar15 = uVar15 + 1;
          } while (uVar15 < uVar16);
          goto LAB_00106f98;
        }
        goto LAB_00106e08;
      }
    }
    uVar7 = *param_1;
    pcVar8 = "write addr %#x failed, rc=%d\n";
  }
LAB_00106eb8:
  _dev_err(uVar7,pcVar8,uVar16,iVar5);
LAB_00106f98:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// fifo_empty_irq_handler @ 001073dc size=1232
// signature: undefined fifo_empty_irq_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fifo_empty_irq_handler(undefined8 param_1,undefined8 *param_2)

{
  void *__src;
  uint uVar1;
  char cVar2;
  uint uVar3;
  short sVar4;
  long lVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  char *pcVar10;
  short sVar11;
  long *plVar12;
  undefined8 uVar13;
  short sVar14;
  uint local_60;
  byte local_5c [4];
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_5c[0] = 0;
  local_60 = 0;
  uVar9 = *(int *)(param_2 + 0x69) + 0x10U & 0xffff;
  iVar7 = regmap_bulk_read(param_2[1],uVar9,local_5c,1);
  if (iVar7 < 0) {
    _dev_err(*param_2,"read addr %#x failed, rc=%d\n",uVar9,iVar7);
    goto LAB_001075bc;
  }
  if ((local_5c[0] >> 1 & 1) == 0) {
    haptics_get_fifo_fill_status(param_2,&local_60);
    if ((*(int *)((long)param_2 + 0x3f4) != 0) && (local_60 < 0x18)) {
      queue_work_on(0x20,_system_wq,param_2 + 0x78);
    }
    goto LAB_001075bc;
  }
  mutex_lock(param_2 + 0x14);
  if (*(int *)((long)param_2 + 0x94) == 1) {
    iVar8 = haptics_get_available_fifo_memory(param_2);
    iVar7 = *(int *)(param_2 + 0x6d);
    if (iVar7 == 2) {
      if (iVar8 == 0x280) goto LAB_0010759c;
    }
    else if (iVar7 == 4) {
      iVar7 = 0x280;
      if (*(int *)((long)param_2 + 0xec) != 0) {
        iVar7 = *(int *)((long)param_2 + 0xec);
      }
      if (iVar8 == iVar7) goto LAB_0010759c;
    }
    else if (iVar7 == 3) {
      if (iVar8 == 0x400) goto LAB_0010759c;
    }
    else {
      _printk(&DAT_00111ba3);
      if (iVar8 == 0) {
LAB_0010759c:
        if (*(int *)((long)param_2 + 0x3f4) != 0) {
          *(undefined4 *)((long)param_2 + 0x3f4) = 0;
        }
        iVar7 = haptics_stop_fifo_play(param_2);
        if (-1 < iVar7) {
          _dev_info(*param_2,"FIFO playing is done\n");
        }
        goto LAB_001075b4;
      }
    }
    uVar13 = *param_2;
    iVar7 = get_max_fifo_samples(param_2);
    _dev_info(uVar13,"%d FIFO samples still in playing\n",iVar7 - iVar8);
  }
  else if (*(int *)((long)param_2 + 0x9c) != 1) {
    if (*(int *)((long)param_2 + 0x3f4) == 0) {
      if (param_2[0x10] != 0) {
        plVar12 = *(long **)(param_2[0x10] + 8);
        if ((plVar12 == (long *)0x0) || (*plVar12 == 0)) {
          _dev_err(*param_2,"no FIFO samples available\n");
        }
        else {
          lVar5 = plVar12[1];
          iVar7 = *(int *)(param_2 + 0x12);
          uVar9 = haptics_get_available_fifo_memory(param_2);
          if (-1 < (int)uVar9) {
            uVar3 = (int)lVar5 - iVar7;
            uVar1 = uVar9 & 0xfffffffc;
            if (uVar3 <= uVar9) {
              uVar1 = uVar3;
            }
            if (*plVar12 + (ulong)*(uint *)(param_2 + 0x12) == 0) {
              _dev_err(*param_2,"no data available to update FIFO\n");
              iVar7 = -0x16;
            }
            else {
              iVar7 = haptics_update_memory_data
                                (param_2,*plVar12 + (ulong)*(uint *)(param_2 + 0x12),uVar1);
              if (-1 < iVar7) {
                *(uint *)(param_2 + 0x12) = *(int *)(param_2 + 0x12) + uVar1;
                if (*(int *)(param_2 + 0x12) == (int)plVar12[1]) {
                  *(undefined4 *)((long)param_2 + 0x94) = 1;
                  haptics_set_fifo_empty_threshold(param_2,0);
                }
                goto LAB_001075b4;
              }
            }
            _dev_err(*param_2,"Update FIFO samples failed, rc=%d\n",iVar7);
          }
        }
      }
    }
    else {
      uVar6 = haptics_get_available_fifo_memory(param_2);
      iVar7 = (int)(short)uVar6;
      iVar8 = get_max_fifo_samples(param_2);
      if (iVar7 == iVar8) {
        _dev_info(*param_2,"aac richtap fifo stopped, wait next vibrator %d\n",iVar7);
      }
      else {
        if ((int)((uint)uVar6 << 0x10) < 0) {
          uVar13 = *param_2;
          pcVar10 = "get fifo error, num_rt = %d\n";
        }
        else {
          sVar11 = 0;
          uVar6 = uVar6 & 0xfffc;
          sVar14 = 3;
LAB_00107720:
          cVar2 = *(char *)param_2[0x71];
          if (cVar2 != 'U') {
            if (cVar2 == -0x56) goto LAB_00107818;
            if (sVar14 < 1) {
              _dev_err(*param_2,"invalid data\n");
              goto LAB_00107818;
            }
            sVar14 = sVar14 + -1;
            usleep_range_state(1000,0x3e9,2);
LAB_001077c0:
            if (((short)uVar6 < 1) || (*(int *)((long)param_2 + 0x3f4) == 0)) goto LAB_00107818;
            goto LAB_00107720;
          }
          uVar9 = (int)*(short *)((char *)param_2[0x71] + 2) - (int)*(short *)(param_2 + 0x7e);
          if ((uVar9 >> 0xf & 1) != 0) {
            _dev_err(*param_2,"aac richtap length error, pos = %d, length = %d\n");
            goto LAB_001076c8;
          }
          sVar4 = (short)uVar9;
          __src = (void *)(param_2[0x71] + (long)*(short *)(param_2 + 0x7e) + 0x18);
          if (sVar4 <= (short)uVar6) {
            memcpy((void *)(param_2[0x6f] + (long)sVar11),__src,(long)sVar4 & 0xffffffff);
            sVar11 = sVar4 + sVar11;
            uVar6 = uVar6 - sVar4;
            *(undefined1 *)param_2[0x71] = 0xff;
            *(undefined2 *)(param_2[0x71] + 2) = 0;
            uVar13 = *(undefined8 *)(param_2[0x71] + 8);
            *(undefined2 *)(param_2 + 0x7e) = 0;
            param_2[0x71] = uVar13;
            goto LAB_001077c0;
          }
          memcpy((void *)(param_2[0x6f] + (long)sVar11),__src,(long)(short)uVar6);
          sVar11 = uVar6 + sVar11;
          *(ushort *)(param_2 + 0x7e) = *(short *)(param_2 + 0x7e) + uVar6;
LAB_00107818:
          _dev_info(*param_2,"update fifo len %d\n",(int)sVar11);
          if ((sVar11 == 0) ||
             (iVar7 = haptics_update_fifo_samples(param_2,param_2[0x6f],(int)sVar11,1), -1 < iVar7))
          {
            if ((*(char *)param_2[0x71] != 'U') && (*(char *)(param_2 + 0x7f) != '\0')) {
              *(undefined1 *)(param_2 + 0x7f) = 0;
              queue_work_on(0x20,_system_wq,param_2 + 0x78);
              _dev_info(*param_2,"richtap stream mode is done\n");
            }
            goto LAB_001075b4;
          }
          uVar13 = *param_2;
          pcVar10 = "richtap Update FIFO fail, rc=%d\n";
        }
        _dev_err(uVar13,pcVar10,iVar7);
LAB_001076c8:
        queue_work_on(0x20,_system_wq,param_2 + 0x78);
      }
    }
  }
LAB_001075b4:
  mutex_unlock(param_2 + 0x14);
LAB_001075bc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// haptics_disable_hbst_timer @ 00107950 size=80
// signature: undefined haptics_disable_hbst_timer(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_disable_hbst_timer(long param_1)

{
  int iVar1;
  
  iVar1 = haptics_boost_vreg_enable((undefined8 *)(param_1 + -0x278),0);
  if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x278),"disable boost vreg failed, rc=%d\n",iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// haptics_stop_constant_effect_play @ 001079a4 size=192
// signature: undefined haptics_stop_constant_effect_play(void)
// callers: []
//------------------------------------------------------------

void haptics_stop_constant_effect_play(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  
  puVar5 = (undefined8 *)(param_1 + -0x130);
  iVar1 = haptics_enable_play(puVar5,0);
  if (iVar1 < 0) {
    _dev_err(*puVar5,"stop constant effect play failed\n");
    lVar2 = *(long *)(param_1 + 0x140);
  }
  else {
    lVar2 = *(long *)(param_1 + 0x140);
  }
  if ((lVar2 != 0) && (*(char *)(param_1 + 0x23f) != '\0')) {
    iVar1 = regulator_disable();
    if (iVar1 < 0) {
      uVar3 = *puVar5;
      pcVar4 = "Disable hpwr failed, rc=%d\n";
    }
    else {
      iVar1 = regulator_set_voltage(*(undefined8 *)(param_1 + 0x140),0,0x7fffffff);
      if (-1 < iVar1) {
        *(undefined1 *)(param_1 + 0x23f) = 0;
        return;
      }
      uVar3 = *puVar5;
      pcVar4 = "Set hpwr voltage failed, rc=%d\n";
    }
    _dev_err(uVar3,pcVar4,iVar1);
    _dev_err(*puVar5,"disable hpwr_vreg failed\n");
  }
  return;
}



//------------------------------------------------------------
// haptics_set_gain_work @ 00107a68 size=368
// signature: undefined haptics_set_gain_work(void)
// callers: []
//------------------------------------------------------------

void haptics_set_gain_work(long param_1)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  undefined8 *puVar7;
  undefined1 local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  puVar7 = (undefined8 *)(param_1 + -0x308);
  mutex_lock(param_1 + -0x268);
  uVar3 = *(uint *)(param_1 + -0x238);
  if (*(int *)(param_1 + -0x22c) == 1) {
    uVar5 = get_direct_play_max_amplitude(puVar7);
    uVar1 = *(int *)(param_1 + 0x44) + 0x26U & 0xffff;
    local_3c[0] = (undefined1)((ulong)((uVar3 & 0xffff) * (uVar5 & 0xff)) / 0x7fff);
    iVar6 = regmap_bulk_write(*(undefined8 *)(param_1 + -0x300),uVar1,local_3c,1);
    if (iVar6 < 0) {
      _dev_err(*puVar7,"write addr %#x failed, rc=%d\n",uVar1,iVar6);
      _dev_err(*puVar7,"config DIRECT_PLAY failed, rc=%d\n",iVar6);
    }
  }
  else {
    puVar2 = (uint *)(param_1 + -0x2d4);
    if (*(long *)(param_1 + -0x288) != 0) {
      puVar2 = (uint *)(*(long *)(param_1 + -0x288) + 0x1c);
    }
    uVar1 = 5000;
    if (*puVar2 < 0x1389 || *(char *)(param_1 + 0x66) == '\0') {
      uVar1 = *puVar2;
    }
    *(uint *)(param_1 + -0x234) = (uVar1 * (uVar3 & 0xffff)) / 0x7fff;
    haptics_set_vmax_mv(puVar7);
  }
  mutex_unlock(param_1 + -0x268);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// haptics_upload_effect @ 00107bdc size=3596
// signature: undefined haptics_upload_effect(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int haptics_upload_effect(long param_1,short *param_2)

{
  undefined8 *puVar1;
  short sVar2;
  short sVar3;
  undefined8 *puVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  uint uVar15;
  ulong uVar16;
  int iVar17;
  uint *puVar18;
  undefined8 *puVar19;
  undefined4 uVar20;
  long *plVar21;
  undefined8 local_80;
  undefined8 local_78;
  ulong local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  puVar19 = *(undefined8 **)(param_1 + 0x2d8);
  if (*param_2 == 0x51) {
    if (param_2[8] != 0x5d) {
      _dev_err(*puVar19,"Only support custom waveforms\n");
      iVar7 = -0x16;
      goto LAB_00108920;
    }
    if (*(int *)(param_2 + 0x12) != 6) {
      if (*(int *)(param_2 + 0x12) != 0x18) goto LAB_0010872c;
      uVar12 = *(ulong *)(param_2 + 0x14);
      local_78 = 0;
      local_70 = 0;
      local_80 = 0;
      sVar2 = param_2[10];
      if ((puVar19[0xf] == 0) || (plVar21 = *(long **)(puVar19[0xf] + 8), plVar21 == (long *)0x0)) {
        iVar7 = -0xc;
      }
      else {
        puVar4 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
           (uVar16 = uVar12, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
          uVar16 = uVar12 & (long)(uVar12 << 8) >> 8;
        }
        if (uVar16 < 0x7fffffffe9) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar16 = daif;
            if ((uVar16 & 0x80) == 0) {
              uVar14 = daif;
              daif = uVar14 | 0xc0;
            }
            uVar14 = ttbr1_el1;
            ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar4[1];
            InstructionSynchronizationBarrier();
            daif = uVar16;
          }
          lVar9 = __arch_copy_from_user(&local_80,uVar12 & 0xff7fffffffffffff,0x18);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar12 = daif;
            if ((uVar12 & 0x80) == 0) {
              uVar16 = daif;
              daif = uVar16 | 0xc0;
            }
            uVar16 = ttbr1_el1;
            ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar16 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar12;
          }
          if (lVar9 == 0) {
            uVar6 = *(uint *)((long)puVar19 + 0x3c);
            if (uVar6 - 0x30d41 < 0xfffcf2c0) {
LAB_001088f8:
              _dev_err(*puVar19,"Can\'t support play rate: %d Hz\n");
              iVar7 = -0x16;
              goto LAB_0010890c;
            }
            if ((int)(uint)local_78 < 32000) {
              if ((uint)local_78 == 8000) {
                uVar20 = 8;
              }
              else if ((uint)local_78 == 16000) {
                uVar20 = 9;
              }
              else {
                if ((uint)local_78 != 24000) goto LAB_001083b0;
                uVar20 = 10;
              }
            }
            else if ((uint)local_78 == 32000) {
              uVar20 = 0xb;
            }
            else if ((uint)local_78 == 0xac44) {
              uVar20 = 0xc;
            }
            else if ((uint)local_78 == 48000) {
              uVar20 = 0xd;
            }
            else {
LAB_001083b0:
              uVar15 = 0;
              if (uVar6 != 0) {
                uVar15 = 1000000 / uVar6;
              }
              uVar6 = uVar15 - 5;
              uVar15 = uVar15 + 5;
              if (((uVar15 < uVar6) || ((uint)local_78 < uVar6)) || (uVar15 < (uint)local_78)) {
                if (uVar15 < uVar6) goto LAB_001088f8;
                if (((uint)local_78 >> 1 < uVar6) || (uVar15 < (uint)local_78 >> 1)) {
                  if (((uint)local_78 >> 2 < uVar6) || (uVar15 < (uint)local_78 >> 2)) {
                    if (((uint)local_78 >> 3 < uVar6) || (uVar15 < (uint)local_78 >> 3)) {
                      if (((uint)local_78 * 2 < uVar6) || (uVar15 < (uint)local_78 * 2)) {
                        if (((uint)local_78 * 4 < uVar6) || (uVar15 < (uint)local_78 * 4)) {
                          if (((uint)local_78 * 8 < uVar6) || (uVar15 < (uint)local_78 * 8))
                          goto LAB_001088f8;
                          uVar20 = 6;
                        }
                        else {
                          uVar20 = 5;
                        }
                      }
                      else {
                        uVar20 = 4;
                      }
                    }
                    else {
                      uVar20 = 3;
                    }
                  }
                  else {
                    uVar20 = 2;
                  }
                }
                else {
                  uVar20 = 1;
                }
              }
              else {
                uVar20 = 0;
              }
            }
            mutex_lock(puVar19 + 0x14);
            *(undefined4 *)((long)plVar21 + 0xc) = uVar20;
            kvfree(*plVar21);
            lVar9 = __kmalloc(local_80._4_4_,0xdc0);
            *plVar21 = lVar9;
            if (lVar9 == 0) {
              lVar9 = vmalloc(local_80._4_4_);
              *plVar21 = lVar9;
              if (lVar9 != 0) goto LAB_00108434;
              iVar7 = -0xc;
            }
            else {
LAB_00108434:
              uVar16 = local_70;
              uVar12 = local_80 >> 0x20;
              if ((long)local_80 < 0) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10896c);
                (*pcVar5)();
              }
              __check_object_size(lVar9,uVar12,0);
              if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
                 (uVar14 = uVar16, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
                uVar14 = uVar16 & (long)(uVar16 << 8) >> 8;
              }
              uVar10 = uVar12;
              if (uVar14 <= 0x8000000000 - uVar12) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar14 = daif;
                  if ((uVar14 & 0x80) == 0) {
                    uVar10 = daif;
                    daif = uVar10 | 0xc0;
                  }
                  uVar10 = ttbr1_el1;
                  ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar10 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar4[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar14;
                }
                uVar10 = __arch_copy_from_user(lVar9,uVar16 & 0xff7fffffffffffff,uVar12);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar16 = daif;
                  if ((uVar16 & 0x80) == 0) {
                    uVar14 = daif;
                    daif = uVar14 | 0xc0;
                  }
                  uVar14 = ttbr1_el1;
                  ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar14 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar16;
                }
              }
              if (uVar10 == 0) {
                *(int *)(plVar21 + 1) = local_80._4_4_;
                iVar7 = local_80._4_4_ + -1;
                if (-1 < iVar7) {
                  iVar7 = 0;
                }
                iVar17 = local_80._4_4_ + 1;
                do {
                  uVar6 = iVar17 - 2;
                  if ((int)uVar6 < 1) {
                    iVar17 = iVar7 + 1;
                    break;
                  }
                  iVar17 = iVar17 + -1;
                } while (*(char *)(*plVar21 + (ulong)uVar6) == '\0');
                if (*(uint *)((long)plVar21 + 0xc) < 0xe) {
                  uVar6 = iVar17 * *(int *)(puVar19[0xf] + 0x20);
                  switch(*(uint *)((long)plVar21 + 0xc)) {
                  case 0:
                    break;
                  case 1:
                    uVar6 = uVar6 >> 1;
                    break;
                  case 2:
                    uVar6 = uVar6 >> 2;
                    break;
                  case 3:
                    uVar6 = uVar6 >> 3;
                    break;
                  default:
                    goto switchD_00108588_caseD_4;
                  case 8:
                    uVar6 = (uint)(local_80._4_4_ * 1000) >> 3;
                    break;
                  case 9:
                    uVar6 = (uint)(local_80._4_4_ * 1000) >> 4;
                    break;
                  case 10:
                    uVar6 = (uint)(local_80._4_4_ * 1000) / 0x18;
                    break;
                  case 0xb:
                    uVar6 = (uint)(local_80._4_4_ * 1000) >> 5;
                    break;
                  case 0xc:
                    uVar6 = (uint)(local_80._4_4_ * 10000) / 0x1b9;
                    break;
                  case 0xd:
                    uVar6 = (uint)(local_80._4_4_ * 1000) / 0x30;
                  }
                }
                else {
switchD_00108588_caseD_4:
                  uVar6 = 0xffffffea;
                }
                *(uint *)(plVar21 + 2) = uVar6;
                if (*(char *)(puVar19 + 0x1c) == '\0') {
                  puVar19[0x10] = puVar19[0xf];
                  puVar19[0x11] = 0;
                  *(uint *)((long)puVar19 + 0xd4) =
                       (uint)(*(int *)(puVar19[0xf] + 0x1c) * (int)sVar2) / 0x7fff;
                  iVar7 = haptics_set_vmax_mv(puVar19);
                  if ((-1 < iVar7) &&
                     (((*(byte *)(puVar19 + 0x6b) >> 3 & 1) == 0 ||
                      (iVar7 = haptics_toggle_module_enable(puVar19), -1 < iVar7)))) {
                    regmap_update_bits_base
                              (puVar19[1],*(int *)(puVar19 + 0x69) + 99U & 0xffff,0x80,
                               (ulong)(*(char *)(puVar19[0x10] + 0x2c) == '\0') << 7,0,0,0);
                    *(undefined4 *)((long)puVar19 + 0xdc) = 0;
                    iVar7 = haptics_set_fifo(puVar19,*(undefined8 *)(puVar19[0x10] + 8));
                    if (-1 < iVar7) goto LAB_00108724;
                  }
                }
                else {
                  _dev_err(*puVar19,"calibration in progress, ignore playing custom effect\n");
                  iVar7 = -0x10;
                }
              }
              else {
                memset((void *)(lVar9 + (uVar12 - uVar10)),0,uVar10);
                iVar7 = -0xe;
              }
              kvfree(*plVar21);
              *plVar21 = 0;
            }
            mutex_unlock(puVar19 + 0x14);
            goto LAB_0010890c;
          }
        }
        iVar7 = -0xe;
      }
LAB_0010890c:
      uVar8 = *puVar19;
      pcVar11 = "Upload custom FIFO data failed rc=%d\n";
      goto LAB_00108918;
    }
    uVar16 = *(ulong *)(param_2 + 0x14);
    puVar4 = (undefined8 *)sp_el0;
    sVar2 = param_2[10];
    local_80 = local_80 & 0xffff000000000000;
    uVar12 = (long)(uVar16 << 8) >> 8;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar14 = uVar16, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar14 = uVar16 & uVar12;
    }
    if (uVar14 < 0x7ffffffffb) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        uVar10 = ttbr1_el1;
        ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4[1];
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      lVar9 = __arch_copy_from_user(&local_80,uVar16 & 0xff7fffffffffffff,6);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar14 = daif;
        if ((uVar14 & 0x80) == 0) {
          uVar10 = daif;
          daif = uVar10 | 0xc0;
        }
        uVar10 = ttbr1_el1;
        ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar10 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar14;
      }
      if (lVar9 != 0) goto LAB_00108320;
      if ((short)local_80 < 0) {
        uVar6 = *(uint *)((long)puVar19 + 0x344);
        if (uVar6 == 0) goto LAB_001087f0;
        uVar15 = (int)(short)local_80 & 0x7fff;
        plVar21 = puVar19 + 0xe;
LAB_0010800c:
        lVar9 = *plVar21;
        if ((int)uVar6 < 1) {
          uVar14 = 0;
LAB_0010804c:
          if ((uint)uVar14 != uVar6) {
            puVar1 = puVar19 + 0x14;
            mutex_lock(puVar1);
            if (*(char *)(puVar19 + 0x1c) == '\0') {
              lVar13 = lVar9 + (uVar14 & 0xffffffff) * 0x30;
              *(uint *)((long)puVar19 + 0xd4) =
                   (uint)(*(int *)(lVar13 + 0x1c) * (int)sVar2) / 0x7fff;
              if (lVar13 == 0) {
LAB_001080dc:
                iVar7 = -0x16;
              }
              else {
                puVar19[0x10] = lVar13;
                iVar7 = haptics_set_vmax_mv(puVar19);
                if (-1 < iVar7) {
                  lVar13 = puVar19[0x10];
                  iVar7 = *(int *)(lVar13 + 0x24);
                  *(int *)((long)puVar19 + 0xdc) = iVar7;
                  if (iVar7 == 0) {
                    if ((*(byte *)(puVar19 + 0x6b) >> 3 & 1) != 0) {
                      iVar7 = haptics_toggle_module_enable(puVar19);
                      if (iVar7 < 0) goto LAB_001085a0;
                      lVar13 = puVar19[0x10];
                    }
LAB_001080fc:
                    regmap_update_bits_base
                              (puVar19[1],*(int *)(puVar19 + 0x69) + 99U & 0xffff,0x80,
                               (ulong)(*(char *)(lVar13 + 0x2c) == '\0') << 7,0,0,0);
                    lVar13 = *(long *)(puVar19[0x10] + 0x10);
                    puVar19[0x11] = lVar13;
                    if ((lVar13 != 0) && (iVar7 = haptics_set_brake(puVar19), iVar7 < 0))
                    goto LAB_001085a0;
                    uVar6 = *(uint *)((long)puVar19 + 0xdc);
                    if ((uVar6 & 0xfffffffe) == 2) {
                      if (*(char *)(*(long *)puVar19[0x10] + 0x68) == '\0') {
                        iVar7 = haptics_set_pattern(puVar19);
                        if (iVar7 < 0) goto LAB_001085a0;
                        uVar6 = *(uint *)((long)puVar19 + 0xdc);
                        goto LAB_0010817c;
                      }
                    }
                    else {
LAB_0010817c:
                      if ((uVar6 == 0) &&
                         (iVar7 = haptics_set_fifo(puVar19,*(undefined8 *)(puVar19[0x10] + 8)),
                         iVar7 < 0)) goto LAB_001085a0;
                      if ((*(int *)(puVar19 + 0x6d) == 4) && (*(int *)((long)puVar19 + 0xdc) == 5))
                      {
                        if (*(char *)(*(long *)(puVar19[0x10] + 8) + 0x14) == '\0') {
                          uVar8 = *puVar19;
                          pcVar11 = "effect %d has PAT_MEM src but not preloaded\n";
                          iVar7 = *(int *)(puVar19[0x10] + 0x18);
                          goto LAB_001080d8;
                        }
                        regmap_update_bits_base
                                  (puVar19[1],*(int *)(puVar19 + 0x69) + 99U & 0xffff,0x80,0,0,0,0);
                      }
                    }
                    mutex_unlock(puVar1);
                    uVar14 = local_80;
                    plVar21 = (long *)puVar19[0x10];
                    uVar6 = 0;
                    if (plVar21[2] != 0) {
                      uVar6 = *(uint *)(plVar21[2] + 0x14);
                    }
                    if ((*(uint *)((long)plVar21 + 0x24) & 0xfffffffe) == 2) {
                      if (*plVar21 != 0) {
                        iVar7 = *(int *)(*plVar21 + 100);
                        goto LAB_0010822c;
                      }
                    }
                    else if ((*(uint *)((long)plVar21 + 0x24) == 0) && (plVar21[1] != 0)) {
                      iVar7 = *(int *)(plVar21[1] + 0x10);
LAB_0010822c:
                      uVar6 = iVar7 + uVar6;
                    }
                    *(uint *)(puVar19 + 0x1b) = uVar6;
                    local_80._6_2_ = SUB82(uVar14,6);
                    local_80._0_6_ =
                         CONCAT24((short)((ulong)(uVar6 % 1000000) / 1000),
                                  CONCAT22((short)(uVar6 / 1000000),(short)local_80));
                    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
                       (uVar14 = uVar16, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
                      uVar14 = uVar16 & uVar12;
                    }
                    if (uVar14 < 0x7ffffffffb) {
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar12 = daif;
                        if ((uVar12 & 0x80) == 0) {
                          uVar14 = daif;
                          daif = uVar14 | 0xc0;
                        }
                        uVar14 = ttbr1_el1;
                        ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        ttbr0_el1 = puVar4[1];
                        InstructionSynchronizationBarrier();
                        daif = uVar12;
                      }
                      lVar9 = __arch_copy_to_user(uVar16 & 0xff7fffffffffffff,&local_80,6);
                      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                        uVar12 = daif;
                        if ((uVar12 & 0x80) == 0) {
                          uVar16 = daif;
                          daif = uVar16 | 0xc0;
                        }
                        uVar16 = ttbr1_el1;
                        ttbr0_el1 = (uVar16 & 0xffffffffffff) - 0x1000;
                        InstructionSynchronizationBarrier();
                        ttbr1_el1 = uVar16 & 0xffffffffffff;
                        InstructionSynchronizationBarrier();
                        daif = uVar12;
                      }
                      if (lVar9 == 0) goto LAB_0010872c;
                    }
                    goto LAB_00108320;
                  }
                  if ((iVar7 != 4) && (iVar7 != 1)) goto LAB_001080fc;
                  uVar8 = *puVar19;
                  pcVar11 = "pattern src %d can\'t be used for predefined effect\n";
LAB_001080d8:
                  _dev_err(uVar8,pcVar11,iVar7);
                  goto LAB_001080dc;
                }
              }
LAB_001085a0:
              _dev_err(*puVar19,"Play predefined effect%d failed, rc=%d\n",
                       *(undefined4 *)(lVar9 + (uVar14 & 0xffffffff) * 0x30 + 0x18),iVar7);
            }
            else {
              _dev_err(*puVar19,"calibration in progress, ignore playing predefined effect\n");
              iVar7 = -0x10;
            }
            mutex_unlock(puVar1);
            goto LAB_00108814;
          }
        }
        else {
          uVar14 = 0;
          puVar18 = (uint *)(lVar9 + 0x18);
          do {
            if (*puVar18 == (uVar15 & 0xffff)) goto LAB_0010804c;
            uVar14 = uVar14 + 1;
            puVar18 = puVar18 + 0xc;
          } while (uVar6 != uVar14);
        }
        _dev_err(*puVar19,"effect%d is not supported!\n");
        iVar7 = -0x16;
      }
      else {
        uVar6 = *(uint *)(puVar19 + 0x68);
        if (uVar6 != 0) {
          plVar21 = puVar19 + 0xd;
          uVar15 = (uint)(short)local_80;
          goto LAB_0010800c;
        }
LAB_001087f0:
        iVar7 = -0x16;
      }
    }
    else {
LAB_00108320:
      iVar7 = -0xe;
    }
LAB_00108814:
    uVar8 = *puVar19;
    pcVar11 = "Upload periodic effect failed rc=%d\n";
  }
  else {
    if (*param_2 != 0x52) {
      _dev_err(*puVar19,"%d effect is not supported\n");
      iVar7 = -0x16;
      goto LAB_00108920;
    }
    sVar2 = param_2[5];
    sVar3 = param_2[8];
    uVar6 = get_direct_play_max_amplitude(puVar19);
    uVar8 = __msecs_to_jiffies(sVar2);
    queue_delayed_work_on(0x20,_system_wq,puVar19 + 0x26,uVar8);
    iVar7 = *(int *)((long)puVar19 + 0x34);
    mutex_lock(puVar19 + 0x14);
    if (*(char *)(puVar19 + 0x1c) == '\0') {
      puVar19[0x10] = 0;
      if ((puVar19[0x4e] != 0) || (*(int *)(puVar19 + 0x6d) == 3)) {
        local_80 = local_80 & 0xffffffffffffff00;
        uVar15 = *(int *)(puVar19 + 0x69) + 0x67U & 0xffff;
        iVar7 = regmap_bulk_read(puVar19[1],uVar15,&local_80,1);
        if (iVar7 < 0) {
          _dev_err(*puVar19,"read addr %#x failed, rc=%d\n",uVar15,iVar7);
          _dev_err(*puVar19,"Get Vmax HDRM failed, rc=%d\n",iVar7);
          goto LAB_00108724;
        }
        iVar7 = *(int *)((long)puVar19 + 0x33c) + ((byte)local_80 & 0x7f) * -0x32;
      }
      iVar7 = haptics_set_vmax_mv(puVar19,iVar7);
      if (-1 < iVar7) {
        puVar19[0x11] = puVar19 + 3;
        iVar7 = haptics_set_brake(puVar19);
        if (-1 < iVar7) {
          uVar15 = *(int *)((long)puVar19 + 0x34c) + 0x26U & 0xffff;
          local_80 = CONCAT71(local_80._1_7_,(char)(((uVar6 & 0xff) * (int)sVar3) / 0x7fff));
          iVar7 = regmap_bulk_write(puVar19[1],uVar15,&local_80,1);
          if (iVar7 < 0) {
            _dev_err(*puVar19,"write addr %#x failed, rc=%d\n",uVar15,iVar7);
            _dev_err(*puVar19,"config DIRECT_PLAY failed, rc=%d\n",iVar7);
          }
          else {
            regmap_update_bits_base
                      (puVar19[1],*(int *)(puVar19 + 0x69) + 99U & 0xffff,0x80,
                       (ulong)(*(char *)((long)puVar19 + 100) == '\0') << 7,0,0,0);
            *(undefined4 *)((long)puVar19 + 0xdc) = 1;
          }
        }
      }
    }
    else {
      _dev_err(*puVar19,"calibration in progress, ignore playing constant effect\n");
    }
LAB_00108724:
    mutex_unlock(puVar19 + 0x14);
LAB_0010872c:
    iVar7 = haptics_enable_hpwr_vreg(puVar19,1);
    if (-1 < iVar7) {
      iVar7 = haptics_wait_hboost_ready(puVar19);
      if ((iVar7 < 0) && (*(int *)((long)puVar19 + 0xdc) == 0)) {
        mutex_lock(puVar19 + 0x14);
        haptics_stop_fifo_play(puVar19);
        mutex_unlock(puVar19 + 0x14);
      }
      else {
        iVar7 = 0;
      }
      goto LAB_00108920;
    }
    uVar8 = *puVar19;
    pcVar11 = "enable hpwr_vreg failed, rc=%d\n";
  }
LAB_00108918:
  _dev_err(uVar8,pcVar11,iVar7);
LAB_00108920:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// haptics_playback @ 00108a50 size=48
// signature: undefined haptics_playback(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_playback(long param_1,undefined8 param_2,int param_3)

{
  undefined8 uVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  uVar1 = haptics_enable_play(*(undefined8 *)(param_1 + 0x2d8),1);
  return uVar1;
}



//------------------------------------------------------------
// haptics_erase @ 00108a84 size=328
// signature: undefined haptics_erase(void)
// callers: []
//------------------------------------------------------------

int haptics_erase(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 *puVar5;
  
  puVar5 = *(undefined8 **)(param_1 + 0x2d8);
  cancel_work_sync(puVar5 + 0x61);
  puVar1 = puVar5 + 0x14;
  mutex_lock(puVar1);
  cancel_delayed_work_sync(puVar5 + 0x26);
  if ((*(int *)((long)puVar5 + 0xdc) == 0) && (*(int *)(puVar5 + 0x13) != 0)) {
    if (*(int *)((long)puVar5 + 0x94) == 0) {
      *(undefined4 *)((long)puVar5 + 0x9c) = 1;
    }
    iVar2 = haptics_stop_fifo_play(puVar5);
    if (-1 < iVar2) {
LAB_00108b08:
      mutex_unlock(puVar1);
      if ((puVar5[0x4e] == 0) || (*(char *)((long)puVar5 + 0x36f) == '\0')) {
        return 0;
      }
      iVar2 = regulator_disable();
      if (iVar2 < 0) {
        uVar3 = *puVar5;
        pcVar4 = "Disable hpwr failed, rc=%d\n";
      }
      else {
        iVar2 = regulator_set_voltage(puVar5[0x4e],0,0x7fffffff);
        if (-1 < iVar2) {
          *(undefined1 *)((long)puVar5 + 0x36f) = 0;
          return 0;
        }
        uVar3 = *puVar5;
        pcVar4 = "Set hpwr voltage failed, rc=%d\n";
      }
      _dev_err(uVar3,pcVar4,iVar2);
      _dev_err(*puVar5,"disable hpwr_vreg failed, rc=%d\n",iVar2);
      return iVar2;
    }
    uVar3 = *puVar5;
    pcVar4 = "stop FIFO playing failed, rc=%d\n";
  }
  else {
    iVar2 = haptics_enable_play(puVar5,0);
    if (-1 < iVar2) goto LAB_00108b08;
    uVar3 = *puVar5;
    pcVar4 = "stop play failed, rc=%d\n";
  }
  _dev_err(uVar3,pcVar4,iVar2);
  mutex_unlock(puVar1);
  return iVar2;
}



//------------------------------------------------------------
// haptics_set_gain @ 00108bd0 size=76
// signature: undefined haptics_set_gain(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void haptics_set_gain(long param_1,ushort param_2)

{
  uint uVar1;
  long lVar2;
  
  if (param_2 != 0) {
    uVar1 = (uint)param_2;
    lVar2 = *(long *)(param_1 + 0x2d8);
    if (0x7ffe < uVar1) {
      uVar1 = 0x7fff;
    }
    *(uint *)(lVar2 + 0xd0) = uVar1;
    queue_work_on(0x20,_system_wq,lVar2 + 0x308);
  }
  return;
}



//------------------------------------------------------------
// haptics_boost_notifier @ 00108c20 size=156
// signature: undefined haptics_boost_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_boost_notifier(long param_1,long param_2,uint *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    uVar2 = *param_3;
    if (10000 < uVar2) {
      _dev_err(*(undefined8 *)(param_1 + -0x2c0),
               "voted Vmax (%u mV) is higher than maximum (%u mV)\n",uVar2,10000);
      return 0xffffffea;
    }
    *(uint *)(param_1 + 0x94) = uVar2;
    uVar3 = 3;
    if (*(int *)(param_1 + 0xa8) != 4) {
      uVar3 = 1;
    }
    uVar1 = 0;
    if (uVar2 != 10000) {
      uVar1 = uVar3;
    }
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + -0x2b8),*(int *)(param_1 + 0x88) + 0x68U & 0xffff,uVar3,
               uVar1,0,0,0);
  }
  return 0;
}



//------------------------------------------------------------
// richtap_work_proc @ 00108cc0 size=1520
// signature: undefined richtap_work_proc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void richtap_work_proc(long param_1)

{
  int iVar1;
  char cVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined8 *puVar10;
  uint uVar11;
  undefined8 uVar12;
  uint *puVar13;
  
  puVar10 = (undefined8 *)(param_1 + -0x390);
  cancel_work_sync(param_1 + 0x30);
  regmap_update_bits_base
            (*(undefined8 *)(param_1 + -0x388),*(int *)(param_1 + -0x48) + 0x72U & 0xffff,0xc,0,0,0,
             0);
  iVar5 = -100;
  *(undefined4 *)(param_1 + 100) = 1;
  *(undefined1 *)(param_1 + 0x68) = 1;
  do {
    pcVar7 = *(char **)(param_1 + -0x10);
    if (*pcVar7 == 'U') goto LAB_00108d60;
    usleep_range_state(1000,0x3e9,2);
    bVar4 = iVar5 != -1;
    iVar5 = iVar5 + 1;
  } while (bVar4);
  pcVar7 = *(char **)(param_1 + -0x10);
LAB_00108d60:
  if ((*(short *)(pcVar7 + 2) < 1) || (*pcVar7 != 'U')) {
    _dev_err(*puVar10,"aac richtap first length invalid %d %d ");
    mutex_lock(param_1 + -0x2f0);
    puVar8 = *(undefined1 **)(param_1 + -0x10);
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar9 + 8);
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    puVar9 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    *puVar9 = 0xaa;
    *(undefined2 *)(puVar9 + 2) = 0;
    *(undefined4 *)(param_1 + -0x2fc) = 1;
    if (*(int *)(param_1 + -0x28) - 2U < 3) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + -0x388),*(int *)(param_1 + -0x44) + 0x2aU & 0xffff,0xf,0,
                 0,0,0);
    }
    else {
      _printk(&DAT_00111ba3);
    }
    haptics_stop_fifo_play(puVar10);
    *(undefined4 *)(param_1 + 100) = 0;
    mutex_unlock(param_1 + -0x2f0);
    return;
  }
  uVar11 = 0;
  iVar5 = 0;
  puVar13 = (uint *)(param_1 + -0x2a4);
  *(undefined2 *)(param_1 + 0x60) = 0;
  *(char **)(param_1 + -8) = pcVar7;
  do {
    cVar2 = **(char **)(param_1 + -8);
    if (cVar2 == 'U') {
      iVar1 = *(int *)(param_1 + -0x28);
      sVar3 = *(short *)(*(char **)(param_1 + -8) + 2);
      if (iVar1 == 2) {
        uVar6 = 0x280;
      }
      else if (iVar1 == 4) {
        uVar6 = 0x280;
        if (*puVar13 != 0) {
          uVar6 = *puVar13;
        }
      }
      else if (iVar1 == 3) {
        uVar6 = 0x400;
      }
      else {
        _printk(&DAT_00111ba3);
        uVar6 = 0;
      }
      if (uVar6 < uVar11 + (int)sVar3) {
        iVar1 = *(int *)(param_1 + -0x28);
        if (iVar1 == 2) {
          uVar6 = 0x280;
        }
        else if (iVar1 == 4) {
          uVar6 = 0x280;
          if (*puVar13 != 0) {
            uVar6 = *puVar13;
          }
        }
        else if (iVar1 == 3) {
          uVar6 = 0x400;
        }
        else {
          _printk(&DAT_00111ba3);
          uVar6 = 0;
        }
        memcpy((void *)(*(long *)(param_1 + -0x18) + (ulong)uVar11),
               (void *)(*(long *)(param_1 + -8) + 0x18),(ulong)(uVar6 - uVar11));
        iVar1 = *(int *)(param_1 + -0x28);
        sVar3 = (short)uVar11;
        if (iVar1 == 4) {
          uVar11 = 0x280;
          if (*puVar13 != 0) {
            uVar11 = *puVar13;
          }
          *(short *)(param_1 + 0x60) = (short)uVar11 - sVar3;
LAB_00108fe0:
          uVar11 = 0x280;
          if (*puVar13 != 0) {
            uVar11 = *puVar13;
          }
        }
        else if (iVar1 == 3) {
          uVar11 = 0x400;
          *(short *)(param_1 + 0x60) = 0x400 - sVar3;
        }
        else if (iVar1 == 2) {
          uVar11 = 0x280;
          *(short *)(param_1 + 0x60) = 0x280 - sVar3;
        }
        else {
          _printk(&DAT_00111ba3);
          iVar1 = *(int *)(param_1 + -0x28);
          *(short *)(param_1 + 0x60) = -sVar3;
          if (iVar1 == 2) {
            uVar11 = 0x280;
          }
          else {
            if (iVar1 == 4) goto LAB_00108fe0;
            if (iVar1 == 3) {
              uVar11 = 0x400;
            }
            else {
              _printk(&DAT_00111ba3);
              uVar11 = 0;
            }
          }
        }
        _dev_err(*puVar10,"first full\n");
      }
      else {
        memcpy((void *)(*(long *)(param_1 + -0x18) + (ulong)uVar11),
               (void *)(*(long *)(param_1 + -8) + 0x18),
               (long)*(short *)(*(long *)(param_1 + -8) + 2));
        puVar8 = *(undefined1 **)(param_1 + -8);
        *puVar8 = 0xff;
        uVar11 = uVar11 + (int)*(short *)(puVar8 + 2);
        *(undefined2 *)(*(long *)(param_1 + -8) + 2) = 0;
        *(undefined2 *)(param_1 + 0x60) = 0;
        *(undefined8 *)(param_1 + -8) = *(undefined8 *)(*(long *)(param_1 + -8) + 8);
      }
    }
    else {
      if (cVar2 == -0x56) break;
      usleep_range_state(1000,0x3e9,2);
      _dev_err(*puVar10,"wait for data\n");
    }
    iVar1 = *(int *)(param_1 + -0x28);
    if (iVar1 == 2) {
      if (0x27f < uVar11) break;
    }
    else if (iVar1 == 4) {
      uVar6 = 0x280;
      if (*puVar13 != 0) {
        uVar6 = *puVar13;
      }
      if (uVar6 <= uVar11) break;
    }
    else {
      if (iVar1 != 3) {
        _printk(&DAT_00111ba3);
        break;
      }
      if (0x3ff < uVar11) break;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0x1f);
  iVar1 = *(int *)(param_1 + -0x28);
  uVar12 = *puVar10;
  if (iVar1 == 2) {
    uVar6 = 0x280;
  }
  else if (iVar1 == 4) {
    uVar6 = 0x280;
    if (*puVar13 != 0) {
      uVar6 = *puVar13;
    }
  }
  else if (iVar1 == 3) {
    uVar6 = 0x400;
  }
  else {
    _printk(&DAT_00111ba3);
    uVar6 = 0;
  }
  _dev_info(uVar12,"tmp_len %d, retry %d, max_fifo %d\n",uVar11,iVar5,uVar6);
  iVar5 = richtap_load_prebake(puVar10,*(undefined8 *)(param_1 + -0x18),uVar11);
  if (iVar5 < 0) {
    uVar12 = *puVar10;
    pcVar7 = "aac RichTap Upload FIFO data fail: %d\n";
  }
  else {
    iVar5 = haptics_enable_hpwr_vreg(puVar10,1);
    if (iVar5 < 0) {
      uVar12 = *puVar10;
      pcVar7 = "aac RichTap enable hpwr_vreg fail, rc=%d\n";
    }
    else {
      iVar5 = haptics_wait_hboost_ready(puVar10);
      if (iVar5 < 0) {
        queue_work_on(0x20,_system_wq,param_1 + 0x30);
        return;
      }
      iVar5 = haptics_enable_play(puVar10,1);
      if (-1 < iVar5) {
        if (*(int *)(param_1 + -0x2b4) != 0) {
          return;
        }
        if (*(char *)(param_1 + -0x24) == '\0') {
          enable_irq(*(undefined4 *)(param_1 + -0x58));
          *(undefined1 *)(param_1 + -0x24) = 1;
          return;
        }
        return;
      }
      uVar12 = *puVar10;
      pcVar7 = "aac RichTap richtap_playback fail, rc=%d\n";
    }
  }
  _dev_err(uVar12,pcVar7,iVar5);
  return;
}



//------------------------------------------------------------
// richtap_erase_work_proc @ 001092b4 size=916
// signature: undefined richtap_erase_work_proc(void)
// callers: []
//------------------------------------------------------------

void richtap_erase_work_proc(long param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined8 *puVar6;
  int *piVar7;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  puVar6 = (undefined8 *)(param_1 + -0x3c0);
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  iVar3 = haptics_get_fifo_fill_status(puVar6,&local_3c);
  if ((-1 < iVar3) && (piVar7 = (int *)(param_1 + -0x328), *piVar7 != 0)) {
    if (0x17 < local_3c) {
      uVar1 = (local_3c / 0x18) * 1000;
      local_3c = uVar1;
      usleep_range_state(uVar1 + 0x19,uVar1 + 0x1e,2);
      _dev_info(*puVar6,"aac fill time %d\n",uVar1);
      iVar3 = haptics_get_fifo_fill_status(puVar6,&local_3c);
      if ((iVar3 < 0) || (*piVar7 == 0)) goto LAB_00109438;
      if (0x17 < local_3c) {
        uVar1 = (local_3c / 0x18) * 1000;
        local_3c = uVar1;
        usleep_range_state(uVar1 + 0x19,uVar1 + 0x1e,2);
        _dev_info(*puVar6,"aac fill time %d\n",uVar1);
        iVar3 = haptics_get_fifo_fill_status(puVar6,&local_3c);
        if ((iVar3 < 0) || (*piVar7 == 0)) goto LAB_00109438;
        if (0x17 < local_3c) {
          uVar1 = (local_3c / 0x18) * 1000;
          local_3c = uVar1;
          usleep_range_state(uVar1 + 0x19,uVar1 + 0x1e,2);
          _dev_info(*puVar6,"aac fill time %d\n",uVar1);
          iVar3 = haptics_get_fifo_fill_status(puVar6,&local_3c);
          if ((iVar3 < 0) || (*piVar7 == 0)) goto LAB_00109438;
          if (0x17 < local_3c) {
            uVar1 = (local_3c / 0x18) * 1000;
            local_3c = uVar1;
            usleep_range_state(uVar1 + 0x19,uVar1 + 0x1e,2);
            _dev_info(*puVar6,"aac fill time %d\n",uVar1);
            iVar3 = haptics_get_fifo_fill_status(puVar6,&local_3c);
            if ((iVar3 < 0) || (*piVar7 == 0)) goto LAB_00109438;
            if (0x17 < local_3c) {
              iVar3 = (local_3c / 0x18) * 1000;
              usleep_range_state(iVar3 + 0x19,iVar3 + 0x1e,2);
              _dev_info(*puVar6,"aac fill time %d\n",iVar3);
            }
          }
        }
      }
    }
    mutex_lock(param_1 + -800);
    puVar4 = *(undefined1 **)(param_1 + -0x40);
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    puVar4 = *(undefined1 **)(puVar5 + 8);
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    puVar5 = *(undefined1 **)(puVar4 + 8);
    *puVar4 = 0xaa;
    *(undefined2 *)(puVar4 + 2) = 0;
    *puVar5 = 0xaa;
    *(undefined2 *)(puVar5 + 2) = 0;
    *(undefined4 *)(param_1 + -0x32c) = 1;
    if (*(int *)(param_1 + -0x58) - 2U < 3) {
      regmap_update_bits_base
                (*(undefined8 *)(param_1 + -0x3b8),*(int *)(param_1 + -0x74) + 0x2aU & 0xffff,0xf,0,
                 0,0,0);
    }
    else {
      _printk(&DAT_00111ba3);
    }
    haptics_stop_fifo_play(puVar6);
    *(undefined4 *)(param_1 + 0x34) = 0;
    mutex_unlock(param_1 + -800);
  }
LAB_00109438:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// haptics_start_lra_calibrate @ 00109648 size=4996
// signature: undefined haptics_start_lra_calibrate(void)
// callers: [haptics_probe, lra_calibration_store]
//------------------------------------------------------------

int haptics_start_lra_calibrate(undefined8 *param_1)

{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  bool bVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  uint uVar10;
  char *pcVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined8 *puVar16;
  uint uVar17;
  ulong uVar18;
  ulong uVar19;
  byte bVar20;
  undefined8 uVar21;
  ulong uVar22;
  ulong uVar23;
  uint uVar24;
  undefined8 uVar25;
  uint uVar26;
  int local_108;
  undefined1 local_fc [4];
  undefined1 local_f8 [4];
  byte local_f4 [4];
  undefined4 local_f0;
  undefined2 local_ec;
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
  int local_88;
  int local_84;
  undefined4 uStack_80;
  undefined8 local_78;
  long local_70;
  
  lVar4 = sp_el0;
  local_70 = *(long *)(lVar4 + 0x638);
  mutex_lock(param_1 + 0x14);
  if ((*(int *)((long)param_1 + 0xdc) == 0) && (*(int *)(param_1 + 0x13) != 0)) {
    _dev_err(*param_1,"In FIFO playing, ignore calibration\n");
    iVar7 = -0x10;
    goto LAB_0010a734;
  }
  iVar7 = haptics_enable_play(param_1,0);
  if (iVar7 < 0) {
    uVar9 = *param_1;
    pcVar11 = "Stop playing failed, rc=%d\n";
  }
  else {
    local_78 = local_78 & 0xffffffffffffff00;
    puVar16 = param_1 + 1;
    *(undefined1 *)(param_1 + 0x1c) = 1;
    iVar8 = *(int *)((long)param_1 + 0x34);
    local_f0 = local_f0 & 0xffffff00;
    uVar10 = *(int *)(param_1 + 0x69) + 99U & 0xffff;
    iVar7 = regmap_bulk_read(*puVar16,uVar10,&local_78,1);
    if (iVar7 < 0) {
      _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar10,iVar7);
      uVar9 = *param_1;
      pcVar11 = "Read AUTORES_CFG failed, rc=%d\n";
LAB_00109fd4:
      _dev_err(uVar9,pcVar11,iVar7);
    }
    else {
      puVar1 = (ushort *)(param_1 + 0x69);
      uVar10 = *(int *)puVar1 + 0x60U & 0xffff;
      iVar7 = regmap_bulk_read(*puVar16,uVar10,&local_f0,1);
      if (iVar7 < 0) {
        _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar10,iVar7);
        uVar9 = *param_1;
        pcVar11 = "Read DRV_DUTY_CFG failed, rc=%d\n";
        goto LAB_00109fd4;
      }
      uVar12 = 0xb9;
      if (*(int *)(param_1 + 0x6d) != 4) {
        uVar12 = 0xb2;
      }
      regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 99U & 0xffff,0xbf,uVar12,0,0,0);
      uVar12 = 0xff;
      if (*(int *)(param_1 + 0x6d) != 4) {
        uVar12 = 0x80;
      }
      uVar15 = 0x16;
      if (*(int *)(param_1 + 0x6d) != 4) {
        uVar15 = 0;
      }
      regmap_update_bits_base
                (param_1[1],*(int *)(param_1 + 0x69) + 0x60U & 0xffff,uVar12,uVar15,0,0,0);
      iVar7 = haptics_config_openloop_lra_period(param_1,*(undefined4 *)((long)param_1 + 0x3c));
      if (-1 < iVar7) {
        local_e8 = CONCAT71(local_e8._1_7_,10);
        uVar10 = *(int *)puVar1 + 0x67U & 0xffff;
        iVar7 = regmap_bulk_write(*puVar16,uVar10,&local_e8,1);
        if (iVar7 < 0) {
          _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar7);
          uVar9 = *param_1;
          pcVar11 = "config VMAX_HDRM failed, rc=%d\n";
LAB_0010996c:
          _dev_err(uVar9,pcVar11,iVar7);
        }
        else {
          if ((param_1[0x4e] != 0) || (*(int *)(param_1 + 0x6d) == 3)) {
            iVar8 = *(int *)((long)param_1 + 0x33c) + -500;
          }
          iVar7 = haptics_set_vmax_mv(param_1,iVar8);
          if (-1 < iVar7) {
            uVar6 = get_direct_play_max_amplitude(param_1);
            local_e8 = CONCAT71(local_e8._1_7_,uVar6);
            uVar10 = *(int *)((long)param_1 + 0x34c) + 0x26U & 0xffff;
            iVar7 = regmap_bulk_write(param_1[1],uVar10,&local_e8,1);
            if (iVar7 < 0) {
              _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar7);
              uVar9 = *param_1;
              pcVar11 = "config DIRECT_PLAY failed, rc=%d\n";
              goto LAB_0010996c;
            }
            iVar7 = haptics_enable_hpwr_vreg(param_1,1);
            if (-1 < iVar7) {
              *(undefined4 *)((long)param_1 + 0xdc) = 1;
              iVar7 = haptics_enable_play(param_1,1);
              if (-1 < iVar7) {
                usleep_range_state(150000,0x25d78,2);
                iVar7 = haptics_get_closeloop_lra_period(param_1,0);
                if ((-1 < iVar7) && (iVar7 = haptics_enable_play(param_1,0), -1 < iVar7)) {
                  haptics_config_openloop_lra_period(param_1,*(undefined4 *)(param_1 + 8));
                }
              }
            }
          }
        }
      }
      haptics_enable_play(param_1,0);
      if ((param_1[0x4e] != 0) && (*(char *)((long)param_1 + 0x36f) != '\0')) {
        iVar7 = regulator_disable();
        if (iVar7 < 0) {
          uVar9 = *param_1;
          pcVar11 = "Disable hpwr failed, rc=%d\n";
        }
        else {
          iVar7 = regulator_set_voltage(param_1[0x4e],0,0x7fffffff);
          if (-1 < iVar7) {
            *(undefined1 *)((long)param_1 + 0x36f) = 0;
            goto LAB_001099ac;
          }
          uVar9 = *param_1;
          pcVar11 = "Set hpwr voltage failed, rc=%d\n";
        }
        goto LAB_00109fd4;
      }
LAB_001099ac:
      uVar10 = *(int *)puVar1 + 99U & 0xffff;
      iVar7 = regmap_bulk_write(*puVar16,uVar10,&local_78,1);
      if (-1 < iVar7) {
        uVar10 = *(int *)puVar1 + 0x60U & 0xffff;
        iVar7 = regmap_bulk_write(*puVar16,uVar10,&local_f0,1);
        if (-1 < iVar7) {
          usleep_range_state(4000,5000,2);
          if (*(char *)((long)param_1 + 0x65) == '\0') {
            uVar23 = (ulong)&local_78 | 1;
            local_e8 = CONCAT26(local_e8._6_2_,0x6700000000);
            local_78 = CONCAT26(local_78._6_2_,0x6700000000);
            uVar10 = *(int *)puVar1 + 0x49U & 0xffff;
            local_f4[0] = 0;
            local_e8 = CONCAT44(local_e8._4_4_,0xc8481049);
            local_78 = CONCAT44(local_78._4_4_,0xc8481049);
            local_f8[0] = 0;
            local_fc[0] = 0;
            iVar7 = regmap_bulk_read(*puVar16,uVar10,uVar23,1);
            if (iVar7 < 0) {
LAB_00109f58:
              uVar9 = *param_1;
              pcVar11 = "read addr %#x failed, rc=%d\n";
LAB_0010a6b8:
              _dev_err(uVar9,pcVar11,uVar10,iVar7);
joined_r0x0010a6c4:
              if (-1 < iVar7) goto LAB_0010a218;
            }
            else {
              uVar22 = (ulong)&local_78 | 3;
              uVar10 = *(int *)puVar1 + (uint)local_78._2_1_ & 0xffff;
              iVar7 = regmap_bulk_read(*puVar16,uVar10,uVar22,1);
              if (iVar7 < 0) goto LAB_00109f58;
              uVar10 = *(int *)puVar1 + (uint)local_78._4_1_ & 0xffff;
              iVar7 = regmap_bulk_read(*puVar16,uVar10,(ulong)&local_78 | 5,1);
              if (iVar7 < 0) goto LAB_00109f58;
              iVar7 = *(int *)(param_1 + 0x6d);
              if (iVar7 == 3) {
                uVar9 = 0x67;
                uVar25 = 0x80;
                bVar20 = 0x61;
                uVar21 = 0x80;
                local_108 = 0x77;
LAB_00109ce4:
                uVar10 = *(int *)puVar1 + 0x65U & 0xffff;
                iVar7 = regmap_bulk_read(*puVar16,uVar10,local_f8,1);
                if (-1 < iVar7) {
                  uVar10 = (uint)*puVar1 + local_108 & 0xffff;
                  iVar7 = regmap_bulk_read(*puVar16,uVar10,local_fc,1);
                  if (iVar7 < 0) goto LAB_00109f88;
                  regmap_update_bits_base
                            (*puVar16,*(int *)puVar1 + 0x65U & 0xffff,uVar21,uVar25,0,0,0);
                  regmap_update_bits_base
                            (*puVar16,(uint)*puVar1 + local_108 & 0xffff,uVar9,bVar20,0,0,0);
                  uVar10 = *(int *)puVar1 + (uint)(byte)local_e8 & 0xffff;
                  iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 1,1);
                  if (iVar7 < 0) {
LAB_00109f6c:
                    uVar9 = *param_1;
                    pcVar11 = "write addr %#x failed, rc=%d\n";
LAB_00109f7c:
                    _dev_err(uVar9,pcVar11,uVar10,iVar7);
                  }
                  else {
                    uVar10 = *(int *)puVar1 + (uint)local_e8._2_1_ & 0xffff;
                    iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 3,1);
                    if (iVar7 < 0) goto LAB_00109f6c;
                    uVar10 = *(int *)puVar1 + (uint)local_e8._4_1_ & 0xffff;
                    iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 5,1);
                    if (iVar7 < 0) goto LAB_00109f6c;
                    iVar7 = haptics_enable_hpwr_vreg(param_1,1);
                    if (-1 < iVar7) {
                      uVar24 = 0;
                      iVar8 = 5;
                      uVar26 = 100000;
                      do {
                        uVar13 = uVar26 + uVar24 >> 1;
                        uVar10 = *(int *)((long)param_1 + 0x34c) + 0x26U & 0xffff;
                        local_f0 = CONCAT31(local_f0._1_3_,(char)((uVar13 * 0xff) / 100000));
                        iVar7 = regmap_bulk_write(param_1[1],uVar10,&local_f0,1);
                        if (iVar7 < 0) {
                          _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar7);
                          _dev_err(*param_1,"config DIRECT_PLAY failed, rc=%d\n",iVar7);
                          goto LAB_0010a100;
                        }
                        *(undefined4 *)((long)param_1 + 0xdc) = 1;
                        iVar7 = haptics_enable_play(param_1,1);
                        if (iVar7 < 0) goto LAB_0010a100;
                        usleep_range_state(*(int *)((long)param_1 + 0x3c),
                                           *(int *)((long)param_1 + 0x3c) + 1000,2);
                        uVar10 = *(int *)(param_1 + 0x69) + 0xcU & 0xffff;
                        iVar7 = regmap_bulk_read(param_1[1],uVar10,local_f4,1);
                        bVar20 = local_f4[0];
                        if (iVar7 < 0) {
                          uVar9 = *param_1;
                          pcVar11 = "read addr %#x failed, rc=%d\n";
                          goto LAB_00109f7c;
                        }
                        iVar7 = haptics_enable_play(param_1,0);
                        if (iVar7 < 0) goto LAB_0010a100;
                        if ((bVar20 & 4) != 0) {
                          uVar26 = uVar13;
                          uVar13 = uVar24;
                        }
                        uVar24 = uVar13;
                        usleep_range_state(4000,5000,2);
                        iVar8 = iVar8 + -1;
                      } while (iVar8 != 0);
                      iVar7 = *(int *)(param_1 + 0x6d);
                      if (iVar7 == 4) {
                        bVar5 = *(char *)((long)param_1 + 0x36e) != '\0';
                        uVar10 = 10000000;
                        if (bVar5) {
                          uVar10 = 5000000;
                        }
                        uVar13 = 0xfa;
                        if (bVar5) {
                          uVar13 = 0x7d;
                        }
LAB_0010a0a8:
                        if (param_1[0x4e] != 0) {
LAB_0010a0b8:
                          uVar10 = *(int *)((long)param_1 + 0x33c) * 1000;
                        }
                        uVar17 = 0;
                        if (uVar13 != 0) {
                          uVar17 = uVar10 / uVar13;
                        }
                      }
                      else {
                        if (iVar7 == 3) {
                          uVar13 = 0x8c;
                          goto LAB_0010a0b8;
                        }
                        if (iVar7 == 2) {
                          uVar10 = 10000000;
                          if (*(char *)((long)param_1 + 0x36e) != '\0') {
                            uVar10 = 5000000;
                          }
                          uVar13 = 0xfa;
                          goto LAB_0010a0a8;
                        }
                        uVar17 = 0;
                      }
                      uVar10 = (uVar17 * uVar26) / 100000;
                      if (uVar17 * uVar24 < 100000) {
                        pcVar11 = "Short circuit detected!\n";
LAB_0010a9bc:
                        _dev_warn(*param_1,pcVar11);
                      }
                      else if (uVar17 <= uVar10) {
                        pcVar11 = "Open circuit detected!\n";
                        goto LAB_0010a9bc;
                      }
                      *(uint *)((long)param_1 + 0x44) = (uVar17 * uVar24) / 100000;
                      *(uint *)(param_1 + 9) = uVar10;
                      *(uint *)((long)param_1 + 0x4c) = uVar17;
                    }
                  }
LAB_0010a100:
                  haptics_enable_play(param_1,0);
                  if ((param_1[0x4e] != 0) && (*(char *)((long)param_1 + 0x36f) != '\0')) {
                    iVar7 = regulator_disable();
                    if (iVar7 < 0) {
                      uVar9 = *param_1;
                      pcVar11 = "Disable hpwr failed, rc=%d\n";
                    }
                    else {
                      iVar7 = regulator_set_voltage(param_1[0x4e],0,0x7fffffff);
                      if (-1 < iVar7) {
                        *(undefined1 *)((long)param_1 + 0x36f) = 0;
                        goto LAB_0010a140;
                      }
                      uVar9 = *param_1;
                      pcVar11 = "Set hpwr voltage failed, rc=%d\n";
                    }
                    _dev_err(uVar9,pcVar11,iVar7);
                    goto joined_r0x0010a6c4;
                  }
LAB_0010a140:
                  if (*(int *)(param_1 + 0x6d) == 2) goto LAB_0010a838;
                  uVar10 = *(int *)puVar1 + 0x65U & 0xffff;
                  iVar7 = regmap_bulk_write(*puVar16,uVar10,local_f8,1);
                  if (-1 < iVar7) {
                    uVar10 = (uint)*puVar1 + local_108 & 0xffff;
                    iVar7 = regmap_bulk_write(*puVar16,uVar10,local_fc,1);
                    if (-1 < iVar7) {
                      uVar10 = *(int *)puVar1 + (uint)(byte)local_78 & 0xffff;
                      iVar7 = regmap_bulk_write(*puVar16,uVar10,uVar23,1);
                      if (-1 < iVar7) {
                        uVar10 = *(int *)puVar1 + (uint)local_78._2_1_ & 0xffff;
                        iVar7 = regmap_bulk_write(*puVar16,uVar10,uVar22,1);
                        if (-1 < iVar7) {
                          uVar10 = *(int *)puVar1 + (uint)local_78._4_1_ & 0xffff;
                          iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_78 | 5,1);
                          if (-1 < iVar7) goto joined_r0x0010a6c4;
                        }
                      }
                    }
                  }
                  uVar9 = *param_1;
                  pcVar11 = "write addr %#x failed, rc=%d\n";
                  goto LAB_0010a6b8;
                }
LAB_00109f88:
                _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar10,iVar7);
                goto joined_r0x0010a6c4;
              }
              if (iVar7 == 4) {
                uVar21 = 0x7c;
                uVar9 = 0x81;
                uVar25 = 0x10;
                bVar20 = *(byte *)((long)param_1 + 0x36e) ^ 0x81;
                local_108 = 0xa4;
                goto LAB_00109ce4;
              }
              if (iVar7 == 2) {
LAB_0010a838:
                if (param_1[0x3a] == 0) {
                  _dev_err(*param_1,"PBS device is not defined\n");
                  iVar7 = -0x13;
                }
                else {
                  iVar7 = -0x13;
                  _dev_err(*param_1,"Trigger PBS to config ISC failed, rc=%d\n",0xffffffed);
                }
              }
              else {
                _dev_err(*param_1,"unsupported HW type: %d\n");
                iVar7 = -0x5f;
              }
            }
            uVar9 = *param_1;
            pcVar11 = "Detect LRA impedance failed, rc=%d\n";
            goto LAB_0010a72c;
          }
          iVar3 = *(int *)((long)param_1 + 0x3c);
          local_d8 = 0;
          uStack_d0 = 0;
          local_c8 = 0;
          uStack_c0 = 0;
          local_e8 = 0xff;
          uStack_e0 = 0;
          iVar8 = iVar3 + 2000;
          local_b8 = 0;
          uStack_b0 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          bVar20 = *(byte *)((long)param_1 + 0x36e) ^ 1;
          local_98 = 0;
          uStack_90 = 0;
          uStack_80 = 0;
          local_88 = iVar8;
          local_84 = iVar8;
          if (param_1[0x39] == 0) {
            uVar10 = 0x1194;
          }
          else {
            local_78 = local_78 & 0xffffffffffffff00;
            iVar7 = nvmem_device_read(param_1[0x39],0x75,1,&local_78);
            uVar10 = 0x1194;
            if (-1 < iVar7) {
              uVar10 = 0;
              if (iVar7 != 0) {
                uVar10 = (uint)((byte)local_78 >> 2);
              }
              bVar2 = 0;
              if (uVar10 < 0x29) {
                bVar2 = bVar20;
              }
              bVar20 = bVar2;
              if (uVar10 < 0xf) {
                bVar20 = 1;
              }
              iVar7 = 0x7d;
              if (bVar20 != 0) {
                iVar7 = 0xfa;
              }
              iVar14 = 1000;
              if (bVar20 != 0) {
                iVar14 = 2000;
              }
              uVar10 = iVar14 + iVar7 * uVar10;
              if (uVar10 < 0x1195) {
                uVar10 = 0x1194;
              }
            }
          }
          iVar7 = haptics_set_vmax_mv(param_1,uVar10);
          if (iVar7 < 0) goto joined_r0x0010a6c4;
          local_78 = CONCAT71(local_78._1_7_,bVar20) | 0x80;
          regmap_update_bits_base
                    (param_1[1],*(int *)(param_1 + 0x69) + 0xa4U & 0xffff,0x81,bVar20 | 0x80,0,0,0);
          regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 0x65U & 0xffff,0x10,0,0,0,0)
          ;
          iVar7 = haptics_set_pattern(param_1,&local_e8,2);
          if (iVar7 < 0) {
LAB_0010a008:
            _dev_err(*param_1,"measure LRA impedance failed, rc=%d\n",iVar7);
          }
          else {
            *(undefined4 *)((long)param_1 + 0xdc) = 2;
            iVar7 = haptics_enable_play(param_1,1);
            if (iVar7 < 0) goto LAB_0010a008;
            usleep_range_state(iVar8,iVar3 + 0x7d1,2);
            iVar7 = haptics_enable_play(param_1,0);
            if (iVar7 < 0) goto LAB_0010a008;
            uVar10 = *(int *)puVar1 + 0xeU & 0xffff;
            iVar7 = regmap_bulk_read(*puVar16,uVar10,&local_78,1);
            if (iVar7 < 0) {
              _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar10,iVar7);
              goto LAB_0010a008;
            }
            *(uint *)(param_1 + 10) = (uint)(byte)local_78 * 0xfa;
            if ((param_1[0x39] != 0) &&
               (iVar7 = nvmem_device_write(param_1[0x39],0x76,1,&local_78), iVar7 < 0)) {
              _dev_err(*param_1,"write measured impedance value into SDAM failed, rc=%d\n",iVar7);
              goto LAB_0010a008;
            }
          }
          regmap_update_bits_base(*puVar16,*(int *)puVar1 + 0xa4U & 0xffff,0x80,0,0,0,0);
LAB_0010a218:
          msleep(0x32);
          local_78 = 0;
          local_ec = 0;
          local_f0 = 0;
          local_e8 = 0x3b61e151c1505560;
          if ((param_1[0x39] == 0) || (*(int *)(param_1 + 0x6d) != 4)) {
            iVar7 = -0x5f;
          }
          else {
            uVar10 = *(uint *)((long)param_1 + 0x3c);
            if (*(uint *)(param_1 + 8) != 0) {
              uVar10 = *(uint *)(param_1 + 8);
            }
            local_f0 = (uint)(CONCAT11((char)((ulong)uVar10 / 0x500),(char)((ulong)uVar10 / 5)) &
                             0xfff);
            iVar7 = nvmem_device_write(param_1[0x39],100,2,&local_f0);
            if (iVar7 < 0) {
              uVar9 = *param_1;
              pcVar11 = "set T_LRA for auto brake cal failed,rc=%d\n";
            }
            else {
              local_f0 = CONCAT31(local_f0._1_3_,0x5a);
              iVar7 = nvmem_device_write(param_1[0x39],0x4b,1,&local_f0);
              if (iVar7 < 0) {
                uVar9 = *param_1;
                pcVar11 = "set Vmax for auto brake cal failed,rc=%d\n";
              }
              else {
                local_ec = 0;
                local_f0 = 0;
                iVar7 = nvmem_device_write(param_1[0x39],0x4c,6,&local_f0);
                if (iVar7 < 0) {
                  uVar9 = *param_1;
                  pcVar11 = "set PTRN1_CFGx for auto brake cal failed, rc=%d\n";
                }
                else {
                  uVar10 = *(int *)((long)param_1 + 0x34) * 0xff;
                  uVar6 = (undefined1)((ulong)uVar10 / 0x1194);
                  local_ec = CONCAT11(uVar6,(char)(uVar10 / 0x1194));
                  local_f0 = CONCAT13(uVar6,0xc9c9ff);
                  iVar7 = nvmem_device_write(param_1[0x39],0x52,6,&local_f0);
                  if (-1 < iVar7) {
                    uVar23 = (ulong)&local_78 | 1;
                    local_78 = local_e8;
                    uVar10 = *(int *)puVar1 + ((uint)local_e8 & 0xff) & 0xffff;
                    iVar7 = regmap_bulk_read(*puVar16,uVar10,uVar23,1);
                    if (-1 < iVar7) {
                      uVar22 = (ulong)&local_78 | 3;
                      uVar10 = *(int *)puVar1 + (uint)local_78._2_1_ & 0xffff;
                      iVar7 = regmap_bulk_read(*puVar16,uVar10,uVar22,1);
                      if (-1 < iVar7) {
                        uVar19 = (ulong)&local_78 | 5;
                        uVar10 = *(int *)puVar1 + (uint)local_78._4_1_ & 0xffff;
                        iVar7 = regmap_bulk_read(*puVar16,uVar10,uVar19,1);
                        if (-1 < iVar7) {
                          uVar18 = (ulong)&local_78 | 7;
                          uVar10 = *(int *)puVar1 + (uint)local_78._6_1_ & 0xffff;
                          iVar7 = regmap_bulk_read(*puVar16,uVar10,uVar18,1);
                          if (-1 < iVar7) {
                            uVar10 = *(int *)puVar1 + (uint)(byte)local_e8 & 0xffff;
                            iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 1,1);
                            if (iVar7 < 0) {
LAB_0010a5c8:
                              _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar7);
                            }
                            else {
                              uVar10 = *(int *)puVar1 + (uint)local_e8._2_1_ & 0xffff;
                              iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 3,1);
                              if (iVar7 < 0) goto LAB_0010a5c8;
                              uVar10 = *(int *)puVar1 + (uint)local_e8._4_1_ & 0xffff;
                              iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 5,1);
                              if (iVar7 < 0) goto LAB_0010a5c8;
                              uVar10 = *(int *)puVar1 + (uint)local_e8._6_1_ & 0xffff;
                              iVar7 = regmap_bulk_write(*puVar16,uVar10,(ulong)&local_e8 | 7,1);
                              if (iVar7 < 0) goto LAB_0010a5c8;
                              local_f0 = local_f0 & 0xffffff00;
                              iVar7 = nvmem_device_write(param_1[0x39],0x7e,1,&local_f0);
                              if (iVar7 < 0) {
                                _dev_err(*param_1,"clear auto brake cal done flag failed, rc=%d\n",
                                         iVar7);
                              }
                              else {
                                local_f4[0] = 7;
                                uVar10 = *(int *)puVar1 + 0x66U & 0xffff;
                                iVar7 = regmap_bulk_write(*puVar16,uVar10,local_f4,1);
                                if (iVar7 < 0) {
                                  _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar7);
                                }
                                else {
                                  local_f0 = CONCAT31(local_f0._1_3_,3);
                                  iVar7 = nvmem_device_write(param_1[0x39],0x42,1,&local_f0);
                                  if (iVar7 < 0) {
                                    _dev_err(*param_1,
                                             "set PBS_ARG for auto brake cal failed, rc=%d\n",iVar7)
                                    ;
                                  }
                                  else {
                                    local_f0 = CONCAT31(local_f0._1_3_,1);
                                    iVar7 = nvmem_device_write(param_1[0x39],0xe6,1,&local_f0);
                                    if (iVar7 < 0) {
                                      _dev_err(*param_1,
                                               "clear PBS_TRIG for auto brake cal failed, rc=%d\n",
                                               iVar7);
                                    }
                                    else {
                                      local_f0 = CONCAT31(local_f0._1_3_,1);
                                      iVar7 = nvmem_device_write(param_1[0x39],0xe5,1,&local_f0);
                                      if (iVar7 < 0) {
                                        uVar9 = *param_1;
                                        pcVar11 = "set PBS_TRIG for auto brake cal failed, rc=%d\n";
LAB_0010a8f0:
                                        _dev_err(uVar9,pcVar11,iVar7);
                                      }
                                      else {
                                        msleep(800);
                                        iVar8 = -10;
                                        do {
                                          iVar7 = nvmem_device_read(param_1[0x39],0x7e,1,&local_f0);
                                          if (iVar7 < 0) {
                                            uVar9 = *param_1;
                                            pcVar11 = 
                                            "read auto brake cal done flag failed, rc=%d\n";
                                            goto LAB_0010a8f0;
                                          }
                                          if ((char)local_f0 < '\0') {
                                            _dev_info(*param_1,"auto brake calibration is done\n");
                                            break;
                                          }
                                          usleep_range_state(20000,0x4e21,2);
                                          bVar5 = iVar8 != -1;
                                          iVar8 = iVar8 + 1;
                                        } while (bVar5);
                                      }
                                    }
                                  }
                                }
                              }
                            }
                            uVar10 = *(int *)puVar1 + (uint)(byte)local_78 & 0xffff;
                            iVar8 = regmap_bulk_write(*puVar16,uVar10,uVar23,1);
                            if (iVar8 < 0) {
                              _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar8);
                            }
                            uVar10 = *(int *)puVar1 + (uint)local_78._2_1_ & 0xffff;
                            iVar8 = regmap_bulk_write(*puVar16,uVar10,uVar22,1);
                            if (iVar8 < 0) {
                              _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar8);
                            }
                            uVar10 = *(int *)puVar1 + (uint)local_78._4_1_ & 0xffff;
                            iVar8 = regmap_bulk_write(*puVar16,uVar10,uVar19,1);
                            if (iVar8 < 0) {
                              _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar8);
                            }
                            uVar10 = *(int *)puVar1 + (uint)local_78._6_1_ & 0xffff;
                            iVar8 = regmap_bulk_write(*puVar16,uVar10,uVar18,1);
                            if (iVar8 < 0) {
                              _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar8);
                            }
                            if (-1 < iVar7) goto LAB_0010a734;
                            goto LAB_0010a720;
                          }
                        }
                      }
                    }
                    _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar10,iVar7);
                    goto LAB_0010a720;
                  }
                  uVar9 = *param_1;
                  pcVar11 = "set PTRN1_LSBx for auto brake cal failed, rc=%d\n";
                }
              }
            }
            _dev_err(uVar9,pcVar11,iVar7);
          }
LAB_0010a720:
          uVar9 = *param_1;
          pcVar11 = "Run auto brake calibration failed, rc=%d\n";
          goto LAB_0010a72c;
        }
      }
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar7);
    }
    uVar9 = *param_1;
    pcVar11 = "Detect LRA frequency failed, rc=%d\n";
  }
LAB_0010a72c:
  _dev_err(uVar9,pcVar11,iVar7);
LAB_0010a734:
  local_e8 = CONCAT71(local_e8._1_7_,7);
  uVar10 = *(int *)(param_1 + 0x69) + 0x66U & 0xffff;
  iVar8 = regmap_bulk_write(param_1[1],uVar10,&local_e8,1);
  if (iVar8 < 0) {
    _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar10,iVar8);
  }
  *(undefined1 *)(param_1 + 0x1c) = 0;
  mutex_unlock(param_1 + 0x14);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// haptics_config_openloop_lra_period @ 0010a9cc size=304
// signature: undefined haptics_config_openloop_lra_period(void)
// callers: [haptics_probe, haptics_start_lra_calibrate, haptics_hw_init]
//------------------------------------------------------------

int haptics_config_openloop_lra_period(undefined8 *param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  byte local_40 [4];
  byte local_3c;
  undefined1 local_3b;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  param_2 = param_2 & 0xffffffff;
  local_40[0] = 0;
  if ((*(byte *)(param_1 + 0x6b) >> 2 & 1) == 0) {
LAB_0010aa50:
    uVar1 = *(int *)(param_1 + 0x69) + 0x5cU & 0xffff;
    local_3c = (byte)((param_2 & 0xffffffff) / 0x500) & 0xf;
    local_3b = (undefined1)((param_2 & 0xffffffff) / 5);
    iVar3 = regmap_bulk_write(param_1[1],uVar1,&local_3c,2);
    if (-1 < iVar3) goto LAB_0010aa94;
    uVar4 = *param_1;
    pcVar5 = "write addr %#x failed, rc=%d\n";
  }
  else {
    uVar1 = *(int *)(param_1 + 0x69) + 0x72U & 0xffff;
    iVar3 = regmap_bulk_read(param_1[1],uVar1,local_40,1);
    if (-1 < iVar3) {
      if ((local_40[0] & 0xc) == 4) {
        param_2 = (param_2 << 10) / 1000;
      }
      goto LAB_0010aa50;
    }
    uVar4 = *param_1;
    pcVar5 = "read addr %#x failed, rc=%d\n";
  }
  _dev_err(uVar4,pcVar5,uVar1,iVar3);
LAB_0010aa94:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// haptics_set_manual_rc_clk_cal @ 0010aafc size=232
// signature: undefined haptics_set_manual_rc_clk_cal(void)
// callers: [haptics_probe, haptics_set_fifo, richtap_load_prebake]
//------------------------------------------------------------

int haptics_set_manual_rc_clk_cal(undefined8 *param_1)

{
  uint uVar1;
  short sVar2;
  long lVar3;
  int iVar4;
  byte local_3c;
  undefined1 local_3b;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  sVar2 = *(short *)((long)param_1 + 0x5c);
  if (sVar2 != 0) {
    local_3c = (byte)((ushort)sVar2 >> 8) & 3;
    local_3b = (undefined1)sVar2;
    uVar1 = *(int *)(param_1 + 0x69) + 0x5eU & 0xffff;
    iVar4 = regmap_bulk_write(param_1[1],uVar1,&local_3c,2);
    if (iVar4 < 0) {
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar1,iVar4);
      goto LAB_0010ab90;
    }
    local_3c = 8;
    regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 0x72U & 0xffff,0xc,8,0,0,0);
  }
  iVar4 = 0;
LAB_0010ab90:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// get_max_fifo_samples @ 0010abe4 size=104
// signature: undefined get_max_fifo_samples(void)
// callers: [haptics_probe, fifo_empty_irq_handler]
//------------------------------------------------------------

int get_max_fifo_samples(long param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x368);
  if (iVar1 == 2) {
    iVar1 = 0x280;
  }
  else if (iVar1 == 4) {
    iVar1 = 0x280;
    if (*(int *)(param_1 + 0xec) != 0) {
      iVar1 = *(int *)(param_1 + 0xec);
    }
  }
  else if (iVar1 == 3) {
    iVar1 = 0x400;
  }
  else {
    _printk(&DAT_00111ba3);
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// haptics_parse_per_effect_dt @ 0010ac4c size=2848
// signature: undefined haptics_parse_per_effect_dt(void)
// callers: [haptics_probe]
//------------------------------------------------------------

int haptics_parse_per_effect_dt(undefined8 *param_1,undefined8 param_2,long *param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 *puVar8;
  long *plVar9;
  char *pcVar10;
  char cVar11;
  undefined8 uVar12;
  int iVar13;
  uint local_b0;
  uint local_ac;
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
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_b0 = 0;
  if (param_3 == (long *)0x0) {
    iVar2 = -0x16;
    goto LAB_0010b644;
  }
  *(undefined4 *)((long)param_3 + 0x1c) = *(undefined4 *)((long)param_1 + 0x34);
  iVar2 = of_property_read_variable_u32_array(param_2,"qcom,wf-vmax-mv",&local_b0,1,0);
  if (iVar2 < 0) {
    uVar3 = *(uint *)((long)param_3 + 0x1c);
  }
  else {
    *(uint *)((long)param_3 + 0x1c) = local_b0;
    uVar3 = local_b0;
  }
  if (11000 < uVar3) {
    _dev_err(*param_1,"qcom,wf-vmax-mv (%d) exceed the max value: %d\n",uVar3,11000);
    iVar2 = -0x16;
    goto LAB_0010b644;
  }
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
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)((long)param_1 + 0x3c);
  uVar3 = of_property_count_elems_of_size(param_2,"qcom,wf-pattern-data",4);
  local_ac = uVar3;
  if ((int)uVar3 < 1) {
    lVar7 = *param_3;
LAB_0010b170:
    if (lVar7 == 0) {
      iVar5 = of_property_count_elems_of_size(param_2,"qcom,wf-fifo-data",1);
      local_a8 = CONCAT44(local_a8._4_4_,iVar5);
      if (0 < iVar5) {
        lVar7 = devm_kmalloc(*param_1,0x18,0xdc0);
        param_3[1] = lVar7;
        if (lVar7 == 0) {
LAB_0010b580:
          iVar2 = -0xc;
        }
        else {
          uVar6 = devm_kmalloc(*param_1,iVar5,0xdc0);
          *(undefined8 *)param_3[1] = uVar6;
          if (*(long *)param_3[1] == 0) goto LAB_0010b580;
          iVar2 = of_property_read_variable_u8_array
                            (param_2,"qcom,wf-fifo-data",*(long *)param_3[1],iVar5,0);
          if (iVar2 < 0) {
            uVar6 = *param_1;
            pcVar10 = "Read wf-fifo-data failed, rc=%d\n";
LAB_0010b5fc:
            _dev_err(uVar6,pcVar10,iVar2);
          }
          else {
            *(int *)(param_3[1] + 8) = iVar5;
            *(undefined4 *)(param_3[1] + 0xc) = 0;
            iVar2 = of_property_read_variable_u32_array(param_2,"qcom,wf-fifo-period",&local_a8,1,0)
            ;
            if (iVar2 < 0) {
              uVar6 = *param_1;
              pcVar10 = "Get qcom,wf-fifo-period failed, rc=%d\n";
              goto LAB_0010b5fc;
            }
            if ((int)(uint)local_a8 < 0xe) {
              *(uint *)(param_3[1] + 0xc) = (uint)local_a8;
              plVar9 = (long *)param_3[1];
              if (plVar9 == (long *)0x0) {
switchD_0010b2a4_caseD_4:
                uVar3 = 0xffffffea;
              }
              else {
                iVar5 = (int)plVar9[1];
                iVar2 = iVar5 + -1;
                if (-1 < iVar2) {
                  iVar2 = 0;
                }
                iVar13 = iVar5 + 1;
                do {
                  uVar3 = iVar13 - 2;
                  if ((int)uVar3 < 1) {
                    iVar13 = iVar2 + 1;
                    break;
                  }
                  iVar13 = iVar13 + -1;
                } while (*(char *)(*plVar9 + (ulong)uVar3) == '\0');
                if (0xd < *(uint *)((long)plVar9 + 0xc)) goto switchD_0010b2a4_caseD_4;
                uVar3 = iVar13 * *(int *)((long)param_1 + 0x3c);
                switch(*(uint *)((long)plVar9 + 0xc)) {
                case 0:
                  break;
                case 1:
                  uVar3 = uVar3 >> 1;
                  break;
                case 2:
                  uVar3 = uVar3 >> 2;
                  break;
                case 3:
                  uVar3 = uVar3 >> 3;
                  break;
                default:
                  goto switchD_0010b2a4_caseD_4;
                case 8:
                  uVar3 = (uint)(iVar5 * 1000) >> 3;
                  break;
                case 9:
                  uVar3 = (uint)(iVar5 * 1000) >> 4;
                  break;
                case 10:
                  uVar3 = (uint)(iVar5 * 1000) / 0x18;
                  break;
                case 0xb:
                  uVar3 = (uint)(iVar5 * 1000) >> 5;
                  break;
                case 0xc:
                  uVar3 = (uint)(iVar5 * 10000) / 0x1b9;
                  break;
                case 0xd:
                  uVar3 = (uint)(iVar5 * 1000) / 0x30;
                }
              }
              *(uint *)(plVar9 + 2) = uVar3;
              if (*(int *)(param_3[1] + 0x10) != -0x16) {
                *(undefined4 *)((long)param_3 + 0x24) = 0;
                lVar7 = of_find_property(param_2,"qcom,wf-fifo-preload",0);
                *(bool *)(param_3[1] + 0x14) = lVar7 != 0;
                goto LAB_0010b2f0;
              }
              _dev_err(*param_1,"get fifo play length failed\n");
            }
            else {
              _dev_err(*param_1,"FIFO playing period %d is not supported\n");
            }
            iVar2 = -0x16;
          }
        }
        uVar6 = *param_1;
        pcVar10 = "parse effect FIFO data failed, rc=%d\n";
        goto LAB_0010b63c;
      }
    }
LAB_0010b2f0:
    if ((*param_3 == 0) && (param_3[1] == 0)) {
      _dev_err(*param_1,"no pattern specified for effect %d\n",(int)param_3[3]);
      iVar2 = -0x16;
      goto LAB_0010b644;
    }
    puVar8 = (undefined8 *)devm_kmalloc(*param_1,0x1c,0xdc0);
    param_3[2] = (long)puVar8;
    if (puVar8 == (undefined8 *)0x0) {
      iVar2 = -0xc;
    }
    else {
      uVar6 = param_1[4];
      uVar12 = param_1[5];
      uVar4 = *(undefined4 *)(param_1 + 6);
      *puVar8 = param_1[3];
      puVar8[2] = uVar12;
      *(undefined4 *)(puVar8 + 3) = uVar4;
      puVar8[1] = uVar6;
      of_property_read_variable_u32_array(param_2,"qcom,wf-brake-mode",puVar8 + 1,1,0);
      lVar7 = param_3[2];
      uVar3 = *(uint *)(lVar7 + 8);
      if (uVar3 < 4) {
        if (*(int *)(lVar7 + 0xc) == 1) {
          of_property_read_variable_u32_array(param_2,"qcom,wf-brake-sine-gain",lVar7 + 0x10,1,0);
          uVar3 = *(uint *)(param_3[2] + 0x10);
          if (3 < uVar3) {
            uVar6 = *param_1;
            pcVar10 = "can\'t support brake sine gain: %d\n";
            goto LAB_0010b594;
          }
        }
        lVar7 = of_find_property(param_2,"qcom,wf-brake-disable",0);
        *(bool *)(param_3[2] + 0x18) = lVar7 != 0;
        iVar2 = of_property_count_elems_of_size(param_2,"qcom,wf-brake-pattern",1);
        if (iVar2 < 9) {
          pcVar10 = (char *)param_3[2];
          if (iVar2 < 1) {
            if (*(uint *)(pcVar10 + 8) < 2) {
LAB_0010b468:
              cVar11 = '\x01';
LAB_0010b46c:
              pcVar10[0x18] = cVar11;
              pcVar10 = (char *)param_3[2];
            }
          }
          else {
            pcVar10[0] = '\0';
            pcVar10[1] = '\0';
            pcVar10[2] = '\0';
            pcVar10[3] = '\0';
            pcVar10[4] = '\0';
            pcVar10[5] = '\0';
            pcVar10[6] = '\0';
            pcVar10[7] = '\0';
            iVar2 = of_property_read_variable_u8_array
                              (param_2,"qcom,wf-brake-pattern",param_3[2],iVar2,0);
            if (iVar2 < 0) {
              _dev_err(*param_1,"Read wf-brake-pattern failed, rc=%d\n",iVar2);
              goto LAB_0010b59c;
            }
            pcVar10 = (char *)param_3[2];
            if ((*(uint *)(pcVar10 + 8) & 0xfffffffe) != 2) {
              if (((((pcVar10[7] == '\0') && (pcVar10[6] == '\0')) && (pcVar10[5] == '\0')) &&
                  ((pcVar10[4] == '\0' && (pcVar10[3] == '\0')))) &&
                 ((pcVar10[2] == '\0' && (pcVar10[1] == '\0')))) goto LAB_0010b468;
              cVar11 = '\0';
              goto LAB_0010b46c;
            }
          }
          if ((pcVar10 == (char *)0x0) || (pcVar10[0x18] != '\0')) {
            uVar3 = 0;
          }
          else if ((*(uint *)(pcVar10 + 8) & 0xfffffffe) == 2) {
            uVar3 = (*(uint *)((long)param_1 + 0x3c) & 0xfffffff) << 3;
          }
          else {
            if (pcVar10[7] == '\0') {
              if (pcVar10[6] == '\0') {
                if (pcVar10[5] == '\0') {
                  if (pcVar10[4] == '\0') {
                    if (pcVar10[3] == '\0') {
                      if (pcVar10[2] == '\0') {
                        if (pcVar10[1] == '\0') {
                          uVar3 = (uint)(*pcVar10 != '\0');
                        }
                        else {
                          uVar3 = 2;
                        }
                      }
                      else {
                        uVar3 = 3;
                      }
                    }
                    else {
                      uVar3 = 4;
                    }
                  }
                  else {
                    uVar3 = 5;
                  }
                }
                else {
                  uVar3 = 6;
                }
              }
              else {
                uVar3 = 7;
              }
            }
            else {
              uVar3 = 8;
            }
            uVar3 = uVar3 * *(uint *)((long)param_1 + 0x3c) >> 1;
          }
          *(uint *)(pcVar10 + 0x14) = uVar3;
          if (*(char *)((long)param_1 + 100) == '\0') {
            lVar7 = of_find_property(param_2,"qcom,wf-auto-res-disable",0);
            iVar2 = 0;
            *(bool *)((long)param_3 + 0x2c) = lVar7 != 0;
          }
          else {
            iVar2 = 0;
          }
          goto LAB_0010b644;
        }
        uVar6 = *param_1;
        pcVar10 = "more than %d brake samples\n";
        uVar3 = 8;
      }
      else {
        uVar6 = *param_1;
        pcVar10 = "can\'t support brake mode: %d\n";
      }
LAB_0010b594:
      _dev_err(uVar6,pcVar10,uVar3);
      iVar2 = -0x16;
    }
LAB_0010b59c:
    uVar6 = *param_1;
    pcVar10 = "parse effect brake data failed, rc=%d\n";
  }
  else {
    uVar6 = *param_1;
    if (uVar3 < 0x19) {
      lVar7 = devm_kmalloc(uVar6,0x6c,0xdc0);
      *param_3 = lVar7;
      if (lVar7 == 0) {
        iVar2 = -0xc;
      }
      else {
        iVar2 = of_property_read_variable_u32_array
                          (param_2,"qcom,wf-pattern-data",&local_a8,uVar3,0);
        if (-1 < iVar2) {
          if (2 < uVar3) {
            if (((0x1ff < (uint)local_a8) || (6 < local_a8._4_4_)) || (1 < (uint)local_a0)) {
LAB_0010b08c:
              uVar6 = *param_1;
              pcVar10 = 
              "allowed tuples: [amplitude(<= 0x1ff) period(<=6(T_LRA_X_8)) f_lra_x2(0,1)]\n";
              goto LAB_0010b53c;
            }
            *(short *)*param_3 = (short)local_a8;
            *(uint *)(*param_3 + 4) = local_a8._4_4_;
            *(bool *)(*param_3 + 8) = (uint)local_a0 != 0;
            if (5 < (int)local_ac) {
              if (((0x1ff < local_a0._4_4_) || (6 < (uint)local_98)) || (1 < local_98._4_4_))
              goto LAB_0010b08c;
              *(short *)(*param_3 + 0xc) = (short)((ulong)local_a0 >> 0x20);
              *(uint *)(*param_3 + 0x10) = (uint)local_98;
              *(bool *)(*param_3 + 0x14) = local_98._4_4_ != 0;
              if (8 < (int)local_ac) {
                if (((0x1ff < (uint)local_90) || (6 < local_90._4_4_)) || (1 < (uint)local_88))
                goto LAB_0010b08c;
                *(short *)(*param_3 + 0x18) = (short)local_90;
                *(uint *)(*param_3 + 0x1c) = local_90._4_4_;
                *(bool *)(*param_3 + 0x20) = (uint)local_88 != 0;
                if (0xb < (int)local_ac) {
                  if (((0x1ff < local_88._4_4_) || (6 < (uint)local_80)) || (1 < local_80._4_4_))
                  goto LAB_0010b08c;
                  *(short *)(*param_3 + 0x24) = (short)((ulong)local_88 >> 0x20);
                  *(uint *)(*param_3 + 0x28) = (uint)local_80;
                  *(bool *)(*param_3 + 0x2c) = local_80._4_4_ != 0;
                  if (0xe < (int)local_ac) {
                    if (((0x1ff < (uint)local_78) || (6 < local_78._4_4_)) || (1 < (uint)local_70))
                    goto LAB_0010b08c;
                    *(short *)(*param_3 + 0x30) = (short)local_78;
                    *(uint *)(*param_3 + 0x34) = local_78._4_4_;
                    *(bool *)(*param_3 + 0x38) = (uint)local_70 != 0;
                    if (0x11 < (int)local_ac) {
                      if (((0x1ff < local_70._4_4_) || (6 < (uint)local_68)) || (1 < local_68._4_4_)
                         ) goto LAB_0010b08c;
                      *(short *)(*param_3 + 0x3c) = (short)((ulong)local_70 >> 0x20);
                      *(uint *)(*param_3 + 0x40) = (uint)local_68;
                      *(bool *)(*param_3 + 0x44) = local_68._4_4_ != 0;
                      if (0x14 < (int)local_ac) {
                        if (((0x1ff < (uint)local_60) || (6 < local_60._4_4_)) ||
                           (1 < (uint)local_58)) goto LAB_0010b08c;
                        *(short *)(*param_3 + 0x48) = (short)local_60;
                        *(uint *)(*param_3 + 0x4c) = local_60._4_4_;
                        *(bool *)(*param_3 + 0x50) = (uint)local_58 != 0;
                        if (0x17 < (int)local_ac) {
                          if (((0x1ff < local_58._4_4_) || (6 < (uint)local_50)) ||
                             (1 < local_50._4_4_)) goto LAB_0010b08c;
                          *(short *)(*param_3 + 0x54) = (short)((ulong)local_58 >> 0x20);
                          *(uint *)(*param_3 + 0x58) = (uint)local_50;
                          *(bool *)(*param_3 + 0x5c) = local_50._4_4_ != 0;
                          if (0x1a < (int)local_ac) {
                    /* WARNING: Does not return */
                            pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10b76c);
                            (*pcVar1)();
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          lVar7 = of_find_property(param_2,"qcom,wf-pattern-preload",0);
          *(bool *)(*param_3 + 0x68) = lVar7 != 0;
          *(undefined4 *)((long)param_3 + 0x24) = 2;
          if (*(char *)(*param_3 + 0x68) == '\0') {
LAB_0010b074:
            if (*(char *)((long)param_1 + 100) != '\0') goto LAB_0010b07c;
LAB_0010b108:
            uVar4 = *(undefined4 *)((long)param_1 + 0x3c);
          }
          else {
            if (*(int *)((long)param_1 + 0x54) == -0x16) {
              *(int *)((long)param_1 + 0x54) = (int)param_3[3];
              *(undefined4 *)((long)param_3 + 0x24) = 3;
              goto LAB_0010b074;
            }
            _dev_err(*param_1,"effect %d has been defined as preloaded\n");
            *(undefined1 *)(*param_3 + 0x68) = 0;
            if (*(char *)((long)param_1 + 100) == '\0') goto LAB_0010b108;
LAB_0010b07c:
            uVar4 = 5000;
          }
          *(undefined4 *)(*param_3 + 0x60) = uVar4;
          iVar2 = of_property_read_variable_u32_array
                            (param_2,"qcom,wf-pattern-period-us",&local_ac,1,0);
          if (-1 < iVar2) {
            *(uint *)(*param_3 + 0x60) = local_ac;
          }
          if (*(uint *)(*param_3 + 0x60) < 0x4ffc) {
            uVar4 = get_pattern_play_length_us();
            *(undefined4 *)(*param_3 + 100) = uVar4;
            lVar7 = *param_3;
            if (*(int *)(lVar7 + 100) != -0x16) goto LAB_0010b170;
            uVar6 = *param_1;
            pcVar10 = "get pattern play length failed\n";
            goto LAB_0010b53c;
          }
          _dev_err(*param_1,"qcom,wf-pattern-period-us (%d) exceed the max value: %d\n",
                   *(uint *)(*param_3 + 0x60),0x4ffb);
          goto LAB_0010b540;
        }
        _dev_err(*param_1,"Read wf-pattern-data failed, rc=%d\n",iVar2);
      }
    }
    else {
      pcVar10 = "Pattern src can only play 8 samples at max\n";
LAB_0010b53c:
      _dev_err(uVar6,pcVar10);
LAB_0010b540:
      iVar2 = -0x16;
    }
    uVar6 = *param_1;
    pcVar10 = "parse effect PATTERN data failed, rc=%d\n";
  }
LAB_0010b63c:
  _dev_err(uVar6,pcVar10,iVar2);
LAB_0010b644:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// __dump_effects @ 0010b76c size=600
// signature: undefined __dump_effects(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __dump_effects(long param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long *plVar7;
  ulong uVar8;
  
  if (0 < (int)param_2) {
    uVar8 = 0;
    do {
      if (param_1 + uVar8 * 0x30 == 0) {
        return;
      }
      plVar7 = (long *)(param_1 + uVar8 * 0x30 + 8);
      if (*plVar7 != 0) {
        iVar3 = *(int *)(*plVar7 + 8) * 8 + 0x10;
        lVar4 = __kmalloc(iVar3,0xdc0);
        if (lVar4 == 0) {
          return;
        }
        uVar5 = scnprintf(lVar4,iVar3,&DAT_001120d7,"FIFO data: ");
        plVar6 = (long *)*plVar7;
        if ((int)plVar6[1] != 0) {
          uVar5 = uVar5 & 0xffffffff;
          uVar2 = 0;
          do {
            iVar1 = scnprintf(lVar4 + uVar5,iVar3 - (int)uVar5,&DAT_00113c87,
                              (long)*(char *)(*plVar6 + (long)(int)uVar2));
            plVar6 = (long *)*plVar7;
            uVar5 = (ulong)(uint)(iVar1 + (int)uVar5);
            uVar2 = uVar2 + 1;
          } while (uVar2 < *(uint *)(plVar6 + 1));
        }
        kfree(lVar4);
      }
      plVar7 = (long *)(param_1 + uVar8 * 0x30 + 0x10);
      if ((*plVar7 != 0) && (*(char *)(*plVar7 + 0x18) == '\0')) {
        lVar4 = kmalloc_trace(___arch_copy_from_user,0xdc0,0x50);
        if (lVar4 == 0) {
          return;
        }
        uVar2 = scnprintf(lVar4,0x50,&DAT_001120d7,"brake pattern: ");
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,*(undefined1 *)*plVar7);
        uVar2 = iVar3 + uVar2;
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,
                          *(undefined1 *)(*plVar7 + 1));
        uVar2 = iVar3 + uVar2;
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,
                          *(undefined1 *)(*plVar7 + 2));
        uVar2 = iVar3 + uVar2;
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,
                          *(undefined1 *)(*plVar7 + 3));
        uVar2 = iVar3 + uVar2;
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,
                          *(undefined1 *)(*plVar7 + 4));
        uVar2 = iVar3 + uVar2;
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,
                          *(undefined1 *)(*plVar7 + 5));
        uVar2 = iVar3 + uVar2;
        iVar3 = scnprintf(lVar4 + (ulong)uVar2,0x50 - uVar2,&DAT_00111da5,
                          *(undefined1 *)(*plVar7 + 6));
        scnprintf(lVar4 + (ulong)(iVar3 + uVar2),0x50 - (iVar3 + uVar2),&DAT_00111da5,
                  *(undefined1 *)(*plVar7 + 7));
        kfree(lVar4);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 != param_2);
  }
  return;
}



//------------------------------------------------------------
// haptics_get_status_data @ 0010b9c4 size=384
// signature: undefined haptics_get_status_data(void)
// callers: [haptics_enable_play, haptics_get_closeloop_lra_period, haptics_wait_hboost_ready, haptics_get_fifo_fill_status, swr_slave_reg_enable, haptics_hw_init]
//------------------------------------------------------------

int haptics_get_status_data(undefined8 *param_1,uint param_2,undefined1 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  undefined2 local_4c [2];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c[0] = (undefined2)param_2;
  uVar6 = *(int *)(param_1 + 0x69) + 0x71U & 0xffff;
  iVar2 = regmap_bulk_write(param_1[1],uVar6,(ulong)local_4c | 1,1);
  if (iVar2 < 0) {
LAB_0010ba48:
    uVar3 = *param_1;
    pcVar4 = "write addr %#x failed, rc=%d\n";
  }
  else {
    uVar6 = *(int *)(param_1 + 0x69) + 0x70U & 0xffff;
    iVar2 = regmap_bulk_write(param_1[1],uVar6,local_4c,1);
    if (iVar2 < 0) goto LAB_0010ba48;
    uVar6 = *(int *)(param_1 + 0x69) + 9U & 0xffff;
    iVar2 = regmap_bulk_read(param_1[1],uVar6,param_3,2);
    if (-1 < iVar2) {
      if (param_2 < 8) {
        pcVar5 = (&PTR_s_CAL_TLRA_CL_STS_00110908)[param_2];
      }
      else {
        pcVar4 = "FIFO_REAL_TIME_STS";
        if (param_2 != 0x8005) {
          pcVar4 = (char *)0x0;
        }
        pcVar5 = "CLAMPED_DUTY_CYCLE_STS";
        if (param_2 != 0x8003) {
          pcVar5 = pcVar4;
        }
      }
      _dev_info(*param_1,"Get status data[%s] = (%#x, %#x)\n",pcVar5,*param_3,param_3[1]);
      iVar2 = 0;
      goto LAB_0010ba64;
    }
    uVar3 = *param_1;
    pcVar4 = "read addr %#x failed, rc=%d\n";
  }
  _dev_err(uVar3,pcVar4,uVar6,iVar2);
LAB_0010ba64:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// haptics_set_vmax_mv @ 0010bbe4 size=792
// signature: undefined haptics_set_vmax_mv(void)
// callers: [haptics_set_gain_work, haptics_upload_effect, richtap_file_unlocked_ioctl, richtap_load_prebake, haptics_start_lra_calibrate, haptics_start_play, haptics_hw_init]
//------------------------------------------------------------

int haptics_set_vmax_mv(undefined8 *param_1,uint param_2)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  undefined1 local_58 [4];
  byte local_54 [4];
  undefined1 local_50 [4];
  byte local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  mutex_lock(param_1 + 0x5b);
  local_54[0] = 0;
  uVar9 = (uint)*(ushort *)((long)param_1 + 0x366);
  if (param_2 <= *(ushort *)((long)param_1 + 0x366)) {
    uVar9 = param_2;
  }
  if (*(uint *)((long)param_1 + 0x354) <= uVar9) {
    uVar9 = *(uint *)((long)param_1 + 0x354);
  }
  uVar8 = 5000;
  if (uVar9 < 0x1389 || *(char *)((long)param_1 + 0x36e) == '\0') {
    uVar8 = uVar9;
  }
  uVar9 = uVar8;
  if (param_1[0x39] == 0) {
LAB_0010bd48:
    uVar8 = 0x20;
    if (*(char *)(param_1 + 0x6e) != '\0') {
      uVar8 = 0x32;
    }
    local_58[0] = 0;
    if (uVar8 != 0) {
      local_58[0] = (undefined1)((uVar9 & 0xffff) / uVar8);
    }
    uVar8 = *(int *)(param_1 + 0x69) + 0x48U & 0xffff;
    iVar5 = regmap_bulk_write(param_1[1],uVar8,local_58,1);
    if (iVar5 < 0) {
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar8,iVar5);
      uVar6 = *param_1;
      pcVar7 = "config VMAX failed, rc=%d\n";
    }
    else {
      _dev_info(*param_1,"Set Vmax to %u mV\n",uVar9);
      iVar5 = 0;
      local_4c[0] = 0;
      if (*(int *)(param_1 + 0x6d) != 4) goto LAB_0010be74;
      iVar4 = 10;
      do {
        uVar9 = *(int *)(param_1 + 0x69) + 0xbU & 0xffff;
        iVar5 = regmap_bulk_read(param_1[1],uVar9,local_4c,1);
        if (iVar5 < 0) {
          _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar9,iVar5);
          goto LAB_0010bee8;
        }
        bVar2 = local_4c[0] & 3;
        bVar3 = local_4c[0] & 3;
        local_4c[0] = local_4c[0] & 3;
        if ((*(byte *)((long)param_1 + 0x359) & 1) == 0) {
          if ((bVar2 == 0) || (local_4c[0] == 3)) goto LAB_0010be74;
        }
        else {
          if (local_4c[0] == 3) goto LAB_0010be74;
          if (bVar3 == 0) {
            usleep_range_state(500,0x1f5,2);
            goto LAB_0010be74;
          }
        }
        usleep_range_state(1000,0x3e9,2);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (iVar5 != 0) goto LAB_0010be74;
      haptics_toggle_module_enable(param_1);
      _dev_err(*param_1,"set Vmax failed, toggle HAPTICS_EN to restore HW status\n");
      iVar5 = -0x10;
LAB_0010bee8:
      uVar6 = *param_1;
      pcVar7 = "check hpwr_status failed, rc=%d\n";
    }
  }
  else {
    iVar4 = nvmem_device_read(param_1[0x39],0x75,1,local_54);
    bVar2 = local_54[0] >> 2;
    if (iVar4 < 1) {
      bVar2 = 0;
    }
    if ((iVar4 < 0) || (*(uint *)(param_1 + 0x6d) < 4)) goto LAB_0010bd48;
    if ((bVar2 < 0xf) || (uVar8 < 0x1195)) {
      if ((bVar2 < 0xf) && (7000 < uVar8)) {
        iVar4 = 0x5dc;
      }
      else {
        iVar4 = 1000;
        if (uVar8 < 0xdad || 0xe < bVar2) {
          iVar4 = 500;
        }
      }
    }
    else {
      iVar4 = 1000;
    }
    uVar9 = *(int *)(param_1 + 0x69) + 0x67U & 0xffff;
    local_50[0] = (undefined1)((uint)(iVar4 * 0x51f) >> 0x10);
    iVar5 = regmap_bulk_write(param_1[1],uVar9,local_50,1);
    if (-1 < iVar5) {
      uVar9 = 11000 - iVar4;
      if (iVar4 + uVar8 < 0x2af9) {
        uVar9 = uVar8;
      }
      goto LAB_0010bd48;
    }
    _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar9,iVar5);
    uVar6 = *param_1;
    pcVar7 = "config VMAX_HDRM failed, rc=%d\n";
  }
  _dev_err(uVar6,pcVar7,iVar5);
LAB_0010be74:
  mutex_unlock(param_1 + 0x5b);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// haptics_toggle_module_enable @ 0010befc size=368
// signature: undefined haptics_toggle_module_enable(void)
// callers: [haptics_enable_play, haptics_upload_effect, richtap_load_prebake, haptics_set_vmax_mv, swr_slave_reg_enable]
//------------------------------------------------------------

int haptics_toggle_module_enable(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  usleep_range_state(100,0x65,2);
  local_44[0] = 0;
  uVar3 = *(int *)(param_1 + 0x69) + 0x46U & 0xffff;
  iVar2 = regmap_bulk_write(param_1[1],uVar3,local_44,1);
  if (iVar2 < 0) {
    _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar3,iVar2);
  }
  else {
    local_40[0] = 7;
    uVar3 = *(int *)(param_1 + 0x69) + 0x66U & 0xffff;
    iVar2 = regmap_bulk_write(param_1[1],uVar3,local_40,1);
    if (iVar2 < 0) {
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar3,iVar2);
    }
    uVar3 = 500;
    if (*(uint *)(param_1 + 0x6d) < 4) {
      uVar3 = 100;
    }
    usleep_range_state(uVar3,uVar3 | 1,2);
    local_3c[0] = 0x80;
    uVar3 = *(int *)(param_1 + 0x69) + 0x46U & 0xffff;
    iVar2 = regmap_bulk_write(param_1[1],uVar3,local_3c,1);
    if (iVar2 < 0) {
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar3,iVar2);
    }
    else {
      iVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// haptics_get_closeloop_lra_period @ 0010c06c size=1000
// signature: undefined haptics_get_closeloop_lra_period(void)
// callers: [haptics_start_lra_calibrate, haptics_hw_init]
//------------------------------------------------------------

int haptics_get_closeloop_lra_period(undefined8 *param_1,ulong param_2)

{
  ulong uVar1;
  byte bVar2;
  uint uVar3;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  byte bVar6;
  int iVar7;
  undefined8 uVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  undefined2 uVar12;
  byte bVar13;
  ulong uVar14;
  long lVar15;
  ulong uVar16;
  ulong uVar17;
  undefined2 local_4c;
  long local_48;
  
  lVar15 = sp_el0;
  local_48 = *(long *)(lVar15 + 0x638);
  local_4c = 0;
  uVar10 = *(int *)(param_1 + 0x69) + 0x72U & 0xffff;
  iVar7 = regmap_bulk_read(param_1[1],uVar10,&local_4c,1);
  if (iVar7 < 0) {
    uVar8 = *param_1;
    pcVar9 = "read addr %#x failed, rc=%d\n";
LAB_0010c320:
    _dev_err(uVar8,pcVar9,uVar10,iVar7);
    goto LAB_0010c210;
  }
  bVar13 = (byte)local_4c;
  if (((param_2 & 1) == 0) || ((*(uint *)(param_1 + 0x6d) & 0xfffffffe) != 2)) {
    iVar7 = haptics_get_status_data(param_1,0,&local_4c);
    if (iVar7 < 0) goto LAB_0010c210;
  }
  else {
    if (param_1[0x39] == 0) {
      iVar7 = -0x16;
      goto LAB_0010c210;
    }
    iVar7 = nvmem_device_read(param_1[0x39],0x46,2,&local_4c);
    uVar8 = *param_1;
    if (iVar7 < 0) {
      pcVar9 = "read SDAM %#x failed, rc=%d\n";
      uVar10 = 0x46;
      goto LAB_0010c320;
    }
    _dev_info(uVar8,"read calibration result from SDAM 0x%x, 0x%x\n",(byte)local_4c,local_4c._1_1_);
  }
  bVar6 = (byte)local_4c;
  uVar16 = (ulong)(byte)local_4c;
  uVar17 = (ulong)local_4c._1_1_;
  iVar7 = haptics_get_status_data(param_1,4,&local_4c);
  if (iVar7 < 0) goto LAB_0010c210;
  bVar2 = bVar13 >> 2 & 3;
  bVar13 = bVar6 >> 5 & 1;
  uVar14 = (ulong)local_4c._1_1_ | ((ulong)(byte)local_4c & 0x1f) << 8;
  if ((bVar2 == 0) && ((bVar6 >> 5 & 1) == 0)) {
    lVar15 = uVar14 * 0x196fb800000000;
LAB_0010c348:
    uVar17 = (ulong)(lVar15 >> 0x20) / 1000000;
    uVar16 = uVar17 & 0xffffffff;
    *(int *)(param_1 + 8) = (int)uVar17;
  }
  else {
    uVar17 = uVar17 | (uVar16 & 0x1f) << 8;
    if ((bVar2 == 0) && ((bVar6 >> 5 & 1) != 0)) {
      lVar15 = uVar17 * 0x32db8800000000;
      goto LAB_0010c348;
    }
    if (bVar2 != 1) {
      bVar13 = 1;
    }
    if (bVar13 == 0) {
      uVar10 = *(int *)(param_1 + 0x69) + 0x5cU & 0xffff;
      iVar7 = regmap_bulk_read(param_1[1],uVar10,&local_4c,2);
      if (iVar7 < 0) {
        uVar8 = *param_1;
        pcVar9 = "read addr %#x failed, rc=%d\n";
        goto LAB_0010c320;
      }
      iVar7 = -0x16;
      uVar1 = (ulong)local_4c._1_1_ | ((ulong)(byte)local_4c & 0xf) << 8;
      uVar10 = 0x196e6b;
      if ((*(uint *)(param_1 + 0x6b) & 4) != 0) {
        uVar10 = 0x18d634;
      }
      uVar16 = 0;
      if (uVar17 != 0) {
        uVar16 = ((ulong)uVar10 * uVar1 * uVar14) / uVar17;
      }
      uVar16 = uVar16 / 1000000;
      uVar10 = *(uint *)((long)param_1 + 0x3c);
      iVar11 = (int)uVar16;
      *(int *)(param_1 + 8) = iVar11;
      if ((uVar10 == 0) || (iVar11 == 0)) goto LAB_0010c210;
      uVar3 = 0x53d64;
      if ((*(uint *)(param_1 + 0x6b) & 4) != 0) {
        uVar3 = 360000;
      }
      uVar14 = 0;
      if (uVar1 != 0) {
        uVar14 = ((ulong)uVar3 * (ulong)(uint)(iVar11 * (int)uVar17)) / uVar1;
      }
      uVar17 = 0x6fd60fba1a362c;
    }
    else {
      if ((bVar2 != 1) || ((bVar6 >> 5 & 1) == 0)) {
        _dev_err(*param_1,"Can\'t get close-loop LRA period in rc_clk_cal mode %u\n");
        iVar7 = -0x16;
        goto LAB_0010c210;
      }
      iVar7 = haptics_get_status_data(param_1,3,&local_4c);
      if (iVar7 < 0) goto LAB_0010c210;
      iVar7 = -0x16;
      uVar1 = (ulong)local_4c._1_1_ | ((ulong)(byte)local_4c & 0x1f) << 8;
      uVar10 = 0xcb735;
      if ((*(uint *)(param_1 + 0x6b) & 4) != 0) {
        uVar10 = 0xc6b1a;
      }
      uVar16 = 0;
      if (uVar17 != 0) {
        uVar16 = ((ulong)uVar10 * uVar1 * uVar1) / uVar17;
      }
      uVar16 = uVar16 / 1000000;
      uVar10 = *(uint *)((long)param_1 + 0x3c);
      iVar11 = (int)uVar16;
      *(int *)(param_1 + 8) = iVar11;
      if ((uVar10 == 0) || (iVar11 == 0)) goto LAB_0010c210;
      uVar3 = 0x53d64;
      if ((*(uint *)(param_1 + 0x6b) & 4) != 0) {
        uVar3 = 360000;
      }
      uVar14 = 0;
      if (uVar1 != 0) {
        uVar14 = ((ulong)uVar3 * (ulong)(uint)(iVar11 * (int)uVar17)) / uVar1;
      }
      uVar17 = 0xdfac1f74346c58;
    }
    auVar4._8_8_ = 0;
    auVar4._0_8_ = uVar14;
    auVar5._8_8_ = 0;
    auVar5._0_8_ = uVar17;
    uVar12 = 0;
    if ((ulong)uVar10 != 0) {
      uVar12 = (undefined2)(SUB168(auVar4 * auVar5,8) / (ulong)uVar10);
    }
    *(undefined2 *)((long)param_1 + 0x5c) = uVar12;
  }
  uVar10 = *(uint *)((long)param_1 + 0x3c);
  uVar17 = (ulong)uVar10;
  iVar11 = uVar10 - (int)uVar16;
  iVar7 = -iVar11;
  if (-1 < iVar11) {
    iVar7 = iVar11;
  }
  uVar3 = 0;
  if (uVar10 != 0) {
    uVar3 = (uint)(iVar7 * 100) / uVar10;
  }
  if (uVar3 < 0x15) {
    uVar12 = *(undefined2 *)((long)param_1 + 0x5c);
  }
  else {
    _dev_warn(*param_1,
              "The calibrated period (%d us) has large variation, use open-loop LRA period (%d us) instead\n"
              ,uVar16,uVar10);
    uVar16 = (ulong)*(uint *)((long)param_1 + 0x3c);
    uVar12 = 0;
    *(undefined2 *)((long)param_1 + 0x5c) = 0;
    *(uint *)(param_1 + 8) = *(uint *)((long)param_1 + 0x3c);
    uVar17 = uVar16;
  }
  _dev_info(*param_1,"OL_TLRA %u us, CL_TLRA %u us, RC_CLK_CAL_COUNT %#x\n",uVar17,uVar16,uVar12);
  iVar7 = 0;
LAB_0010c210:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// haptics_update_memory_data @ 0010c454 size=516
// signature: undefined haptics_update_memory_data(void)
// callers: [fifo_empty_irq_handler, haptics_hw_init, haptics_update_fifo_samples]
//------------------------------------------------------------

int haptics_update_memory_data(undefined8 *param_1,void *param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  if (param_3 != 0) {
    if (3 < param_3) {
      uVar6 = param_3 >> 2;
      do {
        uVar5 = *(int *)((long)param_1 + 0x34c) + 0x20U & 0xffff;
        iVar2 = regmap_bulk_write(param_1[1],uVar5,param_2,4);
        if (iVar2 < 0) {
          _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar5,iVar2);
          uVar3 = *param_1;
          pcVar4 = "bulk write FIFO_DIN failed, rc=%d\n";
          goto LAB_0010c648;
        }
        param_2 = (void *)((long)param_2 + 4);
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    uVar6 = param_3 & 3;
    if ((param_3 & 3) != 0) {
      if (*(int *)(param_1 + 0x6d) == 2) {
        memcpy(&local_4c,param_2,(ulong)uVar6);
        uVar6 = *(int *)((long)param_1 + 0x34c) + 0x20U & 0xffff;
        iVar2 = regmap_bulk_write(param_1[1],uVar6,&local_4c,4);
        if (-1 < iVar2) goto LAB_0010c5c0;
        _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar6,iVar2);
        uVar3 = *param_1;
        pcVar4 = "write FIFO_DIN failed, rc=%d\n";
      }
      else {
        uVar5 = *(int *)((long)param_1 + 0x34c) + 0x2cU & 0xffff;
        iVar2 = regmap_bulk_write(param_1[1],uVar5,param_2,1);
        if (-1 < iVar2) {
          if (uVar6 != 1) {
            uVar5 = *(int *)((long)param_1 + 0x34c) + 0x2cU & 0xffff;
            iVar2 = regmap_bulk_write(param_1[1],uVar5,(long)param_2 + 1,1);
            if (iVar2 < 0) goto LAB_0010c620;
            if (uVar6 != 2) {
              uVar5 = *(int *)((long)param_1 + 0x34c) + 0x2cU & 0xffff;
              iVar2 = regmap_bulk_write(param_1[1],uVar5,(long)param_2 + 2,1);
              if (iVar2 < 0) goto LAB_0010c620;
            }
          }
          goto LAB_0010c5bc;
        }
LAB_0010c620:
        _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar5,iVar2);
        uVar3 = *param_1;
        pcVar4 = "write FIFO_DIN_1B failed, rc=%d\n";
      }
LAB_0010c648:
      _dev_err(uVar3,pcVar4,iVar2);
      goto LAB_0010c5c0;
    }
  }
LAB_0010c5bc:
  iVar2 = 0;
LAB_0010c5c0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// swr_slave_reg_enable @ 0010c65c size=268
// signature: undefined swr_slave_reg_enable(void)
// callers: []
//------------------------------------------------------------

void swr_slave_reg_enable(void)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined2 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = rdev_get_drvdata();
  regmap_update_bits_base
            (*(undefined8 *)(lVar3 + 8),*(int *)(lVar3 + 0x348) + 0x4eU & 0xffff,0xe0,0xe0,0,0,0);
  if ((*(byte *)(lVar3 + 0x358) >> 4 & 1) != 0) {
    local_2c = 0;
    iVar2 = haptics_get_status_data(lVar3,5,&local_2c);
    uVar1 = *(int *)(lVar3 + 0x348) + 0x4bU & 0xffff;
    if ((iVar2 < 0) || ((local_2c._1_1_ & 7) != 4)) {
      regmap_update_bits_base(*(undefined8 *)(lVar3 + 8),uVar1,0x10,0,0,0,0);
    }
    else {
      regmap_update_bits_base(*(undefined8 *)(lVar3 + 8),uVar1,0x10,0x10,0,0,0);
      uVar4 = haptics_toggle_module_enable(lVar3);
      if ((int)uVar4 < 0) goto LAB_0010c73c;
    }
  }
  uVar4 = 0;
  *(undefined1 *)(lVar3 + 0x36d) = 1;
LAB_0010c73c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// swr_slave_reg_disable @ 0010c76c size=88
// signature: undefined swr_slave_reg_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_slave_reg_disable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  regmap_update_bits_base
            (*(undefined8 *)(lVar1 + 8),*(int *)(lVar1 + 0x348) + 0x4eU & 0xffff,0xe0,0,0,0,0);
  *(undefined1 *)(lVar1 + 0x36d) = 0;
  return 0;
}



//------------------------------------------------------------
// swr_slave_reg_is_enabled @ 0010c7c8 size=32
// signature: undefined swr_slave_reg_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 swr_slave_reg_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x36d);
}



//------------------------------------------------------------
// haptics_get_fifo_fill_status @ 0010c7e8 size=260
// signature: undefined haptics_get_fifo_fill_status(void)
// callers: [haptics_get_available_fifo_memory, fifo_empty_irq_handler, richtap_erase_work_proc]
//------------------------------------------------------------

void haptics_get_fifo_fill_status(undefined8 *param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  uint uVar4;
  undefined2 local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  uVar3 = haptics_get_status_data(param_1,0x8005,&local_4c);
  if (-1 < (int)uVar3) {
    iVar1 = *(int *)(param_1 + 0x6d);
    if (iVar1 == 4) {
      uVar4 = (uint)local_4c._1_1_ | ((byte)local_4c & 0xf) << 8;
    }
    else if (iVar1 == 3) {
      uVar4 = (uint)local_4c._1_1_ | ((byte)local_4c & 7) << 8;
    }
    else {
      if (iVar1 != 2) {
        _dev_err(*param_1,"HW type %d is not supported\n");
        uVar3 = 0xffffffea;
        goto LAB_0010c8a0;
      }
      uVar4 = (uint)local_4c._1_1_ | ((byte)local_4c & 3) << 8;
    }
    uVar3 = 0;
    *param_2 = uVar4;
  }
LAB_0010c8a0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// haptics_get_available_fifo_memory @ 0010c9a4 size=544
// signature: undefined haptics_get_available_fifo_memory(void)
// callers: [haptics_set_fifo, richtap_load_prebake, fifo_empty_irq_handler]
//------------------------------------------------------------

void haptics_get_available_fifo_memory(undefined8 *param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  undefined8 uVar6;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  uVar4 = haptics_get_fifo_fill_status(param_1,&local_3c);
  uVar3 = local_3c;
  if ((int)uVar4 < 0) goto LAB_0010cac8;
  iVar5 = *(int *)(param_1 + 0x6d);
  if (iVar5 == 2) {
    if (local_3c < 0x281) goto LAB_0010ca34;
  }
  else if (iVar5 == 4) {
    uVar1 = 0x280;
    if (*(uint *)((long)param_1 + 0xec) != 0) {
      uVar1 = *(uint *)((long)param_1 + 0xec);
    }
    if (local_3c <= uVar1) goto LAB_0010ca34;
  }
  else if (iVar5 == 3) {
    if (local_3c < 0x401) goto LAB_0010ca34;
  }
  else {
    _printk(&DAT_00111ba3);
    if (uVar3 == 0) {
LAB_0010ca34:
      iVar5 = *(int *)(param_1 + 0x6d);
      if (iVar5 == 2) {
        if (uVar3 != 0x280) goto LAB_0010ca88;
      }
      else if (iVar5 == 4) {
        uVar1 = 0x280;
        if (*(uint *)((long)param_1 + 0xec) != 0) {
          uVar1 = *(uint *)((long)param_1 + 0xec);
        }
        if (uVar3 != uVar1) goto LAB_0010ca88;
      }
      else if (iVar5 == 3) {
        if (uVar3 != 0x400) goto LAB_0010ca88;
      }
      else {
        _printk(&DAT_00111ba3);
        if (uVar3 != 0) {
LAB_0010ca88:
          iVar5 = *(int *)(param_1 + 0x6d);
          if (iVar5 == 2) {
            iVar5 = 0x280;
          }
          else if (iVar5 == 4) {
            iVar5 = 0x280;
            if (*(int *)((long)param_1 + 0xec) != 0) {
              iVar5 = *(int *)((long)param_1 + 0xec);
            }
          }
          else if (iVar5 == 3) {
            iVar5 = 0x400;
          }
          else {
            _printk(&DAT_00111ba3);
            iVar5 = 0;
          }
          uVar4 = (ulong)(iVar5 - uVar3);
          goto LAB_0010cac8;
        }
      }
      _dev_err(*param_1,"no FIFO space available\n");
      uVar4 = 0xfffffff0;
      goto LAB_0010cac8;
    }
  }
  iVar5 = *(int *)(param_1 + 0x6d);
  uVar6 = *param_1;
  if (iVar5 == 2) {
    iVar5 = 0x280;
  }
  else if (iVar5 == 4) {
    iVar5 = 0x280;
    if (*(int *)((long)param_1 + 0xec) != 0) {
      iVar5 = *(int *)((long)param_1 + 0xec);
    }
  }
  else if (iVar5 == 3) {
    iVar5 = 0x400;
  }
  else {
    _printk(&DAT_00111ba3);
    iVar5 = 0;
  }
  _dev_err(uVar6,"Filled FIFO number %d exceed the max %d\n",uVar3,iVar5);
  uVar4 = 0xffffffea;
LAB_0010cac8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// haptics_stop_fifo_play @ 0010cbc4 size=228
// signature: undefined haptics_stop_fifo_play(void)
// callers: [haptics_upload_effect, haptics_erase, richtap_work_proc, richtap_file_unlocked_ioctl, haptics_suspend_config, fifo_empty_irq_handler, richtap_erase_work_proc]
//------------------------------------------------------------

undefined8 haptics_stop_fifo_play(undefined8 *param_1)

{
  undefined8 uVar1;
  char *pcVar2;
  
  if (*(int *)(param_1 + 0x13) == 0) {
    pcVar2 = "FIFO playing is not in progress\n";
  }
  else {
    uVar1 = haptics_enable_play(param_1,0);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    regmap_update_bits_base(param_1[1],*(int *)((long)param_1 + 0x34c) + 0x24U & 0xffff,0xf,0,0,0,0)
    ;
    if (*(char *)((long)param_1 + 0x36c) != '\0') {
      disable_irq_nosync(*(undefined4 *)(param_1 + 0x67));
      *(undefined1 *)((long)param_1 + 0x36c) = 0;
    }
    kvfree(**(undefined8 **)(param_1[0xf] + 8));
    **(undefined8 **)(param_1[0xf] + 8) = 0;
    *(undefined4 *)(param_1 + 0x13) = 0;
    regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 0x72U & 0xffff,0xc,4,0,0,0);
    pcVar2 = "stopped FIFO playing successfully\n";
  }
  _dev_info(*param_1,pcVar2);
  return 0;
}



//------------------------------------------------------------
// haptics_update_fifo_samples @ 0010cca8 size=292
// signature: undefined haptics_update_fifo_samples(void)
// callers: [haptics_set_fifo, richtap_load_prebake, fifo_empty_irq_handler]
//------------------------------------------------------------

int haptics_update_fifo_samples(undefined8 *param_1,long param_2,undefined4 param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c[0] = 0;
  if (param_2 == 0) {
    _dev_err(*param_1,"no data available to update FIFO\n");
    iVar2 = -0x16;
    goto LAB_0010cd5c;
  }
  if ((*(int *)(param_1 + 0x6d) == 4) && ((param_4 & 1) == 0)) {
    local_4c[0] = 1;
    uVar3 = *(int *)((long)param_1 + 0x34c) + 0x2dU & 0xffff;
    iVar2 = regmap_bulk_write(param_1[1],uVar3,local_4c,1);
    if (-1 < iVar2) {
      local_4c[0] = 0;
      uVar3 = *(int *)((long)param_1 + 0x34c) + 0x2dU & 0xffff;
      iVar2 = regmap_bulk_write(param_1[1],uVar3,local_4c,1);
      if (-1 < iVar2) goto LAB_0010cd48;
    }
    _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar3,iVar2);
  }
  else {
LAB_0010cd48:
    iVar2 = haptics_update_memory_data(param_1,param_2,param_3);
  }
LAB_0010cd5c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// haptics_set_fifo_empty_threshold @ 0010cdcc size=112
// signature: undefined haptics_set_fifo_empty_threshold(void)
// callers: [fifo_empty_irq_handler]
//------------------------------------------------------------

void haptics_set_fifo_empty_threshold(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(int *)(param_1 + 0x368) - 2;
  if (uVar1 < 3) {
    uVar2 = 0;
    if (*(uint *)(&DAT_00110c1c + (long)(int)uVar1 * 4) != 0) {
      uVar2 = param_2 / *(uint *)(&DAT_00110c1c + (long)(int)uVar1 * 4);
    }
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 8),*(int *)(param_1 + 0x34c) + 0x2aU & 0xffff,0xf,
               uVar2 & 0xff,0,0,0);
  }
  else {
    _printk(&DAT_00111ba3);
  }
  return;
}



//------------------------------------------------------------
// haptics_enable_play @ 0010ce3c size=1224
// signature: undefined haptics_enable_play(void)
// callers: [haptics_stop_fifo_play, haptics_stop_constant_effect_play, haptics_erase, richtap_work_proc, richtap_file_unlocked_ioctl, haptics_suspend_config, haptics_start_lra_calibrate, haptics_playback, haptics_start_play]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x0010cecc) */

int haptics_enable_play(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  undefined8 uVar8;
  char *pcVar9;
  undefined8 uVar10;
  byte bVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  byte local_6c [4];
  undefined1 local_68 [4];
  byte local_64 [4];
  byte local_60 [4];
  undefined2 local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_6c[0] = 0;
  if ((param_2 & 1) != 0) {
    local_68[0] = 7;
    uVar14 = *(int *)(param_1 + 0x69) + 0x66U & 0xffff;
    iVar4 = regmap_bulk_write(param_1[1],uVar14,local_68,1);
    if (-1 < iVar4) goto LAB_0010cea4;
    uVar8 = *param_1;
    pcVar9 = "write addr %#x failed, rc=%d\n";
LAB_0010d120:
    _dev_err(uVar8,pcVar9,uVar14,iVar4);
    goto LAB_0010d278;
  }
LAB_0010cea4:
  local_64[0] = 0;
  uVar7 = is_boost_vreg_enabled_in_open_loop(param_1);
  if ((((((uVar7 & 1) == 0) && (*(char *)((long)param_1 + 0x371) == '\0')) && (param_1[0x4e] == 0))
      && (*(int *)(param_1 + 0x6d) != 3)) || ((param_2 & 1) == 0)) {
    uVar13 = param_2 & 1;
    uVar8 = param_1[1];
    uVar10 = 1;
    uVar14 = *(int *)(param_1 + 0x69) + 0x68;
LAB_0010cfc4:
    regmap_update_bits_base(uVar8,uVar14 & 0xffff,uVar10,uVar13,0,0,0);
  }
  else {
    if (*(int *)((long)param_1 + 0x354) == 10000) {
      uVar12 = 3;
      if (*(int *)(param_1 + 0x6d) != 4) {
        uVar12 = 1;
      }
      regmap_update_bits_base
                (param_1[1],*(int *)(param_1 + 0x69) + 0x68U & 0xffff,uVar12,uVar12,0,0,0);
    }
    uVar14 = *(int *)(param_1 + 0x69) + 0x72U & 0xffff;
    iVar4 = regmap_bulk_read(param_1[1],uVar14,local_64,1);
    if (iVar4 < 0) {
      uVar8 = *param_1;
      pcVar9 = "read addr %#x failed, rc=%d\n";
      goto LAB_0010d120;
    }
    if (((*(byte *)(param_1 + 0x6b) & 1) != 0) && ((local_64[0] & 0xc) == 4)) {
      local_64[0] = 0;
      regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 0x72U & 0xffff,0xc,0,0,0,0);
      uVar8 = param_1[1];
      uVar10 = 0xc;
      uVar13 = 4;
      uVar14 = *(int *)(param_1 + 0x69) + 0x72;
      local_64[0] = 4;
      goto LAB_0010cfc4;
    }
  }
  uVar14 = *(uint *)((long)param_1 + 0xdc);
  local_6c[0] = (byte)uVar14;
  if ((*(int *)(param_1 + 0x6d) == 4) && (uVar14 == 5)) {
    uVar14 = (*(byte *)(param_1[0x10] + 0x28) & 3) << 4 | 5;
    local_6c[0] = (byte)uVar14;
  }
  bVar11 = (byte)uVar14;
  if ((param_1[0x11] != 0) && (*(char *)(param_1[0x11] + 0x18) == '\0')) {
    local_6c[0] = bVar11 | 8;
    bVar11 = local_6c[0];
  }
  if ((param_2 & 1) != 0) {
    local_6c[0] = bVar11 | 0x80;
  }
  uVar14 = *(int *)(param_1 + 0x69) + 0x4cU & 0xffff;
  iVar4 = regmap_bulk_write(param_1[1],uVar14,local_6c,1);
  if (iVar4 < 0) {
    _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar14,iVar4);
    uVar8 = *param_1;
    pcVar9 = "Write SPMI_PLAY failed, rc=%d\n";
  }
  else {
    if ((param_2 & 1) == 0) {
      local_60[0] = 0;
      if (*(int *)(param_1 + 0x6d) == 4) {
        uVar14 = *(uint *)(param_1 + 8);
        if (uVar14 == 0) {
          uVar14 = *(uint *)((long)param_1 + 0x3c);
        }
        pcVar9 = (char *)param_1[0x11];
        uVar13 = 0;
        if (pcVar9 != (char *)0x0) {
          if (pcVar9[0x18] == '\0') {
            if ((*(uint *)(pcVar9 + 8) & 0xfffffffe) == 2) {
              uVar13 = (uVar14 & 0xfffffff) << 3;
            }
            else {
              if (pcVar9[7] == '\0') {
                if (pcVar9[6] == '\0') {
                  if (pcVar9[5] == '\0') {
                    if (pcVar9[4] == '\0') {
                      if (pcVar9[3] == '\0') {
                        if (pcVar9[2] == '\0') {
                          if (pcVar9[1] == '\0') {
                            uVar13 = (uint)(*pcVar9 != '\0');
                          }
                          else {
                            uVar13 = 2;
                          }
                        }
                        else {
                          uVar13 = 3;
                        }
                      }
                      else {
                        uVar13 = 4;
                      }
                    }
                    else {
                      uVar13 = 5;
                    }
                  }
                  else {
                    uVar13 = 6;
                  }
                }
                else {
                  uVar13 = 7;
                }
              }
              else {
                uVar13 = 8;
              }
              uVar13 = uVar13 * uVar14 >> 1;
            }
          }
          else {
            uVar13 = 0;
          }
        }
        uVar1 = uVar14 >> 1;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = (uVar13 + uVar14) / uVar1;
        }
        iVar6 = uVar2 + 1;
        do {
          usleep_range_state(uVar1,uVar1 + 1,2);
          uVar14 = *(int *)(param_1 + 0x69) + 0xbU & 0xffff;
          iVar5 = regmap_bulk_read(param_1[1],uVar14,local_60,1);
          if (iVar5 < 0) {
            _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar14,iVar5);
            _dev_err(*param_1,"read HPWR_INTF failed, rc=%d\n",iVar5);
            goto LAB_0010d254;
          }
          if ((local_60[0] & 3) == 0) {
            if (iVar6 != 0) goto LAB_0010d254;
            break;
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
        local_5c = 0;
        iVar6 = haptics_get_status_data(param_1,5,&local_5c);
        if ((iVar6 < 0) || ((local_5c._1_1_ & 7) != 4)) {
          _dev_warn(*param_1,"poll HPWR_DISABLED failed after stopped play\n");
          haptics_toggle_module_enable(param_1);
        }
      }
LAB_0010d254:
      if ((*(byte *)(param_1 + 0x6b) >> 1 & 1) != 0) {
        hrtimer_start_range_ns(param_1 + 0x4f,2000000000,0,1);
      }
      goto LAB_0010d278;
    }
    if ((*(byte *)(param_1 + 0x6b) >> 1 & 1) == 0) goto LAB_0010d278;
    iVar4 = haptics_boost_vreg_enable(param_1,1);
    if (-1 < iVar4) {
      iVar4 = 0;
      goto LAB_0010d278;
    }
    uVar8 = *param_1;
    pcVar9 = "Keep boost vreg on failed, rc=%d\n";
  }
  _dev_err(uVar8,pcVar9,iVar4);
LAB_0010d278:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// haptics_boost_vreg_enable @ 0010d39c size=300
// signature: undefined haptics_boost_vreg_enable(void)
// callers: [haptics_enable_play, haptics_disable_hbst_timer, haptics_suspend_config]
//------------------------------------------------------------

int haptics_boost_vreg_enable(undefined8 *param_1,byte param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((((param_1[0x4e] == 0) && (*(int *)(param_1 + 0x6d) != 3)) &&
      ((*(byte *)(param_1 + 0x6b) >> 1 & 1) != 0)) && (param_1[0x39] != 0)) {
    uVar3 = is_boost_vreg_enabled_in_open_loop(param_1);
    if (((uVar3 & 1) == 0) && (*(byte *)((long)param_1 + 0x371) != (param_2 & 1))) {
      local_3c[0] = 1;
      if ((param_2 & 1) == 0) {
        local_3c[0] = 2;
      }
      iVar2 = nvmem_device_write(param_1[0x39],0x42,1,local_3c);
      if (iVar2 < 0) {
        uVar4 = *param_1;
        pcVar5 = "write SDAM %#x failed, rc=%d\n";
        uVar6 = 0x42;
      }
      else {
        local_3c[0] = 1;
        iVar2 = nvmem_device_write(param_1[0x39],0xe5,1,local_3c);
        if (-1 < iVar2) {
          iVar2 = 0;
          *(byte *)((long)param_1 + 0x371) = param_2 & 1;
          goto LAB_0010d40c;
        }
        uVar4 = *param_1;
        pcVar5 = "Write SDAM %#x failed, rc=%d\n";
        uVar6 = 0xe5;
      }
      _dev_err(uVar4,pcVar5,uVar6,iVar2);
      goto LAB_0010d40c;
    }
  }
  iVar2 = 0;
LAB_0010d40c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// is_boost_vreg_enabled_in_open_loop @ 0010d4c8 size=244
// signature: undefined is_boost_vreg_enabled_in_open_loop(void)
// callers: [haptics_enable_play, haptics_boost_vreg_enable, haptics_wait_hboost_ready]
//------------------------------------------------------------

void is_boost_vreg_enabled_in_open_loop(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  byte local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = 0;
  local_2c[0] = 0;
  if (param_1[0x4e] != 0) goto LAB_0010d590;
  if (*(int *)(param_1 + 0x6d) != 3) {
    uVar4 = *(int *)(param_1 + 0x6a) + 0x46U & 0xffff;
    iVar2 = regmap_bulk_read(param_1[1],uVar4,local_2c,1);
    if (-1 < iVar2) {
      uVar4 = *(int *)(param_1 + 0x6a) + 0x41U & 0xffff;
      *(byte *)((long)param_1 + 0x371) = local_2c[0] >> 7;
      iVar2 = regmap_bulk_read(param_1[1],uVar4,local_2c,1);
      if (-1 < iVar2) {
        if ((-1 < (char)local_2c[0]) && (*(char *)((long)param_1 + 0x371) != '\0')) {
          uVar3 = 1;
          goto LAB_0010d590;
        }
        goto LAB_0010d58c;
      }
    }
    _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar4,iVar2);
  }
LAB_0010d58c:
  uVar3 = 0;
LAB_0010d590:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// haptics_enable_hpwr_vreg @ 0010d5bc size=248
// signature: undefined haptics_enable_hpwr_vreg(void)
// callers: [haptics_upload_effect, richtap_work_proc, richtap_file_unlocked_ioctl, haptics_start_lra_calibrate, haptics_start_play]
//------------------------------------------------------------

int haptics_enable_hpwr_vreg(undefined8 *param_1,byte param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if ((param_1[0x4e] == 0) || (*(byte *)((long)param_1 + 0x36f) == (param_2 & 1))) {
    return 0;
  }
  if ((param_2 & 1) == 0) {
    iVar1 = regulator_disable();
    if (iVar1 < 0) {
      uVar2 = *param_1;
      pcVar3 = "Disable hpwr failed, rc=%d\n";
      goto LAB_0010d6a8;
    }
    iVar1 = regulator_set_voltage(param_1[0x4e],0,0x7fffffff);
    if (-1 < iVar1) goto LAB_0010d664;
  }
  else {
    iVar1 = regulator_set_voltage(param_1[0x4e],*(int *)((long)param_1 + 0x33c) * 1000,0x7fffffff);
    if (-1 < iVar1) {
      iVar1 = regulator_enable(param_1[0x4e]);
      if (iVar1 < 0) {
        _dev_err(*param_1,"Enable hpwr failed, rc=%d\n",iVar1);
        regulator_set_voltage(param_1[0x4e],0,0x7fffffff);
        return iVar1;
      }
LAB_0010d664:
      *(byte *)((long)param_1 + 0x36f) = param_2 & 1;
      return 0;
    }
  }
  uVar2 = *param_1;
  pcVar3 = "Set hpwr voltage failed, rc=%d\n";
LAB_0010d6a8:
  _dev_err(uVar2,pcVar3,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// get_direct_play_max_amplitude @ 0010d6b4 size=260
// signature: undefined get_direct_play_max_amplitude(void)
// callers: [haptics_set_gain_work, haptics_upload_effect, haptics_start_lra_calibrate, haptics_start_play]
//------------------------------------------------------------

void get_direct_play_max_amplitude(undefined8 *param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  byte local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if ((param_1[0x4e] == 0) && (*(int *)(param_1 + 0x6d) != 3)) {
    uVar4 = 0xff;
  }
  else {
    local_3c[0] = 0;
    uVar4 = *(int *)(param_1 + 0x69) + 0x67U & 0xffff;
    iVar3 = regmap_bulk_read(param_1[1],uVar4,local_3c,1);
    if (iVar3 < 0) {
      _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar4,iVar3);
      _dev_err(*param_1,"Get Vmax HDRM failed, rc=%d\n",iVar3);
      uVar4 = 0;
    }
    else {
      uVar1 = *(int *)((long)param_1 + 0x33c) + (local_3c[0] & 0x7f) * -0x32;
      uVar4 = 0;
      if (uVar1 != 0) {
        uVar4 = (uint)(*(int *)((long)param_1 + 0x34) * 0xff) / uVar1;
      }
      if (0xfe < uVar4) {
        uVar4 = 0xff;
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// haptics_wait_hboost_ready @ 0010d7b8 size=444
// signature: undefined haptics_wait_hboost_ready(void)
// callers: [haptics_upload_effect, richtap_work_proc, richtap_file_unlocked_ioctl, haptics_start_play]
//------------------------------------------------------------

void haptics_wait_hboost_ready(undefined8 *param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  uint uVar7;
  int iVar8;
  byte local_50 [4];
  undefined2 local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  uVar4 = 0;
  local_50[0] = 0;
  if (param_1[0x4e] == 0) {
    if ((*(int *)(param_1 + 0x6d) != 3) && ((*(byte *)(param_1 + 0x6b) >> 1 & 1) != 0)) {
      puVar1 = param_1 + 0x4f;
      lVar5 = __hrtimer_get_remaining(puVar1,0);
      if ((lVar5 < 1) && (uVar6 = hrtimer_active(puVar1), (uVar6 & 1) == 0)) {
        iVar8 = 100;
        do {
          uVar6 = is_boost_vreg_enabled_in_open_loop(param_1);
          if ((uVar6 & 1) != 0) goto LAB_0010d834;
          mutex_lock(param_1 + 0x14);
          local_4c = 0;
          iVar3 = haptics_get_status_data(param_1,5,&local_4c);
          bVar2 = local_4c._1_1_;
          mutex_unlock(param_1 + 0x14);
          if ((-1 < iVar3) && ((bVar2 & 7) == 4)) goto LAB_0010d834;
          uVar7 = *(int *)(param_1 + 0x6a) + 0x46U & 0xffff;
          iVar3 = regmap_bulk_read(param_1[1],uVar7,local_50,1);
          if (iVar3 < 0) {
LAB_0010d87c:
            _dev_err(*param_1,"read addr %#x failed, rc=%d\n",uVar7);
          }
          else if ((iVar3 == 0) && (-1 < (char)local_50[0])) {
            uVar7 = *(int *)(param_1 + 0x6a) + 0xbU & 0xffff;
            iVar3 = regmap_bulk_read(param_1[1],uVar7,local_50,1);
            if (iVar3 < 0) goto LAB_0010d87c;
            if ((iVar3 == 0) && ((local_50[0] & 1) == 0)) goto LAB_0010d834;
          }
          usleep_range_state(200,0xc9,2);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
        _dev_err(*param_1,"hboost is not ready for haptics play\n");
        uVar4 = 0xfffffff0;
        goto LAB_0010d838;
      }
      hrtimer_cancel(puVar1);
    }
LAB_0010d834:
    uVar4 = 0;
  }
LAB_0010d838:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// haptics_set_brake @ 0010d974 size=216
// signature: undefined haptics_set_brake(void)
// callers: [haptics_upload_effect]
//------------------------------------------------------------

int haptics_set_brake(undefined8 *param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if (*(char *)(param_2 + 0x18) == '\0') {
    regmap_update_bits_base
              (param_1[1],*(int *)(param_1 + 0x69) + 0x50U & 0xffff,0xcc,
               (*(int *)(param_2 + 0x10) << 2 | *(int *)(param_2 + 8) << 6) & 0xfc,0,0,0);
    uVar1 = *(int *)((long)param_1 + 0x34c) + 0x70U & 0xffff;
    iVar2 = regmap_bulk_write(param_1[1],uVar1,param_2,8);
    iVar3 = 0;
    if (iVar2 < 0) {
      _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar1,iVar2);
      _dev_err(*param_1,"set brake pattern failed, rc=%d\n",iVar2);
      iVar3 = iVar2;
    }
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



//------------------------------------------------------------
// haptics_set_fifo @ 0010da4c size=560
// signature: undefined haptics_set_fifo(void)
// callers: [haptics_upload_effect]
//------------------------------------------------------------

uint haptics_set_fifo(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x13) == 1) {
    _dev_err(*param_1,"FIFO is busy\n");
    uVar3 = 0xfffffff0;
  }
  else {
    regmap_update_bits_base
              (param_1[1],*(int *)((long)param_1 + 0x34c) + 0x24U & 0xffff,0xf,
               *(undefined1 *)((long)param_2 + 0xc),0,0,0);
    if ((*(uint *)((long)param_2 + 0xc) < 8) ||
       (uVar3 = haptics_set_manual_rc_clk_cal(param_1), -1 < (int)uVar3)) {
      *(undefined4 *)((long)param_1 + 0x94) = 0;
      *(undefined4 *)((long)param_1 + 0x9c) = 0;
      iVar1 = *(int *)(param_1 + 0x6d);
      *(undefined4 *)(param_1 + 0x12) = 0;
      uVar2 = *(uint *)(param_2 + 1);
      if (iVar1 == 2) {
        uVar4 = 0x280;
      }
      else if (iVar1 == 4) {
        uVar4 = 0x280;
        if (*(uint *)((long)param_1 + 0xec) != 0) {
          uVar4 = *(uint *)((long)param_1 + 0xec);
        }
      }
      else if (iVar1 == 3) {
        uVar4 = 0x400;
      }
      else {
        _printk(&DAT_00111ba3);
        uVar4 = 0;
      }
      uVar3 = haptics_get_available_fifo_memory(param_1);
      if (-1 < (int)uVar3) {
        if (uVar4 <= uVar2) {
          uVar2 = uVar4;
        }
        if (uVar2 <= uVar3) {
          uVar3 = uVar2;
        }
        if (0x13f < uVar3) {
          uVar3 = 0x140;
        }
        uVar2 = uVar3;
        if (uVar3 < *(uint *)(param_2 + 1) && (uVar3 & 3) != 0) {
          uVar2 = uVar3 & 0x1fc;
        }
        uVar3 = haptics_update_fifo_samples(param_1,*param_2,uVar2,0);
        if ((int)uVar3 < 0) {
          _dev_err(*param_1,"write FIFO samples failed, rc=%d\n",uVar3);
        }
        else {
          *(undefined4 *)(param_1 + 0x13) = 1;
          *(uint *)(param_1 + 0x12) = uVar2;
          if (uVar2 == *(uint *)(param_2 + 1)) {
            uVar3 = 0;
            *(undefined4 *)((long)param_1 + 0x94) = 1;
          }
          else {
            uVar3 = *(uint *)(param_1 + 0xb);
          }
          if (*(int *)(param_1 + 0x6d) - 2U < 3) {
            uVar2 = 0;
            if (*(uint *)(&DAT_00110c1c + (long)(int)(*(int *)(param_1 + 0x6d) - 2U) * 4) != 0) {
              uVar2 = uVar3 / *(uint *)(&DAT_00110c1c +
                                       (long)(int)(*(int *)(param_1 + 0x6d) - 2U) * 4);
            }
            regmap_update_bits_base
                      (param_1[1],*(int *)((long)param_1 + 0x34c) + 0x2aU & 0xffff,0xf,uVar2 & 0xff,
                       0,0,0);
            uVar3 = 0;
            if (*(char *)((long)param_1 + 0x36c) == '\0') {
              enable_irq(*(undefined4 *)(param_1 + 0x67));
              uVar3 = 0;
              *(undefined1 *)((long)param_1 + 0x36c) = 1;
            }
          }
          else {
            _printk(&DAT_00111ba3);
            uVar3 = 0xffffffea;
          }
        }
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// lra_calibration_store @ 0010dd20 size=144
// signature: undefined lra_calibration_store(void)
// callers: []
//------------------------------------------------------------

long lra_calibration_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  char local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = '\0';
  iVar2 = kstrtobool(param_3,local_2c);
  if (iVar2 == 0) {
    lVar3 = param_4;
    if (local_2c[0] != '\0') {
      iVar2 = haptics_start_lra_calibrate(param_1 + -0x1d8);
      lVar3 = (long)iVar2;
      if (-1 < iVar2) {
        lVar3 = param_4;
      }
    }
  }
  else {
    lVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// lra_frequency_hz_show @ 0010ddb4 size=84
// signature: undefined lra_frequency_hz_show(void)
// callers: []
//------------------------------------------------------------

long lra_frequency_hz_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  uVar1 = *(uint *)(param_1 + -0x198);
  if (uVar1 == 0) {
    lVar4 = -0x16;
  }
  else {
    uVar2 = 0;
    if (uVar1 != 0) {
      uVar2 = 1000000 / uVar1;
    }
    iVar3 = scnprintf(param_3,0x1000,"%d Hz\n",uVar2);
    lVar4 = (long)iVar3;
  }
  return lVar4;
}



//------------------------------------------------------------
// lra_impedance_show @ 0010de0c size=204
// signature: undefined lra_impedance_show(void)
// callers: []
//------------------------------------------------------------

long lra_impedance_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  
  if (*(char *)(param_1 + -0x173) == '\0') {
    if (*(int *)(param_1 + -0x194) == 0) {
      if (*(uint *)(param_1 + -400) == 0) {
        return -0x16;
      }
      pcVar2 = "Short circuit";
    }
    else {
      if (*(uint *)(param_1 + -400) < *(uint *)(param_1 + -0x18c)) {
        iVar1 = scnprintf(param_3,0x1000,"%u ~ %u mohms\n");
        goto LAB_0010dec0;
      }
      pcVar2 = "Open circuit";
    }
    iVar1 = scnprintf(param_3,0x1000,&DAT_001130a8,pcVar2);
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,"measured %u mohms\n",*(undefined4 *)(param_1 + -0x188));
  }
LAB_0010dec0:
  return (long)iVar1;
}



//------------------------------------------------------------
// primitive_duration_show @ 0010dedc size=56
// signature: undefined primitive_duration_show(void)
// callers: []
//------------------------------------------------------------

long primitive_duration_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00112065,*(undefined4 *)(param_1 + 0x184));
  return (long)iVar1;
}



//------------------------------------------------------------
// primitive_duration_store @ 0010df18 size=328
// signature: undefined primitive_duration_store(void)
// callers: []
//------------------------------------------------------------

undefined8
primitive_duration_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long lVar6;
  ushort local_2c [2];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c[0] = 0;
  iVar2 = kstrtou16(param_3,0,local_2c);
  if (iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
    goto LAB_0010e01c;
  }
  iVar2 = *(int *)(param_1 + 0x16c);
  if (iVar2 == 0) {
    iVar3 = 0;
LAB_0010dfa4:
    if (iVar3 != iVar2) {
      lVar4 = *(long *)(param_1 + -0x168);
      plVar5 = (long *)(lVar4 + (long)iVar3 * 0x30);
      lVar6 = plVar5[2];
      if (lVar6 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(lVar6 + 0x14);
      }
      uVar1 = *(uint *)(lVar4 + (long)iVar3 * 0x30 + 0x24);
      if ((uVar1 & 0xfffffffe) == 2) {
        lVar4 = *plVar5;
        if (lVar4 != 0) {
          iVar3 = *(int *)(lVar4 + 100);
LAB_0010e014:
          iVar2 = iVar3 + iVar2;
        }
      }
      else if ((uVar1 == 0) && (lVar4 = *(long *)(lVar4 + (long)iVar3 * 0x30 + 8), lVar4 != 0)) {
        iVar3 = *(int *)(lVar4 + 0x10);
        goto LAB_0010e014;
      }
      *(int *)(param_1 + 0x184) = iVar2;
      goto LAB_0010e01c;
    }
  }
  else {
    iVar3 = 0;
    do {
      if (*(uint *)(*(long *)(param_1 + -0x168) + (long)iVar3 * 0x30 + 0x18) == (uint)local_2c[0])
      goto LAB_0010dfa4;
      iVar3 = iVar3 + 1;
    } while (iVar2 != iVar3);
  }
  _printk(&DAT_00112f0a);
  param_4 = 0xffffffffffffffea;
LAB_0010e01c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// enable_play_store @ 0010e064 size=160
// signature: undefined enable_play_store(void)
// callers: []
//------------------------------------------------------------

void enable_play_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    iVar2 = haptics_start_play(param_1 + -0x1d8,local_2c != 0);
    lVar3 = (long)iVar2;
    if (-1 < iVar2) {
      lVar3 = param_4;
    }
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
// haptics_start_play @ 0010e104 size=464
// signature: undefined haptics_start_play(void)
// callers: [enable_play_store]
//------------------------------------------------------------

int haptics_start_play(undefined8 *param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined1 local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  iVar4 = *(int *)(param_1 + 7);
  if (iVar4 == 0) {
    iVar4 = *(int *)((long)param_1 + 0x34);
  }
  mutex_lock(param_1 + 0x14);
  if ((param_2 & 1) != 0) {
    iVar3 = haptics_enable_play(param_1,0);
    if (iVar3 < 0) {
      uVar5 = *param_1;
      pcVar6 = "Stop playing failed, rc=%d\n";
LAB_0010e21c:
      _dev_err(uVar5,pcVar6,iVar3);
    }
    else {
      iVar4 = haptics_set_vmax_mv(param_1,iVar4);
      if (-1 < iVar4) {
        local_3c[0] = get_direct_play_max_amplitude(param_1);
        uVar1 = *(int *)((long)param_1 + 0x34c) + 0x26U & 0xffff;
        iVar3 = regmap_bulk_write(param_1[1],uVar1,local_3c,1);
        if (iVar3 < 0) {
          _dev_err(*param_1,"write addr %#x failed, rc=%d\n",uVar1,iVar3);
          uVar5 = *param_1;
          pcVar6 = "config DIRECT_PLAY failed, rc=%d\n";
          goto LAB_0010e21c;
        }
        iVar4 = haptics_enable_hpwr_vreg(param_1,1);
        if ((-1 < iVar4) && (iVar4 = haptics_wait_hboost_ready(param_1), -1 < iVar4)) {
          *(undefined4 *)((long)param_1 + 0xdc) = 1;
          iVar4 = haptics_enable_play(param_1,1);
          if (-1 < iVar4) goto LAB_0010e268;
        }
      }
    }
  }
  haptics_enable_play(param_1,0);
  if ((param_1[0x4e] == 0) || (*(char *)((long)param_1 + 0x36f) == '\0')) {
    iVar4 = 0;
  }
  else {
    iVar4 = regulator_disable();
    if (iVar4 < 0) {
      uVar5 = *param_1;
      pcVar6 = "Disable hpwr failed, rc=%d\n";
    }
    else {
      iVar4 = regulator_set_voltage(param_1[0x4e],0,0x7fffffff);
      if (-1 < iVar4) {
        iVar4 = 0;
        *(undefined1 *)((long)param_1 + 0x36f) = 0;
        goto LAB_0010e268;
      }
      uVar5 = *param_1;
      pcVar6 = "Set hpwr voltage failed, rc=%d\n";
    }
    _dev_err(uVar5,pcVar6,iVar4);
  }
LAB_0010e268:
  mutex_unlock(param_1 + 0x14);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// vmax_mv_debug_show @ 0010e2d8 size=60
// signature: undefined vmax_mv_debug_show(void)
// callers: []
//------------------------------------------------------------

long vmax_mv_debug_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%d mv\n",*(undefined4 *)(param_1 + -0x1a0));
  return (long)iVar1;
}



//------------------------------------------------------------
// vmax_mv_debug_store @ 0010e318 size=180
// signature: undefined vmax_mv_debug_store(void)
// callers: []
//------------------------------------------------------------

undefined8
vmax_mv_debug_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    if (local_2c < 0) {
      iVar2 = 0;
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + -0x1d8),"change vmax_mv %d -> %d\n",
               *(undefined4 *)(param_1 + -0x1a4));
      iVar2 = local_2c;
    }
    *(int *)(param_1 + -0x1a0) = iVar2;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// richtap_load_prebake @ 0010e3cc size=948
// signature: undefined richtap_load_prebake(void)
// callers: [richtap_work_proc, richtap_file_unlocked_ioctl]
//------------------------------------------------------------

uint richtap_load_prebake(undefined8 *param_1,void *param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  long *plVar7;
  undefined8 *puVar8;
  uint uVar9;
  
  if ((param_1[0xf] == 0) || (plVar7 = *(long **)(param_1[0xf] + 8), plVar7 == (long *)0x0)) {
    return 0xfffffff4;
  }
  if (*(int *)((long)param_1 + 0x3c) - 0x30d41U < 0xfffcf2c0) {
    _dev_err(*param_1,"aac RichTap Can\'t support play rate: %d Hz\n",24000);
    return 0xffffffea;
  }
  puVar1 = param_1 + 0x14;
  mutex_lock(puVar1);
  *(uint *)(plVar7 + 1) = param_3;
  *(undefined4 *)((long)plVar7 + 0xc) = 10;
  kfree(*plVar7);
  lVar5 = __kmalloc((ulong)param_3,0xdc0);
  *plVar7 = lVar5;
  if (lVar5 == 0) {
    uVar4 = 0xfffffff4;
    goto LAB_0010e610;
  }
  memcpy((void *)*plVar7,param_2,(ulong)param_3);
  param_1[0x10] = param_1[0xf];
  param_1[0x11] = 0;
  uVar4 = haptics_set_vmax_mv(param_1,*(undefined4 *)((long)param_1 + 0xd4));
  if ((-1 < (int)uVar4) &&
     (((*(byte *)(param_1 + 0x6b) >> 3 & 1) == 0 ||
      (uVar4 = haptics_toggle_module_enable(param_1), -1 < (int)uVar4)))) {
    regmap_update_bits_base(param_1[1],*(int *)(param_1 + 0x69) + 99U & 0xffff,0x80,0,0,0,0);
    *(undefined4 *)((long)param_1 + 0xdc) = 0;
    puVar8 = *(undefined8 **)(param_1[0x10] + 8);
    if (*(int *)(param_1 + 0x13) == 1) {
      _dev_err(*param_1,"FIFO is busy\n");
      uVar4 = 0xfffffff0;
    }
    else if ((*(char *)((long)param_1 + 0x361) == '\x01') && (8 < *(uint *)((long)puVar8 + 0xc))) {
      iVar2 = *(int *)(param_1 + 0x6d);
      uVar4 = *(uint *)(puVar8 + 1);
      if (iVar2 == 2) {
        if (0x280 < uVar4) goto LAB_0010e514;
        goto LAB_0010e560;
      }
      if (iVar2 == 4) {
        uVar3 = 0x280;
        if (*(uint *)((long)param_1 + 0xec) != 0) {
          uVar3 = *(uint *)((long)param_1 + 0xec);
        }
        if (uVar3 < uVar4) goto LAB_0010e514;
        goto LAB_0010e560;
      }
      if (iVar2 == 3) {
        if (0x400 < uVar4) goto LAB_0010e514;
        goto LAB_0010e560;
      }
      _printk(&DAT_00111ba3);
      if (uVar4 == 0) goto LAB_0010e560;
LAB_0010e514:
      _dev_err(*param_1,"PM8350B v1 not play long pattern higher than 8 KHz play rate\n");
LAB_0010e75c:
      uVar4 = 0xffffffea;
    }
    else {
LAB_0010e560:
      regmap_update_bits_base
                (param_1[1],*(int *)((long)param_1 + 0x34c) + 0x24U & 0xffff,0xf,
                 *(undefined1 *)((long)puVar8 + 0xc),0,0,0);
      if ((*(uint *)((long)puVar8 + 0xc) < 8) ||
         (uVar4 = haptics_set_manual_rc_clk_cal(param_1), -1 < (int)uVar4)) {
        *(undefined4 *)((long)param_1 + 0x94) = 0;
        *(undefined4 *)((long)param_1 + 0x9c) = 0;
        iVar2 = *(int *)(param_1 + 0x6d);
        *(undefined4 *)(param_1 + 0x12) = 0;
        uVar3 = *(uint *)(puVar8 + 1);
        if (iVar2 == 2) {
          uVar9 = 0x280;
        }
        else if (iVar2 == 4) {
          uVar9 = 0x280;
          if (*(uint *)((long)param_1 + 0xec) != 0) {
            uVar9 = *(uint *)((long)param_1 + 0xec);
          }
        }
        else if (iVar2 == 3) {
          uVar9 = 0x400;
        }
        else {
          _printk(&DAT_00111ba3);
          uVar9 = 0;
        }
        uVar4 = haptics_get_available_fifo_memory(param_1);
        if (-1 < (int)uVar4) {
          if (uVar9 <= uVar3) {
            uVar3 = uVar9;
          }
          uVar9 = uVar4;
          if (uVar3 <= uVar4) {
            uVar9 = uVar3;
          }
          uVar4 = haptics_update_fifo_samples(param_1,*puVar8,uVar9,0);
          if (-1 < (int)uVar4) {
            _dev_info(*param_1,"aac Richtap set busy to 1\n");
            *(undefined4 *)(param_1 + 0x13) = 1;
            *(uint *)(param_1 + 0x12) = uVar9;
            if (*(int *)(param_1 + 0x6d) - 2U < 3) {
              uVar6 = 0x2000200028 >> (((ulong)(*(int *)(param_1 + 0x6d) - 2U) & 3) << 4);
              uVar4 = 0;
              if ((uVar6 & 0xffff) != 0) {
                uVar4 = 0x1e0 / ((uint)uVar6 & 0xffff);
              }
              regmap_update_bits_base
                        (param_1[1],*(int *)((long)param_1 + 0x34c) + 0x2aU & 0xffff,0xf,uVar4,0,0,0
                        );
              _dev_info(*param_1,"aac RichTap haptics_set_fifo success\n");
              mutex_unlock(puVar1);
              return 0;
            }
            _printk(&DAT_00111ba3);
            goto LAB_0010e75c;
          }
          _dev_err(*param_1,"write FIFO samples failed, rc=%d\n",uVar4);
        }
      }
    }
  }
  kfree(*plVar7);
  *plVar7 = 0;
LAB_0010e610:
  mutex_unlock(puVar1);
  return uVar4;
}



//------------------------------------------------------------
// richtap_file_read @ 0010e784 size=8
// signature: undefined richtap_file_read(void)
// callers: []
//------------------------------------------------------------

undefined8 richtap_file_read(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  return param_3;
}



//------------------------------------------------------------
// richtap_file_write @ 0010e790 size=8
// signature: undefined richtap_file_write(void)
// callers: []
//------------------------------------------------------------

undefined8 richtap_file_write(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  return param_3;
}



//------------------------------------------------------------
// richtap_file_unlocked_ioctl @ 0010e79c size=2012
// signature: undefined richtap_file_unlocked_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void richtap_file_unlocked_ioctl(long param_1,undefined4 param_2,ulong param_3)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  size_t __n;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined1 *puVar8;
  undefined8 *puVar9;
  ulong uVar10;
  undefined1 *puVar11;
  undefined8 *puVar12;
  uint local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  puVar12 = *(undefined8 **)(param_1 + 0xd8);
  local_3c = 0;
  _dev_info(*puVar12,"%s: cmd=0x%x, arg=0x%lx\n","richtap_file_unlocked_ioctl",param_2,param_3);
  iVar4 = 0;
  switch(param_2) {
  case 0x5203:
    puVar12 = (undefined8 *)sp_el0;
    local_3c = 5;
    if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_3, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
      uVar10 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar10 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        puVar12 = (undefined8 *)puVar12[1];
        uVar3 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar12;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      lVar5 = __arch_copy_to_user(puVar12,param_3 & 0xff7fffffffffffff,&local_3c,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if (lVar5 == 0) goto LAB_0010ed00;
    }
    lVar5 = -0xe;
    goto LAB_0010ed24;
  default:
    _dev_err(*puVar12,"%s, unknown cmd\n","richtap_file_unlocked_ioctl");
    goto LAB_0010ed00;
  case 0x5205:
    local_3c = *(uint *)((long)puVar12 + 0x3fc);
    if (0x7f < param_3) {
      param_3 = 0x80;
    }
    *(uint *)((long)puVar12 + 0xd4) = local_3c * (int)param_3 >> 7;
    haptics_set_vmax_mv(puVar12);
    goto LAB_0010ed00;
  case 0x5206:
  case 0x5213:
    break;
  case 0x5209:
    cancel_work_sync(puVar12 + 0x72);
    mutex_lock(puVar12 + 0x14);
    haptics_stop_fifo_play(puVar12);
    *(undefined4 *)((long)puVar12 + 0x94) = 1;
    *(undefined4 *)((long)puVar12 + 0x3f4) = 0;
    mutex_unlock(puVar12 + 0x14);
    cancel_work_sync(puVar12 + 0x78);
    regmap_update_bits_base(puVar12[1],*(int *)(puVar12 + 0x69) + 0x72U & 0xffff,0xc,0,0,0,0);
    puVar9 = (undefined8 *)sp_el0;
    lVar5 = puVar12[0x6f];
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar10 = param_3, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar10 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar10 < 0x7fffffc181) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar3 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      __n = __arch_copy_from_user(puVar9,lVar5,param_3 & 0xff7fffffffffffff,16000);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar3 = daif;
          daif = uVar3 | 0xc0;
        }
        uVar3 = ttbr1_el1;
        ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar3 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
      if (__n == 0) {
        local_3c = *(uint *)puVar12[0x6f];
        if (local_3c < 0x3e7d) {
          iVar4 = richtap_load_prebake(puVar12,(uint *)puVar12[0x6f] + 1);
          if (iVar4 < 0) {
            uVar6 = *puVar12;
            pcVar7 = "aac RichTap Upload FIFO data fail: %d\n";
          }
          else {
            iVar4 = haptics_enable_hpwr_vreg(puVar12,1);
            if (-1 < iVar4) {
              iVar4 = haptics_wait_hboost_ready(puVar12);
              if (-1 < iVar4) {
                iVar4 = haptics_enable_play(puVar12,1);
                if (iVar4 < 0) {
                  _dev_err(*puVar12,"aac RichTap en hpwr_vreg fail, rc=%d\n",iVar4);
                }
                else if ((*(int *)((long)puVar12 + 0xdc) == 0) &&
                        (*(char *)((long)puVar12 + 0x36c) == '\0')) {
                  enable_irq(*(undefined4 *)(puVar12 + 0x67));
                  *(undefined1 *)((long)puVar12 + 0x36c) = 1;
                }
              }
              queue_work_on(0x20,_system_wq,puVar12 + 0x78);
              break;
            }
            uVar6 = *puVar12;
            pcVar7 = "aac RichTap en hpwr_vreg fail, rc=%d\n";
          }
          _dev_err(uVar6,pcVar7,iVar4);
        }
        else {
          _dev_err(*puVar12,"aac RichTap rtp mode date len error %d\n");
          iVar4 = -0x16;
        }
        break;
      }
    }
    else {
      __n = 16000;
    }
    memset((void *)((lVar5 - __n) + 16000),0,__n);
    iVar4 = -0xe;
    break;
  case 0x520a:
    cancel_work_sync(puVar12 + 0x72);
    mutex_lock(puVar12 + 0x14);
    haptics_stop_fifo_play(puVar12);
    mutex_unlock(puVar12 + 0x14);
    queue_work_on(0x20,_system_wq,puVar12 + 0x72);
    puVar8 = (undefined1 *)puVar12[0x70];
    iVar4 = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xff;
    *(undefined2 *)(puVar8 + 2) = 0;
    *puVar11 = 0xff;
    *(undefined2 *)(puVar11 + 2) = 0;
    break;
  case 0x5211:
    uVar1 = *(uint *)(puVar12 + 8);
    if (uVar1 == 0) {
      _dev_info(*puVar12,"aac RichTap get f0 =%d\n",0);
      iVar4 = -0x16;
      _dev_err(*puVar12,"aac RichTap get f0 error, ret=%d\n",0xffffffea);
    }
    else {
      local_3c = 0;
      if (uVar1 != 0) {
        local_3c = 1000000 / uVar1;
      }
      _dev_info(*puVar12,"aac RichTap get f0 =%d\n");
      puVar12 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar12 + 0x46) >> 5 & 1) != 0) ||
         (uVar10 = param_3, ((uint)*puVar12 >> 0x1a & 1) != 0)) {
        uVar10 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar10 < 0x7ffffffffd) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar10 = daif;
          if ((uVar10 & 0x80) == 0) {
            uVar3 = daif;
            daif = uVar3 | 0xc0;
          }
          puVar12 = (undefined8 *)puVar12[1];
          uVar3 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar12 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar12;
          InstructionSynchronizationBarrier();
          daif = uVar10;
        }
        lVar5 = __arch_copy_to_user(puVar12,param_3 & 0xff7fffffffffffff,&local_3c,4);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar10 = daif;
          if ((uVar10 & 0x80) == 0) {
            uVar3 = daif;
            daif = uVar3 | 0xc0;
          }
          uVar3 = ttbr1_el1;
          ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar3 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar10;
        }
        iVar4 = 0;
        if (lVar5 != 0) {
          iVar4 = -0xe;
        }
      }
      else {
        iVar4 = -0xe;
      }
    }
    break;
  case 0x5212:
    cancel_work_sync(puVar12 + 0x72);
    mutex_lock(puVar12 + 0x14);
    puVar8 = (undefined1 *)puVar12[0x70];
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    puVar8 = *(undefined1 **)(puVar11 + 8);
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    puVar11 = *(undefined1 **)(puVar8 + 8);
    *puVar8 = 0xaa;
    *(undefined2 *)(puVar8 + 2) = 0;
    *puVar11 = 0xaa;
    *(undefined2 *)(puVar11 + 2) = 0;
    *(undefined4 *)((long)puVar12 + 0x94) = 1;
    if (*(int *)(puVar12 + 0x6d) - 2U < 3) {
      regmap_update_bits_base
                (puVar12[1],*(int *)((long)puVar12 + 0x34c) + 0x2aU & 0xffff,0xf,0,0,0,0);
    }
    else {
      _printk(&DAT_00111ba3);
    }
    haptics_stop_fifo_play(puVar12);
    *(undefined4 *)((long)puVar12 + 0x3f4) = 0;
    mutex_unlock(puVar12 + 0x14);
LAB_0010ed00:
    iVar4 = 0;
  }
  lVar5 = (long)iVar4;
LAB_0010ed24:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// richtap_file_mmap @ 0010efc4 size=224
// signature: undefined richtap_file_mmap(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int richtap_file_mmap(long param_1,long *param_2)

{
  ulong uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  long lVar7;
  
  if (param_2 == (long *)0x0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x10f0a4);
    (*pcVar3)();
  }
  lVar5 = sp_el0;
  puVar6 = *(undefined8 **)(param_1 + 0xd8);
  lVar7 = param_2[3];
  lVar5 = vm_get_page_prot(*(ulong *)(*(long *)(lVar5 + 0x5a0) + 0xf8) | 0xfb);
  if (lVar7 == lVar5) {
    if (param_2[1] - *param_2 == 0x4000) {
      lVar5 = (long)(puVar6[0x70] << 8) >> 8;
      uVar1 = lVar5 + 0x8000000000;
      uVar2 = uVar1 + _memstart_addr;
      if (uVar1 >> 0x26 != 0) {
        uVar2 = lVar5 - _kimage_voffset;
      }
      iVar4 = remap_pfn_range(param_2,*param_2,uVar2 >> 0xc,0x4000,param_2[3]);
      if (iVar4 != 0) {
        _dev_err(*puVar6,"Error mmap failed\n");
      }
    }
    else {
      iVar4 = -0xc;
    }
  }
  else {
    iVar4 = -1;
  }
  return iVar4;
}



//------------------------------------------------------------
// richtap_file_open @ 0010f0a8 size=76
// signature: undefined richtap_file_open(void)
// callers: []
//------------------------------------------------------------

undefined8 richtap_file_open(undefined8 param_1,long param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = try_module_get(&__this_module);
  if ((uVar1 & 1) == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = 0;
    *(undefined8 *)(param_2 + 0xd8) = g_richtap_ptr;
  }
  return uVar2;
}



//------------------------------------------------------------
// richtap_file_release @ 0010f0f8 size=44
// signature: undefined richtap_file_release(void)
// callers: []
//------------------------------------------------------------

undefined8 richtap_file_release(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = 0;
  module_put(&__this_module);
  return 0;
}



//------------------------------------------------------------
// haptics_suspend_config @ 0010f124 size=420
// signature: undefined haptics_suspend_config(void)
// callers: [haptics_freeze, haptics_shutdown, haptics_suspend]
//------------------------------------------------------------

int haptics_suspend_config(long param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 *puVar7;
  undefined1 local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  puVar7 = *(undefined8 **)(param_1 + 0x98);
  puVar1 = puVar7 + 0x14;
  mutex_lock(puVar1);
  if ((*(int *)((long)puVar7 + 0xdc) == 0) && (*(int *)(puVar7 + 0x13) != 0)) {
    if (*(int *)((long)puVar7 + 0x94) == 0) {
      *(undefined4 *)((long)puVar7 + 0x9c) = 1;
    }
    iVar4 = haptics_stop_fifo_play(puVar7);
    if (-1 < iVar4) goto LAB_0010f1a4;
    _dev_err(*puVar7,"stop FIFO playing failed, rc=%d\n",iVar4);
  }
  else {
    iVar4 = haptics_enable_play(puVar7,0);
    if (-1 < iVar4) {
LAB_0010f1a4:
      mutex_unlock(puVar1);
      if ((*(byte *)(puVar7 + 0x6b) >> 1 & 1) != 0) {
        hrtimer_cancel(puVar7 + 0x4f);
        haptics_boost_vreg_enable(puVar7,0);
      }
      if ((puVar7[0x4e] == 0) || (*(char *)((long)puVar7 + 0x36f) == '\0')) {
LAB_0010f1f8:
        local_3c[0] = 0;
        uVar2 = *(int *)(puVar7 + 0x69) + 0x46U & 0xffff;
        iVar4 = regmap_bulk_write(puVar7[1],uVar2,local_3c,1);
        if (iVar4 < 0) {
          _dev_err(*puVar7,"write addr %#x failed, rc=%d\n",uVar2,iVar4);
        }
        else {
          iVar4 = 0;
        }
      }
      else {
        iVar4 = regulator_disable();
        if (iVar4 < 0) {
          uVar5 = *puVar7;
          pcVar6 = "Disable hpwr failed, rc=%d\n";
        }
        else {
          iVar4 = regulator_set_voltage(puVar7[0x4e],0,0x7fffffff);
          if (-1 < iVar4) {
            *(undefined1 *)((long)puVar7 + 0x36f) = 0;
            goto LAB_0010f1f8;
          }
          uVar5 = *puVar7;
          pcVar6 = "Set hpwr voltage failed, rc=%d\n";
        }
        _dev_err(uVar5,pcVar6,iVar4);
      }
      goto LAB_0010f22c;
    }
  }
  mutex_unlock(puVar1);
LAB_0010f22c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// haptics_suspend @ 0010f2cc size=60
// signature: undefined haptics_suspend(void)
// callers: []
//------------------------------------------------------------

int haptics_suspend(long param_1)

{
  int iVar1;
  
  if (*(char *)(*(long *)(param_1 + 0x98) + 0x360) == '\x01') {
    iVar1 = 0;
  }
  else {
    iVar1 = haptics_suspend_config();
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// haptics_resume @ 0010f30c size=204
// signature: undefined haptics_resume(void)
// callers: []
//------------------------------------------------------------

void haptics_resume(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  uVar3 = 500;
  if (*(uint *)(puVar4 + 0x6d) < 4) {
    uVar3 = 100;
  }
  usleep_range_state(uVar3,uVar3 | 1,2);
  local_3c[0] = 0x80;
  uVar3 = *(int *)(puVar4 + 0x69) + 0x46U & 0xffff;
  iVar2 = regmap_bulk_write(puVar4[1],uVar3,local_3c,1);
  if (iVar2 < 0) {
    _dev_err(*puVar4,"write addr %#x failed, rc=%d\n",uVar3,iVar2);
  }
  lVar1 = sp_el0;
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// haptics_freeze @ 0010f3dc size=72
// signature: undefined haptics_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_freeze(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = haptics_suspend_config();
  if (-1 < (int)uVar1) {
    if (0 < *(int *)(*(long *)(param_1 + 0x98) + 0x338)) {
      devm_free_irq(param_1);
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// haptics_restore @ 0010f428 size=332
// signature: undefined haptics_restore(void)
// callers: []
//------------------------------------------------------------

int haptics_restore(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  uint uVar5;
  undefined8 *puVar6;
  undefined1 local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar6 = *(undefined8 **)(param_1 + 0x98);
  iVar2 = haptics_hw_init(puVar6);
  if (iVar2 < 0) {
    uVar3 = *puVar6;
    pcVar4 = "Initialize HW failed, rc = %d\n";
LAB_0010f564:
    _dev_err(uVar3,pcVar4,iVar2);
  }
  else {
    if (0 < *(int *)(puVar6 + 0x67)) {
      iVar2 = devm_request_threaded_irq
                        (*puVar6,*(int *)(puVar6 + 0x67),0,fifo_empty_irq_handler,0x2000,
                         "fifo-empty",puVar6);
      if (iVar2 < 0) {
        uVar3 = *puVar6;
        pcVar4 = "request fifo-empty IRQ failed, rc=%d\n";
        goto LAB_0010f564;
      }
      disable_irq_nosync(*(undefined4 *)(puVar6 + 0x67));
      *(undefined1 *)((long)puVar6 + 0x36c) = 0;
    }
    uVar5 = 500;
    if (*(uint *)(puVar6 + 0x6d) < 4) {
      uVar5 = 100;
    }
    usleep_range_state(uVar5,uVar5 | 1,2);
    local_3c[0] = 0x80;
    uVar5 = *(int *)(puVar6 + 0x69) + 0x46U & 0xffff;
    iVar2 = regmap_bulk_write(puVar6[1],uVar5,local_3c,1);
    if (iVar2 < 0) {
      _dev_err(*puVar6,"write addr %#x failed, rc=%d\n",uVar5,iVar2);
    }
    else {
      iVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 0010f764 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&haptics_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010f794 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&haptics_driver);
  return;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 00117000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_qcom_haptics_fifo_prgm_status, trace_event_raw_event_qcom_haptics_status, trace_event_raw_event_qcom_haptics_fifo_hw_status, trace_event_raw_event_qcom_haptics_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 00117008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_qcom_haptics_fifo_prgm_status, trace_event_raw_event_qcom_haptics_status, trace_event_raw_event_qcom_haptics_fifo_hw_status, trace_event_raw_event_qcom_haptics_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 00117010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_qcom_haptics_fifo_prgm_status, trace_event_raw_event_qcom_haptics_status, trace_event_raw_event_qcom_haptics_fifo_hw_status, trace_event_raw_event_qcom_haptics_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00117018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_qcom_haptics_fifo_hw_status, haptics_update_memory_data, haptics_enable_play, enable_play_store, haptics_probe, haptics_parse_per_effect_dt, haptics_get_status_data, pattern_s_dbgfs_write, haptics_get_closeloop_lra_period, trace_event_raw_event_qcom_haptics_status, get_direct_play_max_amplitude, richtap_file_unlocked_ioctl, haptics_resume, haptics_set_vmax_mv, primitive_duration_store, haptics_start_play, haptics_restore, haptics_config_openloop_lra_period, perf_trace_qcom_haptics_fifo_prgm_status, haptics_get_available_fifo_memory, haptics_wait_hboost_ready, haptics_suspend_config, haptics_start_lra_calibrate, vmax_mv_debug_store, haptics_hw_init, trace_event_raw_event_qcom_haptics_fifo_prgm_status, haptics_set_gain_work, haptics_set_manual_rc_clk_cal, haptics_toggle_module_enable, brake_mode_dbgfs_read, haptics_boost_vreg_enable, haptics_upload_effect, trace_event_raw_event_qcom_haptics_fifo_hw_status, haptics_get_fifo_fill_status, richtap_erase_work_proc, haptics_set_pattern, brake_s_dbgfs_write, is_boost_vreg_enabled_in_open_loop, haptics_update_fifo_samples, fifo_s_dbgfs_write, haptics_add_debugfs, trace_event_raw_event_qcom_haptics_play, perf_trace_qcom_haptics_play, perf_trace_qcom_haptics_status, fifo_empty_irq_handler, swr_slave_reg_enable, lra_calibration_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 00117020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_qcom_haptics_fifo_hw_status, perf_trace_qcom_haptics_fifo_prgm_status, perf_trace_qcom_haptics_play, perf_trace_qcom_haptics_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 00117028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_qcom_haptics_fifo_hw_status, perf_trace_qcom_haptics_fifo_prgm_status, perf_trace_qcom_haptics_play, perf_trace_qcom_haptics_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00117030 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_qcom_haptics_status, perf_trace_qcom_haptics_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 00117038 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_qcom_haptics_status, perf_trace_qcom_haptics_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 00117040 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_qcom_haptics_fifo_hw_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 00117048 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_qcom_haptics_fifo_prgm_status, __bpf_trace_qcom_haptics_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 00117050 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_qcom_haptics_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00117058 size=1
// signature: undefined debugfs_remove(void)
// callers: [haptics_create_debugfs, haptics_remove_debugfs, haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00117060 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [haptics_create_debugfs, haptics_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 00117068 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [haptics_create_debugfs, haptics_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00117070 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [haptics_create_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00117078 size=1
// signature: undefined _dev_err(void)
// callers: [haptics_update_memory_data, haptics_enable_play, haptics_probe, haptics_parse_per_effect_dt, haptics_get_status_data, haptics_get_closeloop_lra_period, haptics_set_brake, get_direct_play_max_amplitude, haptics_stop_constant_effect_play, richtap_file_unlocked_ioctl, haptics_resume, haptics_enable_hpwr_vreg, haptics_boost_notifier, haptics_set_vmax_mv, haptics_start_play, haptics_restore, haptics_config_openloop_lra_period, richtap_file_mmap, haptics_get_available_fifo_memory, haptics_wait_hboost_ready, haptics_suspend_config, haptics_start_lra_calibrate, vmax_mv_debug_store, haptics_hw_init, haptics_disable_hbst_timer, haptics_set_gain_work, haptics_set_manual_rc_clk_cal, haptics_toggle_module_enable, haptics_boost_vreg_enable, haptics_upload_effect, haptics_get_fifo_fill_status, haptics_set_pattern, is_boost_vreg_enabled_in_open_loop, haptics_update_fifo_samples, haptics_create_debugfs, haptics_set_fifo, haptics_erase, richtap_work_proc, richtap_load_prebake, fifo_empty_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00117080 size=1
// signature: undefined scnprintf(void)
// callers: [lra_frequency_hz_show, pattern_s_dbgfs_read, fifo_s_dbgfs_read, primitive_duration_show, vmax_mv_debug_show, brake_s_dbgfs_read, brake_mode_dbgfs_read, lra_impedance_show, haptics_add_debugfs, __dump_effects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00117088 size=1
// signature: undefined debugfs_create_file(void)
// callers: [haptics_add_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00117090 size=1
// signature: undefined _printk(void)
// callers: [haptics_probe, pattern_s_dbgfs_write, get_max_fifo_samples, haptics_set_fifo_empty_threshold, richtap_file_unlocked_ioctl, richtap_erase_work_proc, primitive_duration_store, fifo_period_dbgfs_write, brake_mode_dbgfs_write, haptics_set_fifo, pattern_play_rate_us_dbgfs_write, haptics_get_available_fifo_memory, fifo_s_dbgfs_write, richtap_work_proc, haptics_add_debugfs, richtap_load_prebake, fifo_empty_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00117098 size=1
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
// platform_driver_unregister @ 001170a0 size=1
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
// trace_raw_output_prep @ 001170a8 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_qcom_haptics_fifo_prgm_status, trace_raw_output_qcom_haptics_status, trace_raw_output_qcom_haptics_play, trace_raw_output_qcom_haptics_fifo_hw_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 001170b0 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_qcom_haptics_fifo_prgm_status, trace_raw_output_qcom_haptics_status, trace_raw_output_qcom_haptics_play, trace_raw_output_qcom_haptics_fifo_hw_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 001170b8 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_qcom_haptics_fifo_prgm_status, trace_raw_output_qcom_haptics_status, trace_raw_output_qcom_haptics_play, trace_raw_output_qcom_haptics_fifo_hw_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 001170c0 size=1
// signature: undefined simple_attr_open(void)
// callers: [preload_effect_idx_dbgfs_ops_open, fifo_period_dbgfs_ops_open, vmax_debugfs_ops_open, auto_res_en_debugfs_ops_open, brake_sine_gain_dbgfs_ops_open, pattern_play_rate_dbgfs_ops_open, brake_en_dbgfs_ops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001170d0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [pattern_s_dbgfs_read, pattern_s_dbgfs_write, brake_s_dbgfs_read, brake_s_dbgfs_write, __dump_effects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 001170d8 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [pattern_s_dbgfs_read, fifo_s_dbgfs_read, brake_s_dbgfs_read, brake_mode_dbgfs_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001170e0 size=1
// signature: undefined kfree(void)
// callers: [brake_mode_dbgfs_write, haptics_probe, pattern_s_dbgfs_read, pattern_s_dbgfs_write, fifo_s_dbgfs_read, brake_s_dbgfs_read, fifo_s_dbgfs_write, richtap_load_prebake, haptics_remove, brake_s_dbgfs_write, __dump_effects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001170e8 size=1
// signature: undefined __check_object_size(void)
// callers: [brake_mode_dbgfs_write, pattern_s_dbgfs_write, fifo_s_dbgfs_write, haptics_upload_effect, brake_s_dbgfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00117100 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [brake_mode_dbgfs_write, pattern_s_dbgfs_write, fifo_s_dbgfs_write, haptics_upload_effect, richtap_file_unlocked_ioctl, brake_s_dbgfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00117108 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [pattern_s_dbgfs_write, fifo_s_dbgfs_write, brake_s_dbgfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00117110 size=1
// signature: undefined kstrtouint(void)
// callers: [pattern_s_dbgfs_write, brake_s_dbgfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00117118 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [brake_mode_dbgfs_write, pattern_s_dbgfs_write, fifo_s_dbgfs_write, haptics_upload_effect, richtap_file_unlocked_ioctl, brake_s_dbgfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00117128 size=1
// signature: undefined __kmalloc(void)
// callers: [brake_mode_dbgfs_write, fifo_s_dbgfs_read, fifo_s_dbgfs_write, haptics_upload_effect, richtap_load_prebake, __dump_effects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00117130 size=1
// signature: undefined kstrtoint(void)
// callers: [enable_play_store, fifo_s_dbgfs_write, vmax_mv_debug_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00117138 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [haptics_update_memory_data, fifo_s_dbgfs_write, richtap_work_proc, richtap_load_prebake, fifo_empty_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00117140 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [brake_mode_dbgfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00117148 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [haptics_enable_play, haptics_probe, haptics_get_status_data, haptics_get_closeloop_lra_period, get_direct_play_max_amplitude, haptics_upload_effect, haptics_set_vmax_mv, haptics_set_pattern, is_boost_vreg_enabled_in_open_loop, haptics_config_openloop_lra_period, haptics_wait_hboost_ready, haptics_start_lra_calibrate, fifo_empty_irq_handler, haptics_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 00117150 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [haptics_update_memory_data, haptics_enable_play, haptics_set_gain_work, haptics_get_status_data, haptics_set_manual_rc_clk_cal, haptics_set_brake, haptics_toggle_module_enable, haptics_upload_effect, haptics_resume, haptics_set_vmax_mv, haptics_set_pattern, haptics_start_play, haptics_update_fifo_samples, haptics_restore, haptics_config_openloop_lra_period, haptics_suspend_config, haptics_start_lra_calibrate, haptics_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00117158 size=1
// signature: undefined devm_kmalloc(void)
// callers: [haptics_probe, haptics_parse_per_effect_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_input_allocate_device @ 00117160 size=1
// signature: undefined devm_input_allocate_device(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00117168 size=1
// signature: undefined dev_get_regmap(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00117170 size=1
// signature: undefined of_find_property(void)
// callers: [haptics_probe, haptics_parse_per_effect_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_cell_get @ 00117178 size=1
// signature: undefined devm_nvmem_cell_get(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00117180 size=1
// signature: undefined devm_regulator_get(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_device_get @ 00117188 size=1
// signature: undefined devm_nvmem_device_get(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_device_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00117190 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00117198 size=1
// signature: undefined __of_get_address(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001171a0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [haptics_probe, haptics_parse_per_effect_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001171a8 size=1
// signature: undefined __mutex_init(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 001171b0 size=1
// signature: undefined devm_regulator_register(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001171b8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [haptics_restore, haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 001171c0 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [haptics_restore, haptics_probe, haptics_stop_fifo_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 001171c8 size=1
// signature: undefined hrtimer_init(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001171d8 size=1
// signature: undefined init_timer_key(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_capability @ 001171e0 size=1
// signature: undefined input_set_capability(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_ff_create @ 001171e8 size=1
// signature: undefined input_ff_create(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_ff_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 001171f0 size=1
// signature: undefined input_register_device(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 001171f8 size=1
// signature: undefined __class_register(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_hboost_event_notifier @ 00117200 size=1
// signature: undefined register_hboost_event_notifier(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_hboost_event_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 00117208 size=1
// signature: undefined kmalloc_large(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_free_pages @ 00117210 size=1
// signature: undefined __get_free_pages(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 00117218 size=1
// signature: undefined misc_register(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00117220 size=1
// signature: undefined _dev_info(void)
// callers: [haptics_probe, haptics_get_status_data, haptics_get_closeloop_lra_period, haptics_stop_fifo_play, richtap_work_proc, richtap_file_unlocked_ioctl, richtap_load_prebake, haptics_start_lra_calibrate, haptics_set_vmax_mv, fifo_empty_irq_handler, richtap_erase_work_proc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00117228 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00117230 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [haptics_probe, haptics_parse_per_effect_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u8_array @ 00117238 size=1
// signature: undefined of_property_read_variable_u8_array(void)
// callers: [haptics_probe, haptics_parse_per_effect_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u8_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00117240 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_ff_destroy @ 00117248 size=1
// signature: undefined input_ff_destroy(void)
// callers: [haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_ff_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_hboost_event_notifier @ 00117250 size=1
// signature: undefined unregister_hboost_event_notifier(void)
// callers: [haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_hboost_event_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 00117258 size=1
// signature: undefined class_unregister(void)
// callers: [haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 00117260 size=1
// signature: undefined free_pages(void)
// callers: [haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 00117268 size=1
// signature: undefined input_unregister_device(void)
// callers: [haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00117270 size=1
// signature: undefined devm_free_irq(void)
// callers: [haptics_freeze, haptics_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_write @ 00117278 size=1
// signature: undefined nvmem_cell_write(void)
// callers: [haptics_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00117280 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [haptics_enable_play, haptics_set_manual_rc_clk_cal, haptics_stop_fifo_play, haptics_set_brake, haptics_set_fifo_empty_threshold, haptics_upload_effect, richtap_file_unlocked_ioctl, haptics_boost_notifier, richtap_erase_work_proc, haptics_set_fifo, swr_slave_reg_disable, richtap_work_proc, richtap_load_prebake, haptics_start_lra_calibrate, swr_slave_reg_enable, haptics_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00117288 size=1
// signature: undefined _dev_warn(void)
// callers: [haptics_enable_play, haptics_get_closeloop_lra_period, haptics_start_lra_calibrate, haptics_hw_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00117298 size=1
// signature: undefined queue_work_on(void)
// callers: [richtap_work_proc, richtap_file_unlocked_ioctl, fifo_empty_irq_handler, haptics_set_gain]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001172a0 size=1
// signature: undefined mutex_lock(void)
// callers: [haptics_set_gain_work, haptics_upload_effect, richtap_file_unlocked_ioctl, haptics_set_vmax_mv, richtap_erase_work_proc, haptics_start_play, haptics_erase, richtap_work_proc, haptics_wait_hboost_ready, richtap_load_prebake, haptics_suspend_config, haptics_start_lra_calibrate, fifo_empty_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001172a8 size=1
// signature: undefined mutex_unlock(void)
// callers: [haptics_set_gain_work, haptics_upload_effect, richtap_file_unlocked_ioctl, haptics_set_vmax_mv, richtap_erase_work_proc, haptics_start_play, haptics_erase, richtap_work_proc, haptics_wait_hboost_ready, richtap_load_prebake, haptics_suspend_config, haptics_start_lra_calibrate, fifo_empty_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001172b0 size=1
// signature: undefined usleep_range_state(void)
// callers: [haptics_enable_play, haptics_restore, haptics_toggle_module_enable, richtap_work_proc, haptics_resume, haptics_wait_hboost_ready, haptics_start_lra_calibrate, haptics_set_vmax_mv, fifo_empty_irq_handler, richtap_erase_work_proc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001172d0 size=1
// signature: undefined regulator_disable(void)
// callers: [haptics_stop_constant_effect_play, haptics_erase, haptics_enable_hpwr_vreg, haptics_suspend_config, haptics_start_lra_calibrate, haptics_start_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001172d8 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [haptics_stop_constant_effect_play, haptics_erase, haptics_enable_hpwr_vreg, haptics_suspend_config, haptics_start_lra_calibrate, haptics_start_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 001172e0 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [haptics_upload_effect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001172e8 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [haptics_upload_effect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001172f0 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [haptics_upload_effect, richtap_file_unlocked_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kvfree @ 001172f8 size=1
// signature: undefined kvfree(void)
// callers: [haptics_stop_fifo_play, haptics_upload_effect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kvfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 00117300 size=1
// signature: undefined vmalloc(void)
// callers: [haptics_upload_effect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00117308 size=1
// signature: undefined cancel_work_sync(void)
// callers: [haptics_erase, richtap_work_proc, richtap_file_unlocked_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00117310 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [haptics_erase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00117318 size=1
// signature: undefined enable_irq(void)
// callers: [haptics_set_fifo, richtap_work_proc, richtap_file_unlocked_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_read @ 00117320 size=1
// signature: undefined nvmem_device_read(void)
// callers: [haptics_get_closeloop_lra_period, haptics_start_lra_calibrate, haptics_set_vmax_mv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_write @ 00117328 size=1
// signature: undefined nvmem_device_write(void)
// callers: [haptics_boost_vreg_enable, haptics_start_lra_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00117330 size=1
// signature: undefined msleep(void)
// callers: [haptics_start_lra_calibrate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00117338 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [swr_slave_reg_disable, swr_slave_reg_is_enabled, swr_slave_reg_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 00117340 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [haptics_enable_play]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00117348 size=1
// signature: undefined regulator_enable(void)
// callers: [haptics_enable_hpwr_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __hrtimer_get_remaining @ 00117350 size=1
// signature: undefined __hrtimer_get_remaining(void)
// callers: [haptics_wait_hboost_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __hrtimer_get_remaining(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_active @ 00117358 size=1
// signature: undefined hrtimer_active(void)
// callers: [haptics_wait_hboost_ready]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 00117360 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [haptics_wait_hboost_ready, haptics_suspend_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 00117368 size=1
// signature: undefined kstrtobool(void)
// callers: [lra_calibration_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 00117370 size=1
// signature: undefined kstrtou16(void)
// callers: [primitive_duration_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vm_get_page_prot @ 00117378 size=1
// signature: undefined vm_get_page_prot(void)
// callers: [richtap_file_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vm_get_page_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remap_pfn_range @ 00117390 size=1
// signature: undefined remap_pfn_range(void)
// callers: [richtap_file_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remap_pfn_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_module_get @ 00117398 size=1
// signature: undefined try_module_get(void)
// callers: [richtap_file_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 001173a0 size=1
// signature: undefined module_put(void)
// callers: [richtap_file_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



