// Decompiled by Ghidra 12.2
// Program: mmi_stow.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_stow_probe @ 00100124 size=284
// signature: undefined mmi_stow_probe(void)
// callers: []
//------------------------------------------------------------

int mmi_stow_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  lVar1 = param_1 + 0x10;
  plVar3 = (long *)devm_kmalloc(lVar1,0x10,0xdc0);
  if (plVar3 == (long *)0x0) {
    iVar2 = -0xc;
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x2f8);
    *plVar3 = lVar1;
    *(long **)(param_1 + 0xa8) = plVar3;
    iVar2 = of_get_named_gpio_flags(uVar4,"mmi,stow-gpio",0,0);
    if (iVar2 < 0) {
      _dev_info(lVar1,"can\'t find stow-gpio");
      *(undefined4 *)(plVar3 + 1) = 0;
    }
    else {
      _dev_info(lVar1,"get stow-gpio[%d] from dt",iVar2);
      *(int *)(plVar3 + 1) = iVar2;
      iVar2 = devm_gpio_request(lVar1,iVar2,"mmi-stow-gpio");
      if (iVar2 < 0) {
        pcVar5 = "Failed to request stow-gpio, ret:%d";
      }
      else {
        g_stow_gpio = (undefined4)plVar3[1];
        iVar2 = misc_register(mmi_stow_misc);
        if (iVar2 == 0) {
          _dev_info(lVar1,"probe: All success !\n");
          return 0;
        }
        pcVar5 = "Error registering device %d\n";
      }
      _dev_err(lVar1,pcVar5,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// mmi_stow_remove @ 00100244 size=76
// signature: undefined mmi_stow_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_stow_remove(long param_1)

{
  if (*(uint *)(*(long *)(param_1 + 0xa8) + 8) < 0x200) {
    gpio_free();
  }
  misc_deregister(mmi_stow_misc);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// mmi_stow_show @ 00100294 size=116
// signature: undefined mmi_stow_show(void)
// callers: []
//------------------------------------------------------------

long mmi_stow_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  gpio_to_desc(g_stow_gpio);
  uVar1 = gpiod_get_raw_value();
  _dev_info(param_1,"stowed gpio value %d",uVar1);
  iVar2 = scnprintf(param_3,0x1000,"0x%02x",uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// mmi_stow_store @ 0010030c size=8
// signature: undefined mmi_stow_store(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_stow_store(void)

{
  undefined8 in_x3;
  
  return in_x3;
}



//------------------------------------------------------------
// init_module @ 00100318 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_stow_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100348 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_stow_driver);
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
// callers: [mmi_stow_probe]
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
// callers: [mmi_stow_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102020 size=1
// signature: undefined _dev_info(void)
// callers: [mmi_stow_probe, mmi_stow_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request @ 00102028 size=1
// signature: undefined devm_gpio_request(void)
// callers: [mmi_stow_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 00102030 size=1
// signature: undefined misc_register(void)
// callers: [mmi_stow_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102038 size=1
// signature: undefined _dev_err(void)
// callers: [mmi_stow_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 00102040 size=1
// signature: undefined gpio_free(void)
// callers: [mmi_stow_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 00102048 size=1
// signature: undefined misc_deregister(void)
// callers: [mmi_stow_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00102050 size=1
// signature: undefined gpio_to_desc(void)
// callers: [mmi_stow_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00102058 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [mmi_stow_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00102060 size=1
// signature: undefined scnprintf(void)
// callers: [mmi_stow_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



