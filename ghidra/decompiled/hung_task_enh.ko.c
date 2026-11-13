// Decompiled by Ghidra 12.2
// Program: hung_task_enh.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_before_check_tasks @ 0010014c size=172
// signature: undefined qcom_before_check_tasks(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_before_check_tasks(undefined8 param_1,long param_2,long param_3,undefined1 *param_4)

{
  int iVar1;
  
  if (DAT_00100604 == 1) {
    if (*(char *)(param_2 + 0xd49) != '\x02') goto LAB_00100180;
  }
  else if ((DAT_00100604 != 0) || (*(char *)(param_2 + 0xd49) == '\x01')) {
LAB_00100180:
    *param_4 = 1;
    if ((*(ushort *)(param_2 + 0x5e8) >> 2 & 1) == 0) {
      return;
    }
    iVar1 = *(int *)(param_2 + 0x30);
    if (((iVar1 != 2) && (iVar1 != 0x104)) && (iVar1 != 8)) {
      return;
    }
    if (*(long *)(param_2 + 0x868) == 0) {
      return;
    }
    if (-1 < (*(long *)(param_2 + 0x868) + param_3 * 0xfa) - _jiffies) {
      return;
    }
    if (*(long *)(param_2 + 0x5a0) == 0) {
      return;
    }
    if (*(long *)(param_2 + 0x670) == param_2) {
      DAT_00100608 = DAT_00100608 + 1;
      return;
    }
    return;
  }
  *param_4 = 0;
  return;
}



//------------------------------------------------------------
// qcom_check_tasks_done @ 001001fc size=84
// signature: undefined qcom_check_tasks_done(void)
// callers: []
//------------------------------------------------------------

void qcom_check_tasks_done(void)

{
  int iVar1;
  
  iVar1 = 0;
  if (DAT_0010060c <= DAT_00100608) {
    iVar1 = DAT_00100610 + 1;
  }
  DAT_00100610 = iVar1;
  if ((DAT_00100614 != 0) && (DAT_00100614 <= iVar1)) {
                    /* WARNING: Subroutine does not return */
    panic("Detect IO wait too long time for multiple tasks!\n");
  }
  DAT_00100608 = 0;
  return;
}



//------------------------------------------------------------
// hung_task_handler @ 00100254 size=480
// signature: undefined hung_task_handler(void)
// callers: []
//------------------------------------------------------------

int hung_task_handler(long param_1,int param_2,undefined8 param_3,undefined8 param_4,
                     undefined8 param_5)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  undefined1 uVar8;
  undefined8 local_90;
  undefined8 *puStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  puStack_88 = &local_50;
  local_50 = 0xffffffffffffffff;
  local_90 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  uStack_78 = 0;
  local_80 = (ulong)CONCAT24(*(undefined2 *)(param_1 + 0x14),8);
  mutex_lock(readpid_mutex);
  if (param_2 == 0) {
    uVar6 = find_vpid(hung_task_enh);
    lVar7 = get_pid_task(uVar6,0);
    if (lVar7 == 0) {
      iVar5 = -2;
      goto LAB_001003f4;
    }
    local_50 = (ulong)CONCAT14(*(undefined1 *)(lVar7 + 0xd49),hung_task_enh);
    iVar5 = proc_dointvec(&local_90,0,param_3,param_4,param_5);
  }
  else {
    iVar5 = proc_dointvec(&local_90,param_2,param_3,param_4,param_5);
    if (iVar5 != 0) goto LAB_001003f4;
    iVar5 = -2;
    if ((int)local_50 < 1) goto LAB_001003f4;
    if (((long)local_50 < 0) || (1 < local_50._4_4_)) goto LAB_001003f4;
    uVar6 = find_vpid();
    lVar7 = get_pid_task(uVar6,0);
    if (lVar7 == 0) goto LAB_001003f4;
    if (local_50._4_4_ == 1) {
      if (DAT_00100604 == 0) {
        uVar8 = 1;
      }
      else {
        uVar8 = 2;
      }
      iVar5 = 0;
      *(undefined1 *)(lVar7 + 0xd49) = uVar8;
    }
    else {
      iVar5 = 0;
      *(undefined1 *)(lVar7 + 0xd49) = 0;
    }
  }
  piVar1 = (int *)(lVar7 + 0x40);
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
    __put_task_struct(lVar7);
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
LAB_001003f4:
  mutex_unlock(readpid_mutex);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// read_pid_handler @ 00100448 size=124
// signature: undefined read_pid_handler(void)
// callers: []
//------------------------------------------------------------

undefined4
read_pid_handler(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                undefined8 param_5)

{
  undefined4 uVar1;
  
  mutex_lock(readpid_mutex);
  uVar1 = proc_dointvec_minmax(param_1,param_2,param_3,param_4,param_5);
  mutex_unlock(readpid_mutex);
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 001004c8 size=224
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  DAT_0010060c = 5;
  iVar1 = tracepoint_probe_register
                    (&__tracepoint_android_vh_check_uninterrupt_tasks,qcom_before_check_tasks,0);
  if (iVar1 == 0) {
    iVar1 = tracepoint_probe_register
                      (&__tracepoint_android_vh_check_uninterrupt_tasks_done,qcom_check_tasks_done,0
                      );
    if (iVar1 == 0) {
      DAT_00100618 = register_sysctl_table(&hung_task_base_table);
      if (DAT_00100618 == 0) {
        tracepoint_probe_unregister
                  (&__tracepoint_android_vh_check_uninterrupt_tasks,qcom_before_check_tasks,0);
        tracepoint_probe_unregister
                  (&__tracepoint_android_vh_check_uninterrupt_tasks_done,qcom_check_tasks_done,0);
        iVar1 = -0xc;
      }
      else {
        iVar1 = 0;
      }
    }
    else {
      tracepoint_probe_unregister
                (&__tracepoint_android_vh_check_uninterrupt_tasks,qcom_before_check_tasks,0);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001005ac size=84
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_sysctl_table(DAT_00100618);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_check_uninterrupt_tasks,qcom_before_check_tasks,0);
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_check_uninterrupt_tasks_done,qcom_check_tasks_done,0);
  return;
}



//------------------------------------------------------------
// panic @ 00102008 size=1
// signature: noreturn undefined panic(void)
// callers: [qcom_check_tasks_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102010 size=1
// signature: undefined mutex_lock(void)
// callers: [read_pid_handler, hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_dointvec @ 00102018 size=1
// signature: undefined proc_dointvec(void)
// callers: [hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_dointvec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_vpid @ 00102020 size=1
// signature: undefined find_vpid(void)
// callers: [hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_vpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_pid_task @ 00102028 size=1
// signature: undefined get_pid_task(void)
// callers: [hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_pid_task(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __put_task_struct @ 00102038 size=1
// signature: undefined __put_task_struct(void)
// callers: [hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __put_task_struct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102040 size=1
// signature: undefined mutex_unlock(void)
// callers: [read_pid_handler, hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00102048 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hung_task_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_dointvec_minmax @ 00102058 size=1
// signature: undefined proc_dointvec_minmax(void)
// callers: [read_pid_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_dointvec_minmax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00102068 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00102078 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_sysctl_table @ 00102080 size=1
// signature: undefined register_sysctl_table(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_sysctl_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_sysctl_table @ 00102088 size=1
// signature: undefined unregister_sysctl_table(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_sysctl_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



