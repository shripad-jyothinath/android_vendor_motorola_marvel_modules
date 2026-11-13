// Decompiled by Ghidra 12.2
// Program: coresight-dummy.ko
// Image base: 00100000

//------------------------------------------------------------
// dummy_probe @ 001001fc size=424
// signature: undefined dummy_probe(void)
// callers: []
//------------------------------------------------------------

void dummy_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_90;
  undefined8 local_88;
  undefined **local_80;
  undefined8 local_78;
  long local_70;
  undefined8 local_68;
  long local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar5 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = (undefined **)0x0;
  local_90 = 0;
  local_60 = coresight_alloc_device_name(dummy_devs,lVar1);
  if (local_60 != 0) {
    uVar2 = coresight_get_platform_data(lVar1);
    if (0xfffffffffffff000 < uVar2) goto LAB_0010033c;
    *(ulong *)(param_1 + 0xa0) = uVar2;
    plVar3 = (long *)devm_kmalloc(lVar1,0x18,0xdc0);
    if (plVar3 != (long *)0x0) {
      *plVar3 = lVar1;
      *(long **)(param_1 + 0xa8) = plVar3;
      uVar4 = *(undefined8 *)(param_1 + 0x2f8);
      *(int *)(plVar3 + 2) = dummy_probe_traceid;
      dummy_probe_traceid = dummy_probe_traceid + 1;
      lVar5 = of_find_property(uVar4,"qcom,dummy-source",0);
      if (lVar5 == 0) {
        lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,dummy-sink",0);
        if (lVar5 == 0) {
          lVar5 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,dummy-link",0);
          if (lVar5 == 0) {
            _dev_info(lVar1,"Device type not set\n");
            uVar2 = 0xffffffea;
            goto LAB_0010033c;
          }
          local_90 = CONCAT44(local_90._4_4_,1);
          local_88 = CONCAT44(local_88._4_4_,1);
        }
        else {
          local_90 = 0x100000000;
        }
      }
      else {
        local_90 = 3;
      }
      local_78 = *(undefined8 *)(param_1 + 0xa0);
      local_80 = &dummy_cs_ops;
      local_70 = lVar1;
      uVar2 = coresight_register(&local_90);
      plVar3[1] = uVar2;
      if (uVar2 < 0xfffffffffffff001) {
        pm_runtime_enable(lVar1);
        _dev_info(lVar1,"Dummy device initialized\n");
        uVar2 = 0;
      }
      goto LAB_0010033c;
    }
  }
  uVar2 = 0xfffffff4;
LAB_0010033c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// dummy_remove @ 001003a8 size=64
// signature: undefined dummy_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  __pm_runtime_disable(param_1 + 0x10,1);
  coresight_unregister(*(undefined8 *)(lVar1 + 8));
  return 0;
}



//------------------------------------------------------------
// dummy_sink_enable @ 001003ec size=52
// signature: undefined dummy_sink_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_sink_enable(long param_1)

{
  _dev_info(**(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98),"Dummy sink enabled\n");
  return 0;
}



//------------------------------------------------------------
// dummy_sink_disable @ 00100424 size=52
// signature: undefined dummy_sink_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_sink_disable(long param_1)

{
  _dev_info(**(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98),"Dummy sink disabled\n");
  return 0;
}



//------------------------------------------------------------
// dummy_link_enable @ 0010045c size=52
// signature: undefined dummy_link_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_link_enable(long param_1)

{
  _dev_info(**(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98),"Dummy link enable\n");
  return 0;
}



//------------------------------------------------------------
// dummy_link_disable @ 00100494 size=48
// signature: undefined dummy_link_disable(void)
// callers: []
//------------------------------------------------------------

void dummy_link_disable(long param_1)

{
  _dev_info(**(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98),"Dummy link disabled\n");
  return;
}



//------------------------------------------------------------
// dummy_trace_id @ 001004c8 size=16
// signature: undefined dummy_trace_id(void)
// callers: []
//------------------------------------------------------------

undefined4 dummy_trace_id(long param_1)

{
  return *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x98) + 0x98) + 0x10);
}



//------------------------------------------------------------
// dummy_source_enable @ 001004dc size=52
// signature: undefined dummy_source_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_source_enable(long param_1)

{
  _dev_info(**(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98),"Dummy source enabled\n");
  return 0;
}



//------------------------------------------------------------
// dummy_source_disable @ 00100514 size=48
// signature: undefined dummy_source_disable(void)
// callers: []
//------------------------------------------------------------

void dummy_source_disable(long param_1)

{
  _dev_info(**(undefined8 **)(*(long *)(param_1 + 0x98) + 0x98),"Dummy source disabled\n");
  return;
}



//------------------------------------------------------------
// init_module @ 00100548 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&dummy_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100578 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&dummy_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// coresight_alloc_device_name @ 00102010 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [dummy_probe]
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
// callers: [dummy_probe]
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
// callers: [dummy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102028 size=1
// signature: undefined of_find_property(void)
// callers: [dummy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 00102030 size=1
// signature: undefined coresight_register(void)
// callers: [dummy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00102038 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [dummy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102040 size=1
// signature: undefined _dev_info(void)
// callers: [dummy_link_enable, dummy_source_enable, dummy_source_disable, dummy_sink_disable, dummy_sink_enable, dummy_link_disable, dummy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [dummy_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00102050 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [dummy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00102058 size=1
// signature: undefined coresight_unregister(void)
// callers: [dummy_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



