// Decompiled by Ghidra 12.2
// Program: at803x.ko
// Image base: 00100000

//------------------------------------------------------------
// at803x_config_init @ 001007d4 size=828
// signature: undefined at803x_config_init(void)
// callers: []
//------------------------------------------------------------

uint at803x_config_init(long param_1)

{
  byte bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  byte *pbVar9;
  long lVar10;
  
  if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) == 0x4dd074) {
    lVar10 = *(long *)(param_1 + 0x528);
    mutex_lock(*(long *)(param_1 + 0x390) + 0x470);
    bVar3 = *(char *)(lVar10 + 10) != '\0';
    uVar7 = 0;
    if (bVar3) {
      uVar7 = 0xffff8000;
    }
    uVar8 = 0xffff8000;
    if (bVar3) {
      uVar8 = 0;
    }
    uVar4 = __phy_modify(param_1,0x1f,uVar7,uVar8);
    mutex_unlock(*(long *)(param_1 + 0x390) + 0x470);
    if (uVar4 != 0) {
      return uVar4;
    }
    uVar4 = **(uint **)(param_1 + 0x528);
    uVar5 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,
                          0x1f);
    if ((uVar4 & 1) == 0) {
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      uVar4 = uVar4 & 0xfffffffb;
    }
    else {
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      uVar4 = uVar4 | 4;
    }
    uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                          uVar4);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  uVar4 = *(uint *)(param_1 + 0x494);
  uVar5 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0);
  if ((uVar4 & 0xfffffffe) == 10) {
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = uVar4 | 0xffff8000;
  }
  else {
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = uVar4 & 0x7fff;
  }
  uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,uVar4
                       );
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  if ((*(int *)(param_1 + 0x494) == 0xc) || (*(int *)(param_1 + 0x494) == 10)) {
    uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,5);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = uVar4 | 0x100;
  }
  else {
    uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,5);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = uVar4 & 0xfffffeff;
  }
  uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,uVar4
                       );
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  pbVar9 = *(byte **)(param_1 + 0x528);
  if ((*pbVar9 >> 1 & 1) == 0) {
    bVar1 = pbVar9[8];
    bVar2 = pbVar9[9];
    if (bVar2 == 0 && bVar1 == 0) goto LAB_00100a68;
    uVar4 = 0;
    if (bVar1 != 0) {
      uVar4 = 0xffffff00;
    }
    uVar5 = 0;
    if (bVar1 != 0) {
      uVar5 = (uint)bVar1 << 8;
    }
    if (bVar2 != 0) {
      uVar4 = uVar4 | 0xff;
    }
    uVar4 = phy_modify_mmd(param_1,3,0x805b,uVar4,uVar5 | bVar2);
    if (uVar4 == 0) {
      uVar6 = 0x100;
      goto LAB_00100a48;
    }
  }
  else {
    uVar6 = 0;
LAB_00100a48:
    uVar4 = phy_modify_mmd(param_1,3,0x805d,0x100,uVar6);
  }
  if ((int)uVar4 < 0) {
    return uVar4;
  }
  pbVar9 = *(byte **)(param_1 + 0x528);
LAB_00100a68:
  if (*(short *)(pbVar9 + 6) != 0) {
    uVar4 = phy_modify_mmd(param_1,7,0x8016,*(short *)(pbVar9 + 6),*(undefined2 *)(pbVar9 + 4));
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    pbVar9 = *(byte **)(param_1 + 0x528);
  }
  if ((*pbVar9 >> 2 & 1) != 0) {
    uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0xb
                         );
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar4 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                          uVar4 & 0x7fff);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
  }
  uVar4 = phy_modify(param_1,4,0x2000,0);
  return uVar4;
}



//------------------------------------------------------------
// at803x_probe @ 00100b14 size=1056
// signature: undefined at803x_probe(void)
// callers: []
//------------------------------------------------------------

uint at803x_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  ushort uVar7;
  undefined8 uVar8;
  ulong *puVar9;
  int local_84;
  undefined8 local_80;
  long local_78 [3];
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  puVar3 = (uint *)devm_kmalloc(param_1,0x38,0xdc0);
  if (puVar3 == (uint *)0x0) {
    uVar2 = 0xfffffff4;
    goto LAB_00100ea8;
  }
  uVar8 = *(undefined8 *)(param_1 + 0x2e8);
  *(uint **)(param_1 + 0x528) = puVar3;
  local_80 = 0;
  local_84 = 0;
  lVar4 = of_find_property(uVar8,"qca,disable-smarteee",0);
  if (lVar4 != 0) {
    *puVar3 = *puVar3 | 2;
  }
  lVar4 = of_find_property(uVar8,"qca,disable-hibernation-mode",0);
  if (lVar4 != 0) {
    *puVar3 = *puVar3 | 4;
  }
  iVar1 = of_property_read_variable_u32_array(uVar8,"qca,smarteee-tw-us-1g",&local_84,1,0);
  if (-1 < iVar1) {
    if (0xffffff00 < local_84 - 0x100U) {
      *(char *)(puVar3 + 2) = (char)local_84;
      goto LAB_00100be0;
    }
    uVar2 = 0xffffffea;
    pcVar6 = "invalid qca,smarteee-tw-us-1g\n";
LAB_00100f24:
    _dev_err(param_1,pcVar6);
    goto LAB_00100ea8;
  }
LAB_00100be0:
  iVar1 = of_property_read_variable_u32_array(uVar8,"qca,smarteee-tw-us-100m",&local_84,1,0);
  if (-1 < iVar1) {
    if (local_84 - 0x100U < 0xffffff01) {
      uVar2 = 0xffffffea;
      pcVar6 = "invalid qca,smarteee-tw-us-100m\n";
      goto LAB_00100f24;
    }
    *(char *)((long)puVar3 + 9) = (char)local_84;
  }
  iVar1 = of_property_read_variable_u32_array(uVar8,"qca,clk-out-frequency",(long)&local_80 + 4,1,0)
  ;
  if (-1 < iVar1) {
    uVar2 = 0xffffffea;
    pcVar6 = "invalid qca,clk-out-frequency\n";
    if (local_80._4_4_ < 62500000) {
      if (local_80._4_4_ == 25000000) {
        uVar7 = 0;
      }
      else {
        if (local_80._4_4_ != 50000000) goto LAB_00100f24;
        uVar7 = 8;
      }
    }
    else if (local_80._4_4_ == 62500000) {
      uVar7 = 0x10;
    }
    else {
      if (local_80._4_4_ != 125000000) goto LAB_00100f24;
      uVar7 = 0x18;
    }
    uVar2 = puVar3[1];
    lVar4 = *(long *)(param_1 + 0x3f0);
    *(ushort *)(puVar3 + 1) = (ushort)uVar2 | uVar7;
    *(ushort *)((long)puVar3 + 6) = *(ushort *)((long)puVar3 + 6) | 0x1c;
    if ((*(uint *)(lVar4 + 0xb8) | 4) == 0x4dd076) {
      *(ushort *)(puVar3 + 1) = (ushort)uVar2 & 0x18 | uVar7;
      *(undefined2 *)((long)puVar3 + 6) = 0x18;
    }
  }
  iVar1 = of_property_read_variable_u32_array(uVar8,"qca,clk-out-strength",&local_80,1,0);
  if (-1 < iVar1) {
    *(ushort *)((long)puVar3 + 6) = *(ushort *)((long)puVar3 + 6) | 0x180;
    if ((int)local_80 != 0) {
      if (((int)local_80 != 1) && ((int)local_80 != 2)) {
        uVar2 = 0xffffffea;
        pcVar6 = "invalid qca,clk-out-strength\n";
        goto LAB_00100f24;
      }
      *(ushort *)(puVar3 + 1) = (ushort)puVar3[1] | (ushort)local_80;
    }
  }
  if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) == 0x4dd074) {
    lVar4 = of_find_property(uVar8,"qca,keep-pll-enabled",0);
    if (lVar4 != 0) {
      *puVar3 = *puVar3 | 1;
    }
    lVar4 = *(long *)(param_1 + 0x528);
    local_58 = 0;
    uStack_50 = 0;
    local_78[1] = 0;
    uStack_60 = 0;
    local_78[0] = param_1;
    local_78[2] = param_1;
    uVar5 = devm_regulator_register(param_1,&vddio_desc,local_78);
    puVar9 = (ulong *)(lVar4 + 0x10);
    *puVar9 = uVar5;
    if (uVar5 < 0xfffffffffffff001) {
      uVar5 = devm_regulator_register(param_1,&vddh_desc,local_78);
      puVar9 = (ulong *)(lVar4 + 0x18);
      *puVar9 = uVar5;
      if (0xfffffffffffff000 < uVar5) {
        pcVar6 = "failed to register VDDH regulator\n";
        goto LAB_00100f04;
      }
    }
    else {
      pcVar6 = "failed to register VDDIO regulator\n";
LAB_00100f04:
      _dev_err(param_1,pcVar6);
      uVar2 = (uint)*puVar9;
      if ((int)uVar2 < 0) goto LAB_00100ea8;
    }
    uVar2 = devm_regulator_get_enable_optional(param_1,"vddio");
    if (uVar2 != 0) {
      pcVar6 = "failed to get VDDIO regulator\n";
      goto LAB_00100f24;
    }
    uVar2 = phy_sfp_probe(param_1,&at803x_sfp_ops);
    if ((int)uVar2 < 0) goto LAB_00100ea8;
    if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) != 0x4dd074) goto LAB_00100ea4;
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1f);
    if ((int)uVar2 < 0) goto LAB_00100ea8;
    uVar2 = uVar2 & 0xf;
    if (uVar2 - 2 < 2) {
      *(undefined1 *)((long)puVar3 + 0xb) = 1;
LAB_00100e7c:
      *(undefined1 *)((long)puVar3 + 10) = 1;
    }
    else if ((uVar2 == 6) || (uVar2 == 0xe)) goto LAB_00100e7c;
    uVar2 = phy_modify_mmd(param_1,3,0x8012,0x20,0);
    if (uVar2 != 0) goto LAB_00100ea8;
  }
LAB_00100ea4:
  uVar2 = 0;
LAB_00100ea8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// at803x_suspend @ 00100f38 size=88
// signature: undefined at803x_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_suspend(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12);
  uVar2 = 0x800;
  if ((uVar1 & 1) != 0) {
    uVar2 = 0x400;
  }
  phy_modify(param_1,0,0,uVar2);
  return 0;
}



//------------------------------------------------------------
// at803x_resume @ 00100f94 size=40
// signature: undefined at803x_resume(void)
// callers: []
//------------------------------------------------------------

void at803x_resume(undefined8 param_1)

{
  phy_modify(param_1,0,0xc00,0);
  return;
}



//------------------------------------------------------------
// at803x_config_aneg @ 00100fc0 size=232
// signature: undefined at803x_config_aneg(void)
// callers: []
//------------------------------------------------------------

void at803x_config_aneg(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x528);
  uVar1 = *(byte *)(param_1 + 0x639) - 1;
  if ((2 < uVar1) ||
     ((iVar2 = phy_modify_changed(param_1,0x10,0x60,0x6000200000 >> (((ulong)uVar1 & 3) << 4)),
      -1 < iVar2 && ((iVar2 != 1 || (iVar2 = genphy_soft_reset(param_1), -1 < iVar2)))))) {
    if (*(char *)(lVar3 + 0xb) == '\0') {
      if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) == 0x4dd101) {
        if ((*(byte *)(param_1 + 0x485) >> 4 & 1) == 0) {
          genphy_c45_pma_setup_forced(param_1);
        }
        iVar2 = phy_modify_mmd_changed
                          (param_1,7,0x20,0x80,
                           (uint)((ulong)*(undefined8 *)(param_1 + 0x4c0) >> 0x28) & 0x80);
        if (iVar2 < 0) {
          return;
        }
      }
      else {
        iVar2 = 0;
      }
      __genphy_config_aneg(param_1,iVar2 != 0);
    }
    else {
      genphy_c37_config_aneg(param_1);
    }
  }
  return;
}



//------------------------------------------------------------
// at803x_read_status @ 001010ac size=168
// signature: undefined at803x_read_status(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_read_status(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(char *)(*(long *)(param_1 + 0x528) + 0xb) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x484);
    uVar2 = genphy_update_link(param_1);
    if ((int)uVar2 == 0) {
      if ((((*(uint *)(param_1 + 0x484) >> 0xc & 1) == 0) || ((uVar1 >> 0xd & 1) == 0)) ||
         ((*(uint *)(param_1 + 0x484) >> 0xd & 1) == 0)) {
        *(undefined8 *)(param_1 + 0x498) = 0xffffffffff;
        *(undefined8 *)(param_1 + 0x4a4) = 0;
        uVar2 = genphy_read_lpa(param_1);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        uVar2 = at803x_read_specific_status(param_1);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        if (((*(uint *)(param_1 + 0x484) ^ 0xffffffff) & 0x5000) == 0) {
          phy_resolve_aneg_pause(param_1);
        }
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = genphy_c37_read_status(param_1);
  }
  return uVar2;
}



//------------------------------------------------------------
// at803x_config_intr @ 00101158 size=192
// signature: undefined at803x_config_intr(void)
// callers: []
//------------------------------------------------------------

ulong at803x_config_intr(long param_1)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x528);
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12);
  if (*(char *)(param_1 + 0x485) < '\0') {
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x13);
    uVar4 = uVar2;
    if (-1 < (int)uVar2) {
      uVar4 = 0;
    }
    uVar3 = (ulong)uVar4;
    if (-1 < (int)uVar2) {
      uVar4 = 0xec00;
      if (*(char *)(lVar5 + 10) != '\0') {
        uVar4 = 0xed80;
      }
      uVar3 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12,
                            uVar4 | uVar1);
    }
  }
  else {
    uVar3 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12,0);
    if ((int)uVar3 == 0) {
      uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x13);
      if (-1 < (int)uVar1) {
        uVar1 = 0;
      }
      uVar3 = (ulong)uVar1;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// at803x_handle_interrupt @ 0010121c size=116
// signature: undefined at803x_handle_interrupt(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_handle_interrupt(long param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x13);
  if (((int)uVar1 < 0) ||
     (uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12),
     (int)uVar2 < 0)) {
    phy_error(param_1);
  }
  else if ((uVar2 & uVar1) != 0) {
    phy_trigger_machine(param_1);
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// at803x_set_wol @ 00101294 size=440
// signature: undefined at803x_set_wol(void)
// callers: []
//------------------------------------------------------------

uint at803x_set_wol(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint *puVar5;
  
  if ((*(byte *)(param_2 + 8) >> 5 & 1) == 0) {
    if ((*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) == 0x4dd074) &&
       (uVar1 = phy_modify_mmd(param_1,3,0x8012,0x20,0), uVar1 != 0)) {
      return uVar1;
    }
    uVar3 = 1;
    uVar4 = 0;
  }
  else {
    if (*(long *)(param_1 + 0x620) == 0) {
      return 0xffffffed;
    }
    puVar5 = *(uint **)(*(long *)(param_1 + 0x620) + 0x300);
    uVar1 = *puVar5;
    if (((uVar1 & 1) != 0) || (uVar1 == 0 && (short)puVar5[1] == 0)) {
      return 0xffffffea;
    }
    phy_write_mmd(param_1,3,0x804a,((uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8) & 0xffff);
    phy_write_mmd(param_1,3,0x804b,
                  *(ushort *)((long)puVar5 + 2) >> 8 | *(ushort *)((long)puVar5 + 2) << 8);
    phy_write_mmd(param_1,3,0x804c,(ushort)puVar5[1] >> 8 | (ushort)puVar5[1] << 8);
    if ((*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) == 0x4dd074) &&
       (uVar1 = phy_modify_mmd(param_1,3,0x8012,0,0x20), uVar1 != 0)) {
      return uVar1;
    }
    uVar3 = 0;
    uVar4 = 1;
  }
  uVar1 = phy_modify(param_1,0x12,uVar3,uVar4);
  if (uVar1 == 0) {
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x13);
    uVar1 = uVar2;
    if ((-1 < (int)uVar2) &&
       (uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12)
       , -1 < (int)uVar1)) {
      if (((uVar2 & uVar1 & 0xfffffffe) != 0) &&
         (((*(int *)(param_1 + 0x48c) != 6 ||
           ((*(byte *)(*(long *)(param_1 + 0x3f0) + 0xd8) >> 2 & 1) == 0)) &&
          (*(int *)(param_1 + 0x520) != -1)))) {
        phy_trigger_machine(param_1);
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// at803x_get_wol @ 00101450 size=88
// signature: undefined at803x_get_wol(void)
// callers: []
//------------------------------------------------------------

void at803x_get_wol(long param_1,long param_2)

{
  uint uVar1;
  
  *(undefined8 *)(param_2 + 4) = 0x20;
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12);
  if ((uVar1 & 0x80000001) == 1) {
    *(uint *)(param_2 + 8) = *(uint *)(param_2 + 8) | 0x20;
  }
  return;
}



//------------------------------------------------------------
// at803x_cable_test_start @ 001014ac size=136
// signature: undefined at803x_cable_test_start(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_cable_test_start(long param_1)

{
  uint uVar1;
  
  mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0,0x1000);
  mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),4,1);
  uVar1 = *(int *)(param_1 + 0x3f8) - 0x4dd023;
  if ((0x1f < uVar1) || ((1 << (ulong)(uVar1 & 0x1f) & 0xc0000001U) == 0)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),9,0);
  }
  return 0;
}



//------------------------------------------------------------
// at803x_cable_test_get_status @ 00101538 size=608
// signature: undefined at803x_cable_test_get_status(void)
// callers: []
//------------------------------------------------------------

uint at803x_cable_test_get_status(long param_1,undefined1 *param_2)

{
  ulong uVar1;
  undefined4 uVar2;
  char cVar3;
  bool bVar4;
  uint uVar5;
  long lVar6;
  code *pcVar7;
  uint uVar8;
  undefined8 uVar9;
  ulong uVar10;
  int iVar11;
  ulong local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  uVar8 = *(int *)(param_1 + 0x3f8) - 0x4dd023;
  if ((uVar8 < 0x20) && ((1 << (ulong)(uVar8 & 0x1f) & 0xc0000001U) != 0)) {
    local_70 = 3;
  }
  else {
    local_70 = 0xf;
  }
  iVar11 = 0x14;
  *param_2 = 0;
  while (iVar11 != 0) {
    uVar10 = 0;
    iVar11 = iVar11 + -1;
    do {
      uVar8 = (uint)(-1L << (uVar10 & 0x3f)) & (uint)local_70;
      uVar10 = ((ulong)uVar8 & 10) >> 1 | ((ulong)uVar8 & 5) << 1;
      uVar1 = 4;
      if ((uVar8 & 0xf) != 0) {
        uVar1 = LZCOUNT((uVar10 >> 2 | (uVar10 & 0x3333333333333333) << 2) << 0x3c);
      }
      if (3 < uVar1) break;
      uVar8 = 0xffffa400;
      if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) != 0x4dd101) {
        uVar8 = ((uint)uVar1 & 3) << 8 | 1;
      }
      uVar8 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x16,
                            uVar8);
      if ((uVar8 == 0) && (uVar8 = at803x_cdt_wait_for_completion(param_1), uVar8 == 0)) {
        uVar8 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1c)
        ;
        if ((int)uVar8 < 0) goto LAB_0010175c;
        if (((uVar8 ^ 0xffffffff) & 0x300) != 0) {
          if (3 < uVar1) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(1,0x10179c);
            (*pcVar7)();
          }
          uVar2 = *(undefined4 *)(&at803x_cable_test_one_pair_ethtool_pair + uVar1 * 4);
          uVar5 = (uVar8 & 0xffff) >> 8 & 3;
          if (uVar5 == 0) {
            uVar9 = 1;
LAB_0010171c:
            ethnl_cable_test_result(param_1,uVar2,uVar9);
          }
          else {
            if (uVar5 == 1) {
              uVar9 = 3;
            }
            else {
              if (uVar5 != 2) {
                uVar9 = 0;
                goto LAB_0010171c;
              }
              uVar9 = 2;
            }
            ethnl_cable_test_result(param_1,uVar2,uVar9);
            ethnl_cable_test_fault_length(param_1,uVar2,(ulong)((uVar8 & 0xff) * 0x338) / 10);
          }
          goto LAB_001015e0;
        }
      }
      else {
        if ((int)uVar8 < 0) goto LAB_0010175c;
LAB_001015e0:
        Hint_Prefetch(&local_70,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(&local_70,0x10);
          if (bVar4) {
            cVar3 = ExclusiveMonitorsStatus();
            local_70 = local_70 & (1L << (uVar1 & 0x3f) ^ 0xffffffffffffffffU);
          }
        } while (cVar3 != '\0');
      }
      uVar10 = uVar1 + 1;
    } while (uVar1 < 3);
    if ((local_70 == 0) || (msleep(0xfa), local_70 == 0)) break;
  }
  uVar8 = 0;
  *param_2 = 1;
LAB_0010175c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// at803x_get_tunable @ 001017a4 size=104
// signature: undefined at803x_get_tunable(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_get_tunable(long param_1,long param_2,byte *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_2 + 4) == 1) {
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x14);
    uVar1 = (uint)uVar2;
    if (-1 < (int)uVar1) {
      uVar2 = 0;
      *param_3 = ((byte)(uVar1 >> 2) & 7) + 2 & (byte)((int)(uVar1 << 0x1a) >> 0x1f);
    }
  }
  else {
    uVar2 = 0xffffffa1;
  }
  return uVar2;
}



//------------------------------------------------------------
// at803x_set_tunable @ 00101810 size=160
// signature: undefined at803x_set_tunable(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_set_tunable(undefined8 param_1,long param_2,byte *param_3)

{
  undefined8 uVar1;
  byte bVar2;
  
  if (*(int *)(param_2 + 4) != 1) {
    return 0xffffffa1;
  }
  bVar2 = *param_3;
  uVar1 = 0x22;
  if (7 < bVar2 - 2) {
    if (bVar2 == 0) {
      bVar2 = 0;
      goto LAB_00101858;
    }
    if (bVar2 != 0xff) {
      return 0xffffffea;
    }
    bVar2 = 5;
  }
  bVar2 = bVar2 * '\x04' + 0x18 & 0x1c | 0x22;
  uVar1 = 0x1c;
LAB_00101858:
  uVar1 = phy_modify_changed(param_1,0x14,uVar1,bVar2);
  if ((int)uVar1 == 1) {
    uVar1 = phy_init_hw(param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// at803x_link_change_notify @ 001018b4 size=360
// signature: undefined at803x_link_change_notify(void)
// callers: []
//------------------------------------------------------------

void at803x_link_change_notify(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  if ((*(int *)(param_1 + 0x48c) == 5) && (*(long *)(param_1 + 0x3d8) != 0)) {
    uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0);
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),4);
    uVar3 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),9);
    uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12);
    uVar5 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x14);
    uVar6 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x18);
    mdio_device_reset(param_1,1);
    msleep(1);
    mdio_device_reset(param_1,0);
    msleep(1);
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0,uVar1);
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),4,uVar2);
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),9,uVar3);
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x12,uVar4);
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x14,uVar5);
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x18,uVar6);
  }
  return;
}



//------------------------------------------------------------
// at803x_get_features @ 00101a20 size=168
// signature: undefined at803x_get_features(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_get_features(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x528);
  uVar1 = genphy_read_abilities();
  if ((int)uVar1 == 0) {
    iVar2 = *(int *)(*(long *)(param_1 + 0x3f0) + 0xb8);
    if (iVar2 == 0x4dd101) {
      uVar1 = phy_read_mmd(param_1,1,0x15);
      if ((int)(uint)uVar1 < 0) {
        return uVar1;
      }
      *(ulong *)(param_1 + 0x4b0) =
           *(ulong *)(param_1 + 0x4b0) & 0xffff000000000000 |
           *(ulong *)(param_1 + 0x4b0) & 0x7fffffffffff | (ulong)((uint)uVar1 & 1) << 0x2f;
      iVar2 = *(int *)(*(long *)(param_1 + 0x3f0) + 0xb8);
    }
    if ((iVar2 == 0x4dd074) && (*(char *)(lVar3 + 0xb) == '\0')) {
      uVar1 = 0;
      *(ulong *)(param_1 + 0x4b0) = *(ulong *)(param_1 + 0x4b0) & 0xfffffdffffffffff;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// at803x_read_page @ 00101acc size=56
// signature: undefined at803x_read_page(void)
// callers: []
//------------------------------------------------------------

uint at803x_read_page(long param_1)

{
  uint uVar1;
  
  uVar1 = __mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1f);
  if (-1 < (int)uVar1) {
    uVar1 = uVar1 >> 0xf & 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// at803x_write_page @ 00101b08 size=48
// signature: undefined at803x_write_page(void)
// callers: []
//------------------------------------------------------------

void at803x_write_page(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  if (param_2 != 1) {
    uVar1 = 0xffff8000;
  }
  uVar2 = 0xffff8000;
  if (param_2 != 1) {
    uVar2 = 0;
  }
  __phy_modify(param_1,0x1f,uVar1,uVar2);
  return;
}



//------------------------------------------------------------
// qca83xx_config_init @ 00101b3c size=456
// signature: undefined qca83xx_config_init(void)
// callers: [qca83xx_resume]
//------------------------------------------------------------

undefined8 qca83xx_config_init(long param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  
  uVar4 = *(uint *)(param_1 + 0x490) & 7;
  if (uVar4 == 4) {
LAB_00101bdc:
    phy_write_mmd(param_1,3,0x800d,0x803f);
    puVar1 = (undefined8 *)(param_1 + 0x390);
    puVar2 = (undefined4 *)(param_1 + 0x3d0);
    iVar3 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,
                          0x3d);
    if (-1 < iVar3) {
      mdiobus_write(*puVar1,*puVar2,0x1e,0x6860);
    }
    iVar3 = mdiobus_write(*puVar1,*puVar2,0x1d,5);
    if (-1 < iVar3) {
      mdiobus_write(*puVar1,*puVar2,0x1e,0x2c46);
    }
    iVar3 = mdiobus_write(*puVar1,*puVar2,0x1d,0x3c);
    if (iVar3 < 0) goto LAB_00101c7c;
    uVar5 = 0x6000;
  }
  else {
    if (uVar4 == 2) {
      phy_write_mmd(param_1,7,0x3c,0);
      goto LAB_00101bdc;
    }
    if (uVar4 != 1) goto LAB_00101c7c;
    iVar3 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0);
    if (-1 < iVar3) {
      mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,0x2ea);
    }
    iVar3 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,
                          0x3d);
    if (iVar3 < 0) goto LAB_00101c7c;
    uVar5 = 0x68a0;
  }
  mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,uVar5);
LAB_00101c7c:
  if (((*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) - 0x4dd033U < 2) &&
      (iVar3 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,
                             0), -1 < iVar3)) &&
     (uVar4 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e),
     -1 < (int)uVar4)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                  uVar4 & 0xfffffffb);
  }
  phy_modify(param_1,9,0,0x400);
  return 0;
}



//------------------------------------------------------------
// qca83xx_suspend @ 00101d08 size=224
// signature: undefined qca83xx_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 qca83xx_suspend(long param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) == 0x4dd036) {
    genphy_suspend();
  }
  else {
    phy_modify(param_1,0,0xfebf,0);
  }
  iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0x3d)
  ;
  if ((-1 < iVar1) &&
     (uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e),
     -1 < (int)uVar2)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                  uVar2 & 0xffffffbf);
  }
  iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0xb);
  if ((-1 < iVar1) &&
     (uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e),
     -1 < (int)uVar2)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                  uVar2 & 0xffffdbff);
  }
  return 0;
}



//------------------------------------------------------------
// qca83xx_resume @ 00101dec size=304
// signature: undefined qca83xx_resume(void)
// callers: []
//------------------------------------------------------------

uint qca83xx_resume(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  
  if ((*(byte *)(param_1 + 0x484) >> 5 & 1) == 0) {
    uVar1 = 0;
  }
  else {
    qca83xx_config_init();
    phy_modify(param_1,0,0,0x9000);
    lVar2 = ktime_get();
    usleep_range_state(0x30d5,50000,2);
    uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0);
    uVar4 = uVar1 & 0x80008000;
    if (uVar4 == 0x8000) {
      do {
        lVar3 = ktime_get();
        if (lVar2 + 600000000 < lVar3) {
          uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0);
          uVar4 = uVar1 & 0x80008000;
          break;
        }
        usleep_range_state(0x30d5,50000,2);
        Yield();
        uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0);
        uVar4 = uVar1 & 0x80008000;
      } while (uVar4 == 0x8000);
    }
    uVar5 = 0xffffff92;
    if (uVar4 != 0x8000) {
      uVar5 = 0;
    }
    if (-1 < (int)uVar1) {
      uVar1 = uVar5;
    }
    if (uVar1 == 0) {
      msleep(1);
    }
    else {
      _dev_err(param_1,"%s failed: %d\n","qca83xx_resume",uVar1);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// qca83xx_link_change_notify @ 00101f20 size=212
// signature: undefined qca83xx_link_change_notify(void)
// callers: []
//------------------------------------------------------------

void qca83xx_link_change_notify(long param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) != 0x4dd036) {
    if (*(int *)(param_1 + 0x48c) == 4) {
      if (*(int *)(param_1 + 0x498) != 100) {
        return;
      }
      iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0
                           );
      if (iVar1 < 0) {
        return;
      }
      uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
      if ((int)uVar2 < 0) {
        return;
      }
      uVar2 = uVar2 | 4;
    }
    else {
      iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0
                           );
      if (iVar1 < 0) {
        return;
      }
      uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
      if ((int)uVar2 < 0) {
        return;
      }
      uVar2 = uVar2 & 0xfffffffb;
    }
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,uVar2);
  }
  return;
}



//------------------------------------------------------------
// at803x_get_sset_count @ 00101ff8 size=8
// signature: undefined at803x_get_sset_count(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_get_sset_count(void)

{
  return 3;
}



//------------------------------------------------------------
// at803x_get_strings @ 00102004 size=96
// signature: undefined at803x_get_strings(void)
// callers: []
//------------------------------------------------------------

void at803x_get_strings(undefined8 param_1,long param_2)

{
  strscpy(param_2,"phy_idle_errors",0x10);
  strscpy(param_2 + 0x20,"phy_receive_errors",0x13);
  strscpy(param_2 + 0x40,"eee_wake_errors",0x10);
  return;
}



//------------------------------------------------------------
// at803x_get_stats @ 00102068 size=204
// signature: undefined at803x_get_stats(void)
// callers: []
//------------------------------------------------------------

void at803x_get_stats(long param_1,undefined8 param_2,long *param_3)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x528);
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),10);
  if ((int)uVar1 < 0) {
    lVar2 = -1;
  }
  else {
    lVar2 = *(long *)(lVar3 + 0x20) + (ulong)(uVar1 & 0xff);
    *(long *)(lVar3 + 0x20) = lVar2;
  }
  *param_3 = lVar2;
  lVar3 = *(long *)(param_1 + 0x528);
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x15);
  if ((int)uVar1 < 0) {
    lVar2 = -1;
  }
  else {
    lVar2 = *(long *)(lVar3 + 0x28) + (ulong)(uVar1 & 0xffff);
    *(long *)(lVar3 + 0x28) = lVar2;
  }
  param_3[1] = lVar2;
  lVar3 = *(long *)(param_1 + 0x528);
  uVar1 = phy_read_mmd(param_1,3,0x16);
  if ((int)uVar1 < 0) {
    lVar2 = -1;
  }
  else {
    lVar2 = *(long *)(lVar3 + 0x30) + (ulong)(uVar1 & 0xffff);
    *(long *)(lVar3 + 0x30) = lVar2;
  }
  param_3[2] = lVar2;
  return;
}



//------------------------------------------------------------
// qca808x_soft_reset @ 00102138 size=112
// signature: undefined qca808x_soft_reset(void)
// callers: []
//------------------------------------------------------------

void qca808x_soft_reset(long param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = genphy_soft_reset();
  if (((-1 < iVar1) &&
      (iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,
                             9), -1 < iVar1)) &&
     (uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e),
     -1 < (int)uVar2)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,uVar2 | 2);
  }
  return;
}



//------------------------------------------------------------
// qca808x_config_init @ 001021ac size=428
// signature: undefined qca808x_config_init(void)
// callers: []
//------------------------------------------------------------

void qca808x_config_init(long param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = phy_modify_mmd(param_1,3,0x8007,0x1f0,0x90);
  if (((iVar1 == 0) && (iVar1 = phy_write_mmd(param_1,3,0x8008,0x1c32), iVar1 == 0)) &&
     (iVar1 = genphy_c45_fast_retrain(param_1,1), iVar1 == 0)) {
    phy_write_mmd(param_1,7,0x901c,0);
    phy_write_mmd(param_1,1,0x8014,0x529);
    phy_write_mmd(param_1,1,0x800e,0x341);
    phy_write_mmd(param_1,1,0x801e,0x419);
    phy_write_mmd(param_1,1,0x8020,0x341);
    phy_write_mmd(param_1,3,0xa100,0x9203);
    phy_write_mmd(param_1,3,0xa105,0x8001);
    phy_write_mmd(param_1,3,0xa106,0x1111);
    phy_write_mmd(param_1,3,0xa103,0x1698);
    phy_write_mmd(param_1,3,0xa011,0x5f85);
    phy_write_mmd(param_1,3,0xa101,0x48ad);
    iVar1 = qca808x_phy_ms_random_seed_set(param_1);
    if (((iVar1 == 0) &&
        (iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),
                               0x1d,9), -1 < iVar1)) &&
       ((uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e
                             ), -1 < (int)uVar2 &&
        (iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),
                               0x1e,uVar2 | 2), iVar1 == 0)))) {
      at803x_debug_reg_mask(param_1,0x2c80,0xff,0xf0);
    }
  }
  return;
}



//------------------------------------------------------------
// qca808x_read_status @ 0010235c size=292
// signature: undefined qca808x_read_status(void)
// callers: []
//------------------------------------------------------------

undefined8 qca808x_read_status(long param_1)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  
  uVar3 = phy_read_mmd(param_1,7,0x21);
  if ((int)(uint)uVar3 < 0) {
    return uVar3;
  }
  *(ulong *)(param_1 + 0x4d0) =
       *(ulong *)(param_1 + 0x4d0) & 0xffff000000000000 |
       *(ulong *)(param_1 + 0x4d0) & 0x7fffffffffff | (ulong)(((uint)uVar3 & 0x20) >> 5) << 0x2f;
  uVar3 = genphy_read_status(param_1);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  uVar3 = at803x_read_specific_status(param_1);
  if ((int)uVar3 < 0) {
    return uVar3;
  }
  if ((*(byte *)(param_1 + 0x485) >> 5 & 1) != 0) {
    if (*(int *)(param_1 + 0x498) == 0x9c4) {
      uVar4 = 0x16;
    }
    else {
      uVar4 = 4;
    }
    *(undefined4 *)(param_1 + 0x494) = uVar4;
    return 0;
  }
  if (*(char *)(param_1 + 0x4ae) == '\x04') {
    iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,9);
    if (iVar1 < 0) {
      return 0;
    }
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar2 < 0) {
      return 0;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x390);
    uVar2 = uVar2 & 0xfffffffd;
  }
  else {
    qca808x_phy_ms_random_seed_set(param_1);
    iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,9);
    if (iVar1 < 0) {
      return 0;
    }
    uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if ((int)uVar2 < 0) {
      return 0;
    }
    uVar3 = *(undefined8 *)(param_1 + 0x390);
    uVar2 = uVar2 | 2;
  }
  mdiobus_write(uVar3,*(undefined4 *)(param_1 + 0x3d0),0x1e,uVar2);
  return 0;
}



//------------------------------------------------------------
// qca808x_cable_test_start @ 00102484 size=292
// signature: undefined qca808x_cable_test_start(void)
// callers: []
//------------------------------------------------------------

undefined8 qca808x_cable_test_start(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,0xb);
  if (-1 < (int)uVar1) {
    uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e);
    if (((-1 < (int)(uint)uVar1) &&
        (uVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),
                               0x1e,(uint)uVar1 & 0x7fff), -1 < (int)uVar1)) &&
       (uVar1 = phy_modify_changed(param_1,0x10,0x60,0), -1 < (int)uVar1)) {
      *(undefined8 *)(param_1 + 0x498) = 0x1000003e8;
      uVar1 = genphy_c45_pma_setup_forced(param_1);
      if ((-1 < (int)uVar1) && (uVar1 = genphy_setup_forced(param_1), -1 < (int)uVar1)) {
        phy_write_mmd(param_1,3,0x8074,0xc040);
        phy_write_mmd(param_1,3,0x8076,0xc040);
        phy_write_mmd(param_1,3,0x8077,0xa060);
        phy_write_mmd(param_1,3,0x8078,0xc050);
        phy_write_mmd(param_1,3,0x807a,0xc060);
        phy_write_mmd(param_1,3,0x807e,0xb060);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// qca808x_cable_test_get_status @ 001025ac size=576
// signature: undefined qca808x_cable_test_get_status(void)
// callers: []
//------------------------------------------------------------

uint qca808x_cable_test_get_status(long param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined4 uVar8;
  
  *param_2 = 0;
  uVar8 = 0xffffa400;
  if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) != 0x4dd101) {
    uVar8 = 1;
  }
  uVar5 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x16,uVar8
                       );
  if (uVar5 == 0) {
    uVar5 = at803x_cdt_wait_for_completion(param_1);
    if (uVar5 == 0) {
      uVar5 = phy_read_mmd(param_1,3,0x8064);
      if (-1 < (int)uVar5) {
        uVar2 = uVar5 >> 0xc & 0xf;
        if ((uVar5 >> 0xc & 0xc) != 0) {
          uVar2 = 0;
        }
        uVar3 = uVar5 >> 8 & 0xf;
        uVar4 = uVar5 >> 4 & 0xf;
        uVar1 = uVar5 & 0xf;
        ethnl_cable_test_result(param_1,0,uVar2);
        if ((uVar5 >> 8 & 0xc) != 0) {
          uVar3 = 0;
        }
        ethnl_cable_test_result(param_1,1,uVar3);
        if ((uVar5 >> 4 & 0xc) != 0) {
          uVar4 = 0;
        }
        ethnl_cable_test_result(param_1,2,uVar4);
        if ((uVar5 & 0xc) != 0) {
          uVar1 = 0;
        }
        ethnl_cable_test_result(param_1,3,uVar1);
        if ((uVar5 & 0xe000) == 0x2000) {
          uVar6 = phy_read_mmd(param_1,3,0x8065);
          uVar7 = uVar6 & 0xffffffff;
          if (-1 < (int)(uint)uVar6) {
            uVar7 = (ulong)(((uint)uVar6 & 0xff) * 0x338) / 10;
          }
          ethnl_cable_test_fault_length(param_1,0,uVar7);
        }
        if ((uVar5 & 0xe00) == 0x200) {
          uVar6 = phy_read_mmd(param_1,3,0x8066);
          uVar7 = uVar6 & 0xffffffff;
          if (-1 < (int)(uint)uVar6) {
            uVar7 = (ulong)(((uint)uVar6 & 0xff) * 0x338) / 10;
          }
          ethnl_cable_test_fault_length(param_1,1,uVar7);
        }
        if ((uVar5 & 0xe0) == 0x20) {
          uVar6 = phy_read_mmd(param_1,3,0x8067);
          uVar7 = uVar6 & 0xffffffff;
          if (-1 < (int)(uint)uVar6) {
            uVar7 = (ulong)(((uint)uVar6 & 0xff) * 0x338) / 10;
          }
          ethnl_cable_test_fault_length(param_1,2,uVar7);
        }
        if ((uVar5 & 0xe) == 2) {
          uVar6 = phy_read_mmd(param_1,3,0x8068);
          uVar7 = uVar6 & 0xffffffff;
          if (-1 < (int)(uint)uVar6) {
            uVar7 = (ulong)(((uint)uVar6 & 0xff) * 0x338) / 10;
          }
          ethnl_cable_test_fault_length(param_1,3,uVar7);
        }
        uVar5 = 0;
        *param_2 = 1;
      }
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// at803x_debug_reg_mask @ 001027ec size=128
// signature: undefined at803x_debug_reg_mask(void)
// callers: [qca808x_config_init]
//------------------------------------------------------------

void at803x_debug_reg_mask(long param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,
                        param_2);
  if ((-1 < iVar1) &&
     (uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e),
     -1 < (int)uVar2)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                  uVar2 & (~param_3 | 0xffff0000) | param_4);
  }
  return;
}



//------------------------------------------------------------
// at803x_rgmii_reg_set_voltage_sel @ 00102870 size=144
// signature: undefined at803x_rgmii_reg_set_voltage_sel(void)
// callers: []
//------------------------------------------------------------

void at803x_rgmii_reg_set_voltage_sel(undefined8 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = rdev_get_drvdata();
  iVar1 = mdiobus_write(*(undefined8 *)(lVar3 + 0x390),*(undefined4 *)(lVar3 + 0x3d0),0x1d,0x1f);
  if (param_2 == 0) {
    if (iVar1 < 0) {
      return;
    }
    uVar2 = mdiobus_read(*(undefined8 *)(lVar3 + 0x390),*(undefined4 *)(lVar3 + 0x3d0),0x1e);
    if ((int)uVar2 < 0) {
      return;
    }
    uVar2 = uVar2 & 0xfffffff7;
  }
  else {
    if (iVar1 < 0) {
      return;
    }
    uVar2 = mdiobus_read(*(undefined8 *)(lVar3 + 0x390),*(undefined4 *)(lVar3 + 0x3d0),0x1e);
    if ((int)uVar2 < 0) {
      return;
    }
    uVar2 = uVar2 | 8;
  }
  mdiobus_write(*(undefined8 *)(lVar3 + 0x390),*(undefined4 *)(lVar3 + 0x3d0),0x1e,uVar2);
  return;
}



//------------------------------------------------------------
// at803x_rgmii_reg_get_voltage_sel @ 00102904 size=92
// signature: undefined at803x_rgmii_reg_get_voltage_sel(void)
// callers: []
//------------------------------------------------------------

uint at803x_rgmii_reg_get_voltage_sel(void)

{
  uint uVar1;
  long lVar2;
  
  lVar2 = rdev_get_drvdata();
  uVar1 = mdiobus_write(*(undefined8 *)(lVar2 + 0x390),*(undefined4 *)(lVar2 + 0x3d0),0x1d,0x1f);
  if (-1 < (int)uVar1) {
    uVar1 = mdiobus_read(*(undefined8 *)(lVar2 + 0x390),*(undefined4 *)(lVar2 + 0x3d0),0x1e);
  }
  if (-1 < (int)uVar1) {
    uVar1 = uVar1 >> 3 & 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// at803x_sfp_insert @ 00102964 size=160
// signature: undefined at803x_sfp_insert(void)
// callers: []
//------------------------------------------------------------

undefined8 at803x_sfp_insert(undefined8 param_1)

{
  long lVar1;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0x20000006060;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  __bitmap_and(&local_48,&local_38,&local_48,0x5d);
  lVar1 = _find_first_bit(&local_48,0x5d);
  if (lVar1 == 0x5d) {
    _dev_err(param_1,"incompatible SFP module inserted\n");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// at803x_read_specific_status @ 00102a04 size=248
// signature: undefined at803x_read_specific_status(void)
// callers: [at803x_read_status, qca808x_read_status]
//------------------------------------------------------------

uint at803x_read_specific_status(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  
  uVar2 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x11);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if ((uVar2 >> 0xb & 1) != 0) {
    uVar3 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x10);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    uVar1 = uVar2 >> 7 & 7;
    if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) != 0x4dd101) {
      uVar1 = uVar2 >> 0xe & 3;
    }
    if ((uVar1 < 5) && ((0x17U >> (ulong)uVar1 & 1) != 0)) {
      *(undefined4 *)(param_1 + 0x498) = *(undefined4 *)(&DAT_00104cd8 + (ulong)uVar1 * 4);
    }
    uVar5 = 1;
    uVar4 = 1;
    if ((uVar2 & 0x40) != 0) {
      uVar4 = 2;
    }
    uVar3 = uVar3 >> 5 & 3;
    *(uint *)(param_1 + 0x49c) = uVar2 >> 0xd & 1;
    *(undefined1 *)(param_1 + 0x638) = uVar4;
    if (uVar3 != 0) {
      if (uVar3 == 3) {
        uVar5 = 3;
      }
      else {
        if (uVar3 != 1) {
          return 0;
        }
        uVar5 = 2;
      }
    }
    *(undefined1 *)(param_1 + 0x639) = uVar5;
  }
  return 0;
}



//------------------------------------------------------------
// at803x_cdt_wait_for_completion @ 00102afc size=284
// signature: undefined at803x_cdt_wait_for_completion(void)
// callers: [at803x_cable_test_get_status, qca808x_cable_test_get_status]
//------------------------------------------------------------

uint at803x_cdt_wait_for_completion(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0x8000;
  if (*(int *)(*(long *)(param_1 + 0x3f0) + 0xb8) != 0x4dd101) {
    uVar4 = 1;
  }
  lVar2 = ktime_get();
  usleep_range_state(0x1d4d,30000,2);
  uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x16);
  uVar5 = uVar1 & uVar4;
  if ((-1 < (int)uVar1) && (uVar5 != 0)) {
    while (lVar3 = ktime_get(), lVar3 <= lVar2 + 100000000) {
      usleep_range_state(0x1d4d,30000,2);
      Yield();
      uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x16);
      uVar5 = uVar1 & uVar4;
      if (((int)uVar1 < 0) || (uVar5 == 0)) goto LAB_00102bc0;
    }
    uVar1 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x16);
    uVar5 = uVar1 & uVar4;
  }
LAB_00102bc0:
  uVar4 = 0;
  if (uVar5 != 0 && -1 < (int)uVar1) {
    uVar4 = 0xffffff92;
  }
  if (((int)uVar1 < 0) || (uVar1 = uVar4, uVar5 != 0)) {
    uVar4 = uVar1;
    _dev_err(param_1,"%s failed: %d\n","at803x_cdt_wait_for_completion",uVar4);
  }
  return uVar4;
}



//------------------------------------------------------------
// qca808x_phy_ms_random_seed_set @ 00102c18 size=148
// signature: undefined qca808x_phy_ms_random_seed_set(void)
// callers: [qca808x_config_init, qca808x_read_status]
//------------------------------------------------------------

void qca808x_phy_ms_random_seed_set(long param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  do {
    uVar1 = get_random_u8();
    uVar1 = (uVar1 & 0xff) * 0x32;
  } while ((uVar1 & 0xfe) < 6);
  iVar2 = mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1d,9);
  if ((-1 < iVar2) &&
     (uVar3 = mdiobus_read(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e),
     -1 < (int)uVar3)) {
    mdiobus_write(*(undefined8 *)(param_1 + 0x390),*(undefined4 *)(param_1 + 0x3d0),0x1e,
                  uVar3 & 0xffffe003 | uVar1 >> 6 & 0xfc);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00102cb0 size=48
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  phy_drivers_register(at803x_driver,10,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102ce4 size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  phy_drivers_unregister(at803x_driver,10);
  return;
}



//------------------------------------------------------------
// phy_drivers_register @ 00106000 size=1
// signature: undefined phy_drivers_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_drivers_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_drivers_unregister @ 00106008 size=1
// signature: undefined phy_drivers_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_drivers_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00106010 size=1
// signature: undefined mutex_lock(void)
// callers: [at803x_config_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __phy_modify @ 00106018 size=1
// signature: undefined __phy_modify(void)
// callers: [at803x_write_page, at803x_config_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __phy_modify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00106020 size=1
// signature: undefined mutex_unlock(void)
// callers: [at803x_config_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mdiobus_write @ 00106028 size=1
// signature: undefined mdiobus_write(void)
// callers: [at803x_config_intr, at803x_cable_test_get_status, at803x_link_change_notify, qca83xx_link_change_notify, at803x_debug_reg_mask, qca808x_read_status, at803x_config_init, at803x_rgmii_reg_set_voltage_sel, at803x_cable_test_start, qca83xx_config_init, qca808x_soft_reset, qca808x_config_init, qca83xx_suspend, qca808x_cable_test_start, at803x_rgmii_reg_get_voltage_sel, qca808x_phy_ms_random_seed_set, qca808x_cable_test_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mdiobus_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mdiobus_read @ 00106030 size=1
// signature: undefined mdiobus_read(void)
// callers: [at803x_config_intr, at803x_set_wol, at803x_cable_test_get_status, at803x_config_init, at803x_read_specific_status, at803x_get_stats, qca808x_soft_reset, qca808x_config_init, qca83xx_suspend, qca808x_cable_test_start, at803x_rgmii_reg_get_voltage_sel, at803x_probe, at803x_get_tunable, at803x_handle_interrupt, at803x_link_change_notify, qca83xx_link_change_notify, qca83xx_resume, at803x_debug_reg_mask, qca808x_read_status, at803x_cdt_wait_for_completion, at803x_rgmii_reg_set_voltage_sel, qca83xx_config_init, at803x_suspend, at803x_get_wol, qca808x_phy_ms_random_seed_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mdiobus_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_modify_mmd @ 00106038 size=1
// signature: undefined phy_modify_mmd(void)
// callers: [at803x_probe, at803x_set_wol, qca808x_config_init, at803x_config_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_modify_mmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_modify @ 00106040 size=1
// signature: undefined phy_modify(void)
// callers: [at803x_set_wol, qca83xx_config_init, at803x_resume, qca83xx_suspend, qca83xx_resume, at803x_suspend, at803x_config_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_modify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00106048 size=1
// signature: undefined devm_kmalloc(void)
// callers: [at803x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00106050 size=1
// signature: undefined of_find_property(void)
// callers: [at803x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00106058 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [at803x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_register @ 00106060 size=1
// signature: undefined devm_regulator_register(void)
// callers: [at803x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_enable_optional @ 00106068 size=1
// signature: undefined devm_regulator_get_enable_optional(void)
// callers: [at803x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_enable_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_sfp_probe @ 00106070 size=1
// signature: undefined phy_sfp_probe(void)
// callers: [at803x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_sfp_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106078 size=1
// signature: undefined _dev_err(void)
// callers: [at803x_cdt_wait_for_completion, at803x_probe, qca83xx_resume, at803x_sfp_insert]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [at803x_probe, at803x_cable_test_get_status, at803x_sfp_insert]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_modify_changed @ 00106088 size=1
// signature: undefined phy_modify_changed(void)
// callers: [at803x_config_aneg, qca808x_cable_test_start, at803x_set_tunable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_modify_changed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_soft_reset @ 00106090 size=1
// signature: undefined genphy_soft_reset(void)
// callers: [qca808x_soft_reset, at803x_config_aneg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_soft_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_c37_config_aneg @ 00106098 size=1
// signature: undefined genphy_c37_config_aneg(void)
// callers: [at803x_config_aneg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_c37_config_aneg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_c45_pma_setup_forced @ 001060a0 size=1
// signature: undefined genphy_c45_pma_setup_forced(void)
// callers: [at803x_config_aneg, qca808x_cable_test_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_c45_pma_setup_forced(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_modify_mmd_changed @ 001060a8 size=1
// signature: undefined phy_modify_mmd_changed(void)
// callers: [at803x_config_aneg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_modify_mmd_changed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __genphy_config_aneg @ 001060b0 size=1
// signature: undefined __genphy_config_aneg(void)
// callers: [at803x_config_aneg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __genphy_config_aneg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_c37_read_status @ 001060b8 size=1
// signature: undefined genphy_c37_read_status(void)
// callers: [at803x_read_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_c37_read_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_update_link @ 001060c0 size=1
// signature: undefined genphy_update_link(void)
// callers: [at803x_read_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_update_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_read_lpa @ 001060c8 size=1
// signature: undefined genphy_read_lpa(void)
// callers: [at803x_read_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_read_lpa(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_resolve_aneg_pause @ 001060d0 size=1
// signature: undefined phy_resolve_aneg_pause(void)
// callers: [at803x_read_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_resolve_aneg_pause(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_trigger_machine @ 001060d8 size=1
// signature: undefined phy_trigger_machine(void)
// callers: [at803x_set_wol, at803x_handle_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_trigger_machine(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_error @ 001060e0 size=1
// signature: undefined phy_error(void)
// callers: [at803x_handle_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_error(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_write_mmd @ 001060e8 size=1
// signature: undefined phy_write_mmd(void)
// callers: [at803x_set_wol, qca83xx_config_init, qca808x_config_init, qca808x_cable_test_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_write_mmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ethnl_cable_test_result @ 001060f8 size=1
// signature: undefined ethnl_cable_test_result(void)
// callers: [at803x_cable_test_get_status, qca808x_cable_test_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ethnl_cable_test_result(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ethnl_cable_test_fault_length @ 00106100 size=1
// signature: undefined ethnl_cable_test_fault_length(void)
// callers: [at803x_cable_test_get_status, qca808x_cable_test_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ethnl_cable_test_fault_length(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00106108 size=1
// signature: undefined msleep(void)
// callers: [at803x_cable_test_get_status, at803x_link_change_notify, qca83xx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_init_hw @ 00106110 size=1
// signature: undefined phy_init_hw(void)
// callers: [at803x_set_tunable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_init_hw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mdio_device_reset @ 00106118 size=1
// signature: undefined mdio_device_reset(void)
// callers: [at803x_link_change_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mdio_device_reset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_read_abilities @ 00106120 size=1
// signature: undefined genphy_read_abilities(void)
// callers: [at803x_get_features]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_read_abilities(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// phy_read_mmd @ 00106128 size=1
// signature: undefined phy_read_mmd(void)
// callers: [at803x_get_stats, qca808x_read_status, at803x_get_features, qca808x_cable_test_get_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void phy_read_mmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mdiobus_read @ 00106130 size=1
// signature: undefined __mdiobus_read(void)
// callers: [at803x_read_page]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mdiobus_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_suspend @ 00106138 size=1
// signature: undefined genphy_suspend(void)
// callers: [qca83xx_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00106140 size=1
// signature: undefined ktime_get(void)
// callers: [at803x_cdt_wait_for_completion, qca83xx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00106148 size=1
// signature: undefined usleep_range_state(void)
// callers: [at803x_cdt_wait_for_completion, qca83xx_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00106150 size=1
// signature: undefined strscpy(void)
// callers: [at803x_get_strings]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_c45_fast_retrain @ 00106158 size=1
// signature: undefined genphy_c45_fast_retrain(void)
// callers: [qca808x_config_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_c45_fast_retrain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_read_status @ 00106160 size=1
// signature: undefined genphy_read_status(void)
// callers: [qca808x_read_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_read_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genphy_setup_forced @ 00106168 size=1
// signature: undefined genphy_setup_forced(void)
// callers: [qca808x_cable_test_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genphy_setup_forced(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rdev_get_drvdata @ 00106170 size=1
// signature: undefined rdev_get_drvdata(void)
// callers: [at803x_rgmii_reg_set_voltage_sel, at803x_rgmii_reg_get_voltage_sel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rdev_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_and @ 00106178 size=1
// signature: undefined __bitmap_and(void)
// callers: [at803x_sfp_insert]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_and(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00106180 size=1
// signature: undefined _find_first_bit(void)
// callers: [at803x_sfp_insert]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_u8 @ 00106188 size=1
// signature: undefined get_random_u8(void)
// callers: [qca808x_phy_ms_random_seed_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_u8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



