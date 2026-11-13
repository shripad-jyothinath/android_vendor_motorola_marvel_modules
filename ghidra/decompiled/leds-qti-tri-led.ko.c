// Decompiled by Ghidra 12.2
// Program: leds-qti-tri-led.ko
// Image base: 00100000

//------------------------------------------------------------
// qpnp_tri_led_probe @ 0010022c size=1676
// signature: undefined qpnp_tri_led_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00100650) */

ulong qpnp_tri_led_probe(long param_1)

{
  bool bVar1;
  undefined1 auVar2 [16];
  uint uVar3;
  uint uVar4;
  long *plVar5;
  undefined8 uVar6;
  long lVar7;
  undefined4 *puVar8;
  ulong uVar9;
  long *plVar10;
  undefined8 uVar11;
  long lVar12;
  char *pcVar13;
  int iVar14;
  ulong uVar15;
  long lVar16;
  ulong uVar17;
  long lVar18;
  uint local_6c;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  plVar5 = (long *)devm_kmalloc(param_1 + 0x10,0x58,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar9 = 0xfffffff4;
    goto LAB_00100854;
  }
  uVar6 = *(undefined8 *)(param_1 + 0x70);
  *plVar5 = param_1 + 0x10;
  lVar7 = dev_get_regmap(uVar6,0);
  plVar5[1] = lVar7;
  if (lVar7 == 0) {
    _dev_err(*plVar5,"Getting regmap failed\n");
    uVar9 = 0xffffffea;
    goto LAB_00100854;
  }
  uVar6 = *(undefined8 *)(*plVar5 + 0x2e8);
  local_6c = 0;
  puVar8 = (undefined4 *)__of_get_address(uVar6,0,0xffffffff,0,0);
  if (puVar8 == (undefined4 *)0x0) {
    _dev_err(*plVar5,"Getting address failed\n");
LAB_001006b4:
    uVar9 = 0xffffffea;
    goto LAB_00100614;
  }
  *(ushort *)((long)plVar5 + 0x54) =
       (ushort)(byte)((uint)*puVar8 >> 0x18) | (ushort)((uint)*puVar8 >> 8) & 0xff00;
  lVar7 = of_get_next_available_child(uVar6,0);
  if (lVar7 == 0) {
    *(undefined4 *)(plVar5 + 10) = 0;
LAB_00100680:
    _dev_err(*plVar5,"No led child node defined\n");
LAB_00100690:
    uVar9 = 0xffffffed;
  }
  else {
    iVar14 = 0;
    do {
      iVar14 = iVar14 + 1;
      lVar7 = of_get_next_available_child(uVar6,lVar7);
    } while (lVar7 != 0);
    *(int *)(plVar5 + 10) = iVar14;
    if (iVar14 == 0) goto LAB_00100680;
    if (3 < iVar14) {
      _dev_err(*plVar5,"can\'t support %d leds(max %d)\n",iVar14,3);
      goto LAB_001006b4;
    }
    lVar7 = of_find_property(*(undefined8 *)(*plVar5 + 0x2e8),"nvmem",0);
    if (lVar7 != 0) {
      uVar9 = devm_nvmem_device_get(*plVar5,"pbs_sdam");
      plVar5[3] = uVar9;
      if ((uVar9 != 0) && (uVar9 < 0xfffffffffffff001)) goto LAB_00100348;
      if ((int)uVar9 == -0x205) {
        plVar5[3] = 0;
LAB_00100850:
        uVar9 = 0xfffffdfb;
        goto LAB_00100854;
      }
      _dev_err(*plVar5,"Couldn\'t get nvmem device, rc=%d\n");
      goto LAB_00100690;
    }
LAB_00100348:
    auVar2._8_8_ = 0;
    auVar2._0_8_ = (long)(int)plVar5[10];
    if (SUB168(auVar2 * ZEXT816(0x230),8) == 0) {
      lVar7 = devm_kmalloc(*plVar5,(long)(int)plVar5[10] * 0x230,0xdc0);
      plVar5[2] = lVar7;
      if (lVar7 != 0) {
        plVar10 = (long *)of_get_next_available_child(uVar6,0);
        if (plVar10 != (long *)0x0) {
          iVar14 = 0;
          do {
            uVar3 = of_property_read_variable_u32_array(plVar10,"led-sources",&local_6c,1,0);
            if ((int)uVar3 < 0) {
              uVar9 = (ulong)uVar3;
              _dev_err(*plVar5,"Get led-sources failed, rc=%d\n",uVar9);
joined_r0x00100808:
              if (uVar3 != 0xfffffdfb) goto LAB_00100614;
              goto LAB_00100850;
            }
            if (2 < (int)local_6c) {
              _dev_err(*plVar5,"only support 0~%d current source\n",2);
              goto LAB_001006b4;
            }
            lVar16 = plVar5[2];
            lVar7 = lVar16 + (long)iVar14 * 0x230;
            *(long **)(lVar7 + 0x1e0) = plVar5;
            *(char *)(lVar7 + 0x228) = (char)local_6c;
            lVar7 = of_get_property(plVar10,"label",0);
            if (lVar7 == 0) {
              lVar7 = *plVar10;
            }
            lVar18 = lVar16 + (long)iVar14 * 0x230;
            *(long *)(lVar18 + 0x218) = lVar7;
            uVar9 = devm_fwnode_pwm_get(*plVar5,plVar10 + 3,0);
            *(ulong *)(lVar18 + 0x1a8) = uVar9;
            if (0xfffffffffffff000 < uVar9) {
              uVar3 = (uint)uVar9;
              if (uVar3 == 0xfffffdfb) goto LAB_00100850;
              _dev_err(*plVar5,"Get pwm device for %s led failed, rc=%d\n",
                       *(undefined8 *)(lVar18 + 0x218),uVar9 & 0xffffffff);
              if ((int)uVar3 < 0) goto joined_r0x00100808;
              break;
            }
            lVar16 = lVar16 + (long)iVar14 * 0x230;
            lVar7 = 1000000;
            if (*(long *)(uVar9 + 0x28) != 0) {
              lVar7 = *(long *)(uVar9 + 0x28);
            }
            *(long *)(lVar16 + 0x1b0) = lVar7;
            uVar11 = of_get_property(plVar10,"linux,default-trigger",0);
            *(undefined8 *)(lVar16 + 0x220) = uVar11;
            plVar10 = (long *)of_get_next_available_child(uVar6,plVar10);
            iVar14 = iVar14 + 1;
          } while (plVar10 != (long *)0x0);
        }
        plVar10 = plVar5 + 4;
        __mutex_init(plVar10,"&chip->bus_lock",&qpnp_tri_led_probe___key);
        local_6c = 0;
        mutex_lock(plVar10);
        uVar4 = regmap_read(plVar5[1],*(ushort *)((long)plVar5 + 0x54) + 4,&local_6c);
        uVar3 = local_6c;
        if ((int)uVar4 < 0) {
          uVar9 = (ulong)uVar4;
          _dev_err(*plVar5,"Read addr 0x%x failed, rc=%d\n",4,uVar9);
          mutex_unlock(plVar10);
          lVar7 = *plVar5;
          pcVar13 = "Read REG_TYPE failed, rc=%d\n";
LAB_00100758:
          _dev_err(lVar7,pcVar13,uVar9);
        }
        else {
          mutex_unlock(plVar10);
          if ((uVar3 & 0xff) == 0x19) {
            local_6c = 0;
            mutex_lock(plVar10);
            uVar4 = regmap_read(plVar5[1],*(ushort *)((long)plVar5 + 0x54) + 5,&local_6c);
            uVar3 = local_6c;
            if (-1 < (int)uVar4) {
              mutex_unlock(plVar10);
              *(char *)((long)plVar5 + 0x56) = (char)uVar3;
              *(long **)(*plVar5 + 0x98) = plVar5;
              if (0 < (int)plVar5[10]) {
                lVar7 = 0x1a8;
                uVar17 = 1;
                do {
                  lVar18 = plVar5[2];
                  lVar16 = lVar18 + lVar7;
                  __mutex_init(lVar16 + 0x40,"&led->lock",&qpnp_tri_led_register___key);
                  *(undefined8 *)(lVar16 + -0x1a8) = *(undefined8 *)(lVar16 + 0x70);
                  *(code **)(lVar16 + -0x180) = qpnp_tri_led_set_brightness;
                  *(code **)(lVar16 + -0x178) = qpnp_tri_led_get_brightness;
                  *(code **)(lVar16 + -0x170) = qpnp_tri_led_set_blink;
                  *(undefined8 *)(lVar16 + -0x138) = *(undefined8 *)(lVar16 + 0x78);
                  *(undefined8 *)(lVar16 + -0x1a0) = 0xff00000000;
                  uVar3 = devm_led_classdev_register_ext(*plVar5,(undefined8 *)(lVar16 + -0x1a8),0);
                  if ((int)uVar3 < 0) {
                    uVar9 = (ulong)uVar3;
                    lVar12 = *plVar5;
                    uVar6 = *(undefined8 *)(lVar16 + 0x70);
                    pcVar13 = "%s led class device registering failed, rc=%d\n";
LAB_00100794:
                    _dev_err(lVar12,pcVar13,uVar6,uVar9);
                    uVar15 = 0;
                    lVar7 = 0x50;
                    do {
                      if (uVar15 < uVar17 - 1) {
                        sysfs_remove_files(*(undefined8 *)(plVar5[2] + lVar7),&breath_attrs);
                      }
                      uVar15 = uVar15 + 1;
                      lVar7 = lVar7 + 0x230;
                    } while (uVar17 != uVar15);
                    if (-1 < (int)uVar9) break;
                    lVar7 = *plVar5;
                    pcVar13 = "Registering LED class devices failed, rc=%d\n";
                    goto LAB_0010076c;
                  }
                  uVar3 = qpnp_lpg_pwm_get_output_types_supported(*(undefined8 *)(lVar18 + lVar7));
                  if ((0 < (int)uVar3) && ((uVar3 >> 1 & 1) != 0)) {
                    uVar9 = sysfs_create_files(*(undefined8 *)(lVar18 + lVar7 + -0x158),
                                               &breath_attrs);
                    if ((int)uVar9 < 0) {
                      uVar9 = uVar9 & 0xffffffff;
                      lVar12 = *plVar5;
                      uVar6 = *(undefined8 *)(lVar18 + lVar7 + 0x70);
                      pcVar13 = "Create breath file for %s led failed, rc=%d\n";
                      goto LAB_00100794;
                    }
                  }
                  lVar7 = lVar7 + 0x230;
                  bVar1 = (long)uVar17 < (long)(int)plVar5[10];
                  uVar17 = uVar17 + 1;
                } while (bVar1);
              }
              uVar9 = 0;
              goto LAB_00100854;
            }
            uVar9 = (ulong)uVar4;
            _dev_err(*plVar5,"Read addr 0x%x failed, rc=%d\n",5,uVar9);
            mutex_unlock(plVar10);
            lVar7 = *plVar5;
            pcVar13 = "Read REG_SUBTYPE failed, rc=%d\n";
            goto LAB_00100758;
          }
          _dev_err(*plVar5,"invalid subtype(%d)\n",uVar3 & 0xff);
          uVar9 = 0xffffffed;
        }
        lVar7 = *plVar5;
        pcVar13 = "HW initialization failed, rc=%d\n";
LAB_0010076c:
        _dev_err(lVar7,pcVar13,uVar9);
        *(undefined8 *)(*plVar5 + 0x98) = 0;
        goto LAB_00100854;
      }
      uVar9 = 0xfffffff4;
    }
    else {
      uVar9 = 0xfffffff4;
      plVar5[2] = 0;
    }
  }
LAB_00100614:
  _dev_err(*plVar5,"Devicetree properties parsing failed, rc=%d\n",uVar9 & 0xffffffff);
LAB_00100854:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// qpnp_tri_led_remove @ 001008bc size=120
// signature: undefined qpnp_tri_led_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_tri_led_remove(long param_1)

{
  long *plVar1;
  long lVar2;
  long lVar3;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  if (0 < (int)plVar1[10]) {
    lVar2 = 0;
    lVar3 = 0x50;
    do {
      sysfs_remove_files(*(undefined8 *)(plVar1[2] + lVar3),&breath_attrs);
      lVar2 = lVar2 + 1;
      lVar3 = lVar3 + 0x230;
    } while (lVar2 < (int)plVar1[10]);
  }
  *(undefined8 *)(*plVar1 + 0x98) = 0;
  return 0;
}



//------------------------------------------------------------
// qpnp_tri_led_set_brightness @ 00100938 size=196
// signature: undefined qpnp_tri_led_set_brightness(void)
// callers: []
//------------------------------------------------------------

int qpnp_tri_led_set_brightness(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  
  mutex_lock(param_1 + 0x1e8);
  if (0xfe < param_2) {
    param_2 = 0xff;
  }
  if (((param_2 == *(uint *)(param_1 + 0x1d8)) && (*(char *)(param_1 + 0x229) == '\0')) &&
     (*(char *)(param_1 + 0x22a) == '\0')) {
    iVar2 = 0;
  }
  else {
    lVar1 = 0x1c8;
    if (param_2 != 0) {
      lVar1 = 0x1d0;
    }
    *(uint *)(param_1 + 0x1d8) = param_2;
    *(undefined8 *)(param_1 + lVar1) = 0;
    *(undefined2 *)(param_1 + 0x1dc) = 0;
    iVar2 = qpnp_tri_led_set(param_1);
    if (iVar2 != 0) {
      _dev_err(**(undefined8 **)(param_1 + 0x1e0),"Set led failed for %s, rc=%d\n",
               *(undefined8 *)(param_1 + 0x218),iVar2);
    }
  }
  mutex_unlock(param_1 + 0x1e8);
  return iVar2;
}



//------------------------------------------------------------
// qpnp_tri_led_get_brightness @ 00100a00 size=8
// signature: undefined qpnp_tri_led_get_brightness(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_tri_led_get_brightness(long param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



//------------------------------------------------------------
// qpnp_tri_led_set_blink @ 00100a0c size=232
// signature: undefined qpnp_tri_led_set_blink(void)
// callers: []
//------------------------------------------------------------

int qpnp_tri_led_set_blink(long param_1,long *param_2,long *param_3)

{
  int iVar1;
  long lVar2;
  
  mutex_lock(param_1 + 0x1e8);
  lVar2 = *param_2;
  if (((*(char *)(param_1 + 0x229) == '\0') || (lVar2 != *(long *)(param_1 + 0x1c8))) ||
     (*param_3 != *(long *)(param_1 + 0x1d0))) {
    if (lVar2 == 0) {
      *(undefined2 *)(param_1 + 0x1dc) = 0;
      *(undefined4 *)(param_1 + 0x1d8) = 0;
    }
    else if (*param_3 == 0) {
      *(undefined2 *)(param_1 + 0x1dc) = 0;
      *(undefined4 *)(param_1 + 0x1d8) = *(undefined4 *)(param_1 + 8);
    }
    else {
      *(long *)(param_1 + 0x1c8) = lVar2;
      lVar2 = *param_3;
      *(undefined2 *)(param_1 + 0x1dc) = 1;
      *(long *)(param_1 + 0x1d0) = lVar2;
    }
    iVar1 = qpnp_tri_led_set(param_1);
    if (iVar1 != 0) {
      _dev_err(**(undefined8 **)(param_1 + 0x1e0),"Set led failed for %s, rc=%d\n",
               *(undefined8 *)(param_1 + 0x218),iVar1);
    }
  }
  else {
    iVar1 = 0;
  }
  mutex_unlock(param_1 + 0x1e8);
  return iVar1;
}



//------------------------------------------------------------
// qpnp_tri_led_set @ 00100af4 size=888
// signature: undefined qpnp_tri_led_set(void)
// callers: [breath_store, qpnp_tri_led_set_brightness, qpnp_tri_led_set_blink]
//------------------------------------------------------------

int qpnp_tri_led_set(undefined8 *param_1)

{
  undefined8 *puVar1;
  byte bVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  long lVar6;
  byte bVar7;
  int iVar8;
  char *pcVar9;
  ulong uVar10;
  undefined2 uVar11;
  undefined4 uVar12;
  undefined8 uVar13;
  undefined8 *puVar14;
  undefined1 local_64 [4];
  ulong local_60;
  ulong local_58;
  undefined4 uStack_50;
  bool local_4c;
  undefined3 uStack_4b;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  if (*(char *)((long)param_1 + 0x1dc) == '\0') {
    local_60 = param_1[0x36];
    local_58 = (local_60 * *(uint *)(param_1 + 0x3b)) / 0xff;
    if (local_60 < local_58 && 0xfe < local_60 * *(uint *)(param_1 + 0x3b)) {
      local_60 = local_58 + 1;
    }
  }
  else {
    local_58 = param_1[0x39] * 1000000;
    uVar10 = (param_1[0x3a] + param_1[0x39]) * 1000000;
    local_60 = local_58 | 1;
    if (local_58 <= uVar10) {
      local_60 = uVar10;
    }
  }
  param_1[0x37] = local_60;
  param_1[0x38] = local_58;
  local_64[0] = 0;
  uVar13 = *(undefined8 *)(param_1[0x35] + 0x48);
  uVar12 = 1;
  if (*(char *)((long)param_1 + 0x1dd) != '\0') {
    uVar12 = 2;
  }
  uStack_4b = (undefined3)((ulong)uVar13 >> 0x28);
  _uStack_50 = CONCAT14(local_58 != 0,(int)uVar13);
  iVar8 = qpnp_lpg_pwm_set_output_type(param_1[0x35],uVar12);
  if (iVar8 < 0) {
    puVar14 = (undefined8 *)param_1[0x3c];
    uVar13 = *param_1;
    pcVar9 = "Set output_type for %s led failed, rc=%d\n";
LAB_00100d5c:
    _dev_err(*puVar14,pcVar9,uVar13,iVar8);
    _dev_err(*(undefined8 *)param_1[0x3c],"Configure PWM for %s led failed, rc=%d\n",*param_1,iVar8)
    ;
  }
  else {
    iVar8 = pwm_apply_state(param_1[0x35],&local_60);
    if (iVar8 < 0) {
      puVar14 = (undefined8 *)param_1[0x3c];
      uVar13 = *param_1;
      pcVar9 = "Apply PWM state for %s led failed, rc=%d\n";
      goto LAB_00100d5c;
    }
    puVar14 = (undefined8 *)param_1[0x3c];
    uVar5 = 1 << (ulong)(7 - *(byte *)(param_1 + 0x45) & 0x1f);
    uVar3 = 0;
    if (param_1[0x38] != 0) {
      uVar3 = uVar5;
    }
    if ((*(char *)((long)puVar14 + 0x56) == '\x03') && (puVar14[3] != 0)) {
      bVar4 = *(byte *)((long)puVar14 + 0x57);
      bVar7 = (byte)(1 << (ulong)(*(byte *)(param_1 + 0x45) & 0x1f));
      bVar2 = bVar4 & (bVar7 ^ 0xff);
      if ((uVar3 & 0xff) != 0) {
        bVar2 = bVar4 | bVar7;
      }
      *(byte *)((long)puVar14 + 0x57) = bVar2;
      puVar14 = (undefined8 *)param_1[0x3c];
      if ((*(byte *)((long)puVar14 + 0x57) & bVar4) != 0) goto LAB_00100c9c;
      local_64[0] = 1;
      if (*(byte *)((long)puVar14 + 0x57) == 0) {
        local_64[0] = 2;
      }
      iVar8 = nvmem_device_write(puVar14[3],0x42,1,local_64);
      if (iVar8 < 0) {
        pcVar9 = "Couldn\'t set PBS_ARG, rc=%d\n";
        uVar13 = *(undefined8 *)param_1[0x3c];
      }
      else {
        local_64[0] = 1;
        iVar8 = nvmem_device_write(*(undefined8 *)(param_1[0x3c] + 0x18),0xe6,1,local_64);
        if (iVar8 < 0) {
          pcVar9 = "Couldn\'t set PBS_TRIG_CLR, rc=%d\n";
          uVar13 = *(undefined8 *)param_1[0x3c];
        }
        else {
          local_64[0] = 1;
          iVar8 = nvmem_device_write(*(undefined8 *)(param_1[0x3c] + 0x18),0xe5,1,local_64);
          puVar14 = (undefined8 *)param_1[0x3c];
          if (-1 < iVar8) goto LAB_00100c9c;
          uVar13 = *puVar14;
          pcVar9 = "Couldn\'t set PBS_TRIG_SET, rc=%d\n";
        }
      }
      _dev_err(uVar13,pcVar9,iVar8);
    }
    else {
LAB_00100c9c:
      puVar1 = puVar14 + 4;
      mutex_lock(puVar1);
      uVar5 = uVar5 & 0xff;
      iVar8 = regmap_update_bits_base
                        (puVar14[1],*(ushort *)((long)puVar14 + 0x54) + 0x46,uVar5,uVar3 & 0xff,0,0,
                         0);
      if (-1 < iVar8) {
        mutex_unlock(puVar1);
        if (*(char *)((long)param_1 + 0x1dc) == '\0') {
          if (*(char *)((long)param_1 + 0x1dd) == '\0') {
            *(undefined4 *)(param_1 + 1) = *(undefined4 *)(param_1 + 0x3b);
            *(undefined2 *)((long)param_1 + 0x229) = 0;
            goto LAB_00100e34;
          }
          uVar11 = 0x100;
        }
        else {
          uVar11 = 1;
        }
        *(undefined4 *)(param_1 + 1) = 0xff;
        *(undefined2 *)((long)param_1 + 0x229) = uVar11;
        goto LAB_00100e34;
      }
      _dev_err(*puVar14,"Update addr 0x%x to val 0x%x with mask 0x%x failed, rc=%d\n",0x46,
               uVar3 & 0xff,uVar5,iVar8);
      mutex_unlock(puVar1);
      _dev_err(*(undefined8 *)param_1[0x3c],"Update addr 0x%x failed, rc=%d\n",0x46,iVar8);
    }
  }
  _dev_err(*(undefined8 *)param_1[0x3c],"__tri_led_set %s failed, rc=%d\n",*param_1,iVar8);
LAB_00100e34:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// breath_show @ 00100e70 size=60
// signature: undefined breath_show(void)
// callers: []
//------------------------------------------------------------

long breath_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101355,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0x1dd))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// breath_store @ 00100eb0 size=252
// signature: undefined breath_store(void)
// callers: []
//------------------------------------------------------------

void breath_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  char local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_3c[0] = '\0';
  iVar2 = kstrtobool(param_3,local_3c);
  if (iVar2 < 0) {
    lVar4 = (long)iVar2;
  }
  else {
    cancel_work_sync(lVar4 + 0xd0);
    mutex_lock(lVar4 + 0x1e8);
    if (*(char *)(lVar4 + 0x22a) != local_3c[0]) {
      uVar3 = 0;
      if (local_3c[0] != '\0') {
        uVar3 = 0xff;
      }
      *(undefined1 *)(lVar4 + 0x1dc) = 0;
      *(char *)(lVar4 + 0x1dd) = local_3c[0];
      *(undefined4 *)(lVar4 + 0x1d8) = uVar3;
      iVar2 = qpnp_tri_led_set(lVar4);
      if (iVar2 < 0) {
        _dev_err(**(undefined8 **)(lVar4 + 0x1e0),"Set led failed for %s, rc=%d\n",
                 *(undefined8 *)(lVar4 + 0x218),iVar2);
      }
    }
    mutex_unlock(lVar4 + 0x1e8);
    lVar4 = (long)iVar2;
    if (-1 < iVar2) {
      lVar4 = param_4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100fb0 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qpnp_tri_led_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100fe0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qpnp_tri_led_driver);
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
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00103018 size=1
// signature: undefined dev_get_regmap(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 00103020 size=1
// signature: undefined __of_get_address(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00103028 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103030 size=1
// signature: undefined of_find_property(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_device_get @ 00103038 size=1
// signature: undefined devm_nvmem_device_get(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_device_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103040 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00103048 size=1
// signature: undefined of_get_property(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_fwnode_pwm_get @ 00103050 size=1
// signature: undefined devm_fwnode_pwm_get(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_fwnode_pwm_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103058 size=1
// signature: undefined __mutex_init(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103060 size=1
// signature: undefined mutex_lock(void)
// callers: [breath_store, qpnp_tri_led_set_brightness, qpnp_tri_led_set, qpnp_tri_led_set_blink, qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00103068 size=1
// signature: undefined regmap_read(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103070 size=1
// signature: undefined mutex_unlock(void)
// callers: [breath_store, qpnp_tri_led_set_brightness, qpnp_tri_led_set, qpnp_tri_led_set_blink, qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_register_ext @ 00103078 size=1
// signature: undefined devm_led_classdev_register_ext(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_register_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qpnp_lpg_pwm_get_output_types_supported @ 00103080 size=1
// signature: undefined qpnp_lpg_pwm_get_output_types_supported(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qpnp_lpg_pwm_get_output_types_supported(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_files @ 00103088 size=1
// signature: undefined sysfs_create_files(void)
// callers: [qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_files(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103090 size=1
// signature: undefined _dev_err(void)
// callers: [breath_store, qpnp_tri_led_set_brightness, qpnp_tri_led_set, qpnp_tri_led_set_blink, qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_files @ 00103098 size=1
// signature: undefined sysfs_remove_files(void)
// callers: [qpnp_tri_led_remove, qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_files(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030a0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [breath_store, qpnp_tri_led_set, qpnp_tri_led_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qpnp_lpg_pwm_set_output_type @ 001030a8 size=1
// signature: undefined qpnp_lpg_pwm_set_output_type(void)
// callers: [qpnp_tri_led_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qpnp_lpg_pwm_set_output_type(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pwm_apply_state @ 001030b0 size=1
// signature: undefined pwm_apply_state(void)
// callers: [qpnp_tri_led_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pwm_apply_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_device_write @ 001030b8 size=1
// signature: undefined nvmem_device_write(void)
// callers: [qpnp_tri_led_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_device_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001030c0 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qpnp_tri_led_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001030c8 size=1
// signature: undefined scnprintf(void)
// callers: [breath_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 001030d0 size=1
// signature: undefined kstrtobool(void)
// callers: [breath_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001030d8 size=1
// signature: undefined cancel_work_sync(void)
// callers: [breath_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



