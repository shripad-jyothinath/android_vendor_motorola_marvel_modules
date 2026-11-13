// Decompiled by Ghidra 12.2
// Program: clk-dummy.ko
// Image base: 00100000

//------------------------------------------------------------
// dummy_clk_recalc_rate @ 0010015c size=8
// signature: undefined dummy_clk_recalc_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_clk_recalc_rate(long param_1)

{
  return *(undefined8 *)(param_1 + 0x70);
}



//------------------------------------------------------------
// dummy_clk_round_rate @ 00100168 size=8
// signature: undefined dummy_clk_round_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_clk_round_rate(undefined8 param_1,undefined8 param_2)

{
  return param_2;
}



//------------------------------------------------------------
// dummy_clk_set_rate @ 00100174 size=16
// signature: undefined dummy_clk_set_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_clk_set_rate(long param_1,undefined8 param_2)

{
  *(undefined8 *)(param_1 + 0x70) = param_2;
  return 0;
}



//------------------------------------------------------------
// dummy_clk_probe @ 00100188 size=376
// signature: undefined dummy_clk_probe(void)
// callers: []
//------------------------------------------------------------

ulong dummy_clk_probe(long param_1)

{
  long lVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  char *local_88;
  char *local_80;
  undefined1 *puStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  ulong local_58;
  undefined8 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar5 + 0x638);
  uVar7 = *(undefined8 *)(param_1 + 0x2f8);
  local_88 = "dummy_clk";
  of_property_read_string(uVar7,"clock-output-names",&local_88);
  pcVar3 = local_88;
  local_60 = 0;
  local_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  lVar5 = devm_kmalloc(lVar1,0x78,0xdc0);
  if (lVar5 == 0) {
    uVar8 = 0xfffffff4;
  }
  else {
    local_50 = 0;
    local_58 = local_58 & 0xffffffffffffff00;
    local_80 = pcVar3;
    puStack_78 = &clk_dummy_ops;
    *(char ***)(lVar5 + 0x10) = &local_80;
    uVar8 = devm_clk_register(lVar1,lVar5);
    if (uVar8 < 0xfffffffffffff001) {
      *(undefined8 *)(lVar5 + 0x18) = dummy_reset_ops;
      *(undefined8 *)(lVar5 + 0x50) = uVar7;
      *(undefined4 *)(lVar5 + 0x68) = 100;
      iVar4 = devm_reset_controller_register(lVar1,(undefined8 *)(lVar5 + 0x18));
      puVar2 = &DAT_0010082a;
      if (iVar4 != 0) {
        puVar2 = &DAT_001008f3;
      }
      _printk(puVar2,pcVar3);
      uVar6 = of_clk_add_provider(uVar7,&of_clk_src_simple_get,uVar8);
      uVar8 = uVar6 & 0xffffffff;
      if ((int)uVar6 == 0) {
        _dev_info(lVar1,"Successfully registered dummy clock controller for %s\n",local_88);
      }
      goto LAB_001002b0;
    }
  }
  _printk(&DAT_0010089a,local_88,uVar8 & 0xffffffff);
LAB_001002b0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// dummy_clk_remove @ 00100304 size=36
// signature: undefined dummy_clk_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_clk_remove(long param_1)

{
  of_clk_del_provider(*(undefined8 *)(param_1 + 0x2f8));
  return 0;
}



//------------------------------------------------------------
// dummy_reset_assert @ 0010032c size=8
// signature: undefined dummy_reset_assert(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_reset_assert(void)

{
  return 0;
}



//------------------------------------------------------------
// dummy_reset_deassert @ 00100338 size=8
// signature: undefined dummy_reset_deassert(void)
// callers: []
//------------------------------------------------------------

undefined8 dummy_reset_deassert(void)

{
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100354 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&dummy_clk_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100384 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&dummy_clk_driver);
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
// of_property_read_string @ 00102010 size=1
// signature: undefined of_property_read_string(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_register @ 00102020 size=1
// signature: undefined devm_clk_register(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102028 size=1
// signature: undefined _printk(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_reset_controller_register @ 00102030 size=1
// signature: undefined devm_reset_controller_register(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_reset_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_clk_add_provider @ 00102040 size=1
// signature: undefined of_clk_add_provider(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_clk_add_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102048 size=1
// signature: undefined _dev_info(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [dummy_clk_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_clk_del_provider @ 00102058 size=1
// signature: undefined of_clk_del_provider(void)
// callers: [dummy_clk_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_clk_del_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



