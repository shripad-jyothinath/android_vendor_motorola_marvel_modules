// Decompiled by Ghidra 12.2
// Program: fsa4480-i2c.ko
// Image base: 00100000

//------------------------------------------------------------
// fsa4480_reg_notifier @ 0010028c size=108
// signature: undefined fsa4480_reg_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 fsa4480_reg_notifier(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = of_find_i2c_device_by_node(param_2);
  if ((lVar1 == 0) || (lVar1 = *(long *)(lVar1 + 0xb8), lVar1 == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = blocking_notifier_chain_register(lVar1 + 0x70,param_1);
    if ((int)uVar2 == 0) {
      if (*(int *)(lVar1 + 0x38) == 1) {
        uVar2 = fsa4480_usbc_analog_setup_switches(lVar1);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// fsa4480_usbc_analog_setup_switches @ 001002f8 size=400
// signature: undefined fsa4480_usbc_analog_setup_switches(void)
// callers: [fsa4480_reg_notifier, fsa4480_usbc_analog_work_fn]
//------------------------------------------------------------

int fsa4480_usbc_analog_setup_switches(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (*(int *)(param_1 + 0xe8) == 0) {
    if (*(long *)(param_1 + 8) != 0) {
      mutex_lock(param_1 + 0xb8);
      if (*(int *)(param_1 + 0x38) == 0) {
        blocking_notifier_call_chain(param_1 + 0x70,0,0);
        fsa4480_usbc_update_settings(param_1,0x18,0x98);
      }
      else if (*(int *)(param_1 + 0x38) == 1) {
        fsa4480_usbc_update_settings(param_1,0,0x9f);
        blocking_notifier_call_chain(param_1 + 0x70,1,0);
      }
      mutex_unlock(param_1 + 0xb8);
      iVar1 = 0;
      goto LAB_00100434;
    }
  }
  else {
    lVar2 = *(long *)(param_1 + 8);
    local_40 = 0;
    if (lVar2 != 0) {
      iVar1 = iio_read_channel_processed(*(undefined8 *)(param_1 + 0x30),&local_40);
      mutex_lock(param_1 + 0xb8);
      if (iVar1 < 0) {
        _dev_err(lVar2,"%s: Unable to read USB TYPEC_MODE: %d\n",
                 "fsa4480_usbc_analog_setup_switches_psupply",iVar1);
      }
      else {
        *(int *)(param_1 + 0x38) = (int)local_40;
        if ((int)local_40 == 0) {
          blocking_notifier_call_chain(param_1 + 0x70,0,0);
          fsa4480_usbc_update_settings(param_1,0x18,0x98);
        }
        else if ((int)local_40 == 1) {
          fsa4480_usbc_update_settings(param_1,0,0x9f);
          blocking_notifier_call_chain(param_1 + 0x70,(long)(int)local_40,0);
        }
      }
      mutex_unlock(param_1 + 0xb8);
      goto LAB_00100434;
    }
  }
  iVar1 = -0x16;
LAB_00100434:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// fsa4480_unreg_notifier @ 0010048c size=256
// signature: undefined fsa4480_unreg_notifier(void)
// callers: []
//------------------------------------------------------------

int fsa4480_unreg_notifier(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = of_find_i2c_device_by_node(param_2);
  local_40 = 0;
  if ((lVar2 != 0) && (lVar2 = *(long *)(lVar2 + 0xb8), lVar2 != 0)) {
    if (*(int *)(lVar2 + 0xe8) == 0) {
      fsa4480_usbc_update_settings(lVar2,0x18,0x98);
      iVar1 = blocking_notifier_chain_unregister(lVar2 + 0x70,param_1);
      goto LAB_00100534;
    }
    if (*(long *)(lVar2 + 8) != 0) {
      mutex_lock(lVar2 + 0xb8);
      iVar1 = iio_read_channel_processed(*(undefined8 *)(lVar2 + 0x30),&local_40);
      if (-1 < iVar1) {
        if ((int)local_40 == 1) {
          fsa4480_usbc_update_settings(lVar2,0x18,0x98);
        }
        iVar1 = blocking_notifier_chain_unregister(lVar2 + 0x70,param_1);
      }
      mutex_unlock(lVar2 + 0xb8);
      goto LAB_00100534;
    }
  }
  iVar1 = -0x16;
LAB_00100534:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// fsa4480_usbc_update_settings @ 0010058c size=252
// signature: undefined fsa4480_usbc_update_settings(void)
// callers: [fsa4480_unreg_notifier, fsa4480_switch_event, fsa4480_usbc_analog_setup_switches, fsa4480_remove]
//------------------------------------------------------------

void fsa4480_usbc_update_settings(long *param_1,int param_2,int param_3)

{
  long lVar1;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (*param_1 == 0) {
    _dev_err(param_1[1],"%s: regmap invalid\n","fsa4480_usbc_update_settings");
  }
  else {
    regmap_read(*param_1,5,(long)&local_40 + 4);
    regmap_read(*param_1,4,&local_40);
    if ((local_40._4_4_ != param_2) || ((int)local_40 != param_3)) {
      regmap_write(*param_1,4,0x80);
      regmap_write(*param_1,5,param_2);
      usleep_range_state(0x32,0x37,2);
      regmap_write(*param_1,4,param_3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// fsa4480_switch_event @ 0010068c size=308
// signature: undefined fsa4480_switch_event(void)
// callers: []
//------------------------------------------------------------

void fsa4480_switch_event(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  long *plVar4;
  uint local_30;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  lVar1 = of_find_i2c_device_by_node();
  if (((lVar1 == 0) || (plVar4 = *(long **)(lVar1 + 0xb8), plVar4 == (long *)0x0)) || (*plVar4 == 0)
     ) {
    uVar2 = 0xffffffea;
    goto LAB_00100720;
  }
  switch(param_2) {
  case 0:
    regmap_read(*plVar4,5,&local_30);
    uVar2 = 0x9f;
    uVar3 = local_30 ^ 0xffffffff;
    local_30 = 0;
    if ((uVar3 & 7) != 0) {
      local_30 = 7;
    }
    uVar3 = local_30;
    break;
  case 1:
    uVar2 = 0x18;
    goto LAB_0010075c;
  case 2:
    uVar2 = 0x78;
LAB_0010075c:
    fsa4480_usbc_update_settings(plVar4,uVar2,0xf8);
    local_2c = 0;
    regmap_read(*plVar4,7,&local_2c);
    uVar2 = 0;
    if ((local_2c != 0x1c) && (local_2c != 0x23)) {
      _printk(&DAT_00101181);
      uVar2 = 0xfffffffb;
    }
    goto LAB_00100720;
  case 3:
    uVar2 = 0x98;
    uVar3 = 0x18;
    break;
  default:
    goto switchD_001006ec_default;
  }
  fsa4480_usbc_update_settings(plVar4,uVar3,uVar2);
switchD_001006ec_default:
  uVar2 = 0;
LAB_00100720:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// fsa4480_probe @ 001007c4 size=808
// signature: undefined fsa4480_probe(void)
// callers: []
//------------------------------------------------------------

ulong fsa4480_probe(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  ulong *puVar4;
  ulong uVar5;
  ulong *puVar6;
  int local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  puVar4 = (ulong *)devm_kmalloc(param_1 + 0x20U,0xf0,0xdc0);
  if (puVar4 == (ulong *)0x0) {
    uVar5 = 0xfffffff4;
    goto LAB_00100a40;
  }
  puVar4[0x1c] = 0;
  puVar4[0x1d] = 0;
  puVar4[0x1a] = 0;
  puVar4[0x1b] = 0;
  puVar4[0x18] = 0;
  puVar4[0x19] = 0;
  puVar4[0x16] = 0;
  puVar4[0x17] = 0;
  puVar4[0x14] = 0;
  puVar4[0x15] = 0;
  puVar4[0x12] = 0;
  puVar4[0x13] = 0;
  puVar4[0x10] = 0;
  puVar4[0x11] = 0;
  puVar4[0xe] = 0;
  puVar4[0xf] = 0;
  puVar4[0xc] = 0;
  puVar4[0xd] = 0;
  puVar4[10] = 0;
  puVar4[0xb] = 0;
  puVar4[8] = 0;
  puVar4[9] = 0;
  puVar4[6] = 0;
  puVar4[7] = 0;
  puVar4[4] = 0;
  puVar4[5] = 0;
  puVar4[2] = 0;
  puVar4[3] = 0;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[1] = param_1 + 0x20U;
  uVar5 = __devm_regmap_init_i2c(param_1,fsa4480_regmap_config,0,0);
  *puVar4 = uVar5;
  if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
    _dev_err(puVar4[1],"%s: Failed to initialize regmap: %d\n","fsa4480_probe",0);
    uVar5 = *puVar4;
    if (uVar5 == 0) {
      uVar5 = 0xffffffea;
    }
    goto LAB_00100a40;
  }
  regmap_write(uVar5,8,0);
  regmap_write(uVar5,9,0);
  regmap_write(uVar5,10,0);
  regmap_write(uVar5,0xb,0);
  regmap_write(uVar5,0xc,0);
  regmap_write(uVar5,0xd,0);
  regmap_write(uVar5,0xe,0);
  regmap_write(uVar5,0xf,0);
  regmap_write(uVar5,0x10,9);
  regmap_write(uVar5,4,0x98);
  devm_regmap_qti_debugfs_register(puVar4[1],*puVar4);
  puVar6 = puVar4 + 3;
  *puVar6 = (ulong)fsa4480_usbc_event_changed;
  *(undefined4 *)(puVar4 + 5) = 0;
  iVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(puVar4[1] + 0x2e8),"qcom,use-power-supply",&local_3c,1,0);
  if ((iVar2 < 0) || (local_3c == 0)) {
    *(undefined4 *)(puVar4 + 0x1d) = 0;
    uVar3 = register_ucsi_glink_notifier(puVar6);
    if (uVar3 != 0) {
      uVar5 = (ulong)uVar3;
      _dev_err(puVar4[1],"%s: ucsi glink notifier registration failed: %d\n","fsa4480_probe",uVar5);
      goto LAB_00100a40;
    }
LAB_001009dc:
    __mutex_init(puVar4 + 0x17,"&fsa_priv->notification_lock",&fsa4480_probe___key);
    puVar4[8] = 0xfffffffe0;
    *(ulong **)(param_1 + 0xb8) = puVar4;
    puVar4[9] = (ulong)(puVar4 + 9);
    puVar4[10] = (ulong)(puVar4 + 9);
    puVar4[0xb] = (ulong)fsa4480_usbc_analog_work_fn;
    __init_rwsem(puVar4 + 0xe,"&(&fsa_priv->fsa4480_notifier)->rwsem",&fsa4480_probe___key_13);
    uVar5 = 0;
    puVar4[0x16] = 0;
  }
  else {
    *(undefined4 *)(puVar4 + 0x1d) = 1;
    uVar5 = power_supply_get_by_name(&DAT_0010117d);
    puVar4[2] = uVar5;
    if (uVar5 == 0) {
      uVar5 = 0xfffffdfb;
      goto LAB_00100a40;
    }
    uVar5 = iio_channel_get(puVar4[1],"typec_mode");
    puVar4[6] = uVar5;
    if (uVar5 == 0) {
      _dev_err(puVar4[1],"%s: iio_channel_get failed for typec_mode\n","fsa4480_probe");
      uVar5 = 0;
    }
    else {
      uVar3 = power_supply_reg_notifier(puVar6);
      if (uVar3 == 0) goto LAB_001009dc;
      uVar5 = (ulong)uVar3;
      _dev_err(puVar4[1],"%s: power supply reg failed: %d\n","fsa4480_probe",uVar5);
    }
    power_supply_put(puVar4[2]);
  }
LAB_00100a40:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// fsa4480_remove @ 00100af0 size=112
// signature: undefined fsa4480_remove(void)
// callers: []
//------------------------------------------------------------

void fsa4480_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xb8);
  if (lVar1 != 0) {
    if (*(int *)(lVar1 + 0xe8) == 0) {
      unregister_ucsi_glink_notifier(lVar1 + 0x18);
    }
    else {
      power_supply_unreg_notifier();
      power_supply_put(*(undefined8 *)(lVar1 + 0x10));
    }
    fsa4480_usbc_update_settings(lVar1,0x18,0x98);
    cancel_work_sync(lVar1 + 0x40);
    pm_relax(*(undefined8 *)(lVar1 + 8));
    *(undefined8 *)(param_1 + 0xb8) = 0;
  }
  return;
}



//------------------------------------------------------------
// fsa4480_usbc_event_changed @ 00100b64 size=132
// signature: undefined fsa4480_usbc_event_changed(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fsa4480_usbc_event_changed(long param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  
  if ((param_1 == 0x18) || (*(long *)(param_1 + -0x10) == 0)) {
    return 0xffffffea;
  }
  if (*(int *)(param_1 + 0xd0) == 0) {
    uVar1 = *param_3;
    if (1 < uVar1) {
      return 0;
    }
    if (*(uint *)(param_1 + 0x20) == uVar1) {
      return 0;
    }
    *(uint *)(param_1 + 0x20) = uVar1;
  }
  pm_stay_awake();
  queue_work_on(0x20,_system_freezable_wq,param_1 + 0x28);
  return 0;
}



//------------------------------------------------------------
// fsa4480_usbc_analog_work_fn @ 00100bec size=80
// signature: undefined fsa4480_usbc_analog_work_fn(void)
// callers: []
//------------------------------------------------------------

void fsa4480_usbc_analog_work_fn(long param_1)

{
  if (param_1 + -0x40 == 0) {
    _printk(&DAT_0010124f,"fsa4480_usbc_analog_work_fn");
  }
  else {
    fsa4480_usbc_analog_setup_switches(param_1 + -0x40);
    pm_relax(*(undefined8 *)(param_1 + -0x38));
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100f64 size=84
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = i2c_register_driver(&__this_module,&fsa4480_i2c_driver);
  if (iVar1 != 0) {
    _printk(&DAT_001011d3,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00100fbc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&fsa4480_i2c_driver);
  return;
}



//------------------------------------------------------------
// of_find_i2c_device_by_node @ 00103000 size=1
// signature: undefined of_find_i2c_device_by_node(void)
// callers: [fsa4480_reg_notifier, fsa4480_unreg_notifier, fsa4480_switch_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_i2c_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00103008 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [fsa4480_reg_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iio_read_channel_processed @ 00103010 size=1
// signature: undefined iio_read_channel_processed(void)
// callers: [fsa4480_unreg_notifier, fsa4480_usbc_analog_setup_switches]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iio_read_channel_processed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103018 size=1
// signature: undefined mutex_lock(void)
// callers: [fsa4480_unreg_notifier, fsa4480_usbc_analog_setup_switches]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00103020 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [fsa4480_usbc_analog_setup_switches]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103028 size=1
// signature: undefined mutex_unlock(void)
// callers: [fsa4480_unreg_notifier, fsa4480_usbc_analog_setup_switches]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103030 size=1
// signature: undefined _dev_err(void)
// callers: [fsa4480_usbc_update_settings, fsa4480_usbc_analog_setup_switches, fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [fsa4480_usbc_update_settings, fsa4480_unreg_notifier, fsa4480_switch_event, fsa4480_usbc_analog_setup_switches, fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00103040 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [fsa4480_unreg_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00103048 size=1
// signature: undefined regmap_read(void)
// callers: [fsa4480_usbc_update_settings, fsa4480_switch_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00103050 size=1
// signature: undefined regmap_write(void)
// callers: [fsa4480_usbc_update_settings, fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00103058 size=1
// signature: undefined usleep_range_state(void)
// callers: [fsa4480_usbc_update_settings]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103060 size=1
// signature: undefined _printk(void)
// callers: [fsa4480_usbc_analog_work_fn, fsa4480_switch_event, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 00103068 size=1
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
// i2c_del_driver @ 00103070 size=1
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
// devm_kmalloc @ 00103078 size=1
// signature: undefined devm_kmalloc(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_i2c @ 00103080 size=1
// signature: undefined __devm_regmap_init_i2c(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_i2c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 00103088 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103090 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00103098 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iio_channel_get @ 001030a0 size=1
// signature: undefined iio_channel_get(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iio_channel_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 001030a8 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_ucsi_glink_notifier @ 001030b0 size=1
// signature: undefined register_ucsi_glink_notifier(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_ucsi_glink_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001030b8 size=1
// signature: undefined __mutex_init(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 001030c0 size=1
// signature: undefined __init_rwsem(void)
// callers: [fsa4480_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 001030c8 size=1
// signature: undefined power_supply_put(void)
// callers: [fsa4480_probe, fsa4480_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 001030d0 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [fsa4480_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_ucsi_glink_notifier @ 001030d8 size=1
// signature: undefined unregister_ucsi_glink_notifier(void)
// callers: [fsa4480_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_ucsi_glink_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001030e0 size=1
// signature: undefined cancel_work_sync(void)
// callers: [fsa4480_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 001030e8 size=1
// signature: undefined pm_relax(void)
// callers: [fsa4480_usbc_analog_work_fn, fsa4480_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 001030f0 size=1
// signature: undefined pm_stay_awake(void)
// callers: [fsa4480_usbc_event_changed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00103100 size=1
// signature: undefined queue_work_on(void)
// callers: [fsa4480_usbc_event_changed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



