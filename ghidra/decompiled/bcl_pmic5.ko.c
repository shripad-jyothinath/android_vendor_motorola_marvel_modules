// Decompiled by Ghidra 12.2
// Program: bcl_pmic5.ko
// Image base: 00100000

//------------------------------------------------------------
// get_bpm_stats @ 0010068c size=636
// signature: undefined get_bpm_stats(void)
// callers: [bcl_handle_irq, bpm_stats_show]
//------------------------------------------------------------

int get_bpm_stats(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  mutex_lock(param_1 + 0x28);
  if (param_1 == 0) {
    _printk(&DAT_00103aa4,"bcl_pmic5","bcl_write_register");
    iVar2 = -0x16;
  }
  else {
    iVar3 = *(ushort *)(param_1 + 0x10) + 0xa0;
    iVar2 = regmap_write(*(undefined8 *)(param_1 + 8),iVar3,0x81);
    if (iVar2 < 0) {
      _printk(&DAT_001039ff,"bcl_pmic5","bcl_write_register",iVar3,0x81,iVar2);
    }
    else if (iVar2 == 0) {
      iVar2 = regmap_read(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x10) + 0xaa,param_2);
      if (iVar2 < 0) {
        iVar3 = *(ushort *)(param_1 + 0x10) + 0xaa;
      }
      else {
        if (iVar2 != 0) goto LAB_001008c4;
        iVar2 = regmap_read(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x10) + 0xab,
                            param_2 + 4);
        if (iVar2 < 0) {
          iVar3 = *(ushort *)(param_1 + 0x10) + 0xab;
        }
        else {
          if (iVar2 != 0) goto LAB_001008c4;
          iVar2 = regmap_read(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x10) + 0xac,
                              param_2 + 8);
          if (-1 < iVar2) {
            if (iVar2 == 0) {
              iVar2 = bcl_read_multi_register(param_1,0xa2,&local_5c);
              if (iVar2 == 0) {
                *(uint *)(param_2 + 0xc) = (uint)((short)local_5c * 0x5968c) / 1000000;
                iVar2 = bcl_read_multi_register(param_1,0xa4,&local_5c);
                if (iVar2 == 0) {
                  *(uint *)(param_2 + 0x10) = (uint)((short)local_5c * 0x2f84d) / 1000000;
                  iVar2 = bcl_read_multi_register(param_1,0xa6,&local_5c);
                  if (iVar2 == 0) {
                    *(uint *)(param_2 + 0x14) = (uint)((short)local_5c * 0x2f84d) / 1000000;
                    iVar2 = bcl_read_multi_register(param_1,0xa8,&local_5c);
                    if (iVar2 == 0) {
                      *(uint *)(param_2 + 0x18) = (uint)((short)local_5c * 0x5968c) / 1000000;
                      iVar2 = bcl_write_register(param_1,0xa0,0x80);
                    }
                  }
                }
              }
            }
            goto LAB_001008c4;
          }
          iVar3 = *(ushort *)(param_1 + 0x10) + 0xac;
        }
      }
      _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",iVar3,iVar2);
    }
  }
LAB_001008c4:
  mutex_unlock(param_1 + 0x28);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// bcl_write_register @ 00100908 size=164
// signature: undefined bcl_write_register(void)
// callers: [get_bpm_stats]
//------------------------------------------------------------

int bcl_write_register(long param_1,uint param_2,undefined1 param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    _printk(&DAT_00103aa4,"bcl_pmic5","bcl_write_register");
    iVar2 = -0x16;
  }
  else {
    iVar1 = (uint)*(ushort *)(param_1 + 0x10) + (param_2 & 0xffff);
    iVar2 = regmap_write(*(undefined8 *)(param_1 + 8),iVar1,param_3);
    if (iVar2 < 0) {
      _printk(&DAT_001039ff,"bcl_pmic5","bcl_write_register",iVar1,param_3,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// bcl_read_multi_register @ 001009ac size=168
// signature: undefined bcl_read_multi_register(void)
// callers: [get_bpm_stats]
//------------------------------------------------------------

int bcl_read_multi_register(long param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_00103aa4,"bcl_pmic5","bcl_read_multi_register");
    iVar1 = -0x16;
  }
  else {
    iVar1 = regmap_bulk_read(*(undefined8 *)(param_1 + 8),
                             (uint)*(ushort *)(param_1 + 0x10) + (param_2 & 0xffff),param_3,2);
    if (iVar1 < 0) {
      _printk(&DAT_00103663,"bcl_pmic5","bcl_read_multi_register",
              (uint)*(ushort *)(param_1 + 0x10) + (param_2 & 0xffff),2,iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// bcl_probe @ 00100a58 size=2284
// signature: undefined bcl_probe(void)
// callers: []
//------------------------------------------------------------

ulong bcl_probe(long param_1)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  undefined4 *puVar8;
  void *pvVar9;
  ulong uVar10;
  void *pvVar11;
  long lVar12;
  char *pcVar13;
  undefined1 uVar14;
  undefined4 uVar15;
  uint local_94;
  size_t local_90;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar12 = sp_el0;
  local_58 = *(long *)(lVar12 + 0x638);
  lVar12 = param_1 + 0x10;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if (1 < (int)bcl_device_ct) {
    pcVar13 = "Max bcl peripheral supported already.\n";
LAB_00100ed0:
    _dev_err(lVar12,pcVar13);
    pvVar11 = (void *)0xffffffea;
    goto LAB_00101288;
  }
  plVar5 = (long *)devm_kmalloc(lVar12,0xd20,0xdc0);
  if (1 < bcl_device_ct) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101344);
    (*pcVar2)();
  }
  *(long **)(bcl_devices + (ulong)bcl_device_ct * 8) = plVar5;
  if (plVar5 == (long *)0x0) {
    pvVar11 = (void *)0xfffffff4;
    goto LAB_00101288;
  }
  __mutex_init(plVar5 + 5,"&bcl_perph->stats_lock",&bcl_probe___key);
  uVar6 = *(undefined8 *)(param_1 + 0x70);
  *plVar5 = lVar12;
  lVar7 = dev_get_regmap(uVar6,0);
  plVar5[1] = lVar7;
  if (lVar7 == 0) {
    pcVar13 = "Couldn\'t get parent\'s regmap\n";
    goto LAB_00100ed0;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x2f8);
  bcl_device_ct = bcl_device_ct + 1;
  puVar8 = (undefined4 *)__of_get_address(uVar6,0,0xffffffff,0,0);
  if (puVar8 == (undefined4 *)0x0) {
    _dev_err(lVar12,"No fg_bcl registers found\n");
    pvVar11 = (void *)0xffffffed;
  }
  else {
    *(ushort *)(plVar5 + 2) =
         (ushort)(byte)((uint)*puVar8 >> 0x18) | (ushort)((uint)*puVar8 >> 8) & 0xff00;
    lVar7 = of_find_property(uVar6,"qcom,ibat-use-qg-adc-5a",0);
    *(bool *)((long)plVar5 + 0x21) = lVar7 != 0;
    lVar7 = of_find_property(uVar6,"qcom,pmic7-threshold",0);
    *(bool *)((long)plVar5 + 0x22) = lVar7 != 0;
    lVar7 = of_find_property(uVar6,"qcom,ibat-ccm-hw-support",0);
    uVar6 = *(undefined8 *)(param_1 + 0x2f8);
    local_90 = 0;
    local_88 = 0;
    *(bool *)(plVar5 + 4) = lVar7 != 0;
    local_94 = 0;
    iVar3 = of_property_read_string(uVar6,"nvmem-cell-names",&local_88);
    if (iVar3 == 0) {
      pvVar9 = (void *)nvmem_cell_get(lVar12,local_88);
      if (pvVar9 < (void *)0xfffffffffffff001) {
        pvVar11 = (void *)nvmem_cell_read(pvVar9,&local_90);
        nvmem_cell_put(pvVar9);
        if ((pvVar11 != (void *)0x0) && (pvVar11 < (void *)0xfffffffffffff001)) {
          if (local_90 - 5 < 0xfffffffffffffffb || local_90 == 0) {
            _dev_err(lVar12,"nvmem cell length out of range %d\n");
            kfree(pvVar11);
          }
          else {
            memcpy(&local_94,pvVar11,local_90);
            kfree(pvVar11);
            if (local_94 < 3) {
              uVar15 = *(undefined4 *)(bcl_ibat_ext_ranges + (ulong)local_94 * 4);
              goto LAB_00100c48;
            }
            _dev_err(lVar12,"invalid BCL ibat scaling factor %d\n");
          }
          pvVar11 = (void *)0xffffffea;
          goto LAB_00101094;
        }
        _dev_err(lVar12,"failed to read nvmem cell %s\n",local_88);
        iVar3 = (int)pvVar11;
      }
      else {
        _dev_err(lVar12,"failed to get nvmem cell %s\n",local_88);
        iVar3 = (int)pvVar9;
        pvVar11 = pvVar9;
      }
      if (iVar3 != 0) goto LAB_00101094;
    }
    else {
      uVar15 = 10;
LAB_00100c48:
      *(undefined4 *)((long)plVar5 + 0x24) = uVar15;
    }
    local_88 = local_88 & 0xffffffff00000000;
    uVar4 = regmap_read(plVar5[1],*(ushort *)(plVar5 + 2) + 1,&local_88);
    if ((int)uVar4 < 0) {
      pvVar11 = (void *)(ulong)uVar4;
      iVar3 = 1;
    }
    else {
      *(char *)((long)plVar5 + 0x12) = (char)local_88;
      iVar3 = regmap_read(plVar5[1],(short)plVar5[2],&local_88);
      if (iVar3 < 0) {
        _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",(short)plVar5[2],iVar3);
      }
      else {
        *(char *)((long)plVar5 + 0x13) = (char)local_88;
      }
      if (*(byte *)((long)plVar5 + 0x12) < 4) {
        uVar14 = 0;
        *(undefined1 *)((long)plVar5 + 0x15) = 0;
      }
      else {
        uVar4 = regmap_read(plVar5[1],*(ushort *)(plVar5 + 2) + 0xe,&local_88);
        uVar10 = local_88;
        if ((int)uVar4 < 0) {
          pvVar11 = (void *)(ulong)uVar4;
          iVar3 = 0xe;
          goto LAB_00100fa8;
        }
        local_88 = local_88 & 0xffffffff00000000;
        *(char *)((long)plVar5 + 0x15) = (char)uVar10;
        iVar3 = regmap_read(plVar5[1],*(ushort *)(plVar5 + 2) + 0xf,&local_88);
        if (iVar3 < 0) {
          _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",*(ushort *)(plVar5 + 2) + 0xf,iVar3)
          ;
        }
        uVar14 = (undefined1)local_88;
      }
      *(undefined1 *)((long)plVar5 + 0x16) = uVar14;
      uVar4 = regmap_read(plVar5[1],*(ushort *)(plVar5 + 2) + 3,&local_88);
      if (-1 < (int)uVar4) {
        *(char *)((long)plVar5 + 0x14) = (char)local_88;
        local_88 = local_88 & 0xffffffff00000000;
        __mutex_init(plVar5 + 0x46,"&vbat->state_trans_lock",&bcl_vbat_init___key);
        plVar5[0x5e] = (long)plVar5;
        *(undefined4 *)(plVar5 + 0x43) = 0;
        *(undefined1 *)(plVar5 + 0x4c) = 0;
        plVar5[0x5d] = 0;
        if (*(byte *)((long)plVar5 + 0x12) < 4) {
          iVar3 = regmap_read(plVar5[1],*(ushort *)(plVar5 + 2) + 0x72,&local_88);
          if (iVar3 < 0) {
            _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",*(ushort *)(plVar5 + 2) + 0x72);
          }
          else if ((iVar3 == 0) && ((int)local_88 != 0)) goto LAB_00100d74;
        }
        else if ((*(byte *)((long)plVar5 + 0x15) & 1) != 0) {
LAB_00100d74:
          uVar10 = thermal_zone_device_register
                             (&DAT_00103552,3,0,plVar5 + 0x43,vbat_tzd_ops,vbat_tzp,0,0);
          plVar5[0x5d] = uVar10;
          if (uVar10 < 0xfffffffffffff001) {
            iVar3 = thermal_zone_device_enable();
            if (iVar3 == 0) goto LAB_00100dc4;
            thermal_zone_device_unregister(plVar5[0x5d]);
          }
          plVar5[0x5d] = 0;
        }
LAB_00100dc4:
        local_94 = 0;
        local_90 = 0;
        local_88 = 0;
        iVar3 = of_property_read_string
                          (*(undefined8 *)(param_1 + 0x2f8),"nvmem-cell-names",&local_88);
        if (iVar3 != 0) goto LAB_001010e4;
        uVar10 = nvmem_cell_get(lVar12,local_88);
        if (uVar10 < 0xfffffffffffff001) {
          pvVar11 = (void *)nvmem_cell_read(uVar10,&local_90);
          nvmem_cell_put(uVar10);
          if ((pvVar11 == (void *)0x0) || ((void *)0xfffffffffffff000 < pvVar11)) {
            pcVar13 = "failed to read nvmem cell %s\n";
            goto LAB_001010c0;
          }
          if (local_90 - 5 < 0xfffffffffffffffb || local_90 == 0) {
            _dev_err(lVar12,"nvmem cell length out of range %d\n");
            kfree(pvVar11);
            goto LAB_001010e4;
          }
          memcpy(&local_94,pvVar11,local_90);
          kfree(pvVar11);
          if (local_94 != 1) goto LAB_001010e4;
          __mutex_init(plVar5 + 0xee,"&ibat->state_trans_lock",&bcl_ibat_init___key);
          plVar5[0x106] = (long)plVar5;
          *(undefined4 *)(plVar5 + 0xeb) = 0;
          *(undefined1 *)(plVar5 + 0xf4) = 0;
          *(undefined4 *)((long)plVar5 + 0x7a4) = 8;
          plVar5[0xf7] = (long)bcl_read_ibat;
          plVar5[0xf8] = (long)bcl_set_ibat;
          uVar10 = devm_thermal_of_zone_register(lVar12,8,plVar5 + 0xeb,plVar5 + 0xf5);
          plVar5[0x105] = uVar10;
          if (uVar10 < 0xfffffffffffff001) {
            thermal_zone_device_update(uVar10,5);
          }
          else {
            plVar5[0x105] = 0;
          }
          __mutex_init(plVar5 + 0x10a,"&ibat->state_trans_lock",&bcl_ibat_init___key);
          plVar5[0x122] = (long)plVar5;
          *(undefined4 *)(plVar5 + 0x107) = 0;
          *(undefined1 *)(plVar5 + 0x110) = 0;
          *(undefined4 *)((long)plVar5 + 0x884) = 9;
          plVar5[0x113] = (long)bcl_read_ibat;
          plVar5[0x114] = (long)bcl_set_ibat;
          uVar10 = devm_thermal_of_zone_register(lVar12,9,plVar5 + 0x107,plVar5 + 0x111);
          plVar5[0x121] = uVar10;
          if (uVar10 < 0xfffffffffffff001) goto LAB_001011ac;
          plVar5[0x121] = 0;
        }
        else {
          pcVar13 = "failed to get nvmem cell %s\n";
LAB_001010c0:
          _dev_err(lVar12,pcVar13,local_88);
LAB_001010e4:
          __mutex_init(plVar5 + 0xe,"&ibat->state_trans_lock",&bcl_ibat_init___key);
          *(undefined4 *)((long)plVar5 + 0xa4) = 0;
          plVar5[0x26] = (long)plVar5;
          *(undefined1 *)(plVar5 + 0x14) = 0;
          *(undefined4 *)(plVar5 + 0xb) = 0;
          plVar5[0x17] = (long)bcl_read_ibat;
          plVar5[0x18] = (long)bcl_set_ibat;
          uVar10 = devm_thermal_of_zone_register(lVar12,0,plVar5 + 0xb,plVar5 + 0x15);
          plVar5[0x25] = uVar10;
          if (uVar10 < 0xfffffffffffff001) {
            thermal_zone_device_update(uVar10,5);
          }
          else {
            plVar5[0x25] = 0;
          }
          __mutex_init(plVar5 + 0x2a,"&ibat->state_trans_lock",&bcl_ibat_init___key);
          plVar5[0x42] = (long)plVar5;
          *(undefined4 *)(plVar5 + 0x27) = 0;
          *(undefined1 *)(plVar5 + 0x30) = 0;
          *(undefined4 *)((long)plVar5 + 0x184) = 1;
          plVar5[0x33] = (long)bcl_read_ibat;
          plVar5[0x34] = (long)bcl_set_ibat;
          uVar10 = devm_thermal_of_zone_register(lVar12,1,plVar5 + 0x27,plVar5 + 0x31);
          plVar5[0x41] = uVar10;
          if (uVar10 < 0xfffffffffffff001) {
LAB_001011ac:
            thermal_zone_device_update(uVar10,5);
          }
          else {
            plVar5[0x41] = 0;
          }
        }
        bcl_lvl_init(param_1,5,1,plVar5);
        bcl_lvl_init(param_1,6,2,plVar5);
        bcl_lvl_init(param_1,7,4,plVar5);
        uVar1 = *(ushort *)(plVar5 + 2);
        iVar3 = regmap_write(plVar5[1],uVar1 + 0x46,0x80);
        if (iVar3 < 0) {
          _printk(&DAT_001039ff,"bcl_pmic5","bcl_write_register",uVar1 + 0x46,0x80,iVar3);
        }
        uVar1 = *(ushort *)(plVar5 + 2);
        iVar3 = regmap_write(plVar5[1],uVar1 + 0xa0,0x80);
        if (iVar3 < 0) {
          _printk(&DAT_001039ff,"bcl_pmic5","bcl_write_register",uVar1 + 0xa0,0x80);
        }
        else if (iVar3 == 0) {
          *(undefined1 *)((long)plVar5 + 0x17) = 1;
        }
        uVar1 = *(ushort *)(plVar5 + 2);
        iVar3 = bcl_device_ct - 1;
        *(long **)(param_1 + 0xa8) = plVar5;
        snprintf((char *)&local_80,0x28,"bcl_0x%04x_%d",(uint)uVar1,iVar3);
        lVar12 = ipc_log_context_create(10,&local_80,0);
        plVar5[3] = lVar12;
        if (lVar12 == 0) {
          _printk(&DAT_0010378f,"bcl_pmic5","bcl_probe","bcl_probe",&local_80);
        }
        bcl_stats_init(&local_80,plVar5,3);
        pvVar11 = (void *)0x0;
        goto LAB_00101288;
      }
      pvVar11 = (void *)(ulong)uVar4;
      iVar3 = 3;
    }
LAB_00100fa8:
    _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",iVar3 + (uint)*(ushort *)(plVar5 + 2),
            pvVar11);
  }
LAB_00101094:
  bcl_device_ct = bcl_device_ct - 1;
LAB_00101288:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)pvVar11 & 0xffffffff;
}



//------------------------------------------------------------
// bcl_remove @ 00101348 size=116
// signature: undefined bcl_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_remove(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = 0x128;
  lVar2 = *(long *)(param_1 + 0xa8);
  do {
    lVar3 = *(long *)(lVar2 + lVar1);
    if ((lVar3 != 0) && (*(long *)(lVar3 + 0x440) != 0)) {
      mutex_lock(lVar3 + 0x480);
      *(undefined8 *)(*(long *)(lVar3 + 0x440) + 0x20) = 0;
      mutex_unlock(lVar3 + 0x480);
    }
    lVar1 = lVar1 + 0xe0;
  } while (lVar1 != 0x9e8);
  return 0;
}



//------------------------------------------------------------
// bcl_read_vbat_tz @ 001013c0 size=544
// signature: undefined bcl_read_vbat_tz(void)
// callers: [bcl_read_lbat, bcl_handle_irq]
//------------------------------------------------------------

int bcl_read_vbat_tz(long param_1,uint *param_2)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  uint local_3c;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x3f0);
  *param_2 = 0;
  local_3c = 0;
  lVar7 = *(long *)(lVar6 + 0xd8);
  if (*(byte *)(lVar7 + 0x12) < 5) {
    if (lVar7 == 0) {
      pcVar4 = "bcl_read_register";
LAB_001015a0:
      _printk(&DAT_00103aa4,"bcl_pmic5",pcVar4);
      iVar3 = -0x16;
      goto LAB_0010153c;
    }
    iVar3 = regmap_read(*(undefined8 *)(lVar7 + 8),*(ushort *)(lVar7 + 0x10) + 0x76,&local_3c);
    if (iVar3 < 0) {
      _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",*(ushort *)(lVar7 + 0x10) + 0x76,iVar3);
      goto LAB_0010153c;
    }
  }
  else {
    if (lVar7 == 0) {
      pcVar4 = "bcl_read_multi_register";
      goto LAB_001015a0;
    }
    iVar3 = regmap_bulk_read(*(undefined8 *)(lVar7 + 8),*(ushort *)(lVar7 + 0x10) + 0x76,&local_3c,2
                            );
    if (iVar3 < 0) {
      _printk(&DAT_00103663,"bcl_pmic5","bcl_read_multi_register",*(ushort *)(lVar7 + 0x10) + 0x76,2
              ,iVar3);
      goto LAB_0010153c;
    }
  }
  if (iVar3 != 0) goto LAB_0010153c;
  *param_2 = local_3c;
  bVar1 = *(byte *)(*(long *)(lVar6 + 0xd8) + 0x12);
  if ((bVar1 < 5) && (local_3c == 0x7f)) {
LAB_00101498:
    *param_2 = *(uint *)(lVar6 + 0x10);
    lVar7 = *(long *)(lVar6 + 0xd8);
  }
  else {
    if (bVar1 < 5) {
      uVar5 = (int)(local_3c * 0xc2a3) / 1000;
    }
    else {
      if (local_3c == 0x7fff) goto LAB_00101498;
      uVar5 = (local_3c * 0x2f84d) / 1000000;
    }
    *param_2 = uVar5;
    *(uint *)(lVar6 + 0x10) = uVar5;
    lVar7 = *(long *)(lVar6 + 0xd8);
  }
  if ((lVar7 != 0) && (*(long *)(lVar7 + 0x18) != 0)) {
    lVar2 = sp_el0;
    ipc_log_string(*(long *)(lVar7 + 0x18),"[%s]: %s: vbat:%d mv ADC:0x%02x\n",lVar2 + 0x848,
                   "bcl_read_vbat_tz",*(undefined4 *)(lVar6 + 0x10));
  }
  iVar3 = 0;
LAB_0010153c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// bcl_read_vbat_type @ 001015e4 size=16
// signature: undefined bcl_read_vbat_type(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_read_vbat_type(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  *param_3 = 1;
  return 0;
}



//------------------------------------------------------------
// bcl_get_vbat_trip @ 001015f8 size=388
// signature: undefined bcl_get_vbat_trip(void)
// callers: []
//------------------------------------------------------------

int bcl_get_vbat_trip(long param_1,int param_2,int *param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  int local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x3f0);
  local_4c = 0;
  *param_3 = 0;
  if (param_2 == 0) {
    iVar3 = 0x48;
    bVar1 = true;
    lVar5 = *(long *)(lVar4 + 0xd8);
  }
  else if (param_2 == 2) {
    bVar1 = false;
    iVar3 = 0x4a;
    lVar5 = *(long *)(lVar4 + 0xd8);
  }
  else {
    if (param_2 != 1) {
      iVar2 = -0x13;
      goto LAB_00101718;
    }
    bVar1 = false;
    iVar3 = 0x49;
    lVar5 = *(long *)(lVar4 + 0xd8);
  }
  if (lVar5 == 0) {
    _printk(&DAT_00103aa4,"bcl_pmic5","bcl_read_register");
    iVar2 = -0x16;
  }
  else {
    iVar2 = regmap_read(*(undefined8 *)(lVar5 + 8),iVar3 + (uint)*(ushort *)(lVar5 + 0x10),&local_4c
                       );
    if (iVar2 < 0) {
      _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",iVar3 + (uint)*(ushort *)(lVar5 + 0x10),
              iVar2);
    }
    else if (iVar2 == 0) {
      if (bVar1) {
        *param_3 = local_4c;
        iVar2 = 2000;
        if (*(char *)(*(long *)(lVar4 + 0xd8) + 0x22) != '\0') {
          iVar2 = 1000;
        }
        iVar3 = 0;
        if (iVar2 != 0) {
          iVar3 = (local_4c * 0xc2a3) / iVar2;
        }
      }
      else {
        iVar3 = local_4c * 0x19 + 0x8ca;
        if (0xe0f < iVar3) {
          iVar3 = 0xe10;
        }
      }
      iVar2 = 0;
      *param_3 = iVar3;
    }
  }
LAB_00101718:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// bcl_read_ibat @ 00101780 size=648
// signature: undefined bcl_read_ibat(void)
// callers: [bcl_read_lbat, bcl_handle_irq]
//------------------------------------------------------------

int bcl_read_ibat(long param_1,uint *param_2)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  int local_3c;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + 0x3f0);
  *param_2 = 0;
  local_3c = 0;
  lVar8 = *(long *)(lVar7 + 0xd8);
  if (*(byte *)(lVar8 + 0x12) < 5) {
    if (lVar8 == 0) {
      pcVar3 = "bcl_read_register";
      goto LAB_00101934;
    }
    iVar2 = regmap_read(*(undefined8 *)(lVar8 + 8),*(ushort *)(lVar8 + 0x10) + 0x86,&local_3c);
    if (iVar2 < 0) {
      _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",*(ushort *)(lVar8 + 0x10) + 0x86,iVar2);
      goto LAB_001019d4;
    }
  }
  else {
    if (lVar8 == 0) {
      pcVar3 = "bcl_read_multi_register";
LAB_00101934:
      _printk(&DAT_00103aa4,"bcl_pmic5",pcVar3);
      iVar2 = -0x16;
      goto LAB_001019d4;
    }
    iVar2 = regmap_bulk_read(*(undefined8 *)(lVar8 + 8),*(ushort *)(lVar8 + 0x10) + 0x86,&local_3c,2
                            );
    if (iVar2 < 0) {
      _printk(&DAT_00103663,"bcl_pmic5","bcl_read_multi_register",*(ushort *)(lVar8 + 0x10) + 0x86,2
              ,iVar2);
      goto LAB_001019d4;
    }
  }
  if (iVar2 != 0) goto LAB_001019d4;
  uVar4 = 0x18;
  if (4 < *(byte *)(*(long *)(lVar7 + 0xd8) + 0x12)) {
    uVar4 = 0x10;
  }
  uVar4 = (local_3c << (ulong)uVar4) >> uVar4;
  *param_2 = uVar4;
  if (local_3c == 0) {
    *param_2 = *(uint *)(lVar7 + 0x10);
    lVar8 = *(long *)(lVar7 + 0xd8);
  }
  else {
    lVar8 = *(long *)(lVar7 + 0xd8);
    if (*(char *)(lVar8 + 0x20) == '\0') {
      if (*(byte *)(lVar8 + 0x12) < 5) {
        iVar2 = 10000;
        if (*(char *)(lVar8 + 0x21) != '\0') {
          iVar2 = 2000;
        }
        if (*(byte *)(lVar8 + 0x12) == 4) {
          uVar6 = 0x6e39;
        }
        else {
          uVar6 = 0x312f;
        }
        iVar5 = uVar4 * *(int *)(lVar8 + 0x24) * (uVar6 | 0x10000);
        goto LAB_00101994;
      }
      if (*(byte *)(lVar8 + 0x14) < 3) {
        iVar2 = 0x5968c;
      }
      else {
        iVar2 = 0xee6d;
      }
      uVar4 = (uVar4 * iVar2) / 1000000;
    }
    else {
      iVar5 = uVar4 * *(int *)(lVar8 + 0x24) * 0x3d09;
      iVar2 = 10000;
      if (*(char *)(lVar8 + 0x21) != '\0') {
        iVar2 = 2000;
      }
LAB_00101994:
      uVar4 = 0;
      if (iVar2 != 0) {
        uVar4 = iVar5 / iVar2;
      }
    }
    *param_2 = uVar4;
    *(uint *)(lVar7 + 0x10) = uVar4;
    lVar8 = *(long *)(lVar7 + 0xd8);
  }
  if ((lVar8 != 0) && (*(long *)(lVar8 + 0x18) != 0)) {
    lVar1 = sp_el0;
    ipc_log_string(*(long *)(lVar8 + 0x18),"[%s]: %s: ibat:%d mA ADC:0x%02x\n",lVar1 + 0x848,
                   "bcl_read_ibat",*(undefined4 *)(lVar7 + 0x10));
  }
  iVar2 = 0;
LAB_001019d4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// bcl_set_ibat @ 00101a0c size=656
// signature: undefined bcl_set_ibat(void)
// callers: []
//------------------------------------------------------------

int bcl_set_ibat(long param_1,undefined8 param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  piVar7 = *(int **)(param_1 + 0x3f0);
  mutex_lock(piVar7 + 6);
  if (*(long *)(piVar7 + 2) != (long)param_3) {
    if ((*piVar7 != 0) && ((char)piVar7[0x12] != '\0')) {
      disable_irq_nosync();
      *(undefined1 *)(piVar7 + 0x12) = 0;
    }
    if (param_3 == 0x7fffffff) {
      iVar2 = 0;
      piVar7[2] = 0x7fffffff;
      piVar7[3] = 0;
      goto switchD_00101b58_caseD_2;
    }
    lVar3 = *(long *)(piVar7 + 0x36);
    if (*(char *)(lVar3 + 0x20) == '\0') {
      if (*(byte *)(lVar3 + 0x12) < 5) {
        if (*(byte *)(lVar3 + 0x12) == 4) goto LAB_00101acc;
        iVar2 = *(int *)(lVar3 + 0x24);
        uVar5 = 0x312f;
      }
      else {
        if (2 < *(byte *)(lVar3 + 0x14)) {
          iVar2 = *(int *)(lVar3 + 0x24);
          uVar5 = 0x2625f;
          goto LAB_00101ae4;
        }
LAB_00101acc:
        iVar2 = *(int *)(lVar3 + 0x24);
        uVar5 = 0x6e39;
      }
      uVar5 = uVar5 | 0x10000;
    }
    else {
      iVar2 = *(int *)(lVar3 + 0x24);
      uVar5 = 0x3d09;
    }
LAB_00101ae4:
    iVar2 = iVar2 * uVar5;
    if (*(char *)(lVar3 + 0x21) == '\0') {
      lVar4 = (long)iVar2;
      uVar5 = 0;
      if (lVar4 != 0) {
        uVar5 = (uint)((long)(ulong)(uint)(param_3 * 20000) / lVar4);
      }
      uVar1 = 0;
      if (lVar4 != 0) {
        uVar1 = (uint)((long)(ulong)(uint)(param_3 * 10000) / lVar4);
      }
      if (*(char *)(lVar3 + 0x22) != '\0') {
        uVar5 = uVar1;
      }
    }
    else {
      uVar5 = 0;
      if (iVar2 != 0) {
        uVar5 = (param_3 * 4000) / iVar2;
      }
    }
    iVar2 = 0;
    iVar6 = 0x4b;
    switch(piVar7[0x13]) {
    case 0:
    case 8:
switchD_00101b58_caseD_0:
      break;
    case 1:
    case 9:
      iVar6 = 0x4c;
      if ((3 < *(byte *)(lVar3 + 0x12)) && (iVar6 = 0x4c, (*(byte *)(lVar3 + 0x15) & 4) != 0)) {
        iVar6 = 0x4d;
      }
      if ((*(char *)(lVar3 + 0x20) == '\0') ||
         (uVar5 = (param_3 + -800) / 100, (int)(uVar5 * 0x1000000) < 0xe000001))
      goto switchD_00101b58_caseD_0;
      _printk(&DAT_001037de,"bcl_pmic5","convert_ibat_to_ccm_val",param_3);
      lVar3 = *(long *)(piVar7 + 0x36);
      uVar5 = 0xe;
      break;
    default:
      goto switchD_00101b58_caseD_2;
    }
    if (lVar3 == 0) {
      _printk(&DAT_00103aa4,"bcl_pmic5","bcl_write_register");
      iVar2 = -0x16;
      goto switchD_00101b58_caseD_2;
    }
    iVar6 = (uint)*(ushort *)(lVar3 + 0x10) + iVar6;
    iVar2 = regmap_write(*(undefined8 *)(lVar3 + 8),iVar6,uVar5 & 0xff);
    if (iVar2 < 0) {
      _printk(&DAT_001039ff,"bcl_pmic5","bcl_write_register",iVar6,uVar5 & 0xff,iVar2);
      goto switchD_00101b58_caseD_2;
    }
    if (iVar2 != 0) goto switchD_00101b58_caseD_2;
    *(long *)(piVar7 + 2) = (long)param_3;
    if ((*piVar7 != 0) && ((char)piVar7[0x12] == '\0')) {
      enable_irq();
      iVar2 = 0;
      *(undefined1 *)(piVar7 + 0x12) = 1;
      goto switchD_00101b58_caseD_2;
    }
  }
  iVar2 = 0;
switchD_00101b58_caseD_2:
  mutex_unlock(piVar7 + 6);
  return iVar2;
}



//------------------------------------------------------------
// bcl_lvl_init @ 00101c9c size=432
// signature: undefined bcl_lvl_init(void)
// callers: [bcl_probe]
//------------------------------------------------------------

void bcl_lvl_init(long param_1,uint param_2,undefined4 param_3,long param_4)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  int *piVar5;
  long lVar6;
  
  lVar4 = param_4 + (ulong)param_2 * 0xe0;
  lVar6 = lVar4 + 0x70;
  __mutex_init(lVar6,"&lbat->state_trans_lock",&bcl_lvl_init___key);
  *(uint *)(lVar4 + 0xa4) = param_2;
  *(long *)(lVar4 + 0x130) = param_4;
  *(undefined4 *)(lVar4 + 0x5c) = param_3;
  mutex_lock(lVar6);
  piVar5 = (int *)(lVar4 + 0x58);
  *piVar5 = 0;
  *(undefined1 *)(lVar4 + 0xa0) = 0;
  iVar1 = platform_get_irq_byname(param_1,bcl_int_names + (ulong)param_2 * 0x19);
  if (0 < iVar1) {
    iVar2 = devm_request_threaded_irq
                      (param_1 + 0x10,iVar1,0,bcl_handle_irq,0x2001,
                       bcl_int_names + (ulong)param_2 * 0x19,piVar5);
    if (iVar2 == 0) {
      disable_irq_nosync(iVar1);
      *piVar5 = iVar1;
    }
    else {
      _dev_err(param_1 + 0x10,"Error requesting trip irq. err:%d\n",iVar2);
    }
  }
  mutex_unlock(lVar6);
  if (0 < *piVar5) {
    param_4 = param_4 + (ulong)param_2 * 0xe0;
    *(code **)(param_4 + 0xb8) = bcl_read_lbat;
    *(code **)(param_4 + 0xc0) = bcl_set_lbat;
    *(code **)(param_4 + 0x108) = bcl_get_trend;
    uVar3 = devm_thermal_of_zone_register(param_1 + 0x10,param_2,piVar5,param_4 + 0xa8);
    *(ulong *)(param_4 + 0x128) = uVar3;
    if (uVar3 < 0xfffffffffffff001) {
      thermal_zone_device_update(uVar3,5);
      lVar6 = *(long *)(param_4 + 0x128);
      if ((lVar6 != 0) && (*(long *)(lVar6 + 0x440) != 0)) {
        mutex_lock(lVar6 + 0x480);
        if (*(long *)(*(long *)(lVar6 + 0x440) + 0x20) == 0) {
          *(code **)(*(long *)(lVar6 + 0x440) + 0x20) = qti_tz_change_mode;
        }
        mutex_unlock(lVar6 + 0x480);
      }
    }
    else {
      *(long *)(param_4 + 0x128) = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// bcl_handle_irq @ 00101e50 size=676
// signature: undefined bcl_handle_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_handle_irq(undefined4 param_1,long param_2)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 local_54;
  undefined8 local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_50 = 0;
  local_54 = 0;
  local_58 = 0;
  local_68 = 0;
  local_60 = 0;
  local_70 = 0;
  if (*(long *)(param_2 + 0xd0) != 0) {
    lVar7 = *(long *)(param_2 + 0xd8);
    iVar1 = *(int *)(param_2 + 0x4c);
    if (lVar7 == 0) {
      _printk(&DAT_00103aa4,"bcl_pmic5","bcl_read_register");
    }
    else {
      iVar4 = regmap_read(*(undefined8 *)(lVar7 + 8),*(ushort *)(lVar7 + 0x10) + 8,
                          (long)&local_50 + 4);
      if (iVar4 < 0) {
        _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",*(ushort *)(lVar7 + 0x10) + 8,iVar4);
      }
    }
    lVar5 = *(long *)(lVar7 + 0x128);
    if ((lVar5 != 0) || (lVar5 = *(long *)(lVar7 + 0x828), lVar5 != 0)) {
      bcl_read_ibat(lVar5,&local_50);
    }
    uVar2 = iVar1 - 5;
    if (*(long *)(lVar7 + 0x2e8) != 0) {
      bcl_read_vbat_tz(*(long *)(lVar7 + 0x2e8),&local_54);
    }
    if (uVar2 < 3) {
      if ((*(uint *)(param_2 + 4) & local_50._4_4_) != 0) {
        lVar5 = sched_clock();
        thermal_zone_device_update(*(undefined8 *)(param_2 + 0xd0),2);
        lVar6 = sched_clock();
        if (lVar7 == 0) {
          if (DAT_00000017 != '\0') {
            get_bpm_stats(0,&local_70);
          }
        }
        else {
          if (*(long *)(lVar7 + 0x18) != 0) {
            if (10 < *(uint *)(param_2 + 0x4c)) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1020f4);
              (*pcVar3)();
            }
            lVar8 = sp_el0;
            ipc_log_string(*(long *)(lVar7 + 0x18),
                           "[%s]: %s: Irq:%d triggered for bcl type:%s. status:%u ibat=%d vbat=%d\n"
                           ,lVar8 + 0x848,"bcl_handle_irq",param_1,
                           bcl_int_names + (ulong)*(uint *)(param_2 + 0x4c) * 0x19,local_50._4_4_,
                           local_50 & 0xffffffff,local_54);
          }
          if (*(char *)(lVar7 + 0x17) != '\0') {
            get_bpm_stats(lVar7,&local_70);
            if (*(long *)(lVar7 + 0x18) != 0) {
              lVar8 = sp_el0;
              ipc_log_string(*(long *)(lVar7 + 0x18),
                             "[%s]: %s: bpm. lvl0:%d lvl1:%d lvl2:%d max_ibat:%d sync_vbat:%d min_vbat:%d sync_ibat:%d\n"
                             ,lVar8 + 0x848,"bcl_handle_irq",local_70 & 0xffffffff,local_70._4_4_,
                             local_68 & 0xffffffff,local_68._4_4_,(undefined4)local_60,
                             local_60._4_4_,local_58);
            }
          }
        }
        lVar8 = lVar7 + (ulong)uVar2 * 0x158;
        bcl_update_trigger_stats(lVar8 + 0x918,local_50 & 0xffffffff,local_54,lVar5);
        if (*(ulong *)(lVar8 + 0x930) < (ulong)(lVar6 - lVar5)) {
          *(long *)(lVar8 + 0x930) = lVar6 - lVar5;
          *(long *)(lVar7 + (ulong)uVar2 * 0x158 + 0x928) = lVar5;
        }
        if (*(char *)(param_2 + 0x48) == '\0') goto LAB_00102048;
      }
      lVar7 = lVar7 + (ulong)uVar2 * 0x158;
      *(int *)(lVar7 + 0x91c) = *(int *)(lVar7 + 0x91c) + 1;
    }
    else {
      _printk(&DAT_0010351d,"bcl_pmic5","bcl_handle_irq",*(undefined4 *)(param_2 + 0x4c));
    }
  }
LAB_00102048:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// bcl_read_lbat @ 001020f8 size=424
// signature: undefined bcl_read_lbat(void)
// callers: []
//------------------------------------------------------------

int bcl_read_lbat(long param_1,uint *param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  uint local_44 [3];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x3f0);
  local_44[2] = 0;
  local_44[0] = 0;
  local_44[1] = 0;
  lVar5 = *(long *)(lVar4 + 0xd8);
  *param_2 = 0;
  if (lVar5 == 0) {
    _printk(&DAT_00103aa4,"bcl_pmic5","bcl_read_register");
    iVar1 = -0x16;
  }
  else {
    iVar1 = regmap_read(*(undefined8 *)(lVar5 + 8),*(ushort *)(lVar5 + 0x10) + 8,local_44);
    if (iVar1 < 0) {
      _printk(&DAT_00103b63,"bcl_pmic5","bcl_read_register",*(ushort *)(lVar5 + 0x10) + 8,iVar1);
    }
    else if (iVar1 == 0) {
      iVar1 = *(int *)(lVar4 + 0x4c);
      if (iVar1 == 7) {
        uVar3 = local_44[0] & 4;
      }
      else if (iVar1 == 6) {
        uVar3 = local_44[0] & 2;
      }
      else {
        if (iVar1 != 5) {
          _printk(&DAT_00103872,"bcl_pmic5","bcl_read_lbat");
          iVar1 = -0x13;
          goto LAB_001021f8;
        }
        uVar3 = local_44[0] & 1;
      }
      *param_2 = uVar3;
      *(uint *)(lVar4 + 0x10) = uVar3;
      lVar2 = *(long *)(lVar5 + 0x128);
      if ((lVar2 != 0) || (lVar2 = *(long *)(lVar5 + 0x828), lVar2 != 0)) {
        bcl_read_ibat(lVar2,local_44 + 2);
      }
      if (*(long *)(lVar5 + 0x2e8) != 0) {
        bcl_read_vbat_tz(*(long *)(lVar5 + 0x2e8),local_44 + 1);
      }
      if (*(long *)(lVar5 + 0x18) != 0) {
        lVar2 = sp_el0;
        ipc_log_string(*(long *)(lVar5 + 0x18),"[%s]: %s: LVLbat:%d irq_status:%d val:%d\n",
                       lVar2 + 0x848,"bcl_read_lbat",*(undefined4 *)(lVar4 + 0x4c),local_44[0],
                       *(undefined4 *)(lVar4 + 0x10));
      }
      iVar1 = 0;
    }
  }
LAB_001021f8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// bcl_set_lbat @ 001022a4 size=376
// signature: undefined bcl_set_lbat(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_set_lbat(long param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  int *piVar5;
  long lVar6;
  
  piVar5 = *(int **)(param_1 + 0x3f0);
  if (*(char *)((long)piVar5 + 0x49) != '\0') {
    return 0;
  }
  lVar6 = *(long *)(piVar5 + 0x36);
  mutex_lock(piVar5 + 6);
  if (piVar5[0x13] - 5U < 3) {
    if (param_3 == 1) {
      if ((*piVar5 != 0) && ((char)piVar5[0x12] == '\0')) {
        puVar1 = (undefined4 *)(lVar6 + (ulong)(piVar5[0x13] - 5U) * 0x158 + 0x918);
        bcl_update_clear_stats(puVar1);
        enable_irq(*piVar5);
        irq_set_irq_wake(*piVar5,1);
        *(undefined1 *)(piVar5 + 0x12) = 1;
        if ((lVar6 != 0) && (*(long *)(lVar6 + 0x18) != 0)) {
          if (10 < (uint)piVar5[0x13]) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10241c);
            (*pcVar3)();
          }
          lVar2 = sp_el0;
          ipc_log_string(*(long *)(lVar6 + 0x18),
                         "[%s]: %s: Irq %d cleared for bcl type %s.Rearm irq.low: %d, high: %d, irq_count: %d\n"
                         ,lVar2 + 0x848,"bcl_set_lbat",*piVar5,
                         bcl_int_names + (ulong)(uint)piVar5[0x13] * 0x19,param_2,1,*puVar1);
        }
      }
    }
    else if ((*piVar5 != 0) && ((char)piVar5[0x12] != '\0')) {
      disable_irq_nosync();
      irq_set_irq_wake(*piVar5,0);
      uVar4 = 0;
      *(undefined1 *)(piVar5 + 0x12) = 0;
      goto LAB_001023cc;
    }
    uVar4 = 0;
  }
  else {
    _printk(&DAT_0010351d,"bcl_pmic5","bcl_set_lbat");
    uVar4 = 0xffffffea;
  }
LAB_001023cc:
  mutex_unlock(piVar5 + 6);
  return uVar4;
}



//------------------------------------------------------------
// bcl_get_trend @ 00102420 size=92
// signature: undefined bcl_get_trend(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_get_trend(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3f0);
  lVar1 = lVar3 + 0x18;
  mutex_lock(lVar1);
  uVar2 = 1;
  if (*(int *)(lVar3 + 0x10) == 0) {
    uVar2 = 2;
  }
  *param_3 = uVar2;
  mutex_unlock(lVar1);
  return 0;
}



//------------------------------------------------------------
// qti_tz_change_mode @ 00102480 size=156
// signature: undefined qti_tz_change_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_tz_change_mode(long param_1,int param_2)

{
  long *plVar1;
  
  if (param_1 != 0) {
    plVar1 = *(long **)(param_1 + 0x460);
    *(undefined8 *)(param_1 + 0x42c) = 0x8000000100000000;
    *(undefined4 *)(param_1 + 0x420) = 0xfffbd1b0;
    *(undefined4 *)(param_1 + 0x434) = 0x7fffffff;
    for (; plVar1 != (long *)(param_1 + 0x460); plVar1 = (long *)*plVar1) {
      *(undefined1 *)((long)plVar1 + -0x8c) = 0;
      if (param_2 == 0) {
        plVar1[-0xf] = 0xffffffffffffffff;
        *(undefined1 *)(plVar1[-0x13] + 0x3c8) = 0;
        thermal_cdev_update(plVar1[-0x13]);
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// bcl_freeze @ 00102520 size=176
// signature: undefined bcl_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_freeze(long param_1)

{
  long lVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = 0;
  lVar5 = *(long *)(param_1 + 0x98);
  do {
    lVar1 = lVar5 + lVar4;
    mutex_lock(lVar1 + 0x70);
    piVar3 = (int *)(lVar1 + 0x58);
    iVar2 = *piVar3;
    if ((0 < iVar2) && (*(char *)(lVar1 + 0xa0) != '\0')) {
      disable_irq(iVar2);
      iVar2 = *piVar3;
      *(undefined1 *)(lVar1 + 0xa0) = 0;
    }
    devm_free_irq(param_1,iVar2,piVar3);
    *(undefined1 *)(lVar1 + 0xa1) = 1;
    mutex_unlock(lVar1 + 0x70);
    lVar4 = lVar4 + 0xe0;
  } while (lVar4 != 0x8c0);
  return 0;
}



//------------------------------------------------------------
// bcl_restore @ 001025d4 size=372
// signature: undefined bcl_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_restore(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int *piVar5;
  long lVar6;
  long lVar7;
  
  lVar7 = 0;
  lVar6 = *(long *)(param_1 + 0x98);
  pcVar4 = bcl_int_names;
  do {
    lVar1 = lVar6 + lVar7;
    mutex_lock(lVar1 + 0x70);
    piVar5 = (int *)(lVar1 + 0x58);
    if ((0 < *piVar5) && (*(char *)(lVar1 + 0xa0) == '\0')) {
      iVar2 = devm_request_threaded_irq(param_1,*piVar5,0,bcl_handle_irq,0x2001,pcVar4,piVar5);
      if (iVar2 != 0) {
        _dev_err(param_1,"Error requesting trip irq. err:%d\n",iVar2);
        mutex_unlock(lVar6 + lVar7 + 0x70);
        return 0xffffffea;
      }
      disable_irq_nosync(*piVar5);
      *(undefined1 *)(lVar6 + lVar7 + 0xa1) = 0;
    }
    mutex_unlock(lVar1 + 0x70);
    if (*(long *)(lVar1 + 0x128) != 0) {
      thermal_zone_device_update(*(long *)(lVar1 + 0x128),5);
    }
    pcVar4 = pcVar4 + 0x19;
    lVar7 = lVar7 + 0xe0;
  } while (lVar7 != 0x8c0);
  if (lVar6 == 0) {
    _printk(&DAT_00103aa4,"bcl_pmic5","bcl_write_register");
  }
  else {
    iVar2 = *(ushort *)(lVar6 + 0x10) + 0x46;
    iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),iVar2,0x80);
    if (iVar3 < 0) {
      _printk(&DAT_001039ff,"bcl_pmic5","bcl_write_register",iVar2,0x80,iVar3);
    }
  }
  return 0;
}



//------------------------------------------------------------
// bcl_update_clear_stats @ 0010274c size=168
// signature: undefined bcl_update_clear_stats(void)
// callers: [bcl_set_lbat]
//------------------------------------------------------------

void bcl_update_clear_stats(uint *param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  ulong uVar4;
  
  if ((char)param_1[2] != '\0') {
    uVar1 = *param_1;
    lVar2 = sched_clock();
    lVar3 = *(long *)(param_1 + (ulong)(uVar1 % 10) * 6 + 0x1c);
    *(long *)(param_1 + (ulong)(uVar1 % 10) * 6 + 0x1e) = lVar2;
    uVar4 = ((lVar2 - lVar3) + 999U) / 1000;
    *(ulong *)(param_1 + 10) = uVar4 + *(long *)(param_1 + 10);
    if (*(ulong *)(param_1 + 8) < uVar4) {
      *(ulong *)(param_1 + 8) = uVar4;
    }
    *(undefined1 *)(param_1 + 2) = 0;
    *param_1 = *param_1 + 1;
  }
  return;
}



//------------------------------------------------------------
// bcl_update_trigger_stats @ 001027f8 size=56
// signature: undefined bcl_update_trigger_stats(void)
// callers: [bcl_handle_irq]
//------------------------------------------------------------

void bcl_update_trigger_stats(uint *param_1,uint param_2,uint param_3,undefined8 param_4)

{
  uint uVar1;
  
  uVar1 = *param_1 % 10;
  *(undefined1 *)(param_1 + 2) = 1;
  *(undefined8 *)(param_1 + (ulong)uVar1 * 6 + 0x1c) = param_4;
  (param_1 + (ulong)uVar1 * 6 + 0x1e)[0] = 0;
  (param_1 + (ulong)uVar1 * 6 + 0x1e)[1] = 0;
  param_1[(ulong)uVar1 * 6 + 0x1a] = param_3;
  param_1[(ulong)uVar1 * 6 + 0x1b] = param_2;
  return;
}



//------------------------------------------------------------
// bcl_stats_init @ 00102834 size=404
// signature: undefined bcl_stats_init(void)
// callers: [bcl_probe]
//------------------------------------------------------------

void bcl_stats_init(undefined8 param_1,long param_2,int param_3)

{
  int param3;
  long lVar1;
  char local_88 [32];
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_88[0x18] = '\0';
  local_88[0x19] = '\0';
  local_88[0x1a] = '\0';
  local_88[0x1b] = '\0';
  local_88[0x1c] = '\0';
  local_88[0x1d] = '\0';
  local_88[8] = '\0';
  local_88[9] = '\0';
  local_88[10] = '\0';
  local_88[0xb] = '\0';
  local_88[0xc] = '\0';
  local_88[0xd] = '\0';
  local_88[0xe] = '\0';
  local_88[0xf] = '\0';
  local_88[0x10] = '\0';
  local_88[0x11] = '\0';
  local_88[0x12] = '\0';
  local_88[0x13] = '\0';
  local_88[0x14] = '\0';
  local_88[0x15] = '\0';
  local_88[0x16] = '\0';
  local_88[0x17] = '\0';
  local_88[0] = '\0';
  local_88[1] = '\0';
  local_88[2] = '\0';
  local_88[3] = '\0';
  local_88[4] = '\0';
  local_88[5] = '\0';
  local_88[6] = '\0';
  local_88[7] = '\0';
  bcl_stats_parent = debugfs_lookup("bcl_stats",0);
  if (bcl_stats_parent == 0) {
    bcl_stats_parent = debugfs_create_dir("bcl_stats",0);
  }
  bcl_dev_parent = debugfs_create_dir(param_1,bcl_stats_parent);
  if (param_3 != 0) {
    param3 = 0;
    do {
      snprintf(local_88,0x1e,"lvl%d_stats",param3);
      lVar1 = param_2 + 0x918 + (long)param3 * 0x158;
      __mutex_init(lVar1 + 0x30,"&bcl_stats[idx].stats_lock",&bcl_stats_init___key);
      debugfs_create_file(local_88,0x124,bcl_dev_parent,lVar1,&bcl_lvl_fops);
      param3 = param3 + 1;
    } while (param_3 != param3);
  }
  debugfs_create_file("bpm_stats",0x124,bcl_dev_parent,param_2,&bpm_stats_fops);
  debugfs_create_file("reset",0x80,bcl_dev_parent,param_2,&bpm_reset_fops);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// bcl_lvl_open @ 001029cc size=48
// signature: undefined bcl_lvl_open(void)
// callers: []
//------------------------------------------------------------

void bcl_lvl_open(long param_1,undefined8 param_2)

{
  single_open(param_2,bcl_lvl_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// bcl_lvl_show @ 00102a00 size=508
// signature: undefined bcl_lvl_show(void)
// callers: []
//------------------------------------------------------------

undefined8 bcl_lvl_show(long param_1)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar5 = *(uint **)(param_1 + 0x80);
  seq_printf(param_1,"%-30s: %d\n","SW Counter",*puVar5);
  seq_printf(param_1,"%-30s: %d\n","Irq self cleared counter",puVar5[1]);
  seq_printf(param_1,"%-30s: %lu\n","Max Mitigation at",*(undefined8 *)(puVar5 + 4));
  seq_printf(param_1,"%-30s: %lu usec\n","Max Mitigation latency",
             (*(long *)(puVar5 + 6) + 999U) / 1000);
  seq_printf(param_1,"%-30s: %lu usec\n","BCL mitigation residency",*(undefined8 *)(puVar5 + 8));
  seq_printf(param_1,"%-30s: %lu usec\n","Total residency",*(undefined8 *)(puVar5 + 10));
  seq_printf(param_1,"Last %d iterations\t:\n",10);
  seq_printf(param_1,"%s%10s%10s%15s%15s%16s\n",&DAT_00103b2c,&DAT_00103557,&DAT_00103552,
             "trigger_ts","clear_ts","duration(usec)");
  uVar1 = ((*puVar5 / 10) * 10 ^ 0xffffffff) + *puVar5;
  uVar4 = uVar1;
  uVar6 = 0xfffffffe;
  do {
    while ((int)uVar4 < 0) {
      uVar4 = 9;
      uVar6 = uVar1;
      if (8 < (int)uVar1) {
        return 0;
      }
    }
    lVar2 = *(long *)(puVar5 + (ulong)uVar4 * 6 + 0x1e);
    if (lVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = ((lVar2 - *(long *)(puVar5 + (ulong)uVar4 * 6 + 0x1c)) + 999U) / 1000;
    }
    seq_printf(param_1,"[%d]%10d%10d%15lu%15lu%16lu\n",uVar4,puVar5[(ulong)uVar4 * 6 + 0x1b],
               puVar5[(ulong)uVar4 * 6 + 0x1a],*(long *)(puVar5 + (ulong)uVar4 * 6 + 0x1c),lVar2,
               uVar3);
    uVar4 = uVar4 - 1;
  } while ((int)uVar6 < (int)uVar4);
  return 0;
}



//------------------------------------------------------------
// bpm_stats_open @ 00102c00 size=48
// signature: undefined bpm_stats_open(void)
// callers: []
//------------------------------------------------------------

void bpm_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,bpm_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// bpm_stats_show @ 00102c34 size=256
// signature: undefined bpm_stats_show(void)
// callers: []
//------------------------------------------------------------

undefined8 bpm_stats_show(long param_1)

{
  long lVar1;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar1 = *(long *)(param_1 + 0x80);
  if (lVar1 == 0) {
    _printk(&DAT_00103a89);
  }
  else if (*(char *)(lVar1 + 0x17) != '\0') {
    local_30 = 0;
    local_40 = 0;
    uStack_38 = 0;
    local_48 = 0;
    get_bpm_stats(lVar1,&local_48);
    seq_printf(param_1,"Max Ibat\t: %d \tSynchronus Vbat\t: %d\n",local_40._4_4_,
               uStack_38 & 0xffffffff);
    seq_printf(param_1,"Min Vbat\t: %d \tSynchronus Ibat\t: %d\n",uStack_38._4_4_,local_30);
    seq_printf(param_1,"%-30s: %d\n","lvl0 Alarm counter",local_48 & 0xffffffff);
    seq_printf(param_1,"%-30s: %d\n","lvl1 Alarm counter",local_48._4_4_);
    seq_printf(param_1,"%-30s: %d\n","lvl2 Alarm counter",local_40 & 0xffffffff);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// bpm_reset_fops_open @ 00102d38 size=48
// signature: undefined bpm_reset_fops_open(void)
// callers: []
//------------------------------------------------------------

void bpm_reset_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,0,bpm_reset,"%llu\n");
  return;
}



//------------------------------------------------------------
// bpm_reset @ 00102d6c size=120
// signature: undefined bpm_reset(void)
// callers: []
//------------------------------------------------------------

int bpm_reset(long param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    _printk(&DAT_00103a44);
  }
  else {
    iVar1 = *(ushort *)(param_1 + 0x10) + 0xa1;
    iVar2 = regmap_write(*(undefined8 *)(param_1 + 8),iVar1,1);
    if (iVar2 < 0) {
      _printk(&DAT_00103b30,iVar1,1,iVar2);
      return iVar2;
    }
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102de8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&bcl_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102e18 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&bcl_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00106000 size=1
// signature: undefined mutex_lock(void)
// callers: [bcl_set_lbat, bcl_remove, get_bpm_stats, bcl_lvl_init, bcl_set_ibat, bcl_get_trend, bcl_freeze, bcl_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00106008 size=1
// signature: undefined regmap_write(void)
// callers: [bpm_reset, get_bpm_stats, bcl_probe, bcl_set_ibat, bcl_restore, bcl_write_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00106010 size=1
// signature: undefined regmap_read(void)
// callers: [bcl_read_vbat_tz, bcl_read_lbat, bcl_get_vbat_trip, bcl_read_ibat, get_bpm_stats, bcl_probe, bcl_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106018 size=1
// signature: undefined _printk(void)
// callers: [bcl_get_vbat_trip, bcl_read_ibat, get_bpm_stats, bcl_read_multi_register, bcl_set_ibat, bcl_restore, bcl_read_vbat_tz, bcl_set_lbat, bcl_read_lbat, bpm_reset, bcl_probe, bcl_handle_irq, bpm_stats_show, bcl_write_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00106020 size=1
// signature: undefined mutex_unlock(void)
// callers: [bcl_set_lbat, bcl_remove, get_bpm_stats, bcl_lvl_init, bcl_set_ibat, bcl_get_trend, bcl_freeze, bcl_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [bcl_read_vbat_tz, bcl_read_lbat, bcl_get_vbat_trip, bcl_read_ibat, get_bpm_stats, bcl_probe, bcl_handle_irq, bpm_stats_show, bcl_stats_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00106030 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [bcl_read_vbat_tz, bcl_read_ibat, bcl_read_multi_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00106038 size=1
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
// platform_driver_unregister @ 00106040 size=1
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
// devm_kmalloc @ 00106048 size=1
// signature: undefined devm_kmalloc(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00106050 size=1
// signature: undefined __mutex_init(void)
// callers: [bcl_probe, bcl_lvl_init, bcl_stats_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00106058 size=1
// signature: undefined dev_get_regmap(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00106060 size=1
// signature: undefined __of_get_address(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00106068 size=1
// signature: undefined of_find_property(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00106070 size=1
// signature: undefined of_property_read_string(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_get @ 00106078 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 00106080 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 00106088 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00106090 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106098 size=1
// signature: undefined kfree(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_register @ 001060a0 size=1
// signature: undefined thermal_zone_device_register(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_enable @ 001060a8 size=1
// signature: undefined thermal_zone_device_enable(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_unregister @ 001060b0 size=1
// signature: undefined thermal_zone_device_unregister(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 001060b8 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [bcl_probe, bcl_lvl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001060c0 size=1
// signature: undefined _dev_err(void)
// callers: [bcl_probe, bcl_lvl_init, bcl_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 001060c8 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [bcl_probe, bcl_lvl_init, bcl_handle_irq, bcl_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001060d0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [bcl_probe, bcl_stats_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001060d8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [bcl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001060e0 size=1
// signature: undefined ipc_log_string(void)
// callers: [bcl_read_vbat_tz, bcl_set_lbat, bcl_read_lbat, bcl_read_ibat, bcl_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 001060e8 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [bcl_set_lbat, bcl_lvl_init, bcl_set_ibat, bcl_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 001060f0 size=1
// signature: undefined enable_irq(void)
// callers: [bcl_set_lbat, bcl_set_ibat]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 001060f8 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [bcl_lvl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00106100 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [bcl_lvl_init, bcl_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00106108 size=1
// signature: undefined sched_clock(void)
// callers: [bcl_handle_irq, bcl_update_clear_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00106110 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [bcl_set_lbat]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cdev_update @ 00106118 size=1
// signature: undefined thermal_cdev_update(void)
// callers: [qti_tz_change_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cdev_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00106120 size=1
// signature: undefined devm_free_irq(void)
// callers: [bcl_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00106128 size=1
// signature: undefined disable_irq(void)
// callers: [bcl_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_lookup @ 00106130 size=1
// signature: undefined debugfs_lookup(void)
// callers: [bcl_stats_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00106138 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [bcl_stats_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00106140 size=1
// signature: undefined debugfs_create_file(void)
// callers: [bcl_stats_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00106148 size=1
// signature: undefined single_open(void)
// callers: [bpm_stats_open, bcl_lvl_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00106150 size=1
// signature: undefined seq_printf(void)
// callers: [bcl_lvl_show, bpm_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 00106158 size=1
// signature: undefined simple_attr_open(void)
// callers: [bpm_reset_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



