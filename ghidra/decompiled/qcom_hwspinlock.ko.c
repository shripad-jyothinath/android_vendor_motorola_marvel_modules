// Decompiled by Ghidra 12.2
// Program: qcom_hwspinlock.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_hwspinlock_bust @ 0010016c size=212
// signature: undefined qcom_hwspinlock_bust(void)
// callers: []
//------------------------------------------------------------

int qcom_hwspinlock_bust(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined8 uVar5;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x10);
  local_3c = 0;
  iVar2 = regmap_field_read(uVar5,&local_3c);
  if (iVar2 == 0) {
    if (local_3c != param_2) {
      iVar4 = 0;
      goto LAB_001001f0;
    }
    iVar2 = regmap_field_update_bits_base(uVar5,0xffffffff,0,0,0,0);
    iVar4 = 0;
    if (iVar2 == 0) goto LAB_001001f0;
    puVar3 = &DAT_001006de;
  }
  else {
    puVar3 = &DAT_00100691;
  }
  _printk(puVar3,"qcom_hwspinlock_bust");
  iVar4 = iVar2;
LAB_001001f0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qcom_hwspinlock_probe @ 00100244 size=536
// signature: undefined qcom_hwspinlock_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_hwspinlock_probe(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 *puVar4;
  long lVar5;
  undefined8 uVar6;
  char *pcVar7;
  long lVar8;
  long lVar9;
  undefined8 local_b0;
  int local_a8;
  undefined4 uStack_a4;
  undefined4 local_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_b0 = 0;
  local_a8 = 0;
  uStack_a4 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_94 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  uStack_9c = 0;
  iVar2 = __of_parse_phandle_with_args(*(undefined8 *)(param_1 + 0x2f8),"syscon",0,0,0,&local_a8);
  if ((iVar2 == 0) && (CONCAT44(uStack_a4,local_a8) != 0)) {
    uVar3 = syscon_node_to_regmap();
    if (uVar3 < 0xfffffffffffff001) {
      iVar2 = of_property_read_u32_index(*(undefined8 *)(param_1 + 0x2f8),"syscon",1,&local_b0);
      if (iVar2 < 0) {
        pcVar7 = "no offset in syscon\n";
      }
      else {
        iVar2 = of_property_read_u32_index
                          (*(undefined8 *)(param_1 + 0x2f8),"syscon",2,(long)&local_b0 + 4);
        if (-1 < iVar2) goto LAB_00100364;
        pcVar7 = "no stride syscon\n";
      }
      _dev_err(lVar1,pcVar7);
      uVar3 = 0xffffffffffffffea;
      goto LAB_001003fc;
    }
    if (uVar3 == 0xffffffffffffffed) goto LAB_001002d4;
  }
  else {
LAB_001002d4:
    puVar4 = (undefined8 *)of_device_get_match_data(lVar1);
    if (puVar4[1] == 0) {
      uVar3 = 0xffffffffffffffea;
      goto LAB_001003fc;
    }
    local_b0 = *puVar4;
    uVar3 = devm_platform_ioremap_resource(param_1,0);
    if (uVar3 < 0xfffffffffffff001) {
      uVar3 = __devm_regmap_init_mmio_clk(lVar1,0,uVar3,puVar4[1],0,0);
    }
  }
LAB_00100364:
  if (uVar3 < 0xfffffffffffff001) {
    lVar5 = devm_kmalloc(lVar1,0x318,0xdc0);
    if (lVar5 == 0) {
      uVar3 = 0xfffffff4;
    }
    else {
      lVar8 = 0;
      lVar9 = 0x28;
      *(long *)(param_1 + 0xa8) = lVar5;
      do {
        uStack_a4 = 0;
        local_a0 = 0x1f;
        uStack_9c = 0;
        local_98 = 0;
        local_a8 = (int)local_b0 + local_b0._4_4_ * (int)lVar8;
        uVar6 = devm_regmap_field_alloc(lVar1,uVar3,&local_a8);
        lVar8 = lVar8 + 1;
        *(undefined8 *)(lVar5 + lVar9) = uVar6;
        lVar9 = lVar9 + 0x18;
      } while (lVar8 != 0x20);
      uVar3 = devm_hwspin_lock_register(lVar1,lVar5,&qcom_hwspinlock_ops,0,0x20);
      uVar3 = uVar3 & 0xffffffff;
    }
  }
LAB_001003fc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_hwspinlock_trylock @ 00100460 size=144
// signature: undefined qcom_hwspinlock_trylock(void)
// callers: []
//------------------------------------------------------------

void qcom_hwspinlock_trylock(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  local_2c = 0;
  uVar2 = regmap_field_update_bits_base(uVar3,0xffffffff,1,0,0,0);
  if (((int)uVar2 == 0) && (uVar2 = regmap_field_read(uVar3,&local_2c), (int)uVar2 == 0)) {
    uVar2 = (ulong)(local_2c == 1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_hwspinlock_unlock @ 001004f4 size=204
// signature: undefined qcom_hwspinlock_unlock(void)
// callers: []
//------------------------------------------------------------

void qcom_hwspinlock_unlock(long param_1)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x10);
  local_2c = 0;
  iVar2 = regmap_field_read(uVar4,&local_2c);
  if (iVar2 == 0) {
    if (local_2c != 1) {
      _printk(&DAT_00100640,"qcom_hwspinlock_unlock");
    }
    iVar2 = regmap_field_update_bits_base(uVar4,0xffffffff,0,0,0,0);
    if (iVar2 == 0) goto LAB_00100558;
    puVar3 = &DAT_001006fd;
  }
  else {
    puVar3 = &DAT_00100691;
  }
  _printk(puVar3,"qcom_hwspinlock_unlock");
LAB_00100558:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001005dc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_hwspinlock_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010060c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_hwspinlock_driver);
  return;
}



//------------------------------------------------------------
// regmap_field_read @ 00102000 size=1
// signature: undefined regmap_field_read(void)
// callers: [qcom_hwspinlock_trylock, qcom_hwspinlock_unlock, qcom_hwspinlock_bust]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_field_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_field_update_bits_base @ 00102008 size=1
// signature: undefined regmap_field_update_bits_base(void)
// callers: [qcom_hwspinlock_trylock, qcom_hwspinlock_unlock, qcom_hwspinlock_bust]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_field_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102010 size=1
// signature: undefined _printk(void)
// callers: [qcom_hwspinlock_unlock, qcom_hwspinlock_bust]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_hwspinlock_probe, qcom_hwspinlock_trylock, qcom_hwspinlock_unlock, qcom_hwspinlock_bust]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00102020 size=1
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
// platform_driver_unregister @ 00102028 size=1
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
// __of_parse_phandle_with_args @ 00102030 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_node_to_regmap @ 00102038 size=1
// signature: undefined syscon_node_to_regmap(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_node_to_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00102040 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 00102048 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_mmio_clk @ 00102050 size=1
// signature: undefined __devm_regmap_init_mmio_clk(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_mmio_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00102058 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102060 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_field_alloc @ 00102068 size=1
// signature: undefined devm_regmap_field_alloc(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_field_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_hwspin_lock_register @ 00102070 size=1
// signature: undefined devm_hwspin_lock_register(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_hwspin_lock_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102078 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_hwspinlock_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



