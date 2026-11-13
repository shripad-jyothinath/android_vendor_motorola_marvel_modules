// Decompiled by Ghidra 12.2
// Program: nxp-nci.ko
// Image base: 00100000

//------------------------------------------------------------
// nfc_parse_dt @ 00100cf4 size=624
// signature: undefined nfc_parse_dt(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

uint nfc_parse_dt(long param_1,uint *param_2,char param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x2e8);
  if (lVar3 == 0) {
    _printk(&DAT_00105bac,"nfc_parse_dt");
  }
  else {
    param_2[0] = 0xffffffea;
    param_2[1] = 0xffffffea;
    param_2[2] = 0xffffffea;
    param_2[3] = 0xffffffea;
    if (param_3 == '\0') {
      uVar1 = of_get_named_gpio_flags(lVar3,"qcom,sn-irq",0,0);
      *param_2 = uVar1;
      if (0x1ff < uVar1) {
        _printk(&DAT_001053fe,"nfc_parse_dt");
        return *param_2;
      }
      _printk(&DAT_001052c1,"nfc_parse_dt");
    }
    uVar1 = of_get_named_gpio_flags(lVar3,"qcom,sn-ven",0,0);
    param_2[1] = uVar1;
    if (0x1ff < uVar1) {
      _printk(&DAT_001050d5,"nfc_parse_dt");
      return param_2[1];
    }
    uVar1 = of_get_named_gpio_flags(lVar3,"qcom,sn-firm",0,0);
    param_2[3] = uVar1;
    if (0x1ff < uVar1) {
      _printk(&DAT_00105eb8,"nfc_parse_dt");
    }
    iVar2 = of_property_read_string(lVar3,"qcom,clk-src",param_2 + 8);
    *(bool *)(param_2 + 10) = iVar2 == 0;
    uVar1 = of_get_named_gpio_flags(lVar3,"qcom,sn-clkreq",0,0);
    param_2[2] = uVar1;
    if (uVar1 < 0x200) {
      iVar2 = of_property_read_string(lVar3,"qcom,sn-szone",param_2 + 0xc);
      *(bool *)(param_2 + 0xe) = iVar2 == 0;
      _printk(&DAT_00105e48,"nfc_parse_dt",*param_2,param_2[1],param_2[3],param_2[2]);
      iVar2 = of_property_read_variable_u32_array(lVar3,"qcom,sn-vdd-1p8-voltage",param_2 + 4,2,0);
      if (iVar2 < 0) {
        _dev_err(param_1,"NxpDrv: error reading NFC VDDIO min and max value\n");
        param_2[4] = 0x192d50;
        param_2[5] = 0x1dc130;
      }
      iVar2 = of_property_read_variable_u32_array(lVar3,"qcom,sn-vdd-1p8-current",param_2 + 6,1,0);
      if (iVar2 < 0) {
        _dev_err(param_1,"NxpDrv: error reading NFC current value\n");
        param_2[6] = 0x26548;
        return 0;
      }
      return 0;
    }
    _dev_err(param_1,"NxpDrv: clkreq gpio invalid %d\n");
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// set_valid_gpio @ 00100f68 size=72
// signature: undefined set_valid_gpio(void)
// callers: [nfcc_hw_check]
//------------------------------------------------------------

void set_valid_gpio(uint param_1,undefined4 param_2)

{
  undefined8 uVar1;
  
  if (param_1 < 0x200) {
    uVar1 = gpio_to_desc();
    gpiod_set_raw_value(uVar1,param_2);
    usleep_range_state(10000,0x2774,2);
  }
  return;
}



//------------------------------------------------------------
// get_valid_gpio @ 00100fb4 size=48
// signature: undefined get_valid_gpio(void)
// callers: []
//------------------------------------------------------------

undefined8 get_valid_gpio(uint param_1)

{
  undefined8 uVar1;
  
  if (param_1 < 0x200) {
    gpio_to_desc();
    uVar1 = gpiod_get_raw_value();
    return uVar1;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gpio_set_ven @ 00100fe8 size=112
// signature: undefined gpio_set_ven(void)
// callers: [nfcc_hw_check, nfc_ioctl_power_states, nfc_ese_pwr]
//------------------------------------------------------------

void gpio_set_ven(long param_1,int param_2)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
  iVar1 = gpiod_get_raw_value();
  if (iVar1 != param_2) {
    if ((secure_peripheral_not_found != '\0') || (uVar2 = nfc_hw_secure_check(), (uVar2 & 1) == 0))
    {
      uVar3 = gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
      gpiod_set_raw_value(uVar3,param_2);
    }
    usleep_range_state(10000,0x2774,2);
  }
  return;
}



//------------------------------------------------------------
// nfc_hw_secure_check @ 0010105c size=464
// signature: undefined nfc_hw_secure_check(void)
// callers: [nfc_ioctl_power_states, gpio_set_ven, nfc_i2c_dev_probe]
//------------------------------------------------------------

bool nfc_hw_secure_check(void)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  char local_98 [4];
  undefined4 local_94;
  code *local_90;
  undefined8 uStack_88;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined8 uStack_70;
  char *local_68;
  undefined8 uStack_60;
  undefined4 *local_58;
  undefined8 uStack_50;
  code *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_90 = (code *)0x0;
  uStack_88 = 0;
  local_94 = 0x506;
  local_68 = (char *)0x0;
  uStack_60 = 0;
  local_78 = (undefined4 *)0x0;
  uStack_70 = 0;
  local_98[0] = '\0';
  iVar5 = get_client_env_object(&local_90);
  if (iVar5 == 0) {
    local_58 = &local_7c;
    local_48 = (code *)0x0;
    uStack_40 = 0;
    local_7c = 0x108;
    uStack_50 = 4;
    if (*(int *)(local_90 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x1010e4);
      (*pcVar3)();
    }
    iVar5 = (*local_90)(uStack_88,0,&local_58,0x1001);
    uVar2 = uStack_40;
    pcVar3 = local_48;
    if (iVar5 == 0xc) {
      bVar4 = false;
    }
    else if (iVar5 == 0) {
      local_78 = &local_94;
      local_68 = local_98;
      bVar4 = true;
      uStack_70 = 4;
      uStack_60 = 1;
      if (*(int *)(local_48 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8236,0x1011b4);
        (*pcVar3)();
      }
      iVar5 = (*local_48)(uStack_40,1,&local_78,0x11);
      _printk(&DAT_00105f7a,iVar5,local_98[0]);
      if (iVar5 == 0) {
        bVar4 = local_98[0] == '\x01';
        secure_peripheral_not_found = 0;
      }
      else if (iVar5 == 10) {
        bVar4 = false;
      }
      if (*(int *)(pcVar3 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8236,0x101220);
        (*pcVar3)();
      }
      (*pcVar3)(uVar2,0xffff,0,0);
    }
    else {
      bVar4 = true;
    }
    if (*(int *)(local_90 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101128);
      (*pcVar3)();
    }
    (*local_90)(uStack_88,0xffff,0,0);
  }
  else {
    _printk(&DAT_001057f6,iVar5);
    bVar4 = true;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar4;
}



//------------------------------------------------------------
// configure_gpio @ 00101230 size=268
// signature: undefined configure_gpio(void)
// callers: [nfc_post_init, nfc_i2c_dev_probe]
//------------------------------------------------------------

int configure_gpio(ulong param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (0x1ff < (uint)param_1) {
    _printk(&DAT_001059cf,"configure_gpio");
    return -0x16;
  }
  uVar4 = param_1 & 0xffffffff;
  iVar1 = gpio_request(param_1,"nfc_gpio");
  if (iVar1 != 0) {
    _printk(&DAT_00106394,"configure_gpio",uVar4);
    return iVar1;
  }
  if ((param_2 & 1) == 0) {
    gpio_to_desc(uVar4);
    iVar1 = gpiod_direction_input();
  }
  else {
    uVar3 = gpio_to_desc(uVar4);
    iVar1 = gpiod_direction_output_raw(uVar3,param_2 & 2);
  }
  if (iVar1 == 0) {
    if ((param_2 >> 2 & 1) == 0) {
      return 0;
    }
    gpio_to_desc(uVar4);
    iVar1 = gpiod_to_irq();
    if (-1 < iVar1) {
      return iVar1;
    }
    puVar2 = &DAT_00105ef7;
  }
  else {
    puVar2 = &DAT_001055a5;
  }
  _printk(puVar2,"configure_gpio",uVar4);
  gpio_free(uVar4);
  return iVar1;
}



//------------------------------------------------------------
// gpio_free_all @ 00101340 size=100
// signature: undefined gpio_free_all(void)
// callers: [nfc_i2c_dev_remove, nfc_i2c_dev_probe]
//------------------------------------------------------------

void gpio_free_all(long param_1)

{
  if (*(uint *)(param_1 + 0x188) < 0x200) {
    gpio_free();
  }
  if (*(uint *)(param_1 + 0x18c) < 0x200) {
    gpio_free();
  }
  if (*(uint *)(param_1 + 0x180) < 0x200) {
    gpio_free();
  }
  if (*(uint *)(param_1 + 0x184) < 0x200) {
    gpio_free();
  }
  return;
}



//------------------------------------------------------------
// nfc_misc_unregister @ 001013a8 size=100
// signature: undefined nfc_misc_unregister(void)
// callers: [nfc_i2c_dev_remove, nfc_i2c_dev_probe]
//------------------------------------------------------------

void nfc_misc_unregister(long param_1,undefined4 param_2)

{
  kfree(*(undefined8 *)(param_1 + 0x200));
  device_destroy(*(undefined8 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0x158));
  cdev_del(param_1 + 0xd0);
  class_destroy(*(undefined8 *)(param_1 + 0xc0));
  unregister_chrdev_region(*(undefined4 *)(param_1 + 0x158),param_2);
  if (*(long *)(param_1 + 0x218) != 0) {
    ipc_log_context_destroy();
  }
  return;
}



//------------------------------------------------------------
// nfc_misc_register @ 00101410 size=564
// signature: undefined nfc_misc_register(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong nfc_misc_register(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4,
                       undefined8 param_5)

{
  long lVar1;
  undefined4 uVar2;
  uint uVar3;
  long *plVar4;
  undefined8 uVar5;
  long lVar6;
  
  uVar3 = alloc_chrdev_region((undefined4 *)(param_1 + 0x158),0);
  if ((int)uVar3 < 0) {
    plVar4 = (long *)(ulong)uVar3;
    _printk(&DAT_00105f1d,"nfc_misc_register",plVar4);
  }
  else {
    plVar4 = (long *)__class_create(&__this_module,param_5,&nfc_misc_register___key);
    *(long **)(param_1 + 0xc0) = plVar4;
    if (plVar4 < (long *)0xfffffffffffff001) {
      lVar1 = param_1 + 0xd0;
      cdev_init(lVar1,param_2);
      uVar3 = cdev_add(lVar1,*(undefined4 *)(param_1 + 0x158),param_3);
      if (-1 < (int)uVar3) {
        plVar4 = (long *)device_create(*(undefined8 *)(param_1 + 0xc0),0,
                                       *(undefined4 *)(param_1 + 0x158),param_1,param_4);
        *(long **)(param_1 + 200) = plVar4;
        if (plVar4 < (long *)0xfffffffffffff001) {
          lVar6 = plVar4[0xe];
          if (lVar6 == 0) {
            lVar6 = *plVar4;
          }
          uVar5 = ipc_log_context_create(2,lVar6,0);
          *(undefined8 *)(param_1 + 0x218) = uVar5;
          uVar5 = _down_timeout;
          *(undefined8 *)(param_1 + 0x1f8) = 0x102;
          lVar6 = kmalloc_trace(uVar5,0xdc1,0x102);
          *(long *)(param_1 + 0x200) = lVar6;
          if (lVar6 == 0) {
            kfree();
            device_destroy(*(undefined8 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0x158));
            cdev_del(lVar1);
            class_destroy(*(undefined8 *)(param_1 + 0xc0));
            unregister_chrdev_region(*(undefined4 *)(param_1 + 0x158),param_3);
            if (*(long *)(param_1 + 0x218) != 0) {
              ipc_log_context_destroy();
            }
            plVar4 = (long *)0xfffffff4;
          }
          else {
            *(undefined1 *)(param_1 + 0x1e8) = 0;
            *(undefined2 *)(param_1 + 0x1e6) = 0;
            *(undefined1 *)(param_1 + 0x1e4) = 0xff;
            __init_waitqueue_head
                      (param_1 + 0x1c0,"&nfc_dev->cold_reset.read_wq",&nfc_misc_register___key_26);
            plVar4 = (long *)0x0;
          }
        }
        else {
          _printk(&DAT_00106083,"nfc_misc_register",(ulong)plVar4 & 0xffffffff);
          cdev_del(lVar1);
          class_destroy(*(undefined8 *)(param_1 + 0xc0));
          unregister_chrdev_region(*(undefined4 *)(param_1 + 0x158),param_3);
        }
        goto LAB_00101624;
      }
      plVar4 = (long *)(ulong)uVar3;
      _printk(&DAT_00105f51,"nfc_misc_register",plVar4);
      class_destroy(*(undefined8 *)(param_1 + 0xc0));
      uVar2 = *(undefined4 *)(param_1 + 0x158);
    }
    else {
      _printk(&DAT_00105421,"nfc_misc_register",(ulong)plVar4 & 0xffffffff);
      uVar2 = *(undefined4 *)(param_1 + 0x158);
    }
    unregister_chrdev_region(uVar2,param_3);
  }
LAB_00101624:
  return (ulong)plVar4 & 0xffffffff;
}



//------------------------------------------------------------
// nfc_dev_compat_ioctl @ 00101648 size=32
// signature: undefined nfc_dev_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

long nfc_dev_compat_ioctl(void)

{
  int iVar1;
  
  iVar1 = nfc_dev_ioctl();
  return (long)iVar1;
}



//------------------------------------------------------------
// nfc_dev_ioctl @ 0010166c size=848
// signature: undefined nfc_dev_ioctl(void)
// callers: [nfc_dev_compat_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void nfc_dev_ioctl(long param_1,int param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined8 *puVar8;
  ulong uVar9;
  long lVar10;
  uint local_3c;
  long local_38;
  
  lVar10 = sp_el0;
  local_38 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_1 + 0xd8);
  if (lVar10 == 0) {
    lVar10 = -0x13;
    goto LAB_00101924;
  }
  if (((*(char *)(lVar10 + 0x1b8) != '\0') && (param_2 != 0x4004e90a)) &&
     (*(char *)(lVar10 + 0x20c) != '\0')) {
    lVar10 = -1;
    goto LAB_00101924;
  }
  if (param_2 < 0x4004e901) {
    if (param_2 == -0x7ffb16fd) {
      param_3 = 2;
      goto LAB_001017b0;
    }
    if (param_2 != -0x7ffb16fb) {
      if (param_2 != -0x3fef16f8) goto switchD_001016fc_caseD_4004e903;
      iVar3 = ese_cold_reset_ioctl(lVar10,param_3);
      goto LAB_00101920;
    }
    if (*(uint *)(lVar10 + 0x180) < 0x200) {
      gpio_to_desc();
      uVar4 = gpiod_get_raw_value();
      if ((int)uVar4 < 0) goto LAB_001017d8;
      uVar4 = uVar4 & 3;
    }
    else {
LAB_001017d8:
      uVar4 = 2;
    }
    if (*(uint *)(lVar10 + 0x184) < 0x200) {
      gpio_to_desc();
      uVar5 = gpiod_get_raw_value();
      if ((int)uVar5 < 0) goto LAB_001017fc;
      uVar5 = uVar5 & 3;
    }
    else {
LAB_001017fc:
      uVar5 = 2;
    }
    if (*(uint *)(lVar10 + 0x188) < 0x200) {
      gpio_to_desc();
      uVar6 = gpiod_get_raw_value();
      if ((int)uVar6 < 0) goto LAB_00101824;
      uVar6 = uVar6 & 3;
    }
    else {
LAB_00101824:
      uVar6 = 2;
    }
    if (*(uint *)(lVar10 + 0x18c) < 0x200) {
      gpio_to_desc();
      uVar7 = gpiod_get_raw_value();
      if ((int)uVar7 < 0) goto LAB_0010184c;
      uVar7 = uVar7 & 3;
    }
    else {
LAB_0010184c:
      uVar7 = 2;
    }
    puVar8 = (undefined8 *)sp_el0;
    local_3c = uVar4 | uVar5 << 2 | uVar6 << 4 | uVar7 << 6;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_3, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar9 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar9 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar2 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      iVar3 = __arch_copy_to_user(puVar8,param_3 & 0xff7fffffffffffff,&local_3c,4);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      if (iVar3 < 0) {
        _printk(&DAT_00105fa2,"nfc_gpio_info");
        iVar3 = -0xe;
        goto LAB_00101920;
      }
    }
LAB_0010191c:
    iVar3 = 0;
  }
  else {
    switch(param_2) {
    case 0x4004e901:
      iVar3 = nfc_ioctl_power_states(lVar10,param_3);
      break;
    case 0x4004e902:
LAB_001017b0:
      iVar3 = nfc_ese_pwr(lVar10,param_3);
      break;
    default:
switchD_001016fc_caseD_4004e903:
      _printk(&DAT_00105506,"nfc_dev_ioctl",param_3);
      iVar3 = -0x203;
      break;
    case 0x4004e904:
      if (param_3 == 0) {
        iVar3 = 0;
        *(undefined1 *)(lVar10 + 0x1e9) = 0;
      }
      else if (param_3 == 1) {
        iVar3 = 0;
        *(undefined1 *)(lVar10 + 0x1e9) = 1;
        *(undefined1 *)(lVar10 + 0x15d) = 2;
      }
      else {
        iVar3 = -0x16;
      }
      break;
    case 0x4004e909:
      iVar3 = nfc_ioctl_nfcc_info(param_1,param_3);
      break;
    case 0x4004e90a:
      if (*(char *)(lVar10 + 0x1b8) == '\0') goto LAB_0010191c;
      iVar3 = nfc_dynamic_protection_ioctl(lVar10,param_3);
    }
  }
LAB_00101920:
  lVar10 = (long)iVar3;
LAB_00101924:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar10);
  }
  return;
}



//------------------------------------------------------------
// nfc_post_init @ 001019d8 size=508
// signature: undefined nfc_post_init(void)
// callers: [nfc_dynamic_protection_ioctl, nfc_i2c_dev_probe]
//------------------------------------------------------------

int nfc_post_init(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  iVar5 = 0;
  local_4c = 0;
  if ((nfc_post_init_post_init_success & 1) == 0) {
    if (param_1 == 0) {
      iVar5 = -0x13;
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x184);
      uVar2 = *(undefined4 *)(param_1 + 0x188);
      uVar3 = *(undefined4 *)(param_1 + 0x18c);
      iVar5 = configure_gpio(uVar1,1);
      if (iVar5 == 0) {
        iVar5 = configure_gpio(uVar3,1);
        if (iVar5 != 0) {
          _printk(&DAT_00105457,"nfc_post_init",uVar3);
        }
        iVar5 = configure_gpio(uVar2,0);
        if (iVar5 != 0) {
          _printk(&DAT_00105ada,"nfc_post_init",uVar2);
        }
        iVar5 = of_property_read_u32_index
                          (*(undefined8 *)(*(long *)(param_1 + 0x168) + 0x308),"qcom,sn-clkreq",1,
                           &local_4c);
        if (iVar5 < 0) {
          _printk(&DAT_00105d76,"nfc_post_init",iVar5);
        }
        else {
          iVar5 = msm_gpio_mpm_wake_set(local_4c,1);
          if (iVar5 < 0) {
            _printk(&DAT_001057b7,"nfc_post_init",local_4c,iVar5);
          }
          else {
            iVar5 = nfcc_hw_check(param_1);
            if ((iVar5 == 0) && (*(char *)(param_1 + 0x15d) != '\0')) {
              if (*(char *)(param_1 + 0x1b8) != '\0') {
                sem_eSE_pwr_off = 0;
                DAT_00106558 = &DAT_00106558;
                DAT_00106560 = &DAT_00106558;
              }
              nfc_post_init_post_init_success = 1;
              _printk(&DAT_00105950,"nfc_post_init");
              iVar5 = 0;
            }
            else {
              _printk(&DAT_001056c5,iVar5);
              gpio_free(uVar3);
              gpio_free(uVar1);
            }
          }
        }
      }
      else {
        _printk(&DAT_001052d7,"nfc_post_init",uVar1);
      }
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// nfc_dynamic_protection_ioctl @ 00101bd8 size=272
// signature: undefined nfc_dynamic_protection_ioctl(void)
// callers: [nfc_dev_ioctl]
//------------------------------------------------------------

int nfc_dynamic_protection_ioctl(long param_1,long param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_2 == 1) {
    if (*(char *)(param_1 + 0x1e8) != '\0') {
      return -1;
    }
    if ((*(char *)(param_1 + 0x161) != '\0') &&
       (iVar1 = down_timeout(&sem_eSE_pwr_off,0xfa), iVar1 != 0)) {
      _printk(&DAT_001063f2);
    }
    iVar1 = nfc_ioctl_power_states(param_1,0);
    puVar2 = &DAT_00106491;
    *(undefined1 *)(param_1 + 0x20c) = 1;
  }
  else if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x20c) = 0;
    if ((nfc_dynamic_protection_ioctl_init_flag & 1) == 0) {
      iVar1 = nfc_post_init(param_1);
      if (iVar1 == 0) {
        puVar2 = &DAT_00106280;
        nfc_dynamic_protection_ioctl_init_flag = 1;
        goto LAB_00101ce0;
      }
    }
    else {
      gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
      iVar1 = gpiod_get_raw_value();
      if (iVar1 == 0) {
        iVar1 = nfc_ioctl_power_states(param_1,1);
      }
      else {
        iVar1 = 0;
      }
    }
    puVar2 = &DAT_00106280;
  }
  else {
    iVar1 = -0x203;
    puVar2 = &DAT_00105654;
  }
LAB_00101ce0:
  _printk(puVar2);
  return iVar1;
}



//------------------------------------------------------------
// nfc_ioctl_power_states @ 00101ce8 size=1040
// signature: undefined nfc_ioctl_power_states(void)
// callers: [nfc_dev_ioctl, nfc_dynamic_protection_ioctl]
//------------------------------------------------------------

int nfc_ioctl_power_states(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  
  switch(param_2) {
  case 0:
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101d40);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x238))(param_1);
    if (*(uint *)(param_1 + 0x18c) < 0x200) {
      uVar4 = gpio_to_desc();
      gpiod_set_raw_value(uVar4,0);
      usleep_range_state(10000,0x2774,2);
    }
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    iVar2 = gpiod_get_raw_value();
    if (iVar2 != 0) {
      if ((secure_peripheral_not_found != '\0') || (uVar3 = nfc_hw_secure_check(), (uVar3 & 1) == 0)
         ) {
        uVar4 = gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
        gpiod_set_raw_value(uVar4,0);
      }
      usleep_range_state(10000,0x2774,2);
    }
    uVar6 = 2;
    goto LAB_00101e58;
  case 1:
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101ddc);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x230))(param_1);
    if (*(uint *)(param_1 + 0x18c) < 0x200) {
      uVar4 = gpio_to_desc();
      gpiod_set_raw_value(uVar4,0);
      usleep_range_state(10000,0x2774,2);
    }
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    iVar2 = gpiod_get_raw_value();
    if (iVar2 != 1) {
      if ((secure_peripheral_not_found != '\0') || (uVar3 = nfc_hw_secure_check(), (uVar3 & 1) == 0)
         ) {
        uVar4 = gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
        gpiod_set_raw_value(uVar4,1);
      }
      usleep_range_state(10000,0x2774,2);
    }
    uVar6 = 0x102;
LAB_00101e58:
    iVar2 = 0;
    *(undefined2 *)(param_1 + 0x15d) = uVar6;
    break;
  case 2:
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101e84);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x238))(param_1);
    if (*(uint *)(param_1 + 0x18c) < 0x200) {
      uVar4 = gpio_to_desc();
      gpiod_set_raw_value(uVar4,1);
      usleep_range_state(10000,0x2774,2);
    }
    *(undefined1 *)(param_1 + 0x15d) = 1;
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    iVar2 = gpiod_get_raw_value();
    if (iVar2 != 0) {
      if ((secure_peripheral_not_found != '\0') || (uVar3 = nfc_hw_secure_check(), (uVar3 & 1) == 0)
         ) {
        uVar4 = gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
        gpiod_set_raw_value(uVar4,0);
      }
      usleep_range_state(10000,0x2774,2);
    }
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    iVar2 = gpiod_get_raw_value();
    if (iVar2 != 1) {
      if ((secure_peripheral_not_found != '\0') || (uVar3 = nfc_hw_secure_check(), (uVar3 & 1) == 0)
         ) {
        uVar4 = gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
        gpiod_set_raw_value(uVar4,1);
      }
      usleep_range_state(10000,0x2774,2);
    }
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101f60);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x230))(param_1);
    iVar2 = 0;
    break;
  default:
    _printk(&DAT_00105a02,"nfc_ioctl_power_states");
    iVar2 = -0x203;
    break;
  case 4:
    if (*(uint *)(param_1 + 0x18c) < 0x200) {
      uVar4 = gpio_to_desc();
      gpiod_set_raw_value(uVar4,1);
      usleep_range_state(10000,0x2774,2);
    }
    uVar5 = 1;
    goto LAB_00101fc8;
  case 5:
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10209c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x238))(param_1);
    gpio_set_ven(param_1,0);
    gpio_set_ven(param_1,1);
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1020d8);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x230))(param_1);
    _printk(&DAT_00106417,"nfc_ioctl_power_states");
    iVar2 = 0;
    break;
  case 6:
    if (*(uint *)(param_1 + 0x18c) < 0x200) {
      uVar4 = gpio_to_desc();
      gpiod_set_raw_value(uVar4,0);
      usleep_range_state(10000,0x2774,2);
    }
    uVar5 = 2;
LAB_00101fc8:
    iVar2 = 0;
    *(undefined1 *)(param_1 + 0x15d) = uVar5;
    break;
  case 7:
    if (*(char *)(param_1 + 0x1a8) == '\0') {
      iVar2 = 0;
    }
    else {
      iVar2 = nfc_clock_select(param_1);
      if (iVar2 != 0) {
        _printk(&DAT_00106150,"nfc_ioctl_power_states");
      }
    }
    *(undefined1 *)(param_1 + 0x1e8) = 1;
    break;
  case 8:
    if (*(char *)(param_1 + 0x1a8) == '\0') {
      iVar2 = 0;
    }
    else {
      iVar2 = nfc_clock_deselect(param_1);
      if (iVar2 != 0) {
        _printk(&DAT_001063c3,"nfc_ioctl_power_states");
      }
    }
    *(undefined1 *)(param_1 + 0x1e8) = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// nfc_dev_open @ 001020fc size=208
// signature: undefined nfc_dev_open(void)
// callers: []
//------------------------------------------------------------

undefined8 nfc_dev_open(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x290);
  lVar1 = lVar6 + -0xd0;
  if (lVar1 == 0) {
    uVar4 = 0xffffffed;
  }
  else {
    lVar2 = sp_el0;
    if ((*(uint *)(lVar2 + 0x44) >> 0xf & 1) == 0) {
      *(uint *)(lVar2 + 0x44) = *(uint *)(lVar2 + 0x44) | 0x8000;
    }
    mutex_lock(lVar6 + -0x48);
    *(long *)(param_2 + 0xd8) = lVar1;
    iVar5 = *(int *)(lVar6 + -0x18);
    if (iVar5 == 0) {
      if (*(uint *)(lVar6 + 0xbc) < 0x200) {
        uVar4 = gpio_to_desc();
        gpiod_set_raw_value(uVar4,0);
        usleep_range_state(10000,0x2774,2);
      }
      if (*(int *)(*(code **)(lVar6 + 0x160) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102194);
        (*pcVar3)();
      }
      (**(code **)(lVar6 + 0x160))(lVar1);
      iVar5 = *(int *)(lVar6 + -0x18);
    }
    *(int *)(lVar6 + -0x18) = iVar5 + 1;
    mutex_unlock(lVar6 + -0x48);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// nfc_dev_flush @ 001021d0 size=152
// signature: undefined nfc_dev_flush(void)
// callers: []
//------------------------------------------------------------

undefined8 nfc_dev_flush(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xd8);
  if (lVar5 == 0) {
    uVar4 = 0xffffffed;
  }
  else {
    lVar1 = lVar5 + 0x18;
    iVar3 = mutex_trylock(lVar1);
    if (iVar3 == 0) {
      *(undefined1 *)(lVar5 + 0x162) = 1;
      if (*(int *)(*(code **)(lVar5 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8229,0x102220);
        (*pcVar2)();
      }
      (**(code **)(lVar5 + 0x238))(lVar5);
      __wake_up(lVar5,3,1,0);
      mutex_lock(lVar1);
      *(undefined1 *)(lVar5 + 0x162) = 0;
    }
    mutex_unlock(lVar1);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// nfc_dev_close @ 0010226c size=216
// signature: undefined nfc_dev_close(void)
// callers: []
//------------------------------------------------------------

undefined8 nfc_dev_close(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x290);
  if (lVar5 + -0xd0 == 0) {
    uVar4 = 0xffffffed;
  }
  else {
    lVar2 = sp_el0;
    if ((*(uint *)(lVar2 + 0x44) >> 0xf & 1) != 0) {
      *(uint *)(lVar2 + 0x44) = *(uint *)(lVar2 + 0x44) & 0xffff7fff;
    }
    mutex_lock(lVar5 + -0x48);
    iVar1 = *(int *)(lVar5 + -0x18);
    if (iVar1 == 1) {
      if (*(int *)(*(code **)(lVar5 + 0x168) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1022dc);
        (*pcVar3)();
      }
      (**(code **)(lVar5 + 0x168))(lVar5 + -0xd0);
      if (*(uint *)(lVar5 + 0xbc) < 0x200) {
        uVar4 = gpio_to_desc();
        gpiod_set_raw_value(uVar4,0);
        usleep_range_state(10000,0x2774,2);
      }
      iVar1 = *(int *)(lVar5 + -0x18);
    }
    if (iVar1 != 0) {
      *(int *)(lVar5 + -0x18) = iVar1 + -1;
    }
    *(undefined8 *)(param_2 + 0xd8) = 0;
    mutex_unlock(lVar5 + -0x48);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// validate_nfc_state_nci @ 00102348 size=168
// signature: undefined validate_nfc_state_nci(void)
// callers: []
//------------------------------------------------------------

undefined8 validate_nfc_state_nci(long param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  if (*(char *)(param_1 + 0x20c) == '\0') {
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    iVar1 = gpiod_get_raw_value();
    if (iVar1 == 0) {
      uVar3 = 0xffffffed;
      puVar2 = &DAT_001055de;
      goto LAB_001023e0;
    }
  }
  if (*(uint *)(param_1 + 0x18c) < 0x200) {
    gpio_to_desc();
    iVar1 = gpiod_get_raw_value();
    if (iVar1 == 1) {
      uVar3 = 0xfffffff0;
      puVar2 = &DAT_0010566b;
      goto LAB_001023e0;
    }
  }
  if (*(char *)(param_1 + 0x15d) == '\x02') {
    return 0;
  }
  uVar3 = 0xfffffff0;
  puVar2 = &DAT_0010516c;
LAB_001023e0:
  _printk(puVar2,"validate_nfc_state_nci");
  return uVar3;
}



//------------------------------------------------------------
// get_nfcc_session_state_dl @ 0010241c size=308
// signature: undefined get_nfcc_session_state_dl(void)
// callers: [nfcc_hw_check]
//------------------------------------------------------------

undefined8 get_nfcc_session_state_dl(long param_1)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  
  pcVar1 = *(char **)(param_1 + 0x78);
  **(undefined8 **)(param_1 + 0x80) = 0x33f5000000f20400;
  if (*(int *)(*(code **)(param_1 + 0x228) + -4) != 0x7908fa88) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10246c);
    (*pcVar2)();
  }
  iVar3 = (**(code **)(param_1 + 0x228))(param_1,*(undefined8 *)(param_1 + 0x80),8,3);
  if (iVar3 < 1) {
    puVar4 = &DAT_00105247;
  }
  else {
    pcVar1[0] = '\0';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    pcVar1[4] = '\0';
    pcVar1[5] = '\0';
    pcVar1[6] = '\0';
    pcVar1[7] = '\0';
    if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x5f523d71) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1024b8);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(param_1 + 0x220))(param_1,pcVar1,8,2000);
    if (0 < iVar3) {
      if (*pcVar1 != '\0') {
        _printk(&DAT_001061ed,"get_nfcc_session_state_dl");
        return 0;
      }
      if (pcVar1[3] == '\0') {
        _printk(&DAT_00105daf,"get_nfcc_session_state_dl");
        return 1;
      }
      _printk(&DAT_00105c63,"get_nfcc_session_state_dl");
      return 4;
    }
    puVar4 = &DAT_001064be;
  }
  _printk(puVar4,"get_nfcc_session_state_dl",iVar3);
  return 0;
}



//------------------------------------------------------------
// nfcc_hw_check @ 00102554 size=1324
// signature: undefined nfcc_hw_check(void)
// callers: [nfc_post_init]
//------------------------------------------------------------

undefined8 nfcc_hw_check(long param_1)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  uint uVar8;
  undefined *puVar9;
  undefined8 uVar10;
  
  gpio_set_ven(param_1,1);
  gpio_set_ven(param_1,0);
  gpio_set_ven(param_1,1);
  pcVar2 = *(char **)(param_1 + 0x78);
  **(undefined4 **)(param_1 + 0x80) = 0x10020;
  if (*(int *)(*(code **)(param_1 + 0x228) + -4) != 0x7908fa88) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1025c8);
    (*pcVar6)();
  }
  iVar7 = (**(code **)(param_1 + 0x228))(param_1,*(undefined8 *)(param_1 + 0x80),4,1);
  if (iVar7 < 1) {
    _printk(&DAT_001060b5,"get_nfcc_chip_type",iVar7);
LAB_001027d4:
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1027f4);
      (*pcVar6)();
    }
    (**(code **)(param_1 + 0x230))(param_1);
    set_valid_gpio(*(undefined4 *)(param_1 + 0x18c),1);
    gpio_set_ven(param_1,0);
    gpio_set_ven(param_1,1);
    pcVar2 = *(char **)(param_1 + 0x78);
    **(undefined8 **)(param_1 + 0x80) = 0xef6e000000f10400;
    if (*(int *)(*(code **)(param_1 + 0x228) + -4) != 0x7908fa88) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10285c);
      (*pcVar6)();
    }
    uVar8 = (**(code **)(param_1 + 0x228))(param_1,*(undefined8 *)(param_1 + 0x80),8,3);
    if ((int)uVar8 < 1) {
      puVar9 = &DAT_00105fe5;
LAB_00102a2c:
      _printk(puVar9,"get_nfcc_chip_type_dl",uVar8);
      iVar7 = 0xff;
    }
    else {
      pcVar2[0x10] = '\0';
      pcVar2[0x11] = '\0';
      pcVar2[0x12] = '\0';
      pcVar2[0x13] = '\0';
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      pcVar2[8] = '\0';
      pcVar2[9] = '\0';
      pcVar2[10] = '\0';
      pcVar2[0xb] = '\0';
      pcVar2[0xc] = '\0';
      pcVar2[0xd] = '\0';
      pcVar2[0xe] = '\0';
      pcVar2[0xf] = '\0';
      if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x5f523d71) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10289c);
        (*pcVar6)();
      }
      uVar8 = (**(code **)(param_1 + 0x220))(param_1,pcVar2,0x14,2000);
      if ((int)uVar8 < 1) {
        puVar9 = &DAT_00105719;
        goto LAB_00102a2c;
      }
      iVar7 = 0xff;
      if ((*pcVar2 == '\0') && (0x13 < uVar8)) {
        *(char *)(param_1 + 0x15f) = pcVar2[7];
        if (pcVar2[4] == '\x01') {
          if (pcVar2[7] == '\x10') {
            iVar7 = 1;
          }
          else {
            iVar7 = 2;
            if (pcVar2[7] != '\x01') {
              iVar7 = 0xff;
            }
          }
        }
        else {
          iVar7 = 0xff;
        }
        *(char *)(param_1 + 0x208) = pcVar2[3];
        *(char *)(param_1 + 0x209) = pcVar2[4];
        *(char *)(param_1 + 0x20b) = pcVar2[6];
        *(char *)(param_1 + 0x20a) = pcVar2[7];
      }
    }
    bVar5 = true;
joined_r0x00102708:
    if (param_1 == 0) goto LAB_00102a44;
LAB_00102928:
    if (iVar7 == 1) {
      if (*(uint *)(param_1 + 0x18c) < 0x200) goto LAB_00102964;
      goto LAB_00102a58;
    }
    if (iVar7 != 2) goto LAB_00102a58;
    set_valid_gpio(*(undefined4 *)(param_1 + 0x18c),0);
    gpio_free(*(undefined4 *)(param_1 + 0x18c));
    *(undefined4 *)(param_1 + 0x18c) = 0xffffffea;
LAB_00102964:
    if (!bVar5) {
      iVar7 = 2;
LAB_001029a4:
      uVar10 = 0;
      *(char *)(param_1 + 0x15d) = (char)iVar7;
      goto LAB_001029ac;
    }
    iVar7 = get_nfcc_session_state_dl(param_1);
    if (iVar7 - 1U < 2) goto LAB_001029a4;
    if (iVar7 == 4) {
      _printk(&DAT_001058c5,"nfcc_hw_check");
      iVar7 = 4;
      goto LAB_001029a4;
    }
    puVar9 = &DAT_0010530c;
  }
  else {
    usleep_range_state(10000,0x2774,2);
    if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102604);
      (*pcVar6)();
    }
    (**(code **)(param_1 + 0x230))(param_1);
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x5f523d71) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102638);
      (*pcVar6)();
    }
    iVar7 = (**(code **)(param_1 + 0x220))(param_1,pcVar2,4,2000);
    if (iVar7 < 1) {
      puVar9 = &DAT_00105608;
LAB_001027a4:
      _printk(puVar9,"get_nfcc_chip_type",iVar7);
LAB_001027b0:
      if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1027d0);
        (*pcVar6)();
      }
      (**(code **)(param_1 + 0x238))(param_1);
      goto LAB_001027d4;
    }
    if (*pcVar2 != '@') {
      _printk(&DAT_001056eb,"get_nfcc_chip_type");
      goto LAB_001027b0;
    }
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    pcVar2[8] = '\0';
    pcVar2[9] = '\0';
    pcVar2[10] = '\0';
    pcVar2[0xb] = '\0';
    pcVar2[0xc] = '\0';
    pcVar2[0] = '\0';
    pcVar2[1] = '\0';
    pcVar2[2] = '\0';
    pcVar2[3] = '\0';
    pcVar2[4] = '\0';
    pcVar2[5] = '\0';
    pcVar2[6] = '\0';
    pcVar2[7] = '\0';
    if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x5f523d71) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102684);
      (*pcVar6)();
    }
    iVar7 = (**(code **)(param_1 + 0x220))(param_1,pcVar2,0xd,2000);
    if (iVar7 < 1) {
      puVar9 = &DAT_00105521;
      goto LAB_001027a4;
    }
    if (*pcVar2 != '`') goto LAB_001027b0;
    pcVar1 = pcVar2 + (byte)pcVar2[2];
    cVar3 = *pcVar1;
    cVar4 = pcVar1[1];
    *(char *)(param_1 + 0x208) = pcVar1[-1];
    *(char *)(param_1 + 0x209) = cVar3;
    *(char *)(param_1 + 0x20a) = cVar4;
    *(char *)(param_1 + 0x20b) = pcVar2[(ulong)(byte)pcVar2[2] + 2];
    if ((cVar3 == '\x01') && (cVar4 == '\x10')) {
      if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1026fc);
        (*pcVar6)();
      }
      (**(code **)(param_1 + 0x238))(param_1);
      bVar5 = false;
      iVar7 = 1;
      goto joined_r0x00102708;
    }
    if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102730);
      (*pcVar6)();
    }
    (**(code **)(param_1 + 0x238))(param_1);
    if ((cVar3 != '\x01') || (cVar4 != '\x01')) goto LAB_001027d4;
    bVar5 = false;
    iVar7 = 2;
    if (param_1 != 0) goto LAB_00102928;
LAB_00102a44:
    _printk(&DAT_00105b10,"validate_download_gpio");
LAB_00102a58:
    puVar9 = &DAT_00106220;
  }
  _printk(puVar9,"nfcc_hw_check");
  uVar10 = 0xfffffffa;
LAB_001029ac:
  if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1029cc);
    (*pcVar6)();
  }
  (**(code **)(param_1 + 0x238))(param_1);
  set_valid_gpio(*(undefined4 *)(param_1 + 0x18c),0);
  gpio_set_ven(param_1,0);
  gpio_set_ven(param_1,1);
  *(undefined1 *)(param_1 + 0x15e) = 1;
  return uVar10;
}



//------------------------------------------------------------
// nfc_ioctl_nfcc_info @ 00102a84 size=12
// signature: undefined nfc_ioctl_nfcc_info(void)
// callers: [nfc_dev_ioctl]
//------------------------------------------------------------

undefined4 nfc_ioctl_nfcc_info(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0xd8) + 0x208);
}



//------------------------------------------------------------
// is_nfc_data_available_for_read @ 00102a94 size=260
// signature: undefined is_nfc_data_available_for_read(void)
// callers: [ese_cold_reset_ioctl]
//------------------------------------------------------------

void is_nfc_data_available_for_read(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102ad4);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x230))();
  if (*(char *)(param_1 + 0x170) == '\0') {
    lVar2 = 0x17;
  }
  else {
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_50 = 0;
    init_wait_entry(&local_50,0);
    lVar2 = prepare_to_wait_event(param_1,&local_50,1);
    if (*(char *)(param_1 + 0x170) == '\0') {
      lVar3 = 0x17;
    }
    else {
      lVar3 = 0x17;
      do {
        if (lVar2 != 0) goto LAB_00102b6c;
        lVar3 = schedule_timeout(lVar3);
        lVar2 = prepare_to_wait_event(param_1,&local_50,1);
        if (lVar3 == 0 && *(char *)(param_1 + 0x170) == '\0') {
          lVar3 = 1;
        }
      } while ((*(char *)(param_1 + 0x170) != '\0') && (lVar3 != 0));
    }
    lVar2 = lVar3;
    finish_wait(param_1,&local_50);
  }
LAB_00102b6c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// nfc_ldo_vote @ 00102b9c size=156
// signature: undefined nfc_ldo_vote(void)
// callers: [nfc_ldo_config]
//------------------------------------------------------------

int nfc_ldo_vote(long param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = regulator_set_voltage
                    (*(undefined8 *)(param_1 + 0x1f0),*(undefined4 *)(param_1 + 400),
                     *(undefined4 *)(param_1 + 0x194));
  if (iVar1 < 0) {
    puVar2 = &DAT_001058eb;
  }
  else {
    iVar1 = regulator_set_load(*(undefined8 *)(param_1 + 0x1f0),*(undefined4 *)(param_1 + 0x198));
    if (iVar1 < 0) {
      puVar2 = &DAT_0010518d;
    }
    else {
      iVar1 = regulator_enable(*(undefined8 *)(param_1 + 0x1f0));
      if (-1 < iVar1) {
        *(undefined1 *)(param_1 + 0x160) = 1;
        return iVar1;
      }
      puVar2 = &DAT_00105c90;
    }
  }
  _printk(puVar2,"nfc_ldo_vote");
  return iVar1;
}



//------------------------------------------------------------
// nfc_ldo_config @ 00102c3c size=216
// signature: undefined nfc_ldo_config(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

ulong nfc_ldo_config(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  
  lVar1 = of_get_property(*(undefined8 *)(param_1 + 0x2e8),"qcom,sn-vdd-1p8-supply",0);
  if (lVar1 == 0) {
    *(undefined8 *)(param_2 + 0x1f0) = 0;
    _printk(&DAT_001064f0,"nfc_ldo_config");
    uVar2 = 0;
  }
  else {
    uVar2 = regulator_get(param_1,"qcom,sn-vdd-1p8");
    *(ulong *)(param_2 + 0x1f0) = uVar2;
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = nfc_ldo_vote(param_2);
      uVar2 = uVar3 & 0xffffffff;
      if ((int)uVar3 < 0) {
        _printk(&DAT_001051ac,"nfc_ldo_config",uVar2);
        regulator_put(*(undefined8 *)(param_2 + 0x1f0));
      }
    }
    else {
      *(undefined8 *)(param_2 + 0x1f0) = 0;
      _printk(&DAT_0010616d,"nfc_ldo_config",uVar2 & 0xffffffff);
    }
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// nfc_ldo_unvote @ 00102d18 size=176
// signature: undefined nfc_ldo_unvote(void)
// callers: [nfc_i2c_dev_remove]
//------------------------------------------------------------

int nfc_ldo_unvote(long param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if (*(char *)(param_1 + 0x160) == '\0') {
    iVar1 = -0x16;
    puVar2 = &DAT_00106243;
  }
  else {
    iVar1 = regulator_disable(*(undefined8 *)(param_1 + 0x1f0));
    if (iVar1 < 0) {
      puVar2 = &DAT_001060ea;
    }
    else {
      *(undefined1 *)(param_1 + 0x160) = 0;
      iVar1 = regulator_set_voltage(*(undefined8 *)(param_1 + 0x1f0),0,0x1dc130);
      if (iVar1 < 0) {
        puVar2 = &DAT_001058eb;
      }
      else {
        iVar1 = regulator_set_load(*(undefined8 *)(param_1 + 0x1f0),0);
        if (-1 < iVar1) {
          return iVar1;
        }
        puVar2 = &DAT_0010518d;
      }
    }
  }
  _printk(puVar2,"nfc_ldo_unvote");
  return iVar1;
}



//------------------------------------------------------------
// nfc_clock_select @ 00102dcc size=156
// signature: undefined nfc_clock_select(void)
// callers: [nfc_ioctl_power_states]
//------------------------------------------------------------

ulong nfc_clock_select(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  uVar2 = clk_get(*(long *)(param_1 + 0x168) + 0x20,"nfc_ref_clk");
  *(ulong *)(param_1 + 0x210) = uVar2;
  if (0xfffffffffffff000 < uVar2) {
    return uVar2 & 0xffffffff;
  }
  if (*(char *)(param_1 + 0x20d) == '\0') {
    uVar1 = clk_prepare(uVar2);
    if (uVar1 != 0) {
      return (ulong)uVar1;
    }
    uVar1 = clk_enable(uVar2);
    if (uVar1 != 0) {
      clk_unprepare(uVar2);
      return (ulong)uVar1;
    }
  }
  *(undefined1 *)(param_1 + 0x20d) = 1;
  return 0;
}



//------------------------------------------------------------
// nfc_clock_deselect @ 00102e6c size=92
// signature: undefined nfc_clock_deselect(void)
// callers: [nfc_ioctl_power_states]
//------------------------------------------------------------

undefined8 nfc_clock_deselect(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x210);
  if (lVar2 == 0) {
    uVar1 = 0xffffffea;
  }
  else if (*(char *)(param_1 + 0x20d) == '\0') {
    uVar1 = 0;
  }
  else {
    clk_disable(lVar2);
    clk_unprepare(lVar2);
    uVar1 = 0;
    *(undefined1 *)(param_1 + 0x20d) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// nfc_ese_pwr @ 00102ecc size=188
// signature: undefined nfc_ese_pwr(void)
// callers: [nfc_dev_ioctl]
//------------------------------------------------------------

undefined8 nfc_ese_pwr(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == 2) {
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    uVar2 = gpiod_get_raw_value();
  }
  else if (param_2 == 1) {
    if (*(char *)(param_1 + 0x15e) == '\0') {
      gpio_set_ven(param_1,0);
    }
    uVar2 = 0;
    *(undefined1 *)(param_1 + 0x161) = 0;
  }
  else if (param_2 == 0) {
    gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
    iVar1 = gpiod_get_raw_value();
    *(bool *)(param_1 + 0x15e) = iVar1 != 0;
    if (iVar1 == 0) {
      gpio_set_ven(param_1,1);
    }
    uVar2 = 0;
    *(undefined1 *)(param_1 + 0x161) = 1;
  }
  else {
    _printk(&DAT_0010521e,"nfc_ese_pwr");
    uVar2 = 0xfffffdfd;
  }
  return uVar2;
}



//------------------------------------------------------------
// read_cold_reset_rsp @ 00102f8c size=512
// signature: undefined read_cold_reset_rsp(void)
// callers: [ese_cold_reset_ioctl, i2c_read]
//------------------------------------------------------------

uint read_cold_reset_rsp(long param_1,undefined2 *param_2)

{
  byte bVar1;
  ushort uVar2;
  code *pcVar3;
  int iVar4;
  byte *pbVar5;
  undefined8 uVar6;
  char *pcVar7;
  uint uVar8;
  
  uVar2 = *(ushort *)(param_1 + 0x1e2);
  if (uVar2 < 4) {
    _dev_err(*(undefined8 *)(param_1 + 200),
             "%s: received cold reset rsp buffer length is invalid \n","read_cold_reset_rsp");
    return 0xffffffea;
  }
  pbVar5 = (byte *)__kmalloc(uVar2,0xdc1);
  if (pbVar5 == (byte *)0x0) {
    return 0xfffffff4;
  }
  if ((*(char *)(param_1 + 0x1e8) == '\0') && (*(char *)(param_1 + 0x15c) == '\0')) {
    uVar8 = i2c_transfer_buffer_flags(*(undefined8 *)(param_1 + 0x168),pbVar5,3,1);
    if (0 < (int)uVar8) {
      if (((*pbVar5 >> 6 & 1) != 0) && (*(long *)(param_1 + 0x1d8) != 0)) {
        if (uVar2 == 1) goto LAB_00103188;
        if (pbVar5[1] == *(byte *)(*(long *)(param_1 + 0x1d8) + 1)) goto LAB_00102ff0;
      }
      if (uVar2 != 1) {
        _dev_err(*(undefined8 *)(param_1 + 200),"%s: - invalid cold reset response 0x%x 0x%x\n",
                 "read_cold_reset_rsp",*pbVar5,pbVar5[1]);
        uVar8 = 0xffffffea;
        goto LAB_0010305c;
      }
      goto LAB_00103188;
    }
    uVar6 = *(undefined8 *)(param_1 + 200);
    pcVar7 = "%s: failure to read cold reset rsp header\n";
  }
  else {
    if (param_2 == (undefined2 *)0x0) {
      _dev_err(*(undefined8 *)(param_1 + 200),"%s: - invalid or NULL header\n","read_cold_reset_rsp"
              );
      uVar8 = 0xffffffea;
      goto LAB_0010305c;
    }
    bVar1 = *(byte *)(param_2 + 1);
    uVar8 = 0xffffffff;
    *(undefined2 *)pbVar5 = *param_2;
    pbVar5[2] = bVar1;
LAB_00102ff0:
    if (uVar2 < 3) {
LAB_00103188:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x10318c);
      (*pcVar3)();
    }
    if (*(ushort *)(param_1 + 0x1e2) < (ushort)(pbVar5[2] + 3)) {
      _dev_err(*(undefined8 *)(param_1 + 200),"%s: - no space for cold_reset resp\n",
               "read_cold_reset_rsp");
      uVar8 = 0xfffffff4;
      goto LAB_0010305c;
    }
    if (*(char *)(param_1 + 0x15c) != '\0') goto LAB_0010305c;
    if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x5f523d71) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103040);
      (*pcVar3)();
    }
    iVar4 = (**(code **)(param_1 + 0x220))(param_1,pbVar5 + 3,pbVar5[2],2000);
    if (0 < iVar4) {
      if (uVar2 < 4) goto LAB_00103188;
      bVar1 = pbVar5[3];
      uVar8 = (uint)bVar1;
      *(byte *)(param_1 + 0x1e5) = bVar1;
      goto LAB_0010305c;
    }
    uVar6 = *(undefined8 *)(param_1 + 200);
    pcVar7 = "%s: failure to read cold reset rsp payload\n";
  }
  _dev_err(uVar6,pcVar7,"read_cold_reset_rsp");
  uVar8 = 0xfffffffb;
LAB_0010305c:
  kfree(pbVar5);
  return uVar8;
}



//------------------------------------------------------------
// ese_cold_reset_ioctl @ 00103190 size=1716
// signature: undefined ese_cold_reset_ioctl(void)
// callers: [nfc_dev_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint ese_cold_reset_ioctl(long param_1,ulong param_2)

{
  long lVar1;
  undefined8 *puVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  size_t sVar7;
  char *pcVar8;
  undefined2 *puVar9;
  long lVar10;
  char cVar11;
  ulong uVar12;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  ulong local_58 [2];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58[0] = 0;
  local_58[1] = 0;
  if (param_2 == 0) {
    _dev_err(*(undefined8 *)(param_1 + 200),"arg is invalid\n");
    uVar6 = 0xffffffea;
    goto LAB_001036d8;
  }
  puVar2 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar2 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_2, ((uint)*puVar2 >> 0x1a & 1) != 0)) {
    uVar12 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar12 < 0x7ffffffff1) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = puVar2[1] & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar2[1];
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    sVar7 = __arch_copy_from_user(local_58,param_2 & 0xff7fffffffffffff,0x10);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    if (sVar7 != 0) goto LAB_001037b0;
  }
  else {
    sVar7 = 0x10;
LAB_001037b0:
    memset((void *)((long)local_58 + (0x10 - sVar7)),0,sVar7);
    if ((int)sVar7 != 0) {
      _dev_err(*(undefined8 *)(param_1 + 200),"ese ioctl arg copy from user failed\n");
      uVar6 = 0xfffffff2;
      goto LAB_001036d8;
    }
  }
  pcVar8 = (char *)kmalloc_trace(_cpu_hwcaps,0xdc0,4);
  if (pcVar8 == (char *)0x0) {
    uVar6 = 0xfffffff4;
    goto LAB_001036d8;
  }
  mutex_lock(param_1 + 0x48);
  if (((*(byte *)((long)puVar2 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = local_58[0], ((uint)*puVar2 >> 0x1a & 1) != 0)) {
    uVar12 = local_58[0] & (long)(local_58[0] << 8) >> 8;
  }
  if (uVar12 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr1_el1 = puVar2[1] & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar2[1];
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    sVar7 = __arch_copy_from_user(pcVar8,local_58[0] & 0xff7fffffffffffff,4);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    if (sVar7 != 0) goto LAB_001037e8;
    cVar11 = pcVar8[1];
    if (cVar11 == '\x02') {
      if ((*(char *)(param_1 + 0x1e6) == '\0') || (*pcVar8 == *(char *)(param_1 + 0x1e4))) {
LAB_0010341c:
        puVar9 = (undefined2 *)kmalloc_trace(_cpu_hwcaps,0xdc1,4);
        *(undefined2 **)(param_1 + 0x1d8) = puVar9;
        if (puVar9 != (undefined2 *)0x0) {
          cVar11 = pcVar8[1];
          *puVar9 = 0x1f2f;
          *(undefined1 *)(puVar9 + 1) = 1;
          *(undefined4 *)(param_1 + 0x1e0) = 0x40004;
          if (cVar11 == '\x01') {
            *(undefined1 *)((long)puVar9 + 3) = 1;
          }
          else {
            *(undefined1 *)((long)puVar9 + 3) = 0;
          }
          goto LAB_0010346c;
        }
LAB_00103460:
        uVar6 = 0xfffffff4;
      }
      else {
        _printk(&DAT_00106344);
        uVar6 = 0xfffffff3;
      }
    }
    else if (cVar11 == '\x01') {
      if (*(char *)(param_1 + 0x1e6) == '\0') goto LAB_0010341c;
      if (*pcVar8 == *(char *)(param_1 + 0x1e4)) {
        _printk(&DAT_00105de7);
        uVar6 = 0;
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + 200),"ese protection enable denied\n");
        uVar6 = 0xfffffff3;
      }
    }
    else if (cVar11 == '\0') {
      if (*(char *)(param_1 + 0x1e6) != '\0') {
        if (*pcVar8 != *(char *)(param_1 + 0x1e4)) {
          _dev_err(*(undefined8 *)(param_1 + 200),"cold reset from %d denied, protection is on\n");
          uVar6 = 0xfffffff3;
          goto LAB_001036b8;
        }
      }
      puVar9 = (undefined2 *)kmalloc_trace(_cpu_hwcaps,0xdc1,3);
      *(undefined2 **)(param_1 + 0x1d8) = puVar9;
      if (puVar9 == (undefined2 *)0x0) goto LAB_00103460;
      *(undefined1 *)(puVar9 + 1) = 0;
      *puVar9 = 0x1e2f;
      *(undefined4 *)(param_1 + 0x1e0) = 0x40003;
LAB_0010346c:
      if (*(char *)(param_1 + 0x15d) == '\x01') {
        _dev_err(*(undefined8 *)(param_1 + 200),
                 "cannot send ese cmd as FW download is in-progress\n");
        uVar6 = 0xfffffff0;
      }
      else {
        gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
        iVar5 = gpiod_get_raw_value();
        if (iVar5 == 0) {
          _dev_err(*(undefined8 *)(param_1 + 200),"cannot send ese cmd as NFCC powered off\n");
          uVar6 = 0xffffffed;
        }
        else if (*(long *)(param_1 + 0x1d8) == 0) {
          uVar6 = 0xfffffff2;
        }
        else {
          if (*(int *)(*(code **)(param_1 + 0x228) + -4) != 0x7908fa88) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1034b8);
            (*pcVar4)();
          }
          uVar6 = (**(code **)(param_1 + 0x228))
                            (param_1,*(long *)(param_1 + 0x1d8),*(undefined2 *)(param_1 + 0x1e0),3);
          if (0 < (int)uVar6) {
            lVar1 = param_1 + 0x1c0;
            *(undefined1 *)(param_1 + 0x1e7) = 1;
            if (*(char *)(param_1 + 0x1e8) == '\0') {
              if (*(char *)(param_1 + 0x15c) == '\0') {
                uVar6 = is_nfc_data_available_for_read(param_1);
                if ((int)uVar6 < 1) {
                  if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
                    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103730);
                    (*pcVar4)();
                  }
                  (**(code **)(param_1 + 0x238))(param_1);
                  *(undefined1 *)(param_1 + 0x1e7) = 0;
                }
                else {
                  uVar6 = read_cold_reset_rsp(param_1,0);
                  *(undefined1 *)(param_1 + 0x1e7) = 0;
                  if (-1 < (int)uVar6) goto LAB_001035f8;
                  _printk(&DAT_0010626d,"ese_cold_reset_ioctl");
                }
                goto LAB_001036b8;
              }
              if (*(int *)(*(code **)(param_1 + 0x230) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10354c);
                (*pcVar4)();
              }
              (**(code **)(param_1 + 0x230))(param_1);
              if (*(char *)(param_1 + 0x1e7) != '\0') {
                local_68 = 0;
                uStack_60 = 0;
                local_78 = 0;
                uStack_70 = 0;
                local_80 = 0;
                init_wait_entry(&local_80,0);
                while( true ) {
                  lVar10 = prepare_to_wait_event(lVar1,&local_80,1);
                  if (*(char *)(param_1 + 0x1e7) == '\0') break;
                  if (lVar10 != 0) goto LAB_001035f8;
                  schedule();
                }
                finish_wait(lVar1,&local_80);
              }
LAB_001035f8:
              if (*(int *)(*(code **)(param_1 + 0x238) + -4) != -0x73376f46) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103618);
                (*pcVar4)();
              }
              (**(code **)(param_1 + 0x238))(param_1);
            }
            else {
              local_68 = 0;
              uStack_60 = 0;
              local_78 = 0;
              uStack_70 = 0;
              local_80 = 0;
              init_wait_entry(&local_80,0);
              while( true ) {
                lVar10 = prepare_to_wait_event(lVar1,&local_80,1);
                if (*(char *)(param_1 + 0x1e7) == '\0') break;
                if (lVar10 != 0) goto LAB_0010361c;
                schedule();
              }
              finish_wait(lVar1,&local_80);
            }
LAB_0010361c:
            if (pcVar8[1] == '\x02') {
              cVar11 = -1;
              *(undefined1 *)(param_1 + 0x1e6) = 0;
LAB_00103648:
              *(char *)(param_1 + 0x1e4) = cVar11;
            }
            else if (pcVar8[1] == '\x01') {
              cVar11 = *pcVar8;
              *(undefined1 *)(param_1 + 0x1e6) = 1;
              goto LAB_00103648;
            }
            uVar6 = (uint)*(byte *)(param_1 + 0x1e5);
            goto LAB_001036b8;
          }
          _dev_err(*(undefined8 *)(param_1 + 200),"%s: write failed after max retry, ret %d\n",
                   "send_ese_cmd",uVar6);
        }
      }
      _printk(&DAT_00106017);
    }
    else {
      _printk(&DAT_00105d02,"ese_cold_reset_ioctl");
      uVar6 = 0xfffffdfd;
    }
  }
  else {
    sVar7 = 4;
LAB_001037e8:
    memset(pcVar8 + (4 - sVar7),0,sVar7);
    _dev_err(*(undefined8 *)(param_1 + 200),"ese ioctl arg buffer copy from user failed\n");
    uVar6 = 0xfffffff2;
  }
LAB_001036b8:
  if (*(long *)(param_1 + 0x1d8) != 0) {
    kfree();
    *(undefined8 *)(param_1 + 0x1d8) = 0;
  }
  kfree(pcVar8);
  mutex_unlock(param_1 + 0x48);
LAB_001036d8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// i2c_disable_irq @ 001038c8 size=100
// signature: undefined i2c_disable_irq(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

undefined8 i2c_disable_irq(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x174);
  if (*(char *)(param_1 + 0x170) != '\0') {
    disable_irq_nosync(*(undefined4 *)(*(long *)(param_1 + 0x168) + 0x3b4));
    *(undefined1 *)(param_1 + 0x170) = 0;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x174,uVar1);
  return 0;
}



//------------------------------------------------------------
// i2c_enable_irq @ 00103930 size=104
// signature: undefined i2c_enable_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_enable_irq(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x174);
  if (*(char *)(param_1 + 0x170) == '\0') {
    *(undefined1 *)(param_1 + 0x170) = 1;
    enable_irq(*(undefined4 *)(*(long *)(param_1 + 0x168) + 0x3b4));
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x174,uVar1);
  return 0;
}



//------------------------------------------------------------
// i2c_read @ 0010399c size=1060
// signature: undefined i2c_read(void)
// callers: [nfc_i2c_dev_read]
//------------------------------------------------------------

ulong i2c_read(long param_1,char *param_2,size_t param_3,int param_4)

{
  ulong uVar1;
  char cVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  uVar1 = param_3;
  if (3 < param_3) {
    uVar1 = 4;
  }
  if (1999 < param_4) {
    param_4 = 2000;
  }
  if (0x101 < param_3) {
    param_3 = 0x102;
  }
  gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
  iVar4 = gpiod_get_raw_value();
  if (iVar4 != 0) {
LAB_00103a08:
    memset(param_2,0,param_3);
    uVar5 = i2c_transfer_buffer_flags
                      (*(undefined8 *)(param_1 + 0x168),param_2,param_3 & 0xffffffff,1);
    uVar7 = uVar5 & 0xffffffff;
    ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s of %d bytes, ret %d","i2c_read",param_3,
                   uVar7);
    if ((int)uVar5 < 1) {
      _printk(&DAT_00105bff,"i2c_read",uVar7);
    }
    else {
      if ((((uVar1 != 0) &&
           (ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",*param_2), uVar1 != 1)) &&
          (ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",param_2[1]), uVar1 != 2)) &&
         (ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",param_2[2]), uVar1 != 3)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",param_2[3]);
      }
      if (((*(char *)(param_1 + 0x1e7) != '\0') && (*(long *)(param_1 + 0x1d8) != 0)) &&
         ((*param_2 == 'O' && (param_2[1] == *(char *)(*(long *)(param_1 + 0x1d8) + 1))))) {
        read_cold_reset_rsp(param_1,param_2);
        *(undefined1 *)(param_1 + 0x1e7) = 0;
        __wake_up(param_1 + 0x1c0,1,1,0);
LAB_00103b18:
        uVar7 = 0;
      }
    }
LAB_00103b1c:
    lVar3 = sp_el0;
    if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return uVar7 & 0xffffffff;
  }
  cVar2 = *(char *)(param_1 + 0x170);
  do {
    if (cVar2 == '\0') {
      *(undefined1 *)(param_1 + 0x170) = 1;
      enable_irq(*(undefined4 *)(*(long *)(param_1 + 0x168) + 0x3b4));
    }
    gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
    iVar4 = gpiod_get_raw_value();
    if (iVar4 == 0) {
      if (param_4 == 0) {
        if (*(char *)(param_1 + 0x170) != '\0') {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          uVar7 = prepare_to_wait_event(param_1,&local_90,1);
          if (*(char *)(param_1 + 0x170) != '\0') {
            do {
              if (uVar7 != 0) {
                if ((int)uVar7 == 0) goto LAB_00103cdc;
                _printk(&DAT_001054a8,"i2c_read");
                goto LAB_00103b1c;
              }
              schedule();
              uVar7 = prepare_to_wait_event(param_1,&local_90,1);
            } while (*(char *)(param_1 + 0x170) != '\0');
          }
          finish_wait(param_1,&local_90);
        }
      }
      else {
        uVar7 = __msecs_to_jiffies(param_4);
        if (uVar7 == 0 && *(char *)(param_1 + 0x170) == '\0') {
          uVar7 = 1;
        }
        if ((*(char *)(param_1 + 0x170) != '\0') && (uVar7 != 0)) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          uVar5 = __msecs_to_jiffies(param_4);
          init_wait_entry(&local_90,0);
          uVar7 = prepare_to_wait_event(param_1,&local_90,1);
          if (uVar5 == 0 && *(char *)(param_1 + 0x170) == '\0') {
            uVar5 = 1;
          }
          if ((*(char *)(param_1 + 0x170) != '\0') && (uVar5 != 0)) {
            do {
              if (uVar7 != 0) goto LAB_00103c5c;
              uVar5 = schedule_timeout(uVar5);
              uVar7 = prepare_to_wait_event(param_1,&local_90,1);
              if (uVar5 == 0 && *(char *)(param_1 + 0x170) == '\0') {
                uVar5 = 1;
              }
            } while ((*(char *)(param_1 + 0x170) != '\0') && (uVar5 != 0));
          }
          uVar7 = uVar5;
          finish_wait(param_1,&local_90);
        }
LAB_00103c5c:
        if ((int)uVar7 < 1) {
          _printk(&DAT_00105b3c,"i2c_read");
          goto LAB_00103b1c;
        }
      }
    }
LAB_00103cdc:
    uVar6 = _raw_spin_lock_irqsave(param_1 + 0x174);
    if (*(char *)(param_1 + 0x170) != '\0') {
      disable_irq_nosync(*(undefined4 *)(*(long *)(param_1 + 0x168) + 0x3b4));
      *(undefined1 *)(param_1 + 0x170) = 0;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x174,uVar6);
    gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
    iVar4 = gpiod_get_raw_value();
    if (iVar4 != 0) goto LAB_00103a08;
    if (*(char *)(param_1 + 0x20c) == '\0') {
      gpio_to_desc(*(undefined4 *)(param_1 + 0x184));
      iVar4 = gpiod_get_raw_value();
      if (iVar4 == 0) {
        _printk(&DAT_00105a9d,"i2c_read");
        uVar7 = 0xfffffffb;
        goto LAB_00103b1c;
      }
    }
    if (*(char *)(param_1 + 0x162) != '\0') goto LAB_00103b18;
    _printk(&DAT_00105b59,"i2c_read");
    cVar2 = *(char *)(param_1 + 0x170);
  } while( true );
}



//------------------------------------------------------------
// i2c_write @ 00103dc4 size=720
// signature: undefined i2c_write(void)
// callers: [nfc_i2c_dev_write]
//------------------------------------------------------------

ulong i2c_write(long param_1,undefined1 *param_2,ulong param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  ulong uVar3;
  
  uVar3 = param_3;
  if (3 < param_3) {
    uVar3 = 4;
  }
  if (0x229 < param_3) {
    param_3 = 0x22a;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s sending %d B","i2c_write",param_3);
  if ((((uVar3 != 0) &&
       (ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",*param_2), uVar3 != 1)) &&
      (ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",param_2[1]), uVar3 != 2)) &&
     (ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",param_2[2]), uVar3 != 3)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x218)," %02x",param_2[3]);
  }
  gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
  iVar1 = gpiod_get_raw_value();
  if (iVar1 != 0) {
    _printk(&DAT_00105e7a,"i2c_write");
    usleep_range_state(3000,0xc1c,2);
    gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
    iVar1 = gpiod_get_raw_value();
    if (iVar1 != 0) {
      _printk(&DAT_00105e7a,"i2c_write");
      usleep_range_state(3000,0xc1c,2);
      gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
      iVar1 = gpiod_get_raw_value();
      if (iVar1 != 0) {
        _printk(&DAT_00105e7a,"i2c_write");
        usleep_range_state(3000,0xc1c,2);
        gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
        iVar1 = gpiod_get_raw_value();
        if (iVar1 != 0) {
          _printk(&DAT_00105e7a,"i2c_write");
          usleep_range_state(3000,0xc1c,2);
          gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
          iVar1 = gpiod_get_raw_value();
          if (iVar1 != 0) {
            _printk(&DAT_00105e7a,"i2c_write");
            usleep_range_state(3000,0xc1c,2);
            gpio_to_desc(*(undefined4 *)(param_1 + 0x180));
            iVar1 = gpiod_get_raw_value();
            if (iVar1 != 0) {
              _printk(&DAT_00105b84,"i2c_write");
            }
          }
        }
      }
    }
  }
  if (param_4 < 1) {
    uVar3 = 0xffffffea;
  }
  else {
    iVar1 = 1;
    do {
      uVar2 = i2c_transfer_buffer_flags
                        (*(undefined8 *)(param_1 + 0x168),param_2,param_3 & 0xffffffff,0);
      uVar3 = (ulong)uVar2;
      ipc_log_string(*(undefined8 *)(param_1 + 0x218),"%s ret %d","i2c_write",uVar3);
      if ((int)uVar2 < 1) {
        _printk(&DAT_00106035,"i2c_write",uVar2);
        usleep_range_state(3000,0xc1c,2);
      }
      else {
        if (param_3 == uVar3) {
          return uVar3;
        }
        _printk(&DAT_00106447,"i2c_write",uVar2);
        uVar3 = 0xfffffffb;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= param_4);
  }
  return uVar3;
}



//------------------------------------------------------------
// nfc_i2c_dev_read @ 00104098 size=464
// signature: undefined nfc_i2c_dev_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long nfc_i2c_dev_read(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  uint uVar2;
  long lVar3;
  undefined8 *puVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar7 = *(long *)(param_1 + 0xd8);
  if (lVar7 == 0) {
    _printk(&DAT_001051d7,"nfc_i2c_dev_read");
    return -0x13;
  }
  mutex_lock(lVar7 + 0x18);
  if (0x101 < param_3) {
    param_3 = 0x102;
  }
  if ((*(byte *)(param_1 + 0x41) >> 3 & 1) == 0) {
    uVar2 = i2c_read(lVar7,*(undefined8 *)(lVar7 + 0x78),param_3,0);
  }
  else {
    uVar2 = i2c_transfer_buffer_flags
                      (*(undefined8 *)(lVar7 + 0x168),*(undefined8 *)(lVar7 + 0x78),param_3,1);
  }
  uVar6 = (ulong)uVar2;
  if (0 < (int)uVar2) {
    uVar8 = *(undefined8 *)(lVar7 + 0x78);
    __check_object_size(uVar8,uVar6,1);
    puVar4 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar5 = param_2 & (long)(param_2 << 8) >> 8;
    }
    if (uVar5 <= 0x8000000000 - uVar6) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        puVar4 = (undefined8 *)puVar4[1];
        uVar1 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar4;
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      lVar3 = __arch_copy_to_user(puVar4,param_2 & 0xff7fffffffffffff,uVar8,uVar6);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        uVar5 = ttbr1_el1;
        ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      if (lVar3 == 0) goto LAB_001041f4;
    }
    _printk(&DAT_0010619b,"nfc_i2c_dev_read");
    uVar2 = 0xfffffff2;
  }
LAB_001041f4:
  mutex_unlock(lVar7 + 0x18);
  return (long)(int)uVar2;
}



//------------------------------------------------------------
// nfc_i2c_dev_write @ 00104284 size=452
// signature: undefined nfc_i2c_dev_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long nfc_i2c_dev_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  
  lVar7 = *(long *)(param_1 + 0xd8);
  if (0x229 < param_3) {
    param_3 = 0x22a;
  }
  if (lVar7 == 0) {
    _printk(&DAT_001051d7,"nfc_i2c_dev_write");
    lVar7 = -0x13;
  }
  else {
    lVar1 = lVar7 + 0x48;
    mutex_lock(lVar1);
    lVar8 = *(long *)(lVar7 + 0x80);
    __check_object_size(lVar8,param_3,0);
    puVar5 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
      uVar6 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar4 = param_3;
    if (uVar6 <= 0x8000000000 - param_3) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        puVar5 = (undefined8 *)puVar5[1];
        uVar4 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar5;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      uVar4 = __arch_copy_from_user(puVar5,lVar8,param_2 & 0xff7fffffffffffff,param_3);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
    }
    if (uVar4 == 0) {
      iVar3 = i2c_write(lVar7,*(undefined8 *)(lVar7 + 0x80),param_3,1);
      mutex_unlock(lVar1);
      lVar7 = (long)iVar3;
    }
    else {
      memset((void *)(lVar8 + (param_3 - uVar4)),0,uVar4);
      _printk(&DAT_00105e09,"nfc_i2c_dev_write");
      mutex_unlock(lVar1);
      lVar7 = -0xe;
    }
  }
  return lVar7;
}



//------------------------------------------------------------
// nfc_i2c_dev_probe @ 00104464 size=932
// signature: undefined nfc_i2c_dev_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int nfc_i2c_dev_probe(long param_1)

{
  long lVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined *puVar7;
  long lVar8;
  char *pcVar9;
  code *pcVar10;
  
  lVar5 = kmalloc_trace(_mutex_lock,0xdc0,0x240);
  if (lVar5 == 0) {
    iVar4 = -0xc;
  }
  else {
    lVar1 = param_1 + 0x20;
    iVar4 = nfc_parse_dt(lVar1,(undefined4 *)(lVar5 + 0x180),0);
    if (iVar4 == 0) {
      pcVar10 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
      if (*(int *)(pcVar10 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1044e4);
        (*pcVar10)();
      }
      uVar6 = (*pcVar10)();
      if ((uVar6 & 1) == 0) {
        _printk(&DAT_0010537f,"nfc_i2c_dev_probe");
        iVar4 = -0x13;
      }
      else {
        lVar8 = kmalloc_trace(_down_timeout,0xdc1,0x102);
        *(long *)(lVar5 + 0x78) = lVar8;
        if (lVar8 == 0) {
          iVar4 = -0xc;
        }
        else {
          lVar8 = kmalloc_trace(_mutex_lock,0xdc1,0x22a);
          *(long *)(lVar5 + 0x80) = lVar8;
          if (lVar8 == 0) {
            iVar4 = -0xc;
          }
          else {
            *(long *)(lVar5 + 0x168) = param_1;
            *(undefined2 *)(lVar5 + 0x15c) = 0x200;
            *(code **)(lVar5 + 0x220) = i2c_read;
            *(code **)(lVar5 + 0x230) = i2c_enable_irq;
            *(code **)(lVar5 + 0x228) = i2c_write;
            *(code **)(lVar5 + 0x238) = i2c_disable_irq;
            iVar4 = configure_gpio(*(undefined4 *)(lVar5 + 0x180),4);
            if (iVar4 < 1) {
              _printk(&DAT_00105692,"nfc_i2c_dev_probe",*(undefined4 *)(lVar5 + 0x180));
            }
            else {
              *(int *)(param_1 + 0x3b4) = iVar4;
              __init_waitqueue_head(lVar5,"&nfc_dev->read_wq",&nfc_i2c_dev_probe___key);
              __mutex_init(lVar5 + 0x18,"&nfc_dev->read_mutex",&nfc_i2c_dev_probe___key_20);
              __mutex_init(lVar5 + 0x48,"&nfc_dev->write_mutex",&nfc_i2c_dev_probe___key_22);
              __mutex_init(lVar5 + 0x88,"&nfc_dev->dev_ref_mutex",&nfc_i2c_dev_probe___key_24);
              *(undefined4 *)(lVar5 + 0x174) = 0;
              iVar4 = nfc_misc_register(lVar5,&nfc_i2c_dev_fops,1,"nq-nci","qti-nfc");
              if (iVar4 == 0) {
                _printk(&DAT_00105999,"nfc_i2c_dev_probe",*(undefined4 *)(param_1 + 0x3b4));
                uVar3 = *(undefined4 *)(param_1 + 0x3b4);
                *(undefined1 *)(lVar5 + 0x170) = 1;
                iVar4 = request_threaded_irq(uVar3,i2c_irq_handler,0,4,param_1 + 4,lVar5);
                if (iVar4 == 0) {
                  i2c_disable_irq(lVar5);
                  iVar4 = nfc_ldo_config(lVar1,lVar5);
                  if (iVar4 == 0) {
                    if (*(char *)(lVar5 + 0x1b8) == '\0') {
                      nfc_post_init(lVar5);
                    }
                    else {
                      uVar6 = nfc_hw_secure_check();
                      bVar2 = (uVar6 & 1) == 0;
                      if (bVar2) {
                        nfc_post_init(lVar5);
                        pcVar9 = "false";
                      }
                      else {
                        pcVar9 = "true";
                      }
                      *(bool *)(lVar5 + 0x20c) = !bVar2;
                      _printk(&DAT_00105a2e,"nfc_i2c_dev_probe",pcVar9);
                    }
                    *(byte *)(lVar5 + 0x20d) = *(byte *)(lVar5 + 0x1a8) ^ 1;
                    device_set_wakeup_capable(lVar1,1);
                    device_wakeup_enable(lVar1);
                    iVar4 = 0;
                    puVar7 = &DAT_001050ae;
                    *(long *)(param_1 + 0xb8) = lVar5;
                    *(undefined1 *)(lVar5 + 0x178) = 0;
                    *(undefined1 *)(lVar5 + 0x161) = 0;
                    goto LAB_00104530;
                  }
                  _printk(&DAT_00105782);
                  free_irq(*(undefined4 *)(param_1 + 0x3b4),lVar5);
                }
                else {
                  _printk(&DAT_0010508c,"nfc_i2c_dev_probe");
                }
                nfc_misc_unregister(lVar5,1);
              }
              else {
                _printk(&DAT_00106469,"nfc_i2c_dev_probe");
              }
            }
            gpio_free_all(lVar5);
            kfree(*(undefined8 *)(lVar5 + 0x80));
          }
          kfree(*(undefined8 *)(lVar5 + 0x78));
        }
      }
    }
    else {
      _printk(&DAT_0010535d,"nfc_i2c_dev_probe");
    }
    kfree(lVar5);
  }
  puVar7 = &DAT_0010590d;
LAB_00104530:
  _printk(puVar7,"nfc_i2c_dev_probe");
  return iVar4;
}



//------------------------------------------------------------
// i2c_irq_handler @ 0010480c size=156
// signature: undefined i2c_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 i2c_irq_handler(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_2 + 0x168);
  if (((*(ushort *)(lVar2 + 300) & 1) != 0) && (*(long *)(lVar2 + 0x168) != 0)) {
    pm_wakeup_dev_event(lVar2 + 0x20,100,0);
  }
  uVar1 = _raw_spin_lock_irqsave(param_2 + 0x174);
  if (*(char *)(param_2 + 0x170) != '\0') {
    disable_irq_nosync(*(undefined4 *)(*(long *)(param_2 + 0x168) + 0x3b4));
    *(undefined1 *)(param_2 + 0x170) = 0;
  }
  _raw_spin_unlock_irqrestore(param_2 + 0x174,uVar1);
  __wake_up(param_2,3,1,0);
  return 1;
}



//------------------------------------------------------------
// nfc_i2c_dev_remove @ 001048ac size=268
// signature: undefined nfc_i2c_dev_remove(void)
// callers: []
//------------------------------------------------------------

void nfc_i2c_dev_remove(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  _printk(&DAT_00105c1a,"nfc_i2c_dev_remove");
  lVar3 = *(long *)(param_1 + 0xb8);
  if (lVar3 == 0) {
    _printk(&DAT_001051d7,"nfc_i2c_dev_remove");
    iVar1 = iRam00000000000000b8;
  }
  else {
    iVar1 = *(int *)(lVar3 + 0xb8);
  }
  if (iVar1 != 0) {
    _printk(&DAT_0010586b,"nfc_i2c_dev_remove");
  }
  uVar2 = gpio_to_desc(*(undefined4 *)(lVar3 + 0x184));
  gpiod_set_raw_value(uVar2,0);
  usleep_range_state(10000,0x2774,2);
  if (*(long *)(lVar3 + 0x1f0) != 0) {
    nfc_ldo_unvote(lVar3);
    regulator_put(*(undefined8 *)(lVar3 + 0x1f0));
  }
  device_wakeup_disable(param_1 + 0x20);
  device_set_wakeup_capable(param_1 + 0x20,0);
  free_irq(*(undefined4 *)(param_1 + 0x3b4),lVar3);
  nfc_misc_unregister(lVar3,1);
  gpio_free_all(lVar3);
  kfree(*(undefined8 *)(lVar3 + 0x78));
  kfree(*(undefined8 *)(lVar3 + 0x80));
  kfree(lVar3);
  return;
}



//------------------------------------------------------------
// nfc_i2c_dev_suspend @ 001049bc size=156
// signature: undefined nfc_i2c_dev_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 nfc_i2c_dev_suspend(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    _printk(&DAT_001051d7,"nfc_i2c_dev_suspend");
    uVar1 = 0xffffffed;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x218),"%s: irq_enabled = %d","nfc_i2c_dev_suspend",
                   *(undefined1 *)(lVar2 + 0x170));
    if (((((*(ushort *)(param_1 + 0x10c) & 1) == 0) || (*(long *)(param_1 + 0x148) == 0)) ||
        (*(char *)(lVar2 + 0x170) == '\0')) ||
       (uVar1 = irq_set_irq_wake(*(undefined4 *)(param_1 + 0x394),1), (int)uVar1 != 0)) {
      uVar1 = 0;
    }
    else {
      *(undefined1 *)(lVar2 + 0x178) = 1;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// nfc_i2c_dev_resume @ 00104a5c size=164
// signature: undefined nfc_i2c_dev_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 nfc_i2c_dev_resume(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 == 0) {
    _printk(&DAT_001051d7,"nfc_i2c_dev_resume");
    uVar2 = 0xffffffed;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar3 + 0x218),"%s: irq_wake_up = %d","nfc_i2c_dev_resume",
                   *(undefined1 *)(lVar3 + 0x178));
    if ((((*(ushort *)(param_1 + 0x10c) & 1) == 0) || (*(long *)(param_1 + 0x148) == 0)) ||
       (*(char *)(lVar3 + 0x178) == '\0')) {
      uVar2 = 0;
    }
    else {
      iVar1 = irq_set_irq_wake(*(undefined4 *)(param_1 + 0x394),0);
      uVar2 = 0;
      if (iVar1 == 0) {
        uVar2 = 0;
        *(undefined1 *)(lVar3 + 0x178) = 0;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00106574 size=112
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_001054ce,"nfc_i2c_dev_init");
  iVar1 = i2c_register_driver(&__this_module,&nfc_i2c_dev_driver);
  if (iVar1 != 0) {
    _printk(&DAT_00105d47,"nfc_i2c_dev_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001065e8 size=56
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  _printk(&DAT_00105c37,"nfc_i2c_dev_exit");
  i2c_del_driver(&nfc_i2c_dev_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00109000 size=1
// signature: undefined _printk(void)
// callers: [nfc_dev_ioctl, nfcc_hw_check, ese_cold_reset_ioctl, cleanup_module, nfc_i2c_dev_suspend, nfc_ese_pwr, i2c_read, nfc_dynamic_protection_ioctl, i2c_write, nfc_i2c_dev_remove, nfc_ldo_config, get_nfcc_session_state_dl, nfc_i2c_dev_resume, nfc_ioctl_power_states, validate_nfc_state_nci, nfc_ldo_vote, nfc_misc_register, nfc_ldo_unvote, nfc_parse_dt, nfc_post_init, nfc_i2c_dev_read, nfc_hw_secure_check, init_module, nfc_i2c_dev_probe, nfc_i2c_dev_write, configure_gpio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00109008 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [nfc_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00109010 size=1
// signature: undefined of_property_read_string(void)
// callers: [nfc_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00109018 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [nfc_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00109020 size=1
// signature: undefined _dev_err(void)
// callers: [ese_cold_reset_ioctl, nfc_parse_dt, read_cold_reset_rsp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00109028 size=1
// signature: undefined gpio_to_desc(void)
// callers: [nfc_dev_ioctl, ese_cold_reset_ioctl, validate_nfc_state_nci, nfc_ioctl_power_states, nfc_dev_open, gpio_set_ven, nfc_dev_close, get_valid_gpio, nfc_ese_pwr, i2c_read, set_valid_gpio, nfc_dynamic_protection_ioctl, i2c_write, nfc_i2c_dev_remove, configure_gpio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 00109030 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [set_valid_gpio, nfc_i2c_dev_remove, nfc_ioctl_power_states, nfc_dev_open, gpio_set_ven, nfc_dev_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00109038 size=1
// signature: undefined usleep_range_state(void)
// callers: [set_valid_gpio, nfcc_hw_check, i2c_write, nfc_i2c_dev_remove, nfc_ioctl_power_states, nfc_dev_open, gpio_set_ven, nfc_dev_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00109040 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [nfc_dev_ioctl, nfc_dynamic_protection_ioctl, i2c_write, ese_cold_reset_ioctl, validate_nfc_state_nci, nfc_ioctl_power_states, gpio_set_ven, get_valid_gpio, nfc_ese_pwr, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_client_env_object @ 00109048 size=1
// signature: undefined get_client_env_object(void)
// callers: [nfc_hw_secure_check]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_client_env_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [nfc_dev_ioctl, nfc_post_init, nfc_hw_secure_check, ese_cold_reset_ioctl, i2c_read, is_nfc_data_available_for_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 00109058 size=1
// signature: undefined gpio_request(void)
// callers: [configure_gpio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 00109060 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [configure_gpio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00109068 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [configure_gpio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 00109070 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [configure_gpio]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 00109078 size=1
// signature: undefined gpio_free(void)
// callers: [nfc_post_init, nfcc_hw_check, configure_gpio, gpio_free_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00109080 size=1
// signature: undefined kfree(void)
// callers: [nfc_i2c_dev_remove, ese_cold_reset_ioctl, nfc_misc_unregister, nfc_misc_register, nfc_i2c_dev_probe, read_cold_reset_rsp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00109088 size=1
// signature: undefined device_destroy(void)
// callers: [nfc_misc_unregister, nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00109090 size=1
// signature: undefined cdev_del(void)
// callers: [nfc_misc_unregister, nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00109098 size=1
// signature: undefined class_destroy(void)
// callers: [nfc_misc_unregister, nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001090a0 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [nfc_misc_unregister, nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001090a8 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [nfc_misc_unregister, nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 001090b0 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001090b8 size=1
// signature: undefined __class_create(void)
// callers: [nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001090c0 size=1
// signature: undefined cdev_init(void)
// callers: [nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001090c8 size=1
// signature: undefined cdev_add(void)
// callers: [nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001090d0 size=1
// signature: undefined device_create(void)
// callers: [nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001090d8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [nfc_misc_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001090e8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [ese_cold_reset_ioctl, nfc_misc_register, nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 001090f0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [nfc_misc_register, nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00109108 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [nfc_dev_ioctl, nfc_i2c_dev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00109118 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [nfc_post_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_gpio_mpm_wake_set @ 00109120 size=1
// signature: undefined msm_gpio_mpm_wake_set(void)
// callers: [nfc_post_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_gpio_mpm_wake_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_timeout @ 00109128 size=1
// signature: undefined down_timeout(void)
// callers: [nfc_dynamic_protection_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109130 size=1
// signature: undefined mutex_lock(void)
// callers: [nfc_i2c_dev_read, ese_cold_reset_ioctl, nfc_dev_open, nfc_dev_flush, nfc_dev_close, nfc_i2c_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109138 size=1
// signature: undefined mutex_unlock(void)
// callers: [nfc_i2c_dev_read, ese_cold_reset_ioctl, nfc_dev_open, nfc_dev_flush, nfc_dev_close, nfc_i2c_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 00109140 size=1
// signature: undefined mutex_trylock(void)
// callers: [nfc_dev_flush]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00109148 size=1
// signature: undefined __wake_up(void)
// callers: [i2c_irq_handler, nfc_dev_flush, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00109150 size=1
// signature: undefined init_wait_entry(void)
// callers: [ese_cold_reset_ioctl, i2c_read, is_nfc_data_available_for_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00109158 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [ese_cold_reset_ioctl, i2c_read, is_nfc_data_available_for_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00109160 size=1
// signature: undefined schedule_timeout(void)
// callers: [i2c_read, is_nfc_data_available_for_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00109168 size=1
// signature: undefined finish_wait(void)
// callers: [ese_cold_reset_ioctl, i2c_read, is_nfc_data_available_for_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00109170 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [nfc_ldo_vote, nfc_ldo_unvote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00109178 size=1
// signature: undefined regulator_set_load(void)
// callers: [nfc_ldo_vote, nfc_ldo_unvote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00109180 size=1
// signature: undefined regulator_enable(void)
// callers: [nfc_ldo_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00109188 size=1
// signature: undefined of_get_property(void)
// callers: [nfc_ldo_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 00109190 size=1
// signature: undefined regulator_get(void)
// callers: [nfc_ldo_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00109198 size=1
// signature: undefined regulator_put(void)
// callers: [nfc_i2c_dev_remove, nfc_ldo_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 001091a0 size=1
// signature: undefined regulator_disable(void)
// callers: [nfc_ldo_unvote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 001091a8 size=1
// signature: undefined clk_get(void)
// callers: [nfc_clock_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001091b0 size=1
// signature: undefined clk_prepare(void)
// callers: [nfc_clock_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001091b8 size=1
// signature: undefined clk_enable(void)
// callers: [nfc_clock_select]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001091c0 size=1
// signature: undefined clk_unprepare(void)
// callers: [nfc_clock_select, nfc_clock_deselect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001091c8 size=1
// signature: undefined clk_disable(void)
// callers: [nfc_clock_deselect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001091d0 size=1
// signature: undefined __kmalloc(void)
// callers: [read_cold_reset_rsp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer_buffer_flags @ 001091d8 size=1
// signature: undefined i2c_transfer_buffer_flags(void)
// callers: [nfc_i2c_dev_read, i2c_write, i2c_read, read_cold_reset_rsp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer_buffer_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001091e0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [ese_cold_reset_ioctl, nfc_i2c_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001091e8 size=1
// signature: undefined schedule(void)
// callers: [ese_cold_reset_ioctl, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001091f0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [ese_cold_reset_ioctl, nfc_i2c_dev_write, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001091f8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [i2c_irq_handler, i2c_enable_irq, i2c_disable_irq, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq_nosync @ 00109200 size=1
// signature: undefined disable_irq_nosync(void)
// callers: [i2c_irq_handler, i2c_disable_irq, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq_nosync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00109208 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [i2c_irq_handler, i2c_enable_irq, i2c_disable_irq, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00109210 size=1
// signature: undefined enable_irq(void)
// callers: [i2c_enable_irq, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00109218 size=1
// signature: undefined ipc_log_string(void)
// callers: [nfc_i2c_dev_resume, i2c_write, nfc_i2c_dev_suspend, i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00109220 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00109228 size=1
// signature: undefined __check_object_size(void)
// callers: [nfc_i2c_dev_read, nfc_i2c_dev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00109230 size=1
// signature: undefined __mutex_init(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00109238 size=1
// signature: undefined request_threaded_irq(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00109240 size=1
// signature: undefined free_irq(void)
// callers: [nfc_i2c_dev_remove, nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00109248 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [nfc_i2c_dev_remove, nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00109250 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [nfc_i2c_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 00109258 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [i2c_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00109260 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [nfc_i2c_dev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00109268 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [nfc_i2c_dev_resume, nfc_i2c_dev_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 00109270 size=1
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
// i2c_del_driver @ 00109278 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



