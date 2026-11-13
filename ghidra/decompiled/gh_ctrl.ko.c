// Decompiled by Ghidra 12.2
// Program: gh_ctrl.ko
// Image base: 00100000

//------------------------------------------------------------
// type_show @ 00100314 size=48
// signature: undefined type_show(void)
// callers: []
//------------------------------------------------------------

long type_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"gunyah\n");
  return (long)iVar1;
}



//------------------------------------------------------------
// api_show @ 00100348 size=60
// signature: undefined api_show(void)
// callers: []
//------------------------------------------------------------

long api_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001012db,(uint)gunyah_api_0 & 0x3fff);
  return (long)iVar1;
}



//------------------------------------------------------------
// variant_show @ 00100388 size=56
// signature: undefined variant_show(void)
// callers: []
//------------------------------------------------------------

long variant_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001012db,gunyah_api_0._7_1_);
  return (long)iVar1;
}



//------------------------------------------------------------
// gh_dbgfs_trace_class_set_fops_open @ 001003c4 size=52
// signature: undefined gh_dbgfs_trace_class_set_fops_open(void)
// callers: []
//------------------------------------------------------------

void gh_dbgfs_trace_class_set_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,gh_dbgfs_trace_class_get,gh_dbgfs_trace_class_set,"0x%llx\n");
  return;
}



//------------------------------------------------------------
// gh_dbgfs_trace_class_get @ 001003fc size=200
// signature: undefined gh_dbgfs_trace_class_get(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x001004b0) */

void gh_dbgfs_trace_class_get(undefined8 param_1,undefined8 *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = sp_el0;
  lVar2 = *(long *)(lVar2 + 0x638);
  *param_2 = 0;
  CallHyperVisor(0x603f);
  if (param_2 == (undefined8 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0010048c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)((long)DAT_00100b40 + 0x100480))(0,0,0,0,0,0,0,0,0);
    return;
  }
  *param_2 = 0;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar2) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



//------------------------------------------------------------
// gh_dbgfs_trace_class_set @ 001004ec size=204
// signature: undefined gh_dbgfs_trace_class_set(void)
// callers: []
//------------------------------------------------------------

void gh_dbgfs_trace_class_set(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = sp_el0;
  CallHyperVisor(0x603f);
  switch((int)param_2) {
  case 0:
    break;
  default:
    param_2 = 0xffffffea;
    break;
  case 10:
    param_2 = 0xfffffff4;
    break;
  case 0x1e:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
    param_2 = 0xfffffff3;
    break;
  case 0x1f:
  case 0x20:
    param_2 = 0xfffffff0;
    break;
  case 0x28:
  case 0x29:
  case 0x3c:
  case 0x3d:
    param_2 = 0xfffffffb;
    break;
  case -2:
  case -1:
    param_2 = 0xffffffa1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != *(long *)(lVar1 + 0x638)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_2,0,0,0,0,0,0,0,0);
  }
  return;
}



//------------------------------------------------------------
// gh_dbgfs_trace_class_clear_fops_open @ 001005bc size=52
// signature: undefined gh_dbgfs_trace_class_clear_fops_open(void)
// callers: []
//------------------------------------------------------------

void gh_dbgfs_trace_class_clear_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,gh_dbgfs_trace_class_get,gh_dbgfs_trace_class_clear,"0x%llx\n");
  return;
}



//------------------------------------------------------------
// gh_dbgfs_trace_class_clear @ 001005f4 size=164
// signature: undefined gh_dbgfs_trace_class_clear(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100688) */
/* WARNING: Removing unreachable block (ram,0x001006a8) */
/* WARNING: Removing unreachable block (ram,0x001006b8) */

void gh_dbgfs_trace_class_clear(void)

{
  undefined8 uVar1;
  
  uVar1 = sp_el0;
  CallHyperVisor(0x603f);
                    /* WARNING: Could not recover jumptable at 0x00100664. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)((long)DAT_00100d40 + 0x100658))();
  return;
}



//------------------------------------------------------------
// gh_dbgfs_hyp_uart_ctrl_fops_open @ 001006c0 size=52
// signature: undefined gh_dbgfs_hyp_uart_ctrl_fops_open(void)
// callers: []
//------------------------------------------------------------

void gh_dbgfs_hyp_uart_ctrl_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,gh_dbgfs_hyp_uart_get,gh_dbgfs_hyp_uart_set,"0x%llx\n");
  return;
}



//------------------------------------------------------------
// gh_dbgfs_hyp_uart_get @ 001006f8 size=20
// signature: undefined gh_dbgfs_hyp_uart_get(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_dbgfs_hyp_uart_get(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)hyp_uart_enable;
  return 0;
}



//------------------------------------------------------------
// gh_dbgfs_hyp_uart_set @ 00100710 size=176
// signature: undefined gh_dbgfs_hyp_uart_set(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_dbgfs_hyp_uart_set(undefined8 param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_2 == 0) {
    if (hyp_uart_enable == 1) {
      hyp_uart_enable = 0;
      _printk(&DAT_0010131b);
      CallSecureMonitor(0);
      return 0;
    }
    puVar1 = &DAT_00101292;
  }
  else if (param_2 == 1) {
    if ((hyp_uart_enable & 1) == 0) {
      hyp_uart_enable = 1;
      _printk(&DAT_0010126d);
      CallSecureMonitor(0);
      return 0;
    }
    puVar1 = &DAT_001013de;
  }
  else {
    puVar1 = &DAT_0010135f;
  }
  _printk(puVar1);
  return 0;
}



//------------------------------------------------------------
// init_module @ 001007cc size=464
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100908) */
/* WARNING: Removing unreachable block (ram,0x001008e8) */
/* WARNING: Removing unreachable block (ram,0x001008a8) */
/* WARNING: Removing unreachable block (ram,0x00100888) */
/* WARNING: Removing unreachable block (ram,0x001008b8) */
/* WARNING: Removing unreachable block (ram,0x001008c8) */
/* WARNING: Removing unreachable block (ram,0x001008d8) */
/* WARNING: Removing unreachable block (ram,0x001008f8) */
/* WARNING: Removing unreachable block (ram,0x00100980) */
/* WARNING: Removing unreachable block (ram,0x0010098c) */
/* WARNING: Removing unreachable block (ram,0x00100918) */
/* WARNING: Removing unreachable block (ram,0x00100924) */
/* WARNING: Removing unreachable block (ram,0x0010092c) */
/* WARNING: Removing unreachable block (ram,0x00100934) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void init_module(void)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  long lVar4;
  
  lVar2 = sp_el0;
  lVar4 = *(long *)(lVar2 + 0x638);
  lVar2 = of_find_node_opts_by_path("/hypervisor",0);
  if ((lVar2 == 0) ||
     ((iVar1 = of_device_is_compatible(lVar2,"qcom,gunyah-hypervisor"), iVar1 == 0 &&
      (iVar1 = of_device_is_compatible(lVar2,"qcom,haven-hypervisor"), iVar1 == 0)))) {
    puVar3 = &DAT_00101419;
  }
  else {
    CallHyperVisor(0x6000);
    gunyah_api_0 = 0;
    _gunyah_api_1 = 0;
    puVar3 = &DAT_0010145b;
  }
  _printk(puVar3);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(0);
  }
  return;
}



//------------------------------------------------------------
// gh_sysfs_register @ 0010099c size=76
// signature: undefined gh_sysfs_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_sysfs_register(void)

{
  int iVar1;
  
  iVar1 = sysfs_create_file_ns(_hypervisor_kobj,&type_attr,0);
  if (iVar1 == 0) {
    sysfs_create_group(_hypervisor_kobj,&version_group);
  }
  return;
}



//------------------------------------------------------------
// gh_dbgfs_register @ 001009e8 size=216
// signature: undefined gh_dbgfs_register(void)
// callers: [init_module]
//------------------------------------------------------------

ulong gh_dbgfs_register(void)

{
  ulong uVar1;
  
  uVar1 = debugfs_create_dir("gunyah",0);
  gh_dbgfs_dir = uVar1;
  if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
    if ((gunyah_api_1 < '\0') &&
       (((uVar1 = debugfs_create_file("trace_set",0x180,uVar1,0,&gh_dbgfs_trace_class_set_fops),
         0xfffffffffffff000 < uVar1 ||
         (uVar1 = debugfs_create_file("trace_clear",0x180,gh_dbgfs_dir,0,
                                      &gh_dbgfs_trace_class_clear_fops), 0xfffffffffffff000 < uVar1)
         ) || (uVar1 = debugfs_create_file("hyp_uart_ctrl",0x180,gh_dbgfs_dir,0,
                                           &gh_dbgfs_hyp_uart_ctrl_fops), 0xfffffffffffff000 < uVar1
              )))) {
      uVar1 = uVar1 & 0xffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 00100ac8 size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  gh_sysfs_unregister();
  debugfs_remove(gh_dbgfs_dir);
  return;
}



//------------------------------------------------------------
// gh_sysfs_unregister @ 00100af0 size=72
// signature: undefined gh_sysfs_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gh_sysfs_unregister(void)

{
  sysfs_remove_file_ns(_hypervisor_kobj,&type_attr,0);
  sysfs_remove_group(_hypervisor_kobj,&version_group);
  return;
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00102000 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00102008 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arm_smccc_sve_check @ 00102010 size=1
// signature: undefined __arm_smccc_sve_check(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arm_smccc_sve_check(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102018 size=1
// signature: undefined _printk(void)
// callers: [gh_dbgfs_hyp_uart_set, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_dbgfs_trace_class_set, gh_dbgfs_trace_class_get, gh_dbgfs_trace_class_clear, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00102028 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00102038 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [gh_sysfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00102040 size=1
// signature: undefined sysfs_create_group(void)
// callers: [gh_sysfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00102048 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [gh_dbgfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00102050 size=1
// signature: undefined debugfs_create_file(void)
// callers: [gh_dbgfs_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102058 size=1
// signature: undefined scnprintf(void)
// callers: [type_show, variant_show, api_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00102060 size=1
// signature: undefined simple_attr_open(void)
// callers: [gh_dbgfs_trace_class_set_fops_open, gh_dbgfs_hyp_uart_ctrl_fops_open, gh_dbgfs_trace_class_clear_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 00102068 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [gh_sysfs_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 00102070 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [gh_sysfs_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



