// Decompiled by Ghidra 12.2
// Program: repeater-qti-pmic-eusb2.ko
// Image base: 00100000

//------------------------------------------------------------
// eusb2_repeater_probe @ 001003bc size=1004
// signature: undefined eusb2_repeater_probe(void)
// callers: []
//------------------------------------------------------------

ulong eusb2_repeater_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined4 local_6c;
  long local_68;
  
  lVar5 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar5 + 0x638);
  local_6c = 0;
  plVar4 = (long *)devm_kmalloc(lVar1,0x100,0xdc0);
  if (plVar4 == (long *)0x0) {
    uVar6 = 0xfffffff4;
  }
  else {
    lVar5 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
    plVar4[0xb] = lVar5;
    if (lVar5 == 0) {
      _dev_err(lVar1,"failed to get parent\'s regmap\n");
      uVar6 = 0xffffffea;
    }
    else {
      uVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),&DAT_0010219b,&local_6c,1,0);
      if ((int)uVar2 < 0) {
        uVar6 = (ulong)uVar2;
        _dev_err(lVar1,"failed to get reg base address:%d\n",uVar6);
      }
      else {
        *(short *)(plVar4 + 0xc) = (short)local_6c;
        uVar6 = devm_regulator_get(lVar1,&DAT_001024e6);
        plVar4[0xe] = uVar6;
        if (uVar6 < 0xfffffffffffff001) {
          uVar6 = devm_regulator_get(lVar1,"vdd18");
          plVar4[0xd] = uVar6;
          if (uVar6 < 0xfffffffffffff001) {
            uVar6 = eusb2_repeater_read_overrides
                              (lVar1,"qcom,param-override-seq",plVar4 + 0x13,plVar4 + 0x15);
            if (((int)uVar6 < 0) ||
               (uVar6 = eusb2_repeater_read_overrides
                                  (lVar1,"qcom,host-param-override-seq",plVar4 + 0x14,
                                   (long)plVar4 + 0xac), (int)uVar6 < 0)) {
              uVar6 = uVar6 & 0xffffffff;
            }
            else {
              *plVar4 = lVar1;
              *(long **)(param_1 + 0xa8) = plVar4;
              plVar4[5] = (long)eusb2_repeater_reset;
              plVar4[6] = (long)eusb2_repeater_init;
              plVar4[8] = (long)eusb2_repeater_powerup;
              plVar4[9] = (long)eusb2_repeater_powerdown;
              plVar4[10] = (long)eusb2_repeater_get_version;
              uVar7 = usb_add_repeater_dev(plVar4);
              uVar6 = uVar7 & 0xffffffff;
              if ((int)uVar7 == 0) {
                plVar4[0x11] = -1;
                *(undefined4 *)(plVar4 + 0x12) = 0xffffffff;
                lVar5 = ((long *)*plVar4)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*plVar4;
                }
                lVar5 = debugfs_create_dir(lVar5,0);
                plVar4[0x10] = lVar5;
                debugfs_create_x8("usb2_crossover",0x1a4,lVar5,plVar4 + 0x11);
                debugfs_create_x8("iusb2",0x1a4,plVar4[0x10],(long)plVar4 + 0x89);
                debugfs_create_x8("res_fsdif",0x1a4,plVar4[0x10],(long)plVar4 + 0x8a);
                debugfs_create_x8("hsdisc",0x1a4,plVar4[0x10],(long)plVar4 + 0x8b);
                debugfs_create_x8("squelch_u",0x1a4,plVar4[0x10],(long)plVar4 + 0x8c);
                debugfs_create_x8("usb2_slew",0x1a4,plVar4[0x10],(long)plVar4 + 0x8d);
                debugfs_create_x8("usb2_equ",0x1a4,plVar4[0x10],(long)plVar4 + 0x8e);
                debugfs_create_x8("usb2_preem",0x1a4,plVar4[0x10],(long)plVar4 + 0x8f);
                debugfs_create_x8("hs_comp_current",0x1a4,plVar4[0x10],plVar4 + 0x12);
                debugfs_create_x8("eusb_slew",0x1a4,plVar4[0x10],(long)plVar4 + 0x91);
                debugfs_create_x8("eusb_equ",0x1a4,plVar4[0x10],(long)plVar4 + 0x92);
                debugfs_create_x8("eusb_hs_comp_current",0x1a4,plVar4[0x10],(long)plVar4 + 0x93);
                __mutex_init(plVar4 + 0x1a,"&er->user_param_lock",&eusb2_repeater_probe___key);
                iVar3 = device_create_file(*plVar4,&dev_attr_user_param_override);
                if (iVar3 != 0) {
                  _dev_err(lVar1,"unable to create user param seq attr\n");
                }
                iVar3 = device_create_file(*plVar4,&dev_attr_user_host_param_override);
                if (iVar3 != 0) {
                  _dev_err(lVar1,"unable to create user host param seq attr\n");
                }
                uVar6 = 0;
              }
            }
          }
          else {
            _dev_err(lVar1,"unable to get vdd18 supply\n");
          }
        }
        else {
          _dev_err(lVar1,"unable to get vdd3 supply\n");
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// eusb2_repeater_remove @ 001007ac size=104
// signature: undefined eusb2_repeater_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 eusb2_repeater_remove(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  if (puVar1 != (undefined8 *)0x0) {
    device_remove_file(*puVar1,&dev_attr_user_param_override);
    device_remove_file(*puVar1,&dev_attr_user_host_param_override);
    debugfs_remove(puVar1[0x10]);
    usb_remove_repeater_dev(puVar1);
    eusb2_repeater_power(puVar1,0);
  }
  return 0;
}



//------------------------------------------------------------
// eusb2_repeater_read_overrides @ 00100814 size=224
// signature: undefined eusb2_repeater_read_overrides(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

int eusb2_repeater_read_overrides(long param_1,undefined8 param_2,long *param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  uVar1 = of_property_count_elems_of_size(*(undefined8 *)(param_1 + 0x2e8),param_2,4);
  if (0 < (int)uVar1) {
    if ((uVar1 & 1) != 0) {
      _dev_err(param_1,"invalid len for %s\n",param_2);
      return -0x16;
    }
    *param_4 = uVar1;
    lVar3 = devm_kmalloc(param_1,(ulong)uVar1 << 2,0xdc0);
    *param_3 = lVar3;
    if (lVar3 == 0) {
      return -0xc;
    }
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2e8),param_2,lVar3,uVar1,0);
    if (iVar2 < 0) {
      _dev_err(param_1,"%s read failed %d\n",param_2,iVar2);
      return iVar2;
    }
  }
  return 0;
}



//------------------------------------------------------------
// eusb2_repeater_init @ 001008f8 size=1768
// signature: undefined eusb2_repeater_init(void)
// callers: []
//------------------------------------------------------------

undefined8 eusb2_repeater_init(undefined8 *param_1)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  undefined4 uVar4;
  ushort uVar5;
  bool bVar6;
  int iVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  if ((*(byte *)(param_1 + 2) & 1) == 0) {
    uVar8 = param_1[0x13];
    uVar4 = *(undefined4 *)(param_1 + 0x15);
  }
  else {
    uVar8 = param_1[0x14];
    uVar4 = *(undefined4 *)((long)param_1 + 0xac);
  }
  eusb2_repeater_update_seq(param_1,uVar8,uVar4);
  mutex_lock(param_1 + 0x1a);
  bVar6 = (*(uint *)(param_1 + 2) & 1) != 0;
  lVar1 = 0xb0;
  if (bVar6) {
    lVar1 = 0xc0;
  }
  lVar2 = 0xb8;
  if (bVar6) {
    lVar2 = 200;
  }
  eusb2_repeater_update_seq
            (param_1,*(undefined8 *)((long)param_1 + lVar1),*(undefined1 *)((long)param_1 + lVar2));
  mutex_unlock(param_1 + 0x1a);
  if ((*(byte *)(param_1 + 0x11) < 8) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x50,7,*(byte *)(param_1 + 0x11),
                         0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x50,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x89) < 0x10) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x51,0xf,
                         *(byte *)((long)param_1 + 0x89),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x51,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x8a) < 8) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x52,7,
                         *(byte *)((long)param_1 + 0x8a),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x52,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x8b) < 8) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x53,7,
                         *(byte *)((long)param_1 + 0x8b),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x53,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x8c) < 8) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x54,7,
                         *(byte *)((long)param_1 + 0x8c),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x54,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x8d) < 4) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x55,3,
                         *(byte *)((long)param_1 + 0x8d),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x55,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x8e) < 4) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x56,3,
                         *(byte *)((long)param_1 + 0x8e),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x56,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x8f) < 8) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x57,7,
                         *(byte *)((long)param_1 + 0x8f),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x57,iVar7)
    ;
  }
  if ((*(byte *)(param_1 + 0x12) < 4) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x58,3,*(byte *)(param_1 + 0x12),
                         0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x58,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x91) < 4) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x59,3,
                         *(byte *)((long)param_1 + 0x91),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x59,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x92) < 4) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x5a,3,
                         *(byte *)((long)param_1 + 0x92),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x5a,iVar7)
    ;
  }
  if ((*(byte *)((long)param_1 + 0x93) < 4) &&
     (iVar7 = regmap_update_bits_base
                        (param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x5b,3,
                         *(byte *)((long)param_1 + 0x93),0,0,0), iVar7 != 0)) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x5b,iVar7)
    ;
  }
  if ((*(byte *)(param_1 + 2) & 1) == 0) {
    iVar7 = regmap_update_bits_base(param_1[0xb],*(ushort *)(param_1 + 0xc) + 0xe8,0x40,0,0,0,0);
    if (iVar7 != 0) {
      _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0xe8,
               iVar7);
    }
    uVar5 = *(ushort *)(param_1 + 0xc);
    uVar8 = param_1[0xb];
    uVar9 = 0;
  }
  else {
    iVar7 = regmap_update_bits_base(param_1[0xb],*(ushort *)(param_1 + 0xc) + 0xe8,0x40,0x40,0,0,0);
    if (iVar7 != 0) {
      _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0xe8,
               iVar7);
    }
    uVar5 = *(ushort *)(param_1 + 0xc);
    uVar8 = param_1[0xb];
    uVar9 = 0x40;
  }
  iVar7 = regmap_update_bits_base(uVar8,uVar5 + 0xed,0x40,uVar9,0,0,0);
  if (iVar7 != 0) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0xed,iVar7)
    ;
  }
  iVar7 = regmap_bulk_read(param_1[0xb],*(ushort *)(param_1 + 0xc) + 8,local_2c,1);
  if (iVar7 != 0) {
    _dev_err(*param_1,"read failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 8,iVar7);
  }
  if (-1 < local_2c[0]) {
    usleep_range_state(10,0x14,2);
    iVar7 = regmap_bulk_read(param_1[0xb],*(ushort *)(param_1 + 0xc) + 8,local_2c,1);
    if (iVar7 != 0) {
      _dev_err(*param_1,"read failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 8,iVar7);
    }
    if (-1 < local_2c[0]) {
      usleep_range_state(10,0x14,2);
      iVar7 = regmap_bulk_read(param_1[0xb],*(ushort *)(param_1 + 0xc) + 8,local_2c,1);
      if (iVar7 != 0) {
        _dev_err(*param_1,"read failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 8,iVar7)
        ;
      }
      if (-1 < local_2c[0]) {
        usleep_range_state(10,0x14,2);
        iVar7 = regmap_bulk_read(param_1[0xb],*(ushort *)(param_1 + 0xc) + 8,local_2c,1);
        if (iVar7 != 0) {
          _dev_err(*param_1,"read failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 8,
                   iVar7);
        }
        if (-1 < local_2c[0]) {
          usleep_range_state(10,0x14,2);
          iVar7 = regmap_bulk_read(param_1[0xb],*(ushort *)(param_1 + 0xc) + 8,local_2c,1);
          if (iVar7 != 0) {
            _dev_err(*param_1,"read failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 8,
                     iVar7);
          }
          if (-1 < local_2c[0]) {
            usleep_range_state(10,0x14,2);
          }
        }
      }
    }
  }
  pcVar3 = "NOT OK";
  if (local_2c[0] < '\0') {
    pcVar3 = "OK";
  }
  _dev_info(*param_1,"eUSB2 repeater status:%s\n",pcVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// eusb2_repeater_reset @ 00100fe4 size=120
// signature: undefined eusb2_repeater_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 eusb2_repeater_reset(undefined8 *param_1,ulong param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x80;
  if ((param_2 & 1) == 0) {
    uVar2 = 0;
  }
  iVar1 = regmap_update_bits_base(param_1[0xb],*(ushort *)(param_1 + 0xc) + 0x46,0x80,uVar2,0,0,0);
  if (iVar1 != 0) {
    _dev_err(*param_1,"write failed: addr=0x%04x, ret=%d\n",*(ushort *)(param_1 + 0xc) + 0x46,iVar1)
    ;
  }
  return 0;
}



//------------------------------------------------------------
// eusb2_repeater_powerup @ 00101060 size=32
// signature: undefined eusb2_repeater_powerup(void)
// callers: []
//------------------------------------------------------------

void eusb2_repeater_powerup(undefined8 param_1)

{
  eusb2_repeater_power(param_1,1);
  return;
}



//------------------------------------------------------------
// eusb2_repeater_powerdown @ 00101084 size=32
// signature: undefined eusb2_repeater_powerdown(void)
// callers: []
//------------------------------------------------------------

void eusb2_repeater_powerdown(undefined8 param_1)

{
  eusb2_repeater_power(param_1,0);
  return;
}



//------------------------------------------------------------
// eusb2_repeater_get_version @ 001010a8 size=140
// signature: undefined eusb2_repeater_get_version(void)
// callers: []
//------------------------------------------------------------

void eusb2_repeater_get_version(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = regmap_bulk_read(param_1[0xb],*(undefined2 *)(param_1 + 0xc),local_2c,1);
  if (iVar2 != 0) {
    _dev_err(*param_1,"read failed: addr=0x%04x, ret=%d\n",*(undefined2 *)(param_1 + 0xc),iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_2c[0]);
  }
  return;
}



//------------------------------------------------------------
// eusb2_repeater_update_seq @ 00101134 size=268
// signature: undefined eusb2_repeater_update_seq(void)
// callers: [eusb2_repeater_init]
//------------------------------------------------------------

void eusb2_repeater_update_seq(undefined8 *param_1,long param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined1 local_5c [4];
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  _dev_info(*param_1,"param override seq count:%d\n");
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      uVar4 = (int)uVar3 + 1;
      uVar6 = -(uVar3 >> 0x1f) & 0xfffffffc00000000 | uVar3 << 2;
      uVar5 = -(ulong)(uVar4 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar4 << 2;
      _dev_info(*param_1,"write 0x%02x to 0x%02x\n",*(undefined4 *)(param_2 + uVar6),
                *(undefined4 *)(param_2 + uVar5));
      uVar4 = (uint)*(ushort *)(param_2 + uVar5);
      local_5c[0] = (undefined1)*(undefined4 *)(param_2 + uVar6);
      iVar2 = regmap_bulk_write(param_1[0xb],uVar4 + *(ushort *)(param_1 + 0xc),local_5c,1);
      if (iVar2 != 0) {
        _dev_err(*param_1,"bulk write failed: addr=0x%04x, ret=%d\n",
                 uVar4 + *(ushort *)(param_1 + 0xc),iVar2);
      }
      uVar4 = (int)uVar3 + 2;
      uVar3 = (ulong)uVar4;
    } while (uVar4 < param_3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// eusb2_repeater_power @ 00101240 size=592
// signature: undefined eusb2_repeater_power(void)
// callers: [eusb2_repeater_remove, eusb2_repeater_powerdown, eusb2_repeater_powerup]
//------------------------------------------------------------

int eusb2_repeater_power(undefined8 *param_1,byte param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined1 uVar4;
  
  if (*(byte *)(param_1 + 0xf) == (param_2 & 1)) {
    return 0;
  }
  if ((param_2 & 1) == 0) {
    iVar1 = regulator_disable(param_1[0xe]);
    if (iVar1 != 0) {
      uVar2 = *param_1;
      pcVar3 = "Unable to disable vdd3:%d\n";
LAB_00101488:
      _dev_err(uVar2,pcVar3,iVar1);
    }
    iVar1 = regulator_set_voltage(param_1[0xe],0,3300000);
    if (iVar1 != 0) {
      uVar2 = *param_1;
      pcVar3 = "Unable to set (0) voltage for vdd3:%d\n";
LAB_00101470:
      _dev_err(uVar2,pcVar3,iVar1);
    }
    iVar1 = regulator_set_load(param_1[0xe],0);
    if (iVar1 < 0) {
      _dev_err(*param_1,"Unable to set (0) HPM of vdd3\n");
    }
LAB_00101320:
    iVar1 = regulator_disable(param_1[0xd]);
    if (iVar1 != 0) {
      uVar2 = *param_1;
      pcVar3 = "Unable to disable vdd18:%d\n";
LAB_00101440:
      _dev_err(uVar2,pcVar3,iVar1);
    }
    iVar1 = regulator_set_voltage(param_1[0xd],0,1800000);
    if (iVar1 != 0) {
      uVar2 = *param_1;
      pcVar3 = "Unable to set (0) voltage for vdd18:%d\n";
LAB_00101414:
      _dev_err(uVar2,pcVar3,iVar1);
    }
    iVar1 = regulator_set_load(param_1[0xd],0);
    if (iVar1 < 0) {
      _dev_err(*param_1,"Unable to set LPM of vdd18\n");
    }
  }
  else {
    iVar1 = regulator_set_load(param_1[0xd],32000);
    if (-1 < iVar1) {
      iVar1 = regulator_set_voltage(param_1[0xd],1800000,1800000);
      if (iVar1 == 0) {
        iVar1 = regulator_enable(param_1[0xd]);
        if (iVar1 == 0) {
          iVar1 = regulator_set_load(param_1[0xe],0xdac);
          if (-1 < iVar1) {
            iVar1 = regulator_set_voltage(param_1[0xe],0x2eebb8,3300000);
            if (iVar1 == 0) {
              iVar1 = regulator_enable(param_1[0xe]);
              if (iVar1 == 0) {
                iVar1 = 0;
                uVar4 = 1;
                goto LAB_00101364;
              }
              uVar2 = *param_1;
              pcVar3 = "Unable to enable vdd3:%d\n";
              goto LAB_00101488;
            }
            uVar2 = *param_1;
            pcVar3 = "Unable to set voltage for vdd3:%d\n";
            goto LAB_00101470;
          }
          _dev_err(*param_1,"Unable to set HPM of vdd3:%d\n",iVar1);
          goto LAB_00101320;
        }
        uVar2 = *param_1;
        pcVar3 = "Unable to enable vdd18:%d\n";
        goto LAB_00101440;
      }
      uVar2 = *param_1;
      pcVar3 = "Unable to set voltage for vdd18:%d\n";
      goto LAB_00101414;
    }
    _dev_err(*param_1,"Unable to set HPM of vdd18:%d\n",iVar1);
  }
  if (*(char *)(param_1 + 0xf) == '\0') {
    return -0x16;
  }
  uVar4 = 0;
LAB_00101364:
  *(undefined1 *)(param_1 + 0xf) = uVar4;
  return iVar1;
}



//------------------------------------------------------------
// user_param_override_show @ 00101494 size=184
// signature: undefined user_param_override_show(void)
// callers: []
//------------------------------------------------------------

long user_param_override_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    lVar2 = -0x16;
  }
  else {
    mutex_lock(lVar2 + 0xd0);
    if (*(char *)(lVar2 + 0xb8) == '\0') {
      iVar3 = 0;
    }
    else {
      uVar4 = 0;
      iVar3 = 0;
      lVar5 = *(long *)(lVar2 + 0xb0);
      do {
        iVar1 = sprintf((char *)(param_3 + iVar3),"0x%x,",*(uint *)(lVar5 + uVar4 * 4));
        iVar3 = iVar1 + iVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(byte *)(lVar2 + 0xb8));
    }
    *(undefined2 *)(param_3 + iVar3) = 10;
    mutex_unlock(lVar2 + 0xd0);
    lVar2 = (long)(iVar3 + 1);
  }
  return lVar2;
}



//------------------------------------------------------------
// user_param_override_store @ 00101550 size=764
// signature: undefined user_param_override_store(void)
// callers: []
//------------------------------------------------------------

void user_param_override_store(long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  char *pcVar1;
  int iVar2;
  char *__s1;
  long lVar3;
  char *pcVar4;
  uint uVar5;
  ulong uVar6;
  byte *pbVar7;
  byte *pbVar8;
  long lVar9;
  ulong uVar10;
  byte local_6c [4];
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_6c[0] = 0;
  if (lVar9 == 0) {
    uVar6 = 0xffffffffffffffea;
    goto LAB_001016b4;
  }
  __s1 = (char *)kstrdup(param_3,0xcc0);
  if (__s1 == (char *)0x0) {
    uVar6 = 0xfffffffffffffff4;
    goto LAB_001016b4;
  }
  mutex_lock(lVar9 + 0xd0);
  iVar2 = strncmp(__s1,"none",4);
  if (iVar2 == 0) {
    *(undefined1 *)(lVar9 + 0xb8) = 0;
    _dev_info(param_1,"Clear user parameters override\n");
    iVar2 = 0;
  }
  else {
    if (param_4 == 0) {
      uVar6 = 0;
    }
    else {
      uVar10 = 0;
      uVar6 = 0;
      pbVar7 = (byte *)0x0;
      do {
        pbVar8 = (byte *)(__s1 + uVar10);
        if (*pbVar8 < 0x2d && (1L << ((ulong)*pbVar8 & 0x3f) & 0x100100002401U) != 0) {
          *pbVar8 = 0;
          pbVar8 = pbVar7;
          if (pbVar7 != (byte *)0x0) {
            iVar2 = kstrtou8(pbVar7,0,local_6c);
            if (iVar2 != 0) {
              _dev_err(param_1,"invalid data: %s\n",pbVar7);
              goto LAB_00101690;
            }
            pbVar8 = (byte *)0x0;
          }
        }
        else {
          uVar5 = (uint)uVar6;
          if (pbVar7 == (byte *)0x0) {
            uVar5 = uVar5 + 1;
          }
          uVar6 = (ulong)uVar5;
          if (pbVar7 != (byte *)0x0) {
            pbVar8 = pbVar7;
          }
        }
        uVar10 = (ulong)((int)uVar10 + 1);
        pbVar7 = pbVar8;
      } while (uVar10 < param_4);
      uVar5 = (uint)uVar6;
      if ((0 < (int)uVar5) && ((uVar6 & 1) == 0)) {
        if (*(byte *)(lVar9 + 0xb9) < uVar5) {
          lVar3 = devm_kmalloc(param_1,uVar6 << 2,0xdc0);
          if (lVar3 == 0) {
            iVar2 = -0xc;
            goto LAB_00101690;
          }
          if (*(long *)(lVar9 + 0xb0) != 0) {
            devm_kfree(param_1);
          }
          *(char *)(lVar9 + 0xb9) = (char)uVar6;
        }
        else {
          lVar3 = *(long *)(lVar9 + 0xb0);
        }
        _dev_info(param_1,"Update %d user parameters\n",uVar5 >> 1);
        uVar6 = 0;
        pcVar4 = (char *)0x0;
        uVar5 = 0;
        do {
          pcVar1 = __s1 + uVar6;
          if (*pcVar1 == '\0') {
            pcVar4 = (char *)0x0;
          }
          else if (pcVar4 == (char *)0x0) {
            iVar2 = kstrtou8(pcVar1,0,local_6c);
            if (iVar2 != 0) {
              _dev_err(param_1,"invalid data: %s\n",pcVar1);
              goto LAB_00101690;
            }
            if ((0 < (int)uVar5) && ((uVar5 & 1) != 0)) {
              _dev_info(param_1,"update: 0x%02x to 0x%02x\n",
                        *(undefined4 *)(lVar3 + (ulong)(uVar5 - 1) * 4),local_6c[0]);
            }
            *(uint *)(lVar3 + (long)(int)uVar5 * 4) = (uint)local_6c[0];
            pcVar4 = pcVar1;
            uVar5 = uVar5 + 1;
          }
          else {
          }
          uVar6 = (ulong)((int)uVar6 + 1);
        } while (uVar6 < param_4);
        iVar2 = 0;
        *(long *)(lVar9 + 0xb0) = lVar3;
        *(char *)(lVar9 + 0xb8) = (char)uVar5;
        goto LAB_00101690;
      }
    }
    _dev_err(param_1,"invalid len=%d for %s\n",uVar6,param_3);
    iVar2 = -0x16;
  }
LAB_00101690:
  kfree(__s1);
  mutex_unlock(lVar9 + 0xd0);
  uVar6 = (long)iVar2;
  if (-1 < iVar2) {
    uVar6 = param_4;
  }
LAB_001016b4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// user_host_param_override_show @ 00101850 size=184
// signature: undefined user_host_param_override_show(void)
// callers: []
//------------------------------------------------------------

long user_host_param_override_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    lVar2 = -0x16;
  }
  else {
    mutex_lock(lVar2 + 0xd0);
    if (*(char *)(lVar2 + 200) == '\0') {
      iVar3 = 0;
    }
    else {
      uVar4 = 0;
      iVar3 = 0;
      lVar5 = *(long *)(lVar2 + 0xc0);
      do {
        iVar1 = sprintf((char *)(param_3 + iVar3),"0x%x,",*(uint *)(lVar5 + uVar4 * 4));
        iVar3 = iVar1 + iVar3;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(byte *)(lVar2 + 200));
    }
    *(undefined2 *)(param_3 + iVar3) = 10;
    mutex_unlock(lVar2 + 0xd0);
    lVar2 = (long)(iVar3 + 1);
  }
  return lVar2;
}



//------------------------------------------------------------
// user_host_param_override_store @ 0010190c size=764
// signature: undefined user_host_param_override_store(void)
// callers: []
//------------------------------------------------------------

void user_host_param_override_store
               (long param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  char *pcVar1;
  int iVar2;
  char *__s1;
  long lVar3;
  char *pcVar4;
  uint uVar5;
  ulong uVar6;
  byte *pbVar7;
  byte *pbVar8;
  long lVar9;
  ulong uVar10;
  byte local_6c [4];
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_6c[0] = 0;
  if (lVar9 == 0) {
    uVar6 = 0xffffffffffffffea;
    goto LAB_00101a70;
  }
  __s1 = (char *)kstrdup(param_3,0xcc0);
  if (__s1 == (char *)0x0) {
    uVar6 = 0xfffffffffffffff4;
    goto LAB_00101a70;
  }
  mutex_lock(lVar9 + 0xd0);
  iVar2 = strncmp(__s1,"none",4);
  if (iVar2 == 0) {
    *(undefined1 *)(lVar9 + 200) = 0;
    _dev_info(param_1,"Clear user host parameters override\n");
    iVar2 = 0;
  }
  else {
    if (param_4 == 0) {
      uVar6 = 0;
    }
    else {
      uVar10 = 0;
      uVar6 = 0;
      pbVar7 = (byte *)0x0;
      do {
        pbVar8 = (byte *)(__s1 + uVar10);
        if (*pbVar8 < 0x2d && (1L << ((ulong)*pbVar8 & 0x3f) & 0x100100002401U) != 0) {
          *pbVar8 = 0;
          pbVar8 = pbVar7;
          if (pbVar7 != (byte *)0x0) {
            iVar2 = kstrtou8(pbVar7,0,local_6c);
            if (iVar2 != 0) {
              _dev_err(param_1,"invalid data: %s\n",pbVar7);
              goto LAB_00101a4c;
            }
            pbVar8 = (byte *)0x0;
          }
        }
        else {
          uVar5 = (uint)uVar6;
          if (pbVar7 == (byte *)0x0) {
            uVar5 = uVar5 + 1;
          }
          uVar6 = (ulong)uVar5;
          if (pbVar7 != (byte *)0x0) {
            pbVar8 = pbVar7;
          }
        }
        uVar10 = (ulong)((int)uVar10 + 1);
        pbVar7 = pbVar8;
      } while (uVar10 < param_4);
      uVar5 = (uint)uVar6;
      if ((0 < (int)uVar5) && ((uVar6 & 1) == 0)) {
        if (*(byte *)(lVar9 + 0xc9) < uVar5) {
          lVar3 = devm_kmalloc(param_1,uVar6 << 2,0xdc0);
          if (lVar3 == 0) {
            iVar2 = -0xc;
            goto LAB_00101a4c;
          }
          if (*(long *)(lVar9 + 0xc0) != 0) {
            devm_kfree(param_1);
          }
          *(char *)(lVar9 + 0xc9) = (char)uVar6;
        }
        else {
          lVar3 = *(long *)(lVar9 + 0xc0);
        }
        _dev_info(param_1,"Update %d user host parameters\n",uVar5 >> 1);
        uVar6 = 0;
        pcVar4 = (char *)0x0;
        uVar5 = 0;
        do {
          pcVar1 = __s1 + uVar6;
          if (*pcVar1 == '\0') {
            pcVar4 = (char *)0x0;
          }
          else if (pcVar4 == (char *)0x0) {
            iVar2 = kstrtou8(pcVar1,0,local_6c);
            if (iVar2 != 0) {
              _dev_err(param_1,"invalid data: %s\n",pcVar1);
              goto LAB_00101a4c;
            }
            if ((0 < (int)uVar5) && ((uVar5 & 1) != 0)) {
              _dev_info(param_1,"update: 0x%02x to 0x%02x\n",
                        *(undefined4 *)(lVar3 + (ulong)(uVar5 - 1) * 4),local_6c[0]);
            }
            *(uint *)(lVar3 + (long)(int)uVar5 * 4) = (uint)local_6c[0];
            pcVar4 = pcVar1;
            uVar5 = uVar5 + 1;
          }
          else {
          }
          uVar6 = (ulong)((int)uVar6 + 1);
        } while (uVar6 < param_4);
        iVar2 = 0;
        *(long *)(lVar9 + 0xc0) = lVar3;
        *(char *)(lVar9 + 200) = (char)uVar5;
        goto LAB_00101a4c;
      }
    }
    _dev_err(param_1,"invalid len=%d for %s\n",uVar6,param_3);
    iVar2 = -0x16;
  }
LAB_00101a4c:
  kfree(__s1);
  mutex_unlock(lVar9 + 0xd0);
  uVar6 = (long)iVar2;
  if (-1 < iVar2) {
    uVar6 = param_4;
  }
LAB_00101a70:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101c0c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&eusb2_repeater_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101c3c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&eusb2_repeater_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104000 size=1
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
// platform_driver_unregister @ 00104008 size=1
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
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [eusb2_repeater_probe, user_host_param_override_store, user_param_override_store, eusb2_repeater_read_overrides]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00104018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [eusb2_repeater_probe, eusb2_repeater_read_overrides]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00104028 size=1
// signature: undefined devm_regulator_get(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_add_repeater_dev @ 00104030 size=1
// signature: undefined usb_add_repeater_dev(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_add_repeater_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00104038 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_x8 @ 00104040 size=1
// signature: undefined debugfs_create_x8(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_x8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104048 size=1
// signature: undefined __mutex_init(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00104050 size=1
// signature: undefined device_create_file(void)
// callers: [eusb2_repeater_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104058 size=1
// signature: undefined _dev_err(void)
// callers: [eusb2_repeater_probe, eusb2_repeater_update_seq, eusb2_repeater_reset, eusb2_repeater_init, user_host_param_override_store, eusb2_repeater_get_version, user_param_override_store, eusb2_repeater_read_overrides, eusb2_repeater_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [eusb2_repeater_probe, eusb2_repeater_update_seq, eusb2_repeater_init, user_host_param_override_store, eusb2_repeater_get_version, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00104068 size=1
// signature: undefined device_remove_file(void)
// callers: [eusb2_repeater_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00104070 size=1
// signature: undefined debugfs_remove(void)
// callers: [eusb2_repeater_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_remove_repeater_dev @ 00104078 size=1
// signature: undefined usb_remove_repeater_dev(void)
// callers: [eusb2_repeater_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_remove_repeater_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00104080 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [eusb2_repeater_read_overrides]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104088 size=1
// signature: undefined mutex_lock(void)
// callers: [user_host_param_override_show, eusb2_repeater_init, user_param_override_show, user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104090 size=1
// signature: undefined mutex_unlock(void)
// callers: [user_host_param_override_show, eusb2_repeater_init, user_param_override_show, user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00104098 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [eusb2_repeater_reset, eusb2_repeater_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 001040a0 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [eusb2_repeater_init, eusb2_repeater_get_version]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001040a8 size=1
// signature: undefined usleep_range_state(void)
// callers: [eusb2_repeater_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001040b0 size=1
// signature: undefined _dev_info(void)
// callers: [eusb2_repeater_update_seq, eusb2_repeater_init, user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 001040b8 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [eusb2_repeater_update_seq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 001040c0 size=1
// signature: undefined regulator_set_load(void)
// callers: [eusb2_repeater_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001040c8 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [eusb2_repeater_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001040d0 size=1
// signature: undefined regulator_enable(void)
// callers: [eusb2_repeater_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001040d8 size=1
// signature: undefined regulator_disable(void)
// callers: [eusb2_repeater_power]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 001040e0 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [user_host_param_override_show, user_param_override_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 001040e8 size=1
// signature: undefined kstrdup(void)
// callers: [user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001040f0 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 001040f8 size=1
// signature: undefined kstrtou8(void)
// callers: [user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104100 size=1
// signature: undefined kfree(void)
// callers: [user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00104108 size=1
// signature: undefined devm_kfree(void)
// callers: [user_host_param_override_store, user_param_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



