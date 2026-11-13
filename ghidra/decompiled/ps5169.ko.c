// Decompiled by Ghidra 12.2
// Program: ps5169.ko
// Image base: 00100000

//------------------------------------------------------------
// ps5169_i2c_probe @ 00100714 size=940
// signature: undefined ps5169_i2c_probe(void)
// callers: []
//------------------------------------------------------------

ulong ps5169_i2c_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  ulong uVar7;
  char *pcVar8;
  ulong uVar9;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  lVar1 = param_1 + 0x20;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  lVar4 = devm_kmalloc(lVar1,0x128,0xdc0);
  if (lVar4 == 0) {
LAB_001007f4:
    uVar9 = 0xfffffff4;
    goto LAB_001007f8;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x308);
  *(long *)(lVar4 + 0x58) = lVar1;
  *(long *)(lVar4 + 0x60) = param_1;
  uVar2 = of_get_named_gpio_flags(uVar5,"redriver,enable-gpio",0,0);
  *(uint *)(lVar4 + 0xb8) = uVar2;
  if (uVar2 < 0x200) {
    iVar3 = devm_gpio_request_one(lVar1,uVar2,0,"redriver-enable-gpio");
    if (iVar3 < 0) {
      _dev_err(lVar1,"Failed to request enable gpio\n");
      *(undefined4 *)(lVar4 + 0xb8) = 0xffffffea;
    }
  }
  else {
    _dev_err(lVar1,"Failed to get enable gpio\n");
  }
  of_get_property(*(undefined8 *)(param_1 + 0x308),"config-seq",(long)&local_40 + 4);
  if ((local_40._4_4_ == 0) ||
     (uVar9 = (long)local_40._4_4_ * -0x5555555555555555,
     0x1555555555555555 < (uVar9 >> 2 | uVar9 << 0x3e))) {
    _dev_err(lVar1,"no config-seq or size is wrong\n");
    uVar9 = 0xffffffea;
    goto LAB_001007f8;
  }
  lVar6 = devm_kmalloc(lVar1,(long)local_40._4_4_,0xdc0);
  *(long *)(lVar4 + 0x80) = lVar6;
  if (lVar6 == 0) goto LAB_001007f4;
  uVar5 = *(undefined8 *)(param_1 + 0x308);
  iVar3 = (int)((ulong)(long)local_40._4_4_ / 0xc);
  *(int *)(lVar4 + 0x88) = iVar3;
  of_property_read_variable_u32_array(uVar5,"config-seq",lVar6,iVar3 * 3,0);
  uVar9 = __devm_regmap_init_i2c(param_1,ps5169_regmap,0,0);
  *(ulong *)(lVar4 + 0x78) = uVar9;
  if (0xfffffffffffff000 < uVar9) {
    _dev_err(lVar1,"failed to allocate register map: %d\n",uVar9 & 0xffffffff);
    goto LAB_001007f8;
  }
  uVar7 = devm_regulator_get_optional(lVar1,&DAT_0010392d);
  pcVar8 = "Could not get vcc power regulator\n";
  *(ulong *)(lVar4 + 0x68) = uVar7;
  if ((uVar7 < 0xfffffffffffff001) && (uVar7 != 0)) {
    iVar3 = regulator_enable(uVar7,"Could not get vcc power regulator\n");
    if (iVar3 != 0) {
      pcVar8 = "Could not enable vcc power regulator\n";
      goto LAB_0010091c;
    }
  }
  else {
LAB_0010091c:
    _dev_err(lVar1,pcVar8);
  }
  uVar7 = devm_regulator_get_optional(lVar1,&DAT_00103a33);
  pcVar8 = "Could not get vio power regulator\n";
  *(ulong *)(lVar4 + 0x70) = uVar7;
  if ((uVar7 < 0xfffffffffffff001) && (uVar7 != 0)) {
    iVar3 = regulator_enable(uVar7,"Could not get vio power regulator\n");
    if (iVar3 != 0) {
      pcVar8 = "Could not enable vio power regulator\n";
      goto LAB_0010095c;
    }
  }
  else {
LAB_0010095c:
    _dev_err(lVar1,pcVar8);
  }
  ps5169_redriver_enable_chip(lVar4,1);
  iVar3 = regmap_raw_read(uVar9,0xac,&local_40,2);
  if (iVar3 == 0) {
    if ((int)local_40 != 0x6987) {
      pcVar8 = "%s,device id unknown: 0x%x\n";
      iVar3 = (int)local_40;
      goto LAB_001009b0;
    }
  }
  else {
    pcVar8 = "%s,device id read failed:%d\n";
LAB_001009b0:
    _dev_err(lVar1,pcVar8,"ps5169_i2c_probe",iVar3);
  }
  _dev_info(param_1 + 0x20,"%s,device_id=0x%x\n","ps5169_i2c_probe",local_40 & 0xffffffff);
  *(long *)(param_1 + 0xb8) = lVar4;
  ps5169_config_seqs_init(lVar4);
  ps5169_config_work_mode(lVar4,0);
  *(undefined4 *)(lVar4 + 0xb4) = 0;
  ps5169_redriver_enable_chip(lVar4,0);
  ps5169_debugfs_create(lVar4);
  *(undefined8 *)(lVar4 + 0xc0) = 0xfffffffe0;
  *(long *)(lVar4 + 200) = lVar4 + 200;
  *(long *)(lVar4 + 0xd0) = lVar4 + 200;
  *(code **)(lVar4 + 0xd8) = ps5169_gadget_pullup_work;
  *(undefined8 *)(lVar4 + 0xf8) = 0xfffffffe0;
  *(long *)(lVar4 + 0x100) = lVar4 + 0x100;
  *(long *)(lVar4 + 0x108) = lVar4 + 0x100;
  *(code **)(lVar4 + 0x110) = ps5169_host_work;
  *(undefined8 *)(lVar4 + 0x10) = *(undefined8 *)(*(long *)(lVar4 + 0x58) + 0x2e8);
  *(code **)(lVar4 + 0x18) = ps5169_release_usb_lanes;
  *(code **)(lVar4 + 0x20) = ps5169_notify_connect;
  *(code **)(lVar4 + 0x28) = ps5169_notify_disconnect;
  *(code **)(lVar4 + 0x30) = ps5169_gadget_pullup_enter;
  *(code **)(lVar4 + 0x38) = ps5169_gadget_pullup_exit;
  *(code **)(lVar4 + 0x40) = ps5169_host_powercycle;
  usb_add_redriver(lVar4);
  _dev_info(param_1 + 0x20,"%s,ps5169 probe done.\n","ps5169_i2c_probe");
  uVar9 = 0;
LAB_001007f8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// ps5169_i2c_remove @ 00100ac4 size=136
// signature: undefined ps5169_i2c_remove(void)
// callers: []
//------------------------------------------------------------

void ps5169_i2c_remove(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  iVar1 = usb_remove_redriver(lVar2);
  if (iVar1 == 0) {
    debugfs_remove(*(undefined8 *)(lVar2 + 0x90));
    if ((*(ulong *)(lVar2 + 0x68) != 0) && (*(ulong *)(lVar2 + 0x68) < 0xfffffffffffff001)) {
      iVar1 = regulator_is_enabled();
      if (iVar1 != 0) {
        regulator_disable(*(undefined8 *)(lVar2 + 0x68));
      }
      devm_regulator_put(*(undefined8 *)(lVar2 + 0x68));
    }
    if ((*(ulong *)(lVar2 + 0x70) != 0) && (*(ulong *)(lVar2 + 0x70) < 0xfffffffffffff001)) {
      iVar1 = regulator_is_enabled();
      if (iVar1 != 0) {
        regulator_disable(*(undefined8 *)(lVar2 + 0x70));
      }
      devm_regulator_put(*(undefined8 *)(lVar2 + 0x70));
    }
  }
  return;
}



//------------------------------------------------------------
// ps5169_i2c_shutdown @ 00100b50 size=120
// signature: undefined ps5169_i2c_shutdown(void)
// callers: []
//------------------------------------------------------------

void ps5169_i2c_shutdown(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar1 = *(uint *)(*(long *)(param_1 + 0xb8) + 0xb8);
  if (uVar1 < 0x200) {
    uVar2 = gpio_to_desc(uVar1);
    gpiod_set_raw_value(uVar2,0);
  }
  else {
    _dev_err(*(undefined8 *)(*(long *)(param_1 + 0xb8) + 0x58),"%s: Invalid enable_gpio: %d\n",
             "ps5169_redriver_enable_chip");
    _dev_err(param_1 + 0x20,"%s: fail to disable redriver.\n","ps5169_i2c_shutdown");
  }
  return;
}



//------------------------------------------------------------
// ps5169_redriver_enable_chip @ 00100bc8 size=220
// signature: undefined ps5169_redriver_enable_chip(void)
// callers: [ps5169_release_usb_lanes, ps5169_notify_connect, redriver_i2c_resume, ps5169_host_work, ps5169_i2c_probe, ps5169_gadget_pullup_work]
//------------------------------------------------------------

void ps5169_redriver_enable_chip(long param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (*(uint *)(param_1 + 0xb8) < 0x200) {
    uVar1 = gpio_to_desc(*(uint *)(param_1 + 0xb8));
    gpiod_set_raw_value(uVar1,param_2 & 1);
    if ((param_2 & 1) != 0) {
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
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + 0x58),"%s: Invalid enable_gpio: %d\n",
             "ps5169_redriver_enable_chip");
  }
  return;
}



//------------------------------------------------------------
// ps5169_config_seqs_init @ 00100ca4 size=120
// signature: undefined ps5169_config_seqs_init(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

void ps5169_config_seqs_init(long param_1)

{
  int iVar1;
  
  regmap_register_patch
            (*(undefined8 *)(param_1 + 0x78),*(undefined8 *)(param_1 + 0x80),
             *(undefined4 *)(param_1 + 0x88));
  iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x40,0x80,0x80,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar1);
  }
  return;
}



//------------------------------------------------------------
// ps5169_config_work_mode @ 00100d1c size=560
// signature: undefined ps5169_config_work_mode(void)
// callers: [ps5169_release_usb_lanes, ps5169_notify_connect, redriver_i2c_resume, ps5169_host_work, ps5169_i2c_probe, ps5169_gadget_pullup_work]
//------------------------------------------------------------

void ps5169_config_work_mode(long param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  long lVar6;
  
  switch(param_2) {
  case 0:
    iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x40,0xe0,0x80,0,0,0);
    if (iVar1 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar1);
    }
    iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0xa0,0xff,2,0,0,0);
    if (iVar1 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0xa0,iVar1);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x78);
    uVar3 = 0;
    goto LAB_00100e78;
  case 1:
    uVar4 = 0xd0;
    if (*(int *)(param_1 + 0xb0) != 1) {
      uVar4 = 0xc0;
    }
    iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x40,0xf0,uVar4,0,0,0);
    if (-1 < iVar1) {
      return;
    }
    lVar6 = *(long *)(param_1 + 0x60);
    uVar2 = 0x40;
    goto LAB_00100eb0;
  case 2:
    iVar1 = *(int *)(param_1 + 0xb0);
    uVar4 = 0xb0;
    uVar5 = 0xa0;
    break;
  case 3:
    iVar1 = *(int *)(param_1 + 0xb0);
    uVar4 = 0xf0;
    uVar5 = 0xe0;
    break;
  default:
    _printk(&DAT_00103afd);
    return;
  }
  if (iVar1 != 1) {
    uVar4 = uVar5;
  }
  iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x40,0xf0,uVar4,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar1);
  }
  iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0xa0,0xff,0,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0xa0,iVar1);
  }
  uVar2 = *(undefined8 *)(param_1 + 0x78);
  uVar3 = 4;
LAB_00100e78:
  iVar1 = regmap_update_bits_base(uVar2,0xa1,0xff,uVar3,0,0,0);
  if (iVar1 < 0) {
    lVar6 = *(long *)(param_1 + 0x60);
    uVar2 = 0xa1;
LAB_00100eb0:
    _dev_err(lVar6 + 0x20,"error update reg %u, ret=%d\n",uVar2,iVar1);
  }
  return;
}



//------------------------------------------------------------
// ps5169_debugfs_create @ 00100f4c size=308
// signature: undefined ps5169_debugfs_create(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

void ps5169_debugfs_create(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x60);
  lVar1 = debugfs_create_dir("ps5169",0);
  *(long *)(param_1 + 0x90) = lVar1;
  if (lVar1 == 0) {
    _dev_warn(lVar2 + 0x20,"couldn\'t create debug dir\n");
  }
  else {
    debugfs_create_file("dp-eq",0x1a4,lVar1,param_1,&dp_eq_ops);
    debugfs_create_file("dp-gain",0x1a4,*(undefined8 *)(param_1 + 0x90),param_1,&dp_gain_ops);
    debugfs_create_file("usb-tx-eq",0x1a4,*(undefined8 *)(param_1 + 0x90),param_1,&usb_tx_eq_ops);
    debugfs_create_file("usb-tx-gain",0x1a4,*(undefined8 *)(param_1 + 0x90),param_1,&usb_tx_gain_ops
                       );
    debugfs_create_file("usb-rx-eq",0x1a4,*(undefined8 *)(param_1 + 0x90),param_1,&usb_rx_eq_ops);
    debugfs_create_file("usb-rx-gain",0x1a4,*(undefined8 *)(param_1 + 0x90),param_1,&usb_rx_gain_ops
                       );
    debugfs_create_file("config_seqs",0x124,*(undefined8 *)(param_1 + 0x90),param_1,
                        &config_seqs_fops);
  }
  return;
}



//------------------------------------------------------------
// ps5169_gadget_pullup_work @ 00101084 size=220
// signature: undefined ps5169_gadget_pullup_work(void)
// callers: []
//------------------------------------------------------------

void ps5169_gadget_pullup_work(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(uint *)(param_1 + -8) < 0x200) {
    uVar2 = gpio_to_desc(*(uint *)(param_1 + -8));
    gpiod_set_raw_value(uVar2,0);
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + -0x68),"%s: Invalid enable_gpio: %d\n",
             "ps5169_redriver_enable_chip");
  }
  usleep_range_state(1000,0x5dc,2);
  ps5169_redriver_enable_chip(param_1 + -0xc0,1);
  regmap_register_patch
            (*(undefined8 *)(param_1 + -0x48),*(undefined8 *)(param_1 + -0x40),
             *(undefined4 *)(param_1 + -0x38));
  iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + -0x48),0x40,0x80,0x80,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(long *)(param_1 + -0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar1);
  }
  ps5169_config_work_mode(param_1 + -0xc0,*(undefined4 *)(param_1 + -0xc));
  *(undefined1 *)(param_1 + 0x30) = 0;
  return;
}



//------------------------------------------------------------
// ps5169_host_work @ 00101164 size=216
// signature: undefined ps5169_host_work(void)
// callers: []
//------------------------------------------------------------

void ps5169_host_work(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(uint *)(param_1 + -0x40) < 0x200) {
    uVar2 = gpio_to_desc(*(uint *)(param_1 + -0x40));
    gpiod_set_raw_value(uVar2,0);
  }
  else {
    _dev_err(*(undefined8 *)(param_1 + -0xa0),"%s: Invalid enable_gpio: %d\n",
             "ps5169_redriver_enable_chip");
  }
  usleep_range_state(2000,0x9c4,2);
  ps5169_redriver_enable_chip(param_1 + -0xf8,1);
  regmap_register_patch
            (*(undefined8 *)(param_1 + -0x80),*(undefined8 *)(param_1 + -0x78),
             *(undefined4 *)(param_1 + -0x70));
  iVar1 = regmap_update_bits_base(*(undefined8 *)(param_1 + -0x80),0x40,0x80,0x80,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*(long *)(param_1 + -0x98) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar1);
  }
  ps5169_config_work_mode(param_1 + -0xf8,*(undefined4 *)(param_1 + -0x44));
  return;
}



//------------------------------------------------------------
// ps5169_release_usb_lanes @ 00101240 size=264
// signature: undefined ps5169_release_usb_lanes(void)
// callers: []
//------------------------------------------------------------

undefined8 ps5169_release_usb_lanes(long param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  
  if (param_3 == 4) {
    uVar4 = 2;
  }
  else if (param_3 == 2) {
    uVar4 = 3;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xb4);
  }
  uVar1 = *(uint *)(param_1 + 0xb4);
  *(undefined4 *)(param_1 + 0xb0) = param_2;
  if (uVar4 != uVar1) {
    if ((4 < uVar1) || (4 < uVar4)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101348);
      (*pcVar2)();
    }
    _dev_info(*(undefined8 *)(param_1 + 0x58),"%s: op mode %s -> %s\n","ps5169_release_usb_lanes",
              (&opmode_string)[uVar1],(&opmode_string)[uVar4]);
    *(uint *)(param_1 + 0xb4) = uVar4;
    ps5169_redriver_enable_chip(param_1,1);
    regmap_register_patch
              (*(undefined8 *)(param_1 + 0x78),*(undefined8 *)(param_1 + 0x80),
               *(undefined4 *)(param_1 + 0x88));
    iVar3 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x40,0x80,0x80,0,0,0);
    if (iVar3 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar3);
    }
    ps5169_config_work_mode(param_1,uVar4);
  }
  return 0;
}



//------------------------------------------------------------
// ps5169_notify_connect @ 0010134c size=252
// signature: undefined ps5169_notify_connect(void)
// callers: []
//------------------------------------------------------------

undefined8 ps5169_notify_connect(long param_1,int param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  
  uVar3 = *(uint *)(param_1 + 0xb4);
  uVar2 = uVar3;
  if (uVar3 == 0) {
    uVar2 = 1;
  }
  if (4 < uVar3 || 4 < uVar2) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101448);
    (*pcVar4)();
  }
  puVar1 = &DAT_00103af9;
  if (param_2 != 0) {
    puVar1 = &DAT_00103a4a;
  }
  _dev_info(*(undefined8 *)(param_1 + 0x58),"%s: op mode %s -> %s, orientation %s\n",
            "ps5169_notify_connect",(&opmode_string)[uVar3],(&opmode_string)[uVar2],puVar1);
  *(int *)(param_1 + 0xb0) = param_2;
  *(uint *)(param_1 + 0xb4) = uVar2;
  ps5169_redriver_enable_chip(param_1,1);
  regmap_register_patch
            (*(undefined8 *)(param_1 + 0x78),*(undefined8 *)(param_1 + 0x80),
             *(undefined4 *)(param_1 + 0x88));
  iVar5 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x40,0x80,0x80,0,0,0);
  if (iVar5 < 0) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar5);
  }
  ps5169_config_work_mode(param_1,*(undefined4 *)(param_1 + 0xb4));
  return 0;
}



//------------------------------------------------------------
// ps5169_notify_disconnect @ 0010144c size=168
// signature: undefined ps5169_notify_disconnect(void)
// callers: []
//------------------------------------------------------------

undefined8 ps5169_notify_disconnect(long param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  uVar1 = *(uint *)(param_1 + 0xb4);
  if (uVar1 != 0) {
    if (4 < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1014f4);
      (*pcVar2)();
    }
    _dev_info(*(undefined8 *)(param_1 + 0x58),"%s: op mode %s -> %s\n","ps5169_notify_disconnect",
              (&opmode_string)[uVar1],&DAT_00103a06);
    *(undefined4 *)(param_1 + 0xb4) = 0;
    if (*(uint *)(param_1 + 0xb8) < 0x200) {
      uVar3 = gpio_to_desc(*(uint *)(param_1 + 0xb8));
      gpiod_set_raw_value(uVar3,0);
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0x58),"%s: Invalid enable_gpio: %d\n",
               "ps5169_redriver_enable_chip");
    }
  }
  return 0;
}



//------------------------------------------------------------
// ps5169_gadget_pullup_enter @ 001014f8 size=224
// signature: undefined ps5169_gadget_pullup_enter(void)
// callers: []
//------------------------------------------------------------

undefined8 ps5169_gadget_pullup_enter(long param_1,int param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (4 < *(uint *)(param_1 + 0xb4)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1015d8);
    (*pcVar1)();
  }
  _dev_info(*(undefined8 *)(param_1 + 0x58),"%s: mode %s, %d, %d\n","ps5169_gadget_pullup_enter",
            (&opmode_string)[*(uint *)(param_1 + 0xb4)],param_2,*(undefined1 *)(param_1 + 0xf0));
  if (*(int *)(param_1 + 0xb4) == 1) {
    if (param_2 != 0) {
      lVar3 = 0;
      do {
        if (*(char *)(param_1 + 0xf0) == '\0') goto LAB_001015bc;
        __const_udelay(0x10c7);
        lVar3 = lVar3 + 1;
      } while (lVar3 != 0x7a122);
      _dev_warn(*(undefined8 *)(param_1 + 0x58),"pullup timeout\n");
      lVar3 = 0x7a122;
LAB_001015bc:
      _dev_info(*(undefined8 *)(param_1 + 0x58),"pull-up disable work took %llu us\n",lVar3);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// ps5169_gadget_pullup_exit @ 001015dc size=156
// signature: undefined ps5169_gadget_pullup_exit(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ps5169_gadget_pullup_exit(long param_1,int param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (4 < *(uint *)(param_1 + 0xb4)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101678);
    (*pcVar1)();
  }
  _dev_info(*(undefined8 *)(param_1 + 0x58),"%s: mode %s, %d, %d\n","ps5169_gadget_pullup_exit",
            (&opmode_string)[*(uint *)(param_1 + 0xb4)],param_2,*(undefined1 *)(param_1 + 0xf0));
  uVar2 = _system_highpri_wq;
  if (*(int *)(param_1 + 0xb4) == 1) {
    if (param_2 == 0) {
      *(undefined1 *)(param_1 + 0xf0) = 1;
      queue_work_on(0x20,uVar2,param_1 + 0xc0);
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// ps5169_host_powercycle @ 0010167c size=68
// signature: undefined ps5169_host_powercycle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ps5169_host_powercycle(long param_1)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0xb4) == 1) {
    queue_work_on(0x20,_system_wq,param_1 + 0xf8);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// dp_eq_ops_open @ 001016c4 size=52
// signature: undefined dp_eq_ops_open(void)
// callers: []
//------------------------------------------------------------

void dp_eq_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,dp_eq_get,dp_eq_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// dp_eq_get @ 001016fc size=16
// signature: undefined dp_eq_get(void)
// callers: []
//------------------------------------------------------------

undefined8 dp_eq_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x98);
  return 0;
}



//------------------------------------------------------------
// dp_eq_set @ 00101710 size=604
// signature: undefined dp_eq_set(void)
// callers: []
//------------------------------------------------------------

undefined8 dp_eq_set(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  
  if (5 < (uint)param_2) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error dp eq value %u\n",param_2 & 0xffffffff);
    return 0xffffffea;
  }
  uVar6 = param_2 & 0xffffffff;
  if (uVar6 < 8) {
    iVar5 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x78),0x52,0x70,*(undefined4 *)(dp_eq + uVar6 * 8),
                       0,0,0);
    if (iVar5 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x52,iVar5);
    }
    if ((uVar6 << 3 | 4) < 0x41) {
      iVar5 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x78),0x5e,7,
                         *(undefined4 *)(dp_eq + uVar6 * 8 + 4),0,0,0);
      if (iVar5 < 0) {
        _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x5e,iVar5);
      }
      *(uint *)(param_1 + 0x98) = (uint)param_2;
      if (7 < param_2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10196c);
        (*pcVar4)();
      }
      if ((param_2 & 0x1ffffffffffffff8) == 0) {
        if (*(int *)(param_1 + 0x88) != 0) {
          iVar5 = 0;
          uVar3 = *(uint *)(dp_eq + param_2 * 8);
          do {
            if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar5 * 0xc) == 0x52) {
              lVar1 = *(long *)(param_1 + 0x80) + (long)iVar5 * 0xc;
              *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff8f;
              lVar1 = *(long *)(param_1 + 0x80) + (long)iVar5 * 0xc;
              *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar3 & 0x70;
              iVar2 = *(int *)(param_1 + 0x88);
              if (iVar2 != iVar5) goto LAB_00101838;
              break;
            }
            iVar5 = iVar5 + 1;
          } while (*(int *)(param_1 + 0x88) != iVar5);
        }
        _printk(&DAT_00103a8c,0x52);
        iVar2 = *(int *)(param_1 + 0x88);
LAB_00101838:
        if ((param_2 << 3 | 4) < 0x41) {
          if (iVar2 != 0) {
            iVar5 = 0;
            uVar3 = *(uint *)(dp_eq + param_2 * 8 + 4);
            do {
              if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar5 * 0xc) == 0x5e) {
                lVar1 = *(long *)(param_1 + 0x80) + (long)iVar5 * 0xc;
                *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffff8;
                lVar1 = *(long *)(param_1 + 0x80) + (long)iVar5 * 0xc;
                *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar3 & 7;
                if (*(int *)(param_1 + 0x88) != iVar5) {
                  return 0;
                }
                break;
              }
              iVar5 = iVar5 + 1;
            } while (iVar2 != iVar5);
          }
          _printk(&DAT_00103a8c,0x5e);
          return 0;
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(1,0x101968);
  (*pcVar4)();
}



//------------------------------------------------------------
// dp_gain_ops_open @ 00101970 size=52
// signature: undefined dp_gain_ops_open(void)
// callers: []
//------------------------------------------------------------

void dp_gain_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,dp_gain_get,dp_gain_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// dp_gain_get @ 001019a8 size=16
// signature: undefined dp_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 dp_gain_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0x9c);
  return 0;
}



//------------------------------------------------------------
// dp_gain_set @ 001019bc size=292
// signature: undefined dp_gain_set(void)
// callers: []
//------------------------------------------------------------

undefined8 dp_gain_set(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 < 2) {
    iVar2 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x5c,0x10,param_2,0,0,0);
    if (iVar2 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x5c,iVar2);
    }
    *(uint *)(param_1 + 0x9c) = param_2;
    if (*(int *)(param_1 + 0x88) != 0) {
      iVar2 = 0;
      do {
        if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar2 * 0xc) == 0x5c) {
          lVar1 = *(long *)(param_1 + 0x80) + (long)iVar2 * 0xc;
          *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffffef;
          lVar1 = *(long *)(param_1 + 0x80) + (long)iVar2 * 0xc;
          *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | param_2 & 0x10;
          if (*(int *)(param_1 + 0x88) != iVar2) goto LAB_00101a78;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (*(int *)(param_1 + 0x88) != iVar2);
    }
    _printk(&DAT_00103a8c,0x5c);
LAB_00101a78:
    uVar3 = 0;
  }
  else {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error dp gain value %u\n",param_2);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// usb_tx_eq_ops_open @ 00101ae4 size=52
// signature: undefined usb_tx_eq_ops_open(void)
// callers: []
//------------------------------------------------------------

void usb_tx_eq_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,usb_tx_eq_get,usb_tx_eq_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// usb_tx_eq_get @ 00101b1c size=16
// signature: undefined usb_tx_eq_get(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_tx_eq_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0xa0);
  return 0;
}



//------------------------------------------------------------
// usb_tx_eq_set @ 00101b30 size=896
// signature: undefined usb_tx_eq_set(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_tx_eq_set(long param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  
  if (7 < (uint)param_2) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error usb tx eq value %u\n",param_2 & 0xffffffff);
    return 0xffffffea;
  }
  uVar6 = param_2 & 0xffffffff;
  if (((uVar6 + (param_2 & 0xffffffff) * 2) * 4 < 0x61) && (uVar6 != 8)) {
    iVar4 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x78),0x50,0x70,
                       *(undefined4 *)(usb_tx_eq + uVar6 * 0xc),0,0,0);
    if (iVar4 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x50,iVar4);
    }
    if (uVar6 * 0xc < 0x5d) {
      iVar4 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x78),0x5d,0x70,
                         *(undefined4 *)(usb_tx_eq + uVar6 * 0xc + 4),0,0,0);
      if (iVar4 < 0) {
        _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x5d,iVar4);
      }
      if (uVar6 * 0xc < 0x59) {
        iVar4 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x78),0x54,0xf0,
                           *(undefined4 *)(usb_tx_eq + uVar6 * 0xc + 8),0,0,0);
        if (iVar4 < 0) {
          _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x54,iVar4);
        }
        *(uint *)(param_1 + 0xa0) = (uint)param_2;
        if (7 < param_2) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101eb0);
          (*pcVar3)();
        }
        if (param_2 * 0xc < 0x60) {
          if (*(int *)(param_1 + 0x88) != 0) {
            iVar4 = 0;
            uVar2 = *(uint *)(usb_tx_eq + param_2 * 0xc);
            do {
              if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x50) {
                lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff8f;
                lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0x70;
                iVar5 = *(int *)(param_1 + 0x88);
                if (iVar5 != iVar4) goto LAB_00101cb4;
                break;
              }
              iVar4 = iVar4 + 1;
            } while (*(int *)(param_1 + 0x88) != iVar4);
          }
          _printk(&DAT_00103a8c,0x50);
          iVar5 = *(int *)(param_1 + 0x88);
LAB_00101cb4:
          if (0xffffffffffffff9f < param_2 * 0xc - 0x5c) {
            if (iVar5 != 0) {
              iVar4 = 0;
              uVar2 = *(uint *)(usb_tx_eq + param_2 * 0xc + 4);
              do {
                if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x5d) {
                  lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                  *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff8f;
                  lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                  *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0x70;
                  iVar5 = *(int *)(param_1 + 0x88);
                  if (iVar5 != iVar4) goto LAB_00101d40;
                  break;
                }
                iVar4 = iVar4 + 1;
              } while (iVar5 != iVar4);
            }
            _printk(&DAT_00103a8c,0x5d);
            iVar5 = *(int *)(param_1 + 0x88);
LAB_00101d40:
            if (0xffffffffffffff9f < param_2 * 0xc - 0x58) {
              if (iVar5 != 0) {
                iVar4 = 0;
                uVar2 = *(uint *)(usb_tx_eq + param_2 * 0xc + 8);
                do {
                  if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x54) {
                    lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff0f;
                    lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0xf0;
                    if (*(int *)(param_1 + 0x88) != iVar4) {
                      return 0;
                    }
                    break;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar5 != iVar4);
              }
              _printk(&DAT_00103a8c,0x54);
              return 0;
            }
          }
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x101eac);
  (*pcVar3)();
}



//------------------------------------------------------------
// usb_tx_gain_ops_open @ 00101eb4 size=52
// signature: undefined usb_tx_gain_ops_open(void)
// callers: []
//------------------------------------------------------------

void usb_tx_gain_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,usb_tx_gain_get,usb_tx_gain_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// usb_tx_gain_get @ 00101eec size=16
// signature: undefined usb_tx_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_tx_gain_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0xa4);
  return 0;
}



//------------------------------------------------------------
// usb_tx_gain_set @ 00101f00 size=292
// signature: undefined usb_tx_gain_set(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_tx_gain_set(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 < 2) {
    iVar2 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x5c,1,param_2,0,0,0);
    if (iVar2 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x5c,iVar2);
    }
    *(uint *)(param_1 + 0xa4) = param_2;
    if (*(int *)(param_1 + 0x88) != 0) {
      iVar2 = 0;
      do {
        if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar2 * 0xc) == 0x5c) {
          lVar1 = *(long *)(param_1 + 0x80) + (long)iVar2 * 0xc;
          *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffffe;
          lVar1 = *(long *)(param_1 + 0x80) + (long)iVar2 * 0xc;
          *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | param_2 & 1;
          if (*(int *)(param_1 + 0x88) != iVar2) goto LAB_00101fbc;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (*(int *)(param_1 + 0x88) != iVar2);
    }
    _printk(&DAT_00103a8c,0x5c);
LAB_00101fbc:
    uVar3 = 0;
  }
  else {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error usb tx gain value %u\n",param_2);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// usb_rx_eq_ops_open @ 00102028 size=52
// signature: undefined usb_rx_eq_ops_open(void)
// callers: []
//------------------------------------------------------------

void usb_rx_eq_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,usb_rx_eq_get,usb_rx_eq_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// usb_rx_eq_get @ 00102060 size=16
// signature: undefined usb_rx_eq_get(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_rx_eq_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0xa8);
  return 0;
}



//------------------------------------------------------------
// usb_rx_eq_set @ 00102074 size=1108
// signature: undefined usb_rx_eq_set(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_rx_eq_set(long param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  
  if (7 < (uint)param_2) {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error usb rx eq value %u\n",param_2 & 0xffffffff);
    return 0xffffffea;
  }
  uVar6 = param_2 & 0xffffffff;
  if (uVar6 < 8) {
    iVar4 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x78),0x51,0x70,
                       *(undefined4 *)(usb_rx_eq + uVar6 * 0x10),0,0,0);
    if (iVar4 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x51,iVar4);
    }
    if ((uVar6 << 4 | 4) < 0x81) {
      iVar4 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 0x78),0x77,0xf0,
                         *(undefined4 *)(usb_rx_eq + uVar6 * 0x10 + 4),0,0,0);
      if (iVar4 < 0) {
        _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x77,iVar4);
      }
      if ((uVar6 << 4 | 8) < 0x81) {
        iVar4 = regmap_update_bits_base
                          (*(undefined8 *)(param_1 + 0x78),0x54,0xf,
                           *(undefined4 *)(usb_rx_eq + uVar6 * 0x10 + 8),0,0,0);
        if (iVar4 < 0) {
          _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x54,iVar4);
        }
        if ((uVar6 << 4 | 0xc) < 0x81) {
          iVar4 = regmap_update_bits_base
                            (*(undefined8 *)(param_1 + 0x78),0x78,0xe1,
                             *(undefined4 *)(usb_rx_eq + uVar6 * 0x10 + 0xc),0,0,0);
          if (iVar4 < 0) {
            _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x78,iVar4);
          }
          *(uint *)(param_1 + 0xa0) = (uint)param_2;
          if (7 < param_2) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1024c8);
            (*pcVar3)();
          }
          if ((param_2 & 0xffffffffffffff8) == 0) {
            if (*(int *)(param_1 + 0x88) != 0) {
              iVar4 = 0;
              uVar2 = *(uint *)(usb_rx_eq + param_2 * 0x10);
              do {
                if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x51) {
                  lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                  *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff8f;
                  lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                  *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0x70;
                  iVar5 = *(int *)(param_1 + 0x88);
                  if (iVar5 != iVar4) goto LAB_0010220c;
                  break;
                }
                iVar4 = iVar4 + 1;
              } while (*(int *)(param_1 + 0x88) != iVar4);
            }
            _printk(&DAT_00103a8c,0x51);
            iVar5 = *(int *)(param_1 + 0x88);
LAB_0010220c:
            if ((param_2 << 4 | 4) < 0x81) {
              if (iVar5 != 0) {
                iVar4 = 0;
                uVar2 = *(uint *)(usb_rx_eq + param_2 * 0x10 + 4);
                do {
                  if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x77) {
                    lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff0f;
                    lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                    *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0xf0;
                    iVar5 = *(int *)(param_1 + 0x88);
                    if (iVar5 != iVar4) goto LAB_00102294;
                    break;
                  }
                  iVar4 = iVar4 + 1;
                } while (iVar5 != iVar4);
              }
              _printk(&DAT_00103a8c,0x77);
              iVar5 = *(int *)(param_1 + 0x88);
LAB_00102294:
              if ((param_2 << 4 | 8) < 0x81) {
                if (iVar5 != 0) {
                  iVar4 = 0;
                  uVar2 = *(uint *)(usb_rx_eq + param_2 * 0x10 + 8);
                  do {
                    if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x54) {
                      lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                      *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffff0;
                      lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                      *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0xf;
                      iVar5 = *(int *)(param_1 + 0x88);
                      if (iVar5 != iVar4) goto LAB_0010231c;
                      break;
                    }
                    iVar4 = iVar4 + 1;
                  } while (iVar5 != iVar4);
                }
                _printk(&DAT_00103a8c,0x54);
                iVar5 = *(int *)(param_1 + 0x88);
LAB_0010231c:
                if ((param_2 << 4 | 0xc) < 0x81) {
                  if (iVar5 != 0) {
                    iVar4 = 0;
                    uVar2 = *(uint *)(usb_rx_eq + param_2 * 0x10 + 0xc);
                    do {
                      if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar4 * 0xc) == 0x78) {
                        lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                        *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xffffff1e;
                        lVar1 = *(long *)(param_1 + 0x80) + (long)iVar4 * 0xc;
                        *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | uVar2 & 0xe1;
                        if (*(int *)(param_1 + 0x88) != iVar4) {
                          return 0;
                        }
                        break;
                      }
                      iVar4 = iVar4 + 1;
                    } while (iVar5 != iVar4);
                  }
                  _printk(&DAT_00103a8c,0x78);
                  return 0;
                }
              }
            }
          }
        }
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x1024c4);
  (*pcVar3)();
}



//------------------------------------------------------------
// usb_rx_gain_ops_open @ 001024cc size=52
// signature: undefined usb_rx_gain_ops_open(void)
// callers: []
//------------------------------------------------------------

void usb_rx_gain_ops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,usb_rx_gain_get,usb_rx_gain_set,"%llu\n");
  return;
}



//------------------------------------------------------------
// usb_rx_gain_get @ 00102504 size=16
// signature: undefined usb_rx_gain_get(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_rx_gain_get(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(param_1 + 0xac);
  return 0;
}



//------------------------------------------------------------
// usb_rx_gain_set @ 00102518 size=292
// signature: undefined usb_rx_gain_set(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_rx_gain_set(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 < 2) {
    iVar2 = regmap_update_bits_base(*(undefined8 *)(param_1 + 0x78),0x5c,4,param_2,0,0,0);
    if (iVar2 < 0) {
      _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x5c,iVar2);
    }
    *(uint *)(param_1 + 0xac) = param_2;
    if (*(int *)(param_1 + 0x88) != 0) {
      iVar2 = 0;
      do {
        if (*(int *)(*(long *)(param_1 + 0x80) + (long)iVar2 * 0xc) == 0x5c) {
          lVar1 = *(long *)(param_1 + 0x80) + (long)iVar2 * 0xc;
          *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) & 0xfffffffb;
          lVar1 = *(long *)(param_1 + 0x80) + (long)iVar2 * 0xc;
          *(uint *)(lVar1 + 4) = *(uint *)(lVar1 + 4) | param_2 & 4;
          if (*(int *)(param_1 + 0x88) != iVar2) goto LAB_001025d4;
          break;
        }
        iVar2 = iVar2 + 1;
      } while (*(int *)(param_1 + 0x88) != iVar2);
    }
    _printk(&DAT_00103a8c,0x5c);
LAB_001025d4:
    uVar3 = 0;
  }
  else {
    _dev_err(*(long *)(param_1 + 0x60) + 0x20,"error usb rx gain value %u\n",param_2);
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// config_seqs_open @ 00102640 size=48
// signature: undefined config_seqs_open(void)
// callers: []
//------------------------------------------------------------

void config_seqs_open(long param_1,undefined8 param_2)

{
  single_open(param_2,config_seqs_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// config_seqs_show @ 00102674 size=128
// signature: undefined config_seqs_show(void)
// callers: []
//------------------------------------------------------------

undefined8 config_seqs_show(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = *(long *)(param_1 + 0x80);
  if (*(int *)(lVar2 + 0x88) != 0) {
    uVar3 = 0;
    do {
      puVar1 = (undefined4 *)(*(long *)(lVar2 + 0x80) + (long)(int)uVar3 * 0xc);
      seq_printf(param_1,"0x%02x 0x%02x %u\n",*puVar1,puVar1[1],puVar1[2]);
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(lVar2 + 0x88));
  }
  return 0;
}



//------------------------------------------------------------
// redriver_i2c_suspend @ 001026f8 size=120
// signature: undefined redriver_i2c_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 redriver_i2c_suspend(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (4 < *(uint *)(lVar2 + 0xb4) || (1 << (ulong)(*(uint *)(lVar2 + 0xb4) & 0x1f) & 0x15U) == 0) {
    if (*(uint *)(lVar2 + 0xb8) < 0x200) {
      uVar1 = gpio_to_desc(*(uint *)(lVar2 + 0xb8));
      gpiod_set_raw_value(uVar1,0);
    }
    else {
      _dev_err(*(undefined8 *)(lVar2 + 0x58),"%s: Invalid enable_gpio: %d\n",
               "ps5169_redriver_enable_chip");
    }
  }
  return 0;
}



//------------------------------------------------------------
// redriver_i2c_resume @ 00102774 size=176
// signature: undefined redriver_i2c_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 redriver_i2c_resume(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (4 < *(uint *)(lVar2 + 0xb4) || (1 << (ulong)(*(uint *)(lVar2 + 0xb4) & 0x1f) & 0x15U) == 0) {
    ps5169_redriver_enable_chip(lVar2,1);
    regmap_register_patch
              (*(undefined8 *)(lVar2 + 0x78),*(undefined8 *)(lVar2 + 0x80),
               *(undefined4 *)(lVar2 + 0x88));
    iVar1 = regmap_update_bits_base(*(undefined8 *)(lVar2 + 0x78),0x40,0x80,0x80,0,0,0);
    if (iVar1 < 0) {
      _dev_err(*(long *)(lVar2 + 0x60) + 0x20,"error update reg %u, ret=%d\n",0x40,iVar1);
    }
    ps5169_config_work_mode(lVar2,*(undefined4 *)(lVar2 + 0xb4));
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102828 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&ps5169_i2c_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102858 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&ps5169_i2c_driver);
  return;
}



//------------------------------------------------------------
// i2c_register_driver @ 00105000 size=1
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
// i2c_del_driver @ 00105008 size=1
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
// devm_kmalloc @ 00105010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00105018 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 00105020 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00105028 size=1
// signature: undefined of_get_property(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105030 size=1
// signature: undefined _dev_err(void)
// callers: [ps5169_i2c_shutdown, ps5169_notify_disconnect, redriver_i2c_suspend, dp_gain_set, ps5169_release_usb_lanes, usb_tx_gain_set, usb_rx_gain_set, ps5169_i2c_probe, usb_rx_eq_set, dp_eq_set, ps5169_notify_connect, usb_tx_eq_set, redriver_i2c_resume, ps5169_redriver_enable_chip, ps5169_config_work_mode, ps5169_host_work, ps5169_config_seqs_init, ps5169_gadget_pullup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105038 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_i2c @ 00105040 size=1
// signature: undefined __devm_regmap_init_i2c(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_i2c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_optional @ 00105048 size=1
// signature: undefined devm_regulator_get_optional(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00105050 size=1
// signature: undefined regulator_enable(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_raw_read @ 00105058 size=1
// signature: undefined regmap_raw_read(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_raw_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00105060 size=1
// signature: undefined _dev_info(void)
// callers: [ps5169_gadget_pullup_exit, ps5169_notify_disconnect, ps5169_release_usb_lanes, ps5169_notify_connect, ps5169_gadget_pullup_enter, ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_redriver @ 00105068 size=1
// signature: undefined usb_add_redriver(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_redriver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ps5169_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_redriver @ 00105078 size=1
// signature: undefined usb_remove_redriver(void)
// callers: [ps5169_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_redriver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105080 size=1
// signature: undefined debugfs_remove(void)
// callers: [ps5169_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled @ 00105088 size=1
// signature: undefined regulator_is_enabled(void)
// callers: [ps5169_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00105090 size=1
// signature: undefined regulator_disable(void)
// callers: [ps5169_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_put @ 00105098 size=1
// signature: undefined devm_regulator_put(void)
// callers: [ps5169_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 001050a0 size=1
// signature: undefined gpio_to_desc(void)
// callers: [ps5169_i2c_shutdown, ps5169_notify_disconnect, redriver_i2c_suspend, ps5169_redriver_enable_chip, ps5169_host_work, ps5169_gadget_pullup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 001050a8 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [ps5169_i2c_shutdown, ps5169_notify_disconnect, redriver_i2c_suspend, ps5169_redriver_enable_chip, ps5169_host_work, ps5169_gadget_pullup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001050b0 size=1
// signature: undefined __const_udelay(void)
// callers: [ps5169_gadget_pullup_enter, ps5169_redriver_enable_chip]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_register_patch @ 001050b8 size=1
// signature: undefined regmap_register_patch(void)
// callers: [ps5169_release_usb_lanes, ps5169_notify_connect, redriver_i2c_resume, ps5169_host_work, ps5169_config_seqs_init, ps5169_gadget_pullup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_register_patch(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001050c0 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [dp_gain_set, ps5169_release_usb_lanes, usb_tx_gain_set, usb_rx_gain_set, usb_rx_eq_set, dp_eq_set, ps5169_notify_connect, usb_tx_eq_set, redriver_i2c_resume, ps5169_config_work_mode, ps5169_host_work, ps5169_config_seqs_init, ps5169_gadget_pullup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050c8 size=1
// signature: undefined _printk(void)
// callers: [dp_gain_set, dp_eq_set, usb_tx_eq_set, ps5169_config_work_mode, usb_tx_gain_set, usb_rx_gain_set, usb_rx_eq_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001050d0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [ps5169_debugfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001050d8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [ps5169_debugfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001050e0 size=1
// signature: undefined _dev_warn(void)
// callers: [ps5169_debugfs_create, ps5169_gadget_pullup_enter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001050e8 size=1
// signature: undefined usleep_range_state(void)
// callers: [ps5169_host_work, ps5169_gadget_pullup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001050f8 size=1
// signature: undefined queue_work_on(void)
// callers: [ps5169_gadget_pullup_exit, ps5169_host_powercycle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00105108 size=1
// signature: undefined simple_attr_open(void)
// callers: [dp_eq_ops_open, usb_tx_eq_ops_open, dp_gain_ops_open, usb_tx_gain_ops_open, usb_rx_gain_ops_open, usb_rx_eq_ops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00105110 size=1
// signature: undefined single_open(void)
// callers: [config_seqs_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00105118 size=1
// signature: undefined seq_printf(void)
// callers: [config_seqs_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



