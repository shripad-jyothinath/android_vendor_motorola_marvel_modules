// Decompiled by Ghidra 12.2
// Program: qcom-spmi-adc5-gen3.ko
// Image base: 00100000

//------------------------------------------------------------
// adc_tm_gen3_get_temp @ 00100554 size=236
// signature: undefined adc_tm_gen3_get_temp(void)
// callers: []
//------------------------------------------------------------

int adc_tm_gen3_get_temp(long param_1,undefined4 *param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined2 local_3c [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x3f0);
  local_3c[0] = 0;
  if ((lVar3 == 0) || (*(long *)(lVar3 + 0x38) == 0)) {
    iVar1 = -0x16;
  }
  else if (*(char *)(lVar3 + 0x84) == '\0') {
    iVar1 = adc5_gen3_do_conversion(*(long *)(lVar3 + 0x38),lVar3,local_3c);
    if (-1 < iVar1) {
      iVar1 = qcom_adc5_hw_scale(*(undefined4 *)(lVar3 + 0x28),*(undefined4 *)(lVar3 + 0x10),
                                 *(undefined8 *)(lVar3 + 0x40),local_3c[0],param_2);
      lVar2 = *(long *)(*(long *)(lVar3 + 0x38) + 0xd8);
      if ((lVar2 != 0) && (*(long *)(lVar3 + 0x58) != 0)) {
        thermal_minidump_update_data(lVar2,*(long *)(lVar3 + 0x58) + 4,param_2);
      }
    }
  }
  else {
    iVar1 = 0;
    *(undefined1 *)(lVar3 + 0x84) = 0;
    *param_2 = *(undefined4 *)(lVar3 + 0x80);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// adc5_gen3_do_conversion @ 00100640 size=1008
// signature: undefined adc5_gen3_do_conversion(void)
// callers: [adc5_gen3_read_raw, adc_tm_gen3_get_temp]
//------------------------------------------------------------

int adc5_gen3_do_conversion(undefined8 *param_1,undefined4 *param_2,short *param_3)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  byte local_7c [4];
  undefined1 local_78 [4];
  undefined1 local_74 [4];
  byte local_70;
  undefined1 uStack_6f;
  undefined1 uStack_6e;
  byte local_6d;
  byte bStack_6c;
  undefined1 uStack_6b;
  byte bStack_6a;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  bVar2 = *(byte *)(param_2 + 7);
  local_78[0] = 0;
  iVar1 = param_2[0x12];
  local_7c[0] = 0;
  mutex_lock(param_1 + 0xb);
  iVar3 = adc5_gen3_poll_wait_hs(param_1,0);
  if (iVar3 < 0) goto LAB_001009c0;
  bStack_6c = 0;
  uStack_6b = 0;
  bStack_6a = 0;
  local_70 = 0;
  uStack_6f = 0;
  uStack_6e = 0;
  local_6d = 0;
  uVar8 = (uint)*(byte *)(param_2 + 7);
  if (param_2[0x12] != 0) {
    uVar8 = 0;
  }
  iVar3 = regmap_bulk_read(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) + 0x4f,&local_70,7
                          );
  if (iVar3 < 0) {
    puVar5 = &DAT_00106752;
LAB_00100924:
    uVar6 = 0x4f;
    uVar7 = 7;
  }
  else {
    local_70 = *(byte *)(param_2 + 3) & 0x1f;
    uStack_6f = 0x80;
    uStack_6e = 1;
    local_6d = local_6d & 0xc3 | *(char *)(param_2 + 1) << 4 | *(char *)(param_2 + 2) << 2;
    bStack_6c = bStack_6c & 0x78 | *(byte *)(param_2 + 6) | 0x80;
    bStack_6a = bStack_6a & 0xf0 | *(byte *)(param_2 + 5);
    uStack_6b = (undefined1)*param_2;
    *(undefined4 *)(param_1 + 7) = 0;
    iVar3 = regmap_bulk_write(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) + 0x4f,
                              &local_70,7);
    if (iVar3 < 0) {
      puVar5 = &DAT_0010646b;
      goto LAB_00100924;
    }
    local_74[0] = 1;
    iVar3 = regmap_bulk_write(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) + 0xe5,local_74
                              ,1);
    if (-1 < iVar3) {
      iVar9 = 10;
      do {
        lVar4 = wait_for_completion_timeout(param_1 + 7,0xd);
        if (lVar4 != 0) {
LAB_0010080c:
          jiffies_to_msecs(lVar4);
          uVar8 = (uint)bVar2;
          if (iVar1 != 0) {
            uVar8 = 0;
          }
          local_70 = 0;
          uStack_6f = 0;
          iVar1 = param_2[9];
          iVar3 = regmap_bulk_read(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) + 0x5c,
                                   &local_70,2);
          if (iVar3 < 0) {
            puVar5 = &DAT_00106752;
            uVar6 = 0x5c;
            uVar7 = 2;
          }
          else {
            *param_3 = CONCAT11(uStack_6f,local_70);
            if ((iVar1 == 0) && (CONCAT11(uStack_6f,local_70) == -0x8000)) {
              _printk(&DAT_001068a0,0x8000);
              iVar3 = -0x16;
              goto LAB_001009c0;
            }
            local_78[0] = 1;
            iVar3 = regmap_bulk_write(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) + 0x4b,
                                      local_78,1);
            if (iVar3 < 0) {
              uVar6 = 0x4b;
            }
            else {
              local_78[0] = 0;
              iVar3 = regmap_bulk_write(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) +
                                                 0x50,local_78,1);
              if (iVar3 < 0) {
                uVar6 = 0x50;
              }
              else {
                local_78[0] = 1;
                iVar3 = regmap_bulk_write(*param_1,*(ushort *)(param_1[2] + (ulong)uVar8 * 0x18) +
                                                   0xe5,local_78,1);
                if (-1 < iVar3) goto LAB_001009c0;
                uVar6 = 0xe5;
              }
            }
            puVar5 = &DAT_0010646b;
            uVar7 = 1;
          }
          _printk(puVar5,uVar6,uVar7,iVar3);
          goto LAB_001009c0;
        }
        iVar3 = regmap_bulk_read(*param_1,*(ushort *)param_1[2] + 0x4a,local_7c,1);
        if (iVar3 < 0) {
          _printk(&DAT_00106752,0x4a,1,iVar3);
          puVar5 = &DAT_00106816;
          goto LAB_00100954;
        }
        if ((local_7c[0] & 1) != 0) goto LAB_0010080c;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      _printk(&DAT_00106611,*(undefined8 *)(param_2 + 0xc));
      iVar3 = -0x6e;
      goto LAB_001009c0;
    }
    puVar5 = &DAT_0010646b;
    uVar6 = 0xe5;
    uVar7 = 1;
  }
  _printk(puVar5,uVar6,uVar7,iVar3);
  puVar5 = &DAT_00106340;
LAB_00100954:
  _printk(puVar5,iVar3);
LAB_001009c0:
  mutex_unlock(param_1 + 0xb);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// get_adc_tm_gen3 @ 00100a34 size=232
// signature: undefined get_adc_tm_gen3(void)
// callers: []
//------------------------------------------------------------

void get_adc_tm_gen3(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  long local_78 [11];
  
  lVar1 = sp_el0;
  local_78[10] = *(long *)(lVar1 + 0x638);
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  scnprintf(&local_98,0x20,"qcom,%s-adc_tm",param_2);
  local_78[8] = 0;
  local_78[9] = 0;
  local_78[6] = 0;
  local_78[7] = 0;
  local_78[4] = 0;
  local_78[5] = 0;
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  iVar2 = __of_parse_phandle_with_args(*(undefined8 *)(param_1 + 0x2e8),&local_98,0,0,0,local_78);
  ppuVar3 = (undefined **)0xffffffffffffffed;
  if ((iVar2 == 0) && (local_78[0] != 0)) {
    ppuVar3 = &adc_tm_device_list;
    do {
      ppuVar3 = (undefined **)*ppuVar3;
      if (ppuVar3 == &adc_tm_device_list) {
        ppuVar3 = (undefined **)0xfffffffffffffdfb;
        goto LAB_00100af0;
      }
    } while (*(long *)(ppuVar3[-0x11] + 0x2e8) != local_78[0]);
    ppuVar3 = ppuVar3 + -0x12;
  }
LAB_00100af0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(ppuVar3);
  }
  return;
}



//------------------------------------------------------------
// notify_adc_tm_fn @ 00100b20 size=452
// signature: undefined notify_adc_tm_fn(void)
// callers: []
//------------------------------------------------------------

void notify_adc_tm_fn(long param_1)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  long *plVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  
  lVar1 = *(long *)(param_1 + -0x58) + 0x58;
  mutex_lock(lVar1);
  if (*(char *)(param_1 + -0x27) != '\0') {
    for (plVar4 = *(long **)(param_1 + 0x30); plVar4 != (long *)(param_1 + 0x30);
        plVar4 = (long *)*plVar4) {
      if (*(char *)((long)plVar4 + 0x23) != '\0') {
        *(undefined1 *)((long)plVar4 + 0x23) = 0;
        *(undefined1 *)(plVar4 + 4) = 1;
        *(uint *)((long)plVar4 + 0x24) = (uint)(*(int *)((long)plVar4 + 0x24) != 2) << 2;
      }
    }
    *(undefined1 *)(param_1 + -0x27) = 0;
  }
  if (*(char *)(param_1 + -0x28) != '\0') {
    for (plVar4 = *(long **)(param_1 + 0x30); plVar4 != (long *)(param_1 + 0x30);
        plVar4 = (long *)*plVar4) {
      if (*(char *)((long)plVar4 + 0x22) != '\0') {
        *(undefined2 *)((long)plVar4 + 0x21) = 1;
        uVar5 = 3;
        if (*(int *)((long)plVar4 + 0x24) == 2) {
          uVar5 = 1;
        }
        *(undefined4 *)((long)plVar4 + 0x24) = uVar5;
      }
    }
    *(undefined1 *)(param_1 + -0x28) = 0;
  }
  iVar2 = adc_tm_gen3_manage_thresholds(param_1 + -0x90);
  if (iVar2 < 0) {
    _printk(&DAT_00106584,iVar2);
  }
  iVar2 = adc_tm5_gen3_configure(param_1 + -0x90);
  if (iVar2 < 0) {
    _printk(&DAT_00106447,iVar2);
  }
  mutex_unlock(lVar1);
  puVar6 = *(undefined8 **)(param_1 + 0x30);
  do {
    if (puVar6 == (undefined8 *)(param_1 + 0x30)) {
      return;
    }
    if (*(char *)(puVar6 + 4) != '\0') {
      pcVar3 = *(code **)(puVar6[2] + 0x20);
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != -0x5c3d9bba) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c60);
          (*pcVar3)();
        }
        (*pcVar3)(1,*(undefined8 *)(puVar6[2] + 0x18));
        *(undefined1 *)(puVar6 + 4) = 0;
      }
    }
    if (*(char *)((long)puVar6 + 0x21) != '\0') {
      pcVar3 = *(code **)(puVar6[2] + 0x20);
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != -0x5c3d9bba) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c9c);
          (*pcVar3)();
        }
        (*pcVar3)(0,*(undefined8 *)(puVar6[2] + 0x18));
        *(undefined1 *)((long)puVar6 + 0x21) = 0;
      }
    }
    puVar6 = (undefined8 *)*puVar6;
  } while( true );
}



//------------------------------------------------------------
// adc_tm_gen3_manage_thresholds @ 00100ce4 size=376
// signature: undefined adc_tm_gen3_manage_thresholds(void)
// callers: [adc_tm_disable_chan_meas_gen3, notify_adc_tm_fn, adc_tm_channel_measure_gen3]
//------------------------------------------------------------

void adc_tm_gen3_manage_thresholds(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  int iVar5;
  long *plVar6;
  int iVar7;
  long *plVar8;
  uint uVar9;
  undefined8 local_40;
  long local_38;
  long lStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  plVar4 = (long *)(param_1 + 0xc0);
  plVar6 = (long *)*plVar4;
  local_40 = 0;
  *(undefined8 *)(param_1 + 0x60) = 0;
  if (plVar6 != plVar4) {
    do {
      *(undefined2 *)((long)plVar6 + 0x22) = 0;
      plVar6 = (long *)*plVar6;
    } while (plVar6 != plVar4);
    plVar6 = (long *)*plVar4;
    if (plVar6 != plVar4) {
      iVar5 = -0x80000000;
      iVar7 = 0x7fffffff;
      plVar8 = plVar6;
      do {
        if ((*(uint *)((long)plVar8 + 0x24) | 2) == 2) {
          iVar1 = *(int *)((long)plVar8 + 0x1c);
          if (iVar7 <= *(int *)((long)plVar8 + 0x1c)) {
            iVar1 = iVar7;
          }
          iVar7 = iVar1;
        }
        if (*(uint *)((long)plVar8 + 0x24) - 1 < 2) {
          iVar1 = (int)plVar8[3];
          if ((int)plVar8[3] <= iVar5) {
            iVar1 = iVar5;
          }
          iVar5 = iVar1;
        }
        plVar8 = (long *)*plVar8;
      } while (plVar8 != plVar4);
      for (; plVar6 != plVar4; plVar6 = (long *)*plVar6) {
        uVar9 = *(uint *)((long)plVar6 + 0x24);
        if (((uVar9 | 2) == 2) && (iVar7 == *(int *)((long)plVar6 + 0x1c))) {
          *(undefined4 *)(param_1 + 0x60) = 1;
          uVar9 = *(uint *)((long)plVar6 + 0x24);
          *(undefined1 *)((long)plVar6 + 0x22) = 1;
        }
        if ((uVar9 - 1 < 2) && (iVar5 == *(int *)(plVar6 + 3))) {
          *(undefined4 *)(param_1 + 100) = 1;
          *(undefined1 *)((long)plVar6 + 0x23) = 1;
        }
      }
      goto LAB_00100d98;
    }
  }
  iVar5 = -0x80000000;
  iVar7 = 0x7fffffff;
LAB_00100d98:
  local_38 = (long)iVar7;
  lStack_30 = (long)iVar5;
  if (*(int *)(param_1 + 0xd0) == 0) {
    adc_tm_absolute_rthr_gen3(&local_40);
    uVar3 = 0;
    *(long *)(param_1 + 0x70) = local_38;
    *(long *)(param_1 + 0x78) = lStack_30;
  }
  else {
    uVar3 = 0xfffffff7;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// adc_tm5_gen3_configure @ 00100e5c size=472
// signature: undefined adc_tm5_gen3_configure(void)
// callers: [adc_tm_disable_chan_meas_gen3, notify_adc_tm_fn, adc_tm5_gen3_set_trip_temp, adc_tm_channel_measure_gen3]
//------------------------------------------------------------

int adc_tm5_gen3_configure(undefined4 *param_1)

{
  byte bVar1;
  long lVar2;
  byte bVar3;
  int iVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  undefined1 local_4c [4];
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0xe);
  local_40 = 0;
  local_48 = 0;
  iVar4 = adc5_gen3_poll_wait_hs(puVar8,param_1[7]);
  if (iVar4 < 0) goto LAB_00101000;
  iVar4 = regmap_bulk_read(*puVar8,*(ushort *)(puVar8[2] + (ulong)(uint)param_1[7] * 0x18) + 0x4f,
                           &local_48,0xc);
  if (iVar4 < 0) {
    puVar5 = &DAT_00106752;
LAB_00100ff0:
    uVar6 = 0x4f;
    uVar7 = 0xc;
  }
  else {
    bVar1 = local_48._3_1_ & 0xc3;
    bVar3 = local_48._4_1_;
    local_48 = CONCAT71(local_48._1_7_,*(undefined1 *)(param_1 + 3)) & 0xffffffffffffff1f;
    local_40 = CONCAT22((short)*(undefined8 *)(param_1 + 0x1c),
                        (short)*(undefined8 *)(param_1 + 0x1e));
    local_48 = CONCAT17((byte)param_1[0x19] | (byte)(param_1[0x18] << 1),
                        CONCAT16(local_48._6_1_ & 0xf0 | *(byte *)(param_1 + 5),
                                 CONCAT15((char)*param_1,
                                          CONCAT14(bVar3 & 0x78 | *(byte *)(param_1 + 6),
                                                   CONCAT13(bVar1 | *(char *)(param_1 + 1) << 4 |
                                                            *(char *)(param_1 + 2) << 2,
                                                            CONCAT12((char)param_1[0x14],
                                                                     CONCAT11(*(undefined1 *)
                                                                               (param_1 + 0x13),
                                                                              (undefined1)local_48))
                                                           ))))) | 0x8000008000;
    iVar4 = regmap_bulk_write(*puVar8,*(ushort *)(puVar8[2] + (ulong)(uint)param_1[7] * 0x18) + 0x4f
                              ,&local_48,0xc);
    if (iVar4 < 0) {
      puVar5 = &DAT_0010646b;
      goto LAB_00100ff0;
    }
    local_4c[0] = 1;
    iVar4 = regmap_bulk_write(*puVar8,*(ushort *)(puVar8[2] + (ulong)(uint)param_1[7] * 0x18) + 0xe5
                              ,local_4c,1);
    if (-1 < iVar4) goto LAB_00101000;
    puVar5 = &DAT_0010646b;
    uVar6 = 0xe5;
    uVar7 = 1;
  }
  _printk(puVar5,uVar6,uVar7,iVar4);
LAB_00101000:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// adc_tm_channel_measure_gen3 @ 00101038 size=488
// signature: undefined adc_tm_channel_measure_gen3(void)
// callers: []
//------------------------------------------------------------

int adc_tm_channel_measure_gen3(long param_1,long *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  bool bVar7;
  long *plVar8;
  byte *pbVar9;
  undefined8 *puVar10;
  long lVar11;
  
  if ((param_2 != (long *)0x0) && (param_2[4] != 0)) {
    if (*(int *)(param_1 + 0x20) != 0) {
      lVar11 = 0;
      iVar3 = 0;
      do {
        pbVar9 = (byte *)(*(long *)(param_1 + 0x28) + (long)iVar3 * 0xd8);
        if (((uint)*pbVar9 | (*(uint *)(pbVar9 + 0xc) & 0x1f) << 8) == *(uint *)(param_2 + 2)) {
          mutex_lock(param_1 + 0x58);
          lVar6 = *(long *)(param_1 + 0x28);
          plVar8 = (long *)(lVar6 + lVar11 + 0xc0);
          plVar5 = (long *)*plVar8;
          if (plVar8 == plVar5) {
LAB_00101150:
            plVar5 = (long *)devm_kmalloc(*(undefined8 *)(param_1 + 8),0x28,0xdc0);
            if (plVar5 != (long *)0x0) {
              *(long **)plVar5[2] = plVar5;
              uVar1 = *(undefined4 *)((long)param_2 + 0xc);
              uVar2 = *(undefined4 *)((long)param_2 + 0x14);
              lVar6 = *(long *)(param_1 + 0x28) + lVar11;
              *(int *)(plVar5 + 3) = (int)param_2[1];
              *(undefined4 *)((long)plVar5 + 0x1c) = uVar1;
              *(undefined4 *)((long)plVar5 + 0x24) = uVar2;
              puVar10 = *(undefined8 **)(lVar6 + 200);
              uVar4 = __list_add_valid(plVar5,puVar10,lVar6 + 0xc0);
              if ((uVar4 & 1) != 0) {
                *(long **)(lVar6 + 200) = plVar5;
                *plVar5 = lVar6 + 0xc0;
                plVar5[1] = (long)puVar10;
                *puVar10 = plVar5;
              }
            }
          }
          else {
            bVar7 = false;
            do {
              while (*(long *)plVar5[2] != *param_2) {
                plVar5 = (long *)*plVar5;
                if ((long *)(lVar6 + lVar11 + 0xc0) == plVar5) {
                  if (!bVar7) goto LAB_00101150;
                  goto LAB_001011ac;
                }
              }
              *(int *)(plVar5 + 3) = (int)param_2[1];
              *(undefined4 *)((long)plVar5 + 0x1c) = *(undefined4 *)((long)param_2 + 0xc);
              uVar1 = *(undefined4 *)((long)param_2 + 0x14);
              *(undefined2 *)(plVar5 + 4) = 0;
              *(undefined4 *)((long)plVar5 + 0x24) = uVar1;
              plVar5 = (long *)*plVar5;
              lVar6 = *(long *)(param_1 + 0x28);
              bVar7 = true;
            } while ((long *)(lVar6 + lVar11 + 0xc0) != plVar5);
          }
LAB_001011ac:
          iVar3 = adc_tm_gen3_manage_thresholds(*(long *)(param_1 + 0x28) + lVar11);
          if (iVar3 < 0) {
            _printk(&DAT_00106584,iVar3);
          }
          iVar3 = adc_tm5_gen3_configure(*(long *)(param_1 + 0x28) + lVar11);
          if (iVar3 < 0) {
            _printk(&DAT_00106447,iVar3);
          }
          mutex_unlock(param_1 + 0x58);
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        lVar11 = lVar11 + 0xd8;
      } while (*(int *)(param_1 + 0x20) != iVar3);
    }
    _printk(&DAT_001064e8);
  }
  return -0x16;
}



//------------------------------------------------------------
// adc_tm_disable_chan_meas_gen3 @ 00101224 size=368
// signature: undefined adc_tm_disable_chan_meas_gen3(void)
// callers: []
//------------------------------------------------------------

int adc_tm_disable_chan_meas_gen3(long param_1,long *param_2)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  long *plVar4;
  byte *pbVar5;
  long *plVar6;
  int iVar7;
  
  if (param_2 != (long *)0x0) {
    iVar1 = *(int *)(param_1 + 0x20);
    if (iVar1 == 0) {
      iVar7 = 0;
LAB_00101298:
      if (iVar7 != iVar1) {
        mutex_lock(param_1 + 0x58);
        lVar3 = *(long *)(param_1 + 0x28);
        plVar4 = (long *)(lVar3 + (long)iVar7 * 0xd8 + 0xc0);
        plVar6 = (long *)*plVar4;
        if (plVar6 == plVar4) {
          iVar1 = 0;
        }
        else {
          iVar1 = 0;
          do {
            if (*(long *)plVar6[2] == *param_2) {
              *(undefined4 *)((long)plVar6 + 0x24) = 5;
              iVar1 = adc_tm_gen3_manage_thresholds(*(long *)(param_1 + 0x28) + (long)iVar7 * 0xd8);
              if (iVar1 < 0) {
                puVar2 = &DAT_00106584;
              }
              else {
                iVar1 = adc_tm5_gen3_configure(*(long *)(param_1 + 0x28) + (long)iVar7 * 0xd8);
                if (-1 < iVar1) {
                  lVar3 = *(long *)(param_1 + 0x28);
                  goto LAB_001012d8;
                }
                puVar2 = &DAT_00106447;
              }
              _printk(puVar2,iVar1);
              break;
            }
LAB_001012d8:
            plVar6 = (long *)*plVar6;
          } while (plVar6 != (long *)(lVar3 + (long)iVar7 * 0xd8 + 0xc0));
        }
        mutex_unlock(param_1 + 0x58);
        return iVar1;
      }
    }
    else {
      iVar7 = 0;
      do {
        pbVar5 = (byte *)(*(long *)(param_1 + 0x28) + (long)iVar7 * 0xd8);
        if (((uint)*pbVar5 | (*(uint *)(pbVar5 + 0xc) & 0x1f) << 8) == *(uint *)(param_2 + 2))
        goto LAB_00101298;
        iVar7 = iVar7 + 1;
      } while (iVar1 != iVar7);
    }
    _printk(&DAT_001064e8);
  }
  return -0x16;
}



//------------------------------------------------------------
// adc5_gen3_poll_wait_hs @ 00101394 size=324
// signature: undefined adc5_gen3_poll_wait_hs(void)
// callers: [adc5_gen3_remove, adc5_gen3_do_conversion, adc_tm5_gen3_configure]
//------------------------------------------------------------

int adc5_gen3_poll_wait_hs(undefined8 *param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  char local_50 [4];
  char local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  iVar4 = 0x96;
  local_4c[0] = '\0';
  local_50[0] = '\x01';
  do {
    iVar2 = regmap_bulk_read(*param_1,*(ushort *)(param_1[2] + (ulong)param_2 * 0x18) + 0x45,
                             local_4c,1);
    if (iVar2 < 0) {
      uVar3 = 0x45;
LAB_001014c4:
      _printk(&DAT_00106752,uVar3,1,iVar2);
      goto LAB_00101454;
    }
    if (local_4c[0] == '\x01') {
      iVar2 = regmap_bulk_read(*param_1,*(ushort *)(param_1[2] + (ulong)param_2 * 0x18) + 0xe5,
                               local_50,1);
      if (iVar2 < 0) {
        uVar3 = 0xe5;
        goto LAB_001014c4;
      }
      if (local_50[0] == '\0') {
        iVar2 = 0;
        goto LAB_00101454;
      }
    }
    usleep_range_state(100,0x6e,2);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  _printk(&DAT_001066bd,local_4c[0]);
  iVar2 = -0x6e;
LAB_00101454:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// adc5_gen3_probe @ 001014dc size=3052
// signature: undefined adc5_gen3_probe(void)
// callers: []
//------------------------------------------------------------

ulong adc5_gen3_probe(undefined8 *param_1)

{
  undefined8 *puVar1;
  uint *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined4 *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  long lVar11;
  long *plVar12;
  long lVar13;
  ulong uVar14;
  char *pcVar15;
  uint uVar16;
  undefined4 uVar17;
  int *piVar18;
  long *plVar19;
  uint uVar20;
  undefined4 *puVar21;
  undefined1 *puVar22;
  undefined8 uVar23;
  undefined4 *puVar24;
  ulong uVar25;
  undefined4 local_94;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  uVar23 = param_1[0x5f];
  local_94 = 0;
  local_78 = 0;
  local_88 = 0;
  uStack_80 = 0;
  lVar7 = dev_get_regmap(param_1[0xe],0);
  if (lVar7 == 0) {
    uVar25 = 0xffffffed;
    goto LAB_00101d00;
  }
  puVar1 = param_1 + 2;
  puVar8 = (undefined4 *)devm_iio_device_alloc(puVar1,0xe0);
  if (puVar8 == (undefined4 *)0x0) {
LAB_00101cfc:
    uVar25 = 0xfffffff4;
    goto LAB_00101d00;
  }
  plVar19 = *(long **)(puVar8 + 0x110);
  *plVar19 = lVar7;
  plVar19[1] = (long)puVar1;
  uVar9 = of_property_count_elems_of_size(uVar23,&DAT_00106580,4);
  uVar25 = uVar9 & 0xffffffff;
  if ((int)uVar9 < 0) goto LAB_00101d00;
  *(int *)((long)plVar19 + 0x1c) = (int)uVar9;
  lVar7 = devm_kmalloc(plVar19[1],(uVar9 & 0xffffffff) * 0x18,0xdc0);
  plVar19[2] = lVar7;
  if (lVar7 == 0) goto LAB_00101cfc;
  if (*(int *)((long)plVar19 + 0x1c) != 0) {
    uVar6 = 0;
    do {
      uVar25 = of_property_read_u32_index(uVar23,&DAT_00106580,uVar6,&local_94);
      if ((int)uVar25 < 0) {
        uVar25 = uVar25 & 0xffffffff;
        goto LAB_00101d00;
      }
      *(short *)(plVar19[2] + (long)(int)uVar6 * 0x18) = (short)local_94;
      scnprintf(&local_88,0x14,"adc-sdam%d",uVar6);
      uVar9 = of_irq_get_byname(uVar23,&local_88);
      uVar25 = uVar9 & 0xffffffff;
      if ((int)uVar9 < 0) {
        _printk(&DAT_0010684b,uVar6,uVar25);
        goto LAB_00101d00;
      }
      lVar7 = (long)(int)uVar6 * 0x18;
      *(int *)(plVar19[2] + lVar7 + 0x10) = (int)uVar9;
      uVar10 = devm_kstrdup(plVar19[1],&local_88,0xcc0);
      *(undefined8 *)(plVar19[2] + lVar7 + 8) = uVar10;
      if (*(long *)(plVar19[2] + lVar7 + 8) == 0) goto LAB_00101cfc;
      uVar6 = uVar6 + 1;
    } while (uVar6 < *(uint *)((long)plVar19 + 0x1c));
  }
  iVar5 = of_property_read_variable_u32_array(uVar23,"qcom,debug-base",&local_94,1,0);
  if (-1 < iVar5) {
    *(short *)(plVar19 + 3) = (short)local_94;
  }
  param_1[0x15] = plVar19;
  *(undefined1 **)(puVar8 + 0x10c) = adc5_gen3_info;
  *(undefined4 *)(plVar19 + 7) = 0;
  __init_swait_queue_head(plVar19 + 8,"&x->wait",&init_completion___key);
  __mutex_init(plVar19 + 0xb,"&adc->lock",&adc5_gen3_probe___key);
  lVar7 = of_get_next_available_child(uVar23,0);
  if (lVar7 == 0) {
    uVar25 = 0xffffffea;
    *(undefined4 *)(plVar19 + 4) = 0;
LAB_0010206c:
    _printk(&DAT_001066a3);
  }
  else {
    uVar6 = 0;
    do {
      uVar6 = uVar6 + 1;
      lVar7 = of_get_next_available_child(uVar23,lVar7);
    } while (lVar7 != 0);
    *(uint *)(plVar19 + 4) = uVar6;
    if (uVar6 == 0) {
      uVar25 = 0xffffffea;
      goto LAB_0010206c;
    }
    lVar7 = devm_kmalloc(plVar19[1],(ulong)uVar6 * 0x98,0xdc0);
    plVar19[6] = lVar7;
    if (lVar7 == 0) {
LAB_00101e48:
      uVar25 = 0xfffffff4;
      goto LAB_0010206c;
    }
    lVar7 = devm_kmalloc(plVar19[1],(ulong)*(uint *)(plVar19 + 4) * 0xd8,0xdc0);
    plVar19[5] = lVar7;
    if (lVar7 == 0) goto LAB_00101e48;
    puVar21 = (undefined4 *)plVar19[6];
    *(undefined4 *)(plVar19 + 0x11) = 0;
    lVar11 = of_match_node(&adc5_match_table,uVar23);
    puVar22 = adc5_gen3_data_pmic;
    if (lVar11 != 0) {
      puVar22 = *(undefined1 **)(lVar11 + 0xc0);
    }
    plVar12 = (long *)of_get_next_available_child(uVar23,0);
    if (plVar12 != (long *)0x0) {
      puVar24 = (undefined4 *)(lVar7 + 0xd0);
      uVar9 = 0;
      do {
        lVar7 = *plVar12;
        local_90 = 0;
        lVar11 = plVar19[1];
        local_70 = 0;
        uVar6 = of_property_read_variable_u32_array(plVar12,&DAT_00106580,(long)&local_90 + 4,1,0);
        if ((int)uVar6 < 0) {
          uVar25 = (ulong)uVar6;
          _dev_err(lVar11,"invalid channel number %s\n",lVar7);
          goto LAB_0010206c;
        }
        lVar13 = of_find_property(plVar12,"qcom,adc5-gen4",0);
        uVar20 = local_90._4_4_;
        uVar25 = (ulong)local_90._4_4_;
        uVar6 = (uint)(puVar22 != adc5_gen3_data_pmic);
        if (lVar13 != 0) {
          uVar6 = 1;
        }
        ppuVar3 = &adc5_gen4_data_pmic;
        if (lVar13 == 0) {
          ppuVar3 = (undefined **)puVar22;
        }
        uVar16 = (uint)(uVar25 & 0xff);
        puVar24[-0x2b] = uVar6;
        *(undefined ***)(puVar24 + -0x24) = ppuVar3;
        local_90 = CONCAT44(uVar16,(uint)local_90);
        if ((0xf8 < uVar16) || (*(long *)(ppuVar3[3] + (uVar25 & 0xff) * 0x20) == 0)) {
          _dev_err(lVar11,"%s invalid channel number %d\n",lVar7);
          uVar25 = 0xffffffea;
          goto LAB_0010206c;
        }
        puVar24[-0x2c] = 0;
        puVar24[-0x34] = uVar16;
        puVar24[-0x31] = uVar20 >> 8 & 0x1f;
        lVar7 = of_get_property(plVar12,"label",0);
        if ((lVar7 == 0) && (lVar7 = *plVar12, lVar7 == 0)) {
          _printk(&DAT_001069c2);
          uVar25 = 0xffffffea;
          goto LAB_0010206c;
        }
        *(long *)(puVar24 + -0x28) = lVar7;
        iVar5 = of_property_read_variable_u32_array(plVar12,"qcom,decimation",&local_90,1,0);
        if (-1 < iVar5) {
          piVar18 = *(int **)((long)puVar22 + 0x28);
          if (*piVar18 == (uint)local_90) {
            uVar17 = 0;
            puVar24[-0x32] = 0;
            goto LAB_00101940;
          }
          if (piVar18[1] == (uint)local_90) {
            uVar17 = 1;
            puVar24[-0x32] = 1;
            goto LAB_00101940;
          }
          if (piVar18[2] == (uint)local_90) {
            uVar17 = 2;
            puVar24[-0x32] = 2;
            goto LAB_00101940;
          }
          pcVar15 = "%02x invalid decimation %d\n";
LAB_00102060:
          _dev_err(lVar11,pcVar15,local_90._4_4_);
          uVar25 = 0xfffffffe;
          goto LAB_0010206c;
        }
        if (puVar24[-0x2b] == 0) {
          uVar17 = 2;
        }
        else {
          uVar17 = 1;
        }
        puVar24[-0x32] = uVar17;
LAB_00101940:
        iVar5 = of_property_read_variable_u32_array(uVar17,plVar12,"qcom,pre-scaling",&local_70,2,0)
        ;
        if (iVar5 < 0) {
          iVar5 = *(int *)(*(long *)(*(long *)(puVar24 + -0x24) + 0x18) +
                           (ulong)(uint)puVar24[-0x34] * 0x20 + 8);
        }
        else {
          uVar14 = qcom_adc5_prescaling_from_dt(local_70 & 0xffffffff,local_70._4_4_);
          uVar25 = uVar14 & 0xffffffff;
          iVar5 = (int)uVar14;
          if (iVar5 < 0) {
            _dev_err(lVar11,"%02x invalid pre-scaling <%d %d>\n",local_90._4_4_,
                     local_70 & 0xffffffff,local_70._4_4_);
            goto LAB_0010206c;
          }
        }
        puVar24[-0x30] = iVar5;
        iVar5 = of_property_read_variable_u32_array(plVar12,"qcom,hw-settle-time",&local_90,1,0);
        if (iVar5 < 0) {
LAB_001019c0:
          uVar17 = 0;
        }
        else {
          piVar18 = *(int **)((long)puVar22 + 0x30);
          if (*piVar18 == (uint)local_90) goto LAB_001019c0;
          if (piVar18[1] == (uint)local_90) {
            uVar17 = 1;
          }
          else if (piVar18[2] == (uint)local_90) {
            uVar17 = 2;
          }
          else if (piVar18[3] == (uint)local_90) {
            uVar17 = 3;
          }
          else if (piVar18[4] == (uint)local_90) {
            uVar17 = 4;
          }
          else if (piVar18[5] == (uint)local_90) {
            uVar17 = 5;
          }
          else if (piVar18[6] == (uint)local_90) {
            uVar17 = 6;
          }
          else if (piVar18[7] == (uint)local_90) {
            uVar17 = 7;
          }
          else if (piVar18[8] == (uint)local_90) {
            uVar17 = 8;
          }
          else if (piVar18[9] == (uint)local_90) {
            uVar17 = 9;
          }
          else if (piVar18[10] == (uint)local_90) {
            uVar17 = 10;
          }
          else if (piVar18[0xb] == (uint)local_90) {
            uVar17 = 0xb;
          }
          else if (piVar18[0xc] == (uint)local_90) {
            uVar17 = 0xc;
          }
          else if (piVar18[0xd] == (uint)local_90) {
            uVar17 = 0xd;
          }
          else if (piVar18[0xe] == (uint)local_90) {
            uVar17 = 0xe;
          }
          else {
            if (piVar18[0xf] != (uint)local_90) {
              pcVar15 = "%02x invalid hw-settle-time %d us\n";
              goto LAB_00102060;
            }
            uVar17 = 0xf;
          }
        }
        puVar24[-0x2f] = uVar17;
        iVar5 = of_property_read_variable_u32_array(plVar12,"qcom,avg-samples",&local_90,1,0);
        if (iVar5 < 0) {
          uVar17 = 0;
        }
        else {
          if ((((uint)local_90 == 0) || (0x10 < (uint)local_90)) ||
             (uVar25 = (local_90 & 0xffffffff) - ((ulong)((uint)local_90 >> 1) & 0x5555555555555555)
             , uVar25 = (uVar25 & 0x3333333333333333) + (uVar25 >> 2 & 0x3333333333333333),
             1 < (uVar25 + (uVar25 >> 4) & 0xf0f0f0f0f0f0f0f) * 0x101010101010101 >> 0x38)) {
            _dev_err(lVar11,"%02x invalid avg-samples %d\n",local_90._4_4_);
            uVar25 = 0xffffffea;
            goto LAB_0010206c;
          }
          uVar25 = (local_90 & 0xaaaaaaaa) >> 1 | (local_90 & 0x55555555) << 1;
          uVar25 = (uVar25 & 0xcccccccccccccccc) >> 2 | (uVar25 & 0x3333333333333333) << 2;
          uVar25 = (uVar25 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar25 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar25 = (uVar25 & 0xff00ff00ff00ff00) >> 8 | (uVar25 & 0xff00ff00ff00ff) << 8;
          uVar17 = (undefined4)LZCOUNT((uVar25 >> 0x10 | (uVar25 & 0xffff0000ffff) << 0x10) << 0x20)
          ;
        }
        puVar24[-0x2e] = uVar17;
        puVar24[-0x2a] = 0xffffffea;
        iVar5 = of_property_read_variable_u32_array(plVar12,"qcom,scale-fn-type",&local_90,1,0);
        if ((-1 < iVar5) && ((uint)local_90 < 0x1d)) {
          puVar24[-0x2a] = (uint)local_90;
        }
        lVar7 = of_find_property(plVar12,"qcom,ratiometric",0);
        puVar24[-0x20] = 1;
        uVar17 = 1;
        if (lVar7 == 0) {
          uVar17 = 2;
        }
        puVar24[-0x22] = 0;
        puVar24[-0x33] = uVar17;
        iVar5 = of_property_read_variable_u32_array(plVar12,"qcom,adc-tm-type",&local_90,1,0);
        if ((iVar5 < 0) || (3 < (uint)local_90)) {
          uVar6 = puVar24[-0x22];
        }
        else {
          puVar24[-0x22] = (uint)local_90;
          uVar6 = (uint)local_90;
        }
        if ((uVar6 == 3) &&
           (iVar5 = of_property_read_variable_u32_array(plVar12,"qcom,rscale-type",puVar24,1,0),
           iVar5 < 0)) {
          *puVar24 = 1;
        }
        uVar6 = puVar24[-0x22];
        if ((uVar6 | 2) != 2) {
          uVar20 = (int)plVar19[0x11] + 1;
          *(uint *)(plVar19 + 0x11) = uVar20;
          if (*(int *)((long)plVar19 + 0x1c) * 8 - 1U < uVar20) {
            _printk(&DAT_001067da);
            uVar25 = 0xffffffea;
            goto LAB_0010206c;
          }
          puVar24[-0x2d] = uVar20 >> 3;
          puVar24[-0x21] = uVar20 & 7;
          puVar24[-0x20] = 4;
          if (uVar6 == 3) {
            lVar7 = alloc_workqueue("adc_tm_notify_wq",0x10,0);
            *(long *)(puVar24 + -0x12) = lVar7;
            if (lVar7 == 0) {
              _printk(&DAT_0010678b);
              uVar25 = 0xfffffff4;
              goto LAB_0010206c;
            }
            *(undefined8 *)(puVar24 + -0x10) = 0xfffffffe0;
            *(undefined4 **)(puVar24 + -0xe) = puVar24 + -0xe;
            *(undefined4 **)(puVar24 + -0xc) = puVar24 + -0xe;
            *(code **)(puVar24 + -10) = notify_adc_tm_fn;
          }
          *(undefined4 **)(puVar24 + -4) = puVar24 + -4;
          *(undefined4 **)(puVar24 + -2) = puVar24 + -4;
        }
        *(long **)(puVar24 + -0x26) = plVar19;
        if (puVar24[-0x2a] == -0x16) {
          uVar25 = (ulong)(uint)puVar24[-0x34];
          puVar24[-0x2a] =
               *(undefined4 *)(*(long *)(*(long *)(puVar24 + -0x24) + 0x18) + uVar25 * 0x20 + 0x18);
        }
        else {
          uVar25 = (ulong)(uint)puVar24[-0x34];
        }
        lVar7 = *(long *)(*(long *)(puVar24 + -0x24) + 0x18);
        puVar21[1] = (int)uVar25;
        lVar7 = lVar7 + uVar25 * 0x20;
        *(undefined8 *)(puVar21 + 0x22) = *(undefined8 *)(puVar24 + -0x28);
        *(undefined8 *)(puVar21 + 0x20) = *(undefined8 *)(puVar24 + -0x28);
        *(undefined8 *)(puVar21 + 10) = *(undefined8 *)(lVar7 + 0x10);
        uVar17 = *(undefined4 *)(lVar7 + 0xc);
        *(ulong *)(puVar21 + 4) = uVar9;
        *puVar21 = uVar17;
        plVar12 = (long *)of_get_next_available_child(uVar23,plVar12);
        puVar24 = puVar24 + 0x36;
        puVar21 = puVar21 + 0x26;
        uVar9 = (ulong)((int)uVar9 + 1);
      } while (plVar12 != (long *)0x0);
    }
    if (*(int *)((long)plVar19 + 0x1c) != 0) {
      uVar6 = 0;
      do {
        lVar7 = plVar19[2] + (long)(int)uVar6 * 0x18;
        uVar25 = request_threaded_irq
                           (*(undefined4 *)(lVar7 + 0x10),adc5_gen3_isr,0,0,
                            *(undefined8 *)(lVar7 + 8),plVar19);
        if ((int)uVar25 < 0) {
          uVar25 = uVar25 & 0xffffffff;
          iVar5 = *(int *)((long)plVar19 + 0x1c);
          goto joined_r0x00101e40;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)((long)plVar19 + 0x1c));
    }
    uVar9 = (ulong)*(uint *)(plVar19 + 4);
    if (*(uint *)(plVar19 + 4) != 0) {
      lVar7 = 0;
      uVar14 = 0;
      do {
        lVar11 = plVar19[5];
        puVar2 = (uint *)(lVar11 + lVar7);
        uVar6 = puVar2[0x12];
        if (3 < uVar6) {
          _printk(&DAT_00106902,uVar6,*puVar2);
          uVar25 = 0xffffffea;
          iVar5 = *(int *)((long)plVar19 + 0x1c);
          goto joined_r0x00101e40;
        }
        uVar25 = 0;
        puVar22 = adc_tm_ops;
        switch(uVar6) {
        case 0:
          goto switchD_00101e04_caseD_0;
        case 2:
          puVar22 = adc_tm_ops_iio;
          break;
        case 3:
          goto switchD_00101e04_caseD_3;
        }
        uVar25 = devm_thermal_of_zone_register
                           (plVar19[1],*puVar2 & 0xff | (puVar2[3] & 0x1f) << 8,puVar2,puVar22);
        if (0xfffffffffffff000 < uVar25) {
          _printk(&DAT_001067ac,uVar25,*(undefined4 *)(plVar19[5] + lVar7));
          if ((int)uVar25 < 0) goto LAB_00101fd4;
          break;
        }
        lVar11 = plVar19[5];
switchD_00101e04_caseD_3:
        *(ulong *)(lVar11 + lVar7 + 0x58) = uVar25;
        uVar9 = (ulong)*(uint *)(plVar19 + 4);
switchD_00101e04_caseD_0:
        uVar14 = uVar14 + 1;
        lVar7 = lVar7 + 0xd8;
      } while (uVar14 < uVar9);
    }
    lVar7 = thermal_minidump_register("adc5_gen3");
    plVar19[0x1b] = lVar7;
    if ((int)plVar19[0x11] != 0) {
      plVar19[0x15] = 0xfffffffe0;
      plVar19[0x16] = (long)(plVar19 + 0x16);
      plVar19[0x17] = (long)(plVar19 + 0x16);
      plVar19[0x18] = (long)tm_handler_work;
    }
    *(undefined8 **)(puVar8 + 0x1a) = puVar1;
    *(undefined8 *)(puVar8 + 0xbc) = uVar23;
    plVar12 = plVar19 + 0x12;
    uVar23 = *param_1;
    *puVar8 = 1;
    puVar4 = PTR_adc_tm_device_list_00106a98;
    *(undefined8 *)(puVar8 + 0x108) = uVar23;
    *(long *)(puVar8 + 0x104) = plVar19[6];
    puVar8[0x106] = (int)plVar19[4];
    uVar25 = __list_add_valid(plVar12,puVar4,&adc_tm_device_list);
    if ((uVar25 & 1) != 0) {
      PTR_adc_tm_device_list_00106a98 = (undefined *)plVar12;
      plVar19[0x12] = (long)&adc_tm_device_list;
      plVar19[0x13] = (long)puVar4;
      *(long **)puVar4 = plVar12;
    }
    plVar19[0x14] = (long)&adc_tm_device_list;
    uVar9 = __devm_iio_device_register(puVar1,puVar8,&__this_module);
    uVar25 = uVar9 & 0xffffffff;
    if ((int)uVar9 == 0) goto LAB_00101d00;
LAB_00101fd4:
    iVar5 = *(int *)((long)plVar19 + 0x1c);
joined_r0x00101e40:
    if (iVar5 != 0) {
      uVar6 = 0;
      do {
        free_irq(*(undefined4 *)(plVar19[2] + (long)(int)uVar6 * 0x18 + 0x10),plVar19);
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)((long)plVar19 + 0x1c));
    }
  }
  uVar6 = *(uint *)(plVar19 + 4);
  if (uVar6 != 0) {
    uVar20 = 0;
    do {
      if (*(long *)(plVar19[5] + (long)(int)uVar20 * 0xd8 + 0x88) != 0) {
        destroy_workqueue();
        uVar6 = *(uint *)(plVar19 + 4);
      }
      uVar20 = uVar20 + 1;
    } while (uVar20 < uVar6);
  }
LAB_00101d00:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar25 & 0xffffffff;
}



//------------------------------------------------------------
// adc5_gen3_remove @ 001020cc size=608
// signature: undefined adc5_gen3_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 adc5_gen3_remove(long param_1)

{
  uint uVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  undefined8 *puVar6;
  uint uVar7;
  byte local_5c [4];
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  puVar6 = *(undefined8 **)(param_1 + 0xa8);
  local_5c[0] = 0;
  if (*(int *)(puVar6 + 0x11) != 0) {
    cancel_work_sync(puVar6 + 0x15);
  }
  if (*(int *)((long)puVar6 + 0x1c) != 0) {
    uVar7 = 0;
    do {
      free_irq(*(undefined4 *)(puVar6[2] + (long)(int)uVar7 * 0x18 + 0x10),puVar6);
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)((long)puVar6 + 0x1c));
  }
  mutex_lock(puVar6 + 0xb);
  if (*(int *)(puVar6 + 4) != 0) {
    uVar7 = 0;
    do {
      lVar5 = puVar6[5];
      if (*(long *)(lVar5 + (long)(int)uVar7 * 0xd8 + 0x88) != 0) {
        destroy_workqueue();
        lVar5 = puVar6[5];
      }
      uVar1 = uVar7 + 1;
      *(undefined4 *)(lVar5 + (long)(int)uVar7 * 0xd8 + 0x50) = 0;
      uVar7 = uVar1;
    } while (uVar1 < *(uint *)(puVar6 + 4));
  }
  if ((*(uint *)((long)puVar6 + 0x1c) & 0x1fffffff) != 0) {
    uVar7 = 0;
    do {
      uVar1 = uVar7 + 7;
      if (-1 < (int)uVar7) {
        uVar1 = uVar7;
      }
      uVar1 = (int)uVar1 >> 3;
      adc5_gen3_poll_wait_hs(puVar6,uVar1);
      local_5c[0] = 0;
      iVar3 = regmap_bulk_write(*puVar6,*(ushort *)(puVar6[2] + (ulong)uVar1 * 0x18) + 0x51,local_5c
                                ,1);
      if (iVar3 < 0) {
        _printk(&DAT_0010646b,0x51,1,iVar3);
      }
      local_5c[0] = (char)uVar7 + (char)uVar1 * -8 | 0x80;
      iVar3 = regmap_bulk_write(*puVar6,*(ushort *)(puVar6[2] + (ulong)uVar1 * 0x18) + 0x50,local_5c
                                ,1);
      if (iVar3 < 0) {
        _printk(&DAT_0010646b,0x50,1,iVar3);
      }
      local_5c[0] = 1;
      iVar3 = regmap_bulk_write(*puVar6,*(ushort *)(puVar6[2] + (ulong)uVar1 * 0x18) + 0xe5,local_5c
                                ,1);
      if (iVar3 < 0) {
        _printk(&DAT_0010646b,0xe5,1,iVar3);
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)(*(int *)((long)puVar6 + 0x1c) << 3));
  }
  mutex_unlock(puVar6 + 0xb);
  uVar4 = __list_del_entry_valid(puVar6 + 0x12);
  if ((uVar4 & 1) != 0) {
    lVar5 = puVar6[0x12];
    plVar2 = (long *)puVar6[0x13];
    *(long **)(lVar5 + 8) = plVar2;
    *plVar2 = lVar5;
  }
  puVar6[0x12] = 0xdead000000000100;
  puVar6[0x13] = 0xdead000000000122;
  thermal_minidump_unregister(puVar6[0x1b]);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// adc5_gen3_isr @ 00102330 size=708
// signature: undefined adc5_gen3_isr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adc5_gen3_isr(int param_1,undefined8 *param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined1 local_48 [4];
  byte local_44 [4];
  char local_40 [4];
  undefined2 local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40[0] = '\0';
  local_3c = 0;
  local_44[0] = 0;
  if (*(int *)((long)param_2 + 0x1c) != 0) {
    lVar4 = 0;
    iVar1 = 0;
    do {
      if (*(int *)(param_2[2] + (long)iVar1 * 0x18 + 0x10) == param_1) {
        if (-1 < iVar1) {
          iVar1 = regmap_bulk_read(*param_2,*(ushort *)(param_2[2] + lVar4) + 0x4a,local_44,1);
          if (iVar1 < 0) {
            _printk(&DAT_00106752,0x4a,1,iVar1);
            puVar2 = &DAT_00106816;
          }
          else {
            if ((local_44[0] & 1) != 0) {
              complete(param_2 + 7);
            }
            iVar1 = regmap_bulk_read(*param_2,*(ushort *)(param_2[2] + lVar4) + 0x48,&local_3c,2);
            if (iVar1 < 0) {
              _printk(&DAT_00106752,0x48,2,iVar1);
              puVar2 = &DAT_00106a2e;
            }
            else {
              if ((char)local_3c != '\0' || local_3c._1_1_ != '\0') {
                queue_work_on(0x20,_system_wq,param_2 + 0x15);
              }
              iVar1 = regmap_bulk_read(*param_2,*(ushort *)(param_2[2] + lVar4) + 0x46,local_40,1);
              if (-1 < iVar1) {
                if (-1 < local_40[0]) {
                  uVar3 = 1;
                  goto LAB_001025c0;
                }
                iVar1 = ___ratelimit(adc5_gen3_isr__rs,"adc5_gen3_isr");
                if (iVar1 != 0) {
                  _printk(&DAT_00106a53,local_40[0],local_44[0]);
                }
                local_48[0] = 1;
                iVar1 = regmap_bulk_write(*param_2,*(ushort *)(param_2[2] + lVar4) + 0x4e,local_48,1
                                         );
                if (iVar1 < 0) {
                  uVar3 = 0x4e;
                }
                else {
                  local_48[0] = 0;
                  uVar3 = 1;
                  iVar1 = regmap_bulk_write(*param_2,*(ushort *)(param_2[2] + lVar4) + 0x50,local_48
                                            ,1);
                  if (iVar1 < 0) {
                    uVar3 = 0x50;
                  }
                  else {
                    local_48[0] = 1;
                    iVar1 = regmap_bulk_write(*param_2,*(ushort *)(param_2[2] + lVar4) + 0xe5,
                                              local_48,1);
                    if (-1 < iVar1) goto LAB_001025c0;
                    uVar3 = 0xe5;
                  }
                }
                _printk(&DAT_0010646b,uVar3,1,iVar1);
                goto LAB_001025bc;
              }
              _printk(&DAT_00106752,0x46,1,iVar1);
              puVar2 = &DAT_0010695c;
            }
          }
          _printk(puVar2,iVar1);
          goto LAB_001025bc;
        }
        break;
      }
      iVar1 = iVar1 + 1;
      lVar4 = lVar4 + 0x18;
    } while (*(int *)((long)param_2 + 0x1c) != iVar1);
  }
  _printk(&DAT_001065a3);
LAB_001025bc:
  uVar3 = 0;
LAB_001025c0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// tm_handler_work @ 001025f8 size=996
// signature: undefined tm_handler_work(void)
// callers: []
//------------------------------------------------------------

void tm_handler_work(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  code *pcVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  uint uVar13;
  long lVar14;
  uint *puVar15;
  long lVar16;
  undefined4 local_84;
  undefined1 local_80 [4];
  undefined2 local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  local_7c = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_80[0] = 0;
  if (*(int *)(param_1 + -0x88) != 0) {
    uVar10 = 0;
    lVar12 = param_1 + -0x50;
    uVar13 = 0xffffffff;
    do {
      lVar16 = *(long *)(param_1 + -0x80);
      local_84 = 0;
      lVar14 = lVar16 + (long)(int)uVar10 * 0xd8;
      puVar15 = (uint *)(lVar14 + 0x48);
      if ((*puVar15 | 2) == 3) {
        uVar1 = *(uint *)(lVar14 + 0x4c);
        mutex_lock(lVar12);
        uVar2 = *(uint *)(lVar16 + (long)(int)uVar10 * 0xd8 + 0x1c);
        if (uVar2 != uVar13) {
          iVar8 = regmap_bulk_read(*(undefined8 *)(param_1 + -0xa8),
                                   *(ushort *)(*(long *)(param_1 + -0x98) + (ulong)uVar2 * 0x18) +
                                   0x48,&local_7c,2);
          if (iVar8 < 0) {
            _printk(&DAT_00106752,0x48,2,iVar8);
            puVar9 = &DAT_00106a2e;
          }
          else {
            iVar8 = regmap_bulk_write(*(undefined8 *)(param_1 + -0xa8),
                                      *(ushort *)(*(long *)(param_1 + -0x98) + (ulong)uVar2 * 0x18)
                                      + 0x4c,&local_7c,2);
            if (iVar8 < 0) {
              _printk(&DAT_0010646b,0x4c,2,iVar8);
              puVar9 = &DAT_001065db;
            }
            else {
              local_80[0] = 0;
              iVar8 = regmap_bulk_write(*(undefined8 *)(param_1 + -0xa8),
                                        *(ushort *)
                                         (*(long *)(param_1 + -0x98) + (ulong)uVar2 * 0x18) + 0x50,
                                        local_80,1);
              if (iVar8 < 0) {
                _printk(&DAT_0010646b,0x50,1,iVar8);
                puVar9 = &DAT_00106720;
              }
              else {
                local_80[0] = 1;
                iVar8 = regmap_bulk_write(*(undefined8 *)(param_1 + -0xa8),
                                          *(ushort *)
                                           (*(long *)(param_1 + -0x98) + (ulong)uVar2 * 0x18) + 0xe5
                                          ,local_80,1);
                if (iVar8 < 0) {
                  _printk(&DAT_0010646b,0xe5,1,iVar8);
                  puVar9 = &DAT_0010639b;
                }
                else {
                  iVar8 = regmap_bulk_read(*(undefined8 *)(param_1 + -0xa8),
                                           *(ushort *)
                                            (*(long *)(param_1 + -0x98) + (ulong)uVar2 * 0x18) +
                                           0x5c,&local_78,0x10);
                  uVar13 = uVar2;
                  if (-1 < iVar8) goto LAB_001027b8;
                  _printk(&DAT_00106752,0x5c,0x10,iVar8);
                  puVar9 = &DAT_001064b9;
                }
              }
            }
          }
          _printk(puVar9,iVar8);
          mutex_unlock(lVar12);
          break;
        }
LAB_001027b8:
        uVar11 = 1L << ((ulong)uVar1 & 0x3f);
        if ((uVar11 & (byte)local_7c) == 0) {
          bVar6 = false;
        }
        else {
          bVar6 = *(int *)(lVar16 + (long)(int)uVar10 * 0xd8 + 0x60) != 0;
        }
        if ((uVar11 & local_7c._1_1_) == 0) {
          bVar7 = false;
        }
        else {
          bVar7 = *(int *)(lVar16 + (long)(int)uVar10 * 0xd8 + 100) != 0;
        }
        mutex_unlock(lVar12);
        if ((bool)(bVar6 | bVar7)) {
          uVar1 = uVar1 * 2;
          if (0xf < uVar1) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1029d4);
            (*pcVar5)();
          }
          uVar11 = (ulong)uVar1 | 1;
          if (0x10 < (uint)uVar11) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(1,0x1029d8);
            (*pcVar5)();
          }
          if (*puVar15 == 3) {
            if (bVar7) {
              mutex_lock(lVar12);
              lVar14 = lVar16 + (long)(int)uVar10 * 0xd8;
              *(undefined4 *)(lVar14 + 100) = 0;
              *(undefined1 *)(lVar14 + 0x69) = 1;
              mutex_unlock(lVar12);
              queue_work_on(0x20,*(undefined8 *)(lVar14 + 0x88),lVar14 + 0x90);
            }
            if (bVar6) {
              mutex_lock(lVar12);
              lVar16 = lVar16 + (long)(int)uVar10 * 0xd8;
              *(undefined4 *)(lVar16 + 0x60) = 0;
              *(undefined1 *)(lVar16 + 0x68) = 1;
              mutex_unlock(lVar12);
              queue_work_on(0x20,*(undefined8 *)(lVar16 + 0x88),lVar16 + 0x90);
            }
          }
          else {
            lVar14 = lVar16 + (long)(int)uVar10 * 0xd8;
            uVar3 = local_80[(ulong)uVar1 + 8];
            uVar4 = local_80[uVar11 + 8];
            iVar8 = qcom_adc5_hw_scale(*(undefined4 *)(lVar14 + 0x28),*(undefined4 *)(lVar14 + 0x10)
                                       ,*(undefined8 *)(lVar14 + 0x40),CONCAT11(uVar4,uVar3),
                                       &local_84);
            if (iVar8 < 0) {
              _printk(&DAT_00106369,iVar8,CONCAT11(uVar4,uVar3));
            }
            else {
              lVar16 = lVar16 + (long)(int)uVar10 * 0xd8;
              *(undefined4 *)(lVar16 + 0x80) = local_84;
              *(undefined1 *)(lVar16 + 0x84) = 1;
              thermal_zone_device_update(*(undefined8 *)(lVar16 + 0x58),2);
            }
          }
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < *(uint *)(param_1 + -0x88));
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// adc5_gen3_read_raw @ 001029e0 size=212
// signature: undefined adc5_gen3_read_raw(void)
// callers: []
//------------------------------------------------------------

void adc5_gen3_read_raw(long param_1,long param_2,uint *param_3,undefined8 param_4,long param_5)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ushort local_3c [2];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x440);
  local_3c[0] = 0;
  lVar6 = *(long *)(param_2 + 0x10);
  lVar5 = *(long *)(lVar2 + 0x28);
  lVar4 = lVar5 + lVar6 * 0xd8;
  if (param_5 == 0) {
    uVar3 = adc5_gen3_do_conversion(lVar2,lVar4,local_3c);
    if (-1 < (int)uVar3) {
      uVar3 = 1;
      *param_3 = (uint)local_3c[0];
    }
  }
  else if (param_5 == 1) {
    uVar3 = adc5_gen3_do_conversion(lVar2,lVar4,local_3c);
    if (-1 < (int)uVar3) {
      lVar5 = lVar5 + lVar6 * 0xd8;
      uVar1 = qcom_adc5_hw_scale(*(undefined4 *)(lVar5 + 0x28),*(undefined4 *)(lVar5 + 0x10),
                                 *(undefined8 *)(lVar5 + 0x40),local_3c[0],param_3);
      if (-1 < (int)uVar1) {
        uVar1 = 1;
      }
      uVar3 = (ulong)uVar1;
    }
  }
  else {
    uVar3 = 0xffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// adc5_gen3_fwnode_xlate @ 00102ab8 size=72
// signature: undefined adc5_gen3_fwnode_xlate(void)
// callers: []
//------------------------------------------------------------

int adc5_gen3_fwnode_xlate(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar1 = *(int *)(*(long *)(param_1 + 0x440) + 0x20);
  if (iVar1 != 0) {
    iVar2 = 0;
    do {
      pbVar3 = (byte *)(*(long *)(*(long *)(param_1 + 0x440) + 0x28) + (long)iVar2 * 0xd8);
      if (*(ulong *)(param_2 + 0x10) ==
          ((ulong)*pbVar3 | ((ulong)*(uint *)(pbVar3 + 0xc) & 0x1f) << 8)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar1 != iVar2);
  }
  return -2;
}



//------------------------------------------------------------
// adc_tm5_gen3_set_trip_temp @ 00102b04 size=316
// signature: undefined adc_tm5_gen3_set_trip_temp(void)
// callers: []
//------------------------------------------------------------

int adc_tm5_gen3_set_trip_temp(long param_1,int param_2,int param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int local_50;
  int local_4c;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x3f0);
  local_48 = 0;
  local_40 = 0;
  if (lVar2 == 0) {
LAB_00102b70:
    iVar1 = -0x16;
  }
  else {
    local_50 = 0;
    if (param_3 != 0x7fffffff) {
      local_50 = param_3;
    }
    lVar3 = *(long *)(lVar2 + 0x38);
    local_4c = 0;
    if (param_2 == -0x80000000) {
      if (param_3 == 0x7fffffff) {
        _printk(&DAT_001063fe);
        goto LAB_00102b70;
      }
    }
    else {
      local_4c = param_2;
    }
    adc_tm_scale_therm_voltage_100k_gen3(&local_50,*(undefined8 *)(lVar2 + 0x40));
    lVar3 = lVar3 + 0x58;
    mutex_lock(lVar3);
    if (param_3 != 0x7fffffff) {
      *(undefined8 *)(lVar2 + 0x78) = local_40;
    }
    *(uint *)(lVar2 + 100) = (uint)(param_3 != 0x7fffffff);
    if (-0x7fffffff < param_2) {
      *(undefined8 *)(lVar2 + 0x70) = local_48;
    }
    *(uint *)(lVar2 + 0x60) = (uint)(-0x7fffffff < param_2);
    iVar1 = adc_tm5_gen3_configure(lVar2);
    if (iVar1 < 0) {
      _printk(&DAT_00106447,iVar1);
    }
    mutex_unlock(lVar3);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// adc5_gen3_suspend @ 00102c44 size=136
// signature: undefined adc5_gen3_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adc5_gen3_suspend(long param_1)

{
  long lVar1;
  uint uVar2;
  
  if (_pm_suspend_target_state == 3) {
    lVar1 = *(long *)(param_1 + 0x98);
    mutex_lock(lVar1 + 0x58);
    if (*(int *)(lVar1 + 0x1c) != 0) {
      uVar2 = 0;
      do {
        free_irq(*(undefined4 *)(*(long *)(lVar1 + 0x10) + (long)(int)uVar2 * 0x18 + 0x10),lVar1);
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(lVar1 + 0x1c));
    }
    mutex_unlock(lVar1 + 0x58);
  }
  return 0;
}



//------------------------------------------------------------
// adc5_gen3_resume @ 00102cd0 size=148
// signature: undefined adc5_gen3_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adc5_gen3_resume(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  
  if ((_pm_suspend_target_state == 3) &&
     (lVar3 = *(long *)(param_1 + 0x98), *(int *)(lVar3 + 0x1c) != 0)) {
    uVar4 = 0;
    do {
      lVar2 = *(long *)(lVar3 + 0x10) + (long)(int)uVar4 * 0x18;
      uVar1 = request_threaded_irq
                        (*(undefined4 *)(lVar2 + 0x10),adc5_gen3_isr,0,0,*(undefined8 *)(lVar2 + 8),
                         lVar3);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(lVar3 + 0x1c));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// adc5_gen3_freeze @ 00102d68 size=120
// signature: undefined adc5_gen3_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 adc5_gen3_freeze(long param_1)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar1 + 0x58);
  if (*(int *)(lVar1 + 0x1c) != 0) {
    uVar2 = 0;
    do {
      free_irq(*(undefined4 *)(*(long *)(lVar1 + 0x10) + (long)(int)uVar2 * 0x18 + 0x10),lVar1);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(lVar1 + 0x1c));
  }
  mutex_unlock(lVar1 + 0x58);
  return 0;
}



//------------------------------------------------------------
// adc5_gen3_restore @ 00102de4 size=132
// signature: undefined adc5_gen3_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 adc5_gen3_restore(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  uint uVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (*(int *)(lVar3 + 0x1c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar4 = 0;
    do {
      lVar2 = *(long *)(lVar3 + 0x10) + (long)(int)uVar4 * 0x18;
      uVar1 = request_threaded_irq
                        (*(undefined4 *)(lVar2 + 0x10),adc5_gen3_isr,0,0,*(undefined8 *)(lVar2 + 8),
                         lVar3);
      if ((int)uVar1 < 0) {
        return uVar1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(lVar3 + 0x1c));
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 00102eb8 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&adc5_gen3_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102ee8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&adc5_gen3_driver);
  return;
}



//------------------------------------------------------------
// qcom_adc5_hw_scale @ 00109000 size=1
// signature: undefined qcom_adc5_hw_scale(void)
// callers: [tm_handler_work, adc5_gen3_read_raw, adc_tm_gen3_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_adc5_hw_scale(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_update_data @ 00109008 size=1
// signature: undefined thermal_minidump_update_data(void)
// callers: [adc_tm_gen3_get_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_minidump_update_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [adc5_gen3_probe, adc5_gen3_isr, tm_handler_work, get_adc_tm_gen3, adc5_gen3_read_raw, adc_tm_gen3_get_temp, adc5_gen3_remove, adc5_gen3_do_conversion, adc_tm5_gen3_configure, adc_tm5_gen3_set_trip_temp, adc_tm_gen3_manage_thresholds, adc5_gen3_poll_wait_hs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109018 size=1
// signature: undefined mutex_lock(void)
// callers: [adc_tm_disable_chan_meas_gen3, tm_handler_work, notify_adc_tm_fn, adc5_gen3_remove, adc5_gen3_suspend, adc5_gen3_do_conversion, adc_tm5_gen3_set_trip_temp, adc_tm_channel_measure_gen3, adc5_gen3_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00109020 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [adc5_gen3_isr, tm_handler_work, adc5_gen3_do_conversion, adc_tm5_gen3_configure, adc5_gen3_poll_wait_hs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 00109028 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [adc5_gen3_isr, tm_handler_work, adc5_gen3_remove, adc5_gen3_do_conversion, adc_tm5_gen3_configure]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00109030 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [adc5_gen3_do_conversion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109038 size=1
// signature: undefined _printk(void)
// callers: [adc5_gen3_probe, adc5_gen3_isr, adc_tm_disable_chan_meas_gen3, tm_handler_work, notify_adc_tm_fn, adc5_gen3_remove, adc5_gen3_do_conversion, adc_tm5_gen3_configure, adc_tm5_gen3_set_trip_temp, adc_tm_channel_measure_gen3, adc5_gen3_poll_wait_hs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 00109040 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [adc5_gen3_do_conversion]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109048 size=1
// signature: undefined mutex_unlock(void)
// callers: [adc_tm_disable_chan_meas_gen3, tm_handler_work, notify_adc_tm_fn, adc5_gen3_remove, adc5_gen3_suspend, adc5_gen3_do_conversion, adc_tm5_gen3_set_trip_temp, adc_tm_channel_measure_gen3, adc5_gen3_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00109050 size=1
// signature: undefined scnprintf(void)
// callers: [adc5_gen3_probe, get_adc_tm_gen3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00109058 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [get_adc_tm_gen3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// adc_tm_absolute_rthr_gen3 @ 00109060 size=1
// signature: undefined adc_tm_absolute_rthr_gen3(void)
// callers: [adc_tm_gen3_manage_thresholds]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void adc_tm_absolute_rthr_gen3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00109068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [adc5_gen3_probe, adc_tm_channel_measure_gen3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00109070 size=1
// signature: undefined __list_add_valid(void)
// callers: [adc5_gen3_probe, adc_tm_channel_measure_gen3]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00109078 size=1
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
// platform_driver_unregister @ 00109080 size=1
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
// usleep_range_state @ 00109088 size=1
// signature: undefined usleep_range_state(void)
// callers: [adc5_gen3_poll_wait_hs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00109090 size=1
// signature: undefined dev_get_regmap(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_iio_device_alloc @ 00109098 size=1
// signature: undefined devm_iio_device_alloc(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_iio_device_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 001090a0 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001090a8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 001090b0 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 001090b8 size=1
// signature: undefined devm_kstrdup(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001090c0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001090c8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001090d0 size=1
// signature: undefined __mutex_init(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001090d8 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 001090e0 size=1
// signature: undefined of_match_node(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001090e8 size=1
// signature: undefined of_find_property(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 001090f0 size=1
// signature: undefined of_get_property(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_adc5_prescaling_from_dt @ 001090f8 size=1
// signature: undefined qcom_adc5_prescaling_from_dt(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_adc5_prescaling_from_dt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00109100 size=1
// signature: undefined alloc_workqueue(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00109108 size=1
// signature: undefined request_threaded_irq(void)
// callers: [adc5_gen3_probe, adc5_gen3_resume, adc5_gen3_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 00109110 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00109118 size=1
// signature: undefined _dev_err(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_register @ 00109120 size=1
// signature: undefined thermal_minidump_register(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_minidump_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_iio_device_register @ 00109128 size=1
// signature: undefined __devm_iio_device_register(void)
// callers: [adc5_gen3_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_iio_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00109130 size=1
// signature: undefined free_irq(void)
// callers: [adc5_gen3_probe, adc5_gen3_remove, adc5_gen3_suspend, adc5_gen3_freeze]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00109138 size=1
// signature: undefined destroy_workqueue(void)
// callers: [adc5_gen3_probe, adc5_gen3_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00109140 size=1
// signature: undefined cancel_work_sync(void)
// callers: [adc5_gen3_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00109148 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [adc5_gen3_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_minidump_unregister @ 00109150 size=1
// signature: undefined thermal_minidump_unregister(void)
// callers: [adc5_gen3_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_minidump_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00109158 size=1
// signature: undefined complete(void)
// callers: [adc5_gen3_isr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00109168 size=1
// signature: undefined queue_work_on(void)
// callers: [adc5_gen3_isr, tm_handler_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00109170 size=1
// signature: undefined ___ratelimit(void)
// callers: [adc5_gen3_isr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 00109178 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [tm_handler_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// adc_tm_scale_therm_voltage_100k_gen3 @ 00109180 size=1
// signature: undefined adc_tm_scale_therm_voltage_100k_gen3(void)
// callers: [adc_tm5_gen3_set_trip_temp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void adc_tm_scale_therm_voltage_100k_gen3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



