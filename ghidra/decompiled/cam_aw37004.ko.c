// Decompiled by Ghidra 12.2
// Program: cam_aw37004.ko
// Image base: 00100000

//------------------------------------------------------------
// aw37004_i2c_probe @ 001001cc size=1712
// signature: undefined aw37004_i2c_probe(void)
// callers: []
//------------------------------------------------------------

ulong aw37004_i2c_probe(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  long *plVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  char *pcVar12;
  undefined **ppuVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  ulong uVar16;
  undefined4 local_a4;
  long local_a0 [2];
  long *local_90;
  undefined8 uStack_88;
  long local_80;
  undefined8 uStack_78;
  undefined1 local_6c [4];
  long local_68;
  
  lVar9 = sp_el0;
  lVar10 = param_1 + 0x20;
  local_68 = *(long *)(lVar9 + 0x638);
  local_a4 = 0;
  plVar7 = (long *)devm_kmalloc(lVar10,0x60,0xdc0);
  if (plVar7 == (long *)0x0) {
LAB_00100874:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(1,0x100878);
    (*pcVar4)();
  }
  _dev_info(*plVar7,"aw37004_i2c_probe Enter...\n");
  uVar5 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x308),"cs-gpios",0,0);
  if (0 < (int)uVar5) {
    if (uVar5 < 0x200) {
      uVar8 = devm_gpio_request_one(lVar10,uVar5,0,"aw37004_cs_pin");
      if ((int)uVar8 == 0) {
        *(uint *)(plVar7 + 10) = uVar5;
        goto LAB_0010027c;
      }
LAB_00100338:
      uVar8 = uVar8 & 0xffffffff;
      _dev_err(lVar10,"GPIO(%d) request failed(%d)\n",uVar5,uVar8);
      goto LAB_001006ec;
    }
    pcVar12 = "Invalid chip select pin\n";
LAB_00100488:
    _dev_err(lVar10,pcVar12);
    uVar8 = 0xffffffff;
    goto LAB_001006ec;
  }
LAB_0010027c:
  _dev_info(*plVar7,"aw37004_i2c_probe cs_gpio:%d...\n",uVar5);
  uVar5 = of_get_named_gpio_flags(*(undefined8 *)(param_1 + 0x308),"vin1-gpios",0,0);
  if (0 < (int)uVar5) {
    if (0x1ff < uVar5) {
      pcVar12 = "Invalid vin1 select pin\n";
      goto LAB_00100488;
    }
    uVar8 = devm_gpio_request_one(lVar10,uVar5,2,"aw37004_vin1_pin");
    if ((int)uVar8 != 0) goto LAB_00100338;
    *(uint *)((long)plVar7 + 0x54) = uVar5;
  }
  _dev_info(*plVar7,"aw37004_i2c_probe vin1_gpio:%d...\n",uVar5);
  iVar6 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x308),"init-value",&local_a4,1,0);
  if (iVar6 < 0) {
    _dev_info(*plVar7,"aw37004_i2c_probe no init_value, use default 0x0\n");
    local_a4 = 0;
  }
  *(undefined4 *)(plVar7 + 0xb) = local_a4;
  _dev_info(*plVar7,"aw37004_i2c_probe init_value:%d...\n");
  lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x308),"shutdown-ldo",0);
  *(bool *)((long)plVar7 + 0x5c) = lVar9 != 0;
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  __const_udelay(0x418958);
  *(long **)(param_1 + 0xb8) = plVar7;
  *plVar7 = lVar10;
  uVar8 = __devm_regmap_init_i2c(param_1,aw37004_regmap_config,0,0);
  plVar7[1] = uVar8;
  if (0xfffffffffffff000 < uVar8) {
    _dev_err(lVar10,"Failed to allocate register map: %d\n",uVar8 & 0xffffffff);
    goto LAB_001006ec;
  }
  iVar6 = regmap_read(uVar8,0,&ldo_chipid);
  if (iVar6 < 0) {
    pcVar12 = "Failed to read CHIP ID:0x%x, ret:%d\n";
LAB_00100504:
    _dev_err(lVar10,pcVar12);
    uVar8 = 0xffffffed;
    goto LAB_001006ec;
  }
  if (ldo_chipid == 0x33) {
    lVar10 = *plVar7;
    pcVar12 = "WL28661D CHIP ID matched!\n";
LAB_001004f4:
    _dev_info(lVar10,pcVar12,ldo_chipid,iVar6);
  }
  else {
    if (ldo_chipid != 0) {
      pcVar12 = "CHIP ID not mactched:0x%x, maybe other ic, ret:%d\n";
      goto LAB_00100504;
    }
    _dev_info(*plVar7,"COMMON CHIP ID matched!\n",0,iVar6);
    iVar6 = regmap_read(plVar7[1],0x19,&ldo_chipid);
    if ((-1 < iVar6) && (ldo_chipid == 4)) {
      lVar10 = *plVar7;
      pcVar12 = "AW37004 CHIP ID2 matched!\n";
      goto LAB_001004f4;
    }
    _dev_err(lVar10,"CHIP ID2 not mactched:0x%x, maybe other ic, ret:%d\n",ldo_chipid,iVar6);
  }
  iVar6 = regmap_write(plVar7[1],1,0);
  if (iVar6 < 0) {
    _dev_err(*plVar7,"Failed to write register: 0x%x, value: 0x%x \n",1,0);
  }
  _dev_info(*plVar7,"Success to write register: 0x%x, value: 0x%x \n",1,0);
  iVar6 = regmap_write(plVar7[1],2,0);
  if (iVar6 < 0) {
    _dev_err(*plVar7,"Failed to write register: 0x%x, value: 0x%x \n",2,0);
  }
  _dev_info(*plVar7,"Success to write register: 0x%x, value: 0x%x \n",2,0);
  iVar6 = regmap_write(plVar7[1],10,0);
  if (iVar6 < 0) {
    _dev_err(*plVar7,"Failed to write register: 0x%x, value: 0x%x \n",10,0);
  }
  _dev_info(*plVar7,"Success to write register: 0x%x, value: 0x%x \n",10,0);
  iVar6 = regmap_write(plVar7[1],0xb,0);
  if (iVar6 < 0) {
    _dev_err(*plVar7,"Failed to write register: 0x%x, value: 0x%x \n",0xb,0);
  }
  _dev_info(*plVar7,"Success to write register: 0x%x, value: 0x%x \n",0xb,0);
  iVar6 = regmap_write(plVar7[1],0xf,0);
  if (iVar6 < 0) {
    _dev_err(*plVar7,"Failed to write register: 0x%x, value: 0x%x \n",0xf,0);
  }
  _dev_info(*plVar7,"Success to write register: 0x%x, value: 0x%x \n",0xf,0);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = (long *)0x0;
  uStack_88 = 0;
  local_a0[1] = 0;
  local_6c[0] = 0;
  uVar5 = regmap_write(plVar7[1],0xe,(int)plVar7[0xb]);
  if ((int)uVar5 < 0) {
    uVar8 = (ulong)uVar5;
    pcVar12 = "Disable all LDO output failed!!!\n";
LAB_001006cc:
    _dev_err(*plVar7,pcVar12);
  }
  else {
    uVar5 = regmap_write(plVar7[1],2,0x8f);
    if ((int)uVar5 < 0) {
      uVar8 = (ulong)uVar5;
      pcVar12 = "Enable LDO discharge failed!!!\n";
      goto LAB_001006cc;
    }
    puVar15 = &DAT_00101d64;
    puVar14 = &DAT_00101d54;
    ppuVar13 = &aw37004_regls_desc;
    pcVar12 = "Failed to read the ldo register\n";
    uVar16 = 0;
    lVar10 = 0x30;
    do {
      lVar9 = lVar10;
      if (lVar9 == 0x50) {
        uVar8 = 0;
        goto LAB_00100848;
      }
      *(undefined ***)((long)plVar7 + lVar9 + -0x20) = ppuVar13;
      local_a0[0] = *plVar7;
      local_80 = plVar7[1];
      local_90 = plVar7;
      if ((uVar16 & 0x3fffffffffffffff) == 4) goto LAB_00100874;
      uVar2 = *puVar14;
      uVar11 = regmap_bulk_read(local_80,uVar2,local_6c,1);
      uVar1 = uVar16 + 1;
      uVar8 = uVar11 & 0xffffffff;
      _printk(&DAT_00101ab2,uVar1 & 0xffffffff,local_6c[0]);
      if ((int)uVar11 < 0) goto LAB_001006cc;
      if ((uVar16 & 0x3fffffffffffffff) == 4) goto LAB_00100874;
      uVar3 = *puVar15;
      uVar5 = regmap_write(plVar7[1],uVar2,uVar3);
      if ((int)uVar5 < 0) {
        uVar8 = (ulong)uVar5;
        pcVar12 = "Failed to write inital voltage register\n";
        goto LAB_001006cc;
      }
      _printk(&DAT_001018f4,uVar1 & 0xffffffff,uVar3);
      uVar8 = devm_regulator_register(*plVar7,ppuVar13,local_a0);
      puVar15 = puVar15 + 1;
      puVar14 = puVar14 + 1;
      *(ulong *)((long)plVar7 + lVar9) = uVar8;
      ppuVar13 = ppuVar13 + 0x27;
      uVar16 = uVar1;
      lVar10 = lVar9 + 8;
    } while (uVar8 < 0xfffffffffffff001);
    _dev_err(*plVar7,"Failed to register regulator(%s):%d\n",
             **(undefined8 **)((long)plVar7 + lVar9 + -0x20),uVar8 & 0xffffffff);
    if (-1 < (int)uVar8) {
LAB_00100848:
      aw37004_get_current_limit(plVar7[6]);
      _dev_info(*plVar7,"aw37004_i2c_probe Exit...\n");
      goto LAB_001006ec;
    }
  }
  _dev_err(*plVar7,"Failed to init regulator(%d)\n",uVar8 & 0xffffffff);
LAB_001006ec:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// aw37004_i2c_remove @ 00100880 size=136
// signature: undefined aw37004_i2c_remove(void)
// callers: []
//------------------------------------------------------------

void aw37004_i2c_remove(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0xb8);
  if (0 < *(int *)(puVar4 + 10)) {
    uVar2 = gpio_to_desc();
    iVar1 = gpiod_direction_output_raw(uVar2,0);
    if (iVar1 != 0) {
      uVar2 = *puVar4;
      pcVar3 = "aw37004_i2c_remove cs-pin output %d\n";
      goto LAB_00100900;
    }
  }
  if (*(int *)((long)puVar4 + 0x54) < 1) {
    return;
  }
  uVar2 = gpio_to_desc();
  iVar1 = gpiod_direction_output_raw(uVar2,0);
  if (iVar1 == 0) {
    return;
  }
  uVar2 = *puVar4;
  pcVar3 = "aw37004_i2c_remove vin1-pin output %d\n";
LAB_00100900:
  _dev_err(uVar2,pcVar3,iVar1);
  return;
}



//------------------------------------------------------------
// aw37004_i2c_shutdown @ 0010090c size=188
// signature: undefined aw37004_i2c_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw37004_i2c_shutdown(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar2 = *(undefined8 **)(param_1 + 0xb8);
  local_2c = 0;
  if (*(char *)((long)puVar2 + 0x5c) != '\0') {
    regmap_read(puVar2[1],0xe,&local_2c);
    regmap_write(puVar2[1],0xe,local_2c & 0xfffffffb);
    _dev_info(*puVar2,"aw37004_i2c_shutdown");
  }
  if (puVar2 != (undefined8 *)0x0) {
    regmap_write(puVar2[1],0xe,0);
    _dev_err(*puVar2,"aw37004_i2c_shutdown force disable all LDOs");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw37004_get_current_limit @ 001009cc size=300
// signature: undefined aw37004_get_current_limit(void)
// callers: [aw37004_get_status, aw37004_i2c_probe]
//------------------------------------------------------------

undefined8 aw37004_get_current_limit(undefined8 *param_1)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar2 = (undefined8 *)rdev_get_drvdata();
  local_3c = 0;
  if (aw37004_debug != 0) {
    _dev_err(*puVar2,"************ start dump aw37004 register ************\n");
    _dev_err(*puVar2,"register name =%s \n",*(undefined8 *)*param_1);
    _dev_err(*puVar2,"register 0x00:      chip version\n");
    _dev_err(*puVar2,"register 0x01:      LDO CL\n");
    _dev_err(*puVar2,"register 0x03~0x06: LDO1~LDO4 OUT Voltage\n");
    _dev_err(*puVar2,"register 0x0e:      Bit[3:0] LDO4~LDO1 EN\n");
    iVar3 = 0;
    do {
      regmap_read(puVar2[1],iVar3,&local_3c);
      _dev_err(*puVar2,"Reg[0x%02x] = 0x%x",iVar3,(undefined1)local_3c);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 0x1a);
    _dev_err(*puVar2,"************ end dump aw37004 register ************\n");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw37004_of_parse_cb @ 00100afc size=76
// signature: undefined aw37004_of_parse_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 aw37004_of_parse_cb(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = of_get_named_gpio_flags(param_1,"enable-gpios",0,0);
  if (uVar1 < 0x200) {
    uVar2 = gpio_to_desc();
    *(undefined8 *)(param_3 + 0x28) = uVar2;
  }
  return 0;
}



//------------------------------------------------------------
// aw37004_get_status @ 00100b4c size=220
// signature: undefined aw37004_get_status(void)
// callers: []
//------------------------------------------------------------

uint aw37004_get_status(undefined8 param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar3 = (undefined8 *)rdev_get_drvdata();
  uVar4 = rdev_get_id(param_1);
  local_3c = 0;
  uVar2 = regulator_is_enabled_regmap(param_1);
  if ((int)uVar2 < 0) {
    uVar5 = *puVar3;
    pcVar6 = "Failed to read enable register(%d)\n";
  }
  else {
    if (uVar2 == 0) goto LAB_00100bc8;
    aw37004_get_current_limit(param_1);
    uVar2 = regmap_read(puVar3[1],0xe,&local_3c);
    if (-1 < (int)uVar2) {
      uVar2 = local_3c >> (uVar4 & 0x3f) & 1;
      goto LAB_00100bc8;
    }
    uVar5 = *puVar3;
    pcVar6 = "Failed to read status register(%d)\n";
  }
  _dev_err(uVar5,pcVar6,uVar2);
LAB_00100bc8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00100c2c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&aw37004_regulator_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100c5c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&aw37004_regulator_driver);
  return;
}



//------------------------------------------------------------
// i2c_register_driver @ 00103000 size=1
// signature: undefined i2c_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 00103008 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103018 size=1
// signature: undefined _dev_info(void)
// callers: [aw37004_i2c_shutdown, aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00103020 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [aw37004_i2c_probe, aw37004_of_parse_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 00103028 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103030 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103038 size=1
// signature: undefined _dev_err(void)
// callers: [aw37004_get_status, aw37004_get_current_limit, aw37004_i2c_shutdown, aw37004_i2c_probe, aw37004_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103040 size=1
// signature: undefined of_find_property(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00103048 size=1
// signature: undefined __const_udelay(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_i2c @ 00103050 size=1
// signature: undefined __devm_regmap_init_i2c(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_i2c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00103058 size=1
// signature: undefined regmap_read(void)
// callers: [aw37004_get_status, aw37004_get_current_limit, aw37004_i2c_shutdown, aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00103060 size=1
// signature: undefined regmap_write(void)
// callers: [aw37004_i2c_shutdown, aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00103068 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103070 size=1
// signature: undefined _printk(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00103078 size=1
// signature: undefined devm_regulator_register(void)
// callers: [aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [aw37004_get_status, aw37004_get_current_limit, aw37004_i2c_shutdown, aw37004_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00103088 size=1
// signature: undefined gpio_to_desc(void)
// callers: [aw37004_of_parse_cb, aw37004_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00103090 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [aw37004_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00103098 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [aw37004_get_status, aw37004_get_current_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_id @ 001030a0 size=1
// signature: undefined rdev_get_id(void)
// callers: [aw37004_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled_regmap @ 001030a8 size=1
// signature: undefined regulator_is_enabled_regmap(void)
// callers: [aw37004_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



