// Decompiled by Ghidra 12.2
// Program: wlan_antenna.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 0010012c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&wlan_antenna_plat_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010015c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&wlan_antenna_plat_driver);
  return;
}



//------------------------------------------------------------
// wlan_antenna_probe @ 00100184 size=424
// signature: undefined wlan_antenna_probe(void)
// callers: []
//------------------------------------------------------------

ulong wlan_antenna_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  undefined8 uVar5;
  ulong uVar6;
  undefined *puVar7;
  ulong uVar8;
  
  lVar1 = param_1 + 0x10;
  plVar4 = (long *)devm_kmalloc(lVar1,0x28,0xdc0);
  if (plVar4 == (long *)0x0) {
    uVar8 = 0xfffffff4;
    goto LAB_001001b8;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  *plVar4 = lVar1;
  *(long **)(param_1 + 0xa8) = plVar4;
  uVar5 = of_get_named_gpio_flags(uVar5,"qcom,wlan_antenna-gpio",0,0);
  *(int *)(plVar4 + 2) = (int)uVar5;
  uVar2 = gpio_request(uVar5,"wlan_antenna_gpio");
  if (uVar2 != 0) {
    uVar8 = (ulong)uVar2;
    _printk(&DAT_00100700,"wlan_antenna_probe",(int)plVar4[2],uVar8);
    goto LAB_001001b8;
  }
  uVar8 = devm_pinctrl_get(lVar1);
  plVar4[1] = uVar8;
  if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
    puVar7 = &DAT_00100770;
LAB_001002ec:
    _printk(puVar7,"wlan_antenna_probe",uVar8 & 0xffffffff);
  }
  else {
    uVar8 = pinctrl_lookup_state(uVar8,"antenna_active");
    plVar4[3] = uVar8;
    if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
      puVar7 = &DAT_00100726;
    }
    else {
      uVar8 = pinctrl_lookup_state(plVar4[1],"antenna_suspend");
      plVar4[4] = uVar8;
      if ((uVar8 != 0) && (uVar8 < 0xfffffffffffff001)) {
        iVar3 = pinctrl_select_state(plVar4[1],uVar8);
        puVar7 = &DAT_00100908;
        if (iVar3 != 0) {
          puVar7 = &DAT_00100875;
        }
        _printk(puVar7);
        uVar6 = sysfs_create_group(lVar1,wlan_antenna_sysfs_attr_grp);
        uVar8 = uVar6 & 0xffffffff;
        if ((int)uVar6 == 0) {
          _dev_info(lVar1,"probe: All success !\n");
          goto LAB_001001b8;
        }
        puVar7 = &DAT_001008d2;
        goto LAB_001002ec;
      }
      puVar7 = &DAT_0010079a;
    }
    _printk(puVar7,uVar8 & 0xffffffff);
  }
LAB_001001b8:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// wlan_antenna_remove @ 00100330 size=8
// signature: undefined wlan_antenna_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 wlan_antenna_remove(void)

{
  return 0;
}



//------------------------------------------------------------
// wlan_antenna_en_read @ 0010033c size=128
// signature: undefined wlan_antenna_en_read(void)
// callers: []
//------------------------------------------------------------

undefined8 wlan_antenna_en_read(long param_1,undefined8 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_00100848);
    uVar2 = 0xffffffffffffffea;
  }
  else {
    gpio_to_desc(*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x10));
    iVar1 = gpiod_get_raw_value();
    if (iVar1 == 0) {
      uVar2 = 4;
      *(undefined1 *)(param_3 + 1) = 0;
      *param_3 = 0xa776f6c;
    }
    else {
      uVar2 = 5;
      *(undefined2 *)(param_3 + 1) = 10;
      *param_3 = 0x68676968;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wlan_antenna_en_write @ 001003c0 size=200
// signature: undefined wlan_antenna_en_write(void)
// callers: []
//------------------------------------------------------------

undefined8
wlan_antenna_en_write(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  int local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  if (lVar4 == 0) {
    param_4 = 0xffffffffffffffea;
    puVar3 = &DAT_00100848;
  }
  else {
    iVar2 = kstrtouint(param_3,0,&local_2c);
    if (iVar2 != 0) {
      _printk(&DAT_001007f3);
    }
    lVar1 = 0x18;
    if (local_2c != 1) {
      lVar1 = 0x20;
    }
    iVar2 = pinctrl_select_state(*(undefined8 *)(lVar4 + 8),*(undefined8 *)(lVar4 + lVar1));
    if (iVar2 == 0) goto LAB_00100428;
    puVar3 = &DAT_001008ab;
  }
  _printk(puVar3);
LAB_00100428:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
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
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00102018 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 00102020 size=1
// signature: undefined gpio_request(void)
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00102028 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00102030 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00102038 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [wlan_antenna_en_write, wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102040 size=1
// signature: undefined _printk(void)
// callers: [wlan_antenna_en_write, wlan_antenna_en_read, wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00102048 size=1
// signature: undefined sysfs_create_group(void)
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102050 size=1
// signature: undefined _dev_info(void)
// callers: [wlan_antenna_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00102058 size=1
// signature: undefined gpio_to_desc(void)
// callers: [wlan_antenna_en_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00102060 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [wlan_antenna_en_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00102068 size=1
// signature: undefined kstrtouint(void)
// callers: [wlan_antenna_en_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wlan_antenna_en_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



