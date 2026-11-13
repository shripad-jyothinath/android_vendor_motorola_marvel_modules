// Decompiled by Ghidra 12.2
// Program: qti-fixed-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// reg_fixed_voltage_probe @ 001001ac size=936
// signature: undefined reg_fixed_voltage_probe(void)
// callers: []
//------------------------------------------------------------

ulong reg_fixed_voltage_probe(long param_1)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  long *plVar4;
  undefined8 *puVar5;
  long lVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  long lVar10;
  long local_78;
  undefined8 uStack_70;
  long *local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  ulong local_50;
  long local_48;
  
  lVar10 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar10 + 0x638);
  pcVar3 = (char *)of_device_get_match_data(lVar1);
  local_58 = 0;
  local_50 = 0;
  local_68 = (long *)0x0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  plVar4 = (long *)devm_kmalloc(lVar1,0x150,0xdc0);
  if (plVar4 != (long *)0x0) {
    lVar10 = *(long *)(param_1 + 0x2f8);
    if (lVar10 != 0) {
      puVar5 = (undefined8 *)devm_kmalloc(lVar1,0x28,0xdc0);
      if (puVar5 == (undefined8 *)0x0) {
        puVar5 = (undefined8 *)0xfffffffffffffff4;
        goto LAB_00100440;
      }
      lVar6 = of_get_regulator_init_data(lVar1,*(undefined8 *)(param_1 + 0x2f8),plVar4);
      puVar5[4] = lVar6;
      if (lVar6 != 0) {
        *(ushort *)(lVar6 + 0xe0) = *(ushort *)(lVar6 + 0xe0) & 0xfffb;
        *puVar5 = *(undefined8 *)(lVar6 + 8);
        if (*(int *)(lVar6 + 0x10) == *(int *)(lVar6 + 0x14)) {
          *(int *)(puVar5 + 2) = *(int *)(lVar6 + 0x10);
          if ((*(ushort *)(lVar6 + 0xe0) >> 1 & 1) != 0) {
            *(byte *)((long)puVar5 + 0x1c) = *(byte *)((long)puVar5 + 0x1c) | 1;
          }
          of_property_read_variable_u32_array(lVar10,"startup-delay-us",(long)puVar5 + 0x14,1,0);
          of_property_read_variable_u32_array(lVar10,"off-on-delay-us",puVar5 + 3,1,0);
          lVar10 = of_find_property(lVar10,"vin-supply",0);
          if (lVar10 != 0) {
            puVar5[1] = &DAT_00101289;
          }
          if ((undefined8 *)0xfffffffffffff000 < puVar5) goto LAB_00100440;
          goto LAB_001002ec;
        }
        _dev_err(lVar1,"Fixed regulator specified with variable voltages\n");
      }
      puVar5 = (undefined8 *)0xffffffffffffffea;
      goto LAB_00100440;
    }
    puVar5 = *(undefined8 **)(param_1 + 0xa0);
    if (puVar5 != (undefined8 *)0x0) {
LAB_001002ec:
      lVar10 = devm_kstrdup(lVar1,*puVar5,0xcc0);
      *plVar4 = lVar10;
      if (lVar10 == 0) {
        _dev_err(lVar1,"Failed to allocate supply name\n");
        puVar5 = (undefined8 *)0xfffffff4;
        goto LAB_00100440;
      }
      *(undefined4 *)((long)plVar4 + 0x4c) = 0;
      plVar4[10] = (long)&__this_module;
      if (pcVar3 == (char *)0x0) {
LAB_001003a4:
        plVar4[8] = (long)fixed_voltage_ops;
      }
      else if (*pcVar3 == '\0') {
        if (pcVar3[1] == '\0') goto LAB_001003a4;
        uVar8 = *(undefined8 *)(param_1 + 0x2f8);
        plVar4[8] = (long)fixed_voltage_domain_ops;
        iVar2 = of_get_required_opp_performance_state(uVar8,0);
        *(int *)((long)plVar4 + 0x14c) = iVar2;
        if (iVar2 < 0) {
          _dev_err(lVar1,"Can\'t get performance state from devicetree\n");
          puVar5 = (undefined8 *)(ulong)*(uint *)((long)plVar4 + 0x14c);
          goto LAB_00100440;
        }
      }
      else {
        plVar4[8] = (long)fixed_voltage_clkenabled_ops;
        uVar7 = devm_clk_get(lVar1,0);
        plVar4[0x28] = uVar7;
        if (0xfffffffffffff000 < uVar7) {
          _dev_err(lVar1,"Can\'t get enable-clock from devicetree\n");
          puVar5 = (undefined8 *)(ulong)*(uint *)(plVar4 + 0x28);
          goto LAB_00100440;
        }
      }
      *(undefined4 *)((long)plVar4 + 0x11c) = *(undefined4 *)((long)puVar5 + 0x14);
      *(undefined4 *)(plVar4 + 0x24) = *(undefined4 *)(puVar5 + 3);
      if (puVar5[1] != 0) {
        lVar10 = devm_kstrdup(lVar1,puVar5[1],0xcc0);
        plVar4[1] = lVar10;
        if (lVar10 == 0) goto LAB_0010043c;
      }
      uVar9 = 0;
      if (*(int *)(puVar5 + 2) != 0) {
        *(undefined4 *)(plVar4 + 7) = 1;
        uVar9 = *(undefined4 *)(puVar5 + 2);
      }
      *(undefined4 *)((long)plVar4 + 100) = uVar9;
      uVar9 = 0x13;
      if ((*(byte *)((long)puVar5 + 0x1c) & 1) != 0) {
        uVar9 = 0x17;
      }
      local_50 = gpiod_get_optional(lVar1,0,uVar9);
      if (local_50 < 0xfffffffffffff001) {
        uStack_70 = puVar5[4];
        uStack_60 = *(undefined8 *)(param_1 + 0x2f8);
        local_78 = lVar1;
        local_68 = plVar4;
        uVar7 = devm_regulator_register(lVar1,plVar4,&local_78);
        plVar4[0x27] = uVar7;
        if (uVar7 < 0xfffffffffffff001) {
          *(long **)(param_1 + 0xa8) = plVar4;
          iVar2 = devm_regulator_proxy_consumer_register(lVar1,*(undefined8 *)(param_1 + 0x2f8));
          if (iVar2 != 0) {
            _dev_err(lVar1,"failed to register proxy consumer, ret=%d\n",iVar2);
          }
          iVar2 = devm_regulator_debug_register(lVar1,uVar7);
          if (iVar2 != 0) {
            _dev_err(lVar1,"failed to register debug regulator, ret=%d\n",iVar2);
          }
          puVar5 = (undefined8 *)0x0;
        }
        else {
          uVar7 = dev_err_probe(lVar1,uVar7 & 0xffffffff,"Failed to register regulator: %ld\n",uVar7
                               );
          puVar5 = (undefined8 *)(uVar7 & 0xffffffff);
        }
      }
      else {
        uVar7 = dev_err_probe(lVar1,local_50,"can\'t get GPIO\n");
        puVar5 = (undefined8 *)(uVar7 & 0xffffffff);
      }
      goto LAB_00100440;
    }
  }
LAB_0010043c:
  puVar5 = (undefined8 *)0xfffffff4;
LAB_00100440:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar5 & 0xffffffff;
}



//------------------------------------------------------------
// reg_clock_enable @ 00100558 size=112
// signature: undefined reg_clock_enable(void)
// callers: []
//------------------------------------------------------------

int reg_clock_enable(void)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = rdev_get_drvdata();
  uVar3 = *(undefined8 *)(lVar2 + 0x140);
  iVar1 = clk_prepare(uVar3);
  if (iVar1 == 0) {
    iVar1 = clk_enable(uVar3);
    if (iVar1 == 0) {
      *(int *)(lVar2 + 0x148) = *(int *)(lVar2 + 0x148) + 1;
    }
    else {
      clk_unprepare(uVar3);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// reg_clock_disable @ 001005cc size=76
// signature: undefined reg_clock_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_clock_disable(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = rdev_get_drvdata();
  uVar2 = *(undefined8 *)(lVar1 + 0x140);
  clk_disable(uVar2);
  clk_unprepare(uVar2);
  *(int *)(lVar1 + 0x148) = *(int *)(lVar1 + 0x148) + -1;
  return 0;
}



//------------------------------------------------------------
// reg_is_enabled @ 0010061c size=40
// signature: undefined reg_is_enabled(void)
// callers: []
//------------------------------------------------------------

bool reg_is_enabled(void)

{
  long lVar1;
  
  lVar1 = rdev_get_drvdata();
  return *(int *)(lVar1 + 0x148) != 0;
}



//------------------------------------------------------------
// reg_domain_enable @ 00100648 size=72
// signature: undefined reg_domain_enable(void)
// callers: []
//------------------------------------------------------------

void reg_domain_enable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  iVar1 = dev_pm_genpd_set_performance_state
                    (*(undefined8 *)(param_1 + 0x148),*(undefined4 *)(lVar2 + 0x14c));
  if (iVar1 == 0) {
    *(int *)(lVar2 + 0x148) = *(int *)(lVar2 + 0x148) + 1;
  }
  return;
}



//------------------------------------------------------------
// reg_domain_disable @ 00100694 size=72
// signature: undefined reg_domain_disable(void)
// callers: []
//------------------------------------------------------------

void reg_domain_disable(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  iVar1 = dev_pm_genpd_set_performance_state(*(undefined8 *)(param_1 + 0x148),0);
  if (iVar1 == 0) {
    *(int *)(lVar2 + 0x148) = *(int *)(lVar2 + 0x148) + -1;
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001006e0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&regulator_fixed_voltage_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100710 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&regulator_fixed_voltage_driver);
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
// of_device_get_match_data @ 00102010 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_regulator_init_data @ 00102020 size=1
// signature: undefined of_get_regulator_init_data(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_regulator_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102030 size=1
// signature: undefined of_find_property(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 00102038 size=1
// signature: undefined devm_kstrdup(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00102040 size=1
// signature: undefined devm_clk_get(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_required_opp_performance_state @ 00102050 size=1
// signature: undefined of_get_required_opp_performance_state(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_required_opp_performance_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_optional @ 00102058 size=1
// signature: undefined gpiod_get_optional(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00102060 size=1
// signature: undefined dev_err_probe(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00102068 size=1
// signature: undefined devm_regulator_register(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_proxy_consumer_register @ 00102070 size=1
// signature: undefined devm_regulator_proxy_consumer_register(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_proxy_consumer_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 00102078 size=1
// signature: undefined devm_regulator_debug_register(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_debug_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [reg_fixed_voltage_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00102088 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [reg_clock_disable, reg_domain_disable, reg_is_enabled, reg_domain_enable, reg_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00102090 size=1
// signature: undefined clk_prepare(void)
// callers: [reg_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00102098 size=1
// signature: undefined clk_enable(void)
// callers: [reg_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001020a0 size=1
// signature: undefined clk_unprepare(void)
// callers: [reg_clock_disable, reg_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001020a8 size=1
// signature: undefined clk_disable(void)
// callers: [reg_clock_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_genpd_set_performance_state @ 001020b0 size=1
// signature: undefined dev_pm_genpd_set_performance_state(void)
// callers: [reg_domain_disable, reg_domain_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_genpd_set_performance_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



