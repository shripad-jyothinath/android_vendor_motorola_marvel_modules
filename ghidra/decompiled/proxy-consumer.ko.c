// Decompiled by Ghidra 12.2
// Program: proxy-consumer.ko
// Image base: 00100000

//------------------------------------------------------------
// regulator_proxy_consumer_register @ 0010026c size=36
// signature: undefined regulator_proxy_consumer_register(void)
// callers: []
//------------------------------------------------------------

undefined4 regulator_proxy_consumer_register(void)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = regulator_proxy_consumer_add();
  uVar1 = (undefined4)uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// regulator_proxy_consumer_add @ 00100290 size=800
// signature: undefined regulator_proxy_consumer_add(void)
// callers: [regulator_proxy_consumer_register, devm_regulator_proxy_consumer_register]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * regulator_proxy_consumer_add(long param_1,undefined8 *param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  char *local_58;
  undefined8 local_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = (char *)0x0;
  local_50 = 0;
  if ((param_1 == 0) || (param_2 == (undefined8 *)0x0)) {
    _printk(&DAT_00100b16,"regulator_proxy_consumer_add");
    puVar5 = (undefined8 *)0xffffffffffffffea;
  }
  else {
    lVar4 = of_find_property(param_2,"qcom,proxy-consumer-enable",0);
    if (((lVar4 == 0) &&
        (lVar4 = of_find_property(param_2,"qcom,proxy-consumer-voltage",0), lVar4 == 0)) &&
       (lVar4 = of_find_property(param_2,"qcom,proxy-consumer-current",0), lVar4 == 0)) {
      puVar5 = (undefined8 *)0x0;
    }
    else {
      mutex_lock(&proxy_consumer_list_lock);
      puVar1 = &UNK_00100bbc;
      if ((undefined *)*param_2 != (undefined *)0x0) {
        puVar1 = (undefined *)*param_2;
      }
      puVar5 = (undefined8 *)kmalloc_trace(_regulator_set_load,0xdc0,0x30);
      if (puVar5 == (undefined8 *)0x0) {
        iVar2 = -0xc;
      }
      else {
        puVar5[3] = param_1;
        lVar4 = of_find_property(param_2,"qcom,proxy-consumer-enable",0);
        *(bool *)(puVar5 + 4) = lVar4 != 0;
        of_property_read_variable_u32_array
                  (param_2,"qcom,proxy-consumer-current",(int *)((long)puVar5 + 0x2c),1,0);
        iVar2 = of_property_read_variable_u32_array
                          (param_2,"qcom,proxy-consumer-voltage",&local_50,2,0);
        if (-1 < iVar2) {
          *(undefined4 *)((long)puVar5 + 0x24) = (undefined4)local_50;
          *(undefined4 *)(puVar5 + 5) = local_50._4_4_;
        }
        local_58 = "proxy";
        of_property_read_string(param_2,"qcom,proxy-consumer-name",&local_58);
        uVar6 = regulator_get(param_1,local_58);
        puVar5[2] = uVar6;
        if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
          _printk(&DAT_00100c37,"regulator_proxy_consumer_add",local_58,puVar1,uVar6 & 0xffffffff);
        }
        else {
          if (((*(int *)(puVar5 + 5) < 1) || (*(int *)(puVar5 + 5) < *(int *)((long)puVar5 + 0x24)))
             || (uVar3 = regulator_set_voltage(uVar6), uVar3 == 0)) {
            if ((*(int *)((long)puVar5 + 0x2c) == 0) ||
               (uVar3 = regulator_set_load(puVar5[2]), -1 < (int)uVar3)) {
              if ((*(char *)(puVar5 + 4) == '\0') ||
                 (uVar3 = regulator_enable(puVar5[2]), uVar3 == 0)) {
                puVar1 = proxy_consumer_list;
                uVar6 = __list_add_valid(puVar5,&proxy_consumer_list,proxy_consumer_list);
                if ((uVar6 & 1) != 0) {
                  *(undefined8 **)(puVar1 + 8) = puVar5;
                  *puVar5 = puVar1;
                  puVar5[1] = &proxy_consumer_list;
                  proxy_consumer_list = (undefined *)puVar5;
                }
                mutex_unlock(&proxy_consumer_list_lock);
                goto LAB_00100498;
              }
              uVar6 = (ulong)uVar3;
              _printk(&DAT_00100b8c,"regulator_proxy_consumer_add",puVar1,uVar6);
              regulator_set_load(puVar5[2],0);
            }
            else {
              uVar6 = (ulong)uVar3;
              _printk(&DAT_00100c95,"regulator_proxy_consumer_add",puVar1,uVar6);
            }
            regulator_set_voltage(puVar5[2],0,0x7fffffff);
          }
          else {
            uVar6 = (ulong)uVar3;
            _printk(&DAT_00100c66,"regulator_proxy_consumer_add",puVar1,uVar6);
          }
          regulator_put(puVar5[2]);
        }
        iVar2 = (int)uVar6;
        kfree(puVar5);
      }
      mutex_unlock(&proxy_consumer_list_lock);
      puVar5 = (undefined8 *)(long)iVar2;
    }
  }
LAB_00100498:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar5;
}



//------------------------------------------------------------
// regulator_proxy_consumer_unregister @ 001005b4 size=160
// signature: undefined regulator_proxy_consumer_unregister(void)
// callers: []
//------------------------------------------------------------

void regulator_proxy_consumer_unregister(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  if ((param_1 == (undefined *)0x0) || ((undefined *)0xfffffffffffff000 < param_1)) {
    _printk(&DAT_00100cfd,"regulator_proxy_consumer_unregister");
  }
  else {
    mutex_lock(&proxy_consumer_list_lock);
    ppuVar2 = (undefined **)proxy_consumer_list;
    while (ppuVar2 != &proxy_consumer_list) {
      ppuVar1 = ppuVar2 + 3;
      ppuVar2 = (undefined **)*ppuVar2;
      if (*ppuVar1 == param_1) {
        regulator_proxy_consumer_remove();
      }
    }
    mutex_unlock(&proxy_consumer_list_lock);
  }
  return;
}



//------------------------------------------------------------
// regulator_proxy_consumer_remove @ 00100654 size=276
// signature: undefined regulator_proxy_consumer_remove(void)
// callers: [regulator_proxy_consumer_unregister, _devm_regulator_proxy_consumer_release, devm_regulator_proxy_consumer_release, regulator_proxy_consumer_sync_state]
//------------------------------------------------------------

void regulator_proxy_consumer_remove(long *param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  
  if (((char)param_1[4] == '\0') || (iVar3 = regulator_disable(param_1[2]), iVar3 == 0)) {
    iVar3 = *(int *)((long)param_1 + 0x2c);
  }
  else {
    _printk(&DAT_00100bbd,"regulator_proxy_consumer_remove",iVar3);
    iVar3 = *(int *)((long)param_1 + 0x2c);
  }
  if ((iVar3 != 0) && (iVar3 = regulator_set_load(param_1[2],0), iVar3 < 0)) {
    _printk(&DAT_00100d1b,"regulator_proxy_consumer_remove",iVar3);
  }
  if (((0 < (int)param_1[5]) && (*(int *)((long)param_1 + 0x24) <= (int)param_1[5])) &&
     (iVar3 = regulator_set_voltage(param_1[2],0,0x7fffffff), iVar3 != 0)) {
    _printk(&DAT_00100c0b,"regulator_proxy_consumer_remove",iVar3);
  }
  regulator_put(param_1[2]);
  uVar4 = __list_del_entry_valid(param_1);
  if ((uVar4 & 1) != 0) {
    lVar1 = *param_1;
    plVar2 = (long *)param_1[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *param_1 = -0x2152ffffffffff00;
  param_1[1] = -0x2152fffffffffede;
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// devm_regulator_proxy_consumer_register @ 0010076c size=160
// signature: undefined devm_regulator_proxy_consumer_register(void)
// callers: []
//------------------------------------------------------------

ulong devm_regulator_proxy_consumer_register(undefined8 param_1,undefined8 param_2)

{
  ulong *puVar1;
  ulong uVar2;
  
  puVar1 = (ulong *)__devres_alloc_node(devm_regulator_proxy_consumer_release,8,0xcc0,0xffffffff,
                                        "devm_regulator_proxy_consumer_release");
  if (puVar1 == (ulong *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = regulator_proxy_consumer_add(param_1,param_2);
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
// devm_regulator_proxy_consumer_release @ 00100810 size=100
// signature: undefined devm_regulator_proxy_consumer_release(void)
// callers: []
//------------------------------------------------------------

void devm_regulator_proxy_consumer_release(undefined8 param_1,undefined8 *param_2)

{
  undefined **ppuVar1;
  
  mutex_lock(&proxy_consumer_list_lock);
  ppuVar1 = &proxy_consumer_list;
  do {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &proxy_consumer_list) goto LAB_00100858;
  } while (ppuVar1 != (undefined **)*param_2);
  regulator_proxy_consumer_remove();
LAB_00100858:
  mutex_unlock(&proxy_consumer_list_lock);
  return;
}



//------------------------------------------------------------
// devm_regulator_proxy_consumer_unregister @ 00100878 size=176
// signature: undefined devm_regulator_proxy_consumer_unregister(void)
// callers: []
//------------------------------------------------------------

void devm_regulator_proxy_consumer_unregister(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  if ((param_1 != (undefined *)0x0) && (param_1 < (undefined *)0xfffffffffffff001)) {
    mutex_lock(&proxy_consumer_list_lock);
    ppuVar1 = (undefined **)proxy_consumer_list;
    if ((undefined **)proxy_consumer_list != &proxy_consumer_list) {
      do {
        ppuVar2 = (undefined **)*ppuVar1;
        if (ppuVar1[3] == param_1) {
          devres_release(param_1,_devm_regulator_proxy_consumer_release,
                         devm_regulator_proxy_consumer_match);
        }
        ppuVar1 = ppuVar2;
      } while (ppuVar2 != &proxy_consumer_list);
    }
    mutex_unlock(&proxy_consumer_list_lock);
  }
  return;
}



//------------------------------------------------------------
// _devm_regulator_proxy_consumer_release @ 0010092c size=64
// signature: undefined _devm_regulator_proxy_consumer_release(void)
// callers: []
//------------------------------------------------------------

void _devm_regulator_proxy_consumer_release(undefined8 param_1,undefined8 *param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = &proxy_consumer_list;
  do {
    ppuVar1 = (undefined **)*ppuVar1;
    if (ppuVar1 == &proxy_consumer_list) {
      return;
    }
  } while (ppuVar1 != (undefined **)*param_2);
  regulator_proxy_consumer_remove();
  return;
}



//------------------------------------------------------------
// devm_regulator_proxy_consumer_match @ 00100970 size=32
// signature: undefined devm_regulator_proxy_consumer_match(void)
// callers: []
//------------------------------------------------------------

bool devm_regulator_proxy_consumer_match(undefined8 param_1,long *param_2,long param_3)

{
  code *pcVar1;
  
  if ((param_2 == (long *)0x0) || (*param_2 == 0)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100990);
    (*pcVar1)();
  }
  return *param_2 == param_3;
}



//------------------------------------------------------------
// regulator_proxy_consumer_sync_state @ 00100998 size=160
// signature: undefined regulator_proxy_consumer_sync_state(void)
// callers: []
//------------------------------------------------------------

void regulator_proxy_consumer_sync_state(undefined *param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  if ((param_1 == (undefined *)0x0) || ((undefined *)0xfffffffffffff000 < param_1)) {
    _printk(&DAT_00100cfd,"regulator_proxy_consumer_unregister");
  }
  else {
    mutex_lock(&proxy_consumer_list_lock);
    ppuVar2 = (undefined **)proxy_consumer_list;
    while (ppuVar2 != &proxy_consumer_list) {
      ppuVar1 = ppuVar2 + 3;
      ppuVar2 = (undefined **)*ppuVar2;
      if (*ppuVar1 == param_1) {
        regulator_proxy_consumer_remove();
      }
    }
    mutex_unlock(&proxy_consumer_list_lock);
  }
  return;
}



//------------------------------------------------------------
// of_find_property @ 00102000 size=1
// signature: undefined of_find_property(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102008 size=1
// signature: undefined mutex_lock(void)
// callers: [devm_regulator_proxy_consumer_unregister, regulator_proxy_consumer_add, regulator_proxy_consumer_unregister, devm_regulator_proxy_consumer_release, regulator_proxy_consumer_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102018 size=1
// signature: undefined kmalloc_trace(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00102028 size=1
// signature: undefined of_property_read_string(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 00102030 size=1
// signature: undefined regulator_get(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00102038 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [regulator_proxy_consumer_add, regulator_proxy_consumer_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00102040 size=1
// signature: undefined regulator_set_load(void)
// callers: [regulator_proxy_consumer_add, regulator_proxy_consumer_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00102048 size=1
// signature: undefined regulator_enable(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102050 size=1
// signature: undefined __list_add_valid(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102058 size=1
// signature: undefined mutex_unlock(void)
// callers: [devm_regulator_proxy_consumer_unregister, regulator_proxy_consumer_add, regulator_proxy_consumer_unregister, devm_regulator_proxy_consumer_release, regulator_proxy_consumer_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102060 size=1
// signature: undefined _printk(void)
// callers: [regulator_proxy_consumer_add, regulator_proxy_consumer_unregister, regulator_proxy_consumer_remove, regulator_proxy_consumer_sync_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00102068 size=1
// signature: undefined regulator_put(void)
// callers: [regulator_proxy_consumer_add, regulator_proxy_consumer_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102070 size=1
// signature: undefined kfree(void)
// callers: [regulator_proxy_consumer_add, regulator_proxy_consumer_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102078 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [regulator_proxy_consumer_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00102080 size=1
// signature: undefined regulator_disable(void)
// callers: [regulator_proxy_consumer_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00102088 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [regulator_proxy_consumer_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devres_alloc_node @ 00102090 size=1
// signature: undefined __devres_alloc_node(void)
// callers: [devm_regulator_proxy_consumer_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devres_alloc_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_add @ 00102098 size=1
// signature: undefined devres_add(void)
// callers: [devm_regulator_proxy_consumer_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_free @ 001020a0 size=1
// signature: undefined devres_free(void)
// callers: [devm_regulator_proxy_consumer_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devres_release @ 001020a8 size=1
// signature: undefined devres_release(void)
// callers: [devm_regulator_proxy_consumer_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devres_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



