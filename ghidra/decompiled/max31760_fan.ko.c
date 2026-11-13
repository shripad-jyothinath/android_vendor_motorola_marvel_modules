// Decompiled by Ghidra 12.2
// Program: max31760_fan.ko
// Image base: 00100000

//------------------------------------------------------------
// max31760_probe @ 0010031c size=1340
// signature: undefined max31760_probe(void)
// callers: []
//------------------------------------------------------------

ulong max31760_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  undefined8 uVar8;
  ulong uVar9;
  char *pcVar10;
  code *pcVar11;
  undefined4 uVar12;
  long lVar13;
  ulong *puVar14;
  char local_70 [5];
  char acStack_6b [3];
  char acStack_68 [5];
  undefined4 uStack_63;
  undefined3 uStack_5f;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if ((param_1 == 0) || (*(long *)(param_1 + 0x308) == 0)) {
    _printk(&DAT_001015fe);
    uVar6 = 0xffffffea;
    goto LAB_00100800;
  }
  lVar1 = param_1 + 0x20;
  pcVar11 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
  if (*(int *)(pcVar11 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x100380);
    (*pcVar11)();
  }
  uVar6 = (*pcVar11)();
  if ((uVar6 & 1) == 0) {
    _dev_err(lVar1,"device doesn\'t support I2C\n");
    uVar6 = 0xffffffed;
    goto LAB_00100800;
  }
  plVar7 = (long *)devm_kmalloc(lVar1,0x68,0xdc0);
  if (plVar7 == (long *)0x0) {
    uVar6 = 0xfffffff4;
    goto LAB_00100800;
  }
  plVar2 = plVar7 + 3;
  *plVar7 = lVar1;
  plVar7[1] = param_1;
  *(long **)(param_1 + 0xb8) = plVar7;
  __mutex_init(plVar2,"&pdata->update_lock",&max31760_probe___key);
  lVar13 = *(long *)(*plVar7 + 0x2e8);
  if (lVar13 == 0) {
    _printk(&DAT_0010173d);
    uVar6 = 0xffffffea;
LAB_0010069c:
    _dev_err(*plVar7,"failed to parse device tree, ret:%d\n",uVar6);
  }
  else {
    puVar3 = (uint *)(plVar7 + 0xb);
    uVar5 = 1;
    iVar4 = of_property_read_variable_u32_array(lVar13,"maxim,fan-num",puVar3,1,0);
    if (iVar4 < 0) {
LAB_00100408:
      *puVar3 = uVar5;
    }
    else if (2 < *puVar3) {
      uVar5 = 2;
      goto LAB_00100408;
    }
    uVar8 = of_get_named_gpio_flags(lVar13,"maxim,pwr-en-gpio",0,0);
    *(uint *)((long)plVar7 + 0x5c) = (uint)uVar8;
    if (0x1ff < (uint)uVar8) {
      _dev_err(*plVar7,"enable gpio not specified\n");
      uVar6 = 0xffffffea;
      goto LAB_0010069c;
    }
    uVar5 = gpio_request(uVar8,"pwr_en_gpio");
    if (uVar5 != 0) {
      uVar6 = (ulong)uVar5;
      _printk(&DAT_00101887,uVar6);
      gpio_free(*(undefined4 *)((long)plVar7 + 0x5c));
      goto LAB_0010069c;
    }
    uVar8 = gpio_to_desc(*(undefined4 *)((long)plVar7 + 0x5c));
    gpiod_direction_output_raw(uVar8,1);
    usleep_range_state(20000,0x4e84,2);
    uVar9 = devm_regulator_get(*plVar7,"maxim,vdd");
    puVar14 = (ulong *)(plVar7 + 9);
    *puVar14 = uVar9;
    if (uVar9 < 0xfffffffffffff001) {
      uVar12 = 3300000;
      regulator_set_voltage(uVar9,0x324b00,3300000);
      regulator_set_load(plVar7[9],300000);
      iVar4 = regulator_enable(plVar7[9]);
      lVar13 = *plVar7;
      if (-1 < iVar4) {
        uVar9 = devm_regulator_get(lVar13,"maxim,vcca");
        puVar14 = (ulong *)(plVar7 + 10);
        *puVar14 = uVar9;
        if (0xfffffffffffff000 < uVar9) {
          lVar13 = *plVar7;
          pcVar10 = "couldn\'t get vcca_reg regulator, ret:%d\n";
          goto LAB_00100774;
        }
        uVar12 = 1800000;
        regulator_set_voltage(uVar9,1800000,1800000);
        regulator_set_load(*puVar14,600000);
        iVar4 = regulator_enable(*puVar14);
        if (iVar4 < 0) {
          lVar13 = *plVar7;
          pcVar10 = "vcca_reg regulator failed, ret:%d\n";
          goto LAB_0010079c;
        }
        goto LAB_00100520;
      }
      pcVar10 = "vdd_reg regulator failed, ret:%d\n";
LAB_0010079c:
      _dev_err(lVar13,pcVar10,iVar4);
      regulator_set_voltage(*puVar14,0,uVar12);
      regulator_set_load(*puVar14,0);
      uVar6 = 0xffffffea;
    }
    else {
      lVar13 = *plVar7;
      pcVar10 = "couldn\'t get vdd_reg regulator, ret:%d\n";
LAB_00100774:
      _dev_err(lVar13,pcVar10,uVar9 & 0xffffffff);
      uVar6 = uVar9 & 0xffffffff;
      *puVar14 = 0;
      if ((int)uVar9 == 0) {
LAB_00100520:
        iVar4 = i2c_smbus_write_byte_data(plVar7[1],0,0x19);
        if (iVar4 < 0) {
          _dev_err(*plVar7,"failed write reg %#x failure, ret:%d\n",0,iVar4);
        }
        iVar4 = i2c_smbus_write_byte_data(plVar7[1],1,0x11);
        if (iVar4 < 0) {
          _dev_err(*plVar7,"failed write reg %#x failure, ret:%d\n",1,iVar4);
        }
        if (*puVar3 == 2) {
          lVar13 = plVar7[1];
          uVar8 = 0x33;
LAB_00100580:
          iVar4 = i2c_smbus_write_byte_data(lVar13,2,uVar8);
          if (iVar4 < 0) {
            _dev_err(*plVar7,"failed write reg %#x failure, ret:%d\n",2,iVar4);
          }
        }
        else if (*puVar3 == 1) {
          lVar13 = plVar7[1];
          uVar8 = 0x31;
          goto LAB_00100580;
        }
        mutex_lock(plVar2);
        iVar4 = i2c_smbus_write_byte_data(plVar7[1],0x50,0);
        if (iVar4 < 0) {
          _dev_err(*plVar7,"failed write reg %#x failure, ret:%d\n",0x50,iVar4);
        }
        *(undefined4 *)(plVar7 + 0xc) = 0;
        mutex_unlock(plVar2);
        *(undefined4 *)((long)plVar7 + 100) = 0;
        uStack_5f = 0;
        uStack_63 = 0;
        local_70[0] = s_fan_max31760_001016ac[0];
        local_70[1] = s_fan_max31760_001016ac[1];
        local_70[2] = s_fan_max31760_001016ac[2];
        local_70[3] = s_fan_max31760_001016ac[3];
        local_70[4] = s_fan_max31760_001016ac[4];
        acStack_6b[0] = s_fan_max31760_001016ac[5];
        acStack_6b[1] = s_fan_max31760_001016ac[6];
        acStack_6b[2] = s_fan_max31760_001016ac[7];
        acStack_68[0] = s_fan_max31760_001016ac[8];
        acStack_68[1] = s_fan_max31760_001016ac[9];
        acStack_68[2] = s_fan_max31760_001016ac[10];
        acStack_68[3] = s_fan_max31760_001016ac[0xb];
        acStack_68[4] = s_fan_max31760_001016ac[0xc];
        uVar6 = thermal_of_cooling_device_register
                          (*(undefined8 *)(*plVar7 + 0x2e8),local_70,plVar7,&max31760_cooling_ops);
        plVar7[2] = uVar6;
        if (0xfffffffffffff000 < uVar6) {
          _dev_err(*plVar7,"Cooling register failed for %s, ret:%d\n",local_70,uVar6 & 0xffffffff);
          plVar7[2] = 0;
          if ((int)uVar6 != 0) {
            _dev_err(*plVar7,"failed to register cooling device, ret:%d\n",uVar6 & 0xffffffff);
            max31760_remove(param_1);
            goto LAB_00100800;
          }
        }
        uVar9 = devm_device_add_group(lVar1,max31760_attribute_group);
        uVar6 = uVar9 & 0xffffffff;
        if ((int)uVar9 < 0) {
          _dev_err(*plVar7,"couldn\'t register sysfs group\n");
        }
        goto LAB_00100800;
      }
    }
    _dev_err(*plVar7,"failed to enable regulators, ret:%d\n",uVar6);
    uVar8 = gpio_to_desc(*(undefined4 *)((long)plVar7 + 0x5c));
    gpiod_direction_output_raw(uVar8,0);
    usleep_range_state(20000,0x4e84,2);
    gpio_free(*(undefined4 *)((long)plVar7 + 0x5c));
  }
  *(undefined8 *)(param_1 + 0xb8) = 0;
LAB_00100800:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// max31760_remove @ 0010085c size=104
// signature: undefined max31760_remove(void)
// callers: [max31760_probe, max31760_shutdown]
//------------------------------------------------------------

void max31760_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  if (lVar2 != 0) {
    thermal_cooling_device_unregister(*(undefined8 *)(lVar2 + 0x10));
    regulator_disable(*(undefined8 *)(lVar2 + 0x48));
    regulator_disable(*(undefined8 *)(lVar2 + 0x50));
    uVar1 = gpio_to_desc(*(undefined4 *)(lVar2 + 0x5c));
    gpiod_direction_output_raw(uVar1,0);
    usleep_range_state(20000,0x4e84,2);
    gpio_free(*(undefined4 *)(lVar2 + 0x5c));
  }
  return;
}



//------------------------------------------------------------
// max31760_shutdown @ 001008c8 size=28
// signature: undefined max31760_shutdown(void)
// callers: []
//------------------------------------------------------------

void max31760_shutdown(void)

{
  max31760_remove();
  return;
}



//------------------------------------------------------------
// max31760_get_max_state @ 001008e8 size=16
// signature: undefined max31760_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 max31760_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 100;
  return 0;
}



//------------------------------------------------------------
// max31760_get_cur_state @ 001008fc size=80
// signature: undefined max31760_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 max31760_get_cur_state(long param_1,ulong *param_2)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x3b0);
  lVar1 = lVar2 + 0x18;
  mutex_lock(lVar1);
  *param_2 = (ulong)*(uint *)(lVar2 + 0x60);
  mutex_unlock(lVar1);
  return 0;
}



//------------------------------------------------------------
// max31760_set_cur_state @ 00100950 size=184
// signature: undefined max31760_set_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 max31760_set_cur_state(long param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x3b0);
  if (param_2 < 0x65) {
    mutex_lock(puVar3 + 3);
    if ((*(int *)((long)puVar3 + 100) == 0) &&
       (iVar1 = i2c_smbus_write_byte_data
                          (puVar3[1],0x50,((uint)((int)param_2 * 0xff) >> 2 & 0x3fff) / 0x19),
       iVar1 < 0)) {
      _dev_err(*puVar3,"failed write reg %#x failure, ret:%d\n",0x50,iVar1);
    }
    *(int *)(puVar3 + 0xc) = (int)param_2;
    mutex_unlock(puVar3 + 3);
    uVar2 = 0;
  }
  else {
    _dev_err(*puVar3,"fail to set current state\n");
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// speed_control_show @ 00100a0c size=84
// signature: undefined speed_control_show(void)
// callers: []
//------------------------------------------------------------

long speed_control_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_001018c8);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_00101683,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x60)
                     );
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// speed_control_store @ 00100a64 size=248
// signature: undefined speed_control_store(void)
// callers: []
//------------------------------------------------------------

undefined8
speed_control_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = kstrtoull(param_3,0,&local_40);
  if (iVar2 == 0) {
    mutex_lock(puVar3 + 3);
    lVar1 = local_40;
    if ((*(int *)((long)puVar3 + 100) == 0) &&
       (iVar2 = i2c_smbus_write_byte_data(puVar3[1],0x50,(ulong)(local_40 * 0xff) / 100), iVar2 < 0)
       ) {
      _dev_err(*puVar3,"failed write reg %#x failure, ret:%d\n",0x50,iVar2);
    }
    *(int *)(puVar3 + 0xc) = (int)lVar1;
    mutex_unlock(puVar3 + 3);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// speed_tc1_show @ 00100b60 size=228
// signature: undefined speed_tc1_show(void)
// callers: []
//------------------------------------------------------------

long speed_tc1_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  
  puVar7 = *(undefined8 **)(param_1 + 0x98);
  if (puVar7 == (undefined8 *)0x0) {
    _printk(&DAT_001018c8);
    lVar5 = -0x13;
  }
  else {
    uVar1 = i2c_smbus_read_byte_data(puVar7[1],0x52);
    if ((int)uVar1 < 0) {
      uVar4 = *puVar7;
      uVar6 = 0x52;
    }
    else {
      uVar2 = i2c_smbus_read_byte_data(puVar7[1],0x53);
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 & 0xff | (uVar1 & 0xff) << 8;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = 6000000 / uVar1;
        }
        iVar3 = scnprintf(param_3,0x1000,&DAT_00101683,uVar2 >> 1);
        return (long)iVar3;
      }
      uVar4 = *puVar7;
      uVar6 = 0x53;
      uVar1 = uVar2;
    }
    _dev_err(uVar4,"failed read reg 0x%02x failure, ret:%d\n",uVar6,uVar1);
    _dev_err(*puVar7,"can not read fan speed\n");
    lVar5 = -0x16;
  }
  return lVar5;
}



//------------------------------------------------------------
// speed_tc2_show @ 00100c48 size=228
// signature: undefined speed_tc2_show(void)
// callers: []
//------------------------------------------------------------

long speed_tc2_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  
  puVar7 = *(undefined8 **)(param_1 + 0x98);
  if (puVar7 == (undefined8 *)0x0) {
    _printk(&DAT_001018c8);
    lVar5 = -0x13;
  }
  else {
    uVar1 = i2c_smbus_read_byte_data(puVar7[1],0x54);
    if ((int)uVar1 < 0) {
      uVar4 = *puVar7;
      uVar6 = 0x54;
    }
    else {
      uVar2 = i2c_smbus_read_byte_data(puVar7[1],0x55);
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 & 0xff | (uVar1 & 0xff) << 8;
        uVar2 = 0;
        if (uVar1 != 0) {
          uVar2 = 6000000 / uVar1;
        }
        iVar3 = scnprintf(param_3,0x1000,&DAT_00101683,uVar2 >> 1);
        return (long)iVar3;
      }
      uVar4 = *puVar7;
      uVar6 = 0x55;
      uVar1 = uVar2;
    }
    _dev_err(uVar4,"failed read reg 0x%02x failure, ret:%d\n",uVar6,uVar1);
    _dev_err(*puVar7,"can not read fan speed\n");
    lVar5 = -0x16;
  }
  return lVar5;
}



//------------------------------------------------------------
// pwm_duty_show @ 00100d30 size=160
// signature: undefined pwm_duty_show(void)
// callers: []
//------------------------------------------------------------

long pwm_duty_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _printk(&DAT_001018c8);
    lVar3 = -0x13;
  }
  else {
    uVar1 = i2c_smbus_read_byte_data(puVar4[1],0x50);
    if ((int)uVar1 < 0) {
      _dev_err(*puVar4,"failed read reg 0x%02x failure, ret:%d\n",0x50,uVar1);
      lVar3 = (long)(int)uVar1;
    }
    else {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00101683,(uVar1 & 0xff) * 0x27);
      lVar3 = (long)iVar2;
    }
  }
  return lVar3;
}



//------------------------------------------------------------
// max31760_suspend @ 00100dd4 size=160
// signature: undefined max31760_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 max31760_suspend(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  if (puVar3 != (undefined8 *)0x0) {
    *(undefined4 *)((long)puVar3 + 100) = 1;
    mutex_lock(puVar3 + 3);
    iVar1 = i2c_smbus_write_byte_data(puVar3[1],0x50,0);
    if (iVar1 < 0) {
      _dev_err(*puVar3,"failed write reg %#x failure, ret:%d\n",0x50,iVar1);
    }
    uVar2 = gpio_to_desc(*(undefined4 *)((long)puVar3 + 0x5c));
    gpiod_direction_output_raw(uVar2,0);
    usleep_range_state(20000,0x4e84,2);
    regulator_disable(puVar3[9]);
    mutex_unlock(puVar3 + 3);
  }
  return 0;
}



//------------------------------------------------------------
// max31760_resume @ 00100e78 size=416
// signature: undefined max31760_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 max31760_resume(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    return 0;
  }
  *(undefined4 *)((long)puVar4 + 100) = 0;
  mutex_lock(puVar4 + 3);
  uVar3 = gpio_to_desc(*(undefined4 *)((long)puVar4 + 0x5c));
  gpiod_direction_output_raw(uVar3,1);
  usleep_range_state(20000,0x4e84,2);
  iVar2 = regulator_enable(puVar4[9]);
  if (iVar2 < 0) {
    _dev_err(*puVar4,"vdd_reg regulator failed, ret:%d\n",iVar2);
  }
  iVar2 = i2c_smbus_write_byte_data(puVar4[1],0,0x19);
  if (iVar2 < 0) {
    _dev_err(*puVar4,"failed write reg %#x failure, ret:%d\n",0,iVar2);
  }
  iVar2 = i2c_smbus_write_byte_data(puVar4[1],1,0x11);
  if (iVar2 < 0) {
    _dev_err(*puVar4,"failed write reg %#x failure, ret:%d\n",1,iVar2);
  }
  if (*(int *)(puVar4 + 0xb) == 2) {
    iVar2 = i2c_smbus_write_byte_data(puVar4[1],2,0x33);
  }
  else {
    if (*(int *)(puVar4 + 0xb) != 1) goto LAB_00100f20;
    iVar2 = i2c_smbus_write_byte_data(puVar4[1],2,0x31);
  }
  if (iVar2 < 0) {
    _dev_err(*puVar4,"failed write reg %#x failure, ret:%d\n",2,iVar2);
  }
LAB_00100f20:
  uVar1 = *(uint *)(puVar4 + 0xc);
  if ((*(int *)((long)puVar4 + 100) == 0) &&
     (iVar2 = i2c_smbus_write_byte_data(puVar4[1],0x50,((ulong)uVar1 * 0xff) / 100), iVar2 < 0)) {
    _dev_err(*puVar4,"failed write reg %#x failure, ret:%d\n",0x50,iVar2);
  }
  *(uint *)(puVar4 + 0xc) = uVar1;
  mutex_unlock(puVar4 + 3);
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010101c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&max31760_i2c_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010104c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&max31760_i2c_driver);
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
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103018 size=1
// signature: undefined __mutex_init(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00103028 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 00103030 size=1
// signature: undefined gpio_request(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00103038 size=1
// signature: undefined gpio_to_desc(void)
// callers: [max31760_remove, max31760_probe, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00103040 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [max31760_remove, max31760_probe, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00103048 size=1
// signature: undefined usleep_range_state(void)
// callers: [max31760_remove, max31760_probe, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00103050 size=1
// signature: undefined devm_regulator_get(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00103058 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00103060 size=1
// signature: undefined regulator_set_load(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00103068 size=1
// signature: undefined regulator_enable(void)
// callers: [max31760_probe, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_smbus_write_byte_data @ 00103070 size=1
// signature: undefined i2c_smbus_write_byte_data(void)
// callers: [max31760_set_cur_state, speed_control_store, max31760_probe, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_smbus_write_byte_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103078 size=1
// signature: undefined mutex_lock(void)
// callers: [max31760_set_cur_state, max31760_get_cur_state, speed_control_store, max31760_probe, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103080 size=1
// signature: undefined mutex_unlock(void)
// callers: [max31760_set_cur_state, max31760_get_cur_state, speed_control_store, max31760_probe, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 00103088 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_device_add_group @ 00103090 size=1
// signature: undefined devm_device_add_group(void)
// callers: [max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_device_add_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103098 size=1
// signature: undefined _dev_err(void)
// callers: [max31760_set_cur_state, pwm_duty_show, speed_control_store, max31760_probe, speed_tc1_show, speed_tc2_show, max31760_suspend, max31760_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030a0 size=1
// signature: undefined _printk(void)
// callers: [speed_control_show, pwm_duty_show, max31760_probe, speed_tc1_show, speed_tc2_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 001030a8 size=1
// signature: undefined gpio_free(void)
// callers: [max31760_remove, max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030b0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [speed_control_store, max31760_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 001030b8 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [max31760_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001030c0 size=1
// signature: undefined regulator_disable(void)
// callers: [max31760_remove, max31760_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001030c8 size=1
// signature: undefined scnprintf(void)
// callers: [speed_control_show, pwm_duty_show, speed_tc1_show, speed_tc2_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 001030d0 size=1
// signature: undefined kstrtoull(void)
// callers: [speed_control_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_smbus_read_byte_data @ 001030d8 size=1
// signature: undefined i2c_smbus_read_byte_data(void)
// callers: [pwm_duty_show, speed_tc1_show, speed_tc2_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_smbus_read_byte_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



