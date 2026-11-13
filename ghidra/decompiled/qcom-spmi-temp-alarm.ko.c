// Decompiled by Ghidra 12.2
// Program: qcom-spmi-temp-alarm.ko
// Image base: 00100000

//------------------------------------------------------------
// qpnp_tm_probe @ 001003d4 size=1168
// signature: undefined qpnp_tm_probe(void)
// callers: []
//------------------------------------------------------------

int qpnp_tm_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  ulong uVar8;
  char *pcVar9;
  undefined1 *puVar10;
  undefined8 *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int local_60;
  uint local_5c;
  long local_58;
  
  lVar7 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_58 = *(long *)(lVar7 + 0x638);
  puVar11 = *(undefined8 **)(param_1 + 0x2f8);
  local_60 = 0;
  plVar6 = (long *)devm_kmalloc(lVar1,0xa8,0xdc0);
  if (plVar6 == (long *)0x0) {
    iVar5 = -0xc;
    goto LAB_001007a8;
  }
  *(long **)(param_1 + 0xa8) = plVar6;
  plVar6[1] = lVar1;
  __mutex_init(plVar6 + 8,"&chip->lock",&qpnp_tm_probe___key);
  lVar7 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
  *plVar6 = lVar7;
  if (lVar7 == 0) {
    iVar5 = -6;
    goto LAB_001007a8;
  }
  iVar5 = of_property_read_variable_u32_array(puVar11,&DAT_00101e3f,&local_60,1,0);
  if (iVar5 < 0) goto LAB_001007a8;
  iVar5 = platform_get_irq(param_1,0);
  *(int *)(plVar6 + 7) = iVar5;
  if (iVar5 < 0) goto LAB_001007a8;
  uVar8 = devm_iio_channel_get(lVar1,"thermal");
  plVar6[0xf] = uVar8;
  if ((0xfffffffffffff000 < uVar8) && (plVar6[0xf] = 0, (int)uVar8 == -0x205)) {
    iVar5 = -0x205;
    goto LAB_001007a8;
  }
  local_5c = 0;
  *(int *)((long)plVar6 + 0x34) = local_60;
  iVar5 = regmap_read(*plVar6,local_60 + 4,&local_5c);
  uVar2 = local_5c;
  if (iVar5 < 0) {
    pcVar9 = "could not read type\n";
  }
  else {
    local_5c = 0;
    iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 5,&local_5c);
    uVar14 = local_5c;
    if (iVar5 < 0) {
      pcVar9 = "could not read subtype\n";
    }
    else {
      uVar12 = local_5c & 0xff;
      local_5c = 0;
      iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 1,&local_5c);
      uVar3 = local_5c;
      if (iVar5 < 0) {
        pcVar9 = "could not read dig_major\n";
      }
      else {
        local_5c = 0;
        iVar5 = regmap_read(*plVar6,*(undefined4 *)((long)plVar6 + 0x34),&local_5c);
        uVar4 = local_5c;
        if (iVar5 < 0) {
          iVar5 = dev_err_probe(lVar1,iVar5,"could not read dig_minor\n");
          goto LAB_001007a8;
        }
        if (((uVar2 & 0xff) != 9) || ((uVar13 = uVar14 & 0xff, 1 < uVar13 - 8 && (uVar13 != 0xc0))))
        {
          _dev_err(lVar1,"invalid type 0x%02x or subtype 0x%02x\n",uVar2 & 0xff,uVar12);
          iVar5 = -0x13;
          goto LAB_001007a8;
        }
        uVar2 = uVar3 & 0xff;
        uVar14 = uVar14 & 0xff;
        *(uint *)(plVar6 + 3) = uVar14;
        if ((uVar14 == 9) && (1 < uVar2)) {
          *(undefined1 *)(plVar6 + 0x11) = 1;
        }
        else {
          if ((uVar14 == 9) && (uVar2 != 0)) {
            puVar10 = temp_map_gen2_v1;
          }
          else {
            if (uVar14 != 8) goto LAB_001005e0;
            puVar10 = temp_map_gen1;
          }
          plVar6[0x10] = (long)puVar10;
        }
LAB_001005e0:
        if ((char)plVar6[0x11] == '\0') {
          puVar10 = qpnp_tm_sensor_ops;
        }
        else {
          local_5c = 0;
          iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 0x47,&local_5c);
          if (iVar5 < 0) goto LAB_001007a8;
          uVar8 = (ulong)(byte)local_5c;
          local_5c = 0;
          plVar6[0x12] = uVar8 * 0x271 + 80000;
          iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 0x48,&local_5c);
          if (iVar5 < 0) goto LAB_001007a8;
          uVar8 = (ulong)(byte)local_5c;
          local_5c = 0;
          plVar6[0x13] = uVar8 * 0x271 + 80000;
          iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 0x49,&local_5c);
          if (iVar5 < 0) goto LAB_001007a8;
          puVar10 = qpnp_tm_sensor_temp_dac_ops;
          uVar12 = *(uint *)(plVar6 + 3);
          plVar6[0x14] = (ulong)(byte)local_5c * 0x271 + 80000;
        }
        if (uVar12 == 0xc0) {
          local_5c = 0;
          iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 0x50,&local_5c,puVar10);
          if (iVar5 < 0) goto LAB_001007a8;
          uVar2 = local_5c >> 2;
          local_5c = 0;
          plVar6[0x12] = (&temp_map_lite_warning)[(ulong)uVar2 & 3];
          iVar5 = regmap_read(*plVar6,*(int *)((long)plVar6 + 0x34) + 0x51,&local_5c);
          if (iVar5 < 0) goto LAB_001007a8;
          uVar12 = *(uint *)(plVar6 + 3);
          puVar10 = qpnp_tm_sensor_temp_lite_ops;
          plVar6[0x14] = (&temp_map_lite_shutdown)[(ulong)(local_5c >> 2) & 3];
        }
        if ((uVar12 == 9) &&
           ((uVar2 = uVar4 & 0xff | (uVar3 & 0xff) << 8, uVar2 - 0x100 < 2 || (uVar2 - 1 < 2)))) {
          *(undefined1 *)((long)plVar6 + 0x71) = 1;
        }
        uVar8 = devm_thermal_of_zone_register(lVar1,0,plVar6,puVar10);
        plVar6[2] = uVar8;
        if (0xfffffffffffff000 < uVar8) {
          _dev_err(lVar1,"failed to register sensor\n");
          iVar5 = (int)plVar6[2];
          goto LAB_001007a8;
        }
        iVar5 = qpnp_tm_init(plVar6);
        if (-1 < iVar5) {
          iVar5 = devm_request_threaded_irq
                            (lVar1,(int)plVar6[7],0,qpnp_tm_isr,0x2000,*puVar11,plVar6);
          if (-1 < iVar5) {
            thermal_zone_device_update(plVar6[2],0);
            iVar5 = 0;
          }
          goto LAB_001007a8;
        }
        pcVar9 = "init failed\n";
      }
    }
  }
  _dev_err(lVar1,pcVar9);
LAB_001007a8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qpnp_tm_shutdown @ 00100868 size=48
// signature: undefined qpnp_tm_shutdown(void)
// callers: []
//------------------------------------------------------------

void qpnp_tm_shutdown(long param_1)

{
  if (0 < *(int *)(*(long *)(param_1 + 0xa8) + 0x38)) {
    devm_free_irq(*(undefined8 *)(*(long *)(param_1 + 0xa8) + 8));
  }
  return;
}



//------------------------------------------------------------
// qpnp_tm_init @ 00100898 size=884
// signature: undefined qpnp_tm_init(void)
// callers: [qpnp_tm_resume, qpnp_tm_probe, qpnp_tm_restore]
//------------------------------------------------------------

int qpnp_tm_init(undefined8 *param_1)

{
  long lVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 *puVar11;
  undefined8 uVar10;
  ulong uVar12;
  int *piVar13;
  uint local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  mutex_lock(param_1 + 8);
  local_4c = 0;
  iVar3 = regmap_read(*param_1,*(int *)((long)param_1 + 0x34) + 0x40,&local_4c);
  if (iVar3 < 0) goto LAB_00100b98;
  iVar3 = 0x10;
  if (*(int *)(param_1 + 3) != 0xc0) {
    iVar3 = 8;
  }
  param_1[4] = 37000;
  *(uint *)(param_1 + 5) = local_4c & 3;
  local_4c = 0;
  iVar3 = regmap_read(*param_1,*(int *)((long)param_1 + 0x34) + iVar3,&local_4c);
  if (iVar3 < 0) goto LAB_00100b98;
  iVar3 = *(int *)(param_1 + 3);
  if (iVar3 == 8) {
    uVar4 = 3;
LAB_00100954:
    uVar4 = local_4c & uVar4;
    *(uint *)((long)param_1 + 0x2c) = uVar4;
    if (uVar4 != 0) goto LAB_00100960;
LAB_001009b4:
    if (iVar3 == 0xc0) goto LAB_001009bc;
LAB_00100a54:
    cVar2 = *(char *)(param_1 + 0x11);
    uVar4 = of_thermal_get_ntrips(param_1[2]);
    if (cVar2 == '\0') {
      iVar3 = -0x42e50;
      if ((0 < (int)uVar4) && (lVar7 = of_thermal_get_trip_points(param_1[2]), lVar7 != 0)) {
        uVar12 = 0;
        piVar13 = (int *)(lVar7 + 8);
        do {
          uVar6 = of_thermal_is_trip_valid(param_1[2],uVar12 & 0xffffffff);
          if (((uVar6 & 1) != 0) && (*piVar13 == 3)) {
            iVar3 = piVar13[-2];
            break;
          }
          uVar12 = uVar12 + 1;
          piVar13 = piVar13 + 3;
        } while (uVar4 != uVar12);
      }
      iVar3 = qpnp_tm_update_critical_trip_temp(param_1,iVar3);
      if (iVar3 < 0) goto LAB_00100b98;
    }
    else if (0 < (int)uVar4) {
      puVar5 = (undefined4 *)of_thermal_get_trip_points(param_1[2]);
      if (puVar5 == (undefined4 *)0x0) goto LAB_00100b58;
      uVar12 = 0;
      do {
        uVar6 = of_thermal_is_trip_valid(param_1[2],uVar12 & 0xffffffff);
        if (((uVar6 & 1) != 0) &&
           (iVar3 = qpnp_tm_set_temp_dac_thresh(param_1,uVar12 & 0xffffffff,*puVar5), iVar3 < 0))
        goto LAB_00100b98;
        uVar12 = uVar12 + 1;
        puVar5 = puVar5 + 3;
      } while (uVar4 != uVar12);
      lVar7 = param_1[0x12];
      lVar1 = param_1[0x13];
      if (lVar7 < lVar1) {
        if (lVar1 < (long)param_1[0x14]) goto LAB_00100b78;
        uVar9 = 1;
        uVar10 = 2;
        lVar8 = param_1[0x14];
        lVar7 = lVar1;
      }
      else {
        uVar9 = 0;
        uVar10 = 1;
        lVar8 = lVar1;
      }
      _dev_err(param_1[1],"Threshold %d=%ld <= threshold %d=%ld\n",uVar10,lVar8,uVar9,lVar7);
      iVar3 = -0x16;
      goto LAB_00100b98;
    }
  }
  else {
    if (iVar3 == 0xc0) {
      uVar4 = 1;
      goto LAB_00100954;
    }
    uVar12 = (ulong)(local_4c >> 4) & 7;
    *(int *)((long)param_1 + 0x2c) = (int)uVar12;
    uVar4 = *(uint *)(&alarm_state_map + uVar12 * 4);
    if (uVar4 == 0) goto LAB_001009b4;
LAB_00100960:
    if ((iVar3 == 0xc0) || (*(char *)(param_1 + 0x11) != '\0')) {
      if (uVar4 - 4 < 0xfffffffd) goto LAB_00100a30;
      puVar11 = param_1 + (ulong)(uVar4 - 1) + 0x12;
LAB_00100a44:
      uVar10 = *puVar11;
    }
    else {
      if ((param_1[0x10] != 0) && ((*(uint *)(param_1 + 5) | uVar4) < 4)) {
        puVar11 = (undefined8 *)
                  (param_1[0x10] + (ulong)*(uint *)(param_1 + 5) * 0x18 + (ulong)(uVar4 - 1) * 8);
        goto LAB_00100a44;
      }
LAB_00100a30:
      uVar10 = 0;
    }
    param_1[4] = uVar10;
    if (iVar3 != 0xc0) goto LAB_00100a54;
LAB_001009bc:
    uVar4 = of_thermal_get_ntrips(param_1[2]);
    if (0 < (int)uVar4) {
      puVar5 = (undefined4 *)of_thermal_get_trip_points(param_1[2]);
      if (puVar5 != (undefined4 *)0x0) {
        uVar12 = 0;
        do {
          uVar6 = of_thermal_is_trip_valid(param_1[2],uVar12 & 0xffffffff);
          if (((uVar6 & 1) != 0) &&
             (iVar3 = qpnp_tm_set_temp_lite_thresh(param_1,uVar12 & 0xffffffff,*puVar5), iVar3 < 0))
          goto LAB_00100b98;
          uVar12 = uVar12 + 1;
          puVar5 = puVar5 + 3;
        } while (uVar4 != uVar12);
        if ((long)param_1[0x12] < (long)param_1[0x14]) goto LAB_00100b78;
        _dev_err(param_1[1],"Threshold 2=%ld <= threshold 0=%ld\n");
      }
LAB_00100b58:
      iVar3 = -0x16;
      goto LAB_00100b98;
    }
  }
LAB_00100b78:
  iVar3 = regmap_write(*param_1,*(int *)((long)param_1 + 0x34) + 0x46,0x80);
  *(undefined1 *)(param_1 + 0xe) = 1;
LAB_00100b98:
  mutex_unlock(param_1 + 8);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qpnp_tm_isr @ 00100c10 size=40
// signature: undefined qpnp_tm_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_tm_isr(undefined8 param_1,long param_2)

{
  thermal_zone_device_update(*(undefined8 *)(param_2 + 0x10),0);
  return 1;
}



//------------------------------------------------------------
// qpnp_tm_get_temp @ 00100c3c size=600
// signature: undefined qpnp_tm_get_temp(void)
// callers: []
//------------------------------------------------------------

int qpnp_tm_get_temp(long param_1,int *param_2)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  long *plVar7;
  long lVar8;
  uint *puVar9;
  undefined8 *puVar10;
  int local_40;
  uint local_3c;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  puVar10 = *(undefined8 **)(param_1 + 0x3f0);
  local_40 = 0;
  if (param_2 == (int *)0x0) {
    iVar3 = -0x16;
    goto LAB_00100e58;
  }
  if (*(char *)(puVar10 + 0xe) == '\0') {
    iVar3 = 0;
    *param_2 = 37000;
    goto LAB_00100e58;
  }
  if (puVar10[0xf] == 0) {
    puVar1 = puVar10 + 8;
    mutex_lock(puVar1);
    uVar4 = mutex_is_locked(puVar1);
    if ((uVar4 & 1) == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100e8c);
      (*pcVar2)();
    }
    local_3c = 0;
    iVar3 = 0x10;
    if (*(int *)(puVar10 + 3) != 0xc0) {
      iVar3 = 8;
    }
    iVar3 = regmap_read(*puVar10,*(int *)((long)puVar10 + 0x34) + iVar3,&local_3c);
    if (iVar3 < 0) {
      mutex_unlock(puVar1);
      goto LAB_00100e58;
    }
    iVar3 = *(int *)(puVar10 + 3);
    if (iVar3 == 8) {
      uVar6 = 3;
LAB_00100d34:
      uVar6 = uVar6 & local_3c;
      uVar4 = (ulong)uVar6;
      puVar9 = (uint *)((long)puVar10 + 0x2c);
    }
    else {
      if (iVar3 == 0xc0) {
        uVar6 = 1;
        goto LAB_00100d34;
      }
      if (7 < *(uint *)((long)puVar10 + 0x2c)) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100e98);
        (*pcVar2)();
      }
      uVar4 = (ulong)(local_3c >> 4) & 7;
      puVar9 = (uint *)(&alarm_state_map + (ulong)*(uint *)((long)puVar10 + 0x2c) * 4);
      uVar6 = *(uint *)(&alarm_state_map + uVar4 * 4);
    }
    if (*puVar9 < uVar6) {
      if ((iVar3 == 0xc0) || (*(char *)(puVar10 + 0x11) != '\0')) {
        if (uVar6 - 4 < 0xfffffffd) goto LAB_00100dfc;
        lVar8 = 2000;
        plVar7 = puVar10 + (ulong)(uVar6 - 1) + 0x12;
LAB_00100e34:
        lVar8 = *plVar7 + lVar8;
      }
      else {
        if ((puVar10[0x10] != 0) && ((*(uint *)(puVar10 + 5) | uVar6) < 4)) {
          plVar7 = (long *)(puVar10[0x10] + (ulong)*(uint *)(puVar10 + 5) * 0x18 +
                           (ulong)(uVar6 - 1) * 8);
          lVar8 = 2000;
          goto LAB_00100e34;
        }
LAB_00100dfc:
        lVar8 = 2000;
      }
LAB_00100e3c:
      puVar10[4] = lVar8;
    }
    else if (uVar6 < *puVar9) {
      if ((iVar3 == 0xc0) || (*(char *)(puVar10 + 0x11) != '\0')) {
        if (2 < uVar6) goto LAB_00100e0c;
        plVar7 = puVar10 + (ulong)uVar6 + 0x12;
      }
      else {
        if ((puVar10[0x10] == 0) || (3 < (*(uint *)(puVar10 + 5) | uVar6 + 1))) {
LAB_00100e0c:
          lVar8 = -2000;
          goto LAB_00100e3c;
        }
        plVar7 = (long *)(puVar10[0x10] + (ulong)*(uint *)(puVar10 + 5) * 0x18 + (ulong)uVar6 * 8);
      }
      lVar8 = -2000;
      goto LAB_00100e34;
    }
    *(int *)((long)puVar10 + 0x2c) = (int)uVar4;
    mutex_unlock(puVar1);
    iVar5 = *(int *)(puVar10 + 4);
  }
  else {
    iVar3 = iio_read_channel_processed(puVar10[0xf],&local_40);
    if (iVar3 < 0) goto LAB_00100e58;
    puVar10[4] = (long)local_40;
    iVar5 = local_40;
  }
  iVar3 = 0;
  *param_2 = iVar5;
LAB_00100e58:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qpnp_tm_set_trip_temp @ 00100e9c size=140
// signature: undefined qpnp_tm_set_trip_temp(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_tm_set_trip_temp(long param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3f0);
  lVar2 = of_thermal_get_trip_points(*(undefined8 *)(lVar3 + 0x10));
  if (lVar2 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (*(int *)(lVar2 + (long)param_2 * 0xc + 8) == 3) {
    mutex_lock(lVar3 + 0x40);
    uVar1 = qpnp_tm_update_critical_trip_temp(lVar3,param_3);
    mutex_unlock(lVar3 + 0x40);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qpnp_tm_update_critical_trip_temp @ 00100f28 size=264
// signature: undefined qpnp_tm_update_critical_trip_temp(void)
// callers: [qpnp_tm_set_trip_temp, qpnp_tm_init]
//------------------------------------------------------------

void qpnp_tm_update_critical_trip_temp(undefined8 *param_1,int param_2)

{
  undefined1 auVar1 [16];
  code *pcVar2;
  ulong uVar3;
  uint uVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1[0x10] + 8);
  lVar7 = *(long *)(param_1[0x10] + 0x50);
  uVar3 = mutex_is_locked(param_1 + 8);
  if ((uVar3 & 1) == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101030);
    (*pcVar2)();
  }
  if ((param_2 == -0x42e50) || (lVar5 = (long)param_2, lVar5 < lVar8)) {
    uVar6 = 8;
    *(undefined4 *)(param_1 + 5) = 0;
  }
  else {
    if (lVar7 < lVar5) {
      uVar4 = 3;
      *(undefined4 *)(param_1 + 5) = 3;
      if (param_1[0xf] == 0) {
        _dev_warn(param_1[1],
                  "No ADC is configured and critical temperature %d mC is above the maximum stage 2 threshold of %ld mC! Configuring stage 2 shutdown at %ld mC.\n"
                  ,param_2,lVar7,lVar7);
        uVar6 = *(uint *)(param_1 + 5) | 8;
        goto LAB_00101004;
      }
    }
    else {
      auVar1 = SEXT816(lVar7 - lVar5) * SEXT816(-0x346dc5d63886594b);
      uVar4 = ((int)(auVar1._8_8_ >> 10) - (auVar1._12_4_ >> 0x1f)) + 3;
      *(uint *)(param_1 + 5) = uVar4;
    }
    uVar6 = 0x48;
    if (*(char *)((long)param_1 + 0x71) != '\0') {
      uVar6 = 8;
    }
    uVar6 = uVar6 | uVar4;
  }
LAB_00101004:
  regmap_write(*param_1,*(int *)((long)param_1 + 0x34) + 0x40,uVar6 & 0xff);
  return;
}



//------------------------------------------------------------
// qpnp_tm_set_temp_dac_trip_temp @ 00101038 size=96
// signature: undefined qpnp_tm_set_temp_dac_trip_temp(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_tm_set_temp_dac_trip_temp(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3f0);
  lVar1 = lVar3 + 0x40;
  mutex_lock(lVar1);
  uVar2 = qpnp_tm_set_temp_dac_thresh(lVar3,param_2,param_3);
  mutex_unlock(lVar1);
  return uVar2;
}



//------------------------------------------------------------
// qpnp_tm_set_temp_dac_thresh @ 00101098 size=280
// signature: undefined qpnp_tm_set_temp_dac_thresh(void)
// callers: [qpnp_tm_set_temp_dac_trip_temp, qpnp_tm_init]
//------------------------------------------------------------

int qpnp_tm_set_temp_dac_thresh(undefined8 *param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  ulong uVar6;
  
  uVar6 = (ulong)param_2;
  if (param_2 < 3) {
    if (79999 < (int)param_3) {
      if (2 < param_2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1011b0);
        (*pcVar2)();
      }
      if ((long)(param_3 & 0xffffffff) <= *(long *)(temp_dac_max + (ulong)param_2 * 8)) {
        iVar3 = (int)param_3 * 8 + -640000;
        uVar1 = (uint)((ulong)((long)iVar3 * 0x68db8bad) >> 0x2b) - (iVar3 >> 0x1f) & 0xff;
        iVar3 = regmap_write(*param_1,param_2 + *(int *)((long)param_1 + 0x34) + 0x47,uVar1);
        if (iVar3 < 0) {
          _dev_err(param_1[1],"TEMP_DAC_STG write failed, ret=%d\n",iVar3);
          return iVar3;
        }
        param_1[(ulong)param_2 + 0x12] = (ulong)(uVar1 * 0x271 + 80000);
        return 0;
      }
    }
    uVar4 = param_1[1];
    pcVar5 = "invalid TEMP_DAC temp = %d\n";
    uVar6 = param_3;
  }
  else {
    uVar4 = param_1[1];
    pcVar5 = "invalid TEMP_DAC trip = %d\n";
  }
  _dev_err(uVar4,pcVar5,uVar6);
  return -0x16;
}



//------------------------------------------------------------
// qpnp_tm_set_temp_lite_trip_temp @ 001011b4 size=96
// signature: undefined qpnp_tm_set_temp_lite_trip_temp(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_tm_set_temp_lite_trip_temp(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3f0);
  lVar1 = lVar3 + 0x40;
  mutex_lock(lVar1);
  uVar2 = qpnp_tm_set_temp_lite_thresh(lVar3,param_2,param_3);
  mutex_unlock(lVar1);
  return uVar2;
}



//------------------------------------------------------------
// qpnp_tm_set_temp_lite_thresh @ 00101214 size=424
// signature: undefined qpnp_tm_set_temp_lite_thresh(void)
// callers: [qpnp_tm_set_temp_lite_trip_temp, qpnp_tm_init]
//------------------------------------------------------------

int qpnp_tm_set_temp_lite_thresh(undefined8 *param_1,uint param_2,ulong param_3)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  int iVar9;
  uint uVar10;
  uint local_4c;
  long local_48;
  
  lVar8 = sp_el0;
  uVar4 = (ulong)param_2;
  local_48 = *(long *)(lVar8 + 0x638);
  if (param_2 < 3) {
    if (param_2 == 0) {
      iVar9 = 0x50;
      plVar7 = &temp_map_lite_warning;
LAB_00101274:
      lVar8 = (long)(int)param_3;
      if ((lVar8 < *plVar7) || (lVar5 = plVar7[3], lVar5 < lVar8)) {
        uVar2 = param_1[1];
        pcVar3 = "invalid TEMP_LITE temp = %d\n";
        uVar4 = param_3;
        goto LAB_0010134c;
      }
      if (lVar8 < lVar5) {
        lVar5 = plVar7[2];
        if (lVar8 < lVar5) {
          lVar6 = plVar7[1];
          lVar5 = *plVar7;
          if (lVar6 <= lVar8) {
            lVar5 = lVar6;
          }
          uVar10 = (uint)(lVar6 <= lVar8) << 2;
        }
        else {
          uVar10 = 8;
        }
      }
      else {
        uVar10 = 0xc;
      }
      if ((long)(int)lVar5 != param_1[uVar4 + 0x12]) {
        local_4c = 0;
        iVar1 = regmap_read(*param_1,*(int *)((long)param_1 + 0x34) + iVar9,&local_4c);
        if (iVar1 < 0) {
          uVar2 = param_1[1];
          pcVar3 = "LITE_TEMP_CFG read failed, ret=%d\n";
        }
        else {
          iVar1 = regmap_write(*param_1,*(int *)((long)param_1 + 0x34) + iVar9,
                               local_4c & 0xf3 | uVar10);
          if (-1 < iVar1) {
            iVar1 = 0;
            param_1[uVar4 + 0x12] = (long)(int)lVar5;
            goto LAB_00101354;
          }
          uVar2 = param_1[1];
          pcVar3 = "LITE_TEMP_CFG write failed, ret=%d\n";
        }
        _dev_err(uVar2,pcVar3,iVar1);
        goto LAB_00101354;
      }
    }
    else if (param_2 == 2) {
      iVar9 = 0x51;
      plVar7 = &temp_map_lite_shutdown;
      goto LAB_00101274;
    }
    iVar1 = 0;
  }
  else {
    uVar2 = param_1[1];
    pcVar3 = "invalid TEMP_LITE trip = %d\n";
LAB_0010134c:
    _dev_err(uVar2,pcVar3,uVar4);
    iVar1 = -0x16;
  }
LAB_00101354:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// qpnp_tm_suspend @ 001013c0 size=64
// signature: undefined qpnp_tm_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qpnp_tm_suspend(long param_1)

{
  if (_pm_suspend_target_state == 3) {
    if (0 < *(int *)(*(long *)(param_1 + 0x98) + 0x38)) {
      devm_free_irq();
    }
  }
  return 0;
}



//------------------------------------------------------------
// qpnp_tm_resume @ 00101404 size=184
// signature: undefined qpnp_tm_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qpnp_tm_resume(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  if (_pm_suspend_target_state == 3) {
    lVar3 = *(long *)(param_1 + 0x98);
    if (0 < *(int *)(lVar3 + 0x38)) {
      uVar1 = 0x2003;
      if (*(int *)(lVar3 + 0x18) != 9) {
        uVar1 = 0x2001;
      }
      iVar2 = devm_request_threaded_irq
                        (param_1,*(int *)(lVar3 + 0x38),0,qpnp_tm_isr,uVar1,
                         **(undefined8 **)(param_1 + 0x2e8),lVar3);
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    iVar2 = qpnp_tm_init(lVar3);
    if (iVar2 < 0) {
      _dev_err(param_1,"init failed\n");
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// qpnp_tm_freeze @ 001014c0 size=48
// signature: undefined qpnp_tm_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_tm_freeze(long param_1)

{
  if (0 < *(int *)(*(long *)(param_1 + 0x98) + 0x38)) {
    devm_free_irq();
  }
  return 0;
}



//------------------------------------------------------------
// qpnp_tm_restore @ 001014f4 size=160
// signature: undefined qpnp_tm_restore(void)
// callers: []
//------------------------------------------------------------

int qpnp_tm_restore(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (0 < *(int *)(lVar3 + 0x38)) {
    uVar1 = 0x2003;
    if (*(int *)(lVar3 + 0x18) != 9) {
      uVar1 = 0x2001;
    }
    iVar2 = devm_request_threaded_irq
                      (param_1,*(int *)(lVar3 + 0x38),0,qpnp_tm_isr,uVar1,
                       **(undefined8 **)(param_1 + 0x2e8),lVar3);
    if (iVar2 < 0) {
      return iVar2;
    }
  }
  iVar2 = qpnp_tm_init(lVar3);
  if (iVar2 < 0) {
    _dev_err(param_1,"init failed\n");
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00101598 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qpnp_tm_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001015c8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qpnp_tm_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
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
// devm_kmalloc @ 00103010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qpnp_tm_probe]
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
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00103020 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00103030 size=1
// signature: undefined platform_get_irq(void)
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_iio_channel_get @ 00103038 size=1
// signature: undefined devm_iio_channel_get(void)
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iio_channel_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00103040 size=1
// signature: undefined regmap_read(void)
// callers: [qpnp_tm_set_temp_lite_thresh, qpnp_tm_init, qpnp_tm_probe, qpnp_tm_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00103048 size=1
// signature: undefined dev_err_probe(void)
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 00103050 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [qpnp_tm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00103058 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qpnp_tm_resume, qpnp_tm_probe, qpnp_tm_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 00103060 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [qpnp_tm_probe, qpnp_tm_isr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103068 size=1
// signature: undefined _dev_err(void)
// callers: [qpnp_tm_set_temp_lite_thresh, qpnp_tm_resume, qpnp_tm_init, qpnp_tm_probe, qpnp_tm_set_temp_dac_thresh, qpnp_tm_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qpnp_tm_set_temp_lite_thresh, qpnp_tm_init, qpnp_tm_probe, qpnp_tm_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00103078 size=1
// signature: undefined devm_free_irq(void)
// callers: [qpnp_tm_freeze, qpnp_tm_suspend, qpnp_tm_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103080 size=1
// signature: undefined mutex_lock(void)
// callers: [qpnp_tm_set_temp_lite_trip_temp, qpnp_tm_set_trip_temp, qpnp_tm_set_temp_dac_trip_temp, qpnp_tm_init, qpnp_tm_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_thermal_get_ntrips @ 00103088 size=1
// signature: undefined of_thermal_get_ntrips(void)
// callers: [qpnp_tm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_thermal_get_ntrips(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_thermal_get_trip_points @ 00103090 size=1
// signature: undefined of_thermal_get_trip_points(void)
// callers: [qpnp_tm_set_trip_temp, qpnp_tm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_thermal_get_trip_points(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_thermal_is_trip_valid @ 00103098 size=1
// signature: undefined of_thermal_is_trip_valid(void)
// callers: [qpnp_tm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_thermal_is_trip_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001030a0 size=1
// signature: undefined regmap_write(void)
// callers: [qpnp_tm_update_critical_trip_temp, qpnp_tm_set_temp_lite_thresh, qpnp_tm_init, qpnp_tm_set_temp_dac_thresh]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001030a8 size=1
// signature: undefined mutex_unlock(void)
// callers: [qpnp_tm_set_temp_lite_trip_temp, qpnp_tm_set_trip_temp, qpnp_tm_set_temp_dac_trip_temp, qpnp_tm_init, qpnp_tm_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iio_read_channel_processed @ 001030b0 size=1
// signature: undefined iio_read_channel_processed(void)
// callers: [qpnp_tm_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iio_read_channel_processed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_is_locked @ 001030b8 size=1
// signature: undefined mutex_is_locked(void)
// callers: [qpnp_tm_update_critical_trip_temp, qpnp_tm_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001030c0 size=1
// signature: undefined _dev_warn(void)
// callers: [qpnp_tm_update_critical_trip_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



