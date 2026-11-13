// Decompiled by Ghidra 12.2
// Program: qcom_tsens.ko
// Image base: 00100000

//------------------------------------------------------------
// qfprom_read @ 00100b3c size=128
// signature: undefined qfprom_read(void)
// callers: [calibrate_v1, calibrate_8960, calibrate_9607, calibrate_8939, calibrate_8976, calibrate_8916, calibrate_8974]
//------------------------------------------------------------

ulong qfprom_read(void)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  uVar2 = nvmem_cell_get();
  uVar3 = uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    uVar3 = nvmem_cell_read(uVar2,&local_30);
    nvmem_cell_put(uVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// compute_intercept_slope @ 00100bc0 size=160
// signature: undefined compute_intercept_slope(void)
// callers: [calibrate_v1, calibrate_8960, calibrate_9607, calibrate_8939, calibrate_8976, calibrate_8916, calibrate_8974]
//------------------------------------------------------------

void compute_intercept_slope(long param_1,long param_2,long param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  
  if (*(int *)(param_1 + 8) != 0) {
    uVar2 = 0;
    do {
      lVar3 = param_1 + (long)(int)uVar2 * 0x28;
      iVar4 = *(int *)(lVar3 + 0xab0);
      piVar1 = (int *)(lVar3 + 0xab0);
      if (iVar4 == 0) {
        iVar4 = 0xc80;
        *piVar1 = 0xc80;
      }
      lVar3 = (long)(int)uVar2;
      if (param_4 == 3) {
        lVar5 = lVar3 * 4;
        iVar4 = ((*(int *)(param_3 + lVar5) - *(int *)(param_2 + lVar5)) * 1000) / 0x5a;
        *piVar1 = iVar4;
      }
      lVar5 = (long)(int)uVar2;
      uVar2 = uVar2 + 1;
      *(int *)(param_1 + lVar5 * 0x28 + 0xaa8) =
           *(int *)(param_2 + lVar3 * 4) * 1000 + iVar4 * -0x1e;
    } while (uVar2 < *(uint *)(param_1 + 8));
  }
  return;
}



//------------------------------------------------------------
// tsens_cold_irq_thread @ 00100c64 size=116
// signature: undefined tsens_cold_irq_thread(void)
// callers: []
//------------------------------------------------------------

void tsens_cold_irq_thread(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_2 + 0xa90);
  local_2c = 0;
  uVar1 = regmap_field_read(*(undefined8 *)(param_2 + 0xa28),&local_2c);
  if ((int)uVar1 == 0) {
    thermal_zone_device_update(*(undefined8 *)(lVar2 + 8),0);
    uVar1 = 1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// get_cold_int_status @ 00100cdc size=120
// signature: undefined get_cold_int_status(void)
// callers: []
//------------------------------------------------------------

void get_cold_int_status(long *param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = regmap_field_read(*(undefined8 *)(*param_1 + 0xa28),&local_2c);
  if (iVar2 == 0) {
    *(bool *)param_2 = local_2c != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// get_temp_tsens_valid @ 00100d58 size=660
// signature: undefined get_temp_tsens_valid(void)
// callers: [tsens_irq_thread, tsens_critical_irq_thread]
//------------------------------------------------------------

void get_temp_tsens_valid(long *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  undefined8 *puVar10;
  int local_60;
  int local_5c;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_60 = 0;
  lVar9 = *param_1;
  iVar7 = *(int *)((long)param_1 + 0x14);
  if ((int)param_1[4] == -0x80000000) {
    lVar5 = lVar9;
    if (**(int **)(lVar9 + 0xa38) != 0) {
      lVar5 = ktime_get();
      if (0x140 < iVar7 + 0x19U) goto LAB_00100fe8;
      puVar10 = (undefined8 *)(lVar9 + (ulong)(iVar7 + 0x19U) * 8 + 0x28);
      iVar4 = regmap_field_read(*puVar10,&local_60);
      if (iVar4 == 0 && local_60 == 0) {
        do {
          lVar6 = ktime_get();
          if (lVar5 + 20000000 < lVar6) {
            iVar4 = regmap_field_read(*puVar10,&local_60);
            if (iVar4 == 0) goto LAB_00100e50;
            goto LAB_00100eac;
          }
          usleep_range_state(1,1,2);
          Yield();
          iVar4 = regmap_field_read(*puVar10,&local_60);
        } while (iVar4 == 0 && local_60 == 0);
      }
      if (iVar4 == 0) {
LAB_00100e50:
        if (local_60 != 0) {
          lVar5 = *param_1;
          goto LAB_00100e58;
        }
      }
LAB_00100eac:
      iVar7 = 0;
      if (iVar4 == 0 && local_60 == 0) {
        iVar7 = -0x6e;
      }
      if (iVar4 == 0) {
        iVar4 = iVar7;
      }
      goto LAB_00100fb0;
    }
LAB_00100e58:
    local_5c = 0;
    if (0x140 < iVar7 + 9U) {
LAB_00100fe8:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100fec);
      (*pcVar3)();
    }
    iVar8 = *(int *)(*(long *)(lVar5 + 0xa40) + 0xb8);
    iVar2 = *(int *)(*(long *)(lVar5 + 0xa40) + 0xbc);
    iVar4 = regmap_field_read(*(undefined8 *)(lVar5 + (ulong)(iVar7 + 9U) * 8 + 0x28),&local_5c);
    if (iVar4 == 0) {
      if ((*(byte *)(*(long *)(lVar5 + 0xa38) + 4) >> 1 & 1) == 0) {
        uVar1 = (iVar8 - iVar2) + 0x1f;
        iVar4 = (local_5c << (ulong)(uVar1 & 0x1f)) >> (uVar1 & 0x1f);
        iVar8 = 100;
      }
      else {
        iVar8 = local_5c * 1000 - (int)param_1[2];
        iVar2 = (int)param_1[3];
        if (iVar8 < 1) {
          if (iVar8 < 0) {
            iVar4 = iVar2;
            if (iVar2 < 0) {
              iVar4 = iVar2 + 1;
            }
            iVar8 = iVar8 - (iVar4 >> 1);
          }
          else {
            iVar8 = 0;
          }
        }
        else {
          iVar4 = iVar2;
          if (iVar2 < 0) {
            iVar4 = iVar2 + 1;
          }
          iVar8 = iVar8 + (iVar4 >> 1);
        }
        iVar4 = 0;
        if (iVar2 != 0) {
          iVar4 = iVar8 / iVar2;
        }
        iVar8 = 1000;
      }
      iVar4 = iVar4 * iVar8;
    }
    *param_2 = iVar4;
    if ((*(long *)(*param_1 + 0xa88) != 0) && (param_1[1] != 0)) {
      thermal_minidump_update_data(*(long *)(*param_1 + 0xa88),param_1[1] + 4,param_2);
    }
  }
  else {
    *param_2 = (int)param_1[4];
  }
  if (param_1[1] == 0) {
    if (lVar9 != 0) {
      iVar4 = 0;
      if (*(long *)(lVar9 + 0xa70) == 0) goto LAB_00100fb0;
      lVar5 = sp_el0;
      ipc_log_string(*(long *)(lVar9 + 0xa70),"%s: Sensor_id: %d temp: %d [%s]\n",
                     "get_temp_tsens_valid",iVar7,*param_2,lVar5 + 0x848);
    }
  }
  else if (lVar9 != 0) {
    iVar4 = 0;
    if (*(long *)(lVar9 + 0xa70) == 0) goto LAB_00100fb0;
    lVar5 = sp_el0;
    ipc_log_string(*(long *)(lVar9 + 0xa70),"%s: Sensor_id: %d name:%s temp: %d [%s]\n",
                   "get_temp_tsens_valid",iVar7,param_1[1] + 4,*param_2,lVar5 + 0x848);
  }
  iVar4 = 0;
LAB_00100fb0:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar4);
  }
  return;
}



//------------------------------------------------------------
// tsens_hw_to_mC @ 00100fec size=256
// signature: undefined tsens_hw_to_mC(void)
// callers: [tsens_read_irq_state]
//------------------------------------------------------------

void tsens_hw_to_mC(long *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  ulong uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int local_3c;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  lVar7 = *param_1;
  local_3c = 0;
  if (0x140 < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1010e8);
    (*pcVar3)();
  }
  iVar6 = *(int *)(*(long *)(lVar7 + 0xa40) + 0xb8);
  iVar2 = *(int *)(*(long *)(lVar7 + 0xa40) + 0xbc);
  uVar4 = regmap_field_read(*(undefined8 *)(lVar7 + (ulong)param_2 * 8 + 0x28),&local_3c);
  if ((int)uVar4 == 0) {
    if ((*(byte *)(*(long *)(lVar7 + 0xa38) + 4) >> 1 & 1) == 0) {
      uVar1 = (iVar6 - iVar2) + 0x1f;
      iVar5 = (local_3c << (ulong)(uVar1 & 0x1f)) >> (uVar1 & 0x1f);
      iVar6 = 100;
    }
    else {
      iVar6 = local_3c * 1000 - (int)param_1[2];
      iVar2 = (int)param_1[3];
      if (iVar6 < 1) {
        if (iVar6 < 0) {
          iVar5 = iVar2;
          if (iVar2 < 0) {
            iVar5 = iVar2 + 1;
          }
          iVar6 = iVar6 - (iVar5 >> 1);
        }
        else {
          iVar6 = 0;
        }
      }
      else {
        iVar5 = iVar2;
        if (iVar2 < 0) {
          iVar5 = iVar2 + 1;
        }
        iVar6 = iVar6 + (iVar5 >> 1);
      }
      iVar5 = 0;
      if (iVar2 != 0) {
        iVar5 = iVar6 / iVar2;
      }
      iVar6 = 1000;
    }
    uVar4 = (ulong)(uint)(iVar5 * iVar6);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// get_temp_common @ 001010f0 size=376
// signature: undefined get_temp_common(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void get_temp_common(long *param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  code *pcVar6;
  uint uVar7;
  undefined8 uVar8;
  int iVar9;
  long lVar10;
  undefined8 local_50;
  long local_48;
  
  lVar5 = _jiffies;
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  lVar10 = *param_1;
  iVar3 = *(int *)((long)param_1 + 0x14);
  uVar7 = jiffies_to_usecs(0x3ffffffffffffffe);
  lVar2 = -0x3ffffffffffffffe;
  if (99 < uVar7) {
    lVar2 = -1;
  }
  do {
    if (**(int **)(lVar10 + 0xa38) != 0) {
LAB_00101188:
      uVar7 = iVar3 + 9;
      if (0x140 < uVar7) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x101268);
        (*pcVar6)();
      }
      uVar8 = regmap_field_read(*(undefined8 *)(lVar10 + (ulong)uVar7 * 8 + 0x28),
                                (long)&local_50 + 4);
      if ((int)uVar8 != 0) goto LAB_00101230;
      iVar9 = local_50._4_4_ * 1000 - (int)param_1[2];
      iVar4 = (int)param_1[3];
      if (iVar9 < 1) {
        if (iVar9 < 0) {
          iVar1 = iVar4;
          if (iVar4 < 0) {
            iVar1 = iVar4 + 1;
          }
          iVar9 = iVar9 - (iVar1 >> 1);
        }
        else {
          iVar9 = 0;
        }
      }
      else {
        iVar1 = iVar4;
        if (iVar4 < 0) {
          iVar1 = iVar4 + 1;
        }
        iVar9 = iVar9 + (iVar1 >> 1);
      }
      iVar1 = 0;
      if (iVar4 != 0) {
        iVar1 = iVar9 / iVar4;
      }
      *param_2 = iVar1 * 1000;
      if (lVar10 != 0) {
        uVar8 = 0;
        if (*(long *)(lVar10 + 0xa70) == 0) goto LAB_00101230;
        lVar2 = sp_el0;
        ipc_log_string(*(long *)(lVar10 + 0xa70),"%s: Sensor_id: %d temp: %d [%s]\n",
                       "get_temp_common",iVar3,iVar1 * 1000,lVar2 + 0x848);
      }
      uVar8 = 0;
      goto LAB_00101230;
    }
    uVar8 = regmap_field_read(*(undefined8 *)(lVar10 + 0x60),&local_50);
    if ((int)uVar8 != 0) goto LAB_00101230;
    if ((int)local_50 != 0) goto LAB_00101188;
  } while ((lVar2 - lVar5) + _jiffies < 0);
  uVar8 = 0xffffff92;
LAB_00101230:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// init_common @ 0010126c size=1868
// signature: undefined init_common(void)
// callers: [init_8956, init_8939]
//------------------------------------------------------------

ulong init_common(long *param_1)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long lVar9;
  uint *puVar10;
  uint uVar11;
  long lVar12;
  long *plVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  int local_70;
  uint local_6c;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar12 = *param_1;
  local_70 = 0;
  local_6c = 0xffffffff;
  lVar4 = of_find_device_by_node(*(undefined8 *)(lVar12 + 0x2e8));
  if (lVar4 == 0) {
    uVar6 = 0xffffffea;
    goto LAB_001015f8;
  }
  if (1 < *(uint *)(lVar4 + 0x3b8)) {
    *(undefined4 *)(param_1 + 4) = 0;
    uVar5 = platform_get_resource(lVar4,0x200,1);
    uVar6 = devm_ioremap_resource(lVar12,uVar5);
    if (0xfffffffffffff000 < uVar6) {
LAB_00101364:
      uVar6 = uVar6 & 0xffffffff;
      goto LAB_001015f0;
    }
    uVar6 = __devm_regmap_init_mmio_clk(lVar12,0,uVar6,&tsens_srot_config,0,0);
    param_1[3] = uVar6;
    if (uVar6 < 0xfffffffffffff001) goto LAB_00101330;
    goto LAB_001015ec;
  }
  *(undefined4 *)(param_1 + 4) = 0x1000;
LAB_00101330:
  if (*(int *)param_1[0x147] == 0) {
    if (*(long *)(*param_1 + 0x60) == 0) {
      uVar6 = param_1[2];
      goto joined_r0x001013ac;
    }
    uVar6 = syscon_node_to_regmap(*(undefined8 *)(*(long *)(*param_1 + 0x60) + 0x2e8));
    param_1[2] = uVar6;
    if (uVar6 != 0) goto LAB_001013bc;
LAB_001015e8:
    if (uVar6 == 0) {
LAB_001016d0:
      uVar6 = 0xffffffed;
    }
    else {
LAB_001015ec:
      uVar6 = uVar6 & 0xffffffff;
    }
  }
  else {
    uVar5 = platform_get_resource(lVar4,0x200,0);
    uVar6 = devm_ioremap_resource(lVar12,uVar5);
    if (0xfffffffffffff000 < uVar6) goto LAB_00101364;
    uVar6 = __devm_regmap_init_mmio_clk(lVar12,0,uVar6,&tsens_config,0,0);
    param_1[2] = uVar6;
joined_r0x001013ac:
    if (uVar6 == 0) goto LAB_001015e8;
LAB_001013bc:
    if (0xfffffffffffff000 < uVar6) goto LAB_001015e8;
    uVar7 = param_1[3];
    if (param_1[3] == 0) {
      param_1[3] = uVar6;
      uVar7 = uVar6;
    }
    if (*(uint *)param_1[0x147] < 2) {
LAB_00101498:
      lVar9 = param_1[0x148];
      local_78 = *(undefined4 *)(lVar9 + 0x4c);
      uStack_80 = *(undefined8 *)(lVar9 + 0x44);
      local_88 = *(undefined8 *)(lVar9 + 0x3c);
      uVar6 = devm_regmap_field_alloc(lVar12,uVar7,&local_88);
      param_1[8] = uVar6;
      if (uVar6 < 0xfffffffffffff001) {
        if (*(int *)param_1[0x147] == 0) {
          regmap_field_update_bits_base(uVar6,0xffffffff,1,0,0,0);
          uVar6 = param_1[8];
        }
        uVar7 = regmap_field_read(uVar6,&local_70);
        uVar6 = uVar7 & 0xffffffff;
        if ((int)uVar7 != 0) goto LAB_001015f0;
        if (local_70 != 0) {
          lVar9 = param_1[0x148];
          local_78 = *(undefined4 *)(lVar9 + 0x74);
          uStack_80 = *(undefined8 *)(lVar9 + 0x6c);
          local_88 = *(undefined8 *)(lVar9 + 100);
          uVar6 = devm_regmap_field_alloc(lVar12,param_1[3],&local_88);
          param_1[10] = uVar6;
          if (uVar6 < 0xfffffffffffff001) {
            lVar9 = param_1[0x148];
            local_78 = *(undefined4 *)(lVar9 + 0xb0);
            local_88 = *(undefined8 *)(lVar9 + 0xa0);
            uStack_80 = *(undefined8 *)(lVar9 + 0xa8);
            uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
            param_1[0xd] = uVar6;
            if (uVar6 < 0xfffffffffffff001) {
              lVar9 = param_1[0x148];
              local_78 = *(undefined4 *)(lVar9 + 0x60);
              local_88 = *(undefined8 *)(lVar9 + 0x50);
              uStack_80 = *(undefined8 *)(lVar9 + 0x58);
              uVar6 = devm_regmap_field_alloc(lVar12,param_1[3],&local_88);
              param_1[9] = uVar6;
              if (uVar6 < 0xfffffffffffff001) {
                lVar9 = param_1[0x148];
                local_78 = *(undefined4 *)(lVar9 + 0x9c);
                uStack_80 = *(undefined8 *)(lVar9 + 0x94);
                local_88 = *(undefined8 *)(lVar9 + 0x8c);
                uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                param_1[0xc] = uVar6;
                if (uVar6 < 0xfffffffffffff001) {
                  puVar10 = (uint *)param_1[0x147];
                  plVar13 = param_1 + 0xe;
                  uVar14 = 0x138;
                  lVar9 = 0xb4;
                  uVar7 = 9;
                  do {
                    if (puVar10[2] != 0) {
                      uVar15 = 0;
                      lVar16 = lVar9;
                      do {
                        puVar8 = (undefined8 *)(param_1[0x148] + lVar16);
                        local_78 = *(undefined4 *)(puVar8 + 2);
                        local_88 = *puVar8;
                        uStack_80 = puVar8[1];
                        uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                        if (uVar14 == uVar15) goto LAB_001019b4;
                        plVar13[uVar15] = uVar6;
                        if (0xfffffffffffff000 < uVar6) goto LAB_001015ec;
                        puVar10 = (uint *)param_1[0x147];
                        uVar15 = uVar15 + 1;
                        lVar16 = lVar16 + 0x14;
                      } while (uVar15 < puVar10[2]);
                    }
                    bVar3 = uVar7 < 0xb9;
                    uVar14 = uVar14 - 0x10;
                    lVar9 = lVar9 + 0x140;
                    plVar13 = plVar13 + 0x10;
                    uVar7 = uVar7 + 0x10;
                  } while (bVar3);
                  if (((puVar10[1] & 1) != 0) || (uVar11 = *puVar10, uVar11 == 0)) {
                    lVar9 = 0;
                    plVar13 = param_1 + 0xce;
                    uVar14 = 0x78;
                    uVar7 = 0xc9;
                    do {
                      if (puVar10[2] != 0) {
                        uVar15 = 0;
                        lVar16 = lVar9;
                        do {
                          lVar1 = param_1[0x148] + lVar16;
                          local_78 = *(undefined4 *)(lVar1 + 0xfc4);
                          local_88 = *(undefined8 *)(lVar1 + 0xfb4);
                          uStack_80 = *(undefined8 *)(lVar1 + 0xfbc);
                          uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                          if (uVar14 == uVar15) {
LAB_001019b4:
                    /* WARNING: Does not return */
                            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1019b8);
                            (*pcVar2)();
                          }
                          plVar13[uVar15] = uVar6;
                          if (0xfffffffffffff000 < uVar6) goto LAB_001015ec;
                          puVar10 = (uint *)param_1[0x147];
                          uVar15 = uVar15 + 1;
                          lVar16 = lVar16 + 0x14;
                        } while (uVar15 < puVar10[2]);
                      }
                      bVar3 = uVar7 < 0x109;
                      uVar14 = uVar14 - 0x10;
                      lVar9 = lVar9 + 0x140;
                      plVar13 = plVar13 + 0x10;
                      uVar7 = uVar7 + 0x10;
                    } while (bVar3);
                    uVar11 = *puVar10;
                  }
                  if ((uVar11 < 3) || (local_6c < 3)) {
LAB_001018dc:
                    init_cold_interrupt(param_1,local_6c);
                    *(undefined4 *)((long)param_1 + 0x24) = 0;
                    if (*(int *)param_1[0x147] != 0) {
                      tsens_enable_irq(param_1);
                    }
                    tsens_debug_init(lVar4);
                    uVar6 = 0;
                  }
                  else {
                    *(byte *)(puVar10 + 1) = (byte)puVar10[1] | 8;
                    lVar9 = param_1[0x148];
                    local_78 = *(undefined4 *)(lVar9 + 0x1604);
                    local_88 = *(undefined8 *)(lVar9 + 0x15f4);
                    uStack_80 = *(undefined8 *)(lVar9 + 0x15fc);
                    uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                    param_1[0x11e] = uVar6;
                    if (uVar6 < 0xfffffffffffff001) {
                      lVar9 = param_1[0x148];
                      local_78 = *(undefined4 *)(lVar9 + 0x1618);
                      uStack_80 = *(undefined8 *)(lVar9 + 0x1610);
                      local_88 = *(undefined8 *)(lVar9 + 0x1608);
                      uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                      param_1[0x11f] = uVar6;
                      if (uVar6 < 0xfffffffffffff001) {
                        lVar9 = param_1[0x148];
                        local_78 = *(undefined4 *)(lVar9 + 0x162c);
                        local_88 = *(undefined8 *)(lVar9 + 0x161c);
                        uStack_80 = *(undefined8 *)(lVar9 + 0x1624);
                        uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                        param_1[0x120] = uVar6;
                        if (uVar6 < 0xfffffffffffff001) {
                          lVar9 = param_1[0x148];
                          local_78 = *(undefined4 *)(lVar9 + 0x1640);
                          uStack_80 = *(undefined8 *)(lVar9 + 0x1638);
                          local_88 = *(undefined8 *)(lVar9 + 0x1630);
                          uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                          param_1[0x121] = uVar6;
                          if (uVar6 < 0xfffffffffffff001) {
                            lVar9 = param_1[0x148];
                            local_78 = *(undefined4 *)(lVar9 + 0x1654);
                            local_88 = *(undefined8 *)(lVar9 + 0x1644);
                            uStack_80 = *(undefined8 *)(lVar9 + 0x164c);
                            uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                            param_1[0x122] = uVar6;
                            if (uVar6 < 0xfffffffffffff001) {
                              lVar9 = param_1[0x148];
                              local_78 = *(undefined4 *)(lVar9 + 0x1668);
                              uStack_80 = *(undefined8 *)(lVar9 + 0x1660);
                              local_88 = *(undefined8 *)(lVar9 + 0x1658);
                              uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                              param_1[0x123] = uVar6;
                              if (uVar6 < 0xfffffffffffff001) {
                                lVar9 = param_1[0x148];
                                local_78 = *(undefined4 *)(lVar9 + 0x167c);
                                local_88 = *(undefined8 *)(lVar9 + 0x166c);
                                uStack_80 = *(undefined8 *)(lVar9 + 0x1674);
                                uVar6 = devm_regmap_field_alloc(lVar12,param_1[2],&local_88);
                                param_1[0x124] = uVar6;
                                if (uVar6 < 0xfffffffffffff001) {
                                  regmap_field_update_bits_base(param_1[0x120],0xffffffff,0,0,0,0);
                                  regmap_field_update_bits_base(param_1[0x124],0xffffffff,1,0,0,0);
                                  goto LAB_001018dc;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  goto LAB_001015f0;
                }
              }
            }
          }
          goto LAB_001015ec;
        }
        _dev_err(lVar12,"%s: device not enabled\n","init_common");
        goto LAB_001016d0;
      }
      goto LAB_001015ec;
    }
    puVar8 = (undefined8 *)param_1[0x148];
    local_78 = *(undefined4 *)(puVar8 + 2);
    local_88 = *puVar8;
    uStack_80 = puVar8[1];
    uVar6 = devm_regmap_field_alloc(lVar12,uVar7,&local_88);
    param_1[5] = uVar6;
    if (uVar6 < 0xfffffffffffff001) {
      lVar9 = param_1[0x148];
      local_78 = *(undefined4 *)(lVar9 + 0x24);
      uStack_80 = *(undefined8 *)(lVar9 + 0x1c);
      local_88 = *(undefined8 *)(lVar9 + 0x14);
      uVar6 = devm_regmap_field_alloc(lVar12,param_1[3],&local_88);
      param_1[6] = uVar6;
      if (uVar6 < 0xfffffffffffff001) {
        lVar9 = param_1[0x148];
        local_78 = *(undefined4 *)(lVar9 + 0x38);
        local_88 = *(undefined8 *)(lVar9 + 0x28);
        uStack_80 = *(undefined8 *)(lVar9 + 0x30);
        uVar6 = devm_regmap_field_alloc(lVar12,param_1[3],&local_88);
        param_1[7] = uVar6;
        if (uVar6 < 0xfffffffffffff001) {
          uVar7 = regmap_field_read(param_1[6],&local_6c);
          uVar6 = uVar7 & 0xffffffff;
          if ((int)uVar7 == 0) {
            uVar7 = param_1[3];
            goto LAB_00101498;
          }
        }
      }
    }
  }
LAB_001015f0:
  put_device(lVar4 + 0x10);
LAB_001015f8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// init_cold_interrupt @ 001019b8 size=160
// signature: undefined init_cold_interrupt(void)
// callers: [init_common]
//------------------------------------------------------------

void init_cold_interrupt(undefined8 *param_1,uint param_2)

{
  undefined8 uVar1;
  uint *puVar2;
  long lVar3;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if ((5 < param_2) && (puVar2 = (uint *)param_1[0x147], 2 < *puVar2)) {
    uVar1 = *param_1;
    *(byte *)(puVar2 + 1) = (byte)puVar2[1] | 0x10;
    lVar3 = param_1[0x148];
    local_30 = *(undefined4 *)(lVar3 + 0x1910);
    uStack_38 = *(undefined8 *)(lVar3 + 0x1908);
    local_40 = *(undefined8 *)(lVar3 + 0x1900);
    uVar1 = devm_regmap_field_alloc(uVar1,param_1[2],&local_40);
    param_1[0x145] = uVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tsens_enable_irq @ 00101a58 size=112
// signature: undefined tsens_enable_irq(void)
// callers: [init_common]
//------------------------------------------------------------

void tsens_enable_irq(undefined8 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 7;
  if (*(uint *)param_1[0x147] < 3) {
    uVar2 = 1;
  }
  iVar1 = regmap_field_update_bits_base(param_1[0xd],0xffffffff,uVar2,0,0,0);
  if (iVar1 < 0) {
    _dev_err(*param_1,"%s: failed to enable interrupts\n","tsens_enable_irq");
  }
  return;
}



//------------------------------------------------------------
// tsens_debug_init @ 00101ac8 size=532
// signature: undefined tsens_debug_init(void)
// callers: [init_common]
//------------------------------------------------------------

void tsens_debug_init(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar3 = *(long *)(param_1 + 0xa8);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  lVar1 = debugfs_lookup("tsens",0);
  if (lVar1 == 0) {
    lVar1 = debugfs_create_dir("tsens");
  }
  *(long *)(lVar3 + 0xa60) = lVar1;
  lVar1 = debugfs_lookup("version");
  if (lVar1 == 0) {
    debugfs_create_file("version",0x124,*(undefined8 *)(lVar3 + 0xa60),param_1,&dbg_version_fops);
    lVar1 = *(long *)(param_1 + 0x80);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x80);
  }
  if (lVar1 == 0) {
    lVar1 = *(long *)(param_1 + 0x10);
  }
  uVar2 = debugfs_create_dir(lVar1,*(undefined8 *)(lVar3 + 0xa60));
  *(undefined8 *)(lVar3 + 0xa68) = uVar2;
  debugfs_create_file("sensors",0x124,uVar2,param_1,&dbg_sensors_fops);
  lVar1 = *(long *)(param_1 + 0x80);
  if (lVar1 == 0) {
    lVar1 = *(long *)(param_1 + 0x10);
  }
  snprintf((char *)&local_48,0x20,"%s_0",lVar1);
  lVar1 = ipc_log_context_create(10,&local_48,0);
  *(long *)(lVar3 + 0xa70) = lVar1;
  if (lVar1 == 0) {
    _dev_err(param_1 + 0x10,"%s: unable to create IPC Logging for %s\n","tsens_debug_init",&local_48
            );
    lVar1 = *(long *)(param_1 + 0x80);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x80);
  }
  if (lVar1 == 0) {
    lVar1 = *(long *)(param_1 + 0x10);
  }
  snprintf((char *)&local_48,0x20,"%s_1",lVar1);
  lVar1 = ipc_log_context_create(10,&local_48,0);
  *(long *)(lVar3 + 0xa78) = lVar1;
  if (lVar1 == 0) {
    _dev_err(param_1 + 0x10,"%s: unable to create IPC Logging for %s\n","tsens_debug_init",&local_48
            );
    lVar1 = *(long *)(param_1 + 0x80);
  }
  else {
    lVar1 = *(long *)(param_1 + 0x80);
  }
  if (lVar1 == 0) {
    lVar1 = *(long *)(param_1 + 0x10);
  }
  snprintf((char *)&local_48,0x20,"%s_2",lVar1);
  lVar1 = ipc_log_context_create(1,&local_48,0);
  *(long *)(lVar3 + 0xa80) = lVar1;
  if (lVar1 == 0) {
    _dev_err(param_1 + 0x10,"%s: unable to create IPC Logging for %s\n","tsens_debug_init",&local_48
            );
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tsens_v2_tsens_suspend @ 00101ce0 size=132
// signature: undefined tsens_v2_tsens_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 tsens_v2_tsens_suspend(long param_1)

{
  if ((_pm_suspend_target_state == 3) || (*(char *)(param_1 + 0xa5d) != '\0')) {
    if (0 < *(int *)(param_1 + 0xa50)) {
      disable_irq_nosync();
      irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa50),0);
    }
    if (((*(byte *)(*(long *)(param_1 + 0xa38) + 4) & 1) != 0) && (0 < *(int *)(param_1 + 0xa54))) {
      disable_irq_nosync();
      irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa54),0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// tsens_v2_tsens_resume @ 00101d68 size=144
// signature: undefined tsens_v2_tsens_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 tsens_v2_tsens_resume(long param_1)

{
  if (_pm_suspend_target_state == 3) {
    tsens_reinit(param_1);
  }
  else if (*(char *)(param_1 + 0xa5d) == '\0') {
    return 0;
  }
  if (0 < *(int *)(param_1 + 0xa50)) {
    enable_irq();
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa50),1);
  }
  if (((*(byte *)(*(long *)(param_1 + 0xa38) + 4) & 1) != 0) && (0 < *(int *)(param_1 + 0xa54))) {
    enable_irq();
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa54),1);
  }
  return 0;
}



//------------------------------------------------------------
// tsens_reinit @ 00101df8 size=220
// signature: undefined tsens_reinit(void)
// callers: [tsens_v2_tsens_restore, tsens_v2_tsens_resume]
//------------------------------------------------------------

void tsens_reinit(undefined8 *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  uVar2 = _raw_spin_lock_irqsave((long)param_1 + 0x24);
  puVar4 = (uint *)param_1[0x147];
  if (((byte)puVar4[1] >> 3 & 1) != 0) {
    regmap_field_update_bits_base(param_1[0x120],0xffffffff,0,0,0,0);
    regmap_field_update_bits_base(param_1[0x124],0xffffffff,1,0,0,0);
    puVar4 = (uint *)param_1[0x147];
  }
  if (*puVar4 != 0) {
    uVar3 = 7;
    if (*puVar4 < 3) {
      uVar3 = 1;
    }
    iVar1 = regmap_field_update_bits_base(param_1[0xd],0xffffffff,uVar3,0,0,0);
    if (iVar1 < 0) {
      _dev_err(*param_1,"%s: failed to enable interrupts\n","tsens_enable_irq");
    }
  }
  _raw_spin_unlock_irqrestore((long)param_1 + 0x24,uVar2);
  return;
}



//------------------------------------------------------------
// tsens_v2_tsens_freeze @ 00101ed8 size=108
// signature: undefined tsens_v2_tsens_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_v2_tsens_freeze(long param_1)

{
  if (0 < *(int *)(param_1 + 0xa50)) {
    disable_irq_nosync();
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa50),0);
  }
  if (((*(byte *)(*(long *)(param_1 + 0xa38) + 4) & 1) != 0) && (0 < *(int *)(param_1 + 0xa54))) {
    disable_irq_nosync();
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa54),0);
  }
  return 0;
}



//------------------------------------------------------------
// tsens_v2_tsens_restore @ 00101f48 size=112
// signature: undefined tsens_v2_tsens_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_v2_tsens_restore(long param_1)

{
  tsens_reinit();
  if (0 < *(int *)(param_1 + 0xa50)) {
    enable_irq();
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa50),1);
  }
  if (((*(byte *)(*(long *)(param_1 + 0xa38) + 4) & 1) != 0) && (0 < *(int *)(param_1 + 0xa54))) {
    enable_irq();
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0xa54),1);
  }
  return 0;
}



//------------------------------------------------------------
// dbg_version_open @ 00101fbc size=48
// signature: undefined dbg_version_open(void)
// callers: []
//------------------------------------------------------------

void dbg_version_open(long param_1,undefined8 param_2)

{
  single_open(param_2,dbg_version_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// dbg_version_show @ 00101ff0 size=208
// signature: undefined dbg_version_show(void)
// callers: []
//------------------------------------------------------------

void dbg_version_show(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  local_34 = 0;
  uStack_30 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x80) + 0xa8);
  if (**(uint **)(lVar2 + 0xa38) < 2) {
    seq_puts(param_1,"0.1.0\n");
  }
  else {
    uVar1 = regmap_field_read(*(undefined8 *)(lVar2 + 0x28),&local_2c);
    if ((((int)uVar1 != 0) ||
        (uVar1 = regmap_field_read(*(undefined8 *)(lVar2 + 0x30),&uStack_30), (int)uVar1 != 0)) ||
       (uVar1 = regmap_field_read(*(undefined8 *)(lVar2 + 0x38),&local_34), (int)uVar1 != 0))
    goto LAB_00102094;
    seq_printf(param_1,"%d.%d.%d\n",local_2c,uStack_30,local_34);
  }
  uVar1 = 0;
LAB_00102094:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// dbg_sensors_open @ 001020c4 size=48
// signature: undefined dbg_sensors_open(void)
// callers: []
//------------------------------------------------------------

void dbg_sensors_open(long param_1,undefined8 param_2)

{
  single_open(param_2,dbg_sensors_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// dbg_sensors_show @ 001020f8 size=172
// signature: undefined dbg_sensors_show(void)
// callers: []
//------------------------------------------------------------

undefined8 dbg_sensors_show(long param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x80) + 0xa8);
  seq_printf(param_1,"max: %2d\nnum: %2d\n\n",*(undefined4 *)(*(long *)(lVar2 + 0xa38) + 8),
             *(undefined4 *)(lVar2 + 8));
  seq_puts(param_1,"      id    slope   offset\n--------------------------\n");
  if (*(int *)(lVar2 + 8) != 0) {
    uVar3 = 0;
    do {
      lVar1 = lVar2 + (long)(int)uVar3 * 0x28;
      seq_printf(param_1,"%8d %8d %8d\n",*(undefined4 *)(lVar1 + 0xaac),
                 *(undefined4 *)(lVar1 + 0xab0),*(undefined4 *)(lVar1 + 0xaa8));
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(lVar2 + 8));
  }
  return 0;
}



//------------------------------------------------------------
// tsens_probe @ 001021a8 size=1784
// signature: undefined tsens_probe(void)
// callers: []
//------------------------------------------------------------

int tsens_probe(long param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  byte bVar4;
  bool bVar5;
  int iVar6;
  uint uVar7;
  long lVar8;
  long *plVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  long lVar13;
  long *plVar14;
  char *pcVar15;
  int iVar16;
  undefined4 uVar17;
  uint uVar18;
  undefined8 *puVar19;
  code *pcVar20;
  undefined8 *puVar21;
  uint *puVar22;
  uint local_74;
  undefined4 local_70;
  int local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_74 = 0;
  if (*(long *)(param_1 + 0x2f8) == 0) {
    lVar10 = *(long *)(param_1 + 0x70);
  }
  else {
    lVar10 = param_1 + 0x10;
  }
  puVar21 = *(undefined8 **)(lVar10 + 0x2e8);
  lVar8 = of_match_node(&tsens_table,puVar21);
  if (lVar8 == 0) {
    puVar22 = &data_8960;
  }
  else {
    puVar22 = *(uint **)(lVar8 + 0xc0);
  }
  local_74 = *puVar22;
  if (puVar21 != (undefined8 *)0x0) {
    of_property_read_variable_u32_array(puVar21,"#qcom,sensors",&local_74,1,0);
  }
  if (local_74 == 0) {
    _dev_err(lVar10,"%s: invalid number of sensors\n","tsens_probe");
    iVar6 = -0x16;
    goto LAB_00102834;
  }
  plVar9 = (long *)devm_kmalloc(lVar10,(ulong)local_74 * 0x28 + 0xa98,0xdc0);
  if (plVar9 != (long *)0x0) {
    *plVar9 = lVar10;
    *(uint *)(plVar9 + 1) = local_74;
    puVar19 = *(undefined8 **)(puVar22 + 2);
    plVar9[0x149] = (long)puVar19;
    if (local_74 != 0) {
      uVar18 = 0;
      do {
        uVar7 = uVar18;
        if (*(long *)(puVar22 + 4) != 0) {
          uVar7 = *(uint *)(*(long *)(puVar22 + 4) + (long)(int)uVar18 * 4);
        }
        uVar1 = uVar18 + 1;
        *(undefined4 *)(plVar9 + (long)(int)uVar18 * 5 + 0x157) = 0x80000000;
        uVar3 = *(uint *)(plVar9 + 1);
        *(uint *)((long)plVar9 + (long)(int)uVar18 * 0x28 + 0xaac) = uVar7;
        uVar18 = uVar1;
      } while (uVar1 < uVar3);
      puVar19 = (undefined8 *)plVar9[0x149];
    }
    plVar9[0x147] = *(long *)(puVar22 + 6);
    lVar8 = *(long *)(puVar22 + 8);
    *(long **)(param_1 + 0xa8) = plVar9;
    plVar9[0x148] = lVar8;
    if (((puVar19 == (undefined8 *)0x0) || (pcVar20 = (code *)*puVar19, pcVar20 == (code *)0x0)) ||
       (puVar19[2] == 0)) {
      iVar6 = -0x16;
      goto LAB_00102834;
    }
    if (*(int *)(pcVar20 + -4) != -0x63da61ea) {
                    /* WARNING: Does not return */
      pcVar20 = (code *)SoftwareBreakpoint(0x8229,0x102310);
      (*pcVar20)();
    }
    iVar6 = (*pcVar20)(plVar9);
    if (iVar6 < 0) {
      pcVar15 = "%s: init failed\n";
LAB_00102434:
      _dev_err(lVar10,pcVar15,"tsens_probe");
      goto LAB_00102834;
    }
    pcVar20 = *(code **)(plVar9[0x149] + 8);
    if (pcVar20 != (code *)0x0) {
      if (*(int *)(pcVar20 + -4) != -0x63da61ea) {
                    /* WARNING: Does not return */
        pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x102340);
        (*pcVar20)();
      }
      iVar6 = (*pcVar20)(plVar9);
      if (iVar6 < 0) {
        if (iVar6 == -0x205) goto LAB_00102834;
        pcVar15 = "%s: calibration failed\n";
        goto LAB_00102434;
      }
    }
    lVar10 = thermal_minidump_register(*puVar21);
    plVar9[0x151] = lVar10;
    lVar10 = of_find_property(puVar21,"tm-disable-on-suspend",0);
    local_70 = 0;
    *(bool *)((long)plVar9 + 0xa5d) = lVar10 != 0;
    local_6c = 0;
    lVar10 = of_find_property(*(undefined8 *)(*plVar9 + 0x2e8),"nvmem-cells",0);
    if (lVar10 == 0) {
LAB_00102464:
      bVar5 = false;
    }
    else {
      iVar6 = nvmem_cell_read_variable_le_u32(*plVar9,"tsens_itemp",&local_6c);
      if (iVar6 != 0) {
        _dev_err(*plVar9,"%s: Not able to read tsens_chipinfo nvmem, ret:%d\n",
                 "tsens_is_nvmem_trip_update_needed",iVar6);
        goto LAB_00102464;
      }
      if (plVar9[0x150] != 0) {
        lVar10 = sp_el0;
        ipc_log_string(plVar9[0x150],"%s: itemp fuse:0x%x [%s]\n",
                       "tsens_is_nvmem_trip_update_needed",local_6c,lVar10 + 0x848);
      }
      bVar5 = local_6c != 0;
    }
    *(bool *)((long)plVar9 + 0xa5c) = bVar5;
    if ((int)plVar9[1] != 0) {
      lVar10 = sp_el0;
      uVar18 = 0;
      do {
        plVar9[(long)(int)uVar18 * 5 + 0x153] = (long)plVar9;
        uVar11 = devm_thermal_of_zone_register
                           (*plVar9,*(undefined4 *)((long)plVar9 + (long)(int)uVar18 * 0x28 + 0xaac)
                            ,plVar9 + (long)(int)uVar18 * 5 + 0x153,tsens_of_ops);
        if (uVar11 < 0xfffffffffffff001) {
          pcVar20 = *(code **)(plVar9[0x149] + 0x10);
          if (pcVar20 != (code *)0x0) {
            puVar2 = (undefined4 *)((long)plVar9 + (long)(int)uVar18 * 0x28 + 0xaac);
            if (*(int *)(pcVar20 + -4) != 0x78ed951a) {
                    /* WARNING: Does not return */
              pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x10250c);
              (*pcVar20)();
            }
            iVar6 = (*pcVar20)(plVar9 + (long)(int)uVar18 * 5 + 0x153,&local_70);
            if (iVar6 != 0) {
              _dev_err(*plVar9,"[%u] %s: error reading sensor\n",*puVar2,"tsens_register");
              goto LAB_0010249c;
            }
            if (plVar9[0x150] != 0) {
              ipc_log_string(plVar9[0x150],"%s: Sensor_id: %d name:%s temp: %d [%s]\n",
                             "tsens_register",*puVar2,uVar11 + 4,local_70,lVar10 + 0x848);
            }
          }
          plVar9[(long)(int)uVar18 * 5 + 0x154] = uVar11;
          pcVar20 = *(code **)(plVar9[0x149] + 0x18);
          if (pcVar20 != (code *)0x0) {
            if (*(int *)(pcVar20 + -4) != 0x3d313fbb) {
                    /* WARNING: Does not return */
              pcVar20 = (code *)SoftwareBreakpoint(0x8228,0x102574);
              (*pcVar20)();
            }
            (*pcVar20)(plVar9,uVar18);
          }
          if (*(char *)((long)plVar9 + 0xa5c) != '\0') {
            lVar8 = strnstr(uVar11 + 4,"mdmss",0x14);
            if ((lVar8 == 0) && (uVar7 = of_thermal_get_ntrips(uVar11), 1 < (int)uVar7)) {
              lVar8 = 0;
              iVar6 = 1;
              do {
                uVar12 = of_thermal_is_trip_valid(uVar11,iVar6);
                if (((uVar12 & 1) != 0) && (*(long *)(uVar11 + 0x3f8) != 0)) {
                  iVar16 = *(int *)(*(long *)(uVar11 + 0x3f8) + lVar8 + 0x14);
                  if (iVar16 == 2) {
                    iVar16 = 3000;
                  }
                  else {
                    if (iVar16 == 3) goto LAB_00102604;
                    lVar13 = strnstr(uVar11 + 4,&DAT_00105e17,0x14);
                    iVar16 = 10000;
                    if (lVar13 != 0) {
                      iVar16 = 5000;
                    }
                  }
                  mutex_lock(uVar11 + 0x480);
                  lVar13 = *(long *)(uVar11 + 0x3f8) + lVar8;
                  *(int *)(lVar13 + 0xc) = *(int *)(lVar13 + 0xc) + iVar16;
                  mutex_unlock(uVar11 + 0x480);
                  thermal_zone_device_update(uVar11,0);
                }
LAB_00102604:
                lVar8 = lVar8 + 0xc;
                iVar6 = iVar6 + 1;
              } while ((ulong)uVar7 * 0xc + -0xc != lVar8);
            }
          }
          if ((uVar11 != 0) && (*(long *)(uVar11 + 0x440) != 0)) {
            mutex_lock(uVar11 + 0x480);
            if (*(long *)(*(long *)(uVar11 + 0x440) + 0x20) == 0) {
              *(code **)(*(long *)(uVar11 + 0x440) + 0x20) = qti_tz_change_mode;
            }
            mutex_unlock(uVar11 + 0x480);
          }
        }
LAB_0010249c:
        uVar18 = uVar18 + 1;
      } while (uVar18 < *(uint *)(plVar9 + 1));
    }
    if (*(int *)plVar9[0x147] == 0) {
      if ((*(byte *)(*(long *)(plVar9[0x153] + 0xa38) + 4) >> 1 & 1) == 0) {
        uVar17 = 0x4b0;
      }
      else {
        uVar11 = (long)(int)plVar9[0x155] + (long)(int)plVar9[0x156] * 0x78;
        uVar17 = 0x3ff;
        if (uVar11 < 0xf9c18) {
          uVar17 = (undefined4)((uVar11 & 0xffffffff) / 1000);
        }
      }
      regmap_field_update_bits_base(plVar9[0x10e],0xffffffff,uVar17,0,0,0);
      uVar18 = 0;
      if ((*(byte *)(*(long *)(plVar9[0x153] + 0xa38) + 4) >> 1 & 1) != 0) {
        uVar18 = 0x3ff;
        if (*(uint *)(plVar9 + 0x155) < 0xf9c18) {
          uVar18 = *(uint *)(plVar9 + 0x155) / 1000;
        }
      }
      regmap_field_update_bits_base(plVar9[0x10f],0xffffffff,uVar18,0,0,0);
    }
    iVar6 = tsens_register_irq(plVar9,"uplow",tsens_irq_thread,plVar9 + 0x14a);
    if (iVar6 < 0) goto LAB_00102834;
    bVar4 = *(byte *)(plVar9[0x147] + 4);
    if ((bVar4 & 1) != 0) {
      iVar6 = tsens_register_irq(plVar9,"critical",tsens_critical_irq_thread,(long)plVar9 + 0xa54);
      bVar4 = *(byte *)(plVar9[0x147] + 4);
    }
    if ((bVar4 >> 4 & 1) == 0) goto LAB_00102834;
    plVar14 = (long *)devm_kmalloc(*plVar9,0x28,0xdc0);
    plVar9[0x152] = (long)plVar14;
    if (plVar14 != (long *)0x0) {
      lVar10 = *plVar9;
      *(undefined4 *)((long)plVar14 + 0x14) = 0x80;
      *plVar14 = (long)plVar9;
      uVar11 = devm_thermal_of_zone_register(lVar10,0x80,plVar14,tsens_cold_of_ops);
      if (uVar11 < 0xfffffffffffff001) {
        *(ulong *)(plVar9[0x152] + 8) = uVar11;
        iVar6 = tsens_register_irq(plVar9,&DAT_00105e3f,tsens_cold_irq_thread,plVar9 + 0x14b);
      }
      else {
        iVar6 = 0;
      }
      goto LAB_00102834;
    }
  }
  iVar6 = -0xc;
LAB_00102834:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// tsens_remove @ 001028a4 size=232
// signature: undefined tsens_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_remove(long param_1)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  
  lVar3 = *(long *)(param_1 + 0xa8);
  debugfs_remove(*(undefined8 *)(lVar3 + 0xa60));
  regmap_field_update_bits_base(*(undefined8 *)(lVar3 + 0x68),0xffffffff,0,0,0,0);
  pcVar2 = *(code **)(*(long *)(lVar3 + 0xa48) + 0x20);
  if (pcVar2 != (code *)0x0) {
    if (*(int *)(pcVar2 + -4) != 0x72fb7419) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10290c);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3);
  }
  uVar1 = *(uint *)(lVar3 + 8);
  if (uVar1 != 0) {
    uVar4 = 0;
    do {
      lVar5 = *(long *)(lVar3 + (long)(int)uVar4 * 0x28 + 0xaa0);
      if ((lVar5 != 0) && (*(long *)(lVar5 + 0x440) != 0)) {
        mutex_lock(lVar5 + 0x480);
        *(undefined8 *)(*(long *)(lVar5 + 0x440) + 0x20) = 0;
        mutex_unlock(lVar5 + 0x480);
        uVar1 = *(uint *)(lVar3 + 8);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  thermal_minidump_unregister(*(undefined8 *)(lVar3 + 0xa88));
  return 0;
}



//------------------------------------------------------------
// tsens_register_irq @ 0010298c size=264
// signature: undefined tsens_register_irq(void)
// callers: [tsens_probe]
//------------------------------------------------------------

int tsens_register_irq(long *param_1,undefined8 param_2,undefined8 param_3,int *param_4)

{
  long *plVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  long lVar8;
  
  lVar4 = of_find_device_by_node(*(undefined8 *)(*param_1 + 0x2e8));
  if (lVar4 == 0) {
    iVar3 = -0x13;
  }
  else {
    iVar2 = platform_get_irq_byname(lVar4,param_2);
    *param_4 = iVar2;
    if (iVar2 < 0) {
      iVar3 = 0;
      if (iVar2 != -6) {
        iVar3 = iVar2;
      }
    }
    else {
      plVar1 = (long *)(lVar4 + 0x10);
      lVar8 = *(long *)(lVar4 + 0x80);
      if (*(int *)param_1[0x147] == 0) {
        if (lVar8 == 0) {
          lVar8 = *plVar1;
        }
        uVar6 = 0;
        uVar7 = 1;
        uVar5 = param_3;
      }
      else {
        if (lVar8 == 0) {
          lVar8 = *plVar1;
        }
        uVar7 = 0x2000;
        uVar5 = 0;
        uVar6 = param_3;
      }
      iVar3 = devm_request_threaded_irq(plVar1,iVar2,uVar5,uVar6,uVar7,lVar8,param_1);
      if (iVar3 == 0) {
        irq_set_irq_wake(iVar2,1);
      }
      else {
        _dev_err(lVar4 + 0x10,"%s: failed to get irq\n","tsens_register_irq");
      }
    }
    put_device(lVar4 + 0x10);
  }
  return iVar3;
}



//------------------------------------------------------------
// tsens_irq_thread @ 00102a98 size=608
// signature: undefined tsens_irq_thread(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_irq_thread(undefined4 param_1,undefined8 *param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined8 uVar7;
  int local_9c;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_9c = 0;
  if (*(int *)(param_2 + 1) != 0) {
    uVar6 = 0;
    lVar1 = (long)param_2 + 0x24;
    do {
      if (param_2[(long)(int)uVar6 * 5 + 0x154] != 0) {
        uVar2 = *(uint *)((long)param_2 + (long)(int)uVar6 * 0x28 + 0xaac);
        iVar4 = tsens_threshold_violated(param_2,uVar2,&local_98);
        if (iVar4 != 0) {
          iVar4 = get_temp_tsens_valid(param_2 + (long)(int)uVar6 * 5 + 0x153,&local_9c);
          if (iVar4 == 0) {
            uVar5 = _raw_spin_lock_irqsave(lVar1);
            tsens_read_irq_state(param_2,uVar2,param_2 + (long)(int)uVar6 * 5 + 0x153,&local_98);
            uVar3 = 1 << (ulong)(uVar2 & 0x1f);
            if (((int)local_98 == 0) ||
               ((2 < *(uint *)param_2[0x147] && (((uint)local_90 & uVar3) != 0)))) {
              if (((int)local_88 != 0) &&
                 ((*(uint *)param_2[0x147] < 3 || (((uint)local_80 & uVar3) == 0)))) {
                tsens_set_interrupt(param_2,uVar2,0,0);
                uVar7 = 0;
                if (local_88._4_4_ < local_9c) goto LAB_00102c50;
                goto LAB_00102bfc;
              }
LAB_00102c64:
              _raw_spin_unlock_irqrestore(lVar1,uVar5);
            }
            else {
              uVar7 = 1;
              tsens_set_interrupt(param_2,uVar2,1,0);
              if (local_9c < local_98._4_4_) {
LAB_00102c50:
                tsens_set_interrupt(param_2,uVar2,uVar7,1);
                goto LAB_00102c64;
              }
LAB_00102bfc:
              _raw_spin_unlock_irqrestore(lVar1,uVar5);
              uVar5 = param_2[(long)(int)uVar6 * 5 + 0x154];
              *(int *)(param_2 + (long)(int)uVar6 * 5 + 0x157) = local_9c;
              thermal_zone_device_update(uVar5,0);
            }
            if (*(int *)param_2[0x147] == 0) break;
            *(undefined4 *)(param_2 + (long)(int)uVar6 * 5 + 0x157) = 0x80000000;
          }
          else {
            _dev_err(*param_2,"[%u] %s: error reading sensor\n",uVar2,"tsens_irq_thread");
          }
        }
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)(param_2 + 1));
  }
  if ((param_2 != (undefined8 *)0x0) && (param_2[0x14f] != 0)) {
    lVar1 = sp_el0;
    ipc_log_string(param_2[0x14f],"%s: %s: irq[%d] exit [%s]\n","tsens_irq_thread",
                   "tsens_irq_thread",param_1,lVar1 + 0x848);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// tsens_critical_irq_thread @ 00102cfc size=524
// signature: undefined tsens_critical_irq_thread(void)
// callers: []
//------------------------------------------------------------

int tsens_critical_irq_thread(undefined8 param_1,undefined8 *param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  int local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  local_94 = 0;
  if ((*(byte *)(param_2[0x147] + 4) >> 3 & 1) != 0) {
    iVar3 = regmap_field_read(param_2[0x11e],&local_90);
    if (iVar3 != 0) goto LAB_00102ecc;
    if ((int)local_90 != 0) {
      regmap_field_update_bits_base(param_2[0x11f],0xffffffff,1,0,0,0);
      regmap_field_update_bits_base(param_2[0x11f],0xffffffff,0,0,0,0);
      iVar3 = regmap_field_read(param_2[0x121],&local_94);
      if (iVar3 != 0) goto LAB_00102ecc;
      if (((param_2 != (undefined8 *)0x0) && (local_94 != 0)) && (param_2[0x14f] != 0)) {
        lVar2 = sp_el0;
        ipc_log_string(param_2[0x14f],"%s: %s: watchdog count: %d\n [%s]\n",
                       "tsens_critical_irq_thread","tsens_critical_irq_thread",local_94,
                       lVar2 + 0x848);
      }
    }
  }
  iVar3 = 1;
  if (*(int *)(param_2 + 1) != 0) {
    uVar4 = 0;
    do {
      if (param_2[(long)(int)uVar4 * 5 + 0x154] != 0) {
        uVar1 = *(uint *)((long)param_2 + (long)(int)uVar4 * 0x28 + 0xaac);
        iVar3 = tsens_threshold_violated(param_2,uVar1,&local_88);
        if (iVar3 != 0) {
          iVar3 = get_temp_tsens_valid(param_2 + (long)(int)uVar4 * 5 + 0x153,(long)&local_90 + 4);
          if (iVar3 == 0) {
            tsens_read_irq_state(param_2,uVar1,param_2 + (long)(int)uVar4 * 5 + 0x153,&local_88);
            if (((int)local_68 != 0) &&
               ((*(uint *)param_2[0x147] < 3 || (((uint)local_60 & 1 << (ulong)(uVar1 & 0x1f)) == 0)
                ))) {
              tsens_set_interrupt(param_2,uVar1,2,0);
            }
          }
          else {
            _dev_err(*param_2,"[%u] %s: error reading sensor\n",uVar1,"tsens_critical_irq_thread");
          }
        }
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_2 + 1));
    iVar3 = 1;
  }
LAB_00102ecc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// tsens_get_temp @ 00102f0c size=68
// signature: undefined tsens_get_temp(void)
// callers: []
//------------------------------------------------------------

void tsens_get_temp(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(**(long **)(param_1 + 0x3f0) + 0xa48) + 0x10);
  if (*(int *)(pcVar1 + -4) != 0x78ed951a) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102f40);
    (*pcVar1)();
  }
  (*pcVar1)();
  return;
}



//------------------------------------------------------------
// tsens_set_trips @ 00102f54 size=612
// signature: undefined tsens_set_trips(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_set_trips(long param_1,int param_2,int param_3)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  long *plVar11;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  plVar11 = *(long **)(param_1 + 0x3f0);
  lVar10 = *plVar11;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  iVar1 = 0;
  if (**(int **)(lVar10 + 0xa38) != 0) {
    iVar1 = *(int *)((long)plVar11 + 0x14);
  }
  if (param_3 < -39999) {
    param_3 = -40000;
  }
  if (119999 < param_3) {
    param_3 = 120000;
  }
  if (param_2 < -39999) {
    param_2 = -40000;
  }
  if (119999 < param_2) {
    param_2 = 120000;
  }
  if ((*(byte *)(*(long *)(*plVar11 + 0xa38) + 4) >> 1 & 1) == 0) {
    uVar6 = (long)param_2 / 100 + ((long)param_2 >> 0x3f);
    iVar8 = param_3 / 100;
    iVar5 = param_2 / 100;
  }
  else {
    uVar6 = (long)(int)plVar11[2] + (long)(int)plVar11[3] * (long)(param_3 / 1000);
    uVar7 = (long)(int)plVar11[2] + (long)(int)plVar11[3] * (long)(param_2 / 1000);
    uVar9 = uVar7 & 0xffffffff;
    iVar8 = 0x3ff;
    if (uVar6 < 0xf9c18) {
      iVar8 = (int)((uVar6 & 0xffffffff) / 1000);
    }
    uVar6 = uVar9 / 1000;
    iVar5 = 0x3ff;
    if (uVar7 < 0xf9c18) {
      iVar5 = (int)(uVar9 / 1000);
    }
  }
  uVar4 = _raw_spin_lock_irqsave(uVar6,lVar10 + 0x24);
  tsens_read_irq_state(lVar10,iVar1,plVar11,&local_98);
  if (iVar1 + 0x69U < 0x141) {
    regmap_field_update_bits_base
              (*(undefined8 *)(lVar10 + (ulong)(iVar1 + 0x69U) * 8 + 0x28),0xffffffff,iVar5,0,0,0);
    if (iVar1 + 0xb9U < 0x141) {
      regmap_field_update_bits_base
                (*(undefined8 *)(lVar10 + (ulong)(iVar1 + 0xb9U) * 8 + 0x28),0xffffffff,iVar8,0,0,0)
      ;
      tsens_set_interrupt(lVar10,iVar1,0,1);
      tsens_set_interrupt(lVar10,iVar1,1,1);
      _raw_spin_unlock_irqrestore(lVar10 + 0x24,uVar4);
      if ((lVar10 != 0) && (*(long *)(lVar10 + 0xa78) != 0)) {
        lVar2 = sp_el0;
        ipc_log_string(*(long *)(lVar10 + 0xa78),"%s: [%u] %s: (%d:%d)->(%d:%d)\n [%s]\n",
                       "tsens_set_trips",iVar1,"tsens_set_trips",local_88._4_4_,local_98._4_4_,
                       param_2,param_3,lVar2 + 0x848);
      }
      lVar10 = sp_el0;
      if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return 0;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1031b4);
  (*pcVar3)();
}



//------------------------------------------------------------
// qti_tz_get_trend @ 001031bc size=344
// signature: undefined qti_tz_get_trend(void)
// callers: []
//------------------------------------------------------------

void qti_tz_get_trend(long param_1,ulong param_2,undefined4 *param_3)

{
  long *plVar1;
  long lVar2;
  undefined8 uVar3;
  code *pcVar4;
  long *plVar5;
  bool bVar6;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  if (param_1 != 0) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x440) + 0x30);
    if (*(int *)(pcVar4 + -4) != -0x14767f3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103218);
      (*pcVar4)();
    }
    uVar3 = (*pcVar4)(param_1,param_2,(long)&local_40 + 4);
    if ((int)uVar3 != 0) goto LAB_001032e4;
    pcVar4 = *(code **)(*(long *)(param_1 + 0x440) + 0x40);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0x14767f3) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103250);
        (*pcVar4)();
      }
      uVar3 = (*pcVar4)(param_1,param_2 & 0xffffffff,&local_40);
      if ((int)uVar3 != 0) goto LAB_001032e4;
      if ((int)local_40 != 0) {
        plVar1 = (long *)(param_1 + 0x460);
        plVar5 = *(long **)(param_1 + 0x460);
        if (plVar5 != plVar1) {
          bVar6 = false;
          do {
            while ((int)plVar5[-0x12] == (int)param_2) {
              if (plVar5[-0x10] != plVar5[-0x11]) goto LAB_001032e0;
              plVar5 = (long *)*plVar5;
              bVar6 = true;
              if (plVar5 == plVar1) goto LAB_001032b8;
            }
            plVar5 = (long *)*plVar5;
          } while (plVar5 != plVar1);
          if (bVar6) {
LAB_001032b8:
            uVar3 = 0xffffffea;
            if ((*(int *)(param_1 + 0x420) < local_40._4_4_) &&
               (local_40._4_4_ - (int)local_40 < *(int *)(param_1 + 0x420))) {
              uVar3 = 0;
              *param_3 = 0;
            }
            goto LAB_001032e4;
          }
        }
      }
    }
  }
LAB_001032e0:
  uVar3 = 0xffffffea;
LAB_001032e4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// tsens_read_irq_state @ 00103314 size=840
// signature: undefined tsens_read_irq_state(void)
// callers: [tsens_set_trips, tsens_irq_thread, tsens_critical_irq_thread]
//------------------------------------------------------------

void tsens_read_irq_state(long param_1,int param_2,long *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  long lVar7;
  int local_5c;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  if (0x140 < param_2 + 0x99U) {
LAB_00103654:
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x103658);
    (*pcVar3)();
  }
  iVar4 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0x99U) * 8 + 0x28),
                            param_4 + 3);
  if (iVar4 == 0) {
    if (0x140 < param_2 + 0x49U) goto LAB_00103654;
    iVar4 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0x49U) * 8 + 0x28),
                              param_4 + 7);
    if (iVar4 == 0) {
      if (**(uint **)(param_1 + 0xa38) < 3) {
        iVar4 = 0;
        param_4[2] = 0;
        param_4[6] = 0;
        param_4[10] = 0;
        param_4[0xb] = 0;
      }
      else {
        if (0x140 < param_2 + 0xa9U) goto LAB_00103654;
        iVar4 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0xa9U) * 8 + 0x28),
                                  param_4 + 2);
        if ((iVar4 != 0) ||
           (iVar4 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0x59) * 8 + 0x28),
                                      param_4 + 6), iVar4 != 0)) goto LAB_00103390;
        if (0x140 < param_2 + 0xe9U) goto LAB_00103654;
        iVar4 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0xe9U) * 8 + 0x28),
                                  param_4 + 0xb);
        if (iVar4 != 0) goto LAB_00103390;
        if (0x140 < param_2 + 0xf9U) goto LAB_00103654;
        iVar4 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0xf9U) * 8 + 0x28),
                                  param_4 + 10);
        if (iVar4 != 0) goto LAB_00103390;
        iVar4 = tsens_hw_to_mC(param_3,param_2 + 0x109);
      }
      param_4[9] = iVar4;
      lVar7 = *param_3;
      local_5c = 0;
      if (0x140 < param_2 + 0xb9U) goto LAB_00103654;
      iVar6 = *(int *)(*(long *)(lVar7 + 0xa40) + 0xb8);
      iVar2 = *(int *)(*(long *)(lVar7 + 0xa40) + 0xbc);
      iVar4 = regmap_field_read(*(undefined8 *)(lVar7 + (ulong)(param_2 + 0xb9U) * 8 + 0x28),
                                &local_5c);
      if (iVar4 == 0) {
        if ((*(byte *)(*(long *)(lVar7 + 0xa38) + 4) >> 1 & 1) == 0) {
          uVar1 = (iVar6 - iVar2) + 0x1f;
          iVar4 = (local_5c << (ulong)(uVar1 & 0x1f)) >> (uVar1 & 0x1f);
          iVar6 = 100;
        }
        else {
          iVar6 = local_5c * 1000 - (int)param_3[2];
          iVar2 = (int)param_3[3];
          if (iVar6 < 1) {
            if (iVar6 < 0) {
              iVar4 = iVar2;
              if (iVar2 < 0) {
                iVar4 = iVar2 + 1;
              }
              iVar6 = iVar6 - (iVar4 >> 1);
            }
            else {
              iVar6 = 0;
            }
          }
          else {
            iVar4 = iVar2;
            if (iVar2 < 0) {
              iVar4 = iVar2 + 1;
            }
            iVar6 = iVar6 + (iVar4 >> 1);
          }
          iVar4 = 0;
          if (iVar2 != 0) {
            iVar4 = iVar6 / iVar2;
          }
          iVar6 = 1000;
        }
        iVar4 = iVar4 * iVar6;
      }
      param_4[1] = iVar4;
      lVar7 = *param_3;
      local_5c = 0;
      iVar6 = *(int *)(*(long *)(lVar7 + 0xa40) + 0xb8);
      iVar2 = *(int *)(*(long *)(lVar7 + 0xa40) + 0xbc);
      iVar4 = regmap_field_read(*(undefined8 *)(lVar7 + (ulong)(param_2 + 0x69) * 8 + 0x28),
                                &local_5c);
      if (iVar4 == 0) {
        if ((*(byte *)(*(long *)(lVar7 + 0xa38) + 4) >> 1 & 1) == 0) {
          uVar1 = (iVar6 - iVar2) + 0x1f;
          iVar4 = (local_5c << (ulong)(uVar1 & 0x1f)) >> (uVar1 & 0x1f);
          iVar6 = 100;
        }
        else {
          iVar6 = local_5c * 1000 - (int)param_3[2];
          iVar2 = (int)param_3[3];
          if (iVar6 < 1) {
            if (iVar6 < 0) {
              iVar4 = iVar2;
              if (iVar2 < 0) {
                iVar4 = iVar2 + 1;
              }
              iVar6 = iVar6 - (iVar4 >> 1);
            }
            else {
              iVar6 = 0;
            }
          }
          else {
            iVar4 = iVar2;
            if (iVar2 < 0) {
              iVar4 = iVar2 + 1;
            }
            iVar6 = iVar6 + (iVar4 >> 1);
          }
          iVar4 = 0;
          if (iVar2 != 0) {
            iVar4 = iVar6 / iVar2;
          }
          iVar6 = 1000;
        }
        iVar4 = iVar4 * iVar6;
      }
      param_4[5] = iVar4;
      if ((param_1 != 0) && (*(long *)(param_1 + 0xa78) != 0)) {
        puVar5 = &DAT_00105ce2;
        iVar4 = param_4[4];
        if (*param_4 == 0 && iVar4 == 0) {
          iVar4 = 0;
          puVar5 = &UNK_00105bb9;
          if (param_4[8] != 0) {
            puVar5 = &DAT_00105ce2;
          }
        }
        lVar7 = sp_el0;
        ipc_log_string(*(long *)(param_1 + 0xa78),
                       "%s: [%u] %s%s: status(%u|%u|%u) | clr(%u|%u|%u) | mask(%u|%u|%u)\n [%s]\n",
                       "tsens_read_irq_state",param_2,"tsens_read_irq_state",puVar5,iVar4,*param_4,
                       param_4[8],param_4[7],param_4[3],param_4[0xb],param_4[6],param_4[2],
                       param_4[10],lVar7 + 0x848);
      }
    }
  }
LAB_00103390:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tsens_set_interrupt @ 0010365c size=436
// signature: undefined tsens_set_interrupt(void)
// callers: [tsens_set_trips, tsens_irq_thread, tsens_critical_irq_thread]
//------------------------------------------------------------

void tsens_set_interrupt(long param_1,int param_2,uint param_3,uint param_4)

{
  char *pcVar1;
  char *pcVar2;
  undefined *puVar3;
  long lVar4;
  code *pcVar5;
  undefined8 uVar6;
  int iVar7;
  uint uVar8;
  undefined8 *puVar9;
  uint uVar10;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0xa78) != 0)) {
    pcVar1 = "UP";
    if (param_3 != 1) {
      pcVar1 = "CRITICAL";
    }
    pcVar2 = "LOW";
    if (param_3 != 0) {
      pcVar2 = pcVar1;
    }
    lVar4 = sp_el0;
    puVar3 = &DAT_00105b07;
    if ((param_4 & 1) == 0) {
      puVar3 = &DAT_00105a9b;
    }
    ipc_log_string(*(long *)(param_1 + 0xa78),"%s: [%u] %s: %s -> %s\n [%s]\n","tsens_set_interrupt"
                   ,param_2,"tsens_set_interrupt",pcVar2,puVar3,lVar4 + 0x848);
  }
  if (**(uint **)(param_1 + 0xa38) < 3) {
    if (param_3 - 2 < 2) {
      return;
    }
    if (param_3 == 1) {
      iVar7 = 0x99;
LAB_001037c4:
      uVar8 = iVar7 + param_2;
      if (0x140 < uVar8) {
LAB_001037d0:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1037d4);
        (*pcVar5)();
      }
    }
    else {
      if (param_3 == 0) {
        iVar7 = 0x49;
        goto LAB_001037c4;
      }
      uVar8 = 0;
    }
    uVar10 = (param_4 ^ 0xffffffff) & 1;
    uVar6 = *(undefined8 *)(param_1 + (ulong)uVar8 * 8 + 0x28);
    goto LAB_001037ec;
  }
  if (param_3 < 3) {
    param_2 = param_2 + param_3 * 0x50;
    uVar8 = param_2 + 0x59;
    if ((param_4 & 1) != 0) {
      if (0x140 < uVar8) goto LAB_001037d0;
      goto LAB_00103750;
    }
    if (0x140 < uVar8) goto LAB_001037d0;
    uVar10 = param_2 + 0x49;
LAB_00103768:
    regmap_field_update_bits_base
              (*(undefined8 *)(param_1 + (ulong)uVar8 * 8 + 0x28),0xffffffff,1,0,0,0);
    if (0x140 < uVar10) goto LAB_001037d0;
    puVar9 = (undefined8 *)(param_1 + (ulong)uVar10 * 8 + 0x28);
    regmap_field_update_bits_base(*puVar9,0xffffffff,1,0,0,0);
  }
  else {
    uVar8 = 0;
    uVar10 = 0;
    if ((param_4 & 1) == 0) goto LAB_00103768;
LAB_00103750:
    puVar9 = (undefined8 *)(param_1 + (ulong)uVar8 * 8 + 0x28);
  }
  uVar6 = *puVar9;
  uVar10 = 0;
LAB_001037ec:
  regmap_field_update_bits_base(uVar6,0xffffffff,uVar10,0,0,0);
  return;
}



//------------------------------------------------------------
// qti_tz_change_mode @ 00103814 size=156
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
// tsens_threshold_violated @ 001038b0 size=204
// signature: undefined tsens_threshold_violated(void)
// callers: [tsens_irq_thread, tsens_critical_irq_thread]
//------------------------------------------------------------

ulong tsens_threshold_violated(long param_1,int param_2,int *param_3)

{
  code *pcVar1;
  ulong uVar2;
  
  if (0x140 < param_2 + 0x79U) {
LAB_00103978:
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10397c);
    (*pcVar1)();
  }
  uVar2 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0x79U) * 8 + 0x28),param_3);
  if ((int)uVar2 == 0) {
    if (0x140 < param_2 + 0x29U) goto LAB_00103978;
    uVar2 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0x29U) * 8 + 0x28),
                              param_3 + 4);
    if ((int)uVar2 == 0) {
      if ((*(byte *)(*(long *)(param_1 + 0xa38) + 4) & 1) != 0) {
        if (0x140 < param_2 + 0xc9U) goto LAB_00103978;
        uVar2 = regmap_field_read(*(undefined8 *)(param_1 + (ulong)(param_2 + 0xc9U) * 8 + 0x28),
                                  param_3 + 8);
        if ((int)uVar2 != 0) {
          return uVar2;
        }
      }
      if ((*param_3 == 0) && (param_3[4] == 0)) {
        uVar2 = (ulong)(param_3[8] != 0);
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// tsens_get_cold_status @ 00103980 size=80
// signature: undefined tsens_get_cold_status(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_get_cold_status(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(long *)(**(long **)(param_1 + 0x3f0) + 0xa48) + 0x48);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xffffffa1;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x11b58f49) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1039b8);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// tsens_suspend @ 001039d4 size=80
// signature: undefined tsens_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_suspend(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa48);
  if ((lVar2 == 0) || (pcVar3 = *(code **)(lVar2 + 0x28), pcVar3 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x63da61ea) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103a0c);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// tsens_resume @ 00103a28 size=80
// signature: undefined tsens_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_resume(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa48);
  if ((lVar2 == 0) || (pcVar3 = *(code **)(lVar2 + 0x30), pcVar3 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x63da61ea) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103a60);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// tsens_freeze @ 00103a7c size=80
// signature: undefined tsens_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_freeze(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa48);
  if ((lVar2 == 0) || (pcVar3 = *(code **)(lVar2 + 0x38), pcVar3 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x63da61ea) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103ab4);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// tsens_restore @ 00103ad0 size=80
// signature: undefined tsens_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 tsens_restore(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa48);
  if ((lVar2 == 0) || (pcVar3 = *(code **)(lVar2 + 0x40), pcVar3 == (code *)0x0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x63da61ea) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103b08);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)();
  }
  return uVar1;
}



//------------------------------------------------------------
// calibrate_v1 @ 00103b24 size=1048
// signature: undefined calibrate_v1(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_v1(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  code *pcVar6;
  uint *puVar7;
  int iVar8;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  puVar7 = (uint *)qfprom_read(*param_1,"calib");
  if ((uint *)0xfffffffffffff000 < puVar7) goto LAB_00103f08;
  uVar1 = puVar7[4] & 7;
  if (uVar1 == 3) {
    local_78 = CONCAT44(*puVar7 >> 0x12,*puVar7 >> 6) & 0x3f0000003f;
    uVar1 = *puVar7 >> 0x1e | (puVar7[1] & 0xf) << 2;
    local_70 = CONCAT44(puVar7[1] >> 10,uVar1) & 0x3fffffffff;
    local_68 = CONCAT44(puVar7[2] >> 6,puVar7[1] >> 0x16) & 0x3f0000003f;
    uVar2 = puVar7[2] >> 0x1e | (puVar7[3] & 0xf) << 2;
    local_60 = CONCAT44(uVar2,puVar7[2] >> 0x12) & 0xffffffff0000003f;
    iVar8 = *(int *)(param_1 + 1);
    local_58 = CONCAT44(puVar7[3] >> 0x16,puVar7[3] >> 10) & 0x3f0000003f;
    if (iVar8 != 0) {
      uVar4 = puVar7[4] >> 0xb & 0xff;
      iVar3 = ((*puVar7 >> 6 & 0x3f) + uVar4) * 4;
      local_78 = CONCAT44(local_78._4_4_,iVar3);
      if ((iVar8 != 1) &&
         (local_78 = CONCAT44(((*puVar7 >> 0x12 & 0x3f) + uVar4) * 4,iVar3), iVar8 != 2)) {
        iVar3 = (uVar1 + uVar4) * 4;
        local_70 = CONCAT44(local_70._4_4_,iVar3);
        if ((iVar8 != 3) &&
           (local_70 = CONCAT44(((puVar7[1] >> 10 & 0x3f) + uVar4) * 4,iVar3), iVar8 != 4)) {
          iVar3 = ((puVar7[1] >> 0x16 & 0x3f) + uVar4) * 4;
          local_68 = CONCAT44(local_68._4_4_,iVar3);
          if ((iVar8 != 5) &&
             (local_68 = CONCAT44(((puVar7[2] >> 6 & 0x3f) + uVar4) * 4,iVar3), iVar8 != 6)) {
            iVar3 = ((puVar7[2] >> 0x12 & 0x3f) + uVar4) * 4;
            local_60 = CONCAT44(local_60._4_4_,iVar3);
            if ((iVar8 != 7) && (local_60 = CONCAT44((uVar2 + uVar4) * 4,iVar3), iVar8 != 8)) {
              iVar3 = ((puVar7[3] >> 10 & 0x3f) + uVar4) * 4;
              local_58 = CONCAT44(local_58._4_4_,iVar3);
              if ((iVar8 != 9) &&
                 (local_58 = CONCAT44(((puVar7[3] >> 0x16 & 0x3f) + uVar4) * 4,iVar3), iVar8 != 10))
              goto LAB_00103f38;
            }
          }
        }
      }
    }
LAB_00103cec:
    local_50 = CONCAT44(*puVar7 >> 0xc,*puVar7) & 0x3f0000003f;
    local_48 = CONCAT44(puVar7[1] >> 4,(uint)*(byte *)((long)puVar7 + 3)) & 0x3f0000003f;
    local_40 = CONCAT44(puVar7[2],(uint)*(ushort *)((long)puVar7 + 6)) & 0x3f0000003f;
    local_38 = (ulong)CONCAT14(*(byte *)((long)puVar7 + 0xb),puVar7[2] >> 0xc) & 0x3f0000003f;
    local_30 = (ulong)CONCAT24(*(ushort *)((long)puVar7 + 0xe),puVar7[3] >> 4) & 0x3f0000003f;
    if (iVar8 != 0) {
      uVar1 = puVar7[4] >> 3 & 0xff;
      iVar3 = ((*puVar7 & 0x3f) + uVar1) * 4;
      local_50 = CONCAT44(local_50._4_4_,iVar3);
      if ((iVar8 != 1) &&
         (local_50 = CONCAT44(((*puVar7 >> 0xc & 0x3f) + uVar1) * 4,iVar3), iVar8 != 2)) {
        iVar3 = ((*(byte *)((long)puVar7 + 3) & 0x3f) + uVar1) * 4;
        local_48 = CONCAT44(local_48._4_4_,iVar3);
        if ((iVar8 != 3) &&
           (local_48 = CONCAT44(((puVar7[1] >> 4 & 0x3f) + uVar1) * 4,iVar3), iVar8 != 4)) {
          iVar3 = ((*(ushort *)((long)puVar7 + 6) & 0x3f) + uVar1) * 4;
          local_40 = CONCAT44(local_40._4_4_,iVar3);
          if ((iVar8 != 5) &&
             (local_40 = CONCAT44(((puVar7[2] & 0x3f) + uVar1) * 4,iVar3), iVar8 != 6)) {
            iVar3 = ((puVar7[2] >> 0xc & 0x3f) + uVar1) * 4;
            local_38 = CONCAT44(local_38._4_4_,iVar3);
            if ((iVar8 != 7) &&
               (local_38 = CONCAT44(((*(byte *)((long)puVar7 + 0xb) & 0x3f) + uVar1) * 4,iVar3),
               iVar8 != 8)) {
              iVar3 = ((puVar7[3] >> 4 & 0x3f) + uVar1) * 4;
              local_30 = CONCAT44(local_30._4_4_,iVar3);
              if (iVar8 != 9) {
                local_30 = CONCAT44(((*(ushort *)((long)puVar7 + 0xe) & 0x3f) + uVar1) * 4,iVar3);
                goto joined_r0x00103e34;
              }
            }
          }
        }
      }
    }
  }
  else {
    if (uVar1 == 2) {
      iVar8 = *(int *)(param_1 + 1);
      goto LAB_00103cec;
    }
    iVar8 = *(int *)(param_1 + 1);
    if (iVar8 != 0) {
      local_50 = CONCAT44(local_50._4_4_,500);
      local_78 = CONCAT44(local_78._4_4_,0x30c);
      if (iVar8 == 1) goto LAB_00103eec;
      local_50 = 0x1f4000001f4;
      local_78 = 0x30c0000030c;
      if (iVar8 == 2) goto LAB_00103eec;
      local_48 = CONCAT44(local_48._4_4_,500);
      local_70 = CONCAT44(local_70._4_4_,0x30c);
      if (iVar8 == 3) goto LAB_00103eec;
      local_48 = 0x1f4000001f4;
      local_70 = 0x30c0000030c;
      if (iVar8 == 4) goto LAB_00103eec;
      local_40 = CONCAT44(local_40._4_4_,500);
      local_68 = CONCAT44(local_68._4_4_,0x30c);
      if (iVar8 == 5) goto LAB_00103eec;
      local_40 = 0x1f4000001f4;
      local_68 = 0x30c0000030c;
      if (iVar8 == 6) goto LAB_00103eec;
      local_38 = CONCAT44(local_38._4_4_,500);
      local_60 = CONCAT44(local_60._4_4_,0x30c);
      if (iVar8 == 7) goto LAB_00103eec;
      local_38 = 0x1f4000001f4;
      local_60 = 0x30c0000030c;
      if (iVar8 == 8) goto LAB_00103eec;
      local_30 = CONCAT44(local_30._4_4_,500);
      local_58 = CONCAT44(local_58._4_4_,0x30c);
      if (iVar8 == 9) goto LAB_00103eec;
      local_30 = 0x1f4000001f4;
      local_58 = 0x30c0000030c;
joined_r0x00103e34:
      if (iVar8 != 10) {
LAB_00103f38:
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x103f3c);
        (*pcVar6)();
      }
    }
  }
LAB_00103eec:
  compute_intercept_slope(param_1,&local_50,&local_78);
  kfree(puVar7);
  puVar7 = (uint *)0x0;
LAB_00103f08:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar7 & 0xffffffff;
}



//------------------------------------------------------------
// calibrate_8976 @ 00103f40 size=1184
// signature: undefined calibrate_8976(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_8976(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  uint *puVar6;
  int iVar7;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  uint local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  local_40 = 0;
  local_38 = 0;
  local_50 = 0;
  local_48 = 0;
  local_58 = 0;
  local_60 = 0;
  local_70 = 0;
  local_68 = 0;
  local_80 = 0;
  local_78 = 0;
  local_88 = 0;
  puVar6 = (uint *)qfprom_read(*param_1,"calib");
  if ((uint *)0xfffffffffffff000 < puVar6) goto LAB_001043ac;
  if ((puVar6[4] & 3) == 3) {
    iVar7 = *(int *)(param_1 + 1);
    local_88 = CONCAT44(*puVar6 >> 0x1a,*puVar6 >> 0xe) & 0xffffffff0000003f;
    local_80 = CONCAT44(puVar6[1] >> 0x12,puVar6[1] >> 6) & 0x3f0000003f;
    local_78 = CONCAT44(puVar6[2] >> 0x1a,puVar6[2] >> 0xe) & 0xffffffff0000003f;
    local_70 = CONCAT44(puVar6[3] >> 0x12,puVar6[3] >> 6) & 0x3f0000003f;
    local_68 = CONCAT44(puVar6[4] >> 0x15,puVar6[4] >> 9) & 0x3f0000003f;
    local_60 = puVar6[5] >> 1 & 0x3f;
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar2 = (*puVar6 >> 0xe & 0x3f) << 2;
      local_88 = CONCAT44(local_88._4_4_,iVar2);
      if (iVar7 == 1) {
        iVar7 = 1;
      }
      else {
        local_88 = CONCAT44((*puVar6 >> 0x1a) << 2,iVar2);
        if (iVar7 == 2) {
          iVar7 = 2;
        }
        else {
          iVar2 = (puVar6[1] >> 6 & 0x3f) << 2;
          local_80 = CONCAT44(local_80._4_4_,iVar2);
          if (iVar7 == 3) {
            iVar7 = 3;
          }
          else {
            local_80 = CONCAT44((puVar6[1] >> 0x12 & 0x3f) << 2,iVar2);
            if (iVar7 == 4) {
              iVar7 = 4;
            }
            else {
              iVar2 = (puVar6[2] >> 0xe & 0x3f) << 2;
              local_78 = CONCAT44(local_78._4_4_,iVar2);
              if (iVar7 == 5) {
                iVar7 = 5;
              }
              else {
                local_78 = CONCAT44((puVar6[2] >> 0x1a) << 2,iVar2);
                if (iVar7 == 6) {
                  iVar7 = 6;
                }
                else {
                  iVar2 = (puVar6[3] >> 6 & 0x3f) << 2;
                  local_70 = CONCAT44(local_70._4_4_,iVar2);
                  if (iVar7 == 7) {
                    iVar7 = 7;
                  }
                  else {
                    local_70 = CONCAT44((puVar6[3] >> 0x12 & 0x3f) << 2,iVar2);
                    if (iVar7 == 8) {
                      iVar7 = 8;
                    }
                    else {
                      iVar2 = (puVar6[4] >> 9 & 0x3f) << 2;
                      local_68 = CONCAT44(local_68._4_4_,iVar2);
                      if (iVar7 == 9) {
                        iVar7 = 9;
                      }
                      else {
                        local_68 = CONCAT44((puVar6[4] >> 0x15 & 0x3f) << 2,iVar2);
                        if (iVar7 == 10) {
                          iVar7 = 10;
                        }
                        else {
                          local_60 = local_60 << 2;
                          if (iVar7 != 0xb) goto LAB_001043dc;
                          iVar7 = 0xb;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
LAB_00104224:
    uVar3 = *puVar6 >> 8;
    local_58 = CONCAT44(*puVar6 >> 0x14,uVar3) & 0x3f0000003f;
    local_50 = CONCAT44(puVar6[1] >> 0xc,puVar6[1]) & 0x3f0000003f;
    local_48 = CONCAT44(puVar6[2] >> 0x14,puVar6[2] >> 8) & 0x3f0000003f;
    local_40 = CONCAT44(puVar6[3] >> 0xc,puVar6[3]) & 0x3f0000003f;
    local_38 = CONCAT44(puVar6[4] >> 0xf,puVar6[4] >> 3) & 0x3f0000003f;
    local_30 = puVar6[5] & 1 | puVar6[4] >> 0x1b;
    if (iVar7 != 0) {
      uVar1 = *puVar6 & 0xff;
      iVar2 = ((uVar3 & 0x3f) + uVar1) * 4;
      local_58 = CONCAT44(local_58._4_4_,iVar2);
      if ((iVar7 != 1) &&
         (local_58 = CONCAT44(((*puVar6 >> 0x14 & 0x3f) + uVar1) * 4,iVar2), iVar7 != 2)) {
        iVar2 = ((puVar6[1] & 0x3f) + uVar1) * 4;
        local_50 = CONCAT44(local_50._4_4_,iVar2);
        if ((iVar7 != 3) &&
           (local_50 = CONCAT44(((puVar6[1] >> 0xc & 0x3f) + uVar1) * 4,iVar2), iVar7 != 4)) {
          iVar2 = ((puVar6[2] >> 8 & 0x3f) + uVar1) * 4;
          local_48 = CONCAT44(local_48._4_4_,iVar2);
          if ((iVar7 != 5) &&
             (local_48 = CONCAT44(((puVar6[2] >> 0x14 & 0x3f) + uVar1) * 4,iVar2), iVar7 != 6)) {
            iVar2 = ((puVar6[3] & 0x3f) + uVar1) * 4;
            local_40 = CONCAT44(local_40._4_4_,iVar2);
            if ((iVar7 != 7) &&
               (local_40 = CONCAT44(((puVar6[3] >> 0xc & 0x3f) + uVar1) * 4,iVar2), iVar7 != 8)) {
              iVar2 = ((puVar6[4] >> 3 & 0x3f) + uVar1) * 4;
              local_38 = CONCAT44(local_38._4_4_,iVar2);
              if ((iVar7 != 9) &&
                 (local_38 = CONCAT44(((puVar6[4] >> 0xf & 0x3f) + uVar1) * 4,iVar2), iVar7 != 10))
              {
                local_30 = (local_30 + uVar1) * 4;
                goto joined_r0x0010438c;
              }
            }
          }
        }
      }
    }
  }
  else {
    if ((puVar6[4] & 3) == 2) {
      iVar7 = *(int *)(param_1 + 1);
      goto LAB_00104224;
    }
    iVar7 = *(int *)(param_1 + 1);
    if (iVar7 != 0) {
      local_58 = CONCAT44(local_58._4_4_,500);
      local_88 = CONCAT44(local_88._4_4_,0x30c);
      if (iVar7 == 1) goto LAB_00104390;
      local_58 = 0x1f4000001f4;
      local_88 = 0x30c0000030c;
      if (iVar7 == 2) goto LAB_00104390;
      local_50 = CONCAT44(local_50._4_4_,500);
      local_80 = CONCAT44(local_80._4_4_,0x30c);
      if (iVar7 == 3) goto LAB_00104390;
      local_50 = 0x1f4000001f4;
      local_80 = 0x30c0000030c;
      if (iVar7 == 4) goto LAB_00104390;
      local_48 = CONCAT44(local_48._4_4_,500);
      local_78 = CONCAT44(local_78._4_4_,0x30c);
      if (iVar7 == 5) goto LAB_00104390;
      local_48 = 0x1f4000001f4;
      local_78 = 0x30c0000030c;
      if (iVar7 == 6) goto LAB_00104390;
      local_40 = CONCAT44(local_40._4_4_,500);
      local_70 = CONCAT44(local_70._4_4_,0x30c);
      if (iVar7 == 7) goto LAB_00104390;
      local_40 = 0x1f4000001f4;
      local_70 = 0x30c0000030c;
      if (iVar7 == 8) goto LAB_00104390;
      local_38 = CONCAT44(local_38._4_4_,500);
      local_68 = CONCAT44(local_68._4_4_,0x30c);
      if (iVar7 == 9) goto LAB_00104390;
      local_38 = 0x1f4000001f4;
      local_68 = 0x30c0000030c;
      if (iVar7 == 10) goto LAB_00104390;
      local_30 = 500;
      local_60 = 0x30c;
joined_r0x0010438c:
      if (iVar7 != 0xb) {
LAB_001043dc:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1043e0);
        (*pcVar5)();
      }
    }
  }
LAB_00104390:
  compute_intercept_slope(param_1,&local_58,&local_88);
  kfree(puVar6);
  puVar6 = (uint *)0x0;
LAB_001043ac:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar6 & 0xffffffff;
}



//------------------------------------------------------------
// calibrate_8916 @ 001043e4 size=700
// signature: undefined calibrate_8916(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_8916(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  undefined8 local_68;
  undefined8 local_60;
  uint local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  local_50 = 0;
  local_48 = 0;
  local_58 = 0;
  local_68 = 0;
  local_60 = 0;
  puVar6 = (uint *)qfprom_read(*param_1,"calib");
  if ((uint *)0xfffffffffffff000 < puVar6) goto LAB_00104668;
  puVar7 = (uint *)qfprom_read(*param_1,"calib_sel");
  if ((uint *)0xfffffffffffff000 < puVar7) {
    kfree(puVar6);
    puVar6 = (uint *)((ulong)puVar7 & 0xffffffff);
    goto LAB_00104668;
  }
  if (*puVar7 >> 0x1d == 3) {
    local_68 = CONCAT44(*puVar6 >> 0x16,*puVar6 >> 0xc) & 0x1f0000001f;
    local_60 = CONCAT44(puVar6[1] >> 10,puVar6[1]) & 0x1f0000001f;
    local_58 = puVar6[1] >> 0x14 & 0x1f;
    iVar8 = *(int *)(param_1 + 1);
    if (iVar8 != 0) {
      uVar3 = puVar6[1] >> 0x19;
      iVar2 = ((*puVar6 >> 0xc & 0x1f) + uVar3) * 8;
      local_68 = CONCAT44(local_68._4_4_,iVar2);
      if ((iVar8 != 1) &&
         (local_68 = CONCAT44(((*puVar6 >> 0x16 & 0x1f) + uVar3) * 8,iVar2), iVar8 != 2)) {
        iVar2 = ((puVar6[1] & 0x1f) + uVar3) * 8;
        local_60 = CONCAT44(local_60._4_4_,iVar2);
        if ((iVar8 != 3) &&
           ((local_60 = CONCAT44(((puVar6[1] >> 10 & 0x1f) + uVar3) * 8,iVar2), iVar8 != 4 &&
            (local_58 = (local_58 + uVar3) * 8, iVar8 != 5)))) goto LAB_0010469c;
      }
    }
LAB_00104530:
    uVar3 = *puVar6 >> 7;
    local_50 = CONCAT44(*puVar6 >> 0x11,uVar3) & 0x1f0000001f;
    local_48 = CONCAT44(puVar6[1] >> 5,*puVar6 >> 0x1b) & 0x1fffffffff;
    local_40 = puVar6[1] >> 0xf & 0x1f;
    if (iVar8 != 0) {
      uVar1 = *puVar6 & 0x7f;
      iVar2 = ((uVar3 & 0x1f) + uVar1) * 8;
      local_50 = CONCAT44(local_50._4_4_,iVar2);
      if ((iVar8 != 1) &&
         (local_50 = CONCAT44(((*puVar6 >> 0x11 & 0x1f) + uVar1) * 8,iVar2), iVar8 != 2)) {
        iVar2 = ((*puVar6 >> 0x1b) + uVar1) * 8;
        local_48 = CONCAT44(local_48._4_4_,iVar2);
        if ((iVar8 != 3) &&
           (local_48 = CONCAT44(((puVar6[1] >> 5 & 0x1f) + uVar1) * 8,iVar2), iVar8 != 4)) {
          local_40 = (local_40 + uVar1) * 8;
          goto joined_r0x001045d4;
        }
      }
    }
  }
  else {
    if (*puVar7 >> 0x1d == 2) {
      iVar8 = *(int *)(param_1 + 1);
      goto LAB_00104530;
    }
    iVar8 = *(int *)(param_1 + 1);
    if (iVar8 != 0) {
      local_50 = CONCAT44(local_50._4_4_,500);
      local_68 = CONCAT44(local_68._4_4_,0x30c);
      if (iVar8 == 1) goto LAB_00104644;
      local_50 = 0x1f4000001f4;
      local_68 = 0x30c0000030c;
      if (iVar8 == 2) goto LAB_00104644;
      local_48 = CONCAT44(local_48._4_4_,500);
      local_60 = CONCAT44(local_60._4_4_,0x30c);
      if (iVar8 == 3) goto LAB_00104644;
      local_48 = 0x1f4000001f4;
      local_60 = 0x30c0000030c;
      if (iVar8 == 4) goto LAB_00104644;
      local_40 = 500;
      local_58 = 0x30c;
joined_r0x001045d4:
      if (iVar8 != 5) {
LAB_0010469c:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1046a0);
        (*pcVar5)();
      }
    }
  }
LAB_00104644:
  compute_intercept_slope(param_1,&local_50,&local_68);
  kfree(puVar6);
  kfree(puVar7);
  puVar6 = (uint *)0x0;
LAB_00104668:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar6 & 0xffffffff;
}



//------------------------------------------------------------
// calibrate_8939 @ 001046a4 size=908
// signature: undefined calibrate_8939(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_8939(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  code *pcVar9;
  uint *puVar10;
  int iVar11;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar8 = sp_el0;
  local_28 = *(long *)(lVar8 + 0x638);
  local_38 = 0;
  local_30 = 0;
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  local_70 = 0;
  puVar10 = (uint *)qfprom_read(*param_1,"calib");
  if ((uint *)0xfffffffffffff000 < puVar10) goto LAB_001049fc;
  uVar3 = puVar10[0xc];
  uVar5 = puVar10[0xd];
  uVar4 = *puVar10;
  uVar6 = puVar10[1];
  if ((uVar3 & 7) == 3) {
    iVar11 = *(int *)(param_1 + 1);
    local_78 = CONCAT44(uVar3 >> 0x15,uVar3 >> 9) & 0x3f0000003f;
    local_70 = CONCAT44(uVar5 >> 0xd,uVar5 >> 1) & 0x3f0000003f;
    local_68 = CONCAT44(uVar4 >> 0xe,uVar5 >> 0x19) & 0x3f0000003f;
    local_60 = CONCAT44(uVar6 >> 6,uVar4 >> 0x1a) & 0x3fffffffff;
    local_58 = CONCAT44(local_58._4_4_,uVar6 >> 0x12) & 0xffffffff0000003f;
    if (iVar11 != 0) {
      uVar2 = uVar6 >> 0x18;
      iVar7 = ((uVar3 >> 9 & 0x3f) + uVar2) * 4;
      local_78 = CONCAT44(local_78._4_4_,iVar7);
      if ((iVar11 != 1) &&
         (local_78 = CONCAT44(((uVar3 >> 0x15 & 0x3f) + uVar2) * 4,iVar7), iVar11 != 2)) {
        iVar7 = ((uVar5 >> 1 & 0x3f) + uVar2) * 4;
        local_70 = CONCAT44(local_70._4_4_,iVar7);
        if ((iVar11 != 3) &&
           (local_70 = CONCAT44(((uVar5 >> 0xd & 0x3f) + uVar2) * 4,iVar7), iVar11 != 4)) {
          iVar7 = ((uVar5 >> 0x19 & 0x3f) + uVar2) * 4;
          local_68 = CONCAT44(local_68._4_4_,iVar7);
          if ((iVar11 != 5) &&
             (local_68 = CONCAT44(((uVar4 >> 0xe & 0x3f) + uVar2) * 4,iVar7), iVar11 != 6)) {
            iVar7 = ((uVar4 >> 0x1a) + uVar2) * 4;
            local_60 = CONCAT44(local_60._4_4_,iVar7);
            if ((iVar11 != 7) &&
               (local_60 = CONCAT44(((uVar6 >> 6 & 0x3f) + uVar2) * 4,iVar7), iVar11 != 8)) {
              iVar7 = ((uVar6 >> 0x12 & 0x3f) + uVar2) * 4;
              local_58 = CONCAT44(local_58._4_4_,iVar7);
              if ((iVar11 != 9) && (local_58 = CONCAT44(uVar2 << 2,iVar7), iVar11 != 10))
              goto LAB_00104a2c;
            }
          }
        }
      }
    }
LAB_00104824:
    uVar2 = uVar3 >> 0x1b | (uVar5 & 1) << 5;
    local_50 = CONCAT44(uVar3 >> 0xf,uVar3 >> 3) & 0x3f0000003f;
    local_48 = CONCAT44(uVar5 >> 7,uVar2) & 0x3fffffffff;
    local_40 = CONCAT44(uVar4 >> 8,uVar5 >> 0x13) & 0x3f0000003f;
    local_38 = CONCAT44(uVar6,uVar4 >> 0x14) & 0x3f0000003f;
    local_30 = CONCAT44(local_30._4_4_,uVar6 >> 0xc) & 0xffffffff0000003f;
    if (iVar11 != 0) {
      uVar1 = uVar4 & 0xff;
      iVar7 = ((uVar3 >> 3 & 0x3f) + uVar1) * 4;
      local_50 = CONCAT44(local_50._4_4_,iVar7);
      if ((iVar11 != 1) &&
         (local_50 = CONCAT44(((uVar3 >> 0xf & 0x3f) + uVar1) * 4,iVar7), iVar11 != 2)) {
        iVar7 = (uVar2 + uVar1) * 4;
        local_48 = CONCAT44(local_48._4_4_,iVar7);
        if ((iVar11 != 3) &&
           (local_48 = CONCAT44(((uVar5 >> 7 & 0x3f) + uVar1) * 4,iVar7), iVar11 != 4)) {
          iVar7 = ((uVar5 >> 0x13 & 0x3f) + uVar1) * 4;
          local_40 = CONCAT44(local_40._4_4_,iVar7);
          if ((iVar11 != 5) &&
             (local_40 = CONCAT44(((uVar4 >> 8 & 0x3f) + uVar1) * 4,iVar7), iVar11 != 6)) {
            iVar7 = ((uVar4 >> 0x14 & 0x3f) + uVar1) * 4;
            local_38 = CONCAT44(local_38._4_4_,iVar7);
            if ((iVar11 != 7) &&
               (local_38 = CONCAT44(((uVar6 & 0x3f) + uVar1) * 4,iVar7), iVar11 != 8)) {
              iVar7 = ((uVar6 >> 0xc & 0x3f) + uVar1) * 4;
              local_30 = CONCAT44(local_30._4_4_,iVar7);
              if (iVar11 != 9) {
                local_30 = CONCAT44(uVar1 << 2,iVar7);
                goto joined_r0x00104928;
              }
            }
          }
        }
      }
    }
  }
  else {
    if ((uVar3 & 7) == 2) {
      iVar11 = *(int *)(param_1 + 1);
      goto LAB_00104824;
    }
    iVar11 = *(int *)(param_1 + 1);
    if (iVar11 != 0) {
      local_50 = CONCAT44(local_50._4_4_,500);
      local_78 = CONCAT44(local_78._4_4_,0x30c);
      if (iVar11 == 1) goto LAB_001049e0;
      local_50 = 0x1f4000001f4;
      local_78 = 0x30c0000030c;
      if (iVar11 == 2) goto LAB_001049e0;
      local_48 = CONCAT44(local_48._4_4_,500);
      local_70 = CONCAT44(local_70._4_4_,0x30c);
      if (iVar11 == 3) goto LAB_001049e0;
      local_48 = 0x1f4000001f4;
      local_70 = 0x30c0000030c;
      if (iVar11 == 4) goto LAB_001049e0;
      local_40 = CONCAT44(local_40._4_4_,500);
      local_68 = CONCAT44(local_68._4_4_,0x30c);
      if (iVar11 == 5) goto LAB_001049e0;
      local_40 = 0x1f4000001f4;
      local_68 = 0x30c0000030c;
      if (iVar11 == 6) goto LAB_001049e0;
      local_38 = CONCAT44(local_38._4_4_,500);
      local_60 = CONCAT44(local_60._4_4_,0x30c);
      if (iVar11 == 7) goto LAB_001049e0;
      local_38 = 0x1f4000001f4;
      local_60 = 0x30c0000030c;
      if (iVar11 == 8) goto LAB_001049e0;
      local_30 = CONCAT44(local_30._4_4_,500);
      local_58 = CONCAT44(local_58._4_4_,0x30c);
      if (iVar11 == 9) goto LAB_001049e0;
      local_30 = 0x1f4000001f4;
      local_58 = 0x30c0000030c;
joined_r0x00104928:
      if (iVar11 != 10) {
LAB_00104a2c:
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x104a30);
        (*pcVar9)();
      }
    }
  }
LAB_001049e0:
  compute_intercept_slope(param_1,&local_50,&local_78);
  kfree(puVar10);
  puVar10 = (uint *)0x0;
LAB_001049fc:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar10 & 0xffffffff;
}



//------------------------------------------------------------
// calibrate_8974 @ 00104a34 size=1984
// signature: undefined calibrate_8974(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_8974(undefined8 *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  code *pcVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  long lVar16;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  uint local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  uint local_40;
  long local_38;
  
  lVar16 = sp_el0;
  local_38 = *(long *)(lVar16 + 0x638);
  local_40 = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  local_68 = 0;
  local_70 = 0;
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_98 = 0;
  puVar8 = (uint *)qfprom_read(*param_1,"calib");
  if ((uint *)0xfffffffffffff000 < puVar8) goto LAB_001051bc;
  puVar9 = (uint *)qfprom_read(*param_1,"calib_backup");
  if ((uint *)0xfffffffffffff000 < puVar9) {
    kfree(puVar8);
    puVar8 = (uint *)((ulong)puVar9 & 0xffffffff);
    goto LAB_001051bc;
  }
  if (puVar9[1] >> 0x1d == 3) {
    uVar13 = 0;
    uVar10 = puVar8[5] >> 0x1c & 4 | puVar8[4] >> 0x1e;
    if (uVar10 - 1 < 2) {
LAB_00104b84:
      uVar11 = *puVar9;
      lVar16 = 0xc;
      local_68 = CONCAT44(*puVar9 >> 0xe,uVar11 >> 8);
      local_60 = CONCAT44(*puVar9 >> 0x1a,*puVar9 >> 0x14);
      local_58 = CONCAT44(puVar9[1] >> 6,puVar9[1]);
      local_50 = CONCAT44(puVar9[1] >> 0x12,puVar9[1] >> 0xc);
      uVar2 = 0;
      puVar14 = puVar9 + 2;
      uVar15 = *puVar14 >> 6;
      goto LAB_00104d24;
    }
    if (uVar10 == 3) {
      uVar13 = puVar9[2] >> 0x12 & 0x3f;
      local_98 = CONCAT44(puVar9[3],puVar9[2] >> 0x1a) & 0x3fffffffff;
      local_90 = CONCAT44(puVar9[3] >> 0xc,puVar9[3] >> 6) & 0x3f0000003f;
      local_88 = (ulong)CONCAT14(*(undefined1 *)((long)puVar8 + 0x13),puVar9[3] >> 0x12) &
                 0x3f0000003f;
      local_80 = CONCAT44(puVar8[5] >> 6,puVar8[5]) & 0x3f0000003f;
      local_78 = CONCAT44(puVar8[5] >> 0x12,puVar8[5] >> 0xc) & 0x3f0000003f;
      local_70 = *(byte *)((long)puVar8 + 0x17) & 0x3f;
      goto LAB_00104b84;
    }
LAB_00104dbc:
    uVar11 = 0;
    uVar13 = 0;
    if (uVar10 == 1) goto LAB_00104dc8;
LAB_00104d4c:
    if (uVar10 == 2) {
      iVar12 = *(int *)(param_1 + 1);
      if ((iVar12 != 0) &&
         (local_68 = CONCAT44(local_68._4_4_,((int)local_68 + uVar11) * 4) | 3, iVar12 != 1)) {
LAB_00105094:
        local_68 = CONCAT44((local_68._4_4_ + uVar11) * 4,(int)local_68) | 0x300000000;
        if (iVar12 != 2) {
          iVar1 = local_60._4_4_;
          local_60 = CONCAT44(local_60._4_4_,((int)local_60 + uVar11) * 4) | 3;
          if (iVar12 != 3) {
            local_60 = CONCAT44((iVar1 + uVar11) * 4,(int)local_60) | 0x300000000;
            if (iVar12 != 4) {
              iVar1 = local_58._4_4_;
              local_58 = CONCAT44(local_58._4_4_,((int)local_58 + uVar11) * 4) | 3;
              if (iVar12 != 5) {
                local_58 = CONCAT44((iVar1 + uVar11) * 4,(int)local_58) | 0x300000000;
                if (iVar12 != 6) {
                  iVar1 = local_50._4_4_;
                  local_50 = CONCAT44(local_50._4_4_,((int)local_50 + uVar11) * 4) | 3;
                  if (iVar12 != 7) {
                    local_50 = CONCAT44((iVar1 + uVar11) * 4,(int)local_50) | 0x300000000;
                    if (iVar12 != 8) {
                      iVar1 = local_48._4_4_;
                      local_48 = CONCAT44(local_48._4_4_,((int)local_48 + uVar11) * 4) | 3;
                      if (iVar12 != 9) {
                        local_48 = CONCAT44((iVar1 + uVar11) * 4,(int)local_48) | 0x300000000;
                        if (iVar12 != 10) {
                          local_40 = (local_40 + uVar11) * 4 | 3;
                          goto LAB_0010518c;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar1 = local_98._4_4_;
      iVar3 = local_90._4_4_;
      iVar4 = local_88._4_4_;
      iVar5 = local_80._4_4_;
      iVar6 = local_78._4_4_;
      if (uVar10 == 3) {
        iVar12 = *(int *)(param_1 + 1);
        if (iVar12 != 0) {
          local_98 = CONCAT44(local_98._4_4_,((int)local_98 + uVar13) * 4) | 3;
          if (iVar12 != 1) {
            local_98 = CONCAT44((iVar1 + uVar13) * 4,(int)local_98) | 0x300000000;
            if (iVar12 != 2) {
              local_90 = CONCAT44(local_90._4_4_,((int)local_90 + uVar13) * 4) | 3;
              if (iVar12 != 3) {
                local_90 = CONCAT44((iVar3 + uVar13) * 4,(int)local_90) | 0x300000000;
                if (iVar12 != 4) {
                  local_88 = CONCAT44(local_88._4_4_,((int)local_88 + uVar13) * 4) | 3;
                  if (iVar12 != 5) {
                    local_88 = CONCAT44((iVar4 + uVar13) * 4,(int)local_88) | 0x300000000;
                    if (iVar12 != 6) {
                      local_80 = CONCAT44(local_80._4_4_,((int)local_80 + uVar13) * 4) | 3;
                      if (iVar12 != 7) {
                        local_80 = CONCAT44((iVar5 + uVar13) * 4,(int)local_80) | 0x300000000;
                        if (iVar12 != 8) {
                          local_78 = CONCAT44(local_78._4_4_,((int)local_78 + uVar13) * 4) | 3;
                          if (iVar12 != 9) {
                            local_78 = CONCAT44((iVar6 + uVar13) * 4,(int)local_78) | 0x300000000;
                            if ((iVar12 != 10) &&
                               (local_70 = (local_70 + uVar13) * 4 | 3, iVar12 != 0xb))
                            goto LAB_001051f0;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            local_68 = CONCAT44(local_68._4_4_,((int)local_68 + uVar11) * 4) | 3;
            goto LAB_00105094;
          }
          local_68 = CONCAT44(local_68._4_4_,((int)local_68 + uVar11) * 4) | 3;
        }
      }
      else {
        iVar12 = *(int *)(param_1 + 1);
        if ((((((iVar12 != 0) && (local_98 = CONCAT44(local_98._4_4_,0x30c), iVar12 != 1)) &&
              (local_98 = 0x30c0000030c, iVar12 != 2)) &&
             (((local_90 = CONCAT44(local_90._4_4_,0x30c), iVar12 != 3 &&
               (local_90 = 0x30c0000030c, iVar12 != 4)) &&
              ((local_88 = CONCAT44(local_88._4_4_,0x30c), iVar12 != 5 &&
               ((local_88 = 0x30c0000030c, iVar12 != 6 &&
                (local_80 = CONCAT44(local_80._4_4_,0x30c), iVar12 != 7)))))))) &&
            (local_80 = 0x30c0000030c, iVar12 != 8)) &&
           (((local_78 = CONCAT44(local_78._4_4_,0x30c), iVar12 != 9 &&
             (local_78 = 0x30c0000030c, iVar12 != 10)) && (local_70 = 0x30c, iVar12 != 0xb))))
        goto LAB_001051f0;
        local_68 = 0x1fd000001f6;
        local_60 = 0x1fd000001f7;
        local_58 = 0x1fd000001f9;
        local_50 = 0x1fe000001fb;
        local_48 = 0x1fd000001fc;
        local_40 = 0x1fc;
      }
    }
  }
  else {
    uVar13 = 0;
    uVar10 = puVar8[3] >> 0x1c & 4 | puVar8[1] >> 0x1e;
    if (1 < uVar10 - 1) {
      if (uVar10 != 3) goto LAB_00104dbc;
      uVar13 = puVar8[2] >> 0xc & 0xff;
      local_98 = CONCAT44(puVar8[2] >> 0x1a,puVar8[2] >> 0x14) & 0xffffffff0000003f;
      local_90 = CONCAT44(puVar8[3] >> 6,puVar8[3]) & 0x3f0000003f;
      local_88 = CONCAT44(puVar8[3] >> 0x12,puVar8[3] >> 0xc) & 0x3f0000003f;
      local_80 = CONCAT44(puVar8[4],(uint)*(byte *)((long)puVar8 + 0xf)) & 0x3f0000003f;
      local_78 = CONCAT44(puVar8[4] >> 0xc,puVar8[4] >> 6) & 0x3f0000003f;
      local_70 = puVar8[4] >> 0x12 & 0x3f;
    }
    uVar11 = *puVar8;
    lVar16 = 6;
    local_68 = CONCAT44(*puVar8 >> 0xe,uVar11 >> 8);
    local_60 = CONCAT44(*puVar8 >> 0x1a,*puVar8 >> 0x14);
    local_58 = CONCAT44(puVar8[1] >> 6,puVar8[1]);
    local_50 = CONCAT44(puVar8[1] >> 0x12,puVar8[1] >> 0xc);
    uVar2 = *(byte *)((long)puVar8 + 7) & 0x3f;
    puVar14 = puVar8 + 2;
    uVar15 = *puVar14;
LAB_00104d24:
    local_50 = local_50 & 0x3f0000003f;
    local_58 = local_58 & 0x3f0000003f;
    local_60 = local_60 & 0xffffffff0000003f;
    local_68 = local_68 & 0x3f0000003f;
    local_48 = CONCAT44(uVar15,uVar2) & 0x3fffffffff;
    local_40 = *puVar14 >> lVar16 & 0x3f;
    uVar11 = uVar11 & 0xff;
    if (uVar10 != 1) goto LAB_00104d4c;
LAB_00104dc8:
    iVar12 = *(int *)(param_1 + 1);
    if (iVar12 != 0) {
      uVar10 = uVar11 << 2 | 3;
      iVar1 = uVar10 + (int)local_68;
      local_68 = CONCAT44(local_68._4_4_,iVar1);
      if ((iVar12 == 1) || (local_68 = CONCAT44(uVar10 + local_68._4_4_,iVar1), iVar12 == 2))
      goto LAB_00105198;
      iVar1 = uVar10 + (int)local_60;
      local_60 = CONCAT44(local_60._4_4_,iVar1);
      if ((iVar12 == 3) || (local_60 = CONCAT44(uVar10 + local_60._4_4_,iVar1), iVar12 == 4))
      goto LAB_00105198;
      iVar1 = uVar10 + (int)local_58;
      local_58 = CONCAT44(local_58._4_4_,iVar1);
      if ((iVar12 == 5) || (local_58 = CONCAT44(uVar10 + local_58._4_4_,iVar1), iVar12 == 6))
      goto LAB_00105198;
      iVar1 = uVar10 + (int)local_50;
      local_50 = CONCAT44(local_50._4_4_,iVar1);
      if ((iVar12 == 7) || (local_50 = CONCAT44(uVar10 + local_50._4_4_,iVar1), iVar12 == 8))
      goto LAB_00105198;
      iVar1 = uVar10 + (int)local_48;
      local_48 = CONCAT44(local_48._4_4_,iVar1);
      if ((iVar12 == 9) || (local_48 = CONCAT44(uVar10 + local_48._4_4_,iVar1), iVar12 == 10))
      goto LAB_00105198;
      local_40 = uVar10 + local_40;
LAB_0010518c:
      if (iVar12 != 0xb) {
LAB_001051f0:
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x1051f4);
        (*pcVar7)();
      }
    }
  }
LAB_00105198:
  compute_intercept_slope(param_1,&local_68,&local_98);
  kfree(puVar8);
  kfree(puVar9);
  puVar8 = (uint *)0x0;
LAB_001051bc:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar8 & 0xffffffff;
}



//------------------------------------------------------------
// calibrate_9607 @ 001051f8 size=640
// signature: undefined calibrate_9607(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_9607(undefined8 *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  uint *puVar6;
  int iVar7;
  undefined8 local_58;
  undefined8 local_50;
  uint local_48;
  undefined8 local_40;
  undefined8 local_38;
  uint local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  local_40 = 0;
  local_38 = 0;
  local_48 = 0;
  local_58 = 0;
  local_50 = 0;
  puVar6 = (uint *)qfprom_read(*param_1,"calib");
  if ((uint *)0xfffffffffffff000 < puVar6) goto LAB_00105444;
  uVar3 = puVar6[2] >> 0x14 & 7;
  if (uVar3 == 3) {
    local_58 = CONCAT44(*puVar6 >> 0x1a,*puVar6 >> 0xe) & 0xffffffff0000003f;
    local_50 = CONCAT44(puVar6[1] >> 0x12,puVar6[1] >> 6) & 0x3f0000003f;
    local_48 = puVar6[2] >> 6 & 0x3f;
    iVar7 = *(int *)(param_1 + 1);
    if (iVar7 != 0) {
      uVar3 = puVar6[2] >> 0xc & 0xff;
      iVar2 = ((*puVar6 >> 0xe & 0x3f) + uVar3) * 4;
      local_58 = CONCAT44(local_58._4_4_,iVar2);
      if ((iVar7 != 1) && (local_58 = CONCAT44(((*puVar6 >> 0x1a) + uVar3) * 4,iVar2), iVar7 != 2))
      {
        iVar2 = ((puVar6[1] >> 6 & 0x3f) + uVar3) * 4;
        local_50 = CONCAT44(local_50._4_4_,iVar2);
        if ((iVar7 != 3) &&
           ((local_50 = CONCAT44(((puVar6[1] >> 0x12 & 0x3f) + uVar3) * 4,iVar2), iVar7 != 4 &&
            (local_48 = (local_48 + uVar3) * 4, iVar7 != 5)))) goto LAB_00105474;
      }
    }
LAB_00105314:
    uVar3 = *puVar6 >> 8;
    local_40 = CONCAT44(*puVar6 >> 0x14,uVar3) & 0x3f0000003f;
    local_38 = CONCAT44(puVar6[1] >> 0xc,puVar6[1]) & 0x3f0000003f;
    local_30 = puVar6[2] & 0x3f;
    if (iVar7 != 0) {
      uVar1 = *puVar6 & 0xff;
      iVar2 = ((uVar3 & 0x3f) + uVar1) * 4;
      local_40 = CONCAT44(local_40._4_4_,iVar2);
      if ((iVar7 != 1) &&
         (local_40 = CONCAT44(((*puVar6 >> 0x14 & 0x3f) + uVar1) * 4,iVar2), iVar7 != 2)) {
        iVar2 = ((puVar6[1] & 0x3f) + uVar1) * 4;
        local_38 = CONCAT44(local_38._4_4_,iVar2);
        if ((iVar7 != 3) &&
           (local_38 = CONCAT44(((puVar6[1] >> 0xc & 0x3f) + uVar1) * 4,iVar2), iVar7 != 4)) {
          local_30 = (local_30 + uVar1) * 4;
          goto joined_r0x001053b8;
        }
      }
    }
  }
  else {
    if (uVar3 == 2) {
      iVar7 = *(int *)(param_1 + 1);
      goto LAB_00105314;
    }
    iVar7 = *(int *)(param_1 + 1);
    if (iVar7 != 0) {
      local_40 = CONCAT44(local_40._4_4_,500);
      local_58 = CONCAT44(local_58._4_4_,0x30c);
      if (iVar7 == 1) goto LAB_00105428;
      local_40 = 0x1f4000001f4;
      local_58 = 0x30c0000030c;
      if (iVar7 == 2) goto LAB_00105428;
      local_38 = CONCAT44(local_38._4_4_,500);
      local_50 = CONCAT44(local_50._4_4_,0x30c);
      if (iVar7 == 3) goto LAB_00105428;
      local_38 = 0x1f4000001f4;
      local_50 = 0x30c0000030c;
      if (iVar7 == 4) goto LAB_00105428;
      local_30 = 500;
      local_48 = 0x30c;
joined_r0x001053b8:
      if (iVar7 != 5) {
LAB_00105474:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x105478);
        (*pcVar5)();
      }
    }
  }
LAB_00105428:
  compute_intercept_slope(param_1,&local_40,&local_58);
  kfree(puVar6);
  puVar6 = (uint *)0x0;
LAB_00105444:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar6 & 0xffffffff;
}



//------------------------------------------------------------
// calibrate_8960 @ 0010547c size=456
// signature: undefined calibrate_8960(void)
// callers: []
//------------------------------------------------------------

ulong calibrate_8960(undefined8 *param_1)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  long lVar4;
  code *pcVar5;
  byte *pbVar6;
  ulong local_58;
  ulong local_50;
  ulong local_48;
  ulong local_40;
  ulong local_38;
  uint local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  local_40 = 0;
  local_38 = 0;
  local_50 = 0;
  local_48 = 0;
  local_58 = 0;
  pbVar6 = (byte *)qfprom_read(*param_1,"calib");
  if ((byte *)0xfffffffffffff000 < pbVar6) {
    pbVar6 = (byte *)qfprom_read(*param_1,"calib_backup");
  }
  if (pbVar6 < (byte *)0xfffffffffffff001) {
    iVar1 = *(int *)(param_1 + 1);
    if (iVar1 != 0) {
      bVar2 = *pbVar6;
      local_58 = CONCAT44(local_58._4_4_,(uint)bVar2);
      *(undefined4 *)(param_1 + 0x156) = 0x33a;
      if (iVar1 != 1) {
        bVar3 = pbVar6[1];
        *(undefined4 *)(param_1 + 0x15b) = 0x33a;
        local_58 = (ulong)CONCAT14(bVar3,(uint)bVar2);
        if (iVar1 != 2) {
          bVar2 = pbVar6[2];
          local_50 = CONCAT44(local_50._4_4_,(uint)bVar2);
          *(undefined4 *)(param_1 + 0x160) = 0x324;
          if (iVar1 != 3) {
            local_50 = (ulong)CONCAT14(pbVar6[3],(uint)bVar2);
            *(undefined4 *)(param_1 + 0x165) = 0x33a;
            if (iVar1 != 4) {
              bVar2 = pbVar6[4];
              local_48 = CONCAT44(local_48._4_4_,(uint)bVar2);
              *(undefined4 *)(param_1 + 0x16a) = 0x2f9;
              if (iVar1 != 5) {
                local_48 = (ulong)CONCAT14(pbVar6[5],(uint)bVar2);
                *(undefined4 *)(param_1 + 0x16f) = 0x30e;
                if (iVar1 != 6) {
                  bVar2 = pbVar6[6];
                  *(undefined4 *)(param_1 + 0x174) = 0x30e;
                  local_40 = CONCAT44(local_40._4_4_,(uint)bVar2);
                  if (iVar1 != 7) {
                    local_40 = (ulong)CONCAT14(pbVar6[7],(uint)bVar2);
                    *(undefined4 *)(param_1 + 0x179) = 0x351;
                    if (iVar1 != 8) {
                      bVar2 = pbVar6[8];
                      local_38 = CONCAT44(local_38._4_4_,(uint)bVar2);
                      *(undefined4 *)(param_1 + 0x17e) = 0x30e;
                      if (iVar1 != 9) {
                        local_38 = (ulong)CONCAT14(pbVar6[9],(uint)bVar2);
                        *(undefined4 *)(param_1 + 0x183) = 0x351;
                        if (iVar1 != 10) {
                          local_30 = (uint)pbVar6[10];
                          *(undefined4 *)(param_1 + 0x188) = 0x30e;
                          if (iVar1 != 0xb) {
                    /* WARNING: Does not return */
                            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x105644);
                            (*pcVar5)();
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    compute_intercept_slope(param_1,&local_58,0,1);
    kfree(pbVar6);
    pbVar6 = (byte *)0x0;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)pbVar6 & 0xffffffff;
}



//------------------------------------------------------------
// enable_8960 @ 00105648 size=232
// signature: undefined enable_8960(void)
// callers: []
//------------------------------------------------------------

void enable_8960(long param_1,ulong param_2)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  uVar4 = regmap_read(*(undefined8 *)(param_1 + 0x10),0x3620,&local_2c);
  if ((int)uVar4 == 0) {
    uVar1 = 0x3e00;
    if ((int)param_2 < 6) {
      uVar1 = (int)(1L << (param_2 & 0x3f)) << 3;
    }
    if ((uVar1 & (local_2c ^ 0xffffffff)) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = regmap_write(*(undefined8 *)(param_1 + 0x10),0x3620,local_2c | 2);
      if ((int)uVar4 == 0) {
        uVar2 = 0x4000001;
        if (*(uint *)(param_1 + 8) < 2) {
          uVar2 = 0x1000001;
        }
        local_2c = local_2c | uVar2 | uVar1 | 0x40000;
        uVar4 = regmap_write(*(undefined8 *)(param_1 + 0x10),0x3620);
      }
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// disable_8960 @ 00105734 size=184
// signature: undefined disable_8960(void)
// callers: []
//------------------------------------------------------------

void disable_8960(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  iVar2 = *(int *)(param_1 + 8);
  local_2c = 0;
  iVar4 = regmap_read(*(undefined8 *)(param_1 + 0x10),0x3620,&local_2c);
  if (iVar4 == 0) {
    uVar1 = 0xfbfffffe;
    if (*(uint *)(param_1 + 8) < 2) {
      uVar1 = 0xfefffffe;
    }
    local_2c = uVar1 & local_2c &
               ((int)(0xffffffffffffffff >> ((ulong)(uint)-iVar2 & 0x3f)) << 3 ^ 0xfffffffeU);
    regmap_write(*(undefined8 *)(param_1 + 0x10),0x3620);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// suspend_8960 @ 001057f0 size=136
// signature: undefined suspend_8960(void)
// callers: []
//------------------------------------------------------------

void suspend_8960(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + 0x10);
  iVar2 = regmap_read(uVar3,0x3624,param_1 + 0xa30);
  if ((iVar2 == 0) && (iVar2 = regmap_read(uVar3,0x3620,param_1 + 0xa34), iVar2 == 0)) {
    uVar1 = 0x4000001;
    if (*(uint *)(param_1 + 8) < 2) {
      uVar1 = 0x1000001;
    }
    regmap_update_bits_base(uVar3,0x3620,uVar1,0,0,0,0);
  }
  return;
}



//------------------------------------------------------------
// resume_8960 @ 0010587c size=160
// signature: undefined resume_8960(void)
// callers: []
//------------------------------------------------------------

void resume_8960(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(param_1 + 0x10);
  iVar1 = regmap_update_bits_base(uVar2,0x3620,2,2,0,0,0);
  if ((iVar1 == 0) &&
     (((*(uint *)(param_1 + 8) < 2 ||
       (iVar1 = regmap_update_bits_base(uVar2,0x3640,0xf,0x9b,0,0,0), iVar1 == 0)) &&
      (iVar1 = regmap_write(uVar2,0x3624,*(undefined4 *)(param_1 + 0xa30)), iVar1 == 0)))) {
    regmap_write(uVar2,0x3620,*(undefined4 *)(param_1 + 0xa34));
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00105920 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&tsens_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// init_8956 @ 00105950 size=116
// signature: undefined init_8956(void)
// callers: []
//------------------------------------------------------------

void init_8956(long param_1)

{
  *(undefined4 *)(param_1 + 0xab0) = 0xcf1;
  *(undefined4 *)(param_1 + 0xad8) = 0xccb;
  *(undefined4 *)(param_1 + 0xb00) = 0xcf8;
  *(undefined4 *)(param_1 + 0xb28) = 0xcae;
  *(undefined4 *)(param_1 + 0xb50) = 0xccf;
  *(undefined4 *)(param_1 + 0xb78) = 0xcb9;
  *(undefined4 *)(param_1 + 0xba0) = 0xca2;
  *(undefined4 *)(param_1 + 0xbc8) = 0xcc5;
  *(undefined4 *)(param_1 + 0xbf0) = 0xcb7;
  *(undefined4 *)(param_1 + 0xc18) = 0xca7;
  *(undefined4 *)(param_1 + 0xc40) = 0xcd6;
  init_common();
  return;
}



//------------------------------------------------------------
// init_8939 @ 001059c8 size=100
// signature: undefined init_8939(void)
// callers: []
//------------------------------------------------------------

void init_8939(long param_1)

{
  *(undefined4 *)(param_1 + 0xab0) = 0xb5f;
  *(undefined4 *)(param_1 + 0xad8) = 0xae5;
  *(undefined4 *)(param_1 + 0xb00) = 0xb5a;
  *(undefined4 *)(param_1 + 0xb28) = 0xacb;
  *(undefined4 *)(param_1 + 0xb50) = 0xb6a;
  *(undefined4 *)(param_1 + 0xb78) = 0xb33;
  *(undefined4 *)(param_1 + 0xba0) = 0xb11;
  *(undefined4 *)(param_1 + 0xbc8) = 0xb16;
  *(undefined4 *)(param_1 + 0xbf0) = 0xb18;
  init_common();
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105a30 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&tsens_driver);
  return;
}



//------------------------------------------------------------
// nvmem_cell_get @ 00110000 size=1
// signature: undefined nvmem_cell_get(void)
// callers: [qfprom_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 00110008 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [qfprom_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_put @ 00110010 size=1
// signature: undefined nvmem_cell_put(void)
// callers: [qfprom_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00110018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [dbg_version_show, calibrate_8960, enable_8960, tsens_probe, disable_8960, tsens_irq_thread, calibrate_8939, calibrate_8976, calibrate_8974, calibrate_v1, tsens_hw_to_mC, init_common, tsens_debug_init, tsens_read_irq_state, calibrate_8916, tsens_critical_irq_thread, qti_tz_get_trend, calibrate_9607, init_cold_interrupt, get_temp_common, get_cold_int_status, tsens_set_trips, get_temp_tsens_valid, qfprom_read, tsens_cold_irq_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_field_read @ 00110020 size=1
// signature: undefined regmap_field_read(void)
// callers: [dbg_version_show, get_cold_int_status, get_temp_tsens_valid, tsens_threshold_violated, tsens_hw_to_mC, init_common, tsens_cold_irq_thread, get_temp_common, tsens_read_irq_state, tsens_critical_irq_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_field_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 00110028 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [tsens_probe, tsens_irq_thread, tsens_cold_irq_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00110030 size=1
// signature: undefined ktime_get(void)
// callers: [get_temp_tsens_valid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00110038 size=1
// signature: undefined usleep_range_state(void)
// callers: [get_temp_tsens_valid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_update_data @ 00110040 size=1
// signature: undefined thermal_minidump_update_data(void)
// callers: [get_temp_tsens_valid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_minidump_update_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00110048 size=1
// signature: undefined ipc_log_string(void)
// callers: [tsens_set_trips, tsens_set_interrupt, get_temp_tsens_valid, tsens_probe, tsens_irq_thread, get_temp_common, tsens_read_irq_state, tsens_critical_irq_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_usecs @ 00110058 size=1
// signature: undefined jiffies_to_usecs(void)
// callers: [get_temp_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_usecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00110060 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [tsens_register_irq, init_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource @ 00110068 size=1
// signature: undefined platform_get_resource(void)
// callers: [init_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00110070 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [init_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_mmio_clk @ 00110078 size=1
// signature: undefined __devm_regmap_init_mmio_clk(void)
// callers: [init_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_mmio_clk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// syscon_node_to_regmap @ 00110080 size=1
// signature: undefined syscon_node_to_regmap(void)
// callers: [init_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void syscon_node_to_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_field_alloc @ 00110088 size=1
// signature: undefined devm_regmap_field_alloc(void)
// callers: [init_common, init_cold_interrupt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_field_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_field_update_bits_base @ 00110090 size=1
// signature: undefined regmap_field_update_bits_base(void)
// callers: [tsens_remove, tsens_set_trips, tsens_set_interrupt, tsens_probe, init_common, tsens_reinit, tsens_enable_irq, tsens_critical_irq_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_field_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00110098 size=1
// signature: undefined put_device(void)
// callers: [tsens_register_irq, init_common]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001100a0 size=1
// signature: undefined _dev_err(void)
// callers: [tsens_register_irq, tsens_probe, init_common, tsens_irq_thread, tsens_reinit, tsens_debug_init, tsens_enable_irq, tsens_critical_irq_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_lookup @ 001100a8 size=1
// signature: undefined debugfs_lookup(void)
// callers: [tsens_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001100b0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [tsens_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001100b8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [tsens_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001100c0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [tsens_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001100c8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [tsens_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 001100d8 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [tsens_v2_tsens_suspend, tsens_v2_tsens_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001100e0 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [tsens_register_irq, tsens_v2_tsens_suspend, tsens_v2_tsens_restore, tsens_v2_tsens_resume, tsens_v2_tsens_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 001100e8 size=1
// signature: undefined enable_irq(void)
// callers: [tsens_v2_tsens_restore, tsens_v2_tsens_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001100f0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [tsens_set_trips, tsens_irq_thread, tsens_reinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001100f8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [tsens_set_trips, tsens_irq_thread, tsens_reinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00110100 size=1
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
// platform_driver_unregister @ 00110108 size=1
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
// single_open @ 00110110 size=1
// signature: undefined single_open(void)
// callers: [dbg_sensors_open, dbg_version_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00110118 size=1
// signature: undefined seq_printf(void)
// callers: [dbg_version_show, dbg_sensors_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00110120 size=1
// signature: undefined seq_puts(void)
// callers: [dbg_version_show, dbg_sensors_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 00110128 size=1
// signature: undefined of_match_node(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00110130 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00110138 size=1
// signature: undefined devm_kmalloc(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_register @ 00110140 size=1
// signature: undefined thermal_minidump_register(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_minidump_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00110148 size=1
// signature: undefined of_find_property(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read_variable_le_u32 @ 00110150 size=1
// signature: undefined nvmem_cell_read_variable_le_u32(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read_variable_le_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00110158 size=1
// signature: undefined mutex_unlock(void)
// callers: [tsens_remove, tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 00110160 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00110168 size=1
// signature: undefined strnstr(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_thermal_get_ntrips @ 00110170 size=1
// signature: undefined of_thermal_get_ntrips(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_thermal_get_ntrips(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00110178 size=1
// signature: undefined mutex_lock(void)
// callers: [tsens_remove, tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_thermal_is_trip_valid @ 00110180 size=1
// signature: undefined of_thermal_is_trip_valid(void)
// callers: [tsens_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_thermal_is_trip_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00110188 size=1
// signature: undefined debugfs_remove(void)
// callers: [tsens_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_unregister @ 00110190 size=1
// signature: undefined thermal_minidump_unregister(void)
// callers: [tsens_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_minidump_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00110198 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [tsens_register_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001101a0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [tsens_register_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cdev_update @ 001101a8 size=1
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
// kfree @ 001101c8 size=1
// signature: undefined kfree(void)
// callers: [calibrate_v1, calibrate_8960, calibrate_9607, calibrate_8939, calibrate_8976, calibrate_8916, calibrate_8974]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 001101d0 size=1
// signature: undefined regmap_read(void)
// callers: [suspend_8960, enable_8960, disable_8960]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001101d8 size=1
// signature: undefined regmap_write(void)
// callers: [enable_8960, disable_8960, resume_8960]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001101e0 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [suspend_8960, resume_8960]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



