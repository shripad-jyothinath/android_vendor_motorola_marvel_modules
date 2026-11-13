// Decompiled by Ghidra 12.2
// Program: repeater.ko
// Image base: 00100000

//------------------------------------------------------------
// usb_put_repeater @ 00100274 size=76
// signature: undefined usb_put_repeater(void)
// callers: []
//------------------------------------------------------------

void usb_put_repeater(long *param_1)

{
  if ((param_1 != (long *)0x0) && (*param_1 != 0)) {
    put_device();
    if ((*(long *)(*param_1 + 0x88) != 0) && (*(long *)(*(long *)(*param_1 + 0x88) + 0x10) != 0)) {
      module_put();
    }
  }
  return;
}



//------------------------------------------------------------
// devm_usb_get_repeater_by_node @ 001002c4 size=272
// signature: undefined devm_usb_get_repeater_by_node(void)
// callers: [devm_usb_get_repeater_by_phandle, devm_usb_get_optional_repeater_by_phandle]
//------------------------------------------------------------

undefined ** devm_usb_get_repeater_by_node(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  lVar1 = __devres_alloc_node(devm_usb_repeater_release_by_node,0x58,0xcc0,0xffffffff,
                              "devm_usb_repeater_release_by_node");
  if (lVar1 == 0) {
    return (undefined **)0xfffffffffffffff4;
  }
  uVar2 = _raw_spin_lock_irqsave(&repeater_lock);
  uVar3 = of_device_is_available(param_2);
  if ((uVar3 & 1) == 0) {
    ppuVar5 = (undefined **)0xffffffffffffffed;
  }
  else {
    ppuVar4 = &repeater_list;
    do {
      ppuVar4 = (undefined **)*ppuVar4;
      if (ppuVar4 == &repeater_list) {
        ppuVar5 = (undefined **)0xfffffffffffffdfb;
        goto LAB_00100394;
      }
    } while (*(long *)(ppuVar4[-3] + 0x2e8) != param_2);
    ppuVar5 = ppuVar4 + -3;
    if (ppuVar5 < (undefined **)0xfffffffffffff001) {
      uVar3 = try_module_get(*(undefined8 *)(*(long *)(ppuVar4[-3] + 0x88) + 0x10));
      if ((uVar3 & 1) == 0) {
        devres_free(lVar1);
        ppuVar5 = (undefined **)0xffffffffffffffed;
      }
      else {
        devres_add(param_1,lVar1);
        get_device(*ppuVar5);
      }
      goto LAB_0010039c;
    }
  }
LAB_00100394:
  devres_free(lVar1);
LAB_0010039c:
  _raw_spin_unlock_irqrestore(&repeater_lock,uVar2);
  return ppuVar5;
}



//------------------------------------------------------------
// devm_usb_repeater_release_by_node @ 001003d8 size=76
// signature: undefined devm_usb_repeater_release_by_node(void)
// callers: []
//------------------------------------------------------------

void devm_usb_repeater_release_by_node(undefined8 param_1,long *param_2)

{
  if ((param_2 != (long *)0x0) && (*param_2 != 0)) {
    put_device();
    if ((*(long *)(*param_2 + 0x88) != 0) && (*(long *)(*(long *)(*param_2 + 0x88) + 0x10) != 0)) {
      module_put();
    }
  }
  return;
}



//------------------------------------------------------------
// devm_usb_get_repeater_by_phandle @ 00100428 size=164
// signature: undefined devm_usb_get_repeater_by_phandle(void)
// callers: []
//------------------------------------------------------------

void devm_usb_get_repeater_by_phandle(long param_1,undefined8 param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long local_78 [11];
  
  lVar1 = sp_el0;
  local_78[10] = *(long *)(lVar1 + 0x638);
  if (*(long *)(param_1 + 0x2e8) == 0) {
    uVar3 = 0xffffffffffffffea;
  }
  else {
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[0] = 0;
    local_78[1] = 0;
    iVar2 = __of_parse_phandle_with_args(*(long *)(param_1 + 0x2e8),param_2,0,0,param_3,local_78);
    uVar3 = 0xffffffffffffffed;
    if ((iVar2 == 0) && (local_78[0] != 0)) {
      uVar3 = devm_usb_get_repeater_by_node(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// devm_usb_get_optional_repeater_by_phandle @ 001004d0 size=164
// signature: undefined devm_usb_get_optional_repeater_by_phandle(void)
// callers: []
//------------------------------------------------------------

void devm_usb_get_optional_repeater_by_phandle(long param_1,undefined8 param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long local_78 [11];
  
  lVar1 = sp_el0;
  local_78[10] = *(long *)(lVar1 + 0x638);
  if (*(long *)(param_1 + 0x2e8) == 0) {
    uVar3 = 0xffffffffffffffea;
  }
  else {
    local_78[8] = 0;
    local_78[9] = 0;
    local_78[6] = 0;
    local_78[7] = 0;
    local_78[4] = 0;
    local_78[5] = 0;
    local_78[2] = 0;
    local_78[3] = 0;
    local_78[0] = 0;
    local_78[1] = 0;
    iVar2 = __of_parse_phandle_with_args(*(long *)(param_1 + 0x2e8),param_2,0,0,param_3,local_78);
    uVar3 = 0;
    if ((iVar2 == 0) && (local_78[0] != 0)) {
      uVar3 = devm_usb_get_repeater_by_node(param_1);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// usb_get_repeater_by_node @ 00100578 size=144
// signature: undefined usb_get_repeater_by_node(void)
// callers: []
//------------------------------------------------------------

undefined ** usb_get_repeater_by_node(long param_1)

{
  undefined8 uVar1;
  ulong uVar2;
  undefined **ppuVar3;
  
  uVar1 = _raw_spin_lock_irqsave(&repeater_lock);
  uVar2 = of_device_is_available(param_1);
  if ((uVar2 & 1) == 0) {
    ppuVar3 = (undefined **)0xffffffffffffffed;
  }
  else {
    ppuVar3 = &repeater_list;
    do {
      ppuVar3 = (undefined **)*ppuVar3;
      if (ppuVar3 == &repeater_list) {
        ppuVar3 = (undefined **)0xfffffffffffffdfb;
        goto LAB_001005e4;
      }
    } while (*(long *)(ppuVar3[-3] + 0x2e8) != param_1);
    ppuVar3 = ppuVar3 + -3;
  }
LAB_001005e4:
  _raw_spin_unlock_irqrestore(&repeater_lock,uVar1);
  return ppuVar3;
}



//------------------------------------------------------------
// usb_get_repeater_by_phandle @ 0010060c size=256
// signature: undefined usb_get_repeater_by_phandle(void)
// callers: []
//------------------------------------------------------------

undefined ** usb_get_repeater_by_phandle(long param_1,undefined8 param_2,undefined1 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  long local_88 [11];
  
  lVar1 = sp_el0;
  local_88[10] = *(long *)(lVar1 + 0x638);
  if (*(long *)(param_1 + 0x2e8) == 0) {
    ppuVar5 = (undefined **)0xffffffffffffffea;
  }
  else {
    local_88[8] = 0;
    local_88[9] = 0;
    local_88[6] = 0;
    local_88[7] = 0;
    local_88[4] = 0;
    local_88[5] = 0;
    local_88[2] = 0;
    local_88[3] = 0;
    local_88[0] = 0;
    local_88[1] = 0;
    iVar2 = __of_parse_phandle_with_args(*(long *)(param_1 + 0x2e8),param_2,0,0,param_3,local_88);
    lVar1 = local_88[0];
    ppuVar5 = (undefined **)0xffffffffffffffed;
    if ((iVar2 == 0) && (local_88[0] != 0)) {
      uVar3 = _raw_spin_lock_irqsave(&repeater_lock);
      uVar4 = of_device_is_available(lVar1);
      if ((uVar4 & 1) != 0) {
        ppuVar5 = &repeater_list;
        do {
          ppuVar5 = (undefined **)*ppuVar5;
          if (ppuVar5 == &repeater_list) {
            ppuVar5 = (undefined **)0xfffffffffffffdfb;
            goto LAB_001006c8;
          }
        } while (*(long *)(ppuVar5[-3] + 0x2e8) != lVar1);
        ppuVar5 = ppuVar5 + -3;
      }
LAB_001006c8:
      _raw_spin_unlock_irqrestore(&repeater_lock,uVar3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ppuVar5;
}



//------------------------------------------------------------
// usb_add_repeater_dev @ 00100710 size=152
// signature: undefined usb_add_repeater_dev(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_add_repeater_dev(long *param_1)

{
  long *plVar1;
  undefined *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    _printk(&DAT_0010091f);
    uVar4 = 0xffffffea;
  }
  else {
    _raw_spin_lock(&repeater_lock);
    puVar2 = PTR_repeater_list_00100948;
    plVar1 = param_1 + 3;
    uVar3 = __list_add_valid(plVar1,PTR_repeater_list_00100948,&repeater_list);
    if ((uVar3 & 1) != 0) {
      PTR_repeater_list_00100948 = (undefined *)plVar1;
      param_1[3] = (long)&repeater_list;
      param_1[4] = (long)puVar2;
      *(long **)puVar2 = plVar1;
    }
    _raw_spin_unlock(&repeater_lock);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// usb_remove_repeater_dev @ 001007ac size=116
// signature: undefined usb_remove_repeater_dev(void)
// callers: []
//------------------------------------------------------------

void usb_remove_repeater_dev(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  uVar3 = _raw_spin_lock_irqsave(&repeater_lock);
  if (param_1 != 0) {
    uVar4 = __list_del_entry_valid(param_1 + 0x18);
    if ((uVar4 & 1) != 0) {
      lVar1 = *(long *)(param_1 + 0x18);
      plVar2 = *(long **)(param_1 + 0x20);
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *(undefined8 *)(param_1 + 0x18) = 0xdead000000000100;
    *(undefined8 *)(param_1 + 0x20) = 0xdead000000000122;
  }
  _raw_spin_unlock_irqrestore(&repeater_lock,uVar3);
  return;
}



//------------------------------------------------------------
// put_device @ 00102000 size=1
// signature: undefined put_device(void)
// callers: [usb_put_repeater, devm_usb_repeater_release_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 00102008 size=1
// signature: undefined module_put(void)
// callers: [usb_put_repeater, devm_usb_repeater_release_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devres_alloc_node @ 00102010 size=1
// signature: undefined __devres_alloc_node(void)
// callers: [devm_usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devres_alloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00102018 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [usb_remove_repeater_dev, devm_usb_get_repeater_by_node, usb_get_repeater_by_phandle, usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00102020 size=1
// signature: undefined of_device_is_available(void)
// callers: [devm_usb_get_repeater_by_node, usb_get_repeater_by_phandle, usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_module_get @ 00102028 size=1
// signature: undefined try_module_get(void)
// callers: [devm_usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_add @ 00102030 size=1
// signature: undefined devres_add(void)
// callers: [devm_usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 00102038 size=1
// signature: undefined get_device(void)
// callers: [devm_usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_free @ 00102040 size=1
// signature: undefined devres_free(void)
// callers: [devm_usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00102048 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [usb_remove_repeater_dev, devm_usb_get_repeater_by_node, usb_get_repeater_by_phandle, usb_get_repeater_by_node]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102050 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [devm_usb_get_repeater_by_phandle, devm_usb_get_optional_repeater_by_phandle, usb_get_repeater_by_phandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [devm_usb_get_repeater_by_phandle, devm_usb_get_optional_repeater_by_phandle, usb_get_repeater_by_phandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00102060 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [usb_add_repeater_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102068 size=1
// signature: undefined __list_add_valid(void)
// callers: [usb_add_repeater_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00102070 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [usb_add_repeater_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102078 size=1
// signature: undefined _printk(void)
// callers: [usb_add_repeater_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00102080 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [usb_remove_repeater_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



