// Decompiled by Ghidra 12.2
// Program: smcinvoke_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// __traceiter_put_pending_cbobj_locked @ 001035e4 size=116
// signature: undefined __traceiter_put_pending_cbobj_locked(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_put_pending_cbobj_locked(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00115000;
  plVar2 = DAT_00115000;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x1717f6af) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103634);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_release_mem_obj_locked @ 0010365c size=116
// signature: undefined __traceiter_release_mem_obj_locked(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_release_mem_obj_locked(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115048;
  plVar2 = _DAT_00115048;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x29a34d6a) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1036ac);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_invoke_cmd_handler @ 001036d4 size=140
// signature: undefined __traceiter_invoke_cmd_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_invoke_cmd_handler
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115090;
  plVar2 = _DAT_00115090;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x56c3d8ca) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103738);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_tzcb_req_handle @ 00103764 size=124
// signature: undefined __traceiter_process_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_tzcb_req_handle
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001150d8;
  plVar2 = _DAT_001150d8;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1037bc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_tzcb_req_wait @ 001037e4 size=196
// signature: undefined __traceiter_process_tzcb_req_wait(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_tzcb_req_wait
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115120;
  plVar2 = _DAT_00115120;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x463f8856) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103874);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_tzcb_req_result @ 001038ac size=148
// signature: undefined __traceiter_process_tzcb_req_result(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_tzcb_req_result
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115168;
  plVar2 = _DAT_00115168;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x689376d7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103918);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_marshal_out_invoke_req @ 00103944 size=140
// signature: undefined __traceiter_marshal_out_invoke_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_marshal_out_invoke_req
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001151b0;
  plVar2 = _DAT_001151b0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x5febe7e0) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1039a8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_prepare_send_scm_msg @ 001039d4 size=116
// signature: undefined __traceiter_prepare_send_scm_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_prepare_send_scm_msg(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001151f8;
  plVar2 = _DAT_001151f8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x4ed9a169) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103a24);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_marshal_in_invoke_req @ 00103a4c size=140
// signature: undefined __traceiter_marshal_in_invoke_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_marshal_in_invoke_req
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115240;
  plVar2 = _DAT_00115240;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x56671b79) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103ab0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_marshal_in_tzcb_req_handle @ 00103adc size=148
// signature: undefined __traceiter_marshal_in_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_marshal_in_tzcb_req_handle
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115288;
  plVar2 = _DAT_00115288;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x649faa2e) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103b48);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_marshal_in_tzcb_req_fd @ 00103b74 size=140
// signature: undefined __traceiter_marshal_in_tzcb_req_fd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_marshal_in_tzcb_req_fd
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001152d0;
  plVar2 = _DAT_001152d0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1e398d13) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103bd8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_marshal_out_tzcb_req @ 00103c04 size=140
// signature: undefined __traceiter_marshal_out_tzcb_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_marshal_out_tzcb_req
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115318;
  plVar2 = _DAT_00115318;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x63433c23) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103c68);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_invoke_req_tzhandle @ 00103c94 size=124
// signature: undefined __traceiter_process_invoke_req_tzhandle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_invoke_req_tzhandle
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115360;
  plVar2 = _DAT_00115360;
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
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103cec);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_invoke_req_result @ 00103d14 size=148
// signature: undefined __traceiter_process_invoke_req_result(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_invoke_req_result
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001153a8;
  plVar2 = _DAT_001153a8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x2b18bb41) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103d80);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_log_info @ 00103dac size=124
// signature: undefined __traceiter_process_log_info(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_log_info
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001153f0;
  plVar2 = _DAT_001153f0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x6f88d660) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103e04);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_smcinvoke_ioctl @ 00103e2c size=116
// signature: undefined __traceiter_smcinvoke_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_smcinvoke_ioctl(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115438;
  plVar2 = _DAT_00115438;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x6e407a49) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103e7c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_smcinvoke_create_bridge @ 00103ea4 size=116
// signature: undefined __traceiter_smcinvoke_create_bridge(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_smcinvoke_create_bridge(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115480;
  plVar2 = _DAT_00115480;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x6b3e6aee) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103ef4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_status @ 00103f1c size=116
// signature: undefined __traceiter_status(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_status(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001154c8;
  plVar2 = _DAT_001154c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7ff3bf76) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103f6c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_accept_req_has_response @ 00103f94 size=116
// signature: undefined __traceiter_process_accept_req_has_response(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_accept_req_has_response
          (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115510;
  plVar2 = _DAT_00115510;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5885f495) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103fe4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_accept_req_ret @ 0010400c size=124
// signature: undefined __traceiter_process_accept_req_ret(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_accept_req_ret
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115558;
  plVar2 = _DAT_00115558;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4822cf30) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104064);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_accept_req_placed @ 0010408c size=116
// signature: undefined __traceiter_process_accept_req_placed(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_accept_req_placed(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001155a0;
  plVar2 = _DAT_001155a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5885f495) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1040dc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_process_invoke_request_from_kernel_client @ 00104104 size=124
// signature: undefined __traceiter_process_invoke_request_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_process_invoke_request_from_kernel_client
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001155e8;
  plVar2 = _DAT_001155e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x2cb3f1d8) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10415c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_smcinvoke_release_filp @ 00104184 size=140
// signature: undefined __traceiter_smcinvoke_release_filp(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_smcinvoke_release_filp
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115630;
  plVar2 = _DAT_00115630;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x2ac31cc5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1041e8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_smcinvoke_release_from_kernel_client @ 00104214 size=124
// signature: undefined __traceiter_smcinvoke_release_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_smcinvoke_release_from_kernel_client
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00115678;
  plVar2 = _DAT_00115678;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x53b4ceb5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10426c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_smcinvoke_release @ 00104294 size=140
// signature: undefined __traceiter_smcinvoke_release(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_smcinvoke_release
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001156c0;
  plVar2 = _DAT_001156c0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x13147259) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1042f8);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_put_pending_cbobj_locked @ 00104324 size=176
// signature: undefined trace_event_raw_event_put_pending_cbobj_locked(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_put_pending_cbobj_locked
               (long param_1,undefined2 param_2,undefined2 param_3)

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
    *(undefined2 *)(lVar1 + 8) = param_2;
    *(undefined2 *)(lVar1 + 10) = param_3;
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
// perf_trace_put_pending_cbobj_locked @ 001043d8 size=252
// signature: undefined perf_trace_put_pending_cbobj_locked(void)
// callers: []
//------------------------------------------------------------

void perf_trace_put_pending_cbobj_locked(long param_1,undefined2 param_2,undefined2 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0xc,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined2 *)(lVar3 + 8) = param_2;
    *(undefined2 *)(lVar3 + 10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0xc,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_release_mem_obj_locked @ 001044d8 size=176
// signature: undefined trace_event_raw_event_release_mem_obj_locked(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_release_mem_obj_locked
               (long param_1,undefined4 param_2,undefined8 param_3)

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
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
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
// perf_trace_release_mem_obj_locked @ 0010458c size=252
// signature: undefined perf_trace_release_mem_obj_locked(void)
// callers: []
//------------------------------------------------------------

void perf_trace_release_mem_obj_locked(long param_1,undefined4 param_2,undefined8 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_invoke_cmd_handler @ 0010468c size=200
// signature: undefined trace_event_raw_event_invoke_cmd_handler(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_invoke_cmd_handler
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x1c) = param_5;
    *(undefined4 *)(lVar1 + 8) = param_2;
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
// perf_trace_invoke_cmd_handler @ 00104758 size=272
// signature: undefined perf_trace_invoke_cmd_handler(void)
// callers: []
//------------------------------------------------------------

void perf_trace_invoke_cmd_handler
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0x24,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_process_tzcb_req_handle @ 0010486c size=192
// signature: undefined trace_event_raw_event_process_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_tzcb_req_handle
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
// perf_trace_process_tzcb_req_handle @ 00104930 size=256
// signature: undefined perf_trace_process_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_tzcb_req_handle
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
// trace_event_raw_event_process_tzcb_req_wait @ 00104a34 size=244
// signature: undefined trace_event_raw_event_process_tzcb_req_wait(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_tzcb_req_wait
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined2 param_8,
               undefined4 param_9)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x24), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    *(undefined2 *)(lVar1 + 0x1c) = param_7;
    *(undefined2 *)(lVar1 + 0x1e) = param_8;
    *(undefined4 *)(lVar1 + 0x20) = param_9;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_process_tzcb_req_wait @ 00104b2c size=308
// signature: undefined perf_trace_process_tzcb_req_wait(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_tzcb_req_wait
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined2 param_8,
               undefined4 param_9)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x24,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    *(undefined2 *)(lVar3 + 0x1c) = param_7;
    *(undefined2 *)(lVar3 + 0x1e) = param_8;
    *(undefined4 *)(lVar3 + 0x20) = param_9;
    perf_trace_run_bpf_submit(lVar3,0x24,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_process_tzcb_req_result @ 00104c64 size=212
// signature: undefined trace_event_raw_event_process_tzcb_req_result(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_tzcb_req_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x1c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_process_tzcb_req_result @ 00104d3c size=276
// signature: undefined perf_trace_process_tzcb_req_result(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_tzcb_req_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_marshal_out_invoke_req @ 00104e54 size=200
// signature: undefined trace_event_raw_event_marshal_out_invoke_req(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_marshal_out_invoke_req
               (long param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
               undefined4 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined2 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
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
// perf_trace_marshal_out_invoke_req @ 00104f20 size=272
// signature: undefined perf_trace_marshal_out_invoke_req(void)
// callers: []
//------------------------------------------------------------

void perf_trace_marshal_out_invoke_req
               (long param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined2 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_prepare_send_scm_msg @ 00105034 size=176
// signature: undefined trace_event_raw_event_prepare_send_scm_msg(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_prepare_send_scm_msg(long param_1,undefined8 param_2,undefined4 param_3)

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
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0x10) = param_3;
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
// perf_trace_prepare_send_scm_msg @ 001050e8 size=252
// signature: undefined perf_trace_prepare_send_scm_msg(void)
// callers: []
//------------------------------------------------------------

void perf_trace_prepare_send_scm_msg(long param_1,undefined8 param_2,undefined4 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0x10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_marshal_in_invoke_req @ 001051e8 size=200
// signature: undefined trace_event_raw_event_marshal_in_invoke_req(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_marshal_in_invoke_req
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x1c) = param_5;
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
// perf_trace_marshal_in_invoke_req @ 001052b4 size=272
// signature: undefined perf_trace_marshal_in_invoke_req(void)
// callers: []
//------------------------------------------------------------

void perf_trace_marshal_in_invoke_req
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x24,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_marshal_in_tzcb_req_handle @ 001053c8 size=212
// signature: undefined trace_event_raw_event_marshal_in_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_marshal_in_tzcb_req_handle
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x1c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_marshal_in_tzcb_req_handle @ 001054a0 size=276
// signature: undefined perf_trace_marshal_in_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void perf_trace_marshal_in_tzcb_req_handle
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_marshal_in_tzcb_req_fd @ 001055b8 size=196
// signature: undefined trace_event_raw_event_marshal_in_tzcb_req_fd(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_marshal_in_tzcb_req_fd
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
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
// perf_trace_marshal_in_tzcb_req_fd @ 00105680 size=268
// signature: undefined perf_trace_marshal_in_tzcb_req_fd(void)
// callers: []
//------------------------------------------------------------

void perf_trace_marshal_in_tzcb_req_fd
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_marshal_out_tzcb_req @ 00105790 size=196
// signature: undefined trace_event_raw_event_marshal_out_tzcb_req(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_marshal_out_tzcb_req
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
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
// perf_trace_marshal_out_tzcb_req @ 00105858 size=268
// signature: undefined perf_trace_marshal_out_tzcb_req(void)
// callers: []
//------------------------------------------------------------

void perf_trace_marshal_out_tzcb_req
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_process_invoke_req_tzhandle @ 00105968 size=192
// signature: undefined trace_event_raw_event_process_invoke_req_tzhandle(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_invoke_req_tzhandle
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
// perf_trace_process_invoke_req_tzhandle @ 00105a2c size=256
// signature: undefined perf_trace_process_invoke_req_tzhandle(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_invoke_req_tzhandle
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
// trace_event_raw_event_process_invoke_req_result @ 00105b30 size=212
// signature: undefined trace_event_raw_event_process_invoke_req_result(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_invoke_req_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x1c), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    *(undefined4 *)(lVar1 + 0x18) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_process_invoke_req_result @ 00105c08 size=276
// signature: undefined perf_trace_process_invoke_req_result(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_invoke_req_result
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
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
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    *(undefined4 *)(lVar3 + 0x18) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_process_log_info @ 00105d20 size=252
// signature: undefined trace_event_raw_event_process_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_log_info
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
// perf_trace_process_log_info @ 00105e20 size=336
// signature: undefined perf_trace_process_log_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_log_info(long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

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
// trace_event_raw_event_smcinvoke_ioctl @ 00105f74 size=176
// signature: undefined trace_event_raw_event_smcinvoke_ioctl(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_smcinvoke_ioctl(long param_1,undefined4 param_2,undefined8 param_3)

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
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
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
// perf_trace_smcinvoke_ioctl @ 00106028 size=252
// signature: undefined perf_trace_smcinvoke_ioctl(void)
// callers: []
//------------------------------------------------------------

void perf_trace_smcinvoke_ioctl(long param_1,undefined4 param_2,undefined8 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_smcinvoke_create_bridge @ 00106128 size=176
// signature: undefined trace_event_raw_event_smcinvoke_create_bridge(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_smcinvoke_create_bridge
               (long param_1,undefined8 param_2,undefined2 param_3)

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
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x18), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined2 *)(lVar1 + 0x10) = param_3;
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
// perf_trace_smcinvoke_create_bridge @ 001061dc size=252
// signature: undefined perf_trace_smcinvoke_create_bridge(void)
// callers: []
//------------------------------------------------------------

void perf_trace_smcinvoke_create_bridge(long param_1,undefined8 param_2,undefined2 param_3)

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
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined2 *)(lVar3 + 0x10) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_status @ 001062dc size=292
// signature: undefined trace_event_raw_event_status(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_status(long param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar7 = __trace_trigger_soft_disabled(param_1), (uVar7 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar4 = strlen(__s);
    __s_00 = "(null)";
    if (param_3 != (char *)0x0) {
      __s_00 = param_3;
    }
    iVar1 = (int)sVar4 + 1;
    sVar5 = strlen(__s_00);
    iVar2 = (int)sVar5 + 1;
    lVar6 = trace_event_buffer_reserve(&local_78,param_1,(long)(iVar2 + iVar1) + 0x10);
    if (lVar6 != 0) {
      uVar3 = (int)sVar4 + 0x11;
      *(uint *)(lVar6 + 8) = iVar1 * 0x10000 | 0x10;
      *(uint *)(lVar6 + 0xc) = uVar3 | iVar2 * 0x10000;
      strcpy((char *)(lVar6 + 0x10),__s);
      strcpy((char *)(lVar6 + (ulong)(uVar3 & 0xffff)),__s_00);
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_status @ 00106404 size=380
// signature: undefined perf_trace_status(void)
// callers: []
//------------------------------------------------------------

void perf_trace_status(long param_1,char *param_2,char *param_3)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  int iVar8;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar7 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar7 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar5 = strlen(__s);
  __s_00 = "(null)";
  if (param_3 != (char *)0x0) {
    __s_00 = param_3;
  }
  sVar6 = strlen(__s_00);
  lVar7 = tpidr_el1;
  plVar2 = (long *)(lVar7 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar6 + 1;
    iVar8 = (int)sVar5;
    iVar4 = (iVar8 + iVar1 + 0x1cU & 0xfffffff8) - 4;
    lVar7 = perf_trace_buf_alloc(iVar4,&local_70,&local_74);
    if (lVar7 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar7 + 8) = iVar8 * 0x10000 + 0x10010;
      *(uint *)(lVar7 + 0xc) = iVar8 + 0x11U | iVar1 * 0x10000;
      strcpy((char *)(lVar7 + 0x10),__s);
      strcpy((char *)(lVar7 + (ulong)(iVar8 + 0x11U & 0xffff)),__s_00);
      perf_trace_run_bpf_submit(lVar7,iVar4,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_process_accept_req_has_response @ 00106584 size=172
// signature: undefined trace_event_raw_event_process_accept_req_has_response(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_accept_req_has_response
               (long param_1,undefined4 param_2,undefined4 param_3)

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
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
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
// perf_trace_process_accept_req_has_response @ 00106634 size=248
// signature: undefined perf_trace_process_accept_req_has_response(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_accept_req_has_response(long param_1,undefined4 param_2,undefined4 param_3)

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
// trace_event_raw_event_process_accept_req_ret @ 00106730 size=192
// signature: undefined trace_event_raw_event_process_accept_req_ret(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_accept_req_ret
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
// perf_trace_process_accept_req_ret @ 001067f4 size=256
// signature: undefined perf_trace_process_accept_req_ret(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_accept_req_ret
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
// trace_event_raw_event_process_accept_req_placed @ 001068f8 size=172
// signature: undefined trace_event_raw_event_process_accept_req_placed(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_accept_req_placed
               (long param_1,undefined4 param_2,undefined4 param_3)

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
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
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
// perf_trace_process_accept_req_placed @ 001069a8 size=248
// signature: undefined perf_trace_process_accept_req_placed(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_accept_req_placed(long param_1,undefined4 param_2,undefined4 param_3)

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
// trace_event_raw_event_process_invoke_request_from_kernel_client @ 00106aa4 size=196
// signature: undefined trace_event_raw_event_process_invoke_request_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_process_invoke_request_from_kernel_client
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
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
// perf_trace_process_invoke_request_from_kernel_client @ 00106b6c size=260
// signature: undefined perf_trace_process_invoke_request_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void perf_trace_process_invoke_request_from_kernel_client
               (long param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x24,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_smcinvoke_release_filp @ 00106c74 size=196
// signature: undefined trace_event_raw_event_smcinvoke_release_filp(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_smcinvoke_release_filp
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined4 *)(lVar1 + 0x1c) = param_5;
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
// perf_trace_smcinvoke_release_filp @ 00106d3c size=268
// signature: undefined perf_trace_smcinvoke_release_filp(void)
// callers: []
//------------------------------------------------------------

void perf_trace_smcinvoke_release_filp
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined4 *)(lVar3 + 0x1c) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x24,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_smcinvoke_release_from_kernel_client @ 00106e4c size=192
// signature: undefined trace_event_raw_event_smcinvoke_release_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_smcinvoke_release_from_kernel_client
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x20), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
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
// perf_trace_smcinvoke_release_from_kernel_client @ 00106f10 size=256
// signature: undefined perf_trace_smcinvoke_release_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void perf_trace_smcinvoke_release_from_kernel_client
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

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
     (lVar3 = perf_trace_buf_alloc(0x24,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x24,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_smcinvoke_release @ 00107014 size=200
// signature: undefined trace_event_raw_event_smcinvoke_release(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_smcinvoke_release
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5)

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
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x28), lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(undefined8 *)(lVar1 + 0x10) = param_3;
    *(undefined4 *)(lVar1 + 0x18) = param_4;
    *(undefined8 *)(lVar1 + 0x20) = param_5;
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
// perf_trace_smcinvoke_release @ 001070e0 size=272
// signature: undefined perf_trace_smcinvoke_release(void)
// callers: []
//------------------------------------------------------------

void perf_trace_smcinvoke_release
               (long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4,
               undefined8 param_5)

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
     (lVar3 = perf_trace_buf_alloc(0x2c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined8 *)(lVar3 + 8) = param_2;
    *(undefined8 *)(lVar3 + 0x10) = param_3;
    *(undefined4 *)(lVar3 + 0x18) = param_4;
    *(undefined8 *)(lVar3 + 0x20) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x2c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_put_pending_cbobj_locked @ 001071f4 size=36
// signature: undefined __bpf_trace_put_pending_cbobj_locked(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_put_pending_cbobj_locked(undefined8 param_1,undefined2 param_2,undefined2 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_release_mem_obj_locked @ 0010721c size=32
// signature: undefined __bpf_trace_release_mem_obj_locked(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_release_mem_obj_locked(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run2(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_invoke_cmd_handler @ 00107240 size=40
// signature: undefined __bpf_trace_invoke_cmd_handler(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_invoke_cmd_handler
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_tzcb_req_handle @ 0010726c size=40
// signature: undefined __bpf_trace_process_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_tzcb_req_handle
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_tzcb_req_wait @ 00107298 size=72
// signature: undefined __bpf_trace_process_tzcb_req_wait(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_tzcb_req_wait
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined2 param_8,
               undefined4 param_9)

{
  bpf_trace_run8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_tzcb_req_result @ 001072e4 size=48
// signature: undefined __bpf_trace_process_tzcb_req_result(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_tzcb_req_result
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_marshal_out_invoke_req @ 00107318 size=44
// signature: undefined __bpf_trace_marshal_out_invoke_req(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_marshal_out_invoke_req
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_prepare_send_scm_msg @ 00107348 size=32
// signature: undefined __bpf_trace_prepare_send_scm_msg(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_prepare_send_scm_msg(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_marshal_in_invoke_req @ 0010736c size=40
// signature: undefined __bpf_trace_marshal_in_invoke_req(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_marshal_in_invoke_req
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_marshal_in_tzcb_req_handle @ 00107398 size=48
// signature: undefined __bpf_trace_marshal_in_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_marshal_in_tzcb_req_handle
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_marshal_in_tzcb_req_fd @ 001073cc size=44
// signature: undefined __bpf_trace_marshal_in_tzcb_req_fd(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_marshal_in_tzcb_req_fd
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_marshal_out_tzcb_req @ 001073fc size=44
// signature: undefined __bpf_trace_marshal_out_tzcb_req(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_marshal_out_tzcb_req
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_invoke_req_tzhandle @ 0010742c size=40
// signature: undefined __bpf_trace_process_invoke_req_tzhandle(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_invoke_req_tzhandle
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_invoke_req_result @ 00107458 size=48
// signature: undefined __bpf_trace_process_invoke_req_result(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_invoke_req_result
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_log_info @ 0010748c size=36
// signature: undefined __bpf_trace_process_log_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_log_info
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_smcinvoke_ioctl @ 001074b4 size=32
// signature: undefined __bpf_trace_smcinvoke_ioctl(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_smcinvoke_ioctl(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run2(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_smcinvoke_create_bridge @ 001074d8 size=32
// signature: undefined __bpf_trace_smcinvoke_create_bridge(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_smcinvoke_create_bridge(undefined8 param_1,undefined8 param_2,undefined2 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_status @ 001074fc size=28
// signature: undefined __bpf_trace_status(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_status(void)

{
  bpf_trace_run2();
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_accept_req_has_response @ 0010751c size=36
// signature: undefined __bpf_trace_process_accept_req_has_response(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_accept_req_has_response
               (undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_accept_req_ret @ 00107544 size=40
// signature: undefined __bpf_trace_process_accept_req_ret(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_accept_req_ret
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_accept_req_placed @ 00107570 size=36
// signature: undefined __bpf_trace_process_accept_req_placed(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_accept_req_placed(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_process_invoke_request_from_kernel_client @ 00107598 size=36
// signature: undefined __bpf_trace_process_invoke_request_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_process_invoke_request_from_kernel_client
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_smcinvoke_release_filp @ 001075c0 size=36
// signature: undefined __bpf_trace_smcinvoke_release_filp(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_smcinvoke_release_filp(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_smcinvoke_release_from_kernel_client @ 001075e8 size=32
// signature: undefined __bpf_trace_smcinvoke_release_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_smcinvoke_release_from_kernel_client(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// __bpf_trace_smcinvoke_release @ 0010760c size=32
// signature: undefined __bpf_trace_smcinvoke_release(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_smcinvoke_release(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// get_root_fd @ 00107630 size=52
// signature: undefined get_root_fd(void)
// callers: [get_client_env_object, get_root_obj]
//------------------------------------------------------------

undefined8 get_root_fd(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  uVar1 = get_fd_for_obj(2,1,param_1);
  return uVar1;
}



//------------------------------------------------------------
// get_fd_for_obj @ 00107664 size=232
// signature: undefined get_fd_for_obj(void)
// callers: [get_uhandle_from_tzhandle, get_root_fd, marshal_out_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 get_fd_for_obj(uint param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  puVar2 = (uint *)kmalloc_trace(_kfree,0xdc0,8);
  if (puVar2 == (uint *)0x0) {
    uVar4 = 0xfffffff4;
    goto LAB_0010772c;
  }
  if ((param_1 & 0xfffffffd) == 0) {
    *puVar2 = param_1;
    puVar2[1] = param_2;
LAB_001076cc:
    iVar1 = get_unused_fd_flags(2);
    if ((param_3 == (int *)0x0) || (iVar1 < 0)) {
      if (iVar1 < 0) goto LAB_00107728;
    }
    else {
      uVar3 = anon_inode_getfile("smcinvoke",&g_smcinvoke_fops,puVar2,2);
      if (uVar3 < 0xfffffffffffff001) {
        *param_3 = iVar1;
        fd_install(iVar1,uVar3);
        return 0;
      }
    }
    put_unused_fd(iVar1);
  }
  else if (param_1 == 1) {
    *(short *)(puVar2 + 1) = (short)param_2;
    *puVar2 = 1;
    goto LAB_001076cc;
  }
LAB_00107728:
  uVar4 = 0xffffffea;
LAB_0010772c:
  kfree(puVar2);
  return uVar4;
}



//------------------------------------------------------------
// process_invoke_request_from_kernel_client @ 00107750 size=168
// signature: undefined process_invoke_request_from_kernel_client(void)
// callers: [invoke_over_smcinvoke]
//------------------------------------------------------------

undefined4 process_invoke_request_from_kernel_client(undefined4 param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  if (param_2 == 0) {
    _printk(&DAT_001168e5,"process_invoke_request_from_kernel_client");
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = fget();
    if (lVar2 == 0) {
      _printk(&DAT_00116248,"process_invoke_request_from_kernel_client",param_1);
      uVar1 = 0xffffffea;
    }
    else {
      uVar1 = process_invoke_req(lVar2,0,param_2);
      fput(lVar2);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// process_invoke_req @ 0010789c size=4076
// signature: undefined process_invoke_req(void)
// callers: [smcinvoke_ioctl, process_invoke_request_from_kernel_client]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void process_invoke_req(long param_1,uint param_2,ulong *param_3)

{
  int *piVar1;
  long lVar2;
  long ******pppppplVar3;
  long ******pppppplVar4;
  int iVar5;
  char cVar6;
  undefined8 uVar7;
  uint *__s;
  int *piVar8;
  void *pvVar9;
  code *pcVar10;
  bool bVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  size_t __n;
  void *__dest;
  ulong uVar15;
  undefined *puVar16;
  int *piVar17;
  ulong uVar18;
  ulong uVar19;
  undefined8 *puVar20;
  long lVar21;
  ulong uVar22;
  void *pvVar23;
  ulong *puVar24;
  ulong uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  long *******ppppppplVar29;
  long *******ppppppplVar30;
  ulong uVar31;
  int iVar32;
  char acStack_19c [4];
  long *******local_198;
  long *******local_190;
  undefined8 local_188;
  uint *local_180;
  undefined8 local_178;
  undefined8 local_170;
  int *local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 local_150;
  void *local_148;
  ulong uStack_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined4 local_f0;
  long local_e8 [17];
  
  lVar21 = sp_el0;
  local_e8[0xf] = *(long *)(lVar21 + 0x638);
  local_198 = (long *******)&local_198;
  local_148 = (void *)0x0;
  uStack_140 = 0;
  local_158 = 0;
  local_150 = 0;
  piVar17 = *(int **)(param_1 + 0xd8);
  local_168 = (int *)0x0;
  uStack_160 = 0;
  local_178 = 0;
  local_170 = 0;
  local_188 = 0;
  local_180 = (uint *)0x0;
  iVar5 = *piVar17;
  local_e8[0xd] = 0;
  local_e8[0xe] = 0;
  local_e8[0xb] = 0;
  local_e8[0xc] = 0;
  local_e8[9] = 0;
  local_e8[10] = 0;
  local_e8[7] = 0;
  local_e8[8] = 0;
  local_e8[5] = 0;
  local_e8[6] = 0;
  local_e8[3] = 0;
  local_e8[4] = 0;
  local_e8[1] = 0;
  local_e8[2] = 0;
  local_e8[0] = 0;
  local_f0 = 0;
  local_100 = 0;
  local_f8 = 0;
  local_110 = 0;
  local_108 = 0;
  local_118 = 0;
  local_128 = 0;
  local_120 = 0;
  acStack_19c[0] = '\0';
  local_190 = local_198;
  if (((param_2 & 0x3fff0000) == 0x200000) || (iVar5 != 0)) {
    if (iVar5 == 0) {
      puVar20 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
         (puVar24 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
        puVar24 = (ulong *)((ulong)param_3 & ((long)param_3 << 8) >> 8);
      }
      if (puVar24 < (ulong *)0x7fffffffe1) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar31 = daif;
          if ((uVar31 & 0x80) == 0) {
            uVar18 = daif;
            daif = uVar18 | 0xc0;
          }
          puVar20 = (undefined8 *)puVar20[1];
          uVar18 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar20 & 0xffff000000000000 | uVar18 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar20;
          InstructionSynchronizationBarrier();
          daif = uVar31;
        }
        __n = __arch_copy_from_user(puVar20,&local_158,(ulong)param_3 & 0xff7fffffffffffff,0x20);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar31 = daif;
          if ((uVar31 & 0x80) == 0) {
            uVar18 = daif;
            daif = uVar18 | 0xc0;
          }
          uVar18 = ttbr1_el1;
          ttbr0_el1 = (uVar18 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar18 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar31;
        }
        if (__n == 0) goto LAB_00107a2c;
      }
      else {
        __n = 0x20;
      }
      memset((void *)((long)&local_138 - __n),0,__n);
      if ((int)__n != 0) {
        _printk(&DAT_00117a92,"process_invoke_req");
        lVar21 = -0xe;
        goto LAB_001086fc;
      }
    }
    else {
      if (iVar5 != 2) {
        _printk(&DAT_00116885,"process_invoke_req",iVar5);
        lVar21 = -1;
        goto LAB_001086fc;
      }
      local_148 = (void *)param_3[2];
      uStack_140 = param_3[3];
      local_158 = *param_3;
      local_150 = param_3[1];
    }
LAB_00107a2c:
    if (local_150._4_4_ == 0x18) {
      if ((((iVar5 != 0) || (piVar17[1] != 1)) || (9 < (uint)local_158)) ||
         ((1 << (ulong)((uint)local_158 & 0x1f) & 0x330U) == 0)) {
        lVar21 = ((ulong)(local_158._4_4_ >> 4) & 0xf) + ((ulong)local_158._4_4_ & 0xf) +
                 ((ulong)(local_158._4_4_ >> 0xc) & 0xf) + ((ulong)(local_158._4_4_ >> 8) & 0xf);
        iVar32 = (int)lVar21;
        if (iVar32 == 0) {
          uVar31 = 0;
          __dest = (void *)0x0;
          goto LAB_00107bd0;
        }
        uVar31 = lVar21 * 0x18;
        __dest = (void *)__kmalloc(uVar31,0xdc0);
        pvVar9 = local_148;
        if (__dest == (void *)0x0) {
          lVar21 = -0xc;
          goto LAB_001086fc;
        }
        if (iVar5 == 0) {
          uVar18 = (ulong)(uint)(local_150._4_4_ * iVar32);
          if (local_150._4_4_ * iVar32 < 0) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x800,0x10896c);
            (*pcVar10)();
          }
          __check_object_size(__dest,uVar18,0);
          puVar20 = (undefined8 *)sp_el0;
          if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
             (pvVar23 = pvVar9, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
            pvVar23 = (void *)((ulong)pvVar9 & ((long)pvVar9 << 8) >> 8);
          }
          uVar26 = uVar18;
          if (pvVar23 <= (void *)(0x8000000000 - uVar18)) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar26 = daif;
              if ((uVar26 & 0x80) == 0) {
                uVar19 = daif;
                daif = uVar19 | 0xc0;
              }
              puVar20 = (undefined8 *)puVar20[1];
              uVar19 = ttbr1_el1;
              ttbr1_el1 = (ulong)puVar20 & 0xffff000000000000 | uVar19 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar20;
              InstructionSynchronizationBarrier();
              daif = uVar26;
            }
            uVar26 = __arch_copy_from_user(puVar20,__dest,(ulong)pvVar9 & 0xff7fffffffffffff,uVar18)
            ;
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar19 = daif;
              if ((uVar19 & 0x80) == 0) {
                uVar27 = daif;
                daif = uVar27 | 0xc0;
              }
              uVar27 = ttbr1_el1;
              ttbr0_el1 = (uVar27 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar27 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar19;
            }
          }
          if ((uVar26 == 0) ||
             (memset((void *)((long)__dest + (uVar18 - uVar26)),0,uVar26), (int)uVar26 == 0))
          goto LAB_00107bd0;
          uVar13 = 0xfffffff2;
        }
        else {
          memcpy(__dest,local_148,(ulong)(uint)(local_150._4_4_ * iVar32));
LAB_00107bd0:
          uVar13 = (local_158._4_4_ >> 4 & 0xf) + (local_158._4_4_ & 0xf);
          uVar18 = (ulong)(((local_158._4_4_ >> 0xc & 0xf) + (local_158._4_4_ >> 8 & 0xf) + uVar13)
                           * 8 + 0x13) & 0x3f8;
          if (uVar13 != 0) {
            lVar21 = 0;
            uVar26 = uVar31 - 8;
            do {
              if ((uVar31 < lVar21 + 8U) || (uVar26 < 8)) goto LAB_00108960;
              uVar27 = *(ulong *)((long)__dest + lVar21 + 8);
              uVar26 = uVar26 - 0x18;
              lVar21 = lVar21 + 0x18;
              uVar28 = (ulong)(uint)-(int)uVar27 & 7;
              uVar19 = uVar27 + uVar28;
              if (CARRY8(uVar27,uVar28)) {
                uVar19 = 0xffffffffffffffff;
              }
              bVar11 = CARRY8(uVar18,uVar19);
              uVar18 = uVar18 + uVar19;
              if (bVar11) {
                uVar18 = 0xffffffffffffffff;
              }
            } while ((ulong)uVar13 * 0x18 != lVar21);
          }
          uVar18 = uVar18 + 0xfff & 0xfffffffffffff000;
          iVar12 = qtee_shmbridge_allocate_shm(uVar18,&local_170);
          piVar8 = local_168;
          if (iVar12 == 0) {
            mutex_lock(&g_smcinvoke_lock);
            uVar26 = g_max_cb_buf_size + 0xfffU & 0xfffffffffffff000;
            mutex_unlock(&g_smcinvoke_lock);
            iVar12 = qtee_shmbridge_allocate_shm(uVar26,&local_188);
            __s = local_180;
            if (iVar12 == 0) {
              uVar19 = (((ulong)(local_158._4_4_ >> 4) & 0xf) + ((ulong)local_158._4_4_ & 0xf) +
                       ((ulong)(local_158._4_4_ >> 8) & 0xf) +
                       ((ulong)(local_158._4_4_ >> 0xc) & 0xf)) * 8 + 0xc;
              if (uVar18 < uVar19) {
LAB_001083f0:
                uVar13 = 0xffffffea;
LAB_00108648:
                _printk(&DAT_00116c7f,"process_invoke_req",uVar13);
                goto LAB_00108660;
              }
              iVar12 = piVar17[1];
              piVar8[2] = local_158._4_4_;
              *piVar8 = iVar12;
              piVar8[1] = (uint)local_158;
              if (__dest != (void *)0x0) {
                if ((local_158 & 0xf00000000) == 0) {
                  uVar13 = 0;
                }
                else {
                  lVar21 = 0;
                  puVar20 = (undefined8 *)sp_el0;
                  do {
                    uVar19 = ((ulong)(uint)-(int)uVar19 & 7) + uVar19;
                    uVar27 = uVar19 & 0xffffffff;
                    if (uVar18 < uVar27) goto LAB_001083f0;
                    uVar22 = lVar21 * 0x18;
                    uVar28 = uVar22 + 8;
                    if ((uVar31 < uVar28) || (uVar31 - uVar28 < 8)) goto LAB_00108960;
                    puVar24 = (ulong *)((long)__dest + uVar22);
                    if (uVar18 - uVar27 < puVar24[1]) {
                      uVar13 = 0xffffffea;
                      goto LAB_00108648;
                    }
                    piVar8[lVar21 * 2 + 3] = (int)uVar19;
                    if ((uVar31 < uVar28) || (uVar31 - uVar28 < 8)) goto LAB_00108960;
                    (piVar8 + lVar21 * 2 + 3)[1] = (int)puVar24[1];
                    if (iVar5 == 2) {
                      if (((uVar31 < uVar28) || (uVar31 - uVar28 < 8)) || (uVar31 <= uVar22))
                      goto LAB_00108960;
                      memcpy((void *)((long)piVar8 + uVar27),(void *)*puVar24,puVar24[1]);
                    }
                    else {
                      if (((uVar31 <= uVar22) || (uVar31 < uVar28)) || (uVar31 - uVar28 < 8))
                      goto LAB_00108960;
                      uVar22 = puVar24[1];
                      if (uVar22 >> 0x1f != 0) {
                    /* WARNING: Does not return */
                        pcVar10 = (code *)SoftwareBreakpoint(0x800,0x108904);
                        (*pcVar10)();
                      }
                      uVar25 = *puVar24;
                      lVar2 = (long)piVar8 + uVar27;
                      __check_object_size(lVar2,uVar22,0);
                      if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
                         (uVar27 = uVar25, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
                        uVar27 = uVar25 & (long)(uVar25 << 8) >> 8;
                      }
                      uVar15 = uVar22;
                      if (uVar27 <= 0x8000000000 - uVar22) {
                        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                          uVar27 = daif;
                          if ((uVar27 & 0x80) == 0) {
                            uVar15 = daif;
                            daif = uVar15 | 0xc0;
                          }
                          uVar15 = ttbr1_el1;
                          ttbr1_el1 = puVar20[1] & 0xffff000000000000 | uVar15 & 0xffffffffffff;
                          InstructionSynchronizationBarrier();
                          ttbr0_el1 = puVar20[1];
                          InstructionSynchronizationBarrier();
                          daif = uVar27;
                        }
                        uVar15 = __arch_copy_from_user(lVar2,uVar25 & 0xff7fffffffffffff,uVar22);
                        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                          uVar27 = daif;
                          if ((uVar27 & 0x80) == 0) {
                            uVar25 = daif;
                            daif = uVar25 | 0xc0;
                          }
                          uVar25 = ttbr1_el1;
                          ttbr0_el1 = (uVar25 & 0xffffffffffff) - 0x1000;
                          InstructionSynchronizationBarrier();
                          ttbr1_el1 = uVar25 & 0xffffffffffff;
                          InstructionSynchronizationBarrier();
                          daif = uVar27;
                        }
                      }
                      if (uVar15 != 0) {
                        memset((void *)(lVar2 + (uVar22 - uVar15)),0,uVar15);
                        uVar13 = 0xffffffea;
                        goto LAB_00108648;
                      }
                    }
                    if ((uVar31 < uVar28) || (uVar31 - uVar28 < 8)) goto LAB_00108960;
                    uVar14 = (int)lVar21 + 1;
                    lVar21 = (long)(int)uVar14;
                    uVar19 = puVar24[1] + uVar19 & 0xffffffff;
                    uVar13 = local_158._4_4_ & 0xf;
                  } while (uVar14 < uVar13);
                }
                if ((local_158._4_4_ >> 4 & 0xf) == 0) {
                  uVar27 = (ulong)uVar13;
                  if ((local_158._4_4_ & 0xf00) != 0) goto LAB_00108038;
                }
                else {
                  uVar22 = (ulong)uVar13;
                  lVar21 = uVar22 + (ulong)uVar13 * 2;
                  uVar25 = (uVar31 + lVar21 * -8) - 8;
                  uVar28 = lVar21 * 8 + 8;
                  piVar17 = piVar8 + (ulong)uVar13 * 2 + 4;
                  do {
                    uVar19 = ((ulong)(uint)-(int)uVar19 & 7) + uVar19;
                    uVar27 = uVar19 & 0xffffffff;
                    if (uVar18 < uVar27) goto LAB_001083f0;
                    if ((uVar31 < uVar28) || (uVar25 < 8)) goto LAB_00108960;
                    if (uVar18 - uVar27 < *(ulong *)((long)__dest + uVar28)) goto LAB_001083f0;
                    iVar12 = (int)uVar19;
                    piVar17[-1] = iVar12;
                    if (((uVar31 < uVar28) || (uVar25 < 8)) ||
                       (*piVar17 = (int)*(undefined8 *)((long)__dest + uVar28), uVar25 < 8))
                    goto LAB_00108960;
                    piVar1 = (int *)((long)__dest + uVar28);
                    uVar22 = uVar22 + 1;
                    uVar25 = uVar25 - 0x18;
                    uVar28 = uVar28 + 0x18;
                    piVar17 = piVar17 + 2;
                    uVar19 = (ulong)(uint)(*piVar1 + iVar12);
                    uVar27 = ((ulong)(local_158._4_4_ >> 4) & 0xf) + ((ulong)local_158._4_4_ & 0xf);
                  } while (uVar22 < uVar27);
                  if ((local_158 & 0xf0000000000) != 0) {
LAB_00108038:
                    lVar21 = 0;
                    uVar7 = sp_el0;
LAB_00108050:
                    uVar19 = uVar27 * 0x18;
                    if ((uVar31 <= uVar19) ||
                       (uVar28 = uVar19 + 8, uVar31 < uVar28 || uVar31 - uVar28 < 8)) {
LAB_00108960:
                    /* WARNING: Does not return */
                      pcVar10 = (code *)SoftwareBreakpoint(1,0x108964);
                      (*pcVar10)();
                    }
                    lVar2 = uVar27 * 2;
                    uVar13 = get_tzhandle_from_uhandle
                                       (*(undefined4 *)((long)__dest + uVar19),
                                        ((undefined4 *)((long)__dest + uVar19))[2],local_e8 + lVar21
                                        ,piVar8 + lVar2 + 3,&local_198);
                    if (uVar13 != 0) goto LAB_00108648;
                    if (((uVar31 <= uVar19) || (uVar31 < uVar28)) ||
                       ((uVar31 - uVar28 < 8 || (0x3b < (ulong)(lVar21 * 4))))) goto LAB_00108960;
                    uVar27 = uVar27 + 1;
                    *(int *)((long)&local_128 + lVar21 * 4) = piVar8[lVar2 + 3];
                    lVar21 = lVar21 + 1;
                    if (uVar27 < ((ulong)(local_158._4_4_ >> 4) & 0xf) +
                                 ((ulong)local_158._4_4_ & 0xf) +
                                 ((ulong)(local_158._4_4_ >> 8) & 0xf)) goto LAB_00108050;
                  }
                }
              }
              if (mem_obj_async_support == '\x01') {
                mutex_lock(&g_smcinvoke_lock);
                add_mem_obj_info_to_async_side_channel_locked(__s,uVar26,&local_198);
                mutex_unlock(&g_smcinvoke_lock);
              }
              uVar13 = prepare_send_scm_msg
                                 (piVar8,local_170,uVar18,__s,local_188,uVar26,&local_158,__dest,
                                  acStack_19c,iVar5,&local_170,&local_188,1);
              pvVar9 = local_148;
              if (acStack_19c[0] == '\0') goto LAB_00108660;
              local_f0 = 0;
              local_128 = 0;
              local_120 = 0;
              local_100 = 0;
              local_f8 = 0;
              local_110 = 0;
              local_108 = 0;
              local_118 = 0;
              if ((int)local_150 == 0) {
                if (iVar5 != 0) {
                  memcpy(local_148,__dest,(ulong)(uint)(local_150._4_4_ * iVar32));
                  goto LAB_0010833c;
                }
                uVar14 = local_150._4_4_ * iVar32;
                uVar31 = (ulong)uVar14;
                if ((int)uVar14 < 0) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x800,0x1089a8);
                  (*pcVar10)();
                }
                __check_object_size(__dest,uVar31,1);
                puVar20 = (undefined8 *)sp_el0;
                if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
                   (pvVar23 = pvVar9, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
                  pvVar23 = (void *)((ulong)pvVar9 & ((long)pvVar9 << 8) >> 8);
                }
                if (pvVar23 <= (void *)(0x8000000000 - uVar31)) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar18 = daif;
                    if ((uVar18 & 0x80) == 0) {
                      uVar19 = daif;
                      daif = uVar19 | 0xc0;
                    }
                    puVar20 = (undefined8 *)puVar20[1];
                    uVar19 = ttbr1_el1;
                    ttbr1_el1 = (ulong)puVar20 & 0xffff000000000000 | uVar19 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar20;
                    InstructionSynchronizationBarrier();
                    daif = uVar18;
                  }
                  uVar14 = __arch_copy_to_user(puVar20,(ulong)pvVar9 & 0xff7fffffffffffff,__dest,
                                               uVar31);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar31 = daif;
                    if ((uVar31 & 0x80) == 0) {
                      uVar18 = daif;
                      daif = uVar18 | 0xc0;
                    }
                    uVar18 = ttbr1_el1;
                    ttbr0_el1 = (uVar18 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar18 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar31;
                  }
                }
                uVar13 = uVar13 | uVar14;
LAB_00108500:
                puVar20 = (undefined8 *)sp_el0;
                if (((*(byte *)((long)puVar20 + 0x46) >> 5 & 1) != 0) ||
                   (puVar24 = param_3, ((uint)*puVar20 >> 0x1a & 1) != 0)) {
                  puVar24 = (ulong *)((ulong)param_3 & ((long)param_3 << 8) >> 8);
                }
                uVar14 = 0x20;
                if (puVar24 < (ulong *)0x7fffffffe1) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar31 = daif;
                    if ((uVar31 & 0x80) == 0) {
                      uVar18 = daif;
                      daif = uVar18 | 0xc0;
                    }
                    puVar20 = (undefined8 *)puVar20[1];
                    uVar18 = ttbr1_el1;
                    ttbr1_el1 = (ulong)puVar20 & 0xffff000000000000 | uVar18 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar20;
                    InstructionSynchronizationBarrier();
                    daif = uVar31;
                  }
                  uVar14 = __arch_copy_to_user(puVar20,(ulong)param_3 & 0xff7fffffffffffff,
                                               &local_158,0x20);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar31 = daif;
                    if ((uVar31 & 0x80) == 0) {
                      uVar18 = daif;
                      daif = uVar18 | 0xc0;
                    }
                    uVar18 = ttbr1_el1;
                    ttbr0_el1 = (uVar18 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar18 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar31;
                  }
                }
                uVar13 = uVar13 | uVar14;
                if (uVar13 != 0) goto LAB_00108660;
              }
              else {
                if (iVar5 == 0) goto LAB_00108500;
LAB_0010833c:
                param_3[2] = (ulong)local_148;
                param_3[3] = uStack_140;
                *param_3 = local_158;
                param_3[1] = local_150;
              }
              local_138 = 0;
              local_130 = 0;
              if (*__s != 0) {
                if (__s[2] != 0) {
                  uVar14 = 0;
                  do {
                    if (__s[1] != 0xffff) break;
                    local_130 = 0xffff;
                    local_138 = CONCAT44(__s[(long)(int)uVar14 + 3],(undefined4)local_138);
                    if ((tz_async_version == 0) &&
                       (tz_async_version = *__s, 0x10001 < tz_async_version)) {
                      mem_obj_async_support = '\x01';
                    }
                    process_tzcb_req(&local_138,0x10,0);
                    uVar14 = uVar14 + 1;
                  } while (uVar14 < __s[2]);
                }
                memset(__s,0,uVar26);
              }
              goto LAB_00108660;
            }
            puVar16 = &DAT_00118465;
          }
          else {
            puVar16 = &DAT_00116764;
          }
          _printk(puVar16,"process_invoke_req");
          uVar13 = 0xfffffff4;
        }
LAB_00108660:
        release_filp(local_e8);
        bVar11 = (long ********)local_198 != &local_198;
        ppppppplVar29 = local_198;
        if (uVar13 == 0) {
          while( true ) {
            if (!bVar11) break;
            ppppppplVar30 = (long *******)*ppppppplVar29;
            ppppppplVar29[-1] = (long ******)0x0;
            uVar31 = __list_del_entry_valid(ppppppplVar29);
            if ((uVar31 & 1) != 0) {
              pppppplVar3 = *ppppppplVar29;
              pppppplVar4 = ppppppplVar29[1];
              pppppplVar3[1] = (long *****)pppppplVar4;
              *pppppplVar4 = (long *****)pppppplVar3;
            }
            *ppppppplVar29 = (long ******)0xdead000000000100;
            ppppppplVar29[1] = (long ******)0xdead000000000122;
            kfree(ppppppplVar29 + -1);
            bVar11 = (long ********)ppppppplVar30 != &local_198;
            ppppppplVar29 = ppppppplVar30;
          }
          qtee_shmbridge_free_shm(&local_170);
          qtee_shmbridge_free_shm(&local_188);
          kfree(__dest);
        }
        else {
          while (bVar11) {
            pppppplVar3 = ppppppplVar29[-1];
            ppppppplVar29 = (long *******)*ppppppplVar29;
            piVar17 = (int *)((long)pppppplVar3 + 0x24);
            Hint_Prefetch(piVar17,2,0,1);
            do {
              iVar5 = *piVar17;
              cVar6 = '\x01';
              bVar11 = (bool)ExclusiveMonitorPass(piVar17,0x10);
              if (bVar11) {
                *piVar17 = iVar5 + -1;
                cVar6 = ExclusiveMonitorsStatus();
              }
            } while (cVar6 != '\0');
            if (iVar5 == 1) {
              DataMemoryBarrier(2,1);
              pppppplVar3[5] = (long *****)0x0;
              pppppplVar3[6] = (long *****)0x0;
              if (pppppplVar3[3] != (long *****)0x0) {
                dma_buf_unmap_attachment(pppppplVar3[2],pppppplVar3[3],0);
              }
              if (pppppplVar3[2] != (long *****)0x0) {
                dma_buf_detach(pppppplVar3[1]);
              }
              if (*(int *)(pppppplVar3 + 4) == 0) {
                free_mem_obj_locked(pppppplVar3);
              }
            }
            else if (iVar5 < 1) {
              refcount_warn_saturate(piVar17,3);
            }
            bVar11 = (long ********)ppppppplVar29 != &local_198;
          }
          mutex_lock(&g_smcinvoke_lock);
          release_tzhandle_locked(local_128 & 0xffffffff);
          release_tzhandle_locked(local_128._4_4_);
          release_tzhandle_locked(local_120 & 0xffffffff);
          release_tzhandle_locked(local_120._4_4_);
          release_tzhandle_locked(local_118 & 0xffffffff);
          release_tzhandle_locked(local_118._4_4_);
          release_tzhandle_locked(local_110 & 0xffffffff);
          release_tzhandle_locked(local_110._4_4_);
          release_tzhandle_locked(local_108 & 0xffffffff);
          release_tzhandle_locked(local_108._4_4_);
          release_tzhandle_locked(local_100 & 0xffffffff);
          release_tzhandle_locked(local_100._4_4_);
          release_tzhandle_locked(local_f8 & 0xffffffff);
          release_tzhandle_locked(local_f8._4_4_);
          release_tzhandle_locked(local_f0);
          mutex_unlock(&g_smcinvoke_lock);
          if ((long ********)local_198 != &local_198) {
            ppppppplVar29 = local_198;
            do {
              ppppppplVar30 = (long *******)*ppppppplVar29;
              ppppppplVar29[-1] = (long ******)0x0;
              uVar31 = __list_del_entry_valid(ppppppplVar29);
              if ((uVar31 & 1) != 0) {
                pppppplVar3 = *ppppppplVar29;
                pppppplVar4 = ppppppplVar29[1];
                pppppplVar3[1] = (long *****)pppppplVar4;
                *pppppplVar4 = (long *****)pppppplVar3;
              }
              *ppppppplVar29 = (long ******)0xdead000000000100;
              ppppppplVar29[1] = (long ******)0xdead000000000122;
              kfree(ppppppplVar29 + -1);
              ppppppplVar29 = ppppppplVar30;
            } while ((long ********)ppppppplVar30 != &local_198);
          }
          qtee_shmbridge_free_shm(&local_170);
          qtee_shmbridge_free_shm(&local_188);
          kfree(__dest);
          _printk(&DAT_001164c8,"process_invoke_req",uVar13);
        }
        lVar21 = (long)(int)uVar13;
        goto LAB_001086fc;
      }
      puVar16 = &DAT_00116970;
    }
    else {
      puVar16 = &DAT_00117313;
    }
  }
  else {
    puVar16 = &DAT_00117c72;
  }
  _printk(puVar16,"process_invoke_req");
  lVar21 = -0x16;
LAB_001086fc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_e8[0xf]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar21);
  }
  return;
}



//------------------------------------------------------------
// smcinvoke_release_filp @ 00108bcc size=528
// signature: undefined smcinvoke_release_filp(void)
// callers: [smcinvoke_release, smcinvoke_release_from_kernel_client]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int smcinvoke_release_filp(long param_1)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined *puVar7;
  int *piVar8;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  uVar3 = sp_el0;
  piVar8 = *(int **)(param_1 + 0xd8);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_78 = 0;
  if (*piVar8 == 1) {
    release_cb_server((short)piVar8[1]);
  }
  else {
    uVar1 = piVar8[1];
    if (1 < uVar1) {
      iVar4 = qtee_shmbridge_allocate_shm(0x1000,&local_60);
      if (iVar4 == 0) {
        iVar4 = qtee_shmbridge_allocate_shm(0x1000,&local_78);
        if (iVar4 == 0) {
          iVar4 = smcinvoke_release_tz_object(&local_60,&local_78,uVar1,*piVar8);
          if (iVar4 != -0x10) goto LAB_00108d30;
          puVar5 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x18);
          if (puVar5 == (undefined8 *)0x0) {
            iVar4 = -0xc;
            goto LAB_00108d30;
          }
          *(uint *)(puVar5 + 2) = uVar1;
          *(int *)((long)puVar5 + 0x14) = *piVar8;
          mutex_lock(&object_postprocess_lock);
          puVar7 = PTR_g_object_postprocess_00114cd0;
          uVar6 = __list_add_valid(puVar5,PTR_g_object_postprocess_00114cd0,&g_object_postprocess);
          if ((uVar6 & 1) != 0) {
            PTR_g_object_postprocess_00114cd0 = (undefined *)puVar5;
            *puVar5 = &g_object_postprocess;
            puVar5[1] = puVar7;
            *(undefined8 **)puVar7 = puVar5;
          }
          mutex_unlock(&object_postprocess_lock);
          DAT_0011852c = 1;
          __wake_up(&DAT_00118530,1,1,0);
          goto LAB_00108d2c;
        }
        puVar7 = &DAT_001165b4;
      }
      else {
        puVar7 = &DAT_0011747e;
      }
      _printk(puVar7,"smcinvoke_release_filp",iVar4);
      goto LAB_00108d30;
    }
    if (uVar1 == 0) {
      _printk(&DAT_00116f04,"smcinvoke_release_filp");
    }
  }
LAB_00108d2c:
  iVar4 = 0;
LAB_00108d30:
  qtee_shmbridge_free_shm(&local_60);
  qtee_shmbridge_free_shm(&local_78);
  kfree(*(undefined8 *)(param_1 + 0xd8));
  *(undefined8 *)(param_1 + 0xd8) = 0;
  if (iVar4 != 0) {
    _printk(&DAT_00116268,"smcinvoke_release_filp",iVar4);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// release_cb_server @ 00108e88 size=244
// signature: undefined release_cb_server(void)
// callers: [smcinvoke_release_filp, smcinvoke_ioctl]
//------------------------------------------------------------

void release_cb_server(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  ushort *puVar5;
  long *plVar6;
  long lVar7;
  
  mutex_lock(&g_smcinvoke_lock);
  puVar5 = (ushort *)
           (*(long *)(g_cb_servers + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x18) * 8) + -0x148)
  ;
  if (*(long *)(g_cb_servers + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x18) * 8) != 0 &&
      puVar5 != (ushort *)0x0) {
    do {
      if ((uint)*puVar5 == (param_1 & 0xffff)) {
        puVar1 = puVar5 + 4;
        Hint_Prefetch(puVar1,2,0,1);
        do {
          iVar2 = *(int *)puVar1;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *(int *)puVar1 = iVar2 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (iVar2 == 1) {
          DataMemoryBarrier(2,1);
          plVar6 = *(long **)(puVar5 + 0xa8);
          if (plVar6 != (long *)0x0) {
            puVar1 = puVar5 + 0xa4;
            lVar7 = *(long *)puVar1;
            *plVar6 = lVar7;
            if (lVar7 != 0) {
              *(long **)(lVar7 + 8) = plVar6;
            }
            puVar1[0] = 0;
            puVar1[1] = 0;
            puVar1[2] = 0;
            puVar1[3] = 0;
            puVar5[0xa8] = 0;
            puVar5[0xa9] = 0;
            puVar5[0xaa] = 0;
            puVar5[0xab] = 0;
          }
          kfree();
        }
        else if (iVar2 < 1) {
          refcount_warn_saturate(puVar1,3);
        }
        break;
      }
    } while ((*(long *)(puVar5 + 0xa4) != 0) &&
            (puVar5 = (ushort *)(*(long *)(puVar5 + 0xa4) + -0x148), puVar5 != (ushort *)0x0));
  }
  mutex_unlock(&g_smcinvoke_lock);
  return;
}



//------------------------------------------------------------
// smcinvoke_release_tz_object @ 00108f8c size=432
// signature: undefined smcinvoke_release_tz_object(void)
// callers: [smcinvoke_release_filp, smcinvoke_postprocess_kthread_func]
//------------------------------------------------------------

int smcinvoke_release_tz_object
              (undefined8 *param_1,undefined8 *param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *__s;
  uint uVar5;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 auStack_7c [4];
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  puVar4 = (undefined4 *)param_1[1];
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  __s = (uint *)param_2[1];
  *puVar4 = param_3;
  *(undefined8 *)(puVar4 + 1) = 0xffff;
  iVar2 = prepare_send_scm_msg
                    (puVar4,*param_1,0x1000,__s,*param_2,0x1000,&local_a0,0,auStack_7c,param_4,
                     param_1,param_2,0);
  local_78 = 0;
  local_70 = 0;
  if (*__s != 0) {
    if (__s[2] != 0) {
      uVar5 = 0;
      do {
        if (__s[1] != 0xffff) break;
        local_70 = 0xffff;
        local_78 = CONCAT44(__s[(long)(int)uVar5 + 3],(undefined4)local_78);
        if (tz_async_version == 0) {
          tz_async_version = *__s;
          if (0x10001 < tz_async_version) {
            mem_obj_async_support = 1;
          }
        }
        process_tzcb_req(&local_78,0x10,0);
        uVar5 = uVar5 + 1;
      } while (uVar5 < __s[2]);
    }
    memset(__s,0,0x1000);
  }
  if ((iVar2 != 0) &&
     (iVar3 = ___ratelimit(smcinvoke_release_tz_object__rs,"smcinvoke_release_tz_object"),
     iVar3 != 0)) {
    _printk(&DAT_00116fe8,"smcinvoke_release_tz_object",param_3,iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// smcinvoke_release_from_kernel_client @ 00109140 size=132
// signature: undefined smcinvoke_release_from_kernel_client(void)
// callers: [invoke_over_smcinvoke]
//------------------------------------------------------------

undefined8 smcinvoke_release_from_kernel_client(undefined4 param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = fget();
  if (lVar2 == 0) {
    _printk(&DAT_00116bed,"smcinvoke_release_from_kernel_client",param_1);
    uVar3 = 0xffffffea;
  }
  else {
    lVar1 = sp_el0;
    smcinvoke_release_filp(*(undefined8 *)(lVar1 + 0x878),lVar2);
    fput(lVar2);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// init_module @ 0010926c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&smcinvoke_plat_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010929c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&smcinvoke_plat_driver);
  return;
}



//------------------------------------------------------------
// trace_raw_output_put_pending_cbobj_locked @ 001092c4 size=104
// signature: undefined trace_raw_output_put_pending_cbobj_locked(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_put_pending_cbobj_locked(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"srvr_id=0x%x obj_id=0x%x\n",*(undefined2 *)(lVar2 + 8),
                       *(undefined2 *)(lVar2 + 10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_release_mem_obj_locked @ 00109330 size=104
// signature: undefined trace_raw_output_release_mem_obj_locked(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_release_mem_obj_locked(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"tzhandle=0x%08x, buf_len=%zu\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_invoke_cmd_handler @ 0010939c size=116
// signature: undefined trace_raw_output_invoke_cmd_handler(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_invoke_cmd_handler(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"cmd=0x%x (%d), response_type=%llu, result=0x%x (%d), ret=%d\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x18),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_tzcb_req_handle @ 00109414 size=104
// signature: undefined trace_raw_output_process_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_tzcb_req_handle(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"tzhandle=0x%08x op=0x%02x counts=0x%04x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_tzcb_req_wait @ 00109480 size=136
// signature: undefined trace_raw_output_process_tzcb_req_wait(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_tzcb_req_wait(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "tzhandle=0x%08x, retries=%d, txn_id=%d, pid %x,tid %x, srvr state=%d, server_id=0x%x, cb_reqs_inflight=%d\n"
                       ,*(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined2 *)(lVar2 + 0x1c),
                       *(undefined2 *)(lVar2 + 0x1e),*(undefined4 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_tzcb_req_result @ 0010950c size=108
// signature: undefined trace_raw_output_process_tzcb_req_result(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_tzcb_req_result(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "result=%d tzhandle=0x%08x op=0x%02x counts=0x%04x, cb_reqs_inflight=%d\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_marshal_out_invoke_req @ 0010957c size=108
// signature: undefined trace_raw_output_marshal_out_invoke_req(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_marshal_out_invoke_req(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"OO[%d]: tzhandle=0x%x server=0x%x fd=0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined2 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_prepare_send_scm_msg @ 001095ec size=112
// signature: undefined trace_raw_output_prepare_send_scm_msg(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_prepare_send_scm_msg(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar3 = *(undefined8 *)(lVar4 + 8);
    uVar1 = *(undefined4 *)(lVar4 + 0x10);
    trace_event_printf(param_1,"response_type=%llu (%llu), result=0x%x (%d)\n",uVar3,uVar3,uVar1,
                       uVar1);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_marshal_in_invoke_req @ 00109660 size=108
// signature: undefined trace_raw_output_marshal_in_invoke_req(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_marshal_in_invoke_req(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"OI[%d]: fd=%lld cb_server_fd=0x%x tzhandle=0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_marshal_in_tzcb_req_handle @ 001096d0 size=108
// signature: undefined trace_raw_output_marshal_in_tzcb_req_handle(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_marshal_in_tzcb_req_handle(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,
                       "tzhandle=0x%x srvr_id=0x%x cbobj_id=0x%08x op=0x%02x counts=0x%04x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_marshal_in_tzcb_req_fd @ 00109740 size=104
// signature: undefined trace_raw_output_marshal_in_tzcb_req_fd(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_marshal_in_tzcb_req_fd(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"OI[%d]: tzhandle=0x%x srvr_id=0x%x fd=0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_marshal_out_tzcb_req @ 001097ac size=104
// signature: undefined trace_raw_output_marshal_out_tzcb_req(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_marshal_out_tzcb_req(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"OO[%d]: fd=0x%x cb_server_fd=0x%x tzhandle=0x%x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_invoke_req_tzhandle @ 00109818 size=104
// signature: undefined trace_raw_output_process_invoke_req_tzhandle(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_invoke_req_tzhandle
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"tzhandle=0x%08x op=0x%02x counts=0x%04x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_invoke_req_result @ 00109884 size=108
// signature: undefined trace_raw_output_process_invoke_req_result(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_invoke_req_result(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"ret=%d result=%d tzhandle=0x%08x op=0x%02x counts=0x%04x\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_log_info @ 001098f4 size=108
// signature: undefined trace_raw_output_process_log_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_log_info(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s context_type=%d tzhandle=0x%08x\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_smcinvoke_ioctl @ 00109964 size=124
// signature: undefined trace_raw_output_smcinvoke_ioctl(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_smcinvoke_ioctl(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    uVar2 = trace_print_symbols_seq
                      (param_1 + 0x90,*(undefined4 *)(lVar3 + 8),
                       &trace_raw_output_smcinvoke_ioctl_symbols);
    trace_event_printf(param_1,"cmd=%s ret=%ld\n",uVar2,*(undefined8 *)(lVar3 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_smcinvoke_create_bridge @ 001099e4 size=104
// signature: undefined trace_raw_output_smcinvoke_create_bridge(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_smcinvoke_create_bridge(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"created shm bridge handle %llu for mem_region_id %u\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined2 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_status @ 00109a50 size=112
// signature: undefined trace_raw_output_status(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_status(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s status=%s\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_accept_req_has_response @ 00109ac4 size=100
// signature: undefined trace_raw_output_process_accept_req_has_response(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_accept_req_has_response
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=0x%x, tgid=0x%x\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_accept_req_ret @ 00109b2c size=104
// signature: undefined trace_raw_output_process_accept_req_ret(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_accept_req_ret(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=0x%x tgid=0x%x ret=%d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_accept_req_placed @ 00109b98 size=100
// signature: undefined trace_raw_output_process_accept_req_placed(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_accept_req_placed(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"pid=0x%x, tgid=0x%x\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_process_invoke_request_from_kernel_client @ 00109c00 size=108
// signature: undefined trace_raw_output_process_invoke_request_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_process_invoke_request_from_kernel_client
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"fd=%d, filp=%p, f_count=%d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_smcinvoke_release_filp @ 00109c70 size=104
// signature: undefined trace_raw_output_smcinvoke_release_filp(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_smcinvoke_release_filp(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"files=%p, filp=%p, f_count=%u, cxt_type=%d\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined4 *)(lVar2 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_smcinvoke_release_from_kernel_client @ 00109cdc size=104
// signature: undefined trace_raw_output_smcinvoke_release_from_kernel_client(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_smcinvoke_release_from_kernel_client
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"files=%p, filp=%p, f_count=%u\n",*(undefined8 *)(lVar2 + 8),
                       *(undefined8 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_smcinvoke_release @ 00109d48 size=108
// signature: undefined trace_raw_output_smcinvoke_release(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_smcinvoke_release(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"files=%p, filp=%p, f_count=%d, private_data=%p\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined8 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// smcinvoke_ioctl @ 00109db8 size=7860
// signature: undefined smcinvoke_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long smcinvoke_ioctl(long param_1,int param_2,ulong param_3)

{
  uint *puVar1;
  uint *puVar2;
  long ****pppplVar3;
  long ****pppplVar4;
  char cVar5;
  bool bVar6;
  uint uVar7;
  ulong uVar8;
  long *****ppppplVar9;
  code *pcVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  size_t sVar14;
  long lVar15;
  long lVar16;
  undefined *puVar17;
  char *pcVar18;
  undefined8 uVar19;
  ushort uVar20;
  uint uVar21;
  undefined8 *puVar22;
  ulong uVar23;
  ulong uVar24;
  long *plVar25;
  ulong uVar26;
  long *plVar27;
  uint uVar28;
  uint uVar29;
  long *plVar30;
  ulong uVar31;
  ulong uVar32;
  uint uVar33;
  uint *puVar34;
  ushort *puVar35;
  long *plVar36;
  long lVar37;
  long lVar38;
  int *piVar39;
  long *****ppppplVar40;
  uint *puVar41;
  ulong uVar42;
  int *piVar43;
  uint local_184;
  undefined8 local_138;
  ulong local_130;
  undefined8 uStack_128;
  ulong local_120;
  undefined8 local_118;
  ulong local_110;
  long local_108;
  ulong local_100;
  ulong local_f8;
  undefined8 local_f0;
  long *****local_e8;
  long *****local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  uint local_78;
  undefined1 auStack_74 [4];
  long local_70;
  
  lVar38 = sp_el0;
  local_70 = *(long *)(lVar38 + 0x638);
  lVar38 = -0x203;
  uVar28 = (uint)_cpu_hwcaps;
  if (param_2 < -0x3fdf67ff) {
    if (param_2 == -0x3ff767fc) {
LAB_0010a300:
      lVar38 = -0x16;
      goto code_r0x0010c024;
    }
    if (param_2 != -0x3fef67fd) goto code_r0x0010c024;
    puVar22 = (undefined8 *)sp_el0;
    local_d8 = 0;
    local_d0 = 0;
    local_138 = CONCAT44(local_138._4_4_,0xffffffff);
    if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
       (uVar23 = param_3, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
      uVar23 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar23 < 0x7ffffffff1) {
      if ((uVar28 >> 0x1d & 1) == 0) {
        uVar23 = daif;
        if ((uVar23 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        puVar22 = (undefined8 *)puVar22[1];
        uVar24 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar22 & 0xffff000000000000 | uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar22;
        InstructionSynchronizationBarrier();
        daif = uVar23;
      }
      sVar14 = __arch_copy_from_user(puVar22,&local_d8,param_3 & 0xff7fffffffffffff,0x10);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar23 = daif;
        if ((uVar23 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar23;
      }
      if (sVar14 != 0) goto LAB_0010b9d4;
    }
    else {
      sVar14 = 0x10;
LAB_0010b9d4:
      memset(auStack_74 + (-0x54 - sVar14),0,sVar14);
      if ((int)sVar14 != 0) {
        puVar17 = &DAT_001176f1;
        pcVar18 = "process_server_req";
        goto LAB_0010b9c4;
      }
    }
    puVar13 = (ushort *)kmalloc_trace(__printk,0xdc0,0x170);
    if (puVar13 == (ushort *)0x0) {
      lVar38 = -0xc;
    }
    else {
      puVar13[4] = 1;
      puVar13[5] = 0;
      __init_waitqueue_head(puVar13 + 8,"&server_info->req_wait_q",&process_server_req___key);
      __init_waitqueue_head(puVar13 + 0x14,"&server_info->rsp_wait_q",&process_server_req___key_206)
      ;
      puVar13[0x28] = 0;
      puVar13[0x29] = 0;
      puVar13[0x2a] = 0;
      puVar13[0x2b] = 0;
      puVar13[0x2c] = 0;
      puVar13[0x2d] = 0;
      puVar13[0x2e] = 0;
      puVar13[0x2f] = 0;
      puVar13[0x30] = 0;
      puVar13[0x31] = 0;
      puVar13[0x32] = 0;
      puVar13[0x33] = 0;
      puVar13[0x34] = 0;
      puVar13[0x35] = 0;
      puVar13[0x36] = 0;
      puVar13[0x37] = 0;
      *(ulong *)(puVar13 + 0x20) = local_d8;
      puVar13[0x24] = 0;
      puVar13[0x25] = 0;
      puVar13[0x26] = 0;
      puVar13[0x27] = 0;
      puVar13[0x38] = 0;
      puVar13[0x39] = 0;
      puVar13[0x3a] = 0;
      puVar13[0x3b] = 0;
      puVar13[0x3c] = 0;
      puVar13[0x3d] = 0;
      puVar13[0x3e] = 0;
      puVar13[0x3f] = 0;
      puVar13[0x40] = 0;
      puVar13[0x41] = 0;
      puVar13[0x42] = 0;
      puVar13[0x43] = 0;
      puVar13[0x44] = 0;
      puVar13[0x45] = 0;
      puVar13[0x46] = 0;
      puVar13[0x47] = 0;
      puVar13[0x48] = 0;
      puVar13[0x49] = 0;
      puVar13[0x4a] = 0;
      puVar13[0x4b] = 0;
      puVar13[0x4c] = 0;
      puVar13[0x4d] = 0;
      puVar13[0x4e] = 0;
      puVar13[0x4f] = 0;
      puVar13[0x50] = 0;
      puVar13[0x51] = 0;
      puVar13[0x52] = 0;
      puVar13[0x53] = 0;
      puVar13[0x54] = 0;
      puVar13[0x55] = 0;
      puVar13[0x56] = 0;
      puVar13[0x57] = 0;
      puVar13[0x58] = 0;
      puVar13[0x59] = 0;
      puVar13[0x5a] = 0;
      puVar13[0x5b] = 0;
      puVar13[0x5c] = 0;
      puVar13[0x5d] = 0;
      puVar13[0x5e] = 0;
      puVar13[0x5f] = 0;
      puVar13[0x60] = 0;
      puVar13[0x61] = 0;
      puVar13[0x62] = 0;
      puVar13[99] = 0;
      puVar13[100] = 0;
      puVar13[0x65] = 0;
      puVar13[0x66] = 0;
      puVar13[0x67] = 0;
      puVar13[0x68] = 0;
      puVar13[0x69] = 0;
      puVar13[0x6a] = 0;
      puVar13[0x6b] = 0;
      puVar13[0x6c] = 0;
      puVar13[0x6d] = 0;
      puVar13[0x6e] = 0;
      puVar13[0x6f] = 0;
      puVar13[0x70] = 0;
      puVar13[0x71] = 0;
      puVar13[0x72] = 0;
      puVar13[0x73] = 0;
      puVar13[0x74] = 0;
      puVar13[0x75] = 0;
      puVar13[0x76] = 0;
      puVar13[0x77] = 0;
      puVar13[0x78] = 0;
      puVar13[0x79] = 0;
      puVar13[0x7a] = 0;
      puVar13[0x7b] = 0;
      puVar13[0x7c] = 0;
      puVar13[0x7d] = 0;
      puVar13[0x7e] = 0;
      puVar13[0x7f] = 0;
      puVar13[0x80] = 0;
      puVar13[0x81] = 0;
      puVar13[0x82] = 0;
      puVar13[0x83] = 0;
      puVar13[0x84] = 0;
      puVar13[0x85] = 0;
      puVar13[0x86] = 0;
      puVar13[0x87] = 0;
      puVar13[0x88] = 0;
      puVar13[0x89] = 0;
      puVar13[0x8a] = 0;
      puVar13[0x8b] = 0;
      puVar13[0x8c] = 0;
      puVar13[0x8d] = 0;
      puVar13[0x8e] = 0;
      puVar13[0x8f] = 0;
      puVar13[0x90] = 0;
      puVar13[0x91] = 0;
      puVar13[0x92] = 0;
      puVar13[0x93] = 0;
      puVar13[0x94] = 0;
      puVar13[0x95] = 0;
      puVar13[0x96] = 0;
      puVar13[0x97] = 0;
      puVar13[0x98] = 0;
      puVar13[0x99] = 0;
      puVar13[0x9a] = 0;
      puVar13[0x9b] = 0;
      puVar13[0x9c] = 0;
      puVar13[0x9d] = 0;
      puVar13[0x9e] = 0;
      puVar13[0x9f] = 0;
      puVar13[0xa0] = 0;
      puVar13[0xa1] = 0;
      puVar13[0xa2] = 0;
      puVar13[0xa3] = 0;
      *(ushort **)(puVar13 + 0xac) = puVar13 + 0xac;
      *(ushort **)(puVar13 + 0xb0) = puVar13 + 0xac;
      *(undefined1 *)(puVar13 + 0xb4) = 0;
      mutex_lock(&g_smcinvoke_lock);
      uVar28 = 0x11;
      if ((g_last_cb_server_id + 1 & 0x10000) == 0) {
        uVar28 = g_last_cb_server_id + 1;
      }
      g_last_cb_server_id = (ushort)uVar28;
      uVar23 = (ulong)((uVar28 & 0xffff) * 0x61c88647 >> 0x18);
      lVar38 = *(long *)(g_cb_servers + uVar23 * 8);
      uVar20 = g_last_cb_server_id;
      if ((lVar38 != 0) && (puVar35 = (ushort *)(lVar38 + -0x148), puVar35 != (ushort *)0x0)) {
        do {
          while ((uint)*puVar35 != (uVar28 & 0xffff)) {
            if ((*(long *)(puVar35 + 0xa4) == 0) ||
               (puVar35 = (ushort *)(*(long *)(puVar35 + 0xa4) + -0x148), puVar35 == (ushort *)0x0))
            {
              uVar23 = (ulong)((uVar28 & 0xffff) * 0x61c88647 >> 0x18);
              lVar38 = *(long *)(g_cb_servers + uVar23 * 8);
              uVar20 = (ushort)uVar28;
              goto LAB_0010aa24;
            }
          }
          uVar28 = uVar28 + 1;
          g_last_cb_server_id = (ushort)uVar28;
          uVar23 = (ulong)((uVar28 & 0xffff) * 0x61c88647 >> 0x18);
          lVar38 = *(long *)(g_cb_servers + uVar23 * 8);
          puVar35 = (ushort *)(lVar38 + -0x148);
          uVar20 = g_last_cb_server_id;
        } while (!(lVar38 == 0 || puVar35 == (ushort *)0x0));
      }
LAB_0010aa24:
      *puVar13 = uVar20;
      *(long *)(puVar13 + 0xa4) = lVar38;
      if (lVar38 != 0) {
        *(ushort **)(lVar38 + 8) = puVar13 + 0xa4;
      }
      *(ushort **)(g_cb_servers + uVar23 * 8) = puVar13 + 0xa4;
      *(undefined1 **)(puVar13 + 0xa8) = g_cb_servers + uVar23 * 8;
      if (g_max_cb_buf_size < local_d8) {
        g_max_cb_buf_size = local_d8;
      }
      mutex_unlock(&g_smcinvoke_lock);
      iVar11 = get_fd_for_obj(1,*puVar13,&local_138);
      if (iVar11 != 0) {
        release_cb_server(*puVar13);
      }
      lVar38 = (long)(int)local_138;
    }
    goto code_r0x0010c024;
  }
  if (param_2 == -0x3f9b6701) {
    local_78 = 0;
    puVar22 = (undefined8 *)sp_el0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_b8 = 0;
    local_b0 = 0;
    local_c8 = 0;
    local_c0 = 0;
    local_d8 = 0;
    local_d0 = 0;
    if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
       (uVar23 = param_3, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
      uVar23 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar23 < 0x7fffffff9d) {
      if ((uVar28 >> 0x1d & 1) == 0) {
        uVar23 = daif;
        if ((uVar23 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar22[1];
        InstructionSynchronizationBarrier();
        daif = uVar23;
      }
      sVar14 = __arch_copy_from_user(&local_d8,param_3 & 0xff7fffffffffffff,100);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar23 = daif;
        if ((uVar23 & 0x80) == 0) {
          uVar24 = daif;
          daif = uVar24 | 0xc0;
        }
        uVar24 = ttbr1_el1;
        ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar24 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar23;
      }
      if (sVar14 != 0) goto LAB_0010b96c;
    }
    else {
      sVar14 = 100;
LAB_0010b96c:
      memset(auStack_74 + -sVar14,0,sVar14);
      if ((int)sVar14 != 0) {
        puVar17 = &DAT_00117b6e;
        pcVar18 = "process_log_info";
        goto LAB_0010b9c4;
      }
    }
    local_78 = local_78 & 0xffffff;
    lVar38 = 0;
  }
  else {
    if (param_2 != -0x3fc767fe) {
      if (param_2 == -0x3fdf67ff) {
        lVar38 = process_invoke_req(param_1,0xc0209801,param_3);
      }
      goto code_r0x0010c024;
    }
    piVar39 = *(int **)(param_1 + 0xd8);
    puVar22 = (undefined8 *)sp_el0;
    local_110 = 0;
    local_108 = 0;
    local_120 = 0;
    local_118 = 0;
    local_130 = 0;
    uStack_128 = 0;
    local_138 = 0;
    uVar23 = (long)(param_3 << 8) >> 8;
    if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
       (uVar24 = param_3, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
      uVar24 = param_3 & uVar23;
    }
    if (uVar24 < 0x7fffffffc9) {
      if ((uVar28 >> 0x1d & 1) == 0) {
        uVar24 = daif;
        if ((uVar24 & 0x80) == 0) {
          uVar42 = daif;
          daif = uVar42 | 0xc0;
        }
        uVar42 = ttbr1_el1;
        ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar42 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar22[1];
        InstructionSynchronizationBarrier();
        daif = uVar24;
      }
      sVar14 = __arch_copy_from_user(&local_138,param_3 & 0xff7fffffffffffff,0x38);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar24 = daif;
        if ((uVar24 & 0x80) == 0) {
          uVar42 = daif;
          daif = uVar42 | 0xc0;
        }
        uVar42 = ttbr1_el1;
        ttbr0_el1 = (uVar42 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar42 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar24;
      }
      if (sVar14 == 0) {
        if (uStack_128._4_4_ != 0x18) {
          _printk(&DAT_00118364,"process_accept_req");
          lVar38 = -0x16;
          goto code_r0x0010c024;
        }
        if (*piVar39 != 1) {
          _printk(&DAT_0011785c,"process_accept_req");
          lVar38 = -1;
          goto code_r0x0010c024;
        }
        mutex_lock(&g_smcinvoke_lock);
        plVar25 = *(long **)(g_cb_servers +
                            (ulong)((uint)*(ushort *)(piVar39 + 1) * 0x61c88647 >> 0x18) * 8);
        if (plVar25 != (long *)0x0) {
          while( true ) {
            puVar13 = (ushort *)(plVar25 + -0x29);
            if (puVar13 == (ushort *)0x0) goto LAB_0010a2e0;
            if ((uint)*puVar13 == (uint)*(ushort *)(piVar39 + 1)) break;
            plVar25 = (long *)*plVar25;
            if (plVar25 == (long *)0x0) goto LAB_0010a2e0;
          }
          puVar1 = (uint *)(plVar25 + -0x28);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            uVar28 = *puVar1;
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar6) {
              *puVar1 = uVar28 + 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          if (uVar28 == 0) {
            uVar19 = 2;
LAB_0010bb90:
            refcount_warn_saturate(puVar1,uVar19);
          }
          else if ((int)(uVar28 + 1 | uVar28) < 0) {
            uVar19 = 1;
            goto LAB_0010bb90;
          }
          if (*(short *)((long)plVar25 + -0x146) == 1) {
            *(undefined2 *)((long)plVar25 + -0x146) = 0;
          }
          *(byte *)(plVar25 + 4) =
               *(byte *)(plVar25 + 4) & ((byte)(1 << (ulong)(*(uint *)(puVar22 + 0xc6) & 3)) ^ 0xff)
          ;
          mutex_unlock(&g_smcinvoke_lock);
          if ((int)local_138 == 0) {
LAB_0010a3e4:
            plVar30 = plVar25 + -0x27;
            if (plVar25[-0x20] != 0) goto LAB_0010a558;
LAB_0010a3f8:
            if (((((plVar25[-0x1f] == 0) && (plVar25[-0x1e] == 0)) && (plVar25[-0x1d] == 0)) &&
                ((plVar25[-0x1c] == 0 && (plVar25[-0x1b] == 0)))) &&
               ((((plVar25[-0x1a] == 0 && ((plVar25[-0x19] == 0 && (plVar25[-0x18] == 0)))) &&
                 (plVar25[-0x17] == 0)) &&
                ((((plVar25[-0x16] == 0 && (plVar25[-0x15] == 0)) && (plVar25[-0x14] == 0)) &&
                 (((plVar25[-0x13] == 0 && (plVar25[-0x12] == 0)) && (plVar25[-0x11] == 0)))))))) {
              local_c0 = 0;
              local_b8 = 0;
              local_d0 = 0;
              local_c8 = 0;
              local_d8 = 0;
              init_wait_entry(&local_d8,0);
              lVar38 = prepare_to_wait_event(plVar30,&local_d8,1);
              if (plVar25[-0x20] == 0) {
                do {
                  if ((((plVar25[-0x1f] != 0) || (plVar25[-0x1e] != 0)) ||
                      ((plVar25[-0x1d] != 0 ||
                       (((plVar25[-0x1c] != 0 || (plVar25[-0x1b] != 0)) || (plVar25[-0x1a] != 0)))))
                      ) || (((plVar25[-0x19] != 0 || (plVar25[-0x18] != 0)) ||
                            ((plVar25[-0x17] != 0 ||
                             (((plVar25[-0x16] != 0 || (plVar25[-0x15] != 0)) ||
                              ((plVar25[-0x14] != 0 ||
                               (((plVar25[-0x13] != 0 || (plVar25[-0x12] != 0)) ||
                                (plVar25[-0x11] != 0)))))))))))) break;
                  if (lVar38 != 0) {
                    if ((int)lVar38 == 0) goto LAB_0010a558;
                    mutex_lock(&g_smcinvoke_lock);
                    iVar11 = ___ratelimit(&process_accept_req__rs_178,"process_accept_req");
                    if (iVar11 != 0) {
                      _printk(&DAT_00116442,"process_accept_req",*(undefined4 *)(puVar22 + 0xc6),
                              *puVar13);
                    }
                    *(undefined2 *)((long)plVar25 + -0x146) = 1;
                    goto LAB_0010bf50;
                  }
                  schedule();
                  lVar38 = prepare_to_wait_event(plVar30,&local_d8,1);
                } while (plVar25[-0x20] == 0);
              }
              finish_wait(plVar30,&local_d8);
            }
LAB_0010a558:
            mutex_lock(&g_smcinvoke_lock);
            plVar36 = (long *)plVar25[-0x20];
            if ((((((plVar36 == (long *)0x0) ||
                   (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                  ((plVar36 = (long *)plVar25[-0x1f], plVar36 == (long *)0x0 ||
                   (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))) &&
                 (((plVar36 = (long *)plVar25[-0x1e], plVar36 == (long *)0x0 ||
                   (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                  (((((plVar36 = (long *)plVar25[-0x1d], plVar36 == (long *)0x0 ||
                      (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                     ((((plVar36 = (long *)plVar25[-0x1c], plVar36 == (long *)0x0 ||
                        (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                       ((plVar36 = (long *)plVar25[-0x1b], plVar36 == (long *)0x0 ||
                        (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))) &&
                      ((plVar36 = (long *)plVar25[-0x1a], plVar36 == (long *)0x0 ||
                       (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))))) &&
                    ((plVar36 = (long *)plVar25[-0x19], plVar36 == (long *)0x0 ||
                     (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))) &&
                   (((((plVar36 = (long *)plVar25[-0x18], plVar36 == (long *)0x0 ||
                       (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                      ((plVar36 = (long *)plVar25[-0x17], plVar36 == (long *)0x0 ||
                       (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))) &&
                     (((plVar36 = (long *)plVar25[-0x16], plVar36 == (long *)0x0 ||
                       (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                      ((plVar36 = (long *)plVar25[-0x15], plVar36 == (long *)0x0 ||
                       (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))))) &&
                    (((plVar36 = (long *)plVar25[-0x14], plVar36 == (long *)0x0 ||
                      (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)) &&
                     ((plVar36 = (long *)plVar25[-0x13], plVar36 == (long *)0x0 ||
                      (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))))))))))) &&
                ((plVar36 = (long *)plVar25[-0x12], plVar36 == (long *)0x0 ||
                 (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))) &&
               ((plVar36 = (long *)plVar25[-0x11], plVar36 == (long *)0x0 ||
                (puVar41 = (uint *)(plVar36 + -4), puVar41 == (uint *)0x0)))) goto LAB_0010a660;
            puVar34 = (uint *)(plVar36 + 2);
            Hint_Prefetch(puVar34,2,0,1);
            do {
              uVar28 = *puVar34;
              cVar5 = '\x01';
              bVar6 = (bool)ExclusiveMonitorPass(puVar34,0x10);
              if (bVar6) {
                *puVar34 = uVar28 + 1;
                cVar5 = ExclusiveMonitorsStatus();
              }
            } while (cVar5 != '\0');
            if (uVar28 == 0) {
              uVar19 = 2;
LAB_0010bbf4:
              refcount_warn_saturate(puVar34,uVar19);
              plVar30 = (long *)plVar36[1];
            }
            else {
              if ((int)(uVar28 + 1 | uVar28) < 0) {
                uVar19 = 1;
                goto LAB_0010bbf4;
              }
              plVar30 = (long *)plVar36[1];
            }
            if (plVar30 != (long *)0x0) {
              lVar38 = *plVar36;
              *plVar30 = lVar38;
              if (lVar38 != 0) {
                *(long **)(lVar38 + 8) = plVar30;
              }
              *plVar36 = 0;
              plVar36[1] = 0;
            }
            mutex_unlock(&g_smcinvoke_lock);
            puVar41[1] = 2;
            local_100 = CONCAT44(local_100._4_4_,0xffffffff);
            iVar11 = piVar39[1];
            local_d0 = 0;
            local_c8 = 0;
            local_d8 = 0;
            lVar16 = *(long *)(puVar41 + 2);
            uVar24 = *(ulong *)(puVar41 + 4);
            uVar28 = *(uint *)(lVar16 + 0xc);
            lVar38 = ((ulong)(uVar28 >> 4) & 0xf) + ((ulong)uVar28 & 0xf) +
                     ((ulong)(uVar28 >> 8) & 0xf) + ((ulong)(uVar28 >> 0xc) & 0xf);
            if (uVar24 < lVar38 * 8 + 0x10U) goto LAB_0010afa4;
            local_120 = (ulong)*puVar41;
            iVar12 = get_uhandle_from_tzhandle
                               (*(undefined4 *)(lVar16 + 4),(short)iVar11,&local_118,1,0);
            if (iVar12 != 0) goto LAB_0010afa4;
            local_130 = *(ulong *)(lVar16 + 8);
            uVar42 = lVar38 * 0x18;
            uStack_128 = CONCAT44(0x18,(undefined4)uStack_128);
            uVar28 = *(uint *)(lVar16 + 0xc);
            lVar38 = lVar16 + 0x10;
            if ((uVar28 & 0xf) != 0) {
              lVar37 = 0;
              do {
                puVar34 = (uint *)(lVar38 + lVar37 * 8);
                uVar31 = (ulong)(uint)-(int)uVar42 & 7;
                uVar32 = uVar42 + uVar31;
                local_d0 = (ulong)puVar34[1];
                if (CARRY8(uVar42,uVar31)) {
                  uVar32 = 0xffffffffffffffff;
                }
                if ((((uVar24 < *puVar34) || (uVar24 - *puVar34 < (ulong)puVar34[1])) ||
                    (local_110 < uVar32)) || (local_110 - uVar32 < local_d0)) {
LAB_0010afac:
                  _printk(&DAT_00116a28,"marshal_in_tzcb_req","marshal_in_tzcb_req");
                  lVar38 = 0xffffffea;
                  goto LAB_0010afc8;
                }
                local_d8 = local_108 + uVar32;
                uVar42 = local_108 + lVar37 * 0x18;
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar31 = uVar42, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar31 = uVar42 & (long)(uVar42 * 0x100) >> 8;
                }
                if (0x7fffffffe8 < uVar31) goto LAB_0010aec4;
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar31 = daif;
                  if ((uVar31 & 0x80) == 0) {
                    uVar26 = daif;
                    daif = uVar26 | 0xc0;
                  }
                  uVar26 = ttbr1_el1;
                  ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar26 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar22[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar31;
                }
                lVar15 = __arch_copy_to_user(uVar42 & 0xff7fffffffffffff,&local_d8,0x18);
                uVar42 = local_d8;
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar31 = daif;
                  if ((uVar31 & 0x80) == 0) {
                    uVar26 = daif;
                    daif = uVar26 | 0xc0;
                  }
                  uVar26 = ttbr1_el1;
                  ttbr0_el1 = (uVar26 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar26 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar31;
                }
                if (lVar15 != 0) goto LAB_0010aec4;
                uVar31 = (ulong)puVar34[1];
                if ((int)puVar34[1] < 0) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x800,0x10b8d0);
                  (*pcVar10)();
                }
                uVar28 = *puVar34;
                __check_object_size(lVar16 + (ulong)uVar28,uVar31,1);
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar26 = uVar42, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar26 = uVar42 & (long)(uVar42 << 8) >> 8;
                }
                if (uVar26 <= 0x8000000000 - uVar31) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar26 = daif;
                    if ((uVar26 & 0x80) == 0) {
                      uVar8 = daif;
                      daif = uVar8 | 0xc0;
                    }
                    uVar8 = ttbr1_el1;
                    ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar8 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar22[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar26;
                  }
                  uVar31 = __arch_copy_to_user(uVar42 & 0xff7fffffffffffff,lVar16 + (ulong)uVar28,
                                               uVar31);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar42 = daif;
                    if ((uVar42 & 0x80) == 0) {
                      uVar26 = daif;
                      daif = uVar26 | 0xc0;
                    }
                    uVar26 = ttbr1_el1;
                    ttbr0_el1 = (uVar26 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar26 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar42;
                  }
                }
                if (uVar31 != 0) goto LAB_0010aec4;
                uVar21 = (int)lVar37 + 1;
                uVar28 = *(uint *)(lVar16 + 0xc);
                lVar37 = (long)(int)uVar21;
                uVar42 = local_d0 + uVar32;
                uVar29 = uVar28 & 0xf;
                if (uVar29 <= uVar21) goto LAB_0010aa90;
              } while( true );
            }
            uVar29 = 0;
LAB_0010aa90:
            if ((uVar28 >> 4 & 0xf) == 0) {
LAB_0010abfc:
              if ((uVar28 & 0xf00) == 0) {
LAB_0010ae1c:
                mutex_lock(&g_smcinvoke_lock);
                puVar35 = puVar13 + (ulong)(*puVar41 * 0x61c88647 >> 0x1c) * 4 + 100;
                lVar38 = *(long *)puVar35;
                puVar34 = puVar41 + 8;
                *(long *)puVar34 = lVar38;
                if (lVar38 != 0) {
                  *(uint **)(lVar38 + 8) = puVar34;
                }
                *(uint **)puVar35 = puVar34;
                puVar2 = puVar41 + 0xc;
                *(ushort **)(puVar41 + 10) = puVar35;
                Hint_Prefetch(puVar2,2,0,1);
                do {
                  uVar28 = *puVar2;
                  cVar5 = '\x01';
                  bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                  if (bVar6) {
                    *puVar2 = uVar28 - 1;
                    cVar5 = ExclusiveMonitorsStatus();
                  }
                } while (cVar5 != '\0');
                if (uVar28 == 1) {
                  DataMemoryBarrier(2,1);
                  lVar38 = *(long *)(puVar41 + 2);
                  if (*(short *)(lVar38 + 8) == -1) {
                    release_tzhandle_locked(*(undefined4 *)(lVar38 + 4));
                    lVar38 = *(long *)(puVar41 + 2);
                  }
                  kfree(lVar38);
                  plVar30 = *(long **)(puVar41 + 10);
                  if (plVar30 != (long *)0x0) {
                    lVar38 = *(long *)puVar34;
                    *plVar30 = lVar38;
                    if (lVar38 != 0) {
                      *(long **)(lVar38 + 8) = plVar30;
                    }
                    puVar34[0] = 0;
                    puVar34[1] = 0;
                    puVar41[10] = 0;
                    puVar41[0xb] = 0;
                  }
                  kfree(puVar41);
                }
                else if ((int)uVar28 < 1) {
                  refcount_warn_saturate(puVar2,3);
                }
                mutex_unlock(&g_smcinvoke_lock);
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar24 = param_3, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar24 = param_3 & uVar23;
                }
                iVar11 = 0x38;
                if (uVar24 < 0x7fffffffc9) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar23 = daif;
                    if ((uVar23 & 0x80) == 0) {
                      uVar24 = daif;
                      daif = uVar24 | 0xc0;
                    }
                    uVar24 = ttbr1_el1;
                    ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar24 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar22[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar23;
                  }
                  iVar11 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,&local_138,0x38);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar23 = daif;
                    if ((uVar23 & 0x80) == 0) {
                      uVar24 = daif;
                      daif = uVar24 | 0xc0;
                    }
                    uVar24 = ttbr1_el1;
                    ttbr0_el1 = (uVar24 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar24 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar23;
                  }
                }
                goto LAB_0010bf70;
              }
              uVar24 = (ulong)uVar29;
              while( true ) {
                local_100 = CONCAT44(local_100._4_4_,0xffffffff);
                iVar12 = get_uhandle_from_tzhandle
                                   (*(undefined4 *)(lVar38 + uVar24 * 8),(short)iVar11,&local_100,1,
                                    0);
                local_d8 = (ulong)(int)local_100;
                if (iVar12 != 0) goto LAB_0010afa4;
                uVar42 = local_108 + uVar24 * 0x18;
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar32 = uVar42, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar32 = uVar42 & (long)(uVar42 * 0x100) >> 8;
                }
                if (0x7fffffffe8 < uVar32) break;
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar32 = daif;
                  if ((uVar32 & 0x80) == 0) {
                    uVar31 = daif;
                    daif = uVar31 | 0xc0;
                  }
                  uVar31 = ttbr1_el1;
                  ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar31 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar22[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar32;
                }
                lVar37 = __arch_copy_to_user(uVar42 & 0xff7fffffffffffff,&local_d8,0x18);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar42 = daif;
                  if ((uVar42 & 0x80) == 0) {
                    uVar32 = daif;
                    daif = uVar32 | 0xc0;
                  }
                  uVar32 = ttbr1_el1;
                  ttbr0_el1 = (uVar32 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar32 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar42;
                }
                if (lVar37 != 0) break;
                uVar28 = *(uint *)(lVar16 + 0xc);
                uVar24 = uVar24 + 1;
                if (((ulong)(uVar28 >> 4) & 0xf) + ((ulong)uVar28 & 0xf) +
                    ((ulong)(uVar28 >> 8) & 0xf) <= uVar24) goto LAB_0010ae1c;
              }
            }
            else {
              uVar24 = (ulong)uVar29;
              while( true ) {
                uVar31 = (ulong)(uint)-(int)uVar42 & 7;
                uVar32 = uVar42 + uVar31;
                local_d0 = (ulong)*(uint *)(lVar38 + uVar24 * 8 + 4);
                if (CARRY8(uVar42,uVar31)) {
                  uVar32 = 0xffffffffffffffff;
                }
                if (local_110 < uVar32 || local_110 - uVar32 < local_d0) goto LAB_0010afac;
                local_d8 = local_108 + uVar32;
                uVar42 = local_108 + uVar24 * 0x18;
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar31 = uVar42, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar31 = uVar42 & (long)(uVar42 * 0x100) >> 8;
                }
                if (0x7fffffffe8 < uVar31) break;
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar31 = daif;
                  if ((uVar31 & 0x80) == 0) {
                    uVar26 = daif;
                    daif = uVar26 | 0xc0;
                  }
                  uVar26 = ttbr1_el1;
                  ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar26 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar22[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar31;
                }
                lVar37 = __arch_copy_to_user(uVar42 & 0xff7fffffffffffff,&local_d8,0x18);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar42 = daif;
                  if ((uVar42 & 0x80) == 0) {
                    uVar31 = daif;
                    daif = uVar31 | 0xc0;
                  }
                  uVar31 = ttbr1_el1;
                  ttbr0_el1 = (uVar31 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar31 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar42;
                }
                if (lVar37 != 0) break;
                uVar21 = (int)uVar24 + 1;
                uVar28 = *(uint *)(lVar16 + 0xc);
                uVar24 = (ulong)(int)uVar21;
                uVar42 = local_d0 + uVar32;
                uVar29 = (uVar28 >> 4 & 0xf) + (uVar28 & 0xf);
                if (uVar29 <= uVar21) goto LAB_0010abfc;
              }
            }
LAB_0010aec4:
            lVar38 = 0xfffffff2;
            goto LAB_0010afc8;
          }
          mutex_lock(&g_smcinvoke_lock);
          plVar30 = *(long **)(puVar13 +
                              (ulong)((uint)((int)local_120 * 0x61c88647) >> 0x1c) * 4 + 100);
          while( true ) {
            if ((plVar30 == (long *)0x0) || (plVar36 = plVar30 + -4, plVar36 == (long *)0x0)) {
              mutex_unlock(&g_smcinvoke_lock);
              iVar11 = ___ratelimit(process_accept_req__rs,"process_accept_req");
              if (iVar11 != 0) {
                _printk(&DAT_001161c4,"process_accept_req","process_accept_req",local_120);
              }
              goto LAB_0010a3e4;
            }
            if ((int)*plVar36 == (int)local_120) break;
            plVar30 = (long *)*plVar30;
          }
          puVar41 = (uint *)(plVar30 + 2);
          Hint_Prefetch(puVar41,2,0,1);
          do {
            uVar28 = *puVar41;
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(puVar41,0x10);
            if (bVar6) {
              *puVar41 = uVar28 + 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          if (uVar28 == 0) {
            uVar19 = 2;
LAB_0010c174:
            refcount_warn_saturate(puVar41,uVar19);
          }
          else if ((int)(uVar28 + 1 | uVar28) < 0) {
            uVar19 = 1;
            goto LAB_0010c174;
          }
          plVar27 = (long *)plVar30[1];
          if (plVar27 != (long *)0x0) {
            lVar38 = *plVar30;
            *plVar27 = lVar38;
            if (lVar38 != 0) {
              *(long **)(lVar38 + 8) = plVar27;
            }
            *plVar30 = 0;
            plVar30[1] = 0;
          }
          mutex_unlock(&g_smcinvoke_lock);
          lVar38 = plVar30[-1];
          local_a0 = (ulong)local_a0._4_4_ << 0x20;
          local_b0 = 0;
          local_a8 = 0;
          local_c0 = 0;
          local_b8 = 0;
          local_d0 = 0;
          local_c8 = 0;
          local_d8 = 0;
          piVar43 = (int *)plVar30[-3];
          local_e8 = (long *****)&local_e8;
          uVar28 = piVar43[3];
          local_e0 = local_e8;
          if (1 < (piVar43[1] & 0x8000ffffU) + 0x7fffffff) {
            mutex_lock(&g_smcinvoke_lock);
            release_tzhandle_locked(piVar43[1]);
            mutex_unlock(&g_smcinvoke_lock);
          }
          *piVar43 = local_138._4_4_;
          if (local_138._4_4_ == 0) {
            uVar24 = (ulong)(uint)piVar43[3];
            uVar42 = uVar24 & 0xf;
            uVar21 = (uint)uVar42;
            if (uVar21 == 0) {
              local_184 = 0;
              uVar29 = 0;
            }
            else {
              uVar29 = 0;
              local_184 = 0;
              puVar34 = (uint *)(piVar43 + 5);
              uVar32 = uVar42;
              do {
                if (uVar29 < puVar34[-1]) {
                  local_184 = *puVar34;
                  uVar29 = puVar34[-1];
                }
                uVar32 = uVar32 - 1;
                puVar34 = puVar34 + 2;
              } while (uVar32 != 0);
            }
            if (((uint)piVar43[3] >> 4 & 0xf) == 0) {
LAB_0010b3cc:
              if ((uVar24 & 0xf000) == 0) {
LAB_0010b624:
                iVar11 = 0;
              }
              else {
                uVar7 = (uint)uVar24 >> 8 & 0xf;
                uVar33 = uVar7 + uVar21;
                uVar24 = (ulong)uVar7 + (ulong)uVar21;
                if (uVar33 < 0x10) {
                  uVar33 = 0xf;
                }
                while( true ) {
                  local_f8 = 0;
                  local_f0 = 0;
                  local_100 = 0;
                  uVar42 = local_108 + uVar24 * 0x18;
                  if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                     (uVar32 = uVar42, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                    uVar32 = uVar42 & (long)(uVar42 * 0x100) >> 8;
                  }
                  if (0x7fffffffe8 < uVar32) break;
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar32 = daif;
                    if ((uVar32 & 0x80) == 0) {
                      uVar31 = daif;
                      daif = uVar31 | 0xc0;
                    }
                    uVar31 = ttbr1_el1;
                    ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar31 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar22[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar32;
                  }
                  lVar16 = __arch_copy_from_user(&local_100,uVar42 & 0xff7fffffffffffff,0x18);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar42 = daif;
                    if ((uVar42 & 0x80) == 0) {
                      uVar32 = daif;
                      daif = uVar32 | 0xc0;
                    }
                    uVar32 = ttbr1_el1;
                    ttbr0_el1 = (uVar32 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar32 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar42;
                  }
                  if (lVar16 != 0) break;
                  iVar11 = get_tzhandle_from_uhandle
                                     (local_100 & 0xffffffff,local_f8 & 0xffffffff,
                                      lVar38 + uVar24 * 8,piVar43 + uVar24 * 2 + 4,&local_e8);
                  if (iVar11 != 0) goto LAB_0010b634;
                  if (uVar24 == uVar33) {
                    /* WARNING: Does not return */
                    pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x10ba68);
                    (*pcVar10)();
                  }
                  if ((0x3b < uVar24 * 4) || (0x3b < uVar24 * 4)) {
                    /* WARNING: Does not return */
                    pcVar10 = (code *)SoftwareBreakpoint(1,0x10ba64);
                    (*pcVar10)();
                  }
                  *(int *)(auStack_74 + uVar24 * 4 + -100) = piVar43[uVar24 * 2 + 4];
                  uVar21 = piVar43[3];
                  uVar24 = uVar24 + 1;
                  if (((ulong)(uVar21 >> 4) & 0xf) + ((ulong)uVar21 & 0xf) +
                      ((ulong)(uVar21 >> 8) & 0xf) + ((ulong)(uVar21 >> 0xc) & 0xf) <= uVar24)
                  goto LAB_0010b624;
                }
                iVar11 = -0xe;
              }
            }
            else {
              while( true ) {
                local_f8 = 0;
                local_f0 = 0;
                local_100 = 0;
                uVar24 = local_108 + uVar42 * 0x18;
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar32 = uVar24, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar32 = uVar24 & (long)(uVar24 * 0x100) >> 8;
                }
                if (0x7fffffffe8 < uVar32) break;
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar32 = daif;
                  if ((uVar32 & 0x80) == 0) {
                    uVar31 = daif;
                    daif = uVar31 | 0xc0;
                  }
                  uVar31 = ttbr1_el1;
                  ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar31 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar22[1];
                  InstructionSynchronizationBarrier();
                  daif = uVar32;
                }
                lVar16 = __arch_copy_from_user(&local_100,uVar24 & 0xff7fffffffffffff,0x18);
                uVar32 = local_f8;
                uVar24 = local_100;
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar31 = daif;
                  if ((uVar31 & 0x80) == 0) {
                    uVar26 = daif;
                    daif = uVar26 | 0xc0;
                  }
                  uVar26 = ttbr1_el1;
                  ttbr0_el1 = (uVar26 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar26 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar31;
                }
                if (lVar16 != 0) break;
                puVar34 = (uint *)(piVar43 + uVar42 * 2 + 4);
                if (puVar34[1] < local_f8) {
                  iVar11 = -0x16;
                  goto LAB_0010b634;
                }
                if (local_f8 >> 0x1f != 0) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x800,0x10ba30);
                  (*pcVar10)();
                }
                lVar16 = (long)piVar43 + (ulong)*puVar34;
                __check_object_size(lVar16,local_f8,0);
                if (((*(byte *)((long)puVar22 + 0x46) >> 5 & 1) != 0) ||
                   (uVar31 = uVar24, ((uint)*puVar22 >> 0x1a & 1) != 0)) {
                  uVar31 = uVar24 & (long)(uVar24 << 8) >> 8;
                }
                uVar26 = uVar32;
                if (uVar31 <= 0x8000000000 - uVar32) {
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar31 = daif;
                    if ((uVar31 & 0x80) == 0) {
                      uVar26 = daif;
                      daif = uVar26 | 0xc0;
                    }
                    uVar26 = ttbr1_el1;
                    ttbr1_el1 = puVar22[1] & 0xffff000000000000 | uVar26 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    ttbr0_el1 = puVar22[1];
                    InstructionSynchronizationBarrier();
                    daif = uVar31;
                  }
                  uVar26 = __arch_copy_from_user(lVar16,uVar24 & 0xff7fffffffffffff,uVar32);
                  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                    uVar24 = daif;
                    if ((uVar24 & 0x80) == 0) {
                      uVar31 = daif;
                      daif = uVar31 | 0xc0;
                    }
                    uVar31 = ttbr1_el1;
                    ttbr0_el1 = (uVar31 & 0xffffffffffff) - 0x1000;
                    InstructionSynchronizationBarrier();
                    ttbr1_el1 = uVar31 & 0xffffffffffff;
                    InstructionSynchronizationBarrier();
                    daif = uVar24;
                  }
                }
                if (uVar26 != 0) {
                  memset((void *)(lVar16 + (uVar32 - uVar26)),0,uVar26);
                  iVar11 = -0xe;
                  goto LAB_0010b634;
                }
                if (uVar29 < *puVar34) {
                  local_184 = puVar34[1];
                  uVar29 = *puVar34;
                }
                uVar33 = (int)uVar42 + 1;
                uVar42 = (ulong)(int)uVar33;
                uVar21 = piVar43[3];
                uVar24 = (ulong)uVar21;
                uVar21 = (uVar21 >> 4 & 0xf) + (uVar21 & 0xf);
                if (uVar21 <= uVar33) goto LAB_0010b3cc;
              }
              iVar11 = -0xe;
            }
          }
          else {
            local_184 = 0;
            uVar29 = 0;
            iVar11 = 0;
          }
LAB_0010b634:
          uVar21 = piVar43[3];
          uVar24 = (ulong)uVar21;
          if ((uVar21 & 0xf00) != 0) {
            uVar42 = ((ulong)(uVar21 >> 4) & 0xf) + (uVar24 & 0xf);
            puVar34 = (uint *)(piVar43 + uVar42 * 2 + 4);
            do {
              if (((int)*puVar34 < 0) && ((*puVar34 & 0xfff0) != 0)) {
                mutex_lock(&g_smcinvoke_lock);
                release_tzhandle_locked(*puVar34);
                mutex_unlock(&g_smcinvoke_lock);
                uVar24 = (ulong)(uint)piVar43[3];
              }
              uVar21 = (uint)uVar24;
              uVar42 = uVar42 + 1;
              puVar34 = puVar34 + 2;
            } while (uVar42 < (uVar21 >> 4 & 0xf) + (uVar21 & 0xf) + (uVar21 >> 8 & 0xf));
          }
          if (mem_obj_async_support == '\x01') {
            iVar12 = ((uVar28 >> 4 & 0xf) + (uVar28 & 0xf) +
                     (uVar28 >> 8 & 0xf) + (uVar28 >> 0xc & 0xf)) * 8 + 0x10;
            if (uVar29 != 0) {
              iVar12 = uVar29 + local_184;
            }
            uVar24 = (ulong)((-iVar12 & 7U) + iVar12);
            lVar38 = g_max_cb_buf_size - uVar24;
            if (g_max_cb_buf_size < uVar24) {
              _printk(&DAT_00117c2a,"marshal_out_tzcb_req");
            }
            else {
              mutex_lock(&g_smcinvoke_lock);
              add_mem_obj_info_to_async_side_channel_locked((long)piVar43 + uVar24,lVar38,&local_e8)
              ;
              ppppplVar9 = local_e8;
              while ((long ******)ppppplVar9 != &local_e8) {
                ppppplVar40 = (long *****)*ppppplVar9;
                ppppplVar9[-1] = (long ****)0x0;
                uVar24 = __list_del_entry_valid(ppppplVar9);
                if ((uVar24 & 1) != 0) {
                  pppplVar3 = *ppppplVar9;
                  pppplVar4 = ppppplVar9[1];
                  pppplVar3[1] = (long ***)pppplVar4;
                  *pppplVar4 = (long ***)pppplVar3;
                }
                *ppppplVar9 = (long ****)0xdead000000000100;
                ppppplVar9[1] = (long ****)0xdead000000000122;
                kfree(ppppplVar9 + -1);
                ppppplVar9 = ppppplVar40;
              }
              mutex_unlock(&g_smcinvoke_lock);
            }
          }
          if (iVar11 == 0) {
            *(undefined4 *)((long)plVar30 + -0x1c) = 3;
            mutex_lock(&g_smcinvoke_lock);
            Hint_Prefetch(puVar41,2,0,1);
            do {
              uVar28 = *puVar41;
              cVar5 = '\x01';
              bVar6 = (bool)ExclusiveMonitorPass(puVar41,0x10);
              if (bVar6) {
                *puVar41 = uVar28 - 1;
                cVar5 = ExclusiveMonitorsStatus();
              }
            } while (cVar5 != '\0');
            if (uVar28 == 1) {
              DataMemoryBarrier(2,1);
              lVar38 = plVar30[-3];
              if (*(short *)(lVar38 + 8) == -1) {
                release_tzhandle_locked(*(undefined4 *)(lVar38 + 4));
                lVar38 = plVar30[-3];
              }
              kfree(lVar38);
              plVar27 = (long *)plVar30[1];
              if (plVar27 != (long *)0x0) {
                lVar38 = *plVar30;
                *plVar27 = lVar38;
                if (lVar38 != 0) {
                  *(long **)(lVar38 + 8) = plVar27;
                }
                *plVar30 = 0;
                plVar30[1] = 0;
              }
              kfree(plVar36);
            }
            else if ((int)uVar28 < 1) {
              refcount_warn_saturate(puVar41,3);
            }
            mutex_unlock(&g_smcinvoke_lock);
            __wake_up(plVar25 + -0x24,3,1,0);
            goto LAB_0010a3e4;
          }
          mutex_lock(&g_smcinvoke_lock);
          release_tzhandle_locked(local_d8 & 0xffffffff);
          release_tzhandle_locked(local_d8._4_4_);
          release_tzhandle_locked(local_d0 & 0xffffffff);
          release_tzhandle_locked(local_d0._4_4_);
          release_tzhandle_locked(local_c8 & 0xffffffff);
          release_tzhandle_locked(local_c8._4_4_);
          release_tzhandle_locked(local_c0 & 0xffffffff);
          release_tzhandle_locked(local_c0._4_4_);
          release_tzhandle_locked(local_b8 & 0xffffffff);
          release_tzhandle_locked(local_b8._4_4_);
          release_tzhandle_locked(local_b0 & 0xffffffff);
          release_tzhandle_locked(local_b0._4_4_);
          release_tzhandle_locked(local_a8 & 0xffffffff);
          release_tzhandle_locked(local_a8._4_4_);
          release_tzhandle_locked(local_a0 & 0xffffffff);
          mutex_unlock(&g_smcinvoke_lock);
          if (*(int *)plVar30[-3] == 0) {
            *(int *)plVar30[-3] = -0x60;
          }
          *(undefined4 *)((long)plVar30 + -0x1c) = 3;
          mutex_lock(&g_smcinvoke_lock);
          Hint_Prefetch(puVar41,2,0,1);
          do {
            uVar28 = *puVar41;
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(puVar41,0x10);
            if (bVar6) {
              *puVar41 = uVar28 - 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          if (uVar28 == 1) {
            DataMemoryBarrier(2,1);
            lVar38 = plVar30[-3];
            if (*(short *)(lVar38 + 8) == -1) {
              release_tzhandle_locked(*(undefined4 *)(lVar38 + 4));
              lVar38 = plVar30[-3];
            }
            kfree(lVar38);
            plVar27 = (long *)plVar30[1];
            if (plVar27 != (long *)0x0) {
              lVar38 = *plVar30;
              *plVar27 = lVar38;
              if (lVar38 != 0) {
                *(long **)(lVar38 + 8) = plVar27;
              }
              *plVar30 = 0;
              plVar30[1] = 0;
            }
            kfree(plVar36);
          }
          else if ((int)uVar28 < 1) {
            refcount_warn_saturate(puVar41,3);
          }
          mutex_unlock(&g_smcinvoke_lock);
          __wake_up(plVar25 + -0x24,3,1,0);
          if ((local_130 & 0xf00000000000) == 0) goto LAB_0010a3e4;
          goto LAB_0010bf70;
        }
LAB_0010a2e0:
        _printk(&DAT_00116403,"process_accept_req");
        mutex_unlock(&g_smcinvoke_lock);
        goto LAB_0010a300;
      }
    }
    else {
      sVar14 = 0x38;
    }
    memset((void *)((long)&local_100 - sVar14),0,sVar14);
    puVar17 = &DAT_0011842b;
    pcVar18 = "process_accept_req";
LAB_0010b9c4:
    _printk(puVar17,pcVar18);
    lVar38 = -0xe;
  }
code_r0x0010c024:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar38;
LAB_0010a660:
  mutex_unlock(&g_smcinvoke_lock);
  if (plVar25[-0x20] == 0) goto LAB_0010a3f8;
  goto LAB_0010a558;
LAB_0010afa4:
  lVar38 = 0xffffffea;
LAB_0010afc8:
  _printk(&DAT_00117bee,"process_accept_req");
  **(undefined4 **)(puVar41 + 2) = 0xffffffa0;
  puVar41[1] = 3;
  mutex_lock(&g_smcinvoke_lock);
  puVar34 = puVar41 + 0xc;
  Hint_Prefetch(puVar34,2,0,1);
  do {
    uVar28 = *puVar34;
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(puVar34,0x10);
    if (bVar6) {
      *puVar34 = uVar28 - 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  if (uVar28 == 1) {
    DataMemoryBarrier(2,1);
    lVar16 = *(long *)(puVar41 + 2);
    if (*(short *)(lVar16 + 8) == -1) {
      release_tzhandle_locked(*(undefined4 *)(lVar16 + 4));
      lVar16 = *(long *)(puVar41 + 2);
    }
    kfree(lVar16);
    plVar30 = *(long **)(puVar41 + 10);
    if (plVar30 != (long *)0x0) {
      puVar34 = puVar41 + 8;
      lVar16 = *(long *)puVar34;
      *plVar30 = lVar16;
      if (lVar16 != 0) {
        *(long **)(lVar16 + 8) = plVar30;
      }
      puVar34[0] = 0;
      puVar34[1] = 0;
      puVar41[10] = 0;
      puVar41[0xb] = 0;
    }
    kfree(puVar41);
  }
  else if ((int)uVar28 < 1) {
    refcount_warn_saturate(puVar34,3);
  }
LAB_0010bf50:
  iVar11 = (int)lVar38;
  mutex_unlock(&g_smcinvoke_lock);
  __wake_up(plVar25 + -0x24,1,1,0);
LAB_0010bf70:
  mutex_lock(&g_smcinvoke_lock);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar28 = *puVar1;
    cVar5 = '\x01';
    bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar6) {
      *puVar1 = uVar28 - 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  if (uVar28 == 1) {
    DataMemoryBarrier(2,1);
    if (puVar13 != (ushort *)0x0) {
      plVar30 = (long *)plVar25[1];
      if (plVar30 != (long *)0x0) {
        lVar38 = *plVar25;
        *plVar30 = lVar38;
        if (lVar38 != 0) {
          *(long **)(lVar38 + 8) = plVar30;
        }
        *plVar25 = 0;
        plVar25[1] = 0;
      }
      kfree(puVar13);
    }
  }
  else if ((int)uVar28 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
  mutex_unlock(&g_smcinvoke_lock);
  if ((iVar11 != -0x200) && (iVar11 != 0)) {
    _printk(&DAT_00117410,"process_accept_req",iVar11);
  }
  lVar38 = (long)iVar11;
  goto code_r0x0010c024;
}



//------------------------------------------------------------
// smcinvoke_open @ 0010c378 size=88
// signature: undefined smcinvoke_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 smcinvoke_open(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,8);
  if (puVar1 == (undefined8 *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = 0;
    *(undefined8 **)(param_2 + 0xd8) = puVar1;
    *puVar1 = 0x100000000;
  }
  return uVar2;
}



//------------------------------------------------------------
// smcinvoke_release @ 0010c3d4 size=84
// signature: undefined smcinvoke_release(void)
// callers: []
//------------------------------------------------------------

undefined8 smcinvoke_release(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = sp_el0;
  if (*(long *)(param_2 + 0xd8) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = smcinvoke_release_filp(param_2);
  }
  return uVar1;
}



//------------------------------------------------------------
// get_tzhandle_from_uhandle @ 0010c4e0 size=872
// signature: undefined get_tzhandle_from_uhandle(void)
// callers: [process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int get_tzhandle_from_uhandle
              (int param_1,undefined4 param_2,long *param_3,uint *param_4,long *param_5)

{
  ushort *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ushort *puVar5;
  undefined2 *puVar6;
  undefined8 *puVar7;
  undefined *puVar8;
  char *pcVar9;
  uint uVar10;
  int *piVar11;
  ushort uVar12;
  undefined **ppuVar13;
  undefined8 *puVar14;
  undefined2 uVar15;
  
  if (param_1 == -1) {
    *param_4 = 0;
    return 0;
  }
  if (param_1 < -1) {
    lVar3 = fget(param_2);
    if ((lVar3 != 0) && (*(undefined ***)(lVar3 + 0x28) == &g_smcinvoke_fops)) {
      piVar11 = *(int **)(lVar3 + 0xd8);
      if ((piVar11 == (int *)0x0) || (*piVar11 != 1)) goto LAB_0010c61c;
      uVar12 = *(ushort *)(piVar11 + 1);
      fput();
      if (0xf < uVar12) {
        mutex_lock(&g_smcinvoke_lock);
        iVar2 = get_pending_cbobj_locked(uVar12,-2 - param_1);
        mutex_unlock(&g_smcinvoke_lock);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar10 = (uint)uVar12 | (-2 - param_1) * 0x10000 | 0x80000000;
        goto LAB_0010c7e8;
      }
    }
    return -9;
  }
  uVar4 = dma_buf_get(param_1);
  if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
    lVar3 = fget(param_1);
    if (lVar3 == 0) {
      return -9;
    }
    if ((*(undefined ***)(lVar3 + 0x28) == &g_smcinvoke_fops) &&
       (piVar11 = *(int **)(lVar3 + 0xd8), *piVar11 == 0)) {
      *param_3 = lVar3;
      uVar10 = piVar11[1];
LAB_0010c7e8:
      *param_4 = uVar10;
      return 0;
    }
LAB_0010c61c:
    fput();
    return -9;
  }
  lVar3 = fget(param_2);
  if ((lVar3 == 0) || (*(undefined ***)(lVar3 + 0x28) != &g_smcinvoke_fops)) {
    uVar15 = 0;
  }
  else {
    piVar11 = *(int **)(lVar3 + 0xd8);
    if ((piVar11 == (int *)0x0) || (*piVar11 != 1)) {
      uVar15 = 0;
    }
    else {
      uVar15 = (undefined2)piVar11[1];
    }
    fput();
  }
  puVar5 = (ushort *)kmalloc_trace(_fget,0xdc0,0x60);
  if (puVar5 == (ushort *)0x0) {
LAB_0010c7cc:
    dma_buf_put(uVar4);
    return -0xc;
  }
  puVar6 = (undefined2 *)kmalloc_trace(__printk,0xdc0,0x170);
  if (puVar6 == (undefined2 *)0x0) {
    kfree(puVar5);
    goto LAB_0010c7cc;
  }
  puVar5[0x10] = 1;
  puVar5[0x11] = 0;
  *(ulong *)(puVar5 + 4) = uVar4;
  mutex_lock(&g_smcinvoke_lock);
  puVar8 = PTR_g_mem_objs_00114d90;
  uVar12 = 0;
  if (g_last_mem_rgn_id != 0x7fff) {
    uVar12 = g_last_mem_rgn_id;
  }
  while (uVar12 = uVar12 + 1, ppuVar13 = (undefined **)g_mem_objs,
        (undefined **)g_mem_objs != &g_mem_objs) {
    while (*(ushort *)(ppuVar13 + -7) != uVar12) {
      ppuVar13 = (undefined **)*ppuVar13;
      if (ppuVar13 == &g_mem_objs) goto LAB_0010c6f8;
    }
    if (ppuVar13 == (undefined **)0x38) break;
  }
LAB_0010c6f8:
  g_last_mem_rgn_id = uVar12;
  *puVar6 = uVar15;
  puVar1 = puVar5 + 0x1c;
  *puVar5 = uVar12;
  *(undefined2 **)(puVar5 + 0x28) = puVar6;
  *(int *)(puVar5 + 0x2c) = param_1;
  uVar4 = __list_add_valid(puVar1,puVar8,&g_mem_objs);
  if ((uVar4 & 1) != 0) {
    PTR_g_mem_objs_00114d90 = (undefined *)puVar1;
    *(undefined ***)(puVar5 + 0x1c) = &g_mem_objs;
    *(undefined **)(puVar5 + 0x20) = puVar8;
    *(ushort **)puVar8 = puVar1;
  }
  mutex_unlock(&g_smcinvoke_lock);
  *param_4 = (uint)*puVar5 << 0x10 | 0x80000001;
  if (param_5 == (long *)0x0) {
    return 0;
  }
  if (mem_obj_async_support == '\0') {
    return 0;
  }
  mutex_lock(&g_smcinvoke_lock);
  iVar2 = smcinvoke_map_mem_region_locked(puVar5);
  if (iVar2 == 0) {
    puVar7 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x18);
    if (puVar7 != (undefined8 *)0x0) {
      lVar3 = *param_5;
      puVar14 = puVar7 + 1;
      *puVar7 = puVar5;
      uVar4 = __list_add_valid(puVar14,param_5,lVar3);
      if ((uVar4 & 1) != 0) {
        *(undefined8 **)(lVar3 + 8) = puVar14;
        puVar7[1] = lVar3;
        puVar7[2] = param_5;
        *param_5 = (long)puVar14;
      }
      goto LAB_0010c818;
    }
    puVar8 = &DAT_00116fbc;
    pcVar9 = "queue_mem_obj_pending_async_locked";
  }
  else {
    puVar8 = &DAT_00118062;
    pcVar9 = "get_tzhandle_from_uhandle";
  }
  _printk(puVar8,pcVar9);
LAB_0010c818:
  mutex_unlock(&g_smcinvoke_lock);
  return 0;
}



//------------------------------------------------------------
// add_mem_obj_info_to_async_side_channel_locked @ 0010c848 size=340
// signature: undefined add_mem_obj_info_to_async_side_channel_locked(void)
// callers: [process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

void add_mem_obj_info_to_async_side_channel_locked(undefined8 *param_1,ulong param_2,long *param_3)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  
  if ((long *)*param_3 != param_3) {
    if (param_2 < 0x30) {
      _printk(&DAT_00116484,"add_mem_obj_info_to_async_side_channel_locked");
    }
    else {
      *(undefined4 *)(param_1 + 1) = 0;
      *param_1 = 0x300010002;
      plVar3 = (long *)*param_3;
      if (plVar3 == param_3) {
        lVar2 = 0;
      }
      else {
        lVar2 = 0;
        uVar4 = 0x10;
        do {
          if ((ushort *)plVar3[-1] == (ushort *)0x0) {
            _printk(&DAT_00117a5f,"add_mem_obj_info_to_async_side_channel_locked");
          }
          else {
            uVar4 = uVar4 + 0x20;
            if (param_2 < uVar4) {
              _printk(&DAT_00116b89,"add_mem_obj_info_to_async_side_channel_locked");
              break;
            }
            *(uint *)(param_1 + lVar2 * 4 + 2) = (uint)*(ushort *)plVar3[-1] << 0x10 | 0x80000001;
            *(uint *)((long)param_1 + lVar2 * 0x20 + 0x14) =
                 (uint)*(ushort *)(plVar3[-1] + 2) << 0x10 | 0x80000002;
            param_1[lVar2 * 4 + 3] = *(undefined8 *)(plVar3[-1] + 0x28);
            uVar1 = *(undefined8 *)(plVar3[-1] + 0x30);
            *(undefined4 *)(param_1 + lVar2 * 4 + 5) = 6;
            param_1[lVar2 * 4 + 4] = uVar1;
            lVar2 = lVar2 + 1;
          }
          plVar3 = (long *)*plVar3;
        } while (plVar3 != param_3);
      }
      *(int *)(param_1 + 1) = (int)lVar2;
    }
  }
  return;
}



//------------------------------------------------------------
// release_tzhandle_locked @ 0010c99c size=972
// signature: undefined release_tzhandle_locked(void)
// callers: [process_tzcb_req, process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

undefined8 release_tzhandle_locked(uint param_1)

{
  uint *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  ulong uVar5;
  undefined **ppuVar6;
  ushort *puVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  undefined **ppuVar12;
  ushort *puVar13;
  undefined **ppuVar14;
  ushort *puVar15;
  undefined8 uVar16;
  
  if (((int)param_1 < 0) && (0xfffffffd < (param_1 & 0xffff) - 3)) {
    if ((undefined **)g_mem_objs != &g_mem_objs) {
      uVar4 = param_1 >> 0x10 & 0x7fff;
      ppuVar14 = (undefined **)g_mem_objs;
      do {
        ppuVar12 = ppuVar14 + -7;
        if ((param_1 & 0x8000ffff) == 0x80000001) {
          if (*(ushort *)ppuVar12 == uVar4) {
            if (ppuVar12 != (undefined **)0x0) {
              ppuVar6 = ppuVar14 + -3;
              Hint_Prefetch(ppuVar6,2,0,1);
              do {
                iVar8 = *(int *)ppuVar6;
                cVar2 = '\x01';
                bVar3 = (bool)ExclusiveMonitorPass(ppuVar6,0x10);
                if (bVar3) {
                  *(int *)ppuVar6 = iVar8 + -1;
                  cVar2 = ExclusiveMonitorsStatus();
                }
              } while (cVar2 != '\0');
              if (iVar8 != 1) {
joined_r0x0010cd5c:
                if (iVar8 < 1) {
                  refcount_warn_saturate(ppuVar6,3);
                  return 0;
                }
                return 0;
              }
              DataMemoryBarrier(2,1);
              iVar8 = *(int *)((long)ppuVar14 + -0x14);
joined_r0x0010cbfc:
              if (iVar8 == 0) {
                free_mem_obj_locked(ppuVar12);
                return 0;
              }
              return 0;
            }
            break;
          }
        }
        else if (*(ushort *)((long)ppuVar14 + -0x36) == uVar4) {
          if (ppuVar12 != (undefined **)0x0) {
            ppuVar6 = (undefined **)((long)ppuVar14 + -0x14);
            Hint_Prefetch(ppuVar6,2,0,1);
            do {
              iVar8 = *(int *)ppuVar6;
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(ppuVar6,0x10);
              if (bVar3) {
                *(int *)ppuVar6 = iVar8 + -1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            if (iVar8 != 1) goto joined_r0x0010cd5c;
            DataMemoryBarrier(2,1);
            ppuVar14[-2] = (undefined *)0x0;
            ppuVar14[-1] = (undefined *)0x0;
            if (ppuVar14[-4] != (undefined *)0x0) {
              dma_buf_unmap_attachment(ppuVar14[-5],ppuVar14[-4],0);
            }
            if (ppuVar14[-5] != (undefined *)0x0) {
              dma_buf_detach(ppuVar14[-6]);
            }
            iVar8 = *(int *)(ppuVar14 + -3);
            goto joined_r0x0010cbfc;
          }
          break;
        }
        ppuVar14 = (undefined **)*ppuVar14;
      } while (ppuVar14 != &g_mem_objs);
    }
    _printk(&DAT_00117f27,"release_mem_obj_locked");
    uVar16 = 0xffffffa4;
  }
  else {
    uVar16 = 1;
    if (((int)param_1 < 0) && ((param_1 & 0xfff0) != 0)) {
      puVar13 = (ushort *)
                (*(long *)(g_cb_servers + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x18) * 8) +
                -0x148);
      if (*(long *)(g_cb_servers + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x18) * 8) != 0 &&
          puVar13 != (ushort *)0x0) {
        do {
          if ((uint)*puVar13 == (param_1 & 0xffff)) {
            puVar1 = (uint *)(puVar13 + 4);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              uVar4 = *puVar1;
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = uVar4 + 1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            if (uVar4 == 0) {
              uVar16 = 2;
LAB_0010cc58:
              refcount_warn_saturate(puVar1,uVar16);
            }
            else if ((int)(uVar4 + 1 | uVar4) < 0) {
              uVar16 = 1;
              goto LAB_0010cc58;
            }
            puVar15 = puVar13 + 0xac;
            do {
              puVar15 = *(ushort **)puVar15;
              if (puVar15 == puVar13 + 0xac) {
                uVar16 = 0xffffffea;
                goto LAB_0010cdb8;
              }
            } while ((uint)puVar15[-8] != (param_1 >> 0x10 & 0x7fff));
            puVar7 = puVar15 + -6;
            Hint_Prefetch(puVar7,2,0,1);
            do {
              iVar8 = *(int *)puVar7;
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar7,0x10);
              if (bVar3) {
                *(int *)puVar7 = iVar8 + -1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            if (iVar8 == 1) {
              DataMemoryBarrier(2,1);
              uVar5 = __list_del_entry_valid(puVar15);
              if ((uVar5 & 1) != 0) {
                lVar11 = *(long *)puVar15;
                plVar9 = *(long **)(puVar15 + 4);
                *(long **)(lVar11 + 8) = plVar9;
                *plVar9 = lVar11;
              }
              lVar11 = *(long *)(puVar15 + -4);
              puVar15[0] = 0x100;
              puVar15[1] = 0;
              puVar15[2] = 0;
              puVar15[3] = 0xdead;
              puVar15[4] = 0x122;
              puVar15[5] = 0;
              puVar15[6] = 0;
              puVar15[7] = 0xdead;
              kfree(puVar15 + -8);
              uVar16 = 0;
              if (lVar11 == 0) goto LAB_0010cdb8;
              puVar7 = (ushort *)(lVar11 + 8);
              Hint_Prefetch(puVar7,2,0,1);
              do {
                iVar8 = *(int *)puVar7;
                cVar2 = '\x01';
                bVar3 = (bool)ExclusiveMonitorPass(puVar7,0x10);
                if (bVar3) {
                  *(int *)puVar7 = iVar8 + -1;
                  cVar2 = ExclusiveMonitorsStatus();
                }
              } while (cVar2 != '\0');
              if (iVar8 != 1) goto LAB_0010cdac;
              DataMemoryBarrier(2,1);
              plVar9 = *(long **)(lVar11 + 0x150);
              if (plVar9 != (long *)0x0) {
                lVar10 = *(long *)(lVar11 + 0x148);
                *plVar9 = lVar10;
                if (lVar10 != 0) {
                  *(long **)(lVar10 + 8) = plVar9;
                }
                *(long *)(lVar11 + 0x148) = 0;
                *(undefined8 *)(lVar11 + 0x150) = 0;
              }
              kfree(lVar11);
            }
            else {
LAB_0010cdac:
              if (iVar8 < 1) {
                refcount_warn_saturate(puVar7,3);
              }
            }
            uVar16 = 0;
LAB_0010cdb8:
            Hint_Prefetch(puVar1,2,0,1);
            do {
              uVar4 = *puVar1;
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = uVar4 - 1;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            if (uVar4 != 1) {
              if ((int)uVar4 < 1) {
                refcount_warn_saturate(puVar1,3);
                return uVar16;
              }
              return uVar16;
            }
            DataMemoryBarrier(2,1);
            if (puVar13 == (ushort *)0x0) {
              return uVar16;
            }
            plVar9 = *(long **)(puVar13 + 0xa8);
            if (plVar9 != (long *)0x0) {
              puVar15 = puVar13 + 0xa4;
              lVar11 = *(long *)puVar15;
              *plVar9 = lVar11;
              if (lVar11 != 0) {
                *(long **)(lVar11 + 8) = plVar9;
              }
              puVar15[0] = 0;
              puVar15[1] = 0;
              puVar15[2] = 0;
              puVar15[3] = 0;
              puVar13[0xa8] = 0;
              puVar13[0xa9] = 0;
              puVar13[0xaa] = 0;
              puVar13[0xab] = 0;
            }
            kfree(puVar13);
            return uVar16;
          }
        } while ((*(long *)(puVar13 + 0xa4) != 0) &&
                (puVar13 = (ushort *)(*(long *)(puVar13 + 0xa4) + -0x148), puVar13 != (ushort *)0x0)
                );
      }
      _printk(&DAT_0011816b,"put_pending_cbobj_locked","put_pending_cbobj_locked");
      uVar16 = 0xffffffea;
    }
  }
  return uVar16;
}



//------------------------------------------------------------
// free_mem_obj_locked @ 0010ce60 size=360
// signature: undefined free_mem_obj_locked(void)
// callers: [release_tzhandle_locked, smcinvoke_map_mem_region_locked, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void free_mem_obj_locked(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined *puVar3;
  int iVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  long lVar8;
  
  uVar7 = *(undefined8 *)(param_1 + 8);
  lVar8 = *(long *)(param_1 + 0x48);
  uVar5 = __list_del_entry_valid(param_1 + 0x38);
  if ((uVar5 & 1) != 0) {
    lVar1 = *(long *)(param_1 + 0x38);
    plVar2 = *(long **)(param_1 + 0x40);
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *(undefined8 *)(param_1 + 0x38) = 0xdead000000000100;
  *(undefined8 *)(param_1 + 0x40) = 0xdead000000000122;
  kfree(*(undefined8 *)(param_1 + 0x50));
  kfree(param_1);
  mutex_unlock(&g_smcinvoke_lock);
  if ((lVar8 == 0) || (iVar4 = qtee_shmbridge_deregister(lVar8), iVar4 == 0)) {
    dma_buf_put(uVar7);
  }
  else {
    _printk(&DAT_00117214,"free_mem_obj_locked",iVar4,uVar7);
    if (iVar4 == -0x10) {
      _printk(&DAT_001175e4,"free_mem_obj_locked",uVar7);
      puVar6 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x20);
      if (puVar6 != (undefined8 *)0x0) {
        puVar6[2] = lVar8;
        puVar6[3] = uVar7;
        mutex_lock(&bridge_postprocess_lock);
        puVar3 = PTR_g_bridge_postprocess_00114da0;
        uVar5 = __list_add_valid(puVar6,PTR_g_bridge_postprocess_00114da0,&g_bridge_postprocess);
        if ((uVar5 & 1) != 0) {
          PTR_g_bridge_postprocess_00114da0 = (undefined *)puVar6;
          *puVar6 = &g_bridge_postprocess;
          puVar6[1] = puVar3;
          *(undefined8 **)puVar3 = puVar6;
        }
        mutex_unlock(&bridge_postprocess_lock);
        DAT_00118504 = 1;
        __wake_up(&DAT_00118508,1,1,0);
      }
    }
  }
  mutex_lock(&g_smcinvoke_lock);
  return;
}



//------------------------------------------------------------
// get_pending_cbobj_locked @ 0010cfc8 size=548
// signature: undefined get_pending_cbobj_locked(void)
// callers: [get_uhandle_from_tzhandle, marshal_out_invoke_req, get_tzhandle_from_uhandle]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 get_pending_cbobj_locked(uint param_1,short param_2)

{
  uint *puVar1;
  ushort *puVar2;
  short *psVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  uint *puVar7;
  short *psVar8;
  ulong uVar9;
  undefined8 uVar10;
  ushort *puVar11;
  long *plVar12;
  long lVar13;
  ushort *puVar14;
  
  puVar14 = (ushort *)
            (*(long *)(g_cb_servers + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x18) * 8) + -0x148
            );
  if (*(long *)(g_cb_servers + (ulong)((param_1 & 0xffff) * 0x61c88647 >> 0x18) * 8) != 0 &&
      puVar14 != (ushort *)0x0) {
    do {
      if ((uint)*puVar14 == (param_1 & 0xffff)) {
        puVar1 = (uint *)(puVar14 + 4);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          uVar4 = *puVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar6) {
            *puVar1 = uVar4 + 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (uVar4 == 0) {
          uVar10 = 2;
LAB_0010d190:
          refcount_warn_saturate(puVar1,uVar10);
        }
        else if ((int)(uVar4 + 1 | uVar4) < 0) {
          uVar10 = 1;
          goto LAB_0010d190;
        }
        puVar2 = puVar14 + 0xac;
        puVar11 = puVar2;
        do {
          puVar11 = *(ushort **)puVar11;
          if (puVar11 == puVar2) {
            psVar8 = (short *)kmalloc_trace(_kfree,0xdc0,0x20);
            if (psVar8 != (short *)0x0) {
              *psVar8 = param_2;
              psVar3 = psVar8 + 8;
              psVar8[2] = 1;
              psVar8[3] = 0;
              *(ushort **)(psVar8 + 4) = puVar14;
              plVar12 = *(long **)(puVar14 + 0xb0);
              uVar9 = __list_add_valid(psVar3,plVar12,puVar2);
              if ((uVar9 & 1) == 0) {
                return 0;
              }
              *(short **)(puVar14 + 0xb0) = psVar3;
              *(ushort **)(psVar8 + 8) = puVar2;
              *(long **)(psVar8 + 0xc) = plVar12;
              *plVar12 = (long)psVar3;
              return 0;
            }
            uVar10 = 0xffffff9f;
            goto LAB_0010d11c;
          }
        } while ((uint)puVar11[-8] != (int)param_2);
        puVar7 = (uint *)(puVar11 + -6);
        Hint_Prefetch(puVar7,2,0,1);
        do {
          uVar4 = *puVar7;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar7,0x10);
          if (bVar6) {
            *puVar7 = uVar4 + 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (uVar4 == 0) {
          uVar10 = 2;
LAB_0010d20c:
          refcount_warn_saturate(puVar7,uVar10);
        }
        else if ((int)(uVar4 + 1 | uVar4) < 0) {
          uVar10 = 1;
          goto LAB_0010d20c;
        }
        uVar10 = 0;
LAB_0010d11c:
        Hint_Prefetch(puVar1,2,0,1);
        do {
          uVar4 = *puVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar6) {
            *puVar1 = uVar4 - 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (uVar4 != 1) {
          if ((int)uVar4 < 1) {
            refcount_warn_saturate(puVar1,3);
            return uVar10;
          }
          return uVar10;
        }
        DataMemoryBarrier(2,1);
        if (puVar14 == (ushort *)0x0) {
          return uVar10;
        }
        plVar12 = *(long **)(puVar14 + 0xa8);
        if (plVar12 != (long *)0x0) {
          puVar2 = puVar14 + 0xa4;
          lVar13 = *(long *)puVar2;
          *plVar12 = lVar13;
          if (lVar13 != 0) {
            *(long **)(lVar13 + 8) = plVar12;
          }
          puVar2[0] = 0;
          puVar2[1] = 0;
          puVar2[2] = 0;
          puVar2[3] = 0;
          puVar14[0xa8] = 0;
          puVar14[0xa9] = 0;
          puVar14[0xaa] = 0;
          puVar14[0xab] = 0;
        }
        kfree(puVar14);
        return uVar10;
      }
    } while ((*(long *)(puVar14 + 0xa4) != 0) &&
            (puVar14 = (ushort *)(*(long *)(puVar14 + 0xa4) + -0x148), puVar14 != (ushort *)0x0));
  }
  _printk(&DAT_0011816b,"get_pending_cbobj_locked","get_pending_cbobj_locked");
  return 0xffffffa4;
}



//------------------------------------------------------------
// smcinvoke_map_mem_region_locked @ 0010d214 size=1084
// signature: undefined smcinvoke_map_mem_region_locked(void)
// callers: [process_tzcb_req, get_tzhandle_from_uhandle]
//------------------------------------------------------------

undefined8 smcinvoke_map_mem_region_locked(short *param_1)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  long *plVar6;
  undefined *puVar7;
  undefined8 uVar8;
  long lVar9;
  short sVar10;
  undefined **ppuVar11;
  uint *puVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  long *plVar15;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined8 local_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  if (param_1 == (short *)0x0) {
    puVar7 = &DAT_001176c9;
LAB_0010d5e0:
    _printk(puVar7,"smcinvoke_map_mem_region_locked");
    uVar13 = 0xffffffa4;
    goto LAB_0010d6cc;
  }
  plVar15 = (long *)(param_1 + 0x14);
  if (*plVar15 != 0) {
    uVar13 = 0;
    goto LAB_0010d6cc;
  }
  puVar12 = (uint *)(param_1 + 0x12);
  *puVar12 = 1;
  uVar5 = dma_buf_attach(*(undefined8 *)(param_1 + 4),smcinvoke_pdev + 0x10);
  if (uVar5 < 0xfffffffffffff001) {
    *(ulong *)(param_1 + 8) = uVar5;
    plVar6 = (long *)dma_buf_map_attachment(uVar5,0);
    if (plVar6 < (long *)0xfffffffffffff001) {
      *(long **)(param_1 + 0xc) = plVar6;
      if ((int)plVar6[1] == 1) {
        lVar9 = *(long *)(*plVar6 + 0x10);
        *(long *)(param_1 + 0x14) = lVar9;
        *(ulong *)(param_1 + 0x18) = (ulong)*(uint *)(*plVar6 + 0xc);
        if (lVar9 == 0) {
          puVar7 = &DAT_00117e8e;
        }
        else {
          Hint_Prefetch(puVar12,2,0,1);
          do {
            uVar1 = *puVar12;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar12,0x10);
            if (bVar3) {
              *puVar12 = uVar1 + 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (uVar1 == 0) {
            uVar13 = 2;
LAB_0010d50c:
            refcount_warn_saturate(puVar12,uVar13);
          }
          else if ((int)(uVar1 + 1 | uVar1) < 0) {
            uVar13 = 1;
            goto LAB_0010d50c;
          }
          mutex_unlock(&g_smcinvoke_lock);
          uVar13 = *(undefined8 *)(param_1 + 0x14);
          uVar8 = *(undefined8 *)(param_1 + 0x18);
          local_68 = (undefined4 *)0x0;
          local_60 = 0;
          uVar14 = *(undefined8 *)(param_1 + 4);
          local_6c = 0;
          uVar5 = qtee_shmbridge_is_enabled();
          iVar4 = 0;
          if ((uVar5 & 1) != 0) {
            iVar4 = mem_buf_dma_buf_copy_vmperm(uVar14,&local_60,&local_68,&local_6c);
            if (iVar4 == 0) {
              uVar5 = mem_buf_dma_buf_exclusive_owner(uVar14);
              if ((uVar5 & 1) != 0) {
                *local_68 = 6;
              }
              iVar4 = qtee_shmbridge_register
                                (uVar13,uVar8,local_60,local_68,local_6c,6,param_1 + 0x24);
              if (iVar4 != 0) {
                _printk(&DAT_00116c33,"smcinvoke_create_bridge",*param_1,iVar4);
              }
              kfree(local_68);
              kfree(local_60);
            }
            else {
              _printk(&DAT_00117f82,"smcinvoke_create_bridge",iVar4);
              iVar4 = 1;
            }
          }
          mutex_lock(&g_smcinvoke_lock);
          Hint_Prefetch(puVar12,2,0,1);
          do {
            uVar1 = *puVar12;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar12,0x10);
            if (bVar3) {
              *puVar12 = uVar1 - 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (uVar1 == 1) {
            DataMemoryBarrier(2,1);
            *plVar15 = 0;
            param_1[0x18] = 0;
            param_1[0x19] = 0;
            param_1[0x1a] = 0;
            param_1[0x1b] = 0;
            if (*(long *)(param_1 + 0xc) != 0) {
              dma_buf_unmap_attachment(*(undefined8 *)(param_1 + 8),*(long *)(param_1 + 0xc),0);
            }
            if (*(long *)(param_1 + 8) != 0) {
              dma_buf_detach(*(undefined8 *)(param_1 + 4));
            }
            if (*(int *)(param_1 + 0x10) == 0) {
              free_mem_obj_locked(param_1);
            }
          }
          else if ((int)uVar1 < 1) {
            refcount_warn_saturate(puVar12,3);
          }
          if (iVar4 == 0) {
            ppuVar11 = (undefined **)g_mem_objs;
            if ((undefined **)g_mem_objs != &g_mem_objs) {
              do {
                if (*(short *)(ppuVar11 + -7) == *param_1) {
                  if (ppuVar11 != (undefined **)0x38) {
                    sVar10 = 0;
                    if (g_last_mem_map_obj_id != 0x7fff) {
                      sVar10 = g_last_mem_map_obj_id;
                    }
                    goto LAB_0010d594;
                  }
                  break;
                }
                ppuVar11 = (undefined **)*ppuVar11;
              } while (ppuVar11 != &g_mem_objs);
            }
            puVar7 = &DAT_00117611;
            goto LAB_0010d5e0;
          }
          puVar7 = &DAT_0011793e;
        }
      }
      else {
        puVar7 = &DAT_0011819a;
      }
      uVar8 = 2;
      uVar13 = 2;
      goto LAB_0010d450;
    }
    _printk(&DAT_00117447,"smcinvoke_map_mem_region_locked");
    uVar13 = 0xffffff9f;
  }
  else {
    puVar7 = &DAT_00117f51;
    uVar8 = 0xffffff9f;
    uVar13 = 0xffffff9f;
LAB_0010d450:
    _printk(puVar7,"smcinvoke_map_mem_region_locked",uVar8);
  }
  Hint_Prefetch(puVar12,2,0,1);
  do {
    uVar1 = *puVar12;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar12,0x10);
    if (bVar3) {
      *puVar12 = uVar1 - 1;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  if (uVar1 == 1) {
    DataMemoryBarrier(2,1);
    *plVar15 = 0;
    param_1[0x18] = 0;
    param_1[0x19] = 0;
    param_1[0x1a] = 0;
    param_1[0x1b] = 0;
    if (*(long *)(param_1 + 0xc) != 0) {
      dma_buf_unmap_attachment(*(undefined8 *)(param_1 + 8),*(long *)(param_1 + 0xc),0);
    }
    if (*(long *)(param_1 + 8) != 0) {
      dma_buf_detach(*(undefined8 *)(param_1 + 4));
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      free_mem_obj_locked(param_1);
    }
  }
  else if ((int)uVar1 < 1) {
    refcount_warn_saturate(puVar12,3);
  }
LAB_0010d6cc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13;
LAB_0010d594:
  g_last_mem_map_obj_id = sVar10 + 1;
  ppuVar11 = (undefined **)g_mem_objs;
  if ((undefined **)g_mem_objs == &g_mem_objs) goto LAB_0010d5cc;
  while (*(short *)((long)ppuVar11 + -0x36) != g_last_mem_map_obj_id) {
    ppuVar11 = (undefined **)*ppuVar11;
    if (ppuVar11 == &g_mem_objs) goto LAB_0010d5cc;
  }
  sVar10 = g_last_mem_map_obj_id;
  if (ppuVar11 == (undefined **)0x38) goto LAB_0010d5cc;
  goto LAB_0010d594;
LAB_0010d5cc:
  uVar13 = 0;
  param_1[1] = g_last_mem_map_obj_id;
  goto LAB_0010d6cc;
}



//------------------------------------------------------------
// get_uhandle_from_tzhandle @ 0010d718 size=332
// signature: undefined get_uhandle_from_tzhandle(void)
// callers: [smcinvoke_ioctl]
//------------------------------------------------------------

undefined4
get_uhandle_from_tzhandle(uint param_1,uint param_2,int *param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  
  if (param_1 == 0) {
    *param_3 = -1;
    return 0;
  }
  if ((int)param_1 < 0) {
    uVar1 = param_1 & 0xffff;
    if (uVar1 < 0x10) {
      if (uVar1 == 1) {
        if ((param_4 & 1) != 0) {
          mutex_lock(&g_smcinvoke_lock);
        }
        if ((undefined **)g_mem_objs != &g_mem_objs) {
          ppuVar3 = (undefined **)g_mem_objs;
          do {
            if ((uint)*(ushort *)(ppuVar3 + -7) == (param_1 >> 0x10 & 0x7fff)) {
              if ((ppuVar3 != (undefined **)0x38) && (-1 < *(int *)(ppuVar3 + 4))) {
                uVar2 = 0;
                *param_3 = *(int *)(ppuVar3 + 4);
                goto LAB_0010d83c;
              }
              break;
            }
            ppuVar3 = (undefined **)*ppuVar3;
          } while (ppuVar3 != &g_mem_objs);
        }
        uVar2 = 0xffffffff;
LAB_0010d83c:
        if ((param_4 & 1) == 0) {
          return uVar2;
        }
        mutex_unlock(&g_smcinvoke_lock);
        return uVar2;
      }
    }
    else if (uVar1 == param_2) {
      uVar1 = param_1 >> 0x10 & 0x7fff;
      *param_3 = -2 - uVar1;
      if ((param_4 & 1) != 0) {
        mutex_lock(&g_smcinvoke_lock);
        uVar2 = get_pending_cbobj_locked(param_1,uVar1);
        mutex_unlock(&g_smcinvoke_lock);
        return uVar2;
      }
      uVar2 = get_pending_cbobj_locked(param_1,uVar1);
      goto LAB_0010d84c;
    }
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = get_fd_for_obj(param_5,param_1,param_3);
  }
LAB_0010d84c:
  return uVar2;
}



//------------------------------------------------------------
// prepare_send_scm_msg @ 0010d864 size=1432
// signature: undefined prepare_send_scm_msg(void)
// callers: [smcinvoke_release_tz_object, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int prepare_send_scm_msg
              (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4,
              undefined8 param_5,ulong param_6,long param_7,long param_8,undefined1 *param_9,
              undefined4 param_10,undefined8 param_11,undefined8 param_12,byte param_13)

{
  long lVar1;
  int *piVar2;
  ulong uVar3;
  uint *__s;
  long lVar4;
  undefined8 uVar5;
  bool bVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  uint uVar10;
  ulong uVar11;
  int *piVar12;
  ulong uVar13;
  ulong uVar14;
  int iVar15;
  uint uVar16;
  size_t __n;
  int iVar17;
  undefined4 local_104;
  long local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
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
  
  lVar4 = sp_el0;
  local_70 = *(long *)(lVar4 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_100 = 0;
  local_104 = 0;
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
  local_e8 = 0;
  *param_9 = 0;
  if ((((uint)param_6 | (uint)param_3) & 0xfff) != 0) {
    iVar7 = -0x16;
LAB_0010d8dc:
    lVar4 = sp_el0;
    if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar7;
  }
  iVar17 = 0;
  piVar2 = (int *)(param_7 + 8);
  lVar4 = (param_4 << 8) >> 8;
  uVar3 = lVar4 + 0x8000000000;
  uVar5 = sp_el0;
  iVar15 = invoke_cmd;
  do {
    iVar9 = iVar17;
    if (iVar17 < 0xc9) {
      iVar9 = 200;
    }
    do {
      if (iVar15 == 0x32000602) {
        iVar7 = qcom_scm_invoke_smc(param_2,param_3,param_5,param_6,piVar2,&local_100,&local_104);
      }
      else if (iVar15 == 0x32000601) {
        if (legacy_smc_call != '\0') {
          qtee_shmbridge_flush_shm_buf(param_12);
        }
        lVar1 = _memstart_addr + uVar3;
        if (uVar3 >> 0x26 != 0) {
          lVar1 = lVar4 - _kimage_voffset;
        }
        iVar7 = qcom_scm_invoke_callback_response(lVar1,param_6,piVar2,&local_100,&local_104);
        if (legacy_smc_call != '\0') goto LAB_0010da84;
      }
      else if (iVar15 == 0x32000600) {
        qtee_shmbridge_flush_shm_buf(param_11);
        qtee_shmbridge_flush_shm_buf(param_12);
        iVar7 = qcom_scm_invoke_smc_legacy
                          (param_2,param_3,param_5,param_6,piVar2,&local_100,&local_104);
LAB_0010da84:
        qtee_shmbridge_inv_shm_buf(param_11);
        qtee_shmbridge_inv_shm_buf(param_12);
      }
      else {
        iVar7 = -0x16;
      }
      if (iVar7 != -0x10) {
        if (iVar7 == 0) {
          iVar7 = 0;
          if (2 < (int)local_100 - 1U) {
            if ((param_8 != 0) && (*piVar2 == 0)) {
              iVar7 = marshal_out_invoke_req(param_1,param_3,param_7,param_8,param_10);
            }
            *param_9 = 1;
          }
        }
        goto LAB_0010dc48;
      }
      iVar7 = ___ratelimit(&prepare_send_scm_msg__rs,"prepare_send_scm_msg");
      if (iVar7 != 0) {
        _printk(&DAT_001181f9,"prepare_send_scm_msg",iVar17);
      }
      msleep(0x1e);
      if ((param_13 & 1) == 0) {
        iVar7 = -0x10;
        goto LAB_0010dc48;
      }
      bVar6 = iVar17 != iVar9;
      iVar17 = iVar17 + 1;
    } while (bVar6);
    iVar7 = -0x10;
    iVar17 = iVar9 + 1;
LAB_0010dc48:
    if (iVar15 == 0x32000601) {
      release_filp(&local_e8);
    }
    if (iVar7 != 0) goto LAB_0010d8dc;
    if (2 < (int)local_100 - 1U) {
      iVar7 = 0;
      goto LAB_0010d8dc;
    }
    if (local_100 - 1U < 2) {
      iVar7 = qseecom_process_listener_from_smcinvoke(piVar2,&local_100,&local_104);
      if ((*piVar2 == 0) && (local_100 != 3)) {
        iVar7 = marshal_out_invoke_req(param_1,param_3,param_7,param_8,param_10);
      }
      *param_9 = 1;
    }
    else {
      iVar7 = 0;
    }
    if (local_100 != 3) goto LAB_0010d8dc;
    if (param_4 == 0) {
      puVar8 = &DAT_001162c2;
LAB_0010de94:
      _printk(puVar8,"process_piggyback_cb_data","process_piggyback_cb_data");
    }
    else {
      if ((param_6 < *(uint *)(param_4 + 0x10)) ||
         (param_6 - *(uint *)(param_4 + 0x10) < (ulong)*(uint *)(param_4 + 0x14))) {
        puVar8 = &DAT_001170f8;
        goto LAB_0010de94;
      }
      uVar16 = *(uint *)(param_4 + 0xc);
      uVar11 = (ulong)uVar16 & 0xf;
      if ((int)uVar11 == 0) {
        iVar7 = 0;
        uVar10 = 0;
      }
      else {
        uVar10 = 0;
        iVar7 = 0;
        piVar12 = (int *)(param_4 + 0x14);
        uVar13 = uVar11;
        do {
          if (uVar10 < (uint)piVar12[-1]) {
            iVar7 = *piVar12;
            uVar10 = piVar12[-1];
          }
          uVar13 = uVar13 - 1;
          piVar12 = piVar12 + 2;
        } while (uVar13 != 0);
      }
      uVar14 = (ulong)(uVar16 >> 4) & 0xf;
      uVar13 = uVar14 + uVar11;
      if ((int)uVar14 != 0) {
        piVar12 = (int *)(param_4 + 0x14) + uVar11 * 2;
        do {
          if (uVar10 < (uint)piVar12[-1]) {
            iVar7 = *piVar12;
            uVar10 = piVar12[-1];
          }
          uVar11 = uVar11 + 1;
          piVar12 = piVar12 + 2;
        } while (uVar11 < uVar13);
      }
      if (uVar10 == 0) {
        uVar10 = ((uVar16 >> 0xc & 0xf) + (uVar16 >> 8 & 0xf) + (int)uVar13) * 8 + 0x10;
      }
      else {
        uVar10 = uVar10 + iVar7;
      }
      local_f8 = 0;
      local_f0 = 0;
      lVar1 = ((ulong)-uVar10 & 7) + (ulong)uVar10;
      __s = (uint *)(param_4 + lVar1);
      if (*__s != 0) {
        __n = g_max_cb_buf_size - lVar1;
        if (__s[2] != 0) {
          uVar16 = 0;
          do {
            if (__s[1] != 0xffff) break;
            local_f0 = 0xffff;
            local_f8 = CONCAT44(__s[(long)(int)uVar16 + 3],(undefined4)local_f8);
            if ((tz_async_version == 0) && (tz_async_version = *__s, 0x10001 < tz_async_version)) {
              mem_obj_async_support = 1;
            }
            process_tzcb_req(&local_f8,0x10,0);
            uVar16 = uVar16 + 1;
          } while (uVar16 < __s[2]);
        }
        memset(__s,0,__n);
      }
    }
    process_tzcb_req(param_4,param_6,&local_e8);
    iVar15 = 0x32000601;
  } while( true );
}



//------------------------------------------------------------
// release_filp @ 0010e00c size=276
// signature: undefined release_filp(void)
// callers: [prepare_send_scm_msg, process_invoke_req]
//------------------------------------------------------------

void release_filp(long *param_1)

{
  if (*param_1 != 0) {
    fput();
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    fput();
    param_1[1] = 0;
  }
  if (param_1[2] != 0) {
    fput();
    param_1[2] = 0;
  }
  if (param_1[3] != 0) {
    fput();
    param_1[3] = 0;
  }
  if (param_1[4] != 0) {
    fput();
    param_1[4] = 0;
  }
  if (param_1[5] != 0) {
    fput();
    param_1[5] = 0;
  }
  if (param_1[6] != 0) {
    fput();
    param_1[6] = 0;
  }
  if (param_1[7] != 0) {
    fput();
    param_1[7] = 0;
  }
  if (param_1[8] != 0) {
    fput();
    param_1[8] = 0;
  }
  if (param_1[9] != 0) {
    fput();
    param_1[9] = 0;
  }
  if (param_1[10] != 0) {
    fput();
    param_1[10] = 0;
  }
  if (param_1[0xb] != 0) {
    fput();
    param_1[0xb] = 0;
  }
  if (param_1[0xc] != 0) {
    fput();
    param_1[0xc] = 0;
  }
  if (param_1[0xd] != 0) {
    fput();
    param_1[0xd] = 0;
  }
  if (param_1[0xe] != 0) {
    fput();
    param_1[0xe] = 0;
  }
  return;
}



//------------------------------------------------------------
// marshal_out_invoke_req @ 0010e120 size=996
// signature: undefined marshal_out_invoke_req(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int marshal_out_invoke_req(long param_1,uint param_2,long param_3,long param_4,int param_5)

{
  uint uVar1;
  long lVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  ulong uVar9;
  undefined **ppuVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  uint *puVar15;
  ulong uVar16;
  ulong *puVar17;
  int local_6c;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  uVar13 = *(uint *)(param_3 + 4);
  uVar16 = (ulong)uVar13 & 0xf;
  uVar1 = uVar13 >> 4 & 0xf;
  uVar12 = uVar1 + (int)uVar16;
  uVar8 = (ulong)uVar12;
  uVar11 = uVar13 >> 8 & 0xf;
  uVar12 = uVar12 + uVar11;
  uVar13 = uVar12 + (uVar13 >> 0xc & 0xf);
  if (param_2 < uVar13 * 8 + 0xc) {
    iVar7 = -0x16;
  }
  else {
    if (param_4 != 0) {
      puVar15 = (uint *)(param_1 + uVar16 * 8 + 0xc);
      if (uVar1 != 0) {
        puVar3 = (undefined8 *)sp_el0;
        puVar17 = (ulong *)(param_4 + uVar16 * 0x18);
        do {
          puVar17[1] = (ulong)puVar15[1];
          uVar12 = *puVar15;
          if (param_2 < uVar12) {
LAB_0010e580:
            _printk(&DAT_00116a28,"marshal_out_invoke_req","marshal_out_invoke_req");
            iVar7 = -0x16;
            goto LAB_0010e52c;
          }
          uVar13 = puVar15[1];
          uVar8 = (ulong)uVar13;
          if (param_2 - uVar12 < uVar13) goto LAB_0010e580;
          if (param_5 == 0) {
            if ((int)uVar13 < 0) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10e5a4);
              (*pcVar6)();
            }
            uVar14 = *puVar17;
            __check_object_size(param_1 + (ulong)uVar12,uVar8,1);
            if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
               (uVar9 = uVar14, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
              uVar9 = uVar14 & (long)(uVar14 << 8) >> 8;
            }
            if (uVar9 <= 0x8000000000 - uVar8) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar9 = daif;
                if ((uVar9 & 0x80) == 0) {
                  uVar5 = daif;
                  daif = uVar5 | 0xc0;
                }
                uVar5 = ttbr1_el1;
                ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar5 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar3[1];
                InstructionSynchronizationBarrier();
                daif = uVar9;
              }
              uVar8 = __arch_copy_to_user(uVar14 & 0xff7fffffffffffff,param_1 + (ulong)uVar12,uVar8)
              ;
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar14 = daif;
                if ((uVar14 & 0x80) == 0) {
                  uVar9 = daif;
                  daif = uVar9 | 0xc0;
                }
                uVar9 = ttbr1_el1;
                ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar9 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar14;
              }
            }
            if (uVar8 != 0) {
              iVar7 = -0x16;
              _printk(&DAT_00116e40,"marshal_out_invoke_req",0xffffffea);
              goto LAB_0010e52c;
            }
          }
          else {
            memcpy((void *)*puVar17,(void *)(param_1 + (ulong)*puVar15),uVar8);
          }
          uVar13 = *(uint *)(param_3 + 4);
          puVar15 = puVar15 + 2;
          uVar16 = uVar16 + 1;
          puVar17 = puVar17 + 3;
          uVar8 = ((ulong)(uVar13 >> 4) & 0xf) + ((ulong)uVar13 & 0xf);
        } while (uVar16 < uVar8);
        uVar11 = uVar13 >> 8 & 0xf;
        uVar12 = (int)uVar8 + uVar11;
        uVar13 = uVar12 + (uVar13 >> 0xc & 0xf);
      }
      if (uVar12 < uVar13) {
        puVar15 = puVar15 + (ulong)uVar11 * 2;
        uVar8 = uVar8 + uVar11;
        uVar4 = sp_el0;
        do {
          local_6c = -1;
          uVar12 = *puVar15;
          iVar7 = -1;
          if (uVar12 == 0) {
LAB_0010e42c:
            local_6c = iVar7;
            *(long *)(param_4 + uVar8 * 0x18) = (long)local_6c;
          }
          else {
            if ((int)uVar12 < 0) {
              if ((uVar12 & 0xffff) < 0x10) {
                if (((uVar12 & 0xffff) == 1) && ((undefined **)g_mem_objs != &g_mem_objs)) {
                  ppuVar10 = (undefined **)g_mem_objs;
                  while ((uint)*(ushort *)(ppuVar10 + -7) != (uVar12 >> 0x10 & 0x7fff)) {
                    ppuVar10 = (undefined **)*ppuVar10;
                    if (ppuVar10 == &g_mem_objs) goto LAB_0010e568;
                  }
                  if ((ppuVar10 != (undefined **)0x38) &&
                     (iVar7 = *(int *)(ppuVar10 + 4), -1 < *(int *)(ppuVar10 + 4)))
                  goto LAB_0010e42c;
                }
LAB_0010e568:
                iVar7 = -1;
                *(undefined8 *)(param_4 + uVar8 * 0x18) = 0xffffffffffffffff;
                goto LAB_0010e52c;
              }
              uVar13 = uVar12 >> 0x10 & 0x7fff;
              local_6c = -2 - uVar13;
              iVar7 = get_pending_cbobj_locked(uVar12,uVar13);
            }
            else {
              iVar7 = get_fd_for_obj(param_5,uVar12,&local_6c);
            }
            *(long *)(param_4 + uVar8 * 0x18) = (long)local_6c;
            if (iVar7 != 0) goto LAB_0010e52c;
          }
          uVar12 = *(uint *)(param_3 + 4);
          puVar15 = puVar15 + 2;
          uVar8 = uVar8 + 1;
        } while (uVar8 < ((ulong)(uVar12 >> 4) & 0xf) + ((ulong)uVar12 & 0xf) +
                         ((ulong)(uVar12 >> 8) & 0xf) + ((ulong)(uVar12 >> 0xc) & 0xf));
      }
    }
    iVar7 = 0;
  }
LAB_0010e52c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// process_tzcb_req @ 0010e5c8 size=2652
// signature: undefined process_tzcb_req(void)
// callers: [smcinvoke_release_tz_object, prepare_send_scm_msg, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void process_tzcb_req(int *param_1,ulong param_2,undefined8 param_3)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *__src;
  int *piVar7;
  uint *puVar8;
  char *pcVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined4 uVar12;
  ushort *puVar13;
  undefined *puVar14;
  long *plVar15;
  long *plVar16;
  long lVar17;
  undefined **ppuVar18;
  long lVar19;
  ushort *puVar20;
  int *piVar21;
  long lVar22;
  bool bVar23;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  if (param_2 < 0x10) {
    _printk(&DAT_00116cba,"process_tzcb_req",param_2);
    goto LAB_0010f224;
  }
  uVar3 = param_1[1];
  uVar11 = uVar3 & 0x8000ffff;
  if (uVar11 == 0x80000002) {
    mutex_lock(&g_smcinvoke_lock);
    if (param_1[2] == 0xffff) {
      if (param_1[3] != 0) {
        _printk(&DAT_00117b9e,"smcinvoke_release_mem_obj_locked","smcinvoke_release_mem_obj_locked")
        ;
        goto LAB_0010ee98;
      }
      iVar6 = release_tzhandle_locked(param_1[1]);
      *param_1 = iVar6;
    }
    else {
LAB_0010ee98:
      *param_1 = 2;
    }
  }
  else {
    if (uVar11 != 0x80000001) {
      if (uVar11 == 0x80000000) {
        iVar6 = param_1[2];
        if (iVar6 == 2) {
          if ((param_1[3] == 1) && ((ulong)(uint)param_1[5] <= param_2 - (uint)param_1[4])) {
            msleep(*(undefined4 *)((long)param_1 + (ulong)(uint)param_1[4]));
            goto LAB_0010eb7c;
          }
          puVar14 = &DAT_00116a94;
          pcVar9 = "smcinvoke_sleep";
        }
        else {
          if (iVar6 == 1) {
LAB_0010eb7c:
            *param_1 = 0;
            goto LAB_0010f224;
          }
          if (iVar6 == 0) {
            if (mem_obj_async_support == '\x01') {
              _printk(&DAT_00116ce8,"process_kernel_obj");
            }
            if ((param_1[3] == 0x1110) &&
               (uVar11 = param_1[4], (ulong)(uint)param_1[5] <= param_2 - uVar11)) {
              mutex_lock(&g_smcinvoke_lock);
              if ((undefined **)g_mem_objs != &g_mem_objs) {
                puVar1 = (undefined8 *)((long)param_1 + (ulong)uVar11);
                ppuVar18 = (undefined **)g_mem_objs;
                do {
                  if (*(ushort *)(ppuVar18 + -7) == (*(ushort *)((long)param_1 + 0x1a) & 0x7fff)) {
                    if (ppuVar18 + -7 != (undefined **)0x0) {
                      if (ppuVar18[-2] == (undefined *)0x0) {
                        iVar6 = smcinvoke_map_mem_region_locked(ppuVar18 + -7);
                        if (iVar6 == 0) goto LAB_0010ebb8;
                      }
                      else {
                        puVar8 = (uint *)((long)ppuVar18 + -0x14);
                        Hint_Prefetch(puVar8,2,0,1);
                        do {
                          uVar11 = *puVar8;
                          cVar4 = '\x01';
                          bVar23 = (bool)ExclusiveMonitorPass(puVar8,0x10);
                          if (bVar23) {
                            *puVar8 = uVar11 + 1;
                            cVar4 = ExclusiveMonitorsStatus();
                          }
                        } while (cVar4 != '\0');
                        if (uVar11 == 0) {
                          refcount_warn_saturate(puVar8,2);
                        }
                        else if ((int)(uVar11 + 1 | uVar11) < 0) {
                          refcount_warn_saturate(puVar8,1);
                        }
LAB_0010ebb8:
                        iVar6 = 0;
                        *puVar1 = ppuVar18[-2];
                        puVar14 = ppuVar18[-1];
                        *(undefined4 *)(puVar1 + 2) = 6;
                        puVar1[1] = puVar14;
                        param_1[8] = (uint)*(ushort *)((long)ppuVar18 + -0x36) << 0x10 | 0x80000002;
                      }
                      mutex_unlock(&g_smcinvoke_lock);
                      *param_1 = iVar6;
                      goto LAB_0010f224;
                    }
                    break;
                  }
                  ppuVar18 = (undefined **)*ppuVar18;
                } while (ppuVar18 != &g_mem_objs);
              }
              mutex_unlock(&g_smcinvoke_lock);
              _printk(&DAT_00117611,"smcinvoke_process_map_mem_region_req");
              *param_1 = -0x5c;
              goto LAB_0010f224;
            }
            puVar14 = &DAT_00117761;
            pcVar9 = "smcinvoke_process_map_mem_region_req";
          }
          else {
            puVar14 = &DAT_00118106;
            pcVar9 = "process_kernel_obj";
          }
        }
        _printk(puVar14,pcVar9);
        *param_1 = 2;
        goto LAB_0010f224;
      }
      if ((-1 < (int)uVar3) || ((uVar3 & 0xfff0) == 0)) {
        _printk(&DAT_00116a57,"process_tzcb_req");
        *param_1 = 2;
        goto LAB_0010f224;
      }
    }
    __src = (undefined4 *)kmemdup(param_1,param_2,0xcc0);
    if (__src == (undefined4 *)0x0) {
      *param_1 = -0x61;
      _printk(&DAT_001167a6,"process_tzcb_req",0xffffff9f);
      goto LAB_0010f224;
    }
    piVar7 = (int *)kmalloc_trace(_kfree,0xdc0,0x38);
    if (piVar7 == (int *)0x0) {
      *param_1 = -0x61;
      _printk(&DAT_00116615,"process_tzcb_req",0xffffff9f);
      kfree(__src);
      goto LAB_0010f224;
    }
    piVar21 = piVar7 + 0xc;
    *piVar21 = 1;
    piVar7[1] = 1;
    *(undefined4 **)(piVar7 + 2) = __src;
    *(ulong *)(piVar7 + 4) = param_2;
    *(undefined8 *)(piVar7 + 6) = param_3;
    mutex_lock(&g_smcinvoke_lock);
    uVar11 = __src[1];
    cb_reqs_inflight = cb_reqs_inflight + 1;
    if ((uVar11 & 0x8000ffff) == 0x80000001) {
      if ((undefined **)g_mem_objs != &g_mem_objs) {
        ppuVar18 = (undefined **)g_mem_objs;
        do {
          if ((uint)*(ushort *)(ppuVar18 + -7) == (uVar11 >> 0x10 & 0x7fff)) {
            if (ppuVar18 != (undefined **)0x38) {
              uVar11 = (uint)*(ushort *)ppuVar18[3];
              goto LAB_0010e7f0;
            }
            break;
          }
          ppuVar18 = (undefined **)*ppuVar18;
        } while (ppuVar18 != &g_mem_objs);
      }
      _printk(&DAT_0011772b,"process_tzcb_req");
      puVar20 = (ushort *)0x0;
LAB_0010ecb8:
      mutex_unlock(&g_smcinvoke_lock);
      iVar5 = -0x5a;
    }
    else {
      uVar11 = uVar11 & 0xffff;
LAB_0010e7f0:
      puVar20 = (ushort *)
                (*(long *)(g_cb_servers + (ulong)(uVar11 * 0x61c88647 >> 0x18) * 8) + -0x148);
      if (*(long *)(g_cb_servers + (ulong)(uVar11 * 0x61c88647 >> 0x18) * 8) == 0 ||
          puVar20 == (ushort *)0x0) {
LAB_0010e838:
        _printk(&DAT_0011763b,"process_tzcb_req");
        puVar20 = (ushort *)0x0;
        goto LAB_0010ecb8;
      }
LAB_0010e81c:
      if (*puVar20 != uVar11) goto code_r0x0010e828;
      puVar8 = (uint *)(puVar20 + 4);
      Hint_Prefetch(puVar8,2,0,1);
      do {
        uVar11 = *puVar8;
        cVar4 = '\x01';
        bVar23 = (bool)ExclusiveMonitorPass(puVar8,0x10);
        if (bVar23) {
          *puVar8 = uVar11 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (uVar11 == 0) {
        uVar10 = 2;
LAB_0010f11c:
        refcount_warn_saturate(puVar8,uVar10);
      }
      else if ((int)(uVar11 + 1 | uVar11) < 0) {
        uVar10 = 1;
        goto LAB_0010f11c;
      }
      if (puVar20[1] == 1) {
        _printk(&DAT_0011711f,"process_tzcb_req",1,__src[1]);
        goto LAB_0010ecb8;
      }
      iVar6 = *(int *)(puVar20 + 2) + 1;
      *(int *)(puVar20 + 2) = iVar6;
      *piVar7 = iVar6;
      puVar13 = puVar20 + (ulong)((uint)(iVar6 * 0x61c88647) >> 0x1c) * 4 + 0x24;
      lVar17 = *(long *)puVar13;
      plVar16 = (long *)(piVar7 + 8);
      *plVar16 = lVar17;
      if (lVar17 != 0) {
        *(long **)(lVar17 + 8) = plVar16;
      }
      *(long **)puVar13 = plVar16;
      *(ushort **)(piVar7 + 10) = puVar13;
      mutex_unlock(&g_smcinvoke_lock);
      lVar17 = sp_el0;
      __wake_up(puVar20 + 8,1,0,0);
      bVar23 = false;
      puVar13 = puVar20 + 0x14;
      iVar6 = 0;
      do {
        if (!bVar23) {
          if (piVar7[1] == 3) {
LAB_0010e99c:
            iVar5 = 0x19;
LAB_0010eabc:
            if ((puVar20[1] != 1) && (piVar7[1] != 3)) {
              bVar23 = true;
              goto LAB_0010e92c;
            }
          }
          else {
            if (puVar20[1] != 1) {
              local_78 = 0;
              uStack_70 = 0;
              local_88 = 0;
              uStack_80 = 0;
              local_90 = 0;
              init_wait_entry(&local_90,0);
              lVar22 = prepare_to_wait_event(puVar13,&local_90,1);
              if (piVar7[1] == 3) {
                lVar19 = 0x19;
              }
              else {
                lVar19 = 0x19;
                do {
                  if (lVar19 == 0 && puVar20[1] == 1) {
                    lVar19 = 1;
                  }
                  if (puVar20[1] == 1 || lVar19 == 0) goto LAB_0010eaa8;
                  if (lVar22 != 0) goto LAB_0010eab8;
                  lVar19 = schedule_timeout(lVar19);
                  lVar22 = prepare_to_wait_event(puVar13,&local_90,1);
                } while (piVar7[1] != 3);
                if (lVar19 == 0) {
                  lVar19 = 1;
                }
              }
LAB_0010eaa8:
              finish_wait(puVar13,&local_90);
              lVar22 = lVar19;
              goto LAB_0010eab8;
            }
LAB_0010ec08:
            iVar5 = 0x19;
          }
          break;
        }
        if (piVar7[1] == 3) goto LAB_0010e99c;
        if (puVar20[1] == 1) goto LAB_0010ec08;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_90 = 0;
        init_wait_entry(&local_90,0);
        prepare_to_wait_event(puVar13,&local_90,2);
        if (piVar7[1] == 3) {
          lVar22 = 0x19;
        }
        else {
          lVar22 = 0x19;
          do {
            if (lVar22 == 0 && puVar20[1] == 1) {
              lVar22 = 1;
            }
            if (puVar20[1] == 1 || lVar22 == 0) goto LAB_0010ea3c;
            lVar22 = schedule_timeout(lVar22);
            prepare_to_wait_event(puVar13,&local_90,2);
          } while (piVar7[1] != 3);
          if (lVar22 == 0) {
            lVar22 = 1;
          }
        }
LAB_0010ea3c:
        finish_wait(puVar13,&local_90);
LAB_0010eab8:
        iVar5 = (int)lVar22;
        if (iVar5 != 0) goto LAB_0010eabc;
        if ((char)puVar20[0xb4] == '\0') {
          iVar5 = ___ratelimit(process_tzcb_req__rs,"process_tzcb_req");
          if (iVar5 != 0) {
            _printk(&DAT_001174f6,"process_tzcb_req",*piVar7,__src[1],iVar6,__src[2],__src[3]);
          }
          iVar5 = ___ratelimit(process_tzcb_req__rs_240,"process_tzcb_req");
          if (iVar5 != 0) {
            _printk(&DAT_00116e70,"process_tzcb_req",__src[1],*(undefined4 *)(lVar17 + 0x630),
                    *(undefined4 *)(lVar17 + 0x634),puVar20[1],*puVar20);
          }
        }
        iVar5 = 0;
LAB_0010e92c:
        iVar2 = 0;
        if ((char)puVar20[0xb4] == '\0') {
          iVar2 = iVar6 + 1;
        }
        iVar6 = iVar2;
      } while (iVar2 < 0x32);
    }
    mutex_lock(&g_smcinvoke_lock);
    plVar15 = *(long **)(piVar7 + 10);
    plVar16 = (long *)(piVar7 + 8);
    if (plVar15 != (long *)0x0) {
      lVar17 = *plVar16;
      *plVar15 = lVar17;
      if (lVar17 != 0) {
        *(long **)(lVar17 + 8) = plVar15;
      }
      *plVar16 = 0;
      piVar7[10] = 0;
      piVar7[0xb] = 0;
    }
    if (iVar5 == -0x200) {
      _printk(&DAT_001180d5,"process_tzcb_req",0xfffffe00);
LAB_0010edcc:
      uVar12 = 0xffffffa5;
LAB_0010edd0:
      *__src = uVar12;
    }
    else {
      if (iVar5 == 0) {
        _printk(&DAT_00117975,"process_tzcb_req");
        uVar12 = 0xffffff99;
        goto LAB_0010edd0;
      }
      if (piVar7[1] != 3) {
        if ((puVar20 != (ushort *)0x0) && (puVar20[1] != 1)) {
          _printk(&DAT_0011734e,"process_tzcb_req","process_tzcb_req",iVar5);
          goto LAB_0010edcc;
        }
        *__src = 0xffffffa6;
        _printk(&DAT_00116659,"process_tzcb_req",0xffffffa6);
      }
    }
    cb_reqs_inflight = cb_reqs_inflight + -1;
    memcpy(param_1,__src,param_2);
    Hint_Prefetch(piVar21,2,0,1);
    do {
      iVar6 = *piVar21;
      cVar4 = '\x01';
      bVar23 = (bool)ExclusiveMonitorPass(piVar21,0x10);
      if (bVar23) {
        *piVar21 = iVar6 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar6 == 1) {
      DataMemoryBarrier(2,1);
      lVar17 = *(long *)(piVar7 + 2);
      if (*(short *)(lVar17 + 8) == -1) {
        release_tzhandle_locked(*(undefined4 *)(lVar17 + 4));
        lVar17 = *(long *)(piVar7 + 2);
      }
      kfree(lVar17);
      plVar15 = *(long **)(piVar7 + 10);
      if (plVar15 != (long *)0x0) {
        lVar17 = *plVar16;
        *plVar15 = lVar17;
        if (lVar17 != 0) {
          *(long **)(lVar17 + 8) = plVar15;
        }
        *plVar16 = 0;
        piVar7[10] = 0;
        piVar7[0xb] = 0;
      }
      kfree(piVar7);
    }
    else if (iVar6 < 1) {
      refcount_warn_saturate(piVar21,3);
    }
    if (puVar20 != (ushort *)0x0) {
      puVar13 = puVar20 + 4;
      Hint_Prefetch(puVar13,2,0,1);
      do {
        iVar6 = *(int *)puVar13;
        cVar4 = '\x01';
        bVar23 = (bool)ExclusiveMonitorPass(puVar13,0x10);
        if (bVar23) {
          *(int *)puVar13 = iVar6 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar6 == 1) {
        DataMemoryBarrier(2,1);
        plVar16 = *(long **)(puVar20 + 0xa8);
        if (plVar16 != (long *)0x0) {
          puVar13 = puVar20 + 0xa4;
          lVar17 = *(long *)puVar13;
          *plVar16 = lVar17;
          if (lVar17 != 0) {
            *(long **)(lVar17 + 8) = plVar16;
          }
          puVar13[0] = 0;
          puVar13[1] = 0;
          puVar13[2] = 0;
          puVar13[3] = 0;
          puVar20[0xa8] = 0;
          puVar20[0xa9] = 0;
          puVar20[0xaa] = 0;
          puVar20[0xab] = 0;
        }
        kfree(puVar20);
      }
      else if (iVar6 < 1) {
        refcount_warn_saturate(puVar13,3);
      }
    }
  }
  mutex_unlock(&g_smcinvoke_lock);
LAB_0010f224:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
code_r0x0010e828:
  if ((*(long *)(puVar20 + 0xa4) == 0) ||
     (puVar20 = (ushort *)(*(long *)(puVar20 + 0xa4) + -0x148), puVar20 == (ushort *)0x0))
  goto LAB_0010e838;
  goto LAB_0010e81c;
}



//------------------------------------------------------------
// smcinvoke_probe @ 0010f330 size=960
// signature: undefined smcinvoke_probe(void)
// callers: []
//------------------------------------------------------------

ulong smcinvoke_probe(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  undefined *puVar6;
  
  uVar1 = dma_set_mask(param_1 + 0x10,0xffffffffffffffff);
  if (uVar1 == 0) {
    dma_set_coherent_mask(param_1 + 0x10,0xffffffffffffffff);
    lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,support-legacy_smc",0);
    legacy_smc_call = lVar3 != 0;
    invoke_cmd = 0x32000600;
    if (!(bool)legacy_smc_call) {
      invoke_cmd = 0x32000602;
    }
    __init_waitqueue_head
              (&DAT_00118508,"&smcinvoke[i].postprocess_kthread_wq",&smcinvoke_create_kthreads___key
              );
    smcinvoke = 0;
    uVar4 = kthread_create_on_node
                      (smcinvoke_postprocess_kthread_func,&smcinvoke,0xffffffff,
                       "smcinvoke_shmbridge_postprocess");
    if (uVar4 < 0xfffffffffffff001) {
      wake_up_process(uVar4);
      DAT_00118504 = 0;
      DAT_00118520 = uVar4;
      __init_waitqueue_head
                (&DAT_00118530,"&smcinvoke[i].postprocess_kthread_wq",
                 &smcinvoke_create_kthreads___key);
      lVar3 = 1;
      DAT_00118528 = 1;
      uVar4 = kthread_create_on_node
                        (smcinvoke_postprocess_kthread_func,&DAT_00118528,0xffffffff,
                         "smcinvoke_object_postprocess");
      if (0xfffffffffffff000 < uVar4) goto LAB_0010f5ec;
      wake_up_process(uVar4);
      DAT_0011852c = 0;
      DAT_00118548 = uVar4;
      __init_waitqueue_head
                (&DAT_00118558,"&smcinvoke[i].postprocess_kthread_wq",
                 &smcinvoke_create_kthreads___key);
      lVar3 = 2;
      DAT_00118550 = 2;
      uVar4 = kthread_create_on_node
                        (smcinvoke_postprocess_kthread_func,&DAT_00118550,0xffffffff,
                         "smcinvoke_adci_thread");
      if (0xfffffffffffff000 < uVar4) goto LAB_0010f5ec;
      wake_up_process(uVar4);
      DAT_00118554 = 0;
      DAT_00118570 = uVar4;
    }
    else {
      lVar3 = 0;
LAB_0010f5ec:
      (&DAT_00118520)[lVar3 * 5] = uVar4;
      _printk(&DAT_001184b8,"smcinvoke_create_kthreads",uVar4 & 0xffffffff);
      if ((int)uVar4 != 0) {
        puVar6 = &DAT_00116500;
        goto LAB_0010f5d4;
      }
    }
    uVar5 = alloc_chrdev_region(&smcinvoke_device_no,0,1,"smcinvoke");
    uVar4 = uVar5 & 0xffffffff;
    if ((int)uVar5 < 0) {
      _printk(&DAT_00117021,"smcinvoke_probe",uVar4,"smcinvoke");
      smcinvoke_destroy_kthreads();
    }
    else {
      driver_class = __class_create(&__this_module,"smcinvoke",&smcinvoke_probe___key);
      if (driver_class < 0xfffffffffffff001) {
        class_dev = device_create(driver_class,0,smcinvoke_device_no,0,"smcinvoke");
        if (class_dev == 0) {
          _printk(&DAT_00116ecd,"smcinvoke_probe",uVar4);
          uVar4 = 0xfffffff4;
        }
        else {
          cdev_init(smcinvoke_cdev,&g_smcinvoke_fops);
          smcinvoke_cdev._96_8_ = &__this_module;
          uVar4 = cdev_add(smcinvoke_cdev,smcinvoke_device_no & 0xfff00000,1);
          if (-1 < (int)uVar4) {
            smcinvoke_pdev = param_1;
            iVar2 = get_qseecom_kernel_fun_ops();
            if (iVar2 != 0) {
              _printk(&DAT_00117271,"smcinvoke_probe",iVar2);
            }
            DAT_00118554 = 1;
            __wake_up(&DAT_00118558,1,1,0);
            uVar4 = 0;
            goto LAB_0010f5ac;
          }
          uVar4 = uVar4 & 0xffffffff;
          _printk(&DAT_0011715c,"smcinvoke_probe",uVar4,"smcinvoke");
          device_destroy(driver_class,smcinvoke_device_no);
        }
        class_destroy(driver_class);
      }
      else {
        uVar4 = 0xfffffff4;
        _printk(&DAT_00117fff,"smcinvoke_probe",0xfffffff4);
      }
      unregister_chrdev_region(smcinvoke_device_no,1);
      smcinvoke_destroy_kthreads();
    }
  }
  else {
    uVar4 = (ulong)uVar1;
    puVar6 = &DAT_001168af;
LAB_0010f5d4:
    _printk(puVar6,"smcinvoke_probe",uVar4 & 0xffffffff);
  }
LAB_0010f5ac:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// smcinvoke_remove @ 0010f6f4 size=92
// signature: undefined smcinvoke_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 smcinvoke_remove(void)

{
  smcinvoke_destroy_kthreads();
  cdev_del(smcinvoke_cdev);
  device_destroy(driver_class,smcinvoke_device_no);
  class_destroy(driver_class);
  unregister_chrdev_region(smcinvoke_device_no,1);
  return 0;
}



//------------------------------------------------------------
// smcinvoke_suspend @ 0010f754 size=104
// signature: undefined smcinvoke_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 smcinvoke_suspend(void)

{
  undefined8 uVar1;
  
  mutex_lock(&g_smcinvoke_lock);
  if (cb_reqs_inflight == 0) {
    uVar1 = 0;
  }
  else {
    _printk(&DAT_001179a8,"smcinvoke_suspend");
    uVar1 = 0xfffffffb;
  }
  mutex_unlock(&g_smcinvoke_lock);
  return uVar1;
}



//------------------------------------------------------------
// smcinvoke_resume @ 0010f7c0 size=8
// signature: undefined smcinvoke_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 smcinvoke_resume(void)

{
  return 0;
}



//------------------------------------------------------------
// smcinvoke_destroy_kthreads @ 0010f7c8 size=892
// signature: undefined smcinvoke_destroy_kthreads(void)
// callers: [smcinvoke_probe, smcinvoke_remove]
//------------------------------------------------------------

void smcinvoke_destroy_kthreads(void)

{
  code *pcVar1;
  int iVar2;
  
  if (adci_rootEnv == (code *)0x0) goto LAB_0010fa84;
  if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f814);
    (*pcVar1)();
  }
  iVar2 = (*adci_rootEnv)(DAT_00118e50,9,0,0);
  if (iVar2 != 0) {
    if (iVar2 == -99) {
      iVar2 = ___ratelimit(smcinvoke_destroy_kthreads__rs,"smcinvoke_destroy_kthreads",0xffffff9d);
      if (iVar2 != 0) {
        _printk(&DAT_001162e7,"smcinvoke_destroy_kthreads",0);
      }
      msleep(5);
      if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f878);
        (*pcVar1)();
      }
      iVar2 = (*adci_rootEnv)(DAT_00118e50,9,0,0);
      if (iVar2 == 0) goto LAB_0010fa4c;
      if (iVar2 == -99) {
        iVar2 = ___ratelimit(smcinvoke_destroy_kthreads__rs,"smcinvoke_destroy_kthreads",0xffffff9d)
        ;
        if (iVar2 != 0) {
          _printk(&DAT_001162e7,"smcinvoke_destroy_kthreads",1);
        }
        msleep(5);
        if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f8d4);
          (*pcVar1)();
        }
        iVar2 = (*adci_rootEnv)(DAT_00118e50,9,0,0);
        if (iVar2 == 0) goto LAB_0010fa4c;
        if (iVar2 == -99) {
          iVar2 = ___ratelimit(smcinvoke_destroy_kthreads__rs,"smcinvoke_destroy_kthreads",
                               0xffffff9d);
          if (iVar2 != 0) {
            _printk(&DAT_001162e7,"smcinvoke_destroy_kthreads",2);
          }
          msleep(5);
          if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f930);
            (*pcVar1)();
          }
          iVar2 = (*adci_rootEnv)(DAT_00118e50,9,0,0);
          if (iVar2 == 0) goto LAB_0010fa4c;
          if (iVar2 == -99) {
            iVar2 = ___ratelimit(smcinvoke_destroy_kthreads__rs,"smcinvoke_destroy_kthreads",
                                 0xffffff9d);
            if (iVar2 != 0) {
              _printk(&DAT_001162e7,"smcinvoke_destroy_kthreads",3);
            }
            msleep(5);
            if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f98c);
              (*pcVar1)();
            }
            iVar2 = (*adci_rootEnv)(DAT_00118e50,9,0,0);
            if (iVar2 == 0) goto LAB_0010fa4c;
            if (iVar2 == -99) {
              iVar2 = ___ratelimit(smcinvoke_destroy_kthreads__rs,"smcinvoke_destroy_kthreads",
                                   0xffffff9d);
              if (iVar2 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_destroy_kthreads",4);
              }
              msleep(5);
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f9e8);
                (*pcVar1)();
              }
              iVar2 = (*adci_rootEnv)(DAT_00118e50,9,0,0);
              if (iVar2 == 0) goto LAB_0010fa4c;
              if (iVar2 == -99) {
                iVar2 = ___ratelimit(smcinvoke_destroy_kthreads__rs,"smcinvoke_destroy_kthreads",
                                     0xffffff9d);
                if (iVar2 != 0) {
                  _printk(&DAT_001162e7,"smcinvoke_destroy_kthreads",5);
                }
                msleep(5);
                iVar2 = -99;
              }
            }
          }
        }
      }
    }
    _printk(&DAT_001167e9,"smcinvoke_destroy_kthreads",iVar2);
  }
LAB_0010fa4c:
  if (adci_rootEnv != (code *)0x0) {
    if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10fa7c);
      (*pcVar1)();
    }
    (*adci_rootEnv)(DAT_00118e50,0xffff,0,0);
  }
  adci_rootEnv = (code *)0x0;
  DAT_00118e50 = 0;
LAB_0010fa84:
  kthread_stop(DAT_00118520);
  kthread_stop(DAT_00118548);
  kthread_stop(DAT_00118570);
  return;
}



//------------------------------------------------------------
// smcinvoke_postprocess_kthread_func @ 0010fb48 size=1740
// signature: undefined smcinvoke_postprocess_kthread_func(void)
// callers: []
//------------------------------------------------------------

void smcinvoke_postprocess_kthread_func(int *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  undefined *puVar8;
  undefined8 uVar9;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  if (param_1 == (int *)0x0) {
    _printk(&DAT_001172ab,"smcinvoke_postprocess_kthread_func");
    uVar5 = 0xffffffea;
  }
  else {
    uVar6 = kthread_should_stop();
    if ((uVar6 & 1) == 0) {
      do {
        uVar6 = kthread_should_stop();
        if (((uVar6 & 1) == 0) && (param_1[1] != 1)) {
          local_90 = 0;
          uStack_88 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          local_a8 = 0;
          init_wait_entry(&local_a8,0);
          while( true ) {
            lVar7 = prepare_to_wait_event(param_1 + 2,&local_a8,1);
            uVar6 = kthread_should_stop();
            if (((uVar6 & 1) != 0) || (param_1[1] == 1)) break;
            if (lVar7 != 0) goto LAB_0010fc9c;
            schedule();
          }
          finish_wait(param_1 + 2,&local_a8);
        }
LAB_0010fc9c:
        iVar3 = *param_1;
        if (iVar3 == 2) {
          iVar3 = get_root_obj(&adci_rootEnv);
          if (iVar3 == 0) {
            if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10fde0);
              (*pcVar2)();
            }
            iVar3 = (*adci_rootEnv)(DAT_00118e50,8,0,0);
            if (iVar3 == -99) {
              iVar3 = ___ratelimit(smcinvoke_start_adci_thread__rs,"smcinvoke_start_adci_thread");
              if (iVar3 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_start_adci_thread",0);
              }
              msleep(5);
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10fe34);
                (*pcVar2)();
              }
              iVar3 = (*adci_rootEnv)(DAT_00118e50,8,0,0);
              if (iVar3 != -99) goto LAB_0010ff90;
              iVar3 = ___ratelimit(smcinvoke_start_adci_thread__rs,"smcinvoke_start_adci_thread");
              if (iVar3 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_start_adci_thread",1);
              }
              msleep(5);
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10fe88);
                (*pcVar2)();
              }
              iVar3 = (*adci_rootEnv)(DAT_00118e50,8,0,0);
              if (iVar3 != -99) goto LAB_0010ff90;
              iVar3 = ___ratelimit(smcinvoke_start_adci_thread__rs,"smcinvoke_start_adci_thread");
              if (iVar3 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_start_adci_thread",2);
              }
              msleep(5);
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10fedc);
                (*pcVar2)();
              }
              iVar3 = (*adci_rootEnv)(DAT_00118e50,8,0,0);
              if (iVar3 != -99) goto LAB_0010ff90;
              iVar3 = ___ratelimit(smcinvoke_start_adci_thread__rs,"smcinvoke_start_adci_thread");
              if (iVar3 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_start_adci_thread",3);
              }
              msleep(5);
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10ff30);
                (*pcVar2)();
              }
              iVar3 = (*adci_rootEnv)(DAT_00118e50,8,0,0);
              if (iVar3 != -99) goto LAB_0010ff90;
              iVar3 = ___ratelimit(smcinvoke_start_adci_thread__rs,"smcinvoke_start_adci_thread");
              if (iVar3 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_start_adci_thread",4);
              }
              msleep(5);
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10ff84);
                (*pcVar2)();
              }
              iVar3 = (*adci_rootEnv)(DAT_00118e50,8,0,0);
              if (iVar3 != -99) goto LAB_0010ff90;
              iVar3 = ___ratelimit(smcinvoke_start_adci_thread__rs,"smcinvoke_start_adci_thread");
              if (iVar3 != 0) {
                _printk(&DAT_001162e7,"smcinvoke_start_adci_thread",5);
              }
              msleep(5);
            }
            else {
LAB_0010ff90:
              if (iVar3 == 2) {
                _printk(&DAT_00118264,"smcinvoke_start_adci_thread",2);
              }
            }
            if (adci_rootEnv != (code *)0x0) {
              if (*(int *)(adci_rootEnv + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10ffd0);
                (*pcVar2)();
              }
              (*adci_rootEnv)(DAT_00118e50,0xffff,0,0);
            }
          }
          else {
            _printk(&DAT_00117d06,"smcinvoke_start_adci_thread",iVar3);
          }
          adci_rootEnv = (code *)0x0;
          DAT_00118e50 = 0;
        }
        else if (iVar3 == 1) {
          local_a0 = 0;
          uStack_98 = 0;
          local_a8 = 0;
          local_78 = 0;
          uStack_70 = 0;
          local_80 = 0;
          iVar3 = qtee_shmbridge_allocate_shm(0x1000,&local_a8);
          if (iVar3 == 0) {
            iVar3 = qtee_shmbridge_allocate_shm(0x1000,&local_80);
            if (iVar3 != 0) {
              puVar8 = &DAT_00117188;
              goto LAB_00110118;
            }
            while (mutex_lock(&object_postprocess_lock), puVar8 = g_object_postprocess,
                  (undefined **)g_object_postprocess != &g_object_postprocess) {
              uVar6 = __list_del_entry_valid(g_object_postprocess);
              if ((uVar6 & 1) != 0) {
                lVar7 = *(long *)puVar8;
                plVar1 = *(long **)(puVar8 + 8);
                *(long **)(lVar7 + 8) = plVar1;
                *plVar1 = lVar7;
              }
              *(undefined8 *)puVar8 = 0xdead000000000100;
              *(undefined8 *)(puVar8 + 8) = 0xdead000000000122;
              mutex_unlock(&object_postprocess_lock);
              if (puVar8 == (undefined *)0x0) {
                _printk(&DAT_0011621d,"smcinvoke_object_post_process",0);
              }
              else {
                do {
                  iVar3 = smcinvoke_release_tz_object
                                    (&local_a8,&local_80,*(undefined4 *)(puVar8 + 0x10),
                                     *(undefined4 *)(puVar8 + 0x14));
                } while (iVar3 == -0x10);
              }
              kfree_sensitive(puVar8);
            }
            mutex_unlock(&object_postprocess_lock);
          }
          else {
            puVar8 = &DAT_00116d8f;
LAB_00110118:
            _printk(puVar8,"smcinvoke_object_post_process");
          }
          qtee_shmbridge_free_shm(&local_a8);
          qtee_shmbridge_free_shm(&local_80);
        }
        else if (iVar3 == 0) {
          mutex_lock(&bridge_postprocess_lock);
          if ((undefined **)g_bridge_postprocess != &g_bridge_postprocess) {
            uVar5 = 0;
            uVar9 = 0;
            do {
              puVar8 = g_bridge_postprocess;
              if (g_bridge_postprocess == (undefined *)0x0) {
                _printk(&DAT_0011621d,"smcinvoke_shmbridge_post_process",0);
              }
              else {
                uVar5 = *(undefined8 *)(g_bridge_postprocess + 0x10);
                uVar9 = *(undefined8 *)(g_bridge_postprocess + 0x18);
              }
              uVar6 = __list_del_entry_valid(puVar8);
              if ((uVar6 & 1) != 0) {
                lVar7 = *(long *)puVar8;
                plVar1 = *(long **)(puVar8 + 8);
                *(long **)(lVar7 + 8) = plVar1;
                *plVar1 = lVar7;
              }
              *(undefined8 *)puVar8 = 0xdead000000000100;
              *(undefined8 *)(puVar8 + 8) = 0xdead000000000122;
              kfree_sensitive(puVar8);
              mutex_unlock(&bridge_postprocess_lock);
              if (puVar8 != (undefined *)0x0) {
                do {
                  while( true ) {
                    iVar3 = qtee_shmbridge_deregister(uVar5);
                    if (iVar3 == 0) {
                      dma_buf_put(uVar9);
                      goto LAB_0010fce0;
                    }
                    iVar4 = ___ratelimit(smcinvoke_shmbridge_post_process__rs,
                                         "smcinvoke_shmbridge_post_process");
                    if (iVar4 != 0) break;
                    if (iVar3 != -0x10) goto LAB_0010fce0;
                  }
                  _printk(&DAT_00117cd0,"smcinvoke_shmbridge_post_process",iVar3,uVar9,uVar5);
                } while (iVar3 == -0x10);
              }
LAB_0010fce0:
              mutex_lock(&bridge_postprocess_lock);
            } while ((undefined **)g_bridge_postprocess != &g_bridge_postprocess);
          }
          mutex_unlock(&bridge_postprocess_lock);
        }
        else {
          _printk(&DAT_00116d58,"smcinvoke_postprocess_kthread_func");
        }
        if (*param_1 == 2) break;
        param_1[1] = 0;
        uVar6 = kthread_should_stop();
      } while ((uVar6 & 1) == 0);
    }
    _printk(&DAT_00117052,"smcinvoke_postprocess_kthread_func",*param_1);
    uVar5 = 0;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// get_root_obj @ 0011058c size=212
// signature: undefined get_root_obj(void)
// callers: [smcinvoke_postprocess_kthread_func]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int get_root_obj(undefined8 *param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0xffffffff;
  iVar3 = get_root_fd(&local_3c);
  uVar2 = local_3c;
  if (iVar3 == 0) {
    puVar4 = (undefined4 *)kmalloc_trace(_kfree,0xdc0,8);
    if (puVar4 == (undefined4 *)0x0) {
      *param_1 = 0;
      param_1[1] = 0;
      close_fd(local_3c);
      iVar3 = -0xc;
    }
    else {
      iVar3 = 0;
      puVar4[1] = 1;
      *puVar4 = uVar2;
      *param_1 = invoke_over_smcinvoke;
      param_1[1] = puVar4;
    }
  }
  else {
    _printk(&DAT_001182af,iVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// get_client_env_object @ 00110664 size=704
// signature: undefined get_client_env_object(void)
// callers: [__qseecom_start_app]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int get_client_env_object(undefined8 *param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  ulong local_58 [5];
  
  lVar1 = sp_el0;
  local_58[4] = *(long *)(lVar1 + 0x638);
  local_58[0] = CONCAT44(local_58[0]._4_4_,0xffffffff);
  iVar3 = get_root_fd(local_58);
  if (iVar3 == 0) {
    uVar2 = (undefined4)local_58[0];
    puVar4 = (undefined4 *)kmalloc_trace(_kfree,0xdc0,8);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 1;
      *puVar4 = uVar2;
      local_58[2] = 0;
      local_58[3] = 0;
      local_58[0] = 0;
      local_58[1] = 0;
      iVar3 = invoke_over_smcinvoke(puVar4,5,local_58,0x1100);
      *param_1 = local_58[2];
      param_1[1] = local_58[3];
      if (iVar3 != 0) {
        if (iVar3 == -99) {
          _printk(&DAT_001166b5,0);
          msleep(5);
          local_58[2] = 0;
          local_58[3] = 0;
          local_58[0] = 0;
          local_58[1] = 0;
          iVar3 = invoke_over_smcinvoke(puVar4,5,local_58,0x1100);
          *param_1 = local_58[2];
          param_1[1] = local_58[3];
          if (iVar3 == 0) goto LAB_001106f8;
          if (iVar3 == -99) {
            _printk(&DAT_001166b5,1);
            msleep(5);
            local_58[2] = 0;
            local_58[3] = 0;
            local_58[0] = 0;
            local_58[1] = 0;
            iVar3 = invoke_over_smcinvoke(puVar4,5,local_58,0x1100);
            *param_1 = local_58[2];
            param_1[1] = local_58[3];
            if (iVar3 == 0) goto LAB_001106f8;
            if (iVar3 == -99) {
              _printk(&DAT_001166b5,2);
              msleep(5);
              local_58[2] = 0;
              local_58[3] = 0;
              local_58[0] = 0;
              local_58[1] = 0;
              iVar3 = invoke_over_smcinvoke(puVar4,5,local_58,0x1100);
              *param_1 = local_58[2];
              param_1[1] = local_58[3];
              if (iVar3 == 0) goto LAB_001106f8;
              if (iVar3 == -99) {
                _printk(&DAT_001166b5,3);
                msleep(5);
                local_58[2] = 0;
                local_58[3] = 0;
                local_58[0] = 0;
                local_58[1] = 0;
                iVar3 = invoke_over_smcinvoke(puVar4,5,local_58,0x1100);
                *param_1 = local_58[2];
                param_1[1] = local_58[3];
                if (iVar3 == 0) goto LAB_001106f8;
                if (iVar3 == -99) {
                  _printk(&DAT_001166b5,4);
                  msleep(5);
                  local_58[2] = 0;
                  local_58[3] = 0;
                  local_58[0] = 0;
                  local_58[1] = 0;
                  iVar3 = invoke_over_smcinvoke(puVar4,5,local_58,0x1100);
                  *param_1 = local_58[2];
                  param_1[1] = local_58[3];
                  if (iVar3 == 0) goto LAB_001106f8;
                  if (iVar3 == -99) {
                    _printk(&DAT_001166b5,5);
                    msleep(5);
                  }
                }
              }
            }
          }
        }
        _printk(&DAT_001182d2,iVar3);
      }
LAB_001106f8:
      invoke_over_smcinvoke(puVar4,0xffff,0,0);
      goto LAB_0011070c;
    }
    close_fd(local_58[0] & 0xffffffff);
    iVar3 = -0xc;
  }
  else {
    _printk(&DAT_001182af,iVar3);
  }
  _printk(&DAT_001178b5);
LAB_0011070c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58[4]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// get_qseecom_kernel_fun_ops @ 00110928 size=36
// signature: undefined get_qseecom_kernel_fun_ops(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

void get_qseecom_kernel_fun_ops(void)

{
  provide_qseecom_kernel_fun_ops(&qseecom_driver_ops);
  return;
}



//------------------------------------------------------------
// firmware_request_from_smcinvoke @ 00110950 size=828
// signature: undefined firmware_request_from_smcinvoke(void)
// callers: [__qseecom_start_app]
//------------------------------------------------------------

void * firmware_request_from_smcinvoke(char *param_1,long *param_2,long param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  uint uVar3;
  ushort uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  void *__dest;
  ulong uVar10;
  ulong uVar11;
  size_t sVar12;
  size_t *local_188;
  size_t *local_180;
  size_t *local_178;
  char acStack_170 [264];
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_180 = (size_t *)0x0;
  local_178 = (size_t *)0x0;
  local_188 = (size_t *)0x0;
  memset(acStack_170,0,0x105);
  snprintf(acStack_170,0x105,"%s.b00",param_1);
  iVar6 = firmware_request_nowarn(&local_180,acStack_170,class_dev);
  if (iVar6 != 0) {
    _printk(&DAT_00116335,acStack_170,iVar6);
    __dest = (void *)0x0;
    goto LAB_00110bc0;
  }
  sVar12 = local_180[1];
  if (*(char *)(sVar12 + 4) == '\x02') {
    uVar4 = *(ushort *)(sVar12 + 0x38);
    uVar11 = (ulong)uVar4;
    uVar10 = uVar11 * 8;
    lVar7 = __kmalloc(uVar10,0xdc0);
    if (lVar7 != 0) {
      if (1 < uVar4) {
        uVar9 = 8;
        lVar8 = *(long *)(sVar12 + 0x20) + 0x40;
        do {
          if (uVar10 <= uVar9) goto LAB_00110c84;
          puVar1 = (undefined8 *)(local_180[1] + lVar8);
          lVar8 = lVar8 + 0x38;
          *(undefined8 *)(lVar7 + uVar9) = *puVar1;
          uVar9 = uVar9 + 8;
        } while (uVar10 != uVar9);
      }
      goto LAB_00110ab0;
    }
LAB_00110b88:
    __dest = (void *)0x0;
  }
  else if (*(char *)(sVar12 + 4) == '\x01') {
    uVar4 = *(ushort *)(sVar12 + 0x2c);
    uVar11 = (ulong)uVar4;
    uVar10 = uVar11 * 8;
    lVar7 = __kmalloc(uVar10,0xdc0);
    if (lVar7 == 0) goto LAB_00110b88;
    if (1 < uVar4) {
      uVar3 = *(uint *)(sVar12 + 0x1c);
      uVar9 = 0;
      do {
        uVar2 = uVar9 + 8;
        if (uVar10 <= uVar2) {
LAB_00110c84:
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(1,0x110c88);
          (*pcVar5)();
        }
        *(ulong *)(lVar7 + uVar9 + 8) =
             (ulong)*(uint *)(local_180[1] + (ulong)uVar3 + 0x24 + uVar9 * 4);
        uVar9 = uVar2;
      } while (uVar10 - 8 != uVar2);
    }
LAB_00110ab0:
    uVar3 = (uint)uVar11 - 1;
    uVar10 = (ulong)uVar3;
    snprintf(acStack_170,0x105,"%s.b%02d",param_1,uVar3);
    iVar6 = firmware_request_nowarn(&local_188,acStack_170,class_dev);
    if (iVar6 == 0) {
      lVar8 = *(long *)(lVar7 + (long)(int)uVar3 * 8) + *local_188;
      *param_2 = lVar8;
      iVar6 = qtee_shmbridge_allocate_shm(lVar8,param_3);
      if (iVar6 == 0) {
        __dest = *(void **)(param_3 + 8);
        memcpy(__dest,(void *)local_180[1],*local_180);
        if ((uint)uVar11 < 3) {
          uVar10 = 1;
        }
        else {
          uVar11 = 1;
          do {
            snprintf(acStack_170,0x105,"%s.b%02d",param_1,(int)uVar11);
            iVar6 = firmware_request_nowarn(&local_178,acStack_170,class_dev);
            if (iVar6 != 0) {
              _printk(&DAT_00117386,acStack_170);
              qtee_shmbridge_free_shm(param_3);
              __dest = (void *)0x0;
              goto LAB_00110ba8;
            }
            memcpy((void *)((long)__dest + *(long *)(lVar7 + uVar11 * 8)),(void *)local_178[1],
                   *local_178);
            release_firmware(local_178);
            uVar11 = uVar11 + 1;
            local_178 = (size_t *)0x0;
          } while (uVar10 != uVar11);
        }
        memcpy((void *)((long)__dest + *(long *)(lVar7 + uVar10 * 8)),(void *)local_188[1],
               *local_188);
      }
      else {
        _printk(&DAT_0011634f,*param_2);
        __dest = (void *)0x0;
      }
LAB_00110ba8:
      release_firmware(local_188);
    }
    else {
      _printk(&DAT_00117386,acStack_170);
      __dest = (void *)0x0;
    }
  }
  else {
    _printk(&DAT_001182fd,param_1);
    lVar7 = 0;
    __dest = (void *)0x0;
  }
  release_firmware(local_180);
  kfree(lVar7);
LAB_00110bc0:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __dest;
}



//------------------------------------------------------------
// invoke_over_smcinvoke @ 00110c90 size=1316
// signature: undefined invoke_over_smcinvoke(void)
// callers: [get_client_env_object]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void invoke_over_smcinvoke(undefined4 *param_1,uint param_2,long param_3,uint param_4)

{
  undefined8 *puVar1;
  uint *puVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  long lVar10;
  int *piVar11;
  undefined8 uVar12;
  uint uVar13;
  long *plVar14;
  undefined8 *puVar15;
  code *pcVar16;
  undefined8 *puVar17;
  ulong uVar18;
  ulong uVar19;
  ulong *puVar20;
  ulong uVar21;
  uint uVar22;
  ulong uVar23;
  ulong uVar24;
  uint local_88;
  uint uStack_84;
  undefined8 local_80;
  long local_78;
  undefined8 uStack_70;
  long local_68;
  
  uVar3 = param_4 & 0xf;
  uVar24 = (ulong)uVar3;
  uVar6 = param_4 >> 4 & 0xf;
  uVar7 = param_4 >> 8 & 0xf;
  uVar22 = uVar6 + uVar3;
  uVar19 = (ulong)uVar22;
  lVar10 = sp_el0;
  uVar13 = uVar22 + uVar7;
  uVar21 = (ulong)uVar13;
  uVar8 = param_4 >> 0xc & 0xf;
  local_68 = *(long *)(lVar10 + 0x638);
  uVar23 = (ulong)(uVar13 + uVar8);
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if (uVar8 != 0) {
    uVar18 = uVar23;
    if (uVar23 < uVar21 + 1) {
      uVar18 = uVar21 + 1;
    }
    memset((void *)(param_3 + uVar21 * 0x10),0,(uVar18 - uVar21) * 0x10);
  }
  if ((param_2 >> 0xf & 1) == 0) {
    lVar10 = __kmalloc(uVar23 * 0x18,0xdc0);
    if (lVar10 == 0) {
      uVar22 = 0xffffff9f;
    }
    else {
      local_80 = CONCAT44(0x18,(uint)local_80);
      if (uVar22 != 0) {
        puVar15 = (undefined8 *)(lVar10 + 8);
        puVar17 = (undefined8 *)(param_3 + 8);
        uVar18 = uVar19;
        do {
          puVar1 = puVar17 + -1;
          uVar12 = *puVar17;
          uVar18 = uVar18 - 1;
          puVar17 = puVar17 + 2;
          puVar15[-1] = *puVar1;
          *puVar15 = uVar12;
          puVar15 = puVar15 + 3;
        } while (uVar18 != 0);
      }
      local_88 = param_2;
      uStack_84 = param_4;
      local_78 = lVar10;
      if (uVar7 != 0) {
        puVar15 = (undefined8 *)(param_3 + uVar19 * 0x10 + 8);
        plVar14 = (long *)(lVar10 + uVar19 * 0x18);
        uVar18 = uVar19;
        do {
          if ((code *)puVar15[-1] != (code *)0x0) {
            if ((code *)puVar15[-1] == invoke_over_smcinvoke) {
              if ((int *)*puVar15 != (int *)0x0) {
                iVar9 = *(int *)*puVar15;
                goto LAB_00110db4;
              }
              _printk(&DAT_00117576,0);
            }
            else {
              _printk(&DAT_0011659d);
            }
            _printk(&DAT_00116683,uVar18);
            uVar22 = 0xffffffa4;
            goto LAB_00110e78;
          }
          iVar9 = -1;
LAB_00110db4:
          uVar18 = uVar18 + 1;
          puVar15 = puVar15 + 2;
          *plVar14 = (long)iVar9;
          plVar14 = plVar14 + 3;
        } while (uVar18 < uVar21);
      }
      if (uVar8 != 0) {
        puVar15 = (undefined8 *)(lVar10 + (ulong)uVar13 * 0x18);
        uVar18 = uVar21;
        do {
          uVar18 = uVar18 + 1;
          *puVar15 = 0xffffffffffffffff;
          puVar15 = puVar15 + 3;
        } while (uVar18 < uVar23);
      }
      iVar9 = process_invoke_request_from_kernel_client(*param_1,&local_88);
      if (iVar9 == 0) {
        if ((uint)local_80 == 0) {
          if (uVar6 != 0) {
            puVar15 = (undefined8 *)(param_3 + uVar24 * 0x10 + 8);
            puVar17 = (undefined8 *)(local_78 + (ulong)uVar3 * 0x18 + 8);
            do {
              uVar24 = uVar24 + 1;
              *puVar15 = *puVar17;
              puVar15 = puVar15 + 2;
              puVar17 = puVar17 + 3;
            } while (uVar24 < uVar19);
          }
          if (uVar8 != 0) {
            puVar20 = (ulong *)(local_78 + (ulong)uVar13 * 0x18);
            puVar15 = (undefined8 *)(param_3 + uVar21 * 0x10);
            uVar24 = uVar21;
            do {
              iVar9 = (int)*puVar20;
              if (iVar9 != -1) {
                if (iVar9 < 0) {
                  _printk(&DAT_00117d4f,*puVar20 & 0xffffffff);
                }
                else {
                  piVar11 = (int *)kmalloc_trace(_kfree,0xdc0,8);
                  if (piVar11 != (int *)0x0) {
                    piVar11[1] = 1;
                    *piVar11 = iVar9;
                    *puVar15 = invoke_over_smcinvoke;
                    puVar15[1] = piVar11;
                    goto LAB_00110f60;
                  }
                  *puVar15 = 0;
                  puVar15[1] = 0;
                }
                _printk(&DAT_00116ad3,uVar24,(int)*puVar20);
                uVar22 = 0xffffffa4;
                puVar15 = (undefined8 *)(param_3 + uVar21 * 0x10);
                do {
                  pcVar16 = (code *)*puVar15;
                  if (pcVar16 != (code *)0x0) {
                    if (*(int *)(pcVar16 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x11112c);
                      (*pcVar16)();
                    }
                    (*pcVar16)(puVar15[1],0xffff,0,0);
                  }
                  uVar21 = uVar21 + 1;
                  *puVar15 = 0;
                  puVar15[1] = 0;
                  puVar15 = puVar15 + 2;
                } while (uVar21 < uVar23);
                goto LAB_00110e78;
              }
              pcVar16 = (code *)*puVar15;
              if (pcVar16 != (code *)0x0) {
                if (*(int *)(pcVar16 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                  pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x110fd8);
                  (*pcVar16)();
                }
                (*pcVar16)(puVar15[1],0xffff,0,0);
              }
              *puVar15 = 0;
              puVar15[1] = 0;
LAB_00110f60:
              uVar24 = uVar24 + 1;
              puVar15 = puVar15 + 2;
              puVar20 = puVar20 + 3;
            } while (uVar24 < uVar23);
          }
        }
        uVar22 = 0;
      }
      else {
        _printk(&DAT_0011653f,iVar9,local_80 & 0xffffffff,param_1,*param_1,param_2,param_4);
        if (uVar8 != 0) {
          puVar20 = (ulong *)(lVar10 + (ulong)uVar13 * 0x18);
          do {
            uVar24 = *puVar20;
            if (-1 < (long)uVar24) {
              _printk(&DAT_001179dd,uVar21,uVar24);
              close_fd(uVar24 & 0xffffffff);
            }
            uVar21 = uVar21 + 1;
            puVar20 = puVar20 + 3;
          } while (uVar21 < uVar23);
        }
        uVar13 = 0xffffff9f;
        if (iVar9 != -0xc) {
          uVar13 = 0xffffffa0;
        }
        uVar22 = 0xffffff9d;
        if (iVar9 != -0x10) {
          uVar22 = uVar13;
        }
      }
LAB_00110e78:
      kfree(lVar10);
      uVar22 = (uint)local_80 | uVar22;
    }
    goto LAB_00110ec0;
  }
  if ((param_2 & 0xffff) == 0xffff) {
    piVar11 = param_1 + 1;
    Hint_Prefetch(piVar11,2,0,1);
    do {
      iVar9 = *piVar11;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar11,0x10);
      if (bVar5) {
        *piVar11 = iVar9 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar9 == 1) {
      DataMemoryBarrier(2,1);
      lVar10 = sp_el0;
      _printk(&DAT_001179f8,"tzobject_delete",*param_1,param_1[1],*(undefined8 *)(lVar10 + 0x878));
      smcinvoke_release_from_kernel_client(*param_1);
      close_fd(*param_1);
      kfree(param_1);
      uVar22 = 0;
      goto LAB_00110ec0;
    }
    if (0 < iVar9) {
LAB_00110eb4:
      uVar22 = 0;
      goto LAB_00110ec0;
    }
    uVar12 = 3;
  }
  else {
    if ((param_2 & 0xffff) != 0xfffe) {
      uVar22 = 0xffffff9e;
      goto LAB_00110ec0;
    }
    puVar2 = param_1 + 1;
    Hint_Prefetch(puVar2,2,0,1);
    do {
      uVar22 = *puVar2;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar5) {
        *puVar2 = uVar22 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (uVar22 == 0) {
      uVar12 = 2;
    }
    else {
      if (-1 < (int)(uVar22 + 1 | uVar22)) goto LAB_00110eb4;
      uVar12 = 1;
    }
  }
  refcount_warn_saturate(param_1 + 1,uVar12);
  uVar22 = 0;
LAB_00110ec0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar22);
  }
  return;
}



//------------------------------------------------------------
// __qseecom_send_command @ 001111d4 size=256
// signature: undefined __qseecom_send_command(void)
// callers: []
//------------------------------------------------------------

void __qseecom_send_command(long param_1,long param_2,uint param_3,long param_4,uint param_5)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  uint local_bc;
  long local_b8;
  ulong uStack_b0;
  long local_a8;
  ulong uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  uint *local_88;
  undefined8 uStack_80;
  long local_78;
  ulong uStack_70;
  long local_68;
  ulong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  if ((((param_5 == 0) || (param_3 == 0)) || (param_1 == 0)) || ((param_2 == 0 || (param_4 == 0))))
  {
    _printk(&DAT_0011765f,"__qseecom_send_command");
    uVar3 = 0xffffffea;
  }
  else {
    uStack_b0 = (ulong)param_3;
    uStack_a0 = (ulong)param_5;
    local_98 = 0;
    uStack_90 = 0;
    local_88 = &local_bc;
    local_bc = (uint)(*(char *)(param_1 + 0x30) == '\x02');
    local_58 = 0;
    uStack_50 = 0;
    uStack_80 = 4;
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    uStack_30 = 0;
    local_28 = 0;
    uStack_20 = 0;
    local_b8 = param_2;
    local_a8 = param_4;
    local_78 = param_2;
    uStack_70 = uStack_b0;
    local_68 = param_4;
    uStack_60 = uStack_a0;
    if (*(int *)(*(code **)(param_1 + 0x58) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x11128c);
      (*pcVar2)();
    }
    uVar3 = (**(code **)(param_1 + 0x58))(*(undefined8 *)(param_1 + 0x60),0,&local_b8,0x424);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __qseecom_start_app @ 001112d8 size=1080
// signature: undefined __qseecom_start_app(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __qseecom_start_app(long *param_1,char *param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  size_t sVar5;
  char *pcVar6;
  undefined8 uVar7;
  char local_1d4 [4];
  undefined8 local_1d0;
  undefined8 local_1c8;
  undefined8 uStack_1c0;
  size_t local_1b8;
  char **local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
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
  char *local_b0;
  size_t sStack_a8;
  char *local_a0;
  size_t sStack_98;
  char ***local_90;
  undefined8 local_88;
  long local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar3 = sp_el0;
  local_70 = *(long *)(lVar3 + 0x638);
  _printk(&DAT_001172c8,"__qseecom_start_app",param_2,param_3);
  if ((param_1 == (long *)0x0) || (param_2 == (char *)0x0)) {
    _printk(&DAT_001178d1);
  }
  else {
    lVar3 = kmalloc_trace(_fget,0xdc0,0x68);
    if (lVar3 == 0) {
      uVar4 = 0xfffffff4;
      goto LAB_00111354;
    }
    iVar2 = get_client_env_object(lVar3 + 0x38);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(lVar3 + 0x38);
      uVar7 = *(undefined8 *)(lVar3 + 0x40);
      local_1b0 = &local_b0;
      local_1a0 = 0;
      uStack_198 = 0;
      local_b0 = (char *)CONCAT44(local_b0._4_4_,0x7a);
      uStack_1a8 = 4;
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8238,0x1113f0);
        (*pcVar1)();
      }
      iVar2 = (*pcVar1)(uVar7,0,&local_1b0,0x1001);
      *(undefined8 *)(lVar3 + 0x48) = local_1a0;
      *(undefined8 *)(lVar3 + 0x50) = uStack_198;
      if (iVar2 == 0) {
        local_1b8 = 0;
        local_160 = 0;
        uStack_158 = 0;
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
        local_140 = 0;
        uStack_138 = 0;
        local_150 = 0;
        uStack_148 = 0;
        local_170 = 0;
        uStack_168 = 0;
        local_180 = 0;
        uStack_178 = 0;
        local_190 = 0;
        uStack_188 = 0;
        local_1a0 = 0;
        uStack_198 = 0;
        local_1b0 = (char **)0x0;
        uStack_1a8 = 0;
        local_1c8 = 0;
        uStack_1c0 = 0;
        local_1d0 = 0;
        local_1d4[0] = '\0';
        local_1d4[1] = '\0';
        local_1d4[2] = '\0';
        local_1d4[3] = '\0';
        sVar5 = strnlen(param_2,0x100);
        if (sVar5 == 0x100) {
          sVar5 = strnlen(param_2,0x100);
          if (sVar5 == 0xffffffffffffffff) goto LAB_00111704;
          _printk(&DAT_00117dd7,param_2,sVar5);
          iVar2 = -0x16;
          goto LAB_00111640;
        }
        if (sVar5 == 0xffffffffffffffff) {
LAB_00111704:
          fortify_panic("strnlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        sStack_a8 = strlen(param_2);
        pcVar1 = *(code **)(lVar3 + 0x48);
        uVar7 = *(undefined8 *)(lVar3 + 0x50);
        local_a0 = local_1d4;
        sStack_98 = 4;
        local_90 = (char ***)0x0;
        local_88 = 0;
        local_b0 = param_2;
        if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x823a,0x1114b8);
          (*pcVar1)();
        }
        iVar2 = (*pcVar1)(uVar7,2,&local_b0,0x1011);
        *(long *)(lVar3 + 0x58) = (long)local_90;
        *(undefined8 *)(lVar3 + 0x60) = local_88;
        if (iVar2 == 0) {
          _printk(&DAT_0011683e,param_2);
LAB_001114dc:
          uVar4 = qtee_shmbridge_allocate_shm(param_3,lVar3 + 0x18);
          if ((int)uVar4 == 0) {
            uVar7 = *(undefined8 *)(lVar3 + 0x20);
            *(undefined4 *)(lVar3 + 0x10) = param_3;
            *param_1 = lVar3;
            *(undefined8 *)(lVar3 + 8) = uVar7;
            goto LAB_00111354;
          }
          _printk(&DAT_00117ae3,uVar4 & 0xffffffff);
          if (*(int *)(*(code **)(lVar3 + 0x58) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1116f8);
            (*pcVar1)();
          }
          (**(code **)(lVar3 + 0x58))(*(undefined8 *)(lVar3 + 0x60),0xffff,0,0);
        }
        else {
          pcVar6 = (char *)firmware_request_from_smcinvoke(param_2,&local_1b8,&local_1d0);
          sVar5 = local_1b8;
          if (pcVar6 == (char *)0x0) {
            _printk(&DAT_001170a0);
            iVar2 = -0x16;
          }
          else {
            sStack_98 = strlen(param_2);
            local_90 = &local_1b0;
            sStack_a8 = sVar5;
            local_88 = 0x100;
            local_80 = 0;
            uStack_78 = 0;
            local_b0 = pcVar6;
            local_a0 = param_2;
            if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x823a,0x1115d8);
              (*pcVar1)();
            }
            iVar2 = (*pcVar1)(uVar7,1,&local_b0,0x1012);
            *(long *)(lVar3 + 0x58) = local_80;
            *(undefined8 *)(lVar3 + 0x60) = uStack_78;
            if (iVar2 == 0) {
              *(char *)(lVar3 + 0x30) = pcVar6[4];
              _printk(&DAT_001169c5,"load_app",0x177,param_2,&local_1b0,local_88);
              qtee_shmbridge_free_shm(&local_1d0);
              goto LAB_001114dc;
            }
            _printk(&DAT_00117b12,param_2,iVar2);
            qtee_shmbridge_free_shm(&local_1d0);
          }
LAB_00111640:
          _printk(&DAT_00117a26,param_2,iVar2);
        }
        if (*(int *)(*(code **)(lVar3 + 0x48) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11167c);
          (*pcVar1)();
        }
        (**(code **)(lVar3 + 0x48))(*(undefined8 *)(lVar3 + 0x50),0xffff,0,0);
        pcVar1 = *(code **)(lVar3 + 0x38);
        uVar7 = *(undefined8 *)(lVar3 + 0x40);
      }
      else {
        _printk(&DAT_0011779f,param_2,iVar2);
      }
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8238,0x1116ac);
        (*pcVar1)();
      }
      (*pcVar1)(uVar7,0xffff,0,0);
    }
    else {
      _printk(&DAT_00116376,param_2,iVar2);
    }
    kfree(lVar3);
  }
  uVar4 = 0xffffffea;
LAB_00111354:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// __qseecom_shutdown_app @ 00111714 size=224
// signature: undefined __qseecom_shutdown_app(void)
// callers: []
//------------------------------------------------------------

undefined8 __qseecom_shutdown_app(long *param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((param_1 == (long *)0x0) || (lVar3 = *param_1, lVar3 == 0)) {
    _printk(&DAT_00117a49);
    uVar2 = 0xffffffea;
  }
  else {
    qtee_shmbridge_free_shm(lVar3 + 0x18);
    if (*(int *)(*(code **)(lVar3 + 0x58) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x111764);
      (*pcVar1)();
    }
    (**(code **)(lVar3 + 0x58))(*(undefined8 *)(lVar3 + 0x60),0xffff,0,0);
    if (*(int *)(*(code **)(lVar3 + 0x48) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x111790);
      (*pcVar1)();
    }
    (**(code **)(lVar3 + 0x48))(*(undefined8 *)(lVar3 + 0x50),0xffff,0,0);
    if (*(int *)(*(code **)(lVar3 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1117bc);
      (*pcVar1)();
    }
    (**(code **)(lVar3 + 0x38))(*(undefined8 *)(lVar3 + 0x40),0xffff,0,0);
    kfree(lVar3);
    uVar2 = 0;
    *param_1 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// __qseecom_process_listener_from_smcinvoke @ 001117f8 size=8
// signature: undefined __qseecom_process_listener_from_smcinvoke(void)
// callers: []
//------------------------------------------------------------

undefined8 __qseecom_process_listener_from_smcinvoke(void)

{
  return 0xffffffa1;
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0011c000 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_process_invoke_req_result, trace_event_raw_event_marshal_in_tzcb_req_handle, trace_event_raw_event_process_log_info, trace_event_raw_event_process_accept_req_ret, trace_event_raw_event_process_tzcb_req_wait, trace_event_raw_event_marshal_out_tzcb_req, trace_event_raw_event_marshal_in_tzcb_req_fd, trace_event_raw_event_process_tzcb_req_handle, trace_event_raw_event_smcinvoke_create_bridge, trace_event_raw_event_release_mem_obj_locked, trace_event_raw_event_marshal_out_invoke_req, trace_event_raw_event_smcinvoke_release_from_kernel_client, trace_event_raw_event_put_pending_cbobj_locked, trace_event_raw_event_process_tzcb_req_result, trace_event_raw_event_prepare_send_scm_msg, trace_event_raw_event_invoke_cmd_handler, trace_event_raw_event_smcinvoke_ioctl, trace_event_raw_event_status, trace_event_raw_event_process_invoke_req_tzhandle, trace_event_raw_event_marshal_in_invoke_req, trace_event_raw_event_process_invoke_request_from_kernel_client, trace_event_raw_event_process_accept_req_placed, trace_event_raw_event_smcinvoke_release_filp, trace_event_raw_event_smcinvoke_release, trace_event_raw_event_process_accept_req_has_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0011c008 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_process_invoke_req_result, trace_event_raw_event_marshal_in_tzcb_req_handle, trace_event_raw_event_process_log_info, trace_event_raw_event_process_accept_req_ret, trace_event_raw_event_process_tzcb_req_wait, trace_event_raw_event_marshal_out_tzcb_req, trace_event_raw_event_marshal_in_tzcb_req_fd, trace_event_raw_event_process_tzcb_req_handle, trace_event_raw_event_smcinvoke_create_bridge, trace_event_raw_event_release_mem_obj_locked, trace_event_raw_event_marshal_out_invoke_req, trace_event_raw_event_smcinvoke_release_from_kernel_client, trace_event_raw_event_put_pending_cbobj_locked, trace_event_raw_event_process_tzcb_req_result, trace_event_raw_event_prepare_send_scm_msg, trace_event_raw_event_invoke_cmd_handler, trace_event_raw_event_smcinvoke_ioctl, trace_event_raw_event_status, trace_event_raw_event_process_invoke_req_tzhandle, trace_event_raw_event_marshal_in_invoke_req, trace_event_raw_event_process_invoke_request_from_kernel_client, trace_event_raw_event_process_accept_req_placed, trace_event_raw_event_smcinvoke_release_filp, trace_event_raw_event_smcinvoke_release, trace_event_raw_event_process_accept_req_has_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0011c010 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_process_invoke_req_result, trace_event_raw_event_marshal_in_tzcb_req_handle, trace_event_raw_event_process_log_info, trace_event_raw_event_process_accept_req_ret, trace_event_raw_event_process_tzcb_req_wait, trace_event_raw_event_marshal_out_tzcb_req, trace_event_raw_event_marshal_in_tzcb_req_fd, trace_event_raw_event_process_tzcb_req_handle, trace_event_raw_event_smcinvoke_create_bridge, trace_event_raw_event_release_mem_obj_locked, trace_event_raw_event_marshal_out_invoke_req, trace_event_raw_event_smcinvoke_release_from_kernel_client, trace_event_raw_event_put_pending_cbobj_locked, trace_event_raw_event_process_tzcb_req_result, trace_event_raw_event_prepare_send_scm_msg, trace_event_raw_event_invoke_cmd_handler, trace_event_raw_event_smcinvoke_ioctl, trace_event_raw_event_status, trace_event_raw_event_process_invoke_req_tzhandle, trace_event_raw_event_marshal_in_invoke_req, trace_event_raw_event_process_invoke_request_from_kernel_client, trace_event_raw_event_process_accept_req_placed, trace_event_raw_event_smcinvoke_release_filp, trace_event_raw_event_smcinvoke_release, trace_event_raw_event_process_accept_req_has_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0011c018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_process_tzcb_req_wait, trace_event_raw_event_marshal_in_tzcb_req_handle, perf_trace_process_accept_req_placed, prepare_send_scm_msg, trace_event_raw_event_marshal_out_tzcb_req, perf_trace_invoke_cmd_handler, get_client_env_object, trace_event_raw_event_process_tzcb_req_handle, perf_trace_smcinvoke_create_bridge, trace_event_raw_event_marshal_out_invoke_req, perf_trace_process_log_info, trace_event_raw_event_put_pending_cbobj_locked, perf_trace_smcinvoke_release, trace_event_raw_event_smcinvoke_ioctl, perf_trace_marshal_out_tzcb_req, trace_event_raw_event_status, perf_trace_process_invoke_request_from_kernel_client, perf_trace_process_accept_req_ret, perf_trace_prepare_send_scm_msg, get_root_obj, trace_event_raw_event_smcinvoke_release_filp, perf_trace_smcinvoke_release_filp, smcinvoke_map_mem_region_locked, trace_event_raw_event_process_invoke_req_result, trace_event_raw_event_process_log_info, perf_trace_process_tzcb_req_result, perf_trace_marshal_in_tzcb_req_handle, marshal_out_invoke_req, __qseecom_start_app, perf_trace_marshal_in_invoke_req, trace_event_raw_event_process_accept_req_ret, trace_event_raw_event_process_tzcb_req_wait, trace_event_raw_event_marshal_in_tzcb_req_fd, perf_trace_process_accept_req_has_response, trace_event_raw_event_smcinvoke_create_bridge, process_tzcb_req, trace_event_raw_event_release_mem_obj_locked, perf_trace_marshal_out_invoke_req, trace_event_raw_event_smcinvoke_release_from_kernel_client, trace_event_raw_event_process_tzcb_req_result, perf_trace_status, smcinvoke_ioctl, trace_event_raw_event_prepare_send_scm_msg, trace_event_raw_event_invoke_cmd_handler, perf_trace_smcinvoke_ioctl, trace_event_raw_event_process_invoke_req_tzhandle, smcinvoke_release_tz_object, perf_trace_smcinvoke_release_from_kernel_client, smcinvoke_postprocess_kthread_func, trace_event_raw_event_marshal_in_invoke_req, trace_event_raw_event_process_invoke_request_from_kernel_client, perf_trace_process_invoke_req_result, perf_trace_marshal_in_tzcb_req_fd, __qseecom_send_command, trace_event_raw_event_process_accept_req_placed, perf_trace_process_invoke_req_tzhandle, perf_trace_put_pending_cbobj_locked, trace_event_raw_event_smcinvoke_release, smcinvoke_release_filp, firmware_request_from_smcinvoke, invoke_over_smcinvoke, perf_trace_release_mem_obj_locked, perf_trace_process_tzcb_req_handle, trace_event_raw_event_process_accept_req_has_response, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0011c020 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_process_tzcb_req_wait, perf_trace_process_accept_req_placed, perf_trace_process_tzcb_req_result, perf_trace_marshal_in_tzcb_req_handle, perf_trace_marshal_in_invoke_req, perf_trace_process_accept_req_has_response, perf_trace_invoke_cmd_handler, perf_trace_smcinvoke_create_bridge, perf_trace_marshal_out_invoke_req, perf_trace_process_log_info, perf_trace_status, perf_trace_smcinvoke_release, perf_trace_smcinvoke_ioctl, perf_trace_marshal_out_tzcb_req, perf_trace_process_invoke_request_from_kernel_client, perf_trace_process_accept_req_ret, perf_trace_smcinvoke_release_from_kernel_client, perf_trace_process_invoke_req_result, perf_trace_prepare_send_scm_msg, perf_trace_marshal_in_tzcb_req_fd, perf_trace_process_invoke_req_tzhandle, perf_trace_put_pending_cbobj_locked, perf_trace_smcinvoke_release_filp, perf_trace_release_mem_obj_locked, perf_trace_process_tzcb_req_handle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0011c028 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_process_tzcb_req_wait, perf_trace_process_accept_req_placed, perf_trace_process_tzcb_req_result, perf_trace_marshal_in_tzcb_req_handle, perf_trace_marshal_in_invoke_req, perf_trace_process_accept_req_has_response, perf_trace_invoke_cmd_handler, perf_trace_smcinvoke_create_bridge, perf_trace_marshal_out_invoke_req, perf_trace_process_log_info, perf_trace_status, perf_trace_smcinvoke_release, perf_trace_smcinvoke_ioctl, perf_trace_marshal_out_tzcb_req, perf_trace_process_invoke_request_from_kernel_client, perf_trace_process_accept_req_ret, perf_trace_smcinvoke_release_from_kernel_client, perf_trace_process_invoke_req_result, perf_trace_prepare_send_scm_msg, perf_trace_marshal_in_tzcb_req_fd, perf_trace_process_invoke_req_tzhandle, perf_trace_put_pending_cbobj_locked, perf_trace_smcinvoke_release_filp, perf_trace_release_mem_obj_locked, perf_trace_process_tzcb_req_handle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0011c030 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_process_log_info, trace_event_raw_event_status, __qseecom_start_app, perf_trace_process_log_info, perf_trace_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0011c038 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_process_log_info, trace_event_raw_event_status, perf_trace_process_log_info, perf_trace_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0011c040 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_process_accept_req_has_response, __bpf_trace_release_mem_obj_locked, __bpf_trace_prepare_send_scm_msg, __bpf_trace_smcinvoke_create_bridge, __bpf_trace_process_accept_req_placed, __bpf_trace_put_pending_cbobj_locked, __bpf_trace_status, __bpf_trace_smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0011c048 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_smcinvoke_release_filp, __bpf_trace_marshal_in_invoke_req, __bpf_trace_marshal_out_invoke_req, __bpf_trace_marshal_out_tzcb_req, __bpf_trace_marshal_in_tzcb_req_fd, __bpf_trace_smcinvoke_release, __bpf_trace_invoke_cmd_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 0011c050 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_process_tzcb_req_handle, __bpf_trace_process_invoke_req_tzhandle, __bpf_trace_process_invoke_request_from_kernel_client, __bpf_trace_smcinvoke_release_from_kernel_client, __bpf_trace_process_accept_req_ret, __bpf_trace_process_log_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run8 @ 0011c058 size=1
// signature: undefined bpf_trace_run8(void)
// callers: [__bpf_trace_process_tzcb_req_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 0011c060 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_process_tzcb_req_result, __bpf_trace_marshal_in_tzcb_req_handle, __bpf_trace_process_invoke_req_result]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0011c070 size=1
// signature: undefined kmalloc_trace(void)
// callers: [get_client_env_object, process_tzcb_req, smcinvoke_release_filp, free_mem_obj_locked, get_pending_cbobj_locked, __qseecom_start_app, invoke_over_smcinvoke, get_fd_for_obj, smcinvoke_open, get_tzhandle_from_uhandle, smcinvoke_ioctl, get_root_obj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_unused_fd_flags @ 0011c078 size=1
// signature: undefined get_unused_fd_flags(void)
// callers: [get_fd_for_obj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_unused_fd_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// anon_inode_getfile @ 0011c080 size=1
// signature: undefined anon_inode_getfile(void)
// callers: [get_fd_for_obj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void anon_inode_getfile(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fd_install @ 0011c088 size=1
// signature: undefined fd_install(void)
// callers: [get_fd_for_obj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fd_install(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_unused_fd @ 0011c090 size=1
// signature: undefined put_unused_fd(void)
// callers: [get_fd_for_obj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_unused_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0011c098 size=1
// signature: undefined kfree(void)
// callers: [release_tzhandle_locked, get_pending_cbobj_locked, __qseecom_start_app, release_cb_server, process_tzcb_req, smcinvoke_release_filp, firmware_request_from_smcinvoke, free_mem_obj_locked, smcinvoke_map_mem_region_locked, __qseecom_shutdown_app, invoke_over_smcinvoke, get_fd_for_obj, process_invoke_req, get_tzhandle_from_uhandle, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fget @ 0011c0a0 size=1
// signature: undefined fget(void)
// callers: [get_tzhandle_from_uhandle, smcinvoke_release_from_kernel_client, process_invoke_request_from_kernel_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fget(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fput @ 0011c0a8 size=1
// signature: undefined fput(void)
// callers: [release_filp, get_tzhandle_from_uhandle, smcinvoke_release_from_kernel_client, process_invoke_request_from_kernel_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0011c0b0 size=1
// signature: undefined _printk(void)
// callers: [marshal_out_invoke_req, __qseecom_start_app, prepare_send_scm_msg, get_client_env_object, process_tzcb_req, free_mem_obj_locked, __qseecom_shutdown_app, smcinvoke_probe, get_tzhandle_from_uhandle, smcinvoke_ioctl, release_tzhandle_locked, smcinvoke_release_tz_object, get_pending_cbobj_locked, smcinvoke_postprocess_kthread_func, get_root_obj, __qseecom_send_command, add_mem_obj_info_to_async_side_channel_locked, smcinvoke_destroy_kthreads, smcinvoke_release_filp, firmware_request_from_smcinvoke, smcinvoke_map_mem_region_locked, invoke_over_smcinvoke, smcinvoke_suspend, process_invoke_req, smcinvoke_release_from_kernel_client, process_invoke_request_from_kernel_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0011c0e0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0011c0e8 size=1
// signature: undefined __kmalloc(void)
// callers: [firmware_request_from_smcinvoke, invoke_over_smcinvoke, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0011c0f0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [process_tzcb_req, firmware_request_from_smcinvoke, marshal_out_invoke_req, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0011c0f8 size=1
// signature: undefined __check_object_size(void)
// callers: [marshal_out_invoke_req, process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_allocate_shm @ 0011c100 size=1
// signature: undefined qtee_shmbridge_allocate_shm(void)
// callers: [smcinvoke_release_filp, firmware_request_from_smcinvoke, smcinvoke_postprocess_kthread_func, __qseecom_start_app, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_allocate_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0011c108 size=1
// signature: undefined mutex_lock(void)
// callers: [get_uhandle_from_tzhandle, process_tzcb_req, smcinvoke_release_filp, free_mem_obj_locked, smcinvoke_map_mem_region_locked, smcinvoke_postprocess_kthread_func, smcinvoke_suspend, process_invoke_req, get_tzhandle_from_uhandle, smcinvoke_ioctl, release_cb_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0011c110 size=1
// signature: undefined mutex_unlock(void)
// callers: [get_uhandle_from_tzhandle, process_tzcb_req, smcinvoke_release_filp, free_mem_obj_locked, smcinvoke_map_mem_region_locked, smcinvoke_postprocess_kthread_func, smcinvoke_suspend, process_invoke_req, get_tzhandle_from_uhandle, smcinvoke_ioctl, release_cb_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0011c120 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [smcinvoke_release_tz_object, firmware_request_from_smcinvoke, invoke_over_smcinvoke, prepare_send_scm_msg, process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0011c128 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [marshal_out_invoke_req, process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0011c130 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [release_tzhandle_locked, free_mem_obj_locked, smcinvoke_postprocess_kthread_func, process_invoke_req, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_free_shm @ 0011c138 size=1
// signature: undefined qtee_shmbridge_free_shm(void)
// callers: [smcinvoke_release_filp, firmware_request_from_smcinvoke, smcinvoke_postprocess_kthread_func, __qseecom_start_app, __qseecom_shutdown_app, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_free_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_unmap_attachment @ 0011c140 size=1
// signature: undefined dma_buf_unmap_attachment(void)
// callers: [release_tzhandle_locked, smcinvoke_map_mem_region_locked, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_unmap_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_detach @ 0011c148 size=1
// signature: undefined dma_buf_detach(void)
// callers: [release_tzhandle_locked, smcinvoke_map_mem_region_locked, process_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0011c150 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [process_tzcb_req, release_tzhandle_locked, get_pending_cbobj_locked, smcinvoke_map_mem_region_locked, invoke_over_smcinvoke, process_invoke_req, smcinvoke_ioctl, release_cb_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0011c158 size=1
// signature: undefined __list_add_valid(void)
// callers: [smcinvoke_release_filp, free_mem_obj_locked, get_pending_cbobj_locked, get_tzhandle_from_uhandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0011c160 size=1
// signature: undefined __wake_up(void)
// callers: [process_tzcb_req, smcinvoke_release_filp, free_mem_obj_locked, smcinvoke_probe, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0011c168 size=1
// signature: undefined ___ratelimit(void)
// callers: [smcinvoke_destroy_kthreads, process_tzcb_req, smcinvoke_release_tz_object, smcinvoke_postprocess_kthread_func, prepare_send_scm_msg, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0011c170 size=1
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
// platform_driver_unregister @ 0011c178 size=1
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
// trace_raw_output_prep @ 0011c180 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_process_invoke_req_result, trace_raw_output_marshal_in_tzcb_req_fd, trace_raw_output_smcinvoke_release, trace_raw_output_put_pending_cbobj_locked, trace_raw_output_prepare_send_scm_msg, trace_raw_output_process_tzcb_req_wait, trace_raw_output_status, trace_raw_output_process_tzcb_req_handle, trace_raw_output_process_tzcb_req_result, trace_raw_output_smcinvoke_release_from_kernel_client, trace_raw_output_smcinvoke_release_filp, trace_raw_output_marshal_in_tzcb_req_handle, trace_raw_output_marshal_out_tzcb_req, trace_raw_output_process_invoke_req_tzhandle, trace_raw_output_smcinvoke_create_bridge, trace_raw_output_invoke_cmd_handler, trace_raw_output_process_accept_req_has_response, trace_raw_output_process_accept_req_ret, trace_raw_output_process_log_info, trace_raw_output_process_accept_req_placed, trace_raw_output_release_mem_obj_locked, trace_raw_output_marshal_in_invoke_req, trace_raw_output_smcinvoke_ioctl, trace_raw_output_process_invoke_request_from_kernel_client, trace_raw_output_marshal_out_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0011c188 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_process_invoke_req_result, trace_raw_output_marshal_in_tzcb_req_fd, trace_raw_output_smcinvoke_release, trace_raw_output_put_pending_cbobj_locked, trace_raw_output_prepare_send_scm_msg, trace_raw_output_process_tzcb_req_wait, trace_raw_output_status, trace_raw_output_process_tzcb_req_handle, trace_raw_output_process_tzcb_req_result, trace_raw_output_smcinvoke_release_from_kernel_client, trace_raw_output_smcinvoke_release_filp, trace_raw_output_marshal_in_tzcb_req_handle, trace_raw_output_marshal_out_tzcb_req, trace_raw_output_process_invoke_req_tzhandle, trace_raw_output_smcinvoke_create_bridge, trace_raw_output_invoke_cmd_handler, trace_raw_output_process_accept_req_has_response, trace_raw_output_process_accept_req_ret, trace_raw_output_process_log_info, trace_raw_output_process_accept_req_placed, trace_raw_output_release_mem_obj_locked, trace_raw_output_marshal_in_invoke_req, trace_raw_output_smcinvoke_ioctl, trace_raw_output_process_invoke_request_from_kernel_client, trace_raw_output_marshal_out_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0011c190 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_process_invoke_req_result, trace_raw_output_marshal_in_tzcb_req_fd, trace_raw_output_smcinvoke_release, trace_raw_output_put_pending_cbobj_locked, trace_raw_output_prepare_send_scm_msg, trace_raw_output_process_tzcb_req_wait, trace_raw_output_status, trace_raw_output_process_tzcb_req_handle, trace_raw_output_process_tzcb_req_result, trace_raw_output_smcinvoke_release_from_kernel_client, trace_raw_output_smcinvoke_release_filp, trace_raw_output_marshal_in_tzcb_req_handle, trace_raw_output_marshal_out_tzcb_req, trace_raw_output_process_invoke_req_tzhandle, trace_raw_output_smcinvoke_create_bridge, trace_raw_output_invoke_cmd_handler, trace_raw_output_process_accept_req_has_response, trace_raw_output_process_accept_req_ret, trace_raw_output_process_log_info, trace_raw_output_process_accept_req_placed, trace_raw_output_release_mem_obj_locked, trace_raw_output_marshal_in_invoke_req, trace_raw_output_smcinvoke_ioctl, trace_raw_output_process_invoke_request_from_kernel_client, trace_raw_output_marshal_out_invoke_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_symbols_seq @ 0011c198 size=1
// signature: undefined trace_print_symbols_seq(void)
// callers: [trace_raw_output_smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_symbols_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0011c1a0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [smcinvoke_probe, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0011c1a8 size=1
// signature: undefined init_wait_entry(void)
// callers: [process_tzcb_req, smcinvoke_postprocess_kthread_func, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0011c1b0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [process_tzcb_req, smcinvoke_postprocess_kthread_func, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0011c1b8 size=1
// signature: undefined finish_wait(void)
// callers: [process_tzcb_req, smcinvoke_postprocess_kthread_func, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0011c1c0 size=1
// signature: undefined schedule(void)
// callers: [smcinvoke_postprocess_kthread_func, smcinvoke_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_get @ 0011c1d8 size=1
// signature: undefined dma_buf_get(void)
// callers: [get_tzhandle_from_uhandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_put @ 0011c1e0 size=1
// signature: undefined dma_buf_put(void)
// callers: [free_mem_obj_locked, smcinvoke_postprocess_kthread_func, get_tzhandle_from_uhandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_deregister @ 0011c1e8 size=1
// signature: undefined qtee_shmbridge_deregister(void)
// callers: [free_mem_obj_locked, smcinvoke_postprocess_kthread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_attach @ 0011c1f0 size=1
// signature: undefined dma_buf_attach(void)
// callers: [smcinvoke_map_mem_region_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_buf_map_attachment @ 0011c1f8 size=1
// signature: undefined dma_buf_map_attachment(void)
// callers: [smcinvoke_map_mem_region_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_buf_map_attachment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_is_enabled @ 0011c200 size=1
// signature: undefined qtee_shmbridge_is_enabled(void)
// callers: [smcinvoke_map_mem_region_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_copy_vmperm @ 0011c208 size=1
// signature: undefined mem_buf_dma_buf_copy_vmperm(void)
// callers: [smcinvoke_map_mem_region_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_copy_vmperm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mem_buf_dma_buf_exclusive_owner @ 0011c210 size=1
// signature: undefined mem_buf_dma_buf_exclusive_owner(void)
// callers: [smcinvoke_map_mem_region_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mem_buf_dma_buf_exclusive_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_register @ 0011c218 size=1
// signature: undefined qtee_shmbridge_register(void)
// callers: [smcinvoke_map_mem_region_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_flush_shm_buf @ 0011c220 size=1
// signature: undefined qtee_shmbridge_flush_shm_buf(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_flush_shm_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_invoke_smc_legacy @ 0011c228 size=1
// signature: undefined qcom_scm_invoke_smc_legacy(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_invoke_smc_legacy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_invoke_callback_response @ 0011c240 size=1
// signature: undefined qcom_scm_invoke_callback_response(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_invoke_callback_response(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_inv_shm_buf @ 0011c248 size=1
// signature: undefined qtee_shmbridge_inv_shm_buf(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_inv_shm_buf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_invoke_smc @ 0011c250 size=1
// signature: undefined qcom_scm_invoke_smc(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_invoke_smc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0011c258 size=1
// signature: undefined msleep(void)
// callers: [smcinvoke_destroy_kthreads, get_client_env_object, process_tzcb_req, smcinvoke_postprocess_kthread_func, prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qseecom_process_listener_from_smcinvoke @ 0011c260 size=1
// signature: undefined qseecom_process_listener_from_smcinvoke(void)
// callers: [prepare_send_scm_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qseecom_process_listener_from_smcinvoke(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 0011c268 size=1
// signature: undefined kmemdup(void)
// callers: [process_tzcb_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0011c270 size=1
// signature: undefined schedule_timeout(void)
// callers: [process_tzcb_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 0011c278 size=1
// signature: undefined dma_set_mask(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 0011c280 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0011c288 size=1
// signature: undefined of_find_property(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0011c290 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0011c298 size=1
// signature: undefined wake_up_process(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 0011c2a0 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0011c2a8 size=1
// signature: undefined __class_create(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0011c2b0 size=1
// signature: undefined device_create(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 0011c2b8 size=1
// signature: undefined cdev_init(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 0011c2c0 size=1
// signature: undefined cdev_add(void)
// callers: [smcinvoke_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 0011c2c8 size=1
// signature: undefined device_destroy(void)
// callers: [smcinvoke_probe, smcinvoke_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0011c2d0 size=1
// signature: undefined class_destroy(void)
// callers: [smcinvoke_probe, smcinvoke_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0011c2d8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [smcinvoke_probe, smcinvoke_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 0011c2e0 size=1
// signature: undefined cdev_del(void)
// callers: [smcinvoke_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 0011c2e8 size=1
// signature: undefined kthread_stop(void)
// callers: [smcinvoke_destroy_kthreads]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 0011c2f0 size=1
// signature: undefined kthread_should_stop(void)
// callers: [smcinvoke_postprocess_kthread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_sensitive @ 0011c2f8 size=1
// signature: undefined kfree_sensitive(void)
// callers: [smcinvoke_postprocess_kthread_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// close_fd @ 0011c310 size=1
// signature: undefined close_fd(void)
// callers: [get_client_env_object, invoke_over_smcinvoke, get_root_obj]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void close_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// provide_qseecom_kernel_fun_ops @ 0011c318 size=1
// signature: undefined provide_qseecom_kernel_fun_ops(void)
// callers: [get_qseecom_kernel_fun_ops]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void provide_qseecom_kernel_fun_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0011c320 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [firmware_request_from_smcinvoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// firmware_request_nowarn @ 0011c328 size=1
// signature: undefined firmware_request_nowarn(void)
// callers: [firmware_request_from_smcinvoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void firmware_request_nowarn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 0011c330 size=1
// signature: undefined release_firmware(void)
// callers: [firmware_request_from_smcinvoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0011c338 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [__qseecom_start_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0011c340 size=1
// signature: undefined fortify_panic(void)
// callers: [__qseecom_start_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



