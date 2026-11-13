// Decompiled by Ghidra 12.2
// Program: phy-generic.ko
// Image base: 00100000

//------------------------------------------------------------
// usb_phy_generic_register @ 001002e4 size=116
// signature: undefined usb_phy_generic_register(void)
// callers: []
//------------------------------------------------------------

void usb_phy_generic_register(void)

{
  long lVar1;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  char *pcStack_60;
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
  uStack_50 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_68 = 0;
  pcStack_60 = "usb_phy_generic";
  local_38 = 0;
  uStack_30 = 0;
  local_28 = 0;
  uStack_20 = 0;
  local_58 = 0xfffffffe;
  platform_device_register_full(&local_78);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// usb_phy_generic_unregister @ 0010035c size=28
// signature: undefined usb_phy_generic_unregister(void)
// callers: []
//------------------------------------------------------------

void usb_phy_generic_unregister(void)

{
  platform_device_unregister();
  return;
}



//------------------------------------------------------------
// usb_gen_phy_init @ 0010037c size=200
// signature: undefined usb_gen_phy_init(void)
// callers: []
//------------------------------------------------------------

int usb_gen_phy_init(long *param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*param_1 + 0x98);
  if ((*(ulong *)(lVar3 + 0x198) < 0xfffffffffffff001) && (iVar1 = regulator_enable(), iVar1 != 0))
  {
    _dev_err(*param_1,"Failed to enable power\n");
  }
  uVar2 = *(ulong *)(lVar3 + 400);
  if (uVar2 < 0xfffffffffffff001) {
    iVar1 = clk_prepare(uVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = clk_enable(uVar2);
    if (iVar1 != 0) {
      clk_unprepare(uVar2);
      return iVar1;
    }
  }
  if (*(long *)(lVar3 + 0x1a0) != 0) {
    gpiod_set_value_cansleep(*(long *)(lVar3 + 0x1a0),1);
    usleep_range_state(10000,20000,2);
    gpiod_set_value_cansleep(*(undefined8 *)(lVar3 + 0x1a0),0);
  }
  return 0;
}



//------------------------------------------------------------
// usb_gen_phy_shutdown @ 00100448 size=132
// signature: undefined usb_gen_phy_shutdown(void)
// callers: []
//------------------------------------------------------------

void usb_gen_phy_shutdown(long *param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*param_1 + 0x98);
  gpiod_set_value_cansleep(*(undefined8 *)(lVar3 + 0x1a0),1);
  uVar2 = *(ulong *)(lVar3 + 400);
  if (uVar2 < 0xfffffffffffff001) {
    clk_disable(uVar2);
    clk_unprepare(uVar2);
  }
  if ((*(ulong *)(lVar3 + 0x198) < 0xfffffffffffff001) && (iVar1 = regulator_disable(), iVar1 != 0))
  {
    _dev_err(*param_1,"Failed to disable power\n");
  }
  return;
}



//------------------------------------------------------------
// usb_phy_gen_create_phy @ 001004d0 size=648
// signature: undefined usb_phy_gen_create_phy(void)
// callers: [usb_phy_generic_probe]
//------------------------------------------------------------

ulong usb_phy_gen_create_phy(long param_1,long *param_2)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  char *pcVar8;
  long lVar9;
  int local_4c;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x2e8);
  local_4c = 0;
  if (lVar9 == 0) {
    bVar1 = true;
    bVar2 = true;
  }
  else {
    iVar3 = of_property_read_variable_u32_array(lVar9,"clock-frequency",&local_4c,1,0);
    if (iVar3 < 0) {
      local_4c = 0;
    }
    lVar5 = of_find_property(lVar9,"vcc-supply",0);
    bVar1 = lVar5 == 0;
    lVar9 = of_find_property(lVar9,"clocks",0);
    bVar2 = lVar9 == 0;
  }
  uVar6 = devm_gpiod_get_optional(param_1,"reset",0);
  param_2[0x34] = uVar6;
  if ((uVar6 < 0xfffffffffffff001) || ((int)uVar6 == 0)) {
    uVar7 = devm_gpiod_get_optional(param_1,"vbus-detect",0);
    param_2[0x35] = uVar7;
    if ((0xfffffffffffff000 < uVar7) && (uVar6 = uVar7 & 0xffffffff, (int)uVar7 != 0))
    goto LAB_001005c4;
    if (param_2[0x34] != 0) {
      gpiod_direction_output(param_2[0x34],1);
    }
    lVar9 = devm_kmalloc(param_1,0x60,0xdc0);
    param_2[4] = lVar9;
    if (lVar9 == 0) {
      uVar6 = 0xfffffff4;
      goto LAB_001005d8;
    }
    uVar6 = devm_clk_get(param_1,"main_clk");
    if (uVar6 < 0xfffffffffffff001) {
      bVar2 = true;
    }
    param_2[0x32] = uVar6;
    if (!bVar2) goto LAB_001005d8;
    if (((uVar6 < 0xfffffffffffff001) && (local_4c != 0)) &&
       (uVar4 = clk_set_rate(uVar6), uVar4 != 0)) {
      uVar6 = (ulong)uVar4;
      _dev_err(param_1,"Error setting clock rate\n");
      goto LAB_001005d8;
    }
    uVar6 = devm_regulator_get(param_1,&DAT_00100c1f);
    param_2[0x33] = uVar6;
    if (uVar6 < 0xfffffffffffff001) {
      bVar1 = true;
    }
    if (!bVar1) {
      uVar6 = 0xfffffdfb;
      goto LAB_001005d8;
    }
    uVar6 = devm_regulator_get_exclusive(param_1,&DAT_00100bd5);
    param_2[0x36] = uVar6;
    if (uVar6 == 0xffffffffffffffed) {
      param_2[0x36] = 0;
LAB_001006e0:
      param_2[0x31] = param_1;
      *param_2 = param_1;
      param_2[1] = (long)"nop-xceiv";
      param_2[0x27] = (long)nop_set_suspend;
      *(undefined4 *)((long)param_2 + 0x14) = 1;
      *(undefined4 *)(param_2[4] + 0x28) = 0;
      uVar6 = 0;
      *(long **)(param_2[4] + 0x10) = param_2;
      *(code **)(param_2[4] + 0x30) = nop_set_host;
      *(code **)(param_2[4] + 0x38) = nop_set_peripheral;
      goto LAB_001005d8;
    }
    if (uVar6 < 0xfffffffffffff001) goto LAB_001006e0;
    pcVar8 = "could not get vbus regulator\n";
  }
  else {
LAB_001005c4:
    pcVar8 = "Error requesting RESET or VBUS GPIO\n";
  }
  uVar6 = dev_err_probe(param_1,uVar6,pcVar8);
  uVar6 = uVar6 & 0xffffffff;
LAB_001005d8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// nop_set_suspend @ 0010075c size=100
// signature: undefined nop_set_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 nop_set_suspend(long *param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = *(ulong *)(*(long *)(*param_1 + 0x98) + 400);
  if (uVar2 < 0xfffffffffffff001) {
    if (param_2 == 0) {
      iVar1 = clk_prepare(uVar2);
      if (iVar1 != 0) {
        return 0;
      }
      iVar1 = clk_enable(uVar2);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      clk_disable();
    }
    clk_unprepare(uVar2);
  }
  return 0;
}



//------------------------------------------------------------
// nop_set_host @ 001007c4 size=28
// signature: undefined nop_set_host(void)
// callers: []
//------------------------------------------------------------

undefined4 nop_set_host(long param_1,long param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffed;
  if (param_1 != 0) {
    *(long *)(param_1 + 0x18) = param_2;
    uVar1 = 0xffffffed;
    if (param_2 != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// nop_set_peripheral @ 001007e4 size=112
// signature: undefined nop_set_peripheral(void)
// callers: []
//------------------------------------------------------------

undefined8 nop_set_peripheral(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffed;
  }
  else if (param_2 == 0) {
    uVar1 = 0xffffffed;
    *(undefined8 *)(param_1 + 0x20) = 0;
  }
  else {
    *(long *)(param_1 + 0x20) = param_2;
    if (*(int *)(param_1 + 0x28) == 3) {
      atomic_notifier_call_chain(*(long *)(param_1 + 0x10) + 0xf0,1);
      uVar1 = 0;
    }
    else {
      uVar1 = 0;
      *(undefined4 *)(param_1 + 0x28) = 1;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// usb_phy_generic_probe @ 00100858 size=288
// signature: undefined usb_phy_generic_probe(void)
// callers: []
//------------------------------------------------------------

int usb_phy_generic_probe(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  
  lVar1 = param_1 + 0x10;
  lVar4 = devm_kmalloc(lVar1,0x1d0,0xdc0);
  if (lVar4 == 0) {
    iVar2 = -0xc;
  }
  else {
    iVar2 = usb_phy_gen_create_phy(lVar1,lVar4);
    if (iVar2 == 0) {
      if (*(long *)(lVar4 + 0x1a8) != 0) {
        uVar3 = gpiod_to_irq();
        iVar2 = devm_request_threaded_irq
                          (lVar1,uVar3,0,nop_gpio_vbus_thread,0x2083,"vbus_detect",lVar4);
        if (iVar2 != 0) {
          uVar3 = gpiod_to_irq(*(undefined8 *)(lVar4 + 0x1a8));
          _dev_err(lVar1,"can\'t request irq %i, err: %d\n",uVar3,iVar2);
          return iVar2;
        }
        iVar2 = gpiod_get_value();
        uVar3 = 3;
        if (iVar2 == 0) {
          uVar3 = 1;
        }
        *(undefined4 *)(*(long *)(lVar4 + 0x20) + 0x28) = uVar3;
      }
      *(code **)(lVar4 + 0x118) = usb_gen_phy_init;
      *(code **)(lVar4 + 0x120) = usb_gen_phy_shutdown;
      iVar2 = usb_add_phy_dev(lVar4);
      if (iVar2 == 0) {
        *(long *)(param_1 + 0xa8) = lVar4;
      }
      else {
        _dev_err(lVar1,"can\'t register transceiver, err: %d\n",iVar2);
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// usb_phy_generic_remove @ 0010097c size=36
// signature: undefined usb_phy_generic_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_phy_generic_remove(long param_1)

{
  usb_remove_phy(*(undefined8 *)(param_1 + 0xa8));
  return 0;
}



//------------------------------------------------------------
// nop_gpio_vbus_thread @ 001009a4 size=228
// signature: undefined nop_gpio_vbus_thread(void)
// callers: []
//------------------------------------------------------------

undefined8 nop_gpio_vbus_thread(undefined8 param_1,long param_2)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_2 + 0x20);
  iVar2 = gpiod_get_value(*(undefined8 *)(param_2 + 0x1a8));
  if (iVar2 == *(int *)(param_2 + 0x1c8)) {
    return 1;
  }
  *(int *)(param_2 + 0x1c8) = iVar2;
  if (iVar2 != 0) {
    uVar3 = 1;
    *(undefined4 *)(lVar5 + 0x28) = 3;
    lVar4 = *(long *)(param_2 + 0x1b0);
    *(undefined4 *)(param_2 + 0x18) = 1;
    if (lVar4 != 0) {
      cVar1 = *(char *)(param_2 + 0x1b8);
      regulator_set_current_limit(lVar4,0,100000);
      if (cVar1 == '\0') {
        iVar2 = regulator_enable(lVar4);
        uVar3 = 1;
        if (iVar2 < 0) goto LAB_00100a64;
        *(undefined1 *)(param_2 + 0x1b8) = 1;
      }
      uVar3 = 1;
      *(undefined8 *)(param_2 + 0x1c0) = 100;
    }
    goto LAB_00100a64;
  }
  if (*(long *)(param_2 + 0x1b0) != 0) {
    if (*(char *)(param_2 + 0x1b8) != '\0') {
      iVar2 = regulator_disable();
      if (iVar2 < 0) goto LAB_00100a54;
      *(undefined1 *)(param_2 + 0x1b8) = 0;
    }
    *(undefined8 *)(param_2 + 0x1c0) = 0;
  }
LAB_00100a54:
  uVar3 = 0;
  *(undefined4 *)(lVar5 + 0x28) = 1;
  *(undefined4 *)(param_2 + 0x18) = 0;
LAB_00100a64:
  atomic_notifier_call_chain(param_2 + 0xf0,uVar3,*(undefined8 *)(lVar5 + 0x20));
  return 1;
}



//------------------------------------------------------------
// init_module @ 00100b00 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&usb_phy_generic_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100b30 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&usb_phy_generic_driver);
  return;
}



//------------------------------------------------------------
// platform_device_register_full @ 00102000 size=1
// signature: undefined platform_device_register_full(void)
// callers: [usb_phy_generic_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_register_full(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102008 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [usb_phy_generic_register, usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 00102010 size=1
// signature: undefined platform_device_unregister(void)
// callers: [usb_phy_generic_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00102018 size=1
// signature: undefined regulator_enable(void)
// callers: [usb_gen_phy_init, nop_gpio_vbus_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_value_cansleep @ 00102020 size=1
// signature: undefined gpiod_set_value_cansleep(void)
// callers: [usb_gen_phy_init, usb_gen_phy_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_value_cansleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00102028 size=1
// signature: undefined usleep_range_state(void)
// callers: [usb_gen_phy_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00102030 size=1
// signature: undefined clk_prepare(void)
// callers: [usb_gen_phy_init, nop_set_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00102038 size=1
// signature: undefined clk_enable(void)
// callers: [usb_gen_phy_init, nop_set_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00102040 size=1
// signature: undefined clk_unprepare(void)
// callers: [usb_gen_phy_init, nop_set_suspend, usb_gen_phy_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [usb_gen_phy_init, usb_phy_generic_probe, usb_phy_gen_create_phy, usb_gen_phy_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00102050 size=1
// signature: undefined clk_disable(void)
// callers: [nop_set_suspend, usb_gen_phy_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00102058 size=1
// signature: undefined regulator_disable(void)
// callers: [nop_gpio_vbus_thread, usb_gen_phy_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102060 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00102068 size=1
// signature: undefined of_find_property(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpiod_get_optional @ 00102070 size=1
// signature: undefined devm_gpiod_get_optional(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpiod_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00102078 size=1
// signature: undefined dev_err_probe(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output @ 00102080 size=1
// signature: undefined gpiod_direction_output(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102088 size=1
// signature: undefined devm_kmalloc(void)
// callers: [usb_phy_generic_probe, usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00102090 size=1
// signature: undefined devm_clk_get(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 00102098 size=1
// signature: undefined clk_set_rate(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 001020a0 size=1
// signature: undefined devm_regulator_get(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_exclusive @ 001020a8 size=1
// signature: undefined devm_regulator_get_exclusive(void)
// callers: [usb_phy_gen_create_phy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_exclusive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_call_chain @ 001020b0 size=1
// signature: undefined atomic_notifier_call_chain(void)
// callers: [nop_gpio_vbus_thread, nop_set_peripheral]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001020b8 size=1
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
// platform_driver_unregister @ 001020c0 size=1
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
// gpiod_to_irq @ 001020c8 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [usb_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001020d0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [usb_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_value @ 001020d8 size=1
// signature: undefined gpiod_get_value(void)
// callers: [nop_gpio_vbus_thread, usb_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_phy_dev @ 001020e0 size=1
// signature: undefined usb_add_phy_dev(void)
// callers: [usb_phy_generic_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_phy_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_phy @ 001020e8 size=1
// signature: undefined usb_remove_phy(void)
// callers: [usb_phy_generic_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_phy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_current_limit @ 001020f0 size=1
// signature: undefined regulator_set_current_limit(void)
// callers: [nop_gpio_vbus_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_current_limit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



