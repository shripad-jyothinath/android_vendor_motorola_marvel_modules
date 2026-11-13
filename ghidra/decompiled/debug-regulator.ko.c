// Decompiled by Ghidra 12.2
// Program: debug-regulator.ko
// Image base: 00100000

//------------------------------------------------------------
// regulator_debug_register @ 0010074c size=36
// signature: undefined regulator_debug_register(void)
// callers: []
//------------------------------------------------------------

undefined4 regulator_debug_register(void)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = regulator_debug_add();
  uVar1 = (undefined4)uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// regulator_debug_add @ 00100770 size=644
// signature: undefined regulator_debug_add(void)
// callers: [regulator_debug_register, devm_regulator_debug_register]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * regulator_debug_add(long param_1,long *param_2)

{
  undefined *puVar1;
  bool bVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined4 uVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  
  if ((param_1 == 0) || (param_2 == (long *)0x0)) {
    _printk(&DAT_00102427,"regulator_debug_add");
    return (undefined8 *)0xffffffffffffffea;
  }
  puVar3 = (undefined8 *)kmalloc_trace(_debugfs_create_file,0xdc0,0x28);
  if (puVar3 == (undefined8 *)0x0) {
    return (undefined8 *)0xfffffffffffffff4;
  }
  puVar3[3] = param_1;
  puVar3[4] = param_2;
  mutex_lock(&debug_reg_list_lock);
  puVar1 = debug_reg_list;
  uVar4 = __list_add_valid(puVar3,&debug_reg_list,debug_reg_list);
  if ((uVar4 & 1) != 0) {
    *(undefined8 **)(puVar1 + 8) = puVar3;
    *puVar3 = puVar1;
    puVar3[1] = &debug_reg_list;
    debug_reg_list = (undefined *)puVar3;
  }
  mutex_unlock(&debug_reg_list_lock);
  lVar7 = param_2[0xa5];
  lVar8 = *(long *)(*param_2 + 0x40);
  debugfs_create_file_unsafe("enable",0x1a4,lVar7,puVar3,&reg_enable_fops);
  if (*(long *)(lVar8 + 0xe0) != 0) {
    debugfs_create_file_unsafe("bypass",0x1a4,lVar7,puVar3,&reg_bypass_enable_fops);
  }
  if (*(long *)(lVar8 + 0x78) != 0 || *(long *)(lVar8 + 0x80) != 0) {
    uVar6 = 0;
    if (*(long *)(lVar8 + 0x80) != 0) {
      uVar6 = 0x124;
    }
    if (*(long *)(lVar8 + 0x78) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    debugfs_create_file_unsafe("force_disable",uVar6,lVar7,puVar3,&reg_force_disable_fops);
  }
  if ((*(long *)(lVar8 + 0x20) == 0) && (*(long *)(lVar8 + 0x28) == 0)) {
    uVar6 = 0;
    bVar2 = true;
    if (*(long *)(lVar8 + 8) == 0) goto LAB_001008ac;
LAB_001008d4:
    uVar6 = uVar6 | 0x80;
LAB_001008d8:
    debugfs_create_file_unsafe("voltage",uVar6,lVar7,puVar3,reg_voltage_fops);
  }
  else {
    bVar2 = false;
    uVar6 = 0x124;
    if (*(long *)(lVar8 + 8) != 0) goto LAB_001008d4;
LAB_001008ac:
    if (*(long *)(lVar8 + 0x18) != 0) goto LAB_001008d4;
    if (!bVar2) goto LAB_001008d8;
  }
  if (*(long *)(lVar8 + 0x88) == 0 && *(long *)(lVar8 + 0x90) == 0) {
    bVar2 = true;
    if (*(long *)(lVar8 + 0xd8) == 0) goto LAB_00100958;
LAB_00100968:
    uVar5 = 0x80;
    if (!bVar2) {
      uVar5 = 0x1a4;
    }
  }
  else {
    uVar6 = 0;
    if (*(long *)(lVar8 + 0x90) != 0) {
      uVar6 = 0x124;
    }
    if (*(long *)(lVar8 + 0x88) != 0) {
      uVar6 = uVar6 | 0x80;
    }
    debugfs_create_file_unsafe(&DAT_00102442,uVar6,lVar7,puVar3,&reg_mode_fops);
    bVar2 = *(long *)(lVar8 + 0x90) == 0;
    if (*(long *)(lVar8 + 0xd8) != 0) goto LAB_00100968;
LAB_00100958:
    if ((*(long *)(lVar8 + 0xd0) != 0) && (*(long *)(lVar8 + 0x88) != 0)) goto LAB_00100968;
    if (bVar2) goto LAB_00100994;
    uVar5 = 0x124;
  }
  debugfs_create_file_unsafe(&DAT_0010253c,uVar5,lVar7,puVar3,&reg_set_load_fops);
LAB_00100994:
  debugfs_create_file("consumers",0x124,lVar7,param_2,reg_consumers_fops);
  return puVar3;
}



//------------------------------------------------------------
// regulator_debug_unregister @ 001009f8 size=224
// signature: undefined regulator_debug_unregister(void)
// callers: []
//------------------------------------------------------------

void regulator_debug_unregister(undefined *param_1)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  if ((param_1 == (undefined *)0x0) || ((undefined *)0xfffffffffffff000 < param_1)) {
    _printk(&DAT_001022d4,"regulator_debug_unregister");
  }
  else {
    mutex_lock(&debug_reg_list_lock);
    ppuVar4 = (undefined **)debug_reg_list;
    if ((undefined **)debug_reg_list != &debug_reg_list) {
      do {
        ppuVar5 = (undefined **)*ppuVar4;
        if (ppuVar4[4] == param_1) {
          regulator_put(ppuVar4[2]);
          uVar3 = __list_del_entry_valid(ppuVar4);
          if ((uVar3 & 1) != 0) {
            puVar1 = *ppuVar4;
            plVar2 = (long *)ppuVar4[1];
            *(long **)(puVar1 + 8) = plVar2;
            *plVar2 = (long)puVar1;
          }
          *ppuVar4 = &DAT_dead000000000100;
          ppuVar4[1] = (undefined *)0xdead000000000122;
          kfree(ppuVar4);
        }
        ppuVar4 = ppuVar5;
      } while (ppuVar5 != &debug_reg_list);
    }
    mutex_unlock(&debug_reg_list_lock);
  }
  return;
}



//------------------------------------------------------------
// devm_regulator_debug_register @ 00100adc size=160
// signature: undefined devm_regulator_debug_register(void)
// callers: []
//------------------------------------------------------------

ulong devm_regulator_debug_register(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  ulong uVar2;
  
  puVar1 = (ulong *)__devres_alloc_node(devm_regulator_debug_release,8,0xcc0,0xffffffff,
                                        "devm_regulator_debug_release");
  if (puVar1 == (ulong *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = regulator_debug_add(param_1,param_2);
    if ((uVar2 == 0) || (0xfffffffffffff000 < uVar2)) {
      devres_free(puVar1);
    }
    else {
      *puVar1 = uVar2;
      devres_add(param_1,puVar1);
      uVar2 = 0;
    }
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// devm_regulator_debug_release @ 00100b80 size=156
// signature: undefined devm_regulator_debug_release(void)
// callers: []
//------------------------------------------------------------

void devm_regulator_debug_release(undefined8 param_1,undefined8 *param_2)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  mutex_lock(&debug_reg_list_lock);
  ppuVar5 = (undefined **)*param_2;
  ppuVar4 = &debug_reg_list;
  do {
    ppuVar4 = (undefined **)*ppuVar4;
    if (ppuVar4 == &debug_reg_list) goto LAB_00100c00;
  } while (ppuVar4 != ppuVar5);
  regulator_put(ppuVar5[2]);
  uVar3 = __list_del_entry_valid(ppuVar5);
  if ((uVar3 & 1) != 0) {
    puVar1 = *ppuVar5;
    plVar2 = (long *)ppuVar5[1];
    *(long **)(puVar1 + 8) = plVar2;
    *plVar2 = (long)puVar1;
  }
  *ppuVar5 = &DAT_dead000000000100;
  ppuVar5[1] = (undefined *)0xdead000000000122;
  kfree(ppuVar5);
LAB_00100c00:
  mutex_unlock(&debug_reg_list_lock);
  return;
}



//------------------------------------------------------------
// devm_regulator_debug_unregister @ 00100c20 size=200
// signature: undefined devm_regulator_debug_unregister(void)
// callers: []
//------------------------------------------------------------

void devm_regulator_debug_unregister(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  if ((param_1 == (undefined *)0x0) || ((undefined *)0xfffffffffffff000 < param_1)) {
    _printk(&DAT_001022d4,"devm_regulator_debug_unregister");
  }
  else {
    mutex_lock(&debug_reg_list_lock);
    ppuVar1 = (undefined **)debug_reg_list;
    if ((undefined **)debug_reg_list != &debug_reg_list) {
      do {
        ppuVar2 = (undefined **)*ppuVar1;
        if (ppuVar1[4] == param_1) {
          devres_release(ppuVar1[3],_devm_regulator_debug_release,devm_regulator_debug_match);
        }
        ppuVar1 = ppuVar2;
      } while (ppuVar2 != &debug_reg_list);
    }
    mutex_unlock(&debug_reg_list_lock);
  }
  return;
}



//------------------------------------------------------------
// _devm_regulator_debug_release @ 00100cec size=128
// signature: undefined _devm_regulator_debug_release(void)
// callers: []
//------------------------------------------------------------

void _devm_regulator_debug_release(undefined8 param_1,undefined8 *param_2)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  ppuVar4 = &debug_reg_list;
  ppuVar5 = (undefined **)*param_2;
  do {
    ppuVar4 = (undefined **)*ppuVar4;
    if (ppuVar4 == &debug_reg_list) {
      return;
    }
  } while (ppuVar4 != ppuVar5);
  regulator_put(ppuVar5[2]);
  uVar3 = __list_del_entry_valid(ppuVar5);
  if ((uVar3 & 1) != 0) {
    puVar1 = *ppuVar5;
    plVar2 = (long *)ppuVar5[1];
    *(long **)(puVar1 + 8) = plVar2;
    *plVar2 = (long)puVar1;
  }
  *ppuVar5 = &DAT_dead000000000100;
  ppuVar5[1] = (undefined *)0xdead000000000122;
  kfree(ppuVar5);
  return;
}



//------------------------------------------------------------
// devm_regulator_debug_match @ 00100d70 size=32
// signature: undefined devm_regulator_debug_match(void)
// callers: []
//------------------------------------------------------------

bool devm_regulator_debug_match(undefined8 param_1,long *param_2,long param_3)

{
  code *pcVar1;
  
  if ((param_2 == (long *)0x0) || (*param_2 == 0)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100d90);
    (*pcVar1)();
  }
  return *param_2 == param_3;
}



//------------------------------------------------------------
// reg_enable_fops_open @ 00100d98 size=52
// signature: undefined reg_enable_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_enable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_debug_enable_get,reg_debug_enable_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// reg_debug_enable_get @ 00100dd0 size=204
// signature: undefined reg_debug_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_debug_enable_get(long param_1,long *param_2)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  if (*(long *)(param_1 + 0x10) == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar2 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar2) || (*(ulong *)(param_1 + 0x10) = uVar2, uVar2 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_enable_get",puVar3);
      return 0xffffffed;
    }
  }
  iVar1 = regulator_is_enabled();
  *param_2 = (long)iVar1;
  return 0;
}



//------------------------------------------------------------
// reg_debug_enable_set @ 00100ea0 size=348
// signature: undefined reg_debug_enable_set(void)
// callers: []
//------------------------------------------------------------

int reg_debug_enable_set(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  if (*(long *)(param_1 + 0x10) == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar2 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar2) || (*(ulong *)(param_1 + 0x10) = uVar2, uVar2 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_enable_set",puVar3);
      return -0x13;
    }
  }
  if (param_2 == 0) {
    iVar1 = regulator_disable();
    if (iVar1 == 0) {
      return 0;
    }
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    puVar4 = &DAT_001025b8;
  }
  else {
    iVar1 = regulator_enable();
    if (iVar1 == 0) {
      return 0;
    }
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    puVar4 = &DAT_00102447;
  }
  _printk(puVar4,"reg_debug_enable_set",puVar3,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// reg_bypass_enable_fops_open @ 00101000 size=52
// signature: undefined reg_bypass_enable_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_bypass_enable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_debug_bypass_enable_get,reg_debug_bypass_enable_set,"%llu\n")
  ;
  return;
}



//------------------------------------------------------------
// reg_debug_bypass_enable_get @ 00101038 size=288
// signature: undefined reg_debug_bypass_enable_get(void)
// callers: []
//------------------------------------------------------------

int reg_debug_bypass_enable_get(long param_1,ulong *param_2)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  code *pcVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  long *plVar7;
  byte local_3c [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  plVar7 = *(long **)(param_1 + 0x20);
  local_3c[0] = 0;
  ww_mutex_lock(plVar7 + 0x13,0);
  pcVar4 = *(code **)(*(long *)(*plVar7 + 0x40) + 0xe8);
  if (pcVar4 == (code *)0x0) {
    iVar2 = 0;
    local_3c[0] = *(int *)((long)plVar7 + 0x14) == (int)plVar7[2];
  }
  else {
    if (*(int *)(pcVar4 + -4) != 0x7e17bf3c) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1010ac);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)(plVar7,local_3c);
    if (iVar2 != 0) {
      puVar6 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar6 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar6, puVar3 == (undefined *)0x0)) {
        puVar5 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar5 != (undefined *)0x0) {
          puVar3 = puVar5;
        }
      }
      _printk(&DAT_0010250e,"reg_debug_bypass_enable_get",puVar3,iVar2);
    }
  }
  ww_mutex_unlock(plVar7 + 0x13);
  *param_2 = (ulong)local_3c[0];
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// reg_debug_bypass_enable_set @ 0010115c size=200
// signature: undefined reg_debug_bypass_enable_set(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_debug_bypass_enable_set(long param_1,long param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  uVar1 = *(ulong *)(param_1 + 0x10);
  if (uVar1 == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar1 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar1) || (*(ulong *)(param_1 + 0x10) = uVar1, uVar1 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_bypass_enable_set",puVar3);
      return 0xffffffed;
    }
  }
  uVar2 = regulator_allow_bypass(uVar1,param_2 != 0);
  return uVar2;
}



//------------------------------------------------------------
// reg_force_disable_fops_open @ 00101228 size=52
// signature: undefined reg_force_disable_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_force_disable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_debug_enable_get,reg_debug_force_disable_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// reg_debug_force_disable_set @ 00101260 size=280
// signature: undefined reg_debug_force_disable_set(void)
// callers: []
//------------------------------------------------------------

int reg_debug_force_disable_set(long param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  if (*(long *)(param_1 + 0x10) == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar2 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar2) || (*(ulong *)(param_1 + 0x10) = uVar2, uVar2 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_force_disable_set",puVar3);
      return -0x13;
    }
  }
  iVar1 = 0;
  if ((param_2 != 0) && (iVar1 = regulator_force_disable(), iVar1 != 0)) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    _printk(&DAT_00102468,"reg_debug_force_disable_set",puVar3,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// reg_debug_voltage_read @ 0010137c size=336
// signature: undefined reg_debug_voltage_read(void)
// callers: []
//------------------------------------------------------------

void reg_debug_voltage_read(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined8 *puVar7;
  long lVar8;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined2 local_40;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0xd8);
  if (*(long *)(lVar8 + 0x10) == 0) {
    puVar7 = (undefined8 *)(*(undefined8 **)(lVar8 + 0x20))[0x8f];
    if ((puVar7 == (undefined8 *)0x0) || (puVar5 = (undefined *)*puVar7, puVar5 == (undefined *)0x0)
       ) {
      puVar6 = *(undefined **)**(undefined8 **)(lVar8 + 0x20);
      puVar5 = &DAT_00102541;
      if (puVar6 != (undefined *)0x0) {
        puVar5 = puVar6;
      }
    }
    uVar3 = regulator_get(0,puVar5);
    if (uVar3 < 0xfffffffffffff001) {
      *(ulong *)(lVar8 + 0x10) = uVar3;
      local_40 = 0;
      local_50 = 0;
      uStack_48 = 0;
      local_60 = 0;
      uStack_58 = 0;
      local_70 = 0;
      uStack_68 = 0;
      if (uVar3 != 0) goto LAB_00101420;
    }
    puVar7 = (undefined8 *)(*(undefined8 **)(lVar8 + 0x20))[0x8f];
    if ((puVar7 == (undefined8 *)0x0) || (puVar5 = (undefined *)*puVar7, puVar5 == (undefined *)0x0)
       ) {
      puVar6 = *(undefined **)**(undefined8 **)(lVar8 + 0x20);
      puVar5 = &DAT_00102541;
      if (puVar6 != (undefined *)0x0) {
        puVar5 = puVar6;
      }
    }
    _printk(&DAT_00102835,"reg_debug_voltage_read",puVar5);
    uVar4 = 0xffffffffffffffed;
  }
  else {
LAB_00101420:
    local_40 = 0;
    uStack_48 = 0;
    local_50 = 0;
    uStack_58 = 0;
    local_60 = 0;
    uStack_68 = 0;
    local_70 = 0;
    uVar1 = regulator_get_voltage();
    iVar2 = scnprintf(&local_70,0x32,&DAT_00102490,uVar1);
    uVar4 = simple_read_from_buffer(param_2,param_3,param_4,&local_70,(long)iVar2);
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// reg_debug_voltage_write @ 001014d0 size=892
// signature: undefined reg_debug_voltage_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong reg_debug_voltage_write(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined *puVar7;
  ulong uVar8;
  ulong uVar9;
  long lVar10;
  int local_78;
  int local_74;
  char local_70 [56];
  long local_38;
  
  lVar10 = sp_el0;
  local_38 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0xd8);
  uVar9 = *(ulong *)(lVar10 + 0x10);
  if (uVar9 == 0) {
    puVar6 = (undefined8 *)(*(undefined8 **)(lVar10 + 0x20))[0x8f];
    if ((puVar6 == (undefined8 *)0x0) || (puVar5 = (undefined *)*puVar6, puVar5 == (undefined *)0x0)
       ) {
      puVar7 = *(undefined **)**(undefined8 **)(lVar10 + 0x20);
      puVar5 = &DAT_00102541;
      if (puVar7 != (undefined *)0x0) {
        puVar5 = puVar7;
      }
    }
    uVar9 = regulator_get(0,puVar5);
    if (uVar9 < 0xfffffffffffff001) {
      *(ulong *)(lVar10 + 0x10) = uVar9;
      local_78 = -1;
      local_74 = 0;
      if (uVar9 != 0) goto LAB_00101584;
    }
    local_70[0x30] = '\0';
    local_70[0x31] = '\0';
    local_70[0x28] = '\0';
    local_70[0x29] = '\0';
    local_70[0x2a] = '\0';
    local_70[0x2b] = '\0';
    local_70[0x2c] = '\0';
    local_70[0x2d] = '\0';
    local_70[0x2e] = '\0';
    local_70[0x2f] = '\0';
    local_70[0x20] = '\0';
    local_70[0x21] = '\0';
    local_70[0x22] = '\0';
    local_70[0x23] = '\0';
    local_70[0x24] = '\0';
    local_70[0x25] = '\0';
    local_70[0x26] = '\0';
    local_70[0x27] = '\0';
    local_70[0x18] = '\0';
    local_70[0x19] = '\0';
    local_70[0x1a] = '\0';
    local_70[0x1b] = '\0';
    local_70[0x1c] = '\0';
    local_70[0x1d] = '\0';
    local_70[0x1e] = '\0';
    local_70[0x1f] = '\0';
    local_70[0x10] = '\0';
    local_70[0x11] = '\0';
    local_70[0x12] = '\0';
    local_70[0x13] = '\0';
    local_70[0x14] = '\0';
    local_70[0x15] = '\0';
    local_70[0x16] = '\0';
    local_70[0x17] = '\0';
    local_70[8] = '\0';
    local_70[9] = '\0';
    local_70[10] = '\0';
    local_70[0xb] = '\0';
    local_70[0xc] = '\0';
    local_70[0xd] = '\0';
    local_70[0xe] = '\0';
    local_70[0xf] = '\0';
    local_70[0] = '\0';
    local_70[1] = '\0';
    local_70[2] = '\0';
    local_70[3] = '\0';
    local_70[4] = '\0';
    local_70[5] = '\0';
    local_70[6] = '\0';
    local_70[7] = '\0';
    puVar6 = (undefined8 *)(*(undefined8 **)(lVar10 + 0x20))[0x8f];
    if ((puVar6 == (undefined8 *)0x0) || (puVar5 = (undefined *)*puVar6, puVar5 == (undefined *)0x0)
       ) {
      puVar7 = *(undefined **)**(undefined8 **)(lVar10 + 0x20);
      puVar5 = &DAT_00102541;
      if (puVar7 != (undefined *)0x0) {
        puVar5 = puVar7;
      }
    }
    _printk(&DAT_00102835,"reg_debug_voltage_write",puVar5);
    param_3 = 0xffffffffffffffed;
    goto LAB_001016b8;
  }
LAB_00101584:
  local_70[0x30] = '\0';
  local_70[0x31] = '\0';
  local_70[0x28] = '\0';
  local_70[0x29] = '\0';
  local_70[0x2a] = '\0';
  local_70[0x2b] = '\0';
  local_70[0x2c] = '\0';
  local_70[0x2d] = '\0';
  local_70[0x2e] = '\0';
  local_70[0x2f] = '\0';
  local_70[0x20] = '\0';
  local_70[0x21] = '\0';
  local_70[0x22] = '\0';
  local_70[0x23] = '\0';
  local_70[0x24] = '\0';
  local_70[0x25] = '\0';
  local_70[0x26] = '\0';
  local_70[0x27] = '\0';
  local_70[0x18] = '\0';
  local_70[0x19] = '\0';
  local_70[0x1a] = '\0';
  local_70[0x1b] = '\0';
  local_70[0x1c] = '\0';
  local_70[0x1d] = '\0';
  local_70[0x1e] = '\0';
  local_70[0x1f] = '\0';
  local_70[0x10] = '\0';
  local_70[0x11] = '\0';
  local_70[0x12] = '\0';
  local_70[0x13] = '\0';
  local_70[0x14] = '\0';
  local_70[0x15] = '\0';
  local_70[0x16] = '\0';
  local_70[0x17] = '\0';
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  local_74 = 0;
  local_78 = -1;
  if (param_3 < 0x32) {
    __check_object_size(local_70,param_3,0);
    puVar6 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_2, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
      uVar8 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar4 = param_3;
    if (uVar8 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        puVar6 = (undefined8 *)puVar6[1];
        uVar4 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar6;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      uVar4 = __arch_copy_from_user(puVar6,local_70,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
    }
    if (uVar4 != 0) {
      param_3 = 0xfffffffffffffff2;
      goto LAB_001016b8;
    }
    if (0x31 < param_3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x101834);
      (*pcVar2)();
    }
    local_70[param_3] = '\0';
    iVar3 = sscanf(local_70,"%d %d",&local_74,&local_78);
    if (((1 < iVar3) && (-1 < local_74)) && (local_74 <= local_78)) {
      iVar3 = regulator_set_voltage(uVar9);
      if (iVar3 != 0) {
        puVar6 = (undefined8 *)(*(undefined8 **)(lVar10 + 0x20))[0x8f];
        if ((puVar6 == (undefined8 *)0x0) ||
           (puVar5 = (undefined *)*puVar6, puVar5 == (undefined *)0x0)) {
          puVar7 = *(undefined **)**(undefined8 **)(lVar10 + 0x20);
          puVar5 = &DAT_00102541;
          if (puVar7 != (undefined *)0x0) {
            puVar5 = puVar7;
          }
        }
        _printk(&DAT_001027ac,"reg_debug_voltage_write",puVar5,local_74,local_78,iVar3);
        param_3 = (ulong)iVar3;
      }
      goto LAB_001016b8;
    }
    puVar6 = (undefined8 *)(*(undefined8 **)(lVar10 + 0x20))[0x8f];
    if ((puVar6 == (undefined8 *)0x0) || (puVar5 = (undefined *)*puVar6, puVar5 == (undefined *)0x0)
       ) {
      puVar7 = *(undefined **)**(undefined8 **)(lVar10 + 0x20);
      puVar5 = &DAT_00102541;
      if (puVar7 != (undefined *)0x0) {
        puVar5 = puVar7;
      }
    }
    _printk(&DAT_00102624,"reg_debug_voltage_write",puVar5,local_70);
  }
  else {
    puVar6 = (undefined8 *)(*(undefined8 **)(lVar10 + 0x20))[0x8f];
    if ((puVar6 == (undefined8 *)0x0) || (puVar5 = (undefined *)*puVar6, puVar5 == (undefined *)0x0)
       ) {
      puVar7 = *(undefined **)**(undefined8 **)(lVar10 + 0x20);
      puVar5 = &DAT_00102541;
      if (puVar7 != (undefined *)0x0) {
        puVar5 = puVar7;
      }
    }
    _printk(&DAT_001023cd,"reg_debug_voltage_write",puVar5);
  }
  param_3 = 0xffffffffffffffea;
LAB_001016b8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// reg_mode_fops_open @ 00101868 size=52
// signature: undefined reg_mode_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_mode_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_debug_mode_get,reg_debug_mode_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// reg_debug_mode_get @ 001018a0 size=296
// signature: undefined reg_debug_mode_get(void)
// callers: []
//------------------------------------------------------------

ulong reg_debug_mode_get(long param_1,ulong *param_2)

{
  uint uVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  if (*(long *)(param_1 + 0x10) == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar2 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar2) || (*(ulong *)(param_1 + 0x10) = uVar2, uVar2 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_mode_get",puVar3);
      return 0xffffffed;
    }
  }
  uVar1 = regulator_get_mode();
  uVar2 = (ulong)uVar1;
  if ((int)uVar1 < 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    _printk(&DAT_001026a8,"reg_debug_mode_get",puVar3,uVar2);
  }
  else {
    *param_2 = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// reg_debug_mode_set @ 001019cc size=292
// signature: undefined reg_debug_mode_set(void)
// callers: []
//------------------------------------------------------------

int reg_debug_mode_set(long param_1,undefined4 param_2)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  uVar2 = *(ulong *)(param_1 + 0x10);
  if (uVar2 == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar2 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar2) || (*(ulong *)(param_1 + 0x10) = uVar2, uVar2 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_mode_set",puVar3);
      return -0x13;
    }
  }
  iVar1 = regulator_set_mode(uVar2,param_2);
  if (iVar1 != 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    _printk(&DAT_00102721,"reg_debug_mode_set",puVar3,param_2,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// reg_set_load_fops_open @ 00101af4 size=52
// signature: undefined reg_set_load_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_set_load_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_debug_mode_get,reg_debug_set_load,"%llu\n");
  return;
}



//------------------------------------------------------------
// reg_debug_set_load @ 00101b2c size=292
// signature: undefined reg_debug_set_load(void)
// callers: []
//------------------------------------------------------------

int reg_debug_set_load(long param_1,undefined4 param_2)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  
  uVar2 = *(ulong *)(param_1 + 0x10);
  if (uVar2 == 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    uVar2 = regulator_get(0,puVar3);
    if ((0xfffffffffffff000 < uVar2) || (*(ulong *)(param_1 + 0x10) = uVar2, uVar2 == 0)) {
      puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
      if ((puVar5 == (undefined8 *)0x0) ||
         (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)) {
        puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
        puVar3 = &DAT_00102541;
        if (puVar4 != (undefined *)0x0) {
          puVar3 = puVar4;
        }
      }
      _printk(&DAT_00102835,"reg_debug_set_load",puVar3);
      return -0x13;
    }
  }
  iVar1 = regulator_set_load(uVar2,param_2);
  if (iVar1 != 0) {
    puVar5 = (undefined8 *)(*(undefined8 **)(param_1 + 0x20))[0x8f];
    if ((puVar5 == (undefined8 *)0x0) || (puVar3 = (undefined *)*puVar5, puVar3 == (undefined *)0x0)
       ) {
      puVar4 = *(undefined **)**(undefined8 **)(param_1 + 0x20);
      puVar3 = &DAT_00102541;
      if (puVar4 != (undefined *)0x0) {
        puVar3 = puVar4;
      }
    }
    _printk(&DAT_00102747,"reg_debug_set_load",puVar3,param_2,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// reg_debug_consumers_open @ 00101c54 size=48
// signature: undefined reg_debug_consumers_open(void)
// callers: []
//------------------------------------------------------------

void reg_debug_consumers_open(long param_1,undefined8 param_2)

{
  single_open(param_2,reg_debug_consumers_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// reg_debug_consumers_show @ 00101c88 size=212
// signature: undefined reg_debug_consumers_show(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_debug_consumers_show(long param_1)

{
  char *pcVar1;
  long lVar2;
  long *plVar3;
  undefined4 uVar4;
  
  lVar2 = *(long *)(param_1 + 0x80);
  ww_mutex_lock(lVar2 + 0x98,0);
  if (*(int *)(lVar2 + 0x10) != 0) {
    seq_printf(param_1,"%-32s EN    Min_uV   Max_uV  load_uA\n","Device-Supply");
  }
  for (plVar3 = *(long **)(lVar2 + 0x28); plVar3 != (long *)(lVar2 + 0x28); plVar3 = (long *)*plVar3
      ) {
    pcVar1 = "(null)-(null)";
    if ((char *)plVar3[9] != (char *)0x0) {
      pcVar1 = (char *)plVar3[9];
    }
    uVar4 = 0x4e;
    if (*(int *)(plVar3 + 3) != 0) {
      uVar4 = 0x59;
    }
    seq_printf(param_1,"%-32s %c   %8d %8d %8d\n",pcVar1,uVar4,*(undefined4 *)(plVar3 + 4),
               *(undefined4 *)((long)plVar3 + 0x24),*(undefined4 *)((long)plVar3 + 0x14));
  }
  ww_mutex_unlock(lVar2 + 0x98);
  return 0;
}



//------------------------------------------------------------
// reg_debug_suspend_enable_fops_open @ 00101d60 size=52
// signature: undefined reg_debug_suspend_enable_fops_open(void)
// callers: []
//------------------------------------------------------------

void reg_debug_suspend_enable_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,reg_debug_suspend_enable_get,reg_debug_suspend_enable_set,
                   "%llu\n");
  return;
}



//------------------------------------------------------------
// reg_debug_suspend_enable_get @ 00101d98 size=20
// signature: undefined reg_debug_suspend_enable_get(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_debug_suspend_enable_get(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)debug_suspend;
  return 0;
}



//------------------------------------------------------------
// reg_debug_suspend_enable_set @ 00101db0 size=196
// signature: undefined reg_debug_suspend_enable_set(void)
// callers: []
//------------------------------------------------------------

int reg_debug_suspend_enable_set(undefined8 param_1,long param_2)

{
  undefined *puVar1;
  int iVar2;
  
  if ((bool)debug_suspend == (param_2 != 0)) {
    iVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      iVar2 = tracepoint_probe_unregister
                        (&__tracepoint_suspend_resume,regulator_debug_suspend_trace_probe,0);
    }
    else {
      iVar2 = tracepoint_probe_register
                        (&__tracepoint_suspend_resume,regulator_debug_suspend_trace_probe,0);
    }
    if (iVar2 == 0) {
      debug_suspend = param_2 != 0;
    }
    else {
      puVar1 = &DAT_00102541;
      if (param_2 == 0) {
        puVar1 = &DAT_00102692;
      }
      _printk(&DAT_001027da,"reg_debug_suspend_enable_set",puVar1,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// regulator_debug_suspend_trace_probe @ 00101e78 size=676
// signature: undefined regulator_debug_suspend_trace_probe(void)
// callers: []
//------------------------------------------------------------

void regulator_debug_suspend_trace_probe(undefined8 param_1,char *param_2,int param_3,ulong param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined *puVar6;
  code *pcVar7;
  undefined **ppuVar8;
  long *plVar9;
  long *plVar10;
  
  if (((0 < param_3) && ((param_4 & 1) != 0)) &&
     (iVar3 = strcmp("machine_suspend",param_2), iVar3 == 0)) {
    _printk(&DAT_0010260d);
    ppuVar8 = (undefined **)debug_reg_list;
    if ((undefined **)debug_reg_list != &debug_reg_list) {
      do {
        plVar9 = (long *)ppuVar8[4];
        if (plVar9[0xa6] == 0) {
          pcVar7 = *(code **)(*(long *)(*plVar9 + 0x40) + 0x80);
          if (pcVar7 != (code *)0x0) {
            if (*(int *)(pcVar7 + -4) != 0x4ce9beb0) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101f74);
              (*pcVar7)();
            }
            iVar3 = (*pcVar7)(plVar9);
            if (iVar3 < 1) goto LAB_00101f80;
          }
LAB_00101f90:
          iVar3 = regulator_get_voltage_rdev(plVar9);
          pcVar7 = *(code **)(*(long *)(*plVar9 + 0x40) + 0x90);
          if (pcVar7 == (code *)0x0) {
            if (iVar3 != -1) {
LAB_00102028:
              if (((undefined8 *)plVar9[0x8f] == (undefined8 *)0x0) ||
                 (puVar6 = *(undefined **)plVar9[0x8f], puVar6 == (undefined *)0x0)) {
                puVar6 = &DAT_00102541;
                if (*(undefined **)*plVar9 != (undefined *)0x0) {
                  puVar6 = *(undefined **)*plVar9;
                }
              }
              uVar2 = *(undefined4 *)((long)plVar9 + 0xc);
              puVar5 = &DAT_001026ee;
              iVar4 = iVar3;
              goto LAB_00102054;
            }
LAB_00102098:
            if (((undefined8 *)plVar9[0x8f] == (undefined8 *)0x0) ||
               (puVar6 = *(undefined **)plVar9[0x8f], puVar6 == (undefined *)0x0)) {
              puVar6 = &DAT_00102541;
              if (*(undefined **)*plVar9 != (undefined *)0x0) {
                puVar6 = *(undefined **)*plVar9;
              }
            }
            _printk(&DAT_0010289d,puVar6,*(undefined4 *)((long)plVar9 + 0xc));
          }
          else {
            if (*(int *)(pcVar7 + -4) != 0x47e2cb13) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101fd4);
              (*pcVar7)();
            }
            iVar4 = (*pcVar7)(plVar9);
            if ((iVar3 == -1) || (iVar4 == -1)) {
              if (iVar3 != -1) goto LAB_00102028;
              if (iVar4 == -1) goto LAB_00102098;
              if (((undefined8 *)plVar9[0x8f] == (undefined8 *)0x0) ||
                 (puVar6 = *(undefined **)plVar9[0x8f], puVar6 == (undefined *)0x0)) {
                puVar6 = &DAT_00102541;
                if (*(undefined **)*plVar9 != (undefined *)0x0) {
                  puVar6 = *(undefined **)*plVar9;
                }
              }
              uVar2 = *(undefined4 *)((long)plVar9 + 0xc);
              puVar5 = &DAT_001025a5;
LAB_00102054:
              _printk(puVar5,puVar6,uVar2,iVar4);
            }
            else {
              if (((undefined8 *)plVar9[0x8f] == (undefined8 *)0x0) ||
                 (puVar6 = *(undefined **)plVar9[0x8f], puVar6 == (undefined *)0x0)) {
                puVar6 = &DAT_00102541;
                if (*(undefined **)*plVar9 != (undefined *)0x0) {
                  puVar6 = *(undefined **)*plVar9;
                }
              }
              _printk(&DAT_00102566,puVar6,*(undefined4 *)((long)plVar9 + 0xc),iVar3);
            }
          }
          if ((int)plVar9[2] != 0) {
            _printk(&DAT_0010276d,"Device-Supply");
          }
          for (plVar10 = (long *)plVar9[5]; plVar10 != plVar9 + 5; plVar10 = (long *)*plVar10) {
            pcVar1 = "(null)-(null)";
            if ((char *)plVar10[9] != (char *)0x0) {
              pcVar1 = (char *)plVar10[9];
            }
            _printk(&DAT_0010240b,pcVar1,(int)plVar10[3],(int)plVar10[4],
                    *(undefined4 *)((long)plVar10 + 0x24),*(undefined4 *)((long)plVar10 + 0x14));
          }
        }
        else if ((*(byte *)(plVar9 + 0xa7) & 1) != 0) goto LAB_00101f90;
LAB_00101f80:
        ppuVar8 = (undefined **)*ppuVar8;
      } while (ppuVar8 != &debug_reg_list);
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001021e0 size=168
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  undefined *puVar1;
  
  regulator_debug_init_dir = debugfs_lookup("regulator",0);
  puVar1 = &DAT_00102371;
  if ((regulator_debug_init_dir != 0) && (regulator_debug_init_dir < 0xfffffffffffff001)) {
    regulator_suspend_debugfs =
         debugfs_create_file_unsafe
                   ("debug_suspend",0x1a4,regulator_debug_init_dir,0,&reg_debug_suspend_enable_fops)
    ;
    dput(regulator_debug_init_dir);
    if (regulator_suspend_debugfs < 0xfffffffffffff001) {
      return 0;
    }
    puVar1 = &DAT_00102494;
  }
  _printk(puVar1,"regulator_debug_init");
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 0010228c size=72
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  debugfs_remove(regulator_suspend_debugfs);
  if (debug_suspend != '\0') {
    tracepoint_probe_unregister(&__tracepoint_suspend_resume,regulator_debug_suspend_trace_probe,0);
  }
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00105008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [regulator_debug_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105010 size=1
// signature: undefined mutex_lock(void)
// callers: [devm_regulator_debug_release, regulator_debug_unregister, regulator_debug_add, devm_regulator_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105018 size=1
// signature: undefined __list_add_valid(void)
// callers: [regulator_debug_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105020 size=1
// signature: undefined mutex_unlock(void)
// callers: [devm_regulator_debug_release, regulator_debug_unregister, regulator_debug_add, devm_regulator_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 00105028 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [init_module, regulator_debug_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00105030 size=1
// signature: undefined debugfs_create_file(void)
// callers: [regulator_debug_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105038 size=1
// signature: undefined _printk(void)
// callers: [reg_debug_set_load, reg_debug_bypass_enable_get, reg_debug_mode_get, reg_debug_suspend_enable_set, regulator_debug_unregister, reg_debug_force_disable_set, regulator_debug_add, reg_debug_voltage_read, reg_debug_enable_get, reg_debug_bypass_enable_set, reg_debug_mode_set, init_module, regulator_debug_suspend_trace_probe, devm_regulator_debug_unregister, reg_debug_enable_set, reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105040 size=1
// signature: undefined kfree(void)
// callers: [devm_regulator_debug_release, regulator_debug_unregister, _devm_regulator_debug_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00105048 size=1
// signature: undefined regulator_put(void)
// callers: [devm_regulator_debug_release, regulator_debug_unregister, _devm_regulator_debug_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105050 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [devm_regulator_debug_release, regulator_debug_unregister, _devm_regulator_debug_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devres_alloc_node @ 00105058 size=1
// signature: undefined __devres_alloc_node(void)
// callers: [devm_regulator_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devres_alloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_add @ 00105060 size=1
// signature: undefined devres_add(void)
// callers: [devm_regulator_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_free @ 00105068 size=1
// signature: undefined devres_free(void)
// callers: [devm_regulator_debug_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_release @ 00105070 size=1
// signature: undefined devres_release(void)
// callers: [devm_regulator_debug_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_lookup @ 00105078 size=1
// signature: undefined debugfs_lookup(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dput @ 00105080 size=1
// signature: undefined dput(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dput(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105088 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00105098 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [cleanup_module, reg_debug_suspend_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 001050a0 size=1
// signature: undefined simple_attr_open(void)
// callers: [reg_bypass_enable_fops_open, reg_set_load_fops_open, reg_debug_suspend_enable_fops_open, reg_enable_fops_open, reg_force_disable_fops_open, reg_mode_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 001050a8 size=1
// signature: undefined regulator_get(void)
// callers: [reg_debug_enable_get, reg_debug_set_load, reg_debug_bypass_enable_set, reg_debug_mode_set, reg_debug_mode_get, reg_debug_force_disable_set, reg_debug_enable_set, reg_debug_voltage_read, reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled @ 001050b0 size=1
// signature: undefined regulator_is_enabled(void)
// callers: [reg_debug_enable_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001050b8 size=1
// signature: undefined regulator_enable(void)
// callers: [reg_debug_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001050c0 size=1
// signature: undefined regulator_disable(void)
// callers: [reg_debug_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_lock @ 001050c8 size=1
// signature: undefined ww_mutex_lock(void)
// callers: [reg_debug_bypass_enable_get, reg_debug_consumers_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ww_mutex_unlock @ 001050d0 size=1
// signature: undefined ww_mutex_unlock(void)
// callers: [reg_debug_bypass_enable_get, reg_debug_consumers_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ww_mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050d8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [reg_debug_bypass_enable_get, reg_debug_voltage_read, reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_allow_bypass @ 001050e0 size=1
// signature: undefined regulator_allow_bypass(void)
// callers: [reg_debug_bypass_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_allow_bypass(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_force_disable @ 001050e8 size=1
// signature: undefined regulator_force_disable(void)
// callers: [reg_debug_force_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_force_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_voltage @ 001050f0 size=1
// signature: undefined regulator_get_voltage(void)
// callers: [reg_debug_voltage_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001050f8 size=1
// signature: undefined scnprintf(void)
// callers: [reg_debug_voltage_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_read_from_buffer @ 00105100 size=1
// signature: undefined simple_read_from_buffer(void)
// callers: [reg_debug_voltage_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_read_from_buffer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00105108 size=1
// signature: undefined __check_object_size(void)
// callers: [reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00105120 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00105128 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00105130 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [reg_debug_voltage_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_mode @ 00105140 size=1
// signature: undefined regulator_get_mode(void)
// callers: [reg_debug_mode_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_mode @ 00105148 size=1
// signature: undefined regulator_set_mode(void)
// callers: [reg_debug_mode_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00105150 size=1
// signature: undefined regulator_set_load(void)
// callers: [reg_debug_set_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00105158 size=1
// signature: undefined single_open(void)
// callers: [reg_debug_consumers_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00105160 size=1
// signature: undefined seq_printf(void)
// callers: [reg_debug_consumers_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00105168 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [reg_debug_suspend_enable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105170 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [regulator_debug_suspend_trace_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_voltage_rdev @ 00105178 size=1
// signature: undefined regulator_get_voltage_rdev(void)
// callers: [regulator_debug_suspend_trace_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_voltage_rdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



