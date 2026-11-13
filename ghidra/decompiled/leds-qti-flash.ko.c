// Decompiled by Ghidra 12.2
// Program: leds-qti-flash.ko
// Image base: 00100000

//------------------------------------------------------------
// qti_flash_led_set_param @ 0010069c size=192
// signature: undefined qti_flash_led_set_param(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_led_set_param(undefined8 *param_1,long param_2,long param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  __rcu_read_lock();
  puVar3 = param_1 + 5;
  do {
    puVar3 = (undefined8 *)*puVar3;
    if (puVar3 == param_1 + 5) {
      __rcu_read_unlock();
      goto LAB_00100720;
    }
    iVar1 = strcmp((char *)puVar3[-0x1c],(char *)*param_1);
  } while (iVar1 != 0);
  __rcu_read_unlock();
  if (puVar3 == (undefined8 *)0x150) {
LAB_00100720:
    _printk(&DAT_00103b3b,"qti_flash_led_set_param",*param_1);
    uVar2 = 0xffffffea;
  }
  else if (param_2 == 0 && param_3 == 0) {
    _printk(&DAT_00103d87,"qti_flash_led_set_param");
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    puVar3[0x1d] = param_2;
    puVar3[0x1e] = param_3;
  }
  return uVar2;
}



//------------------------------------------------------------
// qti_flash_led_prepare @ 00100760 size=260
// signature: undefined qti_flash_led_prepare(void)
// callers: []
//------------------------------------------------------------

int qti_flash_led_prepare(undefined8 *param_1,uint param_2,long param_3)

{
  int iVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  
  if (param_1 == (undefined8 *)0x0) {
    puVar2 = &DAT_001044bb;
LAB_00100830:
    _printk(puVar2,"qti_flash_led_prepare");
    iVar1 = -0x16;
  }
  else {
    __rcu_read_lock();
    puVar3 = param_1 + 5;
    do {
      puVar3 = (undefined8 *)*puVar3;
      if (puVar3 == param_1 + 5) {
        __rcu_read_unlock();
        goto LAB_00100808;
      }
      iVar1 = strcmp((char *)puVar3[-0x1c],(char *)*param_1);
    } while (iVar1 != 0);
    __rcu_read_unlock();
    if (puVar3 == (undefined8 *)0x150) {
LAB_00100808:
      _printk(&DAT_00103b3b,"qti_flash_led_prepare",*param_1);
      return -0x13;
    }
    if ((param_2 >> 2 & 1) != 0) {
      if (param_3 == 0) {
        puVar2 = &DAT_00103f29;
        goto LAB_00100830;
      }
      iVar1 = qti_flash_led_get_max_avail_current(puVar3[-0x2b],param_3);
      if (iVar1 < 0) {
        _printk(&DAT_001037e8,"qti_flash_led_prepare",iVar1);
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// qti_flash_led_get_max_avail_current @ 00100864 size=1172
// signature: undefined qti_flash_led_get_max_avail_current(void)
// callers: [qti_flash_led_prepare, qti_flash_led_max_current_show]
//------------------------------------------------------------

int qti_flash_led_get_max_avail_current(long param_1,int *param_2)

{
  long lVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  int iVar4;
  long lVar5;
  undefined *puVar6;
  char *pcVar7;
  uint uVar8;
  undefined4 uVar9;
  ulong uVar10;
  int *piVar11;
  int iVar12;
  long lVar13;
  ulong uVar14;
  long lVar15;
  uint uVar16;
  ulong local_48;
  uint local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if ((*(char *)(param_1 + 0x61) != '\0') || (*(char *)(param_1 + 99) != '\0')) {
    iVar12 = 2000;
LAB_001008a0:
    iVar4 = 0;
    *(int *)(param_1 + 0x4c) = iVar12;
    goto LAB_001008a8;
  }
  local_3c = 0;
  local_48 = 0;
  if (*(long *)(param_1 + 0x20) == 0) {
    lVar5 = power_supply_get_by_name("battery");
    *(long *)(param_1 + 0x20) = lVar5;
    if (lVar5 != 0) goto LAB_00100900;
    iVar12 = 2000;
LAB_00100b70:
    *param_2 = iVar12;
LAB_00100b74:
    uVar9 = 0;
    local_48 = local_48 & 0xffffffffffffff00;
    if ((*(char *)(param_1 + 0x5b) == '\a') && (uVar9 = 0x10, *(char *)(param_1 + 0x5a) != '\x01'))
    {
      uVar9 = 0x13;
    }
    iVar4 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x7a,7,uVar9,0,0,0
                      );
    if (iVar4 < 0) {
      iVar12 = *(ushort *)(param_1 + 0x58) + 0x7a;
LAB_00100c68:
      puVar6 = &DAT_0010357d;
      pcVar7 = "qti_flash_led_masked_write";
    }
    else {
      iVar4 = regmap_update_bits_base
                        (*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x78,7,0x30,0,0,
                         0);
      if (iVar4 < 0) {
        iVar12 = *(ushort *)(param_1 + 0x58) + 0x78;
        goto LAB_00100c68;
      }
      iVar4 = regmap_bulk_read(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 7,
                               &local_48,1);
      if (-1 < iVar4) {
        if (((byte)local_48 >> 5 & 1) == 0) {
          if (((byte)local_48 >> 4 & 1) != 0) {
            piVar11 = (int *)(param_1 + 0x54);
            goto LAB_00100c1c;
          }
        }
        else {
          piVar11 = (int *)(param_1 + 0x50);
LAB_00100c1c:
          iVar12 = *piVar11;
          if (iVar12 != 0) {
            iVar4 = *param_2;
            if (iVar12 <= *param_2) {
              iVar4 = iVar12;
            }
            *param_2 = iVar4;
          }
        }
        iVar12 = *param_2;
        goto LAB_001008a0;
      }
      puVar6 = &DAT_001038b4;
      pcVar7 = "qti_flash_led_read";
      iVar12 = *(ushort *)(param_1 + 0x58) + 7;
    }
    _printk(puVar6,pcVar7,iVar12,iVar4);
    puVar6 = &DAT_0010353a;
  }
  else {
LAB_00100900:
    iVar4 = qti_battery_charger_get_prop("battery",0,&local_3c);
    if (iVar4 < 0) {
      puVar6 = &DAT_00103a23;
      goto LAB_00100cc8;
    }
    if (local_3c == 0) {
      *param_2 = 2000;
      *(undefined1 *)(param_1 + 0x62) = 1;
      goto LAB_00100b74;
    }
    iVar4 = power_supply_get_property(*(undefined8 *)(param_1 + 0x20),0xe,&local_48);
    if (iVar4 < 0) {
      puVar6 = &DAT_001044e1;
    }
    else {
      iVar12 = (int)local_48;
      lVar5 = (long)(int)local_48;
      iVar4 = power_supply_get_property(*(undefined8 *)(param_1 + 0x20),0x11,&local_48);
      if (-1 < iVar4) {
        if (*(char *)(param_1 + 0x5b) == '\a') {
          qti_flash_led_get_voltage_headroom_hdrm_map = &pm8350c_map;
        }
        if (*(int *)(param_1 + 0x2c) == 0) {
LAB_00100a34:
          uVar8 = 400;
        }
        else {
          iVar4 = 0;
          uVar8 = 0;
          do {
            if (*(char *)(*(long *)(param_1 + 0x10) + (long)iVar4 * 0x228 + 0x220) != '\0') {
              if (*(char *)(param_1 + 0x5b) == '\a') {
                uVar2 = *(uint *)(*(long *)(param_1 + 0x10) + (long)iVar4 * 0x228 + 0x20c);
                if (*qti_flash_led_get_voltage_headroom_hdrm_map < uVar2) {
                  uVar16 = 400;
                }
                else {
                  uVar16 = (uint)qti_flash_led_get_voltage_headroom_hdrm_map[1];
                }
                if (uVar2 <= qti_flash_led_get_voltage_headroom_hdrm_map[2]) {
                  uVar16 = (uint)qti_flash_led_get_voltage_headroom_hdrm_map[3];
                }
                if (uVar2 <= qti_flash_led_get_voltage_headroom_hdrm_map[4]) {
                  uVar16 = (uint)qti_flash_led_get_voltage_headroom_hdrm_map[5];
                }
                if (uVar2 <= qti_flash_led_get_voltage_headroom_hdrm_map[6]) {
                  uVar16 = (uint)qti_flash_led_get_voltage_headroom_hdrm_map[7];
                }
              }
              else {
                uVar16 = 400;
              }
              if (uVar8 <= uVar16) {
                uVar8 = uVar16;
              }
            }
            iVar4 = iVar4 + 1;
          } while (*(int *)(param_1 + 0x2c) != iVar4);
          if (uVar8 == 0) goto LAB_00100a34;
        }
        lVar15 = (long)(int)local_3c;
        uVar16 = local_3c;
        if ((int)local_3c < 0) {
          uVar16 = local_3c + 1;
        }
        lVar13 = (long)((ulong)uVar16 << 0x20) >> 0x21;
        lVar1 = -lVar13;
        if (iVar12 < 0x2b7cd1 != 0 < lVar15) {
          lVar1 = lVar13;
        }
        lVar13 = 0;
        if (lVar15 != 0) {
          lVar13 = (lVar1 + (long)iVar12 * 1000000 + -2850000000000) / lVar15;
        }
        if (lVar13 < 4500000) {
          lVar5 = 0x98e2cb40;
          lVar13 = lVar13 - -(int)local_48;
        }
        else {
          lVar13 = (long)((int)local_48 + 4500000);
          if ((int)local_3c < 1) {
            uVar14 = ((long)(int)local_3c * 4500000 + -500000) / 1000000;
          }
          else {
            uVar14 = ((long)(int)local_3c * 4500000 + 500000U) / 1000000;
          }
          lVar5 = (lVar5 - uVar14) * 900;
        }
        lVar15 = (long)(int)uVar8 * 1000;
        if (lVar15 < -199999) {
          lVar15 = -200000;
        }
        uVar10 = lVar15 * 1000 + 3500000000;
        uVar14 = -(uVar10 >> 1);
        if (0 < lVar13 * lVar5) {
          uVar14 = uVar10 >> 1;
        }
        lVar15 = 0;
        if (uVar10 != 0) {
          lVar15 = (long)(uVar14 + lVar13 * lVar5) / (long)uVar10;
        }
        lVar5 = -500;
        if (0 < lVar15) {
          lVar5 = 500;
        }
        auVar3 = SEXT816(lVar5 + lVar15) * SEXT816(0x20c49ba5e353f7cf);
        iVar12 = (int)(auVar3._8_8_ >> 7) - (auVar3._12_4_ >> 0x1f);
        if (1999 < iVar12) {
          iVar12 = 2000;
        }
        goto LAB_00100b70;
      }
      puVar6 = &DAT_001040c8;
    }
LAB_00100cc8:
    _printk(puVar6,"qti_flash_led_calc_max_avail_current",iVar4);
    puVar6 = &DAT_00104209;
  }
  _printk(puVar6,"qti_flash_led_get_max_avail_current",iVar4);
LAB_001008a8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qti_flash_led_probe @ 00100cfc size=4132
// signature: undefined qti_flash_led_probe(void)
// callers: []
//------------------------------------------------------------

int qti_flash_led_probe(long param_1)

{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  byte bVar4;
  char cVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  undefined *puVar13;
  long lVar14;
  char *pcVar15;
  long lVar16;
  bool bVar17;
  long lVar18;
  undefined8 *puVar19;
  uint uVar20;
  long lVar21;
  undefined8 *puVar22;
  ulong uVar23;
  long lVar24;
  int iVar25;
  undefined4 local_9c;
  char *local_98;
  uint local_8c;
  char *local_88;
  ulong local_80 [2];
  undefined4 local_70;
  long local_68;
  
  lVar21 = sp_el0;
  local_68 = *(long *)(lVar21 + 0x638);
  lVar21 = *(long *)(param_1 + 0x2f8);
  plVar10 = (long *)devm_kmalloc(param_1 + 0x10,0x68,0xdc0);
  if (plVar10 == (long *)0x0) {
    iVar6 = -0xc;
    goto LAB_00101c6c;
  }
  lVar11 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
  plVar10[1] = lVar11;
  if (lVar11 == 0) {
    puVar13 = &DAT_00103a5d;
  }
  else {
    cVar5 = of_device_get_match_data(param_1 + 0x10);
    *(char *)((long)plVar10 + 0x5c) = cVar5;
    if (cVar5 != '\0') {
      *plVar10 = param_1;
      *(undefined4 *)(plVar10 + 5) = 0;
      local_70 = 0;
      local_80[0] = 0;
      local_80[1] = 0;
      local_98 = (char *)0x0;
      local_9c = 0;
      iVar6 = of_property_read_variable_u32_array(lVar21,&DAT_00103ac3,&local_9c,1,0);
      if (iVar6 < 0) {
        uVar12 = *(undefined8 *)(lVar21 + 0x10);
        puVar13 = &DAT_00103ac7;
LAB_00101c44:
        _printk(puVar13,"qti_flash_led_register_device",uVar12,iVar6);
        goto LAB_00101c54;
      }
      *(short *)(plVar10 + 0xb) = (short)local_9c;
      lVar11 = devm_kmalloc(*plVar10 + 0x10,(ulong)*(byte *)((long)plVar10 + 0x5c) << 2,0xdc0);
      plVar10[7] = lVar11;
      if (lVar11 != 0) {
        if (*(char *)((long)plVar10 + 0x5c) != '\0') {
          uVar23 = 0;
          do {
            *(undefined4 *)(plVar10[7] + uVar23 * 4) = 0xffffffea;
            uVar7 = of_get_named_gpio_flags(lVar21,"hw-strobe-gpios",uVar23 & 0xffffffff,0);
            if (-1 < (int)uVar7) {
              if (0x1ff < uVar7) {
                _printk(&DAT_001034bc,"qti_flash_led_register_device");
                goto LAB_00101be0;
              }
              *(uint *)(plVar10[7] + uVar23 * 4) = uVar7;
              scnprintf(local_80,0x14,"hw_strobe_gpio%d",uVar23 & 0xffffffff);
              iVar6 = devm_gpio_request_one
                                (*plVar10 + 0x10,*(undefined4 *)(plVar10[7] + uVar23 * 4),0,local_80
                                );
              if (iVar6 < 0) {
                puVar13 = &DAT_00103956;
                goto LAB_00101a0c;
              }
              uVar12 = gpio_to_desc(*(undefined4 *)(plVar10[7] + uVar23 * 4));
              gpiod_direction_output_raw(uVar12,0);
            }
            uVar23 = uVar23 + 1;
          } while (uVar23 < *(byte *)((long)plVar10 + 0x5c));
        }
        lVar11 = of_find_property(lVar21,"qcom,secure-vm",0);
        *(bool *)((long)plVar10 + 0x61) = lVar11 != 0;
        uVar8 = of_irq_get_byname(lVar21,"all-ramp-up-done-irq");
        *(undefined4 *)(plVar10 + 8) = uVar8;
        uVar8 = of_irq_get_byname(lVar21,"all-ramp-down-done-irq");
        *(undefined4 *)((long)plVar10 + 0x44) = uVar8;
        uVar8 = of_irq_get_byname(lVar21,"led-fault-irq");
        *(undefined4 *)(plVar10 + 9) = uVar8;
        lVar11 = of_get_next_available_child(lVar21,0);
        if (lVar11 == 0) {
          uVar23 = (ulong)*(uint *)((long)plVar10 + 0x2c);
          if (*(uint *)((long)plVar10 + 0x2c) == 0) goto LAB_00101a20;
        }
        else {
          bVar17 = false;
          do {
            iVar6 = of_property_read_string(lVar11,"label",&local_98);
            pcVar15 = local_98;
            if (iVar6 < 0) goto LAB_00101a00;
            iVar6 = strcmp("flash",local_98);
            if ((iVar6 != 0) && (iVar6 = strcmp("torch",pcVar15), iVar6 != 0)) {
              iVar6 = strcmp("indicator",pcVar15);
              if (iVar6 == 0) {
                iVar6 = *(int *)((long)plVar10 + 0x2c);
                goto LAB_00100f4c;
              }
              iVar6 = strcmp("switch",pcVar15);
              if (iVar6 == 0) {
                *(int *)(plVar10 + 6) = (int)plVar10[6] + 1;
                goto LAB_00100f54;
              }
              _printk(&DAT_001039e0,"qti_flash_led_register_device",pcVar15);
LAB_00101be0:
              iVar6 = -0x16;
              goto LAB_00101c54;
            }
            iVar6 = *(int *)((long)plVar10 + 0x2c);
            bVar17 = true;
LAB_00100f4c:
            *(int *)((long)plVar10 + 0x2c) = iVar6 + 1;
LAB_00100f54:
            lVar11 = of_get_next_available_child(lVar21,lVar11);
          } while (lVar11 != 0);
          uVar23 = (ulong)*(uint *)((long)plVar10 + 0x2c);
          if (*(uint *)((long)plVar10 + 0x2c) == 0) {
LAB_00101a20:
            _printk(&DAT_00103fc0,"qti_flash_led_register_device");
            iVar6 = -10;
            goto LAB_00101c54;
          }
          if ((bVar17) && ((int)plVar10[6] == 0)) {
            _printk(&DAT_001037a2,"qti_flash_led_register_device");
            iVar6 = -0x13;
            goto LAB_00101c54;
          }
        }
        lVar11 = devm_kmalloc(*plVar10 + 0x10,uVar23 * 0x228,0xdc0);
        plVar10[2] = lVar11;
        if (lVar11 != 0) {
          if (*(uint *)(plVar10 + 6) != 0) {
            lVar11 = devm_kmalloc(*plVar10 + 0x10,(ulong)*(uint *)(plVar10 + 6) * 600,0xdc0);
            plVar10[3] = lVar11;
            if (lVar11 == 0) goto LAB_001019bc;
          }
          lVar11 = of_get_next_available_child(lVar21,0);
          if (lVar11 != 0) {
            iVar1 = 0;
            iVar9 = 0;
            do {
              iVar6 = of_property_read_string(lVar11,"label",&local_98);
              pcVar15 = local_98;
              if (iVar6 < 0) goto LAB_00101a00;
              iVar6 = strcmp("flash",local_98);
              if (((iVar6 == 0) || (iVar6 = strcmp("torch",pcVar15), iVar6 == 0)) ||
                 (iVar6 = strcmp("indicator",pcVar15), iVar6 == 0)) {
                lVar18 = plVar10[2];
                puVar22 = (undefined8 *)(lVar18 + (long)iVar9 * 0x228);
                local_88 = (char *)0x0;
                local_8c = 0;
                puVar19 = puVar22 + 1;
                iVar6 = of_property_read_string(lVar11,"qcom,led-name",puVar19);
                if (iVar6 < 0) {
                  puVar13 = &DAT_00104406;
LAB_00101c20:
                  _printk(puVar13,"register_flash_device");
                }
                else {
                  iVar6 = of_property_read_string(lVar11,"label",&local_88);
                  pcVar15 = local_88;
                  if (iVar6 < 0) {
                    puVar13 = &DAT_00103987;
                    goto LAB_00101c20;
                  }
                  iVar6 = strcmp(local_88,"flash");
                  if (iVar6 != 0) {
                    iVar6 = strcmp(pcVar15,"torch");
                    if (iVar6 == 0) {
                      uVar8 = 2;
                      goto LAB_00101424;
                    }
                    iVar6 = strcmp(pcVar15,"indicator");
                    if (iVar6 == 0) {
                      uVar8 = 3;
                      goto LAB_00101424;
                    }
                    _printk(&DAT_00103a8d,"register_flash_device",pcVar15);
LAB_00101134:
                    iVar25 = iVar9 + 1;
                    lVar18 = plVar10[2] + (long)iVar9 * 0x228;
LAB_00101144:
                    *(long *)(*(long *)(lVar18 + 0x58) + 0x2e8) = lVar11;
                    goto LAB_0010114c;
                  }
                  uVar8 = 1;
LAB_00101424:
                  lVar14 = lVar18 + (long)iVar9 * 0x228;
                  *(undefined4 *)(lVar14 + 0x21c) = uVar8;
                  iVar6 = of_property_read_variable_u32_array(lVar11,"qcom,id",&local_8c,1,0);
                  if (iVar6 < 0) {
                    puVar13 = &DAT_00104248;
                    goto LAB_00101c20;
                  }
                  lVar24 = lVar18 + (long)iVar9 * 0x228;
                  piVar3 = (int *)(lVar14 + 0x21c);
                  *(char *)(lVar24 + 0x215) = (char)local_8c;
                  iVar6 = of_property_read_string(lVar11,"qcom,default-led-trigger",lVar24 + 0x78);
                  if ((iVar6 < 0) && (*piVar3 != 3)) {
                    puVar13 = &DAT_0010382b;
                    goto LAB_00101c20;
                  }
                  iVar6 = of_property_read_variable_u32_array(lVar11,"qcom,ires-ua",&local_8c,1,0);
                  uVar7 = local_8c;
                  if (iVar6 < 0) {
                    puVar13 = &DAT_0010455b;
LAB_00101b60:
                    _printk(puVar13,"register_flash_device",iVar6);
                  }
                  else {
                    iVar6 = -0x16;
                    if (local_8c == 0x30d4) {
                      iVar6 = 1;
                    }
                    iVar25 = 0;
                    if (local_8c != 5000) {
                      iVar25 = iVar6;
                    }
                    if (iVar25 < 0) {
                      _printk(&DAT_00103b83,"register_flash_device",local_8c);
                      if (uVar7 == 0x30d4) goto LAB_00101134;
                    }
                    else {
                      lVar14 = lVar18 + (long)iVar9 * 0x228;
                      *(uint *)(lVar14 + 0x200) = local_8c;
                      *(uint *)(lVar14 + 0x204) = local_8c;
                      *(char *)(lVar14 + 0x217) = (char)iVar25;
                      *(char *)(lVar14 + 0x216) = (char)iVar25;
                      iVar6 = of_property_read_variable_u32_array
                                        (lVar11,"qcom,max-current-ma",&local_8c,1,0);
                      if (iVar6 < 0) {
                        puVar13 = &DAT_00103b00;
                        goto LAB_00101b60;
                      }
                      iVar6 = *piVar3;
                      if ((iVar6 == 1) && (0x5dc < local_8c)) {
                        puVar13 = &DAT_00104437;
                      }
                      else if ((iVar6 == 2) && (500 < local_8c)) {
                        puVar13 = &DAT_0010446f;
                      }
                      else {
                        if ((iVar6 != 3) || (local_8c < 0x65)) {
                          lVar24 = lVar18 + (long)iVar9 * 0x228;
                          *(uint *)(lVar24 + 0x210) = local_8c;
                          *(uint *)(lVar24 + 0x14) = local_8c;
                          iVar6 = of_property_read_variable_u32_array
                                            (lVar11,"qcom,duration-ms",&local_8c,1,0);
                          pcVar15 = (char *)(lVar24 + 0x219);
                          *(undefined1 *)(lVar24 + 0x219) = 0;
                          cVar5 = (char)((local_8c + 5 & 0xffff) / 10) + -1;
                          if ((((local_8c >= 0x501 || local_8c < 9) || local_8c == 9) || iVar6 == -1
                              ) || ((local_8c < 0x501 && local_8c >= 9) && local_8c != 9) &&
                                   iVar6 < -1) {
                            cVar5 = '\x13';
                          }
                          *(char *)(lVar24 + 0x214) = cVar5;
                          iVar6 = of_property_read_variable_u32_array
                                            (lVar11,"qcom,strobe-sel",&local_8c,1,0);
                          if (-1 < iVar6) {
                            *pcVar15 = (char)local_8c;
                          }
                          iVar6 = *piVar3;
                          if (iVar6 == 3) {
                            *pcVar15 = '\0';
                            lVar16 = lVar18 + (long)iVar9 * 0x228;
                            *puVar22 = plVar10;
                            *(code **)(lVar16 + 0x28) = qti_flash_led_brightness_set;
                            *(undefined2 *)(lVar16 + 0x220) = 0;
                            *(code **)(lVar16 + 0x38) = qti_flash_led_brightness_get;
                          }
                          else {
                            if (*pcVar15 == '\x01') {
                              iVar6 = of_property_read_variable_u32_array
                                                (lVar11,"qcom,strobe-config",&local_8c,1,0);
                              if (iVar6 < 0) {
                                puVar13 = &DAT_00103bbe;
                                goto LAB_00101c20;
                              }
                              *puVar22 = plVar10;
                              lVar16 = lVar18 + (long)iVar9 * 0x228;
                              iVar6 = *piVar3;
                              *(char *)(lVar16 + 0x218) = (char)local_8c;
                              *(undefined2 *)(lVar16 + 0x220) = 0;
                              *(code **)(lVar16 + 0x28) = qti_flash_led_brightness_set;
                              *(code **)(lVar16 + 0x38) = qti_flash_led_brightness_get;
                              if (iVar6 == 3) goto LAB_001010b8;
                            }
                            else {
                              *puVar22 = plVar10;
                              lVar16 = lVar18 + (long)iVar9 * 0x228;
                              *(code **)(lVar16 + 0x28) = qti_flash_led_brightness_set;
                              *(undefined2 *)(lVar16 + 0x220) = 0;
                              *(code **)(lVar16 + 0x38) = qti_flash_led_brightness_get;
                            }
                            *(undefined ***)(lVar18 + (long)iVar9 * 0x228 + 0x1b0) = &flash_ops;
                            if (iVar6 == 1) {
                              lVar16 = lVar18 + (long)iVar9 * 0x228;
                              *(undefined4 *)(lVar16 + 0x18) = 0x40000;
                              *(code **)(lVar16 + 0x30) = qti_flash_brightness_set_blocking;
                            }
                          }
LAB_001010b8:
                          lVar18 = lVar18 + (long)iVar9 * 0x228;
                          iVar6 = *(int *)(lVar14 + 0x200);
                          uVar8 = *(undefined4 *)(lVar24 + 0x210);
                          *(undefined4 *)(lVar18 + 0x1b8) = 0;
                          *(undefined4 *)(lVar18 + 0x1bc) = uVar8;
                          *(undefined4 *)(lVar18 + 0x1c0) = 1;
                          *(uint *)(lVar18 + 0x1c4) = (iVar6 + 500U) / 1000;
                          *(undefined8 *)(lVar18 + 0x1c8) = 0x13880000000000;
                          *(undefined8 *)(lVar18 + 0x1d0) = 0x30d4000002710;
                          iVar6 = devm_led_classdev_flash_register_ext(*plVar10 + 0x10,puVar19,0);
                          if (-1 < iVar6) goto LAB_00101134;
                          _printk(&DAT_00103df2,"register_flash_device",*puVar19);
                          goto LAB_00101c2c;
                        }
                        puVar13 = &DAT_001036ef;
                      }
                      _printk(puVar13,"register_flash_device");
                    }
                    iVar6 = -0x16;
                  }
                }
LAB_00101c2c:
                puVar13 = &DAT_001035d8;
                lVar21 = plVar10[2] + (long)iVar9 * 0x228;
LAB_00101c40:
                uVar12 = *(undefined8 *)(lVar21 + 8);
                goto LAB_00101c44;
              }
              iVar6 = strcmp("switch",pcVar15);
              iVar25 = iVar9;
              if (iVar6 == 0) {
                lVar18 = plVar10[3];
                puVar22 = (undefined8 *)(lVar18 + (long)iVar1 * 600);
                puVar19 = puVar22 + 1;
                iVar6 = of_property_read_string(lVar11,"qcom,led-name",puVar19);
                if (iVar6 < 0) {
                  puVar13 = &DAT_00103ff1;
LAB_00101cd4:
                  _printk(puVar13,"register_switch_device",iVar6);
                }
                else {
                  iVar6 = of_property_read_string
                                    (lVar11,"qcom,default-led-trigger",
                                     lVar18 + (long)iVar1 * 600 + 0x78);
                  if (iVar6 < 0) {
                    puVar13 = &DAT_0010428f;
                    goto LAB_00101cd4;
                  }
                  puVar2 = (uint *)(lVar18 + (long)iVar1 * 600 + 0x250);
                  iVar6 = of_property_read_variable_u32_array(lVar11,"qcom,led-mask",puVar2,1,0);
                  if (iVar6 < 0) {
                    puVar13 = &DAT_0010348c;
                    goto LAB_00101cd4;
                  }
                  uVar7 = *puVar2;
                  if ((uVar7 != 0) &&
                     (uVar23 = 0xffffffffffffffff >>
                               ((ulong)-(uint)*(byte *)((long)plVar10 + 0x5c) & 0x3f),
                     uVar7 <= uVar23)) {
                    if (uVar7 < uVar23) {
                      *(undefined1 *)(plVar10 + 0xc) = 1;
                    }
                    lVar14 = of_find_property(lVar11,"qcom,symmetry-en",0);
                    lVar24 = lVar18 + (long)iVar1 * 600;
                    *(undefined8 *)(lVar24 + 0x240) = 0;
                    *(bool *)(lVar24 + 0x255) = lVar14 != 0;
                    *(undefined8 *)(lVar24 + 0x248) = 0;
                    hrtimer_init(lVar24 + 0x1b0,1,1);
                    hrtimer_init(lVar24 + 0x1f8,1,1);
                    *puVar22 = plVar10;
                    *(code **)(lVar24 + 0x1d8) = on_timer_function;
                    *(code **)(lVar24 + 0x220) = off_timer_function;
                    *(code **)(lVar24 + 0x28) = qti_flash_led_switch_brightness_set;
                    *(code **)(lVar24 + 0x38) = qti_flash_led_brightness_get;
                    iVar6 = devm_led_classdev_register_ext(*plVar10 + 0x10,puVar19,0);
                    if (iVar6 < 0) {
                      _printk(&DAT_001043b9,"register_switch_device",*puVar19);
                      goto LAB_00101d04;
                    }
                    puVar19 = (undefined8 *)(lVar18 + (long)iVar1 * 600 + 0x58);
                    iVar9 = sysfs_create_file_ns(*puVar19,&qti_flash_led_attrs,0);
                    if (iVar9 < 0) {
                      lVar18 = 0;
                      iVar6 = iVar9;
LAB_00101728:
                      _printk(&DAT_00103ef3,"register_switch_device",iVar6);
                      sysfs_remove_file_ns(*puVar19,&qti_flash_led_attrs + lVar18 * 4,0);
                      if ((-1 < iVar9) &&
                         (sysfs_remove_file_ns(*puVar19,&qti_flash_led_attrs + (lVar18 + -1) * 4,0),
                         lVar18 + -1 != 0)) {
                        sysfs_remove_file_ns(*puVar19,lVar18 * 0x20 + 0x104988,0);
                      }
                      if (iVar6 < 0) goto LAB_00101d04;
                    }
                    else {
                      iVar6 = sysfs_create_file_ns(*puVar19,&PTR_s_on_time_001049e8,0);
                      if (iVar6 < 0) {
                        lVar18 = 1;
                        goto LAB_00101728;
                      }
                      iVar6 = sysfs_create_file_ns(*puVar19,&PTR_s_off_time_00104a08,0);
                      if (iVar6 < 0) {
                        lVar18 = 2;
                        goto LAB_00101728;
                      }
                    }
                    lVar18 = plVar10[3] + (long)iVar1 * 600;
                    iVar1 = iVar1 + 1;
                    goto LAB_00101144;
                  }
                  _printk(&DAT_0010388d,"register_switch_device");
                  iVar6 = -0x16;
                }
LAB_00101d04:
                puVar13 = &DAT_00103c76;
                lVar21 = plVar10[3] + (long)iVar1 * 600;
                goto LAB_00101c40;
              }
LAB_0010114c:
              lVar11 = of_get_next_available_child(lVar21,lVar11);
              iVar9 = iVar25;
            } while (lVar11 != 0);
          }
          lVar21 = of_find_property(lVar21,"qcom,external-led",0);
          if (lVar21 != 0) {
            *(undefined1 *)((long)plVar10 + 99) = 1;
          }
          local_80[0] = local_80[0] & 0xffffffffffffff00;
          iVar6 = regmap_bulk_read(plVar10[1],(short)plVar10[0xb],local_80,1);
          if (iVar6 < 0) {
            uVar7 = (uint)*(ushort *)(plVar10 + 0xb);
LAB_00101a64:
            puVar13 = &DAT_001038b4;
            pcVar15 = "qti_flash_led_read";
            goto LAB_00101aac;
          }
          *(undefined1 *)((long)plVar10 + 0x5a) = (undefined1)local_80[0];
          iVar6 = regmap_bulk_read(plVar10[1],*(ushort *)(plVar10 + 0xb) + 5,local_80,1);
          if (iVar6 < 0) {
            uVar7 = *(ushort *)(plVar10 + 0xb) + 5;
            goto LAB_00101a64;
          }
          *(undefined1 *)((long)plVar10 + 0x5b) = (undefined1)local_80[0];
          if (*(int *)((long)plVar10 + 0x2c) != 0) {
            uVar20 = 0;
            do {
              uVar7 = (uint)*(byte *)(plVar10[2] + (long)(int)uVar20 * 0x228 + 0x215);
              iVar1 = uVar7 + 0x3e;
              iVar6 = regmap_update_bits_base
                                (plVar10[1],(uint)*(ushort *)(plVar10 + 0xb) + iVar1,0x80,0,0,0,0);
              if (iVar6 < 0) {
                uVar7 = (uint)*(ushort *)(plVar10 + 0xb) + iVar1;
                goto LAB_00101a9c;
              }
              lVar21 = plVar10[2] + (long)(int)uVar20 * 0x228;
              bVar4 = *(char *)(lVar21 + 0x219) << 2 | *(char *)(lVar21 + 0x218) << 4;
              local_80[0] = CONCAT71(local_80[0]._1_7_,bVar4);
              if (*(char *)((long)plVar10 + 99) == '\0') {
                uVar12 = 0x74;
              }
              else {
                uVar12 = 0x75;
                local_80[0] = CONCAT71(local_80[0]._1_7_,bVar4) | 1;
                bVar4 = bVar4 | 1;
              }
              uVar7 = uVar7 + 0x4a;
              iVar6 = regmap_update_bits_base
                                (plVar10[1],*(ushort *)(plVar10 + 0xb) + uVar7,uVar12,bVar4,0,0,0);
              if (iVar6 < 0) goto LAB_00101a3c;
              uVar20 = uVar20 + 1;
            } while (uVar20 < *(uint *)((long)plVar10 + 0x2c));
          }
          if (*(char *)((long)plVar10 + 99) != '\0') {
            lVar21 = 0;
            do {
              uVar7 = (uint)*(ushort *)((long)&ext_setup_reg_list + lVar21);
              iVar6 = regmap_update_bits_base
                                (plVar10[1],*(ushort *)(plVar10 + 0xb) + uVar7,
                                 (&DAT_001048ab)[lVar21],(&DAT_001048aa)[lVar21],0,0,0);
              if (iVar6 < 0) goto LAB_00101a3c;
              lVar21 = lVar21 + 4;
            } while (lVar21 != 0x28);
          }
          *(undefined4 *)((long)plVar10 + 0x54) = 500;
          *(undefined8 *)((long)plVar10 + 0x4c) = 0xc8000007d0;
          if (((int)plVar10[8] < 0) ||
             (iVar6 = devm_request_threaded_irq
                                (*plVar10 + 0x10,(int)plVar10[8],0,qti_flash_led_irq_handler,0x2000,
                                 "flash_all_ramp_up",plVar10), -1 < iVar6)) {
            if ((*(int *)((long)plVar10 + 0x44) < 0) ||
               (iVar6 = devm_request_threaded_irq
                                  (*plVar10 + 0x10,*(int *)((long)plVar10 + 0x44),0,
                                   qti_flash_led_irq_handler,0x2000,"flash_all_ramp_down",plVar10),
               -1 < iVar6)) {
              if (((int)plVar10[9] < 0) ||
                 (iVar6 = devm_request_threaded_irq
                                    (*plVar10 + 0x10,(int)plVar10[9],0,qti_flash_led_irq_handler,
                                     0x2000,"flash_fault",plVar10), -1 < iVar6)) {
                iVar6 = 0;
                *(long **)(param_1 + 0xa8) = plVar10;
                goto LAB_00101c6c;
              }
              uVar8 = (undefined4)plVar10[9];
              puVar13 = &DAT_00103733;
            }
            else {
              uVar8 = *(undefined4 *)((long)plVar10 + 0x44);
              puVar13 = &DAT_00103692;
            }
          }
          else {
            uVar8 = (undefined4)plVar10[8];
            puVar13 = &DAT_00103e99;
          }
          _printk(puVar13,"qti_flash_led_register_interrupts",uVar8,iVar6);
          puVar13 = &DAT_00103f57;
          goto LAB_00101c5c;
        }
      }
LAB_001019bc:
      iVar6 = -0xc;
      goto LAB_00101c54;
    }
    puVar13 = &DAT_0010433b;
  }
  _printk(puVar13,"qti_flash_led_probe");
  iVar6 = -0x16;
  goto LAB_00101c6c;
LAB_00101a00:
  puVar13 = &DAT_00103f91;
LAB_00101a0c:
  _printk(puVar13,"qti_flash_led_register_device",iVar6);
LAB_00101c54:
  puVar13 = &DAT_00104054;
  goto LAB_00101c5c;
LAB_00101a3c:
  uVar7 = *(ushort *)(plVar10 + 0xb) + uVar7;
LAB_00101a9c:
  puVar13 = &DAT_0010357d;
  pcVar15 = "qti_flash_led_masked_write";
LAB_00101aac:
  _printk(puVar13,pcVar15,uVar7,iVar6);
  puVar13 = &DAT_001040ff;
LAB_00101c5c:
  _printk(puVar13,"qti_flash_led_probe",iVar6);
LAB_00101c6c:
  lVar21 = sp_el0;
  if (*(long *)(lVar21 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qti_flash_led_remove @ 00101d24 size=172
// signature: undefined qti_flash_led_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_led_remove(long param_1)

{
  long lVar1;
  uint uVar2;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (*(long *)(lVar1 + 0x20) != 0) {
    power_supply_put();
  }
  if (*(int *)(lVar1 + 0x30) != 0) {
    uVar2 = 0;
    do {
      sysfs_remove_file_ns
                (*(undefined8 *)(*(long *)(lVar1 + 0x18) + (long)(int)uVar2 * 600 + 0x58),
                 &qti_flash_led_attrs,0);
      sysfs_remove_file_ns
                (*(undefined8 *)(*(long *)(lVar1 + 0x18) + (long)(int)uVar2 * 600 + 0x58),
                 &PTR_s_on_time_001049e8,0);
      sysfs_remove_file_ns
                (*(undefined8 *)(*(long *)(lVar1 + 0x18) + (long)(int)uVar2 * 600 + 0x58),
                 &PTR_s_off_time_00104a08,0);
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(lVar1 + 0x30));
  }
  return 0;
}



//------------------------------------------------------------
// qti_flash_led_brightness_set @ 00101dd4 size=260
// signature: undefined qti_flash_led_brightness_set(void)
// callers: [qti_flash_brightness_set, qti_flash_brightness_set_blocking]
//------------------------------------------------------------

void qti_flash_led_brightness_set(long param_1,undefined4 param_2)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + -8);
  uVar1 = *(uint *)(lVar6 + 0x2c);
  if (uVar1 != 0) {
    uVar5 = 0;
    lVar4 = *(long *)(lVar6 + 0x10);
    bVar2 = true;
    do {
      if (((*(char *)(lVar4 + (long)(int)uVar5 * 0x228 + 0x215) == *(char *)(param_1 + 0x20d)) &&
          (*(int *)(lVar4 + (long)(int)uVar5 * 0x228 + 0x21c) != *(int *)(param_1 + 0x214))) &&
         (*(char *)(lVar4 + (long)(int)uVar5 * 0x228 + 0x220) != '\0')) break;
      uVar5 = uVar5 + 1;
      bVar2 = uVar5 < uVar1;
    } while (uVar1 != uVar5);
    if (bVar2) {
      return;
    }
  }
  iVar3 = __qti_flash_led_brightness_set(param_1,param_2);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x200) = param_2;
    if (*(int *)(lVar6 + 0x30) != 0) {
      iVar3 = 0;
      lVar4 = *(long *)(lVar6 + 0x18);
      do {
        if ((*(char *)(lVar4 + (long)iVar3 * 600 + 0x255) != '\0') &&
           (*(char *)(lVar4 + (long)iVar3 * 600 + 0x254) != '\0')) {
          qti_flash_led_symmetry_config(lVar4 + (long)iVar3 * 600);
          return;
        }
        iVar3 = iVar3 + 1;
      } while (*(int *)(lVar6 + 0x30) != iVar3);
    }
  }
  return;
}



//------------------------------------------------------------
// qti_flash_led_brightness_get @ 00101edc size=8
// signature: undefined qti_flash_led_brightness_get(void)
// callers: []
//------------------------------------------------------------

undefined4 qti_flash_led_brightness_get(long param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



//------------------------------------------------------------
// qti_flash_brightness_set_blocking @ 00101ee8 size=32
// signature: undefined qti_flash_brightness_set_blocking(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_brightness_set_blocking(void)

{
  qti_flash_led_brightness_set();
  return 0;
}



//------------------------------------------------------------
// __qti_flash_led_brightness_set @ 00101f08 size=904
// signature: undefined __qti_flash_led_brightness_set(void)
// callers: [qti_flash_led_brightness_set, qti_flash_config_group_symmetry]
//------------------------------------------------------------

uint __qti_flash_led_brightness_set(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  code *pcVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  undefined *puVar10;
  char *pcVar11;
  ulong uVar12;
  undefined4 uVar13;
  long lVar14;
  byte local_5c [4];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  if (param_2 == 0) {
    param_2 = qti_flash_led_strobe
                        (*(undefined8 *)(param_1 + -8),0,
                         1L << ((ulong)*(byte *)(param_1 + 0x20d) & 0x3f),0);
    if (-1 < (int)param_2) {
      uVar7 = qti_flash_led_disable(param_1 + -8);
      if ((int)uVar7 < 0) {
        _printk(&DAT_00103e2b,"__qti_flash_led_brightness_set");
      }
      *(undefined4 *)(param_1 + 8) = 0;
      goto LAB_0010221c;
    }
    puVar10 = &DAT_00103613;
    uVar7 = param_2;
  }
  else {
    uVar7 = *(int *)(param_1 + 0x1f8) + 500;
    bVar5 = *(byte *)(param_1 + 0x20f);
    *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(param_1 + 0x1fc);
    *(byte *)(param_1 + 0x20e) = bVar5;
    uVar3 = uVar7 / 1000;
    if (uVar7 / 1000 <= param_2) {
      uVar3 = param_2;
    }
    if (*(uint *)(param_1 + 0x208) <= uVar3) {
      uVar3 = *(uint *)(param_1 + 0x208);
    }
    if (1 < (ulong)bVar5) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x102290);
      (*pcVar6)();
    }
    if (*(uint *)(&flash_led_max_ires_values + (ulong)bVar5 * 4) < uVar3) {
      uVar13 = 0x30d4;
      if (uVar3 < 0x281) {
        uVar13 = 5000;
      }
      *(undefined4 *)(param_1 + 0x1f8) = uVar13;
      *(bool *)(param_1 + 0x20f) = 0x280 < uVar3;
    }
    lVar14 = *(long *)(param_1 + -8);
    *(uint *)(param_1 + 0x204) = uVar3;
    bVar5 = *(byte *)(param_1 + 0x20d);
    *(uint *)(param_1 + 8) = uVar3;
    lVar2 = lVar14 + 0x28;
    uVar8 = _raw_spin_lock_irqsave(lVar2);
    uVar7 = (uint)(*(char *)(param_1 + 0x20e) == '\0') << (ulong)(*(byte *)(param_1 + 0x20d) & 0x1f)
    ;
    local_5c[0] = (byte)uVar7;
    uVar7 = regmap_update_bits_base
                      (*(undefined8 *)(lVar14 + 8),*(ushort *)(lVar14 + 0x58) + 0x49,
                       (uint)(1L << ((ulong)*(byte *)(param_1 + 0x20d) & 0x3f)) & 0xff,uVar7 & 0xff,
                       0,0,0);
    if ((int)uVar7 < 0) {
      iVar1 = *(ushort *)(lVar14 + 0x58) + 0x49;
LAB_001021c4:
      puVar10 = &DAT_0010357d;
      pcVar11 = "qti_flash_led_masked_write";
    }
    else {
      uVar7 = 0;
      uVar3 = *(uint *)(param_1 + 0x204);
      iVar1 = bVar5 + 0x42;
      if ((uVar3 != 0) && (uVar4 = *(uint *)(param_1 + 0x1f8), uVar4 != 0)) {
        if (uVar3 < (uVar4 + 500) / 1000) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0;
          if (uVar4 != 0) {
            uVar7 = (uVar3 * 1000 + (uVar4 >> 1)) / uVar4;
          }
          uVar7 = uVar7 - 1 & 0xff;
        }
      }
      uVar7 = regmap_update_bits_base
                        (*(undefined8 *)(lVar14 + 8),(uint)*(ushort *)(lVar14 + 0x58) + iVar1,0x7f,
                         uVar7,0,0,0);
      if ((int)uVar7 < 0) {
        iVar1 = (uint)*(ushort *)(lVar14 + 0x58) + iVar1;
        goto LAB_001021c4;
      }
      if ((*(uint *)(param_1 + 0x214) & 0xfffffffe) == 2) {
        if (*(char *)(param_1 + 0x219) == '\0') goto LAB_00102130;
        uVar7 = 0;
LAB_00102164:
        _raw_spin_unlock_irqrestore(lVar2,uVar8);
        if ((*(int *)(param_1 + 0x214) != 3) ||
           (uVar12 = 1L << ((ulong)*(byte *)(param_1 + 0x20d) & 0x3f),
           param_2 = qti_flash_led_strobe
                               (*(undefined8 *)(param_1 + -8),0,uVar12,uVar12 & 0xffffffff),
           uVar7 = param_2, -1 < (int)param_2)) goto LAB_0010221c;
        puVar10 = &DAT_001034ec;
        goto LAB_00102218;
      }
      if ((*(uint *)(param_1 + 0x214) != 1) || (*(char *)(lVar14 + 99) != '\0')) {
LAB_00102130:
        *(undefined1 *)(param_1 + 0x218) = 1;
        if ((*(char *)(param_1 + 0x211) == '\x01') &&
           (*(uint *)(*(long *)(lVar14 + 0x38) + (ulong)*(byte *)(param_1 + 0x20d) * 4) < 0x200)) {
          uVar9 = gpio_to_desc();
          gpiod_set_raw_value(uVar9,1);
        }
        goto LAB_00102164;
      }
      iVar1 = bVar5 + 0x3e;
      local_5c[0] = *(byte *)(param_1 + 0x20c) | 0x80;
      uVar7 = regmap_bulk_write(*(undefined8 *)(lVar14 + 8),(uint)*(ushort *)(lVar14 + 0x58) + iVar1
                                ,local_5c,1);
      if (-1 < (int)uVar7) goto LAB_00102130;
      puVar10 = &DAT_00103859;
      pcVar11 = "qti_flash_led_write";
      iVar1 = (uint)*(ushort *)(lVar14 + 0x58) + iVar1;
    }
    _printk(puVar10,pcVar11,iVar1,uVar7);
    _raw_spin_unlock_irqrestore(lVar2,uVar8);
    puVar10 = &DAT_00104384;
  }
LAB_00102218:
  _printk(puVar10,"__qti_flash_led_brightness_set",param_2);
LAB_0010221c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// qti_flash_led_symmetry_config @ 00102290 size=296
// signature: undefined qti_flash_led_symmetry_config(void)
// callers: [qti_flash_led_brightness_set, qti_flash_switch_enable]
//------------------------------------------------------------

undefined8 qti_flash_led_symmetry_config(long *param_1)

{
  undefined8 uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  uint uVar7;
  
  lVar5 = *param_1;
  if (*(int *)(lVar5 + 0x2c) != 0) {
    iVar4 = 0;
    iVar6 = 0;
    lVar3 = *(long *)(lVar5 + 0x10);
    do {
      if (((*(uint *)(param_1 + 0x4a) >>
            ((ulong)*(byte *)(lVar3 + (long)iVar4 * 0x228 + 0x215) & 0x3f) & 1) != 0) &&
         (*(char *)(lVar3 + (long)iVar4 * 0x228 + 0x220) != '\0')) {
        iVar6 = *(int *)(lVar3 + (long)iVar4 * 0x228 + 0x21c);
      }
      iVar4 = iVar4 + 1;
    } while (*(int *)(lVar5 + 0x2c) != iVar4);
    if (iVar6 != 0) {
      if ((0xffffffffffffffffU >> ((ulong)-(uint)*(byte *)(lVar5 + 0x5c) & 0x3f) !=
           (ulong)*(uint *)(param_1 + 0x4a)) || (*(char *)(lVar5 + 0x60) == '\0')) {
        uVar1 = qti_flash_config_group_symmetry(lVar5,iVar6);
        return uVar1;
      }
      uVar2 = *(uint *)(lVar5 + 0x30);
      if (uVar2 != 0) {
        uVar1 = 0;
        uVar7 = 0;
        do {
          if (0xffffffffffffffffU >> ((ulong)-(uint)*(byte *)(lVar5 + 0x5c) & 0x3f) !=
              (ulong)*(uint *)(*(long *)(lVar5 + 0x18) + (long)(int)uVar7 * 600 + 0x250)) {
            uVar1 = qti_flash_config_group_symmetry(lVar5,iVar6);
            if ((int)uVar1 < 0) {
              return uVar1;
            }
            uVar2 = *(uint *)(lVar5 + 0x30);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
        return uVar1;
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// qti_flash_led_strobe @ 001023b8 size=784
// signature: undefined qti_flash_led_strobe(void)
// callers: [qti_flash_strobe_set, qti_flash_switch_enable, qti_flash_switch_disable, __qti_flash_led_brightness_set]
//------------------------------------------------------------

int qti_flash_led_strobe(long param_1,long param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  char cVar6;
  long lVar7;
  int iVar8;
  undefined8 uVar9;
  undefined *puVar10;
  char *pcVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  undefined1 local_74 [4];
  undefined1 local_70 [4];
  undefined1 local_6c [4];
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  uVar2 = param_4 & 0xff;
  uVar3 = param_3 & 0xff;
  uVar9 = _raw_spin_lock_irqsave(param_1 + 0x28);
  bVar5 = *(byte *)(param_1 + 0x5c);
  if ((uVar2 & uVar3) == 0) {
    if (bVar5 != 0) {
      uVar12 = 0;
      uVar13 = (ulong)*(byte *)(param_1 + 0x5d);
      do {
        uVar14 = 1L << (uVar12 & 0x3f);
        if (((uVar14 & uVar3) != 0 && (uVar14 & uVar13) != 0) && (uVar14 & uVar2) == 0) {
          uVar4 = (uint)uVar13 & ((uint)uVar14 ^ 0xffffffff);
          uVar13 = (ulong)uVar4;
          *(char *)(param_1 + 0x5d) = (char)uVar4;
        }
        uVar12 = uVar12 + 1;
      } while (bVar5 != uVar12);
    }
    iVar8 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x4e,
                       param_3 & 0xff,param_4 & 0xff,0,0,0);
    if (iVar8 < 0) goto LAB_001025f4;
    if ((*(char *)(param_1 + 0x5f) == '\0') || (local_70[0] = 0, *(char *)(param_1 + 0x62) != '\0'))
    {
      cVar6 = *(char *)(param_1 + 0x5e);
    }
    else {
      iVar8 = regmap_bulk_write(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x65,
                                local_70,1);
      if (iVar8 < 0) {
        _printk(&DAT_00103859,"qti_flash_led_write",*(ushort *)(param_1 + 0x58) + 0x65,iVar8);
        _printk(&DAT_001038e9,"qti_flash_lmh_mitigation_config","disable",iVar8);
        goto LAB_00102614;
      }
      *(undefined1 *)(param_1 + 0x5f) = 0;
      cVar6 = *(char *)(param_1 + 0x5e);
    }
    if ((cVar6 == '\0') || (*(char *)(param_1 + 0x5d) != '\0')) {
      iVar8 = 0;
      goto LAB_00102614;
    }
    local_6c[0] = 0;
    iVar8 = regmap_bulk_write(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x46,
                              local_6c,1);
    if (-1 < iVar8) {
      *(undefined1 *)(param_1 + 0x5e) = 0;
      goto LAB_00102614;
    }
LAB_00102660:
    puVar10 = &DAT_00103859;
    pcVar11 = "qti_flash_led_write";
    iVar1 = *(ushort *)(param_1 + 0x58) + 0x46;
  }
  else {
    if (bVar5 != 0) {
      uVar12 = 0;
      do {
        uVar13 = 1L << (uVar12 & 0x3f);
        if ((uVar13 & uVar3) != 0 && (uVar13 & uVar2) != 0) {
          *(byte *)(param_1 + 0x5d) = *(byte *)(param_1 + 0x5d) | (byte)uVar13;
        }
        uVar12 = uVar12 + 1;
      } while (bVar5 != uVar12);
    }
    if ((*(char *)(param_1 + 0x5e) == '\0') && (*(char *)(param_1 + 0x5d) != '\0')) {
      local_74[0] = 0x80;
      iVar8 = regmap_bulk_write(*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x46,
                                local_74,1);
      if (iVar8 < 0) goto LAB_00102660;
      *(undefined1 *)(param_1 + 0x5e) = 1;
    }
    if ((param_2 != 0) && (*(long *)(param_2 + 0x248) != 0)) {
      hrtimer_start_range_ns(param_2 + 0x1f8,*(long *)(param_2 + 0x248) * 1000000,0,1);
    }
    iVar8 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 8),*(ushort *)(param_1 + 0x58) + 0x4e,
                       param_3 & 0xff,param_4 & 0xff,0,0,0);
    if (-1 < iVar8) goto LAB_00102614;
LAB_001025f4:
    puVar10 = &DAT_0010357d;
    pcVar11 = "qti_flash_led_masked_write";
    iVar1 = *(ushort *)(param_1 + 0x58) + 0x4e;
  }
  _printk(puVar10,pcVar11,iVar1,iVar8);
LAB_00102614:
  _raw_spin_unlock_irqrestore(param_1 + 0x28,uVar9);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// qti_flash_led_disable @ 001026c8 size=296
// signature: undefined qti_flash_led_disable(void)
// callers: [qti_flash_strobe_set, qti_flash_switch_disable, __qti_flash_led_brightness_set]
//------------------------------------------------------------

int qti_flash_led_disable(long *param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  
  if ((char)param_1[0x44] == '\0') {
    return 0;
  }
  lVar4 = *param_1;
  uVar2 = _raw_spin_lock_irqsave(lVar4 + 0x28);
  if ((*(char *)((long)param_1 + 0x219) == '\x01') &&
     (*(uint *)(*(long *)(lVar4 + 0x38) + (ulong)*(byte *)((long)param_1 + 0x215) * 4) < 0x200)) {
    uVar3 = gpio_to_desc();
    gpiod_set_raw_value(uVar3,0);
  }
  iVar5 = *(byte *)((long)param_1 + 0x215) + 0x42;
  iVar1 = regmap_update_bits_base
                    (*(undefined8 *)(lVar4 + 8),iVar5 + (uint)*(ushort *)(lVar4 + 0x58),0x7f,0,0,0,0
                    );
  if (-1 < iVar1) {
    iVar5 = *(byte *)((long)param_1 + 0x215) + 0x3e;
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(lVar4 + 8),iVar5 + (uint)*(ushort *)(lVar4 + 0x58),0x80,0,0,0
                       ,0);
    if (-1 < iVar1) {
      *(undefined1 *)(param_1 + 0x44) = 0;
      param_1[0x41] = 0;
      goto LAB_00102798;
    }
  }
  _printk(&DAT_0010357d,"qti_flash_led_masked_write",iVar5 + (uint)*(ushort *)(lVar4 + 0x58),iVar1);
LAB_00102798:
  _raw_spin_unlock_irqrestore(lVar4 + 0x28,uVar2);
  return iVar1;
}



//------------------------------------------------------------
// qti_flash_config_group_symmetry @ 001027f0 size=300
// signature: undefined qti_flash_config_group_symmetry(void)
// callers: [qti_flash_led_symmetry_config]
//------------------------------------------------------------

undefined8 qti_flash_config_group_symmetry(long param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  
  uVar3 = *(uint *)(param_1 + 0x2c);
  if (uVar3 != 0) {
    uVar7 = 0;
    iVar4 = 0;
    iVar5 = 0;
    lVar6 = *(long *)(param_1 + 0x10);
    do {
      if (((param_3 >> ((ulong)*(byte *)(lVar6 + (long)(int)uVar7 * 0x228 + 0x215) & 0x3f) & 1) != 0
          ) && (*(int *)(lVar6 + (long)(int)uVar7 * 0x228 + 0x21c) == param_2)) {
        iVar4 = iVar4 + 1;
        iVar5 = *(int *)(lVar6 + (long)(int)uVar7 * 0x228 + 0x208) + iVar5;
      }
      uVar7 = uVar7 + 1;
    } while (uVar3 != uVar7);
    if (iVar4 != 0) {
      if (uVar3 == 0) {
        return 0;
      }
      iVar1 = 0;
      if (iVar4 != 0) {
        iVar1 = iVar5 / iVar4;
      }
      uVar7 = 0;
      uVar2 = 0;
      do {
        lVar6 = *(long *)(param_1 + 0x10);
        if (((param_3 >> ((ulong)*(byte *)(lVar6 + (long)(int)uVar7 * 0x228 + 0x215) & 0x3f) & 1) !=
             0) && (*(int *)(lVar6 + (long)(int)uVar7 * 0x228 + 0x21c) == param_2)) {
          uVar2 = __qti_flash_led_brightness_set(lVar6 + (long)(int)uVar7 * 0x228 + 8,iVar1);
          if ((int)uVar2 < 0) {
            return uVar2;
          }
          uVar3 = *(uint *)(param_1 + 0x2c);
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar3);
      return uVar2;
    }
  }
  _printk(&DAT_0010419b,"qti_flash_config_group_symmetry");
  return 0xffffffea;
}



//------------------------------------------------------------
// qti_flash_brightness_set @ 00102920 size=32
// signature: undefined qti_flash_brightness_set(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_brightness_set(void)

{
  qti_flash_led_brightness_set();
  return 0;
}



//------------------------------------------------------------
// qti_flash_brightness_get @ 00102944 size=16
// signature: undefined qti_flash_brightness_get(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_brightness_get(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 8);
  return 0;
}



//------------------------------------------------------------
// qti_flash_strobe_set @ 00102958 size=264
// signature: undefined qti_flash_strobe_set(void)
// callers: []
//------------------------------------------------------------

int qti_flash_strobe_set(long param_1,byte param_2)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 uVar4;
  long lVar5;
  
  if (*(byte *)(param_1 + 0x219) != (param_2 & 1)) {
    lVar3 = *(long *)(param_1 + -8);
    if (*(char *)(lVar3 + 99) == '\0') {
      if ((((param_2 & 1) != 0) && (*(char *)(param_1 + 0x218) == '\0')) ||
         (*(char *)(param_1 + 0x20c) == '\0')) {
        return -0x16;
      }
      lVar5 = 1L << ((ulong)*(byte *)(param_1 + 0x20d) & 0x3f);
      uVar4 = (undefined4)lVar5;
      if ((param_2 & 1) == 0) {
        uVar4 = 0;
      }
      iVar2 = qti_flash_led_strobe(lVar3,0,lVar5,uVar4);
      if (iVar2 < 0) {
        pcVar1 = "strobe";
        if ((param_2 & 1) == 0) {
          pcVar1 = "desrobe";
        }
        _printk(&DAT_00103c22,"qti_flash_strobe_set",pcVar1,iVar2);
        return iVar2;
      }
      *(byte *)(param_1 + 0x219) = param_2 & 1;
      if ((param_2 & 1) != 0) {
        return iVar2;
      }
      iVar2 = qti_flash_led_disable((long *)(param_1 + -8));
      if (iVar2 < 0) {
        _printk(&DAT_00104524,"qti_flash_strobe_set",*(undefined1 *)(param_1 + 0x20d));
        return iVar2;
      }
      return iVar2;
    }
  }
  return 0;
}



//------------------------------------------------------------
// qti_flash_strobe_get @ 00102a64 size=16
// signature: undefined qti_flash_strobe_get(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_strobe_get(long param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(param_1 + 0x219);
  return 0;
}



//------------------------------------------------------------
// qti_flash_timeout_set @ 00102a78 size=280
// signature: undefined qti_flash_timeout_set(void)
// callers: []
//------------------------------------------------------------

int qti_flash_timeout_set(long param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  byte local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if ((param_2 == 0) || (lVar3 = *(long *)(param_1 + -8), *(char *)(lVar3 + 99) != '\0')) {
    iVar2 = 0;
    *(undefined1 *)(param_1 + 0x20c) = 0;
  }
  else if (param_2 / 1000 - 0x501 < 0xfffffb00) {
    iVar2 = -0x16;
  }
  else if ((param_2 / 1000 & 0xffff) < 5) {
    iVar2 = -1;
  }
  else {
    local_3c[0] = (char)((param_2 / 1000 + 5 & 0xffff) / 10) - 1;
    iVar1 = *(byte *)(param_1 + 0x20d) + 0x3e;
    *(byte *)(param_1 + 0x20c) = local_3c[0];
    local_3c[0] = local_3c[0] | 0x80;
    iVar2 = regmap_bulk_write(*(undefined8 *)(lVar3 + 8),iVar1 + (uint)*(ushort *)(lVar3 + 0x58),
                              local_3c,1);
    if (iVar2 < 0) {
      _printk(&DAT_00103859,"qti_flash_led_write",iVar1 + (uint)*(ushort *)(lVar3 + 0x58),iVar2);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// on_timer_function @ 00102b94 size=100
// signature: undefined on_timer_function(void)
// callers: []
//------------------------------------------------------------

undefined8 on_timer_function(long param_1)

{
  int iVar1;
  
  iVar1 = qti_flash_switch_enable(param_1 + -0x1b0);
  if (iVar1 < 0) {
    *(undefined1 *)(param_1 + 0xa4) = 0;
    _printk(&DAT_00103d1b,"on_timer_function",*(undefined8 *)(param_1 + -0x1a8),iVar1);
  }
  else {
    *(undefined1 *)(param_1 + 0xa4) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// off_timer_function @ 00102bfc size=92
// signature: undefined off_timer_function(void)
// callers: []
//------------------------------------------------------------

undefined8 off_timer_function(long param_1)

{
  int iVar1;
  
  iVar1 = qti_flash_switch_disable(param_1 + -0x1f8);
  if (iVar1 < 0) {
    _printk(&DAT_00103cb2,"off_timer_function",*(undefined8 *)(param_1 + -0x1f0),iVar1);
  }
  else {
    *(undefined1 *)(param_1 + 0x5c) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// qti_flash_led_switch_brightness_set @ 00102c5c size=192
// signature: undefined qti_flash_led_switch_brightness_set(void)
// callers: []
//------------------------------------------------------------

void qti_flash_led_switch_brightness_set(long param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  
  if ((bool)*(char *)(param_1 + 0x24c) != (param_2 != 0)) {
    if (param_2 == 0) {
      iVar2 = qti_flash_switch_disable(param_1 + -8);
    }
    else {
      if (*(long *)(param_1 + 0x238) != 0) {
        hrtimer_start_range_ns(param_1 + 0x1a8,*(long *)(param_1 + 0x238) * 1000000,0,1);
        return;
      }
      iVar2 = qti_flash_switch_enable();
    }
    if (iVar2 < 0) {
      pcVar1 = "enable";
      if (param_2 == 0) {
        pcVar1 = "disable";
      }
      _printk(&DAT_00103e6c,"qti_flash_led_switch_brightness_set",pcVar1,iVar2);
    }
    else {
      *(bool *)(param_1 + 0x24c) = param_2 != 0;
    }
  }
  return;
}



//------------------------------------------------------------
// qti_flash_switch_enable @ 00102d1c size=584
// signature: undefined qti_flash_switch_enable(void)
// callers: [qti_flash_led_switch_brightness_set, on_timer_function]
//------------------------------------------------------------

int qti_flash_switch_enable(long *param_1)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  undefined1 local_50 [4];
  undefined1 local_4c [4];
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *param_1;
  if ((*(char *)((long)param_1 + 0x255) != '\0') &&
     (iVar2 = qti_flash_led_symmetry_config(param_1), iVar2 < 0)) {
    _printk(&DAT_00103643,"qti_flash_switch_enable",iVar2);
    goto LAB_00102e84;
  }
  if (*(int *)(lVar6 + 0x2c) == 0) {
    uVar7 = 0;
LAB_00102e38:
    if ((*(char *)(lVar6 + 0x5f) != '\0') && (local_4c[0] = 0, *(char *)(lVar6 + 0x62) == '\0')) {
      iVar2 = regmap_bulk_write(*(undefined8 *)(lVar6 + 8),*(ushort *)(lVar6 + 0x58) + 0x65,local_4c
                                ,1);
      if (iVar2 < 0) {
        _printk(&DAT_00103859,"qti_flash_led_write",*(ushort *)(lVar6 + 0x58) + 0x65,iVar2);
        pcVar3 = "disable";
        goto LAB_00102f54;
      }
      *(undefined1 *)(lVar6 + 0x5f) = 0;
    }
  }
  else {
    uVar7 = 0;
    iVar2 = 0;
    iVar4 = 0;
    lVar5 = *(long *)(lVar6 + 0x10);
    do {
      bVar1 = *(byte *)(lVar5 + (long)iVar2 * 0x228 + 0x215);
      if (((*(uint *)(param_1 + 0x4a) >> ((ulong)bVar1 & 0x3f) & 1) != 0) &&
         (*(char *)(lVar5 + (long)iVar2 * 0x228 + 0x220) != '\0')) {
        if (*(int *)(lVar5 + (long)iVar2 * 0x228 + 0x21c) == 1) {
          iVar4 = *(int *)(lVar5 + (long)iVar2 * 0x228 + 0x208) + iVar4;
        }
        uVar7 = uVar7 | 1 << (ulong)(bVar1 & 0x1f);
      }
      iVar2 = iVar2 + 1;
    } while (*(int *)(lVar6 + 0x2c) != iVar2);
    if (iVar4 < 1000) goto LAB_00102e38;
    local_50[0] = 1;
    if ((*(char *)(lVar6 + 0x62) == '\0') && (*(char *)(lVar6 + 0x5f) != '\x01')) {
      iVar2 = regmap_bulk_write(*(undefined8 *)(lVar6 + 8),*(ushort *)(lVar6 + 0x58) + 0x65,local_50
                                ,1);
      if (-1 < iVar2) {
        *(undefined1 *)(lVar6 + 0x5f) = 1;
        goto LAB_00102e24;
      }
      _printk(&DAT_00103859,"qti_flash_led_write",*(ushort *)(lVar6 + 0x58) + 0x65,iVar2);
      pcVar3 = "enable";
LAB_00102f54:
      _printk(&DAT_001038e9,"qti_flash_lmh_mitigation_config",pcVar3,iVar2);
      goto LAB_00102e84;
    }
LAB_00102e24:
    __const_udelay(0x20c4ac);
  }
  iVar2 = qti_flash_led_strobe(lVar6,param_1,(int)param_1[0x4a],uVar7);
LAB_00102e84:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qti_flash_switch_disable @ 00102f64 size=344
// signature: undefined qti_flash_switch_disable(void)
// callers: [qti_flash_led_switch_brightness_set, off_timer_function]
//------------------------------------------------------------

int qti_flash_switch_disable(long *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *param_1;
  if (*(int *)(lVar5 + 0x2c) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    iVar1 = 0;
    do {
      uVar4 = 1L << ((ulong)*(byte *)(*(long *)(lVar5 + 0x10) + (long)iVar1 * 0x228 + 0x215) & 0x3f)
      ;
      if (((uVar4 & *(uint *)(param_1 + 0x4a)) != 0) &&
         (*(char *)(*(long *)(lVar5 + 0x10) + (long)iVar1 * 0x228 + 0x220) != '\0')) {
        uVar2 = uVar2 | (uint)uVar4;
      }
      iVar1 = iVar1 + 1;
    } while (*(int *)(lVar5 + 0x2c) != iVar1);
  }
  iVar1 = qti_flash_led_strobe(lVar5,0,uVar2,~uVar2);
  if (iVar1 < 0) {
    _printk(&DAT_001042c4,"qti_flash_switch_disable",iVar1);
  }
  else {
    uVar2 = *(uint *)(lVar5 + 0x2c);
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        if (((*(uint *)(param_1 + 0x4a) >>
              ((ulong)*(byte *)(*(long *)(lVar5 + 0x10) + (long)(int)uVar3 * 0x228 + 0x215) & 0x3f)
             & 1) != 0) &&
           (*(char *)(*(long *)(lVar5 + 0x10) + (long)(int)uVar3 * 0x228 + 0x220) != '\0')) {
          iVar1 = qti_flash_led_disable();
          if (iVar1 < 0) {
            _printk(&DAT_0010402a,"qti_flash_switch_disable",
                    *(long *)(lVar5 + 0x10) + (long)(int)uVar3 * 0x228 + 0x215);
            break;
          }
          uVar2 = *(uint *)(lVar5 + 0x2c);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
    param_1[0x49] = 0;
    param_1[0x48] = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// qti_flash_led_max_current_show @ 001030c0 size=120
// signature: undefined qti_flash_led_max_current_show(void)
// callers: []
//------------------------------------------------------------

long qti_flash_led_max_current_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar3 + -8);
  iVar1 = qti_flash_led_get_max_avail_current(lVar2,lVar2 + 0x4c);
  if (iVar1 < 0) {
    _printk(&DAT_00104137,"qti_flash_led_max_current_show",iVar1);
    lVar2 = -0x16;
  }
  else {
    iVar1 = scnprintf(param_3,0x1000,&DAT_001039c6,*(undefined4 *)(*(long *)(lVar3 + -8) + 0x4c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// qti_flash_on_time_show @ 0010313c size=64
// signature: undefined qti_flash_on_time_show(void)
// callers: []
//------------------------------------------------------------

long qti_flash_on_time_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010368d,*(long *)(*(long *)(param_1 + 0x98) + 0x238) * 1000
                   );
  return (long)iVar1;
}



//------------------------------------------------------------
// qti_flash_on_time_store @ 00103180 size=144
// signature: undefined qti_flash_on_time_store(void)
// callers: []
//------------------------------------------------------------

long qti_flash_on_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = kstrtoull(param_3,0,&local_30);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else if (local_30 == 0) {
    param_4 = -0x16;
  }
  else {
    *(long *)(lVar2 + 0x238) = local_30;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qti_flash_off_time_show @ 00103214 size=64
// signature: undefined qti_flash_off_time_show(void)
// callers: []
//------------------------------------------------------------

long qti_flash_off_time_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010368d,*(long *)(*(long *)(param_1 + 0x98) + 0x240) * 1000
                   );
  return (long)iVar1;
}



//------------------------------------------------------------
// qti_flash_off_time_store @ 00103258 size=144
// signature: undefined qti_flash_off_time_store(void)
// callers: []
//------------------------------------------------------------

long qti_flash_off_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  ulong local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar2 = kstrtoull(param_3,0,&local_30);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    uVar1 = local_30;
    if (0x4ff < local_30) {
      uVar1 = 0x500;
    }
    *(ulong *)(lVar3 + 0x240) = uVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qti_flash_led_irq_handler @ 001032ec size=244
// signature: undefined qti_flash_led_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_flash_led_irq_handler(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  local_30[0] = 0;
  local_34[0] = 0;
  iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 8),*(ushort *)(param_2 + 0x58) + 0x10,local_2c,
                           1);
  if (iVar2 < 0) {
    iVar3 = 0x10;
  }
  else {
    iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 8),*(ushort *)(param_2 + 0x58) + 6,local_30,1
                            );
    if (iVar2 < 0) {
      iVar3 = 6;
    }
    else {
      iVar2 = regmap_bulk_read(*(undefined8 *)(param_2 + 8),*(ushort *)(param_2 + 0x58) + 7,local_34
                               ,1);
      if (-1 < iVar2) goto LAB_00103370;
      iVar3 = 7;
    }
  }
  _printk(&DAT_001038b4,"qti_flash_led_read",iVar3 + (uint)*(ushort *)(param_2 + 0x58),iVar2);
LAB_00103370:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 00103414 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qti_flash_led_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103444 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qti_flash_led_driver);
  return;
}



//------------------------------------------------------------
// __rcu_read_lock @ 00106000 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [qti_flash_led_prepare, qti_flash_led_set_param]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00106008 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qti_flash_led_prepare, qti_flash_led_probe, qti_flash_led_set_param]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00106010 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [qti_flash_led_prepare, qti_flash_led_set_param]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106018 size=1
// signature: undefined _printk(void)
// callers: [qti_flash_timeout_set, qti_flash_led_switch_brightness_set, qti_flash_led_irq_handler, qti_flash_led_prepare, qti_flash_led_probe, qti_flash_led_set_param, qti_flash_led_get_max_avail_current, qti_flash_config_group_symmetry, on_timer_function, qti_flash_led_strobe, qti_flash_strobe_set, qti_flash_switch_enable, qti_flash_switch_disable, qti_flash_led_max_current_show, __qti_flash_led_brightness_set, off_timer_function, qti_flash_led_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00106020 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [qti_flash_led_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qti_battery_charger_get_prop @ 00106028 size=1
// signature: undefined qti_battery_charger_get_prop(void)
// callers: [qti_flash_led_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_battery_charger_get_prop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00106030 size=1
// signature: undefined power_supply_get_property(void)
// callers: [qti_flash_led_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00106038 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qti_flash_led_strobe, qti_flash_led_probe, qti_flash_led_get_max_avail_current, __qti_flash_led_brightness_set, qti_flash_led_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 00106040 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [qti_flash_led_irq_handler, qti_flash_led_probe, qti_flash_led_get_max_avail_current]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qti_flash_timeout_set, qti_flash_led_strobe, qti_flash_led_irq_handler, qti_flash_on_time_store, qti_flash_led_probe, qti_flash_switch_enable, qti_flash_led_get_max_avail_current, __qti_flash_led_brightness_set, qti_flash_off_time_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00106050 size=1
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
// platform_driver_unregister @ 00106058 size=1
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
// devm_kmalloc @ 00106060 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00106068 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00106070 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00106078 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00106080 size=1
// signature: undefined gpio_to_desc(void)
// callers: [qti_flash_led_probe, __qti_flash_led_brightness_set, qti_flash_led_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00106088 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00106090 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00106098 size=1
// signature: undefined scnprintf(void)
// callers: [qti_flash_led_probe, qti_flash_off_time_show, qti_flash_led_max_current_show, qti_flash_on_time_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 001060a0 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001060a8 size=1
// signature: undefined of_find_property(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 001060b0 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 001060b8 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001060c0 size=1
// signature: undefined of_property_read_string(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_flash_register_ext @ 001060c8 size=1
// signature: undefined devm_led_classdev_flash_register_ext(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_flash_register_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 001060d0 size=1
// signature: undefined hrtimer_init(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_register_ext @ 001060d8 size=1
// signature: undefined devm_led_classdev_register_ext(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_register_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 001060e0 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 001060e8 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [qti_flash_led_probe, qti_flash_led_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001060f0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qti_flash_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 001060f8 size=1
// signature: undefined power_supply_put(void)
// callers: [qti_flash_led_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00106100 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qti_flash_led_strobe, __qti_flash_led_brightness_set, qti_flash_led_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 00106108 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [qti_flash_timeout_set, qti_flash_led_strobe, qti_flash_switch_enable, __qti_flash_led_brightness_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 00106110 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [__qti_flash_led_brightness_set, qti_flash_led_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00106118 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qti_flash_led_strobe, __qti_flash_led_brightness_set, qti_flash_led_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 00106120 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [qti_flash_led_strobe, qti_flash_led_switch_brightness_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00106128 size=1
// signature: undefined __const_udelay(void)
// callers: [qti_flash_switch_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00106130 size=1
// signature: undefined kstrtoull(void)
// callers: [qti_flash_on_time_store, qti_flash_off_time_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



