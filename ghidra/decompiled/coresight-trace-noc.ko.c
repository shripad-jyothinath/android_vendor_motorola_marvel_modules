// Decompiled by Ghidra 12.2
// Program: coresight-trace-noc.ko
// Image base: 00100000

//------------------------------------------------------------
// trace_noc_probe @ 00100394 size=372
// signature: undefined trace_noc_probe(void)
// callers: []
//------------------------------------------------------------

void trace_noc_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  long *plVar3;
  long lVar4;
  undefined8 local_90;
  ulong local_88;
  undefined1 *local_80;
  undefined8 local_78;
  long local_70;
  undefined **local_68;
  long local_60;
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
  local_68 = (undefined **)0x0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = (undefined1 *)0x0;
  local_90 = 0;
  local_60 = coresight_alloc_device_name(trace_noc_devs,param_1);
  if (local_60 != 0) {
    uVar2 = coresight_get_platform_data(param_1);
    if (0xfffffffffffff000 < uVar2) goto LAB_0010049c;
    *(ulong *)(param_1 + 0x90) = uVar2;
    plVar3 = (long *)devm_kmalloc(param_1,0x38,0xdc0);
    if (plVar3 != (long *)0x0) {
      plVar3[1] = param_1;
      *(long **)(param_1 + 0x98) = plVar3;
      lVar4 = devm_ioremap_resource(param_1,param_1 + 0x390);
      *plVar3 = lVar4;
      if (lVar4 != 0) {
        iVar1 = of_property_read_variable_u32_array
                          (*(undefined8 *)(plVar3[1] + 0x2e8),&DAT_0010104a,plVar3 + 4,1,0);
        if (iVar1 < 0) {
          _dev_err(plVar3[1],"Trace Noc ATID is not specified\n");
          uVar2 = 0xffffffea;
        }
        else {
          local_78 = *(undefined8 *)(param_1 + 0x90);
          local_90 = CONCAT44(local_90._4_4_,1);
          local_88 = local_88 & 0xffffffff00000000;
          local_80 = &trace_noc_cs_ops;
          local_68 = &trace_noc_attr_grps;
          local_70 = param_1;
          uVar2 = coresight_register(&local_90);
          plVar3[2] = uVar2;
          if (uVar2 < 0xfffffffffffff001) {
            __pm_runtime_idle(param_1,5);
            uVar2 = 0;
            *(undefined4 *)(plVar3 + 3) = 0;
            *(undefined4 *)((long)plVar3 + 0x2c) = 1;
            *(undefined1 *)((long)plVar3 + 0x1e) = 1;
          }
        }
        goto LAB_0010049c;
      }
    }
  }
  uVar2 = 0xfffffff4;
LAB_0010049c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// trace_noc_enable @ 0010050c size=248
// signature: undefined trace_noc_enable(void)
// callers: []
//------------------------------------------------------------

int trace_noc_enable(long param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  long *plVar5;
  
  plVar5 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  iVar1 = __pm_runtime_resume(plVar5[1],4);
  if (iVar1 < 0) {
    __pm_runtime_idle(plVar5[1],5);
  }
  else {
    _raw_spin_lock(plVar5 + 3);
    writel_relaxed((int)plVar5[4],*plVar5 + 0x10);
    writel_relaxed(0xffff,*plVar5 + 0x20);
    if (*(int *)((long)plVar5 + 0x24) != 0) {
      writel_relaxed(*(int *)((long)plVar5 + 0x24),*plVar5 + 0x18);
    }
    uVar2 = readl_relaxed(*plVar5 + 8);
    uVar4 = 0x80;
    if ((int)plVar5[6] != 1) {
      uVar4 = 1;
    }
    uVar3 = 0x100;
    if (*(int *)((long)plVar5 + 0x2c) != 1) {
      uVar3 = 1;
    }
    writel_relaxed(uVar2 & 0xfffffe7f | uVar4 | uVar3 | 1,*plVar5 + 8);
    *(undefined1 *)((long)plVar5 + 0x1c) = 1;
    _raw_spin_unlock(plVar5 + 3);
    _dev_info(plVar5[1],"Trace NOC is enabled\n");
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// trace_noc_disable @ 00100608 size=108
// signature: undefined trace_noc_disable(void)
// callers: []
//------------------------------------------------------------

void trace_noc_disable(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  _raw_spin_lock(plVar1 + 3);
  writel_relaxed(0,*plVar1 + 8);
  *(undefined1 *)((long)plVar1 + 0x1c) = 0;
  _raw_spin_unlock(plVar1 + 3);
  __pm_runtime_idle(plVar1[1],5);
  _dev_info(plVar1[1],"Trace NOC is disabled\n");
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00100674 size=132
// signature: undefined writel_relaxed(void)
// callers: [flush_req_store, trace_noc_enable, trace_noc_disable, freq_ts_req_store]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10068c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1006c8,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001006f8 size=124
// signature: undefined readl_relaxed(void)
// callers: [flush_status_show, flush_req_store, trace_noc_enable, freq_ts_req_store]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100740,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// flush_req_store @ 00100778 size=208
// signature: undefined flush_req_store(void)
// callers: []
//------------------------------------------------------------

undefined8 flush_req_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    _raw_spin_lock(plVar4 + 3);
    if (*(char *)((long)plVar4 + 0x1c) == '\0') {
      param_4 = 0xffffffffffffffff;
    }
    else if (local_40 != 0) {
      uVar3 = readl_relaxed(*plVar4 + 8);
      writel_relaxed(uVar3 | 2,*plVar4 + 8);
    }
    _raw_spin_unlock(plVar4 + 3);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// flush_status_show @ 0010084c size=140
// signature: undefined flush_status_show(void)
// callers: []
//------------------------------------------------------------

long flush_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  plVar1 = plVar5 + 3;
  _raw_spin_lock(plVar1);
  if (*(char *)((long)plVar5 + 0x1c) == '\0') {
    _raw_spin_unlock(plVar1);
    lVar4 = -1;
  }
  else {
    uVar2 = readl_relaxed(*plVar5 + 8);
    _raw_spin_unlock(plVar1);
    iVar3 = scnprintf(param_3,0x1000,&DAT_001010b0,uVar2 >> 2 & 1);
    lVar4 = (long)iVar3;
  }
  return lVar4;
}



//------------------------------------------------------------
// flag_type_show @ 001008dc size=64
// signature: undefined flag_type_show(void)
// callers: []
//------------------------------------------------------------

long flag_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001010b0,
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// flag_type_store @ 00100920 size=172
// signature: undefined flag_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8 flag_type_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    _raw_spin_lock(lVar1);
    *(uint *)(lVar3 + 0x30) = (uint)(local_40 != 0);
    _raw_spin_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_type_show @ 001009d0 size=64
// signature: undefined freq_type_show(void)
// callers: []
//------------------------------------------------------------

long freq_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001010b0,
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x2c));
  return (long)iVar1;
}



//------------------------------------------------------------
// freq_type_store @ 00100a14 size=172
// signature: undefined freq_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8 freq_type_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x18;
    _raw_spin_lock(lVar1);
    *(uint *)(lVar3 + 0x2c) = (uint)(local_40 != 0);
    _raw_spin_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_req_val_show @ 00100ac4 size=64
// signature: undefined freq_req_val_show(void)
// callers: []
//------------------------------------------------------------

long freq_req_val_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001010b0,
                    *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x24));
  return (long)iVar1;
}



//------------------------------------------------------------
// freq_req_val_store @ 00100b08 size=172
// signature: undefined freq_req_val_store(void)
// callers: []
//------------------------------------------------------------

undefined8 freq_req_val_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0,&local_40);
  if (iVar2 == 0) {
    if (local_40 != 0) {
      lVar1 = lVar3 + 0x18;
      _raw_spin_lock(lVar1);
      *(int *)(lVar3 + 0x24) = (int)local_40;
      _raw_spin_unlock(lVar1);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_ts_req_store @ 00100bb8 size=208
// signature: undefined freq_ts_req_store(void)
// callers: []
//------------------------------------------------------------

undefined8 freq_ts_req_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0x10,&local_40);
  if (iVar2 == 0) {
    _raw_spin_lock(plVar4 + 3);
    if (*(char *)((long)plVar4 + 0x1c) == '\0') {
      param_4 = 0xffffffffffffffff;
    }
    else if (local_40 != 0) {
      uVar3 = readl_relaxed(*plVar4 + 8);
      writel_relaxed(uVar3 | 0x20,*plVar4 + 8);
    }
    _raw_spin_unlock(plVar4 + 3);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00100c90 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  amba_driver_register(&trace_noc_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100cb8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  amba_driver_unregister(&trace_noc_driver);
  return;
}



//------------------------------------------------------------
// trace_noc_remove @ 00100ce0 size=36
// signature: undefined trace_noc_remove(void)
// callers: []
//------------------------------------------------------------

void trace_noc_remove(long param_1)

{
  coresight_unregister(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x10));
  return;
}



//------------------------------------------------------------
// amba_driver_register @ 00102000 size=1
// signature: undefined amba_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_unregister @ 00102008 size=1
// signature: undefined amba_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 00102010 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_get_platform_data @ 00102018 size=1
// signature: undefined coresight_get_platform_data(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_get_platform_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00102028 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102030 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00102038 size=1
// signature: undefined coresight_register(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00102040 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [trace_noc_probe, trace_noc_enable, trace_noc_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [trace_noc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trace_noc_probe, flush_req_store, freq_type_store, freq_req_val_store, freq_ts_req_store, flag_type_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00102058 size=1
// signature: undefined coresight_unregister(void)
// callers: [trace_noc_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00102060 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [trace_noc_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00102068 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [flush_status_show, flush_req_store, freq_type_store, freq_req_val_store, trace_noc_enable, trace_noc_disable, freq_ts_req_store, flag_type_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00102070 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [flush_status_show, flush_req_store, freq_type_store, freq_req_val_store, trace_noc_enable, trace_noc_disable, freq_ts_req_store, flag_type_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102078 size=1
// signature: undefined _dev_info(void)
// callers: [trace_noc_enable, trace_noc_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00102080 size=1
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
// log_post_write_mmio @ 00102088 size=1
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
// log_read_mmio @ 00102090 size=1
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
// log_post_read_mmio @ 00102098 size=1
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
// kstrtoull @ 001020a0 size=1
// signature: undefined kstrtoull(void)
// callers: [flush_req_store, freq_type_store, freq_req_val_store, freq_ts_req_store, flag_type_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001020a8 size=1
// signature: undefined scnprintf(void)
// callers: [flush_status_show, freq_type_show, flag_type_show, freq_req_val_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



