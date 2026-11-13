// Decompiled by Ghidra 12.2
// Program: qcom_scmi_vendor.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_scmi_vendor_protocol_init @ 001001ac size=116
// signature: undefined qcom_scmi_vendor_protocol_init(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scmi_vendor_protocol_init(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  if (*(int *)((code *)**(undefined8 **)(param_1 + 8) + -4) != -0x1d3332c8) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1001f0);
    (*pcVar2)();
  }
  (*(code *)**(undefined8 **)(param_1 + 8))(param_1,&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_scmi_set_param @ 00100224 size=328
// signature: undefined qcom_scmi_set_param(void)
// callers: []
//------------------------------------------------------------

int qcom_scmi_set_param(long param_1,void *param_2,undefined8 param_3,undefined4 param_4,
                       size_t param_5)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  long local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((param_1 == 0) || (*(long *)(param_1 + 8) == 0)) {
    iVar2 = -0x16;
  }
  else {
    pcVar3 = *(code **)(*(long *)(param_1 + 8) + 8);
    if (*(int *)(pcVar3 + -4) != -0x7a2ac1ec) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1002a0);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)(param_1,0x10,param_5 + 0x10,0x80,&local_50);
    if (iVar2 == 0) {
      puVar4 = *(undefined4 **)(local_50 + 0x18);
      *puVar4 = 0;
      puVar4[1] = (int)param_3;
      puVar4[2] = (int)((ulong)param_3 >> 0x20);
      puVar4[3] = param_4;
      memcpy(puVar4 + 4,param_2,param_5);
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x18);
      if (*(int *)(pcVar3 + -4) != -0x504a14db) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1002f8);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(param_1,local_50);
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x28);
      if (*(int *)(pcVar3 + -4) != 0x15fee88b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100328);
        (*pcVar3)();
      }
      (*pcVar3)(param_1,local_50);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_scmi_get_param @ 00100370 size=408
// signature: undefined qcom_scmi_get_param(void)
// callers: []
//------------------------------------------------------------

int qcom_scmi_get_param(long param_1,void *param_2,undefined8 param_3,undefined4 param_4,
                       size_t param_5,ulong param_6)

{
  long lVar1;
  int iVar2;
  size_t __n;
  code *pcVar3;
  undefined4 *puVar4;
  long local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_60 = 0;
  if (param_1 == 0) {
    iVar2 = -0x16;
  }
  else {
    iVar2 = -0x16;
    if ((param_2 != (void *)0x0) && (*(long *)(param_1 + 8) != 0)) {
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 8);
      if (*(int *)(pcVar3 + -4) != -0x7a2ac1ec) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1003fc);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(param_1,0x11,param_5 + 0x10,0x80,&local_60);
      if (iVar2 == 0) {
        puVar4 = *(undefined4 **)(local_60 + 0x18);
        *puVar4 = 0;
        puVar4[1] = (int)param_3;
        puVar4[2] = (int)((ulong)param_3 >> 0x20);
        puVar4[3] = param_4;
        memcpy(puVar4 + 4,param_2,param_5);
        pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x18);
        if (*(int *)(pcVar3 + -4) != -0x504a14db) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100454);
          (*pcVar3)();
        }
        iVar2 = (*pcVar3)(param_1,local_60);
        lVar1 = local_60;
        __n = *(size_t *)(local_60 + 0x30);
        if (param_6 < __n) {
          _printk(&DAT_00100900,__n,param_6);
          iVar2 = -0x5a;
        }
        else {
          memcpy(param_2,*(void **)(local_60 + 0x28),__n);
          pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x28);
          if (*(int *)(pcVar3 + -4) != 0x15fee88b) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1004a4);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,lVar1);
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_scmi_start_activity @ 0010050c size=328
// signature: undefined qcom_scmi_start_activity(void)
// callers: []
//------------------------------------------------------------

int qcom_scmi_start_activity
              (long param_1,void *param_2,undefined8 param_3,undefined4 param_4,size_t param_5)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  long local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((param_1 == 0) || (*(long *)(param_1 + 8) == 0)) {
    iVar2 = -0x16;
  }
  else {
    pcVar3 = *(code **)(*(long *)(param_1 + 8) + 8);
    if (*(int *)(pcVar3 + -4) != -0x7a2ac1ec) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100588);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)(param_1,0x12,param_5 + 0x10,0x80,&local_50);
    if (iVar2 == 0) {
      puVar4 = *(undefined4 **)(local_50 + 0x18);
      *puVar4 = 0;
      puVar4[1] = (int)param_3;
      puVar4[2] = (int)((ulong)param_3 >> 0x20);
      puVar4[3] = param_4;
      memcpy(puVar4 + 4,param_2,param_5);
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x18);
      if (*(int *)(pcVar3 + -4) != -0x504a14db) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1005e0);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(param_1,local_50);
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x28);
      if (*(int *)(pcVar3 + -4) != 0x15fee88b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100610);
        (*pcVar3)();
      }
      (*pcVar3)(param_1,local_50);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_scmi_stop_activity @ 00100658 size=328
// signature: undefined qcom_scmi_stop_activity(void)
// callers: []
//------------------------------------------------------------

int qcom_scmi_stop_activity
              (long param_1,void *param_2,undefined8 param_3,undefined4 param_4,size_t param_5)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  long local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((param_1 == 0) || (*(long *)(param_1 + 8) == 0)) {
    iVar2 = -0x16;
  }
  else {
    pcVar3 = *(code **)(*(long *)(param_1 + 8) + 8);
    if (*(int *)(pcVar3 + -4) != -0x7a2ac1ec) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1006d4);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)(param_1,0x13,param_5 + 0x10,0x80,&local_50);
    if (iVar2 == 0) {
      puVar4 = *(undefined4 **)(local_50 + 0x18);
      *puVar4 = 0;
      puVar4[1] = (int)param_3;
      puVar4[2] = (int)((ulong)param_3 >> 0x20);
      puVar4[3] = param_4;
      memcpy(puVar4 + 4,param_2,param_5);
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x18);
      if (*(int *)(pcVar3 + -4) != -0x504a14db) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10072c);
        (*pcVar3)();
      }
      iVar2 = (*pcVar3)(param_1,local_50);
      pcVar3 = *(code **)(*(long *)(param_1 + 8) + 0x28);
      if (*(int *)(pcVar3 + -4) != 0x15fee88b) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10075c);
        (*pcVar3)();
      }
      (*pcVar3)(param_1,local_50);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 001007a4 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  scmi_protocol_register(&qcom_scmi_vendor);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001007cc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  scmi_protocol_unregister(&qcom_scmi_vendor);
  return;
}



//------------------------------------------------------------
// scmi_protocol_register @ 00101000 size=1
// signature: undefined scmi_protocol_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scmi_protocol_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scmi_protocol_unregister @ 00101008 size=1
// signature: undefined scmi_protocol_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scmi_protocol_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_scmi_start_activity, qcom_scmi_vendor_protocol_init, qcom_scmi_get_param, qcom_scmi_set_param, qcom_scmi_stop_activity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00101018 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_scmi_start_activity, qcom_scmi_get_param, qcom_scmi_set_param, qcom_scmi_stop_activity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101020 size=1
// signature: undefined _printk(void)
// callers: [qcom_scmi_get_param]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



