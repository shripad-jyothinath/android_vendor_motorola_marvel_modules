// Decompiled by Ghidra 12.2
// Program: nb7vpq904m.ko
// Image base: 00100000

//------------------------------------------------------------
// nb7vpq904m_probe @ 001006f4 size=1308
// signature: undefined nb7vpq904m_probe(void)
// callers: []
//------------------------------------------------------------

ulong nb7vpq904m_probe(long param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  uint uVar10;
  undefined8 uVar11;
  
  plVar1 = (long *)(param_1 + 0x20);
  lVar4 = devm_kmalloc(plVar1,0x120,0xdc0);
  if (lVar4 != 0) {
    lVar7 = *(long *)(param_1 + 0x90);
    if (lVar7 == 0) {
      lVar7 = *plVar1;
    }
    lVar7 = alloc_workqueue("%s:pullup",0x12,0,lVar7);
    *(long *)(lVar4 + 0xa8) = lVar7;
    if (lVar7 != 0) {
      uVar5 = __devm_regmap_init_i2c(param_1,&redriver_regmap,0,0);
      *(ulong *)(lVar4 + 0x60) = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        pcVar6 = "Failed to allocate register map: %d\n";
LAB_00100b9c:
        _dev_err(plVar1,pcVar6,uVar5 & 0xffffffff);
        goto LAB_00100b74;
      }
      uVar11 = *(undefined8 *)(param_1 + 0x308);
      *(long **)(lVar4 + 0x58) = plVar1;
      *(long *)(param_1 + 0xb8) = lVar4;
      lVar7 = of_find_property(uVar11,&DAT_001027b8,0);
      if (lVar7 == 0) {
LAB_001007c4:
        lVar7 = of_find_property(uVar11,"flat-gain",0);
        if (lVar7 != 0) {
          uVar2 = of_property_read_variable_u8_array(uVar11,"flat-gain",lVar4 + 0x9c,8,0);
          uVar10 = uVar2;
          if (-1 < (int)uVar2) {
            uVar10 = 0;
          }
          uVar5 = (ulong)uVar10;
          if ((int)uVar2 < 0) goto LAB_00100b38;
        }
        lVar7 = of_find_property(uVar11,"output-comp",0);
        if (lVar7 != 0) {
          uVar2 = of_property_read_variable_u8_array(uVar11,"output-comp",lVar4 + 0x8c,8,0);
          uVar10 = uVar2;
          if (-1 < (int)uVar2) {
            uVar10 = 0;
          }
          uVar5 = (ulong)uVar10;
          if ((int)uVar2 < 0) goto LAB_00100b38;
        }
        lVar7 = of_find_property(uVar11,"loss-match",0);
        if (lVar7 != 0) {
          uVar2 = of_property_read_variable_u8_array(uVar11,"loss-match",lVar4 + 0x94,8,0);
          uVar10 = uVar2;
          if (-1 < (int)uVar2) {
            uVar10 = 0;
          }
          uVar5 = (ulong)uVar10;
          if ((int)uVar2 < 0) goto LAB_00100b38;
        }
        lVar7 = of_find_property(uVar11,"set-aux",0);
        *(bool *)(lVar4 + 0xa7) = lVar7 != 0;
      }
      else {
        uVar2 = of_property_read_variable_u8_array(uVar11,&DAT_001027b8,lVar4 + 0x84,8,0);
        uVar10 = uVar2;
        if (-1 < (int)uVar2) {
          uVar10 = 0;
        }
        uVar5 = (ulong)uVar10;
        if (-1 < (int)uVar2) goto LAB_001007c4;
LAB_00100b38:
        _dev_err(*(undefined8 *)(lVar4 + 0x58),"%s: error read parameters.\n",
                 "nb7vpq904m_read_configuration");
        if ((int)uVar5 < 0) {
          pcVar6 = "Failed to read default configuration: %d\n";
          goto LAB_00100b9c;
        }
      }
      uVar5 = devm_regulator_get_optional(plVar1,&DAT_00102da6);
      *(ulong *)(lVar4 + 0x70) = uVar5;
      if ((0xfffffffffffff000 < uVar5) && (*(undefined8 *)(lVar4 + 0x70) = 0, (int)uVar5 != -0x13))
      {
        _dev_err(plVar1,"Failed to get vdd regulator %d\n");
      }
      *(undefined8 *)(lVar4 + 0xb0) = 0xfffffffe0;
      *(long *)(lVar4 + 0xb8) = lVar4 + 0xb8;
      *(long *)(lVar4 + 0xc0) = lVar4 + 0xb8;
      *(code **)(lVar4 + 200) = nb7vpq904m_gadget_pullup_work;
      *(undefined8 *)(lVar4 + 0xe8) = 0xfffffffe0;
      *(long *)(lVar4 + 0xf0) = lVar4 + 0xf0;
      *(long *)(lVar4 + 0xf8) = lVar4 + 0xf0;
      *(code **)(lVar4 + 0x100) = nb7vpq904m_host_work;
      lVar7 = of_find_property(*(undefined8 *)(*(long *)(lVar4 + 0x58) + 0x2e8),"lane-channel-swap",
                               0);
      *(bool *)(lVar4 + 0xa5) = lVar7 != 0;
      *(undefined4 *)(lVar4 + 0x7c) = 0;
      if ((*(long *)(lVar4 + 0x70) == 0) || (*(char *)(lVar4 + 0xa6) != '\0')) {
switchD_00100b14_default:
        uVar8 = 0;
      }
      else {
        *(undefined1 *)(lVar4 + 0xa6) = 1;
        regulator_set_load(*(long *)(lVar4 + 0x70),260000);
        regulator_set_voltage(*(undefined8 *)(lVar4 + 0x70),0x1a17b0,0x1cd6d0);
        regulator_enable(*(undefined8 *)(lVar4 + 0x70));
        uVar10 = *(uint *)(lVar4 + 0x78);
        if (*(char *)(lVar4 + 0xa5) != '\0') {
          uVar10 = (uint)(uVar10 == 0);
        }
        uVar8 = 0xfb;
        switch(*(undefined4 *)(lVar4 + 0x7c)) {
        case 1:
          uVar9 = 0x3b;
          if (uVar10 != 1) {
            uVar9 = 0xb;
          }
          uVar8 = 0xcb;
          if (uVar10 != 0) {
            uVar8 = uVar9;
          }
          break;
        case 2:
          uVar8 = 0xf5;
          break;
        case 3:
          uVar8 = 0xf3;
          if (uVar10 != 0) {
            uVar8 = 0xf1;
          }
          break;
        case 4:
          break;
        default:
          goto switchD_00100b14_default;
        }
      }
      *(undefined1 *)(lVar4 + 0xa4) = uVar8;
      iVar3 = regmap_write(*(undefined8 *)(lVar4 + 0x60),0,uVar8);
      if (iVar3 < 0) {
        _dev_err(*(undefined8 *)(lVar4 + 0x58),"writing reg 0x%02x failure\n",0);
        lVar7 = *(long *)(lVar4 + 0x70);
      }
      else {
        lVar7 = *(long *)(lVar4 + 0x70);
      }
      if ((lVar7 != 0) && (*(char *)(lVar4 + 0xa6) != '\0')) {
        *(undefined1 *)(lVar4 + 0xa6) = 0;
        regulator_disable();
        regulator_set_voltage(*(undefined8 *)(lVar4 + 0x70),0,0x1cd6d0);
        regulator_set_load(*(undefined8 *)(lVar4 + 0x70),0);
      }
      lVar7 = debugfs_create_dir("nb7vpq904m_redriver",0);
      *(long *)(lVar4 + 0x118) = lVar7;
      if (lVar7 == 0) {
        _dev_warn(*(undefined8 *)(lVar4 + 0x58),"Couldn\'t create debug dir\n");
      }
      else {
        debugfs_create_file(&DAT_001027b8,0x180,lVar7,lVar4,eq_ops);
        debugfs_create_file("flat_gain",0x180,*(undefined8 *)(lVar4 + 0x118),lVar4,flat_gain_ops);
        debugfs_create_file("output_comp",0x180,*(undefined8 *)(lVar4 + 0x118),lVar4,output_comp_ops
                           );
        debugfs_create_file("loss_match",0x180,*(undefined8 *)(lVar4 + 0x118),lVar4,loss_match_ops);
        debugfs_create_bool("lane-channel-swap",0x1a4,*(undefined8 *)(lVar4 + 0x118),lVar4 + 0xa5);
      }
      uVar11 = *(undefined8 *)(*(long *)(lVar4 + 0x58) + 0x2e8);
      *(code **)(lVar4 + 0x20) = nb7vpq904m_notify_connect;
      *(code **)(lVar4 + 0x28) = nb7vpq904m_notify_disconnect;
      *(undefined8 *)(lVar4 + 0x10) = uVar11;
      *(code **)(lVar4 + 0x18) = nb7vpq904m_release_usb_lanes;
      *(code **)(lVar4 + 0x30) = nb7vpq904m_gadget_pullup_enter;
      *(code **)(lVar4 + 0x38) = nb7vpq904m_gadget_pullup_exit;
      *(code **)(lVar4 + 0x40) = nb7vpq904m_host_powercycle;
      usb_add_redriver(lVar4);
      uVar5 = 0;
      goto LAB_00100b74;
    }
    _dev_err(plVar1,"Failed to create pullup workqueue\n");
  }
  uVar5 = 0xfffffff4;
LAB_00100b74:
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// nb7vpq904m_remove @ 00100c14 size=80
// signature: undefined nb7vpq904m_remove(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_remove(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  iVar1 = usb_remove_redriver(lVar2);
  if (iVar1 == 0) {
    debugfs_remove(*(undefined8 *)(lVar2 + 0x118));
    *(undefined1 *)(lVar2 + 0xe0) = 0;
    destroy_workqueue(*(undefined8 *)(lVar2 + 0xa8));
    if (*(long *)(lVar2 + 0x70) != 0) {
      regulator_disable();
    }
  }
  return;
}



//------------------------------------------------------------
// nb7vpq904m_shutdown @ 00100c68 size=108
// signature: undefined nb7vpq904m_shutdown(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_shutdown(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  iVar1 = regmap_write(*(undefined8 *)(lVar2 + 0x60),0,0xfb);
  if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(lVar2 + 0x58),"writing reg 0x%02x failure\n",0);
    _dev_err(param_1 + 0x20,"%s: fail to set USB mode with 4 channel enabled.\n",
             "nb7vpq904m_shutdown");
  }
  return;
}



//------------------------------------------------------------
// nb7vpq904m_gadget_pullup_work @ 00100cd8 size=148
// signature: undefined nb7vpq904m_gadget_pullup_work(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_gadget_pullup_work(long param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + -0xc);
  iVar2 = regmap_write(*(undefined8 *)(param_1 + -0x50),0,bVar1 & 0xfe);
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x58),"writing reg 0x%02x failure\n",0);
  }
  usleep_range_state(1000,0x5dc,2);
  iVar2 = regmap_write(*(undefined8 *)(param_1 + -0x50),0,bVar1);
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x58),"writing reg 0x%02x failure\n",0);
  }
  *(undefined1 *)(param_1 + 0x30) = 0;
  return;
}



//------------------------------------------------------------
// nb7vpq904m_host_work @ 00100d70 size=144
// signature: undefined nb7vpq904m_host_work(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_host_work(long param_1)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = *(byte *)(param_1 + -0x44);
  iVar2 = regmap_write(*(undefined8 *)(param_1 + -0x88),0,bVar1 & 0xfe);
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x90),"writing reg 0x%02x failure\n",0);
  }
  usleep_range_state(2000,0x9c4,2);
  iVar2 = regmap_write(*(undefined8 *)(param_1 + -0x88),0,bVar1);
  if (iVar2 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x90),"writing reg 0x%02x failure\n",0);
  }
  return;
}



//------------------------------------------------------------
// nb7vpq904m_release_usb_lanes @ 00100e04 size=420
// signature: undefined nb7vpq904m_release_usb_lanes(void)
// callers: []
//------------------------------------------------------------

undefined8 nb7vpq904m_release_usb_lanes(long param_1,uint param_2,int param_3)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  
  if (param_3 == 4) {
    uVar5 = 2;
LAB_00100e38:
    *(undefined4 *)(param_1 + 0x7c) = uVar5;
  }
  else if (param_3 == 2) {
    uVar5 = 3;
    goto LAB_00100e38;
  }
  if ((*(long *)(param_1 + 0x70) != 0) && (*(char *)(param_1 + 0xa6) == '\0')) {
    *(undefined1 *)(param_1 + 0xa6) = 1;
    regulator_set_load(*(long *)(param_1 + 0x70),260000);
    regulator_set_voltage(*(undefined8 *)(param_1 + 0x70),0x1a17b0,0x1cd6d0);
    regulator_enable(*(undefined8 *)(param_1 + 0x70));
  }
  *(uint *)(param_1 + 0x78) = param_2;
  if (*(char *)(param_1 + 0xa5) != '\0') {
    param_2 = (uint)(param_2 == 0);
  }
  uVar2 = 0xfb;
  switch(*(undefined4 *)(param_1 + 0x7c)) {
  case 1:
    uVar4 = 0x3b;
    if (param_2 != 1) {
      uVar4 = 0xb;
    }
    uVar2 = 0xcb;
    goto LAB_00100efc;
  case 2:
    uVar2 = 0xf5;
    break;
  case 3:
    uVar4 = 0xf1;
    uVar2 = 0xf3;
LAB_00100efc:
    if (param_2 != 0) {
      uVar2 = uVar4;
    }
    break;
  case 4:
    break;
  default:
    uVar2 = 0;
  }
  *(undefined1 *)(param_1 + 0xa4) = uVar2;
  iVar3 = regmap_write(*(undefined8 *)(param_1 + 0x60),0,uVar2);
  if (iVar3 < 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",0);
    cVar1 = *(char *)(param_1 + 0xa7);
  }
  else {
    cVar1 = *(char *)(param_1 + 0xa7);
  }
  if (cVar1 != '\0') {
    if ((*(uint *)(param_1 + 0x7c) & 0xfffffffe) == 2) {
      uVar2 = *(int *)(param_1 + 0x78) != 0;
    }
    else {
      uVar2 = 2;
    }
    iVar3 = regmap_write(*(undefined8 *)(param_1 + 0x60),9,uVar2);
    if (iVar3 < 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",9);
    }
  }
  nb7vpq904m_channel_update(param_1);
  return 0;
}



//------------------------------------------------------------
// nb7vpq904m_notify_connect @ 00100fac size=448
// signature: undefined nb7vpq904m_notify_connect(void)
// callers: []
//------------------------------------------------------------

undefined8 nb7vpq904m_notify_connect(long param_1,uint param_2)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 uVar4;
  
  if ((*(long *)(param_1 + 0x70) == 0) || (*(char *)(param_1 + 0xa6) != '\0')) {
    iVar3 = *(int *)(param_1 + 0x7c);
    if (iVar3 == 0) goto LAB_00101068;
LAB_00100fe0:
    *(uint *)(param_1 + 0x78) = param_2;
    if (*(char *)(param_1 + 0xa5) != '\0') {
      param_2 = (uint)(param_2 == 0);
    }
    uVar2 = 0xfb;
    switch(iVar3) {
    case 1:
      goto switchD_00101020_caseD_1;
    case 2:
      uVar2 = 0xf5;
      break;
    case 3:
      uVar4 = 0xf1;
      uVar2 = 0xf3;
      goto LAB_001010bc;
    case 4:
      break;
    default:
      uVar2 = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0xa6) = 1;
    regulator_set_load(*(long *)(param_1 + 0x70),260000);
    regulator_set_voltage(*(undefined8 *)(param_1 + 0x70),0x1a17b0,0x1cd6d0);
    regulator_enable(*(undefined8 *)(param_1 + 0x70));
    iVar3 = *(int *)(param_1 + 0x7c);
    if (iVar3 != 0) goto LAB_00100fe0;
LAB_00101068:
    *(uint *)(param_1 + 0x78) = param_2;
    *(undefined4 *)(param_1 + 0x7c) = 1;
    if (*(char *)(param_1 + 0xa5) != '\0') {
      param_2 = (uint)(param_2 == 0);
    }
switchD_00101020_caseD_1:
    uVar4 = 0x3b;
    if (param_2 != 1) {
      uVar4 = 0xb;
    }
    uVar2 = 0xcb;
LAB_001010bc:
    if (param_2 != 0) {
      uVar2 = uVar4;
    }
  }
  *(undefined1 *)(param_1 + 0xa4) = uVar2;
  iVar3 = regmap_write(*(undefined8 *)(param_1 + 0x60),0,uVar2);
  if (iVar3 < 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",0);
    cVar1 = *(char *)(param_1 + 0xa7);
  }
  else {
    cVar1 = *(char *)(param_1 + 0xa7);
  }
  if (cVar1 != '\0') {
    if ((*(uint *)(param_1 + 0x7c) & 0xfffffffe) == 2) {
      uVar2 = *(int *)(param_1 + 0x78) != 0;
    }
    else {
      uVar2 = 2;
    }
    iVar3 = regmap_write(*(undefined8 *)(param_1 + 0x60),9,uVar2);
    if (iVar3 < 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",9);
    }
  }
  nb7vpq904m_channel_update(param_1);
  return 0;
}



//------------------------------------------------------------
// nb7vpq904m_notify_disconnect @ 00101170 size=152
// signature: undefined nb7vpq904m_notify_disconnect(void)
// callers: []
//------------------------------------------------------------

undefined8 nb7vpq904m_notify_disconnect(long param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x7c) != 0) {
    *(undefined4 *)(param_1 + 0x7c) = 0;
    iVar1 = regmap_write(*(undefined8 *)(param_1 + 0x60),0,0);
    if (iVar1 < 0) {
      _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",0);
    }
    else if ((*(long *)(param_1 + 0x70) != 0) && (*(char *)(param_1 + 0xa6) != '\0')) {
      *(undefined1 *)(param_1 + 0xa6) = 0;
      regulator_disable();
      regulator_set_voltage(*(undefined8 *)(param_1 + 0x70),0,0x1cd6d0);
      regulator_set_load(*(undefined8 *)(param_1 + 0x70),0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// nb7vpq904m_gadget_pullup_enter @ 0010120c size=112
// signature: undefined nb7vpq904m_gadget_pullup_enter(void)
// callers: []
//------------------------------------------------------------

undefined8 nb7vpq904m_gadget_pullup_enter(long param_1,int param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x7c) == 1) {
    if (param_2 != 0) {
      lVar2 = 0x7a122;
      do {
        if (*(char *)(param_1 + 0xe0) == '\0') goto LAB_00101260;
        __const_udelay(0x10c7);
        lVar2 = lVar2 + -1;
      } while (lVar2 != 0);
      _dev_warn(*(undefined8 *)(param_1 + 0x58),"pullup timeout\n");
    }
LAB_00101260:
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// nb7vpq904m_gadget_pullup_exit @ 00101280 size=76
// signature: undefined nb7vpq904m_gadget_pullup_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 nb7vpq904m_gadget_pullup_exit(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0x7c) == 1) {
    if (param_2 == 0) {
      *(undefined1 *)(param_1 + 0xe0) = 1;
      queue_work_on(0x20,*(undefined8 *)(param_1 + 0xa8),param_1 + 0xb0);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// nb7vpq904m_host_powercycle @ 001012d0 size=68
// signature: undefined nb7vpq904m_host_powercycle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 nb7vpq904m_host_powercycle(long param_1)

{
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0x7c) == 1) {
    queue_work_on(0x20,_system_wq,param_1 + 0xe8);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// eq_write @ 00101318 size=36
// signature: undefined eq_write(void)
// callers: []
//------------------------------------------------------------

void eq_write(void)

{
  channel_config_write();
  return;
}



//------------------------------------------------------------
// eq_status_open @ 00101340 size=48
// signature: undefined eq_status_open(void)
// callers: []
//------------------------------------------------------------

void eq_status_open(long param_1,undefined8 param_2)

{
  single_open(param_2,eq_status,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// channel_config_write @ 00101370 size=660
// signature: undefined channel_config_write(void)
// callers: [eq_write, output_comp_write, loss_match_write, flat_gain_write]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong channel_config_write(long param_1,ulong param_2,ulong param_3,code *param_4)

{
  byte bVar1;
  uint uVar2;
  long lVar3;
  ulong uVar4;
  code *pcVar5;
  int iVar6;
  ulong uVar7;
  byte *pbVar8;
  undefined8 uVar9;
  undefined8 *puVar10;
  ulong uVar11;
  undefined8 uVar12;
  ulong *local_78;
  ulong local_70 [6];
  
  lVar3 = sp_el0;
  local_78 = local_70;
  local_70[5] = *(long *)(lVar3 + 0x638);
  local_70[0] = 0;
  uVar7 = param_3;
  if (0x26 < param_3) {
    uVar7 = 0x27;
  }
  uVar12 = *(undefined8 *)(*(long *)(param_1 + 0xd8) + 0x80);
  local_70[1] = 0;
  local_70[2] = 0;
  local_70[3] = 0;
  local_70[4] = 0;
  __check_object_size(local_70,uVar7,0);
  puVar10 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar10 + 0x46) >> 5 & 1) != 0) ||
     (uVar11 = param_2, ((uint)*puVar10 >> 0x1a & 1) != 0)) {
    uVar11 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar11 <= 0x8000000000 - uVar7) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      puVar10 = (undefined8 *)puVar10[1];
      uVar4 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar10 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar10;
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
    uVar7 = __arch_copy_from_user(puVar10,local_70,param_2 & 0xff7fffffffffffff,uVar7);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar11 = daif;
      if ((uVar11 & 0x80) == 0) {
        uVar4 = daif;
        daif = uVar4 | 0xc0;
      }
      uVar4 = ttbr1_el1;
      ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar4 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar11;
    }
  }
  if (uVar7 == 0) {
    if ((byte)local_70[0] - 0x3a < 0xfffffff6) {
      if (((&_ctype)[local_70[0] & 0xff] & 3) != 0) {
        do {
          pbVar8 = (byte *)strsep((char **)&local_78," ");
          if (pbVar8 == (byte *)0x0) goto LAB_001015a0;
          uVar2 = *pbVar8 - 0x61;
          if (uVar2 < 4) {
            pbVar8 = (byte *)strsep((char **)&local_78," ");
            bVar1 = *pbVar8;
            if (bVar1 - 0x3a < 0xfffffff6) break;
            uVar9 = 1;
          }
          else {
            uVar2 = *pbVar8 - 0x41;
            if (3 < uVar2) break;
            pbVar8 = (byte *)strsep((char **)&local_78," ");
            bVar1 = *pbVar8;
            if (bVar1 - 0x3a < 0xfffffff6) break;
            uVar9 = 0;
          }
          if (*(int *)(param_4 + -4) != -0x79ed77ff) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8234,0x101518);
            (*pcVar5)();
          }
          iVar6 = (*param_4)(uVar12,uVar2,uVar9,bVar1 - 0x30);
        } while (-1 < iVar6);
      }
    }
    else {
      if (*(int *)(param_4 + -4) != -0x79ed77ff) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8234,0x101598);
        (*pcVar5)();
      }
      iVar6 = (*param_4)(uVar12,4,0xff,(byte)local_70[0] - 0x30);
      if (-1 < iVar6) goto LAB_001015a0;
    }
    _printk(&DAT_00102894);
  }
  param_3 = 0xfffffffffffffff2;
LAB_001015a0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_70[5]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// nb7vpq904m_eq_config @ 00101620 size=56
// signature: undefined nb7vpq904m_eq_config(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_eq_config(long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  nb7vpq904m_param_config(param_1,1,param_2,param_3,7,1,param_4,param_1 + 0x84);
  return;
}



//------------------------------------------------------------
// nb7vpq904m_param_config @ 00101658 size=576
// signature: undefined nb7vpq904m_param_config(void)
// callers: [nb7vpq904m_eq_config, nb7vpq904m_output_comp_config, nb7vpq904m_loss_match_config, nb7vpq904m_channel_update, nb7vpq904m_flat_gain_config]
//------------------------------------------------------------

int nb7vpq904m_param_config
              (long param_1,char param_2,byte param_3,byte param_4,uint param_5,uint param_6,
              uint param_7,undefined1 *param_8)

{
  uint uVar1;
  undefined1 uVar2;
  code *pcVar3;
  int iVar4;
  char cVar5;
  
  uVar2 = (undefined1)param_7;
  if (param_3 != 4) {
    if (3 < param_3) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101898);
      (*pcVar3)();
    }
    if (*(byte *)(param_1 + (ulong)param_3 + 0x80) == param_4) {
      param_2 = param_2 + param_3 * '\x02';
      iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),param_2,
                           (param_7 & param_5) << (ulong)(param_6 & 0x1f) & 0xff);
      if (iVar4 < 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",param_2);
        return iVar4;
      }
    }
    param_8[(ulong)param_3 + (ulong)param_4 * 4] = uVar2;
    return 0;
  }
  uVar1 = (param_7 & param_5) << (ulong)(param_6 & 0x1f) & 0xff;
  if ((*(char *)(param_1 + 0x80) != '\0') ||
     (iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),param_2,uVar1), cVar5 = param_2,
     -1 < iVar4)) {
    *param_8 = uVar2;
    if (*(char *)(param_1 + 0x81) == '\0') {
      iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),param_2 + '\x02',uVar1);
      cVar5 = param_2 + '\x02';
      if (iVar4 < 0) goto LAB_0010185c;
    }
    param_8[1] = uVar2;
    if (*(char *)(param_1 + 0x82) == '\0') {
      iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),param_2 + '\x04',uVar1);
      cVar5 = param_2 + '\x04';
      if (iVar4 < 0) goto LAB_0010185c;
    }
    param_8[2] = uVar2;
    if (*(char *)(param_1 + 0x83) == '\0') {
      iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),param_2 + '\x06',uVar1);
      cVar5 = param_2 + '\x06';
      if (iVar4 < 0) goto LAB_0010185c;
    }
    param_8[3] = uVar2;
    if ((*(char *)(param_1 + 0x80) != '\x01') ||
       (iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),param_2,uVar1), cVar5 = param_2,
       -1 < iVar4)) {
      param_8[4] = uVar2;
      if (*(char *)(param_1 + 0x81) == '\x01') {
        cVar5 = param_2 + '\x02';
        iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),cVar5,uVar1);
        if (iVar4 < 0) goto LAB_0010185c;
      }
      param_8[5] = uVar2;
      if (*(char *)(param_1 + 0x82) == '\x01') {
        cVar5 = param_2 + '\x04';
        iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),cVar5,uVar1);
        if (iVar4 < 0) goto LAB_0010185c;
      }
      param_8[6] = uVar2;
      if (*(char *)(param_1 + 0x83) == '\x01') {
        cVar5 = param_2 + '\x06';
        iVar4 = regmap_write(*(undefined8 *)(param_1 + 0x60),cVar5,uVar1);
        if (iVar4 < 0) goto LAB_0010185c;
      }
      param_8[7] = uVar2;
      return 0;
    }
  }
LAB_0010185c:
  _dev_err(*(undefined8 *)(param_1 + 0x58),"writing reg 0x%02x failure\n",cVar5);
  return iVar4;
}



//------------------------------------------------------------
// eq_status @ 0010189c size=120
// signature: undefined eq_status(void)
// callers: []
//------------------------------------------------------------

undefined8 eq_status(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x80);
  seq_puts(param_1,"\t\t\t A(USB)\t B(USB)\t C(USB)\t D(USB)\tA(DP)\t B(DP)\t C(DP)\t D(DP)\n");
  seq_printf(param_1,"Equalization:\t\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
             *(undefined1 *)(lVar1 + 0x84),*(undefined1 *)(lVar1 + 0x85),
             *(undefined1 *)(lVar1 + 0x86),*(undefined1 *)(lVar1 + 0x87),
             *(undefined1 *)(lVar1 + 0x88),*(undefined1 *)(lVar1 + 0x89),
             *(undefined1 *)(lVar1 + 0x8a),*(undefined1 *)(lVar1 + 0x8b));
  return 0;
}



//------------------------------------------------------------
// flat_gain_write @ 00101918 size=36
// signature: undefined flat_gain_write(void)
// callers: []
//------------------------------------------------------------

void flat_gain_write(void)

{
  channel_config_write();
  return;
}



//------------------------------------------------------------
// flat_gain_status_open @ 00101940 size=48
// signature: undefined flat_gain_status_open(void)
// callers: []
//------------------------------------------------------------

void flat_gain_status_open(long param_1,undefined8 param_2)

{
  single_open(param_2,flat_gain_status,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// nb7vpq904m_flat_gain_config @ 00101974 size=56
// signature: undefined nb7vpq904m_flat_gain_config(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_flat_gain_config
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  nb7vpq904m_param_config(param_1,0x18,param_2,param_3,3,0,param_4,param_1 + 0x9c);
  return;
}



//------------------------------------------------------------
// flat_gain_status @ 001019b0 size=120
// signature: undefined flat_gain_status(void)
// callers: []
//------------------------------------------------------------

undefined8 flat_gain_status(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x80);
  seq_puts(param_1,"\t\t\t A(USB)\t B(USB)\t C(USB)\t D(USB)\tA(DP)\t B(DP)\t C(DP)\t D(DP)\n");
  seq_printf(param_1,"TX/RX Flat Gain:\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
             *(undefined1 *)(lVar1 + 0x9c),*(undefined1 *)(lVar1 + 0x9d),
             *(undefined1 *)(lVar1 + 0x9e),*(undefined1 *)(lVar1 + 0x9f),
             *(undefined1 *)(lVar1 + 0xa0),*(undefined1 *)(lVar1 + 0xa1),
             *(undefined1 *)(lVar1 + 0xa2),*(undefined1 *)(lVar1 + 0xa3));
  return 0;
}



//------------------------------------------------------------
// output_comp_write @ 00101a2c size=36
// signature: undefined output_comp_write(void)
// callers: []
//------------------------------------------------------------

void output_comp_write(void)

{
  channel_config_write();
  return;
}



//------------------------------------------------------------
// output_comp_status_open @ 00101a54 size=48
// signature: undefined output_comp_status_open(void)
// callers: []
//------------------------------------------------------------

void output_comp_status_open(long param_1,undefined8 param_2)

{
  single_open(param_2,output_comp_status,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// nb7vpq904m_output_comp_config @ 00101a88 size=56
// signature: undefined nb7vpq904m_output_comp_config(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_output_comp_config
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  nb7vpq904m_param_config(param_1,2,param_2,param_3,0xb,1,param_4,param_1 + 0x8c);
  return;
}



//------------------------------------------------------------
// output_comp_status @ 00101ac4 size=120
// signature: undefined output_comp_status(void)
// callers: []
//------------------------------------------------------------

undefined8 output_comp_status(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x80);
  seq_puts(param_1,"\t\t\t A(USB)\t B(USB)\t C(USB)\t D(USB)\tA(DP)\t B(DP)\t C(DP)\t D(DP)\n");
  seq_printf(param_1,"Output Compression:\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
             *(undefined1 *)(lVar1 + 0x8c),*(undefined1 *)(lVar1 + 0x8d),
             *(undefined1 *)(lVar1 + 0x8e),*(undefined1 *)(lVar1 + 0x8f),
             *(undefined1 *)(lVar1 + 0x90),*(undefined1 *)(lVar1 + 0x91),
             *(undefined1 *)(lVar1 + 0x92),*(undefined1 *)(lVar1 + 0x93));
  return 0;
}



//------------------------------------------------------------
// loss_match_write @ 00101b40 size=36
// signature: undefined loss_match_write(void)
// callers: []
//------------------------------------------------------------

void loss_match_write(void)

{
  channel_config_write();
  return;
}



//------------------------------------------------------------
// loss_match_status_open @ 00101b68 size=48
// signature: undefined loss_match_status_open(void)
// callers: []
//------------------------------------------------------------

void loss_match_status_open(long param_1,undefined8 param_2)

{
  single_open(param_2,loss_match_status,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// nb7vpq904m_loss_match_config @ 00101b9c size=56
// signature: undefined nb7vpq904m_loss_match_config(void)
// callers: []
//------------------------------------------------------------

void nb7vpq904m_loss_match_config
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  nb7vpq904m_param_config(param_1,0x19,param_2,param_3,3,0,param_4,param_1 + 0x94);
  return;
}



//------------------------------------------------------------
// loss_match_status @ 00101bd8 size=120
// signature: undefined loss_match_status(void)
// callers: []
//------------------------------------------------------------

undefined8 loss_match_status(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x80);
  seq_puts(param_1,"\t\t\t A(USB)\t B(USB)\t C(USB)\t D(USB)\tA(DP)\t B(DP)\t C(DP)\t D(DP)\n");
  seq_printf(param_1,"Loss Profile Match:\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
             *(undefined1 *)(lVar1 + 0x94),*(undefined1 *)(lVar1 + 0x95),
             *(undefined1 *)(lVar1 + 0x96),*(undefined1 *)(lVar1 + 0x97),
             *(undefined1 *)(lVar1 + 0x98),*(undefined1 *)(lVar1 + 0x99),
             *(undefined1 *)(lVar1 + 0x9a),*(undefined1 *)(lVar1 + 0x9b));
  return 0;
}



//------------------------------------------------------------
// nb7vpq904m_channel_update @ 00101c50 size=436
// signature: undefined nb7vpq904m_channel_update(void)
// callers: [nb7vpq904m_release_usb_lanes, nb7vpq904m_notify_connect]
//------------------------------------------------------------

void nb7vpq904m_channel_update(long param_1)

{
  long lVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  
  uVar6 = *(uint *)(param_1 + 0x78);
  if (*(char *)(param_1 + 0xa5) != '\0') {
    uVar6 = (uint)(uVar6 == 0);
  }
  switch(*(undefined4 *)(param_1 + 0x7c)) {
  case 1:
    if (uVar6 == 0) {
      uVar5 = 0xffff;
    }
    else {
      uVar5 = 0xffff0000;
    }
    break;
  case 2:
    uVar5 = 0x1010101;
    break;
  case 3:
    if (uVar6 == 0) {
      uVar5 = 0x101;
    }
    else {
      uVar5 = 0x1010000;
    }
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x80) = 0;
    goto LAB_00101ce4;
  default:
    goto switchD_00101ca8_default;
  }
  *(undefined4 *)(param_1 + 0x80) = uVar5;
LAB_00101ce4:
  uVar7 = 0;
  do {
    bVar2 = *(byte *)(param_1 + uVar7 + 0x80);
    uVar8 = (ulong)bVar2;
    if (uVar8 != 0xff) {
      if (1 < bVar2) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x101e04);
        (*pcVar3)();
      }
      lVar1 = param_1 + uVar8 * 4 + uVar7;
      iVar4 = nb7vpq904m_param_config
                        (param_1,1,uVar7 & 0xffffffff,uVar8,7,1,*(undefined1 *)(lVar1 + 0x84),
                         param_1 + 0x84);
      if ((iVar4 != 0) ||
         (iVar4 = nb7vpq904m_param_config
                            (param_1,0x18,uVar7 & 0xffffffff,bVar2,3,0,*(undefined1 *)(lVar1 + 0x9c)
                             ,param_1 + 0x9c), iVar4 != 0)) {
LAB_00101dd0:
        _dev_err(*(undefined8 *)(param_1 + 0x58),"channel parameters update failure(%d).\n",iVar4);
        return;
      }
      lVar1 = param_1 + uVar8 * 4 + uVar7;
      iVar4 = nb7vpq904m_param_config
                        (param_1,2,uVar7 & 0xffffffff,bVar2,0xb,1,*(undefined1 *)(lVar1 + 0x8c),
                         param_1 + 0x8c);
      if ((iVar4 != 0) ||
         (iVar4 = nb7vpq904m_param_config
                            (param_1,0x19,uVar7 & 0xffffffff,bVar2,3,0,*(undefined1 *)(lVar1 + 0x94)
                             ,param_1 + 0x94), iVar4 != 0)) goto LAB_00101dd0;
    }
    uVar7 = uVar7 + 1;
  } while (uVar7 != 4);
switchD_00101ca8_default:
  return;
}



//------------------------------------------------------------
// init_module @ 00101e30 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&nb7vpq904m_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101e60 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&nb7vpq904m_driver);
  return;
}



//------------------------------------------------------------
// i2c_register_driver @ 00104000 size=1
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
// i2c_del_driver @ 00104008 size=1
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
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00104018 size=1
// signature: undefined alloc_workqueue(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_i2c @ 00104020 size=1
// signature: undefined __devm_regmap_init_i2c(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_i2c(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104028 size=1
// signature: undefined of_find_property(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u8_array @ 00104030 size=1
// signature: undefined of_property_read_variable_u8_array(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u8_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_optional @ 00104038 size=1
// signature: undefined devm_regulator_get_optional(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00104040 size=1
// signature: undefined regmap_write(void)
// callers: [nb7vpq904m_gadget_pullup_work, nb7vpq904m_release_usb_lanes, nb7vpq904m_probe, nb7vpq904m_notify_connect, nb7vpq904m_host_work, nb7vpq904m_param_config, nb7vpq904m_shutdown, nb7vpq904m_notify_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00104048 size=1
// signature: undefined regulator_disable(void)
// callers: [nb7vpq904m_probe, nb7vpq904m_remove, nb7vpq904m_notify_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00104050 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [nb7vpq904m_release_usb_lanes, nb7vpq904m_probe, nb7vpq904m_notify_connect, nb7vpq904m_notify_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00104058 size=1
// signature: undefined regulator_set_load(void)
// callers: [nb7vpq904m_release_usb_lanes, nb7vpq904m_probe, nb7vpq904m_notify_connect, nb7vpq904m_notify_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00104060 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00104068 size=1
// signature: undefined debugfs_create_file(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_bool @ 00104070 size=1
// signature: undefined debugfs_create_bool(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_redriver @ 00104078 size=1
// signature: undefined usb_add_redriver(void)
// callers: [nb7vpq904m_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_redriver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00104080 size=1
// signature: undefined regulator_enable(void)
// callers: [nb7vpq904m_release_usb_lanes, nb7vpq904m_probe, nb7vpq904m_notify_connect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104088 size=1
// signature: undefined _dev_err(void)
// callers: [nb7vpq904m_gadget_pullup_work, nb7vpq904m_release_usb_lanes, nb7vpq904m_probe, nb7vpq904m_notify_connect, nb7vpq904m_channel_update, nb7vpq904m_host_work, nb7vpq904m_param_config, nb7vpq904m_shutdown, nb7vpq904m_notify_disconnect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00104090 size=1
// signature: undefined _dev_warn(void)
// callers: [nb7vpq904m_probe, nb7vpq904m_gadget_pullup_enter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_redriver @ 00104098 size=1
// signature: undefined usb_remove_redriver(void)
// callers: [nb7vpq904m_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_redriver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001040a0 size=1
// signature: undefined debugfs_remove(void)
// callers: [nb7vpq904m_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001040a8 size=1
// signature: undefined destroy_workqueue(void)
// callers: [nb7vpq904m_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001040b0 size=1
// signature: undefined usleep_range_state(void)
// callers: [nb7vpq904m_gadget_pullup_work, nb7vpq904m_host_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001040b8 size=1
// signature: undefined __const_udelay(void)
// callers: [nb7vpq904m_gadget_pullup_enter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001040c0 size=1
// signature: undefined queue_work_on(void)
// callers: [nb7vpq904m_gadget_pullup_exit, nb7vpq904m_host_powercycle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001040d0 size=1
// signature: undefined single_open(void)
// callers: [flat_gain_status_open, output_comp_status_open, eq_status_open, loss_match_status_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001040d8 size=1
// signature: undefined __check_object_size(void)
// callers: [channel_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001040f0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [channel_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00104100 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [channel_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104108 size=1
// signature: undefined _printk(void)
// callers: [channel_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104110 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [channel_config_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00104120 size=1
// signature: undefined seq_puts(void)
// callers: [flat_gain_status, output_comp_status, eq_status, loss_match_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00104128 size=1
// signature: undefined seq_printf(void)
// callers: [flat_gain_status, output_comp_status, eq_status, loss_match_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



