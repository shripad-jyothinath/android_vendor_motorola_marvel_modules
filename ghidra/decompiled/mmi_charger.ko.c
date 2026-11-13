// Decompiled by Ghidra 12.2
// Program: mmi_charger.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_get_battery_charger_rate @ 00100c5c size=96
// signature: undefined mmi_get_battery_charger_rate(void)
// callers: []
//------------------------------------------------------------

undefined4 mmi_get_battery_charger_rate(long param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0xbc) == 0) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0xb8);
  if ((int)uVar1 < 0x9c4) {
    return 2;
  }
  if (uVar1 >> 2 < 0xc35) {
    return 1;
  }
  if (uVar1 >> 3 < 0xc35) {
    return 3;
  }
  uVar2 = 4;
  if (0x270 < uVar1 >> 6) {
    uVar2 = 5;
  }
  return uVar2;
}



//------------------------------------------------------------
// mmi_get_battery_serialnumber @ 00100cc0 size=176
// signature: undefined mmi_get_battery_serialnumber(void)
// callers: []
//------------------------------------------------------------

void mmi_get_battery_serialnumber(void)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_20;
  long local_18;
  
  lVar3 = sp_el0;
  local_18 = *(long *)(lVar3 + 0x638);
  lVar2 = of_find_node_opts_by_path("/chosen",0);
  local_20 = 0;
  lVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = of_property_read_string(lVar2,"mmi,battid",&local_20);
    if ((iVar1 == -0x16) || (local_20 == 0)) {
      _printk(&DAT_001099da);
      lVar3 = 0;
    }
    else {
      _printk(&DAT_00107fe9);
      lVar3 = local_20;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// mmi_is_factory_mode @ 00100d74 size=280
// signature: undefined mmi_is_factory_mode(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

void mmi_is_factory_mode(void)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  local_30 = (char *)0x0;
  if ((this_chip == 0) || (*(char *)(this_chip + 0x108) == '\0')) {
    pcVar4 = (char *)bi_bootmode();
    iVar2 = strncmp(pcVar4,"mot-factory",0xb);
    if (iVar2 != 0) {
      if ((lVar3 == 0) || (iVar2 = of_property_read_string(lVar3,"bootargs",&local_30), iVar2 != 0))
      {
        bVar1 = false;
      }
      else {
        pcVar4 = strstr(local_30,"androidboot.mode=");
        bVar1 = false;
        if (pcVar4 != (char *)0x0) {
          pcVar5 = strchr(pcVar4,0x20);
          pcVar4 = strchr(pcVar4,0x3d);
          bVar1 = false;
          if ((pcVar4 != (char *)0x0) && (pcVar4 <= pcVar5 && (long)pcVar5 - (long)pcVar4 != 0)) {
            lVar3 = strnstr(pcVar4,"factory",(long)pcVar5 - (long)pcVar4);
            bVar1 = lVar3 != 0;
          }
        }
      }
      goto LAB_00100e00;
    }
  }
  bVar1 = true;
LAB_00100e00:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// mmi_is_factory_version @ 00100e90 size=248
// signature: undefined mmi_is_factory_version(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

void mmi_is_factory_version(void)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  char *local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  local_30 = (char *)0x0;
  if ((this_chip == 0) || (*(char *)(this_chip + 0x109) == '\0')) {
    bVar1 = false;
    if (lVar3 != 0) {
      iVar2 = of_property_read_string(lVar3,"bootargs",&local_30);
      if (iVar2 == 0) {
        pcVar4 = strstr(local_30,"androidboot.bootloader=");
        bVar1 = false;
        if (pcVar4 != (char *)0x0) {
          pcVar5 = strchr(pcVar4,0x20);
          pcVar4 = strchr(pcVar4,0x3d);
          bVar1 = false;
          if ((pcVar4 != (char *)0x0) && (pcVar4 <= pcVar5 && (long)pcVar5 - (long)pcVar4 != 0)) {
            lVar3 = strnstr(pcVar4,"factory",(long)pcVar5 - (long)pcVar4);
            bVar1 = lVar3 != 0;
          }
        }
      }
      else {
        bVar1 = false;
      }
    }
  }
  else {
    bVar1 = true;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// mmi_get_charger_configure @ 00100f8c size=268
// signature: undefined mmi_get_charger_configure(void)
// callers: []
//------------------------------------------------------------

void mmi_get_charger_configure(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  
  lVar2 = this_chip;
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
  }
  else {
    lVar1 = this_chip + 0x20;
    mutex_lock(lVar1);
    plVar4 = (long *)(lVar2 + 0x10);
    do {
      plVar4 = (long *)*plVar4;
      if (plVar4 == (long *)(lVar2 + 0x10)) goto LAB_00101064;
    } while (plVar4[-0x15] != param_1);
    lVar3 = (long)(plVar4 + -0x22);
    mmi_get_charger_info(lVar2,lVar3);
    mmi_update_charger_profile(lVar2,lVar3);
    *(undefined1 *)(plVar4 + -5) = 0;
    *(undefined4 *)(plVar4 + -8) = 0xffffffea;
    *(undefined4 *)((long)plVar4 + -0x3c) = *(undefined4 *)((long)plVar4 + -0xf4);
    *(undefined4 *)(plVar4 + -7) = *(undefined4 *)((long)plVar4 + -0xf4);
    *(undefined4 *)((long)plVar4 + -0x34) = *(undefined4 *)((long)plVar4 + -0xfc);
    *(undefined4 *)(plVar4 + -6) = *(undefined4 *)(plVar4 + -0x1f);
    *(undefined4 *)((long)plVar4 + -0x2c) = 0;
    *(undefined4 *)((long)plVar4 + -0x24) = *(undefined4 *)(lVar2 + 0x104);
    *(undefined1 *)((long)plVar4 + -0x1f) = *(undefined1 *)(lVar2 + 0x109);
    *(undefined1 *)(plVar4 + -4) = *(undefined1 *)(lVar2 + 0x108);
    *(undefined4 *)((long)plVar4 + -0x1c) = *(undefined4 *)(lVar2 + 0x110);
    *(undefined4 *)(plVar4 + -3) = *(undefined4 *)(lVar2 + 0x114);
    *(undefined4 *)((long)plVar4 + -0x14) = *(undefined4 *)(lVar2 + 0x118);
    *(undefined4 *)(plVar4 + -2) = *(undefined4 *)(lVar2 + 0x11c);
    mmi_update_charger_status(lVar2,lVar3);
    mmi_configure_charger(lVar2,lVar3);
LAB_00101064:
    mmi_update_battery_status(lVar2);
    mutex_unlock(lVar1);
  }
  return;
}



//------------------------------------------------------------
// mmi_get_charger_info @ 00101098 size=548
// signature: undefined mmi_get_charger_info(void)
// callers: [mmi_get_charger_configure, mmi_charger_heartbeat_work]
//------------------------------------------------------------

void mmi_get_charger_info(undefined8 *param_1,long param_2)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  undefined8 in_stack_ffffffffffffff90;
  undefined4 uVar5;
  undefined8 local_50;
  long local_48;
  
  uVar5 = (undefined4)((ulong)in_stack_ffffffffffffff90 >> 0x20);
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if (param_1[0x13] == 0) {
    _printk(&DAT_00108321,*param_1,"mmi_get_cur_thermal_level");
    ipc_log_string(param_1[0x51],"E %s: %s: No battery supply found\n",*param_1,
                   "mmi_get_cur_thermal_level");
    uVar4 = 0;
  }
  else {
    iVar2 = power_supply_get_property(param_1[0x13],0x21,&local_50);
    uVar4 = (undefined4)local_50;
    if (iVar2 != 0) {
      uVar4 = 0;
    }
  }
  pcVar3 = *(code **)(*(long *)(param_2 + 0x68) + 0x10);
  if (*(int *)(pcVar3 + -4) != 0x4317e002) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x101154);
    (*pcVar3)();
  }
  (*pcVar3)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),param_2 + 0x70);
  pcVar3 = *(code **)(*(long *)(param_2 + 0x68) + 0x18);
  if (*(int *)(pcVar3 + -4) != 0x6c7bab0e) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x101180);
    (*pcVar3)();
  }
  (*pcVar3)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),param_2 + 0xac);
  _printk(&DAT_0010951b,*param_1,"mmi_get_charger_info",**(undefined8 **)(param_2 + 0x68),
          *(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x74),
          *(undefined4 *)(param_2 + 0x78),*(undefined4 *)(param_2 + 0x7c),
          *(undefined4 *)(param_2 + 0x80),param_2 + 0x9c,
          CONCAT44(uVar5,*(undefined4 *)(param_2 + 0x94)),*(undefined4 *)(param_2 + 0x98));
  ipc_log_string(param_1[0x51],
                 "I %s: %s: [C:%s]: batt_mv %d, batt_ma %d, batt_soc %d, batt_temp %d, batt_status %d, batt_sn %s, batt_fv_mv %d, batt_fcc_ma %d\n"
                 ,*param_1,"mmi_get_charger_info",**(undefined8 **)(param_2 + 0x68),
                 *(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x74),
                 *(undefined4 *)(param_2 + 0x78),*(undefined4 *)(param_2 + 0x7c),
                 *(undefined4 *)(param_2 + 0x80),param_2 + 0x9c,*(undefined4 *)(param_2 + 0x94),
                 *(undefined4 *)(param_2 + 0x98));
  _printk(&DAT_00108ec7,*param_1,"mmi_get_charger_info",**(undefined8 **)(param_2 + 0x68),
          *(undefined4 *)(param_2 + 0xbc),*(undefined4 *)(param_2 + 0xb4),
          *(undefined4 *)(param_2 + 0xb8),*(undefined4 *)(param_2 + 0xac),
          *(undefined4 *)(param_2 + 0xb0),*(undefined1 *)(param_2 + 0xc0),uVar4);
  ipc_log_string(param_1[0x51],
                 "I %s: %s: [C:%s]: chrg_present %d, chrg_type %d, chrg_pmax_mw %d, chrg_mv %d, chrg_ma %d, chrg_otg_enabled %d, thermal_level %d\n"
                 ,*param_1,"mmi_get_charger_info",**(undefined8 **)(param_2 + 0x68),
                 *(undefined4 *)(param_2 + 0xbc),*(undefined4 *)(param_2 + 0xb4),
                 *(undefined4 *)(param_2 + 0xb8),*(undefined4 *)(param_2 + 0xac),
                 *(undefined4 *)(param_2 + 0xb0),*(undefined1 *)(param_2 + 0xc0),uVar4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mmi_update_charger_profile @ 001012bc size=428
// signature: undefined mmi_update_charger_profile(void)
// callers: [mmi_get_charger_configure, mmi_charger_heartbeat_work]
//------------------------------------------------------------

void mmi_update_charger_profile(undefined8 *param_1,undefined8 *param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  code *pcVar7;
  int *piVar8;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00107cfe);
    return;
  }
  uVar6 = *(uint *)(param_2 + 7);
  if ((uVar6 == 0) || (piVar5 = (int *)param_2[8], piVar5 == (int *)0x0)) {
LAB_001013cc:
    iVar4 = *(int *)(param_2 + 1);
    *(undefined4 *)((long)param_2 + 0x1c) = *(undefined4 *)((long)param_2 + 0xc);
    *(undefined8 *)((long)param_2 + 0x14) = *param_2;
    if (((0 < iVar4) && (iVar1 = *(int *)((long)param_2 + 0x7c), 0x22 < iVar1)) && (iVar1 < 0x2e)) {
      *(int *)(param_2 + 3) = iVar4;
      _printk(&DAT_00107785,iVar1,iVar4,iVar4);
    }
  }
  else {
    pcVar7 = *(code **)(param_2[0xd] + 0x38);
    if (pcVar7 == (code *)0x0) {
      if (*(int *)(param_2 + 0x17) < 0x61a9) goto LAB_001013cc;
    }
    else {
      if (*(int *)(pcVar7 + -4) != 0x7850c00b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x822a,0x101314);
        (*pcVar7)();
      }
      uVar3 = (*pcVar7)(*(undefined8 *)(param_2[0xd] + 0x50),*(undefined4 *)((long)param_2 + 0x5c));
      if ((uVar3 & 1) == 0) goto LAB_001013cc;
      uVar6 = *(uint *)(param_2 + 7);
      piVar5 = (int *)param_2[8];
    }
    uVar3 = 0;
    if ((int)uVar6 < 1) {
      uVar6 = 0;
    }
    piVar8 = piVar5;
    do {
      if (uVar6 == uVar3) goto LAB_00101368;
      iVar4 = *piVar8;
      uVar3 = uVar3 + 1;
      piVar8 = piVar8 + 4;
    } while (iVar4 < *(int *)((long)param_2 + 0x7c));
    uVar6 = (uint)uVar3;
LAB_00101368:
    iVar4 = uVar6 - 1;
    if ((0 < (int)uVar6) && (piVar5 + (long)iVar4 * 4 != (int *)0x0)) {
      iVar1 = piVar5[(long)iVar4 * 4 + 1];
      *(int *)((long)param_2 + 0x1c) = iVar1;
      iVar2 = piVar5[(long)iVar4 * 4 + 3];
      *(int *)((long)param_2 + 0x14) = iVar2;
      iVar4 = piVar5[(long)iVar4 * 4 + 2];
      *(int *)(param_2 + 3) = iVar4;
      if (*(char *)param_1[0x50] != '\0') {
        _printk(&DAT_00107be4,*param_1,"mmi_update_charger_profile",*(undefined8 *)param_2[0xd],
                iVar1,iVar2,iVar4);
        iVar4 = *(int *)(param_2 + 3);
        iVar1 = *(int *)((long)param_2 + 0x1c);
        iVar2 = *(int *)((long)param_2 + 0x14);
      }
      ipc_log_string(param_1[0x51],"D %s: %s: [C:%s]: Max FV:%d, FG Iterm:%d, Chrg Iterm:%d\n",
                     *param_1,"mmi_update_charger_profile",*(undefined8 *)param_2[0xd],iVar1,iVar2,
                     iVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// mmi_update_charger_status @ 00101468 size=2680
// signature: undefined mmi_update_charger_status(void)
// callers: [mmi_get_charger_configure, mmi_charger_heartbeat_work]
//------------------------------------------------------------

void mmi_update_charger_status(undefined8 *param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  int *piVar8;
  ulong uVar9;
  ulong uVar10;
  uint uVar11;
  undefined4 uVar12;
  int *piVar13;
  long lVar14;
  int iVar15;
  int iVar16;
  ulong uVar17;
  int iVar18;
  ulong uVar19;
  int iVar20;
  
  if ((0 < *(int *)(param_2 + 0x10)) && (*(int *)(param_2 + 0x70) <= *(int *)(param_2 + 0x10))) {
    _printk(&DAT_001093dd,*param_1,"mmi_update_charger_status",**(undefined8 **)(param_2 + 0x68));
    ipc_log_string(param_1[0x51],"E %s: %s: [C:%s]: trigger shutdown, vbat=%d, empty_vbat=%d\n",
                   *param_1,"mmi_update_charger_status",**(undefined8 **)(param_2 + 0x68),
                   *(undefined4 *)(param_2 + 0x70),*(undefined4 *)(param_2 + 0x10));
    *(undefined1 *)((long)param_1 + 0x5a4) = 1;
  }
  if ((*(char *)((long)param_1 + 0x124) != '\0') && (*(char *)((long)param_1 + 0x109) != '\0')) {
    iVar15 = *(int *)(param_2 + 0x60);
    if (iVar15 == 1) {
LAB_00101534:
      if ((*(int *)(param_2 + 0x78) <= *(int *)(param_1 + 0x26)) && (iVar15 != 0)) {
        *(undefined4 *)(param_2 + 0x60) = 0;
      }
    }
    else if ((*(int *)(param_2 + 0x78) < *(int *)((long)param_1 + 300)) ||
            (*(int *)(param_2 + 0x70) < *(int *)(param_1 + 0x25))) {
      if (iVar15 != 0) goto LAB_00101534;
    }
    else {
      *(undefined4 *)(param_2 + 0x60) = 1;
      _printk(&DAT_00108b35,*param_1,"mmi_update_charger_status");
      ipc_log_string(param_1[0x51],"W %s: %s: Factory Mode/Image so Limiting Charging!!!\n",*param_1
                     ,"mmi_update_charger_status");
    }
  }
  if (param_1 != (undefined8 *)0x0) {
    iVar2 = *(int *)(param_2 + 0x7c);
    iVar3 = *(int *)(param_2 + 0x70);
    uVar4 = *(uint *)(param_2 + 0x58);
    piVar13 = *(int **)(param_2 + 0x30);
    iVar15 = *(int *)(param_1 + 0x24);
    if (piVar13 == (int *)0x0) {
      uVar11 = 0;
      if (iVar15 < 0x2f) {
        iVar15 = 0x3c;
      }
    }
    else {
      uVar11 = *(uint *)(param_2 + 0x2c);
      if (iVar15 < 0x2f) {
        iVar15 = *(int *)((long)piVar13 +
                         (-(ulong)(uVar11 - 1 >> 0x1f) & 0xfffffff000000000 |
                         (ulong)(uVar11 - 1) << 4));
      }
      if (uVar4 == 0xc) {
        uVar9 = (ulong)uVar11;
        do {
          iVar15 = (int)uVar9;
          uVar6 = iVar15 - 1;
          uVar9 = (ulong)uVar6;
          if ((int)uVar6 < 0) {
            if (iVar2 < -0x14) goto LAB_001019d0;
            if (0 < (int)uVar11) {
              uVar9 = 0;
              uVar10 = 0;
              piVar8 = piVar13 + 1;
              goto LAB_00101748;
            }
            uVar10 = 0;
            goto LAB_00101a4c;
          }
          iVar5 = piVar13[uVar9 * 4];
        } while (iVar2 < iVar5);
        if (iVar15 == 0xb) {
LAB_00101884:
          uVar10 = 10;
        }
        else {
          if (iVar15 == 0xc) {
            uVar10 = 0;
          }
          else {
            if (iVar5 == *(int *)((long)piVar13 +
                                 (-(ulong)(uVar11 - 1 >> 0x1f) & 0xfffffff000000000 |
                                 (ulong)(uVar11 - 1) << 4))) goto LAB_00101884;
            uVar10 = (ulong)uVar6;
            do {
              uVar6 = (int)uVar10 + 1;
              uVar10 = (ulong)uVar6;
              if ((int)uVar11 <= (int)uVar6) goto LAB_00101884;
            } while (*(int *)((long)piVar13 +
                             (-(ulong)(uVar6 >> 0x1f) & 0xfffffff000000000 | uVar10 << 4)) <= iVar5)
            ;
          }
          iVar15 = (int)uVar10;
          uVar9 = uVar10;
          if (iVar15 < (int)uVar11) {
            lVar14 = (long)(int)uVar11 - (long)iVar15;
            piVar8 = piVar13 + (long)iVar15 * 4 + 1;
            do {
              if ((piVar13[(long)iVar15 * 4] == piVar8[-1]) && (uVar10 = uVar9, iVar3 < *piVar8))
              goto LAB_00101760;
              uVar9 = (ulong)((int)uVar9 + 1);
              piVar8 = piVar8 + 4;
              lVar14 = lVar14 + -1;
            } while (lVar14 != 0);
          }
          else {
LAB_00101760:
            uVar10 = uVar9 & 0xffffffff;
          }
        }
        goto LAB_00101a4c;
      }
    }
    if (uVar4 != 10) {
      if (uVar4 == 0xb) {
        if (iVar2 < -0x12) goto LAB_001016e4;
        if (uVar11 != 0) {
          if ((int)uVar11 < 1) {
            uVar10 = 0;
          }
          else {
            uVar9 = 0;
            uVar10 = 0;
            piVar8 = piVar13 + 1;
            do {
              if (*piVar13 == piVar8[-1]) {
                if (iVar3 < *piVar8) goto LAB_00101934;
                uVar10 = uVar9 & 0xffffffff;
              }
              uVar9 = uVar9 + 1;
              piVar8 = piVar8 + 4;
            } while (uVar11 != uVar9);
          }
          goto LAB_00101938;
        }
        goto LAB_0010176c;
      }
      if (piVar13 == (int *)0x0) {
        if (iVar2 < -0x14) goto LAB_001019d0;
        uVar11 = 0;
        if (iVar15 <= iVar2) {
          uVar11 = 10;
        }
        uVar10 = (ulong)uVar11;
      }
      else {
        uVar9 = (ulong)(uVar11 - 1);
        iVar5 = piVar13[(long)(int)uVar4 * 4];
        if (iVar5 == *(int *)((long)piVar13 +
                             (-(ulong)(uVar11 - 1 >> 0x1f) & 0xfffffff000000000 | uVar9 << 4))) {
          uVar10 = 10;
LAB_001018a0:
          if (iVar5 != *piVar13) {
            uVar9 = (ulong)uVar4;
            do {
              uVar6 = (int)uVar9 - 1;
              uVar9 = (ulong)uVar6;
              if ((int)uVar6 < 0) goto LAB_001018ac;
            } while (iVar5 <= piVar13[uVar9 * 4]);
            goto LAB_001018d0;
          }
LAB_001018ac:
          uVar17 = 0xb;
        }
        else {
          uVar17 = (ulong)uVar4;
          do {
            uVar6 = (int)uVar17 + 1;
            uVar17 = (ulong)uVar6;
            if ((int)uVar11 <= (int)uVar6) {
              uVar10 = 10;
              goto LAB_00101898;
            }
            iVar16 = *(int *)((long)piVar13 +
                             (-(ulong)(uVar6 >> 0x1f) & 0xfffffff000000000 | uVar17 << 4));
          } while (iVar16 <= iVar5);
          piVar8 = piVar13 + (long)(int)uVar6 * 4 + 1;
          lVar14 = (long)(int)uVar11 - (long)(int)uVar6;
          uVar19 = (ulong)uVar6;
          do {
            uVar10 = uVar17;
            iVar18 = (int)uVar10;
            if ((iVar16 == piVar8[-1]) && (uVar19 = uVar10, iVar3 < *piVar8)) break;
            uVar10 = uVar19;
            piVar8 = piVar8 + 4;
            lVar14 = lVar14 + -1;
            uVar19 = uVar10;
            uVar17 = (ulong)(iVar18 + 1);
          } while (lVar14 != 0);
LAB_00101898:
          if (uVar4 != 10) goto LAB_001018a0;
LAB_001018d0:
          uVar17 = uVar9;
          if (0 < (int)uVar9) {
            uVar19 = 0;
            piVar8 = piVar13 + 1;
            do {
              if (piVar13[uVar9 * 4] == piVar8[-1]) {
                if (iVar3 < *piVar8) {
                  uVar17 = uVar19 & 0xffffffff;
                  break;
                }
                uVar17 = uVar19 & 0xffffffff;
              }
              uVar19 = uVar19 + 1;
              piVar8 = piVar8 + 4;
            } while (uVar9 != uVar19);
          }
        }
        iVar16 = (int)uVar17;
        if ((int)uVar10 == 10) {
          iVar18 = 0;
          if (iVar16 != 0xb) goto LAB_00101980;
LAB_001019a0:
          iVar20 = 0;
          iVar16 = -0x14;
        }
        else {
          iVar18 = piVar13[(long)(int)uVar10 * 4 + 2];
          if (iVar16 == 0xb) goto LAB_001019a0;
LAB_00101980:
          iVar20 = (piVar13 + (long)iVar16 * 4)[2];
          iVar16 = piVar13[(long)iVar16 * 4];
        }
        iVar1 = iVar5 + 2;
        if (iVar18 <= piVar13[(long)(int)uVar4 * 4 + 2]) {
          iVar1 = iVar5;
        }
        iVar18 = iVar16 + -2;
        if (iVar20 <= piVar13[(long)(int)uVar4 * 4 + 2]) {
          iVar18 = iVar16;
        }
        if (iVar2 < -0x14) {
LAB_001019d0:
          uVar10 = 0xb;
        }
        else {
          if (iVar2 < iVar15) {
            if (((iVar2 < iVar1) && (uVar10 = uVar17, iVar18 <= iVar2)) &&
               (uVar10 = (ulong)uVar4, 0 < (int)uVar11)) {
              uVar9 = 0;
              piVar8 = piVar13 + 1;
              uVar10 = (ulong)uVar4;
              do {
                if (iVar5 == piVar8[-1]) {
                  if (iVar3 < *piVar8) goto LAB_00101760;
                  uVar10 = uVar9 & 0xffffffff;
                }
                uVar9 = uVar9 + 1;
                piVar8 = piVar8 + 4;
              } while (uVar11 != uVar9);
            }
            goto LAB_00101a4c;
          }
          uVar10 = 10;
        }
      }
      piVar13 = (int *)0x0;
      *(int *)(param_2 + 0x58) = (int)uVar10;
      goto LAB_00101a68;
    }
    if (iVar15 + -2 < iVar2) {
LAB_001016e4:
      uVar10 = (ulong)uVar4;
      if (piVar13 != (int *)0x0) goto LAB_00101a50;
      *(undefined8 *)(param_2 + 0x50) = 0;
      goto LAB_00101ac4;
    }
    if (uVar11 != 0) {
      uVar11 = uVar11 - 1;
      if ((int)uVar11 < 1) {
        uVar10 = (ulong)uVar11;
      }
      else {
        uVar9 = 0;
        piVar8 = piVar13 + 1;
        uVar10 = (ulong)uVar11;
        do {
          if (piVar13[(ulong)uVar11 * 4] == piVar8[-1]) {
            if (iVar3 < *piVar8) goto LAB_00101934;
            uVar10 = uVar9 & 0xffffffff;
          }
          uVar9 = uVar9 + 1;
          piVar8 = piVar8 + 4;
        } while (uVar11 != uVar9);
      }
      goto LAB_00101938;
    }
LAB_0010176c:
    uVar10 = 0;
    *(undefined4 *)(param_2 + 0x58) = 0;
    if (piVar13 != (int *)0x0) goto LAB_00101a64;
    uVar10 = 0;
    *(undefined8 *)(param_2 + 0x50) = 0;
    goto LAB_00101a74;
  }
  _printk(&DAT_00107cfe);
  goto LAB_00101ac4;
LAB_00101934:
  uVar10 = uVar9 & 0xffffffff;
LAB_00101938:
  *(int *)(param_2 + 0x58) = (int)uVar10;
  if (piVar13 != (int *)0x0) goto LAB_00101a50;
  piVar13 = (int *)0x0;
  goto LAB_00101a68;
LAB_00101748:
  do {
    if (*piVar13 == piVar8[-1]) {
      if (iVar3 < *piVar8) goto LAB_00101760;
      uVar10 = uVar9 & 0xffffffff;
    }
    uVar9 = uVar9 + 1;
    piVar8 = piVar8 + 4;
  } while (uVar11 != uVar9);
LAB_00101a4c:
  *(int *)(param_2 + 0x58) = (int)uVar10;
LAB_00101a50:
  if (((uint)uVar10 & 0xfffffffe) == 10) {
    piVar13 = (int *)0x0;
  }
  else {
LAB_00101a64:
    piVar13 = piVar13 + uVar10 * 4;
  }
LAB_00101a68:
  *(int **)(param_2 + 0x50) = piVar13;
  if (uVar4 != (uint)uVar10) {
LAB_00101a74:
    _printk(&DAT_0010959b,*param_1,"mmi_get_temp_zone",**(undefined8 **)(param_2 + 0x68),uVar4,
            uVar10);
    ipc_log_string(param_1[0x51],"I %s: %s: [C:%s]: temp zone switch %x -> %x\n",*param_1,
                   "mmi_get_temp_zone",**(undefined8 **)(param_2 + 0x68),uVar4,
                   *(undefined4 *)(param_2 + 0x58));
  }
LAB_00101ac4:
  if (*(int *)(param_2 + 0xbc) == 0) {
    uVar12 = 6;
    goto LAB_00101af4;
  }
  if (((*(uint *)(param_2 + 0x58) & 0xfffffffe) == 10) || (*(int *)(param_2 + 0x60) == 1)) {
LAB_00101af0:
    uVar12 = 5;
    goto LAB_00101af4;
  }
  if (*(int *)((long)param_1 + 0x104) != 0) {
    *(undefined4 *)(param_2 + 0x5c) = 4;
    if (*(char *)(param_2 + 0x4c) == '\0') {
      if (*(int *)(param_2 + 0x70) + 0x32 < *(int *)(param_2 + 0x28)) {
        uVar9 = 0;
      }
      else {
        pcVar7 = *(code **)(*(long *)(param_2 + 0x68) + 0x28);
        if (*(int *)(pcVar7 + -4) != 0x7850c00b) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x101c68);
          (*pcVar7)();
        }
        uVar9 = (*pcVar7)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),
                          *(undefined4 *)(param_2 + 0x18));
        if (*(char *)(param_2 + 0x4c) != '\0') goto LAB_00101c98;
      }
      if ((*(int *)((long)param_1 + 0x104) <= *(int *)(param_2 + 0x78)) || ((uVar9 & 1) != 0)) {
        *(int *)(param_2 + 0x48) = *(int *)(param_2 + 0x78);
        *(undefined1 *)(param_2 + 0x4c) = 1;
      }
    }
    else {
LAB_00101c98:
      if (*(int *)(param_2 + 0x78) <= *(int *)(param_2 + 0x48) + -5) {
        *(undefined1 *)(param_2 + 0x4c) = 0;
        *(undefined1 *)(param_2 + 0xe6) = 1;
      }
    }
    goto switchD_00101c0c_caseD_4;
  }
  lVar14 = *(long *)(param_2 + 0x50);
  if (lVar14 == 0) goto LAB_00101bb8;
  switch(*(undefined4 *)(param_2 + 0x5c)) {
  case 0:
    if (*(int *)(lVar14 + 4) == 0) {
      uVar12 = 1;
      *(undefined1 *)(param_2 + 0xe6) = 1;
      if (*(int *)(param_2 + 0x1c) <= *(int *)(param_2 + 0x70) + 0x32) goto LAB_00101af4;
      break;
    }
    if (*(int *)(param_2 + 0x70) + 0x32 < *(int *)(lVar14 + 4)) {
      *(undefined4 *)(param_2 + 0x5c) = 0;
      *(undefined1 *)(param_2 + 0xe6) = 1;
      goto switchD_00101c0c_caseD_4;
    }
    if (*(int *)(lVar14 + 0xc) != 0) {
      pcVar7 = *(code **)(*(long *)(param_2 + 0x68) + 0x28);
      if (*(int *)(pcVar7 + -4) != 0x7850c00b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x101e10);
        (*pcVar7)();
      }
      uVar9 = (*pcVar7)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50));
      if ((uVar9 & 1) != 0) {
        *(undefined1 *)(param_2 + 0xe6) = 1;
        pcVar7 = *(code **)(*(long *)(param_2 + 0x68) + 0x30);
        if (pcVar7 != (code *)0x0) {
          if (*(int *)(pcVar7 + -4) != -0x672c52fe) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x101e48);
            (*pcVar7)();
          }
          uVar9 = (*pcVar7)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50));
          if ((uVar9 & 1) != 0) {
            *(undefined1 *)(param_2 + 0xe5) = 1;
            _printk(&DAT_00107d8a,*param_1,"mmi_update_charger_status",
                    **(undefined8 **)(param_2 + 0x68));
            ipc_log_string(param_1[0x51],"W %s: %s: [C:%s]: Charge Halt..Toggle\n",*param_1,
                           "mmi_update_charger_status",**(undefined8 **)(param_2 + 0x68));
          }
        }
        *(undefined4 *)(param_2 + 0x5c) = 1;
      }
      goto switchD_00101c0c_caseD_4;
    }
LAB_00101cc4:
    uVar12 = 3;
    goto LAB_00101af4;
  case 1:
    if (*(int *)(lVar14 + 0xc) == 0) goto LAB_00101cc4;
    if ((99 < *(int *)(param_2 + 0x78)) &&
       (*(int *)(param_2 + 0x1c) <= *(int *)(param_2 + 0x70) + 0x32)) {
      pcVar7 = *(code **)(*(long *)(param_2 + 0x68) + 0x28);
      if (*(int *)(pcVar7 + -4) != 0x7850c00b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x101ecc);
        (*pcVar7)();
      }
      uVar9 = (*pcVar7)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),
                        *(undefined4 *)(param_2 + 0x18));
      if ((uVar9 & 1) == 0) goto switchD_00101c0c_caseD_4;
      uVar12 = 2;
      goto LAB_00101af4;
    }
    goto LAB_00101dd8;
  case 2:
    if ((99 < *(int *)(param_2 + 0x78)) &&
       (*(int *)(param_2 + 0x1c) + -100 <= *(int *)(param_2 + 0x70))) goto switchD_00101c0c_caseD_4;
LAB_00101dd8:
    uVar12 = 1;
    *(undefined1 *)(param_2 + 0xe6) = 1;
LAB_00101af4:
    *(undefined4 *)(param_2 + 0x5c) = uVar12;
    goto switchD_00101c0c_caseD_4;
  case 3:
    if ((*(int *)(lVar14 + 0xc) == 0) && (*(int *)(lVar14 + 4) <= *(int *)(param_2 + 0x70) + 0x32))
    {
      pcVar7 = *(code **)(*(long *)(param_2 + 0x68) + 0x28);
      if (*(int *)(pcVar7 + -4) != 0x7850c00b) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x101d34);
        (*pcVar7)();
      }
      uVar9 = (*pcVar7)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),
                        *(undefined4 *)(param_2 + 0x18));
      if ((uVar9 & 1) == 0) goto switchD_00101c0c_caseD_4;
      goto LAB_00101af0;
    }
    break;
  default:
    goto switchD_00101c0c_caseD_4;
  case 5:
    if (*(int *)(lVar14 + 4) != 0) {
      iVar15 = 100;
      if (*(int *)(param_2 + 0x7c) < 1) {
        iVar15 = 0xfa;
      }
      if (*(int *)(lVar14 + 4) <= iVar15 + *(int *)(param_2 + 0x70)) goto LAB_00101d88;
    }
    break;
  case 6:
    if ((*(int *)(lVar14 + 4) != 0) && (*(int *)(lVar14 + 4) <= *(int *)(param_2 + 0x70) + 0x32)) {
LAB_00101d88:
      if (*(int *)(lVar14 + 0xc) == 0) goto LAB_00101af0;
      uVar12 = 1;
      goto LAB_00101af4;
    }
  }
LAB_00101bb8:
  *(undefined4 *)(param_2 + 0x5c) = 0;
switchD_00101c0c_caseD_4:
  *(int *)(*(long *)(param_2 + 0x108) + 0x10) = *(int *)(*(long *)(param_2 + 0x108) + 0x10) + 1;
  if (*(uint *)(param_2 + 0x5c) < 7) {
    _printk(&DAT_00108942,*param_1,"mmi_update_charger_status",**(undefined8 **)(param_2 + 0x68),
            (&stepchg_str)[*(uint *)(param_2 + 0x5c)],*(undefined4 *)(param_2 + 0x58),
            *(undefined4 *)(param_2 + 0x60),*(undefined1 *)(param_2 + 0x4c));
    if (*(uint *)(param_2 + 0x5c) < 7) {
      ipc_log_string(param_1[0x51],
                     "I %s: %s: [C:%s]: StepChg: %s, TempZone: %d, LimitMode: %d, DemoSuspend: %d\n"
                     ,*param_1,"mmi_update_charger_status",**(undefined8 **)(param_2 + 0x68),
                     (&stepchg_str)[*(uint *)(param_2 + 0x5c)],*(undefined4 *)(param_2 + 0x58),
                     *(undefined4 *)(param_2 + 0x60),*(undefined1 *)(param_2 + 0x4c));
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x101ee0);
  (*pcVar7)();
}



//------------------------------------------------------------
// mmi_configure_charger @ 00101ee0 size=780
// signature: undefined mmi_configure_charger(void)
// callers: [mmi_get_charger_configure, mmi_charger_heartbeat_work]
//------------------------------------------------------------

void mmi_configure_charger(undefined8 *param_1,long param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  byte bVar4;
  int *piVar5;
  long lVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  int iVar10;
  
  switch(*(undefined4 *)(param_2 + 0x5c)) {
  case 0:
  case 3:
    lVar6 = *(long *)(param_2 + 0x50);
    if (lVar6 == 0) {
      piVar5 = (int *)(param_2 + 0x20);
      *(int *)(param_2 + 0xd4) = *(int *)(param_2 + 0x24) + *(int *)(param_2 + 0x1c);
    }
    else {
      iVar7 = *(int *)(lVar6 + 4);
      if (iVar7 == 0) {
        iVar7 = *(int *)(param_2 + 0x1c);
      }
      piVar5 = (int *)(lVar6 + 8);
      *(int *)(param_2 + 0xd4) = *(int *)(param_2 + 0x24) + iVar7;
    }
    goto LAB_00101fc8;
  case 1:
    iVar7 = *(int *)(param_2 + 0x24) + *(int *)(param_2 + 0x1c);
    break;
  case 2:
    bVar4 = 1;
    *(undefined4 *)(param_2 + 0xd0) = 0xffffffea;
    *(undefined4 *)(param_2 + 0xd4) = *(undefined4 *)(param_2 + 0x1c);
    *(undefined1 *)(param_2 + 0xe4) = 1;
    goto LAB_00102024;
  case 4:
    iVar7 = *(int *)(param_2 + 0x28);
    break;
  case 5:
    bVar4 = 1;
    *(undefined4 *)(param_2 + 0xd0) = 0xffffffea;
    *(undefined4 *)(param_2 + 0xd4) = *(undefined4 *)(param_2 + 0x1c);
    goto LAB_00102024;
  default:
    iVar7 = *(int *)(param_2 + 0x1c);
  }
  *(int *)(param_2 + 0xd4) = iVar7;
  if (*(long *)(param_2 + 0x50) == 0) {
    piVar5 = (int *)(param_2 + 0x20);
  }
  else {
    piVar5 = (int *)(*(long *)(param_2 + 0x50) + 0xc);
  }
LAB_00101fc8:
  iVar7 = *piVar5;
  *(int *)(param_2 + 0xd0) = iVar7;
  if (iVar7 < 0) {
    bVar4 = 1;
  }
  else {
    lVar6 = 0;
    uVar8 = 0xffffffea;
    iVar7 = 0x7fffffff;
    do {
      if (param_1[lVar6 + 0x94] != 0) {
        iVar10 = *(int *)((long)param_1 + lVar6 * 4 + 0x420);
        uVar2 = (int)lVar6;
        if (iVar7 <= iVar10) {
          iVar10 = iVar7;
          uVar2 = uVar8;
        }
        uVar8 = uVar2;
        iVar7 = iVar10;
      }
      lVar6 = lVar6 + 1;
    } while (lVar6 != 0x20);
    bVar4 = (byte)~(byte)((uint)uVar8 >> 0x18) >> 7;
  }
LAB_00102024:
  *(byte *)(param_2 + 0xe7) = bVar4;
  if (*(char *)(param_1 + 0x21) != '\0') {
    *(undefined2 *)(param_2 + 0xe5) = 0;
    *(undefined1 *)(param_2 + 0xe7) = 1;
    *(undefined8 *)(param_2 + 0xd0) = 0x113000000bb8;
  }
  if ((*(char *)((long)param_1 + 0x10b) == '\0') && (*(char *)(param_2 + 0x4c) == '\0')) {
    lVar6 = 0;
    iVar7 = -0x16;
    iVar10 = 0x7fffffff;
    do {
      if (param_1[lVar6 + 99] != 0) {
        iVar1 = *(int *)((long)param_1 + lVar6 * 4 + 0x298);
        iVar3 = (int)lVar6;
        if (iVar10 <= iVar1) {
          iVar1 = iVar10;
          iVar3 = iVar7;
        }
        iVar7 = iVar3;
        iVar10 = iVar1;
      }
      lVar6 = lVar6 + 1;
    } while (lVar6 != 0x20);
    if (iVar7 < 0) goto LAB_001020a4;
  }
  *(undefined1 *)(param_2 + 0xe8) = 1;
LAB_001020a4:
  if (*(char *)((long)param_1 + 0x10c) != '\0') {
    *(undefined1 *)(param_2 + 0xe7) = 0;
  }
  lVar6 = *(long *)(*(long *)(param_2 + 0x108) + 0x28);
  if (lVar6 != 0) {
    pcVar9 = *(code **)(*(long *)(param_2 + 0x68) + 0x48);
    if (pcVar9 != (code *)0x0) {
      if (*(int *)(pcVar9 + -4) != -0xe353508) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x1020e8);
        (*pcVar9)();
      }
      (*pcVar9)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),*(undefined8 *)(lVar6 + 0x30));
    }
  }
  pcVar9 = *(code **)(*(long *)(param_2 + 0x68) + 0x40);
  if (*(int *)(pcVar9 + -4) != -0x558c1c5b) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x102114);
    (*pcVar9)();
  }
  (*pcVar9)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),param_2 + 0xec);
  pcVar9 = *(code **)(*(long *)(param_2 + 0x68) + 0x20);
  if (*(int *)(pcVar9 + -4) != 0x566feed3) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x102140);
    (*pcVar9)();
  }
  (*pcVar9)(*(undefined8 *)(*(long *)(param_2 + 0x68) + 0x50),(int *)(param_2 + 0xd0));
  _printk(&DAT_00108f48,*param_1,"mmi_configure_charger",**(undefined8 **)(param_2 + 0x68),
          *(undefined4 *)(param_2 + 0xd4),*(undefined4 *)(param_2 + 0xd0),
          *(undefined1 *)(param_2 + 0xe7),*(undefined1 *)(param_2 + 0xe8),
          *(undefined1 *)(param_2 + 0xe5),*(undefined1 *)(param_2 + 0xe4),
          *(undefined4 *)(param_2 + 0xd8));
  ipc_log_string(param_1[0x51],
                 "I %s: %s: [C:%s]: FV=%d, FCC=%d, CDIS=%d, CSUS=%d, CRES=%d, CFULL=%d, MAX_FV=%d\n"
                 ,*param_1,"mmi_configure_charger",**(undefined8 **)(param_2 + 0x68),
                 *(undefined4 *)(param_2 + 0xd4),*(undefined4 *)(param_2 + 0xd0),
                 *(undefined1 *)(param_2 + 0xe7),*(undefined1 *)(param_2 + 0xe8),
                 *(undefined1 *)(param_2 + 0xe5),*(undefined1 *)(param_2 + 0xe4),
                 *(undefined4 *)(param_2 + 0xd8));
  return;
}



//------------------------------------------------------------
// mmi_update_battery_status @ 001021ec size=2824
// signature: undefined mmi_update_battery_status(void)
// callers: [mmi_get_charger_configure, mmi_charger_heartbeat_work]
//------------------------------------------------------------

void mmi_update_battery_status(undefined8 *param_1)

{
  long *plVar1;
  int *piVar2;
  undefined8 *puVar3;
  char *pcVar4;
  int iVar5;
  code *pcVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  undefined *puVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  undefined8 *puVar21;
  int iVar22;
  int iVar23;
  undefined8 *puVar24;
  int iVar25;
  undefined4 *puVar26;
  uint uVar27;
  int iVar28;
  undefined8 in_stack_ffffffffffffff20;
  undefined4 uVar29;
  undefined *in_stack_ffffffffffffff28;
  undefined8 in_stack_ffffffffffffff50;
  undefined4 uVar30;
  
  mutex_lock();
  uVar29 = (undefined4)((ulong)in_stack_ffffffffffffff20 >> 0x20);
  uVar12 = (undefined4)((ulong)in_stack_ffffffffffffff28 >> 0x20);
  uVar30 = (undefined4)((ulong)in_stack_ffffffffffffff50 >> 0x20);
  puVar11 = param_1 + 2;
  puVar24 = (undefined8 *)*puVar11;
  if (puVar24 == puVar11) {
    bVar8 = false;
    bVar7 = false;
    iVar23 = 0;
    uVar13 = 0;
    iVar18 = 0;
    uVar27 = 0;
  }
  else {
    uVar27 = 0;
    iVar23 = 0;
    bVar7 = false;
    bVar8 = false;
    uVar19 = 0;
    iVar22 = 0;
    do {
      uVar29 = (undefined4)((ulong)in_stack_ffffffffffffff20 >> 0x20);
      puVar26 = (undefined4 *)puVar24[-1];
      if (puVar26[4] == puVar26[5]) {
        uVar12 = 2;
        puVar26[6] = 0;
        puVar26[1] = 2;
        if (*(int *)(puVar24 + -0x17) != 10) {
          if (*(int *)(puVar24 + -0x17) == 0xb) {
            uVar12 = 6;
          }
          else if (*(int *)((long)puVar24 + -0x94) < 0x2d) {
            if (*(int *)((long)puVar24 + -0x94) < 1) {
              uVar12 = 6;
              if (*(int *)((long)puVar24 + -0xb4) != 5) {
                uVar12 = 1;
              }
            }
            else {
              uVar12 = 1;
            }
          }
          else {
            uVar12 = 1;
            if (*(int *)((long)puVar24 + -0xb4) == 5) {
              uVar12 = 2;
            }
          }
        }
        *puVar26 = uVar12;
        iVar18 = *(int *)((long)puVar24 + -0x84);
        if (0 < iVar18) {
          iVar17 = 0;
          if (iVar18 != 0) {
            iVar17 = (*(int *)(puVar24 + -0x11) * 100) / iVar18;
          }
          puVar26[2] = iVar17;
        }
        iVar18 = *(int *)(puVar24 + -0x13);
        iVar17 = iVar18 - puVar26[7];
        if (iVar17 != 0 && (int)puVar26[7] <= iVar18) {
          puVar26[3] = iVar17 + puVar26[3];
          iVar18 = *(int *)(puVar24 + -0x13);
        }
        puVar26[7] = iVar18;
        *(undefined8 **)(puVar26 + 0xc) = puVar24 + -0x14;
      }
      if (*(int *)((long)puVar24 + -0x54) == 0) {
        uVar13 = 0;
      }
      else {
        uVar14 = *(uint *)(puVar24 + -0xb);
        if ((int)uVar14 < 0x9c4) {
          uVar13 = 2;
        }
        else if (uVar14 >> 2 < 0xc35) {
          uVar13 = 1;
        }
        else if (uVar14 >> 3 < 0xc35) {
          uVar13 = 3;
        }
        else {
          uVar13 = 4;
          if (0x270 < uVar14 >> 6) {
            uVar13 = 5;
          }
        }
      }
      uVar14 = puVar26[6];
      if ((int)puVar26[6] < (int)uVar13) {
        puVar26[6] = uVar13;
        uVar14 = uVar13;
      }
      iVar18 = *(int *)((long)puVar24 + -0x5c);
      uVar13 = *(uint *)(puVar24 + -0xb);
      if ((int)*(uint *)(puVar24 + -0xb) <= (int)uVar19) {
        uVar13 = uVar19;
      }
      iVar17 = *(int *)(puVar24 + -0x12);
      if (iVar18 <= iVar22 || iVar18 == 0xff) {
        iVar18 = iVar22;
      }
      if (((iVar17 == 4) || (iVar22 = puVar26[1], iVar22 == 4)) ||
         (*(int *)((long)puVar24 + -0xb4) == 2)) {
        uVar12 = 4;
      }
      else if ((iVar17 == 1) || (iVar22 == 1)) {
        uVar12 = 1;
      }
      else if ((iVar17 == 3) || (iVar22 == 3)) {
        uVar12 = 3;
      }
      else {
        uVar12 = 2;
      }
      iVar22 = puVar26[4] + -1;
      puVar26[1] = uVar12;
      puVar26[4] = iVar22;
      if (iVar22 < 1) {
        puVar26[4] = 0;
        if ((int)uVar27 <= (int)uVar14) {
          uVar27 = uVar14;
        }
        if (*(char *)param_1[0x50] != '\0') {
          if (5 < uVar14) goto LAB_00102cf0;
          puVar10 = (&charge_rate)[uVar14];
          _printk(&DAT_001078d2,*param_1,"mmi_update_battery_status",puVar26 + 0xe,*puVar26,uVar12,
                  puVar26[2],puVar26[3],puVar10);
          uVar29 = (undefined4)((ulong)puVar10 >> 0x20);
          uVar14 = puVar26[6];
        }
        if (5 < uVar14) goto LAB_00102cf0;
        in_stack_ffffffffffffff28 = (&charge_rate)[uVar14];
        in_stack_ffffffffffffff20 = CONCAT44(uVar29,puVar26[3]);
        ipc_log_string(param_1[0x51],
                       "D %s: %s: [B:%s]: health:%d, status:%d, age:%d, cycles:%d, rate:%s\n",
                       *param_1,"mmi_update_battery_status",puVar26 + 0xe,*puVar26,puVar26[1],
                       puVar26[2],in_stack_ffffffffffffff20,in_stack_ffffffffffffff28);
        if (bVar8 == false) goto LAB_00102470;
LAB_001023f0:
        bVar8 = true;
        if (bVar7 == false) goto LAB_001023f8;
LAB_00102480:
        bVar7 = true;
      }
      else {
        if (bVar8 != false) goto LAB_001023f0;
LAB_00102470:
        bVar8 = *(int *)((long)puVar24 + -0x44) != 0;
        if (bVar7 != false) goto LAB_00102480;
LAB_001023f8:
        bVar7 = *(int *)((long)puVar24 + -0x4c) != 0;
      }
      if (iVar23 == 0) {
        iVar23 = *(int *)(puVar24 + -9);
      }
      uVar29 = (undefined4)((ulong)in_stack_ffffffffffffff20 >> 0x20);
      uVar12 = (undefined4)((ulong)in_stack_ffffffffffffff28 >> 0x20);
      uVar30 = (undefined4)((ulong)in_stack_ffffffffffffff50 >> 0x20);
      puVar24 = (undefined8 *)*puVar24;
      uVar19 = uVar13;
      iVar22 = iVar18;
    } while (puVar24 != puVar11);
  }
  puVar24 = param_1 + 10;
  puVar11 = (undefined8 *)*puVar24;
  if (puVar11 == puVar24) {
    iVar22 = 0;
    iVar25 = 0;
    iVar28 = 0;
    iVar17 = 0;
    iVar20 = -1;
    uVar19 = 0xffffffff;
    uVar14 = 0xffffffff;
    *(undefined8 *)((long)param_1 + 0xd4) = 0;
  }
  else {
    uVar15 = 0;
    uVar14 = 0;
    puVar21 = puVar11;
    do {
      plVar1 = puVar21 + -3;
      puVar21 = (undefined8 *)*puVar21;
      iVar22 = *(int *)(*plVar1 + 0x18);
      uVar15 = uVar15 + iVar22 * *(int *)(*plVar1 + 8);
      uVar14 = iVar22 + uVar14;
    } while (puVar21 != puVar24);
    uVar19 = 0xffffffff;
    if ((0 < (int)uVar14) && (-1 < (int)uVar15)) {
      uVar19 = 0;
      if (uVar14 != 0) {
        uVar19 = uVar15 / uVar14;
      }
      if (99 < (int)uVar19) {
        uVar19 = 100;
      }
    }
    iVar25 = 0;
    puVar21 = puVar11;
    do {
      iVar22 = *(int *)((long)puVar21 + -0x44);
      if (iVar22 == 1) {
        iVar25 = 1;
        break;
      }
      puVar21 = (undefined8 *)*puVar21;
      iVar17 = 2;
      if (iVar25 != 2 && iVar22 != 2) {
        iVar17 = iVar22;
      }
      bVar9 = iVar25 != 3;
      iVar25 = 3;
      if (bVar9 && iVar22 != 3) {
        iVar25 = iVar17;
      }
    } while (puVar21 != puVar24);
    uVar16 = 0;
    uVar15 = 0;
    puVar21 = puVar11;
    do {
      plVar1 = puVar21 + -3;
      piVar2 = (int *)((long)puVar21 + -0x3c);
      puVar21 = (undefined8 *)*puVar21;
      uVar16 = uVar16 + *(int *)(*plVar1 + 0x18) * *piVar2;
      uVar15 = *(int *)(*plVar1 + 0x18) + uVar15;
    } while (puVar21 != puVar24);
    uVar14 = 0xffffffff;
    if (((0 < (int)uVar15) && (-1 < (int)uVar16)) && (uVar14 = 0, uVar15 != 0)) {
      uVar14 = uVar16 / uVar15;
    }
    iVar22 = 0;
    iVar17 = 0;
    puVar21 = puVar11;
    do {
      plVar1 = puVar21 + -3;
      puVar21 = (undefined8 *)*puVar21;
      iVar22 = *(int *)(*plVar1 + 0x18) + iVar22;
      iVar17 = *(int *)(*plVar1 + 0x1c) + iVar17;
    } while (puVar21 != puVar24);
    *(int *)((long)param_1 + 0xd4) = iVar22;
    *(int *)(param_1 + 0x1b) = iVar17;
    if (iVar17 < 1 || iVar22 < 1) {
      iVar20 = -1;
    }
    else {
      iVar20 = 0;
      if (iVar17 != 0) {
        iVar20 = (iVar22 * 100) / iVar17;
      }
      if (99 < iVar20) {
        iVar20 = 100;
      }
    }
    iVar17 = 0;
    iVar22 = 0;
    puVar21 = puVar11;
    do {
      puVar3 = puVar21 + -3;
      iVar22 = iVar22 + 1;
      puVar21 = (undefined8 *)*puVar21;
      iVar17 = *(int *)*puVar3 + iVar17;
    } while (puVar21 != puVar24);
    iVar28 = iVar17;
    if ((iVar22 != 0) && (iVar28 = 0, iVar22 != 0)) {
      iVar28 = iVar17 / iVar22;
    }
    iVar22 = 0;
    puVar21 = puVar11;
    do {
      plVar1 = puVar21 + -3;
      puVar21 = (undefined8 *)*puVar21;
      iVar22 = *(int *)(*plVar1 + 4) + iVar22;
    } while (puVar21 != puVar24);
    iVar17 = 0;
    do {
      plVar1 = puVar11 + -3;
      puVar11 = (undefined8 *)*puVar11;
      iVar17 = *(int *)(*plVar1 + 0x20) + iVar17;
    } while (puVar11 != puVar24);
  }
  puVar11 = puVar24;
  do {
    puVar11 = (undefined8 *)*puVar11;
    if (puVar11 == puVar24) goto LAB_00102730;
    iVar5 = *(int *)(puVar11[-3] + 0x14);
  } while (iVar5 == 0);
  if ((iVar5 < 1) || (*(int *)((long)param_1 + 0xf4) == iVar5)) {
LAB_00102730:
    if (-1 < (int)uVar19) goto LAB_00102734;
LAB_00102744:
    bVar9 = false;
  }
  else {
    *(int *)((long)param_1 + 0xf4) = iVar5;
    mmi_notify_charger_event(param_1,6);
    _printk(&DAT_00108c3a,*param_1,"mmi_update_battery_status",iVar5);
    ipc_log_string(param_1[0x51],"I %s: %s: state_of_health is %d\n",*param_1,
                   "mmi_update_battery_status",iVar5);
    if ((int)uVar19 < 0) goto LAB_00102744;
LAB_00102734:
    if (*(uint *)((long)param_1 + 0xb4) == uVar19) goto LAB_00102744;
    bVar9 = true;
    *(uint *)((long)param_1 + 0xb4) = uVar19;
  }
  if (*(int *)((long)param_1 + 0xc4) != iVar25) {
    bVar9 = true;
    *(int *)((long)param_1 + 0xc4) = iVar25;
  }
  if ((-1 < (int)uVar14) && (*(int *)(param_1 + 0x16) / 100 != uVar14 / 100)) {
    bVar9 = true;
    *(uint *)(param_1 + 0x16) = uVar14;
  }
  if ((0 < iVar20) && (*(int *)(param_1 + 0x17) != iVar20)) {
    bVar9 = true;
    *(int *)(param_1 + 0x17) = iVar20;
  }
  if ((0 < iVar28) && (*(int *)((long)param_1 + 0xbc) != iVar28)) {
    *(int *)((long)param_1 + 0xbc) = iVar28;
  }
  if (*(int *)(param_1 + 0x18) != iVar22) {
    *(int *)(param_1 + 0x18) = iVar22;
  }
  if (*(int *)(param_1 + 0x1a) != iVar17) {
    *(int *)(param_1 + 0x1a) = iVar17;
  }
  if (*(uint *)(param_1 + 0x1c) != uVar27) {
    *(uint *)(param_1 + 0x1c) = uVar27;
    mmi_notify_charger_event(param_1,0);
    if (5 < *(uint *)(param_1 + 0x1c)) goto LAB_00102cf0;
    _printk(&DAT_001084b8,*param_1,"mmi_update_battery_status",
            (&charge_rate)[*(uint *)(param_1 + 0x1c)]);
    if (5 < *(uint *)(param_1 + 0x1c)) goto LAB_00102cf0;
    ipc_log_string(param_1[0x51],"E %s: %s: %s charger is detected\n",*param_1,
                   "mmi_update_battery_status",(&charge_rate)[*(uint *)(param_1 + 0x1c)]);
    bVar9 = true;
  }
  if ((bool)*(char *)((long)param_1 + 0xe9) != bVar7) {
    *(bool *)((long)param_1 + 0xe9) = bVar7;
    bVar9 = true;
    mmi_notify_charger_event(param_1,1);
    pcVar4 = "present";
    if (bVar7 == false) {
      pcVar4 = "absent";
    }
    _printk(&DAT_00108880,*param_1,"mmi_update_battery_status",pcVar4);
    ipc_log_string(param_1[0x51],"I %s: %s: lpd is %s\n",*param_1,"mmi_update_battery_status",pcVar4
                  );
  }
  if (*(int *)((long)param_1 + 0xec) != iVar23) {
    _printk(&DAT_001074e1,*param_1,"mmi_update_battery_status",*(int *)((long)param_1 + 0xec),iVar23
           );
    ipc_log_string(param_1[0x51],"I %s: %s: CID status transit: %d -> %d\n",*param_1,
                   "mmi_update_battery_status",*(undefined4 *)((long)param_1 + 0xec),iVar23);
    *(int *)((long)param_1 + 0xec) = iVar23;
    mmi_notify_charger_event(param_1,7);
    bVar9 = true;
  }
  if ((bool)*(char *)(param_1 + 0x1d) != bVar8) {
    *(bool *)(param_1 + 0x1d) = bVar8;
    mmi_notify_charger_event(param_1,2);
    pcVar4 = "present";
    if (bVar8 == false) {
      pcVar4 = "absent";
    }
    _printk(&DAT_001099eb,*param_1,"mmi_update_battery_status",pcVar4);
    ipc_log_string(param_1[0x51],"I %s: %s: vbus is %s\n",*param_1,"mmi_update_battery_status",
                   pcVar4);
    bVar9 = true;
  }
  if (*(int *)(param_1 + 0x1e) / 1000 != uVar13 / 1000) {
    mmi_notify_charger_event(param_1,4);
    *(uint *)(param_1 + 0x1e) = uVar13;
    mmi_notify_charger_event(param_1,3);
    _printk(&DAT_001095c8,*param_1,"mmi_update_battery_status",uVar13);
    ipc_log_string(param_1[0x51],"I %s: %s: charger power is %d mW\n",*param_1,
                   "mmi_update_battery_status",uVar13);
    bVar9 = true;
  }
  if (*(int *)((long)param_1 + 0xe4) != iVar18) {
    *(int *)((long)param_1 + 0xe4) = iVar18;
    mmi_notify_charger_event(param_1,5);
    _printk(&DAT_00107ff8,*param_1,"mmi_update_battery_status",iVar18);
    ipc_log_string(param_1[0x51],"I %s: %s: charger real type is %d\n",*param_1,
                   "mmi_update_battery_status",iVar18);
    bVar9 = true;
  }
  puVar11 = (undefined8 *)*puVar24;
  if (puVar11 == puVar24) {
    iVar23 = 0;
    iVar18 = 0;
  }
  else {
    iVar18 = 0;
    iVar23 = 0;
    do {
      if (iVar23 == 0) {
        iVar23 = *(int *)(puVar11 + -9);
        iVar18 = *(int *)(puVar11[-3] + 0xc);
      }
      else if (iVar18 < *(int *)(puVar11[-3] + 0xc)) {
        iVar23 = *(int *)(puVar11 + -9);
        iVar18 = *(int *)(puVar11[-3] + 0xc);
      }
      puVar11 = (undefined8 *)*puVar11;
    } while (puVar11 != puVar24);
  }
  if ((*(int *)(param_1 + 0x19) == iVar23) && (*(int *)((long)param_1 + 0xcc) == iVar18)) {
    if (!bVar9) goto LAB_001028f4;
  }
  else {
    *(int *)(param_1 + 0x19) = iVar23;
    *(int *)((long)param_1 + 0xcc) = iVar18;
  }
  power_supply_changed(param_1[0x12]);
  if (*(uint *)(param_1 + 0x1c) < 6) {
    _printk(&DAT_0010815d,*param_1,"mmi_update_battery_status",*(undefined4 *)((long)param_1 + 0xb4)
            ,*(undefined4 *)((long)param_1 + 0xc4),*(undefined4 *)((long)param_1 + 0xcc),
            *(undefined4 *)(param_1 + 0x19),*(undefined4 *)((long)param_1 + 0xf4),
            CONCAT44(uVar29,*(undefined4 *)(param_1 + 0x17)),
            CONCAT44(uVar12,*(undefined4 *)(param_1 + 0x16)),*(undefined4 *)((long)param_1 + 0xbc),
            *(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x1a),
            (&charge_rate)[*(uint *)(param_1 + 0x1c)],
            CONCAT44(uVar30,(uint)*(byte *)((long)param_1 + 0xe9)),
            *(undefined4 *)((long)param_1 + 0xec),*(undefined1 *)(param_1 + 0x1d));
    if (*(uint *)(param_1 + 0x1c) < 6) {
      ipc_log_string(param_1[0x51],
                     "I %s: %s: Combo status: soc:%d, status:%d, temp:%d, health:%d, soh %d, age:%d, cycles:%d, voltage:%d, current:%d, counter:%d, rate:%s, lpd:%d, cid:%d, vbus:%d\n"
                     ,*param_1,"mmi_update_battery_status",*(undefined4 *)((long)param_1 + 0xb4),
                     *(undefined4 *)((long)param_1 + 0xc4),*(undefined4 *)((long)param_1 + 0xcc),
                     *(undefined4 *)(param_1 + 0x19),*(undefined4 *)((long)param_1 + 0xf4),
                     *(undefined4 *)(param_1 + 0x17),*(undefined4 *)(param_1 + 0x16),
                     *(undefined4 *)((long)param_1 + 0xbc),*(undefined4 *)(param_1 + 0x18),
                     *(undefined4 *)(param_1 + 0x1a),(&charge_rate)[*(uint *)(param_1 + 0x1c)],
                     *(undefined1 *)((long)param_1 + 0xe9),*(undefined4 *)((long)param_1 + 0xec),
                     *(undefined1 *)(param_1 + 0x1d));
LAB_001028f4:
      mutex_unlock(param_1 + 0xc);
      return;
    }
  }
LAB_00102cf0:
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x102cf4);
  (*pcVar6)();
}



//------------------------------------------------------------
// mmi_vote_charging_disable @ 00102cf8 size=76
// signature: undefined mmi_vote_charging_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_vote_charging_disable(undefined8 param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = mmi_vote(this_chip + 0x418,param_1,param_2 & 1);
  }
  return uVar1;
}



//------------------------------------------------------------
// mmi_vote @ 00102d44 size=472
// signature: undefined mmi_vote(void)
// callers: [mmi_vote_charging_disable, mmi_vote_charger_suspend, force_charging_disable_store]
//------------------------------------------------------------

undefined8 mmi_vote(undefined8 *param_1,char *param_2,uint param_3)

{
  ulong uVar1;
  undefined8 *puVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  ulong uVar9;
  
  puVar2 = this_chip;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    uVar5 = 0xffffffed;
  }
  else if (param_2 == (char *)0x0) {
    _printk(&DAT_00108fc5,*this_chip,"mmi_vote",*param_1);
    ipc_log_string(puVar2[0x51],"E %s: %s: %s: Invalid voter\n",*puVar2,"mmi_vote",*param_1);
    uVar5 = 0xffffffea;
  }
  else {
    uVar1 = 0;
    uVar9 = 0xffffffea;
    do {
      uVar8 = uVar1;
      uVar7 = (uint)uVar9;
      if ((char *)param_1[uVar8 + 0x11] == (char *)0x0) {
        uVar6 = (uint)uVar8;
      }
      else {
        iVar4 = strcmp((char *)param_1[uVar8 + 0x11],param_2);
        uVar6 = uVar7;
        if (iVar4 == 0) {
          if ((param_3 & 1) == 0) {
            param_1[uVar8 + 0x11] = 0;
          }
          else {
            param_1[uVar8 + 0x11] = param_2;
          }
          if ((uVar8 & 0xffffffe0) == 0) goto LAB_00102eb4;
          goto LAB_00102f18;
        }
      }
      uVar1 = uVar8 + 1;
      if (-1 < (int)uVar7) {
        uVar6 = uVar7;
      }
      uVar8 = (ulong)uVar6;
      uVar9 = uVar8;
    } while (uVar1 != 0x20);
    if ((param_3 & 1) != 0) {
      if ((int)uVar6 < 0) {
        _printk(&DAT_00107509,*puVar2,"mmi_vote");
        ipc_log_string(this_chip[0x51],"E %s: %s: No entry found\n",*this_chip,"mmi_vote");
        return 0xfffffffe;
      }
      param_1[(ulong)uVar6 + 0x11] = param_2;
      if (0x1f < uVar6) {
LAB_00102f18:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x102f1c);
        (*pcVar3)();
      }
LAB_00102eb4:
      *(undefined4 *)((long)param_1 + uVar8 * 4 + 8) = 0;
      _printk(&DAT_00108cab,*puVar2,"mmi_vote",*param_1,param_2,param_3 & 1,0);
      ipc_log_string(puVar2[0x51],"I %s: %s: %s:%s voter: en:%d, val:%d\n",*puVar2,"mmi_vote",
                     *param_1,param_2,param_3 & 1,0);
    }
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// mmi_vote_charger_suspend @ 00102f20 size=76
// signature: undefined mmi_vote_charger_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_vote_charger_suspend(undefined8 param_1,uint param_2)

{
  undefined8 uVar1;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = mmi_vote(this_chip + 0x290,param_1,param_2 & 1);
  }
  return uVar1;
}



//------------------------------------------------------------
// mmi_register_charger_driver @ 00102f70 size=2720
// signature: undefined mmi_register_charger_driver(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_register_charger_driver(undefined8 *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined8 *puVar5;
  int iVar6;
  int *piVar7;
  ulong uVar8;
  char *pcVar9;
  code *pcVar10;
  long lVar11;
  uint uVar12;
  undefined8 *puVar13;
  long lVar14;
  undefined8 uVar15;
  undefined8 *puVar16;
  long *plVar17;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  int local_b0;
  int local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 local_74;
  int iStack_70;
  long local_68;
  
  puVar5 = this_chip;
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  iStack_70 = 0;
  local_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  local_74 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_a8 = 0;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108306,"mmi_register_charger_driver");
    uVar15 = 0xffffffed;
    goto LAB_001037c4;
  }
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00108b0f,*this_chip,"mmi_register_charger_driver");
    ipc_log_string(puVar5[0x51],"E %s: %s: Invalid mmi charger driver\n",*puVar5,
                   "mmi_register_charger_driver");
    uVar15 = 0xffffffea;
    goto LAB_001037c4;
  }
  pcVar10 = (code *)param_1[2];
  if ((((pcVar10 == (code *)0x0) || (param_1[3] == 0)) || (param_1[4] == 0)) ||
     ((param_1[5] == 0 || (param_1[8] == 0)))) {
    _printk(&DAT_00109287,*this_chip,"mmi_register_charger_driver",*param_1);
    ipc_log_string(puVar5[0x51],"E %s: %s: [C:%s]: mmi charger function is empty\n",*puVar5,
                   "mmi_register_charger_driver",*param_1);
    uVar15 = 0xffffffea;
    goto LAB_001037c4;
  }
  iStack_70 = 0;
  local_80 = 0;
  uStack_7c = 0;
  uStack_78 = 0;
  local_74 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_a8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  if (*(int *)(pcVar10 + -4) != 0x4317e002) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x103040);
    (*pcVar10)();
  }
  (*pcVar10)(param_1[10],&local_a8);
  if (*(int *)((code *)param_1[3] + -4) != 0x6c7bab0e) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x103068);
    (*pcVar10)();
  }
  (*(code *)param_1[3])(param_1[10],&local_d0);
  mutex_lock(puVar5 + 4);
  puVar13 = puVar5 + 2;
  puVar16 = (undefined8 *)*puVar13;
  if (puVar16 == puVar13) {
    lVar14 = 0;
  }
  else {
    lVar14 = 0;
    do {
      if ((undefined8 *)puVar16[-0x15] == param_1) {
        _printk(&DAT_001073f4,*puVar5,"mmi_register_charger_driver",*param_1);
        ipc_log_string(puVar5[0x51],"E %s: %s: [C:%s]: driver has already registered\n",*puVar5,
                       "mmi_register_charger_driver",*param_1);
        uVar15 = 0xffffffef;
        goto LAB_001037bc;
      }
      if (lVar14 == 0) {
        lVar14 = puVar16[-1];
        iVar6 = strcmp((char *)(lVar14 + 0x38),(char *)&uStack_7c);
        if (iVar6 != 0) {
          lVar14 = 0;
        }
      }
      puVar16 = (undefined8 *)*puVar16;
    } while (puVar16 != puVar13);
  }
  piVar7 = (int *)devm_kmalloc(puVar5[1],0x120,0xdc0);
  if (piVar7 == (int *)0x0) {
    uVar15 = 0xfffffff4;
  }
  else {
    if (lVar14 == 0) {
      lVar14 = devm_kmalloc(puVar5[1],0x58,0xdc0);
      if (lVar14 == 0) {
        devm_kfree(puVar5[1],piVar7);
        uVar15 = 0xfffffff4;
        goto LAB_001037bc;
      }
      *(undefined8 *)(lVar14 + 8) = 100;
      *(undefined4 *)(lVar14 + 0x1c) = 100;
      lVar11 = param_1[1];
      *(ulong *)(lVar14 + 0x38) = CONCAT44(uStack_78,uStack_7c);
      *(ulong *)(lVar14 + 0x40) = CONCAT44(iStack_70,local_74);
      *(int *)(lVar14 + 0x14) = *(int *)(lVar14 + 0x14) + 1;
      of_property_read_variable_u32_array
                (*(undefined8 *)(lVar11 + 0x2e8),"mmi,paired-id",(uint *)(lVar14 + 0x20),1,0);
      if (*(int *)(lVar14 + 0x20) == 0) {
        *(undefined8 *)(lVar14 + 0x28) = 0;
      }
      else {
        for (puVar16 = (undefined8 *)puVar5[10]; puVar16 != puVar5 + 10;
            puVar16 = (undefined8 *)*puVar16) {
          uVar12 = *(uint *)(puVar16 + -5);
          uVar4 = *(uint *)(lVar14 + 0x20);
          if ((int)uVar12 >> 0x10 == (uVar4 & 0xffff)) {
            *(undefined8 **)(lVar14 + 0x28) = puVar16 + -9;
            uVar12 = (uint)*(ushort *)(puVar16 + -5);
          }
          if ((int)uVar4 >> 0x10 == (uVar12 & 0xffff)) {
            puVar16[-4] = lVar14;
          }
        }
      }
      mutex_lock(puVar5 + 0xc);
      plVar17 = (long *)puVar5[0xb];
      lVar11 = lVar14 + 0x48;
      uVar8 = __list_add_valid(lVar11,plVar17,puVar5 + 10);
      if ((uVar8 & 1) != 0) {
        puVar5[0xb] = lVar11;
        *(undefined8 **)(lVar14 + 0x48) = puVar5 + 10;
        *(long **)(lVar14 + 0x50) = plVar17;
        *plVar17 = lVar11;
      }
    }
    else {
      mutex_lock(puVar5 + 0xc);
      *(int *)(lVar14 + 0x14) = *(int *)(lVar14 + 0x14) + 1;
    }
    mutex_unlock(puVar5 + 0xc);
    local_ac = 0;
    *(undefined8 *)(piVar7 + 0x1c) = local_a8;
    piVar7[0x12] = 0;
    piVar7[0x13] = 0;
    piVar7[0x16] = 0xc;
    piVar7[0x17] = 6;
    piVar7[0x18] = 0;
    piVar7[0x19] = 0;
    piVar7[0x18] = 2;
    piVar7[0x12] = 100;
    piVar7[0x2a] = iStack_70;
    piVar7[0x14] = 0;
    piVar7[0x15] = 0;
    *(undefined8 **)(piVar7 + 0x1a) = param_1;
    *(long *)(piVar7 + 0x42) = lVar14;
    *(ulong *)(piVar7 + 0x26) = CONCAT44(uStack_7c,local_80);
    *(ulong *)(piVar7 + 0x28) = CONCAT44(local_74,uStack_78);
    piVar7[0x33] = local_b0;
    *(undefined8 *)(piVar7 + 0x1e) = local_a0;
    *(undefined8 *)(piVar7 + 0x20) = local_98;
    *(undefined8 *)(piVar7 + 0x22) = local_90;
    *(undefined8 *)(piVar7 + 0x24) = uStack_88;
    *(undefined8 *)(piVar7 + 0x2b) = local_d0;
    *(undefined8 *)(piVar7 + 0x2d) = uStack_c8;
    *(undefined8 *)(piVar7 + 0x2f) = local_c0;
    *(undefined8 *)(piVar7 + 0x31) = uStack_b8;
    *(int **)(lVar14 + 0x30) = piVar7 + 0x1c;
    if ((*(long *)(piVar7 + 0x1a) == 0) ||
       (lVar14 = *(long *)(*(long *)(piVar7 + 0x1a) + 8), lVar14 == 0)) {
      _printk(&DAT_00107de6,*puVar5,"mmi_get_charger_profile");
      ipc_log_string(puVar5[0x51],"E %s: %s: mmi charger driver is invalid\n",*puVar5,
                     "mmi_get_charger_profile");
    }
    else {
      uVar15 = *(undefined8 *)(lVar14 + 0x2e8);
      iVar6 = of_property_read_variable_u32_array
                        (uVar15,"mmi,shutdown-empty-vbat-mv",piVar7 + 4,1,0);
      if (iVar6 < 0) {
        piVar7[4] = -0x16;
      }
      piVar1 = piVar7 + 6;
      iVar6 = of_property_read_variable_u32_array(uVar15,"mmi,chrg-iterm-ma",piVar1,1,0);
      if (iVar6 < 0) {
        iVar6 = 300;
        *piVar1 = 300;
      }
      else {
        iVar6 = *piVar1;
      }
      piVar7[1] = iVar6;
      iVar6 = of_property_read_variable_u32_array
                        (uVar15,"mmi,chrg-iterm-ma-noffc-35-45c",piVar7 + 2,1,0);
      if (iVar6 < 0) {
        piVar7[2] = -1;
      }
      piVar2 = piVar7 + 5;
      iVar6 = of_property_read_variable_u32_array(uVar15,"mmi,fg-iterm-ma",piVar2,1,0);
      if (iVar6 < 0) {
        iVar6 = *piVar1 + 0x32;
        *piVar2 = iVar6;
      }
      else {
        iVar6 = *piVar2;
      }
      *piVar7 = iVar6;
      iVar6 = of_property_read_variable_u32_array(uVar15,"mmi,vfloat-comp-uv",piVar7 + 9,1,0);
      if (iVar6 < 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = piVar7[9] / 1000;
      }
      piVar1 = piVar7 + 7;
      piVar7[9] = iVar6;
      iVar6 = of_property_read_variable_u32_array(uVar15,"mmi,max-fv-mv",piVar1,1,0);
      if (iVar6 < 0) {
        iVar6 = 0x1130;
        *piVar1 = 0x1130;
      }
      else {
        iVar6 = *piVar1;
      }
      piVar7[3] = iVar6;
      iVar6 = of_property_read_variable_u32_array(uVar15,"mmi,max-fcc-ma",piVar7 + 8,1,0);
      if (iVar6 < 0) {
        piVar7[8] = 0x1130;
      }
      iVar6 = of_property_read_variable_u32_array(uVar15,"mmi,demo-fv-mv",piVar7 + 10,1,0);
      if (iVar6 < 0) {
        piVar7[10] = 4000;
      }
      lVar14 = of_find_property(uVar15,"mmi,mmi-temp-zones",&local_ac);
      if (lVar14 == 0) {
LAB_00103750:
        lVar14 = of_find_property(uVar15,"mmi,mmi-ffc-zones",&local_ac);
        if (lVar14 != 0) {
          if (((long)local_ac & 0xcU) != 0) {
            _printk(&DAT_00108a4a,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a)
                   );
            puVar16 = *(undefined8 **)(piVar7 + 0x1a);
            pcVar9 = "E %s: %s: [C:%s]: DT error wrong mmi ffc zones\n";
            goto LAB_00103878;
          }
          lVar14 = devm_kmalloc(puVar5[1],(long)local_ac,0xdc0);
          *(long *)(piVar7 + 0x10) = lVar14;
          if (lVar14 != 0) {
            piVar7[0xe] = local_ac >> 4;
            iVar6 = of_property_read_variable_u32_array
                              (uVar15,"mmi,mmi-ffc-zones",lVar14,(ulong)(long)local_ac >> 2,0);
            if (iVar6 < 0) {
              _printk(&DAT_00109a57,*puVar5,"mmi_get_charger_profile",
                      **(undefined8 **)(piVar7 + 0x1a),iVar6);
              ipc_log_string(puVar5[0x51],"E %s: %s: [C:%s]: Couldn\'t read mmi ffc zones rc = %d\n"
                             ,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a),
                             iVar6);
              devm_kfree(puVar5[1],*(undefined8 *)(piVar7 + 0x10));
              piVar7[0x10] = 0;
              piVar7[0x11] = 0;
            }
            else {
              _printk(&DAT_00108293,*puVar5,"mmi_get_charger_profile",
                      **(undefined8 **)(piVar7 + 0x1a),piVar7[0xe]);
              ipc_log_string(puVar5[0x51],"I %s: %s: [C:%s]: mmi ffc zones: Num: %d\n",*puVar5,
                             "mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a),piVar7[0xe])
              ;
              if (0 < piVar7[0xe]) {
                lVar14 = 0;
                uVar8 = 0;
                do {
                  puVar3 = (undefined4 *)(*(long *)(piVar7 + 0x10) + lVar14);
                  _printk(&DAT_0010754e,*puVar5,"mmi_get_charger_profile",
                          **(undefined8 **)(piVar7 + 0x1a),uVar8 & 0xffffffff,*puVar3,puVar3[1],
                          puVar3[2],puVar3[3]);
                  puVar3 = (undefined4 *)(*(long *)(piVar7 + 0x10) + lVar14);
                  ipc_log_string(puVar5[0x51],
                                 "I %s: %s: [C:%s]: mmi ffc zones: Zone %d, Temp %d C, FV %d mV, Chg Iterm %d mA, Fg Iterm %d mA\n"
                                 ,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a)
                                 ,uVar8 & 0xffffffff,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
                  uVar8 = uVar8 + 1;
                  lVar14 = lVar14 + 0x10;
                } while ((long)uVar8 < (long)piVar7[0xe]);
              }
            }
          }
        }
      }
      else if (((long)local_ac & 0xcU) == 0) {
        lVar14 = devm_kmalloc(puVar5[1],(long)local_ac,0xdc0);
        *(long *)(piVar7 + 0xc) = lVar14;
        if (lVar14 != 0) {
          piVar7[0xb] = local_ac >> 4;
          iVar6 = of_property_read_variable_u32_array
                            (uVar15,"mmi,mmi-temp-zones",lVar14,(ulong)(long)local_ac >> 2,0);
          if (-1 < iVar6) {
            _printk(&DAT_00107523,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a)
                    ,piVar7[0xb]);
            ipc_log_string(puVar5[0x51],"I %s: %s: [C:%s]: mmi temp zones: Num: %d\n",*puVar5,
                           "mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a),piVar7[0xb]);
            if (0 < piVar7[0xb]) {
              lVar14 = 0;
              uVar8 = 0;
              do {
                puVar3 = (undefined4 *)(*(long *)(piVar7 + 0xc) + lVar14);
                _printk(&DAT_00109b8d,*puVar5,"mmi_get_charger_profile",
                        **(undefined8 **)(piVar7 + 0x1a),uVar8 & 0xffffffff,*puVar3,puVar3[1],
                        puVar3[2],puVar3[3]);
                puVar3 = (undefined4 *)(*(long *)(piVar7 + 0xc) + lVar14);
                ipc_log_string(puVar5[0x51],
                               "I %s: %s: [C:%s]: mmi temp zones: Zone %d, Temp %d C, Step Volt %d mV, Full Rate %d mA, Taper Rate %d mA\n"
                               ,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a),
                               uVar8 & 0xffffffff,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
                uVar8 = uVar8 + 1;
                lVar14 = lVar14 + 0x10;
              } while ((long)uVar8 < (long)piVar7[0xb]);
            }
            goto LAB_00103750;
          }
          _printk(&DAT_001086d8,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a),
                  iVar6);
          ipc_log_string(puVar5[0x51],"E %s: %s: [C:%s]: Couldn\'t read mmi temp zones rc = %d\n",
                         *puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a),iVar6);
          devm_kfree(puVar5[1],*(undefined8 *)(piVar7 + 0xc));
          piVar7[0xc] = 0;
          piVar7[0xd] = 0;
        }
      }
      else {
        _printk(&DAT_00108fe2,*puVar5,"mmi_get_charger_profile",**(undefined8 **)(piVar7 + 0x1a));
        puVar16 = *(undefined8 **)(piVar7 + 0x1a);
        pcVar9 = "E %s: %s: [C:%s]: DT error wrong mmi temp zones\n";
LAB_00103878:
        ipc_log_string(puVar5[0x51],pcVar9,*puVar5,"mmi_get_charger_profile",*puVar16);
      }
    }
    puVar16 = (undefined8 *)puVar5[3];
    piVar1 = piVar7 + 0x44;
    uVar8 = __list_add_valid(piVar1,puVar16,puVar13);
    if ((uVar8 & 1) != 0) {
      puVar5[3] = piVar1;
      *(undefined8 **)(piVar7 + 0x44) = puVar13;
      *(undefined8 **)(piVar7 + 0x46) = puVar16;
      *puVar16 = piVar1;
    }
    if (puVar5[0x13] != 0) {
      _printk(&DAT_001092b8,*puVar5,"mmi_register_charger_driver",*param_1);
      ipc_log_string(puVar5[0x51],
                     "I %s: %s: [C:%s] register charger succesfully, Throw out BATT_PSY change to update battery info\n"
                     ,*puVar5,"mmi_register_charger_driver",*param_1);
      power_supply_changed(puVar5[0x13]);
    }
    uVar15 = 0;
  }
LAB_001037bc:
  mutex_unlock(puVar5 + 4);
LAB_001037c4:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar15;
}



//------------------------------------------------------------
// mmi_unregister_charger_driver @ 00103a14 size=448
// signature: undefined mmi_unregister_charger_driver(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_unregister_charger_driver(undefined8 *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  long *plVar3;
  undefined8 *puVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  long lVar8;
  
  puVar4 = this_chip;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108306,"mmi_unregister_charger_driver");
    uVar7 = 0xffffffed;
  }
  else if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00108b0f,*this_chip,"mmi_unregister_charger_driver");
    ipc_log_string(puVar4[0x51],"E %s: %s: Invalid mmi charger driver\n",*puVar4,
                   "mmi_unregister_charger_driver");
    uVar7 = 0xffffffea;
  }
  else {
    puVar1 = this_chip + 4;
    mutex_lock(puVar1);
    plVar6 = puVar4 + 2;
    do {
      plVar6 = (long *)*plVar6;
      if (plVar6 == puVar4 + 2) goto LAB_00103b38;
    } while ((undefined8 *)plVar6[-0x15] != param_1);
    if (plVar6 + -0x22 == (long *)0x0) {
LAB_00103b38:
      _printk(&DAT_001097ec,*puVar4,"mmi_unregister_charger_driver",*param_1);
      ipc_log_string(puVar4[0x51],"E %s: %s: [C:%s]: driver has not registered yet\n",*puVar4,
                     "mmi_unregister_charger_driver",*param_1);
      uVar7 = 0xfffffffe;
    }
    else {
      mutex_lock(puVar4 + 0xc);
      *(int *)(plVar6[-1] + 0x14) = *(int *)(plVar6[-1] + 0x14) + -1;
      lVar8 = plVar6[-1];
      if (*(int *)(lVar8 + 0x14) < 1) {
        uVar5 = __list_del_entry_valid(lVar8 + 0x48);
        if ((uVar5 & 1) != 0) {
          lVar2 = *(long *)(lVar8 + 0x48);
          plVar3 = *(long **)(lVar8 + 0x50);
          *(long **)(lVar2 + 8) = plVar3;
          *plVar3 = lVar2;
        }
        *(undefined8 *)(lVar8 + 0x48) = 0xdead000000000100;
        *(undefined8 *)(lVar8 + 0x50) = 0xdead000000000122;
        devm_kfree(puVar4[1],plVar6[-1]);
      }
      mutex_unlock(puVar4 + 0xc);
      uVar5 = __list_del_entry_valid(plVar6);
      if ((uVar5 & 1) != 0) {
        lVar8 = *plVar6;
        plVar3 = (long *)plVar6[1];
        *(long **)(lVar8 + 8) = plVar3;
        *plVar3 = lVar8;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      devm_kfree(puVar4[1],plVar6 + -0x22);
      uVar7 = 0;
    }
    mutex_unlock(puVar1);
  }
  return uVar7;
}



//------------------------------------------------------------
// mmi_notify_charger_event @ 00103bd4 size=492
// signature: undefined mmi_notify_charger_event(void)
// callers: [mmi_update_battery_status, state_sync_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mmi_notify_charger_event(undefined8 *param_1,undefined4 param_2)

{
  char cVar1;
  code *pcVar2;
  long lVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  if ((param_1[0x13] == 0) && (mmi_battery_supply_init(param_1), param_1[0x13] == 0)) {
    return;
  }
  lVar3 = kmalloc_trace(_sysfs_create_group,0xcc0,0x32);
  if (lVar3 == 0) {
    return;
  }
  switch(param_2) {
  case 0:
    if (5 < *(uint *)(param_1 + 0x1c)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x103dc0);
      (*pcVar2)();
    }
    pcVar4 = "POWER_SUPPLY_CHARGE_RATE=%s";
    pcVar5 = (&charge_rate)[*(uint *)(param_1 + 0x1c)];
    goto LAB_00103d00;
  case 1:
    cVar1 = *(char *)((long)param_1 + 0xe9);
    pcVar4 = "POWER_SUPPLY_LPD_PRESENT=%s";
    goto LAB_00103cf8;
  case 2:
    cVar1 = *(char *)(param_1 + 0x1d);
    pcVar4 = "POWER_SUPPLY_VBUS_PRESENT=%s";
LAB_00103cf8:
    pcVar5 = "false";
    if (cVar1 != '\0') {
      pcVar5 = "true";
    }
LAB_00103d00:
    scnprintf(lVar3,0x32,pcVar4,pcVar5);
    goto LAB_00103d38;
  case 3:
    iVar6 = *(int *)(param_1 + 0x1e);
    pcVar4 = "POWER_SUPPLY_POWER_WATT=%d";
    goto LAB_00103cb8;
  case 4:
    iVar6 = *(int *)(param_1 + 0x23);
    pcVar4 = "POWER_SUPPLY_POWER_WATT_DESIGN=%d";
LAB_00103cb8:
    iVar6 = iVar6 / 1000;
    break;
  case 5:
    iVar6 = *(int *)((long)param_1 + 0xe4);
    pcVar4 = "POWER_SUPPLY_CHARGE_REAL_TYPE=%d";
    break;
  case 6:
    iVar6 = *(int *)((long)param_1 + 0xf4);
    pcVar4 = "POWER_SUPPLY_STATE_OF_HEALTH=%d";
    break;
  case 7:
    iVar6 = *(int *)((long)param_1 + 0xec);
    pcVar4 = "POWER_SUPPLY_CID_STATUS=%d";
    break;
  default:
    _printk(&DAT_001089aa,*param_1,"mmi_notify_charger_event",param_2);
    ipc_log_string(param_1[0x51],"E %s: %s: Invalid notify event type %d\n",*param_1,
                   "mmi_notify_charger_event",param_2);
    kfree(lVar3);
    return;
  }
  scnprintf(lVar3,0x32,pcVar4,iVar6);
LAB_00103d38:
  if (param_1[0x14] != 0) {
    kfree();
  }
  param_1[0x14] = lVar3;
  param_1[0x15] = 0;
  kobject_uevent_env(param_1[0x13] + 0x38,2,param_1 + 0x14);
  return;
}



//------------------------------------------------------------
// mmi_battery_supply_init @ 00103dc0 size=756
// signature: undefined mmi_battery_supply_init(void)
// callers: [mmi_psy_notifier_call, mmi_notify_charger_event, mmi_charger_probe]
//------------------------------------------------------------

void mmi_battery_supply_init(undefined8 *param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  char *pcVar4;
  
  if (param_1[0x13] == 0) {
    lVar2 = power_supply_get_by_name("battery");
    param_1[0x13] = lVar2;
    if (lVar2 == 0) {
      pcVar4 = "E %s: %s: No battery supply found\n";
      puVar3 = &DAT_00108321;
    }
    else {
      iVar1 = sysfs_create_group(lVar2 + 0x38,power_supply_mmi_attr_group);
      if (iVar1 != 0) {
        _printk(&DAT_00109697,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: failed: attr create\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),&dev_attr_force_demo_mode);
      if (iVar1 != 0) {
        _printk(&DAT_00109a01,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create force_demo_mode\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),&dev_attr_force_max_chrg_temp
                                );
      if (iVar1 != 0) {
        _printk(&DAT_00107804,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create force_max_chrg_temp\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),&dev_attr_factory_image_mode)
      ;
      if (iVar1 != 0) {
        _printk(&DAT_00107c2f,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create factory_image_mode\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),
                                 &dev_attr_factory_charge_upper);
      if (iVar1 != 0) {
        _printk(&DAT_00108895,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create factory_charge_upper\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),
                                 &dev_attr_force_charger_suspend);
      if (iVar1 != 0) {
        _printk(&DAT_00108c67,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create force_charger_suspend\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),
                                 &dev_attr_force_charging_enable);
      if (iVar1 != 0) {
        _printk(&DAT_00109621,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create force_charging_enable\n",*param_1,
                       "mmi_battery_supply_init");
      }
      iVar1 = device_create_file(*(undefined8 *)(param_1[0x13] + 0x98),
                                 &dev_attr_force_charging_disable);
      if (iVar1 != 0) {
        _printk(&DAT_00109d80,*param_1,"mmi_battery_supply_init");
        ipc_log_string(param_1[0x51],"E %s: %s: couldn\'t create force_charging_disable\n",*param_1,
                       "mmi_battery_supply_init");
      }
      pcVar4 = "I %s: %s: battery supply is initialized\n";
      puVar3 = &DAT_00108a00;
    }
    _printk(puVar3,*param_1,"mmi_battery_supply_init");
    ipc_log_string(param_1[0x51],pcVar4,*param_1,"mmi_battery_supply_init");
  }
  return;
}



//------------------------------------------------------------
// charge_rate_show @ 001040b8 size=112
// signature: undefined charge_rate_show(void)
// callers: []
//------------------------------------------------------------

long charge_rate_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar3 = -0x13;
  }
  else {
    if (5 < *(uint *)(this_chip + 0xe0)) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104128);
      (*pcVar1)();
    }
    iVar2 = scnprintf(param_3,0x32,&DAT_00108fc1,(&charge_rate)[*(uint *)(this_chip + 0xe0)]);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// age_show @ 0010412c size=88
// signature: undefined age_show(void)
// callers: []
//------------------------------------------------------------

long age_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0xb8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// state_of_health_show @ 00104188 size=88
// signature: undefined state_of_health_show(void)
// callers: []
//------------------------------------------------------------

long state_of_health_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0xf4));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// manufacturing_date_show @ 001041e4 size=88
// signature: undefined manufacturing_date_show(void)
// callers: []
//------------------------------------------------------------

long manufacturing_date_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0xf8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// manufacturing_date_store @ 00104240 size=228
// signature: undefined manufacturing_date_store(void)
// callers: []
//------------------------------------------------------------

undefined8
manufacturing_date_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      *(int *)(this_chip + 0x1f) = (int)local_30;
    }
    else {
      _printk(&DAT_0010943b,*this_chip,"manufacturing_date_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid manufacturing_date value = %lu\n",*this_chip
                     ,"manufacturing_date_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// first_usage_date_show @ 00104328 size=88
// signature: undefined first_usage_date_show(void)
// callers: []
//------------------------------------------------------------

long first_usage_date_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0xfc));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// first_usage_date_store @ 00104384 size=228
// signature: undefined first_usage_date_store(void)
// callers: []
//------------------------------------------------------------

undefined8
first_usage_date_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      *(int *)((long)this_chip + 0xfc) = (int)local_30;
    }
    else {
      _printk(&DAT_001090ef,*this_chip,"first_usage_date_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid first_usage_date value = %lu\n",*this_chip,
                     "first_usage_date_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// force_demo_mode_show @ 0010446c size=88
// signature: undefined force_demo_mode_show(void)
// callers: []
//------------------------------------------------------------

long force_demo_mode_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0x104));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// force_demo_mode_store @ 001044c8 size=256
// signature: undefined force_demo_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8
force_demo_mode_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      if (local_30 - 0x23U < 0x2e) {
        *(int *)((long)this_chip + 0x104) = (int)local_30;
      }
      else {
        *(undefined4 *)((long)this_chip + 0x104) = 0x23;
      }
    }
    else {
      _printk(&DAT_0010837f,*this_chip,"force_demo_mode_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid demo mode value = %lu\n",*this_chip,
                     "force_demo_mode_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// force_max_chrg_temp_show @ 001045cc size=88
// signature: undefined force_max_chrg_temp_show(void)
// callers: []
//------------------------------------------------------------

long force_max_chrg_temp_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0x120));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// force_max_chrg_temp_store @ 00104628 size=256
// signature: undefined force_max_chrg_temp_store(void)
// callers: []
//------------------------------------------------------------

undefined8
force_max_chrg_temp_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      if (local_30 - 0x2fU < 0xe) {
        *(int *)(this_chip + 0x24) = (int)local_30;
      }
      else {
        *(undefined4 *)(this_chip + 0x24) = 0x3c;
      }
    }
    else {
      _printk(&DAT_001085b5,*this_chip,"force_max_chrg_temp_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid max temp value = %lu\n",*this_chip,
                     "force_max_chrg_temp_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// factory_image_mode_show @ 0010472c size=88
// signature: undefined factory_image_mode_show(void)
// callers: []
//------------------------------------------------------------

long factory_image_mode_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined1 *)(this_chip + 0x109));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// factory_image_mode_store @ 00104788 size=236
// signature: undefined factory_image_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8
factory_image_mode_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      *(bool *)((long)this_chip + 0x109) = local_30 != 0;
    }
    else {
      _printk(&DAT_00108216,*this_chip,"factory_image_mode_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid factory image mode value = %lu\n",*this_chip
                     ,"factory_image_mode_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// factory_charge_upper_show @ 00104878 size=88
// signature: undefined factory_charge_upper_show(void)
// callers: []
//------------------------------------------------------------

long factory_charge_upper_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 300));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// force_charger_suspend_show @ 001048d4 size=88
// signature: undefined force_charger_suspend_show(void)
// callers: []
//------------------------------------------------------------

long force_charger_suspend_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010805a);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined1 *)(this_chip + 0x10b));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// force_charger_suspend_store @ 00104930 size=332
// signature: undefined force_charger_suspend_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
force_charger_suspend_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  long local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_0010805a);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar4 = kstrtoull(param_3,0,&local_50);
    if (iVar4 == 0) {
      puVar1 = this_chip + 0x3f;
      *(bool *)((long)this_chip + 0x10b) = local_50 != 0;
      cancel_delayed_work(puVar1);
      queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      pcVar2 = "clear";
      if (local_50 != 0) {
        pcVar2 = "set";
      }
      _printk(&DAT_00107844,*this_chip,"force_charger_suspend_store",pcVar2);
      pcVar2 = "clear";
      if (local_50 != 0) {
        pcVar2 = "set";
      }
      ipc_log_string(this_chip[0x51],"I %s: %s: %s force_charger_disabled\n",*this_chip,
                     "force_charger_suspend_store",pcVar2);
    }
    else {
      _printk(&DAT_001088d9);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// force_charging_enable_show @ 00104a80 size=88
// signature: undefined force_charging_enable_show(void)
// callers: []
//------------------------------------------------------------

long force_charging_enable_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010805a);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined1 *)(this_chip + 0x10c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// force_charging_enable_store @ 00104adc size=332
// signature: undefined force_charging_enable_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
force_charging_enable_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  long local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_0010805a);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar4 = kstrtoull(param_3,0,&local_50);
    if (iVar4 == 0) {
      puVar1 = this_chip + 0x3f;
      *(bool *)((long)this_chip + 0x10c) = local_50 != 0;
      cancel_delayed_work(puVar1);
      queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      pcVar2 = "clear";
      if (local_50 != 0) {
        pcVar2 = "set";
      }
      _printk(&DAT_001085dd,*this_chip,"force_charging_enable_store",pcVar2);
      pcVar2 = "clear";
      if (local_50 != 0) {
        pcVar2 = "set";
      }
      ipc_log_string(this_chip[0x51],"I %s: %s: %s force_charging_enabled\n",*this_chip,
                     "force_charging_enable_store",pcVar2);
    }
    else {
      _printk(&DAT_00108b8d);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// force_charging_disable_store @ 00104c2c size=372
// signature: undefined force_charging_disable_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
force_charging_disable_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  long local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_0010805a);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_50);
    if (iVar3 == 0) {
      if (this_chip == (undefined8 *)0x0) {
        _printk(&DAT_00108aef);
      }
      else {
        mmi_vote(this_chip + 0x83,"MMI_USER",local_50 != 0);
      }
      cancel_delayed_work(this_chip + 0x3f);
      queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      pcVar1 = "clear";
      if (local_50 != 0) {
        pcVar1 = "set";
      }
      _printk(&DAT_00108d9c,*this_chip,"force_charging_disable_store",pcVar1);
      pcVar1 = "clear";
      if (local_50 != 0) {
        pcVar1 = "set";
      }
      ipc_log_string(this_chip[0x51],"I %s: %s: %s force_charging_disable\n",*this_chip,
                     "force_charging_disable_store",pcVar1);
    }
    else {
      _printk(&DAT_00108bc0,local_50);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mmi_charger_probe @ 00104da4 size=2568
// signature: undefined mmi_charger_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 mmi_charger_probe(long param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  byte bVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  char *pcVar9;
  char *pcVar10;
  ulong uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 *local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  char *local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  local_78 = (undefined8 *)0x0;
  puVar7 = (undefined8 *)devm_kmalloc(param_1 + 0x10,0x5b0,0xdc0);
  if (puVar7 == (undefined8 *)0x0) {
    uVar12 = 0xfffffff4;
    goto LAB_00104df8;
  }
  local_88 = *(undefined8 *)(param_1 + 0x2f8);
  *puVar7 = "mmi_charger";
  puVar7[1] = param_1 + 0x10;
  *(undefined4 *)(puVar7 + 0x20) = 0;
  puVar7[0x17] = 100;
  puVar7[0x18] = 0;
  puVar7[0x16] = 0x6400000000;
  puVar7[0x1a] = 0;
  puVar7[0x1b] = 0;
  local_78 = puVar7;
  bVar5 = mmi_is_factory_version();
  *(byte *)((long)puVar7 + 0x109) = bVar5 & 1;
  bVar5 = mmi_is_factory_mode();
  uVar13 = puVar7[1];
  *(undefined8 **)(param_1 + 0xa8) = puVar7;
  puVar7[0x83] = "disable_charging";
  *(byte *)(puVar7 + 0x21) = bVar5 & 1;
  puVar7[0x52] = "suspend_charger";
  device_set_wakeup_capable(uVar13,1);
  device_wakeup_enable(uVar13);
  puVar7[0x50] = &debug_enabled;
  lVar8 = ipc_log_context_create(0x32,"mmi_charger",0);
  puVar4 = &DAT_0010971b;
  if (lVar8 != 0) {
    puVar4 = &DAT_0010989d;
  }
  puVar7[0x51] = lVar8;
  pcVar10 = "E %s: %s: Failed to create mmi charger IPC log\n";
  if (lVar8 != 0) {
    pcVar10 = "I %s: %s: IPC logging is enabled for mmi charger\n";
  }
  _printk(puVar4,*puVar7,"mmi_charger_probe");
  ipc_log_string(puVar7[0x51],pcVar10,*puVar7,"mmi_charger_probe");
  local_50 = (char *)0x0;
  uVar13 = *(undefined8 *)(puVar7[1] + 0x2e8);
  lVar8 = of_find_property(uVar13,"mmi,enable-charging-limit",0);
  *(bool *)((long)puVar7 + 0x124) = lVar8 != 0;
  lVar8 = of_find_property(uVar13,"mmi,enable-factory-poweroff",0);
  *(bool *)((long)puVar7 + 0x125) = lVar8 != 0;
  lVar8 = of_find_property(uVar13,"mmi,factory-syspoweroff-wait",0);
  *(bool *)((long)puVar7 + 0x126) = lVar8 != 0;
  lVar8 = of_find_property(uVar13,"mmi,start-factory-kill-disabled",0);
  *(bool *)((long)puVar7 + 0x127) = lVar8 != 0;
  iVar6 = of_property_read_variable_u32_array
                    (uVar13,"mmi,factory-kill-debounce-ms",puVar7 + 0xb4,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(puVar7 + 0xb4) = 0;
  }
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,upper-limit-en-voltage",puVar7 + 0x25,1,0)
  ;
  if (iVar6 < 0) {
    *(undefined4 *)(puVar7 + 0x25) = 4000;
  }
  iVar6 = of_property_read_variable_u32_array
                    (uVar13,"mmi,upper-limit-capacity",(undefined4 *)((long)puVar7 + 300),1,0);
  if (iVar6 < 0) {
    *(undefined4 *)((long)puVar7 + 300) = 100;
  }
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,lower-limit-capacity",puVar7 + 0x26,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(puVar7 + 0x26) = 0;
  }
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,heartbeat-interval",puVar7 + 0x38,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(puVar7 + 0x38) = 60000;
  }
  iVar6 = of_property_read_variable_u32_array
                    (uVar13,"mmi,heartbeat-factory-interval",(undefined4 *)((long)puVar7 + 0x1c4),1,
                     0);
  if (iVar6 < 0) {
    *(undefined4 *)((long)puVar7 + 0x1c4) = 5000;
  }
  puVar1 = puVar7 + 0x22;
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,dcp-power-max",puVar1,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)puVar1 = 0x1d4c;
  }
  puVar2 = (undefined4 *)((long)puVar7 + 0x114);
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,hvdcp-power-max",puVar2,1,0);
  if (iVar6 < 0) {
    *puVar2 = 15000;
  }
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,pd-power-max",puVar7 + 0x23,1,0);
  if (iVar6 < 0) {
    *(undefined4 *)(puVar7 + 0x23) = 18000;
  }
  iVar6 = of_property_read_variable_u32_array
                    (uVar13,"mmi,wls-power-max",(undefined4 *)((long)puVar7 + 0x11c),1,0);
  if (iVar6 < 0) {
    *(undefined4 *)((long)puVar7 + 0x11c) = 10000;
  }
  puVar3 = puVar7 + 0xb5;
  iVar6 = of_property_read_variable_u32_array(uVar13,"mmi,heartbeat-discharger-ms",puVar3,1,0);
  if (iVar6 < 0) {
    uVar12 = 100000;
    *(undefined4 *)puVar3 = 100000;
  }
  else {
    uVar12 = *(undefined4 *)puVar3;
  }
  _printk(&DAT_00108407,*puVar7,"mmi_parse_dt",uVar12);
  ipc_log_string(puVar7[0x51],"W %s: %s: mmi,heartbeat dischg ms %d\n",*puVar7,"mmi_parse_dt",
                 *(undefined4 *)(puVar7 + 0xb5));
  iVar6 = of_property_read_variable_u32_array
                    (uVar13,"mmi,ibat-calc-alignment-time",(undefined4 *)((long)puVar7 + 0x5ac),1,0)
  ;
  if (iVar6 < 0) {
    *(undefined4 *)((long)puVar7 + 0x5ac) = 0xffffffff;
  }
  lVar8 = of_find_node_opts_by_path("/chosen",0);
  if (lVar8 != 0) {
    iVar6 = of_property_read_string(lVar8,"mmi,charger",&local_50);
    if ((iVar6 == -0x16) || (local_50 == (char *)0x0)) {
      _printk(&DAT_00107387,*puVar7,"mmi_parse_dt");
      ipc_log_string(puVar7[0x51],"W %s: %s: mmi,charger is unused\n",*puVar7,"mmi_parse_dt");
    }
    else {
      _printk(&DAT_001091f5,*puVar7,"mmi_parse_dt");
      ipc_log_string(puVar7[0x51],"I %s: %s: QC charger ability = %s\n",*puVar7,"mmi_parse_dt",
                     local_50);
      pcVar10 = local_50;
      pcVar9 = strstr(local_50,"15W");
      if (pcVar9 == (char *)0x0) {
        pcVar9 = strstr(pcVar10,"18W");
        if (pcVar9 == (char *)0x0) {
          pcVar10 = strstr(pcVar10,"20W");
          if (pcVar10 == (char *)0x0) goto LAB_001052f8;
          uVar12 = 20000;
        }
        else {
          uVar12 = 18000;
        }
      }
      else {
        uVar12 = 15000;
      }
      *puVar2 = uVar12;
    }
LAB_001052f8:
    local_50 = (char *)0x0;
    iVar6 = of_property_read_string(lVar8,"mmi,usb_dcp",&local_50);
    if ((iVar6 == -0x16) || (local_50 == (char *)0x0)) {
      _printk(&DAT_0010842d,*puVar7,"mmi_parse_dt");
      ipc_log_string(puVar7[0x51],"W %s: %s: mmi,usb_dcp is unused\n",*puVar7,"mmi_parse_dt");
    }
    else {
      _printk(&DAT_0010862a,*puVar7,"mmi_parse_dt");
      ipc_log_string(puVar7[0x51],"I %s: %s: DCP charger ability = %s\n",*puVar7,"mmi_parse_dt",
                     local_50);
      pcVar10 = local_50;
      pcVar9 = strstr(local_50,"1.5A");
      if (pcVar9 == (char *)0x0) {
        pcVar10 = strstr(pcVar10,"2A");
        if (pcVar10 == (char *)0x0) goto LAB_001053c8;
        uVar12 = 10000;
      }
      else {
        uVar12 = 0x1d4c;
      }
      *(undefined4 *)puVar1 = uVar12;
    }
  }
LAB_001053c8:
  this_chip = puVar7;
  __mutex_init(puVar7 + 4,"&chip->charger_lock",&mmi_charger_probe___key);
  __mutex_init(puVar7 + 0xc,"&chip->battery_lock",&mmi_charger_probe___key_201);
  puVar7[2] = puVar7 + 2;
  puVar7[3] = puVar7 + 2;
  puVar7[10] = puVar7 + 10;
  puVar7[0xb] = puVar7 + 10;
  puVar7[0x3f] = 0xfffffffe0;
  puVar7[0x40] = puVar7 + 0x40;
  puVar7[0x41] = puVar7 + 0x40;
  puVar7[0x42] = mmi_charger_heartbeat_work;
  init_timer_key(puVar7 + 0x45,&delayed_work_timer_fn,0x200000,0,0);
  uVar13 = wakeup_source_register(puVar7[1],"mmi_hb_wake");
  puVar7[0x27] = uVar13;
  alarm_init(puVar7 + 0x28,1,mmi_heartbeat_alarm_cb);
  uVar11 = devm_power_supply_register(puVar7[1],&mmi_psy_desc,&local_88);
  puVar7[0x12] = uVar11;
  if (uVar11 < 0xfffffffffffff001) {
    mmi_battery_supply_init(puVar7);
    iVar6 = device_create_file(puVar7[1],&dev_attr_state_sync);
    if (iVar6 != 0) {
      _printk(&DAT_001098cf,*puVar7,"mmi_charger_probe");
      ipc_log_string(puVar7[0x51],"E %s: %s: couldn\'t create state_sync\n",*puVar7,
                     "mmi_charger_probe");
    }
    iVar6 = device_create_file(puVar7[1],&dev_attr_dcp_pmax);
    if (iVar6 != 0) {
      _printk(&DAT_00109abe,*puVar7,"mmi_charger_probe");
      ipc_log_string(puVar7[0x51],"E %s: %s: couldn\'t create dcp_pmax\n",*puVar7,
                     "mmi_charger_probe");
    }
    iVar6 = device_create_file(puVar7[1],&dev_attr_hvdcp_pmax);
    if (iVar6 != 0) {
      _printk(&DAT_00108e1f,*puVar7,"mmi_charger_probe");
      ipc_log_string(puVar7[0x51],"E %s: %s: couldn\'t create hvdcp_pmax\n",*puVar7,
                     "mmi_charger_probe");
    }
    iVar6 = device_create_file(puVar7[1],&dev_attr_pd_pmax);
    if (iVar6 != 0) {
      _printk(&DAT_00108e45,*puVar7,"mmi_charger_probe");
      ipc_log_string(puVar7[0x51],"E %s: %s: couldn\'t create pd_pmax\n",*puVar7,"mmi_charger_probe"
                    );
    }
    iVar6 = device_create_file(puVar7[1],&dev_attr_wls_pmax);
    if (iVar6 != 0) {
      _printk(&DAT_0010874e,*puVar7,"mmi_charger_probe");
      ipc_log_string(puVar7[0x51],"E %s: %s: couldn\'t create wls_pmax\n",*puVar7,
                     "mmi_charger_probe");
    }
    puVar7[0x3c] = mmi_psy_notifier_call;
    iVar6 = power_supply_reg_notifier(puVar7 + 0x3c);
    if (iVar6 != 0) {
      _printk(&DAT_00107869,*puVar7,"mmi_charger_probe",iVar6);
      ipc_log_string(puVar7[0x51],"E %s: %s: Failed to reg notifier: %d\n",*puVar7,
                     "mmi_charger_probe",iVar6);
    }
    if (*(char *)(puVar7 + 0x21) != '\0') {
      _printk(&DAT_0010974b,*puVar7,"mmi_charger_probe");
      ipc_log_string(puVar7[0x51],"I %s: %s: Entering Factory Mode!\n",*puVar7,"mmi_charger_probe");
      puVar7[0x39] = mmi_charger_reboot;
      puVar7[0x3a] = 0;
      *(undefined4 *)(puVar7 + 0x3b) = 1;
      iVar6 = register_reboot_notifier(puVar7 + 0x39);
      if (iVar6 != 0) {
        _printk(&DAT_001098f5,*puVar7,"mmi_charger_probe");
        ipc_log_string(puVar7[0x51],"E %s: %s: Register for reboot failed\n",*puVar7,
                       "mmi_charger_probe");
      }
    }
    if (*(char *)((long)puVar7 + 0x127) != '\0') {
      factory_kill_disable = 1;
    }
    cancel_delayed_work(puVar7 + 0x3f);
    queue_delayed_work_on(0x20,_system_wq,puVar7 + 0x3f,0);
    _printk(&DAT_001091c9,*puVar7,"mmi_charger_probe");
    ipc_log_string(puVar7[0x51],"I %s: %s: MMI charger probed successfully!\n",*puVar7,
                   "mmi_charger_probe");
    uVar12 = 0;
  }
  else {
    _printk(&DAT_00107b86,*puVar7,"mmi_charger_probe");
    ipc_log_string(puVar7[0x51],"E %s: %s: failed: mmi power supply register\n",*puVar7,
                   "mmi_charger_probe");
    uVar12 = *(undefined4 *)(puVar7 + 0x12);
    ipc_log_context_destroy(puVar7[0x51]);
  }
LAB_00104df8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// mmi_charger_remove @ 001057b0 size=384
// signature: undefined mmi_charger_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_charger_remove(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xa8);
  if (*(long **)(lVar3 + 0x10) == (long *)(lVar3 + 0x10)) {
    cancel_delayed_work(lVar3 + 0x1f8);
    if (*(char *)(lVar3 + 0x108) != '\0') {
      unregister_reboot_notifier(lVar3 + 0x1c8);
    }
    power_supply_unreg_notifier(lVar3 + 0x1e0);
    device_remove_file(*(undefined8 *)(lVar3 + 8),&dev_attr_state_sync);
    device_remove_file(*(undefined8 *)(lVar3 + 8),&dev_attr_dcp_pmax);
    device_remove_file(*(undefined8 *)(lVar3 + 8),&dev_attr_hvdcp_pmax);
    device_remove_file(*(undefined8 *)(lVar3 + 8),&dev_attr_pd_pmax);
    device_remove_file(*(undefined8 *)(lVar3 + 8),&dev_attr_wls_pmax);
    lVar2 = *(long *)(lVar3 + 0x98);
    if (lVar2 != 0) {
      if (*(long *)(lVar3 + 0xa0) != 0) {
        kfree();
        lVar2 = *(long *)(lVar3 + 0x98);
        *(undefined8 *)(lVar3 + 0xa0) = 0;
      }
      device_remove_file(*(undefined8 *)(lVar2 + 0x98),&dev_attr_force_demo_mode);
      device_remove_file(*(undefined8 *)(*(long *)(lVar3 + 0x98) + 0x98),
                         &dev_attr_force_max_chrg_temp);
      device_remove_file(*(undefined8 *)(*(long *)(lVar3 + 0x98) + 0x98),
                         &dev_attr_factory_image_mode);
      device_remove_file(*(undefined8 *)(*(long *)(lVar3 + 0x98) + 0x98),
                         &dev_attr_factory_charge_upper);
      device_remove_file(*(undefined8 *)(*(long *)(lVar3 + 0x98) + 0x98),
                         &dev_attr_force_charger_suspend);
      device_remove_file(*(undefined8 *)(*(long *)(lVar3 + 0x98) + 0x98),
                         &dev_attr_force_charging_enable);
      device_remove_file(*(undefined8 *)(*(long *)(lVar3 + 0x98) + 0x98),
                         &dev_attr_force_charging_disable);
      sysfs_remove_group(*(long *)(lVar3 + 0x98) + 0x38,power_supply_mmi_attr_group);
      power_supply_put(*(undefined8 *)(lVar3 + 0x98));
    }
    wakeup_source_unregister(*(undefined8 *)(lVar3 + 0x138));
    ipc_log_context_destroy(*(undefined8 *)(lVar3 + 0x288));
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}



//------------------------------------------------------------
// mmi_charger_shutdown @ 00105934 size=96
// signature: undefined mmi_charger_shutdown(void)
// callers: []
//------------------------------------------------------------

void mmi_charger_shutdown(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  cancel_delayed_work(puVar1 + 0x3f);
  _printk(&DAT_001099ba,*puVar1,"mmi_charger_shutdown");
  ipc_log_string(puVar1[0x51],"I %s: %s: MMI charger shutdown\n",*puVar1,"mmi_charger_shutdown");
  return;
}



//------------------------------------------------------------
// mmi_charger_heartbeat_work @ 00105998 size=1316
// signature: undefined mmi_charger_heartbeat_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mmi_charger_heartbeat_work(long param_1)

{
  char cVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  puVar6 = (undefined8 *)(param_1 + -0x1f8);
  local_78 = 0;
  local_70 = 0;
  if ((*(byte *)(param_1 + -0xf8) & 1) != 0) {
    _printk(&DAT_001082d7,*puVar6,"mmi_charger_heartbeat_work");
    ipc_log_string(*(undefined8 *)(param_1 + 0x90),"E %s: %s: HB running before Resume\n",*puVar6,
                   "mmi_charger_heartbeat_work");
    queue_delayed_work_on(0x20,_system_wq,param_1,0x19);
    goto LAB_00105d34;
  }
  if (**(char **)(param_1 + 0x88) != '\0') {
    _printk(&DAT_0010991b,*puVar6,"mmi_charger_heartbeat_work");
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x90),"D %s: %s: Heartbeat!\n",*puVar6,
                 "mmi_charger_heartbeat_work");
  pm_stay_awake(*(undefined8 *)(param_1 + -0x1f0));
  alarm_cancel(param_1 + -0xb8);
  mutex_lock(param_1 + -0x1d8);
  plVar8 = (long *)(param_1 + -0x1e8);
  plVar9 = (long *)*plVar8;
  if (plVar9 != plVar8) {
    do {
      plVar7 = plVar9 + -0x22;
      mmi_get_charger_info(puVar6,plVar7);
      mmi_update_charger_profile(puVar6,plVar7);
      *(undefined1 *)(plVar9 + -5) = 0;
      *(undefined4 *)(plVar9 + -7) = *(undefined4 *)((long)plVar9 + -0xf4);
      *(undefined4 *)((long)plVar9 + -0x34) = *(undefined4 *)((long)plVar9 + -0xfc);
      *(undefined4 *)(plVar9 + -8) = 0xffffffea;
      *(undefined4 *)((long)plVar9 + -0x3c) = *(undefined4 *)((long)plVar9 + -0xf4);
      *(int *)(plVar9 + -6) = (int)plVar9[-0x1f];
      *(undefined4 *)((long)plVar9 + -0x2c) = 0;
      *(undefined4 *)((long)plVar9 + -0x24) = *(undefined4 *)(param_1 + -0xf4);
      *(undefined1 *)((long)plVar9 + -0x1f) = *(undefined1 *)(param_1 + -0xef);
      *(undefined1 *)(plVar9 + -4) = *(undefined1 *)(param_1 + -0xf0);
      *(undefined4 *)((long)plVar9 + -0x1c) = *(undefined4 *)(param_1 + -0xe8);
      *(undefined4 *)(plVar9 + -3) = *(undefined4 *)(param_1 + -0xe4);
      *(undefined4 *)((long)plVar9 + -0x14) = *(undefined4 *)(param_1 + -0xe0);
      *(undefined4 *)(plVar9 + -2) = *(undefined4 *)(param_1 + -0xdc);
      mmi_update_charger_status(puVar6,plVar7);
      plVar9 = (long *)*plVar9;
    } while (plVar9 != plVar8);
    for (plVar9 = (long *)*plVar8; plVar9 != plVar8; plVar9 = (long *)*plVar9) {
      mmi_configure_charger(puVar6,plVar9 + -0x22);
    }
  }
  mmi_update_battery_status(puVar6);
  mutex_unlock(param_1 + -0x1d8);
  if (**(char **)(param_1 + 0x88) != '\0') {
    _printk(&DAT_00109931,*puVar6,"mmi_charger_heartbeat_work",*(undefined4 *)(param_1 + -0xf4),
            *(undefined1 *)(param_1 + -0xef),*(undefined1 *)(param_1 + -0xf0),
            *(undefined4 *)(param_1 + -0xe8),*(undefined4 *)(param_1 + -0xe4),
            *(undefined4 *)(param_1 + -0xe0),*(undefined4 *)(param_1 + -0xdc));
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x90),
                 "D %s: %s: DemoMode:%d, FactoryVersion:%d, FactoryMode:%d, dcp_pmax:%d, hvdcp_pmax:%d, pd_pmax:%d, wls_pmax:%d\n"
                 ,*puVar6,"mmi_charger_heartbeat_work",*(undefined4 *)(param_1 + -0xf4),
                 *(undefined1 *)(param_1 + -0xef),*(undefined1 *)(param_1 + -0xf0),
                 *(undefined4 *)(param_1 + -0xe8),*(undefined4 *)(param_1 + -0xe4),
                 *(undefined4 *)(param_1 + -0xe0),*(undefined4 *)(param_1 + -0xdc));
  if ((*(char *)(param_1 + -0xf0) == '\0') &&
     ((*(char *)(param_1 + -0xef) == '\0' || (*(char *)(param_1 + -0xd3) == '\0')))) {
LAB_00105c7c:
    cVar1 = *(char *)(param_1 + 0x3ac);
  }
  else if (*(int *)(param_1 + -0x118) < 1) {
    if ((*(char *)(param_1 + -0xee) == '\0') || (factory_kill_disable != 0)) {
      *(undefined1 *)(param_1 + -0xee) = 0;
      goto LAB_00105c7c;
    }
    ktime_get_real_ts64(&local_78);
    auVar3 = SEXT816(local_70 - _DAT_001070c0) * SEXT816(0x431bde82d7b634db);
    uVar2 = ((int)(auVar3._8_8_ >> 0x12) - (auVar3._12_4_ >> 0x1f)) +
            ((int)local_78 - mmi_charger_heartbeat_work_start) * 1000;
    if (uVar2 < *(uint *)(param_1 + 0x3a8)) {
      _printk(&DAT_00109661,*puVar6,"mmi_charger_heartbeat_work",uVar2);
      ipc_log_string(*(undefined8 *)(param_1 + 0x90),
                     "E %s: %s: Factory kill debounce elapsed_ms:%d\n",*puVar6,
                     "mmi_charger_heartbeat_work",uVar2);
      cVar1 = *(char *)(param_1 + 0x3ac);
    }
    else {
      if ((shutdown_triggered & 1) != 0) goto LAB_00105c7c;
      _printk(&DAT_00107e21,*puVar6,"mmi_charger_heartbeat_work");
      ipc_log_string(*(undefined8 *)(param_1 + 0x90),"E %s: %s: Factory kill power off\n",*puVar6,
                     "mmi_charger_heartbeat_work");
      shutdown_triggered = 1;
      kernel_power_off();
      cVar1 = *(char *)(param_1 + 0x3ac);
    }
  }
  else {
    if (**(char **)(param_1 + 0x88) != '\0') {
      _printk(&DAT_001094ee,*puVar6,"mmi_charger_heartbeat_work");
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x90),"D %s: %s: Factory Kill Armed\n",*puVar6,
                   "mmi_charger_heartbeat_work");
    *(undefined1 *)(param_1 + -0xee) = 1;
    ktime_get_real_ts64(&mmi_charger_heartbeat_work_start);
    cVar1 = *(char *)(param_1 + 0x3ac);
  }
  if ((cVar1 != '\0') && ((shutdown_triggered & 1) == 0)) {
    _printk(&DAT_00107a83,*puVar6,"mmi_charger_heartbeat_work");
    ipc_log_string(*(undefined8 *)(param_1 + 0x90),"E %s: %s: shutdown for empty battery voltage\n",
                   *puVar6,"mmi_charger_heartbeat_work");
    shutdown_triggered = 1;
    kernel_power_off();
  }
  *(undefined4 *)(param_1 + -0xf8) = 0;
  if (*(char *)(param_1 + -0xf0) == '\0') {
    if ((*(int *)(param_1 + -0x118) == 0) || (*(int *)(param_1 + -0x134) == 4)) {
      lVar5 = 0x3b0;
    }
    else {
      lVar5 = -0x38;
    }
  }
  else {
    lVar5 = -0x34;
  }
  uVar4 = __msecs_to_jiffies(*(undefined4 *)(param_1 + lVar5));
  queue_delayed_work_on(0x20,_system_wq,param_1,uVar4);
  if (((suspend_wakeups == 0) && (*(int *)(param_1 + -0x118) == 0)) ||
     (alarm_start_relative(param_1 + -0xb8,70000000000), *(int *)(param_1 + -0x118) == 0)) {
    pm_relax(*(undefined8 *)(param_1 + -0x1f0));
  }
  __pm_relax(*(undefined8 *)(param_1 + -0xc0));
LAB_00105d34:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mmi_heartbeat_alarm_cb @ 00105ec0 size=148
// signature: undefined mmi_heartbeat_alarm_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_heartbeat_alarm_cb(long param_1)

{
  _printk(&DAT_001073a8,*(undefined8 *)(param_1 + -0x140),"mmi_heartbeat_alarm_cb");
  ipc_log_string(*(undefined8 *)(param_1 + 0x148),"I %s: %s: HB alarm fired\n",
                 *(undefined8 *)(param_1 + -0x140),"mmi_heartbeat_alarm_cb");
  __pm_stay_awake(*(undefined8 *)(param_1 + -8));
  cancel_delayed_work(param_1 + 0xb8);
  queue_delayed_work_on(0x20,_system_wq,param_1 + 0xb8,0x7d);
  return 0;
}



//------------------------------------------------------------
// mmi_psy_notifier_call @ 00105f58 size=240
// signature: undefined mmi_psy_notifier_call(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_psy_notifier_call(long param_1,long param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *__s1;
  
  if (param_1 + -0x1e0 == 0) {
    _printk(&DAT_00107adb);
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if ((param_2 == 0) && (param_3 != (undefined8 *)0x0)) {
      if ((*(long *)(param_1 + -0x148) == 0) &&
         (iVar1 = strcmp(*(char **)*param_3,"battery"), iVar1 == 0)) {
        mmi_battery_supply_init(param_1 + -0x1e0);
      }
      __s1 = *(char **)*param_3;
      iVar1 = strcmp(__s1,"battery");
      if (((iVar1 == 0) || (iVar1 = strcmp(__s1,"usb"), iVar1 == 0)) ||
         (iVar1 = strcmp(__s1,"wireless"), iVar1 == 0)) {
        cancel_delayed_work(param_1 + 0x18);
        queue_delayed_work_on(0x20,_system_wq,param_1 + 0x18,0);
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// mmi_charger_reboot @ 0010604c size=280
// signature: undefined mmi_charger_reboot(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_charger_reboot(long param_1,long param_2)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + -0x1c8);
  if (puVar2 == (undefined8 *)0x0) {
    _printk(&DAT_00107adb);
  }
  else if ((*(char *)(param_1 + -0xc0) != '\0') && (_printk(&DAT_00107af8), param_2 == 3)) {
    factory_kill_disable = 1;
    *(undefined1 *)(param_1 + -0xbd) = 1;
    cancel_delayed_work(param_1 + 0x30);
    queue_delayed_work_on(0x20,_system_wq,param_1 + 0x30,0);
    iVar1 = *(int *)(param_1 + -0xe8);
    while ((iVar1 != 0 &&
           ((((shutdown_triggered & 1) != 0 || (*(char *)(param_1 + -0xa2) != '\0')) &&
            (*(char *)(param_1 + 0x3dc) == '\0'))))) {
      _printk(&DAT_00108abf,*puVar2,"mmi_charger_reboot");
      ipc_log_string(*(undefined8 *)(param_1 + 0xc0),"I %s: %s: Wait for charger removal\n",*puVar2,
                     "mmi_charger_reboot");
      msleep(100);
      iVar1 = *(int *)(param_1 + -0xe8);
    }
  }
  return 0;
}



//------------------------------------------------------------
// mmi_get_prop @ 00106168 size=464
// signature: undefined mmi_get_prop(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mmi_get_prop(undefined8 param_1,undefined4 param_2,int *param_3)

{
  undefined1 auVar1 [16];
  long lVar2;
  uint uVar3;
  int iVar4;
  long local_48;
  long local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = power_supply_get_drvdata();
  iVar4 = -0x16;
  local_48 = 0;
  local_40 = 0;
  switch(param_2) {
  case 0:
    iVar4 = *(int *)(lVar2 + 0xc4);
    break;
  case 2:
    iVar4 = *(int *)(lVar2 + 200);
    break;
  case 7:
    iVar4 = *(int *)(lVar2 + 0xb0) / 100 + *(int *)(lVar2 + 0xdc);
    break;
  case 0xc:
    iVar4 = *(int *)(lVar2 + 0xbc);
    goto LAB_001062f8;
  case 0x11:
    if (*(int *)(lVar2 + 0x5ac) != -1) {
      ktime_get_real_ts64(&local_48);
      if (local_48 < mmi_get_prop_start) {
        uVar3 = 0;
        mmi_get_prop_start = local_48;
        DAT_001070d8 = local_40;
      }
      else {
        auVar1 = SEXT816(local_40 - DAT_001070d8) * SEXT816(0x431bde82d7b634db);
        uVar3 = ((int)(auVar1._8_8_ >> 0x12) - (auVar1._12_4_ >> 0x1f)) +
                ((int)local_48 - (int)mmi_get_prop_start) * 1000;
      }
      if (*(uint *)(lVar2 + 0x5ac) <= uVar3) {
        cancel_delayed_work(lVar2 + 0x1f8);
        queue_delayed_work_on(0x20,_system_wq,lVar2 + 0x1f8,0);
        mmi_get_prop_start = local_48;
        DAT_001070d8 = local_40;
      }
    }
    iVar4 = *(int *)(lVar2 + 0xc0);
LAB_001062f8:
    iVar4 = iVar4 * 1000;
    break;
  case 0x16:
    iVar4 = *(int *)(lVar2 + 0xd8);
    break;
  case 0x18:
    iVar4 = *(int *)(lVar2 + 0xd4);
    break;
  case 0x1c:
    iVar4 = *(int *)(lVar2 + 0xd0);
    break;
  case 0x2f:
    iVar4 = *(int *)(lVar2 + 0xb4);
    break;
  case 0x34:
    iVar4 = *(int *)(lVar2 + 0xcc) * 10;
  }
  *param_3 = iVar4;
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// mmi_set_prop @ 0010633c size=64
// signature: undefined mmi_set_prop(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_set_prop(undefined8 param_1,int param_2,undefined4 *param_3)

{
  long lVar1;
  
  lVar1 = power_supply_get_drvdata();
  if (param_2 == 7) {
    *(undefined4 *)(lVar1 + 0xdc) = *param_3;
  }
  return 0;
}



//------------------------------------------------------------
// mmi_prop_is_writeable @ 00106380 size=12
// signature: undefined mmi_prop_is_writeable(void)
// callers: []
//------------------------------------------------------------

bool mmi_prop_is_writeable(undefined8 param_1,int param_2)

{
  return param_2 == 7;
}



//------------------------------------------------------------
// state_sync_store @ 00106390 size=432
// signature: undefined state_sync_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
state_sync_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_40);
    if (iVar2 == 0) {
      if (local_40 != 0) {
        mutex_lock(this_chip + 4);
        mmi_notify_charger_event(this_chip,0);
        mmi_notify_charger_event(this_chip,1);
        mmi_notify_charger_event(this_chip,2);
        mmi_notify_charger_event(this_chip,3);
        mmi_notify_charger_event(this_chip,4);
        mmi_notify_charger_event(this_chip,5);
        mutex_unlock(this_chip + 4);
        cancel_delayed_work(this_chip + 0x3f);
        queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
        _printk(&DAT_001097ad,*this_chip,"state_sync_store");
        ipc_log_string(this_chip[0x51],"I %s: %s: charger state sync received\n",*this_chip,
                       "state_sync_store");
      }
    }
    else {
      _printk(&DAT_001087a9,*this_chip,"state_sync_store",local_40);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid state_sync value = %lu\n",*this_chip,
                     "state_sync_store",local_40);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dcp_pmax_show @ 00106544 size=88
// signature: undefined dcp_pmax_show(void)
// callers: []
//------------------------------------------------------------

long dcp_pmax_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0x110));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// dcp_pmax_store @ 001065a0 size=292
// signature: undefined dcp_pmax_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
dcp_pmax_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      if ((local_30 != *(int *)(this_chip + 0x22)) && (local_30 - 5000U < 0x1389)) {
        puVar1 = this_chip + 0x3f;
        *(int *)(this_chip + 0x22) = (int)local_30;
        cancel_delayed_work(puVar1);
        queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      }
    }
    else {
      _printk(&DAT_001076ef,*this_chip,"dcp_pmax_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid dcp pmax value = %lu\n",*this_chip,
                     "dcp_pmax_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hvdcp_pmax_show @ 001066c8 size=88
// signature: undefined hvdcp_pmax_show(void)
// callers: []
//------------------------------------------------------------

long hvdcp_pmax_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0x114));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// hvdcp_pmax_store @ 00106724 size=296
// signature: undefined hvdcp_pmax_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
hvdcp_pmax_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      if ((local_30 != *(int *)((long)this_chip + 0x114)) && (local_30 - 0x1d4cU < 0x16955)) {
        puVar1 = this_chip + 0x3f;
        *(int *)((long)this_chip + 0x114) = (int)local_30;
        cancel_delayed_work(puVar1);
        queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      }
    }
    else {
      _printk(&DAT_00107ab1,*this_chip,"hvdcp_pmax_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid hvdcp pmax value = %lu\n",*this_chip,
                     "hvdcp_pmax_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// pd_pmax_show @ 00106850 size=88
// signature: undefined pd_pmax_show(void)
// callers: []
//------------------------------------------------------------

long pd_pmax_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0x118));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// pd_pmax_store @ 001068ac size=296
// signature: undefined pd_pmax_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
pd_pmax_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      if ((local_30 != *(int *)(this_chip + 0x23)) && (local_30 - 15000U < 0x14c09)) {
        puVar1 = this_chip + 0x3f;
        *(int *)(this_chip + 0x23) = (int)local_30;
        cancel_delayed_work(puVar1);
        queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      }
    }
    else {
      _printk(&DAT_00107717,*this_chip,"pd_pmax_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid pd pmax value = %lu\n",*this_chip,
                     "pd_pmax_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wls_pmax_show @ 001069d8 size=88
// signature: undefined wls_pmax_show(void)
// callers: []
//------------------------------------------------------------

long wls_pmax_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_00108aef);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_00107c8e,*(undefined4 *)(this_chip + 0x11c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// wls_pmax_store @ 00106a34 size=296
// signature: undefined wls_pmax_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
wls_pmax_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_00108aef);
    param_4 = 0xffffffffffffffed;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      if ((local_30 != *(int *)((long)this_chip + 0x11c)) && (local_30 - 5000U < 0x17319)) {
        puVar1 = this_chip + 0x3f;
        *(int *)((long)this_chip + 0x11c) = (int)local_30;
        cancel_delayed_work(puVar1);
        queue_delayed_work_on(0x20,_system_wq,this_chip + 0x3f,0);
      }
    }
    else {
      _printk(&DAT_00109094,*this_chip,"wls_pmax_store",local_30);
      ipc_log_string(this_chip[0x51],"E %s: %s: Invalid wireless pmax value = %lu\n",*this_chip,
                     "wls_pmax_store",local_30);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// mmi_charger_suspend @ 00106b60 size=32
// signature: undefined mmi_charger_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_charger_suspend(long param_1)

{
  *(uint *)(*(long *)(param_1 + 0x98) + 0x100) =
       *(uint *)(*(long *)(param_1 + 0x98) + 0x100) & 0xfffffffc | 1;
  return 0;
}



//------------------------------------------------------------
// mmi_charger_resume @ 00106b84 size=32
// signature: undefined mmi_charger_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_charger_resume(long param_1)

{
  *(uint *)(*(long *)(param_1 + 0x98) + 0x100) =
       *(uint *)(*(long *)(param_1 + 0x98) + 0x100) & 0xfffffffc | 2;
  return 0;
}



//------------------------------------------------------------
// init_module @ 00107044 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_charger_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00107074 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_charger_driver);
  return;
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 0010c000 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [mmi_get_battery_serialnumber, mmi_is_factory_version, mmi_is_factory_mode, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010c008 size=1
// signature: undefined of_property_read_string(void)
// callers: [mmi_get_battery_serialnumber, mmi_is_factory_version, mmi_is_factory_mode, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010c010 size=1
// signature: undefined _printk(void)
// callers: [force_demo_mode_store, factory_charge_upper_show, force_charging_enable_store, pd_pmax_store, state_sync_store, mmi_psy_notifier_call, dcp_pmax_show, first_usage_date_store, mmi_get_charger_configure, charge_rate_show, force_demo_mode_show, force_max_chrg_temp_show, mmi_vote_charger_suspend, force_max_chrg_temp_store, manufacturing_date_store, mmi_charger_heartbeat_work, hvdcp_pmax_show, wls_pmax_store, mmi_get_battery_serialnumber, hvdcp_pmax_store, factory_image_mode_store, age_show, force_charger_suspend_store, wls_pmax_show, mmi_vote, mmi_register_charger_driver, mmi_update_charger_status, mmi_battery_supply_init, force_charger_suspend_show, mmi_update_charger_profile, manufacturing_date_show, mmi_charger_shutdown, mmi_notify_charger_event, mmi_charger_probe, pd_pmax_show, force_charging_disable_store, mmi_get_charger_info, mmi_update_battery_status, dcp_pmax_store, mmi_configure_charger, mmi_vote_charging_disable, mmi_charger_reboot, factory_image_mode_show, first_usage_date_show, mmi_unregister_charger_driver, force_charging_enable_show, state_of_health_show, mmi_heartbeat_alarm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010c018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [force_demo_mode_store, force_charging_enable_store, pd_pmax_store, state_sync_store, mmi_register_charger_driver, first_usage_date_store, mmi_is_factory_version, mmi_charger_probe, force_max_chrg_temp_store, force_charging_disable_store, manufacturing_date_store, mmi_get_charger_info, mmi_charger_heartbeat_work, wls_pmax_store, mmi_get_battery_serialnumber, hvdcp_pmax_store, dcp_pmax_store, factory_image_mode_store, mmi_is_factory_mode, mmi_get_prop, force_charger_suspend_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bi_bootmode @ 0010c020 size=1
// signature: undefined bi_bootmode(void)
// callers: [mmi_is_factory_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bi_bootmode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 0010c028 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [mmi_is_factory_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 0010c030 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [mmi_is_factory_version, mmi_is_factory_mode, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strchr @ 0010c038 size=1
// signature: char * strchr(char * __s, int __c)
// callers: [mmi_is_factory_version, mmi_is_factory_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0010c040 size=1
// signature: undefined strnstr(void)
// callers: [mmi_is_factory_version, mmi_is_factory_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010c048 size=1
// signature: undefined mutex_lock(void)
// callers: [mmi_update_battery_status, state_sync_store, mmi_register_charger_driver, mmi_get_charger_configure, mmi_charger_heartbeat_work, mmi_unregister_charger_driver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010c050 size=1
// signature: undefined mutex_unlock(void)
// callers: [mmi_update_battery_status, state_sync_store, mmi_register_charger_driver, mmi_get_charger_configure, mmi_charger_heartbeat_work, mmi_unregister_charger_driver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010c058 size=1
// signature: undefined ipc_log_string(void)
// callers: [force_demo_mode_store, force_charging_enable_store, pd_pmax_store, state_sync_store, first_usage_date_store, force_max_chrg_temp_store, manufacturing_date_store, mmi_charger_heartbeat_work, wls_pmax_store, hvdcp_pmax_store, factory_image_mode_store, force_charger_suspend_store, mmi_vote, mmi_register_charger_driver, mmi_update_charger_status, mmi_battery_supply_init, mmi_update_charger_profile, mmi_charger_shutdown, mmi_notify_charger_event, mmi_charger_probe, force_charging_disable_store, mmi_get_charger_info, mmi_update_battery_status, dcp_pmax_store, mmi_configure_charger, mmi_charger_reboot, mmi_unregister_charger_driver, mmi_heartbeat_alarm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 0010c060 size=1
// signature: undefined power_supply_get_property(void)
// callers: [mmi_get_charger_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_changed @ 0010c068 size=1
// signature: undefined power_supply_changed(void)
// callers: [mmi_update_battery_status, mmi_register_charger_driver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_changed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010c070 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mmi_vote, mmi_register_charger_driver, mmi_psy_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010c078 size=1
// signature: undefined devm_kmalloc(void)
// callers: [mmi_register_charger_driver, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010c080 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mmi_register_charger_driver, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010c088 size=1
// signature: undefined of_find_property(void)
// callers: [mmi_register_charger_driver, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0010c090 size=1
// signature: undefined devm_kfree(void)
// callers: [mmi_register_charger_driver, mmi_unregister_charger_driver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010c098 size=1
// signature: undefined __list_add_valid(void)
// callers: [mmi_register_charger_driver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010c0a0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mmi_unregister_charger_driver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010c0a8 size=1
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
// platform_driver_unregister @ 0010c0b0 size=1
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
// kmalloc_trace @ 0010c0c0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mmi_notify_charger_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010c0c8 size=1
// signature: undefined scnprintf(void)
// callers: [factory_charge_upper_show, wls_pmax_show, dcp_pmax_show, force_charger_suspend_show, charge_rate_show, force_demo_mode_show, manufacturing_date_show, force_max_chrg_temp_show, pd_pmax_show, mmi_notify_charger_event, hvdcp_pmax_show, age_show, factory_image_mode_show, first_usage_date_show, force_charging_enable_show, state_of_health_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010c0d0 size=1
// signature: undefined kfree(void)
// callers: [mmi_charger_remove, mmi_notify_charger_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 0010c0d8 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [mmi_notify_charger_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 0010c0e0 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [mmi_battery_supply_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0010c0e8 size=1
// signature: undefined sysfs_create_group(void)
// callers: [mmi_battery_supply_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 0010c0f0 size=1
// signature: undefined device_create_file(void)
// callers: [mmi_battery_supply_init, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0010c0f8 size=1
// signature: undefined kstrtoull(void)
// callers: [force_demo_mode_store, force_charging_enable_store, pd_pmax_store, state_sync_store, first_usage_date_store, force_max_chrg_temp_store, force_charging_disable_store, manufacturing_date_store, wls_pmax_store, hvdcp_pmax_store, dcp_pmax_store, factory_image_mode_store, force_charger_suspend_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 0010c100 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [force_charging_enable_store, pd_pmax_store, state_sync_store, mmi_psy_notifier_call, mmi_charger_remove, mmi_charger_shutdown, mmi_charger_probe, force_charging_disable_store, wls_pmax_store, hvdcp_pmax_store, dcp_pmax_store, mmi_charger_reboot, mmi_get_prop, force_charger_suspend_store, mmi_heartbeat_alarm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0010c110 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [force_charging_enable_store, pd_pmax_store, state_sync_store, mmi_psy_notifier_call, mmi_charger_probe, force_charging_disable_store, mmi_charger_heartbeat_work, wls_pmax_store, hvdcp_pmax_store, dcp_pmax_store, mmi_charger_reboot, mmi_get_prop, force_charger_suspend_store, mmi_heartbeat_alarm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 0010c118 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 0010c120 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010c128 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010c130 size=1
// signature: undefined __mutex_init(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0010c140 size=1
// signature: undefined init_timer_key(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 0010c148 size=1
// signature: undefined wakeup_source_register(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alarm_init @ 0010c150 size=1
// signature: undefined alarm_init(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alarm_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_power_supply_register @ 0010c158 size=1
// signature: undefined devm_power_supply_register(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_power_supply_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 0010c160 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [mmi_charger_remove, mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 0010c168 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 0010c170 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [mmi_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 0010c178 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [mmi_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 0010c180 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [mmi_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 0010c188 size=1
// signature: undefined device_remove_file(void)
// callers: [mmi_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 0010c190 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [mmi_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 0010c198 size=1
// signature: undefined power_supply_put(void)
// callers: [mmi_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 0010c1a0 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [mmi_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 0010c1a8 size=1
// signature: undefined pm_stay_awake(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alarm_cancel @ 0010c1b0 size=1
// signature: undefined alarm_cancel(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alarm_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 0010c1b8 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [mmi_get_prop, mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_power_off @ 0010c1c0 size=1
// signature: undefined kernel_power_off(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_power_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0010c1c8 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alarm_start_relative @ 0010c1d0 size=1
// signature: undefined alarm_start_relative(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alarm_start_relative(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 0010c1d8 size=1
// signature: undefined pm_relax(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 0010c1e0 size=1
// signature: undefined __pm_relax(void)
// callers: [mmi_charger_heartbeat_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_stay_awake @ 0010c1e8 size=1
// signature: undefined __pm_stay_awake(void)
// callers: [mmi_heartbeat_alarm_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010c1f0 size=1
// signature: undefined msleep(void)
// callers: [mmi_charger_reboot]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_drvdata @ 0010c1f8 size=1
// signature: undefined power_supply_get_drvdata(void)
// callers: [mmi_set_prop, mmi_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



