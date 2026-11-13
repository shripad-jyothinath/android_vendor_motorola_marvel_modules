// Decompiled by Ghidra 12.2
// Program: qcom-pon.ko
// Image base: 00100000

//------------------------------------------------------------
// pm8916_pon_probe @ 001000ec size=260
// signature: undefined pm8916_pon_probe(void)
// callers: []
//------------------------------------------------------------

int pm8916_pon_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar1 = param_1 + 0x10;
  plVar3 = (long *)devm_kmalloc(lVar1,0x58,0xdc0);
  if (plVar3 == (long *)0x0) {
    iVar2 = -0xc;
  }
  else {
    uVar4 = *(undefined8 *)(param_1 + 0x70);
    *plVar3 = lVar1;
    lVar5 = dev_get_regmap(uVar4,0);
    plVar3[1] = lVar5;
    if (lVar5 == 0) {
      _dev_err(lVar1,"failed to locate regmap\n");
      iVar2 = -0x13;
    }
    else {
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),&DAT_00100973,plVar3 + 2,1,0);
      if (-1 < iVar2) {
        plVar3[3] = lVar1;
        lVar5 = of_device_get_match_data(lVar1);
        plVar3[10] = lVar5;
        plVar3[6] = (long)pm8916_reboot_mode_write;
        iVar2 = devm_reboot_mode_register(lVar1,plVar3 + 3);
        if (iVar2 == 0) {
          *(long **)(param_1 + 0xa8) = plVar3;
          iVar2 = devm_of_platform_populate(lVar1);
        }
        else {
          _dev_err(lVar1,"can\'t register reboot mode\n");
        }
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8916_reboot_mode_write @ 001001f4 size=120
// signature: undefined pm8916_reboot_mode_write(void)
// callers: []
//------------------------------------------------------------

int pm8916_reboot_mode_write(long param_1,int param_2)

{
  int iVar1;
  
  iVar1 = regmap_update_bits_base
                    (*(undefined8 *)(param_1 + -0x10),*(int *)(param_1 + -8) + 0x8f,
                     (uint)(-1L << (*(ulong *)(param_1 + 0x38) & 0x3f)) & 0xff,
                     param_2 << (ulong)((uint)*(ulong *)(param_1 + 0x38) & 0x1f),0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x18),"update reboot mode bits failed\n");
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00100270 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pm8916_pon_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001002a0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pm8916_pon_driver);
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
// callers: [pm8916_pon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00102018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [pm8916_pon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [pm8916_pon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00102028 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [pm8916_pon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_reboot_mode_register @ 00102030 size=1
// signature: undefined devm_reboot_mode_register(void)
// callers: [pm8916_pon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_reboot_mode_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_platform_populate @ 00102038 size=1
// signature: undefined devm_of_platform_populate(void)
// callers: [pm8916_pon_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102040 size=1
// signature: undefined _dev_err(void)
// callers: [pm8916_pon_probe, pm8916_reboot_mode_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00102048 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [pm8916_reboot_mode_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



