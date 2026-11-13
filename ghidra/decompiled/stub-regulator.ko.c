// Decompiled by Ghidra 12.2
// Program: stub-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// regulator_stub_probe @ 00100234 size=568
// signature: undefined regulator_stub_probe(void)
// callers: []
//------------------------------------------------------------

ulong regulator_stub_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  undefined4 uVar7;
  long local_68;
  long lStack_60;
  long *local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  if (*(long *)(param_1 + 0x2f8) == 0) {
    _dev_err(lVar1,"%s: device node missing\n","regulator_stub_probe");
    uVar6 = 0xffffffed;
    goto LAB_001003ac;
  }
  plVar3 = (long *)devm_kmalloc(lVar1,0x150,0xdc0);
  if ((plVar3 != (long *)0x0) &&
     (lVar4 = of_get_regulator_init_data(lVar1,*(undefined8 *)(param_1 + 0x2f8),plVar3), lVar4 != 0)
     ) {
    if (*(long *)(lVar4 + 8) == 0) {
      _dev_err(lVar1,"%s: regulator name not specified\n","regulator_stub_probe");
      uVar6 = 0xffffffea;
      goto LAB_001003ac;
    }
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"qcom,system-load",plVar3 + 0x29,1,0);
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"qcom,hpm-min-load",(long)plVar3 + 0x144,1,0);
    uVar7 = 4;
    if (*(int *)((long)plVar3 + 0x144) <= (int)plVar3[0x29]) {
      uVar7 = 2;
    }
    *(undefined4 *)(plVar3 + 0x27) = *(undefined4 *)(lVar4 + 0x10);
    *(undefined4 *)(plVar3 + 0x28) = uVar7;
    *(uint *)(lVar4 + 0x40) = *(uint *)(lVar4 + 0x40) | 0x14;
    *(int *)(lVar4 + 0x44) = *(int *)(lVar4 + 0x14);
    *(undefined4 *)(lVar4 + 0x3c) = 6;
    *(uint *)(plVar3 + 7) = (uint)(*(int *)(lVar4 + 0x10) != 0 || *(int *)(lVar4 + 0x14) != 0) << 1;
    lVar5 = devm_kstrdup(lVar1,*(undefined8 *)(lVar4 + 8),0xcc0);
    *plVar3 = lVar5;
    if (lVar5 != 0) {
      *(undefined4 *)((long)plVar3 + 0x4c) = 0;
      plVar3[1] = (long)"parent";
      plVar3[8] = (long)&regulator_stub_ops;
      plVar3[10] = (long)&__this_module;
      uStack_50 = *(undefined8 *)(param_1 + 0x2f8);
      local_68 = lVar1;
      lStack_60 = lVar4;
      local_58 = plVar3;
      uVar6 = devm_regulator_register(lVar1,plVar3,&local_68);
      if (uVar6 < 0xfffffffffffff001) {
        iVar2 = devm_regulator_debug_register(lVar1,uVar6);
        if (iVar2 != 0) {
          _dev_err(lVar1,"failed to register debug regulator, rc=%d\n",iVar2);
        }
        uVar6 = 0;
      }
      else if ((int)uVar6 == -0x205) {
        uVar6 = 0xfffffdfb;
      }
      else {
        _dev_err(lVar1,"%s: regulator_register failed\n","regulator_stub_probe");
      }
      goto LAB_001003ac;
    }
  }
  uVar6 = 0xfffffff4;
LAB_001003ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// regulator_stub_list_voltage @ 00100470 size=40
// signature: undefined regulator_stub_list_voltage(void)
// callers: []
//------------------------------------------------------------

undefined4 regulator_stub_list_voltage(long param_1,uint param_2)

{
  if (1 < param_2) {
    return 0xffffffea;
  }
  if (param_2 == 0) {
    return *(undefined4 *)(*(long *)(param_1 + 0x478) + 8);
  }
  return *(undefined4 *)(*(long *)(param_1 + 0x478) + 0xc);
}



//------------------------------------------------------------
// regulator_stub_set_voltage @ 0010049c size=52
// signature: undefined regulator_stub_set_voltage(void)
// callers: []
//------------------------------------------------------------

undefined8 regulator_stub_set_voltage(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined4 *)(lVar1 + 0x138) = param_2;
  return 0;
}



//------------------------------------------------------------
// regulator_stub_get_voltage @ 001004d4 size=32
// signature: undefined regulator_stub_get_voltage(void)
// callers: []
//------------------------------------------------------------

undefined4 regulator_stub_get_voltage(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined4 *)(lVar1 + 0x138);
}



//------------------------------------------------------------
// regulator_stub_enable @ 001004f8 size=44
// signature: undefined regulator_stub_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 regulator_stub_enable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x13c) = 1;
  return 0;
}



//------------------------------------------------------------
// regulator_stub_disable @ 00100528 size=40
// signature: undefined regulator_stub_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 regulator_stub_disable(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  *(undefined1 *)(lVar1 + 0x13c) = 0;
  return 0;
}



//------------------------------------------------------------
// regulator_stub_is_enabled @ 00100554 size=32
// signature: undefined regulator_stub_is_enabled(void)
// callers: []
//------------------------------------------------------------

undefined1 regulator_stub_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined1 *)(lVar1 + 0x13c);
}



//------------------------------------------------------------
// regulator_stub_set_mode @ 00100578 size=108
// signature: undefined regulator_stub_set_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 regulator_stub_set_mode(long param_1,int param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = rdev_get_drvdata();
  if ((param_2 == 2) || (param_2 == 4)) {
    uVar2 = 0;
    *(int *)(lVar1 + 0x140) = param_2;
  }
  else {
    _dev_err(param_1 + 0xe8,"%s: invalid mode requested %u\n","regulator_stub_set_mode",param_2);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// regulator_stub_get_mode @ 001005e8 size=32
// signature: undefined regulator_stub_get_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 regulator_stub_get_mode(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(undefined4 *)(lVar1 + 0x140);
}



//------------------------------------------------------------
// regulator_stub_get_optimum_mode @ 0010060c size=68
// signature: undefined regulator_stub_get_optimum_mode(void)
// callers: []
//------------------------------------------------------------

undefined4 regulator_stub_get_optimum_mode(void)

{
  long lVar1;
  int in_w3;
  undefined4 uVar2;
  
  lVar1 = rdev_get_drvdata();
  uVar2 = 4;
  if (*(int *)(lVar1 + 0x144) <= *(int *)(lVar1 + 0x148) + in_w3) {
    uVar2 = 2;
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100654 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&regulator_stub_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100684 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&regulator_stub_driver);
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 00102018 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 00102028 size=1
// signature: undefined devm_kstrdup(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00102030 size=1
// signature: undefined devm_regulator_register(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 00102038 size=1
// signature: undefined devm_regulator_debug_register(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [regulator_stub_probe, regulator_stub_set_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [regulator_stub_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00102050 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [regulator_stub_get_voltage, regulator_stub_get_mode, regulator_stub_is_enabled, regulator_stub_set_mode, regulator_stub_get_optimum_mode, regulator_stub_set_voltage, regulator_stub_disable, regulator_stub_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



